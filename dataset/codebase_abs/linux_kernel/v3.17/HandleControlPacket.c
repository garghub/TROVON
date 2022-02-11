static VOID F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
bool V_7 = false ;
struct V_3 * V_8 = NULL ;
CHAR V_9 = 0 ;
bool V_10 = TRUE ;
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
V_10 = false ;
if ( ( V_10 == TRUE ) ||
( V_6 -> V_36 > V_37 )
|| ( ( V_6 -> V_36 >
V_37 / 2 ) &&
( V_7 == false ) ) ) {
struct V_38 * V_39 =
& V_6 -> V_40 ;
switch ( * ( V_12 ) V_4 -> V_13 ) {
case V_18 :
V_39 -> V_41 ++ ;
break;
case V_22 :
V_39 -> V_42 ++ ;
break;
case V_25 :
V_39 -> V_43 ++ ;
break;
case V_26 :
V_39 -> V_44 ++ ;
break;
case V_27 :
V_39 -> V_45 ++ ;
break;
case V_28 :
V_39 -> V_46 ++ ;
break;
case V_30 :
V_39 -> V_47 ++ ;
break;
default:
V_39 -> V_48 ++ ;
break;
}
continue;
}
V_8 = F_10 ( V_4 , V_49 ) ;
if ( ! V_8 )
break;
F_11 ( V_6 -> V_50 ,
V_6 -> V_51 , V_8 ) ;
V_6 -> V_36 ++ ;
}
F_12 ( & V_2 -> V_31 ) ;
F_13 ( & V_2 -> V_52 ) ;
F_14 ( V_4 ) ;
F_4 ( V_2 , V_19 , V_20 , V_21 ,
L_6 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_53 = NULL ;
unsigned long V_54 = 0 ;
F_4 ( V_2 , V_19 , V_20 , V_21 ,
L_7 ) ;
while ( 1 ) {
F_16 ( V_2 -> V_55 ,
F_17 ( & V_2 -> V_56 ) ||
V_2 -> V_57 ||
F_18 () ) ;
if ( F_18 () ) {
F_4 ( V_2 , V_19 , V_20 ,
V_21 , L_8 ) ;
return 0 ;
}
if ( TRUE == V_2 -> V_57 ) {
V_2 -> V_57 = false ;
if ( ( false == V_2 -> V_58 )
&& ( ( TRUE == V_2 -> V_59 ) ||
( TRUE == V_2 -> V_60 ) ) ) {
F_4 ( V_2 , V_19 ,
V_20 , V_21 ,
L_9 ) ;
F_19 ( V_2 ) ;
}
continue;
}
while ( F_17 ( & V_2 -> V_56 ) ) {
F_20 ( & V_2 -> V_61 , V_54 ) ;
V_53 = V_2 -> V_62 ;
if ( V_53 ) {
F_21 ( V_2 -> V_62 ,
V_2 -> V_63 ) ;
}
F_22 ( & V_2 -> V_61 ,
V_54 ) ;
F_1 ( V_2 , V_53 ) ;
F_23 ( & V_2 -> V_56 ) ;
}
F_24 ( V_2 ) ;
}
return V_64 ;
}
INT F_25 ( void )
{
struct V_1 * V_2 = F_26 ( V_65 ) ;
struct V_5 * V_6 = NULL ;
struct V_3 * V_66 = NULL ;
for ( V_6 = V_2 -> V_32 ; V_6 ; V_6 = V_6 -> V_33 ) {
while ( V_6 -> V_50 != NULL ) {
V_66 = V_6 -> V_50 ;
F_21 ( V_6 -> V_50 ,
V_6 -> V_51 ) ;
F_14 ( V_66 ) ;
}
V_6 -> V_36 = 0 ;
memset ( ( V_67 ) & V_6 -> V_40 , 0 ,
sizeof( struct V_38 ) ) ;
}
return V_64 ;
}
