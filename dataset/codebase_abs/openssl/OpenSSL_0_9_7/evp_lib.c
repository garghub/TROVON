int F_1 ( T_1 * V_1 , T_2 * type )
{
int V_2 ;
if ( V_1 -> V_3 -> V_4 != NULL )
V_2 = V_1 -> V_3 -> V_4 ( V_1 , type ) ;
else
V_2 = 1 ;
return ( V_2 ) ;
}
int F_2 ( T_1 * V_1 , T_2 * type )
{
int V_2 ;
if ( V_1 -> V_3 -> V_5 != NULL )
V_2 = V_1 -> V_3 -> V_5 ( V_1 , type ) ;
else
V_2 = 1 ;
return ( V_2 ) ;
}
int F_3 ( T_1 * V_1 , T_2 * type )
{
int V_6 = 0 , V_7 ;
if ( type != NULL )
{
V_7 = F_4 ( V_1 ) ;
F_5 ( V_7 <= sizeof V_1 -> V_8 ) ;
V_6 = F_6 ( type , V_1 -> V_9 , V_7 ) ;
if ( V_6 != V_7 )
return ( - 1 ) ;
else if ( V_6 > 0 )
memcpy ( V_1 -> V_8 , V_1 -> V_9 , V_7 ) ;
}
return ( V_6 ) ;
}
int F_7 ( T_1 * V_1 , T_2 * type )
{
int V_6 = 0 , V_10 ;
if ( type != NULL )
{
V_10 = F_4 ( V_1 ) ;
F_5 ( V_10 <= sizeof V_1 -> V_8 ) ;
V_6 = F_8 ( type , V_1 -> V_9 , V_10 ) ;
}
return ( V_6 ) ;
}
int F_9 ( const T_3 * V_11 )
{
int V_12 ;
T_4 * V_13 ;
V_12 = F_10 ( V_11 ) ;
switch( V_12 ) {
case V_14 :
case V_15 :
case V_16 :
return V_14 ;
case V_17 :
case V_18 :
return V_17 ;
default:
V_13 = F_11 ( V_12 ) ;
if( ! V_13 || ! V_13 -> V_19 ) V_12 = V_20 ;
F_12 ( V_13 ) ;
return V_12 ;
}
}
