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
return 0 ;
V_11:
F_11 ( V_2 , V_4 -> V_8 ) ;
F_12 ( V_4 ) ;
V_9:
F_13 ( V_4 ) ;
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_13 ( V_4 ) ;
F_11 ( V_2 , V_4 -> V_8 ) ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 , const struct V_12 * V_13 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 = & V_4 -> V_15 ;
void T_1 * V_16 ;
int V_5 ;
F_16 ( & V_4 -> V_15 , V_17 L_6 ,
( int ) V_4 -> V_18 , ( int ) V_4 -> V_14 , ( int ) V_4 -> V_19 ) ;
if ( F_17 ( V_4 , 0 ) != V_20 ) {
F_18 ( & V_4 -> V_15 , L_7 V_17 L_8
L_9 ,
( V_21 ) F_17 ( V_4 , 0 ) , V_20 ) ;
return - V_22 ;
}
V_5 = F_19 ( V_4 ) ;
if ( V_5 ) {
F_18 ( & V_4 -> V_15 , L_10 ) ;
return - V_22 ;
}
V_5 = F_20 ( V_4 , 0 , V_17 ) ;
if ( V_5 ) {
F_18 ( & V_4 -> V_15 , L_11 ) ;
goto V_23;
}
V_16 = F_21 ( V_4 , 0 ) ;
if ( ! V_16 ) {
F_18 ( & V_4 -> V_15 , L_12 ) ;
V_5 = - V_22 ;
goto V_24;
}
F_16 ( & V_4 -> V_15 , L_13 , & V_4 -> V_25 [ 0 ] , V_16 ) ;
V_2 = F_22 ( V_15 , V_16 ) ;
if ( F_23 ( V_2 ) ) {
V_5 = ( int ) F_24 ( V_2 ) ;
F_18 ( V_15 , L_14 , V_5 ) ;
goto V_26;
}
F_25 ( V_4 , V_2 ) ;
V_2 -> V_4 = V_4 ;
F_26 ( V_2 ) ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_15 ) ;
goto V_27;
}
V_5 = F_27 ( V_2 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_16 , V_5 ) ;
goto V_28;
}
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
return 0 ;
V_28:
F_14 ( V_2 ) ;
V_27:
F_30 ( V_2 ) ;
V_26:
F_31 ( V_4 , V_16 ) ;
V_24:
F_32 ( V_4 , 0 ) ;
V_23:
F_33 ( V_4 ) ;
return V_5 ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
F_36 ( V_2 ) ;
F_14 ( V_2 ) ;
F_37 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_4 , V_2 -> V_16 ) ;
F_32 ( V_4 , 0 ) ;
F_33 ( V_4 ) ;
}
