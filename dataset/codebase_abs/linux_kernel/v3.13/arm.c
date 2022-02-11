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
V_7 -> V_12 . V_13 = 0 ;
return V_8 ;
V_11:
F_19 ( V_7 ) ;
V_10:
return V_8 ;
}
int F_20 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
return V_16 ;
}
void F_21 ( struct V_7 * V_7 , struct V_17 * free ,
struct V_17 * V_18 )
{
}
int F_22 ( struct V_7 * V_7 , struct V_17 * V_19 ,
unsigned long V_20 )
{
return 0 ;
}
void F_23 ( struct V_7 * V_7 )
{
int V_21 ;
F_19 ( V_7 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; ++ V_21 ) {
if ( V_7 -> V_23 [ V_21 ] ) {
F_24 ( V_7 -> V_23 [ V_21 ] ) ;
V_7 -> V_23 [ V_21 ] = NULL ;
}
}
}
int F_25 ( long V_24 )
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
V_25 = F_26 () ;
break;
case V_37 :
V_25 = V_22 ;
break;
default:
V_25 = F_27 ( V_24 ) ;
break;
}
return V_25 ;
}
long F_28 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
return - V_9 ;
}
void F_29 ( struct V_7 * V_7 )
{
}
int F_30 ( struct V_7 * V_7 ,
struct V_17 * V_42 ,
struct V_43 * V_44 ,
enum V_45 V_46 )
{
return 0 ;
}
void F_31 ( struct V_7 * V_7 ,
struct V_43 * V_44 ,
const struct V_17 * V_47 ,
enum V_45 V_46 )
{
}
void F_32 ( struct V_7 * V_7 )
{
}
void F_33 ( struct V_7 * V_7 ,
struct V_17 * V_19 )
{
}
struct V_1 * F_34 ( struct V_7 * V_7 , unsigned int V_48 )
{
int V_49 ;
struct V_1 * V_2 ;
V_2 = F_35 ( V_50 , V_51 ) ;
if ( ! V_2 ) {
V_49 = - V_52 ;
goto V_53;
}
V_49 = F_36 ( V_2 , V_7 , V_48 ) ;
if ( V_49 )
goto V_54;
V_49 = F_18 ( V_2 , V_2 + 1 ) ;
if ( V_49 )
goto V_55;
return V_2 ;
V_55:
F_37 ( V_2 ) ;
V_54:
F_38 ( V_50 , V_2 ) ;
V_53:
return F_39 ( V_49 ) ;
}
int F_40 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_38 ( V_50 , V_2 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_12 . V_56 = - 1 ;
V_8 = F_46 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_47 ( V_2 ) ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
}
void F_49 ( struct V_1 * V_2 , int V_57 )
{
V_2 -> V_57 = V_57 ;
V_2 -> V_12 . V_58 = F_50 ( V_59 ) ;
if ( F_51 ( V_57 , & V_2 -> V_12 . V_60 ) )
F_52 () ;
F_1 ( V_2 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
F_1 ( NULL ) ;
}
int F_54 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
return - V_9 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
return - V_9 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
return - V_9 ;
}
int F_57 ( struct V_1 * V_65 )
{
return ! ! V_65 -> V_12 . V_66 || F_58 ( V_65 ) ;
}
static void F_59 ( void * V_67 )
{
}
void F_60 ( const T_2 * V_68 )
{
F_61 ( V_68 , F_59 , NULL , true ) ;
}
static bool F_62 ( struct V_7 * V_7 )
{
return F_63 ( V_7 -> V_12 . V_13 != F_64 ( & V_69 ) ) ;
}
static void F_65 ( struct V_7 * V_7 )
{
T_3 V_70 ;
T_4 V_71 ;
if ( ! F_62 ( V_7 ) )
return;
F_66 ( & V_72 ) ;
if ( ! F_62 ( V_7 ) ) {
F_67 ( & V_72 ) ;
return;
}
if ( F_63 ( V_73 == 0 ) ) {
F_68 ( & V_69 ) ;
V_73 = 1 ;
F_60 ( V_74 ) ;
F_69 ( V_75 ) ;
}
V_7 -> V_12 . V_13 = F_64 ( & V_69 ) ;
V_7 -> V_12 . V_71 = V_73 ;
V_73 ++ ;
V_70 = F_70 ( V_7 -> V_12 . V_76 ) ;
V_71 = ( ( T_4 ) ( V_7 -> V_12 . V_71 ) << V_77 ) & V_78 ;
V_7 -> V_12 . V_79 = V_70 & V_80 ;
V_7 -> V_12 . V_79 |= V_71 ;
F_67 ( & V_72 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
if ( F_72 ( V_2 -> V_12 . V_81 ) )
return 0 ;
V_2 -> V_12 . V_81 = true ;
if ( F_73 ( V_2 -> V_7 ) &&
F_63 ( ! F_74 ( V_2 -> V_7 ) ) ) {
int V_8 = F_75 ( V_2 -> V_7 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_76 ( V_82 , V_2 -> V_12 . V_83 ) ) {
* F_77 ( V_2 , 0 ) = V_84 ;
F_78 ( V_2 ) ;
}
return 0 ;
}
static void F_79 ( struct V_1 * V_2 )
{
T_5 * V_85 = F_80 ( V_2 ) ;
F_81 ( * V_85 , ! V_2 -> V_12 . V_86 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
return V_2 -> V_12 . V_56 >= 0 ;
}
int F_83 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
int V_8 ;
T_6 V_89 ;
if ( F_63 ( ! F_82 ( V_2 ) ) )
return - V_90 ;
V_8 = F_71 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( V_88 -> V_91 == V_92 ) {
V_8 = F_84 ( V_2 , V_2 -> V_88 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_2 -> V_93 )
F_85 ( V_94 , & V_2 -> V_95 , & V_89 ) ;
V_8 = 1 ;
V_88 -> V_91 = V_96 ;
while ( V_8 > 0 ) {
F_86 () ;
F_65 ( V_2 -> V_7 ) ;
if ( V_2 -> V_12 . V_86 )
F_79 ( V_2 ) ;
F_87 ( V_2 ) ;
F_88 ( V_2 ) ;
F_89 () ;
if ( F_90 ( V_97 ) ) {
V_8 = - V_98 ;
V_88 -> V_91 = V_99 ;
}
if ( V_8 <= 0 || F_62 ( V_2 -> V_7 ) ) {
F_91 () ;
F_92 ( V_2 ) ;
F_93 ( V_2 ) ;
continue;
}
F_94 ( * F_95 ( V_2 ) ) ;
F_96 () ;
V_2 -> V_100 = V_5 ;
V_8 = F_69 ( V_101 , V_2 ) ;
V_2 -> V_100 = V_102 ;
V_2 -> V_12 . V_103 = F_97 () ;
F_98 () ;
F_99 ( * F_95 ( V_2 ) ) ;
F_91 () ;
F_92 ( V_2 ) ;
F_93 ( V_2 ) ;
V_8 = F_100 ( V_2 , V_88 , V_8 ) ;
}
if ( V_2 -> V_93 )
F_85 ( V_94 , & V_89 , NULL ) ;
return V_8 ;
}
static int F_101 ( struct V_1 * V_2 , int V_104 , bool V_105 )
{
int V_106 ;
bool V_107 ;
unsigned long * V_108 ;
if ( V_104 == V_109 )
V_106 = F_102 ( V_110 ) ;
else
V_106 = F_102 ( V_111 ) ;
V_108 = ( unsigned long * ) & V_2 -> V_12 . V_66 ;
if ( V_105 )
V_107 = F_103 ( V_106 , V_108 ) ;
else
V_107 = F_76 ( V_106 , V_108 ) ;
if ( V_107 == V_105 )
return 0 ;
F_104 ( V_2 ) ;
return 0 ;
}
int F_105 ( struct V_7 * V_7 , struct V_112 * V_113 ,
bool V_114 )
{
T_7 V_115 = V_113 -> V_115 ;
unsigned int V_116 , V_117 , V_118 ;
int V_119 = F_106 ( & V_7 -> V_120 ) ;
struct V_1 * V_2 = NULL ;
bool V_105 = V_113 -> V_105 ;
V_116 = ( V_115 >> V_121 ) & V_122 ;
V_117 = ( V_115 >> V_123 ) & V_124 ;
V_118 = ( V_115 >> V_125 ) & V_126 ;
F_107 ( V_116 , V_117 , V_118 , V_113 -> V_105 ) ;
switch ( V_116 ) {
case V_127 :
if ( F_73 ( V_7 ) )
return - V_128 ;
if ( V_117 >= V_119 )
return - V_9 ;
V_2 = F_108 ( V_7 , V_117 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_118 > V_129 )
return - V_9 ;
return F_101 ( V_2 , V_118 , V_105 ) ;
case V_130 :
if ( ! F_73 ( V_7 ) )
return - V_128 ;
if ( V_117 >= V_119 )
return - V_9 ;
V_2 = F_108 ( V_7 , V_117 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_118 < V_131 || V_118 >= V_132 )
return - V_9 ;
return F_109 ( V_7 , V_2 -> V_133 , V_118 , V_105 ) ;
case V_134 :
if ( ! F_73 ( V_7 ) )
return - V_128 ;
if ( V_118 < V_132 ||
V_118 > V_135 )
return - V_9 ;
return F_109 ( V_7 , 0 , V_118 , V_105 ) ;
}
return - V_9 ;
}
long F_110 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_1 * V_2 = V_39 -> V_136 ;
void T_8 * V_137 = ( void T_8 * ) V_41 ;
switch ( V_40 ) {
case V_138 : {
struct F_36 V_139 ;
if ( F_111 ( & V_139 , V_137 , sizeof( V_139 ) ) )
return - V_140 ;
return F_112 ( V_2 , & V_139 ) ;
}
case V_141 :
case V_142 : {
struct V_143 V_144 ;
if ( F_63 ( ! F_82 ( V_2 ) ) )
return - V_90 ;
if ( F_111 ( & V_144 , V_137 , sizeof( V_144 ) ) )
return - V_140 ;
if ( V_40 == V_141 )
return F_113 ( V_2 , & V_144 ) ;
else
return F_114 ( V_2 , & V_144 ) ;
}
case V_145 : {
struct V_146 T_8 * V_147 = V_137 ;
struct V_146 V_148 ;
unsigned V_149 ;
if ( F_63 ( ! F_82 ( V_2 ) ) )
return - V_90 ;
if ( F_111 ( & V_148 , V_147 , sizeof( V_148 ) ) )
return - V_140 ;
V_149 = V_148 . V_149 ;
V_148 . V_149 = F_115 ( V_2 ) ;
if ( F_116 ( V_147 , & V_148 , sizeof( V_148 ) ) )
return - V_140 ;
if ( V_149 < V_148 . V_149 )
return - V_150 ;
return F_117 ( V_2 , V_147 -> V_144 ) ;
}
default:
return - V_9 ;
}
}
int F_118 ( struct V_7 * V_7 , struct V_151 * log )
{
return - V_9 ;
}
static int F_119 ( struct V_7 * V_7 ,
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
return F_120 ( V_7 , type , V_153 -> V_160 ) ;
default:
return - V_161 ;
}
}
long F_121 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_7 * V_7 = V_39 -> V_136 ;
void T_8 * V_137 = ( void T_8 * ) V_41 ;
switch ( V_40 ) {
case V_162 : {
if ( V_27 )
return F_122 ( V_7 ) ;
else
return - V_128 ;
}
case V_163 : {
struct V_152 V_153 ;
if ( F_111 ( & V_153 , V_137 , sizeof( V_153 ) ) )
return - V_140 ;
return F_119 ( V_7 , & V_153 ) ;
}
case V_164 : {
int V_49 ;
struct F_36 V_139 ;
V_49 = F_123 ( & V_139 ) ;
if ( V_49 )
return V_49 ;
if ( F_116 ( V_137 , & V_139 , sizeof( V_139 ) ) )
return - V_140 ;
return 0 ;
}
default:
return - V_9 ;
}
}
static void F_124 ( void * V_165 )
{
T_3 V_166 ;
T_3 V_167 ;
unsigned long V_168 ;
unsigned long V_169 ;
unsigned long V_170 ;
F_125 ( F_126 () ) ;
V_166 = F_127 () ;
V_167 = F_128 () ;
V_169 = F_6 ( V_171 ) ;
V_168 = V_169 + V_172 ;
V_170 = ( unsigned long ) V_173 ;
F_129 ( V_166 , V_167 , V_168 , V_170 ) ;
}
static int F_130 ( struct V_174 * V_175 ,
unsigned long V_176 , void * V_57 )
{
switch ( V_176 ) {
case V_177 :
case V_178 :
F_124 ( NULL ) ;
break;
}
return V_179 ;
}
static int F_131 ( void )
{
int V_57 ;
int V_49 = 0 ;
V_49 = F_132 () ;
if ( V_49 )
goto V_180;
V_181 = F_133 () ;
F_134 (cpu) {
unsigned long V_169 ;
V_169 = F_135 ( V_51 ) ;
if ( ! V_169 ) {
V_49 = - V_52 ;
goto V_182;
}
F_136 ( V_171 , V_57 ) = V_169 ;
}
V_49 = F_18 ( V_183 , V_184 ) ;
if ( V_49 ) {
F_137 ( L_1 ) ;
goto V_185;
}
F_134 (cpu) {
char * V_169 = ( char * ) F_136 ( V_171 , V_57 ) ;
V_49 = F_18 ( V_169 , V_169 + V_172 ) ;
if ( V_49 ) {
F_137 ( L_2 ) ;
goto V_185;
}
}
V_59 = F_138 ( V_186 ) ;
if ( ! V_59 ) {
V_49 = - V_52 ;
F_137 ( L_3 ) ;
goto V_185;
}
F_134 (cpu) {
V_186 * V_187 ;
V_187 = F_139 ( V_59 , V_57 ) ;
V_49 = F_18 ( V_187 , V_187 + 1 ) ;
if ( V_49 ) {
F_137 ( L_4 , V_49 ) ;
goto V_188;
}
}
F_140 ( F_124 , NULL , 1 ) ;
V_49 = F_141 () ;
if ( V_49 )
goto V_188;
#ifdef F_142
V_27 = true ;
#endif
V_49 = F_143 () ;
if ( V_49 )
goto V_185;
#ifndef F_144
F_145 () ;
#endif
F_146 () ;
F_147 ( L_5 ) ;
return 0 ;
V_188:
F_148 ( V_59 ) ;
V_185:
F_149 () ;
V_182:
F_134 (cpu)
F_150 ( F_136 ( V_171 , V_57 ) ) ;
V_180:
F_137 ( L_6 , V_49 ) ;
return V_49 ;
}
static void F_151 ( void * V_8 )
{
* ( int * ) V_8 = F_152 () ;
}
int F_153 ( void * V_189 )
{
int V_49 ;
int V_8 , V_57 ;
if ( ! F_154 () ) {
F_137 ( L_7 ) ;
return - V_161 ;
}
F_155 (cpu) {
F_156 ( V_57 , F_151 , & V_8 , 1 ) ;
if ( V_8 < 0 ) {
F_137 ( L_8 , V_57 ) ;
return - V_161 ;
}
}
V_49 = F_131 () ;
if ( V_49 )
goto V_180;
V_49 = F_157 ( & V_190 ) ;
if ( V_49 ) {
F_137 ( L_9 , V_49 ) ;
goto V_180;
}
F_158 () ;
return 0 ;
V_180:
return V_49 ;
}
void F_159 ( void )
{
F_160 () ;
}
static int F_161 ( void )
{
int V_191 = F_162 ( NULL , sizeof( struct V_1 ) , 0 , V_192 ) ;
return V_191 ;
}
