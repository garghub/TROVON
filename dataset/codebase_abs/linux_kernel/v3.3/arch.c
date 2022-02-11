static void F_1 ( char V_1 , const char * V_2 )
{
F_2 ( L_1 , V_1 , V_3 ) ;
if ( V_1 == 'h' ) {
if ( V_3 ) {
F_2 ( L_2 ) ;
F_3 ( V_4 ) ;
} else {
F_2 ( L_3 ) ;
F_3 ( V_5 ) ;
}
} else {
F_2 ( L_3 ) ;
F_3 ( V_5 ) ;
}
}
static void T_1 F_4 ( void )
{
V_6 = F_5 ( V_7 ) ;
F_6 () ;
F_7 ( V_8 , F_8 ( V_8 ) ) ;
F_9 () ;
F_10 () ;
}
static void T_1 F_11 ( struct V_9 * V_10 , char * * V_11 ,
struct V_12 * V_13 ) {
#ifdef F_12
F_2 ( V_14 L_4 ) ;
V_10 -> V_15 . V_9 = V_16 ;
V_10 -> V_15 . V_17 = F_13 ( V_18 ) ;
V_10 -> V_19 . V_20 . V_21 = 0 ;
V_10 -> V_19 . V_20 . V_22 = V_23 ;
V_10 -> V_19 . V_20 . V_24 = 31 << 8 | 0 ;
V_10 = F_14 ( V_10 ) ;
V_10 -> V_15 . V_9 = V_25 ;
V_10 -> V_15 . V_17 = F_13 ( V_26 ) ;
V_10 -> V_19 . V_27 . V_28 = V_29 ;
V_10 -> V_19 . V_27 . V_17 = V_30 ;
V_10 = F_14 ( V_10 ) ;
V_10 -> V_15 . V_9 = V_31 ;
V_10 -> V_15 . V_17 = 0 ;
#endif
}
