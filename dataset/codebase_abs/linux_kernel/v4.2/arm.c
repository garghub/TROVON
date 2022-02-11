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
struct V_1 * T_1 * F_7 ( void )
{
return & V_3 ;
}
int F_8 ( void )
{
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_2 ) == V_4 ;
}
int F_11 ( void )
{
return 0 ;
}
void F_12 ( void * V_5 )
{
* ( int * ) V_5 = 0 ;
}
int F_13 ( struct V_6 * V_6 , unsigned long type )
{
int V_7 = 0 ;
if ( type )
return - V_8 ;
V_7 = F_14 ( V_6 ) ;
if ( V_7 )
goto V_9;
V_7 = F_15 ( V_6 , V_6 + 1 ) ;
if ( V_7 )
goto V_10;
F_16 ( V_6 ) ;
V_6 -> V_11 . V_12 = 0 ;
V_6 -> V_11 . V_13 = F_17 () ;
return V_7 ;
V_10:
F_18 ( V_6 ) ;
V_9:
return V_7 ;
}
int F_19 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
return V_16 ;
}
void F_20 ( struct V_6 * V_6 )
{
int V_17 ;
F_18 ( V_6 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; ++ V_17 ) {
if ( V_6 -> V_19 [ V_17 ] ) {
F_21 ( V_6 -> V_19 [ V_17 ] ) ;
V_6 -> V_19 [ V_17 ] = NULL ;
}
}
F_22 ( V_6 ) ;
}
int F_23 ( struct V_6 * V_6 , long V_20 )
{
int V_21 ;
switch ( V_20 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
V_21 = 1 ;
break;
case V_33 :
V_21 = V_34 ;
break;
case V_35 :
V_21 = 1 ;
break;
case V_36 :
V_21 = F_24 () ;
break;
case V_37 :
V_21 = V_18 ;
break;
default:
V_21 = F_25 ( V_20 ) ;
break;
}
return V_21 ;
}
long F_26 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
return - V_8 ;
}
struct V_1 * F_27 ( struct V_6 * V_6 , unsigned int V_42 )
{
int V_43 ;
struct V_1 * V_2 ;
if ( F_28 ( V_6 ) && F_29 ( V_6 ) ) {
V_43 = - V_44 ;
goto V_45;
}
if ( V_42 >= V_6 -> V_11 . V_13 ) {
V_43 = - V_8 ;
goto V_45;
}
V_2 = F_30 ( V_46 , V_47 ) ;
if ( ! V_2 ) {
V_43 = - V_48 ;
goto V_45;
}
V_43 = F_31 ( V_2 , V_6 , V_42 ) ;
if ( V_43 )
goto V_49;
V_43 = F_15 ( V_2 , V_2 + 1 ) ;
if ( V_43 )
goto V_50;
return V_2 ;
V_50:
F_32 ( V_2 ) ;
V_49:
F_33 ( V_46 , V_2 ) ;
V_45:
return F_34 ( V_43 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
}
void F_21 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_33 ( V_46 , V_2 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
}
int F_40 ( struct V_1 * V_2 )
{
return F_41 ( V_2 ) ;
}
int F_42 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_51 = - 1 ;
F_43 ( V_2 -> V_11 . V_52 , V_53 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 , int V_54 )
{
V_2 -> V_54 = V_54 ;
V_2 -> V_11 . V_55 = F_46 ( V_56 ) ;
F_1 ( V_2 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_54 = - 1 ;
F_1 ( NULL ) ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
return - V_8 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
if ( V_2 -> V_11 . V_61 )
V_60 -> V_60 = V_62 ;
else
V_60 -> V_60 = V_63 ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
switch ( V_60 -> V_60 ) {
case V_63 :
V_2 -> V_11 . V_61 = false ;
break;
case V_62 :
V_2 -> V_11 . V_61 = true ;
break;
default:
return - V_8 ;
}
return 0 ;
}
int F_51 ( struct V_1 * V_64 )
{
return ! ! V_64 -> V_11 . V_65 || F_52 ( V_64 ) ;
}
static void F_53 ( void * V_66 )
{
}
void F_54 ( const T_2 * V_67 )
{
F_55 ( V_67 , F_53 , NULL , true ) ;
}
static bool F_56 ( struct V_6 * V_6 )
{
return F_57 ( V_6 -> V_11 . V_12 != F_58 ( & V_68 ) ) ;
}
static void F_59 ( struct V_6 * V_6 )
{
T_3 V_69 ;
T_4 V_70 ;
if ( ! F_56 ( V_6 ) )
return;
F_60 ( & V_71 ) ;
if ( ! F_56 ( V_6 ) ) {
F_61 ( & V_71 ) ;
return;
}
if ( F_57 ( V_72 == 0 ) ) {
F_62 ( & V_68 ) ;
V_72 = 1 ;
F_54 ( V_73 ) ;
F_63 ( V_74 ) ;
}
V_6 -> V_11 . V_12 = F_58 ( & V_68 ) ;
V_6 -> V_11 . V_70 = V_72 ;
V_72 ++ ;
V_69 = F_64 ( F_65 ( V_6 ) ) ;
F_2 ( V_69 & ~ V_75 ) ;
V_70 = ( ( T_4 ) ( V_6 -> V_11 . V_70 ) << V_76 ) & V_77 ;
V_6 -> V_11 . V_78 = V_69 | V_70 ;
F_61 ( & V_71 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 ;
if ( F_67 ( V_2 -> V_11 . V_79 ) )
return 0 ;
V_2 -> V_11 . V_79 = true ;
if ( F_57 ( ! F_68 ( V_6 ) ) ) {
V_7 = F_69 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
if ( F_28 ( V_6 ) && F_29 ( V_6 ) )
F_70 ( V_6 ) ;
return 0 ;
}
bool F_71 ( struct V_6 * V_6 )
{
return F_29 ( V_6 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
T_5 * V_80 = F_73 ( V_2 ) ;
F_74 ( * V_80 , ! V_2 -> V_11 . V_61 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
return V_2 -> V_11 . V_51 >= 0 ;
}
int F_76 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
int V_7 ;
T_6 V_83 ;
if ( F_57 ( ! F_75 ( V_2 ) ) )
return - V_84 ;
V_7 = F_66 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_82 -> V_85 == V_86 ) {
V_7 = F_77 ( V_2 , V_2 -> V_82 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_87 )
F_78 ( V_88 , & V_2 -> V_89 , & V_83 ) ;
V_7 = 1 ;
V_82 -> V_85 = V_90 ;
while ( V_7 > 0 ) {
F_79 () ;
F_59 ( V_2 -> V_6 ) ;
if ( V_2 -> V_11 . V_61 )
F_72 ( V_2 ) ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
F_82 () ;
F_83 () ;
if ( F_84 ( V_91 ) ) {
V_7 = - V_92 ;
V_82 -> V_85 = V_93 ;
}
if ( V_7 <= 0 || F_56 ( V_2 -> V_6 ) ) {
F_85 () ;
F_86 () ;
F_87 ( V_2 ) ;
F_88 ( V_2 ) ;
continue;
}
F_89 ( * F_90 ( V_2 ) ) ;
F_91 () ;
V_2 -> V_94 = V_4 ;
V_7 = F_63 ( V_95 , V_2 ) ;
V_2 -> V_94 = V_96 ;
F_85 () ;
F_92 () ;
F_93 ( F_94 ( V_2 ) , * F_90 ( V_2 ) ) ;
F_86 () ;
F_87 ( V_2 ) ;
F_88 ( V_2 ) ;
V_7 = F_95 ( V_2 , V_82 , V_7 ) ;
}
if ( V_2 -> V_87 )
F_78 ( V_88 , & V_83 , NULL ) ;
return V_7 ;
}
static int F_96 ( struct V_1 * V_2 , int V_97 , bool V_98 )
{
int V_99 ;
bool V_100 ;
unsigned long * V_101 ;
if ( V_97 == V_102 )
V_99 = F_97 ( V_103 ) ;
else
V_99 = F_97 ( V_104 ) ;
V_101 = ( unsigned long * ) & V_2 -> V_11 . V_65 ;
if ( V_98 )
V_100 = F_98 ( V_99 , V_101 ) ;
else
V_100 = F_99 ( V_99 , V_101 ) ;
if ( V_100 == V_98 )
return 0 ;
F_100 ( V_2 ) ;
return 0 ;
}
int F_101 ( struct V_6 * V_6 , struct V_105 * V_106 ,
bool V_107 )
{
T_7 V_108 = V_106 -> V_108 ;
unsigned int V_109 , V_110 , V_111 ;
int V_112 = F_102 ( & V_6 -> V_113 ) ;
struct V_1 * V_2 = NULL ;
bool V_98 = V_106 -> V_98 ;
V_109 = ( V_108 >> V_114 ) & V_115 ;
V_110 = ( V_108 >> V_116 ) & V_117 ;
V_111 = ( V_108 >> V_118 ) & V_119 ;
F_103 ( V_109 , V_110 , V_111 , V_106 -> V_98 ) ;
switch ( V_109 ) {
case V_120 :
if ( F_28 ( V_6 ) )
return - V_121 ;
if ( V_110 >= V_112 )
return - V_8 ;
V_2 = F_104 ( V_6 , V_110 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_111 > V_122 )
return - V_8 ;
return F_96 ( V_2 , V_111 , V_98 ) ;
case V_123 :
if ( ! F_28 ( V_6 ) )
return - V_121 ;
if ( V_110 >= V_112 )
return - V_8 ;
V_2 = F_104 ( V_6 , V_110 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_111 < V_124 || V_111 >= V_125 )
return - V_8 ;
return F_105 ( V_6 , V_2 -> V_126 , V_111 , V_98 ) ;
case V_127 :
if ( ! F_28 ( V_6 ) )
return - V_121 ;
if ( V_111 < V_125 )
return - V_8 ;
return F_105 ( V_6 , 0 , V_111 , V_98 ) ;
}
return - V_8 ;
}
static int F_106 ( struct V_1 * V_2 ,
const struct F_31 * V_128 )
{
unsigned int V_17 ;
int V_129 = F_107 () ;
if ( V_128 -> V_51 != V_129 )
return - V_8 ;
if ( V_2 -> V_11 . V_51 != - 1 && V_2 -> V_11 . V_51 != V_128 -> V_51 )
return - V_8 ;
for ( V_17 = 0 ; V_17 < sizeof( V_128 -> V_52 ) * 8 ; V_17 ++ ) {
bool V_100 = ( V_128 -> V_52 [ V_17 / 32 ] & ( 1 << ( V_17 % 32 ) ) ) ;
if ( V_100 && V_17 >= V_53 )
return - V_130 ;
if ( V_2 -> V_11 . V_51 != - 1 && V_17 < V_53 &&
F_108 ( V_17 , V_2 -> V_11 . V_52 ) != V_100 )
return - V_8 ;
if ( V_100 )
F_109 ( V_17 , V_2 -> V_11 . V_52 ) ;
}
V_2 -> V_11 . V_51 = V_129 ;
return F_110 ( V_2 ) ;
}
static int F_111 ( struct V_1 * V_2 ,
struct F_31 * V_128 )
{
int V_7 ;
V_7 = F_106 ( V_2 , V_128 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_11 . V_79 )
F_112 ( V_2 -> V_6 ) ;
F_113 ( V_2 ) ;
if ( F_108 ( V_131 , V_2 -> V_11 . V_52 ) )
V_2 -> V_11 . V_61 = true ;
else
V_2 -> V_11 . V_61 = false ;
return 0 ;
}
long F_114 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_1 * V_2 = V_39 -> V_132 ;
void T_8 * V_133 = ( void T_8 * ) V_41 ;
switch ( V_40 ) {
case V_134 : {
struct F_31 V_128 ;
if ( F_115 ( & V_128 , V_133 , sizeof( V_128 ) ) )
return - V_135 ;
return F_111 ( V_2 , & V_128 ) ;
}
case V_136 :
case V_137 : {
struct V_138 V_139 ;
if ( F_57 ( ! F_75 ( V_2 ) ) )
return - V_84 ;
if ( F_115 ( & V_139 , V_133 , sizeof( V_139 ) ) )
return - V_135 ;
if ( V_40 == V_136 )
return F_116 ( V_2 , & V_139 ) ;
else
return F_117 ( V_2 , & V_139 ) ;
}
case V_140 : {
struct V_141 T_8 * V_142 = V_133 ;
struct V_141 V_143 ;
unsigned V_144 ;
if ( F_57 ( ! F_75 ( V_2 ) ) )
return - V_84 ;
if ( F_115 ( & V_143 , V_142 , sizeof( V_143 ) ) )
return - V_135 ;
V_144 = V_143 . V_144 ;
V_143 . V_144 = F_118 ( V_2 ) ;
if ( F_119 ( V_142 , & V_143 , sizeof( V_143 ) ) )
return - V_135 ;
if ( V_144 < V_143 . V_144 )
return - V_145 ;
return F_120 ( V_2 , V_142 -> V_139 ) ;
}
default:
return - V_8 ;
}
}
int F_121 ( struct V_6 * V_6 , struct V_146 * log )
{
bool V_147 = false ;
int V_21 ;
F_122 ( & V_6 -> V_148 ) ;
V_21 = F_123 ( V_6 , log , & V_147 ) ;
if ( V_147 )
F_124 ( V_6 ) ;
F_125 ( & V_6 -> V_148 ) ;
return V_21 ;
}
static int F_126 ( struct V_6 * V_6 ,
struct V_149 * V_150 )
{
unsigned long V_151 , type ;
V_151 = ( V_150 -> V_42 & V_152 ) >>
V_153 ;
type = ( V_150 -> V_42 & V_154 ) >>
V_155 ;
switch ( V_151 ) {
case V_156 :
return F_127 ( V_6 , type , & V_150 -> V_157 , true ) ;
default:
return - V_158 ;
}
}
long F_128 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_6 * V_6 = V_39 -> V_132 ;
void T_8 * V_133 = ( void T_8 * ) V_41 ;
switch ( V_40 ) {
case V_159 : {
return F_129 ( V_6 , V_160 ) ;
}
case V_161 : {
struct V_149 V_150 ;
if ( F_115 ( & V_150 , V_133 , sizeof( V_150 ) ) )
return - V_135 ;
return F_126 ( V_6 , & V_150 ) ;
}
case V_162 : {
int V_43 ;
struct F_31 V_128 ;
V_43 = F_130 ( & V_128 ) ;
if ( V_43 )
return V_43 ;
if ( F_119 ( V_133 , & V_128 , sizeof( V_128 ) ) )
return - V_135 ;
return 0 ;
}
default:
return - V_8 ;
}
}
static void F_131 ( void * V_163 )
{
T_3 V_164 ;
T_3 V_165 ;
unsigned long V_166 ;
unsigned long V_167 ;
unsigned long V_168 ;
F_132 ( F_133 () ) ;
V_164 = F_134 () ;
V_165 = F_135 () ;
V_167 = F_6 ( V_169 ) ;
V_166 = V_167 + V_170 ;
V_168 = ( unsigned long ) V_171 ;
F_136 ( V_164 , V_165 , V_166 , V_168 ) ;
}
static int F_137 ( struct V_172 * V_173 ,
unsigned long V_174 , void * V_54 )
{
switch ( V_174 ) {
case V_175 :
case V_176 :
if ( F_138 () == V_177 )
F_131 ( NULL ) ;
break;
}
return V_178 ;
}
static int F_139 ( struct V_172 * V_173 ,
unsigned long V_179 ,
void * V_64 )
{
if ( V_179 == V_180 &&
F_138 () == V_177 ) {
F_131 ( NULL ) ;
return V_178 ;
}
return V_181 ;
}
static void T_9 F_140 ( void )
{
F_141 ( & V_182 ) ;
}
static inline void F_140 ( void )
{
}
static int F_142 ( void )
{
int V_54 ;
int V_43 = 0 ;
V_43 = F_143 () ;
if ( V_43 )
goto V_183;
V_177 = F_138 () ;
F_144 (cpu) {
unsigned long V_167 ;
V_167 = F_145 ( V_47 ) ;
if ( ! V_167 ) {
V_43 = - V_48 ;
goto V_184;
}
F_146 ( V_169 , V_54 ) = V_167 ;
}
V_43 = F_15 ( V_185 , V_186 ) ;
if ( V_43 ) {
F_147 ( L_1 ) ;
goto V_187;
}
F_144 (cpu) {
char * V_167 = ( char * ) F_146 ( V_169 , V_54 ) ;
V_43 = F_15 ( V_167 , V_167 + V_170 ) ;
if ( V_43 ) {
F_147 ( L_2 ) ;
goto V_187;
}
}
V_56 = F_148 ( V_188 ) ;
if ( ! V_56 ) {
V_43 = - V_48 ;
F_147 ( L_3 ) ;
goto V_187;
}
F_144 (cpu) {
V_188 * V_189 ;
V_189 = F_149 ( V_56 , V_54 ) ;
V_43 = F_15 ( V_189 , V_189 + 1 ) ;
if ( V_43 ) {
F_147 ( L_4 , V_43 ) ;
goto V_190;
}
}
F_150 ( F_131 , NULL , 1 ) ;
V_43 = F_151 () ;
if ( V_43 )
goto V_190;
V_43 = F_152 () ;
if ( V_43 )
goto V_187;
#ifndef F_153
F_154 () ;
#endif
F_155 () ;
F_156 ( L_5 ) ;
return 0 ;
V_190:
F_157 ( V_56 ) ;
V_187:
F_158 () ;
V_184:
F_144 (cpu)
F_159 ( F_146 ( V_169 , V_54 ) ) ;
V_183:
F_147 ( L_6 , V_43 ) ;
return V_43 ;
}
static void F_160 ( void * V_7 )
{
* ( int * ) V_7 = F_107 () ;
}
struct V_1 * F_161 ( struct V_6 * V_6 , unsigned long V_191 )
{
struct V_1 * V_2 ;
int V_17 ;
V_191 &= V_192 ;
F_162 (i, vcpu, kvm) {
if ( V_191 == F_163 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_164 ( void * V_193 )
{
int V_43 ;
int V_7 , V_54 ;
if ( ! F_165 () ) {
F_147 ( L_7 ) ;
return - V_158 ;
}
F_166 (cpu) {
F_167 ( V_54 , F_160 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_147 ( L_8 , V_54 ) ;
return - V_158 ;
}
}
F_168 () ;
V_43 = F_142 () ;
if ( V_43 )
goto V_183;
V_43 = F_169 ( & V_194 ) ;
if ( V_43 ) {
F_147 ( L_9 , V_43 ) ;
goto V_183;
}
F_170 () ;
F_140 () ;
F_171 () ;
return 0 ;
V_183:
F_170 () ;
return V_43 ;
}
void F_172 ( void )
{
F_173 () ;
}
static int F_174 ( void )
{
int V_195 = F_175 ( NULL , sizeof( struct V_1 ) , 0 , V_196 ) ;
return V_195 ;
}
