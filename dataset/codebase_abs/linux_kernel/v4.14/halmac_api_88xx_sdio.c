enum V_1
F_1 ( struct V_2 * V_2 )
{
void * V_3 = NULL ;
struct V_4 * V_4 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 , V_8 ) ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
F_5 ( V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
F_6 ( V_2 , V_12 ) ;
F_7 ( V_2 , V_13 , 0x00000000 ) ;
F_5 ( V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
enum V_1
F_8 ( struct V_2 * V_2 )
{
void * V_3 = NULL ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 , V_14 ) ;
V_3 = V_2 -> V_3 ;
F_5 ( V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
F_5 ( V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
enum V_1
F_9 ( struct V_2 * V_2 ,
struct V_15 * V_16 )
{
T_1 V_17 ;
T_1 V_18 = 0 , V_19 = 0 , V_20 = 0 ;
void * V_3 = NULL ;
struct V_4 * V_4 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 ,
V_21 ) ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
F_5 ( V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
V_20 = F_10 ( V_2 , V_22 ) ;
switch ( V_16 -> V_23 ) {
case V_24 :
V_20 &= ~ ( V_25 ) ;
break;
case V_26 :
case V_27 :
V_20 |= V_25 ;
break;
default:
F_11 ( L_3 ) ;
V_20 &= ~ V_25 ;
break;
}
if ( ! V_16 -> V_28 . V_29 ) {
V_18 = 0xFF ;
V_19 = 0x01 ;
} else {
V_18 = V_16 -> V_28 . V_18 ;
V_19 = V_16 -> V_28 . V_19 ;
}
F_12 ( V_2 , V_22 , V_20 ) ;
F_13 ( V_2 , V_30 ,
( V_31 ) ( V_18 | ( V_19 << V_32 ) ) ) ;
V_17 = F_10 ( V_2 , V_33 ) ;
if ( ( V_20 & V_25 ) != 0 )
F_12 ( V_2 , V_33 ,
V_17 | V_34 ) ;
else
F_12 ( V_2 , V_33 ,
V_17 & ~ ( V_34 ) ) ;
F_5 ( V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
T_1 F_14 ( struct V_2 * V_2 ,
T_2 V_35 )
{
T_1 V_17 ;
void * V_3 = NULL ;
struct V_4 * V_4 ;
enum V_1 V_36 = V_5 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
if ( ( V_35 & 0xFFFF0000 ) == 0 )
V_35 |= V_37 ;
V_36 = F_15 ( V_2 ,
& V_35 ) ;
if ( V_36 != V_5 ) {
F_11 ( L_4 , V_11 , V_36 ) ;
return V_36 ;
}
V_17 = F_16 ( V_3 , V_35 ) ;
return V_17 ;
}
enum V_1
F_17 ( struct V_2 * V_2 ,
T_2 V_35 , T_1 V_38 )
{
void * V_3 = NULL ;
struct V_4 * V_4 ;
enum V_1 V_36 = V_5 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
if ( ( V_35 & 0xFFFF0000 ) == 0 )
V_35 |= V_37 ;
V_36 = F_15 ( V_2 ,
& V_35 ) ;
if ( V_36 != V_5 ) {
F_11 ( L_4 , V_11 , V_36 ) ;
return V_36 ;
}
F_18 ( V_3 , V_35 , V_38 ) ;
return V_5 ;
}
V_31 F_19 ( struct V_2 * V_2 ,
T_2 V_35 )
{
void * V_3 = NULL ;
struct V_4 * V_4 ;
enum V_1 V_36 = V_5 ;
union {
V_31 V_39 ;
T_1 V_40 [ 2 ] ;
T_3 V_41 ;
} V_42 = { 0x0000 } ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
if ( ( V_35 & 0xFFFF0000 ) == 0 )
V_35 |= V_37 ;
V_36 = F_15 ( V_2 ,
& V_35 ) ;
if ( V_36 != V_5 ) {
F_11 ( L_4 , V_11 , V_36 ) ;
return V_36 ;
}
if ( V_2 -> V_43 . V_44 == V_45 ||
( V_35 & ( 2 - 1 ) ) != 0 ||
V_2 -> V_46 ==
V_47 ||
V_2 -> V_46 ==
V_48 ) {
V_42 . V_40 [ 0 ] =
F_16 ( V_3 , V_35 ) ;
V_42 . V_40 [ 1 ] = F_16 ( V_3 ,
V_35 + 1 ) ;
V_42 . V_39 = F_20 ( V_42 . V_41 ) ;
} else {
#if ( V_49 > V_50 )
if ( ( V_35 & 0xffffef00 ) == 0x00000000 ) {
V_42 . V_40 [ 0 ] = F_16 (
V_3 , V_35 ) ;
V_42 . V_40 [ 1 ] = F_16 (
V_3 , V_35 + 1 ) ;
V_42 . V_39 = F_20 ( V_42 . V_39 ) ;
} else {
V_42 . V_39 = F_21 (
V_3 , V_35 ) ;
}
#else
V_42 . V_39 = F_21 ( V_3 ,
V_35 ) ;
#endif
}
return V_42 . V_39 ;
}
enum V_1
F_22 ( struct V_2 * V_2 ,
T_2 V_35 , V_31 V_38 )
{
void * V_3 = NULL ;
struct V_4 * V_4 ;
enum V_1 V_36 = V_5 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
if ( ( V_35 & 0xFFFF0000 ) == 0 )
V_35 |= V_37 ;
V_36 = F_15 ( V_2 ,
& V_35 ) ;
if ( V_36 != V_5 ) {
F_11 ( L_4 , V_11 , V_36 ) ;
return V_36 ;
}
if ( V_2 -> V_43 . V_44 == V_45 ||
( V_35 & ( 2 - 1 ) ) != 0 ||
V_2 -> V_46 ==
V_47 ||
V_2 -> V_46 ==
V_51 ) {
F_18 ( V_3 , V_35 ,
( T_1 ) ( V_38 & 0xFF ) ) ;
F_18 ( V_3 , V_35 + 1 ,
( T_1 ) ( ( V_38 & 0xFF00 ) >> 8 ) ) ;
} else {
F_23 ( V_3 , V_35 ,
V_38 ) ;
}
return V_5 ;
}
T_2 F_24 ( struct V_2 * V_2 ,
T_2 V_35 )
{
void * V_3 = NULL ;
struct V_4 * V_4 ;
enum V_1 V_36 = V_5 ;
T_2 V_52 = 0 ;
union {
T_2 V_53 ;
T_1 V_40 [ 4 ] ;
T_4 V_54 ;
} V_55 = { 0x00000000 } ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
V_52 = V_35 ;
if ( ( V_35 & 0xFFFF0000 ) == 0 )
V_35 |= V_37 ;
V_36 = F_15 ( V_2 ,
& V_35 ) ;
if ( V_36 != V_5 ) {
F_11 ( L_4 , V_11 , V_36 ) ;
return V_36 ;
}
if ( V_2 -> V_43 . V_44 == V_45 ||
( V_35 & ( 4 - 1 ) ) != 0 ) {
V_55 . V_40 [ 0 ] =
F_16 ( V_3 , V_35 ) ;
V_55 . V_40 [ 1 ] = F_16 ( V_3 ,
V_35 + 1 ) ;
V_55 . V_40 [ 2 ] = F_16 ( V_3 ,
V_35 + 2 ) ;
V_55 . V_40 [ 3 ] = F_16 ( V_3 ,
V_35 + 3 ) ;
V_55 . V_53 = F_25 ( V_55 . V_54 ) ;
} else {
#if ( V_49 > V_50 )
if ( ( V_52 & 0xffffef00 ) == 0x00000000 ) {
V_55 . V_40 [ 0 ] = F_16 (
V_3 , V_35 ) ;
V_55 . V_40 [ 1 ] = F_16 (
V_3 , V_35 + 1 ) ;
V_55 . V_40 [ 2 ] = F_16 (
V_3 , V_35 + 2 ) ;
V_55 . V_40 [ 3 ] = F_16 (
V_3 , V_35 + 3 ) ;
V_55 . V_53 = F_25 ( V_55 . V_53 ) ;
} else {
V_55 . V_53 = F_26 (
V_3 , V_35 ) ;
}
#else
V_55 . V_53 = F_26 ( V_3 ,
V_35 ) ;
#endif
}
return V_55 . V_53 ;
}
enum V_1
F_27 ( struct V_2 * V_2 ,
T_2 V_35 , T_2 V_38 )
{
void * V_3 = NULL ;
struct V_4 * V_4 ;
enum V_1 V_36 = V_5 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
if ( ( V_35 & 0xFFFF0000 ) == 0 )
V_35 |= V_37 ;
V_36 = F_15 ( V_2 ,
& V_35 ) ;
if ( V_36 != V_5 ) {
F_11 ( L_4 , V_11 , V_36 ) ;
return V_36 ;
}
if ( V_2 -> V_43 . V_44 == V_45 ||
( V_35 & ( 4 - 1 ) ) != 0 ) {
F_18 ( V_3 , V_35 ,
( T_1 ) ( V_38 & 0xFF ) ) ;
F_18 ( V_3 , V_35 + 1 ,
( T_1 ) ( ( V_38 & 0xFF00 ) >> 8 ) ) ;
F_18 ( V_3 , V_35 + 2 ,
( T_1 ) ( ( V_38 & 0xFF0000 ) >> 16 ) ) ;
F_18 (
V_3 , V_35 + 3 ,
( T_1 ) ( ( V_38 & 0xFF000000 ) >> 24 ) ) ;
} else {
F_28 ( V_3 , V_35 ,
V_38 ) ;
}
return V_5 ;
}
T_1 F_29 ( struct V_2 * V_2 ,
T_2 V_35 , T_2 V_56 ,
T_1 * V_38 )
{
void * V_3 = NULL ;
struct V_4 * V_4 ;
enum V_1 V_36 = V_5 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
if ( ( V_35 & 0xFFFF0000 ) == 0 ) {
F_11 ( L_5 , V_35 ) ;
return V_57 ;
}
V_36 = F_15 ( V_2 ,
& V_35 ) ;
if ( V_36 != V_5 ) {
F_11 ( L_4 , V_11 , V_36 ) ;
return V_36 ;
}
if ( V_2 -> V_43 . V_44 == V_45 ) {
F_11 ( L_6 ,
V_2 -> V_43 . V_44 ) ;
return V_57 ;
}
F_30 ( V_3 , V_35 , V_56 ,
V_38 ) ;
return V_5 ;
}
enum V_1
F_31 ( struct V_2 * V_2 ,
T_1 * V_58 , T_2 V_56 , T_2 * V_59 )
{
T_2 V_60 ;
void * V_3 = NULL ;
struct V_4 * V_4 ;
enum V_61 V_62 ;
enum V_63 V_64 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 , V_65 ) ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
F_5 ( V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
if ( ! V_58 ) {
F_11 ( L_7 ) ;
return V_66 ;
}
if ( V_56 == 0 ) {
F_11 ( L_8 ) ;
return V_67 ;
}
V_62 = (enum V_61 ) F_32 ( V_58 ) ;
switch ( V_62 ) {
case V_68 :
case V_69 :
V_64 =
V_2 -> V_70 [ V_71 ] ;
break;
case V_72 :
case V_73 :
V_64 =
V_2 -> V_70 [ V_74 ] ;
break;
case V_75 :
case V_76 :
V_64 =
V_2 -> V_70 [ V_77 ] ;
break;
case V_78 :
case V_79 :
V_64 =
V_2 -> V_70 [ V_80 ] ;
break;
case V_81 :
V_64 =
V_2 -> V_70 [ V_82 ] ;
break;
case V_83 :
case V_84 :
case V_85 :
V_64 =
V_2 -> V_70 [ V_86 ] ;
break;
default:
F_11 ( L_9 ) ;
return V_87 ;
}
V_60 = ( V_56 >> 2 ) + ( ( V_56 & ( 4 - 1 ) ) ? 1 : 0 ) ;
switch ( V_64 ) {
case V_88 :
* V_59 = V_89 ;
break;
case V_90 :
* V_59 = V_91 ;
break;
case V_92 :
* V_59 = V_93 ;
break;
case V_94 :
* V_59 = V_95 ;
break;
default:
F_11 ( L_10 ) ;
return V_96 ;
}
* V_59 = ( * V_59 << 13 ) |
( V_60 & V_97 ) ;
F_5 ( V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
enum V_1
F_33 ( struct V_2 * V_2 ,
T_1 V_98 , V_31 V_99 )
{
struct V_4 * V_4 ;
void * V_3 = NULL ;
T_1 V_100 , V_101 = 0 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 , V_102 ) ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
F_5 ( V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
if ( ( V_99 & 0xF000 ) != 0 ) {
F_11 ( L_11 ) ;
return V_57 ;
}
for ( V_100 = 3 ; V_100 <= 11 ; V_100 ++ ) {
if ( V_99 == 1 << V_100 ) {
V_101 = 1 ;
break;
}
}
if ( V_101 == 0 ) {
F_11 ( L_12 ) ;
return V_57 ;
}
V_2 -> V_103 . V_104 = V_99 ;
if ( V_98 )
F_13 ( V_2 , V_105 ,
0x8000 | V_99 ) ;
else
F_13 ( V_2 , V_105 ,
V_99 ) ;
F_5 ( V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
enum V_1 F_34 (
struct V_2 * V_2 , T_1 V_98 , V_31 V_99 )
{
struct V_4 * V_4 ;
void * V_3 = NULL ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 , V_102 ) ;
V_3 = V_2 -> V_3 ;
V_4 = (struct V_4 * ) V_2 -> V_4 ;
F_5 (
V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
F_5 (
V_3 , V_9 , V_10 ,
L_13 , V_11 ) ;
F_5 (
V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
enum V_1
F_35 ( struct V_2 * V_2 ,
T_1 * V_58 , T_2 V_56 )
{
T_1 * V_106 ;
V_31 * V_107 ;
T_2 V_100 , V_108 ;
T_2 V_109 , V_110 = 0 ;
T_2 V_111 , V_112 = 0 ;
enum V_1 V_36 = V_5 ;
void * V_3 = NULL ;
enum V_63 V_64 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 , V_113 ) ;
V_3 = V_2 -> V_3 ;
F_5 ( V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
V_109 = F_36 ( V_58 ) ;
V_106 = V_58 ;
V_109 = V_109 == 0 ? 1 : V_109 ;
switch ( (enum V_61 ) F_32 ( V_106 ) ) {
case V_68 :
case V_69 :
V_64 =
V_2 -> V_70 [ V_71 ] ;
break;
case V_72 :
case V_73 :
V_64 =
V_2 -> V_70 [ V_74 ] ;
break;
case V_75 :
case V_76 :
V_64 =
V_2 -> V_70 [ V_77 ] ;
break;
case V_78 :
case V_79 :
V_64 =
V_2 -> V_70 [ V_80 ] ;
break;
case V_81 :
V_64 =
V_2 -> V_70 [ V_82 ] ;
break;
case V_83 :
V_64 =
V_2 -> V_70 [ V_86 ] ;
break;
case V_84 :
case V_85 :
return V_5 ;
default:
F_11 ( L_9 ) ;
return V_87 ;
}
switch ( V_64 ) {
case V_88 :
V_107 =
& V_2 -> V_114 . V_115 ;
break;
case V_90 :
V_107 =
& V_2 -> V_114 . V_116 ;
break;
case V_92 :
V_107 =
& V_2 -> V_114 . V_117 ;
break;
case V_94 :
V_107 =
& V_2 -> V_114 . V_118 ;
break;
default:
F_11 ( L_10 ) ;
return V_96 ;
}
for ( V_100 = 0 ; V_100 < V_109 ; V_100 ++ ) {
V_110 = F_37 ( V_106 ) +
F_38 ( V_106 ) +
( F_39 ( V_106 ) << 3 ) ;
V_111 =
( V_110 >>
V_2 -> V_103 . V_119 ) +
( ( V_110 &
( V_2 -> V_103 . V_120 - 1 ) ) ?
1 :
0 ) ;
V_112 += V_111 ;
V_110 = F_40 ( V_110 , 8 ) ;
V_106 += V_110 ;
}
V_108 = 10 ;
do {
if ( ( T_2 ) ( * V_107 +
V_2 -> V_114 . V_121 ) >
V_112 ) {
if ( * V_107 >= V_112 ) {
* V_107 -=
( V_31 ) V_112 ;
} else {
V_2 -> V_114
. V_121 -=
( V_31 ) ( V_112 -
* V_107 ) ;
* V_107 = 0 ;
}
V_36 = F_41 ( V_2 ,
V_109 , V_58 ) ;
if ( V_36 != V_5 )
return V_36 ;
break;
}
F_42 ( V_2 ) ;
V_108 -- ;
if ( V_108 == 0 )
return V_122 ;
} while ( 1 );
F_5 ( V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
T_2 F_43 ( struct V_2 * V_2 ,
T_2 V_35 )
{
T_1 V_123 ;
T_2 V_108 = 1000 ;
void * V_3 = NULL ;
union {
T_2 V_53 ;
T_1 V_40 [ 4 ] ;
} V_55 = { 0x00000000 } ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
F_28 (
V_3 ,
( V_124 << 13 ) |
( V_125 & V_126 ) ,
V_35 | F_44 ( 19 ) | F_44 ( 17 ) ) ;
do {
V_123 = F_16 (
V_3 ,
( V_124 << 13 ) |
( ( V_125 + 2 ) &
V_126 ) ) ;
V_108 -- ;
} while ( ( V_123 & F_44 ( 4 ) ) != 0 && V_108 > 0 );
V_55 . V_53 = F_26 (
V_3 ,
( V_124 << 13 ) |
( V_127 & V_126 ) ) ;
return V_55 . V_53 ;
}
