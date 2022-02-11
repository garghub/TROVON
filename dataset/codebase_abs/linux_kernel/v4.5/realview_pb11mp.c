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
int V_12 = F_11 ( & V_13 ) ;
if ( V_12 )
F_12 ( L_1 , V_12 ) ;
}
static void T_1 F_13 ( void )
{
V_14 = F_6 ( V_15 ) ;
V_16 = F_6 ( V_15 ) + 0x20 ;
V_17 = F_6 ( V_18 ) ;
V_19 = F_6 ( V_18 ) + 0x20 ;
F_14 ( F_6 ( V_4 ) , false ) ;
F_15 ( V_20 ) ;
F_10 () ;
}
static void F_16 ( enum V_21 V_22 , const char * V_23 )
{
void T_2 * V_24 = F_6 ( V_25 ) ;
void T_2 * V_26 = F_6 ( V_3 ) ;
F_17 ( V_27 , V_26 ) ;
F_17 ( 0x0000 , V_24 ) ;
F_17 ( 0x0004 , V_24 ) ;
F_18 () ;
}
static void T_1 F_19 ( void )
{
int V_28 ;
#ifdef F_20
F_21 ( F_6 ( V_29 ) , 0x00790000 , 0xfe000fff ) ;
V_30 . V_31 = NULL ;
#endif
F_22 ( V_32 ,
F_3 ( V_32 ) ) ;
F_23 ( NULL , V_33 ) ;
F_24 ( & V_34 ) ;
F_24 ( & V_35 ) ;
F_24 ( & V_36 ) ;
F_25 ( V_37 ) ;
F_24 ( & V_38 ) ;
for ( V_28 = 0 ; V_28 < F_3 ( V_39 ) ; V_28 ++ ) {
struct V_40 * V_41 = V_39 [ V_28 ] ;
F_26 ( V_41 , & V_42 ) ;
}
}
