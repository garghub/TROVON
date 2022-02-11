static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
const struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = V_4 -> V_11 ;
struct V_12 V_13 ;
T_1 V_14 = 0 ;
F_2 ( V_15 ) ;
int V_16 ;
V_6 = F_3 ( V_17 , V_4 ) ;
if ( ! V_6 )
return - V_18 ;
V_8 = F_4 ( V_4 , sizeof( * V_8 ) , V_19 ) ;
if ( ! V_8 )
return - V_20 ;
V_8 -> V_4 = V_4 ;
V_8 -> type = (enum V_21 ) V_6 -> V_22 ;
V_16 = F_5 ( V_10 , 0 , & V_13 ) ;
if ( V_16 < 0 ) {
F_6 ( V_4 , L_1 ) ;
return V_16 ;
}
V_8 -> V_23 = F_7 ( V_4 , V_13 . V_24 , F_8 ( & V_13 ) ) ;
if ( ! V_8 -> V_23 ) {
F_6 ( V_4 , L_2 ) ;
return - V_20 ;
}
V_8 -> V_25 = V_13 . V_24 ;
if ( F_9 ( V_10 , L_3 ) ) {
T_2 V_26 ;
V_16 = F_10 ( V_10 , L_4 ,
& V_26 ) ;
if ( V_16 ) {
F_6 ( V_4 ,
L_5 ) ;
return V_16 ;
}
V_8 -> V_27 . V_28 = V_26 ;
V_8 -> V_29 = true ;
}
V_8 -> V_30 = F_11 ( V_4 , L_6 ) ;
if ( F_12 ( V_8 -> V_30 ) ) {
if ( F_13 ( V_8 -> V_30 ) == - V_31 )
return - V_31 ;
V_8 -> V_30 = NULL ;
}
V_16 = F_14 ( V_10 , 0 , 0xff , & V_15 , & V_14 ) ;
if ( V_16 ) {
F_6 ( V_4 ,
L_7 ) ;
return V_16 ;
}
switch ( V_8 -> type ) {
case V_32 :
case V_33 :
break;
default:
V_8 -> V_34 = V_35 ;
}
V_16 = F_15 ( V_8 , & V_15 ) ;
if ( V_16 )
F_6 ( V_4 , L_8 ) ;
F_16 ( & V_15 ) ;
F_17 ( V_2 , V_8 ) ;
return V_16 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_19 ( V_2 ) ;
return F_20 ( V_8 ) ;
}
