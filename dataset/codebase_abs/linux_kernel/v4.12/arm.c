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
int F_68 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
if ( V_2 -> V_10 . V_70 )
V_69 -> V_69 = V_71 ;
else
V_69 -> V_69 = V_72 ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
switch ( V_69 -> V_69 ) {
case V_72 :
V_2 -> V_10 . V_70 = false ;
break;
case V_71 :
V_2 -> V_10 . V_70 = true ;
break;
default:
return - V_9 ;
}
return 0 ;
}
int F_70 ( struct V_1 * V_73 )
{
return ( ( ! ! V_73 -> V_10 . V_74 || F_71 ( V_73 ) )
&& ! V_73 -> V_10 . V_70 && ! V_73 -> V_10 . V_75 ) ;
}
static void F_72 ( void * V_76 )
{
}
void F_73 ( const T_2 * V_77 )
{
F_74 () ;
F_75 ( V_77 , F_72 , NULL , true ) ;
F_76 () ;
}
static bool F_77 ( struct V_6 * V_6 )
{
return F_78 ( V_6 -> V_10 . V_16 != F_79 ( & V_78 ) ) ;
}
static void F_80 ( struct V_6 * V_6 )
{
T_3 V_79 ;
T_4 V_80 ;
if ( ! F_77 ( V_6 ) )
return;
F_81 ( & V_81 ) ;
if ( ! F_77 ( V_6 ) ) {
F_82 ( & V_81 ) ;
return;
}
if ( F_78 ( V_82 == 0 ) ) {
F_83 ( & V_78 ) ;
V_82 = 1 ;
F_73 ( V_83 ) ;
F_63 ( V_84 ) ;
}
V_6 -> V_10 . V_16 = F_79 ( & V_78 ) ;
V_6 -> V_10 . V_80 = V_82 ;
V_82 ++ ;
V_82 &= ( 1 << V_85 ) - 1 ;
V_79 = F_84 ( V_6 -> V_10 . V_86 ) ;
F_2 ( V_79 & ~ V_87 ) ;
V_80 = ( ( T_4 ) ( V_6 -> V_10 . V_80 ) << V_88 ) & F_85 ( V_85 ) ;
V_6 -> V_10 . V_89 = V_79 | V_80 ;
F_82 ( & V_81 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
if ( F_87 ( V_2 -> V_10 . V_90 ) )
return 0 ;
V_2 -> V_10 . V_90 = true ;
if ( F_78 ( F_34 ( V_6 ) && ! F_88 ( V_6 ) ) ) {
V_7 = F_89 ( V_6 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_90 ( V_2 ) ;
return V_7 ;
}
bool F_91 ( struct V_6 * V_6 )
{
return F_35 ( V_6 ) ;
}
void F_92 ( struct V_6 * V_6 )
{
int V_23 ;
struct V_1 * V_2 ;
F_93 (i, vcpu, kvm)
V_2 -> V_10 . V_75 = true ;
F_94 ( V_6 , V_91 ) ;
}
void F_95 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_75 = true ;
F_96 ( V_2 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_92 * V_93 = F_98 ( V_2 ) ;
V_2 -> V_10 . V_75 = false ;
F_99 ( V_93 ) ;
}
void F_100 ( struct V_6 * V_6 )
{
int V_23 ;
struct V_1 * V_2 ;
F_93 (i, vcpu, kvm)
F_97 ( V_2 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_92 * V_93 = F_98 ( V_2 ) ;
F_102 ( * V_93 , ( ( ! V_2 -> V_10 . V_70 ) &&
( ! V_2 -> V_10 . V_75 ) ) ) ;
}
static int F_103 ( struct V_1 * V_2 )
{
return V_2 -> V_10 . V_60 >= 0 ;
}
int F_104 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
int V_7 ;
T_5 V_96 ;
if ( F_78 ( ! F_103 ( V_2 ) ) )
return - V_97 ;
V_7 = F_86 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_95 -> V_98 == V_99 ) {
V_7 = F_105 ( V_2 , V_2 -> V_95 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_95 -> V_100 )
return - V_101 ;
if ( V_2 -> V_102 )
F_106 ( V_103 , & V_2 -> V_104 , & V_96 ) ;
V_7 = 1 ;
V_95 -> V_98 = V_105 ;
while ( V_7 > 0 ) {
F_107 () ;
F_80 ( V_2 -> V_6 ) ;
if ( V_2 -> V_10 . V_70 || V_2 -> V_10 . V_75 )
F_101 ( V_2 ) ;
F_74 () ;
F_108 ( V_2 ) ;
F_109 ( V_2 ) ;
F_110 ( V_2 ) ;
F_111 () ;
if ( F_112 ( V_106 ) ||
F_113 ( V_2 ) ||
F_114 ( V_2 ) ) {
V_7 = - V_101 ;
V_95 -> V_98 = V_107 ;
}
if ( V_7 <= 0 || F_77 ( V_2 -> V_6 ) ||
V_2 -> V_10 . V_70 || V_2 -> V_10 . V_75 ) {
F_115 () ;
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_76 () ;
continue;
}
F_119 ( V_2 ) ;
F_120 ( * F_121 ( V_2 ) ) ;
F_122 () ;
V_2 -> V_108 = V_4 ;
V_7 = F_63 ( V_109 , V_2 ) ;
V_2 -> V_108 = V_110 ;
V_2 -> V_111 . V_112 ++ ;
F_123 ( V_2 ) ;
F_115 () ;
F_124 () ;
F_125 ( V_7 , F_126 ( V_2 ) , * F_121 ( V_2 ) ) ;
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_76 () ;
V_7 = F_127 ( V_2 , V_95 , V_7 ) ;
}
if ( F_78 ( ! F_34 ( V_2 -> V_6 ) ) ) {
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
}
if ( V_2 -> V_102 )
F_106 ( V_103 , & V_96 , NULL ) ;
return V_7 ;
}
static int F_130 ( struct V_1 * V_2 , int V_113 , bool V_114 )
{
int V_115 ;
bool V_116 ;
unsigned long * V_117 ;
if ( V_113 == V_118 )
V_115 = F_131 ( V_119 ) ;
else
V_115 = F_131 ( V_120 ) ;
V_117 = ( unsigned long * ) & V_2 -> V_10 . V_74 ;
if ( V_114 )
V_116 = F_132 ( V_115 , V_117 ) ;
else
V_116 = F_133 ( V_115 , V_117 ) ;
if ( V_116 == V_114 )
return 0 ;
F_96 ( V_2 ) ;
return 0 ;
}
int F_134 ( struct V_6 * V_6 , struct V_121 * V_122 ,
bool V_123 )
{
T_6 V_124 = V_122 -> V_124 ;
unsigned int V_125 , V_126 , V_127 ;
int V_128 = F_135 ( & V_6 -> V_129 ) ;
struct V_1 * V_2 = NULL ;
bool V_114 = V_122 -> V_114 ;
V_125 = ( V_124 >> V_130 ) & V_131 ;
V_126 = ( V_124 >> V_132 ) & V_133 ;
V_127 = ( V_124 >> V_134 ) & V_135 ;
F_136 ( V_125 , V_126 , V_127 , V_122 -> V_114 ) ;
switch ( V_125 ) {
case V_136 :
if ( F_34 ( V_6 ) )
return - V_137 ;
if ( V_126 >= V_128 )
return - V_9 ;
V_2 = F_137 ( V_6 , V_126 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_127 > V_138 )
return - V_9 ;
return F_130 ( V_2 , V_127 , V_114 ) ;
case V_139 :
if ( ! F_34 ( V_6 ) )
return - V_137 ;
if ( V_126 >= V_128 )
return - V_9 ;
V_2 = F_137 ( V_6 , V_126 ) ;
if ( ! V_2 )
return - V_9 ;
if ( V_127 < V_140 || V_127 >= V_141 )
return - V_9 ;
return F_138 ( V_6 , V_2 -> V_64 , V_127 , V_114 ) ;
case V_142 :
if ( ! F_34 ( V_6 ) )
return - V_137 ;
if ( V_127 < V_141 )
return - V_9 ;
return F_138 ( V_6 , 0 , V_127 , V_114 ) ;
}
return - V_9 ;
}
static int F_139 ( struct V_1 * V_2 ,
const struct F_37 * V_143 )
{
unsigned int V_23 ;
int V_144 = F_140 () ;
if ( V_143 -> V_60 != V_144 )
return - V_9 ;
if ( V_2 -> V_10 . V_60 != - 1 && V_2 -> V_10 . V_60 != V_143 -> V_60 )
return - V_9 ;
for ( V_23 = 0 ; V_23 < sizeof( V_143 -> V_61 ) * 8 ; V_23 ++ ) {
bool V_116 = ( V_143 -> V_61 [ V_23 / 32 ] & ( 1 << ( V_23 % 32 ) ) ) ;
if ( V_116 && V_23 >= V_62 )
return - V_145 ;
if ( V_2 -> V_10 . V_60 != - 1 && V_23 < V_62 &&
F_141 ( V_23 , V_2 -> V_10 . V_61 ) != V_116 )
return - V_9 ;
if ( V_116 )
F_142 ( V_23 , V_2 -> V_10 . V_61 ) ;
}
V_2 -> V_10 . V_60 = V_144 ;
return F_143 ( V_2 ) ;
}
static int F_144 ( struct V_1 * V_2 ,
struct F_37 * V_143 )
{
int V_7 ;
V_7 = F_139 ( V_2 , V_143 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_10 . V_90 )
F_145 ( V_2 -> V_6 ) ;
F_146 ( V_2 ) ;
if ( F_141 ( V_146 , V_2 -> V_10 . V_61 ) )
V_2 -> V_10 . V_70 = true ;
else
V_2 -> V_10 . V_70 = false ;
return 0 ;
}
static int F_147 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
int V_7 = - V_137 ;
switch ( V_148 -> V_149 ) {
default:
V_7 = F_148 ( V_2 , V_148 ) ;
break;
}
return V_7 ;
}
static int F_149 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
int V_7 = - V_137 ;
switch ( V_148 -> V_149 ) {
default:
V_7 = F_150 ( V_2 , V_148 ) ;
break;
}
return V_7 ;
}
static int F_151 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
int V_7 = - V_137 ;
switch ( V_148 -> V_149 ) {
default:
V_7 = F_152 ( V_2 , V_148 ) ;
break;
}
return V_7 ;
}
long F_153 ( struct V_48 * V_49 ,
unsigned int V_50 , unsigned long V_51 )
{
struct V_1 * V_2 = V_49 -> V_150 ;
void T_7 * V_151 = ( void T_7 * ) V_51 ;
struct V_147 V_148 ;
switch ( V_50 ) {
case V_152 : {
struct F_37 V_143 ;
if ( F_154 ( & V_143 , V_151 , sizeof( V_143 ) ) )
return - V_153 ;
return F_144 ( V_2 , & V_143 ) ;
}
case V_154 :
case V_155 : {
struct V_156 V_157 ;
if ( F_78 ( ! F_103 ( V_2 ) ) )
return - V_97 ;
if ( F_154 ( & V_157 , V_151 , sizeof( V_157 ) ) )
return - V_153 ;
if ( V_50 == V_154 )
return F_155 ( V_2 , & V_157 ) ;
else
return F_156 ( V_2 , & V_157 ) ;
}
case V_158 : {
struct V_159 T_7 * V_160 = V_151 ;
struct V_159 V_161 ;
unsigned V_162 ;
if ( F_78 ( ! F_103 ( V_2 ) ) )
return - V_97 ;
if ( F_154 ( & V_161 , V_160 , sizeof( V_161 ) ) )
return - V_153 ;
V_162 = V_161 . V_162 ;
V_161 . V_162 = F_157 ( V_2 ) ;
if ( F_158 ( V_160 , & V_161 , sizeof( V_161 ) ) )
return - V_153 ;
if ( V_162 < V_161 . V_162 )
return - V_163 ;
return F_159 ( V_2 , V_160 -> V_157 ) ;
}
case V_164 : {
if ( F_154 ( & V_148 , V_151 , sizeof( V_148 ) ) )
return - V_153 ;
return F_147 ( V_2 , & V_148 ) ;
}
case V_165 : {
if ( F_154 ( & V_148 , V_151 , sizeof( V_148 ) ) )
return - V_153 ;
return F_149 ( V_2 , & V_148 ) ;
}
case V_166 : {
if ( F_154 ( & V_148 , V_151 , sizeof( V_148 ) ) )
return - V_153 ;
return F_151 ( V_2 , & V_148 ) ;
}
default:
return - V_9 ;
}
}
int F_160 ( struct V_6 * V_6 , struct V_167 * log )
{
bool V_168 = false ;
int V_26 ;
F_161 ( & V_6 -> V_169 ) ;
V_26 = F_162 ( V_6 , log , & V_168 ) ;
if ( V_168 )
F_163 ( V_6 ) ;
F_164 ( & V_6 -> V_169 ) ;
return V_26 ;
}
static int F_165 ( struct V_6 * V_6 ,
struct V_170 * V_171 )
{
unsigned long V_172 , type ;
V_172 = ( V_171 -> V_52 & V_173 ) >>
V_174 ;
type = ( V_171 -> V_52 & V_175 ) >>
V_176 ;
switch ( V_172 ) {
case V_177 :
if ( ! V_18 )
return - V_137 ;
return F_166 ( V_6 , type , & V_171 -> V_178 , true ) ;
default:
return - V_179 ;
}
}
long F_167 ( struct V_48 * V_49 ,
unsigned int V_50 , unsigned long V_51 )
{
struct V_6 * V_6 = V_49 -> V_150 ;
void T_7 * V_151 = ( void T_7 * ) V_51 ;
switch ( V_50 ) {
case V_180 : {
int V_7 ;
if ( ! V_18 )
return - V_137 ;
F_161 ( & V_6 -> V_181 ) ;
V_7 = F_168 ( V_6 , V_182 ) ;
F_164 ( & V_6 -> V_181 ) ;
return V_7 ;
}
case V_183 : {
struct V_170 V_171 ;
if ( F_154 ( & V_171 , V_151 , sizeof( V_171 ) ) )
return - V_153 ;
return F_165 ( V_6 , & V_171 ) ;
}
case V_184 : {
int V_53 ;
struct F_37 V_143 ;
V_53 = F_169 ( & V_143 ) ;
if ( V_53 )
return V_53 ;
if ( F_158 ( V_151 , & V_143 , sizeof( V_143 ) ) )
return - V_153 ;
return 0 ;
}
default:
return - V_9 ;
}
}
static void F_170 ( void * V_185 )
{
T_3 V_186 ;
unsigned long V_187 ;
unsigned long V_188 ;
unsigned long V_189 ;
F_171 ( F_172 () ) ;
V_186 = F_173 () ;
V_188 = F_6 ( V_190 ) ;
V_187 = V_188 + V_191 ;
V_189 = ( unsigned long ) F_174 ( V_192 ) ;
F_175 ( V_186 , V_187 , V_189 ) ;
F_176 () ;
if ( F_177 () )
F_178 () ;
F_179 () ;
}
static void F_180 ( void )
{
if ( ! F_177 () )
F_181 () ;
}
static void F_182 ( void )
{
F_180 () ;
if ( F_177 () ) {
F_176 () ;
} else {
F_170 ( NULL ) ;
}
if ( V_18 )
F_183 () ;
}
static void F_184 ( void * V_193 )
{
if ( ! F_6 ( V_194 ) ) {
F_182 () ;
F_4 ( V_194 , 1 ) ;
}
}
int F_185 ( void )
{
F_184 ( NULL ) ;
return 0 ;
}
static void F_186 ( void * V_193 )
{
if ( F_6 ( V_194 ) ) {
F_180 () ;
F_4 ( V_194 , 0 ) ;
}
}
void F_187 ( void )
{
F_186 ( NULL ) ;
}
static int F_188 ( struct V_195 * V_196 ,
unsigned long V_197 ,
void * V_73 )
{
switch ( V_197 ) {
case V_198 :
if ( F_6 ( V_194 ) )
F_180 () ;
return V_199 ;
case V_200 :
if ( F_6 ( V_194 ) )
F_182 () ;
return V_199 ;
default:
return V_201 ;
}
}
static void T_8 F_189 ( void )
{
F_190 ( & V_202 ) ;
}
static void T_8 F_191 ( void )
{
F_192 ( & V_202 ) ;
}
static inline void F_189 ( void )
{
}
static inline void F_191 ( void )
{
}
static void F_193 ( void )
{
F_22 ( V_67 ) ;
}
static int F_194 ( void )
{
V_67 = F_13 ( V_203 ) ;
if ( ! V_67 ) {
F_195 ( L_1 ) ;
return - V_12 ;
}
V_85 = F_196 () ;
F_197 ( L_2 , V_85 ) ;
return 0 ;
}
static int F_198 ( void )
{
int V_53 = 0 ;
F_199 ( F_184 , NULL , 1 ) ;
F_189 () ;
V_53 = F_200 () ;
switch ( V_53 ) {
case 0 :
V_18 = true ;
break;
case - V_179 :
case - V_137 :
V_18 = false ;
V_53 = 0 ;
break;
default:
goto V_55;
}
V_53 = F_201 () ;
if ( V_53 )
goto V_55;
F_202 () ;
F_203 () ;
V_55:
F_199 ( F_186 , NULL , 1 ) ;
return V_53 ;
}
static void F_204 ( void )
{
int V_8 ;
if ( F_177 () )
return;
F_205 () ;
F_15 (cpu)
F_206 ( F_207 ( V_190 , V_8 ) ) ;
F_191 () ;
}
static int F_208 ( void )
{
F_197 ( L_3 ) ;
return 0 ;
}
static int F_209 ( void )
{
int V_8 ;
int V_53 = 0 ;
V_53 = F_210 () ;
if ( V_53 )
goto V_204;
F_15 (cpu) {
unsigned long V_188 ;
V_188 = F_211 ( V_57 ) ;
if ( ! V_188 ) {
V_53 = - V_12 ;
goto V_204;
}
F_207 ( V_190 , V_8 ) = V_188 ;
}
V_53 = F_18 ( F_174 ( V_205 ) ,
F_174 ( V_206 ) , V_207 ) ;
if ( V_53 ) {
F_195 ( L_4 ) ;
goto V_204;
}
V_53 = F_18 ( F_174 ( V_208 ) ,
F_174 ( V_209 ) , V_210 ) ;
if ( V_53 ) {
F_195 ( L_5 ) ;
goto V_204;
}
V_53 = F_18 ( F_174 ( V_211 ) ,
F_174 ( V_212 ) , V_210 ) ;
if ( V_53 ) {
F_195 ( L_6 ) ;
goto V_204;
}
F_15 (cpu) {
char * V_188 = ( char * ) F_207 ( V_190 , V_8 ) ;
V_53 = F_18 ( V_188 , V_188 + V_191 ,
V_14 ) ;
if ( V_53 ) {
F_195 ( L_7 ) ;
goto V_204;
}
}
F_15 (cpu) {
V_203 * V_213 ;
V_213 = F_16 ( V_67 , V_8 ) ;
V_53 = F_18 ( V_213 , V_213 + 1 , V_14 ) ;
if ( V_53 ) {
F_195 ( L_8 , V_53 ) ;
goto V_204;
}
}
F_197 ( L_9 ) ;
return 0 ;
V_204:
F_204 () ;
F_195 ( L_10 , V_53 ) ;
return V_53 ;
}
static void F_212 ( void * V_7 )
{
* ( int * ) V_7 = F_140 () ;
}
struct V_1 * F_213 ( struct V_6 * V_6 , unsigned long V_214 )
{
struct V_1 * V_2 ;
int V_23 ;
V_214 &= V_215 ;
F_93 (i, vcpu, kvm) {
if ( V_214 == F_214 ( V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_215 ( void * V_216 )
{
int V_53 ;
int V_7 , V_8 ;
if ( ! F_216 () ) {
F_195 ( L_11 ) ;
return - V_179 ;
}
F_217 (cpu) {
F_218 ( V_8 , F_212 , & V_7 , 1 ) ;
if ( V_7 < 0 ) {
F_195 ( L_12 , V_8 ) ;
return - V_179 ;
}
}
V_53 = F_194 () ;
if ( V_53 )
return V_53 ;
if ( F_177 () )
V_53 = F_208 () ;
else
V_53 = F_209 () ;
if ( V_53 )
goto V_204;
V_53 = F_198 () ;
if ( V_53 )
goto V_217;
return 0 ;
V_217:
F_204 () ;
V_204:
F_193 () ;
return V_53 ;
}
void F_219 ( void )
{
F_220 () ;
}
static int F_221 ( void )
{
int V_218 = F_222 ( NULL , sizeof( struct V_1 ) , 0 , V_219 ) ;
return V_218 ;
}
