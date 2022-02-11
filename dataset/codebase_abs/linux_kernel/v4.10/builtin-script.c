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
unsigned long long V_87 ;
if ( F_11 ( V_88 ) ) {
if ( V_89 )
printf ( L_28 , F_22 ( V_85 ) ) ;
else if ( F_11 ( V_27 ) && V_70 . V_67 )
printf ( L_29 , F_22 ( V_85 ) ) ;
else
printf ( L_30 , F_22 ( V_85 ) ) ;
}
if ( F_11 ( V_43 ) && F_11 ( V_44 ) )
printf ( L_31 , V_76 -> V_90 , V_76 -> V_91 ) ;
else if ( F_11 ( V_43 ) )
printf ( L_32 , V_76 -> V_90 ) ;
else if ( F_11 ( V_44 ) )
printf ( L_32 , V_76 -> V_91 ) ;
if ( F_11 ( V_50 ) ) {
if ( V_89 )
printf ( L_33 , V_76 -> V_92 ) ;
else
printf ( L_34 , V_76 -> V_92 ) ;
}
if ( F_11 ( TIME ) ) {
V_87 = V_76 -> time ;
V_86 = V_87 / V_93 ;
V_87 -= V_86 * V_93 ;
if ( V_94 )
printf ( L_35 , V_86 , V_87 ) ;
else {
char V_95 [ 32 ] ;
F_23 ( V_76 -> time , V_95 , sizeof( V_95 ) ) ;
printf ( L_36 , V_95 ) ;
}
}
}
static inline char
F_24 ( struct V_96 * V_97 )
{
if ( ! ( V_97 -> V_98 . V_99 || V_97 -> V_98 . V_100 ) )
return '-' ;
return V_97 -> V_98 . V_100 ? 'P' : 'M' ;
}
static void F_25 ( struct V_75 * V_76 )
{
struct V_101 * V_97 = V_76 -> V_101 ;
T_1 V_7 ;
if ( ! ( V_97 && V_97 -> V_102 ) )
return;
for ( V_7 = 0 ; V_7 < V_97 -> V_102 ; V_7 ++ ) {
printf ( L_37 V_84 L_38 V_84 L_39 ,
V_97 -> V_103 [ V_7 ] . V_104 ,
V_97 -> V_103 [ V_7 ] . V_105 ,
F_24 ( V_97 -> V_103 + V_7 ) ,
V_97 -> V_103 [ V_7 ] . V_98 . V_106 ? 'X' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . abort ? 'A' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . V_107 ) ;
}
}
static void F_26 ( struct V_75 * V_76 ,
struct V_85 * V_85 )
{
struct V_101 * V_97 = V_76 -> V_101 ;
struct V_108 V_109 , V_110 ;
T_1 V_7 , V_104 , V_105 ;
if ( ! ( V_97 && V_97 -> V_102 ) )
return;
for ( V_7 = 0 ; V_7 < V_97 -> V_102 ; V_7 ++ ) {
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_104 = V_97 -> V_103 [ V_7 ] . V_104 ;
V_105 = V_97 -> V_103 [ V_7 ] . V_105 ;
F_27 ( V_85 , V_76 -> V_111 , V_112 , V_104 , & V_109 ) ;
if ( V_109 . V_113 )
V_109 . V_114 = F_28 ( V_109 . V_113 , V_109 . V_115 ) ;
F_27 ( V_85 , V_76 -> V_111 , V_112 , V_105 , & V_110 ) ;
if ( V_110 . V_113 )
V_110 . V_114 = F_28 ( V_110 . V_113 , V_110 . V_115 ) ;
F_29 ( V_109 . V_114 , & V_109 , stdout ) ;
putchar ( '/' ) ;
F_29 ( V_110 . V_114 , & V_110 , stdout ) ;
printf ( L_39 ,
F_24 ( V_97 -> V_103 + V_7 ) ,
V_97 -> V_103 [ V_7 ] . V_98 . V_106 ? 'X' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . abort ? 'A' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . V_107 ) ;
}
}
static void F_30 ( struct V_75 * V_76 ,
struct V_85 * V_85 ,
struct V_16 * V_17 )
{
struct V_108 V_116 ;
printf ( L_40 V_84 , V_76 -> V_115 ) ;
if ( ! F_31 ( V_17 ) )
return;
F_32 ( V_85 , & V_116 , V_76 ) ;
if ( F_11 ( V_39 ) ) {
printf ( L_27 ) ;
if ( F_11 ( V_40 ) )
F_29 ( V_116 . V_114 , & V_116 , stdout ) ;
else
F_33 ( V_116 . V_114 , stdout ) ;
}
if ( F_11 ( V_41 ) ) {
printf ( L_41 ) ;
F_34 ( V_116 . V_113 , stdout ) ;
printf ( L_42 ) ;
}
}
static void F_35 ( struct V_75 * V_76 ,
struct V_11 * V_12 ,
struct V_85 * V_85 ,
struct V_108 * V_116 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
T_3 V_117 = F_36 ( V_85 ) ;
struct V_108 V_118 ;
const char * V_119 = NULL ;
static int V_120 ;
int V_121 = 0 ;
T_1 V_122 = 0 ;
if ( V_85 -> V_123 && V_76 -> V_98 & V_124 )
V_117 += 1 ;
if ( V_76 -> V_98 & ( V_125 | V_126 ) ) {
if ( F_31 ( V_17 ) ) {
F_32 ( V_85 , & V_118 , V_76 ) ;
if ( V_118 . V_114 )
V_119 = V_118 . V_114 -> V_119 ;
else
V_122 = V_76 -> V_115 ;
} else {
V_122 = V_76 -> V_115 ;
}
} else if ( V_76 -> V_98 & ( V_124 | V_127 ) ) {
if ( V_116 -> V_114 )
V_119 = V_116 -> V_114 -> V_119 ;
else
V_122 = V_76 -> V_122 ;
}
if ( V_119 )
V_121 = printf ( L_43 , ( int ) V_117 * 4 , L_1 , V_119 ) ;
else if ( V_122 )
V_121 = printf ( L_44 V_84 , ( int ) V_117 * 4 , L_1 , V_122 ) ;
if ( V_121 < 0 )
return;
if ( V_121 > V_120 || ( V_121 && V_121 < V_120 - 52 ) )
V_120 = F_37 ( V_121 + 4 , 32 ) ;
if ( V_121 < V_120 )
printf ( L_45 , V_120 - V_121 , L_1 ) ;
}
static void F_38 ( struct V_75 * V_76 ,
struct V_16 * V_17 )
{
if ( F_11 ( V_128 ) )
printf ( L_46 , V_76 -> V_129 ) ;
if ( F_11 ( V_130 ) ) {
int V_7 ;
printf ( L_47 ) ;
for ( V_7 = 0 ; V_7 < V_76 -> V_129 ; V_7 ++ )
printf ( L_48 , ( unsigned char ) V_76 -> V_131 [ V_7 ] ) ;
}
}
static void F_39 ( struct V_75 * V_76 ,
struct V_11 * V_12 ,
struct V_85 * V_85 ,
struct V_108 * V_116 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_132 = false ;
if ( F_11 ( V_133 ) )
F_35 ( V_76 , V_12 , V_85 , V_116 ) ;
if ( F_11 ( V_27 ) ) {
unsigned int V_134 = V_3 [ V_17 -> type ] . V_59 ;
struct V_135 * V_136 = NULL ;
if ( V_70 . V_67 && V_76 -> V_137 &&
F_40 ( V_116 -> V_85 , & V_135 , V_12 ,
V_76 , NULL , NULL , V_138 ) == 0 )
V_136 = & V_135 ;
if ( V_136 == NULL ) {
putchar ( ' ' ) ;
if ( V_134 & V_64 ) {
V_132 = true ;
V_134 &= ~ V_64 ;
}
} else
putchar ( '\n' ) ;
F_41 ( V_76 , V_116 , 0 , V_134 , V_136 , stdout ) ;
}
if ( F_11 ( V_30 ) ||
( ( V_12 -> V_17 . V_13 & V_31 ) &&
! V_3 [ V_17 -> type ] . V_4 ) ) {
printf ( L_49 ) ;
F_30 ( V_76 , V_85 , V_17 ) ;
}
if ( V_132 )
F_42 ( V_116 -> V_113 , V_116 -> V_115 , L_50 , stdout ) ;
F_38 ( V_76 , V_17 ) ;
printf ( L_51 ) ;
}
static void F_43 ( T_4 V_98 )
{
const char * V_139 = V_140 ;
const int V_141 = strlen ( V_140 ) ;
bool V_106 = V_98 & V_142 ;
const char * V_119 = NULL ;
char V_10 [ 33 ] ;
int V_7 , V_143 = 0 ;
for ( V_7 = 0 ; V_144 [ V_7 ] . V_119 ; V_7 ++ ) {
if ( V_144 [ V_7 ] . V_98 == ( V_98 & ~ V_142 ) ) {
V_119 = V_144 [ V_7 ] . V_119 ;
break;
}
}
for ( V_7 = 0 ; V_7 < V_141 ; V_7 ++ , V_98 >>= 1 ) {
if ( V_98 & 1 )
V_10 [ V_143 ++ ] = V_139 [ V_7 ] ;
}
for (; V_7 < 32 ; V_7 ++ , V_98 >>= 1 ) {
if ( V_98 & 1 )
V_10 [ V_143 ++ ] = '?' ;
}
V_10 [ V_143 ] = 0 ;
if ( V_119 )
printf ( L_52 , V_119 , V_106 ? L_53 : L_1 ) ;
else
printf ( L_54 , V_10 ) ;
}
static void
F_44 ( enum V_145 V_146 ,
unsigned int V_83 ,
void * V_147 )
{
unsigned char V_148 = ( unsigned char ) V_83 ;
struct V_149 * V_149 = V_147 ;
switch ( V_146 ) {
case V_150 :
printf ( L_51 ) ;
break;
case V_151 :
printf ( L_55 , ! V_149 -> V_152 ? L_56 :
L_57 ) ;
break;
case V_153 :
printf ( L_58 , V_83 ) ;
break;
case V_154 :
printf ( L_48 , V_83 ) ;
break;
case V_155 :
printf ( L_59 ) ;
break;
case V_156 :
printf ( L_60 ) ;
break;
case V_157 :
if ( V_149 -> V_158 && V_148 )
V_149 -> V_159 = false ;
if ( ! isprint ( V_148 ) ) {
printf ( L_61 , '.' ) ;
if ( ! V_149 -> V_159 )
break;
if ( V_148 == '\0' )
V_149 -> V_158 = true ;
else
V_149 -> V_159 = false ;
} else {
printf ( L_61 , V_148 ) ;
}
break;
case V_160 :
printf ( L_27 ) ;
break;
case V_161 :
printf ( L_51 ) ;
V_149 -> V_152 ++ ;
break;
case V_162 :
default:
break;
}
}
static void F_45 ( struct V_75 * V_76 )
{
unsigned int V_163 = V_76 -> V_164 ;
struct V_149 V_149 = { 0 , false , true } ;
F_46 ( V_76 -> V_165 , V_163 , 8 ,
F_44 , & V_149 ) ;
if ( V_149 . V_159 && V_149 . V_158 )
printf ( L_62 , L_63 ,
( char * ) ( V_76 -> V_165 ) ) ;
}
static int F_47 ( struct V_166 * V_167 )
{
struct V_11 * V_12 ;
int V_168 = 0 ;
F_17 (evlist, evsel) {
int V_121 = strlen ( F_5 ( V_12 ) ) ;
V_168 = F_48 ( V_121 , V_168 ) ;
}
return V_168 ;
}
static T_3 F_49 ( T_1 V_169 )
{
struct V_170 V_171 = { . V_169 . V_83 = V_169 } ;
char V_172 [ 100 ] ;
char V_74 [ 100 ] ;
static int V_173 ;
int V_121 ;
F_50 ( V_172 , 100 , & V_171 ) ;
V_121 = F_51 ( V_74 , 100 , L_40 V_84 L_64 , V_169 , V_172 ) ;
if ( V_173 < V_121 )
V_173 = V_121 ;
return printf ( L_65 , V_173 , V_74 ) ;
}
static void F_52 ( struct V_174 * V_175 ,
struct V_75 * V_76 , struct V_11 * V_12 ,
struct V_108 * V_116 )
{
struct V_85 * V_85 = V_116 -> V_85 ;
struct V_16 * V_17 = & V_12 -> V_17 ;
if ( V_3 [ V_17 -> type ] . V_19 == 0 )
return;
F_21 ( V_76 , V_85 , V_12 ) ;
if ( F_11 ( V_53 ) )
printf ( L_66 V_176 L_27 , V_76 -> V_177 ) ;
if ( F_11 ( V_178 ) ) {
const char * V_18 = F_5 ( V_12 ) ;
if ( ! V_175 -> V_179 )
V_175 -> V_179 = F_47 ( V_175 -> V_21 -> V_167 ) ;
printf ( L_67 , V_175 -> V_179 ,
V_18 ? V_18 : L_68 ) ;
}
if ( V_180 )
F_43 ( V_76 -> V_98 ) ;
if ( F_53 ( V_17 ) ) {
F_39 ( V_76 , V_12 , V_85 , V_116 ) ;
return;
}
if ( F_11 ( V_25 ) )
F_54 ( V_12 -> V_181 , V_76 -> V_92 ,
V_76 -> V_165 , V_76 -> V_164 ) ;
if ( F_11 ( V_30 ) )
F_30 ( V_76 , V_85 , V_17 ) ;
if ( F_11 ( V_33 ) )
F_49 ( V_76 -> V_169 ) ;
if ( F_11 ( V_36 ) )
printf ( L_40 V_176 , V_76 -> V_182 ) ;
if ( F_11 ( V_27 ) ) {
struct V_135 * V_136 = NULL ;
if ( V_70 . V_67 && V_76 -> V_137 &&
F_40 ( V_116 -> V_85 , & V_135 , V_12 ,
V_76 , NULL , NULL , V_138 ) == 0 )
V_136 = & V_135 ;
putchar ( V_136 ? '\n' : ' ' ) ;
F_41 ( V_76 , V_116 , 0 , V_3 [ V_17 -> type ] . V_59 , V_136 , stdout ) ;
}
if ( F_11 ( V_56 ) )
F_18 ( V_76 , V_17 ) ;
if ( F_11 ( V_183 ) )
F_25 ( V_76 ) ;
else if ( F_11 ( V_184 ) )
F_26 ( V_76 , V_85 ) ;
if ( F_55 ( V_12 ) && F_11 ( V_185 ) )
F_45 ( V_76 ) ;
F_38 ( V_76 , V_17 ) ;
printf ( L_51 ) ;
}
static void F_56 ( struct V_11 * V_186 , T_1 V_187 )
{
int V_188 = F_57 ( V_186 -> V_189 ) ;
int V_190 = F_58 ( V_186 ) ;
int V_92 , V_85 ;
static int V_191 ;
if ( V_186 -> V_192 )
V_188 = 1 ;
if ( ! V_191 ) {
printf ( L_69 ,
L_21 , L_70 , L_71 , L_72 , L_73 , L_20 , L_74 ) ;
V_191 = 1 ;
}
for ( V_85 = 0 ; V_85 < V_188 ; V_85 ++ ) {
for ( V_92 = 0 ; V_92 < V_190 ; V_92 ++ ) {
struct V_193 * V_194 ;
V_194 = F_59 ( V_186 -> V_194 , V_92 , V_85 ) ;
printf ( L_75 V_176 L_76 V_176 L_76 V_176 L_76 V_176 L_77 ,
V_186 -> V_195 -> V_113 [ V_92 ] ,
F_60 ( V_186 -> V_189 , V_85 ) ,
V_194 -> V_83 ,
V_194 -> V_196 ,
V_194 -> V_197 ,
V_187 ,
F_5 ( V_186 ) ) ;
}
}
}
static void F_61 ( struct V_11 * V_186 , T_1 V_187 )
{
if ( V_198 && V_198 -> F_61 )
V_198 -> F_61 ( & V_199 , V_186 , V_187 ) ;
else
F_56 ( V_186 , V_187 ) ;
}
static void F_62 ( T_1 V_187 )
{
if ( V_198 && V_198 -> F_62 )
V_198 -> F_62 ( V_187 ) ;
}
static void F_63 ( void )
{
F_64 () ;
F_65 () ;
}
static int F_66 ( void )
{
return V_198 ? V_198 -> V_200 () : 0 ;
}
static int F_67 ( void )
{
F_7 ( L_78 ) ;
return V_198 ? V_198 -> V_201 () : 0 ;
}
static int F_68 ( struct V_202 * V_203 ,
union V_204 * V_205 ,
struct V_75 * V_76 ,
struct V_11 * V_12 ,
struct V_206 * V_206 )
{
struct V_174 * V_207 = F_69 ( V_203 , struct V_174 , V_203 ) ;
struct V_108 V_116 ;
if ( F_70 ( & V_207 -> V_208 , V_76 -> time ) )
return 0 ;
if ( V_209 ) {
if ( V_76 -> time < V_210 ) {
F_6 ( L_79 V_176
L_80 V_176 L_51 , V_210 ,
V_76 -> time ) ;
V_211 ++ ;
}
V_210 = V_76 -> time ;
return 0 ;
}
if ( F_71 ( V_206 , & V_116 , V_76 ) < 0 ) {
F_6 ( L_81 ,
V_205 -> V_22 . type ) ;
return - 1 ;
}
if ( V_116 . V_212 )
goto V_213;
if ( V_214 && ! F_72 ( V_76 -> V_92 , V_215 ) )
goto V_213;
if ( V_198 )
V_198 -> F_52 ( V_205 , V_76 , V_12 , & V_116 ) ;
else
F_52 ( V_207 , V_76 , V_12 , & V_116 ) ;
V_213:
F_73 ( & V_116 ) ;
return 0 ;
}
static int F_74 ( struct V_202 * V_203 , union V_204 * V_205 ,
struct V_166 * * V_216 )
{
struct V_174 * V_207 = F_69 ( V_203 , struct V_174 , V_203 ) ;
struct V_166 * V_167 ;
struct V_11 * V_12 , * V_143 ;
int V_217 ;
V_217 = F_75 ( V_203 , V_205 , V_216 ) ;
if ( V_217 )
return V_217 ;
V_167 = * V_216 ;
V_12 = F_76 ( * V_216 ) ;
if ( V_12 -> V_17 . type >= V_2 )
return 0 ;
F_17 (evlist, pos) {
if ( V_143 -> V_17 . type == V_12 -> V_17 . type && V_143 != V_12 )
return 0 ;
}
F_13 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_17 . V_13 )
V_217 = F_9 ( V_12 , V_207 -> V_21 ) ;
return V_217 ;
}
static int F_77 ( struct V_202 * V_203 ,
union V_204 * V_205 ,
struct V_75 * V_76 ,
struct V_206 * V_206 )
{
struct V_85 * V_85 ;
struct V_174 * V_175 = F_69 ( V_203 , struct V_174 , V_203 ) ;
struct V_20 * V_21 = V_175 -> V_21 ;
struct V_11 * V_12 = F_78 ( V_21 -> V_167 , V_76 -> V_218 ) ;
int V_219 = - 1 ;
V_85 = F_79 ( V_206 , V_205 -> V_220 . V_90 , V_205 -> V_220 . V_91 ) ;
if ( V_85 == NULL ) {
F_7 ( L_82 ) ;
return - 1 ;
}
if ( F_80 ( V_203 , V_205 , V_76 , V_206 ) < 0 )
goto V_74;
if ( ! V_12 -> V_17 . V_221 ) {
V_76 -> V_92 = 0 ;
V_76 -> time = 0 ;
V_76 -> V_91 = V_205 -> V_220 . V_91 ;
V_76 -> V_90 = V_205 -> V_220 . V_90 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_81 ( V_205 , stdout ) ;
V_219 = 0 ;
V_74:
F_82 ( V_85 ) ;
return V_219 ;
}
static int F_83 ( struct V_202 * V_203 ,
union V_204 * V_205 ,
struct V_75 * V_76 ,
struct V_206 * V_206 )
{
struct V_85 * V_85 ;
struct V_174 * V_175 = F_69 ( V_203 , struct V_174 , V_203 ) ;
struct V_20 * V_21 = V_175 -> V_21 ;
struct V_11 * V_12 = F_78 ( V_21 -> V_167 , V_76 -> V_218 ) ;
if ( F_84 ( V_203 , V_205 , V_76 , V_206 ) < 0 )
return - 1 ;
V_85 = F_79 ( V_206 , V_205 -> V_222 . V_90 , V_205 -> V_222 . V_91 ) ;
if ( V_85 == NULL ) {
F_7 ( L_83 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_221 ) {
V_76 -> V_92 = 0 ;
V_76 -> time = V_205 -> V_222 . time ;
V_76 -> V_91 = V_205 -> V_222 . V_91 ;
V_76 -> V_90 = V_205 -> V_222 . V_90 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_81 ( V_205 , stdout ) ;
F_82 ( V_85 ) ;
return 0 ;
}
static int F_85 ( struct V_202 * V_203 ,
union V_204 * V_205 ,
struct V_75 * V_76 ,
struct V_206 * V_206 )
{
int V_217 = 0 ;
struct V_85 * V_85 ;
struct V_174 * V_175 = F_69 ( V_203 , struct V_174 , V_203 ) ;
struct V_20 * V_21 = V_175 -> V_21 ;
struct V_11 * V_12 = F_78 ( V_21 -> V_167 , V_76 -> V_218 ) ;
V_85 = F_79 ( V_206 , V_205 -> V_222 . V_90 , V_205 -> V_222 . V_91 ) ;
if ( V_85 == NULL ) {
F_7 ( L_84 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_221 ) {
V_76 -> V_92 = 0 ;
V_76 -> time = 0 ;
V_76 -> V_91 = V_205 -> V_222 . V_91 ;
V_76 -> V_90 = V_205 -> V_222 . V_90 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_81 ( V_205 , stdout ) ;
if ( F_86 ( V_203 , V_205 , V_76 , V_206 ) < 0 )
V_217 = - 1 ;
F_82 ( V_85 ) ;
return V_217 ;
}
static int F_87 ( struct V_202 * V_203 ,
union V_204 * V_205 ,
struct V_75 * V_76 ,
struct V_206 * V_206 )
{
struct V_85 * V_85 ;
struct V_174 * V_175 = F_69 ( V_203 , struct V_174 , V_203 ) ;
struct V_20 * V_21 = V_175 -> V_21 ;
struct V_11 * V_12 = F_78 ( V_21 -> V_167 , V_76 -> V_218 ) ;
if ( F_88 ( V_203 , V_205 , V_76 , V_206 ) < 0 )
return - 1 ;
V_85 = F_79 ( V_206 , V_205 -> V_223 . V_90 , V_205 -> V_223 . V_91 ) ;
if ( V_85 == NULL ) {
F_7 ( L_85 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_221 ) {
V_76 -> V_92 = 0 ;
V_76 -> time = 0 ;
V_76 -> V_91 = V_205 -> V_223 . V_91 ;
V_76 -> V_90 = V_205 -> V_223 . V_90 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_81 ( V_205 , stdout ) ;
F_82 ( V_85 ) ;
return 0 ;
}
static int F_89 ( struct V_202 * V_203 ,
union V_204 * V_205 ,
struct V_75 * V_76 ,
struct V_206 * V_206 )
{
struct V_85 * V_85 ;
struct V_174 * V_175 = F_69 ( V_203 , struct V_174 , V_203 ) ;
struct V_20 * V_21 = V_175 -> V_21 ;
struct V_11 * V_12 = F_78 ( V_21 -> V_167 , V_76 -> V_218 ) ;
if ( F_90 ( V_203 , V_205 , V_76 , V_206 ) < 0 )
return - 1 ;
V_85 = F_79 ( V_206 , V_205 -> V_224 . V_90 , V_205 -> V_224 . V_91 ) ;
if ( V_85 == NULL ) {
F_7 ( L_86 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_221 ) {
V_76 -> V_92 = 0 ;
V_76 -> time = 0 ;
V_76 -> V_91 = V_205 -> V_224 . V_91 ;
V_76 -> V_90 = V_205 -> V_224 . V_90 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_81 ( V_205 , stdout ) ;
F_82 ( V_85 ) ;
return 0 ;
}
static int F_91 ( struct V_202 * V_203 ,
union V_204 * V_205 ,
struct V_75 * V_76 ,
struct V_206 * V_206 )
{
struct V_85 * V_85 ;
struct V_174 * V_175 = F_69 ( V_203 , struct V_174 , V_203 ) ;
struct V_20 * V_21 = V_175 -> V_21 ;
struct V_11 * V_12 = F_78 ( V_21 -> V_167 , V_76 -> V_218 ) ;
if ( F_92 ( V_203 , V_205 , V_76 , V_206 ) < 0 )
return - 1 ;
V_85 = F_79 ( V_206 , V_76 -> V_90 ,
V_76 -> V_91 ) ;
if ( V_85 == NULL ) {
F_7 ( L_87 ) ;
return - 1 ;
}
F_21 ( V_76 , V_85 , V_12 ) ;
F_81 ( V_205 , stdout ) ;
F_82 ( V_85 ) ;
return 0 ;
}
static void F_93 ( int T_5 V_225 )
{
V_226 = 1 ;
}
static int F_94 ( struct V_174 * V_175 )
{
int V_219 ;
signal ( V_227 , F_93 ) ;
if ( V_175 -> V_228 ) {
V_175 -> V_203 . V_220 = F_77 ;
V_175 -> V_203 . V_222 = F_83 ;
V_175 -> V_203 . exit = F_85 ;
}
if ( V_175 -> V_229 ) {
V_175 -> V_203 . V_223 = F_87 ;
V_175 -> V_203 . V_224 = F_89 ;
}
if ( V_175 -> V_230 )
V_175 -> V_203 . V_231 = F_91 ;
V_219 = F_95 ( V_175 -> V_21 ) ;
if ( V_209 )
F_6 ( L_88 V_176 L_51 , V_211 ) ;
return V_219 ;
}
static struct V_232 * F_96 ( const char * V_233 ,
struct V_198 * V_234 )
{
struct V_232 * V_235 = malloc ( sizeof( * V_235 ) + strlen ( V_233 ) + 1 ) ;
if ( V_235 != NULL ) {
strcpy ( V_235 -> V_233 , V_233 ) ;
V_235 -> V_234 = V_234 ;
}
return V_235 ;
}
static void F_97 ( struct V_232 * V_235 )
{
F_98 ( & V_235 -> V_236 , & V_237 ) ;
}
static struct V_232 * F_99 ( const char * V_233 )
{
struct V_232 * V_235 ;
F_100 (s, &script_specs, node)
if ( strcasecmp ( V_235 -> V_233 , V_233 ) == 0 )
return V_235 ;
return NULL ;
}
int F_101 ( const char * V_233 , struct V_198 * V_234 )
{
struct V_232 * V_235 ;
V_235 = F_99 ( V_233 ) ;
if ( V_235 )
return - 1 ;
V_235 = F_96 ( V_233 , V_234 ) ;
if ( ! V_235 )
return - 1 ;
else
F_97 ( V_235 ) ;
return 0 ;
}
static struct V_198 * F_102 ( const char * V_233 )
{
struct V_232 * V_235 = F_99 ( V_233 ) ;
if ( ! V_235 )
return NULL ;
return V_235 -> V_234 ;
}
static void F_103 ( void )
{
struct V_232 * V_235 ;
fprintf ( V_238 , L_51 ) ;
fprintf ( V_238 , L_89
L_90 ) ;
F_100 (s, &script_specs, node)
fprintf ( V_238 , L_91 , V_235 -> V_233 , V_235 -> V_234 -> V_119 ) ;
fprintf ( V_238 , L_51 ) ;
}
static int F_104 ( const struct V_239 * T_6 V_225 ,
const char * V_10 , int T_7 V_225 )
{
char V_233 [ V_240 ] ;
const char * V_175 , * V_241 ;
int V_121 ;
if ( strcmp ( V_10 , L_92 ) == 0 ) {
F_103 () ;
exit ( 0 ) ;
}
V_175 = strchr ( V_10 , ':' ) ;
if ( V_175 ) {
V_121 = V_175 - V_10 ;
if ( V_121 >= V_240 ) {
fprintf ( V_238 , L_93 ) ;
return - 1 ;
}
strncpy ( V_233 , V_10 , V_121 ) ;
V_233 [ V_121 ] = '\0' ;
V_198 = F_102 ( V_233 ) ;
if ( ! V_198 ) {
fprintf ( V_238 , L_93 ) ;
return - 1 ;
}
V_175 ++ ;
} else {
V_175 = V_10 ;
V_241 = strrchr ( V_175 , '.' ) ;
if ( ! V_241 ) {
fprintf ( V_238 , L_94 ) ;
return - 1 ;
}
V_198 = F_102 ( ++ V_241 ) ;
if ( ! V_198 ) {
fprintf ( V_238 , L_94 ) ;
return - 1 ;
}
}
V_242 = F_105 ( V_175 ) ;
return 0 ;
}
static int F_106 ( const struct V_239 * T_6 V_225 ,
const char * V_243 , int T_7 V_225 )
{
char * V_244 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_245 = 0 ;
char * V_10 = F_105 ( V_243 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_246 ;
V_244 = strchr ( V_10 , ':' ) ;
if ( V_244 ) {
* V_244 = '\0' ;
V_244 ++ ;
if ( ! strcmp ( V_10 , L_95 ) )
type = V_247 ;
else if ( ! strcmp ( V_10 , L_96 ) )
type = V_248 ;
else if ( ! strcmp ( V_10 , L_97 ) )
type = V_71 ;
else if ( ! strcmp ( V_10 , L_98 ) )
type = V_249 ;
else if ( ! strcmp ( V_10 , L_99 ) )
type = V_250 ;
else {
fprintf ( V_238 , L_100 ) ;
V_245 = - V_26 ;
goto V_74;
}
if ( V_3 [ type ] . V_4 )
F_107 ( L_101 ,
F_16 ( type ) ) ;
V_3 [ type ] . V_19 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_65 = false ;
} else {
V_244 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_238 ,
L_102 ) ;
V_245 = - V_26 ;
goto V_74;
}
if ( F_1 () )
F_107 ( L_103 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_19 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_65 = true ;
}
}
for ( V_244 = strtok ( V_244 , L_104 ) ; V_244 ; V_244 = strtok ( NULL , L_104 ) ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_244 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 && strcmp ( V_244 , L_105 ) == 0 ) {
V_180 = true ;
continue;
}
if ( V_7 == V_8 ) {
fprintf ( V_238 , L_106 ) ;
V_245 = - V_26 ;
goto V_74;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_251 & V_9 [ V_7 ] . V_6 ) {
F_107 ( L_107 ,
V_9 [ V_7 ] . V_10 , F_16 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_251 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_238 , L_108 ,
V_9 [ V_7 ] . V_10 , F_16 ( type ) ) ;
V_245 = - V_26 ;
goto V_74;
}
V_3 [ type ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_19 == 0 ) {
F_7 ( L_109
L_110 , F_16 ( type ) ) ;
}
}
V_74:
free ( V_10 ) ;
return V_245 ;
}
static int F_108 ( const char * V_252 , const struct V_253 * V_254 )
{
char V_255 [ V_240 ] ;
struct V_256 V_257 ;
sprintf ( V_255 , L_111 , V_252 , V_254 -> V_258 ) ;
if ( V_256 ( V_255 , & V_257 ) )
return 0 ;
return F_109 ( V_257 . V_259 ) ;
}
static struct V_260 * F_110 ( const char * V_119 )
{
struct V_260 * V_235 = F_111 ( sizeof( * V_235 ) ) ;
if ( V_235 != NULL && V_119 )
V_235 -> V_119 = F_105 ( V_119 ) ;
return V_235 ;
}
static void F_112 ( struct V_260 * V_235 )
{
F_113 ( & V_235 -> V_119 ) ;
F_113 ( & V_235 -> V_261 ) ;
F_113 ( & V_235 -> args ) ;
free ( V_235 ) ;
}
static void F_114 ( struct V_260 * V_235 )
{
F_98 ( & V_235 -> V_236 , & V_262 ) ;
}
static struct V_260 * F_115 ( const char * V_119 )
{
struct V_260 * V_235 ;
F_100 (s, &script_descs, node)
if ( strcasecmp ( V_235 -> V_119 , V_119 ) == 0 )
return V_235 ;
return NULL ;
}
static struct V_260 * F_116 ( const char * V_119 )
{
struct V_260 * V_235 = F_115 ( V_119 ) ;
if ( V_235 )
return V_235 ;
V_235 = F_110 ( V_119 ) ;
if ( ! V_235 )
goto V_263;
F_114 ( V_235 ) ;
return V_235 ;
V_263:
F_112 ( V_235 ) ;
return NULL ;
}
static const char * F_117 ( const char * V_10 , const char * V_264 )
{
T_3 V_265 = strlen ( V_264 ) ;
const char * V_266 = V_10 ;
if ( strlen ( V_10 ) > V_265 ) {
V_266 = V_10 + strlen ( V_10 ) - V_265 ;
if ( ! strncmp ( V_266 , V_264 , V_265 ) )
return V_266 ;
}
return NULL ;
}
static int F_118 ( struct V_260 * V_267 , const char * V_268 )
{
char line [ V_269 ] , * V_266 ;
T_8 * V_270 ;
V_270 = fopen ( V_268 , L_112 ) ;
if ( ! V_270 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_270 ) ) {
V_266 = F_119 ( line ) ;
if ( strlen ( V_266 ) == 0 )
continue;
if ( * V_266 != '#' )
continue;
V_266 ++ ;
if ( strlen ( V_266 ) && * V_266 == '!' )
continue;
V_266 = F_119 ( V_266 ) ;
if ( strlen ( V_266 ) && V_266 [ strlen ( V_266 ) - 1 ] == '\n' )
V_266 [ strlen ( V_266 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_266 , L_113 , strlen ( L_113 ) ) ) {
V_266 += strlen ( L_113 ) ;
V_267 -> V_261 = F_105 ( F_119 ( V_266 ) ) ;
continue;
}
if ( ! strncmp ( V_266 , L_114 , strlen ( L_114 ) ) ) {
V_266 += strlen ( L_114 ) ;
V_267 -> args = F_105 ( F_119 ( V_266 ) ) ;
continue;
}
}
fclose ( V_270 ) ;
return 0 ;
}
static char * F_120 ( struct V_253 * V_271 , const char * V_264 )
{
char * V_272 , * V_10 ;
V_272 = F_105 ( V_271 -> V_258 ) ;
if ( ! V_272 )
return NULL ;
V_10 = ( char * ) F_117 ( V_272 , V_264 ) ;
if ( ! V_10 ) {
free ( V_272 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_272 ;
}
static int F_121 ( const struct V_239 * T_6 V_225 ,
const char * V_235 V_225 ,
int T_7 V_225 )
{
struct V_253 * V_271 , * V_273 ;
char V_274 [ V_275 ] ;
T_9 * V_276 , * V_277 ;
char V_278 [ V_275 ] ;
char V_279 [ V_275 ] ;
struct V_260 * V_267 ;
char V_280 [ V_269 ] ;
char * V_272 ;
snprintf ( V_274 , V_275 , L_115 , F_122 () ) ;
V_276 = F_123 ( V_274 ) ;
if ( ! V_276 ) {
fprintf ( stdout ,
L_116
L_117 ,
V_274 ) ;
exit ( - 1 ) ;
}
F_124 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_279 , V_275 , L_118 , V_274 ,
V_273 -> V_258 ) ;
V_277 = F_123 ( V_279 ) ;
if ( ! V_277 )
continue;
F_125 (lang_path, lang_dir, script_dirent) {
V_272 = F_120 ( V_271 , V_281 ) ;
if ( V_272 ) {
V_267 = F_116 ( V_272 ) ;
snprintf ( V_278 , V_275 , L_111 ,
V_279 , V_271 -> V_258 ) ;
F_118 ( V_267 , V_278 ) ;
free ( V_272 ) ;
}
}
}
fprintf ( stdout , L_119 ) ;
F_100 (desc, &script_descs, node) {
sprintf ( V_280 , L_120 , V_267 -> V_119 ,
V_267 -> args ? V_267 -> args : L_1 ) ;
fprintf ( stdout , L_121 , V_280 ,
V_267 -> V_261 ? V_267 -> V_261 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_126 ( char * V_282 , char * V_283 ,
struct V_20 * V_21 )
{
char V_268 [ V_275 ] , V_18 [ 128 ] ;
char line [ V_269 ] , * V_266 ;
struct V_11 * V_143 ;
int V_284 , V_121 ;
T_8 * V_270 ;
sprintf ( V_268 , L_122 , V_282 , V_283 ) ;
V_270 = fopen ( V_268 , L_112 ) ;
if ( ! V_270 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_270 ) ) {
V_266 = F_119 ( line ) ;
if ( * V_266 == '#' )
continue;
while ( strlen ( V_266 ) ) {
V_266 = strstr ( V_266 , L_123 ) ;
if ( ! V_266 )
break;
V_266 += 2 ;
V_266 = F_119 ( V_266 ) ;
V_121 = strcspn ( V_266 , L_124 ) ;
if ( ! V_121 )
break;
snprintf ( V_18 , V_121 + 1 , L_125 , V_266 ) ;
V_284 = 0 ;
F_17 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_143 ) , V_18 ) ) {
V_284 = 1 ;
break;
}
}
if ( ! V_284 ) {
fclose ( V_270 ) ;
return - 1 ;
}
}
}
fclose ( V_270 ) ;
return 0 ;
}
int F_127 ( char * * V_285 , char * * V_286 )
{
struct V_253 * V_271 , * V_273 ;
char V_274 [ V_275 ] , V_279 [ V_275 ] ;
T_9 * V_276 , * V_277 ;
struct V_20 * V_21 ;
struct V_287 V_288 = {
. V_255 = V_289 ,
. V_290 = V_291 ,
} ;
char * V_292 ;
int V_7 = 0 ;
V_21 = F_128 ( & V_288 , false , NULL ) ;
if ( ! V_21 )
return - 1 ;
snprintf ( V_274 , V_275 , L_115 , F_122 () ) ;
V_276 = F_123 ( V_274 ) ;
if ( ! V_276 ) {
F_129 ( V_21 ) ;
return - 1 ;
}
F_124 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_279 , V_275 , L_111 , V_274 ,
V_273 -> V_258 ) ;
#ifdef F_130
if ( strstr ( V_279 , L_126 ) )
continue;
#endif
#ifdef F_131
if ( strstr ( V_279 , L_127 ) )
continue;
#endif
V_277 = F_123 ( V_279 ) ;
if ( ! V_277 )
continue;
F_125 (lang_path, lang_dir, script_dirent) {
if ( strstr ( V_271 -> V_258 , L_128 ) )
continue;
sprintf ( V_286 [ V_7 ] , L_111 , V_279 ,
V_271 -> V_258 ) ;
V_292 = strchr ( V_271 -> V_258 , '.' ) ;
snprintf ( V_285 [ V_7 ] ,
( V_292 - V_271 -> V_258 ) + 1 ,
L_125 , V_271 -> V_258 ) ;
if ( F_126 ( V_279 ,
V_285 [ V_7 ] , V_21 ) )
continue;
V_7 ++ ;
}
F_132 ( V_277 ) ;
}
F_132 ( V_276 ) ;
F_129 ( V_21 ) ;
return V_7 ;
}
static char * F_133 ( const char * V_272 , const char * V_264 )
{
struct V_253 * V_271 , * V_273 ;
char V_274 [ V_275 ] ;
char V_278 [ V_275 ] ;
T_9 * V_276 , * V_277 ;
char V_279 [ V_275 ] ;
char * V_293 ;
snprintf ( V_274 , V_275 , L_115 , F_122 () ) ;
V_276 = F_123 ( V_274 ) ;
if ( ! V_276 )
return NULL ;
F_124 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_279 , V_275 , L_118 , V_274 ,
V_273 -> V_258 ) ;
V_277 = F_123 ( V_279 ) ;
if ( ! V_277 )
continue;
F_125 (lang_path, lang_dir, script_dirent) {
V_293 = F_120 ( V_271 , V_264 ) ;
if ( V_293 && ! strcmp ( V_272 , V_293 ) ) {
free ( V_293 ) ;
F_132 ( V_277 ) ;
F_132 ( V_276 ) ;
snprintf ( V_278 , V_275 , L_111 ,
V_279 , V_271 -> V_258 ) ;
return F_105 ( V_278 ) ;
}
free ( V_293 ) ;
}
F_132 ( V_277 ) ;
}
F_132 ( V_276 ) ;
return NULL ;
}
static bool F_134 ( const char * V_278 )
{
return F_117 ( V_278 , L_129 ) == NULL ? false : true ;
}
static int F_135 ( char * V_278 )
{
struct V_260 * V_267 ;
int V_294 = 0 ;
char * V_266 ;
V_267 = F_110 ( NULL ) ;
if ( F_118 ( V_267 , V_278 ) )
goto V_74;
if ( ! V_267 -> args )
goto V_74;
for ( V_266 = V_267 -> args ; * V_266 ; V_266 ++ )
if ( * V_266 == '<' )
V_294 ++ ;
V_74:
F_112 ( V_267 ) ;
return V_294 ;
}
static int F_136 ( int V_295 , const char * * V_296 )
{
char * * V_297 = malloc ( sizeof( const char * ) * V_295 ) ;
if ( ! V_297 ) {
F_6 ( L_130 ) ;
return - 1 ;
}
memcpy ( V_297 , V_296 , sizeof( const char * ) * V_295 ) ;
V_295 = F_137 ( V_295 , ( const char * * ) V_297 , V_298 ,
NULL , V_299 ) ;
free ( V_297 ) ;
V_192 = ( V_295 == 0 ) ;
return 0 ;
}
static void F_138 ( struct V_174 * V_175 )
{
struct V_20 * V_21 = V_175 -> V_21 ;
T_1 V_13 = F_139 ( V_21 -> V_167 ) ;
if ( V_70 . V_67 || V_70 . V_300 ) {
if ( ( V_13 & V_301 ) &&
( V_13 & V_302 ) )
V_303 . V_304 = V_305 ;
else if ( V_13 & V_306 )
V_303 . V_304 = V_307 ;
else
V_303 . V_304 = V_308 ;
}
}
static int F_140 ( struct V_202 * V_203 V_225 ,
union V_204 * V_205 ,
struct V_20 * V_21 )
{
struct V_309 * V_310 = & V_205 -> V_311 ;
struct V_11 * V_186 ;
F_17 (session->evlist, counter) {
F_141 ( & V_199 , V_186 ) ;
F_61 ( V_186 , V_310 -> time ) ;
}
F_62 ( V_310 -> time ) ;
return 0 ;
}
static int F_142 ( struct V_202 * V_203 V_225 ,
union V_204 * V_205 ,
struct V_20 * V_21 V_225 )
{
F_143 ( & V_199 , & V_205 -> V_199 ) ;
return 0 ;
}
static int F_144 ( struct V_174 * V_175 )
{
struct V_166 * V_167 = V_175 -> V_21 -> V_167 ;
if ( ! V_175 -> V_195 || ! V_175 -> V_189 )
return 0 ;
if ( F_145 ( V_175 -> V_312 , L_131 ) )
return - V_26 ;
F_146 ( V_167 , V_175 -> V_195 , V_175 -> V_189 ) ;
if ( F_147 ( V_167 , true ) )
return - V_246 ;
V_175 -> V_312 = true ;
return 0 ;
}
static
int F_148 ( struct V_202 * V_203 ,
union V_204 * V_205 ,
struct V_20 * V_21 V_225 )
{
struct V_174 * V_175 = F_69 ( V_203 , struct V_174 , V_203 ) ;
if ( V_175 -> V_189 ) {
F_107 ( L_132 ) ;
return 0 ;
}
V_175 -> V_189 = F_149 ( & V_205 -> V_313 ) ;
if ( ! V_175 -> V_189 )
return - V_246 ;
return F_144 ( V_175 ) ;
}
static
int F_150 ( struct V_202 * V_203 V_225 ,
union V_204 * V_205 ,
struct V_20 * V_21 V_225 )
{
struct V_174 * V_175 = F_69 ( V_203 , struct V_174 , V_203 ) ;
if ( V_175 -> V_195 ) {
F_107 ( L_133 ) ;
return 0 ;
}
V_175 -> V_195 = F_151 ( & V_205 -> V_314 . V_315 ) ;
if ( ! V_175 -> V_195 )
return - V_246 ;
return F_144 ( V_175 ) ;
}
int F_152 ( int V_295 , const char * * V_296 , const char * T_10 V_225 )
{
bool V_316 = false ;
bool V_22 = false ;
bool V_317 = false ;
bool V_318 = false ;
char * V_319 = NULL ;
char * V_320 = NULL ;
struct V_20 * V_21 ;
struct V_321 V_321 = { . V_322 = false , } ;
char * V_278 = NULL ;
const char * * V_297 ;
int V_7 , V_1 , V_217 = 0 ;
struct V_174 V_175 = {
. V_203 = {
. V_76 = F_68 ,
. V_223 = F_88 ,
. V_224 = F_90 ,
. V_220 = F_80 ,
. exit = F_86 ,
. V_222 = F_84 ,
. V_17 = F_74 ,
. V_323 = V_324 ,
. V_325 = V_326 ,
. V_327 = V_328 ,
. V_329 = V_330 ,
. V_331 = V_332 ,
. V_333 = V_334 ,
. V_335 = V_336 ,
. V_256 = V_337 ,
. V_311 = F_140 ,
. V_199 = F_142 ,
. V_313 = F_148 ,
. V_314 = F_150 ,
. V_338 = true ,
. V_339 = true ,
} ,
} ;
struct V_287 V_288 = {
. V_290 = V_291 ,
} ;
const struct V_239 V_340 [] = {
F_153 ( 'D' , L_134 , & V_341 ,
L_135 ) ,
F_154 ( 'v' , L_136 , & V_342 ,
L_137 ) ,
F_153 ( 'L' , L_138 , & V_89 ,
L_139 ) ,
F_155 ( 'l' , L_140 , NULL , NULL , L_141 ,
F_121 ) ,
F_156 ( 's' , L_142 , NULL , L_143 ,
L_144 ,
F_104 ) ,
F_157 ( 'g' , L_145 , & V_343 , L_92 ,
L_146 ) ,
F_157 ( 'i' , L_147 , & V_289 , L_148 , L_149 ) ,
F_153 ( 'd' , L_150 , & V_209 ,
L_151 ) ,
F_153 ( 0 , L_152 , & V_22 , L_153 ) ,
F_153 ( 0 , L_154 , & V_317 , L_155 ) ,
F_157 ( 'k' , L_156 , & V_70 . V_344 ,
L_148 , L_157 ) ,
F_157 ( 0 , L_158 , & V_70 . V_345 ,
L_148 , L_159 ) ,
F_153 ( 'G' , L_160 , & V_66 ,
L_161 ) ,
F_156 ( 0 , L_162 , NULL , L_163 ,
L_164 ,
V_346 ) ,
F_156 ( 'F' , L_165 , NULL , L_166 ,
L_167
L_168
L_169
L_170
L_171 , F_106 ) ,
F_153 ( 'a' , L_172 , & V_192 ,
L_173 ) ,
F_157 ( 'S' , L_174 , & V_70 . V_347 , L_175 ,
L_176 ) ,
F_157 ( 0 , L_177 , & V_70 . V_348 , L_175 ,
L_178 ) ,
F_157 ( 'C' , L_179 , & V_214 , L_179 , L_180 ) ,
F_157 ( 'c' , L_181 , & V_70 . V_349 , L_182 ,
L_183 ) ,
F_157 ( 0 , L_184 , & V_70 . V_350 , L_185 ,
L_186 ) ,
F_157 ( 0 , L_187 , & V_70 . V_351 , L_188 ,
L_189 ) ,
F_158 ( 0 , L_190 , & V_138 ,
L_191
L_192
L_193 F_159 ( V_352 ) ) ,
F_153 ( 'I' , L_194 , & V_316 ,
L_195 ) ,
F_153 ( '\0' , L_196 , & V_70 . V_353 ,
L_197 ) ,
F_153 ( '\0' , L_198 , & V_175 . V_228 ,
L_199 ) ,
F_153 ( '\0' , L_200 , & V_175 . V_229 ,
L_201 ) ,
F_153 ( '\0' , L_202 , & V_175 . V_230 ,
L_203 ) ,
F_153 ( 'f' , L_204 , & V_288 . V_354 , L_205 ) ,
F_153 ( 0 , L_206 , & V_94 ,
L_207 ) ,
F_160 ( 0 , L_208 , & V_321 , NULL , L_209 ,
L_210 ,
V_355 ) ,
F_153 ( 0 , L_211 , & V_356 ,
L_212 ) ,
F_153 ( 0 , L_213 , & V_70 . V_357 ,
L_214 ) ,
F_153 ( 0 , L_215 , & V_70 . V_358 ,
L_216 ) ,
F_157 ( 0 , L_217 , & V_175 . V_359 , L_166 ,
L_218 ) ,
F_161 ()
} ;
const char * const V_360 [] = { L_219 , L_220 , NULL } ;
const char * V_361 [] = {
L_221 ,
L_222 ,
L_223 ,
L_224 ,
L_225 ,
NULL
} ;
F_63 () ;
V_295 = F_162 ( V_295 , V_296 , V_340 , V_360 , V_361 ,
V_299 ) ;
V_288 . V_255 = V_289 ;
if ( V_295 > 1 && ! strncmp ( V_296 [ 0 ] , L_226 , strlen ( L_226 ) ) ) {
V_319 = F_133 ( V_296 [ 1 ] , V_362 ) ;
if ( ! V_319 )
return F_163 ( V_295 , V_296 , NULL ) ;
}
if ( V_295 > 1 && ! strncmp ( V_296 [ 0 ] , L_227 , strlen ( L_227 ) ) ) {
V_320 = F_133 ( V_296 [ 1 ] , V_281 ) ;
if ( ! V_320 ) {
fprintf ( V_238 ,
L_228
L_229 ) ;
return - 1 ;
}
}
if ( V_321 . V_137 &&
V_321 . V_363 > V_138 )
V_138 = V_321 . V_363 ;
F_164 ( F_122 () ) ;
if ( V_295 && ! V_242 && ! V_319 && ! V_320 ) {
int V_364 [ 2 ] ;
int V_365 ;
T_11 V_90 ;
V_319 = F_133 ( V_296 [ 0 ] , V_362 ) ;
V_320 = F_133 ( V_296 [ 0 ] , V_281 ) ;
if ( ! V_319 && ! V_320 ) {
F_165 ( V_361 , V_340 ,
L_230
L_231 , V_296 [ 0 ] ) ;
}
if ( F_134 ( V_296 [ 0 ] ) ) {
V_365 = V_295 - 1 ;
} else {
int V_366 ;
V_365 = F_135 ( V_320 ) ;
V_366 = ( V_295 - 1 ) - V_365 ;
if ( V_366 < 0 ) {
F_165 ( V_361 , V_340 ,
L_232
L_233
L_234 , V_296 [ 0 ] ) ;
}
}
if ( F_166 ( V_364 ) < 0 ) {
perror ( L_235 ) ;
return - 1 ;
}
V_90 = V_222 () ;
if ( V_90 < 0 ) {
perror ( L_236 ) ;
return - 1 ;
}
if ( ! V_90 ) {
V_1 = 0 ;
F_167 ( V_364 [ 1 ] , 1 ) ;
F_168 ( V_364 [ 0 ] ) ;
if ( F_134 ( V_296 [ 0 ] ) ) {
V_192 = true ;
} else if ( ! V_192 ) {
if ( F_136 ( V_295 - V_365 , & V_296 [ V_365 ] ) != 0 ) {
V_217 = - 1 ;
goto V_74;
}
}
V_297 = malloc ( ( V_295 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_297 ) {
F_6 ( L_130 ) ;
V_217 = - V_246 ;
goto V_74;
}
V_297 [ V_1 ++ ] = L_237 ;
V_297 [ V_1 ++ ] = V_319 ;
if ( V_192 )
V_297 [ V_1 ++ ] = L_238 ;
V_297 [ V_1 ++ ] = L_239 ;
V_297 [ V_1 ++ ] = L_240 ;
V_297 [ V_1 ++ ] = L_241 ;
for ( V_7 = V_365 + 1 ; V_7 < V_295 ; V_7 ++ )
V_297 [ V_1 ++ ] = V_296 [ V_7 ] ;
V_297 [ V_1 ++ ] = NULL ;
F_169 ( L_237 , ( char * * ) V_297 ) ;
free ( V_297 ) ;
exit ( - 1 ) ;
}
F_167 ( V_364 [ 0 ] , 0 ) ;
F_168 ( V_364 [ 1 ] ) ;
V_297 = malloc ( ( V_295 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_297 ) {
F_6 ( L_130 ) ;
V_217 = - V_246 ;
goto V_74;
}
V_1 = 0 ;
V_297 [ V_1 ++ ] = L_237 ;
V_297 [ V_1 ++ ] = V_320 ;
for ( V_7 = 1 ; V_7 < V_365 + 1 ; V_7 ++ )
V_297 [ V_1 ++ ] = V_296 [ V_7 ] ;
V_297 [ V_1 ++ ] = L_242 ;
V_297 [ V_1 ++ ] = L_241 ;
V_297 [ V_1 ++ ] = NULL ;
F_169 ( L_237 , ( char * * ) V_297 ) ;
free ( V_297 ) ;
exit ( - 1 ) ;
}
if ( V_319 )
V_278 = V_319 ;
if ( V_320 )
V_278 = V_320 ;
if ( V_278 ) {
V_1 = 0 ;
if ( ! V_319 )
V_192 = false ;
else if ( ! V_192 ) {
if ( F_136 ( V_295 - 1 , & V_296 [ 1 ] ) != 0 ) {
V_217 = - 1 ;
goto V_74;
}
}
V_297 = malloc ( ( V_295 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_297 ) {
F_6 ( L_130 ) ;
V_217 = - V_246 ;
goto V_74;
}
V_297 [ V_1 ++ ] = L_237 ;
V_297 [ V_1 ++ ] = V_278 ;
if ( V_192 )
V_297 [ V_1 ++ ] = L_238 ;
for ( V_7 = 2 ; V_7 < V_295 ; V_7 ++ )
V_297 [ V_1 ++ ] = V_296 [ V_7 ] ;
V_297 [ V_1 ++ ] = NULL ;
F_169 ( L_237 , ( char * * ) V_297 ) ;
free ( V_297 ) ;
exit ( - 1 ) ;
}
if ( ! V_242 )
F_170 () ;
V_21 = F_128 ( & V_288 , false , & V_175 . V_203 ) ;
if ( V_21 == NULL )
return - 1 ;
if ( V_22 || V_317 ) {
F_171 ( V_21 , stdout , V_316 ) ;
if ( V_317 )
goto V_367;
}
if ( F_172 ( & V_21 -> V_22 . V_368 ) < 0 )
goto V_367;
V_175 . V_21 = V_21 ;
F_138 ( & V_175 ) ;
if ( V_3 [ V_247 ] . V_19 & V_369 )
V_321 . V_370 = true ;
V_21 -> V_321 = & V_321 ;
if ( V_214 ) {
V_217 = F_173 ( V_21 , V_214 , V_215 ) ;
if ( V_217 < 0 )
goto V_367;
}
if ( ! V_66 )
V_70 . V_67 = true ;
else
V_70 . V_67 = false ;
if ( V_21 -> V_371 . V_372 &&
F_174 ( V_21 -> V_371 . V_372 ,
V_373 ,
& V_21 -> V_374 . V_375 ) < 0 ) {
F_6 ( L_243 , V_376 ) ;
return - 1 ;
}
if ( V_343 ) {
struct V_256 V_377 ;
int V_378 ;
if ( F_1 () ) {
fprintf ( V_238 ,
L_244 ) ;
V_217 = - V_26 ;
goto V_367;
}
V_378 = F_175 ( V_288 . V_255 , V_379 ) ;
if ( V_378 < 0 ) {
V_217 = - V_380 ;
perror ( L_245 ) ;
goto V_367;
}
V_217 = F_176 ( V_378 , & V_377 ) ;
if ( V_217 < 0 ) {
perror ( L_246 ) ;
goto V_367;
}
if ( ! V_377 . V_381 ) {
fprintf ( V_238 , L_247 ) ;
goto V_367;
}
V_198 = F_102 ( V_343 ) ;
if ( ! V_198 ) {
fprintf ( V_238 , L_93 ) ;
V_217 = - V_382 ;
goto V_367;
}
V_217 = V_198 -> V_383 ( V_21 -> V_371 . V_372 ,
L_248 ) ;
goto V_367;
}
if ( V_242 ) {
V_217 = V_198 -> V_384 ( V_242 , V_295 , V_296 ) ;
if ( V_217 )
goto V_367;
F_7 ( L_249 , V_242 ) ;
V_318 = true ;
}
V_217 = F_14 ( V_21 ) ;
if ( V_217 < 0 )
goto V_367;
if ( F_177 ( & V_175 . V_208 , V_175 . V_359 ) != 0 ) {
F_6 ( L_250 ) ;
return - V_26 ;
}
V_217 = F_94 ( & V_175 ) ;
F_66 () ;
V_367:
F_178 ( V_21 -> V_167 ) ;
F_129 ( V_21 ) ;
if ( V_318 )
F_67 () ;
V_74:
return V_217 ;
}
