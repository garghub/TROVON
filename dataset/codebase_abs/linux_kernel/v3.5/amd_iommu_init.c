static inline void F_1 ( T_1 V_1 )
{
if ( V_1 > V_2 )
V_2 = V_1 ;
}
static inline unsigned long F_2 ( int V_3 )
{
unsigned V_4 = V_5 +
F_3 ( ( ( int ) V_2 + 1 ) * V_3 ) ;
return 1UL << V_4 ;
}
static T_2 F_4 ( struct V_6 * V_7 , T_1 V_8 , T_3 V_9 )
{
T_2 V_10 ;
F_5 ( V_7 -> V_11 , 0xf8 , ( V_9 | V_8 << 16 ) ) ;
F_6 ( V_7 -> V_11 , 0xfc , & V_10 ) ;
return V_10 ;
}
static void F_7 ( struct V_6 * V_7 , T_1 V_8 , T_3 V_9 , T_2 V_10 )
{
F_5 ( V_7 -> V_11 , 0xf8 , ( V_9 | V_8 << 16 | 1 << 31 ) ) ;
F_5 ( V_7 -> V_11 , 0xfc , V_10 ) ;
F_5 ( V_7 -> V_11 , 0xf8 , ( V_9 | V_8 << 16 ) ) ;
}
static T_2 F_8 ( struct V_6 * V_7 , T_3 V_9 )
{
T_2 V_10 ;
F_5 ( V_7 -> V_11 , 0xf0 , V_9 ) ;
F_6 ( V_7 -> V_11 , 0xf4 , & V_10 ) ;
return V_10 ;
}
static void F_9 ( struct V_6 * V_7 , T_3 V_9 , T_2 V_10 )
{
F_5 ( V_7 -> V_11 , 0xf0 , ( V_9 | 1 << 8 ) ) ;
F_5 ( V_7 -> V_11 , 0xf4 , V_10 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
T_4 V_12 = V_7 -> V_13 & V_14 ;
T_4 V_15 = ( V_12 + V_7 -> V_16 ) & V_14 ;
T_4 V_17 ;
if ( ! V_7 -> V_13 )
return;
V_17 = V_12 | V_18 ;
F_11 ( V_7 -> V_19 + V_20 ,
& V_17 , sizeof( V_17 ) ) ;
V_17 = V_15 ;
F_11 ( V_7 -> V_19 + V_21 ,
& V_17 , sizeof( V_17 ) ) ;
}
static void F_12 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_19 == NULL ) ;
V_17 = F_14 ( V_22 ) ;
V_17 |= ( V_23 >> 12 ) - 1 ;
F_11 ( V_7 -> V_19 + V_24 ,
& V_17 , sizeof( V_17 ) ) ;
}
static void F_15 ( struct V_6 * V_7 , T_3 V_25 )
{
T_2 V_26 ;
V_26 = F_16 ( V_7 -> V_19 + V_27 ) ;
V_26 |= ( 1 << V_25 ) ;
F_17 ( V_26 , V_7 -> V_19 + V_27 ) ;
}
static void F_18 ( struct V_6 * V_7 , T_3 V_25 )
{
T_2 V_26 ;
V_26 = F_16 ( V_7 -> V_19 + V_27 ) ;
V_26 &= ~ ( 1 << V_25 ) ;
F_17 ( V_26 , V_7 -> V_19 + V_27 ) ;
}
static void F_19 ( struct V_6 * V_7 , int V_28 )
{
T_2 V_26 ;
V_26 = F_16 ( V_7 -> V_19 + V_27 ) ;
V_26 &= ~ V_29 ;
V_26 |= ( V_28 << V_30 ) & V_29 ;
F_17 ( V_26 , V_7 -> V_19 + V_27 ) ;
}
static void F_20 ( struct V_6 * V_7 )
{
static const char * const V_31 [] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 ,
L_7 , L_8 , L_9 , L_10 , NULL
} ;
int V_32 ;
F_21 ( V_33 L_11 ,
F_22 ( & V_7 -> V_11 -> V_11 ) , V_7 -> V_34 ) ;
if ( V_7 -> V_35 & ( 1 << V_36 ) ) {
F_21 ( V_37 L_12 ) ;
for ( V_32 = 0 ; V_31 [ V_32 ] ; ++ V_32 )
if ( F_23 ( V_7 , ( 1ULL << V_32 ) ) )
F_21 ( V_37 L_13 , V_31 [ V_32 ] ) ;
}
F_21 ( V_37 L_14 ) ;
F_15 ( V_7 , V_38 ) ;
}
static void F_24 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_39 ) ;
F_18 ( V_7 , V_40 ) ;
F_18 ( V_7 , V_41 ) ;
F_18 ( V_7 , V_38 ) ;
}
static T_3 * T_5 F_25 ( T_4 V_9 )
{
if ( ! F_26 ( V_9 , V_42 , L_15 ) ) {
F_27 ( L_16 ,
V_9 ) ;
F_27 ( L_17 ) ;
return NULL ;
}
return F_28 ( V_9 , V_42 ) ;
}
static void T_5 F_29 ( struct V_6 * V_7 )
{
if ( V_7 -> V_19 )
F_30 ( V_7 -> V_19 ) ;
F_31 ( V_7 -> V_43 , V_42 ) ;
}
static inline int F_32 ( T_3 * V_44 )
{
return 0x04 << ( * V_44 >> 6 ) ;
}
static int T_5 F_33 ( int V_45 , int V_11 , int V_46 , int V_34 )
{
T_2 V_35 ;
V_35 = F_34 ( V_45 , V_11 , V_46 , V_34 + V_47 ) ;
F_1 ( F_35 ( F_36 ( V_35 ) , F_37 ( V_35 ) ) ) ;
return 0 ;
}
static int T_5 F_38 ( struct V_48 * V_49 )
{
T_3 * V_50 = ( void * ) V_49 , * V_51 = ( void * ) V_49 ;
struct V_52 * V_11 ;
V_50 += sizeof( * V_49 ) ;
V_51 += V_49 -> V_53 ;
F_33 ( F_39 ( V_49 -> V_1 ) ,
F_40 ( V_49 -> V_1 ) ,
F_41 ( V_49 -> V_1 ) ,
V_49 -> V_34 ) ;
while ( V_50 < V_51 ) {
V_11 = (struct V_52 * ) V_50 ;
switch ( V_11 -> type ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
F_1 ( V_11 -> V_1 ) ;
break;
default:
break;
}
V_50 += F_32 ( V_50 ) ;
}
F_42 ( V_50 != V_51 ) ;
return 0 ;
}
static int T_5 F_43 ( struct V_58 * V_59 )
{
int V_32 ;
T_3 V_60 = 0 , * V_50 = ( T_3 * ) V_59 , * V_51 = ( T_3 * ) V_59 ;
struct V_48 * V_49 ;
for ( V_32 = 0 ; V_32 < V_59 -> V_53 ; ++ V_32 )
V_60 += V_50 [ V_32 ] ;
if ( V_60 != 0 ) {
V_61 = - V_62 ;
return 0 ;
}
V_50 += V_63 ;
V_51 += V_59 -> V_53 ;
while ( V_50 < V_51 ) {
V_49 = (struct V_48 * ) V_50 ;
switch ( V_49 -> type ) {
case V_64 :
F_38 ( V_49 ) ;
break;
default:
break;
}
V_50 += V_49 -> V_53 ;
}
F_42 ( V_50 != V_51 ) ;
return 0 ;
}
static T_3 * T_5 F_44 ( struct V_6 * V_7 )
{
T_3 * V_65 = ( T_3 * ) F_45 ( V_66 | V_67 ,
F_3 ( V_68 ) ) ;
if ( V_65 == NULL )
return NULL ;
V_7 -> V_69 = V_68 | V_70 ;
return V_65 ;
}
void F_46 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_39 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_71 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_72 ) ;
F_15 ( V_7 , V_39 ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_65 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_65 ) ;
V_17 |= V_73 ;
F_11 ( V_7 -> V_19 + V_74 ,
& V_17 , sizeof( V_17 ) ) ;
F_46 ( V_7 ) ;
V_7 -> V_69 &= ~ ( V_70 ) ;
}
static void T_5 F_48 ( struct V_6 * V_7 )
{
F_49 ( ( unsigned long ) V_7 -> V_65 ,
F_3 ( V_7 -> V_69 & ~ ( V_70 ) ) ) ;
}
static T_3 * T_5 F_50 ( struct V_6 * V_7 )
{
V_7 -> V_75 = ( T_3 * ) F_45 ( V_66 | V_67 ,
F_3 ( V_76 ) ) ;
if ( V_7 -> V_75 == NULL )
return NULL ;
V_7 -> V_77 = V_76 ;
return V_7 -> V_75 ;
}
static void F_51 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_75 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_75 ) | V_78 ;
F_11 ( V_7 -> V_19 + V_79 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_80 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_81 ) ;
F_15 ( V_7 , V_41 ) ;
}
static void T_5 F_52 ( struct V_6 * V_7 )
{
F_49 ( ( unsigned long ) V_7 -> V_75 , F_3 ( V_76 ) ) ;
}
static T_3 * T_5 F_53 ( struct V_6 * V_7 )
{
V_7 -> V_82 = ( T_3 * ) F_45 ( V_66 | V_67 ,
F_3 ( V_83 ) ) ;
if ( V_7 -> V_82 == NULL )
return NULL ;
return V_7 -> V_82 ;
}
static void F_54 ( struct V_6 * V_7 )
{
T_4 V_17 ;
if ( V_7 -> V_82 == NULL )
return;
V_17 = ( T_4 ) F_14 ( V_7 -> V_82 ) | V_84 ;
F_11 ( V_7 -> V_19 + V_85 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_86 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_87 ) ;
F_15 ( V_7 , V_88 ) ;
F_15 ( V_7 , V_89 ) ;
}
static void T_5 F_55 ( struct V_6 * V_7 )
{
if ( V_7 -> V_82 == NULL )
return;
F_49 ( ( unsigned long ) V_7 -> V_82 , F_3 ( V_83 ) ) ;
}
static void F_56 ( struct V_6 * V_7 )
{
if ( ! F_23 ( V_7 , V_90 ) )
return;
F_15 ( V_7 , V_91 ) ;
}
static void F_57 ( T_1 V_1 , T_3 V_25 )
{
int V_32 = ( V_25 >> 6 ) & 0x03 ;
int V_92 = V_25 & 0x3f ;
V_22 [ V_1 ] . V_93 [ V_32 ] |= ( 1UL << V_92 ) ;
}
static int F_58 ( T_1 V_1 , T_3 V_25 )
{
int V_32 = ( V_25 >> 6 ) & 0x03 ;
int V_92 = V_25 & 0x3f ;
return ( V_22 [ V_1 ] . V_93 [ V_32 ] & ( 1UL << V_92 ) ) >> V_92 ;
}
void F_59 ( T_1 V_1 )
{
int V_94 ;
V_94 = F_58 ( V_1 , V_95 ) |
( F_58 ( V_1 , V_96 ) << 1 ) ;
if ( V_94 == 0x01 )
F_57 ( V_1 , V_97 ) ;
}
static void T_5 F_60 ( struct V_6 * V_7 , T_1 V_1 )
{
V_98 [ V_1 ] = V_7 ;
}
static void T_5 F_61 ( struct V_6 * V_7 ,
T_1 V_1 , T_2 V_99 , T_2 V_100 )
{
if ( V_99 & V_101 )
F_57 ( V_1 , V_102 ) ;
if ( V_99 & V_103 )
F_57 ( V_1 , V_104 ) ;
if ( V_99 & V_105 )
F_57 ( V_1 , V_106 ) ;
if ( V_99 & V_107 )
F_57 ( V_1 , V_95 ) ;
if ( V_99 & V_108 )
F_57 ( V_1 , V_96 ) ;
if ( V_99 & V_109 )
F_57 ( V_1 , V_110 ) ;
if ( V_99 & V_111 )
F_57 ( V_1 , V_112 ) ;
F_59 ( V_1 ) ;
F_60 ( V_7 , V_1 ) ;
}
static void T_5 F_62 ( T_1 V_1 , struct V_113 * V_114 )
{
struct V_6 * V_7 = V_98 [ V_1 ] ;
if ( ! ( V_114 -> V_99 & V_115 ) )
return;
if ( V_7 ) {
F_57 ( V_114 -> V_1 , V_116 ) ;
V_7 -> V_13 = V_114 -> V_117 ;
V_7 -> V_16 = V_114 -> V_118 ;
}
}
static void T_5 F_63 ( struct V_6 * V_7 )
{
int V_34 = V_7 -> V_34 ;
T_2 V_119 , V_120 , V_121 , V_122 ;
int V_32 , V_123 ;
F_6 ( V_7 -> V_11 , V_34 + V_124 ,
& V_7 -> V_35 ) ;
F_6 ( V_7 -> V_11 , V_34 + V_47 ,
& V_119 ) ;
F_6 ( V_7 -> V_11 , V_34 + V_125 ,
& V_120 ) ;
V_7 -> V_126 = F_35 ( F_36 ( V_119 ) ,
F_64 ( V_119 ) ) ;
V_7 -> V_127 = F_35 ( F_36 ( V_119 ) ,
F_37 ( V_119 ) ) ;
V_7 -> V_128 = F_65 ( V_120 ) ;
if ( ! ( V_7 -> V_35 & ( 1 << V_129 ) ) )
V_130 = false ;
V_121 = F_16 ( V_7 -> V_19 + V_131 ) ;
V_122 = F_16 ( V_7 -> V_19 + V_131 + 4 ) ;
V_7 -> V_132 = ( ( T_4 ) V_122 << 32 ) | V_121 ;
if ( F_23 ( V_7 , V_90 ) ) {
int V_133 ;
T_2 V_134 ;
T_4 V_4 ;
V_4 = V_7 -> V_132 & V_135 ;
V_4 >>= V_136 ;
V_134 = ( 1 << V_4 ) ;
V_137 = F_66 ( V_137 , V_134 ) ;
V_133 = V_7 -> V_132 & V_138 ;
V_133 >>= V_139 ;
if ( V_140 == - 1 )
V_140 = V_133 ;
else
V_140 = F_66 ( V_140 , V_133 ) ;
}
if ( F_23 ( V_7 , V_90 ) &&
F_23 ( V_7 , V_141 ) ) {
V_7 -> V_142 = true ;
V_143 = true ;
}
if ( ! F_67 ( V_7 -> V_11 ) )
return;
F_6 ( V_7 -> V_11 , V_7 -> V_34 + 4 ,
& V_7 -> V_144 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_34 + 8 ,
& V_7 -> V_145 ) ;
V_7 -> V_144 &= ~ 1 ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
for ( V_123 = 0 ; V_123 < 0x12 ; V_123 ++ )
V_7 -> V_146 [ V_32 ] [ V_123 ] = F_4 ( V_7 , V_32 , V_123 ) ;
for ( V_32 = 0 ; V_32 < 0x83 ; V_32 ++ )
V_7 -> V_147 [ V_32 ] = F_8 ( V_7 , V_32 ) ;
}
static void T_5 F_68 ( struct V_6 * V_7 ,
struct V_48 * V_49 )
{
T_3 * V_50 = ( T_3 * ) V_49 ;
T_3 * V_51 = V_50 , V_99 = 0 ;
T_1 V_1 = 0 , V_148 = 0 , V_149 = 0 ;
T_2 V_150 , V_100 = 0 ;
bool V_151 = false ;
struct V_52 * V_152 ;
V_7 -> V_153 = V_49 -> V_99 ;
V_50 += sizeof( struct V_48 ) ;
V_51 += V_49 -> V_53 ;
while ( V_50 < V_51 ) {
V_152 = (struct V_52 * ) V_50 ;
switch ( V_152 -> type ) {
case V_154 :
F_69 ( L_18
L_19 ,
F_39 ( V_7 -> V_126 ) ,
F_40 ( V_7 -> V_126 ) ,
F_41 ( V_7 -> V_126 ) ,
F_39 ( V_7 -> V_127 ) ,
F_40 ( V_7 -> V_127 ) ,
F_41 ( V_7 -> V_127 ) ,
V_152 -> V_99 ) ;
for ( V_150 = V_7 -> V_126 ;
V_150 <= V_7 -> V_127 ; ++ V_150 )
F_61 ( V_7 , V_150 ,
V_152 -> V_99 , 0 ) ;
break;
case V_54 :
F_69 ( L_20
L_21 ,
F_39 ( V_152 -> V_1 ) ,
F_40 ( V_152 -> V_1 ) ,
F_41 ( V_152 -> V_1 ) ,
V_152 -> V_99 ) ;
V_1 = V_152 -> V_1 ;
F_61 ( V_7 , V_1 , V_152 -> V_99 , 0 ) ;
break;
case V_155 :
F_69 ( L_22
L_23 ,
F_39 ( V_152 -> V_1 ) ,
F_40 ( V_152 -> V_1 ) ,
F_41 ( V_152 -> V_1 ) ,
V_152 -> V_99 ) ;
V_148 = V_152 -> V_1 ;
V_99 = V_152 -> V_99 ;
V_100 = 0 ;
V_151 = false ;
break;
case V_56 :
F_69 ( L_24
L_25 ,
F_39 ( V_152 -> V_1 ) ,
F_40 ( V_152 -> V_1 ) ,
F_41 ( V_152 -> V_1 ) ,
V_152 -> V_99 ,
F_39 ( V_152 -> V_156 >> 8 ) ,
F_40 ( V_152 -> V_156 >> 8 ) ,
F_41 ( V_152 -> V_156 >> 8 ) ) ;
V_1 = V_152 -> V_1 ;
V_149 = V_152 -> V_156 >> 8 ;
F_61 ( V_7 , V_1 , V_152 -> V_99 , 0 ) ;
F_61 ( V_7 , V_149 , V_152 -> V_99 , 0 ) ;
V_157 [ V_1 ] = V_149 ;
break;
case V_158 :
F_69 ( L_26
L_27
L_28 ,
F_39 ( V_152 -> V_1 ) ,
F_40 ( V_152 -> V_1 ) ,
F_41 ( V_152 -> V_1 ) ,
V_152 -> V_99 ,
F_39 ( V_152 -> V_156 >> 8 ) ,
F_40 ( V_152 -> V_156 >> 8 ) ,
F_41 ( V_152 -> V_156 >> 8 ) ) ;
V_148 = V_152 -> V_1 ;
V_99 = V_152 -> V_99 ;
V_149 = V_152 -> V_156 >> 8 ;
V_100 = 0 ;
V_151 = true ;
break;
case V_57 :
F_69 ( L_29
L_30 ,
F_39 ( V_152 -> V_1 ) ,
F_40 ( V_152 -> V_1 ) ,
F_41 ( V_152 -> V_1 ) ,
V_152 -> V_99 , V_152 -> V_156 ) ;
V_1 = V_152 -> V_1 ;
F_61 ( V_7 , V_1 , V_152 -> V_99 ,
V_152 -> V_156 ) ;
break;
case V_159 :
F_69 ( L_31
L_32 ,
F_39 ( V_152 -> V_1 ) ,
F_40 ( V_152 -> V_1 ) ,
F_41 ( V_152 -> V_1 ) ,
V_152 -> V_99 , V_152 -> V_156 ) ;
V_148 = V_152 -> V_1 ;
V_99 = V_152 -> V_99 ;
V_100 = V_152 -> V_156 ;
V_151 = false ;
break;
case V_55 :
F_69 ( L_33 ,
F_39 ( V_152 -> V_1 ) ,
F_40 ( V_152 -> V_1 ) ,
F_41 ( V_152 -> V_1 ) ) ;
V_1 = V_152 -> V_1 ;
for ( V_150 = V_148 ; V_150 <= V_1 ; ++ V_150 ) {
if ( V_151 ) {
V_157 [ V_150 ] = V_149 ;
F_61 ( V_7 ,
V_149 , V_99 , V_100 ) ;
}
F_61 ( V_7 , V_150 ,
V_99 , V_100 ) ;
}
break;
default:
break;
}
V_50 += F_32 ( V_50 ) ;
}
}
static int T_5 F_70 ( struct V_6 * V_7 )
{
T_2 V_32 ;
for ( V_32 = V_7 -> V_126 ; V_32 <= V_7 -> V_127 ; ++ V_32 )
F_60 ( V_7 , V_32 ) ;
return 0 ;
}
static void T_5 F_71 ( struct V_6 * V_7 )
{
F_48 ( V_7 ) ;
F_52 ( V_7 ) ;
F_55 ( V_7 ) ;
F_29 ( V_7 ) ;
}
static void T_5 F_72 ( void )
{
struct V_6 * V_7 , * V_160 ;
F_73 (iommu, next) {
F_74 ( & V_7 -> V_161 ) ;
F_71 ( V_7 ) ;
F_75 ( V_7 ) ;
}
}
static int T_5 F_76 ( struct V_6 * V_7 , struct V_48 * V_49 )
{
F_77 ( & V_7 -> V_162 ) ;
F_78 ( & V_7 -> V_161 , & V_163 ) ;
V_7 -> V_164 = V_165 ++ ;
if ( F_79 ( V_7 -> V_164 >= V_166 ) ) {
F_80 ( 1 , L_34 ) ;
return - V_167 ;
}
V_168 [ V_7 -> V_164 ] = V_7 ;
V_7 -> V_11 = F_81 ( F_39 ( V_49 -> V_1 ) , V_49 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return 1 ;
V_7 -> V_169 = F_81 ( V_7 -> V_11 -> V_45 -> V_170 ,
F_82 ( 0 , 0 ) ) ;
V_7 -> V_34 = V_49 -> V_34 ;
V_7 -> V_171 = V_49 -> V_171 ;
V_7 -> V_43 = V_49 -> V_43 ;
V_7 -> V_19 = F_25 ( V_49 -> V_43 ) ;
if ( ! V_7 -> V_19 )
return - V_172 ;
V_7 -> V_65 = F_44 ( V_7 ) ;
if ( ! V_7 -> V_65 )
return - V_172 ;
V_7 -> V_75 = F_50 ( V_7 ) ;
if ( ! V_7 -> V_75 )
return - V_172 ;
V_7 -> V_173 = false ;
F_63 ( V_7 ) ;
F_68 ( V_7 , V_49 ) ;
F_70 ( V_7 ) ;
if ( F_23 ( V_7 , V_141 ) ) {
V_7 -> V_82 = F_53 ( V_7 ) ;
if ( ! V_7 -> V_82 )
return - V_172 ;
}
if ( V_7 -> V_35 & ( 1UL << V_174 ) )
V_175 = true ;
return F_83 ( V_7 -> V_11 ) ;
}
static int T_5 F_84 ( struct V_58 * V_59 )
{
T_3 * V_50 = ( T_3 * ) V_59 , * V_51 = ( T_3 * ) V_59 ;
struct V_48 * V_49 ;
struct V_6 * V_7 ;
int V_176 ;
V_51 += V_59 -> V_53 ;
V_50 += V_63 ;
while ( V_50 < V_51 ) {
V_49 = (struct V_48 * ) V_50 ;
switch ( * V_50 ) {
case V_64 :
F_69 ( L_35
L_36 ,
F_39 ( V_49 -> V_1 ) , F_40 ( V_49 -> V_1 ) ,
F_41 ( V_49 -> V_1 ) , V_49 -> V_34 ,
V_49 -> V_171 , V_49 -> V_99 , V_49 -> V_177 ) ;
F_69 ( L_37 ,
V_49 -> V_43 ) ;
V_7 = F_85 ( sizeof( struct V_6 ) , V_66 ) ;
if ( V_7 == NULL ) {
V_61 = - V_172 ;
return 0 ;
}
V_176 = F_76 ( V_7 , V_49 ) ;
if ( V_176 ) {
V_61 = V_176 ;
return 0 ;
}
break;
default:
break;
}
V_50 += V_49 -> V_53 ;
}
F_42 ( V_50 != V_51 ) ;
return 0 ;
}
static int F_86 ( struct V_6 * V_7 )
{
int V_178 ;
V_178 = F_87 ( V_7 -> V_11 ) ;
if ( V_178 )
return V_178 ;
V_178 = F_88 ( V_7 -> V_11 -> V_179 ,
V_180 ,
V_181 ,
0 , L_38 ,
V_7 -> V_11 ) ;
if ( V_178 ) {
F_89 ( V_7 -> V_11 ) ;
return V_178 ;
}
V_7 -> V_173 = true ;
return 0 ;
}
static int F_90 ( struct V_6 * V_7 )
{
int V_176 ;
if ( V_7 -> V_173 )
goto V_182;
if ( F_91 ( V_7 -> V_11 , V_183 ) )
V_176 = F_86 ( V_7 ) ;
else
V_176 = - V_62 ;
if ( V_176 )
return V_176 ;
V_182:
F_15 ( V_7 , V_40 ) ;
if ( V_7 -> V_82 != NULL )
F_15 ( V_7 , V_184 ) ;
return 0 ;
}
static void T_5 F_92 ( void )
{
struct V_185 * V_17 , * V_160 ;
F_93 (entry, next, &amd_iommu_unity_map, list) {
F_74 ( & V_17 -> V_161 ) ;
F_75 ( V_17 ) ;
}
}
static int T_5 F_94 ( struct V_113 * V_114 )
{
int V_32 ;
switch ( V_114 -> type ) {
case V_186 :
F_62 ( V_114 -> V_1 , V_114 ) ;
break;
case V_187 :
for ( V_32 = 0 ; V_32 <= V_2 ; ++ V_32 )
F_62 ( V_32 , V_114 ) ;
break;
case V_188 :
for ( V_32 = V_114 -> V_1 ; V_32 <= V_114 -> V_189 ; ++ V_32 )
F_62 ( V_32 , V_114 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_5 F_95 ( struct V_113 * V_114 )
{
struct V_185 * V_152 = 0 ;
char * V_190 ;
V_152 = F_85 ( sizeof( * V_152 ) , V_66 ) ;
if ( V_152 == NULL )
return - V_172 ;
switch ( V_114 -> type ) {
default:
F_75 ( V_152 ) ;
return 0 ;
case V_186 :
V_190 = L_39 ;
V_152 -> V_148 = V_152 -> V_191 = V_114 -> V_1 ;
break;
case V_187 :
V_190 = L_40 ;
V_152 -> V_148 = 0 ;
V_152 -> V_191 = V_2 ;
break;
case V_188 :
V_190 = L_41 ;
V_152 -> V_148 = V_114 -> V_1 ;
V_152 -> V_191 = V_114 -> V_189 ;
break;
}
V_152 -> V_192 = F_96 ( V_114 -> V_117 ) ;
V_152 -> V_193 = V_152 -> V_192 + F_96 ( V_114 -> V_118 ) ;
V_152 -> V_194 = V_114 -> V_99 >> 1 ;
F_69 ( L_42
L_43 , V_190 ,
F_39 ( V_152 -> V_148 ) , F_40 ( V_152 -> V_148 ) ,
F_41 ( V_152 -> V_148 ) , F_39 ( V_152 -> V_191 ) ,
F_40 ( V_152 -> V_191 ) , F_41 ( V_152 -> V_191 ) ,
V_152 -> V_192 , V_152 -> V_193 , V_114 -> V_99 ) ;
F_78 ( & V_152 -> V_161 , & V_195 ) ;
return 0 ;
}
static int T_5 F_97 ( struct V_58 * V_59 )
{
T_3 * V_50 = ( T_3 * ) V_59 , * V_51 = ( T_3 * ) V_59 ;
struct V_113 * V_114 ;
V_51 += V_59 -> V_53 ;
V_50 += V_63 ;
while ( V_50 < V_51 ) {
V_114 = (struct V_113 * ) V_50 ;
if ( V_114 -> V_99 & V_115 )
F_94 ( V_114 ) ;
else if ( V_114 -> V_99 & V_196 )
F_95 ( V_114 ) ;
V_50 += V_114 -> V_53 ;
}
return 0 ;
}
static void F_98 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_57 ( V_1 , V_197 ) ;
F_57 ( V_1 , V_198 ) ;
}
}
static void F_99 ( struct V_6 * V_7 )
{
V_7 -> V_153 & V_199 ?
F_15 ( V_7 , V_200 ) :
F_18 ( V_7 , V_200 ) ;
V_7 -> V_153 & V_201 ?
F_15 ( V_7 , V_202 ) :
F_18 ( V_7 , V_202 ) ;
V_7 -> V_153 & V_203 ?
F_15 ( V_7 , V_204 ) :
F_18 ( V_7 , V_204 ) ;
V_7 -> V_153 & V_205 ?
F_15 ( V_7 , V_206 ) :
F_18 ( V_7 , V_206 ) ;
F_15 ( V_7 , V_207 ) ;
F_19 ( V_7 , V_208 ) ;
}
static void F_100 ( struct V_6 * V_7 )
{
int V_32 , V_123 ;
T_2 V_209 ;
struct V_210 * V_211 = V_7 -> V_169 ;
if ( ! F_67 ( V_7 -> V_11 ) || ! V_211 )
return;
F_5 ( V_211 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_211 , 0x64 , & V_209 ) ;
if ( ! ( V_209 & 0x1 ) )
F_5 ( V_211 , 0x64 , V_209 | 1 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_34 + 4 ,
V_7 -> V_144 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_34 + 8 ,
V_7 -> V_145 ) ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
for ( V_123 = 0 ; V_123 < 0x12 ; V_123 ++ )
F_7 ( V_7 , V_32 , V_123 , V_7 -> V_146 [ V_32 ] [ V_123 ] ) ;
for ( V_32 = 0 ; V_32 < 0x83 ; V_32 ++ )
F_9 ( V_7 , V_32 , V_7 -> V_147 [ V_32 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_34 + 4 ,
V_7 -> V_144 | 1 ) ;
}
static void F_101 ( void )
{
struct V_6 * V_7 ;
F_102 (iommu) {
F_24 ( V_7 ) ;
F_99 ( V_7 ) ;
F_12 ( V_7 ) ;
F_47 ( V_7 ) ;
F_51 ( V_7 ) ;
F_54 ( V_7 ) ;
F_56 ( V_7 ) ;
F_10 ( V_7 ) ;
F_20 ( V_7 ) ;
F_103 ( V_7 ) ;
}
}
static void F_104 ( void )
{
struct V_6 * V_7 ;
F_102 (iommu)
F_24 ( V_7 ) ;
}
static void F_105 ( void )
{
struct V_6 * V_7 ;
F_102 (iommu)
F_100 ( V_7 ) ;
F_101 () ;
F_106 () ;
}
static int F_107 ( void )
{
F_104 () ;
return 0 ;
}
static void T_5 F_108 ( void )
{
F_109 () ;
F_49 ( ( unsigned long ) V_212 ,
F_3 ( V_213 / 8 ) ) ;
F_49 ( ( unsigned long ) V_98 ,
F_3 ( V_214 ) ) ;
F_49 ( ( unsigned long ) V_157 ,
F_3 ( V_215 ) ) ;
F_49 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_72 () ;
F_92 () ;
#ifdef F_110
F_111 () ;
#endif
}
int T_5 F_112 ( void )
{
int V_32 , V_176 = 0 ;
if ( ! V_216 )
return - V_62 ;
if ( V_22 != NULL ) {
return 0 ;
}
if ( F_113 ( L_44 , F_43 ) != 0 )
return - V_62 ;
V_176 = V_61 ;
if ( V_176 )
goto V_217;
V_23 = F_2 ( V_218 ) ;
V_215 = F_2 ( V_219 ) ;
V_214 = F_2 ( V_220 ) ;
V_176 = - V_172 ;
V_22 = ( void * ) F_45 ( V_66 | V_67 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_217;
V_157 = ( void * ) F_45 ( V_66 ,
F_3 ( V_215 ) ) ;
if ( V_157 == NULL )
goto free;
V_98 = ( void * ) F_45 (
V_66 | V_67 ,
F_3 ( V_214 ) ) ;
if ( V_98 == NULL )
goto free;
V_212 = ( void * ) F_45 (
V_66 | V_67 ,
F_3 ( V_213 / 8 ) ) ;
if ( V_212 == NULL )
goto free;
F_98 () ;
for ( V_32 = 0 ; V_32 <= V_2 ; ++ V_32 )
V_157 [ V_32 ] = V_32 ;
V_212 [ 0 ] = 1 ;
F_77 ( & V_221 ) ;
V_176 = - V_62 ;
if ( F_113 ( L_44 , F_84 ) != 0 )
goto free;
if ( V_61 ) {
V_176 = V_61 ;
goto free;
}
if ( F_113 ( L_44 , F_97 ) != 0 )
goto free;
if ( V_61 ) {
V_176 = V_61 ;
goto free;
}
V_176 = F_114 () ;
if ( V_176 )
goto free;
F_101 () ;
F_115 () ;
F_116 ( & V_222 ) ;
V_217:
return V_176 ;
free:
F_108 () ;
return V_176 ;
}
static int F_106 ( void )
{
struct V_6 * V_7 ;
int V_176 = 0 ;
F_102 (iommu) {
V_176 = F_90 ( V_7 ) ;
if ( V_176 )
goto V_217;
}
V_217:
return V_176 ;
}
static int T_5 F_117 ( void )
{
int V_176 = 0 ;
V_176 = F_112 () ;
if ( V_176 )
goto V_217;
V_176 = F_106 () ;
if ( V_176 )
goto free;
if ( V_223 )
V_176 = F_118 () ;
else
V_176 = F_119 () ;
if ( V_176 )
goto free;
F_120 () ;
V_224 . V_225 = F_104 ;
if ( V_223 )
goto V_217;
if ( V_226 )
F_21 ( V_33 L_45 ) ;
else
F_21 ( V_33 L_46 ) ;
V_217:
return V_176 ;
free:
F_104 () ;
F_108 () ;
goto V_217;
}
static int T_5 F_121 ( struct V_58 * V_59 )
{
return 0 ;
}
int T_5 F_122 ( void )
{
if ( V_227 || ( V_228 && ! V_229 ) )
return - V_62 ;
if ( V_230 )
return - V_62 ;
if ( F_113 ( L_44 , F_121 ) == 0 ) {
V_228 = 1 ;
V_216 = 1 ;
V_231 . V_7 . V_232 = F_117 ;
F_123 () ;
return 1 ;
}
return - V_62 ;
}
static int T_5 F_124 ( char * V_233 )
{
V_234 = true ;
return 1 ;
}
static int T_5 F_125 ( char * V_233 )
{
for (; * V_233 ; ++ V_233 ) {
if ( strncmp ( V_233 , L_47 , 9 ) == 0 )
V_226 = true ;
if ( strncmp ( V_233 , L_48 , 3 ) == 0 )
V_230 = true ;
if ( strncmp ( V_233 , L_49 , 15 ) == 0 )
V_235 = true ;
}
return 1 ;
}
bool F_126 ( void )
{
return V_143 ;
}
