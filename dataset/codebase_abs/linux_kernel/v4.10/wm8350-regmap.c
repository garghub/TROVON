static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_4 [ V_3 ] . V_5 ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_6 * V_6 = F_3 ( V_2 ) ;
if ( ! V_6 -> V_7 ) {
if ( ( V_3 >= V_8 &&
V_3 <= V_9 ) ||
( V_3 >= V_10 &&
V_3 <= V_11 ) )
return false ;
}
return V_4 [ V_3 ] . V_12 ;
}
static bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_4 [ V_3 ] . V_13 ;
}
static bool F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return true ;
default:
return false ;
}
}
