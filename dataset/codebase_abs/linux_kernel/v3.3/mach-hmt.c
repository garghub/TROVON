static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( F_3 ( 4 ) , L_1 ) ;
if ( ! V_3 )
V_3 = F_4 ( F_3 ( 4 ) , 0 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 , int V_4 )
{
if ( V_4 < 0x800 ) {
V_4 = ( 100 * 256 * V_4 + 231245 / 2 ) / 231245 ;
} else {
int V_5 = ( V_4 * 4 + 16 * 1024 + 58 ) / 116 ;
V_4 = 25 * ( ( V_5 * V_5 * V_5 + 0x100000 / 2 ) / 0x100000 ) ;
}
F_6 ( F_3 ( 4 ) , V_4 ) ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( 4 ) ) ;
}
static void T_1 F_9 ( void )
{
F_10 ( V_6 , F_11 ( V_6 ) ) ;
F_12 ( 12000000 ) ;
F_13 ( V_7 , F_11 ( V_7 ) ) ;
}
static void T_1 F_14 ( void )
{
F_15 ( NULL ) ;
F_16 ( & V_8 ) ;
F_17 ( & V_9 ) ;
F_2 ( F_18 ( 7 ) , L_2 ) ;
F_4 ( F_18 ( 7 ) , 0 ) ;
F_2 ( F_19 ( 0 ) , L_2 ) ;
F_4 ( F_19 ( 0 ) , 1 ) ;
F_2 ( F_20 ( 7 ) , L_2 ) ;
F_4 ( F_20 ( 7 ) , 1 ) ;
F_2 ( F_21 ( 13 ) , L_2 ) ;
F_4 ( F_21 ( 13 ) , 1 ) ;
F_22 ( V_10 , F_11 ( V_10 ) ) ;
}
