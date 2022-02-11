static inline T_1 F_1 ( T_2 V_1 )
{
return ( T_1 ) 1 << V_1 ;
}
static inline bool F_2 ( T_2 V_2 , const char * V_3 )
{
F_3 ( V_2 , V_3 ) ;
return false ;
}
static int F_4 ( T_3 V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ )
if ( V_4 <= ( V_6 << V_5 ) )
return 1 << V_5 ;
return 0 ;
}
static int F_5 ( T_3 V_4 )
{
int V_7 ;
int V_5 , V_8 = 0 ;
if ( V_4 <= 0 )
return V_9 ;
V_7 = F_4 ( V_4 ) ;
if ( V_7 == 0 )
return V_9 ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
T_1 const V_11 = F_6 ( V_4 , V_6 ) ;
T_1 V_12 = ~ ( ( ~ ( T_1 ) 0 ) << V_11 ) ;
do {
if ( ( V_13 . V_14 [ V_5 ] & V_12 ) == 0 ) {
V_13 . V_14 [ V_5 ] |= V_12 ;
return V_8 * V_6 ;
}
V_8 += V_7 ;
V_12 <<= V_7 - 1 ;
} while ( ( V_12 <<= 1 ) != 0 );
}
return V_9 ;
}
static void F_7 ( int V_15 , int V_4 )
{
int V_8 = V_15 / V_6 ;
T_1 const V_11 = F_6 ( V_4 , V_6 ) ;
T_1 V_12 = ~ ( ( ~ ( T_1 ) 0 ) << V_11 ) ;
V_12 <<= V_8 % 32 ;
V_13 . V_14 [ V_8 / 32 ] &= ~ V_12 ;
}
static void F_8 ( T_1 V_16 )
{
F_9 ( & V_13 . V_17 -> V_18 , V_16 ) ;
while ( ( F_10 ( & V_13 . V_17 -> V_19 ) & 1 ) != 1 )
continue;
F_9 ( & V_13 . V_17 -> V_19 , 0 ) ;
}
static void F_11 ( T_3 V_20 , T_3 V_4 )
{
enum { V_21 = 30 , V_22 = 31 };
T_3 const V_23 = V_20 + V_4 ;
T_1 const V_24 = F_1 ( V_22 ) | F_1 ( V_21 ) ;
F_9 ( & V_13 . V_17 -> V_19 , 0 ) ;
F_9 ( & V_13 . V_17 -> V_25 , 0 ) ;
for (; V_20 < V_23 ; V_20 ++ )
F_8 ( V_24 | V_20 ) ;
}
static T_1 F_12 ( T_1 V_26 , T_3 V_27 )
{
F_8 ( V_26 ) ;
return F_10 ( ( & V_13 . V_17 -> V_25 ) + V_27 ) ;
}
static void F_13 ( T_1 V_26 , const T_1 * V_12 , const T_1 * V_28 )
{
enum { V_22 = 31 };
F_9 ( & V_13 . V_17 -> V_19 , 0 ) ;
if ( V_12 [ 0 ] != 0 )
F_9 ( & V_13 . V_17 -> V_25 , V_28 [ 0 ] ) ;
if ( V_12 [ 1 ] != 0 )
F_9 ( & V_13 . V_17 -> V_29 , V_28 [ 1 ] ) ;
if ( V_12 [ 2 ] != 0 )
F_9 ( & V_13 . V_17 -> V_30 , V_28 [ 2 ] ) ;
if ( V_12 [ 3 ] != 0 )
F_9 ( & V_13 . V_17 -> V_31 , V_28 [ 3 ] ) ;
F_9 ( & V_13 . V_17 -> V_32 , V_12 [ 0 ] ) ;
F_9 ( & V_13 . V_17 -> V_33 , V_12 [ 1 ] ) ;
F_9 ( & V_13 . V_17 -> V_34 , V_12 [ 2 ] ) ;
F_9 ( & V_13 . V_17 -> V_35 , V_12 [ 3 ] ) ;
F_8 ( F_1 ( V_22 ) | V_26 ) ;
}
static inline void F_14 ( T_1 V_26 , const T_1 * V_28 )
{
T_1 const V_12 [ 4 ] = { 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF } ;
F_13 ( V_26 , V_12 , V_28 ) ;
}
static inline void F_15 ( T_1 V_26 )
{
T_1 const V_28 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_14 ( V_26 , V_28 ) ;
}
static void F_16 ( T_2 V_36 , T_2 V_37 , T_2 V_38 ,
bool V_39 )
{
bool V_40 = V_38 == V_41 ;
bool V_42 = V_38 == V_43 ;
T_3 const V_44 =
( V_39 << V_45 ) |
( V_38 << V_46 ) |
( V_37 << V_47 ) |
( V_40 << V_48 ) |
( V_42 << V_49 ) |
( false << V_50 ) |
( true << V_51 ) ;
T_2 const V_26 = V_36 + V_37 / 8 ;
T_2 const V_52 = ( V_37 % 8 ) / 2 ;
T_2 const V_53 = ( V_37 % 2 ) * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_28 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ V_52 ] = ( T_1 ) 0xFFFF << V_53 ;
V_28 [ V_52 ] = V_44 << V_53 ;
F_13 ( V_26 , V_12 , V_28 ) ;
}
static void F_17 ( T_2 V_36 , T_2 V_37 )
{
T_2 const V_26 = V_36 + V_37 / 8 ;
T_2 const V_52 = ( V_37 % 8 ) / 2 ;
T_2 const V_53 = ( V_37 % 2 ) * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_28 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ V_52 ] = ( T_1 ) 0xFFFF << V_53 ;
F_13 ( V_26 , V_12 , V_28 ) ;
}
static void F_18 ( T_2 V_37 , T_3 V_54 , T_3 V_55 ,
T_3 V_56 )
{
T_1 V_57 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( V_56 )
V_57 [ 1 ] = ( ( V_56 - 1 ) << V_58 ) ;
V_57 [ 3 ] =
( ( V_55 - 1 ) << V_59 ) |
( V_54 << V_60 ) ;
F_14 ( V_61 + V_37 , V_57 ) ;
}
static T_3 F_19 ( T_2 V_37 )
{
T_1 V_62 = F_12 ( V_61 + V_37 , 0 ) ;
return ( V_62 >> V_63 ) & V_64 ;
}
static void F_20 ( T_2 V_37 )
{
T_1 V_57 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_14 ( V_61 + V_37 , V_57 ) ;
}
static void F_21 ( T_2 V_37 )
{
T_1 V_65 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_65 [ 0 ] =
( true << V_66 ) |
( true << V_67 ) |
( 0 << V_68 ) ;
F_14 ( V_69 + V_37 , V_65 ) ;
}
static void F_22 ( T_2 V_37 )
{
T_1 V_65 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_14 ( V_69 + V_37 , V_65 ) ;
}
static void F_23 ( T_2 V_37 , T_2 V_52 , T_1 V_70 ,
T_3 V_71 )
{
T_2 const V_53 = V_52 * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_65 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ 1 ] =
F_1 ( V_72 + V_53 ) |
F_1 ( V_73 + V_53 ) |
( V_74 << ( V_75 + V_53 ) ) ;
V_65 [ 1 ] =
( true << ( V_72 + V_53 ) ) |
( true << ( V_73 + V_53 ) ) |
( ( V_71 - 1 ) << ( V_75 + V_53 ) ) ;
V_12 [ V_52 + 2 ] = 0xFFFFFFFF ;
V_65 [ V_52 + 2 ] = V_70 ;
F_13 ( V_69 + V_37 , V_12 , V_65 ) ;
}
static void F_24 ( T_2 V_37 , T_2 V_52 , T_1 V_70 ,
T_3 V_71 )
{
T_2 const V_53 = V_52 * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_65 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ 1 ] =
F_1 ( V_73 + V_53 ) |
( V_76 << ( V_75 + V_53 ) ) ;
V_65 [ 1 ] =
( true << ( V_73 + V_53 ) ) |
( ( V_71 - 1 ) << ( V_75 + V_53 ) ) ;
V_12 [ V_52 + 2 ] = 0xFFFFFFFF ;
V_65 [ V_52 + 2 ] = V_70 ;
F_13 ( V_69 + V_37 , V_12 , V_65 ) ;
}
static void F_25 ( void )
{
T_1 V_26 ;
for ( V_26 = 0 ; V_26 < 0x90 ; V_26 ++ )
F_15 ( V_26 ) ;
}
static void F_26 (
T_2 V_37 , T_2 type , T_2 V_77 , T_3 V_54 , T_3 V_55 ,
T_3 V_56 )
{
F_18 ( V_37 , V_54 , V_55 , V_56 ) ;
F_16 ( V_78 , V_37 , type , V_77 ? 1 : 0 ) ;
F_21 ( V_37 ) ;
F_16 ( V_79 , V_37 , type , V_77 ? 0 : 1 ) ;
F_9 ( & V_13 . V_17 -> V_80 ,
F_10 ( & V_13 . V_17 -> V_80 ) | F_1 ( V_37 ) ) ;
}
static void F_27 ( T_2 V_37 )
{
F_9 ( & V_13 . V_17 -> V_80 ,
F_10 ( & V_13 . V_17 -> V_80 ) & ~ F_1 ( V_37 ) ) ;
F_17 ( V_79 , V_37 ) ;
F_22 ( V_37 ) ;
F_17 ( V_78 , V_37 ) ;
F_20 ( V_37 ) ;
F_9 ( & V_13 . V_17 -> V_81 , F_1 ( V_37 ) ) ;
}
static inline T_3 F_28 ( T_3 V_82 )
{
return V_82 & V_64 ;
}
static void F_29 ( T_2 V_37 , T_3 V_83 )
{
V_13 . V_84 . V_85 = V_83 ;
V_13 . V_84 . V_86 = F_19 ( V_37 ) ;
V_13 . V_84 . V_87 = V_13 . V_84 . V_86 ;
}
static void F_30 ( int V_88 )
{
V_13 . V_84 . V_85 -= V_88 ;
V_13 . V_84 . V_89 [ F_28 ( V_13 . V_84 . V_87 ) ] = V_88 ;
V_13 . V_84 . V_87 ++ ;
}
T_3 F_31 ( struct V_90 * V_91 )
{
T_3 V_92 ;
struct V_93 * V_94 = & V_13 . V_84 ;
if ( V_91 -> V_20 != V_94 -> V_37 )
return 0xFFFF ;
V_92 = F_19 ( V_91 -> V_20 ) ;
while ( F_28 ( V_94 -> V_86 ) != V_92 ) {
V_94 -> V_85 += V_94 -> V_89 [ F_28 ( V_94 -> V_86 ) ] ;
V_94 -> V_86 ++ ;
}
if ( ( T_3 ) ( V_94 -> V_87 - V_94 -> V_86 ) >= V_64 )
return 0 ;
return V_94 -> V_85 ;
}
static void F_32 ( struct V_95 * V_96 )
{
V_96 -> V_97 = 0 ;
V_96 -> V_98 = 0 ;
V_96 -> V_99 = 0 ;
V_96 -> V_100 = 0 ;
V_96 -> V_101 = 0 ;
}
static inline bool F_33 ( T_1 V_102 )
{
return V_102 > 0 && ( V_102 % 2 ) == 0 &&
( V_102 / 2 ) <= ( T_1 ) V_103 ;
}
static inline bool F_34 ( T_1 V_56 )
{
T_3 const V_104 = ( ( T_3 ) V_105 + 1u ) / V_106 ;
if ( V_56 <= 0 )
return false ;
if ( V_56 > V_104 )
return false ;
if ( V_56 - 1u > ( T_1 ) V_107 )
return false ;
return true ;
}
static inline bool F_35 ( T_1 V_108 )
{
T_3 const V_109 = V_13 . V_110 + 2 ;
T_3 const V_104 = ( ( T_3 ) V_111 + 1u ) >> V_109 ;
if ( V_108 <= 0 )
return false ;
if ( V_108 > V_104 )
return false ;
return true ;
}
static inline T_3 F_36 ( T_3 V_112 )
{
T_3 const V_104 = ( T_3 ) V_74 + 1u ;
if ( V_112 > V_104 )
return V_104 ;
return V_112 ;
}
static inline T_3 F_37 ( T_3 V_112 , T_3 V_56 )
{
T_3 V_113 ;
T_3 const V_104 = ( T_3 ) V_76 + 1u ;
if ( V_112 > V_104 )
V_112 = V_104 ;
V_113 = V_112 / V_56 ;
if ( V_113 < 2u )
return 0 ;
return V_56 * V_113 ;
}
static inline T_3 F_38 ( T_3 V_112 , T_3 V_108 )
{
T_3 V_113 ;
T_3 const V_104 = ( T_3 ) V_76 + 1u ;
T_1 const V_114 = V_108 << V_13 . V_110 ;
if ( V_112 > V_104 )
V_112 = V_104 ;
V_113 = V_112 / V_114 ;
if ( V_113 < 1u )
return 0 ;
return V_114 * V_113 ;
}
static void F_39 ( void )
{
F_9 ( & V_13 . V_17 -> V_115 , false << V_116 ) ;
F_25 () ;
F_9 ( & V_13 . V_17 -> V_117 , 0 ) ;
F_9 ( & V_13 . V_17 -> V_81 , 0xFFFFFFFF ) ;
F_9 ( & V_13 . V_17 -> V_118 , 0xFFFFFFFF ) ;
F_9 ( & V_13 . V_17 -> V_80 , 0 ) ;
F_9 ( & V_13 . V_17 -> V_119 , 0 ) ;
}
static void F_40 ( bool V_120 , T_2 V_121 )
{
F_39 () ;
F_9 ( & V_13 . V_17 -> V_115 ,
V_120 << V_122 |
V_121 << V_123 |
V_13 . V_110 << V_124 |
true << V_116 ) ;
F_9 ( & V_13 . V_17 -> V_125 , 0xFFFFFFFF ) ;
F_9 ( & V_13 . V_17 -> V_126 , 0xFFFFFFFF ) ;
F_9 ( & V_13 . V_17 -> V_127 , F_1 ( V_128 ) ) ;
F_9 ( & V_13 . V_17 -> V_129 ,
V_130 << V_131 |
true << V_132 ) ;
}
static bool F_41 ( void )
{
T_1 const V_133 = F_1 ( V_134 ) ;
T_1 const V_135 = F_1 ( V_136 ) |
F_1 ( V_137 ) ;
T_1 const V_138 = F_10 ( & V_13 . V_17 -> V_139 ) ;
T_1 const V_140 = ( T_1 ) V_141 << V_142 ;
F_9 ( & V_13 . V_17 -> V_139 , V_138 & V_140 ) ;
return ( F_10 ( & V_13 . V_17 -> V_139 ) & V_135 ) == 0 &&
( F_10 ( & V_13 . V_17 -> V_115 ) & V_133 ) != 0 ;
}
static inline bool F_42 ( T_2 V_37 , T_2 V_52 )
{
T_2 const V_53 = V_52 * 16 ;
T_1 const V_143 = F_12 ( V_69 + V_37 , 1 ) ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_144 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ( ( V_143 >> ( V_145 + V_53 ) ) & 1 ) == 0 )
return false ;
V_12 [ 1 ] =
F_1 ( V_145 + V_53 ) |
F_1 ( V_146 + V_53 ) |
F_1 ( V_73 + V_53 ) ;
F_13 ( V_69 + V_37 , V_12 , V_144 ) ;
F_9 ( & V_13 . V_17 -> V_81 , F_1 ( V_37 ) ) ;
return true ;
}
static void F_43 ( struct V_90 * V_91 , T_2 V_37 , T_3 V_56 )
{
F_32 ( & V_91 -> V_96 ) ;
V_91 -> V_20 = V_37 ;
V_91 -> V_56 = V_56 ;
V_91 -> V_108 = 0 ;
V_91 -> V_147 = 0 ;
}
static void F_44 ( struct V_90 * V_91 , T_2 V_37 , T_3 V_108 )
{
F_32 ( & V_91 -> V_96 ) ;
V_91 -> V_20 = V_37 ;
V_91 -> V_56 = 0 ;
V_91 -> V_108 = V_108 ;
V_91 -> V_147 = 0 ;
}
static void F_45 ( struct V_90 * V_91 , T_2 V_37 )
{
F_32 ( & V_91 -> V_96 ) ;
V_91 -> V_20 = V_37 ;
V_91 -> V_56 = 0 ;
V_91 -> V_108 = 0 ;
V_91 -> V_147 = 0 ;
}
static bool F_46 ( struct V_90 * V_91 )
{
struct V_95 * const V_96 = & V_91 -> V_96 ;
if ( ! F_42 ( V_91 -> V_20 , V_96 -> V_100 ) )
return false ;
V_96 -> V_100 ^= 1 ;
V_96 -> V_97 ++ ;
return true ;
}
static bool F_47 ( struct V_90 * V_91 , T_1 V_70 , T_3 V_112 )
{
struct V_95 * const V_96 = & V_91 -> V_96 ;
if ( V_112 <= 0 )
return F_2 ( V_148 , L_1 ) ;
if ( V_91 -> V_56 == 0 && V_91 -> V_108 == 0 &&
V_112 != F_36 ( V_112 ) )
return F_2 ( V_148 ,
L_2 ) ;
if ( V_91 -> V_56 &&
V_112 != F_37 ( V_112 , V_91 -> V_56 ) )
return F_2 ( V_148 ,
L_3 ) ;
if ( V_91 -> V_108 &&
V_112 != F_38 ( V_112 , V_91 -> V_108 ) )
return F_2 ( V_148 ,
L_4 ) ;
if ( V_96 -> V_101 >= 2u )
return F_2 ( V_149 , L_5 ) ;
++ V_96 -> V_101 ;
if ( V_91 -> V_20 == V_13 . V_84 . V_37 )
F_30 ( V_112 ) ;
if ( V_91 -> V_56 || V_91 -> V_108 )
F_24 ( V_91 -> V_20 , V_96 -> V_99 , V_70 , V_112 ) ;
else
F_23 ( V_91 -> V_20 , V_96 -> V_99 , V_70 ,
V_112 ) ;
V_96 -> V_99 ^= 1 ;
return true ;
}
static T_2 F_48 ( struct V_90 * V_91 )
{
struct V_95 * const V_96 = & V_91 -> V_96 ;
if ( V_96 -> V_98 != V_96 -> V_97 ) {
V_96 -> V_98 ++ ;
if ( V_96 -> V_101 == 0 )
return V_150 ;
-- V_96 -> V_101 ;
V_91 -> V_147 ++ ;
}
return V_151 ;
}
static bool F_49 ( struct V_90 * V_91 , T_3 V_152 )
{
if ( V_152 > V_91 -> V_147 )
return F_2 ( V_150 , L_6 ) ;
V_91 -> V_147 -= V_152 ;
return true ;
}
T_2 F_50 ( struct V_153 T_4 * V_154 , T_1 V_121 ,
T_1 V_110 )
{
V_13 . V_155 = false ;
if ( ! V_154 )
return V_156 ;
if ( V_121 >= 8 )
return V_157 ;
if ( V_110 > V_158 )
return V_157 ;
V_13 . V_17 = V_154 ;
V_13 . V_110 = V_110 ;
V_13 . V_14 [ 0 ] = 0 ;
V_13 . V_14 [ 1 ] = 0 ;
F_40 ( V_121 >= 3 , V_121 ) ;
V_13 . V_155 = true ;
return V_151 ;
}
void F_51 ( void )
{
V_13 . V_155 = false ;
F_39 () ;
}
bool F_52 ( void )
{
return F_41 () ;
}
static T_2 F_53 ( struct V_90 * V_91 , T_2 type , T_2 V_77 ,
T_3 V_102 , T_3 V_55 )
{
if ( ! V_13 . V_155 || ! V_91 )
return V_159 ;
if ( ! F_33 ( V_102 ) )
return V_160 ;
V_91 -> V_83 = F_54 ( V_55 , V_6 ) ;
V_91 -> V_161 = F_5 ( V_91 -> V_83 ) ;
if ( V_91 -> V_161 >= V_9 )
return V_162 ;
F_45 ( V_91 , V_102 / 2 ) ;
F_26 ( V_91 -> V_20 , type , V_77 ,
V_91 -> V_161 , V_91 -> V_83 , 0 ) ;
return V_151 ;
}
void F_55 ( void )
{
F_9 ( & V_13 . V_17 -> V_163 , 0 ) ;
F_9 ( & V_13 . V_17 -> V_164 , 0 ) ;
}
T_3 F_56 ( T_3 V_112 )
{
return F_36 ( V_112 ) ;
}
T_3 F_57 ( T_3 V_112 , T_3 V_56 )
{
if ( ! F_34 ( V_56 ) )
return 0 ;
return F_37 ( V_112 , V_56 ) ;
}
T_3 F_58 ( T_3 V_112 , T_3 V_108 )
{
if ( ! F_35 ( V_108 ) )
return 0 ;
return F_38 ( V_112 , V_108 ) ;
}
T_2 F_59 ( struct V_90 * V_91 , T_2 V_77 , T_3 V_102 ,
T_3 V_165 )
{
return F_53 ( V_91 , V_166 , V_77 , V_102 ,
V_165 ) ;
}
T_2 F_60 ( struct V_90 * V_91 , T_2 V_77 , T_3 V_102 ,
T_3 V_165 )
{
T_2 V_167 = F_53 ( V_91 , V_168 , V_77 , V_102 ,
V_165 ) ;
if ( V_77 && ! V_13 . V_84 . V_37 ) {
V_13 . V_84 . V_37 = V_91 -> V_20 ;
F_29 ( V_91 -> V_20 , V_91 -> V_83 ) ;
F_9 ( & V_13 . V_17 -> V_117 , F_1 ( 20 ) ) ;
}
return V_167 ;
}
T_2 F_61 ( struct V_90 * V_91 , T_2 V_77 , T_3 V_102 ,
T_3 V_56 )
{
if ( ! V_13 . V_155 || ! V_91 )
return V_159 ;
if ( ! F_33 ( V_102 ) )
return V_160 ;
if ( ! F_34 ( V_56 ) )
return V_169 ;
V_91 -> V_83 = V_56 * V_106 ;
V_91 -> V_161 = F_5 ( V_91 -> V_83 ) ;
if ( V_91 -> V_161 >= V_9 )
return V_162 ;
F_43 ( V_91 , V_102 / 2 , V_56 ) ;
F_26 ( V_91 -> V_20 , V_41 , V_77 , V_91 -> V_161 ,
V_91 -> V_83 , V_56 ) ;
return V_151 ;
}
T_2 F_62 ( struct V_90 * V_91 , T_2 V_77 , T_3 V_102 ,
T_3 V_108 )
{
T_3 V_109 = V_13 . V_110 + 2 ;
if ( ! V_13 . V_155 || ! V_91 )
return V_159 ;
if ( ! F_33 ( V_102 ) )
return V_160 ;
if ( ! F_35 ( V_108 ) )
return V_169 ;
V_91 -> V_83 = V_108 << V_109 ;
V_91 -> V_161 = F_5 ( V_91 -> V_83 ) ;
if ( V_91 -> V_161 >= V_9 )
return V_162 ;
F_44 ( V_91 , V_102 / 2 , V_108 ) ;
F_11 ( V_91 -> V_161 , V_91 -> V_83 ) ;
F_26 ( V_91 -> V_20 , V_43 , V_77 ,
V_91 -> V_161 , V_91 -> V_83 , 0 ) ;
return V_151 ;
}
T_2 F_63 ( struct V_90 * V_91 )
{
if ( ! V_13 . V_155 || ! V_91 )
return V_159 ;
if ( V_91 -> V_20 == V_13 . V_84 . V_37 ) {
F_9 ( & V_13 . V_17 -> V_117 , 0 ) ;
V_13 . V_84 . V_37 = 0 ;
}
F_27 ( V_91 -> V_20 ) ;
if ( V_91 -> V_161 < V_9 )
F_7 ( V_91 -> V_161 , V_91 -> V_83 ) ;
V_91 -> V_161 = V_9 ;
return V_151 ;
}
void F_64 ( struct V_90 * const * V_170 )
{
bool V_171 ;
if ( ! V_13 . V_155 ) {
F_2 ( V_159 ,
L_7 ) ;
return;
}
if ( ! V_170 ) {
F_2 ( V_159 , L_8 ) ;
return;
}
do {
struct V_90 * const * V_91 = V_170 ;
V_171 = false ;
while ( * V_91 ) {
V_171 |= F_46 ( * V_91 ) ;
++ V_91 ;
}
} while ( V_171 );
}
T_2 F_65 ( struct V_90 * V_91 )
{
if ( ! V_13 . V_155 || ! V_91 )
return V_159 ;
return F_48 ( V_91 ) ;
}
struct V_172 * F_66 ( struct V_90 * V_91 ,
struct V_172 * V_173 )
{
if ( ! V_91 || ! V_173 )
return NULL ;
V_173 -> V_174 = V_91 -> V_96 . V_101 < 2 ;
V_173 -> V_175 = V_91 -> V_147 ;
return V_173 ;
}
bool F_67 ( struct V_90 * V_91 , T_1 V_176 ,
T_3 V_71 )
{
if ( ! V_91 )
return F_2 ( V_159 ,
L_9 ) ;
return F_47 ( V_91 , V_176 , V_71 ) ;
}
bool F_68 ( struct V_90 * V_91 , T_3 V_152 )
{
if ( ! V_91 )
return F_2 ( V_159 ,
L_9 ) ;
return F_49 ( V_91 , V_152 ) ;
}
