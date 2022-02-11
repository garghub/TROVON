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
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 ,
const void * V_13 , T_1 V_14 )
{
if ( ! V_2 -> V_8
&& ! F_2 ( V_2 , V_3 )
&& V_3 < V_2 -> V_6 -> V_7 )
return - V_15 ;
return F_9 ( V_2 -> V_11 , V_3 , V_13 , V_14 ) ;
}
int F_10 ( struct V_1 * V_2 ,
int V_16 , int V_17 ,
enum V_18 V_19 )
{
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_2 -> V_22 = F_1 ;
V_2 -> V_23 = F_5 ;
V_2 -> V_24 = F_8 ;
V_21 . V_25 = V_16 ;
V_21 . V_26 = V_17 ;
switch ( V_19 ) {
#if F_11 ( V_27 ) || F_11 ( V_28 )
case V_29 :
V_2 -> V_11 = F_12 ( F_13 ( V_2 -> V_30 ) ,
& V_21 ) ;
break;
#endif
#if F_11 ( V_31 ) || F_11 ( V_32 )
case V_33 :
V_2 -> V_11 = F_14 ( F_15 ( V_2 -> V_30 ) ,
& V_21 ) ;
break;
#endif
case V_34 :
break;
default:
return - V_15 ;
}
if ( F_16 ( V_2 -> V_11 ) )
return F_17 ( V_2 -> V_11 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
int V_16 , int V_17 ,
enum V_18 V_19 )
{
return - V_35 ;
}
