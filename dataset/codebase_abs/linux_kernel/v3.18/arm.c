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
return V_7 ;
V_10:
F_17 ( V_6 ) ;
V_9:
return V_7 ;
}
int F_18 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return V_15 ;
}
void F_19 ( struct V_6 * V_6 )
{
int V_16 ;
F_17 ( V_6 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; ++ V_16 ) {
if ( V_6 -> V_18 [ V_16 ] ) {
F_20 ( V_6 -> V_18 [ V_16 ] ) ;
V_6 -> V_18 [ V_16 ] = NULL ;
}
}
F_21 ( V_6 ) ;
}
int F_22 ( struct V_6 * V_6 , long V_19 )
{
int V_20 ;
switch ( V_19 ) {
case V_21 :
V_20 = V_22 ;
break;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_20 = 1 ;
break;
case V_31 :
V_20 = V_32 ;
break;
case V_33 :
V_20 = 1 ;
break;
case V_34 :
V_20 = F_23 () ;
break;
case V_35 :
V_20 = V_17 ;
break;
default:
V_20 = F_24 ( V_19 ) ;
break;
}
return V_20 ;
}
long F_25 ( struct V_36 * V_37 ,
unsigned int V_38 , unsigned long V_39 )
{
return - V_8 ;
}
struct V_1 * F_26 ( struct V_6 * V_6 , unsigned int V_40 )
{
int V_41 ;
struct V_1 * V_2 ;
V_2 = F_27 ( V_42 , V_43 ) ;
if ( ! V_2 ) {
V_41 = - V_44 ;
goto V_45;
}
V_41 = F_28 ( V_2 , V_6 , V_40 ) ;
if ( V_41 )
goto V_46;
V_41 = F_15 ( V_2 , V_2 + 1 ) ;
if ( V_41 )
goto V_47;
return V_2 ;
V_47:
F_29 ( V_2 ) ;
V_46:
F_30 ( V_42 , V_2 ) ;
V_45:
return F_31 ( V_41 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_30 ( V_42 , V_2 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_38 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_48 = - 1 ;
F_39 ( V_2 ) ;
return 0 ;
}
void F_40 ( struct V_1 * V_2 , int V_49 )
{
V_2 -> V_49 = V_49 ;
V_2 -> V_11 . V_50 = F_41 ( V_51 ) ;
if ( F_42 ( V_49 , & V_2 -> V_11 . V_52 ) )
F_43 () ;
F_1 ( V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
V_2 -> V_49 = - 1 ;
F_1 ( NULL ) ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
return - V_8 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
return - V_8 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
return - V_8 ;
}
int F_48 ( struct V_1 * V_57 )
{
return ! ! V_57 -> V_11 . V_58 || F_49 ( V_57 ) ;
}
static void F_50 ( void * V_59 )
{
}
void F_51 ( const T_2 * V_60 )
{
F_52 ( V_60 , F_50 , NULL , true ) ;
}
static bool F_53 ( struct V_6 * V_6 )
{
return F_54 ( V_6 -> V_11 . V_12 != F_55 ( & V_61 ) ) ;
}
static void F_56 ( struct V_6 * V_6 )
{
T_3 V_62 ;
T_4 V_63 ;
if ( ! F_53 ( V_6 ) )
return;
F_57 ( & V_64 ) ;
if ( ! F_53 ( V_6 ) ) {
F_58 ( & V_64 ) ;
return;
}
if ( F_54 ( V_65 == 0 ) ) {
F_59 ( & V_61 ) ;
V_65 = 1 ;
F_51 ( V_66 ) ;
F_60 ( V_67 ) ;
}
V_6 -> V_11 . V_12 = F_55 ( & V_61 ) ;
V_6 -> V_11 . V_63 = V_65 ;
V_65 ++ ;
V_62 = F_61 ( F_62 ( V_6 ) ) ;
F_2 ( V_62 & ~ V_68 ) ;
V_63 = ( ( T_4 ) ( V_6 -> V_11 . V_63 ) << V_69 ) & V_70 ;
V_6 -> V_11 . V_71 = V_62 | V_63 ;
F_58 ( & V_64 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_7 ;
if ( F_64 ( V_2 -> V_11 . V_72 ) )
return 0 ;
V_2 -> V_11 . V_72 = true ;
if ( F_54 ( ! F_65 ( V_2 -> V_6 ) ) ) {
V_7 = F_66 ( V_2 -> V_6 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
T_5 * V_73 = F_68 ( V_2 ) ;
F_69 ( * V_73 , ! V_2 -> V_11 . V_74 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
return V_2 -> V_11 . V_48 >= 0 ;
}
int F_71 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
int V_7 ;
T_6 V_77 ;
if ( F_54 ( ! F_70 ( V_2 ) ) )
return - V_78 ;
V_7 = F_63 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_76 -> V_79 == V_80 ) {
V_7 = F_72 ( V_2 , V_2 -> V_76 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_81 )
F_73 ( V_82 , & V_2 -> V_83 , & V_77 ) ;
V_7 = 1 ;
V_76 -> V_79 = V_84 ;
while ( V_7 > 0 ) {
F_74 () ;
F_56 ( V_2 -> V_6 ) ;
if ( V_2 -> V_11 . V_74 )
F_67 ( V_2 ) ;
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
F_77 () ;
if ( F_78 ( V_85 ) ) {
V_7 = - V_86 ;
V_76 -> V_79 = V_87 ;
}
if ( V_7 <= 0 || F_53 ( V_2 -> V_6 ) ) {
F_79 () ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
continue;
}
F_82 ( * F_83 ( V_2 ) ) ;
F_84 () ;
V_2 -> V_88 = V_4 ;
V_7 = F_60 ( V_89 , V_2 ) ;
V_2 -> V_88 = V_90 ;
V_2 -> V_11 . V_91 = F_85 () ;
F_86 () ;
F_87 ( * F_83 ( V_2 ) ) ;
F_79 () ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
V_7 = F_88 ( V_2 , V_76 , V_7 ) ;
}
if ( V_2 -> V_81 )
F_73 ( V_82 , & V_77 , NULL ) ;
return V_7 ;
}
static int F_89 ( struct V_1 * V_2 , int V_92 , bool V_93 )
{
int V_94 ;
bool V_95 ;
unsigned long * V_96 ;
if ( V_92 == V_97 )
V_94 = F_90 ( V_98 ) ;
else
V_94 = F_90 ( V_99 ) ;
V_96 = ( unsigned long * ) & V_2 -> V_11 . V_58 ;
if ( V_93 )
V_95 = F_91 ( V_94 , V_96 ) ;
else
V_95 = F_92 ( V_94 , V_96 ) ;
if ( V_95 == V_93 )
return 0 ;
F_93 ( V_2 ) ;
return 0 ;
}
int F_94 ( struct V_6 * V_6 , struct V_100 * V_101 ,
bool V_102 )
{
T_7 V_103 = V_101 -> V_103 ;
unsigned int V_104 , V_105 , V_106 ;
int V_107 = F_95 ( & V_6 -> V_108 ) ;
struct V_1 * V_2 = NULL ;
bool V_93 = V_101 -> V_93 ;
V_104 = ( V_103 >> V_109 ) & V_110 ;
V_105 = ( V_103 >> V_111 ) & V_112 ;
V_106 = ( V_103 >> V_113 ) & V_114 ;
F_96 ( V_104 , V_105 , V_106 , V_101 -> V_93 ) ;
switch ( V_104 ) {
case V_115 :
if ( F_97 ( V_6 ) )
return - V_116 ;
if ( V_105 >= V_107 )
return - V_8 ;
V_2 = F_98 ( V_6 , V_105 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_106 > V_117 )
return - V_8 ;
return F_89 ( V_2 , V_106 , V_93 ) ;
case V_118 :
if ( ! F_97 ( V_6 ) )
return - V_116 ;
if ( V_105 >= V_107 )
return - V_8 ;
V_2 = F_98 ( V_6 , V_105 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_106 < V_119 || V_106 >= V_120 )
return - V_8 ;
return F_99 ( V_6 , V_2 -> V_121 , V_106 , V_93 ) ;
case V_122 :
if ( ! F_97 ( V_6 ) )
return - V_116 ;
if ( V_106 < V_120 ||
V_106 > V_123 )
return - V_8 ;
return F_99 ( V_6 , 0 , V_106 , V_93 ) ;
}
return - V_8 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct F_28 * V_124 )
{
int V_7 ;
V_7 = F_101 ( V_2 , V_124 ) ;
if ( V_7 )
return V_7 ;
if ( F_102 ( V_125 , V_2 -> V_11 . V_126 ) )
V_2 -> V_11 . V_74 = true ;
return 0 ;
}
long F_103 ( struct V_36 * V_37 ,
unsigned int V_38 , unsigned long V_39 )
{
struct V_1 * V_2 = V_37 -> V_127 ;
void T_8 * V_128 = ( void T_8 * ) V_39 ;
switch ( V_38 ) {
case V_129 : {
struct F_28 V_124 ;
if ( F_104 ( & V_124 , V_128 , sizeof( V_124 ) ) )
return - V_130 ;
return F_100 ( V_2 , & V_124 ) ;
}
case V_131 :
case V_132 : {
struct V_133 V_134 ;
if ( F_54 ( ! F_70 ( V_2 ) ) )
return - V_78 ;
if ( F_104 ( & V_134 , V_128 , sizeof( V_134 ) ) )
return - V_130 ;
if ( V_38 == V_131 )
return F_105 ( V_2 , & V_134 ) ;
else
return F_106 ( V_2 , & V_134 ) ;
}
case V_135 : {
struct V_136 T_8 * V_137 = V_128 ;
struct V_136 V_138 ;
unsigned V_139 ;
if ( F_54 ( ! F_70 ( V_2 ) ) )
return - V_78 ;
if ( F_104 ( & V_138 , V_137 , sizeof( V_138 ) ) )
return - V_130 ;
V_139 = V_138 . V_139 ;
V_138 . V_139 = F_107 ( V_2 ) ;
if ( F_108 ( V_137 , & V_138 , sizeof( V_138 ) ) )
return - V_130 ;
if ( V_139 < V_138 . V_139 )
return - V_140 ;
return F_109 ( V_2 , V_137 -> V_134 ) ;
}
default:
return - V_8 ;
}
}
int F_110 ( struct V_6 * V_6 , struct V_141 * log )
{
return - V_8 ;
}
static int F_111 ( struct V_6 * V_6 ,
struct V_142 * V_143 )
{
unsigned long V_144 , type ;
V_144 = ( V_143 -> V_40 & V_145 ) >>
V_146 ;
type = ( V_143 -> V_40 & V_147 ) >>
V_148 ;
switch ( V_144 ) {
case V_149 :
if ( ! V_22 )
return - V_116 ;
return F_112 ( V_6 , type , & V_143 -> V_150 , true ) ;
default:
return - V_151 ;
}
}
long F_113 ( struct V_36 * V_37 ,
unsigned int V_38 , unsigned long V_39 )
{
struct V_6 * V_6 = V_37 -> V_127 ;
void T_8 * V_128 = ( void T_8 * ) V_39 ;
switch ( V_38 ) {
case V_152 : {
if ( V_22 )
return F_114 ( V_6 ) ;
else
return - V_116 ;
}
case V_153 : {
struct V_142 V_143 ;
if ( F_104 ( & V_143 , V_128 , sizeof( V_143 ) ) )
return - V_130 ;
return F_111 ( V_6 , & V_143 ) ;
}
case V_154 : {
int V_41 ;
struct F_28 V_124 ;
V_41 = F_115 ( & V_124 ) ;
if ( V_41 )
return V_41 ;
if ( F_108 ( V_128 , & V_124 , sizeof( V_124 ) ) )
return - V_130 ;
return 0 ;
}
default:
return - V_8 ;
}
}
static void F_116 ( void * V_155 )
{
T_3 V_156 ;
T_3 V_157 ;
unsigned long V_158 ;
unsigned long V_159 ;
unsigned long V_160 ;
F_117 ( F_118 () ) ;
V_156 = F_119 () ;
V_157 = F_120 () ;
V_159 = F_6 ( V_161 ) ;
V_158 = V_159 + V_162 ;
V_160 = ( unsigned long ) V_163 ;
F_121 ( V_156 , V_157 , V_158 , V_160 ) ;
}
static int F_122 ( struct V_164 * V_165 ,
unsigned long V_166 , void * V_49 )
{
switch ( V_166 ) {
case V_167 :
case V_168 :
if ( F_123 () == V_169 )
F_116 ( NULL ) ;
break;
}
return V_170 ;
}
static int F_124 ( struct V_164 * V_165 ,
unsigned long V_171 ,
void * V_57 )
{
if ( V_171 == V_172 &&
F_123 () == V_169 ) {
F_116 ( NULL ) ;
return V_170 ;
}
return V_173 ;
}
static void T_9 F_125 ( void )
{
F_126 ( & V_174 ) ;
}
static inline void F_125 ( void )
{
}
static int F_127 ( void )
{
int V_49 ;
int V_41 = 0 ;
V_41 = F_128 () ;
if ( V_41 )
goto V_175;
V_169 = F_123 () ;
F_129 (cpu) {
unsigned long V_159 ;
V_159 = F_130 ( V_43 ) ;
if ( ! V_159 ) {
V_41 = - V_44 ;
goto V_176;
}
F_131 ( V_161 , V_49 ) = V_159 ;
}
V_41 = F_15 ( V_177 , V_178 ) ;
if ( V_41 ) {
F_132 ( L_1 ) ;
goto V_179;
}
F_129 (cpu) {
char * V_159 = ( char * ) F_131 ( V_161 , V_49 ) ;
V_41 = F_15 ( V_159 , V_159 + V_162 ) ;
if ( V_41 ) {
F_132 ( L_2 ) ;
goto V_179;
}
}
V_51 = F_133 ( V_180 ) ;
if ( ! V_51 ) {
V_41 = - V_44 ;
F_132 ( L_3 ) ;
goto V_179;
}
F_129 (cpu) {
V_180 * V_181 ;
V_181 = F_134 ( V_51 , V_49 ) ;
V_41 = F_15 ( V_181 , V_181 + 1 ) ;
if ( V_41 ) {
F_132 ( L_4 , V_41 ) ;
goto V_182;
}
}
F_135 ( F_116 , NULL , 1 ) ;
V_41 = F_136 () ;
if ( V_41 )
goto V_182;
#ifdef F_137
V_22 = true ;
#endif
V_41 = F_138 () ;
if ( V_41 )
goto V_179;
#ifndef F_139
F_140 () ;
#endif
F_141 () ;
F_142 ( L_5 ) ;
return 0 ;
V_182:
F_143 ( V_51 ) ;
V_179:
F_144 () ;
V_176:
F_129 (cpu)
F_145 ( F_131 ( V_161 , V_49 ) ) ;
V_175:
F_132 ( L_6 , V_41 ) ;
return V_41 ;
}
static void F_146 ( void * V_7 )
{
* ( int * ) V_7 = F_147 () ;
}
int F_148 ( void * V_183 )
{
int V_41 ;
int V_7 , V_49 ;
if ( ! F_149 () ) {
F_132 ( L_7 ) ;
return - V_151 ;
}
F_150 (cpu) {
F_151 ( V_49 , F_146 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_132 ( L_8 , V_49 ) ;
return - V_151 ;
}
}
F_152 () ;
V_41 = F_127 () ;
if ( V_41 )
goto V_175;
V_41 = F_153 ( & V_184 ) ;
if ( V_41 ) {
F_132 ( L_9 , V_41 ) ;
goto V_175;
}
F_154 () ;
F_125 () ;
F_155 () ;
return 0 ;
V_175:
F_154 () ;
return V_41 ;
}
void F_156 ( void )
{
F_157 () ;
}
static int F_158 ( void )
{
int V_185 = F_159 ( NULL , sizeof( struct V_1 ) , 0 , V_186 ) ;
return V_185 ;
}
