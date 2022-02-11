T_1
F_1 ( T_2 V_1 , T_3 * V_2 )
{
T_4 * V_3 ;
T_1 V_4 = FALSE ;
if ( ! V_2 ) return FALSE ;
switch ( V_2 -> V_5 . V_6 [ V_1 ] . V_7 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
V_4 = TRUE ;
break;
case V_19 :
V_3 = F_2 ( V_2 -> V_5 . V_6 [ V_1 ] . V_20 ) ;
if ( ( V_3 != NULL ) && ( ( V_3 -> V_21 == NULL ) || ! F_3 ( V_1 ) ) ) {
if ( ( V_3 -> type == V_22 ) || ( V_3 -> type == V_23 ) ||
( ( ( V_3 -> V_24 == V_25 ) || ( V_3 -> V_24 == V_26 ) ) &&
( F_4 ( V_3 -> type ) || F_5 ( V_3 -> type ) ) ) ) {
V_4 = TRUE ;
}
}
break;
default:
break;
}
return V_4 ;
}
T_1
F_6 ( T_2 V_1 , T_3 * V_2 )
{
T_4 * V_3 ;
T_1 V_27 = FALSE ;
if ( ! V_2 ) return FALSE ;
switch ( V_2 -> V_5 . V_6 [ V_1 ] . V_7 ) {
case V_19 :
V_3 = F_2 ( V_2 -> V_5 . V_6 [ V_1 ] . V_20 ) ;
if ( V_3 != NULL ) {
if ( ( V_3 -> type == V_28 ) || ( V_3 -> type == V_29 ) ||
( ( V_3 -> V_21 != NULL ) &&
( ( V_3 -> type == V_22 ) || ( V_3 -> type == V_23 ) ||
F_4 ( V_3 -> type ) || F_5 ( V_3 -> type ) ) ) ) {
V_27 = TRUE ;
}
}
break;
default:
break;
}
return V_27 ;
}
