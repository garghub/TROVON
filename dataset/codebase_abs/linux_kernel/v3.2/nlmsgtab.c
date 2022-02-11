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
case V_12 :
V_6 = F_1 ( V_1 , V_2 , V_13 ,
sizeof( V_13 ) ) ;
break;
case V_14 :
V_6 = F_1 ( V_1 , V_2 , V_15 ,
sizeof( V_15 ) ) ;
break;
case V_16 :
V_6 = F_1 ( V_1 , V_2 , V_17 ,
sizeof( V_17 ) ) ;
break;
case V_18 :
if ( ( V_1 >= V_19 &&
V_1 <= V_20 ) ||
( V_1 >= V_21 &&
V_1 <= V_22 ) ) {
* V_2 = V_23 ;
} else {
V_6 = F_1 ( V_1 , V_2 , V_24 ,
sizeof( V_24 ) ) ;
}
break;
default:
V_6 = - V_25 ;
break;
}
return V_6 ;
}
