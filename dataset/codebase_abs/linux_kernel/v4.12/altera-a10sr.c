static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_5 :
case V_7 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_17 :
case V_18 :
case V_19 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_12 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_20 * V_21 )
{
int V_22 ;
struct V_23 * V_24 ;
V_24 = F_5 ( & V_21 -> V_2 , sizeof( * V_24 ) ,
V_25 ) ;
if ( ! V_24 )
return - V_26 ;
V_21 -> V_27 = V_28 ;
V_21 -> V_29 = 8 ;
F_6 ( V_21 ) ;
V_24 -> V_2 = & V_21 -> V_2 ;
F_7 ( V_21 , V_24 ) ;
V_24 -> V_30 = F_8 ( V_21 , & V_31 ) ;
if ( F_9 ( V_24 -> V_30 ) ) {
V_22 = F_10 ( V_24 -> V_30 ) ;
F_11 ( & V_21 -> V_2 , L_1 ,
V_22 ) ;
return V_22 ;
}
V_22 = F_12 ( V_24 -> V_2 , V_32 ,
V_33 ,
F_13 ( V_33 ) ,
NULL , 0 , NULL ) ;
if ( V_22 )
F_11 ( V_24 -> V_2 , L_2 ,
V_22 ) ;
return V_22 ;
}
