static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
F_2 ( V_4 ) ;
switch ( V_6 ) {
case 3 :
case 1 :
F_3 ( V_2 , L_1 , V_6 ) ;
break;
case 0 :
F_3 ( V_2 , L_2 ) ;
break;
default:
F_4 ( V_2 , L_3 , V_6 ) ;
V_6 = 1 ;
}
if ( V_6 == 3 && F_5 ( V_4 , 3 , 3 ) < 0 ) {
F_4 ( V_2 , L_4 ) ;
V_6 = 1 ;
}
if ( V_6 == 1 && F_6 ( V_4 ) ) {
F_4 ( V_2 , L_5 ) ;
V_6 = 0 ;
}
V_2 -> V_7 = V_6 ;
V_5 = F_7 ( V_2 , V_4 -> V_8 ) ;
if ( V_5 )
goto V_9;
F_8 ( & V_2 -> V_10 ) ;
V_5 = F_9 ( V_2 ) ;
F_10 ( & V_2 -> V_10 ) ;
if ( V_5 )
goto V_11;
F_11 ( V_2 , L_6 , V_2 -> V_12 ) ;
return 0 ;
V_11:
F_12 ( V_2 , V_4 -> V_8 ) ;
F_13 ( V_4 ) ;
V_9:
F_14 ( V_4 ) ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_14 ( V_4 ) ;
F_12 ( V_2 , V_4 -> V_8 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , const struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 = & V_4 -> V_16 ;
void T_1 * V_17 ;
int V_5 ;
F_17 ( & V_4 -> V_16 , V_18 L_7 ,
( int ) V_4 -> V_19 , ( int ) V_4 -> V_15 , ( int ) V_4 -> V_20 ) ;
if ( F_18 ( V_4 , 0 ) != V_21 ) {
F_19 ( & V_4 -> V_16 , L_8 V_18 L_9
L_10 ,
( V_22 ) F_18 ( V_4 , 0 ) , V_21 ) ;
return - V_23 ;
}
V_5 = F_20 ( V_4 ) ;
if ( V_5 ) {
F_19 ( & V_4 -> V_16 , L_11 ) ;
return - V_23 ;
}
V_5 = F_21 ( V_4 , 0 , V_18 ) ;
if ( V_5 ) {
F_19 ( & V_4 -> V_16 , L_12 ) ;
goto V_24;
}
V_17 = F_22 ( V_4 , 0 ) ;
if ( ! V_17 ) {
F_19 ( & V_4 -> V_16 , L_13 ) ;
V_5 = - V_23 ;
goto V_25;
}
F_17 ( & V_4 -> V_16 , L_14 , & V_4 -> V_26 [ 0 ] , V_17 ) ;
V_2 = F_23 ( V_16 , V_17 ) ;
if ( F_24 ( V_2 ) ) {
V_5 = ( int ) F_25 ( V_2 ) ;
F_19 ( V_16 , L_15 , V_5 ) ;
goto V_27;
}
F_26 ( V_4 , V_2 ) ;
V_2 -> V_4 = V_4 ;
F_27 ( V_2 ) ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_16 ) ;
goto V_28;
}
V_5 = F_28 ( V_2 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_17 , V_5 ) ;
goto V_29;
}
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
return 0 ;
V_29:
F_15 ( V_2 ) ;
V_28:
F_31 ( V_2 ) ;
V_27:
F_32 ( V_4 , V_17 ) ;
V_25:
F_33 ( V_4 , 0 ) ;
V_24:
F_34 ( V_4 ) ;
return V_5 ;
}
static void F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_36 ( V_4 ) ;
F_37 ( V_2 ) ;
F_15 ( V_2 ) ;
F_38 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_4 , V_2 -> V_17 ) ;
F_33 ( V_4 , 0 ) ;
F_34 ( V_4 ) ;
}
