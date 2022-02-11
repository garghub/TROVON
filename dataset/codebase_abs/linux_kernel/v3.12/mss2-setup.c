static int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 != - 1 )
return V_5 ;
return - 1 ;
}
static int T_1 F_3 ( void )
{
if ( F_4 () )
F_5 ( & V_6 ) ;
return 0 ;
}
static void F_6 ( void )
{
T_3 V_7 ;
V_7 = F_7 ( V_8 ) ;
V_7 |= 1 << 2 ;
F_8 ( V_7 , V_8 ) ;
V_7 = F_7 ( V_9 ) ;
V_7 |= 1 ;
F_8 ( V_7 , V_9 ) ;
}
static void T_1 F_9 ( void )
{
F_10 () ;
F_11 ( V_10 ) ;
F_12 () ;
F_13 () ;
F_14 ( & V_11 ) ;
F_15 () ;
F_16 ( & V_12 ) ;
F_17 () ;
F_18 () ;
F_19 ( V_13 ,
V_14 ,
V_15 ,
V_16 ) ;
F_20 ( & V_17 ) ;
F_20 ( & V_18 ) ;
if ( F_21 ( V_19 , L_1 ) == 0 ) {
if ( F_22 ( V_19 ) == 0 )
V_20 . V_5 = F_23 ( V_19 ) ;
else
F_24 ( V_19 ) ;
}
F_25 ( 0 , & V_20 , 1 ) ;
V_21 = F_6 ;
}
