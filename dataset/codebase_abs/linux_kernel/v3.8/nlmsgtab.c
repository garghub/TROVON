static int F_1 ( T_1 V_1 , T_2 * V_2 , struct F_1 * V_3 , T_3 V_4 )
{
int V_5 , V_6 = - V_7 ;
for ( V_5 = 0 ; V_5 < V_4 / sizeof( struct F_1 ) ; V_5 ++ )
if ( V_1 == V_3 [ V_5 ] . V_1 ) {
* V_2 = V_3 [ V_5 ] . V_2 ;
V_6 = 0 ;
break;
}
return V_6 ;
}
int F_2 ( T_1 V_8 , T_1 V_1 , T_2 * V_2 )
{
int V_6 = 0 ;
switch ( V_8 ) {
case V_9 :
V_6 = F_1 ( V_1 , V_2 , V_10 ,
sizeof( V_10 ) ) ;
break;
case V_11 :
V_6 = F_1 ( V_1 , V_2 , V_12 ,
sizeof( V_12 ) ) ;
break;
case V_13 :
V_6 = F_1 ( V_1 , V_2 , V_14 ,
sizeof( V_14 ) ) ;
break;
case V_15 :
if ( ( V_1 >= V_16 &&
V_1 <= V_17 ) ||
( V_1 >= V_18 &&
V_1 <= V_19 ) ) {
* V_2 = V_20 ;
} else {
V_6 = F_1 ( V_1 , V_2 , V_21 ,
sizeof( V_21 ) ) ;
}
break;
default:
V_6 = - V_22 ;
break;
}
return V_6 ;
}
