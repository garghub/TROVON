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
int F_44 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_51 = - 1 ;
F_45 ( V_2 -> V_11 . V_52 , V_53 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 , int V_54 )
{
V_2 -> V_54 = V_54 ;
V_2 -> V_11 . V_55 = F_49 ( V_56 ) ;
F_1 ( V_2 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
V_2 -> V_54 = - 1 ;
F_1 ( NULL ) ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
if ( V_2 -> V_11 . V_59 )
V_58 -> V_58 = V_60 ;
else
V_58 -> V_58 = V_61 ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 ,
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
int F_53 ( struct V_1 * V_62 )
{
return ! ! V_62 -> V_11 . V_63 || F_54 ( V_62 ) ;
}
static void F_55 ( void * V_64 )
{
}
void F_56 ( const T_2 * V_65 )
{
F_57 ( V_65 , F_55 , NULL , true ) ;
}
static bool F_58 ( struct V_6 * V_6 )
{
return F_59 ( V_6 -> V_11 . V_12 != F_60 ( & V_66 ) ) ;
}
static void F_61 ( struct V_6 * V_6 )
{
T_3 V_67 ;
T_4 V_68 ;
if ( ! F_58 ( V_6 ) )
return;
F_62 ( & V_69 ) ;
if ( ! F_58 ( V_6 ) ) {
F_63 ( & V_69 ) ;
return;
}
if ( F_59 ( V_70 == 0 ) ) {
F_64 ( & V_66 ) ;
V_70 = 1 ;
F_56 ( V_71 ) ;
F_65 ( V_72 ) ;
}
V_6 -> V_11 . V_12 = F_60 ( & V_66 ) ;
V_6 -> V_11 . V_68 = V_70 ;
V_70 ++ ;
V_67 = F_66 ( F_67 ( V_6 ) ) ;
F_2 ( V_67 & ~ V_73 ) ;
V_68 = ( ( T_4 ) ( V_6 -> V_11 . V_68 ) << V_74 ) & V_75 ;
V_6 -> V_11 . V_76 = V_67 | V_68 ;
F_63 ( & V_69 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 ;
if ( F_69 ( V_2 -> V_11 . V_77 ) )
return 0 ;
V_2 -> V_11 . V_77 = true ;
if ( F_59 ( F_29 ( V_6 ) && ! F_70 ( V_6 ) ) ) {
V_7 = F_71 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
if ( F_29 ( V_6 ) && F_30 ( V_6 ) )
F_72 ( V_6 ) ;
return 0 ;
}
bool F_73 ( struct V_6 * V_6 )
{
return F_30 ( V_6 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
T_5 * V_78 = F_75 ( V_2 ) ;
F_76 ( * V_78 , ! V_2 -> V_11 . V_59 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
return V_2 -> V_11 . V_51 >= 0 ;
}
int F_78 ( struct V_1 * V_2 , struct V_79 * V_80 )
{
int V_7 ;
T_6 V_81 ;
if ( F_59 ( ! F_77 ( V_2 ) ) )
return - V_82 ;
V_7 = F_68 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_80 -> V_83 == V_84 ) {
V_7 = F_79 ( V_2 , V_2 -> V_80 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_85 )
F_80 ( V_86 , & V_2 -> V_87 , & V_81 ) ;
V_7 = 1 ;
V_80 -> V_83 = V_88 ;
while ( V_7 > 0 ) {
F_81 () ;
F_61 ( V_2 -> V_6 ) ;
if ( V_2 -> V_11 . V_59 )
F_74 ( V_2 ) ;
F_82 ( V_2 ) ;
F_83 () ;
F_84 ( V_2 ) ;
F_85 () ;
if ( F_86 ( V_89 ) ) {
V_7 = - V_90 ;
V_80 -> V_83 = V_91 ;
}
if ( V_7 <= 0 || F_58 ( V_2 -> V_6 ) ) {
F_87 () ;
F_88 ( V_2 ) ;
F_89 () ;
F_90 ( V_2 ) ;
continue;
}
F_91 ( V_2 ) ;
F_92 ( * F_93 ( V_2 ) ) ;
F_94 () ;
V_2 -> V_92 = V_4 ;
V_7 = F_65 ( V_93 , V_2 ) ;
V_2 -> V_92 = V_94 ;
F_95 ( V_2 ) ;
F_87 () ;
F_96 () ;
F_97 ( F_98 ( V_2 ) , * F_93 ( V_2 ) ) ;
F_88 ( V_2 ) ;
F_89 () ;
F_90 ( V_2 ) ;
V_7 = F_99 ( V_2 , V_80 , V_7 ) ;
}
if ( V_2 -> V_85 )
F_80 ( V_86 , & V_81 , NULL ) ;
return V_7 ;
}
static int F_100 ( struct V_1 * V_2 , int V_95 , bool V_96 )
{
int V_97 ;
bool V_98 ;
unsigned long * V_99 ;
if ( V_95 == V_100 )
V_97 = F_101 ( V_101 ) ;
else
V_97 = F_101 ( V_102 ) ;
V_99 = ( unsigned long * ) & V_2 -> V_11 . V_63 ;
if ( V_96 )
V_98 = F_102 ( V_97 , V_99 ) ;
else
V_98 = F_103 ( V_97 , V_99 ) ;
if ( V_98 == V_96 )
return 0 ;
F_104 ( V_2 ) ;
return 0 ;
}
int F_105 ( struct V_6 * V_6 , struct V_103 * V_104 ,
bool V_105 )
{
T_7 V_106 = V_104 -> V_106 ;
unsigned int V_107 , V_108 , V_109 ;
int V_110 = F_106 ( & V_6 -> V_111 ) ;
struct V_1 * V_2 = NULL ;
bool V_96 = V_104 -> V_96 ;
V_107 = ( V_106 >> V_112 ) & V_113 ;
V_108 = ( V_106 >> V_114 ) & V_115 ;
V_109 = ( V_106 >> V_116 ) & V_117 ;
F_107 ( V_107 , V_108 , V_109 , V_104 -> V_96 ) ;
switch ( V_107 ) {
case V_118 :
if ( F_29 ( V_6 ) )
return - V_119 ;
if ( V_108 >= V_110 )
return - V_8 ;
V_2 = F_108 ( V_6 , V_108 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_109 > V_120 )
return - V_8 ;
return F_100 ( V_2 , V_109 , V_96 ) ;
case V_121 :
if ( ! F_29 ( V_6 ) )
return - V_119 ;
if ( V_108 >= V_110 )
return - V_8 ;
V_2 = F_108 ( V_6 , V_108 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_109 < V_122 || V_109 >= V_123 )
return - V_8 ;
return F_109 ( V_6 , V_2 -> V_124 , V_109 , V_96 ) ;
case V_125 :
if ( ! F_29 ( V_6 ) )
return - V_119 ;
if ( V_109 < V_123 )
return - V_8 ;
return F_109 ( V_6 , 0 , V_109 , V_96 ) ;
}
return - V_8 ;
}
static int F_110 ( struct V_1 * V_2 ,
const struct F_32 * V_126 )
{
unsigned int V_17 ;
int V_127 = F_111 () ;
if ( V_126 -> V_51 != V_127 )
return - V_8 ;
if ( V_2 -> V_11 . V_51 != - 1 && V_2 -> V_11 . V_51 != V_126 -> V_51 )
return - V_8 ;
for ( V_17 = 0 ; V_17 < sizeof( V_126 -> V_52 ) * 8 ; V_17 ++ ) {
bool V_98 = ( V_126 -> V_52 [ V_17 / 32 ] & ( 1 << ( V_17 % 32 ) ) ) ;
if ( V_98 && V_17 >= V_53 )
return - V_128 ;
if ( V_2 -> V_11 . V_51 != - 1 && V_17 < V_53 &&
F_112 ( V_17 , V_2 -> V_11 . V_52 ) != V_98 )
return - V_8 ;
if ( V_98 )
F_113 ( V_17 , V_2 -> V_11 . V_52 ) ;
}
V_2 -> V_11 . V_51 = V_127 ;
return F_114 ( V_2 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
struct F_32 * V_126 )
{
int V_7 ;
V_7 = F_110 ( V_2 , V_126 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_11 . V_77 )
F_116 ( V_2 -> V_6 ) ;
F_117 ( V_2 ) ;
if ( F_112 ( V_129 , V_2 -> V_11 . V_52 ) )
V_2 -> V_11 . V_59 = true ;
else
V_2 -> V_11 . V_59 = false ;
return 0 ;
}
long F_118 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_1 * V_2 = V_39 -> V_130 ;
void T_8 * V_131 = ( void T_8 * ) V_41 ;
switch ( V_40 ) {
case V_132 : {
struct F_32 V_126 ;
if ( F_119 ( & V_126 , V_131 , sizeof( V_126 ) ) )
return - V_133 ;
return F_115 ( V_2 , & V_126 ) ;
}
case V_134 :
case V_135 : {
struct V_136 V_137 ;
if ( F_59 ( ! F_77 ( V_2 ) ) )
return - V_82 ;
if ( F_119 ( & V_137 , V_131 , sizeof( V_137 ) ) )
return - V_133 ;
if ( V_40 == V_134 )
return F_120 ( V_2 , & V_137 ) ;
else
return F_121 ( V_2 , & V_137 ) ;
}
case V_138 : {
struct V_139 T_8 * V_140 = V_131 ;
struct V_139 V_141 ;
unsigned V_142 ;
if ( F_59 ( ! F_77 ( V_2 ) ) )
return - V_82 ;
if ( F_119 ( & V_141 , V_140 , sizeof( V_141 ) ) )
return - V_133 ;
V_142 = V_141 . V_142 ;
V_141 . V_142 = F_122 ( V_2 ) ;
if ( F_123 ( V_140 , & V_141 , sizeof( V_141 ) ) )
return - V_133 ;
if ( V_142 < V_141 . V_142 )
return - V_143 ;
return F_124 ( V_2 , V_140 -> V_137 ) ;
}
default:
return - V_8 ;
}
}
int F_125 ( struct V_6 * V_6 , struct V_144 * log )
{
bool V_145 = false ;
int V_21 ;
F_126 ( & V_6 -> V_146 ) ;
V_21 = F_127 ( V_6 , log , & V_145 ) ;
if ( V_145 )
F_128 ( V_6 ) ;
F_129 ( & V_6 -> V_146 ) ;
return V_21 ;
}
static int F_130 ( struct V_6 * V_6 ,
struct V_147 * V_148 )
{
unsigned long V_149 , type ;
V_149 = ( V_148 -> V_42 & V_150 ) >>
V_151 ;
type = ( V_148 -> V_42 & V_152 ) >>
V_153 ;
switch ( V_149 ) {
case V_154 :
return F_131 ( V_6 , type , & V_148 -> V_155 , true ) ;
default:
return - V_156 ;
}
}
long F_132 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_6 * V_6 = V_39 -> V_130 ;
void T_8 * V_131 = ( void T_8 * ) V_41 ;
switch ( V_40 ) {
case V_157 : {
return F_133 ( V_6 , V_158 ) ;
}
case V_159 : {
struct V_147 V_148 ;
if ( F_119 ( & V_148 , V_131 , sizeof( V_148 ) ) )
return - V_133 ;
return F_130 ( V_6 , & V_148 ) ;
}
case V_160 : {
int V_43 ;
struct F_32 V_126 ;
V_43 = F_134 ( & V_126 ) ;
if ( V_43 )
return V_43 ;
if ( F_123 ( V_131 , & V_126 , sizeof( V_126 ) ) )
return - V_133 ;
return 0 ;
}
default:
return - V_8 ;
}
}
static void F_135 ( void * V_161 )
{
T_3 V_162 ;
T_3 V_163 ;
unsigned long V_164 ;
unsigned long V_165 ;
unsigned long V_166 ;
F_136 ( F_137 () ) ;
V_162 = F_138 () ;
V_163 = F_139 () ;
V_165 = F_6 ( V_167 ) ;
V_164 = V_165 + V_168 ;
V_166 = ( unsigned long ) V_169 ;
F_140 ( V_162 , V_163 , V_164 , V_166 ) ;
F_141 () ;
}
static int F_142 ( struct V_170 * V_171 ,
unsigned long V_172 , void * V_54 )
{
switch ( V_172 ) {
case V_173 :
case V_174 :
if ( F_143 () == V_175 )
F_135 ( NULL ) ;
break;
}
return V_176 ;
}
static int F_144 ( struct V_170 * V_171 ,
unsigned long V_177 ,
void * V_62 )
{
if ( V_177 == V_178 &&
F_143 () == V_175 ) {
F_135 ( NULL ) ;
return V_176 ;
}
return V_179 ;
}
static void T_9 F_145 ( void )
{
F_146 ( & V_180 ) ;
}
static inline void F_145 ( void )
{
}
static int F_147 ( void )
{
int V_54 ;
int V_43 = 0 ;
V_43 = F_148 () ;
if ( V_43 )
goto V_181;
V_175 = F_143 () ;
F_149 (cpu) {
unsigned long V_165 ;
V_165 = F_150 ( V_47 ) ;
if ( ! V_165 ) {
V_43 = - V_48 ;
goto V_182;
}
F_151 ( V_167 , V_54 ) = V_165 ;
}
V_43 = F_15 ( V_183 , V_184 ) ;
if ( V_43 ) {
F_152 ( L_1 ) ;
goto V_185;
}
F_149 (cpu) {
char * V_165 = ( char * ) F_151 ( V_167 , V_54 ) ;
V_43 = F_15 ( V_165 , V_165 + V_168 ) ;
if ( V_43 ) {
F_152 ( L_2 ) ;
goto V_185;
}
}
V_56 = F_153 ( V_186 ) ;
if ( ! V_56 ) {
V_43 = - V_48 ;
F_152 ( L_3 ) ;
goto V_185;
}
F_149 (cpu) {
V_186 * V_187 ;
V_187 = F_154 ( V_56 , V_54 ) ;
V_43 = F_15 ( V_187 , V_187 + 1 ) ;
if ( V_43 ) {
F_152 ( L_4 , V_43 ) ;
goto V_188;
}
}
F_155 ( F_135 , NULL , 1 ) ;
V_43 = F_156 () ;
if ( V_43 )
goto V_188;
V_43 = F_157 () ;
if ( V_43 )
goto V_188;
#ifndef F_158
F_159 () ;
#endif
F_160 () ;
F_161 ( L_5 ) ;
return 0 ;
V_188:
F_162 ( V_56 ) ;
V_185:
F_163 () ;
V_182:
F_149 (cpu)
F_164 ( F_151 ( V_167 , V_54 ) ) ;
V_181:
F_152 ( L_6 , V_43 ) ;
return V_43 ;
}
static void F_165 ( void * V_7 )
{
* ( int * ) V_7 = F_111 () ;
}
struct V_1 * F_166 ( struct V_6 * V_6 , unsigned long V_189 )
{
struct V_1 * V_2 ;
int V_17 ;
V_189 &= V_190 ;
F_167 (i, vcpu, kvm) {
if ( V_189 == F_168 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_169 ( void * V_191 )
{
int V_43 ;
int V_7 , V_54 ;
if ( ! F_170 () ) {
F_152 ( L_7 ) ;
return - V_156 ;
}
F_171 (cpu) {
F_172 ( V_54 , F_165 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_152 ( L_8 , V_54 ) ;
return - V_156 ;
}
}
F_173 () ;
V_43 = F_147 () ;
if ( V_43 )
goto V_181;
V_43 = F_174 ( & V_192 ) ;
if ( V_43 ) {
F_152 ( L_9 , V_43 ) ;
goto V_181;
}
F_175 () ;
F_145 () ;
F_176 () ;
return 0 ;
V_181:
F_175 () ;
return V_43 ;
}
void F_177 ( void )
{
F_178 () ;
}
static int F_179 ( void )
{
int V_193 = F_180 ( NULL , sizeof( struct V_1 ) , 0 , V_194 ) ;
return V_193 ;
}
