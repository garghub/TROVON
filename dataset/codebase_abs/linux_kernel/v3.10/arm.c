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
V_25 = F_26 ( V_24 ) ;
break;
}
return V_25 ;
}
long F_27 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
return - V_9 ;
}
int F_28 ( struct V_7 * V_7 ,
struct V_17 * V_42 ,
struct V_43 * V_44 ,
enum V_45 V_46 )
{
return 0 ;
}
void F_29 ( struct V_7 * V_7 ,
struct V_43 * V_44 ,
const struct V_17 * V_47 ,
enum V_45 V_46 )
{
}
void F_30 ( struct V_7 * V_7 )
{
}
void F_31 ( struct V_7 * V_7 ,
struct V_17 * V_19 )
{
}
struct V_1 * F_32 ( struct V_7 * V_7 , unsigned int V_48 )
{
int V_49 ;
struct V_1 * V_2 ;
V_2 = F_33 ( V_50 , V_51 ) ;
if ( ! V_2 ) {
V_49 = - V_52 ;
goto V_53;
}
V_49 = F_34 ( V_2 , V_7 , V_48 ) ;
if ( V_49 )
goto V_54;
V_49 = F_17 ( V_2 , V_2 + 1 ) ;
if ( V_49 )
goto V_55;
return V_2 ;
V_55:
F_35 ( V_2 ) ;
V_54:
F_36 ( V_50 , V_2 ) ;
V_53:
return F_37 ( V_49 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_36 ( V_50 , V_2 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
}
int F_42 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_43 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_12 . V_56 = - 1 ;
V_8 = F_44 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_45 ( V_2 ) ;
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
}
void F_47 ( struct V_1 * V_2 , int V_57 )
{
V_2 -> V_57 = V_57 ;
V_2 -> V_12 . V_58 = F_48 ( V_59 ) ;
if ( F_49 ( V_57 , & V_2 -> V_12 . V_60 ) )
F_50 () ;
F_1 ( V_2 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
F_1 ( NULL ) ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
return - V_9 ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
return - V_9 ;
}
int F_54 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
return - V_9 ;
}
int F_55 ( struct V_1 * V_65 )
{
return ! ! V_65 -> V_12 . V_66 || F_56 ( V_65 ) ;
}
static void F_57 ( void * V_67 )
{
}
void F_58 ( const T_2 * V_68 )
{
F_59 ( V_68 , F_57 , NULL , true ) ;
}
static bool F_60 ( struct V_7 * V_7 )
{
return F_61 ( V_7 -> V_12 . V_13 != F_62 ( & V_69 ) ) ;
}
static void F_63 ( struct V_7 * V_7 )
{
T_3 V_70 ;
T_4 V_71 ;
if ( ! F_60 ( V_7 ) )
return;
F_64 ( & V_72 ) ;
if ( ! F_60 ( V_7 ) ) {
F_65 ( & V_72 ) ;
return;
}
if ( F_61 ( V_73 == 0 ) ) {
F_66 ( & V_69 ) ;
V_73 = 1 ;
F_58 ( V_74 ) ;
F_67 ( V_75 ) ;
}
V_7 -> V_12 . V_13 = F_62 ( & V_69 ) ;
V_7 -> V_12 . V_71 = V_73 ;
V_73 ++ ;
V_70 = F_68 ( V_7 -> V_12 . V_76 ) ;
V_71 = ( ( T_4 ) ( V_7 -> V_12 . V_71 ) << V_77 ) & V_78 ;
V_7 -> V_12 . V_79 = V_70 & V_80 ;
V_7 -> V_12 . V_79 |= V_71 ;
F_65 ( & V_72 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
if ( F_70 ( V_2 -> V_12 . V_81 ) )
return 0 ;
V_2 -> V_12 . V_81 = true ;
if ( F_71 ( V_2 -> V_7 ) &&
F_61 ( ! F_72 ( V_2 -> V_7 ) ) ) {
int V_8 = F_73 ( V_2 -> V_7 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_74 ( V_82 , V_2 -> V_12 . V_83 ) ) {
* F_75 ( V_2 , 0 ) = V_84 ;
F_76 ( V_2 ) ;
}
return 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
T_5 * V_85 = F_78 ( V_2 ) ;
F_79 ( * V_85 , ! V_2 -> V_12 . V_86 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
return V_2 -> V_12 . V_56 >= 0 ;
}
int F_81 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
int V_8 ;
T_6 V_89 ;
if ( F_61 ( ! F_80 ( V_2 ) ) )
return - V_90 ;
V_8 = F_69 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( V_88 -> V_91 == V_92 ) {
V_8 = F_82 ( V_2 , V_2 -> V_88 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_2 -> V_93 )
F_83 ( V_94 , & V_2 -> V_95 , & V_89 ) ;
V_8 = 1 ;
V_88 -> V_91 = V_96 ;
while ( V_8 > 0 ) {
F_84 () ;
F_63 ( V_2 -> V_7 ) ;
if ( V_2 -> V_12 . V_86 )
F_77 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_87 () ;
if ( F_88 ( V_97 ) ) {
V_8 = - V_98 ;
V_88 -> V_91 = V_99 ;
}
if ( V_8 <= 0 || F_60 ( V_2 -> V_7 ) ) {
F_89 () ;
F_90 ( V_2 ) ;
F_91 ( V_2 ) ;
continue;
}
F_92 ( * F_93 ( V_2 ) ) ;
F_94 () ;
V_2 -> V_100 = V_5 ;
V_8 = F_67 ( V_101 , V_2 ) ;
V_2 -> V_100 = V_102 ;
V_2 -> V_12 . V_103 = F_95 () ;
F_96 () ;
F_97 ( * F_93 ( V_2 ) ) ;
F_89 () ;
F_90 ( V_2 ) ;
F_91 ( V_2 ) ;
V_8 = F_98 ( V_2 , V_88 , V_8 ) ;
}
if ( V_2 -> V_93 )
F_83 ( V_94 , & V_89 , NULL ) ;
return V_8 ;
}
static int F_99 ( struct V_1 * V_2 , int V_104 , bool V_105 )
{
int V_106 ;
bool V_107 ;
unsigned long * V_108 ;
if ( V_104 == V_109 )
V_106 = F_100 ( V_110 ) ;
else
V_106 = F_100 ( V_111 ) ;
V_108 = ( unsigned long * ) & V_2 -> V_12 . V_66 ;
if ( V_105 )
V_107 = F_101 ( V_106 , V_108 ) ;
else
V_107 = F_74 ( V_106 , V_108 ) ;
if ( V_107 == V_105 )
return 0 ;
F_102 ( V_2 ) ;
return 0 ;
}
int F_103 ( struct V_7 * V_7 , struct V_112 * V_113 ,
bool V_114 )
{
T_7 V_115 = V_113 -> V_115 ;
unsigned int V_116 , V_117 , V_118 ;
int V_119 = F_104 ( & V_7 -> V_120 ) ;
struct V_1 * V_2 = NULL ;
bool V_105 = V_113 -> V_105 ;
V_116 = ( V_115 >> V_121 ) & V_122 ;
V_117 = ( V_115 >> V_123 ) & V_124 ;
V_118 = ( V_115 >> V_125 ) & V_126 ;
F_105 ( V_116 , V_117 , V_118 , V_113 -> V_105 ) ;
switch ( V_116 ) {
case V_127 :
if ( F_71 ( V_7 ) )
return - V_128 ;
if ( V_117 >= V_119 )
return - V_9 ;
V_2 = F_106 ( V_7 , V_117 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_118 > V_129 )
return - V_9 ;
return F_99 ( V_2 , V_118 , V_105 ) ;
case V_130 :
if ( ! F_71 ( V_7 ) )
return - V_128 ;
if ( V_117 >= V_119 )
return - V_9 ;
V_2 = F_106 ( V_7 , V_117 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_118 < V_131 || V_118 >= V_132 )
return - V_9 ;
return F_107 ( V_7 , V_2 -> V_133 , V_118 , V_105 ) ;
case V_134 :
if ( ! F_71 ( V_7 ) )
return - V_128 ;
if ( V_118 < V_132 ||
V_118 > V_135 )
return - V_9 ;
return F_107 ( V_7 , 0 , V_118 , V_105 ) ;
}
return - V_9 ;
}
long F_108 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_1 * V_2 = V_39 -> V_136 ;
void T_8 * V_137 = ( void T_8 * ) V_41 ;
switch ( V_40 ) {
case V_138 : {
struct F_34 V_139 ;
if ( F_109 ( & V_139 , V_137 , sizeof( V_139 ) ) )
return - V_140 ;
return F_110 ( V_2 , & V_139 ) ;
}
case V_141 :
case V_142 : {
struct V_143 V_144 ;
if ( F_61 ( ! F_80 ( V_2 ) ) )
return - V_90 ;
if ( F_109 ( & V_144 , V_137 , sizeof( V_144 ) ) )
return - V_140 ;
if ( V_40 == V_141 )
return F_111 ( V_2 , & V_144 ) ;
else
return F_112 ( V_2 , & V_144 ) ;
}
case V_145 : {
struct V_146 T_8 * V_147 = V_137 ;
struct V_146 V_148 ;
unsigned V_149 ;
if ( F_61 ( ! F_80 ( V_2 ) ) )
return - V_90 ;
if ( F_109 ( & V_148 , V_147 , sizeof( V_148 ) ) )
return - V_140 ;
V_149 = V_148 . V_149 ;
V_148 . V_149 = F_113 ( V_2 ) ;
if ( F_114 ( V_147 , & V_148 , sizeof( V_148 ) ) )
return - V_140 ;
if ( V_149 < V_148 . V_149 )
return - V_150 ;
return F_115 ( V_2 , V_147 -> V_144 ) ;
}
default:
return - V_9 ;
}
}
int F_116 ( struct V_7 * V_7 , struct V_151 * log )
{
return - V_9 ;
}
static int F_117 ( struct V_7 * V_7 ,
struct V_152 * V_153 )
{
unsigned long V_154 , type ;
V_154 = ( V_153 -> V_48 & V_155 ) >>
V_156 ;
type = ( V_153 -> V_48 & V_157 ) >>
V_158 ;
switch ( V_154 ) {
case V_159 :
if ( ! V_27 )
return - V_128 ;
return F_118 ( V_7 , type , V_153 -> V_160 ) ;
default:
return - V_161 ;
}
}
long F_119 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_7 * V_7 = V_39 -> V_136 ;
void T_8 * V_137 = ( void T_8 * ) V_41 ;
switch ( V_40 ) {
case V_162 : {
if ( V_27 )
return F_120 ( V_7 ) ;
else
return - V_128 ;
}
case V_163 : {
struct V_152 V_153 ;
if ( F_109 ( & V_153 , V_137 , sizeof( V_153 ) ) )
return - V_140 ;
return F_117 ( V_7 , & V_153 ) ;
}
default:
return - V_9 ;
}
}
static void F_121 ( void * V_164 )
{
unsigned long long V_165 ;
unsigned long long V_166 ;
unsigned long V_167 ;
unsigned long V_168 ;
unsigned long V_169 ;
F_122 ( F_123 () ) ;
V_165 = ( unsigned long long ) F_124 () ;
V_166 = ( unsigned long long ) F_125 () ;
V_168 = F_4 ( V_170 ) ;
V_167 = V_168 + V_171 ;
V_169 = ( unsigned long ) V_172 ;
F_126 ( V_165 , V_166 , V_167 , V_169 ) ;
}
static int F_127 ( struct V_173 * V_174 ,
unsigned long V_175 , void * V_57 )
{
switch ( V_175 ) {
case V_176 :
case V_177 :
F_121 ( NULL ) ;
break;
}
return V_178 ;
}
static int F_128 ( void )
{
int V_57 ;
int V_49 = 0 ;
V_49 = F_129 () ;
if ( V_49 )
goto V_179;
V_180 = F_130 () ;
F_131 (cpu) {
unsigned long V_168 ;
V_168 = F_132 ( V_51 ) ;
if ( ! V_168 ) {
V_49 = - V_52 ;
goto V_181;
}
F_133 ( V_170 , V_57 ) = V_168 ;
}
V_49 = F_17 ( V_182 , V_183 ) ;
if ( V_49 ) {
F_134 ( L_1 ) ;
goto V_184;
}
F_131 (cpu) {
char * V_168 = ( char * ) F_133 ( V_170 , V_57 ) ;
V_49 = F_17 ( V_168 , V_168 + V_171 ) ;
if ( V_49 ) {
F_134 ( L_2 ) ;
goto V_184;
}
}
V_59 = F_135 ( V_185 ) ;
if ( ! V_59 ) {
V_49 = - V_52 ;
F_134 ( L_3 ) ;
goto V_184;
}
F_131 (cpu) {
V_185 * V_186 ;
V_186 = F_136 ( V_59 , V_57 ) ;
V_49 = F_17 ( V_186 , V_186 + 1 ) ;
if ( V_49 ) {
F_134 ( L_4 , V_49 ) ;
goto V_187;
}
}
F_137 ( F_121 , NULL , 1 ) ;
V_49 = F_138 () ;
if ( V_49 )
goto V_187;
#ifdef F_139
V_27 = true ;
#endif
V_49 = F_140 () ;
if ( V_49 )
goto V_184;
#ifndef F_141
F_142 () ;
#endif
F_143 () ;
F_144 ( L_5 ) ;
return 0 ;
V_187:
F_145 ( V_59 ) ;
V_184:
F_146 () ;
V_181:
F_131 (cpu)
F_147 ( F_133 ( V_170 , V_57 ) ) ;
V_179:
F_134 ( L_6 , V_49 ) ;
return V_49 ;
}
static void F_148 ( void * V_8 )
{
* ( int * ) V_8 = F_149 () ;
}
int F_150 ( void * V_188 )
{
int V_49 ;
int V_8 , V_57 ;
if ( ! F_151 () ) {
F_134 ( L_7 ) ;
return - V_161 ;
}
F_152 (cpu) {
F_153 ( V_57 , F_148 , & V_8 , 1 ) ;
if ( V_8 < 0 ) {
F_134 ( L_8 , V_57 ) ;
return - V_161 ;
}
}
V_49 = F_128 () ;
if ( V_49 )
goto V_179;
V_49 = F_154 ( & V_189 ) ;
if ( V_49 ) {
F_134 ( L_9 , V_49 ) ;
goto V_179;
}
F_155 () ;
return 0 ;
V_179:
return V_49 ;
}
void F_156 ( void )
{
F_157 () ;
}
static int F_158 ( void )
{
int V_190 = F_159 ( NULL , sizeof( struct V_1 ) , 0 , V_191 ) ;
return V_190 ;
}
