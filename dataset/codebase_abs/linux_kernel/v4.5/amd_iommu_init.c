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
static int T_6 F_30 ( struct V_39 * V_40 )
{
T_3 * V_41 = ( void * ) V_40 , * V_35 = ( void * ) V_40 ;
struct V_42 * V_11 ;
V_41 += sizeof( * V_40 ) ;
V_35 += V_40 -> V_43 ;
while ( V_41 < V_35 ) {
V_11 = (struct V_42 * ) V_41 ;
switch ( V_11 -> type ) {
case V_44 :
F_1 ( 0xffff ) ;
break;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
F_1 ( V_11 -> V_1 ) ;
break;
default:
break;
}
V_41 += F_29 ( V_41 ) ;
}
F_31 ( V_41 != V_35 ) ;
return 0 ;
}
static int T_6 F_32 ( struct V_49 * V_50 )
{
int V_51 ;
T_3 V_52 = 0 , * V_41 = ( T_3 * ) V_50 , * V_35 = ( T_3 * ) V_50 ;
struct V_39 * V_40 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_43 ; ++ V_51 )
V_52 += V_41 [ V_51 ] ;
if ( V_52 != 0 )
return - V_53 ;
V_41 += V_54 ;
V_35 += V_50 -> V_43 ;
while ( V_41 < V_35 ) {
V_40 = (struct V_39 * ) V_41 ;
switch ( V_40 -> type ) {
case V_55 :
F_30 ( V_40 ) ;
break;
default:
break;
}
V_41 += V_40 -> V_43 ;
}
F_31 ( V_41 != V_35 ) ;
return 0 ;
}
static int T_6 F_33 ( struct V_6 * V_7 )
{
V_7 -> V_56 = ( void * ) F_34 ( V_57 | V_58 ,
F_3 ( V_59 ) ) ;
return V_7 -> V_56 ? 0 : - V_60 ;
}
void F_35 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_32 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_61 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_62 ) ;
F_15 ( V_7 , V_32 ) ;
}
static void F_36 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_56 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_56 ) ;
V_17 |= V_63 ;
F_11 ( V_7 -> V_19 + V_64 ,
& V_17 , sizeof( V_17 ) ) ;
F_35 ( V_7 ) ;
}
static void T_6 F_37 ( struct V_6 * V_7 )
{
F_38 ( ( unsigned long ) V_7 -> V_56 , F_3 ( V_59 ) ) ;
}
static int T_6 F_39 ( struct V_6 * V_7 )
{
V_7 -> V_65 = ( void * ) F_34 ( V_57 | V_58 ,
F_3 ( V_66 ) ) ;
return V_7 -> V_65 ? 0 : - V_60 ;
}
static void F_40 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_65 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_65 ) | V_67 ;
F_11 ( V_7 -> V_19 + V_68 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_69 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_70 ) ;
F_15 ( V_7 , V_34 ) ;
}
static void T_6 F_41 ( struct V_6 * V_7 )
{
F_38 ( ( unsigned long ) V_7 -> V_65 , F_3 ( V_66 ) ) ;
}
static int T_6 F_42 ( struct V_6 * V_7 )
{
V_7 -> V_71 = ( void * ) F_34 ( V_57 | V_58 ,
F_3 ( V_72 ) ) ;
return V_7 -> V_71 ? 0 : - V_60 ;
}
static void F_43 ( struct V_6 * V_7 )
{
T_4 V_17 ;
if ( V_7 -> V_71 == NULL )
return;
V_17 = ( T_4 ) F_14 ( V_7 -> V_71 ) | V_73 ;
F_11 ( V_7 -> V_19 + V_74 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_75 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_76 ) ;
F_15 ( V_7 , V_77 ) ;
F_15 ( V_7 , V_78 ) ;
}
static void T_6 F_44 ( struct V_6 * V_7 )
{
if ( V_7 -> V_71 == NULL )
return;
F_38 ( ( unsigned long ) V_7 -> V_71 , F_3 ( V_72 ) ) ;
}
static void F_45 ( struct V_6 * V_7 )
{
if ( ! F_46 ( V_7 , V_79 ) )
return;
F_15 ( V_7 , V_80 ) ;
}
static void F_47 ( T_1 V_1 , T_3 V_25 )
{
int V_51 = ( V_25 >> 6 ) & 0x03 ;
int V_81 = V_25 & 0x3f ;
V_22 [ V_1 ] . V_82 [ V_51 ] |= ( 1UL << V_81 ) ;
}
static int F_48 ( T_1 V_1 , T_3 V_25 )
{
int V_51 = ( V_25 >> 6 ) & 0x03 ;
int V_81 = V_25 & 0x3f ;
return ( V_22 [ V_1 ] . V_82 [ V_51 ] & ( 1UL << V_81 ) ) >> V_81 ;
}
void F_49 ( T_1 V_1 )
{
int V_83 ;
V_83 = F_48 ( V_1 , V_84 ) |
( F_48 ( V_1 , V_85 ) << 1 ) ;
if ( V_83 == 0x01 )
F_47 ( V_1 , V_86 ) ;
}
static void T_6 F_50 ( struct V_6 * V_7 , T_1 V_1 )
{
V_87 [ V_1 ] = V_7 ;
}
static void T_6 F_51 ( struct V_6 * V_7 ,
T_1 V_1 , T_2 V_88 , T_2 V_89 )
{
if ( V_88 & V_90 )
F_47 ( V_1 , V_91 ) ;
if ( V_88 & V_92 )
F_47 ( V_1 , V_93 ) ;
if ( V_88 & V_94 )
F_47 ( V_1 , V_95 ) ;
if ( V_88 & V_96 )
F_47 ( V_1 , V_84 ) ;
if ( V_88 & V_97 )
F_47 ( V_1 , V_85 ) ;
if ( V_88 & V_98 )
F_47 ( V_1 , V_99 ) ;
if ( V_88 & V_100 )
F_47 ( V_1 , V_101 ) ;
F_49 ( V_1 ) ;
F_50 ( V_7 , V_1 ) ;
}
static int T_6 F_52 ( T_3 type , T_3 V_102 , T_1 * V_1 , bool V_103 )
{
struct V_104 * V_17 ;
struct V_105 * V_106 ;
if ( type == V_107 )
V_106 = & V_108 ;
else if ( type == V_109 )
V_106 = & V_110 ;
else
return - V_111 ;
F_53 (entry, list, list) {
if ( ! ( V_17 -> V_102 == V_102 && V_17 -> V_103 ) )
continue;
F_54 ( L_4 ,
type == V_107 ? L_5 : L_6 , V_102 ) ;
* V_1 = V_17 -> V_1 ;
return 0 ;
}
V_17 = F_55 ( sizeof( * V_17 ) , V_57 ) ;
if ( ! V_17 )
return - V_60 ;
V_17 -> V_102 = V_102 ;
V_17 -> V_1 = * V_1 ;
V_17 -> V_103 = V_103 ;
F_56 ( & V_17 -> V_106 , V_106 ) ;
return 0 ;
}
static int T_6 F_57 ( void )
{
int V_51 , V_112 ;
for ( V_51 = 0 ; V_51 < V_113 ; ++ V_51 ) {
V_112 = F_52 ( V_107 ,
V_114 [ V_51 ] . V_102 ,
& V_114 [ V_51 ] . V_1 ,
V_114 [ V_51 ] . V_103 ) ;
if ( V_112 )
return V_112 ;
}
for ( V_51 = 0 ; V_51 < V_115 ; ++ V_51 ) {
V_112 = F_52 ( V_109 ,
V_116 [ V_51 ] . V_102 ,
& V_116 [ V_51 ] . V_1 ,
V_116 [ V_51 ] . V_103 ) ;
if ( V_112 )
return V_112 ;
}
return 0 ;
}
static void T_6 F_58 ( T_1 V_1 , struct V_117 * V_118 )
{
struct V_6 * V_7 = V_87 [ V_1 ] ;
if ( ! ( V_118 -> V_88 & V_119 ) )
return;
if ( V_7 ) {
F_47 ( V_1 , V_120 ) ;
V_7 -> V_13 = V_118 -> V_121 ;
V_7 -> V_16 = V_118 -> V_122 ;
}
}
static int T_6 F_59 ( struct V_6 * V_7 ,
struct V_39 * V_40 )
{
T_3 * V_41 = ( T_3 * ) V_40 ;
T_3 * V_35 = V_41 , V_88 = 0 ;
T_1 V_1 = 0 , V_123 = 0 , V_124 = 0 ;
T_2 V_125 , V_89 = 0 ;
bool V_126 = false ;
struct V_42 * V_127 ;
int V_112 ;
V_112 = F_57 () ;
if ( V_112 )
return V_112 ;
V_7 -> V_128 = V_40 -> V_88 ;
V_41 += sizeof( struct V_39 ) ;
V_35 += V_40 -> V_43 ;
while ( V_41 < V_35 ) {
V_127 = (struct V_42 * ) V_41 ;
switch ( V_127 -> type ) {
case V_44 :
F_60 ( L_7 , V_127 -> V_88 ) ;
for ( V_125 = 0 ; V_125 <= V_2 ; ++ V_125 )
F_51 ( V_7 , V_125 , V_127 -> V_88 , 0 ) ;
break;
case V_45 :
F_60 ( L_8
L_9 ,
F_61 ( V_127 -> V_1 ) ,
F_62 ( V_127 -> V_1 ) ,
F_63 ( V_127 -> V_1 ) ,
V_127 -> V_88 ) ;
V_1 = V_127 -> V_1 ;
F_51 ( V_7 , V_1 , V_127 -> V_88 , 0 ) ;
break;
case V_129 :
F_60 ( L_10
L_11 ,
F_61 ( V_127 -> V_1 ) ,
F_62 ( V_127 -> V_1 ) ,
F_63 ( V_127 -> V_1 ) ,
V_127 -> V_88 ) ;
V_123 = V_127 -> V_1 ;
V_88 = V_127 -> V_88 ;
V_89 = 0 ;
V_126 = false ;
break;
case V_47 :
F_60 ( L_12
L_13 ,
F_61 ( V_127 -> V_1 ) ,
F_62 ( V_127 -> V_1 ) ,
F_63 ( V_127 -> V_1 ) ,
V_127 -> V_88 ,
F_61 ( V_127 -> V_130 >> 8 ) ,
F_62 ( V_127 -> V_130 >> 8 ) ,
F_63 ( V_127 -> V_130 >> 8 ) ) ;
V_1 = V_127 -> V_1 ;
V_124 = V_127 -> V_130 >> 8 ;
F_51 ( V_7 , V_1 , V_127 -> V_88 , 0 ) ;
F_51 ( V_7 , V_124 , V_127 -> V_88 , 0 ) ;
V_131 [ V_1 ] = V_124 ;
break;
case V_132 :
F_60 ( L_14
L_15
L_16 ,
F_61 ( V_127 -> V_1 ) ,
F_62 ( V_127 -> V_1 ) ,
F_63 ( V_127 -> V_1 ) ,
V_127 -> V_88 ,
F_61 ( V_127 -> V_130 >> 8 ) ,
F_62 ( V_127 -> V_130 >> 8 ) ,
F_63 ( V_127 -> V_130 >> 8 ) ) ;
V_123 = V_127 -> V_1 ;
V_88 = V_127 -> V_88 ;
V_124 = V_127 -> V_130 >> 8 ;
V_89 = 0 ;
V_126 = true ;
break;
case V_48 :
F_60 ( L_17
L_18 ,
F_61 ( V_127 -> V_1 ) ,
F_62 ( V_127 -> V_1 ) ,
F_63 ( V_127 -> V_1 ) ,
V_127 -> V_88 , V_127 -> V_130 ) ;
V_1 = V_127 -> V_1 ;
F_51 ( V_7 , V_1 , V_127 -> V_88 ,
V_127 -> V_130 ) ;
break;
case V_133 :
F_60 ( L_19
L_20 ,
F_61 ( V_127 -> V_1 ) ,
F_62 ( V_127 -> V_1 ) ,
F_63 ( V_127 -> V_1 ) ,
V_127 -> V_88 , V_127 -> V_130 ) ;
V_123 = V_127 -> V_1 ;
V_88 = V_127 -> V_88 ;
V_89 = V_127 -> V_130 ;
V_126 = false ;
break;
case V_46 :
F_60 ( L_21 ,
F_61 ( V_127 -> V_1 ) ,
F_62 ( V_127 -> V_1 ) ,
F_63 ( V_127 -> V_1 ) ) ;
V_1 = V_127 -> V_1 ;
for ( V_125 = V_123 ; V_125 <= V_1 ; ++ V_125 ) {
if ( V_126 ) {
V_131 [ V_125 ] = V_124 ;
F_51 ( V_7 ,
V_124 , V_88 , V_89 ) ;
}
F_51 ( V_7 , V_125 ,
V_88 , V_89 ) ;
}
break;
case V_134 : {
T_3 V_135 , type ;
const char * V_136 ;
T_1 V_1 ;
int V_112 ;
V_135 = V_127 -> V_130 & 0xff ;
V_1 = ( V_127 -> V_130 >> 8 ) & 0xffff ;
type = ( V_127 -> V_130 >> 24 ) & 0xff ;
if ( type == V_107 )
V_136 = L_5 ;
else if ( type == V_109 )
V_136 = L_6 ;
else
V_136 = L_22 ;
F_60 ( L_23 ,
V_136 , ( int ) V_135 ,
F_61 ( V_1 ) ,
F_62 ( V_1 ) ,
F_63 ( V_1 ) ) ;
V_112 = F_52 ( type , V_135 , & V_1 , false ) ;
if ( V_112 )
return V_112 ;
F_51 ( V_7 , V_1 , V_127 -> V_88 , 0 ) ;
break;
}
default:
break;
}
V_41 += F_29 ( V_41 ) ;
}
return 0 ;
}
static void T_6 F_64 ( struct V_6 * V_7 )
{
F_37 ( V_7 ) ;
F_41 ( V_7 ) ;
F_44 ( V_7 ) ;
F_26 ( V_7 ) ;
}
static void T_6 F_65 ( void )
{
struct V_6 * V_7 , * V_137 ;
F_66 (iommu, next) {
F_67 ( & V_7 -> V_106 ) ;
F_64 ( V_7 ) ;
F_68 ( V_7 ) ;
}
}
static void F_69 ( struct V_6 * V_7 )
{
T_2 V_138 ;
if ( ( V_139 . V_140 != 0x15 ) ||
( V_139 . V_141 < 0x10 ) ||
( V_139 . V_141 > 0x1f ) )
return;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 ) ;
F_6 ( V_7 -> V_11 , 0xf4 , & V_138 ) ;
if ( V_138 & F_70 ( 2 ) )
return;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 | ( 1 << 8 ) ) ;
F_5 ( V_7 -> V_11 , 0xf4 , V_138 | 0x4 ) ;
F_54 ( L_24 ,
F_71 ( & V_7 -> V_11 -> V_11 ) ) ;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 ) ;
}
static void F_72 ( struct V_6 * V_7 )
{
T_2 V_138 ;
if ( ( V_139 . V_140 != 0x15 ) ||
( V_139 . V_141 < 0x30 ) ||
( V_139 . V_141 > 0x3f ) )
return;
V_138 = F_8 ( V_7 , 0x47 ) ;
if ( V_138 & F_70 ( 0 ) )
return;
F_9 ( V_7 , 0x47 , V_138 | F_70 ( 0 ) ) ;
F_54 ( L_25 ,
F_71 ( & V_7 -> V_11 -> V_11 ) ) ;
}
static int T_6 F_73 ( struct V_6 * V_7 , struct V_39 * V_40 )
{
int V_112 ;
F_74 ( & V_7 -> V_142 ) ;
F_56 ( & V_7 -> V_106 , & V_143 ) ;
V_7 -> V_144 = V_145 ++ ;
if ( F_75 ( V_7 -> V_144 >= V_146 ) ) {
F_76 ( 1 , L_26 ) ;
return - V_147 ;
}
V_148 [ V_7 -> V_144 ] = V_7 ;
V_7 -> V_1 = V_40 -> V_1 ;
V_7 -> V_149 = V_40 -> V_149 ;
V_7 -> V_150 = V_40 -> V_150 ;
V_7 -> V_36 = V_40 -> V_36 ;
if ( ( V_40 -> V_151 != 0 ) &&
( ( V_40 -> V_151 & ( 0xF << 13 ) ) != 0 ) &&
( ( V_40 -> V_151 & ( 0x3F << 17 ) ) != 0 ) ) {
V_7 -> V_37 = V_152 ;
} else {
V_7 -> V_37 = V_153 ;
}
V_7 -> V_19 = F_22 ( V_7 -> V_36 ,
V_7 -> V_37 ) ;
if ( ! V_7 -> V_19 )
return - V_60 ;
if ( F_33 ( V_7 ) )
return - V_60 ;
if ( F_39 ( V_7 ) )
return - V_60 ;
V_7 -> V_154 = false ;
V_112 = F_59 ( V_7 , V_40 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_77 ( V_7 ) ;
if ( V_112 )
return V_112 ;
V_87 [ V_7 -> V_1 ] = NULL ;
return 0 ;
}
static int T_6 F_78 ( struct V_49 * V_50 )
{
T_3 * V_41 = ( T_3 * ) V_50 , * V_35 = ( T_3 * ) V_50 ;
struct V_39 * V_40 ;
struct V_6 * V_7 ;
int V_112 ;
V_35 += V_50 -> V_43 ;
V_41 += V_54 ;
while ( V_41 < V_35 ) {
V_40 = (struct V_39 * ) V_41 ;
switch ( * V_41 ) {
case V_55 :
F_60 ( L_27
L_28 ,
F_61 ( V_40 -> V_1 ) , F_62 ( V_40 -> V_1 ) ,
F_63 ( V_40 -> V_1 ) , V_40 -> V_149 ,
V_40 -> V_150 , V_40 -> V_88 , V_40 -> V_155 ) ;
F_60 ( L_29 ,
V_40 -> V_36 ) ;
V_7 = F_55 ( sizeof( struct V_6 ) , V_57 ) ;
if ( V_7 == NULL )
return - V_60 ;
V_112 = F_73 ( V_7 , V_40 ) ;
if ( V_112 )
return V_112 ;
break;
default:
break;
}
V_41 += V_40 -> V_43 ;
}
F_31 ( V_41 != V_35 ) ;
return 0 ;
}
static void F_79 ( struct V_6 * V_7 )
{
T_4 V_10 = 0xabcd , V_156 = 0 ;
if ( ! F_46 ( V_7 , V_157 ) )
return;
V_158 = true ;
if ( ( 0 != F_80 ( V_7 , 0 , 0 , 0 , & V_10 , true ) ) ||
( 0 != F_80 ( V_7 , 0 , 0 , 0 , & V_156 , false ) ) ||
( V_10 != V_156 ) ) {
F_24 ( L_30 ) ;
V_158 = false ;
return;
}
F_54 ( L_31 ) ;
V_10 = F_16 ( V_7 -> V_19 + V_153 ) ;
V_7 -> V_159 = ( T_3 ) ( ( V_10 >> 12 ) & 0x3f ) ;
V_7 -> V_160 = ( T_3 ) ( ( V_10 >> 7 ) & 0xf ) ;
}
static T_7 F_81 ( struct V_161 * V_11 ,
struct V_162 * V_163 ,
char * V_164 )
{
struct V_6 * V_7 = F_82 ( V_11 ) ;
return sprintf ( V_164 , L_32 , V_7 -> V_165 ) ;
}
static T_7 F_83 ( struct V_161 * V_11 ,
struct V_162 * V_163 ,
char * V_164 )
{
struct V_6 * V_7 = F_82 ( V_11 ) ;
return sprintf ( V_164 , L_33 , V_7 -> V_166 ) ;
}
static int F_84 ( struct V_6 * V_7 )
{
int V_149 = V_7 -> V_149 ;
T_2 V_167 , V_168 , V_169 , V_170 ;
V_7 -> V_11 = F_85 ( F_61 ( V_7 -> V_1 ) ,
V_7 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return - V_53 ;
V_7 -> V_11 -> V_171 = false ;
F_6 ( V_7 -> V_11 , V_149 + V_172 ,
& V_7 -> V_165 ) ;
F_6 ( V_7 -> V_11 , V_149 + V_173 ,
& V_167 ) ;
F_6 ( V_7 -> V_11 , V_149 + V_174 ,
& V_168 ) ;
if ( ! ( V_7 -> V_165 & ( 1 << V_175 ) ) )
V_176 = false ;
V_169 = F_16 ( V_7 -> V_19 + V_177 ) ;
V_170 = F_16 ( V_7 -> V_19 + V_177 + 4 ) ;
V_7 -> V_166 = ( ( T_4 ) V_170 << 32 ) | V_169 ;
if ( F_46 ( V_7 , V_79 ) ) {
int V_178 ;
T_2 V_179 ;
T_4 V_180 ;
V_180 = V_7 -> V_166 & V_181 ;
V_180 >>= V_182 ;
V_179 = ( 1 << ( V_180 + 1 ) ) - 1 ;
V_183 = F_86 ( V_183 , V_179 ) ;
F_13 ( V_183 & ~ V_184 ) ;
V_178 = V_7 -> V_166 & V_185 ;
V_178 >>= V_186 ;
if ( V_187 == - 1 )
V_187 = V_178 ;
else
V_187 = F_86 ( V_187 , V_178 ) ;
}
if ( F_46 ( V_7 , V_79 ) &&
F_46 ( V_7 , V_188 ) ) {
V_7 -> V_189 = true ;
V_190 = true ;
}
if ( F_46 ( V_7 , V_188 ) && F_42 ( V_7 ) )
return - V_60 ;
if ( V_7 -> V_165 & ( 1UL << V_191 ) )
V_192 = true ;
F_79 ( V_7 ) ;
if ( F_87 ( V_7 -> V_11 ) ) {
int V_51 , V_193 ;
V_7 -> V_194 = F_85 ( V_7 -> V_11 -> V_195 -> V_196 ,
F_88 ( 0 , 0 ) ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_149 + 4 ,
& V_7 -> V_197 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_149 + 8 ,
& V_7 -> V_198 ) ;
V_7 -> V_197 &= ~ 1 ;
for ( V_51 = 0 ; V_51 < 6 ; V_51 ++ )
for ( V_193 = 0 ; V_193 < 0x12 ; V_193 ++ )
V_7 -> V_199 [ V_51 ] [ V_193 ] = F_4 ( V_7 , V_51 , V_193 ) ;
for ( V_51 = 0 ; V_51 < 0x83 ; V_51 ++ )
V_7 -> V_200 [ V_51 ] = F_8 ( V_7 , V_51 ) ;
}
F_69 ( V_7 ) ;
F_72 ( V_7 ) ;
V_7 -> V_201 = F_89 ( & V_7 -> V_11 -> V_11 , V_7 ,
V_202 , L_34 ,
V_7 -> V_144 ) ;
return F_90 ( V_7 -> V_11 ) ;
}
static void F_91 ( void )
{
static const char * const V_203 [] = {
L_35 , L_36 , L_37 , L_38 , L_39 , L_40 ,
L_41 , L_42 , L_43 , L_44
} ;
struct V_6 * V_7 ;
F_92 (iommu) {
int V_51 ;
F_54 ( L_45 ,
F_71 ( & V_7 -> V_11 -> V_11 ) , V_7 -> V_149 ) ;
if ( V_7 -> V_165 & ( 1 << V_204 ) ) {
F_54 ( L_46 ) ;
for ( V_51 = 0 ; V_51 < F_93 ( V_203 ) ; ++ V_51 ) {
if ( F_46 ( V_7 , ( 1ULL << V_51 ) ) )
F_94 ( L_47 , V_203 [ V_51 ] ) ;
}
F_94 ( L_48 ) ;
}
}
if ( V_205 )
F_54 ( L_49 ) ;
}
static int T_6 F_95 ( void )
{
struct V_6 * V_7 ;
int V_112 = 0 ;
F_92 (iommu) {
V_112 = F_84 ( V_7 ) ;
if ( V_112 )
break;
}
F_96 () ;
F_92 (iommu)
F_97 ( V_7 ) ;
V_112 = F_98 () ;
if ( ! V_112 )
F_91 () ;
return V_112 ;
}
static int F_99 ( struct V_6 * V_7 )
{
int V_206 ;
V_206 = F_100 ( V_7 -> V_11 ) ;
if ( V_206 )
return V_206 ;
V_206 = F_101 ( V_7 -> V_11 -> V_207 ,
V_208 ,
V_209 ,
0 , L_50 ,
V_7 ) ;
if ( V_206 ) {
F_102 ( V_7 -> V_11 ) ;
return V_206 ;
}
V_7 -> V_154 = true ;
return 0 ;
}
static int F_103 ( struct V_6 * V_7 )
{
int V_112 ;
if ( V_7 -> V_154 )
goto V_210;
if ( V_7 -> V_11 -> V_211 )
V_112 = F_99 ( V_7 ) ;
else
V_112 = - V_53 ;
if ( V_112 )
return V_112 ;
V_210:
F_15 ( V_7 , V_33 ) ;
if ( V_7 -> V_71 != NULL )
F_15 ( V_7 , V_212 ) ;
return 0 ;
}
static void T_6 F_104 ( void )
{
struct V_213 * V_17 , * V_137 ;
F_105 (entry, next, &amd_iommu_unity_map, list) {
F_67 ( & V_17 -> V_106 ) ;
F_68 ( V_17 ) ;
}
}
static int T_6 F_106 ( struct V_117 * V_118 )
{
int V_51 ;
switch ( V_118 -> type ) {
case V_214 :
F_58 ( V_118 -> V_1 , V_118 ) ;
break;
case V_215 :
for ( V_51 = 0 ; V_51 <= V_2 ; ++ V_51 )
F_58 ( V_51 , V_118 ) ;
break;
case V_216 :
for ( V_51 = V_118 -> V_1 ; V_51 <= V_118 -> V_217 ; ++ V_51 )
F_58 ( V_51 , V_118 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_107 ( struct V_117 * V_118 )
{
struct V_213 * V_127 = NULL ;
char * V_218 ;
V_127 = F_55 ( sizeof( * V_127 ) , V_57 ) ;
if ( V_127 == NULL )
return - V_60 ;
switch ( V_118 -> type ) {
default:
F_68 ( V_127 ) ;
return 0 ;
case V_214 :
V_218 = L_51 ;
V_127 -> V_123 = V_127 -> V_219 = V_118 -> V_1 ;
break;
case V_215 :
V_218 = L_52 ;
V_127 -> V_123 = 0 ;
V_127 -> V_219 = V_2 ;
break;
case V_216 :
V_218 = L_53 ;
V_127 -> V_123 = V_118 -> V_1 ;
V_127 -> V_219 = V_118 -> V_217 ;
break;
}
V_127 -> V_220 = F_108 ( V_118 -> V_121 ) ;
V_127 -> V_221 = V_127 -> V_220 + F_108 ( V_118 -> V_122 ) ;
V_127 -> V_222 = V_118 -> V_88 >> 1 ;
F_60 ( L_54
L_55 , V_218 ,
F_61 ( V_127 -> V_123 ) , F_62 ( V_127 -> V_123 ) ,
F_63 ( V_127 -> V_123 ) , F_61 ( V_127 -> V_219 ) ,
F_62 ( V_127 -> V_219 ) , F_63 ( V_127 -> V_219 ) ,
V_127 -> V_220 , V_127 -> V_221 , V_118 -> V_88 ) ;
F_56 ( & V_127 -> V_106 , & V_223 ) ;
return 0 ;
}
static int T_6 F_109 ( struct V_49 * V_50 )
{
T_3 * V_41 = ( T_3 * ) V_50 , * V_35 = ( T_3 * ) V_50 ;
struct V_117 * V_118 ;
V_35 += V_50 -> V_43 ;
V_41 += V_54 ;
while ( V_41 < V_35 ) {
V_118 = (struct V_117 * ) V_41 ;
if ( V_118 -> V_88 & V_119 )
F_106 ( V_118 ) ;
else if ( V_118 -> V_88 & V_224 )
F_107 ( V_118 ) ;
V_41 += V_118 -> V_43 ;
}
return 0 ;
}
static void F_96 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_47 ( V_1 , V_225 ) ;
F_47 ( V_1 , V_226 ) ;
}
}
static void T_6 F_110 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
V_22 [ V_1 ] . V_82 [ 0 ] = 0ULL ;
V_22 [ V_1 ] . V_82 [ 1 ] = 0ULL ;
}
}
static void F_111 ( void )
{
T_2 V_1 ;
if ( ! V_227 )
return;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 )
F_47 ( V_1 , V_228 ) ;
}
static void F_112 ( struct V_6 * V_7 )
{
V_7 -> V_128 & V_229 ?
F_15 ( V_7 , V_230 ) :
F_18 ( V_7 , V_230 ) ;
V_7 -> V_128 & V_231 ?
F_15 ( V_7 , V_232 ) :
F_18 ( V_7 , V_232 ) ;
V_7 -> V_128 & V_233 ?
F_15 ( V_7 , V_234 ) :
F_18 ( V_7 , V_234 ) ;
V_7 -> V_128 & V_235 ?
F_15 ( V_7 , V_236 ) :
F_18 ( V_7 , V_236 ) ;
F_15 ( V_7 , V_237 ) ;
F_19 ( V_7 , V_238 ) ;
}
static void F_113 ( struct V_6 * V_7 )
{
int V_51 , V_193 ;
T_2 V_239 ;
struct V_240 * V_241 = V_7 -> V_194 ;
if ( ! F_87 ( V_7 -> V_11 ) || ! V_241 )
return;
F_5 ( V_241 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_241 , 0x64 , & V_239 ) ;
if ( ! ( V_239 & 0x1 ) )
F_5 ( V_241 , 0x64 , V_239 | 1 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_149 + 4 ,
V_7 -> V_197 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_149 + 8 ,
V_7 -> V_198 ) ;
for ( V_51 = 0 ; V_51 < 6 ; V_51 ++ )
for ( V_193 = 0 ; V_193 < 0x12 ; V_193 ++ )
F_7 ( V_7 , V_51 , V_193 , V_7 -> V_199 [ V_51 ] [ V_193 ] ) ;
for ( V_51 = 0 ; V_51 < 0x83 ; V_51 ++ )
F_9 ( V_7 , V_51 , V_7 -> V_200 [ V_51 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_149 + 4 ,
V_7 -> V_197 | 1 ) ;
}
static void F_114 ( void )
{
struct V_6 * V_7 ;
F_92 (iommu) {
F_21 ( V_7 ) ;
F_112 ( V_7 ) ;
F_12 ( V_7 ) ;
F_36 ( V_7 ) ;
F_40 ( V_7 ) ;
F_10 ( V_7 ) ;
F_20 ( V_7 ) ;
F_97 ( V_7 ) ;
}
}
static void F_115 ( void )
{
struct V_6 * V_7 ;
F_92 (iommu) {
F_43 ( V_7 ) ;
F_45 ( V_7 ) ;
}
}
static void F_116 ( void )
{
F_114 () ;
F_115 () ;
}
static void F_117 ( void )
{
struct V_6 * V_7 ;
F_92 (iommu)
F_21 ( V_7 ) ;
}
static void F_118 ( void )
{
struct V_6 * V_7 ;
F_92 (iommu)
F_113 ( V_7 ) ;
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
F_38 ( ( unsigned long ) V_242 ,
F_3 ( V_243 ) ) ;
F_122 ( V_244 ) ;
V_244 = NULL ;
F_38 ( ( unsigned long ) V_87 ,
F_3 ( V_243 ) ) ;
F_38 ( ( unsigned long ) V_131 ,
F_3 ( V_245 ) ) ;
F_38 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_65 () ;
#ifdef F_123
F_124 () ;
#endif
}
static bool T_6 F_125 ( void )
{
const char * V_246 = V_247 ;
bool V_112 , V_248 ;
int V_249 ;
V_248 = false ;
V_112 = false ;
if ( V_250 )
V_246 = L_56 ;
for ( V_249 = 0 ; V_249 < V_251 ; V_249 ++ ) {
int V_1 , V_102 = F_126 ( V_249 ) ;
V_1 = F_127 ( V_102 ) ;
if ( V_1 < 0 ) {
F_24 ( L_57 ,
V_246 , V_102 ) ;
V_112 = false ;
} else if ( V_1 == V_252 ) {
V_248 = true ;
V_112 = true ;
}
}
if ( ! V_248 ) {
F_24 ( L_58 , V_246 ) ;
}
if ( ! V_112 )
F_24 ( L_59 ) ;
return V_112 ;
}
static void T_6 F_128 ( void )
{
F_38 ( ( unsigned long ) V_253 ,
F_3 ( V_254 / 8 ) ) ;
F_104 () ;
}
static int T_6 F_129 ( void )
{
struct V_49 * V_255 ;
T_8 V_256 ;
T_9 V_257 ;
int V_51 , V_112 = 0 ;
if ( ! V_258 )
return - V_53 ;
V_257 = F_130 ( L_60 , 0 , & V_255 , & V_256 ) ;
if ( V_257 == V_259 )
return - V_53 ;
else if ( F_131 ( V_257 ) ) {
const char * V_260 = F_132 ( V_257 ) ;
F_24 ( L_61 , V_260 ) ;
return - V_111 ;
}
V_112 = F_32 ( V_255 ) ;
if ( V_112 )
goto V_261;
V_23 = F_2 ( V_262 ) ;
V_245 = F_2 ( V_263 ) ;
V_243 = F_2 ( V_264 ) ;
V_112 = - V_60 ;
V_22 = ( void * ) F_34 ( V_57 | V_58 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_261;
V_131 = ( void * ) F_34 ( V_57 ,
F_3 ( V_245 ) ) ;
if ( V_131 == NULL )
goto V_261;
V_87 = ( void * ) F_34 (
V_57 | V_58 ,
F_3 ( V_243 ) ) ;
if ( V_87 == NULL )
goto V_261;
V_253 = ( void * ) F_34 (
V_57 | V_58 ,
F_3 ( V_254 / 8 ) ) ;
if ( V_253 == NULL )
goto V_261;
for ( V_51 = 0 ; V_51 <= V_2 ; ++ V_51 )
V_131 [ V_51 ] = V_51 ;
V_253 [ 0 ] = 1 ;
F_74 ( & V_265 ) ;
V_112 = F_78 ( V_255 ) ;
if ( V_112 )
goto V_261;
if ( V_227 )
V_227 = F_125 () ;
if ( V_227 ) {
V_112 = - V_60 ;
V_244 = F_133 ( L_62 ,
V_266 * sizeof( T_2 ) ,
V_267 ,
0 , NULL ) ;
if ( ! V_244 )
goto V_261;
V_242 = ( void * ) F_34 (
V_57 | V_58 ,
F_3 ( V_243 ) ) ;
if ( ! V_242 )
goto V_261;
}
V_112 = F_109 ( V_255 ) ;
if ( V_112 )
goto V_261;
F_111 () ;
V_261:
F_134 ( ( char T_5 * ) V_255 , V_256 ) ;
V_255 = NULL ;
return V_112 ;
}
static int F_119 ( void )
{
struct V_6 * V_7 ;
int V_112 = 0 ;
F_92 (iommu) {
V_112 = F_103 ( V_7 ) ;
if ( V_112 )
goto V_261;
}
V_261:
return V_112 ;
}
static bool F_135 ( void )
{
struct V_49 * V_255 ;
T_8 V_256 ;
T_9 V_257 ;
V_257 = F_130 ( L_60 , 0 , & V_255 , & V_256 ) ;
if ( V_257 == V_259 )
return false ;
else if ( F_131 ( V_257 ) ) {
const char * V_260 = F_132 ( V_257 ) ;
F_24 ( L_61 , V_260 ) ;
return false ;
}
F_134 ( ( char T_5 * ) V_255 , V_256 ) ;
F_136 () ;
return true ;
}
static int T_6 F_137 ( void )
{
int V_112 = 0 ;
switch ( V_268 ) {
case V_269 :
if ( ! F_135 () ) {
V_268 = V_270 ;
V_112 = - V_53 ;
} else {
V_268 = V_271 ;
}
break;
case V_271 :
V_112 = F_129 () ;
V_268 = V_112 ? V_272 : V_273 ;
break;
case V_273 :
F_114 () ;
F_138 ( & V_274 ) ;
V_275 . V_276 = F_117 ;
V_268 = V_277 ;
break;
case V_277 :
V_112 = F_95 () ;
V_268 = V_112 ? V_272 : V_278 ;
F_115 () ;
break;
case V_278 :
V_112 = F_119 () ;
V_268 = V_112 ? V_272 : V_279 ;
break;
case V_279 :
V_112 = F_139 () ;
V_268 = V_112 ? V_272 : V_280 ;
break;
case V_280 :
V_268 = V_281 ;
break;
case V_281 :
break;
case V_270 :
case V_272 :
V_112 = - V_111 ;
break;
default:
F_140 () ;
}
return V_112 ;
}
static int T_6 F_141 ( enum V_282 V_283 )
{
int V_112 = 0 ;
while ( V_268 != V_283 ) {
V_112 = F_137 () ;
if ( V_268 == V_270 ||
V_268 == V_272 )
break;
}
return V_112 ;
}
int T_6 F_142 ( void )
{
int V_112 ;
V_227 = true ;
V_112 = F_141 ( V_273 ) ;
if ( V_112 )
return V_112 ;
return V_227 ? 0 : - V_53 ;
}
int T_6 F_143 ( void )
{
int V_112 ;
V_112 = F_141 ( V_277 ) ;
if ( V_112 )
return V_112 ;
V_205 = 1 ;
return 0 ;
}
void F_144 ( void )
{
F_120 () ;
}
int F_145 ( int V_284 )
{
F_118 () ;
return 0 ;
}
int T_6 F_146 ( void )
{
return 0 ;
}
static int T_6 F_147 ( void )
{
int V_112 ;
V_112 = F_141 ( V_281 ) ;
if ( V_112 ) {
F_128 () ;
if ( ! V_205 ) {
F_117 () ;
F_121 () ;
} else {
struct V_6 * V_7 ;
F_110 () ;
F_92 (iommu)
F_97 ( V_7 ) ;
}
}
return V_112 ;
}
int T_6 F_148 ( void )
{
int V_112 ;
if ( V_285 || ( V_286 && ! V_287 ) )
return - V_53 ;
if ( V_288 )
return - V_53 ;
V_112 = F_141 ( V_271 ) ;
if ( V_112 )
return V_112 ;
V_258 = true ;
V_286 = 1 ;
V_289 . V_7 . V_290 = F_147 ;
return 1 ;
}
static int T_6 F_149 ( char * V_291 )
{
V_292 = true ;
return 1 ;
}
static int T_6 F_150 ( char * V_291 )
{
for (; * V_291 ; ++ V_291 ) {
if ( strncmp ( V_291 , L_63 , 9 ) == 0 )
V_293 = true ;
if ( strncmp ( V_291 , L_64 , 3 ) == 0 )
V_288 = true ;
if ( strncmp ( V_291 , L_65 , 15 ) == 0 )
V_294 = true ;
}
return 1 ;
}
static int T_6 F_151 ( char * V_291 )
{
unsigned int V_195 , V_11 , V_295 ;
int V_112 , V_102 , V_51 ;
T_1 V_1 ;
V_112 = sscanf ( V_291 , L_66 , & V_102 , & V_195 , & V_11 , & V_295 ) ;
if ( V_112 != 4 ) {
F_24 ( L_67 , V_291 ) ;
return 1 ;
}
if ( V_113 == V_296 ) {
F_24 ( L_68 ,
V_291 ) ;
return 1 ;
}
V_1 = ( ( V_195 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_295 & 0x7 ) ;
V_250 = true ;
V_51 = V_113 ++ ;
V_114 [ V_51 ] . V_102 = V_102 ;
V_114 [ V_51 ] . V_1 = V_1 ;
V_114 [ V_51 ] . V_103 = true ;
return 1 ;
}
static int T_6 F_152 ( char * V_291 )
{
unsigned int V_195 , V_11 , V_295 ;
int V_112 , V_102 , V_51 ;
T_1 V_1 ;
V_112 = sscanf ( V_291 , L_66 , & V_102 , & V_195 , & V_11 , & V_295 ) ;
if ( V_112 != 4 ) {
F_24 ( L_69 , V_291 ) ;
return 1 ;
}
if ( V_115 == V_296 ) {
F_24 ( L_70 ,
V_291 ) ;
return 1 ;
}
V_1 = ( ( V_195 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_295 & 0x7 ) ;
V_250 = true ;
V_51 = V_115 ++ ;
V_116 [ V_51 ] . V_102 = V_102 ;
V_116 [ V_51 ] . V_1 = V_1 ;
V_116 [ V_51 ] . V_103 = true ;
return 1 ;
}
bool F_153 ( void )
{
return V_190 ;
}
T_3 F_154 ( T_1 V_1 )
{
struct V_6 * V_7 ;
T_3 V_112 = 0 ;
V_7 = V_87 [ V_1 ] ;
if ( V_7 )
V_112 = V_7 -> V_159 ;
return V_112 ;
}
bool F_155 ( void )
{
return V_158 ;
}
T_3 F_156 ( T_1 V_1 )
{
struct V_6 * V_7 ;
T_3 V_112 = 0 ;
V_7 = V_87 [ V_1 ] ;
if ( V_7 )
V_112 = V_7 -> V_160 ;
return V_112 ;
}
static int F_80 ( struct V_6 * V_7 ,
T_3 V_297 , T_3 V_298 , T_3 V_299 ,
T_4 * V_138 , bool V_300 )
{
T_2 V_301 ;
T_2 V_302 ;
if ( F_31 ( ( V_299 > 0x28 ) || ( V_299 & 7 ) ) )
return - V_53 ;
V_301 = ( T_2 ) ( ( ( 0x40 | V_297 ) << 12 ) | ( V_298 << 8 ) | V_299 ) ;
V_302 = ( T_2 ) ( ( ( 0x40 | V_7 -> V_159 ) << 12 ) |
( V_7 -> V_160 << 8 ) | 0x28 ) ;
if ( ( V_301 < V_303 ) ||
( V_301 > V_302 ) )
return - V_111 ;
if ( V_300 ) {
F_17 ( ( T_2 ) * V_138 , V_7 -> V_19 + V_301 ) ;
F_17 ( ( * V_138 >> 32 ) , V_7 -> V_19 + V_301 + 4 ) ;
} else {
* V_138 = F_16 ( V_7 -> V_19 + V_301 + 4 ) ;
* V_138 <<= 32 ;
* V_138 = F_16 ( V_7 -> V_19 + V_301 ) ;
}
return 0 ;
}
int F_157 ( T_1 V_1 , T_3 V_297 , T_3 V_298 , T_3 V_299 ,
T_4 * V_138 , bool V_300 )
{
struct V_6 * V_7 = V_87 [ V_1 ] ;
if ( ! V_158 || V_7 == NULL )
return - V_53 ;
return F_80 ( V_7 , V_297 , V_298 , V_299 ,
V_138 , V_300 ) ;
}
