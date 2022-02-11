static unsigned int F_1 ( int V_1 , int V_2 )
{
switch ( V_2 ) {
case V_3 :
return V_1 == V_4 ?
V_5 :
V_6 ;
case V_7 :
return V_1 == V_4 ?
V_8 :
V_9 ;
case V_10 :
if ( V_1 == V_4 )
return V_11 ;
default:
return V_12 ;
}
}
int F_2 ( T_1 V_13 , unsigned int * V_14 )
{
struct V_15 * V_16 = F_3 ( V_17 ,
V_18 ) ;
* V_14 = F_4 ( V_16 , V_13 ) ;
return ( * V_14 > 0 ) ? * V_14 : - V_19 ;
}
int F_5 ( struct V_20 * V_21 , T_1 V_13 , int V_1 ,
int V_2 )
{
struct V_22 V_23 ;
if ( F_6 ( ! V_17 ) ) {
F_7 ( L_1 ) ;
return - V_19 ;
}
V_23 . V_24 = V_17 ;
V_23 . V_25 [ 0 ] = V_13 ;
V_23 . V_25 [ 1 ] = F_1 ( V_1 , V_2 ) ;
V_23 . V_26 = 2 ;
return F_8 ( & V_23 ) ;
}
void F_9 ( T_1 V_13 )
{
struct V_15 * V_16 = F_3 ( V_17 ,
V_18 ) ;
int V_14 = F_4 ( V_16 , V_13 ) ;
F_10 ( V_14 ) ;
}
void T_2 F_11 ( enum V_27 V_28 ,
struct V_29 * V_24 )
{
V_30 = V_28 ;
V_17 = V_24 ;
}
