static T_1
F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
T_1 V_5 ;
V_6 = TRUE ;
V_5 = V_7 ;
while ( V_5 == V_7 ) {
V_5 = F_2 () ;
if ( F_3 ( V_5 ) ) {
goto V_8;
}
V_5 = F_4 () ;
if ( F_3 ( V_5 ) ) {
goto V_8;
}
V_5 =
F_5 ( V_9 , V_2 ,
V_4 ) ;
}
V_8:
if ( F_3 ( V_5 ) && V_5 != V_10 ) {
F_6 ( ( V_11 , V_5 ,
L_1 ) ) ;
}
return ( V_5 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
#ifndef F_8
if ( V_12 != F_9 () ) {
return;
}
#endif
V_13 = TRUE ;
F_10 ( L_2 ) ;
}
T_1
F_11 ( struct V_1 * V_2 ,
union V_3 * V_4 , T_2 V_14 )
{
union V_3 * V_15 ;
T_1 V_5 = V_16 ;
T_2 V_17 ;
union V_3 * V_18 ;
union V_3 * V_19 ;
T_2 V_20 ;
F_12 () ;
#ifndef F_8
if ( V_12 != F_9 () ) {
return ( V_16 ) ;
}
#endif
if ( V_21 ) {
V_21 = FALSE ;
return ( V_22 ) ;
}
V_20 = ( T_2 ) F_13 ( V_4 -> V_23 . V_24 ,
V_2 -> V_25 . V_26 ) ;
if ( V_2 -> V_27 &&
( V_2 -> V_27 <= V_20 ) ) {
F_10 ( L_3 , V_20 ) ;
V_13 = TRUE ;
V_28 = FALSE ;
V_2 -> V_27 = 0 ;
}
else if ( V_2 -> V_29 &&
( V_2 -> V_29 == V_20 ) ) {
F_10 ( L_4 ,
V_20 ) ;
V_13 = TRUE ;
V_28 = FALSE ;
V_2 -> V_27 = 0 ;
}
if ( V_4 -> V_23 . V_30 == V_31 ) {
return ( V_16 ) ;
}
switch ( V_14 ) {
case V_32 :
case V_33 :
return ( V_16 ) ;
default:
break;
}
if ( ( V_34 ) ||
( V_13 ) || ( V_35 & V_36 ) ) {
if ( ( V_34 ) ||
( V_35 & V_36 ) ) {
F_10
( L_5 ) ;
}
V_17 = V_35 ;
V_35 &= ~ ( V_36 | V_37 ) ;
V_15 = V_4 -> V_23 . V_15 ;
V_4 -> V_23 . V_15 = NULL ;
V_18 = V_4 ;
V_19 = V_4 -> V_23 . V_38 ;
if ( V_19 ) {
if ( ( V_2 -> V_39 ) &&
( V_2 -> V_39 -> V_23 . V_40 ==
V_41 ) ) {
while ( V_19 ) {
if ( ( V_19 -> V_23 . V_30 ==
V_42 )
|| ( V_19 -> V_23 . V_30 ==
V_43 ) ) {
V_18 = V_19 ;
break;
}
V_19 = V_19 -> V_23 . V_38 ;
}
} else {
while ( V_19 ) {
if ( ( V_19 -> V_23 . V_30 ==
V_42 )
|| ( V_19 -> V_23 . V_30 ==
V_44 )
|| ( V_19 -> V_23 . V_30 ==
V_45 )
|| ( V_19 -> V_23 . V_30 ==
V_46 )
|| ( V_19 -> V_23 . V_30 ==
V_43 ) ) {
break;
}
V_18 = V_19 ;
V_19 = V_19 -> V_23 . V_38 ;
}
}
}
#ifdef F_14
F_15 ( V_2 , V_18 , V_47 ) ;
#endif
if ( ( V_4 -> V_23 . V_30 == V_42 ) ||
( V_4 -> V_23 . V_30 == V_43 ) ) {
if ( V_2 -> V_39 -> V_23 . V_48 ) {
F_10
( L_6 ) ;
} else {
F_10
( L_7 ) ;
}
} else if ( V_4 -> V_23 . V_30 == V_44 ) {
F_10
( L_8 ) ;
}
V_4 -> V_23 . V_15 = V_15 ;
F_10 ( L_9 ) ;
if ( ( V_34 ) ||
( V_35 & V_36 ) ) {
F_10 ( L_9 ) ;
}
V_35 = V_17 ;
}
if ( ! V_13 ) {
return ( V_16 ) ;
}
if ( V_28 ) {
if ( V_4 -> V_23 . V_30 != V_49 ) {
return ( V_16 ) ;
}
V_28 = FALSE ;
}
if ( V_4 -> V_23 . V_30 == V_49 ) {
V_13 = FALSE ;
V_2 -> V_27 = 1 ;
}
F_16 () ;
V_5 = F_1 ( V_2 , V_4 ) ;
F_17 () ;
return ( V_5 ) ;
}
T_1 F_18 ( void )
{
T_1 V_5 ;
F_19 ( F_18 ) ;
V_50 = NULL ;
V_51 = NULL ;
V_34 = FALSE ;
V_52 = V_53 ;
V_54 = V_55 | V_56 ;
V_57 = V_58 ;
V_59 = FALSE ;
V_50 = F_20 ( V_60 ) ;
if ( ! V_50 ) {
F_21 ( V_61 ) ;
}
memset ( V_50 , 0 , V_60 ) ;
V_62 [ 0 ] = V_63 ;
V_62 [ 1 ] = 0 ;
V_64 = V_65 ;
V_66 = FALSE ;
if ( V_67 & V_68 ) {
V_5 = F_22 () ;
if ( F_3 ( V_5 ) ) {
F_10 ( L_10 ) ;
F_21 ( V_5 ) ;
}
V_69 = FALSE ;
V_5 = F_23 ( V_70 ,
V_71 , NULL ) ;
if ( F_3 ( V_5 ) ) {
F_6 ( ( V_11 , V_5 ,
L_11 ) ) ;
V_69 = TRUE ;
F_21 ( V_5 ) ;
}
} else {
V_12 = F_9 () ;
}
F_21 ( V_16 ) ;
}
void F_24 ( void )
{
V_66 = TRUE ;
if ( V_67 & V_68 ) {
while ( ! V_69 ) {
F_25 ( 100 ) ;
}
F_26 () ;
}
if ( V_50 ) {
F_27 ( V_50 ) ;
V_50 = NULL ;
}
V_57 = V_72 ;
}
void F_28 ( T_3 V_73 )
{
V_12 = V_73 ;
}
