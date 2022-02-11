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
V_29 = 1 ;
else if ( ! strcmp ( V_28 , L_5 ) )
V_29 = 0 ;
else
F_15 ( L_6
L_7 ) ;
return 0 ;
}
static void T_2 F_16 ( void )
{
F_17 ( V_30 , F_18 ( V_30 ) ) ;
F_19 ( 3 ,
V_31 |
F_20 ( 0 ) |
V_32 ,
F_21 ( 0 ) ) ;
F_19 ( 0 ,
V_31 |
F_22 ( 3 ) |
V_33 ,
F_21 ( 3 ) ) ;
F_23 ( NULL ) ;
F_24 ( V_34 , F_18 ( V_34 ) ) ;
F_25 ( NULL ) ;
F_26 ( & V_35 ) ;
F_27 ( & V_36 ) ;
F_28 ( 0 , & V_37 ) ;
F_29 ( & V_35 ) ;
F_30 ( 0 , V_38 ,
F_18 ( V_38 ) ) ;
F_31 ( & V_39 ) ;
F_32 ( & V_40 ) ;
F_33 ( & V_41 ) ;
if ( V_29 ) {
V_42 . V_43 = F_34 ( V_44 |
V_45 ) ;
if ( V_42 . V_43 )
F_35 ( & V_42 ) ;
}
F_36 ( & V_46 ) ;
if ( ! V_29 )
F_37 ( & V_47 ) ;
F_38 ( NULL ) ;
F_39 ( 0 , & V_48 ) ;
}
static void T_2 F_40 ( void )
{
F_41 () ;
}
