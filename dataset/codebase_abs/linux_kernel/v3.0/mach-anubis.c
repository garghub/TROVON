static void F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
V_3 = V_2 -> V_5 [ V_3 ] & 3 ;
F_2 ( L_1 ,
V_3 , V_2 , V_2 -> V_5 ) ;
V_4 = F_3 ( V_6 ) ;
V_4 &= ~ V_7 ;
V_4 |= V_3 ;
F_2 ( L_2 , V_4 ) ;
F_4 ( V_4 , V_6 ) ;
}
static void T_1 F_5 ( void )
{
V_8 . V_9 = & V_10 ;
V_8 . V_11 = 12 * 1000 * 1000 ;
V_12 . V_9 = & V_10 ;
V_12 . V_11 = 24 * 1000 * 1000 ;
V_13 . V_9 = & V_8 ;
V_14 . V_9 = & V_12 ;
V_15 . V_9 = & V_14 ;
F_6 ( V_16 , F_7 ( V_16 ) ) ;
F_8 ( V_17 , F_7 ( V_17 ) ) ;
F_9 ( 0 ) ;
F_10 ( V_18 , F_7 ( V_18 ) ) ;
if ( ( F_3 ( V_19 ) & V_20 ) >= 4 ) {
F_11 ( V_21 L_3 ,
F_3 ( V_19 ) & V_20 ) ;
V_22 [ 0 ] . V_23 = V_24 ;
V_22 [ 0 ] . V_25 = F_7 ( V_24 ) ;
} else {
F_12 ( F_13 ( 0 ) , 1 ) ;
}
}
static void T_1 F_14 ( void )
{
F_15 ( NULL ) ;
F_16 ( & V_26 ) ;
F_17 ( NULL , false , & V_27 ) ;
F_18 ( V_28 , F_7 ( V_28 ) ) ;
F_19 ( 0 , V_29 ,
F_7 ( V_29 ) ) ;
}
