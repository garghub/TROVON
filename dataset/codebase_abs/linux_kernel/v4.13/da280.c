static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 = V_3 ? V_5 : V_6 ;
return F_2 ( V_2 , V_7 , V_4 ) ;
}
static int F_3 ( struct V_8 * V_9 ,
struct V_10 const * V_11 ,
int * V_12 , int * V_13 , long V_14 )
{
struct V_15 * V_4 = F_4 ( V_9 ) ;
int V_16 ;
switch ( V_14 ) {
case V_17 :
V_16 = F_5 ( V_4 -> V_2 , V_11 -> V_18 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_12 = ( short ) V_16 >> 2 ;
return V_19 ;
case V_20 :
* V_12 = 0 ;
* V_13 = V_21 ;
return V_22 ;
default:
return - V_23 ;
}
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
int V_16 ;
struct V_8 * V_9 ;
struct V_15 * V_4 ;
V_16 = F_7 ( V_2 , V_26 ) ;
if ( V_16 != V_27 )
return ( V_16 < 0 ) ? V_16 : - V_28 ;
V_9 = F_8 ( & V_2 -> V_29 , sizeof( * V_4 ) ) ;
if ( ! V_9 )
return - V_30 ;
V_4 = F_4 ( V_9 ) ;
V_4 -> V_2 = V_2 ;
F_9 ( V_2 , V_9 ) ;
V_9 -> V_29 . V_31 = & V_2 -> V_29 ;
V_9 -> V_32 = & V_33 ;
V_9 -> V_34 = V_35 ;
V_9 -> V_36 = V_37 ;
if ( V_25 -> V_38 == V_39 ) {
V_9 -> V_40 = L_1 ;
V_9 -> V_41 = 2 ;
} else {
V_9 -> V_40 = L_2 ;
V_9 -> V_41 = 3 ;
}
V_16 = F_1 ( V_2 , true ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_10 ( V_9 ) ;
if ( V_16 < 0 ) {
F_11 ( & V_2 -> V_29 , L_3 ) ;
F_1 ( V_2 , false ) ;
}
return V_16 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_13 ( V_2 ) ;
F_14 ( V_9 ) ;
return F_1 ( V_2 , false ) ;
}
static int F_15 ( struct V_42 * V_29 )
{
return F_1 ( F_16 ( V_29 ) , false ) ;
}
static int F_17 ( struct V_42 * V_29 )
{
return F_1 ( F_16 ( V_29 ) , true ) ;
}
