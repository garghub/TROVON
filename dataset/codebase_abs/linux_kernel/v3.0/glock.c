static unsigned int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned int V_5 ;
V_5 = F_2 ( & V_4 -> V_6 , sizeof( V_7 ) , 0 ) ;
V_5 = F_2 ( & V_4 -> V_8 , sizeof( unsigned int ) , V_5 ) ;
V_5 = F_2 ( & V_2 , sizeof( struct V_1 * ) , V_5 ) ;
V_5 &= V_9 ;
return V_5 ;
}
static inline void F_3 ( unsigned int V_10 )
{
F_4 ( & V_11 [ V_10 ] ) ;
}
static inline void F_5 ( unsigned int V_10 )
{
F_6 ( & V_11 [ V_10 ] ) ;
}
static void F_7 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_8 ( V_13 , struct V_14 , V_16 ) ;
if ( V_15 -> V_17 -> V_18 & V_19 )
F_9 ( V_20 , V_15 ) ;
else
F_9 ( V_21 , V_15 ) ;
}
void F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_22 ;
F_11 ( & V_15 -> V_16 , F_7 ) ;
if ( F_12 ( & V_2 -> V_23 ) )
F_13 ( & V_2 -> V_24 ) ;
}
void F_14 ( struct V_14 * V_15 )
{
F_15 ( V_15 , F_16 ( & V_15 -> V_25 ) == 0 ) ;
F_17 ( & V_15 -> V_25 ) ;
}
static int F_18 ( const struct V_14 * V_15 )
{
const struct V_26 * V_27 = V_15 -> V_17 ;
if ( V_15 -> V_28 == V_29 )
return 0 ;
if ( ! F_19 ( & V_15 -> V_30 ) )
return 0 ;
if ( V_27 -> V_31 )
return V_27 -> V_31 ( V_15 ) ;
return 1 ;
}
void F_20 ( struct V_14 * V_15 )
{
F_21 ( & V_32 ) ;
if ( ! F_19 ( & V_15 -> V_33 ) )
F_22 ( & V_15 -> V_33 ) ;
else
F_17 ( & V_34 ) ;
F_23 ( & V_15 -> V_33 , & V_35 ) ;
F_24 ( V_36 , & V_15 -> V_37 ) ;
F_25 ( & V_32 ) ;
}
static void F_26 ( struct V_14 * V_15 )
{
F_21 ( & V_32 ) ;
if ( ! F_19 ( & V_15 -> V_33 ) ) {
F_22 ( & V_15 -> V_33 ) ;
F_27 ( & V_34 ) ;
F_28 ( V_36 , & V_15 -> V_37 ) ;
}
F_25 ( & V_32 ) ;
}
static void F_29 ( struct V_14 * V_15 )
{
if ( F_18 ( V_15 ) )
F_20 ( V_15 ) ;
}
void F_30 ( struct V_14 * V_15 )
{
if ( F_12 ( & V_15 -> V_25 ) )
F_15 ( V_15 , 1 ) ;
}
void F_31 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_22 ;
struct V_38 * V_39 = F_32 ( V_15 ) ;
if ( F_12 ( & V_15 -> V_25 ) ) {
F_3 ( V_15 -> F_1 ) ;
F_33 ( & V_15 -> V_40 ) ;
F_5 ( V_15 -> F_1 ) ;
F_26 ( V_15 ) ;
F_15 ( V_15 , ! F_19 ( & V_15 -> V_30 ) ) ;
F_15 ( V_15 , V_39 && V_39 -> V_41 ) ;
F_34 ( V_15 ) ;
V_2 -> V_42 . V_43 -> V_44 ( V_15 ) ;
}
}
static struct V_14 * F_35 ( unsigned int V_10 ,
const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_14 * V_15 ;
struct V_45 * V_5 ;
F_36 (gl, h, &gl_hash_table[hash], gl_list) {
if ( ! F_37 ( & V_15 -> V_46 , V_4 ) )
continue;
if ( V_15 -> V_22 != V_2 )
continue;
if ( F_38 ( & V_15 -> V_25 ) )
return V_15 ;
}
return NULL ;
}
static inline int F_39 ( const struct V_14 * V_15 , const struct V_47 * V_48 )
{
const struct V_47 * V_49 = F_40 ( V_15 -> V_30 . V_50 , const struct V_47 , V_51 ) ;
if ( ( V_48 -> V_52 == V_53 ||
V_49 -> V_52 == V_53 ) && V_48 != V_49 )
return 0 ;
if ( V_15 -> V_28 == V_48 -> V_52 )
return 1 ;
if ( V_48 -> V_54 & V_55 )
return 0 ;
if ( V_15 -> V_28 == V_53 ) {
if ( V_48 -> V_52 == V_56 && V_49 -> V_52 == V_56 )
return 1 ;
if ( V_48 -> V_52 == V_57 && V_49 -> V_52 == V_57 )
return 1 ;
}
if ( V_15 -> V_28 != V_29 && ( V_48 -> V_54 & V_58 ) )
return 1 ;
return 0 ;
}
static void F_41 ( struct V_47 * V_48 )
{
F_28 ( V_59 , & V_48 -> V_60 ) ;
F_42 () ;
F_43 ( & V_48 -> V_60 , V_59 ) ;
}
static inline void F_44 ( struct V_14 * V_15 , const int V_61 )
{
struct V_47 * V_48 , * V_62 ;
F_45 (gh, tmp, &gl->gl_holders, gh_list) {
if ( F_46 ( V_63 , & V_48 -> V_60 ) )
continue;
if ( V_61 & V_64 )
V_48 -> V_65 = - V_66 ;
else if ( V_48 -> V_54 & ( V_67 | V_68 ) )
V_48 -> V_65 = V_69 ;
else
continue;
F_22 ( & V_48 -> V_51 ) ;
F_47 ( V_48 , 0 ) ;
F_41 ( V_48 ) ;
}
}
static int F_48 ( struct V_14 * V_15 )
__releases( &gl->gl_spin
static inline struct V_47 * F_49 ( const struct V_14 * V_15 )
{
struct V_47 * V_48 ;
F_50 (gh, &gl->gl_holders, gh_list) {
if ( ! F_46 ( V_63 , & V_48 -> V_60 ) )
return V_48 ;
}
return NULL ;
}
static void F_51 ( struct V_14 * V_15 , unsigned int V_70 )
{
int V_71 , V_72 ;
V_71 = ( V_15 -> V_28 != V_29 ) ;
V_72 = ( V_70 != V_29 ) ;
if ( V_71 != V_72 ) {
if ( V_72 )
F_14 ( V_15 ) ;
else
F_30 ( V_15 ) ;
}
if ( V_71 && V_72 && F_19 ( & V_15 -> V_30 ) )
F_28 ( V_73 , & V_15 -> V_37 ) ;
V_15 -> V_28 = V_70 ;
V_15 -> V_74 = V_75 ;
}
static void F_52 ( struct V_14 * V_15 )
{
V_15 -> V_76 = V_53 ;
F_28 ( V_77 , & V_15 -> V_37 ) ;
F_42 () ;
F_43 ( & V_15 -> V_37 , V_77 ) ;
}
static void F_53 ( struct V_14 * V_15 , unsigned int V_61 )
{
const struct V_26 * V_27 = V_15 -> V_17 ;
struct V_47 * V_48 ;
unsigned V_78 = V_61 & V_79 ;
int V_80 ;
F_21 ( & V_15 -> V_81 ) ;
F_54 ( V_15 , V_78 ) ;
F_51 ( V_15 , V_78 ) ;
V_48 = F_49 ( V_15 ) ;
if ( F_46 ( V_82 , & V_15 -> V_37 ) &&
V_78 != V_29 && V_15 -> V_76 == V_29 )
V_15 -> V_83 = V_29 ;
if ( F_55 ( V_78 != V_15 -> V_83 ) ) {
if ( V_48 && ! F_46 ( V_82 , & V_15 -> V_37 ) ) {
if ( V_61 & V_84 ) {
if ( ( V_48 -> V_54 & V_85 ) == 0 )
F_56 ( & V_48 -> V_51 , & V_15 -> V_30 ) ;
V_48 = F_49 ( V_15 ) ;
V_15 -> V_83 = V_48 -> V_52 ;
goto V_86;
}
if ( ( V_61 & V_64 ) ||
( V_48 -> V_54 & ( V_67 | V_68 ) ) ) {
V_15 -> V_83 = V_15 -> V_28 ;
F_44 ( V_15 , V_61 ) ;
goto V_87;
}
}
switch( V_78 ) {
case V_29 :
V_86:
F_57 ( V_15 , V_48 , V_15 -> V_83 ) ;
break;
case V_56 :
case V_57 :
F_57 ( V_15 , V_48 , V_29 ) ;
break;
default:
F_58 ( V_88 L_1 , V_15 -> V_83 , V_78 ) ;
F_15 ( V_15 , 1 ) ;
}
F_25 ( & V_15 -> V_81 ) ;
return;
}
if ( F_59 ( V_82 , & V_15 -> V_37 ) )
F_52 ( V_15 ) ;
if ( V_78 != V_29 ) {
if ( V_27 -> V_89 ) {
F_25 ( & V_15 -> V_81 ) ;
V_80 = V_27 -> V_89 ( V_15 , V_48 ) ;
F_21 ( & V_15 -> V_81 ) ;
if ( V_80 ) {
F_44 ( V_15 , V_80 ) ;
goto V_87;
}
}
V_80 = F_48 ( V_15 ) ;
if ( V_80 == 2 )
goto V_90;
}
V_87:
F_28 ( V_91 , & V_15 -> V_37 ) ;
V_90:
F_25 ( & V_15 -> V_81 ) ;
}
static void F_57 ( struct V_14 * V_15 , struct V_47 * V_48 , unsigned int V_92 )
__releases( &gl->gl_spin
static inline struct V_47 * F_60 ( const struct V_14 * V_15 )
{
struct V_47 * V_48 ;
if ( ! F_19 ( & V_15 -> V_30 ) ) {
V_48 = F_40 ( V_15 -> V_30 . V_50 , struct V_47 , V_51 ) ;
if ( F_46 ( V_63 , & V_48 -> V_60 ) )
return V_48 ;
}
return NULL ;
}
static void F_61 ( struct V_14 * V_15 , const int V_93 )
__releases( &gl->gl_spin
static void F_62 ( struct V_94 * V_95 )
{
struct V_14 * V_15 = F_8 ( V_95 , struct V_14 , V_96 ) ;
struct V_1 * V_2 = V_15 -> V_22 ;
struct V_97 * V_98 ;
struct V_99 * V_99 ;
V_7 V_100 = V_15 -> V_46 . V_6 ;
V_98 = V_15 -> V_101 ;
if ( V_98 )
V_99 = F_63 ( V_2 -> V_102 , V_100 , 1 ) ;
else
V_99 = F_64 ( V_2 , V_100 , NULL , V_103 ) ;
if ( V_99 && ! F_65 ( V_99 ) ) {
F_66 ( V_99 ) ;
F_67 ( V_99 ) ;
}
F_31 ( V_15 ) ;
}
static void F_68 ( struct V_94 * V_95 )
{
unsigned long V_104 = 0 ;
struct V_14 * V_15 = F_8 ( V_95 , struct V_14 , V_105 . V_95 ) ;
int V_106 = 0 ;
if ( F_59 ( V_107 , & V_15 -> V_37 ) ) {
F_53 ( V_15 , V_15 -> V_108 ) ;
V_106 = 1 ;
}
F_21 ( & V_15 -> V_81 ) ;
if ( F_46 ( V_109 , & V_15 -> V_37 ) &&
V_15 -> V_28 != V_29 &&
V_15 -> V_76 != V_53 ) {
unsigned long V_110 , V_111 = V_75 ;
V_110 = V_15 -> V_74 + V_15 -> V_17 -> V_112 ;
if ( F_69 ( V_111 , V_110 ) )
V_104 = V_110 - V_111 ;
if ( ! V_104 ) {
F_28 ( V_109 , & V_15 -> V_37 ) ;
F_24 ( V_77 , & V_15 -> V_37 ) ;
}
}
F_61 ( V_15 , 0 ) ;
F_25 ( & V_15 -> V_81 ) ;
if ( ! V_104 ||
F_70 ( V_113 , & V_15 -> V_105 , V_104 ) == 0 )
F_31 ( V_15 ) ;
if ( V_106 )
F_31 ( V_15 ) ;
}
int F_71 ( struct V_1 * V_2 , V_7 V_114 ,
const struct V_26 * V_27 , int V_115 ,
struct V_14 * * V_116 )
{
struct V_117 * V_118 = V_2 -> V_102 ;
struct V_3 V_4 = { . V_6 = V_114 , . V_8 = V_27 -> V_119 } ;
struct V_14 * V_15 , * V_62 ;
unsigned int V_10 = F_1 ( V_2 , & V_4 ) ;
struct V_38 * V_39 ;
struct V_120 * V_121 ;
F_72 () ;
V_15 = F_35 ( V_10 , V_2 , & V_4 ) ;
F_73 () ;
* V_116 = V_15 ;
if ( V_15 )
return 0 ;
if ( ! V_115 )
return - V_122 ;
if ( V_27 -> V_18 & V_19 )
V_121 = V_20 ;
else
V_121 = V_21 ;
V_15 = F_74 ( V_121 , V_123 ) ;
if ( ! V_15 )
return - V_124 ;
F_17 ( & V_2 -> V_23 ) ;
V_15 -> V_37 = 0 ;
V_15 -> V_46 = V_4 ;
F_75 ( & V_15 -> V_25 , 1 ) ;
V_15 -> V_28 = V_29 ;
V_15 -> V_83 = V_29 ;
V_15 -> V_76 = V_53 ;
V_15 -> F_1 = V_10 ;
V_15 -> V_17 = V_27 ;
snprintf ( V_15 -> V_125 , V_126 , L_2 , V_4 . V_8 , ( unsigned long long ) V_114 ) ;
memset ( & V_15 -> V_127 , 0 , sizeof( struct V_128 ) ) ;
V_15 -> V_127 . V_129 = V_15 -> V_130 ;
V_15 -> V_74 = V_75 ;
V_15 -> V_101 = NULL ;
V_15 -> V_22 = V_2 ;
F_76 ( & V_15 -> V_105 , F_68 ) ;
F_77 ( & V_15 -> V_96 , F_62 ) ;
V_39 = F_32 ( V_15 ) ;
if ( V_39 ) {
V_39 -> V_131 = & V_132 ;
V_39 -> V_133 = V_118 -> V_134 -> V_135 ;
V_39 -> V_136 = 0 ;
F_78 ( V_39 , V_137 ) ;
V_39 -> V_138 = NULL ;
V_39 -> V_139 = V_118 -> V_140 ;
V_39 -> V_141 = 0 ;
}
F_3 ( V_10 ) ;
V_62 = F_35 ( V_10 , V_2 , & V_4 ) ;
if ( V_62 ) {
F_5 ( V_10 ) ;
F_9 ( V_121 , V_15 ) ;
F_27 ( & V_2 -> V_23 ) ;
V_15 = V_62 ;
} else {
F_79 ( & V_15 -> V_40 , & V_11 [ V_10 ] ) ;
F_5 ( V_10 ) ;
}
* V_116 = V_15 ;
return 0 ;
}
void F_80 ( struct V_14 * V_15 , unsigned int V_78 , unsigned V_136 ,
struct V_47 * V_48 )
{
F_81 ( & V_48 -> V_51 ) ;
V_48 -> V_142 = V_15 ;
V_48 -> V_143 = ( unsigned long ) F_82 ( 0 ) ;
V_48 -> V_144 = F_83 ( F_84 ( V_145 ) ) ;
V_48 -> V_52 = V_78 ;
V_48 -> V_54 = V_136 ;
V_48 -> V_65 = 0 ;
V_48 -> V_60 = 0 ;
F_14 ( V_15 ) ;
}
void F_85 ( unsigned int V_78 , unsigned V_136 , struct V_47 * V_48 )
{
V_48 -> V_52 = V_78 ;
V_48 -> V_54 = V_136 ;
V_48 -> V_60 = 0 ;
V_48 -> V_143 = ( unsigned long ) F_82 ( 0 ) ;
if ( V_48 -> V_144 )
F_86 ( V_48 -> V_144 ) ;
V_48 -> V_144 = F_83 ( F_84 ( V_145 ) ) ;
}
void F_87 ( struct V_47 * V_48 )
{
F_86 ( V_48 -> V_144 ) ;
F_31 ( V_48 -> V_142 ) ;
V_48 -> V_142 = NULL ;
V_48 -> V_143 = 0 ;
}
static int F_88 ( void * V_146 )
{
F_89 () ;
return 0 ;
}
static int F_90 ( void * V_146 )
{
F_89 () ;
return 0 ;
}
static void F_91 ( struct V_47 * V_48 )
{
F_92 () ;
F_93 ( & V_48 -> V_60 , V_59 , F_88 , V_147 ) ;
}
static void F_94 ( struct V_14 * V_15 )
{
F_92 () ;
F_93 ( & V_15 -> V_37 , V_77 , F_90 , V_147 ) ;
}
static void F_95 ( struct V_14 * V_15 , unsigned int V_78 ,
unsigned long V_104 )
{
int V_148 = V_104 ? V_109 : V_77 ;
F_24 ( V_148 , & V_15 -> V_37 ) ;
if ( V_15 -> V_76 == V_53 ) {
V_15 -> V_76 = V_78 ;
V_15 -> V_149 = V_75 ;
} else if ( V_15 -> V_76 != V_29 &&
V_15 -> V_76 != V_78 ) {
V_15 -> V_76 = V_29 ;
}
if ( V_15 -> V_17 -> V_150 )
V_15 -> V_17 -> V_150 ( V_15 ) ;
F_96 ( V_15 ) ;
}
int F_97 ( struct V_47 * V_48 )
{
F_91 ( V_48 ) ;
return V_48 -> V_65 ;
}
void F_98 ( struct V_151 * V_152 , const char * V_153 , ... )
{
struct V_154 V_155 ;
T_1 args ;
va_start ( args , V_153 ) ;
if ( V_152 ) {
struct V_156 * V_157 = V_152 -> V_158 ;
vsprintf ( V_157 -> string , V_153 , args ) ;
F_99 ( V_152 , V_157 -> string ) ;
} else {
V_155 . V_153 = V_153 ;
V_155 . V_159 = & args ;
F_58 ( V_88 L_3 , & V_155 ) ;
}
va_end ( args ) ;
}
static inline void F_100 ( struct V_47 * V_48 )
__releases( &gl->gl_spin
int F_101 ( struct V_47 * V_48 )
{
struct V_14 * V_15 = V_48 -> V_142 ;
struct V_1 * V_2 = V_15 -> V_22 ;
int error = 0 ;
if ( F_55 ( F_46 ( V_160 , & V_2 -> V_161 ) ) )
return - V_66 ;
if ( F_46 ( V_36 , & V_15 -> V_37 ) )
F_26 ( V_15 ) ;
F_21 ( & V_15 -> V_81 ) ;
F_100 ( V_48 ) ;
if ( ( V_162 & V_48 -> V_54 ) &&
F_59 ( V_163 , & V_15 -> V_37 ) )
F_24 ( V_107 , & V_15 -> V_37 ) ;
F_61 ( V_15 , 1 ) ;
F_25 ( & V_15 -> V_81 ) ;
if ( ! ( V_48 -> V_54 & V_164 ) )
error = F_97 ( V_48 ) ;
return error ;
}
int F_102 ( struct V_47 * V_48 )
{
return F_46 ( V_59 , & V_48 -> V_60 ) ? 0 : 1 ;
}
void F_103 ( struct V_47 * V_48 )
{
struct V_14 * V_15 = V_48 -> V_142 ;
const struct V_26 * V_27 = V_15 -> V_17 ;
unsigned V_104 = 0 ;
int V_165 = 0 ;
F_21 ( & V_15 -> V_81 ) ;
if ( V_48 -> V_54 & V_166 )
F_95 ( V_15 , V_29 , 0 ) ;
F_22 ( & V_48 -> V_51 ) ;
if ( F_60 ( V_15 ) == NULL ) {
if ( V_27 -> V_167 ) {
F_15 ( V_15 , F_104 ( V_91 , & V_15 -> V_37 ) ) ;
F_25 ( & V_15 -> V_81 ) ;
V_27 -> V_167 ( V_48 ) ;
F_21 ( & V_15 -> V_81 ) ;
F_28 ( V_91 , & V_15 -> V_37 ) ;
}
if ( F_19 ( & V_15 -> V_30 ) &&
! F_46 ( V_109 , & V_15 -> V_37 ) &&
! F_46 ( V_77 , & V_15 -> V_37 ) )
V_165 = 1 ;
}
if ( ! F_46 ( V_168 , & V_15 -> V_37 ) )
F_29 ( V_15 ) ;
F_47 ( V_48 , 0 ) ;
F_25 ( & V_15 -> V_81 ) ;
if ( F_105 ( V_165 ) )
return;
F_14 ( V_15 ) ;
if ( F_46 ( V_109 , & V_15 -> V_37 ) &&
! F_46 ( V_77 , & V_15 -> V_37 ) )
V_104 = V_15 -> V_17 -> V_112 ;
if ( F_70 ( V_113 , & V_15 -> V_105 , V_104 ) == 0 )
F_31 ( V_15 ) ;
}
void F_106 ( struct V_47 * V_48 )
{
struct V_14 * V_15 = V_48 -> V_142 ;
F_103 ( V_48 ) ;
F_94 ( V_15 ) ;
}
void F_107 ( struct V_47 * V_48 )
{
F_103 ( V_48 ) ;
F_87 ( V_48 ) ;
}
int F_108 ( struct V_1 * V_2 , V_7 V_114 ,
const struct V_26 * V_27 ,
unsigned int V_78 , int V_136 , struct V_47 * V_48 )
{
struct V_14 * V_15 ;
int error ;
error = F_71 ( V_2 , V_114 , V_27 , V_169 , & V_15 ) ;
if ( ! error ) {
error = F_109 ( V_15 , V_78 , V_136 , V_48 ) ;
F_31 ( V_15 ) ;
}
return error ;
}
static int F_110 ( const void * V_170 , const void * V_171 )
{
const struct V_47 * V_172 = * ( const struct V_47 * * ) V_170 ;
const struct V_47 * V_173 = * ( const struct V_47 * * ) V_171 ;
const struct V_3 * V_174 = & V_172 -> V_142 -> V_46 ;
const struct V_3 * V_175 = & V_173 -> V_142 -> V_46 ;
if ( V_174 -> V_6 > V_175 -> V_6 )
return 1 ;
if ( V_174 -> V_6 < V_175 -> V_6 )
return - 1 ;
F_111 ( V_172 -> V_142 -> V_17 -> V_119 == V_173 -> V_142 -> V_17 -> V_119 ) ;
return 0 ;
}
static int F_112 ( unsigned int V_176 , struct V_47 * V_177 ,
struct V_47 * * V_178 )
{
unsigned int V_179 ;
int error = 0 ;
for ( V_179 = 0 ; V_179 < V_176 ; V_179 ++ )
V_178 [ V_179 ] = & V_177 [ V_179 ] ;
F_113 ( V_178 , V_176 , sizeof( struct V_47 * ) , F_110 , NULL ) ;
for ( V_179 = 0 ; V_179 < V_176 ; V_179 ++ ) {
V_178 [ V_179 ] -> V_54 &= ~ ( V_67 | V_164 ) ;
error = F_101 ( V_178 [ V_179 ] ) ;
if ( error ) {
while ( V_179 -- )
F_103 ( V_178 [ V_179 ] ) ;
break;
}
}
return error ;
}
int F_114 ( unsigned int V_176 , struct V_47 * V_177 )
{
struct V_47 * V_62 [ 4 ] ;
struct V_47 * * V_180 = V_62 ;
int error = 0 ;
switch( V_176 ) {
case 0 :
return 0 ;
case 1 :
V_177 -> V_54 &= ~ ( V_67 | V_164 ) ;
return F_101 ( V_177 ) ;
default:
if ( V_176 <= 4 )
break;
V_180 = F_115 ( V_176 * sizeof( struct V_47 * ) , V_137 ) ;
if ( ! V_180 )
return - V_124 ;
}
error = F_112 ( V_176 , V_177 , V_180 ) ;
if ( V_180 != V_62 )
F_116 ( V_180 ) ;
return error ;
}
void F_117 ( unsigned int V_176 , struct V_47 * V_177 )
{
while ( V_176 -- )
F_103 ( & V_177 [ V_176 ] ) ;
}
void F_118 ( unsigned int V_176 , struct V_47 * V_177 )
{
while ( V_176 -- )
F_107 ( & V_177 [ V_176 ] ) ;
}
void F_119 ( struct V_14 * V_15 , unsigned int V_78 )
{
unsigned long V_104 = 0 ;
unsigned long V_110 ;
unsigned long V_111 = V_75 ;
F_14 ( V_15 ) ;
V_110 = V_15 -> V_74 + V_15 -> V_17 -> V_112 ;
if ( F_46 ( V_73 , & V_15 -> V_37 ) ) {
if ( F_69 ( V_111 , V_110 ) )
V_104 = V_110 - V_111 ;
if ( F_46 ( V_107 , & V_15 -> V_37 ) )
V_104 = V_15 -> V_17 -> V_112 ;
}
F_21 ( & V_15 -> V_81 ) ;
F_95 ( V_15 , V_78 , V_104 ) ;
F_25 ( & V_15 -> V_81 ) ;
if ( F_70 ( V_113 , & V_15 -> V_105 , V_104 ) == 0 )
F_31 ( V_15 ) ;
}
static int F_120 ( const struct V_14 * V_15 )
{
const struct V_47 * V_48 ;
if ( V_15 -> V_108 & ~ V_79 )
return 0 ;
if ( V_15 -> V_83 == V_29 )
return 0 ;
F_50 (gh, &gl->gl_holders, gh_list) {
if ( F_46 ( V_63 , & V_48 -> V_60 ) )
continue;
if ( V_162 & V_48 -> V_54 )
return 0 ;
}
return 1 ;
}
void F_121 ( struct V_14 * V_15 , int V_61 )
{
struct V_181 * V_182 = & V_15 -> V_22 -> V_42 ;
F_21 ( & V_15 -> V_81 ) ;
V_15 -> V_108 = V_61 ;
if ( F_55 ( F_46 ( V_183 , & V_182 -> V_184 ) ) ) {
if ( F_120 ( V_15 ) ) {
F_24 ( V_163 , & V_15 -> V_37 ) ;
F_25 ( & V_15 -> V_81 ) ;
return;
}
}
F_25 ( & V_15 -> V_81 ) ;
F_24 ( V_107 , & V_15 -> V_37 ) ;
F_122 () ;
F_14 ( V_15 ) ;
if ( F_70 ( V_113 , & V_15 -> V_105 , 0 ) == 0 )
F_31 ( V_15 ) ;
}
static int F_123 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
struct V_14 * V_15 ;
int V_189 ;
int V_190 = 0 ;
int V_191 = V_188 -> V_192 ;
T_2 V_193 = V_188 -> V_193 ;
F_124 ( V_194 ) ;
if ( V_191 == 0 )
goto V_87;
if ( ! ( V_193 & V_195 ) )
return - 1 ;
F_21 ( & V_32 ) ;
while( V_191 && ! F_19 ( & V_35 ) ) {
V_15 = F_40 ( V_35 . V_50 , struct V_14 , V_33 ) ;
F_22 ( & V_15 -> V_33 ) ;
F_28 ( V_36 , & V_15 -> V_37 ) ;
F_27 ( & V_34 ) ;
if ( ! F_104 ( V_91 , & V_15 -> V_37 ) ) {
F_14 ( V_15 ) ;
F_25 ( & V_32 ) ;
F_21 ( & V_15 -> V_81 ) ;
V_189 = F_18 ( V_15 ) ;
if ( V_189 ) {
F_95 ( V_15 , V_29 , 0 ) ;
V_191 -- ;
}
F_28 ( V_91 , & V_15 -> V_37 ) ;
F_42 () ;
if ( F_70 ( V_113 , & V_15 -> V_105 , 0 ) == 0 )
F_30 ( V_15 ) ;
F_25 ( & V_15 -> V_81 ) ;
F_21 ( & V_32 ) ;
continue;
}
V_190 ++ ;
F_125 ( & V_15 -> V_33 , & V_194 ) ;
F_24 ( V_36 , & V_15 -> V_37 ) ;
}
F_126 ( & V_194 , & V_35 ) ;
F_127 ( V_190 , & V_34 ) ;
F_25 ( & V_32 ) ;
V_87:
return ( F_16 ( & V_34 ) / 100 ) * V_196 ;
}
static void F_128 ( T_3 V_197 , const struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_14 * V_15 ;
struct V_198 * V_199 = & V_11 [ V_10 ] ;
struct V_45 * V_200 ;
F_72 () ;
F_36 (gl, pos, head, gl_list) {
if ( ( V_15 -> V_22 == V_2 ) && F_16 ( & V_15 -> V_25 ) )
V_197 ( V_15 ) ;
}
F_73 () ;
F_129 () ;
}
static void F_130 ( T_3 V_197 , const struct V_1 * V_2 )
{
unsigned V_179 ;
for ( V_179 = 0 ; V_179 < V_201 ; V_179 ++ )
F_128 ( V_197 , V_2 , V_179 ) ;
}
static void F_131 ( struct V_14 * V_15 )
{
if ( ! F_59 ( V_163 , & V_15 -> V_37 ) )
return;
F_24 ( V_107 , & V_15 -> V_37 ) ;
F_14 ( V_15 ) ;
if ( F_70 ( V_113 , & V_15 -> V_105 , 0 ) == 0 )
F_31 ( V_15 ) ;
}
static void F_132 ( struct V_14 * V_15 )
{
F_26 ( V_15 ) ;
F_21 ( & V_15 -> V_81 ) ;
if ( V_15 -> V_28 != V_29 )
F_95 ( V_15 , V_29 , 0 ) ;
F_25 ( & V_15 -> V_81 ) ;
F_14 ( V_15 ) ;
if ( F_70 ( V_113 , & V_15 -> V_105 , 0 ) == 0 )
F_31 ( V_15 ) ;
}
void F_133 ( struct V_1 * V_2 )
{
F_130 ( F_131 , V_2 ) ;
}
static int F_134 ( struct V_151 * V_152 , struct V_14 * V_15 )
{
int V_61 ;
F_21 ( & V_15 -> V_81 ) ;
V_61 = F_135 ( V_152 , V_15 ) ;
F_25 ( & V_15 -> V_81 ) ;
return V_61 ;
}
static void F_136 ( struct V_14 * V_15 )
{
F_134 ( NULL , V_15 ) ;
}
void F_137 ( struct V_1 * V_2 )
{
F_130 ( F_132 , V_2 ) ;
F_138 ( V_113 ) ;
F_139 ( V_2 -> V_24 , F_16 ( & V_2 -> V_23 ) == 0 ) ;
F_130 ( F_136 , V_2 ) ;
}
void F_140 ( struct V_97 * V_98 )
{
struct V_14 * V_15 = V_98 -> V_202 ;
int V_61 ;
V_61 = F_141 ( V_98 ) ;
F_142 ( V_15 -> V_22 , V_61 == 0 ) ;
F_21 ( & V_15 -> V_81 ) ;
F_28 ( V_91 , & V_15 -> V_37 ) ;
F_61 ( V_15 , 1 ) ;
F_25 ( & V_15 -> V_81 ) ;
}
static const char * F_143 ( unsigned V_78 )
{
switch( V_78 ) {
case V_29 :
return L_4 ;
case V_56 :
return L_5 ;
case V_57 :
return L_6 ;
case V_53 :
return L_7 ;
}
return L_8 ;
}
static const char * F_144 ( char * V_203 , unsigned V_136 , unsigned long V_204 )
{
char * V_178 = V_203 ;
if ( V_136 & V_67 )
* V_178 ++ = 't' ;
if ( V_136 & V_68 )
* V_178 ++ = 'T' ;
if ( V_136 & V_162 )
* V_178 ++ = 'e' ;
if ( V_136 & V_58 )
* V_178 ++ = 'A' ;
if ( V_136 & V_85 )
* V_178 ++ = 'p' ;
if ( V_136 & V_164 )
* V_178 ++ = 'a' ;
if ( V_136 & V_55 )
* V_178 ++ = 'E' ;
if ( V_136 & V_166 )
* V_178 ++ = 'c' ;
if ( F_46 ( V_63 , & V_204 ) )
* V_178 ++ = 'H' ;
if ( F_46 ( V_59 , & V_204 ) )
* V_178 ++ = 'W' ;
if ( F_46 ( V_205 , & V_204 ) )
* V_178 ++ = 'F' ;
* V_178 = 0 ;
return V_203 ;
}
static int F_145 ( struct V_151 * V_152 , const struct V_47 * V_48 )
{
struct V_206 * V_207 = NULL ;
char V_208 [ 32 ] ;
if ( V_48 -> V_144 )
V_207 = F_146 ( V_48 -> V_144 , V_209 ) ;
F_98 ( V_152 , L_9 ,
F_143 ( V_48 -> V_52 ) ,
F_144 ( V_208 , V_48 -> V_54 , V_48 -> V_60 ) ,
V_48 -> V_65 ,
V_48 -> V_144 ? ( long ) F_147 ( V_48 -> V_144 ) : - 1 ,
V_207 ? V_207 -> V_210 : L_10 ,
( void * ) V_48 -> V_143 ) ;
return 0 ;
}
static const char * F_148 ( char * V_203 , const struct V_14 * V_15 )
{
const unsigned long * V_211 = & V_15 -> V_37 ;
char * V_178 = V_203 ;
if ( F_46 ( V_91 , V_211 ) )
* V_178 ++ = 'l' ;
if ( F_46 ( V_77 , V_211 ) )
* V_178 ++ = 'D' ;
if ( F_46 ( V_109 , V_211 ) )
* V_178 ++ = 'd' ;
if ( F_46 ( V_82 , V_211 ) )
* V_178 ++ = 'p' ;
if ( F_46 ( V_212 , V_211 ) )
* V_178 ++ = 'y' ;
if ( F_46 ( V_168 , V_211 ) )
* V_178 ++ = 'f' ;
if ( F_46 ( V_213 , V_211 ) )
* V_178 ++ = 'i' ;
if ( F_46 ( V_107 , V_211 ) )
* V_178 ++ = 'r' ;
if ( F_46 ( V_214 , V_211 ) )
* V_178 ++ = 'I' ;
if ( F_46 ( V_163 , V_211 ) )
* V_178 ++ = 'F' ;
if ( F_46 ( V_73 , V_211 ) )
* V_178 ++ = 'q' ;
if ( F_46 ( V_36 , V_211 ) )
* V_178 ++ = 'L' ;
if ( V_15 -> V_101 )
* V_178 ++ = 'o' ;
* V_178 = 0 ;
return V_203 ;
}
static int F_135 ( struct V_151 * V_152 , const struct V_14 * V_15 )
{
const struct V_26 * V_27 = V_15 -> V_17 ;
unsigned long long V_215 ;
const struct V_47 * V_48 ;
char V_216 [ 32 ] ;
int error = 0 ;
V_215 = V_75 - V_15 -> V_149 ;
V_215 *= 1000000 / V_217 ;
if ( ! F_46 ( V_77 , & V_15 -> V_37 ) )
V_215 = 0 ;
F_98 ( V_152 , L_11 ,
F_143 ( V_15 -> V_28 ) ,
V_15 -> V_46 . V_8 ,
( unsigned long long ) V_15 -> V_46 . V_6 ,
F_148 ( V_216 , V_15 ) ,
F_143 ( V_15 -> V_83 ) ,
F_143 ( V_15 -> V_76 ) , V_215 ,
F_16 ( & V_15 -> V_218 ) ,
F_16 ( & V_15 -> V_219 ) ,
F_16 ( & V_15 -> V_25 ) ) ;
F_50 (gh, &gl->gl_holders, gh_list) {
error = F_145 ( V_152 , V_48 ) ;
if ( error )
goto V_87;
}
if ( V_15 -> V_28 != V_29 && V_27 -> V_220 )
error = V_27 -> V_220 ( V_152 , V_15 ) ;
V_87:
return error ;
}
int T_4 F_149 ( void )
{
unsigned V_221 ;
for( V_221 = 0 ; V_221 < V_201 ; V_221 ++ ) {
F_150 ( & V_11 [ V_221 ] ) ;
}
V_113 = F_151 ( L_12 , V_222 |
V_223 | V_224 , 0 ) ;
if ( F_65 ( V_113 ) )
return F_152 ( V_113 ) ;
V_225 = F_151 ( L_13 ,
V_222 | V_224 ,
0 ) ;
if ( F_65 ( V_225 ) ) {
F_153 ( V_113 ) ;
return F_152 ( V_225 ) ;
}
F_154 ( & V_226 ) ;
return 0 ;
}
void F_155 ( void )
{
F_156 ( & V_226 ) ;
F_153 ( V_113 ) ;
F_153 ( V_225 ) ;
}
static inline struct V_14 * F_157 ( unsigned V_10 )
{
return F_158 ( F_159 ( & V_11 [ V_10 ] ) ,
struct V_14 , V_40 ) ;
}
static inline struct V_14 * F_160 ( struct V_14 * V_15 )
{
return F_158 ( F_161 ( V_15 -> V_40 . V_50 ) ,
struct V_14 , V_40 ) ;
}
static int F_162 ( struct V_156 * V_157 )
{
struct V_14 * V_15 ;
do {
V_15 = V_157 -> V_15 ;
if ( V_15 ) {
V_157 -> V_15 = F_160 ( V_15 ) ;
} else {
V_157 -> V_15 = F_157 ( V_157 -> V_10 ) ;
}
while ( V_157 -> V_15 == NULL ) {
V_157 -> V_10 ++ ;
if ( V_157 -> V_10 >= V_201 ) {
F_73 () ;
return 1 ;
}
V_157 -> V_15 = F_157 ( V_157 -> V_10 ) ;
}
} while ( V_157 -> V_2 != V_157 -> V_15 -> V_22 || F_16 ( & V_157 -> V_15 -> V_25 ) == 0 );
return 0 ;
}
static void * F_163 ( struct V_151 * V_152 , T_5 * V_200 )
{
struct V_156 * V_157 = V_152 -> V_158 ;
T_5 V_227 = * V_200 ;
V_157 -> V_10 = 0 ;
F_72 () ;
do {
if ( F_162 ( V_157 ) )
return NULL ;
} while ( V_227 -- );
return V_157 -> V_15 ;
}
static void * F_164 ( struct V_151 * V_152 , void * V_228 ,
T_5 * V_200 )
{
struct V_156 * V_157 = V_152 -> V_158 ;
( * V_200 ) ++ ;
if ( F_162 ( V_157 ) )
return NULL ;
return V_157 -> V_15 ;
}
static void F_165 ( struct V_151 * V_152 , void * V_228 )
{
struct V_156 * V_157 = V_152 -> V_158 ;
if ( V_157 -> V_15 )
F_73 () ;
V_157 -> V_15 = NULL ;
}
static int F_166 ( struct V_151 * V_152 , void * V_228 )
{
return F_134 ( V_152 , V_228 ) ;
}
static int F_167 ( struct V_99 * V_99 , struct V_229 * V_229 )
{
int V_61 = F_168 ( V_229 , & V_230 ,
sizeof( struct V_156 ) ) ;
if ( V_61 == 0 ) {
struct V_151 * V_152 = V_229 -> V_231 ;
struct V_156 * V_157 = V_152 -> V_158 ;
V_157 -> V_2 = V_99 -> V_232 ;
}
return V_61 ;
}
int F_169 ( struct V_1 * V_2 )
{
V_2 -> V_233 = F_170 ( V_2 -> V_234 , V_235 ) ;
if ( ! V_2 -> V_233 )
return - V_124 ;
V_2 -> V_236 = F_171 ( L_14 ,
V_237 | V_238 ,
V_2 -> V_233 , V_2 ,
& V_239 ) ;
if ( ! V_2 -> V_236 )
return - V_124 ;
return 0 ;
}
void F_172 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_233 ) {
if ( V_2 -> V_236 ) {
F_173 ( V_2 -> V_236 ) ;
V_2 -> V_236 = NULL ;
}
F_173 ( V_2 -> V_233 ) ;
V_2 -> V_233 = NULL ;
}
}
int F_174 ( void )
{
V_235 = F_170 ( L_15 , NULL ) ;
return V_235 ? 0 : - V_124 ;
}
void F_175 ( void )
{
F_173 ( V_235 ) ;
V_235 = NULL ;
}
