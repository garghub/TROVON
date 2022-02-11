static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
switch ( V_2 -> V_4 ) {
case 0 :
V_3 = F_2 ( V_5 , L_1 ) ;
if ( V_3 )
goto V_6;
V_3 = F_3 ( V_5 ) ;
if ( V_3 )
goto V_7;
V_2 -> V_8 . V_9 = F_4 ( V_5 ) ;
V_3 = F_2 ( V_10 , L_2 ) ;
if ( V_3 )
goto V_7;
V_3 = F_3 ( V_10 ) ;
if ( V_3 )
goto V_11;
V_12 [ 0 ] . V_13 = F_4 ( V_10 ) ;
V_3 = F_2 ( V_14 , L_3 ) ;
if ( V_3 )
goto V_11;
V_3 = F_5 ( V_14 , 0 ) ;
if ( V_3 )
goto V_15;
V_3 = F_2 ( V_16 , L_4 ) ;
if ( V_3 )
goto V_15;
V_3 = F_5 ( V_16 , 0 ) ;
if ( V_3 )
goto V_17;
V_3 = F_2 ( V_18 , L_5 ) ;
if ( V_3 )
goto V_17;
V_3 = F_5 ( V_18 , 0 ) ;
if ( V_3 )
goto V_19;
V_3 = F_2 ( V_20 , L_6 ) ;
if ( V_3 )
goto V_19;
V_3 = F_5 ( V_20 , 0 ) ;
if ( V_3 )
goto V_21;
V_3 = F_6 ( V_2 , V_12 , F_7 ( V_12 ) ) ;
if ( V_3 )
goto V_21;
break;
case 1 :
V_3 = F_2 ( V_22 , L_7 ) ;
if ( V_3 )
goto V_23;
V_3 = F_3 ( V_22 ) ;
if ( V_3 )
goto V_24;
V_2 -> V_8 . V_9 = F_4 ( V_22 ) ;
V_3 = F_2 ( V_25 , L_8 ) ;
if ( V_3 )
goto V_24;
V_3 = F_3 ( V_25 ) ;
if ( V_3 )
goto V_26;
V_12 [ 1 ] . V_13 = F_4 ( V_25 ) ;
V_3 = F_6 ( V_2 , V_12 , F_7 ( V_12 ) ) ;
if ( V_3 )
goto V_26;
break;
}
return 0 ;
V_21: F_8 ( V_20 ) ;
V_19: F_8 ( V_18 ) ;
V_17: F_8 ( V_16 ) ;
V_15: F_8 ( V_14 ) ;
V_11: F_8 ( V_10 ) ;
V_7: F_8 ( V_5 ) ;
V_6: return V_3 ;
V_26: F_8 ( V_10 ) ;
V_24: F_8 ( V_5 ) ;
V_23: return V_3 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_12 , F_7 ( V_12 ) ) ;
switch ( V_2 -> V_4 ) {
case 0 :
F_11 ( V_14 , 0 ) ;
F_11 ( V_16 , 0 ) ;
F_11 ( V_18 , 1 ) ;
F_8 ( V_20 ) ;
F_8 ( V_18 ) ;
F_8 ( V_16 ) ;
F_8 ( V_14 ) ;
F_8 ( V_10 ) ;
F_8 ( V_5 ) ;
break;
case 1 :
F_8 ( V_25 ) ;
F_8 ( V_22 ) ;
break;
}
}
static void
F_12 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
switch ( V_2 -> V_4 ) {
case 0 :
V_28 -> V_29 = ! F_13 ( V_10 ) ;
V_28 -> V_30 = ! ! F_13 ( V_5 ) ;
V_28 -> V_31 = 0 ;
V_28 -> V_32 = 0 ;
V_28 -> V_33 = 0 ;
V_28 -> V_34 = 0 ;
V_28 -> V_35 = 0 ;
break;
case 1 :
V_28 -> V_29 = ! F_13 ( V_25 ) ;
V_28 -> V_30 = ! ! F_13 ( V_22 ) ;
V_28 -> V_31 = 0 ;
V_28 -> V_32 = 0 ;
V_28 -> V_33 = 0 ;
V_28 -> V_34 = 0 ;
V_28 -> V_35 = 0 ;
break;
}
}
static int
F_14 ( struct V_1 * V_2 , const T_1 * V_28 )
{
if ( V_28 -> V_36 != 0 && V_28 -> V_36 != 33 && V_28 -> V_36 != 50 ) {
F_15 ( V_37 L_9 ,
V_28 -> V_36 / 10 , V_28 -> V_36 % 10 ) ;
return - 1 ;
}
F_11 ( V_20 , ! ! ( V_28 -> V_38 & V_39 ) ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_11 ( V_14 , 1 ) ;
F_11 ( V_16 , 1 ) ;
F_11 ( V_18 , 0 ) ;
F_17 ( 10 ) ;
F_18 ( V_2 , V_12 , F_7 ( V_12 ) ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_12 , F_7 ( V_12 ) ) ;
if ( V_2 -> V_4 == 1 ) {
F_11 ( V_16 , 0 ) ;
F_11 ( V_14 , 0 ) ;
F_11 ( V_18 , 1 ) ;
}
}
int T_2 F_21 ( struct V_40 * V_41 )
{
int V_42 = - V_43 ;
if ( F_22 () || F_23 () )
V_42 = F_24 ( V_41 , & V_44 , 0 , 2 ) ;
return V_42 ;
}
