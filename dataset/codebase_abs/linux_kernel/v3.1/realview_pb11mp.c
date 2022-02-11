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
static void F_13 ( char V_21 )
{
void T_2 * V_22 = F_6 ( V_23 ) ;
void T_2 * V_24 = F_6 ( V_3 ) ;
F_14 ( V_25 , V_24 ) ;
F_14 ( 0x0000 , V_22 ) ;
F_14 ( 0x0004 , V_22 ) ;
}
static void T_1 F_15 ( void )
{
int V_26 ;
#ifdef F_16
F_17 ( F_6 ( V_27 ) , 0x00790000 , 0xfe000fff ) ;
#endif
F_18 ( V_28 ,
F_3 ( V_28 ) ) ;
F_19 ( NULL , V_29 ) ;
F_20 ( & V_30 ) ;
F_20 ( & V_31 ) ;
F_21 ( V_32 ) ;
F_20 ( & V_33 ) ;
for ( V_26 = 0 ; V_26 < F_3 ( V_34 ) ; V_26 ++ ) {
struct V_35 * V_36 = V_34 [ V_26 ] ;
F_22 ( V_36 , & V_37 ) ;
}
#ifdef F_23
V_38 = V_39 ;
#endif
V_40 = F_13 ;
}
