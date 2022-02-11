int F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
enum V_5 V_6 , struct V_7 * * V_8 )
{
int V_9 ;
switch ( V_4 ) {
case V_10 :
V_9 = F_2 ( V_8 ) ;
break;
case V_11 :
V_9 = F_3 ( V_8 ) ;
break;
default:
V_9 = - V_12 ;
break;
}
if ( V_9 )
return V_9 ;
( * V_8 ) -> V_2 = V_2 ;
( * V_8 ) -> V_4 = V_4 ;
( * V_8 ) -> V_6 = V_6 ;
return 0 ;
}
int F_4 ( struct V_7 * V_7 )
{
int V_9 ;
switch ( V_7 -> V_2 -> V_13 ) {
case 0x0005 :
V_9 = F_5 ( V_7 ) ;
break;
case 0x000B :
V_9 = F_6 ( V_7 ) ;
break;
default:
V_9 = - V_12 ;
break;
}
return V_9 ;
}
unsigned int F_7 ( unsigned int V_14 , unsigned int V_15 )
{
int V_16 ;
F_8 ( ! V_15 ) ;
for ( V_16 = 0 ; ! ( V_15 & ( 1 << V_16 ) ) ; )
V_16 ++ ;
return ( V_14 & V_15 ) >> V_16 ;
}
void F_9 ( unsigned int * V_14 , unsigned int V_15 , unsigned int V_17 )
{
int V_16 ;
F_8 ( ! V_15 ) ;
for ( V_16 = 0 ; ! ( V_15 & ( 1 << V_16 ) ) ; )
V_16 ++ ;
* V_14 = ( * V_14 & ( ~ V_15 ) ) | ( ( V_17 << V_16 ) & V_15 ) ;
}
