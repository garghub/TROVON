static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , 0 ,
V_7 , 128 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
switch ( F_4 ( V_9 ) ) {
case V_10 :
V_11 . V_12 = 16 ;
break;
case V_13 :
V_11 . V_12 = 32 ;
break;
default:
V_5 = - V_14 ;
}
V_11 . V_15 = V_16 ;
F_5 ( V_4 , V_2 ,
& V_11 ) ;
return V_5 ;
}
static T_1 int F_6 ( struct V_17 * V_18 )
{
int V_19 ;
struct V_20 * V_21 ;
V_21 = F_7 ( V_18 , V_22 , 0 ) ;
if ( ! V_21 ) {
F_8 ( & V_18 -> V_23 , L_1 ) ;
return - V_14 ;
}
V_11 . V_24 = V_21 -> V_25
+ V_26 ;
V_21 = F_7 ( V_18 , V_27 , 0 ) ;
if ( ! V_21 ) {
F_8 ( & V_18 -> V_23 , L_2 ) ;
return - V_14 ;
}
V_11 . V_28 = V_21 -> V_25 ;
V_19 = F_9 ( & V_18 -> V_23 , & V_29 ) ;
return V_19 ;
}
static int T_2 F_10 ( struct V_17 * V_18 )
{
F_11 ( & V_18 -> V_23 ) ;
return 0 ;
}
