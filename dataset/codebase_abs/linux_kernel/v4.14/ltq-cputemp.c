static void F_1 ( void )
{
F_2 ( F_3 ( V_1 ) | V_2 , V_1 ) ;
}
static void F_4 ( void * V_3 )
{
F_2 ( F_3 ( V_1 ) & ~ V_2 , V_1 ) ;
}
static int F_5 ( struct V_4 * V_5 , enum V_6 type ,
T_1 V_7 , int V_8 , long * V_9 )
{
int V_10 ;
switch ( V_7 ) {
case V_11 :
V_10 = ( F_3 ( V_1 ) >> 9 ) & 0x01FF ;
V_10 = V_10 * 5 ;
V_10 -= 380 ;
V_10 = V_10 * 100 ;
break;
default:
return - V_12 ;
}
* V_9 = V_10 ;
return 0 ;
}
static T_2 F_6 ( const void * V_13 , enum V_6 type ,
T_1 V_7 , int V_8 )
{
if ( type != V_14 )
return 0 ;
switch ( V_7 ) {
case V_11 :
return 0444 ;
default:
return 0 ;
}
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_4 * V_17 ;
int V_18 = 0 ;
if ( F_8 () != V_19 )
return - V_20 ;
V_18 = F_9 ( & V_16 -> V_5 , F_4 , NULL ) ;
if ( V_18 )
return V_18 ;
F_1 () ;
V_17 = F_10 ( & V_16 -> V_5 ,
L_1 ,
NULL ,
& V_21 ,
NULL ) ;
if ( F_11 ( V_17 ) ) {
F_12 ( & V_16 -> V_5 , L_2 ) ;
return F_13 ( V_17 ) ;
}
return 0 ;
}
