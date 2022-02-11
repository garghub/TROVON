static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
T_1 V_5 = V_6 ;
int V_7 ;
V_7 = F_2 ( V_8 , L_1 ) ;
if ( V_7 ) {
F_3 ( L_2 , V_7 ) ;
return;
}
F_4 ( V_3 ) ;
F_5 ( V_8 , 1 ) ;
F_6 ( 2 ) ;
F_7 ( V_8 , 0 ) ;
F_8 ( V_8 ) ;
F_4 ( V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
T_1 V_5 = V_6 ;
T_1 V_9 = V_10 ;
T_1 V_11 = V_12 ;
T_1 V_13 = V_14 ;
int V_7 ;
V_7 = F_2 ( V_8 , L_1 ) ;
if ( V_7 )
goto V_15;
V_7 = F_2 ( V_16 , L_1 ) ;
if ( V_7 )
goto V_17;
V_7 = F_2 ( V_18 , L_1 ) ;
if ( V_7 )
goto V_19;
F_4 ( V_3 ) ;
F_4 ( V_9 ) ;
F_4 ( V_13 ) ;
F_5 ( V_8 , 0 ) ;
F_5 ( V_16 , 0 ) ;
F_5 ( V_18 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_18 , 1 ) ;
F_4 ( V_11 ) ;
F_4 ( V_5 ) ;
F_8 ( V_18 ) ;
V_19:
F_8 ( V_16 ) ;
V_17:
F_8 ( V_8 ) ;
V_15:
if ( V_7 )
F_3 ( L_3 , V_20 , V_7 ) ;
F_10 ( 1 ) ;
}
static int F_11 ( struct V_21 * V_22 )
{
return F_12 ( V_22 -> V_23 , V_24 ) ;
}
static int F_13 ( struct V_21 * V_22 )
{
return F_12 ( V_22 -> V_23 , V_25 |
V_26 | V_27 ) ;
}
static int T_2 F_14 ( char * V_28 )
{
if ( ! strcmp ( V_28 , L_4 ) )
V_29 = true ;
else if ( ! strcmp ( V_28 , L_5 ) )
V_29 = false ;
else
F_15 ( L_6
L_7 ) ;
return 1 ;
}
static void T_2 F_16 ( void )
{
F_17 () ;
F_18 ( V_30 , F_19 ( V_30 ) ) ;
F_20 ( NULL ) ;
F_21 ( V_31 , F_19 ( V_31 ) ) ;
F_22 () ;
F_23 ( & V_32 ) ;
F_24 ( & V_33 ) ;
F_25 ( & V_32 ) ;
F_26 ( 0 , V_34 ,
F_19 ( V_34 ) ) ;
F_27 ( & V_35 ) ;
F_28 () ;
F_29 ( & V_36 ) ;
if ( V_29 ) {
V_37 . V_38 = F_30 ( V_39 |
V_40 ) ;
if ( V_37 . V_38 )
F_31 ( & V_37 ) ;
}
F_32 ( & V_41 ) ;
if ( ! V_29 )
F_33 ( & V_42 ) ;
F_34 () ;
}
static void T_2 F_35 ( void )
{
F_36 ( 0 , & V_43 ) ;
F_37 ( 0 , & V_44 ) ;
}
static void T_2 F_38 ( void )
{
F_39 () ;
}
