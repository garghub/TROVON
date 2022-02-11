static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
F_2 () ;
for ( V_2 = 0 ; V_1 ; V_2 ++ ) {
V_1 &= ( T_2 ) ( V_1 - 1 ) ;
}
return ( V_2 ) ;
}
static T_3
F_3 ( struct V_3 * V_4 )
{
F_2 () ;
if ( V_4 -> V_5 ) {
return ( ( T_3 ) ( V_4 -> V_6 + 1 ) ) ;
}
return ( 0 ) ;
}
static T_4
F_4 ( T_4 V_7 ,
T_4 V_8 )
{
T_4 V_6 = 0 ;
F_2 () ;
if ( V_7 > V_8 ) {
V_6 =
V_7 - V_8 - 1 ;
}
return ( ( T_4 ) F_5 ( V_6 ) ) ;
}
T_5
F_6 ( struct V_9 * V_10 , T_6 * V_11 )
{
T_6 V_12 = 0 ;
T_3 V_13 ;
F_7 ( V_14 ) ;
while ( V_10 ) {
if ( V_10 -> type > V_15 ) {
F_8 ( V_16 ) ;
}
if ( ! V_10 -> V_17 ) {
F_8 ( V_18 ) ;
}
V_13 = V_19 [ V_10 -> type ] ;
switch ( V_10 -> type ) {
case V_20 :
if ( V_10 -> V_21 . V_22 . V_23 == 2 ) {
V_13 -- ;
}
break;
case V_24 :
if ( V_10 -> V_21 . V_22 . V_23 == 0 ) {
V_13 -- ;
}
break;
case V_25 :
if ( V_10 -> V_21 . V_26 . V_27 > 7 ) {
V_13 =
sizeof( struct V_28 ) ;
}
V_13 = ( T_3 )
( V_13 + V_10 -> V_21 . V_26 . V_27 ) ;
break;
case V_29 :
* V_11 = V_12 + V_13 ;
F_8 ( V_30 ) ;
case V_31 :
V_13 = ( T_3 )
( V_13 +
F_3 ( & V_10 -> V_21 .
V_32 .
V_4 ) ) ;
break;
case V_33 :
V_13 = ( T_3 )
( V_13 +
F_3 ( & V_10 -> V_21 .
V_34 .
V_4 ) ) ;
break;
case V_35 :
V_13 = ( T_3 )
( V_13 +
F_3 ( & V_10 -> V_21 .
V_36 .
V_4 ) ) ;
break;
case V_37 :
V_13 = ( T_3 )
( V_13 +
( ( V_10 -> V_21 . V_38 . V_39 -
1 ) * 4 ) +
F_3 ( & V_10 -> V_21 .
V_38 .
V_4 ) ) ;
break;
case V_40 :
V_13 =
( T_3 ) ( V_13 +
( V_10 -> V_21 . V_41 .
V_42 * 2 ) +
V_10 -> V_21 . V_41 .
V_4 . V_6 +
V_10 -> V_21 . V_41 .
V_43 ) ;
break;
case V_44 :
V_13 =
V_45 [ V_10 ->
V_21 .
V_46 .
type ] ;
V_13 = ( T_3 ) ( V_13 +
V_10 -> V_21 .
V_47 .
V_4 .
V_6 +
V_10 -> V_21 .
V_47 .
V_43 ) ;
break;
default:
break;
}
V_12 += V_13 ;
V_10 =
F_9 ( struct V_9 , V_10 ,
V_10 -> V_17 ) ;
}
F_8 ( V_48 ) ;
}
T_5
F_10 ( T_1 * V_49 ,
T_4 V_50 , T_6 * V_11 )
{
T_5 V_51 ;
T_1 * V_52 ;
T_1 * V_53 ;
T_4 V_54 ;
T_2 V_55 ;
T_2 V_7 ;
T_4 V_56 ;
T_1 V_57 ;
T_1 V_8 ;
union V_58 * V_58 ;
F_7 ( V_59 ) ;
* V_11 = V_60 ;
V_52 = V_49 + V_50 ;
while ( V_49 < V_52 ) {
V_51 =
F_11 ( NULL , V_49 ,
& V_57 ) ;
if ( F_12 ( V_51 ) ) {
F_8 ( V_51 ) ;
}
V_58 = ( void * ) V_49 ;
V_7 = F_13 ( V_49 ) ;
V_8 =
V_61 [ V_57 ] ;
V_56 = 0 ;
V_53 =
V_49 + F_14 ( V_49 ) ;
switch ( F_15 ( V_49 ) ) {
case V_62 :
F_16 ( & V_55 , V_53 ) ;
V_56 = F_1 ( V_55 ) ;
break;
case V_63 :
V_56 = F_1 ( * V_53 ) ;
break;
case V_64 :
case V_65 :
V_56 = V_7 ;
if ( V_56 ) {
V_56 -- ;
}
break;
case V_66 :
F_8 ( V_30 ) ;
case V_67 :
case V_68 :
case V_69 :
V_56 =
F_4 ( V_7 ,
V_8 ) ;
break;
case V_70 :
V_56 = ( V_53 [ 1 ] - 1 ) * sizeof( T_4 ) ;
V_56 +=
F_4 ( V_7 -
V_56 ,
V_8 ) ;
break;
case V_71 :
if ( V_58 -> V_41 . V_43 ) {
V_56 +=
V_58 -> V_41 . V_72 -
V_58 -> V_41 . V_73 +
V_58 -> V_41 . V_43 ;
} else {
V_56 +=
V_58 -> V_74 . V_7 +
sizeof( struct V_28 ) -
V_58 -> V_41 . V_73 ;
}
break;
case V_75 :
V_8 =
V_76
[ V_58 -> V_46 . type ] ;
V_56 +=
V_58 -> V_46 . V_7 -
V_8 ;
break;
default:
break;
}
if ( F_15 ( V_49 ) ==
V_75 ) {
V_54 =
V_77
[ V_58 -> V_46 . type ] +
V_56 ;
} else {
V_54 =
V_78 [ V_57 ] +
V_56 ;
}
V_54 = ( T_4 ) F_5 ( V_54 ) ;
* V_11 += V_54 ;
F_17 ( ( V_79 ,
L_1 ,
F_15 ( V_49 ) ,
F_18 ( V_49 ) ,
V_54 ) ) ;
V_49 += F_18 ( V_49 ) ;
}
F_8 ( V_48 ) ;
}
T_5
F_19 ( union V_80 * V_81 ,
T_6 * V_82 )
{
T_4 V_83 ;
T_6 V_84 = 0 ;
union V_80 * * V_85 ;
T_4 V_86 ;
union V_80 * V_87 ;
union V_80 * * V_88 ;
T_1 V_89 ;
T_4 V_90 ;
F_7 ( V_91 ) ;
V_83 = V_81 -> V_92 . V_93 ;
V_85 = V_81 -> V_92 . V_94 ;
for ( V_86 = 0 ; V_86 < V_83 ; V_86 ++ ) {
V_87 = * V_85 ;
if ( ! V_87 ||
( V_87 -> V_95 . type != V_96 ) ) {
F_8 ( V_97 ) ;
}
V_88 = V_87 -> V_92 . V_94 ;
V_89 = FALSE ;
for ( V_90 = 0 ;
V_90 < V_87 -> V_92 . V_93
&& ! V_89 ; V_90 ++ ) {
if ( * V_88 &&
( ( V_98 ==
( * V_88 ) -> V_95 . type ) ||
( ( V_99 ==
( * V_88 ) -> V_95 . type ) &&
( ( * V_88 ) -> V_100 . V_101 ==
V_102 ) ) ) ) {
V_89 = TRUE ;
} else {
V_88 ++ ;
}
}
V_84 += ( sizeof( struct V_103 ) - 4 ) ;
if ( V_89 ) {
if ( ( * V_88 ) -> V_95 . type == V_98 ) {
V_84 += ( ( T_6 )
( * V_88 ) -> string .
V_17 + 1 ) ;
} else {
V_84 += F_20 ( ( * V_88 ) -> V_100 . V_104 ) ;
}
} else {
V_84 += sizeof( T_4 ) ;
}
V_84 = F_21 ( V_84 ) ;
V_85 ++ ;
}
* V_82 =
V_84 + sizeof( struct V_103 ) ;
F_8 ( V_30 ) ;
}
