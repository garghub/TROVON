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
unsigned int V_1 ;
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
bool V_68 = false ;
F_17 (session->evlist, evsel) {
V_68 = true ;
if ( V_12 -> V_17 . V_13 & V_69 ) {
V_67 = true ;
break;
}
}
if ( V_68 && ! V_67 )
V_70 . V_67 = false ;
}
if ( V_70 . V_67 &&
! V_3 [ V_71 ] . V_4 ) {
struct V_16 * V_17 ;
V_1 = V_71 ;
F_17 (session->evlist, evsel) {
if ( V_12 -> V_17 . type != V_1 )
continue;
V_17 = & V_12 -> V_17 ;
if ( V_17 -> V_13 & V_69 ) {
V_3 [ V_1 ] . V_19 |= V_29 ;
V_3 [ V_1 ] . V_19 |= V_72 ;
V_3 [ V_1 ] . V_19 |= V_73 ;
F_13 ( V_17 ) ;
goto V_74;
}
}
}
V_74:
return 0 ;
}
static void F_18 ( struct V_75 * V_76 ,
struct V_16 * V_17 )
{
struct V_77 * V_78 = & V_76 -> V_79 ;
T_2 V_80 = V_17 -> V_81 ;
unsigned V_7 = 0 , V_82 ;
if ( ! V_78 )
return;
F_19 (r, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_1 V_83 = V_78 -> V_78 [ V_7 ++ ] ;
printf ( L_26 V_84 L_27 , F_20 ( V_82 ) , V_83 ) ;
}
}
static void F_21 ( struct V_75 * V_76 ,
struct V_85 * V_85 ,
struct V_11 * V_12 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
unsigned long V_86 ;
unsigned long V_87 ;
unsigned long long V_88 ;
if ( F_11 ( V_89 ) ) {
if ( V_90 )
printf ( L_28 , F_22 ( V_85 ) ) ;
else if ( F_11 ( V_27 ) && V_70 . V_67 )
printf ( L_29 , F_22 ( V_85 ) ) ;
else
printf ( L_30 , F_22 ( V_85 ) ) ;
}
if ( F_11 ( V_43 ) && F_11 ( V_44 ) )
printf ( L_31 , V_76 -> V_91 , V_76 -> V_92 ) ;
else if ( F_11 ( V_43 ) )
printf ( L_32 , V_76 -> V_91 ) ;
else if ( F_11 ( V_44 ) )
printf ( L_32 , V_76 -> V_92 ) ;
if ( F_11 ( V_50 ) ) {
if ( V_90 )
printf ( L_33 , V_76 -> V_93 ) ;
else
printf ( L_34 , V_76 -> V_93 ) ;
}
if ( F_11 ( TIME ) ) {
V_88 = V_76 -> time ;
V_86 = V_88 / V_94 ;
V_88 -= V_86 * V_94 ;
V_87 = V_88 / V_95 ;
if ( V_96 )
printf ( L_35 , V_86 , V_88 ) ;
else
printf ( L_36 , V_86 , V_87 ) ;
}
}
static inline char
F_23 ( struct V_97 * V_98 )
{
if ( ! ( V_98 -> V_99 . V_100 || V_98 -> V_99 . V_101 ) )
return '-' ;
return V_98 -> V_99 . V_101 ? 'P' : 'M' ;
}
static void F_24 ( struct V_75 * V_76 )
{
struct V_102 * V_98 = V_76 -> V_102 ;
T_1 V_7 ;
if ( ! ( V_98 && V_98 -> V_103 ) )
return;
for ( V_7 = 0 ; V_7 < V_98 -> V_103 ; V_7 ++ ) {
printf ( L_37 V_84 L_38 V_84 L_39 ,
V_98 -> V_104 [ V_7 ] . V_105 ,
V_98 -> V_104 [ V_7 ] . V_106 ,
F_23 ( V_98 -> V_104 + V_7 ) ,
V_98 -> V_104 [ V_7 ] . V_99 . V_107 ? 'X' : '-' ,
V_98 -> V_104 [ V_7 ] . V_99 . abort ? 'A' : '-' ,
V_98 -> V_104 [ V_7 ] . V_99 . V_108 ) ;
}
}
static void F_25 ( struct V_75 * V_76 ,
struct V_85 * V_85 )
{
struct V_102 * V_98 = V_76 -> V_102 ;
struct V_109 V_110 , V_111 ;
T_1 V_7 , V_105 , V_106 ;
if ( ! ( V_98 && V_98 -> V_103 ) )
return;
for ( V_7 = 0 ; V_7 < V_98 -> V_103 ; V_7 ++ ) {
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_105 = V_98 -> V_104 [ V_7 ] . V_105 ;
V_106 = V_98 -> V_104 [ V_7 ] . V_106 ;
F_26 ( V_85 , V_76 -> V_112 , V_113 , V_105 , & V_110 ) ;
if ( V_110 . V_114 )
V_110 . V_115 = F_27 ( V_110 . V_114 , V_110 . V_116 , NULL ) ;
F_26 ( V_85 , V_76 -> V_112 , V_113 , V_106 , & V_111 ) ;
if ( V_111 . V_114 )
V_111 . V_115 = F_27 ( V_111 . V_114 , V_111 . V_116 , NULL ) ;
F_28 ( V_110 . V_115 , & V_110 , stdout ) ;
putchar ( '/' ) ;
F_28 ( V_111 . V_115 , & V_111 , stdout ) ;
printf ( L_39 ,
F_23 ( V_98 -> V_104 + V_7 ) ,
V_98 -> V_104 [ V_7 ] . V_99 . V_107 ? 'X' : '-' ,
V_98 -> V_104 [ V_7 ] . V_99 . abort ? 'A' : '-' ,
V_98 -> V_104 [ V_7 ] . V_99 . V_108 ) ;
}
}
static void F_29 ( struct V_75 * V_76 ,
struct V_85 * V_85 ,
struct V_16 * V_17 )
{
struct V_109 V_117 ;
printf ( L_40 V_84 , V_76 -> V_116 ) ;
if ( ! F_30 ( V_17 ) )
return;
F_31 ( V_85 , & V_117 , V_76 ) ;
if ( F_11 ( V_39 ) ) {
printf ( L_27 ) ;
if ( F_11 ( V_40 ) )
F_28 ( V_117 . V_115 , & V_117 , stdout ) ;
else
F_32 ( V_117 . V_115 , stdout ) ;
}
if ( F_11 ( V_41 ) ) {
printf ( L_41 ) ;
F_33 ( V_117 . V_114 , stdout ) ;
printf ( L_42 ) ;
}
}
static void F_34 ( struct V_75 * V_76 ,
struct V_11 * V_12 ,
struct V_85 * V_85 ,
struct V_109 * V_117 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
T_3 V_118 = F_35 ( V_85 ) ;
struct V_109 V_119 ;
const char * V_120 = NULL ;
static int V_121 ;
int V_122 = 0 ;
T_1 V_123 = 0 ;
if ( V_85 -> V_124 && V_76 -> V_99 & V_125 )
V_118 += 1 ;
if ( V_76 -> V_99 & ( V_126 | V_127 ) ) {
if ( F_30 ( V_17 ) ) {
F_31 ( V_85 , & V_119 , V_76 ) ;
if ( V_119 . V_115 )
V_120 = V_119 . V_115 -> V_120 ;
else
V_123 = V_76 -> V_116 ;
} else {
V_123 = V_76 -> V_116 ;
}
} else if ( V_76 -> V_99 & ( V_125 | V_128 ) ) {
if ( V_117 -> V_115 )
V_120 = V_117 -> V_115 -> V_120 ;
else
V_123 = V_76 -> V_123 ;
}
if ( V_120 )
V_122 = printf ( L_43 , ( int ) V_118 * 4 , L_1 , V_120 ) ;
else if ( V_123 )
V_122 = printf ( L_44 V_84 , ( int ) V_118 * 4 , L_1 , V_123 ) ;
if ( V_122 < 0 )
return;
if ( V_122 > V_121 || ( V_122 && V_122 < V_121 - 52 ) )
V_121 = F_36 ( V_122 + 4 , 32 ) ;
if ( V_122 < V_121 )
printf ( L_45 , V_121 - V_122 , L_1 ) ;
}
static void F_37 ( struct V_75 * V_76 ,
struct V_11 * V_12 ,
struct V_85 * V_85 ,
struct V_109 * V_117 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_129 = false ;
if ( F_11 ( V_130 ) )
F_34 ( V_76 , V_12 , V_85 , V_117 ) ;
if ( F_11 ( V_27 ) ) {
unsigned int V_131 = V_3 [ V_17 -> type ] . V_59 ;
struct V_132 * V_133 = NULL ;
if ( V_70 . V_67 && V_76 -> V_134 &&
F_38 ( V_117 -> V_85 , & V_132 , V_12 ,
V_76 , NULL , NULL , V_135 ) == 0 )
V_133 = & V_132 ;
if ( V_133 == NULL ) {
putchar ( ' ' ) ;
if ( V_131 & V_64 ) {
V_129 = true ;
V_131 &= ~ V_64 ;
}
} else
putchar ( '\n' ) ;
F_39 ( V_76 , V_117 , 0 , V_131 , V_133 , stdout ) ;
}
if ( F_11 ( V_30 ) ||
( ( V_12 -> V_17 . V_13 & V_31 ) &&
! V_3 [ V_17 -> type ] . V_4 ) ) {
printf ( L_46 ) ;
F_29 ( V_76 , V_85 , V_17 ) ;
}
if ( V_129 )
F_40 ( V_117 -> V_114 , V_117 -> V_116 , L_47 , stdout ) ;
printf ( L_48 ) ;
}
static void F_41 ( T_4 V_99 )
{
const char * V_136 = V_137 ;
const int V_138 = strlen ( V_137 ) ;
bool V_107 = V_99 & V_139 ;
const char * V_120 = NULL ;
char V_10 [ 33 ] ;
int V_7 , V_140 = 0 ;
for ( V_7 = 0 ; V_141 [ V_7 ] . V_120 ; V_7 ++ ) {
if ( V_141 [ V_7 ] . V_99 == ( V_99 & ~ V_139 ) ) {
V_120 = V_141 [ V_7 ] . V_120 ;
break;
}
}
for ( V_7 = 0 ; V_7 < V_138 ; V_7 ++ , V_99 >>= 1 ) {
if ( V_99 & 1 )
V_10 [ V_140 ++ ] = V_136 [ V_7 ] ;
}
for (; V_7 < 32 ; V_7 ++ , V_99 >>= 1 ) {
if ( V_99 & 1 )
V_10 [ V_140 ++ ] = '?' ;
}
V_10 [ V_140 ] = 0 ;
if ( V_120 )
printf ( L_49 , V_120 , V_107 ? L_50 : L_1 ) ;
else
printf ( L_51 , V_10 ) ;
}
static void
F_42 ( enum V_142 V_143 ,
unsigned int V_83 ,
void * V_144 )
{
unsigned char V_145 = ( unsigned char ) V_83 ;
struct V_146 * V_146 = V_144 ;
switch ( V_143 ) {
case V_147 :
printf ( L_48 ) ;
break;
case V_148 :
printf ( L_52 , ! V_146 -> V_149 ? L_53 :
L_54 ) ;
break;
case V_150 :
printf ( L_55 , V_83 ) ;
break;
case V_151 :
printf ( L_56 , V_83 ) ;
break;
case V_152 :
printf ( L_57 ) ;
break;
case V_153 :
printf ( L_58 ) ;
break;
case V_154 :
if ( V_146 -> V_155 && V_145 )
V_146 -> V_156 = false ;
if ( ! isprint ( V_145 ) ) {
printf ( L_59 , '.' ) ;
if ( ! V_146 -> V_156 )
break;
if ( V_145 == '\0' )
V_146 -> V_155 = true ;
else
V_146 -> V_156 = false ;
} else {
printf ( L_59 , V_145 ) ;
}
break;
case V_157 :
printf ( L_27 ) ;
break;
case V_158 :
printf ( L_48 ) ;
V_146 -> V_149 ++ ;
break;
case V_159 :
default:
break;
}
}
static void F_43 ( struct V_75 * V_76 )
{
unsigned int V_160 = V_76 -> V_161 ;
struct V_146 V_146 = { 0 , false , true } ;
F_44 ( V_76 -> V_162 , V_160 , 8 ,
F_42 , & V_146 ) ;
if ( V_146 . V_156 && V_146 . V_155 )
printf ( L_60 , L_61 ,
( char * ) ( V_76 -> V_162 ) ) ;
}
static int F_45 ( struct V_163 * V_164 )
{
struct V_11 * V_12 ;
int V_165 = 0 ;
F_17 (evlist, evsel) {
int V_122 = strlen ( F_5 ( V_12 ) ) ;
V_165 = F_46 ( V_122 , V_165 ) ;
}
return V_165 ;
}
static T_3 F_47 ( T_1 V_166 )
{
struct V_167 V_168 = { . V_166 . V_83 = V_166 } ;
char V_169 [ 100 ] ;
char V_74 [ 100 ] ;
static int V_170 ;
int V_122 ;
F_48 ( V_169 , 100 , & V_168 ) ;
V_122 = F_49 ( V_74 , 100 , L_40 V_84 L_62 , V_166 , V_169 ) ;
if ( V_170 < V_122 )
V_170 = V_122 ;
return printf ( L_63 , V_170 , V_74 ) ;
}
static void F_50 ( struct V_171 * V_172 ,
struct V_75 * V_76 , struct V_11 * V_12 ,
struct V_109 * V_117 )
{
struct V_85 * V_85 = V_117 -> V_85 ;
struct V_16 * V_17 = & V_12 -> V_17 ;
if ( V_3 [ V_17 -> type ] . V_19 == 0 )
return;
F_21 ( V_76 , V_85 , V_12 ) ;
if ( F_11 ( V_53 ) )
printf ( L_64 V_173 L_27 , V_76 -> V_174 ) ;
if ( F_11 ( V_175 ) ) {
const char * V_18 = F_5 ( V_12 ) ;
if ( ! V_172 -> V_176 )
V_172 -> V_176 = F_45 ( V_172 -> V_21 -> V_164 ) ;
printf ( L_65 , V_172 -> V_176 ,
V_18 ? V_18 : L_66 ) ;
}
if ( V_177 )
F_41 ( V_76 -> V_99 ) ;
if ( F_51 ( V_17 ) ) {
F_37 ( V_76 , V_12 , V_85 , V_117 ) ;
return;
}
if ( F_11 ( V_25 ) )
F_52 ( V_12 -> V_178 , V_76 -> V_93 ,
V_76 -> V_162 , V_76 -> V_161 ) ;
if ( F_11 ( V_30 ) )
F_29 ( V_76 , V_85 , V_17 ) ;
if ( F_11 ( V_33 ) )
F_47 ( V_76 -> V_166 ) ;
if ( F_11 ( V_36 ) )
printf ( L_40 V_173 , V_76 -> V_179 ) ;
if ( F_11 ( V_27 ) ) {
struct V_132 * V_133 = NULL ;
if ( V_70 . V_67 && V_76 -> V_134 &&
F_38 ( V_117 -> V_85 , & V_132 , V_12 ,
V_76 , NULL , NULL , V_135 ) == 0 )
V_133 = & V_132 ;
putchar ( V_133 ? '\n' : ' ' ) ;
F_39 ( V_76 , V_117 , 0 , V_3 [ V_17 -> type ] . V_59 , V_133 , stdout ) ;
}
if ( F_11 ( V_56 ) )
F_18 ( V_76 , V_17 ) ;
if ( F_11 ( V_180 ) )
F_24 ( V_76 ) ;
else if ( F_11 ( V_181 ) )
F_25 ( V_76 , V_85 ) ;
if ( F_53 ( V_12 ) && F_11 ( V_182 ) )
F_43 ( V_76 ) ;
printf ( L_48 ) ;
}
static void F_54 ( struct V_11 * V_183 , T_1 V_184 )
{
int V_185 = F_55 ( V_183 -> V_186 ) ;
int V_187 = F_56 ( V_183 ) ;
int V_93 , V_85 ;
static int V_188 ;
if ( V_183 -> V_189 )
V_185 = 1 ;
if ( ! V_188 ) {
printf ( L_67 ,
L_21 , L_68 , L_69 , L_70 , L_71 , L_20 , L_72 ) ;
V_188 = 1 ;
}
for ( V_85 = 0 ; V_85 < V_185 ; V_85 ++ ) {
for ( V_93 = 0 ; V_93 < V_187 ; V_93 ++ ) {
struct V_190 * V_191 ;
V_191 = F_57 ( V_183 -> V_191 , V_93 , V_85 ) ;
printf ( L_73 V_173 L_74 V_173 L_74 V_173 L_74 V_173 L_75 ,
V_183 -> V_192 -> V_114 [ V_93 ] ,
F_58 ( V_183 -> V_186 , V_85 ) ,
V_191 -> V_83 ,
V_191 -> V_193 ,
V_191 -> V_194 ,
V_184 ,
F_5 ( V_183 ) ) ;
}
}
}
static void F_59 ( struct V_11 * V_183 , T_1 V_184 )
{
if ( V_195 && V_195 -> F_59 )
V_195 -> F_59 ( & V_196 , V_183 , V_184 ) ;
else
F_54 ( V_183 , V_184 ) ;
}
static void F_60 ( T_1 V_184 )
{
if ( V_195 && V_195 -> F_60 )
V_195 -> F_60 ( V_184 ) ;
}
static void F_61 ( void )
{
F_62 () ;
F_63 () ;
}
static int F_64 ( void )
{
return V_195 ? V_195 -> V_197 () : 0 ;
}
static int F_65 ( void )
{
F_7 ( L_76 ) ;
return V_195 ? V_195 -> V_198 () : 0 ;
}
static int F_66 ( struct V_199 * V_200 ,
union V_201 * V_202 ,
struct V_75 * V_76 ,
struct V_11 * V_12 ,
struct V_203 * V_203 )
{
struct V_171 * V_204 = F_67 ( V_200 , struct V_171 , V_200 ) ;
struct V_109 V_117 ;
if ( V_205 ) {
if ( V_76 -> time < V_206 ) {
F_6 ( L_77 V_173
L_78 V_173 L_48 , V_206 ,
V_76 -> time ) ;
V_207 ++ ;
}
V_206 = V_76 -> time ;
return 0 ;
}
if ( F_68 ( V_203 , & V_117 , V_76 ) < 0 ) {
F_6 ( L_79 ,
V_202 -> V_22 . type ) ;
return - 1 ;
}
if ( V_117 . V_208 )
goto V_209;
if ( V_210 && ! F_69 ( V_76 -> V_93 , V_211 ) )
goto V_209;
if ( V_195 )
V_195 -> F_50 ( V_202 , V_76 , V_12 , & V_117 ) ;
else
F_50 ( V_204 , V_76 , V_12 , & V_117 ) ;
V_209:
F_70 ( & V_117 ) ;
return 0 ;
}
static int F_71 ( struct V_199 * V_200 , union V_201 * V_202 ,
struct V_163 * * V_212 )
{
struct V_171 * V_204 = F_67 ( V_200 , struct V_171 , V_200 ) ;
struct V_163 * V_164 ;
struct V_11 * V_12 , * V_140 ;
int V_213 ;
V_213 = F_72 ( V_200 , V_202 , V_212 ) ;
if ( V_213 )
return V_213 ;
V_164 = * V_212 ;
V_12 = F_73 ( * V_212 ) ;
if ( V_12 -> V_17 . type >= V_2 )
return 0 ;
F_17 (evlist, pos) {
if ( V_140 -> V_17 . type == V_12 -> V_17 . type && V_140 != V_12 )
return 0 ;
}
F_13 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_17 . V_13 )
V_213 = F_9 ( V_12 , V_204 -> V_21 ) ;
return V_213 ;
}
static int F_74 ( struct V_199 * V_200 ,
union V_201 * V_202 ,
struct V_75 * V_76 ,
struct V_203 * V_203 )
{
struct V_85 * V_85 ;
struct V_171 * V_172 = F_67 ( V_200 , struct V_171 , V_200 ) ;
struct V_20 * V_21 = V_172 -> V_21 ;
struct V_11 * V_12 = F_75 ( V_21 -> V_164 , V_76 -> V_214 ) ;
int V_215 = - 1 ;
V_85 = F_76 ( V_203 , V_202 -> V_216 . V_91 , V_202 -> V_216 . V_92 ) ;
if ( V_85 == NULL ) {
F_7 ( L_80 ) ;
return - 1 ;
}
if ( F_77 ( V_200 , V_202 , V_76 , V_203 ) < 0 )
goto V_74;
if ( ! V_12 -> V_17 . V_217 ) {
V_76 -> V_93 = 0 ;
V_76 -> time = 0 ;
V_76 -> V_92 = V_202 -> V_216 . V_92 ;
V_76 -> V_91 = V_202 -> V_216 . V_91 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_78 ( V_202 , stdout ) ;
V_215 = 0 ;
V_74:
F_79 ( V_85 ) ;
return V_215 ;
}
static int F_80 ( struct V_199 * V_200 ,
union V_201 * V_202 ,
struct V_75 * V_76 ,
struct V_203 * V_203 )
{
struct V_85 * V_85 ;
struct V_171 * V_172 = F_67 ( V_200 , struct V_171 , V_200 ) ;
struct V_20 * V_21 = V_172 -> V_21 ;
struct V_11 * V_12 = F_75 ( V_21 -> V_164 , V_76 -> V_214 ) ;
if ( F_81 ( V_200 , V_202 , V_76 , V_203 ) < 0 )
return - 1 ;
V_85 = F_76 ( V_203 , V_202 -> V_218 . V_91 , V_202 -> V_218 . V_92 ) ;
if ( V_85 == NULL ) {
F_7 ( L_81 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_217 ) {
V_76 -> V_93 = 0 ;
V_76 -> time = V_202 -> V_218 . time ;
V_76 -> V_92 = V_202 -> V_218 . V_92 ;
V_76 -> V_91 = V_202 -> V_218 . V_91 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_78 ( V_202 , stdout ) ;
F_79 ( V_85 ) ;
return 0 ;
}
static int F_82 ( struct V_199 * V_200 ,
union V_201 * V_202 ,
struct V_75 * V_76 ,
struct V_203 * V_203 )
{
int V_213 = 0 ;
struct V_85 * V_85 ;
struct V_171 * V_172 = F_67 ( V_200 , struct V_171 , V_200 ) ;
struct V_20 * V_21 = V_172 -> V_21 ;
struct V_11 * V_12 = F_75 ( V_21 -> V_164 , V_76 -> V_214 ) ;
V_85 = F_76 ( V_203 , V_202 -> V_218 . V_91 , V_202 -> V_218 . V_92 ) ;
if ( V_85 == NULL ) {
F_7 ( L_82 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_217 ) {
V_76 -> V_93 = 0 ;
V_76 -> time = 0 ;
V_76 -> V_92 = V_202 -> V_218 . V_92 ;
V_76 -> V_91 = V_202 -> V_218 . V_91 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_78 ( V_202 , stdout ) ;
if ( F_83 ( V_200 , V_202 , V_76 , V_203 ) < 0 )
V_213 = - 1 ;
F_79 ( V_85 ) ;
return V_213 ;
}
static int F_84 ( struct V_199 * V_200 ,
union V_201 * V_202 ,
struct V_75 * V_76 ,
struct V_203 * V_203 )
{
struct V_85 * V_85 ;
struct V_171 * V_172 = F_67 ( V_200 , struct V_171 , V_200 ) ;
struct V_20 * V_21 = V_172 -> V_21 ;
struct V_11 * V_12 = F_75 ( V_21 -> V_164 , V_76 -> V_214 ) ;
if ( F_85 ( V_200 , V_202 , V_76 , V_203 ) < 0 )
return - 1 ;
V_85 = F_76 ( V_203 , V_202 -> V_219 . V_91 , V_202 -> V_219 . V_92 ) ;
if ( V_85 == NULL ) {
F_7 ( L_83 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_217 ) {
V_76 -> V_93 = 0 ;
V_76 -> time = 0 ;
V_76 -> V_92 = V_202 -> V_219 . V_92 ;
V_76 -> V_91 = V_202 -> V_219 . V_91 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_78 ( V_202 , stdout ) ;
F_79 ( V_85 ) ;
return 0 ;
}
static int F_86 ( struct V_199 * V_200 ,
union V_201 * V_202 ,
struct V_75 * V_76 ,
struct V_203 * V_203 )
{
struct V_85 * V_85 ;
struct V_171 * V_172 = F_67 ( V_200 , struct V_171 , V_200 ) ;
struct V_20 * V_21 = V_172 -> V_21 ;
struct V_11 * V_12 = F_75 ( V_21 -> V_164 , V_76 -> V_214 ) ;
if ( F_87 ( V_200 , V_202 , V_76 , V_203 ) < 0 )
return - 1 ;
V_85 = F_76 ( V_203 , V_202 -> V_220 . V_91 , V_202 -> V_220 . V_92 ) ;
if ( V_85 == NULL ) {
F_7 ( L_84 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_217 ) {
V_76 -> V_93 = 0 ;
V_76 -> time = 0 ;
V_76 -> V_92 = V_202 -> V_220 . V_92 ;
V_76 -> V_91 = V_202 -> V_220 . V_91 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_78 ( V_202 , stdout ) ;
F_79 ( V_85 ) ;
return 0 ;
}
static int F_88 ( struct V_199 * V_200 ,
union V_201 * V_202 ,
struct V_75 * V_76 ,
struct V_203 * V_203 )
{
struct V_85 * V_85 ;
struct V_171 * V_172 = F_67 ( V_200 , struct V_171 , V_200 ) ;
struct V_20 * V_21 = V_172 -> V_21 ;
struct V_11 * V_12 = F_75 ( V_21 -> V_164 , V_76 -> V_214 ) ;
if ( F_89 ( V_200 , V_202 , V_76 , V_203 ) < 0 )
return - 1 ;
V_85 = F_76 ( V_203 , V_76 -> V_91 ,
V_76 -> V_92 ) ;
if ( V_85 == NULL ) {
F_7 ( L_85 ) ;
return - 1 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_78 ( V_202 , stdout ) ;
F_79 ( V_85 ) ;
return 0 ;
}
static void F_90 ( int T_5 V_221 )
{
V_222 = 1 ;
}
static int F_91 ( struct V_171 * V_172 )
{
int V_215 ;
signal ( V_223 , F_90 ) ;
if ( V_172 -> V_224 ) {
V_172 -> V_200 . V_216 = F_74 ;
V_172 -> V_200 . V_218 = F_80 ;
V_172 -> V_200 . exit = F_82 ;
}
if ( V_172 -> V_225 ) {
V_172 -> V_200 . V_219 = F_84 ;
V_172 -> V_200 . V_220 = F_86 ;
}
if ( V_172 -> V_226 )
V_172 -> V_200 . V_227 = F_88 ;
V_215 = F_92 ( V_172 -> V_21 ) ;
if ( V_205 )
F_6 ( L_86 V_173 L_48 , V_207 ) ;
return V_215 ;
}
static struct V_228 * F_93 ( const char * V_229 ,
struct V_195 * V_230 )
{
struct V_228 * V_231 = malloc ( sizeof( * V_231 ) + strlen ( V_229 ) + 1 ) ;
if ( V_231 != NULL ) {
strcpy ( V_231 -> V_229 , V_229 ) ;
V_231 -> V_230 = V_230 ;
}
return V_231 ;
}
static void F_94 ( struct V_228 * V_231 )
{
F_95 ( & V_231 -> V_232 , & V_233 ) ;
}
static struct V_228 * F_96 ( const char * V_229 )
{
struct V_228 * V_231 ;
F_97 (s, &script_specs, node)
if ( strcasecmp ( V_231 -> V_229 , V_229 ) == 0 )
return V_231 ;
return NULL ;
}
int F_98 ( const char * V_229 , struct V_195 * V_230 )
{
struct V_228 * V_231 ;
V_231 = F_96 ( V_229 ) ;
if ( V_231 )
return - 1 ;
V_231 = F_93 ( V_229 , V_230 ) ;
if ( ! V_231 )
return - 1 ;
else
F_94 ( V_231 ) ;
return 0 ;
}
static struct V_195 * F_99 ( const char * V_229 )
{
struct V_228 * V_231 = F_96 ( V_229 ) ;
if ( ! V_231 )
return NULL ;
return V_231 -> V_230 ;
}
static void F_100 ( void )
{
struct V_228 * V_231 ;
fprintf ( V_234 , L_48 ) ;
fprintf ( V_234 , L_87
L_88 ) ;
F_97 (s, &script_specs, node)
fprintf ( V_234 , L_89 , V_231 -> V_229 , V_231 -> V_230 -> V_120 ) ;
fprintf ( V_234 , L_48 ) ;
}
static int F_101 ( const struct V_235 * T_6 V_221 ,
const char * V_10 , int T_7 V_221 )
{
char V_229 [ V_236 ] ;
const char * V_172 , * V_237 ;
int V_122 ;
if ( strcmp ( V_10 , L_90 ) == 0 ) {
F_100 () ;
exit ( 0 ) ;
}
V_172 = strchr ( V_10 , ':' ) ;
if ( V_172 ) {
V_122 = V_172 - V_10 ;
if ( V_122 >= V_236 ) {
fprintf ( V_234 , L_91 ) ;
return - 1 ;
}
strncpy ( V_229 , V_10 , V_122 ) ;
V_229 [ V_122 ] = '\0' ;
V_195 = F_99 ( V_229 ) ;
if ( ! V_195 ) {
fprintf ( V_234 , L_91 ) ;
return - 1 ;
}
V_172 ++ ;
} else {
V_172 = V_10 ;
V_237 = strrchr ( V_172 , '.' ) ;
if ( ! V_237 ) {
fprintf ( V_234 , L_92 ) ;
return - 1 ;
}
V_195 = F_99 ( ++ V_237 ) ;
if ( ! V_195 ) {
fprintf ( V_234 , L_92 ) ;
return - 1 ;
}
}
V_238 = F_102 ( V_172 ) ;
return 0 ;
}
static int F_103 ( const struct V_235 * T_6 V_221 ,
const char * V_239 , int T_7 V_221 )
{
char * V_240 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_241 = 0 ;
char * V_10 = F_102 ( V_239 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_242 ;
V_240 = strchr ( V_10 , ':' ) ;
if ( V_240 ) {
* V_240 = '\0' ;
V_240 ++ ;
if ( ! strcmp ( V_10 , L_93 ) )
type = V_243 ;
else if ( ! strcmp ( V_10 , L_94 ) )
type = V_244 ;
else if ( ! strcmp ( V_10 , L_95 ) )
type = V_71 ;
else if ( ! strcmp ( V_10 , L_96 ) )
type = V_245 ;
else if ( ! strcmp ( V_10 , L_97 ) )
type = V_246 ;
else {
fprintf ( V_234 , L_98 ) ;
V_241 = - V_26 ;
goto V_74;
}
if ( V_3 [ type ] . V_4 )
F_104 ( L_99 ,
F_16 ( type ) ) ;
V_3 [ type ] . V_19 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_65 = false ;
} else {
V_240 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_234 ,
L_100 ) ;
V_241 = - V_26 ;
goto V_74;
}
if ( F_1 () )
F_104 ( L_101 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_19 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_65 = true ;
}
}
for ( V_240 = strtok ( V_240 , L_102 ) ; V_240 ; V_240 = strtok ( NULL , L_102 ) ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_240 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 && strcmp ( V_240 , L_103 ) == 0 ) {
V_177 = true ;
continue;
}
if ( V_7 == V_8 ) {
fprintf ( V_234 , L_104 ) ;
V_241 = - V_26 ;
goto V_74;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_247 & V_9 [ V_7 ] . V_6 ) {
F_104 ( L_105 ,
V_9 [ V_7 ] . V_10 , F_16 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_247 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_234 , L_106 ,
V_9 [ V_7 ] . V_10 , F_16 ( type ) ) ;
V_241 = - V_26 ;
goto V_74;
}
V_3 [ type ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_19 == 0 ) {
F_7 ( L_107
L_108 , F_16 ( type ) ) ;
}
}
V_74:
free ( V_10 ) ;
return V_241 ;
}
static int F_105 ( const char * V_248 , const struct V_249 * V_250 )
{
char V_251 [ V_236 ] ;
struct V_252 V_253 ;
sprintf ( V_251 , L_109 , V_248 , V_250 -> V_254 ) ;
if ( V_252 ( V_251 , & V_253 ) )
return 0 ;
return F_106 ( V_253 . V_255 ) ;
}
static struct V_256 * F_107 ( const char * V_120 )
{
struct V_256 * V_231 = F_108 ( sizeof( * V_231 ) ) ;
if ( V_231 != NULL && V_120 )
V_231 -> V_120 = F_102 ( V_120 ) ;
return V_231 ;
}
static void F_109 ( struct V_256 * V_231 )
{
F_110 ( & V_231 -> V_120 ) ;
F_110 ( & V_231 -> V_257 ) ;
F_110 ( & V_231 -> args ) ;
free ( V_231 ) ;
}
static void F_111 ( struct V_256 * V_231 )
{
F_95 ( & V_231 -> V_232 , & V_258 ) ;
}
static struct V_256 * F_112 ( const char * V_120 )
{
struct V_256 * V_231 ;
F_97 (s, &script_descs, node)
if ( strcasecmp ( V_231 -> V_120 , V_120 ) == 0 )
return V_231 ;
return NULL ;
}
static struct V_256 * F_113 ( const char * V_120 )
{
struct V_256 * V_231 = F_112 ( V_120 ) ;
if ( V_231 )
return V_231 ;
V_231 = F_107 ( V_120 ) ;
if ( ! V_231 )
goto V_259;
F_111 ( V_231 ) ;
return V_231 ;
V_259:
F_109 ( V_231 ) ;
return NULL ;
}
static const char * F_114 ( const char * V_10 , const char * V_260 )
{
T_3 V_261 = strlen ( V_260 ) ;
const char * V_262 = V_10 ;
if ( strlen ( V_10 ) > V_261 ) {
V_262 = V_10 + strlen ( V_10 ) - V_261 ;
if ( ! strncmp ( V_262 , V_260 , V_261 ) )
return V_262 ;
}
return NULL ;
}
static int F_115 ( struct V_256 * V_263 , const char * V_264 )
{
char line [ V_265 ] , * V_262 ;
T_8 * V_266 ;
V_266 = fopen ( V_264 , L_110 ) ;
if ( ! V_266 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_266 ) ) {
V_262 = F_116 ( line ) ;
if ( strlen ( V_262 ) == 0 )
continue;
if ( * V_262 != '#' )
continue;
V_262 ++ ;
if ( strlen ( V_262 ) && * V_262 == '!' )
continue;
V_262 = F_116 ( V_262 ) ;
if ( strlen ( V_262 ) && V_262 [ strlen ( V_262 ) - 1 ] == '\n' )
V_262 [ strlen ( V_262 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_262 , L_111 , strlen ( L_111 ) ) ) {
V_262 += strlen ( L_111 ) ;
V_263 -> V_257 = F_102 ( F_116 ( V_262 ) ) ;
continue;
}
if ( ! strncmp ( V_262 , L_112 , strlen ( L_112 ) ) ) {
V_262 += strlen ( L_112 ) ;
V_263 -> args = F_102 ( F_116 ( V_262 ) ) ;
continue;
}
}
fclose ( V_266 ) ;
return 0 ;
}
static char * F_117 ( struct V_249 * V_267 , const char * V_260 )
{
char * V_268 , * V_10 ;
V_268 = F_102 ( V_267 -> V_254 ) ;
if ( ! V_268 )
return NULL ;
V_10 = ( char * ) F_114 ( V_268 , V_260 ) ;
if ( ! V_10 ) {
free ( V_268 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_268 ;
}
static int F_118 ( const struct V_235 * T_6 V_221 ,
const char * V_231 V_221 ,
int T_7 V_221 )
{
struct V_249 * V_267 , * V_269 ;
char V_270 [ V_271 ] ;
T_9 * V_272 , * V_273 ;
char V_274 [ V_271 ] ;
char V_275 [ V_271 ] ;
struct V_256 * V_263 ;
char V_276 [ V_265 ] ;
char * V_268 ;
snprintf ( V_270 , V_271 , L_113 , F_119 () ) ;
V_272 = F_120 ( V_270 ) ;
if ( ! V_272 ) {
fprintf ( stdout ,
L_114
L_115 ,
V_270 ) ;
exit ( - 1 ) ;
}
F_121 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_275 , V_271 , L_116 , V_270 ,
V_269 -> V_254 ) ;
V_273 = F_120 ( V_275 ) ;
if ( ! V_273 )
continue;
F_122 (lang_path, lang_dir, script_dirent) {
V_268 = F_117 ( V_267 , V_277 ) ;
if ( V_268 ) {
V_263 = F_113 ( V_268 ) ;
snprintf ( V_274 , V_271 , L_109 ,
V_275 , V_267 -> V_254 ) ;
F_115 ( V_263 , V_274 ) ;
free ( V_268 ) ;
}
}
}
fprintf ( stdout , L_117 ) ;
F_97 (desc, &script_descs, node) {
sprintf ( V_276 , L_118 , V_263 -> V_120 ,
V_263 -> args ? V_263 -> args : L_1 ) ;
fprintf ( stdout , L_119 , V_276 ,
V_263 -> V_257 ? V_263 -> V_257 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_123 ( char * V_278 , char * V_279 ,
struct V_20 * V_21 )
{
char V_264 [ V_271 ] , V_18 [ 128 ] ;
char line [ V_265 ] , * V_262 ;
struct V_11 * V_140 ;
int V_280 , V_122 ;
T_8 * V_266 ;
sprintf ( V_264 , L_120 , V_278 , V_279 ) ;
V_266 = fopen ( V_264 , L_110 ) ;
if ( ! V_266 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_266 ) ) {
V_262 = F_116 ( line ) ;
if ( * V_262 == '#' )
continue;
while ( strlen ( V_262 ) ) {
V_262 = strstr ( V_262 , L_121 ) ;
if ( ! V_262 )
break;
V_262 += 2 ;
V_262 = F_116 ( V_262 ) ;
V_122 = strcspn ( V_262 , L_122 ) ;
if ( ! V_122 )
break;
snprintf ( V_18 , V_122 + 1 , L_123 , V_262 ) ;
V_280 = 0 ;
F_17 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_140 ) , V_18 ) ) {
V_280 = 1 ;
break;
}
}
if ( ! V_280 ) {
fclose ( V_266 ) ;
return - 1 ;
}
}
}
fclose ( V_266 ) ;
return 0 ;
}
int F_124 ( char * * V_281 , char * * V_282 )
{
struct V_249 * V_267 , * V_269 ;
char V_270 [ V_271 ] , V_275 [ V_271 ] ;
T_9 * V_272 , * V_273 ;
struct V_20 * V_21 ;
struct V_283 V_284 = {
. V_251 = V_285 ,
. V_286 = V_287 ,
} ;
char * V_288 ;
int V_7 = 0 ;
V_21 = F_125 ( & V_284 , false , NULL ) ;
if ( ! V_21 )
return - 1 ;
snprintf ( V_270 , V_271 , L_113 , F_119 () ) ;
V_272 = F_120 ( V_270 ) ;
if ( ! V_272 ) {
F_126 ( V_21 ) ;
return - 1 ;
}
F_121 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_275 , V_271 , L_109 , V_270 ,
V_269 -> V_254 ) ;
#ifdef F_127
if ( strstr ( V_275 , L_124 ) )
continue;
#endif
#ifdef F_128
if ( strstr ( V_275 , L_125 ) )
continue;
#endif
V_273 = F_120 ( V_275 ) ;
if ( ! V_273 )
continue;
F_122 (lang_path, lang_dir, script_dirent) {
if ( strstr ( V_267 -> V_254 , L_126 ) )
continue;
sprintf ( V_282 [ V_7 ] , L_109 , V_275 ,
V_267 -> V_254 ) ;
V_288 = strchr ( V_267 -> V_254 , '.' ) ;
snprintf ( V_281 [ V_7 ] ,
( V_288 - V_267 -> V_254 ) + 1 ,
L_123 , V_267 -> V_254 ) ;
if ( F_123 ( V_275 ,
V_281 [ V_7 ] , V_21 ) )
continue;
V_7 ++ ;
}
F_129 ( V_273 ) ;
}
F_129 ( V_272 ) ;
F_126 ( V_21 ) ;
return V_7 ;
}
static char * F_130 ( const char * V_268 , const char * V_260 )
{
struct V_249 * V_267 , * V_269 ;
char V_270 [ V_271 ] ;
char V_274 [ V_271 ] ;
T_9 * V_272 , * V_273 ;
char V_275 [ V_271 ] ;
char * V_289 ;
snprintf ( V_270 , V_271 , L_113 , F_119 () ) ;
V_272 = F_120 ( V_270 ) ;
if ( ! V_272 )
return NULL ;
F_121 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_275 , V_271 , L_116 , V_270 ,
V_269 -> V_254 ) ;
V_273 = F_120 ( V_275 ) ;
if ( ! V_273 )
continue;
F_122 (lang_path, lang_dir, script_dirent) {
V_289 = F_117 ( V_267 , V_260 ) ;
if ( V_289 && ! strcmp ( V_268 , V_289 ) ) {
free ( V_289 ) ;
F_129 ( V_273 ) ;
F_129 ( V_272 ) ;
snprintf ( V_274 , V_271 , L_109 ,
V_275 , V_267 -> V_254 ) ;
return F_102 ( V_274 ) ;
}
free ( V_289 ) ;
}
F_129 ( V_273 ) ;
}
F_129 ( V_272 ) ;
return NULL ;
}
static bool F_131 ( const char * V_274 )
{
return F_114 ( V_274 , L_127 ) == NULL ? false : true ;
}
static int F_132 ( char * V_274 )
{
struct V_256 * V_263 ;
int V_290 = 0 ;
char * V_262 ;
V_263 = F_107 ( NULL ) ;
if ( F_115 ( V_263 , V_274 ) )
goto V_74;
if ( ! V_263 -> args )
goto V_74;
for ( V_262 = V_263 -> args ; * V_262 ; V_262 ++ )
if ( * V_262 == '<' )
V_290 ++ ;
V_74:
F_109 ( V_263 ) ;
return V_290 ;
}
static int F_133 ( int V_291 , const char * * V_292 )
{
char * * V_293 = malloc ( sizeof( const char * ) * V_291 ) ;
if ( ! V_293 ) {
F_6 ( L_128 ) ;
return - 1 ;
}
memcpy ( V_293 , V_292 , sizeof( const char * ) * V_291 ) ;
V_291 = F_134 ( V_291 , ( const char * * ) V_293 , V_294 ,
NULL , V_295 ) ;
free ( V_293 ) ;
V_189 = ( V_291 == 0 ) ;
return 0 ;
}
static void F_135 ( struct V_171 * V_172 )
{
struct V_20 * V_21 = V_172 -> V_21 ;
T_1 V_13 = F_136 ( V_21 -> V_164 ) ;
if ( V_70 . V_67 || V_70 . V_296 ) {
if ( ( V_13 & V_297 ) &&
( V_13 & V_298 ) )
V_299 . V_300 = V_301 ;
else if ( V_13 & V_302 )
V_299 . V_300 = V_303 ;
else
V_299 . V_300 = V_304 ;
}
}
static int F_137 ( struct V_199 * V_200 V_221 ,
union V_201 * V_202 ,
struct V_20 * V_21 )
{
struct V_305 * V_306 = & V_202 -> V_307 ;
struct V_11 * V_183 ;
F_17 (session->evlist, counter) {
F_138 ( & V_196 , V_183 ) ;
F_59 ( V_183 , V_306 -> time ) ;
}
F_60 ( V_306 -> time ) ;
return 0 ;
}
static int F_139 ( struct V_199 * V_200 V_221 ,
union V_201 * V_202 ,
struct V_20 * V_21 V_221 )
{
F_140 ( & V_196 , & V_202 -> V_196 ) ;
return 0 ;
}
static int F_141 ( struct V_171 * V_172 )
{
struct V_163 * V_164 = V_172 -> V_21 -> V_164 ;
if ( ! V_172 -> V_192 || ! V_172 -> V_186 )
return 0 ;
if ( F_142 ( V_172 -> V_308 , L_129 ) )
return - V_26 ;
F_143 ( V_164 , V_172 -> V_192 , V_172 -> V_186 ) ;
if ( F_144 ( V_164 , true ) )
return - V_242 ;
V_172 -> V_308 = true ;
return 0 ;
}
static
int F_145 ( struct V_199 * V_200 ,
union V_201 * V_202 ,
struct V_20 * V_21 V_221 )
{
struct V_171 * V_172 = F_67 ( V_200 , struct V_171 , V_200 ) ;
if ( V_172 -> V_186 ) {
F_104 ( L_130 ) ;
return 0 ;
}
V_172 -> V_186 = F_146 ( & V_202 -> V_309 ) ;
if ( ! V_172 -> V_186 )
return - V_242 ;
return F_141 ( V_172 ) ;
}
static
int F_147 ( struct V_199 * V_200 V_221 ,
union V_201 * V_202 ,
struct V_20 * V_21 V_221 )
{
struct V_171 * V_172 = F_67 ( V_200 , struct V_171 , V_200 ) ;
if ( V_172 -> V_192 ) {
F_104 ( L_131 ) ;
return 0 ;
}
V_172 -> V_192 = F_148 ( & V_202 -> V_310 . V_311 ) ;
if ( ! V_172 -> V_192 )
return - V_242 ;
return F_141 ( V_172 ) ;
}
int F_149 ( int V_291 , const char * * V_292 , const char * T_10 V_221 )
{
bool V_312 = false ;
bool V_22 = false ;
bool V_313 = false ;
bool V_314 = false ;
char * V_315 = NULL ;
char * V_316 = NULL ;
struct V_20 * V_21 ;
struct V_317 V_317 = { . V_318 = false , } ;
char * V_274 = NULL ;
const char * * V_293 ;
int V_7 , V_1 , V_213 = 0 ;
struct V_171 V_172 = {
. V_200 = {
. V_76 = F_66 ,
. V_219 = F_85 ,
. V_220 = F_87 ,
. V_216 = F_77 ,
. exit = F_83 ,
. V_218 = F_81 ,
. V_17 = F_71 ,
. V_319 = V_320 ,
. V_321 = V_322 ,
. V_323 = V_324 ,
. V_325 = V_326 ,
. V_327 = V_328 ,
. V_329 = V_330 ,
. V_331 = V_332 ,
. V_252 = V_333 ,
. V_307 = F_137 ,
. V_196 = F_139 ,
. V_309 = F_145 ,
. V_310 = F_147 ,
. V_334 = true ,
. V_335 = true ,
} ,
} ;
struct V_283 V_284 = {
. V_286 = V_287 ,
} ;
const struct V_235 V_336 [] = {
F_150 ( 'D' , L_132 , & V_337 ,
L_133 ) ,
F_151 ( 'v' , L_134 , & V_338 ,
L_135 ) ,
F_150 ( 'L' , L_136 , & V_90 ,
L_137 ) ,
F_152 ( 'l' , L_138 , NULL , NULL , L_139 ,
F_118 ) ,
F_153 ( 's' , L_140 , NULL , L_141 ,
L_142 ,
F_101 ) ,
F_154 ( 'g' , L_143 , & V_339 , L_90 ,
L_144 ) ,
F_154 ( 'i' , L_145 , & V_285 , L_146 , L_147 ) ,
F_150 ( 'd' , L_148 , & V_205 ,
L_149 ) ,
F_150 ( 0 , L_150 , & V_22 , L_151 ) ,
F_150 ( 0 , L_152 , & V_313 , L_153 ) ,
F_154 ( 'k' , L_154 , & V_70 . V_340 ,
L_146 , L_155 ) ,
F_154 ( 0 , L_156 , & V_70 . V_341 ,
L_146 , L_157 ) ,
F_150 ( 'G' , L_158 , & V_66 ,
L_159 ) ,
F_153 ( 0 , L_160 , NULL , L_161 ,
L_162 ,
V_342 ) ,
F_153 ( 'F' , L_163 , NULL , L_164 ,
L_165
L_166
L_167
L_168
L_169 , F_103 ) ,
F_150 ( 'a' , L_170 , & V_189 ,
L_171 ) ,
F_154 ( 'S' , L_172 , & V_70 . V_343 , L_173 ,
L_174 ) ,
F_154 ( 'C' , L_175 , & V_210 , L_175 , L_176 ) ,
F_154 ( 'c' , L_177 , & V_70 . V_344 , L_178 ,
L_179 ) ,
F_154 ( 0 , L_180 , & V_70 . V_345 , L_181 ,
L_182 ) ,
F_154 ( 0 , L_183 , & V_70 . V_346 , L_184 ,
L_185 ) ,
F_155 ( 0 , L_186 , & V_135 ,
L_187
L_188
L_189 F_156 ( V_347 ) ) ,
F_150 ( 'I' , L_190 , & V_312 ,
L_191 ) ,
F_150 ( '\0' , L_192 , & V_70 . V_348 ,
L_193 ) ,
F_150 ( '\0' , L_194 , & V_172 . V_224 ,
L_195 ) ,
F_150 ( '\0' , L_196 , & V_172 . V_225 ,
L_197 ) ,
F_150 ( '\0' , L_198 , & V_172 . V_226 ,
L_199 ) ,
F_150 ( 'f' , L_200 , & V_284 . V_349 , L_201 ) ,
F_150 ( 0 , L_202 , & V_96 ,
L_203 ) ,
F_157 ( 0 , L_204 , & V_317 , NULL , L_205 ,
L_206 ,
V_350 ) ,
F_150 ( 0 , L_207 , & V_351 ,
L_208 ) ,
F_150 ( 0 , L_209 , & V_70 . V_352 ,
L_210 ) ,
F_150 ( 0 , L_211 , & V_70 . V_353 ,
L_212 ) ,
F_158 ()
} ;
const char * const V_354 [] = { L_213 , L_214 , NULL } ;
const char * V_355 [] = {
L_215 ,
L_216 ,
L_217 ,
L_218 ,
L_219 ,
NULL
} ;
F_61 () ;
V_291 = F_159 ( V_291 , V_292 , V_336 , V_354 , V_355 ,
V_295 ) ;
V_284 . V_251 = V_285 ;
if ( V_291 > 1 && ! strncmp ( V_292 [ 0 ] , L_220 , strlen ( L_220 ) ) ) {
V_315 = F_130 ( V_292 [ 1 ] , V_356 ) ;
if ( ! V_315 )
return F_160 ( V_291 , V_292 , NULL ) ;
}
if ( V_291 > 1 && ! strncmp ( V_292 [ 0 ] , L_221 , strlen ( L_221 ) ) ) {
V_316 = F_130 ( V_292 [ 1 ] , V_277 ) ;
if ( ! V_316 ) {
fprintf ( V_234 ,
L_222
L_223 ) ;
return - 1 ;
}
}
if ( V_317 . V_134 &&
V_317 . V_357 > V_135 )
V_135 = V_317 . V_357 ;
F_161 ( F_119 () ) ;
if ( V_291 && ! V_238 && ! V_315 && ! V_316 ) {
int V_358 [ 2 ] ;
int V_359 ;
T_11 V_91 ;
V_315 = F_130 ( V_292 [ 0 ] , V_356 ) ;
V_316 = F_130 ( V_292 [ 0 ] , V_277 ) ;
if ( ! V_315 && ! V_316 ) {
F_162 ( V_355 , V_336 ,
L_224
L_225 , V_292 [ 0 ] ) ;
}
if ( F_131 ( V_292 [ 0 ] ) ) {
V_359 = V_291 - 1 ;
} else {
int V_360 ;
V_359 = F_132 ( V_316 ) ;
V_360 = ( V_291 - 1 ) - V_359 ;
if ( V_360 < 0 ) {
F_162 ( V_355 , V_336 ,
L_226
L_227
L_228 , V_292 [ 0 ] ) ;
}
}
if ( F_163 ( V_358 ) < 0 ) {
perror ( L_229 ) ;
return - 1 ;
}
V_91 = V_218 () ;
if ( V_91 < 0 ) {
perror ( L_230 ) ;
return - 1 ;
}
if ( ! V_91 ) {
V_1 = 0 ;
F_164 ( V_358 [ 1 ] , 1 ) ;
F_165 ( V_358 [ 0 ] ) ;
if ( F_131 ( V_292 [ 0 ] ) ) {
V_189 = true ;
} else if ( ! V_189 ) {
if ( F_133 ( V_291 - V_359 , & V_292 [ V_359 ] ) != 0 ) {
V_213 = - 1 ;
goto V_74;
}
}
V_293 = malloc ( ( V_291 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_293 ) {
F_6 ( L_128 ) ;
V_213 = - V_242 ;
goto V_74;
}
V_293 [ V_1 ++ ] = L_231 ;
V_293 [ V_1 ++ ] = V_315 ;
if ( V_189 )
V_293 [ V_1 ++ ] = L_232 ;
V_293 [ V_1 ++ ] = L_233 ;
V_293 [ V_1 ++ ] = L_234 ;
V_293 [ V_1 ++ ] = L_235 ;
for ( V_7 = V_359 + 1 ; V_7 < V_291 ; V_7 ++ )
V_293 [ V_1 ++ ] = V_292 [ V_7 ] ;
V_293 [ V_1 ++ ] = NULL ;
F_166 ( L_231 , ( char * * ) V_293 ) ;
free ( V_293 ) ;
exit ( - 1 ) ;
}
F_164 ( V_358 [ 0 ] , 0 ) ;
F_165 ( V_358 [ 1 ] ) ;
V_293 = malloc ( ( V_291 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_293 ) {
F_6 ( L_128 ) ;
V_213 = - V_242 ;
goto V_74;
}
V_1 = 0 ;
V_293 [ V_1 ++ ] = L_231 ;
V_293 [ V_1 ++ ] = V_316 ;
for ( V_7 = 1 ; V_7 < V_359 + 1 ; V_7 ++ )
V_293 [ V_1 ++ ] = V_292 [ V_7 ] ;
V_293 [ V_1 ++ ] = L_236 ;
V_293 [ V_1 ++ ] = L_235 ;
V_293 [ V_1 ++ ] = NULL ;
F_166 ( L_231 , ( char * * ) V_293 ) ;
free ( V_293 ) ;
exit ( - 1 ) ;
}
if ( V_315 )
V_274 = V_315 ;
if ( V_316 )
V_274 = V_316 ;
if ( V_274 ) {
V_1 = 0 ;
if ( ! V_315 )
V_189 = false ;
else if ( ! V_189 ) {
if ( F_133 ( V_291 - 1 , & V_292 [ 1 ] ) != 0 ) {
V_213 = - 1 ;
goto V_74;
}
}
V_293 = malloc ( ( V_291 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_293 ) {
F_6 ( L_128 ) ;
V_213 = - V_242 ;
goto V_74;
}
V_293 [ V_1 ++ ] = L_231 ;
V_293 [ V_1 ++ ] = V_274 ;
if ( V_189 )
V_293 [ V_1 ++ ] = L_232 ;
for ( V_7 = 2 ; V_7 < V_291 ; V_7 ++ )
V_293 [ V_1 ++ ] = V_292 [ V_7 ] ;
V_293 [ V_1 ++ ] = NULL ;
F_166 ( L_231 , ( char * * ) V_293 ) ;
free ( V_293 ) ;
exit ( - 1 ) ;
}
if ( ! V_238 )
F_167 () ;
V_21 = F_125 ( & V_284 , false , & V_172 . V_200 ) ;
if ( V_21 == NULL )
return - 1 ;
if ( V_22 || V_313 ) {
F_168 ( V_21 , stdout , V_312 ) ;
if ( V_313 )
goto V_361;
}
if ( F_169 ( & V_21 -> V_22 . V_362 ) < 0 )
goto V_361;
V_172 . V_21 = V_21 ;
F_135 ( & V_172 ) ;
if ( V_3 [ V_243 ] . V_19 & V_363 )
V_317 . V_364 = true ;
V_21 -> V_317 = & V_317 ;
if ( V_210 ) {
V_213 = F_170 ( V_21 , V_210 , V_211 ) ;
if ( V_213 < 0 )
goto V_361;
}
if ( ! V_66 )
V_70 . V_67 = true ;
else
V_70 . V_67 = false ;
if ( V_21 -> V_365 . V_366 &&
F_171 ( V_21 -> V_365 . V_366 ,
V_367 ,
& V_21 -> V_368 . V_369 ) < 0 ) {
F_6 ( L_237 , V_370 ) ;
return - 1 ;
}
if ( V_339 ) {
struct V_252 V_371 ;
int V_372 ;
if ( F_1 () ) {
fprintf ( V_234 ,
L_238 ) ;
V_213 = - V_26 ;
goto V_361;
}
V_372 = F_172 ( V_284 . V_251 , V_373 ) ;
if ( V_372 < 0 ) {
V_213 = - V_374 ;
perror ( L_239 ) ;
goto V_361;
}
V_213 = F_173 ( V_372 , & V_371 ) ;
if ( V_213 < 0 ) {
perror ( L_240 ) ;
goto V_361;
}
if ( ! V_371 . V_375 ) {
fprintf ( V_234 , L_241 ) ;
goto V_361;
}
V_195 = F_99 ( V_339 ) ;
if ( ! V_195 ) {
fprintf ( V_234 , L_91 ) ;
V_213 = - V_376 ;
goto V_361;
}
V_213 = V_195 -> V_377 ( V_21 -> V_365 . V_366 ,
L_242 ) ;
goto V_361;
}
if ( V_238 ) {
V_213 = V_195 -> V_378 ( V_238 , V_291 , V_292 ) ;
if ( V_213 )
goto V_361;
F_7 ( L_243 , V_238 ) ;
V_314 = true ;
}
V_213 = F_14 ( V_21 ) ;
if ( V_213 < 0 )
goto V_361;
V_213 = F_91 ( & V_172 ) ;
F_64 () ;
V_361:
F_174 ( V_21 -> V_164 ) ;
F_126 ( V_21 ) ;
if ( V_314 )
F_65 () ;
V_74:
return V_213 ;
}
