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
if ( F_11 ( V_33 ) &&
F_8 ( V_12 , V_34 , L_8 ,
V_35 ) )
return - V_26 ;
if ( F_11 ( V_36 ) &&
F_8 ( V_12 , V_37 , L_9 ,
V_38 ) )
return - V_26 ;
if ( F_11 ( V_39 ) && ! F_11 ( V_27 ) && ! F_11 ( V_30 ) ) {
F_6 ( L_10
L_11
L_12 ) ;
return - V_26 ;
}
if ( F_11 ( V_40 ) && ! F_11 ( V_39 ) ) {
F_6 ( L_13
L_14 ) ;
return - V_26 ;
}
if ( F_11 ( V_41 ) && ! F_11 ( V_27 ) && ! F_11 ( V_30 ) ) {
F_6 ( L_15
L_11
L_16 ) ;
return - V_26 ;
}
if ( F_11 ( V_42 ) && ! F_11 ( V_27 ) ) {
F_6 ( L_17
L_18 ) ;
return - V_26 ;
}
if ( ( F_11 ( V_43 ) || F_11 ( V_44 ) ) &&
F_8 ( V_12 , V_45 , L_19 ,
V_46 | V_47 ) )
return - V_26 ;
if ( F_11 ( TIME ) &&
F_8 ( V_12 , V_48 , L_20 ,
V_49 ) )
return - V_26 ;
if ( F_11 ( V_50 ) &&
F_4 ( V_12 , V_51 , L_21 ,
V_52 , V_15 ) )
return - V_26 ;
if ( F_11 ( V_53 ) &&
F_8 ( V_12 , V_54 , L_22 ,
V_55 ) )
return - V_26 ;
if ( F_11 ( V_56 ) &&
F_8 ( V_12 , V_57 , L_23 ,
V_58 ) )
return - V_26 ;
return 0 ;
}
static void F_13 ( struct V_16 * V_17 )
{
unsigned int type = V_17 -> type ;
V_3 [ type ] . V_59 = 0 ;
if ( F_11 ( V_27 ) )
V_3 [ type ] . V_59 |= V_60 ;
if ( F_11 ( V_39 ) )
V_3 [ type ] . V_59 |= V_61 ;
if ( F_11 ( V_41 ) )
V_3 [ type ] . V_59 |= V_62 ;
if ( F_11 ( V_40 ) )
V_3 [ type ] . V_59 |= V_63 ;
if ( F_11 ( V_42 ) )
V_3 [ type ] . V_59 |= V_64 ;
}
static int F_14 ( struct V_20 * V_21 )
{
int V_1 ;
struct V_11 * V_12 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_12 = F_15 ( V_21 , V_1 ) ;
if ( ! V_12 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_65 ) {
F_6 ( L_24
L_25 ,
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
if ( ! V_66 ) {
bool V_67 = false ;
F_17 (session->evlist, evsel) {
if ( V_12 -> V_17 . V_13 & V_68 ) {
V_67 = true ;
break;
}
}
if ( ! V_67 )
V_69 . V_67 = false ;
}
if ( V_69 . V_67 &&
! V_3 [ V_70 ] . V_4 ) {
struct V_16 * V_17 ;
V_1 = V_70 ;
V_12 = F_15 ( V_21 , V_1 ) ;
if ( V_12 == NULL )
goto V_71;
V_17 = & V_12 -> V_17 ;
if ( V_17 -> V_13 & V_68 ) {
V_3 [ V_1 ] . V_19 |= V_29 ;
V_3 [ V_1 ] . V_19 |= V_72 ;
V_3 [ V_1 ] . V_19 |= V_73 ;
F_13 ( V_17 ) ;
}
}
V_71:
return 0 ;
}
static void F_18 ( struct V_74 * V_75 ,
struct V_16 * V_17 )
{
struct V_76 * V_77 = & V_75 -> V_78 ;
T_2 V_79 = V_17 -> V_80 ;
unsigned V_7 = 0 , V_81 ;
if ( ! V_77 )
return;
F_19 (r, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_1 V_82 = V_77 -> V_77 [ V_7 ++ ] ;
printf ( L_26 V_83 L_27 , F_20 ( V_81 ) , V_82 ) ;
}
}
static void F_21 ( struct V_74 * V_75 ,
struct V_84 * V_84 ,
struct V_11 * V_12 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
unsigned long V_85 ;
unsigned long V_86 ;
unsigned long long V_87 ;
if ( F_11 ( V_88 ) ) {
if ( V_89 )
printf ( L_28 , F_22 ( V_84 ) ) ;
else if ( F_11 ( V_27 ) && V_69 . V_67 )
printf ( L_29 , F_22 ( V_84 ) ) ;
else
printf ( L_30 , F_22 ( V_84 ) ) ;
}
if ( F_11 ( V_43 ) && F_11 ( V_44 ) )
printf ( L_31 , V_75 -> V_90 , V_75 -> V_91 ) ;
else if ( F_11 ( V_43 ) )
printf ( L_32 , V_75 -> V_90 ) ;
else if ( F_11 ( V_44 ) )
printf ( L_32 , V_75 -> V_91 ) ;
if ( F_11 ( V_50 ) ) {
if ( V_89 )
printf ( L_33 , V_75 -> V_92 ) ;
else
printf ( L_34 , V_75 -> V_92 ) ;
}
if ( F_11 ( TIME ) ) {
V_87 = V_75 -> time ;
V_85 = V_87 / V_93 ;
V_87 -= V_85 * V_93 ;
V_86 = V_87 / V_94 ;
if ( V_95 )
printf ( L_35 , V_85 , V_87 ) ;
else
printf ( L_36 , V_85 , V_86 ) ;
}
}
static inline char
F_23 ( struct V_96 * V_97 )
{
if ( ! ( V_97 -> V_98 . V_99 || V_97 -> V_98 . V_100 ) )
return '-' ;
return V_97 -> V_98 . V_100 ? 'P' : 'M' ;
}
static void F_24 ( struct V_74 * V_75 )
{
struct V_101 * V_97 = V_75 -> V_101 ;
T_1 V_7 ;
if ( ! ( V_97 && V_97 -> V_102 ) )
return;
for ( V_7 = 0 ; V_7 < V_97 -> V_102 ; V_7 ++ ) {
printf ( L_37 V_83 L_38 V_83 L_39 ,
V_97 -> V_103 [ V_7 ] . V_104 ,
V_97 -> V_103 [ V_7 ] . V_105 ,
F_23 ( V_97 -> V_103 + V_7 ) ,
V_97 -> V_103 [ V_7 ] . V_98 . V_106 ? 'X' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . abort ? 'A' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . V_107 ) ;
}
}
static void F_25 ( struct V_74 * V_75 ,
struct V_84 * V_84 )
{
struct V_101 * V_97 = V_75 -> V_101 ;
struct V_108 V_109 , V_110 ;
T_1 V_7 , V_104 , V_105 ;
if ( ! ( V_97 && V_97 -> V_102 ) )
return;
for ( V_7 = 0 ; V_7 < V_97 -> V_102 ; V_7 ++ ) {
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_104 = V_97 -> V_103 [ V_7 ] . V_104 ;
V_105 = V_97 -> V_103 [ V_7 ] . V_105 ;
F_26 ( V_84 , V_75 -> V_111 , V_112 , V_104 , & V_109 ) ;
if ( V_109 . V_113 )
V_109 . V_114 = F_27 ( V_109 . V_113 , V_109 . V_115 , NULL ) ;
F_26 ( V_84 , V_75 -> V_111 , V_112 , V_105 , & V_110 ) ;
if ( V_110 . V_113 )
V_110 . V_114 = F_27 ( V_110 . V_113 , V_110 . V_115 , NULL ) ;
F_28 ( V_109 . V_114 , & V_109 , stdout ) ;
putchar ( '/' ) ;
F_28 ( V_110 . V_114 , & V_110 , stdout ) ;
printf ( L_39 ,
F_23 ( V_97 -> V_103 + V_7 ) ,
V_97 -> V_103 [ V_7 ] . V_98 . V_106 ? 'X' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . abort ? 'A' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . V_107 ) ;
}
}
static void F_29 ( struct V_74 * V_75 ,
struct V_84 * V_84 ,
struct V_16 * V_17 )
{
struct V_108 V_116 ;
printf ( L_40 V_83 , V_75 -> V_115 ) ;
if ( ! F_30 ( V_17 ) )
return;
F_31 ( V_84 , & V_116 , V_75 ) ;
if ( F_11 ( V_39 ) ) {
printf ( L_27 ) ;
if ( F_11 ( V_40 ) )
F_28 ( V_116 . V_114 , & V_116 , stdout ) ;
else
F_32 ( V_116 . V_114 , stdout ) ;
}
if ( F_11 ( V_41 ) ) {
printf ( L_41 ) ;
F_33 ( V_116 . V_113 , stdout ) ;
printf ( L_42 ) ;
}
}
static void F_34 ( struct V_74 * V_75 ,
struct V_11 * V_12 ,
struct V_84 * V_84 ,
struct V_108 * V_116 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_117 = false ;
if ( F_11 ( V_27 ) ) {
unsigned int V_118 = V_3 [ V_17 -> type ] . V_59 ;
if ( V_69 . V_67 && V_75 -> V_119 ) {
printf ( L_43 ) ;
} else {
printf ( L_27 ) ;
if ( V_118 & V_64 ) {
V_117 = true ;
V_118 &= ~ V_64 ;
}
}
F_35 ( V_12 , V_75 , V_116 , V_118 ,
V_120 ) ;
}
if ( F_11 ( V_30 ) ||
( ( V_12 -> V_17 . V_13 & V_31 ) &&
! V_3 [ V_17 -> type ] . V_4 ) ) {
printf ( L_44 ) ;
F_29 ( V_75 , V_84 , V_17 ) ;
}
if ( V_117 )
F_36 ( V_116 -> V_113 , V_116 -> V_115 , L_45 , stdout ) ;
printf ( L_43 ) ;
}
static void F_37 ( T_3 V_98 )
{
const char * V_121 = V_122 ;
const int V_123 = strlen ( V_122 ) ;
char V_10 [ 33 ] ;
int V_7 , V_124 = 0 ;
for ( V_7 = 0 ; V_7 < V_123 ; V_7 ++ , V_98 >>= 1 ) {
if ( V_98 & 1 )
V_10 [ V_124 ++ ] = V_121 [ V_7 ] ;
}
for (; V_7 < 32 ; V_7 ++ , V_98 >>= 1 ) {
if ( V_98 & 1 )
V_10 [ V_124 ++ ] = '?' ;
}
V_10 [ V_124 ] = 0 ;
printf ( L_46 , V_10 ) ;
}
static void
F_38 ( enum V_125 V_126 ,
unsigned int V_82 ,
void * V_127 )
{
unsigned char V_128 = ( unsigned char ) V_82 ;
struct V_129 * V_129 = V_127 ;
switch ( V_126 ) {
case V_130 :
printf ( L_43 ) ;
break;
case V_131 :
printf ( L_47 , ! V_129 -> V_132 ? L_48 :
L_49 ) ;
break;
case V_133 :
printf ( L_50 , V_82 ) ;
break;
case V_134 :
printf ( L_51 , V_82 ) ;
break;
case V_135 :
printf ( L_52 ) ;
break;
case V_136 :
printf ( L_53 ) ;
break;
case V_137 :
if ( V_129 -> V_138 && V_128 )
V_129 -> V_139 = false ;
if ( ! isprint ( V_128 ) ) {
printf ( L_54 , '.' ) ;
if ( ! V_129 -> V_139 )
break;
if ( V_128 == '\0' )
V_129 -> V_138 = true ;
else
V_129 -> V_139 = false ;
} else {
printf ( L_54 , V_128 ) ;
}
break;
case V_140 :
printf ( L_27 ) ;
break;
case V_141 :
printf ( L_43 ) ;
V_129 -> V_132 ++ ;
break;
case V_142 :
default:
break;
}
}
static void F_39 ( struct V_74 * V_75 )
{
unsigned int V_143 = V_75 -> V_144 ;
struct V_129 V_129 = { 0 , false , true } ;
F_40 ( V_75 -> V_145 , V_143 , 8 ,
F_38 , & V_129 ) ;
if ( V_129 . V_139 && V_129 . V_138 )
printf ( L_55 , L_56 ,
( char * ) ( V_75 -> V_145 ) ) ;
}
static int F_41 ( struct V_146 * V_147 )
{
struct V_11 * V_12 ;
int V_148 = 0 ;
F_17 (evlist, evsel) {
int V_149 = strlen ( F_5 ( V_12 ) ) ;
V_148 = F_42 ( V_149 , V_148 ) ;
}
return V_148 ;
}
static T_4 F_43 ( T_1 V_150 )
{
struct V_151 V_152 = { . V_150 . V_82 = V_150 } ;
char V_153 [ 100 ] ;
char V_71 [ 100 ] ;
static int V_154 ;
int V_149 ;
F_44 ( V_153 , 100 , & V_152 ) ;
V_149 = F_45 ( V_71 , 100 , L_40 V_83 L_57 , V_150 , V_153 ) ;
if ( V_154 < V_149 )
V_154 = V_149 ;
return printf ( L_58 , V_154 , V_71 ) ;
}
static void F_46 ( struct V_155 * V_156 ,
struct V_74 * V_75 , struct V_11 * V_12 ,
struct V_108 * V_116 )
{
struct V_84 * V_84 = V_116 -> V_84 ;
struct V_16 * V_17 = & V_12 -> V_17 ;
if ( V_3 [ V_17 -> type ] . V_19 == 0 )
return;
F_21 ( V_75 , V_84 , V_12 ) ;
if ( F_11 ( V_53 ) )
printf ( L_59 V_157 L_27 , V_75 -> V_158 ) ;
if ( F_11 ( V_159 ) ) {
const char * V_18 = F_5 ( V_12 ) ;
if ( ! V_156 -> V_160 )
V_156 -> V_160 = F_41 ( V_156 -> V_21 -> V_147 ) ;
printf ( L_60 , V_156 -> V_160 ,
V_18 ? V_18 : L_61 ) ;
}
if ( V_161 )
F_37 ( V_75 -> V_98 ) ;
if ( F_47 ( V_17 ) ) {
F_34 ( V_75 , V_12 , V_84 , V_116 ) ;
return;
}
if ( F_11 ( V_25 ) )
F_48 ( V_12 -> V_162 , V_75 -> V_92 ,
V_75 -> V_145 , V_75 -> V_144 ) ;
if ( F_11 ( V_30 ) )
F_29 ( V_75 , V_84 , V_17 ) ;
if ( F_11 ( V_33 ) )
F_43 ( V_75 -> V_150 ) ;
if ( F_11 ( V_36 ) )
printf ( L_40 V_157 , V_75 -> V_163 ) ;
if ( F_11 ( V_27 ) ) {
if ( ! V_69 . V_67 )
printf ( L_27 ) ;
else
printf ( L_43 ) ;
F_35 ( V_12 , V_75 , V_116 ,
V_3 [ V_17 -> type ] . V_59 ,
V_120 ) ;
}
if ( F_11 ( V_56 ) )
F_18 ( V_75 , V_17 ) ;
if ( F_11 ( V_164 ) )
F_24 ( V_75 ) ;
else if ( F_11 ( V_165 ) )
F_25 ( V_75 , V_84 ) ;
if ( F_49 ( V_12 ) && F_11 ( V_166 ) )
F_39 ( V_75 ) ;
printf ( L_43 ) ;
}
static void F_50 ( struct V_11 * V_167 , T_1 V_168 )
{
int V_169 = F_51 ( V_167 -> V_170 ) ;
int V_171 = F_52 ( V_167 ) ;
int V_92 , V_84 ;
static int V_172 ;
if ( V_167 -> V_173 )
V_169 = 1 ;
if ( ! V_172 ) {
printf ( L_62 ,
L_21 , L_63 , L_64 , L_65 , L_66 , L_20 , L_67 ) ;
V_172 = 1 ;
}
for ( V_84 = 0 ; V_84 < V_169 ; V_84 ++ ) {
for ( V_92 = 0 ; V_92 < V_171 ; V_92 ++ ) {
struct V_174 * V_175 ;
V_175 = F_53 ( V_167 -> V_175 , V_92 , V_84 ) ;
printf ( L_68 V_157 L_69 V_157 L_69 V_157 L_69 V_157 L_70 ,
V_167 -> V_176 -> V_113 [ V_92 ] ,
F_54 ( V_167 -> V_170 , V_84 ) ,
V_175 -> V_82 ,
V_175 -> V_177 ,
V_175 -> V_178 ,
V_168 ,
F_5 ( V_167 ) ) ;
}
}
}
static void F_55 ( struct V_11 * V_167 , T_1 V_168 )
{
if ( V_179 && V_179 -> F_55 )
V_179 -> F_55 ( & V_180 , V_167 , V_168 ) ;
else
F_50 ( V_167 , V_168 ) ;
}
static void F_56 ( T_1 V_168 )
{
if ( V_179 && V_179 -> F_56 )
V_179 -> F_56 ( V_168 ) ;
}
static void F_57 ( void )
{
F_58 () ;
F_59 () ;
}
static int F_60 ( void )
{
return V_179 ? V_179 -> V_181 () : 0 ;
}
static int F_61 ( void )
{
F_7 ( L_71 ) ;
return V_179 ? V_179 -> V_182 () : 0 ;
}
static int F_62 ( struct V_183 * V_184 ,
union V_185 * V_186 ,
struct V_74 * V_75 ,
struct V_11 * V_12 ,
struct V_187 * V_187 )
{
struct V_155 * V_188 = F_63 ( V_184 , struct V_155 , V_184 ) ;
struct V_108 V_116 ;
if ( V_189 ) {
if ( V_75 -> time < V_190 ) {
F_6 ( L_72 V_157
L_73 V_157 L_43 , V_190 ,
V_75 -> time ) ;
V_191 ++ ;
}
V_190 = V_75 -> time ;
return 0 ;
}
if ( F_64 ( V_187 , & V_116 , V_75 ) < 0 ) {
F_6 ( L_74 ,
V_186 -> V_22 . type ) ;
return - 1 ;
}
if ( V_116 . V_192 )
goto V_193;
if ( V_194 && ! F_65 ( V_75 -> V_92 , V_195 ) )
goto V_193;
if ( V_179 )
V_179 -> F_46 ( V_186 , V_75 , V_12 , & V_116 ) ;
else
F_46 ( V_188 , V_75 , V_12 , & V_116 ) ;
V_193:
F_66 ( & V_116 ) ;
return 0 ;
}
static int F_67 ( struct V_183 * V_184 , union V_185 * V_186 ,
struct V_146 * * V_196 )
{
struct V_155 * V_188 = F_63 ( V_184 , struct V_155 , V_184 ) ;
struct V_146 * V_147 ;
struct V_11 * V_12 , * V_124 ;
int V_197 ;
V_197 = F_68 ( V_184 , V_186 , V_196 ) ;
if ( V_197 )
return V_197 ;
V_147 = * V_196 ;
V_12 = F_69 ( * V_196 ) ;
if ( V_12 -> V_17 . type >= V_2 )
return 0 ;
F_17 (evlist, pos) {
if ( V_124 -> V_17 . type == V_12 -> V_17 . type && V_124 != V_12 )
return 0 ;
}
F_13 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_17 . V_13 )
V_197 = F_9 ( V_12 , V_188 -> V_21 ) ;
return V_197 ;
}
static int F_70 ( struct V_183 * V_184 ,
union V_185 * V_186 ,
struct V_74 * V_75 ,
struct V_187 * V_187 )
{
struct V_84 * V_84 ;
struct V_155 * V_156 = F_63 ( V_184 , struct V_155 , V_184 ) ;
struct V_20 * V_21 = V_156 -> V_21 ;
struct V_11 * V_12 = F_71 ( V_21 -> V_147 , V_75 -> V_198 ) ;
int V_199 = - 1 ;
V_84 = F_72 ( V_187 , V_186 -> V_200 . V_90 , V_186 -> V_200 . V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_75 ) ;
return - 1 ;
}
if ( F_73 ( V_184 , V_186 , V_75 , V_187 ) < 0 )
goto V_71;
if ( ! V_12 -> V_17 . V_201 ) {
V_75 -> V_92 = 0 ;
V_75 -> time = 0 ;
V_75 -> V_91 = V_186 -> V_200 . V_91 ;
V_75 -> V_90 = V_186 -> V_200 . V_90 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_74 ( V_186 , stdout ) ;
V_199 = 0 ;
V_71:
F_75 ( V_84 ) ;
return V_199 ;
}
static int F_76 ( struct V_183 * V_184 ,
union V_185 * V_186 ,
struct V_74 * V_75 ,
struct V_187 * V_187 )
{
struct V_84 * V_84 ;
struct V_155 * V_156 = F_63 ( V_184 , struct V_155 , V_184 ) ;
struct V_20 * V_21 = V_156 -> V_21 ;
struct V_11 * V_12 = F_71 ( V_21 -> V_147 , V_75 -> V_198 ) ;
if ( F_77 ( V_184 , V_186 , V_75 , V_187 ) < 0 )
return - 1 ;
V_84 = F_72 ( V_187 , V_186 -> V_202 . V_90 , V_186 -> V_202 . V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_76 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_201 ) {
V_75 -> V_92 = 0 ;
V_75 -> time = V_186 -> V_202 . time ;
V_75 -> V_91 = V_186 -> V_202 . V_91 ;
V_75 -> V_90 = V_186 -> V_202 . V_90 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_74 ( V_186 , stdout ) ;
F_75 ( V_84 ) ;
return 0 ;
}
static int F_78 ( struct V_183 * V_184 ,
union V_185 * V_186 ,
struct V_74 * V_75 ,
struct V_187 * V_187 )
{
int V_197 = 0 ;
struct V_84 * V_84 ;
struct V_155 * V_156 = F_63 ( V_184 , struct V_155 , V_184 ) ;
struct V_20 * V_21 = V_156 -> V_21 ;
struct V_11 * V_12 = F_71 ( V_21 -> V_147 , V_75 -> V_198 ) ;
V_84 = F_72 ( V_187 , V_186 -> V_202 . V_90 , V_186 -> V_202 . V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_77 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_201 ) {
V_75 -> V_92 = 0 ;
V_75 -> time = 0 ;
V_75 -> V_91 = V_186 -> V_202 . V_91 ;
V_75 -> V_90 = V_186 -> V_202 . V_90 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_74 ( V_186 , stdout ) ;
if ( F_79 ( V_184 , V_186 , V_75 , V_187 ) < 0 )
V_197 = - 1 ;
F_75 ( V_84 ) ;
return V_197 ;
}
static int F_80 ( struct V_183 * V_184 ,
union V_185 * V_186 ,
struct V_74 * V_75 ,
struct V_187 * V_187 )
{
struct V_84 * V_84 ;
struct V_155 * V_156 = F_63 ( V_184 , struct V_155 , V_184 ) ;
struct V_20 * V_21 = V_156 -> V_21 ;
struct V_11 * V_12 = F_71 ( V_21 -> V_147 , V_75 -> V_198 ) ;
if ( F_81 ( V_184 , V_186 , V_75 , V_187 ) < 0 )
return - 1 ;
V_84 = F_72 ( V_187 , V_186 -> V_203 . V_90 , V_186 -> V_203 . V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_78 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_201 ) {
V_75 -> V_92 = 0 ;
V_75 -> time = 0 ;
V_75 -> V_91 = V_186 -> V_203 . V_91 ;
V_75 -> V_90 = V_186 -> V_203 . V_90 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_74 ( V_186 , stdout ) ;
F_75 ( V_84 ) ;
return 0 ;
}
static int F_82 ( struct V_183 * V_184 ,
union V_185 * V_186 ,
struct V_74 * V_75 ,
struct V_187 * V_187 )
{
struct V_84 * V_84 ;
struct V_155 * V_156 = F_63 ( V_184 , struct V_155 , V_184 ) ;
struct V_20 * V_21 = V_156 -> V_21 ;
struct V_11 * V_12 = F_71 ( V_21 -> V_147 , V_75 -> V_198 ) ;
if ( F_83 ( V_184 , V_186 , V_75 , V_187 ) < 0 )
return - 1 ;
V_84 = F_72 ( V_187 , V_186 -> V_204 . V_90 , V_186 -> V_204 . V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_79 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_201 ) {
V_75 -> V_92 = 0 ;
V_75 -> time = 0 ;
V_75 -> V_91 = V_186 -> V_204 . V_91 ;
V_75 -> V_90 = V_186 -> V_204 . V_90 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_74 ( V_186 , stdout ) ;
F_75 ( V_84 ) ;
return 0 ;
}
static int F_84 ( struct V_183 * V_184 ,
union V_185 * V_186 ,
struct V_74 * V_75 ,
struct V_187 * V_187 )
{
struct V_84 * V_84 ;
struct V_155 * V_156 = F_63 ( V_184 , struct V_155 , V_184 ) ;
struct V_20 * V_21 = V_156 -> V_21 ;
struct V_11 * V_12 = F_71 ( V_21 -> V_147 , V_75 -> V_198 ) ;
if ( F_85 ( V_184 , V_186 , V_75 , V_187 ) < 0 )
return - 1 ;
V_84 = F_72 ( V_187 , V_75 -> V_90 ,
V_75 -> V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_80 ) ;
return - 1 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_74 ( V_186 , stdout ) ;
F_75 ( V_84 ) ;
return 0 ;
}
static void F_86 ( int T_5 V_205 )
{
V_206 = 1 ;
}
static int F_87 ( struct V_155 * V_156 )
{
int V_199 ;
signal ( V_207 , F_86 ) ;
if ( V_156 -> V_208 ) {
V_156 -> V_184 . V_200 = F_70 ;
V_156 -> V_184 . V_202 = F_76 ;
V_156 -> V_184 . exit = F_78 ;
}
if ( V_156 -> V_209 ) {
V_156 -> V_184 . V_203 = F_80 ;
V_156 -> V_184 . V_204 = F_82 ;
}
if ( V_156 -> V_210 )
V_156 -> V_184 . V_211 = F_84 ;
V_199 = F_88 ( V_156 -> V_21 ) ;
if ( V_189 )
F_6 ( L_81 V_157 L_43 , V_191 ) ;
return V_199 ;
}
static struct V_212 * F_89 ( const char * V_213 ,
struct V_179 * V_214 )
{
struct V_212 * V_215 = malloc ( sizeof( * V_215 ) + strlen ( V_213 ) + 1 ) ;
if ( V_215 != NULL ) {
strcpy ( V_215 -> V_213 , V_213 ) ;
V_215 -> V_214 = V_214 ;
}
return V_215 ;
}
static void F_90 ( struct V_212 * V_215 )
{
F_91 ( & V_215 -> V_216 , & V_217 ) ;
}
static struct V_212 * F_92 ( const char * V_213 )
{
struct V_212 * V_215 ;
F_93 (s, &script_specs, node)
if ( strcasecmp ( V_215 -> V_213 , V_213 ) == 0 )
return V_215 ;
return NULL ;
}
int F_94 ( const char * V_213 , struct V_179 * V_214 )
{
struct V_212 * V_215 ;
V_215 = F_92 ( V_213 ) ;
if ( V_215 )
return - 1 ;
V_215 = F_89 ( V_213 , V_214 ) ;
if ( ! V_215 )
return - 1 ;
else
F_90 ( V_215 ) ;
return 0 ;
}
static struct V_179 * F_95 ( const char * V_213 )
{
struct V_212 * V_215 = F_92 ( V_213 ) ;
if ( ! V_215 )
return NULL ;
return V_215 -> V_214 ;
}
static void F_96 ( void )
{
struct V_212 * V_215 ;
fprintf ( V_218 , L_43 ) ;
fprintf ( V_218 , L_82
L_83 ) ;
F_93 (s, &script_specs, node)
fprintf ( V_218 , L_84 , V_215 -> V_213 , V_215 -> V_214 -> V_219 ) ;
fprintf ( V_218 , L_43 ) ;
}
static int F_97 ( const struct V_220 * T_6 V_205 ,
const char * V_10 , int T_7 V_205 )
{
char V_213 [ V_221 ] ;
const char * V_156 , * V_222 ;
int V_149 ;
if ( strcmp ( V_10 , L_85 ) == 0 ) {
F_96 () ;
exit ( 0 ) ;
}
V_156 = strchr ( V_10 , ':' ) ;
if ( V_156 ) {
V_149 = V_156 - V_10 ;
if ( V_149 >= V_221 ) {
fprintf ( V_218 , L_86 ) ;
return - 1 ;
}
strncpy ( V_213 , V_10 , V_149 ) ;
V_213 [ V_149 ] = '\0' ;
V_179 = F_95 ( V_213 ) ;
if ( ! V_179 ) {
fprintf ( V_218 , L_86 ) ;
return - 1 ;
}
V_156 ++ ;
} else {
V_156 = V_10 ;
V_222 = strrchr ( V_156 , '.' ) ;
if ( ! V_222 ) {
fprintf ( V_218 , L_87 ) ;
return - 1 ;
}
V_179 = F_95 ( ++ V_222 ) ;
if ( ! V_179 ) {
fprintf ( V_218 , L_87 ) ;
return - 1 ;
}
}
V_223 = F_98 ( V_156 ) ;
return 0 ;
}
static int F_99 ( const struct V_220 * T_6 V_205 ,
const char * V_224 , int T_7 V_205 )
{
char * V_225 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_226 = 0 ;
char * V_10 = F_98 ( V_224 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_227 ;
V_225 = strchr ( V_10 , ':' ) ;
if ( V_225 ) {
* V_225 = '\0' ;
V_225 ++ ;
if ( ! strcmp ( V_10 , L_88 ) )
type = V_228 ;
else if ( ! strcmp ( V_10 , L_89 ) )
type = V_229 ;
else if ( ! strcmp ( V_10 , L_90 ) )
type = V_70 ;
else if ( ! strcmp ( V_10 , L_91 ) )
type = V_230 ;
else if ( ! strcmp ( V_10 , L_92 ) )
type = V_231 ;
else {
fprintf ( V_218 , L_93 ) ;
V_226 = - V_26 ;
goto V_71;
}
if ( V_3 [ type ] . V_4 )
F_100 ( L_94 ,
F_16 ( type ) ) ;
V_3 [ type ] . V_19 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_65 = false ;
} else {
V_225 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_218 ,
L_95 ) ;
V_226 = - V_26 ;
goto V_71;
}
if ( F_1 () )
F_100 ( L_96 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_19 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_65 = true ;
}
}
for ( V_225 = strtok ( V_225 , L_97 ) ; V_225 ; V_225 = strtok ( NULL , L_97 ) ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_225 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 && strcmp ( V_225 , L_98 ) == 0 ) {
V_161 = true ;
continue;
}
if ( V_7 == V_8 ) {
fprintf ( V_218 , L_99 ) ;
V_226 = - V_26 ;
goto V_71;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_232 & V_9 [ V_7 ] . V_6 ) {
F_100 ( L_100 ,
V_9 [ V_7 ] . V_10 , F_16 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_232 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_218 , L_101 ,
V_9 [ V_7 ] . V_10 , F_16 ( type ) ) ;
V_226 = - V_26 ;
goto V_71;
}
V_3 [ type ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_19 == 0 ) {
F_7 ( L_102
L_103 , F_16 ( type ) ) ;
}
}
V_71:
free ( V_10 ) ;
return V_226 ;
}
static int F_101 ( const char * V_233 , const struct V_234 * V_235 )
{
char V_236 [ V_221 ] ;
struct V_237 V_238 ;
sprintf ( V_236 , L_104 , V_233 , V_235 -> V_239 ) ;
if ( V_237 ( V_236 , & V_238 ) )
return 0 ;
return F_102 ( V_238 . V_240 ) ;
}
static struct V_241 * F_103 ( const char * V_219 )
{
struct V_241 * V_215 = F_104 ( sizeof( * V_215 ) ) ;
if ( V_215 != NULL && V_219 )
V_215 -> V_219 = F_98 ( V_219 ) ;
return V_215 ;
}
static void F_105 ( struct V_241 * V_215 )
{
F_106 ( & V_215 -> V_219 ) ;
F_106 ( & V_215 -> V_242 ) ;
F_106 ( & V_215 -> args ) ;
free ( V_215 ) ;
}
static void F_107 ( struct V_241 * V_215 )
{
F_91 ( & V_215 -> V_216 , & V_243 ) ;
}
static struct V_241 * F_108 ( const char * V_219 )
{
struct V_241 * V_215 ;
F_93 (s, &script_descs, node)
if ( strcasecmp ( V_215 -> V_219 , V_219 ) == 0 )
return V_215 ;
return NULL ;
}
static struct V_241 * F_109 ( const char * V_219 )
{
struct V_241 * V_215 = F_108 ( V_219 ) ;
if ( V_215 )
return V_215 ;
V_215 = F_103 ( V_219 ) ;
if ( ! V_215 )
goto V_244;
F_107 ( V_215 ) ;
return V_215 ;
V_244:
F_105 ( V_215 ) ;
return NULL ;
}
static const char * F_110 ( const char * V_10 , const char * V_245 )
{
T_4 V_246 = strlen ( V_245 ) ;
const char * V_247 = V_10 ;
if ( strlen ( V_10 ) > V_246 ) {
V_247 = V_10 + strlen ( V_10 ) - V_246 ;
if ( ! strncmp ( V_247 , V_245 , V_246 ) )
return V_247 ;
}
return NULL ;
}
static int F_111 ( struct V_241 * V_248 , const char * V_249 )
{
char line [ V_250 ] , * V_247 ;
T_8 * V_251 ;
V_251 = fopen ( V_249 , L_105 ) ;
if ( ! V_251 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_251 ) ) {
V_247 = F_112 ( line ) ;
if ( strlen ( V_247 ) == 0 )
continue;
if ( * V_247 != '#' )
continue;
V_247 ++ ;
if ( strlen ( V_247 ) && * V_247 == '!' )
continue;
V_247 = F_112 ( V_247 ) ;
if ( strlen ( V_247 ) && V_247 [ strlen ( V_247 ) - 1 ] == '\n' )
V_247 [ strlen ( V_247 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_247 , L_106 , strlen ( L_106 ) ) ) {
V_247 += strlen ( L_106 ) ;
V_248 -> V_242 = F_98 ( F_112 ( V_247 ) ) ;
continue;
}
if ( ! strncmp ( V_247 , L_107 , strlen ( L_107 ) ) ) {
V_247 += strlen ( L_107 ) ;
V_248 -> args = F_98 ( F_112 ( V_247 ) ) ;
continue;
}
}
fclose ( V_251 ) ;
return 0 ;
}
static char * F_113 ( struct V_234 * V_252 , const char * V_245 )
{
char * V_253 , * V_10 ;
V_253 = F_98 ( V_252 -> V_239 ) ;
if ( ! V_253 )
return NULL ;
V_10 = ( char * ) F_110 ( V_253 , V_245 ) ;
if ( ! V_10 ) {
free ( V_253 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_253 ;
}
static int F_114 ( const struct V_220 * T_6 V_205 ,
const char * V_215 V_205 ,
int T_7 V_205 )
{
struct V_234 * V_252 , * V_254 ;
char V_255 [ V_256 ] ;
T_9 * V_257 , * V_258 ;
char V_259 [ V_256 ] ;
char V_260 [ V_256 ] ;
struct V_241 * V_248 ;
char V_261 [ V_250 ] ;
char * V_253 ;
snprintf ( V_255 , V_256 , L_108 , F_115 () ) ;
V_257 = F_116 ( V_255 ) ;
if ( ! V_257 )
return - 1 ;
F_117 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_260 , V_256 , L_109 , V_255 ,
V_254 -> V_239 ) ;
V_258 = F_116 ( V_260 ) ;
if ( ! V_258 )
continue;
F_118 (lang_path, lang_dir, script_dirent) {
V_253 = F_113 ( V_252 , V_262 ) ;
if ( V_253 ) {
V_248 = F_109 ( V_253 ) ;
snprintf ( V_259 , V_256 , L_104 ,
V_260 , V_252 -> V_239 ) ;
F_111 ( V_248 , V_259 ) ;
free ( V_253 ) ;
}
}
}
fprintf ( stdout , L_110 ) ;
F_93 (desc, &script_descs, node) {
sprintf ( V_261 , L_111 , V_248 -> V_219 ,
V_248 -> args ? V_248 -> args : L_1 ) ;
fprintf ( stdout , L_112 , V_261 ,
V_248 -> V_242 ? V_248 -> V_242 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_119 ( char * V_263 , char * V_264 ,
struct V_20 * V_21 )
{
char V_249 [ V_256 ] , V_18 [ 128 ] ;
char line [ V_250 ] , * V_247 ;
struct V_11 * V_124 ;
int V_265 , V_149 ;
T_8 * V_251 ;
sprintf ( V_249 , L_113 , V_263 , V_264 ) ;
V_251 = fopen ( V_249 , L_105 ) ;
if ( ! V_251 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_251 ) ) {
V_247 = F_112 ( line ) ;
if ( * V_247 == '#' )
continue;
while ( strlen ( V_247 ) ) {
V_247 = strstr ( V_247 , L_114 ) ;
if ( ! V_247 )
break;
V_247 += 2 ;
V_247 = F_112 ( V_247 ) ;
V_149 = strcspn ( V_247 , L_115 ) ;
if ( ! V_149 )
break;
snprintf ( V_18 , V_149 + 1 , L_116 , V_247 ) ;
V_265 = 0 ;
F_17 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_124 ) , V_18 ) ) {
V_265 = 1 ;
break;
}
}
if ( ! V_265 ) {
fclose ( V_251 ) ;
return - 1 ;
}
}
}
fclose ( V_251 ) ;
return 0 ;
}
int F_120 ( char * * V_266 , char * * V_267 )
{
struct V_234 * V_252 , * V_254 ;
char V_255 [ V_256 ] , V_260 [ V_256 ] ;
T_9 * V_257 , * V_258 ;
struct V_20 * V_21 ;
struct V_268 V_269 = {
. V_236 = V_270 ,
. V_271 = V_272 ,
} ;
char * V_273 ;
int V_7 = 0 ;
V_21 = F_121 ( & V_269 , false , NULL ) ;
if ( ! V_21 )
return - 1 ;
snprintf ( V_255 , V_256 , L_108 , F_115 () ) ;
V_257 = F_116 ( V_255 ) ;
if ( ! V_257 ) {
F_122 ( V_21 ) ;
return - 1 ;
}
F_117 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_260 , V_256 , L_104 , V_255 ,
V_254 -> V_239 ) ;
#ifdef F_123
if ( strstr ( V_260 , L_117 ) )
continue;
#endif
#ifdef F_124
if ( strstr ( V_260 , L_118 ) )
continue;
#endif
V_258 = F_116 ( V_260 ) ;
if ( ! V_258 )
continue;
F_118 (lang_path, lang_dir, script_dirent) {
if ( strstr ( V_252 -> V_239 , L_119 ) )
continue;
sprintf ( V_267 [ V_7 ] , L_104 , V_260 ,
V_252 -> V_239 ) ;
V_273 = strchr ( V_252 -> V_239 , '.' ) ;
snprintf ( V_266 [ V_7 ] ,
( V_273 - V_252 -> V_239 ) + 1 ,
L_116 , V_252 -> V_239 ) ;
if ( F_119 ( V_260 ,
V_266 [ V_7 ] , V_21 ) )
continue;
V_7 ++ ;
}
F_125 ( V_258 ) ;
}
F_125 ( V_257 ) ;
F_122 ( V_21 ) ;
return V_7 ;
}
static char * F_126 ( const char * V_253 , const char * V_245 )
{
struct V_234 * V_252 , * V_254 ;
char V_255 [ V_256 ] ;
char V_259 [ V_256 ] ;
T_9 * V_257 , * V_258 ;
char V_260 [ V_256 ] ;
char * V_274 ;
snprintf ( V_255 , V_256 , L_108 , F_115 () ) ;
V_257 = F_116 ( V_255 ) ;
if ( ! V_257 )
return NULL ;
F_117 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_260 , V_256 , L_109 , V_255 ,
V_254 -> V_239 ) ;
V_258 = F_116 ( V_260 ) ;
if ( ! V_258 )
continue;
F_118 (lang_path, lang_dir, script_dirent) {
V_274 = F_113 ( V_252 , V_245 ) ;
if ( V_274 && ! strcmp ( V_253 , V_274 ) ) {
free ( V_274 ) ;
F_125 ( V_258 ) ;
F_125 ( V_257 ) ;
snprintf ( V_259 , V_256 , L_104 ,
V_260 , V_252 -> V_239 ) ;
return F_98 ( V_259 ) ;
}
free ( V_274 ) ;
}
F_125 ( V_258 ) ;
}
F_125 ( V_257 ) ;
return NULL ;
}
static bool F_127 ( const char * V_259 )
{
return F_110 ( V_259 , L_120 ) == NULL ? false : true ;
}
static int F_128 ( char * V_259 )
{
struct V_241 * V_248 ;
int V_275 = 0 ;
char * V_247 ;
V_248 = F_103 ( NULL ) ;
if ( F_111 ( V_248 , V_259 ) )
goto V_71;
if ( ! V_248 -> args )
goto V_71;
for ( V_247 = V_248 -> args ; * V_247 ; V_247 ++ )
if ( * V_247 == '<' )
V_275 ++ ;
V_71:
F_105 ( V_248 ) ;
return V_275 ;
}
static int F_129 ( int V_276 , const char * * V_277 )
{
char * * V_278 = malloc ( sizeof( const char * ) * V_276 ) ;
if ( ! V_278 ) {
F_6 ( L_121 ) ;
return - 1 ;
}
memcpy ( V_278 , V_277 , sizeof( const char * ) * V_276 ) ;
V_276 = F_130 ( V_276 , ( const char * * ) V_278 , V_279 ,
NULL , V_280 ) ;
free ( V_278 ) ;
V_173 = ( V_276 == 0 ) ;
return 0 ;
}
static void F_131 ( struct V_155 * V_156 )
{
struct V_20 * V_21 = V_156 -> V_21 ;
T_1 V_13 = F_132 ( V_21 -> V_147 ) ;
if ( V_69 . V_67 || V_69 . V_281 ) {
if ( ( V_13 & V_282 ) &&
( V_13 & V_283 ) )
V_284 . V_285 = V_286 ;
else if ( V_13 & V_287 )
V_284 . V_285 = V_288 ;
else
V_284 . V_285 = V_289 ;
}
}
static int F_133 ( struct V_183 * V_184 V_205 ,
union V_185 * V_186 ,
struct V_20 * V_21 )
{
struct V_290 * V_291 = & V_186 -> V_292 ;
struct V_11 * V_167 ;
F_17 (session->evlist, counter) {
F_134 ( & V_180 , V_167 ) ;
F_55 ( V_167 , V_291 -> time ) ;
}
F_56 ( V_291 -> time ) ;
return 0 ;
}
static int F_135 ( struct V_183 * V_184 V_205 ,
union V_185 * V_186 ,
struct V_20 * V_21 V_205 )
{
F_136 ( & V_180 , & V_186 -> V_180 ) ;
return 0 ;
}
static int F_137 ( struct V_155 * V_156 )
{
struct V_146 * V_147 = V_156 -> V_21 -> V_147 ;
if ( ! V_156 -> V_176 || ! V_156 -> V_170 )
return 0 ;
if ( F_138 ( V_156 -> V_293 , L_122 ) )
return - V_26 ;
F_139 ( V_147 , V_156 -> V_176 , V_156 -> V_170 ) ;
if ( F_140 ( V_147 , true ) )
return - V_227 ;
V_156 -> V_293 = true ;
return 0 ;
}
static
int F_141 ( struct V_183 * V_184 ,
union V_185 * V_186 ,
struct V_20 * V_21 V_205 )
{
struct V_155 * V_156 = F_63 ( V_184 , struct V_155 , V_184 ) ;
if ( V_156 -> V_170 ) {
F_100 ( L_123 ) ;
return 0 ;
}
V_156 -> V_170 = F_142 ( & V_186 -> V_294 ) ;
if ( ! V_156 -> V_170 )
return - V_227 ;
return F_137 ( V_156 ) ;
}
static
int F_143 ( struct V_183 * V_184 V_205 ,
union V_185 * V_186 ,
struct V_20 * V_21 V_205 )
{
struct V_155 * V_156 = F_63 ( V_184 , struct V_155 , V_184 ) ;
if ( V_156 -> V_176 ) {
F_100 ( L_124 ) ;
return 0 ;
}
V_156 -> V_176 = F_144 ( & V_186 -> V_295 . V_296 ) ;
if ( ! V_156 -> V_176 )
return - V_227 ;
return F_137 ( V_156 ) ;
}
int F_145 ( int V_276 , const char * * V_277 , const char * T_10 V_205 )
{
bool V_297 = false ;
bool V_22 = false ;
bool V_298 = false ;
bool V_299 = false ;
char * V_300 = NULL ;
char * V_301 = NULL ;
struct V_20 * V_21 ;
struct V_302 V_302 = { . V_303 = false , } ;
char * V_259 = NULL ;
const char * * V_278 ;
int V_7 , V_1 , V_197 = 0 ;
struct V_155 V_156 = {
. V_184 = {
. V_75 = F_62 ,
. V_203 = F_81 ,
. V_204 = F_83 ,
. V_200 = F_73 ,
. exit = F_79 ,
. V_202 = F_77 ,
. V_17 = F_67 ,
. V_304 = V_305 ,
. V_306 = V_307 ,
. V_308 = V_309 ,
. V_310 = V_311 ,
. V_312 = V_313 ,
. V_314 = V_315 ,
. V_237 = V_316 ,
. V_292 = F_133 ,
. V_180 = F_135 ,
. V_294 = F_141 ,
. V_295 = F_143 ,
. V_317 = true ,
. V_318 = true ,
} ,
} ;
struct V_268 V_269 = {
. V_271 = V_272 ,
} ;
const struct V_220 V_319 [] = {
F_146 ( 'D' , L_125 , & V_320 ,
L_126 ) ,
F_147 ( 'v' , L_127 , & V_321 ,
L_128 ) ,
F_146 ( 'L' , L_129 , & V_89 ,
L_130 ) ,
F_148 ( 'l' , L_131 , NULL , NULL , L_132 ,
F_114 ) ,
F_149 ( 's' , L_133 , NULL , L_134 ,
L_135 ,
F_97 ) ,
F_150 ( 'g' , L_136 , & V_322 , L_85 ,
L_137 ) ,
F_150 ( 'i' , L_138 , & V_270 , L_139 , L_140 ) ,
F_146 ( 'd' , L_141 , & V_189 ,
L_142 ) ,
F_146 ( 0 , L_143 , & V_22 , L_144 ) ,
F_146 ( 0 , L_145 , & V_298 , L_146 ) ,
F_150 ( 'k' , L_147 , & V_69 . V_323 ,
L_139 , L_148 ) ,
F_150 ( 0 , L_149 , & V_69 . V_324 ,
L_139 , L_150 ) ,
F_146 ( 'G' , L_151 , & V_66 ,
L_152 ) ,
F_150 ( 0 , L_153 , & V_69 . V_325 , L_154 ,
L_155 ) ,
F_149 ( 'F' , L_156 , NULL , L_157 ,
L_158
L_159
L_160
L_161 , F_99 ) ,
F_146 ( 'a' , L_162 , & V_173 ,
L_163 ) ,
F_150 ( 'S' , L_164 , & V_69 . V_326 , L_165 ,
L_166 ) ,
F_150 ( 'C' , L_167 , & V_194 , L_167 , L_168 ) ,
F_150 ( 'c' , L_169 , & V_69 . V_327 , L_170 ,
L_171 ) ,
F_150 ( 0 , L_172 , & V_69 . V_328 , L_173 ,
L_174 ) ,
F_150 ( 0 , L_175 , & V_69 . V_329 , L_176 ,
L_177 ) ,
F_146 ( 'I' , L_178 , & V_297 ,
L_179 ) ,
F_146 ( '\0' , L_180 , & V_69 . V_330 ,
L_181 ) ,
F_146 ( '\0' , L_182 , & V_156 . V_208 ,
L_183 ) ,
F_146 ( '\0' , L_184 , & V_156 . V_209 ,
L_185 ) ,
F_146 ( '\0' , L_186 , & V_156 . V_210 ,
L_187 ) ,
F_146 ( 'f' , L_188 , & V_269 . V_331 , L_189 ) ,
F_146 ( 0 , L_190 , & V_95 ,
L_191 ) ,
F_151 ( 0 , L_192 , & V_302 , NULL , L_193 ,
L_194 ,
V_332 ) ,
F_146 ( 0 , L_195 , & V_333 ,
L_196 ) ,
F_146 ( 0 , L_197 , & V_69 . V_334 ,
L_198 ) ,
F_146 ( 0 , L_199 , & V_69 . V_335 ,
L_200 ) ,
F_152 ()
} ;
const char * const V_336 [] = { L_201 , L_202 , NULL } ;
const char * V_337 [] = {
L_203 ,
L_204 ,
L_205 ,
L_206 ,
L_207 ,
NULL
} ;
F_57 () ;
V_276 = F_153 ( V_276 , V_277 , V_319 , V_336 , V_337 ,
V_280 ) ;
V_269 . V_236 = V_270 ;
if ( V_276 > 1 && ! strncmp ( V_277 [ 0 ] , L_208 , strlen ( L_208 ) ) ) {
V_300 = F_126 ( V_277 [ 1 ] , V_338 ) ;
if ( ! V_300 )
return F_154 ( V_276 , V_277 , NULL ) ;
}
if ( V_276 > 1 && ! strncmp ( V_277 [ 0 ] , L_209 , strlen ( L_209 ) ) ) {
V_301 = F_126 ( V_277 [ 1 ] , V_262 ) ;
if ( ! V_301 ) {
fprintf ( V_218 ,
L_210
L_211 ) ;
return - 1 ;
}
}
if ( V_302 . V_119 &&
V_302 . V_339 > V_120 )
V_120 = V_302 . V_339 ;
F_155 ( F_115 () ) ;
if ( V_276 && ! V_223 && ! V_300 && ! V_301 ) {
int V_340 [ 2 ] ;
int V_341 ;
T_11 V_90 ;
V_300 = F_126 ( V_277 [ 0 ] , V_338 ) ;
V_301 = F_126 ( V_277 [ 0 ] , V_262 ) ;
if ( ! V_300 && ! V_301 ) {
F_156 ( V_337 , V_319 ,
L_212
L_213 , V_277 [ 0 ] ) ;
}
if ( F_127 ( V_277 [ 0 ] ) ) {
V_341 = V_276 - 1 ;
} else {
int V_342 ;
V_341 = F_128 ( V_301 ) ;
V_342 = ( V_276 - 1 ) - V_341 ;
if ( V_342 < 0 ) {
F_156 ( V_337 , V_319 ,
L_214
L_215
L_216 , V_277 [ 0 ] ) ;
}
}
if ( F_157 ( V_340 ) < 0 ) {
perror ( L_217 ) ;
return - 1 ;
}
V_90 = V_202 () ;
if ( V_90 < 0 ) {
perror ( L_218 ) ;
return - 1 ;
}
if ( ! V_90 ) {
V_1 = 0 ;
F_158 ( V_340 [ 1 ] , 1 ) ;
F_159 ( V_340 [ 0 ] ) ;
if ( F_127 ( V_277 [ 0 ] ) ) {
V_173 = true ;
} else if ( ! V_173 ) {
if ( F_129 ( V_276 - V_341 , & V_277 [ V_341 ] ) != 0 ) {
V_197 = - 1 ;
goto V_71;
}
}
V_278 = malloc ( ( V_276 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_278 ) {
F_6 ( L_121 ) ;
V_197 = - V_227 ;
goto V_71;
}
V_278 [ V_1 ++ ] = L_219 ;
V_278 [ V_1 ++ ] = V_300 ;
if ( V_173 )
V_278 [ V_1 ++ ] = L_220 ;
V_278 [ V_1 ++ ] = L_221 ;
V_278 [ V_1 ++ ] = L_222 ;
V_278 [ V_1 ++ ] = L_223 ;
for ( V_7 = V_341 + 1 ; V_7 < V_276 ; V_7 ++ )
V_278 [ V_1 ++ ] = V_277 [ V_7 ] ;
V_278 [ V_1 ++ ] = NULL ;
F_160 ( L_219 , ( char * * ) V_278 ) ;
free ( V_278 ) ;
exit ( - 1 ) ;
}
F_158 ( V_340 [ 0 ] , 0 ) ;
F_159 ( V_340 [ 1 ] ) ;
V_278 = malloc ( ( V_276 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_278 ) {
F_6 ( L_121 ) ;
V_197 = - V_227 ;
goto V_71;
}
V_1 = 0 ;
V_278 [ V_1 ++ ] = L_219 ;
V_278 [ V_1 ++ ] = V_301 ;
for ( V_7 = 1 ; V_7 < V_341 + 1 ; V_7 ++ )
V_278 [ V_1 ++ ] = V_277 [ V_7 ] ;
V_278 [ V_1 ++ ] = L_224 ;
V_278 [ V_1 ++ ] = L_223 ;
V_278 [ V_1 ++ ] = NULL ;
F_160 ( L_219 , ( char * * ) V_278 ) ;
free ( V_278 ) ;
exit ( - 1 ) ;
}
if ( V_300 )
V_259 = V_300 ;
if ( V_301 )
V_259 = V_301 ;
if ( V_259 ) {
V_1 = 0 ;
if ( ! V_300 )
V_173 = false ;
else if ( ! V_173 ) {
if ( F_129 ( V_276 - 1 , & V_277 [ 1 ] ) != 0 ) {
V_197 = - 1 ;
goto V_71;
}
}
V_278 = malloc ( ( V_276 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_278 ) {
F_6 ( L_121 ) ;
V_197 = - V_227 ;
goto V_71;
}
V_278 [ V_1 ++ ] = L_219 ;
V_278 [ V_1 ++ ] = V_259 ;
if ( V_173 )
V_278 [ V_1 ++ ] = L_220 ;
for ( V_7 = 2 ; V_7 < V_276 ; V_7 ++ )
V_278 [ V_1 ++ ] = V_277 [ V_7 ] ;
V_278 [ V_1 ++ ] = NULL ;
F_160 ( L_219 , ( char * * ) V_278 ) ;
free ( V_278 ) ;
exit ( - 1 ) ;
}
if ( ! V_223 )
F_161 () ;
V_21 = F_121 ( & V_269 , false , & V_156 . V_184 ) ;
if ( V_21 == NULL )
return - 1 ;
if ( V_22 || V_298 ) {
F_162 ( V_21 , stdout , V_297 ) ;
if ( V_298 )
goto V_343;
}
if ( F_163 ( & V_21 -> V_22 . V_344 ) < 0 )
goto V_343;
V_156 . V_21 = V_21 ;
F_131 ( & V_156 ) ;
V_21 -> V_302 = & V_302 ;
if ( V_194 ) {
V_197 = F_164 ( V_21 , V_194 , V_195 ) ;
if ( V_197 < 0 )
goto V_343;
}
if ( ! V_66 )
V_69 . V_67 = true ;
else
V_69 . V_67 = false ;
if ( V_21 -> V_345 . V_346 &&
F_165 ( V_21 -> V_345 . V_346 ,
V_347 ,
& V_21 -> V_348 . V_349 ) < 0 ) {
F_6 ( L_225 , V_350 ) ;
return - 1 ;
}
if ( V_322 ) {
struct V_237 V_351 ;
int V_352 ;
if ( F_1 () ) {
fprintf ( V_218 ,
L_226 ) ;
V_197 = - V_26 ;
goto V_343;
}
V_352 = F_166 ( V_269 . V_236 , V_353 ) ;
if ( V_352 < 0 ) {
V_197 = - V_354 ;
perror ( L_227 ) ;
goto V_343;
}
V_197 = F_167 ( V_352 , & V_351 ) ;
if ( V_197 < 0 ) {
perror ( L_228 ) ;
goto V_343;
}
if ( ! V_351 . V_355 ) {
fprintf ( V_218 , L_229 ) ;
goto V_343;
}
V_179 = F_95 ( V_322 ) ;
if ( ! V_179 ) {
fprintf ( V_218 , L_86 ) ;
V_197 = - V_356 ;
goto V_343;
}
V_197 = V_179 -> V_357 ( V_21 -> V_345 . V_346 ,
L_230 ) ;
goto V_343;
}
if ( V_223 ) {
V_197 = V_179 -> V_358 ( V_223 , V_276 , V_277 ) ;
if ( V_197 )
goto V_343;
F_7 ( L_231 , V_223 ) ;
V_299 = true ;
}
V_197 = F_14 ( V_21 ) ;
if ( V_197 < 0 )
goto V_343;
V_197 = F_87 ( & V_156 ) ;
F_60 () ;
V_343:
F_168 ( V_21 -> V_147 ) ;
F_122 ( V_21 ) ;
if ( V_299 )
F_61 () ;
V_71:
return V_197 ;
}
