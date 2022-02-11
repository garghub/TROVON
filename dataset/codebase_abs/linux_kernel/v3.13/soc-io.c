static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
int V_5 ;
if ( ! F_2 ( V_2 , V_3 ) &&
V_3 < V_2 -> V_6 -> V_7 &&
! V_2 -> V_8 ) {
V_5 = F_3 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return - 1 ;
}
if ( V_2 -> V_9 ) {
V_2 -> V_10 = 1 ;
return 0 ;
}
return F_4 ( V_2 -> V_11 , V_3 , V_4 ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_5 ;
unsigned int V_12 ;
if ( V_3 >= V_2 -> V_6 -> V_7 ||
F_2 ( V_2 , V_3 ) ||
V_2 -> V_8 ) {
if ( V_2 -> V_9 )
return - 1 ;
V_5 = F_6 ( V_2 -> V_11 , V_3 , & V_12 ) ;
if ( V_5 == 0 )
return V_12 ;
else
return - 1 ;
}
V_5 = F_7 ( V_2 , V_3 , & V_12 ) ;
if ( V_5 < 0 )
return - 1 ;
return V_12 ;
}
int F_8 ( struct V_1 * V_2 ,
int V_13 , int V_14 ,
enum V_15 V_16 )
{
struct V_17 V_18 ;
int V_5 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_2 -> V_19 = F_1 ;
V_2 -> V_20 = F_5 ;
V_18 . V_21 = V_13 ;
V_18 . V_22 = V_14 ;
switch ( V_16 ) {
#if F_9 ( V_23 ) || F_9 ( V_24 )
case V_25 :
V_2 -> V_11 = F_10 ( F_11 ( V_2 -> V_26 ) ,
& V_18 ) ;
break;
#endif
#if F_9 ( V_27 ) || F_9 ( V_28 )
case V_29 :
V_2 -> V_11 = F_12 ( F_13 ( V_2 -> V_26 ) ,
& V_18 ) ;
break;
#endif
case V_30 :
V_2 -> V_31 = true ;
if ( ! V_2 -> V_11 )
V_2 -> V_11 = F_14 ( V_2 -> V_26 , NULL ) ;
if ( V_2 -> V_11 ) {
V_5 = F_15 ( V_2 -> V_11 ) ;
if ( V_5 > 0 )
V_2 -> V_32 = V_5 ;
}
break;
default:
return - V_33 ;
}
return F_16 ( V_2 -> V_11 ) ;
}
int F_8 ( struct V_1 * V_2 ,
int V_13 , int V_14 ,
enum V_15 V_16 )
{
return - V_34 ;
}
