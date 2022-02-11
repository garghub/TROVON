int F_1 ( const struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_6 :
case V_7 :
* V_3 = 1 ;
* V_4 = 1 ;
return 0 ;
case V_8 :
case V_9 :
* V_3 = 2 ;
* V_4 = 1 ;
return 0 ;
case V_10 :
* V_3 = 3 ;
* V_4 = 2 ;
return 0 ;
case V_11 :
* V_3 = 0 ;
* V_4 = 1 ;
return 0 ;
}
return - V_12 ;
}
T_1 F_2 ( T_2 V_13 , const struct V_1 * V_2 )
{
switch ( V_2 -> V_5 ) {
case V_6 :
return V_13 * V_2 -> V_14 / 8 ;
case V_8 :
case V_9 :
case V_7 :
return V_13 * 2 ;
case V_10 :
return V_13 * 3 / 2 ;
case V_11 :
return 0 ;
}
return - V_12 ;
}
const struct V_1 * F_3 (
enum V_15 V_16 ,
const struct V_17 * V_18 ,
int V_19 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ )
if ( V_18 [ V_20 ] . V_16 == V_16 )
return & V_18 [ V_20 ] . V_21 ;
return NULL ;
}
const struct V_1 * F_4 (
enum V_15 V_16 )
{
return F_3 ( V_16 , V_22 , F_5 ( V_22 ) ) ;
}
static int T_3 F_6 ( void )
{
return 0 ;
}
static void T_4 F_7 ( void )
{
}
