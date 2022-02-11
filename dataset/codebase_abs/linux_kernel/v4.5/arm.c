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
V_6 -> V_11 . V_13 = V_14 ?
F_18 () : V_15 ;
return V_7 ;
V_10:
F_19 ( V_6 ) ;
V_9:
return V_7 ;
}
int F_20 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
return V_18 ;
}
void F_21 ( struct V_6 * V_6 )
{
int V_19 ;
F_19 ( V_6 ) ;
for ( V_19 = 0 ; V_19 < V_15 ; ++ V_19 ) {
if ( V_6 -> V_20 [ V_19 ] ) {
F_22 ( V_6 -> V_20 [ V_19 ] ) ;
V_6 -> V_20 [ V_19 ] = NULL ;
}
}
F_23 ( V_6 ) ;
}
int F_24 ( struct V_6 * V_6 , long V_21 )
{
int V_22 ;
switch ( V_21 ) {
case V_23 :
V_22 = V_14 ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
V_22 = 1 ;
break;
case V_34 :
V_22 = V_35 ;
break;
case V_36 :
V_22 = 1 ;
break;
case V_37 :
V_22 = F_25 () ;
break;
case V_38 :
V_22 = V_15 ;
break;
default:
V_22 = F_26 ( V_21 ) ;
break;
}
return V_22 ;
}
long F_27 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
return - V_8 ;
}
struct V_1 * F_28 ( struct V_6 * V_6 , unsigned int V_43 )
{
int V_44 ;
struct V_1 * V_2 ;
if ( F_29 ( V_6 ) && F_30 ( V_6 ) ) {
V_44 = - V_45 ;
goto V_46;
}
if ( V_43 >= V_6 -> V_11 . V_13 ) {
V_44 = - V_8 ;
goto V_46;
}
V_2 = F_31 ( V_47 , V_48 ) ;
if ( ! V_2 ) {
V_44 = - V_49 ;
goto V_46;
}
V_44 = F_32 ( V_2 , V_6 , V_43 ) ;
if ( V_44 )
goto V_50;
V_44 = F_15 ( V_2 , V_2 + 1 ) ;
if ( V_44 )
goto V_51;
return V_2 ;
V_51:
F_33 ( V_2 ) ;
V_50:
F_34 ( V_47 , V_2 ) ;
V_46:
return F_35 ( V_44 ) ;
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
F_34 ( V_47 , V_2 ) ;
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
V_2 -> V_11 . V_52 = - 1 ;
F_49 ( V_2 -> V_11 . V_53 , V_54 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 , int V_55 )
{
V_2 -> V_55 = V_55 ;
V_2 -> V_11 . V_56 = F_53 ( V_57 ) ;
F_1 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
V_2 -> V_55 = - 1 ;
F_1 ( NULL ) ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
if ( V_2 -> V_11 . V_60 )
V_59 -> V_59 = V_61 ;
else
V_59 -> V_59 = V_62 ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
switch ( V_59 -> V_59 ) {
case V_62 :
V_2 -> V_11 . V_60 = false ;
break;
case V_61 :
V_2 -> V_11 . V_60 = true ;
break;
default:
return - V_8 ;
}
return 0 ;
}
int F_57 ( struct V_1 * V_63 )
{
return ( ( ! ! V_63 -> V_11 . V_64 || F_58 ( V_63 ) )
&& ! V_63 -> V_11 . V_60 && ! V_63 -> V_11 . V_65 ) ;
}
static void F_59 ( void * V_66 )
{
}
void F_60 ( const T_2 * V_67 )
{
F_61 ( V_67 , F_59 , NULL , true ) ;
}
static bool F_62 ( struct V_6 * V_6 )
{
return F_63 ( V_6 -> V_11 . V_12 != F_64 ( & V_68 ) ) ;
}
static void F_65 ( struct V_6 * V_6 )
{
T_3 V_69 ;
T_4 V_70 ;
if ( ! F_62 ( V_6 ) )
return;
F_66 ( & V_71 ) ;
if ( ! F_62 ( V_6 ) ) {
F_67 ( & V_71 ) ;
return;
}
if ( F_63 ( V_72 == 0 ) ) {
F_68 ( & V_68 ) ;
V_72 = 1 ;
F_60 ( V_73 ) ;
F_69 ( V_74 ) ;
}
V_6 -> V_11 . V_12 = F_64 ( & V_68 ) ;
V_6 -> V_11 . V_70 = V_72 ;
V_72 ++ ;
V_72 &= ( 1 << V_75 ) - 1 ;
V_69 = F_70 ( F_71 ( V_6 ) ) ;
F_2 ( V_69 & ~ V_76 ) ;
V_70 = ( ( T_4 ) ( V_6 -> V_11 . V_70 ) << V_77 ) & F_72 ( V_75 ) ;
V_6 -> V_11 . V_78 = V_69 | V_70 ;
F_67 ( & V_71 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 ;
if ( F_74 ( V_2 -> V_11 . V_79 ) )
return 0 ;
V_2 -> V_11 . V_79 = true ;
if ( F_63 ( F_29 ( V_6 ) && ! F_75 ( V_6 ) ) ) {
V_7 = F_76 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
if ( F_29 ( V_6 ) && F_30 ( V_6 ) )
F_77 ( V_6 ) ;
return 0 ;
}
bool F_78 ( struct V_6 * V_6 )
{
return F_30 ( V_6 ) ;
}
static void F_79 ( struct V_6 * V_6 )
{
int V_19 ;
struct V_1 * V_2 ;
F_80 (i, vcpu, kvm)
V_2 -> V_11 . V_65 = true ;
F_60 ( V_73 ) ;
}
static void F_81 ( struct V_6 * V_6 )
{
int V_19 ;
struct V_1 * V_2 ;
F_80 (i, vcpu, kvm) {
T_5 * V_80 = F_82 ( V_2 ) ;
V_2 -> V_11 . V_65 = false ;
F_83 ( V_80 ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
T_5 * V_80 = F_82 ( V_2 ) ;
F_85 ( * V_80 , ( ( ! V_2 -> V_11 . V_60 ) &&
( ! V_2 -> V_11 . V_65 ) ) ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
return V_2 -> V_11 . V_52 >= 0 ;
}
int F_87 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
int V_7 ;
T_6 V_83 ;
if ( F_63 ( ! F_86 ( V_2 ) ) )
return - V_84 ;
V_7 = F_73 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_82 -> V_85 == V_86 ) {
V_7 = F_88 ( V_2 , V_2 -> V_82 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_87 )
F_89 ( V_88 , & V_2 -> V_89 , & V_83 ) ;
V_7 = 1 ;
V_82 -> V_85 = V_90 ;
while ( V_7 > 0 ) {
F_90 () ;
F_65 ( V_2 -> V_6 ) ;
if ( V_2 -> V_11 . V_60 || V_2 -> V_11 . V_65 )
F_84 ( V_2 ) ;
F_91 () ;
F_92 ( V_2 ) ;
F_93 ( V_2 ) ;
F_94 () ;
if ( F_95 ( V_91 ) ) {
V_7 = - V_92 ;
V_82 -> V_85 = V_93 ;
}
if ( V_7 <= 0 || F_62 ( V_2 -> V_6 ) ||
V_2 -> V_11 . V_60 || V_2 -> V_11 . V_65 ) {
F_96 () ;
F_97 ( V_2 ) ;
F_98 ( V_2 ) ;
F_99 () ;
continue;
}
F_100 ( V_2 ) ;
F_101 ( * F_102 ( V_2 ) ) ;
F_103 () ;
V_2 -> V_94 = V_4 ;
V_7 = F_69 ( V_95 , V_2 ) ;
V_2 -> V_94 = V_96 ;
V_2 -> V_97 . V_98 ++ ;
F_104 ( V_2 ) ;
F_96 () ;
F_105 () ;
F_106 ( V_7 , F_107 ( V_2 ) , * F_102 ( V_2 ) ) ;
F_97 ( V_2 ) ;
F_98 ( V_2 ) ;
F_99 () ;
V_7 = F_108 ( V_2 , V_82 , V_7 ) ;
}
if ( V_2 -> V_87 )
F_89 ( V_88 , & V_83 , NULL ) ;
return V_7 ;
}
static int F_109 ( struct V_1 * V_2 , int V_99 , bool V_100 )
{
int V_101 ;
bool V_102 ;
unsigned long * V_103 ;
if ( V_99 == V_104 )
V_101 = F_110 ( V_105 ) ;
else
V_101 = F_110 ( V_106 ) ;
V_103 = ( unsigned long * ) & V_2 -> V_11 . V_64 ;
if ( V_100 )
V_102 = F_111 ( V_101 , V_103 ) ;
else
V_102 = F_112 ( V_101 , V_103 ) ;
if ( V_102 == V_100 )
return 0 ;
F_113 ( V_2 ) ;
return 0 ;
}
int F_114 ( struct V_6 * V_6 , struct V_107 * V_108 ,
bool V_109 )
{
T_7 V_110 = V_108 -> V_110 ;
unsigned int V_111 , V_112 , V_113 ;
int V_114 = F_115 ( & V_6 -> V_115 ) ;
struct V_1 * V_2 = NULL ;
bool V_100 = V_108 -> V_100 ;
V_111 = ( V_110 >> V_116 ) & V_117 ;
V_112 = ( V_110 >> V_118 ) & V_119 ;
V_113 = ( V_110 >> V_120 ) & V_121 ;
F_116 ( V_111 , V_112 , V_113 , V_108 -> V_100 ) ;
switch ( V_111 ) {
case V_122 :
if ( F_29 ( V_6 ) )
return - V_123 ;
if ( V_112 >= V_114 )
return - V_8 ;
V_2 = F_117 ( V_6 , V_112 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_113 > V_124 )
return - V_8 ;
return F_109 ( V_2 , V_113 , V_100 ) ;
case V_125 :
if ( ! F_29 ( V_6 ) )
return - V_123 ;
if ( V_112 >= V_114 )
return - V_8 ;
V_2 = F_117 ( V_6 , V_112 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_113 < V_126 || V_113 >= V_127 )
return - V_8 ;
return F_118 ( V_6 , V_2 -> V_128 , V_113 , V_100 ) ;
case V_129 :
if ( ! F_29 ( V_6 ) )
return - V_123 ;
if ( V_113 < V_127 )
return - V_8 ;
return F_118 ( V_6 , 0 , V_113 , V_100 ) ;
}
return - V_8 ;
}
static int F_119 ( struct V_1 * V_2 ,
const struct F_32 * V_130 )
{
unsigned int V_19 ;
int V_131 = F_120 () ;
if ( V_130 -> V_52 != V_131 )
return - V_8 ;
if ( V_2 -> V_11 . V_52 != - 1 && V_2 -> V_11 . V_52 != V_130 -> V_52 )
return - V_8 ;
for ( V_19 = 0 ; V_19 < sizeof( V_130 -> V_53 ) * 8 ; V_19 ++ ) {
bool V_102 = ( V_130 -> V_53 [ V_19 / 32 ] & ( 1 << ( V_19 % 32 ) ) ) ;
if ( V_102 && V_19 >= V_54 )
return - V_132 ;
if ( V_2 -> V_11 . V_52 != - 1 && V_19 < V_54 &&
F_121 ( V_19 , V_2 -> V_11 . V_53 ) != V_102 )
return - V_8 ;
if ( V_102 )
F_122 ( V_19 , V_2 -> V_11 . V_53 ) ;
}
V_2 -> V_11 . V_52 = V_131 ;
return F_123 ( V_2 ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct F_32 * V_130 )
{
int V_7 ;
V_7 = F_119 ( V_2 , V_130 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_11 . V_79 )
F_125 ( V_2 -> V_6 ) ;
F_126 ( V_2 ) ;
if ( F_121 ( V_133 , V_2 -> V_11 . V_53 ) )
V_2 -> V_11 . V_60 = true ;
else
V_2 -> V_11 . V_60 = false ;
return 0 ;
}
long F_127 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_1 * V_2 = V_40 -> V_134 ;
void T_8 * V_135 = ( void T_8 * ) V_42 ;
switch ( V_41 ) {
case V_136 : {
struct F_32 V_130 ;
if ( F_128 ( & V_130 , V_135 , sizeof( V_130 ) ) )
return - V_137 ;
return F_124 ( V_2 , & V_130 ) ;
}
case V_138 :
case V_139 : {
struct V_140 V_141 ;
if ( F_63 ( ! F_86 ( V_2 ) ) )
return - V_84 ;
if ( F_128 ( & V_141 , V_135 , sizeof( V_141 ) ) )
return - V_137 ;
if ( V_41 == V_138 )
return F_129 ( V_2 , & V_141 ) ;
else
return F_130 ( V_2 , & V_141 ) ;
}
case V_142 : {
struct V_143 T_8 * V_144 = V_135 ;
struct V_143 V_145 ;
unsigned V_146 ;
if ( F_63 ( ! F_86 ( V_2 ) ) )
return - V_84 ;
if ( F_128 ( & V_145 , V_144 , sizeof( V_145 ) ) )
return - V_137 ;
V_146 = V_145 . V_146 ;
V_145 . V_146 = F_131 ( V_2 ) ;
if ( F_132 ( V_144 , & V_145 , sizeof( V_145 ) ) )
return - V_137 ;
if ( V_146 < V_145 . V_146 )
return - V_147 ;
return F_133 ( V_2 , V_144 -> V_141 ) ;
}
default:
return - V_8 ;
}
}
int F_134 ( struct V_6 * V_6 , struct V_148 * log )
{
bool V_149 = false ;
int V_22 ;
F_135 ( & V_6 -> V_150 ) ;
V_22 = F_136 ( V_6 , log , & V_149 ) ;
if ( V_149 )
F_137 ( V_6 ) ;
F_138 ( & V_6 -> V_150 ) ;
return V_22 ;
}
static int F_139 ( struct V_6 * V_6 ,
struct V_151 * V_152 )
{
unsigned long V_153 , type ;
V_153 = ( V_152 -> V_43 & V_154 ) >>
V_155 ;
type = ( V_152 -> V_43 & V_156 ) >>
V_157 ;
switch ( V_153 ) {
case V_158 :
if ( ! V_14 )
return - V_123 ;
return F_140 ( V_6 , type , & V_152 -> V_159 , true ) ;
default:
return - V_160 ;
}
}
long F_141 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_6 * V_6 = V_40 -> V_134 ;
void T_8 * V_135 = ( void T_8 * ) V_42 ;
switch ( V_41 ) {
case V_161 : {
if ( ! V_14 )
return - V_123 ;
return F_142 ( V_6 , V_162 ) ;
}
case V_163 : {
struct V_151 V_152 ;
if ( F_128 ( & V_152 , V_135 , sizeof( V_152 ) ) )
return - V_137 ;
return F_139 ( V_6 , & V_152 ) ;
}
case V_164 : {
int V_44 ;
struct F_32 V_130 ;
V_44 = F_143 ( & V_130 ) ;
if ( V_44 )
return V_44 ;
if ( F_132 ( V_135 , & V_130 , sizeof( V_130 ) ) )
return - V_137 ;
return 0 ;
}
default:
return - V_8 ;
}
}
static void F_144 ( void * V_165 )
{
T_3 V_166 ;
T_3 V_167 ;
unsigned long V_168 ;
unsigned long V_169 ;
unsigned long V_170 ;
F_145 ( F_146 () ) ;
V_166 = F_147 () ;
V_167 = F_148 () ;
V_169 = F_6 ( V_171 ) ;
V_168 = V_169 + V_172 ;
V_170 = ( unsigned long ) V_173 ;
F_149 ( V_166 , V_167 , V_168 , V_170 ) ;
F_150 () ;
}
static int F_151 ( struct V_174 * V_175 ,
unsigned long V_176 , void * V_55 )
{
switch ( V_176 ) {
case V_177 :
case V_178 :
if ( F_152 () == V_179 )
F_144 ( NULL ) ;
break;
}
return V_180 ;
}
static int F_153 ( struct V_174 * V_175 ,
unsigned long V_181 ,
void * V_63 )
{
if ( V_181 == V_182 &&
F_152 () == V_179 ) {
F_144 ( NULL ) ;
return V_180 ;
}
return V_183 ;
}
static void T_9 F_154 ( void )
{
F_155 ( & V_184 ) ;
}
static inline void F_154 ( void )
{
}
static int F_156 ( void )
{
int V_55 ;
int V_44 = 0 ;
V_44 = F_157 () ;
if ( V_44 )
goto V_185;
V_179 = F_152 () ;
F_158 (cpu) {
unsigned long V_169 ;
V_169 = F_159 ( V_48 ) ;
if ( ! V_169 ) {
V_44 = - V_49 ;
goto V_186;
}
F_160 ( V_171 , V_55 ) = V_169 ;
}
V_44 = F_15 ( V_187 , V_188 ) ;
if ( V_44 ) {
F_161 ( L_1 ) ;
goto V_189;
}
V_44 = F_15 ( V_190 , V_191 ) ;
if ( V_44 ) {
F_161 ( L_2 ) ;
goto V_189;
}
F_158 (cpu) {
char * V_169 = ( char * ) F_160 ( V_171 , V_55 ) ;
V_44 = F_15 ( V_169 , V_169 + V_172 ) ;
if ( V_44 ) {
F_161 ( L_3 ) ;
goto V_189;
}
}
V_57 = F_162 ( V_192 ) ;
if ( ! V_57 ) {
V_44 = - V_49 ;
F_161 ( L_4 ) ;
goto V_189;
}
F_158 (cpu) {
V_192 * V_193 ;
V_193 = F_163 ( V_57 , V_55 ) ;
V_44 = F_15 ( V_193 , V_193 + 1 ) ;
if ( V_44 ) {
F_161 ( L_5 , V_44 ) ;
goto V_194;
}
}
F_164 ( F_144 , NULL , 1 ) ;
V_44 = F_165 () ;
switch ( V_44 ) {
case 0 :
V_14 = true ;
break;
case - V_160 :
case - V_123 :
V_14 = false ;
break;
default:
goto V_194;
}
V_44 = F_166 () ;
if ( V_44 )
goto V_194;
#ifndef F_167
F_168 () ;
#endif
F_169 () ;
V_75 = F_170 () ;
F_171 ( L_6 , V_75 ) ;
F_171 ( L_7 ) ;
return 0 ;
V_194:
F_172 ( V_57 ) ;
V_189:
F_173 () ;
V_186:
F_158 (cpu)
F_174 ( F_160 ( V_171 , V_55 ) ) ;
V_185:
F_161 ( L_8 , V_44 ) ;
return V_44 ;
}
static void F_175 ( void * V_7 )
{
* ( int * ) V_7 = F_120 () ;
}
struct V_1 * F_176 ( struct V_6 * V_6 , unsigned long V_195 )
{
struct V_1 * V_2 ;
int V_19 ;
V_195 &= V_196 ;
F_80 (i, vcpu, kvm) {
if ( V_195 == F_177 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_178 ( void * V_197 )
{
int V_44 ;
int V_7 , V_55 ;
if ( ! F_179 () ) {
F_161 ( L_9 ) ;
return - V_160 ;
}
F_180 (cpu) {
F_181 ( V_55 , F_175 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_161 ( L_10 , V_55 ) ;
return - V_160 ;
}
}
F_182 () ;
V_44 = F_156 () ;
if ( V_44 )
goto V_185;
V_44 = F_183 ( & V_198 ) ;
if ( V_44 ) {
F_161 ( L_11 , V_44 ) ;
goto V_185;
}
F_184 () ;
F_154 () ;
F_185 () ;
return 0 ;
V_185:
F_184 () ;
return V_44 ;
}
void F_186 ( void )
{
F_187 () ;
}
static int F_188 ( void )
{
int V_199 = F_189 ( NULL , sizeof( struct V_1 ) , 0 , V_200 ) ;
return V_199 ;
}
