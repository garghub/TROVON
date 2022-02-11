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
int V_7 , V_8 ;
if ( type )
return - V_9 ;
V_6 -> V_10 . V_11 = F_13 ( F_14 ( * V_6 -> V_10 . V_11 ) ) ;
if ( ! V_6 -> V_10 . V_11 )
return - V_12 ;
F_15 ( V_8 )
* F_16 ( V_6 -> V_10 . V_11 , V_8 ) = - 1 ;
V_7 = F_17 ( V_6 ) ;
if ( V_7 )
goto V_13;
V_7 = F_18 ( V_6 , V_6 + 1 , V_14 ) ;
if ( V_7 )
goto V_15;
F_19 ( V_6 ) ;
F_20 ( V_6 ) ;
V_6 -> V_10 . V_16 = 0 ;
V_6 -> V_10 . V_17 = V_18 ?
F_21 () : V_19 ;
return V_7 ;
V_15:
F_22 ( V_6 ) ;
V_13:
F_23 ( V_6 -> V_10 . V_11 ) ;
V_6 -> V_10 . V_11 = NULL ;
return V_7 ;
}
bool F_24 ( void )
{
return false ;
}
int F_25 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_26 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
return V_22 ;
}
void F_27 ( struct V_6 * V_6 )
{
int V_23 ;
F_23 ( V_6 -> V_10 . V_11 ) ;
V_6 -> V_10 . V_11 = NULL ;
for ( V_23 = 0 ; V_23 < V_19 ; ++ V_23 ) {
if ( V_6 -> V_24 [ V_23 ] ) {
F_28 ( V_6 -> V_24 [ V_23 ] ) ;
V_6 -> V_24 [ V_23 ] = NULL ;
}
}
F_29 ( V_6 ) ;
}
int F_30 ( struct V_6 * V_6 , long V_25 )
{
int V_26 ;
switch ( V_25 ) {
case V_27 :
V_26 = V_18 ;
break;
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_26 = 1 ;
break;
case V_38 :
V_26 = V_39 ;
break;
case V_40 :
V_26 = 1 ;
break;
case V_41 :
V_26 = F_31 () ;
break;
case V_42 :
V_26 = V_19 ;
break;
default:
V_26 = F_32 ( V_6 , V_25 ) ;
break;
}
return V_26 ;
}
long F_33 ( struct V_43 * V_44 ,
unsigned int V_45 , unsigned long V_46 )
{
return - V_9 ;
}
struct V_1 * F_34 ( struct V_6 * V_6 , unsigned int V_47 )
{
int V_48 ;
struct V_1 * V_2 ;
if ( F_35 ( V_6 ) && F_36 ( V_6 ) ) {
V_48 = - V_49 ;
goto V_50;
}
if ( V_47 >= V_6 -> V_10 . V_17 ) {
V_48 = - V_9 ;
goto V_50;
}
V_2 = F_37 ( V_51 , V_52 ) ;
if ( ! V_2 ) {
V_48 = - V_12 ;
goto V_50;
}
V_48 = F_38 ( V_2 , V_6 , V_47 ) ;
if ( V_48 )
goto V_53;
V_48 = F_18 ( V_2 , V_2 + 1 , V_14 ) ;
if ( V_48 )
goto V_54;
return V_2 ;
V_54:
F_39 ( V_2 ) ;
V_53:
F_40 ( V_51 , V_2 ) ;
V_50:
return F_41 ( V_48 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_51 , V_2 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
return F_50 ( V_2 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
F_54 ( V_2 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_55 = - 1 ;
F_56 ( V_2 -> V_10 . V_56 , V_57 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
void F_59 ( struct V_1 * V_2 , int V_8 )
{
int * V_58 ;
V_58 = F_60 ( V_2 -> V_6 -> V_10 . V_11 ) ;
if ( * V_58 != V_2 -> V_59 ) {
F_61 ( V_60 , V_2 ) ;
* V_58 = V_2 -> V_59 ;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_10 . V_61 = F_60 ( V_62 ) ;
F_1 ( V_2 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
V_2 -> V_8 = - 1 ;
F_1 ( NULL ) ;
F_63 ( V_2 ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
if ( V_2 -> V_10 . V_65 )
V_64 -> V_64 = V_66 ;
else
V_64 -> V_64 = V_67 ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
switch ( V_64 -> V_64 ) {
case V_67 :
V_2 -> V_10 . V_65 = false ;
break;
case V_66 :
V_2 -> V_10 . V_65 = true ;
break;
default:
return - V_9 ;
}
return 0 ;
}
int F_66 ( struct V_1 * V_68 )
{
return ( ( ! ! V_68 -> V_10 . V_69 || F_67 ( V_68 ) )
&& ! V_68 -> V_10 . V_65 && ! V_68 -> V_10 . V_70 ) ;
}
static void F_68 ( void * V_71 )
{
}
void F_69 ( const T_2 * V_72 )
{
F_70 () ;
F_71 ( V_72 , F_68 , NULL , true ) ;
F_72 () ;
}
static bool F_73 ( struct V_6 * V_6 )
{
return F_74 ( V_6 -> V_10 . V_16 != F_75 ( & V_73 ) ) ;
}
static void F_76 ( struct V_6 * V_6 )
{
T_3 V_74 ;
T_4 V_75 ;
if ( ! F_73 ( V_6 ) )
return;
F_77 ( & V_76 ) ;
if ( ! F_73 ( V_6 ) ) {
F_78 ( & V_76 ) ;
return;
}
if ( F_74 ( V_77 == 0 ) ) {
F_79 ( & V_73 ) ;
V_77 = 1 ;
F_69 ( V_78 ) ;
F_61 ( V_79 ) ;
}
V_6 -> V_10 . V_16 = F_75 ( & V_73 ) ;
V_6 -> V_10 . V_75 = V_77 ;
V_77 ++ ;
V_77 &= ( 1 << V_80 ) - 1 ;
V_74 = F_80 ( V_6 -> V_10 . V_81 ) ;
F_2 ( V_74 & ~ V_82 ) ;
V_75 = ( ( T_4 ) ( V_6 -> V_10 . V_75 ) << V_83 ) & F_81 ( V_80 ) ;
V_6 -> V_10 . V_84 = V_74 | V_75 ;
F_78 ( & V_76 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
if ( F_83 ( V_2 -> V_10 . V_85 ) )
return 0 ;
V_2 -> V_10 . V_85 = true ;
if ( F_74 ( F_35 ( V_6 ) && ! F_84 ( V_6 ) ) ) {
V_7 = F_85 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
if ( F_35 ( V_6 ) && F_36 ( V_6 ) )
V_7 = F_86 ( V_2 ) ;
return V_7 ;
}
bool F_87 ( struct V_6 * V_6 )
{
return F_36 ( V_6 ) ;
}
void F_88 ( struct V_6 * V_6 )
{
int V_23 ;
struct V_1 * V_2 ;
F_89 (i, vcpu, kvm)
V_2 -> V_10 . V_70 = true ;
F_90 ( V_6 , V_86 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_70 = true ;
F_92 ( V_2 ) ;
}
void F_93 ( struct V_1 * V_2 )
{
struct V_87 * V_88 = F_94 ( V_2 ) ;
V_2 -> V_10 . V_70 = false ;
F_95 ( V_88 ) ;
}
void F_96 ( struct V_6 * V_6 )
{
int V_23 ;
struct V_1 * V_2 ;
F_89 (i, vcpu, kvm)
F_93 ( V_2 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_87 * V_88 = F_94 ( V_2 ) ;
F_98 ( * V_88 , ( ( ! V_2 -> V_10 . V_65 ) &&
( ! V_2 -> V_10 . V_70 ) ) ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
return V_2 -> V_10 . V_55 >= 0 ;
}
int F_100 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
int V_7 ;
T_5 V_91 ;
if ( F_74 ( ! F_99 ( V_2 ) ) )
return - V_92 ;
V_7 = F_82 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_90 -> V_93 == V_94 ) {
V_7 = F_101 ( V_2 , V_2 -> V_90 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_95 )
F_102 ( V_96 , & V_2 -> V_97 , & V_91 ) ;
V_7 = 1 ;
V_90 -> V_93 = V_98 ;
while ( V_7 > 0 ) {
F_103 () ;
F_76 ( V_2 -> V_6 ) ;
if ( V_2 -> V_10 . V_65 || V_2 -> V_10 . V_70 )
F_97 ( V_2 ) ;
F_70 () ;
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
F_107 () ;
if ( F_108 ( V_99 ) ) {
V_7 = - V_100 ;
V_90 -> V_93 = V_101 ;
}
if ( V_7 <= 0 || F_73 ( V_2 -> V_6 ) ||
V_2 -> V_10 . V_65 || V_2 -> V_10 . V_70 ) {
F_109 () ;
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
F_72 () ;
continue;
}
F_113 ( V_2 ) ;
F_114 ( * F_115 ( V_2 ) ) ;
F_116 () ;
V_2 -> V_102 = V_4 ;
V_7 = F_61 ( V_103 , V_2 ) ;
V_2 -> V_102 = V_104 ;
V_2 -> V_105 . V_106 ++ ;
F_117 ( V_2 ) ;
F_109 () ;
F_118 () ;
F_119 ( V_7 , F_120 ( V_2 ) , * F_115 ( V_2 ) ) ;
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
F_72 () ;
V_7 = F_121 ( V_2 , V_90 , V_7 ) ;
}
if ( V_2 -> V_95 )
F_102 ( V_96 , & V_91 , NULL ) ;
return V_7 ;
}
static int F_122 ( struct V_1 * V_2 , int V_107 , bool V_108 )
{
int V_109 ;
bool V_110 ;
unsigned long * V_111 ;
if ( V_107 == V_112 )
V_109 = F_123 ( V_113 ) ;
else
V_109 = F_123 ( V_114 ) ;
V_111 = ( unsigned long * ) & V_2 -> V_10 . V_69 ;
if ( V_108 )
V_110 = F_124 ( V_109 , V_111 ) ;
else
V_110 = F_125 ( V_109 , V_111 ) ;
if ( V_110 == V_108 )
return 0 ;
F_92 ( V_2 ) ;
return 0 ;
}
int F_126 ( struct V_6 * V_6 , struct V_115 * V_116 ,
bool V_117 )
{
T_6 V_118 = V_116 -> V_118 ;
unsigned int V_119 , V_120 , V_121 ;
int V_122 = F_127 ( & V_6 -> V_123 ) ;
struct V_1 * V_2 = NULL ;
bool V_108 = V_116 -> V_108 ;
V_119 = ( V_118 >> V_124 ) & V_125 ;
V_120 = ( V_118 >> V_126 ) & V_127 ;
V_121 = ( V_118 >> V_128 ) & V_129 ;
F_128 ( V_119 , V_120 , V_121 , V_116 -> V_108 ) ;
switch ( V_119 ) {
case V_130 :
if ( F_35 ( V_6 ) )
return - V_131 ;
if ( V_120 >= V_122 )
return - V_9 ;
V_2 = F_129 ( V_6 , V_120 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_121 > V_132 )
return - V_9 ;
return F_122 ( V_2 , V_121 , V_108 ) ;
case V_133 :
if ( ! F_35 ( V_6 ) )
return - V_131 ;
if ( V_120 >= V_122 )
return - V_9 ;
V_2 = F_129 ( V_6 , V_120 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_121 < V_134 || V_121 >= V_135 )
return - V_9 ;
return F_130 ( V_6 , V_2 -> V_59 , V_121 , V_108 ) ;
case V_136 :
if ( ! F_35 ( V_6 ) )
return - V_131 ;
if ( V_121 < V_135 )
return - V_9 ;
return F_130 ( V_6 , 0 , V_121 , V_108 ) ;
}
return - V_9 ;
}
static int F_131 ( struct V_1 * V_2 ,
const struct F_38 * V_137 )
{
unsigned int V_23 ;
int V_138 = F_132 () ;
if ( V_137 -> V_55 != V_138 )
return - V_9 ;
if ( V_2 -> V_10 . V_55 != - 1 && V_2 -> V_10 . V_55 != V_137 -> V_55 )
return - V_9 ;
for ( V_23 = 0 ; V_23 < sizeof( V_137 -> V_56 ) * 8 ; V_23 ++ ) {
bool V_110 = ( V_137 -> V_56 [ V_23 / 32 ] & ( 1 << ( V_23 % 32 ) ) ) ;
if ( V_110 && V_23 >= V_57 )
return - V_139 ;
if ( V_2 -> V_10 . V_55 != - 1 && V_23 < V_57 &&
F_133 ( V_23 , V_2 -> V_10 . V_56 ) != V_110 )
return - V_9 ;
if ( V_110 )
F_134 ( V_23 , V_2 -> V_10 . V_56 ) ;
}
V_2 -> V_10 . V_55 = V_138 ;
return F_135 ( V_2 ) ;
}
static int F_136 ( struct V_1 * V_2 ,
struct F_38 * V_137 )
{
int V_7 ;
V_7 = F_131 ( V_2 , V_137 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_10 . V_85 )
F_137 ( V_2 -> V_6 ) ;
F_138 ( V_2 ) ;
if ( F_133 ( V_140 , V_2 -> V_10 . V_56 ) )
V_2 -> V_10 . V_65 = true ;
else
V_2 -> V_10 . V_65 = false ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
int V_7 = - V_131 ;
switch ( V_142 -> V_143 ) {
default:
V_7 = F_140 ( V_2 , V_142 ) ;
break;
}
return V_7 ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
int V_7 = - V_131 ;
switch ( V_142 -> V_143 ) {
default:
V_7 = F_142 ( V_2 , V_142 ) ;
break;
}
return V_7 ;
}
static int F_143 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
int V_7 = - V_131 ;
switch ( V_142 -> V_143 ) {
default:
V_7 = F_144 ( V_2 , V_142 ) ;
break;
}
return V_7 ;
}
long F_145 ( struct V_43 * V_44 ,
unsigned int V_45 , unsigned long V_46 )
{
struct V_1 * V_2 = V_44 -> V_144 ;
void T_7 * V_145 = ( void T_7 * ) V_46 ;
struct V_141 V_142 ;
switch ( V_45 ) {
case V_146 : {
struct F_38 V_137 ;
if ( F_146 ( & V_137 , V_145 , sizeof( V_137 ) ) )
return - V_147 ;
return F_136 ( V_2 , & V_137 ) ;
}
case V_148 :
case V_149 : {
struct V_150 V_151 ;
if ( F_74 ( ! F_99 ( V_2 ) ) )
return - V_92 ;
if ( F_146 ( & V_151 , V_145 , sizeof( V_151 ) ) )
return - V_147 ;
if ( V_45 == V_148 )
return F_147 ( V_2 , & V_151 ) ;
else
return F_148 ( V_2 , & V_151 ) ;
}
case V_152 : {
struct V_153 T_7 * V_154 = V_145 ;
struct V_153 V_155 ;
unsigned V_156 ;
if ( F_74 ( ! F_99 ( V_2 ) ) )
return - V_92 ;
if ( F_146 ( & V_155 , V_154 , sizeof( V_155 ) ) )
return - V_147 ;
V_156 = V_155 . V_156 ;
V_155 . V_156 = F_149 ( V_2 ) ;
if ( F_150 ( V_154 , & V_155 , sizeof( V_155 ) ) )
return - V_147 ;
if ( V_156 < V_155 . V_156 )
return - V_157 ;
return F_151 ( V_2 , V_154 -> V_151 ) ;
}
case V_158 : {
if ( F_146 ( & V_142 , V_145 , sizeof( V_142 ) ) )
return - V_147 ;
return F_139 ( V_2 , & V_142 ) ;
}
case V_159 : {
if ( F_146 ( & V_142 , V_145 , sizeof( V_142 ) ) )
return - V_147 ;
return F_141 ( V_2 , & V_142 ) ;
}
case V_160 : {
if ( F_146 ( & V_142 , V_145 , sizeof( V_142 ) ) )
return - V_147 ;
return F_143 ( V_2 , & V_142 ) ;
}
default:
return - V_9 ;
}
}
int F_152 ( struct V_6 * V_6 , struct V_161 * log )
{
bool V_162 = false ;
int V_26 ;
F_153 ( & V_6 -> V_163 ) ;
V_26 = F_154 ( V_6 , log , & V_162 ) ;
if ( V_162 )
F_155 ( V_6 ) ;
F_156 ( & V_6 -> V_163 ) ;
return V_26 ;
}
static int F_157 ( struct V_6 * V_6 ,
struct V_164 * V_165 )
{
unsigned long V_166 , type ;
V_166 = ( V_165 -> V_47 & V_167 ) >>
V_168 ;
type = ( V_165 -> V_47 & V_169 ) >>
V_170 ;
switch ( V_166 ) {
case V_171 :
if ( ! V_18 )
return - V_131 ;
return F_158 ( V_6 , type , & V_165 -> V_172 , true ) ;
default:
return - V_173 ;
}
}
long F_159 ( struct V_43 * V_44 ,
unsigned int V_45 , unsigned long V_46 )
{
struct V_6 * V_6 = V_44 -> V_144 ;
void T_7 * V_145 = ( void T_7 * ) V_46 ;
switch ( V_45 ) {
case V_174 : {
int V_7 ;
if ( ! V_18 )
return - V_131 ;
F_153 ( & V_6 -> V_175 ) ;
V_7 = F_160 ( V_6 , V_176 ) ;
F_156 ( & V_6 -> V_175 ) ;
return V_7 ;
}
case V_177 : {
struct V_164 V_165 ;
if ( F_146 ( & V_165 , V_145 , sizeof( V_165 ) ) )
return - V_147 ;
return F_157 ( V_6 , & V_165 ) ;
}
case V_178 : {
int V_48 ;
struct F_38 V_137 ;
V_48 = F_161 ( & V_137 ) ;
if ( V_48 )
return V_48 ;
if ( F_150 ( V_145 , & V_137 , sizeof( V_137 ) ) )
return - V_147 ;
return 0 ;
}
default:
return - V_9 ;
}
}
static void F_162 ( void * V_179 )
{
T_3 V_180 ;
unsigned long V_181 ;
unsigned long V_182 ;
unsigned long V_183 ;
F_163 ( F_164 () ) ;
V_180 = F_165 () ;
V_182 = F_6 ( V_184 ) ;
V_181 = V_182 + V_185 ;
V_183 = ( unsigned long ) F_166 ( V_186 ) ;
F_167 ( V_180 , V_181 , V_183 ) ;
F_168 () ;
F_169 () ;
}
static void F_170 ( void )
{
if ( F_171 () ) {
F_168 () ;
} else {
if ( F_172 () == V_187 )
F_162 ( NULL ) ;
}
}
static void F_173 ( void )
{
if ( ! F_171 () )
F_174 ( V_187 ,
F_175 () ) ;
}
static void F_176 ( void * V_188 )
{
if ( ! F_6 ( V_189 ) ) {
F_170 () ;
F_4 ( V_189 , 1 ) ;
}
}
int F_177 ( void )
{
F_176 ( NULL ) ;
return 0 ;
}
static void F_178 ( void * V_188 )
{
if ( F_6 ( V_189 ) ) {
F_173 () ;
F_4 ( V_189 , 0 ) ;
}
}
void F_179 ( void )
{
F_178 ( NULL ) ;
}
static int F_180 ( struct V_190 * V_191 ,
unsigned long V_192 ,
void * V_68 )
{
switch ( V_192 ) {
case V_193 :
if ( F_6 ( V_189 ) )
F_173 () ;
return V_194 ;
case V_195 :
if ( F_6 ( V_189 ) )
F_170 () ;
return V_194 ;
default:
return V_196 ;
}
}
static void T_8 F_181 ( void )
{
F_182 ( & V_197 ) ;
}
static void T_8 F_183 ( void )
{
F_184 ( & V_197 ) ;
}
static inline void F_181 ( void )
{
}
static inline void F_183 ( void )
{
}
static void F_185 ( void )
{
F_23 ( V_62 ) ;
}
static int F_186 ( void )
{
V_62 = F_13 ( V_198 ) ;
if ( ! V_62 ) {
F_187 ( L_1 ) ;
return - V_12 ;
}
V_80 = F_188 () ;
F_189 ( L_2 , V_80 ) ;
return 0 ;
}
static int F_190 ( void )
{
int V_48 = 0 ;
F_191 ( F_176 , NULL , 1 ) ;
F_181 () ;
V_48 = F_192 () ;
switch ( V_48 ) {
case 0 :
V_18 = true ;
break;
case - V_173 :
case - V_131 :
V_18 = false ;
V_48 = 0 ;
break;
default:
goto V_50;
}
V_48 = F_193 () ;
if ( V_48 )
goto V_50;
F_194 () ;
F_195 () ;
V_50:
F_191 ( F_178 , NULL , 1 ) ;
return V_48 ;
}
static void F_196 ( void )
{
int V_8 ;
if ( F_171 () )
return;
F_197 () ;
F_15 (cpu)
F_198 ( F_199 ( V_184 , V_8 ) ) ;
F_183 () ;
}
static int F_200 ( void )
{
F_189 ( L_3 ) ;
return 0 ;
}
static int F_201 ( void )
{
int V_8 ;
int V_48 = 0 ;
V_48 = F_202 () ;
if ( V_48 )
goto V_199;
V_187 = F_172 () ;
F_15 (cpu) {
unsigned long V_182 ;
V_182 = F_203 ( V_52 ) ;
if ( ! V_182 ) {
V_48 = - V_12 ;
goto V_199;
}
F_199 ( V_184 , V_8 ) = V_182 ;
}
V_48 = F_18 ( F_166 ( V_200 ) ,
F_166 ( V_201 ) , V_202 ) ;
if ( V_48 ) {
F_187 ( L_4 ) ;
goto V_199;
}
V_48 = F_18 ( F_166 ( V_203 ) ,
F_166 ( V_204 ) , V_205 ) ;
if ( V_48 ) {
F_187 ( L_5 ) ;
goto V_199;
}
V_48 = F_18 ( F_166 ( V_206 ) ,
F_166 ( V_207 ) , V_205 ) ;
if ( V_48 ) {
F_187 ( L_6 ) ;
goto V_199;
}
F_15 (cpu) {
char * V_182 = ( char * ) F_199 ( V_184 , V_8 ) ;
V_48 = F_18 ( V_182 , V_182 + V_185 ,
V_14 ) ;
if ( V_48 ) {
F_187 ( L_7 ) ;
goto V_199;
}
}
F_15 (cpu) {
V_198 * V_208 ;
V_208 = F_16 ( V_62 , V_8 ) ;
V_48 = F_18 ( V_208 , V_208 + 1 , V_14 ) ;
if ( V_48 ) {
F_187 ( L_8 , V_48 ) ;
goto V_199;
}
}
F_189 ( L_9 ) ;
return 0 ;
V_199:
F_196 () ;
F_187 ( L_10 , V_48 ) ;
return V_48 ;
}
static void F_204 ( void * V_7 )
{
* ( int * ) V_7 = F_132 () ;
}
struct V_1 * F_205 ( struct V_6 * V_6 , unsigned long V_209 )
{
struct V_1 * V_2 ;
int V_23 ;
V_209 &= V_210 ;
F_89 (i, vcpu, kvm) {
if ( V_209 == F_206 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_207 ( void * V_211 )
{
int V_48 ;
int V_7 , V_8 ;
if ( ! F_208 () ) {
F_187 ( L_11 ) ;
return - V_173 ;
}
F_209 (cpu) {
F_210 ( V_8 , F_204 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_187 ( L_12 , V_8 ) ;
return - V_173 ;
}
}
V_48 = F_186 () ;
if ( V_48 )
return V_48 ;
if ( F_171 () )
V_48 = F_200 () ;
else
V_48 = F_201 () ;
if ( V_48 )
goto V_199;
V_48 = F_190 () ;
if ( V_48 )
goto V_212;
return 0 ;
V_212:
F_196 () ;
V_199:
F_185 () ;
return V_48 ;
}
void F_211 ( void )
{
F_212 () ;
}
static int F_213 ( void )
{
int V_213 = F_214 ( NULL , sizeof( struct V_1 ) , 0 , V_214 ) ;
return V_213 ;
}
