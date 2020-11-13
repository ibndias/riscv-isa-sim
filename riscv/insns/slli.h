
if(insn.rd() != 0){
    require(SHAMT < xlen);
    WRITE_RD(sext_xlen(RS1 << SHAMT));
}else{
    reg_t idx = (insn.rs1() & 0x3);
    reg_t btid = 0;
    btid = insn.i_imm() & 0x1F;
    btid = (btid << 3) | (insn.rs1() >> 2);
    reg_t old = 0;
    reg_t flag = 0;
    //printf("rs1 : %x\n", insn.rs1());    
    //printf("idx : %d\n", idx);
    //printf("btid : %x\n", btid);
    switch(idx){
        case 0 :
            old = p->get_csr(CSR_BTID0) & 0xFFFFFF00;
            flag = old | btid;
            break;
        case 1 :
            old = p->get_csr(CSR_BTID0) & 0xFFFF00FF;
            flag = old | (btid << 8);
            break;
        case 2 : 
            old = p->get_csr(CSR_BTID0) & 0xFF00FFFF;
            flag = old | (btid << 16);
            break;
        case 3 :
            old = p->get_csr(CSR_BTID0) & 0x00FFFFFF;
            flag = old | (btid << 24);
            break;
        default : ;
    }
    //printf("old : %x\n", old);
    //printf("flag : %x\n", flag);
    p->set_csr(CSR_BTID0, flag);
    //printf("csr : %d\n",p->get_csr(CSR_BTID0));
}

