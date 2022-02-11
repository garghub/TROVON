static inline int F_1 ( unsigned int type )
{
switch ( type ) {
case V_1 :
return V_2 ;
default:
return type ;
}
}
static inline unsigned int F_2 ( unsigned int type )
{
switch ( type ) {
case V_2 :
return V_1 ;
default:
return type ;
}
}
static bool F_3 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( V_5 [ V_3 ] . V_6 )
return true ;
}
return false ;
}
static const char * F_4 ( enum V_7 V_8 )
{
int V_9 , V_10 = F_5 ( V_11 ) ;
const char * V_12 = L_1 ;
for ( V_9 = 0 ; V_9 < V_10 ; ++ V_9 ) {
if ( V_11 [ V_9 ] . V_8 == V_8 ) {
V_12 = V_11 [ V_9 ] . V_12 ;
break;
}
}
return V_12 ;
}
static int F_6 ( struct V_13 * V_14 ,
T_1 V_15 , const char * V_16 ,
enum V_7 V_8 ,
bool V_17 )
{
struct V_18 * V_19 = & V_14 -> V_19 ;
int type = F_1 ( V_19 -> type ) ;
const char * V_20 ;
if ( V_19 -> V_15 & V_15 )
return 0 ;
if ( V_5 [ type ] . V_6 ) {
if ( V_17 )
return 0 ;
V_20 = F_7 ( V_14 ) ;
F_8 ( L_2
L_3 ,
V_20 , V_16 , F_4 ( V_8 ) ) ;
return - 1 ;
}
V_5 [ type ] . V_21 &= ~ V_8 ;
V_20 = F_7 ( V_14 ) ;
F_9 ( L_2
L_4 ,
V_20 , V_16 , F_4 ( V_8 ) ) ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 ,
T_1 V_15 , const char * V_16 ,
enum V_7 V_8 )
{
return F_6 ( V_14 , V_15 , V_16 , V_8 ,
false ) ;
}
static int F_11 ( struct V_13 * V_14 ,
struct V_22 * V_23 )
{
struct V_18 * V_19 = & V_14 -> V_19 ;
bool V_17 ;
if ( F_12 ( & V_23 -> V_24 , V_25 ) )
return 0 ;
V_17 = F_12 ( & V_23 -> V_24 ,
V_26 ) ;
if ( F_13 ( V_27 ) &&
! F_14 ( V_23 , L_5 ) )
return - V_28 ;
if ( F_13 ( V_29 ) ) {
if ( F_10 ( V_14 , V_30 , L_6 ,
V_31 ) )
return - V_28 ;
}
if ( F_13 ( V_32 ) &&
F_6 ( V_14 , V_33 , L_7 ,
V_34 , V_17 ) )
return - V_28 ;
if ( F_13 ( V_35 ) &&
F_10 ( V_14 , V_36 , L_8 ,
V_37 ) )
return - V_28 ;
if ( F_13 ( V_38 ) &&
F_10 ( V_14 , V_39 , L_9 ,
V_40 ) )
return - V_28 ;
if ( F_13 ( V_41 ) && ! F_13 ( V_29 ) && ! F_13 ( V_32 ) ) {
F_8 ( L_10
L_11
L_12 ) ;
return - V_28 ;
}
if ( F_13 ( V_42 ) && ! F_13 ( V_41 ) ) {
F_8 ( L_13
L_14 ) ;
return - V_28 ;
}
if ( F_13 ( V_43 ) && ! F_13 ( V_29 ) && ! F_13 ( V_32 ) &&
! F_13 ( V_44 ) && ! F_13 ( V_45 ) && ! F_13 ( V_46 ) ) {
F_8 ( L_15
L_16 ) ;
return - V_28 ;
}
if ( F_13 ( V_47 ) && ! F_13 ( V_29 ) ) {
F_8 ( L_17
L_18 ) ;
return - V_28 ;
}
if ( F_13 ( V_48 ) &&
! ( F_15 ( V_23 -> V_49 ) &
V_50 ) ) {
F_8 ( L_19
L_20 ) ;
return - V_28 ;
}
if ( ( F_13 ( V_51 ) || F_13 ( V_52 ) ) &&
F_10 ( V_14 , V_53 , L_21 ,
V_54 | V_55 ) )
return - V_28 ;
if ( F_13 ( TIME ) &&
F_10 ( V_14 , V_56 , L_22 ,
V_57 ) )
return - V_28 ;
if ( F_13 ( V_58 ) &&
F_6 ( V_14 , V_59 , L_23 ,
V_60 , V_17 ) )
return - V_28 ;
if ( F_13 ( V_61 ) &&
F_10 ( V_14 , V_62 , L_24 ,
V_63 ) )
return - V_28 ;
if ( F_13 ( V_64 ) &&
F_10 ( V_14 , V_65 , L_25 ,
V_66 ) )
return - V_28 ;
return 0 ;
}
static void F_16 ( struct V_18 * V_19 )
{
unsigned int type = F_1 ( V_19 -> type ) ;
V_5 [ type ] . V_67 = 0 ;
if ( F_13 ( V_29 ) )
V_5 [ type ] . V_67 |= V_68 ;
if ( F_13 ( V_41 ) )
V_5 [ type ] . V_67 |= V_69 ;
if ( F_13 ( V_43 ) )
V_5 [ type ] . V_67 |= V_70 ;
if ( F_13 ( V_42 ) )
V_5 [ type ] . V_67 |= V_71 ;
if ( F_13 ( V_47 ) )
V_5 [ type ] . V_67 |= V_72 ;
}
static int F_17 ( struct V_22 * V_23 )
{
unsigned int V_3 ;
struct V_13 * V_14 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
V_14 = F_18 ( V_23 , F_2 ( V_3 ) ) ;
if ( ! V_14 && V_5 [ V_3 ] . V_6 && ! V_5 [ V_3 ] . V_73 &&
V_3 != V_2 ) {
F_8 ( L_26
L_27 ,
F_19 ( V_3 ) ) ;
return - 1 ;
}
if ( V_14 && V_5 [ V_3 ] . V_21 &&
F_11 ( V_14 , V_23 ) )
return - 1 ;
if ( V_14 == NULL )
continue;
F_16 ( & V_14 -> V_19 ) ;
}
if ( ! V_74 ) {
bool V_75 = false ;
bool V_76 = false ;
F_20 (session->evlist, evsel) {
V_76 = true ;
if ( V_14 -> V_19 . V_15 & V_77 ) {
V_75 = true ;
break;
}
}
if ( V_76 && ! V_75 )
V_78 . V_75 = false ;
}
if ( V_78 . V_75 &&
! V_5 [ V_79 ] . V_6 ) {
struct V_18 * V_19 ;
V_3 = V_79 ;
F_20 (session->evlist, evsel) {
if ( V_14 -> V_19 . type != V_3 )
continue;
V_19 = & V_14 -> V_19 ;
if ( V_19 -> V_15 & V_77 ) {
V_5 [ V_3 ] . V_21 |= V_31 ;
V_5 [ V_3 ] . V_21 |= V_80 ;
V_5 [ V_3 ] . V_21 |= V_81 ;
F_16 ( V_19 ) ;
goto V_82;
}
}
}
V_82:
return 0 ;
}
static void F_21 ( struct V_83 * V_84 ,
struct V_18 * V_19 )
{
struct V_85 * V_86 = & V_84 -> V_87 ;
T_2 V_88 = V_19 -> V_89 ;
unsigned V_9 = 0 , V_90 ;
if ( ! V_86 )
return;
F_22 (r, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_1 V_91 = V_86 -> V_86 [ V_9 ++ ] ;
printf ( L_28 V_92 L_29 , F_23 ( V_90 ) , V_91 ) ;
}
}
static void F_24 ( struct V_83 * V_84 ,
struct V_93 * V_93 ,
struct V_13 * V_14 )
{
struct V_18 * V_19 = & V_14 -> V_19 ;
unsigned long V_94 ;
unsigned long long V_95 ;
if ( F_13 ( V_96 ) ) {
if ( V_97 )
printf ( L_30 , F_25 ( V_93 ) ) ;
else if ( F_13 ( V_29 ) && V_78 . V_75 )
printf ( L_31 , F_25 ( V_93 ) ) ;
else
printf ( L_32 , F_25 ( V_93 ) ) ;
}
if ( F_13 ( V_51 ) && F_13 ( V_52 ) )
printf ( L_33 , V_84 -> V_98 , V_84 -> V_99 ) ;
else if ( F_13 ( V_51 ) )
printf ( L_34 , V_84 -> V_98 ) ;
else if ( F_13 ( V_52 ) )
printf ( L_34 , V_84 -> V_99 ) ;
if ( F_13 ( V_58 ) ) {
if ( V_97 )
printf ( L_35 , V_84 -> V_100 ) ;
else
printf ( L_36 , V_84 -> V_100 ) ;
}
if ( F_13 ( TIME ) ) {
V_95 = V_84 -> time ;
V_94 = V_95 / V_101 ;
V_95 -= V_94 * V_101 ;
if ( V_102 )
printf ( L_37 , V_94 , V_95 ) ;
else {
char V_103 [ 32 ] ;
F_26 ( V_84 -> time , V_103 , sizeof( V_103 ) ) ;
printf ( L_38 , V_103 ) ;
}
}
}
static inline char
F_27 ( struct V_104 * V_105 )
{
if ( ! ( V_105 -> V_106 . V_107 || V_105 -> V_106 . V_108 ) )
return '-' ;
return V_105 -> V_106 . V_108 ? 'P' : 'M' ;
}
static void F_28 ( struct V_83 * V_84 ,
struct V_93 * V_93 ,
struct V_18 * V_19 )
{
struct V_109 * V_105 = V_84 -> V_109 ;
struct V_110 V_111 , V_112 ;
T_1 V_9 , V_113 , V_114 ;
if ( ! ( V_105 && V_105 -> V_115 ) )
return;
for ( V_9 = 0 ; V_9 < V_105 -> V_115 ; V_9 ++ ) {
V_113 = V_105 -> V_116 [ V_9 ] . V_113 ;
V_114 = V_105 -> V_116 [ V_9 ] . V_114 ;
if ( F_13 ( V_43 ) ) {
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
F_29 ( V_93 , V_84 -> V_117 , V_118 , V_113 , & V_111 ) ;
F_29 ( V_93 , V_84 -> V_117 , V_118 , V_114 , & V_112 ) ;
}
printf ( L_39 V_92 , V_113 ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_40 ) ;
F_30 ( V_111 . V_119 , stdout ) ;
printf ( L_41 ) ;
}
printf ( L_42 V_92 , V_114 ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_40 ) ;
F_30 ( V_112 . V_119 , stdout ) ;
printf ( L_41 ) ;
}
printf ( L_43 ,
F_27 ( V_105 -> V_116 + V_9 ) ,
V_105 -> V_116 [ V_9 ] . V_106 . V_120 ? 'X' : '-' ,
V_105 -> V_116 [ V_9 ] . V_106 . abort ? 'A' : '-' ,
V_105 -> V_116 [ V_9 ] . V_106 . V_121 ) ;
}
}
static void F_31 ( struct V_83 * V_84 ,
struct V_93 * V_93 ,
struct V_18 * V_19 )
{
struct V_109 * V_105 = V_84 -> V_109 ;
struct V_110 V_111 , V_112 ;
T_1 V_9 , V_113 , V_114 ;
if ( ! ( V_105 && V_105 -> V_115 ) )
return;
for ( V_9 = 0 ; V_9 < V_105 -> V_115 ; V_9 ++ ) {
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
V_113 = V_105 -> V_116 [ V_9 ] . V_113 ;
V_114 = V_105 -> V_116 [ V_9 ] . V_114 ;
F_29 ( V_93 , V_84 -> V_117 , V_118 , V_113 , & V_111 ) ;
if ( V_111 . V_119 )
V_111 . V_122 = F_32 ( V_111 . V_119 , V_111 . V_123 ) ;
F_29 ( V_93 , V_84 -> V_117 , V_118 , V_114 , & V_112 ) ;
if ( V_112 . V_119 )
V_112 . V_122 = F_32 ( V_112 . V_119 , V_112 . V_123 ) ;
F_33 ( V_111 . V_122 , & V_111 , stdout ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_40 ) ;
F_30 ( V_111 . V_119 , stdout ) ;
printf ( L_41 ) ;
}
putchar ( '/' ) ;
F_33 ( V_112 . V_122 , & V_112 , stdout ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_40 ) ;
F_30 ( V_112 . V_119 , stdout ) ;
printf ( L_41 ) ;
}
printf ( L_43 ,
F_27 ( V_105 -> V_116 + V_9 ) ,
V_105 -> V_116 [ V_9 ] . V_106 . V_120 ? 'X' : '-' ,
V_105 -> V_116 [ V_9 ] . V_106 . abort ? 'A' : '-' ,
V_105 -> V_116 [ V_9 ] . V_106 . V_121 ) ;
}
}
static void F_34 ( struct V_83 * V_84 ,
struct V_93 * V_93 ,
struct V_18 * V_19 )
{
struct V_109 * V_105 = V_84 -> V_109 ;
struct V_110 V_111 , V_112 ;
T_1 V_9 , V_113 , V_114 ;
if ( ! ( V_105 && V_105 -> V_115 ) )
return;
for ( V_9 = 0 ; V_9 < V_105 -> V_115 ; V_9 ++ ) {
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
V_113 = V_105 -> V_116 [ V_9 ] . V_113 ;
V_114 = V_105 -> V_116 [ V_9 ] . V_114 ;
F_29 ( V_93 , V_84 -> V_117 , V_118 , V_113 , & V_111 ) ;
if ( V_111 . V_119 && ! V_111 . V_119 -> V_124 -> V_125 )
V_113 = F_35 ( V_111 . V_119 , V_113 ) ;
F_29 ( V_93 , V_84 -> V_117 , V_118 , V_114 , & V_112 ) ;
if ( V_112 . V_119 && ! V_112 . V_119 -> V_124 -> V_125 )
V_114 = F_35 ( V_112 . V_119 , V_114 ) ;
printf ( L_39 V_92 , V_113 ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_40 ) ;
F_30 ( V_111 . V_119 , stdout ) ;
printf ( L_41 ) ;
}
printf ( L_42 V_92 , V_114 ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_40 ) ;
F_30 ( V_112 . V_119 , stdout ) ;
printf ( L_41 ) ;
}
printf ( L_43 ,
F_27 ( V_105 -> V_116 + V_9 ) ,
V_105 -> V_116 [ V_9 ] . V_106 . V_120 ? 'X' : '-' ,
V_105 -> V_116 [ V_9 ] . V_106 . abort ? 'A' : '-' ,
V_105 -> V_116 [ V_9 ] . V_106 . V_121 ) ;
}
}
static int F_36 ( T_3 * V_126 , T_1 V_127 , T_1 V_128 ,
struct V_129 * V_129 , struct V_93 * V_93 ,
bool * V_130 , T_3 * V_117 , bool V_131 )
{
long V_132 , V_133 ;
struct V_110 V_134 ;
bool V_135 ;
if ( ! V_127 || ! V_128 )
return 0 ;
V_135 = F_37 ( V_129 , V_127 ) ;
if ( V_135 )
* V_117 = V_136 ;
else
* V_117 = V_137 ;
if ( V_135 != F_37 ( V_129 , V_128 ) ) {
printf ( L_44 V_92 L_45 V_92 L_46 ,
V_127 , V_128 ) ;
return - V_138 ;
}
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
if ( V_128 - V_127 > V_139 - V_140 ) {
if ( V_131 )
printf ( L_47 V_92 L_45 V_92 L_48 , V_127 , V_128 ) ;
else
printf ( L_44 V_92 L_45 V_92 L_49 V_141 L_50 , V_127 , V_128 , V_128 - V_127 ) ;
return 0 ;
}
F_29 ( V_93 , * V_117 , V_118 , V_127 , & V_134 ) ;
if ( ! V_134 . V_119 || ! V_134 . V_119 -> V_124 ) {
printf ( L_51 V_92 L_45 V_92 L_52 , V_127 , V_128 ) ;
return 0 ;
}
if ( V_134 . V_119 -> V_124 -> V_142 . V_143 == V_144 ) {
printf ( L_51 V_92 L_45 V_92 L_52 , V_127 , V_128 ) ;
return 0 ;
}
F_38 ( V_134 . V_119 ) ;
V_132 = V_134 . V_119 -> V_145 ( V_134 . V_119 , V_127 ) ;
V_133 = F_39 ( V_134 . V_119 -> V_124 , V_129 , V_132 , ( T_3 * ) V_126 ,
V_128 - V_127 + V_140 ) ;
* V_130 = V_134 . V_119 -> V_124 -> V_146 ;
if ( V_133 <= 0 )
printf ( L_53 V_92 L_45 V_92 L_52 ,
V_127 , V_128 ) ;
return V_133 ;
}
static void F_40 ( T_2 V_147 , struct V_104 * V_148 ,
struct V_149 * V_150 , T_3 * V_151 , int V_133 ,
int V_152 )
{
printf ( L_54 V_92 L_55 ,
V_147 ,
F_41 ( V_150 , V_147 , V_151 , V_133 , NULL ) ,
V_148 -> V_106 . V_108 ? L_56 : L_1 ,
V_148 -> V_106 . V_107 ? L_57 : L_1 ,
V_148 -> V_106 . V_120 ? L_58 : L_1 ,
V_148 -> V_106 . abort ? L_59 : L_1 ) ;
if ( V_148 -> V_106 . V_121 ) {
printf ( L_60 , V_148 -> V_106 . V_121 ) ;
if ( V_152 )
printf ( L_61 , ( float ) V_152 / V_148 -> V_106 . V_121 ) ;
}
putchar ( '\n' ) ;
}
static void F_42 ( struct V_93 * V_93 , T_3 V_117 , int V_100 ,
T_2 V_123 , struct V_153 * * V_154 ,
struct V_18 * V_19 )
{
struct V_110 V_134 ;
int V_155 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
F_29 ( V_93 , V_117 , V_118 , V_123 , & V_134 ) ;
if ( ! V_134 . V_119 )
F_29 ( V_93 , V_117 , V_156 ,
V_123 , & V_134 ) ;
if ( ( * V_154 ) && V_134 . V_123 >= ( * V_154 ) -> V_127 && V_134 . V_123 < ( * V_154 ) -> V_128 )
return;
V_134 . V_100 = V_100 ;
V_134 . V_122 = NULL ;
if ( V_134 . V_119 )
V_134 . V_122 = F_32 ( V_134 . V_119 , V_134 . V_123 ) ;
if ( ! V_134 . V_122 )
return;
if ( V_134 . V_123 < V_134 . V_122 -> V_128 )
V_155 = V_134 . V_123 - V_134 . V_122 -> V_127 ;
else
V_155 = V_134 . V_123 - V_134 . V_119 -> V_127 - V_134 . V_122 -> V_127 ;
printf ( L_62 , V_134 . V_122 -> V_157 ) ;
if ( V_155 )
printf ( L_63 , V_155 ) ;
putchar ( ':' ) ;
if ( F_13 ( V_47 ) )
F_43 ( V_134 . V_119 , V_134 . V_123 , L_64 , stdout ) ;
putchar ( '\n' ) ;
* V_154 = V_134 . V_122 ;
}
static void F_44 ( struct V_83 * V_84 ,
struct V_93 * V_93 ,
struct V_18 * V_19 ,
struct V_129 * V_129 )
{
struct V_109 * V_105 = V_84 -> V_109 ;
T_1 V_127 , V_128 ;
int V_9 , V_152 , V_133 , V_115 , V_158 ;
struct V_149 V_150 ;
T_3 V_126 [ V_139 ] ;
unsigned V_155 ;
struct V_153 * V_154 = NULL ;
if ( ! ( V_105 && V_105 -> V_115 ) )
return;
V_115 = V_105 -> V_115 ;
if ( V_159 && V_115 > V_159 + 1 )
V_115 = V_159 + 1 ;
V_150 . V_93 = V_93 ;
V_150 . V_100 = V_84 -> V_100 ;
putchar ( '\n' ) ;
V_133 = F_36 ( V_126 , V_105 -> V_116 [ V_115 - 1 ] . V_113 ,
V_105 -> V_116 [ V_115 - 1 ] . V_113 ,
V_129 , V_93 , & V_150 . V_130 , & V_150 . V_117 , false ) ;
if ( V_133 > 0 ) {
F_42 ( V_93 , V_150 . V_117 , V_150 . V_100 ,
V_105 -> V_116 [ V_115 - 1 ] . V_113 , & V_154 , V_19 ) ;
F_40 ( V_105 -> V_116 [ V_115 - 1 ] . V_113 , & V_105 -> V_116 [ V_115 - 1 ] ,
& V_150 , V_126 , V_133 , 0 ) ;
}
for ( V_9 = V_115 - 2 ; V_9 >= 0 ; V_9 -- ) {
if ( V_105 -> V_116 [ V_9 ] . V_113 || V_105 -> V_116 [ V_9 ] . V_114 )
F_9 ( L_65 V_92 L_45 V_92 L_52 , V_9 ,
V_105 -> V_116 [ V_9 ] . V_113 ,
V_105 -> V_116 [ V_9 ] . V_114 ) ;
V_127 = V_105 -> V_116 [ V_9 + 1 ] . V_114 ;
V_128 = V_105 -> V_116 [ V_9 ] . V_113 ;
V_133 = F_36 ( V_126 , V_127 , V_128 , V_129 , V_93 , & V_150 . V_130 , & V_150 . V_117 , false ) ;
if ( V_133 == - V_138 && V_9 > 0 ) {
V_128 = V_105 -> V_116 [ -- V_9 ] . V_113 ;
F_9 ( L_66 V_92 L_45 V_92 L_52 , V_127 , V_128 ) ;
V_133 = F_36 ( V_126 , V_127 , V_128 , V_129 , V_93 , & V_150 . V_130 , & V_150 . V_117 , false ) ;
}
if ( V_133 <= 0 )
continue;
V_152 = 0 ;
for ( V_155 = 0 ; ; V_155 += V_158 ) {
T_2 V_147 = V_127 + V_155 ;
F_42 ( V_93 , V_150 . V_117 , V_150 . V_100 , V_147 , & V_154 , V_19 ) ;
if ( V_147 == V_128 ) {
F_40 ( V_147 , & V_105 -> V_116 [ V_9 ] , & V_150 , V_126 + V_155 , V_133 - V_155 , V_152 ) ;
break;
} else {
printf ( L_54 V_92 L_67 , V_147 ,
F_41 ( & V_150 , V_147 , V_126 + V_155 , V_133 - V_155 , & V_158 ) ) ;
if ( V_158 == 0 )
break;
V_152 ++ ;
}
}
}
if ( V_105 -> V_116 [ 0 ] . V_113 == V_84 -> V_147 )
return;
if ( V_105 -> V_116 [ 0 ] . V_106 . abort )
return;
V_127 = V_105 -> V_116 [ 0 ] . V_114 ;
V_128 = V_84 -> V_147 ;
V_133 = F_36 ( V_126 , V_127 , V_128 , V_129 , V_93 , & V_150 . V_130 , & V_150 . V_117 , true ) ;
F_42 ( V_93 , V_150 . V_117 , V_150 . V_100 , V_127 , & V_154 , V_19 ) ;
if ( V_133 <= 0 ) {
V_133 = F_36 ( V_126 , V_84 -> V_147 , V_84 -> V_147 ,
V_129 , V_93 , & V_150 . V_130 , & V_150 . V_117 , false ) ;
if ( V_133 <= 0 )
return;
printf ( L_54 V_92 L_67 , V_84 -> V_147 ,
F_41 ( & V_150 , V_84 -> V_147 , V_126 , V_133 , NULL ) ) ;
return;
}
for ( V_155 = 0 ; V_155 <= V_128 - V_127 ; V_155 += V_158 ) {
printf ( L_54 V_92 L_67 , V_127 + V_155 ,
F_41 ( & V_150 , V_127 + V_155 , V_126 + V_155 , V_133 - V_155 , & V_158 ) ) ;
if ( V_158 == 0 )
break;
}
}
static void F_45 ( struct V_83 * V_84 ,
struct V_93 * V_93 ,
struct V_18 * V_19 )
{
struct V_110 V_134 ;
printf ( L_68 V_92 , V_84 -> V_123 ) ;
if ( ! F_46 ( V_19 ) )
return;
F_47 ( V_93 , & V_134 , V_84 ) ;
if ( F_13 ( V_41 ) ) {
printf ( L_29 ) ;
if ( F_13 ( V_42 ) )
F_33 ( V_134 . V_122 , & V_134 , stdout ) ;
else
F_48 ( V_134 . V_122 , stdout ) ;
}
if ( F_13 ( V_43 ) ) {
printf ( L_69 ) ;
F_30 ( V_134 . V_119 , stdout ) ;
printf ( L_41 ) ;
}
}
static void F_49 ( struct V_83 * V_84 ,
struct V_13 * V_14 ,
struct V_93 * V_93 ,
struct V_110 * V_134 )
{
struct V_18 * V_19 = & V_14 -> V_19 ;
T_4 V_160 = F_50 ( V_93 ) ;
struct V_110 V_161 ;
const char * V_157 = NULL ;
static int V_162 ;
int V_133 = 0 ;
T_1 V_147 = 0 ;
if ( V_93 -> V_163 && V_84 -> V_106 & V_164 )
V_160 += 1 ;
if ( V_84 -> V_106 & ( V_165 | V_166 ) ) {
if ( F_46 ( V_19 ) ) {
F_47 ( V_93 , & V_161 , V_84 ) ;
if ( V_161 . V_122 )
V_157 = V_161 . V_122 -> V_157 ;
else
V_147 = V_84 -> V_123 ;
} else {
V_147 = V_84 -> V_123 ;
}
} else if ( V_84 -> V_106 & ( V_164 | V_167 ) ) {
if ( V_134 -> V_122 )
V_157 = V_134 -> V_122 -> V_157 ;
else
V_147 = V_84 -> V_147 ;
}
if ( V_157 )
V_133 = printf ( L_70 , ( int ) V_160 * 4 , L_1 , V_157 ) ;
else if ( V_147 )
V_133 = printf ( L_71 V_92 , ( int ) V_160 * 4 , L_1 , V_147 ) ;
if ( V_133 < 0 )
return;
if ( V_133 > V_162 || ( V_133 && V_133 < V_162 - 52 ) )
V_162 = F_51 ( V_133 + 4 , 32 ) ;
if ( V_133 < V_162 )
printf ( L_72 , V_162 - V_133 , L_1 ) ;
}
static void F_52 ( struct V_83 * V_84 ,
struct V_18 * V_19 ,
struct V_93 * V_93 ,
struct V_129 * V_129 )
{
if ( F_13 ( V_168 ) )
printf ( L_73 , V_84 -> V_169 ) ;
if ( F_13 ( V_170 ) ) {
int V_9 ;
printf ( L_74 ) ;
for ( V_9 = 0 ; V_9 < V_84 -> V_169 ; V_9 ++ )
printf ( L_75 , ( unsigned char ) V_84 -> V_152 [ V_9 ] ) ;
}
if ( F_13 ( V_48 ) )
F_44 ( V_84 , V_93 , V_19 , V_129 ) ;
}
static void F_53 ( struct V_83 * V_84 ,
struct V_13 * V_14 ,
struct V_93 * V_93 ,
struct V_110 * V_134 ,
struct V_129 * V_129 )
{
struct V_18 * V_19 = & V_14 -> V_19 ;
unsigned int type = F_1 ( V_19 -> type ) ;
bool V_171 = false ;
if ( F_13 ( V_172 ) )
F_49 ( V_84 , V_14 , V_93 , V_134 ) ;
if ( F_13 ( V_29 ) ) {
unsigned int V_173 = V_5 [ type ] . V_67 ;
struct V_174 * V_175 = NULL ;
if ( V_78 . V_75 && V_84 -> V_176 &&
F_54 ( V_134 -> V_93 , & V_174 , V_14 ,
V_84 , NULL , NULL , V_177 ) == 0 )
V_175 = & V_174 ;
if ( V_175 == NULL ) {
putchar ( ' ' ) ;
if ( V_173 & V_72 ) {
V_171 = true ;
V_173 &= ~ V_72 ;
}
} else
putchar ( '\n' ) ;
F_55 ( V_84 , V_134 , 0 , V_173 , V_175 , stdout ) ;
}
if ( F_13 ( V_32 ) ||
( ( V_14 -> V_19 . V_15 & V_33 ) &&
! V_5 [ type ] . V_6 ) ) {
printf ( L_76 ) ;
F_45 ( V_84 , V_93 , V_19 ) ;
}
if ( V_171 )
F_43 ( V_134 -> V_119 , V_134 -> V_123 , L_77 , stdout ) ;
F_52 ( V_84 , V_19 , V_93 , V_129 ) ;
printf ( L_52 ) ;
}
static void F_56 ( T_5 V_106 )
{
const char * V_178 = V_179 ;
const int V_180 = strlen ( V_179 ) ;
bool V_120 = V_106 & V_181 ;
const char * V_157 = NULL ;
char V_12 [ 33 ] ;
int V_9 , V_182 = 0 ;
for ( V_9 = 0 ; V_183 [ V_9 ] . V_157 ; V_9 ++ ) {
if ( V_183 [ V_9 ] . V_106 == ( V_106 & ~ V_181 ) ) {
V_157 = V_183 [ V_9 ] . V_157 ;
break;
}
}
for ( V_9 = 0 ; V_9 < V_180 ; V_9 ++ , V_106 >>= 1 ) {
if ( V_106 & 1 )
V_12 [ V_182 ++ ] = V_178 [ V_9 ] ;
}
for (; V_9 < 32 ; V_9 ++ , V_106 >>= 1 ) {
if ( V_106 & 1 )
V_12 [ V_182 ++ ] = '?' ;
}
V_12 [ V_182 ] = 0 ;
if ( V_157 )
printf ( L_78 , V_157 , V_120 ? L_79 : L_1 ) ;
else
printf ( L_80 , V_12 ) ;
}
static void
F_57 ( enum V_184 V_185 ,
unsigned int V_91 ,
void * V_186 )
{
unsigned char V_187 = ( unsigned char ) V_91 ;
struct V_188 * V_188 = V_186 ;
switch ( V_185 ) {
case V_189 :
printf ( L_52 ) ;
break;
case V_190 :
printf ( L_81 , ! V_188 -> V_191 ? L_82 :
L_83 ) ;
break;
case V_192 :
printf ( L_84 , V_91 ) ;
break;
case V_193 :
printf ( L_75 , V_91 ) ;
break;
case V_194 :
printf ( L_85 ) ;
break;
case V_195 :
printf ( L_86 ) ;
break;
case V_196 :
if ( V_188 -> V_197 && V_187 )
V_188 -> V_198 = false ;
if ( ! isprint ( V_187 ) ) {
printf ( L_87 , '.' ) ;
if ( ! V_188 -> V_198 )
break;
if ( V_187 == '\0' )
V_188 -> V_197 = true ;
else
V_188 -> V_198 = false ;
} else {
printf ( L_87 , V_187 ) ;
}
break;
case V_199 :
printf ( L_29 ) ;
break;
case V_200 :
printf ( L_52 ) ;
V_188 -> V_191 ++ ;
break;
case V_201 :
default:
break;
}
}
static void F_58 ( struct V_83 * V_84 )
{
unsigned int V_202 = V_84 -> V_203 ;
struct V_188 V_188 = { 0 , false , true } ;
F_59 ( V_84 -> V_204 , V_202 , 8 ,
F_57 , & V_188 ) ;
if ( V_188 . V_198 && V_188 . V_197 )
printf ( L_88 , L_89 ,
( char * ) ( V_84 -> V_204 ) ) ;
}
static void F_60 ( int V_133 , int V_162 )
{
if ( V_133 > 0 && V_133 < V_162 )
printf ( L_72 , V_162 - V_133 , L_1 ) ;
}
static void F_61 ( int V_133 )
{
F_60 ( V_133 , 34 ) ;
}
static void F_62 ( struct V_83 * V_84 )
{
struct V_205 * V_142 = F_63 ( V_84 ) ;
int V_133 ;
if ( F_64 ( V_84 , * V_142 ) )
return;
V_133 = printf ( L_90 V_92 L_29 ,
V_142 -> V_147 , F_65 ( V_142 -> V_206 ) ) ;
F_61 ( V_133 ) ;
}
static void F_66 ( struct V_83 * V_84 )
{
struct V_207 * V_142 = F_63 ( V_84 ) ;
int V_133 ;
if ( F_64 ( V_84 , * V_142 ) )
return;
V_133 = printf ( L_91 ,
V_142 -> V_208 , V_142 -> V_209 ) ;
F_61 ( V_133 ) ;
}
static void F_67 ( struct V_83 * V_84 )
{
struct V_210 * V_142 = F_63 ( V_84 ) ;
int V_133 ;
if ( F_64 ( V_84 , * V_142 ) )
return;
V_133 = printf ( L_92 ,
V_142 -> V_211 , V_142 -> V_212 , V_142 -> V_213 ) ;
F_61 ( V_133 ) ;
}
static void F_68 ( struct V_83 * V_84 )
{
struct V_214 * V_142 = F_63 ( V_84 ) ;
int V_133 ;
if ( F_64 ( V_84 , * V_142 ) )
return;
V_133 = printf ( L_93 , V_142 -> V_147 ) ;
F_61 ( V_133 ) ;
}
static void F_69 ( struct V_83 * V_84 )
{
struct V_215 * V_142 = F_63 ( V_84 ) ;
int V_133 ;
if ( F_64 ( V_84 , * V_142 ) )
return;
V_133 = printf ( L_94 ,
V_142 -> V_216 , V_142 -> V_217 ,
V_142 -> V_218 ) ;
F_61 ( V_133 ) ;
}
static void F_70 ( struct V_83 * V_84 )
{
struct V_219 * V_142 = F_63 ( V_84 ) ;
unsigned int V_220 , V_221 ;
int V_133 ;
if ( F_64 ( V_84 , * V_142 ) )
return;
V_221 = ( F_71 ( V_142 -> V_221 ) + 500 ) / 1000 ;
V_133 = printf ( L_95 , V_142 -> V_222 , V_221 ) ;
if ( V_142 -> V_223 ) {
V_220 = ( 5 + ( 1000 * V_142 -> V_222 ) / V_142 -> V_223 ) / 10 ;
V_133 += printf ( L_96 , V_220 ) ;
}
F_61 ( V_133 ) ;
}
static void F_72 ( struct V_83 * V_84 ,
struct V_13 * V_14 )
{
switch ( V_14 -> V_19 . V_224 ) {
case V_225 :
F_62 ( V_84 ) ;
break;
case V_226 :
F_66 ( V_84 ) ;
break;
case V_227 :
F_67 ( V_84 ) ;
break;
case V_228 :
F_68 ( V_84 ) ;
break;
case V_229 :
F_69 ( V_84 ) ;
break;
case V_230 :
F_70 ( V_84 ) ;
break;
default:
break;
}
}
static int F_73 ( struct V_231 * V_49 )
{
struct V_13 * V_14 ;
int V_232 = 0 ;
F_20 (evlist, evsel) {
int V_133 = strlen ( F_7 ( V_14 ) ) ;
V_232 = F_74 ( V_133 , V_232 ) ;
}
return V_232 ;
}
static T_4 F_75 ( T_1 V_233 )
{
struct V_234 V_235 = { . V_233 . V_91 = V_233 } ;
char V_236 [ 100 ] ;
char V_82 [ 100 ] ;
static int V_237 ;
int V_133 ;
F_76 ( V_236 , 100 , & V_235 ) ;
V_133 = F_77 ( V_82 , 100 , L_68 V_92 L_97 , V_233 , V_236 ) ;
if ( V_237 < V_133 )
V_237 = V_133 ;
return printf ( L_98 , V_237 , V_82 ) ;
}
static void F_78 ( struct V_238 * V_239 ,
struct V_83 * V_84 , struct V_13 * V_14 ,
struct V_110 * V_134 ,
struct V_129 * V_129 )
{
struct V_93 * V_93 = V_134 -> V_93 ;
struct V_18 * V_19 = & V_14 -> V_19 ;
unsigned int type = F_1 ( V_19 -> type ) ;
if ( V_5 [ type ] . V_21 == 0 )
return;
F_24 ( V_84 , V_93 , V_14 ) ;
if ( F_13 ( V_61 ) )
printf ( L_99 V_141 L_29 , V_84 -> V_240 ) ;
if ( F_13 ( V_241 ) ) {
const char * V_20 = F_7 ( V_14 ) ;
if ( ! V_239 -> V_242 )
V_239 -> V_242 = F_73 ( V_239 -> V_23 -> V_49 ) ;
printf ( L_100 , V_239 -> V_242 ,
V_20 ? V_20 : L_101 ) ;
}
if ( V_243 )
F_56 ( V_84 -> V_106 ) ;
if ( F_79 ( V_19 ) ) {
F_53 ( V_84 , V_14 , V_93 , V_134 , V_129 ) ;
return;
}
if ( F_13 ( V_27 ) )
F_80 ( V_14 -> V_244 , V_84 -> V_100 ,
V_84 -> V_204 , V_84 -> V_203 ) ;
if ( V_19 -> type == V_1 && F_13 ( V_245 ) )
F_72 ( V_84 , V_14 ) ;
if ( F_13 ( V_32 ) )
F_45 ( V_84 , V_93 , V_19 ) ;
if ( F_13 ( V_35 ) )
F_75 ( V_84 -> V_233 ) ;
if ( F_13 ( V_38 ) )
printf ( L_68 V_141 , V_84 -> V_246 ) ;
if ( F_13 ( V_29 ) ) {
struct V_174 * V_175 = NULL ;
if ( V_78 . V_75 && V_84 -> V_176 &&
F_54 ( V_134 -> V_93 , & V_174 , V_14 ,
V_84 , NULL , NULL , V_177 ) == 0 )
V_175 = & V_174 ;
putchar ( V_175 ? '\n' : ' ' ) ;
F_55 ( V_84 , V_134 , 0 , V_5 [ type ] . V_67 , V_175 , stdout ) ;
}
if ( F_13 ( V_64 ) )
F_21 ( V_84 , V_19 ) ;
if ( F_13 ( V_44 ) )
F_28 ( V_84 , V_93 , V_19 ) ;
else if ( F_13 ( V_45 ) )
F_31 ( V_84 , V_93 , V_19 ) ;
else if ( F_13 ( V_46 ) )
F_34 ( V_84 , V_93 , V_19 ) ;
if ( F_81 ( V_14 ) && F_13 ( V_247 ) )
F_58 ( V_84 ) ;
F_52 ( V_84 , V_19 , V_93 , V_129 ) ;
printf ( L_52 ) ;
}
static void F_82 ( struct V_13 * V_248 , T_1 V_249 )
{
int V_250 = F_83 ( V_248 -> V_251 ) ;
int V_252 = F_84 ( V_248 ) ;
int V_100 , V_93 ;
static int V_253 ;
if ( V_248 -> V_254 )
V_250 = 1 ;
if ( ! V_253 ) {
printf ( L_102 ,
L_23 , L_103 , L_104 , L_105 , L_106 , L_22 , L_107 ) ;
V_253 = 1 ;
}
for ( V_93 = 0 ; V_93 < V_250 ; V_93 ++ ) {
for ( V_100 = 0 ; V_100 < V_252 ; V_100 ++ ) {
struct V_255 * V_256 ;
V_256 = F_85 ( V_248 -> V_256 , V_100 , V_93 ) ;
printf ( L_108 V_141 L_109 V_141 L_109 V_141 L_109 V_141 L_110 ,
V_248 -> V_257 -> V_119 [ V_100 ] ,
F_86 ( V_248 -> V_251 , V_93 ) ,
V_256 -> V_91 ,
V_256 -> V_258 ,
V_256 -> V_259 ,
V_249 ,
F_7 ( V_248 ) ) ;
}
}
}
static void F_87 ( struct V_13 * V_248 , T_1 V_249 )
{
if ( V_260 && V_260 -> F_87 )
V_260 -> F_87 ( & V_261 , V_248 , V_249 ) ;
else
F_82 ( V_248 , V_249 ) ;
}
static void F_88 ( T_1 V_249 )
{
if ( V_260 && V_260 -> F_88 )
V_260 -> F_88 ( V_249 ) ;
}
static void F_89 ( void )
{
F_90 () ;
F_91 () ;
}
static int F_92 ( void )
{
return V_260 ? V_260 -> V_262 () : 0 ;
}
static int F_93 ( void )
{
F_9 ( L_111 ) ;
return V_260 ? V_260 -> V_263 () : 0 ;
}
static int F_94 ( struct V_264 * V_265 ,
union V_266 * V_267 ,
struct V_83 * V_84 ,
struct V_13 * V_14 ,
struct V_129 * V_129 )
{
struct V_238 * V_268 = F_95 ( V_265 , struct V_238 , V_265 ) ;
struct V_110 V_134 ;
if ( F_96 ( & V_268 -> V_269 , V_84 -> time ) )
return 0 ;
if ( V_270 ) {
if ( V_84 -> time < V_271 ) {
F_8 ( L_112 V_141
L_113 V_141 L_52 , V_271 ,
V_84 -> time ) ;
V_272 ++ ;
}
V_271 = V_84 -> time ;
return 0 ;
}
if ( F_97 ( V_129 , & V_134 , V_84 ) < 0 ) {
F_8 ( L_114 ,
V_267 -> V_24 . type ) ;
return - 1 ;
}
if ( V_134 . V_273 )
goto V_274;
if ( V_275 && ! F_98 ( V_84 -> V_100 , V_276 ) )
goto V_274;
if ( V_260 )
V_260 -> F_78 ( V_267 , V_84 , V_14 , & V_134 ) ;
else
F_78 ( V_268 , V_84 , V_14 , & V_134 , V_129 ) ;
V_274:
F_99 ( & V_134 ) ;
return 0 ;
}
static int F_100 ( struct V_264 * V_265 , union V_266 * V_267 ,
struct V_231 * * V_277 )
{
struct V_238 * V_268 = F_95 ( V_265 , struct V_238 , V_265 ) ;
struct V_231 * V_49 ;
struct V_13 * V_14 , * V_182 ;
int V_278 ;
V_278 = F_101 ( V_265 , V_267 , V_277 ) ;
if ( V_278 )
return V_278 ;
V_49 = * V_277 ;
V_14 = F_102 ( * V_277 ) ;
if ( V_14 -> V_19 . type >= V_279 &&
V_14 -> V_19 . type != V_1 )
return 0 ;
F_20 (evlist, pos) {
if ( V_182 -> V_19 . type == V_14 -> V_19 . type && V_182 != V_14 )
return 0 ;
}
F_16 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_19 . V_15 )
V_278 = F_11 ( V_14 , V_268 -> V_23 ) ;
return V_278 ;
}
static int F_103 ( struct V_264 * V_265 ,
union V_266 * V_267 ,
struct V_83 * V_84 ,
struct V_129 * V_129 )
{
struct V_93 * V_93 ;
struct V_238 * V_239 = F_95 ( V_265 , struct V_238 , V_265 ) ;
struct V_22 * V_23 = V_239 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_84 -> V_280 ) ;
int V_281 = - 1 ;
V_93 = F_105 ( V_129 , V_267 -> V_282 . V_98 , V_267 -> V_282 . V_99 ) ;
if ( V_93 == NULL ) {
F_9 ( L_115 ) ;
return - 1 ;
}
if ( F_106 ( V_265 , V_267 , V_84 , V_129 ) < 0 )
goto V_82;
if ( ! V_14 -> V_19 . V_283 ) {
V_84 -> V_100 = 0 ;
V_84 -> time = 0 ;
V_84 -> V_99 = V_267 -> V_282 . V_99 ;
V_84 -> V_98 = V_267 -> V_282 . V_98 ;
}
F_24 ( V_84 , V_93 , V_14 ) ;
F_107 ( V_267 , stdout ) ;
V_281 = 0 ;
V_82:
F_108 ( V_93 ) ;
return V_281 ;
}
static int F_109 ( struct V_264 * V_265 ,
union V_266 * V_267 ,
struct V_83 * V_84 ,
struct V_129 * V_129 )
{
struct V_93 * V_93 ;
struct V_238 * V_239 = F_95 ( V_265 , struct V_238 , V_265 ) ;
struct V_22 * V_23 = V_239 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_84 -> V_280 ) ;
int V_281 = - 1 ;
V_93 = F_105 ( V_129 , V_267 -> V_284 . V_98 ,
V_267 -> V_284 . V_99 ) ;
if ( V_93 == NULL ) {
F_9 ( L_116 ) ;
return - 1 ;
}
if ( F_110 ( V_265 , V_267 , V_84 , V_129 ) < 0 )
goto V_82;
if ( ! V_14 -> V_19 . V_283 ) {
V_84 -> V_100 = 0 ;
V_84 -> time = 0 ;
V_84 -> V_99 = V_267 -> V_284 . V_99 ;
V_84 -> V_98 = V_267 -> V_284 . V_98 ;
}
F_24 ( V_84 , V_93 , V_14 ) ;
F_107 ( V_267 , stdout ) ;
V_281 = 0 ;
V_82:
F_108 ( V_93 ) ;
return V_281 ;
}
static int F_111 ( struct V_264 * V_265 ,
union V_266 * V_267 ,
struct V_83 * V_84 ,
struct V_129 * V_129 )
{
struct V_93 * V_93 ;
struct V_238 * V_239 = F_95 ( V_265 , struct V_238 , V_265 ) ;
struct V_22 * V_23 = V_239 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_84 -> V_280 ) ;
if ( F_112 ( V_265 , V_267 , V_84 , V_129 ) < 0 )
return - 1 ;
V_93 = F_105 ( V_129 , V_267 -> V_285 . V_98 , V_267 -> V_285 . V_99 ) ;
if ( V_93 == NULL ) {
F_9 ( L_117 ) ;
return - 1 ;
}
if ( ! V_14 -> V_19 . V_283 ) {
V_84 -> V_100 = 0 ;
V_84 -> time = V_267 -> V_285 . time ;
V_84 -> V_99 = V_267 -> V_285 . V_99 ;
V_84 -> V_98 = V_267 -> V_285 . V_98 ;
}
F_24 ( V_84 , V_93 , V_14 ) ;
F_107 ( V_267 , stdout ) ;
F_108 ( V_93 ) ;
return 0 ;
}
static int F_113 ( struct V_264 * V_265 ,
union V_266 * V_267 ,
struct V_83 * V_84 ,
struct V_129 * V_129 )
{
int V_278 = 0 ;
struct V_93 * V_93 ;
struct V_238 * V_239 = F_95 ( V_265 , struct V_238 , V_265 ) ;
struct V_22 * V_23 = V_239 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_84 -> V_280 ) ;
V_93 = F_105 ( V_129 , V_267 -> V_285 . V_98 , V_267 -> V_285 . V_99 ) ;
if ( V_93 == NULL ) {
F_9 ( L_118 ) ;
return - 1 ;
}
if ( ! V_14 -> V_19 . V_283 ) {
V_84 -> V_100 = 0 ;
V_84 -> time = 0 ;
V_84 -> V_99 = V_267 -> V_285 . V_99 ;
V_84 -> V_98 = V_267 -> V_285 . V_98 ;
}
F_24 ( V_84 , V_93 , V_14 ) ;
F_107 ( V_267 , stdout ) ;
if ( F_114 ( V_265 , V_267 , V_84 , V_129 ) < 0 )
V_278 = - 1 ;
F_108 ( V_93 ) ;
return V_278 ;
}
static int F_115 ( struct V_264 * V_265 ,
union V_266 * V_267 ,
struct V_83 * V_84 ,
struct V_129 * V_129 )
{
struct V_93 * V_93 ;
struct V_238 * V_239 = F_95 ( V_265 , struct V_238 , V_265 ) ;
struct V_22 * V_23 = V_239 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_84 -> V_280 ) ;
if ( F_116 ( V_265 , V_267 , V_84 , V_129 ) < 0 )
return - 1 ;
V_93 = F_105 ( V_129 , V_267 -> V_286 . V_98 , V_267 -> V_286 . V_99 ) ;
if ( V_93 == NULL ) {
F_9 ( L_119 ) ;
return - 1 ;
}
if ( ! V_14 -> V_19 . V_283 ) {
V_84 -> V_100 = 0 ;
V_84 -> time = 0 ;
V_84 -> V_99 = V_267 -> V_286 . V_99 ;
V_84 -> V_98 = V_267 -> V_286 . V_98 ;
}
F_24 ( V_84 , V_93 , V_14 ) ;
F_107 ( V_267 , stdout ) ;
F_108 ( V_93 ) ;
return 0 ;
}
static int F_117 ( struct V_264 * V_265 ,
union V_266 * V_267 ,
struct V_83 * V_84 ,
struct V_129 * V_129 )
{
struct V_93 * V_93 ;
struct V_238 * V_239 = F_95 ( V_265 , struct V_238 , V_265 ) ;
struct V_22 * V_23 = V_239 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_84 -> V_280 ) ;
if ( F_118 ( V_265 , V_267 , V_84 , V_129 ) < 0 )
return - 1 ;
V_93 = F_105 ( V_129 , V_267 -> V_287 . V_98 , V_267 -> V_287 . V_99 ) ;
if ( V_93 == NULL ) {
F_9 ( L_120 ) ;
return - 1 ;
}
if ( ! V_14 -> V_19 . V_283 ) {
V_84 -> V_100 = 0 ;
V_84 -> time = 0 ;
V_84 -> V_99 = V_267 -> V_287 . V_99 ;
V_84 -> V_98 = V_267 -> V_287 . V_98 ;
}
F_24 ( V_84 , V_93 , V_14 ) ;
F_107 ( V_267 , stdout ) ;
F_108 ( V_93 ) ;
return 0 ;
}
static int F_119 ( struct V_264 * V_265 ,
union V_266 * V_267 ,
struct V_83 * V_84 ,
struct V_129 * V_129 )
{
struct V_93 * V_93 ;
struct V_238 * V_239 = F_95 ( V_265 , struct V_238 , V_265 ) ;
struct V_22 * V_23 = V_239 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_84 -> V_280 ) ;
if ( F_120 ( V_265 , V_267 , V_84 , V_129 ) < 0 )
return - 1 ;
V_93 = F_105 ( V_129 , V_84 -> V_98 ,
V_84 -> V_99 ) ;
if ( V_93 == NULL ) {
F_9 ( L_121 ) ;
return - 1 ;
}
F_24 ( V_84 , V_93 , V_14 ) ;
F_107 ( V_267 , stdout ) ;
F_108 ( V_93 ) ;
return 0 ;
}
static void F_121 ( int T_6 V_288 )
{
V_289 = 1 ;
}
static int F_122 ( struct V_238 * V_239 )
{
int V_281 ;
signal ( V_290 , F_121 ) ;
if ( V_239 -> V_291 ) {
V_239 -> V_265 . V_282 = F_103 ;
V_239 -> V_265 . V_285 = F_111 ;
V_239 -> V_265 . exit = F_113 ;
}
if ( V_239 -> V_292 ) {
V_239 -> V_265 . V_286 = F_115 ;
V_239 -> V_265 . V_287 = F_117 ;
}
if ( V_239 -> V_293 )
V_239 -> V_265 . V_294 = F_119 ;
if ( V_239 -> V_295 )
V_239 -> V_265 . V_284 = F_109 ;
V_281 = F_123 ( V_239 -> V_23 ) ;
if ( V_270 )
F_8 ( L_122 V_141 L_52 , V_272 ) ;
return V_281 ;
}
static struct V_296 * F_124 ( const char * V_297 ,
struct V_260 * V_298 )
{
struct V_296 * V_299 = malloc ( sizeof( * V_299 ) + strlen ( V_297 ) + 1 ) ;
if ( V_299 != NULL ) {
strcpy ( V_299 -> V_297 , V_297 ) ;
V_299 -> V_298 = V_298 ;
}
return V_299 ;
}
static void F_125 ( struct V_296 * V_299 )
{
F_126 ( & V_299 -> V_300 , & V_301 ) ;
}
static struct V_296 * F_127 ( const char * V_297 )
{
struct V_296 * V_299 ;
F_128 (s, &script_specs, node)
if ( strcasecmp ( V_299 -> V_297 , V_297 ) == 0 )
return V_299 ;
return NULL ;
}
int F_129 ( const char * V_297 , struct V_260 * V_298 )
{
struct V_296 * V_299 ;
V_299 = F_127 ( V_297 ) ;
if ( V_299 )
return - 1 ;
V_299 = F_124 ( V_297 , V_298 ) ;
if ( ! V_299 )
return - 1 ;
else
F_125 ( V_299 ) ;
return 0 ;
}
static struct V_260 * F_130 ( const char * V_297 )
{
struct V_296 * V_299 = F_127 ( V_297 ) ;
if ( ! V_299 )
return NULL ;
return V_299 -> V_298 ;
}
static void F_131 ( void )
{
struct V_296 * V_299 ;
fprintf ( V_302 , L_52 ) ;
fprintf ( V_302 , L_123
L_124 ) ;
F_128 (s, &script_specs, node)
fprintf ( V_302 , L_125 , V_299 -> V_297 , V_299 -> V_298 -> V_157 ) ;
fprintf ( V_302 , L_52 ) ;
}
static int F_132 ( const struct V_303 * T_7 V_288 ,
const char * V_12 , int T_8 V_288 )
{
char V_297 [ V_304 ] ;
const char * V_239 , * V_305 ;
int V_133 ;
if ( strcmp ( V_12 , L_126 ) == 0 ) {
F_131 () ;
exit ( 0 ) ;
}
V_239 = strchr ( V_12 , ':' ) ;
if ( V_239 ) {
V_133 = V_239 - V_12 ;
if ( V_133 >= V_304 ) {
fprintf ( V_302 , L_127 ) ;
return - 1 ;
}
strncpy ( V_297 , V_12 , V_133 ) ;
V_297 [ V_133 ] = '\0' ;
V_260 = F_130 ( V_297 ) ;
if ( ! V_260 ) {
fprintf ( V_302 , L_127 ) ;
return - 1 ;
}
V_239 ++ ;
} else {
V_239 = V_12 ;
V_305 = strrchr ( V_239 , '.' ) ;
if ( ! V_305 ) {
fprintf ( V_302 , L_128 ) ;
return - 1 ;
}
V_260 = F_130 ( ++ V_305 ) ;
if ( ! V_260 ) {
fprintf ( V_302 , L_128 ) ;
return - 1 ;
}
}
V_306 = F_133 ( V_239 ) ;
return 0 ;
}
static int F_134 ( const struct V_303 * T_7 V_288 ,
const char * V_307 , int T_8 V_288 )
{
char * V_308 , * V_309 = NULL ;
int V_9 , V_10 = F_5 ( V_11 ) ;
int V_3 ;
int V_310 = 0 ;
char * V_12 = F_133 ( V_307 ) ;
int type = - 1 ;
enum { DEFAULT , V_311 , V_312 , REMOVE } V_313 = DEFAULT ;
if ( ! V_12 )
return - V_314 ;
V_308 = strchr ( V_12 , ':' ) ;
if ( V_308 ) {
* V_308 = '\0' ;
V_308 ++ ;
if ( ! strcmp ( V_12 , L_129 ) )
type = V_315 ;
else if ( ! strcmp ( V_12 , L_130 ) )
type = V_316 ;
else if ( ! strcmp ( V_12 , L_131 ) )
type = V_79 ;
else if ( ! strcmp ( V_12 , L_132 ) )
type = V_317 ;
else if ( ! strcmp ( V_12 , L_133 ) )
type = V_318 ;
else if ( ! strcmp ( V_12 , L_134 ) )
type = V_2 ;
else {
fprintf ( V_302 , L_135 ) ;
V_310 = - V_28 ;
goto V_82;
}
if ( V_5 [ type ] . V_6 )
F_135 ( L_136 ,
F_19 ( type ) ) ;
V_5 [ type ] . V_21 = 0 ;
V_5 [ type ] . V_6 = true ;
V_5 [ type ] . V_73 = false ;
} else {
V_308 = V_12 ;
if ( strlen ( V_12 ) == 0 ) {
fprintf ( V_302 ,
L_137 ) ;
V_310 = - V_28 ;
goto V_82;
}
if ( strchr ( V_12 , '+' ) || strchr ( V_12 , '-' ) )
goto V_319;
if ( F_3 () )
F_135 ( L_138 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
V_5 [ V_3 ] . V_21 = 0 ;
V_5 [ V_3 ] . V_6 = true ;
V_5 [ V_3 ] . V_73 = true ;
}
}
V_319:
for ( V_308 = strtok_r ( V_308 , L_139 , & V_309 ) ; V_308 ; V_308 = strtok_r ( NULL , L_139 , & V_309 ) ) {
if ( * V_308 == '+' ) {
if ( V_313 == V_311 )
goto V_320;
V_313 = V_312 ;
V_308 ++ ;
} else if ( * V_308 == '-' ) {
if ( V_313 == V_311 )
goto V_320;
V_313 = REMOVE ;
V_308 ++ ;
} else {
if ( V_313 != V_311 && V_313 != DEFAULT )
goto V_320;
V_313 = V_311 ;
}
for ( V_9 = 0 ; V_9 < V_10 ; ++ V_9 ) {
if ( strcmp ( V_308 , V_11 [ V_9 ] . V_12 ) == 0 )
break;
}
if ( V_9 == V_10 && strcmp ( V_308 , L_140 ) == 0 ) {
V_243 = V_313 == REMOVE ? false : true ;
continue;
}
if ( V_9 == V_10 ) {
fprintf ( V_302 , L_141 ) ;
V_310 = - V_28 ;
goto V_82;
}
if ( type == - 1 ) {
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( V_5 [ V_3 ] . V_321 & V_11 [ V_9 ] . V_8 ) {
F_135 ( L_142 ,
V_11 [ V_9 ] . V_12 , F_19 ( V_3 ) ) ;
} else {
if ( V_313 == REMOVE )
V_5 [ V_3 ] . V_21 &= ~ V_11 [ V_9 ] . V_8 ;
else
V_5 [ V_3 ] . V_21 |= V_11 [ V_9 ] . V_8 ;
}
}
} else {
if ( V_5 [ type ] . V_321 & V_11 [ V_9 ] . V_8 ) {
fprintf ( V_302 , L_143 ,
V_11 [ V_9 ] . V_12 , F_19 ( type ) ) ;
V_310 = - V_28 ;
goto V_82;
}
V_5 [ type ] . V_21 |= V_11 [ V_9 ] . V_8 ;
}
}
if ( type >= 0 ) {
if ( V_5 [ type ] . V_21 == 0 ) {
F_9 ( L_144
L_145 , F_19 ( type ) ) ;
}
}
goto V_82;
V_320:
fprintf ( V_302 , L_146 ) ;
V_310 = - V_28 ;
V_82:
free ( V_12 ) ;
return V_310 ;
}
static int F_136 ( const char * V_322 , const struct V_323 * V_324 )
{
char V_325 [ V_304 ] ;
struct V_326 V_327 ;
sprintf ( V_325 , L_147 , V_322 , V_324 -> V_328 ) ;
if ( V_326 ( V_325 , & V_327 ) )
return 0 ;
return F_137 ( V_327 . V_329 ) ;
}
static struct V_330 * F_138 ( const char * V_157 )
{
struct V_330 * V_299 = F_139 ( sizeof( * V_299 ) ) ;
if ( V_299 != NULL && V_157 )
V_299 -> V_157 = F_133 ( V_157 ) ;
return V_299 ;
}
static void F_140 ( struct V_330 * V_299 )
{
F_141 ( & V_299 -> V_157 ) ;
F_141 ( & V_299 -> V_331 ) ;
F_141 ( & V_299 -> args ) ;
free ( V_299 ) ;
}
static void F_142 ( struct V_330 * V_299 )
{
F_126 ( & V_299 -> V_300 , & V_332 ) ;
}
static struct V_330 * F_143 ( const char * V_157 )
{
struct V_330 * V_299 ;
F_128 (s, &script_descs, node)
if ( strcasecmp ( V_299 -> V_157 , V_157 ) == 0 )
return V_299 ;
return NULL ;
}
static struct V_330 * F_144 ( const char * V_157 )
{
struct V_330 * V_299 = F_143 ( V_157 ) ;
if ( V_299 )
return V_299 ;
V_299 = F_138 ( V_157 ) ;
if ( ! V_299 )
goto V_333;
F_142 ( V_299 ) ;
return V_299 ;
V_333:
F_140 ( V_299 ) ;
return NULL ;
}
static const char * F_145 ( const char * V_12 , const char * V_334 )
{
T_4 V_335 = strlen ( V_334 ) ;
const char * V_336 = V_12 ;
if ( strlen ( V_12 ) > V_335 ) {
V_336 = V_12 + strlen ( V_12 ) - V_335 ;
if ( ! strncmp ( V_336 , V_334 , V_335 ) )
return V_336 ;
}
return NULL ;
}
static int F_146 ( struct V_330 * V_337 , const char * V_338 )
{
char line [ V_339 ] , * V_336 ;
T_9 * V_340 ;
V_340 = fopen ( V_338 , L_148 ) ;
if ( ! V_340 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_340 ) ) {
V_336 = F_147 ( line ) ;
if ( strlen ( V_336 ) == 0 )
continue;
if ( * V_336 != '#' )
continue;
V_336 ++ ;
if ( strlen ( V_336 ) && * V_336 == '!' )
continue;
V_336 = F_147 ( V_336 ) ;
if ( strlen ( V_336 ) && V_336 [ strlen ( V_336 ) - 1 ] == '\n' )
V_336 [ strlen ( V_336 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_336 , L_149 , strlen ( L_149 ) ) ) {
V_336 += strlen ( L_149 ) ;
V_337 -> V_331 = F_133 ( F_147 ( V_336 ) ) ;
continue;
}
if ( ! strncmp ( V_336 , L_150 , strlen ( L_150 ) ) ) {
V_336 += strlen ( L_150 ) ;
V_337 -> args = F_133 ( F_147 ( V_336 ) ) ;
continue;
}
}
fclose ( V_340 ) ;
return 0 ;
}
static char * F_148 ( struct V_323 * V_341 , const char * V_334 )
{
char * V_342 , * V_12 ;
V_342 = F_133 ( V_341 -> V_328 ) ;
if ( ! V_342 )
return NULL ;
V_12 = ( char * ) F_145 ( V_342 , V_334 ) ;
if ( ! V_12 ) {
free ( V_342 ) ;
return NULL ;
}
* V_12 = '\0' ;
return V_342 ;
}
static int F_149 ( const struct V_303 * T_7 V_288 ,
const char * V_299 V_288 ,
int T_8 V_288 )
{
struct V_323 * V_341 , * V_343 ;
char V_344 [ V_345 ] ;
T_10 * V_346 , * V_347 ;
char V_348 [ V_345 ] ;
char V_349 [ V_345 ] ;
struct V_330 * V_337 ;
char V_350 [ V_339 ] ;
char * V_342 ;
snprintf ( V_344 , V_345 , L_151 , F_150 () ) ;
V_346 = F_151 ( V_344 ) ;
if ( ! V_346 ) {
fprintf ( stdout ,
L_152
L_153 ,
V_344 ) ;
exit ( - 1 ) ;
}
F_152 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_349 , V_345 , L_154 , V_344 ,
V_343 -> V_328 ) ;
V_347 = F_151 ( V_349 ) ;
if ( ! V_347 )
continue;
F_153 (lang_path, lang_dir, script_dirent) {
V_342 = F_148 ( V_341 , V_351 ) ;
if ( V_342 ) {
V_337 = F_144 ( V_342 ) ;
snprintf ( V_348 , V_345 , L_147 ,
V_349 , V_341 -> V_328 ) ;
F_146 ( V_337 , V_348 ) ;
free ( V_342 ) ;
}
}
}
fprintf ( stdout , L_155 ) ;
F_128 (desc, &script_descs, node) {
sprintf ( V_350 , L_156 , V_337 -> V_157 ,
V_337 -> args ? V_337 -> args : L_1 ) ;
fprintf ( stdout , L_157 , V_350 ,
V_337 -> V_331 ? V_337 -> V_331 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_154 ( char * V_352 , char * V_353 ,
struct V_22 * V_23 )
{
char V_338 [ V_345 ] , V_20 [ 128 ] ;
char line [ V_339 ] , * V_336 ;
struct V_13 * V_182 ;
int V_354 , V_133 ;
T_9 * V_340 ;
sprintf ( V_338 , L_158 , V_352 , V_353 ) ;
V_340 = fopen ( V_338 , L_148 ) ;
if ( ! V_340 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_340 ) ) {
V_336 = F_147 ( line ) ;
if ( * V_336 == '#' )
continue;
while ( strlen ( V_336 ) ) {
V_336 = strstr ( V_336 , L_159 ) ;
if ( ! V_336 )
break;
V_336 += 2 ;
V_336 = F_147 ( V_336 ) ;
V_133 = strcspn ( V_336 , L_160 ) ;
if ( ! V_133 )
break;
snprintf ( V_20 , V_133 + 1 , L_161 , V_336 ) ;
V_354 = 0 ;
F_20 (session->evlist, pos) {
if ( ! strcmp ( F_7 ( V_182 ) , V_20 ) ) {
V_354 = 1 ;
break;
}
}
if ( ! V_354 ) {
fclose ( V_340 ) ;
return - 1 ;
}
}
}
fclose ( V_340 ) ;
return 0 ;
}
int F_155 ( char * * V_355 , char * * V_356 )
{
struct V_323 * V_341 , * V_343 ;
char V_344 [ V_345 ] , V_349 [ V_345 ] ;
T_10 * V_346 , * V_347 ;
struct V_22 * V_23 ;
struct V_357 V_358 = {
. V_325 = V_359 ,
. V_360 = V_361 ,
} ;
char * V_362 ;
int V_9 = 0 ;
V_23 = F_156 ( & V_358 , false , NULL ) ;
if ( ! V_23 )
return - 1 ;
snprintf ( V_344 , V_345 , L_151 , F_150 () ) ;
V_346 = F_151 ( V_344 ) ;
if ( ! V_346 ) {
F_157 ( V_23 ) ;
return - 1 ;
}
F_152 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_349 , V_345 , L_147 , V_344 ,
V_343 -> V_328 ) ;
#ifdef F_158
if ( strstr ( V_349 , L_162 ) )
continue;
#endif
#ifdef F_159
if ( strstr ( V_349 , L_163 ) )
continue;
#endif
V_347 = F_151 ( V_349 ) ;
if ( ! V_347 )
continue;
F_153 (lang_path, lang_dir, script_dirent) {
if ( strstr ( V_341 -> V_328 , L_164 ) )
continue;
sprintf ( V_356 [ V_9 ] , L_147 , V_349 ,
V_341 -> V_328 ) ;
V_362 = strchr ( V_341 -> V_328 , '.' ) ;
snprintf ( V_355 [ V_9 ] ,
( V_362 - V_341 -> V_328 ) + 1 ,
L_161 , V_341 -> V_328 ) ;
if ( F_154 ( V_349 ,
V_355 [ V_9 ] , V_23 ) )
continue;
V_9 ++ ;
}
F_160 ( V_347 ) ;
}
F_160 ( V_346 ) ;
F_157 ( V_23 ) ;
return V_9 ;
}
static char * F_161 ( const char * V_342 , const char * V_334 )
{
struct V_323 * V_341 , * V_343 ;
char V_344 [ V_345 ] ;
char V_348 [ V_345 ] ;
T_10 * V_346 , * V_347 ;
char V_349 [ V_345 ] ;
char * V_363 ;
snprintf ( V_344 , V_345 , L_151 , F_150 () ) ;
V_346 = F_151 ( V_344 ) ;
if ( ! V_346 )
return NULL ;
F_152 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_349 , V_345 , L_154 , V_344 ,
V_343 -> V_328 ) ;
V_347 = F_151 ( V_349 ) ;
if ( ! V_347 )
continue;
F_153 (lang_path, lang_dir, script_dirent) {
V_363 = F_148 ( V_341 , V_334 ) ;
if ( V_363 && ! strcmp ( V_342 , V_363 ) ) {
free ( V_363 ) ;
F_160 ( V_347 ) ;
F_160 ( V_346 ) ;
snprintf ( V_348 , V_345 , L_147 ,
V_349 , V_341 -> V_328 ) ;
return F_133 ( V_348 ) ;
}
free ( V_363 ) ;
}
F_160 ( V_347 ) ;
}
F_160 ( V_346 ) ;
return NULL ;
}
static bool F_162 ( const char * V_348 )
{
return F_145 ( V_348 , L_165 ) == NULL ? false : true ;
}
static int F_163 ( char * V_348 )
{
struct V_330 * V_337 ;
int V_364 = 0 ;
char * V_336 ;
V_337 = F_138 ( NULL ) ;
if ( F_146 ( V_337 , V_348 ) )
goto V_82;
if ( ! V_337 -> args )
goto V_82;
for ( V_336 = V_337 -> args ; * V_336 ; V_336 ++ )
if ( * V_336 == '<' )
V_364 ++ ;
V_82:
F_140 ( V_337 ) ;
return V_364 ;
}
static int F_164 ( int V_365 , const char * * V_366 )
{
char * * V_367 = malloc ( sizeof( const char * ) * V_365 ) ;
if ( ! V_367 ) {
F_8 ( L_166 ) ;
return - 1 ;
}
memcpy ( V_367 , V_366 , sizeof( const char * ) * V_365 ) ;
V_365 = F_165 ( V_365 , ( const char * * ) V_367 , V_368 ,
NULL , V_369 ) ;
free ( V_367 ) ;
V_254 = ( V_365 == 0 ) ;
return 0 ;
}
static void F_166 ( struct V_238 * V_239 )
{
struct V_22 * V_23 = V_239 -> V_23 ;
T_1 V_15 = F_167 ( V_23 -> V_49 ) ;
if ( V_78 . V_75 || V_78 . V_370 ) {
if ( ( V_15 & V_371 ) &&
( V_15 & V_372 ) )
V_373 . V_374 = V_375 ;
else if ( V_15 & V_376 )
V_373 . V_374 = V_377 ;
else
V_373 . V_374 = V_378 ;
}
}
static int F_168 ( struct V_264 * V_265 V_288 ,
union V_266 * V_267 ,
struct V_22 * V_23 )
{
struct V_379 * V_380 = & V_267 -> V_381 ;
struct V_13 * V_248 ;
F_20 (session->evlist, counter) {
F_169 ( & V_261 , V_248 ) ;
F_87 ( V_248 , V_380 -> time ) ;
}
F_88 ( V_380 -> time ) ;
return 0 ;
}
static int F_170 ( struct V_264 * V_265 V_288 ,
union V_266 * V_267 ,
struct V_22 * V_23 V_288 )
{
F_171 ( & V_261 , & V_267 -> V_261 ) ;
return 0 ;
}
static int F_172 ( struct V_238 * V_239 )
{
struct V_231 * V_49 = V_239 -> V_23 -> V_49 ;
if ( ! V_239 -> V_257 || ! V_239 -> V_251 )
return 0 ;
if ( F_173 ( V_239 -> V_382 , L_167 ) )
return - V_28 ;
F_174 ( V_49 , V_239 -> V_257 , V_239 -> V_251 ) ;
if ( F_175 ( V_49 , true ) )
return - V_314 ;
V_239 -> V_382 = true ;
return 0 ;
}
static
int F_176 ( struct V_264 * V_265 ,
union V_266 * V_267 ,
struct V_22 * V_23 V_288 )
{
struct V_238 * V_239 = F_95 ( V_265 , struct V_238 , V_265 ) ;
if ( V_239 -> V_251 ) {
F_135 ( L_168 ) ;
return 0 ;
}
V_239 -> V_251 = F_177 ( & V_267 -> V_383 ) ;
if ( ! V_239 -> V_251 )
return - V_314 ;
return F_172 ( V_239 ) ;
}
static
int F_178 ( struct V_264 * V_265 V_288 ,
union V_266 * V_267 ,
struct V_22 * V_23 V_288 )
{
struct V_238 * V_239 = F_95 ( V_265 , struct V_238 , V_265 ) ;
if ( V_239 -> V_257 ) {
F_135 ( L_169 ) ;
return 0 ;
}
V_239 -> V_257 = F_179 ( & V_267 -> V_384 . V_142 ) ;
if ( ! V_239 -> V_257 )
return - V_314 ;
return F_172 ( V_239 ) ;
}
int F_180 ( int V_365 , const char * * V_366 )
{
bool V_385 = false ;
bool V_24 = false ;
bool V_386 = false ;
bool V_387 = false ;
char * V_388 = NULL ;
char * V_389 = NULL ;
struct V_22 * V_23 ;
struct V_390 V_390 = { . V_391 = false , } ;
char * V_348 = NULL ;
const char * * V_367 ;
int V_9 , V_3 , V_278 = 0 ;
struct V_238 V_239 = {
. V_265 = {
. V_84 = F_94 ,
. V_286 = F_116 ,
. V_287 = F_118 ,
. V_282 = F_106 ,
. V_284 = F_110 ,
. exit = F_114 ,
. V_285 = F_112 ,
. V_19 = F_100 ,
. V_392 = V_393 ,
. V_394 = V_395 ,
. V_396 = V_397 ,
. V_398 = V_399 ,
. V_400 = V_401 ,
. V_402 = V_403 ,
. V_404 = V_405 ,
. V_326 = V_406 ,
. V_381 = F_168 ,
. V_261 = F_170 ,
. V_383 = F_176 ,
. V_384 = F_178 ,
. V_407 = true ,
. V_408 = true ,
} ,
} ;
struct V_357 V_358 = {
. V_360 = V_361 ,
} ;
const struct V_303 V_409 [] = {
F_181 ( 'D' , L_170 , & V_410 ,
L_171 ) ,
F_182 ( 'v' , L_172 , & V_411 ,
L_173 ) ,
F_181 ( 'L' , L_174 , & V_97 ,
L_175 ) ,
F_183 ( 'l' , L_176 , NULL , NULL , L_177 ,
F_149 ) ,
F_184 ( 's' , L_178 , NULL , L_179 ,
L_180 ,
F_132 ) ,
F_185 ( 'g' , L_181 , & V_412 , L_126 ,
L_182 ) ,
F_185 ( 'i' , L_183 , & V_359 , L_184 , L_185 ) ,
F_181 ( 'd' , L_186 , & V_270 ,
L_187 ) ,
F_181 ( 0 , L_188 , & V_24 , L_189 ) ,
F_181 ( 0 , L_190 , & V_386 , L_191 ) ,
F_185 ( 'k' , L_192 , & V_78 . V_413 ,
L_184 , L_193 ) ,
F_185 ( 0 , L_194 , & V_78 . V_414 ,
L_184 , L_195 ) ,
F_181 ( 'G' , L_196 , & V_74 ,
L_197 ) ,
F_184 ( 0 , L_198 , NULL , L_199 ,
L_200 ,
V_415 ) ,
F_184 ( 'F' , L_201 , NULL , L_202 ,
L_203
L_204
L_205
L_206
L_207
L_208 ,
F_134 ) ,
F_181 ( 'a' , L_209 , & V_254 ,
L_210 ) ,
F_185 ( 'S' , L_211 , & V_78 . V_416 , L_212 ,
L_213 ) ,
F_185 ( 0 , L_214 , & V_78 . V_417 , L_212 ,
L_215 ) ,
F_185 ( 'C' , L_216 , & V_275 , L_216 , L_217 ) ,
F_185 ( 'c' , L_218 , & V_78 . V_418 , L_219 ,
L_220 ) ,
F_185 ( 0 , L_221 , & V_78 . V_419 , L_222 ,
L_223 ) ,
F_185 ( 0 , L_224 , & V_78 . V_420 , L_225 ,
L_226 ) ,
F_186 ( 0 , L_227 , & V_177 ,
L_228
L_229
L_230 F_187 ( V_421 ) ) ,
F_181 ( 'I' , L_231 , & V_385 ,
L_232 ) ,
F_181 ( '\0' , L_233 , & V_78 . V_422 ,
L_234 ) ,
F_181 ( '\0' , L_235 , & V_239 . V_291 ,
L_236 ) ,
F_181 ( '\0' , L_237 , & V_239 . V_292 ,
L_238 ) ,
F_181 ( '\0' , L_239 , & V_239 . V_293 ,
L_240 ) ,
F_181 ( '\0' , L_241 , & V_239 . V_295 ,
L_242 ) ,
F_181 ( 'f' , L_243 , & V_78 . V_423 , L_244 ) ,
F_188 ( 0 , L_245 , & V_159 ,
L_246 ) ,
F_181 ( 0 , L_247 , & V_102 ,
L_248 ) ,
F_189 ( 0 , L_249 , & V_390 , NULL , L_250 ,
L_251 ,
V_424 ) ,
F_181 ( 0 , L_252 , & V_425 ,
L_253 ) ,
F_181 ( 0 , L_254 , & V_78 . V_426 ,
L_255 ) ,
F_181 ( 0 , L_256 , & V_78 . V_427 ,
L_257 ) ,
F_185 ( 0 , L_258 , & V_239 . V_428 , L_202 ,
L_259 ) ,
F_181 ( 0 , L_260 , & V_78 . V_429 ,
L_261 ) ,
F_190 ()
} ;
const char * const V_430 [] = { L_262 , L_263 , NULL } ;
const char * V_431 [] = {
L_264 ,
L_265 ,
L_266 ,
L_267 ,
L_268 ,
NULL
} ;
F_89 () ;
V_365 = F_191 ( V_365 , V_366 , V_409 , V_430 , V_431 ,
V_369 ) ;
V_358 . V_325 = V_359 ;
V_358 . V_423 = V_78 . V_423 ;
if ( V_365 > 1 && ! strncmp ( V_366 [ 0 ] , L_269 , strlen ( L_269 ) ) ) {
V_388 = F_161 ( V_366 [ 1 ] , V_432 ) ;
if ( ! V_388 )
return F_192 ( V_365 , V_366 ) ;
}
if ( V_365 > 1 && ! strncmp ( V_366 [ 0 ] , L_270 , strlen ( L_270 ) ) ) {
V_389 = F_161 ( V_366 [ 1 ] , V_351 ) ;
if ( ! V_389 ) {
fprintf ( V_302 ,
L_271
L_272 ) ;
return - 1 ;
}
}
if ( V_390 . V_176 &&
V_390 . V_433 > V_177 )
V_177 = V_390 . V_433 ;
F_193 ( F_150 () ) ;
if ( V_365 && ! V_306 && ! V_388 && ! V_389 ) {
int V_434 [ 2 ] ;
int V_435 ;
T_11 V_98 ;
V_388 = F_161 ( V_366 [ 0 ] , V_432 ) ;
V_389 = F_161 ( V_366 [ 0 ] , V_351 ) ;
if ( ! V_388 && ! V_389 ) {
F_194 ( V_431 , V_409 ,
L_273
L_274 , V_366 [ 0 ] ) ;
}
if ( F_162 ( V_366 [ 0 ] ) ) {
V_435 = V_365 - 1 ;
} else {
int V_436 ;
V_435 = F_163 ( V_389 ) ;
V_436 = ( V_365 - 1 ) - V_435 ;
if ( V_436 < 0 ) {
F_194 ( V_431 , V_409 ,
L_275
L_276
L_277 , V_366 [ 0 ] ) ;
}
}
if ( F_195 ( V_434 ) < 0 ) {
perror ( L_278 ) ;
return - 1 ;
}
V_98 = V_285 () ;
if ( V_98 < 0 ) {
perror ( L_279 ) ;
return - 1 ;
}
if ( ! V_98 ) {
V_3 = 0 ;
F_196 ( V_434 [ 1 ] , 1 ) ;
F_197 ( V_434 [ 0 ] ) ;
if ( F_162 ( V_366 [ 0 ] ) ) {
V_254 = true ;
} else if ( ! V_254 ) {
if ( F_164 ( V_365 - V_435 , & V_366 [ V_435 ] ) != 0 ) {
V_278 = - 1 ;
goto V_82;
}
}
V_367 = malloc ( ( V_365 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_367 ) {
F_8 ( L_166 ) ;
V_278 = - V_314 ;
goto V_82;
}
V_367 [ V_3 ++ ] = L_280 ;
V_367 [ V_3 ++ ] = V_388 ;
if ( V_254 )
V_367 [ V_3 ++ ] = L_281 ;
V_367 [ V_3 ++ ] = L_282 ;
V_367 [ V_3 ++ ] = L_283 ;
V_367 [ V_3 ++ ] = L_284 ;
for ( V_9 = V_435 + 1 ; V_9 < V_365 ; V_9 ++ )
V_367 [ V_3 ++ ] = V_366 [ V_9 ] ;
V_367 [ V_3 ++ ] = NULL ;
F_198 ( L_280 , ( char * * ) V_367 ) ;
free ( V_367 ) ;
exit ( - 1 ) ;
}
F_196 ( V_434 [ 0 ] , 0 ) ;
F_197 ( V_434 [ 1 ] ) ;
V_367 = malloc ( ( V_365 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_367 ) {
F_8 ( L_166 ) ;
V_278 = - V_314 ;
goto V_82;
}
V_3 = 0 ;
V_367 [ V_3 ++ ] = L_280 ;
V_367 [ V_3 ++ ] = V_389 ;
for ( V_9 = 1 ; V_9 < V_435 + 1 ; V_9 ++ )
V_367 [ V_3 ++ ] = V_366 [ V_9 ] ;
V_367 [ V_3 ++ ] = L_285 ;
V_367 [ V_3 ++ ] = L_284 ;
V_367 [ V_3 ++ ] = NULL ;
F_198 ( L_280 , ( char * * ) V_367 ) ;
free ( V_367 ) ;
exit ( - 1 ) ;
}
if ( V_388 )
V_348 = V_388 ;
if ( V_389 )
V_348 = V_389 ;
if ( V_348 ) {
V_3 = 0 ;
if ( ! V_388 )
V_254 = false ;
else if ( ! V_254 ) {
if ( F_164 ( V_365 - 1 , & V_366 [ 1 ] ) != 0 ) {
V_278 = - 1 ;
goto V_82;
}
}
V_367 = malloc ( ( V_365 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_367 ) {
F_8 ( L_166 ) ;
V_278 = - V_314 ;
goto V_82;
}
V_367 [ V_3 ++ ] = L_280 ;
V_367 [ V_3 ++ ] = V_348 ;
if ( V_254 )
V_367 [ V_3 ++ ] = L_281 ;
for ( V_9 = 2 ; V_9 < V_365 ; V_9 ++ )
V_367 [ V_3 ++ ] = V_366 [ V_9 ] ;
V_367 [ V_3 ++ ] = NULL ;
F_198 ( L_280 , ( char * * ) V_367 ) ;
free ( V_367 ) ;
exit ( - 1 ) ;
}
if ( ! V_306 )
F_199 () ;
V_23 = F_156 ( & V_358 , false , & V_239 . V_265 ) ;
if ( V_23 == NULL )
return - 1 ;
if ( V_24 || V_386 ) {
F_200 ( V_23 , stdout , V_385 ) ;
if ( V_386 )
goto V_437;
}
if ( F_201 ( & V_23 -> V_24 . V_438 ) < 0 )
goto V_437;
V_239 . V_23 = V_23 ;
F_166 ( & V_239 ) ;
if ( V_5 [ V_315 ] . V_21 & V_439 )
V_390 . V_440 = true ;
V_23 -> V_390 = & V_390 ;
if ( V_275 ) {
V_278 = F_202 ( V_23 , V_275 , V_276 ) ;
if ( V_278 < 0 )
goto V_437;
V_390 . V_276 = V_276 ;
}
if ( ! V_74 )
V_78 . V_75 = true ;
else
V_78 . V_75 = false ;
if ( V_23 -> V_441 . V_442 &&
F_203 ( V_23 -> V_441 . V_442 ,
V_443 ,
& V_23 -> V_444 . V_445 ) < 0 ) {
F_8 ( L_286 , V_446 ) ;
return - 1 ;
}
if ( V_412 ) {
struct V_326 V_447 ;
int V_448 ;
if ( F_3 () ) {
fprintf ( V_302 ,
L_287 ) ;
V_278 = - V_28 ;
goto V_437;
}
V_448 = F_204 ( V_358 . V_325 , V_449 ) ;
if ( V_448 < 0 ) {
V_278 = - V_450 ;
perror ( L_288 ) ;
goto V_437;
}
V_278 = F_205 ( V_448 , & V_447 ) ;
if ( V_278 < 0 ) {
perror ( L_289 ) ;
goto V_437;
}
if ( ! V_447 . V_451 ) {
fprintf ( V_302 , L_290 ) ;
goto V_437;
}
V_260 = F_130 ( V_412 ) ;
if ( ! V_260 ) {
fprintf ( V_302 , L_127 ) ;
V_278 = - V_452 ;
goto V_437;
}
V_278 = V_260 -> V_453 ( V_23 -> V_441 . V_442 ,
L_291 ) ;
goto V_437;
}
if ( V_306 ) {
V_278 = V_260 -> V_454 ( V_306 , V_365 , V_366 ) ;
if ( V_278 )
goto V_437;
F_9 ( L_292 , V_306 ) ;
V_387 = true ;
}
V_278 = F_17 ( V_23 ) ;
if ( V_278 < 0 )
goto V_437;
if ( F_206 ( & V_239 . V_269 , V_239 . V_428 ) != 0 ) {
F_8 ( L_293 ) ;
return - V_28 ;
}
V_278 = F_122 ( & V_239 ) ;
F_92 () ;
V_437:
F_207 ( V_23 -> V_49 ) ;
F_157 ( V_23 ) ;
if ( V_387 )
F_93 () ;
V_82:
return V_278 ;
}
