static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void T_1 F_4 ( void )
{
F_5 ( 0 , V_2 ,
F_6 ( V_3 ) ,
F_6 ( V_4 ) ) ;
F_5 ( 1 , V_5 ,
F_6 ( V_6 ) ,
F_6 ( V_7 ) ) ;
F_7 ( 1 , V_8 ) ;
}
static void T_1 F_8 ( void )
{
V_9 = F_6 ( V_10 ) ;
V_11 = F_6 ( V_10 ) + 0x20 ;
V_12 = F_6 ( V_13 ) ;
V_14 = F_6 ( V_13 ) + 0x20 ;
F_9 ( V_15 ) ;
}
static void F_10 ( char V_16 , const char * V_17 )
{
void T_2 * V_18 = F_6 ( V_19 ) ;
void T_2 * V_20 = F_6 ( V_21 ) ;
F_11 ( V_22 , V_20 ) ;
F_11 ( V_23 , V_18 ) ;
F_12 () ;
}
static void F_13 ( struct V_24 * V_25 , char * * V_26 ,
struct V_27 * V_27 )
{
V_27 -> V_28 [ 0 ] . V_29 = 0 ;
V_27 -> V_28 [ 0 ] . V_30 = V_31 ;
V_27 -> V_32 = 1 ;
}
static void T_1 F_14 ( void )
{
int V_33 ;
#ifdef F_15
F_16 ( F_6 ( V_34 ) , 0x00730000 , 0xfe000fff ) ;
#endif
F_17 ( V_35 ,
F_3 ( V_35 ) ) ;
F_18 ( & V_36 ) ;
F_19 ( NULL , V_37 ) ;
F_18 ( & V_38 ) ;
F_20 ( V_39 ) ;
F_18 ( & V_40 ) ;
F_18 ( & V_41 ) ;
for ( V_33 = 0 ; V_33 < F_3 ( V_42 ) ; V_33 ++ ) {
struct V_43 * V_44 = V_42 [ V_33 ] ;
F_21 ( V_44 , & V_45 ) ;
}
#ifdef F_22
V_46 = V_47 ;
#endif
}
