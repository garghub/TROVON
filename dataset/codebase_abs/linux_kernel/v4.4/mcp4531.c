static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 = V_4 -> V_11 << V_12 ;
T_1 V_13 ;
switch ( V_7 ) {
case V_14 :
V_13 = F_3 ( V_9 -> V_15 ,
V_16 | V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_5 = V_13 ;
return V_17 ;
case V_18 :
* V_5 = 1000 * V_19 [ V_9 -> V_20 ] . V_21 ;
* V_6 = V_19 [ V_9 -> V_20 ] . V_22 ;
return V_23 ;
}
return - V_24 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 , int V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 = V_4 -> V_11 << V_12 ;
switch ( V_7 ) {
case V_14 :
if ( V_5 > V_19 [ V_9 -> V_20 ] . V_22 || V_5 < 0 )
return - V_24 ;
break;
default:
return - V_24 ;
}
return F_5 ( V_9 -> V_15 ,
V_25 | V_10 | ( V_5 >> 8 ) ,
V_5 & 0xff ) ;
}
static int F_6 ( struct V_26 * V_15 ,
const struct V_27 * V_28 )
{
struct V_29 * V_30 = & V_15 -> V_30 ;
unsigned long V_20 = V_28 -> V_31 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
if ( ! F_7 ( V_15 -> V_32 ,
V_33 ) ) {
F_8 ( V_30 , L_1 ) ;
return - V_34 ;
}
V_2 = F_9 ( V_30 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_35 ;
V_9 = F_2 ( V_2 ) ;
F_10 ( V_15 , V_2 ) ;
V_9 -> V_15 = V_15 ;
V_9 -> V_20 = V_20 ;
V_2 -> V_30 . V_36 = V_30 ;
V_2 -> V_37 = & V_38 ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = V_19 [ V_20 ] . V_42 ;
V_2 -> V_43 = V_15 -> V_43 ;
return F_11 ( V_30 , V_2 ) ;
}
