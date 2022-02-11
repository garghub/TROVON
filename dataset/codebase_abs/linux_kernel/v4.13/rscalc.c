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
F_6 ( struct V_9 * V_10 ,
T_6 V_11 , T_6 * V_12 )
{
T_6 V_13 = 0 ;
struct V_9 * V_14 ;
T_3 V_15 ;
F_7 ( V_16 ) ;
V_14 =
F_8 ( struct V_9 , V_10 , V_11 ) ;
while ( V_10 < V_14 ) {
if ( V_10 -> type > V_17 ) {
F_9 ( V_18 ) ;
}
if ( ! V_10 -> V_19 ) {
F_9 ( V_20 ) ;
}
V_15 = V_21 [ V_10 -> type ] ;
switch ( V_10 -> type ) {
case V_22 :
if ( V_10 -> V_23 . V_24 . V_25 == 2 ) {
V_15 -- ;
}
break;
case V_26 :
if ( V_10 -> V_23 . V_24 . V_25 == 0 ) {
V_15 -- ;
}
break;
case V_27 :
if ( V_10 -> V_23 . V_28 . V_29 > 7 ) {
V_15 =
sizeof( struct V_30 ) ;
}
V_15 = ( T_3 )
( V_15 + V_10 -> V_23 . V_28 . V_29 ) ;
break;
case V_31 :
* V_12 = V_13 + V_15 ;
F_9 ( V_32 ) ;
case V_33 :
V_15 = ( T_3 ) ( V_15 +
F_3
( & V_10 -> V_23 .
V_34 .
V_4 ) ) ;
break;
case V_35 :
V_15 = ( T_3 ) ( V_15 +
F_3
( & V_10 -> V_23 .
V_36 .
V_4 ) ) ;
break;
case V_37 :
V_15 = ( T_3 ) ( V_15 +
F_3
( & V_10 -> V_23 .
V_38 .
V_4 ) ) ;
break;
case V_39 :
V_15 = ( T_3 ) ( V_15 +
( ( V_10 -> V_23 .
V_40 .
V_41 -
1 ) * 4 ) +
F_3
( & V_10 -> V_23 .
V_40 .
V_4 ) ) ;
break;
case V_42 :
V_15 = ( T_3 ) ( V_15 +
( V_10 -> V_23 . V_43 .
V_44 * 2 ) +
V_10 -> V_23 . V_43 .
V_4 .
V_6 +
V_10 -> V_23 . V_43 .
V_45 ) ;
break;
case V_46 :
V_15 = ( T_3 ) ( V_15 +
( V_10 -> V_23 .
V_47 .
V_44 * 2 ) +
V_10 -> V_23 .
V_47 .
V_4 .
V_6 +
V_10 -> V_23 .
V_47 .
V_45 ) ;
break;
case V_48 :
V_15 =
V_49 [ V_10 ->
V_23 .
V_50 .
type ] ;
V_15 = ( T_3 ) ( V_15 +
V_10 -> V_23 .
V_51 .
V_4 .
V_6 +
V_10 -> V_23 .
V_51 .
V_45 ) ;
break;
case V_52 :
V_15 = ( T_3 ) ( V_15 +
( V_10 -> V_23 .
V_53 .
V_44 * 2 ) +
V_10 -> V_23 . V_53 .
V_4 .
V_6 +
V_10 -> V_23 . V_53 .
V_45 ) ;
break;
case V_54 :
V_15 = ( T_3 ) ( V_15 +
( V_10 -> V_23 . V_55 .
V_44 * 2 ) +
V_10 -> V_23 . V_55 .
V_56 .
V_6 +
V_10 -> V_23 . V_55 .
V_45 ) ;
break;
case V_57 :
V_15 = ( T_3 ) ( V_15 +
V_10 -> V_23 .
V_58 .
V_4 .
V_6 +
V_10 -> V_23 .
V_58 .
V_59 .
V_6 +
V_10 -> V_23 .
V_58 .
V_45 ) ;
break;
case V_60 :
V_15 = ( T_3 ) ( V_15 +
V_10 -> V_23 .
V_61 .
V_4 .
V_6 +
V_10 -> V_23 .
V_61 .
V_59 .
V_6 +
V_10 -> V_23 .
V_61 .
V_45 ) ;
break;
default:
break;
}
V_13 += V_15 ;
V_10 =
F_8 ( struct V_9 , V_10 ,
V_10 -> V_19 ) ;
}
F_9 ( V_62 ) ;
}
T_5
F_10 ( T_1 * V_63 ,
T_4 V_64 , T_6 * V_12 )
{
T_5 V_65 ;
T_1 * V_66 ;
T_1 * V_67 ;
T_4 V_68 ;
T_2 V_69 ;
T_2 V_7 ;
T_4 V_70 ;
T_1 V_71 ;
T_1 V_8 ;
union V_72 * V_72 ;
F_7 ( V_73 ) ;
* V_12 = V_74 ;
V_66 = V_63 + V_64 ;
while ( V_63 < V_66 ) {
V_65 =
F_11 ( NULL , V_63 ,
& V_71 ) ;
if ( F_12 ( V_65 ) ) {
F_9 ( V_65 ) ;
}
V_72 = ( void * ) V_63 ;
V_7 = F_13 ( V_63 ) ;
V_8 =
V_75 [ V_71 ] ;
V_70 = 0 ;
V_67 =
V_63 + F_14 ( V_63 ) ;
switch ( F_15 ( V_63 ) ) {
case V_76 :
F_16 ( & V_69 , V_67 ) ;
V_70 = F_1 ( V_69 ) ;
break;
case V_77 :
V_70 = F_1 ( * V_67 ) ;
break;
case V_78 :
case V_79 :
V_70 = V_7 ;
if ( V_70 ) {
V_70 -- ;
}
break;
case V_80 :
F_9 ( V_32 ) ;
case V_81 :
case V_82 :
case V_83 :
V_70 =
F_4 ( V_7 ,
V_8 ) ;
break;
case V_84 :
V_70 = ( V_67 [ 1 ] - 1 ) * sizeof( T_4 ) ;
V_70 +=
F_4 ( V_7 -
V_70 ,
V_8 ) ;
break;
case V_85 :
if ( V_72 -> V_43 . V_45 ) {
V_70 +=
V_72 -> V_43 . V_86 -
V_72 -> V_43 . V_87 +
V_72 -> V_43 . V_45 ;
} else {
V_70 +=
V_72 -> V_88 . V_7 +
sizeof( struct V_30 ) -
V_72 -> V_43 . V_87 ;
}
break;
case V_89 :
if ( V_72 -> V_47 . V_45 ) {
V_70 +=
V_72 -> V_47 . V_86 -
V_72 -> V_47 .
V_87 +
V_72 -> V_47 . V_45 ;
} else {
V_70 +=
V_72 -> V_88 . V_7 +
sizeof( struct V_30 ) -
V_72 -> V_47 . V_87 ;
}
break;
case V_90 :
V_8 =
V_91
[ V_72 -> V_50 . type ] ;
V_70 +=
V_72 -> V_50 . V_7 -
V_8 ;
break;
case V_92 :
if ( V_72 -> V_53 . V_45 ) {
V_70 +=
V_72 -> V_53 . V_86 -
V_72 -> V_53 . V_87 +
V_72 -> V_53 . V_45 ;
} else {
V_70 +=
V_72 -> V_88 . V_7 +
sizeof( struct V_30 ) -
V_72 -> V_53 . V_87 ;
}
break;
case V_93 :
V_70 +=
V_72 -> V_55 . V_86 -
V_72 -> V_55 . V_87 +
V_72 -> V_55 . V_45 ;
break;
case V_94 :
V_70 +=
V_72 -> V_58 . V_86 -
V_72 -> V_58 . V_95 +
V_72 -> V_58 . V_45 ;
break;
case V_96 :
V_70 +=
V_72 -> V_61 . V_86 -
V_72 -> V_61 . V_95 +
V_72 -> V_61 . V_45 ;
break;
default:
break;
}
if ( F_15 ( V_63 ) ==
V_90 ) {
V_68 =
V_97
[ V_72 -> V_50 . type ] +
V_70 ;
} else {
V_68 =
V_98 [ V_71 ] +
V_70 ;
}
V_68 = ( T_4 ) F_5 ( V_68 ) ;
* V_12 += V_68 ;
F_17 ( ( V_99 ,
L_1 ,
F_15 ( V_63 ) ,
F_18 ( V_63 ) ,
V_68 ) ) ;
V_63 += F_18 ( V_63 ) ;
}
F_9 ( V_62 ) ;
}
T_5
F_19 ( union V_100 * V_101 ,
T_6 * V_102 )
{
T_4 V_103 ;
T_6 V_104 = 0 ;
union V_100 * * V_105 ;
T_4 V_106 ;
union V_100 * V_107 ;
union V_100 * * V_108 ;
T_1 V_109 ;
T_4 V_110 ;
F_7 ( V_111 ) ;
V_103 = V_101 -> V_112 . V_113 ;
V_105 = V_101 -> V_112 . V_114 ;
for ( V_106 = 0 ; V_106 < V_103 ; V_106 ++ ) {
V_107 = * V_105 ;
if ( ! V_107 ||
( V_107 -> V_115 . type != V_116 ) ) {
F_9 ( V_117 ) ;
}
V_108 = V_107 -> V_112 . V_114 ;
V_109 = FALSE ;
for ( V_110 = 0 ;
V_110 < V_107 -> V_112 . V_113
&& ! V_109 ; V_110 ++ ) {
if ( * V_108 &&
( ( V_118 ==
( * V_108 ) -> V_115 . type ) ||
( ( V_119 ==
( * V_108 ) -> V_115 . type ) &&
( ( * V_108 ) -> V_120 . V_121 ==
V_122 ) ) ) ) {
V_109 = TRUE ;
} else {
V_108 ++ ;
}
}
V_104 += ( sizeof( struct V_123 ) - 4 ) ;
if ( V_109 ) {
if ( ( * V_108 ) -> V_115 . type == V_118 ) {
V_104 += ( ( T_6 )
( * V_108 ) -> string .
V_19 + 1 ) ;
} else {
V_104 += F_20 ( ( * V_108 ) -> V_120 . V_124 ) ;
}
} else {
V_104 += sizeof( T_4 ) ;
}
V_104 = F_21 ( V_104 ) ;
V_105 ++ ;
}
* V_102 =
V_104 + sizeof( struct V_123 ) ;
F_9 ( V_32 ) ;
}
