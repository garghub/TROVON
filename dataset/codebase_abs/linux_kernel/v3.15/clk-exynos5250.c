static int F_1 ( void )
{
F_2 ( V_1 , V_2 ,
F_3 ( V_3 ) ) ;
return 0 ;
}
static void F_4 ( void )
{
F_5 ( V_1 , V_2 ,
F_3 ( V_3 ) ) ;
}
static void F_6 ( void )
{
V_2 = F_7 ( V_3 ,
F_3 ( V_3 ) ) ;
if ( ! V_2 ) {
F_8 ( L_1 ,
V_4 ) ;
return;
}
F_9 ( & V_5 ) ;
}
static void F_6 ( void ) {}
static void T_1 F_10 ( struct V_6 * V_7 )
{
if ( V_7 ) {
V_1 = F_11 ( V_7 , 0 ) ;
if ( ! V_1 )
F_12 ( L_2 , V_4 ) ;
} else {
F_12 ( L_3 , V_4 ) ;
}
F_13 ( V_7 , V_1 , V_8 ) ;
F_14 ( V_9 ,
F_3 ( V_9 ) ,
V_10 ) ;
F_15 ( V_11 ,
F_3 ( V_11 ) ) ;
if ( F_16 ( L_4 ) == 24 * V_12 ) {
V_13 [ V_14 ] . V_15 = V_16 ;
V_13 [ V_17 ] . V_15 = V_18 ;
}
if ( F_16 ( L_5 ) == 24 * V_12 )
V_13 [ V_19 ] . V_15 = V_20 ;
F_17 ( V_13 , F_3 ( V_13 ) ,
V_1 ) ;
F_18 ( V_21 ,
F_3 ( V_21 ) ) ;
F_19 ( V_22 ,
F_3 ( V_22 ) ) ;
F_15 ( V_23 ,
F_3 ( V_23 ) ) ;
F_20 ( V_24 ,
F_3 ( V_24 ) ) ;
F_21 ( V_25 ,
F_3 ( V_25 ) ) ;
F_6 () ;
F_22 ( L_6 ,
F_16 ( L_7 ) ) ;
}
