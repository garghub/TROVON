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
F_17 ( V_6 ) ;
V_6 -> V_11 . V_12 = 0 ;
V_6 -> V_11 . V_13 = V_14 ?
F_18 () : V_15 ;
return V_7 ;
V_10:
F_19 ( V_6 ) ;
V_9:
return V_7 ;
}
int F_20 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
return V_18 ;
}
void F_21 ( struct V_6 * V_6 )
{
int V_19 ;
F_19 ( V_6 ) ;
for ( V_19 = 0 ; V_19 < V_15 ; ++ V_19 ) {
if ( V_6 -> V_20 [ V_19 ] ) {
F_22 ( V_6 -> V_20 [ V_19 ] ) ;
V_6 -> V_20 [ V_19 ] = NULL ;
}
}
F_23 ( V_6 ) ;
}
int F_24 ( struct V_6 * V_6 , long V_21 )
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
V_22 = F_25 () ;
break;
case V_38 :
V_22 = V_15 ;
break;
default:
V_22 = F_26 ( V_21 ) ;
break;
}
return V_22 ;
}
long F_27 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
return - V_8 ;
}
struct V_1 * F_28 ( struct V_6 * V_6 , unsigned int V_43 )
{
int V_44 ;
struct V_1 * V_2 ;
if ( F_29 ( V_6 ) && F_30 ( V_6 ) ) {
V_44 = - V_45 ;
goto V_46;
}
if ( V_43 >= V_6 -> V_11 . V_13 ) {
V_44 = - V_8 ;
goto V_46;
}
V_2 = F_31 ( V_47 , V_48 ) ;
if ( ! V_2 ) {
V_44 = - V_49 ;
goto V_46;
}
V_44 = F_32 ( V_2 , V_6 , V_43 ) ;
if ( V_44 )
goto V_50;
V_44 = F_15 ( V_2 , V_2 + 1 ) ;
if ( V_44 )
goto V_51;
return V_2 ;
V_51:
F_33 ( V_2 ) ;
V_50:
F_34 ( V_47 , V_2 ) ;
V_46:
return F_35 ( V_44 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 ( V_2 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
F_34 ( V_47 , V_2 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
return F_44 ( V_2 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
F_46 ( V_2 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_52 = - 1 ;
F_50 ( V_2 -> V_11 . V_53 , V_54 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_2 , int V_55 )
{
V_2 -> V_55 = V_55 ;
V_2 -> V_11 . V_56 = F_54 ( V_57 ) ;
F_1 ( V_2 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
V_2 -> V_55 = - 1 ;
F_1 ( NULL ) ;
F_56 ( V_2 ) ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
if ( V_2 -> V_11 . V_60 )
V_59 -> V_59 = V_61 ;
else
V_59 -> V_59 = V_62 ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 ,
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
int F_59 ( struct V_1 * V_63 )
{
return ( ( ! ! V_63 -> V_11 . V_64 || F_60 ( V_63 ) )
&& ! V_63 -> V_11 . V_60 && ! V_63 -> V_11 . V_65 ) ;
}
static void F_61 ( void * V_66 )
{
}
void F_62 ( const T_2 * V_67 )
{
F_63 () ;
F_64 ( V_67 , F_61 , NULL , true ) ;
F_65 () ;
}
static bool F_66 ( struct V_6 * V_6 )
{
return F_67 ( V_6 -> V_11 . V_12 != F_68 ( & V_68 ) ) ;
}
static void F_69 ( struct V_6 * V_6 )
{
T_3 V_69 ;
T_4 V_70 ;
if ( ! F_66 ( V_6 ) )
return;
F_70 ( & V_71 ) ;
if ( ! F_66 ( V_6 ) ) {
F_71 ( & V_71 ) ;
return;
}
if ( F_67 ( V_72 == 0 ) ) {
F_72 ( & V_68 ) ;
V_72 = 1 ;
F_62 ( V_73 ) ;
F_73 ( V_74 ) ;
}
V_6 -> V_11 . V_12 = F_68 ( & V_68 ) ;
V_6 -> V_11 . V_70 = V_72 ;
V_72 ++ ;
V_72 &= ( 1 << V_75 ) - 1 ;
V_69 = F_74 ( F_75 ( V_6 ) ) ;
F_2 ( V_69 & ~ V_76 ) ;
V_70 = ( ( T_4 ) ( V_6 -> V_11 . V_70 ) << V_77 ) & F_76 ( V_75 ) ;
V_6 -> V_11 . V_78 = V_69 | V_70 ;
F_71 ( & V_71 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 ;
if ( F_78 ( V_2 -> V_11 . V_79 ) )
return 0 ;
V_2 -> V_11 . V_79 = true ;
if ( F_67 ( F_29 ( V_6 ) && ! F_79 ( V_6 ) ) ) {
V_7 = F_80 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
if ( F_29 ( V_6 ) && F_30 ( V_6 ) )
F_81 ( V_6 ) ;
return 0 ;
}
bool F_82 ( struct V_6 * V_6 )
{
return F_30 ( V_6 ) ;
}
static void F_83 ( struct V_6 * V_6 )
{
int V_19 ;
struct V_1 * V_2 ;
F_84 (i, vcpu, kvm)
V_2 -> V_11 . V_65 = true ;
F_62 ( V_73 ) ;
}
static void F_85 ( struct V_6 * V_6 )
{
int V_19 ;
struct V_1 * V_2 ;
F_84 (i, vcpu, kvm) {
struct V_80 * V_81 = F_86 ( V_2 ) ;
V_2 -> V_11 . V_65 = false ;
F_87 ( V_81 ) ;
}
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = F_86 ( V_2 ) ;
F_89 ( * V_81 , ( ( ! V_2 -> V_11 . V_60 ) &&
( ! V_2 -> V_11 . V_65 ) ) ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
return V_2 -> V_11 . V_52 >= 0 ;
}
int F_91 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
int V_7 ;
T_5 V_84 ;
if ( F_67 ( ! F_90 ( V_2 ) ) )
return - V_85 ;
V_7 = F_77 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_83 -> V_86 == V_87 ) {
V_7 = F_92 ( V_2 , V_2 -> V_83 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_2 -> V_88 )
F_93 ( V_89 , & V_2 -> V_90 , & V_84 ) ;
V_7 = 1 ;
V_83 -> V_86 = V_91 ;
while ( V_7 > 0 ) {
F_94 () ;
F_69 ( V_2 -> V_6 ) ;
if ( V_2 -> V_11 . V_60 || V_2 -> V_11 . V_65 )
F_88 ( V_2 ) ;
F_63 () ;
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
F_98 () ;
if ( F_99 ( V_92 ) ) {
V_7 = - V_93 ;
V_83 -> V_86 = V_94 ;
}
if ( V_7 <= 0 || F_66 ( V_2 -> V_6 ) ||
V_2 -> V_11 . V_60 || V_2 -> V_11 . V_65 ) {
F_100 () ;
F_101 ( V_2 ) ;
F_102 ( V_2 ) ;
F_103 ( V_2 ) ;
F_65 () ;
continue;
}
F_104 ( V_2 ) ;
F_105 ( * F_106 ( V_2 ) ) ;
F_107 () ;
V_2 -> V_95 = V_4 ;
V_7 = F_73 ( V_96 , V_2 ) ;
V_2 -> V_95 = V_97 ;
V_2 -> V_98 . V_99 ++ ;
F_108 ( V_2 ) ;
F_100 () ;
F_109 () ;
F_110 ( V_7 , F_111 ( V_2 ) , * F_106 ( V_2 ) ) ;
F_101 ( V_2 ) ;
F_102 ( V_2 ) ;
F_103 ( V_2 ) ;
F_65 () ;
V_7 = F_112 ( V_2 , V_83 , V_7 ) ;
}
if ( V_2 -> V_88 )
F_93 ( V_89 , & V_84 , NULL ) ;
return V_7 ;
}
static int F_113 ( struct V_1 * V_2 , int V_100 , bool V_101 )
{
int V_102 ;
bool V_103 ;
unsigned long * V_104 ;
if ( V_100 == V_105 )
V_102 = F_114 ( V_106 ) ;
else
V_102 = F_114 ( V_107 ) ;
V_104 = ( unsigned long * ) & V_2 -> V_11 . V_64 ;
if ( V_101 )
V_103 = F_115 ( V_102 , V_104 ) ;
else
V_103 = F_116 ( V_102 , V_104 ) ;
if ( V_103 == V_101 )
return 0 ;
F_117 ( V_2 ) ;
return 0 ;
}
int F_118 ( struct V_6 * V_6 , struct V_108 * V_109 ,
bool V_110 )
{
T_6 V_111 = V_109 -> V_111 ;
unsigned int V_112 , V_113 , V_114 ;
int V_115 = F_119 ( & V_6 -> V_116 ) ;
struct V_1 * V_2 = NULL ;
bool V_101 = V_109 -> V_101 ;
V_112 = ( V_111 >> V_117 ) & V_118 ;
V_113 = ( V_111 >> V_119 ) & V_120 ;
V_114 = ( V_111 >> V_121 ) & V_122 ;
F_120 ( V_112 , V_113 , V_114 , V_109 -> V_101 ) ;
switch ( V_112 ) {
case V_123 :
if ( F_29 ( V_6 ) )
return - V_124 ;
if ( V_113 >= V_115 )
return - V_8 ;
V_2 = F_121 ( V_6 , V_113 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_114 > V_125 )
return - V_8 ;
return F_113 ( V_2 , V_114 , V_101 ) ;
case V_126 :
if ( ! F_29 ( V_6 ) )
return - V_124 ;
if ( V_113 >= V_115 )
return - V_8 ;
V_2 = F_121 ( V_6 , V_113 ) ;
if ( ! V_2 )
return - V_8 ;
if ( V_114 < V_127 || V_114 >= V_128 )
return - V_8 ;
return F_122 ( V_6 , V_2 -> V_129 , V_114 , V_101 ) ;
case V_130 :
if ( ! F_29 ( V_6 ) )
return - V_124 ;
if ( V_114 < V_128 )
return - V_8 ;
return F_122 ( V_6 , 0 , V_114 , V_101 ) ;
}
return - V_8 ;
}
static int F_123 ( struct V_1 * V_2 ,
const struct F_32 * V_131 )
{
unsigned int V_19 ;
int V_132 = F_124 () ;
if ( V_131 -> V_52 != V_132 )
return - V_8 ;
if ( V_2 -> V_11 . V_52 != - 1 && V_2 -> V_11 . V_52 != V_131 -> V_52 )
return - V_8 ;
for ( V_19 = 0 ; V_19 < sizeof( V_131 -> V_53 ) * 8 ; V_19 ++ ) {
bool V_103 = ( V_131 -> V_53 [ V_19 / 32 ] & ( 1 << ( V_19 % 32 ) ) ) ;
if ( V_103 && V_19 >= V_54 )
return - V_133 ;
if ( V_2 -> V_11 . V_52 != - 1 && V_19 < V_54 &&
F_125 ( V_19 , V_2 -> V_11 . V_53 ) != V_103 )
return - V_8 ;
if ( V_103 )
F_126 ( V_19 , V_2 -> V_11 . V_53 ) ;
}
V_2 -> V_11 . V_52 = V_132 ;
return F_127 ( V_2 ) ;
}
static int F_128 ( struct V_1 * V_2 ,
struct F_32 * V_131 )
{
int V_7 ;
V_7 = F_123 ( V_2 , V_131 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_11 . V_79 )
F_129 ( V_2 -> V_6 ) ;
F_130 ( V_2 ) ;
if ( F_125 ( V_134 , V_2 -> V_11 . V_53 ) )
V_2 -> V_11 . V_60 = true ;
else
V_2 -> V_11 . V_60 = false ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
int V_7 = - V_124 ;
switch ( V_136 -> V_137 ) {
default:
V_7 = F_132 ( V_2 , V_136 ) ;
break;
}
return V_7 ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
int V_7 = - V_124 ;
switch ( V_136 -> V_137 ) {
default:
V_7 = F_134 ( V_2 , V_136 ) ;
break;
}
return V_7 ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
int V_7 = - V_124 ;
switch ( V_136 -> V_137 ) {
default:
V_7 = F_136 ( V_2 , V_136 ) ;
break;
}
return V_7 ;
}
long F_137 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_1 * V_2 = V_40 -> V_138 ;
void T_7 * V_139 = ( void T_7 * ) V_42 ;
struct V_135 V_136 ;
switch ( V_41 ) {
case V_140 : {
struct F_32 V_131 ;
if ( F_138 ( & V_131 , V_139 , sizeof( V_131 ) ) )
return - V_141 ;
return F_128 ( V_2 , & V_131 ) ;
}
case V_142 :
case V_143 : {
struct V_144 V_145 ;
if ( F_67 ( ! F_90 ( V_2 ) ) )
return - V_85 ;
if ( F_138 ( & V_145 , V_139 , sizeof( V_145 ) ) )
return - V_141 ;
if ( V_41 == V_142 )
return F_139 ( V_2 , & V_145 ) ;
else
return F_140 ( V_2 , & V_145 ) ;
}
case V_146 : {
struct V_147 T_7 * V_148 = V_139 ;
struct V_147 V_149 ;
unsigned V_150 ;
if ( F_67 ( ! F_90 ( V_2 ) ) )
return - V_85 ;
if ( F_138 ( & V_149 , V_148 , sizeof( V_149 ) ) )
return - V_141 ;
V_150 = V_149 . V_150 ;
V_149 . V_150 = F_141 ( V_2 ) ;
if ( F_142 ( V_148 , & V_149 , sizeof( V_149 ) ) )
return - V_141 ;
if ( V_150 < V_149 . V_150 )
return - V_151 ;
return F_143 ( V_2 , V_148 -> V_145 ) ;
}
case V_152 : {
if ( F_138 ( & V_136 , V_139 , sizeof( V_136 ) ) )
return - V_141 ;
return F_131 ( V_2 , & V_136 ) ;
}
case V_153 : {
if ( F_138 ( & V_136 , V_139 , sizeof( V_136 ) ) )
return - V_141 ;
return F_133 ( V_2 , & V_136 ) ;
}
case V_154 : {
if ( F_138 ( & V_136 , V_139 , sizeof( V_136 ) ) )
return - V_141 ;
return F_135 ( V_2 , & V_136 ) ;
}
default:
return - V_8 ;
}
}
int F_144 ( struct V_6 * V_6 , struct V_155 * log )
{
bool V_156 = false ;
int V_22 ;
F_145 ( & V_6 -> V_157 ) ;
V_22 = F_146 ( V_6 , log , & V_156 ) ;
if ( V_156 )
F_147 ( V_6 ) ;
F_148 ( & V_6 -> V_157 ) ;
return V_22 ;
}
static int F_149 ( struct V_6 * V_6 ,
struct V_158 * V_159 )
{
unsigned long V_160 , type ;
V_160 = ( V_159 -> V_43 & V_161 ) >>
V_162 ;
type = ( V_159 -> V_43 & V_163 ) >>
V_164 ;
switch ( V_160 ) {
case V_165 :
if ( ! V_14 )
return - V_124 ;
return F_150 ( V_6 , type , & V_159 -> V_166 , true ) ;
default:
return - V_167 ;
}
}
long F_151 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_6 * V_6 = V_40 -> V_138 ;
void T_7 * V_139 = ( void T_7 * ) V_42 ;
switch ( V_41 ) {
case V_168 : {
if ( ! V_14 )
return - V_124 ;
return F_152 ( V_6 , V_169 ) ;
}
case V_170 : {
struct V_158 V_159 ;
if ( F_138 ( & V_159 , V_139 , sizeof( V_159 ) ) )
return - V_141 ;
return F_149 ( V_6 , & V_159 ) ;
}
case V_171 : {
int V_44 ;
struct F_32 V_131 ;
V_44 = F_153 ( & V_131 ) ;
if ( V_44 )
return V_44 ;
if ( F_142 ( V_139 , & V_131 , sizeof( V_131 ) ) )
return - V_141 ;
return 0 ;
}
default:
return - V_8 ;
}
}
static void F_154 ( void * V_172 )
{
F_155 () ;
}
static void F_156 ( void * V_172 )
{
T_3 V_173 ;
T_3 V_174 ;
unsigned long V_175 ;
unsigned long V_176 ;
unsigned long V_177 ;
F_157 ( F_158 () ) ;
V_173 = F_159 () ;
V_174 = F_160 () ;
V_176 = F_6 ( V_178 ) ;
V_175 = V_176 + V_179 ;
V_177 = ( unsigned long ) F_161 ( V_180 ) ;
F_162 ( V_173 , V_174 , V_175 , V_177 ) ;
F_155 () ;
F_163 () ;
}
static void F_164 ( void )
{
if ( F_165 () ) {
F_154 ( NULL ) ;
} else {
if ( F_166 () == V_181 )
F_156 ( NULL ) ;
}
}
static int F_167 ( struct V_182 * V_183 ,
unsigned long V_184 , void * V_55 )
{
switch ( V_184 ) {
case V_185 :
case V_186 :
F_164 () ;
}
return V_187 ;
}
static int F_168 ( struct V_182 * V_183 ,
unsigned long V_188 ,
void * V_63 )
{
if ( V_188 == V_189 ) {
F_164 () ;
return V_187 ;
}
return V_190 ;
}
static void T_8 F_169 ( void )
{
F_170 ( & V_191 ) ;
}
static void T_8 F_171 ( void )
{
F_172 ( & V_191 ) ;
}
static inline void F_169 ( void )
{
}
static inline void F_171 ( void )
{
}
static void F_173 ( void )
{
F_174 ( V_57 ) ;
}
static int F_175 ( void )
{
V_57 = F_176 ( V_192 ) ;
if ( ! V_57 ) {
F_177 ( L_1 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_178 ( void )
{
int V_44 ;
V_44 = F_179 ( & V_193 ) ;
if ( V_44 ) {
F_177 ( L_2 , V_44 ) ;
return V_44 ;
}
F_169 () ;
V_44 = F_180 () ;
switch ( V_44 ) {
case 0 :
V_14 = true ;
break;
case - V_167 :
case - V_124 :
V_14 = false ;
break;
default:
return V_44 ;
}
V_44 = F_181 () ;
if ( V_44 )
return V_44 ;
F_182 () ;
F_183 () ;
return 0 ;
}
static void F_184 ( void )
{
int V_55 ;
if ( F_165 () )
return;
F_185 () ;
F_186 (cpu)
F_187 ( F_188 ( V_178 , V_55 ) ) ;
F_189 ( & V_193 ) ;
F_171 () ;
}
static int F_190 ( void )
{
F_191 ( F_154 , NULL , 1 ) ;
V_75 = F_192 () ;
F_193 ( L_3 , V_75 ) ;
F_193 ( L_4 ) ;
return 0 ;
}
static int F_194 ( void )
{
int V_55 ;
int V_44 = 0 ;
V_44 = F_195 () ;
if ( V_44 )
goto V_194;
V_181 = F_166 () ;
F_186 (cpu) {
unsigned long V_176 ;
V_176 = F_196 ( V_48 ) ;
if ( ! V_176 ) {
V_44 = - V_49 ;
goto V_194;
}
F_188 ( V_178 , V_55 ) = V_176 ;
}
V_44 = F_15 ( F_161 ( V_195 ) ,
F_161 ( V_196 ) ) ;
if ( V_44 ) {
F_177 ( L_5 ) ;
goto V_194;
}
V_44 = F_15 ( F_161 ( V_197 ) ,
F_161 ( V_198 ) ) ;
if ( V_44 ) {
F_177 ( L_6 ) ;
goto V_194;
}
F_186 (cpu) {
char * V_176 = ( char * ) F_188 ( V_178 , V_55 ) ;
V_44 = F_15 ( V_176 , V_176 + V_179 ) ;
if ( V_44 ) {
F_177 ( L_7 ) ;
goto V_194;
}
}
F_186 (cpu) {
V_192 * V_199 ;
V_199 = F_197 ( V_57 , V_55 ) ;
V_44 = F_15 ( V_199 , V_199 + 1 ) ;
if ( V_44 ) {
F_177 ( L_8 , V_44 ) ;
goto V_194;
}
}
F_191 ( F_156 , NULL , 1 ) ;
#ifndef F_198
F_199 () ;
#endif
V_75 = F_192 () ;
F_193 ( L_3 , V_75 ) ;
F_193 ( L_9 ) ;
return 0 ;
V_194:
F_184 () ;
F_177 ( L_10 , V_44 ) ;
return V_44 ;
}
static void F_200 ( void * V_7 )
{
* ( int * ) V_7 = F_124 () ;
}
struct V_1 * F_201 ( struct V_6 * V_6 , unsigned long V_200 )
{
struct V_1 * V_2 ;
int V_19 ;
V_200 &= V_201 ;
F_84 (i, vcpu, kvm) {
if ( V_200 == F_202 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_203 ( void * V_202 )
{
int V_44 ;
int V_7 , V_55 ;
if ( ! F_204 () ) {
F_177 ( L_11 ) ;
return - V_167 ;
}
F_205 (cpu) {
F_206 ( V_55 , F_200 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_177 ( L_12 , V_55 ) ;
return - V_167 ;
}
}
V_44 = F_175 () ;
if ( V_44 )
return V_44 ;
if ( F_165 () )
V_44 = F_190 () ;
else
V_44 = F_194 () ;
if ( V_44 )
goto V_194;
V_44 = F_178 () ;
if ( V_44 )
goto V_203;
return 0 ;
V_203:
F_184 () ;
V_194:
F_173 () ;
return V_44 ;
}
void F_207 ( void )
{
F_208 () ;
}
static int F_209 ( void )
{
int V_204 = F_210 ( NULL , sizeof( struct V_1 ) , 0 , V_205 ) ;
return V_204 ;
}
