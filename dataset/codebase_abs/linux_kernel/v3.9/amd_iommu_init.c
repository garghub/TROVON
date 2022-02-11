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
static int F_60 ( T_3 type , T_3 V_108 , T_1 V_1 )
{
struct V_109 * V_17 ;
struct V_110 * V_111 ;
if ( type != V_112 && type != V_113 )
return - V_114 ;
V_17 = F_61 ( sizeof( * V_17 ) , V_61 ) ;
if ( ! V_17 )
return - V_115 ;
V_17 -> V_108 = V_108 ;
V_17 -> V_1 = V_1 ;
if ( type == V_112 )
V_111 = & V_116 ;
else
V_111 = & V_117 ;
F_62 ( & V_17 -> V_111 , V_111 ) ;
return 0 ;
}
static void T_6 F_63 ( T_1 V_1 , struct V_118 * V_119 )
{
struct V_6 * V_7 = V_93 [ V_1 ] ;
if ( ! ( V_119 -> V_94 & V_120 ) )
return;
if ( V_7 ) {
F_55 ( V_119 -> V_1 , V_121 ) ;
V_7 -> V_13 = V_119 -> V_122 ;
V_7 -> V_16 = V_119 -> V_123 ;
}
}
static int T_6 F_64 ( struct V_6 * V_7 ,
struct V_43 * V_44 )
{
T_3 * V_45 = ( T_3 * ) V_44 ;
T_3 * V_46 = V_45 , V_94 = 0 ;
T_1 V_1 = 0 , V_124 = 0 , V_125 = 0 ;
T_2 V_126 , V_95 = 0 ;
bool V_127 = false ;
struct V_47 * V_128 ;
V_7 -> V_129 = V_44 -> V_94 ;
V_45 += sizeof( struct V_43 ) ;
V_46 += V_44 -> V_48 ;
while ( V_45 < V_46 ) {
V_128 = (struct V_47 * ) V_45 ;
switch ( V_128 -> type ) {
case V_130 :
F_65 ( L_4
L_5 ,
F_36 ( V_7 -> V_131 ) ,
F_37 ( V_7 -> V_131 ) ,
F_38 ( V_7 -> V_131 ) ,
F_36 ( V_7 -> V_132 ) ,
F_37 ( V_7 -> V_132 ) ,
F_38 ( V_7 -> V_132 ) ,
V_128 -> V_94 ) ;
for ( V_126 = V_7 -> V_131 ;
V_126 <= V_7 -> V_132 ; ++ V_126 )
F_59 ( V_7 , V_126 ,
V_128 -> V_94 , 0 ) ;
break;
case V_49 :
F_65 ( L_6
L_7 ,
F_36 ( V_128 -> V_1 ) ,
F_37 ( V_128 -> V_1 ) ,
F_38 ( V_128 -> V_1 ) ,
V_128 -> V_94 ) ;
V_1 = V_128 -> V_1 ;
F_59 ( V_7 , V_1 , V_128 -> V_94 , 0 ) ;
break;
case V_133 :
F_65 ( L_8
L_9 ,
F_36 ( V_128 -> V_1 ) ,
F_37 ( V_128 -> V_1 ) ,
F_38 ( V_128 -> V_1 ) ,
V_128 -> V_94 ) ;
V_124 = V_128 -> V_1 ;
V_94 = V_128 -> V_94 ;
V_95 = 0 ;
V_127 = false ;
break;
case V_51 :
F_65 ( L_10
L_11 ,
F_36 ( V_128 -> V_1 ) ,
F_37 ( V_128 -> V_1 ) ,
F_38 ( V_128 -> V_1 ) ,
V_128 -> V_94 ,
F_36 ( V_128 -> V_134 >> 8 ) ,
F_37 ( V_128 -> V_134 >> 8 ) ,
F_38 ( V_128 -> V_134 >> 8 ) ) ;
V_1 = V_128 -> V_1 ;
V_125 = V_128 -> V_134 >> 8 ;
F_59 ( V_7 , V_1 , V_128 -> V_94 , 0 ) ;
F_59 ( V_7 , V_125 , V_128 -> V_94 , 0 ) ;
V_135 [ V_1 ] = V_125 ;
break;
case V_136 :
F_65 ( L_12
L_13
L_14 ,
F_36 ( V_128 -> V_1 ) ,
F_37 ( V_128 -> V_1 ) ,
F_38 ( V_128 -> V_1 ) ,
V_128 -> V_94 ,
F_36 ( V_128 -> V_134 >> 8 ) ,
F_37 ( V_128 -> V_134 >> 8 ) ,
F_38 ( V_128 -> V_134 >> 8 ) ) ;
V_124 = V_128 -> V_1 ;
V_94 = V_128 -> V_94 ;
V_125 = V_128 -> V_134 >> 8 ;
V_95 = 0 ;
V_127 = true ;
break;
case V_52 :
F_65 ( L_15
L_16 ,
F_36 ( V_128 -> V_1 ) ,
F_37 ( V_128 -> V_1 ) ,
F_38 ( V_128 -> V_1 ) ,
V_128 -> V_94 , V_128 -> V_134 ) ;
V_1 = V_128 -> V_1 ;
F_59 ( V_7 , V_1 , V_128 -> V_94 ,
V_128 -> V_134 ) ;
break;
case V_137 :
F_65 ( L_17
L_18 ,
F_36 ( V_128 -> V_1 ) ,
F_37 ( V_128 -> V_1 ) ,
F_38 ( V_128 -> V_1 ) ,
V_128 -> V_94 , V_128 -> V_134 ) ;
V_124 = V_128 -> V_1 ;
V_94 = V_128 -> V_94 ;
V_95 = V_128 -> V_134 ;
V_127 = false ;
break;
case V_50 :
F_65 ( L_19 ,
F_36 ( V_128 -> V_1 ) ,
F_37 ( V_128 -> V_1 ) ,
F_38 ( V_128 -> V_1 ) ) ;
V_1 = V_128 -> V_1 ;
for ( V_126 = V_124 ; V_126 <= V_1 ; ++ V_126 ) {
if ( V_127 ) {
V_135 [ V_126 ] = V_125 ;
F_59 ( V_7 ,
V_125 , V_94 , V_95 ) ;
}
F_59 ( V_7 , V_126 ,
V_94 , V_95 ) ;
}
break;
case V_138 : {
T_3 V_139 , type ;
const char * V_140 ;
T_1 V_1 ;
int V_141 ;
V_139 = V_128 -> V_134 & 0xff ;
V_1 = ( V_128 -> V_134 >> 8 ) & 0xffff ;
type = ( V_128 -> V_134 >> 24 ) & 0xff ;
if ( type == V_112 )
V_140 = L_20 ;
else if ( type == V_113 )
V_140 = L_21 ;
else
V_140 = L_22 ;
F_65 ( L_23 ,
V_140 , ( int ) V_139 ,
F_36 ( V_1 ) ,
F_37 ( V_1 ) ,
F_38 ( V_1 ) ) ;
F_59 ( V_7 , V_1 , V_128 -> V_94 , 0 ) ;
V_141 = F_60 ( type , V_139 , V_1 ) ;
if ( V_141 )
return V_141 ;
break;
}
default:
break;
}
V_45 += F_29 ( V_45 ) ;
}
return 0 ;
}
static int T_6 F_66 ( struct V_6 * V_7 )
{
T_2 V_55 ;
for ( V_55 = V_7 -> V_131 ; V_55 <= V_7 -> V_132 ; ++ V_55 )
F_58 ( V_7 , V_55 ) ;
return 0 ;
}
static void T_6 F_67 ( struct V_6 * V_7 )
{
F_45 ( V_7 ) ;
F_49 ( V_7 ) ;
F_52 ( V_7 ) ;
F_26 ( V_7 ) ;
}
static void T_6 F_68 ( void )
{
struct V_6 * V_7 , * V_142 ;
F_69 (iommu, next) {
F_70 ( & V_7 -> V_111 ) ;
F_67 ( V_7 ) ;
F_71 ( V_7 ) ;
}
}
static void F_72 ( struct V_6 * V_7 )
{
T_2 V_143 ;
if ( ( V_144 . V_145 != 0x15 ) ||
( V_144 . V_146 < 0x10 ) ||
( V_144 . V_146 > 0x1f ) )
return;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 ) ;
F_6 ( V_7 -> V_11 , 0xf4 , & V_143 ) ;
if ( V_143 & F_73 ( 2 ) )
return;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 | ( 1 << 8 ) ) ;
F_5 ( V_7 -> V_11 , 0xf4 , V_143 | 0x4 ) ;
F_74 ( L_24 ,
F_75 ( & V_7 -> V_11 -> V_11 ) ) ;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 ) ;
}
static int T_6 F_76 ( struct V_6 * V_7 , struct V_43 * V_44 )
{
int V_141 ;
F_77 ( & V_7 -> V_147 ) ;
F_62 ( & V_7 -> V_111 , & V_148 ) ;
V_7 -> V_149 = V_150 ++ ;
if ( F_78 ( V_7 -> V_149 >= V_151 ) ) {
F_79 ( 1 , L_25 ) ;
return - V_152 ;
}
V_153 [ V_7 -> V_149 ] = V_7 ;
V_7 -> V_1 = V_44 -> V_1 ;
V_7 -> V_40 = V_44 -> V_40 ;
V_7 -> V_154 = V_44 -> V_154 ;
V_7 -> V_36 = V_44 -> V_36 ;
V_7 -> V_19 = F_22 ( V_44 -> V_36 ) ;
if ( ! V_7 -> V_19 )
return - V_115 ;
V_7 -> V_60 = F_41 ( V_7 ) ;
if ( ! V_7 -> V_60 )
return - V_115 ;
V_7 -> V_70 = F_47 ( V_7 ) ;
if ( ! V_7 -> V_70 )
return - V_115 ;
V_7 -> V_155 = false ;
V_141 = F_64 ( V_7 , V_44 ) ;
if ( V_141 )
return V_141 ;
V_93 [ V_7 -> V_1 ] = NULL ;
F_66 ( V_7 ) ;
return 0 ;
}
static int T_6 F_80 ( struct V_53 * V_54 )
{
T_3 * V_45 = ( T_3 * ) V_54 , * V_46 = ( T_3 * ) V_54 ;
struct V_43 * V_44 ;
struct V_6 * V_7 ;
int V_141 ;
V_46 += V_54 -> V_48 ;
V_45 += V_58 ;
while ( V_45 < V_46 ) {
V_44 = (struct V_43 * ) V_45 ;
switch ( * V_45 ) {
case V_59 :
F_65 ( L_26
L_27 ,
F_36 ( V_44 -> V_1 ) , F_37 ( V_44 -> V_1 ) ,
F_38 ( V_44 -> V_1 ) , V_44 -> V_40 ,
V_44 -> V_154 , V_44 -> V_94 , V_44 -> V_156 ) ;
F_65 ( L_28 ,
V_44 -> V_36 ) ;
V_7 = F_61 ( sizeof( struct V_6 ) , V_61 ) ;
if ( V_7 == NULL )
return - V_115 ;
V_141 = F_76 ( V_7 , V_44 ) ;
if ( V_141 )
return V_141 ;
break;
default:
break;
}
V_45 += V_44 -> V_48 ;
}
F_39 ( V_45 != V_46 ) ;
return 0 ;
}
static int F_81 ( struct V_6 * V_7 )
{
int V_40 = V_7 -> V_40 ;
T_2 V_157 , V_158 , V_159 , V_160 ;
V_7 -> V_11 = F_82 ( F_36 ( V_7 -> V_1 ) ,
V_7 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return - V_57 ;
F_6 ( V_7 -> V_11 , V_40 + V_161 ,
& V_7 -> V_41 ) ;
F_6 ( V_7 -> V_11 , V_40 + V_42 ,
& V_157 ) ;
F_6 ( V_7 -> V_11 , V_40 + V_162 ,
& V_158 ) ;
V_7 -> V_131 = F_32 ( F_33 ( V_157 ) ,
F_83 ( V_157 ) ) ;
V_7 -> V_132 = F_32 ( F_33 ( V_157 ) ,
F_34 ( V_157 ) ) ;
if ( ! ( V_7 -> V_41 & ( 1 << V_163 ) ) )
V_164 = false ;
V_159 = F_16 ( V_7 -> V_19 + V_165 ) ;
V_160 = F_16 ( V_7 -> V_19 + V_165 + 4 ) ;
V_7 -> V_166 = ( ( T_4 ) V_160 << 32 ) | V_159 ;
if ( F_54 ( V_7 , V_85 ) ) {
int V_167 ;
T_2 V_168 ;
T_4 V_4 ;
V_4 = V_7 -> V_166 & V_169 ;
V_4 >>= V_170 ;
V_168 = ( 1 << V_4 ) ;
V_171 = F_84 ( V_171 , V_168 ) ;
V_167 = V_7 -> V_166 & V_172 ;
V_167 >>= V_173 ;
if ( V_174 == - 1 )
V_174 = V_167 ;
else
V_174 = F_84 ( V_174 , V_167 ) ;
}
if ( F_54 ( V_7 , V_85 ) &&
F_54 ( V_7 , V_175 ) ) {
V_7 -> V_176 = true ;
V_177 = true ;
}
if ( F_54 ( V_7 , V_175 ) ) {
V_7 -> V_77 = F_50 ( V_7 ) ;
if ( ! V_7 -> V_77 )
return - V_115 ;
}
if ( V_7 -> V_41 & ( 1UL << V_178 ) )
V_179 = true ;
if ( F_85 ( V_7 -> V_11 ) ) {
int V_55 , V_180 ;
V_7 -> V_181 = F_82 ( V_7 -> V_11 -> V_38 -> V_182 ,
F_86 ( 0 , 0 ) ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
& V_7 -> V_183 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_40 + 8 ,
& V_7 -> V_184 ) ;
V_7 -> V_183 &= ~ 1 ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_180 = 0 ; V_180 < 0x12 ; V_180 ++ )
V_7 -> V_185 [ V_55 ] [ V_180 ] = F_4 ( V_7 , V_55 , V_180 ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
V_7 -> V_186 [ V_55 ] = F_8 ( V_7 , V_55 ) ;
}
F_72 ( V_7 ) ;
return F_87 ( V_7 -> V_11 ) ;
}
static void F_88 ( void )
{
static const char * const V_187 [] = {
L_29 , L_30 , L_31 , L_32 , L_33 , L_34 ,
L_35 , L_36 , L_37 , L_38
} ;
struct V_6 * V_7 ;
F_89 (iommu) {
int V_55 ;
F_74 ( L_39 ,
F_75 ( & V_7 -> V_11 -> V_11 ) , V_7 -> V_40 ) ;
if ( V_7 -> V_41 & ( 1 << V_188 ) ) {
F_74 ( L_40 ) ;
for ( V_55 = 0 ; V_55 < F_90 ( V_187 ) ; ++ V_55 ) {
if ( F_54 ( V_7 , ( 1ULL << V_55 ) ) )
F_91 ( L_41 , V_187 [ V_55 ] ) ;
}
F_91 ( L_42 ) ;
}
}
if ( V_189 )
F_74 ( L_43 ) ;
}
static int T_6 F_92 ( void )
{
struct V_6 * V_7 ;
int V_141 = 0 ;
F_89 (iommu) {
V_141 = F_81 ( V_7 ) ;
if ( V_141 )
break;
}
V_141 = F_93 () ;
F_88 () ;
return V_141 ;
}
static int F_94 ( struct V_6 * V_7 )
{
int V_190 ;
V_190 = F_95 ( V_7 -> V_11 ) ;
if ( V_190 )
return V_190 ;
V_190 = F_96 ( V_7 -> V_11 -> V_191 ,
V_192 ,
V_193 ,
0 , L_44 ,
V_7 -> V_11 ) ;
if ( V_190 ) {
F_97 ( V_7 -> V_11 ) ;
return V_190 ;
}
V_7 -> V_155 = true ;
return 0 ;
}
static int F_98 ( struct V_6 * V_7 )
{
int V_141 ;
if ( V_7 -> V_155 )
goto V_194;
if ( F_99 ( V_7 -> V_11 , V_195 ) )
V_141 = F_94 ( V_7 ) ;
else
V_141 = - V_57 ;
if ( V_141 )
return V_141 ;
V_194:
F_15 ( V_7 , V_33 ) ;
if ( V_7 -> V_77 != NULL )
F_15 ( V_7 , V_196 ) ;
return 0 ;
}
static void T_6 F_100 ( void )
{
struct V_197 * V_17 , * V_142 ;
F_101 (entry, next, &amd_iommu_unity_map, list) {
F_70 ( & V_17 -> V_111 ) ;
F_71 ( V_17 ) ;
}
}
static int T_6 F_102 ( struct V_118 * V_119 )
{
int V_55 ;
switch ( V_119 -> type ) {
case V_198 :
F_63 ( V_119 -> V_1 , V_119 ) ;
break;
case V_199 :
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
F_63 ( V_55 , V_119 ) ;
break;
case V_200 :
for ( V_55 = V_119 -> V_1 ; V_55 <= V_119 -> V_201 ; ++ V_55 )
F_63 ( V_55 , V_119 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_103 ( struct V_118 * V_119 )
{
struct V_197 * V_128 = NULL ;
char * V_202 ;
V_128 = F_61 ( sizeof( * V_128 ) , V_61 ) ;
if ( V_128 == NULL )
return - V_115 ;
switch ( V_119 -> type ) {
default:
F_71 ( V_128 ) ;
return 0 ;
case V_198 :
V_202 = L_45 ;
V_128 -> V_124 = V_128 -> V_203 = V_119 -> V_1 ;
break;
case V_199 :
V_202 = L_46 ;
V_128 -> V_124 = 0 ;
V_128 -> V_203 = V_2 ;
break;
case V_200 :
V_202 = L_47 ;
V_128 -> V_124 = V_119 -> V_1 ;
V_128 -> V_203 = V_119 -> V_201 ;
break;
}
V_128 -> V_204 = F_104 ( V_119 -> V_122 ) ;
V_128 -> V_205 = V_128 -> V_204 + F_104 ( V_119 -> V_123 ) ;
V_128 -> V_206 = V_119 -> V_94 >> 1 ;
F_65 ( L_48
L_49 , V_202 ,
F_36 ( V_128 -> V_124 ) , F_37 ( V_128 -> V_124 ) ,
F_38 ( V_128 -> V_124 ) , F_36 ( V_128 -> V_203 ) ,
F_37 ( V_128 -> V_203 ) , F_38 ( V_128 -> V_203 ) ,
V_128 -> V_204 , V_128 -> V_205 , V_119 -> V_94 ) ;
F_62 ( & V_128 -> V_111 , & V_207 ) ;
return 0 ;
}
static int T_6 F_105 ( struct V_53 * V_54 )
{
T_3 * V_45 = ( T_3 * ) V_54 , * V_46 = ( T_3 * ) V_54 ;
struct V_118 * V_119 ;
V_46 += V_54 -> V_48 ;
V_45 += V_58 ;
while ( V_45 < V_46 ) {
V_119 = (struct V_118 * ) V_45 ;
if ( V_119 -> V_94 & V_120 )
F_102 ( V_119 ) ;
else if ( V_119 -> V_94 & V_208 )
F_103 ( V_119 ) ;
V_45 += V_119 -> V_48 ;
}
return 0 ;
}
static void F_106 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_55 ( V_1 , V_209 ) ;
F_55 ( V_1 , V_210 ) ;
}
}
static void T_6 F_107 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
V_22 [ V_1 ] . V_88 [ 0 ] = 0ULL ;
V_22 [ V_1 ] . V_88 [ 1 ] = 0ULL ;
}
}
static void F_108 ( void )
{
T_2 V_1 ;
if ( ! V_211 )
return;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 )
F_55 ( V_1 , V_212 ) ;
}
static void F_109 ( struct V_6 * V_7 )
{
V_7 -> V_129 & V_213 ?
F_15 ( V_7 , V_214 ) :
F_18 ( V_7 , V_214 ) ;
V_7 -> V_129 & V_215 ?
F_15 ( V_7 , V_216 ) :
F_18 ( V_7 , V_216 ) ;
V_7 -> V_129 & V_217 ?
F_15 ( V_7 , V_218 ) :
F_18 ( V_7 , V_218 ) ;
V_7 -> V_129 & V_219 ?
F_15 ( V_7 , V_220 ) :
F_18 ( V_7 , V_220 ) ;
F_15 ( V_7 , V_221 ) ;
F_19 ( V_7 , V_222 ) ;
}
static void F_110 ( struct V_6 * V_7 )
{
int V_55 , V_180 ;
T_2 V_223 ;
struct V_224 * V_225 = V_7 -> V_181 ;
if ( ! F_85 ( V_7 -> V_11 ) || ! V_225 )
return;
F_5 ( V_225 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_225 , 0x64 , & V_223 ) ;
if ( ! ( V_223 & 0x1 ) )
F_5 ( V_225 , 0x64 , V_223 | 1 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
V_7 -> V_183 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 8 ,
V_7 -> V_184 ) ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_180 = 0 ; V_180 < 0x12 ; V_180 ++ )
F_7 ( V_7 , V_55 , V_180 , V_7 -> V_185 [ V_55 ] [ V_180 ] ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
F_9 ( V_7 , V_55 , V_7 -> V_186 [ V_55 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
V_7 -> V_183 | 1 ) ;
}
static void F_111 ( void )
{
struct V_6 * V_7 ;
F_89 (iommu) {
F_21 ( V_7 ) ;
F_109 ( V_7 ) ;
F_12 ( V_7 ) ;
F_44 ( V_7 ) ;
F_48 ( V_7 ) ;
F_10 ( V_7 ) ;
F_20 ( V_7 ) ;
F_112 ( V_7 ) ;
}
}
static void F_113 ( void )
{
struct V_6 * V_7 ;
F_89 (iommu) {
F_51 ( V_7 ) ;
F_53 ( V_7 ) ;
}
}
static void F_114 ( void )
{
F_111 () ;
F_113 () ;
}
static void F_115 ( void )
{
struct V_6 * V_7 ;
F_89 (iommu)
F_21 ( V_7 ) ;
}
static void F_116 ( void )
{
struct V_6 * V_7 ;
F_89 (iommu)
F_110 ( V_7 ) ;
F_114 () ;
F_117 () ;
}
static int F_118 ( void )
{
F_115 () ;
return 0 ;
}
static void T_6 F_119 ( void )
{
F_46 ( ( unsigned long ) V_226 ,
F_3 ( V_227 ) ) ;
if ( V_228 ) {
F_120 ( V_228 ) ;
V_228 = NULL ;
}
F_46 ( ( unsigned long ) V_93 ,
F_3 ( V_227 ) ) ;
F_46 ( ( unsigned long ) V_135 ,
F_3 ( V_229 ) ) ;
F_46 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_68 () ;
#ifdef F_121
F_122 () ;
#endif
}
static bool T_6 F_123 ( void )
{
bool V_141 , V_230 ;
int V_231 ;
V_230 = false ;
V_141 = false ;
for ( V_231 = 0 ; V_231 < V_232 ; V_231 ++ ) {
int V_1 , V_108 = F_124 ( V_231 ) ;
V_1 = F_125 ( V_108 ) ;
if ( V_1 < 0 ) {
F_24 ( V_233 L_50 , V_108 ) ;
V_141 = false ;
} else if ( V_1 == V_234 ) {
V_230 = true ;
V_141 = true ;
}
}
if ( ! V_230 ) {
F_24 ( V_233 L_51 ) ;
}
if ( ! V_141 )
F_24 ( L_52 ) ;
return V_141 ;
}
static void T_6 F_126 ( void )
{
F_127 () ;
F_46 ( ( unsigned long ) V_235 ,
F_3 ( V_236 / 8 ) ) ;
F_100 () ;
}
static int T_6 F_128 ( void )
{
struct V_53 * V_237 ;
T_7 V_238 ;
T_8 V_239 ;
int V_55 , V_141 = 0 ;
if ( ! V_240 )
return - V_57 ;
V_239 = F_129 ( L_53 , 0 , & V_237 , & V_238 ) ;
if ( V_239 == V_241 )
return - V_57 ;
else if ( F_130 ( V_239 ) ) {
const char * V_242 = F_131 ( V_239 ) ;
F_24 ( L_54 , V_242 ) ;
return - V_114 ;
}
V_141 = F_40 ( V_237 ) ;
if ( V_141 )
goto V_243;
V_23 = F_2 ( V_244 ) ;
V_229 = F_2 ( V_245 ) ;
V_227 = F_2 ( V_246 ) ;
V_141 = - V_115 ;
V_22 = ( void * ) F_42 ( V_61 | V_62 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_243;
V_135 = ( void * ) F_42 ( V_61 ,
F_3 ( V_229 ) ) ;
if ( V_135 == NULL )
goto V_243;
V_93 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_227 ) ) ;
if ( V_93 == NULL )
goto V_243;
V_235 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_236 / 8 ) ) ;
if ( V_235 == NULL )
goto V_243;
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
V_135 [ V_55 ] = V_55 ;
V_235 [ 0 ] = 1 ;
F_77 ( & V_247 ) ;
V_141 = F_80 ( V_237 ) ;
if ( V_141 )
goto V_243;
if ( V_211 )
V_211 = F_123 () ;
if ( V_211 ) {
V_228 = F_132 ( L_55 ,
V_248 * sizeof( T_2 ) ,
V_249 ,
0 , NULL ) ;
if ( ! V_228 )
goto V_243;
V_226 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_227 ) ) ;
if ( ! V_226 )
goto V_243;
}
V_141 = F_105 ( V_237 ) ;
if ( V_141 )
goto V_243;
F_108 () ;
V_243:
F_133 ( ( char T_5 * ) V_237 , V_238 ) ;
V_237 = NULL ;
return V_141 ;
}
static int F_117 ( void )
{
struct V_6 * V_7 ;
int V_141 = 0 ;
F_89 (iommu) {
V_141 = F_98 ( V_7 ) ;
if ( V_141 )
goto V_243;
}
V_243:
return V_141 ;
}
static bool F_134 ( void )
{
struct V_53 * V_237 ;
T_7 V_238 ;
T_8 V_239 ;
V_239 = F_129 ( L_53 , 0 , & V_237 , & V_238 ) ;
if ( V_239 == V_241 )
return false ;
else if ( F_130 ( V_239 ) ) {
const char * V_242 = F_131 ( V_239 ) ;
F_24 ( L_54 , V_242 ) ;
return false ;
}
F_133 ( ( char T_5 * ) V_237 , V_238 ) ;
F_135 () ;
if ( ! V_250 )
V_211 = true ;
return true ;
}
static int F_136 ( void )
{
struct V_6 * V_7 ;
int V_141 ;
if ( V_251 )
V_141 = F_137 () ;
else
V_141 = F_138 () ;
if ( V_141 )
return V_141 ;
F_106 () ;
F_89 (iommu)
F_112 ( V_7 ) ;
F_139 () ;
F_140 () ;
return 0 ;
}
static int T_6 F_141 ( void )
{
int V_141 = 0 ;
switch ( V_252 ) {
case V_253 :
if ( ! F_134 () ) {
V_252 = V_254 ;
V_141 = - V_57 ;
} else {
V_252 = V_255 ;
}
break;
case V_255 :
V_141 = F_128 () ;
V_252 = V_141 ? V_256 : V_257 ;
break;
case V_257 :
F_111 () ;
F_142 ( & V_258 ) ;
V_259 . V_260 = F_115 ;
V_252 = V_261 ;
break;
case V_261 :
V_141 = F_92 () ;
V_252 = V_141 ? V_256 : V_262 ;
F_113 () ;
break;
case V_262 :
V_141 = F_117 () ;
V_252 = V_141 ? V_256 : V_263 ;
break;
case V_263 :
V_141 = F_136 () ;
V_252 = V_141 ? V_256 : V_264 ;
break;
case V_264 :
V_252 = V_265 ;
break;
case V_265 :
break;
case V_254 :
case V_256 :
V_141 = - V_114 ;
break;
default:
F_143 () ;
}
return V_141 ;
}
static int T_6 F_144 ( enum V_266 V_267 )
{
int V_141 = 0 ;
while ( V_252 != V_267 ) {
V_141 = F_141 () ;
if ( V_252 == V_254 ||
V_252 == V_256 )
break;
}
return V_141 ;
}
int T_6 F_145 ( void )
{
return F_144 ( V_257 ) ;
}
int T_6 F_146 ( void )
{
return V_211 ? 1 : 0 ;
}
int T_6 F_147 ( void )
{
int V_141 ;
V_141 = F_144 ( V_261 ) ;
if ( V_141 )
return V_141 ;
V_189 = 1 ;
return 0 ;
}
void F_148 ( void )
{
F_118 () ;
}
int F_149 ( int V_268 )
{
F_116 () ;
return 0 ;
}
int T_6 F_150 ( void )
{
return 0 ;
}
static int T_6 F_151 ( void )
{
int V_141 ;
V_141 = F_144 ( V_265 ) ;
if ( V_141 ) {
F_126 () ;
if ( ! V_189 ) {
F_115 () ;
F_119 () ;
} else {
struct V_6 * V_7 ;
F_107 () ;
F_89 (iommu)
F_112 ( V_7 ) ;
}
}
return V_141 ;
}
int T_6 F_152 ( void )
{
int V_141 ;
if ( V_269 || ( V_270 && ! V_271 ) )
return - V_57 ;
if ( V_272 )
return - V_57 ;
V_141 = F_144 ( V_255 ) ;
if ( V_141 )
return V_141 ;
V_240 = true ;
V_270 = 1 ;
V_273 . V_7 . V_274 = F_151 ;
return 0 ;
}
static int T_6 F_153 ( char * V_275 )
{
V_276 = true ;
return 1 ;
}
static int T_6 F_154 ( char * V_275 )
{
for (; * V_275 ; ++ V_275 ) {
if ( strncmp ( V_275 , L_56 , 9 ) == 0 )
V_277 = true ;
if ( strncmp ( V_275 , L_57 , 3 ) == 0 )
V_272 = true ;
if ( strncmp ( V_275 , L_58 , 15 ) == 0 )
V_278 = true ;
}
return 1 ;
}
bool F_155 ( void )
{
return V_177 ;
}
