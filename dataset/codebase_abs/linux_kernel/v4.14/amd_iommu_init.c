bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_4 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 &= ~ V_4 ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_7 ) ;
if ( V_5 & ( 1 << V_8 ) )
V_2 -> V_3 |= V_4 ;
}
static inline void F_5 ( T_2 V_9 )
{
if ( V_9 > V_10 )
V_10 = V_9 ;
}
static inline unsigned long F_6 ( int V_11 )
{
unsigned V_12 = V_13 +
F_7 ( ( ( int ) V_10 + 1 ) * V_11 ) ;
return 1UL << V_12 ;
}
int F_8 ( void )
{
return V_14 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_2 V_15 , T_3 V_16 )
{
T_1 V_17 ;
F_10 ( V_2 -> V_18 , 0xf8 , ( V_16 | V_15 << 16 ) ) ;
F_11 ( V_2 -> V_18 , 0xfc , & V_17 ) ;
return V_17 ;
}
static void F_12 ( struct V_1 * V_2 , T_2 V_15 , T_3 V_16 , T_1 V_17 )
{
F_10 ( V_2 -> V_18 , 0xf8 , ( V_16 | V_15 << 16 | 1 << 31 ) ) ;
F_10 ( V_2 -> V_18 , 0xfc , V_17 ) ;
F_10 ( V_2 -> V_18 , 0xf8 , ( V_16 | V_15 << 16 ) ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_3 V_16 )
{
T_1 V_17 ;
F_10 ( V_2 -> V_18 , 0xf0 , V_16 ) ;
F_11 ( V_2 -> V_18 , 0xf4 , & V_17 ) ;
return V_17 ;
}
static void F_14 ( struct V_1 * V_2 , T_3 V_16 , T_1 V_17 )
{
F_10 ( V_2 -> V_18 , 0xf0 , ( V_16 | 1 << 8 ) ) ;
F_10 ( V_2 -> V_18 , 0xf4 , V_17 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_4 V_19 = V_2 -> V_20 & V_21 ;
T_4 V_22 = ( V_19 + V_2 -> V_23 ) & V_21 ;
T_4 V_24 ;
if ( ! V_2 -> V_20 )
return;
V_24 = V_19 | V_25 ;
F_16 ( V_2 -> V_6 + V_26 ,
& V_24 , sizeof( V_24 ) ) ;
V_24 = V_22 ;
F_16 ( V_2 -> V_6 + V_27 ,
& V_24 , sizeof( V_24 ) ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_4 V_24 ;
F_18 ( V_2 -> V_6 == NULL ) ;
V_24 = F_19 ( V_28 ) ;
V_24 |= ( V_29 >> 12 ) - 1 ;
F_16 ( V_2 -> V_6 + V_30 ,
& V_24 , sizeof( V_24 ) ) ;
}
static void F_20 ( struct V_1 * V_2 , T_3 V_31 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_7 ) ;
V_5 |= ( 1 << V_31 ) ;
F_21 ( V_5 , V_2 -> V_6 + V_7 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_3 V_31 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_7 ) ;
V_5 &= ~ ( 1 << V_31 ) ;
F_21 ( V_5 , V_2 -> V_6 + V_7 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_32 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_7 ) ;
V_5 &= ~ V_33 ;
V_5 |= ( V_32 << V_34 ) & V_33 ;
F_21 ( V_5 , V_2 -> V_6 + V_7 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_8 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_35 ) ;
F_22 ( V_2 , V_36 ) ;
F_22 ( V_2 , V_37 ) ;
F_22 ( V_2 , V_38 ) ;
F_22 ( V_2 , V_39 ) ;
F_22 ( V_2 , V_8 ) ;
}
static T_3 T_5 * T_6 F_26 ( T_4 V_16 , T_4 V_40 )
{
if ( ! F_27 ( V_16 , V_40 , L_1 ) ) {
F_28 ( L_2 ,
V_16 , V_40 ) ;
F_28 ( L_3 ) ;
return NULL ;
}
return ( T_3 T_5 * ) F_29 ( V_16 , V_40 ) ;
}
static void T_6 F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 )
F_31 ( V_2 -> V_6 ) ;
F_32 ( V_2 -> V_41 , V_2 -> V_42 ) ;
}
static inline T_1 F_33 ( struct V_43 * V_44 )
{
T_1 V_45 = 0 ;
switch ( V_44 -> type ) {
case 0x10 :
V_45 = 24 ;
break;
case 0x11 :
case 0x40 :
V_45 = 40 ;
break;
}
return V_45 ;
}
static inline int F_34 ( T_3 * V_46 )
{
T_1 type = ( (struct V_47 * ) V_46 ) -> type ;
if ( type < 0x80 ) {
return 0x04 << ( * V_46 >> 6 ) ;
} else if ( type == V_48 ) {
return * ( ( T_3 * ) V_46 + 21 ) + 22 ;
}
return 0 ;
}
static int T_6 F_35 ( struct V_43 * V_44 )
{
T_3 * V_49 = ( void * ) V_44 , * V_40 = ( void * ) V_44 ;
struct V_47 * V_18 ;
T_1 V_50 = F_33 ( V_44 ) ;
if ( ! V_50 ) {
F_28 ( L_4 , V_44 -> type ) ;
return - V_51 ;
}
V_49 += V_50 ;
V_40 += V_44 -> V_52 ;
while ( V_49 < V_40 ) {
V_18 = (struct V_47 * ) V_49 ;
switch ( V_18 -> type ) {
case V_53 :
F_5 ( 0xffff ) ;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
F_5 ( V_18 -> V_9 ) ;
break;
default:
break;
}
V_49 += F_34 ( V_49 ) ;
}
F_36 ( V_49 != V_40 ) ;
return 0 ;
}
static int T_6 F_37 ( struct V_58 * V_59 )
{
int V_60 ;
T_3 V_61 = 0 , * V_49 = ( T_3 * ) V_59 ;
for ( V_60 = 0 ; V_60 < V_59 -> V_52 ; ++ V_60 )
V_61 += V_49 [ V_60 ] ;
if ( V_61 != 0 ) {
F_28 ( V_62 L_5 ) ;
return - V_63 ;
}
return 0 ;
}
static int T_6 F_38 ( struct V_58 * V_59 )
{
T_3 * V_49 = ( T_3 * ) V_59 , * V_40 = ( T_3 * ) V_59 ;
struct V_43 * V_44 ;
V_49 += V_64 ;
V_40 += V_59 -> V_52 ;
while ( V_49 < V_40 ) {
V_44 = (struct V_43 * ) V_49 ;
if ( V_44 -> type == V_65 ) {
int V_66 = F_35 ( V_44 ) ;
if ( V_66 )
return V_66 ;
}
V_49 += V_44 -> V_52 ;
}
F_36 ( V_49 != V_40 ) ;
return 0 ;
}
static int T_6 F_39 ( struct V_1 * V_2 )
{
V_2 -> V_67 = ( void * ) F_40 ( V_68 | V_69 ,
F_7 ( V_70 ) ) ;
return V_2 -> V_67 ? 0 : - V_71 ;
}
void F_41 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_35 ) ;
F_21 ( 0x00 , V_2 -> V_6 + V_72 ) ;
F_21 ( 0x00 , V_2 -> V_6 + V_73 ) ;
V_2 -> V_74 = 0 ;
V_2 -> V_75 = 0 ;
F_20 ( V_2 , V_35 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_4 V_24 ;
F_18 ( V_2 -> V_67 == NULL ) ;
V_24 = F_19 ( V_2 -> V_67 ) ;
V_24 |= V_76 ;
F_16 ( V_2 -> V_6 + V_77 ,
& V_24 , sizeof( V_24 ) ) ;
F_41 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_35 ) ;
}
static void T_6 F_44 ( struct V_1 * V_2 )
{
F_45 ( ( unsigned long ) V_2 -> V_67 , F_7 ( V_70 ) ) ;
}
static int T_6 F_46 ( struct V_1 * V_2 )
{
V_2 -> V_78 = ( void * ) F_40 ( V_68 | V_69 ,
F_7 ( V_79 ) ) ;
return V_2 -> V_78 ? 0 : - V_71 ;
}
static void F_47 ( struct V_1 * V_2 )
{
T_4 V_24 ;
F_18 ( V_2 -> V_78 == NULL ) ;
V_24 = F_19 ( V_2 -> V_78 ) | V_80 ;
F_16 ( V_2 -> V_6 + V_81 ,
& V_24 , sizeof( V_24 ) ) ;
F_21 ( 0x00 , V_2 -> V_6 + V_82 ) ;
F_21 ( 0x00 , V_2 -> V_6 + V_83 ) ;
F_20 ( V_2 , V_37 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_37 ) ;
}
static void T_6 F_49 ( struct V_1 * V_2 )
{
F_45 ( ( unsigned long ) V_2 -> V_78 , F_7 ( V_79 ) ) ;
}
static int T_6 F_50 ( struct V_1 * V_2 )
{
V_2 -> V_84 = ( void * ) F_40 ( V_68 | V_69 ,
F_7 ( V_85 ) ) ;
return V_2 -> V_84 ? 0 : - V_71 ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_4 V_24 ;
if ( V_2 -> V_84 == NULL )
return;
V_24 = F_19 ( V_2 -> V_84 ) | V_86 ;
F_16 ( V_2 -> V_6 + V_87 ,
& V_24 , sizeof( V_24 ) ) ;
F_21 ( 0x00 , V_2 -> V_6 + V_88 ) ;
F_21 ( 0x00 , V_2 -> V_6 + V_89 ) ;
F_20 ( V_2 , V_90 ) ;
F_20 ( V_2 , V_91 ) ;
}
static void T_6 F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_84 == NULL )
return;
F_45 ( ( unsigned long ) V_2 -> V_84 , F_7 ( V_85 ) ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
#ifdef F_54
if ( V_2 -> V_92 )
F_45 ( ( unsigned long ) V_2 -> V_92 ,
F_7 ( V_93 ) ) ;
if ( V_2 -> V_94 )
F_45 ( ( unsigned long ) V_2 -> V_94 ,
F_7 ( 8 ) ) ;
#endif
}
static int F_55 ( struct V_1 * V_2 )
{
#ifdef F_54
T_1 V_95 , V_60 ;
if ( ! V_2 -> V_92 )
return - V_51 ;
V_95 = F_4 ( V_2 -> V_6 + V_96 ) ;
if ( V_95 & ( V_97 ) )
return 0 ;
F_20 ( V_2 , V_39 ) ;
F_20 ( V_2 , V_38 ) ;
for ( V_60 = 0 ; V_60 < V_98 ; ++ V_60 ) {
V_95 = F_4 ( V_2 -> V_6 + V_96 ) ;
if ( V_95 & ( V_97 ) )
break;
}
if ( V_60 >= V_98 )
return - V_51 ;
#endif
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
T_4 V_24 ;
if ( ! F_57 ( V_99 ) )
return 0 ;
V_2 -> V_92 = ( T_3 * ) F_40 ( V_68 | V_69 ,
F_7 ( V_93 ) ) ;
if ( ! V_2 -> V_92 )
goto V_100;
V_2 -> V_94 = ( T_3 * ) F_40 ( V_68 | V_69 ,
F_7 ( 8 ) ) ;
if ( ! V_2 -> V_94 )
goto V_100;
V_24 = F_19 ( V_2 -> V_92 ) | V_101 ;
F_16 ( V_2 -> V_6 + V_102 ,
& V_24 , sizeof( V_24 ) ) ;
V_24 = ( F_19 ( V_2 -> V_92 ) & 0xFFFFFFFFFFFFFULL ) & ~ 7ULL ;
F_16 ( V_2 -> V_6 + V_103 ,
& V_24 , sizeof( V_24 ) ) ;
F_21 ( 0x00 , V_2 -> V_6 + V_104 ) ;
F_21 ( 0x00 , V_2 -> V_6 + V_105 ) ;
return 0 ;
V_100:
F_53 ( V_2 ) ;
return - V_51 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_66 = 0 ;
#ifdef F_54
if ( F_57 ( V_99 ) &&
! F_59 ( V_2 , V_106 ) )
V_99 = V_107 ;
V_66 = F_56 ( V_2 ) ;
#endif
return V_66 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( ! F_59 ( V_2 , V_108 ) )
return;
F_20 ( V_2 , V_109 ) ;
}
static void F_61 ( T_2 V_9 , T_3 V_31 )
{
int V_60 = ( V_31 >> 6 ) & 0x03 ;
int V_110 = V_31 & 0x3f ;
V_28 [ V_9 ] . V_111 [ V_60 ] |= ( 1UL << V_110 ) ;
}
static int F_62 ( T_2 V_9 , T_3 V_31 )
{
int V_60 = ( V_31 >> 6 ) & 0x03 ;
int V_110 = V_31 & 0x3f ;
return ( V_28 [ V_9 ] . V_111 [ V_60 ] & ( 1UL << V_110 ) ) >> V_110 ;
}
static bool F_63 ( void )
{
T_4 V_112 , V_113 , V_24 = 0 , V_114 = 0 ;
struct V_115 * V_116 = NULL ;
T_1 V_117 , V_118 , V_9 , V_119 ;
T_7 V_120 ;
struct V_1 * V_2 ;
T_2 V_121 , V_122 , V_123 ;
T_8 V_124 ;
T_4 V_125 ;
if ( ! V_126 )
return false ;
F_64 ( L_6 ) ;
F_65 (iommu) {
V_117 = F_4 ( V_2 -> V_6 + V_30 ) ;
V_118 = F_4 ( V_2 -> V_6 + V_30 + 4 ) ;
V_24 = ( ( ( T_4 ) V_118 ) << 32 ) + V_117 ;
if ( V_114 && V_114 != V_24 ) {
F_28 ( L_7 ,
V_2 -> V_127 ) ;
return false ;
}
V_114 = V_24 ;
V_119 = ( ( V_24 & ~ V_21 ) + 1 ) << 12 ;
if ( V_119 != V_29 ) {
F_28 ( L_8 ,
V_2 -> V_127 ) ;
return false ;
}
}
V_120 = V_24 & V_21 ;
if ( V_120 >= 0x100000000ULL ) {
F_28 ( L_9 ) ;
return false ;
}
V_116 = F_66 ( V_120 , V_29 , V_128 ) ;
if ( ! V_116 )
return false ;
V_124 = V_68 | V_69 | V_129 ;
V_130 = ( void * ) F_40 ( V_124 ,
F_7 ( V_29 ) ) ;
if ( V_130 == NULL ) {
F_28 ( L_10 ) ;
return false ;
}
for ( V_9 = 0 ; V_9 <= V_10 ; ++ V_9 ) {
V_130 [ V_9 ] = V_116 [ V_9 ] ;
V_121 = V_116 [ V_9 ] . V_111 [ 1 ] & V_131 ;
V_122 = V_116 [ V_9 ] . V_111 [ 0 ] & V_132 ;
if ( V_122 && V_121 ) {
V_130 [ V_9 ] . V_111 [ 0 ] = V_116 [ V_9 ] . V_111 [ 0 ] ;
V_130 [ V_9 ] . V_111 [ 1 ] = V_116 [ V_9 ] . V_111 [ 1 ] ;
F_67 ( V_121 , V_133 ) ;
if ( V_116 [ V_9 ] . V_111 [ 0 ] & V_134 ) {
V_125 = F_68 ( ~ 0ULL ) << V_135 ;
V_125 |= F_69 ( ~ 0ULL ) << V_136 ;
V_130 [ V_9 ] . V_111 [ 1 ] &= ~ V_125 ;
V_125 = F_70 ( ~ 0ULL ) << V_137 ;
V_125 |= V_134 ;
V_130 [ V_9 ] . V_111 [ 0 ] &= ~ V_125 ;
}
}
V_123 = V_116 [ V_9 ] . V_111 [ 2 ] & V_138 ;
V_112 = V_116 [ V_9 ] . V_111 [ 2 ] & V_139 ;
V_113 = V_116 [ V_9 ] . V_111 [ 2 ] & V_140 ;
if ( V_123 && ( V_112 || V_113 ) ) {
if ( ( V_112 != V_141 ) ||
( V_113 != V_142 ) ) {
F_28 ( L_11 , V_9 ) ;
return false ;
}
V_130 [ V_9 ] . V_111 [ 2 ] = V_116 [ V_9 ] . V_111 [ 2 ] ;
}
}
F_71 ( V_116 ) ;
return true ;
}
void F_72 ( T_2 V_9 )
{
int V_143 ;
V_143 = F_62 ( V_9 , V_144 ) |
( F_62 ( V_9 , V_145 ) << 1 ) ;
if ( V_143 == 0x01 )
F_61 ( V_9 , V_146 ) ;
}
static void T_6 F_73 ( struct V_1 * V_2 , T_2 V_9 )
{
V_147 [ V_9 ] = V_2 ;
}
static void T_6 F_74 ( struct V_1 * V_2 ,
T_2 V_9 , T_1 V_3 , T_1 V_148 )
{
if ( V_3 & V_149 )
F_61 ( V_9 , V_150 ) ;
if ( V_3 & V_151 )
F_61 ( V_9 , V_152 ) ;
if ( V_3 & V_153 )
F_61 ( V_9 , V_154 ) ;
if ( V_3 & V_155 )
F_61 ( V_9 , V_144 ) ;
if ( V_3 & V_156 )
F_61 ( V_9 , V_145 ) ;
if ( V_3 & V_157 )
F_61 ( V_9 , V_158 ) ;
if ( V_3 & V_159 )
F_61 ( V_9 , V_160 ) ;
F_72 ( V_9 ) ;
F_73 ( V_2 , V_9 ) ;
}
static int T_6 F_75 ( T_3 type , T_3 V_161 , T_2 * V_9 , bool V_162 )
{
struct V_163 * V_24 ;
struct V_164 * V_165 ;
if ( type == V_166 )
V_165 = & V_167 ;
else if ( type == V_168 )
V_165 = & V_169 ;
else
return - V_51 ;
F_76 (entry, list, list) {
if ( ! ( V_24 -> V_161 == V_161 && V_24 -> V_162 ) )
continue;
F_77 ( L_12 ,
type == V_166 ? L_13 : L_14 , V_161 ) ;
* V_9 = V_24 -> V_9 ;
return 0 ;
}
V_24 = F_78 ( sizeof( * V_24 ) , V_68 ) ;
if ( ! V_24 )
return - V_71 ;
V_24 -> V_161 = V_161 ;
V_24 -> V_9 = * V_9 ;
V_24 -> V_162 = V_162 ;
F_79 ( & V_24 -> V_165 , V_165 ) ;
return 0 ;
}
static int T_6 F_80 ( T_3 * V_170 , T_3 * V_171 , T_2 * V_9 ,
bool V_162 )
{
struct V_172 * V_24 ;
struct V_164 * V_165 = & V_173 ;
F_76 (entry, list, list) {
if ( strcmp ( V_24 -> V_170 , V_170 ) ||
( * V_171 && * V_24 -> V_171 && strcmp ( V_24 -> V_171 , V_171 ) ) ||
! V_24 -> V_162 )
continue;
F_77 ( L_15 ,
V_170 , V_171 ) ;
* V_9 = V_24 -> V_9 ;
return 0 ;
}
V_24 = F_78 ( sizeof( * V_24 ) , V_68 ) ;
if ( ! V_24 )
return - V_71 ;
memcpy ( V_24 -> V_171 , V_171 , strlen ( V_171 ) ) ;
memcpy ( V_24 -> V_170 , V_170 , strlen ( V_170 ) ) ;
V_24 -> V_9 = * V_9 ;
V_24 -> V_162 = V_162 ;
V_24 -> V_174 = ( V_24 -> V_9 & ( ~ 0x7 ) ) ;
F_77 ( L_16 ,
V_24 -> V_162 ? L_17 : L_18 ,
V_24 -> V_170 , V_24 -> V_171 , V_24 -> V_174 ) ;
F_79 ( & V_24 -> V_165 , V_165 ) ;
return 0 ;
}
static int T_6 F_81 ( void )
{
int V_60 , V_66 ;
for ( V_60 = 0 ; V_60 < V_175 ; ++ V_60 ) {
V_66 = F_75 ( V_166 ,
V_176 [ V_60 ] . V_161 ,
& V_176 [ V_60 ] . V_9 ,
V_176 [ V_60 ] . V_162 ) ;
if ( V_66 )
return V_66 ;
}
for ( V_60 = 0 ; V_60 < V_177 ; ++ V_60 ) {
V_66 = F_75 ( V_168 ,
V_178 [ V_60 ] . V_161 ,
& V_178 [ V_60 ] . V_9 ,
V_178 [ V_60 ] . V_162 ) ;
if ( V_66 )
return V_66 ;
}
for ( V_60 = 0 ; V_60 < V_179 ; ++ V_60 ) {
V_66 = F_80 ( V_180 [ V_60 ] . V_170 ,
V_180 [ V_60 ] . V_171 ,
& V_180 [ V_60 ] . V_9 ,
V_180 [ V_60 ] . V_162 ) ;
if ( V_66 )
return V_66 ;
}
return 0 ;
}
static void T_6 F_82 ( T_2 V_9 , struct V_181 * V_182 )
{
struct V_1 * V_2 = V_147 [ V_9 ] ;
if ( ! ( V_182 -> V_3 & V_183 ) )
return;
if ( V_2 ) {
F_61 ( V_9 , V_184 ) ;
V_2 -> V_20 = V_182 -> V_185 ;
V_2 -> V_23 = V_182 -> V_186 ;
}
}
static int T_6 F_83 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
T_3 * V_49 = ( T_3 * ) V_44 ;
T_3 * V_40 = V_49 , V_3 = 0 ;
T_2 V_9 = 0 , V_187 = 0 , V_188 = 0 ;
T_1 V_189 , V_148 = 0 ;
bool V_190 = false ;
struct V_47 * V_191 ;
T_1 V_50 ;
int V_66 ;
V_66 = F_81 () ;
if ( V_66 )
return V_66 ;
V_2 -> V_192 = V_44 -> V_3 ;
V_50 = F_33 ( V_44 ) ;
if ( ! V_50 ) {
F_28 ( L_4 , V_44 -> type ) ;
return - V_51 ;
}
V_49 += V_50 ;
V_40 += V_44 -> V_52 ;
while ( V_49 < V_40 ) {
V_191 = (struct V_47 * ) V_49 ;
switch ( V_191 -> type ) {
case V_53 :
F_84 ( L_19 , V_191 -> V_3 ) ;
for ( V_189 = 0 ; V_189 <= V_10 ; ++ V_189 )
F_74 ( V_2 , V_189 , V_191 -> V_3 , 0 ) ;
break;
case V_54 :
F_84 ( L_20
L_21 ,
F_85 ( V_191 -> V_9 ) ,
F_86 ( V_191 -> V_9 ) ,
F_87 ( V_191 -> V_9 ) ,
V_191 -> V_3 ) ;
V_9 = V_191 -> V_9 ;
F_74 ( V_2 , V_9 , V_191 -> V_3 , 0 ) ;
break;
case V_193 :
F_84 ( L_22
L_23 ,
F_85 ( V_191 -> V_9 ) ,
F_86 ( V_191 -> V_9 ) ,
F_87 ( V_191 -> V_9 ) ,
V_191 -> V_3 ) ;
V_187 = V_191 -> V_9 ;
V_3 = V_191 -> V_3 ;
V_148 = 0 ;
V_190 = false ;
break;
case V_56 :
F_84 ( L_24
L_25 ,
F_85 ( V_191 -> V_9 ) ,
F_86 ( V_191 -> V_9 ) ,
F_87 ( V_191 -> V_9 ) ,
V_191 -> V_3 ,
F_85 ( V_191 -> V_194 >> 8 ) ,
F_86 ( V_191 -> V_194 >> 8 ) ,
F_87 ( V_191 -> V_194 >> 8 ) ) ;
V_9 = V_191 -> V_9 ;
V_188 = V_191 -> V_194 >> 8 ;
F_74 ( V_2 , V_9 , V_191 -> V_3 , 0 ) ;
F_74 ( V_2 , V_188 , V_191 -> V_3 , 0 ) ;
V_195 [ V_9 ] = V_188 ;
break;
case V_196 :
F_84 ( L_26
L_27
L_28 ,
F_85 ( V_191 -> V_9 ) ,
F_86 ( V_191 -> V_9 ) ,
F_87 ( V_191 -> V_9 ) ,
V_191 -> V_3 ,
F_85 ( V_191 -> V_194 >> 8 ) ,
F_86 ( V_191 -> V_194 >> 8 ) ,
F_87 ( V_191 -> V_194 >> 8 ) ) ;
V_187 = V_191 -> V_9 ;
V_3 = V_191 -> V_3 ;
V_188 = V_191 -> V_194 >> 8 ;
V_148 = 0 ;
V_190 = true ;
break;
case V_57 :
F_84 ( L_29
L_30 ,
F_85 ( V_191 -> V_9 ) ,
F_86 ( V_191 -> V_9 ) ,
F_87 ( V_191 -> V_9 ) ,
V_191 -> V_3 , V_191 -> V_194 ) ;
V_9 = V_191 -> V_9 ;
F_74 ( V_2 , V_9 , V_191 -> V_3 ,
V_191 -> V_194 ) ;
break;
case V_197 :
F_84 ( L_31
L_32 ,
F_85 ( V_191 -> V_9 ) ,
F_86 ( V_191 -> V_9 ) ,
F_87 ( V_191 -> V_9 ) ,
V_191 -> V_3 , V_191 -> V_194 ) ;
V_187 = V_191 -> V_9 ;
V_3 = V_191 -> V_3 ;
V_148 = V_191 -> V_194 ;
V_190 = false ;
break;
case V_55 :
F_84 ( L_33 ,
F_85 ( V_191 -> V_9 ) ,
F_86 ( V_191 -> V_9 ) ,
F_87 ( V_191 -> V_9 ) ) ;
V_9 = V_191 -> V_9 ;
for ( V_189 = V_187 ; V_189 <= V_9 ; ++ V_189 ) {
if ( V_190 ) {
V_195 [ V_189 ] = V_188 ;
F_74 ( V_2 ,
V_188 , V_3 , V_148 ) ;
}
F_74 ( V_2 , V_189 ,
V_3 , V_148 ) ;
}
break;
case V_198 : {
T_3 V_199 , type ;
const char * V_200 ;
T_2 V_9 ;
int V_66 ;
V_199 = V_191 -> V_194 & 0xff ;
V_9 = ( V_191 -> V_194 >> 8 ) & 0xffff ;
type = ( V_191 -> V_194 >> 24 ) & 0xff ;
if ( type == V_166 )
V_200 = L_13 ;
else if ( type == V_168 )
V_200 = L_14 ;
else
V_200 = L_34 ;
F_84 ( L_35 ,
V_200 , ( int ) V_199 ,
F_85 ( V_9 ) ,
F_86 ( V_9 ) ,
F_87 ( V_9 ) ) ;
V_66 = F_75 ( type , V_199 , & V_9 , false ) ;
if ( V_66 )
return V_66 ;
F_74 ( V_2 , V_9 , V_191 -> V_3 , 0 ) ;
break;
}
case V_48 : {
T_2 V_9 ;
T_3 V_170 [ V_201 ] = { 0 } ;
T_3 V_171 [ V_202 ] = { 0 } ;
int V_66 ;
if ( V_44 -> type != 0x40 ) {
F_28 ( V_62 L_36 ,
V_191 -> type ) ;
break;
}
memcpy ( V_170 , ( T_3 * ) ( & V_191 -> V_194 ) , V_201 - 1 ) ;
V_170 [ V_201 - 1 ] = '\0' ;
if ( ! ( * V_170 ) ) {
F_28 ( V_62 L_37 ) ;
break;
}
switch ( V_191 -> V_203 ) {
case V_204 :
if ( V_191 -> V_205 != 0 )
F_64 ( V_62 L_38 ) ;
break;
case V_206 :
sprintf ( V_171 , L_39 , V_191 -> V_171 ) ;
break;
case V_207 :
memcpy ( V_171 , ( T_3 * ) ( & V_191 -> V_171 ) , V_202 - 1 ) ;
V_171 [ V_202 - 1 ] = '\0' ;
break;
default:
break;
}
V_9 = V_191 -> V_9 ;
F_84 ( L_40 ,
V_170 , V_171 ,
F_85 ( V_9 ) ,
F_86 ( V_9 ) ,
F_87 ( V_9 ) ) ;
V_3 = V_191 -> V_3 ;
V_66 = F_80 ( V_170 , V_171 , & V_9 , false ) ;
if ( V_66 )
return V_66 ;
F_74 ( V_2 , V_9 , V_191 -> V_3 , 0 ) ;
break;
}
default:
break;
}
V_49 += F_34 ( V_49 ) ;
}
return 0 ;
}
static void T_6 F_88 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
F_49 ( V_2 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static void T_6 F_89 ( void )
{
struct V_1 * V_2 , * V_208 ;
F_90 (iommu, next) {
F_91 ( & V_2 -> V_165 ) ;
F_88 ( V_2 ) ;
F_92 ( V_2 ) ;
}
}
static void F_93 ( struct V_1 * V_2 )
{
T_1 V_209 ;
if ( ( V_210 . V_211 != 0x15 ) ||
( V_210 . V_212 < 0x10 ) ||
( V_210 . V_212 > 0x1f ) )
return;
F_10 ( V_2 -> V_18 , 0xf0 , 0x90 ) ;
F_11 ( V_2 -> V_18 , 0xf4 , & V_209 ) ;
if ( V_209 & F_94 ( 2 ) )
return;
F_10 ( V_2 -> V_18 , 0xf0 , 0x90 | ( 1 << 8 ) ) ;
F_10 ( V_2 -> V_18 , 0xf4 , V_209 | 0x4 ) ;
F_77 ( L_41 ,
F_95 ( & V_2 -> V_18 -> V_18 ) ) ;
F_10 ( V_2 -> V_18 , 0xf0 , 0x90 ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
T_1 V_209 ;
if ( ( V_210 . V_211 != 0x15 ) ||
( V_210 . V_212 < 0x30 ) ||
( V_210 . V_212 > 0x3f ) )
return;
V_209 = F_13 ( V_2 , 0x47 ) ;
if ( V_209 & F_94 ( 0 ) )
return;
F_14 ( V_2 , 0x47 , V_209 | F_94 ( 0 ) ) ;
F_77 ( L_42 ,
F_95 ( & V_2 -> V_18 -> V_18 ) ) ;
}
static int T_6 F_97 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
int V_66 ;
F_98 ( & V_2 -> V_213 ) ;
F_79 ( & V_2 -> V_165 , & V_214 ) ;
V_2 -> V_127 = V_14 ++ ;
if ( F_99 ( V_2 -> V_127 >= V_215 ) ) {
F_100 ( 1 , L_43 ) ;
return - V_216 ;
}
V_217 [ V_2 -> V_127 ] = V_2 ;
V_2 -> V_9 = V_44 -> V_9 ;
V_2 -> V_218 = V_44 -> V_218 ;
V_2 -> V_219 = V_44 -> V_219 ;
V_2 -> V_41 = V_44 -> V_41 ;
switch ( V_44 -> type ) {
case 0x10 :
if ( ( V_44 -> V_220 != 0 ) &&
( ( V_44 -> V_220 & ( 0xF << 13 ) ) != 0 ) &&
( ( V_44 -> V_220 & ( 0x3F << 17 ) ) != 0 ) )
V_2 -> V_42 = V_221 ;
else
V_2 -> V_42 = V_222 ;
if ( ( ( V_44 -> V_220 & ( 0x1 << V_223 ) ) == 0 ) )
V_99 = V_224 ;
break;
case 0x11 :
case 0x40 :
if ( V_44 -> V_225 & ( 1 << 9 ) )
V_2 -> V_42 = V_221 ;
else
V_2 -> V_42 = V_222 ;
if ( ( ( V_44 -> V_225 & ( 0x1 << V_226 ) ) == 0 ) )
V_99 = V_224 ;
break;
default:
return - V_51 ;
}
V_2 -> V_6 = F_26 ( V_2 -> V_41 ,
V_2 -> V_42 ) ;
if ( ! V_2 -> V_6 )
return - V_71 ;
if ( F_39 ( V_2 ) )
return - V_71 ;
if ( F_46 ( V_2 ) )
return - V_71 ;
V_2 -> V_227 = false ;
F_3 ( V_2 ) ;
if ( F_1 ( V_2 ) && ! F_101 () ) {
F_25 ( V_2 ) ;
F_2 ( V_2 ) ;
F_64 ( L_44 ,
V_2 -> V_127 ) ;
}
if ( V_126 )
V_126 = F_1 ( V_2 ) ;
V_66 = F_83 ( V_2 , V_44 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_102 ( V_2 ) ;
if ( V_66 )
return V_66 ;
V_147 [ V_2 -> V_9 ] = NULL ;
return 0 ;
}
static T_3 F_103 ( struct V_58 * V_228 )
{
T_3 * V_229 = ( T_3 * ) V_228 ;
struct V_43 * V_46 = (struct V_43 * )
( V_229 + V_64 ) ;
T_3 V_230 = V_46 -> type ;
T_2 V_9 = V_46 -> V_9 ;
while ( ( ( T_3 * ) V_46 - V_229 < V_228 -> V_52 ) &&
( V_46 -> type <= V_231 ) ) {
T_3 * V_49 = ( T_3 * ) V_46 ;
if ( V_46 -> V_9 == V_9 )
V_230 = V_46 -> type ;
V_46 = (struct V_43 * ) ( V_49 + V_46 -> V_52 ) ;
}
return V_230 ;
}
static int T_6 F_104 ( struct V_58 * V_59 )
{
T_3 * V_49 = ( T_3 * ) V_59 , * V_40 = ( T_3 * ) V_59 ;
struct V_43 * V_44 ;
struct V_1 * V_2 ;
int V_66 ;
V_40 += V_59 -> V_52 ;
V_49 += V_64 ;
while ( V_49 < V_40 ) {
V_44 = (struct V_43 * ) V_49 ;
if ( * V_49 == V_65 ) {
F_84 ( L_45
L_46 ,
F_85 ( V_44 -> V_9 ) , F_86 ( V_44 -> V_9 ) ,
F_87 ( V_44 -> V_9 ) , V_44 -> V_218 ,
V_44 -> V_219 , V_44 -> V_3 , V_44 -> V_232 ) ;
F_84 ( L_47 ,
V_44 -> V_41 ) ;
V_2 = F_78 ( sizeof( struct V_1 ) , V_68 ) ;
if ( V_2 == NULL )
return - V_71 ;
V_66 = F_97 ( V_2 , V_44 ) ;
if ( V_66 )
return V_66 ;
}
V_49 += V_44 -> V_52 ;
}
F_36 ( V_49 != V_40 ) ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_4 V_17 = 0xabcd , V_233 = 0 ;
if ( ! F_59 ( V_2 , V_234 ) )
return;
V_235 = true ;
if ( ( F_106 ( V_2 , 0 , 0 , 0 , & V_17 , true ) ) ||
( F_106 ( V_2 , 0 , 0 , 0 , & V_233 , false ) ) ||
( V_17 != V_233 ) ) {
F_28 ( L_48 ) ;
V_235 = false ;
return;
}
F_77 ( L_49 ) ;
V_17 = F_4 ( V_2 -> V_6 + V_222 ) ;
V_2 -> V_236 = ( T_3 ) ( ( V_17 >> 12 ) & 0x3f ) ;
V_2 -> V_237 = ( T_3 ) ( ( V_17 >> 7 ) & 0xf ) ;
}
static T_9 F_107 ( struct V_238 * V_18 ,
struct V_239 * V_240 ,
char * V_241 )
{
struct V_1 * V_2 = F_108 ( V_18 ) ;
return sprintf ( V_241 , L_50 , V_2 -> V_242 ) ;
}
static T_9 F_109 ( struct V_238 * V_18 ,
struct V_239 * V_240 ,
char * V_241 )
{
struct V_1 * V_2 = F_108 ( V_18 ) ;
return sprintf ( V_241 , L_51 , V_2 -> V_243 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_218 = V_2 -> V_218 ;
T_1 V_244 , V_245 , V_246 , V_247 ;
int V_66 ;
V_2 -> V_18 = F_111 ( F_85 ( V_2 -> V_9 ) ,
V_2 -> V_9 & 0xff ) ;
if ( ! V_2 -> V_18 )
return - V_63 ;
V_2 -> V_18 -> V_248 = false ;
F_11 ( V_2 -> V_18 , V_218 + V_249 ,
& V_2 -> V_242 ) ;
F_11 ( V_2 -> V_18 , V_218 + V_250 ,
& V_244 ) ;
F_11 ( V_2 -> V_18 , V_218 + V_251 ,
& V_245 ) ;
if ( ! ( V_2 -> V_242 & ( 1 << V_252 ) ) )
V_253 = false ;
V_246 = F_4 ( V_2 -> V_6 + V_254 ) ;
V_247 = F_4 ( V_2 -> V_6 + V_254 + 4 ) ;
V_2 -> V_243 = ( ( T_4 ) V_247 << 32 ) | V_246 ;
if ( F_59 ( V_2 , V_108 ) ) {
int V_255 ;
T_1 V_256 ;
T_4 V_257 ;
V_257 = V_2 -> V_243 & V_258 ;
V_257 >>= V_259 ;
V_256 = ( 1 << ( V_257 + 1 ) ) - 1 ;
V_260 = F_112 ( V_260 , V_256 ) ;
F_18 ( V_260 & ~ V_261 ) ;
V_255 = V_2 -> V_243 & V_262 ;
V_255 >>= V_263 ;
if ( V_264 == - 1 )
V_264 = V_255 ;
else
V_264 = F_112 ( V_264 , V_255 ) ;
}
if ( F_59 ( V_2 , V_108 ) &&
F_59 ( V_2 , V_265 ) ) {
V_2 -> V_266 = true ;
V_267 = true ;
}
if ( F_59 ( V_2 , V_265 ) && F_50 ( V_2 ) )
return - V_71 ;
V_66 = F_58 ( V_2 ) ;
if ( V_66 )
return V_66 ;
if ( V_2 -> V_242 & ( 1UL << V_268 ) )
V_269 = true ;
F_105 ( V_2 ) ;
if ( F_113 ( V_2 -> V_18 ) ) {
int V_60 , V_270 ;
V_2 -> V_271 = F_111 ( V_2 -> V_18 -> V_272 -> V_273 ,
F_114 ( 0 , 0 ) ) ;
F_11 ( V_2 -> V_18 , V_2 -> V_218 + 4 ,
& V_2 -> V_274 ) ;
F_11 ( V_2 -> V_18 , V_2 -> V_218 + 8 ,
& V_2 -> V_275 ) ;
V_2 -> V_274 &= ~ 1 ;
for ( V_60 = 0 ; V_60 < 6 ; V_60 ++ )
for ( V_270 = 0 ; V_270 < 0x12 ; V_270 ++ )
V_2 -> V_276 [ V_60 ] [ V_270 ] = F_9 ( V_2 , V_60 , V_270 ) ;
for ( V_60 = 0 ; V_60 < 0x83 ; V_60 ++ )
V_2 -> V_277 [ V_60 ] = F_13 ( V_2 , V_60 ) ;
}
F_93 ( V_2 ) ;
F_96 ( V_2 ) ;
F_115 ( & V_2 -> V_2 , & V_2 -> V_18 -> V_18 ,
V_278 , L_52 , V_2 -> V_127 ) ;
F_116 ( & V_2 -> V_2 , & V_279 ) ;
F_117 ( & V_2 -> V_2 ) ;
return F_118 ( V_2 -> V_18 ) ;
}
static void F_119 ( void )
{
static const char * const V_280 [] = {
L_53 , L_54 , L_55 , L_56 , L_57 , L_58 ,
L_59 , L_60 , L_61 , L_62
} ;
struct V_1 * V_2 ;
F_65 (iommu) {
int V_60 ;
F_77 ( L_63 ,
F_95 ( & V_2 -> V_18 -> V_18 ) , V_2 -> V_218 ) ;
if ( V_2 -> V_242 & ( 1 << V_281 ) ) {
F_77 ( L_64 ,
V_2 -> V_243 ) ;
for ( V_60 = 0 ; V_60 < F_120 ( V_280 ) ; ++ V_60 ) {
if ( F_59 ( V_2 , ( 1ULL << V_60 ) ) )
F_121 ( L_65 , V_280 [ V_60 ] ) ;
}
if ( V_2 -> V_243 & V_106 )
F_121 ( L_66 ) ;
F_121 ( L_67 ) ;
}
}
if ( V_282 ) {
F_77 ( L_68 ) ;
if ( F_57 ( V_99 ) )
F_77 ( L_69 ) ;
}
}
static int T_6 F_122 ( void )
{
struct V_1 * V_2 ;
int V_66 = 0 ;
F_65 (iommu) {
V_66 = F_110 ( V_2 ) ;
if ( V_66 )
break;
}
V_66 = F_123 () ;
F_124 () ;
F_65 (iommu)
F_125 ( V_2 ) ;
if ( ! V_66 )
F_119 () ;
return V_66 ;
}
static int F_126 ( struct V_1 * V_2 )
{
int V_283 ;
V_283 = F_127 ( V_2 -> V_18 ) ;
if ( V_283 )
return V_283 ;
V_283 = F_128 ( V_2 -> V_18 -> V_284 ,
V_285 ,
V_286 ,
0 , L_70 ,
V_2 ) ;
if ( V_283 ) {
F_129 ( V_2 -> V_18 ) ;
return V_283 ;
}
V_2 -> V_227 = true ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 )
{
int V_66 ;
if ( V_2 -> V_227 )
goto V_287;
if ( V_2 -> V_18 -> V_288 )
V_66 = F_126 ( V_2 ) ;
else
V_66 = - V_63 ;
if ( V_66 )
return V_66 ;
V_287:
F_20 ( V_2 , V_36 ) ;
if ( V_2 -> V_84 != NULL )
F_20 ( V_2 , V_289 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static void T_6 F_131 ( void )
{
struct V_290 * V_24 , * V_208 ;
F_132 (entry, next, &amd_iommu_unity_map, list) {
F_91 ( & V_24 -> V_165 ) ;
F_92 ( V_24 ) ;
}
}
static int T_6 F_133 ( struct V_181 * V_182 )
{
int V_60 ;
switch ( V_182 -> type ) {
case V_291 :
F_82 ( V_182 -> V_9 , V_182 ) ;
break;
case V_292 :
for ( V_60 = 0 ; V_60 <= V_10 ; ++ V_60 )
F_82 ( V_60 , V_182 ) ;
break;
case V_293 :
for ( V_60 = V_182 -> V_9 ; V_60 <= V_182 -> V_294 ; ++ V_60 )
F_82 ( V_60 , V_182 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_134 ( struct V_181 * V_182 )
{
struct V_290 * V_191 = NULL ;
char * V_295 ;
V_191 = F_78 ( sizeof( * V_191 ) , V_68 ) ;
if ( V_191 == NULL )
return - V_71 ;
switch ( V_182 -> type ) {
default:
F_92 ( V_191 ) ;
return 0 ;
case V_291 :
V_295 = L_71 ;
V_191 -> V_187 = V_191 -> V_296 = V_182 -> V_9 ;
break;
case V_292 :
V_295 = L_72 ;
V_191 -> V_187 = 0 ;
V_191 -> V_296 = V_10 ;
break;
case V_293 :
V_295 = L_73 ;
V_191 -> V_187 = V_182 -> V_9 ;
V_191 -> V_296 = V_182 -> V_294 ;
break;
}
V_191 -> V_297 = F_135 ( V_182 -> V_185 ) ;
V_191 -> V_298 = V_191 -> V_297 + F_135 ( V_182 -> V_186 ) ;
V_191 -> V_299 = V_182 -> V_3 >> 1 ;
F_84 ( L_74
L_75 , V_295 ,
F_85 ( V_191 -> V_187 ) , F_86 ( V_191 -> V_187 ) ,
F_87 ( V_191 -> V_187 ) , F_85 ( V_191 -> V_296 ) ,
F_86 ( V_191 -> V_296 ) , F_87 ( V_191 -> V_296 ) ,
V_191 -> V_297 , V_191 -> V_298 , V_182 -> V_3 ) ;
F_79 ( & V_191 -> V_165 , & V_300 ) ;
return 0 ;
}
static int T_6 F_136 ( struct V_58 * V_59 )
{
T_3 * V_49 = ( T_3 * ) V_59 , * V_40 = ( T_3 * ) V_59 ;
struct V_181 * V_182 ;
V_40 += V_59 -> V_52 ;
V_49 += V_64 ;
while ( V_49 < V_40 ) {
V_182 = (struct V_181 * ) V_49 ;
if ( V_182 -> V_3 & V_183 )
F_133 ( V_182 ) ;
else if ( V_182 -> V_3 & V_301 )
F_134 ( V_182 ) ;
V_49 += V_182 -> V_52 ;
}
return 0 ;
}
static void F_124 ( void )
{
T_1 V_9 ;
for ( V_9 = 0 ; V_9 <= V_10 ; ++ V_9 ) {
F_61 ( V_9 , V_302 ) ;
F_61 ( V_9 , V_303 ) ;
}
}
static void T_6 F_137 ( void )
{
T_1 V_9 ;
for ( V_9 = 0 ; V_9 <= V_10 ; ++ V_9 ) {
V_28 [ V_9 ] . V_111 [ 0 ] = 0ULL ;
V_28 [ V_9 ] . V_111 [ 1 ] = 0ULL ;
}
}
static void F_138 ( void )
{
T_1 V_9 ;
if ( ! V_304 )
return;
for ( V_9 = 0 ; V_9 <= V_10 ; ++ V_9 )
F_61 ( V_9 , V_305 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
V_2 -> V_192 & V_306 ?
F_20 ( V_2 , V_307 ) :
F_22 ( V_2 , V_307 ) ;
V_2 -> V_192 & V_308 ?
F_20 ( V_2 , V_309 ) :
F_22 ( V_2 , V_309 ) ;
V_2 -> V_192 & V_310 ?
F_20 ( V_2 , V_311 ) :
F_22 ( V_2 , V_311 ) ;
V_2 -> V_192 & V_312 ?
F_20 ( V_2 , V_313 ) :
F_22 ( V_2 , V_313 ) ;
F_20 ( V_2 , V_314 ) ;
F_23 ( V_2 , V_315 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
int V_60 , V_270 ;
T_1 V_316 ;
struct V_317 * V_318 = V_2 -> V_271 ;
if ( ! F_113 ( V_2 -> V_18 ) || ! V_318 )
return;
F_10 ( V_318 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_11 ( V_318 , 0x64 , & V_316 ) ;
if ( ! ( V_316 & 0x1 ) )
F_10 ( V_318 , 0x64 , V_316 | 1 ) ;
F_10 ( V_2 -> V_18 , V_2 -> V_218 + 4 ,
V_2 -> V_274 ) ;
F_10 ( V_2 -> V_18 , V_2 -> V_218 + 8 ,
V_2 -> V_275 ) ;
for ( V_60 = 0 ; V_60 < 6 ; V_60 ++ )
for ( V_270 = 0 ; V_270 < 0x12 ; V_270 ++ )
F_12 ( V_2 , V_60 , V_270 , V_2 -> V_276 [ V_60 ] [ V_270 ] ) ;
for ( V_60 = 0 ; V_60 < 0x83 ; V_60 ++ )
F_14 ( V_2 , V_60 , V_2 -> V_277 [ V_60 ] ) ;
F_10 ( V_2 -> V_18 , V_2 -> V_218 + 4 ,
V_2 -> V_274 | 1 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
#ifdef F_54
switch ( V_99 ) {
case F_57 :
F_20 ( V_2 , V_319 ) ;
case V_107 :
F_20 ( V_2 , V_320 ) ;
V_2 -> V_321 = & V_322 ;
break;
default:
V_2 -> V_321 = & V_323 ;
break;
}
#endif
}
static void F_142 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_139 ( V_2 ) ;
F_17 ( V_2 ) ;
F_42 ( V_2 ) ;
F_47 ( V_2 ) ;
F_15 ( V_2 ) ;
F_141 ( V_2 ) ;
F_24 ( V_2 ) ;
F_125 ( V_2 ) ;
}
static void F_143 ( void )
{
struct V_1 * V_2 ;
if ( ! F_63 () ) {
if ( V_126 )
F_28 ( L_76 ) ;
if ( V_130 != NULL )
F_45 ( ( unsigned long ) V_130 ,
F_7 ( V_29 ) ) ;
F_65 (iommu) {
F_2 ( V_2 ) ;
F_142 ( V_2 ) ;
}
} else {
F_77 ( L_77 ) ;
F_45 ( ( unsigned long ) V_28 ,
F_7 ( V_29 ) ) ;
V_28 = V_130 ;
F_65 (iommu) {
F_43 ( V_2 ) ;
F_48 ( V_2 ) ;
F_42 ( V_2 ) ;
F_47 ( V_2 ) ;
F_141 ( V_2 ) ;
F_17 ( V_2 ) ;
F_125 ( V_2 ) ;
}
}
#ifdef F_54
if ( F_57 ( V_99 ) )
V_324 . V_325 |= ( 1 << V_326 ) ;
#endif
}
static void F_144 ( void )
{
struct V_1 * V_2 ;
F_65 (iommu) {
F_51 ( V_2 ) ;
F_60 ( V_2 ) ;
}
}
static void F_145 ( void )
{
F_143 () ;
F_144 () ;
}
static void F_146 ( void )
{
struct V_1 * V_2 ;
F_65 (iommu)
F_25 ( V_2 ) ;
#ifdef F_54
if ( F_57 ( V_99 ) )
V_324 . V_325 &= ~ ( 1 << V_326 ) ;
#endif
}
static void F_147 ( void )
{
struct V_1 * V_2 ;
F_65 (iommu)
F_140 ( V_2 ) ;
F_145 () ;
F_148 () ;
}
static int F_149 ( void )
{
F_146 () ;
return 0 ;
}
static void T_6 F_150 ( void )
{
F_151 ( V_327 ) ;
F_45 ( ( unsigned long ) V_327 ,
F_7 ( V_328 ) ) ;
V_327 = NULL ;
F_152 ( V_329 ) ;
V_329 = NULL ;
F_45 ( ( unsigned long ) V_147 ,
F_7 ( V_328 ) ) ;
V_147 = NULL ;
F_45 ( ( unsigned long ) V_195 ,
F_7 ( V_330 ) ) ;
V_195 = NULL ;
F_45 ( ( unsigned long ) V_28 ,
F_7 ( V_29 ) ) ;
V_28 = NULL ;
F_89 () ;
#ifdef F_153
F_154 () ;
#endif
}
static bool T_6 F_155 ( void )
{
const char * V_331 = V_62 ;
bool V_66 , V_332 ;
int V_333 ;
V_332 = false ;
V_66 = false ;
if ( V_334 )
V_331 = L_78 ;
for ( V_333 = 0 ; V_333 < V_335 ; V_333 ++ ) {
int V_9 , V_161 = F_156 ( V_333 ) ;
V_9 = F_157 ( V_161 ) ;
if ( V_9 < 0 ) {
F_28 ( L_79 ,
V_331 , V_161 ) ;
V_66 = false ;
} else if ( V_9 == V_336 ) {
V_332 = true ;
V_66 = true ;
}
}
if ( ! V_332 ) {
F_28 ( L_80 , V_331 ) ;
}
if ( ! V_66 )
F_28 ( L_81 ) ;
return V_66 ;
}
static void T_6 F_158 ( void )
{
F_45 ( ( unsigned long ) V_133 ,
F_7 ( V_337 / 8 ) ) ;
V_133 = NULL ;
F_131 () ;
}
static int T_6 F_159 ( void )
{
struct V_58 * V_338 ;
T_10 V_95 ;
int V_60 , V_339 , V_66 = 0 ;
if ( ! V_340 )
return - V_63 ;
V_95 = F_160 ( L_82 , 0 , & V_338 ) ;
if ( V_95 == V_341 )
return - V_63 ;
else if ( F_161 ( V_95 ) ) {
const char * V_342 = F_162 ( V_95 ) ;
F_28 ( L_83 , V_342 ) ;
return - V_51 ;
}
V_66 = F_37 ( V_338 ) ;
if ( V_66 )
goto V_343;
V_65 = F_103 ( V_338 ) ;
F_84 ( L_84 , V_65 ) ;
V_66 = F_38 ( V_338 ) ;
if ( V_66 )
goto V_343;
V_29 = F_6 ( V_344 ) ;
V_330 = F_6 ( V_345 ) ;
V_328 = F_6 ( V_346 ) ;
V_66 = - V_71 ;
V_28 = ( void * ) F_40 (
V_68 | V_69 | V_129 ,
F_7 ( V_29 ) ) ;
if ( V_28 == NULL )
goto V_343;
V_195 = ( void * ) F_40 ( V_68 ,
F_7 ( V_330 ) ) ;
if ( V_195 == NULL )
goto V_343;
V_147 = ( void * ) F_40 (
V_68 | V_69 ,
F_7 ( V_328 ) ) ;
if ( V_147 == NULL )
goto V_343;
V_133 = ( void * ) F_40 (
V_68 | V_69 ,
F_7 ( V_337 / 8 ) ) ;
if ( V_133 == NULL )
goto V_343;
for ( V_60 = 0 ; V_60 <= V_10 ; ++ V_60 )
V_195 [ V_60 ] = V_60 ;
F_67 ( 0 , V_133 ) ;
F_98 ( & V_347 ) ;
V_66 = F_104 ( V_338 ) ;
if ( V_66 )
goto V_343;
if ( ! F_101 () || V_348 )
F_146 () ;
if ( V_304 )
V_304 = F_155 () ;
if ( V_304 ) {
V_66 = - V_71 ;
if ( ! F_163 ( V_99 ) )
V_339 = V_349 * sizeof( T_1 ) ;
else
V_339 = V_349 * ( sizeof( T_4 ) * 2 ) ;
V_329 = F_164 ( L_85 ,
V_339 ,
V_350 ,
0 , NULL ) ;
if ( ! V_329 )
goto V_343;
V_327 = ( void * ) F_40 (
V_68 | V_69 ,
F_7 ( V_328 ) ) ;
F_165 ( V_327 , V_328 ,
1 , V_68 ) ;
if ( ! V_327 )
goto V_343;
}
V_66 = F_136 ( V_338 ) ;
if ( V_66 )
goto V_343;
F_138 () ;
V_343:
F_166 ( V_338 ) ;
V_338 = NULL ;
return V_66 ;
}
static int F_148 ( void )
{
struct V_1 * V_2 ;
int V_66 = 0 ;
F_65 (iommu) {
V_66 = F_130 ( V_2 ) ;
if ( V_66 )
goto V_343;
}
V_343:
return V_66 ;
}
static bool F_167 ( void )
{
struct V_58 * V_338 ;
T_10 V_95 ;
V_95 = F_160 ( L_82 , 0 , & V_338 ) ;
if ( V_95 == V_341 )
return false ;
else if ( F_161 ( V_95 ) ) {
const char * V_342 = F_162 ( V_95 ) ;
F_28 ( L_83 , V_342 ) ;
return false ;
}
F_166 ( V_338 ) ;
F_168 () ;
return true ;
}
static int T_6 F_169 ( void )
{
int V_66 = 0 ;
switch ( V_351 ) {
case V_352 :
if ( ! F_167 () ) {
V_351 = V_353 ;
V_66 = - V_63 ;
} else {
V_351 = V_354 ;
}
break;
case V_354 :
V_66 = F_159 () ;
V_351 = V_66 ? V_355 : V_356 ;
if ( V_351 == V_356 && V_348 ) {
F_77 ( L_86 ) ;
F_158 () ;
F_150 () ;
V_351 = V_357 ;
V_66 = - V_51 ;
}
break;
case V_356 :
F_143 () ;
V_358 . V_359 = F_146 ;
V_351 = V_360 ;
break;
case V_360 :
F_170 ( & V_361 ) ;
V_66 = F_122 () ;
V_351 = V_66 ? V_355 : V_362 ;
F_144 () ;
break;
case V_362 :
V_66 = F_148 () ;
V_351 = V_66 ? V_355 : V_363 ;
break;
case V_363 :
V_66 = F_171 () ;
V_351 = V_66 ? V_355 : V_364 ;
break;
case V_364 :
V_351 = V_365 ;
break;
case V_365 :
break;
case V_353 :
case V_355 :
case V_357 :
V_66 = - V_51 ;
break;
default:
F_172 () ;
}
return V_66 ;
}
static int T_6 F_173 ( enum V_366 V_367 )
{
int V_66 = - V_51 ;
while ( V_351 != V_367 ) {
if ( V_351 == V_353 ||
V_351 == V_355 ||
V_351 == V_357 )
break;
V_66 = F_169 () ;
}
return V_66 ;
}
int T_6 F_174 ( void )
{
int V_66 ;
V_304 = true ;
V_66 = F_173 ( V_356 ) ;
if ( V_66 )
return V_66 ;
return V_304 ? 0 : - V_63 ;
}
int T_6 F_175 ( void )
{
int V_66 ;
V_66 = F_173 ( V_360 ) ;
if ( V_66 )
return V_66 ;
V_282 = 1 ;
return 0 ;
}
void F_176 ( void )
{
F_149 () ;
}
int F_177 ( int V_368 )
{
F_147 () ;
return 0 ;
}
int T_6 F_178 ( void )
{
return 0 ;
}
static int T_6 F_179 ( void )
{
int V_66 ;
V_66 = F_173 ( V_365 ) ;
if ( V_66 ) {
F_158 () ;
if ( ! V_282 ) {
F_146 () ;
F_150 () ;
} else {
struct V_1 * V_2 ;
F_137 () ;
F_65 (iommu)
F_125 ( V_2 ) ;
}
}
return V_66 ;
}
static bool F_180 ( void )
{
if ( ! F_181 () || ( V_210 . V_211 != 0x17 ) )
return true ;
if ( V_210 . V_369 >= 0x08001205 )
return true ;
if ( ( V_210 . V_369 >= 0x08001126 ) &&
( V_210 . V_369 <= 0x080011ff ) )
return true ;
F_182 ( L_87 ) ;
return false ;
}
int T_6 F_183 ( void )
{
int V_66 ;
if ( V_370 || ( V_371 && ! V_372 ) )
return - V_63 ;
if ( ! F_180 () )
return - V_63 ;
V_66 = F_173 ( V_354 ) ;
if ( V_66 )
return V_66 ;
V_340 = true ;
V_371 = 1 ;
V_373 . V_2 . V_374 = F_179 ;
return 1 ;
}
static int T_6 F_184 ( char * V_375 )
{
V_376 = true ;
return 1 ;
}
static int T_6 F_185 ( char * V_375 )
{
for (; * V_375 ; ++ V_375 ) {
if ( strncmp ( V_375 , L_88 , 6 ) == 0 ) {
V_99 = V_224 ;
break;
}
if ( strncmp ( V_375 , L_89 , 5 ) == 0 ) {
V_99 = F_57 ;
break;
}
}
return 1 ;
}
static int T_6 F_186 ( char * V_375 )
{
for (; * V_375 ; ++ V_375 ) {
if ( strncmp ( V_375 , L_90 , 9 ) == 0 )
V_377 = true ;
if ( strncmp ( V_375 , L_91 , 3 ) == 0 )
V_348 = true ;
if ( strncmp ( V_375 , L_92 , 15 ) == 0 )
V_378 = true ;
}
return 1 ;
}
static int T_6 F_187 ( char * V_375 )
{
unsigned int V_272 , V_18 , V_379 ;
int V_66 , V_161 , V_60 ;
T_2 V_9 ;
V_66 = sscanf ( V_375 , L_93 , & V_161 , & V_272 , & V_18 , & V_379 ) ;
if ( V_66 != 4 ) {
F_28 ( L_94 , V_375 ) ;
return 1 ;
}
if ( V_175 == V_380 ) {
F_28 ( L_95 ,
V_375 ) ;
return 1 ;
}
V_9 = ( ( V_272 & 0xff ) << 8 ) | ( ( V_18 & 0x1f ) << 3 ) | ( V_379 & 0x7 ) ;
V_334 = true ;
V_60 = V_175 ++ ;
V_176 [ V_60 ] . V_161 = V_161 ;
V_176 [ V_60 ] . V_9 = V_9 ;
V_176 [ V_60 ] . V_162 = true ;
return 1 ;
}
static int T_6 F_188 ( char * V_375 )
{
unsigned int V_272 , V_18 , V_379 ;
int V_66 , V_161 , V_60 ;
T_2 V_9 ;
V_66 = sscanf ( V_375 , L_93 , & V_161 , & V_272 , & V_18 , & V_379 ) ;
if ( V_66 != 4 ) {
F_28 ( L_96 , V_375 ) ;
return 1 ;
}
if ( V_177 == V_380 ) {
F_28 ( L_97 ,
V_375 ) ;
return 1 ;
}
V_9 = ( ( V_272 & 0xff ) << 8 ) | ( ( V_18 & 0x1f ) << 3 ) | ( V_379 & 0x7 ) ;
V_334 = true ;
V_60 = V_177 ++ ;
V_178 [ V_60 ] . V_161 = V_161 ;
V_178 [ V_60 ] . V_9 = V_9 ;
V_178 [ V_60 ] . V_162 = true ;
return 1 ;
}
static int T_6 F_189 ( char * V_375 )
{
T_1 V_272 , V_18 , V_379 ;
char * V_170 , * V_171 , * V_49 ;
char V_381 [ V_202 + V_201 ] = { 0 } ;
int V_66 , V_60 ;
V_66 = sscanf ( V_375 , L_98 , & V_272 , & V_18 , & V_379 , V_381 ) ;
if ( V_66 != 4 ) {
F_28 ( L_99 , V_375 ) ;
return 1 ;
}
V_49 = V_381 ;
V_170 = F_190 ( & V_49 , L_100 ) ;
V_171 = V_49 ;
if ( ! V_170 || ! ( * V_170 ) || ! V_171 ) {
F_28 ( L_101 ) ;
return 1 ;
}
V_60 = V_179 ++ ;
memcpy ( V_180 [ V_60 ] . V_170 , V_170 , strlen ( V_170 ) ) ;
memcpy ( V_180 [ V_60 ] . V_171 , V_171 , strlen ( V_171 ) ) ;
V_180 [ V_60 ] . V_9 =
( ( V_272 & 0xff ) << 8 ) | ( ( V_18 & 0x1f ) << 3 ) | ( V_379 & 0x7 ) ;
V_180 [ V_60 ] . V_162 = true ;
return 1 ;
}
bool F_191 ( void )
{
return V_267 ;
}
struct V_1 * F_192 ( unsigned int V_333 )
{
unsigned int V_60 = 0 ;
struct V_1 * V_2 ;
F_65 (iommu)
if ( V_60 ++ == V_333 )
return V_2 ;
return NULL ;
}
T_3 F_193 ( unsigned int V_333 )
{
struct V_1 * V_2 = F_192 ( V_333 ) ;
if ( V_2 )
return V_2 -> V_236 ;
return 0 ;
}
bool F_194 ( void )
{
return V_235 ;
}
T_3 F_195 ( unsigned int V_333 )
{
struct V_1 * V_2 = F_192 ( V_333 ) ;
if ( V_2 )
return V_2 -> V_237 ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 , T_3 V_382 , T_3 V_383 ,
T_3 V_384 , T_4 * V_209 , bool V_385 )
{
T_1 V_386 ;
T_1 V_387 ;
if ( ! V_235 )
return - V_63 ;
if ( F_36 ( ! V_2 || ( V_384 > 0x28 ) || ( V_384 & 7 ) ) )
return - V_63 ;
V_386 = ( T_1 ) ( ( ( 0x40 | V_382 ) << 12 ) | ( V_383 << 8 ) | V_384 ) ;
V_387 = ( T_1 ) ( ( ( 0x40 | V_2 -> V_236 ) << 12 ) |
( V_2 -> V_237 << 8 ) | 0x28 ) ;
if ( ( V_386 < V_388 ) ||
( V_386 > V_387 ) )
return - V_51 ;
if ( V_385 ) {
T_4 V_17 = * V_209 & F_196 ( 47 , 0 ) ;
F_21 ( ( T_1 ) V_17 , V_2 -> V_6 + V_386 ) ;
F_21 ( ( V_17 >> 32 ) , V_2 -> V_6 + V_386 + 4 ) ;
} else {
* V_209 = F_4 ( V_2 -> V_6 + V_386 + 4 ) ;
* V_209 <<= 32 ;
* V_209 |= F_4 ( V_2 -> V_6 + V_386 ) ;
* V_209 &= F_196 ( 47 , 0 ) ;
}
return 0 ;
}
int F_197 ( struct V_1 * V_2 , T_3 V_382 , T_3 V_383 , T_3 V_384 , T_4 * V_209 )
{
if ( ! V_2 )
return - V_51 ;
return F_106 ( V_2 , V_382 , V_383 , V_384 , V_209 , false ) ;
}
int F_198 ( struct V_1 * V_2 , T_3 V_382 , T_3 V_383 , T_3 V_384 , T_4 * V_209 )
{
if ( ! V_2 )
return - V_51 ;
return F_106 ( V_2 , V_382 , V_383 , V_384 , V_209 , true ) ;
}
