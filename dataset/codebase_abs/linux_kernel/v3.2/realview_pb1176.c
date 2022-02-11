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
static void F_10 ( char V_16 )
{
void T_2 * V_17 = F_6 ( V_18 ) ;
void T_2 * V_19 = F_6 ( V_20 ) ;
F_11 ( V_21 , V_19 ) ;
F_11 ( V_22 , V_17 ) ;
}
static void F_12 ( struct V_23 * V_24 , char * * V_25 ,
struct V_26 * V_26 )
{
V_26 -> V_27 [ 0 ] . V_28 = 0 ;
V_26 -> V_27 [ 0 ] . V_29 = V_30 ;
V_26 -> V_31 = 1 ;
}
static void T_1 F_13 ( void )
{
int V_32 ;
#ifdef F_14
F_15 ( F_6 ( V_33 ) , 0x00730000 , 0xfe000fff ) ;
#endif
F_16 ( V_34 ,
F_3 ( V_34 ) ) ;
F_17 ( & V_35 ) ;
F_18 ( NULL , V_36 ) ;
F_17 ( & V_37 ) ;
F_19 ( V_38 ) ;
F_17 ( & V_39 ) ;
F_17 ( & V_40 ) ;
for ( V_32 = 0 ; V_32 < F_3 ( V_41 ) ; V_32 ++ ) {
struct V_42 * V_43 = V_41 [ V_32 ] ;
F_20 ( V_43 , & V_44 ) ;
}
#ifdef F_21
V_45 = V_46 ;
#endif
V_47 = F_10 ;
}
