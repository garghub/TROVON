bool F_1 (
struct V_1 * V_2 ,
T_1 * V_3 ,
T_2 V_4 ,
T_2 V_5 )
{
bool V_6 = true ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_3 V_9 ;
T_3 V_10 = 0 , V_11 = 0 ;
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_15 * V_16 ;
unsigned char * V_17 ;
struct V_18 * V_19 ;
T_1 V_20 ;
struct V_21 * V_22 = NULL ;
F_3 ( V_23 , L_1 , V_24 , V_5 ) ;
F_4 ( V_2 ) ;
V_9 = V_13 -> V_25 ;
do {
if ( ( V_5 - V_11 ) > V_9 ) {
V_10 = V_9 ;
V_20 = 0 ;
} else {
V_10 = ( T_3 ) ( V_5 - V_11 ) ;
V_20 = 1 ;
}
V_16 = F_5 ( V_10 +
V_8 -> V_26 -> V_27 + 4 ) ;
if ( V_16 == NULL ) {
V_6 = false ;
goto V_28;
}
memcpy ( ( unsigned char * ) ( V_16 -> V_29 ) , & V_2 , sizeof( V_2 ) ) ;
V_19 = (struct V_18 * ) ( V_16 -> V_29 + V_30 ) ;
V_19 -> V_31 = V_32 ;
V_19 -> V_33 = V_34 ;
V_19 -> V_20 = V_20 ;
V_19 -> V_35 = V_10 ;
V_17 = F_6 ( V_16 , V_8 -> V_26 -> V_27 ) ;
V_22 = (struct V_21 * ) V_17 ;
memset ( V_22 , 0 , sizeof( struct V_21 ) ) ;
memset ( V_22 , 0x12 , 8 ) ;
V_17 = F_6 ( V_16 , V_10 ) ;
memcpy ( V_17 , V_3 , ( T_2 ) V_10 ) ;
V_8 -> V_26 -> V_36 ( V_16 , V_2 ) ;
V_3 += V_10 ;
V_11 += V_10 ;
} while ( V_11 < V_5 );
F_7 ( V_2 , V_37 , V_38 ) ;
V_28:
return V_6 ;
}
static void
F_8 (
struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
#ifdef F_9
enum V_41 V_42 ;
V_43 -> V_44 . V_45 ( V_43 , V_46 ,
( V_47 ) ( & V_42 ) ) ;
if ( V_42 == V_48 )
return;
#endif
if ( V_40 -> V_49 ) {
V_8 -> V_50 . V_51 ++ ;
V_8 -> V_50 . V_52 ++ ;
V_8 -> V_50 . V_53 += V_40 -> V_54 ;
V_8 -> V_50 . V_55 ++ ;
if ( V_40 -> V_56 == V_57 ) {
V_8 -> V_50 . V_58 ++ ;
V_8 -> V_50 . V_59 += V_40 -> V_54 ;
} else if ( V_40 -> V_56 == V_60 ) {
V_8 -> V_50 . V_61 ++ ;
V_8 -> V_50 . V_62 += V_40 -> V_54 ;
} else {
V_8 -> V_50 . V_63 ++ ;
V_8 -> V_50 . V_64 += V_40 -> V_54 ;
}
} else {
V_8 -> V_50 . V_65 ++ ;
V_8 -> V_50 . V_66 ++ ;
V_8 -> V_50 . V_67 += V_40 -> V_54 ;
if ( V_40 -> V_56 == V_57 )
V_8 -> V_50 . V_68 ++ ;
else if ( V_40 -> V_56 == V_60 )
V_8 -> V_50 . V_69 ++ ;
else
V_8 -> V_50 . V_70 ++ ;
}
V_8 -> V_50 . V_71 += V_40 -> V_72 ;
V_8 -> V_50 . V_73 += V_40 -> V_72 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 * V_74 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_39 V_75 ;
V_8 -> V_50 . V_76 ++ ;
memcpy ( ( T_1 * ) & V_75 , V_74 , sizeof( struct V_39 ) ) ;
F_8 ( V_2 , & V_75 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ( V_8 -> V_26 -> V_77 . V_78 == V_79 ) ||
( V_8 -> V_26 -> V_77 . V_78 == V_80 ) ||
( ( V_8 -> V_26 -> V_77 . V_78 == V_81 ) &&
( ! V_8 -> V_26 -> V_82 -> V_83 ) ) )
F_12 ( L_2 ) ;
else
F_12 ( L_3 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 * V_74 )
{
struct V_84 V_85 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_12 ( L_4 ) ;
V_85 . V_86 = V_74 [ 1 ] ;
if ( V_85 . V_86 != ( sizeof( struct V_84 ) - 2 ) ) {
F_12 ( L_5 ) ;
return;
}
if ( V_8 -> V_26 -> V_87 == V_88 ) {
V_85 . V_89 = * ( ( T_2 * ) ( V_74 + 4 ) ) ;
F_12 ( L_6 ,
V_85 . V_89 ) ;
if ( V_85 . V_89 & V_90 ) {
V_8 -> V_26 -> V_91 = true ;
V_8 -> V_50 . V_92 ++ ;
} else if ( V_85 . V_89 & V_93 ) {
V_8 -> V_26 -> V_91 = false ;
V_8 -> V_50 . V_94 ++ ;
}
if ( V_85 . V_89 & V_95 )
F_11 ( V_2 ) ;
}
F_12 ( L_7 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 * V_74 )
{
T_4 V_96 ;
V_96 . V_97 = ( V_74 [ 4 ] & 0x80000000 ) >> 31 ;
V_96 . V_98 = ( V_74 [ 4 ] & 0x60 ) >> 5 ;
V_96 . V_99 = ( V_74 [ 4 ] & 0x18 ) >> 3 ;
V_96 . V_100 = ( V_74 [ 6 ] & 0x0F ) >> 0 ;
V_96 . V_101 = V_74 [ 7 ] ;
V_96 . V_102 = ( V_74 [ 8 ] << 24 ) | ( V_74 [ 9 ] << 16 ) |
( V_74 [ 10 ] << 8 ) | ( V_74 [ 11 ] << 0 ) ;
V_96 . V_103 = ( V_74 [ 12 ] << 24 ) | ( V_74 [ 13 ] << 16 ) |
( V_74 [ 14 ] << 8 ) | ( V_74 [ 15 ] << 0 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
#ifdef F_9
enum V_41 V_106 ;
V_43 -> V_44 . V_45 ( V_43 , V_46 ,
( V_47 ) ( & V_42 ) ) ;
if ( V_42 == V_48 )
return;
#endif
V_8 -> V_50 . V_51 += V_105 -> V_107 ;
V_8 -> V_50 . V_52 += V_105 -> V_107 ;
V_8 -> V_50 . V_65 += V_105 -> V_108 ;
V_8 -> V_50 . V_66 += V_105 -> V_108 ;
V_8 -> V_50 . V_71 += V_105 -> V_109 ;
V_8 -> V_50 . V_73 += V_105 -> V_109 ;
V_8 -> V_50 . V_58 += V_105 -> V_110 ;
V_8 -> V_50 . V_61 += V_105 -> V_111 ;
V_8 -> V_50 . V_63 += V_105 -> V_112 ;
V_8 -> V_50 . V_68 += V_105 -> V_113 ;
V_8 -> V_50 . V_69 += V_105 -> V_114 ;
V_8 -> V_50 . V_70 += V_105 -> V_115 ;
V_8 -> V_50 . V_59 += V_105 -> V_116 ;
V_8 -> V_50 . V_62 += V_105 -> V_117 ;
V_8 -> V_50 . V_64 += V_105 -> V_118 ;
V_8 -> V_50 . V_119 = V_105 -> V_120 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 * V_74 )
{
struct V_104 V_121 ;
memcpy ( ( void * ) & V_121 , ( void * ) V_74 , sizeof( struct V_104 ) ) ;
F_15 ( V_2 , & V_121 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 * V_74 )
{
struct V_122 * V_123 ;
T_1 V_124 , V_125 ;
T_3 V_86 = sizeof( struct V_122 ) ;
T_2 * V_126 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
#ifdef F_9
V_43 -> V_44 . V_45 ( V_43 , V_46 ,
( V_47 ) ( & V_42 ) ) ;
if ( V_42 == V_48 )
return;
#endif
V_126 = ( T_2 * ) V_74 ;
for ( V_124 = 0 ; V_124 < ( V_86 / 4 ) ; V_124 ++ ) {
T_3 V_127 , V_128 ;
V_127 = V_126 [ V_124 ] & 0x0000FFFF ;
V_128 = V_126 [ V_124 ] >> 16 ;
V_126 [ V_124 ] = ( V_127 << 16 ) | V_128 ;
}
V_123 = (struct V_122 * ) V_74 ;
if ( V_123 == NULL )
return;
for ( V_124 = 0 ; V_124 < 16 ; V_124 ++ ) {
if ( V_124 < 4 )
V_8 -> V_50 . V_129 . V_130 [ V_124 ] += V_123 -> V_130 [ V_124 ] ;
if ( V_124 < 8 )
V_8 -> V_50 . V_129 . V_131 [ V_124 ] += V_123 -> V_131 [ V_124 ] ;
for ( V_125 = 0 ; V_125 < 4 ; V_125 ++ )
V_8 -> V_50 . V_129 . V_132 [ V_125 ] [ V_124 ] +=
V_123 -> V_132 [ V_125 ] [ V_124 ] ;
}
}
T_2 F_18 ( struct V_1 * V_2 ,
struct V_133 * V_134 )
{
int V_135 ;
T_1 V_136 , V_137 = 0 ;
T_1 V_138 ;
T_1 * V_139 ;
F_3 ( V_23 , L_8 ) ;
if ( V_134 == NULL )
return 0 ;
V_135 = V_134 -> V_140 ;
V_139 = V_134 -> V_141 ;
V_138 = V_139 [ 0 ] ;
while ( V_135 > 0 || V_137 ++ > 100 ) {
V_138 = V_139 [ 0 ] ;
switch ( V_138 ) {
case V_142 :
F_3 ( V_23 , L_9
L_10 ) ;
F_10 ( V_2 , V_139 ) ;
V_136 = V_143 ;
break;
case V_144 :
F_3 ( V_23 , L_9
L_11 ) ;
F_13 ( V_2 , V_139 ) ;
V_136 = sizeof( struct V_84 ) ;
break;
case V_145 :
F_3 ( V_23 , L_9
L_12 ) ;
F_14 ( V_2 , V_139 ) ;
V_136 = V_146 ;
break;
case V_147 :
F_3 ( V_23 , L_9
L_13 ) ;
F_16 ( V_2 , V_139 ) ;
V_136 = V_148 ;
break;
case V_149 :
F_3 ( V_23 , L_9
L_14 ) ;
V_136 = V_143 ;
break;
case V_150 :
F_3 ( V_23 , L_9
L_15 ) ;
F_17 ( V_2 , V_139 ) ;
V_136 = V_151 ;
break;
default:
F_3 ( V_23 , L_9
L_16 ) ;
return 1 ;
}
V_135 -= V_136 ;
V_139 += V_136 ;
}
return 1 ;
}
