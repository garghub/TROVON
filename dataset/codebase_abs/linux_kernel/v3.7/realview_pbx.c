static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
if ( F_4 () || F_5 () )
F_2 ( V_2 , F_3 ( V_2 ) ) ;
}
static void T_1 F_6 ( void )
{
if ( F_4 () || F_5 () ) {
F_7 ( 0 , 29 , F_8 ( V_3 ) ,
F_8 ( V_4 ) ) ;
} else {
F_7 ( 0 , V_5 ,
F_8 ( V_6 ) ,
F_8 ( V_7 ) ) ;
}
}
static void T_1 F_9 ( void )
{
int V_8 = F_10 ( & V_9 ) ;
if ( V_8 )
F_11 ( L_1 , V_8 ) ;
}
static void T_1 F_12 ( void )
{
V_10 = F_8 ( V_11 ) ;
V_12 = F_8 ( V_11 ) + 0x20 ;
V_13 = F_8 ( V_14 ) ;
V_15 = F_8 ( V_14 ) + 0x20 ;
F_13 ( F_8 ( V_16 ) , false ) ;
F_14 ( V_17 ) ;
F_9 () ;
}
static void F_15 ( struct V_18 * V_19 , char * * V_20 ,
struct V_21 * V_21 )
{
#ifdef F_16
V_21 -> V_22 [ 0 ] . V_23 = 0 ;
V_21 -> V_22 [ 0 ] . V_24 = V_25 ;
V_21 -> V_22 [ 1 ] . V_23 = 0x20000000 ;
V_21 -> V_22 [ 1 ] . V_24 = V_26 ;
V_21 -> V_22 [ 2 ] . V_23 = 0x80000000 ;
V_21 -> V_22 [ 2 ] . V_24 = V_25 ;
V_21 -> V_27 = 3 ;
#else
F_17 ( V_19 , V_20 , V_21 ) ;
#endif
}
static void F_18 ( char V_28 , const char * V_29 )
{
void T_2 * V_30 = F_8 ( V_31 ) ;
void T_2 * V_32 = F_8 ( V_33 ) ;
F_19 ( V_34 , V_32 ) ;
F_19 ( 0x00F0 , V_30 ) ;
F_19 ( 0x00F4 , V_30 ) ;
F_20 () ;
}
static void T_1 F_21 ( void )
{
int V_35 ;
#ifdef F_22
if ( F_5 () ) {
void T_2 * V_36 =
F_8 ( V_37 ) ;
F_23 ( 0 , V_36 + V_38 ) ;
F_23 ( 0 , V_36 + V_39 ) ;
F_24 ( V_36 , 0x02520000 , 0xc0000fff ) ;
F_25 ( & V_40 ) ;
}
#endif
F_26 ( V_41 ,
F_3 ( V_41 ) ) ;
F_27 ( NULL , V_42 ) ;
F_25 ( & V_43 ) ;
F_25 ( & V_44 ) ;
F_28 ( V_45 ) ;
for ( V_35 = 0 ; V_35 < F_3 ( V_46 ) ; V_35 ++ ) {
struct V_47 * V_48 = V_46 [ V_35 ] ;
F_29 ( V_48 , & V_49 ) ;
}
}
