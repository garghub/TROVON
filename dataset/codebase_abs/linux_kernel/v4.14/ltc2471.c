static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = F_2 ( V_2 , ( char * ) & V_4 , sizeof( V_4 ) ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 != sizeof( V_4 ) )
return - V_5 ;
return F_3 ( V_4 ) ;
}
static int F_4 ( struct V_6 * V_7 ,
struct V_8 const * V_9 ,
int * V_10 , int * V_11 , long V_12 )
{
struct V_13 * V_14 = F_5 ( V_7 ) ;
int V_3 ;
switch ( V_12 ) {
case V_15 :
V_3 = F_1 ( V_14 -> V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_10 = V_3 ;
return V_16 ;
case V_17 :
if ( V_9 -> V_18 )
* V_10 = 2 * V_19 ;
else
* V_10 = V_19 ;
* V_11 = 16 ;
return V_20 ;
case V_21 :
* V_10 = - V_19 ;
return V_16 ;
default:
return - V_22 ;
}
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_6 * V_7 ;
struct V_13 * V_14 ;
int V_3 ;
if ( ! F_7 ( V_2 -> V_25 , V_26 ) )
return - V_27 ;
V_7 = F_8 ( & V_2 -> V_28 , sizeof( * V_14 ) ) ;
if ( ! V_7 )
return - V_29 ;
V_14 = F_5 ( V_7 ) ;
V_14 -> V_2 = V_2 ;
V_7 -> V_28 . V_30 = & V_2 -> V_28 ;
V_7 -> V_31 = V_24 -> V_31 ;
V_7 -> V_12 = & V_32 ;
V_7 -> V_33 = V_34 ;
if ( V_24 -> V_35 == V_36 )
V_7 -> V_37 = V_38 ;
else
V_7 -> V_37 = V_39 ;
V_7 -> V_40 = 1 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_9 ( & V_2 -> V_28 , L_1 ) ;
return V_3 ;
}
return F_10 ( & V_2 -> V_28 , V_7 ) ;
}
