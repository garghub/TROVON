static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void T_1 F_4 ( void )
{
F_5 ( 0 , V_2 ,
F_6 ( V_3 ) ,
F_6 ( V_4 ) ) ;
}
static void T_1 F_7 ( void )
{
V_5 = F_6 ( V_6 ) ;
V_7 = F_6 ( V_6 ) + 0x20 ;
V_8 = F_6 ( V_9 ) ;
V_10 = F_6 ( V_9 ) + 0x20 ;
F_8 ( V_11 ) ;
}
static void F_9 ( char V_12 )
{
void T_2 * V_13 = F_6 ( V_14 ) ;
void T_2 * V_15 = F_6 ( V_16 ) ;
F_10 ( V_17 , V_15 ) ;
F_10 ( 0x0000 , V_13 ) ;
F_10 ( 0x0004 , V_13 ) ;
}
static void T_1 F_11 ( void )
{
int V_18 ;
F_12 ( V_19 ,
F_3 ( V_19 ) ) ;
F_13 ( NULL , V_20 ) ;
F_14 ( & V_21 ) ;
F_14 ( & V_22 ) ;
F_15 ( V_23 ) ;
F_14 ( & V_24 ) ;
for ( V_18 = 0 ; V_18 < F_3 ( V_25 ) ; V_18 ++ ) {
struct V_26 * V_27 = V_25 [ V_18 ] ;
F_16 ( V_27 , & V_28 ) ;
}
#ifdef F_17
V_29 = V_30 ;
#endif
V_31 = F_9 ;
}
