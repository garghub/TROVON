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
F_13 ( V_16 ) ;
F_9 () ;
}
static void F_14 ( struct V_17 * V_18 , char * * V_19 ,
struct V_20 * V_20 )
{
#ifdef F_15
V_20 -> V_21 [ 0 ] . V_22 = 0 ;
V_20 -> V_21 [ 0 ] . V_23 = V_24 ;
V_20 -> V_21 [ 1 ] . V_22 = 0x20000000 ;
V_20 -> V_21 [ 1 ] . V_23 = V_25 ;
V_20 -> V_21 [ 2 ] . V_22 = 0x80000000 ;
V_20 -> V_21 [ 2 ] . V_23 = V_24 ;
V_20 -> V_26 = 3 ;
#else
F_16 ( V_18 , V_19 , V_20 ) ;
#endif
}
static void F_17 ( char V_27 , const char * V_28 )
{
void T_2 * V_29 = F_8 ( V_30 ) ;
void T_2 * V_31 = F_8 ( V_32 ) ;
F_18 ( V_33 , V_31 ) ;
F_18 ( 0x00F0 , V_29 ) ;
F_18 ( 0x00F4 , V_29 ) ;
F_19 () ;
}
static void T_1 F_20 ( void )
{
int V_34 ;
#ifdef F_21
if ( F_5 () ) {
void T_2 * V_35 =
F_8 ( V_36 ) ;
F_22 ( 0 , V_35 + V_37 ) ;
F_22 ( 0 , V_35 + V_38 ) ;
F_23 ( V_35 , 0x02520000 , 0xc0000fff ) ;
F_24 ( & V_39 ) ;
}
#endif
F_25 ( V_40 ,
F_3 ( V_40 ) ) ;
F_26 ( NULL , V_41 ) ;
F_24 ( & V_42 ) ;
F_24 ( & V_43 ) ;
F_27 ( V_44 ) ;
for ( V_34 = 0 ; V_34 < F_3 ( V_45 ) ; V_34 ++ ) {
struct V_46 * V_47 = V_45 [ V_34 ] ;
F_28 ( V_47 , & V_48 ) ;
}
#ifdef F_29
V_49 = V_50 ;
#endif
}
