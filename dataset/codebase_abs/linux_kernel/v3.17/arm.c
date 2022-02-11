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
void F_22 ( struct V_7 * V_7 )
{
int V_17 ;
F_20 ( V_7 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; ++ V_17 ) {
if ( V_7 -> V_19 [ V_17 ] ) {
F_23 ( V_7 -> V_19 [ V_17 ] ) ;
V_7 -> V_19 [ V_17 ] = NULL ;
}
}
}
int F_24 ( struct V_7 * V_7 , long V_20 )
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
V_21 = 1 ;
break;
case V_31 :
V_21 = V_32 ;
break;
case V_33 :
V_21 = 1 ;
break;
case V_34 :
V_21 = F_25 () ;
break;
case V_35 :
V_21 = V_18 ;
break;
default:
V_21 = F_26 ( V_20 ) ;
break;
}
return V_21 ;
}
long F_27 ( struct V_36 * V_37 ,
unsigned int V_38 , unsigned long V_39 )
{
return - V_9 ;
}
struct V_1 * F_28 ( struct V_7 * V_7 , unsigned int V_40 )
{
int V_41 ;
struct V_1 * V_2 ;
V_2 = F_29 ( V_42 , V_43 ) ;
if ( ! V_2 ) {
V_41 = - V_44 ;
goto V_45;
}
V_41 = F_30 ( V_2 , V_7 , V_40 ) ;
if ( V_41 )
goto V_46;
V_41 = F_18 ( V_2 , V_2 + 1 ) ;
if ( V_41 )
goto V_47;
return V_2 ;
V_47:
F_31 ( V_2 ) ;
V_46:
F_32 ( V_42 , V_2 ) ;
V_45:
return F_33 ( V_41 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_32 ( V_42 , V_2 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_12 . V_48 = - 1 ;
V_8 = F_40 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_41 ( V_2 ) ;
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
}
void F_43 ( struct V_1 * V_2 , int V_49 )
{
V_2 -> V_49 = V_49 ;
V_2 -> V_12 . V_50 = F_44 ( V_51 ) ;
if ( F_45 ( V_49 , & V_2 -> V_12 . V_52 ) )
F_46 () ;
F_1 ( V_2 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_49 = - 1 ;
F_1 ( NULL ) ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
return - V_9 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
return - V_9 ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
return - V_9 ;
}
int F_51 ( struct V_1 * V_57 )
{
return ! ! V_57 -> V_12 . V_58 || F_52 ( V_57 ) ;
}
static void F_53 ( void * V_59 )
{
}
void F_54 ( const T_2 * V_60 )
{
F_55 ( V_60 , F_53 , NULL , true ) ;
}
static bool F_56 ( struct V_7 * V_7 )
{
return F_57 ( V_7 -> V_12 . V_13 != F_58 ( & V_61 ) ) ;
}
static void F_59 ( struct V_7 * V_7 )
{
T_3 V_62 ;
T_4 V_63 ;
if ( ! F_56 ( V_7 ) )
return;
F_60 ( & V_64 ) ;
if ( ! F_56 ( V_7 ) ) {
F_61 ( & V_64 ) ;
return;
}
if ( F_57 ( V_65 == 0 ) ) {
F_62 ( & V_61 ) ;
V_65 = 1 ;
F_54 ( V_66 ) ;
F_63 ( V_67 ) ;
}
V_7 -> V_12 . V_13 = F_58 ( & V_61 ) ;
V_7 -> V_12 . V_63 = V_65 ;
V_65 ++ ;
V_62 = F_64 ( V_7 -> V_12 . V_68 ) ;
V_63 = ( ( T_4 ) ( V_7 -> V_12 . V_63 ) << V_69 ) & V_70 ;
V_7 -> V_12 . V_71 = V_62 & V_72 ;
V_7 -> V_12 . V_71 |= V_63 ;
F_61 ( & V_64 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_8 ;
if ( F_66 ( V_2 -> V_12 . V_73 ) )
return 0 ;
V_2 -> V_12 . V_73 = true ;
if ( F_57 ( ! F_67 ( V_2 -> V_7 ) ) ) {
V_8 = F_68 ( V_2 -> V_7 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_5 * V_74 = F_70 ( V_2 ) ;
F_71 ( * V_74 , ! V_2 -> V_12 . V_75 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
return V_2 -> V_12 . V_48 >= 0 ;
}
int F_73 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
int V_8 ;
T_6 V_78 ;
if ( F_57 ( ! F_72 ( V_2 ) ) )
return - V_79 ;
V_8 = F_65 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( V_77 -> V_80 == V_81 ) {
V_8 = F_74 ( V_2 , V_2 -> V_77 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_2 -> V_82 )
F_75 ( V_83 , & V_2 -> V_84 , & V_78 ) ;
V_8 = 1 ;
V_77 -> V_80 = V_85 ;
while ( V_8 > 0 ) {
F_76 () ;
F_59 ( V_2 -> V_7 ) ;
if ( V_2 -> V_12 . V_75 )
F_69 ( V_2 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_79 () ;
if ( F_80 ( V_86 ) ) {
V_8 = - V_87 ;
V_77 -> V_80 = V_88 ;
}
if ( V_8 <= 0 || F_56 ( V_2 -> V_7 ) ) {
F_81 () ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
continue;
}
F_84 ( * F_85 ( V_2 ) ) ;
F_86 () ;
V_2 -> V_89 = V_5 ;
V_8 = F_63 ( V_90 , V_2 ) ;
V_2 -> V_89 = V_91 ;
V_2 -> V_12 . V_92 = F_87 () ;
F_88 () ;
F_89 ( * F_85 ( V_2 ) ) ;
F_81 () ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
V_8 = F_90 ( V_2 , V_77 , V_8 ) ;
}
if ( V_2 -> V_82 )
F_75 ( V_83 , & V_78 , NULL ) ;
return V_8 ;
}
static int F_91 ( struct V_1 * V_2 , int V_93 , bool V_94 )
{
int V_95 ;
bool V_96 ;
unsigned long * V_97 ;
if ( V_93 == V_98 )
V_95 = F_92 ( V_99 ) ;
else
V_95 = F_92 ( V_100 ) ;
V_97 = ( unsigned long * ) & V_2 -> V_12 . V_58 ;
if ( V_94 )
V_96 = F_93 ( V_95 , V_97 ) ;
else
V_96 = F_94 ( V_95 , V_97 ) ;
if ( V_96 == V_94 )
return 0 ;
F_95 ( V_2 ) ;
return 0 ;
}
int F_96 ( struct V_7 * V_7 , struct V_101 * V_102 ,
bool V_103 )
{
T_7 V_104 = V_102 -> V_104 ;
unsigned int V_105 , V_106 , V_107 ;
int V_108 = F_97 ( & V_7 -> V_109 ) ;
struct V_1 * V_2 = NULL ;
bool V_94 = V_102 -> V_94 ;
V_105 = ( V_104 >> V_110 ) & V_111 ;
V_106 = ( V_104 >> V_112 ) & V_113 ;
V_107 = ( V_104 >> V_114 ) & V_115 ;
F_98 ( V_105 , V_106 , V_107 , V_102 -> V_94 ) ;
switch ( V_105 ) {
case V_116 :
if ( F_99 ( V_7 ) )
return - V_117 ;
if ( V_106 >= V_108 )
return - V_9 ;
V_2 = F_100 ( V_7 , V_106 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_107 > V_118 )
return - V_9 ;
return F_91 ( V_2 , V_107 , V_94 ) ;
case V_119 :
if ( ! F_99 ( V_7 ) )
return - V_117 ;
if ( V_106 >= V_108 )
return - V_9 ;
V_2 = F_100 ( V_7 , V_106 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_107 < V_120 || V_107 >= V_121 )
return - V_9 ;
return F_101 ( V_7 , V_2 -> V_122 , V_107 , V_94 ) ;
case V_123 :
if ( ! F_99 ( V_7 ) )
return - V_117 ;
if ( V_107 < V_121 ||
V_107 > V_124 )
return - V_9 ;
return F_101 ( V_7 , 0 , V_107 , V_94 ) ;
}
return - V_9 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct F_30 * V_125 )
{
int V_8 ;
V_8 = F_103 ( V_2 , V_125 ) ;
if ( V_8 )
return V_8 ;
if ( F_104 ( V_126 , V_2 -> V_12 . V_127 ) )
V_2 -> V_12 . V_75 = true ;
return 0 ;
}
long F_105 ( struct V_36 * V_37 ,
unsigned int V_38 , unsigned long V_39 )
{
struct V_1 * V_2 = V_37 -> V_128 ;
void T_8 * V_129 = ( void T_8 * ) V_39 ;
switch ( V_38 ) {
case V_130 : {
struct F_30 V_125 ;
if ( F_106 ( & V_125 , V_129 , sizeof( V_125 ) ) )
return - V_131 ;
return F_102 ( V_2 , & V_125 ) ;
}
case V_132 :
case V_133 : {
struct V_134 V_135 ;
if ( F_57 ( ! F_72 ( V_2 ) ) )
return - V_79 ;
if ( F_106 ( & V_135 , V_129 , sizeof( V_135 ) ) )
return - V_131 ;
if ( V_38 == V_132 )
return F_107 ( V_2 , & V_135 ) ;
else
return F_108 ( V_2 , & V_135 ) ;
}
case V_136 : {
struct V_137 T_8 * V_138 = V_129 ;
struct V_137 V_139 ;
unsigned V_140 ;
if ( F_57 ( ! F_72 ( V_2 ) ) )
return - V_79 ;
if ( F_106 ( & V_139 , V_138 , sizeof( V_139 ) ) )
return - V_131 ;
V_140 = V_139 . V_140 ;
V_139 . V_140 = F_109 ( V_2 ) ;
if ( F_110 ( V_138 , & V_139 , sizeof( V_139 ) ) )
return - V_131 ;
if ( V_140 < V_139 . V_140 )
return - V_141 ;
return F_111 ( V_2 , V_138 -> V_135 ) ;
}
default:
return - V_9 ;
}
}
int F_112 ( struct V_7 * V_7 , struct V_142 * log )
{
return - V_9 ;
}
static int F_113 ( struct V_7 * V_7 ,
struct V_143 * V_144 )
{
unsigned long V_145 , type ;
V_145 = ( V_144 -> V_40 & V_146 ) >>
V_147 ;
type = ( V_144 -> V_40 & V_148 ) >>
V_149 ;
switch ( V_145 ) {
case V_150 :
if ( ! V_23 )
return - V_117 ;
return F_114 ( V_7 , type , & V_144 -> V_151 , true ) ;
default:
return - V_152 ;
}
}
long F_115 ( struct V_36 * V_37 ,
unsigned int V_38 , unsigned long V_39 )
{
struct V_7 * V_7 = V_37 -> V_128 ;
void T_8 * V_129 = ( void T_8 * ) V_39 ;
switch ( V_38 ) {
case V_153 : {
if ( V_23 )
return F_116 ( V_7 ) ;
else
return - V_117 ;
}
case V_154 : {
struct V_143 V_144 ;
if ( F_106 ( & V_144 , V_129 , sizeof( V_144 ) ) )
return - V_131 ;
return F_113 ( V_7 , & V_144 ) ;
}
case V_155 : {
int V_41 ;
struct F_30 V_125 ;
V_41 = F_117 ( & V_125 ) ;
if ( V_41 )
return V_41 ;
if ( F_110 ( V_129 , & V_125 , sizeof( V_125 ) ) )
return - V_131 ;
return 0 ;
}
default:
return - V_9 ;
}
}
static void F_118 ( void * V_156 )
{
T_3 V_157 ;
T_3 V_158 ;
unsigned long V_159 ;
unsigned long V_160 ;
unsigned long V_161 ;
F_119 ( F_120 () ) ;
V_157 = F_121 () ;
V_158 = F_122 () ;
V_160 = F_6 ( V_162 ) ;
V_159 = V_160 + V_163 ;
V_161 = ( unsigned long ) V_164 ;
F_123 ( V_157 , V_158 , V_159 , V_161 ) ;
}
static int F_124 ( struct V_165 * V_166 ,
unsigned long V_167 , void * V_49 )
{
switch ( V_167 ) {
case V_168 :
case V_169 :
F_118 ( NULL ) ;
break;
}
return V_170 ;
}
static int F_125 ( struct V_165 * V_166 ,
unsigned long V_171 ,
void * V_57 )
{
if ( V_171 == V_172 &&
F_126 () == V_173 ) {
F_118 ( NULL ) ;
return V_170 ;
}
return V_174 ;
}
static void T_9 F_127 ( void )
{
F_128 ( & V_175 ) ;
}
static inline void F_127 ( void )
{
}
static int F_129 ( void )
{
int V_49 ;
int V_41 = 0 ;
V_41 = F_130 () ;
if ( V_41 )
goto V_176;
V_173 = F_126 () ;
F_131 (cpu) {
unsigned long V_160 ;
V_160 = F_132 ( V_43 ) ;
if ( ! V_160 ) {
V_41 = - V_44 ;
goto V_177;
}
F_133 ( V_162 , V_49 ) = V_160 ;
}
V_41 = F_18 ( V_178 , V_179 ) ;
if ( V_41 ) {
F_134 ( L_1 ) ;
goto V_180;
}
F_131 (cpu) {
char * V_160 = ( char * ) F_133 ( V_162 , V_49 ) ;
V_41 = F_18 ( V_160 , V_160 + V_163 ) ;
if ( V_41 ) {
F_134 ( L_2 ) ;
goto V_180;
}
}
V_51 = F_135 ( V_181 ) ;
if ( ! V_51 ) {
V_41 = - V_44 ;
F_134 ( L_3 ) ;
goto V_180;
}
F_131 (cpu) {
V_181 * V_182 ;
V_182 = F_136 ( V_51 , V_49 ) ;
V_41 = F_18 ( V_182 , V_182 + 1 ) ;
if ( V_41 ) {
F_134 ( L_4 , V_41 ) ;
goto V_183;
}
}
F_137 ( F_118 , NULL , 1 ) ;
V_41 = F_138 () ;
if ( V_41 )
goto V_183;
#ifdef F_139
V_23 = true ;
#endif
V_41 = F_140 () ;
if ( V_41 )
goto V_180;
#ifndef F_141
F_142 () ;
#endif
F_143 () ;
F_144 ( L_5 ) ;
return 0 ;
V_183:
F_145 ( V_51 ) ;
V_180:
F_146 () ;
V_177:
F_131 (cpu)
F_147 ( F_133 ( V_162 , V_49 ) ) ;
V_176:
F_134 ( L_6 , V_41 ) ;
return V_41 ;
}
static void F_148 ( void * V_8 )
{
* ( int * ) V_8 = F_149 () ;
}
int F_150 ( void * V_184 )
{
int V_41 ;
int V_8 , V_49 ;
if ( ! F_151 () ) {
F_134 ( L_7 ) ;
return - V_152 ;
}
F_152 (cpu) {
F_153 ( V_49 , F_148 , & V_8 , 1 ) ;
if ( V_8 < 0 ) {
F_134 ( L_8 , V_49 ) ;
return - V_152 ;
}
}
F_154 () ;
V_41 = F_129 () ;
if ( V_41 )
goto V_176;
V_41 = F_155 ( & V_185 ) ;
if ( V_41 ) {
F_134 ( L_9 , V_41 ) ;
goto V_176;
}
F_156 () ;
F_127 () ;
F_157 () ;
return 0 ;
V_176:
F_156 () ;
return V_41 ;
}
void F_158 ( void )
{
F_159 () ;
}
static int F_160 ( void )
{
int V_186 = F_161 ( NULL , sizeof( struct V_1 ) , 0 , V_187 ) ;
return V_186 ;
}
