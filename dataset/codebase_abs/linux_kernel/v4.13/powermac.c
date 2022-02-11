static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
char * V_7 ;
int V_8 ;
V_8 = F_2 ( & V_2 -> V_9 , V_10 , V_11 , V_12 , 0 , & V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_8 = F_3 ( V_4 , & V_6 ) ) < 0 )
goto V_13;
V_4 -> V_14 = V_6 ;
switch ( V_6 -> V_15 ) {
case V_16 :
strcpy ( V_4 -> V_17 , L_1 ) ;
strcpy ( V_4 -> V_18 , L_2 ) ;
sprintf ( V_4 -> V_19 , L_3 ,
V_4 -> V_18 , V_6 -> V_20 , V_6 -> V_21 ) ;
if ( ( V_8 = F_4 ( V_6 ) ) < 0 )
goto V_13;
break;
case V_22 :
strcpy ( V_4 -> V_17 , L_4 ) ;
strcpy ( V_4 -> V_18 , L_5 ) ;
sprintf ( V_4 -> V_19 , L_3 ,
V_4 -> V_18 , V_6 -> V_20 , V_6 -> V_21 ) ;
if ( ( V_8 = F_5 ( V_6 ) ) < 0 )
goto V_13;
break;
case V_23 :
case V_24 :
V_7 = V_6 -> V_15 == V_23 ? L_6 : L_7 ;
sprintf ( V_4 -> V_17 , L_8 , V_7 ) ;
sprintf ( V_4 -> V_18 , L_9 , V_7 ) ;
sprintf ( V_4 -> V_19 , L_3 ,
V_4 -> V_18 , V_6 -> V_20 , V_6 -> V_21 ) ;
if ( F_6 ( V_6 ) < 0 || F_7 () < 0 )
goto V_13;
break;
case V_25 :
case V_26 :
V_7 = V_6 -> V_15 == V_26 ? L_10 : L_11 ;
sprintf ( V_4 -> V_17 , L_8 , V_7 ) ;
sprintf ( V_4 -> V_18 , L_9 , V_7 ) ;
if ( V_6 -> V_27 )
V_7 = L_12 ;
else if ( V_6 -> V_28 )
V_7 = L_13 ;
else
V_7 = L_14 ;
sprintf ( V_4 -> V_19 , L_15 ,
V_4 -> V_18 , V_7 , V_6 -> V_29 ) ;
if ( ( V_8 = F_8 ( V_6 ) ) < 0 )
goto V_13;
break;
default:
F_9 ( V_30 L_16 , V_6 -> V_15 ) ;
V_8 = - V_31 ;
goto V_13;
}
if ( ( V_8 = F_10 ( V_6 ) ) < 0 )
goto V_13;
V_6 -> V_32 = 1 ;
if ( V_33 )
F_11 ( V_6 ) ;
if ( ( V_8 = F_12 ( V_4 ) ) < 0 )
goto V_13;
F_13 ( V_2 , V_4 ) ;
return 0 ;
V_13:
F_14 ( V_4 ) ;
return V_8 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_14 ( F_16 ( V_2 ) ) ;
return 0 ;
}
static int F_17 ( struct V_34 * V_9 )
{
struct V_3 * V_4 = F_18 ( V_9 ) ;
F_19 ( V_4 -> V_14 ) ;
return 0 ;
}
static int F_20 ( struct V_34 * V_9 )
{
struct V_3 * V_4 = F_18 ( V_9 ) ;
F_21 ( V_4 -> V_14 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
int V_8 ;
if ( ( V_8 = F_23 ( & V_35 ) ) < 0 )
return V_8 ;
V_34 = F_24 ( V_36 , - 1 , NULL , 0 ) ;
return 0 ;
}
static void T_2 F_25 ( void )
{
if ( ! F_26 ( V_34 ) )
F_27 ( V_34 ) ;
F_28 ( & V_35 ) ;
}
