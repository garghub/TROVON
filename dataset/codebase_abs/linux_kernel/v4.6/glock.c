void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
if ( V_2 -> V_7 -> V_8 & V_9 ) {
F_2 ( V_10 , V_2 ) ;
} else {
F_3 ( V_2 -> V_11 . V_12 ) ;
F_2 ( V_13 , V_2 ) ;
}
if ( F_4 ( & V_4 -> V_14 ) )
F_5 ( & V_4 -> V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 , F_8 ( & V_2 -> V_16 ) ) ;
F_9 ( & V_2 -> V_16 ) ;
}
static int F_10 ( const struct V_1 * V_2 )
{
const struct V_17 * V_18 = V_2 -> V_7 ;
if ( V_2 -> V_19 == V_20 )
return 0 ;
if ( ! F_11 ( & V_2 -> V_21 ) )
return 0 ;
if ( V_18 -> V_22 )
return V_18 -> V_22 ( V_2 ) ;
return 1 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_23 ) ;
if ( ! F_11 ( & V_2 -> V_24 ) )
F_14 ( & V_2 -> V_24 ) ;
else
F_15 ( & V_25 ) ;
F_16 ( & V_2 -> V_24 , & V_26 ) ;
F_17 ( V_27 , & V_2 -> V_28 ) ;
F_18 ( & V_23 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_13 ( & V_23 ) ;
if ( ! F_11 ( & V_2 -> V_24 ) ) {
F_14 ( & V_2 -> V_24 ) ;
F_20 ( & V_25 ) ;
F_21 ( V_27 , & V_2 -> V_28 ) ;
}
F_18 ( & V_23 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_29 * V_30 = F_23 ( V_2 ) ;
if ( F_24 ( & V_2 -> V_16 ) )
return;
F_25 ( & V_2 -> V_16 ) ;
F_19 ( V_2 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
F_26 ( & V_32 , & V_2 -> V_33 , V_34 ) ;
F_7 ( V_2 , ! F_11 ( & V_2 -> V_21 ) ) ;
F_7 ( V_2 , V_30 && V_30 -> V_35 ) ;
F_27 ( V_2 ) ;
V_4 -> V_36 . V_37 -> V_38 ( V_2 ) ;
}
static inline int F_28 ( const struct V_1 * V_2 , const struct V_39 * V_40 )
{
const struct V_39 * V_41 = F_29 ( V_2 -> V_21 . V_42 , const struct V_39 , V_43 ) ;
if ( ( V_40 -> V_44 == V_45 ||
V_41 -> V_44 == V_45 ) && V_40 != V_41 )
return 0 ;
if ( V_2 -> V_19 == V_40 -> V_44 )
return 1 ;
if ( V_40 -> V_46 & V_47 )
return 0 ;
if ( V_2 -> V_19 == V_45 ) {
if ( V_40 -> V_44 == V_48 && V_41 -> V_44 == V_48 )
return 1 ;
if ( V_40 -> V_44 == V_49 && V_41 -> V_44 == V_49 )
return 1 ;
}
if ( V_2 -> V_19 != V_20 && ( V_40 -> V_46 & V_50 ) )
return 1 ;
return 0 ;
}
static void F_30 ( struct V_39 * V_40 )
{
F_21 ( V_51 , & V_40 -> V_52 ) ;
F_31 () ;
F_32 ( & V_40 -> V_52 , V_51 ) ;
}
static inline void F_33 ( struct V_1 * V_2 , const int V_53 )
{
struct V_39 * V_40 , * V_54 ;
F_34 (gh, tmp, &gl->gl_holders, gh_list) {
if ( F_35 ( V_55 , & V_40 -> V_52 ) )
continue;
if ( V_53 & V_56 )
V_40 -> V_57 = - V_58 ;
else if ( V_40 -> V_46 & ( V_59 | V_60 ) )
V_40 -> V_57 = V_61 ;
else
continue;
F_14 ( & V_40 -> V_43 ) ;
F_36 ( V_40 , 0 ) ;
F_30 ( V_40 ) ;
}
}
static int F_37 ( struct V_1 * V_2 )
__releases( &gl->gl_lockref.lock
static inline struct V_39 * F_38 ( const struct V_1 * V_2 )
{
struct V_39 * V_40 ;
F_39 (gh, &gl->gl_holders, gh_list) {
if ( ! F_35 ( V_55 , & V_40 -> V_52 ) )
return V_40 ;
}
return NULL ;
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_62 )
{
int V_63 , V_64 ;
V_63 = ( V_2 -> V_19 != V_20 ) ;
V_64 = ( V_62 != V_20 ) ;
if ( V_63 != V_64 ) {
F_7 ( V_2 , F_8 ( & V_2 -> V_16 ) ) ;
if ( V_64 )
V_2 -> V_16 . V_65 ++ ;
else
V_2 -> V_16 . V_65 -- ;
}
if ( V_63 && V_64 && F_11 ( & V_2 -> V_21 ) )
F_21 ( V_66 , & V_2 -> V_28 ) ;
if ( V_62 != V_2 -> V_67 )
V_2 -> V_68 = F_41 ( V_2 -> V_68 - V_69 ,
V_70 ) ;
V_2 -> V_19 = V_62 ;
V_2 -> V_71 = V_72 ;
}
static void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_73 = V_45 ;
F_21 ( V_74 , & V_2 -> V_28 ) ;
F_31 () ;
F_32 ( & V_2 -> V_28 , V_74 ) ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_53 )
{
const struct V_17 * V_18 = V_2 -> V_7 ;
struct V_39 * V_40 ;
unsigned V_75 = V_53 & V_76 ;
int V_77 ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_44 ( V_2 , V_75 ) ;
F_40 ( V_2 , V_75 ) ;
V_40 = F_38 ( V_2 ) ;
if ( F_35 ( V_78 , & V_2 -> V_28 ) &&
V_75 != V_20 && V_2 -> V_73 == V_20 )
V_2 -> V_67 = V_20 ;
if ( F_45 ( V_75 != V_2 -> V_67 ) ) {
if ( V_40 && ! F_35 ( V_78 , & V_2 -> V_28 ) ) {
if ( V_53 & V_79 ) {
if ( ( V_40 -> V_46 & V_80 ) == 0 )
F_46 ( & V_40 -> V_43 , & V_2 -> V_21 ) ;
V_40 = F_38 ( V_2 ) ;
V_2 -> V_67 = V_40 -> V_44 ;
goto V_81;
}
if ( ( V_53 & V_56 ) ||
( V_40 -> V_46 & ( V_59 | V_60 ) ) ) {
V_2 -> V_67 = V_2 -> V_19 ;
F_33 ( V_2 , V_53 ) ;
goto V_82;
}
}
switch( V_75 ) {
case V_20 :
V_81:
F_47 ( V_2 , V_40 , V_2 -> V_67 ) ;
break;
case V_48 :
case V_49 :
F_47 ( V_2 , V_40 , V_20 ) ;
break;
default:
F_48 ( L_1 , V_2 -> V_67 , V_75 ) ;
F_7 ( V_2 , 1 ) ;
}
F_18 ( & V_2 -> V_16 . V_31 ) ;
return;
}
if ( F_49 ( V_78 , & V_2 -> V_28 ) )
F_42 ( V_2 ) ;
if ( V_75 != V_20 ) {
if ( V_18 -> V_83 ) {
F_18 ( & V_2 -> V_16 . V_31 ) ;
V_77 = V_18 -> V_83 ( V_2 , V_40 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( V_77 ) {
F_33 ( V_2 , V_77 ) ;
goto V_82;
}
}
V_77 = F_37 ( V_2 ) ;
if ( V_77 == 2 )
goto V_84;
}
V_82:
F_21 ( V_85 , & V_2 -> V_28 ) ;
V_84:
F_18 ( & V_2 -> V_16 . V_31 ) ;
}
static void F_47 ( struct V_1 * V_2 , struct V_39 * V_40 , unsigned int V_86 )
__releases( &gl->gl_lockref.lock
static inline struct V_39 * F_50 ( const struct V_1 * V_2 )
{
struct V_39 * V_40 ;
if ( ! F_11 ( & V_2 -> V_21 ) ) {
V_40 = F_29 ( V_2 -> V_21 . V_42 , struct V_39 , V_43 ) ;
if ( F_35 ( V_55 , & V_40 -> V_52 ) )
return V_40 ;
}
return NULL ;
}
static void F_51 ( struct V_1 * V_2 , const int V_87 )
__releases( &gl->gl_lockref.lock
static void F_52 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_53 ( V_89 , struct V_1 , V_90 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_91 * V_92 ;
struct V_93 * V_93 ;
T_1 V_94 = V_2 -> V_5 . V_95 ;
if ( F_35 ( V_96 , & V_2 -> V_28 ) )
goto V_82;
V_92 = V_2 -> V_97 ;
if ( V_92 )
V_93 = F_54 ( V_4 -> V_98 , V_94 ) ;
else
V_93 = F_55 ( V_4 , V_94 , NULL , V_99 ) ;
if ( V_93 && ! F_56 ( V_93 ) ) {
F_57 ( V_93 ) ;
F_58 ( V_93 ) ;
}
V_82:
F_22 ( V_2 ) ;
}
static void F_59 ( struct V_88 * V_89 )
{
unsigned long V_100 = 0 ;
struct V_1 * V_2 = F_53 ( V_89 , struct V_1 , V_101 . V_89 ) ;
int V_102 = 0 ;
if ( F_49 ( V_103 , & V_2 -> V_28 ) ) {
F_43 ( V_2 , V_2 -> V_104 ) ;
V_102 = 1 ;
}
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( F_35 ( V_105 , & V_2 -> V_28 ) &&
V_2 -> V_19 != V_20 &&
V_2 -> V_73 != V_45 ) {
unsigned long V_106 , V_107 = V_72 ;
V_106 = V_2 -> V_71 + V_2 -> V_68 ;
if ( F_60 ( V_107 , V_106 ) )
V_100 = V_106 - V_107 ;
if ( ! V_100 ) {
F_21 ( V_105 , & V_2 -> V_28 ) ;
F_17 ( V_74 , & V_2 -> V_28 ) ;
}
}
F_51 ( V_2 , 0 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( ! V_100 )
F_22 ( V_2 ) ;
else {
if ( V_2 -> V_5 . V_108 != V_109 )
V_100 = 0 ;
if ( F_61 ( V_110 , & V_2 -> V_101 , V_100 ) == 0 )
F_22 ( V_2 ) ;
}
if ( V_102 )
F_22 ( V_2 ) ;
}
int F_62 ( struct V_3 * V_4 , T_1 V_111 ,
const struct V_17 * V_18 , int V_112 ,
struct V_1 * * V_113 )
{
struct V_114 * V_115 = V_4 -> V_98 ;
struct V_116 V_117 = { . V_95 = V_111 ,
. V_108 = V_18 -> V_118 ,
. V_6 = V_4 } ;
struct V_1 * V_2 , * V_54 = NULL ;
struct V_29 * V_30 ;
struct V_119 * V_120 ;
int V_53 , V_121 = 0 ;
V_2 = F_63 ( & V_32 , & V_117 , V_34 ) ;
if ( V_2 && ! F_64 ( & V_2 -> V_16 ) )
V_2 = NULL ;
* V_113 = V_2 ;
if ( V_2 )
return 0 ;
if ( ! V_112 )
return - V_122 ;
if ( V_18 -> V_8 & V_9 )
V_120 = V_10 ;
else
V_120 = V_13 ;
V_2 = F_65 ( V_120 , V_123 ) ;
if ( ! V_2 )
return - V_124 ;
memset ( & V_2 -> V_11 , 0 , sizeof( struct V_125 ) ) ;
if ( V_18 -> V_8 & V_126 ) {
V_2 -> V_11 . V_12 = F_66 ( V_127 , V_123 ) ;
if ( ! V_2 -> V_11 . V_12 ) {
F_2 ( V_120 , V_2 ) ;
return - V_124 ;
}
}
F_15 ( & V_4 -> V_14 ) ;
V_2 -> V_33 . V_42 = NULL ;
V_2 -> V_28 = 0 ;
V_2 -> V_5 = V_117 ;
V_2 -> V_16 . V_65 = 1 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_67 = V_20 ;
V_2 -> V_73 = V_45 ;
V_2 -> V_7 = V_18 ;
V_2 -> V_128 = F_67 ( 0 , 0 ) ;
F_68 () ;
V_2 -> V_129 = F_69 ( V_4 -> V_130 ) -> V_131 [ V_18 -> V_118 ] ;
F_70 () ;
V_2 -> V_129 . V_132 [ V_133 ] = 0 ;
V_2 -> V_129 . V_132 [ V_134 ] = 0 ;
V_2 -> V_71 = V_72 ;
V_2 -> V_97 = NULL ;
V_2 -> V_68 = V_135 ;
F_71 ( & V_2 -> V_101 , F_59 ) ;
F_72 ( & V_2 -> V_90 , F_52 ) ;
V_30 = F_23 ( V_2 ) ;
if ( V_30 ) {
V_30 -> V_136 = & V_137 ;
V_30 -> V_138 = V_115 -> V_139 -> V_140 ;
V_30 -> V_141 = 0 ;
F_73 ( V_30 , V_123 ) ;
V_30 -> V_142 = NULL ;
V_30 -> V_143 = 0 ;
}
V_144:
V_53 = F_74 ( & V_32 , & V_2 -> V_33 ,
V_34 ) ;
if ( V_53 == 0 ) {
* V_113 = V_2 ;
return 0 ;
}
if ( V_53 == - V_145 ) {
V_53 = 0 ;
V_54 = F_63 ( & V_32 , & V_117 , V_34 ) ;
if ( V_54 == NULL || ! F_64 ( & V_54 -> V_16 ) ) {
if ( ++ V_121 < 100 ) {
F_75 () ;
goto V_144;
}
V_54 = NULL ;
V_53 = - V_124 ;
}
} else {
F_76 ( V_53 ) ;
}
F_3 ( V_2 -> V_11 . V_12 ) ;
F_2 ( V_120 , V_2 ) ;
F_20 ( & V_4 -> V_14 ) ;
* V_113 = V_54 ;
return V_53 ;
}
void F_77 ( struct V_1 * V_2 , unsigned int V_75 , T_2 V_141 ,
struct V_39 * V_40 )
{
F_78 ( & V_40 -> V_43 ) ;
V_40 -> V_146 = V_2 ;
V_40 -> V_147 = V_148 ;
V_40 -> V_149 = F_79 ( F_80 ( V_150 ) ) ;
V_40 -> V_44 = V_75 ;
V_40 -> V_46 = V_141 ;
V_40 -> V_57 = 0 ;
V_40 -> V_52 = 0 ;
F_6 ( V_2 ) ;
}
void F_81 ( unsigned int V_75 , T_2 V_141 , struct V_39 * V_40 )
{
V_40 -> V_44 = V_75 ;
V_40 -> V_46 = V_141 ;
V_40 -> V_52 = 0 ;
V_40 -> V_147 = V_148 ;
F_82 ( V_40 -> V_149 ) ;
V_40 -> V_149 = F_79 ( F_80 ( V_150 ) ) ;
}
void F_83 ( struct V_39 * V_40 )
{
F_82 ( V_40 -> V_149 ) ;
F_22 ( V_40 -> V_146 ) ;
V_40 -> V_146 = NULL ;
V_40 -> V_147 = 0 ;
}
int F_84 ( struct V_39 * V_40 )
{
unsigned long V_151 = V_72 ;
F_85 () ;
F_86 ( & V_40 -> V_52 , V_51 , V_152 ) ;
if ( F_87 ( V_72 , V_151 + V_153 ) )
V_40 -> V_146 -> V_68 = F_88 ( V_40 -> V_146 -> V_68 +
V_154 ,
V_155 ) ;
return V_40 -> V_57 ;
}
static void F_89 ( struct V_1 * V_2 , unsigned int V_75 ,
unsigned long V_100 , bool V_156 )
{
int V_157 = V_100 ? V_105 : V_74 ;
F_17 ( V_157 , & V_2 -> V_28 ) ;
if ( V_2 -> V_73 == V_45 ) {
V_2 -> V_73 = V_75 ;
V_2 -> V_158 = V_72 ;
} else if ( V_2 -> V_73 != V_20 &&
V_2 -> V_73 != V_75 ) {
V_2 -> V_73 = V_20 ;
}
if ( V_2 -> V_7 -> V_159 )
V_2 -> V_7 -> V_159 ( V_2 , V_156 ) ;
F_90 ( V_2 , V_156 ) ;
}
void F_91 ( struct V_160 * V_161 , const char * V_162 , ... )
{
struct V_163 V_164 ;
T_3 args ;
va_start ( args , V_162 ) ;
if ( V_161 ) {
F_92 ( V_161 , V_162 , args ) ;
} else {
V_164 . V_162 = V_162 ;
V_164 . V_165 = & args ;
F_48 ( L_2 , & V_164 ) ;
}
va_end ( args ) ;
}
static inline void F_93 ( struct V_39 * V_40 )
__releases( &gl->gl_lockref.lock
int F_94 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_146 ;
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
int error = 0 ;
if ( F_45 ( F_35 ( V_166 , & V_4 -> V_167 ) ) )
return - V_58 ;
if ( F_35 ( V_27 , & V_2 -> V_28 ) )
F_19 ( V_2 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_93 ( V_40 ) ;
if ( F_45 ( ( V_168 & V_40 -> V_46 ) &&
F_49 ( V_169 , & V_2 -> V_28 ) ) ) {
F_17 ( V_103 , & V_2 -> V_28 ) ;
V_2 -> V_16 . V_65 ++ ;
if ( F_61 ( V_110 , & V_2 -> V_101 , 0 ) == 0 )
V_2 -> V_16 . V_65 -- ;
}
F_51 ( V_2 , 1 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( ! ( V_40 -> V_46 & V_170 ) )
error = F_84 ( V_40 ) ;
return error ;
}
int F_95 ( struct V_39 * V_40 )
{
return F_35 ( V_51 , & V_40 -> V_52 ) ? 0 : 1 ;
}
void F_96 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_146 ;
const struct V_17 * V_18 = V_2 -> V_7 ;
unsigned V_100 = 0 ;
int V_171 = 0 ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( V_40 -> V_46 & V_172 )
F_89 ( V_2 , V_20 , 0 , false ) ;
F_14 ( & V_40 -> V_43 ) ;
F_21 ( V_55 , & V_40 -> V_52 ) ;
if ( F_50 ( V_2 ) == NULL ) {
if ( V_18 -> V_173 ) {
F_7 ( V_2 , F_97 ( V_85 , & V_2 -> V_28 ) ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
V_18 -> V_173 ( V_40 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_21 ( V_85 , & V_2 -> V_28 ) ;
}
if ( F_11 ( & V_2 -> V_21 ) &&
! F_35 ( V_105 , & V_2 -> V_28 ) &&
! F_35 ( V_74 , & V_2 -> V_28 ) )
V_171 = 1 ;
}
if ( ! F_35 ( V_174 , & V_2 -> V_28 ) && F_10 ( V_2 ) &&
( V_18 -> V_8 & V_175 ) )
F_12 ( V_2 ) ;
F_36 ( V_40 , 0 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_98 ( V_171 ) )
return;
F_6 ( V_2 ) ;
if ( F_35 ( V_105 , & V_2 -> V_28 ) &&
! F_35 ( V_74 , & V_2 -> V_28 ) &&
V_2 -> V_5 . V_108 == V_109 )
V_100 = V_2 -> V_68 ;
if ( F_61 ( V_110 , & V_2 -> V_101 , V_100 ) == 0 )
F_22 ( V_2 ) ;
}
void F_99 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_146 ;
F_96 ( V_40 ) ;
F_85 () ;
F_86 ( & V_2 -> V_28 , V_74 , V_152 ) ;
}
void F_100 ( struct V_39 * V_40 )
{
F_96 ( V_40 ) ;
F_83 ( V_40 ) ;
}
int F_101 ( struct V_3 * V_4 , T_1 V_111 ,
const struct V_17 * V_18 ,
unsigned int V_75 , T_2 V_141 , struct V_39 * V_40 )
{
struct V_1 * V_2 ;
int error ;
error = F_62 ( V_4 , V_111 , V_18 , V_176 , & V_2 ) ;
if ( ! error ) {
error = F_102 ( V_2 , V_75 , V_141 , V_40 ) ;
F_22 ( V_2 ) ;
}
return error ;
}
static int F_103 ( const void * V_177 , const void * V_178 )
{
const struct V_39 * V_179 = * ( const struct V_39 * * ) V_177 ;
const struct V_39 * V_180 = * ( const struct V_39 * * ) V_178 ;
const struct V_116 * V_181 = & V_179 -> V_146 -> V_5 ;
const struct V_116 * V_182 = & V_180 -> V_146 -> V_5 ;
if ( V_181 -> V_95 > V_182 -> V_95 )
return 1 ;
if ( V_181 -> V_95 < V_182 -> V_95 )
return - 1 ;
F_104 ( V_179 -> V_146 -> V_7 -> V_118 == V_180 -> V_146 -> V_7 -> V_118 ) ;
return 0 ;
}
static int F_105 ( unsigned int V_183 , struct V_39 * V_184 ,
struct V_39 * * V_185 )
{
unsigned int V_186 ;
int error = 0 ;
for ( V_186 = 0 ; V_186 < V_183 ; V_186 ++ )
V_185 [ V_186 ] = & V_184 [ V_186 ] ;
F_106 ( V_185 , V_183 , sizeof( struct V_39 * ) , F_103 , NULL ) ;
for ( V_186 = 0 ; V_186 < V_183 ; V_186 ++ ) {
V_185 [ V_186 ] -> V_46 &= ~ ( V_59 | V_170 ) ;
error = F_94 ( V_185 [ V_186 ] ) ;
if ( error ) {
while ( V_186 -- )
F_96 ( V_185 [ V_186 ] ) ;
break;
}
}
return error ;
}
int F_107 ( unsigned int V_183 , struct V_39 * V_184 )
{
struct V_39 * V_54 [ 4 ] ;
struct V_39 * * V_187 = V_54 ;
int error = 0 ;
switch( V_183 ) {
case 0 :
return 0 ;
case 1 :
V_184 -> V_46 &= ~ ( V_59 | V_170 ) ;
return F_94 ( V_184 ) ;
default:
if ( V_183 <= 4 )
break;
V_187 = F_108 ( V_183 * sizeof( struct V_39 * ) , V_123 ) ;
if ( ! V_187 )
return - V_124 ;
}
error = F_105 ( V_183 , V_184 , V_187 ) ;
if ( V_187 != V_54 )
F_3 ( V_187 ) ;
return error ;
}
void F_109 ( unsigned int V_183 , struct V_39 * V_184 )
{
while ( V_183 -- )
F_96 ( & V_184 [ V_183 ] ) ;
}
void F_110 ( struct V_1 * V_2 , unsigned int V_75 )
{
unsigned long V_100 = 0 ;
unsigned long V_106 ;
unsigned long V_107 = V_72 ;
F_6 ( V_2 ) ;
V_106 = V_2 -> V_71 + V_2 -> V_68 ;
if ( F_35 ( V_66 , & V_2 -> V_28 ) &&
V_2 -> V_5 . V_108 == V_109 ) {
if ( F_60 ( V_107 , V_106 ) )
V_100 = V_106 - V_107 ;
if ( F_35 ( V_103 , & V_2 -> V_28 ) )
V_100 = V_2 -> V_68 ;
}
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_89 ( V_2 , V_75 , V_100 , true ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_61 ( V_110 , & V_2 -> V_101 , V_100 ) == 0 )
F_22 ( V_2 ) ;
}
static int F_111 ( const struct V_1 * V_2 )
{
const struct V_39 * V_40 ;
if ( V_2 -> V_104 & ~ V_76 )
return 0 ;
if ( V_2 -> V_67 == V_20 )
return 0 ;
F_39 (gh, &gl->gl_holders, gh_list) {
if ( F_35 ( V_55 , & V_40 -> V_52 ) )
continue;
if ( V_168 & V_40 -> V_46 )
return 0 ;
}
return 1 ;
}
void F_112 ( struct V_1 * V_2 , int V_53 )
{
struct V_188 * V_189 = & V_2 -> V_5 . V_6 -> V_36 ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
V_2 -> V_104 = V_53 ;
if ( F_45 ( F_35 ( V_190 , & V_189 -> V_191 ) ) ) {
if ( F_111 ( V_2 ) ) {
F_17 ( V_169 , & V_2 -> V_28 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
return;
}
}
V_2 -> V_16 . V_65 ++ ;
F_17 ( V_103 , & V_2 -> V_28 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_61 ( V_110 , & V_2 -> V_101 , 0 ) == 0 )
F_22 ( V_2 ) ;
}
static int F_113 ( void * V_192 , struct V_193 * V_181 , struct V_193 * V_182 )
{
struct V_1 * V_194 , * V_195 ;
V_194 = F_29 ( V_181 , struct V_1 , V_24 ) ;
V_195 = F_29 ( V_182 , struct V_1 , V_24 ) ;
if ( V_194 -> V_5 . V_95 > V_195 -> V_5 . V_95 )
return 1 ;
if ( V_194 -> V_5 . V_95 < V_195 -> V_5 . V_95 )
return - 1 ;
return 0 ;
}
static void F_114 ( struct V_193 * V_196 )
__releases( &lru_lock
static long F_115 ( int V_197 )
{
struct V_1 * V_2 ;
F_116 ( V_198 ) ;
F_116 ( V_199 ) ;
long V_200 = 0 ;
F_13 ( & V_23 ) ;
while ( ( V_197 -- >= 0 ) && ! F_11 ( & V_26 ) ) {
V_2 = F_29 ( V_26 . V_42 , struct V_1 , V_24 ) ;
if ( ! F_35 ( V_85 , & V_2 -> V_28 ) ) {
F_117 ( & V_2 -> V_24 , & V_199 ) ;
F_20 ( & V_25 ) ;
V_200 ++ ;
continue;
}
F_117 ( & V_2 -> V_24 , & V_198 ) ;
}
F_118 ( & V_198 , & V_26 ) ;
if ( ! F_11 ( & V_199 ) )
F_114 ( & V_199 ) ;
F_18 ( & V_23 ) ;
return V_200 ;
}
static unsigned long F_119 ( struct V_201 * V_202 ,
struct V_203 * V_204 )
{
if ( ! ( V_204 -> V_205 & V_206 ) )
return V_207 ;
return F_115 ( V_204 -> V_208 ) ;
}
static unsigned long F_120 ( struct V_201 * V_202 ,
struct V_203 * V_204 )
{
return F_121 ( F_122 ( & V_25 ) ) ;
}
static void F_123 ( T_4 V_209 , const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_210 * V_211 ;
const struct V_212 * V_213 ;
int V_214 ;
F_124 () ;
V_213 = F_125 ( V_32 . V_213 , & V_32 ) ;
for ( V_214 = 0 ; V_214 < V_213 -> V_215 ; V_214 ++ ) {
F_126 (gl, pos, tbl, i, gl_node) {
if ( ( V_2 -> V_5 . V_6 == V_4 ) &&
F_64 ( & V_2 -> V_16 ) )
V_209 ( V_2 ) ;
}
}
F_127 () ;
F_75 () ;
}
static void F_128 ( struct V_1 * V_2 )
{
if ( ! F_49 ( V_169 , & V_2 -> V_28 ) )
goto V_82;
F_17 ( V_103 , & V_2 -> V_28 ) ;
if ( F_61 ( V_110 , & V_2 -> V_101 , 0 ) == 0 ) {
V_82:
F_22 ( V_2 ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
if ( V_2 -> V_19 != V_20 )
F_89 ( V_2 , V_20 , 0 , false ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
if ( F_61 ( V_110 , & V_2 -> V_101 , 0 ) == 0 )
F_22 ( V_2 ) ;
}
void F_130 ( struct V_3 * V_4 )
{
F_123 ( F_128 , V_4 ) ;
}
static void F_131 ( struct V_160 * V_161 , struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_132 ( V_161 , V_2 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
F_131 ( NULL , V_2 ) ;
}
void F_134 ( struct V_3 * V_4 )
{
F_17 ( V_216 , & V_4 -> V_167 ) ;
F_135 ( V_110 ) ;
F_123 ( F_129 , V_4 ) ;
F_135 ( V_110 ) ;
F_136 ( V_4 -> V_15 ,
F_122 ( & V_4 -> V_14 ) == 0 ,
V_153 * 600 ) ;
F_123 ( F_133 , V_4 ) ;
}
void F_137 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = V_92 -> V_217 ;
int V_53 ;
V_53 = F_138 ( V_92 ) ;
F_139 ( V_2 -> V_5 . V_6 , V_53 == 0 ) ;
F_13 ( & V_2 -> V_16 . V_31 ) ;
F_21 ( V_85 , & V_2 -> V_28 ) ;
F_51 ( V_2 , 1 ) ;
F_18 ( & V_2 -> V_16 . V_31 ) ;
}
static const char * F_140 ( unsigned V_75 )
{
switch( V_75 ) {
case V_20 :
return L_3 ;
case V_48 :
return L_4 ;
case V_49 :
return L_5 ;
case V_45 :
return L_6 ;
}
return L_7 ;
}
static const char * F_141 ( char * V_218 , T_2 V_141 , unsigned long V_219 )
{
char * V_185 = V_218 ;
if ( V_141 & V_59 )
* V_185 ++ = 't' ;
if ( V_141 & V_60 )
* V_185 ++ = 'T' ;
if ( V_141 & V_168 )
* V_185 ++ = 'e' ;
if ( V_141 & V_50 )
* V_185 ++ = 'A' ;
if ( V_141 & V_80 )
* V_185 ++ = 'p' ;
if ( V_141 & V_170 )
* V_185 ++ = 'a' ;
if ( V_141 & V_47 )
* V_185 ++ = 'E' ;
if ( V_141 & V_172 )
* V_185 ++ = 'c' ;
if ( F_35 ( V_55 , & V_219 ) )
* V_185 ++ = 'H' ;
if ( F_35 ( V_51 , & V_219 ) )
* V_185 ++ = 'W' ;
if ( F_35 ( V_220 , & V_219 ) )
* V_185 ++ = 'F' ;
* V_185 = 0 ;
return V_218 ;
}
static void F_142 ( struct V_160 * V_161 , const struct V_39 * V_40 )
{
struct V_221 * V_222 = NULL ;
char V_223 [ 32 ] ;
F_124 () ;
if ( V_40 -> V_149 )
V_222 = F_143 ( V_40 -> V_149 , V_224 ) ;
F_91 ( V_161 , L_8 ,
F_140 ( V_40 -> V_44 ) ,
F_141 ( V_223 , V_40 -> V_46 , V_40 -> V_52 ) ,
V_40 -> V_57 ,
V_40 -> V_149 ? ( long ) F_144 ( V_40 -> V_149 ) : - 1 ,
V_222 ? V_222 -> V_225 : L_9 ,
( void * ) V_40 -> V_147 ) ;
F_127 () ;
}
static const char * F_145 ( char * V_218 , const struct V_1 * V_2 )
{
const unsigned long * V_226 = & V_2 -> V_28 ;
char * V_185 = V_218 ;
if ( F_35 ( V_85 , V_226 ) )
* V_185 ++ = 'l' ;
if ( F_35 ( V_74 , V_226 ) )
* V_185 ++ = 'D' ;
if ( F_35 ( V_105 , V_226 ) )
* V_185 ++ = 'd' ;
if ( F_35 ( V_78 , V_226 ) )
* V_185 ++ = 'p' ;
if ( F_35 ( V_227 , V_226 ) )
* V_185 ++ = 'y' ;
if ( F_35 ( V_174 , V_226 ) )
* V_185 ++ = 'f' ;
if ( F_35 ( V_228 , V_226 ) )
* V_185 ++ = 'i' ;
if ( F_35 ( V_103 , V_226 ) )
* V_185 ++ = 'r' ;
if ( F_35 ( V_229 , V_226 ) )
* V_185 ++ = 'I' ;
if ( F_35 ( V_169 , V_226 ) )
* V_185 ++ = 'F' ;
if ( F_35 ( V_66 , V_226 ) )
* V_185 ++ = 'q' ;
if ( F_35 ( V_27 , V_226 ) )
* V_185 ++ = 'L' ;
if ( V_2 -> V_97 )
* V_185 ++ = 'o' ;
if ( F_35 ( V_230 , V_226 ) )
* V_185 ++ = 'b' ;
* V_185 = 0 ;
return V_218 ;
}
void F_132 ( struct V_160 * V_161 , const struct V_1 * V_2 )
{
const struct V_17 * V_18 = V_2 -> V_7 ;
unsigned long long V_231 ;
const struct V_39 * V_40 ;
char V_232 [ 32 ] ;
V_231 = V_72 - V_2 -> V_158 ;
V_231 *= 1000000 / V_153 ;
if ( ! F_35 ( V_74 , & V_2 -> V_28 ) )
V_231 = 0 ;
F_91 ( V_161 , L_10 ,
F_140 ( V_2 -> V_19 ) ,
V_2 -> V_5 . V_108 ,
( unsigned long long ) V_2 -> V_5 . V_95 ,
F_145 ( V_232 , V_2 ) ,
F_140 ( V_2 -> V_67 ) ,
F_140 ( V_2 -> V_73 ) , V_231 ,
F_122 ( & V_2 -> V_233 ) ,
F_122 ( & V_2 -> V_234 ) ,
( int ) V_2 -> V_16 . V_65 , V_2 -> V_68 ) ;
F_39 (gh, &gl->gl_holders, gh_list)
F_142 ( V_161 , V_40 ) ;
if ( V_2 -> V_19 != V_20 && V_18 -> V_235 )
V_18 -> V_235 ( V_161 , V_2 ) ;
}
static int F_146 ( struct V_160 * V_161 , void * V_236 )
{
struct V_1 * V_2 = V_236 ;
F_147 ( V_161 , L_11 ,
V_2 -> V_5 . V_108 ,
( unsigned long long ) V_2 -> V_5 . V_95 ,
( unsigned long long ) V_2 -> V_129 . V_132 [ V_237 ] ,
( unsigned long long ) V_2 -> V_129 . V_132 [ V_238 ] ,
( unsigned long long ) V_2 -> V_129 . V_132 [ V_239 ] ,
( unsigned long long ) V_2 -> V_129 . V_132 [ V_240 ] ,
( unsigned long long ) V_2 -> V_129 . V_132 [ V_241 ] ,
( unsigned long long ) V_2 -> V_129 . V_132 [ V_242 ] ,
( unsigned long long ) V_2 -> V_129 . V_132 [ V_133 ] ,
( unsigned long long ) V_2 -> V_129 . V_132 [ V_134 ] ) ;
return 0 ;
}
static int F_148 ( struct V_160 * V_161 , void * V_236 )
{
struct V_3 * V_4 = V_161 -> V_243 ;
T_5 V_211 = * ( T_5 * ) V_236 ;
unsigned V_244 = V_211 >> 3 ;
unsigned V_245 = V_211 & 0x07 ;
int V_214 ;
if ( V_244 == 0 && V_245 != 0 )
return 0 ;
F_147 ( V_161 , L_12 , V_246 [ V_244 ] ,
( V_244 == 0 ) ? L_13 : V_247 [ V_245 ] ) ;
F_149 (i) {
const struct V_248 * V_131 = F_150 ( V_4 -> V_130 , V_214 ) ;
if ( V_244 == 0 )
F_147 ( V_161 , L_14 , V_214 ) ;
else
F_147 ( V_161 , L_15 , ( unsigned long long ) V_131 ->
V_131 [ V_244 - 1 ] . V_132 [ V_245 ] ) ;
}
F_151 ( V_161 , '\n' ) ;
return 0 ;
}
int T_6 F_152 ( void )
{
int V_53 ;
V_53 = F_153 ( & V_32 , & V_34 ) ;
if ( V_53 < 0 )
return V_53 ;
V_110 = F_154 ( L_16 , V_249 |
V_250 | V_251 , 0 ) ;
if ( ! V_110 ) {
F_155 ( & V_32 ) ;
return - V_124 ;
}
V_252 = F_154 ( L_17 ,
V_249 | V_251 ,
0 ) ;
if ( ! V_252 ) {
F_156 ( V_110 ) ;
F_155 ( & V_32 ) ;
return - V_124 ;
}
F_157 ( & V_253 ) ;
return 0 ;
}
void F_158 ( void )
{
F_159 ( & V_253 ) ;
F_155 ( & V_32 ) ;
F_156 ( V_110 ) ;
F_156 ( V_252 ) ;
}
static void F_160 ( struct V_254 * V_255 )
{
do {
V_255 -> V_2 = F_161 ( & V_255 -> V_256 ) ;
if ( F_56 ( V_255 -> V_2 ) ) {
if ( F_162 ( V_255 -> V_2 ) == - V_257 )
continue;
V_255 -> V_2 = NULL ;
}
} while ( ( V_255 -> V_2 ) && ( ( V_255 -> V_4 != V_255 -> V_2 -> V_5 . V_6 ) ||
F_8 ( & V_255 -> V_2 -> V_16 ) ) );
}
static void * F_163 ( struct V_160 * V_161 , T_5 * V_211 )
{
struct V_254 * V_255 = V_161 -> V_243 ;
T_5 V_258 = * V_211 ;
int V_53 ;
if ( V_255 -> V_259 <= * V_211 )
V_258 = ( * V_211 - V_255 -> V_259 ) ;
V_53 = F_164 ( & V_255 -> V_256 ) ;
if ( V_53 )
return NULL ;
do {
F_160 ( V_255 ) ;
} while ( V_255 -> V_2 && V_258 -- );
V_255 -> V_259 = * V_211 ;
return V_255 -> V_2 ;
}
static void * F_165 ( struct V_160 * V_161 , void * V_236 ,
T_5 * V_211 )
{
struct V_254 * V_255 = V_161 -> V_243 ;
( * V_211 ) ++ ;
V_255 -> V_259 = * V_211 ;
F_160 ( V_255 ) ;
return V_255 -> V_2 ;
}
static void F_166 ( struct V_160 * V_161 , void * V_236 )
{
struct V_254 * V_255 = V_161 -> V_243 ;
V_255 -> V_2 = NULL ;
F_167 ( & V_255 -> V_256 ) ;
}
static int F_168 ( struct V_160 * V_161 , void * V_236 )
{
F_131 ( V_161 , V_236 ) ;
return 0 ;
}
static void * F_169 ( struct V_160 * V_161 , T_5 * V_211 )
{
F_68 () ;
if ( * V_211 >= V_260 )
return NULL ;
return V_211 ;
}
static void * F_170 ( struct V_160 * V_161 , void * V_236 ,
T_5 * V_211 )
{
( * V_211 ) ++ ;
if ( * V_211 >= V_260 )
return NULL ;
return V_211 ;
}
static void F_171 ( struct V_160 * V_161 , void * V_236 )
{
F_70 () ;
}
static int F_172 ( struct V_93 * V_93 , struct V_261 * V_261 )
{
int V_53 = F_173 ( V_261 , & V_262 ,
sizeof( struct V_254 ) ) ;
if ( V_53 == 0 ) {
struct V_160 * V_161 = V_261 -> V_142 ;
struct V_254 * V_255 = V_161 -> V_243 ;
V_255 -> V_4 = V_93 -> V_263 ;
V_255 -> V_259 = 0 ;
V_161 -> V_218 = F_108 ( V_264 , V_265 | V_266 ) ;
if ( V_161 -> V_218 )
V_161 -> V_215 = V_264 ;
V_255 -> V_2 = NULL ;
V_53 = F_174 ( & V_32 , & V_255 -> V_256 ) ;
}
return V_53 ;
}
static int F_175 ( struct V_93 * V_93 , struct V_261 * V_261 )
{
struct V_160 * V_161 = V_261 -> V_142 ;
struct V_254 * V_255 = V_161 -> V_243 ;
V_255 -> V_2 = NULL ;
F_176 ( & V_255 -> V_256 ) ;
return F_177 ( V_93 , V_261 ) ;
}
static int F_178 ( struct V_93 * V_93 , struct V_261 * V_261 )
{
int V_53 = F_173 ( V_261 , & V_267 ,
sizeof( struct V_254 ) ) ;
if ( V_53 == 0 ) {
struct V_160 * V_161 = V_261 -> V_142 ;
struct V_254 * V_255 = V_161 -> V_243 ;
V_255 -> V_4 = V_93 -> V_263 ;
V_255 -> V_259 = 0 ;
V_161 -> V_218 = F_108 ( V_264 , V_265 | V_266 ) ;
if ( V_161 -> V_218 )
V_161 -> V_215 = V_264 ;
V_255 -> V_2 = NULL ;
V_53 = F_174 ( & V_32 , & V_255 -> V_256 ) ;
}
return V_53 ;
}
static int F_179 ( struct V_93 * V_93 , struct V_261 * V_261 )
{
int V_53 = F_180 ( V_261 , & V_268 ) ;
if ( V_53 == 0 ) {
struct V_160 * V_161 = V_261 -> V_142 ;
V_161 -> V_243 = V_93 -> V_263 ;
}
return V_53 ;
}
int F_181 ( struct V_3 * V_4 )
{
struct V_269 * V_270 ;
V_270 = F_182 ( V_4 -> V_271 , V_272 ) ;
if ( F_183 ( V_270 ) )
goto V_273;
V_4 -> V_274 = V_270 ;
V_270 = F_184 ( L_18 ,
V_275 | V_276 ,
V_4 -> V_274 , V_4 ,
& V_277 ) ;
if ( F_183 ( V_270 ) )
goto V_273;
V_4 -> V_278 = V_270 ;
V_270 = F_184 ( L_19 ,
V_275 | V_276 ,
V_4 -> V_274 , V_4 ,
& V_279 ) ;
if ( F_183 ( V_270 ) )
goto V_273;
V_4 -> V_280 = V_270 ;
V_270 = F_184 ( L_20 ,
V_275 | V_276 ,
V_4 -> V_274 , V_4 ,
& V_281 ) ;
if ( F_183 ( V_270 ) )
goto V_273;
V_4 -> V_282 = V_270 ;
return 0 ;
V_273:
F_185 ( V_4 ) ;
return V_270 ? F_162 ( V_270 ) : - V_124 ;
}
void F_185 ( struct V_3 * V_4 )
{
if ( V_4 -> V_274 ) {
if ( V_4 -> V_278 ) {
F_186 ( V_4 -> V_278 ) ;
V_4 -> V_278 = NULL ;
}
if ( V_4 -> V_280 ) {
F_186 ( V_4 -> V_280 ) ;
V_4 -> V_280 = NULL ;
}
if ( V_4 -> V_282 ) {
F_186 ( V_4 -> V_282 ) ;
V_4 -> V_282 = NULL ;
}
F_186 ( V_4 -> V_274 ) ;
V_4 -> V_274 = NULL ;
}
}
int F_187 ( void )
{
V_272 = F_182 ( L_21 , NULL ) ;
if ( F_56 ( V_272 ) )
return F_162 ( V_272 ) ;
return V_272 ? 0 : - V_124 ;
}
void F_188 ( void )
{
F_186 ( V_272 ) ;
V_272 = NULL ;
}
