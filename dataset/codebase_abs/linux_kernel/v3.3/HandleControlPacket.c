static VOID F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
T_2 V_4 = NULL ;
BOOLEAN V_5 = FALSE ;
struct V_2 * V_6 = NULL ;
CHAR V_7 = 0 ;
BOOLEAN V_8 = TRUE ;
T_3 V_9 = * ( V_10 ) ( V_3 -> V_11 ) ;
if ( F_2 ( V_1 ) )
F_3 ( V_12 , V_13 L_1 , V_14 ,
16 , 1 , V_3 -> V_11 , V_3 -> V_15 , 0 ) ;
switch ( V_9 ) {
case V_16 :
F_4 ( V_1 , V_17 , V_18 ,
V_19 ,
L_2 ) ;
V_5 = TRUE ;
break;
case V_20 :
V_5 = TRUE ;
if ( V_1 -> V_21 == V_22 )
F_5 ( V_1 ,
( V_3 -> V_11 + sizeof( T_3 ) ) ) ;
break;
case V_23 :
case V_24 :
F_4 ( V_1 , V_17 , V_18 ,
V_19 , L_3 ) ;
V_5 = TRUE ;
F_6 ( V_1 ,
( V_3 -> V_11 + sizeof( T_3 ) ) ) ;
break;
case V_25 :
V_5 = TRUE ;
F_7 ( V_1 , ( V_3 -> V_11 + sizeof( T_3 ) ) ) ;
break;
case V_26 :
F_4 ( V_1 , V_17 , V_18 ,
V_19 ,
L_4 ) ;
F_8 ( V_1 , ( V_27 ) ( V_3 -> V_11 +
sizeof( T_3 ) ) ) ;
V_5 = TRUE ;
break;
case V_28 :
V_5 = TRUE ;
break;
default:
F_4 ( V_1 , V_17 , V_18 ,
V_19 , L_5 ) ;
break;
}
F_9 ( & V_1 -> V_29 ) ;
for ( V_4 = V_1 -> V_30 ; V_4 ; V_4 = V_4 -> V_31 ) {
if ( V_1 -> V_32 )
break;
V_8 = TRUE ;
V_7 = ( V_9 & 0x1F ) ;
if ( V_4 -> V_33 & ( 1 << V_7 ) )
V_8 = FALSE ;
if ( ( V_8 == TRUE ) ||
( V_4 -> V_34 > V_35 )
|| ( ( V_4 -> V_34 >
V_35 / 2 ) &&
( V_5 == FALSE ) ) ) {
switch ( * ( V_10 ) V_3 -> V_11 ) {
case V_16 :
V_4 -> V_36 . V_37 ++ ;
break;
case V_20 :
V_4 -> V_36 . V_38 ++ ;
break;
case V_23 :
V_4 -> V_36 . V_39 ++ ;
break;
case V_24 :
V_4 -> V_36 . V_40 ++ ;
break;
case V_25 :
V_4 -> V_36 . V_41 ++ ;
break;
case V_26 :
V_4 -> V_36 . V_42 ++ ;
break;
case V_28 :
V_4 -> V_36 . V_43 ++ ;
break;
default:
V_4 -> V_36 . V_44 ++ ;
break;
}
continue;
}
V_6 = F_10 ( V_3 , V_45 ) ;
if ( ! V_6 )
break;
F_11 ( V_4 -> V_46 ,
V_4 -> V_47 , V_6 ) ;
V_4 -> V_34 ++ ;
}
F_12 ( & V_1 -> V_29 ) ;
F_13 ( & V_1 -> V_48 ) ;
F_14 ( V_3 ) ;
F_4 ( V_1 , V_17 , V_18 , V_19 ,
L_6 ) ;
}
int F_15 ( T_1 V_1 )
{
struct V_2 * V_49 = NULL ;
unsigned long V_50 = 0 ;
F_4 ( V_1 , V_17 , V_18 , V_19 ,
L_7 ) ;
while ( 1 ) {
F_16 ( V_1 -> V_51 ,
F_17 ( & V_1 -> V_52 ) ||
V_1 -> V_53 ||
F_18 () ) ;
if ( F_18 () ) {
F_4 ( V_1 , V_17 , V_18 ,
V_19 , L_8 ) ;
return 0 ;
}
if ( TRUE == V_1 -> V_53 ) {
V_1 -> V_53 = FALSE ;
if ( ( FALSE == V_1 -> V_54 )
&& ( ( TRUE == V_1 -> V_55 ) ||
( TRUE == V_1 -> V_56 ) ) ) {
F_4 ( V_1 , V_17 ,
V_18 , V_19 ,
L_9 ) ;
F_19 ( V_1 ) ;
}
continue;
}
while ( F_17 ( & V_1 -> V_52 ) ) {
F_20 ( & V_1 -> V_57 , V_50 ) ;
V_49 = V_1 -> V_58 ;
if ( V_49 ) {
F_21 ( V_1 -> V_58 ,
V_1 -> V_59 ) ;
}
F_22 ( & V_1 -> V_57 ,
V_50 ) ;
F_1 ( V_1 , V_49 ) ;
F_23 ( & V_1 -> V_52 ) ;
}
F_24 ( V_1 ) ;
}
return V_60 ;
}
INT F_25 ( void )
{
T_1 V_1 = F_26 ( V_61 ) ;
T_2 V_4 = NULL ;
struct V_2 * V_62 = NULL ;
for ( V_4 = V_1 -> V_30 ; V_4 ; V_4 = V_4 -> V_31 ) {
while ( V_4 -> V_46 != NULL ) {
V_62 = V_4 -> V_46 ;
F_21 ( V_4 -> V_46 ,
V_4 -> V_47 ) ;
F_14 ( V_62 ) ;
}
V_4 -> V_34 = 0 ;
memset ( ( V_63 ) & V_4 -> V_36 , 0 ,
sizeof( V_64 ) ) ;
}
return V_60 ;
}
