static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 = V_4 -> V_11 ;
int V_12 ;
T_1 V_13 [ V_2 -> V_14 ] ;
switch ( V_7 ) {
case V_15 :
V_12 = F_3 ( V_9 -> V_16 , V_13 ,
V_2 -> V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_5 = V_13 [ V_10 ] ;
return V_17 ;
case V_18 :
* V_5 = 1000 * V_9 -> V_19 -> V_20 ;
* V_6 = V_21 ;
return V_22 ;
}
return - V_23 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 , int V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 = V_4 -> V_11 ;
if ( V_6 != 0 )
return - V_23 ;
switch ( V_7 ) {
case V_15 :
if ( V_5 > V_21 || V_5 < 0 )
return - V_23 ;
break;
default:
return - V_23 ;
}
return F_5 ( V_9 -> V_16 , F_6 ( V_10 ) , V_5 ) ;
}
static int F_7 ( struct V_24 * V_16 ,
const struct V_25 * V_26 )
{
struct V_27 * V_28 = & V_16 -> V_28 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_8 ( V_28 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_29 ;
F_9 ( V_16 , V_2 ) ;
V_9 = F_2 ( V_2 ) ;
V_9 -> V_16 = V_16 ;
V_9 -> V_19 = & V_30 [ V_26 -> V_31 ] ;
V_2 -> V_28 . V_32 = V_28 ;
V_2 -> V_33 = & V_34 ;
V_2 -> V_35 = V_36 ;
V_2 -> V_14 = F_10 ( V_36 ) ;
V_2 -> V_37 = V_16 -> V_37 ;
return F_11 ( V_28 , V_2 ) ;
}
