static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned V_6 ;
T_1 V_7 ;
F_2 ( & V_5 -> V_8 ) ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_6 = V_11 ;
break;
case V_12 :
V_6 = V_13 ;
break;
default:
F_3 ( & V_5 -> V_8 ) ;
F_4 ( V_5 -> V_14 , L_1 , V_2 -> V_9 ) ;
return - V_15 ;
}
if ( V_3 ) {
V_7 = F_5 ( V_5 -> V_16 + V_17 ) ;
V_7 &= ~ F_6 ( V_6 ) ;
F_7 ( V_7 , V_5 -> V_16 + V_17 ) ;
F_8 ( 50 ) ;
} else {
V_7 = F_5 ( V_5 -> V_16 + V_17 ) ;
V_7 |= F_6 ( V_6 ) ;
F_7 ( V_7 , V_5 -> V_16 + V_17 ) ;
}
F_3 ( & V_5 -> V_8 ) ;
F_9 ( V_5 -> V_14 , L_2 , V_2 -> V_9 ,
V_3 ? L_3 : L_4 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_18 )
{
struct V_1 * V_2 = F_11 ( V_18 ) ;
return F_1 ( V_2 , true ) ;
}
static int F_12 ( struct V_2 * V_18 )
{
struct V_1 * V_2 = F_11 ( V_18 ) ;
return F_1 ( V_2 , false ) ;
}
static int F_13 ( struct V_19 * V_20 )
{
struct V_21 * V_14 = & V_20 -> V_14 ;
struct V_22 * V_23 = V_14 -> V_24 , * V_25 ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
unsigned V_30 = 0 ;
int V_31 ;
if ( F_14 ( V_23 ) == 0 ) {
F_4 ( V_14 , L_5 ) ;
return - V_32 ;
}
V_5 = F_15 ( V_14 , sizeof( * V_5 ) , V_33 ) ;
if ( ! V_5 )
return - V_34 ;
V_5 -> V_14 = V_14 ;
V_29 = F_16 ( V_20 , V_35 , 0 ) ;
V_5 -> V_16 = F_17 ( V_14 , V_29 ) ;
if ( F_18 ( V_5 -> V_16 ) )
return F_19 ( V_5 -> V_16 ) ;
F_20 ( & V_5 -> V_8 ) ;
F_21 (node, child) {
unsigned int V_9 ;
struct V_1 * V_18 ;
if ( F_22 ( V_25 , L_6 , & V_9 ) ) {
F_4 ( V_14 , L_7 ,
V_25 -> V_36 ) ;
V_31 = - V_15 ;
goto V_37;
}
if ( V_9 >= V_38 ) {
F_4 ( V_14 , L_8 , V_9 ) ;
V_31 = - V_15 ;
goto V_37;
}
if ( V_5 -> V_39 [ V_9 ] . V_2 ) {
F_4 ( V_14 , L_9 , V_9 ) ;
V_31 = - V_15 ;
goto V_37;
}
V_18 = & V_5 -> V_39 [ V_9 ] ;
V_18 -> V_2 = F_23 ( V_14 , V_25 , & V_40 ) ;
if ( F_18 ( V_18 -> V_2 ) ) {
F_4 ( V_14 , L_10 ) ;
V_31 = F_19 ( V_18 -> V_2 ) ;
goto V_37;
}
V_18 -> V_5 = V_5 ;
V_18 -> V_9 = V_9 ;
F_24 ( V_18 -> V_2 , V_18 ) ;
V_30 ++ ;
}
F_25 ( V_14 , V_5 ) ;
V_27 = F_26 ( V_14 , V_41 ) ;
if ( F_18 ( V_27 ) ) {
F_4 ( V_14 , L_11 ) ;
return F_19 ( V_27 ) ;
}
F_9 ( V_14 , L_12 , V_30 ) ;
return 0 ;
V_37:
F_27 ( V_25 ) ;
return V_31 ;
}
