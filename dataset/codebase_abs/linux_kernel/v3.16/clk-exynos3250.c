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
V_2 =
F_7 ( V_3 ,
F_3 ( V_3 ) ) ;
if ( ! V_2 ) {
F_8 ( L_1 , V_4 ) ;
goto V_5;
}
F_9 ( & V_6 ) ;
return;
V_5:
F_10 ( V_2 ) ;
}
static inline void F_6 ( void ) { }
static void T_1 F_11 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_1 = F_12 ( V_8 , 0 ) ;
if ( ! V_1 )
F_13 ( L_2 , V_4 ) ;
V_10 = F_14 ( V_8 , V_1 , V_11 ) ;
if ( ! V_10 )
F_13 ( L_3 , V_4 ) ;
F_15 ( V_10 , V_12 ,
F_3 ( V_12 ) ) ;
V_13 [ V_14 ] . V_15 = V_16 ;
V_13 [ V_17 ] . V_15 = V_16 ;
V_13 [ V_18 ] . V_15 = V_19 ;
V_13 [ V_20 ] . V_15 = V_16 ;
F_16 ( V_10 , V_13 ,
F_3 ( V_13 ) , V_1 ) ;
F_17 ( V_10 , V_21 , F_3 ( V_21 ) ) ;
F_18 ( V_10 , V_22 , F_3 ( V_22 ) ) ;
F_19 ( V_10 , V_23 , F_3 ( V_23 ) ) ;
F_6 () ;
}
