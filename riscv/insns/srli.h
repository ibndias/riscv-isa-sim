if(insn.rd() != 0){
    require(SHAMT < xlen);
    WRITE_RD(sext_xlen(zext_xlen(RS1) >> SHAMT));
}else{
    reg_t idx = insn.rs1() & 0x3;
    reg_t btid = 0;
    btid = insn.i_imm() & 0x1F;
    btid = (btid << 3) | (insn.rs1() >> 2);
    reg_t old = p->get_csr(CSR_BTID0);
    //printf("idx2 : %d\n", idx);
    //printf("csr2 : %d\n", old);
    switch(idx){
        case 0 :
            old = old & 0x000000FF;
            break;
        case 1 :
            old = (old & 0x0000FF00) >> 8;
            break;
        case 2 :
            old = (old & 0x00FF0000) >> 16;
            break;
        case 3 :
            old = (old & 0xFF000000) >> 24;
            break;
        default : ;
    }
    //printf("btid2 : %x\n", btid);
    //printf("old : %x\n", old);
    // if(btid != old) printf("error\n");
    // else printf("success\n");
}