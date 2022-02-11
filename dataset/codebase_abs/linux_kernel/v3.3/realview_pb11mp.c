static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void T_1 F_4 ( void )
{
unsigned int V_2 ;
F_5 ( 0x0000a05f , F_6 ( V_3 ) ) ;
V_2 = F_7 ( F_6 ( V_4 ) + V_5 ) ;
V_2 |= 2 << 22 ;
F_5 ( V_2 , F_6 ( V_4 ) + V_5 ) ;
F_5 ( 0x00000000 , F_6 ( V_3 ) ) ;
F_8 ( 0 , 29 , F_6 ( V_6 ) ,
F_6 ( V_7 ) ) ;
F_8 ( 1 , V_8 ,
F_6 ( V_9 ) ,
F_6 ( V_10 ) ) ;
F_9 ( 1 , V_11 ) ;
}
static void T_1 F_10 ( void )
{
V_12 = F_6 ( V_13 ) ;
V_14 = F_6 ( V_13 ) + 0x20 ;
V_15 = F_6 ( V_16 ) ;
V_17 = F_6 ( V_16 ) + 0x20 ;
#ifdef F_11
V_18 = F_6 ( V_19 ) ;
#endif
F_12 ( V_20 ) ;
}
static void F_13 ( char V_21 , const char * V_22 )
{
void T_2 * V_23 = F_6 ( V_24 ) ;
void T_2 * V_25 = F_6 ( V_3 ) ;
F_14 ( V_26 , V_25 ) ;
F_14 ( 0x0000 , V_23 ) ;
F_14 ( 0x0004 , V_23 ) ;
F_15 () ;
}
static void T_1 F_16 ( void )
{
int V_27 ;
#ifdef F_17
F_18 ( F_6 ( V_28 ) , 0x00790000 , 0xfe000fff ) ;
#endif
F_19 ( V_29 ,
F_3 ( V_29 ) ) ;
F_20 ( NULL , V_30 ) ;
F_21 ( & V_31 ) ;
F_21 ( & V_32 ) ;
F_22 ( V_33 ) ;
F_21 ( & V_34 ) ;
for ( V_27 = 0 ; V_27 < F_3 ( V_35 ) ; V_27 ++ ) {
struct V_36 * V_37 = V_35 [ V_27 ] ;
F_23 ( V_37 , & V_38 ) ;
}
#ifdef F_24
V_39 = V_40 ;
#endif
}
