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
if ( F_27 ( V_6 ) && F_28 ( V_6 ) ) {
V_41 = - V_42 ;
goto V_43;
}
V_2 = F_29 ( V_44 , V_45 ) ;
if ( ! V_2 ) {
V_41 = - V_46 ;
goto V_43;
}
V_41 = F_30 ( V_2 , V_6 , V_40 ) ;
if ( V_41 )
goto V_47;
V_41 = F_15 ( V_2 , V_2 + 1 ) ;
if ( V_41 )
goto V_48;
return V_2 ;
V_48:
F_31 ( V_2 ) ;
V_47:
F_32 ( V_44 , V_2 ) ;
V_43:
return F_33 ( V_41 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_32 ( V_44 , V_2 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_49 = - 1 ;
F_41 ( V_2 -> V_11 . V_50 , V_51 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
void F_43 ( struct V_1 * V_2 , int V_52 )
{
V_2 -> V_52 = V_52 ;
V_2 -> V_11 . V_53 = F_44 ( V_54 ) ;
F_1 ( V_2 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
V_2 -> V_52 = - 1 ;
F_1 ( NULL ) ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
return - V_8 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
return - V_8 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
return - V_8 ;
}
int F_49 ( struct V_1 * V_59 )
{
return ! ! V_59 -> V_11 . V_60 || F_50 ( V_59 ) ;
}
static void F_51 ( void * V_61 )
{
}
void F_52 ( const T_2 * V_62 )
{
F_53 ( V_62 , F_51 , NULL , true ) ;
}
static bool F_54 ( struct V_6 * V_6 )
{
return F_55 ( V_6 -> V_11 . V_12 != F_56 ( & V_63 ) ) ;
}
static void F_57 ( struct V_6 * V_6 )
{
T_3 V_64 ;
T_4 V_65 ;
if ( ! F_54 ( V_6 ) )
return;
F_58 ( & V_66 ) ;
if ( ! F_54 ( V_6 ) ) {
F_59 ( & V_66 ) ;
return;
}
if ( F_55 ( V_67 == 0 ) ) {
F_60 ( & V_63 ) ;
V_67 = 1 ;
F_52 ( V_68 ) ;
F_61 ( V_69 ) ;
}
V_6 -> V_11 . V_12 = F_56 ( & V_63 ) ;
V_6 -> V_11 . V_65 = V_67 ;
V_67 ++ ;
V_64 = F_62 ( F_63 ( V_6 ) ) ;
F_2 ( V_64 & ~ V_70 ) ;
V_65 = ( ( T_4 ) ( V_6 -> V_11 . V_65 ) << V_71 ) & V_72 ;
V_6 -> V_11 . V_73 = V_64 | V_65 ;
F_59 ( & V_66 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 ;
if ( F_65 ( V_2 -> V_11 . V_74 ) )
return 0 ;
V_2 -> V_11 . V_74 = true ;
if ( F_55 ( ! F_66 ( V_6 ) ) ) {
V_7 = F_67 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
if ( F_27 ( V_6 ) && F_28 ( V_6 ) )
F_68 ( V_6 ) ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_5 * V_75 = F_70 ( V_2 ) ;
F_71 ( * V_75 , ! V_2 -> V_11 . V_76 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
return V_2 -> V_11 . V_49 >= 0 ;
}
int F_73 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
int V_7 ;
T_6 V_79 ;
if ( F_55 ( ! F_72 ( V_2 ) ) )
return - V_80 ;
V_7 = F_64 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_78 -> V_81 == V_82 ) {
V_7 = F_74 ( V_2 , V_2 -> V_78 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_83 )
F_75 ( V_84 , & V_2 -> V_85 , & V_79 ) ;
V_7 = 1 ;
V_78 -> V_81 = V_86 ;
while ( V_7 > 0 ) {
F_76 () ;
F_57 ( V_2 -> V_6 ) ;
if ( V_2 -> V_11 . V_76 )
F_69 ( V_2 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_79 () ;
if ( F_80 ( V_87 ) ) {
V_7 = - V_88 ;
V_78 -> V_81 = V_89 ;
}
if ( V_7 <= 0 || F_54 ( V_2 -> V_6 ) ) {
F_81 () ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
continue;
}
F_84 ( * F_85 ( V_2 ) ) ;
F_86 () ;
V_2 -> V_90 = V_4 ;
V_7 = F_61 ( V_91 , V_2 ) ;
V_2 -> V_90 = V_92 ;
F_87 () ;
F_88 ( * F_85 ( V_2 ) ) ;
F_81 () ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
V_7 = F_89 ( V_2 , V_78 , V_7 ) ;
}
if ( V_2 -> V_83 )
F_75 ( V_84 , & V_79 , NULL ) ;
return V_7 ;
}
static int F_90 ( struct V_1 * V_2 , int V_93 , bool V_94 )
{
int V_95 ;
bool V_96 ;
unsigned long * V_97 ;
if ( V_93 == V_98 )
V_95 = F_91 ( V_99 ) ;
else
V_95 = F_91 ( V_100 ) ;
V_97 = ( unsigned long * ) & V_2 -> V_11 . V_60 ;
if ( V_94 )
V_96 = F_92 ( V_95 , V_97 ) ;
else
V_96 = F_93 ( V_95 , V_97 ) ;
if ( V_96 == V_94 )
return 0 ;
F_94 ( V_2 ) ;
return 0 ;
}
int F_95 ( struct V_6 * V_6 , struct V_101 * V_102 ,
bool V_103 )
{
T_7 V_104 = V_102 -> V_104 ;
unsigned int V_105 , V_106 , V_107 ;
int V_108 = F_96 ( & V_6 -> V_109 ) ;
struct V_1 * V_2 = NULL ;
bool V_94 = V_102 -> V_94 ;
V_105 = ( V_104 >> V_110 ) & V_111 ;
V_106 = ( V_104 >> V_112 ) & V_113 ;
V_107 = ( V_104 >> V_114 ) & V_115 ;
F_97 ( V_105 , V_106 , V_107 , V_102 -> V_94 ) ;
switch ( V_105 ) {
case V_116 :
if ( F_27 ( V_6 ) )
return - V_117 ;
if ( V_106 >= V_108 )
return - V_8 ;
V_2 = F_98 ( V_6 , V_106 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_107 > V_118 )
return - V_8 ;
return F_90 ( V_2 , V_107 , V_94 ) ;
case V_119 :
if ( ! F_27 ( V_6 ) )
return - V_117 ;
if ( V_106 >= V_108 )
return - V_8 ;
V_2 = F_98 ( V_6 , V_106 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_107 < V_120 || V_107 >= V_121 )
return - V_8 ;
return F_99 ( V_6 , V_2 -> V_122 , V_107 , V_94 ) ;
case V_123 :
if ( ! F_27 ( V_6 ) )
return - V_117 ;
if ( V_107 < V_121 ||
V_107 > V_124 )
return - V_8 ;
return F_99 ( V_6 , 0 , V_107 , V_94 ) ;
}
return - V_8 ;
}
static int F_100 ( struct V_1 * V_2 ,
const struct F_30 * V_125 )
{
unsigned int V_16 ;
int V_126 = F_101 () ;
if ( V_125 -> V_49 != V_126 )
return - V_8 ;
if ( V_2 -> V_11 . V_49 != - 1 && V_2 -> V_11 . V_49 != V_125 -> V_49 )
return - V_8 ;
for ( V_16 = 0 ; V_16 < sizeof( V_125 -> V_50 ) * 8 ; V_16 ++ ) {
bool V_96 = ( V_125 -> V_50 [ V_16 / 32 ] & ( 1 << ( V_16 % 32 ) ) ) ;
if ( V_96 && V_16 >= V_51 )
return - V_127 ;
if ( V_2 -> V_11 . V_49 != - 1 && V_16 < V_51 &&
F_102 ( V_16 , V_2 -> V_11 . V_50 ) != V_96 )
return - V_8 ;
if ( V_96 )
F_103 ( V_16 , V_2 -> V_11 . V_50 ) ;
}
V_2 -> V_11 . V_49 = V_126 ;
return F_104 ( V_2 ) ;
}
static int F_105 ( struct V_1 * V_2 ,
struct F_30 * V_125 )
{
int V_7 ;
V_7 = F_100 ( V_2 , V_125 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_11 . V_74 )
F_106 ( V_2 -> V_6 ) ;
F_107 ( V_2 ) ;
if ( F_102 ( V_128 , V_2 -> V_11 . V_50 ) )
V_2 -> V_11 . V_76 = true ;
else
V_2 -> V_11 . V_76 = false ;
return 0 ;
}
long F_108 ( struct V_36 * V_37 ,
unsigned int V_38 , unsigned long V_39 )
{
struct V_1 * V_2 = V_37 -> V_129 ;
void T_8 * V_130 = ( void T_8 * ) V_39 ;
switch ( V_38 ) {
case V_131 : {
struct F_30 V_125 ;
if ( F_109 ( & V_125 , V_130 , sizeof( V_125 ) ) )
return - V_132 ;
return F_105 ( V_2 , & V_125 ) ;
}
case V_133 :
case V_134 : {
struct V_135 V_136 ;
if ( F_55 ( ! F_72 ( V_2 ) ) )
return - V_80 ;
if ( F_109 ( & V_136 , V_130 , sizeof( V_136 ) ) )
return - V_132 ;
if ( V_38 == V_133 )
return F_110 ( V_2 , & V_136 ) ;
else
return F_111 ( V_2 , & V_136 ) ;
}
case V_137 : {
struct V_138 T_8 * V_139 = V_130 ;
struct V_138 V_140 ;
unsigned V_141 ;
if ( F_55 ( ! F_72 ( V_2 ) ) )
return - V_80 ;
if ( F_109 ( & V_140 , V_139 , sizeof( V_140 ) ) )
return - V_132 ;
V_141 = V_140 . V_141 ;
V_140 . V_141 = F_112 ( V_2 ) ;
if ( F_113 ( V_139 , & V_140 , sizeof( V_140 ) ) )
return - V_132 ;
if ( V_141 < V_140 . V_141 )
return - V_142 ;
return F_114 ( V_2 , V_139 -> V_136 ) ;
}
default:
return - V_8 ;
}
}
int F_115 ( struct V_6 * V_6 , struct V_143 * log )
{
return - V_8 ;
}
static int F_116 ( struct V_6 * V_6 ,
struct V_144 * V_145 )
{
unsigned long V_146 , type ;
V_146 = ( V_145 -> V_40 & V_147 ) >>
V_148 ;
type = ( V_145 -> V_40 & V_149 ) >>
V_150 ;
switch ( V_146 ) {
case V_151 :
if ( ! V_22 )
return - V_117 ;
return F_117 ( V_6 , type , & V_145 -> V_152 , true ) ;
default:
return - V_153 ;
}
}
long F_118 ( struct V_36 * V_37 ,
unsigned int V_38 , unsigned long V_39 )
{
struct V_6 * V_6 = V_37 -> V_129 ;
void T_8 * V_130 = ( void T_8 * ) V_39 ;
switch ( V_38 ) {
case V_154 : {
if ( V_22 )
return F_119 ( V_6 ) ;
else
return - V_117 ;
}
case V_155 : {
struct V_144 V_145 ;
if ( F_109 ( & V_145 , V_130 , sizeof( V_145 ) ) )
return - V_132 ;
return F_116 ( V_6 , & V_145 ) ;
}
case V_156 : {
int V_41 ;
struct F_30 V_125 ;
V_41 = F_120 ( & V_125 ) ;
if ( V_41 )
return V_41 ;
if ( F_113 ( V_130 , & V_125 , sizeof( V_125 ) ) )
return - V_132 ;
return 0 ;
}
default:
return - V_8 ;
}
}
static void F_121 ( void * V_157 )
{
T_3 V_158 ;
T_3 V_159 ;
unsigned long V_160 ;
unsigned long V_161 ;
unsigned long V_162 ;
F_122 ( F_123 () ) ;
V_158 = F_124 () ;
V_159 = F_125 () ;
V_161 = F_6 ( V_163 ) ;
V_160 = V_161 + V_164 ;
V_162 = ( unsigned long ) V_165 ;
F_126 ( V_158 , V_159 , V_160 , V_162 ) ;
}
static int F_127 ( struct V_166 * V_167 ,
unsigned long V_168 , void * V_52 )
{
switch ( V_168 ) {
case V_169 :
case V_170 :
if ( F_128 () == V_171 )
F_121 ( NULL ) ;
break;
}
return V_172 ;
}
static int F_129 ( struct V_166 * V_167 ,
unsigned long V_173 ,
void * V_59 )
{
if ( V_173 == V_174 &&
F_128 () == V_171 ) {
F_121 ( NULL ) ;
return V_172 ;
}
return V_175 ;
}
static void T_9 F_130 ( void )
{
F_131 ( & V_176 ) ;
}
static inline void F_130 ( void )
{
}
static int F_132 ( void )
{
int V_52 ;
int V_41 = 0 ;
V_41 = F_133 () ;
if ( V_41 )
goto V_177;
V_171 = F_128 () ;
F_134 (cpu) {
unsigned long V_161 ;
V_161 = F_135 ( V_45 ) ;
if ( ! V_161 ) {
V_41 = - V_46 ;
goto V_178;
}
F_136 ( V_163 , V_52 ) = V_161 ;
}
V_41 = F_15 ( V_179 , V_180 ) ;
if ( V_41 ) {
F_137 ( L_1 ) ;
goto V_181;
}
F_134 (cpu) {
char * V_161 = ( char * ) F_136 ( V_163 , V_52 ) ;
V_41 = F_15 ( V_161 , V_161 + V_164 ) ;
if ( V_41 ) {
F_137 ( L_2 ) ;
goto V_181;
}
}
V_54 = F_138 ( V_182 ) ;
if ( ! V_54 ) {
V_41 = - V_46 ;
F_137 ( L_3 ) ;
goto V_181;
}
F_134 (cpu) {
V_182 * V_183 ;
V_183 = F_139 ( V_54 , V_52 ) ;
V_41 = F_15 ( V_183 , V_183 + 1 ) ;
if ( V_41 ) {
F_137 ( L_4 , V_41 ) ;
goto V_184;
}
}
F_140 ( F_121 , NULL , 1 ) ;
V_41 = F_141 () ;
if ( V_41 )
goto V_184;
#ifdef F_142
V_22 = true ;
#endif
V_41 = F_143 () ;
if ( V_41 )
goto V_181;
#ifndef F_144
F_145 () ;
#endif
F_146 () ;
F_147 ( L_5 ) ;
return 0 ;
V_184:
F_148 ( V_54 ) ;
V_181:
F_149 () ;
V_178:
F_134 (cpu)
F_150 ( F_136 ( V_163 , V_52 ) ) ;
V_177:
F_137 ( L_6 , V_41 ) ;
return V_41 ;
}
static void F_151 ( void * V_7 )
{
* ( int * ) V_7 = F_101 () ;
}
int F_152 ( void * V_185 )
{
int V_41 ;
int V_7 , V_52 ;
if ( ! F_153 () ) {
F_137 ( L_7 ) ;
return - V_153 ;
}
F_154 (cpu) {
F_155 ( V_52 , F_151 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_137 ( L_8 , V_52 ) ;
return - V_153 ;
}
}
F_156 () ;
V_41 = F_132 () ;
if ( V_41 )
goto V_177;
V_41 = F_157 ( & V_186 ) ;
if ( V_41 ) {
F_137 ( L_9 , V_41 ) ;
goto V_177;
}
F_158 () ;
F_130 () ;
F_159 () ;
return 0 ;
V_177:
F_158 () ;
return V_41 ;
}
void F_160 ( void )
{
F_161 () ;
}
static int F_162 ( void )
{
int V_187 = F_163 ( NULL , sizeof( struct V_1 ) , 0 , V_188 ) ;
return V_187 ;
}
