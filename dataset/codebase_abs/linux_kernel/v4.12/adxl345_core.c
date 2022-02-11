static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 ;
int V_11 ;
switch ( V_7 ) {
case V_12 :
V_11 = F_3 ( V_9 -> V_13 , V_4 -> V_14 , & V_10 ,
sizeof( V_10 ) ) ;
if ( V_11 < 0 )
return V_11 ;
* V_5 = F_4 ( F_5 ( V_10 ) , 12 ) ;
return V_15 ;
case V_16 :
* V_5 = 0 ;
* V_6 = V_17 ;
return V_18 ;
}
return - V_19 ;
}
int F_6 ( struct V_20 * V_21 , struct V_13 * V_13 ,
const char * V_22 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
T_2 V_10 ;
int V_11 ;
V_11 = F_7 ( V_13 , V_23 , & V_10 ) ;
if ( V_11 < 0 ) {
F_8 ( V_21 , L_1 , V_11 ) ;
return V_11 ;
}
if ( V_10 != V_24 ) {
F_8 ( V_21 , L_2 ,
V_10 , V_24 ) ;
return - V_25 ;
}
V_2 = F_9 ( V_21 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_26 ;
V_9 = F_2 ( V_2 ) ;
F_10 ( V_21 , V_2 ) ;
V_9 -> V_13 = V_13 ;
V_9 -> V_27 = V_28 ;
V_11 = F_11 ( V_9 -> V_13 , V_29 ,
V_9 -> V_27 ) ;
if ( V_11 < 0 ) {
F_8 ( V_21 , L_3 , V_11 ) ;
return V_11 ;
}
V_2 -> V_21 . V_30 = V_21 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_31 = & V_32 ;
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = F_12 ( V_36 ) ;
V_11 = F_11 ( V_9 -> V_13 , V_38 ,
V_39 ) ;
if ( V_11 < 0 ) {
F_8 ( V_21 , L_4 , V_11 ) ;
return V_11 ;
}
V_11 = F_13 ( V_2 ) ;
if ( V_11 < 0 ) {
F_8 ( V_21 , L_5 , V_11 ) ;
F_11 ( V_9 -> V_13 , V_38 ,
V_40 ) ;
}
return V_11 ;
}
int F_14 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_15 ( V_21 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_16 ( V_2 ) ;
return F_11 ( V_9 -> V_13 , V_38 ,
V_40 ) ;
}
