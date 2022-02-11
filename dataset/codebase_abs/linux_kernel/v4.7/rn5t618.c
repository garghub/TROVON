static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 ... V_7 :
case V_8 ... V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return true ;
default:
return false ;
}
}
static void F_2 ( void )
{
F_3 ( V_14 -> V_15 , V_16 ,
V_17 , 0 ) ;
F_3 ( V_14 -> V_15 , V_18 ,
V_19 , V_19 ) ;
}
static int F_4 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
struct V_24 * V_25 ;
int V_26 ;
V_25 = F_5 ( & V_21 -> V_2 , sizeof( * V_25 ) , V_27 ) ;
if ( ! V_25 )
return - V_28 ;
F_6 ( V_21 , V_25 ) ;
V_25 -> V_15 = F_7 ( V_21 , & V_29 ) ;
if ( F_8 ( V_25 -> V_15 ) ) {
V_26 = F_9 ( V_25 -> V_15 ) ;
F_10 ( & V_21 -> V_2 , L_1 , V_26 ) ;
return V_26 ;
}
V_26 = F_11 ( & V_21 -> V_2 , - 1 , V_30 ,
F_12 ( V_30 ) , NULL , 0 , NULL ) ;
if ( V_26 ) {
F_10 ( & V_21 -> V_2 , L_2 , V_26 ) ;
return V_26 ;
}
if ( ! V_31 ) {
V_14 = V_25 ;
V_31 = F_2 ;
}
return 0 ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_24 * V_25 = F_14 ( V_21 ) ;
if ( V_25 == V_14 ) {
V_14 = NULL ;
V_31 = NULL ;
}
return 0 ;
}
