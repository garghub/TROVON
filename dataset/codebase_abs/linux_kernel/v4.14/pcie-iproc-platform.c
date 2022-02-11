static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 V_11 ;
T_1 V_12 = 0 ;
F_2 ( V_13 ) ;
struct V_14 * V_15 ;
int V_16 ;
V_15 = F_3 ( V_4 , sizeof( * V_6 ) ) ;
if ( ! V_15 )
return - V_17 ;
V_6 = F_4 ( V_15 ) ;
V_6 -> V_4 = V_4 ;
V_6 -> type = (enum V_18 ) F_5 ( V_4 ) ;
V_16 = F_6 ( V_8 , 0 , & V_11 ) ;
if ( V_16 < 0 ) {
F_7 ( V_4 , L_1 ) ;
return V_16 ;
}
V_6 -> V_19 = F_8 ( V_4 , V_11 . V_20 ,
F_9 ( & V_11 ) ) ;
if ( ! V_6 -> V_19 ) {
F_7 ( V_4 , L_2 ) ;
return - V_17 ;
}
V_6 -> V_21 = V_11 . V_20 ;
if ( F_10 ( V_8 , L_3 ) ) {
T_2 V_22 ;
V_16 = F_11 ( V_8 , L_4 ,
& V_22 ) ;
if ( V_16 ) {
F_7 ( V_4 ,
L_5 ) ;
return V_16 ;
}
V_6 -> V_23 . V_24 = V_22 ;
V_6 -> V_25 = true ;
}
V_6 -> V_26 = F_12 ( V_4 , L_6 ) ;
if ( F_13 ( V_6 -> V_26 ) ) {
if ( F_14 ( V_6 -> V_26 ) == - V_27 )
return - V_27 ;
V_6 -> V_26 = NULL ;
}
V_16 = F_15 ( V_8 , 0 , 0xff , & V_13 ,
& V_12 ) ;
if ( V_16 ) {
F_7 ( V_4 , L_7 ) ;
return V_16 ;
}
switch ( V_6 -> type ) {
case V_28 :
case V_29 :
break;
default:
V_6 -> V_30 = V_31 ;
}
V_16 = F_16 ( V_6 , & V_13 ) ;
if ( V_16 ) {
F_7 ( V_4 , L_8 ) ;
F_17 ( & V_13 ) ;
return V_16 ;
}
F_18 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_20 ( V_2 ) ;
return F_21 ( V_6 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_20 ( V_2 ) ;
F_23 ( V_6 ) ;
}
