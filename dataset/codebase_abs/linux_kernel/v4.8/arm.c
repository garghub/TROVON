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
int F_8 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ) == V_4 ;
}
int F_10 ( void )
{
return 0 ;
}
void F_11 ( void * V_5 )
{
* ( int * ) V_5 = 0 ;
}
int F_12 ( struct V_6 * V_6 , unsigned long type )
{
int V_7 = 0 ;
if ( type )
return - V_8 ;
V_7 = F_13 ( V_6 ) ;
if ( V_7 )
goto V_9;
V_7 = F_14 ( V_6 , V_6 + 1 , V_10 ) ;
if ( V_7 )
goto V_11;
F_15 ( V_6 ) ;
F_16 ( V_6 ) ;
V_6 -> V_12 . V_13 = 0 ;
V_6 -> V_12 . V_14 = V_15 ?
F_17 () : V_16 ;
return V_7 ;
V_11:
F_18 ( V_6 ) ;
V_9:
return V_7 ;
}
int F_19 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
return V_19 ;
}
void F_20 ( struct V_6 * V_6 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_16 ; ++ V_20 ) {
if ( V_6 -> V_21 [ V_20 ] ) {
F_21 ( V_6 -> V_21 [ V_20 ] ) ;
V_6 -> V_21 [ V_20 ] = NULL ;
}
}
F_22 ( V_6 ) ;
}
int F_23 ( struct V_6 * V_6 , long V_22 )
{
int V_23 ;
switch ( V_22 ) {
case V_24 :
V_23 = V_15 ;
break;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
V_23 = 1 ;
break;
case V_35 :
V_23 = V_36 ;
break;
case V_37 :
V_23 = 1 ;
break;
case V_38 :
V_23 = F_24 () ;
break;
case V_39 :
V_23 = V_16 ;
break;
default:
V_23 = F_25 ( V_6 , V_22 ) ;
break;
}
return V_23 ;
}
long F_26 ( struct V_40 * V_41 ,
unsigned int V_42 , unsigned long V_43 )
{
return - V_8 ;
}
struct V_1 * F_27 ( struct V_6 * V_6 , unsigned int V_44 )
{
int V_45 ;
struct V_1 * V_2 ;
if ( F_28 ( V_6 ) && F_29 ( V_6 ) ) {
V_45 = - V_46 ;
goto V_47;
}
if ( V_44 >= V_6 -> V_12 . V_14 ) {
V_45 = - V_8 ;
goto V_47;
}
V_2 = F_30 ( V_48 , V_49 ) ;
if ( ! V_2 ) {
V_45 = - V_50 ;
goto V_47;
}
V_45 = F_31 ( V_2 , V_6 , V_44 ) ;
if ( V_45 )
goto V_51;
V_45 = F_14 ( V_2 , V_2 + 1 , V_10 ) ;
if ( V_45 )
goto V_52;
return V_2 ;
V_52:
F_32 ( V_2 ) ;
V_51:
F_33 ( V_48 , V_2 ) ;
V_47:
return F_34 ( V_45 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_48 , V_2 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
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
V_2 -> V_12 . V_53 = - 1 ;
F_49 ( V_2 -> V_12 . V_54 , V_55 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 , int V_56 )
{
V_2 -> V_56 = V_56 ;
V_2 -> V_12 . V_57 = F_53 ( V_58 ) ;
F_1 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
V_2 -> V_56 = - 1 ;
F_1 ( NULL ) ;
F_55 ( V_2 ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
if ( V_2 -> V_12 . V_61 )
V_60 -> V_60 = V_62 ;
else
V_60 -> V_60 = V_63 ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
switch ( V_60 -> V_60 ) {
case V_63 :
V_2 -> V_12 . V_61 = false ;
break;
case V_62 :
V_2 -> V_12 . V_61 = true ;
break;
default:
return - V_8 ;
}
return 0 ;
}
int F_58 ( struct V_1 * V_64 )
{
return ( ( ! ! V_64 -> V_12 . V_65 || F_59 ( V_64 ) )
&& ! V_64 -> V_12 . V_61 && ! V_64 -> V_12 . V_66 ) ;
}
static void F_60 ( void * V_67 )
{
}
void F_61 ( const T_2 * V_68 )
{
F_62 () ;
F_63 ( V_68 , F_60 , NULL , true ) ;
F_64 () ;
}
static bool F_65 ( struct V_6 * V_6 )
{
return F_66 ( V_6 -> V_12 . V_13 != F_67 ( & V_69 ) ) ;
}
static void F_68 ( struct V_6 * V_6 )
{
T_3 V_70 ;
T_4 V_71 ;
if ( ! F_65 ( V_6 ) )
return;
F_69 ( & V_72 ) ;
if ( ! F_65 ( V_6 ) ) {
F_70 ( & V_72 ) ;
return;
}
if ( F_66 ( V_73 == 0 ) ) {
F_71 ( & V_69 ) ;
V_73 = 1 ;
F_61 ( V_74 ) ;
F_72 ( V_75 ) ;
}
V_6 -> V_12 . V_13 = F_67 ( & V_69 ) ;
V_6 -> V_12 . V_71 = V_73 ;
V_73 ++ ;
V_73 &= ( 1 << V_76 ) - 1 ;
V_70 = F_73 ( V_6 -> V_12 . V_77 ) ;
F_2 ( V_70 & ~ V_78 ) ;
V_71 = ( ( T_4 ) ( V_6 -> V_12 . V_71 ) << V_79 ) & F_74 ( V_76 ) ;
V_6 -> V_12 . V_80 = V_70 | V_71 ;
F_70 ( & V_72 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
if ( F_76 ( V_2 -> V_12 . V_81 ) )
return 0 ;
V_2 -> V_12 . V_81 = true ;
if ( F_66 ( F_28 ( V_6 ) && ! F_77 ( V_6 ) ) ) {
V_7 = F_78 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
if ( F_28 ( V_6 ) && F_29 ( V_6 ) )
V_7 = F_79 ( V_2 ) ;
return V_7 ;
}
bool F_80 ( struct V_6 * V_6 )
{
return F_29 ( V_6 ) ;
}
void F_81 ( struct V_6 * V_6 )
{
int V_20 ;
struct V_1 * V_2 ;
F_82 (i, vcpu, kvm)
V_2 -> V_12 . V_66 = true ;
F_83 ( V_6 , V_82 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
V_2 -> V_12 . V_66 = true ;
F_85 ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = F_87 ( V_2 ) ;
V_2 -> V_12 . V_66 = false ;
F_88 ( V_84 ) ;
}
void F_89 ( struct V_6 * V_6 )
{
int V_20 ;
struct V_1 * V_2 ;
F_82 (i, vcpu, kvm)
F_86 ( V_2 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = F_87 ( V_2 ) ;
F_91 ( * V_84 , ( ( ! V_2 -> V_12 . V_61 ) &&
( ! V_2 -> V_12 . V_66 ) ) ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
return V_2 -> V_12 . V_53 >= 0 ;
}
int F_93 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
int V_7 ;
T_5 V_87 ;
if ( F_66 ( ! F_92 ( V_2 ) ) )
return - V_88 ;
V_7 = F_75 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_86 -> V_89 == V_90 ) {
V_7 = F_94 ( V_2 , V_2 -> V_86 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_91 )
F_95 ( V_92 , & V_2 -> V_93 , & V_87 ) ;
V_7 = 1 ;
V_86 -> V_89 = V_94 ;
while ( V_7 > 0 ) {
F_96 () ;
F_68 ( V_2 -> V_6 ) ;
if ( V_2 -> V_12 . V_61 || V_2 -> V_12 . V_66 )
F_90 ( V_2 ) ;
F_62 () ;
F_97 ( V_2 ) ;
F_98 ( V_2 ) ;
F_99 ( V_2 ) ;
F_100 () ;
if ( F_101 ( V_95 ) ) {
V_7 = - V_96 ;
V_86 -> V_89 = V_97 ;
}
if ( V_7 <= 0 || F_65 ( V_2 -> V_6 ) ||
V_2 -> V_12 . V_61 || V_2 -> V_12 . V_66 ) {
F_102 () ;
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
F_64 () ;
continue;
}
F_106 ( V_2 ) ;
F_107 ( * F_108 ( V_2 ) ) ;
F_109 () ;
V_2 -> V_98 = V_4 ;
V_7 = F_72 ( V_99 , V_2 ) ;
V_2 -> V_98 = V_100 ;
V_2 -> V_101 . V_102 ++ ;
F_110 ( V_2 ) ;
F_102 () ;
F_111 () ;
F_112 ( V_7 , F_113 ( V_2 ) , * F_108 ( V_2 ) ) ;
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
F_64 () ;
V_7 = F_114 ( V_2 , V_86 , V_7 ) ;
}
if ( V_2 -> V_91 )
F_95 ( V_92 , & V_87 , NULL ) ;
return V_7 ;
}
static int F_115 ( struct V_1 * V_2 , int V_103 , bool V_104 )
{
int V_105 ;
bool V_106 ;
unsigned long * V_107 ;
if ( V_103 == V_108 )
V_105 = F_116 ( V_109 ) ;
else
V_105 = F_116 ( V_110 ) ;
V_107 = ( unsigned long * ) & V_2 -> V_12 . V_65 ;
if ( V_104 )
V_106 = F_117 ( V_105 , V_107 ) ;
else
V_106 = F_118 ( V_105 , V_107 ) ;
if ( V_106 == V_104 )
return 0 ;
F_85 ( V_2 ) ;
return 0 ;
}
int F_119 ( struct V_6 * V_6 , struct V_111 * V_112 ,
bool V_113 )
{
T_6 V_114 = V_112 -> V_114 ;
unsigned int V_115 , V_116 , V_117 ;
int V_118 = F_120 ( & V_6 -> V_119 ) ;
struct V_1 * V_2 = NULL ;
bool V_104 = V_112 -> V_104 ;
V_115 = ( V_114 >> V_120 ) & V_121 ;
V_116 = ( V_114 >> V_122 ) & V_123 ;
V_117 = ( V_114 >> V_124 ) & V_125 ;
F_121 ( V_115 , V_116 , V_117 , V_112 -> V_104 ) ;
switch ( V_115 ) {
case V_126 :
if ( F_28 ( V_6 ) )
return - V_127 ;
if ( V_116 >= V_118 )
return - V_8 ;
V_2 = F_122 ( V_6 , V_116 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_117 > V_128 )
return - V_8 ;
return F_115 ( V_2 , V_117 , V_104 ) ;
case V_129 :
if ( ! F_28 ( V_6 ) )
return - V_127 ;
if ( V_116 >= V_118 )
return - V_8 ;
V_2 = F_122 ( V_6 , V_116 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_117 < V_130 || V_117 >= V_131 )
return - V_8 ;
return F_123 ( V_6 , V_2 -> V_132 , V_117 , V_104 ) ;
case V_133 :
if ( ! F_28 ( V_6 ) )
return - V_127 ;
if ( V_117 < V_131 )
return - V_8 ;
return F_123 ( V_6 , 0 , V_117 , V_104 ) ;
}
return - V_8 ;
}
static int F_124 ( struct V_1 * V_2 ,
const struct F_31 * V_134 )
{
unsigned int V_20 ;
int V_135 = F_125 () ;
if ( V_134 -> V_53 != V_135 )
return - V_8 ;
if ( V_2 -> V_12 . V_53 != - 1 && V_2 -> V_12 . V_53 != V_134 -> V_53 )
return - V_8 ;
for ( V_20 = 0 ; V_20 < sizeof( V_134 -> V_54 ) * 8 ; V_20 ++ ) {
bool V_106 = ( V_134 -> V_54 [ V_20 / 32 ] & ( 1 << ( V_20 % 32 ) ) ) ;
if ( V_106 && V_20 >= V_55 )
return - V_136 ;
if ( V_2 -> V_12 . V_53 != - 1 && V_20 < V_55 &&
F_126 ( V_20 , V_2 -> V_12 . V_54 ) != V_106 )
return - V_8 ;
if ( V_106 )
F_127 ( V_20 , V_2 -> V_12 . V_54 ) ;
}
V_2 -> V_12 . V_53 = V_135 ;
return F_128 ( V_2 ) ;
}
static int F_129 ( struct V_1 * V_2 ,
struct F_31 * V_134 )
{
int V_7 ;
V_7 = F_124 ( V_2 , V_134 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_12 . V_81 )
F_130 ( V_2 -> V_6 ) ;
F_131 ( V_2 ) ;
if ( F_126 ( V_137 , V_2 -> V_12 . V_54 ) )
V_2 -> V_12 . V_61 = true ;
else
V_2 -> V_12 . V_61 = false ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
int V_7 = - V_127 ;
switch ( V_139 -> V_140 ) {
default:
V_7 = F_133 ( V_2 , V_139 ) ;
break;
}
return V_7 ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
int V_7 = - V_127 ;
switch ( V_139 -> V_140 ) {
default:
V_7 = F_135 ( V_2 , V_139 ) ;
break;
}
return V_7 ;
}
static int F_136 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
int V_7 = - V_127 ;
switch ( V_139 -> V_140 ) {
default:
V_7 = F_137 ( V_2 , V_139 ) ;
break;
}
return V_7 ;
}
long F_138 ( struct V_40 * V_41 ,
unsigned int V_42 , unsigned long V_43 )
{
struct V_1 * V_2 = V_41 -> V_141 ;
void T_7 * V_142 = ( void T_7 * ) V_43 ;
struct V_138 V_139 ;
switch ( V_42 ) {
case V_143 : {
struct F_31 V_134 ;
if ( F_139 ( & V_134 , V_142 , sizeof( V_134 ) ) )
return - V_144 ;
return F_129 ( V_2 , & V_134 ) ;
}
case V_145 :
case V_146 : {
struct V_147 V_148 ;
if ( F_66 ( ! F_92 ( V_2 ) ) )
return - V_88 ;
if ( F_139 ( & V_148 , V_142 , sizeof( V_148 ) ) )
return - V_144 ;
if ( V_42 == V_145 )
return F_140 ( V_2 , & V_148 ) ;
else
return F_141 ( V_2 , & V_148 ) ;
}
case V_149 : {
struct V_150 T_7 * V_151 = V_142 ;
struct V_150 V_152 ;
unsigned V_153 ;
if ( F_66 ( ! F_92 ( V_2 ) ) )
return - V_88 ;
if ( F_139 ( & V_152 , V_151 , sizeof( V_152 ) ) )
return - V_144 ;
V_153 = V_152 . V_153 ;
V_152 . V_153 = F_142 ( V_2 ) ;
if ( F_143 ( V_151 , & V_152 , sizeof( V_152 ) ) )
return - V_144 ;
if ( V_153 < V_152 . V_153 )
return - V_154 ;
return F_144 ( V_2 , V_151 -> V_148 ) ;
}
case V_155 : {
if ( F_139 ( & V_139 , V_142 , sizeof( V_139 ) ) )
return - V_144 ;
return F_132 ( V_2 , & V_139 ) ;
}
case V_156 : {
if ( F_139 ( & V_139 , V_142 , sizeof( V_139 ) ) )
return - V_144 ;
return F_134 ( V_2 , & V_139 ) ;
}
case V_157 : {
if ( F_139 ( & V_139 , V_142 , sizeof( V_139 ) ) )
return - V_144 ;
return F_136 ( V_2 , & V_139 ) ;
}
default:
return - V_8 ;
}
}
int F_145 ( struct V_6 * V_6 , struct V_158 * log )
{
bool V_159 = false ;
int V_23 ;
F_146 ( & V_6 -> V_160 ) ;
V_23 = F_147 ( V_6 , log , & V_159 ) ;
if ( V_159 )
F_148 ( V_6 ) ;
F_149 ( & V_6 -> V_160 ) ;
return V_23 ;
}
static int F_150 ( struct V_6 * V_6 ,
struct V_161 * V_162 )
{
unsigned long V_163 , type ;
V_163 = ( V_162 -> V_44 & V_164 ) >>
V_165 ;
type = ( V_162 -> V_44 & V_166 ) >>
V_167 ;
switch ( V_163 ) {
case V_168 :
if ( ! V_15 )
return - V_127 ;
return F_151 ( V_6 , type , & V_162 -> V_169 , true ) ;
default:
return - V_170 ;
}
}
long F_152 ( struct V_40 * V_41 ,
unsigned int V_42 , unsigned long V_43 )
{
struct V_6 * V_6 = V_41 -> V_141 ;
void T_7 * V_142 = ( void T_7 * ) V_43 ;
switch ( V_42 ) {
case V_171 : {
int V_7 ;
if ( ! V_15 )
return - V_127 ;
F_146 ( & V_6 -> V_172 ) ;
V_7 = F_153 ( V_6 , V_173 ) ;
F_149 ( & V_6 -> V_172 ) ;
return V_7 ;
}
case V_174 : {
struct V_161 V_162 ;
if ( F_139 ( & V_162 , V_142 , sizeof( V_162 ) ) )
return - V_144 ;
return F_150 ( V_6 , & V_162 ) ;
}
case V_175 : {
int V_45 ;
struct F_31 V_134 ;
V_45 = F_154 ( & V_134 ) ;
if ( V_45 )
return V_45 ;
if ( F_143 ( V_142 , & V_134 , sizeof( V_134 ) ) )
return - V_144 ;
return 0 ;
}
default:
return - V_8 ;
}
}
static void F_155 ( void * V_176 )
{
T_3 V_177 ;
unsigned long V_178 ;
unsigned long V_179 ;
unsigned long V_180 ;
F_156 ( F_157 () ) ;
V_177 = F_158 () ;
V_179 = F_6 ( V_181 ) ;
V_178 = V_179 + V_182 ;
V_180 = ( unsigned long ) F_159 ( V_183 ) ;
F_160 ( V_177 , V_178 , V_180 ) ;
F_161 () ;
F_162 () ;
}
static void F_163 ( void )
{
if ( F_164 () ) {
F_161 () ;
} else {
if ( F_165 () == V_184 )
F_155 ( NULL ) ;
}
}
static void F_166 ( void )
{
if ( ! F_164 () )
F_167 ( V_184 ,
F_168 () ) ;
}
static void F_169 ( void * V_185 )
{
if ( ! F_6 ( V_186 ) ) {
F_163 () ;
F_4 ( V_186 , 1 ) ;
}
}
int F_170 ( void )
{
F_169 ( NULL ) ;
return 0 ;
}
static void F_171 ( void * V_185 )
{
if ( F_6 ( V_186 ) ) {
F_166 () ;
F_4 ( V_186 , 0 ) ;
}
}
void F_172 ( void )
{
F_171 ( NULL ) ;
}
static int F_173 ( struct V_187 * V_188 ,
unsigned long V_189 ,
void * V_64 )
{
switch ( V_189 ) {
case V_190 :
if ( F_6 ( V_186 ) )
F_166 () ;
return V_191 ;
case V_192 :
if ( F_6 ( V_186 ) )
F_163 () ;
return V_191 ;
default:
return V_193 ;
}
}
static void T_8 F_174 ( void )
{
F_175 ( & V_194 ) ;
}
static void T_8 F_176 ( void )
{
F_177 ( & V_194 ) ;
}
static inline void F_174 ( void )
{
}
static inline void F_176 ( void )
{
}
static void F_178 ( void )
{
F_179 ( V_58 ) ;
}
static int F_180 ( void )
{
V_58 = F_181 ( V_195 ) ;
if ( ! V_58 ) {
F_182 ( L_1 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_183 ( void )
{
int V_45 = 0 ;
F_184 ( F_169 , NULL , 1 ) ;
F_174 () ;
V_45 = F_185 () ;
switch ( V_45 ) {
case 0 :
V_15 = true ;
break;
case - V_170 :
case - V_127 :
V_15 = false ;
V_45 = 0 ;
break;
default:
goto V_47;
}
V_45 = F_186 () ;
if ( V_45 )
goto V_47;
F_187 () ;
F_188 () ;
V_47:
F_184 ( F_171 , NULL , 1 ) ;
return V_45 ;
}
static void F_189 ( void )
{
int V_56 ;
if ( F_164 () )
return;
F_190 () ;
F_191 (cpu)
F_192 ( F_193 ( V_181 , V_56 ) ) ;
F_176 () ;
}
static int F_194 ( void )
{
V_76 = F_195 () ;
F_196 ( L_2 , V_76 ) ;
F_196 ( L_3 ) ;
return 0 ;
}
static int F_197 ( void )
{
int V_56 ;
int V_45 = 0 ;
V_45 = F_198 () ;
if ( V_45 )
goto V_196;
V_184 = F_165 () ;
F_191 (cpu) {
unsigned long V_179 ;
V_179 = F_199 ( V_49 ) ;
if ( ! V_179 ) {
V_45 = - V_50 ;
goto V_196;
}
F_193 ( V_181 , V_56 ) = V_179 ;
}
V_45 = F_14 ( F_159 ( V_197 ) ,
F_159 ( V_198 ) , V_199 ) ;
if ( V_45 ) {
F_182 ( L_4 ) ;
goto V_196;
}
V_45 = F_14 ( F_159 ( V_200 ) ,
F_159 ( V_201 ) , V_202 ) ;
if ( V_45 ) {
F_182 ( L_5 ) ;
goto V_196;
}
F_191 (cpu) {
char * V_179 = ( char * ) F_193 ( V_181 , V_56 ) ;
V_45 = F_14 ( V_179 , V_179 + V_182 ,
V_10 ) ;
if ( V_45 ) {
F_182 ( L_6 ) ;
goto V_196;
}
}
F_191 (cpu) {
V_195 * V_203 ;
V_203 = F_200 ( V_58 , V_56 ) ;
V_45 = F_14 ( V_203 , V_203 + 1 , V_10 ) ;
if ( V_45 ) {
F_182 ( L_7 , V_45 ) ;
goto V_196;
}
}
V_76 = F_195 () ;
F_196 ( L_2 , V_76 ) ;
F_196 ( L_8 ) ;
return 0 ;
V_196:
F_189 () ;
F_182 ( L_9 , V_45 ) ;
return V_45 ;
}
static void F_201 ( void * V_7 )
{
* ( int * ) V_7 = F_125 () ;
}
struct V_1 * F_202 ( struct V_6 * V_6 , unsigned long V_204 )
{
struct V_1 * V_2 ;
int V_20 ;
V_204 &= V_205 ;
F_82 (i, vcpu, kvm) {
if ( V_204 == F_203 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_204 ( void * V_206 )
{
int V_45 ;
int V_7 , V_56 ;
if ( ! F_205 () ) {
F_182 ( L_10 ) ;
return - V_170 ;
}
F_206 (cpu) {
F_207 ( V_56 , F_201 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_182 ( L_11 , V_56 ) ;
return - V_170 ;
}
}
V_45 = F_180 () ;
if ( V_45 )
return V_45 ;
if ( F_164 () )
V_45 = F_194 () ;
else
V_45 = F_197 () ;
if ( V_45 )
goto V_196;
V_45 = F_183 () ;
if ( V_45 )
goto V_207;
return 0 ;
V_207:
F_189 () ;
V_196:
F_178 () ;
return V_45 ;
}
void F_208 ( void )
{
F_209 () ;
}
static int F_210 ( void )
{
int V_208 = F_211 ( NULL , sizeof( struct V_1 ) , 0 , V_209 ) ;
return V_208 ;
}
