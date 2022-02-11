T_1
F_1 ( struct V_1 * V_2 ,
union V_3 * * V_4 )
{
union V_3 * V_5 ;
struct V_6 * V_7 ;
T_1 V_8 ;
T_2 V_9 ;
char * V_10 ;
T_3 V_11 ;
F_2 ( V_12 ) ;
V_5 = V_2 -> V_5 ;
F_3 ( ( V_13 , L_1 , V_5 ,
V_2 ) ) ;
if ( V_5 ) {
if ( ( V_2 -> V_14 ) &&
( V_2 -> V_14 -> V_15 . V_16 ==
V_17 ) ) {
V_8 = F_4 ( V_2 , V_4 ) ;
F_5 ( V_8 ) ;
}
if ( ( ! ( V_2 -> V_18 -> V_11 & V_19 ) &&
( V_2 -> V_20 != V_21 ) ) ||
( ! ( V_2 -> V_18 -> V_11 & V_22 ) ) ) {
F_5 ( V_23 ) ;
}
if ( V_2 -> V_20 == V_21 ) {
V_10 = V_5 -> V_15 . V_24 . string ;
if ( ! V_10 ) {
F_5 ( V_23 ) ;
}
} else {
V_10 = F_6 ( char , & V_5 -> V_25 . V_26 ) ;
}
} else {
V_10 =
F_7 ( & V_2 -> V_27 ) ;
}
V_9 = V_2 -> V_18 -> V_9 ;
F_3 ( ( V_13 ,
L_2 , V_2 , V_5 ,
V_9 ) ) ;
switch ( V_2 -> V_20 ) {
case V_28 :
case V_29 :
case V_30 :
V_7 = NULL ;
V_8 = V_23 ;
break;
case V_21 :
V_8 =
F_8 ( V_2 -> V_31 , V_10 ,
V_9 , V_32 ,
V_33 , V_2 , & ( V_7 ) ) ;
break;
case V_34 :
if ( V_5 && ( V_5 -> V_25 . V_7 == V_35 ) ) {
V_7 = V_5 -> V_25 . V_7 ;
V_8 =
F_9 ( V_7 , V_9 ,
V_2 ) ;
if ( F_10 ( V_8 ) ) {
F_5 ( V_8 ) ;
}
} else {
V_8 =
F_8 ( V_2 -> V_31 , V_10 ,
V_9 , V_32 ,
V_33 , V_2 ,
& ( V_7 ) ) ;
if ( F_10 ( V_8 ) ) {
#ifdef F_11
if ( V_8 == V_36 ) {
V_8 = V_23 ;
} else {
F_12 ( V_10 ,
V_8 ) ;
}
#else
F_12 ( V_10 , V_8 ) ;
#endif
F_5 ( V_8 ) ;
}
}
switch ( V_7 -> type ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
break;
case V_43 :
case V_44 :
case V_45 :
F_13 ( ( V_46 ,
L_3
L_4 ,
F_14 ( V_7 ) ,
F_15 ( V_7 -> type ) ) ) ;
V_7 -> type = V_37 ;
V_2 -> V_31 -> V_15 . V_24 = V_37 ;
break;
case V_47 :
if ( ( V_7 == V_35 ) &&
( V_2 ->
V_48 & V_49 ) ) {
break;
}
default:
F_16 ( ( V_46 ,
L_5
L_6 ,
F_15 ( V_7 -> type ) ,
F_14 ( V_7 ) ) ) ;
F_5 ( V_50 ) ;
}
break;
default:
if ( V_5 && V_5 -> V_15 . V_7 ) {
V_7 = V_5 -> V_15 . V_7 ;
if ( F_17 ( V_9 ) ) {
V_8 =
F_9 ( V_7 , V_9 ,
V_2 ) ;
if ( F_10 ( V_8 ) ) {
F_5 ( V_8 ) ;
}
}
F_5 ( V_23 ) ;
}
if ( V_2 -> V_51 ) {
V_7 = V_2 -> V_51 ;
V_8 = V_23 ;
break;
}
V_11 = V_52 ;
if ( V_2 -> V_53 == V_32 ) {
V_11 |= V_54 ;
if ( !
( V_2 ->
V_48 & V_49 ) ) {
V_11 |= V_55 ;
}
}
#ifdef F_11
if ( V_2 -> V_20 == V_56 ) {
V_11 |= V_57 ;
}
#endif
V_8 =
F_8 ( V_2 -> V_31 , V_10 ,
V_9 , V_58 , V_11 ,
V_2 , & V_7 ) ;
if ( F_18 ( V_8 ) && ( V_11 & V_55 ) ) {
F_3 ( ( V_13 ,
L_7 ,
F_14 ( V_7 ) , V_7 ) ) ;
}
break;
}
if ( F_10 ( V_8 ) ) {
F_12 ( V_10 , V_8 ) ;
F_5 ( V_8 ) ;
}
if ( ! V_5 ) {
V_5 = F_19 ( V_2 -> V_20 , V_2 -> V_59 ) ;
if ( ! V_5 ) {
F_5 ( V_60 ) ;
}
if ( V_7 ) {
V_5 -> V_25 . V_26 = V_7 -> V_26 . integer ;
}
* V_4 = V_5 ;
}
V_5 -> V_15 . V_7 = V_7 ;
F_5 ( V_8 ) ;
}
T_1 F_20 ( struct V_1 * V_2 )
{
union V_3 * V_5 ;
T_1 V_8 = V_23 ;
T_2 V_9 ;
struct V_6 * V_7 ;
union V_3 * V_61 ;
struct V_6 * V_62 ;
#ifndef F_21
T_3 V_63 ;
T_4 V_64 ;
#endif
F_2 ( V_65 ) ;
V_5 = V_2 -> V_5 ;
F_3 ( ( V_13 , L_8 ,
V_2 -> V_18 -> V_26 , V_5 , V_2 ) ) ;
if ( ! ( V_2 -> V_18 -> V_11 & V_66 ) ) {
F_5 ( V_23 ) ;
}
if ( V_5 -> V_15 . V_67 == V_34 ) {
F_3 ( ( V_13 ,
L_9 , V_5 ,
V_2 ) ) ;
}
V_9 = V_2 -> V_18 -> V_9 ;
V_7 = V_5 -> V_15 . V_7 ;
V_2 -> V_68 [ 0 ] = ( void * ) V_7 ;
V_2 -> V_69 = 1 ;
if ( F_17 ( V_9 ) &&
( V_5 -> V_15 . V_67 != V_70 ) ) {
F_3 ( ( V_13 ,
L_10 ,
F_15 ( V_9 ) , V_5 ) ) ;
V_8 = F_22 ( V_2 ) ;
if ( F_10 ( V_8 ) ) {
goto V_71;
}
}
F_3 ( ( V_13 ,
L_11 ,
F_23 ( V_5 -> V_15 . V_67 ) ,
V_2 , V_5 , V_7 ) ) ;
V_61 = V_5 -> V_15 . V_24 . V_61 ;
switch ( V_2 -> V_18 -> type ) {
#ifndef F_21
case V_72 :
V_8 = F_24 ( V_5 , V_2 ) ;
break;
case V_73 :
if ( V_2 -> V_74 ) {
V_8 = F_25 ( V_5 , V_2 ) ;
}
switch ( V_5 -> V_15 . V_67 ) {
case V_30 :
V_8 =
F_26 ( V_5 ,
( V_75 ) V_61 -> V_15 .
V_7 , V_2 ) ;
break;
case V_29 :
V_8 =
F_27 ( V_5 , V_61 -> V_15 . V_7 ,
V_2 ) ;
break;
case V_28 :
V_8 =
F_28 ( V_5 , V_61 -> V_15 . V_7 ,
V_2 ) ;
break;
default:
break;
}
break;
case V_76 :
V_8 = F_29 ( V_2 , V_61 ) ;
if ( F_10 ( V_8 ) ) {
goto V_71;
}
switch ( V_5 -> V_15 . V_67 ) {
case V_77 :
V_8 = F_30 ( V_2 ) ;
break;
case V_78 :
V_8 = F_31 ( V_2 ) ;
break;
case V_79 :
V_8 = F_32 ( V_2 ) ;
break;
case V_80 :
V_8 = F_33 ( V_2 ) ;
break;
case V_81 :
V_8 = F_34 ( V_2 ) ;
break;
default:
V_8 = V_23 ;
goto V_71;
}
for ( V_63 = 1 ; V_63 < V_2 -> V_69 ; V_63 ++ ) {
F_35 ( V_2 -> V_68 [ V_63 ] ) ;
V_2 -> V_68 [ V_63 ] = NULL ;
}
break;
#endif
case V_82 :
switch ( V_5 -> V_15 . V_67 ) {
#ifndef F_21
case V_83 :
case V_84 :
if ( V_5 -> V_15 . V_67 == V_83 ) {
V_64 = ( V_85 )
( ( V_5 -> V_15 . V_24 . V_61 ) -> V_15 . V_24 .
integer ) ;
} else {
V_64 = V_86 ;
}
if ( V_2 -> V_74 ) {
V_8 = F_36 ( V_5 -> V_25 . V_87 ,
V_5 -> V_25 . V_88 ,
V_64 ,
V_2 ) ;
if ( F_10 ( V_8 ) ) {
F_5 ( V_8 ) ;
}
}
V_8 =
F_37
( F_38 ( V_7 ) ) ;
break;
case V_89 :
V_8 = F_39 ( V_2 , V_7 , V_5 ) ;
break;
case V_90 :
F_3 ( ( V_13 ,
L_12 ,
V_2 , V_5 , V_5 -> V_25 . V_7 ) ) ;
if ( ! F_38 ( V_5 -> V_25 . V_7 ) ) {
V_2 -> V_68 [ 0 ] =
F_6 ( void , V_5 -> V_25 . V_7 ) ;
V_2 -> V_69 = 1 ;
V_8 =
F_29 ( V_2 ,
V_5 -> V_15 . V_24 .
V_61 ) ;
if ( F_18 ( V_8 ) ) {
V_8 =
F_40 ( V_5 -> V_25 .
V_87 ,
V_5 -> V_25 .
V_88 ,
V_2 ) ;
}
V_2 -> V_68 [ 0 ] = NULL ;
V_2 -> V_69 = 0 ;
if ( F_10 ( V_8 ) ) {
F_5 ( V_8 ) ;
}
}
break;
#endif
default:
break;
}
break;
case V_91 :
break;
case V_92 :
F_3 ( ( V_13 ,
L_13 ,
V_2 , V_5 , V_7 ) ) ;
V_8 =
F_8 ( V_2 -> V_31 ,
V_61 -> V_15 . V_24 . string , V_37 ,
V_58 ,
V_33 |
V_57 , V_2 ,
& ( V_62 ) ) ;
if ( F_18 ( V_8 ) ) {
if ( V_62 -> type != V_47 ) {
V_8 = V_50 ;
}
V_5 -> V_15 . V_7 = V_62 ;
} else {
F_12 ( V_61 -> V_15 . V_24 . string , V_8 ) ;
}
break;
default:
break;
}
V_71:
V_2 -> V_68 [ 0 ] = NULL ;
V_2 -> V_69 = 0 ;
F_5 ( V_8 ) ;
}
