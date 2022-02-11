static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
F_2 ( V_4 ) ;
switch ( V_6 ) {
case 3 :
case 1 :
case 0 :
break;
default:
F_3 ( V_2 , L_1 ,
V_6 ) ;
V_6 = 1 ;
}
V_2 -> V_7 = V_6 ;
if ( V_2 -> V_7 ) {
F_4 ( V_2 , L_2 , V_6 ) ;
V_5 = F_5 ( V_4 , V_2 -> V_7 ) ;
if ( V_5 && ( V_2 -> V_7 == 3 ) ) {
F_3 ( V_2 , L_3 ) ;
V_2 -> V_7 = 1 ;
V_5 = F_5 ( V_4 , V_2 -> V_7 ) ;
}
if ( V_5 ) {
F_3 ( V_2 , L_4 ) ;
V_2 -> V_7 = 0 ;
}
} else {
F_4 ( V_2 , L_5 ) ;
}
V_5 = F_6 ( V_2 , V_4 -> V_8 ) ;
if ( V_5 )
goto V_9;
V_5 = F_7 ( V_2 ) ;
if ( V_5 )
goto V_10;
return 0 ;
V_10:
F_8 ( V_2 , V_4 -> V_8 ) ;
F_9 ( V_4 ) ;
V_9:
F_10 ( V_4 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_10 ( V_4 ) ;
F_8 ( V_2 , V_4 -> V_8 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 , const struct V_11 * V_12 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 = & V_4 -> V_14 ;
void T_1 * V_15 ;
int V_5 ;
F_13 ( & V_4 -> V_14 , V_16 L_6 ,
( int ) V_4 -> V_17 , ( int ) V_4 -> V_13 , ( int ) V_4 -> V_18 ) ;
if ( F_14 ( V_4 , 0 ) != V_19 ) {
F_15 ( & V_4 -> V_14 , L_7 V_16 L_8
L_9 ,
( V_20 ) F_14 ( V_4 , 0 ) , V_19 ) ;
return - V_21 ;
}
V_5 = F_16 ( V_4 ) ;
if ( V_5 ) {
F_15 ( & V_4 -> V_14 , L_10 ) ;
return - V_21 ;
}
V_5 = F_17 ( V_4 , 0 , V_16 ) ;
if ( V_5 ) {
F_15 ( & V_4 -> V_14 , L_11 ) ;
goto V_22;
}
V_15 = F_18 ( V_4 , 0 ) ;
if ( ! V_15 ) {
F_15 ( & V_4 -> V_14 , L_12 ) ;
V_5 = - V_21 ;
goto V_23;
}
F_13 ( & V_4 -> V_14 , L_13 , & V_4 -> V_24 [ 0 ] , V_15 ) ;
V_2 = F_19 ( V_14 , V_15 ) ;
if ( F_20 ( V_2 ) ) {
V_5 = ( int ) F_21 ( V_2 ) ;
F_15 ( V_14 , L_14 , V_5 ) ;
goto V_25;
}
F_22 ( V_4 , V_2 ) ;
V_2 -> V_4 = V_4 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_15 ) ;
goto V_26;
}
V_5 = F_23 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_16 , V_5 ) ;
goto V_27;
}
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
return 0 ;
V_27:
F_11 ( V_2 ) ;
V_26:
F_26 ( V_2 ) ;
V_25:
F_27 ( V_4 , V_15 ) ;
V_23:
F_28 ( V_4 , 0 ) ;
V_22:
F_29 ( V_4 ) ;
return V_5 ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
F_32 ( V_2 ) ;
F_11 ( V_2 ) ;
F_33 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_4 , V_2 -> V_15 ) ;
F_28 ( V_4 , 0 ) ;
F_29 ( V_4 ) ;
F_22 ( V_4 , NULL ) ;
}
