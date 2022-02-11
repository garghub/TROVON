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
static void T_5 F_12 ( struct V_6 * V_7 )
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
static void F_19 ( struct V_6 * V_7 )
{
static const char * const V_28 [] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 ,
L_7 , L_8 , L_9 , L_10 , NULL
} ;
int V_29 ;
F_20 ( V_30 L_11 ,
F_21 ( & V_7 -> V_11 -> V_11 ) , V_7 -> V_31 ) ;
if ( V_7 -> V_32 & ( 1 << V_33 ) ) {
F_20 ( V_34 L_12 ) ;
for ( V_29 = 0 ; V_28 [ V_29 ] ; ++ V_29 )
if ( F_22 ( V_7 , ( 1ULL << V_29 ) ) )
F_20 ( V_34 L_13 , V_28 [ V_29 ] ) ;
}
F_20 ( V_34 L_14 ) ;
F_15 ( V_7 , V_35 ) ;
}
static void F_23 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_36 ) ;
F_18 ( V_7 , V_37 ) ;
F_18 ( V_7 , V_38 ) ;
F_18 ( V_7 , V_35 ) ;
}
static T_3 * T_5 F_24 ( T_4 V_9 )
{
T_3 * V_39 ;
if ( ! F_25 ( V_9 , V_40 , L_15 ) ) {
F_26 ( L_16 ,
V_9 ) ;
F_26 ( L_17 ) ;
return NULL ;
}
V_39 = F_27 ( V_9 , V_40 ) ;
if ( V_39 != NULL )
return V_39 ;
F_28 ( V_9 , V_40 ) ;
return NULL ;
}
static void T_5 F_29 ( struct V_6 * V_7 )
{
if ( V_7 -> V_19 )
F_30 ( V_7 -> V_19 ) ;
F_28 ( V_7 -> V_41 , V_40 ) ;
}
static inline int F_31 ( T_3 * V_42 )
{
return 0x04 << ( * V_42 >> 6 ) ;
}
static int T_5 F_32 ( int V_43 , int V_11 , int V_44 , int V_31 )
{
T_2 V_32 ;
V_32 = F_33 ( V_43 , V_11 , V_44 , V_31 + V_45 ) ;
F_1 ( F_34 ( F_35 ( V_32 ) , F_36 ( V_32 ) ) ) ;
return 0 ;
}
static int T_5 F_37 ( struct V_46 * V_47 )
{
T_3 * V_48 = ( void * ) V_47 , * V_49 = ( void * ) V_47 ;
struct V_50 * V_11 ;
V_48 += sizeof( * V_47 ) ;
V_49 += V_47 -> V_51 ;
F_32 ( F_38 ( V_47 -> V_1 ) ,
F_39 ( V_47 -> V_1 ) ,
F_40 ( V_47 -> V_1 ) ,
V_47 -> V_31 ) ;
while ( V_48 < V_49 ) {
V_11 = (struct V_50 * ) V_48 ;
switch ( V_11 -> type ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
F_1 ( V_11 -> V_1 ) ;
break;
default:
break;
}
V_48 += F_31 ( V_48 ) ;
}
F_41 ( V_48 != V_49 ) ;
return 0 ;
}
static int T_5 F_42 ( struct V_56 * V_57 )
{
int V_29 ;
T_3 V_58 = 0 , * V_48 = ( T_3 * ) V_57 , * V_49 = ( T_3 * ) V_57 ;
struct V_46 * V_47 ;
for ( V_29 = 0 ; V_29 < V_57 -> V_51 ; ++ V_29 )
V_58 += V_48 [ V_29 ] ;
if ( V_58 != 0 ) {
V_59 = - V_60 ;
return 0 ;
}
V_48 += V_61 ;
V_49 += V_57 -> V_51 ;
while ( V_48 < V_49 ) {
V_47 = (struct V_46 * ) V_48 ;
switch ( V_47 -> type ) {
case V_62 :
F_37 ( V_47 ) ;
break;
default:
break;
}
V_48 += V_47 -> V_51 ;
}
F_41 ( V_48 != V_49 ) ;
return 0 ;
}
static T_3 * T_5 F_43 ( struct V_6 * V_7 )
{
T_3 * V_63 = ( T_3 * ) F_44 ( V_64 | V_65 ,
F_3 ( V_66 ) ) ;
if ( V_63 == NULL )
return NULL ;
V_7 -> V_67 = V_66 | V_68 ;
return V_63 ;
}
void F_45 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_36 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_69 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_70 ) ;
F_15 ( V_7 , V_36 ) ;
}
static void F_46 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_63 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_63 ) ;
V_17 |= V_71 ;
F_11 ( V_7 -> V_19 + V_72 ,
& V_17 , sizeof( V_17 ) ) ;
F_45 ( V_7 ) ;
V_7 -> V_67 &= ~ ( V_68 ) ;
}
static void T_5 F_47 ( struct V_6 * V_7 )
{
F_48 ( ( unsigned long ) V_7 -> V_63 ,
F_3 ( V_7 -> V_67 & ~ ( V_68 ) ) ) ;
}
static T_3 * T_5 F_49 ( struct V_6 * V_7 )
{
V_7 -> V_73 = ( T_3 * ) F_44 ( V_64 | V_65 ,
F_3 ( V_74 ) ) ;
if ( V_7 -> V_73 == NULL )
return NULL ;
V_7 -> V_75 = V_74 ;
return V_7 -> V_73 ;
}
static void F_50 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_73 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_73 ) | V_76 ;
F_11 ( V_7 -> V_19 + V_77 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_78 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_79 ) ;
F_15 ( V_7 , V_38 ) ;
}
static void T_5 F_51 ( struct V_6 * V_7 )
{
F_48 ( ( unsigned long ) V_7 -> V_73 , F_3 ( V_74 ) ) ;
}
static void F_52 ( T_1 V_1 , T_3 V_25 )
{
int V_29 = ( V_25 >> 5 ) & 0x07 ;
int V_80 = V_25 & 0x1f ;
V_22 [ V_1 ] . V_81 [ V_29 ] |= ( 1 << V_80 ) ;
}
static int F_53 ( T_1 V_1 , T_3 V_25 )
{
int V_29 = ( V_25 >> 5 ) & 0x07 ;
int V_80 = V_25 & 0x1f ;
return ( V_22 [ V_1 ] . V_81 [ V_29 ] & ( 1 << V_80 ) ) >> V_80 ;
}
void F_54 ( T_1 V_1 )
{
int V_82 ;
V_82 = F_53 ( V_1 , V_83 ) |
( F_53 ( V_1 , V_84 ) << 1 ) ;
if ( V_82 == 0x01 )
F_52 ( V_1 , V_85 ) ;
}
static void T_5 F_55 ( struct V_6 * V_7 , T_1 V_1 )
{
V_86 [ V_1 ] = V_7 ;
}
static void T_5 F_56 ( struct V_6 * V_7 ,
T_1 V_1 , T_2 V_87 , T_2 V_88 )
{
if ( V_87 & V_89 )
F_52 ( V_1 , V_90 ) ;
if ( V_87 & V_91 )
F_52 ( V_1 , V_92 ) ;
if ( V_87 & V_93 )
F_52 ( V_1 , V_94 ) ;
if ( V_87 & V_95 )
F_52 ( V_1 , V_83 ) ;
if ( V_87 & V_96 )
F_52 ( V_1 , V_84 ) ;
if ( V_87 & V_97 )
F_52 ( V_1 , V_98 ) ;
if ( V_87 & V_99 )
F_52 ( V_1 , V_100 ) ;
F_54 ( V_1 ) ;
F_55 ( V_7 , V_1 ) ;
}
static void T_5 F_57 ( T_1 V_1 , struct V_101 * V_102 )
{
struct V_6 * V_7 = V_86 [ V_1 ] ;
if ( ! ( V_102 -> V_87 & V_103 ) )
return;
if ( V_7 ) {
F_52 ( V_102 -> V_1 , V_104 ) ;
V_7 -> V_13 = V_102 -> V_105 ;
V_7 -> V_16 = V_102 -> V_106 ;
}
}
static void T_5 F_58 ( struct V_6 * V_7 )
{
int V_31 = V_7 -> V_31 ;
T_2 V_107 , V_108 , V_109 , V_110 ;
int V_29 , V_111 ;
F_6 ( V_7 -> V_11 , V_31 + V_112 ,
& V_7 -> V_32 ) ;
F_6 ( V_7 -> V_11 , V_31 + V_45 ,
& V_107 ) ;
F_6 ( V_7 -> V_11 , V_31 + V_113 ,
& V_108 ) ;
V_7 -> V_114 = F_34 ( F_35 ( V_107 ) ,
F_59 ( V_107 ) ) ;
V_7 -> V_115 = F_34 ( F_35 ( V_107 ) ,
F_36 ( V_107 ) ) ;
V_7 -> V_116 = F_60 ( V_108 ) ;
if ( ! ( V_7 -> V_32 & ( 1 << V_117 ) ) )
V_118 = false ;
V_109 = F_16 ( V_7 -> V_19 + V_119 ) ;
V_110 = F_16 ( V_7 -> V_19 + V_119 + 4 ) ;
V_7 -> V_120 = ( ( T_4 ) V_110 << 32 ) | V_109 ;
if ( ! F_61 ( V_7 -> V_11 ) )
return;
F_6 ( V_7 -> V_11 , V_7 -> V_31 + 4 ,
& V_7 -> V_121 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_31 + 8 ,
& V_7 -> V_122 ) ;
V_7 -> V_121 &= ~ 1 ;
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
for ( V_111 = 0 ; V_111 < 0x12 ; V_111 ++ )
V_7 -> V_123 [ V_29 ] [ V_111 ] = F_4 ( V_7 , V_29 , V_111 ) ;
for ( V_29 = 0 ; V_29 < 0x83 ; V_29 ++ )
V_7 -> V_124 [ V_29 ] = F_8 ( V_7 , V_29 ) ;
}
static void T_5 F_62 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
T_3 * V_48 = ( T_3 * ) V_47 ;
T_3 * V_49 = V_48 , V_87 = 0 ;
T_1 V_1 = 0 , V_125 = 0 , V_126 = 0 ;
T_2 V_127 , V_88 = 0 ;
bool V_128 = false ;
struct V_50 * V_129 ;
V_7 -> V_130 = V_47 -> V_87 ;
V_48 += sizeof( struct V_46 ) ;
V_49 += V_47 -> V_51 ;
while ( V_48 < V_49 ) {
V_129 = (struct V_50 * ) V_48 ;
switch ( V_129 -> type ) {
case V_131 :
F_63 ( L_18
L_19 ,
F_38 ( V_7 -> V_114 ) ,
F_39 ( V_7 -> V_114 ) ,
F_40 ( V_7 -> V_114 ) ,
F_38 ( V_7 -> V_115 ) ,
F_39 ( V_7 -> V_115 ) ,
F_40 ( V_7 -> V_115 ) ,
V_129 -> V_87 ) ;
for ( V_127 = V_7 -> V_114 ;
V_127 <= V_7 -> V_115 ; ++ V_127 )
F_56 ( V_7 , V_127 ,
V_129 -> V_87 , 0 ) ;
break;
case V_52 :
F_63 ( L_20
L_21 ,
F_38 ( V_129 -> V_1 ) ,
F_39 ( V_129 -> V_1 ) ,
F_40 ( V_129 -> V_1 ) ,
V_129 -> V_87 ) ;
V_1 = V_129 -> V_1 ;
F_56 ( V_7 , V_1 , V_129 -> V_87 , 0 ) ;
break;
case V_132 :
F_63 ( L_22
L_23 ,
F_38 ( V_129 -> V_1 ) ,
F_39 ( V_129 -> V_1 ) ,
F_40 ( V_129 -> V_1 ) ,
V_129 -> V_87 ) ;
V_125 = V_129 -> V_1 ;
V_87 = V_129 -> V_87 ;
V_88 = 0 ;
V_128 = false ;
break;
case V_54 :
F_63 ( L_24
L_25 ,
F_38 ( V_129 -> V_1 ) ,
F_39 ( V_129 -> V_1 ) ,
F_40 ( V_129 -> V_1 ) ,
V_129 -> V_87 ,
F_38 ( V_129 -> V_133 >> 8 ) ,
F_39 ( V_129 -> V_133 >> 8 ) ,
F_40 ( V_129 -> V_133 >> 8 ) ) ;
V_1 = V_129 -> V_1 ;
V_126 = V_129 -> V_133 >> 8 ;
F_56 ( V_7 , V_1 , V_129 -> V_87 , 0 ) ;
F_56 ( V_7 , V_126 , V_129 -> V_87 , 0 ) ;
V_134 [ V_1 ] = V_126 ;
break;
case V_135 :
F_63 ( L_26
L_27
L_28 ,
F_38 ( V_129 -> V_1 ) ,
F_39 ( V_129 -> V_1 ) ,
F_40 ( V_129 -> V_1 ) ,
V_129 -> V_87 ,
F_38 ( V_129 -> V_133 >> 8 ) ,
F_39 ( V_129 -> V_133 >> 8 ) ,
F_40 ( V_129 -> V_133 >> 8 ) ) ;
V_125 = V_129 -> V_1 ;
V_87 = V_129 -> V_87 ;
V_126 = V_129 -> V_133 >> 8 ;
V_88 = 0 ;
V_128 = true ;
break;
case V_55 :
F_63 ( L_29
L_30 ,
F_38 ( V_129 -> V_1 ) ,
F_39 ( V_129 -> V_1 ) ,
F_40 ( V_129 -> V_1 ) ,
V_129 -> V_87 , V_129 -> V_133 ) ;
V_1 = V_129 -> V_1 ;
F_56 ( V_7 , V_1 , V_129 -> V_87 ,
V_129 -> V_133 ) ;
break;
case V_136 :
F_63 ( L_31
L_32 ,
F_38 ( V_129 -> V_1 ) ,
F_39 ( V_129 -> V_1 ) ,
F_40 ( V_129 -> V_1 ) ,
V_129 -> V_87 , V_129 -> V_133 ) ;
V_125 = V_129 -> V_1 ;
V_87 = V_129 -> V_87 ;
V_88 = V_129 -> V_133 ;
V_128 = false ;
break;
case V_53 :
F_63 ( L_33 ,
F_38 ( V_129 -> V_1 ) ,
F_39 ( V_129 -> V_1 ) ,
F_40 ( V_129 -> V_1 ) ) ;
V_1 = V_129 -> V_1 ;
for ( V_127 = V_125 ; V_127 <= V_1 ; ++ V_127 ) {
if ( V_128 ) {
V_134 [ V_127 ] = V_126 ;
F_56 ( V_7 ,
V_126 , V_87 , V_88 ) ;
}
F_56 ( V_7 , V_127 ,
V_87 , V_88 ) ;
}
break;
default:
break;
}
V_48 += F_31 ( V_48 ) ;
}
}
static int T_5 F_64 ( struct V_6 * V_7 )
{
T_2 V_29 ;
for ( V_29 = V_7 -> V_114 ; V_29 <= V_7 -> V_115 ; ++ V_29 )
F_55 ( V_7 , V_29 ) ;
return 0 ;
}
static void T_5 F_65 ( struct V_6 * V_7 )
{
F_47 ( V_7 ) ;
F_51 ( V_7 ) ;
F_29 ( V_7 ) ;
}
static void T_5 F_66 ( void )
{
struct V_6 * V_7 , * V_137 ;
F_67 (iommu, next) {
F_68 ( & V_7 -> V_138 ) ;
F_65 ( V_7 ) ;
F_69 ( V_7 ) ;
}
}
static int T_5 F_70 ( struct V_6 * V_7 , struct V_46 * V_47 )
{
F_71 ( & V_7 -> V_139 ) ;
F_72 ( & V_7 -> V_138 , & V_140 ) ;
V_7 -> V_141 = V_142 ++ ;
if ( F_73 ( V_7 -> V_141 >= V_143 ) ) {
F_74 ( 1 , L_34 ) ;
return - V_144 ;
}
V_145 [ V_7 -> V_141 ] = V_7 ;
V_7 -> V_11 = F_75 ( F_38 ( V_47 -> V_1 ) , V_47 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return 1 ;
V_7 -> V_31 = V_47 -> V_31 ;
V_7 -> V_146 = V_47 -> V_146 ;
V_7 -> V_41 = V_47 -> V_41 ;
V_7 -> V_19 = F_24 ( V_47 -> V_41 ) ;
if ( ! V_7 -> V_19 )
return - V_147 ;
V_7 -> V_63 = F_43 ( V_7 ) ;
if ( ! V_7 -> V_63 )
return - V_147 ;
V_7 -> V_73 = F_49 ( V_7 ) ;
if ( ! V_7 -> V_73 )
return - V_147 ;
V_7 -> V_148 = false ;
F_58 ( V_7 ) ;
F_62 ( V_7 , V_47 ) ;
F_64 ( V_7 ) ;
if ( V_7 -> V_32 & ( 1UL << V_149 ) )
V_150 = true ;
return F_76 ( V_7 -> V_11 ) ;
}
static int T_5 F_77 ( struct V_56 * V_57 )
{
T_3 * V_48 = ( T_3 * ) V_57 , * V_49 = ( T_3 * ) V_57 ;
struct V_46 * V_47 ;
struct V_6 * V_7 ;
int V_39 ;
V_49 += V_57 -> V_51 ;
V_48 += V_61 ;
while ( V_48 < V_49 ) {
V_47 = (struct V_46 * ) V_48 ;
switch ( * V_48 ) {
case V_62 :
F_63 ( L_35
L_36 ,
F_38 ( V_47 -> V_1 ) , F_39 ( V_47 -> V_1 ) ,
F_40 ( V_47 -> V_1 ) , V_47 -> V_31 ,
V_47 -> V_146 , V_47 -> V_87 , V_47 -> V_151 ) ;
F_63 ( L_37 ,
V_47 -> V_41 ) ;
V_7 = F_78 ( sizeof( struct V_6 ) , V_64 ) ;
if ( V_7 == NULL ) {
V_59 = - V_147 ;
return 0 ;
}
V_39 = F_70 ( V_7 , V_47 ) ;
if ( V_39 ) {
V_59 = V_39 ;
return 0 ;
}
break;
default:
break;
}
V_48 += V_47 -> V_51 ;
}
F_41 ( V_48 != V_49 ) ;
return 0 ;
}
static int F_79 ( struct V_6 * V_7 )
{
int V_152 ;
if ( F_80 ( V_7 -> V_11 ) )
return 1 ;
V_152 = F_81 ( V_7 -> V_11 -> V_153 ,
V_154 ,
V_155 ,
0 , L_38 ,
V_7 -> V_11 ) ;
if ( V_152 ) {
F_82 ( V_7 -> V_11 ) ;
return 1 ;
}
V_7 -> V_148 = true ;
F_15 ( V_7 , V_37 ) ;
return 0 ;
}
static int F_83 ( struct V_6 * V_7 )
{
if ( V_7 -> V_148 )
return 0 ;
if ( F_84 ( V_7 -> V_11 , V_156 ) )
return F_79 ( V_7 ) ;
return 1 ;
}
static void T_5 F_85 ( void )
{
struct V_157 * V_17 , * V_137 ;
F_86 (entry, next, &amd_iommu_unity_map, list) {
F_68 ( & V_17 -> V_138 ) ;
F_69 ( V_17 ) ;
}
}
static int T_5 F_87 ( struct V_101 * V_102 )
{
int V_29 ;
switch ( V_102 -> type ) {
case V_158 :
F_57 ( V_102 -> V_1 , V_102 ) ;
break;
case V_159 :
for ( V_29 = 0 ; V_29 <= V_2 ; ++ V_29 )
F_57 ( V_29 , V_102 ) ;
break;
case V_160 :
for ( V_29 = V_102 -> V_1 ; V_29 <= V_102 -> V_161 ; ++ V_29 )
F_57 ( V_29 , V_102 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_5 F_88 ( struct V_101 * V_102 )
{
struct V_157 * V_129 = 0 ;
char * V_162 ;
V_129 = F_78 ( sizeof( * V_129 ) , V_64 ) ;
if ( V_129 == NULL )
return - V_147 ;
switch ( V_102 -> type ) {
default:
F_69 ( V_129 ) ;
return 0 ;
case V_158 :
V_162 = L_39 ;
V_129 -> V_125 = V_129 -> V_163 = V_102 -> V_1 ;
break;
case V_159 :
V_162 = L_40 ;
V_129 -> V_125 = 0 ;
V_129 -> V_163 = V_2 ;
break;
case V_160 :
V_162 = L_41 ;
V_129 -> V_125 = V_102 -> V_1 ;
V_129 -> V_163 = V_102 -> V_161 ;
break;
}
V_129 -> V_164 = F_89 ( V_102 -> V_105 ) ;
V_129 -> V_165 = V_129 -> V_164 + F_89 ( V_102 -> V_106 ) ;
V_129 -> V_166 = V_102 -> V_87 >> 1 ;
F_63 ( L_42
L_43 , V_162 ,
F_38 ( V_129 -> V_125 ) , F_39 ( V_129 -> V_125 ) ,
F_40 ( V_129 -> V_125 ) , F_38 ( V_129 -> V_163 ) ,
F_39 ( V_129 -> V_163 ) , F_40 ( V_129 -> V_163 ) ,
V_129 -> V_164 , V_129 -> V_165 , V_102 -> V_87 ) ;
F_72 ( & V_129 -> V_138 , & V_167 ) ;
return 0 ;
}
static int T_5 F_90 ( struct V_56 * V_57 )
{
T_3 * V_48 = ( T_3 * ) V_57 , * V_49 = ( T_3 * ) V_57 ;
struct V_101 * V_102 ;
V_49 += V_57 -> V_51 ;
V_48 += V_61 ;
while ( V_48 < V_49 ) {
V_102 = (struct V_101 * ) V_48 ;
if ( V_102 -> V_87 & V_103 )
F_87 ( V_102 ) ;
else if ( V_102 -> V_87 & V_168 )
F_88 ( V_102 ) ;
V_48 += V_102 -> V_51 ;
}
return 0 ;
}
static void F_91 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_52 ( V_1 , V_169 ) ;
F_52 ( V_1 , V_170 ) ;
}
}
static void F_92 ( struct V_6 * V_7 )
{
V_7 -> V_130 & V_171 ?
F_15 ( V_7 , V_172 ) :
F_18 ( V_7 , V_172 ) ;
V_7 -> V_130 & V_173 ?
F_15 ( V_7 , V_174 ) :
F_18 ( V_7 , V_174 ) ;
V_7 -> V_130 & V_175 ?
F_15 ( V_7 , V_176 ) :
F_18 ( V_7 , V_176 ) ;
V_7 -> V_130 & V_177 ?
F_15 ( V_7 , V_178 ) :
F_18 ( V_7 , V_178 ) ;
F_15 ( V_7 , V_179 ) ;
}
static void F_93 ( struct V_6 * V_7 )
{
int V_29 , V_111 ;
T_2 V_180 ;
struct V_181 * V_182 = NULL ;
if ( ! F_61 ( V_7 -> V_11 ) )
return;
V_182 = F_75 ( V_7 -> V_11 -> V_43 -> V_183 , F_94 ( 0 , 0 ) ) ;
if ( ! V_182 )
return;
F_5 ( V_182 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_182 , 0x64 , & V_180 ) ;
if ( ! ( V_180 & 0x1 ) )
F_5 ( V_182 , 0x64 , V_180 | 1 ) ;
F_95 ( V_182 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_31 + 4 ,
V_7 -> V_121 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_31 + 8 ,
V_7 -> V_122 ) ;
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
for ( V_111 = 0 ; V_111 < 0x12 ; V_111 ++ )
F_7 ( V_7 , V_29 , V_111 , V_7 -> V_123 [ V_29 ] [ V_111 ] ) ;
for ( V_29 = 0 ; V_29 < 0x83 ; V_29 ++ )
F_9 ( V_7 , V_29 , V_7 -> V_124 [ V_29 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_31 + 4 ,
V_7 -> V_121 | 1 ) ;
}
static void F_96 ( void )
{
struct V_6 * V_7 ;
F_97 (iommu) {
F_23 ( V_7 ) ;
F_92 ( V_7 ) ;
F_12 ( V_7 ) ;
F_46 ( V_7 ) ;
F_50 ( V_7 ) ;
F_10 ( V_7 ) ;
F_83 ( V_7 ) ;
F_19 ( V_7 ) ;
F_98 ( V_7 ) ;
}
}
static void F_99 ( void )
{
struct V_6 * V_7 ;
F_97 (iommu)
F_23 ( V_7 ) ;
}
static void F_100 ( void )
{
struct V_6 * V_7 ;
F_97 (iommu)
F_93 ( V_7 ) ;
F_96 () ;
F_97 (iommu)
F_98 ( V_7 ) ;
}
static int F_101 ( void )
{
F_99 () ;
return 0 ;
}
static int T_5 F_102 ( void )
{
int V_29 , V_39 = 0 ;
if ( F_103 ( L_44 , F_42 ) != 0 )
return - V_60 ;
V_39 = V_59 ;
if ( V_39 )
goto V_184;
V_23 = F_2 ( V_185 ) ;
V_186 = F_2 ( V_187 ) ;
V_188 = F_2 ( V_189 ) ;
V_39 = - V_147 ;
V_22 = ( void * ) F_44 ( V_64 | V_65 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_184;
V_134 = ( void * ) F_44 ( V_64 ,
F_3 ( V_186 ) ) ;
if ( V_134 == NULL )
goto free;
V_86 = ( void * ) F_44 (
V_64 | V_65 ,
F_3 ( V_188 ) ) ;
if ( V_86 == NULL )
goto free;
V_190 = ( void * ) F_44 (
V_64 | V_65 ,
F_3 ( V_191 / 8 ) ) ;
if ( V_190 == NULL )
goto free;
F_91 () ;
for ( V_29 = 0 ; V_29 <= V_2 ; ++ V_29 )
V_134 [ V_29 ] = V_29 ;
V_190 [ 0 ] = 1 ;
F_71 ( & V_192 ) ;
V_39 = - V_60 ;
if ( F_103 ( L_44 , F_77 ) != 0 )
goto free;
if ( V_59 ) {
V_39 = V_59 ;
goto free;
}
if ( F_103 ( L_44 , F_90 ) != 0 )
goto free;
if ( V_59 ) {
V_39 = V_59 ;
goto free;
}
V_39 = F_104 () ;
if ( V_39 )
goto free;
F_96 () ;
if ( V_193 )
V_39 = F_105 () ;
else
V_39 = F_106 () ;
if ( V_39 )
goto V_194;
F_107 () ;
F_108 () ;
F_109 ( & V_195 ) ;
if ( V_193 )
goto V_184;
if ( V_196 )
F_20 ( V_30 L_45 ) ;
else
F_20 ( V_30 L_46 ) ;
V_197 . V_198 = F_99 ;
V_184:
return V_39 ;
V_194:
F_99 () ;
free:
F_110 () ;
F_48 ( ( unsigned long ) V_190 ,
F_3 ( V_191 / 8 ) ) ;
F_48 ( ( unsigned long ) V_86 ,
F_3 ( V_188 ) ) ;
F_48 ( ( unsigned long ) V_134 ,
F_3 ( V_186 ) ) ;
F_48 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_66 () ;
F_85 () ;
#ifdef F_111
F_112 () ;
#endif
goto V_184;
}
static int T_5 F_113 ( struct V_56 * V_57 )
{
return 0 ;
}
int T_5 F_114 ( void )
{
if ( V_199 || ( V_200 && ! V_201 ) )
return - V_60 ;
if ( V_202 )
return - V_60 ;
if ( F_103 ( L_44 , F_113 ) == 0 ) {
V_200 = 1 ;
V_203 = 1 ;
V_204 . V_7 . V_205 = F_102 ;
F_115 () ;
return 1 ;
}
return - V_60 ;
}
static int T_5 F_116 ( char * V_206 )
{
V_207 = true ;
return 1 ;
}
static int T_5 F_117 ( char * V_206 )
{
for (; * V_206 ; ++ V_206 ) {
if ( strncmp ( V_206 , L_47 , 9 ) == 0 )
V_196 = true ;
if ( strncmp ( V_206 , L_48 , 3 ) == 0 )
V_202 = true ;
}
return 1 ;
}
