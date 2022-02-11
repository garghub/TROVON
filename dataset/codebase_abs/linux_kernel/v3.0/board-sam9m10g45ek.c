static void T_1 F_1 ( void )
{
F_2 ( 12000000 ) ;
F_3 ( 0 , 0 , 0 ) ;
F_3 ( V_1 , 2 , V_2 | V_3 ) ;
F_4 ( 0 ) ;
}
static void T_1 F_5 ( void )
{
F_6 ( NULL ) ;
}
static struct V_4 * T_1 F_7 ( int V_5 , int * V_6 )
{
* V_6 = F_8 ( V_7 ) ;
return V_7 ;
}
static void T_1 F_9 ( void )
{
V_8 . V_9 = F_10 () ;
if ( V_8 . V_9 )
V_10 . V_11 |= V_12 ;
else
V_10 . V_11 |= V_13 ;
F_11 ( 3 , & V_10 ) ;
F_12 ( & V_8 ) ;
}
static void T_1 F_13 ( void )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_8 ( V_15 ) ; V_14 ++ ) {
F_14 ( V_15 [ V_14 ] . V_16 , 1 ) ;
F_15 ( V_15 [ V_14 ] . V_16 , 1 ) ;
}
F_16 ( & V_17 ) ;
}
static void T_1 F_13 ( void ) {}
static void T_1 F_17 ( void )
{
F_18 () ;
F_19 ( & V_18 ) ;
F_20 ( & V_18 ) ;
F_21 ( & V_19 ) ;
F_22 ( V_20 , F_8 ( V_20 ) ) ;
F_23 ( 0 , & V_21 ) ;
F_23 ( 1 , & V_22 ) ;
F_24 ( & V_23 ) ;
F_9 () ;
F_25 ( 0 , NULL , 0 ) ;
F_26 ( & V_24 ) ;
F_27 ( & V_25 ) ;
F_13 () ;
F_28 ( & V_26 ) ;
F_29 ( V_27 , F_8 ( V_27 ) ) ;
F_30 ( V_28 , F_8 ( V_28 ) ) ;
}
