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
static int T_6 F_60 ( T_3 type , T_3 V_108 , T_1 * V_1 , bool V_109 )
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
* V_1 = V_17 -> V_1 ;
return 0 ;
}
V_17 = F_63 ( sizeof( * V_17 ) , V_61 ) ;
if ( ! V_17 )
return - V_118 ;
V_17 -> V_108 = V_108 ;
V_17 -> V_1 = * V_1 ;
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
& V_121 [ V_55 ] . V_1 ,
V_121 [ V_55 ] . V_109 ) ;
if ( V_119 )
return V_119 ;
}
for ( V_55 = 0 ; V_55 < V_122 ; ++ V_55 ) {
V_119 = F_60 ( V_115 ,
V_123 [ V_55 ] . V_108 ,
& V_123 [ V_55 ] . V_1 ,
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
V_119 = F_60 ( type , V_145 , & V_1 , false ) ;
if ( V_119 )
return V_119 ;
F_59 ( V_7 , V_1 , V_134 -> V_94 , 0 ) ;
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
static T_7 F_85 ( struct V_170 * V_11 ,
struct V_171 * V_172 ,
char * V_173 )
{
struct V_6 * V_7 = F_86 ( V_11 ) ;
return sprintf ( V_173 , L_32 , V_7 -> V_42 ) ;
}
static T_7 F_87 ( struct V_170 * V_11 ,
struct V_171 * V_172 ,
char * V_173 )
{
struct V_6 * V_7 = F_86 ( V_11 ) ;
return sprintf ( V_173 , L_33 , V_7 -> V_174 ) ;
}
static int F_88 ( struct V_6 * V_7 )
{
int V_41 = V_7 -> V_41 ;
T_2 V_175 , V_176 , V_177 , V_178 ;
V_7 -> V_11 = F_89 ( F_36 ( V_7 -> V_1 ) ,
V_7 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return - V_57 ;
F_6 ( V_7 -> V_11 , V_41 + V_179 ,
& V_7 -> V_42 ) ;
F_6 ( V_7 -> V_11 , V_41 + V_43 ,
& V_175 ) ;
F_6 ( V_7 -> V_11 , V_41 + V_180 ,
& V_176 ) ;
V_7 -> V_137 = F_32 ( F_33 ( V_175 ) ,
F_90 ( V_175 ) ) ;
V_7 -> V_138 = F_32 ( F_33 ( V_175 ) ,
F_34 ( V_175 ) ) ;
if ( ! ( V_7 -> V_42 & ( 1 << V_181 ) ) )
V_182 = false ;
V_177 = F_16 ( V_7 -> V_19 + V_183 ) ;
V_178 = F_16 ( V_7 -> V_19 + V_183 + 4 ) ;
V_7 -> V_174 = ( ( T_4 ) V_178 << 32 ) | V_177 ;
if ( F_54 ( V_7 , V_85 ) ) {
int V_184 ;
T_2 V_185 ;
T_4 V_186 ;
V_186 = V_7 -> V_174 & V_187 ;
V_186 >>= V_188 ;
V_185 = ( 1 << ( V_186 + 1 ) ) - 1 ;
V_189 = F_91 ( V_189 , V_185 ) ;
F_13 ( V_189 & ~ V_190 ) ;
V_184 = V_7 -> V_174 & V_191 ;
V_184 >>= V_192 ;
if ( V_193 == - 1 )
V_193 = V_184 ;
else
V_193 = F_91 ( V_193 , V_184 ) ;
}
if ( F_54 ( V_7 , V_85 ) &&
F_54 ( V_7 , V_194 ) ) {
V_7 -> V_195 = true ;
V_196 = true ;
}
if ( F_54 ( V_7 , V_194 ) ) {
V_7 -> V_77 = F_50 ( V_7 ) ;
if ( ! V_7 -> V_77 )
return - V_118 ;
}
if ( V_7 -> V_42 & ( 1UL << V_197 ) )
V_198 = true ;
F_83 ( V_7 ) ;
if ( F_92 ( V_7 -> V_11 ) ) {
int V_55 , V_199 ;
V_7 -> V_200 = F_89 ( V_7 -> V_11 -> V_39 -> V_201 ,
F_93 ( 0 , 0 ) ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_41 + 4 ,
& V_7 -> V_202 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_41 + 8 ,
& V_7 -> V_203 ) ;
V_7 -> V_202 &= ~ 1 ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_199 = 0 ; V_199 < 0x12 ; V_199 ++ )
V_7 -> V_204 [ V_55 ] [ V_199 ] = F_4 ( V_7 , V_55 , V_199 ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
V_7 -> V_205 [ V_55 ] = F_8 ( V_7 , V_55 ) ;
}
F_75 ( V_7 ) ;
V_7 -> V_206 = F_94 ( & V_7 -> V_11 -> V_11 , V_7 ,
V_207 , L_34 ,
V_7 -> V_154 ) ;
return F_95 ( V_7 -> V_11 ) ;
}
static void F_96 ( void )
{
static const char * const V_208 [] = {
L_35 , L_36 , L_37 , L_38 , L_39 , L_40 ,
L_41 , L_42 , L_43 , L_44
} ;
struct V_6 * V_7 ;
F_97 (iommu) {
int V_55 ;
F_62 ( L_45 ,
F_77 ( & V_7 -> V_11 -> V_11 ) , V_7 -> V_41 ) ;
if ( V_7 -> V_42 & ( 1 << V_209 ) ) {
F_62 ( L_46 ) ;
for ( V_55 = 0 ; V_55 < F_98 ( V_208 ) ; ++ V_55 ) {
if ( F_54 ( V_7 , ( 1ULL << V_55 ) ) )
F_99 ( L_47 , V_208 [ V_55 ] ) ;
}
F_99 ( L_48 ) ;
}
}
if ( V_210 )
F_62 ( L_49 ) ;
}
static int T_6 F_100 ( void )
{
struct V_6 * V_7 ;
int V_119 = 0 ;
F_97 (iommu) {
V_119 = F_88 ( V_7 ) ;
if ( V_119 )
break;
}
V_119 = F_101 () ;
F_96 () ;
return V_119 ;
}
static int F_102 ( struct V_6 * V_7 )
{
int V_211 ;
V_211 = F_103 ( V_7 -> V_11 ) ;
if ( V_211 )
return V_211 ;
V_211 = F_104 ( V_7 -> V_11 -> V_212 ,
V_213 ,
V_214 ,
0 , L_50 ,
V_7 ) ;
if ( V_211 ) {
F_105 ( V_7 -> V_11 ) ;
return V_211 ;
}
V_7 -> V_163 = true ;
return 0 ;
}
static int F_106 ( struct V_6 * V_7 )
{
int V_119 ;
if ( V_7 -> V_163 )
goto V_215;
if ( V_7 -> V_11 -> V_216 )
V_119 = F_102 ( V_7 ) ;
else
V_119 = - V_57 ;
if ( V_119 )
return V_119 ;
V_215:
F_15 ( V_7 , V_33 ) ;
if ( V_7 -> V_77 != NULL )
F_15 ( V_7 , V_217 ) ;
return 0 ;
}
static void T_6 F_107 ( void )
{
struct V_218 * V_17 , * V_147 ;
F_108 (entry, next, &amd_iommu_unity_map, list) {
F_73 ( & V_17 -> V_112 ) ;
F_74 ( V_17 ) ;
}
}
static int T_6 F_109 ( struct V_124 * V_125 )
{
int V_55 ;
switch ( V_125 -> type ) {
case V_219 :
F_66 ( V_125 -> V_1 , V_125 ) ;
break;
case V_220 :
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
F_66 ( V_55 , V_125 ) ;
break;
case V_221 :
for ( V_55 = V_125 -> V_1 ; V_55 <= V_125 -> V_222 ; ++ V_55 )
F_66 ( V_55 , V_125 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_110 ( struct V_124 * V_125 )
{
struct V_218 * V_134 = NULL ;
char * V_223 ;
V_134 = F_63 ( sizeof( * V_134 ) , V_61 ) ;
if ( V_134 == NULL )
return - V_118 ;
switch ( V_125 -> type ) {
default:
F_74 ( V_134 ) ;
return 0 ;
case V_219 :
V_223 = L_51 ;
V_134 -> V_130 = V_134 -> V_224 = V_125 -> V_1 ;
break;
case V_220 :
V_223 = L_52 ;
V_134 -> V_130 = 0 ;
V_134 -> V_224 = V_2 ;
break;
case V_221 :
V_223 = L_53 ;
V_134 -> V_130 = V_125 -> V_1 ;
V_134 -> V_224 = V_125 -> V_222 ;
break;
}
V_134 -> V_225 = F_111 ( V_125 -> V_128 ) ;
V_134 -> V_226 = V_134 -> V_225 + F_111 ( V_125 -> V_129 ) ;
V_134 -> V_227 = V_125 -> V_94 >> 1 ;
F_68 ( L_54
L_55 , V_223 ,
F_36 ( V_134 -> V_130 ) , F_37 ( V_134 -> V_130 ) ,
F_38 ( V_134 -> V_130 ) , F_36 ( V_134 -> V_224 ) ,
F_37 ( V_134 -> V_224 ) , F_38 ( V_134 -> V_224 ) ,
V_134 -> V_225 , V_134 -> V_226 , V_125 -> V_94 ) ;
F_64 ( & V_134 -> V_112 , & V_228 ) ;
return 0 ;
}
static int T_6 F_112 ( struct V_53 * V_54 )
{
T_3 * V_46 = ( T_3 * ) V_54 , * V_35 = ( T_3 * ) V_54 ;
struct V_124 * V_125 ;
V_35 += V_54 -> V_48 ;
V_46 += V_58 ;
while ( V_46 < V_35 ) {
V_125 = (struct V_124 * ) V_46 ;
if ( V_125 -> V_94 & V_126 )
F_109 ( V_125 ) ;
else if ( V_125 -> V_94 & V_229 )
F_110 ( V_125 ) ;
V_46 += V_125 -> V_48 ;
}
return 0 ;
}
static void F_113 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_55 ( V_1 , V_230 ) ;
F_55 ( V_1 , V_231 ) ;
}
}
static void T_6 F_114 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
V_22 [ V_1 ] . V_88 [ 0 ] = 0ULL ;
V_22 [ V_1 ] . V_88 [ 1 ] = 0ULL ;
}
}
static void F_115 ( void )
{
T_2 V_1 ;
if ( ! V_232 )
return;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 )
F_55 ( V_1 , V_233 ) ;
}
static void F_116 ( struct V_6 * V_7 )
{
V_7 -> V_135 & V_234 ?
F_15 ( V_7 , V_235 ) :
F_18 ( V_7 , V_235 ) ;
V_7 -> V_135 & V_236 ?
F_15 ( V_7 , V_237 ) :
F_18 ( V_7 , V_237 ) ;
V_7 -> V_135 & V_238 ?
F_15 ( V_7 , V_239 ) :
F_18 ( V_7 , V_239 ) ;
V_7 -> V_135 & V_240 ?
F_15 ( V_7 , V_241 ) :
F_18 ( V_7 , V_241 ) ;
F_15 ( V_7 , V_242 ) ;
F_19 ( V_7 , V_243 ) ;
}
static void F_117 ( struct V_6 * V_7 )
{
int V_55 , V_199 ;
T_2 V_244 ;
struct V_245 * V_246 = V_7 -> V_200 ;
if ( ! F_92 ( V_7 -> V_11 ) || ! V_246 )
return;
F_5 ( V_246 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_246 , 0x64 , & V_244 ) ;
if ( ! ( V_244 & 0x1 ) )
F_5 ( V_246 , 0x64 , V_244 | 1 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_41 + 4 ,
V_7 -> V_202 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_41 + 8 ,
V_7 -> V_203 ) ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_199 = 0 ; V_199 < 0x12 ; V_199 ++ )
F_7 ( V_7 , V_55 , V_199 , V_7 -> V_204 [ V_55 ] [ V_199 ] ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
F_9 ( V_7 , V_55 , V_7 -> V_205 [ V_55 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_41 + 4 ,
V_7 -> V_202 | 1 ) ;
}
static void F_118 ( void )
{
struct V_6 * V_7 ;
F_97 (iommu) {
F_21 ( V_7 ) ;
F_116 ( V_7 ) ;
F_12 ( V_7 ) ;
F_44 ( V_7 ) ;
F_48 ( V_7 ) ;
F_10 ( V_7 ) ;
F_20 ( V_7 ) ;
F_119 ( V_7 ) ;
}
}
static void F_120 ( void )
{
struct V_6 * V_7 ;
F_97 (iommu) {
F_51 ( V_7 ) ;
F_53 ( V_7 ) ;
}
}
static void F_121 ( void )
{
F_118 () ;
F_120 () ;
}
static void F_122 ( void )
{
struct V_6 * V_7 ;
F_97 (iommu)
F_21 ( V_7 ) ;
}
static void F_123 ( void )
{
struct V_6 * V_7 ;
F_97 (iommu)
F_117 ( V_7 ) ;
F_121 () ;
F_124 () ;
}
static int F_125 ( void )
{
F_122 () ;
return 0 ;
}
static void T_6 F_126 ( void )
{
F_46 ( ( unsigned long ) V_247 ,
F_3 ( V_248 ) ) ;
if ( V_249 ) {
F_127 ( V_249 ) ;
V_249 = NULL ;
}
F_46 ( ( unsigned long ) V_93 ,
F_3 ( V_248 ) ) ;
F_46 ( ( unsigned long ) V_141 ,
F_3 ( V_250 ) ) ;
F_46 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_71 () ;
#ifdef F_128
F_129 () ;
#endif
}
static bool T_6 F_130 ( void )
{
const char * V_251 = V_252 ;
bool V_119 , V_253 ;
int V_254 ;
V_253 = false ;
V_119 = false ;
if ( V_255 )
V_251 = L_56 ;
for ( V_254 = 0 ; V_254 < V_256 ; V_254 ++ ) {
int V_1 , V_108 = F_131 ( V_254 ) ;
V_1 = F_132 ( V_108 ) ;
if ( V_1 < 0 ) {
F_24 ( L_57 ,
V_251 , V_108 ) ;
V_119 = false ;
} else if ( V_1 == V_257 ) {
V_253 = true ;
V_119 = true ;
}
}
if ( ! V_253 ) {
F_24 ( L_58 , V_251 ) ;
}
if ( ! V_119 )
F_24 ( L_59 ) ;
return V_119 ;
}
static void T_6 F_133 ( void )
{
F_134 () ;
F_46 ( ( unsigned long ) V_258 ,
F_3 ( V_259 / 8 ) ) ;
F_107 () ;
}
static int T_6 F_135 ( void )
{
struct V_53 * V_260 ;
T_8 V_261 ;
T_9 V_262 ;
int V_55 , V_119 = 0 ;
if ( ! V_263 )
return - V_57 ;
V_262 = F_136 ( L_60 , 0 , & V_260 , & V_261 ) ;
if ( V_262 == V_264 )
return - V_57 ;
else if ( F_137 ( V_262 ) ) {
const char * V_265 = F_138 ( V_262 ) ;
F_24 ( L_61 , V_265 ) ;
return - V_117 ;
}
V_119 = F_40 ( V_260 ) ;
if ( V_119 )
goto V_266;
V_23 = F_2 ( V_267 ) ;
V_250 = F_2 ( V_268 ) ;
V_248 = F_2 ( V_269 ) ;
V_119 = - V_118 ;
V_22 = ( void * ) F_42 ( V_61 | V_62 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_266;
V_141 = ( void * ) F_42 ( V_61 ,
F_3 ( V_250 ) ) ;
if ( V_141 == NULL )
goto V_266;
V_93 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_248 ) ) ;
if ( V_93 == NULL )
goto V_266;
V_258 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_259 / 8 ) ) ;
if ( V_258 == NULL )
goto V_266;
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
V_141 [ V_55 ] = V_55 ;
V_258 [ 0 ] = 1 ;
F_79 ( & V_270 ) ;
V_119 = F_82 ( V_260 ) ;
if ( V_119 )
goto V_266;
if ( V_232 )
V_232 = F_130 () ;
if ( V_232 ) {
V_119 = - V_118 ;
V_249 = F_139 ( L_62 ,
V_271 * sizeof( T_2 ) ,
V_272 ,
0 , NULL ) ;
if ( ! V_249 )
goto V_266;
V_247 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_248 ) ) ;
if ( ! V_247 )
goto V_266;
}
V_119 = F_112 ( V_260 ) ;
if ( V_119 )
goto V_266;
F_115 () ;
V_266:
F_140 ( ( char T_5 * ) V_260 , V_261 ) ;
V_260 = NULL ;
return V_119 ;
}
static int F_124 ( void )
{
struct V_6 * V_7 ;
int V_119 = 0 ;
F_97 (iommu) {
V_119 = F_106 ( V_7 ) ;
if ( V_119 )
goto V_266;
}
V_266:
return V_119 ;
}
static bool F_141 ( void )
{
struct V_53 * V_260 ;
T_8 V_261 ;
T_9 V_262 ;
V_262 = F_136 ( L_60 , 0 , & V_260 , & V_261 ) ;
if ( V_262 == V_264 )
return false ;
else if ( F_137 ( V_262 ) ) {
const char * V_265 = F_138 ( V_262 ) ;
F_24 ( L_61 , V_265 ) ;
return false ;
}
F_140 ( ( char T_5 * ) V_260 , V_261 ) ;
F_142 () ;
return true ;
}
static int F_143 ( void )
{
struct V_6 * V_7 ;
int V_119 ;
if ( V_273 )
V_119 = F_144 () ;
else
V_119 = F_145 () ;
if ( V_119 )
return V_119 ;
F_113 () ;
F_97 (iommu)
F_119 ( V_7 ) ;
F_146 () ;
F_147 () ;
return 0 ;
}
static int T_6 F_148 ( void )
{
int V_119 = 0 ;
switch ( V_274 ) {
case V_275 :
if ( ! F_141 () ) {
V_274 = V_276 ;
V_119 = - V_57 ;
} else {
V_274 = V_277 ;
}
break;
case V_277 :
V_119 = F_135 () ;
V_274 = V_119 ? V_278 : V_279 ;
break;
case V_279 :
F_118 () ;
F_149 ( & V_280 ) ;
V_281 . V_282 = F_122 ;
V_274 = V_283 ;
break;
case V_283 :
V_119 = F_100 () ;
V_274 = V_119 ? V_278 : V_284 ;
F_120 () ;
break;
case V_284 :
V_119 = F_124 () ;
V_274 = V_119 ? V_278 : V_285 ;
break;
case V_285 :
V_119 = F_143 () ;
V_274 = V_119 ? V_278 : V_286 ;
break;
case V_286 :
V_274 = V_287 ;
break;
case V_287 :
break;
case V_276 :
case V_278 :
V_119 = - V_117 ;
break;
default:
F_150 () ;
}
return V_119 ;
}
static int T_6 F_151 ( enum V_288 V_289 )
{
int V_119 = 0 ;
while ( V_274 != V_289 ) {
V_119 = F_148 () ;
if ( V_274 == V_276 ||
V_274 == V_278 )
break;
}
return V_119 ;
}
int T_6 F_152 ( void )
{
int V_119 ;
V_232 = true ;
V_119 = F_151 ( V_279 ) ;
if ( V_119 )
return V_119 ;
return V_232 ? 0 : - V_57 ;
}
int T_6 F_153 ( void )
{
int V_119 ;
V_119 = F_151 ( V_283 ) ;
if ( V_119 )
return V_119 ;
V_210 = 1 ;
return 0 ;
}
void F_154 ( void )
{
F_125 () ;
}
int F_155 ( int V_290 )
{
F_123 () ;
return 0 ;
}
int T_6 F_156 ( void )
{
return 0 ;
}
static int T_6 F_157 ( void )
{
int V_119 ;
V_119 = F_151 ( V_287 ) ;
if ( V_119 ) {
F_133 () ;
if ( ! V_210 ) {
F_122 () ;
F_126 () ;
} else {
struct V_6 * V_7 ;
F_114 () ;
F_97 (iommu)
F_119 ( V_7 ) ;
}
}
return V_119 ;
}
int T_6 F_158 ( void )
{
int V_119 ;
if ( V_291 || ( V_292 && ! V_293 ) )
return - V_57 ;
if ( V_294 )
return - V_57 ;
V_119 = F_151 ( V_277 ) ;
if ( V_119 )
return V_119 ;
V_263 = true ;
V_292 = 1 ;
V_295 . V_7 . V_296 = F_157 ;
return 0 ;
}
static int T_6 F_159 ( char * V_297 )
{
V_298 = true ;
return 1 ;
}
static int T_6 F_160 ( char * V_297 )
{
for (; * V_297 ; ++ V_297 ) {
if ( strncmp ( V_297 , L_63 , 9 ) == 0 )
V_299 = true ;
if ( strncmp ( V_297 , L_64 , 3 ) == 0 )
V_294 = true ;
if ( strncmp ( V_297 , L_65 , 15 ) == 0 )
V_300 = true ;
}
return 1 ;
}
static int T_6 F_161 ( char * V_297 )
{
unsigned int V_39 , V_11 , V_40 ;
int V_119 , V_108 , V_55 ;
T_1 V_1 ;
V_119 = sscanf ( V_297 , L_66 , & V_108 , & V_39 , & V_11 , & V_40 ) ;
if ( V_119 != 4 ) {
F_24 ( L_67 , V_297 ) ;
return 1 ;
}
if ( V_120 == V_301 ) {
F_24 ( L_68 ,
V_297 ) ;
return 1 ;
}
V_1 = ( ( V_39 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_40 & 0x7 ) ;
V_255 = true ;
V_55 = V_120 ++ ;
V_121 [ V_55 ] . V_108 = V_108 ;
V_121 [ V_55 ] . V_1 = V_1 ;
V_121 [ V_55 ] . V_109 = true ;
return 1 ;
}
static int T_6 F_162 ( char * V_297 )
{
unsigned int V_39 , V_11 , V_40 ;
int V_119 , V_108 , V_55 ;
T_1 V_1 ;
V_119 = sscanf ( V_297 , L_66 , & V_108 , & V_39 , & V_11 , & V_40 ) ;
if ( V_119 != 4 ) {
F_24 ( L_69 , V_297 ) ;
return 1 ;
}
if ( V_122 == V_301 ) {
F_24 ( L_70 ,
V_297 ) ;
return 1 ;
}
V_1 = ( ( V_39 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_40 & 0x7 ) ;
V_255 = true ;
V_55 = V_122 ++ ;
V_123 [ V_55 ] . V_108 = V_108 ;
V_123 [ V_55 ] . V_1 = V_1 ;
V_123 [ V_55 ] . V_109 = true ;
return 1 ;
}
bool F_163 ( void )
{
return V_196 ;
}
T_3 F_164 ( T_1 V_1 )
{
struct V_6 * V_7 ;
T_3 V_119 = 0 ;
V_7 = V_93 [ V_1 ] ;
if ( V_7 )
V_119 = V_7 -> V_168 ;
return V_119 ;
}
bool F_165 ( void )
{
return V_167 ;
}
T_3 F_166 ( T_1 V_1 )
{
struct V_6 * V_7 ;
T_3 V_119 = 0 ;
V_7 = V_93 [ V_1 ] ;
if ( V_7 )
V_119 = V_7 -> V_169 ;
return V_119 ;
}
int F_84 ( T_1 V_1 , T_3 V_302 , T_3 V_303 , T_3 V_304 ,
T_4 * V_148 , bool V_305 )
{
struct V_6 * V_7 ;
T_2 V_306 ;
T_2 V_307 ;
if ( ! V_167 )
return - V_57 ;
V_7 = V_93 [ V_1 ] ;
if ( F_39 ( ( V_7 == NULL ) || ( V_304 > 0x28 ) || ( V_304 & 7 ) ) )
return - V_57 ;
V_306 = ( T_2 ) ( ( ( 0x40 | V_302 ) << 12 ) | ( V_303 << 8 ) | V_304 ) ;
V_307 = ( T_2 ) ( ( ( 0x40 | V_7 -> V_168 ) << 12 ) |
( V_7 -> V_169 << 8 ) | 0x28 ) ;
if ( ( V_306 < V_308 ) ||
( V_306 > V_307 ) )
return - V_117 ;
if ( V_305 ) {
F_17 ( ( T_2 ) * V_148 , V_7 -> V_19 + V_306 ) ;
F_17 ( ( * V_148 >> 32 ) , V_7 -> V_19 + V_306 + 4 ) ;
} else {
* V_148 = F_16 ( V_7 -> V_19 + V_306 + 4 ) ;
* V_148 <<= 32 ;
* V_148 = F_16 ( V_7 -> V_19 + V_306 ) ;
}
return 0 ;
}
