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
if ( ( ( V_16 ) V_2 ) & 0x3 ) {
F_3 ( ( V_17 ,
L_1 ,
V_2 , V_2 -> type , V_2 -> V_18 ) ) ;
}
V_7 = F_4 ( V_4 ) ;
V_11 = F_5 ( V_6 ) ;
while ( V_11 ) {
V_8 = F_6 ( void , V_4 , V_6 -> V_19 ) ;
V_9 =
F_6 ( void , V_2 , V_6 -> V_20 ) ;
switch ( V_6 -> V_21 ) {
case V_22 :
F_7 ( V_2 , 0 , F_8 ( V_6 ) ) ;
V_2 -> type = F_9 ( V_6 ) ;
V_2 -> V_18 = F_8 ( V_6 ) ;
break;
case V_23 :
break;
case V_24 :
V_12 = TRUE ;
break;
case V_25 :
F_10 ( V_9 ) = ( T_3 )
( ( F_11 ( V_8 ) >> V_6 -> V_26 ) & 0x01 ) ;
break;
case V_27 :
F_10 ( V_9 ) = ( T_3 )
( ( F_11 ( V_8 ) >> V_6 -> V_26 ) & 0x03 ) ;
break;
case V_28 :
V_13 = F_11 ( V_8 ) ;
F_10 ( V_9 ) = ( T_3 ) V_13 ;
V_2 -> V_18 = V_2 -> V_18 +
( V_6 -> V_26 * ( V_13 - 1 ) ) ;
break;
case V_29 :
V_13 = V_7 ;
F_12 ( V_9 ) = V_13 ;
V_2 -> V_18 = V_2 -> V_18 +
( V_6 -> V_26 * ( V_13 - 1 ) ) ;
break;
case V_30 :
V_2 -> V_18 = V_2 -> V_18 + V_6 -> V_26 ;
break;
case V_31 :
case V_32 :
case V_33 :
case V_34 :
if ( V_6 -> V_26 ) {
V_13 = V_6 -> V_26 ;
}
F_13 ( V_9 , V_8 , V_13 ,
V_6 -> V_21 ) ;
break;
case V_35 :
F_7 ( V_9 , V_6 -> V_19 , V_6 -> V_26 ) ;
break;
case V_36 :
V_10 = F_6 ( char , V_2 , V_6 -> V_26 ) ;
F_14 ( V_9 , V_8 , F_15 ( V_10 ) ) ;
break;
case V_37 :
if ( ! F_16 ( V_2 , V_4 ) ) {
F_17
( V_38 ) ;
}
break;
case V_39 :
V_2 -> V_18 +=
F_18 ( V_7 ,
V_6 -> V_26 ,
V_9 , V_4 , NULL ) ;
break;
case V_40 :
V_10 =
F_6 ( char , V_2 ,
V_6 -> V_19 + ( V_13 * 4 ) ) ;
V_2 -> V_18 +=
F_18 ( V_7 ,
( T_2 ) ( ( ( V_13 - 1 ) * sizeof( V_41 ) ) + V_6 -> V_26 ) , V_9 , V_4 , V_10 ) ;
break;
case V_42 :
V_13 =
F_19 ( F_11 ( V_8 ) ,
V_9 ) ;
if ( V_13 ) {
V_2 -> V_18 += ( V_13 - 1 ) ;
}
V_10 = F_6 ( char , V_2 , V_6 -> V_26 ) ;
F_10 ( V_10 ) = ( T_3 ) V_13 ;
break;
case V_43 :
F_20 ( & V_14 , V_8 ) ;
V_13 =
F_19 ( V_14 , V_9 ) ;
if ( V_13 ) {
V_2 -> V_18 += ( V_13 - 1 ) ;
}
V_10 = F_6 ( char , V_2 , V_6 -> V_26 ) ;
F_10 ( V_10 ) = ( T_3 ) V_13 ;
break;
case V_44 :
switch ( V_6 -> V_20 ) {
case V_45 :
if ( V_7 != V_6 -> V_26 ) {
goto exit;
}
break;
case V_46 :
if ( F_11 ( V_8 ) != V_6 -> V_26 ) {
goto exit;
}
break;
default:
F_21 ( ( V_17 ,
L_2 ) ) ;
F_17 ( V_47 ) ;
}
break;
default:
F_21 ( ( V_17 , L_3 ) ) ;
F_17 ( V_47 ) ;
}
V_11 -- ;
V_6 ++ ;
}
exit:
if ( ! V_12 ) {
V_2 -> V_18 =
( V_41 ) F_22 ( V_2 -> V_18 ) ;
}
F_17 ( V_48 ) ;
}
T_1
F_23 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6 )
{
void * V_8 = NULL ;
void * V_9 ;
T_5 V_49 = 0 ;
T_3 V_11 ;
T_4 V_14 = 0 ;
T_4 V_13 = 0 ;
F_2 ( V_50 ) ;
V_11 = F_5 ( V_6 ) ;
while ( V_11 ) {
V_8 = F_6 ( void , V_2 , V_6 -> V_20 ) ;
V_9 = F_6 ( void , V_4 , V_6 -> V_19 ) ;
switch ( V_6 -> V_21 ) {
case V_23 :
F_7 ( V_4 , 0 , F_8 ( V_6 ) ) ;
V_49 = F_8 ( V_6 ) ;
F_24 ( F_9 ( V_6 ) ,
V_49 , V_4 ) ;
break;
case V_22 :
break;
case V_24 :
F_10 ( V_9 ) = 0 ;
break;
case V_25 :
F_10 ( V_9 ) |= ( T_3 )
( ( F_11 ( V_8 ) & 0x01 ) << V_6 -> V_26 ) ;
break;
case V_27 :
F_10 ( V_9 ) |= ( T_3 )
( ( F_11 ( V_8 ) & 0x03 ) << V_6 -> V_26 ) ;
break;
case V_28 :
V_13 = F_11 ( V_8 ) ;
F_10 ( V_9 ) = ( T_3 ) V_13 ;
V_49 =
( T_4 ) ( V_49 +
( V_6 -> V_26 * ( V_13 - 1 ) ) ) ;
break;
case V_29 :
V_13 = F_15 ( V_8 ) ;
V_49 = ( T_4 ) ( V_49 + V_13 ) ;
F_25 ( V_49 , V_4 ) ;
break;
case V_30 :
F_25 ( V_6 -> V_26 , V_4 ) ;
break;
case V_31 :
case V_32 :
case V_33 :
case V_34 :
if ( V_6 -> V_26 ) {
V_13 = V_6 -> V_26 ;
}
F_13 ( V_9 , V_8 , V_13 ,
V_6 -> V_21 ) ;
break;
case V_37 :
F_26 ( V_4 , V_2 ) ;
break;
case V_40 :
V_49 =
F_27 ( V_4 , ( T_2 )
V_49 , V_8 ) ;
F_25 ( V_49 , V_4 ) ;
break;
case V_39 :
V_49 =
F_27 ( V_4 , V_6 -> V_26 ,
V_8 ) ;
F_25 ( V_49 , V_4 ) ;
break;
case V_42 :
F_10 ( V_9 ) = ( T_3 )
F_28 ( V_8 ,
* F_6 ( T_3 , V_2 ,
V_6 -> V_26 ) ) ;
break;
case V_43 :
V_14 = F_28 ( V_8 ,
* F_6 ( T_3 ,
V_2 ,
V_6 ->
V_26 ) ) ;
F_20 ( V_9 , & V_14 ) ;
break;
case V_51 :
if ( V_13 <= V_6 -> V_26 ) {
goto exit;
}
break;
case V_44 :
switch ( F_29 ( V_6 ) ) {
case V_46 :
if ( * F_6 ( T_3 , V_2 ,
F_30 ( V_6 ) ) !=
F_31 ( V_6 ) ) {
goto exit;
}
break;
default:
F_21 ( ( V_17 ,
L_2 ) ) ;
F_17 ( V_47 ) ;
}
break;
case V_52 :
if ( * F_6 ( T_3 , V_2 ,
F_30 ( V_6 ) ) ==
F_31 ( V_6 ) ) {
goto exit;
}
break;
default:
F_21 ( ( V_17 , L_3 ) ) ;
F_17 ( V_47 ) ;
}
V_11 -- ;
V_6 ++ ;
}
exit:
F_17 ( V_48 ) ;
}
