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
F_15 ( V_7 , V_31 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_32 ) ;
F_18 ( V_7 , V_33 ) ;
F_18 ( V_7 , V_34 ) ;
F_18 ( V_7 , V_31 ) ;
}
static T_3 T_5 * T_6 F_22 ( T_4 V_9 )
{
if ( ! F_23 ( V_9 , V_35 , L_1 ) ) {
F_24 ( L_2 ,
V_9 ) ;
F_24 ( L_3 ) ;
return NULL ;
}
return ( T_3 T_5 * ) F_25 ( V_9 , V_35 ) ;
}
static void T_6 F_26 ( struct V_6 * V_7 )
{
if ( V_7 -> V_19 )
F_27 ( V_7 -> V_19 ) ;
F_28 ( V_7 -> V_36 , V_35 ) ;
}
static inline int F_29 ( T_3 * V_37 )
{
return 0x04 << ( * V_37 >> 6 ) ;
}
static int T_6 F_30 ( int V_38 , int V_11 , int V_39 , int V_40 )
{
T_2 V_41 ;
V_41 = F_31 ( V_38 , V_11 , V_39 , V_40 + V_42 ) ;
F_1 ( F_32 ( F_33 ( V_41 ) , F_34 ( V_41 ) ) ) ;
return 0 ;
}
static int T_6 F_35 ( struct V_43 * V_44 )
{
T_3 * V_45 = ( void * ) V_44 , * V_46 = ( void * ) V_44 ;
struct V_47 * V_11 ;
V_45 += sizeof( * V_44 ) ;
V_46 += V_44 -> V_48 ;
F_30 ( F_36 ( V_44 -> V_1 ) ,
F_37 ( V_44 -> V_1 ) ,
F_38 ( V_44 -> V_1 ) ,
V_44 -> V_40 ) ;
while ( V_45 < V_46 ) {
V_11 = (struct V_47 * ) V_45 ;
switch ( V_11 -> type ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_1 ( V_11 -> V_1 ) ;
break;
default:
break;
}
V_45 += F_29 ( V_45 ) ;
}
F_39 ( V_45 != V_46 ) ;
return 0 ;
}
static int T_6 F_40 ( struct V_53 * V_54 )
{
int V_55 ;
T_3 V_56 = 0 , * V_45 = ( T_3 * ) V_54 , * V_46 = ( T_3 * ) V_54 ;
struct V_43 * V_44 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_48 ; ++ V_55 )
V_56 += V_45 [ V_55 ] ;
if ( V_56 != 0 )
return - V_57 ;
V_45 += V_58 ;
V_46 += V_54 -> V_48 ;
while ( V_45 < V_46 ) {
V_44 = (struct V_43 * ) V_45 ;
switch ( V_44 -> type ) {
case V_59 :
F_35 ( V_44 ) ;
break;
default:
break;
}
V_45 += V_44 -> V_48 ;
}
F_39 ( V_45 != V_46 ) ;
return 0 ;
}
static T_3 * T_6 F_41 ( struct V_6 * V_7 )
{
T_3 * V_60 = ( T_3 * ) F_42 ( V_61 | V_62 ,
F_3 ( V_63 ) ) ;
if ( V_60 == NULL )
return NULL ;
V_7 -> V_64 = V_63 | V_65 ;
return V_60 ;
}
void F_43 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_32 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_66 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_67 ) ;
F_15 ( V_7 , V_32 ) ;
}
static void F_44 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_60 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_60 ) ;
V_17 |= V_68 ;
F_11 ( V_7 -> V_19 + V_69 ,
& V_17 , sizeof( V_17 ) ) ;
F_43 ( V_7 ) ;
V_7 -> V_64 &= ~ ( V_65 ) ;
}
static void T_6 F_45 ( struct V_6 * V_7 )
{
F_46 ( ( unsigned long ) V_7 -> V_60 ,
F_3 ( V_7 -> V_64 & ~ ( V_65 ) ) ) ;
}
static T_3 * T_6 F_47 ( struct V_6 * V_7 )
{
V_7 -> V_70 = ( T_3 * ) F_42 ( V_61 | V_62 ,
F_3 ( V_71 ) ) ;
if ( V_7 -> V_70 == NULL )
return NULL ;
V_7 -> V_72 = V_71 ;
return V_7 -> V_70 ;
}
static void F_48 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_70 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_70 ) | V_73 ;
F_11 ( V_7 -> V_19 + V_74 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_75 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_76 ) ;
F_15 ( V_7 , V_34 ) ;
}
static void T_6 F_49 ( struct V_6 * V_7 )
{
F_46 ( ( unsigned long ) V_7 -> V_70 , F_3 ( V_71 ) ) ;
}
static T_3 * T_6 F_50 ( struct V_6 * V_7 )
{
V_7 -> V_77 = ( T_3 * ) F_42 ( V_61 | V_62 ,
F_3 ( V_78 ) ) ;
if ( V_7 -> V_77 == NULL )
return NULL ;
return V_7 -> V_77 ;
}
static void F_51 ( struct V_6 * V_7 )
{
T_4 V_17 ;
if ( V_7 -> V_77 == NULL )
return;
V_17 = ( T_4 ) F_14 ( V_7 -> V_77 ) | V_79 ;
F_11 ( V_7 -> V_19 + V_80 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_81 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_82 ) ;
F_15 ( V_7 , V_83 ) ;
F_15 ( V_7 , V_84 ) ;
}
static void T_6 F_52 ( struct V_6 * V_7 )
{
if ( V_7 -> V_77 == NULL )
return;
F_46 ( ( unsigned long ) V_7 -> V_77 , F_3 ( V_78 ) ) ;
}
static void F_53 ( struct V_6 * V_7 )
{
if ( ! F_54 ( V_7 , V_85 ) )
return;
F_15 ( V_7 , V_86 ) ;
}
static void F_55 ( T_1 V_1 , T_3 V_25 )
{
int V_55 = ( V_25 >> 6 ) & 0x03 ;
int V_87 = V_25 & 0x3f ;
V_22 [ V_1 ] . V_88 [ V_55 ] |= ( 1UL << V_87 ) ;
}
static int F_56 ( T_1 V_1 , T_3 V_25 )
{
int V_55 = ( V_25 >> 6 ) & 0x03 ;
int V_87 = V_25 & 0x3f ;
return ( V_22 [ V_1 ] . V_88 [ V_55 ] & ( 1UL << V_87 ) ) >> V_87 ;
}
void F_57 ( T_1 V_1 )
{
int V_89 ;
V_89 = F_56 ( V_1 , V_90 ) |
( F_56 ( V_1 , V_91 ) << 1 ) ;
if ( V_89 == 0x01 )
F_55 ( V_1 , V_92 ) ;
}
static void T_6 F_58 ( struct V_6 * V_7 , T_1 V_1 )
{
V_93 [ V_1 ] = V_7 ;
}
static void T_6 F_59 ( struct V_6 * V_7 ,
T_1 V_1 , T_2 V_94 , T_2 V_95 )
{
if ( V_94 & V_96 )
F_55 ( V_1 , V_97 ) ;
if ( V_94 & V_98 )
F_55 ( V_1 , V_99 ) ;
if ( V_94 & V_100 )
F_55 ( V_1 , V_101 ) ;
if ( V_94 & V_102 )
F_55 ( V_1 , V_90 ) ;
if ( V_94 & V_103 )
F_55 ( V_1 , V_91 ) ;
if ( V_94 & V_104 )
F_55 ( V_1 , V_105 ) ;
if ( V_94 & V_106 )
F_55 ( V_1 , V_107 ) ;
F_57 ( V_1 ) ;
F_58 ( V_7 , V_1 ) ;
}
static void T_6 F_60 ( T_1 V_1 , struct V_108 * V_109 )
{
struct V_6 * V_7 = V_93 [ V_1 ] ;
if ( ! ( V_109 -> V_94 & V_110 ) )
return;
if ( V_7 ) {
F_55 ( V_109 -> V_1 , V_111 ) ;
V_7 -> V_13 = V_109 -> V_112 ;
V_7 -> V_16 = V_109 -> V_113 ;
}
}
static void T_6 F_61 ( struct V_6 * V_7 ,
struct V_43 * V_44 )
{
T_3 * V_45 = ( T_3 * ) V_44 ;
T_3 * V_46 = V_45 , V_94 = 0 ;
T_1 V_1 = 0 , V_114 = 0 , V_115 = 0 ;
T_2 V_116 , V_95 = 0 ;
bool V_117 = false ;
struct V_47 * V_118 ;
V_7 -> V_119 = V_44 -> V_94 ;
V_45 += sizeof( struct V_43 ) ;
V_46 += V_44 -> V_48 ;
while ( V_45 < V_46 ) {
V_118 = (struct V_47 * ) V_45 ;
switch ( V_118 -> type ) {
case V_120 :
F_62 ( L_4
L_5 ,
F_36 ( V_7 -> V_121 ) ,
F_37 ( V_7 -> V_121 ) ,
F_38 ( V_7 -> V_121 ) ,
F_36 ( V_7 -> V_122 ) ,
F_37 ( V_7 -> V_122 ) ,
F_38 ( V_7 -> V_122 ) ,
V_118 -> V_94 ) ;
for ( V_116 = V_7 -> V_121 ;
V_116 <= V_7 -> V_122 ; ++ V_116 )
F_59 ( V_7 , V_116 ,
V_118 -> V_94 , 0 ) ;
break;
case V_49 :
F_62 ( L_6
L_7 ,
F_36 ( V_118 -> V_1 ) ,
F_37 ( V_118 -> V_1 ) ,
F_38 ( V_118 -> V_1 ) ,
V_118 -> V_94 ) ;
V_1 = V_118 -> V_1 ;
F_59 ( V_7 , V_1 , V_118 -> V_94 , 0 ) ;
break;
case V_123 :
F_62 ( L_8
L_9 ,
F_36 ( V_118 -> V_1 ) ,
F_37 ( V_118 -> V_1 ) ,
F_38 ( V_118 -> V_1 ) ,
V_118 -> V_94 ) ;
V_114 = V_118 -> V_1 ;
V_94 = V_118 -> V_94 ;
V_95 = 0 ;
V_117 = false ;
break;
case V_51 :
F_62 ( L_10
L_11 ,
F_36 ( V_118 -> V_1 ) ,
F_37 ( V_118 -> V_1 ) ,
F_38 ( V_118 -> V_1 ) ,
V_118 -> V_94 ,
F_36 ( V_118 -> V_124 >> 8 ) ,
F_37 ( V_118 -> V_124 >> 8 ) ,
F_38 ( V_118 -> V_124 >> 8 ) ) ;
V_1 = V_118 -> V_1 ;
V_115 = V_118 -> V_124 >> 8 ;
F_59 ( V_7 , V_1 , V_118 -> V_94 , 0 ) ;
F_59 ( V_7 , V_115 , V_118 -> V_94 , 0 ) ;
V_125 [ V_1 ] = V_115 ;
break;
case V_126 :
F_62 ( L_12
L_13
L_14 ,
F_36 ( V_118 -> V_1 ) ,
F_37 ( V_118 -> V_1 ) ,
F_38 ( V_118 -> V_1 ) ,
V_118 -> V_94 ,
F_36 ( V_118 -> V_124 >> 8 ) ,
F_37 ( V_118 -> V_124 >> 8 ) ,
F_38 ( V_118 -> V_124 >> 8 ) ) ;
V_114 = V_118 -> V_1 ;
V_94 = V_118 -> V_94 ;
V_115 = V_118 -> V_124 >> 8 ;
V_95 = 0 ;
V_117 = true ;
break;
case V_52 :
F_62 ( L_15
L_16 ,
F_36 ( V_118 -> V_1 ) ,
F_37 ( V_118 -> V_1 ) ,
F_38 ( V_118 -> V_1 ) ,
V_118 -> V_94 , V_118 -> V_124 ) ;
V_1 = V_118 -> V_1 ;
F_59 ( V_7 , V_1 , V_118 -> V_94 ,
V_118 -> V_124 ) ;
break;
case V_127 :
F_62 ( L_17
L_18 ,
F_36 ( V_118 -> V_1 ) ,
F_37 ( V_118 -> V_1 ) ,
F_38 ( V_118 -> V_1 ) ,
V_118 -> V_94 , V_118 -> V_124 ) ;
V_114 = V_118 -> V_1 ;
V_94 = V_118 -> V_94 ;
V_95 = V_118 -> V_124 ;
V_117 = false ;
break;
case V_50 :
F_62 ( L_19 ,
F_36 ( V_118 -> V_1 ) ,
F_37 ( V_118 -> V_1 ) ,
F_38 ( V_118 -> V_1 ) ) ;
V_1 = V_118 -> V_1 ;
for ( V_116 = V_114 ; V_116 <= V_1 ; ++ V_116 ) {
if ( V_117 ) {
V_125 [ V_116 ] = V_115 ;
F_59 ( V_7 ,
V_115 , V_94 , V_95 ) ;
}
F_59 ( V_7 , V_116 ,
V_94 , V_95 ) ;
}
break;
default:
break;
}
V_45 += F_29 ( V_45 ) ;
}
}
static int T_6 F_63 ( struct V_6 * V_7 )
{
T_2 V_55 ;
for ( V_55 = V_7 -> V_121 ; V_55 <= V_7 -> V_122 ; ++ V_55 )
F_58 ( V_7 , V_55 ) ;
return 0 ;
}
static void T_6 F_64 ( struct V_6 * V_7 )
{
F_45 ( V_7 ) ;
F_49 ( V_7 ) ;
F_52 ( V_7 ) ;
F_26 ( V_7 ) ;
}
static void T_6 F_65 ( void )
{
struct V_6 * V_7 , * V_128 ;
F_66 (iommu, next) {
F_67 ( & V_7 -> V_129 ) ;
F_64 ( V_7 ) ;
F_68 ( V_7 ) ;
}
}
static int T_6 F_69 ( struct V_6 * V_7 , struct V_43 * V_44 )
{
F_70 ( & V_7 -> V_130 ) ;
F_71 ( & V_7 -> V_129 , & V_131 ) ;
V_7 -> V_132 = V_133 ++ ;
if ( F_72 ( V_7 -> V_132 >= V_134 ) ) {
F_73 ( 1 , L_20 ) ;
return - V_135 ;
}
V_136 [ V_7 -> V_132 ] = V_7 ;
V_7 -> V_1 = V_44 -> V_1 ;
V_7 -> V_40 = V_44 -> V_40 ;
V_7 -> V_137 = V_44 -> V_137 ;
V_7 -> V_36 = V_44 -> V_36 ;
V_7 -> V_19 = F_22 ( V_44 -> V_36 ) ;
if ( ! V_7 -> V_19 )
return - V_138 ;
V_7 -> V_60 = F_41 ( V_7 ) ;
if ( ! V_7 -> V_60 )
return - V_138 ;
V_7 -> V_70 = F_47 ( V_7 ) ;
if ( ! V_7 -> V_70 )
return - V_138 ;
V_7 -> V_139 = false ;
F_61 ( V_7 , V_44 ) ;
F_63 ( V_7 ) ;
return 0 ;
}
static int T_6 F_74 ( struct V_53 * V_54 )
{
T_3 * V_45 = ( T_3 * ) V_54 , * V_46 = ( T_3 * ) V_54 ;
struct V_43 * V_44 ;
struct V_6 * V_7 ;
int V_140 ;
V_46 += V_54 -> V_48 ;
V_45 += V_58 ;
while ( V_45 < V_46 ) {
V_44 = (struct V_43 * ) V_45 ;
switch ( * V_45 ) {
case V_59 :
F_62 ( L_21
L_22 ,
F_36 ( V_44 -> V_1 ) , F_37 ( V_44 -> V_1 ) ,
F_38 ( V_44 -> V_1 ) , V_44 -> V_40 ,
V_44 -> V_137 , V_44 -> V_94 , V_44 -> V_141 ) ;
F_62 ( L_23 ,
V_44 -> V_36 ) ;
V_7 = F_75 ( sizeof( struct V_6 ) , V_61 ) ;
if ( V_7 == NULL )
return - V_138 ;
V_140 = F_69 ( V_7 , V_44 ) ;
if ( V_140 )
return V_140 ;
break;
default:
break;
}
V_45 += V_44 -> V_48 ;
}
F_39 ( V_45 != V_46 ) ;
return 0 ;
}
static int F_76 ( struct V_6 * V_7 )
{
int V_40 = V_7 -> V_40 ;
T_2 V_142 , V_143 , V_144 , V_145 ;
V_7 -> V_11 = F_77 ( F_36 ( V_7 -> V_1 ) ,
V_7 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return - V_57 ;
F_6 ( V_7 -> V_11 , V_40 + V_146 ,
& V_7 -> V_41 ) ;
F_6 ( V_7 -> V_11 , V_40 + V_42 ,
& V_142 ) ;
F_6 ( V_7 -> V_11 , V_40 + V_147 ,
& V_143 ) ;
V_7 -> V_121 = F_32 ( F_33 ( V_142 ) ,
F_78 ( V_142 ) ) ;
V_7 -> V_122 = F_32 ( F_33 ( V_142 ) ,
F_34 ( V_142 ) ) ;
if ( ! ( V_7 -> V_41 & ( 1 << V_148 ) ) )
V_149 = false ;
V_144 = F_16 ( V_7 -> V_19 + V_150 ) ;
V_145 = F_16 ( V_7 -> V_19 + V_150 + 4 ) ;
V_7 -> V_151 = ( ( T_4 ) V_145 << 32 ) | V_144 ;
if ( F_54 ( V_7 , V_85 ) ) {
int V_152 ;
T_2 V_153 ;
T_4 V_4 ;
V_4 = V_7 -> V_151 & V_154 ;
V_4 >>= V_155 ;
V_153 = ( 1 << V_4 ) ;
V_156 = F_79 ( V_156 , V_153 ) ;
V_152 = V_7 -> V_151 & V_157 ;
V_152 >>= V_158 ;
if ( V_159 == - 1 )
V_159 = V_152 ;
else
V_159 = F_79 ( V_159 , V_152 ) ;
}
if ( F_54 ( V_7 , V_85 ) &&
F_54 ( V_7 , V_160 ) ) {
V_7 -> V_161 = true ;
V_162 = true ;
}
if ( F_54 ( V_7 , V_160 ) ) {
V_7 -> V_77 = F_50 ( V_7 ) ;
if ( ! V_7 -> V_77 )
return - V_138 ;
}
if ( V_7 -> V_41 & ( 1UL << V_163 ) )
V_164 = true ;
if ( F_80 ( V_7 -> V_11 ) ) {
int V_55 , V_165 ;
V_7 -> V_166 = F_77 ( V_7 -> V_11 -> V_38 -> V_167 ,
F_81 ( 0 , 0 ) ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
& V_7 -> V_168 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_40 + 8 ,
& V_7 -> V_169 ) ;
V_7 -> V_168 &= ~ 1 ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_165 = 0 ; V_165 < 0x12 ; V_165 ++ )
V_7 -> V_170 [ V_55 ] [ V_165 ] = F_4 ( V_7 , V_55 , V_165 ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
V_7 -> V_171 [ V_55 ] = F_8 ( V_7 , V_55 ) ;
}
return F_82 ( V_7 -> V_11 ) ;
}
static void F_83 ( void )
{
static const char * const V_172 [] = {
L_24 , L_25 , L_26 , L_27 , L_28 , L_29 ,
L_30 , L_31 , L_32 , L_33
} ;
struct V_6 * V_7 ;
F_84 (iommu) {
int V_55 ;
F_85 ( L_34 ,
F_86 ( & V_7 -> V_11 -> V_11 ) , V_7 -> V_40 ) ;
if ( V_7 -> V_41 & ( 1 << V_173 ) ) {
F_85 ( L_35 ) ;
for ( V_55 = 0 ; V_55 < F_87 ( V_172 ) ; ++ V_55 ) {
if ( F_54 ( V_7 , ( 1ULL << V_55 ) ) )
F_88 ( L_36 , V_172 [ V_55 ] ) ;
}
}
F_88 ( L_37 ) ;
}
}
static int T_6 F_89 ( void )
{
struct V_6 * V_7 ;
int V_140 = 0 ;
F_84 (iommu) {
V_140 = F_76 ( V_7 ) ;
if ( V_140 )
break;
}
V_140 = F_90 () ;
F_83 () ;
return V_140 ;
}
static int F_91 ( struct V_6 * V_7 )
{
int V_174 ;
V_174 = F_92 ( V_7 -> V_11 ) ;
if ( V_174 )
return V_174 ;
V_174 = F_93 ( V_7 -> V_11 -> V_175 ,
V_176 ,
V_177 ,
0 , L_38 ,
V_7 -> V_11 ) ;
if ( V_174 ) {
F_94 ( V_7 -> V_11 ) ;
return V_174 ;
}
V_7 -> V_139 = true ;
return 0 ;
}
static int F_95 ( struct V_6 * V_7 )
{
int V_140 ;
if ( V_7 -> V_139 )
goto V_178;
if ( F_96 ( V_7 -> V_11 , V_179 ) )
V_140 = F_91 ( V_7 ) ;
else
V_140 = - V_57 ;
if ( V_140 )
return V_140 ;
V_178:
F_15 ( V_7 , V_33 ) ;
if ( V_7 -> V_77 != NULL )
F_15 ( V_7 , V_180 ) ;
return 0 ;
}
static void T_6 F_97 ( void )
{
struct V_181 * V_17 , * V_128 ;
F_98 (entry, next, &amd_iommu_unity_map, list) {
F_67 ( & V_17 -> V_129 ) ;
F_68 ( V_17 ) ;
}
}
static int T_6 F_99 ( struct V_108 * V_109 )
{
int V_55 ;
switch ( V_109 -> type ) {
case V_182 :
F_60 ( V_109 -> V_1 , V_109 ) ;
break;
case V_183 :
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
F_60 ( V_55 , V_109 ) ;
break;
case V_184 :
for ( V_55 = V_109 -> V_1 ; V_55 <= V_109 -> V_185 ; ++ V_55 )
F_60 ( V_55 , V_109 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_100 ( struct V_108 * V_109 )
{
struct V_181 * V_118 = NULL ;
char * V_186 ;
V_118 = F_75 ( sizeof( * V_118 ) , V_61 ) ;
if ( V_118 == NULL )
return - V_138 ;
switch ( V_109 -> type ) {
default:
F_68 ( V_118 ) ;
return 0 ;
case V_182 :
V_186 = L_39 ;
V_118 -> V_114 = V_118 -> V_187 = V_109 -> V_1 ;
break;
case V_183 :
V_186 = L_40 ;
V_118 -> V_114 = 0 ;
V_118 -> V_187 = V_2 ;
break;
case V_184 :
V_186 = L_41 ;
V_118 -> V_114 = V_109 -> V_1 ;
V_118 -> V_187 = V_109 -> V_185 ;
break;
}
V_118 -> V_188 = F_101 ( V_109 -> V_112 ) ;
V_118 -> V_189 = V_118 -> V_188 + F_101 ( V_109 -> V_113 ) ;
V_118 -> V_190 = V_109 -> V_94 >> 1 ;
F_62 ( L_42
L_43 , V_186 ,
F_36 ( V_118 -> V_114 ) , F_37 ( V_118 -> V_114 ) ,
F_38 ( V_118 -> V_114 ) , F_36 ( V_118 -> V_187 ) ,
F_37 ( V_118 -> V_187 ) , F_38 ( V_118 -> V_187 ) ,
V_118 -> V_188 , V_118 -> V_189 , V_109 -> V_94 ) ;
F_71 ( & V_118 -> V_129 , & V_191 ) ;
return 0 ;
}
static int T_6 F_102 ( struct V_53 * V_54 )
{
T_3 * V_45 = ( T_3 * ) V_54 , * V_46 = ( T_3 * ) V_54 ;
struct V_108 * V_109 ;
V_46 += V_54 -> V_48 ;
V_45 += V_58 ;
while ( V_45 < V_46 ) {
V_109 = (struct V_108 * ) V_45 ;
if ( V_109 -> V_94 & V_110 )
F_99 ( V_109 ) ;
else if ( V_109 -> V_94 & V_192 )
F_100 ( V_109 ) ;
V_45 += V_109 -> V_48 ;
}
return 0 ;
}
static void F_103 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_55 ( V_1 , V_193 ) ;
F_55 ( V_1 , V_194 ) ;
}
}
static void F_104 ( struct V_6 * V_7 )
{
V_7 -> V_119 & V_195 ?
F_15 ( V_7 , V_196 ) :
F_18 ( V_7 , V_196 ) ;
V_7 -> V_119 & V_197 ?
F_15 ( V_7 , V_198 ) :
F_18 ( V_7 , V_198 ) ;
V_7 -> V_119 & V_199 ?
F_15 ( V_7 , V_200 ) :
F_18 ( V_7 , V_200 ) ;
V_7 -> V_119 & V_201 ?
F_15 ( V_7 , V_202 ) :
F_18 ( V_7 , V_202 ) ;
F_15 ( V_7 , V_203 ) ;
F_19 ( V_7 , V_204 ) ;
}
static void F_105 ( struct V_6 * V_7 )
{
int V_55 , V_165 ;
T_2 V_205 ;
struct V_206 * V_207 = V_7 -> V_166 ;
if ( ! F_80 ( V_7 -> V_11 ) || ! V_207 )
return;
F_5 ( V_207 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_207 , 0x64 , & V_205 ) ;
if ( ! ( V_205 & 0x1 ) )
F_5 ( V_207 , 0x64 , V_205 | 1 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
V_7 -> V_168 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 8 ,
V_7 -> V_169 ) ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_165 = 0 ; V_165 < 0x12 ; V_165 ++ )
F_7 ( V_7 , V_55 , V_165 , V_7 -> V_170 [ V_55 ] [ V_165 ] ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
F_9 ( V_7 , V_55 , V_7 -> V_171 [ V_55 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
V_7 -> V_168 | 1 ) ;
}
static void F_106 ( void )
{
struct V_6 * V_7 ;
F_84 (iommu) {
F_21 ( V_7 ) ;
F_104 ( V_7 ) ;
F_12 ( V_7 ) ;
F_44 ( V_7 ) ;
F_48 ( V_7 ) ;
F_10 ( V_7 ) ;
F_20 ( V_7 ) ;
F_107 ( V_7 ) ;
}
}
static void F_108 ( void )
{
struct V_6 * V_7 ;
F_84 (iommu) {
F_51 ( V_7 ) ;
F_53 ( V_7 ) ;
}
}
static void F_109 ( void )
{
F_106 () ;
F_108 () ;
}
static void F_110 ( void )
{
struct V_6 * V_7 ;
F_84 (iommu)
F_21 ( V_7 ) ;
}
static void F_111 ( void )
{
struct V_6 * V_7 ;
F_84 (iommu)
F_105 ( V_7 ) ;
F_109 () ;
F_112 () ;
}
static int F_113 ( void )
{
F_110 () ;
return 0 ;
}
static void T_6 F_114 ( void )
{
F_115 () ;
F_46 ( ( unsigned long ) V_208 ,
F_3 ( V_209 / 8 ) ) ;
F_46 ( ( unsigned long ) V_93 ,
F_3 ( V_210 ) ) ;
F_46 ( ( unsigned long ) V_125 ,
F_3 ( V_211 ) ) ;
F_46 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_65 () ;
F_97 () ;
#ifdef F_116
F_117 () ;
#endif
}
static int T_6 F_118 ( void )
{
struct V_53 * V_212 ;
T_7 V_213 ;
T_8 V_214 ;
int V_55 , V_140 = 0 ;
if ( ! V_215 )
return - V_57 ;
V_214 = F_119 ( L_44 , 0 , & V_212 , & V_213 ) ;
if ( V_214 == V_216 )
return - V_57 ;
else if ( F_120 ( V_214 ) ) {
const char * V_217 = F_121 ( V_214 ) ;
F_24 ( L_45 , V_217 ) ;
return - V_218 ;
}
V_140 = F_40 ( V_212 ) ;
if ( V_140 )
goto V_219;
V_23 = F_2 ( V_220 ) ;
V_211 = F_2 ( V_221 ) ;
V_210 = F_2 ( V_222 ) ;
V_140 = - V_138 ;
V_22 = ( void * ) F_42 ( V_61 | V_62 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_219;
V_125 = ( void * ) F_42 ( V_61 ,
F_3 ( V_211 ) ) ;
if ( V_125 == NULL )
goto V_219;
V_93 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_210 ) ) ;
if ( V_93 == NULL )
goto V_219;
V_208 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_209 / 8 ) ) ;
if ( V_208 == NULL )
goto V_219;
F_103 () ;
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
V_125 [ V_55 ] = V_55 ;
V_208 [ 0 ] = 1 ;
F_70 ( & V_223 ) ;
V_140 = F_74 ( V_212 ) ;
if ( V_140 )
goto V_219;
V_140 = F_102 ( V_212 ) ;
if ( V_140 )
goto V_219;
V_219:
F_122 ( ( char T_5 * ) V_212 , V_213 ) ;
V_212 = NULL ;
return V_140 ;
}
static int F_112 ( void )
{
struct V_6 * V_7 ;
int V_140 = 0 ;
F_84 (iommu) {
V_140 = F_95 ( V_7 ) ;
if ( V_140 )
goto V_219;
}
V_219:
return V_140 ;
}
static bool F_123 ( void )
{
struct V_53 * V_212 ;
T_7 V_213 ;
T_8 V_214 ;
V_214 = F_119 ( L_44 , 0 , & V_212 , & V_213 ) ;
if ( V_214 == V_216 )
return false ;
else if ( F_120 ( V_214 ) ) {
const char * V_217 = F_121 ( V_214 ) ;
F_24 ( L_45 , V_217 ) ;
return false ;
}
F_122 ( ( char T_5 * ) V_212 , V_213 ) ;
F_124 () ;
return true ;
}
static int F_125 ( void )
{
int V_140 ;
if ( V_224 )
V_140 = F_126 () ;
else
V_140 = F_127 () ;
if ( V_140 )
return V_140 ;
F_128 () ;
F_129 () ;
return 0 ;
}
static int T_6 F_130 ( void )
{
int V_140 = 0 ;
switch ( V_225 ) {
case V_226 :
if ( ! F_123 () ) {
V_225 = V_227 ;
V_140 = - V_57 ;
} else {
V_225 = V_228 ;
}
break;
case V_228 :
V_140 = F_118 () ;
V_225 = V_140 ? V_229 : V_230 ;
break;
case V_230 :
F_106 () ;
F_131 ( & V_231 ) ;
V_232 . V_233 = F_110 ;
V_225 = V_234 ;
break;
case V_234 :
V_140 = F_89 () ;
V_225 = V_140 ? V_229 : V_235 ;
F_108 () ;
break;
case V_235 :
V_140 = F_112 () ;
V_225 = V_140 ? V_229 : V_236 ;
break;
case V_236 :
V_140 = F_125 () ;
V_225 = V_140 ? V_229 : V_237 ;
break;
case V_237 :
V_225 = V_238 ;
break;
case V_238 :
break;
case V_227 :
case V_229 :
V_140 = - V_218 ;
break;
default:
F_132 () ;
}
return V_140 ;
}
static int T_6 F_133 ( enum V_239 V_240 )
{
int V_140 = 0 ;
while ( V_225 != V_240 ) {
V_140 = F_130 () ;
if ( V_225 == V_227 ||
V_225 == V_229 )
break;
}
return V_140 ;
}
static int T_6 F_134 ( void )
{
int V_140 ;
V_140 = F_133 ( V_238 ) ;
if ( V_140 ) {
F_110 () ;
F_114 () ;
}
return V_140 ;
}
int T_6 F_135 ( void )
{
int V_140 ;
if ( V_241 || ( V_242 && ! V_243 ) )
return - V_57 ;
if ( V_244 )
return - V_57 ;
V_140 = F_133 ( V_228 ) ;
if ( V_140 )
return V_140 ;
V_215 = true ;
V_242 = 1 ;
V_245 . V_7 . V_246 = F_134 ;
return 0 ;
}
static int T_6 F_136 ( char * V_247 )
{
V_248 = true ;
return 1 ;
}
static int T_6 F_137 ( char * V_247 )
{
for (; * V_247 ; ++ V_247 ) {
if ( strncmp ( V_247 , L_46 , 9 ) == 0 )
V_249 = true ;
if ( strncmp ( V_247 , L_47 , 3 ) == 0 )
V_244 = true ;
if ( strncmp ( V_247 , L_48 , 15 ) == 0 )
V_250 = true ;
}
return 1 ;
}
bool F_138 ( void )
{
return V_162 ;
}
