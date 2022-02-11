static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_10 : {
int V_11 = F_3 ( V_9 -> V_12 , V_4 -> V_13 , V_5 ) ;
return V_11 ? V_11 : V_14 ;
}
case V_15 :
* V_5 = 1000 * V_16 [ V_9 -> V_17 ] . V_18 ;
* V_6 = V_16 [ V_9 -> V_17 ] . V_19 ;
return V_20 ;
}
return - V_21 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 , int V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_7 != V_10 )
return - V_21 ;
if ( V_5 >= V_16 [ V_9 -> V_17 ] . V_19 || V_5 < 0 )
return - V_21 ;
return F_5 ( V_9 -> V_12 , V_4 -> V_13 , V_5 ) ;
}
static int F_6 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 * V_27 = & V_23 -> V_27 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_7 ( V_27 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_28 ;
V_9 = F_2 ( V_2 ) ;
F_8 ( V_23 , V_2 ) ;
V_9 -> V_17 = V_25 -> V_29 ;
V_9 -> V_12 = F_9 ( V_23 , & V_30 ) ;
if ( F_10 ( V_9 -> V_12 ) ) {
F_11 ( V_27 , L_1 ) ;
return F_12 ( V_9 -> V_12 ) ;
}
V_2 -> V_27 . V_31 = V_27 ;
V_2 -> V_32 = & V_33 ;
V_2 -> V_34 = V_35 ;
V_2 -> V_36 = V_16 [ V_9 -> V_17 ] . V_37 ;
V_2 -> V_38 = V_23 -> V_38 ;
return F_13 ( V_27 , V_2 ) ;
}
