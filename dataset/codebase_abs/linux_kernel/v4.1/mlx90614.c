static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 ;
T_2 V_11 ;
switch ( V_7 ) {
case V_12 :
switch ( V_4 -> V_13 ) {
case V_14 :
V_10 = V_15 ;
break;
case V_16 :
switch ( V_4 -> V_4 ) {
case 0 :
V_10 = V_17 ;
break;
case 1 :
V_10 = V_18 ;
break;
default:
return - V_19 ;
}
break;
default:
return - V_19 ;
}
V_11 = F_3 ( V_9 -> V_20 , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_5 = V_11 ;
return V_21 ;
case V_22 :
* V_5 = 13657 ;
* V_6 = 500000 ;
return V_23 ;
case V_24 :
* V_5 = 20 ;
return V_21 ;
default:
return - V_19 ;
}
}
static int F_4 ( struct V_25 * V_20 )
{
T_2 V_11 ;
V_11 = F_3 ( V_20 , V_26 ) ;
if ( V_11 < 0 )
return V_11 ;
return ( V_11 & V_27 ) ? 1 : 0 ;
}
static int F_5 ( struct V_25 * V_20 ,
const struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_11 ;
if ( ! F_6 ( V_20 -> V_30 , V_31 ) )
return - V_32 ;
V_2 = F_7 ( & V_20 -> V_33 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_34 ;
V_9 = F_2 ( V_2 ) ;
F_8 ( V_20 , V_2 ) ;
V_9 -> V_20 = V_20 ;
V_2 -> V_33 . V_35 = & V_20 -> V_33 ;
V_2 -> V_36 = V_29 -> V_36 ;
V_2 -> V_37 = V_38 ;
V_2 -> V_39 = & V_40 ;
V_11 = F_4 ( V_20 ) ;
switch ( V_11 ) {
case 0 :
F_9 ( & V_20 -> V_33 , L_1 ) ;
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = 2 ;
break;
case 1 :
F_9 ( & V_20 -> V_33 , L_2 ) ;
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = 3 ;
break;
default:
return V_11 ;
}
return F_10 ( V_2 ) ;
}
static int F_11 ( struct V_25 * V_20 )
{
F_12 ( F_13 ( V_20 ) ) ;
return 0 ;
}
