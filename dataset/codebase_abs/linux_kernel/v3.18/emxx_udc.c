static inline T_1 F_1 ( void * V_1 )
{
return F_2 ( V_1 ) ;
}
static inline void F_3 ( void * V_1 , T_1 V_2 )
{
F_4 ( V_2 , V_1 ) ;
}
static inline void F_5 ( void * V_1 , T_1 V_2 )
{
T_1 V_3 = F_2 ( V_1 ) | ( V_2 ) ;
F_4 ( V_3 , V_1 ) ;
}
static inline void F_6 ( void * V_1 , T_1 V_2 )
{
T_1 V_3 = F_2 ( V_1 ) & ~ ( V_2 ) ;
F_4 ( V_3 , V_1 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
int V_6 ;
T_1 V_7 ;
F_8 ( L_1 , V_8 ) ;
if ( V_5 == NULL ) {
F_9 ( L_2 , V_8 ) ;
return;
}
F_10 ( & V_5 -> V_9 ) ;
F_11 ( & V_5 -> V_10 , L_3 ) ;
for ( V_6 = 0x0 ; V_6 < V_11 ; V_6 += 16 ) {
V_7 = F_1 (
( T_1 * ) F_12 ( V_12 + V_6 ) ) ;
F_11 ( & V_5 -> V_10 , L_4 , V_6 , ( int ) V_7 ) ;
V_7 = F_1 (
( T_1 * ) F_12 ( V_12 + V_6 + 4 ) ) ;
F_11 ( & V_5 -> V_10 , L_5 , ( int ) V_7 ) ;
V_7 = F_1 (
( T_1 * ) F_12 ( V_12 + V_6 + 8 ) ) ;
F_11 ( & V_5 -> V_10 , L_5 , ( int ) V_7 ) ;
V_7 = F_1 (
( T_1 * ) F_12 ( V_12 + V_6 + 12 ) ) ;
F_11 ( & V_5 -> V_10 , L_6 , ( int ) V_7 ) ;
}
F_13 ( & V_5 -> V_9 ) ;
}
static void F_14 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
T_2 V_17 ;
T_3 V_18 ;
T_1 V_19 ;
struct V_20 * V_21 ;
struct V_4 * V_5 ;
if ( ( V_14 == NULL ) || ( V_16 == NULL ) )
return;
V_5 = (struct V_4 * ) V_16 -> V_22 ;
V_21 = & V_5 -> V_23 ;
if ( ( V_21 -> V_24 & V_25 ) == V_26 ) {
if ( V_21 -> V_27 == V_28 ) {
V_17 = ( T_2 ) ( V_21 -> V_24 & V_29 ) ;
V_18 = V_21 -> V_30 ;
if ( ( V_17 == V_31 ) &&
( V_18 == V_32 ) ) {
V_19 = ( T_1 ) ( V_21 -> V_33 >> 8 ) ;
F_15 ( V_5 , V_19 ) ;
}
}
}
}
static void F_16 (
struct V_4 * V_5 ,
void * V_34 ,
unsigned V_35
)
{
V_5 -> V_36 . V_37 . V_38 = V_34 ;
V_5 -> V_36 . V_37 . V_35 = V_35 ;
V_5 -> V_36 . V_37 . V_39 = 0 ;
V_5 -> V_36 . V_37 . V_40 = TRUE ;
V_5 -> V_36 . V_37 . V_41 = F_14 ;
V_5 -> V_36 . V_37 . V_42 = - V_43 ;
V_5 -> V_36 . V_37 . V_22 = V_5 ;
V_5 -> V_36 . V_37 . V_44 = 0 ;
}
static T_1 F_17 ( struct V_4 * V_5 )
{
T_1 V_45 , V_46 ;
T_1 V_47 , V_48 , V_49 ;
T_4 V_50 ;
V_48 = ( V_51 / sizeof( T_1 ) ) * 2 ;
V_49 = 0 ;
for ( V_45 = 0 ; V_45 < V_52 - 1 ; V_45 ++ ) {
V_50 = & V_5 -> V_53 -> V_54 [ V_45 ] ;
V_47 = F_1 ( & V_50 -> V_55 ) ;
V_46 = F_1 ( & V_50 -> V_56 ) & V_57 ;
if ( V_46 == 0 ) {
V_49 += ( V_47 & V_58 ) / sizeof( T_1 ) ;
} else {
V_49 += ( ( V_47 & V_58 ) / sizeof( T_1 ) ) * 2 ;
}
if ( ( V_47 >> 16 ) > V_48 )
V_48 = V_47 >> 16 ;
}
return V_48 + V_49 ;
}
static int F_18 ( struct V_4 * V_5 , struct V_59 * V_60 )
{
T_1 V_45 ;
T_1 V_47 ;
T_1 V_61 ;
if ( V_60 -> V_62 == 0 )
return - V_63 ;
V_45 = V_60 -> V_62 - 1 ;
V_61 = F_17 ( V_5 ) ;
V_47 = ( V_61 << 16 ) | V_60 -> V_60 . V_64 ;
F_3 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_55 , V_47 ) ;
V_47 = 1 << ( V_60 -> V_62 + 8 ) ;
F_5 ( & V_5 -> V_53 -> V_65 , V_47 ) ;
switch ( V_60 -> V_66 ) {
case V_67 :
V_47 = V_68 ;
break;
case V_69 :
V_47 = V_70 | V_71 ;
break;
case V_72 :
V_47 = V_73 ;
break;
default:
V_47 = 0 ;
break;
}
F_5 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
F_19 ( V_5 , ( V_60 -> V_62 | V_60 -> V_74 ) ) ;
if ( V_60 -> V_74 == V_75 ) {
V_47 = V_76 | V_77 | V_78 ;
F_5 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
V_47 = ( V_79 | V_80 | V_81 ) ;
F_6 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
V_47 = ( V_82 | V_83 ) ;
F_5 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_84 , V_47 ) ;
} else {
V_47 = ( V_76 | V_77 | V_85 ) ;
F_5 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
V_47 = ( V_86 ) ;
F_6 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
V_47 = ( V_87 | V_88 ) ;
F_5 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_84 , V_47 ) ;
}
return 0 ;
}
static int F_20 ( struct V_4 * V_5 , struct V_59 * V_60 )
{
T_1 V_45 ;
T_1 V_47 ;
if ( ( V_60 -> V_62 == 0 ) || ( V_5 -> V_89 == 0 ) )
return - V_63 ;
V_45 = V_60 -> V_62 - 1 ;
F_3 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_55 , 0 ) ;
V_47 = 1 << ( V_60 -> V_62 + 8 ) ;
F_6 ( & V_5 -> V_53 -> V_65 , V_47 ) ;
if ( V_60 -> V_74 == V_75 ) {
V_47 = V_79 | V_77 ;
F_5 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
V_47 = V_76 | V_78 ;
F_6 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
V_47 = V_82 | V_83 ;
F_6 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_84 , V_47 ) ;
} else {
V_47 = V_77 ;
F_5 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
V_47 = V_76 | V_85 ;
F_6 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
V_47 = V_87 | V_88 ;
F_6 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_84 , V_47 ) ;
}
return 0 ;
}
static void F_21 ( struct V_4 * V_5 , struct V_59 * V_60 )
{
T_1 V_45 ;
T_1 V_47 ;
V_47 = F_1 ( & V_5 -> V_53 -> V_90 ) ;
if ( ( ( V_60 -> V_62 == 0 ) || ( V_47 & ( 1 << V_60 -> V_62 ) ) == 0 ) )
return;
V_45 = V_60 -> V_62 - 1 ;
if ( V_60 -> V_74 == V_75 ) {
V_47 = V_60 -> V_60 . V_64 ;
F_3 ( & V_5 -> V_53 -> V_91 [ V_45 ] . V_92 , V_47 ) ;
V_47 = V_93 ;
F_5 ( & V_5 -> V_53 -> V_91 [ V_45 ] . V_94 , V_47 ) ;
V_47 = V_95 | V_96 | V_97 ;
F_3 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_98 , V_47 ) ;
} else {
F_5 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_85 ) ;
V_47 = V_99 | V_97 ;
F_3 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_98 , V_47 ) ;
}
}
static void F_22 ( struct V_4 * V_5 , struct V_59 * V_60 )
{
T_1 V_45 ;
T_1 V_47 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_5 -> V_89 == 0 )
return;
V_47 = F_1 ( & V_100 -> V_90 ) ;
if ( ( V_60 -> V_62 == 0 ) || ( ( V_47 & ( 1 << V_60 -> V_62 ) ) == 0 ) )
return;
V_45 = V_60 -> V_62 - 1 ;
F_23 ( V_5 , V_60 ) ;
if ( V_60 -> V_74 == V_75 ) {
F_3 ( & V_100 -> V_91 [ V_45 ] . V_92 , 0 ) ;
F_6 ( & V_100 -> V_91 [ V_45 ] . V_94 , V_93 ) ;
F_3 ( & V_100 -> V_54 [ V_45 ] . V_98 , 0 ) ;
} else {
F_6 ( & V_100 -> V_54 [ V_45 ] . V_56 , V_85 ) ;
F_3 ( & V_100 -> V_54 [ V_45 ] . V_98 , 0 ) ;
}
}
static void F_23 ( struct V_4 * V_5 , struct V_59 * V_60 )
{
T_5 V_100 = V_5 -> V_53 ;
F_6 ( & V_100 -> V_91 [ V_60 -> V_62 - 1 ] . V_94 , V_101 ) ;
F_24 ( V_102 ) ;
F_6 ( & V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_98 , V_103 ) ;
}
static void F_25 (
struct V_4 * V_5 ,
T_1 V_62 ,
T_1 V_104 ,
T_1 V_35
)
{
T_1 V_47 ;
T_1 V_45 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_35 >= sizeof( T_1 ) )
return;
if ( V_62 == 0 ) {
F_6 ( & V_100 -> V_105 , V_106 ) ;
if ( V_35 )
F_3 ( & V_100 -> V_107 , V_104 ) ;
V_47 = ( ( V_35 << 5 ) & V_108 ) | V_109 ;
F_3 ( & V_100 -> V_105 , V_47 ) ;
F_5 ( & V_100 -> V_105 , V_106 ) ;
} else {
V_45 = V_62 - 1 ;
F_6 ( & V_100 -> V_54 [ V_45 ] . V_56 , V_85 ) ;
if ( V_35 )
F_3 ( & V_100 -> V_54 [ V_45 ] . V_110 , V_104 ) ;
V_47 = ( ( ( ( ( T_1 ) V_35 ) << 5 ) & V_111 ) | V_112 ) ;
F_5 ( & V_100 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
F_5 ( & V_100 -> V_54 [ V_45 ] . V_56 , V_85 ) ;
}
}
static void F_26 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_2 V_74
)
{
if ( V_37 -> V_37 . V_39 == V_114 ) {
if ( V_37 -> V_115 )
V_37 -> V_37 . V_39 = V_60 -> V_116 ;
else {
V_37 -> V_37 . V_39 = F_27 (
V_5 -> V_117 . V_10 . V_118 ,
V_37 -> V_37 . V_38 ,
V_37 -> V_37 . V_35 ,
( V_74 == V_119 )
? V_120 : V_121 ) ;
}
V_37 -> V_122 = 1 ;
} else {
if ( ! V_37 -> V_115 )
F_28 (
V_5 -> V_117 . V_10 . V_118 ,
V_37 -> V_37 . V_39 ,
V_37 -> V_37 . V_35 ,
( V_74 == V_119 )
? V_120 : V_121 ) ;
V_37 -> V_122 = 0 ;
}
}
static void F_29 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_2 V_74
)
{
T_2 V_47 [ 4 ] ;
T_2 * V_123 ;
T_1 V_124 = 0 ;
if ( V_74 == V_75 ) {
V_124 = V_37 -> V_37 . V_44 % 4 ;
if ( V_124 ) {
V_123 = V_37 -> V_37 . V_38 ;
V_123 += ( V_37 -> V_37 . V_44 - V_124 ) ;
memcpy ( V_47 , V_123 , V_124 ) ;
}
}
if ( V_37 -> V_122 ) {
if ( V_37 -> V_115 ) {
if ( V_74 == V_75 )
memcpy ( V_37 -> V_37 . V_38 , V_60 -> V_125 ,
V_37 -> V_37 . V_44 & 0xfffffffc ) ;
} else
F_30 ( V_5 -> V_117 . V_10 . V_118 ,
V_37 -> V_37 . V_39 , V_37 -> V_37 . V_35 ,
( V_74 == V_119 )
? V_120
: V_121 ) ;
V_37 -> V_37 . V_39 = V_114 ;
V_37 -> V_122 = 0 ;
} else {
if ( ! V_37 -> V_115 )
F_31 ( V_5 -> V_117 . V_10 . V_118 ,
V_37 -> V_37 . V_39 , V_37 -> V_37 . V_35 ,
( V_74 == V_119 )
? V_120
: V_121 ) ;
}
if ( V_124 ) {
V_123 = V_37 -> V_37 . V_38 ;
V_123 += ( V_37 -> V_37 . V_44 - V_124 ) ;
memcpy ( V_123 , V_47 , V_124 ) ;
}
}
static int F_32 ( struct V_4 * V_5 , T_2 * V_126 , T_1 V_35 )
{
T_1 V_6 ;
int V_127 = 0 ;
T_1 V_128 = 0 ;
T_6 * V_129 = ( T_6 * ) V_126 ;
V_128 = V_35 / sizeof( T_1 ) ;
if ( V_128 ) {
for ( V_6 = 0 ; V_6 < V_128 ; V_6 ++ ) {
V_129 -> V_130 = F_1 ( & V_5 -> V_53 -> V_131 ) ;
V_129 ++ ;
}
V_127 = V_128 * sizeof( T_1 ) ;
}
return V_127 ;
}
static int F_33 ( struct V_4 * V_5 , T_2 * V_126 , T_1 V_35 )
{
T_1 V_6 ;
T_1 V_132 = 0 ;
T_6 V_133 ;
T_6 * V_129 = ( T_6 * ) V_126 ;
if ( ( 0 < V_35 ) && ( V_35 < sizeof( T_1 ) ) ) {
V_133 . V_130 = F_1 ( & V_5 -> V_53 -> V_131 ) ;
for ( V_6 = 0 ; V_6 < V_35 ; V_6 ++ )
V_129 -> V_134 . V_135 [ V_6 ] = V_133 . V_134 . V_135 [ V_6 ] ;
V_132 += V_35 ;
}
return V_132 ;
}
static int F_34 ( struct V_4 * V_5 , T_2 * V_126 , T_1 V_35 )
{
T_1 V_6 ;
T_1 V_136 = V_137 ;
T_1 V_128 = 0 ;
T_1 V_138 = 0 ;
T_6 * V_129 = ( T_6 * ) V_126 ;
if ( V_136 < V_35 )
V_128 = V_136 / sizeof( T_1 ) ;
else
V_128 = V_35 / sizeof( T_1 ) ;
for ( V_6 = 0 ; V_6 < V_128 ; V_6 ++ ) {
F_3 ( & V_5 -> V_53 -> V_107 , V_129 -> V_130 ) ;
V_129 ++ ;
V_138 += sizeof( T_1 ) ;
}
return V_138 ;
}
static int F_35 ( struct V_4 * V_5 , T_2 * V_126 , T_1 V_139 )
{
T_1 V_6 ;
T_6 V_133 ;
T_6 * V_129 = ( T_6 * ) V_126 ;
if ( ( 0 < V_139 ) && ( V_139 < sizeof( T_1 ) ) ) {
for ( V_6 = 0 ; V_6 < V_139 ; V_6 ++ )
V_133 . V_134 . V_135 [ V_6 ] = V_129 -> V_134 . V_135 [ V_6 ] ;
F_25 ( V_5 , 0 , V_133 . V_130 , V_139 ) ;
return V_139 ;
}
return 0 ;
}
static int F_36 ( struct V_4 * V_5 , bool V_140 )
{
T_1 V_47 ;
V_47 = F_1 ( & V_5 -> V_53 -> V_105 ) ;
V_47 &= ~ ( T_1 ) V_141 ;
if ( V_140 )
V_47 |= ( V_142 | V_143 | V_109 ) ;
else
V_47 |= ( V_142 | V_109 ) ;
F_3 ( & V_5 -> V_53 -> V_105 , V_47 ) ;
return 0 ;
}
static int F_37 ( struct V_4 * V_5 , bool V_140 )
{
T_1 V_47 ;
V_47 = F_1 ( & V_5 -> V_53 -> V_105 ) ;
V_47 &= ~ ( T_1 ) V_144 ;
if ( V_140 )
V_47 |= V_143 ;
F_3 ( & V_5 -> V_53 -> V_105 , V_47 ) ;
return 0 ;
}
static int F_38 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37
)
{
T_2 * V_145 ;
T_1 V_47 ;
T_1 V_139 = 0 ;
int V_146 = 0 ;
if ( V_37 -> V_37 . V_44 == V_37 -> V_37 . V_35 ) {
if ( ( V_37 -> V_37 . V_44 % V_137 ) == 0 ) {
if ( V_37 -> V_40 ) {
V_37 -> V_40 = false ;
F_36 ( V_5 , FALSE ) ;
return 1 ;
}
}
return 0 ;
}
V_47 = F_1 ( & V_5 -> V_53 -> V_105 ) ;
V_47 |= V_142 ;
V_47 &= ~ ( T_1 ) V_141 ;
F_3 ( & V_5 -> V_53 -> V_105 , V_47 ) ;
V_139 = V_37 -> V_37 . V_35 - V_37 -> V_37 . V_44 ;
V_145 = ( T_2 * ) V_37 -> V_37 . V_38 ;
V_145 += V_37 -> V_37 . V_44 ;
V_146 = F_34 ( V_5 , V_145 , V_139 ) ;
V_37 -> V_147 = V_146 ;
V_139 -= V_146 ;
if ( V_139 == 0 ) {
F_36 ( V_5 , FALSE ) ;
return V_146 ;
}
if ( ( V_139 < sizeof( T_1 ) ) && ( V_146 != V_137 ) ) {
V_145 += V_146 ;
V_146 += F_35 ( V_5 , V_145 , V_139 ) ;
V_37 -> V_147 = V_146 ;
}
return V_146 ;
}
static int F_39 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37
)
{
T_2 * V_145 ;
T_1 V_139 ;
T_1 V_148 ;
int V_146 = 0 ;
int V_149 ;
V_148 = F_1 ( & V_5 -> V_53 -> V_150 ) & V_151 ;
if ( V_148 != 0 ) {
V_149 = 0 ;
V_139 = V_37 -> V_37 . V_35 - V_37 -> V_37 . V_44 ;
V_145 = ( T_2 * ) V_37 -> V_37 . V_38 ;
V_145 += V_37 -> V_37 . V_44 ;
V_146 = F_32 ( V_5 , V_145
, F_40 ( V_139 , V_148 ) ) ;
if ( V_146 < 0 )
return V_146 ;
V_37 -> V_37 . V_44 += V_146 ;
V_148 -= V_146 ;
if ( ( 0 < V_148 ) && ( V_148 < sizeof( T_1 ) ) ) {
V_145 += V_146 ;
V_139 -= V_146 ;
V_146 = F_33 ( V_5 , V_145
, F_40 ( V_139 , V_148 ) ) ;
V_37 -> V_37 . V_44 += V_146 ;
}
} else {
V_149 = 1 ;
}
if ( V_37 -> V_37 . V_44 == V_37 -> V_37 . V_35 ) {
if ( ( V_37 -> V_37 . V_44 % V_137 ) == 0 ) {
if ( V_37 -> V_40 ) {
V_37 -> V_40 = false ;
F_37 ( V_5 , FALSE ) ;
return 1 ;
}
}
return 0 ;
}
if ( ( V_37 -> V_37 . V_44 % V_137 ) != 0 )
return 0 ;
if ( V_37 -> V_37 . V_44 > V_37 -> V_37 . V_35 ) {
F_9 ( L_7 ) ;
return - V_152 ;
}
if ( V_149 != 0 ) {
V_139 = F_1 ( & V_5 -> V_53 -> V_105 ) ;
if ( V_139 & V_144 ) {
F_6 ( & V_5 -> V_53 -> V_105 , V_144 ) ;
}
V_146 = 1 ;
}
return V_146 ;
}
static int F_41 (
struct V_4 * V_5 ,
struct V_113 * V_37 ,
T_1 V_45 ,
T_1 V_35
)
{
T_2 * V_145 ;
T_1 V_153 ;
T_1 V_154 ;
T_1 V_155 ;
T_1 V_156 = 1 ;
T_1 V_47 ;
int V_146 = - V_63 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_37 -> V_157 )
return 1 ;
V_37 -> V_157 = TRUE ;
V_145 = ( T_2 * ) V_37 -> V_37 . V_39 ;
V_145 += V_37 -> V_37 . V_44 ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_158 , ( T_1 ) V_145 ) ;
V_153 = F_1 ( & V_100 -> V_54 [ V_45 ] . V_55 ) & V_58 ;
V_155 = ( V_35 / V_153 ) ;
V_154 = ( V_35 % V_153 ) & ~ ( T_1 ) 0x03 ;
if ( V_159 < V_155 ) {
V_155 = V_159 ;
V_154 = 0 ;
} else if ( 0 != V_154 ) {
if ( 0 == V_155 )
V_156 = 0 ;
V_155 ++ ;
}
V_47 = V_153 | ( V_154 << 16 ) ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_92 , V_47 ) ;
V_47 = ( ( V_155 & 0xff ) << 16 ) | V_93 | V_101 ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_94 , V_47 ) ;
if ( 0 == V_156 ) {
F_3 ( & V_100 -> V_54 [ V_45 ] . V_160 , 0 ) ;
F_6 ( & V_100 -> V_54 [ V_45 ] . V_98 , V_99 ) ;
} else {
F_3 ( & V_100 -> V_54 [ V_45 ] . V_160
, ( V_155 << 16 ) ) ;
F_5 ( & V_100 -> V_54 [ V_45 ] . V_98 , V_99 ) ;
}
F_5 ( & V_100 -> V_54 [ V_45 ] . V_98 , V_103 ) ;
V_146 = V_35 & ~ ( T_1 ) 0x03 ;
V_37 -> V_147 = V_146 ;
return V_146 ;
}
static int F_42 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_1 V_35
)
{
T_2 * V_145 ;
T_1 V_6 ;
T_1 V_47 ;
T_1 V_128 ;
T_6 V_133 ;
T_6 * V_129 ;
int V_146 = 0 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_37 -> V_157 )
return 1 ;
if ( V_35 == 0 )
return 0 ;
V_145 = ( T_2 * ) V_37 -> V_37 . V_38 ;
V_129 = ( T_6 * ) ( V_145 + V_37 -> V_37 . V_44 ) ;
V_128 = V_35 / sizeof( T_1 ) ;
if ( V_128 > 0 ) {
for ( V_6 = 0 ; V_6 < V_128 ; V_6 ++ ) {
V_129 -> V_130 =
F_1 ( & V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_161 ) ;
V_129 ++ ;
}
V_146 = V_128 * sizeof( T_1 ) ;
}
V_47 = V_35 - V_146 ;
if ( V_47 > 0 ) {
V_133 . V_130 = F_1 ( & V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_161 ) ;
for ( V_6 = 0 ; V_6 < V_47 ; V_6 ++ )
V_129 -> V_134 . V_135 [ V_6 ] = V_133 . V_134 . V_135 [ V_6 ] ;
V_146 += V_47 ;
}
V_37 -> V_37 . V_44 += V_146 ;
if ( ( V_37 -> V_37 . V_44 == V_37 -> V_37 . V_35 )
|| ( ( V_37 -> V_37 . V_44 % V_60 -> V_60 . V_64 ) != 0 ) ) {
V_146 = 0 ;
}
return V_146 ;
}
static int F_43 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_1 V_162
)
{
T_1 V_45 ;
T_1 V_163 ;
int V_127 = 1 ;
if ( V_60 -> V_62 == 0 )
return - V_63 ;
V_45 = V_60 -> V_62 - 1 ;
V_163 = F_40 ( ( V_37 -> V_37 . V_35 - V_37 -> V_37 . V_44 ) , V_162 ) ;
if ( ( V_60 -> V_66 != V_69 )
&& ( V_37 -> V_37 . V_39 != 0 )
&& ( V_163 >= sizeof( T_1 ) ) ) {
V_127 = F_41 ( V_5 , V_37 , V_45 , V_163 ) ;
} else {
V_163 = F_44 ( T_1 , V_163 , V_60 -> V_60 . V_64 ) ;
V_127 = F_42 ( V_5 , V_60 , V_37 , V_163 ) ;
}
return V_127 ;
}
static int F_45 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37
)
{
T_1 V_45 ;
T_1 V_148 ;
int V_146 = 1 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_60 -> V_62 == 0 )
return - V_63 ;
V_45 = V_60 -> V_62 - 1 ;
V_148
= F_1 ( & V_100 -> V_54 [ V_45 ] . V_160 ) & V_164 ;
if ( V_148 != 0 ) {
V_146 = F_43 ( V_5 , V_60 , V_37 , V_148 ) ;
if ( V_148 < V_60 -> V_60 . V_64 ) {
if ( V_148 == V_146 ) {
V_37 -> V_37 . V_44 += V_146 ;
V_146 = 0 ;
}
}
} else {
if ( ( V_37 -> V_37 . V_44 == V_37 -> V_37 . V_35 )
|| ( ( V_37 -> V_37 . V_44 % V_60 -> V_60 . V_64 ) != 0 ) ) {
V_146 = 0 ;
}
}
if ( V_146 == 0 ) {
if ( ( V_37 -> V_37 . V_44 % V_60 -> V_60 . V_64 ) == 0 ) {
if ( V_37 -> V_40 ) {
V_37 -> V_40 = false ;
return 1 ;
}
}
}
if ( V_37 -> V_37 . V_44 > V_37 -> V_37 . V_35 ) {
F_9 ( L_7 ) ;
F_9 ( L_8 ,
V_37 -> V_37 . V_44 , V_37 -> V_37 . V_35 ) ;
V_146 = - V_152 ;
}
return V_146 ;
}
static int F_46 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_1 V_45 ,
T_1 V_35
)
{
T_2 * V_145 ;
T_1 V_153 ;
T_1 V_154 ;
T_1 V_155 ;
T_1 V_138 ;
T_1 V_47 ;
int V_146 = - V_63 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_37 -> V_157 )
return 1 ;
#ifdef F_47
if ( V_37 -> V_37 . V_44 == 0 )
F_26 ( V_5 , V_60 , V_37 , V_119 ) ;
#endif
V_37 -> V_157 = TRUE ;
V_153 = F_1 ( & V_100 -> V_54 [ V_45 ] . V_55 ) & V_58 ;
if ( ( V_159 * V_153 ) < V_35 )
V_138 = V_159 * V_153 ;
else
V_138 = V_35 ;
if ( V_153 < V_138 ) {
V_155 = V_138 / V_153 ;
V_154 = ( V_138 % V_153 ) & ~ ( T_1 ) 0x3 ;
if ( V_154 != 0 )
V_155 ++ ;
else
V_154 = V_153 & ~ ( T_1 ) 0x3 ;
} else {
V_155 = 1 ;
V_154 = V_138 & ~ ( T_1 ) 0x3 ;
}
V_47 = V_153 | ( V_154 << 16 ) ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_92 , V_47 ) ;
V_145 = ( T_2 * ) V_37 -> V_37 . V_39 ;
V_145 += V_37 -> V_37 . V_44 ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_158 , ( T_1 ) V_145 ) ;
V_47 = ( ( V_155 & 0xff ) << 16 ) | V_101 ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_94 , V_47 ) ;
V_47 = V_155 << 16 ;
F_3 ( & V_100 -> V_54 [ V_45 ] . V_160 , V_47 ) ;
F_5 ( & V_100 -> V_54 [ V_45 ] . V_98 , V_103 ) ;
V_146 = V_138 & ~ ( T_1 ) 0x3 ;
V_37 -> V_147 = V_146 ;
return V_146 ;
}
static int F_48 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_1 V_35
)
{
T_2 * V_145 ;
T_1 V_6 ;
T_1 V_47 ;
T_1 V_128 ;
T_6 V_133 ;
T_6 * V_129 = NULL ;
int V_146 = 0 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_37 -> V_157 )
return 1 ;
if ( V_35 > 0 ) {
V_145 = ( T_2 * ) V_37 -> V_37 . V_38 ;
V_129 = ( T_6 * ) ( V_145 + V_37 -> V_37 . V_44 ) ;
V_128 = V_35 / sizeof( T_1 ) ;
if ( V_128 > 0 ) {
for ( V_6 = 0 ; V_6 < V_128 ; V_6 ++ ) {
F_3 (
& V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_110
, V_129 -> V_130
) ;
V_129 ++ ;
}
V_146 = V_128 * sizeof( T_1 ) ;
}
}
if ( V_146 != V_60 -> V_60 . V_64 ) {
V_47 = V_35 - V_146 ;
V_133 . V_130 = 0 ;
for ( V_6 = 0 ; V_6 < V_47 ; V_6 ++ )
V_133 . V_134 . V_135 [ V_6 ] = V_129 -> V_134 . V_135 [ V_6 ] ;
F_25 ( V_5 , V_60 -> V_62 , V_133 . V_130 , V_47 ) ;
V_146 += V_47 ;
}
V_37 -> V_147 = V_146 ;
return V_146 ;
}
static int F_49 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_1 V_162
)
{
T_1 V_45 ;
int V_127 = 1 ;
if ( V_60 -> V_62 == 0 )
return - V_63 ;
V_45 = V_60 -> V_62 - 1 ;
if ( ( V_60 -> V_66 != V_69 )
&& ( V_37 -> V_37 . V_39 != 0 )
&& ( V_162 >= sizeof( T_1 ) ) ) {
V_127 = F_46 ( V_5 , V_60 , V_37 , V_45 , V_162 ) ;
} else {
V_162 = F_44 ( T_1 , V_162 , V_60 -> V_60 . V_64 ) ;
V_127 = F_48 ( V_5 , V_60 , V_37 , V_162 ) ;
}
return V_127 ;
}
static int F_50 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37
)
{
T_1 V_45 ;
T_1 V_163 ;
int V_146 = 0 ;
T_1 V_42 ;
if ( V_60 -> V_62 == 0 )
return - V_63 ;
V_45 = V_60 -> V_62 - 1 ;
V_42 = F_1 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_165 ) ;
if ( V_37 -> V_37 . V_44 == 0 ) {
if ( ( V_42 & V_166 ) == 0 )
return 1 ;
} else {
if ( ( V_42 & V_167 ) != 0 )
return 1 ;
}
V_163 = V_37 -> V_37 . V_35 - V_37 -> V_37 . V_44 ;
if ( V_163 > 0 )
V_146 = F_49 ( V_5 , V_60 , V_37 , V_163 ) ;
else if ( V_37 -> V_37 . V_35 == 0 )
F_51 ( V_5 , V_60 -> V_62 ) ;
return V_146 ;
}
static int F_52 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
bool V_168 )
{
int V_127 = - V_63 ;
V_37 -> V_157 = FALSE ;
V_37 -> V_147 = 0 ;
if ( V_37 -> V_37 . V_35 == 0 )
V_37 -> V_40 = false ;
else {
if ( ( V_37 -> V_37 . V_35 % V_60 -> V_60 . V_64 ) == 0 )
V_37 -> V_40 = V_37 -> V_37 . V_40 ;
else
V_37 -> V_40 = false ;
}
if ( V_60 -> V_62 == 0 ) {
switch ( V_5 -> V_169 ) {
case V_170 :
V_127 = F_38 ( V_5 , V_60 , V_37 ) ;
break;
case V_171 :
V_127 = F_39 ( V_5 , V_60 , V_37 ) ;
break;
case V_172 :
V_127 = F_36 ( V_5 , TRUE ) ;
break;
default:
break;
}
} else {
if ( V_60 -> V_74 == V_75 ) {
if ( V_168 == FALSE )
V_127 = F_45 ( V_5 , V_60 , V_37 ) ;
} else {
V_127 = F_50 ( V_5 , V_60 , V_37 ) ;
}
}
return V_127 ;
}
static void F_53 ( struct V_59 * V_60 )
{
T_1 V_35 ;
bool V_168 = FALSE ;
struct V_113 * V_37 ;
if ( F_54 ( & V_60 -> V_173 ) )
V_37 = NULL ;
else
V_37 = F_55 ( V_60 -> V_173 . V_174 , struct V_113 , V_173 ) ;
if ( V_37 == NULL )
return;
if ( V_60 -> V_62 > 0 ) {
V_35 = F_1 (
& V_60 -> V_5 -> V_53 -> V_54 [ V_60 -> V_62 - 1 ] . V_160 ) ;
V_35 &= V_164 ;
if ( V_35 < V_60 -> V_60 . V_64 )
V_168 = TRUE ;
}
F_52 ( V_60 -> V_5 , V_60 , V_37 , V_168 ) ;
}
static void F_19 (
struct V_4 * V_5 ,
T_2 V_175 )
{
T_2 V_45 ;
T_1 V_47 ;
if ( ( V_175 == 0 ) || ( V_175 == 0x80 ) )
return;
V_45 = ( V_175 & 0x7F ) - 1 ;
if ( V_175 & V_119 )
V_47 = V_176 ;
else
V_47 = V_77 | V_177 ;
F_5 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
}
static void F_56 (
struct V_4 * V_5 ,
T_2 V_175 ,
bool V_178 )
{
T_2 V_45 , V_62 ;
T_1 V_47 ;
struct V_59 * V_60 ;
T_5 V_100 = V_5 -> V_53 ;
if ( ( V_175 == 0 ) || ( V_175 == 0x80 ) ) {
if ( V_178 ) {
F_5 ( & V_100 -> V_105 , V_179 ) ;
} else {
F_6 ( & V_100 -> V_105 , V_179 ) ;
}
} else {
V_62 = V_175 & V_180 ;
V_45 = V_62 - 1 ;
V_60 = & V_5 -> V_60 [ V_62 ] ;
if ( V_178 ) {
V_60 -> V_181 = TRUE ;
if ( V_175 & V_119 )
V_47 = V_77 | V_86 ;
else
V_47 = V_80 | V_81 ;
F_5 ( & V_100 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
} else {
V_60 -> V_182 = FALSE ;
if ( V_175 & V_119 ) {
F_6 ( & V_100 -> V_54 [ V_45 ] . V_56
, V_86 ) ;
} else {
V_47 =
F_1 ( & V_100 -> V_54 [ V_45 ] . V_56 ) ;
V_47 &= ~ V_81 ;
V_47 |= V_80 ;
F_3 ( & V_100 -> V_54 [ V_45 ] . V_56
, V_47 ) ;
}
V_60 -> V_182 = FALSE ;
if ( V_60 -> V_181 ) {
V_60 -> V_181 = FALSE ;
F_53 ( V_60 ) ;
}
}
}
}
static void F_15 ( struct V_4 * V_5 , T_1 V_183 )
{
T_1 V_47 ;
if ( V_183 > V_184 )
return;
F_8 ( L_9 , V_183 ) ;
V_47 = F_1 ( & V_5 -> V_53 -> V_185 ) ;
V_47 &= ~ V_186 ;
V_47 |= V_183 << V_187 ;
F_3 ( & V_5 -> V_53 -> V_185 , V_47 ) ;
F_5 ( & V_5 -> V_53 -> V_188 , V_189 ) ;
}
static int F_57 (
struct V_4 * V_5 ,
T_3 V_18 ,
T_3 V_33
)
{
int V_146 = - V_190 ;
switch ( V_18 ) {
case V_191 :
if ( 0x0000 == V_33 ) {
V_5 -> V_192 = V_193 ;
V_146 = 0 ;
}
break;
case V_32 :
V_33 = V_33 >> 8 ;
if ( V_33 <= V_184 )
V_146 = 0 ;
break;
default:
break;
}
return V_146 ;
}
static int F_58 ( struct V_4 * V_5 , T_2 V_175 )
{
T_2 V_62 ;
T_1 V_47 = 0 , V_194 ;
T_5 V_100 = V_5 -> V_53 ;
V_62 = V_175 & ~ V_195 ;
if ( V_62 == 0 ) {
V_47 = F_1 ( & V_100 -> V_105 ) ;
V_194 = V_179 ;
} else {
V_47 = F_1 ( & V_100 -> V_54 [ V_62 - 1 ] . V_56 ) ;
if ( ( V_47 & V_76 ) == 0 )
return - 1 ;
if ( V_175 & V_195 )
V_194 = V_86 ;
else
V_194 = V_81 ;
}
if ( ( V_47 & V_194 ) == 0 )
return 0 ;
return 1 ;
}
static inline int F_59 ( struct V_4 * V_5 , bool V_196 )
{
T_2 V_17 = ( T_2 ) ( V_5 -> V_23 . V_24 & V_29 ) ;
T_2 V_197 = ( T_2 ) ( V_5 -> V_23 . V_24 & V_119 ) ;
T_3 V_18 = V_5 -> V_23 . V_30 ;
T_3 V_33 = V_5 -> V_23 . V_33 ;
T_2 V_175 ;
int V_146 = - V_190 ;
if ( ( 0x0000 != V_5 -> V_23 . V_198 ) ||
( V_75 != V_197 ) ) {
return - V_63 ;
}
switch ( V_17 ) {
case V_31 :
if ( V_196 )
V_146 =
F_57 ( V_5 , V_18 , V_33 ) ;
break;
case V_199 :
if ( 0x0000 == ( V_33 & 0xFF70 ) ) {
if ( V_200 == V_18 ) {
V_175 = V_33 & 0xFF ;
if ( V_196 == FALSE ) {
F_19 (
V_5 , V_175 ) ;
}
F_56 (
V_5 , V_175 , V_196 ) ;
V_146 = 0 ;
}
}
break;
default:
break;
}
if ( V_146 >= 0 )
F_16 ( V_5 , V_5 -> V_201 , 0 ) ;
return V_146 ;
}
static inline enum V_202 F_60 ( struct V_4 * V_5 )
{
T_1 V_47 ;
enum V_202 V_203 = V_204 ;
V_47 = F_1 ( & V_5 -> V_53 -> V_205 ) ;
if ( V_47 & V_206 )
V_203 = V_207 ;
return V_203 ;
}
static void F_61 (
struct V_4 * V_5 ,
struct V_59 * V_60
)
{
T_2 V_175 ;
T_1 V_208 ;
int V_209 = 0 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_60 -> V_74 == V_119 ) {
for ( V_209 = 0
; V_209 < V_210
; V_209 ++ ) {
V_208 = F_1 (
& V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_165 ) ;
if ( ( V_208 & V_211 ) == 0 )
break;
F_24 ( 1 ) ;
}
}
V_175 = V_60 -> V_62 | V_60 -> V_74 ;
F_56 ( V_5 , V_175 , 1 ) ;
}
static int F_62 ( struct V_4 * V_5 )
{
T_1 V_35 ;
T_3 V_212 = 0 ;
T_2 V_17 = ( T_2 ) ( V_5 -> V_23 . V_24 & V_29 ) ;
T_2 V_197 = ( T_2 ) ( V_5 -> V_23 . V_24 & V_119 ) ;
T_2 V_175 ;
int V_146 = - V_63 ;
if ( ( 0x0000 != V_5 -> V_23 . V_30 )
|| ( V_119 != V_197 ) ) {
return V_146 ;
}
V_35 = F_44 ( T_3 , V_5 -> V_23 . V_198 , sizeof( V_212 ) ) ;
switch ( V_17 ) {
case V_31 :
if ( V_5 -> V_23 . V_33 == 0x0000 ) {
if ( V_5 -> V_213 )
V_212 |= ( 1 << V_214 ) ;
if ( V_5 -> V_192 )
V_212 |= ( 1 << V_191 ) ;
V_146 = 0 ;
}
break;
case V_199 :
if ( 0x0000 == ( V_5 -> V_23 . V_33 & 0xFF70 ) ) {
V_175 = ( T_2 ) ( V_5 -> V_23 . V_33 & 0xFF ) ;
V_146 = F_58 ( V_5 , V_175 ) ;
if ( V_146 > 0 )
V_212 |= ( 1 << V_200 ) ;
}
break;
default:
break;
}
if ( V_146 >= 0 ) {
memcpy ( V_5 -> V_201 , & V_212 , V_35 ) ;
F_16 ( V_5 , V_5 -> V_201 , V_35 ) ;
F_38 ( V_5 , & V_5 -> V_60 [ 0 ] , & V_5 -> V_36 ) ;
} else {
F_9 ( L_10 ) ;
}
return V_146 ;
}
static int F_63 ( struct V_4 * V_5 )
{
return F_59 ( V_5 , FALSE ) ;
}
static int F_64 ( struct V_4 * V_5 )
{
return F_59 ( V_5 , TRUE ) ;
}
static int F_65 ( struct V_4 * V_5 )
{
int V_146 = 0 ;
T_1 V_30 = V_5 -> V_23 . V_30 ;
if ( ( 0x00 != V_5 -> V_23 . V_24 ) ||
( 0x0000 != V_5 -> V_23 . V_33 ) ||
( 0x0000 != V_5 -> V_23 . V_198 ) ) {
return - V_63 ;
}
if ( V_30 != ( V_30 & 0x007F ) )
return - V_63 ;
V_30 = V_30 << V_215 ;
F_3 ( & V_5 -> V_53 -> V_216 , V_30 ) ;
F_16 ( V_5 , V_5 -> V_201 , 0 ) ;
return V_146 ;
}
static int F_66 ( struct V_4 * V_5 )
{
T_1 V_217 = ( T_1 ) ( V_5 -> V_23 . V_30 & 0x00ff ) ;
if ( ( 0x0000 != V_5 -> V_23 . V_33 ) ||
( 0x0000 != V_5 -> V_23 . V_198 ) ||
( 0x00 != V_5 -> V_23 . V_24 ) ) {
return - V_63 ;
}
V_5 -> V_218 = V_217 ;
if ( V_217 > 0 ) {
F_5 ( & V_5 -> V_53 -> V_185 , V_219 ) ;
V_5 -> V_220 = V_221 ;
} else {
F_6 ( & V_5 -> V_53 -> V_185 , V_219 ) ;
V_5 -> V_220 = V_222 ;
}
return 0 ;
}
static inline void F_67 ( struct V_4 * V_5 , T_1 * V_223 )
{
if ( ( V_5 == NULL ) && ( V_223 == NULL ) )
return;
* V_223 = F_1 ( & V_5 -> V_53 -> V_224 ) ;
V_223 ++ ;
* V_223 = F_1 ( & V_5 -> V_53 -> V_225 ) ;
}
static inline int F_68 ( struct V_4 * V_5 )
{
bool V_226 = TRUE ;
int V_127 = - V_63 ;
struct V_20 * V_21 ;
V_21 = & V_5 -> V_23 ;
F_67 ( V_5 , ( T_1 * ) V_21 ) ;
if ( V_21 -> V_198 == 0 ) {
V_5 -> V_169 = V_172 ;
} else {
if ( V_21 -> V_24 & V_119 )
V_5 -> V_169 = V_170 ;
else
V_5 -> V_169 = V_171 ;
}
if ( ( V_21 -> V_24 & V_25 ) == V_26 ) {
switch ( V_21 -> V_27 ) {
case V_227 :
V_127 = F_62 ( V_5 ) ;
V_226 = FALSE ;
break;
case V_228 :
V_127 = F_63 ( V_5 ) ;
V_226 = FALSE ;
break;
case V_28 :
V_127 = F_64 ( V_5 ) ;
V_226 = FALSE ;
break;
case V_229 :
V_127 = F_65 ( V_5 ) ;
V_226 = FALSE ;
break;
case V_230 :
V_127 = F_66 ( V_5 ) ;
break;
default:
break;
}
}
if ( V_226 == FALSE ) {
if ( V_5 -> V_169 == V_172 ) {
if ( V_127 >= 0 ) {
V_127 = F_36 ( V_5 , TRUE ) ;
}
}
} else {
F_10 ( & V_5 -> V_9 ) ;
V_127 = V_5 -> V_231 -> V_232 ( & V_5 -> V_117 , & V_5 -> V_23 ) ;
F_13 ( & V_5 -> V_9 ) ;
}
if ( V_127 < 0 )
V_5 -> V_169 = V_233 ;
return V_127 ;
}
static inline int F_69 ( struct V_4 * V_5 )
{
int V_127 ;
struct V_113 * V_37 ;
struct V_59 * V_60 = & V_5 -> V_60 [ 0 ] ;
if ( F_54 ( & V_60 -> V_173 ) )
V_37 = NULL ;
else
V_37 = F_55 ( V_60 -> V_173 . V_174 , struct V_113 , V_173 ) ;
if ( V_37 == NULL )
V_37 = & V_5 -> V_36 ;
V_37 -> V_37 . V_44 += V_37 -> V_147 ;
V_37 -> V_147 = 0 ;
V_127 = F_38 ( V_5 , V_60 , V_37 ) ;
if ( V_127 == 0 ) {
V_5 -> V_169 = V_234 ;
F_37 ( V_5 , TRUE ) ;
}
return 0 ;
}
static inline int F_70 ( struct V_4 * V_5 )
{
int V_127 ;
struct V_113 * V_37 ;
struct V_59 * V_60 = & V_5 -> V_60 [ 0 ] ;
if ( F_54 ( & V_60 -> V_173 ) )
V_37 = NULL ;
else
V_37 = F_55 ( V_60 -> V_173 . V_174 , struct V_113 , V_173 ) ;
if ( V_37 == NULL )
V_37 = & V_5 -> V_36 ;
V_127 = F_39 ( V_5 , V_60 , V_37 ) ;
if ( V_127 == 0 ) {
V_5 -> V_169 = V_172 ;
F_36 ( V_5 , TRUE ) ;
} else if ( V_127 < 0 ) {
F_5 ( & V_5 -> V_53 -> V_105 , V_235 ) ;
V_37 -> V_37 . V_42 = V_127 ;
}
return 0 ;
}
static inline int F_71 ( struct V_4 * V_5 )
{
struct V_113 * V_37 ;
struct V_59 * V_60 = & V_5 -> V_60 [ 0 ] ;
if ( F_54 ( & V_60 -> V_173 ) )
V_37 = NULL ;
else
V_37 = F_55 ( V_60 -> V_173 . V_174 , struct V_113 , V_173 ) ;
if ( V_37 == NULL ) {
V_37 = & V_5 -> V_36 ;
if ( V_37 -> V_37 . V_41 )
V_37 -> V_37 . V_41 ( & V_60 -> V_60 , & V_37 -> V_37 ) ;
} else {
if ( V_37 -> V_37 . V_41 )
F_72 ( V_60 , V_37 , 0 ) ;
}
V_5 -> V_169 = V_233 ;
return 0 ;
}
static inline void F_73 ( struct V_4 * V_5 )
{
int V_6 ;
T_1 V_42 ;
T_1 V_236 ;
int V_127 = - 1 ;
V_42 = F_1 ( & V_5 -> V_53 -> V_237 ) ;
V_236 = V_42 & V_238 ;
F_3 ( & V_5 -> V_53 -> V_237 , ~ ( T_1 ) V_236 ) ;
V_42 &= ( V_239 | V_240 | V_241
| V_242 | V_243 ) ;
if ( V_42 == 0 ) {
F_8 ( L_11 , V_8 ) ;
F_8 ( L_12 , V_236 ) ;
return;
}
if ( V_5 -> V_117 . V_203 == V_244 )
V_5 -> V_117 . V_203 = F_60 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_245 ; V_6 ++ ) {
switch ( V_5 -> V_169 ) {
case V_233 :
if ( V_42 & V_239 ) {
V_42 = 0 ;
V_127 = F_68 ( V_5 ) ;
}
break;
case V_170 :
if ( V_42 & V_240 ) {
V_42 &= ~ V_240 ;
V_127 = F_69 ( V_5 ) ;
}
break;
case V_171 :
if ( V_42 & V_241 ) {
V_42 &= ~ V_241 ;
V_127 = F_70 ( V_5 ) ;
}
break;
case V_172 :
if ( ( V_42 & V_242 ) || ( V_42 & V_239 ) ) {
V_42 &= ~ ( V_242 | V_240 ) ;
V_127 = F_71 ( V_5 ) ;
}
break;
case V_234 :
if ( ( V_42 & V_242 )
|| ( V_42 & V_239 )
|| ( V_42 & V_243 ) ) {
V_42 &= ~ ( V_242
| V_241
| V_243 ) ;
V_127 = F_71 ( V_5 ) ;
}
break;
default:
V_42 = 0 ;
break;
}
if ( V_42 == 0 )
break;
}
if ( V_127 < 0 ) {
F_56 ( V_5 , 0 , TRUE ) ;
}
}
static void F_72 (
struct V_59 * V_60 ,
struct V_113 * V_37 ,
int V_42 )
{
struct V_4 * V_5 = V_60 -> V_5 ;
F_74 ( & V_37 -> V_173 ) ;
if ( V_42 == - V_246 )
F_75 ( V_5 , V_60 ) ;
if ( F_76 ( V_37 -> V_37 . V_42 == - V_43 ) )
V_37 -> V_37 . V_42 = V_42 ;
if ( V_60 -> V_182 )
F_61 ( V_5 , V_60 ) ;
else {
if ( ! F_54 ( & V_60 -> V_173 ) )
F_53 ( V_60 ) ;
}
#ifdef F_47
if ( ( V_60 -> V_74 == V_75 ) && ( V_60 -> V_62 > 0 ) &&
( V_37 -> V_37 . V_39 != 0 ) )
F_29 ( V_5 , V_60 , V_37 , V_75 ) ;
#endif
F_10 ( & V_5 -> V_9 ) ;
V_37 -> V_37 . V_41 ( & V_60 -> V_60 , & V_37 -> V_37 ) ;
F_13 ( & V_5 -> V_9 ) ;
}
static inline void F_77 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 )
{
int V_146 = 0 ;
T_1 V_42 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_37 -> V_157 )
return;
V_37 -> V_37 . V_44 += V_37 -> V_147 ;
V_37 -> V_147 = 0 ;
if ( V_37 -> V_37 . V_44 != V_37 -> V_37 . V_35 ) {
V_146 = F_50 ( V_5 , V_60 , V_37 ) ;
} else {
if ( V_37 -> V_40 && ( ( V_37 -> V_37 . V_44 % V_60 -> V_60 . V_64 ) == 0 ) ) {
V_42 =
F_1 ( & V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_165 ) ;
if ( ( V_42 & V_167 ) == 0 ) {
V_37 -> V_40 = false ;
F_51 ( V_5 , V_60 -> V_62 ) ;
}
return;
}
}
if ( V_146 <= 0 ) {
F_72 ( V_60 , V_37 , V_146 ) ;
}
}
static inline void F_78 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 )
{
int V_146 ;
V_146 = F_45 ( V_5 , V_60 , V_37 ) ;
if ( V_146 <= 0 )
F_72 ( V_60 , V_37 , V_146 ) ;
}
static inline void F_79 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 )
{
T_1 V_153 ;
T_1 V_247 ;
struct V_15 * V_248 ;
V_248 = & V_37 -> V_37 ;
if ( V_37 -> V_157 == FALSE )
return;
V_248 -> V_44 += V_37 -> V_147 ;
V_37 -> V_147 = 0 ;
V_37 -> V_157 = FALSE ;
#ifdef F_47
F_29 ( V_5 , V_60 , V_37 , V_119 ) ;
#endif
if ( V_248 -> V_44 != V_248 -> V_35 ) {
F_50 ( V_5 , V_60 , V_37 ) ;
} else {
V_153 = V_60 -> V_60 . V_64 ;
V_247 = V_248 -> V_44 % V_153 ;
if ( V_247 > 0 ) {
if ( ( ( V_248 -> V_44 & 0x03 ) == 0 ) && ( V_247 < V_153 ) )
F_25 ( V_5 , V_60 -> V_62 , 0 , 0 ) ;
} else {
F_77 ( V_5 , V_60 , V_37 ) ;
}
}
}
static inline void F_80 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 )
{
int V_6 ;
T_1 V_45 ;
T_1 V_155 , V_249 ;
T_1 V_153 ;
T_5 V_100 = V_5 -> V_53 ;
V_45 = V_60 -> V_62 - 1 ;
if ( V_37 -> V_37 . V_44 == V_37 -> V_37 . V_35 ) {
if ( ( V_37 -> V_37 . V_35 % V_60 -> V_60 . V_64 ) && ! V_37 -> V_40 ) {
V_37 -> V_147 = 0 ;
V_37 -> V_157 = FALSE ;
F_72 ( V_60 , V_37 , 0 ) ;
return;
}
}
V_249 = F_1 ( & V_100 -> V_54 [ V_45 ] . V_160 )
& V_250 ;
V_249 >>= 16 ;
for ( V_6 = 0 ; V_6 < V_251 ; V_6 ++ ) {
V_155 = F_1 ( & V_100 -> V_91 [ V_45 ] . V_94 )
& V_252 ;
V_155 >>= 16 ;
if ( V_249 == V_155 )
break;
}
F_6 ( & V_100 -> V_91 [ V_45 ] . V_94 , V_101 ) ;
if ( V_155 != 0 ) {
V_153 = V_60 -> V_60 . V_64 ;
if ( ( V_37 -> V_147 % V_153 ) == 0 )
V_37 -> V_147 -= V_153 * V_155 ;
}
if ( ( V_37 -> V_37 . V_44 % V_60 -> V_60 . V_64 ) > 0 ) {
if ( V_37 -> V_37 . V_44 == V_37 -> V_147 ) {
V_37 -> V_147 = 0 ;
V_37 -> V_157 = FALSE ;
F_72 ( V_60 , V_37 , 0 ) ;
return;
}
}
V_37 -> V_37 . V_44 += V_37 -> V_147 ;
V_37 -> V_147 = 0 ;
V_37 -> V_157 = FALSE ;
F_78 ( V_5 , V_60 , V_37 ) ;
}
static inline void F_81 ( struct V_4 * V_5 , T_1 V_62 )
{
T_1 V_45 ;
T_1 V_42 ;
struct V_113 * V_37 ;
struct V_59 * V_60 = & V_5 -> V_60 [ V_62 ] ;
V_45 = V_62 - 1 ;
V_42 = F_1 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_165 ) ;
F_3 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_165 , ~ ( T_1 ) V_42 ) ;
if ( F_54 ( & V_60 -> V_173 ) )
V_37 = NULL ;
else
V_37 = F_55 ( V_60 -> V_173 . V_174 , struct V_113 , V_173 ) ;
if ( V_37 == NULL ) {
return;
}
if ( V_42 & V_253 ) {
V_42 &= ~ V_254 ;
F_80 ( V_5 , V_60 , V_37 ) ;
}
if ( V_42 & V_254 )
F_78 ( V_5 , V_60 , V_37 ) ;
if ( V_42 & V_255 ) {
V_42 &= ~ V_256 ;
F_79 ( V_5 , V_60 , V_37 ) ;
}
if ( V_42 & V_256 )
F_77 ( V_5 , V_60 , V_37 ) ;
}
static inline void F_82 ( struct V_4 * V_5 , T_1 V_62 )
{
if ( V_62 == 0 )
F_73 ( V_5 ) ;
else
F_81 ( V_5 , V_62 ) ;
}
static void F_83 ( struct V_4 * V_5 )
{
F_5 ( & V_5 -> V_53 -> V_105 , ( V_106 | V_235 ) ) ;
F_3 ( & V_5 -> V_53 -> V_257 , V_258 ) ;
}
static int F_84 ( struct V_4 * V_5 ,
struct V_59 * V_60 ,
int V_42 )
{
struct V_113 * V_37 ;
F_20 ( V_5 , V_60 ) ;
F_22 ( V_5 , V_60 ) ;
if ( F_54 ( & V_60 -> V_173 ) )
return 0 ;
while ( ! F_54 ( & V_60 -> V_173 ) ) {
V_37 = F_55 ( V_60 -> V_173 . V_174 , struct V_113 , V_173 ) ;
F_72 ( V_60 , V_37 , V_42 ) ;
}
return 0 ;
}
static void F_85 ( struct V_4 * V_5 )
{
struct V_59 * V_60 ;
V_5 -> V_117 . V_203 = V_244 ;
F_84 ( V_5 , & V_5 -> V_60 [ 0 ] , - V_259 ) ;
F_86 (ep, &udc->gadget.ep_list, ep.ep_list) {
F_84 ( V_5 , V_60 , - V_259 ) ;
}
}
static int F_87 ( struct V_4 * V_5 , int V_260 )
{
T_1 V_3 ;
if ( ! V_5 ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
if ( V_5 -> V_89 == 0 )
return - V_259 ;
if ( V_260 ) {
if ( V_5 -> V_231 ) {
V_3 = ( F_1 ( & V_5 -> V_53 -> V_185 )
| V_261 ) & ~ ( T_1 ) V_262 ;
F_3 ( & V_5 -> V_53 -> V_185 , V_3 ) ;
}
} else {
V_3 = ( F_1 ( & V_5 -> V_53 -> V_185 ) | V_262 )
& ~ ( T_1 ) V_261 ;
F_3 ( & V_5 -> V_53 -> V_185 , V_3 ) ;
V_5 -> V_117 . V_203 = V_244 ;
}
return 0 ;
}
static void F_75 ( struct V_4 * V_5 , struct V_59 * V_60 )
{
T_5 V_123 = V_5 -> V_53 ;
if ( V_5 -> V_89 == 0 )
return;
if ( V_60 -> V_62 == 0 ) {
F_5 ( & V_123 -> V_105 , V_235 ) ;
} else {
F_23 ( V_5 , V_60 ) ;
F_5 ( & V_123 -> V_54 [ V_60 -> V_62 - 1 ] . V_56 , V_77 ) ;
}
}
static int F_88 ( struct V_4 * V_5 )
{
int V_263 = 0 ;
if ( V_5 -> V_264 )
return 0 ;
#if 0
emxx_open_clockgate(EMXX_CLK_USB1);
emxx_unreset_device(EMXX_RST_USB1);
#endif
F_5 ( & V_5 -> V_53 -> V_265 , ( V_266 | V_267 ) ) ;
F_89 ( V_268 ) ;
F_6 ( & V_5 -> V_53 -> V_265 , V_266 ) ;
F_24 ( V_269 ) ;
F_6 ( & V_5 -> V_53 -> V_265 , V_267 ) ;
F_3 ( & V_5 -> V_53 -> V_270 , V_271 ) ;
#if 0
if ((system_rev & EMXX_REV_MASK) == EMXX_REV_ES1) {
_nbu2ss_bitset(&udc->p_regs->AHBMCTR, BURST_TYPE);
_nbu2ss_bitclr(&udc->p_regs->AHBMCTR, HTRANS_MODE);
} else
#endif
F_3 ( & V_5 -> V_53 -> V_272 ,
V_273 | V_274 | V_275 ) ;
while ( ! ( F_1 ( & V_5 -> V_53 -> V_265 ) & V_276 ) ) {
V_263 ++ ;
F_89 ( 1 ) ;
if ( V_263 == V_251 ) {
F_9 ( L_14 ) ;
return - V_63 ;
}
} ;
#if 0
if ((system_rev & EMXX_REV_MASK) < EMXX_REV_ES3)
#endif
F_5 ( & V_5 -> V_53 -> V_277 , V_278 ) ;
F_5 ( & V_5 -> V_53 -> V_185 , ( V_279 | V_280 ) ) ;
F_83 ( V_5 ) ;
F_5 ( & V_5 -> V_53 -> V_65 , V_281 ) ;
V_5 -> V_264 = TRUE ;
return 0 ;
}
static void F_90 ( struct V_4 * V_5 )
{
F_5 ( & V_5 -> V_53 -> V_265 , V_267 ) ;
F_6 ( & V_5 -> V_53 -> V_265 , V_267 ) ;
}
static void F_91 ( struct V_4 * V_5 )
{
if ( V_5 -> V_264 ) {
V_5 -> V_264 = FALSE ;
F_90 ( V_5 ) ;
F_5 ( & V_5 -> V_53 -> V_265 , ( V_266 | V_267 ) ) ;
}
#if 0
emxx_reset_device(EMXX_RST_USB1);
emxx_close_clockgate(EMXX_CLK_USB1);
#endif
}
static inline void F_92 ( struct V_4 * V_5 )
{
int V_127 ;
T_1 V_3 ;
F_24 ( V_282 ) ;
V_3 = F_93 ( V_283 ) ;
if ( V_3 == 0 ) {
V_5 -> V_284 = 0 ;
F_90 ( V_5 ) ;
F_8 ( L_15 ) ;
if ( V_5 -> V_89 == 1 ) {
V_5 -> V_89 = 0 ;
if ( V_5 -> V_285 ) {
V_5 -> V_285 = 0 ;
}
V_5 -> V_220 = V_286 ;
F_85 ( V_5 ) ;
if ( V_5 -> V_231 ) {
F_10 ( & V_5 -> V_9 ) ;
V_5 -> V_231 -> V_287 ( & V_5 -> V_117 ) ;
F_13 ( & V_5 -> V_9 ) ;
}
F_91 ( V_5 ) ;
}
} else {
F_24 ( 5 ) ;
V_3 = F_93 ( V_283 ) ;
if ( V_3 == 0 )
return;
F_8 ( L_16 ) ;
if ( V_5 -> V_284 )
return;
if ( V_5 -> V_89 == 0 ) {
V_5 -> V_89 = 1 ;
V_5 -> V_220 = V_288 ;
V_127 = F_88 ( V_5 ) ;
if ( V_127 < 0 ) {
F_91 ( V_5 ) ;
V_5 -> V_89 = 0 ;
return;
}
F_87 ( V_5 , 1 ) ;
#ifdef F_94
F_7 ( V_5 ) ;
#endif
} else {
if ( V_5 -> V_220 == V_288 )
F_87 ( V_5 , 1 ) ;
}
}
}
static inline void F_95 ( struct V_4 * V_5 )
{
V_5 -> V_220 = V_289 ;
V_5 -> V_192 = 0 ;
F_85 ( V_5 ) ;
V_5 -> V_169 = V_233 ;
}
static inline void F_96 ( struct V_4 * V_5 )
{
if ( V_5 -> V_285 == 1 ) {
V_5 -> V_285 = 0 ;
if ( V_5 -> V_231 && V_5 -> V_231 -> V_290 ) {
F_10 ( & V_5 -> V_9 ) ;
V_5 -> V_231 -> V_290 ( & V_5 -> V_117 ) ;
F_13 ( & V_5 -> V_9 ) ;
}
}
}
static inline void F_97 ( struct V_4 * V_5 )
{
T_1 V_3 ;
if ( V_5 -> V_285 == 0 ) {
V_3 = F_93 ( V_283 ) ;
if ( V_3 == 0 )
return;
V_5 -> V_285 = 1 ;
if ( V_5 -> V_231 && V_5 -> V_231 -> V_291 ) {
F_10 ( & V_5 -> V_9 ) ;
V_5 -> V_231 -> V_291 ( & V_5 -> V_117 ) ;
F_13 ( & V_5 -> V_9 ) ;
}
F_5 ( & V_5 -> V_53 -> V_185 , V_292 ) ;
}
}
static T_7 F_98 ( int V_293 , void * V_294 )
{
struct V_4 * V_5 = (struct V_4 * ) V_294 ;
F_13 ( & V_5 -> V_9 ) ;
F_92 ( V_5 ) ;
F_10 ( & V_5 -> V_9 ) ;
return V_295 ;
}
static T_7 F_99 ( int V_293 , void * V_294 )
{
T_2 V_296 = 0 ;
T_1 V_42 ;
T_1 V_62 , V_297 ;
struct V_4 * V_5 = (struct V_4 * ) V_294 ;
T_5 V_100 = V_5 -> V_53 ;
if ( F_93 ( V_283 ) == 0 ) {
F_3 ( & V_100 -> V_298 , ~ V_299 ) ;
F_3 ( & V_100 -> V_65 , 0 ) ;
return V_295 ;
}
F_13 ( & V_5 -> V_9 ) ;
for (; ; ) {
if ( F_93 ( V_283 ) == 0 ) {
F_3 ( & V_100 -> V_298 , ~ V_299 ) ;
F_3 ( & V_100 -> V_65 , 0 ) ;
V_42 = 0 ;
} else
V_42 = F_1 ( & V_100 -> V_298 ) ;
if ( V_42 == 0 )
break;
F_3 ( & V_100 -> V_298 , ~ ( V_42 & V_299 ) ) ;
if ( V_42 & V_300 ) {
F_95 ( V_5 ) ;
}
if ( V_42 & V_301 ) {
F_96 ( V_5 ) ;
}
if ( V_42 & V_302 ) {
V_296 = 1 ;
}
if ( V_42 & V_303 ) {
V_297 = V_42 >> 8 ;
for ( V_62 = 0 ; V_62 < V_52 ; V_62 ++ ) {
if ( 0x01 & V_297 )
F_82 ( V_5 , V_62 ) ;
V_297 >>= 1 ;
if ( V_297 == 0 )
break;
}
}
}
if ( V_296 )
F_97 ( V_5 ) ;
F_10 ( & V_5 -> V_9 ) ;
return V_295 ;
}
static int F_100 (
struct V_13 * V_14 ,
const struct V_304 * V_305 )
{
T_2 V_66 ;
unsigned long V_306 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
if ( ( V_14 == NULL ) || ( V_305 == NULL ) ) {
F_9 ( L_17 , V_8 ) ;
return - V_63 ;
}
V_60 = F_101 ( V_14 , struct V_59 , V_60 ) ;
if ( ( V_60 == NULL ) || ( V_60 -> V_5 == NULL ) ) {
F_9 ( L_18 , V_8 ) ;
return - V_63 ;
}
V_66 = V_305 -> V_307 & V_308 ;
if ( ( V_66 == V_309 )
|| ( V_66 == V_72 ) ) {
F_9 ( L_19 , V_8 ) ;
return - V_63 ;
}
V_5 = V_60 -> V_5 ;
if ( V_5 -> V_89 == 0 )
return - V_259 ;
if ( ( V_5 -> V_231 == NULL )
|| ( V_5 -> V_117 . V_203 == V_244 ) ) {
F_9 ( L_20 , V_8 ) ;
return - V_259 ;
}
F_102 ( & V_5 -> V_9 , V_306 ) ;
V_60 -> V_305 = V_305 ;
V_60 -> V_62 = V_305 -> V_310 & V_180 ;
V_60 -> V_74 = V_305 -> V_310 & V_195 ;
V_60 -> V_66 = V_66 ;
V_60 -> V_311 = 0 ;
V_60 -> V_181 = FALSE ;
V_60 -> V_182 = FALSE ;
V_60 -> V_60 . V_64 = F_103 ( V_305 -> V_312 ) ;
F_21 ( V_5 , V_60 ) ;
F_18 ( V_5 , V_60 ) ;
F_104 ( & V_5 -> V_9 , V_306 ) ;
return 0 ;
}
static int F_105 ( struct V_13 * V_14 )
{
struct V_59 * V_60 ;
struct V_4 * V_5 ;
unsigned long V_306 ;
if ( V_14 == NULL ) {
F_9 ( L_17 , V_8 ) ;
return - V_63 ;
}
V_60 = F_101 ( V_14 , struct V_59 , V_60 ) ;
if ( ( V_60 == NULL ) || ( V_60 -> V_5 == NULL ) ) {
F_9 ( L_18 , V_8 ) ;
return - V_63 ;
}
V_5 = V_60 -> V_5 ;
if ( V_5 -> V_89 == 0 )
return - V_259 ;
F_102 ( & V_5 -> V_9 , V_306 ) ;
F_84 ( V_5 , V_60 , - V_43 ) ;
F_104 ( & V_5 -> V_9 , V_306 ) ;
return 0 ;
}
static struct V_15 * F_106 (
struct V_13 * V_60 ,
T_8 V_313 )
{
struct V_113 * V_37 ;
V_37 = F_107 ( sizeof( * V_37 ) , V_313 ) ;
if ( ! V_37 )
return 0 ;
#ifdef F_47
V_37 -> V_37 . V_39 = V_114 ;
#endif
F_108 ( & V_37 -> V_173 ) ;
return & V_37 -> V_37 ;
}
static void F_109 (
struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_113 * V_37 ;
if ( V_16 != NULL ) {
V_37 = F_101 ( V_16 , struct V_113 , V_37 ) ;
if ( V_37 != NULL )
F_110 ( V_37 ) ;
}
}
static int F_111 (
struct V_13 * V_14 ,
struct V_15 * V_16 ,
T_8 V_313 )
{
struct V_113 * V_37 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
unsigned long V_306 ;
bool V_168 ;
int V_146 = - V_63 ;
if ( ( V_14 == NULL ) || ( V_16 == NULL ) ) {
if ( V_14 == NULL )
F_9 ( L_21 , V_8 ) ;
if ( V_16 == NULL )
F_9 ( L_22 , V_8 ) ;
return - V_63 ;
}
V_37 = F_101 ( V_16 , struct V_113 , V_37 ) ;
if ( F_112
( ! V_16 -> V_41 || ! V_16 -> V_38
|| ! F_54 ( & V_37 -> V_173 ) ) ) {
if ( ! V_16 -> V_41 )
F_9 ( L_23 , V_8 ) ;
if ( ! V_16 -> V_38 )
F_9 ( L_24 , V_8 ) ;
if ( ! F_54 ( & V_37 -> V_173 ) )
F_9 ( L_25 , V_8 ) ;
return - V_63 ;
}
V_60 = F_101 ( V_14 , struct V_59 , V_60 ) ;
V_5 = V_60 -> V_5 ;
if ( V_5 -> V_89 == 0 ) {
F_8 ( L_26 ) ;
return - V_259 ;
}
if ( F_112 ( ! V_5 -> V_231 ) ) {
F_9 ( L_27 , V_8 , V_5 -> V_231 ) ;
return - V_259 ;
}
F_102 ( & V_5 -> V_9 , V_306 ) ;
#ifdef F_47
if ( ( T_1 ) V_37 -> V_37 . V_38 & 0x3 )
V_37 -> V_115 = TRUE ;
else
V_37 -> V_115 = FALSE ;
if ( V_37 -> V_115 ) {
if ( V_60 -> V_125 == NULL )
V_60 -> V_125 = ( T_2 * ) F_113 (
NULL , V_314 ,
& V_60 -> V_116 , V_315 | V_316 ) ;
if ( V_60 -> V_62 > 0 ) {
if ( V_60 -> V_74 == V_119 )
memcpy ( V_60 -> V_125 , V_37 -> V_37 . V_38 ,
V_37 -> V_37 . V_35 ) ;
}
}
if ( ( V_60 -> V_62 > 0 ) && ( V_60 -> V_74 == V_75 ) &&
( V_37 -> V_37 . V_39 != 0 ) )
F_26 ( V_5 , V_60 , V_37 , V_75 ) ;
#endif
V_16 -> V_42 = - V_43 ;
V_16 -> V_44 = 0 ;
V_168 = F_54 ( & V_60 -> V_173 ) ;
F_114 ( & V_37 -> V_173 , & V_60 -> V_173 ) ;
if ( ( V_168 != FALSE ) && ( V_60 -> V_182 == FALSE ) ) {
V_146 = F_52 ( V_5 , V_60 , V_37 , FALSE ) ;
if ( V_146 < 0 ) {
F_9 ( L_28 , V_8 , V_146 ) ;
F_115 ( & V_37 -> V_173 ) ;
} else if ( ( V_60 -> V_62 > 0 ) && ( V_60 -> V_74 == V_75 ) ) {
#ifdef F_47
if ( V_37 -> V_37 . V_35 < 4 &&
V_37 -> V_37 . V_35 == V_37 -> V_37 . V_44 )
#else
if ( V_37 -> V_37 . V_35 == V_37 -> V_37 . V_44 )
#endif
F_72 ( V_60 , V_37 , V_146 ) ;
}
}
F_104 ( & V_5 -> V_9 , V_306 ) ;
return 0 ;
}
static int F_116 (
struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_113 * V_37 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
unsigned long V_306 ;
if ( ( V_14 == NULL ) || ( V_16 == NULL ) ) {
return - V_63 ;
}
V_60 = F_101 ( V_14 , struct V_59 , V_60 ) ;
if ( ! V_60 ) {
F_9 ( L_29 , V_8 ) ;
return - V_63 ;
}
V_5 = V_60 -> V_5 ;
if ( V_5 == NULL )
return - V_63 ;
F_102 ( & V_5 -> V_9 , V_306 ) ;
F_86 (req, &ep->queue, queue) {
if ( & V_37 -> V_37 == V_16 )
break;
}
if ( & V_37 -> V_37 != V_16 ) {
F_104 ( & V_5 -> V_9 , V_306 ) ;
F_117 ( L_30 , V_8 ) ;
return - V_63 ;
}
F_72 ( V_60 , V_37 , - V_246 ) ;
F_104 ( & V_5 -> V_9 , V_306 ) ;
return 0 ;
}
static int F_118 ( struct V_13 * V_14 , int V_317 )
{
T_2 V_175 ;
unsigned long V_306 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
if ( ! V_14 ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_60 = F_101 ( V_14 , struct V_59 , V_60 ) ;
if ( ! V_60 ) {
F_9 ( L_31 , V_8 ) ;
return - V_63 ;
}
V_5 = V_60 -> V_5 ;
if ( ! V_5 ) {
F_9 ( L_32 , V_8 ) ;
return - V_63 ;
}
F_102 ( & V_5 -> V_9 , V_306 ) ;
V_175 = V_60 -> V_62 | V_60 -> V_74 ;
if ( V_317 == 0 ) {
F_56 ( V_5 , V_175 , V_317 ) ;
V_60 -> V_182 = FALSE ;
} else {
if ( F_54 ( & V_60 -> V_173 ) )
F_61 ( V_5 , V_60 ) ;
else
V_60 -> V_182 = TRUE ;
}
if ( V_317 == 0 )
V_60 -> V_311 = 0 ;
F_104 ( & V_5 -> V_9 , V_306 ) ;
return 0 ;
}
static int F_119 ( struct V_13 * V_14 )
{
return F_118 ( V_14 , 1 ) ;
}
static int F_120 ( struct V_13 * V_14 )
{
T_1 V_47 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
unsigned long V_306 ;
T_5 V_100 ;
if ( ! V_14 ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_60 = F_101 ( V_14 , struct V_59 , V_60 ) ;
if ( ! V_60 ) {
F_9 ( L_31 , V_8 ) ;
return - V_63 ;
}
V_5 = V_60 -> V_5 ;
if ( ! V_5 ) {
F_9 ( L_33 , V_8 ) ;
return - V_63 ;
}
V_100 = V_5 -> V_53 ;
V_47 = F_93 ( V_283 ) ;
if ( V_47 == 0 )
return - V_63 ;
F_102 ( & V_5 -> V_9 , V_306 ) ;
if ( V_60 -> V_62 == 0 ) {
V_47 = F_1 ( & V_100 -> V_150 ) & V_151 ;
} else {
V_47 = F_1 ( & V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_160 )
& V_164 ;
}
F_104 ( & V_5 -> V_9 , V_306 ) ;
return 0 ;
}
static void F_121 ( struct V_13 * V_14 )
{
T_1 V_47 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
unsigned long V_306 ;
if ( ! V_14 ) {
F_9 ( L_13 , V_8 ) ;
return;
}
V_60 = F_101 ( V_14 , struct V_59 , V_60 ) ;
if ( ! V_14 ) {
F_9 ( L_31 , V_8 ) ;
return;
}
V_5 = V_60 -> V_5 ;
if ( ! V_5 ) {
F_9 ( L_33 , V_8 ) ;
return;
}
V_47 = F_93 ( V_283 ) ;
if ( V_47 == 0 )
return;
F_102 ( & V_5 -> V_9 , V_306 ) ;
F_75 ( V_5 , V_60 ) ;
F_104 ( & V_5 -> V_9 , V_306 ) ;
}
static int F_122 ( struct V_318 * V_319 )
{
T_1 V_47 ;
struct V_4 * V_5 ;
if ( V_319 == NULL ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_5 = F_101 ( V_319 , struct V_4 , V_117 ) ;
if ( V_5 == NULL ) {
F_9 ( L_34 , V_8 ) ;
return - V_63 ;
}
V_47 = F_93 ( V_283 ) ;
if ( V_47 == 0 )
return - V_63 ;
V_47 = F_1 ( & V_5 -> V_53 -> V_216 ) & V_320 ;
return V_47 ;
}
static int F_123 ( struct V_318 * V_319 )
{
int V_6 ;
T_1 V_47 ;
struct V_4 * V_5 ;
if ( V_319 == NULL ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_5 = F_101 ( V_319 , struct V_4 , V_117 ) ;
if ( V_5 == NULL ) {
F_9 ( L_34 , V_8 ) ;
return - V_63 ;
}
V_47 = F_93 ( V_283 ) ;
if ( V_47 == 0 ) {
F_124 ( L_35 , V_47 ) ;
return - V_63 ;
}
F_5 ( & V_5 -> V_53 -> V_265 , V_321 ) ;
for ( V_6 = 0 ; V_6 < V_251 ; V_6 ++ ) {
V_47 = F_1 ( & V_5 -> V_53 -> V_265 ) ;
if ( V_47 & V_276 )
break;
}
F_6 ( & V_5 -> V_53 -> V_265 , V_321 ) ;
return 0 ;
}
static int F_125 ( struct V_318 * V_319 ,
int V_322 )
{
struct V_4 * V_5 ;
unsigned long V_306 ;
if ( V_319 == NULL ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_5 = F_101 ( V_319 , struct V_4 , V_117 ) ;
F_102 ( & V_5 -> V_9 , V_306 ) ;
V_5 -> V_213 = ( V_322 != 0 ) ;
F_104 ( & V_5 -> V_9 , V_306 ) ;
return 0 ;
}
static int F_126 ( struct V_318 * V_319 , int V_323 )
{
return 0 ;
}
static int F_127 ( struct V_318 * V_319 , unsigned V_324 )
{
struct V_4 * V_5 ;
unsigned long V_306 ;
if ( V_319 == NULL ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_5 = F_101 ( V_319 , struct V_4 , V_117 ) ;
F_102 ( & V_5 -> V_9 , V_306 ) ;
V_5 -> V_324 = V_324 ;
F_104 ( & V_5 -> V_9 , V_306 ) ;
return 0 ;
}
static int F_128 ( struct V_318 * V_319 , int V_260 )
{
struct V_4 * V_5 ;
unsigned long V_306 ;
if ( V_319 == NULL ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_5 = F_101 ( V_319 , struct V_4 , V_117 ) ;
if ( V_5 -> V_231 == NULL ) {
F_124 ( L_36 , V_8 ) ;
return - V_63 ;
}
if ( V_5 -> V_89 == 0 )
return - V_259 ;
F_102 ( & V_5 -> V_9 , V_306 ) ;
F_87 ( V_5 , V_260 ) ;
F_104 ( & V_5 -> V_9 , V_306 ) ;
return 0 ;
}
static int F_129 (
struct V_318 * V_319 ,
unsigned V_325 ,
unsigned long V_326 )
{
return 0 ;
}
static void T_9 F_130 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
const char * V_327 )
{
V_60 -> V_5 = V_5 ;
V_60 -> V_305 = NULL ;
V_60 -> V_60 . V_328 = NULL ;
V_60 -> V_60 . V_327 = V_327 ;
V_60 -> V_60 . V_329 = & V_330 ;
if ( isdigit ( V_327 [ 2 ] ) ) {
long V_45 ;
int V_331 ;
char V_332 [ 2 ] ;
V_332 [ 0 ] = V_327 [ 2 ] ;
V_332 [ 1 ] = '\0' ;
V_331 = F_131 ( V_332 , 16 , & V_45 ) ;
if ( V_45 == 0 )
V_60 -> V_60 . V_64 = V_137 ;
else
V_60 -> V_60 . V_64 = V_333 ;
} else {
V_60 -> V_60 . V_64 = V_333 ;
}
F_114 ( & V_60 -> V_60 . V_334 , & V_5 -> V_117 . V_334 ) ;
F_108 ( & V_60 -> V_173 ) ;
}
static void T_9 F_132 ( struct V_4 * V_5 )
{
int V_6 ;
F_108 ( & V_5 -> V_117 . V_334 ) ;
V_5 -> V_117 . V_335 = & V_5 -> V_60 [ 0 ] . V_60 ;
for ( V_6 = 0 ; V_6 < V_52 ; V_6 ++ )
F_130 ( V_5 , & V_5 -> V_60 [ V_6 ] , V_336 [ V_6 ] ) ;
F_74 ( & V_5 -> V_60 [ 0 ] . V_60 . V_334 ) ;
}
static int T_9 F_133 (
struct V_337 * V_338 ,
struct V_4 * V_5 )
{
F_134 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = & V_338 -> V_10 ;
V_5 -> V_213 = 1 ;
V_5 -> V_220 = V_286 ;
V_5 -> V_338 = V_338 ;
V_5 -> V_324 = 0 ;
V_5 -> V_338 -> V_10 . V_339 = F_135 ( 32 ) ;
F_132 ( V_5 ) ;
V_5 -> V_117 . V_329 = & V_340 ;
V_5 -> V_117 . V_335 = & V_5 -> V_60 [ 0 ] . V_60 ;
V_5 -> V_117 . V_203 = V_244 ;
V_5 -> V_117 . V_327 = V_341 ;
F_136 ( & V_5 -> V_117 . V_10 ) ;
F_137 ( & V_5 -> V_117 . V_10 , L_37 ) ;
V_5 -> V_117 . V_10 . V_118 = & V_338 -> V_10 ;
V_5 -> V_117 . V_10 . V_342 = V_338 -> V_10 . V_342 ;
return 0 ;
}
static int F_138 ( struct V_337 * V_338 )
{
int V_42 = - V_343 ;
struct V_4 * V_5 ;
struct V_344 * V_345 ;
int V_293 ;
void T_10 * V_346 ;
V_5 = & V_347 ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
F_139 ( V_338 , V_5 ) ;
V_345 = F_140 ( V_338 , V_348 , 0 ) ;
V_346 = F_141 ( & V_338 -> V_10 , V_345 ) ;
if ( F_142 ( V_346 ) )
return F_143 ( V_346 ) ;
V_293 = F_144 ( V_338 , 0 ) ;
if ( V_293 < 0 ) {
F_145 ( & V_338 -> V_10 , L_38 ) ;
return V_293 ;
}
V_42 = F_146 ( & V_338 -> V_10 , V_293 , F_99 ,
0 , V_341 , V_5 ) ;
V_5 -> V_53 = ( T_5 ) V_346 ;
if ( V_42 != 0 ) {
F_9 ( L_39 ) ;
goto V_349;
}
V_42 = F_133 ( V_338 , V_5 ) ;
if ( V_42 < 0 ) {
goto V_349;
}
F_147 ( V_350 , V_351 ) ;
V_42 = F_148 ( V_350 ,
F_98 ,
V_352 ,
V_341 ,
V_5 ) ;
if ( V_42 != 0 ) {
F_9 ( L_40 ) ;
goto V_349;
}
return V_42 ;
V_349:
return V_42 ;
}
static void F_149 ( struct V_337 * V_338 )
{
struct V_4 * V_5 ;
V_5 = F_150 ( V_338 ) ;
if ( V_5 == NULL )
return;
F_91 ( V_5 ) ;
}
static int T_11 F_151 ( struct V_337 * V_338 )
{
struct V_4 * V_5 ;
struct V_59 * V_60 ;
int V_6 ;
V_5 = & V_347 ;
for ( V_6 = 0 ; V_6 < V_52 ; V_6 ++ ) {
V_60 = & V_5 -> V_60 [ V_6 ] ;
if ( V_60 -> V_125 )
F_152 ( NULL , V_314 ,
( void * ) V_60 -> V_125 , V_60 -> V_116 ) ;
}
F_153 ( V_350 , V_5 ) ;
return 0 ;
}
static int F_154 ( struct V_337 * V_338 , T_12 V_353 )
{
struct V_4 * V_5 ;
V_5 = F_150 ( V_338 ) ;
if ( V_5 == NULL )
return 0 ;
if ( V_5 -> V_89 ) {
V_5 -> V_89 = 0 ;
V_5 -> V_220 = V_286 ;
V_5 -> V_284 = 1 ;
if ( V_5 -> V_285 ) {
V_5 -> V_285 = 0 ;
F_90 ( V_5 ) ;
}
F_85 ( V_5 ) ;
}
F_91 ( V_5 ) ;
return 0 ;
}
static int F_155 ( struct V_337 * V_338 )
{
T_1 V_47 ;
struct V_4 * V_5 ;
V_5 = F_150 ( V_338 ) ;
if ( V_5 == NULL )
return 0 ;
V_47 = F_93 ( V_283 ) ;
if ( V_47 ) {
V_5 -> V_89 = 1 ;
V_5 -> V_220 = V_288 ;
F_88 ( V_5 ) ;
F_87 ( V_5 , 1 ) ;
}
V_5 -> V_284 = 0 ;
return 0 ;
}
