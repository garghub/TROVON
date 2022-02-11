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
F_3 ( V_10 != ( V_11 + 3 ) ) ;
V_6 = F_1 ( V_1 , V_2 , V_12 ,
sizeof( V_12 ) ) ;
break;
case V_13 :
V_6 = F_1 ( V_1 , V_2 , V_14 ,
sizeof( V_14 ) ) ;
break;
case V_15 :
F_3 ( V_16 != V_17 ) ;
V_6 = F_1 ( V_1 , V_2 , V_18 ,
sizeof( V_18 ) ) ;
break;
case V_19 :
if ( ( V_1 >= V_20 &&
V_1 <= V_21 ) ||
( V_1 >= V_22 &&
V_1 <= V_23 ) ) {
* V_2 = V_24 ;
} else {
V_6 = F_1 ( V_1 , V_2 , V_25 ,
sizeof( V_25 ) ) ;
}
break;
default:
V_6 = - V_26 ;
break;
}
return V_6 ;
}
