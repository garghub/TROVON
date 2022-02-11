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
static void F_12 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * * V_21 , struct V_22 * V_22 )
{
#ifdef F_13
V_22 -> V_23 [ 0 ] . V_24 = 0 ;
V_22 -> V_23 [ 0 ] . V_25 = V_26 ;
V_22 -> V_23 [ 1 ] . V_24 = 0x20000000 ;
V_22 -> V_23 [ 1 ] . V_25 = V_27 ;
V_22 -> V_23 [ 2 ] . V_24 = 0x80000000 ;
V_22 -> V_23 [ 2 ] . V_25 = V_26 ;
V_22 -> V_28 = 3 ;
#else
F_14 ( V_18 , V_20 , V_21 , V_22 ) ;
#endif
}
static void F_15 ( char V_29 )
{
void T_2 * V_30 = F_8 ( V_31 ) ;
void T_2 * V_32 = F_8 ( V_33 ) ;
F_16 ( V_34 , V_32 ) ;
F_16 ( 0x00F0 , V_30 ) ;
F_16 ( 0x00F4 , V_30 ) ;
}
static void T_1 F_17 ( void )
{
int V_35 ;
#ifdef F_18
if ( F_5 () ) {
void T_2 * V_36 =
F_8 ( V_37 ) ;
F_19 ( 0 , V_36 + V_38 ) ;
F_19 ( 0 , V_36 + V_39 ) ;
F_20 ( V_36 , 0x02520000 , 0xc0000fff ) ;
F_21 ( & V_40 ) ;
}
#endif
F_22 ( V_41 ,
F_3 ( V_41 ) ) ;
F_23 ( NULL , V_42 ) ;
F_21 ( & V_43 ) ;
F_21 ( & V_44 ) ;
F_24 ( V_45 ) ;
for ( V_35 = 0 ; V_35 < F_3 ( V_46 ) ; V_35 ++ ) {
struct V_47 * V_48 = V_46 [ V_35 ] ;
F_25 ( V_48 , & V_49 ) ;
}
#ifdef F_26
V_50 = V_51 ;
#endif
V_52 = F_15 ;
}
