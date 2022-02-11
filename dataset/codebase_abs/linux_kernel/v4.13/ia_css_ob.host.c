void
F_1 (
struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
}
void
F_2 (
struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_1 * V_2 ,
unsigned V_9 )
{
unsigned int V_10
= V_2 -> V_3 == 2 ? V_11 : V_2 -> V_4 ;
unsigned int V_12 = 16 - V_10 ;
( void ) V_9 ;
switch ( V_8 -> V_13 ) {
case V_14 :
V_6 -> V_15 = V_8 -> V_16 >> V_12 ;
V_6 -> V_17 = V_8 -> V_18 >> V_12 ;
V_6 -> V_19 = V_8 -> V_20 >> V_12 ;
V_6 -> V_21 = V_8 -> V_22 >> V_12 ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 0 ;
V_6 -> V_25 = 0 ;
break;
case V_26 :
V_6 -> V_15 = 0 ;
V_6 -> V_17 = 0 ;
V_6 -> V_19 = 0 ;
V_6 -> V_21 = 0 ;
V_6 -> V_23 = V_8 -> V_27 ;
V_6 -> V_24 =
( V_8 -> V_28 - V_8 -> V_27 ) + 1 ;
V_6 -> V_25 = V_29 / V_6 -> V_24 ;
break;
default:
V_6 -> V_15 = 0 ;
V_6 -> V_17 = 0 ;
V_6 -> V_19 = 0 ;
V_6 -> V_21 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 0 ;
V_6 -> V_25 = 0 ;
break;
}
}
void
F_3 (
struct V_30 * V_6 ,
const struct V_7 * V_8 ,
const struct V_1 * V_2 ,
unsigned V_9 )
{
struct V_5 V_31 ;
struct V_5 * V_32 = & V_31 ;
( void ) V_9 ;
F_2 ( & V_31 , V_8 , V_2 , sizeof( V_31 ) ) ;
{
unsigned V_33 ;
unsigned V_34 = V_32 -> V_23 ;
unsigned V_35 = V_32 -> V_24 ;
unsigned V_36 = V_34 ;
unsigned V_37 = V_36 + V_35 ;
T_1 V_38 = ~ 0 ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
if ( V_33 >= V_36 && V_33 < V_37 )
V_6 -> V_40 [ V_33 / V_41 ] [ V_33 % V_41 ] = V_38 ;
else
V_6 -> V_40 [ V_33 / V_41 ] [ V_33 % V_41 ] = 0 ;
}
}
}
void
F_4 (
const struct V_5 * V_32 ,
unsigned V_42 )
{
if ( ! V_32 ) return;
F_5 ( V_42 , L_1 ) ;
F_5 ( V_42 , L_2 ,
L_3 , V_32 -> V_15 ) ;
F_5 ( V_42 , L_2 ,
L_4 , V_32 -> V_17 ) ;
F_5 ( V_42 , L_2 ,
L_5 , V_32 -> V_19 ) ;
F_5 ( V_42 , L_2 ,
L_6 , V_32 -> V_21 ) ;
F_5 ( V_42 , L_2 ,
L_7 , V_32 -> V_23 ) ;
F_5 ( V_42 , L_2 ,
L_8 , V_32 -> V_24 ) ;
F_5 ( V_42 , L_2 ,
L_9 ,
V_32 -> V_25 ) ;
}
void
F_6 (
const struct V_7 * V_2 ,
unsigned V_42 )
{
F_5 ( V_42 ,
L_10
L_11
L_12
L_13 ,
V_2 -> V_13 ,
V_2 -> V_16 , V_2 -> V_18 ,
V_2 -> V_20 , V_2 -> V_22 ,
V_2 -> V_27 , V_2 -> V_28 ) ;
}
