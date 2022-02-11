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
F_17 ( V_6 ) ;
V_6 -> V_11 . V_12 = 0 ;
V_6 -> V_11 . V_13 = F_18 () ;
return V_7 ;
V_10:
F_19 ( V_6 ) ;
V_9:
return V_7 ;
}
int F_20 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
return V_16 ;
}
void F_21 ( struct V_6 * V_6 )
{
int V_17 ;
F_19 ( V_6 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; ++ V_17 ) {
if ( V_6 -> V_19 [ V_17 ] ) {
F_22 ( V_6 -> V_19 [ V_17 ] ) ;
V_6 -> V_19 [ V_17 ] = NULL ;
}
}
F_23 ( V_6 ) ;
}
int F_24 ( struct V_6 * V_6 , long V_20 )
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
V_21 = F_25 () ;
break;
case V_37 :
V_21 = V_18 ;
break;
default:
V_21 = F_26 ( V_20 ) ;
break;
}
return V_21 ;
}
long F_27 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
return - V_8 ;
}
struct V_1 * F_28 ( struct V_6 * V_6 , unsigned int V_42 )
{
int V_43 ;
struct V_1 * V_2 ;
if ( F_29 ( V_6 ) && F_30 ( V_6 ) ) {
V_43 = - V_44 ;
goto V_45;
}
if ( V_42 >= V_6 -> V_11 . V_13 ) {
V_43 = - V_8 ;
goto V_45;
}
V_2 = F_31 ( V_46 , V_47 ) ;
if ( ! V_2 ) {
V_43 = - V_48 ;
goto V_45;
}
V_43 = F_32 ( V_2 , V_6 , V_42 ) ;
if ( V_43 )
goto V_49;
V_43 = F_15 ( V_2 , V_2 + 1 ) ;
if ( V_43 )
goto V_50;
return V_2 ;
V_50:
F_33 ( V_2 ) ;
V_49:
F_34 ( V_46 , V_2 ) ;
V_45:
return F_35 ( V_43 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 ( V_2 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_34 ( V_46 , V_2 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
}
int F_42 ( struct V_1 * V_2 )
{
return F_43 ( V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 ) ;
}
int F_48 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_51 = - 1 ;
F_49 ( V_2 -> V_11 . V_52 , V_53 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 , int V_54 )
{
V_2 -> V_54 = V_54 ;
V_2 -> V_11 . V_55 = F_53 ( V_56 ) ;
F_1 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
V_2 -> V_54 = - 1 ;
F_1 ( NULL ) ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
if ( V_2 -> V_11 . V_59 )
V_58 -> V_58 = V_60 ;
else
V_58 -> V_58 = V_61 ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
switch ( V_58 -> V_58 ) {
case V_61 :
V_2 -> V_11 . V_59 = false ;
break;
case V_60 :
V_2 -> V_11 . V_59 = true ;
break;
default:
return - V_8 ;
}
return 0 ;
}
int F_57 ( struct V_1 * V_62 )
{
return ( ( ! ! V_62 -> V_11 . V_63 || F_58 ( V_62 ) )
&& ! V_62 -> V_11 . V_59 && ! V_62 -> V_11 . V_64 ) ;
}
static void F_59 ( void * V_65 )
{
}
void F_60 ( const T_2 * V_66 )
{
F_61 ( V_66 , F_59 , NULL , true ) ;
}
static bool F_62 ( struct V_6 * V_6 )
{
return F_63 ( V_6 -> V_11 . V_12 != F_64 ( & V_67 ) ) ;
}
static void F_65 ( struct V_6 * V_6 )
{
T_3 V_68 ;
T_4 V_69 ;
if ( ! F_62 ( V_6 ) )
return;
F_66 ( & V_70 ) ;
if ( ! F_62 ( V_6 ) ) {
F_67 ( & V_70 ) ;
return;
}
if ( F_63 ( V_71 == 0 ) ) {
F_68 ( & V_67 ) ;
V_71 = 1 ;
F_60 ( V_72 ) ;
F_69 ( V_73 ) ;
}
V_6 -> V_11 . V_12 = F_64 ( & V_67 ) ;
V_6 -> V_11 . V_69 = V_71 ;
V_71 ++ ;
V_68 = F_70 ( F_71 ( V_6 ) ) ;
F_2 ( V_68 & ~ V_74 ) ;
V_69 = ( ( T_4 ) ( V_6 -> V_11 . V_69 ) << V_75 ) & V_76 ;
V_6 -> V_11 . V_77 = V_68 | V_69 ;
F_67 ( & V_70 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 ;
if ( F_73 ( V_2 -> V_11 . V_78 ) )
return 0 ;
V_2 -> V_11 . V_78 = true ;
if ( F_63 ( F_29 ( V_6 ) && ! F_74 ( V_6 ) ) ) {
V_7 = F_75 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
if ( F_29 ( V_6 ) && F_30 ( V_6 ) )
F_76 ( V_6 ) ;
return 0 ;
}
bool F_77 ( struct V_6 * V_6 )
{
return F_30 ( V_6 ) ;
}
static void F_78 ( struct V_6 * V_6 )
{
int V_17 ;
struct V_1 * V_2 ;
F_79 (i, vcpu, kvm)
V_2 -> V_11 . V_64 = true ;
F_60 ( V_72 ) ;
}
static void F_80 ( struct V_6 * V_6 )
{
int V_17 ;
struct V_1 * V_2 ;
F_79 (i, vcpu, kvm) {
T_5 * V_79 = F_81 ( V_2 ) ;
V_2 -> V_11 . V_64 = false ;
F_82 ( V_79 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
T_5 * V_79 = F_81 ( V_2 ) ;
F_84 ( * V_79 , ( ( ! V_2 -> V_11 . V_59 ) &&
( ! V_2 -> V_11 . V_64 ) ) ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
return V_2 -> V_11 . V_51 >= 0 ;
}
int F_86 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
int V_7 ;
T_6 V_82 ;
if ( F_63 ( ! F_85 ( V_2 ) ) )
return - V_83 ;
V_7 = F_72 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_81 -> V_84 == V_85 ) {
V_7 = F_87 ( V_2 , V_2 -> V_81 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_86 )
F_88 ( V_87 , & V_2 -> V_88 , & V_82 ) ;
V_7 = 1 ;
V_81 -> V_84 = V_89 ;
while ( V_7 > 0 ) {
F_89 () ;
F_65 ( V_2 -> V_6 ) ;
if ( V_2 -> V_11 . V_59 || V_2 -> V_11 . V_64 )
F_83 ( V_2 ) ;
F_90 () ;
F_91 ( V_2 ) ;
F_92 ( V_2 ) ;
F_93 () ;
if ( F_94 ( V_90 ) ) {
V_7 = - V_91 ;
V_81 -> V_84 = V_92 ;
}
if ( V_7 <= 0 || F_62 ( V_2 -> V_6 ) ||
V_2 -> V_11 . V_59 || V_2 -> V_11 . V_64 ) {
F_95 () ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
F_98 () ;
continue;
}
F_99 ( V_2 ) ;
F_100 ( * F_101 ( V_2 ) ) ;
F_102 () ;
V_2 -> V_93 = V_4 ;
V_7 = F_69 ( V_94 , V_2 ) ;
V_2 -> V_93 = V_95 ;
F_103 ( V_2 ) ;
F_95 () ;
F_104 () ;
F_105 ( V_7 , F_106 ( V_2 ) , * F_101 ( V_2 ) ) ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
F_98 () ;
V_7 = F_107 ( V_2 , V_81 , V_7 ) ;
}
if ( V_2 -> V_86 )
F_88 ( V_87 , & V_82 , NULL ) ;
return V_7 ;
}
static int F_108 ( struct V_1 * V_2 , int V_96 , bool V_97 )
{
int V_98 ;
bool V_99 ;
unsigned long * V_100 ;
if ( V_96 == V_101 )
V_98 = F_109 ( V_102 ) ;
else
V_98 = F_109 ( V_103 ) ;
V_100 = ( unsigned long * ) & V_2 -> V_11 . V_63 ;
if ( V_97 )
V_99 = F_110 ( V_98 , V_100 ) ;
else
V_99 = F_111 ( V_98 , V_100 ) ;
if ( V_99 == V_97 )
return 0 ;
F_112 ( V_2 ) ;
return 0 ;
}
int F_113 ( struct V_6 * V_6 , struct V_104 * V_105 ,
bool V_106 )
{
T_7 V_107 = V_105 -> V_107 ;
unsigned int V_108 , V_109 , V_110 ;
int V_111 = F_114 ( & V_6 -> V_112 ) ;
struct V_1 * V_2 = NULL ;
bool V_97 = V_105 -> V_97 ;
V_108 = ( V_107 >> V_113 ) & V_114 ;
V_109 = ( V_107 >> V_115 ) & V_116 ;
V_110 = ( V_107 >> V_117 ) & V_118 ;
F_115 ( V_108 , V_109 , V_110 , V_105 -> V_97 ) ;
switch ( V_108 ) {
case V_119 :
if ( F_29 ( V_6 ) )
return - V_120 ;
if ( V_109 >= V_111 )
return - V_8 ;
V_2 = F_116 ( V_6 , V_109 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_110 > V_121 )
return - V_8 ;
return F_108 ( V_2 , V_110 , V_97 ) ;
case V_122 :
if ( ! F_29 ( V_6 ) )
return - V_120 ;
if ( V_109 >= V_111 )
return - V_8 ;
V_2 = F_116 ( V_6 , V_109 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_110 < V_123 || V_110 >= V_124 )
return - V_8 ;
return F_117 ( V_6 , V_2 -> V_125 , V_110 , V_97 ) ;
case V_126 :
if ( ! F_29 ( V_6 ) )
return - V_120 ;
if ( V_110 < V_124 )
return - V_8 ;
return F_117 ( V_6 , 0 , V_110 , V_97 ) ;
}
return - V_8 ;
}
static int F_118 ( struct V_1 * V_2 ,
const struct F_32 * V_127 )
{
unsigned int V_17 ;
int V_128 = F_119 () ;
if ( V_127 -> V_51 != V_128 )
return - V_8 ;
if ( V_2 -> V_11 . V_51 != - 1 && V_2 -> V_11 . V_51 != V_127 -> V_51 )
return - V_8 ;
for ( V_17 = 0 ; V_17 < sizeof( V_127 -> V_52 ) * 8 ; V_17 ++ ) {
bool V_99 = ( V_127 -> V_52 [ V_17 / 32 ] & ( 1 << ( V_17 % 32 ) ) ) ;
if ( V_99 && V_17 >= V_53 )
return - V_129 ;
if ( V_2 -> V_11 . V_51 != - 1 && V_17 < V_53 &&
F_120 ( V_17 , V_2 -> V_11 . V_52 ) != V_99 )
return - V_8 ;
if ( V_99 )
F_121 ( V_17 , V_2 -> V_11 . V_52 ) ;
}
V_2 -> V_11 . V_51 = V_128 ;
return F_122 ( V_2 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct F_32 * V_127 )
{
int V_7 ;
V_7 = F_118 ( V_2 , V_127 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_11 . V_78 )
F_124 ( V_2 -> V_6 ) ;
F_125 ( V_2 ) ;
if ( F_120 ( V_130 , V_2 -> V_11 . V_52 ) )
V_2 -> V_11 . V_59 = true ;
else
V_2 -> V_11 . V_59 = false ;
return 0 ;
}
long F_126 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_1 * V_2 = V_39 -> V_131 ;
void T_8 * V_132 = ( void T_8 * ) V_41 ;
switch ( V_40 ) {
case V_133 : {
struct F_32 V_127 ;
if ( F_127 ( & V_127 , V_132 , sizeof( V_127 ) ) )
return - V_134 ;
return F_123 ( V_2 , & V_127 ) ;
}
case V_135 :
case V_136 : {
struct V_137 V_138 ;
if ( F_63 ( ! F_85 ( V_2 ) ) )
return - V_83 ;
if ( F_127 ( & V_138 , V_132 , sizeof( V_138 ) ) )
return - V_134 ;
if ( V_40 == V_135 )
return F_128 ( V_2 , & V_138 ) ;
else
return F_129 ( V_2 , & V_138 ) ;
}
case V_139 : {
struct V_140 T_8 * V_141 = V_132 ;
struct V_140 V_142 ;
unsigned V_143 ;
if ( F_63 ( ! F_85 ( V_2 ) ) )
return - V_83 ;
if ( F_127 ( & V_142 , V_141 , sizeof( V_142 ) ) )
return - V_134 ;
V_143 = V_142 . V_143 ;
V_142 . V_143 = F_130 ( V_2 ) ;
if ( F_131 ( V_141 , & V_142 , sizeof( V_142 ) ) )
return - V_134 ;
if ( V_143 < V_142 . V_143 )
return - V_144 ;
return F_132 ( V_2 , V_141 -> V_138 ) ;
}
default:
return - V_8 ;
}
}
int F_133 ( struct V_6 * V_6 , struct V_145 * log )
{
bool V_146 = false ;
int V_21 ;
F_134 ( & V_6 -> V_147 ) ;
V_21 = F_135 ( V_6 , log , & V_146 ) ;
if ( V_146 )
F_136 ( V_6 ) ;
F_137 ( & V_6 -> V_147 ) ;
return V_21 ;
}
static int F_138 ( struct V_6 * V_6 ,
struct V_148 * V_149 )
{
unsigned long V_150 , type ;
V_150 = ( V_149 -> V_42 & V_151 ) >>
V_152 ;
type = ( V_149 -> V_42 & V_153 ) >>
V_154 ;
switch ( V_150 ) {
case V_155 :
return F_139 ( V_6 , type , & V_149 -> V_156 , true ) ;
default:
return - V_157 ;
}
}
long F_140 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_6 * V_6 = V_39 -> V_131 ;
void T_8 * V_132 = ( void T_8 * ) V_41 ;
switch ( V_40 ) {
case V_158 : {
return F_141 ( V_6 , V_159 ) ;
}
case V_160 : {
struct V_148 V_149 ;
if ( F_127 ( & V_149 , V_132 , sizeof( V_149 ) ) )
return - V_134 ;
return F_138 ( V_6 , & V_149 ) ;
}
case V_161 : {
int V_43 ;
struct F_32 V_127 ;
V_43 = F_142 ( & V_127 ) ;
if ( V_43 )
return V_43 ;
if ( F_131 ( V_132 , & V_127 , sizeof( V_127 ) ) )
return - V_134 ;
return 0 ;
}
default:
return - V_8 ;
}
}
static void F_143 ( void * V_162 )
{
T_3 V_163 ;
T_3 V_164 ;
unsigned long V_165 ;
unsigned long V_166 ;
unsigned long V_167 ;
F_144 ( F_145 () ) ;
V_163 = F_146 () ;
V_164 = F_147 () ;
V_166 = F_6 ( V_168 ) ;
V_165 = V_166 + V_169 ;
V_167 = ( unsigned long ) V_170 ;
F_148 ( V_163 , V_164 , V_165 , V_167 ) ;
F_149 () ;
}
static int F_150 ( struct V_171 * V_172 ,
unsigned long V_173 , void * V_54 )
{
switch ( V_173 ) {
case V_174 :
case V_175 :
if ( F_151 () == V_176 )
F_143 ( NULL ) ;
break;
}
return V_177 ;
}
static int F_152 ( struct V_171 * V_172 ,
unsigned long V_178 ,
void * V_62 )
{
if ( V_178 == V_179 &&
F_151 () == V_176 ) {
F_143 ( NULL ) ;
return V_177 ;
}
return V_180 ;
}
static void T_9 F_153 ( void )
{
F_154 ( & V_181 ) ;
}
static inline void F_153 ( void )
{
}
static int F_155 ( void )
{
int V_54 ;
int V_43 = 0 ;
V_43 = F_156 () ;
if ( V_43 )
goto V_182;
V_176 = F_151 () ;
F_157 (cpu) {
unsigned long V_166 ;
V_166 = F_158 ( V_47 ) ;
if ( ! V_166 ) {
V_43 = - V_48 ;
goto V_183;
}
F_159 ( V_168 , V_54 ) = V_166 ;
}
V_43 = F_15 ( V_184 , V_185 ) ;
if ( V_43 ) {
F_160 ( L_1 ) ;
goto V_186;
}
F_157 (cpu) {
char * V_166 = ( char * ) F_159 ( V_168 , V_54 ) ;
V_43 = F_15 ( V_166 , V_166 + V_169 ) ;
if ( V_43 ) {
F_160 ( L_2 ) ;
goto V_186;
}
}
V_56 = F_161 ( V_187 ) ;
if ( ! V_56 ) {
V_43 = - V_48 ;
F_160 ( L_3 ) ;
goto V_186;
}
F_157 (cpu) {
V_187 * V_188 ;
V_188 = F_162 ( V_56 , V_54 ) ;
V_43 = F_15 ( V_188 , V_188 + 1 ) ;
if ( V_43 ) {
F_160 ( L_4 , V_43 ) ;
goto V_189;
}
}
F_163 ( F_143 , NULL , 1 ) ;
V_43 = F_164 () ;
if ( V_43 )
goto V_189;
V_43 = F_165 () ;
if ( V_43 )
goto V_189;
#ifndef F_166
F_167 () ;
#endif
F_168 () ;
F_169 ( L_5 ) ;
return 0 ;
V_189:
F_170 ( V_56 ) ;
V_186:
F_171 () ;
V_183:
F_157 (cpu)
F_172 ( F_159 ( V_168 , V_54 ) ) ;
V_182:
F_160 ( L_6 , V_43 ) ;
return V_43 ;
}
static void F_173 ( void * V_7 )
{
* ( int * ) V_7 = F_119 () ;
}
struct V_1 * F_174 ( struct V_6 * V_6 , unsigned long V_190 )
{
struct V_1 * V_2 ;
int V_17 ;
V_190 &= V_191 ;
F_79 (i, vcpu, kvm) {
if ( V_190 == F_175 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_176 ( void * V_192 )
{
int V_43 ;
int V_7 , V_54 ;
if ( ! F_177 () ) {
F_160 ( L_7 ) ;
return - V_157 ;
}
F_178 (cpu) {
F_179 ( V_54 , F_173 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_160 ( L_8 , V_54 ) ;
return - V_157 ;
}
}
F_180 () ;
V_43 = F_155 () ;
if ( V_43 )
goto V_182;
V_43 = F_181 ( & V_193 ) ;
if ( V_43 ) {
F_160 ( L_9 , V_43 ) ;
goto V_182;
}
F_182 () ;
F_153 () ;
F_183 () ;
return 0 ;
V_182:
F_182 () ;
return V_43 ;
}
void F_184 ( void )
{
F_185 () ;
}
static int F_186 ( void )
{
int V_194 = F_187 ( NULL , sizeof( struct V_1 ) , 0 , V_195 ) ;
return V_194 ;
}
