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
F_8 ( F_6 ( V_11 ) , false ) ;
F_9 ( V_12 ) ;
}
static void F_10 ( char V_13 , const char * V_14 )
{
void T_2 * V_15 = F_6 ( V_16 ) ;
void T_2 * V_17 = F_6 ( V_18 ) ;
F_11 ( V_19 , V_17 ) ;
F_11 ( 0x0000 , V_15 ) ;
F_11 ( 0x0004 , V_15 ) ;
F_12 () ;
}
static void T_1 F_13 ( void )
{
int V_20 ;
F_14 ( V_21 ,
F_3 ( V_21 ) ) ;
F_15 ( NULL , V_22 ) ;
F_16 ( & V_23 ) ;
F_16 ( & V_24 ) ;
F_17 ( V_25 ) ;
F_16 ( & V_26 ) ;
for ( V_20 = 0 ; V_20 < F_3 ( V_27 ) ; V_20 ++ ) {
struct V_28 * V_29 = V_27 [ V_20 ] ;
F_18 ( V_29 , & V_30 ) ;
}
}
