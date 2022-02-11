static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 () ) ;
F_4 ( V_3 , V_2 ) ;
}
struct V_1 * F_5 ( void )
{
F_2 ( F_3 () ) ;
return F_6 ( V_3 ) ;
}
struct V_1 T_1 * * F_7 ( void )
{
return & V_3 ;
}
int F_8 ( void * V_4 )
{
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_2 ) == V_5 ;
}
void F_11 ( void * V_4 )
{
}
int F_12 ( void )
{
return 0 ;
}
void F_13 ( void )
{
}
void F_14 ( void * V_6 )
{
* ( int * ) V_6 = 0 ;
}
void F_15 ( struct V_7 * V_7 )
{
}
int F_16 ( struct V_7 * V_7 , unsigned long type )
{
int V_8 = 0 ;
if ( type )
return - V_9 ;
V_8 = F_17 ( V_7 ) ;
if ( V_8 )
goto V_10;
V_8 = F_18 ( V_7 , V_7 + 1 ) ;
if ( V_8 )
goto V_11;
F_19 ( V_7 ) ;
V_7 -> V_12 . V_13 = 0 ;
return V_8 ;
V_11:
F_20 ( V_7 ) ;
V_10:
return V_8 ;
}
int F_21 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
return V_16 ;
}
void F_22 ( struct V_7 * V_7 , struct V_17 * free ,
struct V_17 * V_18 )
{
}
int F_23 ( struct V_7 * V_7 , struct V_17 * V_19 ,
unsigned long V_20 )
{
return 0 ;
}
void F_24 ( struct V_7 * V_7 )
{
int V_21 ;
F_20 ( V_7 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; ++ V_21 ) {
if ( V_7 -> V_23 [ V_21 ] ) {
F_25 ( V_7 -> V_23 [ V_21 ] ) ;
V_7 -> V_23 [ V_21 ] = NULL ;
}
}
}
int F_26 ( long V_24 )
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
case V_33 :
V_25 = 1 ;
break;
case V_34 :
V_25 = V_35 ;
break;
case V_36 :
V_25 = 1 ;
break;
case V_37 :
V_25 = F_27 () ;
break;
case V_38 :
V_25 = V_22 ;
break;
default:
V_25 = F_28 ( V_24 ) ;
break;
}
return V_25 ;
}
long F_29 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
return - V_9 ;
}
void F_30 ( struct V_7 * V_7 )
{
}
int F_31 ( struct V_7 * V_7 ,
struct V_17 * V_43 ,
struct V_44 * V_45 ,
enum V_46 V_47 )
{
return 0 ;
}
void F_32 ( struct V_7 * V_7 ,
struct V_44 * V_45 ,
const struct V_17 * V_48 ,
enum V_46 V_47 )
{
}
void F_33 ( struct V_7 * V_7 )
{
}
void F_34 ( struct V_7 * V_7 ,
struct V_17 * V_19 )
{
}
struct V_1 * F_35 ( struct V_7 * V_7 , unsigned int V_49 )
{
int V_50 ;
struct V_1 * V_2 ;
V_2 = F_36 ( V_51 , V_52 ) ;
if ( ! V_2 ) {
V_50 = - V_53 ;
goto V_54;
}
V_50 = F_37 ( V_2 , V_7 , V_49 ) ;
if ( V_50 )
goto V_55;
V_50 = F_18 ( V_2 , V_2 + 1 ) ;
if ( V_50 )
goto V_56;
return V_2 ;
V_56:
F_38 ( V_2 ) ;
V_55:
F_39 ( V_51 , V_2 ) ;
V_54:
return F_40 ( V_50 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_39 ( V_51 , V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_12 . V_57 = - 1 ;
V_8 = F_47 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_48 ( V_2 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
}
void F_50 ( struct V_1 * V_2 , int V_58 )
{
V_2 -> V_58 = V_58 ;
V_2 -> V_12 . V_59 = F_51 ( V_60 ) ;
if ( F_52 ( V_58 , & V_2 -> V_12 . V_61 ) )
F_53 () ;
F_1 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
V_2 -> V_58 = - 1 ;
F_1 ( NULL ) ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_62 * V_63 )
{
return - V_9 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
return - V_9 ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
return - V_9 ;
}
int F_58 ( struct V_1 * V_66 )
{
return ! ! V_66 -> V_12 . V_67 || F_59 ( V_66 ) ;
}
static void F_60 ( void * V_68 )
{
}
void F_61 ( const T_2 * V_69 )
{
F_62 ( V_69 , F_60 , NULL , true ) ;
}
static bool F_63 ( struct V_7 * V_7 )
{
return F_64 ( V_7 -> V_12 . V_13 != F_65 ( & V_70 ) ) ;
}
static void F_66 ( struct V_7 * V_7 )
{
T_3 V_71 ;
T_4 V_72 ;
if ( ! F_63 ( V_7 ) )
return;
F_67 ( & V_73 ) ;
if ( ! F_63 ( V_7 ) ) {
F_68 ( & V_73 ) ;
return;
}
if ( F_64 ( V_74 == 0 ) ) {
F_69 ( & V_70 ) ;
V_74 = 1 ;
F_61 ( V_75 ) ;
F_70 ( V_76 ) ;
}
V_7 -> V_12 . V_13 = F_65 ( & V_70 ) ;
V_7 -> V_12 . V_72 = V_74 ;
V_74 ++ ;
V_71 = F_71 ( V_7 -> V_12 . V_77 ) ;
V_72 = ( ( T_4 ) ( V_7 -> V_12 . V_72 ) << V_78 ) & V_79 ;
V_7 -> V_12 . V_80 = V_71 & V_81 ;
V_7 -> V_12 . V_80 |= V_72 ;
F_68 ( & V_73 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_8 ;
if ( F_73 ( V_2 -> V_12 . V_82 ) )
return 0 ;
V_2 -> V_12 . V_82 = true ;
if ( F_64 ( ! F_74 ( V_2 -> V_7 ) ) ) {
V_8 = F_75 ( V_2 -> V_7 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
T_5 * V_83 = F_77 ( V_2 ) ;
F_78 ( * V_83 , ! V_2 -> V_12 . V_84 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
return V_2 -> V_12 . V_57 >= 0 ;
}
int F_80 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
int V_8 ;
T_6 V_87 ;
if ( F_64 ( ! F_79 ( V_2 ) ) )
return - V_88 ;
V_8 = F_72 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( V_86 -> V_89 == V_90 ) {
V_8 = F_81 ( V_2 , V_2 -> V_86 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_2 -> V_91 )
F_82 ( V_92 , & V_2 -> V_93 , & V_87 ) ;
V_8 = 1 ;
V_86 -> V_89 = V_94 ;
while ( V_8 > 0 ) {
F_83 () ;
F_66 ( V_2 -> V_7 ) ;
if ( V_2 -> V_12 . V_84 )
F_76 ( V_2 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 () ;
if ( F_87 ( V_95 ) ) {
V_8 = - V_96 ;
V_86 -> V_89 = V_97 ;
}
if ( V_8 <= 0 || F_63 ( V_2 -> V_7 ) ) {
F_88 () ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
continue;
}
F_91 ( * F_92 ( V_2 ) ) ;
F_93 () ;
V_2 -> V_98 = V_5 ;
V_8 = F_70 ( V_99 , V_2 ) ;
V_2 -> V_98 = V_100 ;
V_2 -> V_12 . V_101 = F_94 () ;
F_95 () ;
F_96 ( * F_92 ( V_2 ) ) ;
F_88 () ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
V_8 = F_97 ( V_2 , V_86 , V_8 ) ;
}
if ( V_2 -> V_91 )
F_82 ( V_92 , & V_87 , NULL ) ;
return V_8 ;
}
static int F_98 ( struct V_1 * V_2 , int V_102 , bool V_103 )
{
int V_104 ;
bool V_105 ;
unsigned long * V_106 ;
if ( V_102 == V_107 )
V_104 = F_99 ( V_108 ) ;
else
V_104 = F_99 ( V_109 ) ;
V_106 = ( unsigned long * ) & V_2 -> V_12 . V_67 ;
if ( V_103 )
V_105 = F_100 ( V_104 , V_106 ) ;
else
V_105 = F_101 ( V_104 , V_106 ) ;
if ( V_105 == V_103 )
return 0 ;
F_102 ( V_2 ) ;
return 0 ;
}
int F_103 ( struct V_7 * V_7 , struct V_110 * V_111 ,
bool V_112 )
{
T_7 V_113 = V_111 -> V_113 ;
unsigned int V_114 , V_115 , V_116 ;
int V_117 = F_104 ( & V_7 -> V_118 ) ;
struct V_1 * V_2 = NULL ;
bool V_103 = V_111 -> V_103 ;
V_114 = ( V_113 >> V_119 ) & V_120 ;
V_115 = ( V_113 >> V_121 ) & V_122 ;
V_116 = ( V_113 >> V_123 ) & V_124 ;
F_105 ( V_114 , V_115 , V_116 , V_111 -> V_103 ) ;
switch ( V_114 ) {
case V_125 :
if ( F_106 ( V_7 ) )
return - V_126 ;
if ( V_115 >= V_117 )
return - V_9 ;
V_2 = F_107 ( V_7 , V_115 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_116 > V_127 )
return - V_9 ;
return F_98 ( V_2 , V_116 , V_103 ) ;
case V_128 :
if ( ! F_106 ( V_7 ) )
return - V_126 ;
if ( V_115 >= V_117 )
return - V_9 ;
V_2 = F_107 ( V_7 , V_115 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_116 < V_129 || V_116 >= V_130 )
return - V_9 ;
return F_108 ( V_7 , V_2 -> V_131 , V_116 , V_103 ) ;
case V_132 :
if ( ! F_106 ( V_7 ) )
return - V_126 ;
if ( V_116 < V_130 ||
V_116 > V_133 )
return - V_9 ;
return F_108 ( V_7 , 0 , V_116 , V_103 ) ;
}
return - V_9 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct F_37 * V_134 )
{
int V_8 ;
V_8 = F_110 ( V_2 , V_134 ) ;
if ( V_8 )
return V_8 ;
if ( F_111 ( V_135 , V_2 -> V_12 . V_136 ) )
V_2 -> V_12 . V_84 = true ;
return 0 ;
}
long F_112 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_1 * V_2 = V_40 -> V_137 ;
void T_8 * V_138 = ( void T_8 * ) V_42 ;
switch ( V_41 ) {
case V_139 : {
struct F_37 V_134 ;
if ( F_113 ( & V_134 , V_138 , sizeof( V_134 ) ) )
return - V_140 ;
return F_109 ( V_2 , & V_134 ) ;
}
case V_141 :
case V_142 : {
struct V_143 V_144 ;
if ( F_64 ( ! F_79 ( V_2 ) ) )
return - V_88 ;
if ( F_113 ( & V_144 , V_138 , sizeof( V_144 ) ) )
return - V_140 ;
if ( V_41 == V_141 )
return F_114 ( V_2 , & V_144 ) ;
else
return F_115 ( V_2 , & V_144 ) ;
}
case V_145 : {
struct V_146 T_8 * V_147 = V_138 ;
struct V_146 V_148 ;
unsigned V_149 ;
if ( F_64 ( ! F_79 ( V_2 ) ) )
return - V_88 ;
if ( F_113 ( & V_148 , V_147 , sizeof( V_148 ) ) )
return - V_140 ;
V_149 = V_148 . V_149 ;
V_148 . V_149 = F_116 ( V_2 ) ;
if ( F_117 ( V_147 , & V_148 , sizeof( V_148 ) ) )
return - V_140 ;
if ( V_149 < V_148 . V_149 )
return - V_150 ;
return F_118 ( V_2 , V_147 -> V_144 ) ;
}
default:
return - V_9 ;
}
}
int F_119 ( struct V_7 * V_7 , struct V_151 * log )
{
return - V_9 ;
}
static int F_120 ( struct V_7 * V_7 ,
struct V_152 * V_153 )
{
unsigned long V_154 , type ;
V_154 = ( V_153 -> V_49 & V_155 ) >>
V_156 ;
type = ( V_153 -> V_49 & V_157 ) >>
V_158 ;
switch ( V_154 ) {
case V_159 :
if ( ! V_27 )
return - V_126 ;
return F_121 ( V_7 , type , & V_153 -> V_160 , true ) ;
default:
return - V_161 ;
}
}
long F_122 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_7 * V_7 = V_40 -> V_137 ;
void T_8 * V_138 = ( void T_8 * ) V_42 ;
switch ( V_41 ) {
case V_162 : {
if ( V_27 )
return F_123 ( V_7 ) ;
else
return - V_126 ;
}
case V_163 : {
struct V_152 V_153 ;
if ( F_113 ( & V_153 , V_138 , sizeof( V_153 ) ) )
return - V_140 ;
return F_120 ( V_7 , & V_153 ) ;
}
case V_164 : {
int V_50 ;
struct F_37 V_134 ;
V_50 = F_124 ( & V_134 ) ;
if ( V_50 )
return V_50 ;
if ( F_117 ( V_138 , & V_134 , sizeof( V_134 ) ) )
return - V_140 ;
return 0 ;
}
default:
return - V_9 ;
}
}
static void F_125 ( void * V_165 )
{
T_3 V_166 ;
T_3 V_167 ;
unsigned long V_168 ;
unsigned long V_169 ;
unsigned long V_170 ;
F_126 ( F_127 () ) ;
V_166 = F_128 () ;
V_167 = F_129 () ;
V_169 = F_6 ( V_171 ) ;
V_168 = V_169 + V_172 ;
V_170 = ( unsigned long ) V_173 ;
F_130 ( V_166 , V_167 , V_168 , V_170 ) ;
}
static int F_131 ( struct V_174 * V_175 ,
unsigned long V_176 , void * V_58 )
{
switch ( V_176 ) {
case V_177 :
case V_178 :
F_125 ( NULL ) ;
break;
}
return V_179 ;
}
static int F_132 ( struct V_174 * V_175 ,
unsigned long V_180 ,
void * V_66 )
{
if ( V_180 == V_181 &&
F_133 () == V_182 ) {
F_125 ( NULL ) ;
return V_179 ;
}
return V_183 ;
}
static void T_9 F_134 ( void )
{
F_135 ( & V_184 ) ;
}
static inline void F_134 ( void )
{
}
static int F_136 ( void )
{
int V_58 ;
int V_50 = 0 ;
V_50 = F_137 () ;
if ( V_50 )
goto V_185;
V_182 = F_133 () ;
F_138 (cpu) {
unsigned long V_169 ;
V_169 = F_139 ( V_52 ) ;
if ( ! V_169 ) {
V_50 = - V_53 ;
goto V_186;
}
F_140 ( V_171 , V_58 ) = V_169 ;
}
V_50 = F_18 ( V_187 , V_188 ) ;
if ( V_50 ) {
F_141 ( L_1 ) ;
goto V_189;
}
F_138 (cpu) {
char * V_169 = ( char * ) F_140 ( V_171 , V_58 ) ;
V_50 = F_18 ( V_169 , V_169 + V_172 ) ;
if ( V_50 ) {
F_141 ( L_2 ) ;
goto V_189;
}
}
V_60 = F_142 ( V_190 ) ;
if ( ! V_60 ) {
V_50 = - V_53 ;
F_141 ( L_3 ) ;
goto V_189;
}
F_138 (cpu) {
V_190 * V_191 ;
V_191 = F_143 ( V_60 , V_58 ) ;
V_50 = F_18 ( V_191 , V_191 + 1 ) ;
if ( V_50 ) {
F_141 ( L_4 , V_50 ) ;
goto V_192;
}
}
F_144 ( F_125 , NULL , 1 ) ;
V_50 = F_145 () ;
if ( V_50 )
goto V_192;
#ifdef F_146
V_27 = true ;
#endif
V_50 = F_147 () ;
if ( V_50 )
goto V_189;
#ifndef F_148
F_149 () ;
#endif
F_150 () ;
F_151 ( L_5 ) ;
return 0 ;
V_192:
F_152 ( V_60 ) ;
V_189:
F_153 () ;
V_186:
F_138 (cpu)
F_154 ( F_140 ( V_171 , V_58 ) ) ;
V_185:
F_141 ( L_6 , V_50 ) ;
return V_50 ;
}
static void F_155 ( void * V_8 )
{
* ( int * ) V_8 = F_156 () ;
}
int F_157 ( void * V_193 )
{
int V_50 ;
int V_8 , V_58 ;
if ( ! F_158 () ) {
F_141 ( L_7 ) ;
return - V_161 ;
}
F_159 (cpu) {
F_160 ( V_58 , F_155 , & V_8 , 1 ) ;
if ( V_8 < 0 ) {
F_141 ( L_8 , V_58 ) ;
return - V_161 ;
}
}
F_161 () ;
V_50 = F_136 () ;
if ( V_50 )
goto V_185;
V_50 = F_162 ( & V_194 ) ;
if ( V_50 ) {
F_141 ( L_9 , V_50 ) ;
goto V_185;
}
F_163 () ;
F_134 () ;
F_164 () ;
return 0 ;
V_185:
F_163 () ;
return V_50 ;
}
void F_165 ( void )
{
F_166 () ;
}
static int F_167 ( void )
{
int V_195 = F_168 ( NULL , sizeof( struct V_1 ) , 0 , V_196 ) ;
return V_195 ;
}
