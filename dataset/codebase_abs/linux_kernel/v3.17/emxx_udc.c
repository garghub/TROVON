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
F_11 ( V_10 L_3 ) ;
for ( V_6 = 0x0 ; V_6 < V_11 ; V_6 += 16 ) {
V_7 = F_1 (
( T_1 * ) F_12 ( V_12 + V_6 ) ) ;
F_11 ( V_10 L_4 , V_6 , ( int ) V_7 ) ;
V_7 = F_1 (
( T_1 * ) F_12 ( V_12 + V_6 + 4 ) ) ;
F_11 ( V_10 L_5 , ( int ) V_7 ) ;
V_7 = F_1 (
( T_1 * ) F_12 ( V_12 + V_6 + 8 ) ) ;
F_11 ( V_10 L_5 , ( int ) V_7 ) ;
V_7 = F_1 (
( T_1 * ) F_12 ( V_12 + V_6 + 12 ) ) ;
F_11 ( V_10 L_6 , ( int ) V_7 ) ;
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
return;
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
V_5 -> V_117 . V_118 . V_119 ,
V_37 -> V_37 . V_38 ,
V_37 -> V_37 . V_35 ,
( V_74 == V_120 )
? V_121 : V_122 ) ;
}
V_37 -> V_123 = 1 ;
} else {
if ( ! V_37 -> V_115 )
F_28 (
V_5 -> V_117 . V_118 . V_119 ,
V_37 -> V_37 . V_39 ,
V_37 -> V_37 . V_35 ,
( V_74 == V_120 )
? V_121 : V_122 ) ;
V_37 -> V_123 = 0 ;
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
T_2 * V_124 ;
T_1 V_125 = 0 ;
if ( V_74 == V_75 ) {
V_125 = V_37 -> V_37 . V_44 % 4 ;
if ( V_125 ) {
V_124 = V_37 -> V_37 . V_38 ;
V_124 += ( V_37 -> V_37 . V_44 - V_125 ) ;
memcpy ( V_47 , V_124 , V_125 ) ;
}
}
if ( V_37 -> V_123 ) {
if ( V_37 -> V_115 ) {
if ( V_74 == V_75 )
memcpy ( V_37 -> V_37 . V_38 , V_60 -> V_126 ,
V_37 -> V_37 . V_44 & 0xfffffffc ) ;
} else
F_30 ( V_5 -> V_117 . V_118 . V_119 ,
V_37 -> V_37 . V_39 , V_37 -> V_37 . V_35 ,
( V_74 == V_120 )
? V_121
: V_122 ) ;
V_37 -> V_37 . V_39 = V_114 ;
V_37 -> V_123 = 0 ;
} else {
if ( ! V_37 -> V_115 )
F_31 ( V_5 -> V_117 . V_118 . V_119 ,
V_37 -> V_37 . V_39 , V_37 -> V_37 . V_35 ,
( V_74 == V_120 )
? V_121
: V_122 ) ;
}
if ( V_125 ) {
V_124 = V_37 -> V_37 . V_38 ;
V_124 += ( V_37 -> V_37 . V_44 - V_125 ) ;
memcpy ( V_124 , V_47 , V_125 ) ;
}
}
static int F_32 ( struct V_4 * V_5 , T_2 * V_127 , T_1 V_35 )
{
T_1 V_6 ;
int V_128 = 0 ;
T_1 V_129 = 0 ;
T_6 * V_130 = ( T_6 * ) V_127 ;
V_129 = V_35 / sizeof( T_1 ) ;
if ( V_129 ) {
for ( V_6 = 0 ; V_6 < V_129 ; V_6 ++ ) {
V_130 -> V_131 = F_1 ( & V_5 -> V_53 -> V_132 ) ;
V_130 ++ ;
}
V_128 = V_129 * sizeof( T_1 ) ;
}
return V_128 ;
}
static int F_33 ( struct V_4 * V_5 , T_2 * V_127 , T_1 V_35 )
{
T_1 V_6 ;
T_1 V_133 = 0 ;
T_6 V_134 ;
T_6 * V_130 = ( T_6 * ) V_127 ;
if ( ( 0 < V_35 ) && ( V_35 < sizeof( T_1 ) ) ) {
V_134 . V_131 = F_1 ( & V_5 -> V_53 -> V_132 ) ;
for ( V_6 = 0 ; V_6 < V_35 ; V_6 ++ )
V_130 -> V_135 . V_136 [ V_6 ] = V_134 . V_135 . V_136 [ V_6 ] ;
V_133 += V_35 ;
}
return V_133 ;
}
static int F_34 ( struct V_4 * V_5 , T_2 * V_127 , T_1 V_35 )
{
T_1 V_6 ;
T_1 V_137 = V_138 ;
T_1 V_129 = 0 ;
T_1 V_139 = 0 ;
T_6 * V_130 = ( T_6 * ) V_127 ;
if ( V_137 < V_35 )
V_129 = V_137 / sizeof( T_1 ) ;
else
V_129 = V_35 / sizeof( T_1 ) ;
for ( V_6 = 0 ; V_6 < V_129 ; V_6 ++ ) {
F_3 ( & V_5 -> V_53 -> V_107 , V_130 -> V_131 ) ;
V_130 ++ ;
V_139 += sizeof( T_1 ) ;
}
return V_139 ;
}
static int F_35 ( struct V_4 * V_5 , T_2 * V_127 , T_1 V_140 )
{
T_1 V_6 ;
T_6 V_134 ;
T_6 * V_130 = ( T_6 * ) V_127 ;
if ( ( 0 < V_140 ) && ( V_140 < sizeof( T_1 ) ) ) {
for ( V_6 = 0 ; V_6 < V_140 ; V_6 ++ )
V_134 . V_135 . V_136 [ V_6 ] = V_130 -> V_135 . V_136 [ V_6 ] ;
F_25 ( V_5 , 0 , V_134 . V_131 , V_140 ) ;
return V_140 ;
}
return 0 ;
}
static int F_36 ( struct V_4 * V_5 , bool V_141 )
{
T_1 V_47 ;
V_47 = F_1 ( & V_5 -> V_53 -> V_105 ) ;
V_47 &= ~ ( T_1 ) V_142 ;
if ( V_141 )
V_47 |= ( V_143 | V_144 | V_109 ) ;
else
V_47 |= ( V_143 | V_109 ) ;
F_3 ( & V_5 -> V_53 -> V_105 , V_47 ) ;
return 0 ;
}
static int F_37 ( struct V_4 * V_5 , bool V_141 )
{
T_1 V_47 ;
V_47 = F_1 ( & V_5 -> V_53 -> V_105 ) ;
V_47 &= ~ ( T_1 ) V_145 ;
if ( V_141 )
V_47 |= V_144 ;
F_3 ( & V_5 -> V_53 -> V_105 , V_47 ) ;
return 0 ;
}
static int F_38 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37
)
{
T_2 * V_146 ;
T_1 V_47 ;
T_1 V_140 = 0 ;
int V_147 = 0 ;
if ( V_37 -> V_37 . V_44 == V_37 -> V_37 . V_35 ) {
if ( ( V_37 -> V_37 . V_44 % V_138 ) == 0 ) {
if ( V_37 -> V_40 ) {
V_37 -> V_40 = 0 ;
F_36 ( V_5 , FALSE ) ;
return 1 ;
}
}
return 0 ;
}
V_47 = F_1 ( & V_5 -> V_53 -> V_105 ) ;
V_47 |= V_143 ;
V_47 &= ~ ( T_1 ) V_142 ;
F_3 ( & V_5 -> V_53 -> V_105 , V_47 ) ;
V_140 = V_37 -> V_37 . V_35 - V_37 -> V_37 . V_44 ;
V_146 = ( T_2 * ) V_37 -> V_37 . V_38 ;
V_146 += V_37 -> V_37 . V_44 ;
V_147 = F_34 ( V_5 , V_146 , V_140 ) ;
V_37 -> V_148 = V_147 ;
V_140 -= V_147 ;
if ( V_140 == 0 ) {
F_36 ( V_5 , FALSE ) ;
return V_147 ;
}
if ( ( V_140 < sizeof( T_1 ) ) && ( V_147 != V_138 ) ) {
V_146 += V_147 ;
V_147 += F_35 ( V_5 , V_146 , V_140 ) ;
V_37 -> V_148 = V_147 ;
}
return V_147 ;
}
static int F_39 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37
)
{
T_2 * V_146 ;
T_1 V_140 ;
T_1 V_149 ;
int V_147 = 0 ;
int V_150 ;
V_149 = F_1 ( & V_5 -> V_53 -> V_151 ) & V_152 ;
if ( V_149 != 0 ) {
V_150 = 0 ;
V_140 = V_37 -> V_37 . V_35 - V_37 -> V_37 . V_44 ;
V_146 = ( T_2 * ) V_37 -> V_37 . V_38 ;
V_146 += V_37 -> V_37 . V_44 ;
V_147 = F_32 ( V_5 , V_146
, F_40 ( V_140 , V_149 ) ) ;
if ( V_147 < 0 )
return V_147 ;
V_37 -> V_37 . V_44 += V_147 ;
V_149 -= V_147 ;
if ( ( 0 < V_149 ) && ( V_149 < sizeof( T_1 ) ) ) {
V_146 += V_147 ;
V_140 -= V_147 ;
V_147 = F_33 ( V_5 , V_146
, F_40 ( V_140 , V_149 ) ) ;
V_37 -> V_37 . V_44 += V_147 ;
}
} else {
V_150 = 1 ;
}
if ( V_37 -> V_37 . V_44 == V_37 -> V_37 . V_35 ) {
if ( ( V_37 -> V_37 . V_44 % V_138 ) == 0 ) {
if ( V_37 -> V_40 ) {
V_37 -> V_40 = 0 ;
F_37 ( V_5 , FALSE ) ;
return 1 ;
}
}
return 0 ;
}
if ( ( V_37 -> V_37 . V_44 % V_138 ) != 0 )
return 0 ;
if ( V_37 -> V_37 . V_44 > V_37 -> V_37 . V_35 ) {
F_9 ( L_7 ) ;
return - V_153 ;
}
if ( V_150 != 0 ) {
V_140 = F_1 ( & V_5 -> V_53 -> V_105 ) ;
if ( V_140 & V_145 ) {
F_6 ( & V_5 -> V_53 -> V_105 , V_145 ) ;
}
V_147 = 1 ;
}
return V_147 ;
}
static int F_41 (
struct V_4 * V_5 ,
struct V_113 * V_37 ,
T_1 V_45 ,
T_1 V_35
)
{
T_2 * V_146 ;
T_1 V_154 ;
T_1 V_155 ;
T_1 V_156 ;
T_1 V_157 = 1 ;
T_1 V_47 ;
int V_147 = - V_63 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_37 -> V_158 )
return 1 ;
V_37 -> V_158 = TRUE ;
V_146 = ( T_2 * ) V_37 -> V_37 . V_39 ;
V_146 += V_37 -> V_37 . V_44 ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_159 , ( T_1 ) V_146 ) ;
V_154 = F_1 ( & V_100 -> V_54 [ V_45 ] . V_55 ) & V_58 ;
V_156 = ( V_35 / V_154 ) ;
V_155 = ( V_35 % V_154 ) & ~ ( T_1 ) 0x03 ;
if ( V_160 < V_156 ) {
V_156 = V_160 ;
V_155 = 0 ;
} else if ( 0 != V_155 ) {
if ( 0 == V_156 )
V_157 = 0 ;
V_156 ++ ;
}
V_47 = V_154 | ( V_155 << 16 ) ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_92 , V_47 ) ;
V_47 = ( ( V_156 & 0xff ) << 16 ) | V_93 | V_101 ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_94 , V_47 ) ;
if ( 0 == V_157 ) {
F_3 ( & V_100 -> V_54 [ V_45 ] . V_161 , 0 ) ;
F_6 ( & V_100 -> V_54 [ V_45 ] . V_98 , V_99 ) ;
} else {
F_3 ( & V_100 -> V_54 [ V_45 ] . V_161
, ( V_156 << 16 ) ) ;
F_5 ( & V_100 -> V_54 [ V_45 ] . V_98 , V_99 ) ;
}
F_5 ( & V_100 -> V_54 [ V_45 ] . V_98 , V_103 ) ;
V_147 = V_35 & ~ ( T_1 ) 0x03 ;
V_37 -> V_148 = V_147 ;
return V_147 ;
}
static int F_42 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_1 V_35
)
{
T_2 * V_146 ;
T_1 V_6 ;
T_1 V_47 ;
T_1 V_129 ;
T_6 V_134 ;
T_6 * V_130 ;
int V_147 = 0 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_37 -> V_158 )
return 1 ;
if ( V_35 == 0 )
return 0 ;
V_146 = ( T_2 * ) V_37 -> V_37 . V_38 ;
V_130 = ( T_6 * ) ( V_146 + V_37 -> V_37 . V_44 ) ;
V_129 = V_35 / sizeof( T_1 ) ;
if ( V_129 > 0 ) {
for ( V_6 = 0 ; V_6 < V_129 ; V_6 ++ ) {
V_130 -> V_131 =
F_1 ( & V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_162 ) ;
V_130 ++ ;
}
V_147 = V_129 * sizeof( T_1 ) ;
}
V_47 = V_35 - V_147 ;
if ( V_47 > 0 ) {
V_134 . V_131 = F_1 ( & V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_162 ) ;
for ( V_6 = 0 ; V_6 < V_47 ; V_6 ++ )
V_130 -> V_135 . V_136 [ V_6 ] = V_134 . V_135 . V_136 [ V_6 ] ;
V_147 += V_47 ;
}
V_37 -> V_37 . V_44 += V_147 ;
if ( ( V_37 -> V_37 . V_44 == V_37 -> V_37 . V_35 )
|| ( ( V_37 -> V_37 . V_44 % V_60 -> V_60 . V_64 ) != 0 ) ) {
V_147 = 0 ;
}
return V_147 ;
}
static int F_43 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_1 V_163
)
{
T_1 V_45 ;
T_1 V_164 ;
int V_128 = 1 ;
if ( V_60 -> V_62 == 0 )
return - V_63 ;
V_45 = V_60 -> V_62 - 1 ;
V_164 = F_40 ( ( V_37 -> V_37 . V_35 - V_37 -> V_37 . V_44 ) , V_163 ) ;
if ( ( V_60 -> V_66 != V_69 )
&& ( V_37 -> V_37 . V_39 != 0 )
&& ( V_164 >= sizeof( T_1 ) ) ) {
V_128 = F_41 ( V_5 , V_37 , V_45 , V_164 ) ;
} else {
V_164 = F_40 ( V_164 , ( T_1 ) V_60 -> V_60 . V_64 ) ;
V_128 = F_42 ( V_5 , V_60 , V_37 , V_164 ) ;
}
return V_128 ;
}
static int F_44 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37
)
{
T_1 V_45 ;
T_1 V_149 ;
int V_147 = 1 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_60 -> V_62 == 0 )
return - V_63 ;
V_45 = V_60 -> V_62 - 1 ;
V_149
= F_1 ( & V_100 -> V_54 [ V_45 ] . V_161 ) & V_165 ;
if ( V_149 != 0 ) {
V_147 = F_43 ( V_5 , V_60 , V_37 , V_149 ) ;
if ( V_149 < V_60 -> V_60 . V_64 ) {
if ( V_149 == V_147 ) {
V_37 -> V_37 . V_44 += V_147 ;
V_147 = 0 ;
}
}
} else {
if ( ( V_37 -> V_37 . V_44 == V_37 -> V_37 . V_35 )
|| ( ( V_37 -> V_37 . V_44 % V_60 -> V_60 . V_64 ) != 0 ) ) {
V_147 = 0 ;
}
}
if ( V_147 == 0 ) {
if ( ( V_37 -> V_37 . V_44 % V_60 -> V_60 . V_64 ) == 0 ) {
if ( V_37 -> V_40 ) {
V_37 -> V_40 = 0 ;
return 1 ;
}
}
}
if ( V_37 -> V_37 . V_44 > V_37 -> V_37 . V_35 ) {
F_9 ( L_7 ) ;
F_9 ( L_8 ,
V_37 -> V_37 . V_44 , V_37 -> V_37 . V_35 ) ;
V_147 = - V_153 ;
}
return V_147 ;
}
static int F_45 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_1 V_45 ,
T_1 V_35
)
{
T_2 * V_146 ;
T_1 V_154 ;
T_1 V_155 ;
T_1 V_156 ;
T_1 V_139 ;
T_1 V_47 ;
int V_147 = - V_63 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_37 -> V_158 )
return 1 ;
#ifdef F_46
if ( V_37 -> V_37 . V_44 == 0 )
F_26 ( V_5 , V_60 , V_37 , V_120 ) ;
#endif
V_37 -> V_158 = TRUE ;
V_154 = F_1 ( & V_100 -> V_54 [ V_45 ] . V_55 ) & V_58 ;
if ( ( V_160 * V_154 ) < V_35 )
V_139 = V_160 * V_154 ;
else
V_139 = V_35 ;
if ( V_154 < V_139 ) {
V_156 = V_139 / V_154 ;
V_155 = ( V_139 % V_154 ) & ~ ( T_1 ) 0x3 ;
if ( V_155 != 0 )
V_156 ++ ;
else
V_155 = V_154 & ~ ( T_1 ) 0x3 ;
} else {
V_156 = 1 ;
V_155 = V_139 & ~ ( T_1 ) 0x3 ;
}
V_47 = V_154 | ( V_155 << 16 ) ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_92 , V_47 ) ;
V_146 = ( T_2 * ) V_37 -> V_37 . V_39 ;
V_146 += V_37 -> V_37 . V_44 ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_159 , ( T_1 ) V_146 ) ;
V_47 = ( ( V_156 & 0xff ) << 16 ) | V_101 ;
F_3 ( & V_100 -> V_91 [ V_45 ] . V_94 , V_47 ) ;
V_47 = V_156 << 16 ;
F_3 ( & V_100 -> V_54 [ V_45 ] . V_161 , V_47 ) ;
F_5 ( & V_100 -> V_54 [ V_45 ] . V_98 , V_103 ) ;
V_147 = V_139 & ~ ( T_1 ) 0x3 ;
V_37 -> V_148 = V_147 ;
return V_147 ;
}
static int F_47 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_1 V_35
)
{
T_2 * V_146 ;
T_1 V_6 ;
T_1 V_47 ;
T_1 V_129 ;
T_6 V_134 ;
T_6 * V_130 = NULL ;
int V_147 = 0 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_37 -> V_158 )
return 1 ;
if ( V_35 > 0 ) {
V_146 = ( T_2 * ) V_37 -> V_37 . V_38 ;
V_130 = ( T_6 * ) ( V_146 + V_37 -> V_37 . V_44 ) ;
V_129 = V_35 / sizeof( T_1 ) ;
if ( V_129 > 0 ) {
for ( V_6 = 0 ; V_6 < V_129 ; V_6 ++ ) {
F_3 (
& V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_110
, V_130 -> V_131
) ;
V_130 ++ ;
}
V_147 = V_129 * sizeof( T_1 ) ;
}
}
if ( V_147 != V_60 -> V_60 . V_64 ) {
V_47 = V_35 - V_147 ;
V_134 . V_131 = 0 ;
for ( V_6 = 0 ; V_6 < V_47 ; V_6 ++ )
V_134 . V_135 . V_136 [ V_6 ] = V_130 -> V_135 . V_136 [ V_6 ] ;
F_25 ( V_5 , V_60 -> V_62 , V_134 . V_131 , V_47 ) ;
V_147 += V_47 ;
}
V_37 -> V_148 = V_147 ;
return V_147 ;
}
static int F_48 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
T_1 V_163
)
{
T_1 V_45 ;
int V_128 = 1 ;
if ( V_60 -> V_62 == 0 )
return - V_63 ;
V_45 = V_60 -> V_62 - 1 ;
if ( ( V_60 -> V_66 != V_69 )
&& ( V_37 -> V_37 . V_39 != 0 )
&& ( V_163 >= sizeof( T_1 ) ) ) {
V_128 = F_45 ( V_5 , V_60 , V_37 , V_45 , V_163 ) ;
} else {
V_163 = F_40 ( V_163 , ( T_1 ) V_60 -> V_60 . V_64 ) ;
V_128 = F_47 ( V_5 , V_60 , V_37 , V_163 ) ;
}
return V_128 ;
}
static int F_49 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37
)
{
T_1 V_45 ;
T_1 V_164 ;
int V_147 = 0 ;
T_1 V_42 ;
if ( V_60 -> V_62 == 0 )
return - V_63 ;
V_45 = V_60 -> V_62 - 1 ;
V_42 = F_1 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_166 ) ;
if ( V_37 -> V_37 . V_44 == 0 ) {
if ( ( V_42 & V_167 ) == 0 )
return 1 ;
} else {
if ( ( V_42 & V_168 ) != 0 )
return 1 ;
}
V_164 = V_37 -> V_37 . V_35 - V_37 -> V_37 . V_44 ;
if ( V_164 > 0 )
V_147 = F_48 ( V_5 , V_60 , V_37 , V_164 ) ;
else if ( V_37 -> V_37 . V_35 == 0 )
F_50 ( V_5 , V_60 -> V_62 ) ;
return V_147 ;
}
static int F_51 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 ,
bool V_169 )
{
int V_128 = - V_63 ;
V_37 -> V_158 = FALSE ;
V_37 -> V_148 = 0 ;
if ( V_37 -> V_37 . V_35 == 0 )
V_37 -> V_40 = 0 ;
else {
if ( ( V_37 -> V_37 . V_35 % V_60 -> V_60 . V_64 ) == 0 )
V_37 -> V_40 = V_37 -> V_37 . V_40 ;
else
V_37 -> V_40 = 0 ;
}
if ( V_60 -> V_62 == 0 ) {
switch ( V_5 -> V_170 ) {
case V_171 :
V_128 = F_38 ( V_5 , V_60 , V_37 ) ;
break;
case V_172 :
V_128 = F_39 ( V_5 , V_60 , V_37 ) ;
break;
case V_173 :
V_128 = F_36 ( V_5 , TRUE ) ;
break;
default:
break;
}
} else {
if ( V_60 -> V_74 == V_75 ) {
if ( V_169 == FALSE )
V_128 = F_44 ( V_5 , V_60 , V_37 ) ;
} else {
V_128 = F_49 ( V_5 , V_60 , V_37 ) ;
}
}
return V_128 ;
}
static void F_52 ( struct V_59 * V_60 )
{
T_1 V_35 ;
bool V_169 = FALSE ;
struct V_113 * V_37 ;
if ( F_53 ( & V_60 -> V_174 ) )
V_37 = NULL ;
else
V_37 = F_54 ( V_60 -> V_174 . V_175 , struct V_113 , V_174 ) ;
if ( V_37 == NULL )
return;
if ( V_60 -> V_62 > 0 ) {
V_35 = F_1 (
& V_60 -> V_5 -> V_53 -> V_54 [ V_60 -> V_62 - 1 ] . V_161 ) ;
V_35 &= V_165 ;
if ( V_35 < V_60 -> V_60 . V_64 )
V_169 = TRUE ;
}
F_51 ( V_60 -> V_5 , V_60 , V_37 , V_169 ) ;
}
static void F_19 (
struct V_4 * V_5 ,
T_2 V_176 )
{
T_2 V_45 ;
T_1 V_47 ;
if ( ( V_176 == 0 ) || ( V_176 == 0x80 ) )
return;
V_45 = ( V_176 & 0x7F ) - 1 ;
if ( V_176 & V_120 )
V_47 = V_177 ;
else
V_47 = V_77 | V_178 ;
F_5 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
}
static void F_55 (
struct V_4 * V_5 ,
T_2 V_176 ,
bool V_179 )
{
T_2 V_45 , V_62 ;
T_1 V_47 ;
struct V_59 * V_60 ;
T_5 V_100 = V_5 -> V_53 ;
if ( ( V_176 == 0 ) || ( V_176 == 0x80 ) ) {
if ( V_179 ) {
F_5 ( & V_100 -> V_105 , V_180 ) ;
} else {
F_6 ( & V_100 -> V_105 , V_180 ) ;
}
} else {
V_62 = V_176 & V_181 ;
V_45 = V_62 - 1 ;
V_60 = & V_5 -> V_60 [ V_62 ] ;
if ( V_179 ) {
V_60 -> V_182 = TRUE ;
if ( V_176 & V_120 )
V_47 = V_77 | V_86 ;
else
V_47 = V_80 | V_81 ;
F_5 ( & V_100 -> V_54 [ V_45 ] . V_56 , V_47 ) ;
} else {
V_60 -> V_183 = FALSE ;
if ( V_176 & V_120 ) {
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
V_60 -> V_183 = FALSE ;
if ( V_60 -> V_182 ) {
V_60 -> V_182 = FALSE ;
F_52 ( V_60 ) ;
}
}
}
return;
}
static void F_15 ( struct V_4 * V_5 , T_1 V_184 )
{
T_1 V_47 ;
if ( V_184 > V_185 )
return;
F_8 ( L_9 , V_184 ) ;
V_47 = F_1 ( & V_5 -> V_53 -> V_186 ) ;
V_47 &= ~ V_187 ;
V_47 |= V_184 << V_188 ;
F_3 ( & V_5 -> V_53 -> V_186 , V_47 ) ;
F_5 ( & V_5 -> V_53 -> V_189 , V_190 ) ;
}
static int F_56 (
struct V_4 * V_5 ,
T_3 V_18 ,
T_3 V_33
)
{
int V_147 = - V_191 ;
switch ( V_18 ) {
case V_192 :
if ( 0x0000 == V_33 ) {
V_5 -> V_193 = V_194 ;
V_147 = 0 ;
}
break;
case V_32 :
V_33 = V_33 >> 8 ;
if ( V_33 <= V_185 )
V_147 = 0 ;
break;
default:
break;
}
return V_147 ;
}
static int F_57 ( struct V_4 * V_5 , T_2 V_176 )
{
T_2 V_62 ;
T_1 V_47 = 0 , V_195 ;
T_5 V_100 = V_5 -> V_53 ;
V_62 = V_176 & ~ V_196 ;
if ( V_62 == 0 ) {
V_47 = F_1 ( & V_100 -> V_105 ) ;
V_195 = V_180 ;
} else {
V_47 = F_1 ( & V_100 -> V_54 [ V_62 - 1 ] . V_56 ) ;
if ( ( V_47 & V_76 ) == 0 )
return - 1 ;
if ( V_176 & V_196 )
V_195 = V_86 ;
else
V_195 = V_81 ;
}
if ( ( V_47 & V_195 ) == 0 )
return 0 ;
else
return 1 ;
}
static inline int F_58 ( struct V_4 * V_5 , bool V_197 )
{
T_2 V_17 = ( T_2 ) ( V_5 -> V_23 . V_24 & V_29 ) ;
T_2 V_198 = ( T_2 ) ( V_5 -> V_23 . V_24 & V_120 ) ;
T_3 V_18 = V_5 -> V_23 . V_30 ;
T_3 V_33 = V_5 -> V_23 . V_33 ;
T_2 V_176 ;
int V_147 = - V_191 ;
if ( ( 0x0000 != V_5 -> V_23 . V_199 ) ||
( V_75 != V_198 ) ) {
return - V_63 ;
}
switch ( V_17 ) {
case V_31 :
if ( V_197 )
V_147 =
F_56 ( V_5 , V_18 , V_33 ) ;
break;
case V_200 :
if ( 0x0000 == ( V_33 & 0xFF70 ) ) {
if ( V_201 == V_18 ) {
V_176 = V_33 & 0xFF ;
if ( V_197 == FALSE ) {
F_19 (
V_5 , V_176 ) ;
}
F_55 (
V_5 , V_176 , V_197 ) ;
V_147 = 0 ;
}
}
break;
default:
break;
}
if ( V_147 >= 0 )
F_16 ( V_5 , V_5 -> V_202 , 0 ) ;
return V_147 ;
}
static inline enum V_203 F_59 ( struct V_4 * V_5 )
{
T_1 V_47 ;
enum V_203 V_204 = V_205 ;
V_47 = F_1 ( & V_5 -> V_53 -> V_206 ) ;
if ( V_47 & V_207 )
V_204 = V_208 ;
return V_204 ;
}
static void F_60 (
struct V_4 * V_5 ,
struct V_59 * V_60
)
{
T_2 V_176 ;
T_1 V_209 ;
int V_210 = 0 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_60 -> V_74 == V_120 ) {
for ( V_210 = 0
; V_210 < V_211
; V_210 ++ ) {
V_209 = F_1 (
& V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_166 ) ;
if ( ( V_209 & V_212 ) == 0 )
break;
F_24 ( 1 ) ;
}
}
V_176 = V_60 -> V_62 | V_60 -> V_74 ;
F_55 ( V_5 , V_176 , 1 ) ;
}
static int F_61 ( struct V_4 * V_5 )
{
T_1 V_35 ;
T_3 V_213 = 0 ;
T_2 V_17 = ( T_2 ) ( V_5 -> V_23 . V_24 & V_29 ) ;
T_2 V_198 = ( T_2 ) ( V_5 -> V_23 . V_24 & V_120 ) ;
T_2 V_176 ;
int V_147 = - V_63 ;
if ( ( 0x0000 != V_5 -> V_23 . V_30 )
|| ( V_120 != V_198 ) ) {
return V_147 ;
}
V_35 = F_40 ( V_5 -> V_23 . V_199 , ( T_3 ) sizeof( V_213 ) ) ;
switch ( V_17 ) {
case V_31 :
if ( V_5 -> V_23 . V_33 == 0x0000 ) {
if ( V_5 -> V_214 )
V_213 |= ( 1 << V_215 ) ;
if ( V_5 -> V_193 )
V_213 |= ( 1 << V_192 ) ;
V_147 = 0 ;
}
break;
case V_200 :
if ( 0x0000 == ( V_5 -> V_23 . V_33 & 0xFF70 ) ) {
V_176 = ( T_2 ) ( V_5 -> V_23 . V_33 & 0xFF ) ;
V_147 = F_57 ( V_5 , V_176 ) ;
if ( V_147 > 0 )
V_213 |= ( 1 << V_201 ) ;
}
break;
default:
break;
}
if ( V_147 >= 0 ) {
memcpy ( V_5 -> V_202 , & V_213 , V_35 ) ;
F_16 ( V_5 , V_5 -> V_202 , V_35 ) ;
F_38 ( V_5 , & V_5 -> V_60 [ 0 ] , & V_5 -> V_36 ) ;
} else {
F_9 ( L_10 ) ;
}
return V_147 ;
}
static int F_62 ( struct V_4 * V_5 )
{
return F_58 ( V_5 , FALSE ) ;
}
static int F_63 ( struct V_4 * V_5 )
{
return F_58 ( V_5 , TRUE ) ;
}
static int F_64 ( struct V_4 * V_5 )
{
int V_147 = 0 ;
T_1 V_30 = V_5 -> V_23 . V_30 ;
if ( ( 0x00 != V_5 -> V_23 . V_24 ) ||
( 0x0000 != V_5 -> V_23 . V_33 ) ||
( 0x0000 != V_5 -> V_23 . V_199 ) ) {
return - V_63 ;
}
if ( V_30 != ( V_30 & 0x007F ) )
return - V_63 ;
V_30 = V_30 << V_216 ;
F_3 ( & V_5 -> V_53 -> V_217 , V_30 ) ;
F_16 ( V_5 , V_5 -> V_202 , 0 ) ;
return V_147 ;
}
static int F_65 ( struct V_4 * V_5 )
{
T_1 V_218 = ( T_1 ) ( V_5 -> V_23 . V_30 & 0x00ff ) ;
if ( ( 0x0000 != V_5 -> V_23 . V_33 ) ||
( 0x0000 != V_5 -> V_23 . V_199 ) ||
( 0x00 != V_5 -> V_23 . V_24 ) ) {
return - V_63 ;
}
V_5 -> V_219 = V_218 ;
if ( V_218 > 0 ) {
F_5 ( & V_5 -> V_53 -> V_186 , V_220 ) ;
V_5 -> V_221 = V_222 ;
} else {
F_6 ( & V_5 -> V_53 -> V_186 , V_220 ) ;
V_5 -> V_221 = V_223 ;
}
return 0 ;
}
static inline void F_66 ( struct V_4 * V_5 , T_1 * V_224 )
{
if ( ( V_5 == NULL ) && ( V_224 == NULL ) )
return;
* V_224 = F_1 ( & V_5 -> V_53 -> V_225 ) ;
V_224 ++ ;
* V_224 = F_1 ( & V_5 -> V_53 -> V_226 ) ;
}
static inline int F_67 ( struct V_4 * V_5 )
{
bool V_227 = TRUE ;
int V_128 = - V_63 ;
struct V_20 * V_21 ;
V_21 = & V_5 -> V_23 ;
F_66 ( V_5 , ( T_1 * ) V_21 ) ;
if ( V_21 -> V_199 == 0 ) {
V_5 -> V_170 = V_173 ;
} else {
if ( V_21 -> V_24 & V_120 )
V_5 -> V_170 = V_171 ;
else
V_5 -> V_170 = V_172 ;
}
if ( ( V_21 -> V_24 & V_25 ) == V_26 ) {
switch ( V_21 -> V_27 ) {
case V_228 :
V_128 = F_61 ( V_5 ) ;
V_227 = FALSE ;
break;
case V_229 :
V_128 = F_62 ( V_5 ) ;
V_227 = FALSE ;
break;
case V_28 :
V_128 = F_63 ( V_5 ) ;
V_227 = FALSE ;
break;
case V_230 :
V_128 = F_64 ( V_5 ) ;
V_227 = FALSE ;
break;
case V_231 :
V_128 = F_65 ( V_5 ) ;
break;
default:
break;
}
}
if ( V_227 == FALSE ) {
if ( V_5 -> V_170 == V_173 ) {
if ( V_128 >= 0 ) {
V_128 = F_36 ( V_5 , TRUE ) ;
}
}
} else {
F_10 ( & V_5 -> V_9 ) ;
V_128 = V_5 -> V_232 -> V_233 ( & V_5 -> V_117 , & V_5 -> V_23 ) ;
F_13 ( & V_5 -> V_9 ) ;
}
if ( V_128 < 0 )
V_5 -> V_170 = V_234 ;
return V_128 ;
}
static inline int F_68 ( struct V_4 * V_5 )
{
int V_128 ;
struct V_113 * V_37 ;
struct V_59 * V_60 = & V_5 -> V_60 [ 0 ] ;
if ( F_53 ( & V_60 -> V_174 ) )
V_37 = NULL ;
else
V_37 = F_54 ( V_60 -> V_174 . V_175 , struct V_113 , V_174 ) ;
if ( V_37 == NULL )
V_37 = & V_5 -> V_36 ;
V_37 -> V_37 . V_44 += V_37 -> V_148 ;
V_37 -> V_148 = 0 ;
V_128 = F_38 ( V_5 , V_60 , V_37 ) ;
if ( V_128 == 0 ) {
V_5 -> V_170 = V_235 ;
F_37 ( V_5 , TRUE ) ;
}
return 0 ;
}
static inline int F_69 ( struct V_4 * V_5 )
{
int V_128 ;
struct V_113 * V_37 ;
struct V_59 * V_60 = & V_5 -> V_60 [ 0 ] ;
if ( F_53 ( & V_60 -> V_174 ) )
V_37 = NULL ;
else
V_37 = F_54 ( V_60 -> V_174 . V_175 , struct V_113 , V_174 ) ;
if ( V_37 == NULL )
V_37 = & V_5 -> V_36 ;
V_128 = F_39 ( V_5 , V_60 , V_37 ) ;
if ( V_128 == 0 ) {
V_5 -> V_170 = V_173 ;
F_36 ( V_5 , TRUE ) ;
} else if ( V_128 < 0 ) {
F_5 ( & V_5 -> V_53 -> V_105 , V_236 ) ;
V_37 -> V_37 . V_42 = V_128 ;
}
return 0 ;
}
static inline int F_70 ( struct V_4 * V_5 )
{
struct V_113 * V_37 ;
struct V_59 * V_60 = & V_5 -> V_60 [ 0 ] ;
if ( F_53 ( & V_60 -> V_174 ) )
V_37 = NULL ;
else
V_37 = F_54 ( V_60 -> V_174 . V_175 , struct V_113 , V_174 ) ;
if ( V_37 == NULL ) {
V_37 = & V_5 -> V_36 ;
if ( V_37 -> V_37 . V_41 )
V_37 -> V_37 . V_41 ( & V_60 -> V_60 , & V_37 -> V_37 ) ;
} else {
if ( V_37 -> V_37 . V_41 )
F_71 ( V_60 , V_37 , 0 ) ;
}
V_5 -> V_170 = V_234 ;
return 0 ;
}
static inline void F_72 ( struct V_4 * V_5 )
{
int V_6 ;
T_1 V_42 ;
T_1 V_237 ;
int V_128 = - 1 ;
V_42 = F_1 ( & V_5 -> V_53 -> V_238 ) ;
V_237 = V_42 & V_239 ;
F_3 ( & V_5 -> V_53 -> V_238 , ~ ( T_1 ) V_237 ) ;
V_42 &= ( V_240 | V_241 | V_242
| V_243 | V_244 ) ;
if ( V_42 == 0 ) {
F_8 ( L_11 , V_8 ) ;
F_8 ( L_12 , V_237 ) ;
return;
}
if ( V_5 -> V_117 . V_204 == V_245 )
V_5 -> V_117 . V_204 = F_59 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < V_246 ; V_6 ++ ) {
switch ( V_5 -> V_170 ) {
case V_234 :
if ( V_42 & V_240 ) {
V_42 = 0 ;
V_128 = F_67 ( V_5 ) ;
}
break;
case V_171 :
if ( V_42 & V_241 ) {
V_42 &= ~ V_241 ;
V_128 = F_68 ( V_5 ) ;
}
break;
case V_172 :
if ( V_42 & V_242 ) {
V_42 &= ~ V_242 ;
V_128 = F_69 ( V_5 ) ;
}
break;
case V_173 :
if ( ( V_42 & V_243 ) || ( V_42 & V_240 ) ) {
V_42 &= ~ ( V_243 | V_241 ) ;
V_128 = F_70 ( V_5 ) ;
}
break;
case V_235 :
if ( ( V_42 & V_243 )
|| ( V_42 & V_240 )
|| ( V_42 & V_244 ) ) {
V_42 &= ~ ( V_243
| V_242
| V_244 ) ;
V_128 = F_70 ( V_5 ) ;
}
break;
default:
V_42 = 0 ;
break;
}
if ( V_42 == 0 )
break;
}
if ( V_128 < 0 ) {
F_55 ( V_5 , 0 , TRUE ) ;
}
}
static void F_71 (
struct V_59 * V_60 ,
struct V_113 * V_37 ,
int V_42 )
{
struct V_4 * V_5 = V_60 -> V_5 ;
F_73 ( & V_37 -> V_174 ) ;
if ( V_42 == - V_247 )
F_74 ( V_5 , V_60 ) ;
if ( F_75 ( V_37 -> V_37 . V_42 == - V_43 ) )
V_37 -> V_37 . V_42 = V_42 ;
if ( V_60 -> V_183 )
F_60 ( V_5 , V_60 ) ;
else {
if ( ! F_53 ( & V_60 -> V_174 ) )
F_52 ( V_60 ) ;
}
#ifdef F_46
if ( ( V_60 -> V_74 == V_75 ) && ( V_60 -> V_62 > 0 ) &&
( V_37 -> V_37 . V_39 != 0 ) )
F_29 ( V_5 , V_60 , V_37 , V_75 ) ;
#endif
F_10 ( & V_5 -> V_9 ) ;
V_37 -> V_37 . V_41 ( & V_60 -> V_60 , & V_37 -> V_37 ) ;
F_13 ( & V_5 -> V_9 ) ;
}
static inline void F_76 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 )
{
int V_147 = 0 ;
T_1 V_42 ;
T_5 V_100 = V_5 -> V_53 ;
if ( V_37 -> V_158 )
return;
V_37 -> V_37 . V_44 += V_37 -> V_148 ;
V_37 -> V_148 = 0 ;
if ( V_37 -> V_37 . V_44 != V_37 -> V_37 . V_35 ) {
V_147 = F_49 ( V_5 , V_60 , V_37 ) ;
} else {
if ( ( V_37 -> V_40 != 0 )
&& ( ( V_37 -> V_37 . V_44 % V_60 -> V_60 . V_64 ) == 0 ) ) {
V_42 =
F_1 ( & V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_166 ) ;
if ( ( V_42 & V_168 ) == 0 ) {
V_37 -> V_40 = 0 ;
F_50 ( V_5 , V_60 -> V_62 ) ;
}
return;
}
}
if ( V_147 <= 0 ) {
F_71 ( V_60 , V_37 , V_147 ) ;
}
}
static inline void F_77 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 )
{
int V_147 ;
V_147 = F_44 ( V_5 , V_60 , V_37 ) ;
if ( V_147 <= 0 )
F_71 ( V_60 , V_37 , V_147 ) ;
return;
}
static inline void F_78 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 )
{
T_1 V_154 ;
T_1 V_248 ;
struct V_15 * V_249 ;
V_249 = & V_37 -> V_37 ;
if ( V_37 -> V_158 == FALSE )
return;
V_249 -> V_44 += V_37 -> V_148 ;
V_37 -> V_148 = 0 ;
V_37 -> V_158 = FALSE ;
#ifdef F_46
F_29 ( V_5 , V_60 , V_37 , V_120 ) ;
#endif
if ( V_249 -> V_44 != V_249 -> V_35 ) {
F_49 ( V_5 , V_60 , V_37 ) ;
} else {
V_154 = V_60 -> V_60 . V_64 ;
V_248 = V_249 -> V_44 % V_154 ;
if ( V_248 > 0 ) {
if ( ( ( V_249 -> V_44 & 0x03 ) == 0 ) && ( V_248 < V_154 ) )
F_25 ( V_5 , V_60 -> V_62 , 0 , 0 ) ;
} else {
F_76 ( V_5 , V_60 , V_37 ) ;
}
}
return;
}
static inline void F_79 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
struct V_113 * V_37 )
{
int V_6 ;
T_1 V_45 ;
T_1 V_156 , V_250 ;
T_1 V_154 ;
T_5 V_100 = V_5 -> V_53 ;
V_45 = V_60 -> V_62 - 1 ;
if ( V_37 -> V_37 . V_44 == V_37 -> V_37 . V_35 ) {
if ( ( V_37 -> V_37 . V_35 % V_60 -> V_60 . V_64 )
&& ( V_37 -> V_40 == 0 ) ) {
V_37 -> V_148 = 0 ;
V_37 -> V_158 = FALSE ;
F_71 ( V_60 , V_37 , 0 ) ;
return;
}
}
V_250 = F_1 ( & V_100 -> V_54 [ V_45 ] . V_161 )
& V_251 ;
V_250 >>= 16 ;
for ( V_6 = 0 ; V_6 < V_252 ; V_6 ++ ) {
V_156 = F_1 ( & V_100 -> V_91 [ V_45 ] . V_94 )
& V_253 ;
V_156 >>= 16 ;
if ( V_250 == V_156 )
break;
}
F_6 ( & V_100 -> V_91 [ V_45 ] . V_94 , V_101 ) ;
if ( V_156 != 0 ) {
V_154 = V_60 -> V_60 . V_64 ;
if ( ( V_37 -> V_148 % V_154 ) == 0 )
V_37 -> V_148 -= V_154 * V_156 ;
}
if ( ( V_37 -> V_37 . V_44 % V_60 -> V_60 . V_64 ) > 0 ) {
if ( V_37 -> V_37 . V_44 == V_37 -> V_148 ) {
V_37 -> V_148 = 0 ;
V_37 -> V_158 = FALSE ;
F_71 ( V_60 , V_37 , 0 ) ;
return;
}
}
V_37 -> V_37 . V_44 += V_37 -> V_148 ;
V_37 -> V_148 = 0 ;
V_37 -> V_158 = FALSE ;
F_77 ( V_5 , V_60 , V_37 ) ;
}
static inline void F_80 ( struct V_4 * V_5 , T_1 V_62 )
{
T_1 V_45 ;
T_1 V_42 ;
struct V_113 * V_37 ;
struct V_59 * V_60 = & V_5 -> V_60 [ V_62 ] ;
V_45 = V_62 - 1 ;
V_42 = F_1 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_166 ) ;
F_3 ( & V_5 -> V_53 -> V_54 [ V_45 ] . V_166 , ~ ( T_1 ) V_42 ) ;
if ( F_53 ( & V_60 -> V_174 ) )
V_37 = NULL ;
else
V_37 = F_54 ( V_60 -> V_174 . V_175 , struct V_113 , V_174 ) ;
if ( V_37 == NULL ) {
return;
}
if ( V_42 & V_254 ) {
V_42 &= ~ V_255 ;
F_79 ( V_5 , V_60 , V_37 ) ;
}
if ( V_42 & V_255 )
F_77 ( V_5 , V_60 , V_37 ) ;
if ( V_42 & V_256 ) {
V_42 &= ~ V_257 ;
F_78 ( V_5 , V_60 , V_37 ) ;
}
if ( V_42 & V_257 )
F_76 ( V_5 , V_60 , V_37 ) ;
}
static inline void F_81 ( struct V_4 * V_5 , T_1 V_62 )
{
if ( V_62 == 0 )
F_72 ( V_5 ) ;
else
F_80 ( V_5 , V_62 ) ;
}
static void F_82 ( struct V_4 * V_5 )
{
F_5 ( & V_5 -> V_53 -> V_105 , ( V_106 | V_236 ) ) ;
F_3 ( & V_5 -> V_53 -> V_258 , V_259 ) ;
return;
}
static int F_83 ( struct V_4 * V_5 ,
struct V_59 * V_60 ,
int V_42 )
{
struct V_113 * V_37 ;
F_20 ( V_5 , V_60 ) ;
F_22 ( V_5 , V_60 ) ;
if ( F_53 ( & V_60 -> V_174 ) )
return 0 ;
while ( ! F_53 ( & V_60 -> V_174 ) ) {
V_37 = F_54 ( V_60 -> V_174 . V_175 , struct V_113 , V_174 ) ;
F_71 ( V_60 , V_37 , V_42 ) ;
}
return 0 ;
}
static void F_84 ( struct V_4 * V_5 )
{
struct V_59 * V_60 ;
V_5 -> V_117 . V_204 = V_245 ;
F_83 ( V_5 , & V_5 -> V_60 [ 0 ] , - V_260 ) ;
F_85 (ep, &udc->gadget.ep_list, ep.ep_list) {
F_83 ( V_5 , V_60 , - V_260 ) ;
}
}
static int F_86 ( struct V_4 * V_5 , int V_261 )
{
T_1 V_3 ;
if ( ! V_5 ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
if ( V_5 -> V_89 == 0 )
return - V_260 ;
if ( V_261 ) {
if ( V_5 -> V_232 ) {
V_3 = ( F_1 ( & V_5 -> V_53 -> V_186 )
| V_262 ) & ~ ( T_1 ) V_263 ;
F_3 ( & V_5 -> V_53 -> V_186 , V_3 ) ;
}
} else {
V_3 = ( F_1 ( & V_5 -> V_53 -> V_186 ) | V_263 )
& ~ ( T_1 ) V_262 ;
F_3 ( & V_5 -> V_53 -> V_186 , V_3 ) ;
V_5 -> V_117 . V_204 = V_245 ;
}
return 0 ;
}
static void F_74 ( struct V_4 * V_5 , struct V_59 * V_60 )
{
T_5 V_124 = V_5 -> V_53 ;
if ( V_5 -> V_89 == 0 )
return;
if ( V_60 -> V_62 == 0 ) {
F_5 ( & V_124 -> V_105 , V_236 ) ;
} else {
F_23 ( V_5 , V_60 ) ;
F_5 ( & V_124 -> V_54 [ V_60 -> V_62 - 1 ] . V_56 , V_77 ) ;
}
}
static int F_87 ( struct V_4 * V_5 )
{
int V_264 = 0 ;
if ( V_5 -> V_265 )
return 0 ;
#if 0
emxx_open_clockgate(EMXX_CLK_USB1);
emxx_unreset_device(EMXX_RST_USB1);
#endif
F_5 ( & V_5 -> V_53 -> V_266 , ( V_267 | V_268 ) ) ;
F_88 ( V_269 ) ;
F_6 ( & V_5 -> V_53 -> V_266 , V_267 ) ;
F_24 ( V_270 ) ;
F_6 ( & V_5 -> V_53 -> V_266 , V_268 ) ;
F_3 ( & V_5 -> V_53 -> V_271 , V_272 ) ;
#if 0
if ((system_rev & EMXX_REV_MASK) == EMXX_REV_ES1) {
_nbu2ss_bitset(&udc->p_regs->AHBMCTR, BURST_TYPE);
_nbu2ss_bitclr(&udc->p_regs->AHBMCTR, HTRANS_MODE);
} else
#endif
F_3 ( & V_5 -> V_53 -> V_273 ,
V_274 | V_275 | V_276 ) ;
while ( ! ( F_1 ( & V_5 -> V_53 -> V_266 ) & V_277 ) ) {
V_264 ++ ;
F_88 ( 1 ) ;
if ( V_264 == V_252 ) {
F_9 ( L_14 ) ;
return - V_63 ;
}
} ;
#if 0
if ((system_rev & EMXX_REV_MASK) < EMXX_REV_ES3)
#endif
F_5 ( & V_5 -> V_53 -> V_278 , V_279 ) ;
F_5 ( & V_5 -> V_53 -> V_186 , ( V_280 | V_281 ) ) ;
F_82 ( V_5 ) ;
F_5 ( & V_5 -> V_53 -> V_65 , V_282 ) ;
V_5 -> V_265 = TRUE ;
return 0 ;
}
static void F_89 ( struct V_4 * V_5 )
{
F_5 ( & V_5 -> V_53 -> V_266 , V_268 ) ;
F_6 ( & V_5 -> V_53 -> V_266 , V_268 ) ;
}
static void F_90 ( struct V_4 * V_5 )
{
if ( V_5 -> V_265 ) {
V_5 -> V_265 = FALSE ;
F_89 ( V_5 ) ;
F_5 ( & V_5 -> V_53 -> V_266 , ( V_267 | V_268 ) ) ;
}
#if 0
emxx_reset_device(EMXX_RST_USB1);
emxx_close_clockgate(EMXX_CLK_USB1);
#endif
}
static inline void F_91 ( struct V_4 * V_5 )
{
int V_128 ;
T_1 V_3 ;
F_24 ( V_283 ) ;
V_3 = F_92 ( V_284 ) ;
if ( V_3 == 0 ) {
V_5 -> V_285 = 0 ;
F_89 ( V_5 ) ;
F_8 ( L_15 ) ;
if ( V_5 -> V_89 == 1 ) {
V_5 -> V_89 = 0 ;
if ( V_5 -> V_286 ) {
V_5 -> V_286 = 0 ;
}
V_5 -> V_221 = V_287 ;
F_84 ( V_5 ) ;
if ( V_5 -> V_232 ) {
F_10 ( & V_5 -> V_9 ) ;
V_5 -> V_232 -> V_288 ( & V_5 -> V_117 ) ;
F_13 ( & V_5 -> V_9 ) ;
}
F_90 ( V_5 ) ;
}
} else {
F_24 ( 5 ) ;
V_3 = F_92 ( V_284 ) ;
if ( V_3 == 0 )
return;
F_8 ( L_16 ) ;
if ( V_5 -> V_285 )
return;
if ( V_5 -> V_89 == 0 ) {
V_5 -> V_89 = 1 ;
V_5 -> V_221 = V_289 ;
V_128 = F_87 ( V_5 ) ;
if ( V_128 < 0 ) {
F_90 ( V_5 ) ;
V_5 -> V_89 = 0 ;
return;
}
F_86 ( V_5 , 1 ) ;
#ifdef F_93
F_7 ( V_5 ) ;
#endif
} else {
if ( V_5 -> V_221 == V_289 )
F_86 ( V_5 , 1 ) ;
}
}
return;
}
static inline void F_94 ( struct V_4 * V_5 )
{
V_5 -> V_221 = V_290 ;
V_5 -> V_193 = 0 ;
F_84 ( V_5 ) ;
V_5 -> V_170 = V_234 ;
}
static inline void F_95 ( struct V_4 * V_5 )
{
if ( V_5 -> V_286 == 1 ) {
V_5 -> V_286 = 0 ;
if ( V_5 -> V_232 && V_5 -> V_232 -> V_291 ) {
F_10 ( & V_5 -> V_9 ) ;
V_5 -> V_232 -> V_291 ( & V_5 -> V_117 ) ;
F_13 ( & V_5 -> V_9 ) ;
}
}
}
static inline void F_96 ( struct V_4 * V_5 )
{
T_1 V_3 ;
if ( V_5 -> V_286 == 0 ) {
V_3 = F_92 ( V_284 ) ;
if ( V_3 == 0 )
return;
V_5 -> V_286 = 1 ;
if ( V_5 -> V_232 && V_5 -> V_232 -> V_292 ) {
F_10 ( & V_5 -> V_9 ) ;
V_5 -> V_232 -> V_292 ( & V_5 -> V_117 ) ;
F_13 ( & V_5 -> V_9 ) ;
}
F_5 ( & V_5 -> V_53 -> V_186 , V_293 ) ;
}
}
static T_7 F_97 ( int V_294 , void * V_295 )
{
struct V_4 * V_5 = (struct V_4 * ) V_295 ;
F_13 ( & V_5 -> V_9 ) ;
F_91 ( V_5 ) ;
F_10 ( & V_5 -> V_9 ) ;
return V_296 ;
}
static T_7 F_98 ( int V_294 , void * V_295 )
{
T_2 V_297 = 0 ;
T_1 V_42 ;
T_1 V_62 , V_298 ;
struct V_4 * V_5 = (struct V_4 * ) V_295 ;
T_5 V_100 = V_5 -> V_53 ;
if ( F_92 ( V_284 ) == 0 ) {
F_3 ( & V_100 -> V_299 , ~ V_300 ) ;
F_3 ( & V_100 -> V_65 , 0 ) ;
return V_296 ;
}
F_13 ( & V_5 -> V_9 ) ;
for (; ; ) {
if ( F_92 ( V_284 ) == 0 ) {
F_3 ( & V_100 -> V_299 , ~ V_300 ) ;
F_3 ( & V_100 -> V_65 , 0 ) ;
V_42 = 0 ;
} else
V_42 = F_1 ( & V_100 -> V_299 ) ;
if ( V_42 == 0 )
break;
F_3 ( & V_100 -> V_299 , ~ ( V_42 & V_300 ) ) ;
if ( V_42 & V_301 ) {
F_94 ( V_5 ) ;
}
if ( V_42 & V_302 ) {
F_95 ( V_5 ) ;
}
if ( V_42 & V_303 ) {
V_297 = 1 ;
}
if ( V_42 & V_304 ) {
V_298 = V_42 >> 8 ;
for ( V_62 = 0 ; V_62 < V_52 ; V_62 ++ ) {
if ( 0x01 & V_298 )
F_81 ( V_5 , V_62 ) ;
V_298 >>= 1 ;
if ( V_298 == 0 )
break;
}
}
}
if ( V_297 )
F_96 ( V_5 ) ;
F_10 ( & V_5 -> V_9 ) ;
return V_296 ;
}
static int F_99 (
struct V_13 * V_14 ,
const struct V_305 * V_306 )
{
T_2 V_66 ;
unsigned long V_307 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
if ( ( V_14 == NULL ) || ( V_306 == NULL ) ) {
F_9 ( L_17 , V_8 ) ;
return - V_63 ;
}
V_60 = F_100 ( V_14 , struct V_59 , V_60 ) ;
if ( ( V_60 == NULL ) || ( V_60 -> V_5 == NULL ) ) {
F_9 ( L_18 , V_8 ) ;
return - V_63 ;
}
V_66 = V_306 -> V_308 & V_309 ;
if ( ( V_66 == V_310 )
|| ( V_66 == V_72 ) ) {
F_9 ( L_19 , V_8 ) ;
return - V_63 ;
}
V_5 = V_60 -> V_5 ;
if ( V_5 -> V_89 == 0 )
return - V_260 ;
if ( ( V_5 -> V_232 == NULL )
|| ( V_5 -> V_117 . V_204 == V_245 ) ) {
F_9 ( L_20 , V_8 ) ;
return - V_260 ;
}
F_101 ( & V_5 -> V_9 , V_307 ) ;
V_60 -> V_306 = V_306 ;
V_60 -> V_62 = V_306 -> V_311 & V_181 ;
V_60 -> V_74 = V_306 -> V_311 & V_196 ;
V_60 -> V_66 = V_66 ;
V_60 -> V_312 = 0 ;
V_60 -> V_182 = FALSE ;
V_60 -> V_183 = FALSE ;
V_60 -> V_60 . V_64 = F_102 ( V_306 -> V_313 ) ;
F_21 ( V_5 , V_60 ) ;
F_18 ( V_5 , V_60 ) ;
F_103 ( & V_5 -> V_9 , V_307 ) ;
return 0 ;
}
static int F_104 ( struct V_13 * V_14 )
{
struct V_59 * V_60 ;
struct V_4 * V_5 ;
unsigned long V_307 ;
if ( V_14 == NULL ) {
F_9 ( L_17 , V_8 ) ;
return - V_63 ;
}
V_60 = F_100 ( V_14 , struct V_59 , V_60 ) ;
if ( ( V_60 == NULL ) || ( V_60 -> V_5 == NULL ) ) {
F_9 ( L_18 , V_8 ) ;
return - V_63 ;
}
V_5 = V_60 -> V_5 ;
if ( V_5 -> V_89 == 0 )
return - V_260 ;
F_101 ( & V_5 -> V_9 , V_307 ) ;
F_83 ( V_5 , V_60 , - V_43 ) ;
F_103 ( & V_5 -> V_9 , V_307 ) ;
return 0 ;
}
static struct V_15 * F_105 (
struct V_13 * V_60 ,
T_8 V_314 )
{
struct V_113 * V_37 ;
V_37 = F_106 ( sizeof( * V_37 ) , V_314 ) ;
if ( ! V_37 )
return 0 ;
#ifdef F_46
V_37 -> V_37 . V_39 = V_114 ;
#endif
F_107 ( & V_37 -> V_174 ) ;
return & V_37 -> V_37 ;
}
static void F_108 (
struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_113 * V_37 ;
if ( V_16 != NULL ) {
V_37 = F_100 ( V_16 , struct V_113 , V_37 ) ;
if ( V_37 != NULL )
F_109 ( V_37 ) ;
}
}
static int F_110 (
struct V_13 * V_14 ,
struct V_15 * V_16 ,
T_8 V_314 )
{
struct V_113 * V_37 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
unsigned long V_307 ;
bool V_169 ;
int V_147 = - V_63 ;
if ( ( V_14 == NULL ) || ( V_16 == NULL ) ) {
if ( V_14 == NULL )
F_9 ( L_21 , V_8 ) ;
if ( V_16 == NULL )
F_9 ( L_22 , V_8 ) ;
return - V_63 ;
}
V_37 = F_100 ( V_16 , struct V_113 , V_37 ) ;
if ( F_111
( ! V_16 -> V_41 || ! V_16 -> V_38
|| ! F_53 ( & V_37 -> V_174 ) ) ) {
if ( ! V_16 -> V_41 )
F_9 ( L_23 , V_8 ) ;
if ( ! V_16 -> V_38 )
F_9 ( L_24 , V_8 ) ;
if ( ! F_53 ( & V_37 -> V_174 ) )
F_9 ( L_25 , V_8 ) ;
return - V_63 ;
}
V_60 = F_100 ( V_14 , struct V_59 , V_60 ) ;
V_5 = V_60 -> V_5 ;
if ( V_5 -> V_89 == 0 ) {
F_8 ( L_26 ) ;
return - V_260 ;
}
if ( F_111 ( ! V_5 -> V_232 ) ) {
F_9 ( L_27 , V_8 , V_5 -> V_232 ) ;
return - V_260 ;
}
F_101 ( & V_5 -> V_9 , V_307 ) ;
#ifdef F_46
if ( ( T_1 ) V_37 -> V_37 . V_38 & 0x3 )
V_37 -> V_115 = TRUE ;
else
V_37 -> V_115 = FALSE ;
if ( V_37 -> V_115 ) {
if ( V_60 -> V_126 == NULL )
V_60 -> V_126 = ( T_2 * ) F_112 (
NULL , V_315 ,
& V_60 -> V_116 , V_316 | V_317 ) ;
if ( V_60 -> V_62 > 0 ) {
if ( V_60 -> V_74 == V_120 )
memcpy ( V_60 -> V_126 , V_37 -> V_37 . V_38 ,
V_37 -> V_37 . V_35 ) ;
}
}
if ( ( V_60 -> V_62 > 0 ) && ( V_60 -> V_74 == V_75 ) &&
( V_37 -> V_37 . V_39 != 0 ) )
F_26 ( V_5 , V_60 , V_37 , V_75 ) ;
#endif
V_16 -> V_42 = - V_43 ;
V_16 -> V_44 = 0 ;
V_169 = F_53 ( & V_60 -> V_174 ) ;
F_113 ( & V_37 -> V_174 , & V_60 -> V_174 ) ;
if ( ( V_169 != FALSE ) && ( V_60 -> V_183 == FALSE ) ) {
V_147 = F_51 ( V_5 , V_60 , V_37 , FALSE ) ;
if ( V_147 < 0 ) {
F_9 ( L_28 , V_8 , V_147 ) ;
F_114 ( & V_37 -> V_174 ) ;
} else if ( ( V_60 -> V_62 > 0 ) && ( V_60 -> V_74 == V_75 ) ) {
#ifdef F_46
if ( V_37 -> V_37 . V_35 < 4 &&
V_37 -> V_37 . V_35 == V_37 -> V_37 . V_44 )
#else
if ( V_37 -> V_37 . V_35 == V_37 -> V_37 . V_44 )
#endif
F_71 ( V_60 , V_37 , V_147 ) ;
}
}
F_103 ( & V_5 -> V_9 , V_307 ) ;
return 0 ;
}
static int F_115 (
struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_113 * V_37 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
unsigned long V_307 ;
if ( ( V_14 == NULL ) || ( V_16 == NULL ) ) {
return - V_63 ;
}
V_60 = F_100 ( V_14 , struct V_59 , V_60 ) ;
if ( ! V_60 ) {
F_9 ( L_29 , V_8 ) ;
return - V_63 ;
}
V_5 = V_60 -> V_5 ;
if ( V_5 == NULL )
return - V_63 ;
F_101 ( & V_5 -> V_9 , V_307 ) ;
F_85 (req, &ep->queue, queue) {
if ( & V_37 -> V_37 == V_16 )
break;
}
if ( & V_37 -> V_37 != V_16 ) {
F_103 ( & V_5 -> V_9 , V_307 ) ;
F_116 ( L_30 , V_8 ) ;
return - V_63 ;
}
F_71 ( V_60 , V_37 , - V_247 ) ;
F_103 ( & V_5 -> V_9 , V_307 ) ;
return 0 ;
}
static int F_117 ( struct V_13 * V_14 , int V_318 )
{
T_2 V_176 ;
unsigned long V_307 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
if ( ! V_14 ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_60 = F_100 ( V_14 , struct V_59 , V_60 ) ;
if ( ! V_60 ) {
F_9 ( L_31 , V_8 ) ;
return - V_63 ;
}
V_5 = V_60 -> V_5 ;
if ( ! V_5 ) {
F_9 ( L_32 , V_8 ) ;
return - V_63 ;
}
F_101 ( & V_5 -> V_9 , V_307 ) ;
V_176 = V_60 -> V_62 | V_60 -> V_74 ;
if ( V_318 == 0 ) {
F_55 ( V_5 , V_176 , V_318 ) ;
V_60 -> V_183 = FALSE ;
} else {
if ( F_53 ( & V_60 -> V_174 ) )
F_60 ( V_5 , V_60 ) ;
else
V_60 -> V_183 = TRUE ;
}
if ( V_318 == 0 )
V_60 -> V_312 = 0 ;
F_103 ( & V_5 -> V_9 , V_307 ) ;
return 0 ;
}
static int F_118 ( struct V_13 * V_14 )
{
return F_117 ( V_14 , 1 ) ;
}
static int F_119 ( struct V_13 * V_14 )
{
T_1 V_47 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
unsigned long V_307 ;
T_5 V_100 ;
if ( ! V_14 ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_60 = F_100 ( V_14 , struct V_59 , V_60 ) ;
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
V_47 = F_92 ( V_284 ) ;
if ( V_47 == 0 )
return - V_63 ;
F_101 ( & V_5 -> V_9 , V_307 ) ;
if ( V_60 -> V_62 == 0 ) {
V_47 = F_1 ( & V_100 -> V_151 ) & V_152 ;
} else {
V_47 = F_1 ( & V_100 -> V_54 [ V_60 -> V_62 - 1 ] . V_161 )
& V_165 ;
}
F_103 ( & V_5 -> V_9 , V_307 ) ;
return 0 ;
}
static void F_120 ( struct V_13 * V_14 )
{
T_1 V_47 ;
struct V_59 * V_60 ;
struct V_4 * V_5 ;
unsigned long V_307 ;
if ( ! V_14 ) {
F_9 ( L_13 , V_8 ) ;
return;
}
V_60 = F_100 ( V_14 , struct V_59 , V_60 ) ;
if ( ! V_14 ) {
F_9 ( L_31 , V_8 ) ;
return;
}
V_5 = V_60 -> V_5 ;
if ( ! V_5 ) {
F_9 ( L_33 , V_8 ) ;
return;
}
V_47 = F_92 ( V_284 ) ;
if ( V_47 == 0 )
return;
F_101 ( & V_5 -> V_9 , V_307 ) ;
F_74 ( V_5 , V_60 ) ;
F_103 ( & V_5 -> V_9 , V_307 ) ;
}
static int F_121 ( struct V_319 * V_320 )
{
T_1 V_47 ;
struct V_4 * V_5 ;
if ( V_320 == NULL ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_5 = F_100 ( V_320 , struct V_4 , V_117 ) ;
if ( V_5 == NULL ) {
F_9 ( L_34 , V_8 ) ;
return - V_63 ;
}
V_47 = F_92 ( V_284 ) ;
if ( V_47 == 0 )
return - V_63 ;
V_47 = F_1 ( & V_5 -> V_53 -> V_217 ) & V_321 ;
return V_47 ;
}
static int F_122 ( struct V_319 * V_320 )
{
int V_6 ;
T_1 V_47 ;
struct V_4 * V_5 ;
if ( V_320 == NULL ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_5 = F_100 ( V_320 , struct V_4 , V_117 ) ;
if ( V_5 == NULL ) {
F_9 ( L_34 , V_8 ) ;
return - V_63 ;
}
V_47 = F_92 ( V_284 ) ;
if ( V_47 == 0 ) {
F_123 ( L_35 , V_47 ) ;
return - V_63 ;
}
F_5 ( & V_5 -> V_53 -> V_266 , V_322 ) ;
for ( V_6 = 0 ; V_6 < V_252 ; V_6 ++ ) {
V_47 = F_1 ( & V_5 -> V_53 -> V_266 ) ;
if ( V_47 & V_277 )
break;
}
F_6 ( & V_5 -> V_53 -> V_266 , V_322 ) ;
return 0 ;
}
static int F_124 ( struct V_319 * V_320 ,
int V_323 )
{
struct V_4 * V_5 ;
unsigned long V_307 ;
if ( V_320 == NULL ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_5 = F_100 ( V_320 , struct V_4 , V_117 ) ;
F_101 ( & V_5 -> V_9 , V_307 ) ;
V_5 -> V_214 = ( V_323 != 0 ) ;
F_103 ( & V_5 -> V_9 , V_307 ) ;
return 0 ;
}
static int F_125 ( struct V_319 * V_320 , int V_324 )
{
return 0 ;
}
static int F_126 ( struct V_319 * V_320 , unsigned V_325 )
{
struct V_4 * V_5 ;
unsigned long V_307 ;
if ( V_320 == NULL ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_5 = F_100 ( V_320 , struct V_4 , V_117 ) ;
F_101 ( & V_5 -> V_9 , V_307 ) ;
V_5 -> V_325 = V_325 ;
F_103 ( & V_5 -> V_9 , V_307 ) ;
return 0 ;
}
static int F_127 ( struct V_319 * V_320 , int V_261 )
{
struct V_4 * V_5 ;
unsigned long V_307 ;
if ( V_320 == NULL ) {
F_9 ( L_13 , V_8 ) ;
return - V_63 ;
}
V_5 = F_100 ( V_320 , struct V_4 , V_117 ) ;
if ( V_5 -> V_232 == NULL ) {
F_123 ( L_36 , V_8 ) ;
return - V_63 ;
}
if ( V_5 -> V_89 == 0 )
return - V_260 ;
F_101 ( & V_5 -> V_9 , V_307 ) ;
F_86 ( V_5 , V_261 ) ;
F_103 ( & V_5 -> V_9 , V_307 ) ;
return 0 ;
}
static int F_128 (
struct V_319 * V_320 ,
unsigned V_326 ,
unsigned long V_327 )
{
return 0 ;
}
static void T_9 F_129 (
struct V_4 * V_5 ,
struct V_59 * V_60 ,
T_2 * V_328 )
{
V_60 -> V_5 = V_5 ;
V_60 -> V_306 = NULL ;
V_60 -> V_60 . V_329 = NULL ;
V_60 -> V_60 . V_328 = V_328 ;
V_60 -> V_60 . V_330 = & V_331 ;
if ( isdigit ( V_328 [ 2 ] ) ) {
long V_45 ;
int V_332 ;
char V_333 [ 2 ] ;
V_333 [ 0 ] = V_328 [ 2 ] ;
V_333 [ 1 ] = '\0' ;
V_332 = F_130 ( V_333 , 16 , & V_45 ) ;
if ( V_45 == 0 )
V_60 -> V_60 . V_64 = V_138 ;
else
V_60 -> V_60 . V_64 = V_334 ;
} else {
V_60 -> V_60 . V_64 = V_334 ;
}
F_113 ( & V_60 -> V_60 . V_335 , & V_5 -> V_117 . V_335 ) ;
F_107 ( & V_60 -> V_174 ) ;
}
static void T_9 F_131 ( struct V_4 * V_5 )
{
int V_6 ;
F_107 ( & V_5 -> V_117 . V_335 ) ;
V_5 -> V_117 . V_336 = & V_5 -> V_60 [ 0 ] . V_60 ;
for ( V_6 = 0 ; V_6 < V_52 ; V_6 ++ )
F_129 ( V_5 , & V_5 -> V_60 [ V_6 ] , V_337 [ V_6 ] ) ;
F_73 ( & V_5 -> V_60 [ 0 ] . V_60 . V_335 ) ;
}
static int T_9 F_132 (
struct V_338 * V_339 ,
struct V_4 * V_5 )
{
F_133 ( & V_5 -> V_9 ) ;
V_5 -> V_118 = & V_339 -> V_118 ;
V_5 -> V_214 = 1 ;
V_5 -> V_221 = V_287 ;
V_5 -> V_339 = V_339 ;
V_5 -> V_325 = 0 ;
V_5 -> V_339 -> V_118 . V_340 = F_134 ( 32 ) ;
F_131 ( V_5 ) ;
V_5 -> V_117 . V_330 = & V_341 ;
V_5 -> V_117 . V_336 = & V_5 -> V_60 [ 0 ] . V_60 ;
V_5 -> V_117 . V_204 = V_245 ;
V_5 -> V_117 . V_328 = V_342 ;
F_135 ( & V_5 -> V_117 . V_118 ) ;
F_136 ( & V_5 -> V_117 . V_118 , L_37 ) ;
V_5 -> V_117 . V_118 . V_119 = & V_339 -> V_118 ;
V_5 -> V_117 . V_118 . V_343 = V_339 -> V_118 . V_343 ;
return 0 ;
}
static int F_137 ( struct V_338 * V_339 )
{
int V_42 = - V_344 ;
struct V_4 * V_5 ;
struct V_345 * V_346 ;
int V_294 ;
void T_10 * V_347 ;
V_5 = & V_348 ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
F_138 ( V_339 , V_5 ) ;
V_346 = F_139 ( V_339 , V_349 , 0 ) ;
V_347 = F_140 ( & V_339 -> V_118 , V_346 ) ;
if ( F_141 ( V_347 ) )
return F_142 ( V_347 ) ;
V_294 = F_143 ( V_339 , 0 ) ;
if ( V_294 < 0 ) {
F_144 ( & V_339 -> V_118 , L_38 ) ;
return V_294 ;
}
V_42 = F_145 ( & V_339 -> V_118 , V_294 , F_98 ,
0 , V_342 , V_5 ) ;
V_5 -> V_53 = ( T_5 ) V_347 ;
if ( V_42 != 0 ) {
F_9 ( L_39 ) ;
goto V_350;
}
V_42 = F_132 ( V_339 , V_5 ) ;
if ( V_42 < 0 ) {
goto V_350;
}
F_146 ( V_351 , V_352 ) ;
V_42 = F_147 ( V_351 ,
F_97 ,
V_353 ,
V_342 ,
V_5 ) ;
if ( V_42 != 0 ) {
F_9 ( L_40 ) ;
goto V_350;
}
return V_42 ;
V_350:
return V_42 ;
}
static void F_148 ( struct V_338 * V_339 )
{
struct V_4 * V_5 ;
V_5 = F_149 ( V_339 ) ;
if ( V_5 == NULL )
return;
F_90 ( V_5 ) ;
}
static int T_11 F_150 ( struct V_338 * V_339 )
{
struct V_4 * V_5 ;
struct V_59 * V_60 ;
int V_6 ;
V_5 = & V_348 ;
for ( V_6 = 0 ; V_6 < V_52 ; V_6 ++ ) {
V_60 = & V_5 -> V_60 [ V_6 ] ;
if ( V_60 -> V_126 )
F_151 ( NULL , V_315 ,
( void * ) V_60 -> V_126 , V_60 -> V_116 ) ;
}
F_152 ( V_351 , V_5 ) ;
return 0 ;
}
static int F_153 ( struct V_338 * V_339 , T_12 V_354 )
{
struct V_4 * V_5 ;
V_5 = F_149 ( V_339 ) ;
if ( V_5 == NULL )
return 0 ;
if ( V_5 -> V_89 ) {
V_5 -> V_89 = 0 ;
V_5 -> V_221 = V_287 ;
V_5 -> V_285 = 1 ;
if ( V_5 -> V_286 ) {
V_5 -> V_286 = 0 ;
F_89 ( V_5 ) ;
}
F_84 ( V_5 ) ;
}
F_90 ( V_5 ) ;
return 0 ;
}
static int F_154 ( struct V_338 * V_339 )
{
T_1 V_47 ;
struct V_4 * V_5 ;
V_5 = F_149 ( V_339 ) ;
if ( V_5 == NULL )
return 0 ;
V_47 = F_92 ( V_284 ) ;
if ( V_47 ) {
V_5 -> V_89 = 1 ;
V_5 -> V_221 = V_289 ;
F_87 ( V_5 ) ;
F_86 ( V_5 , 1 ) ;
}
V_5 -> V_285 = 0 ;
return 0 ;
}
