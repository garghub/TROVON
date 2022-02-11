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
V_15 = ( T_3 )
( V_15 +
F_3 ( & V_10 -> V_23 .
V_34 .
V_4 ) ) ;
break;
case V_35 :
V_15 = ( T_3 )
( V_15 +
F_3 ( & V_10 -> V_23 .
V_36 .
V_4 ) ) ;
break;
case V_37 :
V_15 = ( T_3 )
( V_15 +
F_3 ( & V_10 -> V_23 .
V_38 .
V_4 ) ) ;
break;
case V_39 :
V_15 = ( T_3 )
( V_15 +
( ( V_10 -> V_23 . V_40 . V_41 -
1 ) * 4 ) +
F_3 ( & V_10 -> V_23 .
V_40 .
V_4 ) ) ;
break;
case V_42 :
V_15 =
( T_3 ) ( V_15 +
( V_10 -> V_23 . V_43 .
V_44 * 2 ) +
V_10 -> V_23 . V_43 .
V_4 . V_6 +
V_10 -> V_23 . V_43 .
V_45 ) ;
break;
case V_46 :
V_15 =
V_47 [ V_10 ->
V_23 .
V_48 .
type ] ;
V_15 = ( T_3 ) ( V_15 +
V_10 -> V_23 .
V_49 .
V_4 .
V_6 +
V_10 -> V_23 .
V_49 .
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
F_9 ( V_50 ) ;
}
T_5
F_10 ( T_1 * V_51 ,
T_4 V_52 , T_6 * V_12 )
{
T_5 V_53 ;
T_1 * V_54 ;
T_1 * V_55 ;
T_4 V_56 ;
T_2 V_57 ;
T_2 V_7 ;
T_4 V_58 ;
T_1 V_59 ;
T_1 V_8 ;
union V_60 * V_60 ;
F_7 ( V_61 ) ;
* V_12 = V_62 ;
V_54 = V_51 + V_52 ;
while ( V_51 < V_54 ) {
V_53 =
F_11 ( NULL , V_51 ,
& V_59 ) ;
if ( F_12 ( V_53 ) ) {
F_9 ( V_53 ) ;
}
V_60 = ( void * ) V_51 ;
V_7 = F_13 ( V_51 ) ;
V_8 =
V_63 [ V_59 ] ;
V_58 = 0 ;
V_55 =
V_51 + F_14 ( V_51 ) ;
switch ( F_15 ( V_51 ) ) {
case V_64 :
F_16 ( & V_57 , V_55 ) ;
V_58 = F_1 ( V_57 ) ;
break;
case V_65 :
V_58 = F_1 ( * V_55 ) ;
break;
case V_66 :
case V_67 :
V_58 = V_7 ;
if ( V_58 ) {
V_58 -- ;
}
break;
case V_68 :
F_9 ( V_32 ) ;
case V_69 :
case V_70 :
case V_71 :
V_58 =
F_4 ( V_7 ,
V_8 ) ;
break;
case V_72 :
V_58 = ( V_55 [ 1 ] - 1 ) * sizeof( T_4 ) ;
V_58 +=
F_4 ( V_7 -
V_58 ,
V_8 ) ;
break;
case V_73 :
if ( V_60 -> V_43 . V_45 ) {
V_58 +=
V_60 -> V_43 . V_74 -
V_60 -> V_43 . V_75 +
V_60 -> V_43 . V_45 ;
} else {
V_58 +=
V_60 -> V_76 . V_7 +
sizeof( struct V_30 ) -
V_60 -> V_43 . V_75 ;
}
break;
case V_77 :
V_8 =
V_78
[ V_60 -> V_48 . type ] ;
V_58 +=
V_60 -> V_48 . V_7 -
V_8 ;
break;
default:
break;
}
if ( F_15 ( V_51 ) ==
V_77 ) {
V_56 =
V_79
[ V_60 -> V_48 . type ] +
V_58 ;
} else {
V_56 =
V_80 [ V_59 ] +
V_58 ;
}
V_56 = ( T_4 ) F_5 ( V_56 ) ;
* V_12 += V_56 ;
F_17 ( ( V_81 ,
L_1 ,
F_15 ( V_51 ) ,
F_18 ( V_51 ) ,
V_56 ) ) ;
V_51 += F_18 ( V_51 ) ;
}
F_9 ( V_50 ) ;
}
T_5
F_19 ( union V_82 * V_83 ,
T_6 * V_84 )
{
T_4 V_85 ;
T_6 V_86 = 0 ;
union V_82 * * V_87 ;
T_4 V_88 ;
union V_82 * V_89 ;
union V_82 * * V_90 ;
T_1 V_91 ;
T_4 V_92 ;
F_7 ( V_93 ) ;
V_85 = V_83 -> V_94 . V_95 ;
V_87 = V_83 -> V_94 . V_96 ;
for ( V_88 = 0 ; V_88 < V_85 ; V_88 ++ ) {
V_89 = * V_87 ;
if ( ! V_89 ||
( V_89 -> V_97 . type != V_98 ) ) {
F_9 ( V_99 ) ;
}
V_90 = V_89 -> V_94 . V_96 ;
V_91 = FALSE ;
for ( V_92 = 0 ;
V_92 < V_89 -> V_94 . V_95
&& ! V_91 ; V_92 ++ ) {
if ( * V_90 &&
( ( V_100 ==
( * V_90 ) -> V_97 . type ) ||
( ( V_101 ==
( * V_90 ) -> V_97 . type ) &&
( ( * V_90 ) -> V_102 . V_103 ==
V_104 ) ) ) ) {
V_91 = TRUE ;
} else {
V_90 ++ ;
}
}
V_86 += ( sizeof( struct V_105 ) - 4 ) ;
if ( V_91 ) {
if ( ( * V_90 ) -> V_97 . type == V_100 ) {
V_86 += ( ( T_6 )
( * V_90 ) -> string .
V_19 + 1 ) ;
} else {
V_86 += F_20 ( ( * V_90 ) -> V_102 . V_106 ) ;
}
} else {
V_86 += sizeof( T_4 ) ;
}
V_86 = F_21 ( V_86 ) ;
V_87 ++ ;
}
* V_84 =
V_86 + sizeof( struct V_105 ) ;
F_9 ( V_32 ) ;
}
