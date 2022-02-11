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
V_21 = V_23 ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
V_21 = 1 ;
break;
case V_32 :
V_21 = V_33 ;
break;
case V_34 :
V_21 = 1 ;
break;
case V_35 :
V_21 = F_24 () ;
break;
case V_36 :
V_21 = V_18 ;
break;
default:
V_21 = F_25 ( V_20 ) ;
break;
}
return V_21 ;
}
long F_26 ( struct V_37 * V_38 ,
unsigned int V_39 , unsigned long V_40 )
{
return - V_8 ;
}
struct V_1 * F_27 ( struct V_6 * V_6 , unsigned int V_41 )
{
int V_42 ;
struct V_1 * V_2 ;
if ( F_28 ( V_6 ) && F_29 ( V_6 ) ) {
V_42 = - V_43 ;
goto V_44;
}
if ( V_41 >= V_6 -> V_11 . V_13 ) {
V_42 = - V_8 ;
goto V_44;
}
V_2 = F_30 ( V_45 , V_46 ) ;
if ( ! V_2 ) {
V_42 = - V_47 ;
goto V_44;
}
V_42 = F_31 ( V_2 , V_6 , V_41 ) ;
if ( V_42 )
goto V_48;
V_42 = F_15 ( V_2 , V_2 + 1 ) ;
if ( V_42 )
goto V_49;
return V_2 ;
V_49:
F_32 ( V_2 ) ;
V_48:
F_33 ( V_45 , V_2 ) ;
V_44:
return F_34 ( V_42 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
}
void F_21 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_33 ( V_45 , V_2 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
}
int F_40 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_41 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_50 = - 1 ;
F_42 ( V_2 -> V_11 . V_51 , V_52 ) ;
F_43 ( V_2 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 , int V_53 )
{
V_2 -> V_53 = V_53 ;
V_2 -> V_11 . V_54 = F_45 ( V_55 ) ;
F_1 ( V_2 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_53 = - 1 ;
F_1 ( NULL ) ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
return - V_8 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
return - V_8 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
return - V_8 ;
}
int F_50 ( struct V_1 * V_60 )
{
return ! ! V_60 -> V_11 . V_61 || F_51 ( V_60 ) ;
}
static void F_52 ( void * V_62 )
{
}
void F_53 ( const T_2 * V_63 )
{
F_54 ( V_63 , F_52 , NULL , true ) ;
}
static bool F_55 ( struct V_6 * V_6 )
{
return F_56 ( V_6 -> V_11 . V_12 != F_57 ( & V_64 ) ) ;
}
static void F_58 ( struct V_6 * V_6 )
{
T_3 V_65 ;
T_4 V_66 ;
if ( ! F_55 ( V_6 ) )
return;
F_59 ( & V_67 ) ;
if ( ! F_55 ( V_6 ) ) {
F_60 ( & V_67 ) ;
return;
}
if ( F_56 ( V_68 == 0 ) ) {
F_61 ( & V_64 ) ;
V_68 = 1 ;
F_53 ( V_69 ) ;
F_62 ( V_70 ) ;
}
V_6 -> V_11 . V_12 = F_57 ( & V_64 ) ;
V_6 -> V_11 . V_66 = V_68 ;
V_68 ++ ;
V_65 = F_63 ( F_64 ( V_6 ) ) ;
F_2 ( V_65 & ~ V_71 ) ;
V_66 = ( ( T_4 ) ( V_6 -> V_11 . V_66 ) << V_72 ) & V_73 ;
V_6 -> V_11 . V_74 = V_65 | V_66 ;
F_60 ( & V_67 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 ;
if ( F_66 ( V_2 -> V_11 . V_75 ) )
return 0 ;
V_2 -> V_11 . V_75 = true ;
if ( F_56 ( ! F_67 ( V_6 ) ) ) {
V_7 = F_68 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
if ( F_28 ( V_6 ) && F_29 ( V_6 ) )
F_69 ( V_6 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
T_5 * V_76 = F_71 ( V_2 ) ;
F_72 ( * V_76 , ! V_2 -> V_11 . V_77 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
return V_2 -> V_11 . V_50 >= 0 ;
}
int F_74 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
int V_7 ;
T_6 V_80 ;
if ( F_56 ( ! F_73 ( V_2 ) ) )
return - V_81 ;
V_7 = F_65 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_79 -> V_82 == V_83 ) {
V_7 = F_75 ( V_2 , V_2 -> V_79 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_84 )
F_76 ( V_85 , & V_2 -> V_86 , & V_80 ) ;
V_7 = 1 ;
V_79 -> V_82 = V_87 ;
while ( V_7 > 0 ) {
F_77 () ;
F_58 ( V_2 -> V_6 ) ;
if ( V_2 -> V_11 . V_77 )
F_70 ( V_2 ) ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_80 () ;
if ( F_81 ( V_88 ) ) {
V_7 = - V_89 ;
V_79 -> V_82 = V_90 ;
}
if ( V_7 <= 0 || F_55 ( V_2 -> V_6 ) ) {
F_82 () ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
continue;
}
F_85 ( * F_86 ( V_2 ) ) ;
F_87 () ;
V_2 -> V_91 = V_4 ;
V_7 = F_62 ( V_92 , V_2 ) ;
V_2 -> V_91 = V_93 ;
F_88 () ;
F_89 ( F_90 ( V_2 ) , * F_86 ( V_2 ) ) ;
F_82 () ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
V_7 = F_91 ( V_2 , V_79 , V_7 ) ;
}
if ( V_2 -> V_84 )
F_76 ( V_85 , & V_80 , NULL ) ;
return V_7 ;
}
static int F_92 ( struct V_1 * V_2 , int V_94 , bool V_95 )
{
int V_96 ;
bool V_97 ;
unsigned long * V_98 ;
if ( V_94 == V_99 )
V_96 = F_93 ( V_100 ) ;
else
V_96 = F_93 ( V_101 ) ;
V_98 = ( unsigned long * ) & V_2 -> V_11 . V_61 ;
if ( V_95 )
V_97 = F_94 ( V_96 , V_98 ) ;
else
V_97 = F_95 ( V_96 , V_98 ) ;
if ( V_97 == V_95 )
return 0 ;
F_96 ( V_2 ) ;
return 0 ;
}
int F_97 ( struct V_6 * V_6 , struct V_102 * V_103 ,
bool V_104 )
{
T_7 V_105 = V_103 -> V_105 ;
unsigned int V_106 , V_107 , V_108 ;
int V_109 = F_98 ( & V_6 -> V_110 ) ;
struct V_1 * V_2 = NULL ;
bool V_95 = V_103 -> V_95 ;
V_106 = ( V_105 >> V_111 ) & V_112 ;
V_107 = ( V_105 >> V_113 ) & V_114 ;
V_108 = ( V_105 >> V_115 ) & V_116 ;
F_99 ( V_106 , V_107 , V_108 , V_103 -> V_95 ) ;
switch ( V_106 ) {
case V_117 :
if ( F_28 ( V_6 ) )
return - V_118 ;
if ( V_107 >= V_109 )
return - V_8 ;
V_2 = F_100 ( V_6 , V_107 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_108 > V_119 )
return - V_8 ;
return F_92 ( V_2 , V_108 , V_95 ) ;
case V_120 :
if ( ! F_28 ( V_6 ) )
return - V_118 ;
if ( V_107 >= V_109 )
return - V_8 ;
V_2 = F_100 ( V_6 , V_107 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_108 < V_121 || V_108 >= V_122 )
return - V_8 ;
return F_101 ( V_6 , V_2 -> V_123 , V_108 , V_95 ) ;
case V_124 :
if ( ! F_28 ( V_6 ) )
return - V_118 ;
if ( V_108 < V_122 ||
V_108 > V_125 )
return - V_8 ;
return F_101 ( V_6 , 0 , V_108 , V_95 ) ;
}
return - V_8 ;
}
static int F_102 ( struct V_1 * V_2 ,
const struct F_31 * V_126 )
{
unsigned int V_17 ;
int V_127 = F_103 () ;
if ( V_126 -> V_50 != V_127 )
return - V_8 ;
if ( V_2 -> V_11 . V_50 != - 1 && V_2 -> V_11 . V_50 != V_126 -> V_50 )
return - V_8 ;
for ( V_17 = 0 ; V_17 < sizeof( V_126 -> V_51 ) * 8 ; V_17 ++ ) {
bool V_97 = ( V_126 -> V_51 [ V_17 / 32 ] & ( 1 << ( V_17 % 32 ) ) ) ;
if ( V_97 && V_17 >= V_52 )
return - V_128 ;
if ( V_2 -> V_11 . V_50 != - 1 && V_17 < V_52 &&
F_104 ( V_17 , V_2 -> V_11 . V_51 ) != V_97 )
return - V_8 ;
if ( V_97 )
F_105 ( V_17 , V_2 -> V_11 . V_51 ) ;
}
V_2 -> V_11 . V_50 = V_127 ;
return F_106 ( V_2 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
struct F_31 * V_126 )
{
int V_7 ;
V_7 = F_102 ( V_2 , V_126 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_11 . V_75 )
F_108 ( V_2 -> V_6 ) ;
F_109 ( V_2 ) ;
if ( F_104 ( V_129 , V_2 -> V_11 . V_51 ) )
V_2 -> V_11 . V_77 = true ;
else
V_2 -> V_11 . V_77 = false ;
return 0 ;
}
long F_110 ( struct V_37 * V_38 ,
unsigned int V_39 , unsigned long V_40 )
{
struct V_1 * V_2 = V_38 -> V_130 ;
void T_8 * V_131 = ( void T_8 * ) V_40 ;
switch ( V_39 ) {
case V_132 : {
struct F_31 V_126 ;
if ( F_111 ( & V_126 , V_131 , sizeof( V_126 ) ) )
return - V_133 ;
return F_107 ( V_2 , & V_126 ) ;
}
case V_134 :
case V_135 : {
struct V_136 V_137 ;
if ( F_56 ( ! F_73 ( V_2 ) ) )
return - V_81 ;
if ( F_111 ( & V_137 , V_131 , sizeof( V_137 ) ) )
return - V_133 ;
if ( V_39 == V_134 )
return F_112 ( V_2 , & V_137 ) ;
else
return F_113 ( V_2 , & V_137 ) ;
}
case V_138 : {
struct V_139 T_8 * V_140 = V_131 ;
struct V_139 V_141 ;
unsigned V_142 ;
if ( F_56 ( ! F_73 ( V_2 ) ) )
return - V_81 ;
if ( F_111 ( & V_141 , V_140 , sizeof( V_141 ) ) )
return - V_133 ;
V_142 = V_141 . V_142 ;
V_141 . V_142 = F_114 ( V_2 ) ;
if ( F_115 ( V_140 , & V_141 , sizeof( V_141 ) ) )
return - V_133 ;
if ( V_142 < V_141 . V_142 )
return - V_143 ;
return F_116 ( V_2 , V_140 -> V_137 ) ;
}
default:
return - V_8 ;
}
}
int F_117 ( struct V_6 * V_6 , struct V_144 * log )
{
bool V_145 = false ;
int V_21 ;
F_118 ( & V_6 -> V_146 ) ;
V_21 = F_119 ( V_6 , log , & V_145 ) ;
if ( V_145 )
F_120 ( V_6 ) ;
F_121 ( & V_6 -> V_146 ) ;
return V_21 ;
}
static int F_122 ( struct V_6 * V_6 ,
struct V_147 * V_148 )
{
unsigned long V_149 , type ;
V_149 = ( V_148 -> V_41 & V_150 ) >>
V_151 ;
type = ( V_148 -> V_41 & V_152 ) >>
V_153 ;
switch ( V_149 ) {
case V_154 :
if ( ! V_23 )
return - V_118 ;
return F_123 ( V_6 , type , & V_148 -> V_155 , true ) ;
default:
return - V_156 ;
}
}
long F_124 ( struct V_37 * V_38 ,
unsigned int V_39 , unsigned long V_40 )
{
struct V_6 * V_6 = V_38 -> V_130 ;
void T_8 * V_131 = ( void T_8 * ) V_40 ;
switch ( V_39 ) {
case V_157 : {
if ( V_23 )
return F_125 ( V_6 , V_158 ) ;
else
return - V_118 ;
}
case V_159 : {
struct V_147 V_148 ;
if ( F_111 ( & V_148 , V_131 , sizeof( V_148 ) ) )
return - V_133 ;
return F_122 ( V_6 , & V_148 ) ;
}
case V_160 : {
int V_42 ;
struct F_31 V_126 ;
V_42 = F_126 ( & V_126 ) ;
if ( V_42 )
return V_42 ;
if ( F_115 ( V_131 , & V_126 , sizeof( V_126 ) ) )
return - V_133 ;
return 0 ;
}
default:
return - V_8 ;
}
}
static void F_127 ( void * V_161 )
{
T_3 V_162 ;
T_3 V_163 ;
unsigned long V_164 ;
unsigned long V_165 ;
unsigned long V_166 ;
F_128 ( F_129 () ) ;
V_162 = F_130 () ;
V_163 = F_131 () ;
V_165 = F_6 ( V_167 ) ;
V_164 = V_165 + V_168 ;
V_166 = ( unsigned long ) V_169 ;
F_132 ( V_162 , V_163 , V_164 , V_166 ) ;
}
static int F_133 ( struct V_170 * V_171 ,
unsigned long V_172 , void * V_53 )
{
switch ( V_172 ) {
case V_173 :
case V_174 :
if ( F_134 () == V_175 )
F_127 ( NULL ) ;
break;
}
return V_176 ;
}
static int F_135 ( struct V_170 * V_171 ,
unsigned long V_177 ,
void * V_60 )
{
if ( V_177 == V_178 &&
F_134 () == V_175 ) {
F_127 ( NULL ) ;
return V_176 ;
}
return V_179 ;
}
static void T_9 F_136 ( void )
{
F_137 ( & V_180 ) ;
}
static inline void F_136 ( void )
{
}
static int F_138 ( void )
{
int V_53 ;
int V_42 = 0 ;
V_42 = F_139 () ;
if ( V_42 )
goto V_181;
V_175 = F_134 () ;
F_140 (cpu) {
unsigned long V_165 ;
V_165 = F_141 ( V_46 ) ;
if ( ! V_165 ) {
V_42 = - V_47 ;
goto V_182;
}
F_142 ( V_167 , V_53 ) = V_165 ;
}
V_42 = F_15 ( V_183 , V_184 ) ;
if ( V_42 ) {
F_143 ( L_1 ) ;
goto V_185;
}
F_140 (cpu) {
char * V_165 = ( char * ) F_142 ( V_167 , V_53 ) ;
V_42 = F_15 ( V_165 , V_165 + V_168 ) ;
if ( V_42 ) {
F_143 ( L_2 ) ;
goto V_185;
}
}
V_55 = F_144 ( V_186 ) ;
if ( ! V_55 ) {
V_42 = - V_47 ;
F_143 ( L_3 ) ;
goto V_185;
}
F_140 (cpu) {
V_186 * V_187 ;
V_187 = F_145 ( V_55 , V_53 ) ;
V_42 = F_15 ( V_187 , V_187 + 1 ) ;
if ( V_42 ) {
F_143 ( L_4 , V_42 ) ;
goto V_188;
}
}
F_146 ( F_127 , NULL , 1 ) ;
V_42 = F_147 () ;
if ( V_42 )
goto V_188;
#ifdef F_148
V_23 = true ;
#endif
V_42 = F_149 () ;
if ( V_42 )
goto V_185;
#ifndef F_150
F_151 () ;
#endif
F_152 () ;
F_153 ( L_5 ) ;
return 0 ;
V_188:
F_154 ( V_55 ) ;
V_185:
F_155 () ;
V_182:
F_140 (cpu)
F_156 ( F_142 ( V_167 , V_53 ) ) ;
V_181:
F_143 ( L_6 , V_42 ) ;
return V_42 ;
}
static void F_157 ( void * V_7 )
{
* ( int * ) V_7 = F_103 () ;
}
struct V_1 * F_158 ( struct V_6 * V_6 , unsigned long V_189 )
{
struct V_1 * V_2 ;
int V_17 ;
V_189 &= V_190 ;
F_159 (i, vcpu, kvm) {
if ( V_189 == F_160 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_161 ( void * V_191 )
{
int V_42 ;
int V_7 , V_53 ;
if ( ! F_162 () ) {
F_143 ( L_7 ) ;
return - V_156 ;
}
F_163 (cpu) {
F_164 ( V_53 , F_157 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_143 ( L_8 , V_53 ) ;
return - V_156 ;
}
}
F_165 () ;
V_42 = F_138 () ;
if ( V_42 )
goto V_181;
V_42 = F_166 ( & V_192 ) ;
if ( V_42 ) {
F_143 ( L_9 , V_42 ) ;
goto V_181;
}
F_167 () ;
F_136 () ;
F_168 () ;
return 0 ;
V_181:
F_167 () ;
return V_42 ;
}
void F_169 ( void )
{
F_170 () ;
}
static int F_171 ( void )
{
int V_193 = F_172 ( NULL , sizeof( struct V_1 ) , 0 , V_194 ) ;
return V_193 ;
}
