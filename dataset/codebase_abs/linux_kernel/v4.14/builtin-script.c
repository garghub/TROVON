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
if ( F_13 ( V_67 ) &&
F_10 ( V_14 , V_68 , L_26 ,
V_69 ) )
return - V_28 ;
return 0 ;
}
static void F_16 ( struct V_18 * V_19 )
{
unsigned int type = F_1 ( V_19 -> type ) ;
V_5 [ type ] . V_70 = 0 ;
if ( F_13 ( V_29 ) )
V_5 [ type ] . V_70 |= V_71 ;
if ( F_13 ( V_41 ) )
V_5 [ type ] . V_70 |= V_72 ;
if ( F_13 ( V_43 ) )
V_5 [ type ] . V_70 |= V_73 ;
if ( F_13 ( V_42 ) )
V_5 [ type ] . V_70 |= V_74 ;
if ( F_13 ( V_47 ) )
V_5 [ type ] . V_70 |= V_75 ;
}
static int F_17 ( struct V_22 * V_23 )
{
unsigned int V_3 ;
struct V_13 * V_14 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
V_14 = F_18 ( V_23 , F_2 ( V_3 ) ) ;
if ( ! V_14 && V_5 [ V_3 ] . V_6 && ! V_5 [ V_3 ] . V_76 &&
V_3 != V_2 ) {
F_8 ( L_27
L_28 ,
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
if ( ! V_77 ) {
bool V_78 = false ;
bool V_79 = false ;
F_20 (session->evlist, evsel) {
V_79 = true ;
if ( V_14 -> V_19 . V_15 & V_80 ) {
V_78 = true ;
break;
}
}
if ( V_79 && ! V_78 )
V_81 . V_78 = false ;
}
if ( V_81 . V_78 &&
! V_5 [ V_82 ] . V_6 ) {
struct V_18 * V_19 ;
V_3 = V_82 ;
F_20 (session->evlist, evsel) {
if ( V_14 -> V_19 . type != V_3 )
continue;
V_19 = & V_14 -> V_19 ;
if ( V_19 -> V_15 & V_80 ) {
V_5 [ V_3 ] . V_21 |= V_31 ;
V_5 [ V_3 ] . V_21 |= V_83 ;
V_5 [ V_3 ] . V_21 |= V_84 ;
F_16 ( V_19 ) ;
goto V_85;
}
}
}
V_85:
return 0 ;
}
static void F_21 ( struct V_86 * V_87 ,
struct V_18 * V_19 )
{
struct V_88 * V_89 = & V_87 -> V_90 ;
T_2 V_91 = V_19 -> V_92 ;
unsigned V_9 = 0 , V_93 ;
if ( ! V_89 )
return;
F_22 (r, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_1 V_94 = V_89 -> V_89 [ V_9 ++ ] ;
printf ( L_29 V_95 L_30 , F_23 ( V_93 ) , V_94 ) ;
}
}
static void F_24 ( struct V_86 * V_87 ,
struct V_96 * V_96 ,
struct V_13 * V_14 )
{
struct V_18 * V_19 = & V_14 -> V_19 ;
unsigned long V_97 ;
unsigned long long V_98 ;
if ( F_13 ( V_99 ) ) {
if ( V_100 )
printf ( L_31 , F_25 ( V_96 ) ) ;
else if ( F_13 ( V_29 ) && V_81 . V_78 )
printf ( L_32 , F_25 ( V_96 ) ) ;
else
printf ( L_33 , F_25 ( V_96 ) ) ;
}
if ( F_13 ( V_51 ) && F_13 ( V_52 ) )
printf ( L_34 , V_87 -> V_101 , V_87 -> V_102 ) ;
else if ( F_13 ( V_51 ) )
printf ( L_35 , V_87 -> V_101 ) ;
else if ( F_13 ( V_52 ) )
printf ( L_35 , V_87 -> V_102 ) ;
if ( F_13 ( V_58 ) ) {
if ( V_100 )
printf ( L_36 , V_87 -> V_103 ) ;
else
printf ( L_37 , V_87 -> V_103 ) ;
}
if ( F_13 ( TIME ) ) {
V_98 = V_87 -> time ;
V_97 = V_98 / V_104 ;
V_98 -= V_97 * V_104 ;
if ( V_105 )
printf ( L_38 , V_97 , V_98 ) ;
else {
char V_106 [ 32 ] ;
F_26 ( V_87 -> time , V_106 , sizeof( V_106 ) ) ;
printf ( L_39 , V_106 ) ;
}
}
}
static inline char
F_27 ( struct V_107 * V_108 )
{
if ( ! ( V_108 -> V_109 . V_110 || V_108 -> V_109 . V_111 ) )
return '-' ;
return V_108 -> V_109 . V_111 ? 'P' : 'M' ;
}
static void F_28 ( struct V_86 * V_87 ,
struct V_96 * V_96 ,
struct V_18 * V_19 )
{
struct V_112 * V_108 = V_87 -> V_112 ;
struct V_113 V_114 , V_115 ;
T_1 V_9 , V_116 , V_117 ;
if ( ! ( V_108 && V_108 -> V_118 ) )
return;
for ( V_9 = 0 ; V_9 < V_108 -> V_118 ; V_9 ++ ) {
V_116 = V_108 -> V_119 [ V_9 ] . V_116 ;
V_117 = V_108 -> V_119 [ V_9 ] . V_117 ;
if ( F_13 ( V_43 ) ) {
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
F_29 ( V_96 , V_87 -> V_120 , V_121 , V_116 , & V_114 ) ;
F_29 ( V_96 , V_87 -> V_120 , V_121 , V_117 , & V_115 ) ;
}
printf ( L_40 V_95 , V_116 ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_41 ) ;
F_30 ( V_114 . V_122 , stdout ) ;
printf ( L_42 ) ;
}
printf ( L_43 V_95 , V_117 ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_41 ) ;
F_30 ( V_115 . V_122 , stdout ) ;
printf ( L_42 ) ;
}
printf ( L_44 ,
F_27 ( V_108 -> V_119 + V_9 ) ,
V_108 -> V_119 [ V_9 ] . V_109 . V_123 ? 'X' : '-' ,
V_108 -> V_119 [ V_9 ] . V_109 . abort ? 'A' : '-' ,
V_108 -> V_119 [ V_9 ] . V_109 . V_124 ) ;
}
}
static void F_31 ( struct V_86 * V_87 ,
struct V_96 * V_96 ,
struct V_18 * V_19 )
{
struct V_112 * V_108 = V_87 -> V_112 ;
struct V_113 V_114 , V_115 ;
T_1 V_9 , V_116 , V_117 ;
if ( ! ( V_108 && V_108 -> V_118 ) )
return;
for ( V_9 = 0 ; V_9 < V_108 -> V_118 ; V_9 ++ ) {
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_116 = V_108 -> V_119 [ V_9 ] . V_116 ;
V_117 = V_108 -> V_119 [ V_9 ] . V_117 ;
F_29 ( V_96 , V_87 -> V_120 , V_121 , V_116 , & V_114 ) ;
if ( V_114 . V_122 )
V_114 . V_125 = F_32 ( V_114 . V_122 , V_114 . V_126 ) ;
F_29 ( V_96 , V_87 -> V_120 , V_121 , V_117 , & V_115 ) ;
if ( V_115 . V_122 )
V_115 . V_125 = F_32 ( V_115 . V_122 , V_115 . V_126 ) ;
F_33 ( V_114 . V_125 , & V_114 , stdout ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_41 ) ;
F_30 ( V_114 . V_122 , stdout ) ;
printf ( L_42 ) ;
}
putchar ( '/' ) ;
F_33 ( V_115 . V_125 , & V_115 , stdout ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_41 ) ;
F_30 ( V_115 . V_122 , stdout ) ;
printf ( L_42 ) ;
}
printf ( L_44 ,
F_27 ( V_108 -> V_119 + V_9 ) ,
V_108 -> V_119 [ V_9 ] . V_109 . V_123 ? 'X' : '-' ,
V_108 -> V_119 [ V_9 ] . V_109 . abort ? 'A' : '-' ,
V_108 -> V_119 [ V_9 ] . V_109 . V_124 ) ;
}
}
static void F_34 ( struct V_86 * V_87 ,
struct V_96 * V_96 ,
struct V_18 * V_19 )
{
struct V_112 * V_108 = V_87 -> V_112 ;
struct V_113 V_114 , V_115 ;
T_1 V_9 , V_116 , V_117 ;
if ( ! ( V_108 && V_108 -> V_118 ) )
return;
for ( V_9 = 0 ; V_9 < V_108 -> V_118 ; V_9 ++ ) {
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_116 = V_108 -> V_119 [ V_9 ] . V_116 ;
V_117 = V_108 -> V_119 [ V_9 ] . V_117 ;
F_29 ( V_96 , V_87 -> V_120 , V_121 , V_116 , & V_114 ) ;
if ( V_114 . V_122 && ! V_114 . V_122 -> V_127 -> V_128 )
V_116 = F_35 ( V_114 . V_122 , V_116 ) ;
F_29 ( V_96 , V_87 -> V_120 , V_121 , V_117 , & V_115 ) ;
if ( V_115 . V_122 && ! V_115 . V_122 -> V_127 -> V_128 )
V_117 = F_35 ( V_115 . V_122 , V_117 ) ;
printf ( L_40 V_95 , V_116 ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_41 ) ;
F_30 ( V_114 . V_122 , stdout ) ;
printf ( L_42 ) ;
}
printf ( L_43 V_95 , V_117 ) ;
if ( F_13 ( V_43 ) ) {
printf ( L_41 ) ;
F_30 ( V_115 . V_122 , stdout ) ;
printf ( L_42 ) ;
}
printf ( L_44 ,
F_27 ( V_108 -> V_119 + V_9 ) ,
V_108 -> V_119 [ V_9 ] . V_109 . V_123 ? 'X' : '-' ,
V_108 -> V_119 [ V_9 ] . V_109 . abort ? 'A' : '-' ,
V_108 -> V_119 [ V_9 ] . V_109 . V_124 ) ;
}
}
static int F_36 ( T_3 * V_129 , T_1 V_130 , T_1 V_131 ,
struct V_132 * V_132 , struct V_96 * V_96 ,
bool * V_133 , T_3 * V_120 , bool V_134 )
{
long V_135 , V_136 ;
struct V_113 V_137 ;
bool V_138 ;
if ( ! V_130 || ! V_131 )
return 0 ;
V_138 = F_37 ( V_132 , V_130 ) ;
if ( V_138 )
* V_120 = V_139 ;
else
* V_120 = V_140 ;
if ( V_138 != F_37 ( V_132 , V_131 ) ) {
printf ( L_45 V_95 L_46 V_95 L_47 ,
V_130 , V_131 ) ;
return - V_141 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( V_131 - V_130 > V_142 - V_143 ) {
if ( V_134 )
printf ( L_48 V_95 L_46 V_95 L_49 , V_130 , V_131 ) ;
else
printf ( L_45 V_95 L_46 V_95 L_50 V_144 L_51 , V_130 , V_131 , V_131 - V_130 ) ;
return 0 ;
}
F_29 ( V_96 , * V_120 , V_121 , V_130 , & V_137 ) ;
if ( ! V_137 . V_122 || ! V_137 . V_122 -> V_127 ) {
printf ( L_52 V_95 L_46 V_95 L_53 , V_130 , V_131 ) ;
return 0 ;
}
if ( V_137 . V_122 -> V_127 -> V_145 . V_146 == V_147 ) {
printf ( L_52 V_95 L_46 V_95 L_53 , V_130 , V_131 ) ;
return 0 ;
}
F_38 ( V_137 . V_122 ) ;
V_135 = V_137 . V_122 -> V_148 ( V_137 . V_122 , V_130 ) ;
V_136 = F_39 ( V_137 . V_122 -> V_127 , V_132 , V_135 , ( T_3 * ) V_129 ,
V_131 - V_130 + V_143 ) ;
* V_133 = V_137 . V_122 -> V_127 -> V_149 ;
if ( V_136 <= 0 )
printf ( L_54 V_95 L_46 V_95 L_53 ,
V_130 , V_131 ) ;
return V_136 ;
}
static void F_40 ( T_2 V_150 , struct V_107 * V_151 ,
struct V_152 * V_153 , T_3 * V_154 , int V_136 ,
int V_155 )
{
printf ( L_55 V_95 L_56 ,
V_150 ,
F_41 ( V_153 , V_150 , V_154 , V_136 , NULL ) ,
V_151 -> V_109 . V_111 ? L_57 : L_1 ,
V_151 -> V_109 . V_110 ? L_58 : L_1 ,
V_151 -> V_109 . V_123 ? L_59 : L_1 ,
V_151 -> V_109 . abort ? L_60 : L_1 ) ;
if ( V_151 -> V_109 . V_124 ) {
printf ( L_61 , V_151 -> V_109 . V_124 ) ;
if ( V_155 )
printf ( L_62 , ( float ) V_155 / V_151 -> V_109 . V_124 ) ;
}
putchar ( '\n' ) ;
}
static void F_42 ( struct V_96 * V_96 , T_3 V_120 , int V_103 ,
T_2 V_126 , struct V_156 * * V_157 ,
struct V_18 * V_19 )
{
struct V_113 V_137 ;
int V_158 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
F_29 ( V_96 , V_120 , V_121 , V_126 , & V_137 ) ;
if ( ! V_137 . V_122 )
F_29 ( V_96 , V_120 , V_159 ,
V_126 , & V_137 ) ;
if ( ( * V_157 ) && V_137 . V_126 >= ( * V_157 ) -> V_130 && V_137 . V_126 < ( * V_157 ) -> V_131 )
return;
V_137 . V_103 = V_103 ;
V_137 . V_125 = NULL ;
if ( V_137 . V_122 )
V_137 . V_125 = F_32 ( V_137 . V_122 , V_137 . V_126 ) ;
if ( ! V_137 . V_125 )
return;
if ( V_137 . V_126 < V_137 . V_125 -> V_131 )
V_158 = V_137 . V_126 - V_137 . V_125 -> V_130 ;
else
V_158 = V_137 . V_126 - V_137 . V_122 -> V_130 - V_137 . V_125 -> V_130 ;
printf ( L_63 , V_137 . V_125 -> V_160 ) ;
if ( V_158 )
printf ( L_64 , V_158 ) ;
putchar ( ':' ) ;
if ( F_13 ( V_47 ) )
F_43 ( V_137 . V_122 , V_137 . V_126 , L_65 , stdout ) ;
putchar ( '\n' ) ;
* V_157 = V_137 . V_125 ;
}
static void F_44 ( struct V_86 * V_87 ,
struct V_96 * V_96 ,
struct V_18 * V_19 ,
struct V_132 * V_132 )
{
struct V_112 * V_108 = V_87 -> V_112 ;
T_1 V_130 , V_131 ;
int V_9 , V_155 , V_136 , V_118 , V_161 ;
struct V_152 V_153 ;
T_3 V_129 [ V_142 ] ;
unsigned V_158 ;
struct V_156 * V_157 = NULL ;
if ( ! ( V_108 && V_108 -> V_118 ) )
return;
V_118 = V_108 -> V_118 ;
if ( V_162 && V_118 > V_162 + 1 )
V_118 = V_162 + 1 ;
V_153 . V_96 = V_96 ;
V_153 . V_103 = V_87 -> V_103 ;
putchar ( '\n' ) ;
V_136 = F_36 ( V_129 , V_108 -> V_119 [ V_118 - 1 ] . V_116 ,
V_108 -> V_119 [ V_118 - 1 ] . V_116 ,
V_132 , V_96 , & V_153 . V_133 , & V_153 . V_120 , false ) ;
if ( V_136 > 0 ) {
F_42 ( V_96 , V_153 . V_120 , V_153 . V_103 ,
V_108 -> V_119 [ V_118 - 1 ] . V_116 , & V_157 , V_19 ) ;
F_40 ( V_108 -> V_119 [ V_118 - 1 ] . V_116 , & V_108 -> V_119 [ V_118 - 1 ] ,
& V_153 , V_129 , V_136 , 0 ) ;
}
for ( V_9 = V_118 - 2 ; V_9 >= 0 ; V_9 -- ) {
if ( V_108 -> V_119 [ V_9 ] . V_116 || V_108 -> V_119 [ V_9 ] . V_117 )
F_9 ( L_66 V_95 L_46 V_95 L_53 , V_9 ,
V_108 -> V_119 [ V_9 ] . V_116 ,
V_108 -> V_119 [ V_9 ] . V_117 ) ;
V_130 = V_108 -> V_119 [ V_9 + 1 ] . V_117 ;
V_131 = V_108 -> V_119 [ V_9 ] . V_116 ;
V_136 = F_36 ( V_129 , V_130 , V_131 , V_132 , V_96 , & V_153 . V_133 , & V_153 . V_120 , false ) ;
if ( V_136 == - V_141 && V_9 > 0 ) {
V_131 = V_108 -> V_119 [ -- V_9 ] . V_116 ;
F_9 ( L_67 V_95 L_46 V_95 L_53 , V_130 , V_131 ) ;
V_136 = F_36 ( V_129 , V_130 , V_131 , V_132 , V_96 , & V_153 . V_133 , & V_153 . V_120 , false ) ;
}
if ( V_136 <= 0 )
continue;
V_155 = 0 ;
for ( V_158 = 0 ; ; V_158 += V_161 ) {
T_2 V_150 = V_130 + V_158 ;
F_42 ( V_96 , V_153 . V_120 , V_153 . V_103 , V_150 , & V_157 , V_19 ) ;
if ( V_150 == V_131 ) {
F_40 ( V_150 , & V_108 -> V_119 [ V_9 ] , & V_153 , V_129 + V_158 , V_136 - V_158 , V_155 ) ;
break;
} else {
printf ( L_55 V_95 L_68 , V_150 ,
F_41 ( & V_153 , V_150 , V_129 + V_158 , V_136 - V_158 , & V_161 ) ) ;
if ( V_161 == 0 )
break;
V_155 ++ ;
}
}
}
if ( V_108 -> V_119 [ 0 ] . V_116 == V_87 -> V_150 )
return;
if ( V_108 -> V_119 [ 0 ] . V_109 . abort )
return;
V_130 = V_108 -> V_119 [ 0 ] . V_117 ;
V_131 = V_87 -> V_150 ;
V_136 = F_36 ( V_129 , V_130 , V_131 , V_132 , V_96 , & V_153 . V_133 , & V_153 . V_120 , true ) ;
F_42 ( V_96 , V_153 . V_120 , V_153 . V_103 , V_130 , & V_157 , V_19 ) ;
if ( V_136 <= 0 ) {
V_136 = F_36 ( V_129 , V_87 -> V_150 , V_87 -> V_150 ,
V_132 , V_96 , & V_153 . V_133 , & V_153 . V_120 , false ) ;
if ( V_136 <= 0 )
return;
printf ( L_55 V_95 L_68 , V_87 -> V_150 ,
F_41 ( & V_153 , V_87 -> V_150 , V_129 , V_136 , NULL ) ) ;
return;
}
for ( V_158 = 0 ; V_158 <= V_131 - V_130 ; V_158 += V_161 ) {
printf ( L_55 V_95 L_68 , V_130 + V_158 ,
F_41 ( & V_153 , V_130 + V_158 , V_129 + V_158 , V_136 - V_158 , & V_161 ) ) ;
if ( V_161 == 0 )
break;
}
}
static void F_45 ( struct V_86 * V_87 ,
struct V_96 * V_96 ,
struct V_18 * V_19 )
{
struct V_113 V_137 ;
printf ( L_69 V_95 , V_87 -> V_126 ) ;
if ( ! F_46 ( V_19 ) )
return;
F_47 ( V_96 , & V_137 , V_87 ) ;
if ( F_13 ( V_41 ) ) {
printf ( L_30 ) ;
if ( F_13 ( V_42 ) )
F_33 ( V_137 . V_125 , & V_137 , stdout ) ;
else
F_48 ( V_137 . V_125 , stdout ) ;
}
if ( F_13 ( V_43 ) ) {
printf ( L_70 ) ;
F_30 ( V_137 . V_122 , stdout ) ;
printf ( L_42 ) ;
}
}
static void F_49 ( struct V_86 * V_87 ,
struct V_13 * V_14 ,
struct V_96 * V_96 ,
struct V_113 * V_137 )
{
struct V_18 * V_19 = & V_14 -> V_19 ;
T_4 V_163 = F_50 ( V_96 ) ;
struct V_113 V_164 ;
const char * V_160 = NULL ;
static int V_165 ;
int V_136 = 0 ;
T_1 V_150 = 0 ;
if ( V_96 -> V_166 && V_87 -> V_109 & V_167 )
V_163 += 1 ;
if ( V_87 -> V_109 & ( V_168 | V_169 ) ) {
if ( F_46 ( V_19 ) ) {
F_47 ( V_96 , & V_164 , V_87 ) ;
if ( V_164 . V_125 )
V_160 = V_164 . V_125 -> V_160 ;
else
V_150 = V_87 -> V_126 ;
} else {
V_150 = V_87 -> V_126 ;
}
} else if ( V_87 -> V_109 & ( V_167 | V_170 ) ) {
if ( V_137 -> V_125 )
V_160 = V_137 -> V_125 -> V_160 ;
else
V_150 = V_87 -> V_150 ;
}
if ( V_160 )
V_136 = printf ( L_71 , ( int ) V_163 * 4 , L_1 , V_160 ) ;
else if ( V_150 )
V_136 = printf ( L_72 V_95 , ( int ) V_163 * 4 , L_1 , V_150 ) ;
if ( V_136 < 0 )
return;
if ( V_136 > V_165 || ( V_136 && V_136 < V_165 - 52 ) )
V_165 = F_51 ( V_136 + 4 , 32 ) ;
if ( V_136 < V_165 )
printf ( L_73 , V_165 - V_136 , L_1 ) ;
}
static void F_52 ( struct V_86 * V_87 ,
struct V_18 * V_19 ,
struct V_96 * V_96 ,
struct V_132 * V_132 )
{
if ( F_13 ( V_171 ) )
printf ( L_74 , V_87 -> V_172 ) ;
if ( F_13 ( V_173 ) ) {
int V_9 ;
printf ( L_75 ) ;
for ( V_9 = 0 ; V_9 < V_87 -> V_172 ; V_9 ++ )
printf ( L_76 , ( unsigned char ) V_87 -> V_155 [ V_9 ] ) ;
}
if ( F_13 ( V_48 ) )
F_44 ( V_87 , V_96 , V_19 , V_132 ) ;
}
static void F_53 ( struct V_86 * V_87 ,
struct V_13 * V_14 ,
struct V_96 * V_96 ,
struct V_113 * V_137 ,
struct V_132 * V_132 )
{
struct V_18 * V_19 = & V_14 -> V_19 ;
unsigned int type = F_1 ( V_19 -> type ) ;
bool V_174 = false ;
if ( F_13 ( V_175 ) )
F_49 ( V_87 , V_14 , V_96 , V_137 ) ;
if ( F_13 ( V_29 ) ) {
unsigned int V_176 = V_5 [ type ] . V_70 ;
struct V_177 * V_178 = NULL ;
if ( V_81 . V_78 && V_87 -> V_179 &&
F_54 ( V_137 -> V_96 , & V_177 , V_14 ,
V_87 , NULL , NULL , V_180 ) == 0 )
V_178 = & V_177 ;
if ( V_178 == NULL ) {
putchar ( ' ' ) ;
if ( V_176 & V_75 ) {
V_174 = true ;
V_176 &= ~ V_75 ;
}
} else
putchar ( '\n' ) ;
F_55 ( V_87 , V_137 , 0 , V_176 , V_178 , stdout ) ;
}
if ( F_13 ( V_32 ) ||
( ( V_14 -> V_19 . V_15 & V_33 ) &&
! V_5 [ type ] . V_6 ) ) {
printf ( L_77 ) ;
F_45 ( V_87 , V_96 , V_19 ) ;
}
if ( V_174 )
F_43 ( V_137 -> V_122 , V_137 -> V_126 , L_78 , stdout ) ;
F_52 ( V_87 , V_19 , V_96 , V_132 ) ;
printf ( L_53 ) ;
}
static void F_56 ( T_5 V_109 )
{
const char * V_181 = V_182 ;
const int V_183 = strlen ( V_182 ) ;
bool V_123 = V_109 & V_184 ;
const char * V_160 = NULL ;
char V_12 [ 33 ] ;
int V_9 , V_185 = 0 ;
for ( V_9 = 0 ; V_186 [ V_9 ] . V_160 ; V_9 ++ ) {
if ( V_186 [ V_9 ] . V_109 == ( V_109 & ~ V_184 ) ) {
V_160 = V_186 [ V_9 ] . V_160 ;
break;
}
}
for ( V_9 = 0 ; V_9 < V_183 ; V_9 ++ , V_109 >>= 1 ) {
if ( V_109 & 1 )
V_12 [ V_185 ++ ] = V_181 [ V_9 ] ;
}
for (; V_9 < 32 ; V_9 ++ , V_109 >>= 1 ) {
if ( V_109 & 1 )
V_12 [ V_185 ++ ] = '?' ;
}
V_12 [ V_185 ] = 0 ;
if ( V_160 )
printf ( L_79 , V_160 , V_123 ? L_80 : L_1 ) ;
else
printf ( L_81 , V_12 ) ;
}
static void
F_57 ( enum V_187 V_188 ,
unsigned int V_94 ,
void * V_189 )
{
unsigned char V_190 = ( unsigned char ) V_94 ;
struct V_191 * V_191 = V_189 ;
switch ( V_188 ) {
case V_192 :
printf ( L_53 ) ;
break;
case V_193 :
printf ( L_82 , ! V_191 -> V_194 ? L_83 :
L_84 ) ;
break;
case V_195 :
printf ( L_85 , V_94 ) ;
break;
case V_196 :
printf ( L_76 , V_94 ) ;
break;
case V_197 :
printf ( L_86 ) ;
break;
case V_198 :
printf ( L_87 ) ;
break;
case V_199 :
if ( V_191 -> V_200 && V_190 )
V_191 -> V_201 = false ;
if ( ! isprint ( V_190 ) ) {
printf ( L_88 , '.' ) ;
if ( ! V_191 -> V_201 )
break;
if ( V_190 == '\0' )
V_191 -> V_200 = true ;
else
V_191 -> V_201 = false ;
} else {
printf ( L_88 , V_190 ) ;
}
break;
case V_202 :
printf ( L_30 ) ;
break;
case V_203 :
printf ( L_53 ) ;
V_191 -> V_194 ++ ;
break;
case V_204 :
default:
break;
}
}
static void F_58 ( struct V_86 * V_87 )
{
unsigned int V_205 = V_87 -> V_206 ;
struct V_191 V_191 = { 0 , false , true } ;
F_59 ( V_87 -> V_207 , V_205 , 8 ,
F_57 , & V_191 ) ;
if ( V_191 . V_201 && V_191 . V_200 )
printf ( L_89 , L_90 ,
( char * ) ( V_87 -> V_207 ) ) ;
}
static void F_60 ( int V_136 , int V_165 )
{
if ( V_136 > 0 && V_136 < V_165 )
printf ( L_73 , V_165 - V_136 , L_1 ) ;
}
static void F_61 ( int V_136 )
{
F_60 ( V_136 , 34 ) ;
}
static void F_62 ( struct V_86 * V_87 )
{
struct V_208 * V_145 = F_63 ( V_87 ) ;
int V_136 ;
if ( F_64 ( V_87 , * V_145 ) )
return;
V_136 = printf ( L_91 V_95 L_30 ,
V_145 -> V_150 , F_65 ( V_145 -> V_209 ) ) ;
F_61 ( V_136 ) ;
}
static void F_66 ( struct V_86 * V_87 )
{
struct V_210 * V_145 = F_63 ( V_87 ) ;
int V_136 ;
if ( F_64 ( V_87 , * V_145 ) )
return;
V_136 = printf ( L_92 ,
V_145 -> V_211 , V_145 -> V_212 ) ;
F_61 ( V_136 ) ;
}
static void F_67 ( struct V_86 * V_87 )
{
struct V_213 * V_145 = F_63 ( V_87 ) ;
int V_136 ;
if ( F_64 ( V_87 , * V_145 ) )
return;
V_136 = printf ( L_93 ,
V_145 -> V_214 , V_145 -> V_215 , V_145 -> V_216 ) ;
F_61 ( V_136 ) ;
}
static void F_68 ( struct V_86 * V_87 )
{
struct V_217 * V_145 = F_63 ( V_87 ) ;
int V_136 ;
if ( F_64 ( V_87 , * V_145 ) )
return;
V_136 = printf ( L_94 , V_145 -> V_150 ) ;
F_61 ( V_136 ) ;
}
static void F_69 ( struct V_86 * V_87 )
{
struct V_218 * V_145 = F_63 ( V_87 ) ;
int V_136 ;
if ( F_64 ( V_87 , * V_145 ) )
return;
V_136 = printf ( L_95 ,
V_145 -> V_219 , V_145 -> V_220 ,
V_145 -> V_221 ) ;
F_61 ( V_136 ) ;
}
static void F_70 ( struct V_86 * V_87 )
{
struct V_222 * V_145 = F_63 ( V_87 ) ;
unsigned int V_223 , V_224 ;
int V_136 ;
if ( F_64 ( V_87 , * V_145 ) )
return;
V_224 = ( F_71 ( V_145 -> V_224 ) + 500 ) / 1000 ;
V_136 = printf ( L_96 , V_145 -> V_225 , V_224 ) ;
if ( V_145 -> V_226 ) {
V_223 = ( 5 + ( 1000 * V_145 -> V_225 ) / V_145 -> V_226 ) / 10 ;
V_136 += printf ( L_97 , V_223 ) ;
}
F_61 ( V_136 ) ;
}
static void F_72 ( struct V_86 * V_87 ,
struct V_13 * V_14 )
{
switch ( V_14 -> V_19 . V_227 ) {
case V_228 :
F_62 ( V_87 ) ;
break;
case V_229 :
F_66 ( V_87 ) ;
break;
case V_230 :
F_67 ( V_87 ) ;
break;
case V_231 :
F_68 ( V_87 ) ;
break;
case V_232 :
F_69 ( V_87 ) ;
break;
case V_233 :
F_70 ( V_87 ) ;
break;
default:
break;
}
}
static int F_73 ( struct V_234 * V_49 )
{
struct V_13 * V_14 ;
int V_235 = 0 ;
F_20 (evlist, evsel) {
int V_136 = strlen ( F_7 ( V_14 ) ) ;
V_235 = F_74 ( V_136 , V_235 ) ;
}
return V_235 ;
}
static T_4 F_75 ( T_1 V_236 )
{
struct V_237 V_238 = { . V_236 . V_94 = V_236 } ;
char V_239 [ 100 ] ;
char V_85 [ 100 ] ;
static int V_240 ;
int V_136 ;
F_76 ( V_239 , 100 , & V_238 ) ;
V_136 = F_77 ( V_85 , 100 , L_69 V_95 L_98 , V_236 , V_239 ) ;
if ( V_240 < V_136 )
V_240 = V_136 ;
return printf ( L_99 , V_240 , V_85 ) ;
}
static void F_78 ( struct V_241 * V_242 ,
struct V_86 * V_87 , struct V_13 * V_14 ,
struct V_113 * V_137 ,
struct V_132 * V_132 )
{
struct V_96 * V_96 = V_137 -> V_96 ;
struct V_18 * V_19 = & V_14 -> V_19 ;
unsigned int type = F_1 ( V_19 -> type ) ;
if ( V_5 [ type ] . V_21 == 0 )
return;
F_24 ( V_87 , V_96 , V_14 ) ;
if ( F_13 ( V_61 ) )
printf ( L_100 V_144 L_30 , V_87 -> V_243 ) ;
if ( F_13 ( V_244 ) ) {
const char * V_20 = F_7 ( V_14 ) ;
if ( ! V_242 -> V_245 )
V_242 -> V_245 = F_73 ( V_242 -> V_23 -> V_49 ) ;
printf ( L_101 , V_242 -> V_245 ,
V_20 ? V_20 : L_102 ) ;
}
if ( V_246 )
F_56 ( V_87 -> V_109 ) ;
if ( F_79 ( V_19 ) ) {
F_53 ( V_87 , V_14 , V_96 , V_137 , V_132 ) ;
return;
}
if ( F_13 ( V_27 ) )
F_80 ( V_14 -> V_247 , V_87 -> V_103 ,
V_87 -> V_207 , V_87 -> V_206 ) ;
if ( V_19 -> type == V_1 && F_13 ( V_248 ) )
F_72 ( V_87 , V_14 ) ;
if ( F_13 ( V_32 ) )
F_45 ( V_87 , V_96 , V_19 ) ;
if ( F_13 ( V_35 ) )
F_75 ( V_87 -> V_236 ) ;
if ( F_13 ( V_38 ) )
printf ( L_69 V_144 , V_87 -> V_249 ) ;
if ( F_13 ( V_29 ) ) {
struct V_177 * V_178 = NULL ;
if ( V_81 . V_78 && V_87 -> V_179 &&
F_54 ( V_137 -> V_96 , & V_177 , V_14 ,
V_87 , NULL , NULL , V_180 ) == 0 )
V_178 = & V_177 ;
putchar ( V_178 ? '\n' : ' ' ) ;
F_55 ( V_87 , V_137 , 0 , V_5 [ type ] . V_70 , V_178 , stdout ) ;
}
if ( F_13 ( V_64 ) )
F_21 ( V_87 , V_19 ) ;
if ( F_13 ( V_44 ) )
F_28 ( V_87 , V_96 , V_19 ) ;
else if ( F_13 ( V_45 ) )
F_31 ( V_87 , V_96 , V_19 ) ;
else if ( F_13 ( V_46 ) )
F_34 ( V_87 , V_96 , V_19 ) ;
if ( F_81 ( V_14 ) && F_13 ( V_250 ) )
F_58 ( V_87 ) ;
F_52 ( V_87 , V_19 , V_96 , V_132 ) ;
if ( F_13 ( V_67 ) )
printf ( L_69 V_95 , V_87 -> V_251 ) ;
printf ( L_53 ) ;
}
static void F_82 ( struct V_13 * V_252 , T_1 V_253 )
{
int V_254 = F_83 ( V_252 -> V_255 ) ;
int V_256 = F_84 ( V_252 ) ;
int V_103 , V_96 ;
static int V_257 ;
if ( V_252 -> V_258 )
V_254 = 1 ;
if ( ! V_257 ) {
printf ( L_103 ,
L_23 , L_104 , L_105 , L_106 , L_107 , L_22 , L_108 ) ;
V_257 = 1 ;
}
for ( V_96 = 0 ; V_96 < V_254 ; V_96 ++ ) {
for ( V_103 = 0 ; V_103 < V_256 ; V_103 ++ ) {
struct V_259 * V_260 ;
V_260 = F_85 ( V_252 -> V_260 , V_103 , V_96 ) ;
printf ( L_109 V_144 L_110 V_144 L_110 V_144 L_110 V_144 L_111 ,
V_252 -> V_261 -> V_122 [ V_103 ] ,
F_86 ( V_252 -> V_255 , V_96 ) ,
V_260 -> V_94 ,
V_260 -> V_262 ,
V_260 -> V_263 ,
V_253 ,
F_7 ( V_252 ) ) ;
}
}
}
static void F_87 ( struct V_13 * V_252 , T_1 V_253 )
{
if ( V_264 && V_264 -> F_87 )
V_264 -> F_87 ( & V_265 , V_252 , V_253 ) ;
else
F_82 ( V_252 , V_253 ) ;
}
static void F_88 ( T_1 V_253 )
{
if ( V_264 && V_264 -> F_88 )
V_264 -> F_88 ( V_253 ) ;
}
static void F_89 ( void )
{
F_90 () ;
F_91 () ;
}
static int F_92 ( void )
{
return V_264 ? V_264 -> V_266 () : 0 ;
}
static int F_93 ( void )
{
F_9 ( L_112 ) ;
return V_264 ? V_264 -> V_267 () : 0 ;
}
static int F_94 ( struct V_268 * V_269 ,
union V_270 * V_271 ,
struct V_86 * V_87 ,
struct V_13 * V_14 ,
struct V_132 * V_132 )
{
struct V_241 * V_272 = F_95 ( V_269 , struct V_241 , V_269 ) ;
struct V_113 V_137 ;
if ( F_96 ( & V_272 -> V_273 , V_87 -> time ) )
return 0 ;
if ( V_274 ) {
if ( V_87 -> time < V_275 ) {
F_8 ( L_113 V_144
L_114 V_144 L_53 , V_275 ,
V_87 -> time ) ;
V_276 ++ ;
}
V_275 = V_87 -> time ;
return 0 ;
}
if ( F_97 ( V_132 , & V_137 , V_87 ) < 0 ) {
F_8 ( L_115 ,
V_271 -> V_24 . type ) ;
return - 1 ;
}
if ( V_137 . V_277 )
goto V_278;
if ( V_279 && ! F_98 ( V_87 -> V_103 , V_280 ) )
goto V_278;
if ( V_264 )
V_264 -> F_78 ( V_271 , V_87 , V_14 , & V_137 ) ;
else
F_78 ( V_272 , V_87 , V_14 , & V_137 , V_132 ) ;
V_278:
F_99 ( & V_137 ) ;
return 0 ;
}
static int F_100 ( struct V_268 * V_269 , union V_270 * V_271 ,
struct V_234 * * V_281 )
{
struct V_241 * V_272 = F_95 ( V_269 , struct V_241 , V_269 ) ;
struct V_234 * V_49 ;
struct V_13 * V_14 , * V_185 ;
int V_282 ;
V_282 = F_101 ( V_269 , V_271 , V_281 ) ;
if ( V_282 )
return V_282 ;
V_49 = * V_281 ;
V_14 = F_102 ( * V_281 ) ;
if ( V_14 -> V_19 . type >= V_283 &&
V_14 -> V_19 . type != V_1 )
return 0 ;
F_20 (evlist, pos) {
if ( V_185 -> V_19 . type == V_14 -> V_19 . type && V_185 != V_14 )
return 0 ;
}
F_16 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_19 . V_15 )
V_282 = F_11 ( V_14 , V_272 -> V_23 ) ;
return V_282 ;
}
static int F_103 ( struct V_268 * V_269 ,
union V_270 * V_271 ,
struct V_86 * V_87 ,
struct V_132 * V_132 )
{
struct V_96 * V_96 ;
struct V_241 * V_242 = F_95 ( V_269 , struct V_241 , V_269 ) ;
struct V_22 * V_23 = V_242 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_87 -> V_284 ) ;
int V_285 = - 1 ;
V_96 = F_105 ( V_132 , V_271 -> V_286 . V_101 , V_271 -> V_286 . V_102 ) ;
if ( V_96 == NULL ) {
F_9 ( L_116 ) ;
return - 1 ;
}
if ( F_106 ( V_269 , V_271 , V_87 , V_132 ) < 0 )
goto V_85;
if ( ! V_14 -> V_19 . V_287 ) {
V_87 -> V_103 = 0 ;
V_87 -> time = 0 ;
V_87 -> V_102 = V_271 -> V_286 . V_102 ;
V_87 -> V_101 = V_271 -> V_286 . V_101 ;
}
F_24 ( V_87 , V_96 , V_14 ) ;
F_107 ( V_271 , stdout ) ;
V_285 = 0 ;
V_85:
F_108 ( V_96 ) ;
return V_285 ;
}
static int F_109 ( struct V_268 * V_269 ,
union V_270 * V_271 ,
struct V_86 * V_87 ,
struct V_132 * V_132 )
{
struct V_96 * V_96 ;
struct V_241 * V_242 = F_95 ( V_269 , struct V_241 , V_269 ) ;
struct V_22 * V_23 = V_242 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_87 -> V_284 ) ;
int V_285 = - 1 ;
V_96 = F_105 ( V_132 , V_271 -> V_288 . V_101 ,
V_271 -> V_288 . V_102 ) ;
if ( V_96 == NULL ) {
F_9 ( L_117 ) ;
return - 1 ;
}
if ( F_110 ( V_269 , V_271 , V_87 , V_132 ) < 0 )
goto V_85;
if ( ! V_14 -> V_19 . V_287 ) {
V_87 -> V_103 = 0 ;
V_87 -> time = 0 ;
V_87 -> V_102 = V_271 -> V_288 . V_102 ;
V_87 -> V_101 = V_271 -> V_288 . V_101 ;
}
F_24 ( V_87 , V_96 , V_14 ) ;
F_107 ( V_271 , stdout ) ;
V_285 = 0 ;
V_85:
F_108 ( V_96 ) ;
return V_285 ;
}
static int F_111 ( struct V_268 * V_269 ,
union V_270 * V_271 ,
struct V_86 * V_87 ,
struct V_132 * V_132 )
{
struct V_96 * V_96 ;
struct V_241 * V_242 = F_95 ( V_269 , struct V_241 , V_269 ) ;
struct V_22 * V_23 = V_242 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_87 -> V_284 ) ;
if ( F_112 ( V_269 , V_271 , V_87 , V_132 ) < 0 )
return - 1 ;
V_96 = F_105 ( V_132 , V_271 -> V_289 . V_101 , V_271 -> V_289 . V_102 ) ;
if ( V_96 == NULL ) {
F_9 ( L_118 ) ;
return - 1 ;
}
if ( ! V_14 -> V_19 . V_287 ) {
V_87 -> V_103 = 0 ;
V_87 -> time = V_271 -> V_289 . time ;
V_87 -> V_102 = V_271 -> V_289 . V_102 ;
V_87 -> V_101 = V_271 -> V_289 . V_101 ;
}
F_24 ( V_87 , V_96 , V_14 ) ;
F_107 ( V_271 , stdout ) ;
F_108 ( V_96 ) ;
return 0 ;
}
static int F_113 ( struct V_268 * V_269 ,
union V_270 * V_271 ,
struct V_86 * V_87 ,
struct V_132 * V_132 )
{
int V_282 = 0 ;
struct V_96 * V_96 ;
struct V_241 * V_242 = F_95 ( V_269 , struct V_241 , V_269 ) ;
struct V_22 * V_23 = V_242 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_87 -> V_284 ) ;
V_96 = F_105 ( V_132 , V_271 -> V_289 . V_101 , V_271 -> V_289 . V_102 ) ;
if ( V_96 == NULL ) {
F_9 ( L_119 ) ;
return - 1 ;
}
if ( ! V_14 -> V_19 . V_287 ) {
V_87 -> V_103 = 0 ;
V_87 -> time = 0 ;
V_87 -> V_102 = V_271 -> V_289 . V_102 ;
V_87 -> V_101 = V_271 -> V_289 . V_101 ;
}
F_24 ( V_87 , V_96 , V_14 ) ;
F_107 ( V_271 , stdout ) ;
if ( F_114 ( V_269 , V_271 , V_87 , V_132 ) < 0 )
V_282 = - 1 ;
F_108 ( V_96 ) ;
return V_282 ;
}
static int F_115 ( struct V_268 * V_269 ,
union V_270 * V_271 ,
struct V_86 * V_87 ,
struct V_132 * V_132 )
{
struct V_96 * V_96 ;
struct V_241 * V_242 = F_95 ( V_269 , struct V_241 , V_269 ) ;
struct V_22 * V_23 = V_242 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_87 -> V_284 ) ;
if ( F_116 ( V_269 , V_271 , V_87 , V_132 ) < 0 )
return - 1 ;
V_96 = F_105 ( V_132 , V_271 -> V_290 . V_101 , V_271 -> V_290 . V_102 ) ;
if ( V_96 == NULL ) {
F_9 ( L_120 ) ;
return - 1 ;
}
if ( ! V_14 -> V_19 . V_287 ) {
V_87 -> V_103 = 0 ;
V_87 -> time = 0 ;
V_87 -> V_102 = V_271 -> V_290 . V_102 ;
V_87 -> V_101 = V_271 -> V_290 . V_101 ;
}
F_24 ( V_87 , V_96 , V_14 ) ;
F_107 ( V_271 , stdout ) ;
F_108 ( V_96 ) ;
return 0 ;
}
static int F_117 ( struct V_268 * V_269 ,
union V_270 * V_271 ,
struct V_86 * V_87 ,
struct V_132 * V_132 )
{
struct V_96 * V_96 ;
struct V_241 * V_242 = F_95 ( V_269 , struct V_241 , V_269 ) ;
struct V_22 * V_23 = V_242 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_87 -> V_284 ) ;
if ( F_118 ( V_269 , V_271 , V_87 , V_132 ) < 0 )
return - 1 ;
V_96 = F_105 ( V_132 , V_271 -> V_291 . V_101 , V_271 -> V_291 . V_102 ) ;
if ( V_96 == NULL ) {
F_9 ( L_121 ) ;
return - 1 ;
}
if ( ! V_14 -> V_19 . V_287 ) {
V_87 -> V_103 = 0 ;
V_87 -> time = 0 ;
V_87 -> V_102 = V_271 -> V_291 . V_102 ;
V_87 -> V_101 = V_271 -> V_291 . V_101 ;
}
F_24 ( V_87 , V_96 , V_14 ) ;
F_107 ( V_271 , stdout ) ;
F_108 ( V_96 ) ;
return 0 ;
}
static int F_119 ( struct V_268 * V_269 ,
union V_270 * V_271 ,
struct V_86 * V_87 ,
struct V_132 * V_132 )
{
struct V_96 * V_96 ;
struct V_241 * V_242 = F_95 ( V_269 , struct V_241 , V_269 ) ;
struct V_22 * V_23 = V_242 -> V_23 ;
struct V_13 * V_14 = F_104 ( V_23 -> V_49 , V_87 -> V_284 ) ;
if ( F_120 ( V_269 , V_271 , V_87 , V_132 ) < 0 )
return - 1 ;
V_96 = F_105 ( V_132 , V_87 -> V_101 ,
V_87 -> V_102 ) ;
if ( V_96 == NULL ) {
F_9 ( L_122 ) ;
return - 1 ;
}
F_24 ( V_87 , V_96 , V_14 ) ;
F_107 ( V_271 , stdout ) ;
F_108 ( V_96 ) ;
return 0 ;
}
static void F_121 ( int T_6 V_292 )
{
V_293 = 1 ;
}
static int F_122 ( struct V_241 * V_242 )
{
int V_285 ;
signal ( V_294 , F_121 ) ;
if ( V_242 -> V_295 ) {
V_242 -> V_269 . V_286 = F_103 ;
V_242 -> V_269 . V_289 = F_111 ;
V_242 -> V_269 . exit = F_113 ;
}
if ( V_242 -> V_296 ) {
V_242 -> V_269 . V_290 = F_115 ;
V_242 -> V_269 . V_291 = F_117 ;
}
if ( V_242 -> V_297 )
V_242 -> V_269 . V_298 = F_119 ;
if ( V_242 -> V_299 )
V_242 -> V_269 . V_288 = F_109 ;
V_285 = F_123 ( V_242 -> V_23 ) ;
if ( V_274 )
F_8 ( L_123 V_144 L_53 , V_276 ) ;
return V_285 ;
}
static struct V_300 * F_124 ( const char * V_301 ,
struct V_264 * V_302 )
{
struct V_300 * V_303 = malloc ( sizeof( * V_303 ) + strlen ( V_301 ) + 1 ) ;
if ( V_303 != NULL ) {
strcpy ( V_303 -> V_301 , V_301 ) ;
V_303 -> V_302 = V_302 ;
}
return V_303 ;
}
static void F_125 ( struct V_300 * V_303 )
{
F_126 ( & V_303 -> V_304 , & V_305 ) ;
}
static struct V_300 * F_127 ( const char * V_301 )
{
struct V_300 * V_303 ;
F_128 (s, &script_specs, node)
if ( strcasecmp ( V_303 -> V_301 , V_301 ) == 0 )
return V_303 ;
return NULL ;
}
int F_129 ( const char * V_301 , struct V_264 * V_302 )
{
struct V_300 * V_303 ;
V_303 = F_127 ( V_301 ) ;
if ( V_303 )
return - 1 ;
V_303 = F_124 ( V_301 , V_302 ) ;
if ( ! V_303 )
return - 1 ;
else
F_125 ( V_303 ) ;
return 0 ;
}
static struct V_264 * F_130 ( const char * V_301 )
{
struct V_300 * V_303 = F_127 ( V_301 ) ;
if ( ! V_303 )
return NULL ;
return V_303 -> V_302 ;
}
static void F_131 ( void )
{
struct V_300 * V_303 ;
fprintf ( V_306 , L_53 ) ;
fprintf ( V_306 , L_124
L_125 ) ;
F_128 (s, &script_specs, node)
fprintf ( V_306 , L_126 , V_303 -> V_301 , V_303 -> V_302 -> V_160 ) ;
fprintf ( V_306 , L_53 ) ;
}
static int F_132 ( const struct V_307 * T_7 V_292 ,
const char * V_12 , int T_8 V_292 )
{
char V_301 [ V_308 ] ;
const char * V_242 , * V_309 ;
int V_136 ;
if ( strcmp ( V_12 , L_127 ) == 0 ) {
F_131 () ;
exit ( 0 ) ;
}
V_242 = strchr ( V_12 , ':' ) ;
if ( V_242 ) {
V_136 = V_242 - V_12 ;
if ( V_136 >= V_308 ) {
fprintf ( V_306 , L_128 ) ;
return - 1 ;
}
strncpy ( V_301 , V_12 , V_136 ) ;
V_301 [ V_136 ] = '\0' ;
V_264 = F_130 ( V_301 ) ;
if ( ! V_264 ) {
fprintf ( V_306 , L_128 ) ;
return - 1 ;
}
V_242 ++ ;
} else {
V_242 = V_12 ;
V_309 = strrchr ( V_242 , '.' ) ;
if ( ! V_309 ) {
fprintf ( V_306 , L_129 ) ;
return - 1 ;
}
V_264 = F_130 ( ++ V_309 ) ;
if ( ! V_264 ) {
fprintf ( V_306 , L_129 ) ;
return - 1 ;
}
}
V_310 = F_133 ( V_242 ) ;
return 0 ;
}
static int F_134 ( const struct V_307 * T_7 V_292 ,
const char * V_311 , int T_8 V_292 )
{
char * V_312 , * V_313 = NULL ;
int V_9 , V_10 = F_5 ( V_11 ) ;
int V_3 ;
int V_314 = 0 ;
char * V_12 = F_133 ( V_311 ) ;
int type = - 1 ;
enum { DEFAULT , V_315 , V_316 , REMOVE } V_317 = DEFAULT ;
if ( ! V_12 )
return - V_318 ;
V_312 = strchr ( V_12 , ':' ) ;
if ( V_312 ) {
* V_312 = '\0' ;
V_312 ++ ;
if ( ! strcmp ( V_12 , L_130 ) )
type = V_319 ;
else if ( ! strcmp ( V_12 , L_131 ) )
type = V_320 ;
else if ( ! strcmp ( V_12 , L_132 ) )
type = V_82 ;
else if ( ! strcmp ( V_12 , L_133 ) )
type = V_321 ;
else if ( ! strcmp ( V_12 , L_134 ) )
type = V_322 ;
else if ( ! strcmp ( V_12 , L_135 ) )
type = V_2 ;
else {
fprintf ( V_306 , L_136 ) ;
V_314 = - V_28 ;
goto V_85;
}
if ( V_5 [ type ] . V_6 )
F_135 ( L_137 ,
F_19 ( type ) ) ;
V_5 [ type ] . V_21 = 0 ;
V_5 [ type ] . V_6 = true ;
V_5 [ type ] . V_76 = false ;
} else {
V_312 = V_12 ;
if ( strlen ( V_12 ) == 0 ) {
fprintf ( V_306 ,
L_138 ) ;
V_314 = - V_28 ;
goto V_85;
}
if ( strchr ( V_12 , '+' ) || strchr ( V_12 , '-' ) )
goto V_323;
if ( F_3 () )
F_135 ( L_139 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
V_5 [ V_3 ] . V_21 = 0 ;
V_5 [ V_3 ] . V_6 = true ;
V_5 [ V_3 ] . V_76 = true ;
}
}
V_323:
for ( V_312 = strtok_r ( V_312 , L_140 , & V_313 ) ; V_312 ; V_312 = strtok_r ( NULL , L_140 , & V_313 ) ) {
if ( * V_312 == '+' ) {
if ( V_317 == V_315 )
goto V_324;
V_317 = V_316 ;
V_312 ++ ;
} else if ( * V_312 == '-' ) {
if ( V_317 == V_315 )
goto V_324;
V_317 = REMOVE ;
V_312 ++ ;
} else {
if ( V_317 != V_315 && V_317 != DEFAULT )
goto V_324;
V_317 = V_315 ;
}
for ( V_9 = 0 ; V_9 < V_10 ; ++ V_9 ) {
if ( strcmp ( V_312 , V_11 [ V_9 ] . V_12 ) == 0 )
break;
}
if ( V_9 == V_10 && strcmp ( V_312 , L_141 ) == 0 ) {
V_246 = V_317 == REMOVE ? false : true ;
continue;
}
if ( V_9 == V_10 ) {
fprintf ( V_306 , L_142 ) ;
V_314 = - V_28 ;
goto V_85;
}
if ( type == - 1 ) {
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( V_5 [ V_3 ] . V_325 & V_11 [ V_9 ] . V_8 ) {
F_135 ( L_143 ,
V_11 [ V_9 ] . V_12 , F_19 ( V_3 ) ) ;
} else {
if ( V_317 == REMOVE )
V_5 [ V_3 ] . V_21 &= ~ V_11 [ V_9 ] . V_8 ;
else
V_5 [ V_3 ] . V_21 |= V_11 [ V_9 ] . V_8 ;
}
}
} else {
if ( V_5 [ type ] . V_325 & V_11 [ V_9 ] . V_8 ) {
fprintf ( V_306 , L_144 ,
V_11 [ V_9 ] . V_12 , F_19 ( type ) ) ;
V_314 = - V_28 ;
goto V_85;
}
V_5 [ type ] . V_21 |= V_11 [ V_9 ] . V_8 ;
}
}
if ( type >= 0 ) {
if ( V_5 [ type ] . V_21 == 0 ) {
F_9 ( L_145
L_146 , F_19 ( type ) ) ;
}
}
goto V_85;
V_324:
fprintf ( V_306 , L_147 ) ;
V_314 = - V_28 ;
V_85:
free ( V_12 ) ;
return V_314 ;
}
static int F_136 ( const char * V_326 , const struct V_327 * V_328 )
{
char V_329 [ V_308 ] ;
struct V_330 V_331 ;
sprintf ( V_329 , L_148 , V_326 , V_328 -> V_332 ) ;
if ( V_330 ( V_329 , & V_331 ) )
return 0 ;
return F_137 ( V_331 . V_333 ) ;
}
static struct V_334 * F_138 ( const char * V_160 )
{
struct V_334 * V_303 = F_139 ( sizeof( * V_303 ) ) ;
if ( V_303 != NULL && V_160 )
V_303 -> V_160 = F_133 ( V_160 ) ;
return V_303 ;
}
static void F_140 ( struct V_334 * V_303 )
{
F_141 ( & V_303 -> V_160 ) ;
F_141 ( & V_303 -> V_335 ) ;
F_141 ( & V_303 -> args ) ;
free ( V_303 ) ;
}
static void F_142 ( struct V_334 * V_303 )
{
F_126 ( & V_303 -> V_304 , & V_336 ) ;
}
static struct V_334 * F_143 ( const char * V_160 )
{
struct V_334 * V_303 ;
F_128 (s, &script_descs, node)
if ( strcasecmp ( V_303 -> V_160 , V_160 ) == 0 )
return V_303 ;
return NULL ;
}
static struct V_334 * F_144 ( const char * V_160 )
{
struct V_334 * V_303 = F_143 ( V_160 ) ;
if ( V_303 )
return V_303 ;
V_303 = F_138 ( V_160 ) ;
if ( ! V_303 )
return NULL ;
F_142 ( V_303 ) ;
return V_303 ;
}
static const char * F_145 ( const char * V_12 , const char * V_337 )
{
T_4 V_338 = strlen ( V_337 ) ;
const char * V_339 = V_12 ;
if ( strlen ( V_12 ) > V_338 ) {
V_339 = V_12 + strlen ( V_12 ) - V_338 ;
if ( ! strncmp ( V_339 , V_337 , V_338 ) )
return V_339 ;
}
return NULL ;
}
static int F_146 ( struct V_334 * V_340 , const char * V_341 )
{
char line [ V_342 ] , * V_339 ;
T_9 * V_343 ;
V_343 = fopen ( V_341 , L_149 ) ;
if ( ! V_343 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_343 ) ) {
V_339 = F_147 ( line ) ;
if ( strlen ( V_339 ) == 0 )
continue;
if ( * V_339 != '#' )
continue;
V_339 ++ ;
if ( strlen ( V_339 ) && * V_339 == '!' )
continue;
V_339 = F_147 ( V_339 ) ;
if ( strlen ( V_339 ) && V_339 [ strlen ( V_339 ) - 1 ] == '\n' )
V_339 [ strlen ( V_339 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_339 , L_150 , strlen ( L_150 ) ) ) {
V_339 += strlen ( L_150 ) ;
V_340 -> V_335 = F_133 ( F_147 ( V_339 ) ) ;
continue;
}
if ( ! strncmp ( V_339 , L_151 , strlen ( L_151 ) ) ) {
V_339 += strlen ( L_151 ) ;
V_340 -> args = F_133 ( F_147 ( V_339 ) ) ;
continue;
}
}
fclose ( V_343 ) ;
return 0 ;
}
static char * F_148 ( struct V_327 * V_344 , const char * V_337 )
{
char * V_345 , * V_12 ;
V_345 = F_133 ( V_344 -> V_332 ) ;
if ( ! V_345 )
return NULL ;
V_12 = ( char * ) F_145 ( V_345 , V_337 ) ;
if ( ! V_12 ) {
free ( V_345 ) ;
return NULL ;
}
* V_12 = '\0' ;
return V_345 ;
}
static int F_149 ( const struct V_307 * T_7 V_292 ,
const char * V_303 V_292 ,
int T_8 V_292 )
{
struct V_327 * V_344 , * V_346 ;
char V_347 [ V_348 ] ;
T_10 * V_349 , * V_350 ;
char V_351 [ V_348 ] ;
char V_352 [ V_348 ] ;
struct V_334 * V_340 ;
char V_353 [ V_342 ] ;
char * V_345 ;
snprintf ( V_347 , V_348 , L_152 , F_150 () ) ;
V_349 = F_151 ( V_347 ) ;
if ( ! V_349 ) {
fprintf ( stdout ,
L_153
L_154 ,
V_347 ) ;
exit ( - 1 ) ;
}
F_152 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_352 , V_348 , L_155 , V_347 ,
V_346 -> V_332 ) ;
V_350 = F_151 ( V_352 ) ;
if ( ! V_350 )
continue;
F_153 (lang_path, lang_dir, script_dirent) {
V_345 = F_148 ( V_344 , V_354 ) ;
if ( V_345 ) {
V_340 = F_144 ( V_345 ) ;
snprintf ( V_351 , V_348 , L_148 ,
V_352 , V_344 -> V_332 ) ;
F_146 ( V_340 , V_351 ) ;
free ( V_345 ) ;
}
}
}
fprintf ( stdout , L_156 ) ;
F_128 (desc, &script_descs, node) {
sprintf ( V_353 , L_157 , V_340 -> V_160 ,
V_340 -> args ? V_340 -> args : L_1 ) ;
fprintf ( stdout , L_158 , V_353 ,
V_340 -> V_335 ? V_340 -> V_335 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_154 ( char * V_355 , char * V_356 ,
struct V_22 * V_23 )
{
char V_341 [ V_348 ] , V_20 [ 128 ] ;
char line [ V_342 ] , * V_339 ;
struct V_13 * V_185 ;
int V_357 , V_136 ;
T_9 * V_343 ;
sprintf ( V_341 , L_159 , V_355 , V_356 ) ;
V_343 = fopen ( V_341 , L_149 ) ;
if ( ! V_343 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_343 ) ) {
V_339 = F_147 ( line ) ;
if ( * V_339 == '#' )
continue;
while ( strlen ( V_339 ) ) {
V_339 = strstr ( V_339 , L_160 ) ;
if ( ! V_339 )
break;
V_339 += 2 ;
V_339 = F_147 ( V_339 ) ;
V_136 = strcspn ( V_339 , L_161 ) ;
if ( ! V_136 )
break;
snprintf ( V_20 , V_136 + 1 , L_162 , V_339 ) ;
V_357 = 0 ;
F_20 (session->evlist, pos) {
if ( ! strcmp ( F_7 ( V_185 ) , V_20 ) ) {
V_357 = 1 ;
break;
}
}
if ( ! V_357 ) {
fclose ( V_343 ) ;
return - 1 ;
}
}
}
fclose ( V_343 ) ;
return 0 ;
}
int F_155 ( char * * V_358 , char * * V_359 )
{
struct V_327 * V_344 , * V_346 ;
char V_347 [ V_348 ] , V_352 [ V_348 ] ;
T_10 * V_349 , * V_350 ;
struct V_22 * V_23 ;
struct V_360 V_361 = {
. V_329 = V_362 ,
. V_363 = V_364 ,
} ;
char * V_365 ;
int V_9 = 0 ;
V_23 = F_156 ( & V_361 , false , NULL ) ;
if ( ! V_23 )
return - 1 ;
snprintf ( V_347 , V_348 , L_152 , F_150 () ) ;
V_349 = F_151 ( V_347 ) ;
if ( ! V_349 ) {
F_157 ( V_23 ) ;
return - 1 ;
}
F_152 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_352 , V_348 , L_148 , V_347 ,
V_346 -> V_332 ) ;
#ifdef F_158
if ( strstr ( V_352 , L_163 ) )
continue;
#endif
#ifdef F_159
if ( strstr ( V_352 , L_164 ) )
continue;
#endif
V_350 = F_151 ( V_352 ) ;
if ( ! V_350 )
continue;
F_153 (lang_path, lang_dir, script_dirent) {
if ( strstr ( V_344 -> V_332 , L_165 ) )
continue;
sprintf ( V_359 [ V_9 ] , L_148 , V_352 ,
V_344 -> V_332 ) ;
V_365 = strchr ( V_344 -> V_332 , '.' ) ;
snprintf ( V_358 [ V_9 ] ,
( V_365 - V_344 -> V_332 ) + 1 ,
L_162 , V_344 -> V_332 ) ;
if ( F_154 ( V_352 ,
V_358 [ V_9 ] , V_23 ) )
continue;
V_9 ++ ;
}
F_160 ( V_350 ) ;
}
F_160 ( V_349 ) ;
F_157 ( V_23 ) ;
return V_9 ;
}
static char * F_161 ( const char * V_345 , const char * V_337 )
{
struct V_327 * V_344 , * V_346 ;
char V_347 [ V_348 ] ;
char V_351 [ V_348 ] ;
T_10 * V_349 , * V_350 ;
char V_352 [ V_348 ] ;
char * V_366 ;
snprintf ( V_347 , V_348 , L_152 , F_150 () ) ;
V_349 = F_151 ( V_347 ) ;
if ( ! V_349 )
return NULL ;
F_152 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_352 , V_348 , L_155 , V_347 ,
V_346 -> V_332 ) ;
V_350 = F_151 ( V_352 ) ;
if ( ! V_350 )
continue;
F_153 (lang_path, lang_dir, script_dirent) {
V_366 = F_148 ( V_344 , V_337 ) ;
if ( V_366 && ! strcmp ( V_345 , V_366 ) ) {
free ( V_366 ) ;
F_160 ( V_350 ) ;
F_160 ( V_349 ) ;
snprintf ( V_351 , V_348 , L_148 ,
V_352 , V_344 -> V_332 ) ;
return F_133 ( V_351 ) ;
}
free ( V_366 ) ;
}
F_160 ( V_350 ) ;
}
F_160 ( V_349 ) ;
return NULL ;
}
static bool F_162 ( const char * V_351 )
{
return F_145 ( V_351 , L_166 ) == NULL ? false : true ;
}
static int F_163 ( char * V_351 )
{
struct V_334 * V_340 ;
int V_367 = 0 ;
char * V_339 ;
V_340 = F_138 ( NULL ) ;
if ( F_146 ( V_340 , V_351 ) )
goto V_85;
if ( ! V_340 -> args )
goto V_85;
for ( V_339 = V_340 -> args ; * V_339 ; V_339 ++ )
if ( * V_339 == '<' )
V_367 ++ ;
V_85:
F_140 ( V_340 ) ;
return V_367 ;
}
static int F_164 ( int V_368 , const char * * V_369 )
{
char * * V_370 = malloc ( sizeof( const char * ) * V_368 ) ;
if ( ! V_370 ) {
F_8 ( L_167 ) ;
return - 1 ;
}
memcpy ( V_370 , V_369 , sizeof( const char * ) * V_368 ) ;
V_368 = F_165 ( V_368 , ( const char * * ) V_370 , V_371 ,
NULL , V_372 ) ;
free ( V_370 ) ;
V_258 = ( V_368 == 0 ) ;
return 0 ;
}
static void F_166 ( struct V_241 * V_242 )
{
struct V_22 * V_23 = V_242 -> V_23 ;
T_1 V_15 = F_167 ( V_23 -> V_49 ) ;
if ( V_81 . V_78 || V_81 . V_373 ) {
if ( ( V_15 & V_374 ) &&
( V_15 & V_375 ) )
V_376 . V_377 = V_378 ;
else if ( V_15 & V_379 )
V_376 . V_377 = V_380 ;
else
V_376 . V_377 = V_381 ;
}
}
static int F_168 ( struct V_268 * V_269 V_292 ,
union V_270 * V_271 ,
struct V_22 * V_23 )
{
struct V_382 * V_383 = & V_271 -> V_384 ;
struct V_13 * V_252 ;
F_20 (session->evlist, counter) {
F_169 ( & V_265 , V_252 ) ;
F_87 ( V_252 , V_383 -> time ) ;
}
F_88 ( V_383 -> time ) ;
return 0 ;
}
static int F_170 ( struct V_268 * V_269 V_292 ,
union V_270 * V_271 ,
struct V_22 * V_23 V_292 )
{
F_171 ( & V_265 , & V_271 -> V_265 ) ;
return 0 ;
}
static int F_172 ( struct V_241 * V_242 )
{
struct V_234 * V_49 = V_242 -> V_23 -> V_49 ;
if ( ! V_242 -> V_261 || ! V_242 -> V_255 )
return 0 ;
if ( F_173 ( V_242 -> V_385 , L_168 ) )
return - V_28 ;
F_174 ( V_49 , V_242 -> V_261 , V_242 -> V_255 ) ;
if ( F_175 ( V_49 , true ) )
return - V_318 ;
V_242 -> V_385 = true ;
return 0 ;
}
static
int F_176 ( struct V_268 * V_269 ,
union V_270 * V_271 ,
struct V_22 * V_23 V_292 )
{
struct V_241 * V_242 = F_95 ( V_269 , struct V_241 , V_269 ) ;
if ( V_242 -> V_255 ) {
F_135 ( L_169 ) ;
return 0 ;
}
V_242 -> V_255 = F_177 ( & V_271 -> V_386 ) ;
if ( ! V_242 -> V_255 )
return - V_318 ;
return F_172 ( V_242 ) ;
}
static
int F_178 ( struct V_268 * V_269 V_292 ,
union V_270 * V_271 ,
struct V_22 * V_23 V_292 )
{
struct V_241 * V_242 = F_95 ( V_269 , struct V_241 , V_269 ) ;
if ( V_242 -> V_261 ) {
F_135 ( L_170 ) ;
return 0 ;
}
V_242 -> V_261 = F_179 ( & V_271 -> V_387 . V_145 ) ;
if ( ! V_242 -> V_261 )
return - V_318 ;
return F_172 ( V_242 ) ;
}
int F_180 ( int V_368 , const char * * V_369 )
{
bool V_388 = false ;
bool V_24 = false ;
bool V_389 = false ;
bool V_390 = false ;
char * V_391 = NULL ;
char * V_392 = NULL ;
struct V_22 * V_23 ;
struct V_393 V_393 = { . V_394 = false , } ;
char * V_351 = NULL ;
const char * * V_370 ;
int V_9 , V_3 , V_282 = 0 ;
struct V_241 V_242 = {
. V_269 = {
. V_87 = F_94 ,
. V_290 = F_116 ,
. V_291 = F_118 ,
. V_286 = F_106 ,
. V_288 = F_110 ,
. exit = F_114 ,
. V_289 = F_112 ,
. V_19 = F_100 ,
. V_395 = V_396 ,
. V_397 = V_398 ,
. V_399 = V_400 ,
. V_401 = V_402 ,
. V_403 = V_404 ,
. V_405 = V_406 ,
. V_407 = V_408 ,
. V_409 = V_410 ,
. V_330 = V_411 ,
. V_384 = F_168 ,
. V_265 = F_170 ,
. V_386 = F_176 ,
. V_387 = F_178 ,
. V_412 = true ,
. V_413 = true ,
} ,
} ;
struct V_360 V_361 = {
. V_363 = V_364 ,
} ;
const struct V_307 V_414 [] = {
F_181 ( 'D' , L_171 , & V_415 ,
L_172 ) ,
F_182 ( 'v' , L_173 , & V_416 ,
L_174 ) ,
F_181 ( 'L' , L_175 , & V_100 ,
L_176 ) ,
F_183 ( 'l' , L_177 , NULL , NULL , L_178 ,
F_149 ) ,
F_184 ( 's' , L_179 , NULL , L_180 ,
L_181 ,
F_132 ) ,
F_185 ( 'g' , L_182 , & V_417 , L_127 ,
L_183 ) ,
F_185 ( 'i' , L_184 , & V_362 , L_185 , L_186 ) ,
F_181 ( 'd' , L_187 , & V_274 ,
L_188 ) ,
F_181 ( 0 , L_189 , & V_24 , L_190 ) ,
F_181 ( 0 , L_191 , & V_389 , L_192 ) ,
F_185 ( 'k' , L_193 , & V_81 . V_418 ,
L_185 , L_194 ) ,
F_185 ( 0 , L_195 , & V_81 . V_419 ,
L_185 , L_196 ) ,
F_181 ( 'G' , L_197 , & V_77 ,
L_198 ) ,
F_184 ( 0 , L_199 , NULL , L_200 ,
L_201 ,
V_420 ) ,
F_184 ( 'F' , L_202 , NULL , L_203 ,
L_204
L_205
L_206
L_207
L_208
L_209 ,
F_134 ) ,
F_181 ( 'a' , L_210 , & V_258 ,
L_211 ) ,
F_185 ( 'S' , L_212 , & V_81 . V_421 , L_213 ,
L_214 ) ,
F_185 ( 0 , L_215 , & V_81 . V_422 , L_213 ,
L_216 ) ,
F_185 ( 'C' , L_217 , & V_279 , L_217 , L_218 ) ,
F_185 ( 'c' , L_219 , & V_81 . V_423 , L_220 ,
L_221 ) ,
F_185 ( 0 , L_222 , & V_81 . V_424 , L_223 ,
L_224 ) ,
F_185 ( 0 , L_225 , & V_81 . V_425 , L_226 ,
L_227 ) ,
F_186 ( 0 , L_228 , & V_180 ,
L_229
L_230
L_231 F_187 ( V_426 ) ) ,
F_181 ( 'I' , L_232 , & V_388 ,
L_233 ) ,
F_181 ( '\0' , L_234 , & V_81 . V_427 ,
L_235 ) ,
F_181 ( '\0' , L_236 , & V_242 . V_295 ,
L_237 ) ,
F_181 ( '\0' , L_238 , & V_242 . V_296 ,
L_239 ) ,
F_181 ( '\0' , L_240 , & V_242 . V_297 ,
L_241 ) ,
F_181 ( '\0' , L_242 , & V_242 . V_299 ,
L_243 ) ,
F_181 ( 'f' , L_244 , & V_81 . V_428 , L_245 ) ,
F_188 ( 0 , L_246 , & V_162 ,
L_247 ) ,
F_181 ( 0 , L_248 , & V_105 ,
L_249 ) ,
F_189 ( 0 , L_250 , & V_393 , NULL , L_251 ,
L_252 ,
V_429 ) ,
F_181 ( 0 , L_253 , & V_430 ,
L_254 ) ,
F_181 ( 0 , L_255 , & V_81 . V_431 ,
L_256 ) ,
F_181 ( 0 , L_257 , & V_81 . V_432 ,
L_258 ) ,
F_185 ( 0 , L_259 , & V_242 . V_433 , L_203 ,
L_260 ) ,
F_181 ( 0 , L_261 , & V_81 . V_434 ,
L_262 ) ,
F_190 ()
} ;
const char * const V_435 [] = { L_263 , L_264 , NULL } ;
const char * V_436 [] = {
L_265 ,
L_266 ,
L_267 ,
L_268 ,
L_269 ,
NULL
} ;
F_89 () ;
V_368 = F_191 ( V_368 , V_369 , V_414 , V_435 , V_436 ,
V_372 ) ;
V_361 . V_329 = V_362 ;
V_361 . V_428 = V_81 . V_428 ;
if ( V_368 > 1 && ! strncmp ( V_369 [ 0 ] , L_270 , strlen ( L_270 ) ) ) {
V_391 = F_161 ( V_369 [ 1 ] , V_437 ) ;
if ( ! V_391 )
return F_192 ( V_368 , V_369 ) ;
}
if ( V_368 > 1 && ! strncmp ( V_369 [ 0 ] , L_271 , strlen ( L_271 ) ) ) {
V_392 = F_161 ( V_369 [ 1 ] , V_354 ) ;
if ( ! V_392 ) {
fprintf ( V_306 ,
L_272
L_273 ) ;
return - 1 ;
}
}
if ( V_393 . V_179 &&
V_393 . V_438 > V_180 )
V_180 = V_393 . V_438 ;
F_193 ( F_150 () ) ;
if ( V_368 && ! V_310 && ! V_391 && ! V_392 ) {
int V_439 [ 2 ] ;
int V_440 ;
T_11 V_101 ;
V_391 = F_161 ( V_369 [ 0 ] , V_437 ) ;
V_392 = F_161 ( V_369 [ 0 ] , V_354 ) ;
if ( ! V_391 && ! V_392 ) {
F_194 ( V_436 , V_414 ,
L_274
L_275 , V_369 [ 0 ] ) ;
}
if ( F_162 ( V_369 [ 0 ] ) ) {
V_440 = V_368 - 1 ;
} else {
int V_441 ;
V_440 = F_163 ( V_392 ) ;
V_441 = ( V_368 - 1 ) - V_440 ;
if ( V_441 < 0 ) {
F_194 ( V_436 , V_414 ,
L_276
L_277
L_278 , V_369 [ 0 ] ) ;
}
}
if ( F_195 ( V_439 ) < 0 ) {
perror ( L_279 ) ;
return - 1 ;
}
V_101 = V_289 () ;
if ( V_101 < 0 ) {
perror ( L_280 ) ;
return - 1 ;
}
if ( ! V_101 ) {
V_3 = 0 ;
F_196 ( V_439 [ 1 ] , 1 ) ;
F_197 ( V_439 [ 0 ] ) ;
if ( F_162 ( V_369 [ 0 ] ) ) {
V_258 = true ;
} else if ( ! V_258 ) {
if ( F_164 ( V_368 - V_440 , & V_369 [ V_440 ] ) != 0 ) {
V_282 = - 1 ;
goto V_85;
}
}
V_370 = malloc ( ( V_368 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_370 ) {
F_8 ( L_167 ) ;
V_282 = - V_318 ;
goto V_85;
}
V_370 [ V_3 ++ ] = L_281 ;
V_370 [ V_3 ++ ] = V_391 ;
if ( V_258 )
V_370 [ V_3 ++ ] = L_282 ;
V_370 [ V_3 ++ ] = L_283 ;
V_370 [ V_3 ++ ] = L_284 ;
V_370 [ V_3 ++ ] = L_285 ;
for ( V_9 = V_440 + 1 ; V_9 < V_368 ; V_9 ++ )
V_370 [ V_3 ++ ] = V_369 [ V_9 ] ;
V_370 [ V_3 ++ ] = NULL ;
F_198 ( L_281 , ( char * * ) V_370 ) ;
free ( V_370 ) ;
exit ( - 1 ) ;
}
F_196 ( V_439 [ 0 ] , 0 ) ;
F_197 ( V_439 [ 1 ] ) ;
V_370 = malloc ( ( V_368 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_370 ) {
F_8 ( L_167 ) ;
V_282 = - V_318 ;
goto V_85;
}
V_3 = 0 ;
V_370 [ V_3 ++ ] = L_281 ;
V_370 [ V_3 ++ ] = V_392 ;
for ( V_9 = 1 ; V_9 < V_440 + 1 ; V_9 ++ )
V_370 [ V_3 ++ ] = V_369 [ V_9 ] ;
V_370 [ V_3 ++ ] = L_286 ;
V_370 [ V_3 ++ ] = L_285 ;
V_370 [ V_3 ++ ] = NULL ;
F_198 ( L_281 , ( char * * ) V_370 ) ;
free ( V_370 ) ;
exit ( - 1 ) ;
}
if ( V_391 )
V_351 = V_391 ;
if ( V_392 )
V_351 = V_392 ;
if ( V_351 ) {
V_3 = 0 ;
if ( ! V_391 )
V_258 = false ;
else if ( ! V_258 ) {
if ( F_164 ( V_368 - 1 , & V_369 [ 1 ] ) != 0 ) {
V_282 = - 1 ;
goto V_85;
}
}
V_370 = malloc ( ( V_368 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_370 ) {
F_8 ( L_167 ) ;
V_282 = - V_318 ;
goto V_85;
}
V_370 [ V_3 ++ ] = L_281 ;
V_370 [ V_3 ++ ] = V_351 ;
if ( V_258 )
V_370 [ V_3 ++ ] = L_282 ;
for ( V_9 = 2 ; V_9 < V_368 ; V_9 ++ )
V_370 [ V_3 ++ ] = V_369 [ V_9 ] ;
V_370 [ V_3 ++ ] = NULL ;
F_198 ( L_281 , ( char * * ) V_370 ) ;
free ( V_370 ) ;
exit ( - 1 ) ;
}
if ( ! V_310 )
F_199 () ;
V_23 = F_156 ( & V_361 , false , & V_242 . V_269 ) ;
if ( V_23 == NULL )
return - 1 ;
if ( V_24 || V_389 ) {
V_242 . V_269 . V_442 = V_443 ;
F_200 ( V_23 , stdout , V_388 ) ;
if ( V_389 )
goto V_444;
}
if ( V_388 )
V_242 . V_269 . V_442 = V_445 ;
if ( F_201 ( & V_23 -> V_24 . V_446 ) < 0 )
goto V_444;
V_242 . V_23 = V_23 ;
F_166 ( & V_242 ) ;
if ( V_5 [ V_319 ] . V_21 & V_447 )
V_393 . V_448 = true ;
V_23 -> V_393 = & V_393 ;
if ( V_279 ) {
V_282 = F_202 ( V_23 , V_279 , V_280 ) ;
if ( V_282 < 0 )
goto V_444;
V_393 . V_280 = V_280 ;
}
if ( ! V_77 )
V_81 . V_78 = true ;
else
V_81 . V_78 = false ;
if ( V_23 -> V_449 . V_450 &&
F_203 ( V_23 -> V_449 . V_450 ,
V_451 ,
& V_23 -> V_452 . V_453 ) < 0 ) {
F_8 ( L_287 , V_454 ) ;
return - 1 ;
}
if ( V_417 ) {
struct V_330 V_455 ;
int V_456 ;
if ( F_3 () ) {
fprintf ( V_306 ,
L_288 ) ;
V_282 = - V_28 ;
goto V_444;
}
V_456 = F_204 ( V_361 . V_329 , V_457 ) ;
if ( V_456 < 0 ) {
V_282 = - V_458 ;
perror ( L_289 ) ;
goto V_444;
}
V_282 = F_205 ( V_456 , & V_455 ) ;
if ( V_282 < 0 ) {
perror ( L_290 ) ;
goto V_444;
}
if ( ! V_455 . V_459 ) {
fprintf ( V_306 , L_291 ) ;
goto V_444;
}
V_264 = F_130 ( V_417 ) ;
if ( ! V_264 ) {
fprintf ( V_306 , L_128 ) ;
V_282 = - V_460 ;
goto V_444;
}
V_282 = V_264 -> V_461 ( V_23 -> V_449 . V_450 ,
L_292 ) ;
goto V_444;
}
if ( V_310 ) {
V_282 = V_264 -> V_462 ( V_310 , V_368 , V_369 ) ;
if ( V_282 )
goto V_444;
F_9 ( L_293 , V_310 ) ;
V_390 = true ;
}
V_282 = F_17 ( V_23 ) ;
if ( V_282 < 0 )
goto V_444;
if ( F_206 ( & V_242 . V_273 , V_242 . V_433 ) != 0 ) {
F_8 ( L_294 ) ;
return - V_28 ;
}
V_282 = F_122 ( & V_242 ) ;
F_92 () ;
V_444:
F_207 ( V_23 -> V_49 ) ;
F_157 ( V_23 ) ;
if ( V_390 )
F_93 () ;
V_85:
return V_282 ;
}
