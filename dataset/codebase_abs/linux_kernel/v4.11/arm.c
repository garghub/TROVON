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
V_6 -> V_10 . V_16 = 0 ;
V_6 -> V_10 . V_17 = V_18 ?
F_20 () : V_19 ;
return V_7 ;
V_15:
F_21 ( V_6 ) ;
V_13:
F_22 ( V_6 -> V_10 . V_11 ) ;
V_6 -> V_10 . V_11 = NULL ;
return V_7 ;
}
bool F_23 ( void )
{
return false ;
}
int F_24 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_25 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
return V_22 ;
}
void F_26 ( struct V_6 * V_6 )
{
int V_23 ;
F_22 ( V_6 -> V_10 . V_11 ) ;
V_6 -> V_10 . V_11 = NULL ;
for ( V_23 = 0 ; V_23 < V_19 ; ++ V_23 ) {
if ( V_6 -> V_24 [ V_23 ] ) {
F_27 ( V_6 -> V_24 [ V_23 ] ) ;
V_6 -> V_24 [ V_23 ] = NULL ;
}
}
F_28 ( V_6 ) ;
}
int F_29 ( struct V_6 * V_6 , long V_25 )
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
case V_38 :
V_26 = 1 ;
break;
case V_39 :
V_26 = V_40 ;
break;
case V_41 :
V_26 = 1 ;
break;
case V_42 :
V_26 = F_30 () ;
break;
case V_43 :
V_26 = V_19 ;
break;
case V_44 :
V_26 = V_45 ;
break;
case V_46 :
if ( ! V_6 )
V_26 = - V_9 ;
else
V_26 = V_6 -> V_10 . V_47 . V_48 ;
break;
default:
V_26 = F_31 ( V_6 , V_25 ) ;
break;
}
return V_26 ;
}
long F_32 ( struct V_49 * V_50 ,
unsigned int V_51 , unsigned long V_52 )
{
return - V_9 ;
}
struct V_1 * F_33 ( struct V_6 * V_6 , unsigned int V_53 )
{
int V_54 ;
struct V_1 * V_2 ;
if ( F_34 ( V_6 ) && F_35 ( V_6 ) ) {
V_54 = - V_55 ;
goto V_56;
}
if ( V_53 >= V_6 -> V_10 . V_17 ) {
V_54 = - V_9 ;
goto V_56;
}
V_2 = F_36 ( V_57 , V_58 ) ;
if ( ! V_2 ) {
V_54 = - V_12 ;
goto V_56;
}
V_54 = F_37 ( V_2 , V_6 , V_53 ) ;
if ( V_54 )
goto V_59;
V_54 = F_18 ( V_2 , V_2 + 1 , V_14 ) ;
if ( V_54 )
goto V_60;
return V_2 ;
V_60:
F_38 ( V_2 ) ;
V_59:
F_39 ( V_57 , V_2 ) ;
V_56:
return F_40 ( V_54 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_57 , V_2 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
}
int F_48 ( struct V_1 * V_2 )
{
return F_49 ( F_50 ( V_2 ) ) ||
F_49 ( F_51 ( V_2 ) ) ;
}
void F_52 ( struct V_1 * V_2 )
{
F_53 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
F_55 ( V_2 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_61 = - 1 ;
F_57 ( V_2 -> V_10 . V_62 , V_63 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
void F_60 ( struct V_1 * V_2 , int V_8 )
{
int * V_64 ;
V_64 = F_61 ( V_2 -> V_6 -> V_10 . V_11 ) ;
if ( * V_64 != V_2 -> V_65 ) {
F_62 ( V_66 , V_2 ) ;
* V_64 = V_2 -> V_65 ;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_10 . V_67 = F_61 ( V_68 ) ;
F_1 ( V_2 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
V_2 -> V_8 = - 1 ;
F_1 ( NULL ) ;
F_64 ( V_2 ) ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
if ( V_2 -> V_10 . V_71 )
V_70 -> V_70 = V_72 ;
else
V_70 -> V_70 = V_73 ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
switch ( V_70 -> V_70 ) {
case V_73 :
V_2 -> V_10 . V_71 = false ;
break;
case V_72 :
V_2 -> V_10 . V_71 = true ;
break;
default:
return - V_9 ;
}
return 0 ;
}
int F_67 ( struct V_1 * V_74 )
{
return ( ( ! ! V_74 -> V_10 . V_75 || F_68 ( V_74 ) )
&& ! V_74 -> V_10 . V_71 && ! V_74 -> V_10 . V_76 ) ;
}
static void F_69 ( void * V_77 )
{
}
void F_70 ( const T_2 * V_78 )
{
F_71 () ;
F_72 ( V_78 , F_69 , NULL , true ) ;
F_73 () ;
}
static bool F_74 ( struct V_6 * V_6 )
{
return F_75 ( V_6 -> V_10 . V_16 != F_76 ( & V_79 ) ) ;
}
static void F_77 ( struct V_6 * V_6 )
{
T_3 V_80 ;
T_4 V_81 ;
if ( ! F_74 ( V_6 ) )
return;
F_78 ( & V_82 ) ;
if ( ! F_74 ( V_6 ) ) {
F_79 ( & V_82 ) ;
return;
}
if ( F_75 ( V_83 == 0 ) ) {
F_80 ( & V_79 ) ;
V_83 = 1 ;
F_70 ( V_84 ) ;
F_62 ( V_85 ) ;
}
V_6 -> V_10 . V_16 = F_76 ( & V_79 ) ;
V_6 -> V_10 . V_81 = V_83 ;
V_83 ++ ;
V_83 &= ( 1 << V_86 ) - 1 ;
V_80 = F_81 ( V_6 -> V_10 . V_87 ) ;
F_2 ( V_80 & ~ V_88 ) ;
V_81 = ( ( T_4 ) ( V_6 -> V_10 . V_81 ) << V_89 ) & F_82 ( V_86 ) ;
V_6 -> V_10 . V_90 = V_80 | V_81 ;
F_79 ( & V_82 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
if ( F_84 ( V_2 -> V_10 . V_91 ) )
return 0 ;
V_2 -> V_10 . V_91 = true ;
if ( F_75 ( F_34 ( V_6 ) && ! F_85 ( V_6 ) ) ) {
V_7 = F_86 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
if ( F_34 ( V_6 ) && F_35 ( V_6 ) )
V_7 = F_87 ( V_2 ) ;
return V_7 ;
}
bool F_88 ( struct V_6 * V_6 )
{
return F_35 ( V_6 ) ;
}
void F_89 ( struct V_6 * V_6 )
{
int V_23 ;
struct V_1 * V_2 ;
F_90 (i, vcpu, kvm)
V_2 -> V_10 . V_76 = true ;
F_91 ( V_6 , V_92 ) ;
}
void F_92 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_76 = true ;
F_93 ( V_2 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = F_95 ( V_2 ) ;
V_2 -> V_10 . V_76 = false ;
F_96 ( V_94 ) ;
}
void F_97 ( struct V_6 * V_6 )
{
int V_23 ;
struct V_1 * V_2 ;
F_90 (i, vcpu, kvm)
F_94 ( V_2 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = F_95 ( V_2 ) ;
F_99 ( * V_94 , ( ( ! V_2 -> V_10 . V_71 ) &&
( ! V_2 -> V_10 . V_76 ) ) ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
return V_2 -> V_10 . V_61 >= 0 ;
}
int F_101 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
int V_7 ;
T_5 V_97 ;
if ( F_75 ( ! F_100 ( V_2 ) ) )
return - V_98 ;
V_7 = F_83 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_96 -> V_99 == V_100 ) {
V_7 = F_102 ( V_2 , V_2 -> V_96 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_96 -> V_101 )
return - V_102 ;
if ( V_2 -> V_103 )
F_103 ( V_104 , & V_2 -> V_105 , & V_97 ) ;
V_7 = 1 ;
V_96 -> V_99 = V_106 ;
while ( V_7 > 0 ) {
F_104 () ;
F_77 ( V_2 -> V_6 ) ;
if ( V_2 -> V_10 . V_71 || V_2 -> V_10 . V_76 )
F_98 ( V_2 ) ;
F_71 () ;
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
F_108 () ;
if ( F_109 ( V_107 ) ) {
V_7 = - V_102 ;
V_96 -> V_99 = V_108 ;
}
if ( V_7 <= 0 || F_74 ( V_2 -> V_6 ) ||
V_2 -> V_10 . V_71 || V_2 -> V_10 . V_76 ) {
F_110 () ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
F_113 ( V_2 ) ;
F_73 () ;
continue;
}
F_114 ( V_2 ) ;
F_115 ( * F_116 ( V_2 ) ) ;
F_117 () ;
V_2 -> V_109 = V_4 ;
V_7 = F_62 ( V_110 , V_2 ) ;
V_2 -> V_109 = V_111 ;
V_2 -> V_112 . V_113 ++ ;
F_118 ( V_2 ) ;
F_110 () ;
F_119 () ;
F_120 ( V_7 , F_121 ( V_2 ) , * F_116 ( V_2 ) ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
F_113 ( V_2 ) ;
F_73 () ;
V_7 = F_122 ( V_2 , V_96 , V_7 ) ;
}
if ( V_2 -> V_103 )
F_103 ( V_104 , & V_97 , NULL ) ;
return V_7 ;
}
static int F_123 ( struct V_1 * V_2 , int V_114 , bool V_115 )
{
int V_116 ;
bool V_117 ;
unsigned long * V_118 ;
if ( V_114 == V_119 )
V_116 = F_124 ( V_120 ) ;
else
V_116 = F_124 ( V_121 ) ;
V_118 = ( unsigned long * ) & V_2 -> V_10 . V_75 ;
if ( V_115 )
V_117 = F_125 ( V_116 , V_118 ) ;
else
V_117 = F_126 ( V_116 , V_118 ) ;
if ( V_117 == V_115 )
return 0 ;
F_93 ( V_2 ) ;
return 0 ;
}
int F_127 ( struct V_6 * V_6 , struct V_122 * V_123 ,
bool V_124 )
{
T_6 V_125 = V_123 -> V_125 ;
unsigned int V_126 , V_127 , V_128 ;
int V_129 = F_128 ( & V_6 -> V_130 ) ;
struct V_1 * V_2 = NULL ;
bool V_115 = V_123 -> V_115 ;
V_126 = ( V_125 >> V_131 ) & V_132 ;
V_127 = ( V_125 >> V_133 ) & V_134 ;
V_128 = ( V_125 >> V_135 ) & V_136 ;
F_129 ( V_126 , V_127 , V_128 , V_123 -> V_115 ) ;
switch ( V_126 ) {
case V_137 :
if ( F_34 ( V_6 ) )
return - V_138 ;
if ( V_127 >= V_129 )
return - V_9 ;
V_2 = F_130 ( V_6 , V_127 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_128 > V_139 )
return - V_9 ;
return F_123 ( V_2 , V_128 , V_115 ) ;
case V_140 :
if ( ! F_34 ( V_6 ) )
return - V_138 ;
if ( V_127 >= V_129 )
return - V_9 ;
V_2 = F_130 ( V_6 , V_127 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_128 < V_141 || V_128 >= V_142 )
return - V_9 ;
return F_131 ( V_6 , V_2 -> V_65 , V_128 , V_115 ) ;
case V_143 :
if ( ! F_34 ( V_6 ) )
return - V_138 ;
if ( V_128 < V_142 )
return - V_9 ;
return F_131 ( V_6 , 0 , V_128 , V_115 ) ;
}
return - V_9 ;
}
static int F_132 ( struct V_1 * V_2 ,
const struct F_37 * V_144 )
{
unsigned int V_23 ;
int V_145 = F_133 () ;
if ( V_144 -> V_61 != V_145 )
return - V_9 ;
if ( V_2 -> V_10 . V_61 != - 1 && V_2 -> V_10 . V_61 != V_144 -> V_61 )
return - V_9 ;
for ( V_23 = 0 ; V_23 < sizeof( V_144 -> V_62 ) * 8 ; V_23 ++ ) {
bool V_117 = ( V_144 -> V_62 [ V_23 / 32 ] & ( 1 << ( V_23 % 32 ) ) ) ;
if ( V_117 && V_23 >= V_63 )
return - V_146 ;
if ( V_2 -> V_10 . V_61 != - 1 && V_23 < V_63 &&
F_134 ( V_23 , V_2 -> V_10 . V_62 ) != V_117 )
return - V_9 ;
if ( V_117 )
F_135 ( V_23 , V_2 -> V_10 . V_62 ) ;
}
V_2 -> V_10 . V_61 = V_145 ;
return F_136 ( V_2 ) ;
}
static int F_137 ( struct V_1 * V_2 ,
struct F_37 * V_144 )
{
int V_7 ;
V_7 = F_132 ( V_2 , V_144 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_10 . V_91 )
F_138 ( V_2 -> V_6 ) ;
F_139 ( V_2 ) ;
if ( F_134 ( V_147 , V_2 -> V_10 . V_62 ) )
V_2 -> V_10 . V_71 = true ;
else
V_2 -> V_10 . V_71 = false ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
int V_7 = - V_138 ;
switch ( V_149 -> V_150 ) {
default:
V_7 = F_141 ( V_2 , V_149 ) ;
break;
}
return V_7 ;
}
static int F_142 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
int V_7 = - V_138 ;
switch ( V_149 -> V_150 ) {
default:
V_7 = F_143 ( V_2 , V_149 ) ;
break;
}
return V_7 ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
int V_7 = - V_138 ;
switch ( V_149 -> V_150 ) {
default:
V_7 = F_145 ( V_2 , V_149 ) ;
break;
}
return V_7 ;
}
long F_146 ( struct V_49 * V_50 ,
unsigned int V_51 , unsigned long V_52 )
{
struct V_1 * V_2 = V_50 -> V_151 ;
void T_7 * V_152 = ( void T_7 * ) V_52 ;
struct V_148 V_149 ;
switch ( V_51 ) {
case V_153 : {
struct F_37 V_144 ;
if ( F_147 ( & V_144 , V_152 , sizeof( V_144 ) ) )
return - V_154 ;
return F_137 ( V_2 , & V_144 ) ;
}
case V_155 :
case V_156 : {
struct V_157 V_158 ;
if ( F_75 ( ! F_100 ( V_2 ) ) )
return - V_98 ;
if ( F_147 ( & V_158 , V_152 , sizeof( V_158 ) ) )
return - V_154 ;
if ( V_51 == V_155 )
return F_148 ( V_2 , & V_158 ) ;
else
return F_149 ( V_2 , & V_158 ) ;
}
case V_159 : {
struct V_160 T_7 * V_161 = V_152 ;
struct V_160 V_162 ;
unsigned V_163 ;
if ( F_75 ( ! F_100 ( V_2 ) ) )
return - V_98 ;
if ( F_147 ( & V_162 , V_161 , sizeof( V_162 ) ) )
return - V_154 ;
V_163 = V_162 . V_163 ;
V_162 . V_163 = F_150 ( V_2 ) ;
if ( F_151 ( V_161 , & V_162 , sizeof( V_162 ) ) )
return - V_154 ;
if ( V_163 < V_162 . V_163 )
return - V_164 ;
return F_152 ( V_2 , V_161 -> V_158 ) ;
}
case V_165 : {
if ( F_147 ( & V_149 , V_152 , sizeof( V_149 ) ) )
return - V_154 ;
return F_140 ( V_2 , & V_149 ) ;
}
case V_166 : {
if ( F_147 ( & V_149 , V_152 , sizeof( V_149 ) ) )
return - V_154 ;
return F_142 ( V_2 , & V_149 ) ;
}
case V_167 : {
if ( F_147 ( & V_149 , V_152 , sizeof( V_149 ) ) )
return - V_154 ;
return F_144 ( V_2 , & V_149 ) ;
}
default:
return - V_9 ;
}
}
int F_153 ( struct V_6 * V_6 , struct V_168 * log )
{
bool V_169 = false ;
int V_26 ;
F_154 ( & V_6 -> V_170 ) ;
V_26 = F_155 ( V_6 , log , & V_169 ) ;
if ( V_169 )
F_156 ( V_6 ) ;
F_157 ( & V_6 -> V_170 ) ;
return V_26 ;
}
static int F_158 ( struct V_6 * V_6 ,
struct V_171 * V_172 )
{
unsigned long V_173 , type ;
V_173 = ( V_172 -> V_53 & V_174 ) >>
V_175 ;
type = ( V_172 -> V_53 & V_176 ) >>
V_177 ;
switch ( V_173 ) {
case V_178 :
if ( ! V_18 )
return - V_138 ;
return F_159 ( V_6 , type , & V_172 -> V_179 , true ) ;
default:
return - V_180 ;
}
}
long F_160 ( struct V_49 * V_50 ,
unsigned int V_51 , unsigned long V_52 )
{
struct V_6 * V_6 = V_50 -> V_151 ;
void T_7 * V_152 = ( void T_7 * ) V_52 ;
switch ( V_51 ) {
case V_181 : {
int V_7 ;
if ( ! V_18 )
return - V_138 ;
F_154 ( & V_6 -> V_182 ) ;
V_7 = F_161 ( V_6 , V_183 ) ;
F_157 ( & V_6 -> V_182 ) ;
return V_7 ;
}
case V_184 : {
struct V_171 V_172 ;
if ( F_147 ( & V_172 , V_152 , sizeof( V_172 ) ) )
return - V_154 ;
return F_158 ( V_6 , & V_172 ) ;
}
case V_185 : {
int V_54 ;
struct F_37 V_144 ;
V_54 = F_162 ( & V_144 ) ;
if ( V_54 )
return V_54 ;
if ( F_151 ( V_152 , & V_144 , sizeof( V_144 ) ) )
return - V_154 ;
return 0 ;
}
default:
return - V_9 ;
}
}
static void F_163 ( void * V_186 )
{
T_3 V_187 ;
unsigned long V_188 ;
unsigned long V_189 ;
unsigned long V_190 ;
F_164 ( F_165 () ) ;
V_187 = F_166 () ;
V_189 = F_6 ( V_191 ) ;
V_188 = V_189 + V_192 ;
V_190 = ( unsigned long ) F_167 ( V_193 ) ;
F_168 ( V_187 , V_188 , V_190 ) ;
F_169 () ;
if ( F_170 () )
F_171 () ;
F_172 () ;
}
static void F_173 ( void )
{
if ( F_170 () ) {
F_169 () ;
} else {
if ( F_174 () == V_194 )
F_163 ( NULL ) ;
}
if ( V_18 )
F_175 () ;
}
static void F_176 ( void )
{
if ( ! F_170 () )
F_177 ( V_194 ,
F_178 () ) ;
}
static void F_179 ( void * V_195 )
{
if ( ! F_6 ( V_196 ) ) {
F_173 () ;
F_4 ( V_196 , 1 ) ;
}
}
int F_180 ( void )
{
F_179 ( NULL ) ;
return 0 ;
}
static void F_181 ( void * V_195 )
{
if ( F_6 ( V_196 ) ) {
F_176 () ;
F_4 ( V_196 , 0 ) ;
}
}
void F_182 ( void )
{
F_181 ( NULL ) ;
}
static int F_183 ( struct V_197 * V_198 ,
unsigned long V_199 ,
void * V_74 )
{
switch ( V_199 ) {
case V_200 :
if ( F_6 ( V_196 ) )
F_176 () ;
return V_201 ;
case V_202 :
if ( F_6 ( V_196 ) )
F_173 () ;
return V_201 ;
default:
return V_203 ;
}
}
static void T_8 F_184 ( void )
{
F_185 ( & V_204 ) ;
}
static void T_8 F_186 ( void )
{
F_187 ( & V_204 ) ;
}
static inline void F_184 ( void )
{
}
static inline void F_186 ( void )
{
}
static void F_188 ( void )
{
F_22 ( V_68 ) ;
}
static int F_189 ( void )
{
V_68 = F_13 ( V_205 ) ;
if ( ! V_68 ) {
F_190 ( L_1 ) ;
return - V_12 ;
}
V_86 = F_191 () ;
F_192 ( L_2 , V_86 ) ;
return 0 ;
}
static int F_193 ( void )
{
int V_54 = 0 ;
F_194 ( F_179 , NULL , 1 ) ;
F_184 () ;
V_54 = F_195 () ;
switch ( V_54 ) {
case 0 :
V_18 = true ;
break;
case - V_180 :
case - V_138 :
V_18 = false ;
V_54 = 0 ;
break;
default:
goto V_56;
}
V_54 = F_196 () ;
if ( V_54 )
goto V_56;
F_197 () ;
F_198 () ;
V_56:
F_194 ( F_181 , NULL , 1 ) ;
return V_54 ;
}
static void F_199 ( void )
{
int V_8 ;
if ( F_170 () )
return;
F_200 () ;
F_15 (cpu)
F_201 ( F_202 ( V_191 , V_8 ) ) ;
F_186 () ;
}
static int F_203 ( void )
{
F_192 ( L_3 ) ;
return 0 ;
}
static int F_204 ( void )
{
int V_8 ;
int V_54 = 0 ;
V_54 = F_205 () ;
if ( V_54 )
goto V_206;
V_194 = F_174 () ;
F_15 (cpu) {
unsigned long V_189 ;
V_189 = F_206 ( V_58 ) ;
if ( ! V_189 ) {
V_54 = - V_12 ;
goto V_206;
}
F_202 ( V_191 , V_8 ) = V_189 ;
}
V_54 = F_18 ( F_167 ( V_207 ) ,
F_167 ( V_208 ) , V_209 ) ;
if ( V_54 ) {
F_190 ( L_4 ) ;
goto V_206;
}
V_54 = F_18 ( F_167 ( V_210 ) ,
F_167 ( V_211 ) , V_212 ) ;
if ( V_54 ) {
F_190 ( L_5 ) ;
goto V_206;
}
V_54 = F_18 ( F_167 ( V_213 ) ,
F_167 ( V_214 ) , V_212 ) ;
if ( V_54 ) {
F_190 ( L_6 ) ;
goto V_206;
}
F_15 (cpu) {
char * V_189 = ( char * ) F_202 ( V_191 , V_8 ) ;
V_54 = F_18 ( V_189 , V_189 + V_192 ,
V_14 ) ;
if ( V_54 ) {
F_190 ( L_7 ) ;
goto V_206;
}
}
F_15 (cpu) {
V_205 * V_215 ;
V_215 = F_16 ( V_68 , V_8 ) ;
V_54 = F_18 ( V_215 , V_215 + 1 , V_14 ) ;
if ( V_54 ) {
F_190 ( L_8 , V_54 ) ;
goto V_206;
}
}
F_192 ( L_9 ) ;
return 0 ;
V_206:
F_199 () ;
F_190 ( L_10 , V_54 ) ;
return V_54 ;
}
static void F_207 ( void * V_7 )
{
* ( int * ) V_7 = F_133 () ;
}
struct V_1 * F_208 ( struct V_6 * V_6 , unsigned long V_216 )
{
struct V_1 * V_2 ;
int V_23 ;
V_216 &= V_217 ;
F_90 (i, vcpu, kvm) {
if ( V_216 == F_209 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_210 ( void * V_218 )
{
int V_54 ;
int V_7 , V_8 ;
if ( ! F_211 () ) {
F_190 ( L_11 ) ;
return - V_180 ;
}
F_212 (cpu) {
F_213 ( V_8 , F_207 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_190 ( L_12 , V_8 ) ;
return - V_180 ;
}
}
V_54 = F_189 () ;
if ( V_54 )
return V_54 ;
if ( F_170 () )
V_54 = F_203 () ;
else
V_54 = F_204 () ;
if ( V_54 )
goto V_206;
V_54 = F_193 () ;
if ( V_54 )
goto V_219;
return 0 ;
V_219:
F_199 () ;
V_206:
F_188 () ;
return V_54 ;
}
void F_214 ( void )
{
F_215 () ;
}
static int F_216 ( void )
{
int V_220 = F_217 ( NULL , sizeof( struct V_1 ) , 0 , V_221 ) ;
return V_220 ;
}
