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
static int T_6 F_72 ( struct V_6 * V_7 , struct V_43 * V_44 )
{
int V_141 ;
F_73 ( & V_7 -> V_143 ) ;
F_62 ( & V_7 -> V_111 , & V_144 ) ;
V_7 -> V_145 = V_146 ++ ;
if ( F_74 ( V_7 -> V_145 >= V_147 ) ) {
F_75 ( 1 , L_24 ) ;
return - V_148 ;
}
V_149 [ V_7 -> V_145 ] = V_7 ;
V_7 -> V_1 = V_44 -> V_1 ;
V_7 -> V_40 = V_44 -> V_40 ;
V_7 -> V_150 = V_44 -> V_150 ;
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
V_7 -> V_151 = false ;
V_141 = F_64 ( V_7 , V_44 ) ;
if ( V_141 )
return V_141 ;
V_93 [ V_7 -> V_1 ] = NULL ;
F_66 ( V_7 ) ;
return 0 ;
}
static int T_6 F_76 ( struct V_53 * V_54 )
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
F_65 ( L_25
L_26 ,
F_36 ( V_44 -> V_1 ) , F_37 ( V_44 -> V_1 ) ,
F_38 ( V_44 -> V_1 ) , V_44 -> V_40 ,
V_44 -> V_150 , V_44 -> V_94 , V_44 -> V_152 ) ;
F_65 ( L_27 ,
V_44 -> V_36 ) ;
V_7 = F_61 ( sizeof( struct V_6 ) , V_61 ) ;
if ( V_7 == NULL )
return - V_115 ;
V_141 = F_72 ( V_7 , V_44 ) ;
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
static int F_77 ( struct V_6 * V_7 )
{
int V_40 = V_7 -> V_40 ;
T_2 V_153 , V_154 , V_155 , V_156 ;
V_7 -> V_11 = F_78 ( F_36 ( V_7 -> V_1 ) ,
V_7 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return - V_57 ;
F_6 ( V_7 -> V_11 , V_40 + V_157 ,
& V_7 -> V_41 ) ;
F_6 ( V_7 -> V_11 , V_40 + V_42 ,
& V_153 ) ;
F_6 ( V_7 -> V_11 , V_40 + V_158 ,
& V_154 ) ;
V_7 -> V_131 = F_32 ( F_33 ( V_153 ) ,
F_79 ( V_153 ) ) ;
V_7 -> V_132 = F_32 ( F_33 ( V_153 ) ,
F_34 ( V_153 ) ) ;
if ( ! ( V_7 -> V_41 & ( 1 << V_159 ) ) )
V_160 = false ;
V_155 = F_16 ( V_7 -> V_19 + V_161 ) ;
V_156 = F_16 ( V_7 -> V_19 + V_161 + 4 ) ;
V_7 -> V_162 = ( ( T_4 ) V_156 << 32 ) | V_155 ;
if ( F_54 ( V_7 , V_85 ) ) {
int V_163 ;
T_2 V_164 ;
T_4 V_4 ;
V_4 = V_7 -> V_162 & V_165 ;
V_4 >>= V_166 ;
V_164 = ( 1 << V_4 ) ;
V_167 = F_80 ( V_167 , V_164 ) ;
V_163 = V_7 -> V_162 & V_168 ;
V_163 >>= V_169 ;
if ( V_170 == - 1 )
V_170 = V_163 ;
else
V_170 = F_80 ( V_170 , V_163 ) ;
}
if ( F_54 ( V_7 , V_85 ) &&
F_54 ( V_7 , V_171 ) ) {
V_7 -> V_172 = true ;
V_173 = true ;
}
if ( F_54 ( V_7 , V_171 ) ) {
V_7 -> V_77 = F_50 ( V_7 ) ;
if ( ! V_7 -> V_77 )
return - V_115 ;
}
if ( V_7 -> V_41 & ( 1UL << V_174 ) )
V_175 = true ;
if ( F_81 ( V_7 -> V_11 ) ) {
int V_55 , V_176 ;
V_7 -> V_177 = F_78 ( V_7 -> V_11 -> V_38 -> V_178 ,
F_82 ( 0 , 0 ) ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
& V_7 -> V_179 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_40 + 8 ,
& V_7 -> V_180 ) ;
V_7 -> V_179 &= ~ 1 ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_176 = 0 ; V_176 < 0x12 ; V_176 ++ )
V_7 -> V_181 [ V_55 ] [ V_176 ] = F_4 ( V_7 , V_55 , V_176 ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
V_7 -> V_182 [ V_55 ] = F_8 ( V_7 , V_55 ) ;
}
return F_83 ( V_7 -> V_11 ) ;
}
static void F_84 ( void )
{
static const char * const V_183 [] = {
L_28 , L_29 , L_30 , L_31 , L_32 , L_33 ,
L_34 , L_35 , L_36 , L_37
} ;
struct V_6 * V_7 ;
F_85 (iommu) {
int V_55 ;
F_86 ( L_38 ,
F_87 ( & V_7 -> V_11 -> V_11 ) , V_7 -> V_40 ) ;
if ( V_7 -> V_41 & ( 1 << V_184 ) ) {
F_86 ( L_39 ) ;
for ( V_55 = 0 ; V_55 < F_88 ( V_183 ) ; ++ V_55 ) {
if ( F_54 ( V_7 , ( 1ULL << V_55 ) ) )
F_89 ( L_40 , V_183 [ V_55 ] ) ;
}
F_89 ( L_41 ) ;
}
}
if ( V_185 )
F_86 ( L_42 ) ;
}
static int T_6 F_90 ( void )
{
struct V_6 * V_7 ;
int V_141 = 0 ;
F_85 (iommu) {
V_141 = F_77 ( V_7 ) ;
if ( V_141 )
break;
}
V_141 = F_91 () ;
F_84 () ;
return V_141 ;
}
static int F_92 ( struct V_6 * V_7 )
{
int V_186 ;
V_186 = F_93 ( V_7 -> V_11 ) ;
if ( V_186 )
return V_186 ;
V_186 = F_94 ( V_7 -> V_11 -> V_187 ,
V_188 ,
V_189 ,
0 , L_43 ,
V_7 -> V_11 ) ;
if ( V_186 ) {
F_95 ( V_7 -> V_11 ) ;
return V_186 ;
}
V_7 -> V_151 = true ;
return 0 ;
}
static int F_96 ( struct V_6 * V_7 )
{
int V_141 ;
if ( V_7 -> V_151 )
goto V_190;
if ( F_97 ( V_7 -> V_11 , V_191 ) )
V_141 = F_92 ( V_7 ) ;
else
V_141 = - V_57 ;
if ( V_141 )
return V_141 ;
V_190:
F_15 ( V_7 , V_33 ) ;
if ( V_7 -> V_77 != NULL )
F_15 ( V_7 , V_192 ) ;
return 0 ;
}
static void T_6 F_98 ( void )
{
struct V_193 * V_17 , * V_142 ;
F_99 (entry, next, &amd_iommu_unity_map, list) {
F_70 ( & V_17 -> V_111 ) ;
F_71 ( V_17 ) ;
}
}
static int T_6 F_100 ( struct V_118 * V_119 )
{
int V_55 ;
switch ( V_119 -> type ) {
case V_194 :
F_63 ( V_119 -> V_1 , V_119 ) ;
break;
case V_195 :
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
F_63 ( V_55 , V_119 ) ;
break;
case V_196 :
for ( V_55 = V_119 -> V_1 ; V_55 <= V_119 -> V_197 ; ++ V_55 )
F_63 ( V_55 , V_119 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_101 ( struct V_118 * V_119 )
{
struct V_193 * V_128 = NULL ;
char * V_198 ;
V_128 = F_61 ( sizeof( * V_128 ) , V_61 ) ;
if ( V_128 == NULL )
return - V_115 ;
switch ( V_119 -> type ) {
default:
F_71 ( V_128 ) ;
return 0 ;
case V_194 :
V_198 = L_44 ;
V_128 -> V_124 = V_128 -> V_199 = V_119 -> V_1 ;
break;
case V_195 :
V_198 = L_45 ;
V_128 -> V_124 = 0 ;
V_128 -> V_199 = V_2 ;
break;
case V_196 :
V_198 = L_46 ;
V_128 -> V_124 = V_119 -> V_1 ;
V_128 -> V_199 = V_119 -> V_197 ;
break;
}
V_128 -> V_200 = F_102 ( V_119 -> V_122 ) ;
V_128 -> V_201 = V_128 -> V_200 + F_102 ( V_119 -> V_123 ) ;
V_128 -> V_202 = V_119 -> V_94 >> 1 ;
F_65 ( L_47
L_48 , V_198 ,
F_36 ( V_128 -> V_124 ) , F_37 ( V_128 -> V_124 ) ,
F_38 ( V_128 -> V_124 ) , F_36 ( V_128 -> V_199 ) ,
F_37 ( V_128 -> V_199 ) , F_38 ( V_128 -> V_199 ) ,
V_128 -> V_200 , V_128 -> V_201 , V_119 -> V_94 ) ;
F_62 ( & V_128 -> V_111 , & V_203 ) ;
return 0 ;
}
static int T_6 F_103 ( struct V_53 * V_54 )
{
T_3 * V_45 = ( T_3 * ) V_54 , * V_46 = ( T_3 * ) V_54 ;
struct V_118 * V_119 ;
V_46 += V_54 -> V_48 ;
V_45 += V_58 ;
while ( V_45 < V_46 ) {
V_119 = (struct V_118 * ) V_45 ;
if ( V_119 -> V_94 & V_120 )
F_100 ( V_119 ) ;
else if ( V_119 -> V_94 & V_204 )
F_101 ( V_119 ) ;
V_45 += V_119 -> V_48 ;
}
return 0 ;
}
static void F_104 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_55 ( V_1 , V_205 ) ;
F_55 ( V_1 , V_206 ) ;
}
}
static void T_6 F_105 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
V_22 [ V_1 ] . V_88 [ 0 ] = 0ULL ;
V_22 [ V_1 ] . V_88 [ 1 ] = 0ULL ;
}
}
static void F_106 ( void )
{
T_2 V_1 ;
if ( ! V_207 )
return;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 )
F_55 ( V_1 , V_208 ) ;
}
static void F_107 ( struct V_6 * V_7 )
{
V_7 -> V_129 & V_209 ?
F_15 ( V_7 , V_210 ) :
F_18 ( V_7 , V_210 ) ;
V_7 -> V_129 & V_211 ?
F_15 ( V_7 , V_212 ) :
F_18 ( V_7 , V_212 ) ;
V_7 -> V_129 & V_213 ?
F_15 ( V_7 , V_214 ) :
F_18 ( V_7 , V_214 ) ;
V_7 -> V_129 & V_215 ?
F_15 ( V_7 , V_216 ) :
F_18 ( V_7 , V_216 ) ;
F_15 ( V_7 , V_217 ) ;
F_19 ( V_7 , V_218 ) ;
}
static void F_108 ( struct V_6 * V_7 )
{
int V_55 , V_176 ;
T_2 V_219 ;
struct V_220 * V_221 = V_7 -> V_177 ;
if ( ! F_81 ( V_7 -> V_11 ) || ! V_221 )
return;
F_5 ( V_221 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_221 , 0x64 , & V_219 ) ;
if ( ! ( V_219 & 0x1 ) )
F_5 ( V_221 , 0x64 , V_219 | 1 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
V_7 -> V_179 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 8 ,
V_7 -> V_180 ) ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_176 = 0 ; V_176 < 0x12 ; V_176 ++ )
F_7 ( V_7 , V_55 , V_176 , V_7 -> V_181 [ V_55 ] [ V_176 ] ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
F_9 ( V_7 , V_55 , V_7 -> V_182 [ V_55 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_40 + 4 ,
V_7 -> V_179 | 1 ) ;
}
static void F_109 ( void )
{
struct V_6 * V_7 ;
F_85 (iommu) {
F_21 ( V_7 ) ;
F_107 ( V_7 ) ;
F_12 ( V_7 ) ;
F_44 ( V_7 ) ;
F_48 ( V_7 ) ;
F_10 ( V_7 ) ;
F_20 ( V_7 ) ;
F_110 ( V_7 ) ;
}
}
static void F_111 ( void )
{
struct V_6 * V_7 ;
F_85 (iommu) {
F_51 ( V_7 ) ;
F_53 ( V_7 ) ;
}
}
static void F_112 ( void )
{
F_109 () ;
F_111 () ;
}
static void F_113 ( void )
{
struct V_6 * V_7 ;
F_85 (iommu)
F_21 ( V_7 ) ;
}
static void F_114 ( void )
{
struct V_6 * V_7 ;
F_85 (iommu)
F_108 ( V_7 ) ;
F_112 () ;
F_115 () ;
}
static int F_116 ( void )
{
F_113 () ;
return 0 ;
}
static void T_6 F_117 ( void )
{
F_46 ( ( unsigned long ) V_222 ,
F_3 ( V_223 ) ) ;
if ( V_224 ) {
F_118 ( V_224 ) ;
V_224 = NULL ;
}
F_46 ( ( unsigned long ) V_93 ,
F_3 ( V_223 ) ) ;
F_46 ( ( unsigned long ) V_135 ,
F_3 ( V_225 ) ) ;
F_46 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_68 () ;
#ifdef F_119
F_120 () ;
#endif
}
static bool T_6 F_121 ( void )
{
bool V_141 , V_226 ;
int V_227 ;
V_226 = false ;
V_141 = false ;
for ( V_227 = 0 ; V_227 < V_228 ; V_227 ++ ) {
int V_1 , V_108 = F_122 ( V_227 ) ;
V_1 = F_123 ( V_108 ) ;
if ( V_1 < 0 ) {
F_24 ( V_229 L_49 , V_108 ) ;
V_141 = false ;
} else if ( V_1 == V_230 ) {
V_226 = true ;
V_141 = true ;
}
}
if ( ! V_226 ) {
F_24 ( V_229 L_50 ) ;
}
if ( ! V_141 )
F_24 ( L_51 ) ;
return V_141 ;
}
static void T_6 F_124 ( void )
{
F_125 () ;
F_46 ( ( unsigned long ) V_231 ,
F_3 ( V_232 / 8 ) ) ;
F_98 () ;
}
static int T_6 F_126 ( void )
{
struct V_53 * V_233 ;
T_7 V_234 ;
T_8 V_235 ;
int V_55 , V_141 = 0 ;
if ( ! V_236 )
return - V_57 ;
V_235 = F_127 ( L_52 , 0 , & V_233 , & V_234 ) ;
if ( V_235 == V_237 )
return - V_57 ;
else if ( F_128 ( V_235 ) ) {
const char * V_238 = F_129 ( V_235 ) ;
F_24 ( L_53 , V_238 ) ;
return - V_114 ;
}
V_141 = F_40 ( V_233 ) ;
if ( V_141 )
goto V_239;
V_23 = F_2 ( V_240 ) ;
V_225 = F_2 ( V_241 ) ;
V_223 = F_2 ( V_242 ) ;
V_141 = - V_115 ;
V_22 = ( void * ) F_42 ( V_61 | V_62 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_239;
V_135 = ( void * ) F_42 ( V_61 ,
F_3 ( V_225 ) ) ;
if ( V_135 == NULL )
goto V_239;
V_93 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_223 ) ) ;
if ( V_93 == NULL )
goto V_239;
V_231 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_232 / 8 ) ) ;
if ( V_231 == NULL )
goto V_239;
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
V_135 [ V_55 ] = V_55 ;
V_231 [ 0 ] = 1 ;
F_73 ( & V_243 ) ;
V_141 = F_76 ( V_233 ) ;
if ( V_141 )
goto V_239;
if ( V_207 )
V_207 = F_121 () ;
if ( V_207 ) {
V_224 = F_130 ( L_54 ,
V_244 * sizeof( T_2 ) ,
V_245 ,
0 , NULL ) ;
if ( ! V_224 )
goto V_239;
V_222 = ( void * ) F_42 (
V_61 | V_62 ,
F_3 ( V_223 ) ) ;
if ( ! V_222 )
goto V_239;
}
V_141 = F_103 ( V_233 ) ;
if ( V_141 )
goto V_239;
F_106 () ;
V_239:
F_131 ( ( char T_5 * ) V_233 , V_234 ) ;
V_233 = NULL ;
return V_141 ;
}
static int F_115 ( void )
{
struct V_6 * V_7 ;
int V_141 = 0 ;
F_85 (iommu) {
V_141 = F_96 ( V_7 ) ;
if ( V_141 )
goto V_239;
}
V_239:
return V_141 ;
}
static bool F_132 ( void )
{
struct V_53 * V_233 ;
T_7 V_234 ;
T_8 V_235 ;
V_235 = F_127 ( L_52 , 0 , & V_233 , & V_234 ) ;
if ( V_235 == V_237 )
return false ;
else if ( F_128 ( V_235 ) ) {
const char * V_238 = F_129 ( V_235 ) ;
F_24 ( L_53 , V_238 ) ;
return false ;
}
F_131 ( ( char T_5 * ) V_233 , V_234 ) ;
F_133 () ;
if ( ! V_246 )
V_207 = true ;
return true ;
}
static int F_134 ( void )
{
struct V_6 * V_7 ;
int V_141 ;
F_104 () ;
F_85 (iommu)
F_110 ( V_7 ) ;
if ( V_247 )
V_141 = F_135 () ;
else
V_141 = F_136 () ;
if ( V_141 )
return V_141 ;
F_137 () ;
F_138 () ;
return 0 ;
}
static int T_6 F_139 ( void )
{
int V_141 = 0 ;
switch ( V_248 ) {
case V_249 :
if ( ! F_132 () ) {
V_248 = V_250 ;
V_141 = - V_57 ;
} else {
V_248 = V_251 ;
}
break;
case V_251 :
V_141 = F_126 () ;
V_248 = V_141 ? V_252 : V_253 ;
break;
case V_253 :
F_109 () ;
F_140 ( & V_254 ) ;
V_255 . V_256 = F_113 ;
V_248 = V_257 ;
break;
case V_257 :
V_141 = F_90 () ;
V_248 = V_141 ? V_252 : V_258 ;
F_111 () ;
break;
case V_258 :
V_141 = F_115 () ;
V_248 = V_141 ? V_252 : V_259 ;
break;
case V_259 :
V_141 = F_134 () ;
V_248 = V_141 ? V_252 : V_260 ;
break;
case V_260 :
V_248 = V_261 ;
break;
case V_261 :
break;
case V_250 :
case V_252 :
V_141 = - V_114 ;
break;
default:
F_141 () ;
}
return V_141 ;
}
static int T_6 F_142 ( enum V_262 V_263 )
{
int V_141 = 0 ;
while ( V_248 != V_263 ) {
V_141 = F_139 () ;
if ( V_248 == V_250 ||
V_248 == V_252 )
break;
}
return V_141 ;
}
int T_6 F_143 ( void )
{
return F_142 ( V_253 ) ;
}
int T_6 F_144 ( void )
{
return V_207 ? 1 : 0 ;
}
int T_6 F_145 ( void )
{
int V_141 ;
V_141 = F_142 ( V_257 ) ;
if ( V_141 )
return V_141 ;
V_185 = 1 ;
return 0 ;
}
void F_146 ( void )
{
F_116 () ;
}
int F_147 ( int V_264 )
{
F_114 () ;
return 0 ;
}
int T_6 F_148 ( void )
{
return 0 ;
}
static int T_6 F_149 ( void )
{
int V_141 ;
V_141 = F_142 ( V_261 ) ;
if ( V_141 ) {
F_124 () ;
if ( ! V_185 ) {
F_113 () ;
F_117 () ;
} else {
struct V_6 * V_7 ;
F_105 () ;
F_85 (iommu)
F_110 ( V_7 ) ;
}
}
return V_141 ;
}
int T_6 F_150 ( void )
{
int V_141 ;
if ( V_265 || ( V_266 && ! V_267 ) )
return - V_57 ;
if ( V_268 )
return - V_57 ;
V_141 = F_142 ( V_251 ) ;
if ( V_141 )
return V_141 ;
V_236 = true ;
V_266 = 1 ;
V_269 . V_7 . V_270 = F_149 ;
return 0 ;
}
static int T_6 F_151 ( char * V_271 )
{
V_272 = true ;
return 1 ;
}
static int T_6 F_152 ( char * V_271 )
{
for (; * V_271 ; ++ V_271 ) {
if ( strncmp ( V_271 , L_55 , 9 ) == 0 )
V_273 = true ;
if ( strncmp ( V_271 , L_56 , 3 ) == 0 )
V_268 = true ;
if ( strncmp ( V_271 , L_57 , 15 ) == 0 )
V_274 = true ;
}
return 1 ;
}
bool F_153 ( void )
{
return V_173 ;
}
