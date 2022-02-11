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
static T_3 T_5 * T_6 F_22 ( T_4 V_9 , T_4 V_35 )
{
if ( ! F_23 ( V_9 , V_35 , L_1 ) ) {
F_24 ( L_2 ,
V_9 , V_35 ) ;
F_24 ( L_3 ) ;
return NULL ;
}
return ( T_3 T_5 * ) F_25 ( V_9 , V_35 ) ;
}
static void T_6 F_26 ( struct V_6 * V_7 )
{
if ( V_7 -> V_19 )
F_27 ( V_7 -> V_19 ) ;
F_28 ( V_7 -> V_36 , V_7 -> V_37 ) ;
}
static inline int F_29 ( T_3 * V_38 )
{
return 0x04 << ( * V_38 >> 6 ) ;
}
static int T_6 F_30 ( int V_39 , int V_11 , int V_40 , int V_41 )
{
T_2 V_42 ;
V_42 = F_31 ( V_39 , V_11 , V_40 , V_41 + V_43 ) ;
F_1 ( F_32 ( F_33 ( V_42 ) , F_34 ( V_42 ) ) ) ;
return 0 ;
}
static int T_6 F_35 ( struct V_44 * V_45 )
{
T_3 * V_46 = ( void * ) V_45 , * V_35 = ( void * ) V_45 ;
struct V_47 * V_11 ;
V_46 += sizeof( * V_45 ) ;
V_35 += V_45 -> V_48 ;
F_30 ( F_36 ( V_45 -> V_1 ) ,
F_37 ( V_45 -> V_1 ) ,
F_38 ( V_45 -> V_1 ) ,
V_45 -> V_41 ) ;
while ( V_46 < V_35 ) {
V_11 = (struct V_47 * ) V_46 ;
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
V_46 += F_29 ( V_46 ) ;
}
F_39 ( V_46 != V_35 ) ;
return 0 ;
}
static int T_6 F_40 ( struct V_53 * V_54 )
{
int V_55 ;
T_3 V_56 = 0 , * V_46 = ( T_3 * ) V_54 , * V_35 = ( T_3 * ) V_54 ;
struct V_44 * V_45 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_48 ; ++ V_55 )
V_56 += V_46 [ V_55 ] ;
if ( V_56 != 0 )
return - V_57 ;
V_46 += V_58 ;
V_35 += V_54 -> V_48 ;
while ( V_46 < V_35 ) {
V_45 = (struct V_44 * ) V_46 ;
switch ( V_45 -> type ) {
case V_59 :
F_35 ( V_45 ) ;
break;
default:
break;
}
V_46 += V_45 -> V_48 ;
}
F_39 ( V_46 != V_35 ) ;
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
static int T_6 F_60 ( T_3 type , T_3 V_108 , T_1 V_1 , bool V_109 )
{
struct V_110 * V_17 ;
struct V_111 * V_112 ;
if ( type == V_113 )
V_112 = & V_114 ;
else if ( type == V_115 )
V_112 = & V_116 ;
else
return - V_117 ;
F_61 (entry, list, list) {
if ( ! ( V_17 -> V_108 == V_108 && V_17 -> V_109 ) )
continue;
F_62 ( L_4 ,
type == V_113 ? L_5 : L_6 , V_108 ) ;
return 0 ;
}
V_17 = F_63 ( sizeof( * V_17 ) , V_61 ) ;
if ( ! V_17 )
return - V_118 ;
V_17 -> V_108 = V_108 ;
V_17 -> V_1 = V_1 ;
V_17 -> V_109 = V_109 ;
F_64 ( & V_17 -> V_112 , V_112 ) ;
return 0 ;
}
static int T_6 F_65 ( void )
{
int V_55 , V_119 ;
for ( V_55 = 0 ; V_55 < V_120 ; ++ V_55 ) {
V_119 = F_60 ( V_113 ,
V_121 [ V_55 ] . V_108 ,
V_121 [ V_55 ] . V_1 ,
V_121 [ V_55 ] . V_109 ) ;
if ( V_119 )
return V_119 ;
}
for ( V_55 = 0 ; V_55 < V_122 ; ++ V_55 ) {
V_119 = F_60 ( V_115 ,
V_123 [ V_55 ] . V_108 ,
V_123 [ V_55 ] . V_1 ,
V_123 [ V_55 ] . V_109 ) ;
if ( V_119 )
return V_119 ;
}
return 0 ;
}
static void T_6 F_66 ( T_1 V_1 , struct V_124 * V_125 )
{
struct V_6 * V_7 = V_93 [ V_1 ] ;
if ( ! ( V_125 -> V_94 & V_126 ) )
return;
if ( V_7 ) {
F_55 ( V_1 , V_127 ) ;
V_7 -> V_13 = V_125 -> V_128 ;
V_7 -> V_16 = V_125 -> V_129 ;
}
}
static int T_6 F_67 ( struct V_6 * V_7 ,
struct V_44 * V_45 )
{
T_3 * V_46 = ( T_3 * ) V_45 ;
T_3 * V_35 = V_46 , V_94 = 0 ;
T_1 V_1 = 0 , V_130 = 0 , V_131 = 0 ;
T_2 V_132 , V_95 = 0 ;
bool V_133 = false ;
struct V_47 * V_134 ;
int V_119 ;
V_119 = F_65 () ;
if ( V_119 )
return V_119 ;
V_7 -> V_135 = V_45 -> V_94 ;
V_46 += sizeof( struct V_44 ) ;
V_35 += V_45 -> V_48 ;
while ( V_46 < V_35 ) {
V_134 = (struct V_47 * ) V_46 ;
switch ( V_134 -> type ) {
case V_136 :
F_68 ( L_7
L_8 ,
F_36 ( V_7 -> V_137 ) ,
F_37 ( V_7 -> V_137 ) ,
F_38 ( V_7 -> V_137 ) ,
F_36 ( V_7 -> V_138 ) ,
F_37 ( V_7 -> V_138 ) ,
F_38 ( V_7 -> V_138 ) ,
V_134 -> V_94 ) ;
for ( V_132 = V_7 -> V_137 ;
V_132 <= V_7 -> V_138 ; ++ V_132 )
F_59 ( V_7 , V_132 ,
V_134 -> V_94 , 0 ) ;
break;
case V_49 :
F_68 ( L_9
L_10 ,
F_36 ( V_134 -> V_1 ) ,
F_37 ( V_134 -> V_1 ) ,
F_38 ( V_134 -> V_1 ) ,
V_134 -> V_94 ) ;
V_1 = V_134 -> V_1 ;
F_59 ( V_7 , V_1 , V_134 -> V_94 , 0 ) ;
break;
case V_139 :
F_68 ( L_11
L_12 ,
F_36 ( V_134 -> V_1 ) ,
F_37 ( V_134 -> V_1 ) ,
F_38 ( V_134 -> V_1 ) ,
V_134 -> V_94 ) ;
V_130 = V_134 -> V_1 ;
V_94 = V_134 -> V_94 ;
V_95 = 0 ;
V_133 = false ;
break;
case V_51 :
F_68 ( L_13
L_14 ,
F_36 ( V_134 -> V_1 ) ,
F_37 ( V_134 -> V_1 ) ,
F_38 ( V_134 -> V_1 ) ,
V_134 -> V_94 ,
F_36 ( V_134 -> V_140 >> 8 ) ,
F_37 ( V_134 -> V_140 >> 8 ) ,
F_38 ( V_134 -> V_140 >> 8 ) ) ;
V_1 = V_134 -> V_1 ;
V_131 = V_134 -> V_140 >> 8 ;
F_59 ( V_7 , V_1 , V_134 -> V_94 , 0 ) ;
F_59 ( V_7 , V_131 , V_134 -> V_94 , 0 ) ;
V_141 [ V_1 ] = V_131 ;
break;
case V_142 :
F_68 ( L_15
L_16
L_17 ,
F_36 ( V_134 -> V_1 ) ,
F_37 ( V_134 -> V_1 ) ,
F_38 ( V_134 -> V_1 ) ,
V_134 -> V_94 ,
F_36 ( V_134 -> V_140 >> 8 ) ,
F_37 ( V_134 -> V_140 >> 8 ) ,
F_38 ( V_134 -> V_140 >> 8 ) ) ;
V_130 = V_134 -> V_1 ;
V_94 = V_134 -> V_94 ;
V_131 = V_134 -> V_140 >> 8 ;
V_95 = 0 ;
V_133 = true ;
break;
case V_52 :
F_68 ( L_18
L_19 ,
F_36 ( V_134 -> V_1 ) ,
F_37 ( V_134 -> V_1 ) ,
F_38 ( V_134 -> V_1 ) ,
V_134 -> V_94 , V_134 -> V_140 ) ;
V_1 = V_134 -> V_1 ;
F_59 ( V_7 , V_1 , V_134 -> V_94 ,
V_134 -> V_140 ) ;
break;
case V_143 :
F_68 ( L_20
L_21 ,
F_36 ( V_134 -> V_1 ) ,
F_37 ( V_134 -> V_1 ) ,
F_38 ( V_134 -> V_1 ) ,
V_134 -> V_94 , V_134 -> V_140 ) ;
V_130 = V_134 -> V_1 ;
V_94 = V_134 -> V_94 ;
V_95 = V_134 -> V_140 ;
V_133 = false ;
break;
case V_50 :
F_68 ( L_22 ,
F_36 ( V_134 -> V_1 ) ,
F_37 ( V_134 -> V_1 ) ,
F_38 ( V_134 -> V_1 ) ) ;
V_1 = V_134 -> V_1 ;
for ( V_132 = V_130 ; V_132 <= V_1 ; ++ V_132 ) {
if ( V_133 ) {
V_141 [ V_132 ] = V_131 ;
F_59 ( V_7 ,
V_131 , V_94 , V_95 ) ;
}
F_59 ( V_7 , V_132 ,
V_94 , V_95 ) ;
}
break;
case V_144 : {
T_3 V_145 , type ;
const char * V_146 ;
T_1 V_1 ;
int V_119 ;
V_145 = V_134 -> V_140 & 0xff ;
V_1 = ( V_134 -> V_140 >> 8 ) & 0xffff ;
type = ( V_134 -> V_140 >> 24 ) & 0xff ;
if ( type == V_113 )
V_146 = L_5 ;
else if ( type == V_115 )
V_146 = L_6 ;
else
V_146 = L_23 ;
F_68 ( L_24 ,
V_146 , ( int ) V_145 ,
F_36 ( V_1 ) ,
F_37 ( V_1 ) ,
F_38 ( V_1 ) ) ;
F_59 ( V_7 , V_1 , V_134 -> V_94 , 0 ) ;
V_119 = F_60 ( type , V_145 , V_1 , false ) ;
if ( V_119 )
return V_119 ;
break;
}
default:
break;
}
V_46 += F_29 ( V_46 ) ;
}
return 0 ;
}
static int T_6 F_69 ( struct V_6 * V_7 )
{
T_2 V_55 ;
for ( V_55 = V_7 -> V_137 ; V_55 <= V_7 -> V_138 ; ++ V_55 )
F_58 ( V_7 , V_55 ) ;
return 0 ;
}
static void T_6 F_70 ( struct V_6 * V_7 )
{
F_45 ( V_7 ) ;
F_49 ( V_7 ) ;
F_52 ( V_7 ) ;
F_26 ( V_7 ) ;
}
static void T_6 F_71 ( void )
{
struct V_6 * V_7 , * V_147 ;
F_72 (iommu, next) {
F_73 ( & V_7 -> V_112 ) ;
F_70 ( V_7 ) ;
F_74 ( V_7 ) ;
}
}
static void F_75 ( struct V_6 * V_7 )
{
T_2 V_148 ;
if ( ( V_149 . V_150 != 0x15 ) ||
( V_149 . V_151 < 0x10 ) ||
( V_149 . V_151 > 0x1f ) )
return;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 ) ;
F_6 ( V_7 -> V_11 , 0xf4 , & V_148 ) ;
if ( V_148 & F_76 ( 2 ) )
return;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 | ( 1 << 8 ) ) ;
F_5 ( V_7 -> V_11 , 0xf4 , V_148 | 0x4 ) ;
F_62 ( L_25 ,
F_77 ( & V_7 -> V_11 -> V_11 ) ) ;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 ) ;
}
static int T_6 F_78 ( struct V_6 * V_7 , struct V_44 * V_45 )
{
int V_119 ;
F_79 ( & V_7 -> V_152 ) ;
F_64 ( & V_7 -> V_112 , & V_153 ) ;
V_7 -> V_154 = V_155 ++ ;
if ( F_80 ( V_7 -> V_154 >= V_156 ) ) {
F_81 ( 1 , L_26 ) ;
return - V_157 ;
}
V_158 [ V_7 -> V_154 ] = V_7 ;
V_7 -> V_1 = V_45 -> V_1 ;
V_7 -> V_41 = V_45 -> V_41 ;
V_7 -> V_159 = V_45 -> V_159 ;
V_7 -> V_36 = V_45 -> V_36 ;
if ( ( V_45 -> V_160 != 0 ) &&
( ( V_45 -> V_160 & ( 0xF << 13 ) ) != 0 ) &&
( ( V_45 -> V_160 & ( 0x3F << 17 ) ) != 0 ) ) {
V_7 -> V_37 = V_161 ;
} else {
V_7 -> V_37 = V_162 ;
}
V_7 -> V_19 = F_22 ( V_7 -> V_36 ,
V_7 -> V_37 ) ;
if ( ! V_7 -> V_19 )
return - V_118 ;
V_7 -> V_60 = F_41 ( V_7 ) ;
if ( ! V_7 -> V_60 )
return - V_118 ;
V_7 -> V_70 = F_47 ( V_7 ) ;
if ( ! V_7 -> V_70 )
return - V_118 ;
V_7 -> V_163 = false ;
V_119 = F_67 ( V_7 , V_45 ) ;
if ( V_119 )
return V_119 ;
V_93 [ V_7 -> V_1 ] = NULL ;
F_69 ( V_7 ) ;
return 0 ;
}
static int T_6 F_82 ( struct V_53 * V_54 )
{
T_3 * V_46 = ( T_3 * ) V_54 , * V_35 = ( T_3 * ) V_54 ;
struct V_44 * V_45 ;
struct V_6 * V_7 ;
int V_119 ;
V_35 += V_54 -> V_48 ;
V_46 += V_58 ;
while ( V_46 < V_35 ) {
V_45 = (struct V_44 * ) V_46 ;
switch ( * V_46 ) {
case V_59 :
F_68 ( L_27
L_28 ,
F_36 ( V_45 -> V_1 ) , F_37 ( V_45 -> V_1 ) ,
F_38 ( V_45 -> V_1 ) , V_45 -> V_41 ,
V_45 -> V_159 , V_45 -> V_94 , V_45 -> V_164 ) ;
F_68 ( L_29 ,
V_45 -> V_36 ) ;
V_7 = F_63 ( sizeof( struct V_6 ) , V_61 ) ;
if ( V_7 == NULL )
return - V_118 ;
V_119 = F_78 ( V_7 , V_45 ) ;
if ( V_119 )
return V_119 ;
break;
default:
break;
}
V_46 += V_45 -> V_48 ;
}
F_39 ( V_46 != V_35 ) ;
return 0 ;
}
static void F_83 ( struct V_6 * V_7 )
{
T_4 V_10 = 0xabcd , V_165 = 0 ;
if ( ! F_54 ( V_7 , V_166 ) )
return;
V_167 = true ;
if ( ( 0 != F_84 ( 0 , 0 , 0 , 0 , & V_10 , true ) ) ||
( 0 != F_84 ( 0 , 0 , 0 , 0 , & V_165 , false ) ) ||
( V_10 != V_165 ) ) {
F_24 ( L_30 ) ;
V_167 = false ;
return;
}
F_62 ( L_31 ) ;
V_10 = F_16 ( V_7 -> V_19 + V_162 ) ;
V_7 -> V_168 = ( T_3 ) ( ( V_10 >> 12 ) & 0x3f ) ;
V_7 -> V_169 = ( T_3 ) ( ( V_10 >> 7 ) & 0xf ) ;
}
static int F_85 ( struct V_6 * V_7 )
{
int V_41 = V_7 -> V_41 ;
T_2 V_170 , V_171 , V_172 , V_173 ;
V_7 -> V_11 = F_86 ( F_36 ( V_7 -> V_1 ) ,
V_7 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return - V_57 ;
F_6 ( V_7 -> V_11 , V_41 + V_174 ,
& V_7 -> V_42 ) ;
F_6 ( V_7 -> V_11 , V_41 + V_43 ,
& V_170 ) ;
F_6 ( V_7 -> V_11 , V_41 + V_175 ,
& V_171 ) ;
V_7 -> V_137 = F_32 ( F_33 ( V_170 ) ,
F_87 ( V_170 ) ) ;
V_7 -> V_138 = F_32 ( F_33 ( V_170 ) ,
F_34 ( V_170 ) ) ;
if ( ! ( V_7 -> V_42 & ( 1 << V_176 ) ) )
V_177 = false ;
V_172 = F_16 ( V_7 -> V_19 + V_178 ) ;
V_173 = F_16 ( V_7 -> V_19 + V_178 + 4 ) ;
V_7 -> V_179 = ( ( T_4 ) V_173 << 32 ) | V_172 ;
if ( F_54 ( V_7 , V_85 ) ) {
int V_180 ;
T_2 V_181 ;
T_4 V_182 ;
V_182 = V_7 -> V_179 & V_183 ;
V_182 >>= V_184 ;
V_181 = ( 1 << ( V_182 + 1 ) ) - 1 ;
V_185 = F_88 ( V_185 , V_181 ) ;
F_13 ( V_185 & ~ V_186 ) ;
V_180 = V_7 -> V_179 & V_187 ;
V_180 >>= V_188 ;
if ( V_189 == - 1 )
V_189 = V_180 ;
else
V_189 = F_88 ( V_189 , V_180 ) ;
}
if ( F_54 ( V_7 , V_85 ) &&
F_54 ( V_7 , V_190 ) ) {
V_7 -> V_191 = true ;
V_192 = true ;
}
if ( F_54 ( V_7 , V_190 ) ) {
V_7 -> V_77 = F_50 ( V_7 ) ;
if ( ! V_7 -> V_77 )
return - V_118 ;
}
if ( V_7 -> V_42 & ( 1UL << V_193 ) )
V_194 = true ;
F_83 ( V_7 ) ;
if ( F_89 ( V_7 -> V_11 ) ) {
int V_55 , V_195 ;
V_7 -> V_196 = F_86 ( V_7 -> V_11 -> V_39 -> V_197 ,
F_90 ( 0 , 0 ) ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_41 + 4 ,
& V_7 -> V_198 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_41 + 8 ,
& V_7 -> V_199 ) ;
V_7 -> V_198 &= ~ 1 ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_195 = 0 ; V_195 < 0x12 ; V_195 ++ )
V_7 -> V_200 [ V_55 ] [ V_195 ] = F_4 ( V_7 , V_55 , V_195 ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
V_7 -> V_201 [ V_55 ] = F_8 ( V_7 , V_55 ) ;
}
F_75 ( V_7 ) ;
return F_91 ( V_7 -> V_11 ) ;
}
static void F_92 ( void )
{
static const char * const V_202 [] = {
L_32 , L_33 , L_34 , L_35 , L_36 , L_37 ,
L_38 , L_39 , L_40 , L_41
} ;
struct V_6 * V_7 ;
F_93 (iommu) {
int V_55 ;
F_62 ( L_42 ,
F_77 ( & V_7 -> V_11 -> V_11 ) , V_7 -> V_41 ) ;
if ( V_7 -> V_42 & ( 1 << V_203 ) ) {
F_62 ( L_43 ) ;
for ( V_55 = 0 ; V_55 < F_94 ( V_202 ) ; ++ V_55 ) {
if ( F_54 ( V_7 , ( 1ULL << V_55 ) ) )
F_95 ( L_44 , V_202 [ V_55 ] ) ;
}
F_95 ( L_45 ) ;
}
}
if ( V_204 )
F_62 ( L_46 ) ;
}
static int T_6 F_96 ( void )
{
struct V_6 * V_7 ;
int V_119 = 0 ;
F_93 (iommu) {
V_119 = F_85 ( V_7 ) ;
if ( V_119 )
break;
}
V_119 = F_97 () ;
F_92 () ;
return V_119 ;
}
static int F_98 ( struct V_6 * V_7 )
{
int V_205 ;
V_205 = F_99 ( V_7 -> V_11 ) ;
if ( V_205 )
return V_205 ;
V_205 = F_100 ( V_7 -> V_11 -> V_206 ,
V_207 ,
V_208 ,
0 , L_47 ,
V_7 ) ;
if ( V_205 ) {
F_101 ( V_7 -> V_11 ) ;
return V_205 ;
}
V_7 -> V_163 = true ;
return 0 ;
}
static int F_102 ( struct V_6 * V_7 )
{
int V_119 ;
if ( V_7 -> V_163 )
goto V_209;
if ( V_7 -> V_11 -> V_210 )
V_119 = F_98 ( V_7 ) ;
else
V_119 = - V_57 ;
if ( V_119 )
return V_119 ;
V_209:
F_15 ( V_7 , V_33 ) ;
if ( V_7 -> V_77 != NULL )
F_15 ( V_7 , V_211 ) ;
return 0 ;
}
static void T_6 F_103 ( void )
{
struct V_212 * V_17 , * V_147 ;
F_104 (entry, next, &amd_iommu_unity_map, list) {
F_73 ( & V_17 -> V_112 ) ;
F_74 ( V_17 ) ;
}
}
static int T_6 F_105 ( struct V_124 * V_125 )
{
int V_55 ;
switch ( V_125 -> type ) {
case V_213 :
F_66 ( V_125 -> V_1 , V_125 ) ;
break;
case V_214 :
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
F_66 ( V_55 , V_125 ) ;
break;
case V_215 :
for ( V_55 = V_125 -> V_1 ; V_55 <= V_125 -> V_216 ; ++ V_55 )
F_66 ( V_55 , V_125 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_106 ( struct V_124 * V_125 )
{
struct V_212 * V_134 = NULL ;
char * V_217 ;
V_134 = F_63 ( sizeof( * V_134 ) , V_61 ) ;
if ( V_134 == NULL )
return - V_118 ;
switch ( V_125 -> type ) {
default:
F_74 ( V_134 ) ;
return 0 ;
case V_213 :
V_217 = L_48 ;
V_134 -> V_130 = V_134 -> V_218 = V_125 -> V_1 ;
break;
case V_214 :
V_217 = L_49 ;
V_134 -> V_130 = 0 ;
V_134 -> V_218 = V_2 ;
break;
case V_215 :
V_217 = L_50 ;
V_134 -> V_130 = V_125 -> V_1 ;
V_134 -> V_218 = V_125 -> V_216 ;
break;
}
V_134 -> V_219 = F_107 ( V_125 -> V_128 ) ;
V_134 -> V_220 = V_134 -> V_219 + F_107 ( V_125 -> V_129 ) ;
V_134 -> V_221 = V_125 -> V_94 >> 1 ;
F_68 ( L_51
L_52 , V_217 ,
F_36 ( V_134 -> V_130 ) , F_37 ( V_134 -> V_130 ) ,
F_38 ( V_134 -> V_130 ) , F_36 ( V_134 -> V_218 ) ,
F_37 ( V_134 -> V_218 ) , F_38 ( V_134 -> V_218 ) ,
V_134 -> V_219 , V_134 -> V_220 , V_125 -> V_94 ) ;
F_64 ( & V_134 -> V_112 , & V_222 ) ;
return 0 ;
}
static int T_6 F_108 ( struct V_53 * V_54 )
{
T_3 * V_46 = ( T_3 * ) V_54 , * V_35 = ( T_3 * ) V_54 ;
struct V_124 * V_125 ;
V_35 += V_54 -> V_48 ;
V_46 += V_58 ;
while ( V_46 < V_35 ) {
V_125 = (struct V_124 * ) V_46 ;
if ( V_125 -> V_94 & V_126 )
F_105 ( V_125 ) ;
else if ( V_125 -> V_94 & V_223 )
F_106 ( V_125 ) ;
V_46 += V_125 -> V_48 ;
}
return 0 ;
}
static void F_109 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_55 ( V_1 , V_224 ) ;
F_55 ( V_1 , V_225 ) ;
}
}
static void T_6 F_110 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
V_22 [ V_1 ] . V_88 [ 0 ] = 0ULL ;
V_22 [ V_1 ] . V_88 [ 1 ] = 0ULL ;
}
}
static void F_111 ( void )
{
T_2 V_1 ;
if ( ! V_226 )
return;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 )
F_55 ( V_1 , V_227 ) ;
}
static void F_112 ( struct V_6 * V_7 )
{
V_7 -> V_135 & V_228 ?
F_15 ( V_7 , V_229 ) :
F_18 ( V_7 , V_229 ) ;
V_7 -> V_135 & V_230 ?
F_15 ( V_7 , V_231 ) :
F_18 ( V_7 , V_231 ) ;
V_7 -> V_135 & V_232 ?
F_15 ( V_7 , V_233 ) :
F_18 ( V_7 , V_233 ) ;
V_7 -> V_135 & V_234 ?
F_15 ( V_7 , V_235 ) :
F_18 ( V_7 , V_235 ) ;
F_15 ( V_7 , V_236 ) ;
F_19 ( V_7 , V_237 ) ;
}
static void F_113 ( struct V_6 * V_7 )
{
int V_55 , V_195 ;
T_2 V_238 ;
struct V_239 * V_240 = V_7 -> V_196 ;
if ( ! F_89 ( V_7 -> V_11 ) || ! V_240 )
return;
F_5 ( V_240 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_240 , 0x64 , & V_238 ) ;
if ( ! ( V_238 & 0x1 ) )
F_5 ( V_240 , 0x64 , V_238 | 1 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_41 + 4 ,
V_7 -> V_198 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_41 + 8 ,
V_7 -> V_199 ) ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_195 = 0 ; V_195 < 0x12 ; V_195 ++ )
F_7 ( V_7 , V_55 , V_195 , V_7 -> V_200 [ V_55 ] [ V_195 ] ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
F_9 ( V_7 , V_55 , V_7 -> V_201 [ V_55 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_41 + 4 ,
V_7 -> V_198 | 1 ) ;
}
static void F_114 ( void )
{
struct V_6 * V_7 ;
F_93 (iommu) {
F_21 ( V_7 ) ;
F_112 ( V_7 ) ;
F_12 ( V_7 ) ;
F_44 ( V_7 ) ;
F_48 ( V_7 ) ;
F_10 ( V_7 ) ;
F_20 ( V_7 ) ;
F_115 ( V_7 ) ;
}
}
static void F_116 ( void )
{
struct V_6 * V_7 ;
F_93 (iommu) {
F_51 ( V_7 ) ;
F_53 ( V_7 ) ;
}
}
static void F_117 ( void )
{
F_114 () ;
F_116 () ;
}
static void F_118 ( void )
{
struct V_6 * V_7 ;
F_93 (iommu)
F_21 ( V_7 ) ;
}
static void F_119 ( void )
{
struct V_6 * V_7 ;
F_93 (iommu)
F_113 ( V_7 ) ;
F_117 () ;
F_120 () ;
}
static int F_121 ( void )
{
F_118 () ;
return 0 ;
}
static void T_6 F_122 ( void )
{
F_46 ( ( unsigned long ) V_241 ,
F_3 ( V_242 ) ) ;
if ( V_243 ) {
F_123 ( V_243 ) ;
V_243 = NULL ;
}
F_46 ( ( unsigned long ) V_93 ,
F_3 ( V_242 ) ) ;
F_46 ( ( unsigned long ) V_141 ,
F_3 ( V_244 ) ) ;
F_46 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_71 () ;
#ifdef F_124
F_125 () ;
#endif
}
static bool T_6 F_126 ( void )
{
const char * V_245 = V_246 ;
bool V_119 , V_247 ;
int V_248 ;
V_247 = false ;
V_119 = false ;
if ( V_249 )
V_245 = L_53 ;
for ( V_248 = 0 ; V_248 < V_250 ; V_248 ++ ) {
int V_1 , V_108 = F_127 ( V_248 ) ;
V_1 = F_128 ( V_108 ) ;
if ( V_1 < 0 ) {
F_24 ( L_54 ,
V_245 , V_108 ) ;
V_119 = false ;
} else if ( V_1 == V_251 ) {
V_247 = true ;
V_119 = true ;
}
}
if ( ! V_247 ) {
F_24 ( L_55 , V_245 ) ;
}
if ( ! V_119 )
F_24 ( L_56 ) ;
return V_119 ;
}
static void T_6 F_129 ( void )
{
F_130 () ;
F_46 ( ( unsigned long ) V_252 ,
F_3 ( V_253 / 8 ) ) ;
F_103 () ;
}
static int T_6 F_131 ( void )
{
struct V_53 * V_254 ;
T_7 V_255 ;
T_8 V_256 ;
int V_55 , V_119 = 0 ;
if ( ! V_257 )
return - V_57 ;
V_256 = F_132 ( L_57 , 0 , & V_254 , & V_255 ) ;
if ( V_256 == V_258 )
return - V_57 ;
else if ( F_133 ( V_256 ) ) {
const char * V_259 = F_134 ( V_256 ) ;
F_24 ( L_58 , V_259 ) ;
return - V_117 ;
}
V_119 = F_40 ( V_254 ) ;
if ( V_119 )
goto V_260;
V_23 = F_2 ( V_261 ) ;
V_244 = F_2 ( V_262 ) ;
V_242 = F_2 ( V_263 ) ;
V_119 = - V_118 ;
V_22 = ( void * ) F_42 ( V_61 | V_62 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_260;
V_141 = ( void * ) F_42 ( V_61 ,
F_3 ( V_244 ) ) ;
if ( V_141 == NULL )
goto V_260;
V_93 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_242 ) ) ;
if ( V_93 == NULL )
goto V_260;
V_252 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_253 / 8 ) ) ;
if ( V_252 == NULL )
goto V_260;
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
V_141 [ V_55 ] = V_55 ;
V_252 [ 0 ] = 1 ;
F_79 ( & V_264 ) ;
V_119 = F_82 ( V_254 ) ;
if ( V_119 )
goto V_260;
if ( V_226 )
V_226 = F_126 () ;
if ( V_226 ) {
V_119 = - V_118 ;
V_243 = F_135 ( L_59 ,
V_265 * sizeof( T_2 ) ,
V_266 ,
0 , NULL ) ;
if ( ! V_243 )
goto V_260;
V_241 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_242 ) ) ;
if ( ! V_241 )
goto V_260;
}
V_119 = F_108 ( V_254 ) ;
if ( V_119 )
goto V_260;
F_111 () ;
V_260:
F_136 ( ( char T_5 * ) V_254 , V_255 ) ;
V_254 = NULL ;
return V_119 ;
}
static int F_120 ( void )
{
struct V_6 * V_7 ;
int V_119 = 0 ;
F_93 (iommu) {
V_119 = F_102 ( V_7 ) ;
if ( V_119 )
goto V_260;
}
V_260:
return V_119 ;
}
static bool F_137 ( void )
{
struct V_53 * V_254 ;
T_7 V_255 ;
T_8 V_256 ;
V_256 = F_132 ( L_57 , 0 , & V_254 , & V_255 ) ;
if ( V_256 == V_258 )
return false ;
else if ( F_133 ( V_256 ) ) {
const char * V_259 = F_134 ( V_256 ) ;
F_24 ( L_58 , V_259 ) ;
return false ;
}
F_136 ( ( char T_5 * ) V_254 , V_255 ) ;
F_138 () ;
if ( ! V_267 )
V_226 = true ;
return true ;
}
static int F_139 ( void )
{
struct V_6 * V_7 ;
int V_119 ;
if ( V_268 )
V_119 = F_140 () ;
else
V_119 = F_141 () ;
if ( V_119 )
return V_119 ;
F_109 () ;
F_93 (iommu)
F_115 ( V_7 ) ;
F_142 () ;
F_143 () ;
return 0 ;
}
static int T_6 F_144 ( void )
{
int V_119 = 0 ;
switch ( V_269 ) {
case V_270 :
if ( ! F_137 () ) {
V_269 = V_271 ;
V_119 = - V_57 ;
} else {
V_269 = V_272 ;
}
break;
case V_272 :
V_119 = F_131 () ;
V_269 = V_119 ? V_273 : V_274 ;
break;
case V_274 :
F_114 () ;
F_145 ( & V_275 ) ;
V_276 . V_277 = F_118 ;
V_269 = V_278 ;
break;
case V_278 :
V_119 = F_96 () ;
V_269 = V_119 ? V_273 : V_279 ;
F_116 () ;
break;
case V_279 :
V_119 = F_120 () ;
V_269 = V_119 ? V_273 : V_280 ;
break;
case V_280 :
V_119 = F_139 () ;
V_269 = V_119 ? V_273 : V_281 ;
break;
case V_281 :
V_269 = V_282 ;
break;
case V_282 :
break;
case V_271 :
case V_273 :
V_119 = - V_117 ;
break;
default:
F_146 () ;
}
return V_119 ;
}
static int T_6 F_147 ( enum V_283 V_284 )
{
int V_119 = 0 ;
while ( V_269 != V_284 ) {
V_119 = F_144 () ;
if ( V_269 == V_271 ||
V_269 == V_273 )
break;
}
return V_119 ;
}
int T_6 F_148 ( void )
{
return F_147 ( V_274 ) ;
}
int T_6 F_149 ( void )
{
return V_226 ? 1 : 0 ;
}
int T_6 F_150 ( void )
{
int V_119 ;
V_119 = F_147 ( V_278 ) ;
if ( V_119 )
return V_119 ;
V_204 = 1 ;
return 0 ;
}
void F_151 ( void )
{
F_121 () ;
}
int F_152 ( int V_285 )
{
F_119 () ;
return 0 ;
}
int T_6 F_153 ( void )
{
return 0 ;
}
static int T_6 F_154 ( void )
{
int V_119 ;
V_119 = F_147 ( V_282 ) ;
if ( V_119 ) {
F_129 () ;
if ( ! V_204 ) {
F_118 () ;
F_122 () ;
} else {
struct V_6 * V_7 ;
F_110 () ;
F_93 (iommu)
F_115 ( V_7 ) ;
}
}
return V_119 ;
}
int T_6 F_155 ( void )
{
int V_119 ;
if ( V_286 || ( V_287 && ! V_288 ) )
return - V_57 ;
if ( V_289 )
return - V_57 ;
V_119 = F_147 ( V_272 ) ;
if ( V_119 )
return V_119 ;
V_257 = true ;
V_287 = 1 ;
V_290 . V_7 . V_291 = F_154 ;
return 0 ;
}
static int T_6 F_156 ( char * V_292 )
{
V_293 = true ;
return 1 ;
}
static int T_6 F_157 ( char * V_292 )
{
for (; * V_292 ; ++ V_292 ) {
if ( strncmp ( V_292 , L_60 , 9 ) == 0 )
V_294 = true ;
if ( strncmp ( V_292 , L_61 , 3 ) == 0 )
V_289 = true ;
if ( strncmp ( V_292 , L_62 , 15 ) == 0 )
V_295 = true ;
}
return 1 ;
}
static int T_6 F_158 ( char * V_292 )
{
unsigned int V_39 , V_11 , V_40 ;
int V_119 , V_108 , V_55 ;
T_1 V_1 ;
V_119 = sscanf ( V_292 , L_63 , & V_108 , & V_39 , & V_11 , & V_40 ) ;
if ( V_119 != 4 ) {
F_24 ( L_64 , V_292 ) ;
return 1 ;
}
if ( V_120 == V_296 ) {
F_24 ( L_65 ,
V_292 ) ;
return 1 ;
}
V_1 = ( ( V_39 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_40 & 0x7 ) ;
V_249 = true ;
V_55 = V_120 ++ ;
V_121 [ V_55 ] . V_108 = V_108 ;
V_121 [ V_55 ] . V_1 = V_1 ;
V_121 [ V_55 ] . V_109 = true ;
return 1 ;
}
static int T_6 F_159 ( char * V_292 )
{
unsigned int V_39 , V_11 , V_40 ;
int V_119 , V_108 , V_55 ;
T_1 V_1 ;
V_119 = sscanf ( V_292 , L_63 , & V_108 , & V_39 , & V_11 , & V_40 ) ;
if ( V_119 != 4 ) {
F_24 ( L_66 , V_292 ) ;
return 1 ;
}
if ( V_122 == V_296 ) {
F_24 ( L_67 ,
V_292 ) ;
return 1 ;
}
V_1 = ( ( V_39 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_40 & 0x7 ) ;
V_249 = true ;
V_55 = V_122 ++ ;
V_123 [ V_55 ] . V_108 = V_108 ;
V_123 [ V_55 ] . V_1 = V_1 ;
V_123 [ V_55 ] . V_109 = true ;
return 1 ;
}
bool F_160 ( void )
{
return V_192 ;
}
T_3 F_161 ( T_1 V_1 )
{
struct V_6 * V_7 ;
T_3 V_119 = 0 ;
V_7 = V_93 [ V_1 ] ;
if ( V_7 )
V_119 = V_7 -> V_168 ;
return V_119 ;
}
bool F_162 ( void )
{
return V_167 ;
}
T_3 F_163 ( T_1 V_1 )
{
struct V_6 * V_7 ;
T_3 V_119 = 0 ;
V_7 = V_93 [ V_1 ] ;
if ( V_7 )
V_119 = V_7 -> V_169 ;
return V_119 ;
}
int F_84 ( T_1 V_1 , T_3 V_297 , T_3 V_298 , T_3 V_299 ,
T_4 * V_148 , bool V_300 )
{
struct V_6 * V_7 ;
T_2 V_301 ;
T_2 V_302 ;
if ( ! V_167 )
return - V_57 ;
V_7 = V_93 [ V_1 ] ;
if ( F_39 ( ( V_7 == NULL ) || ( V_299 > 0x28 ) || ( V_299 & 7 ) ) )
return - V_57 ;
V_301 = ( T_2 ) ( ( ( 0x40 | V_297 ) << 12 ) | ( V_298 << 8 ) | V_299 ) ;
V_302 = ( T_2 ) ( ( ( 0x40 | V_7 -> V_168 ) << 12 ) |
( V_7 -> V_169 << 8 ) | 0x28 ) ;
if ( ( V_301 < V_303 ) ||
( V_301 > V_302 ) )
return - V_117 ;
if ( V_300 ) {
F_17 ( ( T_2 ) * V_148 , V_7 -> V_19 + V_301 ) ;
F_17 ( ( * V_148 >> 32 ) , V_7 -> V_19 + V_301 + 4 ) ;
} else {
* V_148 = F_16 ( V_7 -> V_19 + V_301 + 4 ) ;
* V_148 <<= 32 ;
* V_148 = F_16 ( V_7 -> V_19 + V_301 ) ;
}
return 0 ;
}
