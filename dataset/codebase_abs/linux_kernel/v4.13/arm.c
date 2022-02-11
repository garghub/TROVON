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
V_26 = 1 ;
break;
case V_40 :
V_26 = F_30 () ;
break;
case V_41 :
V_26 = V_19 ;
break;
case V_42 :
V_26 = V_43 ;
break;
case V_44 :
if ( ! V_6 )
V_26 = - V_9 ;
else
V_26 = V_6 -> V_10 . V_45 . V_46 ;
break;
case V_47 :
V_26 = 1 ;
break;
default:
V_26 = F_31 ( V_6 , V_25 ) ;
break;
}
return V_26 ;
}
long F_32 ( struct V_48 * V_49 ,
unsigned int V_50 , unsigned long V_51 )
{
return - V_9 ;
}
struct V_1 * F_33 ( struct V_6 * V_6 , unsigned int V_52 )
{
int V_53 ;
struct V_1 * V_2 ;
if ( F_34 ( V_6 ) && F_35 ( V_6 ) ) {
V_53 = - V_54 ;
goto V_55;
}
if ( V_52 >= V_6 -> V_10 . V_17 ) {
V_53 = - V_9 ;
goto V_55;
}
V_2 = F_36 ( V_56 , V_57 ) ;
if ( ! V_2 ) {
V_53 = - V_12 ;
goto V_55;
}
V_53 = F_37 ( V_2 , V_6 , V_52 ) ;
if ( V_53 )
goto V_58;
V_53 = F_18 ( V_2 , V_2 + 1 , V_14 ) ;
if ( V_53 )
goto V_59;
return V_2 ;
V_59:
F_38 ( V_2 ) ;
V_58:
F_39 ( V_56 , V_2 ) ;
V_55:
return F_40 ( V_53 ) ;
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
F_39 ( V_56 , V_2 ) ;
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
V_2 -> V_10 . V_60 = - 1 ;
F_57 ( V_2 -> V_10 . V_61 , V_62 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
return F_60 ( V_2 ) ;
}
void F_61 ( struct V_1 * V_2 , int V_8 )
{
int * V_63 ;
V_63 = F_62 ( V_2 -> V_6 -> V_10 . V_11 ) ;
if ( * V_63 != V_2 -> V_64 ) {
F_63 ( V_65 , V_2 ) ;
* V_63 = V_2 -> V_64 ;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_10 . V_66 = F_62 ( V_67 ) ;
F_1 ( V_2 ) ;
F_64 ( V_2 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
F_66 ( V_2 ) ;
V_2 -> V_8 = - 1 ;
F_1 ( NULL ) ;
F_67 ( V_2 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_68 = true ;
F_69 ( V_69 , V_2 ) ;
F_70 ( V_2 ) ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
if ( V_2 -> V_10 . V_68 )
V_71 -> V_71 = V_72 ;
else
V_71 -> V_71 = V_73 ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
switch ( V_71 -> V_71 ) {
case V_73 :
V_2 -> V_10 . V_68 = false ;
break;
case V_72 :
F_68 ( V_2 ) ;
break;
default:
return - V_9 ;
}
return 0 ;
}
int F_73 ( struct V_1 * V_74 )
{
return ( ( ! ! V_74 -> V_10 . V_75 || F_74 ( V_74 ) )
&& ! V_74 -> V_10 . V_68 && ! V_74 -> V_10 . V_76 ) ;
}
static void F_75 ( void * V_77 )
{
}
void F_76 ( const T_2 * V_78 )
{
F_77 () ;
F_78 ( V_78 , F_75 , NULL , true ) ;
F_79 () ;
}
static bool F_80 ( struct V_6 * V_6 )
{
return F_81 ( V_6 -> V_10 . V_16 != F_82 ( & V_79 ) ) ;
}
static void F_83 ( struct V_6 * V_6 )
{
T_3 V_80 ;
T_4 V_81 ;
if ( ! F_80 ( V_6 ) )
return;
F_84 ( & V_82 ) ;
if ( ! F_80 ( V_6 ) ) {
F_85 ( & V_82 ) ;
return;
}
if ( F_81 ( V_83 == 0 ) ) {
F_86 ( & V_79 ) ;
V_83 = 1 ;
F_76 ( V_84 ) ;
F_63 ( V_85 ) ;
}
V_6 -> V_10 . V_16 = F_82 ( & V_79 ) ;
V_6 -> V_10 . V_81 = V_83 ;
V_83 ++ ;
V_83 &= ( 1 << V_86 ) - 1 ;
V_80 = F_87 ( V_6 -> V_10 . V_87 ) ;
F_2 ( V_80 & ~ V_88 ) ;
V_81 = ( ( T_4 ) ( V_6 -> V_10 . V_81 ) << V_89 ) & F_88 ( V_86 ) ;
V_6 -> V_10 . V_90 = V_80 | V_81 ;
F_85 ( & V_82 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
if ( F_90 ( V_2 -> V_10 . V_91 ) )
return 0 ;
V_2 -> V_10 . V_91 = true ;
if ( F_81 ( F_34 ( V_6 ) && ! F_91 ( V_6 ) ) ) {
V_7 = F_92 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_93 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_94 ( V_2 ) ;
return V_7 ;
}
bool F_95 ( struct V_6 * V_6 )
{
return F_35 ( V_6 ) ;
}
void F_96 ( struct V_6 * V_6 )
{
int V_23 ;
struct V_1 * V_2 ;
F_97 (i, vcpu, kvm)
V_2 -> V_10 . V_76 = true ;
F_98 ( V_6 , V_69 ) ;
}
void F_99 ( struct V_6 * V_6 )
{
int V_23 ;
struct V_1 * V_2 ;
F_97 (i, vcpu, kvm) {
V_2 -> V_10 . V_76 = false ;
F_100 ( F_101 ( V_2 ) ) ;
}
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_92 * V_93 = F_101 ( V_2 ) ;
F_103 ( * V_93 , ( ( ! V_2 -> V_10 . V_68 ) &&
( ! V_2 -> V_10 . V_76 ) ) ) ;
if ( V_2 -> V_10 . V_68 || V_2 -> V_10 . V_76 ) {
F_69 ( V_69 , V_2 ) ;
}
}
static int F_104 ( struct V_1 * V_2 )
{
return V_2 -> V_10 . V_60 >= 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
if ( F_106 ( V_2 ) ) {
if ( F_107 ( V_69 , V_2 ) )
F_102 ( V_2 ) ;
F_107 ( V_94 , V_2 ) ;
}
}
int F_108 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
int V_7 ;
T_5 V_97 ;
if ( F_81 ( ! F_104 ( V_2 ) ) )
return - V_98 ;
V_7 = F_89 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_96 -> V_99 == V_100 ) {
V_7 = F_109 ( V_2 , V_2 -> V_96 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_96 -> V_101 )
return - V_102 ;
if ( V_2 -> V_103 )
F_110 ( V_104 , & V_2 -> V_105 , & V_97 ) ;
V_7 = 1 ;
V_96 -> V_99 = V_106 ;
while ( V_7 > 0 ) {
F_111 () ;
F_83 ( V_2 -> V_6 ) ;
F_105 ( V_2 ) ;
F_77 () ;
F_112 ( V_2 ) ;
F_113 ( V_2 ) ;
F_114 ( V_2 ) ;
F_115 () ;
if ( F_116 ( V_107 ) ||
F_117 ( V_2 ) ||
F_118 ( V_2 ) ) {
V_7 = - V_102 ;
V_96 -> V_99 = V_108 ;
}
F_119 ( V_2 -> V_109 , V_4 ) ;
if ( V_7 <= 0 || F_80 ( V_2 -> V_6 ) ||
F_106 ( V_2 ) ) {
V_2 -> V_109 = V_110 ;
F_120 () ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_79 () ;
continue;
}
F_124 ( V_2 ) ;
F_125 ( * F_126 ( V_2 ) ) ;
F_127 () ;
V_7 = F_63 ( V_111 , V_2 ) ;
V_2 -> V_109 = V_110 ;
V_2 -> V_112 . V_113 ++ ;
F_128 ( V_2 ) ;
F_120 () ;
F_129 () ;
F_130 ( V_7 , F_131 ( V_2 ) , * F_126 ( V_2 ) ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_79 () ;
V_7 = F_132 ( V_2 , V_96 , V_7 ) ;
}
if ( F_81 ( ! F_34 ( V_2 -> V_6 ) ) ) {
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
}
if ( V_2 -> V_103 )
F_110 ( V_104 , & V_97 , NULL ) ;
return V_7 ;
}
static int F_135 ( struct V_1 * V_2 , int V_114 , bool V_115 )
{
int V_116 ;
bool V_117 ;
unsigned long * V_118 ;
if ( V_114 == V_119 )
V_116 = F_136 ( V_120 ) ;
else
V_116 = F_136 ( V_121 ) ;
V_118 = ( unsigned long * ) & V_2 -> V_10 . V_75 ;
if ( V_115 )
V_117 = F_137 ( V_116 , V_118 ) ;
else
V_117 = F_138 ( V_116 , V_118 ) ;
if ( V_117 == V_115 )
return 0 ;
F_69 ( V_94 , V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
int F_139 ( struct V_6 * V_6 , struct V_122 * V_123 ,
bool V_124 )
{
T_6 V_125 = V_123 -> V_125 ;
unsigned int V_126 , V_127 , V_128 ;
int V_129 = F_140 ( & V_6 -> V_130 ) ;
struct V_1 * V_2 = NULL ;
bool V_115 = V_123 -> V_115 ;
V_126 = ( V_125 >> V_131 ) & V_132 ;
V_127 = ( V_125 >> V_133 ) & V_134 ;
V_128 = ( V_125 >> V_135 ) & V_136 ;
F_141 ( V_126 , V_127 , V_128 , V_123 -> V_115 ) ;
switch ( V_126 ) {
case V_137 :
if ( F_34 ( V_6 ) )
return - V_138 ;
if ( V_127 >= V_129 )
return - V_9 ;
V_2 = F_142 ( V_6 , V_127 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_128 > V_139 )
return - V_9 ;
return F_135 ( V_2 , V_128 , V_115 ) ;
case V_140 :
if ( ! F_34 ( V_6 ) )
return - V_138 ;
if ( V_127 >= V_129 )
return - V_9 ;
V_2 = F_142 ( V_6 , V_127 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_128 < V_141 || V_128 >= V_142 )
return - V_9 ;
return F_143 ( V_6 , V_2 -> V_64 , V_128 , V_115 , NULL ) ;
case V_143 :
if ( ! F_34 ( V_6 ) )
return - V_138 ;
if ( V_128 < V_142 )
return - V_9 ;
return F_143 ( V_6 , 0 , V_128 , V_115 , NULL ) ;
}
return - V_9 ;
}
static int F_144 ( struct V_1 * V_2 ,
const struct F_37 * V_144 )
{
unsigned int V_23 ;
int V_145 = F_145 () ;
if ( V_144 -> V_60 != V_145 )
return - V_9 ;
if ( V_2 -> V_10 . V_60 != - 1 && V_2 -> V_10 . V_60 != V_144 -> V_60 )
return - V_9 ;
for ( V_23 = 0 ; V_23 < sizeof( V_144 -> V_61 ) * 8 ; V_23 ++ ) {
bool V_117 = ( V_144 -> V_61 [ V_23 / 32 ] & ( 1 << ( V_23 % 32 ) ) ) ;
if ( V_117 && V_23 >= V_62 )
return - V_146 ;
if ( V_2 -> V_10 . V_60 != - 1 && V_23 < V_62 &&
F_146 ( V_23 , V_2 -> V_10 . V_61 ) != V_117 )
return - V_9 ;
if ( V_117 )
F_147 ( V_23 , V_2 -> V_10 . V_61 ) ;
}
V_2 -> V_10 . V_60 = V_145 ;
return F_148 ( V_2 ) ;
}
static int F_149 ( struct V_1 * V_2 ,
struct F_37 * V_144 )
{
int V_7 ;
V_7 = F_144 ( V_2 , V_144 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_10 . V_91 )
F_150 ( V_2 -> V_6 ) ;
F_151 ( V_2 ) ;
if ( F_146 ( V_147 , V_2 -> V_10 . V_61 ) )
F_68 ( V_2 ) ;
else
V_2 -> V_10 . V_68 = false ;
return 0 ;
}
static int F_152 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
int V_7 = - V_138 ;
switch ( V_149 -> V_150 ) {
default:
V_7 = F_153 ( V_2 , V_149 ) ;
break;
}
return V_7 ;
}
static int F_154 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
int V_7 = - V_138 ;
switch ( V_149 -> V_150 ) {
default:
V_7 = F_155 ( V_2 , V_149 ) ;
break;
}
return V_7 ;
}
static int F_156 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
int V_7 = - V_138 ;
switch ( V_149 -> V_150 ) {
default:
V_7 = F_157 ( V_2 , V_149 ) ;
break;
}
return V_7 ;
}
long F_158 ( struct V_48 * V_49 ,
unsigned int V_50 , unsigned long V_51 )
{
struct V_1 * V_2 = V_49 -> V_151 ;
void T_7 * V_152 = ( void T_7 * ) V_51 ;
struct V_148 V_149 ;
switch ( V_50 ) {
case V_153 : {
struct F_37 V_144 ;
if ( F_159 ( & V_144 , V_152 , sizeof( V_144 ) ) )
return - V_154 ;
return F_149 ( V_2 , & V_144 ) ;
}
case V_155 :
case V_156 : {
struct V_157 V_158 ;
if ( F_81 ( ! F_104 ( V_2 ) ) )
return - V_98 ;
if ( F_159 ( & V_158 , V_152 , sizeof( V_158 ) ) )
return - V_154 ;
if ( V_50 == V_155 )
return F_160 ( V_2 , & V_158 ) ;
else
return F_161 ( V_2 , & V_158 ) ;
}
case V_159 : {
struct V_160 T_7 * V_161 = V_152 ;
struct V_160 V_162 ;
unsigned V_163 ;
if ( F_81 ( ! F_104 ( V_2 ) ) )
return - V_98 ;
if ( F_159 ( & V_162 , V_161 , sizeof( V_162 ) ) )
return - V_154 ;
V_163 = V_162 . V_163 ;
V_162 . V_163 = F_162 ( V_2 ) ;
if ( F_163 ( V_161 , & V_162 , sizeof( V_162 ) ) )
return - V_154 ;
if ( V_163 < V_162 . V_163 )
return - V_164 ;
return F_164 ( V_2 , V_161 -> V_158 ) ;
}
case V_165 : {
if ( F_159 ( & V_149 , V_152 , sizeof( V_149 ) ) )
return - V_154 ;
return F_152 ( V_2 , & V_149 ) ;
}
case V_166 : {
if ( F_159 ( & V_149 , V_152 , sizeof( V_149 ) ) )
return - V_154 ;
return F_154 ( V_2 , & V_149 ) ;
}
case V_167 : {
if ( F_159 ( & V_149 , V_152 , sizeof( V_149 ) ) )
return - V_154 ;
return F_156 ( V_2 , & V_149 ) ;
}
default:
return - V_9 ;
}
}
int F_165 ( struct V_6 * V_6 , struct V_168 * log )
{
bool V_169 = false ;
int V_26 ;
F_166 ( & V_6 -> V_170 ) ;
V_26 = F_167 ( V_6 , log , & V_169 ) ;
if ( V_169 )
F_168 ( V_6 ) ;
F_169 ( & V_6 -> V_170 ) ;
return V_26 ;
}
static int F_170 ( struct V_6 * V_6 ,
struct V_171 * V_172 )
{
unsigned long V_173 , type ;
V_173 = ( V_172 -> V_52 & V_174 ) >>
V_175 ;
type = ( V_172 -> V_52 & V_176 ) >>
V_177 ;
switch ( V_173 ) {
case V_178 :
if ( ! V_18 )
return - V_138 ;
return F_171 ( V_6 , type , & V_172 -> V_179 , true ) ;
default:
return - V_180 ;
}
}
long F_172 ( struct V_48 * V_49 ,
unsigned int V_50 , unsigned long V_51 )
{
struct V_6 * V_6 = V_49 -> V_151 ;
void T_7 * V_152 = ( void T_7 * ) V_51 ;
switch ( V_50 ) {
case V_181 : {
int V_7 ;
if ( ! V_18 )
return - V_138 ;
F_166 ( & V_6 -> V_182 ) ;
V_7 = F_173 ( V_6 , V_183 ) ;
F_169 ( & V_6 -> V_182 ) ;
return V_7 ;
}
case V_184 : {
struct V_171 V_172 ;
if ( F_159 ( & V_172 , V_152 , sizeof( V_172 ) ) )
return - V_154 ;
return F_170 ( V_6 , & V_172 ) ;
}
case V_185 : {
int V_53 ;
struct F_37 V_144 ;
V_53 = F_174 ( & V_144 ) ;
if ( V_53 )
return V_53 ;
if ( F_163 ( V_152 , & V_144 , sizeof( V_144 ) ) )
return - V_154 ;
return 0 ;
}
default:
return - V_9 ;
}
}
static void F_175 ( void * V_186 )
{
T_3 V_187 ;
unsigned long V_188 ;
unsigned long V_189 ;
unsigned long V_190 ;
F_176 ( F_177 () ) ;
V_187 = F_178 () ;
V_189 = F_6 ( V_191 ) ;
V_188 = V_189 + V_192 ;
V_190 = ( unsigned long ) F_179 ( V_193 ) ;
F_180 ( V_187 , V_188 , V_190 ) ;
F_181 () ;
F_182 () ;
}
static void F_183 ( void )
{
if ( ! F_184 () )
F_185 () ;
}
static void F_186 ( void )
{
F_183 () ;
if ( F_184 () ) {
F_181 () ;
F_187 () ;
} else {
F_175 ( NULL ) ;
}
if ( V_18 )
F_188 () ;
}
static void F_189 ( void * V_194 )
{
if ( ! F_6 ( V_195 ) ) {
F_186 () ;
F_4 ( V_195 , 1 ) ;
}
}
int F_190 ( void )
{
F_189 ( NULL ) ;
return 0 ;
}
static void F_191 ( void * V_194 )
{
if ( F_6 ( V_195 ) ) {
F_183 () ;
F_4 ( V_195 , 0 ) ;
}
}
void F_192 ( void )
{
F_191 ( NULL ) ;
}
static int F_193 ( struct V_196 * V_197 ,
unsigned long V_198 ,
void * V_74 )
{
switch ( V_198 ) {
case V_199 :
if ( F_6 ( V_195 ) )
F_183 () ;
return V_200 ;
case V_201 :
if ( F_6 ( V_195 ) )
F_186 () ;
return V_200 ;
default:
return V_202 ;
}
}
static void T_8 F_194 ( void )
{
F_195 ( & V_203 ) ;
}
static void T_8 F_196 ( void )
{
F_197 ( & V_203 ) ;
}
static inline void F_194 ( void )
{
}
static inline void F_196 ( void )
{
}
static void F_198 ( void )
{
F_22 ( V_67 ) ;
}
static int F_199 ( void )
{
V_67 = F_13 ( V_204 ) ;
if ( ! V_67 ) {
F_200 ( L_1 ) ;
return - V_12 ;
}
V_86 = F_201 () ;
F_202 ( L_2 , V_86 ) ;
return 0 ;
}
static int F_203 ( void )
{
int V_53 = 0 ;
F_204 ( F_189 , NULL , 1 ) ;
F_194 () ;
V_53 = F_205 () ;
switch ( V_53 ) {
case 0 :
V_18 = true ;
break;
case - V_180 :
case - V_138 :
V_18 = false ;
V_53 = 0 ;
break;
default:
goto V_55;
}
V_53 = F_206 () ;
if ( V_53 )
goto V_55;
F_207 () ;
F_208 () ;
V_55:
F_204 ( F_191 , NULL , 1 ) ;
return V_53 ;
}
static void F_209 ( void )
{
int V_8 ;
if ( F_184 () )
return;
F_210 () ;
F_15 (cpu)
F_211 ( F_212 ( V_191 , V_8 ) ) ;
F_196 () ;
}
static int F_213 ( void )
{
F_202 ( L_3 ) ;
return 0 ;
}
static int F_214 ( void )
{
int V_8 ;
int V_53 = 0 ;
V_53 = F_215 () ;
if ( V_53 )
goto V_205;
F_15 (cpu) {
unsigned long V_189 ;
V_189 = F_216 ( V_57 ) ;
if ( ! V_189 ) {
V_53 = - V_12 ;
goto V_205;
}
F_212 ( V_191 , V_8 ) = V_189 ;
}
V_53 = F_18 ( F_179 ( V_206 ) ,
F_179 ( V_207 ) , V_208 ) ;
if ( V_53 ) {
F_200 ( L_4 ) ;
goto V_205;
}
V_53 = F_18 ( F_179 ( V_209 ) ,
F_179 ( V_210 ) , V_211 ) ;
if ( V_53 ) {
F_200 ( L_5 ) ;
goto V_205;
}
V_53 = F_18 ( F_179 ( V_212 ) ,
F_179 ( V_213 ) , V_211 ) ;
if ( V_53 ) {
F_200 ( L_6 ) ;
goto V_205;
}
F_15 (cpu) {
char * V_189 = ( char * ) F_212 ( V_191 , V_8 ) ;
V_53 = F_18 ( V_189 , V_189 + V_192 ,
V_14 ) ;
if ( V_53 ) {
F_200 ( L_7 ) ;
goto V_205;
}
}
F_15 (cpu) {
V_204 * V_214 ;
V_214 = F_16 ( V_67 , V_8 ) ;
V_53 = F_18 ( V_214 , V_214 + 1 , V_14 ) ;
if ( V_53 ) {
F_200 ( L_8 , V_53 ) ;
goto V_205;
}
}
F_202 ( L_9 ) ;
return 0 ;
V_205:
F_209 () ;
F_200 ( L_10 , V_53 ) ;
return V_53 ;
}
static void F_217 ( void * V_7 )
{
* ( int * ) V_7 = F_145 () ;
}
struct V_1 * F_218 ( struct V_6 * V_6 , unsigned long V_215 )
{
struct V_1 * V_2 ;
int V_23 ;
V_215 &= V_216 ;
F_97 (i, vcpu, kvm) {
if ( V_215 == F_219 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_220 ( void * V_217 )
{
int V_53 ;
int V_7 , V_8 ;
if ( ! F_221 () ) {
F_200 ( L_11 ) ;
return - V_180 ;
}
F_222 (cpu) {
F_223 ( V_8 , F_217 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_200 ( L_12 , V_8 ) ;
return - V_180 ;
}
}
V_53 = F_199 () ;
if ( V_53 )
return V_53 ;
if ( F_184 () )
V_53 = F_213 () ;
else
V_53 = F_214 () ;
if ( V_53 )
goto V_205;
V_53 = F_203 () ;
if ( V_53 )
goto V_218;
return 0 ;
V_218:
F_209 () ;
V_205:
F_198 () ;
return V_53 ;
}
void F_224 ( void )
{
F_225 () ;
}
static int F_226 ( void )
{
int V_219 = F_227 ( NULL , sizeof( struct V_1 ) , 0 , V_220 ) ;
return V_219 ;
}
