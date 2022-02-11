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
F_18 ( V_7 , V_35 ) ;
F_18 ( V_7 , V_36 ) ;
F_18 ( V_7 , V_31 ) ;
}
static T_3 T_5 * T_6 F_22 ( T_4 V_9 , T_4 V_37 )
{
if ( ! F_23 ( V_9 , V_37 , L_1 ) ) {
F_24 ( L_2 ,
V_9 , V_37 ) ;
F_24 ( L_3 ) ;
return NULL ;
}
return ( T_3 T_5 * ) F_25 ( V_9 , V_37 ) ;
}
static void T_6 F_26 ( struct V_6 * V_7 )
{
if ( V_7 -> V_19 )
F_27 ( V_7 -> V_19 ) ;
F_28 ( V_7 -> V_38 , V_7 -> V_39 ) ;
}
static inline T_2 F_29 ( struct V_40 * V_41 )
{
T_2 V_42 = 0 ;
switch ( V_41 -> type ) {
case 0x10 :
V_42 = 24 ;
break;
case 0x11 :
case 0x40 :
V_42 = 40 ;
break;
}
return V_42 ;
}
static inline int F_30 ( T_3 * V_43 )
{
T_2 type = ( (struct V_44 * ) V_43 ) -> type ;
if ( type < 0x80 ) {
return 0x04 << ( * V_43 >> 6 ) ;
} else if ( type == V_45 ) {
return * ( ( T_3 * ) V_43 + 21 ) + 22 ;
}
return 0 ;
}
static int T_6 F_31 ( struct V_40 * V_41 )
{
T_3 * V_46 = ( void * ) V_41 , * V_37 = ( void * ) V_41 ;
struct V_44 * V_11 ;
T_2 V_47 = F_29 ( V_41 ) ;
if ( ! V_47 ) {
F_24 ( L_4 , V_41 -> type ) ;
return - V_48 ;
}
V_46 += V_47 ;
V_37 += V_41 -> V_49 ;
while ( V_46 < V_37 ) {
V_11 = (struct V_44 * ) V_46 ;
switch ( V_11 -> type ) {
case V_50 :
F_1 ( 0xffff ) ;
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
F_1 ( V_11 -> V_1 ) ;
break;
default:
break;
}
V_46 += F_30 ( V_46 ) ;
}
F_32 ( V_46 != V_37 ) ;
return 0 ;
}
static int T_6 F_33 ( struct V_55 * V_56 )
{
int V_57 ;
T_3 V_58 = 0 , * V_46 = ( T_3 * ) V_56 ;
for ( V_57 = 0 ; V_57 < V_56 -> V_49 ; ++ V_57 )
V_58 += V_46 [ V_57 ] ;
if ( V_58 != 0 ) {
F_24 ( V_59 L_5 ) ;
return - V_60 ;
}
return 0 ;
}
static int T_6 F_34 ( struct V_55 * V_56 )
{
T_3 * V_46 = ( T_3 * ) V_56 , * V_37 = ( T_3 * ) V_56 ;
struct V_40 * V_41 ;
V_46 += V_61 ;
V_37 += V_56 -> V_49 ;
while ( V_46 < V_37 ) {
V_41 = (struct V_40 * ) V_46 ;
if ( V_41 -> type == V_62 ) {
int V_63 = F_31 ( V_41 ) ;
if ( V_63 )
return V_63 ;
}
V_46 += V_41 -> V_49 ;
}
F_32 ( V_46 != V_37 ) ;
return 0 ;
}
static int T_6 F_35 ( struct V_6 * V_7 )
{
V_7 -> V_64 = ( void * ) F_36 ( V_65 | V_66 ,
F_3 ( V_67 ) ) ;
return V_7 -> V_64 ? 0 : - V_68 ;
}
void F_37 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_32 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_69 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_70 ) ;
F_15 ( V_7 , V_32 ) ;
}
static void F_38 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_64 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_64 ) ;
V_17 |= V_71 ;
F_11 ( V_7 -> V_19 + V_72 ,
& V_17 , sizeof( V_17 ) ) ;
F_37 ( V_7 ) ;
}
static void T_6 F_39 ( struct V_6 * V_7 )
{
F_40 ( ( unsigned long ) V_7 -> V_64 , F_3 ( V_67 ) ) ;
}
static int T_6 F_41 ( struct V_6 * V_7 )
{
V_7 -> V_73 = ( void * ) F_36 ( V_65 | V_66 ,
F_3 ( V_74 ) ) ;
return V_7 -> V_73 ? 0 : - V_68 ;
}
static void F_42 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_73 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_73 ) | V_75 ;
F_11 ( V_7 -> V_19 + V_76 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_77 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_78 ) ;
F_15 ( V_7 , V_34 ) ;
}
static void T_6 F_43 ( struct V_6 * V_7 )
{
F_40 ( ( unsigned long ) V_7 -> V_73 , F_3 ( V_74 ) ) ;
}
static int T_6 F_44 ( struct V_6 * V_7 )
{
V_7 -> V_79 = ( void * ) F_36 ( V_65 | V_66 ,
F_3 ( V_80 ) ) ;
return V_7 -> V_79 ? 0 : - V_68 ;
}
static void F_45 ( struct V_6 * V_7 )
{
T_4 V_17 ;
if ( V_7 -> V_79 == NULL )
return;
V_17 = ( T_4 ) F_14 ( V_7 -> V_79 ) | V_81 ;
F_11 ( V_7 -> V_19 + V_82 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_83 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_84 ) ;
F_15 ( V_7 , V_85 ) ;
F_15 ( V_7 , V_86 ) ;
}
static void T_6 F_46 ( struct V_6 * V_7 )
{
if ( V_7 -> V_79 == NULL )
return;
F_40 ( ( unsigned long ) V_7 -> V_79 , F_3 ( V_80 ) ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
#ifdef F_48
if ( V_7 -> V_87 )
F_40 ( ( unsigned long ) V_7 -> V_87 ,
F_3 ( V_88 ) ) ;
if ( V_7 -> V_89 )
F_40 ( ( unsigned long ) V_7 -> V_89 ,
F_3 ( 8 ) ) ;
#endif
}
static int F_49 ( struct V_6 * V_7 )
{
#ifdef F_48
T_2 V_90 , V_57 ;
if ( ! V_7 -> V_87 )
return - V_48 ;
V_90 = F_16 ( V_7 -> V_19 + V_91 ) ;
if ( V_90 & ( V_92 ) )
return 0 ;
F_15 ( V_7 , V_36 ) ;
F_15 ( V_7 , V_35 ) ;
for ( V_57 = 0 ; V_57 < V_93 ; ++ V_57 ) {
V_90 = F_16 ( V_7 -> V_19 + V_91 ) ;
if ( V_90 & ( V_92 ) )
break;
}
if ( V_57 >= V_93 )
return - V_48 ;
#endif
return 0 ;
}
static int F_50 ( struct V_6 * V_7 )
{
T_4 V_17 ;
if ( ! F_51 ( V_94 ) )
return 0 ;
V_7 -> V_87 = ( T_3 * ) F_36 ( V_65 | V_66 ,
F_3 ( V_88 ) ) ;
if ( ! V_7 -> V_87 )
goto V_95;
V_7 -> V_89 = ( T_3 * ) F_36 ( V_65 | V_66 ,
F_3 ( 8 ) ) ;
if ( ! V_7 -> V_89 )
goto V_95;
V_17 = ( T_4 ) F_14 ( V_7 -> V_87 ) | V_96 ;
F_11 ( V_7 -> V_19 + V_97 ,
& V_17 , sizeof( V_17 ) ) ;
V_17 = ( ( T_4 ) F_14 ( V_7 -> V_87 ) & 0xFFFFFFFFFFFFFULL ) & ~ 7ULL ;
F_11 ( V_7 -> V_19 + V_98 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_99 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_100 ) ;
return 0 ;
V_95:
F_47 ( V_7 ) ;
return - V_48 ;
}
static int F_52 ( struct V_6 * V_7 )
{
int V_63 = 0 ;
#ifdef F_48
if ( F_51 ( V_94 ) &&
! F_53 ( V_7 , V_101 ) )
V_94 = V_102 ;
V_63 = F_50 ( V_7 ) ;
#endif
return V_63 ;
}
static void F_54 ( struct V_6 * V_7 )
{
if ( ! F_53 ( V_7 , V_103 ) )
return;
F_15 ( V_7 , V_104 ) ;
}
static void F_55 ( T_1 V_1 , T_3 V_25 )
{
int V_57 = ( V_25 >> 6 ) & 0x03 ;
int V_105 = V_25 & 0x3f ;
V_22 [ V_1 ] . V_106 [ V_57 ] |= ( 1UL << V_105 ) ;
}
static int F_56 ( T_1 V_1 , T_3 V_25 )
{
int V_57 = ( V_25 >> 6 ) & 0x03 ;
int V_105 = V_25 & 0x3f ;
return ( V_22 [ V_1 ] . V_106 [ V_57 ] & ( 1UL << V_105 ) ) >> V_105 ;
}
void F_57 ( T_1 V_1 )
{
int V_107 ;
V_107 = F_56 ( V_1 , V_108 ) |
( F_56 ( V_1 , V_109 ) << 1 ) ;
if ( V_107 == 0x01 )
F_55 ( V_1 , V_110 ) ;
}
static void T_6 F_58 ( struct V_6 * V_7 , T_1 V_1 )
{
V_111 [ V_1 ] = V_7 ;
}
static void T_6 F_59 ( struct V_6 * V_7 ,
T_1 V_1 , T_2 V_112 , T_2 V_113 )
{
if ( V_112 & V_114 )
F_55 ( V_1 , V_115 ) ;
if ( V_112 & V_116 )
F_55 ( V_1 , V_117 ) ;
if ( V_112 & V_118 )
F_55 ( V_1 , V_119 ) ;
if ( V_112 & V_120 )
F_55 ( V_1 , V_108 ) ;
if ( V_112 & V_121 )
F_55 ( V_1 , V_109 ) ;
if ( V_112 & V_122 )
F_55 ( V_1 , V_123 ) ;
if ( V_112 & V_124 )
F_55 ( V_1 , V_125 ) ;
F_57 ( V_1 ) ;
F_58 ( V_7 , V_1 ) ;
}
static int T_6 F_60 ( T_3 type , T_3 V_126 , T_1 * V_1 , bool V_127 )
{
struct V_128 * V_17 ;
struct V_129 * V_130 ;
if ( type == V_131 )
V_130 = & V_132 ;
else if ( type == V_133 )
V_130 = & V_134 ;
else
return - V_48 ;
F_61 (entry, list, list) {
if ( ! ( V_17 -> V_126 == V_126 && V_17 -> V_127 ) )
continue;
F_62 ( L_6 ,
type == V_131 ? L_7 : L_8 , V_126 ) ;
* V_1 = V_17 -> V_1 ;
return 0 ;
}
V_17 = F_63 ( sizeof( * V_17 ) , V_65 ) ;
if ( ! V_17 )
return - V_68 ;
V_17 -> V_126 = V_126 ;
V_17 -> V_1 = * V_1 ;
V_17 -> V_127 = V_127 ;
F_64 ( & V_17 -> V_130 , V_130 ) ;
return 0 ;
}
static int T_6 F_65 ( T_3 * V_135 , T_3 * V_136 , T_1 * V_1 ,
bool V_127 )
{
struct V_137 * V_17 ;
struct V_129 * V_130 = & V_138 ;
F_61 (entry, list, list) {
if ( strcmp ( V_17 -> V_135 , V_135 ) ||
( * V_136 && * V_17 -> V_136 && strcmp ( V_17 -> V_136 , V_136 ) ) ||
! V_17 -> V_127 )
continue;
F_62 ( L_9 ,
V_135 , V_136 ) ;
* V_1 = V_17 -> V_1 ;
return 0 ;
}
V_17 = F_63 ( sizeof( * V_17 ) , V_65 ) ;
if ( ! V_17 )
return - V_68 ;
memcpy ( V_17 -> V_136 , V_136 , strlen ( V_136 ) ) ;
memcpy ( V_17 -> V_135 , V_135 , strlen ( V_135 ) ) ;
V_17 -> V_1 = * V_1 ;
V_17 -> V_127 = V_127 ;
V_17 -> V_139 = ( V_17 -> V_1 & ( ~ 0x7 ) ) ;
F_62 ( L_10 ,
V_17 -> V_127 ? L_11 : L_12 ,
V_17 -> V_135 , V_17 -> V_136 , V_17 -> V_139 ) ;
F_64 ( & V_17 -> V_130 , V_130 ) ;
return 0 ;
}
static int T_6 F_66 ( void )
{
int V_57 , V_63 ;
for ( V_57 = 0 ; V_57 < V_140 ; ++ V_57 ) {
V_63 = F_60 ( V_131 ,
V_141 [ V_57 ] . V_126 ,
& V_141 [ V_57 ] . V_1 ,
V_141 [ V_57 ] . V_127 ) ;
if ( V_63 )
return V_63 ;
}
for ( V_57 = 0 ; V_57 < V_142 ; ++ V_57 ) {
V_63 = F_60 ( V_133 ,
V_143 [ V_57 ] . V_126 ,
& V_143 [ V_57 ] . V_1 ,
V_143 [ V_57 ] . V_127 ) ;
if ( V_63 )
return V_63 ;
}
for ( V_57 = 0 ; V_57 < V_144 ; ++ V_57 ) {
V_63 = F_65 ( V_145 [ V_57 ] . V_135 ,
V_145 [ V_57 ] . V_136 ,
& V_145 [ V_57 ] . V_1 ,
V_145 [ V_57 ] . V_127 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static void T_6 F_67 ( T_1 V_1 , struct V_146 * V_147 )
{
struct V_6 * V_7 = V_111 [ V_1 ] ;
if ( ! ( V_147 -> V_112 & V_148 ) )
return;
if ( V_7 ) {
F_55 ( V_1 , V_149 ) ;
V_7 -> V_13 = V_147 -> V_150 ;
V_7 -> V_16 = V_147 -> V_151 ;
}
}
static int T_6 F_68 ( struct V_6 * V_7 ,
struct V_40 * V_41 )
{
T_3 * V_46 = ( T_3 * ) V_41 ;
T_3 * V_37 = V_46 , V_112 = 0 ;
T_1 V_1 = 0 , V_152 = 0 , V_153 = 0 ;
T_2 V_154 , V_113 = 0 ;
bool V_155 = false ;
struct V_44 * V_156 ;
T_2 V_47 ;
int V_63 ;
V_63 = F_66 () ;
if ( V_63 )
return V_63 ;
V_7 -> V_157 = V_41 -> V_112 ;
V_47 = F_29 ( V_41 ) ;
if ( ! V_47 ) {
F_24 ( L_4 , V_41 -> type ) ;
return - V_48 ;
}
V_46 += V_47 ;
V_37 += V_41 -> V_49 ;
while ( V_46 < V_37 ) {
V_156 = (struct V_44 * ) V_46 ;
switch ( V_156 -> type ) {
case V_50 :
F_69 ( L_13 , V_156 -> V_112 ) ;
for ( V_154 = 0 ; V_154 <= V_2 ; ++ V_154 )
F_59 ( V_7 , V_154 , V_156 -> V_112 , 0 ) ;
break;
case V_51 :
F_69 ( L_14
L_15 ,
F_70 ( V_156 -> V_1 ) ,
F_71 ( V_156 -> V_1 ) ,
F_72 ( V_156 -> V_1 ) ,
V_156 -> V_112 ) ;
V_1 = V_156 -> V_1 ;
F_59 ( V_7 , V_1 , V_156 -> V_112 , 0 ) ;
break;
case V_158 :
F_69 ( L_16
L_17 ,
F_70 ( V_156 -> V_1 ) ,
F_71 ( V_156 -> V_1 ) ,
F_72 ( V_156 -> V_1 ) ,
V_156 -> V_112 ) ;
V_152 = V_156 -> V_1 ;
V_112 = V_156 -> V_112 ;
V_113 = 0 ;
V_155 = false ;
break;
case V_53 :
F_69 ( L_18
L_19 ,
F_70 ( V_156 -> V_1 ) ,
F_71 ( V_156 -> V_1 ) ,
F_72 ( V_156 -> V_1 ) ,
V_156 -> V_112 ,
F_70 ( V_156 -> V_159 >> 8 ) ,
F_71 ( V_156 -> V_159 >> 8 ) ,
F_72 ( V_156 -> V_159 >> 8 ) ) ;
V_1 = V_156 -> V_1 ;
V_153 = V_156 -> V_159 >> 8 ;
F_59 ( V_7 , V_1 , V_156 -> V_112 , 0 ) ;
F_59 ( V_7 , V_153 , V_156 -> V_112 , 0 ) ;
V_160 [ V_1 ] = V_153 ;
break;
case V_161 :
F_69 ( L_20
L_21
L_22 ,
F_70 ( V_156 -> V_1 ) ,
F_71 ( V_156 -> V_1 ) ,
F_72 ( V_156 -> V_1 ) ,
V_156 -> V_112 ,
F_70 ( V_156 -> V_159 >> 8 ) ,
F_71 ( V_156 -> V_159 >> 8 ) ,
F_72 ( V_156 -> V_159 >> 8 ) ) ;
V_152 = V_156 -> V_1 ;
V_112 = V_156 -> V_112 ;
V_153 = V_156 -> V_159 >> 8 ;
V_113 = 0 ;
V_155 = true ;
break;
case V_54 :
F_69 ( L_23
L_24 ,
F_70 ( V_156 -> V_1 ) ,
F_71 ( V_156 -> V_1 ) ,
F_72 ( V_156 -> V_1 ) ,
V_156 -> V_112 , V_156 -> V_159 ) ;
V_1 = V_156 -> V_1 ;
F_59 ( V_7 , V_1 , V_156 -> V_112 ,
V_156 -> V_159 ) ;
break;
case V_162 :
F_69 ( L_25
L_26 ,
F_70 ( V_156 -> V_1 ) ,
F_71 ( V_156 -> V_1 ) ,
F_72 ( V_156 -> V_1 ) ,
V_156 -> V_112 , V_156 -> V_159 ) ;
V_152 = V_156 -> V_1 ;
V_112 = V_156 -> V_112 ;
V_113 = V_156 -> V_159 ;
V_155 = false ;
break;
case V_52 :
F_69 ( L_27 ,
F_70 ( V_156 -> V_1 ) ,
F_71 ( V_156 -> V_1 ) ,
F_72 ( V_156 -> V_1 ) ) ;
V_1 = V_156 -> V_1 ;
for ( V_154 = V_152 ; V_154 <= V_1 ; ++ V_154 ) {
if ( V_155 ) {
V_160 [ V_154 ] = V_153 ;
F_59 ( V_7 ,
V_153 , V_112 , V_113 ) ;
}
F_59 ( V_7 , V_154 ,
V_112 , V_113 ) ;
}
break;
case V_163 : {
T_3 V_164 , type ;
const char * V_165 ;
T_1 V_1 ;
int V_63 ;
V_164 = V_156 -> V_159 & 0xff ;
V_1 = ( V_156 -> V_159 >> 8 ) & 0xffff ;
type = ( V_156 -> V_159 >> 24 ) & 0xff ;
if ( type == V_131 )
V_165 = L_7 ;
else if ( type == V_133 )
V_165 = L_8 ;
else
V_165 = L_28 ;
F_69 ( L_29 ,
V_165 , ( int ) V_164 ,
F_70 ( V_1 ) ,
F_71 ( V_1 ) ,
F_72 ( V_1 ) ) ;
V_63 = F_60 ( type , V_164 , & V_1 , false ) ;
if ( V_63 )
return V_63 ;
F_59 ( V_7 , V_1 , V_156 -> V_112 , 0 ) ;
break;
}
case V_45 : {
T_1 V_1 ;
T_3 V_135 [ V_166 ] = { 0 } ;
T_3 V_136 [ V_167 ] = { 0 } ;
int V_63 ;
if ( V_41 -> type != 0x40 ) {
F_24 ( V_59 L_30 ,
V_156 -> type ) ;
break;
}
memcpy ( V_135 , ( T_3 * ) ( & V_156 -> V_159 ) , V_166 - 1 ) ;
V_135 [ V_166 - 1 ] = '\0' ;
if ( ! ( * V_135 ) ) {
F_24 ( V_59 L_31 ) ;
break;
}
switch ( V_156 -> V_168 ) {
case V_169 :
if ( V_156 -> V_170 != 0 )
F_73 ( V_59 L_32 ) ;
break;
case V_171 :
sprintf ( V_136 , L_33 , V_156 -> V_136 ) ;
break;
case V_172 :
memcpy ( V_136 , ( T_3 * ) ( & V_156 -> V_136 ) , V_167 - 1 ) ;
V_136 [ V_167 - 1 ] = '\0' ;
break;
default:
break;
}
V_1 = V_156 -> V_1 ;
F_69 ( L_34 ,
V_135 , V_136 ,
F_70 ( V_1 ) ,
F_71 ( V_1 ) ,
F_72 ( V_1 ) ) ;
V_112 = V_156 -> V_112 ;
V_63 = F_65 ( V_135 , V_136 , & V_1 , false ) ;
if ( V_63 )
return V_63 ;
F_59 ( V_7 , V_1 , V_156 -> V_112 , 0 ) ;
break;
}
default:
break;
}
V_46 += F_30 ( V_46 ) ;
}
return 0 ;
}
static void T_6 F_74 ( struct V_6 * V_7 )
{
F_39 ( V_7 ) ;
F_43 ( V_7 ) ;
F_46 ( V_7 ) ;
F_47 ( V_7 ) ;
F_26 ( V_7 ) ;
}
static void T_6 F_75 ( void )
{
struct V_6 * V_7 , * V_173 ;
F_76 (iommu, next) {
F_77 ( & V_7 -> V_130 ) ;
F_74 ( V_7 ) ;
F_78 ( V_7 ) ;
}
}
static void F_79 ( struct V_6 * V_7 )
{
T_2 V_174 ;
if ( ( V_175 . V_176 != 0x15 ) ||
( V_175 . V_177 < 0x10 ) ||
( V_175 . V_177 > 0x1f ) )
return;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 ) ;
F_6 ( V_7 -> V_11 , 0xf4 , & V_174 ) ;
if ( V_174 & F_80 ( 2 ) )
return;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 | ( 1 << 8 ) ) ;
F_5 ( V_7 -> V_11 , 0xf4 , V_174 | 0x4 ) ;
F_62 ( L_35 ,
F_81 ( & V_7 -> V_11 -> V_11 ) ) ;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 ) ;
}
static void F_82 ( struct V_6 * V_7 )
{
T_2 V_174 ;
if ( ( V_175 . V_176 != 0x15 ) ||
( V_175 . V_177 < 0x30 ) ||
( V_175 . V_177 > 0x3f ) )
return;
V_174 = F_8 ( V_7 , 0x47 ) ;
if ( V_174 & F_80 ( 0 ) )
return;
F_9 ( V_7 , 0x47 , V_174 | F_80 ( 0 ) ) ;
F_62 ( L_36 ,
F_81 ( & V_7 -> V_11 -> V_11 ) ) ;
}
static int T_6 F_83 ( struct V_6 * V_7 , struct V_40 * V_41 )
{
int V_63 ;
F_84 ( & V_7 -> V_178 ) ;
F_64 ( & V_7 -> V_130 , & V_179 ) ;
V_7 -> V_180 = V_181 ++ ;
if ( F_85 ( V_7 -> V_180 >= V_182 ) ) {
F_86 ( 1 , L_37 ) ;
return - V_183 ;
}
V_184 [ V_7 -> V_180 ] = V_7 ;
V_7 -> V_1 = V_41 -> V_1 ;
V_7 -> V_185 = V_41 -> V_185 ;
V_7 -> V_186 = V_41 -> V_186 ;
V_7 -> V_38 = V_41 -> V_38 ;
switch ( V_41 -> type ) {
case 0x10 :
if ( ( V_41 -> V_187 != 0 ) &&
( ( V_41 -> V_187 & ( 0xF << 13 ) ) != 0 ) &&
( ( V_41 -> V_187 & ( 0x3F << 17 ) ) != 0 ) )
V_7 -> V_39 = V_188 ;
else
V_7 -> V_39 = V_189 ;
if ( ( ( V_41 -> V_187 & ( 0x1 << V_190 ) ) == 0 ) )
V_94 = V_191 ;
break;
case 0x11 :
case 0x40 :
if ( V_41 -> V_192 & ( 1 << 9 ) )
V_7 -> V_39 = V_188 ;
else
V_7 -> V_39 = V_189 ;
if ( ( ( V_41 -> V_192 & ( 0x1 << V_193 ) ) == 0 ) )
V_94 = V_191 ;
break;
default:
return - V_48 ;
}
V_7 -> V_19 = F_22 ( V_7 -> V_38 ,
V_7 -> V_39 ) ;
if ( ! V_7 -> V_19 )
return - V_68 ;
if ( F_35 ( V_7 ) )
return - V_68 ;
if ( F_41 ( V_7 ) )
return - V_68 ;
V_7 -> V_194 = false ;
V_63 = F_68 ( V_7 , V_41 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_87 ( V_7 ) ;
if ( V_63 )
return V_63 ;
V_111 [ V_7 -> V_1 ] = NULL ;
return 0 ;
}
static T_3 F_88 ( struct V_55 * V_195 )
{
T_3 * V_196 = ( T_3 * ) V_195 ;
struct V_40 * V_43 = (struct V_40 * )
( V_196 + V_61 ) ;
T_3 V_197 = V_43 -> type ;
T_1 V_1 = V_43 -> V_1 ;
while ( ( ( T_3 * ) V_43 - V_196 < V_195 -> V_49 ) &&
( V_43 -> type <= V_198 ) ) {
T_3 * V_46 = ( T_3 * ) V_43 ;
if ( V_43 -> V_1 == V_1 )
V_197 = V_43 -> type ;
V_43 = (struct V_40 * ) ( V_46 + V_43 -> V_49 ) ;
}
return V_197 ;
}
static int T_6 F_89 ( struct V_55 * V_56 )
{
T_3 * V_46 = ( T_3 * ) V_56 , * V_37 = ( T_3 * ) V_56 ;
struct V_40 * V_41 ;
struct V_6 * V_7 ;
int V_63 ;
V_37 += V_56 -> V_49 ;
V_46 += V_61 ;
while ( V_46 < V_37 ) {
V_41 = (struct V_40 * ) V_46 ;
if ( * V_46 == V_62 ) {
F_69 ( L_38
L_39 ,
F_70 ( V_41 -> V_1 ) , F_71 ( V_41 -> V_1 ) ,
F_72 ( V_41 -> V_1 ) , V_41 -> V_185 ,
V_41 -> V_186 , V_41 -> V_112 , V_41 -> V_199 ) ;
F_69 ( L_40 ,
V_41 -> V_38 ) ;
V_7 = F_63 ( sizeof( struct V_6 ) , V_65 ) ;
if ( V_7 == NULL )
return - V_68 ;
V_63 = F_83 ( V_7 , V_41 ) ;
if ( V_63 )
return V_63 ;
}
V_46 += V_41 -> V_49 ;
}
F_32 ( V_46 != V_37 ) ;
return 0 ;
}
static void F_90 ( struct V_6 * V_7 )
{
T_4 V_10 = 0xabcd , V_200 = 0 ;
if ( ! F_53 ( V_7 , V_201 ) )
return;
V_202 = true ;
if ( ( 0 != F_91 ( V_7 , 0 , 0 , 0 , & V_10 , true ) ) ||
( 0 != F_91 ( V_7 , 0 , 0 , 0 , & V_200 , false ) ) ||
( V_10 != V_200 ) ) {
F_24 ( L_41 ) ;
V_202 = false ;
return;
}
F_62 ( L_42 ) ;
V_10 = F_16 ( V_7 -> V_19 + V_189 ) ;
V_7 -> V_203 = ( T_3 ) ( ( V_10 >> 12 ) & 0x3f ) ;
V_7 -> V_204 = ( T_3 ) ( ( V_10 >> 7 ) & 0xf ) ;
}
static T_7 F_92 ( struct V_205 * V_11 ,
struct V_206 * V_207 ,
char * V_208 )
{
struct V_6 * V_7 = F_93 ( V_11 ) ;
return sprintf ( V_208 , L_43 , V_7 -> V_209 ) ;
}
static T_7 F_94 ( struct V_205 * V_11 ,
struct V_206 * V_207 ,
char * V_208 )
{
struct V_6 * V_7 = F_93 ( V_11 ) ;
return sprintf ( V_208 , L_44 , V_7 -> V_210 ) ;
}
static int F_95 ( struct V_6 * V_7 )
{
int V_185 = V_7 -> V_185 ;
T_2 V_211 , V_212 , V_213 , V_214 ;
int V_63 ;
V_7 -> V_11 = F_96 ( F_70 ( V_7 -> V_1 ) ,
V_7 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return - V_60 ;
V_7 -> V_11 -> V_215 = false ;
F_6 ( V_7 -> V_11 , V_185 + V_216 ,
& V_7 -> V_209 ) ;
F_6 ( V_7 -> V_11 , V_185 + V_217 ,
& V_211 ) ;
F_6 ( V_7 -> V_11 , V_185 + V_218 ,
& V_212 ) ;
if ( ! ( V_7 -> V_209 & ( 1 << V_219 ) ) )
V_220 = false ;
V_213 = F_16 ( V_7 -> V_19 + V_221 ) ;
V_214 = F_16 ( V_7 -> V_19 + V_221 + 4 ) ;
V_7 -> V_210 = ( ( T_4 ) V_214 << 32 ) | V_213 ;
if ( F_53 ( V_7 , V_103 ) ) {
int V_222 ;
T_2 V_223 ;
T_4 V_224 ;
V_224 = V_7 -> V_210 & V_225 ;
V_224 >>= V_226 ;
V_223 = ( 1 << ( V_224 + 1 ) ) - 1 ;
V_227 = F_97 ( V_227 , V_223 ) ;
F_13 ( V_227 & ~ V_228 ) ;
V_222 = V_7 -> V_210 & V_229 ;
V_222 >>= V_230 ;
if ( V_231 == - 1 )
V_231 = V_222 ;
else
V_231 = F_97 ( V_231 , V_222 ) ;
}
if ( F_53 ( V_7 , V_103 ) &&
F_53 ( V_7 , V_232 ) ) {
V_7 -> V_233 = true ;
V_234 = true ;
}
if ( F_53 ( V_7 , V_232 ) && F_44 ( V_7 ) )
return - V_68 ;
V_63 = F_52 ( V_7 ) ;
if ( V_63 )
return V_63 ;
if ( V_7 -> V_209 & ( 1UL << V_235 ) )
V_236 = true ;
F_90 ( V_7 ) ;
if ( F_98 ( V_7 -> V_11 ) ) {
int V_57 , V_237 ;
V_7 -> V_238 = F_96 ( V_7 -> V_11 -> V_239 -> V_240 ,
F_99 ( 0 , 0 ) ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_185 + 4 ,
& V_7 -> V_241 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_185 + 8 ,
& V_7 -> V_242 ) ;
V_7 -> V_241 &= ~ 1 ;
for ( V_57 = 0 ; V_57 < 6 ; V_57 ++ )
for ( V_237 = 0 ; V_237 < 0x12 ; V_237 ++ )
V_7 -> V_243 [ V_57 ] [ V_237 ] = F_4 ( V_7 , V_57 , V_237 ) ;
for ( V_57 = 0 ; V_57 < 0x83 ; V_57 ++ )
V_7 -> V_244 [ V_57 ] = F_8 ( V_7 , V_57 ) ;
}
F_79 ( V_7 ) ;
F_82 ( V_7 ) ;
F_100 ( & V_7 -> V_7 , & V_7 -> V_11 -> V_11 ,
V_245 , L_45 , V_7 -> V_180 ) ;
F_101 ( & V_7 -> V_7 , & V_246 ) ;
F_102 ( & V_7 -> V_7 ) ;
return F_103 ( V_7 -> V_11 ) ;
}
static void F_104 ( void )
{
static const char * const V_247 [] = {
L_46 , L_47 , L_48 , L_49 , L_50 , L_51 ,
L_52 , L_53 , L_54 , L_55
} ;
struct V_6 * V_7 ;
F_105 (iommu) {
int V_57 ;
F_62 ( L_56 ,
F_81 ( & V_7 -> V_11 -> V_11 ) , V_7 -> V_185 ) ;
if ( V_7 -> V_209 & ( 1 << V_248 ) ) {
F_62 ( L_57 ,
V_7 -> V_210 ) ;
for ( V_57 = 0 ; V_57 < F_106 ( V_247 ) ; ++ V_57 ) {
if ( F_53 ( V_7 , ( 1ULL << V_57 ) ) )
F_107 ( L_58 , V_247 [ V_57 ] ) ;
}
if ( V_7 -> V_210 & V_101 )
F_107 ( L_59 ) ;
F_107 ( L_60 ) ;
}
}
if ( V_249 ) {
F_62 ( L_61 ) ;
if ( F_51 ( V_94 ) )
F_62 ( L_62 ) ;
}
}
static int T_6 F_108 ( void )
{
struct V_6 * V_7 ;
int V_63 = 0 ;
F_105 (iommu) {
V_63 = F_95 ( V_7 ) ;
if ( V_63 )
break;
}
V_63 = F_109 () ;
F_110 () ;
F_105 (iommu)
F_111 ( V_7 ) ;
if ( ! V_63 )
F_104 () ;
return V_63 ;
}
static int F_112 ( struct V_6 * V_7 )
{
int V_250 ;
V_250 = F_113 ( V_7 -> V_11 ) ;
if ( V_250 )
return V_250 ;
V_250 = F_114 ( V_7 -> V_11 -> V_251 ,
V_252 ,
V_253 ,
0 , L_63 ,
V_7 ) ;
if ( V_250 ) {
F_115 ( V_7 -> V_11 ) ;
return V_250 ;
}
V_7 -> V_194 = true ;
return 0 ;
}
static int F_116 ( struct V_6 * V_7 )
{
int V_63 ;
if ( V_7 -> V_194 )
goto V_254;
if ( V_7 -> V_11 -> V_255 )
V_63 = F_112 ( V_7 ) ;
else
V_63 = - V_60 ;
if ( V_63 )
return V_63 ;
V_254:
F_15 ( V_7 , V_33 ) ;
if ( V_7 -> V_79 != NULL )
F_15 ( V_7 , V_256 ) ;
F_49 ( V_7 ) ;
return 0 ;
}
static void T_6 F_117 ( void )
{
struct V_257 * V_17 , * V_173 ;
F_118 (entry, next, &amd_iommu_unity_map, list) {
F_77 ( & V_17 -> V_130 ) ;
F_78 ( V_17 ) ;
}
}
static int T_6 F_119 ( struct V_146 * V_147 )
{
int V_57 ;
switch ( V_147 -> type ) {
case V_258 :
F_67 ( V_147 -> V_1 , V_147 ) ;
break;
case V_259 :
for ( V_57 = 0 ; V_57 <= V_2 ; ++ V_57 )
F_67 ( V_57 , V_147 ) ;
break;
case V_260 :
for ( V_57 = V_147 -> V_1 ; V_57 <= V_147 -> V_261 ; ++ V_57 )
F_67 ( V_57 , V_147 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_120 ( struct V_146 * V_147 )
{
struct V_257 * V_156 = NULL ;
char * V_262 ;
V_156 = F_63 ( sizeof( * V_156 ) , V_65 ) ;
if ( V_156 == NULL )
return - V_68 ;
switch ( V_147 -> type ) {
default:
F_78 ( V_156 ) ;
return 0 ;
case V_258 :
V_262 = L_64 ;
V_156 -> V_152 = V_156 -> V_263 = V_147 -> V_1 ;
break;
case V_259 :
V_262 = L_65 ;
V_156 -> V_152 = 0 ;
V_156 -> V_263 = V_2 ;
break;
case V_260 :
V_262 = L_66 ;
V_156 -> V_152 = V_147 -> V_1 ;
V_156 -> V_263 = V_147 -> V_261 ;
break;
}
V_156 -> V_264 = F_121 ( V_147 -> V_150 ) ;
V_156 -> V_265 = V_156 -> V_264 + F_121 ( V_147 -> V_151 ) ;
V_156 -> V_266 = V_147 -> V_112 >> 1 ;
F_69 ( L_67
L_68 , V_262 ,
F_70 ( V_156 -> V_152 ) , F_71 ( V_156 -> V_152 ) ,
F_72 ( V_156 -> V_152 ) , F_70 ( V_156 -> V_263 ) ,
F_71 ( V_156 -> V_263 ) , F_72 ( V_156 -> V_263 ) ,
V_156 -> V_264 , V_156 -> V_265 , V_147 -> V_112 ) ;
F_64 ( & V_156 -> V_130 , & V_267 ) ;
return 0 ;
}
static int T_6 F_122 ( struct V_55 * V_56 )
{
T_3 * V_46 = ( T_3 * ) V_56 , * V_37 = ( T_3 * ) V_56 ;
struct V_146 * V_147 ;
V_37 += V_56 -> V_49 ;
V_46 += V_61 ;
while ( V_46 < V_37 ) {
V_147 = (struct V_146 * ) V_46 ;
if ( V_147 -> V_112 & V_148 )
F_119 ( V_147 ) ;
else if ( V_147 -> V_112 & V_268 )
F_120 ( V_147 ) ;
V_46 += V_147 -> V_49 ;
}
return 0 ;
}
static void F_110 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_55 ( V_1 , V_269 ) ;
F_55 ( V_1 , V_270 ) ;
}
}
static void T_6 F_123 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
V_22 [ V_1 ] . V_106 [ 0 ] = 0ULL ;
V_22 [ V_1 ] . V_106 [ 1 ] = 0ULL ;
}
}
static void F_124 ( void )
{
T_2 V_1 ;
if ( ! V_271 )
return;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 )
F_55 ( V_1 , V_272 ) ;
}
static void F_125 ( struct V_6 * V_7 )
{
V_7 -> V_157 & V_273 ?
F_15 ( V_7 , V_274 ) :
F_18 ( V_7 , V_274 ) ;
V_7 -> V_157 & V_275 ?
F_15 ( V_7 , V_276 ) :
F_18 ( V_7 , V_276 ) ;
V_7 -> V_157 & V_277 ?
F_15 ( V_7 , V_278 ) :
F_18 ( V_7 , V_278 ) ;
V_7 -> V_157 & V_279 ?
F_15 ( V_7 , V_280 ) :
F_18 ( V_7 , V_280 ) ;
F_15 ( V_7 , V_281 ) ;
F_19 ( V_7 , V_282 ) ;
}
static void F_126 ( struct V_6 * V_7 )
{
int V_57 , V_237 ;
T_2 V_283 ;
struct V_284 * V_285 = V_7 -> V_238 ;
if ( ! F_98 ( V_7 -> V_11 ) || ! V_285 )
return;
F_5 ( V_285 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_285 , 0x64 , & V_283 ) ;
if ( ! ( V_283 & 0x1 ) )
F_5 ( V_285 , 0x64 , V_283 | 1 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_185 + 4 ,
V_7 -> V_241 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_185 + 8 ,
V_7 -> V_242 ) ;
for ( V_57 = 0 ; V_57 < 6 ; V_57 ++ )
for ( V_237 = 0 ; V_237 < 0x12 ; V_237 ++ )
F_7 ( V_7 , V_57 , V_237 , V_7 -> V_243 [ V_57 ] [ V_237 ] ) ;
for ( V_57 = 0 ; V_57 < 0x83 ; V_57 ++ )
F_9 ( V_7 , V_57 , V_7 -> V_244 [ V_57 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_185 + 4 ,
V_7 -> V_241 | 1 ) ;
}
static void F_127 ( struct V_6 * V_7 )
{
#ifdef F_48
switch ( V_94 ) {
case F_51 :
F_15 ( V_7 , V_286 ) ;
case V_102 :
F_15 ( V_7 , V_287 ) ;
V_7 -> V_288 = & V_289 ;
break;
default:
V_7 -> V_288 = & V_290 ;
break;
}
#endif
}
static void F_128 ( void )
{
struct V_6 * V_7 ;
F_105 (iommu) {
F_21 ( V_7 ) ;
F_125 ( V_7 ) ;
F_12 ( V_7 ) ;
F_38 ( V_7 ) ;
F_42 ( V_7 ) ;
F_10 ( V_7 ) ;
F_127 ( V_7 ) ;
F_20 ( V_7 ) ;
F_111 ( V_7 ) ;
}
#ifdef F_48
if ( F_51 ( V_94 ) )
V_291 . V_292 |= ( 1 << V_293 ) ;
#endif
}
static void F_129 ( void )
{
struct V_6 * V_7 ;
F_105 (iommu) {
F_45 ( V_7 ) ;
F_54 ( V_7 ) ;
}
}
static void F_130 ( void )
{
F_128 () ;
F_129 () ;
}
static void F_131 ( void )
{
struct V_6 * V_7 ;
F_105 (iommu)
F_21 ( V_7 ) ;
#ifdef F_48
if ( F_51 ( V_94 ) )
V_291 . V_292 &= ~ ( 1 << V_293 ) ;
#endif
}
static void F_132 ( void )
{
struct V_6 * V_7 ;
F_105 (iommu)
F_126 ( V_7 ) ;
F_130 () ;
F_133 () ;
}
static int F_134 ( void )
{
F_131 () ;
return 0 ;
}
static void T_6 F_135 ( void )
{
F_136 ( V_294 ) ;
F_40 ( ( unsigned long ) V_294 ,
F_3 ( V_295 ) ) ;
F_137 ( V_296 ) ;
V_296 = NULL ;
F_40 ( ( unsigned long ) V_111 ,
F_3 ( V_295 ) ) ;
F_40 ( ( unsigned long ) V_160 ,
F_3 ( V_297 ) ) ;
F_40 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_75 () ;
#ifdef F_138
F_139 () ;
#endif
}
static bool T_6 F_140 ( void )
{
const char * V_298 = V_59 ;
bool V_63 , V_299 ;
int V_300 ;
V_299 = false ;
V_63 = false ;
if ( V_301 )
V_298 = L_69 ;
for ( V_300 = 0 ; V_300 < V_302 ; V_300 ++ ) {
int V_1 , V_126 = F_141 ( V_300 ) ;
V_1 = F_142 ( V_126 ) ;
if ( V_1 < 0 ) {
F_24 ( L_70 ,
V_298 , V_126 ) ;
V_63 = false ;
} else if ( V_1 == V_303 ) {
V_299 = true ;
V_63 = true ;
}
}
if ( ! V_299 ) {
F_24 ( L_71 , V_298 ) ;
}
if ( ! V_63 )
F_24 ( L_72 ) ;
return V_63 ;
}
static void T_6 F_143 ( void )
{
F_40 ( ( unsigned long ) V_304 ,
F_3 ( V_305 / 8 ) ) ;
F_117 () ;
}
static int T_6 F_144 ( void )
{
struct V_55 * V_306 ;
T_8 V_90 ;
int V_57 , V_307 , V_63 = 0 ;
if ( ! V_308 )
return - V_60 ;
V_90 = F_145 ( L_73 , 0 , & V_306 ) ;
if ( V_90 == V_309 )
return - V_60 ;
else if ( F_146 ( V_90 ) ) {
const char * V_310 = F_147 ( V_90 ) ;
F_24 ( L_74 , V_310 ) ;
return - V_48 ;
}
V_63 = F_33 ( V_306 ) ;
if ( V_63 )
goto V_311;
V_62 = F_88 ( V_306 ) ;
F_69 ( L_75 , V_62 ) ;
V_63 = F_34 ( V_306 ) ;
if ( V_63 )
goto V_311;
V_23 = F_2 ( V_312 ) ;
V_297 = F_2 ( V_313 ) ;
V_295 = F_2 ( V_314 ) ;
V_63 = - V_68 ;
V_22 = ( void * ) F_36 ( V_65 | V_66 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_311;
V_160 = ( void * ) F_36 ( V_65 ,
F_3 ( V_297 ) ) ;
if ( V_160 == NULL )
goto V_311;
V_111 = ( void * ) F_36 (
V_65 | V_66 ,
F_3 ( V_295 ) ) ;
if ( V_111 == NULL )
goto V_311;
V_304 = ( void * ) F_36 (
V_65 | V_66 ,
F_3 ( V_305 / 8 ) ) ;
if ( V_304 == NULL )
goto V_311;
for ( V_57 = 0 ; V_57 <= V_2 ; ++ V_57 )
V_160 [ V_57 ] = V_57 ;
F_148 ( 0 , V_304 ) ;
F_84 ( & V_315 ) ;
V_63 = F_89 ( V_306 ) ;
if ( V_63 )
goto V_311;
if ( V_271 )
V_271 = F_140 () ;
if ( V_271 ) {
V_63 = - V_68 ;
if ( ! F_149 ( V_94 ) )
V_307 = V_316 * sizeof( T_2 ) ;
else
V_307 = V_316 * ( sizeof( T_4 ) * 2 ) ;
V_296 = F_150 ( L_76 ,
V_307 ,
V_317 ,
0 , NULL ) ;
if ( ! V_296 )
goto V_311;
V_294 = ( void * ) F_36 (
V_65 | V_66 ,
F_3 ( V_295 ) ) ;
F_151 ( V_294 , V_295 ,
1 , V_65 ) ;
if ( ! V_294 )
goto V_311;
}
V_63 = F_122 ( V_306 ) ;
if ( V_63 )
goto V_311;
F_124 () ;
V_311:
F_152 ( V_306 ) ;
V_306 = NULL ;
return V_63 ;
}
static int F_133 ( void )
{
struct V_6 * V_7 ;
int V_63 = 0 ;
F_105 (iommu) {
V_63 = F_116 ( V_7 ) ;
if ( V_63 )
goto V_311;
}
V_311:
return V_63 ;
}
static bool F_153 ( void )
{
struct V_55 * V_306 ;
T_8 V_90 ;
V_90 = F_145 ( L_73 , 0 , & V_306 ) ;
if ( V_90 == V_309 )
return false ;
else if ( F_146 ( V_90 ) ) {
const char * V_310 = F_147 ( V_90 ) ;
F_24 ( L_74 , V_310 ) ;
return false ;
}
F_152 ( V_306 ) ;
F_154 () ;
return true ;
}
static int T_6 F_155 ( void )
{
int V_63 = 0 ;
switch ( V_318 ) {
case V_319 :
if ( ! F_153 () ) {
V_318 = V_320 ;
V_63 = - V_60 ;
} else {
V_318 = V_321 ;
}
break;
case V_321 :
V_63 = F_144 () ;
V_318 = V_63 ? V_322 : V_323 ;
break;
case V_323 :
F_128 () ;
F_156 ( & V_324 ) ;
V_325 . V_326 = F_131 ;
V_318 = V_327 ;
break;
case V_327 :
V_63 = F_108 () ;
V_318 = V_63 ? V_322 : V_328 ;
F_129 () ;
break;
case V_328 :
V_63 = F_133 () ;
V_318 = V_63 ? V_322 : V_329 ;
break;
case V_329 :
V_63 = F_157 () ;
V_318 = V_63 ? V_322 : V_330 ;
break;
case V_330 :
V_318 = V_331 ;
break;
case V_331 :
break;
case V_320 :
case V_322 :
V_63 = - V_48 ;
break;
default:
F_158 () ;
}
return V_63 ;
}
static int T_6 F_159 ( enum V_332 V_333 )
{
int V_63 = 0 ;
while ( V_318 != V_333 ) {
V_63 = F_155 () ;
if ( V_318 == V_320 ||
V_318 == V_322 )
break;
}
return V_63 ;
}
int T_6 F_160 ( void )
{
int V_63 ;
V_271 = true ;
V_63 = F_159 ( V_323 ) ;
if ( V_63 )
return V_63 ;
return V_271 ? 0 : - V_60 ;
}
int T_6 F_161 ( void )
{
int V_63 ;
V_63 = F_159 ( V_327 ) ;
if ( V_63 )
return V_63 ;
V_249 = 1 ;
return 0 ;
}
void F_162 ( void )
{
F_134 () ;
}
int F_163 ( int V_334 )
{
F_132 () ;
return 0 ;
}
int T_6 F_164 ( void )
{
return 0 ;
}
static int T_6 F_165 ( void )
{
int V_63 ;
V_63 = F_159 ( V_331 ) ;
if ( V_63 ) {
F_143 () ;
if ( ! V_249 ) {
F_131 () ;
F_135 () ;
} else {
struct V_6 * V_7 ;
F_123 () ;
F_105 (iommu)
F_111 ( V_7 ) ;
}
}
return V_63 ;
}
int T_6 F_166 ( void )
{
int V_63 ;
if ( V_335 || ( V_336 && ! V_337 ) )
return - V_60 ;
if ( V_338 )
return - V_60 ;
V_63 = F_159 ( V_321 ) ;
if ( V_63 )
return V_63 ;
V_308 = true ;
V_336 = 1 ;
V_339 . V_7 . V_340 = F_165 ;
return 1 ;
}
static int T_6 F_167 ( char * V_341 )
{
V_342 = true ;
return 1 ;
}
static int T_6 F_168 ( char * V_341 )
{
for (; * V_341 ; ++ V_341 ) {
if ( strncmp ( V_341 , L_77 , 6 ) == 0 ) {
V_94 = V_191 ;
break;
}
if ( strncmp ( V_341 , L_78 , 5 ) == 0 ) {
V_94 = F_51 ;
break;
}
}
return 1 ;
}
static int T_6 F_169 ( char * V_341 )
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
static int T_6 F_170 ( char * V_341 )
{
unsigned int V_239 , V_11 , V_345 ;
int V_63 , V_126 , V_57 ;
T_1 V_1 ;
V_63 = sscanf ( V_341 , L_82 , & V_126 , & V_239 , & V_11 , & V_345 ) ;
if ( V_63 != 4 ) {
F_24 ( L_83 , V_341 ) ;
return 1 ;
}
if ( V_140 == V_346 ) {
F_24 ( L_84 ,
V_341 ) ;
return 1 ;
}
V_1 = ( ( V_239 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_345 & 0x7 ) ;
V_301 = true ;
V_57 = V_140 ++ ;
V_141 [ V_57 ] . V_126 = V_126 ;
V_141 [ V_57 ] . V_1 = V_1 ;
V_141 [ V_57 ] . V_127 = true ;
return 1 ;
}
static int T_6 F_171 ( char * V_341 )
{
unsigned int V_239 , V_11 , V_345 ;
int V_63 , V_126 , V_57 ;
T_1 V_1 ;
V_63 = sscanf ( V_341 , L_82 , & V_126 , & V_239 , & V_11 , & V_345 ) ;
if ( V_63 != 4 ) {
F_24 ( L_85 , V_341 ) ;
return 1 ;
}
if ( V_142 == V_346 ) {
F_24 ( L_86 ,
V_341 ) ;
return 1 ;
}
V_1 = ( ( V_239 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_345 & 0x7 ) ;
V_301 = true ;
V_57 = V_142 ++ ;
V_143 [ V_57 ] . V_126 = V_126 ;
V_143 [ V_57 ] . V_1 = V_1 ;
V_143 [ V_57 ] . V_127 = true ;
return 1 ;
}
static int T_6 F_172 ( char * V_341 )
{
T_2 V_239 , V_11 , V_345 ;
char * V_135 , * V_136 , * V_46 ;
char V_347 [ V_167 + V_166 ] = { 0 } ;
int V_63 , V_57 ;
V_63 = sscanf ( V_341 , L_87 , & V_239 , & V_11 , & V_345 , V_347 ) ;
if ( V_63 != 4 ) {
F_24 ( L_88 , V_341 ) ;
return 1 ;
}
V_46 = V_347 ;
V_135 = F_173 ( & V_46 , L_89 ) ;
V_136 = V_46 ;
if ( ! V_135 || ! ( * V_135 ) || ! V_136 ) {
F_24 ( L_90 ) ;
return 1 ;
}
V_57 = V_144 ++ ;
memcpy ( V_145 [ V_57 ] . V_135 , V_135 , strlen ( V_135 ) ) ;
memcpy ( V_145 [ V_57 ] . V_136 , V_136 , strlen ( V_136 ) ) ;
V_145 [ V_57 ] . V_1 =
( ( V_239 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_345 & 0x7 ) ;
V_145 [ V_57 ] . V_127 = true ;
return 1 ;
}
bool F_174 ( void )
{
return V_234 ;
}
T_3 F_175 ( T_1 V_1 )
{
struct V_6 * V_7 ;
T_3 V_63 = 0 ;
V_7 = V_111 [ V_1 ] ;
if ( V_7 )
V_63 = V_7 -> V_203 ;
return V_63 ;
}
bool F_176 ( void )
{
return V_202 ;
}
T_3 F_177 ( T_1 V_1 )
{
struct V_6 * V_7 ;
T_3 V_63 = 0 ;
V_7 = V_111 [ V_1 ] ;
if ( V_7 )
V_63 = V_7 -> V_204 ;
return V_63 ;
}
static int F_91 ( struct V_6 * V_7 ,
T_3 V_348 , T_3 V_349 , T_3 V_350 ,
T_4 * V_174 , bool V_351 )
{
T_2 V_352 ;
T_2 V_353 ;
if ( F_32 ( ( V_350 > 0x28 ) || ( V_350 & 7 ) ) )
return - V_60 ;
V_352 = ( T_2 ) ( ( ( 0x40 | V_348 ) << 12 ) | ( V_349 << 8 ) | V_350 ) ;
V_353 = ( T_2 ) ( ( ( 0x40 | V_7 -> V_203 ) << 12 ) |
( V_7 -> V_204 << 8 ) | 0x28 ) ;
if ( ( V_352 < V_354 ) ||
( V_352 > V_353 ) )
return - V_48 ;
if ( V_351 ) {
F_17 ( ( T_2 ) * V_174 , V_7 -> V_19 + V_352 ) ;
F_17 ( ( * V_174 >> 32 ) , V_7 -> V_19 + V_352 + 4 ) ;
} else {
* V_174 = F_16 ( V_7 -> V_19 + V_352 + 4 ) ;
* V_174 <<= 32 ;
* V_174 = F_16 ( V_7 -> V_19 + V_352 ) ;
}
return 0 ;
}
int F_178 ( T_1 V_1 , T_3 V_348 , T_3 V_349 , T_3 V_350 ,
T_4 * V_174 , bool V_351 )
{
struct V_6 * V_7 = V_111 [ V_1 ] ;
if ( ! V_202 || V_7 == NULL )
return - V_60 ;
return F_91 ( V_7 , V_348 , V_349 , V_350 ,
V_174 , V_351 ) ;
}
