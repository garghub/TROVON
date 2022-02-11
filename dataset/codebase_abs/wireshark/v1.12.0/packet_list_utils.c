T_1
F_1 ( T_2 V_1 , T_3 * V_2 )
{
T_4 * V_3 ;
T_1 V_4 = FALSE ;
if ( ! V_2 ) return FALSE ;
switch ( V_2 -> V_5 . V_6 [ V_1 ] ) {
case V_7 :
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
V_4 = TRUE ;
break;
case V_18 :
V_3 = F_2 ( V_2 -> V_5 . V_19 [ V_1 ] ) ;
if ( ( V_3 != NULL ) && ( ( V_3 -> V_20 == NULL ) || ! F_3 ( V_1 ) ) ) {
if ( ( V_3 -> type == V_21 ) || ( V_3 -> type == V_22 ) ||
( ( ( V_3 -> V_23 == V_24 ) || ( V_3 -> V_23 == V_25 ) ) &&
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
T_1 V_26 = FALSE ;
if ( ! V_2 ) return FALSE ;
switch ( V_2 -> V_5 . V_6 [ V_1 ] ) {
case V_18 :
V_3 = F_2 ( V_2 -> V_5 . V_19 [ V_1 ] ) ;
if ( V_3 != NULL ) {
if ( ( V_3 -> type == V_27 ) || ( V_3 -> type == V_28 ) ||
( ( V_3 -> V_20 != NULL ) &&
( ( V_3 -> type == V_21 ) || ( V_3 -> type == V_22 ) ||
F_4 ( V_3 -> type ) || F_5 ( V_3 -> type ) ) ) ) {
V_26 = TRUE ;
}
}
break;
default:
break;
}
return V_26 ;
}
