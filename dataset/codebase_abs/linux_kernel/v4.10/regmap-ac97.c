bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
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
case V_20 :
return true ;
default:
return false ;
}
}
static int F_2 ( void * V_21 , unsigned int V_3 ,
unsigned int * V_22 )
{
struct V_23 * V_24 = V_21 ;
* V_22 = V_24 -> V_25 -> V_26 -> V_27 ( V_24 , V_3 ) ;
return 0 ;
}
static int F_3 ( void * V_21 , unsigned int V_3 ,
unsigned int V_22 )
{
struct V_23 * V_24 = V_21 ;
V_24 -> V_25 -> V_26 -> V_28 ( V_24 , V_3 , V_22 ) ;
return 0 ;
}
struct V_29 * F_4 ( struct V_23 * V_24 ,
const struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 )
{
return F_5 ( & V_24 -> V_2 , & V_35 , V_24 , V_31 ,
V_33 , V_34 ) ;
}
struct V_29 * F_6 ( struct V_23 * V_24 ,
const struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 )
{
return F_7 ( & V_24 -> V_2 , & V_35 , V_24 , V_31 ,
V_33 , V_34 ) ;
}
