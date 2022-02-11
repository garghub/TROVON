static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 ;
switch ( V_7 ) {
case V_11 :
switch ( V_4 -> V_12 ) {
case V_13 :
V_10 = F_3 ( V_9 -> V_14 ,
V_15 | V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
break;
case V_17 :
V_10 = F_3 ( V_9 -> V_14 ,
V_15 | V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
break;
default:
return - V_19 ;
}
* V_5 = V_10 ;
return V_20 ;
case V_21 :
* V_5 = 13657 ;
* V_6 = 500000 ;
return V_22 ;
case V_23 :
* V_5 = 20 ;
return V_20 ;
default:
return - V_19 ;
}
}
static int F_4 ( struct V_24 * V_14 ,
const struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
if ( ! F_5 ( V_14 -> V_27 , V_28 ) )
return - V_29 ;
V_2 = F_6 ( & V_14 -> V_30 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_31 ;
V_9 = F_2 ( V_2 ) ;
F_7 ( V_14 , V_2 ) ;
V_9 -> V_14 = V_14 ;
V_2 -> V_30 . V_32 = & V_14 -> V_30 ;
V_2 -> V_33 = V_26 -> V_33 ;
V_2 -> V_34 = V_35 ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = F_8 ( V_39 ) ;
return F_9 ( V_2 ) ;
}
static int F_10 ( struct V_24 * V_14 )
{
F_11 ( F_12 ( V_14 ) ) ;
return 0 ;
}
