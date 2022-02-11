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
V_7 = F_14 ( V_6 , V_6 + 1 ) ;
if ( V_7 )
goto V_10;
F_15 ( V_6 ) ;
F_16 ( V_6 ) ;
V_6 -> V_11 . V_12 = 0 ;
V_6 -> V_11 . V_13 = V_14 ?
F_17 () : V_15 ;
return V_7 ;
V_10:
F_18 ( V_6 ) ;
V_9:
return V_7 ;
}
int F_19 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
return V_18 ;
}
void F_20 ( struct V_6 * V_6 )
{
int V_19 ;
F_18 ( V_6 ) ;
for ( V_19 = 0 ; V_19 < V_15 ; ++ V_19 ) {
if ( V_6 -> V_20 [ V_19 ] ) {
F_21 ( V_6 -> V_20 [ V_19 ] ) ;
V_6 -> V_20 [ V_19 ] = NULL ;
}
}
F_22 ( V_6 ) ;
}
int F_23 ( struct V_6 * V_6 , long V_21 )
{
int V_22 ;
switch ( V_21 ) {
case V_23 :
V_22 = V_14 ;
break;
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
V_22 = 1 ;
break;
case V_34 :
V_22 = V_35 ;
break;
case V_36 :
V_22 = 1 ;
break;
case V_37 :
V_22 = F_24 () ;
break;
case V_38 :
V_22 = V_15 ;
break;
default:
V_22 = F_25 ( V_21 ) ;
break;
}
return V_22 ;
}
long F_26 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
return - V_8 ;
}
struct V_1 * F_27 ( struct V_6 * V_6 , unsigned int V_43 )
{
int V_44 ;
struct V_1 * V_2 ;
if ( F_28 ( V_6 ) && F_29 ( V_6 ) ) {
V_44 = - V_45 ;
goto V_46;
}
if ( V_43 >= V_6 -> V_11 . V_13 ) {
V_44 = - V_8 ;
goto V_46;
}
V_2 = F_30 ( V_47 , V_48 ) ;
if ( ! V_2 ) {
V_44 = - V_49 ;
goto V_46;
}
V_44 = F_31 ( V_2 , V_6 , V_43 ) ;
if ( V_44 )
goto V_50;
V_44 = F_14 ( V_2 , V_2 + 1 ) ;
if ( V_44 )
goto V_51;
return V_2 ;
V_51:
F_32 ( V_2 ) ;
V_50:
F_33 ( V_47 , V_2 ) ;
V_46:
return F_34 ( V_44 ) ;
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
F_33 ( V_47 , V_2 ) ;
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
V_2 -> V_11 . V_52 = - 1 ;
F_49 ( V_2 -> V_11 . V_53 , V_54 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 , int V_55 )
{
V_2 -> V_55 = V_55 ;
V_2 -> V_11 . V_56 = F_53 ( V_57 ) ;
F_1 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
V_2 -> V_55 = - 1 ;
F_1 ( NULL ) ;
F_55 ( V_2 ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
if ( V_2 -> V_11 . V_60 )
V_59 -> V_59 = V_61 ;
else
V_59 -> V_59 = V_62 ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
switch ( V_59 -> V_59 ) {
case V_62 :
V_2 -> V_11 . V_60 = false ;
break;
case V_61 :
V_2 -> V_11 . V_60 = true ;
break;
default:
return - V_8 ;
}
return 0 ;
}
int F_58 ( struct V_1 * V_63 )
{
return ( ( ! ! V_63 -> V_11 . V_64 || F_59 ( V_63 ) )
&& ! V_63 -> V_11 . V_60 && ! V_63 -> V_11 . V_65 ) ;
}
static void F_60 ( void * V_66 )
{
}
void F_61 ( const T_2 * V_67 )
{
F_62 () ;
F_63 ( V_67 , F_60 , NULL , true ) ;
F_64 () ;
}
static bool F_65 ( struct V_6 * V_6 )
{
return F_66 ( V_6 -> V_11 . V_12 != F_67 ( & V_68 ) ) ;
}
static void F_68 ( struct V_6 * V_6 )
{
T_3 V_69 ;
T_4 V_70 ;
if ( ! F_65 ( V_6 ) )
return;
F_69 ( & V_71 ) ;
if ( ! F_65 ( V_6 ) ) {
F_70 ( & V_71 ) ;
return;
}
if ( F_66 ( V_72 == 0 ) ) {
F_71 ( & V_68 ) ;
V_72 = 1 ;
F_61 ( V_73 ) ;
F_72 ( V_74 ) ;
}
V_6 -> V_11 . V_12 = F_67 ( & V_68 ) ;
V_6 -> V_11 . V_70 = V_72 ;
V_72 ++ ;
V_72 &= ( 1 << V_75 ) - 1 ;
V_69 = F_73 ( V_6 -> V_11 . V_76 ) ;
F_2 ( V_69 & ~ V_77 ) ;
V_70 = ( ( T_4 ) ( V_6 -> V_11 . V_70 ) << V_78 ) & F_74 ( V_75 ) ;
V_6 -> V_11 . V_79 = V_69 | V_70 ;
F_70 ( & V_71 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
if ( F_76 ( V_2 -> V_11 . V_80 ) )
return 0 ;
V_2 -> V_11 . V_80 = true ;
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
int V_19 ;
struct V_1 * V_2 ;
F_82 (i, vcpu, kvm)
V_2 -> V_11 . V_65 = true ;
F_83 ( V_6 , V_81 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_65 = true ;
F_85 ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_87 ( V_2 ) ;
V_2 -> V_11 . V_65 = false ;
F_88 ( V_83 ) ;
}
void F_89 ( struct V_6 * V_6 )
{
int V_19 ;
struct V_1 * V_2 ;
F_82 (i, vcpu, kvm)
F_86 ( V_2 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_87 ( V_2 ) ;
F_91 ( * V_83 , ( ( ! V_2 -> V_11 . V_60 ) &&
( ! V_2 -> V_11 . V_65 ) ) ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
return V_2 -> V_11 . V_52 >= 0 ;
}
int F_93 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
int V_7 ;
T_5 V_86 ;
if ( F_66 ( ! F_92 ( V_2 ) ) )
return - V_87 ;
V_7 = F_75 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_85 -> V_88 == V_89 ) {
V_7 = F_94 ( V_2 , V_2 -> V_85 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_90 )
F_95 ( V_91 , & V_2 -> V_92 , & V_86 ) ;
V_7 = 1 ;
V_85 -> V_88 = V_93 ;
while ( V_7 > 0 ) {
F_96 () ;
F_68 ( V_2 -> V_6 ) ;
if ( V_2 -> V_11 . V_60 || V_2 -> V_11 . V_65 )
F_90 ( V_2 ) ;
F_62 () ;
F_97 ( V_2 ) ;
F_98 ( V_2 ) ;
F_99 ( V_2 ) ;
F_100 () ;
if ( F_101 ( V_94 ) ) {
V_7 = - V_95 ;
V_85 -> V_88 = V_96 ;
}
if ( V_7 <= 0 || F_65 ( V_2 -> V_6 ) ||
V_2 -> V_11 . V_60 || V_2 -> V_11 . V_65 ) {
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
V_2 -> V_97 = V_4 ;
V_7 = F_72 ( V_98 , V_2 ) ;
V_2 -> V_97 = V_99 ;
V_2 -> V_100 . V_101 ++ ;
F_110 ( V_2 ) ;
F_102 () ;
F_111 () ;
F_112 ( V_7 , F_113 ( V_2 ) , * F_108 ( V_2 ) ) ;
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
F_64 () ;
V_7 = F_114 ( V_2 , V_85 , V_7 ) ;
}
if ( V_2 -> V_90 )
F_95 ( V_91 , & V_86 , NULL ) ;
return V_7 ;
}
static int F_115 ( struct V_1 * V_2 , int V_102 , bool V_103 )
{
int V_104 ;
bool V_105 ;
unsigned long * V_106 ;
if ( V_102 == V_107 )
V_104 = F_116 ( V_108 ) ;
else
V_104 = F_116 ( V_109 ) ;
V_106 = ( unsigned long * ) & V_2 -> V_11 . V_64 ;
if ( V_103 )
V_105 = F_117 ( V_104 , V_106 ) ;
else
V_105 = F_118 ( V_104 , V_106 ) ;
if ( V_105 == V_103 )
return 0 ;
F_85 ( V_2 ) ;
return 0 ;
}
int F_119 ( struct V_6 * V_6 , struct V_110 * V_111 ,
bool V_112 )
{
T_6 V_113 = V_111 -> V_113 ;
unsigned int V_114 , V_115 , V_116 ;
int V_117 = F_120 ( & V_6 -> V_118 ) ;
struct V_1 * V_2 = NULL ;
bool V_103 = V_111 -> V_103 ;
V_114 = ( V_113 >> V_119 ) & V_120 ;
V_115 = ( V_113 >> V_121 ) & V_122 ;
V_116 = ( V_113 >> V_123 ) & V_124 ;
F_121 ( V_114 , V_115 , V_116 , V_111 -> V_103 ) ;
switch ( V_114 ) {
case V_125 :
if ( F_28 ( V_6 ) )
return - V_126 ;
if ( V_115 >= V_117 )
return - V_8 ;
V_2 = F_122 ( V_6 , V_115 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_116 > V_127 )
return - V_8 ;
return F_115 ( V_2 , V_116 , V_103 ) ;
case V_128 :
if ( ! F_28 ( V_6 ) )
return - V_126 ;
if ( V_115 >= V_117 )
return - V_8 ;
V_2 = F_122 ( V_6 , V_115 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_116 < V_129 || V_116 >= V_130 )
return - V_8 ;
return F_123 ( V_6 , V_2 -> V_131 , V_116 , V_103 ) ;
case V_132 :
if ( ! F_28 ( V_6 ) )
return - V_126 ;
if ( V_116 < V_130 )
return - V_8 ;
return F_123 ( V_6 , 0 , V_116 , V_103 ) ;
}
return - V_8 ;
}
static int F_124 ( struct V_1 * V_2 ,
const struct F_31 * V_133 )
{
unsigned int V_19 ;
int V_134 = F_125 () ;
if ( V_133 -> V_52 != V_134 )
return - V_8 ;
if ( V_2 -> V_11 . V_52 != - 1 && V_2 -> V_11 . V_52 != V_133 -> V_52 )
return - V_8 ;
for ( V_19 = 0 ; V_19 < sizeof( V_133 -> V_53 ) * 8 ; V_19 ++ ) {
bool V_105 = ( V_133 -> V_53 [ V_19 / 32 ] & ( 1 << ( V_19 % 32 ) ) ) ;
if ( V_105 && V_19 >= V_54 )
return - V_135 ;
if ( V_2 -> V_11 . V_52 != - 1 && V_19 < V_54 &&
F_126 ( V_19 , V_2 -> V_11 . V_53 ) != V_105 )
return - V_8 ;
if ( V_105 )
F_127 ( V_19 , V_2 -> V_11 . V_53 ) ;
}
V_2 -> V_11 . V_52 = V_134 ;
return F_128 ( V_2 ) ;
}
static int F_129 ( struct V_1 * V_2 ,
struct F_31 * V_133 )
{
int V_7 ;
V_7 = F_124 ( V_2 , V_133 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_11 . V_80 )
F_130 ( V_2 -> V_6 ) ;
F_131 ( V_2 ) ;
if ( F_126 ( V_136 , V_2 -> V_11 . V_53 ) )
V_2 -> V_11 . V_60 = true ;
else
V_2 -> V_11 . V_60 = false ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
int V_7 = - V_126 ;
switch ( V_138 -> V_139 ) {
default:
V_7 = F_133 ( V_2 , V_138 ) ;
break;
}
return V_7 ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
int V_7 = - V_126 ;
switch ( V_138 -> V_139 ) {
default:
V_7 = F_135 ( V_2 , V_138 ) ;
break;
}
return V_7 ;
}
static int F_136 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
int V_7 = - V_126 ;
switch ( V_138 -> V_139 ) {
default:
V_7 = F_137 ( V_2 , V_138 ) ;
break;
}
return V_7 ;
}
long F_138 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_1 * V_2 = V_40 -> V_140 ;
void T_7 * V_141 = ( void T_7 * ) V_42 ;
struct V_137 V_138 ;
switch ( V_41 ) {
case V_142 : {
struct F_31 V_133 ;
if ( F_139 ( & V_133 , V_141 , sizeof( V_133 ) ) )
return - V_143 ;
return F_129 ( V_2 , & V_133 ) ;
}
case V_144 :
case V_145 : {
struct V_146 V_147 ;
if ( F_66 ( ! F_92 ( V_2 ) ) )
return - V_87 ;
if ( F_139 ( & V_147 , V_141 , sizeof( V_147 ) ) )
return - V_143 ;
if ( V_41 == V_144 )
return F_140 ( V_2 , & V_147 ) ;
else
return F_141 ( V_2 , & V_147 ) ;
}
case V_148 : {
struct V_149 T_7 * V_150 = V_141 ;
struct V_149 V_151 ;
unsigned V_152 ;
if ( F_66 ( ! F_92 ( V_2 ) ) )
return - V_87 ;
if ( F_139 ( & V_151 , V_150 , sizeof( V_151 ) ) )
return - V_143 ;
V_152 = V_151 . V_152 ;
V_151 . V_152 = F_142 ( V_2 ) ;
if ( F_143 ( V_150 , & V_151 , sizeof( V_151 ) ) )
return - V_143 ;
if ( V_152 < V_151 . V_152 )
return - V_153 ;
return F_144 ( V_2 , V_150 -> V_147 ) ;
}
case V_154 : {
if ( F_139 ( & V_138 , V_141 , sizeof( V_138 ) ) )
return - V_143 ;
return F_132 ( V_2 , & V_138 ) ;
}
case V_155 : {
if ( F_139 ( & V_138 , V_141 , sizeof( V_138 ) ) )
return - V_143 ;
return F_134 ( V_2 , & V_138 ) ;
}
case V_156 : {
if ( F_139 ( & V_138 , V_141 , sizeof( V_138 ) ) )
return - V_143 ;
return F_136 ( V_2 , & V_138 ) ;
}
default:
return - V_8 ;
}
}
int F_145 ( struct V_6 * V_6 , struct V_157 * log )
{
bool V_158 = false ;
int V_22 ;
F_146 ( & V_6 -> V_159 ) ;
V_22 = F_147 ( V_6 , log , & V_158 ) ;
if ( V_158 )
F_148 ( V_6 ) ;
F_149 ( & V_6 -> V_159 ) ;
return V_22 ;
}
static int F_150 ( struct V_6 * V_6 ,
struct V_160 * V_161 )
{
unsigned long V_162 , type ;
V_162 = ( V_161 -> V_43 & V_163 ) >>
V_164 ;
type = ( V_161 -> V_43 & V_165 ) >>
V_166 ;
switch ( V_162 ) {
case V_167 :
if ( ! V_14 )
return - V_126 ;
return F_151 ( V_6 , type , & V_161 -> V_168 , true ) ;
default:
return - V_169 ;
}
}
long F_152 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_6 * V_6 = V_40 -> V_140 ;
void T_7 * V_141 = ( void T_7 * ) V_42 ;
switch ( V_41 ) {
case V_170 : {
if ( ! V_14 )
return - V_126 ;
return F_153 ( V_6 , V_171 ) ;
}
case V_172 : {
struct V_160 V_161 ;
if ( F_139 ( & V_161 , V_141 , sizeof( V_161 ) ) )
return - V_143 ;
return F_150 ( V_6 , & V_161 ) ;
}
case V_173 : {
int V_44 ;
struct F_31 V_133 ;
V_44 = F_154 ( & V_133 ) ;
if ( V_44 )
return V_44 ;
if ( F_143 ( V_141 , & V_133 , sizeof( V_133 ) ) )
return - V_143 ;
return 0 ;
}
default:
return - V_8 ;
}
}
static void F_155 ( void * V_174 )
{
T_3 V_175 ;
T_3 V_176 ;
unsigned long V_177 ;
unsigned long V_178 ;
unsigned long V_179 ;
F_156 ( F_157 () ) ;
V_175 = F_158 () ;
V_176 = F_159 () ;
V_178 = F_6 ( V_180 ) ;
V_177 = V_178 + V_181 ;
V_179 = ( unsigned long ) F_160 ( V_182 ) ;
F_161 ( V_175 , V_176 , V_177 , V_179 ) ;
F_162 () ;
F_163 () ;
}
static void F_164 ( void )
{
if ( F_165 () ) {
F_162 () ;
} else {
if ( F_166 () == V_183 )
F_155 ( NULL ) ;
}
}
static void F_167 ( void )
{
T_3 V_175 ;
T_3 V_184 ;
if ( ! F_165 () ) {
V_175 = F_158 () ;
V_184 = F_168 () ;
F_169 ( V_175 , V_184 ) ;
}
}
static void F_170 ( void * V_185 )
{
if ( ! F_6 ( V_186 ) ) {
F_164 () ;
F_4 ( V_186 , 1 ) ;
}
}
int F_171 ( void )
{
F_170 ( NULL ) ;
return 0 ;
}
static void F_172 ( void * V_185 )
{
if ( F_6 ( V_186 ) ) {
F_167 () ;
F_4 ( V_186 , 0 ) ;
}
}
void F_173 ( void )
{
F_172 ( NULL ) ;
}
static int F_174 ( struct V_187 * V_188 ,
unsigned long V_189 ,
void * V_63 )
{
switch ( V_189 ) {
case V_190 :
if ( F_6 ( V_186 ) )
F_167 () ;
return V_191 ;
case V_192 :
if ( F_6 ( V_186 ) )
F_164 () ;
return V_191 ;
default:
return V_193 ;
}
}
static void T_8 F_175 ( void )
{
F_176 ( & V_194 ) ;
}
static void T_8 F_177 ( void )
{
F_178 ( & V_194 ) ;
}
static inline void F_175 ( void )
{
}
static inline void F_177 ( void )
{
}
static void F_179 ( void )
{
F_180 ( V_57 ) ;
}
static int F_181 ( void )
{
V_57 = F_182 ( V_195 ) ;
if ( ! V_57 ) {
F_183 ( L_1 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_184 ( void )
{
int V_44 = 0 ;
F_185 ( F_170 , NULL , 1 ) ;
F_175 () ;
V_44 = F_186 () ;
switch ( V_44 ) {
case 0 :
V_14 = true ;
break;
case - V_169 :
case - V_126 :
V_14 = false ;
V_44 = 0 ;
break;
default:
goto V_46;
}
V_44 = F_187 () ;
if ( V_44 )
goto V_46;
F_188 () ;
F_189 () ;
V_46:
F_185 ( F_172 , NULL , 1 ) ;
return V_44 ;
}
static void F_190 ( void )
{
int V_55 ;
if ( F_165 () )
return;
F_191 () ;
F_192 (cpu)
F_193 ( F_194 ( V_180 , V_55 ) ) ;
F_177 () ;
}
static int F_195 ( void )
{
V_75 = F_196 () ;
F_197 ( L_2 , V_75 ) ;
F_197 ( L_3 ) ;
return 0 ;
}
static int F_198 ( void )
{
int V_55 ;
int V_44 = 0 ;
V_44 = F_199 () ;
if ( V_44 )
goto V_196;
V_183 = F_166 () ;
F_192 (cpu) {
unsigned long V_178 ;
V_178 = F_200 ( V_48 ) ;
if ( ! V_178 ) {
V_44 = - V_49 ;
goto V_196;
}
F_194 ( V_180 , V_55 ) = V_178 ;
}
V_44 = F_14 ( F_160 ( V_197 ) ,
F_160 ( V_198 ) ) ;
if ( V_44 ) {
F_183 ( L_4 ) ;
goto V_196;
}
V_44 = F_14 ( F_160 ( V_199 ) ,
F_160 ( V_200 ) ) ;
if ( V_44 ) {
F_183 ( L_5 ) ;
goto V_196;
}
F_192 (cpu) {
char * V_178 = ( char * ) F_194 ( V_180 , V_55 ) ;
V_44 = F_14 ( V_178 , V_178 + V_181 ) ;
if ( V_44 ) {
F_183 ( L_6 ) ;
goto V_196;
}
}
F_192 (cpu) {
V_195 * V_201 ;
V_201 = F_201 ( V_57 , V_55 ) ;
V_44 = F_14 ( V_201 , V_201 + 1 ) ;
if ( V_44 ) {
F_183 ( L_7 , V_44 ) ;
goto V_196;
}
}
#ifndef F_202
F_203 () ;
#endif
V_75 = F_196 () ;
F_197 ( L_2 , V_75 ) ;
F_197 ( L_8 ) ;
return 0 ;
V_196:
F_190 () ;
F_183 ( L_9 , V_44 ) ;
return V_44 ;
}
static void F_204 ( void * V_7 )
{
* ( int * ) V_7 = F_125 () ;
}
struct V_1 * F_205 ( struct V_6 * V_6 , unsigned long V_202 )
{
struct V_1 * V_2 ;
int V_19 ;
V_202 &= V_203 ;
F_82 (i, vcpu, kvm) {
if ( V_202 == F_206 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_207 ( void * V_204 )
{
int V_44 ;
int V_7 , V_55 ;
if ( ! F_208 () ) {
F_183 ( L_10 ) ;
return - V_169 ;
}
F_209 (cpu) {
F_210 ( V_55 , F_204 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_183 ( L_11 , V_55 ) ;
return - V_169 ;
}
}
V_44 = F_181 () ;
if ( V_44 )
return V_44 ;
if ( F_165 () )
V_44 = F_195 () ;
else
V_44 = F_198 () ;
if ( V_44 )
goto V_196;
V_44 = F_184 () ;
if ( V_44 )
goto V_205;
return 0 ;
V_205:
F_190 () ;
V_196:
F_179 () ;
return V_44 ;
}
void F_211 ( void )
{
F_212 () ;
}
static int F_213 ( void )
{
int V_206 = F_214 ( NULL , sizeof( struct V_1 ) , 0 , V_207 ) ;
return V_206 ;
}
