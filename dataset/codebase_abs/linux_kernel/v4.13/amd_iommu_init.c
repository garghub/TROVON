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
int F_4 ( void )
{
return V_6 ;
}
static T_2 F_5 ( struct V_7 * V_8 , T_1 V_9 , T_3 V_10 )
{
T_2 V_11 ;
F_6 ( V_8 -> V_12 , 0xf8 , ( V_10 | V_9 << 16 ) ) ;
F_7 ( V_8 -> V_12 , 0xfc , & V_11 ) ;
return V_11 ;
}
static void F_8 ( struct V_7 * V_8 , T_1 V_9 , T_3 V_10 , T_2 V_11 )
{
F_6 ( V_8 -> V_12 , 0xf8 , ( V_10 | V_9 << 16 | 1 << 31 ) ) ;
F_6 ( V_8 -> V_12 , 0xfc , V_11 ) ;
F_6 ( V_8 -> V_12 , 0xf8 , ( V_10 | V_9 << 16 ) ) ;
}
static T_2 F_9 ( struct V_7 * V_8 , T_3 V_10 )
{
T_2 V_11 ;
F_6 ( V_8 -> V_12 , 0xf0 , V_10 ) ;
F_7 ( V_8 -> V_12 , 0xf4 , & V_11 ) ;
return V_11 ;
}
static void F_10 ( struct V_7 * V_8 , T_3 V_10 , T_2 V_11 )
{
F_6 ( V_8 -> V_12 , 0xf0 , ( V_10 | 1 << 8 ) ) ;
F_6 ( V_8 -> V_12 , 0xf4 , V_11 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
T_4 V_13 = V_8 -> V_14 & V_15 ;
T_4 V_16 = ( V_13 + V_8 -> V_17 ) & V_15 ;
T_4 V_18 ;
if ( ! V_8 -> V_14 )
return;
V_18 = V_13 | V_19 ;
F_12 ( V_8 -> V_20 + V_21 ,
& V_18 , sizeof( V_18 ) ) ;
V_18 = V_16 ;
F_12 ( V_8 -> V_20 + V_22 ,
& V_18 , sizeof( V_18 ) ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
T_4 V_18 ;
F_14 ( V_8 -> V_20 == NULL ) ;
V_18 = F_15 ( V_23 ) ;
V_18 |= ( V_24 >> 12 ) - 1 ;
F_12 ( V_8 -> V_20 + V_25 ,
& V_18 , sizeof( V_18 ) ) ;
}
static void F_16 ( struct V_7 * V_8 , T_3 V_26 )
{
T_2 V_27 ;
V_27 = F_17 ( V_8 -> V_20 + V_28 ) ;
V_27 |= ( 1 << V_26 ) ;
F_18 ( V_27 , V_8 -> V_20 + V_28 ) ;
}
static void F_19 ( struct V_7 * V_8 , T_3 V_26 )
{
T_2 V_27 ;
V_27 = F_17 ( V_8 -> V_20 + V_28 ) ;
V_27 &= ~ ( 1 << V_26 ) ;
F_18 ( V_27 , V_8 -> V_20 + V_28 ) ;
}
static void F_20 ( struct V_7 * V_8 , int V_29 )
{
T_2 V_27 ;
V_27 = F_17 ( V_8 -> V_20 + V_28 ) ;
V_27 &= ~ V_30 ;
V_27 |= ( V_29 << V_31 ) & V_30 ;
F_18 ( V_27 , V_8 -> V_20 + V_28 ) ;
}
static void F_21 ( struct V_7 * V_8 )
{
F_16 ( V_8 , V_32 ) ;
}
static void F_22 ( struct V_7 * V_8 )
{
F_19 ( V_8 , V_33 ) ;
F_19 ( V_8 , V_34 ) ;
F_19 ( V_8 , V_35 ) ;
F_19 ( V_8 , V_36 ) ;
F_19 ( V_8 , V_37 ) ;
F_19 ( V_8 , V_32 ) ;
}
static T_3 T_5 * T_6 F_23 ( T_4 V_10 , T_4 V_38 )
{
if ( ! F_24 ( V_10 , V_38 , L_1 ) ) {
F_25 ( L_2 ,
V_10 , V_38 ) ;
F_25 ( L_3 ) ;
return NULL ;
}
return ( T_3 T_5 * ) F_26 ( V_10 , V_38 ) ;
}
static void T_6 F_27 ( struct V_7 * V_8 )
{
if ( V_8 -> V_20 )
F_28 ( V_8 -> V_20 ) ;
F_29 ( V_8 -> V_39 , V_8 -> V_40 ) ;
}
static inline T_2 F_30 ( struct V_41 * V_42 )
{
T_2 V_43 = 0 ;
switch ( V_42 -> type ) {
case 0x10 :
V_43 = 24 ;
break;
case 0x11 :
case 0x40 :
V_43 = 40 ;
break;
}
return V_43 ;
}
static inline int F_31 ( T_3 * V_44 )
{
T_2 type = ( (struct V_45 * ) V_44 ) -> type ;
if ( type < 0x80 ) {
return 0x04 << ( * V_44 >> 6 ) ;
} else if ( type == V_46 ) {
return * ( ( T_3 * ) V_44 + 21 ) + 22 ;
}
return 0 ;
}
static int T_6 F_32 ( struct V_41 * V_42 )
{
T_3 * V_47 = ( void * ) V_42 , * V_38 = ( void * ) V_42 ;
struct V_45 * V_12 ;
T_2 V_48 = F_30 ( V_42 ) ;
if ( ! V_48 ) {
F_25 ( L_4 , V_42 -> type ) ;
return - V_49 ;
}
V_47 += V_48 ;
V_38 += V_42 -> V_50 ;
while ( V_47 < V_38 ) {
V_12 = (struct V_45 * ) V_47 ;
switch ( V_12 -> type ) {
case V_51 :
F_1 ( 0xffff ) ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
F_1 ( V_12 -> V_1 ) ;
break;
default:
break;
}
V_47 += F_31 ( V_47 ) ;
}
F_33 ( V_47 != V_38 ) ;
return 0 ;
}
static int T_6 F_34 ( struct V_56 * V_57 )
{
int V_58 ;
T_3 V_59 = 0 , * V_47 = ( T_3 * ) V_57 ;
for ( V_58 = 0 ; V_58 < V_57 -> V_50 ; ++ V_58 )
V_59 += V_47 [ V_58 ] ;
if ( V_59 != 0 ) {
F_25 ( V_60 L_5 ) ;
return - V_61 ;
}
return 0 ;
}
static int T_6 F_35 ( struct V_56 * V_57 )
{
T_3 * V_47 = ( T_3 * ) V_57 , * V_38 = ( T_3 * ) V_57 ;
struct V_41 * V_42 ;
V_47 += V_62 ;
V_38 += V_57 -> V_50 ;
while ( V_47 < V_38 ) {
V_42 = (struct V_41 * ) V_47 ;
if ( V_42 -> type == V_63 ) {
int V_64 = F_32 ( V_42 ) ;
if ( V_64 )
return V_64 ;
}
V_47 += V_42 -> V_50 ;
}
F_33 ( V_47 != V_38 ) ;
return 0 ;
}
static int T_6 F_36 ( struct V_7 * V_8 )
{
V_8 -> V_65 = ( void * ) F_37 ( V_66 | V_67 ,
F_3 ( V_68 ) ) ;
return V_8 -> V_65 ? 0 : - V_69 ;
}
void F_38 ( struct V_7 * V_8 )
{
F_19 ( V_8 , V_33 ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_70 ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_71 ) ;
V_8 -> V_72 = 0 ;
V_8 -> V_73 = 0 ;
F_16 ( V_8 , V_33 ) ;
}
static void F_39 ( struct V_7 * V_8 )
{
T_4 V_18 ;
F_14 ( V_8 -> V_65 == NULL ) ;
V_18 = ( T_4 ) F_15 ( V_8 -> V_65 ) ;
V_18 |= V_74 ;
F_12 ( V_8 -> V_20 + V_75 ,
& V_18 , sizeof( V_18 ) ) ;
F_38 ( V_8 ) ;
}
static void T_6 F_40 ( struct V_7 * V_8 )
{
F_41 ( ( unsigned long ) V_8 -> V_65 , F_3 ( V_68 ) ) ;
}
static int T_6 F_42 ( struct V_7 * V_8 )
{
V_8 -> V_76 = ( void * ) F_37 ( V_66 | V_67 ,
F_3 ( V_77 ) ) ;
return V_8 -> V_76 ? 0 : - V_69 ;
}
static void F_43 ( struct V_7 * V_8 )
{
T_4 V_18 ;
F_14 ( V_8 -> V_76 == NULL ) ;
V_18 = ( T_4 ) F_15 ( V_8 -> V_76 ) | V_78 ;
F_12 ( V_8 -> V_20 + V_79 ,
& V_18 , sizeof( V_18 ) ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_80 ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_81 ) ;
F_16 ( V_8 , V_35 ) ;
}
static void T_6 F_44 ( struct V_7 * V_8 )
{
F_41 ( ( unsigned long ) V_8 -> V_76 , F_3 ( V_77 ) ) ;
}
static int T_6 F_45 ( struct V_7 * V_8 )
{
V_8 -> V_82 = ( void * ) F_37 ( V_66 | V_67 ,
F_3 ( V_83 ) ) ;
return V_8 -> V_82 ? 0 : - V_69 ;
}
static void F_46 ( struct V_7 * V_8 )
{
T_4 V_18 ;
if ( V_8 -> V_82 == NULL )
return;
V_18 = ( T_4 ) F_15 ( V_8 -> V_82 ) | V_84 ;
F_12 ( V_8 -> V_20 + V_85 ,
& V_18 , sizeof( V_18 ) ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_86 ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_87 ) ;
F_16 ( V_8 , V_88 ) ;
F_16 ( V_8 , V_89 ) ;
}
static void T_6 F_47 ( struct V_7 * V_8 )
{
if ( V_8 -> V_82 == NULL )
return;
F_41 ( ( unsigned long ) V_8 -> V_82 , F_3 ( V_83 ) ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
#ifdef F_49
if ( V_8 -> V_90 )
F_41 ( ( unsigned long ) V_8 -> V_90 ,
F_3 ( V_91 ) ) ;
if ( V_8 -> V_92 )
F_41 ( ( unsigned long ) V_8 -> V_92 ,
F_3 ( 8 ) ) ;
#endif
}
static int F_50 ( struct V_7 * V_8 )
{
#ifdef F_49
T_2 V_93 , V_58 ;
if ( ! V_8 -> V_90 )
return - V_49 ;
V_93 = F_17 ( V_8 -> V_20 + V_94 ) ;
if ( V_93 & ( V_95 ) )
return 0 ;
F_16 ( V_8 , V_37 ) ;
F_16 ( V_8 , V_36 ) ;
for ( V_58 = 0 ; V_58 < V_96 ; ++ V_58 ) {
V_93 = F_17 ( V_8 -> V_20 + V_94 ) ;
if ( V_93 & ( V_95 ) )
break;
}
if ( V_58 >= V_96 )
return - V_49 ;
#endif
return 0 ;
}
static int F_51 ( struct V_7 * V_8 )
{
T_4 V_18 ;
if ( ! F_52 ( V_97 ) )
return 0 ;
V_8 -> V_90 = ( T_3 * ) F_37 ( V_66 | V_67 ,
F_3 ( V_91 ) ) ;
if ( ! V_8 -> V_90 )
goto V_98;
V_8 -> V_92 = ( T_3 * ) F_37 ( V_66 | V_67 ,
F_3 ( 8 ) ) ;
if ( ! V_8 -> V_92 )
goto V_98;
V_18 = ( T_4 ) F_15 ( V_8 -> V_90 ) | V_99 ;
F_12 ( V_8 -> V_20 + V_100 ,
& V_18 , sizeof( V_18 ) ) ;
V_18 = ( ( T_4 ) F_15 ( V_8 -> V_90 ) & 0xFFFFFFFFFFFFFULL ) & ~ 7ULL ;
F_12 ( V_8 -> V_20 + V_101 ,
& V_18 , sizeof( V_18 ) ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_102 ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_103 ) ;
return 0 ;
V_98:
F_48 ( V_8 ) ;
return - V_49 ;
}
static int F_53 ( struct V_7 * V_8 )
{
int V_64 = 0 ;
#ifdef F_49
if ( F_52 ( V_97 ) &&
! F_54 ( V_8 , V_104 ) )
V_97 = V_105 ;
V_64 = F_51 ( V_8 ) ;
#endif
return V_64 ;
}
static void F_55 ( struct V_7 * V_8 )
{
if ( ! F_54 ( V_8 , V_106 ) )
return;
F_16 ( V_8 , V_107 ) ;
}
static void F_56 ( T_1 V_1 , T_3 V_26 )
{
int V_58 = ( V_26 >> 6 ) & 0x03 ;
int V_108 = V_26 & 0x3f ;
V_23 [ V_1 ] . V_109 [ V_58 ] |= ( 1UL << V_108 ) ;
}
static int F_57 ( T_1 V_1 , T_3 V_26 )
{
int V_58 = ( V_26 >> 6 ) & 0x03 ;
int V_108 = V_26 & 0x3f ;
return ( V_23 [ V_1 ] . V_109 [ V_58 ] & ( 1UL << V_108 ) ) >> V_108 ;
}
void F_58 ( T_1 V_1 )
{
int V_110 ;
V_110 = F_57 ( V_1 , V_111 ) |
( F_57 ( V_1 , V_112 ) << 1 ) ;
if ( V_110 == 0x01 )
F_56 ( V_1 , V_113 ) ;
}
static void T_6 F_59 ( struct V_7 * V_8 , T_1 V_1 )
{
V_114 [ V_1 ] = V_8 ;
}
static void T_6 F_60 ( struct V_7 * V_8 ,
T_1 V_1 , T_2 V_115 , T_2 V_116 )
{
if ( V_115 & V_117 )
F_56 ( V_1 , V_118 ) ;
if ( V_115 & V_119 )
F_56 ( V_1 , V_120 ) ;
if ( V_115 & V_121 )
F_56 ( V_1 , V_122 ) ;
if ( V_115 & V_123 )
F_56 ( V_1 , V_111 ) ;
if ( V_115 & V_124 )
F_56 ( V_1 , V_112 ) ;
if ( V_115 & V_125 )
F_56 ( V_1 , V_126 ) ;
if ( V_115 & V_127 )
F_56 ( V_1 , V_128 ) ;
F_58 ( V_1 ) ;
F_59 ( V_8 , V_1 ) ;
}
static int T_6 F_61 ( T_3 type , T_3 V_129 , T_1 * V_1 , bool V_130 )
{
struct V_131 * V_18 ;
struct V_132 * V_133 ;
if ( type == V_134 )
V_133 = & V_135 ;
else if ( type == V_136 )
V_133 = & V_137 ;
else
return - V_49 ;
F_62 (entry, list, list) {
if ( ! ( V_18 -> V_129 == V_129 && V_18 -> V_130 ) )
continue;
F_63 ( L_6 ,
type == V_134 ? L_7 : L_8 , V_129 ) ;
* V_1 = V_18 -> V_1 ;
return 0 ;
}
V_18 = F_64 ( sizeof( * V_18 ) , V_66 ) ;
if ( ! V_18 )
return - V_69 ;
V_18 -> V_129 = V_129 ;
V_18 -> V_1 = * V_1 ;
V_18 -> V_130 = V_130 ;
F_65 ( & V_18 -> V_133 , V_133 ) ;
return 0 ;
}
static int T_6 F_66 ( T_3 * V_138 , T_3 * V_139 , T_1 * V_1 ,
bool V_130 )
{
struct V_140 * V_18 ;
struct V_132 * V_133 = & V_141 ;
F_62 (entry, list, list) {
if ( strcmp ( V_18 -> V_138 , V_138 ) ||
( * V_139 && * V_18 -> V_139 && strcmp ( V_18 -> V_139 , V_139 ) ) ||
! V_18 -> V_130 )
continue;
F_63 ( L_9 ,
V_138 , V_139 ) ;
* V_1 = V_18 -> V_1 ;
return 0 ;
}
V_18 = F_64 ( sizeof( * V_18 ) , V_66 ) ;
if ( ! V_18 )
return - V_69 ;
memcpy ( V_18 -> V_139 , V_139 , strlen ( V_139 ) ) ;
memcpy ( V_18 -> V_138 , V_138 , strlen ( V_138 ) ) ;
V_18 -> V_1 = * V_1 ;
V_18 -> V_130 = V_130 ;
V_18 -> V_142 = ( V_18 -> V_1 & ( ~ 0x7 ) ) ;
F_63 ( L_10 ,
V_18 -> V_130 ? L_11 : L_12 ,
V_18 -> V_138 , V_18 -> V_139 , V_18 -> V_142 ) ;
F_65 ( & V_18 -> V_133 , V_133 ) ;
return 0 ;
}
static int T_6 F_67 ( void )
{
int V_58 , V_64 ;
for ( V_58 = 0 ; V_58 < V_143 ; ++ V_58 ) {
V_64 = F_61 ( V_134 ,
V_144 [ V_58 ] . V_129 ,
& V_144 [ V_58 ] . V_1 ,
V_144 [ V_58 ] . V_130 ) ;
if ( V_64 )
return V_64 ;
}
for ( V_58 = 0 ; V_58 < V_145 ; ++ V_58 ) {
V_64 = F_61 ( V_136 ,
V_146 [ V_58 ] . V_129 ,
& V_146 [ V_58 ] . V_1 ,
V_146 [ V_58 ] . V_130 ) ;
if ( V_64 )
return V_64 ;
}
for ( V_58 = 0 ; V_58 < V_147 ; ++ V_58 ) {
V_64 = F_66 ( V_148 [ V_58 ] . V_138 ,
V_148 [ V_58 ] . V_139 ,
& V_148 [ V_58 ] . V_1 ,
V_148 [ V_58 ] . V_130 ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
static void T_6 F_68 ( T_1 V_1 , struct V_149 * V_150 )
{
struct V_7 * V_8 = V_114 [ V_1 ] ;
if ( ! ( V_150 -> V_115 & V_151 ) )
return;
if ( V_8 ) {
F_56 ( V_1 , V_152 ) ;
V_8 -> V_14 = V_150 -> V_153 ;
V_8 -> V_17 = V_150 -> V_154 ;
}
}
static int T_6 F_69 ( struct V_7 * V_8 ,
struct V_41 * V_42 )
{
T_3 * V_47 = ( T_3 * ) V_42 ;
T_3 * V_38 = V_47 , V_115 = 0 ;
T_1 V_1 = 0 , V_155 = 0 , V_156 = 0 ;
T_2 V_157 , V_116 = 0 ;
bool V_158 = false ;
struct V_45 * V_159 ;
T_2 V_48 ;
int V_64 ;
V_64 = F_67 () ;
if ( V_64 )
return V_64 ;
V_8 -> V_160 = V_42 -> V_115 ;
V_48 = F_30 ( V_42 ) ;
if ( ! V_48 ) {
F_25 ( L_4 , V_42 -> type ) ;
return - V_49 ;
}
V_47 += V_48 ;
V_38 += V_42 -> V_50 ;
while ( V_47 < V_38 ) {
V_159 = (struct V_45 * ) V_47 ;
switch ( V_159 -> type ) {
case V_51 :
F_70 ( L_13 , V_159 -> V_115 ) ;
for ( V_157 = 0 ; V_157 <= V_2 ; ++ V_157 )
F_60 ( V_8 , V_157 , V_159 -> V_115 , 0 ) ;
break;
case V_52 :
F_70 ( L_14
L_15 ,
F_71 ( V_159 -> V_1 ) ,
F_72 ( V_159 -> V_1 ) ,
F_73 ( V_159 -> V_1 ) ,
V_159 -> V_115 ) ;
V_1 = V_159 -> V_1 ;
F_60 ( V_8 , V_1 , V_159 -> V_115 , 0 ) ;
break;
case V_161 :
F_70 ( L_16
L_17 ,
F_71 ( V_159 -> V_1 ) ,
F_72 ( V_159 -> V_1 ) ,
F_73 ( V_159 -> V_1 ) ,
V_159 -> V_115 ) ;
V_155 = V_159 -> V_1 ;
V_115 = V_159 -> V_115 ;
V_116 = 0 ;
V_158 = false ;
break;
case V_54 :
F_70 ( L_18
L_19 ,
F_71 ( V_159 -> V_1 ) ,
F_72 ( V_159 -> V_1 ) ,
F_73 ( V_159 -> V_1 ) ,
V_159 -> V_115 ,
F_71 ( V_159 -> V_162 >> 8 ) ,
F_72 ( V_159 -> V_162 >> 8 ) ,
F_73 ( V_159 -> V_162 >> 8 ) ) ;
V_1 = V_159 -> V_1 ;
V_156 = V_159 -> V_162 >> 8 ;
F_60 ( V_8 , V_1 , V_159 -> V_115 , 0 ) ;
F_60 ( V_8 , V_156 , V_159 -> V_115 , 0 ) ;
V_163 [ V_1 ] = V_156 ;
break;
case V_164 :
F_70 ( L_20
L_21
L_22 ,
F_71 ( V_159 -> V_1 ) ,
F_72 ( V_159 -> V_1 ) ,
F_73 ( V_159 -> V_1 ) ,
V_159 -> V_115 ,
F_71 ( V_159 -> V_162 >> 8 ) ,
F_72 ( V_159 -> V_162 >> 8 ) ,
F_73 ( V_159 -> V_162 >> 8 ) ) ;
V_155 = V_159 -> V_1 ;
V_115 = V_159 -> V_115 ;
V_156 = V_159 -> V_162 >> 8 ;
V_116 = 0 ;
V_158 = true ;
break;
case V_55 :
F_70 ( L_23
L_24 ,
F_71 ( V_159 -> V_1 ) ,
F_72 ( V_159 -> V_1 ) ,
F_73 ( V_159 -> V_1 ) ,
V_159 -> V_115 , V_159 -> V_162 ) ;
V_1 = V_159 -> V_1 ;
F_60 ( V_8 , V_1 , V_159 -> V_115 ,
V_159 -> V_162 ) ;
break;
case V_165 :
F_70 ( L_25
L_26 ,
F_71 ( V_159 -> V_1 ) ,
F_72 ( V_159 -> V_1 ) ,
F_73 ( V_159 -> V_1 ) ,
V_159 -> V_115 , V_159 -> V_162 ) ;
V_155 = V_159 -> V_1 ;
V_115 = V_159 -> V_115 ;
V_116 = V_159 -> V_162 ;
V_158 = false ;
break;
case V_53 :
F_70 ( L_27 ,
F_71 ( V_159 -> V_1 ) ,
F_72 ( V_159 -> V_1 ) ,
F_73 ( V_159 -> V_1 ) ) ;
V_1 = V_159 -> V_1 ;
for ( V_157 = V_155 ; V_157 <= V_1 ; ++ V_157 ) {
if ( V_158 ) {
V_163 [ V_157 ] = V_156 ;
F_60 ( V_8 ,
V_156 , V_115 , V_116 ) ;
}
F_60 ( V_8 , V_157 ,
V_115 , V_116 ) ;
}
break;
case V_166 : {
T_3 V_167 , type ;
const char * V_168 ;
T_1 V_1 ;
int V_64 ;
V_167 = V_159 -> V_162 & 0xff ;
V_1 = ( V_159 -> V_162 >> 8 ) & 0xffff ;
type = ( V_159 -> V_162 >> 24 ) & 0xff ;
if ( type == V_134 )
V_168 = L_7 ;
else if ( type == V_136 )
V_168 = L_8 ;
else
V_168 = L_28 ;
F_70 ( L_29 ,
V_168 , ( int ) V_167 ,
F_71 ( V_1 ) ,
F_72 ( V_1 ) ,
F_73 ( V_1 ) ) ;
V_64 = F_61 ( type , V_167 , & V_1 , false ) ;
if ( V_64 )
return V_64 ;
F_60 ( V_8 , V_1 , V_159 -> V_115 , 0 ) ;
break;
}
case V_46 : {
T_1 V_1 ;
T_3 V_138 [ V_169 ] = { 0 } ;
T_3 V_139 [ V_170 ] = { 0 } ;
int V_64 ;
if ( V_42 -> type != 0x40 ) {
F_25 ( V_60 L_30 ,
V_159 -> type ) ;
break;
}
memcpy ( V_138 , ( T_3 * ) ( & V_159 -> V_162 ) , V_169 - 1 ) ;
V_138 [ V_169 - 1 ] = '\0' ;
if ( ! ( * V_138 ) ) {
F_25 ( V_60 L_31 ) ;
break;
}
switch ( V_159 -> V_171 ) {
case V_172 :
if ( V_159 -> V_173 != 0 )
F_74 ( V_60 L_32 ) ;
break;
case V_174 :
sprintf ( V_139 , L_33 , V_159 -> V_139 ) ;
break;
case V_175 :
memcpy ( V_139 , ( T_3 * ) ( & V_159 -> V_139 ) , V_170 - 1 ) ;
V_139 [ V_170 - 1 ] = '\0' ;
break;
default:
break;
}
V_1 = V_159 -> V_1 ;
F_70 ( L_34 ,
V_138 , V_139 ,
F_71 ( V_1 ) ,
F_72 ( V_1 ) ,
F_73 ( V_1 ) ) ;
V_115 = V_159 -> V_115 ;
V_64 = F_66 ( V_138 , V_139 , & V_1 , false ) ;
if ( V_64 )
return V_64 ;
F_60 ( V_8 , V_1 , V_159 -> V_115 , 0 ) ;
break;
}
default:
break;
}
V_47 += F_31 ( V_47 ) ;
}
return 0 ;
}
static void T_6 F_75 ( struct V_7 * V_8 )
{
F_40 ( V_8 ) ;
F_44 ( V_8 ) ;
F_47 ( V_8 ) ;
F_48 ( V_8 ) ;
F_27 ( V_8 ) ;
}
static void T_6 F_76 ( void )
{
struct V_7 * V_8 , * V_176 ;
F_77 (iommu, next) {
F_78 ( & V_8 -> V_133 ) ;
F_75 ( V_8 ) ;
F_79 ( V_8 ) ;
}
}
static void F_80 ( struct V_7 * V_8 )
{
T_2 V_177 ;
if ( ( V_178 . V_179 != 0x15 ) ||
( V_178 . V_180 < 0x10 ) ||
( V_178 . V_180 > 0x1f ) )
return;
F_6 ( V_8 -> V_12 , 0xf0 , 0x90 ) ;
F_7 ( V_8 -> V_12 , 0xf4 , & V_177 ) ;
if ( V_177 & F_81 ( 2 ) )
return;
F_6 ( V_8 -> V_12 , 0xf0 , 0x90 | ( 1 << 8 ) ) ;
F_6 ( V_8 -> V_12 , 0xf4 , V_177 | 0x4 ) ;
F_63 ( L_35 ,
F_82 ( & V_8 -> V_12 -> V_12 ) ) ;
F_6 ( V_8 -> V_12 , 0xf0 , 0x90 ) ;
}
static void F_83 ( struct V_7 * V_8 )
{
T_2 V_177 ;
if ( ( V_178 . V_179 != 0x15 ) ||
( V_178 . V_180 < 0x30 ) ||
( V_178 . V_180 > 0x3f ) )
return;
V_177 = F_9 ( V_8 , 0x47 ) ;
if ( V_177 & F_81 ( 0 ) )
return;
F_10 ( V_8 , 0x47 , V_177 | F_81 ( 0 ) ) ;
F_63 ( L_36 ,
F_82 ( & V_8 -> V_12 -> V_12 ) ) ;
}
static int T_6 F_84 ( struct V_7 * V_8 , struct V_41 * V_42 )
{
int V_64 ;
F_85 ( & V_8 -> V_181 ) ;
F_65 ( & V_8 -> V_133 , & V_182 ) ;
V_8 -> V_183 = V_6 ++ ;
if ( F_86 ( V_8 -> V_183 >= V_184 ) ) {
F_87 ( 1 , L_37 ) ;
return - V_185 ;
}
V_186 [ V_8 -> V_183 ] = V_8 ;
V_8 -> V_1 = V_42 -> V_1 ;
V_8 -> V_187 = V_42 -> V_187 ;
V_8 -> V_188 = V_42 -> V_188 ;
V_8 -> V_39 = V_42 -> V_39 ;
switch ( V_42 -> type ) {
case 0x10 :
if ( ( V_42 -> V_189 != 0 ) &&
( ( V_42 -> V_189 & ( 0xF << 13 ) ) != 0 ) &&
( ( V_42 -> V_189 & ( 0x3F << 17 ) ) != 0 ) )
V_8 -> V_40 = V_190 ;
else
V_8 -> V_40 = V_191 ;
if ( ( ( V_42 -> V_189 & ( 0x1 << V_192 ) ) == 0 ) )
V_97 = V_193 ;
break;
case 0x11 :
case 0x40 :
if ( V_42 -> V_194 & ( 1 << 9 ) )
V_8 -> V_40 = V_190 ;
else
V_8 -> V_40 = V_191 ;
if ( ( ( V_42 -> V_194 & ( 0x1 << V_195 ) ) == 0 ) )
V_97 = V_193 ;
break;
default:
return - V_49 ;
}
V_8 -> V_20 = F_23 ( V_8 -> V_39 ,
V_8 -> V_40 ) ;
if ( ! V_8 -> V_20 )
return - V_69 ;
if ( F_36 ( V_8 ) )
return - V_69 ;
if ( F_42 ( V_8 ) )
return - V_69 ;
V_8 -> V_196 = false ;
V_64 = F_69 ( V_8 , V_42 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_88 ( V_8 ) ;
if ( V_64 )
return V_64 ;
V_114 [ V_8 -> V_1 ] = NULL ;
return 0 ;
}
static T_3 F_89 ( struct V_56 * V_197 )
{
T_3 * V_198 = ( T_3 * ) V_197 ;
struct V_41 * V_44 = (struct V_41 * )
( V_198 + V_62 ) ;
T_3 V_199 = V_44 -> type ;
T_1 V_1 = V_44 -> V_1 ;
while ( ( ( T_3 * ) V_44 - V_198 < V_197 -> V_50 ) &&
( V_44 -> type <= V_200 ) ) {
T_3 * V_47 = ( T_3 * ) V_44 ;
if ( V_44 -> V_1 == V_1 )
V_199 = V_44 -> type ;
V_44 = (struct V_41 * ) ( V_47 + V_44 -> V_50 ) ;
}
return V_199 ;
}
static int T_6 F_90 ( struct V_56 * V_57 )
{
T_3 * V_47 = ( T_3 * ) V_57 , * V_38 = ( T_3 * ) V_57 ;
struct V_41 * V_42 ;
struct V_7 * V_8 ;
int V_64 ;
V_38 += V_57 -> V_50 ;
V_47 += V_62 ;
while ( V_47 < V_38 ) {
V_42 = (struct V_41 * ) V_47 ;
if ( * V_47 == V_63 ) {
F_70 ( L_38
L_39 ,
F_71 ( V_42 -> V_1 ) , F_72 ( V_42 -> V_1 ) ,
F_73 ( V_42 -> V_1 ) , V_42 -> V_187 ,
V_42 -> V_188 , V_42 -> V_115 , V_42 -> V_201 ) ;
F_70 ( L_40 ,
V_42 -> V_39 ) ;
V_8 = F_64 ( sizeof( struct V_7 ) , V_66 ) ;
if ( V_8 == NULL )
return - V_69 ;
V_64 = F_84 ( V_8 , V_42 ) ;
if ( V_64 )
return V_64 ;
}
V_47 += V_42 -> V_50 ;
}
F_33 ( V_47 != V_38 ) ;
return 0 ;
}
static void F_91 ( struct V_7 * V_8 )
{
T_4 V_11 = 0xabcd , V_202 = 0 ;
if ( ! F_54 ( V_8 , V_203 ) )
return;
V_204 = true ;
if ( ( F_92 ( V_8 , 0 , 0 , 0 , & V_11 , true ) ) ||
( F_92 ( V_8 , 0 , 0 , 0 , & V_202 , false ) ) ||
( V_11 != V_202 ) ) {
F_25 ( L_41 ) ;
V_204 = false ;
return;
}
F_63 ( L_42 ) ;
V_11 = F_17 ( V_8 -> V_20 + V_191 ) ;
V_8 -> V_205 = ( T_3 ) ( ( V_11 >> 12 ) & 0x3f ) ;
V_8 -> V_206 = ( T_3 ) ( ( V_11 >> 7 ) & 0xf ) ;
}
static T_7 F_93 ( struct V_207 * V_12 ,
struct V_208 * V_209 ,
char * V_210 )
{
struct V_7 * V_8 = F_94 ( V_12 ) ;
return sprintf ( V_210 , L_43 , V_8 -> V_211 ) ;
}
static T_7 F_95 ( struct V_207 * V_12 ,
struct V_208 * V_209 ,
char * V_210 )
{
struct V_7 * V_8 = F_94 ( V_12 ) ;
return sprintf ( V_210 , L_44 , V_8 -> V_212 ) ;
}
static int F_96 ( struct V_7 * V_8 )
{
int V_187 = V_8 -> V_187 ;
T_2 V_213 , V_214 , V_215 , V_216 ;
int V_64 ;
V_8 -> V_12 = F_97 ( F_71 ( V_8 -> V_1 ) ,
V_8 -> V_1 & 0xff ) ;
if ( ! V_8 -> V_12 )
return - V_61 ;
V_8 -> V_12 -> V_217 = false ;
F_7 ( V_8 -> V_12 , V_187 + V_218 ,
& V_8 -> V_211 ) ;
F_7 ( V_8 -> V_12 , V_187 + V_219 ,
& V_213 ) ;
F_7 ( V_8 -> V_12 , V_187 + V_220 ,
& V_214 ) ;
if ( ! ( V_8 -> V_211 & ( 1 << V_221 ) ) )
V_222 = false ;
V_215 = F_17 ( V_8 -> V_20 + V_223 ) ;
V_216 = F_17 ( V_8 -> V_20 + V_223 + 4 ) ;
V_8 -> V_212 = ( ( T_4 ) V_216 << 32 ) | V_215 ;
if ( F_54 ( V_8 , V_106 ) ) {
int V_224 ;
T_2 V_225 ;
T_4 V_226 ;
V_226 = V_8 -> V_212 & V_227 ;
V_226 >>= V_228 ;
V_225 = ( 1 << ( V_226 + 1 ) ) - 1 ;
V_229 = F_98 ( V_229 , V_225 ) ;
F_14 ( V_229 & ~ V_230 ) ;
V_224 = V_8 -> V_212 & V_231 ;
V_224 >>= V_232 ;
if ( V_233 == - 1 )
V_233 = V_224 ;
else
V_233 = F_98 ( V_233 , V_224 ) ;
}
if ( F_54 ( V_8 , V_106 ) &&
F_54 ( V_8 , V_234 ) ) {
V_8 -> V_235 = true ;
V_236 = true ;
}
if ( F_54 ( V_8 , V_234 ) && F_45 ( V_8 ) )
return - V_69 ;
V_64 = F_53 ( V_8 ) ;
if ( V_64 )
return V_64 ;
if ( V_8 -> V_211 & ( 1UL << V_237 ) )
V_238 = true ;
F_91 ( V_8 ) ;
if ( F_99 ( V_8 -> V_12 ) ) {
int V_58 , V_239 ;
V_8 -> V_240 = F_97 ( V_8 -> V_12 -> V_241 -> V_242 ,
F_100 ( 0 , 0 ) ) ;
F_7 ( V_8 -> V_12 , V_8 -> V_187 + 4 ,
& V_8 -> V_243 ) ;
F_7 ( V_8 -> V_12 , V_8 -> V_187 + 8 ,
& V_8 -> V_244 ) ;
V_8 -> V_243 &= ~ 1 ;
for ( V_58 = 0 ; V_58 < 6 ; V_58 ++ )
for ( V_239 = 0 ; V_239 < 0x12 ; V_239 ++ )
V_8 -> V_245 [ V_58 ] [ V_239 ] = F_5 ( V_8 , V_58 , V_239 ) ;
for ( V_58 = 0 ; V_58 < 0x83 ; V_58 ++ )
V_8 -> V_246 [ V_58 ] = F_9 ( V_8 , V_58 ) ;
}
F_80 ( V_8 ) ;
F_83 ( V_8 ) ;
F_101 ( & V_8 -> V_8 , & V_8 -> V_12 -> V_12 ,
V_247 , L_45 , V_8 -> V_183 ) ;
F_102 ( & V_8 -> V_8 , & V_248 ) ;
F_103 ( & V_8 -> V_8 ) ;
return F_104 ( V_8 -> V_12 ) ;
}
static void F_105 ( void )
{
static const char * const V_249 [] = {
L_46 , L_47 , L_48 , L_49 , L_50 , L_51 ,
L_52 , L_53 , L_54 , L_55
} ;
struct V_7 * V_8 ;
F_106 (iommu) {
int V_58 ;
F_63 ( L_56 ,
F_82 ( & V_8 -> V_12 -> V_12 ) , V_8 -> V_187 ) ;
if ( V_8 -> V_211 & ( 1 << V_250 ) ) {
F_63 ( L_57 ,
V_8 -> V_212 ) ;
for ( V_58 = 0 ; V_58 < F_107 ( V_249 ) ; ++ V_58 ) {
if ( F_54 ( V_8 , ( 1ULL << V_58 ) ) )
F_108 ( L_58 , V_249 [ V_58 ] ) ;
}
if ( V_8 -> V_212 & V_104 )
F_108 ( L_59 ) ;
F_108 ( L_60 ) ;
}
}
if ( V_251 ) {
F_63 ( L_61 ) ;
if ( F_52 ( V_97 ) )
F_63 ( L_62 ) ;
}
}
static int T_6 F_109 ( void )
{
struct V_7 * V_8 ;
int V_64 = 0 ;
F_106 (iommu) {
V_64 = F_96 ( V_8 ) ;
if ( V_64 )
break;
}
V_64 = F_110 () ;
F_111 () ;
F_106 (iommu)
F_112 ( V_8 ) ;
if ( ! V_64 )
F_105 () ;
return V_64 ;
}
static int F_113 ( struct V_7 * V_8 )
{
int V_252 ;
V_252 = F_114 ( V_8 -> V_12 ) ;
if ( V_252 )
return V_252 ;
V_252 = F_115 ( V_8 -> V_12 -> V_253 ,
V_254 ,
V_255 ,
0 , L_63 ,
V_8 ) ;
if ( V_252 ) {
F_116 ( V_8 -> V_12 ) ;
return V_252 ;
}
V_8 -> V_196 = true ;
return 0 ;
}
static int F_117 ( struct V_7 * V_8 )
{
int V_64 ;
if ( V_8 -> V_196 )
goto V_256;
if ( V_8 -> V_12 -> V_257 )
V_64 = F_113 ( V_8 ) ;
else
V_64 = - V_61 ;
if ( V_64 )
return V_64 ;
V_256:
F_16 ( V_8 , V_34 ) ;
if ( V_8 -> V_82 != NULL )
F_16 ( V_8 , V_258 ) ;
F_50 ( V_8 ) ;
return 0 ;
}
static void T_6 F_118 ( void )
{
struct V_259 * V_18 , * V_176 ;
F_119 (entry, next, &amd_iommu_unity_map, list) {
F_78 ( & V_18 -> V_133 ) ;
F_79 ( V_18 ) ;
}
}
static int T_6 F_120 ( struct V_149 * V_150 )
{
int V_58 ;
switch ( V_150 -> type ) {
case V_260 :
F_68 ( V_150 -> V_1 , V_150 ) ;
break;
case V_261 :
for ( V_58 = 0 ; V_58 <= V_2 ; ++ V_58 )
F_68 ( V_58 , V_150 ) ;
break;
case V_262 :
for ( V_58 = V_150 -> V_1 ; V_58 <= V_150 -> V_263 ; ++ V_58 )
F_68 ( V_58 , V_150 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_121 ( struct V_149 * V_150 )
{
struct V_259 * V_159 = NULL ;
char * V_264 ;
V_159 = F_64 ( sizeof( * V_159 ) , V_66 ) ;
if ( V_159 == NULL )
return - V_69 ;
switch ( V_150 -> type ) {
default:
F_79 ( V_159 ) ;
return 0 ;
case V_260 :
V_264 = L_64 ;
V_159 -> V_155 = V_159 -> V_265 = V_150 -> V_1 ;
break;
case V_261 :
V_264 = L_65 ;
V_159 -> V_155 = 0 ;
V_159 -> V_265 = V_2 ;
break;
case V_262 :
V_264 = L_66 ;
V_159 -> V_155 = V_150 -> V_1 ;
V_159 -> V_265 = V_150 -> V_263 ;
break;
}
V_159 -> V_266 = F_122 ( V_150 -> V_153 ) ;
V_159 -> V_267 = V_159 -> V_266 + F_122 ( V_150 -> V_154 ) ;
V_159 -> V_268 = V_150 -> V_115 >> 1 ;
F_70 ( L_67
L_68 , V_264 ,
F_71 ( V_159 -> V_155 ) , F_72 ( V_159 -> V_155 ) ,
F_73 ( V_159 -> V_155 ) , F_71 ( V_159 -> V_265 ) ,
F_72 ( V_159 -> V_265 ) , F_73 ( V_159 -> V_265 ) ,
V_159 -> V_266 , V_159 -> V_267 , V_150 -> V_115 ) ;
F_65 ( & V_159 -> V_133 , & V_269 ) ;
return 0 ;
}
static int T_6 F_123 ( struct V_56 * V_57 )
{
T_3 * V_47 = ( T_3 * ) V_57 , * V_38 = ( T_3 * ) V_57 ;
struct V_149 * V_150 ;
V_38 += V_57 -> V_50 ;
V_47 += V_62 ;
while ( V_47 < V_38 ) {
V_150 = (struct V_149 * ) V_47 ;
if ( V_150 -> V_115 & V_151 )
F_120 ( V_150 ) ;
else if ( V_150 -> V_115 & V_270 )
F_121 ( V_150 ) ;
V_47 += V_150 -> V_50 ;
}
return 0 ;
}
static void F_111 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_56 ( V_1 , V_271 ) ;
F_56 ( V_1 , V_272 ) ;
if ( F_124 () )
F_56 ( V_1 , V_273 ) ;
}
}
static void T_6 F_125 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
V_23 [ V_1 ] . V_109 [ 0 ] = 0ULL ;
V_23 [ V_1 ] . V_109 [ 1 ] = 0ULL ;
}
}
static void F_126 ( void )
{
T_2 V_1 ;
if ( ! V_274 )
return;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 )
F_56 ( V_1 , V_275 ) ;
}
static void F_127 ( struct V_7 * V_8 )
{
V_8 -> V_160 & V_276 ?
F_16 ( V_8 , V_277 ) :
F_19 ( V_8 , V_277 ) ;
V_8 -> V_160 & V_278 ?
F_16 ( V_8 , V_279 ) :
F_19 ( V_8 , V_279 ) ;
V_8 -> V_160 & V_280 ?
F_16 ( V_8 , V_281 ) :
F_19 ( V_8 , V_281 ) ;
V_8 -> V_160 & V_282 ?
F_16 ( V_8 , V_283 ) :
F_19 ( V_8 , V_283 ) ;
F_16 ( V_8 , V_284 ) ;
F_20 ( V_8 , V_285 ) ;
}
static void F_128 ( struct V_7 * V_8 )
{
int V_58 , V_239 ;
T_2 V_286 ;
struct V_287 * V_288 = V_8 -> V_240 ;
if ( ! F_99 ( V_8 -> V_12 ) || ! V_288 )
return;
F_6 ( V_288 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_7 ( V_288 , 0x64 , & V_286 ) ;
if ( ! ( V_286 & 0x1 ) )
F_6 ( V_288 , 0x64 , V_286 | 1 ) ;
F_6 ( V_8 -> V_12 , V_8 -> V_187 + 4 ,
V_8 -> V_243 ) ;
F_6 ( V_8 -> V_12 , V_8 -> V_187 + 8 ,
V_8 -> V_244 ) ;
for ( V_58 = 0 ; V_58 < 6 ; V_58 ++ )
for ( V_239 = 0 ; V_239 < 0x12 ; V_239 ++ )
F_8 ( V_8 , V_58 , V_239 , V_8 -> V_245 [ V_58 ] [ V_239 ] ) ;
for ( V_58 = 0 ; V_58 < 0x83 ; V_58 ++ )
F_10 ( V_8 , V_58 , V_8 -> V_246 [ V_58 ] ) ;
F_6 ( V_8 -> V_12 , V_8 -> V_187 + 4 ,
V_8 -> V_243 | 1 ) ;
}
static void F_129 ( struct V_7 * V_8 )
{
#ifdef F_49
switch ( V_97 ) {
case F_52 :
F_16 ( V_8 , V_289 ) ;
case V_105 :
F_16 ( V_8 , V_290 ) ;
V_8 -> V_291 = & V_292 ;
break;
default:
V_8 -> V_291 = & V_293 ;
break;
}
#endif
}
static void F_130 ( void )
{
struct V_7 * V_8 ;
F_106 (iommu) {
F_22 ( V_8 ) ;
F_127 ( V_8 ) ;
F_13 ( V_8 ) ;
F_39 ( V_8 ) ;
F_43 ( V_8 ) ;
F_11 ( V_8 ) ;
F_129 ( V_8 ) ;
F_21 ( V_8 ) ;
F_112 ( V_8 ) ;
}
#ifdef F_49
if ( F_52 ( V_97 ) )
V_294 . V_295 |= ( 1 << V_296 ) ;
#endif
}
static void F_131 ( void )
{
struct V_7 * V_8 ;
F_106 (iommu) {
F_46 ( V_8 ) ;
F_55 ( V_8 ) ;
}
}
static void F_132 ( void )
{
F_130 () ;
F_131 () ;
}
static void F_133 ( void )
{
struct V_7 * V_8 ;
F_106 (iommu)
F_22 ( V_8 ) ;
#ifdef F_49
if ( F_52 ( V_97 ) )
V_294 . V_295 &= ~ ( 1 << V_296 ) ;
#endif
}
static void F_134 ( void )
{
struct V_7 * V_8 ;
F_106 (iommu)
F_128 ( V_8 ) ;
F_132 () ;
F_135 () ;
}
static int F_136 ( void )
{
F_133 () ;
return 0 ;
}
static void T_6 F_137 ( void )
{
F_138 ( V_297 ) ;
F_41 ( ( unsigned long ) V_297 ,
F_3 ( V_298 ) ) ;
V_297 = NULL ;
F_139 ( V_299 ) ;
V_299 = NULL ;
F_41 ( ( unsigned long ) V_114 ,
F_3 ( V_298 ) ) ;
V_114 = NULL ;
F_41 ( ( unsigned long ) V_163 ,
F_3 ( V_300 ) ) ;
V_163 = NULL ;
F_41 ( ( unsigned long ) V_23 ,
F_3 ( V_24 ) ) ;
V_23 = NULL ;
F_76 () ;
#ifdef F_140
F_141 () ;
#endif
}
static bool T_6 F_142 ( void )
{
const char * V_301 = V_60 ;
bool V_64 , V_302 ;
int V_303 ;
V_302 = false ;
V_64 = false ;
if ( V_304 )
V_301 = L_69 ;
for ( V_303 = 0 ; V_303 < V_305 ; V_303 ++ ) {
int V_1 , V_129 = F_143 ( V_303 ) ;
V_1 = F_144 ( V_129 ) ;
if ( V_1 < 0 ) {
F_25 ( L_70 ,
V_301 , V_129 ) ;
V_64 = false ;
} else if ( V_1 == V_306 ) {
V_302 = true ;
V_64 = true ;
}
}
if ( ! V_302 ) {
F_25 ( L_71 , V_301 ) ;
}
if ( ! V_64 )
F_25 ( L_72 ) ;
return V_64 ;
}
static void T_6 F_145 ( void )
{
F_41 ( ( unsigned long ) V_307 ,
F_3 ( V_308 / 8 ) ) ;
V_307 = NULL ;
F_118 () ;
}
static int T_6 F_146 ( void )
{
struct V_56 * V_309 ;
T_8 V_93 ;
int V_58 , V_310 , V_64 = 0 ;
if ( ! V_311 )
return - V_61 ;
V_93 = F_147 ( L_73 , 0 , & V_309 ) ;
if ( V_93 == V_312 )
return - V_61 ;
else if ( F_148 ( V_93 ) ) {
const char * V_313 = F_149 ( V_93 ) ;
F_25 ( L_74 , V_313 ) ;
return - V_49 ;
}
V_64 = F_34 ( V_309 ) ;
if ( V_64 )
goto V_314;
V_63 = F_89 ( V_309 ) ;
F_70 ( L_75 , V_63 ) ;
V_64 = F_35 ( V_309 ) ;
if ( V_64 )
goto V_314;
V_24 = F_2 ( V_315 ) ;
V_300 = F_2 ( V_316 ) ;
V_298 = F_2 ( V_317 ) ;
V_64 = - V_69 ;
V_23 = ( void * ) F_37 ( V_66 | V_67 ,
F_3 ( V_24 ) ) ;
if ( V_23 == NULL )
goto V_314;
V_163 = ( void * ) F_37 ( V_66 ,
F_3 ( V_300 ) ) ;
if ( V_163 == NULL )
goto V_314;
V_114 = ( void * ) F_37 (
V_66 | V_67 ,
F_3 ( V_298 ) ) ;
if ( V_114 == NULL )
goto V_314;
V_307 = ( void * ) F_37 (
V_66 | V_67 ,
F_3 ( V_308 / 8 ) ) ;
if ( V_307 == NULL )
goto V_314;
for ( V_58 = 0 ; V_58 <= V_2 ; ++ V_58 )
V_163 [ V_58 ] = V_58 ;
F_150 ( 0 , V_307 ) ;
F_85 ( & V_318 ) ;
V_64 = F_90 ( V_309 ) ;
if ( V_64 )
goto V_314;
F_133 () ;
if ( V_274 )
V_274 = F_142 () ;
if ( V_274 ) {
V_64 = - V_69 ;
if ( ! F_151 ( V_97 ) )
V_310 = V_319 * sizeof( T_2 ) ;
else
V_310 = V_319 * ( sizeof( T_4 ) * 2 ) ;
V_299 = F_152 ( L_76 ,
V_310 ,
V_320 ,
0 , NULL ) ;
if ( ! V_299 )
goto V_314;
V_297 = ( void * ) F_37 (
V_66 | V_67 ,
F_3 ( V_298 ) ) ;
F_153 ( V_297 , V_298 ,
1 , V_66 ) ;
if ( ! V_297 )
goto V_314;
}
V_64 = F_123 ( V_309 ) ;
if ( V_64 )
goto V_314;
F_126 () ;
V_314:
F_154 ( V_309 ) ;
V_309 = NULL ;
return V_64 ;
}
static int F_135 ( void )
{
struct V_7 * V_8 ;
int V_64 = 0 ;
F_106 (iommu) {
V_64 = F_117 ( V_8 ) ;
if ( V_64 )
goto V_314;
}
V_314:
return V_64 ;
}
static bool F_155 ( void )
{
struct V_56 * V_309 ;
T_8 V_93 ;
V_93 = F_147 ( L_73 , 0 , & V_309 ) ;
if ( V_93 == V_312 )
return false ;
else if ( F_148 ( V_93 ) ) {
const char * V_313 = F_149 ( V_93 ) ;
F_25 ( L_74 , V_313 ) ;
return false ;
}
F_154 ( V_309 ) ;
F_156 () ;
return true ;
}
static int T_6 F_157 ( void )
{
int V_64 = 0 ;
switch ( V_321 ) {
case V_322 :
if ( ! F_155 () ) {
V_321 = V_323 ;
V_64 = - V_61 ;
} else {
V_321 = V_324 ;
}
break;
case V_324 :
V_64 = F_146 () ;
V_321 = V_64 ? V_325 : V_326 ;
if ( V_321 == V_326 && V_327 ) {
F_63 ( L_77 ) ;
F_145 () ;
F_137 () ;
V_321 = V_328 ;
V_64 = - V_49 ;
}
break;
case V_326 :
F_130 () ;
V_329 . V_330 = F_133 ;
V_321 = V_331 ;
break;
case V_331 :
F_158 ( & V_332 ) ;
V_64 = F_109 () ;
V_321 = V_64 ? V_325 : V_333 ;
F_131 () ;
break;
case V_333 :
V_64 = F_135 () ;
V_321 = V_64 ? V_325 : V_334 ;
break;
case V_334 :
V_64 = F_159 () ;
V_321 = V_64 ? V_325 : V_335 ;
break;
case V_335 :
V_321 = V_336 ;
break;
case V_336 :
break;
case V_323 :
case V_325 :
case V_328 :
V_64 = - V_49 ;
break;
default:
F_160 () ;
}
return V_64 ;
}
static int T_6 F_161 ( enum V_337 V_338 )
{
int V_64 = - V_49 ;
while ( V_321 != V_338 ) {
if ( V_321 == V_323 ||
V_321 == V_325 ||
V_321 == V_328 )
break;
V_64 = F_157 () ;
}
return V_64 ;
}
int T_6 F_162 ( void )
{
int V_64 ;
V_274 = true ;
V_64 = F_161 ( V_326 ) ;
if ( V_64 )
return V_64 ;
return V_274 ? 0 : - V_61 ;
}
int T_6 F_163 ( void )
{
int V_64 ;
V_64 = F_161 ( V_331 ) ;
if ( V_64 )
return V_64 ;
V_251 = 1 ;
return 0 ;
}
void F_164 ( void )
{
F_136 () ;
}
int F_165 ( int V_339 )
{
F_134 () ;
return 0 ;
}
int T_6 F_166 ( void )
{
return 0 ;
}
static int T_6 F_167 ( void )
{
int V_64 ;
V_64 = F_161 ( V_336 ) ;
if ( V_64 ) {
F_145 () ;
if ( ! V_251 ) {
F_133 () ;
F_137 () ;
} else {
struct V_7 * V_8 ;
F_125 () ;
F_106 (iommu)
F_112 ( V_8 ) ;
}
}
return V_64 ;
}
int T_6 F_168 ( void )
{
int V_64 ;
if ( V_340 || ( V_341 && ! V_342 ) )
return - V_61 ;
V_64 = F_161 ( V_324 ) ;
if ( V_64 )
return V_64 ;
V_311 = true ;
V_341 = 1 ;
V_343 . V_8 . V_344 = F_167 ;
return 1 ;
}
static int T_6 F_169 ( char * V_345 )
{
V_346 = true ;
return 1 ;
}
static int T_6 F_170 ( char * V_345 )
{
for (; * V_345 ; ++ V_345 ) {
if ( strncmp ( V_345 , L_78 , 6 ) == 0 ) {
V_97 = V_193 ;
break;
}
if ( strncmp ( V_345 , L_79 , 5 ) == 0 ) {
V_97 = F_52 ;
break;
}
}
return 1 ;
}
static int T_6 F_171 ( char * V_345 )
{
for (; * V_345 ; ++ V_345 ) {
if ( strncmp ( V_345 , L_80 , 9 ) == 0 )
V_347 = true ;
if ( strncmp ( V_345 , L_81 , 3 ) == 0 )
V_327 = true ;
if ( strncmp ( V_345 , L_82 , 15 ) == 0 )
V_348 = true ;
}
return 1 ;
}
static int T_6 F_172 ( char * V_345 )
{
unsigned int V_241 , V_12 , V_349 ;
int V_64 , V_129 , V_58 ;
T_1 V_1 ;
V_64 = sscanf ( V_345 , L_83 , & V_129 , & V_241 , & V_12 , & V_349 ) ;
if ( V_64 != 4 ) {
F_25 ( L_84 , V_345 ) ;
return 1 ;
}
if ( V_143 == V_350 ) {
F_25 ( L_85 ,
V_345 ) ;
return 1 ;
}
V_1 = ( ( V_241 & 0xff ) << 8 ) | ( ( V_12 & 0x1f ) << 3 ) | ( V_349 & 0x7 ) ;
V_304 = true ;
V_58 = V_143 ++ ;
V_144 [ V_58 ] . V_129 = V_129 ;
V_144 [ V_58 ] . V_1 = V_1 ;
V_144 [ V_58 ] . V_130 = true ;
return 1 ;
}
static int T_6 F_173 ( char * V_345 )
{
unsigned int V_241 , V_12 , V_349 ;
int V_64 , V_129 , V_58 ;
T_1 V_1 ;
V_64 = sscanf ( V_345 , L_83 , & V_129 , & V_241 , & V_12 , & V_349 ) ;
if ( V_64 != 4 ) {
F_25 ( L_86 , V_345 ) ;
return 1 ;
}
if ( V_145 == V_350 ) {
F_25 ( L_87 ,
V_345 ) ;
return 1 ;
}
V_1 = ( ( V_241 & 0xff ) << 8 ) | ( ( V_12 & 0x1f ) << 3 ) | ( V_349 & 0x7 ) ;
V_304 = true ;
V_58 = V_145 ++ ;
V_146 [ V_58 ] . V_129 = V_129 ;
V_146 [ V_58 ] . V_1 = V_1 ;
V_146 [ V_58 ] . V_130 = true ;
return 1 ;
}
static int T_6 F_174 ( char * V_345 )
{
T_2 V_241 , V_12 , V_349 ;
char * V_138 , * V_139 , * V_47 ;
char V_351 [ V_170 + V_169 ] = { 0 } ;
int V_64 , V_58 ;
V_64 = sscanf ( V_345 , L_88 , & V_241 , & V_12 , & V_349 , V_351 ) ;
if ( V_64 != 4 ) {
F_25 ( L_89 , V_345 ) ;
return 1 ;
}
V_47 = V_351 ;
V_138 = F_175 ( & V_47 , L_90 ) ;
V_139 = V_47 ;
if ( ! V_138 || ! ( * V_138 ) || ! V_139 ) {
F_25 ( L_91 ) ;
return 1 ;
}
V_58 = V_147 ++ ;
memcpy ( V_148 [ V_58 ] . V_138 , V_138 , strlen ( V_138 ) ) ;
memcpy ( V_148 [ V_58 ] . V_139 , V_139 , strlen ( V_139 ) ) ;
V_148 [ V_58 ] . V_1 =
( ( V_241 & 0xff ) << 8 ) | ( ( V_12 & 0x1f ) << 3 ) | ( V_349 & 0x7 ) ;
V_148 [ V_58 ] . V_130 = true ;
return 1 ;
}
bool F_176 ( void )
{
return V_236 ;
}
struct V_7 * F_177 ( unsigned int V_303 )
{
unsigned int V_58 = 0 ;
struct V_7 * V_8 ;
F_106 (iommu)
if ( V_58 ++ == V_303 )
return V_8 ;
return NULL ;
}
T_3 F_178 ( unsigned int V_303 )
{
struct V_7 * V_8 = F_177 ( V_303 ) ;
if ( V_8 )
return V_8 -> V_205 ;
return 0 ;
}
bool F_179 ( void )
{
return V_204 ;
}
T_3 F_180 ( unsigned int V_303 )
{
struct V_7 * V_8 = F_177 ( V_303 ) ;
if ( V_8 )
return V_8 -> V_206 ;
return 0 ;
}
static int F_92 ( struct V_7 * V_8 , T_3 V_352 , T_3 V_353 ,
T_3 V_354 , T_4 * V_177 , bool V_355 )
{
T_2 V_356 ;
T_2 V_357 ;
if ( ! V_204 )
return - V_61 ;
if ( F_33 ( ! V_8 || ( V_354 > 0x28 ) || ( V_354 & 7 ) ) )
return - V_61 ;
V_356 = ( T_2 ) ( ( ( 0x40 | V_352 ) << 12 ) | ( V_353 << 8 ) | V_354 ) ;
V_357 = ( T_2 ) ( ( ( 0x40 | V_8 -> V_205 ) << 12 ) |
( V_8 -> V_206 << 8 ) | 0x28 ) ;
if ( ( V_356 < V_358 ) ||
( V_356 > V_357 ) )
return - V_49 ;
if ( V_355 ) {
T_4 V_11 = * V_177 & F_181 ( 47 , 0 ) ;
F_18 ( ( T_2 ) V_11 , V_8 -> V_20 + V_356 ) ;
F_18 ( ( V_11 >> 32 ) , V_8 -> V_20 + V_356 + 4 ) ;
} else {
* V_177 = F_17 ( V_8 -> V_20 + V_356 + 4 ) ;
* V_177 <<= 32 ;
* V_177 |= F_17 ( V_8 -> V_20 + V_356 ) ;
* V_177 &= F_181 ( 47 , 0 ) ;
}
return 0 ;
}
int F_182 ( struct V_7 * V_8 , T_3 V_352 , T_3 V_353 , T_3 V_354 , T_4 * V_177 )
{
if ( ! V_8 )
return - V_49 ;
return F_92 ( V_8 , V_352 , V_353 , V_354 , V_177 , false ) ;
}
int F_183 ( struct V_7 * V_8 , T_3 V_352 , T_3 V_353 , T_3 V_354 , T_4 * V_177 )
{
if ( ! V_8 )
return - V_49 ;
return F_92 ( V_8 , V_352 , V_353 , V_354 , V_177 , true ) ;
}
