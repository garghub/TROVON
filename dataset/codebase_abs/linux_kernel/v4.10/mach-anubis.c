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
F_6 ( V_8 , F_7 ( V_8 ) ) ;
F_8 ( V_9 , F_7 ( V_9 ) ) ;
F_9 ( V_10 , V_11 ) ;
if ( ( F_3 ( V_12 ) & V_13 ) >= 4 ) {
F_10 ( V_14 L_3 ,
F_3 ( V_12 ) & V_13 ) ;
V_15 [ 0 ] . V_16 = V_17 ;
V_15 [ 0 ] . V_18 = F_7 ( V_17 ) ;
} else {
F_11 ( F_12 ( 0 ) , V_19 , NULL ) ;
F_13 ( F_12 ( 0 ) ) ;
}
}
static void T_1 F_14 ( void )
{
F_15 ( 12000000 ) ;
F_16 () ;
}
static void T_1 F_17 ( void )
{
F_18 ( NULL ) ;
F_19 ( & V_20 ) ;
F_20 ( NULL , false , & V_21 ) ;
F_21 ( V_22 , F_7 ( V_22 ) ) ;
F_22 ( 0 , V_23 ,
F_7 ( V_23 ) ) ;
}
