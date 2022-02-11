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
V_8 = F_8 ( V_9 ) ;
V_10 = F_8 ( V_9 ) + 0x20 ;
V_11 = F_8 ( V_12 ) ;
V_13 = F_8 ( V_12 ) + 0x20 ;
#ifdef F_10
if ( F_4 () || F_5 () )
V_14 = F_8 ( V_15 ) ;
#endif
F_11 ( V_16 ) ;
}
static void F_12 ( struct V_17 * V_18 , char * * V_19 ,
struct V_20 * V_20 )
{
#ifdef F_13
V_20 -> V_21 [ 0 ] . V_22 = 0 ;
V_20 -> V_21 [ 0 ] . V_23 = V_24 ;
V_20 -> V_21 [ 1 ] . V_22 = 0x20000000 ;
V_20 -> V_21 [ 1 ] . V_23 = V_25 ;
V_20 -> V_21 [ 2 ] . V_22 = 0x80000000 ;
V_20 -> V_21 [ 2 ] . V_23 = V_24 ;
V_20 -> V_26 = 3 ;
#else
F_14 ( V_18 , V_19 , V_20 ) ;
#endif
}
static void F_15 ( char V_27 , const char * V_28 )
{
void T_2 * V_29 = F_8 ( V_30 ) ;
void T_2 * V_31 = F_8 ( V_32 ) ;
F_16 ( V_33 , V_31 ) ;
F_16 ( 0x00F0 , V_29 ) ;
F_16 ( 0x00F4 , V_29 ) ;
F_17 () ;
}
static void T_1 F_18 ( void )
{
int V_34 ;
#ifdef F_19
if ( F_5 () ) {
void T_2 * V_35 =
F_8 ( V_36 ) ;
F_20 ( 0 , V_35 + V_37 ) ;
F_20 ( 0 , V_35 + V_38 ) ;
F_21 ( V_35 , 0x02520000 , 0xc0000fff ) ;
F_22 ( & V_39 ) ;
}
#endif
F_23 ( V_40 ,
F_3 ( V_40 ) ) ;
F_24 ( NULL , V_41 ) ;
F_22 ( & V_42 ) ;
F_22 ( & V_43 ) ;
F_25 ( V_44 ) ;
for ( V_34 = 0 ; V_34 < F_3 ( V_45 ) ; V_34 ++ ) {
struct V_46 * V_47 = V_45 [ V_34 ] ;
F_26 ( V_47 , & V_48 ) ;
}
#ifdef F_27
V_49 = V_50 ;
#endif
}
