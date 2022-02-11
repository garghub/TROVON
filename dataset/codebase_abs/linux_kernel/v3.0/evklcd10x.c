static void F_1 ( int V_1 )
{
F_2 ( F_3 ( 15 ) , V_1 ) ;
}
static int T_1 F_4 ( void )
{
F_5 ( F_3 ( 15 ) , V_2 ) ;
F_6 ( F_3 ( 15 ) , L_1 ) ;
F_7 ( F_3 ( 15 ) , 0 ) ;
V_3 . V_4 =
F_1 ;
F_8 ( 0 , &atevklcd10x_lcdc_data,
fbmem_start, fbmem_size,
#ifdef F_9
ATMEL_LCDC_PRI_18BIT | ATMEL_LCDC_PC_DVAL
#else
ATMEL_LCDC_ALT_18BIT | ATMEL_LCDC_PE_DVAL
#endif
) ;
F_10 ( 0 , & V_5 , V_6 ) ;
return 0 ;
}
