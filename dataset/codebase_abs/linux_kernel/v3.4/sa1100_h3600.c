static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
switch ( V_2 -> V_4 ) {
case 0 :
V_2 -> V_5 [ V_6 ] . V_7 = V_8 ;
V_2 -> V_5 [ V_6 ] . V_9 = L_1 ;
V_2 -> V_5 [ V_10 ] . V_7 = V_11 ;
V_2 -> V_5 [ V_10 ] . V_9 = L_2 ;
V_3 = F_2 ( V_12 , L_3 ) ;
if ( V_3 )
goto V_13;
V_3 = F_3 ( V_12 , 0 ) ;
if ( V_3 )
goto V_14;
V_3 = F_2 ( V_15 , L_4 ) ;
if ( V_3 )
goto V_14;
V_3 = F_3 ( V_15 , 0 ) ;
if ( V_3 )
goto V_16;
V_3 = F_2 ( V_17 , L_5 ) ;
if ( V_3 )
goto V_16;
V_3 = F_3 ( V_17 , 0 ) ;
if ( V_3 )
goto V_18;
V_3 = F_2 ( V_19 , L_6 ) ;
if ( V_3 )
goto V_18;
V_3 = F_3 ( V_19 , 0 ) ;
if ( V_3 )
goto V_20;
break;
case 1 :
V_2 -> V_5 [ V_6 ] . V_7 = V_21 ;
V_2 -> V_5 [ V_6 ] . V_9 = L_7 ;
V_2 -> V_5 [ V_10 ] . V_7 = V_22 ;
V_2 -> V_5 [ V_10 ] . V_9 = L_8 ;
break;
}
return 0 ;
V_20: F_4 ( V_19 ) ;
V_18: F_4 ( V_17 ) ;
V_16: F_4 ( V_15 ) ;
V_14: F_4 ( V_12 ) ;
V_13: F_4 ( V_11 ) ;
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_4 ) {
case 0 :
F_6 ( V_12 , 0 ) ;
F_6 ( V_15 , 0 ) ;
F_6 ( V_17 , 1 ) ;
F_4 ( V_19 ) ;
F_4 ( V_17 ) ;
F_4 ( V_15 ) ;
F_4 ( V_12 ) ;
break;
case 1 :
break;
}
}
static void
F_7 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
V_24 -> V_25 = 0 ;
V_24 -> V_26 = 0 ;
V_24 -> V_27 = 0 ;
V_24 -> V_28 = 0 ;
}
static int
F_8 ( struct V_1 * V_2 , const T_1 * V_24 )
{
if ( V_24 -> V_29 != 0 && V_24 -> V_29 != 33 && V_24 -> V_29 != 50 ) {
F_9 ( V_30 L_9 ,
V_24 -> V_29 / 10 , V_24 -> V_29 % 10 ) ;
return - 1 ;
}
F_6 ( V_19 , ! ! ( V_24 -> V_31 & V_32 ) ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_12 , 1 ) ;
F_6 ( V_15 , 1 ) ;
F_6 ( V_17 , 0 ) ;
F_11 ( 10 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 == 1 ) {
F_6 ( V_15 , 0 ) ;
F_6 ( V_12 , 0 ) ;
F_6 ( V_17 , 1 ) ;
}
}
int T_2 F_13 ( struct V_33 * V_34 )
{
int V_35 = - V_36 ;
if ( F_14 () || F_15 () )
V_35 = F_16 ( V_34 , & V_37 , 0 , 2 ) ;
return V_35 ;
}
