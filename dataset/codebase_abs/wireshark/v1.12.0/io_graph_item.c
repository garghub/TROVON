int F_1 ( T_1 * V_1 , int V_2 ) {
T_2 V_3 ;
V_3 = V_1 -> V_4 ;
if ( V_3 . V_5 < 0 ) {
V_3 . V_6 -- ;
V_3 . V_5 += 1000000000 ;
}
if ( V_3 . V_6 < 0 ) {
return - 1 ;
}
return ( int ) ( ( V_3 . V_6 * 1000 + V_3 . V_5 / 1000000 ) / V_2 ) ;
}
T_3 * F_2 ( const char * V_7 , int * V_8 , T_4 V_9 )
{
T_3 * V_10 = NULL ;
if ( V_9 >= V_11 ) {
T_5 * V_12 ;
const char * V_13 [ V_14 ] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10
} ;
if ( ( V_7 == NULL ) || ( V_7 [ 0 ] == 0 ) ) {
V_10 = F_3 ( L_11 ) ;
return V_10 ;
}
V_12 = F_4 ( V_7 ) ;
if ( V_12 == NULL ) {
V_10 = F_3 ( L_12 ) ;
F_5 ( V_10 , L_13 , V_7 ) ;
return V_10 ;
}
if ( V_8 ) * V_8 = V_12 -> V_15 ;
switch ( V_12 -> type ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
switch ( V_9 ) {
case V_28 :
V_10 = F_3 ( L_14 ) ;
default:
break;
}
break;
case V_29 :
switch ( V_9 ) {
case V_11 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_28 :
break;
default:
V_10 = F_3 ( L_12 ) ;
F_5 ( V_10 , L_15 ,
V_7 ,
V_13 [ V_9 ] ) ;
}
break;
default:
if ( ( V_9 != V_30 ) &&
( V_9 != V_31 ) ) {
V_10 = F_3 ( L_12 ) ;
F_5 ( V_10 , L_16 ,
V_7 ,
V_13 [ V_9 ] ) ;
}
break;
}
}
return V_10 ;
}
