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
bool V_39 , bool V_40 )
{
T_3 const V_41 =
( V_39 << V_42 ) |
( V_38 << V_43 ) |
( V_37 << V_44 ) |
( V_40 << V_45 ) |
( false << V_46 ) |
( true << V_47 ) ;
T_2 const V_26 = V_36 + V_37 / 8 ;
T_2 const V_48 = ( V_37 % 8 ) / 2 ;
T_2 const V_49 = ( V_37 % 2 ) * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_28 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ V_48 ] = ( T_1 ) 0xFFFF << V_49 ;
V_28 [ V_48 ] = V_41 << V_49 ;
F_13 ( V_26 , V_12 , V_28 ) ;
}
static void F_17 ( T_2 V_36 , T_2 V_37 )
{
T_2 const V_26 = V_36 + V_37 / 8 ;
T_2 const V_48 = ( V_37 % 8 ) / 2 ;
T_2 const V_49 = ( V_37 % 2 ) * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_28 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ V_48 ] = ( T_1 ) 0xFFFF << V_49 ;
F_13 ( V_26 , V_12 , V_28 ) ;
}
static void F_18 ( T_2 V_37 , T_3 V_50 , T_3 V_51 ,
T_3 V_52 )
{
T_1 V_53 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( V_52 )
V_53 [ 1 ] = ( ( V_52 - 1 ) << V_54 ) ;
V_53 [ 3 ] =
( ( V_51 - 1 ) << V_55 ) |
( V_50 << V_56 ) ;
F_14 ( V_57 + V_37 , V_53 ) ;
}
static T_3 F_19 ( T_2 V_37 )
{
T_1 V_58 = F_12 ( V_57 + V_37 , 0 ) ;
return ( V_58 >> V_59 ) & V_60 ;
}
static void F_20 ( T_2 V_37 )
{
T_1 V_53 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_14 ( V_57 + V_37 , V_53 ) ;
}
static void F_21 ( T_2 V_37 )
{
T_1 V_61 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_61 [ 0 ] =
( true << V_62 ) |
( true << V_63 ) |
( 0 << V_64 ) ;
F_14 ( V_65 + V_37 , V_61 ) ;
}
static void F_22 ( T_2 V_37 )
{
T_1 V_61 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_14 ( V_65 + V_37 , V_61 ) ;
}
static void F_23 ( T_2 V_37 , T_2 V_48 , T_1 V_66 ,
T_3 V_67 )
{
T_2 const V_49 = V_48 * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_61 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ 1 ] =
F_1 ( V_68 + V_49 ) |
F_1 ( V_69 + V_49 ) |
( V_70 << ( V_71 + V_49 ) ) ;
V_61 [ 1 ] =
( true << ( V_68 + V_49 ) ) |
( true << ( V_69 + V_49 ) ) |
( ( V_67 - 1 ) << ( V_71 + V_49 ) ) ;
V_12 [ V_48 + 2 ] = 0xFFFFFFFF ;
V_61 [ V_48 + 2 ] = V_66 ;
F_13 ( V_65 + V_37 , V_12 , V_61 ) ;
}
static void F_24 ( T_2 V_37 , T_2 V_48 , T_1 V_66 ,
T_3 V_67 )
{
T_2 const V_49 = V_48 * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_61 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ 1 ] =
F_1 ( V_69 + V_49 ) |
( V_72 << ( V_71 + V_49 ) ) ;
V_61 [ 1 ] =
( true << ( V_69 + V_49 ) ) |
( ( V_67 - 1 ) << ( V_71 + V_49 ) ) ;
V_12 [ V_48 + 2 ] = 0xFFFFFFFF ;
V_61 [ V_48 + 2 ] = V_66 ;
F_13 ( V_65 + V_37 , V_12 , V_61 ) ;
}
static void F_25 ( void )
{
T_1 V_26 ;
for ( V_26 = 0 ; V_26 < 0x90 ; V_26 ++ )
F_15 ( V_26 ) ;
}
static void F_26 (
T_2 V_37 , T_2 type , T_2 V_73 , T_3 V_50 , T_3 V_51 ,
T_3 V_52 , bool V_40 )
{
F_18 ( V_37 , V_50 , V_51 , V_52 ) ;
F_16 ( V_74 , V_37 , type , V_73 ? 1 : 0 , V_40 ) ;
F_21 ( V_37 ) ;
F_16 ( V_75 , V_37 , type , V_73 ? 0 : 1 , V_40 ) ;
F_9 ( & V_13 . V_17 -> V_76 ,
F_10 ( & V_13 . V_17 -> V_76 ) | F_1 ( V_37 ) ) ;
}
static void F_27 ( T_2 V_37 )
{
F_9 ( & V_13 . V_17 -> V_76 ,
F_10 ( & V_13 . V_17 -> V_76 ) & ~ F_1 ( V_37 ) ) ;
F_17 ( V_75 , V_37 ) ;
F_22 ( V_37 ) ;
F_17 ( V_74 , V_37 ) ;
F_20 ( V_37 ) ;
F_9 ( & V_13 . V_17 -> V_77 , F_1 ( V_37 ) ) ;
}
static inline T_3 F_28 ( T_3 V_78 )
{
return V_78 & V_60 ;
}
static void F_29 ( T_2 V_37 , T_3 V_79 )
{
V_13 . V_80 . V_81 = V_79 ;
V_13 . V_80 . V_82 = F_19 ( V_37 ) ;
V_13 . V_80 . V_83 = V_13 . V_80 . V_82 ;
}
static void F_30 ( int V_84 )
{
V_13 . V_80 . V_81 -= V_84 ;
V_13 . V_80 . V_85 [ F_28 ( V_13 . V_80 . V_83 ) ] = V_84 ;
V_13 . V_80 . V_83 ++ ;
}
T_3 F_31 ( struct V_86 * V_87 )
{
T_3 V_88 ;
struct V_89 * V_90 = & V_13 . V_80 ;
if ( V_87 -> V_20 != V_90 -> V_37 )
return 0xFFFF ;
V_88 = F_19 ( V_87 -> V_20 ) ;
while ( F_28 ( V_90 -> V_82 ) != V_88 ) {
V_90 -> V_81 += V_90 -> V_85 [ F_28 ( V_90 -> V_82 ) ] ;
V_90 -> V_82 ++ ;
}
if ( ( T_3 ) ( V_90 -> V_83 - V_90 -> V_82 ) >= V_60 )
return 0 ;
return V_90 -> V_81 ;
}
static void F_32 ( struct V_91 * V_92 )
{
V_92 -> V_93 = 0 ;
V_92 -> V_94 = 0 ;
V_92 -> V_95 = 0 ;
V_92 -> V_96 = 0 ;
V_92 -> V_97 = 0 ;
}
static inline bool F_33 ( T_1 V_98 )
{
return V_98 > 0 && ( V_98 % 2 ) == 0 &&
( V_98 / 2 ) <= ( T_1 ) V_99 ;
}
static inline bool F_34 ( T_1 V_52 )
{
T_3 const V_100 = ( ( T_3 ) V_101 + 1u ) / V_102 ;
if ( V_52 <= 0 )
return false ;
if ( V_52 > V_100 )
return false ;
if ( V_52 - 1u > ( T_1 ) V_103 )
return false ;
return true ;
}
static inline bool F_35 ( T_1 V_104 )
{
T_3 const V_105 = V_13 . V_106 + 2 ;
T_3 const V_100 = ( ( T_3 ) V_107 + 1u ) >> V_105 ;
if ( V_104 <= 0 )
return false ;
if ( V_104 > V_100 )
return false ;
return true ;
}
static inline T_3 F_36 ( T_3 V_108 )
{
T_3 const V_100 = ( T_3 ) V_70 + 1u ;
if ( V_108 > V_100 )
return V_100 ;
return V_108 ;
}
static inline T_3 F_37 ( T_3 V_108 , T_3 V_52 )
{
T_3 V_109 ;
T_3 const V_100 = ( T_3 ) V_72 + 1u ;
if ( V_108 > V_100 )
V_108 = V_100 ;
V_109 = V_108 / V_52 ;
if ( V_109 < 2u )
return 0 ;
return V_52 * V_109 ;
}
static inline T_3 F_38 ( T_3 V_108 , T_3 V_104 )
{
T_3 V_109 ;
T_3 const V_100 = ( T_3 ) V_72 + 1u ;
T_1 const V_110 = V_104 << V_13 . V_106 ;
if ( V_108 > V_100 )
V_108 = V_100 ;
V_109 = V_108 / V_110 ;
if ( V_109 < 1u )
return 0 ;
return V_110 * V_109 ;
}
static void F_39 ( void )
{
F_9 ( & V_13 . V_17 -> V_111 , false << V_112 ) ;
F_25 () ;
F_9 ( & V_13 . V_17 -> V_113 , 0 ) ;
F_9 ( & V_13 . V_17 -> V_77 , 0xFFFFFFFF ) ;
F_9 ( & V_13 . V_17 -> V_114 , 0xFFFFFFFF ) ;
F_9 ( & V_13 . V_17 -> V_76 , 0 ) ;
F_9 ( & V_13 . V_17 -> V_115 , 0 ) ;
}
static void F_40 ( bool V_116 , T_2 V_117 )
{
F_39 () ;
F_9 ( & V_13 . V_17 -> V_111 ,
V_116 << V_118 |
V_117 << V_119 |
V_13 . V_106 << V_120 |
true << V_112 ) ;
F_9 ( & V_13 . V_17 -> V_121 , 0xFFFFFFFF ) ;
F_9 ( & V_13 . V_17 -> V_122 , 0xFFFFFFFF ) ;
F_9 ( & V_13 . V_17 -> V_123 , F_1 ( V_124 ) ) ;
F_9 ( & V_13 . V_17 -> V_125 ,
V_126 << V_127 |
true << V_128 ) ;
}
static bool F_41 ( void )
{
T_1 const V_129 = F_1 ( V_130 ) ;
T_1 const V_131 = F_1 ( V_132 ) |
F_1 ( V_133 ) ;
T_1 const V_134 = F_10 ( & V_13 . V_17 -> V_135 ) ;
T_1 const V_136 = ( T_1 ) V_137 << V_138 ;
F_9 ( & V_13 . V_17 -> V_135 , V_134 & V_136 ) ;
return ( F_10 ( & V_13 . V_17 -> V_135 ) & V_131 ) == 0 &&
( F_10 ( & V_13 . V_17 -> V_111 ) & V_129 ) != 0 ;
}
static inline bool F_42 ( T_2 V_37 , T_2 V_48 )
{
T_2 const V_49 = V_48 * 16 ;
T_1 const V_139 = F_12 ( V_65 + V_37 , 1 ) ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_140 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ( ( V_139 >> ( V_141 + V_49 ) ) & 1 ) == 0 )
return false ;
V_12 [ 1 ] =
F_1 ( V_141 + V_49 ) |
F_1 ( V_142 + V_49 ) |
F_1 ( V_69 + V_49 ) ;
F_13 ( V_65 + V_37 , V_12 , V_140 ) ;
F_9 ( & V_13 . V_17 -> V_77 , F_1 ( V_37 ) ) ;
return true ;
}
static void F_43 ( struct V_86 * V_87 , T_2 V_37 , T_3 V_52 )
{
F_32 ( & V_87 -> V_92 ) ;
V_87 -> V_20 = V_37 ;
V_87 -> V_52 = V_52 ;
V_87 -> V_104 = 0 ;
V_87 -> V_143 = 0 ;
}
static void F_44 ( struct V_86 * V_87 , T_2 V_37 , T_3 V_104 )
{
F_32 ( & V_87 -> V_92 ) ;
V_87 -> V_20 = V_37 ;
V_87 -> V_52 = 0 ;
V_87 -> V_104 = V_104 ;
V_87 -> V_143 = 0 ;
}
static void F_45 ( struct V_86 * V_87 , T_2 V_37 )
{
F_32 ( & V_87 -> V_92 ) ;
V_87 -> V_20 = V_37 ;
V_87 -> V_52 = 0 ;
V_87 -> V_104 = 0 ;
V_87 -> V_143 = 0 ;
}
static bool F_46 ( struct V_86 * V_87 )
{
struct V_91 * const V_92 = & V_87 -> V_92 ;
if ( ! F_42 ( V_87 -> V_20 , V_92 -> V_96 ) )
return false ;
V_92 -> V_96 ^= 1 ;
V_92 -> V_93 ++ ;
return true ;
}
static bool F_47 ( struct V_86 * V_87 , T_1 V_66 , T_3 V_108 )
{
struct V_91 * const V_92 = & V_87 -> V_92 ;
if ( V_108 <= 0 )
return F_2 ( V_144 , L_1 ) ;
if ( V_87 -> V_52 == 0 && V_87 -> V_104 == 0 &&
V_108 != F_36 ( V_108 ) )
return F_2 ( V_144 ,
L_2 ) ;
if ( V_87 -> V_52 &&
V_108 != F_37 ( V_108 , V_87 -> V_52 ) )
return F_2 ( V_144 ,
L_3 ) ;
if ( V_87 -> V_104 &&
V_108 != F_38 ( V_108 , V_87 -> V_104 ) )
return F_2 ( V_144 ,
L_4 ) ;
if ( V_92 -> V_97 >= 2u )
return F_2 ( V_145 , L_5 ) ;
++ V_92 -> V_97 ;
if ( V_87 -> V_20 == V_13 . V_80 . V_37 )
F_30 ( V_108 ) ;
if ( V_87 -> V_52 || V_87 -> V_104 )
F_24 ( V_87 -> V_20 , V_92 -> V_95 , V_66 , V_108 ) ;
else
F_23 ( V_87 -> V_20 , V_92 -> V_95 , V_66 ,
V_108 ) ;
V_92 -> V_95 ^= 1 ;
return true ;
}
static T_2 F_48 ( struct V_86 * V_87 )
{
struct V_91 * const V_92 = & V_87 -> V_92 ;
if ( V_92 -> V_94 != V_92 -> V_93 ) {
V_92 -> V_94 ++ ;
if ( V_92 -> V_97 == 0 )
return V_146 ;
-- V_92 -> V_97 ;
V_87 -> V_143 ++ ;
}
return V_147 ;
}
static bool F_49 ( struct V_86 * V_87 , T_3 V_148 )
{
if ( V_148 > V_87 -> V_143 )
return F_2 ( V_146 , L_6 ) ;
V_87 -> V_143 -= V_148 ;
return true ;
}
T_2 F_50 ( struct V_149 T_4 * V_150 , T_1 V_117 ,
T_1 V_106 )
{
V_13 . V_151 = false ;
if ( ! V_150 )
return V_152 ;
if ( V_117 >= 8 )
return V_153 ;
if ( V_106 > V_154 )
return V_153 ;
V_13 . V_17 = V_150 ;
V_13 . V_106 = V_106 ;
V_13 . V_14 [ 0 ] = 0 ;
V_13 . V_14 [ 1 ] = 0 ;
F_40 ( V_117 >= 3 , V_117 ) ;
V_13 . V_151 = true ;
return V_147 ;
}
void F_51 ( void )
{
V_13 . V_151 = false ;
F_39 () ;
}
bool F_52 ( void )
{
return F_41 () ;
}
static T_2 F_53 ( struct V_86 * V_87 , T_2 type , T_2 V_73 ,
T_3 V_98 , T_3 V_51 )
{
if ( ! V_13 . V_151 || ! V_87 )
return V_155 ;
if ( ! F_33 ( V_98 ) )
return V_156 ;
V_87 -> V_79 = F_54 ( V_51 , V_6 ) ;
V_87 -> V_157 = F_5 ( V_87 -> V_79 ) ;
if ( V_87 -> V_157 >= V_9 )
return V_158 ;
F_45 ( V_87 , V_98 / 2 ) ;
F_26 ( V_87 -> V_20 , type , V_73 ,
V_87 -> V_157 , V_87 -> V_79 , 0 , false ) ;
return V_147 ;
}
void F_55 ( void )
{
F_9 ( & V_13 . V_17 -> V_159 , 0 ) ;
F_9 ( & V_13 . V_17 -> V_160 , 0 ) ;
}
T_3 F_56 ( T_3 V_108 )
{
return F_36 ( V_108 ) ;
}
T_3 F_57 ( T_3 V_108 , T_3 V_52 )
{
if ( ! F_34 ( V_52 ) )
return 0 ;
return F_37 ( V_108 , V_52 ) ;
}
T_3 F_58 ( T_3 V_108 , T_3 V_104 )
{
if ( ! F_35 ( V_104 ) )
return 0 ;
return F_38 ( V_108 , V_104 ) ;
}
T_2 F_59 ( struct V_86 * V_87 , T_2 V_73 , T_3 V_98 ,
T_3 V_161 )
{
return F_53 ( V_87 , V_162 , V_73 , V_98 ,
V_161 ) ;
}
T_2 F_60 ( struct V_86 * V_87 , T_2 V_73 , T_3 V_98 ,
T_3 V_161 )
{
T_2 V_163 = F_53 ( V_87 , V_164 , V_73 , V_98 ,
V_161 ) ;
if ( V_73 && ! V_13 . V_80 . V_37 ) {
V_13 . V_80 . V_37 = V_87 -> V_20 ;
F_29 ( V_87 -> V_20 , V_87 -> V_79 ) ;
F_9 ( & V_13 . V_17 -> V_113 , F_1 ( 20 ) ) ;
}
return V_163 ;
}
T_2 F_61 ( struct V_86 * V_87 , T_2 V_73 , T_3 V_98 ,
T_3 V_52 )
{
if ( ! V_13 . V_151 || ! V_87 )
return V_155 ;
if ( ! F_33 ( V_98 ) )
return V_156 ;
if ( ! F_34 ( V_52 ) )
return V_165 ;
V_87 -> V_79 = V_52 * V_102 ;
V_87 -> V_157 = F_5 ( V_87 -> V_79 ) ;
if ( V_87 -> V_157 >= V_9 )
return V_158 ;
F_43 ( V_87 , V_98 / 2 , V_52 ) ;
F_26 ( V_87 -> V_20 , V_166 , V_73 , V_87 -> V_157 ,
V_87 -> V_79 , V_52 , false ) ;
return V_147 ;
}
T_2 F_62 ( struct V_86 * V_87 , T_2 V_73 , T_3 V_98 ,
T_3 V_104 )
{
T_3 V_105 = V_13 . V_106 + 2 ;
if ( ! V_13 . V_151 || ! V_87 )
return V_155 ;
if ( ! F_33 ( V_98 ) )
return V_156 ;
if ( ! F_35 ( V_104 ) )
return V_165 ;
V_87 -> V_79 = V_104 << V_105 ;
V_87 -> V_157 = F_5 ( V_87 -> V_79 ) ;
if ( V_87 -> V_157 >= V_9 )
return V_158 ;
F_44 ( V_87 , V_98 / 2 , V_104 ) ;
F_11 ( V_87 -> V_157 , V_87 -> V_79 ) ;
F_26 ( V_87 -> V_20 , V_167 , V_73 ,
V_87 -> V_157 , V_87 -> V_79 , 0 , true ) ;
return V_147 ;
}
T_2 F_63 ( struct V_86 * V_87 )
{
if ( ! V_13 . V_151 || ! V_87 )
return V_155 ;
if ( V_87 -> V_20 == V_13 . V_80 . V_37 ) {
F_9 ( & V_13 . V_17 -> V_113 , 0 ) ;
V_13 . V_80 . V_37 = 0 ;
}
F_27 ( V_87 -> V_20 ) ;
if ( V_87 -> V_157 < V_9 )
F_7 ( V_87 -> V_157 , V_87 -> V_79 ) ;
V_87 -> V_157 = V_9 ;
return V_147 ;
}
void F_64 ( struct V_86 * const * V_168 )
{
bool V_169 ;
if ( ! V_13 . V_151 ) {
F_2 ( V_155 ,
L_7 ) ;
return;
}
if ( ! V_168 ) {
F_2 ( V_155 , L_8 ) ;
return;
}
do {
struct V_86 * const * V_87 = V_168 ;
V_169 = false ;
while ( * V_87 ) {
V_169 |= F_46 ( * V_87 ) ;
++ V_87 ;
}
} while ( V_169 );
}
T_2 F_65 ( struct V_86 * V_87 )
{
if ( ! V_13 . V_151 || ! V_87 )
return V_155 ;
return F_48 ( V_87 ) ;
}
struct V_170 * F_66 ( struct V_86 * V_87 ,
struct V_170 * V_171 )
{
if ( ! V_87 || ! V_171 )
return NULL ;
V_171 -> V_172 = V_87 -> V_92 . V_97 < 2 ;
V_171 -> V_173 = V_87 -> V_143 ;
return V_171 ;
}
bool F_67 ( struct V_86 * V_87 , T_1 V_174 ,
T_3 V_67 )
{
if ( ! V_87 )
return F_2 ( V_155 ,
L_9 ) ;
return F_47 ( V_87 , V_174 , V_67 ) ;
}
bool F_68 ( struct V_86 * V_87 , T_3 V_148 )
{
if ( ! V_87 )
return F_2 ( V_155 ,
L_9 ) ;
return F_49 ( V_87 , V_148 ) ;
}
