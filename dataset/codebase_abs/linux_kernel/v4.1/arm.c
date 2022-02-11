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
case V_33 :
V_21 = 1 ;
break;
case V_34 :
V_21 = V_35 ;
break;
case V_36 :
V_21 = 1 ;
break;
case V_37 :
V_21 = F_24 () ;
break;
case V_38 :
V_21 = V_18 ;
break;
default:
V_21 = F_25 ( V_20 ) ;
break;
}
return V_21 ;
}
long F_26 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
return - V_8 ;
}
struct V_1 * F_27 ( struct V_6 * V_6 , unsigned int V_43 )
{
int V_44 ;
struct V_1 * V_2 ;
if ( F_28 ( V_6 ) && F_29 ( V_6 ) ) {
V_44 = - V_45 ;
goto V_46;
}
if ( V_43 >= V_6 -> V_11 . V_13 ) {
V_44 = - V_8 ;
goto V_46;
}
V_2 = F_30 ( V_47 , V_48 ) ;
if ( ! V_2 ) {
V_44 = - V_49 ;
goto V_46;
}
V_44 = F_31 ( V_2 , V_6 , V_43 ) ;
if ( V_44 )
goto V_50;
V_44 = F_15 ( V_2 , V_2 + 1 ) ;
if ( V_44 )
goto V_51;
return V_2 ;
V_51:
F_32 ( V_2 ) ;
V_50:
F_33 ( V_47 , V_2 ) ;
V_46:
return F_34 ( V_44 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
}
void F_21 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_33 ( V_47 , V_2 ) ;
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
V_2 -> V_11 . V_52 = - 1 ;
F_43 ( V_2 -> V_11 . V_53 , V_54 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 , int V_55 )
{
V_2 -> V_55 = V_55 ;
V_2 -> V_11 . V_56 = F_46 ( V_57 ) ;
F_1 ( V_2 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_55 = - 1 ;
F_1 ( NULL ) ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
return - V_8 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
if ( V_2 -> V_11 . V_62 )
V_61 -> V_61 = V_63 ;
else
V_61 -> V_61 = V_64 ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
switch ( V_61 -> V_61 ) {
case V_64 :
V_2 -> V_11 . V_62 = false ;
break;
case V_63 :
V_2 -> V_11 . V_62 = true ;
break;
default:
return - V_8 ;
}
return 0 ;
}
int F_51 ( struct V_1 * V_65 )
{
return ! ! V_65 -> V_11 . V_66 || F_52 ( V_65 ) ;
}
static void F_53 ( void * V_67 )
{
}
void F_54 ( const T_2 * V_68 )
{
F_55 ( V_68 , F_53 , NULL , true ) ;
}
static bool F_56 ( struct V_6 * V_6 )
{
return F_57 ( V_6 -> V_11 . V_12 != F_58 ( & V_69 ) ) ;
}
static void F_59 ( struct V_6 * V_6 )
{
T_3 V_70 ;
T_4 V_71 ;
if ( ! F_56 ( V_6 ) )
return;
F_60 ( & V_72 ) ;
if ( ! F_56 ( V_6 ) ) {
F_61 ( & V_72 ) ;
return;
}
if ( F_57 ( V_73 == 0 ) ) {
F_62 ( & V_69 ) ;
V_73 = 1 ;
F_54 ( V_74 ) ;
F_63 ( V_75 ) ;
}
V_6 -> V_11 . V_12 = F_58 ( & V_69 ) ;
V_6 -> V_11 . V_71 = V_73 ;
V_73 ++ ;
V_70 = F_64 ( F_65 ( V_6 ) ) ;
F_2 ( V_70 & ~ V_76 ) ;
V_71 = ( ( T_4 ) ( V_6 -> V_11 . V_71 ) << V_77 ) & V_78 ;
V_6 -> V_11 . V_79 = V_70 | V_71 ;
F_61 ( & V_72 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 ;
if ( F_67 ( V_2 -> V_11 . V_80 ) )
return 0 ;
V_2 -> V_11 . V_80 = true ;
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
T_5 * V_81 = F_73 ( V_2 ) ;
F_74 ( * V_81 , ! V_2 -> V_11 . V_62 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
return V_2 -> V_11 . V_52 >= 0 ;
}
int F_76 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
int V_7 ;
T_6 V_84 ;
if ( F_57 ( ! F_75 ( V_2 ) ) )
return - V_85 ;
V_7 = F_66 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_83 -> V_86 == V_87 ) {
V_7 = F_77 ( V_2 , V_2 -> V_83 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_88 )
F_78 ( V_89 , & V_2 -> V_90 , & V_84 ) ;
V_7 = 1 ;
V_83 -> V_86 = V_91 ;
while ( V_7 > 0 ) {
F_79 () ;
F_59 ( V_2 -> V_6 ) ;
if ( V_2 -> V_11 . V_62 )
F_72 ( V_2 ) ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
F_82 () ;
if ( F_83 ( V_92 ) ) {
V_7 = - V_93 ;
V_83 -> V_86 = V_94 ;
}
if ( V_7 <= 0 || F_56 ( V_2 -> V_6 ) ) {
F_84 () ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
continue;
}
F_87 ( * F_88 ( V_2 ) ) ;
F_89 () ;
V_2 -> V_95 = V_4 ;
V_7 = F_63 ( V_96 , V_2 ) ;
V_2 -> V_95 = V_97 ;
F_90 () ;
F_91 ( F_92 ( V_2 ) , * F_88 ( V_2 ) ) ;
F_84 () ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
V_7 = F_93 ( V_2 , V_83 , V_7 ) ;
}
if ( V_2 -> V_88 )
F_78 ( V_89 , & V_84 , NULL ) ;
return V_7 ;
}
static int F_94 ( struct V_1 * V_2 , int V_98 , bool V_99 )
{
int V_100 ;
bool V_101 ;
unsigned long * V_102 ;
if ( V_98 == V_103 )
V_100 = F_95 ( V_104 ) ;
else
V_100 = F_95 ( V_105 ) ;
V_102 = ( unsigned long * ) & V_2 -> V_11 . V_66 ;
if ( V_99 )
V_101 = F_96 ( V_100 , V_102 ) ;
else
V_101 = F_97 ( V_100 , V_102 ) ;
if ( V_101 == V_99 )
return 0 ;
F_98 ( V_2 ) ;
return 0 ;
}
int F_99 ( struct V_6 * V_6 , struct V_106 * V_107 ,
bool V_108 )
{
T_7 V_109 = V_107 -> V_109 ;
unsigned int V_110 , V_111 , V_112 ;
int V_113 = F_100 ( & V_6 -> V_114 ) ;
struct V_1 * V_2 = NULL ;
bool V_99 = V_107 -> V_99 ;
V_110 = ( V_109 >> V_115 ) & V_116 ;
V_111 = ( V_109 >> V_117 ) & V_118 ;
V_112 = ( V_109 >> V_119 ) & V_120 ;
F_101 ( V_110 , V_111 , V_112 , V_107 -> V_99 ) ;
switch ( V_110 ) {
case V_121 :
if ( F_28 ( V_6 ) )
return - V_122 ;
if ( V_111 >= V_113 )
return - V_8 ;
V_2 = F_102 ( V_6 , V_111 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_112 > V_123 )
return - V_8 ;
return F_94 ( V_2 , V_112 , V_99 ) ;
case V_124 :
if ( ! F_28 ( V_6 ) )
return - V_122 ;
if ( V_111 >= V_113 )
return - V_8 ;
V_2 = F_102 ( V_6 , V_111 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_112 < V_125 || V_112 >= V_126 )
return - V_8 ;
return F_103 ( V_6 , V_2 -> V_127 , V_112 , V_99 ) ;
case V_128 :
if ( ! F_28 ( V_6 ) )
return - V_122 ;
if ( V_112 < V_126 )
return - V_8 ;
return F_103 ( V_6 , 0 , V_112 , V_99 ) ;
}
return - V_8 ;
}
static int F_104 ( struct V_1 * V_2 ,
const struct F_31 * V_129 )
{
unsigned int V_17 ;
int V_130 = F_105 () ;
if ( V_129 -> V_52 != V_130 )
return - V_8 ;
if ( V_2 -> V_11 . V_52 != - 1 && V_2 -> V_11 . V_52 != V_129 -> V_52 )
return - V_8 ;
for ( V_17 = 0 ; V_17 < sizeof( V_129 -> V_53 ) * 8 ; V_17 ++ ) {
bool V_101 = ( V_129 -> V_53 [ V_17 / 32 ] & ( 1 << ( V_17 % 32 ) ) ) ;
if ( V_101 && V_17 >= V_54 )
return - V_131 ;
if ( V_2 -> V_11 . V_52 != - 1 && V_17 < V_54 &&
F_106 ( V_17 , V_2 -> V_11 . V_53 ) != V_101 )
return - V_8 ;
if ( V_101 )
F_107 ( V_17 , V_2 -> V_11 . V_53 ) ;
}
V_2 -> V_11 . V_52 = V_130 ;
return F_108 ( V_2 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
struct F_31 * V_129 )
{
int V_7 ;
V_7 = F_104 ( V_2 , V_129 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_11 . V_80 )
F_110 ( V_2 -> V_6 ) ;
F_111 ( V_2 ) ;
if ( F_106 ( V_132 , V_2 -> V_11 . V_53 ) )
V_2 -> V_11 . V_62 = true ;
else
V_2 -> V_11 . V_62 = false ;
return 0 ;
}
long F_112 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_1 * V_2 = V_40 -> V_133 ;
void T_8 * V_134 = ( void T_8 * ) V_42 ;
switch ( V_41 ) {
case V_135 : {
struct F_31 V_129 ;
if ( F_113 ( & V_129 , V_134 , sizeof( V_129 ) ) )
return - V_136 ;
return F_109 ( V_2 , & V_129 ) ;
}
case V_137 :
case V_138 : {
struct V_139 V_140 ;
if ( F_57 ( ! F_75 ( V_2 ) ) )
return - V_85 ;
if ( F_113 ( & V_140 , V_134 , sizeof( V_140 ) ) )
return - V_136 ;
if ( V_41 == V_137 )
return F_114 ( V_2 , & V_140 ) ;
else
return F_115 ( V_2 , & V_140 ) ;
}
case V_141 : {
struct V_142 T_8 * V_143 = V_134 ;
struct V_142 V_144 ;
unsigned V_145 ;
if ( F_57 ( ! F_75 ( V_2 ) ) )
return - V_85 ;
if ( F_113 ( & V_144 , V_143 , sizeof( V_144 ) ) )
return - V_136 ;
V_145 = V_144 . V_145 ;
V_144 . V_145 = F_116 ( V_2 ) ;
if ( F_117 ( V_143 , & V_144 , sizeof( V_144 ) ) )
return - V_136 ;
if ( V_145 < V_144 . V_145 )
return - V_146 ;
return F_118 ( V_2 , V_143 -> V_140 ) ;
}
default:
return - V_8 ;
}
}
int F_119 ( struct V_6 * V_6 , struct V_147 * log )
{
bool V_148 = false ;
int V_21 ;
F_120 ( & V_6 -> V_149 ) ;
V_21 = F_121 ( V_6 , log , & V_148 ) ;
if ( V_148 )
F_122 ( V_6 ) ;
F_123 ( & V_6 -> V_149 ) ;
return V_21 ;
}
static int F_124 ( struct V_6 * V_6 ,
struct V_150 * V_151 )
{
unsigned long V_152 , type ;
V_152 = ( V_151 -> V_43 & V_153 ) >>
V_154 ;
type = ( V_151 -> V_43 & V_155 ) >>
V_156 ;
switch ( V_152 ) {
case V_157 :
return F_125 ( V_6 , type , & V_151 -> V_158 , true ) ;
default:
return - V_159 ;
}
}
long F_126 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_6 * V_6 = V_40 -> V_133 ;
void T_8 * V_134 = ( void T_8 * ) V_42 ;
switch ( V_41 ) {
case V_160 : {
return F_127 ( V_6 , V_161 ) ;
}
case V_162 : {
struct V_150 V_151 ;
if ( F_113 ( & V_151 , V_134 , sizeof( V_151 ) ) )
return - V_136 ;
return F_124 ( V_6 , & V_151 ) ;
}
case V_163 : {
int V_44 ;
struct F_31 V_129 ;
V_44 = F_128 ( & V_129 ) ;
if ( V_44 )
return V_44 ;
if ( F_117 ( V_134 , & V_129 , sizeof( V_129 ) ) )
return - V_136 ;
return 0 ;
}
default:
return - V_8 ;
}
}
static void F_129 ( void * V_164 )
{
T_3 V_165 ;
T_3 V_166 ;
unsigned long V_167 ;
unsigned long V_168 ;
unsigned long V_169 ;
F_130 ( F_131 () ) ;
V_165 = F_132 () ;
V_166 = F_133 () ;
V_168 = F_6 ( V_170 ) ;
V_167 = V_168 + V_171 ;
V_169 = ( unsigned long ) V_172 ;
F_134 ( V_165 , V_166 , V_167 , V_169 ) ;
}
static int F_135 ( struct V_173 * V_174 ,
unsigned long V_175 , void * V_55 )
{
switch ( V_175 ) {
case V_176 :
case V_177 :
if ( F_136 () == V_178 )
F_129 ( NULL ) ;
break;
}
return V_179 ;
}
static int F_137 ( struct V_173 * V_174 ,
unsigned long V_180 ,
void * V_65 )
{
if ( V_180 == V_181 &&
F_136 () == V_178 ) {
F_129 ( NULL ) ;
return V_179 ;
}
return V_182 ;
}
static void T_9 F_138 ( void )
{
F_139 ( & V_183 ) ;
}
static inline void F_138 ( void )
{
}
static int F_140 ( void )
{
int V_55 ;
int V_44 = 0 ;
V_44 = F_141 () ;
if ( V_44 )
goto V_184;
V_178 = F_136 () ;
F_142 (cpu) {
unsigned long V_168 ;
V_168 = F_143 ( V_48 ) ;
if ( ! V_168 ) {
V_44 = - V_49 ;
goto V_185;
}
F_144 ( V_170 , V_55 ) = V_168 ;
}
V_44 = F_15 ( V_186 , V_187 ) ;
if ( V_44 ) {
F_145 ( L_1 ) ;
goto V_188;
}
F_142 (cpu) {
char * V_168 = ( char * ) F_144 ( V_170 , V_55 ) ;
V_44 = F_15 ( V_168 , V_168 + V_171 ) ;
if ( V_44 ) {
F_145 ( L_2 ) ;
goto V_188;
}
}
V_57 = F_146 ( V_189 ) ;
if ( ! V_57 ) {
V_44 = - V_49 ;
F_145 ( L_3 ) ;
goto V_188;
}
F_142 (cpu) {
V_189 * V_190 ;
V_190 = F_147 ( V_57 , V_55 ) ;
V_44 = F_15 ( V_190 , V_190 + 1 ) ;
if ( V_44 ) {
F_145 ( L_4 , V_44 ) ;
goto V_191;
}
}
F_148 ( F_129 , NULL , 1 ) ;
V_44 = F_149 () ;
if ( V_44 )
goto V_191;
V_44 = F_150 () ;
if ( V_44 )
goto V_188;
#ifndef F_151
F_152 () ;
#endif
F_153 () ;
F_154 ( L_5 ) ;
return 0 ;
V_191:
F_155 ( V_57 ) ;
V_188:
F_156 () ;
V_185:
F_142 (cpu)
F_157 ( F_144 ( V_170 , V_55 ) ) ;
V_184:
F_145 ( L_6 , V_44 ) ;
return V_44 ;
}
static void F_158 ( void * V_7 )
{
* ( int * ) V_7 = F_105 () ;
}
struct V_1 * F_159 ( struct V_6 * V_6 , unsigned long V_192 )
{
struct V_1 * V_2 ;
int V_17 ;
V_192 &= V_193 ;
F_160 (i, vcpu, kvm) {
if ( V_192 == F_161 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_162 ( void * V_194 )
{
int V_44 ;
int V_7 , V_55 ;
if ( ! F_163 () ) {
F_145 ( L_7 ) ;
return - V_159 ;
}
F_164 (cpu) {
F_165 ( V_55 , F_158 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_145 ( L_8 , V_55 ) ;
return - V_159 ;
}
}
F_166 () ;
V_44 = F_140 () ;
if ( V_44 )
goto V_184;
V_44 = F_167 ( & V_195 ) ;
if ( V_44 ) {
F_145 ( L_9 , V_44 ) ;
goto V_184;
}
F_168 () ;
F_138 () ;
F_169 () ;
return 0 ;
V_184:
F_168 () ;
return V_44 ;
}
void F_170 ( void )
{
F_171 () ;
}
static int F_172 ( void )
{
int V_196 = F_173 ( NULL , sizeof( struct V_1 ) , 0 , V_197 ) ;
return V_196 ;
}
