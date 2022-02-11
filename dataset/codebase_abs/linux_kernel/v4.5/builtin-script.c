static bool F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_4 )
return true ;
}
return false ;
}
static const char * F_2 ( enum V_5 V_6 )
{
int V_7 , V_8 = F_3 ( V_9 ) ;
const char * V_10 = L_1 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( V_9 [ V_7 ] . V_6 == V_6 ) {
V_10 = V_9 [ V_7 ] . V_10 ;
break;
}
}
return V_10 ;
}
static int F_4 ( struct V_11 * V_12 ,
T_1 V_13 , const char * V_14 ,
enum V_5 V_6 ,
bool V_15 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
int type = V_17 -> type ;
const char * V_18 ;
if ( V_17 -> V_13 & V_13 )
return 0 ;
if ( V_3 [ type ] . V_4 ) {
if ( V_15 )
return 0 ;
V_18 = F_5 ( V_12 ) ;
F_6 ( L_2
L_3 ,
V_18 , V_14 , F_2 ( V_6 ) ) ;
return - 1 ;
}
V_3 [ type ] . V_19 &= ~ V_6 ;
V_18 = F_5 ( V_12 ) ;
F_7 ( L_2
L_4 ,
V_18 , V_14 , F_2 ( V_6 ) ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
T_1 V_13 , const char * V_14 ,
enum V_5 V_6 )
{
return F_4 ( V_12 , V_13 , V_14 , V_6 ,
false ) ;
}
static int F_9 ( struct V_11 * V_12 ,
struct V_20 * V_21 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_15 ;
if ( F_10 ( & V_21 -> V_22 , V_23 ) )
return 0 ;
V_15 = F_10 ( & V_21 -> V_22 ,
V_24 ) ;
if ( F_11 ( V_25 ) &&
! F_12 ( V_21 , L_5 ) )
return - V_26 ;
if ( F_11 ( V_27 ) ) {
if ( F_8 ( V_12 , V_28 , L_6 ,
V_29 ) )
return - V_26 ;
}
if ( F_11 ( V_30 ) &&
F_4 ( V_12 , V_31 , L_7 ,
V_32 , V_15 ) )
return - V_26 ;
if ( F_11 ( V_33 ) && ! F_11 ( V_27 ) && ! F_11 ( V_30 ) ) {
F_6 ( L_8
L_9
L_10 ) ;
return - V_26 ;
}
if ( F_11 ( V_34 ) && ! F_11 ( V_33 ) ) {
F_6 ( L_11
L_12 ) ;
return - V_26 ;
}
if ( F_11 ( V_35 ) && ! F_11 ( V_27 ) && ! F_11 ( V_30 ) ) {
F_6 ( L_13
L_9
L_14 ) ;
return - V_26 ;
}
if ( F_11 ( V_36 ) && ! F_11 ( V_27 ) ) {
F_6 ( L_15
L_16 ) ;
return - V_26 ;
}
if ( ( F_11 ( V_37 ) || F_11 ( V_38 ) ) &&
F_8 ( V_12 , V_39 , L_17 ,
V_40 | V_41 ) )
return - V_26 ;
if ( F_11 ( TIME ) &&
F_8 ( V_12 , V_42 , L_18 ,
V_43 ) )
return - V_26 ;
if ( F_11 ( V_44 ) &&
F_4 ( V_12 , V_45 , L_19 ,
V_46 , V_15 ) )
return - V_26 ;
if ( F_11 ( V_47 ) &&
F_8 ( V_12 , V_48 , L_20 ,
V_49 ) )
return - V_26 ;
if ( F_11 ( V_50 ) &&
F_8 ( V_12 , V_51 , L_21 ,
V_52 ) )
return - V_26 ;
return 0 ;
}
static void F_13 ( struct V_16 * V_17 )
{
unsigned int type = V_17 -> type ;
V_3 [ type ] . V_53 = 0 ;
if ( F_11 ( V_27 ) )
V_3 [ type ] . V_53 |= V_54 ;
if ( F_11 ( V_33 ) )
V_3 [ type ] . V_53 |= V_55 ;
if ( F_11 ( V_35 ) )
V_3 [ type ] . V_53 |= V_56 ;
if ( F_11 ( V_34 ) )
V_3 [ type ] . V_53 |= V_57 ;
if ( F_11 ( V_36 ) )
V_3 [ type ] . V_53 |= V_58 ;
}
static int F_14 ( struct V_20 * V_21 )
{
int V_1 ;
struct V_11 * V_12 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_12 = F_15 ( V_21 , V_1 ) ;
if ( ! V_12 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_59 ) {
F_6 ( L_22
L_23 ,
F_16 ( V_1 ) ) ;
return - 1 ;
}
if ( V_12 && V_3 [ V_1 ] . V_19 &&
F_9 ( V_12 , V_21 ) )
return - 1 ;
if ( V_12 == NULL )
continue;
F_13 ( & V_12 -> V_17 ) ;
}
if ( ! V_60 ) {
bool V_61 = false ;
F_17 (session->evlist, evsel) {
if ( V_12 -> V_17 . V_13 & V_62 ) {
V_61 = true ;
break;
}
}
if ( ! V_61 )
V_63 . V_61 = false ;
}
if ( V_63 . V_61 &&
! V_3 [ V_64 ] . V_4 ) {
struct V_16 * V_17 ;
V_1 = V_64 ;
V_12 = F_15 ( V_21 , V_1 ) ;
if ( V_12 == NULL )
goto V_65;
V_17 = & V_12 -> V_17 ;
if ( V_17 -> V_13 & V_62 ) {
V_3 [ V_1 ] . V_19 |= V_29 ;
V_3 [ V_1 ] . V_19 |= V_66 ;
V_3 [ V_1 ] . V_19 |= V_67 ;
F_13 ( V_17 ) ;
}
}
V_65:
return 0 ;
}
static void F_18 ( union V_68 * T_2 V_69 ,
struct V_70 * V_71 ,
struct V_72 * V_72 V_69 ,
struct V_16 * V_17 )
{
struct V_73 * V_74 = & V_71 -> V_75 ;
T_3 V_76 = V_17 -> V_77 ;
unsigned V_7 = 0 , V_78 ;
if ( ! V_74 )
return;
F_19 (r, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_1 V_79 = V_74 -> V_74 [ V_7 ++ ] ;
printf ( L_24 V_80 L_25 , F_20 ( V_78 ) , V_79 ) ;
}
}
static void F_21 ( struct V_70 * V_71 ,
struct V_72 * V_72 ,
struct V_11 * V_12 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
unsigned long V_81 ;
unsigned long V_82 ;
unsigned long long V_83 ;
if ( F_11 ( V_84 ) ) {
if ( V_85 )
printf ( L_26 , F_22 ( V_72 ) ) ;
else if ( F_11 ( V_27 ) && V_63 . V_61 )
printf ( L_27 , F_22 ( V_72 ) ) ;
else
printf ( L_28 , F_22 ( V_72 ) ) ;
}
if ( F_11 ( V_37 ) && F_11 ( V_38 ) )
printf ( L_29 , V_71 -> V_86 , V_71 -> V_87 ) ;
else if ( F_11 ( V_37 ) )
printf ( L_30 , V_71 -> V_86 ) ;
else if ( F_11 ( V_38 ) )
printf ( L_30 , V_71 -> V_87 ) ;
if ( F_11 ( V_44 ) ) {
if ( V_85 )
printf ( L_31 , V_71 -> V_88 ) ;
else
printf ( L_32 , V_71 -> V_88 ) ;
}
if ( F_11 ( TIME ) ) {
V_83 = V_71 -> time ;
V_81 = V_83 / V_89 ;
V_83 -= V_81 * V_89 ;
V_82 = V_83 / V_90 ;
if ( V_91 )
printf ( L_33 , V_81 , V_83 ) ;
else
printf ( L_34 , V_81 , V_82 ) ;
}
}
static inline char
F_23 ( struct V_92 * V_93 )
{
if ( ! ( V_93 -> V_94 . V_95 || V_93 -> V_94 . V_96 ) )
return '-' ;
return V_93 -> V_94 . V_96 ? 'P' : 'M' ;
}
static void F_24 ( union V_68 * T_2 V_69 ,
struct V_70 * V_71 ,
struct V_72 * V_72 V_69 ,
struct V_16 * V_17 V_69 )
{
struct V_97 * V_93 = V_71 -> V_97 ;
T_1 V_7 ;
if ( ! ( V_93 && V_93 -> V_98 ) )
return;
for ( V_7 = 0 ; V_7 < V_93 -> V_98 ; V_7 ++ ) {
printf ( L_35 V_80 L_36 V_80 L_37 ,
V_93 -> V_99 [ V_7 ] . V_100 ,
V_93 -> V_99 [ V_7 ] . V_101 ,
F_23 ( V_93 -> V_99 + V_7 ) ,
V_93 -> V_99 [ V_7 ] . V_94 . V_102 ? 'X' : '-' ,
V_93 -> V_99 [ V_7 ] . V_94 . abort ? 'A' : '-' ,
V_93 -> V_99 [ V_7 ] . V_94 . V_103 ) ;
}
}
static void F_25 ( union V_68 * T_2 V_69 ,
struct V_70 * V_71 ,
struct V_72 * V_72 V_69 ,
struct V_16 * V_17 V_69 )
{
struct V_97 * V_93 = V_71 -> V_97 ;
struct V_104 V_105 , V_106 ;
T_4 V_107 = T_2 -> V_22 . V_108 & V_109 ;
T_1 V_7 , V_100 , V_101 ;
if ( ! ( V_93 && V_93 -> V_98 ) )
return;
for ( V_7 = 0 ; V_7 < V_93 -> V_98 ; V_7 ++ ) {
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_100 = V_93 -> V_99 [ V_7 ] . V_100 ;
V_101 = V_93 -> V_99 [ V_7 ] . V_101 ;
F_26 ( V_72 , V_107 , V_110 , V_100 , & V_105 ) ;
if ( V_105 . V_111 )
V_105 . V_112 = F_27 ( V_105 . V_111 , V_105 . V_113 , NULL ) ;
F_26 ( V_72 , V_107 , V_110 , V_101 , & V_106 ) ;
if ( V_106 . V_111 )
V_106 . V_112 = F_27 ( V_106 . V_111 , V_106 . V_113 , NULL ) ;
F_28 ( V_105 . V_112 , & V_105 , stdout ) ;
putchar ( '/' ) ;
F_28 ( V_106 . V_112 , & V_106 , stdout ) ;
printf ( L_37 ,
F_23 ( V_93 -> V_99 + V_7 ) ,
V_93 -> V_99 [ V_7 ] . V_94 . V_102 ? 'X' : '-' ,
V_93 -> V_99 [ V_7 ] . V_94 . abort ? 'A' : '-' ,
V_93 -> V_99 [ V_7 ] . V_94 . V_103 ) ;
}
}
static void F_29 ( union V_68 * T_2 ,
struct V_70 * V_71 ,
struct V_72 * V_72 ,
struct V_16 * V_17 )
{
struct V_104 V_114 ;
printf ( L_38 V_80 , V_71 -> V_113 ) ;
if ( ! F_30 ( V_17 ) )
return;
F_31 ( T_2 , V_71 , V_72 , & V_114 ) ;
if ( F_11 ( V_33 ) ) {
printf ( L_25 ) ;
if ( F_11 ( V_34 ) )
F_28 ( V_114 . V_112 , & V_114 , stdout ) ;
else
F_32 ( V_114 . V_112 , stdout ) ;
}
if ( F_11 ( V_35 ) ) {
printf ( L_39 ) ;
F_33 ( V_114 . V_111 , stdout ) ;
printf ( L_40 ) ;
}
}
static void F_34 ( union V_68 * T_2 ,
struct V_70 * V_71 ,
struct V_11 * V_12 ,
struct V_72 * V_72 ,
struct V_104 * V_114 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_115 = false ;
if ( F_11 ( V_27 ) ) {
unsigned int V_116 = V_3 [ V_17 -> type ] . V_53 ;
if ( V_63 . V_61 && V_71 -> V_117 ) {
printf ( L_41 ) ;
} else {
printf ( L_25 ) ;
if ( V_116 & V_58 ) {
V_115 = true ;
V_116 &= ~ V_58 ;
}
}
F_35 ( V_12 , V_71 , V_114 , V_116 ,
V_118 ) ;
}
if ( F_11 ( V_30 ) ||
( ( V_12 -> V_17 . V_13 & V_31 ) &&
! V_3 [ V_17 -> type ] . V_4 ) ) {
printf ( L_42 ) ;
F_29 ( T_2 , V_71 , V_72 , V_17 ) ;
}
if ( V_115 )
F_36 ( V_114 -> V_111 , V_114 -> V_113 , L_43 , stdout ) ;
printf ( L_41 ) ;
}
static void F_37 ( T_5 V_94 )
{
const char * V_119 = V_120 ;
const int V_121 = strlen ( V_120 ) ;
char V_10 [ 33 ] ;
int V_7 , V_122 = 0 ;
for ( V_7 = 0 ; V_7 < V_121 ; V_7 ++ , V_94 >>= 1 ) {
if ( V_94 & 1 )
V_10 [ V_122 ++ ] = V_119 [ V_7 ] ;
}
for (; V_7 < 32 ; V_7 ++ , V_94 >>= 1 ) {
if ( V_94 & 1 )
V_10 [ V_122 ++ ] = '?' ;
}
V_10 [ V_122 ] = 0 ;
printf ( L_44 , V_10 ) ;
}
static int F_38 ( struct V_123 * V_124 )
{
struct V_11 * V_12 ;
int V_125 = 0 ;
F_17 (evlist, evsel) {
int V_126 = strlen ( F_5 ( V_12 ) ) ;
V_125 = F_39 ( V_126 , V_125 ) ;
}
return V_125 ;
}
static void F_40 ( struct V_127 * V_128 , union V_68 * T_2 ,
struct V_70 * V_71 , struct V_11 * V_12 ,
struct V_104 * V_114 )
{
struct V_72 * V_72 = V_114 -> V_72 ;
struct V_16 * V_17 = & V_12 -> V_17 ;
if ( V_3 [ V_17 -> type ] . V_19 == 0 )
return;
F_21 ( V_71 , V_72 , V_12 ) ;
if ( F_11 ( V_47 ) )
printf ( L_45 V_129 L_25 , V_71 -> V_130 ) ;
if ( F_11 ( V_131 ) ) {
const char * V_18 = F_5 ( V_12 ) ;
if ( ! V_128 -> V_132 )
V_128 -> V_132 = F_38 ( V_128 -> V_21 -> V_124 ) ;
printf ( L_46 , V_128 -> V_132 ,
V_18 ? V_18 : L_47 ) ;
}
if ( V_133 )
F_37 ( V_71 -> V_94 ) ;
if ( F_41 ( V_17 ) ) {
F_34 ( T_2 , V_71 , V_12 , V_72 , V_114 ) ;
return;
}
if ( F_11 ( V_25 ) )
F_42 ( V_12 -> V_134 , V_71 -> V_88 ,
V_71 -> V_135 , V_71 -> V_136 ) ;
if ( F_11 ( V_30 ) )
F_29 ( T_2 , V_71 , V_72 , V_17 ) ;
if ( F_11 ( V_27 ) ) {
if ( ! V_63 . V_61 )
printf ( L_25 ) ;
else
printf ( L_41 ) ;
F_35 ( V_12 , V_71 , V_114 ,
V_3 [ V_17 -> type ] . V_53 ,
V_118 ) ;
}
if ( F_11 ( V_50 ) )
F_18 ( T_2 , V_71 , V_72 , V_17 ) ;
if ( F_11 ( V_137 ) )
F_24 ( T_2 , V_71 , V_72 , V_17 ) ;
else if ( F_11 ( V_138 ) )
F_25 ( T_2 , V_71 , V_72 , V_17 ) ;
printf ( L_41 ) ;
}
static void F_43 ( struct V_11 * V_139 , T_1 V_140 )
{
int V_141 = F_44 ( V_139 -> V_142 ) ;
int V_143 = F_45 ( V_139 ) ;
int V_88 , V_72 ;
static int V_144 ;
if ( V_139 -> V_145 )
V_141 = 1 ;
if ( ! V_144 ) {
printf ( L_48 ,
L_19 , L_49 , L_50 , L_51 , L_52 , L_18 , L_53 ) ;
V_144 = 1 ;
}
for ( V_72 = 0 ; V_72 < V_141 ; V_72 ++ ) {
for ( V_88 = 0 ; V_88 < V_143 ; V_88 ++ ) {
struct V_146 * V_147 ;
V_147 = F_46 ( V_139 -> V_147 , V_88 , V_72 ) ;
printf ( L_54 V_129 L_55 V_129 L_55 V_129 L_55 V_129 L_56 ,
V_139 -> V_148 -> V_111 [ V_88 ] ,
F_47 ( V_139 -> V_142 , V_72 ) ,
V_147 -> V_79 ,
V_147 -> V_149 ,
V_147 -> V_150 ,
V_140 ,
F_5 ( V_139 ) ) ;
}
}
}
static void F_48 ( struct V_11 * V_139 , T_1 V_140 )
{
if ( V_151 && V_151 -> F_48 )
V_151 -> F_48 ( & V_152 , V_139 , V_140 ) ;
else
F_43 ( V_139 , V_140 ) ;
}
static void F_49 ( T_1 V_140 )
{
if ( V_151 && V_151 -> F_49 )
V_151 -> F_49 ( V_140 ) ;
}
static void F_50 ( void )
{
F_51 () ;
F_52 () ;
}
static int F_53 ( void )
{
return V_151 ? V_151 -> V_153 () : 0 ;
}
static int F_54 ( void )
{
F_7 ( L_57 ) ;
return V_151 ? V_151 -> V_154 () : 0 ;
}
static int F_55 ( struct V_155 * V_156 ,
union V_68 * T_2 ,
struct V_70 * V_71 ,
struct V_11 * V_12 ,
struct V_157 * V_157 )
{
struct V_127 * V_158 = F_56 ( V_156 , struct V_127 , V_156 ) ;
struct V_104 V_114 ;
if ( V_159 ) {
if ( V_71 -> time < V_160 ) {
F_6 ( L_58 V_129
L_59 V_129 L_41 , V_160 ,
V_71 -> time ) ;
V_161 ++ ;
}
V_160 = V_71 -> time ;
return 0 ;
}
if ( F_57 ( T_2 , V_157 , & V_114 , V_71 ) < 0 ) {
F_6 ( L_60 ,
T_2 -> V_22 . type ) ;
return - 1 ;
}
if ( V_114 . V_162 )
goto V_163;
if ( V_164 && ! F_58 ( V_71 -> V_88 , V_165 ) )
goto V_163;
if ( V_151 )
V_151 -> F_40 ( T_2 , V_71 , V_12 , & V_114 ) ;
else
F_40 ( V_158 , T_2 , V_71 , V_12 , & V_114 ) ;
V_163:
F_59 ( & V_114 ) ;
return 0 ;
}
static int F_60 ( struct V_155 * V_156 , union V_68 * T_2 ,
struct V_123 * * V_166 )
{
struct V_127 * V_158 = F_56 ( V_156 , struct V_127 , V_156 ) ;
struct V_123 * V_124 ;
struct V_11 * V_12 , * V_122 ;
int V_167 ;
V_167 = F_61 ( V_156 , T_2 , V_166 ) ;
if ( V_167 )
return V_167 ;
V_124 = * V_166 ;
V_12 = F_62 ( * V_166 ) ;
if ( V_12 -> V_17 . type >= V_2 )
return 0 ;
F_17 (evlist, pos) {
if ( V_122 -> V_17 . type == V_12 -> V_17 . type && V_122 != V_12 )
return 0 ;
}
F_13 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_17 . V_13 )
V_167 = F_9 ( V_12 , V_158 -> V_21 ) ;
return V_167 ;
}
static int F_63 ( struct V_155 * V_156 ,
union V_68 * T_2 ,
struct V_70 * V_71 ,
struct V_157 * V_157 )
{
struct V_72 * V_72 ;
struct V_127 * V_128 = F_56 ( V_156 , struct V_127 , V_156 ) ;
struct V_20 * V_21 = V_128 -> V_21 ;
struct V_11 * V_12 = F_64 ( V_21 -> V_124 , V_71 -> V_168 ) ;
int V_169 = - 1 ;
V_72 = F_65 ( V_157 , T_2 -> V_170 . V_86 , T_2 -> V_170 . V_87 ) ;
if ( V_72 == NULL ) {
F_7 ( L_61 ) ;
return - 1 ;
}
if ( F_66 ( V_156 , T_2 , V_71 , V_157 ) < 0 )
goto V_65;
if ( ! V_12 -> V_17 . V_171 ) {
V_71 -> V_88 = 0 ;
V_71 -> time = 0 ;
V_71 -> V_87 = T_2 -> V_170 . V_87 ;
V_71 -> V_86 = T_2 -> V_170 . V_86 ;
}
F_21 ( V_71 , V_72 , V_12 ) ;
F_67 ( T_2 , stdout ) ;
V_169 = 0 ;
V_65:
F_68 ( V_72 ) ;
return V_169 ;
}
static int F_69 ( struct V_155 * V_156 ,
union V_68 * T_2 ,
struct V_70 * V_71 ,
struct V_157 * V_157 )
{
struct V_72 * V_72 ;
struct V_127 * V_128 = F_56 ( V_156 , struct V_127 , V_156 ) ;
struct V_20 * V_21 = V_128 -> V_21 ;
struct V_11 * V_12 = F_64 ( V_21 -> V_124 , V_71 -> V_168 ) ;
if ( F_70 ( V_156 , T_2 , V_71 , V_157 ) < 0 )
return - 1 ;
V_72 = F_65 ( V_157 , T_2 -> V_172 . V_86 , T_2 -> V_172 . V_87 ) ;
if ( V_72 == NULL ) {
F_7 ( L_62 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_171 ) {
V_71 -> V_88 = 0 ;
V_71 -> time = T_2 -> V_172 . time ;
V_71 -> V_87 = T_2 -> V_172 . V_87 ;
V_71 -> V_86 = T_2 -> V_172 . V_86 ;
}
F_21 ( V_71 , V_72 , V_12 ) ;
F_67 ( T_2 , stdout ) ;
F_68 ( V_72 ) ;
return 0 ;
}
static int F_71 ( struct V_155 * V_156 ,
union V_68 * T_2 ,
struct V_70 * V_71 ,
struct V_157 * V_157 )
{
int V_167 = 0 ;
struct V_72 * V_72 ;
struct V_127 * V_128 = F_56 ( V_156 , struct V_127 , V_156 ) ;
struct V_20 * V_21 = V_128 -> V_21 ;
struct V_11 * V_12 = F_64 ( V_21 -> V_124 , V_71 -> V_168 ) ;
V_72 = F_65 ( V_157 , T_2 -> V_172 . V_86 , T_2 -> V_172 . V_87 ) ;
if ( V_72 == NULL ) {
F_7 ( L_63 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_171 ) {
V_71 -> V_88 = 0 ;
V_71 -> time = 0 ;
V_71 -> V_87 = T_2 -> V_172 . V_87 ;
V_71 -> V_86 = T_2 -> V_172 . V_86 ;
}
F_21 ( V_71 , V_72 , V_12 ) ;
F_67 ( T_2 , stdout ) ;
if ( F_72 ( V_156 , T_2 , V_71 , V_157 ) < 0 )
V_167 = - 1 ;
F_68 ( V_72 ) ;
return V_167 ;
}
static int F_73 ( struct V_155 * V_156 ,
union V_68 * T_2 ,
struct V_70 * V_71 ,
struct V_157 * V_157 )
{
struct V_72 * V_72 ;
struct V_127 * V_128 = F_56 ( V_156 , struct V_127 , V_156 ) ;
struct V_20 * V_21 = V_128 -> V_21 ;
struct V_11 * V_12 = F_64 ( V_21 -> V_124 , V_71 -> V_168 ) ;
if ( F_74 ( V_156 , T_2 , V_71 , V_157 ) < 0 )
return - 1 ;
V_72 = F_65 ( V_157 , T_2 -> V_173 . V_86 , T_2 -> V_173 . V_87 ) ;
if ( V_72 == NULL ) {
F_7 ( L_64 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_171 ) {
V_71 -> V_88 = 0 ;
V_71 -> time = 0 ;
V_71 -> V_87 = T_2 -> V_173 . V_87 ;
V_71 -> V_86 = T_2 -> V_173 . V_86 ;
}
F_21 ( V_71 , V_72 , V_12 ) ;
F_67 ( T_2 , stdout ) ;
F_68 ( V_72 ) ;
return 0 ;
}
static int F_75 ( struct V_155 * V_156 ,
union V_68 * T_2 ,
struct V_70 * V_71 ,
struct V_157 * V_157 )
{
struct V_72 * V_72 ;
struct V_127 * V_128 = F_56 ( V_156 , struct V_127 , V_156 ) ;
struct V_20 * V_21 = V_128 -> V_21 ;
struct V_11 * V_12 = F_64 ( V_21 -> V_124 , V_71 -> V_168 ) ;
if ( F_76 ( V_156 , T_2 , V_71 , V_157 ) < 0 )
return - 1 ;
V_72 = F_65 ( V_157 , T_2 -> V_174 . V_86 , T_2 -> V_174 . V_87 ) ;
if ( V_72 == NULL ) {
F_7 ( L_65 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_171 ) {
V_71 -> V_88 = 0 ;
V_71 -> time = 0 ;
V_71 -> V_87 = T_2 -> V_174 . V_87 ;
V_71 -> V_86 = T_2 -> V_174 . V_86 ;
}
F_21 ( V_71 , V_72 , V_12 ) ;
F_67 ( T_2 , stdout ) ;
F_68 ( V_72 ) ;
return 0 ;
}
static int F_77 ( struct V_155 * V_156 ,
union V_68 * T_2 ,
struct V_70 * V_71 ,
struct V_157 * V_157 )
{
struct V_72 * V_72 ;
struct V_127 * V_128 = F_56 ( V_156 , struct V_127 , V_156 ) ;
struct V_20 * V_21 = V_128 -> V_21 ;
struct V_11 * V_12 = F_64 ( V_21 -> V_124 , V_71 -> V_168 ) ;
if ( F_78 ( V_156 , T_2 , V_71 , V_157 ) < 0 )
return - 1 ;
V_72 = F_65 ( V_157 , V_71 -> V_86 ,
V_71 -> V_87 ) ;
if ( V_72 == NULL ) {
F_7 ( L_66 ) ;
return - 1 ;
}
F_21 ( V_71 , V_72 , V_12 ) ;
F_67 ( T_2 , stdout ) ;
F_68 ( V_72 ) ;
return 0 ;
}
static void F_79 ( int T_6 V_69 )
{
V_175 = 1 ;
}
static int F_80 ( struct V_127 * V_128 )
{
int V_169 ;
signal ( V_176 , F_79 ) ;
if ( V_128 -> V_177 ) {
V_128 -> V_156 . V_170 = F_63 ;
V_128 -> V_156 . V_172 = F_69 ;
V_128 -> V_156 . exit = F_71 ;
}
if ( V_128 -> V_178 ) {
V_128 -> V_156 . V_173 = F_73 ;
V_128 -> V_156 . V_174 = F_75 ;
}
if ( V_128 -> V_179 )
V_128 -> V_156 . V_180 = F_77 ;
V_169 = F_81 ( V_128 -> V_21 ) ;
if ( V_159 )
F_6 ( L_67 V_129 L_41 , V_161 ) ;
return V_169 ;
}
static struct V_181 * F_82 ( const char * V_182 ,
struct V_151 * V_183 )
{
struct V_181 * V_184 = malloc ( sizeof( * V_184 ) + strlen ( V_182 ) + 1 ) ;
if ( V_184 != NULL ) {
strcpy ( V_184 -> V_182 , V_182 ) ;
V_184 -> V_183 = V_183 ;
}
return V_184 ;
}
static void F_83 ( struct V_181 * V_184 )
{
F_84 ( & V_184 -> V_185 , & V_186 ) ;
}
static struct V_181 * F_85 ( const char * V_182 )
{
struct V_181 * V_184 ;
F_86 (s, &script_specs, node)
if ( strcasecmp ( V_184 -> V_182 , V_182 ) == 0 )
return V_184 ;
return NULL ;
}
static struct V_181 * F_87 ( const char * V_182 ,
struct V_151 * V_183 )
{
struct V_181 * V_184 = F_85 ( V_182 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_82 ( V_182 , V_183 ) ;
if ( ! V_184 )
return NULL ;
F_83 ( V_184 ) ;
return V_184 ;
}
int F_88 ( const char * V_182 , struct V_151 * V_183 )
{
struct V_181 * V_184 ;
V_184 = F_85 ( V_182 ) ;
if ( V_184 )
return - 1 ;
V_184 = F_87 ( V_182 , V_183 ) ;
if ( ! V_184 )
return - 1 ;
return 0 ;
}
static struct V_151 * F_89 ( const char * V_182 )
{
struct V_181 * V_184 = F_85 ( V_182 ) ;
if ( ! V_184 )
return NULL ;
return V_184 -> V_183 ;
}
static void F_90 ( void )
{
struct V_181 * V_184 ;
fprintf ( V_187 , L_41 ) ;
fprintf ( V_187 , L_68
L_69 ) ;
F_86 (s, &script_specs, node)
fprintf ( V_187 , L_70 , V_184 -> V_182 , V_184 -> V_183 -> V_188 ) ;
fprintf ( V_187 , L_41 ) ;
}
static int F_91 ( const struct V_189 * T_7 V_69 ,
const char * V_10 , int T_8 V_69 )
{
char V_182 [ V_190 ] ;
const char * V_128 , * V_191 ;
int V_126 ;
if ( strcmp ( V_10 , L_71 ) == 0 ) {
F_90 () ;
exit ( 0 ) ;
}
V_128 = strchr ( V_10 , ':' ) ;
if ( V_128 ) {
V_126 = V_128 - V_10 ;
if ( V_126 >= V_190 ) {
fprintf ( V_187 , L_72 ) ;
return - 1 ;
}
strncpy ( V_182 , V_10 , V_126 ) ;
V_182 [ V_126 ] = '\0' ;
V_151 = F_89 ( V_182 ) ;
if ( ! V_151 ) {
fprintf ( V_187 , L_72 ) ;
return - 1 ;
}
V_128 ++ ;
} else {
V_128 = V_10 ;
V_191 = strrchr ( V_128 , '.' ) ;
if ( ! V_191 ) {
fprintf ( V_187 , L_73 ) ;
return - 1 ;
}
V_151 = F_89 ( ++ V_191 ) ;
if ( ! V_151 ) {
fprintf ( V_187 , L_73 ) ;
return - 1 ;
}
}
V_192 = F_92 ( V_128 ) ;
return 0 ;
}
static int F_93 ( const struct V_189 * T_7 V_69 ,
const char * V_193 , int T_8 V_69 )
{
char * V_194 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_195 = 0 ;
char * V_10 = F_92 ( V_193 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_196 ;
V_194 = strchr ( V_10 , ':' ) ;
if ( V_194 ) {
* V_194 = '\0' ;
V_194 ++ ;
if ( ! strcmp ( V_10 , L_74 ) )
type = V_197 ;
else if ( ! strcmp ( V_10 , L_75 ) )
type = V_198 ;
else if ( ! strcmp ( V_10 , L_76 ) )
type = V_64 ;
else if ( ! strcmp ( V_10 , L_77 ) )
type = V_199 ;
else if ( ! strcmp ( V_10 , L_78 ) )
type = V_200 ;
else {
fprintf ( V_187 , L_79 ) ;
V_195 = - V_26 ;
goto V_65;
}
if ( V_3 [ type ] . V_4 )
F_94 ( L_80 ,
F_16 ( type ) ) ;
V_3 [ type ] . V_19 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_59 = false ;
} else {
V_194 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_187 ,
L_81 ) ;
V_195 = - V_26 ;
goto V_65;
}
if ( F_1 () )
F_94 ( L_82 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_19 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_59 = true ;
}
}
for ( V_194 = strtok ( V_194 , L_83 ) ; V_194 ; V_194 = strtok ( NULL , L_83 ) ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_194 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 && strcmp ( V_194 , L_84 ) == 0 ) {
V_133 = true ;
continue;
}
if ( V_7 == V_8 ) {
fprintf ( V_187 , L_85 ) ;
V_195 = - V_26 ;
goto V_65;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_201 & V_9 [ V_7 ] . V_6 ) {
F_94 ( L_86 ,
V_9 [ V_7 ] . V_10 , F_16 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_201 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_187 , L_87 ,
V_9 [ V_7 ] . V_10 , F_16 ( type ) ) ;
V_195 = - V_26 ;
goto V_65;
}
V_3 [ type ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_19 == 0 ) {
F_7 ( L_88
L_89 , F_16 ( type ) ) ;
}
}
V_65:
free ( V_10 ) ;
return V_195 ;
}
static int F_95 ( const char * V_202 , const struct V_203 * V_204 )
{
char V_205 [ V_190 ] ;
struct V_206 V_207 ;
sprintf ( V_205 , L_90 , V_202 , V_204 -> V_208 ) ;
if ( V_206 ( V_205 , & V_207 ) )
return 0 ;
return F_96 ( V_207 . V_209 ) ;
}
static struct V_210 * F_97 ( const char * V_188 )
{
struct V_210 * V_184 = F_98 ( sizeof( * V_184 ) ) ;
if ( V_184 != NULL && V_188 )
V_184 -> V_188 = F_92 ( V_188 ) ;
return V_184 ;
}
static void F_99 ( struct V_210 * V_184 )
{
F_100 ( & V_184 -> V_188 ) ;
F_100 ( & V_184 -> V_211 ) ;
F_100 ( & V_184 -> args ) ;
free ( V_184 ) ;
}
static void F_101 ( struct V_210 * V_184 )
{
F_84 ( & V_184 -> V_185 , & V_212 ) ;
}
static struct V_210 * F_102 ( const char * V_188 )
{
struct V_210 * V_184 ;
F_86 (s, &script_descs, node)
if ( strcasecmp ( V_184 -> V_188 , V_188 ) == 0 )
return V_184 ;
return NULL ;
}
static struct V_210 * F_103 ( const char * V_188 )
{
struct V_210 * V_184 = F_102 ( V_188 ) ;
if ( V_184 )
return V_184 ;
V_184 = F_97 ( V_188 ) ;
if ( ! V_184 )
goto V_213;
F_101 ( V_184 ) ;
return V_184 ;
V_213:
F_99 ( V_184 ) ;
return NULL ;
}
static const char * F_104 ( const char * V_10 , const char * V_214 )
{
T_9 V_215 = strlen ( V_214 ) ;
const char * V_216 = V_10 ;
if ( strlen ( V_10 ) > V_215 ) {
V_216 = V_10 + strlen ( V_10 ) - V_215 ;
if ( ! strncmp ( V_216 , V_214 , V_215 ) )
return V_216 ;
}
return NULL ;
}
static int F_105 ( struct V_210 * V_217 , const char * V_218 )
{
char line [ V_219 ] , * V_216 ;
T_10 * V_220 ;
V_220 = fopen ( V_218 , L_91 ) ;
if ( ! V_220 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_220 ) ) {
V_216 = F_106 ( line ) ;
if ( strlen ( V_216 ) == 0 )
continue;
if ( * V_216 != '#' )
continue;
V_216 ++ ;
if ( strlen ( V_216 ) && * V_216 == '!' )
continue;
V_216 = F_106 ( V_216 ) ;
if ( strlen ( V_216 ) && V_216 [ strlen ( V_216 ) - 1 ] == '\n' )
V_216 [ strlen ( V_216 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_216 , L_92 , strlen ( L_92 ) ) ) {
V_216 += strlen ( L_92 ) ;
V_217 -> V_211 = F_92 ( F_106 ( V_216 ) ) ;
continue;
}
if ( ! strncmp ( V_216 , L_93 , strlen ( L_93 ) ) ) {
V_216 += strlen ( L_93 ) ;
V_217 -> args = F_92 ( F_106 ( V_216 ) ) ;
continue;
}
}
fclose ( V_220 ) ;
return 0 ;
}
static char * F_107 ( struct V_203 * V_221 , const char * V_214 )
{
char * V_222 , * V_10 ;
V_222 = F_92 ( V_221 -> V_208 ) ;
if ( ! V_222 )
return NULL ;
V_10 = ( char * ) F_104 ( V_222 , V_214 ) ;
if ( ! V_10 ) {
free ( V_222 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_222 ;
}
static int F_108 ( const struct V_189 * T_7 V_69 ,
const char * V_184 V_69 ,
int T_8 V_69 )
{
struct V_203 * V_223 , * V_224 , V_221 , V_225 ;
char V_226 [ V_227 ] ;
T_11 * V_228 , * V_229 ;
char V_230 [ V_227 ] ;
char V_231 [ V_227 ] ;
struct V_210 * V_217 ;
char V_232 [ V_219 ] ;
char * V_222 ;
snprintf ( V_226 , V_227 , L_94 , F_109 () ) ;
V_228 = F_110 ( V_226 ) ;
if ( ! V_228 )
return - 1 ;
F_111 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_231 , V_227 , L_95 , V_226 ,
V_225 . V_208 ) ;
V_229 = F_110 ( V_231 ) ;
if ( ! V_229 )
continue;
F_112 (lang_path, lang_dir, script_dirent, script_next) {
V_222 = F_107 ( & V_221 , V_233 ) ;
if ( V_222 ) {
V_217 = F_103 ( V_222 ) ;
snprintf ( V_230 , V_227 , L_90 ,
V_231 , V_221 . V_208 ) ;
F_105 ( V_217 , V_230 ) ;
free ( V_222 ) ;
}
}
}
fprintf ( stdout , L_96 ) ;
F_86 (desc, &script_descs, node) {
sprintf ( V_232 , L_97 , V_217 -> V_188 ,
V_217 -> args ? V_217 -> args : L_1 ) ;
fprintf ( stdout , L_98 , V_232 ,
V_217 -> V_211 ? V_217 -> V_211 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_113 ( char * V_234 , char * V_235 ,
struct V_20 * V_21 )
{
char V_218 [ V_227 ] , V_18 [ 128 ] ;
char line [ V_219 ] , * V_216 ;
struct V_11 * V_122 ;
int V_236 , V_126 ;
T_10 * V_220 ;
sprintf ( V_218 , L_99 , V_234 , V_235 ) ;
V_220 = fopen ( V_218 , L_91 ) ;
if ( ! V_220 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_220 ) ) {
V_216 = F_106 ( line ) ;
if ( * V_216 == '#' )
continue;
while ( strlen ( V_216 ) ) {
V_216 = strstr ( V_216 , L_100 ) ;
if ( ! V_216 )
break;
V_216 += 2 ;
V_216 = F_106 ( V_216 ) ;
V_126 = strcspn ( V_216 , L_101 ) ;
if ( ! V_126 )
break;
snprintf ( V_18 , V_126 + 1 , L_102 , V_216 ) ;
V_236 = 0 ;
F_17 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_122 ) , V_18 ) ) {
V_236 = 1 ;
break;
}
}
if ( ! V_236 ) {
fclose ( V_220 ) ;
return - 1 ;
}
}
}
fclose ( V_220 ) ;
return 0 ;
}
int F_114 ( char * * V_237 , char * * V_238 )
{
struct V_203 * V_223 , * V_224 , V_221 , V_225 ;
char V_226 [ V_227 ] , V_231 [ V_227 ] ;
T_11 * V_228 , * V_229 ;
struct V_20 * V_21 ;
struct V_239 V_240 = {
. V_205 = V_241 ,
. V_242 = V_243 ,
} ;
char * V_244 ;
int V_7 = 0 ;
V_21 = F_115 ( & V_240 , false , NULL ) ;
if ( ! V_21 )
return - 1 ;
snprintf ( V_226 , V_227 , L_94 , F_109 () ) ;
V_228 = F_110 ( V_226 ) ;
if ( ! V_228 ) {
F_116 ( V_21 ) ;
return - 1 ;
}
F_111 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_231 , V_227 , L_90 , V_226 ,
V_225 . V_208 ) ;
#ifdef F_117
if ( strstr ( V_231 , L_103 ) )
continue;
#endif
#ifdef F_118
if ( strstr ( V_231 , L_104 ) )
continue;
#endif
V_229 = F_110 ( V_231 ) ;
if ( ! V_229 )
continue;
F_112 (lang_path, lang_dir, script_dirent, script_next) {
if ( strstr ( V_221 . V_208 , L_105 ) )
continue;
sprintf ( V_238 [ V_7 ] , L_90 , V_231 ,
V_221 . V_208 ) ;
V_244 = strchr ( V_221 . V_208 , '.' ) ;
snprintf ( V_237 [ V_7 ] ,
( V_244 - V_221 . V_208 ) + 1 ,
L_102 , V_221 . V_208 ) ;
if ( F_113 ( V_231 ,
V_237 [ V_7 ] , V_21 ) )
continue;
V_7 ++ ;
}
F_119 ( V_229 ) ;
}
F_119 ( V_228 ) ;
F_116 ( V_21 ) ;
return V_7 ;
}
static char * F_120 ( const char * V_222 , const char * V_214 )
{
struct V_203 * V_223 , * V_224 , V_221 , V_225 ;
char V_226 [ V_227 ] ;
char V_230 [ V_227 ] ;
T_11 * V_228 , * V_229 ;
char V_231 [ V_227 ] ;
char * V_245 ;
snprintf ( V_226 , V_227 , L_94 , F_109 () ) ;
V_228 = F_110 ( V_226 ) ;
if ( ! V_228 )
return NULL ;
F_111 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_231 , V_227 , L_95 , V_226 ,
V_225 . V_208 ) ;
V_229 = F_110 ( V_231 ) ;
if ( ! V_229 )
continue;
F_112 (lang_path, lang_dir, script_dirent, script_next) {
V_245 = F_107 ( & V_221 , V_214 ) ;
if ( V_245 && ! strcmp ( V_222 , V_245 ) ) {
free ( V_245 ) ;
F_119 ( V_229 ) ;
F_119 ( V_228 ) ;
snprintf ( V_230 , V_227 , L_90 ,
V_231 , V_221 . V_208 ) ;
return F_92 ( V_230 ) ;
}
free ( V_245 ) ;
}
F_119 ( V_229 ) ;
}
F_119 ( V_228 ) ;
return NULL ;
}
static bool F_121 ( const char * V_230 )
{
return F_104 ( V_230 , L_106 ) == NULL ? false : true ;
}
static int F_122 ( char * V_230 )
{
struct V_210 * V_217 ;
int V_246 = 0 ;
char * V_216 ;
V_217 = F_97 ( NULL ) ;
if ( F_105 ( V_217 , V_230 ) )
goto V_65;
if ( ! V_217 -> args )
goto V_65;
for ( V_216 = V_217 -> args ; * V_216 ; V_216 ++ )
if ( * V_216 == '<' )
V_246 ++ ;
V_65:
F_99 ( V_217 ) ;
return V_246 ;
}
static int F_123 ( int V_247 , const char * * V_248 )
{
char * * V_249 = malloc ( sizeof( const char * ) * V_247 ) ;
if ( ! V_249 ) {
F_6 ( L_107 ) ;
return - 1 ;
}
memcpy ( V_249 , V_248 , sizeof( const char * ) * V_247 ) ;
V_247 = F_124 ( V_247 , ( const char * * ) V_249 , V_250 ,
NULL , V_251 ) ;
free ( V_249 ) ;
V_145 = ( V_247 == 0 ) ;
return 0 ;
}
static void F_125 ( struct V_127 * V_128 )
{
struct V_20 * V_21 = V_128 -> V_21 ;
T_1 V_13 = F_126 ( V_21 -> V_124 ) ;
if ( V_63 . V_61 || V_63 . V_252 ) {
if ( ( V_13 & V_253 ) &&
( V_13 & V_254 ) )
V_255 . V_256 = V_257 ;
else if ( V_13 & V_258 )
V_255 . V_256 = V_259 ;
else
V_255 . V_256 = V_260 ;
}
}
static int F_127 ( struct V_155 * V_156 V_69 ,
union V_68 * T_2 ,
struct V_20 * V_21 )
{
struct V_261 * V_262 = & T_2 -> V_263 ;
struct V_11 * V_139 ;
F_17 (session->evlist, counter) {
F_128 ( & V_152 , V_139 ) ;
F_48 ( V_139 , V_262 -> time ) ;
}
F_49 ( V_262 -> time ) ;
return 0 ;
}
static int F_129 ( struct V_155 * V_156 V_69 ,
union V_68 * T_2 ,
struct V_20 * V_21 V_69 )
{
F_130 ( & V_152 , & T_2 -> V_152 ) ;
return 0 ;
}
static int F_131 ( struct V_127 * V_128 )
{
struct V_123 * V_124 = V_128 -> V_21 -> V_124 ;
if ( ! V_128 -> V_148 || ! V_128 -> V_142 )
return 0 ;
if ( F_132 ( V_128 -> V_264 , L_108 ) )
return - V_26 ;
F_133 ( V_124 , V_128 -> V_148 , V_128 -> V_142 ) ;
if ( F_134 ( V_124 , true ) )
return - V_196 ;
V_128 -> V_264 = true ;
return 0 ;
}
static
int F_135 ( struct V_155 * V_156 ,
union V_68 * T_2 ,
struct V_20 * V_21 V_69 )
{
struct V_127 * V_128 = F_56 ( V_156 , struct V_127 , V_156 ) ;
if ( V_128 -> V_142 ) {
F_94 ( L_109 ) ;
return 0 ;
}
V_128 -> V_142 = F_136 ( & T_2 -> V_265 ) ;
if ( ! V_128 -> V_142 )
return - V_196 ;
return F_131 ( V_128 ) ;
}
static
int F_137 ( struct V_155 * V_156 V_69 ,
union V_68 * T_2 ,
struct V_20 * V_21 V_69 )
{
struct V_127 * V_128 = F_56 ( V_156 , struct V_127 , V_156 ) ;
if ( V_128 -> V_148 ) {
F_94 ( L_110 ) ;
return 0 ;
}
V_128 -> V_148 = F_138 ( & T_2 -> V_266 . V_267 ) ;
if ( ! V_128 -> V_148 )
return - V_196 ;
return F_131 ( V_128 ) ;
}
int F_139 ( int V_247 , const char * * V_248 , const char * T_12 V_69 )
{
bool V_268 = false ;
bool V_22 = false ;
bool V_269 = false ;
bool V_270 = false ;
char * V_271 = NULL ;
char * V_272 = NULL ;
struct V_20 * V_21 ;
struct V_273 V_273 = { . V_274 = false , } ;
char * V_230 = NULL ;
const char * * V_249 ;
int V_7 , V_1 , V_167 = 0 ;
struct V_127 V_128 = {
. V_156 = {
. V_71 = F_55 ,
. V_173 = F_74 ,
. V_174 = F_76 ,
. V_170 = F_66 ,
. exit = F_72 ,
. V_172 = F_70 ,
. V_17 = F_60 ,
. V_275 = V_276 ,
. V_277 = V_278 ,
. V_279 = V_280 ,
. V_281 = V_282 ,
. V_283 = V_284 ,
. V_285 = V_286 ,
. V_206 = V_287 ,
. V_263 = F_127 ,
. V_152 = F_129 ,
. V_265 = F_135 ,
. V_266 = F_137 ,
. V_288 = true ,
. V_289 = true ,
} ,
} ;
struct V_239 V_240 = {
. V_242 = V_243 ,
} ;
const struct V_189 V_290 [] = {
F_140 ( 'D' , L_111 , & V_291 ,
L_112 ) ,
F_141 ( 'v' , L_113 , & V_292 ,
L_114 ) ,
F_140 ( 'L' , L_115 , & V_85 ,
L_116 ) ,
F_142 ( 'l' , L_117 , NULL , NULL , L_118 ,
F_108 ) ,
F_143 ( 's' , L_119 , NULL , L_120 ,
L_121 ,
F_91 ) ,
F_144 ( 'g' , L_122 , & V_293 , L_71 ,
L_123 ) ,
F_144 ( 'i' , L_124 , & V_241 , L_125 , L_126 ) ,
F_140 ( 'd' , L_127 , & V_159 ,
L_128 ) ,
F_140 ( 0 , L_129 , & V_22 , L_130 ) ,
F_140 ( 0 , L_131 , & V_269 , L_132 ) ,
F_144 ( 'k' , L_133 , & V_63 . V_294 ,
L_125 , L_134 ) ,
F_144 ( 0 , L_135 , & V_63 . V_295 ,
L_125 , L_136 ) ,
F_140 ( 'G' , L_137 , & V_60 ,
L_138 ) ,
F_144 ( 0 , L_139 , & V_63 . V_296 , L_140 ,
L_141 ) ,
F_143 ( 'F' , L_142 , NULL , L_143 ,
L_144
L_145
L_146
L_147 , F_93 ) ,
F_140 ( 'a' , L_148 , & V_145 ,
L_149 ) ,
F_144 ( 'S' , L_150 , & V_63 . V_297 , L_151 ,
L_152 ) ,
F_144 ( 'C' , L_153 , & V_164 , L_153 , L_154 ) ,
F_144 ( 'c' , L_155 , & V_63 . V_298 , L_156 ,
L_157 ) ,
F_144 ( 0 , L_158 , & V_63 . V_299 , L_159 ,
L_160 ) ,
F_144 ( 0 , L_161 , & V_63 . V_300 , L_162 ,
L_163 ) ,
F_140 ( 'I' , L_164 , & V_268 ,
L_165 ) ,
F_140 ( '\0' , L_166 , & V_63 . V_301 ,
L_167 ) ,
F_140 ( '\0' , L_168 , & V_128 . V_177 ,
L_169 ) ,
F_140 ( '\0' , L_170 , & V_128 . V_178 ,
L_171 ) ,
F_140 ( '\0' , L_172 , & V_128 . V_179 ,
L_173 ) ,
F_140 ( 'f' , L_174 , & V_240 . V_302 , L_175 ) ,
F_140 ( 0 , L_176 , & V_91 ,
L_177 ) ,
F_145 ( 0 , L_178 , & V_273 , NULL , L_179 ,
L_180 ,
V_303 ) ,
F_140 ( 0 , L_181 , & V_304 ,
L_182 ) ,
F_140 ( 0 , L_183 , & V_63 . V_305 ,
L_184 ) ,
F_140 ( 0 , L_185 , & V_63 . V_306 ,
L_186 ) ,
F_146 ()
} ;
const char * const V_307 [] = { L_187 , L_188 , NULL } ;
const char * V_308 [] = {
L_189 ,
L_190 ,
L_191 ,
L_192 ,
L_193 ,
NULL
} ;
F_50 () ;
V_247 = F_147 ( V_247 , V_248 , V_290 , V_307 , V_308 ,
V_251 ) ;
V_240 . V_205 = V_241 ;
if ( V_247 > 1 && ! strncmp ( V_248 [ 0 ] , L_194 , strlen ( L_194 ) ) ) {
V_271 = F_120 ( V_248 [ 1 ] , V_309 ) ;
if ( ! V_271 )
return F_148 ( V_247 , V_248 , NULL ) ;
}
if ( V_247 > 1 && ! strncmp ( V_248 [ 0 ] , L_195 , strlen ( L_195 ) ) ) {
V_272 = F_120 ( V_248 [ 1 ] , V_233 ) ;
if ( ! V_272 ) {
fprintf ( V_187 ,
L_196
L_197 ) ;
return - 1 ;
}
}
if ( V_273 . V_117 &&
V_273 . V_310 > V_118 )
V_118 = V_273 . V_310 ;
F_149 ( F_109 () ) ;
if ( V_247 && ! V_192 && ! V_271 && ! V_272 ) {
int V_311 [ 2 ] ;
int V_312 ;
T_13 V_86 ;
V_271 = F_120 ( V_248 [ 0 ] , V_309 ) ;
V_272 = F_120 ( V_248 [ 0 ] , V_233 ) ;
if ( ! V_271 && ! V_272 ) {
F_150 ( V_308 , V_290 ,
L_198
L_199 , V_248 [ 0 ] ) ;
}
if ( F_121 ( V_248 [ 0 ] ) ) {
V_312 = V_247 - 1 ;
} else {
int V_313 ;
V_312 = F_122 ( V_272 ) ;
V_313 = ( V_247 - 1 ) - V_312 ;
if ( V_313 < 0 ) {
F_150 ( V_308 , V_290 ,
L_200
L_201
L_202 , V_248 [ 0 ] ) ;
}
}
if ( F_151 ( V_311 ) < 0 ) {
perror ( L_203 ) ;
return - 1 ;
}
V_86 = V_172 () ;
if ( V_86 < 0 ) {
perror ( L_204 ) ;
return - 1 ;
}
if ( ! V_86 ) {
V_1 = 0 ;
F_152 ( V_311 [ 1 ] , 1 ) ;
F_153 ( V_311 [ 0 ] ) ;
if ( F_121 ( V_248 [ 0 ] ) ) {
V_145 = true ;
} else if ( ! V_145 ) {
if ( F_123 ( V_247 - V_312 , & V_248 [ V_312 ] ) != 0 ) {
V_167 = - 1 ;
goto V_65;
}
}
V_249 = malloc ( ( V_247 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_249 ) {
F_6 ( L_107 ) ;
V_167 = - V_196 ;
goto V_65;
}
V_249 [ V_1 ++ ] = L_205 ;
V_249 [ V_1 ++ ] = V_271 ;
if ( V_145 )
V_249 [ V_1 ++ ] = L_206 ;
V_249 [ V_1 ++ ] = L_207 ;
V_249 [ V_1 ++ ] = L_208 ;
V_249 [ V_1 ++ ] = L_209 ;
for ( V_7 = V_312 + 1 ; V_7 < V_247 ; V_7 ++ )
V_249 [ V_1 ++ ] = V_248 [ V_7 ] ;
V_249 [ V_1 ++ ] = NULL ;
F_154 ( L_205 , ( char * * ) V_249 ) ;
free ( V_249 ) ;
exit ( - 1 ) ;
}
F_152 ( V_311 [ 0 ] , 0 ) ;
F_153 ( V_311 [ 1 ] ) ;
V_249 = malloc ( ( V_247 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_249 ) {
F_6 ( L_107 ) ;
V_167 = - V_196 ;
goto V_65;
}
V_1 = 0 ;
V_249 [ V_1 ++ ] = L_205 ;
V_249 [ V_1 ++ ] = V_272 ;
for ( V_7 = 1 ; V_7 < V_312 + 1 ; V_7 ++ )
V_249 [ V_1 ++ ] = V_248 [ V_7 ] ;
V_249 [ V_1 ++ ] = L_210 ;
V_249 [ V_1 ++ ] = L_209 ;
V_249 [ V_1 ++ ] = NULL ;
F_154 ( L_205 , ( char * * ) V_249 ) ;
free ( V_249 ) ;
exit ( - 1 ) ;
}
if ( V_271 )
V_230 = V_271 ;
if ( V_272 )
V_230 = V_272 ;
if ( V_230 ) {
V_1 = 0 ;
if ( ! V_271 )
V_145 = false ;
else if ( ! V_145 ) {
if ( F_123 ( V_247 - 1 , & V_248 [ 1 ] ) != 0 ) {
V_167 = - 1 ;
goto V_65;
}
}
V_249 = malloc ( ( V_247 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_249 ) {
F_6 ( L_107 ) ;
V_167 = - V_196 ;
goto V_65;
}
V_249 [ V_1 ++ ] = L_205 ;
V_249 [ V_1 ++ ] = V_230 ;
if ( V_145 )
V_249 [ V_1 ++ ] = L_206 ;
for ( V_7 = 2 ; V_7 < V_247 ; V_7 ++ )
V_249 [ V_1 ++ ] = V_248 [ V_7 ] ;
V_249 [ V_1 ++ ] = NULL ;
F_154 ( L_205 , ( char * * ) V_249 ) ;
free ( V_249 ) ;
exit ( - 1 ) ;
}
if ( ! V_192 )
F_155 () ;
V_21 = F_115 ( & V_240 , false , & V_128 . V_156 ) ;
if ( V_21 == NULL )
return - 1 ;
if ( V_22 || V_269 ) {
F_156 ( V_21 , stdout , V_268 ) ;
if ( V_269 )
goto V_314;
}
if ( F_157 ( & V_21 -> V_22 . V_315 ) < 0 )
goto V_314;
V_128 . V_21 = V_21 ;
F_125 ( & V_128 ) ;
V_21 -> V_273 = & V_273 ;
if ( V_164 ) {
V_167 = F_158 ( V_21 , V_164 , V_165 ) ;
if ( V_167 < 0 )
goto V_314;
}
if ( ! V_60 )
V_63 . V_61 = true ;
else
V_63 . V_61 = false ;
if ( V_21 -> V_316 . V_317 &&
F_159 ( V_21 -> V_316 . V_317 ,
V_318 ,
& V_21 -> V_319 . V_320 ) < 0 ) {
F_6 ( L_211 , V_321 ) ;
return - 1 ;
}
if ( V_293 ) {
struct V_206 V_322 ;
int V_323 ;
if ( F_1 () ) {
fprintf ( V_187 ,
L_212 ) ;
V_167 = - V_26 ;
goto V_314;
}
V_323 = F_160 ( V_240 . V_205 , V_324 ) ;
if ( V_323 < 0 ) {
V_167 = - V_325 ;
perror ( L_213 ) ;
goto V_314;
}
V_167 = F_161 ( V_323 , & V_322 ) ;
if ( V_167 < 0 ) {
perror ( L_214 ) ;
goto V_314;
}
if ( ! V_322 . V_326 ) {
fprintf ( V_187 , L_215 ) ;
goto V_314;
}
V_151 = F_89 ( V_293 ) ;
if ( ! V_151 ) {
fprintf ( V_187 , L_72 ) ;
V_167 = - V_327 ;
goto V_314;
}
V_167 = V_151 -> V_328 ( V_21 -> V_316 . V_317 ,
L_216 ) ;
goto V_314;
}
if ( V_192 ) {
V_167 = V_151 -> V_329 ( V_192 , V_247 , V_248 ) ;
if ( V_167 )
goto V_314;
F_7 ( L_217 , V_192 ) ;
V_270 = true ;
}
V_167 = F_14 ( V_21 ) ;
if ( V_167 < 0 )
goto V_314;
V_167 = F_80 ( & V_128 ) ;
F_53 () ;
V_314:
F_162 ( V_21 -> V_124 ) ;
F_116 ( V_21 ) ;
if ( V_270 )
F_54 () ;
V_65:
return V_167 ;
}
