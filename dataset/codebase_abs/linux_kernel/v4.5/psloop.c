static T_1
F_1 ( struct V_1 * V_2 ,
T_2 * V_3 , union V_4 * V_5 )
{
T_1 V_6 = V_7 ;
union V_4 * V_8 = NULL ;
const struct V_9 * V_10 ;
F_2 ( V_11 , V_2 ) ;
switch ( V_5 -> V_12 . V_13 ) {
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
F_3 ( & ( V_2 -> V_19 ) ,
F_4 ( V_2 ->
V_20 ) ,
V_5 ) ;
break;
case V_21 :
V_6 = F_5 ( V_2 ,
& ( V_2 -> V_19 ) ,
V_5 ,
V_22 ) ;
if ( F_6 ( V_6 ) ) {
F_7 ( V_6 ) ;
}
V_2 -> V_20 = 0 ;
break;
default:
while ( F_4 ( V_2 -> V_20 ) &&
! V_2 -> V_23 ) {
V_2 -> V_24 = V_2 -> V_19 . V_24 ;
V_6 =
F_8 ( V_2 ,
& ( V_2 -> V_19 ) ,
F_4
( V_2 -> V_20 ) , & V_8 ) ;
if ( F_6 ( V_6 ) ) {
F_7 ( V_6 ) ;
}
if ( V_8 ) {
F_9 ( V_5 , V_8 ) ;
}
F_10 ( V_2 -> V_20 ) ;
}
if ( ( V_2 -> V_25 <= V_26 ) &&
( ( V_2 -> V_27 & V_28 ) == 0 ) ) {
switch ( V_5 -> V_12 . V_13 ) {
case V_29 :
case V_30 :
case V_31 :
if ( V_2 -> V_25 ==
V_32 ) {
F_11 ( V_5 -> V_12 .
V_33 ,
V_3 ,
( V_34 )
( V_2 ->
V_19 .
V_35 -
V_3 ) ,
V_2 ->
V_36 ) ;
}
F_12 ( ( V_37 ,
L_1 ) ) ;
V_2 -> V_19 . V_24 =
V_2 -> V_19 . V_35 ;
V_2 -> V_23 = 0 ;
break;
default:
if ( ( V_2 -> V_25 ==
V_32 )
&& ( V_5 -> V_12 . V_33 -> V_12 . V_13 ==
V_38 ) ) {
V_10 =
F_13 ( V_5 -> V_12 .
V_13 ) ;
if ( ( V_10 -> V_39 ==
V_40 ) && ( ! V_8 ) ) {
F_14 ( ( V_41 ,
L_2
L_3 ,
V_5 -> V_12 .
V_13 ,
( V_34 )
( F_15
( V_3 ,
V_2 ->
V_19 .
V_42 ) +
sizeof( struct
V_43 ) ) ) ) ;
}
}
break;
}
}
switch ( V_5 -> V_12 . V_13 ) {
case V_44 :
V_5 -> V_45 . V_46 = V_2 -> V_19 . V_24 ;
V_5 -> V_45 . V_47 = ( V_34 )
( V_2 -> V_19 . V_35 -
V_2 -> V_19 . V_24 ) ;
V_2 -> V_19 . V_24 =
V_2 -> V_19 . V_35 ;
V_2 -> V_23 = 0 ;
break;
case V_48 :
case V_49 :
case V_50 :
if ( ( V_5 -> V_12 . V_33 ) &&
( V_5 -> V_12 . V_33 -> V_12 . V_13 ==
V_51 )
&& ( V_2 -> V_25 <=
V_26 ) ) {
V_5 -> V_45 . V_46 = V_3 ;
V_5 -> V_45 . V_47 = ( V_34 )
( V_2 -> V_19 . V_35 -
V_3 ) ;
V_2 -> V_19 . V_24 =
V_2 -> V_19 . V_35 ;
V_2 -> V_23 = 0 ;
}
break;
case V_31 :
if ( V_2 -> V_52 ) {
V_2 -> V_52 -> V_53 . V_54 =
V_2 -> V_19 . V_35 ;
}
break;
default:
break;
}
break;
}
F_7 ( V_7 ) ;
}
static void
F_11 ( union V_4 * V_55 ,
T_2 * V_42 , V_34 V_56 , T_3 V_36 )
{
union V_57 * V_58 ;
union V_57 * V_59 ;
union V_57 * V_60 ;
struct V_61 * V_62 ;
F_16 ( V_63 ) ;
V_58 = V_59 = V_64 ;
while ( V_59 ) {
V_58 = V_59 ;
V_59 = V_59 -> V_65 . V_66 ;
}
if ( ! V_58 ||
( ( V_58 -> V_65 . V_42 + V_58 -> V_65 . V_56 ) != V_42 ) ) {
V_60 = F_17 ( V_67 ) ;
if ( ! V_60 ) {
V_68 ;
}
F_12 ( ( V_37 ,
L_4 ,
V_60 ) ) ;
if ( V_55 -> V_12 . V_69 ) {
V_62 = V_55 -> V_12 . V_69 ;
} else {
V_62 = V_70 ;
}
V_60 -> V_65 . V_42 = V_42 ;
V_60 -> V_65 . V_56 = V_56 ;
V_60 -> V_65 . V_36 = V_36 ;
V_60 -> V_65 . V_71 |= V_72 ;
V_60 -> V_65 . V_73 =
F_18 ( union V_57 , V_62 ) ;
if ( ! V_58 ) {
V_64 = V_60 ;
} else {
V_58 -> V_65 . V_66 = V_60 ;
}
} else {
F_12 ( ( V_37 ,
L_5 ,
V_58 ) ) ;
V_58 -> V_65 . V_56 += V_56 ;
}
V_68 ;
}
T_1 F_19 ( struct V_1 * V_2 )
{
T_1 V_6 = V_7 ;
union V_4 * V_5 = NULL ;
struct V_74 * V_19 ;
T_2 * V_3 = NULL ;
F_2 ( V_75 , V_2 ) ;
if ( V_2 -> V_76 == NULL ) {
F_7 ( V_77 ) ;
}
V_19 = & V_2 -> V_19 ;
V_2 -> V_20 = 0 ;
#if ( ! F_20 ( V_78 ) && ! F_20 ( V_79 ) )
if ( V_2 -> V_80 & V_81 ) {
if ( F_21 ( V_19 ) ) {
if ( ( V_19 -> V_82 -> V_83 . V_5 ) &&
( ( V_19 -> V_82 -> V_83 . V_5 -> V_12 .
V_13 == V_29 )
|| ( V_19 -> V_82 -> V_83 . V_5 -> V_12 .
V_13 == V_31 ) )
&& ( V_2 -> V_52 )
&& ( V_2 -> V_52 -> V_12 . V_84 ==
V_85 ) ) {
V_2 -> V_5 = NULL ;
V_6 =
F_22 ( V_2 ,
F_23
( TRUE ) ) ;
if ( F_6 ( V_6 )
&& ( ( V_6 & V_86 ) !=
V_87 ) ) {
if ( V_6 == V_88 ) {
F_24 ( ( V_41 , V_6 ,
L_6 ) ) ;
}
F_24 ( ( V_41 , V_6 ,
L_7 ) ) ;
F_7 ( V_6 ) ;
}
V_6 =
F_25 ( V_2 , V_5 ,
V_6 ) ;
}
F_26 ( V_19 , & V_5 ,
& V_2 -> V_20 ,
& V_2 -> V_23 ) ;
F_12 ( ( V_37 ,
L_8 , V_5 ) ) ;
} else if ( V_2 -> V_89 ) {
V_5 = V_2 -> V_89 ;
V_2 -> V_20 = V_2 -> V_90 ;
}
}
#endif
while ( ( V_19 -> V_24 < V_19 -> V_91 ) || ( V_5 ) ) {
V_3 = V_19 -> V_24 ;
if ( ! V_5 ) {
V_6 =
F_27 ( V_2 , V_3 , & V_5 ) ;
if ( F_6 ( V_6 ) ) {
if ( V_6 == V_92 ) {
continue;
}
if ( V_6 == V_93 ) {
V_6 = V_7 ;
}
if ( V_6 == V_94 ) {
F_7 ( V_6 ) ;
}
V_6 =
F_28 ( V_2 , & V_5 ,
V_6 ) ;
if ( F_6 ( V_6 ) ) {
F_7 ( V_6 ) ;
}
continue;
}
F_29 ( V_5 , V_2 ) ;
}
V_2 -> V_23 = 0 ;
if ( V_2 -> V_20 ) {
V_6 =
F_1 ( V_2 , V_3 , V_5 ) ;
if ( F_6 ( V_6 ) ) {
V_6 =
F_28 ( V_2 , & V_5 ,
V_6 ) ;
if ( F_6 ( V_6 ) ) {
F_7 ( V_6 ) ;
}
continue;
}
}
if ( V_2 -> V_23 ) {
V_6 = F_30 ( V_19 , V_5 ,
V_2 -> V_20 ,
V_2 -> V_23 ) ;
if ( F_6 ( V_6 ) ) {
V_6 =
F_28 ( V_2 , & V_5 ,
V_6 ) ;
if ( F_6 ( V_6 ) ) {
F_7 ( V_6 ) ;
}
continue;
}
V_5 = NULL ;
continue;
}
V_2 -> V_10 =
F_13 ( V_5 -> V_12 . V_13 ) ;
if ( V_2 -> V_10 -> V_95 & V_96 ) {
if ( V_5 -> V_12 . V_13 == V_97 ||
V_5 -> V_12 . V_13 == V_98 ) {
V_5 -> V_45 . V_47 =
( V_34 ) ( V_19 -> V_24 - V_5 -> V_45 . V_46 ) ;
}
}
if ( V_2 -> V_10 -> V_95 & V_99 ) {
V_5 -> V_45 . V_47 =
( V_34 ) ( V_19 -> V_24 - V_5 -> V_45 . V_46 ) ;
}
if ( V_5 -> V_12 . V_13 == V_100 ) {
V_5 -> V_45 . V_47 =
( V_34 ) ( V_19 -> V_24 - V_5 -> V_45 . V_46 ) ;
}
if ( V_2 -> V_101 != NULL ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_102 = V_5 -> V_12 . V_13 ;
V_6 = V_2 -> V_101 ( V_2 ) ;
V_6 =
F_25 ( V_2 , V_5 , V_6 ) ;
if ( V_6 == V_103 ) {
V_6 = V_7 ;
}
}
V_6 = F_28 ( V_2 , & V_5 , V_6 ) ;
if ( F_6 ( V_6 ) ) {
F_7 ( V_6 ) ;
}
}
V_6 = F_31 ( V_2 , V_5 , V_6 ) ;
F_7 ( V_6 ) ;
}
