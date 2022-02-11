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
case V_43 :
if ( ! V_6 )
V_26 = - V_9 ;
else
V_26 = V_6 -> V_10 . V_44 . V_45 ;
break;
default:
V_26 = F_32 ( V_6 , V_25 ) ;
break;
}
return V_26 ;
}
long F_33 ( struct V_46 * V_47 ,
unsigned int V_48 , unsigned long V_49 )
{
return - V_9 ;
}
struct V_1 * F_34 ( struct V_6 * V_6 , unsigned int V_50 )
{
int V_51 ;
struct V_1 * V_2 ;
if ( F_35 ( V_6 ) && F_36 ( V_6 ) ) {
V_51 = - V_52 ;
goto V_53;
}
if ( V_50 >= V_6 -> V_10 . V_17 ) {
V_51 = - V_9 ;
goto V_53;
}
V_2 = F_37 ( V_54 , V_55 ) ;
if ( ! V_2 ) {
V_51 = - V_12 ;
goto V_53;
}
V_51 = F_38 ( V_2 , V_6 , V_50 ) ;
if ( V_51 )
goto V_56;
V_51 = F_18 ( V_2 , V_2 + 1 , V_14 ) ;
if ( V_51 )
goto V_57;
return V_2 ;
V_57:
F_39 ( V_2 ) ;
V_56:
F_40 ( V_54 , V_2 ) ;
V_53:
return F_41 ( V_51 ) ;
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
F_40 ( V_54 , V_2 ) ;
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
V_2 -> V_10 . V_58 = - 1 ;
F_56 ( V_2 -> V_10 . V_59 , V_60 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
void F_59 ( struct V_1 * V_2 , int V_8 )
{
int * V_61 ;
V_61 = F_60 ( V_2 -> V_6 -> V_10 . V_11 ) ;
if ( * V_61 != V_2 -> V_62 ) {
F_61 ( V_63 , V_2 ) ;
* V_61 = V_2 -> V_62 ;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_10 . V_64 = F_60 ( V_65 ) ;
F_1 ( V_2 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
V_2 -> V_8 = - 1 ;
F_1 ( NULL ) ;
F_63 ( V_2 ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
if ( V_2 -> V_10 . V_68 )
V_67 -> V_67 = V_69 ;
else
V_67 -> V_67 = V_70 ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
switch ( V_67 -> V_67 ) {
case V_70 :
V_2 -> V_10 . V_68 = false ;
break;
case V_69 :
V_2 -> V_10 . V_68 = true ;
break;
default:
return - V_9 ;
}
return 0 ;
}
int F_66 ( struct V_1 * V_71 )
{
return ( ( ! ! V_71 -> V_10 . V_72 || F_67 ( V_71 ) )
&& ! V_71 -> V_10 . V_68 && ! V_71 -> V_10 . V_73 ) ;
}
static void F_68 ( void * V_74 )
{
}
void F_69 ( const T_2 * V_75 )
{
F_70 () ;
F_71 ( V_75 , F_68 , NULL , true ) ;
F_72 () ;
}
static bool F_73 ( struct V_6 * V_6 )
{
return F_74 ( V_6 -> V_10 . V_16 != F_75 ( & V_76 ) ) ;
}
static void F_76 ( struct V_6 * V_6 )
{
T_3 V_77 ;
T_4 V_78 ;
if ( ! F_73 ( V_6 ) )
return;
F_77 ( & V_79 ) ;
if ( ! F_73 ( V_6 ) ) {
F_78 ( & V_79 ) ;
return;
}
if ( F_74 ( V_80 == 0 ) ) {
F_79 ( & V_76 ) ;
V_80 = 1 ;
F_69 ( V_81 ) ;
F_61 ( V_82 ) ;
}
V_6 -> V_10 . V_16 = F_75 ( & V_76 ) ;
V_6 -> V_10 . V_78 = V_80 ;
V_80 ++ ;
V_80 &= ( 1 << V_83 ) - 1 ;
V_77 = F_80 ( V_6 -> V_10 . V_84 ) ;
F_2 ( V_77 & ~ V_85 ) ;
V_78 = ( ( T_4 ) ( V_6 -> V_10 . V_78 ) << V_86 ) & F_81 ( V_83 ) ;
V_6 -> V_10 . V_87 = V_77 | V_78 ;
F_78 ( & V_79 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
if ( F_83 ( V_2 -> V_10 . V_88 ) )
return 0 ;
V_2 -> V_10 . V_88 = true ;
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
V_2 -> V_10 . V_73 = true ;
F_90 ( V_6 , V_89 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_73 = true ;
F_92 ( V_2 ) ;
}
void F_93 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = F_94 ( V_2 ) ;
V_2 -> V_10 . V_73 = false ;
F_95 ( V_91 ) ;
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
struct V_90 * V_91 = F_94 ( V_2 ) ;
F_98 ( * V_91 , ( ( ! V_2 -> V_10 . V_68 ) &&
( ! V_2 -> V_10 . V_73 ) ) ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
return V_2 -> V_10 . V_58 >= 0 ;
}
int F_100 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
int V_7 ;
T_5 V_94 ;
if ( F_74 ( ! F_99 ( V_2 ) ) )
return - V_95 ;
V_7 = F_82 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_93 -> V_96 == V_97 ) {
V_7 = F_101 ( V_2 , V_2 -> V_93 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_98 )
F_102 ( V_99 , & V_2 -> V_100 , & V_94 ) ;
V_7 = 1 ;
V_93 -> V_96 = V_101 ;
while ( V_7 > 0 ) {
F_103 () ;
F_76 ( V_2 -> V_6 ) ;
if ( V_2 -> V_10 . V_68 || V_2 -> V_10 . V_73 )
F_97 ( V_2 ) ;
F_70 () ;
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
F_107 () ;
if ( F_108 ( V_102 ) ) {
V_7 = - V_103 ;
V_93 -> V_96 = V_104 ;
}
if ( V_7 <= 0 || F_73 ( V_2 -> V_6 ) ||
V_2 -> V_10 . V_68 || V_2 -> V_10 . V_73 ) {
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
V_2 -> V_105 = V_4 ;
V_7 = F_61 ( V_106 , V_2 ) ;
V_2 -> V_105 = V_107 ;
V_2 -> V_108 . V_109 ++ ;
F_117 ( V_2 ) ;
F_109 () ;
F_118 () ;
F_119 ( V_7 , F_120 ( V_2 ) , * F_115 ( V_2 ) ) ;
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
F_72 () ;
V_7 = F_121 ( V_2 , V_93 , V_7 ) ;
}
if ( V_2 -> V_98 )
F_102 ( V_99 , & V_94 , NULL ) ;
return V_7 ;
}
static int F_122 ( struct V_1 * V_2 , int V_110 , bool V_111 )
{
int V_112 ;
bool V_113 ;
unsigned long * V_114 ;
if ( V_110 == V_115 )
V_112 = F_123 ( V_116 ) ;
else
V_112 = F_123 ( V_117 ) ;
V_114 = ( unsigned long * ) & V_2 -> V_10 . V_72 ;
if ( V_111 )
V_113 = F_124 ( V_112 , V_114 ) ;
else
V_113 = F_125 ( V_112 , V_114 ) ;
if ( V_113 == V_111 )
return 0 ;
F_92 ( V_2 ) ;
return 0 ;
}
int F_126 ( struct V_6 * V_6 , struct V_118 * V_119 ,
bool V_120 )
{
T_6 V_121 = V_119 -> V_121 ;
unsigned int V_122 , V_123 , V_124 ;
int V_125 = F_127 ( & V_6 -> V_126 ) ;
struct V_1 * V_2 = NULL ;
bool V_111 = V_119 -> V_111 ;
V_122 = ( V_121 >> V_127 ) & V_128 ;
V_123 = ( V_121 >> V_129 ) & V_130 ;
V_124 = ( V_121 >> V_131 ) & V_132 ;
F_128 ( V_122 , V_123 , V_124 , V_119 -> V_111 ) ;
switch ( V_122 ) {
case V_133 :
if ( F_35 ( V_6 ) )
return - V_134 ;
if ( V_123 >= V_125 )
return - V_9 ;
V_2 = F_129 ( V_6 , V_123 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_124 > V_135 )
return - V_9 ;
return F_122 ( V_2 , V_124 , V_111 ) ;
case V_136 :
if ( ! F_35 ( V_6 ) )
return - V_134 ;
if ( V_123 >= V_125 )
return - V_9 ;
V_2 = F_129 ( V_6 , V_123 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_124 < V_137 || V_124 >= V_138 )
return - V_9 ;
return F_130 ( V_6 , V_2 -> V_62 , V_124 , V_111 ) ;
case V_139 :
if ( ! F_35 ( V_6 ) )
return - V_134 ;
if ( V_124 < V_138 )
return - V_9 ;
return F_130 ( V_6 , 0 , V_124 , V_111 ) ;
}
return - V_9 ;
}
static int F_131 ( struct V_1 * V_2 ,
const struct F_38 * V_140 )
{
unsigned int V_23 ;
int V_141 = F_132 () ;
if ( V_140 -> V_58 != V_141 )
return - V_9 ;
if ( V_2 -> V_10 . V_58 != - 1 && V_2 -> V_10 . V_58 != V_140 -> V_58 )
return - V_9 ;
for ( V_23 = 0 ; V_23 < sizeof( V_140 -> V_59 ) * 8 ; V_23 ++ ) {
bool V_113 = ( V_140 -> V_59 [ V_23 / 32 ] & ( 1 << ( V_23 % 32 ) ) ) ;
if ( V_113 && V_23 >= V_60 )
return - V_142 ;
if ( V_2 -> V_10 . V_58 != - 1 && V_23 < V_60 &&
F_133 ( V_23 , V_2 -> V_10 . V_59 ) != V_113 )
return - V_9 ;
if ( V_113 )
F_134 ( V_23 , V_2 -> V_10 . V_59 ) ;
}
V_2 -> V_10 . V_58 = V_141 ;
return F_135 ( V_2 ) ;
}
static int F_136 ( struct V_1 * V_2 ,
struct F_38 * V_140 )
{
int V_7 ;
V_7 = F_131 ( V_2 , V_140 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_10 . V_88 )
F_137 ( V_2 -> V_6 ) ;
F_138 ( V_2 ) ;
if ( F_133 ( V_143 , V_2 -> V_10 . V_59 ) )
V_2 -> V_10 . V_68 = true ;
else
V_2 -> V_10 . V_68 = false ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
int V_7 = - V_134 ;
switch ( V_145 -> V_146 ) {
default:
V_7 = F_140 ( V_2 , V_145 ) ;
break;
}
return V_7 ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
int V_7 = - V_134 ;
switch ( V_145 -> V_146 ) {
default:
V_7 = F_142 ( V_2 , V_145 ) ;
break;
}
return V_7 ;
}
static int F_143 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
int V_7 = - V_134 ;
switch ( V_145 -> V_146 ) {
default:
V_7 = F_144 ( V_2 , V_145 ) ;
break;
}
return V_7 ;
}
long F_145 ( struct V_46 * V_47 ,
unsigned int V_48 , unsigned long V_49 )
{
struct V_1 * V_2 = V_47 -> V_147 ;
void T_7 * V_148 = ( void T_7 * ) V_49 ;
struct V_144 V_145 ;
switch ( V_48 ) {
case V_149 : {
struct F_38 V_140 ;
if ( F_146 ( & V_140 , V_148 , sizeof( V_140 ) ) )
return - V_150 ;
return F_136 ( V_2 , & V_140 ) ;
}
case V_151 :
case V_152 : {
struct V_153 V_154 ;
if ( F_74 ( ! F_99 ( V_2 ) ) )
return - V_95 ;
if ( F_146 ( & V_154 , V_148 , sizeof( V_154 ) ) )
return - V_150 ;
if ( V_48 == V_151 )
return F_147 ( V_2 , & V_154 ) ;
else
return F_148 ( V_2 , & V_154 ) ;
}
case V_155 : {
struct V_156 T_7 * V_157 = V_148 ;
struct V_156 V_158 ;
unsigned V_159 ;
if ( F_74 ( ! F_99 ( V_2 ) ) )
return - V_95 ;
if ( F_146 ( & V_158 , V_157 , sizeof( V_158 ) ) )
return - V_150 ;
V_159 = V_158 . V_159 ;
V_158 . V_159 = F_149 ( V_2 ) ;
if ( F_150 ( V_157 , & V_158 , sizeof( V_158 ) ) )
return - V_150 ;
if ( V_159 < V_158 . V_159 )
return - V_160 ;
return F_151 ( V_2 , V_157 -> V_154 ) ;
}
case V_161 : {
if ( F_146 ( & V_145 , V_148 , sizeof( V_145 ) ) )
return - V_150 ;
return F_139 ( V_2 , & V_145 ) ;
}
case V_162 : {
if ( F_146 ( & V_145 , V_148 , sizeof( V_145 ) ) )
return - V_150 ;
return F_141 ( V_2 , & V_145 ) ;
}
case V_163 : {
if ( F_146 ( & V_145 , V_148 , sizeof( V_145 ) ) )
return - V_150 ;
return F_143 ( V_2 , & V_145 ) ;
}
default:
return - V_9 ;
}
}
int F_152 ( struct V_6 * V_6 , struct V_164 * log )
{
bool V_165 = false ;
int V_26 ;
F_153 ( & V_6 -> V_166 ) ;
V_26 = F_154 ( V_6 , log , & V_165 ) ;
if ( V_165 )
F_155 ( V_6 ) ;
F_156 ( & V_6 -> V_166 ) ;
return V_26 ;
}
static int F_157 ( struct V_6 * V_6 ,
struct V_167 * V_168 )
{
unsigned long V_169 , type ;
V_169 = ( V_168 -> V_50 & V_170 ) >>
V_171 ;
type = ( V_168 -> V_50 & V_172 ) >>
V_173 ;
switch ( V_169 ) {
case V_174 :
if ( ! V_18 )
return - V_134 ;
return F_158 ( V_6 , type , & V_168 -> V_175 , true ) ;
default:
return - V_176 ;
}
}
long F_159 ( struct V_46 * V_47 ,
unsigned int V_48 , unsigned long V_49 )
{
struct V_6 * V_6 = V_47 -> V_147 ;
void T_7 * V_148 = ( void T_7 * ) V_49 ;
switch ( V_48 ) {
case V_177 : {
int V_7 ;
if ( ! V_18 )
return - V_134 ;
F_153 ( & V_6 -> V_178 ) ;
V_7 = F_160 ( V_6 , V_179 ) ;
F_156 ( & V_6 -> V_178 ) ;
return V_7 ;
}
case V_180 : {
struct V_167 V_168 ;
if ( F_146 ( & V_168 , V_148 , sizeof( V_168 ) ) )
return - V_150 ;
return F_157 ( V_6 , & V_168 ) ;
}
case V_181 : {
int V_51 ;
struct F_38 V_140 ;
V_51 = F_161 ( & V_140 ) ;
if ( V_51 )
return V_51 ;
if ( F_150 ( V_148 , & V_140 , sizeof( V_140 ) ) )
return - V_150 ;
return 0 ;
}
default:
return - V_9 ;
}
}
static void F_162 ( void * V_182 )
{
T_3 V_183 ;
unsigned long V_184 ;
unsigned long V_185 ;
unsigned long V_186 ;
F_163 ( F_164 () ) ;
V_183 = F_165 () ;
V_185 = F_6 ( V_187 ) ;
V_184 = V_185 + V_188 ;
V_186 = ( unsigned long ) F_166 ( V_189 ) ;
F_167 ( V_183 , V_184 , V_186 ) ;
F_168 () ;
if ( F_169 () )
F_170 () ;
F_171 () ;
}
static void F_172 ( void )
{
if ( F_169 () ) {
F_168 () ;
} else {
if ( F_173 () == V_190 )
F_162 ( NULL ) ;
}
}
static void F_174 ( void )
{
if ( ! F_169 () )
F_175 ( V_190 ,
F_176 () ) ;
}
static void F_177 ( void * V_191 )
{
if ( ! F_6 ( V_192 ) ) {
F_172 () ;
F_4 ( V_192 , 1 ) ;
}
}
int F_178 ( void )
{
F_177 ( NULL ) ;
return 0 ;
}
static void F_179 ( void * V_191 )
{
if ( F_6 ( V_192 ) ) {
F_174 () ;
F_4 ( V_192 , 0 ) ;
}
}
void F_180 ( void )
{
F_179 ( NULL ) ;
}
static int F_181 ( struct V_193 * V_194 ,
unsigned long V_195 ,
void * V_71 )
{
switch ( V_195 ) {
case V_196 :
if ( F_6 ( V_192 ) )
F_174 () ;
return V_197 ;
case V_198 :
if ( F_6 ( V_192 ) )
F_172 () ;
return V_197 ;
default:
return V_199 ;
}
}
static void T_8 F_182 ( void )
{
F_183 ( & V_200 ) ;
}
static void T_8 F_184 ( void )
{
F_185 ( & V_200 ) ;
}
static inline void F_182 ( void )
{
}
static inline void F_184 ( void )
{
}
static void F_186 ( void )
{
F_23 ( V_65 ) ;
}
static int F_187 ( void )
{
V_65 = F_13 ( V_201 ) ;
if ( ! V_65 ) {
F_188 ( L_1 ) ;
return - V_12 ;
}
V_83 = F_189 () ;
F_190 ( L_2 , V_83 ) ;
return 0 ;
}
static int F_191 ( void )
{
int V_51 = 0 ;
F_192 ( F_177 , NULL , 1 ) ;
F_182 () ;
V_51 = F_193 () ;
switch ( V_51 ) {
case 0 :
V_18 = true ;
break;
case - V_176 :
case - V_134 :
V_18 = false ;
V_51 = 0 ;
break;
default:
goto V_53;
}
V_51 = F_194 () ;
if ( V_51 )
goto V_53;
F_195 () ;
F_196 () ;
V_53:
F_192 ( F_179 , NULL , 1 ) ;
return V_51 ;
}
static void F_197 ( void )
{
int V_8 ;
if ( F_169 () )
return;
F_198 () ;
F_15 (cpu)
F_199 ( F_200 ( V_187 , V_8 ) ) ;
F_184 () ;
}
static int F_201 ( void )
{
F_190 ( L_3 ) ;
return 0 ;
}
static int F_202 ( void )
{
int V_8 ;
int V_51 = 0 ;
V_51 = F_203 () ;
if ( V_51 )
goto V_202;
V_190 = F_173 () ;
F_15 (cpu) {
unsigned long V_185 ;
V_185 = F_204 ( V_55 ) ;
if ( ! V_185 ) {
V_51 = - V_12 ;
goto V_202;
}
F_200 ( V_187 , V_8 ) = V_185 ;
}
V_51 = F_18 ( F_166 ( V_203 ) ,
F_166 ( V_204 ) , V_205 ) ;
if ( V_51 ) {
F_188 ( L_4 ) ;
goto V_202;
}
V_51 = F_18 ( F_166 ( V_206 ) ,
F_166 ( V_207 ) , V_208 ) ;
if ( V_51 ) {
F_188 ( L_5 ) ;
goto V_202;
}
V_51 = F_18 ( F_166 ( V_209 ) ,
F_166 ( V_210 ) , V_208 ) ;
if ( V_51 ) {
F_188 ( L_6 ) ;
goto V_202;
}
F_15 (cpu) {
char * V_185 = ( char * ) F_200 ( V_187 , V_8 ) ;
V_51 = F_18 ( V_185 , V_185 + V_188 ,
V_14 ) ;
if ( V_51 ) {
F_188 ( L_7 ) ;
goto V_202;
}
}
F_15 (cpu) {
V_201 * V_211 ;
V_211 = F_16 ( V_65 , V_8 ) ;
V_51 = F_18 ( V_211 , V_211 + 1 , V_14 ) ;
if ( V_51 ) {
F_188 ( L_8 , V_51 ) ;
goto V_202;
}
}
F_190 ( L_9 ) ;
return 0 ;
V_202:
F_197 () ;
F_188 ( L_10 , V_51 ) ;
return V_51 ;
}
static void F_205 ( void * V_7 )
{
* ( int * ) V_7 = F_132 () ;
}
struct V_1 * F_206 ( struct V_6 * V_6 , unsigned long V_212 )
{
struct V_1 * V_2 ;
int V_23 ;
V_212 &= V_213 ;
F_89 (i, vcpu, kvm) {
if ( V_212 == F_207 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_208 ( void * V_214 )
{
int V_51 ;
int V_7 , V_8 ;
if ( ! F_209 () ) {
F_188 ( L_11 ) ;
return - V_176 ;
}
F_210 (cpu) {
F_211 ( V_8 , F_205 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_188 ( L_12 , V_8 ) ;
return - V_176 ;
}
}
V_51 = F_187 () ;
if ( V_51 )
return V_51 ;
if ( F_169 () )
V_51 = F_201 () ;
else
V_51 = F_202 () ;
if ( V_51 )
goto V_202;
V_51 = F_191 () ;
if ( V_51 )
goto V_215;
return 0 ;
V_215:
F_197 () ;
V_202:
F_186 () ;
return V_51 ;
}
void F_212 ( void )
{
F_213 () ;
}
static int F_214 ( void )
{
int V_216 = F_215 ( NULL , sizeof( struct V_1 ) , 0 , V_217 ) ;
return V_216 ;
}
