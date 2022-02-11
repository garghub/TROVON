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
static void F_9 ( char V_12 , const char * V_13 )
{
void T_2 * V_14 = F_6 ( V_15 ) ;
void T_2 * V_16 = F_6 ( V_17 ) ;
F_10 ( V_18 , V_16 ) ;
F_10 ( 0x0000 , V_14 ) ;
F_10 ( 0x0004 , V_14 ) ;
F_11 () ;
}
static void T_1 F_12 ( void )
{
int V_19 ;
F_13 ( V_20 ,
F_3 ( V_20 ) ) ;
F_14 ( NULL , V_21 ) ;
F_15 ( & V_22 ) ;
F_15 ( & V_23 ) ;
F_16 ( V_24 ) ;
F_15 ( & V_25 ) ;
for ( V_19 = 0 ; V_19 < F_3 ( V_26 ) ; V_19 ++ ) {
struct V_27 * V_28 = V_26 [ V_19 ] ;
F_17 ( V_28 , & V_29 ) ;
}
#ifdef F_18
V_30 = V_31 ;
#endif
}
