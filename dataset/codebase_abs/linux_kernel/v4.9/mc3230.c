static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_4 = F_2 ( V_6 , V_7 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 , V_4 ) ;
return V_4 ;
}
V_4 &= ~ V_9 ;
V_4 |= V_3 ;
V_4 = F_4 ( V_6 , V_7 , V_4 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_8 , L_2 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_5 ( struct V_10 * V_11 ,
struct V_12 const * V_13 ,
int * V_14 , int * V_15 , long V_16 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
int V_4 ;
switch ( V_16 ) {
case V_17 :
V_4 = F_2 ( V_2 -> V_6 , V_13 -> V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_14 = F_7 ( V_4 , 7 ) ;
return V_19 ;
case V_20 :
* V_14 = 0 ;
* V_15 = V_21 ;
return V_22 ;
default:
return - V_23 ;
}
}
static int F_8 ( struct V_5 * V_6 ,
const struct V_24 * V_25 )
{
int V_4 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
V_4 = F_2 ( V_6 , V_26 ) ;
if ( V_4 != V_27 )
return ( V_4 < 0 ) ? V_4 : - V_28 ;
V_4 = F_2 ( V_6 , V_29 ) ;
if ( V_4 != V_30 )
return ( V_4 < 0 ) ? V_4 : - V_28 ;
V_11 = F_9 ( & V_6 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_11 ) {
F_3 ( & V_6 -> V_8 , L_3 ) ;
return - V_31 ;
}
V_2 = F_6 ( V_11 ) ;
V_2 -> V_6 = V_6 ;
F_10 ( V_6 , V_11 ) ;
V_11 -> V_8 . V_32 = & V_6 -> V_8 ;
V_11 -> V_33 = & V_34 ;
V_11 -> V_35 = L_4 ;
V_11 -> V_36 = V_37 ;
V_11 -> V_38 = V_39 ;
V_11 -> V_40 = F_11 ( V_39 ) ;
V_4 = F_1 ( V_2 , V_41 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_12 ( V_11 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_8 , L_5 ) ;
F_1 ( V_2 , V_42 ) ;
}
return V_4 ;
}
static int F_13 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = F_14 ( V_6 ) ;
F_15 ( V_11 ) ;
return F_1 ( F_6 ( V_11 ) , V_42 ) ;
}
static int F_16 ( struct V_43 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( F_14 ( F_17 ( V_8 ) ) ) ;
return F_1 ( V_2 , V_42 ) ;
}
static int F_18 ( struct V_43 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( F_14 ( F_17 ( V_8 ) ) ) ;
return F_1 ( V_2 , V_41 ) ;
}
