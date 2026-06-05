static bool trans_xg233_dma(DisasContext *ctx, arg_r *a){
    
    TCGv addr_dst = get_gpr(ctx, a -> rd, EXT_NONE);
    TCGv addr_src = get_gpr(ctx, a -> rs1, EXT_NONE);
    TCGv size_idx = get_gpr(ctx, a -> rs2, EXT_NONE);
    
    gen_helper_xg233_dma(tcg_env, addr_dst, addr_src, size_idx);
    return true;
}

static bool trans_xg233_sort(DisasContext *ctx, arg_r *a){
    TCGv elem_total = get_gpr(ctx, a -> rd, EXT_NONE);
    TCGv addr_src = get_gpr(ctx, a -> rs1, EXT_NONE);
    TCGv elem_num = get_gpr(ctx, a -> rs2, EXT_NONE);

    gen_helper_xg233_sort(tcg_env, elem_total, addr_src, elem_num);

    return true;
}

static bool trans_xg233_crush(DisasContext *ctx, arg_r *a){
    TCGv addr_dst = get_gpr(ctx, a -> rd, EXT_NONE);
    TCGv addr_src = get_gpr(ctx, a -> rs1, EXT_NONE);
    TCGv elem_num = get_gpr(ctx, a -> rs2, EXT_NONE);

    gen_helper_xg233_crush(tcg_env, elem_num, addr_dst, addr_src);

    return true;
}

static bool trans_xg233_expand(DisasContext *ctx, arg_r *a){
    TCGv addr_dst = get_gpr(ctx, a -> rd, EXT_NONE);
    TCGv addr_src = get_gpr(ctx, a -> rs1, EXT_NONE);
    TCGv elem_num = get_gpr(ctx, a -> rs2, EXT_NONE);

    gen_helper_xg233_expand(tcg_env, elem_num, addr_dst, addr_src);

    return true;    
}

static bool trans_xg233_vdot(DisasContext *ctx, arg_r *a){
    TCGv reg = get_gpr(ctx, a -> rd, EXT_NONE);
    TCGv addr_src1 = get_gpr(ctx, a -> rs1, EXT_NONE);
    TCGv addr_src2 = get_gpr(ctx, a -> rs2, EXT_NONE);

    gen_helper_xg233_vdot(reg, tcg_env, addr_src1, addr_src2);
    gen_set_gpr(ctx, a -> rd, reg);
    return true;    
}

static bool trans_xg233_vrelu(DisasContext *ctx, arg_r *a){
    TCGv addr_dst = get_gpr(ctx, a -> rd, EXT_NONE);
    TCGv addr_src = get_gpr(ctx, a -> rs1, EXT_NONE);
    TCGv elem_num = get_gpr(ctx, a -> rs2, EXT_NONE);

    gen_helper_xg233_vrelu(tcg_env, elem_num, addr_dst, addr_src);

    return true;    
}

static bool trans_xg233_vscale(DisasContext *ctx, arg_r *a){
    TCGv addr_dst = get_gpr(ctx, a -> rd, EXT_NONE);
    TCGv addr_src = get_gpr(ctx, a -> rs1, EXT_NONE);
    TCGv scale = get_gpr(ctx, a -> rs2, EXT_NONE);

    gen_helper_xg233_vscale(tcg_env, scale, addr_dst, addr_src);

    return true;
}

static bool trans_xg233_vmax(DisasContext *ctx, arg_r *a){
    TCGv reg = get_gpr(ctx, a -> rd, EXT_NONE);
    TCGv addr_src = get_gpr(ctx, a -> rs1, EXT_NONE);
    TCGv elem_num = get_gpr(ctx, a -> rs2, EXT_NONE);

    gen_helper_xg233_vmax(reg, tcg_env, addr_src, elem_num);
    gen_set_gpr(ctx, a -> rd, reg);
    return true;    
}

static bool trans_xg233_gemm(DisasContext *ctx, arg_r *a){
    TCGv addr_dst = get_gpr(ctx, a -> rd, EXT_NONE);
    TCGv addr_src1 = get_gpr(ctx, a -> rs1, EXT_NONE);
    TCGv addr_src2 = get_gpr(ctx, a -> rs2, EXT_NONE);

    gen_helper_xg233_gemm(tcg_env, addr_src2, addr_src1, addr_dst);
    return true;
}

static bool trans_xg233_vadd(DisasContext *ctx, arg_r *a){
    TCGv addr_dst = get_gpr(ctx, a -> rd, EXT_NONE);
    TCGv addr_src1 = get_gpr(ctx, a -> rs1, EXT_NONE);
    TCGv addr_src2 = get_gpr(ctx, a -> rs2, EXT_NONE);

    gen_helper_xg233_vadd(tcg_env, addr_src2, addr_src1, addr_dst);
    return true;
}