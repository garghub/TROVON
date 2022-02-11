static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 () ) ;
F_4 ( V_3 ) = V_2 ;
}
struct V_1 * F_5 ( void )
{
F_2 ( F_3 () ) ;
return F_4 ( V_3 ) ;
}
struct V_1 T_1 * * F_6 ( void )
{
return & V_3 ;
}
int F_7 ( void * V_4 )
{
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ) == V_5 ;
}
void F_10 ( void * V_4 )
{
}
int F_11 ( void )
{
return 0 ;
}
void F_12 ( void )
{
}
void F_13 ( void * V_6 )
{
* ( int * ) V_6 = 0 ;
}
void F_14 ( struct V_7 * V_7 )
{
}
int F_15 ( struct V_7 * V_7 , unsigned long type )
{
int V_8 = 0 ;
if ( type )
return - V_9 ;
V_8 = F_16 ( V_7 ) ;
if ( V_8 )
goto V_10;
V_8 = F_17 ( V_7 , V_7 + 1 ) ;
if ( V_8 )
goto V_11;
V_7 -> V_12 . V_13 = 0 ;
return V_8 ;
V_11:
F_18 ( V_7 ) ;
V_10:
return V_8 ;
}
int F_19 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
return V_16 ;
}
void F_20 ( struct V_17 * free ,
struct V_17 * V_18 )
{
}
int F_21 ( struct V_17 * V_19 , unsigned long V_20 )
{
return 0 ;
}
void F_22 ( struct V_7 * V_7 )
{
int V_21 ;
F_18 ( V_7 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; ++ V_21 ) {
if ( V_7 -> V_23 [ V_21 ] ) {
F_23 ( V_7 -> V_23 [ V_21 ] ) ;
V_7 -> V_23 [ V_21 ] = NULL ;
}
}
}
int F_24 ( long V_24 )
{
int V_25 ;
switch ( V_24 ) {
case V_26 :
V_25 = V_27 ;
break;
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
V_25 = 1 ;
break;
case V_33 :
V_25 = V_34 ;
break;
case V_35 :
V_25 = 1 ;
break;
case V_36 :
V_25 = F_25 () ;
break;
case V_37 :
V_25 = V_22 ;
break;
default:
V_25 = 0 ;
break;
}
return V_25 ;
}
long F_26 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
return - V_9 ;
}
int F_27 ( struct V_7 * V_7 ,
struct V_42 * V_43 ,
struct V_17 V_44 ,
int V_45 )
{
return 0 ;
}
int F_28 ( struct V_7 * V_7 ,
struct V_17 * V_46 ,
struct V_17 V_44 ,
struct V_42 * V_43 ,
bool V_45 )
{
return 0 ;
}
void F_29 ( struct V_7 * V_7 ,
struct V_42 * V_43 ,
struct V_17 V_44 ,
bool V_45 )
{
}
void F_30 ( struct V_7 * V_7 )
{
}
void F_31 ( struct V_7 * V_7 ,
struct V_17 * V_19 )
{
}
struct V_1 * F_32 ( struct V_7 * V_7 , unsigned int V_47 )
{
int V_48 ;
struct V_1 * V_2 ;
V_2 = F_33 ( V_49 , V_50 ) ;
if ( ! V_2 ) {
V_48 = - V_51 ;
goto V_52;
}
V_48 = F_34 ( V_2 , V_7 , V_47 ) ;
if ( V_48 )
goto V_53;
V_48 = F_17 ( V_2 , V_2 + 1 ) ;
if ( V_48 )
goto V_54;
return V_2 ;
V_54:
F_35 ( V_2 ) ;
V_53:
F_36 ( V_49 , V_2 ) ;
V_52:
return F_37 ( V_48 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_36 ( V_49 , V_2 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
}
int F_42 ( struct V_1 * V_2 )
{
return 0 ;
}
int T_2 F_43 ( void )
{
unsigned long V_55 = F_44 () ;
unsigned long V_56 = F_45 () ;
if ( V_55 != V_57 )
return - V_9 ;
switch ( V_56 ) {
case V_58 :
return V_59 ;
default:
return - V_9 ;
}
}
int F_46 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_12 . V_60 = - 1 ;
V_8 = F_47 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_48 ( V_2 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
}
void F_50 ( struct V_1 * V_2 , int V_61 )
{
V_2 -> V_61 = V_61 ;
V_2 -> V_12 . V_62 = F_51 ( V_63 ) ;
if ( F_52 ( V_61 , & V_2 -> V_12 . V_64 ) )
F_53 () ;
F_1 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
F_1 ( NULL ) ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
return - V_9 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
return - V_9 ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
return - V_9 ;
}
int F_58 ( struct V_1 * V_69 )
{
return ! ! V_69 -> V_12 . V_70 || F_59 ( V_69 ) ;
}
static void F_60 ( void * V_71 )
{
}
void F_61 ( const T_3 * V_72 )
{
F_62 ( V_72 , F_60 , NULL , true ) ;
}
static bool F_63 ( struct V_7 * V_7 )
{
return F_64 ( V_7 -> V_12 . V_13 != F_65 ( & V_73 ) ) ;
}
static void F_66 ( struct V_7 * V_7 )
{
T_4 V_74 ;
T_5 V_75 ;
if ( ! F_63 ( V_7 ) )
return;
F_67 ( & V_76 ) ;
if ( ! F_63 ( V_7 ) ) {
F_68 ( & V_76 ) ;
return;
}
if ( F_64 ( V_77 == 0 ) ) {
F_69 ( & V_73 ) ;
V_77 = 1 ;
F_61 ( V_78 ) ;
F_70 ( V_79 ) ;
}
V_7 -> V_12 . V_13 = F_65 ( & V_73 ) ;
V_7 -> V_12 . V_75 = V_77 ;
V_77 ++ ;
V_74 = F_71 ( V_7 -> V_12 . V_80 ) ;
V_75 = ( ( T_5 ) ( V_7 -> V_12 . V_75 ) << V_81 ) & V_82 ;
V_7 -> V_12 . V_83 = V_74 & V_84 ;
V_7 -> V_12 . V_83 |= V_75 ;
F_68 ( & V_76 ) ;
}
static int F_72 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
F_73 ( L_1 ) ;
F_74 () ;
return - V_9 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
F_76 ( * F_77 ( V_2 ) , * F_78 ( V_2 , 0 ) ,
V_2 -> V_12 . V_87 & V_88 ) ;
if ( F_79 ( V_2 ) )
return 1 ;
F_80 ( V_2 ) ;
return 1 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
if ( F_79 ( V_2 ) )
return 1 ;
F_80 ( V_2 ) ;
return 1 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
F_83 ( L_2 ,
V_2 -> V_12 . V_89 , V_2 -> V_12 . V_87 ) ;
return - V_90 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
F_83 ( L_3 ,
V_2 -> V_12 . V_89 , V_2 -> V_12 . V_87 ) ;
return - V_90 ;
}
static bool F_85 ( struct V_1 * V_2 )
{
unsigned long V_91 , V_92 , V_93 ;
F_2 ( ( ( V_2 -> V_12 . V_87 & V_94 ) >> V_95 ) == 0 ) ;
if ( V_2 -> V_12 . V_87 >> 30 )
return true ;
V_91 = * F_86 ( V_2 ) ;
if ( ( V_2 -> V_12 . V_87 & V_96 ) >> V_97 )
V_92 = ( V_2 -> V_12 . V_87 & V_98 ) >> V_99 ;
else {
unsigned long V_100 ;
V_100 = ( ( V_91 >> 8 ) & 0xFC ) | ( ( V_91 >> 25 ) & 0x3 ) ;
if ( V_100 == 0 )
return true ;
V_92 = ( V_100 >> 4 ) ;
}
V_93 = V_92 << 28 ;
return F_87 ( V_93 , V_91 ) != V_101 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_85 * V_86 ,
int V_102 )
{
unsigned long V_103 ;
switch ( V_102 ) {
case V_104 :
return 1 ;
case V_105 :
F_83 ( L_4 ,
V_2 -> V_12 . V_106 ) ;
F_74 () ;
F_89 ( L_5 ) ;
case V_107 :
case V_108 :
case V_109 :
V_103 = ( V_2 -> V_12 . V_87 & V_94 ) >> V_95 ;
if ( V_103 >= F_90 ( V_110 )
|| ! V_110 [ V_103 ] ) {
F_83 ( L_6
L_7 , V_103 ,
( unsigned int ) V_2 -> V_12 . V_87 ) ;
F_74 () ;
}
if ( ! F_85 ( V_2 ) ) {
bool V_111 = V_2 -> V_12 . V_87 & V_112 ;
F_91 ( V_2 , V_111 ) ;
return 1 ;
}
return V_110 [ V_103 ] ( V_2 , V_86 ) ;
default:
F_92 ( L_8 ,
V_102 ) ;
V_86 -> V_113 = V_114 ;
return 0 ;
}
}
static int F_93 ( struct V_1 * V_2 )
{
if ( F_94 ( V_2 -> V_12 . V_115 ) )
return 0 ;
V_2 -> V_12 . V_115 = true ;
if ( F_95 ( V_2 -> V_7 ) &&
F_64 ( ! F_96 ( V_2 -> V_7 ) ) ) {
int V_8 = F_97 ( V_2 -> V_7 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_98 ( V_116 , V_2 -> V_12 . V_117 ) ) {
* F_78 ( V_2 , 0 ) = V_118 ;
F_79 ( V_2 ) ;
}
return 0 ;
}
static void F_99 ( struct V_1 * V_2 )
{
T_6 * V_119 = F_100 ( V_2 ) ;
F_101 ( * V_119 , ! V_2 -> V_12 . V_120 ) ;
}
int F_102 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
int V_8 ;
T_7 V_121 ;
if ( F_64 ( V_2 -> V_12 . V_60 < 0 ) )
return - V_122 ;
V_8 = F_93 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( V_86 -> V_113 == V_123 ) {
V_8 = F_103 ( V_2 , V_2 -> V_86 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_2 -> V_124 )
F_104 ( V_125 , & V_2 -> V_126 , & V_121 ) ;
V_8 = 1 ;
V_86 -> V_113 = V_127 ;
while ( V_8 > 0 ) {
F_105 () ;
F_66 ( V_2 -> V_7 ) ;
if ( V_2 -> V_12 . V_120 )
F_99 ( V_2 ) ;
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
F_108 () ;
if ( F_109 ( V_128 ) ) {
V_8 = - V_129 ;
V_86 -> V_113 = V_130 ;
}
if ( V_8 <= 0 || F_63 ( V_2 -> V_7 ) ) {
F_110 () ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
continue;
}
F_113 ( * F_77 ( V_2 ) ) ;
F_114 () ;
V_2 -> V_131 = V_5 ;
V_8 = F_70 ( V_132 , V_2 ) ;
V_2 -> V_131 = V_133 ;
V_2 -> V_12 . V_134 = F_115 () ;
F_116 () ;
F_117 ( * F_77 ( V_2 ) ) ;
F_110 () ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
V_8 = F_88 ( V_2 , V_86 , V_8 ) ;
}
if ( V_2 -> V_124 )
F_104 ( V_125 , & V_121 , NULL ) ;
return V_8 ;
}
static int F_118 ( struct V_1 * V_2 , int V_135 , bool V_136 )
{
int V_137 ;
bool V_138 ;
unsigned long * V_139 ;
if ( V_135 == V_140 )
V_137 = F_119 ( V_141 ) ;
else
V_137 = F_119 ( V_142 ) ;
V_139 = ( unsigned long * ) & V_2 -> V_12 . V_70 ;
if ( V_136 )
V_138 = F_120 ( V_137 , V_139 ) ;
else
V_138 = F_98 ( V_137 , V_139 ) ;
if ( V_138 == V_136 )
return 0 ;
F_121 ( V_2 ) ;
return 0 ;
}
int F_122 ( struct V_7 * V_7 , struct V_143 * V_144 )
{
T_8 V_145 = V_144 -> V_145 ;
unsigned int V_146 , V_147 , V_148 ;
int V_149 = F_123 ( & V_7 -> V_150 ) ;
struct V_1 * V_2 = NULL ;
bool V_136 = V_144 -> V_136 ;
V_146 = ( V_145 >> V_151 ) & V_152 ;
V_147 = ( V_145 >> V_153 ) & V_154 ;
V_148 = ( V_145 >> V_155 ) & V_156 ;
F_124 ( V_146 , V_147 , V_148 , V_144 -> V_136 ) ;
switch ( V_146 ) {
case V_157 :
if ( F_95 ( V_7 ) )
return - V_158 ;
if ( V_147 >= V_149 )
return - V_9 ;
V_2 = F_125 ( V_7 , V_147 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_148 > V_159 )
return - V_9 ;
return F_118 ( V_2 , V_148 , V_136 ) ;
case V_160 :
if ( ! F_95 ( V_7 ) )
return - V_158 ;
if ( V_147 >= V_149 )
return - V_9 ;
V_2 = F_125 ( V_7 , V_147 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_148 < V_161 || V_148 >= V_162 )
return - V_9 ;
return F_126 ( V_7 , V_2 -> V_163 , V_148 , V_136 ) ;
case V_164 :
if ( ! F_95 ( V_7 ) )
return - V_158 ;
if ( V_148 < V_162 ||
V_148 > V_165 )
return - V_9 ;
return F_126 ( V_7 , 0 , V_148 , V_136 ) ;
}
return - V_9 ;
}
long F_127 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_1 * V_2 = V_39 -> V_166 ;
void T_9 * V_167 = ( void T_9 * ) V_41 ;
switch ( V_40 ) {
case V_168 : {
struct F_34 V_169 ;
if ( F_128 ( & V_169 , V_167 , sizeof( V_169 ) ) )
return - V_90 ;
return F_129 ( V_2 , & V_169 ) ;
}
case V_170 :
case V_171 : {
struct V_172 V_173 ;
if ( F_128 ( & V_173 , V_167 , sizeof( V_173 ) ) )
return - V_90 ;
if ( V_40 == V_170 )
return F_130 ( V_2 , & V_173 ) ;
else
return F_131 ( V_2 , & V_173 ) ;
}
case V_174 : {
struct V_175 T_9 * V_176 = V_167 ;
struct V_175 V_177 ;
unsigned V_178 ;
if ( F_128 ( & V_177 , V_176 , sizeof( V_177 ) ) )
return - V_90 ;
V_178 = V_177 . V_178 ;
V_177 . V_178 = F_132 ( V_2 ) ;
if ( F_133 ( V_176 , & V_177 , sizeof( V_177 ) ) )
return - V_90 ;
if ( V_178 < V_177 . V_178 )
return - V_179 ;
return F_134 ( V_2 , V_176 -> V_173 ) ;
}
default:
return - V_9 ;
}
}
int F_135 ( struct V_7 * V_7 , struct V_180 * log )
{
return - V_9 ;
}
static int F_136 ( struct V_7 * V_7 ,
struct V_181 * V_182 )
{
unsigned long V_183 , type ;
V_183 = ( V_182 -> V_47 & V_184 ) >>
V_185 ;
type = ( V_182 -> V_47 & V_186 ) >>
V_187 ;
switch ( V_183 ) {
case V_188 :
if ( ! V_27 )
return - V_158 ;
return F_137 ( V_7 , type , V_182 -> V_189 ) ;
default:
return - V_190 ;
}
}
long F_138 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_7 * V_7 = V_39 -> V_166 ;
void T_9 * V_167 = ( void T_9 * ) V_41 ;
switch ( V_40 ) {
case V_191 : {
if ( V_27 )
return F_139 ( V_7 ) ;
else
return - V_158 ;
}
case V_192 : {
struct V_181 V_182 ;
if ( F_128 ( & V_182 , V_167 , sizeof( V_182 ) ) )
return - V_90 ;
return F_136 ( V_7 , & V_182 ) ;
}
default:
return - V_9 ;
}
}
static void F_140 ( void * V_193 )
{
unsigned long long V_194 ;
unsigned long V_195 , V_196 ;
unsigned long V_197 ;
unsigned long V_198 ;
unsigned long V_199 ;
F_141 ( ( unsigned long ) V_193 ) ;
V_194 = ( unsigned long long ) F_142 () ;
V_195 = ( V_194 & ( ( 1ULL << 32 ) - 1 ) ) ;
V_196 = ( V_194 >> 32ULL ) ;
V_198 = F_4 ( V_200 ) ;
V_197 = V_198 + V_201 ;
V_199 = ( unsigned long ) V_202 ;
F_70 ( ( void * ) V_195 , V_196 , V_197 , V_199 ) ;
}
static int F_143 ( void )
{
T_4 V_203 ;
int V_61 ;
int V_48 = 0 ;
V_48 = F_144 () ;
if ( V_48 )
goto V_204;
V_205 = F_145 () ;
F_146 (cpu) {
unsigned long V_198 ;
V_198 = F_147 ( V_50 ) ;
if ( ! V_198 ) {
V_48 = - V_51 ;
goto V_206;
}
F_148 ( V_200 , V_61 ) = V_198 ;
}
V_203 = F_71 ( V_207 ) ;
F_149 (cpu) {
F_150 ( V_61 , F_140 ,
( void * ) ( long ) V_203 , 1 ) ;
}
F_151 () ;
V_48 = F_17 ( V_208 , V_209 ) ;
if ( V_48 ) {
F_83 ( L_9 ) ;
goto V_210;
}
F_146 (cpu) {
char * V_198 = ( char * ) F_148 ( V_200 , V_61 ) ;
V_48 = F_17 ( V_198 , V_198 + V_201 ) ;
if ( V_48 ) {
F_83 ( L_10 ) ;
goto V_210;
}
}
V_63 = F_152 ( struct V_211 ) ;
if ( ! V_63 ) {
V_48 = - V_51 ;
F_83 ( L_11 ) ;
goto V_210;
}
F_146 (cpu) {
struct V_211 * V_212 ;
V_212 = F_153 ( V_63 , V_61 ) ;
V_48 = F_17 ( V_212 , V_212 + 1 ) ;
if ( V_48 ) {
F_83 ( L_12 , V_48 ) ;
goto V_213;
}
}
V_48 = F_154 () ;
if ( V_48 )
goto V_213;
#ifdef F_155
V_27 = true ;
#endif
V_48 = F_156 () ;
if ( V_48 )
goto V_210;
F_157 ( L_13 ) ;
return 0 ;
V_213:
F_158 ( V_63 ) ;
V_210:
F_159 () ;
V_206:
F_146 (cpu)
F_160 ( F_148 ( V_200 , V_61 ) ) ;
V_204:
F_83 ( L_14 , V_48 ) ;
return V_48 ;
}
int F_161 ( void * V_214 )
{
int V_48 ;
if ( ! F_162 () ) {
F_83 ( L_15 ) ;
return - V_190 ;
}
if ( F_43 () < 0 ) {
F_83 ( L_16 ) ;
return - V_190 ;
}
V_48 = F_143 () ;
if ( V_48 )
goto V_204;
F_163 () ;
return 0 ;
V_204:
return V_48 ;
}
void F_164 ( void )
{
}
static int F_165 ( void )
{
int V_215 = F_166 ( NULL , sizeof( struct V_1 ) , 0 , V_216 ) ;
return V_215 ;
}
