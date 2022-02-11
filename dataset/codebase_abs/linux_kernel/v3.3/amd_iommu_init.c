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
T_3 * V_42 ;
if ( ! F_26 ( V_9 , V_43 , L_15 ) ) {
F_27 ( L_16 ,
V_9 ) ;
F_27 ( L_17 ) ;
return NULL ;
}
V_42 = F_28 ( V_9 , V_43 ) ;
if ( V_42 != NULL )
return V_42 ;
F_29 ( V_9 , V_43 ) ;
return NULL ;
}
static void T_5 F_30 ( struct V_6 * V_7 )
{
if ( V_7 -> V_19 )
F_31 ( V_7 -> V_19 ) ;
F_29 ( V_7 -> V_44 , V_43 ) ;
}
static inline int F_32 ( T_3 * V_45 )
{
return 0x04 << ( * V_45 >> 6 ) ;
}
static int T_5 F_33 ( int V_46 , int V_11 , int V_47 , int V_34 )
{
T_2 V_35 ;
V_35 = F_34 ( V_46 , V_11 , V_47 , V_34 + V_48 ) ;
F_1 ( F_35 ( F_36 ( V_35 ) , F_37 ( V_35 ) ) ) ;
return 0 ;
}
static int T_5 F_38 ( struct V_49 * V_50 )
{
T_3 * V_51 = ( void * ) V_50 , * V_52 = ( void * ) V_50 ;
struct V_53 * V_11 ;
V_51 += sizeof( * V_50 ) ;
V_52 += V_50 -> V_54 ;
F_33 ( F_39 ( V_50 -> V_1 ) ,
F_40 ( V_50 -> V_1 ) ,
F_41 ( V_50 -> V_1 ) ,
V_50 -> V_34 ) ;
while ( V_51 < V_52 ) {
V_11 = (struct V_53 * ) V_51 ;
switch ( V_11 -> type ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
F_1 ( V_11 -> V_1 ) ;
break;
default:
break;
}
V_51 += F_32 ( V_51 ) ;
}
F_42 ( V_51 != V_52 ) ;
return 0 ;
}
static int T_5 F_43 ( struct V_59 * V_60 )
{
int V_32 ;
T_3 V_61 = 0 , * V_51 = ( T_3 * ) V_60 , * V_52 = ( T_3 * ) V_60 ;
struct V_49 * V_50 ;
for ( V_32 = 0 ; V_32 < V_60 -> V_54 ; ++ V_32 )
V_61 += V_51 [ V_32 ] ;
if ( V_61 != 0 ) {
V_62 = - V_63 ;
return 0 ;
}
V_51 += V_64 ;
V_52 += V_60 -> V_54 ;
while ( V_51 < V_52 ) {
V_50 = (struct V_49 * ) V_51 ;
switch ( V_50 -> type ) {
case V_65 :
F_38 ( V_50 ) ;
break;
default:
break;
}
V_51 += V_50 -> V_54 ;
}
F_42 ( V_51 != V_52 ) ;
return 0 ;
}
static T_3 * T_5 F_44 ( struct V_6 * V_7 )
{
T_3 * V_66 = ( T_3 * ) F_45 ( V_67 | V_68 ,
F_3 ( V_69 ) ) ;
if ( V_66 == NULL )
return NULL ;
V_7 -> V_70 = V_69 | V_71 ;
return V_66 ;
}
void F_46 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_39 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_72 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_73 ) ;
F_15 ( V_7 , V_39 ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_66 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_66 ) ;
V_17 |= V_74 ;
F_11 ( V_7 -> V_19 + V_75 ,
& V_17 , sizeof( V_17 ) ) ;
F_46 ( V_7 ) ;
V_7 -> V_70 &= ~ ( V_71 ) ;
}
static void T_5 F_48 ( struct V_6 * V_7 )
{
F_49 ( ( unsigned long ) V_7 -> V_66 ,
F_3 ( V_7 -> V_70 & ~ ( V_71 ) ) ) ;
}
static T_3 * T_5 F_50 ( struct V_6 * V_7 )
{
V_7 -> V_76 = ( T_3 * ) F_45 ( V_67 | V_68 ,
F_3 ( V_77 ) ) ;
if ( V_7 -> V_76 == NULL )
return NULL ;
V_7 -> V_78 = V_77 ;
return V_7 -> V_76 ;
}
static void F_51 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_76 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_76 ) | V_79 ;
F_11 ( V_7 -> V_19 + V_80 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_81 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_82 ) ;
F_15 ( V_7 , V_41 ) ;
}
static void T_5 F_52 ( struct V_6 * V_7 )
{
F_49 ( ( unsigned long ) V_7 -> V_76 , F_3 ( V_77 ) ) ;
}
static T_3 * T_5 F_53 ( struct V_6 * V_7 )
{
V_7 -> V_83 = ( T_3 * ) F_45 ( V_67 | V_68 ,
F_3 ( V_84 ) ) ;
if ( V_7 -> V_83 == NULL )
return NULL ;
return V_7 -> V_83 ;
}
static void F_54 ( struct V_6 * V_7 )
{
T_4 V_17 ;
if ( V_7 -> V_83 == NULL )
return;
V_17 = ( T_4 ) F_14 ( V_7 -> V_83 ) | V_85 ;
F_11 ( V_7 -> V_19 + V_86 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_87 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_88 ) ;
F_15 ( V_7 , V_89 ) ;
F_15 ( V_7 , V_90 ) ;
}
static void T_5 F_55 ( struct V_6 * V_7 )
{
if ( V_7 -> V_83 == NULL )
return;
F_49 ( ( unsigned long ) V_7 -> V_83 , F_3 ( V_84 ) ) ;
}
static void F_56 ( struct V_6 * V_7 )
{
if ( ! F_23 ( V_7 , V_91 ) )
return;
F_15 ( V_7 , V_92 ) ;
}
static void F_57 ( T_1 V_1 , T_3 V_25 )
{
int V_32 = ( V_25 >> 6 ) & 0x03 ;
int V_93 = V_25 & 0x3f ;
V_22 [ V_1 ] . V_94 [ V_32 ] |= ( 1UL << V_93 ) ;
}
static int F_58 ( T_1 V_1 , T_3 V_25 )
{
int V_32 = ( V_25 >> 6 ) & 0x03 ;
int V_93 = V_25 & 0x3f ;
return ( V_22 [ V_1 ] . V_94 [ V_32 ] & ( 1UL << V_93 ) ) >> V_93 ;
}
void F_59 ( T_1 V_1 )
{
int V_95 ;
V_95 = F_58 ( V_1 , V_96 ) |
( F_58 ( V_1 , V_97 ) << 1 ) ;
if ( V_95 == 0x01 )
F_57 ( V_1 , V_98 ) ;
}
static void T_5 F_60 ( struct V_6 * V_7 , T_1 V_1 )
{
V_99 [ V_1 ] = V_7 ;
}
static void T_5 F_61 ( struct V_6 * V_7 ,
T_1 V_1 , T_2 V_100 , T_2 V_101 )
{
if ( V_100 & V_102 )
F_57 ( V_1 , V_103 ) ;
if ( V_100 & V_104 )
F_57 ( V_1 , V_105 ) ;
if ( V_100 & V_106 )
F_57 ( V_1 , V_107 ) ;
if ( V_100 & V_108 )
F_57 ( V_1 , V_96 ) ;
if ( V_100 & V_109 )
F_57 ( V_1 , V_97 ) ;
if ( V_100 & V_110 )
F_57 ( V_1 , V_111 ) ;
if ( V_100 & V_112 )
F_57 ( V_1 , V_113 ) ;
F_59 ( V_1 ) ;
F_60 ( V_7 , V_1 ) ;
}
static void T_5 F_62 ( T_1 V_1 , struct V_114 * V_115 )
{
struct V_6 * V_7 = V_99 [ V_1 ] ;
if ( ! ( V_115 -> V_100 & V_116 ) )
return;
if ( V_7 ) {
F_57 ( V_115 -> V_1 , V_117 ) ;
V_7 -> V_13 = V_115 -> V_118 ;
V_7 -> V_16 = V_115 -> V_119 ;
}
}
static void T_5 F_63 ( struct V_6 * V_7 )
{
int V_34 = V_7 -> V_34 ;
T_2 V_120 , V_121 , V_122 , V_123 ;
int V_32 , V_124 ;
F_6 ( V_7 -> V_11 , V_34 + V_125 ,
& V_7 -> V_35 ) ;
F_6 ( V_7 -> V_11 , V_34 + V_48 ,
& V_120 ) ;
F_6 ( V_7 -> V_11 , V_34 + V_126 ,
& V_121 ) ;
V_7 -> V_127 = F_35 ( F_36 ( V_120 ) ,
F_64 ( V_120 ) ) ;
V_7 -> V_128 = F_35 ( F_36 ( V_120 ) ,
F_37 ( V_120 ) ) ;
V_7 -> V_129 = F_65 ( V_121 ) ;
if ( ! ( V_7 -> V_35 & ( 1 << V_130 ) ) )
V_131 = false ;
V_122 = F_16 ( V_7 -> V_19 + V_132 ) ;
V_123 = F_16 ( V_7 -> V_19 + V_132 + 4 ) ;
V_7 -> V_133 = ( ( T_4 ) V_123 << 32 ) | V_122 ;
if ( F_23 ( V_7 , V_91 ) ) {
int V_134 ;
T_2 V_135 ;
T_4 V_4 ;
V_4 = V_7 -> V_133 & V_136 ;
V_4 >>= V_137 ;
V_135 = ( 1 << V_4 ) ;
V_138 = F_66 ( V_138 , V_135 ) ;
V_134 = V_7 -> V_133 & V_139 ;
V_134 >>= V_140 ;
if ( V_141 == - 1 )
V_141 = V_134 ;
else
V_141 = F_66 ( V_141 , V_134 ) ;
}
if ( F_23 ( V_7 , V_91 ) &&
F_23 ( V_7 , V_142 ) ) {
V_7 -> V_143 = true ;
V_144 = true ;
}
if ( ! F_67 ( V_7 -> V_11 ) )
return;
F_6 ( V_7 -> V_11 , V_7 -> V_34 + 4 ,
& V_7 -> V_145 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_34 + 8 ,
& V_7 -> V_146 ) ;
V_7 -> V_145 &= ~ 1 ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
for ( V_124 = 0 ; V_124 < 0x12 ; V_124 ++ )
V_7 -> V_147 [ V_32 ] [ V_124 ] = F_4 ( V_7 , V_32 , V_124 ) ;
for ( V_32 = 0 ; V_32 < 0x83 ; V_32 ++ )
V_7 -> V_148 [ V_32 ] = F_8 ( V_7 , V_32 ) ;
}
static void T_5 F_68 ( struct V_6 * V_7 ,
struct V_49 * V_50 )
{
T_3 * V_51 = ( T_3 * ) V_50 ;
T_3 * V_52 = V_51 , V_100 = 0 ;
T_1 V_1 = 0 , V_149 = 0 , V_150 = 0 ;
T_2 V_151 , V_101 = 0 ;
bool V_152 = false ;
struct V_53 * V_153 ;
V_7 -> V_154 = V_50 -> V_100 ;
V_51 += sizeof( struct V_49 ) ;
V_52 += V_50 -> V_54 ;
while ( V_51 < V_52 ) {
V_153 = (struct V_53 * ) V_51 ;
switch ( V_153 -> type ) {
case V_155 :
F_69 ( L_18
L_19 ,
F_39 ( V_7 -> V_127 ) ,
F_40 ( V_7 -> V_127 ) ,
F_41 ( V_7 -> V_127 ) ,
F_39 ( V_7 -> V_128 ) ,
F_40 ( V_7 -> V_128 ) ,
F_41 ( V_7 -> V_128 ) ,
V_153 -> V_100 ) ;
for ( V_151 = V_7 -> V_127 ;
V_151 <= V_7 -> V_128 ; ++ V_151 )
F_61 ( V_7 , V_151 ,
V_153 -> V_100 , 0 ) ;
break;
case V_55 :
F_69 ( L_20
L_21 ,
F_39 ( V_153 -> V_1 ) ,
F_40 ( V_153 -> V_1 ) ,
F_41 ( V_153 -> V_1 ) ,
V_153 -> V_100 ) ;
V_1 = V_153 -> V_1 ;
F_61 ( V_7 , V_1 , V_153 -> V_100 , 0 ) ;
break;
case V_156 :
F_69 ( L_22
L_23 ,
F_39 ( V_153 -> V_1 ) ,
F_40 ( V_153 -> V_1 ) ,
F_41 ( V_153 -> V_1 ) ,
V_153 -> V_100 ) ;
V_149 = V_153 -> V_1 ;
V_100 = V_153 -> V_100 ;
V_101 = 0 ;
V_152 = false ;
break;
case V_57 :
F_69 ( L_24
L_25 ,
F_39 ( V_153 -> V_1 ) ,
F_40 ( V_153 -> V_1 ) ,
F_41 ( V_153 -> V_1 ) ,
V_153 -> V_100 ,
F_39 ( V_153 -> V_157 >> 8 ) ,
F_40 ( V_153 -> V_157 >> 8 ) ,
F_41 ( V_153 -> V_157 >> 8 ) ) ;
V_1 = V_153 -> V_1 ;
V_150 = V_153 -> V_157 >> 8 ;
F_61 ( V_7 , V_1 , V_153 -> V_100 , 0 ) ;
F_61 ( V_7 , V_150 , V_153 -> V_100 , 0 ) ;
V_158 [ V_1 ] = V_150 ;
break;
case V_159 :
F_69 ( L_26
L_27
L_28 ,
F_39 ( V_153 -> V_1 ) ,
F_40 ( V_153 -> V_1 ) ,
F_41 ( V_153 -> V_1 ) ,
V_153 -> V_100 ,
F_39 ( V_153 -> V_157 >> 8 ) ,
F_40 ( V_153 -> V_157 >> 8 ) ,
F_41 ( V_153 -> V_157 >> 8 ) ) ;
V_149 = V_153 -> V_1 ;
V_100 = V_153 -> V_100 ;
V_150 = V_153 -> V_157 >> 8 ;
V_101 = 0 ;
V_152 = true ;
break;
case V_58 :
F_69 ( L_29
L_30 ,
F_39 ( V_153 -> V_1 ) ,
F_40 ( V_153 -> V_1 ) ,
F_41 ( V_153 -> V_1 ) ,
V_153 -> V_100 , V_153 -> V_157 ) ;
V_1 = V_153 -> V_1 ;
F_61 ( V_7 , V_1 , V_153 -> V_100 ,
V_153 -> V_157 ) ;
break;
case V_160 :
F_69 ( L_31
L_32 ,
F_39 ( V_153 -> V_1 ) ,
F_40 ( V_153 -> V_1 ) ,
F_41 ( V_153 -> V_1 ) ,
V_153 -> V_100 , V_153 -> V_157 ) ;
V_149 = V_153 -> V_1 ;
V_100 = V_153 -> V_100 ;
V_101 = V_153 -> V_157 ;
V_152 = false ;
break;
case V_56 :
F_69 ( L_33 ,
F_39 ( V_153 -> V_1 ) ,
F_40 ( V_153 -> V_1 ) ,
F_41 ( V_153 -> V_1 ) ) ;
V_1 = V_153 -> V_1 ;
for ( V_151 = V_149 ; V_151 <= V_1 ; ++ V_151 ) {
if ( V_152 ) {
V_158 [ V_151 ] = V_150 ;
F_61 ( V_7 ,
V_150 , V_100 , V_101 ) ;
}
F_61 ( V_7 , V_151 ,
V_100 , V_101 ) ;
}
break;
default:
break;
}
V_51 += F_32 ( V_51 ) ;
}
}
static int T_5 F_70 ( struct V_6 * V_7 )
{
T_2 V_32 ;
for ( V_32 = V_7 -> V_127 ; V_32 <= V_7 -> V_128 ; ++ V_32 )
F_60 ( V_7 , V_32 ) ;
return 0 ;
}
static void T_5 F_71 ( struct V_6 * V_7 )
{
F_48 ( V_7 ) ;
F_52 ( V_7 ) ;
F_55 ( V_7 ) ;
F_30 ( V_7 ) ;
}
static void T_5 F_72 ( void )
{
struct V_6 * V_7 , * V_161 ;
F_73 (iommu, next) {
F_74 ( & V_7 -> V_162 ) ;
F_71 ( V_7 ) ;
F_75 ( V_7 ) ;
}
}
static int T_5 F_76 ( struct V_6 * V_7 , struct V_49 * V_50 )
{
F_77 ( & V_7 -> V_163 ) ;
F_78 ( & V_7 -> V_162 , & V_164 ) ;
V_7 -> V_165 = V_166 ++ ;
if ( F_79 ( V_7 -> V_165 >= V_167 ) ) {
F_80 ( 1 , L_34 ) ;
return - V_168 ;
}
V_169 [ V_7 -> V_165 ] = V_7 ;
V_7 -> V_11 = F_81 ( F_39 ( V_50 -> V_1 ) , V_50 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return 1 ;
V_7 -> V_34 = V_50 -> V_34 ;
V_7 -> V_170 = V_50 -> V_170 ;
V_7 -> V_44 = V_50 -> V_44 ;
V_7 -> V_19 = F_25 ( V_50 -> V_44 ) ;
if ( ! V_7 -> V_19 )
return - V_171 ;
V_7 -> V_66 = F_44 ( V_7 ) ;
if ( ! V_7 -> V_66 )
return - V_171 ;
V_7 -> V_76 = F_50 ( V_7 ) ;
if ( ! V_7 -> V_76 )
return - V_171 ;
V_7 -> V_172 = false ;
F_63 ( V_7 ) ;
F_68 ( V_7 , V_50 ) ;
F_70 ( V_7 ) ;
if ( F_23 ( V_7 , V_142 ) ) {
V_7 -> V_83 = F_53 ( V_7 ) ;
if ( ! V_7 -> V_83 )
return - V_171 ;
}
if ( V_7 -> V_35 & ( 1UL << V_173 ) )
V_174 = true ;
return F_82 ( V_7 -> V_11 ) ;
}
static int T_5 F_83 ( struct V_59 * V_60 )
{
T_3 * V_51 = ( T_3 * ) V_60 , * V_52 = ( T_3 * ) V_60 ;
struct V_49 * V_50 ;
struct V_6 * V_7 ;
int V_42 ;
V_52 += V_60 -> V_54 ;
V_51 += V_64 ;
while ( V_51 < V_52 ) {
V_50 = (struct V_49 * ) V_51 ;
switch ( * V_51 ) {
case V_65 :
F_69 ( L_35
L_36 ,
F_39 ( V_50 -> V_1 ) , F_40 ( V_50 -> V_1 ) ,
F_41 ( V_50 -> V_1 ) , V_50 -> V_34 ,
V_50 -> V_170 , V_50 -> V_100 , V_50 -> V_175 ) ;
F_69 ( L_37 ,
V_50 -> V_44 ) ;
V_7 = F_84 ( sizeof( struct V_6 ) , V_67 ) ;
if ( V_7 == NULL ) {
V_62 = - V_171 ;
return 0 ;
}
V_42 = F_76 ( V_7 , V_50 ) ;
if ( V_42 ) {
V_62 = V_42 ;
return 0 ;
}
break;
default:
break;
}
V_51 += V_50 -> V_54 ;
}
F_42 ( V_51 != V_52 ) ;
return 0 ;
}
static int F_85 ( struct V_6 * V_7 )
{
int V_176 ;
if ( F_86 ( V_7 -> V_11 ) )
return 1 ;
V_176 = F_87 ( V_7 -> V_11 -> V_177 ,
V_178 ,
V_179 ,
0 , L_38 ,
V_7 -> V_11 ) ;
if ( V_176 ) {
F_88 ( V_7 -> V_11 ) ;
return 1 ;
}
V_7 -> V_172 = true ;
F_15 ( V_7 , V_40 ) ;
if ( V_7 -> V_83 != NULL )
F_15 ( V_7 , V_180 ) ;
return 0 ;
}
static int F_89 ( struct V_6 * V_7 )
{
if ( V_7 -> V_172 )
return 0 ;
if ( F_90 ( V_7 -> V_11 , V_181 ) )
return F_85 ( V_7 ) ;
return 1 ;
}
static void T_5 F_91 ( void )
{
struct V_182 * V_17 , * V_161 ;
F_92 (entry, next, &amd_iommu_unity_map, list) {
F_74 ( & V_17 -> V_162 ) ;
F_75 ( V_17 ) ;
}
}
static int T_5 F_93 ( struct V_114 * V_115 )
{
int V_32 ;
switch ( V_115 -> type ) {
case V_183 :
F_62 ( V_115 -> V_1 , V_115 ) ;
break;
case V_184 :
for ( V_32 = 0 ; V_32 <= V_2 ; ++ V_32 )
F_62 ( V_32 , V_115 ) ;
break;
case V_185 :
for ( V_32 = V_115 -> V_1 ; V_32 <= V_115 -> V_186 ; ++ V_32 )
F_62 ( V_32 , V_115 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_5 F_94 ( struct V_114 * V_115 )
{
struct V_182 * V_153 = 0 ;
char * V_187 ;
V_153 = F_84 ( sizeof( * V_153 ) , V_67 ) ;
if ( V_153 == NULL )
return - V_171 ;
switch ( V_115 -> type ) {
default:
F_75 ( V_153 ) ;
return 0 ;
case V_183 :
V_187 = L_39 ;
V_153 -> V_149 = V_153 -> V_188 = V_115 -> V_1 ;
break;
case V_184 :
V_187 = L_40 ;
V_153 -> V_149 = 0 ;
V_153 -> V_188 = V_2 ;
break;
case V_185 :
V_187 = L_41 ;
V_153 -> V_149 = V_115 -> V_1 ;
V_153 -> V_188 = V_115 -> V_186 ;
break;
}
V_153 -> V_189 = F_95 ( V_115 -> V_118 ) ;
V_153 -> V_190 = V_153 -> V_189 + F_95 ( V_115 -> V_119 ) ;
V_153 -> V_191 = V_115 -> V_100 >> 1 ;
F_69 ( L_42
L_43 , V_187 ,
F_39 ( V_153 -> V_149 ) , F_40 ( V_153 -> V_149 ) ,
F_41 ( V_153 -> V_149 ) , F_39 ( V_153 -> V_188 ) ,
F_40 ( V_153 -> V_188 ) , F_41 ( V_153 -> V_188 ) ,
V_153 -> V_189 , V_153 -> V_190 , V_115 -> V_100 ) ;
F_78 ( & V_153 -> V_162 , & V_192 ) ;
return 0 ;
}
static int T_5 F_96 ( struct V_59 * V_60 )
{
T_3 * V_51 = ( T_3 * ) V_60 , * V_52 = ( T_3 * ) V_60 ;
struct V_114 * V_115 ;
V_52 += V_60 -> V_54 ;
V_51 += V_64 ;
while ( V_51 < V_52 ) {
V_115 = (struct V_114 * ) V_51 ;
if ( V_115 -> V_100 & V_116 )
F_93 ( V_115 ) ;
else if ( V_115 -> V_100 & V_193 )
F_94 ( V_115 ) ;
V_51 += V_115 -> V_54 ;
}
return 0 ;
}
static void F_97 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_57 ( V_1 , V_194 ) ;
F_57 ( V_1 , V_195 ) ;
}
}
static void F_98 ( struct V_6 * V_7 )
{
V_7 -> V_154 & V_196 ?
F_15 ( V_7 , V_197 ) :
F_18 ( V_7 , V_197 ) ;
V_7 -> V_154 & V_198 ?
F_15 ( V_7 , V_199 ) :
F_18 ( V_7 , V_199 ) ;
V_7 -> V_154 & V_200 ?
F_15 ( V_7 , V_201 ) :
F_18 ( V_7 , V_201 ) ;
V_7 -> V_154 & V_202 ?
F_15 ( V_7 , V_203 ) :
F_18 ( V_7 , V_203 ) ;
F_15 ( V_7 , V_204 ) ;
F_19 ( V_7 , V_205 ) ;
}
static void F_99 ( struct V_6 * V_7 )
{
int V_32 , V_124 ;
T_2 V_206 ;
struct V_207 * V_208 = NULL ;
if ( ! F_67 ( V_7 -> V_11 ) )
return;
V_208 = F_81 ( V_7 -> V_11 -> V_46 -> V_209 , F_100 ( 0 , 0 ) ) ;
if ( ! V_208 )
return;
F_5 ( V_208 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_208 , 0x64 , & V_206 ) ;
if ( ! ( V_206 & 0x1 ) )
F_5 ( V_208 , 0x64 , V_206 | 1 ) ;
F_101 ( V_208 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_34 + 4 ,
V_7 -> V_145 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_34 + 8 ,
V_7 -> V_146 ) ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
for ( V_124 = 0 ; V_124 < 0x12 ; V_124 ++ )
F_7 ( V_7 , V_32 , V_124 , V_7 -> V_147 [ V_32 ] [ V_124 ] ) ;
for ( V_32 = 0 ; V_32 < 0x83 ; V_32 ++ )
F_9 ( V_7 , V_32 , V_7 -> V_148 [ V_32 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_34 + 4 ,
V_7 -> V_145 | 1 ) ;
}
static void F_102 ( void )
{
struct V_6 * V_7 ;
F_103 (iommu) {
F_24 ( V_7 ) ;
F_98 ( V_7 ) ;
F_12 ( V_7 ) ;
F_47 ( V_7 ) ;
F_51 ( V_7 ) ;
F_54 ( V_7 ) ;
F_56 ( V_7 ) ;
F_10 ( V_7 ) ;
F_89 ( V_7 ) ;
F_20 ( V_7 ) ;
F_104 ( V_7 ) ;
}
}
static void F_105 ( void )
{
struct V_6 * V_7 ;
F_103 (iommu)
F_24 ( V_7 ) ;
}
static void F_106 ( void )
{
struct V_6 * V_7 ;
F_103 (iommu)
F_99 ( V_7 ) ;
F_102 () ;
}
static int F_107 ( void )
{
F_105 () ;
return 0 ;
}
static int T_5 F_108 ( void )
{
int V_32 , V_42 = 0 ;
if ( F_109 ( L_44 , F_43 ) != 0 )
return - V_63 ;
V_42 = V_62 ;
if ( V_42 )
goto V_210;
V_23 = F_2 ( V_211 ) ;
V_212 = F_2 ( V_213 ) ;
V_214 = F_2 ( V_215 ) ;
V_42 = - V_171 ;
V_22 = ( void * ) F_45 ( V_67 | V_68 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_210;
V_158 = ( void * ) F_45 ( V_67 ,
F_3 ( V_212 ) ) ;
if ( V_158 == NULL )
goto free;
V_99 = ( void * ) F_45 (
V_67 | V_68 ,
F_3 ( V_214 ) ) ;
if ( V_99 == NULL )
goto free;
V_216 = ( void * ) F_45 (
V_67 | V_68 ,
F_3 ( V_217 / 8 ) ) ;
if ( V_216 == NULL )
goto free;
F_97 () ;
for ( V_32 = 0 ; V_32 <= V_2 ; ++ V_32 )
V_158 [ V_32 ] = V_32 ;
V_216 [ 0 ] = 1 ;
F_77 ( & V_218 ) ;
V_42 = - V_63 ;
if ( F_109 ( L_44 , F_83 ) != 0 )
goto free;
if ( V_62 ) {
V_42 = V_62 ;
goto free;
}
if ( F_109 ( L_44 , F_96 ) != 0 )
goto free;
if ( V_62 ) {
V_42 = V_62 ;
goto free;
}
V_42 = F_110 () ;
if ( V_42 )
goto free;
F_102 () ;
if ( V_219 )
V_42 = F_111 () ;
else
V_42 = F_112 () ;
if ( V_42 )
goto V_220;
F_113 () ;
F_114 () ;
F_115 ( & V_221 ) ;
if ( V_219 )
goto V_210;
if ( V_222 )
F_21 ( V_33 L_45 ) ;
else
F_21 ( V_33 L_46 ) ;
V_223 . V_224 = F_105 ;
V_210:
return V_42 ;
V_220:
F_105 () ;
free:
F_116 () ;
F_49 ( ( unsigned long ) V_216 ,
F_3 ( V_217 / 8 ) ) ;
F_49 ( ( unsigned long ) V_99 ,
F_3 ( V_214 ) ) ;
F_49 ( ( unsigned long ) V_158 ,
F_3 ( V_212 ) ) ;
F_49 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_72 () ;
F_91 () ;
#ifdef F_117
F_118 () ;
#endif
goto V_210;
}
static int T_5 F_119 ( struct V_59 * V_60 )
{
return 0 ;
}
int T_5 F_120 ( void )
{
if ( V_225 || ( V_226 && ! V_227 ) )
return - V_63 ;
if ( V_228 )
return - V_63 ;
if ( F_109 ( L_44 , F_119 ) == 0 ) {
V_226 = 1 ;
V_229 = 1 ;
V_230 . V_7 . V_231 = F_108 ;
F_121 () ;
return 1 ;
}
return - V_63 ;
}
static int T_5 F_122 ( char * V_232 )
{
V_233 = true ;
return 1 ;
}
static int T_5 F_123 ( char * V_232 )
{
for (; * V_232 ; ++ V_232 ) {
if ( strncmp ( V_232 , L_47 , 9 ) == 0 )
V_222 = true ;
if ( strncmp ( V_232 , L_48 , 3 ) == 0 )
V_228 = true ;
if ( strncmp ( V_232 , L_49 , 15 ) == 0 )
V_234 = true ;
}
return 1 ;
}
bool F_124 ( void )
{
return V_144 ;
}
