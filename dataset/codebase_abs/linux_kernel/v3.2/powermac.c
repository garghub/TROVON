static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
char * V_7 ;
int V_8 ;
V_8 = F_2 ( V_9 , V_10 , V_11 , 0 , & V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 = F_3 ( V_4 , & V_6 ) ) < 0 )
goto V_12;
V_4 -> V_13 = V_6 ;
switch ( V_6 -> V_14 ) {
case V_15 :
strcpy ( V_4 -> V_16 , L_1 ) ;
strcpy ( V_4 -> V_17 , L_2 ) ;
sprintf ( V_4 -> V_18 , L_3 ,
V_4 -> V_17 , V_6 -> V_19 , V_6 -> V_20 ) ;
if ( ( V_8 = F_4 ( V_6 ) ) < 0 )
goto V_12;
break;
case V_21 :
strcpy ( V_4 -> V_16 , L_4 ) ;
strcpy ( V_4 -> V_17 , L_5 ) ;
sprintf ( V_4 -> V_18 , L_3 ,
V_4 -> V_17 , V_6 -> V_19 , V_6 -> V_20 ) ;
if ( ( V_8 = F_5 ( V_6 ) ) < 0 )
goto V_12;
break;
case V_22 :
case V_23 :
V_7 = V_6 -> V_14 == V_22 ? L_6 : L_7 ;
sprintf ( V_4 -> V_16 , L_8 , V_7 ) ;
sprintf ( V_4 -> V_17 , L_9 , V_7 ) ;
sprintf ( V_4 -> V_18 , L_3 ,
V_4 -> V_17 , V_6 -> V_19 , V_6 -> V_20 ) ;
if ( F_6 ( V_6 ) < 0 || F_7 () < 0 )
goto V_12;
break;
case V_24 :
case V_25 :
V_7 = V_6 -> V_14 == V_25 ? L_10 : L_11 ;
sprintf ( V_4 -> V_16 , L_8 , V_7 ) ;
sprintf ( V_4 -> V_17 , L_9 , V_7 ) ;
if ( V_6 -> V_26 )
V_7 = L_12 ;
else if ( V_6 -> V_27 )
V_7 = L_13 ;
else
V_7 = L_14 ;
sprintf ( V_4 -> V_18 , L_15 ,
V_4 -> V_17 , V_7 , V_6 -> V_28 ) ;
if ( ( V_8 = F_8 ( V_6 ) ) < 0 )
goto V_12;
break;
default:
F_9 ( V_29 L_16 , V_6 -> V_14 ) ;
V_8 = - V_30 ;
goto V_12;
}
if ( ( V_8 = F_10 ( V_6 ) ) < 0 )
goto V_12;
V_6 -> V_31 = 1 ;
if ( V_32 )
F_11 ( V_6 ) ;
F_12 ( V_4 , & V_2 -> V_33 ) ;
if ( ( V_8 = F_13 ( V_4 ) ) < 0 )
goto V_12;
F_14 ( V_2 , V_4 ) ;
return 0 ;
V_12:
F_15 ( V_4 ) ;
return V_8 ;
}
static int T_2 F_16 ( struct V_1 * V_2 )
{
F_15 ( F_17 ( V_2 ) ) ;
F_14 ( V_2 , NULL ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_3 V_34 )
{
struct V_3 * V_4 = F_17 ( V_2 ) ;
F_19 ( V_4 -> V_13 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_17 ( V_2 ) ;
F_21 ( V_4 -> V_13 ) ;
return 0 ;
}
static int T_4 F_22 ( void )
{
int V_8 ;
if ( ( V_8 = F_23 ( & V_35 ) ) < 0 )
return V_8 ;
V_36 = F_24 ( V_37 , - 1 , NULL , 0 ) ;
return 0 ;
}
static void T_5 F_25 ( void )
{
if ( ! F_26 ( V_36 ) )
F_27 ( V_36 ) ;
F_28 ( & V_35 ) ;
}
