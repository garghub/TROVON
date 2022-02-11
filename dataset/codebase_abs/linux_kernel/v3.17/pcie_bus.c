static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
int V_6 = V_4 -> V_7 ;
V_4 -> V_7 = 0 ;
F_2 ( V_4 ) ;
switch ( V_8 ) {
case 3 :
case 1 :
F_3 ( V_2 , L_1 , V_8 ) ;
break;
case 0 :
F_3 ( V_2 , L_2 ) ;
break;
default:
F_4 ( V_2 , L_3 , V_8 ) ;
V_8 = 1 ;
}
if ( V_8 == 3 && F_5 ( V_4 , 3 , 3 ) < 0 ) {
F_4 ( V_2 , L_4 ) ;
V_8 = 1 ;
}
if ( V_8 == 1 && F_6 ( V_4 ) ) {
F_4 ( V_2 , L_5 ) ;
V_8 = 0 ;
}
V_2 -> V_9 = V_8 ;
if ( ( V_2 -> V_9 == 0 ) && V_6 ) {
F_4 ( V_2 , L_6 ) ;
V_5 = - V_10 ;
goto V_11;
}
V_5 = F_7 ( V_2 , V_4 -> V_12 ) ;
if ( V_5 )
goto V_11;
F_8 ( & V_2 -> V_13 ) ;
V_5 = F_9 ( V_2 ) ;
F_10 ( & V_2 -> V_13 ) ;
if ( V_14 )
V_5 = 0 ;
if ( V_5 )
goto V_15;
return 0 ;
V_15:
F_11 ( V_2 , V_4 -> V_12 ) ;
F_12 ( V_4 ) ;
V_11:
F_13 ( V_4 ) ;
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_13 ( V_4 ) ;
F_11 ( V_2 , V_4 -> V_12 ) ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 , const struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 = & V_4 -> V_19 ;
void T_1 * V_20 ;
struct V_21 * V_22 = (struct V_21 * ) V_17 -> V_23 ;
int V_5 ;
F_16 ( & V_4 -> V_19 , V_24
L_7 , V_22 -> V_25 ,
( int ) V_4 -> V_26 , ( int ) V_4 -> V_18 , ( int ) V_4 -> V_27 ) ;
if ( F_17 ( V_4 , 0 ) != V_28 ) {
F_18 ( & V_4 -> V_19 , L_8 V_24 L_9
L_10 ,
( V_29 ) F_17 ( V_4 , 0 ) , V_28 ) ;
return - V_10 ;
}
V_5 = F_19 ( V_4 ) ;
if ( V_5 ) {
F_18 ( & V_4 -> V_19 ,
L_11 ) ;
V_4 -> V_7 = 1 ;
V_5 = F_19 ( V_4 ) ;
}
if ( V_5 )
return - V_10 ;
V_5 = F_20 ( V_4 , 0 , V_24 ) ;
if ( V_5 ) {
F_18 ( & V_4 -> V_19 , L_12 ) ;
goto V_30;
}
V_20 = F_21 ( V_4 , 0 ) ;
if ( ! V_20 ) {
F_18 ( & V_4 -> V_19 , L_13 ) ;
V_5 = - V_10 ;
goto V_31;
}
F_16 ( & V_4 -> V_19 , L_14 , & V_4 -> V_32 [ 0 ] , V_20 ) ;
V_2 = F_22 ( V_19 , V_20 ) ;
if ( F_23 ( V_2 ) ) {
V_5 = ( int ) F_24 ( V_2 ) ;
F_18 ( V_19 , L_15 , V_5 ) ;
goto V_33;
}
F_25 ( V_4 , V_2 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_22 = V_22 ;
F_26 ( V_2 ) ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_16 ) ;
goto V_34;
}
V_5 = F_27 ( V_2 ) ;
if ( V_5 ) {
F_4 ( V_2 , L_17 , V_5 ) ;
goto V_35;
}
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
return 0 ;
V_35:
F_14 ( V_2 ) ;
V_34:
F_30 ( V_2 ) ;
V_33:
F_31 ( V_4 , V_20 ) ;
V_31:
F_32 ( V_4 , 0 ) ;
V_30:
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
F_31 ( V_4 , V_2 -> V_20 ) ;
F_32 ( V_4 , 0 ) ;
F_33 ( V_4 ) ;
}
