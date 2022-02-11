static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_14 ;
unsigned int V_15 ;
int V_16 ;
switch ( F_2 ( V_4 ) ) {
case 2 :
V_15 = V_17 |
V_18 |
V_19 ;
break;
case 4 :
V_15 = V_20 |
V_21 |
V_19 ;
break;
default:
return - V_22 ;
}
V_16 = F_3 ( V_9 , V_15 ) ;
if ( V_16 < 0 ) {
F_4 ( V_14 -> V_23 , L_1 ) ;
return V_16 ;
}
V_16 = F_3 ( V_10 , V_15 ) ;
if ( V_16 < 0 ) {
F_4 ( V_14 -> V_23 , L_2 ) ;
return V_16 ;
}
return 0 ;
}
static T_1 int F_5 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( & V_25 -> V_23 ) ;
struct V_28 * V_29 = V_25 -> V_23 . V_30 ;
struct V_13 * V_14 = & V_31 ;
int V_16 = 0 ;
V_14 -> V_23 = & V_25 -> V_23 ;
if ( V_29 ) {
struct V_28 * V_32 ;
if ( F_7 ( V_14 , L_3 ) ) {
F_4 ( & V_25 -> V_23 , L_4 ) ;
return - V_33 ;
}
V_32 = F_8 ( V_29 , L_5 , 0 ) ;
if ( ! V_32 ) {
F_4 ( & V_25 -> V_23 , L_6 ) ;
return - V_22 ;
}
V_34 [ 0 ] . V_35 = NULL ;
V_34 [ 0 ] . V_36 = V_32 ;
} else if ( V_27 ) {
if ( V_27 -> V_37 ) {
V_14 -> V_38 = V_27 -> V_37 ;
} else {
F_4 ( & V_25 -> V_23 , L_4 ) ;
return - V_33 ;
}
} else {
F_4 ( & V_25 -> V_23 , L_7 ) ;
return - V_33 ;
}
V_16 = F_9 ( V_14 ) ;
if ( V_16 ) {
F_4 ( & V_25 -> V_23 , L_8 ,
V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int T_2 F_10 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = F_11 ( V_25 ) ;
F_12 ( V_14 ) ;
return 0 ;
}
