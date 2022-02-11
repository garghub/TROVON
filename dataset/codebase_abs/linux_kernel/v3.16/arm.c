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
case V_34 :
V_25 = 1 ;
break;
case V_35 :
V_25 = V_36 ;
break;
case V_37 :
V_25 = 1 ;
break;
case V_38 :
V_25 = F_27 () ;
break;
case V_39 :
V_25 = V_22 ;
break;
default:
V_25 = F_28 ( V_24 ) ;
break;
}
return V_25 ;
}
long F_29 ( struct V_40 * V_41 ,
unsigned int V_42 , unsigned long V_43 )
{
return - V_9 ;
}
void F_30 ( struct V_7 * V_7 )
{
}
int F_31 ( struct V_7 * V_7 ,
struct V_17 * V_44 ,
struct V_45 * V_46 ,
enum V_47 V_48 )
{
return 0 ;
}
void F_32 ( struct V_7 * V_7 ,
struct V_45 * V_46 ,
const struct V_17 * V_49 ,
enum V_47 V_48 )
{
}
void F_33 ( struct V_7 * V_7 )
{
}
void F_34 ( struct V_7 * V_7 ,
struct V_17 * V_19 )
{
}
struct V_1 * F_35 ( struct V_7 * V_7 , unsigned int V_50 )
{
int V_51 ;
struct V_1 * V_2 ;
V_2 = F_36 ( V_52 , V_53 ) ;
if ( ! V_2 ) {
V_51 = - V_54 ;
goto V_55;
}
V_51 = F_37 ( V_2 , V_7 , V_50 ) ;
if ( V_51 )
goto V_56;
V_51 = F_18 ( V_2 , V_2 + 1 ) ;
if ( V_51 )
goto V_57;
return V_2 ;
V_57:
F_38 ( V_2 ) ;
V_56:
F_39 ( V_52 , V_2 ) ;
V_55:
return F_40 ( V_51 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_39 ( V_52 , V_2 ) ;
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
V_2 -> V_12 . V_58 = - 1 ;
V_8 = F_47 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_48 ( V_2 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
}
void F_50 ( struct V_1 * V_2 , int V_59 )
{
V_2 -> V_59 = V_59 ;
V_2 -> V_12 . V_60 = F_51 ( V_61 ) ;
if ( F_52 ( V_59 , & V_2 -> V_12 . V_62 ) )
F_53 () ;
F_1 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
V_2 -> V_59 = - 1 ;
F_1 ( NULL ) ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
return - V_9 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
return - V_9 ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
return - V_9 ;
}
int F_58 ( struct V_1 * V_67 )
{
return ! ! V_67 -> V_12 . V_68 || F_59 ( V_67 ) ;
}
static void F_60 ( void * V_69 )
{
}
void F_61 ( const T_2 * V_70 )
{
F_62 ( V_70 , F_60 , NULL , true ) ;
}
static bool F_63 ( struct V_7 * V_7 )
{
return F_64 ( V_7 -> V_12 . V_13 != F_65 ( & V_71 ) ) ;
}
static void F_66 ( struct V_7 * V_7 )
{
T_3 V_72 ;
T_4 V_73 ;
if ( ! F_63 ( V_7 ) )
return;
F_67 ( & V_74 ) ;
if ( ! F_63 ( V_7 ) ) {
F_68 ( & V_74 ) ;
return;
}
if ( F_64 ( V_75 == 0 ) ) {
F_69 ( & V_71 ) ;
V_75 = 1 ;
F_61 ( V_76 ) ;
F_70 ( V_77 ) ;
}
V_7 -> V_12 . V_13 = F_65 ( & V_71 ) ;
V_7 -> V_12 . V_73 = V_75 ;
V_75 ++ ;
V_72 = F_71 ( V_7 -> V_12 . V_78 ) ;
V_73 = ( ( T_4 ) ( V_7 -> V_12 . V_73 ) << V_79 ) & V_80 ;
V_7 -> V_12 . V_81 = V_72 & V_82 ;
V_7 -> V_12 . V_81 |= V_73 ;
F_68 ( & V_74 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_8 ;
if ( F_73 ( V_2 -> V_12 . V_83 ) )
return 0 ;
V_2 -> V_12 . V_83 = true ;
if ( F_64 ( ! F_74 ( V_2 -> V_7 ) ) ) {
V_8 = F_75 ( V_2 -> V_7 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
T_5 * V_84 = F_77 ( V_2 ) ;
F_78 ( * V_84 , ! V_2 -> V_12 . V_85 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
return V_2 -> V_12 . V_58 >= 0 ;
}
int F_80 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
int V_8 ;
T_6 V_88 ;
if ( F_64 ( ! F_79 ( V_2 ) ) )
return - V_89 ;
V_8 = F_72 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( V_87 -> V_90 == V_91 ) {
V_8 = F_81 ( V_2 , V_2 -> V_87 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_2 -> V_92 )
F_82 ( V_93 , & V_2 -> V_94 , & V_88 ) ;
V_8 = 1 ;
V_87 -> V_90 = V_95 ;
while ( V_8 > 0 ) {
F_83 () ;
F_66 ( V_2 -> V_7 ) ;
if ( V_2 -> V_12 . V_85 )
F_76 ( V_2 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 () ;
if ( F_87 ( V_96 ) ) {
V_8 = - V_97 ;
V_87 -> V_90 = V_98 ;
}
if ( V_8 <= 0 || F_63 ( V_2 -> V_7 ) ) {
F_88 () ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
continue;
}
F_91 ( * F_92 ( V_2 ) ) ;
F_93 () ;
V_2 -> V_99 = V_5 ;
V_8 = F_70 ( V_100 , V_2 ) ;
V_2 -> V_99 = V_101 ;
V_2 -> V_12 . V_102 = F_94 () ;
F_95 () ;
F_96 ( * F_92 ( V_2 ) ) ;
F_88 () ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
V_8 = F_97 ( V_2 , V_87 , V_8 ) ;
}
if ( V_2 -> V_92 )
F_82 ( V_93 , & V_88 , NULL ) ;
return V_8 ;
}
static int F_98 ( struct V_1 * V_2 , int V_103 , bool V_104 )
{
int V_105 ;
bool V_106 ;
unsigned long * V_107 ;
if ( V_103 == V_108 )
V_105 = F_99 ( V_109 ) ;
else
V_105 = F_99 ( V_110 ) ;
V_107 = ( unsigned long * ) & V_2 -> V_12 . V_68 ;
if ( V_104 )
V_106 = F_100 ( V_105 , V_107 ) ;
else
V_106 = F_101 ( V_105 , V_107 ) ;
if ( V_106 == V_104 )
return 0 ;
F_102 ( V_2 ) ;
return 0 ;
}
int F_103 ( struct V_7 * V_7 , struct V_111 * V_112 ,
bool V_113 )
{
T_7 V_114 = V_112 -> V_114 ;
unsigned int V_115 , V_116 , V_117 ;
int V_118 = F_104 ( & V_7 -> V_119 ) ;
struct V_1 * V_2 = NULL ;
bool V_104 = V_112 -> V_104 ;
V_115 = ( V_114 >> V_120 ) & V_121 ;
V_116 = ( V_114 >> V_122 ) & V_123 ;
V_117 = ( V_114 >> V_124 ) & V_125 ;
F_105 ( V_115 , V_116 , V_117 , V_112 -> V_104 ) ;
switch ( V_115 ) {
case V_126 :
if ( F_106 ( V_7 ) )
return - V_127 ;
if ( V_116 >= V_118 )
return - V_9 ;
V_2 = F_107 ( V_7 , V_116 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_117 > V_128 )
return - V_9 ;
return F_98 ( V_2 , V_117 , V_104 ) ;
case V_129 :
if ( ! F_106 ( V_7 ) )
return - V_127 ;
if ( V_116 >= V_118 )
return - V_9 ;
V_2 = F_107 ( V_7 , V_116 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_117 < V_130 || V_117 >= V_131 )
return - V_9 ;
return F_108 ( V_7 , V_2 -> V_132 , V_117 , V_104 ) ;
case V_133 :
if ( ! F_106 ( V_7 ) )
return - V_127 ;
if ( V_117 < V_131 ||
V_117 > V_134 )
return - V_9 ;
return F_108 ( V_7 , 0 , V_117 , V_104 ) ;
}
return - V_9 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct F_37 * V_135 )
{
int V_8 ;
V_8 = F_110 ( V_2 , V_135 ) ;
if ( V_8 )
return V_8 ;
if ( F_111 ( V_136 , V_2 -> V_12 . V_137 ) )
V_2 -> V_12 . V_85 = true ;
return 0 ;
}
long F_112 ( struct V_40 * V_41 ,
unsigned int V_42 , unsigned long V_43 )
{
struct V_1 * V_2 = V_41 -> V_138 ;
void T_8 * V_139 = ( void T_8 * ) V_43 ;
switch ( V_42 ) {
case V_140 : {
struct F_37 V_135 ;
if ( F_113 ( & V_135 , V_139 , sizeof( V_135 ) ) )
return - V_141 ;
return F_109 ( V_2 , & V_135 ) ;
}
case V_142 :
case V_143 : {
struct V_144 V_145 ;
if ( F_64 ( ! F_79 ( V_2 ) ) )
return - V_89 ;
if ( F_113 ( & V_145 , V_139 , sizeof( V_145 ) ) )
return - V_141 ;
if ( V_42 == V_142 )
return F_114 ( V_2 , & V_145 ) ;
else
return F_115 ( V_2 , & V_145 ) ;
}
case V_146 : {
struct V_147 T_8 * V_148 = V_139 ;
struct V_147 V_149 ;
unsigned V_150 ;
if ( F_64 ( ! F_79 ( V_2 ) ) )
return - V_89 ;
if ( F_113 ( & V_149 , V_148 , sizeof( V_149 ) ) )
return - V_141 ;
V_150 = V_149 . V_150 ;
V_149 . V_150 = F_116 ( V_2 ) ;
if ( F_117 ( V_148 , & V_149 , sizeof( V_149 ) ) )
return - V_141 ;
if ( V_150 < V_149 . V_150 )
return - V_151 ;
return F_118 ( V_2 , V_148 -> V_145 ) ;
}
default:
return - V_9 ;
}
}
int F_119 ( struct V_7 * V_7 , struct V_152 * log )
{
return - V_9 ;
}
static int F_120 ( struct V_7 * V_7 ,
struct V_153 * V_154 )
{
unsigned long V_155 , type ;
V_155 = ( V_154 -> V_50 & V_156 ) >>
V_157 ;
type = ( V_154 -> V_50 & V_158 ) >>
V_159 ;
switch ( V_155 ) {
case V_160 :
if ( ! V_27 )
return - V_127 ;
return F_121 ( V_7 , type , & V_154 -> V_161 , true ) ;
default:
return - V_162 ;
}
}
long F_122 ( struct V_40 * V_41 ,
unsigned int V_42 , unsigned long V_43 )
{
struct V_7 * V_7 = V_41 -> V_138 ;
void T_8 * V_139 = ( void T_8 * ) V_43 ;
switch ( V_42 ) {
case V_163 : {
if ( V_27 )
return F_123 ( V_7 ) ;
else
return - V_127 ;
}
case V_164 : {
struct V_153 V_154 ;
if ( F_113 ( & V_154 , V_139 , sizeof( V_154 ) ) )
return - V_141 ;
return F_120 ( V_7 , & V_154 ) ;
}
case V_165 : {
int V_51 ;
struct F_37 V_135 ;
V_51 = F_124 ( & V_135 ) ;
if ( V_51 )
return V_51 ;
if ( F_117 ( V_139 , & V_135 , sizeof( V_135 ) ) )
return - V_141 ;
return 0 ;
}
default:
return - V_9 ;
}
}
static void F_125 ( void * V_166 )
{
T_3 V_167 ;
T_3 V_168 ;
unsigned long V_169 ;
unsigned long V_170 ;
unsigned long V_171 ;
F_126 ( F_127 () ) ;
V_167 = F_128 () ;
V_168 = F_129 () ;
V_170 = F_6 ( V_172 ) ;
V_169 = V_170 + V_173 ;
V_171 = ( unsigned long ) V_174 ;
F_130 ( V_167 , V_168 , V_169 , V_171 ) ;
}
static int F_131 ( struct V_175 * V_176 ,
unsigned long V_177 , void * V_59 )
{
switch ( V_177 ) {
case V_178 :
case V_179 :
F_125 ( NULL ) ;
break;
}
return V_180 ;
}
static int F_132 ( struct V_175 * V_176 ,
unsigned long V_181 ,
void * V_67 )
{
if ( V_181 == V_182 &&
F_133 () == V_183 ) {
F_125 ( NULL ) ;
return V_180 ;
}
return V_184 ;
}
static void T_9 F_134 ( void )
{
F_135 ( & V_185 ) ;
}
static inline void F_134 ( void )
{
}
static int F_136 ( void )
{
int V_59 ;
int V_51 = 0 ;
V_51 = F_137 () ;
if ( V_51 )
goto V_186;
V_183 = F_133 () ;
F_138 (cpu) {
unsigned long V_170 ;
V_170 = F_139 ( V_53 ) ;
if ( ! V_170 ) {
V_51 = - V_54 ;
goto V_187;
}
F_140 ( V_172 , V_59 ) = V_170 ;
}
V_51 = F_18 ( V_188 , V_189 ) ;
if ( V_51 ) {
F_141 ( L_1 ) ;
goto V_190;
}
F_138 (cpu) {
char * V_170 = ( char * ) F_140 ( V_172 , V_59 ) ;
V_51 = F_18 ( V_170 , V_170 + V_173 ) ;
if ( V_51 ) {
F_141 ( L_2 ) ;
goto V_190;
}
}
V_61 = F_142 ( V_191 ) ;
if ( ! V_61 ) {
V_51 = - V_54 ;
F_141 ( L_3 ) ;
goto V_190;
}
F_138 (cpu) {
V_191 * V_192 ;
V_192 = F_143 ( V_61 , V_59 ) ;
V_51 = F_18 ( V_192 , V_192 + 1 ) ;
if ( V_51 ) {
F_141 ( L_4 , V_51 ) ;
goto V_193;
}
}
F_144 ( F_125 , NULL , 1 ) ;
V_51 = F_145 () ;
if ( V_51 )
goto V_193;
#ifdef F_146
V_27 = true ;
#endif
V_51 = F_147 () ;
if ( V_51 )
goto V_190;
#ifndef F_148
F_149 () ;
#endif
F_150 () ;
F_151 ( L_5 ) ;
return 0 ;
V_193:
F_152 ( V_61 ) ;
V_190:
F_153 () ;
V_187:
F_138 (cpu)
F_154 ( F_140 ( V_172 , V_59 ) ) ;
V_186:
F_141 ( L_6 , V_51 ) ;
return V_51 ;
}
static void F_155 ( void * V_8 )
{
* ( int * ) V_8 = F_156 () ;
}
int F_157 ( void * V_194 )
{
int V_51 ;
int V_8 , V_59 ;
if ( ! F_158 () ) {
F_141 ( L_7 ) ;
return - V_162 ;
}
F_159 (cpu) {
F_160 ( V_59 , F_155 , & V_8 , 1 ) ;
if ( V_8 < 0 ) {
F_141 ( L_8 , V_59 ) ;
return - V_162 ;
}
}
F_161 () ;
V_51 = F_136 () ;
if ( V_51 )
goto V_186;
V_51 = F_162 ( & V_195 ) ;
if ( V_51 ) {
F_141 ( L_9 , V_51 ) ;
goto V_186;
}
F_163 () ;
F_134 () ;
F_164 () ;
return 0 ;
V_186:
F_163 () ;
return V_51 ;
}
void F_165 ( void )
{
F_166 () ;
}
static int F_167 ( void )
{
int V_196 = F_168 ( NULL , sizeof( struct V_1 ) , 0 , V_197 ) ;
return V_196 ;
}
