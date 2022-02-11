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
* V_14 = F_3 ( NULL , V_13 ) ;
return ( * V_14 > 0 ) ? * V_14 : - V_15 ;
}
int F_4 ( struct V_16 * V_17 , T_1 V_13 , int V_1 ,
int V_2 )
{
unsigned int V_14 ;
unsigned int V_18 = F_1 ( V_1 , V_2 ) ;
V_14 = F_5 ( NULL , V_13 ) ;
if ( ! V_14 )
return - V_15 ;
if ( V_18 != V_12 &&
V_18 != F_6 ( V_14 ) )
F_7 ( V_14 , V_18 ) ;
return V_14 ;
}
void F_8 ( T_1 V_13 )
{
int V_14 = F_3 ( NULL , V_13 ) ;
F_9 ( V_14 ) ;
}
