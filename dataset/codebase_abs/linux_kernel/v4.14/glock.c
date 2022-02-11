static int F_1 ( T_1 * V_1 , unsigned int V_2 ,
int V_3 , void * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_1 , struct V_5 , V_1 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_7 * V_10 = V_4 ;
if ( V_10 -> V_11 != V_8 -> V_11 ||
V_10 -> V_12 != V_8 -> V_12 ||
V_10 -> V_13 != V_8 -> V_13 )
return 0 ;
return F_3 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static T_2 * F_4 ( struct V_7 * V_9 )
{
T_3 V_14 = F_5 ( ( T_3 * ) V_9 , sizeof( * V_9 ) / 4 , 0 ) ;
return V_15 + F_6 ( V_14 , V_16 ) ;
}
static void F_7 ( struct V_17 * V_18 )
{
T_2 * V_19 = F_4 ( & V_18 -> V_20 ) ;
if ( F_8 ( V_19 ) )
F_9 ( V_19 , V_21 , 1 , & V_18 -> V_20 ) ;
}
static void F_10 ( struct V_22 * V_23 )
{
struct V_17 * V_18 = F_2 ( V_23 , struct V_17 , V_24 ) ;
if ( V_18 -> V_25 -> V_26 & V_27 ) {
F_11 ( V_28 , V_18 ) ;
} else {
F_12 ( V_18 -> V_29 . V_30 ) ;
F_11 ( V_31 , V_18 ) ;
}
}
void F_13 ( struct V_17 * V_18 )
{
struct V_32 * V_33 = V_18 -> V_20 . V_11 ;
F_14 ( & V_34 , & V_18 -> V_35 , V_36 ) ;
F_15 () ;
F_7 ( V_18 ) ;
F_16 ( & V_18 -> V_24 , F_10 ) ;
if ( F_17 ( & V_33 -> V_37 ) )
F_18 ( & V_33 -> V_38 ) ;
}
void F_19 ( struct V_17 * V_18 )
{
F_20 ( V_18 , F_21 ( & V_18 -> V_39 ) ) ;
F_22 ( & V_18 -> V_39 ) ;
}
static int F_23 ( const struct V_17 * V_18 )
{
const struct V_40 * V_41 = V_18 -> V_25 ;
if ( V_18 -> V_42 == V_43 )
return 0 ;
if ( ! F_24 ( & V_18 -> V_44 ) )
return 0 ;
if ( V_41 -> V_45 )
return V_41 -> V_45 ( V_18 ) ;
return 1 ;
}
void F_25 ( struct V_17 * V_18 )
{
F_26 ( & V_46 ) ;
if ( ! F_24 ( & V_18 -> V_47 ) )
F_27 ( & V_18 -> V_47 ) ;
else
F_28 ( & V_48 ) ;
F_29 ( & V_18 -> V_47 , & V_49 ) ;
F_30 ( V_50 , & V_18 -> V_51 ) ;
F_31 ( & V_46 ) ;
}
static void F_32 ( struct V_17 * V_18 )
{
if ( ! ( V_18 -> V_25 -> V_26 & V_52 ) )
return;
F_26 ( & V_46 ) ;
if ( ! F_24 ( & V_18 -> V_47 ) ) {
F_27 ( & V_18 -> V_47 ) ;
F_33 ( & V_48 ) ;
F_34 ( V_50 , & V_18 -> V_51 ) ;
}
F_31 ( & V_46 ) ;
}
static void F_35 ( struct V_17 * V_18 , unsigned long V_53 ) {
if ( ! F_36 ( V_54 , & V_18 -> V_55 , V_53 ) ) {
F_20 ( V_18 , V_18 -> V_39 . V_56 < 2 ) ;
V_18 -> V_39 . V_56 -- ;
}
}
static void F_37 ( struct V_17 * V_18 , unsigned long V_53 ) {
F_26 ( & V_18 -> V_39 . V_57 ) ;
F_35 ( V_18 , V_53 ) ;
F_31 ( & V_18 -> V_39 . V_57 ) ;
}
static void F_38 ( struct V_17 * V_18 )
{
struct V_32 * V_33 = V_18 -> V_20 . V_11 ;
struct V_58 * V_59 = F_39 ( V_18 ) ;
F_40 ( & V_18 -> V_39 ) ;
F_32 ( V_18 ) ;
F_31 ( & V_18 -> V_39 . V_57 ) ;
F_20 ( V_18 , ! F_24 ( & V_18 -> V_44 ) ) ;
F_20 ( V_18 , V_59 && V_59 -> V_60 ) ;
F_41 ( V_18 ) ;
V_33 -> V_61 . V_62 -> V_63 ( V_18 ) ;
}
void F_42 ( struct V_17 * V_18 )
{
F_37 ( V_18 , 0 ) ;
}
void F_43 ( struct V_17 * V_18 )
{
if ( F_44 ( & V_18 -> V_39 ) )
return;
F_38 ( V_18 ) ;
}
static inline int F_45 ( const struct V_17 * V_18 , const struct V_64 * V_65 )
{
const struct V_64 * V_66 = F_46 ( V_18 -> V_44 . V_67 , const struct V_64 , V_68 ) ;
if ( ( V_65 -> V_69 == V_70 ||
V_66 -> V_69 == V_70 ) && V_65 != V_66 )
return 0 ;
if ( V_18 -> V_42 == V_65 -> V_69 )
return 1 ;
if ( V_65 -> V_71 & V_72 )
return 0 ;
if ( V_18 -> V_42 == V_70 ) {
if ( V_65 -> V_69 == V_73 && V_66 -> V_69 == V_73 )
return 1 ;
if ( V_65 -> V_69 == V_74 && V_66 -> V_69 == V_74 )
return 1 ;
}
if ( V_18 -> V_42 != V_43 && ( V_65 -> V_71 & V_75 ) )
return 1 ;
return 0 ;
}
static void F_47 ( struct V_64 * V_65 )
{
F_34 ( V_76 , & V_65 -> V_77 ) ;
F_48 () ;
F_49 ( & V_65 -> V_77 , V_76 ) ;
}
static void F_50 ( struct V_17 * V_18 , const int V_78 )
{
struct V_64 * V_65 , * V_79 ;
F_51 (gh, tmp, &gl->gl_holders, gh_list) {
if ( F_52 ( V_80 , & V_65 -> V_77 ) )
continue;
if ( V_78 & V_81 )
V_65 -> V_82 = - V_83 ;
else if ( V_65 -> V_71 & ( V_84 | V_85 ) )
V_65 -> V_82 = V_86 ;
else
continue;
F_27 ( & V_65 -> V_68 ) ;
F_53 ( V_65 , 0 ) ;
F_47 ( V_65 ) ;
}
}
static int F_54 ( struct V_17 * V_18 )
__releases( &gl->gl_lockref.lock
static inline struct V_64 * F_55 ( const struct V_17 * V_18 )
{
struct V_64 * V_65 ;
F_56 (gh, &gl->gl_holders, gh_list) {
if ( ! F_52 ( V_80 , & V_65 -> V_77 ) )
return V_65 ;
}
return NULL ;
}
static void F_57 ( struct V_17 * V_18 , unsigned int V_87 )
{
int V_88 , V_89 ;
V_88 = ( V_18 -> V_42 != V_43 ) ;
V_89 = ( V_87 != V_43 ) ;
if ( V_88 != V_89 ) {
F_20 ( V_18 , F_21 ( & V_18 -> V_39 ) ) ;
if ( V_89 )
V_18 -> V_39 . V_56 ++ ;
else
V_18 -> V_39 . V_56 -- ;
}
if ( V_88 && V_89 && F_24 ( & V_18 -> V_44 ) )
F_34 ( V_90 , & V_18 -> V_51 ) ;
if ( V_87 != V_18 -> V_91 )
V_18 -> V_92 = F_58 ( V_18 -> V_92 - V_93 ,
V_94 ) ;
V_18 -> V_42 = V_87 ;
V_18 -> V_95 = V_96 ;
}
static void F_59 ( struct V_17 * V_18 )
{
V_18 -> V_97 = V_70 ;
F_34 ( V_98 , & V_18 -> V_51 ) ;
F_48 () ;
F_49 ( & V_18 -> V_51 , V_98 ) ;
}
static void F_60 ( struct V_17 * V_18 , unsigned int V_78 )
{
const struct V_40 * V_41 = V_18 -> V_25 ;
struct V_64 * V_65 ;
unsigned V_99 = V_78 & V_100 ;
int V_101 ;
F_26 ( & V_18 -> V_39 . V_57 ) ;
F_61 ( V_18 , V_99 ) ;
F_57 ( V_18 , V_99 ) ;
V_65 = F_55 ( V_18 ) ;
if ( F_52 ( V_102 , & V_18 -> V_51 ) &&
V_99 != V_43 && V_18 -> V_97 == V_43 )
V_18 -> V_91 = V_43 ;
if ( F_62 ( V_99 != V_18 -> V_91 ) ) {
if ( V_65 && ! F_52 ( V_102 , & V_18 -> V_51 ) ) {
if ( V_78 & V_103 ) {
if ( ( V_65 -> V_71 & V_104 ) == 0 )
F_63 ( & V_65 -> V_68 , & V_18 -> V_44 ) ;
V_65 = F_55 ( V_18 ) ;
V_18 -> V_91 = V_65 -> V_69 ;
goto V_105;
}
if ( ( V_78 & V_81 ) ||
( V_65 -> V_71 & ( V_84 | V_85 ) ) ) {
V_18 -> V_91 = V_18 -> V_42 ;
F_50 ( V_18 , V_78 ) ;
goto V_106;
}
}
switch( V_99 ) {
case V_43 :
V_105:
F_64 ( V_18 , V_65 , V_18 -> V_91 ) ;
break;
case V_73 :
case V_74 :
F_64 ( V_18 , V_65 , V_43 ) ;
break;
default:
F_65 ( L_1 , V_18 -> V_91 , V_99 ) ;
F_20 ( V_18 , 1 ) ;
}
F_31 ( & V_18 -> V_39 . V_57 ) ;
return;
}
if ( F_66 ( V_102 , & V_18 -> V_51 ) )
F_59 ( V_18 ) ;
if ( V_99 != V_43 ) {
if ( V_41 -> V_107 ) {
F_31 ( & V_18 -> V_39 . V_57 ) ;
V_101 = V_41 -> V_107 ( V_18 , V_65 ) ;
F_26 ( & V_18 -> V_39 . V_57 ) ;
if ( V_101 ) {
F_50 ( V_18 , V_101 ) ;
goto V_106;
}
}
V_101 = F_54 ( V_18 ) ;
if ( V_101 == 2 )
goto V_108;
}
V_106:
F_34 ( V_109 , & V_18 -> V_51 ) ;
V_108:
F_31 ( & V_18 -> V_39 . V_57 ) ;
}
static void F_64 ( struct V_17 * V_18 , struct V_64 * V_65 , unsigned int V_110 )
__releases( &gl->gl_lockref.lock
static inline struct V_64 * F_67 ( const struct V_17 * V_18 )
{
struct V_64 * V_65 ;
if ( ! F_24 ( & V_18 -> V_44 ) ) {
V_65 = F_46 ( V_18 -> V_44 . V_67 , struct V_64 , V_68 ) ;
if ( F_52 ( V_80 , & V_65 -> V_77 ) )
return V_65 ;
}
return NULL ;
}
static void F_68 ( struct V_17 * V_18 , const int V_111 )
__releases( &gl->gl_lockref.lock
static void F_69 ( struct V_112 * V_113 )
{
struct V_17 * V_18 = F_2 ( V_113 , struct V_17 , V_114 ) ;
struct V_32 * V_33 = V_18 -> V_20 . V_11 ;
struct V_115 * V_115 ;
T_4 V_116 = V_18 -> V_20 . V_12 ;
if ( F_52 ( V_117 , & V_18 -> V_51 ) )
goto V_106;
V_115 = F_70 ( V_33 , V_116 , NULL , V_118 ) ;
if ( V_115 && ! F_71 ( V_115 ) ) {
F_72 ( V_115 ) ;
F_73 ( V_115 ) ;
}
V_106:
F_43 ( V_18 ) ;
}
static void F_74 ( struct V_112 * V_113 )
{
unsigned long V_53 = 0 ;
struct V_17 * V_18 = F_2 ( V_113 , struct V_17 , V_55 . V_113 ) ;
unsigned int V_119 = 1 ;
if ( F_66 ( V_120 , & V_18 -> V_51 ) ) {
F_60 ( V_18 , V_18 -> V_121 ) ;
V_119 ++ ;
}
F_26 ( & V_18 -> V_39 . V_57 ) ;
if ( F_52 ( V_122 , & V_18 -> V_51 ) &&
V_18 -> V_42 != V_43 &&
V_18 -> V_97 != V_70 ) {
unsigned long V_123 , V_124 = V_96 ;
V_123 = V_18 -> V_95 + V_18 -> V_92 ;
if ( F_75 ( V_124 , V_123 ) )
V_53 = V_123 - V_124 ;
if ( ! V_53 ) {
F_34 ( V_122 , & V_18 -> V_51 ) ;
F_30 ( V_98 , & V_18 -> V_51 ) ;
}
}
F_68 ( V_18 , 0 ) ;
if ( V_53 ) {
V_119 -- ;
if ( V_18 -> V_20 . V_13 != V_125 )
V_53 = 0 ;
F_35 ( V_18 , V_53 ) ;
}
V_18 -> V_39 . V_56 -= V_119 ;
if ( ! V_18 -> V_39 . V_56 ) {
F_38 ( V_18 ) ;
return;
}
F_31 ( & V_18 -> V_39 . V_57 ) ;
}
static struct V_17 * F_76 ( struct V_7 * V_9 ,
struct V_17 * V_126 )
{
struct V_5 V_1 ;
T_2 * V_19 = F_4 ( V_9 ) ;
struct V_17 * V_18 ;
V_1 . V_9 = V_9 ;
F_77 ( & V_1 . V_1 ) ;
V_1 . V_1 . V_127 = F_1 ;
V_128:
F_78 ( V_19 , & V_1 . V_1 , V_129 ) ;
F_79 () ;
if ( V_126 ) {
V_18 = F_80 ( & V_34 ,
& V_126 -> V_35 , V_36 ) ;
if ( F_71 ( V_18 ) )
goto V_106;
} else {
V_18 = F_81 ( & V_34 ,
V_9 , V_36 ) ;
}
if ( V_18 && ! F_82 ( & V_18 -> V_39 ) ) {
F_83 () ;
F_84 () ;
goto V_128;
}
V_106:
F_83 () ;
F_85 ( V_19 , & V_1 . V_1 ) ;
return V_18 ;
}
int F_86 ( struct V_32 * V_33 , T_4 V_130 ,
const struct V_40 * V_41 , int V_131 ,
struct V_17 * * V_132 )
{
struct V_133 * V_134 = V_33 -> V_135 ;
struct V_7 V_9 = { . V_12 = V_130 ,
. V_13 = V_41 -> V_136 ,
. V_11 = V_33 } ;
struct V_17 * V_18 , * V_79 ;
struct V_58 * V_59 ;
struct V_137 * V_138 ;
int V_78 = 0 ;
V_18 = F_76 ( & V_9 , NULL ) ;
if ( V_18 ) {
* V_132 = V_18 ;
return 0 ;
}
if ( ! V_131 )
return - V_139 ;
if ( V_41 -> V_26 & V_27 )
V_138 = V_28 ;
else
V_138 = V_31 ;
V_18 = F_87 ( V_138 , V_140 ) ;
if ( ! V_18 )
return - V_141 ;
memset ( & V_18 -> V_29 , 0 , sizeof( struct V_142 ) ) ;
if ( V_41 -> V_26 & V_143 ) {
V_18 -> V_29 . V_30 = F_88 ( V_144 , V_140 ) ;
if ( ! V_18 -> V_29 . V_30 ) {
F_11 ( V_138 , V_18 ) ;
return - V_141 ;
}
}
F_28 ( & V_33 -> V_37 ) ;
V_18 -> V_35 . V_67 = NULL ;
V_18 -> V_51 = 0 ;
V_18 -> V_20 = V_9 ;
V_18 -> V_39 . V_56 = 1 ;
V_18 -> V_42 = V_43 ;
V_18 -> V_91 = V_43 ;
V_18 -> V_97 = V_70 ;
V_18 -> V_25 = V_41 ;
V_18 -> V_145 = 0 ;
F_89 () ;
V_18 -> V_146 = F_90 ( V_33 -> V_147 ) -> V_148 [ V_41 -> V_136 ] ;
F_91 () ;
V_18 -> V_146 . V_149 [ V_150 ] = 0 ;
V_18 -> V_146 . V_149 [ V_151 ] = 0 ;
V_18 -> V_95 = V_96 ;
V_18 -> V_152 = NULL ;
V_18 -> V_92 = V_153 ;
F_92 ( & V_18 -> V_55 , F_74 ) ;
F_93 ( & V_18 -> V_114 , F_69 ) ;
V_59 = F_39 ( V_18 ) ;
if ( V_59 ) {
V_59 -> V_154 = & V_155 ;
V_59 -> V_156 = V_134 -> V_157 -> V_158 ;
V_59 -> V_159 = 0 ;
F_94 ( V_59 , V_140 ) ;
V_59 -> V_160 = NULL ;
V_59 -> V_161 = 0 ;
}
V_79 = F_76 ( & V_9 , V_18 ) ;
if ( ! V_79 ) {
* V_132 = V_18 ;
goto V_106;
}
if ( F_71 ( V_79 ) ) {
V_78 = F_95 ( V_79 ) ;
goto V_162;
}
* V_132 = V_79 ;
V_162:
F_12 ( V_18 -> V_29 . V_30 ) ;
F_11 ( V_138 , V_18 ) ;
F_33 ( & V_33 -> V_37 ) ;
V_106:
return V_78 ;
}
void F_96 ( struct V_17 * V_18 , unsigned int V_99 , T_5 V_159 ,
struct V_64 * V_65 )
{
F_97 ( & V_65 -> V_68 ) ;
V_65 -> V_163 = V_18 ;
V_65 -> V_164 = V_165 ;
V_65 -> V_166 = F_98 ( F_99 ( V_167 ) ) ;
V_65 -> V_69 = V_99 ;
V_65 -> V_71 = V_159 ;
V_65 -> V_82 = 0 ;
V_65 -> V_77 = 0 ;
F_19 ( V_18 ) ;
}
void F_100 ( unsigned int V_99 , T_5 V_159 , struct V_64 * V_65 )
{
V_65 -> V_69 = V_99 ;
V_65 -> V_71 = V_159 ;
V_65 -> V_77 = 0 ;
V_65 -> V_164 = V_165 ;
F_101 ( V_65 -> V_166 ) ;
V_65 -> V_166 = F_98 ( F_99 ( V_167 ) ) ;
}
void F_102 ( struct V_64 * V_65 )
{
F_101 ( V_65 -> V_166 ) ;
F_43 ( V_65 -> V_163 ) ;
F_103 ( V_65 ) ;
V_65 -> V_164 = 0 ;
}
int F_104 ( struct V_64 * V_65 )
{
unsigned long V_168 = V_96 ;
F_105 () ;
F_106 ( & V_65 -> V_77 , V_76 , V_129 ) ;
if ( F_107 ( V_96 , V_168 + V_169 ) )
V_65 -> V_163 -> V_92 = F_108 ( V_65 -> V_163 -> V_92 +
V_170 ,
V_171 ) ;
return V_65 -> V_82 ;
}
static void F_109 ( struct V_17 * V_18 , unsigned int V_99 ,
unsigned long V_53 , bool V_172 )
{
int V_173 = V_53 ? V_122 : V_98 ;
F_30 ( V_173 , & V_18 -> V_51 ) ;
if ( V_18 -> V_97 == V_70 ) {
V_18 -> V_97 = V_99 ;
V_18 -> V_174 = V_96 ;
} else if ( V_18 -> V_97 != V_43 &&
V_18 -> V_97 != V_99 ) {
V_18 -> V_97 = V_43 ;
}
if ( V_18 -> V_25 -> V_175 )
V_18 -> V_25 -> V_175 ( V_18 , V_172 ) ;
F_110 ( V_18 , V_172 ) ;
}
void F_111 ( struct V_176 * V_177 , const char * V_178 , ... )
{
struct V_179 V_180 ;
T_6 args ;
va_start ( args , V_178 ) ;
if ( V_177 ) {
F_112 ( V_177 , V_178 , args ) ;
} else {
V_180 . V_178 = V_178 ;
V_180 . V_181 = & args ;
F_65 ( L_2 , & V_180 ) ;
}
va_end ( args ) ;
}
static inline void F_113 ( struct V_64 * V_65 )
__releases( &gl->gl_lockref.lock
int F_114 ( struct V_64 * V_65 )
{
struct V_17 * V_18 = V_65 -> V_163 ;
struct V_32 * V_33 = V_18 -> V_20 . V_11 ;
int error = 0 ;
if ( F_62 ( F_52 ( V_182 , & V_33 -> V_183 ) ) )
return - V_83 ;
if ( F_52 ( V_50 , & V_18 -> V_51 ) )
F_32 ( V_18 ) ;
F_26 ( & V_18 -> V_39 . V_57 ) ;
F_113 ( V_65 ) ;
if ( F_62 ( ( V_184 & V_65 -> V_71 ) &&
F_66 ( V_185 , & V_18 -> V_51 ) ) ) {
F_30 ( V_120 , & V_18 -> V_51 ) ;
V_18 -> V_39 . V_56 ++ ;
F_35 ( V_18 , 0 ) ;
}
F_68 ( V_18 , 1 ) ;
F_31 ( & V_18 -> V_39 . V_57 ) ;
if ( ! ( V_65 -> V_71 & V_186 ) )
error = F_104 ( V_65 ) ;
return error ;
}
int F_115 ( struct V_64 * V_65 )
{
return F_52 ( V_76 , & V_65 -> V_77 ) ? 0 : 1 ;
}
void F_116 ( struct V_64 * V_65 )
{
struct V_17 * V_18 = V_65 -> V_163 ;
const struct V_40 * V_41 = V_18 -> V_25 ;
unsigned V_53 = 0 ;
int V_187 = 0 ;
F_26 ( & V_18 -> V_39 . V_57 ) ;
if ( V_65 -> V_71 & V_188 )
F_109 ( V_18 , V_43 , 0 , false ) ;
F_27 ( & V_65 -> V_68 ) ;
F_34 ( V_80 , & V_65 -> V_77 ) ;
if ( F_67 ( V_18 ) == NULL ) {
if ( V_41 -> V_189 ) {
F_20 ( V_18 , F_117 ( V_109 , & V_18 -> V_51 ) ) ;
F_31 ( & V_18 -> V_39 . V_57 ) ;
V_41 -> V_189 ( V_65 ) ;
F_26 ( & V_18 -> V_39 . V_57 ) ;
F_34 ( V_109 , & V_18 -> V_51 ) ;
}
if ( F_24 ( & V_18 -> V_44 ) &&
! F_52 ( V_122 , & V_18 -> V_51 ) &&
! F_52 ( V_98 , & V_18 -> V_51 ) )
V_187 = 1 ;
}
if ( ! F_52 ( V_190 , & V_18 -> V_51 ) && F_23 ( V_18 ) &&
( V_41 -> V_26 & V_52 ) )
F_25 ( V_18 ) ;
F_53 ( V_65 , 0 ) ;
if ( F_62 ( ! V_187 ) ) {
V_18 -> V_39 . V_56 ++ ;
if ( F_52 ( V_122 , & V_18 -> V_51 ) &&
! F_52 ( V_98 , & V_18 -> V_51 ) &&
V_18 -> V_20 . V_13 == V_125 )
V_53 = V_18 -> V_92 ;
F_35 ( V_18 , V_53 ) ;
}
F_31 ( & V_18 -> V_39 . V_57 ) ;
}
void F_118 ( struct V_64 * V_65 )
{
struct V_17 * V_18 = V_65 -> V_163 ;
F_116 ( V_65 ) ;
F_105 () ;
F_106 ( & V_18 -> V_51 , V_98 , V_129 ) ;
}
void F_119 ( struct V_64 * V_65 )
{
F_116 ( V_65 ) ;
F_102 ( V_65 ) ;
}
int F_120 ( struct V_32 * V_33 , T_4 V_130 ,
const struct V_40 * V_41 ,
unsigned int V_99 , T_5 V_159 , struct V_64 * V_65 )
{
struct V_17 * V_18 ;
int error ;
error = F_86 ( V_33 , V_130 , V_41 , V_191 , & V_18 ) ;
if ( ! error ) {
error = F_121 ( V_18 , V_99 , V_159 , V_65 ) ;
F_43 ( V_18 ) ;
}
return error ;
}
static int F_122 ( const void * V_192 , const void * V_193 )
{
const struct V_64 * V_194 = * ( const struct V_64 * * ) V_192 ;
const struct V_64 * V_195 = * ( const struct V_64 * * ) V_193 ;
const struct V_7 * V_196 = & V_194 -> V_163 -> V_20 ;
const struct V_7 * V_197 = & V_195 -> V_163 -> V_20 ;
if ( V_196 -> V_12 > V_197 -> V_12 )
return 1 ;
if ( V_196 -> V_12 < V_197 -> V_12 )
return - 1 ;
F_123 ( V_194 -> V_163 -> V_25 -> V_136 == V_195 -> V_163 -> V_25 -> V_136 ) ;
return 0 ;
}
static int F_124 ( unsigned int V_198 , struct V_64 * V_199 ,
struct V_64 * * V_200 )
{
unsigned int V_201 ;
int error = 0 ;
for ( V_201 = 0 ; V_201 < V_198 ; V_201 ++ )
V_200 [ V_201 ] = & V_199 [ V_201 ] ;
F_125 ( V_200 , V_198 , sizeof( struct V_64 * ) , F_122 , NULL ) ;
for ( V_201 = 0 ; V_201 < V_198 ; V_201 ++ ) {
V_200 [ V_201 ] -> V_71 &= ~ ( V_84 | V_186 ) ;
error = F_114 ( V_200 [ V_201 ] ) ;
if ( error ) {
while ( V_201 -- )
F_116 ( V_200 [ V_201 ] ) ;
break;
}
}
return error ;
}
int F_126 ( unsigned int V_198 , struct V_64 * V_199 )
{
struct V_64 * V_79 [ 4 ] ;
struct V_64 * * V_202 = V_79 ;
int error = 0 ;
switch( V_198 ) {
case 0 :
return 0 ;
case 1 :
V_199 -> V_71 &= ~ ( V_84 | V_186 ) ;
return F_114 ( V_199 ) ;
default:
if ( V_198 <= 4 )
break;
V_202 = F_127 ( V_198 * sizeof( struct V_64 * ) , V_140 ) ;
if ( ! V_202 )
return - V_141 ;
}
error = F_124 ( V_198 , V_199 , V_202 ) ;
if ( V_202 != V_79 )
F_12 ( V_202 ) ;
return error ;
}
void F_128 ( unsigned int V_198 , struct V_64 * V_199 )
{
while ( V_198 -- )
F_116 ( & V_199 [ V_198 ] ) ;
}
void F_129 ( struct V_17 * V_18 , unsigned int V_99 )
{
unsigned long V_53 = 0 ;
unsigned long V_123 ;
unsigned long V_124 = V_96 ;
F_19 ( V_18 ) ;
V_123 = V_18 -> V_95 + V_18 -> V_92 ;
if ( F_52 ( V_90 , & V_18 -> V_51 ) &&
V_18 -> V_20 . V_13 == V_125 ) {
if ( F_75 ( V_124 , V_123 ) )
V_53 = V_123 - V_124 ;
if ( F_52 ( V_120 , & V_18 -> V_51 ) )
V_53 = V_18 -> V_92 ;
}
F_26 ( & V_18 -> V_39 . V_57 ) ;
F_109 ( V_18 , V_99 , V_53 , true ) ;
F_35 ( V_18 , V_53 ) ;
F_31 ( & V_18 -> V_39 . V_57 ) ;
}
static int F_130 ( const struct V_17 * V_18 )
{
const struct V_64 * V_65 ;
if ( V_18 -> V_121 & ~ V_100 )
return 0 ;
if ( V_18 -> V_91 == V_43 )
return 0 ;
F_56 (gh, &gl->gl_holders, gh_list) {
if ( F_52 ( V_80 , & V_65 -> V_77 ) )
continue;
if ( V_184 & V_65 -> V_71 )
return 0 ;
}
return 1 ;
}
void F_131 ( struct V_17 * V_18 , int V_78 )
{
struct V_203 * V_204 = & V_18 -> V_20 . V_11 -> V_61 ;
F_26 ( & V_18 -> V_39 . V_57 ) ;
V_18 -> V_121 = V_78 ;
if ( F_62 ( F_52 ( V_205 , & V_204 -> V_206 ) ) ) {
if ( F_130 ( V_18 ) ) {
F_30 ( V_185 , & V_18 -> V_51 ) ;
F_31 ( & V_18 -> V_39 . V_57 ) ;
return;
}
}
V_18 -> V_39 . V_56 ++ ;
F_30 ( V_120 , & V_18 -> V_51 ) ;
F_35 ( V_18 , 0 ) ;
F_31 ( & V_18 -> V_39 . V_57 ) ;
}
static int F_132 ( void * V_207 , struct V_208 * V_196 , struct V_208 * V_197 )
{
struct V_17 * V_209 , * V_210 ;
V_209 = F_46 ( V_196 , struct V_17 , V_47 ) ;
V_210 = F_46 ( V_197 , struct V_17 , V_47 ) ;
if ( V_209 -> V_20 . V_12 > V_210 -> V_20 . V_12 )
return 1 ;
if ( V_209 -> V_20 . V_12 < V_210 -> V_20 . V_12 )
return - 1 ;
return 0 ;
}
static void F_133 ( struct V_208 * V_211 )
__releases( &lru_lock
static long F_134 ( int V_212 )
{
struct V_17 * V_18 ;
F_135 ( V_213 ) ;
F_135 ( V_214 ) ;
long V_215 = 0 ;
F_26 ( & V_46 ) ;
while ( ( V_212 -- >= 0 ) && ! F_24 ( & V_49 ) ) {
V_18 = F_46 ( V_49 . V_67 , struct V_17 , V_47 ) ;
if ( ! F_52 ( V_109 , & V_18 -> V_51 ) ) {
F_136 ( & V_18 -> V_47 , & V_214 ) ;
F_33 ( & V_48 ) ;
V_215 ++ ;
continue;
}
F_136 ( & V_18 -> V_47 , & V_213 ) ;
}
F_137 ( & V_213 , & V_49 ) ;
if ( ! F_24 ( & V_214 ) )
F_133 ( & V_214 ) ;
F_31 ( & V_46 ) ;
return V_215 ;
}
static unsigned long F_138 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
if ( ! ( V_219 -> V_220 & V_221 ) )
return V_222 ;
return F_134 ( V_219 -> V_223 ) ;
}
static unsigned long F_139 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
return F_140 ( F_141 ( & V_48 ) ) ;
}
static void F_142 ( T_7 V_224 , const struct V_32 * V_33 )
{
struct V_17 * V_18 ;
struct V_225 V_226 ;
F_143 ( & V_34 , & V_226 ) ;
do {
V_18 = F_144 ( F_145 ( & V_226 ) ) ;
if ( F_71 ( V_18 ) )
goto V_227;
while ( ( V_18 = F_146 ( & V_226 ) ) && ! F_71 ( V_18 ) )
if ( V_18 -> V_20 . V_11 == V_33 &&
F_82 ( & V_18 -> V_39 ) )
V_224 ( V_18 ) ;
V_227:
F_147 ( & V_226 ) ;
} while ( F_148 () , V_18 == F_144 ( - V_228 ) );
F_149 ( & V_226 ) ;
}
static void F_150 ( struct V_17 * V_18 )
{
if ( ! F_66 ( V_185 , & V_18 -> V_51 ) ) {
F_43 ( V_18 ) ;
return;
}
F_30 ( V_120 , & V_18 -> V_51 ) ;
F_37 ( V_18 , 0 ) ;
}
static void F_151 ( struct V_17 * V_18 )
{
F_32 ( V_18 ) ;
F_26 ( & V_18 -> V_39 . V_57 ) ;
if ( V_18 -> V_42 != V_43 )
F_109 ( V_18 , V_43 , 0 , false ) ;
F_35 ( V_18 , 0 ) ;
F_31 ( & V_18 -> V_39 . V_57 ) ;
}
void F_152 ( struct V_32 * V_33 )
{
F_142 ( F_150 , V_33 ) ;
}
static void F_153 ( struct V_176 * V_177 , struct V_17 * V_18 )
{
F_26 ( & V_18 -> V_39 . V_57 ) ;
F_154 ( V_177 , V_18 ) ;
F_31 ( & V_18 -> V_39 . V_57 ) ;
}
static void F_155 ( struct V_17 * V_18 )
{
F_153 ( NULL , V_18 ) ;
}
void F_156 ( struct V_32 * V_33 )
{
F_30 ( V_229 , & V_33 -> V_183 ) ;
F_157 ( V_54 ) ;
F_142 ( F_151 , V_33 ) ;
F_157 ( V_54 ) ;
F_158 ( V_33 -> V_38 ,
F_141 ( & V_33 -> V_37 ) == 0 ,
V_169 * 600 ) ;
F_142 ( F_155 , V_33 ) ;
}
void F_159 ( struct V_230 * V_231 )
{
struct V_17 * V_18 = V_231 -> V_232 ;
int V_78 ;
V_78 = F_160 ( V_231 ) ;
F_161 ( V_18 -> V_20 . V_11 , V_78 == 0 ) ;
F_26 ( & V_18 -> V_39 . V_57 ) ;
F_34 ( V_109 , & V_18 -> V_51 ) ;
F_68 ( V_18 , 1 ) ;
F_31 ( & V_18 -> V_39 . V_57 ) ;
}
static const char * F_162 ( unsigned V_99 )
{
switch( V_99 ) {
case V_43 :
return L_3 ;
case V_73 :
return L_4 ;
case V_74 :
return L_5 ;
case V_70 :
return L_6 ;
}
return L_7 ;
}
static const char * F_163 ( char * V_233 , T_5 V_159 , unsigned long V_234 )
{
char * V_200 = V_233 ;
if ( V_159 & V_84 )
* V_200 ++ = 't' ;
if ( V_159 & V_85 )
* V_200 ++ = 'T' ;
if ( V_159 & V_184 )
* V_200 ++ = 'e' ;
if ( V_159 & V_75 )
* V_200 ++ = 'A' ;
if ( V_159 & V_104 )
* V_200 ++ = 'p' ;
if ( V_159 & V_186 )
* V_200 ++ = 'a' ;
if ( V_159 & V_72 )
* V_200 ++ = 'E' ;
if ( V_159 & V_188 )
* V_200 ++ = 'c' ;
if ( F_52 ( V_80 , & V_234 ) )
* V_200 ++ = 'H' ;
if ( F_52 ( V_76 , & V_234 ) )
* V_200 ++ = 'W' ;
if ( F_52 ( V_235 , & V_234 ) )
* V_200 ++ = 'F' ;
* V_200 = 0 ;
return V_233 ;
}
static void F_164 ( struct V_176 * V_177 , const struct V_64 * V_65 )
{
struct V_236 * V_237 = NULL ;
char V_238 [ 32 ] ;
F_79 () ;
if ( V_65 -> V_166 )
V_237 = F_165 ( V_65 -> V_166 , V_239 ) ;
F_111 ( V_177 , L_8 ,
F_162 ( V_65 -> V_69 ) ,
F_163 ( V_238 , V_65 -> V_71 , V_65 -> V_77 ) ,
V_65 -> V_82 ,
V_65 -> V_166 ? ( long ) F_166 ( V_65 -> V_166 ) : - 1 ,
V_237 ? V_237 -> V_240 : L_9 ,
( void * ) V_65 -> V_164 ) ;
F_83 () ;
}
static const char * F_167 ( char * V_233 , const struct V_17 * V_18 )
{
const unsigned long * V_241 = & V_18 -> V_51 ;
char * V_200 = V_233 ;
if ( F_52 ( V_109 , V_241 ) )
* V_200 ++ = 'l' ;
if ( F_52 ( V_98 , V_241 ) )
* V_200 ++ = 'D' ;
if ( F_52 ( V_122 , V_241 ) )
* V_200 ++ = 'd' ;
if ( F_52 ( V_102 , V_241 ) )
* V_200 ++ = 'p' ;
if ( F_52 ( V_242 , V_241 ) )
* V_200 ++ = 'y' ;
if ( F_52 ( V_190 , V_241 ) )
* V_200 ++ = 'f' ;
if ( F_52 ( V_243 , V_241 ) )
* V_200 ++ = 'i' ;
if ( F_52 ( V_120 , V_241 ) )
* V_200 ++ = 'r' ;
if ( F_52 ( V_244 , V_241 ) )
* V_200 ++ = 'I' ;
if ( F_52 ( V_185 , V_241 ) )
* V_200 ++ = 'F' ;
if ( F_52 ( V_90 , V_241 ) )
* V_200 ++ = 'q' ;
if ( F_52 ( V_50 , V_241 ) )
* V_200 ++ = 'L' ;
if ( V_18 -> V_152 )
* V_200 ++ = 'o' ;
if ( F_52 ( V_245 , V_241 ) )
* V_200 ++ = 'b' ;
* V_200 = 0 ;
return V_233 ;
}
void F_154 ( struct V_176 * V_177 , const struct V_17 * V_18 )
{
const struct V_40 * V_41 = V_18 -> V_25 ;
unsigned long long V_246 ;
const struct V_64 * V_65 ;
char V_247 [ 32 ] ;
V_246 = V_96 - V_18 -> V_174 ;
V_246 *= 1000000 / V_169 ;
if ( ! F_52 ( V_98 , & V_18 -> V_51 ) )
V_246 = 0 ;
F_111 ( V_177 , L_10 ,
F_162 ( V_18 -> V_42 ) ,
V_18 -> V_20 . V_13 ,
( unsigned long long ) V_18 -> V_20 . V_12 ,
F_167 ( V_247 , V_18 ) ,
F_162 ( V_18 -> V_91 ) ,
F_162 ( V_18 -> V_97 ) , V_246 ,
F_141 ( & V_18 -> V_248 ) ,
F_141 ( & V_18 -> V_249 ) ,
( int ) V_18 -> V_39 . V_56 , V_18 -> V_92 ) ;
F_56 (gh, &gl->gl_holders, gh_list)
F_164 ( V_177 , V_65 ) ;
if ( V_18 -> V_42 != V_43 && V_41 -> V_250 )
V_41 -> V_250 ( V_177 , V_18 ) ;
}
static int F_168 ( struct V_176 * V_177 , void * V_251 )
{
struct V_17 * V_18 = V_251 ;
F_169 ( V_177 , L_11 ,
V_18 -> V_20 . V_13 ,
( unsigned long long ) V_18 -> V_20 . V_12 ,
( unsigned long long ) V_18 -> V_146 . V_149 [ V_252 ] ,
( unsigned long long ) V_18 -> V_146 . V_149 [ V_253 ] ,
( unsigned long long ) V_18 -> V_146 . V_149 [ V_254 ] ,
( unsigned long long ) V_18 -> V_146 . V_149 [ V_255 ] ,
( unsigned long long ) V_18 -> V_146 . V_149 [ V_256 ] ,
( unsigned long long ) V_18 -> V_146 . V_149 [ V_257 ] ,
( unsigned long long ) V_18 -> V_146 . V_149 [ V_150 ] ,
( unsigned long long ) V_18 -> V_146 . V_149 [ V_151 ] ) ;
return 0 ;
}
static int F_170 ( struct V_176 * V_177 , void * V_251 )
{
struct V_32 * V_33 = V_177 -> V_258 ;
T_8 V_259 = * ( T_8 * ) V_251 ;
unsigned V_260 = V_259 >> 3 ;
unsigned V_261 = V_259 & 0x07 ;
int V_262 ;
if ( V_260 == 0 && V_261 != 0 )
return 0 ;
F_169 ( V_177 , L_12 , V_263 [ V_260 ] ,
( V_260 == 0 ) ? L_13 : V_264 [ V_261 ] ) ;
F_171 (i) {
const struct V_265 * V_148 = F_172 ( V_33 -> V_147 , V_262 ) ;
if ( V_260 == 0 )
F_169 ( V_177 , L_14 , V_262 ) ;
else
F_169 ( V_177 , L_15 , ( unsigned long long ) V_148 ->
V_148 [ V_260 - 1 ] . V_149 [ V_261 ] ) ;
}
F_173 ( V_177 , '\n' ) ;
return 0 ;
}
int T_9 F_174 ( void )
{
int V_262 , V_78 ;
V_78 = F_175 ( & V_34 , & V_36 ) ;
if ( V_78 < 0 )
return V_78 ;
V_54 = F_176 ( L_16 , V_266 |
V_267 | V_268 , 0 ) ;
if ( ! V_54 ) {
F_177 ( & V_34 ) ;
return - V_141 ;
}
V_269 = F_176 ( L_17 ,
V_266 | V_268 ,
0 ) ;
if ( ! V_269 ) {
F_178 ( V_54 ) ;
F_177 ( & V_34 ) ;
return - V_141 ;
}
V_78 = F_179 ( & V_270 ) ;
if ( V_78 ) {
F_178 ( V_269 ) ;
F_178 ( V_54 ) ;
F_177 ( & V_34 ) ;
return V_78 ;
}
for ( V_262 = 0 ; V_262 < V_271 ; V_262 ++ )
F_180 ( V_15 + V_262 ) ;
return 0 ;
}
void F_181 ( void )
{
F_182 ( & V_270 ) ;
F_177 ( & V_34 ) ;
F_178 ( V_54 ) ;
F_178 ( V_269 ) ;
}
static void F_183 ( struct V_272 * V_273 )
{
while ( ( V_273 -> V_18 = F_146 ( & V_273 -> V_274 ) ) ) {
if ( F_71 ( V_273 -> V_18 ) ) {
if ( F_95 ( V_273 -> V_18 ) == - V_228 )
continue;
V_273 -> V_18 = NULL ;
return;
}
if ( V_273 -> V_33 == V_273 -> V_18 -> V_20 . V_11 &&
! F_21 ( & V_273 -> V_18 -> V_39 ) )
return;
}
}
static void * F_184 ( struct V_176 * V_177 , T_8 * V_259 )
__acquires( T_10 )
{
struct V_272 * V_273 = V_177 -> V_258 ;
T_8 V_275 = * V_259 ;
F_143 ( & V_34 , & V_273 -> V_274 ) ;
if ( F_145 ( & V_273 -> V_274 ) != 0 )
return NULL ;
do {
F_183 ( V_273 ) ;
} while ( V_273 -> V_18 && V_275 -- );
V_273 -> V_276 = * V_259 ;
return V_273 -> V_18 ;
}
static void * F_185 ( struct V_176 * V_177 , void * V_251 ,
T_8 * V_259 )
{
struct V_272 * V_273 = V_177 -> V_258 ;
( * V_259 ) ++ ;
V_273 -> V_276 = * V_259 ;
F_183 ( V_273 ) ;
return V_273 -> V_18 ;
}
static void F_186 ( struct V_176 * V_177 , void * V_251 )
__releases( T_10 )
{
struct V_272 * V_273 = V_177 -> V_258 ;
V_273 -> V_18 = NULL ;
F_147 ( & V_273 -> V_274 ) ;
F_149 ( & V_273 -> V_274 ) ;
}
static int F_187 ( struct V_176 * V_177 , void * V_251 )
{
F_153 ( V_177 , V_251 ) ;
return 0 ;
}
static void * F_188 ( struct V_176 * V_177 , T_8 * V_259 )
{
F_89 () ;
if ( * V_259 >= V_277 )
return NULL ;
return V_259 ;
}
static void * F_189 ( struct V_176 * V_177 , void * V_251 ,
T_8 * V_259 )
{
( * V_259 ) ++ ;
if ( * V_259 >= V_277 )
return NULL ;
return V_259 ;
}
static void F_190 ( struct V_176 * V_177 , void * V_251 )
{
F_91 () ;
}
static int F_191 ( struct V_115 * V_115 , struct V_278 * V_278 ,
const struct V_279 * V_280 )
{
int V_78 = F_192 ( V_278 , V_280 , sizeof( struct V_272 ) ) ;
if ( V_78 == 0 ) {
struct V_176 * V_177 = V_278 -> V_160 ;
struct V_272 * V_273 = V_177 -> V_258 ;
V_273 -> V_33 = V_115 -> V_281 ;
V_177 -> V_233 = F_127 ( V_282 , V_283 | V_284 ) ;
if ( V_177 -> V_233 )
V_177 -> V_285 = V_282 ;
V_273 -> V_18 = NULL ;
}
return V_78 ;
}
static int F_193 ( struct V_115 * V_115 , struct V_278 * V_278 )
{
return F_191 ( V_115 , V_278 , & V_286 ) ;
}
static int F_194 ( struct V_115 * V_115 , struct V_278 * V_278 )
{
struct V_176 * V_177 = V_278 -> V_160 ;
struct V_272 * V_273 = V_177 -> V_258 ;
V_273 -> V_18 = NULL ;
return F_195 ( V_115 , V_278 ) ;
}
static int F_196 ( struct V_115 * V_115 , struct V_278 * V_278 )
{
return F_191 ( V_115 , V_278 , & V_287 ) ;
}
static int F_197 ( struct V_115 * V_115 , struct V_278 * V_278 )
{
int V_78 = F_198 ( V_278 , & V_288 ) ;
if ( V_78 == 0 ) {
struct V_176 * V_177 = V_278 -> V_160 ;
V_177 -> V_258 = V_115 -> V_281 ;
}
return V_78 ;
}
int F_199 ( struct V_32 * V_33 )
{
struct V_289 * V_290 ;
V_290 = F_200 ( V_33 -> V_291 , V_292 ) ;
if ( F_201 ( V_290 ) )
goto V_293;
V_33 -> V_294 = V_290 ;
V_290 = F_202 ( L_18 ,
V_295 | V_296 ,
V_33 -> V_294 , V_33 ,
& V_297 ) ;
if ( F_201 ( V_290 ) )
goto V_293;
V_33 -> V_298 = V_290 ;
V_290 = F_202 ( L_19 ,
V_295 | V_296 ,
V_33 -> V_294 , V_33 ,
& V_299 ) ;
if ( F_201 ( V_290 ) )
goto V_293;
V_33 -> V_300 = V_290 ;
V_290 = F_202 ( L_20 ,
V_295 | V_296 ,
V_33 -> V_294 , V_33 ,
& V_301 ) ;
if ( F_201 ( V_290 ) )
goto V_293;
V_33 -> V_302 = V_290 ;
return 0 ;
V_293:
F_203 ( V_33 ) ;
return V_290 ? F_95 ( V_290 ) : - V_141 ;
}
void F_203 ( struct V_32 * V_33 )
{
if ( V_33 -> V_294 ) {
if ( V_33 -> V_298 ) {
F_204 ( V_33 -> V_298 ) ;
V_33 -> V_298 = NULL ;
}
if ( V_33 -> V_300 ) {
F_204 ( V_33 -> V_300 ) ;
V_33 -> V_300 = NULL ;
}
if ( V_33 -> V_302 ) {
F_204 ( V_33 -> V_302 ) ;
V_33 -> V_302 = NULL ;
}
F_204 ( V_33 -> V_294 ) ;
V_33 -> V_294 = NULL ;
}
}
int F_205 ( void )
{
V_292 = F_200 ( L_21 , NULL ) ;
if ( F_71 ( V_292 ) )
return F_95 ( V_292 ) ;
return V_292 ? 0 : - V_141 ;
}
void F_206 ( void )
{
F_204 ( V_292 ) ;
V_292 = NULL ;
}
