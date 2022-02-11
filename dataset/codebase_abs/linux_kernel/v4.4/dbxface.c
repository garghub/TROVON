static T_1
F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
T_1 V_5 ;
V_6 = TRUE ;
V_5 = V_7 ;
while ( V_5 == V_7 ) {
if ( V_8 == V_9 ) {
F_2 ( V_10 ) ;
V_5 =
F_3 ( V_11 ,
V_12 ) ;
if ( F_4 ( V_5 ) ) {
return ( V_5 ) ;
}
} else {
F_5 ( V_13 ) ;
if ( ! V_6 ) {
F_6 ( L_1 ,
V_14 ) ;
} else {
F_6 ( L_1 ,
V_15 ) ;
}
V_5 = F_7 ( V_16 ,
V_17 ,
NULL ) ;
if ( F_4 ( V_5 ) ) {
F_8 ( ( V_18 , V_5 ,
L_2 ) ) ;
return ( V_5 ) ;
}
}
V_5 =
F_9 ( V_16 , V_2 ,
V_4 ) ;
}
return ( V_5 ) ;
}
T_1
F_10 ( struct V_1 * V_2 ,
union V_3 * V_4 , T_2 V_19 )
{
union V_3 * V_20 ;
T_1 V_5 = V_21 ;
T_2 V_22 ;
union V_3 * V_23 ;
union V_3 * V_24 ;
T_2 V_25 ;
F_11 () ;
#ifndef F_12
if ( V_26 != F_13 () ) {
return ( V_21 ) ;
}
#endif
if ( V_27 ) {
V_27 = FALSE ;
return ( V_28 ) ;
}
V_25 = ( T_2 ) F_14 ( V_4 -> V_29 . V_30 ,
V_2 -> V_31 . V_32 ) ;
if ( V_2 -> V_33 &&
( V_2 -> V_33 <= V_25 ) ) {
F_6 ( L_3 , V_25 ) ;
V_34 = TRUE ;
V_35 = FALSE ;
V_2 -> V_33 = 0 ;
}
else if ( V_2 -> V_36 &&
( V_2 -> V_36 == V_25 ) ) {
F_6 ( L_4 ,
V_25 ) ;
V_34 = TRUE ;
V_35 = FALSE ;
V_2 -> V_33 = 0 ;
}
if ( V_4 -> V_29 . V_37 == V_38 ) {
return ( V_21 ) ;
}
switch ( V_19 ) {
case V_39 :
case V_40 :
return ( V_21 ) ;
default:
break;
}
if ( ( V_41 ) ||
( V_34 ) || ( V_42 & V_43 ) ) {
if ( ( V_41 ) ||
( V_42 & V_43 ) ) {
F_6
( L_5 ) ;
}
V_22 = V_42 ;
V_42 &= ~ ( V_43 | V_44 ) ;
V_20 = V_4 -> V_29 . V_20 ;
V_4 -> V_29 . V_20 = NULL ;
V_23 = V_4 ;
V_24 = V_4 -> V_29 . V_45 ;
if ( V_24 ) {
if ( ( V_2 -> V_46 ) &&
( V_2 -> V_46 -> V_29 . V_47 ==
V_48 ) ) {
while ( V_24 ) {
if ( ( V_24 -> V_29 . V_37 ==
V_49 )
|| ( V_24 -> V_29 . V_37 ==
V_50 ) ) {
V_23 = V_24 ;
break;
}
V_24 = V_24 -> V_29 . V_45 ;
}
} else {
while ( V_24 ) {
if ( ( V_24 -> V_29 . V_37 ==
V_49 )
|| ( V_24 -> V_29 . V_37 ==
V_51 )
|| ( V_24 -> V_29 . V_37 ==
V_52 )
|| ( V_24 -> V_29 . V_37 ==
V_53 )
|| ( V_24 -> V_29 . V_37 ==
V_50 ) ) {
break;
}
V_23 = V_24 ;
V_24 = V_24 -> V_29 . V_45 ;
}
}
}
#ifdef F_15
F_16 ( V_2 , V_23 , V_54 ) ;
#endif
if ( ( V_4 -> V_29 . V_37 == V_49 ) ||
( V_4 -> V_29 . V_37 == V_50 ) ) {
if ( V_2 -> V_46 -> V_29 . V_55 ) {
F_6
( L_6 ) ;
} else {
F_6
( L_7 ) ;
}
} else if ( V_4 -> V_29 . V_37 == V_51 ) {
F_6
( L_8 ) ;
}
V_4 -> V_29 . V_20 = V_20 ;
F_6 ( L_9 ) ;
if ( ( V_41 ) ||
( V_42 & V_43 ) ) {
F_6 ( L_9 ) ;
}
V_42 = V_22 ;
}
if ( ! V_34 ) {
return ( V_21 ) ;
}
if ( V_35 ) {
if ( V_4 -> V_29 . V_37 != V_56 ) {
return ( V_21 ) ;
}
V_35 = FALSE ;
}
if ( V_4 -> V_29 . V_37 == V_56 ) {
V_34 = FALSE ;
V_2 -> V_33 = 1 ;
}
V_5 = F_1 ( V_2 , V_4 ) ;
return ( V_5 ) ;
}
T_1 F_17 ( void )
{
T_1 V_5 ;
F_18 ( F_17 ) ;
V_57 = NULL ;
V_58 = NULL ;
V_41 = FALSE ;
V_59 = V_60 ;
V_61 = V_62 | V_63 ;
V_64 = V_13 ;
V_65 = FALSE ;
V_57 = F_19 ( V_66 ) ;
if ( ! V_57 ) {
F_20 ( V_67 ) ;
}
memset ( V_57 , 0 , V_66 ) ;
V_68 [ 0 ] = V_69 ;
V_68 [ 1 ] = 0 ;
V_70 = V_71 ;
V_72 = FALSE ;
if ( V_8 & V_9 ) {
V_5 = F_3 ( V_10 ,
V_12 ) ;
if ( F_4 ( V_5 ) ) {
F_6 ( L_10 ) ;
F_20 ( V_5 ) ;
}
V_5 = F_3 ( V_11 ,
V_12 ) ;
if ( F_4 ( V_5 ) ) {
F_6 ( L_10 ) ;
F_20 ( V_5 ) ;
}
V_73 = FALSE ;
V_5 = F_21 ( V_74 ,
V_75 , NULL ) ;
if ( F_4 ( V_5 ) ) {
F_8 ( ( V_18 , V_5 ,
L_11 ) ) ;
V_73 = TRUE ;
F_20 ( V_5 ) ;
}
} else {
V_26 = F_13 () ;
}
F_20 ( V_21 ) ;
}
void F_22 ( void )
{
V_72 = TRUE ;
if ( V_8 & V_9 ) {
F_2 ( V_11 ) ;
while ( ! V_73 ) {
F_23 ( 100 ) ;
}
}
if ( V_57 ) {
F_24 ( V_57 ) ;
V_57 = NULL ;
}
V_64 = V_76 ;
}
void F_25 ( T_3 V_77 )
{
V_26 = V_77 ;
}
