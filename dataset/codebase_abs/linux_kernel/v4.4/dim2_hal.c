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
T_1 const V_11 = ( V_4 + V_6 - 1 ) / V_6 ;
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
static void F_6 ( int V_15 , int V_4 )
{
int V_8 = V_15 / V_6 ;
T_1 const V_11 = ( V_4 + V_6 - 1 ) / V_6 ;
T_1 V_12 = ~ ( ( ~ ( T_1 ) 0 ) << V_11 ) ;
V_12 <<= V_8 % 32 ;
V_13 . V_14 [ V_8 / 32 ] &= ~ V_12 ;
}
static T_1 F_7 ( T_1 V_16 , T_3 V_17 )
{
F_8 ( & V_13 . V_18 -> V_19 , V_16 ) ;
while ( ( F_9 ( & V_13 . V_18 -> V_20 ) & 1 ) != 1 )
continue;
F_8 ( & V_13 . V_18 -> V_20 , 0 ) ;
return F_9 ( ( & V_13 . V_18 -> V_21 ) + V_17 ) ;
}
static void F_10 ( T_1 V_16 , const T_1 * V_12 , const T_1 * V_22 )
{
enum { V_23 = 31 };
F_8 ( & V_13 . V_18 -> V_20 , 0 ) ;
if ( V_12 [ 0 ] != 0 )
F_8 ( & V_13 . V_18 -> V_21 , V_22 [ 0 ] ) ;
if ( V_12 [ 1 ] != 0 )
F_8 ( & V_13 . V_18 -> V_24 , V_22 [ 1 ] ) ;
if ( V_12 [ 2 ] != 0 )
F_8 ( & V_13 . V_18 -> V_25 , V_22 [ 2 ] ) ;
if ( V_12 [ 3 ] != 0 )
F_8 ( & V_13 . V_18 -> V_26 , V_22 [ 3 ] ) ;
F_8 ( & V_13 . V_18 -> V_27 , V_12 [ 0 ] ) ;
F_8 ( & V_13 . V_18 -> V_28 , V_12 [ 1 ] ) ;
F_8 ( & V_13 . V_18 -> V_29 , V_12 [ 2 ] ) ;
F_8 ( & V_13 . V_18 -> V_30 , V_12 [ 3 ] ) ;
F_8 ( & V_13 . V_18 -> V_19 , F_1 ( V_23 ) | V_16 ) ;
while ( ( F_9 ( & V_13 . V_18 -> V_20 ) & 1 ) != 1 )
continue;
F_8 ( & V_13 . V_18 -> V_20 , 0 ) ;
}
static inline void F_11 ( T_1 V_16 , const T_1 * V_22 )
{
T_1 const V_12 [ 4 ] = { 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF } ;
F_10 ( V_16 , V_12 , V_22 ) ;
}
static inline void F_12 ( T_1 V_16 )
{
T_1 const V_22 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_11 ( V_16 , V_22 ) ;
}
static void F_13 ( T_2 V_31 , T_2 V_32 , T_2 V_33 ,
bool V_34 , bool V_35 )
{
T_3 const V_36 =
( V_34 << V_37 ) |
( V_33 << V_38 ) |
( V_32 << V_39 ) |
( V_35 << V_40 ) |
( false << V_41 ) |
( true << V_42 ) ;
T_2 const V_16 = V_31 + V_32 / 8 ;
T_2 const V_43 = ( V_32 % 8 ) / 2 ;
T_2 const V_44 = ( V_32 % 2 ) * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_22 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ V_43 ] = ( T_1 ) 0xFFFF << V_44 ;
V_22 [ V_43 ] = V_36 << V_44 ;
F_10 ( V_16 , V_12 , V_22 ) ;
}
static void F_14 ( T_2 V_31 , T_2 V_32 )
{
T_2 const V_16 = V_31 + V_32 / 8 ;
T_2 const V_43 = ( V_32 % 8 ) / 2 ;
T_2 const V_44 = ( V_32 % 2 ) * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_22 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ V_43 ] = ( T_1 ) 0xFFFF << V_44 ;
F_10 ( V_16 , V_12 , V_22 ) ;
}
static void F_15 ( T_2 V_32 , T_3 V_45 , T_3 V_46 ,
T_3 V_47 )
{
T_1 V_48 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( V_47 )
V_48 [ 1 ] = ( ( V_47 - 1 ) << V_49 ) ;
V_48 [ 3 ] =
( ( V_46 - 1 ) << V_50 ) |
( V_45 << V_51 ) ;
F_11 ( V_52 + V_32 , V_48 ) ;
}
static void F_16 ( T_2 V_32 )
{
T_1 V_48 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_11 ( V_52 + V_32 , V_48 ) ;
}
static void F_17 ( T_2 V_32 )
{
T_1 V_53 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_53 [ 0 ] =
( true << V_54 ) |
( true << V_55 ) |
( 0 << V_56 ) ;
F_11 ( V_57 + V_32 , V_53 ) ;
}
static void F_18 ( T_2 V_32 )
{
T_1 V_53 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_11 ( V_57 + V_32 , V_53 ) ;
}
static void F_19 ( T_2 V_32 , T_2 V_43 , T_1 V_58 ,
T_3 V_59 )
{
T_2 const V_44 = V_43 * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_53 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ 1 ] =
F_1 ( V_60 + V_44 ) |
F_1 ( V_61 + V_44 ) |
( V_62 << ( V_63 + V_44 ) ) ;
V_53 [ 1 ] =
( true << ( V_60 + V_44 ) ) |
( true << ( V_61 + V_44 ) ) |
( ( V_59 - 1 ) << ( V_63 + V_44 ) ) ;
V_12 [ V_43 + 2 ] = 0xFFFFFFFF ;
V_53 [ V_43 + 2 ] = V_58 ;
F_10 ( V_57 + V_32 , V_12 , V_53 ) ;
}
static void F_20 ( T_2 V_32 , T_2 V_43 , T_1 V_58 ,
T_3 V_59 )
{
T_2 const V_44 = V_43 * 16 ;
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_53 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ 1 ] =
F_1 ( V_61 + V_44 ) |
( V_64 << ( V_63 + V_44 ) ) ;
V_53 [ 1 ] =
( true << ( V_61 + V_44 ) ) |
( ( V_59 - 1 ) << ( V_63 + V_44 ) ) ;
V_12 [ V_43 + 2 ] = 0xFFFFFFFF ;
V_53 [ V_43 + 2 ] = V_58 ;
F_10 ( V_57 + V_32 , V_12 , V_53 ) ;
}
static void F_21 ( void )
{
T_1 V_16 ;
for ( V_16 = 0 ; V_16 < 0x90 ; V_16 ++ )
F_12 ( V_16 ) ;
}
static void F_22 (
T_2 V_32 , T_2 type , T_2 V_65 , T_3 V_45 , T_3 V_46 ,
T_3 V_47 , bool V_35 )
{
F_15 ( V_32 , V_45 , V_46 , V_47 ) ;
F_13 ( V_66 , V_32 , type , V_65 ? 1 : 0 , V_35 ) ;
F_17 ( V_32 ) ;
F_13 ( V_67 , V_32 , type , V_65 ? 0 : 1 , V_35 ) ;
F_8 ( & V_13 . V_18 -> V_68 ,
F_9 ( & V_13 . V_18 -> V_68 ) | F_1 ( V_32 ) ) ;
}
static void F_23 ( T_2 V_32 )
{
F_8 ( & V_13 . V_18 -> V_68 ,
F_9 ( & V_13 . V_18 -> V_68 ) & ~ F_1 ( V_32 ) ) ;
F_14 ( V_67 , V_32 ) ;
F_18 ( V_32 ) ;
F_14 ( V_66 , V_32 ) ;
F_16 ( V_32 ) ;
}
static void F_24 ( struct V_69 * V_70 )
{
V_70 -> V_71 = 0 ;
V_70 -> V_72 = 0 ;
V_70 -> V_73 = 0 ;
V_70 -> V_74 = 0 ;
V_70 -> V_75 = 0 ;
}
static inline bool F_25 ( T_1 V_76 )
{
return V_76 > 0 && ( V_76 % 2 ) == 0 &&
( V_76 / 2 ) <= ( T_1 ) V_77 ;
}
static inline bool F_26 ( T_1 V_47 )
{
T_3 const V_78 = ( ( T_3 ) V_79 + 1u ) / V_80 ;
if ( V_47 <= 0 )
return false ;
if ( V_47 > V_78 )
return false ;
if ( V_47 - 1u > ( T_1 ) V_81 )
return false ;
return true ;
}
static inline bool F_27 ( T_1 V_82 )
{
T_3 const V_78 = ( ( T_3 ) V_83 + 1u ) / V_84 ;
if ( V_82 <= 0 )
return false ;
if ( V_82 > V_78 )
return false ;
return true ;
}
static inline T_3 F_28 ( T_3 V_85 )
{
T_3 const V_78 = ( T_3 ) V_62 + 1u ;
if ( V_85 > V_78 )
return V_78 ;
return V_85 ;
}
static inline T_3 F_29 ( T_3 V_85 , T_3 V_47 )
{
T_3 V_86 ;
T_3 const V_78 = ( T_3 ) V_64 + 1u ;
if ( V_85 > V_78 )
V_85 = V_78 ;
V_86 = V_85 / V_47 ;
if ( V_86 < 2u )
return 0 ;
return V_47 * V_86 ;
}
static inline T_3 F_30 ( T_3 V_85 , T_3 V_82 )
{
T_3 V_86 ;
T_3 const V_78 = ( T_3 ) V_64 + 1u ;
T_1 const V_87 = V_82 * ( T_3 ) V_88 ;
if ( V_85 > V_78 )
V_85 = V_78 ;
V_86 = V_85 / V_87 ;
if ( V_86 < 1u )
return 0 ;
return V_87 * V_86 ;
}
static void F_31 ( void )
{
F_8 ( & V_13 . V_18 -> V_89 , false << V_90 ) ;
F_21 () ;
F_8 ( & V_13 . V_18 -> V_91 , 0 ) ;
F_8 ( & V_13 . V_18 -> V_92 , 0xFFFFFFFF ) ;
F_8 ( & V_13 . V_18 -> V_93 , 0xFFFFFFFF ) ;
F_8 ( & V_13 . V_18 -> V_68 , 0 ) ;
F_8 ( & V_13 . V_18 -> V_94 , 0 ) ;
}
static void F_32 ( bool V_95 , T_2 V_96 )
{
F_31 () ;
F_8 ( & V_13 . V_18 -> V_89 ,
V_95 << V_97 |
V_96 << V_98 |
F_33 ( V_88 ) << V_99 |
true << V_90 ) ;
F_8 ( & V_13 . V_18 -> V_100 , 0xFFFFFFFF ) ;
F_8 ( & V_13 . V_18 -> V_101 , 0xFFFFFFFF ) ;
F_8 ( & V_13 . V_18 -> V_102 , F_1 ( V_103 ) ) ;
F_8 ( & V_13 . V_18 -> V_104 ,
V_105 << V_106 |
true << V_107 ) ;
}
static bool F_34 ( void )
{
T_1 const V_108 = F_1 ( V_109 ) ;
T_1 const V_110 = F_1 ( V_111 ) |
F_1 ( V_112 ) ;
T_1 const V_113 = F_9 ( & V_13 . V_18 -> V_114 ) ;
T_1 const V_115 = ( T_1 ) V_116 << V_117 ;
F_8 ( & V_13 . V_18 -> V_114 , V_113 & V_115 ) ;
return ( F_9 ( & V_13 . V_18 -> V_114 ) & V_110 ) == 0 &&
( F_9 ( & V_13 . V_18 -> V_89 ) & V_108 ) != 0 ;
}
static inline bool F_35 ( T_2 V_32 , T_2 V_43 )
{
T_2 const V_44 = V_43 * 16 ;
T_1 const V_118 = F_7 ( V_57 + V_32 , 1 ) ;
if ( ( ( V_118 >> ( V_119 + V_44 ) ) & 1 ) == 0 )
return false ;
{
T_1 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_120 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_12 [ 1 ] =
F_1 ( V_119 + V_44 ) |
F_1 ( V_121 + V_44 ) |
F_1 ( V_61 + V_44 ) ;
F_10 ( V_57 + V_32 , V_12 , V_120 ) ;
}
F_8 ( & V_13 . V_18 -> V_92 , F_1 ( V_32 ) ) ;
return true ;
}
static void F_36 ( struct V_122 * V_123 , T_2 V_32 , T_3 V_47 )
{
F_24 ( & V_123 -> V_70 ) ;
V_123 -> V_124 = V_32 ;
V_123 -> V_47 = V_47 ;
V_123 -> V_82 = 0 ;
V_123 -> V_125 = 0 ;
}
static void F_37 ( struct V_122 * V_123 , T_2 V_32 , T_3 V_82 )
{
F_24 ( & V_123 -> V_70 ) ;
V_123 -> V_124 = V_32 ;
V_123 -> V_47 = 0 ;
V_123 -> V_82 = V_82 ;
V_123 -> V_125 = 0 ;
}
static void F_38 ( struct V_122 * V_123 , T_2 V_32 )
{
F_24 ( & V_123 -> V_70 ) ;
V_123 -> V_124 = V_32 ;
V_123 -> V_47 = 0 ;
V_123 -> V_82 = 0 ;
V_123 -> V_125 = 0 ;
}
static bool F_39 ( struct V_122 * V_123 )
{
struct V_69 * const V_70 = & V_123 -> V_70 ;
if ( ! F_35 ( V_123 -> V_124 , V_70 -> V_74 ) )
return false ;
V_70 -> V_74 ^= 1 ;
V_70 -> V_71 ++ ;
return true ;
}
static bool F_40 ( struct V_122 * V_123 , T_1 V_58 , T_3 V_85 )
{
struct V_69 * const V_70 = & V_123 -> V_70 ;
if ( V_85 <= 0 )
return F_2 ( V_126 , L_1 ) ;
if ( V_123 -> V_47 == 0 && V_123 -> V_82 == 0 &&
V_85 != F_28 ( V_85 ) )
return F_2 ( V_126 ,
L_2 ) ;
if ( V_123 -> V_47 &&
V_85 != F_29 ( V_85 , V_123 -> V_47 ) )
return F_2 ( V_126 ,
L_3 ) ;
if ( V_123 -> V_82 &&
V_85 != F_30 ( V_85 , V_123 -> V_82 ) )
return F_2 ( V_126 ,
L_4 ) ;
if ( V_70 -> V_75 >= 2u )
return F_2 ( V_127 , L_5 ) ;
++ V_70 -> V_75 ;
if ( V_123 -> V_47 || V_123 -> V_82 )
F_20 ( V_123 -> V_124 , V_70 -> V_73 , V_58 , V_85 ) ;
else
F_19 ( V_123 -> V_124 , V_70 -> V_73 , V_58 ,
V_85 ) ;
V_70 -> V_73 ^= 1 ;
return true ;
}
static T_2 F_41 ( struct V_122 * V_123 )
{
struct V_69 * const V_70 = & V_123 -> V_70 ;
if ( V_70 -> V_72 != V_70 -> V_71 ) {
V_70 -> V_72 ++ ;
if ( V_70 -> V_75 == 0 )
return V_128 ;
-- V_70 -> V_75 ;
V_123 -> V_125 ++ ;
}
return V_129 ;
}
static bool F_42 ( struct V_122 * V_123 , T_3 V_130 )
{
if ( V_130 > V_123 -> V_125 )
return F_2 ( V_128 , L_6 ) ;
V_123 -> V_125 -= V_130 ;
return true ;
}
T_2 F_43 ( void * V_131 , T_1 V_96 )
{
V_13 . V_132 = false ;
if ( ! V_131 )
return V_133 ;
if ( V_96 >= 8 )
return V_134 ;
V_13 . V_18 = V_131 ;
V_13 . V_14 [ 0 ] = 0 ;
V_13 . V_14 [ 1 ] = 0 ;
F_32 ( V_96 >= 3 , V_96 ) ;
V_13 . V_132 = true ;
return V_129 ;
}
void F_44 ( void )
{
V_13 . V_132 = false ;
F_31 () ;
}
bool F_45 ( void )
{
return F_34 () ;
}
static T_2 F_46 ( struct V_122 * V_123 , T_2 type , T_2 V_65 ,
T_3 V_76 , T_3 V_46 )
{
if ( ! V_13 . V_132 || ! V_123 )
return V_135 ;
if ( ! F_25 ( V_76 ) )
return V_136 ;
V_123 -> V_137 = V_46 ;
V_123 -> V_138 = F_5 ( V_123 -> V_137 ) ;
if ( V_123 -> V_138 >= V_9 )
return V_139 ;
F_38 ( V_123 , V_76 / 2 ) ;
F_22 ( V_123 -> V_124 , type , V_65 ,
V_123 -> V_138 , V_123 -> V_137 , 0 , false ) ;
return V_129 ;
}
T_3 F_47 ( T_3 V_85 )
{
return F_28 ( V_85 ) ;
}
T_3 F_48 ( T_3 V_85 , T_3 V_47 )
{
if ( ! F_26 ( V_47 ) )
return 0 ;
return F_29 ( V_85 , V_47 ) ;
}
T_3 F_49 ( T_3 V_85 , T_3 V_82 )
{
if ( ! F_27 ( V_82 ) )
return 0 ;
return F_30 ( V_85 , V_82 ) ;
}
T_2 F_50 ( struct V_122 * V_123 , T_2 V_65 , T_3 V_76 ,
T_3 V_140 )
{
return F_46 ( V_123 , V_141 , V_65 , V_76 ,
V_140 ) ;
}
T_2 F_51 ( struct V_122 * V_123 , T_2 V_65 , T_3 V_76 ,
T_3 V_140 )
{
return F_46 ( V_123 , V_142 , V_65 , V_76 ,
V_140 ) ;
}
T_2 F_52 ( struct V_122 * V_123 , T_2 V_65 , T_3 V_76 ,
T_3 V_47 )
{
if ( ! V_13 . V_132 || ! V_123 )
return V_135 ;
if ( ! F_25 ( V_76 ) )
return V_136 ;
if ( ! F_26 ( V_47 ) )
return V_143 ;
V_123 -> V_137 = V_47 * V_80 ;
V_123 -> V_138 = F_5 ( V_123 -> V_137 ) ;
if ( V_123 -> V_138 >= V_9 )
return V_139 ;
F_36 ( V_123 , V_76 / 2 , V_47 ) ;
F_22 ( V_123 -> V_124 , V_144 , V_65 , V_123 -> V_138 ,
V_123 -> V_137 , V_47 , false ) ;
return V_129 ;
}
T_2 F_53 ( struct V_122 * V_123 , T_2 V_65 , T_3 V_76 ,
T_3 V_82 )
{
if ( ! V_13 . V_132 || ! V_123 )
return V_135 ;
if ( ! F_25 ( V_76 ) )
return V_136 ;
if ( ! F_27 ( V_82 ) )
return V_143 ;
V_123 -> V_137 = V_82 * V_84 ;
V_123 -> V_138 = F_5 ( V_123 -> V_137 ) ;
if ( V_123 -> V_138 >= V_9 )
return V_139 ;
F_37 ( V_123 , V_76 / 2 , V_82 ) ;
F_22 ( V_123 -> V_124 , V_145 , V_65 ,
V_123 -> V_138 , V_123 -> V_137 , 0 , true ) ;
return V_129 ;
}
T_2 F_54 ( struct V_122 * V_123 )
{
if ( ! V_13 . V_132 || ! V_123 )
return V_135 ;
F_23 ( V_123 -> V_124 ) ;
if ( V_123 -> V_138 < V_9 )
F_6 ( V_123 -> V_138 , V_123 -> V_137 ) ;
V_123 -> V_138 = V_9 ;
return V_129 ;
}
void F_55 ( struct V_122 * const * V_146 )
{
bool V_147 ;
if ( ! V_13 . V_132 ) {
F_2 ( V_135 ,
L_7 ) ;
return;
}
if ( ! V_146 ) {
F_2 ( V_135 , L_8 ) ;
return;
}
do {
struct V_122 * const * V_123 = V_146 ;
V_147 = false ;
while ( * V_123 ) {
V_147 |= F_39 ( * V_123 ) ;
++ V_123 ;
}
} while ( V_147 );
F_8 ( & V_13 . V_18 -> V_148 , 0 ) ;
F_8 ( & V_13 . V_18 -> V_149 , 0 ) ;
}
T_2 F_56 ( struct V_122 * V_123 )
{
if ( ! V_13 . V_132 || ! V_123 )
return V_135 ;
return F_41 ( V_123 ) ;
}
struct V_150 * F_57 ( struct V_122 * V_123 ,
struct V_150 * V_151 )
{
if ( ! V_123 || ! V_151 )
return NULL ;
V_151 -> V_152 = V_123 -> V_70 . V_75 < 2 ;
V_151 -> V_153 = V_123 -> V_125 ;
return V_151 ;
}
bool F_58 ( struct V_122 * V_123 , T_1 V_154 , T_3 V_59 )
{
if ( ! V_123 )
return F_2 ( V_135 ,
L_9 ) ;
return F_40 ( V_123 , V_154 , V_59 ) ;
}
bool F_59 ( struct V_122 * V_123 , T_3 V_130 )
{
if ( ! V_123 )
return F_2 ( V_135 ,
L_9 ) ;
return F_42 ( V_123 , V_130 ) ;
}
