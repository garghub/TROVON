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
F_55 ( V_125 -> V_1 , V_127 ) ;
V_7 -> V_13 = V_125 -> V_128 ;
V_7 -> V_16 = V_125 -> V_129 ;
}
}
static int T_6 F_67 ( struct V_6 * V_7 ,
struct V_43 * V_44 )
{
T_3 * V_45 = ( T_3 * ) V_44 ;
T_3 * V_46 = V_45 , V_94 = 0 ;
T_1 V_1 = 0 , V_130 = 0 , V_131 = 0 ;
T_2 V_132 , V_95 = 0 ;
bool V_133 = false ;
struct V_47 * V_134 ;
int V_119 ;
V_119 = F_65 () ;
if ( V_119 )
return V_119 ;
V_7 -> V_135 = V_44 -> V_94 ;
V_45 += sizeof( struct V_43 ) ;
V_46 += V_44 -> V_48 ;
while ( V_45 < V_46 ) {
V_134 = (struct V_47 * ) V_45 ;
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
V_45 += F_29 ( V_45 ) ;
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
static int T_6 F_78 ( struct V_6 * V_7 , struct V_43 * V_44 )
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
V_7 -> V_1 = V_44 -> V_1 ;
V_7 -> V_40 = V_44 -> V_40 ;
V_7 -> V_159 = V_44 -> V_159 ;
V_7 -> V_36 = V_44 -> V_36 ;
V_7 -> V_19 = F_22 ( V_44 -> V_36 ) ;
if ( ! V_7 -> V_19 )
return - V_118 ;
V_7 -> V_60 = F_41 ( V_7 ) ;
if ( ! V_7 -> V_60 )
return - V_118 ;
V_7 -> V_70 = F_47 ( V_7 ) ;
if ( ! V_7 -> V_70 )
return - V_118 ;
V_7 -> V_160 = false ;
V_119 = F_67 ( V_7 , V_44 ) ;
if ( V_119 )
return V_119 ;
V_93 [ V_7 -> V_1 ] = NULL ;
F_69 ( V_7 ) ;
return 0 ;
}
static int T_6 F_82 ( struct V_53 * V_54 )
{
T_3 * V_45 = ( T_3 * ) V_54 , * V_46 = ( T_3 * ) V_54 ;
struct V_43 * V_44 ;
struct V_6 * V_7 ;
int V_119 ;
V_46 += V_54 -> V_48 ;
V_45 += V_58 ;
while ( V_45 < V_46 ) {
V_44 = (struct V_43 * ) V_45 ;
switch ( * V_45 ) {
case V_59 :
F_68 ( L_27
L_28 ,
F_36 ( V_44 -> V_1 ) , F_37 ( V_44 -> V_1 ) ,
F_38 ( V_44 -> V_1 ) , V_44 -> V_40 ,
V_44 -> V_159 , V_44 -> V_94 , V_44 -> V_161 ) ;
F_68 ( L_29 ,
V_44 -> V_36 ) ;
V_7 = F_63 ( sizeof( struct V_6 ) , V_61 ) ;
if ( V_7 == NULL )
return - V_118 ;
V_119 = F_78 ( V_7 , V_44 ) ;
if ( V_119 )
return V_119 ;
break;
default:
break;
}
V_45 += V_44 -> V_48 ;
}
F_39 ( V_45 != V_46 ) ;
return 0 ;
}
static int F_83 ( struct V_6 * V_7 )
{
int V_40 = V_7 -> V_40 ;
T_2 V_162 , V_163 , V_164 , V_165 ;
V_7 -> V_11 = F_84 ( F_36 ( V_7 -> V_1 ) ,
V_7 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return - V_57 ;
F_6 ( V_7 -> V_11 , V_40 + V_166 ,
& V_7 -> V_41 ) ;
F_6 ( V_7 -> V_11 , V_40 + V_42 ,
& V_162 ) ;
F_6 ( V_7 -> V_11 , V_40 + V_167 ,
& V_163 ) ;
V_7 -> V_137 = F_32 ( F_33 ( V_162 ) ,
F_85 ( V_162 ) ) ;
V_7 -> V_138 = F_32 ( F_33 ( V_162 ) ,
F_34 ( V_162 ) ) ;
if ( ! ( V_7 -> V_41 & ( 1 << V_168 ) ) )
V_169 = false ;
V_164 = F_16 ( V_7 -> V_19 + V_170 ) ;
V_165 = F_16 ( V_7 -> V_19 + V_170 + 4 ) ;
V_7 -> V_171 = ( ( T_4 ) V_165 << 32 ) | V_164 ;
if ( F_54 ( V_7 , V_85 ) ) {
int V_172 ;
T_2 V_173 ;
T_4 V_4 ;
V_4 = V_7 -> V_171 & V_174 ;
V_4 >>= V_175 ;
V_173 = ( 1 << V_4 ) ;
V_176 = F_86 ( V_176 , V_173 ) ;
V_172 = V_7 -> V_171 & V_177 ;
V_172 >>= V_178 ;
if ( V_179 == - 1 )
V_179 = V_172 ;
else
V_179 = F_86 ( V_179 , V_172 ) ;
}
if ( F_54 ( V_7 , V_85 ) &&
F_54 ( V_7 , V_180 ) ) {
V_7 -> V_181 = true ;
V_182 = true ;
}
if ( F_54 ( V_7 , V_180 ) ) {
V_7 -> V_77 = F_50 ( V_7 ) ;
if ( ! V_7 -> V_77 )
return - V_118 ;
}
if ( V_7 -> V_41 & ( 1UL << V_183 ) )
V_184 = true ;
if ( F_87 ( V_7 -> V_11 ) ) {
int V_55 , V_185 ;
V_7 -> V_186 = F_84 ( V_7 -> V_11 -> V_38 -> V_187 ,
F_88 ( 0 , 0 ) ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
& V_7 -> V_188 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_40 + 8 ,
& V_7 -> V_189 ) ;
V_7 -> V_188 &= ~ 1 ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_185 = 0 ; V_185 < 0x12 ; V_185 ++ )
V_7 -> V_190 [ V_55 ] [ V_185 ] = F_4 ( V_7 , V_55 , V_185 ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
V_7 -> V_191 [ V_55 ] = F_8 ( V_7 , V_55 ) ;
}
F_75 ( V_7 ) ;
return F_89 ( V_7 -> V_11 ) ;
}
static void F_90 ( void )
{
static const char * const V_192 [] = {
L_30 , L_31 , L_32 , L_33 , L_34 , L_35 ,
L_36 , L_37 , L_38 , L_39
} ;
struct V_6 * V_7 ;
F_91 (iommu) {
int V_55 ;
F_62 ( L_40 ,
F_77 ( & V_7 -> V_11 -> V_11 ) , V_7 -> V_40 ) ;
if ( V_7 -> V_41 & ( 1 << V_193 ) ) {
F_62 ( L_41 ) ;
for ( V_55 = 0 ; V_55 < F_92 ( V_192 ) ; ++ V_55 ) {
if ( F_54 ( V_7 , ( 1ULL << V_55 ) ) )
F_93 ( L_42 , V_192 [ V_55 ] ) ;
}
F_93 ( L_43 ) ;
}
}
if ( V_194 )
F_62 ( L_44 ) ;
}
static int T_6 F_94 ( void )
{
struct V_6 * V_7 ;
int V_119 = 0 ;
F_91 (iommu) {
V_119 = F_83 ( V_7 ) ;
if ( V_119 )
break;
}
V_119 = F_95 () ;
F_90 () ;
return V_119 ;
}
static int F_96 ( struct V_6 * V_7 )
{
int V_195 ;
V_195 = F_97 ( V_7 -> V_11 ) ;
if ( V_195 )
return V_195 ;
V_195 = F_98 ( V_7 -> V_11 -> V_196 ,
V_197 ,
V_198 ,
0 , L_45 ,
V_7 ) ;
if ( V_195 ) {
F_99 ( V_7 -> V_11 ) ;
return V_195 ;
}
V_7 -> V_160 = true ;
return 0 ;
}
static int F_100 ( struct V_6 * V_7 )
{
int V_119 ;
if ( V_7 -> V_160 )
goto V_199;
if ( F_101 ( V_7 -> V_11 , V_200 ) )
V_119 = F_96 ( V_7 ) ;
else
V_119 = - V_57 ;
if ( V_119 )
return V_119 ;
V_199:
F_15 ( V_7 , V_33 ) ;
if ( V_7 -> V_77 != NULL )
F_15 ( V_7 , V_201 ) ;
return 0 ;
}
static void T_6 F_102 ( void )
{
struct V_202 * V_17 , * V_147 ;
F_103 (entry, next, &amd_iommu_unity_map, list) {
F_73 ( & V_17 -> V_112 ) ;
F_74 ( V_17 ) ;
}
}
static int T_6 F_104 ( struct V_124 * V_125 )
{
int V_55 ;
switch ( V_125 -> type ) {
case V_203 :
F_66 ( V_125 -> V_1 , V_125 ) ;
break;
case V_204 :
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
F_66 ( V_55 , V_125 ) ;
break;
case V_205 :
for ( V_55 = V_125 -> V_1 ; V_55 <= V_125 -> V_206 ; ++ V_55 )
F_66 ( V_55 , V_125 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_105 ( struct V_124 * V_125 )
{
struct V_202 * V_134 = NULL ;
char * V_207 ;
V_134 = F_63 ( sizeof( * V_134 ) , V_61 ) ;
if ( V_134 == NULL )
return - V_118 ;
switch ( V_125 -> type ) {
default:
F_74 ( V_134 ) ;
return 0 ;
case V_203 :
V_207 = L_46 ;
V_134 -> V_130 = V_134 -> V_208 = V_125 -> V_1 ;
break;
case V_204 :
V_207 = L_47 ;
V_134 -> V_130 = 0 ;
V_134 -> V_208 = V_2 ;
break;
case V_205 :
V_207 = L_48 ;
V_134 -> V_130 = V_125 -> V_1 ;
V_134 -> V_208 = V_125 -> V_206 ;
break;
}
V_134 -> V_209 = F_106 ( V_125 -> V_128 ) ;
V_134 -> V_210 = V_134 -> V_209 + F_106 ( V_125 -> V_129 ) ;
V_134 -> V_211 = V_125 -> V_94 >> 1 ;
F_68 ( L_49
L_50 , V_207 ,
F_36 ( V_134 -> V_130 ) , F_37 ( V_134 -> V_130 ) ,
F_38 ( V_134 -> V_130 ) , F_36 ( V_134 -> V_208 ) ,
F_37 ( V_134 -> V_208 ) , F_38 ( V_134 -> V_208 ) ,
V_134 -> V_209 , V_134 -> V_210 , V_125 -> V_94 ) ;
F_64 ( & V_134 -> V_112 , & V_212 ) ;
return 0 ;
}
static int T_6 F_107 ( struct V_53 * V_54 )
{
T_3 * V_45 = ( T_3 * ) V_54 , * V_46 = ( T_3 * ) V_54 ;
struct V_124 * V_125 ;
V_46 += V_54 -> V_48 ;
V_45 += V_58 ;
while ( V_45 < V_46 ) {
V_125 = (struct V_124 * ) V_45 ;
if ( V_125 -> V_94 & V_126 )
F_104 ( V_125 ) ;
else if ( V_125 -> V_94 & V_213 )
F_105 ( V_125 ) ;
V_45 += V_125 -> V_48 ;
}
return 0 ;
}
static void F_108 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_55 ( V_1 , V_214 ) ;
F_55 ( V_1 , V_215 ) ;
}
}
static void T_6 F_109 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
V_22 [ V_1 ] . V_88 [ 0 ] = 0ULL ;
V_22 [ V_1 ] . V_88 [ 1 ] = 0ULL ;
}
}
static void F_110 ( void )
{
T_2 V_1 ;
if ( ! V_216 )
return;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 )
F_55 ( V_1 , V_217 ) ;
}
static void F_111 ( struct V_6 * V_7 )
{
V_7 -> V_135 & V_218 ?
F_15 ( V_7 , V_219 ) :
F_18 ( V_7 , V_219 ) ;
V_7 -> V_135 & V_220 ?
F_15 ( V_7 , V_221 ) :
F_18 ( V_7 , V_221 ) ;
V_7 -> V_135 & V_222 ?
F_15 ( V_7 , V_223 ) :
F_18 ( V_7 , V_223 ) ;
V_7 -> V_135 & V_224 ?
F_15 ( V_7 , V_225 ) :
F_18 ( V_7 , V_225 ) ;
F_15 ( V_7 , V_226 ) ;
F_19 ( V_7 , V_227 ) ;
}
static void F_112 ( struct V_6 * V_7 )
{
int V_55 , V_185 ;
T_2 V_228 ;
struct V_229 * V_230 = V_7 -> V_186 ;
if ( ! F_87 ( V_7 -> V_11 ) || ! V_230 )
return;
F_5 ( V_230 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_230 , 0x64 , & V_228 ) ;
if ( ! ( V_228 & 0x1 ) )
F_5 ( V_230 , 0x64 , V_228 | 1 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
V_7 -> V_188 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 8 ,
V_7 -> V_189 ) ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_185 = 0 ; V_185 < 0x12 ; V_185 ++ )
F_7 ( V_7 , V_55 , V_185 , V_7 -> V_190 [ V_55 ] [ V_185 ] ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
F_9 ( V_7 , V_55 , V_7 -> V_191 [ V_55 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
V_7 -> V_188 | 1 ) ;
}
static void F_113 ( void )
{
struct V_6 * V_7 ;
F_91 (iommu) {
F_21 ( V_7 ) ;
F_111 ( V_7 ) ;
F_12 ( V_7 ) ;
F_44 ( V_7 ) ;
F_48 ( V_7 ) ;
F_10 ( V_7 ) ;
F_20 ( V_7 ) ;
F_114 ( V_7 ) ;
}
}
static void F_115 ( void )
{
struct V_6 * V_7 ;
F_91 (iommu) {
F_51 ( V_7 ) ;
F_53 ( V_7 ) ;
}
}
static void F_116 ( void )
{
F_113 () ;
F_115 () ;
}
static void F_117 ( void )
{
struct V_6 * V_7 ;
F_91 (iommu)
F_21 ( V_7 ) ;
}
static void F_118 ( void )
{
struct V_6 * V_7 ;
F_91 (iommu)
F_112 ( V_7 ) ;
F_116 () ;
F_119 () ;
}
static int F_120 ( void )
{
F_117 () ;
return 0 ;
}
static void T_6 F_121 ( void )
{
F_46 ( ( unsigned long ) V_231 ,
F_3 ( V_232 ) ) ;
if ( V_233 ) {
F_122 ( V_233 ) ;
V_233 = NULL ;
}
F_46 ( ( unsigned long ) V_93 ,
F_3 ( V_232 ) ) ;
F_46 ( ( unsigned long ) V_141 ,
F_3 ( V_234 ) ) ;
F_46 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_71 () ;
#ifdef F_123
F_124 () ;
#endif
}
static bool T_6 F_125 ( void )
{
const char * V_235 = V_236 ;
bool V_119 , V_237 ;
int V_238 ;
V_237 = false ;
V_119 = false ;
if ( V_239 )
V_235 = L_51 ;
for ( V_238 = 0 ; V_238 < V_240 ; V_238 ++ ) {
int V_1 , V_108 = F_126 ( V_238 ) ;
V_1 = F_127 ( V_108 ) ;
if ( V_1 < 0 ) {
F_24 ( L_52 ,
V_235 , V_108 ) ;
V_119 = false ;
} else if ( V_1 == V_241 ) {
V_237 = true ;
V_119 = true ;
}
}
if ( ! V_237 ) {
F_24 ( L_53 , V_235 ) ;
}
if ( ! V_119 )
F_24 ( L_54 ) ;
return V_119 ;
}
static void T_6 F_128 ( void )
{
F_129 () ;
F_46 ( ( unsigned long ) V_242 ,
F_3 ( V_243 / 8 ) ) ;
F_102 () ;
}
static int T_6 F_130 ( void )
{
struct V_53 * V_244 ;
T_7 V_245 ;
T_8 V_246 ;
int V_55 , V_119 = 0 ;
if ( ! V_247 )
return - V_57 ;
V_246 = F_131 ( L_55 , 0 , & V_244 , & V_245 ) ;
if ( V_246 == V_248 )
return - V_57 ;
else if ( F_132 ( V_246 ) ) {
const char * V_249 = F_133 ( V_246 ) ;
F_24 ( L_56 , V_249 ) ;
return - V_117 ;
}
V_119 = F_40 ( V_244 ) ;
if ( V_119 )
goto V_250;
V_23 = F_2 ( V_251 ) ;
V_234 = F_2 ( V_252 ) ;
V_232 = F_2 ( V_253 ) ;
V_119 = - V_118 ;
V_22 = ( void * ) F_42 ( V_61 | V_62 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_250;
V_141 = ( void * ) F_42 ( V_61 ,
F_3 ( V_234 ) ) ;
if ( V_141 == NULL )
goto V_250;
V_93 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_232 ) ) ;
if ( V_93 == NULL )
goto V_250;
V_242 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_243 / 8 ) ) ;
if ( V_242 == NULL )
goto V_250;
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
V_141 [ V_55 ] = V_55 ;
V_242 [ 0 ] = 1 ;
F_79 ( & V_254 ) ;
V_119 = F_82 ( V_244 ) ;
if ( V_119 )
goto V_250;
if ( V_216 )
V_216 = F_125 () ;
if ( V_216 ) {
V_119 = - V_118 ;
V_233 = F_134 ( L_57 ,
V_255 * sizeof( T_2 ) ,
V_256 ,
0 , NULL ) ;
if ( ! V_233 )
goto V_250;
V_231 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_232 ) ) ;
if ( ! V_231 )
goto V_250;
}
V_119 = F_107 ( V_244 ) ;
if ( V_119 )
goto V_250;
F_110 () ;
V_250:
F_135 ( ( char T_5 * ) V_244 , V_245 ) ;
V_244 = NULL ;
return V_119 ;
}
static int F_119 ( void )
{
struct V_6 * V_7 ;
int V_119 = 0 ;
F_91 (iommu) {
V_119 = F_100 ( V_7 ) ;
if ( V_119 )
goto V_250;
}
V_250:
return V_119 ;
}
static bool F_136 ( void )
{
struct V_53 * V_244 ;
T_7 V_245 ;
T_8 V_246 ;
V_246 = F_131 ( L_55 , 0 , & V_244 , & V_245 ) ;
if ( V_246 == V_248 )
return false ;
else if ( F_132 ( V_246 ) ) {
const char * V_249 = F_133 ( V_246 ) ;
F_24 ( L_56 , V_249 ) ;
return false ;
}
F_135 ( ( char T_5 * ) V_244 , V_245 ) ;
F_137 () ;
if ( ! V_257 )
V_216 = true ;
return true ;
}
static int F_138 ( void )
{
struct V_6 * V_7 ;
int V_119 ;
if ( V_258 )
V_119 = F_139 () ;
else
V_119 = F_140 () ;
if ( V_119 )
return V_119 ;
F_108 () ;
F_91 (iommu)
F_114 ( V_7 ) ;
F_141 () ;
F_142 () ;
return 0 ;
}
static int T_6 F_143 ( void )
{
int V_119 = 0 ;
switch ( V_259 ) {
case V_260 :
if ( ! F_136 () ) {
V_259 = V_261 ;
V_119 = - V_57 ;
} else {
V_259 = V_262 ;
}
break;
case V_262 :
V_119 = F_130 () ;
V_259 = V_119 ? V_263 : V_264 ;
break;
case V_264 :
F_113 () ;
F_144 ( & V_265 ) ;
V_266 . V_267 = F_117 ;
V_259 = V_268 ;
break;
case V_268 :
V_119 = F_94 () ;
V_259 = V_119 ? V_263 : V_269 ;
F_115 () ;
break;
case V_269 :
V_119 = F_119 () ;
V_259 = V_119 ? V_263 : V_270 ;
break;
case V_270 :
V_119 = F_138 () ;
V_259 = V_119 ? V_263 : V_271 ;
break;
case V_271 :
V_259 = V_272 ;
break;
case V_272 :
break;
case V_261 :
case V_263 :
V_119 = - V_117 ;
break;
default:
F_145 () ;
}
return V_119 ;
}
static int T_6 F_146 ( enum V_273 V_274 )
{
int V_119 = 0 ;
while ( V_259 != V_274 ) {
V_119 = F_143 () ;
if ( V_259 == V_261 ||
V_259 == V_263 )
break;
}
return V_119 ;
}
int T_6 F_147 ( void )
{
return F_146 ( V_264 ) ;
}
int T_6 F_148 ( void )
{
return V_216 ? 1 : 0 ;
}
int T_6 F_149 ( void )
{
int V_119 ;
V_119 = F_146 ( V_268 ) ;
if ( V_119 )
return V_119 ;
V_194 = 1 ;
return 0 ;
}
void F_150 ( void )
{
F_120 () ;
}
int F_151 ( int V_275 )
{
F_118 () ;
return 0 ;
}
int T_6 F_152 ( void )
{
return 0 ;
}
static int T_6 F_153 ( void )
{
int V_119 ;
V_119 = F_146 ( V_272 ) ;
if ( V_119 ) {
F_128 () ;
if ( ! V_194 ) {
F_117 () ;
F_121 () ;
} else {
struct V_6 * V_7 ;
F_109 () ;
F_91 (iommu)
F_114 ( V_7 ) ;
}
}
return V_119 ;
}
int T_6 F_154 ( void )
{
int V_119 ;
if ( V_276 || ( V_277 && ! V_278 ) )
return - V_57 ;
if ( V_279 )
return - V_57 ;
V_119 = F_146 ( V_262 ) ;
if ( V_119 )
return V_119 ;
V_247 = true ;
V_277 = 1 ;
V_280 . V_7 . V_281 = F_153 ;
return 0 ;
}
static int T_6 F_155 ( char * V_282 )
{
V_283 = true ;
return 1 ;
}
static int T_6 F_156 ( char * V_282 )
{
for (; * V_282 ; ++ V_282 ) {
if ( strncmp ( V_282 , L_58 , 9 ) == 0 )
V_284 = true ;
if ( strncmp ( V_282 , L_59 , 3 ) == 0 )
V_279 = true ;
if ( strncmp ( V_282 , L_60 , 15 ) == 0 )
V_285 = true ;
}
return 1 ;
}
static int T_6 F_157 ( char * V_282 )
{
unsigned int V_38 , V_11 , V_39 ;
int V_119 , V_108 , V_55 ;
T_1 V_1 ;
V_119 = sscanf ( V_282 , L_61 , & V_108 , & V_38 , & V_11 , & V_39 ) ;
if ( V_119 != 4 ) {
F_24 ( L_62 , V_282 ) ;
return 1 ;
}
if ( V_120 == V_286 ) {
F_24 ( L_63 ,
V_282 ) ;
return 1 ;
}
V_1 = ( ( V_38 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_39 & 0x7 ) ;
V_239 = true ;
V_55 = V_120 ++ ;
V_121 [ V_55 ] . V_108 = V_108 ;
V_121 [ V_55 ] . V_1 = V_1 ;
V_121 [ V_55 ] . V_109 = true ;
return 1 ;
}
static int T_6 F_158 ( char * V_282 )
{
unsigned int V_38 , V_11 , V_39 ;
int V_119 , V_108 , V_55 ;
T_1 V_1 ;
V_119 = sscanf ( V_282 , L_61 , & V_108 , & V_38 , & V_11 , & V_39 ) ;
if ( V_119 != 4 ) {
F_24 ( L_64 , V_282 ) ;
return 1 ;
}
if ( V_122 == V_286 ) {
F_24 ( L_65 ,
V_282 ) ;
return 1 ;
}
V_1 = ( ( V_38 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_39 & 0x7 ) ;
V_239 = true ;
V_55 = V_122 ++ ;
V_123 [ V_55 ] . V_108 = V_108 ;
V_123 [ V_55 ] . V_1 = V_1 ;
V_123 [ V_55 ] . V_109 = true ;
return 1 ;
}
bool F_159 ( void )
{
return V_182 ;
}
