static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 V_11 ;
T_1 V_12 = 0 ;
F_2 ( V_13 ) ;
int V_14 ;
V_6 = F_3 ( V_4 , sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_6 -> V_4 = V_4 ;
V_6 -> type = (enum V_17 ) F_4 ( V_4 ) ;
V_14 = F_5 ( V_8 , 0 , & V_11 ) ;
if ( V_14 < 0 ) {
F_6 ( V_4 , L_1 ) ;
return V_14 ;
}
V_6 -> V_18 = F_7 ( V_4 , V_11 . V_19 ,
F_8 ( & V_11 ) ) ;
if ( ! V_6 -> V_18 ) {
F_6 ( V_4 , L_2 ) ;
return - V_16 ;
}
V_6 -> V_20 = V_11 . V_19 ;
if ( F_9 ( V_8 , L_3 ) ) {
T_2 V_21 ;
V_14 = F_10 ( V_8 , L_4 ,
& V_21 ) ;
if ( V_14 ) {
F_6 ( V_4 ,
L_5 ) ;
return V_14 ;
}
V_6 -> V_22 . V_23 = V_21 ;
V_6 -> V_24 = true ;
}
V_6 -> V_25 = F_11 ( V_4 , L_6 ) ;
if ( F_12 ( V_6 -> V_25 ) ) {
if ( F_13 ( V_6 -> V_25 ) == - V_26 )
return - V_26 ;
V_6 -> V_25 = NULL ;
}
V_14 = F_14 ( V_8 , 0 , 0xff , & V_13 ,
& V_12 ) ;
if ( V_14 ) {
F_6 ( V_4 , L_7 ) ;
return V_14 ;
}
switch ( V_6 -> type ) {
case V_27 :
case V_28 :
break;
default:
V_6 -> V_29 = V_30 ;
}
V_14 = F_15 ( V_6 , & V_13 ) ;
if ( V_14 ) {
F_6 ( V_4 , L_8 ) ;
F_16 ( & V_13 ) ;
return V_14 ;
}
F_17 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_19 ( V_2 ) ;
return F_20 ( V_6 ) ;
}
