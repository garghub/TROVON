int
F_1 ( const T_1 * V_1 , int V_2 , T_2 V_3 )
{
T_3 V_4 ;
switch ( V_1 [ V_2 ] & 0x03 ) {
case V_5 :
default:
if ( V_3 )
V_4 = F_2 ( & V_1 [ V_2 ] ) ;
else
V_4 = V_1 [ V_2 ] ;
break;
case V_6 :
V_4 = V_1 [ V_2 ] ;
break;
}
return V_4 ;
}
T_2
F_3 ( T_4 * V_7 , int V_2 ,
const T_5 * V_8 ,
const T_5 * V_9 , T_2 V_10 ,
T_2 V_3 V_11 )
{
T_3 V_4 ;
if ( ! F_4 ( V_7 , V_2 , 1 ) )
return FALSE ;
switch ( F_5 ( V_7 , V_2 ) & 0x03 ) {
case V_5 :
return TRUE ;
case V_6 :
if ( V_8 == NULL )
V_8 = V_12 ;
if ( V_9 == NULL )
V_9 = V_13 ;
V_4 = F_5 ( V_7 , V_2 ) ;
if ( V_10 ) {
if ( F_6 ( V_4 & V_14 ,
V_9 ) == NULL )
return FALSE ;
} else {
if ( F_6 ( V_4 & V_14 ,
V_8 ) == NULL )
return FALSE ;
}
return TRUE ;
default:
return TRUE ;
}
}
int
F_7 ( T_4 * V_7 , int V_2 , T_6 * V_15 ,
T_7 * V_16 , int V_17 , T_8 V_18 ,
const T_9 * V_19 , const T_9 * V_20 ,
const T_5 * V_8 ,
const T_5 * V_9 , T_2 V_10 ,
T_2 V_3 , T_2 V_21 )
{
T_3 V_4 ;
int V_22 ;
const T_9 * V_23 ;
const char * V_24 ;
T_3 V_25 ;
char * V_26 ;
T_7 * V_27 , * V_28 ;
const T_10 * V_29 = NULL ;
const T_10 * V_30 ;
V_26 = ( char * ) F_8 ( 80 ) ;
switch ( F_5 ( V_7 , V_2 ) & 0x03 ) {
case V_5 :
if ( V_3 ) {
V_4 = F_9 ( V_7 , V_2 ) ;
V_22 = 2 ;
V_23 = V_20 ;
V_24 = L_1 ;
} else {
V_4 = F_5 ( V_7 , V_2 ) ;
V_22 = 1 ;
V_23 = V_19 ;
V_24 = L_2 ;
}
switch ( V_4 & V_31 ) {
case V_32 :
V_29 = L_3 ;
break;
case V_33 :
V_29 = L_4 ;
break;
case V_34 :
V_29 = L_5 ;
break;
case V_35 :
V_29 = L_6 ;
break;
}
if ( V_3 ) {
V_25 = ( V_4 & V_36 ) ;
F_10 ( V_26 , 80 , L_7 ,
( V_25 ?
( V_10 ? L_8 : L_9 ) :
L_10 ) ,
V_29 ,
( V_4 & V_37 ) >> V_38 ) ;
} else {
V_25 = ( V_4 & V_39 ) ;
F_10 ( V_26 , 80 , L_7 ,
( V_25 ?
( V_10 ? L_8 : L_9 ) :
L_10 ) ,
V_29 ,
( V_4 & V_40 ) >> V_41 ) ;
}
if ( V_21 ) {
F_11 ( V_15 -> V_42 , V_43 , L_11 ) ;
F_11 ( V_15 -> V_42 , V_43 , V_26 ) ;
} else {
F_12 ( V_15 -> V_42 , V_43 , V_26 ) ;
}
if ( V_16 ) {
V_27 = F_13 ( V_16 , V_17 , V_7 ,
V_2 , V_22 , V_4 , V_24 , V_26 , V_4 ) ;
V_28 = F_14 ( V_27 , V_18 ) ;
F_15 ( V_28 , * V_23 -> V_44 ,
V_7 , V_2 , V_22 , V_4 ) ;
if ( V_25 ) {
F_16 ( V_28 ,
( V_10 ? * V_23 -> V_45 :
* V_23 -> V_46 ) ,
V_7 , V_2 , V_22 , V_4 ) ;
}
F_15 ( V_28 , * V_23 -> V_47 ,
V_7 , V_2 , V_22 , V_4 ) ;
F_15 ( V_28 , * V_23 -> V_48 ,
V_7 , V_2 , V_22 , V_4 ) ;
}
break;
case V_6 :
if ( V_8 == NULL )
V_8 = V_12 ;
if ( V_9 == NULL )
V_9 = V_13 ;
V_4 = F_5 ( V_7 , V_2 ) ;
V_22 = 1 ;
V_23 = V_19 ;
V_24 = L_2 ;
if ( V_10 ) {
V_30 = F_17 ( V_4 & V_14 ,
V_9 , L_12 ) ;
} else {
V_30 = F_17 ( V_4 & V_14 ,
V_8 , L_12 ) ;
}
V_25 = ( V_4 & V_39 ) ;
F_10 ( V_26 , 80 , L_13 ,
( V_25 ?
( V_10 ? L_8 : L_9 ) :
L_10 ) ,
V_30 ) ;
if ( V_21 ) {
F_11 ( V_15 -> V_42 , V_43 , L_11 ) ;
F_11 ( V_15 -> V_42 , V_43 , V_26 ) ;
} else {
F_12 ( V_15 -> V_42 , V_43 , V_26 ) ;
}
if ( V_16 ) {
V_27 = F_13 ( V_16 , V_17 , V_7 ,
V_2 , V_22 , V_4 , V_24 , V_26 , V_4 ) ;
V_28 = F_14 ( V_27 , V_18 ) ;
if ( V_25 ) {
F_16 ( V_28 ,
( V_10 ? * V_23 -> V_45 :
* V_23 -> V_46 ) ,
V_7 , V_2 , V_22 , V_4 ) ;
}
F_15 ( V_28 ,
( V_10 ? * V_23 -> V_49 :
* V_23 -> V_50 ) ,
V_7 , V_2 , V_22 , V_4 ) ;
F_15 ( V_28 , * V_23 -> V_48 ,
V_7 , V_2 , V_22 , V_4 ) ;
}
break;
default:
if ( V_3 ) {
V_4 = F_9 ( V_7 , V_2 ) ;
V_22 = 2 ;
V_23 = V_20 ;
V_24 = L_1 ;
V_25 = ( V_4 & V_36 ) ;
F_10 ( V_26 , 80 , L_14 ,
( ( V_4 & V_36 ) ? L_9 : L_10 ) ,
( V_4 & V_37 ) >> V_38 ,
( V_4 & V_51 ) >> V_52 ) ;
} else {
V_4 = F_5 ( V_7 , V_2 ) ;
V_22 = 1 ;
V_23 = V_19 ;
V_24 = L_2 ;
V_25 = ( V_4 & V_39 ) ;
F_10 ( V_26 , 80 , L_14 ,
( ( V_4 & V_39 ) ? L_9 : L_10 ) ,
( V_4 & V_40 ) >> V_41 ,
( V_4 & V_53 ) >> V_54 ) ;
}
if ( V_21 ) {
F_11 ( V_15 -> V_42 , V_43 , L_11 ) ;
F_11 ( V_15 -> V_42 , V_43 , V_26 ) ;
} else {
F_12 ( V_15 -> V_42 , V_43 , V_26 ) ;
}
if ( V_16 ) {
V_27 = F_13 ( V_16 , V_17 , V_7 ,
V_2 , V_22 , V_4 , V_24 , V_26 , V_4 ) ;
V_28 = F_14 ( V_27 , V_18 ) ;
F_15 ( V_28 , * V_23 -> V_44 ,
V_7 , V_2 , V_22 , V_4 ) ;
F_15 ( V_28 , * V_23 -> V_55 ,
V_7 , V_2 , V_22 , V_4 ) ;
if ( V_25 ) {
F_16 ( V_28 , * V_23 -> V_46 ,
V_7 , V_2 , V_22 , V_4 ) ;
}
F_15 ( V_28 , * V_23 -> V_56 ,
V_7 , V_2 , V_22 , V_4 ) ;
}
break;
}
return V_4 ;
}
