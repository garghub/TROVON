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
if ( ! F_19 ( & V_15 -> V_33 ) ) {
F_22 ( & V_15 -> V_33 ) ;
F_27 ( & V_34 ) ;
F_28 ( V_36 , & V_15 -> V_37 ) ;
}
}
static void F_29 ( struct V_14 * V_15 )
{
F_21 ( & V_32 ) ;
F_26 ( V_15 ) ;
F_25 ( & V_32 ) ;
}
static void F_30 ( struct V_14 * V_15 )
{
if ( F_18 ( V_15 ) )
F_20 ( V_15 ) ;
}
void F_31 ( struct V_14 * V_15 )
{
if ( F_12 ( & V_15 -> V_25 ) )
F_15 ( V_15 , 1 ) ;
}
void F_32 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_22 ;
struct V_38 * V_39 = F_33 ( V_15 ) ;
if ( F_34 ( & V_15 -> V_25 , & V_32 ) ) {
F_26 ( V_15 ) ;
F_25 ( & V_32 ) ;
F_3 ( V_15 -> F_1 ) ;
F_35 ( & V_15 -> V_40 ) ;
F_5 ( V_15 -> F_1 ) ;
F_15 ( V_15 , ! F_19 ( & V_15 -> V_30 ) ) ;
F_15 ( V_15 , V_39 && V_39 -> V_41 ) ;
F_36 ( V_15 ) ;
V_2 -> V_42 . V_43 -> V_44 ( V_15 ) ;
}
}
static struct V_14 * F_37 ( unsigned int V_10 ,
const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_14 * V_15 ;
struct V_45 * V_5 ;
F_38 (gl, h, &gl_hash_table[hash], gl_list) {
if ( ! F_39 ( & V_15 -> V_46 , V_4 ) )
continue;
if ( V_15 -> V_22 != V_2 )
continue;
if ( F_40 ( & V_15 -> V_25 ) )
return V_15 ;
}
return NULL ;
}
static inline int F_41 ( const struct V_14 * V_15 , const struct V_47 * V_48 )
{
const struct V_47 * V_49 = F_42 ( V_15 -> V_30 . V_50 , const struct V_47 , V_51 ) ;
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
static void F_43 ( struct V_47 * V_48 )
{
F_28 ( V_59 , & V_48 -> V_60 ) ;
F_44 () ;
F_45 ( & V_48 -> V_60 , V_59 ) ;
}
static inline void F_46 ( struct V_14 * V_15 , const int V_61 )
{
struct V_47 * V_48 , * V_62 ;
F_47 (gh, tmp, &gl->gl_holders, gh_list) {
if ( F_48 ( V_63 , & V_48 -> V_60 ) )
continue;
if ( V_61 & V_64 )
V_48 -> V_65 = - V_66 ;
else if ( V_48 -> V_54 & ( V_67 | V_68 ) )
V_48 -> V_65 = V_69 ;
else
continue;
F_22 ( & V_48 -> V_51 ) ;
F_49 ( V_48 , 0 ) ;
F_43 ( V_48 ) ;
}
}
static int F_50 ( struct V_14 * V_15 )
__releases( &gl->gl_spin
static inline struct V_47 * F_51 ( const struct V_14 * V_15 )
{
struct V_47 * V_48 ;
F_52 (gh, &gl->gl_holders, gh_list) {
if ( ! F_48 ( V_63 , & V_48 -> V_60 ) )
return V_48 ;
}
return NULL ;
}
static void F_53 ( struct V_14 * V_15 , unsigned int V_70 )
{
int V_71 , V_72 ;
V_71 = ( V_15 -> V_28 != V_29 ) ;
V_72 = ( V_70 != V_29 ) ;
if ( V_71 != V_72 ) {
if ( V_72 )
F_14 ( V_15 ) ;
else
F_31 ( V_15 ) ;
}
if ( V_71 && V_72 && F_19 ( & V_15 -> V_30 ) )
F_28 ( V_73 , & V_15 -> V_37 ) ;
if ( V_70 != V_15 -> V_74 )
V_15 -> V_75 = F_54 ( V_15 -> V_75 - V_76 ,
V_77 ) ;
V_15 -> V_28 = V_70 ;
V_15 -> V_78 = V_79 ;
}
static void F_55 ( struct V_14 * V_15 )
{
V_15 -> V_80 = V_53 ;
F_28 ( V_81 , & V_15 -> V_37 ) ;
F_44 () ;
F_45 ( & V_15 -> V_37 , V_81 ) ;
}
static void F_56 ( struct V_14 * V_15 , unsigned int V_61 )
{
const struct V_26 * V_27 = V_15 -> V_17 ;
struct V_47 * V_48 ;
unsigned V_82 = V_61 & V_83 ;
int V_84 ;
F_21 ( & V_15 -> V_85 ) ;
F_57 ( V_15 , V_82 ) ;
F_53 ( V_15 , V_82 ) ;
V_48 = F_51 ( V_15 ) ;
if ( F_48 ( V_86 , & V_15 -> V_37 ) &&
V_82 != V_29 && V_15 -> V_80 == V_29 )
V_15 -> V_74 = V_29 ;
if ( F_58 ( V_82 != V_15 -> V_74 ) ) {
if ( V_48 && ! F_48 ( V_86 , & V_15 -> V_37 ) ) {
if ( V_61 & V_87 ) {
if ( ( V_48 -> V_54 & V_88 ) == 0 )
F_59 ( & V_48 -> V_51 , & V_15 -> V_30 ) ;
V_48 = F_51 ( V_15 ) ;
V_15 -> V_74 = V_48 -> V_52 ;
goto V_89;
}
if ( ( V_61 & V_64 ) ||
( V_48 -> V_54 & ( V_67 | V_68 ) ) ) {
V_15 -> V_74 = V_15 -> V_28 ;
F_46 ( V_15 , V_61 ) ;
goto V_90;
}
}
switch( V_82 ) {
case V_29 :
V_89:
F_60 ( V_15 , V_48 , V_15 -> V_74 ) ;
break;
case V_56 :
case V_57 :
F_60 ( V_15 , V_48 , V_29 ) ;
break;
default:
F_61 ( V_91 L_1 , V_15 -> V_74 , V_82 ) ;
F_15 ( V_15 , 1 ) ;
}
F_25 ( & V_15 -> V_85 ) ;
return;
}
if ( F_62 ( V_86 , & V_15 -> V_37 ) )
F_55 ( V_15 ) ;
if ( V_82 != V_29 ) {
if ( V_27 -> V_92 ) {
F_25 ( & V_15 -> V_85 ) ;
V_84 = V_27 -> V_92 ( V_15 , V_48 ) ;
F_21 ( & V_15 -> V_85 ) ;
if ( V_84 ) {
F_46 ( V_15 , V_84 ) ;
goto V_90;
}
}
V_84 = F_50 ( V_15 ) ;
if ( V_84 == 2 )
goto V_93;
}
V_90:
F_28 ( V_94 , & V_15 -> V_37 ) ;
V_93:
F_25 ( & V_15 -> V_85 ) ;
}
static void F_60 ( struct V_14 * V_15 , struct V_47 * V_48 , unsigned int V_95 )
__releases( &gl->gl_spin
static inline struct V_47 * F_63 ( const struct V_14 * V_15 )
{
struct V_47 * V_48 ;
if ( ! F_19 ( & V_15 -> V_30 ) ) {
V_48 = F_42 ( V_15 -> V_30 . V_50 , struct V_47 , V_51 ) ;
if ( F_48 ( V_63 , & V_48 -> V_60 ) )
return V_48 ;
}
return NULL ;
}
static void F_64 ( struct V_14 * V_15 , const int V_96 )
__releases( &gl->gl_spin
static void F_65 ( struct V_97 * V_98 )
{
struct V_14 * V_15 = F_8 ( V_98 , struct V_14 , V_99 ) ;
struct V_1 * V_2 = V_15 -> V_22 ;
struct V_100 * V_101 ;
struct V_102 * V_102 ;
V_7 V_103 = V_15 -> V_46 . V_6 ;
V_101 = V_15 -> V_104 ;
if ( V_101 )
V_102 = F_66 ( V_2 -> V_105 , V_103 , 1 ) ;
else
V_102 = F_67 ( V_2 , V_103 , NULL , V_106 ) ;
if ( V_102 && ! F_68 ( V_102 ) ) {
F_69 ( V_102 ) ;
F_70 ( V_102 ) ;
}
F_32 ( V_15 ) ;
}
static void F_71 ( struct V_97 * V_98 )
{
unsigned long V_107 = 0 ;
struct V_14 * V_15 = F_8 ( V_98 , struct V_14 , V_108 . V_98 ) ;
int V_109 = 0 ;
if ( F_62 ( V_110 , & V_15 -> V_37 ) ) {
F_56 ( V_15 , V_15 -> V_111 ) ;
V_109 = 1 ;
}
F_21 ( & V_15 -> V_85 ) ;
if ( F_48 ( V_112 , & V_15 -> V_37 ) &&
V_15 -> V_28 != V_29 &&
V_15 -> V_80 != V_53 ) {
unsigned long V_113 , V_114 = V_79 ;
V_113 = V_15 -> V_78 + V_15 -> V_75 ;
if ( F_72 ( V_114 , V_113 ) )
V_107 = V_113 - V_114 ;
if ( ! V_107 ) {
F_28 ( V_112 , & V_15 -> V_37 ) ;
F_24 ( V_81 , & V_15 -> V_37 ) ;
}
}
F_64 ( V_15 , 0 ) ;
F_25 ( & V_15 -> V_85 ) ;
if ( ! V_107 )
F_32 ( V_15 ) ;
else {
if ( V_15 -> V_46 . V_8 != V_115 )
V_107 = 0 ;
if ( F_73 ( V_116 , & V_15 -> V_108 , V_107 ) == 0 )
F_32 ( V_15 ) ;
}
if ( V_109 )
F_32 ( V_15 ) ;
}
int F_74 ( struct V_1 * V_2 , V_7 V_117 ,
const struct V_26 * V_27 , int V_118 ,
struct V_14 * * V_119 )
{
struct V_120 * V_121 = V_2 -> V_105 ;
struct V_3 V_4 = { . V_6 = V_117 , . V_8 = V_27 -> V_122 } ;
struct V_14 * V_15 , * V_62 ;
unsigned int V_10 = F_1 ( V_2 , & V_4 ) ;
struct V_38 * V_39 ;
struct V_123 * V_124 ;
F_75 () ;
V_15 = F_37 ( V_10 , V_2 , & V_4 ) ;
F_76 () ;
* V_119 = V_15 ;
if ( V_15 )
return 0 ;
if ( ! V_118 )
return - V_125 ;
if ( V_27 -> V_18 & V_19 )
V_124 = V_20 ;
else
V_124 = V_21 ;
V_15 = F_77 ( V_124 , V_126 ) ;
if ( ! V_15 )
return - V_127 ;
F_17 ( & V_2 -> V_23 ) ;
V_15 -> V_37 = 0 ;
V_15 -> V_46 = V_4 ;
F_78 ( & V_15 -> V_25 , 1 ) ;
V_15 -> V_28 = V_29 ;
V_15 -> V_74 = V_29 ;
V_15 -> V_80 = V_53 ;
V_15 -> F_1 = V_10 ;
V_15 -> V_17 = V_27 ;
snprintf ( V_15 -> V_128 , V_129 , L_2 , V_4 . V_8 , ( unsigned long long ) V_117 ) ;
memset ( & V_15 -> V_130 , 0 , sizeof( struct V_131 ) ) ;
V_15 -> V_130 . V_132 = V_15 -> V_133 ;
V_15 -> V_78 = V_79 ;
V_15 -> V_104 = NULL ;
V_15 -> V_22 = V_2 ;
V_15 -> V_75 = V_134 ;
F_79 ( & V_15 -> V_108 , F_71 ) ;
F_80 ( & V_15 -> V_99 , F_65 ) ;
V_39 = F_33 ( V_15 ) ;
if ( V_39 ) {
V_39 -> V_135 = & V_136 ;
V_39 -> V_137 = V_121 -> V_138 -> V_139 ;
V_39 -> V_140 = 0 ;
F_81 ( V_39 , V_141 ) ;
V_39 -> V_142 = NULL ;
V_39 -> V_143 = V_121 -> V_144 ;
V_39 -> V_145 = 0 ;
}
F_3 ( V_10 ) ;
V_62 = F_37 ( V_10 , V_2 , & V_4 ) ;
if ( V_62 ) {
F_5 ( V_10 ) ;
F_9 ( V_124 , V_15 ) ;
F_27 ( & V_2 -> V_23 ) ;
V_15 = V_62 ;
} else {
F_82 ( & V_15 -> V_40 , & V_11 [ V_10 ] ) ;
F_5 ( V_10 ) ;
}
* V_119 = V_15 ;
return 0 ;
}
void F_83 ( struct V_14 * V_15 , unsigned int V_82 , unsigned V_140 ,
struct V_47 * V_48 )
{
F_84 ( & V_48 -> V_51 ) ;
V_48 -> V_146 = V_15 ;
V_48 -> V_147 = ( unsigned long ) F_85 ( 0 ) ;
V_48 -> V_148 = F_86 ( F_87 ( V_149 ) ) ;
V_48 -> V_52 = V_82 ;
V_48 -> V_54 = V_140 ;
V_48 -> V_65 = 0 ;
V_48 -> V_60 = 0 ;
F_14 ( V_15 ) ;
}
void F_88 ( unsigned int V_82 , unsigned V_140 , struct V_47 * V_48 )
{
V_48 -> V_52 = V_82 ;
V_48 -> V_54 = V_140 ;
V_48 -> V_60 = 0 ;
V_48 -> V_147 = ( unsigned long ) F_85 ( 0 ) ;
if ( V_48 -> V_148 )
F_89 ( V_48 -> V_148 ) ;
V_48 -> V_148 = F_86 ( F_87 ( V_149 ) ) ;
}
void F_90 ( struct V_47 * V_48 )
{
F_89 ( V_48 -> V_148 ) ;
F_32 ( V_48 -> V_146 ) ;
V_48 -> V_146 = NULL ;
V_48 -> V_147 = 0 ;
}
static int F_91 ( void * V_150 )
{
F_92 () ;
return 0 ;
}
static int F_93 ( void * V_150 )
{
F_92 () ;
return 0 ;
}
static void F_94 ( struct V_47 * V_48 )
{
unsigned long V_151 = V_79 ;
F_95 () ;
F_96 ( & V_48 -> V_60 , V_59 , F_91 , V_152 ) ;
if ( F_97 ( V_79 , V_151 + V_153 ) )
V_48 -> V_146 -> V_75 = F_98 ( V_48 -> V_146 -> V_75 +
V_154 ,
V_155 ) ;
}
static void F_99 ( struct V_14 * V_15 )
{
F_95 () ;
F_96 ( & V_15 -> V_37 , V_81 , F_93 , V_152 ) ;
}
static void F_100 ( struct V_14 * V_15 , unsigned int V_82 ,
unsigned long V_107 )
{
int V_156 = V_107 ? V_112 : V_81 ;
F_24 ( V_156 , & V_15 -> V_37 ) ;
if ( V_15 -> V_80 == V_53 ) {
V_15 -> V_80 = V_82 ;
V_15 -> V_157 = V_79 ;
} else if ( V_15 -> V_80 != V_29 &&
V_15 -> V_80 != V_82 ) {
V_15 -> V_80 = V_29 ;
}
if ( V_15 -> V_17 -> V_158 )
V_15 -> V_17 -> V_158 ( V_15 ) ;
F_101 ( V_15 ) ;
}
int F_102 ( struct V_47 * V_48 )
{
F_94 ( V_48 ) ;
return V_48 -> V_65 ;
}
void F_103 ( struct V_159 * V_160 , const char * V_161 , ... )
{
struct V_162 V_163 ;
T_1 args ;
va_start ( args , V_161 ) ;
if ( V_160 ) {
struct V_164 * V_165 = V_160 -> V_166 ;
vsprintf ( V_165 -> string , V_161 , args ) ;
F_104 ( V_160 , V_165 -> string ) ;
} else {
V_163 . V_161 = V_161 ;
V_163 . V_167 = & args ;
F_61 ( V_91 L_3 , & V_163 ) ;
}
va_end ( args ) ;
}
static inline void F_105 ( struct V_47 * V_48 )
__releases( &gl->gl_spin
int F_106 ( struct V_47 * V_48 )
{
struct V_14 * V_15 = V_48 -> V_146 ;
struct V_1 * V_2 = V_15 -> V_22 ;
int error = 0 ;
if ( F_58 ( F_48 ( V_168 , & V_2 -> V_169 ) ) )
return - V_66 ;
if ( F_48 ( V_36 , & V_15 -> V_37 ) )
F_29 ( V_15 ) ;
F_21 ( & V_15 -> V_85 ) ;
F_105 ( V_48 ) ;
if ( ( V_170 & V_48 -> V_54 ) &&
F_62 ( V_171 , & V_15 -> V_37 ) )
F_24 ( V_110 , & V_15 -> V_37 ) ;
F_64 ( V_15 , 1 ) ;
F_25 ( & V_15 -> V_85 ) ;
if ( ! ( V_48 -> V_54 & V_172 ) )
error = F_102 ( V_48 ) ;
return error ;
}
int F_107 ( struct V_47 * V_48 )
{
return F_48 ( V_59 , & V_48 -> V_60 ) ? 0 : 1 ;
}
void F_108 ( struct V_47 * V_48 )
{
struct V_14 * V_15 = V_48 -> V_146 ;
const struct V_26 * V_27 = V_15 -> V_17 ;
unsigned V_107 = 0 ;
int V_173 = 0 ;
F_21 ( & V_15 -> V_85 ) ;
if ( V_48 -> V_54 & V_174 )
F_100 ( V_15 , V_29 , 0 ) ;
F_22 ( & V_48 -> V_51 ) ;
if ( F_63 ( V_15 ) == NULL ) {
if ( V_27 -> V_175 ) {
F_15 ( V_15 , F_109 ( V_94 , & V_15 -> V_37 ) ) ;
F_25 ( & V_15 -> V_85 ) ;
V_27 -> V_175 ( V_48 ) ;
F_21 ( & V_15 -> V_85 ) ;
F_28 ( V_94 , & V_15 -> V_37 ) ;
}
if ( F_19 ( & V_15 -> V_30 ) &&
! F_48 ( V_112 , & V_15 -> V_37 ) &&
! F_48 ( V_81 , & V_15 -> V_37 ) )
V_173 = 1 ;
}
if ( ! F_48 ( V_176 , & V_15 -> V_37 ) )
F_30 ( V_15 ) ;
F_49 ( V_48 , 0 ) ;
F_25 ( & V_15 -> V_85 ) ;
if ( F_110 ( V_173 ) )
return;
F_14 ( V_15 ) ;
if ( F_48 ( V_112 , & V_15 -> V_37 ) &&
! F_48 ( V_81 , & V_15 -> V_37 ) &&
V_15 -> V_46 . V_8 == V_115 )
V_107 = V_15 -> V_75 ;
if ( F_73 ( V_116 , & V_15 -> V_108 , V_107 ) == 0 )
F_32 ( V_15 ) ;
}
void F_111 ( struct V_47 * V_48 )
{
struct V_14 * V_15 = V_48 -> V_146 ;
F_108 ( V_48 ) ;
F_99 ( V_15 ) ;
}
void F_112 ( struct V_47 * V_48 )
{
F_108 ( V_48 ) ;
F_90 ( V_48 ) ;
}
int F_113 ( struct V_1 * V_2 , V_7 V_117 ,
const struct V_26 * V_27 ,
unsigned int V_82 , int V_140 , struct V_47 * V_48 )
{
struct V_14 * V_15 ;
int error ;
error = F_74 ( V_2 , V_117 , V_27 , V_177 , & V_15 ) ;
if ( ! error ) {
error = F_114 ( V_15 , V_82 , V_140 , V_48 ) ;
F_32 ( V_15 ) ;
}
return error ;
}
static int F_115 ( const void * V_178 , const void * V_179 )
{
const struct V_47 * V_180 = * ( const struct V_47 * * ) V_178 ;
const struct V_47 * V_181 = * ( const struct V_47 * * ) V_179 ;
const struct V_3 * V_182 = & V_180 -> V_146 -> V_46 ;
const struct V_3 * V_183 = & V_181 -> V_146 -> V_46 ;
if ( V_182 -> V_6 > V_183 -> V_6 )
return 1 ;
if ( V_182 -> V_6 < V_183 -> V_6 )
return - 1 ;
F_116 ( V_180 -> V_146 -> V_17 -> V_122 == V_181 -> V_146 -> V_17 -> V_122 ) ;
return 0 ;
}
static int F_117 ( unsigned int V_184 , struct V_47 * V_185 ,
struct V_47 * * V_186 )
{
unsigned int V_187 ;
int error = 0 ;
for ( V_187 = 0 ; V_187 < V_184 ; V_187 ++ )
V_186 [ V_187 ] = & V_185 [ V_187 ] ;
F_118 ( V_186 , V_184 , sizeof( struct V_47 * ) , F_115 , NULL ) ;
for ( V_187 = 0 ; V_187 < V_184 ; V_187 ++ ) {
V_186 [ V_187 ] -> V_54 &= ~ ( V_67 | V_172 ) ;
error = F_106 ( V_186 [ V_187 ] ) ;
if ( error ) {
while ( V_187 -- )
F_108 ( V_186 [ V_187 ] ) ;
break;
}
}
return error ;
}
int F_119 ( unsigned int V_184 , struct V_47 * V_185 )
{
struct V_47 * V_62 [ 4 ] ;
struct V_47 * * V_188 = V_62 ;
int error = 0 ;
switch( V_184 ) {
case 0 :
return 0 ;
case 1 :
V_185 -> V_54 &= ~ ( V_67 | V_172 ) ;
return F_106 ( V_185 ) ;
default:
if ( V_184 <= 4 )
break;
V_188 = F_120 ( V_184 * sizeof( struct V_47 * ) , V_141 ) ;
if ( ! V_188 )
return - V_127 ;
}
error = F_117 ( V_184 , V_185 , V_188 ) ;
if ( V_188 != V_62 )
F_121 ( V_188 ) ;
return error ;
}
void F_122 ( unsigned int V_184 , struct V_47 * V_185 )
{
while ( V_184 -- )
F_108 ( & V_185 [ V_184 ] ) ;
}
void F_123 ( unsigned int V_184 , struct V_47 * V_185 )
{
while ( V_184 -- )
F_112 ( & V_185 [ V_184 ] ) ;
}
void F_124 ( struct V_14 * V_15 , unsigned int V_82 )
{
unsigned long V_107 = 0 ;
unsigned long V_113 ;
unsigned long V_114 = V_79 ;
F_14 ( V_15 ) ;
V_113 = V_15 -> V_78 + V_15 -> V_75 ;
if ( F_48 ( V_73 , & V_15 -> V_37 ) &&
V_15 -> V_46 . V_8 == V_115 ) {
if ( F_72 ( V_114 , V_113 ) )
V_107 = V_113 - V_114 ;
if ( F_48 ( V_110 , & V_15 -> V_37 ) )
V_107 = V_15 -> V_75 ;
}
F_21 ( & V_15 -> V_85 ) ;
F_100 ( V_15 , V_82 , V_107 ) ;
F_25 ( & V_15 -> V_85 ) ;
if ( F_73 ( V_116 , & V_15 -> V_108 , V_107 ) == 0 )
F_32 ( V_15 ) ;
}
static int F_125 ( const struct V_14 * V_15 )
{
const struct V_47 * V_48 ;
if ( V_15 -> V_111 & ~ V_83 )
return 0 ;
if ( V_15 -> V_74 == V_29 )
return 0 ;
F_52 (gh, &gl->gl_holders, gh_list) {
if ( F_48 ( V_63 , & V_48 -> V_60 ) )
continue;
if ( V_170 & V_48 -> V_54 )
return 0 ;
}
return 1 ;
}
void F_126 ( struct V_14 * V_15 , int V_61 )
{
struct V_189 * V_190 = & V_15 -> V_22 -> V_42 ;
F_21 ( & V_15 -> V_85 ) ;
V_15 -> V_111 = V_61 ;
if ( F_58 ( F_48 ( V_191 , & V_190 -> V_192 ) ) ) {
if ( F_125 ( V_15 ) ) {
F_24 ( V_171 , & V_15 -> V_37 ) ;
F_25 ( & V_15 -> V_85 ) ;
return;
}
}
F_25 ( & V_15 -> V_85 ) ;
F_24 ( V_110 , & V_15 -> V_37 ) ;
F_127 () ;
F_14 ( V_15 ) ;
if ( F_73 ( V_116 , & V_15 -> V_108 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
static int F_128 ( struct V_193 * V_194 ,
struct V_195 * V_196 )
{
struct V_14 * V_15 ;
int V_197 ;
int V_198 = 0 ;
int V_199 = V_196 -> V_200 ;
T_2 V_201 = V_196 -> V_201 ;
F_129 ( V_202 ) ;
if ( V_199 == 0 )
goto V_90;
if ( ! ( V_201 & V_203 ) )
return - 1 ;
F_21 ( & V_32 ) ;
while( V_199 && ! F_19 ( & V_35 ) ) {
V_15 = F_42 ( V_35 . V_50 , struct V_14 , V_33 ) ;
F_22 ( & V_15 -> V_33 ) ;
F_28 ( V_36 , & V_15 -> V_37 ) ;
F_27 ( & V_34 ) ;
if ( ! F_109 ( V_94 , & V_15 -> V_37 ) ) {
F_14 ( V_15 ) ;
F_25 ( & V_32 ) ;
F_21 ( & V_15 -> V_85 ) ;
V_197 = F_18 ( V_15 ) ;
if ( V_197 ) {
F_100 ( V_15 , V_29 , 0 ) ;
V_199 -- ;
}
F_28 ( V_94 , & V_15 -> V_37 ) ;
F_44 () ;
if ( F_73 ( V_116 , & V_15 -> V_108 , 0 ) == 0 )
F_31 ( V_15 ) ;
F_25 ( & V_15 -> V_85 ) ;
F_21 ( & V_32 ) ;
continue;
}
V_198 ++ ;
F_130 ( & V_15 -> V_33 , & V_202 ) ;
F_24 ( V_36 , & V_15 -> V_37 ) ;
}
F_131 ( & V_202 , & V_35 ) ;
F_132 ( V_198 , & V_34 ) ;
F_25 ( & V_32 ) ;
V_90:
return ( F_16 ( & V_34 ) / 100 ) * V_204 ;
}
static void F_133 ( T_3 V_205 , const struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_14 * V_15 ;
struct V_206 * V_207 = & V_11 [ V_10 ] ;
struct V_45 * V_208 ;
F_75 () ;
F_38 (gl, pos, head, gl_list) {
if ( ( V_15 -> V_22 == V_2 ) && F_16 ( & V_15 -> V_25 ) )
V_205 ( V_15 ) ;
}
F_76 () ;
F_134 () ;
}
static void F_135 ( T_3 V_205 , const struct V_1 * V_2 )
{
unsigned V_187 ;
for ( V_187 = 0 ; V_187 < V_209 ; V_187 ++ )
F_133 ( V_205 , V_2 , V_187 ) ;
}
static void F_136 ( struct V_14 * V_15 )
{
if ( ! F_62 ( V_171 , & V_15 -> V_37 ) )
return;
F_24 ( V_110 , & V_15 -> V_37 ) ;
F_14 ( V_15 ) ;
if ( F_73 ( V_116 , & V_15 -> V_108 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
static void F_137 ( struct V_14 * V_15 )
{
F_29 ( V_15 ) ;
F_21 ( & V_15 -> V_85 ) ;
if ( V_15 -> V_28 != V_29 )
F_100 ( V_15 , V_29 , 0 ) ;
F_25 ( & V_15 -> V_85 ) ;
F_14 ( V_15 ) ;
if ( F_73 ( V_116 , & V_15 -> V_108 , 0 ) == 0 )
F_32 ( V_15 ) ;
}
void F_138 ( struct V_1 * V_2 )
{
F_135 ( F_136 , V_2 ) ;
}
static int F_139 ( struct V_159 * V_160 , struct V_14 * V_15 )
{
int V_61 ;
F_21 ( & V_15 -> V_85 ) ;
V_61 = F_140 ( V_160 , V_15 ) ;
F_25 ( & V_15 -> V_85 ) ;
return V_61 ;
}
static void F_141 ( struct V_14 * V_15 )
{
F_139 ( NULL , V_15 ) ;
}
void F_142 ( struct V_1 * V_2 )
{
F_135 ( F_137 , V_2 ) ;
F_143 ( V_116 ) ;
F_144 ( V_2 -> V_24 , F_16 ( & V_2 -> V_23 ) == 0 ) ;
F_135 ( F_141 , V_2 ) ;
}
void F_145 ( struct V_100 * V_101 )
{
struct V_14 * V_15 = V_101 -> V_210 ;
int V_61 ;
V_61 = F_146 ( V_101 ) ;
F_147 ( V_15 -> V_22 , V_61 == 0 ) ;
F_21 ( & V_15 -> V_85 ) ;
F_28 ( V_94 , & V_15 -> V_37 ) ;
F_64 ( V_15 , 1 ) ;
F_25 ( & V_15 -> V_85 ) ;
}
static const char * F_148 ( unsigned V_82 )
{
switch( V_82 ) {
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
static const char * F_149 ( char * V_211 , unsigned V_140 , unsigned long V_212 )
{
char * V_186 = V_211 ;
if ( V_140 & V_67 )
* V_186 ++ = 't' ;
if ( V_140 & V_68 )
* V_186 ++ = 'T' ;
if ( V_140 & V_170 )
* V_186 ++ = 'e' ;
if ( V_140 & V_58 )
* V_186 ++ = 'A' ;
if ( V_140 & V_88 )
* V_186 ++ = 'p' ;
if ( V_140 & V_172 )
* V_186 ++ = 'a' ;
if ( V_140 & V_55 )
* V_186 ++ = 'E' ;
if ( V_140 & V_174 )
* V_186 ++ = 'c' ;
if ( F_48 ( V_63 , & V_212 ) )
* V_186 ++ = 'H' ;
if ( F_48 ( V_59 , & V_212 ) )
* V_186 ++ = 'W' ;
if ( F_48 ( V_213 , & V_212 ) )
* V_186 ++ = 'F' ;
* V_186 = 0 ;
return V_211 ;
}
static int F_150 ( struct V_159 * V_160 , const struct V_47 * V_48 )
{
struct V_214 * V_215 = NULL ;
char V_216 [ 32 ] ;
if ( V_48 -> V_148 )
V_215 = F_151 ( V_48 -> V_148 , V_217 ) ;
F_103 ( V_160 , L_9 ,
F_148 ( V_48 -> V_52 ) ,
F_149 ( V_216 , V_48 -> V_54 , V_48 -> V_60 ) ,
V_48 -> V_65 ,
V_48 -> V_148 ? ( long ) F_152 ( V_48 -> V_148 ) : - 1 ,
V_215 ? V_215 -> V_218 : L_10 ,
( void * ) V_48 -> V_147 ) ;
return 0 ;
}
static const char * F_153 ( char * V_211 , const struct V_14 * V_15 )
{
const unsigned long * V_219 = & V_15 -> V_37 ;
char * V_186 = V_211 ;
if ( F_48 ( V_94 , V_219 ) )
* V_186 ++ = 'l' ;
if ( F_48 ( V_81 , V_219 ) )
* V_186 ++ = 'D' ;
if ( F_48 ( V_112 , V_219 ) )
* V_186 ++ = 'd' ;
if ( F_48 ( V_86 , V_219 ) )
* V_186 ++ = 'p' ;
if ( F_48 ( V_220 , V_219 ) )
* V_186 ++ = 'y' ;
if ( F_48 ( V_176 , V_219 ) )
* V_186 ++ = 'f' ;
if ( F_48 ( V_221 , V_219 ) )
* V_186 ++ = 'i' ;
if ( F_48 ( V_110 , V_219 ) )
* V_186 ++ = 'r' ;
if ( F_48 ( V_222 , V_219 ) )
* V_186 ++ = 'I' ;
if ( F_48 ( V_171 , V_219 ) )
* V_186 ++ = 'F' ;
if ( F_48 ( V_73 , V_219 ) )
* V_186 ++ = 'q' ;
if ( F_48 ( V_36 , V_219 ) )
* V_186 ++ = 'L' ;
if ( V_15 -> V_104 )
* V_186 ++ = 'o' ;
* V_186 = 0 ;
return V_211 ;
}
static int F_140 ( struct V_159 * V_160 , const struct V_14 * V_15 )
{
const struct V_26 * V_27 = V_15 -> V_17 ;
unsigned long long V_223 ;
const struct V_47 * V_48 ;
char V_224 [ 32 ] ;
int error = 0 ;
V_223 = V_79 - V_15 -> V_157 ;
V_223 *= 1000000 / V_153 ;
if ( ! F_48 ( V_81 , & V_15 -> V_37 ) )
V_223 = 0 ;
F_103 ( V_160 , L_11 ,
F_148 ( V_15 -> V_28 ) ,
V_15 -> V_46 . V_8 ,
( unsigned long long ) V_15 -> V_46 . V_6 ,
F_153 ( V_224 , V_15 ) ,
F_148 ( V_15 -> V_74 ) ,
F_148 ( V_15 -> V_80 ) , V_223 ,
F_16 ( & V_15 -> V_225 ) ,
F_16 ( & V_15 -> V_226 ) ,
F_16 ( & V_15 -> V_25 ) , V_15 -> V_75 ) ;
F_52 (gh, &gl->gl_holders, gh_list) {
error = F_150 ( V_160 , V_48 ) ;
if ( error )
goto V_90;
}
if ( V_15 -> V_28 != V_29 && V_27 -> V_227 )
error = V_27 -> V_227 ( V_160 , V_15 ) ;
V_90:
return error ;
}
int T_4 F_154 ( void )
{
unsigned V_228 ;
for( V_228 = 0 ; V_228 < V_209 ; V_228 ++ ) {
F_155 ( & V_11 [ V_228 ] ) ;
}
V_116 = F_156 ( L_12 , V_229 |
V_230 | V_231 , 0 ) ;
if ( F_68 ( V_116 ) )
return F_157 ( V_116 ) ;
V_232 = F_156 ( L_13 ,
V_229 | V_231 ,
0 ) ;
if ( F_68 ( V_232 ) ) {
F_158 ( V_116 ) ;
return F_157 ( V_232 ) ;
}
F_159 ( & V_233 ) ;
return 0 ;
}
void F_160 ( void )
{
F_161 ( & V_233 ) ;
F_158 ( V_116 ) ;
F_158 ( V_232 ) ;
}
static inline struct V_14 * F_162 ( unsigned V_10 )
{
return F_163 ( F_164 ( & V_11 [ V_10 ] ) ,
struct V_14 , V_40 ) ;
}
static inline struct V_14 * F_165 ( struct V_14 * V_15 )
{
return F_163 ( F_166 ( V_15 -> V_40 . V_50 ) ,
struct V_14 , V_40 ) ;
}
static int F_167 ( struct V_164 * V_165 )
{
struct V_14 * V_15 ;
do {
V_15 = V_165 -> V_15 ;
if ( V_15 ) {
V_165 -> V_15 = F_165 ( V_15 ) ;
} else {
V_165 -> V_15 = F_162 ( V_165 -> V_10 ) ;
}
while ( V_165 -> V_15 == NULL ) {
V_165 -> V_10 ++ ;
if ( V_165 -> V_10 >= V_209 ) {
F_76 () ;
return 1 ;
}
V_165 -> V_15 = F_162 ( V_165 -> V_10 ) ;
}
} while ( V_165 -> V_2 != V_165 -> V_15 -> V_22 || F_16 ( & V_165 -> V_15 -> V_25 ) == 0 );
return 0 ;
}
static void * F_168 ( struct V_159 * V_160 , T_5 * V_208 )
{
struct V_164 * V_165 = V_160 -> V_166 ;
T_5 V_234 = * V_208 ;
V_165 -> V_10 = 0 ;
F_75 () ;
do {
if ( F_167 ( V_165 ) )
return NULL ;
} while ( V_234 -- );
return V_165 -> V_15 ;
}
static void * F_169 ( struct V_159 * V_160 , void * V_235 ,
T_5 * V_208 )
{
struct V_164 * V_165 = V_160 -> V_166 ;
( * V_208 ) ++ ;
if ( F_167 ( V_165 ) )
return NULL ;
return V_165 -> V_15 ;
}
static void F_170 ( struct V_159 * V_160 , void * V_235 )
{
struct V_164 * V_165 = V_160 -> V_166 ;
if ( V_165 -> V_15 )
F_76 () ;
V_165 -> V_15 = NULL ;
}
static int F_171 ( struct V_159 * V_160 , void * V_235 )
{
return F_139 ( V_160 , V_235 ) ;
}
static int F_172 ( struct V_102 * V_102 , struct V_236 * V_236 )
{
int V_61 = F_173 ( V_236 , & V_237 ,
sizeof( struct V_164 ) ) ;
if ( V_61 == 0 ) {
struct V_159 * V_160 = V_236 -> V_238 ;
struct V_164 * V_165 = V_160 -> V_166 ;
V_165 -> V_2 = V_102 -> V_239 ;
}
return V_61 ;
}
int F_174 ( struct V_1 * V_2 )
{
V_2 -> V_240 = F_175 ( V_2 -> V_241 , V_242 ) ;
if ( ! V_2 -> V_240 )
return - V_127 ;
V_2 -> V_243 = F_176 ( L_14 ,
V_244 | V_245 ,
V_2 -> V_240 , V_2 ,
& V_246 ) ;
if ( ! V_2 -> V_243 )
return - V_127 ;
return 0 ;
}
void F_177 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_240 ) {
if ( V_2 -> V_243 ) {
F_178 ( V_2 -> V_243 ) ;
V_2 -> V_243 = NULL ;
}
F_178 ( V_2 -> V_240 ) ;
V_2 -> V_240 = NULL ;
}
}
int F_179 ( void )
{
V_242 = F_175 ( L_15 , NULL ) ;
return V_242 ? 0 : - V_127 ;
}
void F_180 ( void )
{
F_178 ( V_242 ) ;
V_242 = NULL ;
}
