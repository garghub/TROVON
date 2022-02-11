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
F_16 ( V_8 , V_33 ) ;
}
static void F_39 ( struct V_7 * V_8 )
{
T_4 V_18 ;
F_14 ( V_8 -> V_65 == NULL ) ;
V_18 = ( T_4 ) F_15 ( V_8 -> V_65 ) ;
V_18 |= V_72 ;
F_12 ( V_8 -> V_20 + V_73 ,
& V_18 , sizeof( V_18 ) ) ;
F_38 ( V_8 ) ;
}
static void T_6 F_40 ( struct V_7 * V_8 )
{
F_41 ( ( unsigned long ) V_8 -> V_65 , F_3 ( V_68 ) ) ;
}
static int T_6 F_42 ( struct V_7 * V_8 )
{
V_8 -> V_74 = ( void * ) F_37 ( V_66 | V_67 ,
F_3 ( V_75 ) ) ;
return V_8 -> V_74 ? 0 : - V_69 ;
}
static void F_43 ( struct V_7 * V_8 )
{
T_4 V_18 ;
F_14 ( V_8 -> V_74 == NULL ) ;
V_18 = ( T_4 ) F_15 ( V_8 -> V_74 ) | V_76 ;
F_12 ( V_8 -> V_20 + V_77 ,
& V_18 , sizeof( V_18 ) ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_78 ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_79 ) ;
F_16 ( V_8 , V_35 ) ;
}
static void T_6 F_44 ( struct V_7 * V_8 )
{
F_41 ( ( unsigned long ) V_8 -> V_74 , F_3 ( V_75 ) ) ;
}
static int T_6 F_45 ( struct V_7 * V_8 )
{
V_8 -> V_80 = ( void * ) F_37 ( V_66 | V_67 ,
F_3 ( V_81 ) ) ;
return V_8 -> V_80 ? 0 : - V_69 ;
}
static void F_46 ( struct V_7 * V_8 )
{
T_4 V_18 ;
if ( V_8 -> V_80 == NULL )
return;
V_18 = ( T_4 ) F_15 ( V_8 -> V_80 ) | V_82 ;
F_12 ( V_8 -> V_20 + V_83 ,
& V_18 , sizeof( V_18 ) ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_84 ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_85 ) ;
F_16 ( V_8 , V_86 ) ;
F_16 ( V_8 , V_87 ) ;
}
static void T_6 F_47 ( struct V_7 * V_8 )
{
if ( V_8 -> V_80 == NULL )
return;
F_41 ( ( unsigned long ) V_8 -> V_80 , F_3 ( V_81 ) ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
#ifdef F_49
if ( V_8 -> V_88 )
F_41 ( ( unsigned long ) V_8 -> V_88 ,
F_3 ( V_89 ) ) ;
if ( V_8 -> V_90 )
F_41 ( ( unsigned long ) V_8 -> V_90 ,
F_3 ( 8 ) ) ;
#endif
}
static int F_50 ( struct V_7 * V_8 )
{
#ifdef F_49
T_2 V_91 , V_58 ;
if ( ! V_8 -> V_88 )
return - V_49 ;
V_91 = F_17 ( V_8 -> V_20 + V_92 ) ;
if ( V_91 & ( V_93 ) )
return 0 ;
F_16 ( V_8 , V_37 ) ;
F_16 ( V_8 , V_36 ) ;
for ( V_58 = 0 ; V_58 < V_94 ; ++ V_58 ) {
V_91 = F_17 ( V_8 -> V_20 + V_92 ) ;
if ( V_91 & ( V_93 ) )
break;
}
if ( V_58 >= V_94 )
return - V_49 ;
#endif
return 0 ;
}
static int F_51 ( struct V_7 * V_8 )
{
T_4 V_18 ;
if ( ! F_52 ( V_95 ) )
return 0 ;
V_8 -> V_88 = ( T_3 * ) F_37 ( V_66 | V_67 ,
F_3 ( V_89 ) ) ;
if ( ! V_8 -> V_88 )
goto V_96;
V_8 -> V_90 = ( T_3 * ) F_37 ( V_66 | V_67 ,
F_3 ( 8 ) ) ;
if ( ! V_8 -> V_90 )
goto V_96;
V_18 = ( T_4 ) F_15 ( V_8 -> V_88 ) | V_97 ;
F_12 ( V_8 -> V_20 + V_98 ,
& V_18 , sizeof( V_18 ) ) ;
V_18 = ( ( T_4 ) F_15 ( V_8 -> V_88 ) & 0xFFFFFFFFFFFFFULL ) & ~ 7ULL ;
F_12 ( V_8 -> V_20 + V_99 ,
& V_18 , sizeof( V_18 ) ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_100 ) ;
F_18 ( 0x00 , V_8 -> V_20 + V_101 ) ;
return 0 ;
V_96:
F_48 ( V_8 ) ;
return - V_49 ;
}
static int F_53 ( struct V_7 * V_8 )
{
int V_64 = 0 ;
#ifdef F_49
if ( F_52 ( V_95 ) &&
! F_54 ( V_8 , V_102 ) )
V_95 = V_103 ;
V_64 = F_51 ( V_8 ) ;
#endif
return V_64 ;
}
static void F_55 ( struct V_7 * V_8 )
{
if ( ! F_54 ( V_8 , V_104 ) )
return;
F_16 ( V_8 , V_105 ) ;
}
static void F_56 ( T_1 V_1 , T_3 V_26 )
{
int V_58 = ( V_26 >> 6 ) & 0x03 ;
int V_106 = V_26 & 0x3f ;
V_23 [ V_1 ] . V_107 [ V_58 ] |= ( 1UL << V_106 ) ;
}
static int F_57 ( T_1 V_1 , T_3 V_26 )
{
int V_58 = ( V_26 >> 6 ) & 0x03 ;
int V_106 = V_26 & 0x3f ;
return ( V_23 [ V_1 ] . V_107 [ V_58 ] & ( 1UL << V_106 ) ) >> V_106 ;
}
void F_58 ( T_1 V_1 )
{
int V_108 ;
V_108 = F_57 ( V_1 , V_109 ) |
( F_57 ( V_1 , V_110 ) << 1 ) ;
if ( V_108 == 0x01 )
F_56 ( V_1 , V_111 ) ;
}
static void T_6 F_59 ( struct V_7 * V_8 , T_1 V_1 )
{
V_112 [ V_1 ] = V_8 ;
}
static void T_6 F_60 ( struct V_7 * V_8 ,
T_1 V_1 , T_2 V_113 , T_2 V_114 )
{
if ( V_113 & V_115 )
F_56 ( V_1 , V_116 ) ;
if ( V_113 & V_117 )
F_56 ( V_1 , V_118 ) ;
if ( V_113 & V_119 )
F_56 ( V_1 , V_120 ) ;
if ( V_113 & V_121 )
F_56 ( V_1 , V_109 ) ;
if ( V_113 & V_122 )
F_56 ( V_1 , V_110 ) ;
if ( V_113 & V_123 )
F_56 ( V_1 , V_124 ) ;
if ( V_113 & V_125 )
F_56 ( V_1 , V_126 ) ;
F_58 ( V_1 ) ;
F_59 ( V_8 , V_1 ) ;
}
static int T_6 F_61 ( T_3 type , T_3 V_127 , T_1 * V_1 , bool V_128 )
{
struct V_129 * V_18 ;
struct V_130 * V_131 ;
if ( type == V_132 )
V_131 = & V_133 ;
else if ( type == V_134 )
V_131 = & V_135 ;
else
return - V_49 ;
F_62 (entry, list, list) {
if ( ! ( V_18 -> V_127 == V_127 && V_18 -> V_128 ) )
continue;
F_63 ( L_6 ,
type == V_132 ? L_7 : L_8 , V_127 ) ;
* V_1 = V_18 -> V_1 ;
return 0 ;
}
V_18 = F_64 ( sizeof( * V_18 ) , V_66 ) ;
if ( ! V_18 )
return - V_69 ;
V_18 -> V_127 = V_127 ;
V_18 -> V_1 = * V_1 ;
V_18 -> V_128 = V_128 ;
F_65 ( & V_18 -> V_131 , V_131 ) ;
return 0 ;
}
static int T_6 F_66 ( T_3 * V_136 , T_3 * V_137 , T_1 * V_1 ,
bool V_128 )
{
struct V_138 * V_18 ;
struct V_130 * V_131 = & V_139 ;
F_62 (entry, list, list) {
if ( strcmp ( V_18 -> V_136 , V_136 ) ||
( * V_137 && * V_18 -> V_137 && strcmp ( V_18 -> V_137 , V_137 ) ) ||
! V_18 -> V_128 )
continue;
F_63 ( L_9 ,
V_136 , V_137 ) ;
* V_1 = V_18 -> V_1 ;
return 0 ;
}
V_18 = F_64 ( sizeof( * V_18 ) , V_66 ) ;
if ( ! V_18 )
return - V_69 ;
memcpy ( V_18 -> V_137 , V_137 , strlen ( V_137 ) ) ;
memcpy ( V_18 -> V_136 , V_136 , strlen ( V_136 ) ) ;
V_18 -> V_1 = * V_1 ;
V_18 -> V_128 = V_128 ;
V_18 -> V_140 = ( V_18 -> V_1 & ( ~ 0x7 ) ) ;
F_63 ( L_10 ,
V_18 -> V_128 ? L_11 : L_12 ,
V_18 -> V_136 , V_18 -> V_137 , V_18 -> V_140 ) ;
F_65 ( & V_18 -> V_131 , V_131 ) ;
return 0 ;
}
static int T_6 F_67 ( void )
{
int V_58 , V_64 ;
for ( V_58 = 0 ; V_58 < V_141 ; ++ V_58 ) {
V_64 = F_61 ( V_132 ,
V_142 [ V_58 ] . V_127 ,
& V_142 [ V_58 ] . V_1 ,
V_142 [ V_58 ] . V_128 ) ;
if ( V_64 )
return V_64 ;
}
for ( V_58 = 0 ; V_58 < V_143 ; ++ V_58 ) {
V_64 = F_61 ( V_134 ,
V_144 [ V_58 ] . V_127 ,
& V_144 [ V_58 ] . V_1 ,
V_144 [ V_58 ] . V_128 ) ;
if ( V_64 )
return V_64 ;
}
for ( V_58 = 0 ; V_58 < V_145 ; ++ V_58 ) {
V_64 = F_66 ( V_146 [ V_58 ] . V_136 ,
V_146 [ V_58 ] . V_137 ,
& V_146 [ V_58 ] . V_1 ,
V_146 [ V_58 ] . V_128 ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
static void T_6 F_68 ( T_1 V_1 , struct V_147 * V_148 )
{
struct V_7 * V_8 = V_112 [ V_1 ] ;
if ( ! ( V_148 -> V_113 & V_149 ) )
return;
if ( V_8 ) {
F_56 ( V_1 , V_150 ) ;
V_8 -> V_14 = V_148 -> V_151 ;
V_8 -> V_17 = V_148 -> V_152 ;
}
}
static int T_6 F_69 ( struct V_7 * V_8 ,
struct V_41 * V_42 )
{
T_3 * V_47 = ( T_3 * ) V_42 ;
T_3 * V_38 = V_47 , V_113 = 0 ;
T_1 V_1 = 0 , V_153 = 0 , V_154 = 0 ;
T_2 V_155 , V_114 = 0 ;
bool V_156 = false ;
struct V_45 * V_157 ;
T_2 V_48 ;
int V_64 ;
V_64 = F_67 () ;
if ( V_64 )
return V_64 ;
V_8 -> V_158 = V_42 -> V_113 ;
V_48 = F_30 ( V_42 ) ;
if ( ! V_48 ) {
F_25 ( L_4 , V_42 -> type ) ;
return - V_49 ;
}
V_47 += V_48 ;
V_38 += V_42 -> V_50 ;
while ( V_47 < V_38 ) {
V_157 = (struct V_45 * ) V_47 ;
switch ( V_157 -> type ) {
case V_51 :
F_70 ( L_13 , V_157 -> V_113 ) ;
for ( V_155 = 0 ; V_155 <= V_2 ; ++ V_155 )
F_60 ( V_8 , V_155 , V_157 -> V_113 , 0 ) ;
break;
case V_52 :
F_70 ( L_14
L_15 ,
F_71 ( V_157 -> V_1 ) ,
F_72 ( V_157 -> V_1 ) ,
F_73 ( V_157 -> V_1 ) ,
V_157 -> V_113 ) ;
V_1 = V_157 -> V_1 ;
F_60 ( V_8 , V_1 , V_157 -> V_113 , 0 ) ;
break;
case V_159 :
F_70 ( L_16
L_17 ,
F_71 ( V_157 -> V_1 ) ,
F_72 ( V_157 -> V_1 ) ,
F_73 ( V_157 -> V_1 ) ,
V_157 -> V_113 ) ;
V_153 = V_157 -> V_1 ;
V_113 = V_157 -> V_113 ;
V_114 = 0 ;
V_156 = false ;
break;
case V_54 :
F_70 ( L_18
L_19 ,
F_71 ( V_157 -> V_1 ) ,
F_72 ( V_157 -> V_1 ) ,
F_73 ( V_157 -> V_1 ) ,
V_157 -> V_113 ,
F_71 ( V_157 -> V_160 >> 8 ) ,
F_72 ( V_157 -> V_160 >> 8 ) ,
F_73 ( V_157 -> V_160 >> 8 ) ) ;
V_1 = V_157 -> V_1 ;
V_154 = V_157 -> V_160 >> 8 ;
F_60 ( V_8 , V_1 , V_157 -> V_113 , 0 ) ;
F_60 ( V_8 , V_154 , V_157 -> V_113 , 0 ) ;
V_161 [ V_1 ] = V_154 ;
break;
case V_162 :
F_70 ( L_20
L_21
L_22 ,
F_71 ( V_157 -> V_1 ) ,
F_72 ( V_157 -> V_1 ) ,
F_73 ( V_157 -> V_1 ) ,
V_157 -> V_113 ,
F_71 ( V_157 -> V_160 >> 8 ) ,
F_72 ( V_157 -> V_160 >> 8 ) ,
F_73 ( V_157 -> V_160 >> 8 ) ) ;
V_153 = V_157 -> V_1 ;
V_113 = V_157 -> V_113 ;
V_154 = V_157 -> V_160 >> 8 ;
V_114 = 0 ;
V_156 = true ;
break;
case V_55 :
F_70 ( L_23
L_24 ,
F_71 ( V_157 -> V_1 ) ,
F_72 ( V_157 -> V_1 ) ,
F_73 ( V_157 -> V_1 ) ,
V_157 -> V_113 , V_157 -> V_160 ) ;
V_1 = V_157 -> V_1 ;
F_60 ( V_8 , V_1 , V_157 -> V_113 ,
V_157 -> V_160 ) ;
break;
case V_163 :
F_70 ( L_25
L_26 ,
F_71 ( V_157 -> V_1 ) ,
F_72 ( V_157 -> V_1 ) ,
F_73 ( V_157 -> V_1 ) ,
V_157 -> V_113 , V_157 -> V_160 ) ;
V_153 = V_157 -> V_1 ;
V_113 = V_157 -> V_113 ;
V_114 = V_157 -> V_160 ;
V_156 = false ;
break;
case V_53 :
F_70 ( L_27 ,
F_71 ( V_157 -> V_1 ) ,
F_72 ( V_157 -> V_1 ) ,
F_73 ( V_157 -> V_1 ) ) ;
V_1 = V_157 -> V_1 ;
for ( V_155 = V_153 ; V_155 <= V_1 ; ++ V_155 ) {
if ( V_156 ) {
V_161 [ V_155 ] = V_154 ;
F_60 ( V_8 ,
V_154 , V_113 , V_114 ) ;
}
F_60 ( V_8 , V_155 ,
V_113 , V_114 ) ;
}
break;
case V_164 : {
T_3 V_165 , type ;
const char * V_166 ;
T_1 V_1 ;
int V_64 ;
V_165 = V_157 -> V_160 & 0xff ;
V_1 = ( V_157 -> V_160 >> 8 ) & 0xffff ;
type = ( V_157 -> V_160 >> 24 ) & 0xff ;
if ( type == V_132 )
V_166 = L_7 ;
else if ( type == V_134 )
V_166 = L_8 ;
else
V_166 = L_28 ;
F_70 ( L_29 ,
V_166 , ( int ) V_165 ,
F_71 ( V_1 ) ,
F_72 ( V_1 ) ,
F_73 ( V_1 ) ) ;
V_64 = F_61 ( type , V_165 , & V_1 , false ) ;
if ( V_64 )
return V_64 ;
F_60 ( V_8 , V_1 , V_157 -> V_113 , 0 ) ;
break;
}
case V_46 : {
T_1 V_1 ;
T_3 V_136 [ V_167 ] = { 0 } ;
T_3 V_137 [ V_168 ] = { 0 } ;
int V_64 ;
if ( V_42 -> type != 0x40 ) {
F_25 ( V_60 L_30 ,
V_157 -> type ) ;
break;
}
memcpy ( V_136 , ( T_3 * ) ( & V_157 -> V_160 ) , V_167 - 1 ) ;
V_136 [ V_167 - 1 ] = '\0' ;
if ( ! ( * V_136 ) ) {
F_25 ( V_60 L_31 ) ;
break;
}
switch ( V_157 -> V_169 ) {
case V_170 :
if ( V_157 -> V_171 != 0 )
F_74 ( V_60 L_32 ) ;
break;
case V_172 :
sprintf ( V_137 , L_33 , V_157 -> V_137 ) ;
break;
case V_173 :
memcpy ( V_137 , ( T_3 * ) ( & V_157 -> V_137 ) , V_168 - 1 ) ;
V_137 [ V_168 - 1 ] = '\0' ;
break;
default:
break;
}
V_1 = V_157 -> V_1 ;
F_70 ( L_34 ,
V_136 , V_137 ,
F_71 ( V_1 ) ,
F_72 ( V_1 ) ,
F_73 ( V_1 ) ) ;
V_113 = V_157 -> V_113 ;
V_64 = F_66 ( V_136 , V_137 , & V_1 , false ) ;
if ( V_64 )
return V_64 ;
F_60 ( V_8 , V_1 , V_157 -> V_113 , 0 ) ;
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
struct V_7 * V_8 , * V_174 ;
F_77 (iommu, next) {
F_78 ( & V_8 -> V_131 ) ;
F_75 ( V_8 ) ;
F_79 ( V_8 ) ;
}
}
static void F_80 ( struct V_7 * V_8 )
{
T_2 V_175 ;
if ( ( V_176 . V_177 != 0x15 ) ||
( V_176 . V_178 < 0x10 ) ||
( V_176 . V_178 > 0x1f ) )
return;
F_6 ( V_8 -> V_12 , 0xf0 , 0x90 ) ;
F_7 ( V_8 -> V_12 , 0xf4 , & V_175 ) ;
if ( V_175 & F_81 ( 2 ) )
return;
F_6 ( V_8 -> V_12 , 0xf0 , 0x90 | ( 1 << 8 ) ) ;
F_6 ( V_8 -> V_12 , 0xf4 , V_175 | 0x4 ) ;
F_63 ( L_35 ,
F_82 ( & V_8 -> V_12 -> V_12 ) ) ;
F_6 ( V_8 -> V_12 , 0xf0 , 0x90 ) ;
}
static void F_83 ( struct V_7 * V_8 )
{
T_2 V_175 ;
if ( ( V_176 . V_177 != 0x15 ) ||
( V_176 . V_178 < 0x30 ) ||
( V_176 . V_178 > 0x3f ) )
return;
V_175 = F_9 ( V_8 , 0x47 ) ;
if ( V_175 & F_81 ( 0 ) )
return;
F_10 ( V_8 , 0x47 , V_175 | F_81 ( 0 ) ) ;
F_63 ( L_36 ,
F_82 ( & V_8 -> V_12 -> V_12 ) ) ;
}
static int T_6 F_84 ( struct V_7 * V_8 , struct V_41 * V_42 )
{
int V_64 ;
F_85 ( & V_8 -> V_179 ) ;
F_65 ( & V_8 -> V_131 , & V_180 ) ;
V_8 -> V_181 = V_6 ++ ;
if ( F_86 ( V_8 -> V_181 >= V_182 ) ) {
F_87 ( 1 , L_37 ) ;
return - V_183 ;
}
V_184 [ V_8 -> V_181 ] = V_8 ;
V_8 -> V_1 = V_42 -> V_1 ;
V_8 -> V_185 = V_42 -> V_185 ;
V_8 -> V_186 = V_42 -> V_186 ;
V_8 -> V_39 = V_42 -> V_39 ;
switch ( V_42 -> type ) {
case 0x10 :
if ( ( V_42 -> V_187 != 0 ) &&
( ( V_42 -> V_187 & ( 0xF << 13 ) ) != 0 ) &&
( ( V_42 -> V_187 & ( 0x3F << 17 ) ) != 0 ) )
V_8 -> V_40 = V_188 ;
else
V_8 -> V_40 = V_189 ;
if ( ( ( V_42 -> V_187 & ( 0x1 << V_190 ) ) == 0 ) )
V_95 = V_191 ;
break;
case 0x11 :
case 0x40 :
if ( V_42 -> V_192 & ( 1 << 9 ) )
V_8 -> V_40 = V_188 ;
else
V_8 -> V_40 = V_189 ;
if ( ( ( V_42 -> V_192 & ( 0x1 << V_193 ) ) == 0 ) )
V_95 = V_191 ;
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
V_8 -> V_194 = false ;
V_64 = F_69 ( V_8 , V_42 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_88 ( V_8 ) ;
if ( V_64 )
return V_64 ;
V_112 [ V_8 -> V_1 ] = NULL ;
return 0 ;
}
static T_3 F_89 ( struct V_56 * V_195 )
{
T_3 * V_196 = ( T_3 * ) V_195 ;
struct V_41 * V_44 = (struct V_41 * )
( V_196 + V_62 ) ;
T_3 V_197 = V_44 -> type ;
T_1 V_1 = V_44 -> V_1 ;
while ( ( ( T_3 * ) V_44 - V_196 < V_195 -> V_50 ) &&
( V_44 -> type <= V_198 ) ) {
T_3 * V_47 = ( T_3 * ) V_44 ;
if ( V_44 -> V_1 == V_1 )
V_197 = V_44 -> type ;
V_44 = (struct V_41 * ) ( V_47 + V_44 -> V_50 ) ;
}
return V_197 ;
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
F_73 ( V_42 -> V_1 ) , V_42 -> V_185 ,
V_42 -> V_186 , V_42 -> V_113 , V_42 -> V_199 ) ;
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
T_4 V_11 = 0xabcd , V_200 = 0 ;
if ( ! F_54 ( V_8 , V_201 ) )
return;
V_202 = true ;
if ( ( F_92 ( V_8 , 0 , 0 , 0 , & V_11 , true ) ) ||
( F_92 ( V_8 , 0 , 0 , 0 , & V_200 , false ) ) ||
( V_11 != V_200 ) ) {
F_25 ( L_41 ) ;
V_202 = false ;
return;
}
F_63 ( L_42 ) ;
V_11 = F_17 ( V_8 -> V_20 + V_189 ) ;
V_8 -> V_203 = ( T_3 ) ( ( V_11 >> 12 ) & 0x3f ) ;
V_8 -> V_204 = ( T_3 ) ( ( V_11 >> 7 ) & 0xf ) ;
}
static T_7 F_93 ( struct V_205 * V_12 ,
struct V_206 * V_207 ,
char * V_208 )
{
struct V_7 * V_8 = F_94 ( V_12 ) ;
return sprintf ( V_208 , L_43 , V_8 -> V_209 ) ;
}
static T_7 F_95 ( struct V_205 * V_12 ,
struct V_206 * V_207 ,
char * V_208 )
{
struct V_7 * V_8 = F_94 ( V_12 ) ;
return sprintf ( V_208 , L_44 , V_8 -> V_210 ) ;
}
static int F_96 ( struct V_7 * V_8 )
{
int V_185 = V_8 -> V_185 ;
T_2 V_211 , V_212 , V_213 , V_214 ;
int V_64 ;
V_8 -> V_12 = F_97 ( F_71 ( V_8 -> V_1 ) ,
V_8 -> V_1 & 0xff ) ;
if ( ! V_8 -> V_12 )
return - V_61 ;
V_8 -> V_12 -> V_215 = false ;
F_7 ( V_8 -> V_12 , V_185 + V_216 ,
& V_8 -> V_209 ) ;
F_7 ( V_8 -> V_12 , V_185 + V_217 ,
& V_211 ) ;
F_7 ( V_8 -> V_12 , V_185 + V_218 ,
& V_212 ) ;
if ( ! ( V_8 -> V_209 & ( 1 << V_219 ) ) )
V_220 = false ;
V_213 = F_17 ( V_8 -> V_20 + V_221 ) ;
V_214 = F_17 ( V_8 -> V_20 + V_221 + 4 ) ;
V_8 -> V_210 = ( ( T_4 ) V_214 << 32 ) | V_213 ;
if ( F_54 ( V_8 , V_104 ) ) {
int V_222 ;
T_2 V_223 ;
T_4 V_224 ;
V_224 = V_8 -> V_210 & V_225 ;
V_224 >>= V_226 ;
V_223 = ( 1 << ( V_224 + 1 ) ) - 1 ;
V_227 = F_98 ( V_227 , V_223 ) ;
F_14 ( V_227 & ~ V_228 ) ;
V_222 = V_8 -> V_210 & V_229 ;
V_222 >>= V_230 ;
if ( V_231 == - 1 )
V_231 = V_222 ;
else
V_231 = F_98 ( V_231 , V_222 ) ;
}
if ( F_54 ( V_8 , V_104 ) &&
F_54 ( V_8 , V_232 ) ) {
V_8 -> V_233 = true ;
V_234 = true ;
}
if ( F_54 ( V_8 , V_232 ) && F_45 ( V_8 ) )
return - V_69 ;
V_64 = F_53 ( V_8 ) ;
if ( V_64 )
return V_64 ;
if ( V_8 -> V_209 & ( 1UL << V_235 ) )
V_236 = true ;
F_91 ( V_8 ) ;
if ( F_99 ( V_8 -> V_12 ) ) {
int V_58 , V_237 ;
V_8 -> V_238 = F_97 ( V_8 -> V_12 -> V_239 -> V_240 ,
F_100 ( 0 , 0 ) ) ;
F_7 ( V_8 -> V_12 , V_8 -> V_185 + 4 ,
& V_8 -> V_241 ) ;
F_7 ( V_8 -> V_12 , V_8 -> V_185 + 8 ,
& V_8 -> V_242 ) ;
V_8 -> V_241 &= ~ 1 ;
for ( V_58 = 0 ; V_58 < 6 ; V_58 ++ )
for ( V_237 = 0 ; V_237 < 0x12 ; V_237 ++ )
V_8 -> V_243 [ V_58 ] [ V_237 ] = F_5 ( V_8 , V_58 , V_237 ) ;
for ( V_58 = 0 ; V_58 < 0x83 ; V_58 ++ )
V_8 -> V_244 [ V_58 ] = F_9 ( V_8 , V_58 ) ;
}
F_80 ( V_8 ) ;
F_83 ( V_8 ) ;
F_101 ( & V_8 -> V_8 , & V_8 -> V_12 -> V_12 ,
V_245 , L_45 , V_8 -> V_181 ) ;
F_102 ( & V_8 -> V_8 , & V_246 ) ;
F_103 ( & V_8 -> V_8 ) ;
return F_104 ( V_8 -> V_12 ) ;
}
static void F_105 ( void )
{
static const char * const V_247 [] = {
L_46 , L_47 , L_48 , L_49 , L_50 , L_51 ,
L_52 , L_53 , L_54 , L_55
} ;
struct V_7 * V_8 ;
F_106 (iommu) {
int V_58 ;
F_63 ( L_56 ,
F_82 ( & V_8 -> V_12 -> V_12 ) , V_8 -> V_185 ) ;
if ( V_8 -> V_209 & ( 1 << V_248 ) ) {
F_63 ( L_57 ,
V_8 -> V_210 ) ;
for ( V_58 = 0 ; V_58 < F_107 ( V_247 ) ; ++ V_58 ) {
if ( F_54 ( V_8 , ( 1ULL << V_58 ) ) )
F_108 ( L_58 , V_247 [ V_58 ] ) ;
}
if ( V_8 -> V_210 & V_102 )
F_108 ( L_59 ) ;
F_108 ( L_60 ) ;
}
}
if ( V_249 ) {
F_63 ( L_61 ) ;
if ( F_52 ( V_95 ) )
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
int V_250 ;
V_250 = F_114 ( V_8 -> V_12 ) ;
if ( V_250 )
return V_250 ;
V_250 = F_115 ( V_8 -> V_12 -> V_251 ,
V_252 ,
V_253 ,
0 , L_63 ,
V_8 ) ;
if ( V_250 ) {
F_116 ( V_8 -> V_12 ) ;
return V_250 ;
}
V_8 -> V_194 = true ;
return 0 ;
}
static int F_117 ( struct V_7 * V_8 )
{
int V_64 ;
if ( V_8 -> V_194 )
goto V_254;
if ( V_8 -> V_12 -> V_255 )
V_64 = F_113 ( V_8 ) ;
else
V_64 = - V_61 ;
if ( V_64 )
return V_64 ;
V_254:
F_16 ( V_8 , V_34 ) ;
if ( V_8 -> V_80 != NULL )
F_16 ( V_8 , V_256 ) ;
F_50 ( V_8 ) ;
return 0 ;
}
static void T_6 F_118 ( void )
{
struct V_257 * V_18 , * V_174 ;
F_119 (entry, next, &amd_iommu_unity_map, list) {
F_78 ( & V_18 -> V_131 ) ;
F_79 ( V_18 ) ;
}
}
static int T_6 F_120 ( struct V_147 * V_148 )
{
int V_58 ;
switch ( V_148 -> type ) {
case V_258 :
F_68 ( V_148 -> V_1 , V_148 ) ;
break;
case V_259 :
for ( V_58 = 0 ; V_58 <= V_2 ; ++ V_58 )
F_68 ( V_58 , V_148 ) ;
break;
case V_260 :
for ( V_58 = V_148 -> V_1 ; V_58 <= V_148 -> V_261 ; ++ V_58 )
F_68 ( V_58 , V_148 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_121 ( struct V_147 * V_148 )
{
struct V_257 * V_157 = NULL ;
char * V_262 ;
V_157 = F_64 ( sizeof( * V_157 ) , V_66 ) ;
if ( V_157 == NULL )
return - V_69 ;
switch ( V_148 -> type ) {
default:
F_79 ( V_157 ) ;
return 0 ;
case V_258 :
V_262 = L_64 ;
V_157 -> V_153 = V_157 -> V_263 = V_148 -> V_1 ;
break;
case V_259 :
V_262 = L_65 ;
V_157 -> V_153 = 0 ;
V_157 -> V_263 = V_2 ;
break;
case V_260 :
V_262 = L_66 ;
V_157 -> V_153 = V_148 -> V_1 ;
V_157 -> V_263 = V_148 -> V_261 ;
break;
}
V_157 -> V_264 = F_122 ( V_148 -> V_151 ) ;
V_157 -> V_265 = V_157 -> V_264 + F_122 ( V_148 -> V_152 ) ;
V_157 -> V_266 = V_148 -> V_113 >> 1 ;
F_70 ( L_67
L_68 , V_262 ,
F_71 ( V_157 -> V_153 ) , F_72 ( V_157 -> V_153 ) ,
F_73 ( V_157 -> V_153 ) , F_71 ( V_157 -> V_263 ) ,
F_72 ( V_157 -> V_263 ) , F_73 ( V_157 -> V_263 ) ,
V_157 -> V_264 , V_157 -> V_265 , V_148 -> V_113 ) ;
F_65 ( & V_157 -> V_131 , & V_267 ) ;
return 0 ;
}
static int T_6 F_123 ( struct V_56 * V_57 )
{
T_3 * V_47 = ( T_3 * ) V_57 , * V_38 = ( T_3 * ) V_57 ;
struct V_147 * V_148 ;
V_38 += V_57 -> V_50 ;
V_47 += V_62 ;
while ( V_47 < V_38 ) {
V_148 = (struct V_147 * ) V_47 ;
if ( V_148 -> V_113 & V_149 )
F_120 ( V_148 ) ;
else if ( V_148 -> V_113 & V_268 )
F_121 ( V_148 ) ;
V_47 += V_148 -> V_50 ;
}
return 0 ;
}
static void F_111 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_56 ( V_1 , V_269 ) ;
F_56 ( V_1 , V_270 ) ;
}
}
static void T_6 F_124 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
V_23 [ V_1 ] . V_107 [ 0 ] = 0ULL ;
V_23 [ V_1 ] . V_107 [ 1 ] = 0ULL ;
}
}
static void F_125 ( void )
{
T_2 V_1 ;
if ( ! V_271 )
return;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 )
F_56 ( V_1 , V_272 ) ;
}
static void F_126 ( struct V_7 * V_8 )
{
V_8 -> V_158 & V_273 ?
F_16 ( V_8 , V_274 ) :
F_19 ( V_8 , V_274 ) ;
V_8 -> V_158 & V_275 ?
F_16 ( V_8 , V_276 ) :
F_19 ( V_8 , V_276 ) ;
V_8 -> V_158 & V_277 ?
F_16 ( V_8 , V_278 ) :
F_19 ( V_8 , V_278 ) ;
V_8 -> V_158 & V_279 ?
F_16 ( V_8 , V_280 ) :
F_19 ( V_8 , V_280 ) ;
F_16 ( V_8 , V_281 ) ;
F_20 ( V_8 , V_282 ) ;
}
static void F_127 ( struct V_7 * V_8 )
{
int V_58 , V_237 ;
T_2 V_283 ;
struct V_284 * V_285 = V_8 -> V_238 ;
if ( ! F_99 ( V_8 -> V_12 ) || ! V_285 )
return;
F_6 ( V_285 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_7 ( V_285 , 0x64 , & V_283 ) ;
if ( ! ( V_283 & 0x1 ) )
F_6 ( V_285 , 0x64 , V_283 | 1 ) ;
F_6 ( V_8 -> V_12 , V_8 -> V_185 + 4 ,
V_8 -> V_241 ) ;
F_6 ( V_8 -> V_12 , V_8 -> V_185 + 8 ,
V_8 -> V_242 ) ;
for ( V_58 = 0 ; V_58 < 6 ; V_58 ++ )
for ( V_237 = 0 ; V_237 < 0x12 ; V_237 ++ )
F_8 ( V_8 , V_58 , V_237 , V_8 -> V_243 [ V_58 ] [ V_237 ] ) ;
for ( V_58 = 0 ; V_58 < 0x83 ; V_58 ++ )
F_10 ( V_8 , V_58 , V_8 -> V_244 [ V_58 ] ) ;
F_6 ( V_8 -> V_12 , V_8 -> V_185 + 4 ,
V_8 -> V_241 | 1 ) ;
}
static void F_128 ( struct V_7 * V_8 )
{
#ifdef F_49
switch ( V_95 ) {
case F_52 :
F_16 ( V_8 , V_286 ) ;
case V_103 :
F_16 ( V_8 , V_287 ) ;
V_8 -> V_288 = & V_289 ;
break;
default:
V_8 -> V_288 = & V_290 ;
break;
}
#endif
}
static void F_129 ( void )
{
struct V_7 * V_8 ;
F_106 (iommu) {
F_22 ( V_8 ) ;
F_126 ( V_8 ) ;
F_13 ( V_8 ) ;
F_39 ( V_8 ) ;
F_43 ( V_8 ) ;
F_11 ( V_8 ) ;
F_128 ( V_8 ) ;
F_21 ( V_8 ) ;
F_112 ( V_8 ) ;
}
#ifdef F_49
if ( F_52 ( V_95 ) )
V_291 . V_292 |= ( 1 << V_293 ) ;
#endif
}
static void F_130 ( void )
{
struct V_7 * V_8 ;
F_106 (iommu) {
F_46 ( V_8 ) ;
F_55 ( V_8 ) ;
}
}
static void F_131 ( void )
{
F_129 () ;
F_130 () ;
}
static void F_132 ( void )
{
struct V_7 * V_8 ;
F_106 (iommu)
F_22 ( V_8 ) ;
#ifdef F_49
if ( F_52 ( V_95 ) )
V_291 . V_292 &= ~ ( 1 << V_293 ) ;
#endif
}
static void F_133 ( void )
{
struct V_7 * V_8 ;
F_106 (iommu)
F_127 ( V_8 ) ;
F_131 () ;
F_134 () ;
}
static int F_135 ( void )
{
F_132 () ;
return 0 ;
}
static void T_6 F_136 ( void )
{
F_137 ( V_294 ) ;
F_41 ( ( unsigned long ) V_294 ,
F_3 ( V_295 ) ) ;
F_138 ( V_296 ) ;
V_296 = NULL ;
F_41 ( ( unsigned long ) V_112 ,
F_3 ( V_295 ) ) ;
F_41 ( ( unsigned long ) V_161 ,
F_3 ( V_297 ) ) ;
F_41 ( ( unsigned long ) V_23 ,
F_3 ( V_24 ) ) ;
F_76 () ;
#ifdef F_139
F_140 () ;
#endif
}
static bool T_6 F_141 ( void )
{
const char * V_298 = V_60 ;
bool V_64 , V_299 ;
int V_300 ;
V_299 = false ;
V_64 = false ;
if ( V_301 )
V_298 = L_69 ;
for ( V_300 = 0 ; V_300 < V_302 ; V_300 ++ ) {
int V_1 , V_127 = F_142 ( V_300 ) ;
V_1 = F_143 ( V_127 ) ;
if ( V_1 < 0 ) {
F_25 ( L_70 ,
V_298 , V_127 ) ;
V_64 = false ;
} else if ( V_1 == V_303 ) {
V_299 = true ;
V_64 = true ;
}
}
if ( ! V_299 ) {
F_25 ( L_71 , V_298 ) ;
}
if ( ! V_64 )
F_25 ( L_72 ) ;
return V_64 ;
}
static void T_6 F_144 ( void )
{
F_41 ( ( unsigned long ) V_304 ,
F_3 ( V_305 / 8 ) ) ;
F_118 () ;
}
static int T_6 F_145 ( void )
{
struct V_56 * V_306 ;
T_8 V_91 ;
int V_58 , V_307 , V_64 = 0 ;
if ( ! V_308 )
return - V_61 ;
V_91 = F_146 ( L_73 , 0 , & V_306 ) ;
if ( V_91 == V_309 )
return - V_61 ;
else if ( F_147 ( V_91 ) ) {
const char * V_310 = F_148 ( V_91 ) ;
F_25 ( L_74 , V_310 ) ;
return - V_49 ;
}
V_64 = F_34 ( V_306 ) ;
if ( V_64 )
goto V_311;
V_63 = F_89 ( V_306 ) ;
F_70 ( L_75 , V_63 ) ;
V_64 = F_35 ( V_306 ) ;
if ( V_64 )
goto V_311;
V_24 = F_2 ( V_312 ) ;
V_297 = F_2 ( V_313 ) ;
V_295 = F_2 ( V_314 ) ;
V_64 = - V_69 ;
V_23 = ( void * ) F_37 ( V_66 | V_67 ,
F_3 ( V_24 ) ) ;
if ( V_23 == NULL )
goto V_311;
V_161 = ( void * ) F_37 ( V_66 ,
F_3 ( V_297 ) ) ;
if ( V_161 == NULL )
goto V_311;
V_112 = ( void * ) F_37 (
V_66 | V_67 ,
F_3 ( V_295 ) ) ;
if ( V_112 == NULL )
goto V_311;
V_304 = ( void * ) F_37 (
V_66 | V_67 ,
F_3 ( V_305 / 8 ) ) ;
if ( V_304 == NULL )
goto V_311;
for ( V_58 = 0 ; V_58 <= V_2 ; ++ V_58 )
V_161 [ V_58 ] = V_58 ;
F_149 ( 0 , V_304 ) ;
F_85 ( & V_315 ) ;
V_64 = F_90 ( V_306 ) ;
if ( V_64 )
goto V_311;
if ( V_271 )
V_271 = F_141 () ;
if ( V_271 ) {
V_64 = - V_69 ;
if ( ! F_150 ( V_95 ) )
V_307 = V_316 * sizeof( T_2 ) ;
else
V_307 = V_316 * ( sizeof( T_4 ) * 2 ) ;
V_296 = F_151 ( L_76 ,
V_307 ,
V_317 ,
0 , NULL ) ;
if ( ! V_296 )
goto V_311;
V_294 = ( void * ) F_37 (
V_66 | V_67 ,
F_3 ( V_295 ) ) ;
F_152 ( V_294 , V_295 ,
1 , V_66 ) ;
if ( ! V_294 )
goto V_311;
}
V_64 = F_123 ( V_306 ) ;
if ( V_64 )
goto V_311;
F_125 () ;
V_311:
F_153 ( V_306 ) ;
V_306 = NULL ;
return V_64 ;
}
static int F_134 ( void )
{
struct V_7 * V_8 ;
int V_64 = 0 ;
F_106 (iommu) {
V_64 = F_117 ( V_8 ) ;
if ( V_64 )
goto V_311;
}
V_311:
return V_64 ;
}
static bool F_154 ( void )
{
struct V_56 * V_306 ;
T_8 V_91 ;
V_91 = F_146 ( L_73 , 0 , & V_306 ) ;
if ( V_91 == V_309 )
return false ;
else if ( F_147 ( V_91 ) ) {
const char * V_310 = F_148 ( V_91 ) ;
F_25 ( L_74 , V_310 ) ;
return false ;
}
F_153 ( V_306 ) ;
F_155 () ;
return true ;
}
static int T_6 F_156 ( void )
{
int V_64 = 0 ;
switch ( V_318 ) {
case V_319 :
if ( ! F_154 () ) {
V_318 = V_320 ;
V_64 = - V_61 ;
} else {
V_318 = V_321 ;
}
break;
case V_321 :
V_64 = F_145 () ;
V_318 = V_64 ? V_322 : V_323 ;
break;
case V_323 :
F_129 () ;
F_157 ( & V_324 ) ;
V_325 . V_326 = F_132 ;
V_318 = V_327 ;
break;
case V_327 :
V_64 = F_109 () ;
V_318 = V_64 ? V_322 : V_328 ;
F_130 () ;
break;
case V_328 :
V_64 = F_134 () ;
V_318 = V_64 ? V_322 : V_329 ;
break;
case V_329 :
V_64 = F_158 () ;
V_318 = V_64 ? V_322 : V_330 ;
break;
case V_330 :
V_318 = V_331 ;
break;
case V_331 :
break;
case V_320 :
case V_322 :
V_64 = - V_49 ;
break;
default:
F_159 () ;
}
return V_64 ;
}
static int T_6 F_160 ( enum V_332 V_333 )
{
int V_64 = 0 ;
while ( V_318 != V_333 ) {
V_64 = F_156 () ;
if ( V_318 == V_320 ||
V_318 == V_322 )
break;
}
return V_64 ;
}
int T_6 F_161 ( void )
{
int V_64 ;
V_271 = true ;
V_64 = F_160 ( V_323 ) ;
if ( V_64 )
return V_64 ;
return V_271 ? 0 : - V_61 ;
}
int T_6 F_162 ( void )
{
int V_64 ;
V_64 = F_160 ( V_327 ) ;
if ( V_64 )
return V_64 ;
V_249 = 1 ;
return 0 ;
}
void F_163 ( void )
{
F_135 () ;
}
int F_164 ( int V_334 )
{
F_133 () ;
return 0 ;
}
int T_6 F_165 ( void )
{
return 0 ;
}
static int T_6 F_166 ( void )
{
int V_64 ;
V_64 = F_160 ( V_331 ) ;
if ( V_64 ) {
F_144 () ;
if ( ! V_249 ) {
F_132 () ;
F_136 () ;
} else {
struct V_7 * V_8 ;
F_124 () ;
F_106 (iommu)
F_112 ( V_8 ) ;
}
}
return V_64 ;
}
int T_6 F_167 ( void )
{
int V_64 ;
if ( V_335 || ( V_336 && ! V_337 ) )
return - V_61 ;
if ( V_338 )
return - V_61 ;
V_64 = F_160 ( V_321 ) ;
if ( V_64 )
return V_64 ;
V_308 = true ;
V_336 = 1 ;
V_339 . V_8 . V_340 = F_166 ;
return 1 ;
}
static int T_6 F_168 ( char * V_341 )
{
V_342 = true ;
return 1 ;
}
static int T_6 F_169 ( char * V_341 )
{
for (; * V_341 ; ++ V_341 ) {
if ( strncmp ( V_341 , L_77 , 6 ) == 0 ) {
V_95 = V_191 ;
break;
}
if ( strncmp ( V_341 , L_78 , 5 ) == 0 ) {
V_95 = F_52 ;
break;
}
}
return 1 ;
}
static int T_6 F_170 ( char * V_341 )
{
for (; * V_341 ; ++ V_341 ) {
if ( strncmp ( V_341 , L_79 , 9 ) == 0 )
V_343 = true ;
if ( strncmp ( V_341 , L_80 , 3 ) == 0 )
V_338 = true ;
if ( strncmp ( V_341 , L_81 , 15 ) == 0 )
V_344 = true ;
}
return 1 ;
}
static int T_6 F_171 ( char * V_341 )
{
unsigned int V_239 , V_12 , V_345 ;
int V_64 , V_127 , V_58 ;
T_1 V_1 ;
V_64 = sscanf ( V_341 , L_82 , & V_127 , & V_239 , & V_12 , & V_345 ) ;
if ( V_64 != 4 ) {
F_25 ( L_83 , V_341 ) ;
return 1 ;
}
if ( V_141 == V_346 ) {
F_25 ( L_84 ,
V_341 ) ;
return 1 ;
}
V_1 = ( ( V_239 & 0xff ) << 8 ) | ( ( V_12 & 0x1f ) << 3 ) | ( V_345 & 0x7 ) ;
V_301 = true ;
V_58 = V_141 ++ ;
V_142 [ V_58 ] . V_127 = V_127 ;
V_142 [ V_58 ] . V_1 = V_1 ;
V_142 [ V_58 ] . V_128 = true ;
return 1 ;
}
static int T_6 F_172 ( char * V_341 )
{
unsigned int V_239 , V_12 , V_345 ;
int V_64 , V_127 , V_58 ;
T_1 V_1 ;
V_64 = sscanf ( V_341 , L_82 , & V_127 , & V_239 , & V_12 , & V_345 ) ;
if ( V_64 != 4 ) {
F_25 ( L_85 , V_341 ) ;
return 1 ;
}
if ( V_143 == V_346 ) {
F_25 ( L_86 ,
V_341 ) ;
return 1 ;
}
V_1 = ( ( V_239 & 0xff ) << 8 ) | ( ( V_12 & 0x1f ) << 3 ) | ( V_345 & 0x7 ) ;
V_301 = true ;
V_58 = V_143 ++ ;
V_144 [ V_58 ] . V_127 = V_127 ;
V_144 [ V_58 ] . V_1 = V_1 ;
V_144 [ V_58 ] . V_128 = true ;
return 1 ;
}
static int T_6 F_173 ( char * V_341 )
{
T_2 V_239 , V_12 , V_345 ;
char * V_136 , * V_137 , * V_47 ;
char V_347 [ V_168 + V_167 ] = { 0 } ;
int V_64 , V_58 ;
V_64 = sscanf ( V_341 , L_87 , & V_239 , & V_12 , & V_345 , V_347 ) ;
if ( V_64 != 4 ) {
F_25 ( L_88 , V_341 ) ;
return 1 ;
}
V_47 = V_347 ;
V_136 = F_174 ( & V_47 , L_89 ) ;
V_137 = V_47 ;
if ( ! V_136 || ! ( * V_136 ) || ! V_137 ) {
F_25 ( L_90 ) ;
return 1 ;
}
V_58 = V_145 ++ ;
memcpy ( V_146 [ V_58 ] . V_136 , V_136 , strlen ( V_136 ) ) ;
memcpy ( V_146 [ V_58 ] . V_137 , V_137 , strlen ( V_137 ) ) ;
V_146 [ V_58 ] . V_1 =
( ( V_239 & 0xff ) << 8 ) | ( ( V_12 & 0x1f ) << 3 ) | ( V_345 & 0x7 ) ;
V_146 [ V_58 ] . V_128 = true ;
return 1 ;
}
bool F_175 ( void )
{
return V_234 ;
}
struct V_7 * F_176 ( unsigned int V_300 )
{
unsigned int V_58 = 0 ;
struct V_7 * V_8 ;
F_106 (iommu)
if ( V_58 ++ == V_300 )
return V_8 ;
return NULL ;
}
T_3 F_177 ( unsigned int V_300 )
{
struct V_7 * V_8 = F_176 ( V_300 ) ;
if ( V_8 )
return V_8 -> V_203 ;
return 0 ;
}
bool F_178 ( void )
{
return V_202 ;
}
T_3 F_179 ( unsigned int V_300 )
{
struct V_7 * V_8 = F_176 ( V_300 ) ;
if ( V_8 )
return V_8 -> V_204 ;
return 0 ;
}
static int F_92 ( struct V_7 * V_8 , T_3 V_348 , T_3 V_349 ,
T_3 V_350 , T_4 * V_175 , bool V_351 )
{
T_2 V_352 ;
T_2 V_353 ;
if ( ! V_202 )
return - V_61 ;
if ( F_33 ( ! V_8 || ( V_350 > 0x28 ) || ( V_350 & 7 ) ) )
return - V_61 ;
V_352 = ( T_2 ) ( ( ( 0x40 | V_348 ) << 12 ) | ( V_349 << 8 ) | V_350 ) ;
V_353 = ( T_2 ) ( ( ( 0x40 | V_8 -> V_203 ) << 12 ) |
( V_8 -> V_204 << 8 ) | 0x28 ) ;
if ( ( V_352 < V_354 ) ||
( V_352 > V_353 ) )
return - V_49 ;
if ( V_351 ) {
T_4 V_11 = * V_175 & F_180 ( 47 , 0 ) ;
F_18 ( ( T_2 ) V_11 , V_8 -> V_20 + V_352 ) ;
F_18 ( ( V_11 >> 32 ) , V_8 -> V_20 + V_352 + 4 ) ;
} else {
* V_175 = F_17 ( V_8 -> V_20 + V_352 + 4 ) ;
* V_175 <<= 32 ;
* V_175 |= F_17 ( V_8 -> V_20 + V_352 ) ;
* V_175 &= F_180 ( 47 , 0 ) ;
}
return 0 ;
}
int F_181 ( struct V_7 * V_8 , T_3 V_348 , T_3 V_349 , T_3 V_350 , T_4 * V_175 )
{
if ( ! V_8 )
return - V_49 ;
return F_92 ( V_8 , V_348 , V_349 , V_350 , V_175 , false ) ;
}
int F_182 ( struct V_7 * V_8 , T_3 V_348 , T_3 V_349 , T_3 V_350 , T_4 * V_175 )
{
if ( ! V_8 )
return - V_49 ;
return F_92 ( V_8 , V_348 , V_349 , V_350 , V_175 , true ) ;
}
