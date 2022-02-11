static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
F_2 () ;
for ( V_2 = 0 ; V_1 ; V_2 ++ ) {
V_1 &= ( T_2 ) ( V_1 - 1 ) ;
}
return V_2 ;
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
V_13 = V_17 [ V_10 -> type ] ;
switch ( V_10 -> type ) {
case V_18 :
if ( V_10 -> V_19 . V_20 . V_21 == 2 ) {
V_13 -- ;
}
break;
case V_22 :
if ( V_10 -> V_19 . V_20 . V_21 == 0 ) {
V_13 -- ;
}
break;
case V_23 :
if ( V_10 -> V_19 . V_24 . V_25 > 7 ) {
V_13 =
sizeof( struct V_26 ) ;
}
V_13 = ( T_3 )
( V_13 + V_10 -> V_19 . V_24 . V_25 ) ;
break;
case V_27 :
* V_11 = V_12 + V_13 ;
F_8 ( V_28 ) ;
case V_29 :
V_13 = ( T_3 )
( V_13 +
F_3 ( & V_10 -> V_19 .
V_30 .
V_4 ) ) ;
break;
case V_31 :
V_13 = ( T_3 )
( V_13 +
F_3 ( & V_10 -> V_19 .
V_32 .
V_4 ) ) ;
break;
case V_33 :
V_13 = ( T_3 )
( V_13 +
F_3 ( & V_10 -> V_19 .
V_34 .
V_4 ) ) ;
break;
case V_35 :
V_13 = ( T_3 )
( V_13 +
( ( V_10 -> V_19 . V_36 . V_37 -
1 ) * 4 ) +
F_3 ( & V_10 -> V_19 .
V_36 .
V_4 ) ) ;
break;
case V_38 :
V_13 =
( T_3 ) ( V_13 +
( V_10 -> V_19 . V_39 .
V_40 * 2 ) +
V_10 -> V_19 . V_39 .
V_4 . V_6 +
V_10 -> V_19 . V_39 .
V_41 ) ;
break;
case V_42 :
V_13 =
V_43 [ V_10 ->
V_19 .
V_44 .
type ] ;
V_13 = ( T_3 ) ( V_13 +
V_10 -> V_19 .
V_45 .
V_4 .
V_6 +
V_10 -> V_19 .
V_45 .
V_41 ) ;
break;
default:
break;
}
V_12 += V_13 ;
V_10 =
F_9 ( struct V_9 , V_10 ,
V_10 -> V_46 ) ;
}
F_8 ( V_47 ) ;
}
T_5
F_10 ( T_1 * V_48 ,
T_4 V_49 , T_6 * V_11 )
{
T_5 V_50 ;
T_1 * V_51 ;
T_1 * V_52 ;
T_4 V_53 ;
T_2 V_54 ;
T_2 V_7 ;
T_4 V_55 ;
T_1 V_56 ;
T_1 V_8 ;
union V_57 * V_57 ;
F_7 ( V_58 ) ;
* V_11 = V_59 ;
V_51 = V_48 + V_49 ;
while ( V_48 < V_51 ) {
V_50 = F_11 ( V_48 , & V_56 ) ;
if ( F_12 ( V_50 ) ) {
F_8 ( V_50 ) ;
}
V_57 = ( void * ) V_48 ;
V_7 = F_13 ( V_48 ) ;
V_8 =
V_60 [ V_56 ] ;
V_55 = 0 ;
V_52 =
V_48 + F_14 ( V_48 ) ;
switch ( F_15 ( V_48 ) ) {
case V_61 :
F_16 ( & V_54 , V_52 ) ;
V_55 = F_1 ( V_54 ) ;
break;
case V_62 :
V_55 = F_1 ( * V_52 ) ;
break;
case V_63 :
case V_64 :
V_55 = V_7 ;
if ( V_55 ) {
V_55 -- ;
}
break;
case V_65 :
F_8 ( V_28 ) ;
case V_66 :
case V_67 :
case V_68 :
V_55 =
F_4 ( V_7 ,
V_8 ) ;
break;
case V_69 :
V_55 = ( V_52 [ 1 ] - 1 ) * sizeof( T_4 ) ;
V_55 +=
F_4 ( V_7 -
V_55 ,
V_8 ) ;
break;
case V_70 :
if ( V_57 -> V_39 . V_41 ) {
V_55 +=
V_57 -> V_39 . V_71 -
V_57 -> V_39 . V_72 +
V_57 -> V_39 . V_41 ;
} else {
V_55 +=
V_57 -> V_73 . V_7 +
sizeof( struct V_26 ) -
V_57 -> V_39 . V_72 ;
}
break;
case V_74 :
V_8 =
V_75
[ V_57 -> V_44 . type ] ;
V_55 +=
V_57 -> V_44 . V_7 -
V_8 ;
break;
default:
break;
}
if ( F_15 ( V_48 ) ==
V_74 ) {
V_53 =
V_76
[ V_57 -> V_44 . type ] +
V_55 ;
} else {
V_53 =
V_77 [ V_56 ] +
V_55 ;
}
V_53 = ( T_4 ) F_5 ( V_53 ) ;
* V_11 += V_53 ;
F_17 ( ( V_78 ,
L_1 ,
F_15 ( V_48 ) ,
F_18 ( V_48 ) ,
V_53 ) ) ;
V_48 += F_18 ( V_48 ) ;
}
F_8 ( V_47 ) ;
}
T_5
F_19 ( union V_79 * V_80 ,
T_6 * V_81 )
{
T_4 V_82 ;
T_6 V_83 = 0 ;
union V_79 * * V_84 ;
T_4 V_85 ;
union V_79 * V_86 ;
union V_79 * * V_87 ;
T_1 V_88 ;
T_4 V_89 ;
F_7 ( V_90 ) ;
V_82 = V_80 -> V_91 . V_92 ;
V_84 = V_80 -> V_91 . V_93 ;
for ( V_85 = 0 ; V_85 < V_82 ; V_85 ++ ) {
V_86 = * V_84 ;
if ( ! V_86 ||
( V_86 -> V_94 . type != V_95 ) ) {
F_8 ( V_96 ) ;
}
V_87 = V_86 -> V_91 . V_93 ;
V_88 = FALSE ;
for ( V_89 = 0 ; V_89 < 4 && ! V_88 ;
V_89 ++ ) {
if ( * V_87 &&
( ( V_97 ==
( * V_87 ) -> V_94 . type ) ||
( ( V_98 ==
( * V_87 ) -> V_94 . type ) &&
( ( * V_87 ) -> V_99 . V_100 ==
V_101 ) ) ) ) {
V_88 = TRUE ;
} else {
V_87 ++ ;
}
}
V_83 += ( sizeof( struct V_102 ) - 4 ) ;
if ( V_88 ) {
if ( ( * V_87 ) -> V_94 . type == V_97 ) {
V_83 += ( ( T_6 )
( * V_87 ) -> string .
V_46 + 1 ) ;
} else {
V_83 += F_20 ( ( * V_87 ) -> V_99 . V_103 ) ;
}
} else {
V_83 += sizeof( T_4 ) ;
}
V_83 = F_21 ( V_83 ) ;
V_84 ++ ;
}
* V_81 =
V_83 + sizeof( struct V_102 ) ;
F_8 ( V_28 ) ;
}
