void T_1 F_1 ( unsigned V_1 ,
const struct V_2 * V_3 , unsigned V_4 )
{
F_2 ( V_5 ) ;
if ( V_1 & F_3 ( 0 ) )
F_2 ( V_6 ) ;
if ( V_1 & F_3 ( 1 ) )
F_2 ( V_7 ) ;
F_4 ( V_3 , V_4 ) ;
F_5 ( & V_8 ) ;
}
static void F_6 ( void )
{
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
F_2 ( V_14 ) ;
F_2 ( V_15 ) ;
}
void F_7 ( struct V_16 * V_17 )
{
V_18 . V_19 . V_20 = V_17 ;
}
void T_1 F_8 ( T_2 V_21 , struct V_22 * V_23 )
{
if ( V_21 & V_24 )
F_2 ( V_25 ) ;
if ( V_21 & V_26 )
F_2 ( V_27 ) ;
V_28 . V_19 . V_20 = V_23 ;
F_5 ( & V_28 ) ;
}
void T_1 F_9 ( void )
{
F_10 ( & V_29 ) ;
F_11 () ;
}
static int T_1 F_12 ( void )
{
if ( ! F_13 () )
return 0 ;
F_14 ( L_1 , V_30 . V_31 , L_2 , NULL ) ;
F_14 ( L_3 , V_30 . V_31 , L_2 , NULL ) ;
F_2 ( V_32 ) ;
F_5 ( & V_33 ) ;
F_5 ( & V_34 ) ;
F_5 ( & V_30 ) ;
F_5 ( & V_18 ) ;
return 0 ;
}
