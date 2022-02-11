T_1
F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6 )
{
T_2 V_7 ;
void * V_8 ;
void * V_9 ;
char * V_10 ;
T_3 V_11 ;
T_3 V_12 = FALSE ;
T_4 V_13 = 0 ;
T_4 V_14 = 0 ;
F_2 ( V_15 ) ;
if ( ! V_6 ) {
F_3 ( V_16 ) ;
}
if ( ( ( V_17 ) V_2 ) & 0x3 ) {
F_4 ( ( V_18 ,
L_1 ,
V_2 , V_2 -> type , V_2 -> V_19 ) ) ;
}
V_7 = F_5 ( V_4 ) ;
V_11 = F_6 ( V_6 ) ;
while ( V_11 ) {
V_8 = F_7 ( void , V_4 , V_6 -> V_20 ) ;
V_9 =
F_7 ( void , V_2 , V_6 -> V_21 ) ;
switch ( V_6 -> V_22 ) {
case V_23 :
memset ( V_2 , 0 , F_8 ( V_6 ) ) ;
V_2 -> type = F_9 ( V_6 ) ;
V_2 -> V_19 = F_8 ( V_6 ) ;
break;
case V_24 :
break;
case V_25 :
V_12 = TRUE ;
break;
case V_26 :
F_10 ( V_9 ,
( ( F_11 ( V_8 ) >> V_6 -> V_27 ) & 0x01 ) ) ;
break;
case V_28 :
F_10 ( V_9 ,
( ( F_11 ( V_8 ) >> V_6 -> V_27 ) & 0x03 ) ) ;
break;
case V_29 :
F_10 ( V_9 ,
( ( F_11 ( V_8 ) >> V_6 -> V_27 ) & 0x07 ) ) ;
break;
case V_30 :
V_13 = F_11 ( V_8 ) ;
F_10 ( V_9 , V_13 ) ;
V_2 -> V_19 = V_2 -> V_19 +
( V_6 -> V_27 * ( V_13 - 1 ) ) ;
break;
case V_31 :
V_13 = V_7 ;
F_12 ( V_9 , V_13 ) ;
V_2 -> V_19 = V_2 -> V_19 +
( V_6 -> V_27 * ( V_13 - 1 ) ) ;
break;
case V_32 :
V_10 = F_7 ( void , V_4 , V_6 -> V_27 ) ;
V_13 = F_13 ( V_10 ) - F_13 ( V_8 ) ;
V_2 -> V_19 = V_2 -> V_19 + V_13 ;
V_13 = V_13 / 2 ;
F_12 ( V_9 , V_13 ) ;
break;
case V_33 :
V_13 = F_11 ( V_8 ) ;
F_10 ( V_9 , V_13 ) ;
V_2 -> V_19 =
V_2 -> V_19 + ( V_6 -> V_27 * V_13 ) ;
break;
case V_34 :
V_10 = F_7 ( void , V_4 , ( V_6 -> V_27 + 2 ) ) ;
if ( F_13 ( V_10 ) ) {
V_10 = F_7 ( void , V_4 , V_6 -> V_27 ) ;
V_13 =
F_13 ( V_10 ) - F_13 ( V_8 ) ;
} else {
V_13 = V_4 -> V_35 . V_36 +
sizeof( struct V_37 ) -
F_13 ( V_8 ) ;
}
V_2 -> V_19 = V_2 -> V_19 + V_13 ;
F_12 ( V_9 , V_13 ) ;
break;
case V_38 :
V_13 = F_13 ( V_8 ) - V_6 -> V_27 ;
V_2 -> V_19 = V_2 -> V_19 + V_13 ;
F_12 ( V_9 , V_13 ) ;
break;
case V_39 :
V_13 = ( V_7 +
sizeof( struct V_37 ) )
- F_13 ( V_8 ) - V_6 -> V_27 ;
V_2 -> V_19 = V_2 -> V_19 + V_13 ;
F_12 ( V_9 , V_13 ) ;
break;
case V_40 :
V_2 -> V_19 = V_2 -> V_19 + V_6 -> V_27 ;
break;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
if ( V_6 -> V_27 ) {
V_13 = V_6 -> V_27 ;
}
F_14 ( V_9 , V_8 , V_13 ,
V_6 -> V_22 ) ;
break;
case V_45 :
V_10 = ( char * ) F_7 ( void , V_2 ,
( V_2 -> V_19 -
V_13 * 2 ) ) ;
* ( T_4 * * ) V_9 = F_15 ( T_4 , V_10 ) ;
V_8 = F_7 ( void , V_4 , F_13 ( V_8 ) ) ;
F_14 ( V_10 , V_8 , V_13 ,
V_6 -> V_22 ) ;
break;
case V_46 :
V_10 = ( char * ) F_7 ( void , V_2 ,
( V_2 -> V_19 -
V_13 ) ) ;
* ( T_3 * * ) V_9 = F_15 ( T_3 , V_10 ) ;
V_8 = F_7 ( void , V_4 , F_13 ( V_8 ) ) ;
F_14 ( V_10 , V_8 , V_13 ,
V_6 -> V_22 ) ;
break;
case V_47 :
V_10 = ( char * ) F_7 ( void , V_2 ,
( V_2 -> V_19 -
V_13 ) ) ;
* ( T_3 * * ) V_9 = F_15 ( T_3 , V_10 ) ;
V_8 = F_7 ( void , V_4 , V_6 -> V_27 ) ;
F_14 ( V_10 , V_8 , V_13 ,
V_6 -> V_22 ) ;
break;
case V_48 :
V_10 = ( char * ) F_7 ( void , V_2 ,
( V_2 -> V_19 -
V_13 ) ) ;
* ( T_3 * * ) V_9 = F_15 ( T_3 , V_10 ) ;
V_8 =
F_7 ( void , V_4 ,
( F_13 ( V_8 ) + V_6 -> V_27 ) ) ;
F_14 ( V_10 , V_8 , V_13 ,
V_6 -> V_22 ) ;
break;
case V_49 :
memset ( V_9 , V_6 -> V_20 , V_6 -> V_27 ) ;
break;
case V_50 :
V_10 = F_7 ( char , V_2 , V_6 -> V_27 ) ;
memcpy ( V_9 , V_8 , F_13 ( V_10 ) ) ;
break;
case V_51 :
if ( ! F_16 ( V_2 , V_4 ) ) {
F_3
( V_52 ) ;
}
break;
case V_53 :
V_2 -> V_19 +=
F_17 ( V_7 ,
V_6 -> V_27 ,
V_9 , V_4 , NULL ) ;
break;
case V_54 :
V_10 = F_7 ( char , V_2 ,
V_6 -> V_20 +
( V_13 * 4 ) ) ;
V_2 -> V_19 +=
F_17 ( V_7 ,
( T_2 )
( ( ( V_13 -
1 ) * sizeof( V_55 ) ) +
V_6 -> V_27 ) ,
V_9 , V_4 ,
V_10 ) ;
break;
case V_56 :
V_13 =
F_18 ( F_11 ( V_8 ) ,
V_9 ) ;
if ( V_13 ) {
V_2 -> V_19 += ( V_13 - 1 ) ;
}
V_10 = F_7 ( char , V_2 , V_6 -> V_27 ) ;
F_10 ( V_10 , V_13 ) ;
break;
case V_57 :
F_19 ( & V_14 , V_8 ) ;
V_13 =
F_18 ( V_14 , V_9 ) ;
if ( V_13 ) {
V_2 -> V_19 += ( V_13 - 1 ) ;
}
V_10 = F_7 ( char , V_2 , V_6 -> V_27 ) ;
F_10 ( V_10 , V_13 ) ;
break;
case V_58 :
switch ( V_6 -> V_21 ) {
case V_59 :
if ( V_7 != V_6 -> V_27 ) {
goto exit;
}
break;
case V_60 :
if ( F_11 ( V_8 ) != V_6 -> V_27 ) {
goto exit;
}
break;
default:
F_20 ( ( V_18 ,
L_2 ) ) ;
F_3 ( V_16 ) ;
}
break;
default:
F_20 ( ( V_18 , L_3 ) ) ;
F_3 ( V_16 ) ;
}
V_11 -- ;
V_6 ++ ;
}
exit:
if ( ! V_12 ) {
V_2 -> V_19 = ( V_55 )
F_21 ( V_2 -> V_19 ) ;
}
F_3 ( V_61 ) ;
}
T_1
F_22 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6 )
{
void * V_8 = NULL ;
void * V_9 ;
char * V_10 ;
T_5 V_62 = 0 ;
T_3 V_11 ;
T_4 V_14 = 0 ;
T_4 V_13 = 0 ;
F_2 ( V_63 ) ;
if ( ! V_6 ) {
F_3 ( V_16 ) ;
}
V_11 = F_6 ( V_6 ) ;
while ( V_11 ) {
V_8 = F_7 ( void , V_2 , V_6 -> V_21 ) ;
V_9 = F_7 ( void , V_4 , V_6 -> V_20 ) ;
switch ( V_6 -> V_22 ) {
case V_24 :
memset ( V_4 , 0 , F_8 ( V_6 ) ) ;
V_62 = F_8 ( V_6 ) ;
F_23 ( F_9 ( V_6 ) ,
V_62 , V_4 ) ;
break;
case V_23 :
break;
case V_25 :
F_10 ( V_9 , 0 ) ;
break;
case V_26 :
F_24 ( * F_25 ( V_9 ) , ( T_3 )
( ( F_11 ( V_8 ) & 0x01 ) << V_6 ->
V_27 ) ) ;
break;
case V_28 :
F_24 ( * F_25 ( V_9 ) , ( T_3 )
( ( F_11 ( V_8 ) & 0x03 ) << V_6 ->
V_27 ) ) ;
break;
case V_29 :
F_24 ( * F_25 ( V_9 ) , ( T_3 )
( ( F_11 ( V_8 ) & 0x07 ) << V_6 ->
V_27 ) ) ;
break;
case V_30 :
V_13 = F_11 ( V_8 ) ;
F_10 ( V_9 , V_13 ) ;
V_62 = ( T_4 )
( V_62 + ( V_6 -> V_27 * ( V_13 - 1 ) ) ) ;
break;
case V_31 :
V_13 = F_13 ( V_8 ) ;
V_62 = ( T_4 ) ( V_62 + V_13 ) ;
F_26 ( V_62 , V_4 ) ;
break;
case V_32 :
V_13 = F_13 ( V_8 ) ;
F_12 ( V_9 , V_62 ) ;
V_62 = ( T_4 ) ( V_62 + V_13 * 2 ) ;
V_10 = F_7 ( void , V_4 , V_6 -> V_27 ) ;
F_12 ( V_10 , V_62 ) ;
F_26 ( V_62 , V_4 ) ;
break;
case V_33 :
V_13 = F_13 ( V_8 ) ;
F_12 ( V_9 , V_13 ) ;
V_62 =
( T_4 ) ( V_62 + ( V_6 -> V_27 * V_13 ) ) ;
F_26 ( V_62 , V_4 ) ;
break;
case V_34 :
V_13 = F_13 ( V_8 ) ;
F_12 ( V_9 , V_62 ) ;
V_62 = ( T_4 ) ( V_62 + V_13 ) ;
V_10 = F_7 ( void , V_4 , V_6 -> V_27 ) ;
if ( V_2 -> V_64 . V_65 . V_66 ) {
F_12 ( V_10 , V_62 ) ;
}
F_26 ( V_62 , V_4 ) ;
break;
case V_38 :
V_13 = F_13 ( V_8 ) ;
F_12 ( V_9 , V_13 + V_6 -> V_27 ) ;
V_62 = ( T_4 ) ( V_62 + V_13 ) ;
F_26 ( V_62 , V_4 ) ;
break;
case V_39 :
V_13 = F_13 ( V_8 ) ;
V_62 = ( T_4 ) ( V_62 + V_13 ) ;
F_26 ( V_62 , V_4 ) ;
break;
case V_40 :
F_26 ( V_6 -> V_27 , V_4 ) ;
break;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
if ( V_6 -> V_27 ) {
V_13 = V_6 -> V_27 ;
}
F_14 ( V_9 , V_8 , V_13 ,
V_6 -> V_22 ) ;
break;
case V_45 :
V_9 = ( char * ) F_7 ( void , V_4 ,
F_13
( V_9 ) ) ;
V_8 = * ( T_4 * * ) V_8 ;
F_14 ( V_9 , V_8 , V_13 ,
V_6 -> V_22 ) ;
break;
case V_46 :
V_9 = ( char * ) F_7 ( void , V_4 ,
F_13
( V_9 ) ) ;
V_8 = * ( T_3 * * ) V_8 ;
F_14 ( V_9 , V_8 , V_13 ,
V_6 -> V_22 ) ;
break;
case V_47 :
V_9 = ( char * ) F_7 ( void , V_4 ,
( V_62 -
V_13 ) ) ;
V_8 = * ( T_3 * * ) V_8 ;
F_14 ( V_9 , V_8 , V_13 ,
V_6 -> V_22 ) ;
break;
case V_48 :
V_9 = ( char * ) F_7 ( void , V_4 ,
( V_62 -
V_13 ) ) ;
V_8 = * ( T_3 * * ) V_8 ;
F_14 ( V_9 , V_8 , V_13 ,
V_6 -> V_22 ) ;
break;
case V_51 :
F_27 ( V_4 , V_2 ) ;
break;
case V_54 :
V_62 =
F_28 ( V_4 ,
( T_2 )
V_62 , V_8 ) ;
F_26 ( V_62 , V_4 ) ;
break;
case V_53 :
V_62 =
F_28 ( V_4 , V_6 -> V_27 ,
V_8 ) ;
F_26 ( V_62 , V_4 ) ;
break;
case V_56 :
F_10 ( V_9 ,
F_29 ( V_8 ,
* F_7 ( T_3 ,
V_2 ,
V_6 ->
V_27 ) ) ) ;
break;
case V_57 :
V_14 =
F_29 ( V_8 ,
* F_7 ( T_3 , V_2 ,
V_6 -> V_27 ) ) ;
F_19 ( V_9 , & V_14 ) ;
break;
case V_67 :
if ( V_13 <= V_6 -> V_27 ) {
goto exit;
}
break;
case V_58 :
switch ( F_30 ( V_6 ) ) {
case V_60 :
if ( * F_7 ( T_3 , V_2 ,
F_31 ( V_6 ) ) !=
F_32 ( V_6 ) ) {
goto exit;
}
break;
default:
F_20 ( ( V_18 ,
L_2 ) ) ;
F_3 ( V_16 ) ;
}
break;
case V_68 :
if ( * F_7 ( T_3 , V_2 ,
F_31 ( V_6 ) ) ==
F_32 ( V_6 ) ) {
goto exit;
}
break;
default:
F_20 ( ( V_18 , L_3 ) ) ;
F_3 ( V_16 ) ;
}
V_11 -- ;
V_6 ++ ;
}
exit:
F_3 ( V_61 ) ;
}
