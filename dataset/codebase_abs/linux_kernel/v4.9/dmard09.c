static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 [ V_11 ] ;
int V_12 ;
T_2 V_13 ;
switch ( V_7 ) {
case V_14 :
V_12 = F_3 ( V_9 -> V_15 ,
V_16 ,
V_11 , V_10 ) ;
if ( V_12 < 0 ) {
F_4 ( & V_9 -> V_15 -> V_17 , L_1 ,
V_16 ) ;
return V_12 ;
}
V_13 = F_5 ( & V_10 [ V_4 -> V_18 ] ) ;
V_13 <<= 4 ;
V_13 >>= 7 ;
* V_5 = V_13 ;
return V_19 ;
default:
return - V_20 ;
}
}
static int F_6 ( struct V_21 * V_15 ,
const struct V_22 * V_23 )
{
int V_12 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_2 = F_7 ( & V_15 -> V_17 , sizeof( * V_9 ) ) ;
if ( ! V_2 ) {
F_4 ( & V_15 -> V_17 , L_2 ) ;
return - V_24 ;
}
V_9 = F_2 ( V_2 ) ;
V_9 -> V_15 = V_15 ;
V_12 = F_8 ( V_9 -> V_15 , V_25 ) ;
if ( V_12 < 0 ) {
F_4 ( & V_15 -> V_17 , L_3 , V_12 ) ;
return V_12 ;
}
if ( V_12 != V_26 ) {
F_4 ( & V_15 -> V_17 , L_4 , V_12 ) ;
return - V_27 ;
}
F_9 ( V_15 , V_2 ) ;
V_2 -> V_17 . V_28 = & V_15 -> V_17 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = V_32 ;
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = F_10 ( V_34 ) ;
V_2 -> V_36 = & V_37 ;
return F_11 ( & V_15 -> V_17 , V_2 ) ;
}
