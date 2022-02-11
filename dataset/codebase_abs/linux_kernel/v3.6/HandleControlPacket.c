static VOID F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
BOOLEAN V_7 = FALSE ;
struct V_3 * V_8 = NULL ;
CHAR V_9 = 0 ;
BOOLEAN V_10 = TRUE ;
T_1 V_11 = * ( V_12 ) ( V_4 -> V_13 ) ;
if ( F_2 ( V_2 ) )
F_3 ( V_14 , V_15 L_1 , V_16 ,
16 , 1 , V_4 -> V_13 , V_4 -> V_17 , 0 ) ;
switch ( V_11 ) {
case V_18 :
F_4 ( V_2 , V_19 , V_20 ,
V_21 ,
L_2 ) ;
V_7 = TRUE ;
break;
case V_22 :
V_7 = TRUE ;
if ( V_2 -> V_23 == V_24 )
F_5 ( V_2 ,
( V_4 -> V_13 + sizeof( T_1 ) ) ) ;
break;
case V_25 :
case V_26 :
F_4 ( V_2 , V_19 , V_20 ,
V_21 , L_3 ) ;
V_7 = TRUE ;
F_6 ( V_2 ,
( V_4 -> V_13 + sizeof( T_1 ) ) ) ;
break;
case V_27 :
V_7 = TRUE ;
F_7 ( V_2 , ( V_4 -> V_13 + sizeof( T_1 ) ) ) ;
break;
case V_28 :
F_4 ( V_2 , V_19 , V_20 ,
V_21 ,
L_4 ) ;
F_8 ( V_2 , ( V_29 ) ( V_4 -> V_13 +
sizeof( T_1 ) ) ) ;
V_7 = TRUE ;
break;
case V_30 :
V_7 = TRUE ;
break;
default:
F_4 ( V_2 , V_19 , V_20 ,
V_21 , L_5 ) ;
break;
}
F_9 ( & V_2 -> V_31 ) ;
for ( V_6 = V_2 -> V_32 ; V_6 ; V_6 = V_6 -> V_33 ) {
if ( V_2 -> V_34 )
break;
V_10 = TRUE ;
V_9 = ( V_11 & 0x1F ) ;
if ( V_6 -> V_35 & ( 1 << V_9 ) )
V_10 = FALSE ;
if ( ( V_10 == TRUE ) ||
( V_6 -> V_36 > V_37 )
|| ( ( V_6 -> V_36 >
V_37 / 2 ) &&
( V_7 == FALSE ) ) ) {
switch ( * ( V_12 ) V_4 -> V_13 ) {
case V_18 :
V_6 -> V_38 . V_39 ++ ;
break;
case V_22 :
V_6 -> V_38 . V_40 ++ ;
break;
case V_25 :
V_6 -> V_38 . V_41 ++ ;
break;
case V_26 :
V_6 -> V_38 . V_42 ++ ;
break;
case V_27 :
V_6 -> V_38 . V_43 ++ ;
break;
case V_28 :
V_6 -> V_38 . V_44 ++ ;
break;
case V_30 :
V_6 -> V_38 . V_45 ++ ;
break;
default:
V_6 -> V_38 . V_46 ++ ;
break;
}
continue;
}
V_8 = F_10 ( V_4 , V_47 ) ;
if ( ! V_8 )
break;
F_11 ( V_6 -> V_48 ,
V_6 -> V_49 , V_8 ) ;
V_6 -> V_36 ++ ;
}
F_12 ( & V_2 -> V_31 ) ;
F_13 ( & V_2 -> V_50 ) ;
F_14 ( V_4 ) ;
F_4 ( V_2 , V_19 , V_20 , V_21 ,
L_6 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_51 = NULL ;
unsigned long V_52 = 0 ;
F_4 ( V_2 , V_19 , V_20 , V_21 ,
L_7 ) ;
while ( 1 ) {
F_16 ( V_2 -> V_53 ,
F_17 ( & V_2 -> V_54 ) ||
V_2 -> V_55 ||
F_18 () ) ;
if ( F_18 () ) {
F_4 ( V_2 , V_19 , V_20 ,
V_21 , L_8 ) ;
return 0 ;
}
if ( TRUE == V_2 -> V_55 ) {
V_2 -> V_55 = FALSE ;
if ( ( FALSE == V_2 -> V_56 )
&& ( ( TRUE == V_2 -> V_57 ) ||
( TRUE == V_2 -> V_58 ) ) ) {
F_4 ( V_2 , V_19 ,
V_20 , V_21 ,
L_9 ) ;
F_19 ( V_2 ) ;
}
continue;
}
while ( F_17 ( & V_2 -> V_54 ) ) {
F_20 ( & V_2 -> V_59 , V_52 ) ;
V_51 = V_2 -> V_60 ;
if ( V_51 ) {
F_21 ( V_2 -> V_60 ,
V_2 -> V_61 ) ;
}
F_22 ( & V_2 -> V_59 ,
V_52 ) ;
F_1 ( V_2 , V_51 ) ;
F_23 ( & V_2 -> V_54 ) ;
}
F_24 ( V_2 ) ;
}
return V_62 ;
}
INT F_25 ( void )
{
struct V_1 * V_2 = F_26 ( V_63 ) ;
struct V_5 * V_6 = NULL ;
struct V_3 * V_64 = NULL ;
for ( V_6 = V_2 -> V_32 ; V_6 ; V_6 = V_6 -> V_33 ) {
while ( V_6 -> V_48 != NULL ) {
V_64 = V_6 -> V_48 ;
F_21 ( V_6 -> V_48 ,
V_6 -> V_49 ) ;
F_14 ( V_64 ) ;
}
V_6 -> V_36 = 0 ;
memset ( ( V_65 ) & V_6 -> V_38 , 0 ,
sizeof( V_66 ) ) ;
}
return V_62 ;
}
