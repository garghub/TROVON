static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( V_4 -> V_6 -> V_7 & V_8 ) {
F_3 ( V_9 , V_4 ) ;
} else {
F_4 ( V_4 -> V_10 . V_11 ) ;
F_3 ( V_12 , V_4 ) ;
}
}
void F_5 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_15 . V_16 ;
F_6 ( & V_4 -> V_5 , F_1 ) ;
if ( F_7 ( & V_14 -> V_17 ) )
F_8 ( & V_14 -> V_18 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
F_10 ( V_4 , F_11 ( & V_4 -> V_19 ) ) ;
F_12 ( & V_4 -> V_19 ) ;
}
static int F_13 ( const struct V_3 * V_4 )
{
const struct V_20 * V_21 = V_4 -> V_6 ;
if ( V_4 -> V_22 == V_23 )
return 0 ;
if ( ! F_14 ( & V_4 -> V_24 ) )
return 0 ;
if ( V_21 -> V_25 )
return V_21 -> V_25 ( V_4 ) ;
return 1 ;
}
void F_15 ( struct V_3 * V_4 )
{
F_16 ( & V_26 ) ;
if ( ! F_14 ( & V_4 -> V_27 ) )
F_17 ( & V_4 -> V_27 ) ;
else
F_18 ( & V_28 ) ;
F_19 ( & V_4 -> V_27 , & V_29 ) ;
F_20 ( V_30 , & V_4 -> V_31 ) ;
F_21 ( & V_26 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
F_16 ( & V_26 ) ;
if ( ! F_14 ( & V_4 -> V_27 ) ) {
F_17 ( & V_4 -> V_27 ) ;
F_23 ( & V_28 ) ;
F_24 ( V_30 , & V_4 -> V_31 ) ;
}
F_21 ( & V_26 ) ;
}
static void F_25 ( struct V_3 * V_4 , unsigned long V_32 ) {
if ( ! F_26 ( V_33 , & V_4 -> V_34 , V_32 ) ) {
F_10 ( V_4 , V_4 -> V_19 . V_35 < 2 ) ;
V_4 -> V_19 . V_35 -- ;
}
}
static void F_27 ( struct V_3 * V_4 , unsigned long V_32 ) {
F_16 ( & V_4 -> V_19 . V_36 ) ;
F_25 ( V_4 , V_32 ) ;
F_21 ( & V_4 -> V_19 . V_36 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_15 . V_16 ;
struct V_37 * V_38 = F_29 ( V_4 ) ;
F_30 ( & V_4 -> V_19 ) ;
F_22 ( V_4 ) ;
F_21 ( & V_4 -> V_19 . V_36 ) ;
F_31 ( & V_39 , & V_4 -> V_40 , V_41 ) ;
F_10 ( V_4 , ! F_14 ( & V_4 -> V_24 ) ) ;
F_10 ( V_4 , V_38 && V_38 -> V_42 ) ;
F_32 ( V_4 ) ;
V_14 -> V_43 . V_44 -> V_45 ( V_4 ) ;
}
void F_33 ( struct V_3 * V_4 )
{
if ( F_34 ( & V_4 -> V_19 ) )
return;
F_28 ( V_4 ) ;
}
static inline int F_35 ( const struct V_3 * V_4 , const struct V_46 * V_47 )
{
const struct V_46 * V_48 = F_36 ( V_4 -> V_24 . V_49 , const struct V_46 , V_50 ) ;
if ( ( V_47 -> V_51 == V_52 ||
V_48 -> V_51 == V_52 ) && V_47 != V_48 )
return 0 ;
if ( V_4 -> V_22 == V_47 -> V_51 )
return 1 ;
if ( V_47 -> V_53 & V_54 )
return 0 ;
if ( V_4 -> V_22 == V_52 ) {
if ( V_47 -> V_51 == V_55 && V_48 -> V_51 == V_55 )
return 1 ;
if ( V_47 -> V_51 == V_56 && V_48 -> V_51 == V_56 )
return 1 ;
}
if ( V_4 -> V_22 != V_23 && ( V_47 -> V_53 & V_57 ) )
return 1 ;
return 0 ;
}
static void F_37 ( struct V_46 * V_47 )
{
F_24 ( V_58 , & V_47 -> V_59 ) ;
F_38 () ;
F_39 ( & V_47 -> V_59 , V_58 ) ;
}
static void F_40 ( struct V_3 * V_4 , const int V_60 )
{
struct V_46 * V_47 , * V_61 ;
F_41 (gh, tmp, &gl->gl_holders, gh_list) {
if ( F_42 ( V_62 , & V_47 -> V_59 ) )
continue;
if ( V_60 & V_63 )
V_47 -> V_64 = - V_65 ;
else if ( V_47 -> V_53 & ( V_66 | V_67 ) )
V_47 -> V_64 = V_68 ;
else
continue;
F_17 ( & V_47 -> V_50 ) ;
F_43 ( V_47 , 0 ) ;
F_37 ( V_47 ) ;
}
}
static int F_44 ( struct V_3 * V_4 )
__releases( &gl->gl_lockref.lock
static inline struct V_46 * F_45 ( const struct V_3 * V_4 )
{
struct V_46 * V_47 ;
F_46 (gh, &gl->gl_holders, gh_list) {
if ( ! F_42 ( V_62 , & V_47 -> V_59 ) )
return V_47 ;
}
return NULL ;
}
static void F_47 ( struct V_3 * V_4 , unsigned int V_69 )
{
int V_70 , V_71 ;
V_70 = ( V_4 -> V_22 != V_23 ) ;
V_71 = ( V_69 != V_23 ) ;
if ( V_70 != V_71 ) {
F_10 ( V_4 , F_11 ( & V_4 -> V_19 ) ) ;
if ( V_71 )
V_4 -> V_19 . V_35 ++ ;
else
V_4 -> V_19 . V_35 -- ;
}
if ( V_70 && V_71 && F_14 ( & V_4 -> V_24 ) )
F_24 ( V_72 , & V_4 -> V_31 ) ;
if ( V_69 != V_4 -> V_73 )
V_4 -> V_74 = F_48 ( V_4 -> V_74 - V_75 ,
V_76 ) ;
V_4 -> V_22 = V_69 ;
V_4 -> V_77 = V_78 ;
}
static void F_49 ( struct V_3 * V_4 )
{
V_4 -> V_79 = V_52 ;
F_24 ( V_80 , & V_4 -> V_31 ) ;
F_38 () ;
F_39 ( & V_4 -> V_31 , V_80 ) ;
}
static void F_50 ( struct V_3 * V_4 , unsigned int V_60 )
{
const struct V_20 * V_21 = V_4 -> V_6 ;
struct V_46 * V_47 ;
unsigned V_81 = V_60 & V_82 ;
int V_83 ;
F_16 ( & V_4 -> V_19 . V_36 ) ;
F_51 ( V_4 , V_81 ) ;
F_47 ( V_4 , V_81 ) ;
V_47 = F_45 ( V_4 ) ;
if ( F_42 ( V_84 , & V_4 -> V_31 ) &&
V_81 != V_23 && V_4 -> V_79 == V_23 )
V_4 -> V_73 = V_23 ;
if ( F_52 ( V_81 != V_4 -> V_73 ) ) {
if ( V_47 && ! F_42 ( V_84 , & V_4 -> V_31 ) ) {
if ( V_60 & V_85 ) {
if ( ( V_47 -> V_53 & V_86 ) == 0 )
F_53 ( & V_47 -> V_50 , & V_4 -> V_24 ) ;
V_47 = F_45 ( V_4 ) ;
V_4 -> V_73 = V_47 -> V_51 ;
goto V_87;
}
if ( ( V_60 & V_63 ) ||
( V_47 -> V_53 & ( V_66 | V_67 ) ) ) {
V_4 -> V_73 = V_4 -> V_22 ;
F_40 ( V_4 , V_60 ) ;
goto V_88;
}
}
switch( V_81 ) {
case V_23 :
V_87:
F_54 ( V_4 , V_47 , V_4 -> V_73 ) ;
break;
case V_55 :
case V_56 :
F_54 ( V_4 , V_47 , V_23 ) ;
break;
default:
F_55 ( L_1 , V_4 -> V_73 , V_81 ) ;
F_10 ( V_4 , 1 ) ;
}
F_21 ( & V_4 -> V_19 . V_36 ) ;
return;
}
if ( F_56 ( V_84 , & V_4 -> V_31 ) )
F_49 ( V_4 ) ;
if ( V_81 != V_23 ) {
if ( V_21 -> V_89 ) {
F_21 ( & V_4 -> V_19 . V_36 ) ;
V_83 = V_21 -> V_89 ( V_4 , V_47 ) ;
F_16 ( & V_4 -> V_19 . V_36 ) ;
if ( V_83 ) {
F_40 ( V_4 , V_83 ) ;
goto V_88;
}
}
V_83 = F_44 ( V_4 ) ;
if ( V_83 == 2 )
goto V_90;
}
V_88:
F_24 ( V_91 , & V_4 -> V_31 ) ;
V_90:
F_21 ( & V_4 -> V_19 . V_36 ) ;
}
static void F_54 ( struct V_3 * V_4 , struct V_46 * V_47 , unsigned int V_92 )
__releases( &gl->gl_lockref.lock
static inline struct V_46 * F_57 ( const struct V_3 * V_4 )
{
struct V_46 * V_47 ;
if ( ! F_14 ( & V_4 -> V_24 ) ) {
V_47 = F_36 ( V_4 -> V_24 . V_49 , struct V_46 , V_50 ) ;
if ( F_42 ( V_62 , & V_47 -> V_59 ) )
return V_47 ;
}
return NULL ;
}
static void F_58 ( struct V_3 * V_4 , const int V_93 )
__releases( &gl->gl_lockref.lock
static void F_59 ( struct V_94 * V_95 )
{
struct V_3 * V_4 = F_2 ( V_95 , struct V_3 , V_96 ) ;
struct V_13 * V_14 = V_4 -> V_15 . V_16 ;
struct V_97 * V_97 ;
T_1 V_98 = V_4 -> V_15 . V_99 ;
if ( F_42 ( V_100 , & V_4 -> V_31 ) )
goto V_88;
V_97 = F_60 ( V_14 , V_98 , NULL , V_101 ) ;
if ( V_97 && ! F_61 ( V_97 ) ) {
F_62 ( V_97 ) ;
F_63 ( V_97 ) ;
}
V_88:
F_33 ( V_4 ) ;
}
static void F_64 ( struct V_94 * V_95 )
{
unsigned long V_32 = 0 ;
struct V_3 * V_4 = F_2 ( V_95 , struct V_3 , V_34 . V_95 ) ;
unsigned int V_102 = 1 ;
if ( F_56 ( V_103 , & V_4 -> V_31 ) ) {
F_50 ( V_4 , V_4 -> V_104 ) ;
V_102 ++ ;
}
F_16 ( & V_4 -> V_19 . V_36 ) ;
if ( F_42 ( V_105 , & V_4 -> V_31 ) &&
V_4 -> V_22 != V_23 &&
V_4 -> V_79 != V_52 ) {
unsigned long V_106 , V_107 = V_78 ;
V_106 = V_4 -> V_77 + V_4 -> V_74 ;
if ( F_65 ( V_107 , V_106 ) )
V_32 = V_106 - V_107 ;
if ( ! V_32 ) {
F_24 ( V_105 , & V_4 -> V_31 ) ;
F_20 ( V_80 , & V_4 -> V_31 ) ;
}
}
F_58 ( V_4 , 0 ) ;
if ( V_32 ) {
V_102 -- ;
if ( V_4 -> V_15 . V_108 != V_109 )
V_32 = 0 ;
F_25 ( V_4 , V_32 ) ;
}
V_4 -> V_19 . V_35 -= V_102 ;
if ( ! V_4 -> V_19 . V_35 ) {
F_28 ( V_4 ) ;
return;
}
F_21 ( & V_4 -> V_19 . V_36 ) ;
}
int F_66 ( struct V_13 * V_14 , T_1 V_110 ,
const struct V_20 * V_21 , int V_111 ,
struct V_3 * * V_112 )
{
struct V_113 * V_114 = V_14 -> V_115 ;
struct V_116 V_117 = { . V_99 = V_110 ,
. V_108 = V_21 -> V_118 ,
. V_16 = V_14 } ;
struct V_3 * V_4 , * V_61 ;
struct V_37 * V_38 ;
struct V_119 * V_120 ;
int V_60 = 0 ;
F_67 () ;
V_4 = F_68 ( & V_39 , & V_117 , V_41 ) ;
if ( V_4 && ! F_69 ( & V_4 -> V_19 ) )
V_4 = NULL ;
F_70 () ;
* V_112 = V_4 ;
if ( V_4 )
return 0 ;
if ( ! V_111 )
return - V_121 ;
if ( V_21 -> V_7 & V_8 )
V_120 = V_9 ;
else
V_120 = V_12 ;
V_4 = F_71 ( V_120 , V_122 ) ;
if ( ! V_4 )
return - V_123 ;
memset ( & V_4 -> V_10 , 0 , sizeof( struct V_124 ) ) ;
if ( V_21 -> V_7 & V_125 ) {
V_4 -> V_10 . V_11 = F_72 ( V_126 , V_122 ) ;
if ( ! V_4 -> V_10 . V_11 ) {
F_3 ( V_120 , V_4 ) ;
return - V_123 ;
}
}
F_18 ( & V_14 -> V_17 ) ;
V_4 -> V_40 . V_49 = NULL ;
V_4 -> V_31 = 0 ;
V_4 -> V_15 = V_117 ;
V_4 -> V_19 . V_35 = 1 ;
V_4 -> V_22 = V_23 ;
V_4 -> V_73 = V_23 ;
V_4 -> V_79 = V_52 ;
V_4 -> V_6 = V_21 ;
V_4 -> V_127 = 0 ;
F_73 () ;
V_4 -> V_128 = F_74 ( V_14 -> V_129 ) -> V_130 [ V_21 -> V_118 ] ;
F_75 () ;
V_4 -> V_128 . V_131 [ V_132 ] = 0 ;
V_4 -> V_128 . V_131 [ V_133 ] = 0 ;
V_4 -> V_77 = V_78 ;
V_4 -> V_134 = NULL ;
V_4 -> V_74 = V_135 ;
F_76 ( & V_4 -> V_34 , F_64 ) ;
F_77 ( & V_4 -> V_96 , F_59 ) ;
V_38 = F_29 ( V_4 ) ;
if ( V_38 ) {
V_38 -> V_136 = & V_137 ;
V_38 -> V_138 = V_114 -> V_139 -> V_140 ;
V_38 -> V_141 = 0 ;
F_78 ( V_38 , V_122 ) ;
V_38 -> V_142 = NULL ;
V_38 -> V_143 = 0 ;
}
V_144:
F_67 () ;
V_61 = F_79 ( & V_39 , & V_4 -> V_40 ,
V_41 ) ;
if ( ! V_61 ) {
* V_112 = V_4 ;
goto V_88;
}
if ( F_61 ( V_61 ) ) {
V_60 = F_80 ( V_61 ) ;
goto V_145;
}
if ( F_69 ( & V_61 -> V_19 ) ) {
* V_112 = V_61 ;
goto V_145;
}
F_70 () ;
F_81 () ;
goto V_144;
V_145:
F_4 ( V_4 -> V_10 . V_11 ) ;
F_3 ( V_120 , V_4 ) ;
F_23 ( & V_14 -> V_17 ) ;
V_88:
F_70 () ;
return V_60 ;
}
void F_82 ( struct V_3 * V_4 , unsigned int V_81 , T_2 V_141 ,
struct V_46 * V_47 )
{
F_83 ( & V_47 -> V_50 ) ;
V_47 -> V_146 = V_4 ;
V_47 -> V_147 = V_148 ;
V_47 -> V_149 = F_84 ( F_85 ( V_150 ) ) ;
V_47 -> V_51 = V_81 ;
V_47 -> V_53 = V_141 ;
V_47 -> V_64 = 0 ;
V_47 -> V_59 = 0 ;
F_9 ( V_4 ) ;
}
void F_86 ( unsigned int V_81 , T_2 V_141 , struct V_46 * V_47 )
{
V_47 -> V_51 = V_81 ;
V_47 -> V_53 = V_141 ;
V_47 -> V_59 = 0 ;
V_47 -> V_147 = V_148 ;
F_87 ( V_47 -> V_149 ) ;
V_47 -> V_149 = F_84 ( F_85 ( V_150 ) ) ;
}
void F_88 ( struct V_46 * V_47 )
{
F_87 ( V_47 -> V_149 ) ;
F_33 ( V_47 -> V_146 ) ;
F_89 ( V_47 ) ;
V_47 -> V_147 = 0 ;
}
int F_90 ( struct V_46 * V_47 )
{
unsigned long V_151 = V_78 ;
F_91 () ;
F_92 ( & V_47 -> V_59 , V_58 , V_152 ) ;
if ( F_93 ( V_78 , V_151 + V_153 ) )
V_47 -> V_146 -> V_74 = F_94 ( V_47 -> V_146 -> V_74 +
V_154 ,
V_155 ) ;
return V_47 -> V_64 ;
}
static void F_95 ( struct V_3 * V_4 , unsigned int V_81 ,
unsigned long V_32 , bool V_156 )
{
int V_157 = V_32 ? V_105 : V_80 ;
F_20 ( V_157 , & V_4 -> V_31 ) ;
if ( V_4 -> V_79 == V_52 ) {
V_4 -> V_79 = V_81 ;
V_4 -> V_158 = V_78 ;
} else if ( V_4 -> V_79 != V_23 &&
V_4 -> V_79 != V_81 ) {
V_4 -> V_79 = V_23 ;
}
if ( V_4 -> V_6 -> V_159 )
V_4 -> V_6 -> V_159 ( V_4 , V_156 ) ;
F_96 ( V_4 , V_156 ) ;
}
void F_97 ( struct V_160 * V_161 , const char * V_162 , ... )
{
struct V_163 V_164 ;
T_3 args ;
va_start ( args , V_162 ) ;
if ( V_161 ) {
F_98 ( V_161 , V_162 , args ) ;
} else {
V_164 . V_162 = V_162 ;
V_164 . V_165 = & args ;
F_55 ( L_2 , & V_164 ) ;
}
va_end ( args ) ;
}
static inline void F_99 ( struct V_46 * V_47 )
__releases( &gl->gl_lockref.lock
int F_100 ( struct V_46 * V_47 )
{
struct V_3 * V_4 = V_47 -> V_146 ;
struct V_13 * V_14 = V_4 -> V_15 . V_16 ;
int error = 0 ;
if ( F_52 ( F_42 ( V_166 , & V_14 -> V_167 ) ) )
return - V_65 ;
if ( F_42 ( V_30 , & V_4 -> V_31 ) )
F_22 ( V_4 ) ;
F_16 ( & V_4 -> V_19 . V_36 ) ;
F_99 ( V_47 ) ;
if ( F_52 ( ( V_168 & V_47 -> V_53 ) &&
F_56 ( V_169 , & V_4 -> V_31 ) ) ) {
F_20 ( V_103 , & V_4 -> V_31 ) ;
V_4 -> V_19 . V_35 ++ ;
F_25 ( V_4 , 0 ) ;
}
F_58 ( V_4 , 1 ) ;
F_21 ( & V_4 -> V_19 . V_36 ) ;
if ( ! ( V_47 -> V_53 & V_170 ) )
error = F_90 ( V_47 ) ;
return error ;
}
int F_101 ( struct V_46 * V_47 )
{
return F_42 ( V_58 , & V_47 -> V_59 ) ? 0 : 1 ;
}
void F_102 ( struct V_46 * V_47 )
{
struct V_3 * V_4 = V_47 -> V_146 ;
const struct V_20 * V_21 = V_4 -> V_6 ;
unsigned V_32 = 0 ;
int V_171 = 0 ;
F_16 ( & V_4 -> V_19 . V_36 ) ;
if ( V_47 -> V_53 & V_172 )
F_95 ( V_4 , V_23 , 0 , false ) ;
F_17 ( & V_47 -> V_50 ) ;
F_24 ( V_62 , & V_47 -> V_59 ) ;
if ( F_57 ( V_4 ) == NULL ) {
if ( V_21 -> V_173 ) {
F_10 ( V_4 , F_103 ( V_91 , & V_4 -> V_31 ) ) ;
F_21 ( & V_4 -> V_19 . V_36 ) ;
V_21 -> V_173 ( V_47 ) ;
F_16 ( & V_4 -> V_19 . V_36 ) ;
F_24 ( V_91 , & V_4 -> V_31 ) ;
}
if ( F_14 ( & V_4 -> V_24 ) &&
! F_42 ( V_105 , & V_4 -> V_31 ) &&
! F_42 ( V_80 , & V_4 -> V_31 ) )
V_171 = 1 ;
}
if ( ! F_42 ( V_174 , & V_4 -> V_31 ) && F_13 ( V_4 ) &&
( V_21 -> V_7 & V_175 ) )
F_15 ( V_4 ) ;
F_43 ( V_47 , 0 ) ;
if ( F_52 ( ! V_171 ) ) {
V_4 -> V_19 . V_35 ++ ;
if ( F_42 ( V_105 , & V_4 -> V_31 ) &&
! F_42 ( V_80 , & V_4 -> V_31 ) &&
V_4 -> V_15 . V_108 == V_109 )
V_32 = V_4 -> V_74 ;
F_25 ( V_4 , V_32 ) ;
}
F_21 ( & V_4 -> V_19 . V_36 ) ;
}
void F_104 ( struct V_46 * V_47 )
{
struct V_3 * V_4 = V_47 -> V_146 ;
F_102 ( V_47 ) ;
F_91 () ;
F_92 ( & V_4 -> V_31 , V_80 , V_152 ) ;
}
void F_105 ( struct V_46 * V_47 )
{
F_102 ( V_47 ) ;
F_88 ( V_47 ) ;
}
int F_106 ( struct V_13 * V_14 , T_1 V_110 ,
const struct V_20 * V_21 ,
unsigned int V_81 , T_2 V_141 , struct V_46 * V_47 )
{
struct V_3 * V_4 ;
int error ;
error = F_66 ( V_14 , V_110 , V_21 , V_176 , & V_4 ) ;
if ( ! error ) {
error = F_107 ( V_4 , V_81 , V_141 , V_47 ) ;
F_33 ( V_4 ) ;
}
return error ;
}
static int F_108 ( const void * V_177 , const void * V_178 )
{
const struct V_46 * V_179 = * ( const struct V_46 * * ) V_177 ;
const struct V_46 * V_180 = * ( const struct V_46 * * ) V_178 ;
const struct V_116 * V_181 = & V_179 -> V_146 -> V_15 ;
const struct V_116 * V_182 = & V_180 -> V_146 -> V_15 ;
if ( V_181 -> V_99 > V_182 -> V_99 )
return 1 ;
if ( V_181 -> V_99 < V_182 -> V_99 )
return - 1 ;
F_109 ( V_179 -> V_146 -> V_6 -> V_118 == V_180 -> V_146 -> V_6 -> V_118 ) ;
return 0 ;
}
static int F_110 ( unsigned int V_183 , struct V_46 * V_184 ,
struct V_46 * * V_185 )
{
unsigned int V_186 ;
int error = 0 ;
for ( V_186 = 0 ; V_186 < V_183 ; V_186 ++ )
V_185 [ V_186 ] = & V_184 [ V_186 ] ;
F_111 ( V_185 , V_183 , sizeof( struct V_46 * ) , F_108 , NULL ) ;
for ( V_186 = 0 ; V_186 < V_183 ; V_186 ++ ) {
V_185 [ V_186 ] -> V_53 &= ~ ( V_66 | V_170 ) ;
error = F_100 ( V_185 [ V_186 ] ) ;
if ( error ) {
while ( V_186 -- )
F_102 ( V_185 [ V_186 ] ) ;
break;
}
}
return error ;
}
int F_112 ( unsigned int V_183 , struct V_46 * V_184 )
{
struct V_46 * V_61 [ 4 ] ;
struct V_46 * * V_187 = V_61 ;
int error = 0 ;
switch( V_183 ) {
case 0 :
return 0 ;
case 1 :
V_184 -> V_53 &= ~ ( V_66 | V_170 ) ;
return F_100 ( V_184 ) ;
default:
if ( V_183 <= 4 )
break;
V_187 = F_113 ( V_183 * sizeof( struct V_46 * ) , V_122 ) ;
if ( ! V_187 )
return - V_123 ;
}
error = F_110 ( V_183 , V_184 , V_187 ) ;
if ( V_187 != V_61 )
F_4 ( V_187 ) ;
return error ;
}
void F_114 ( unsigned int V_183 , struct V_46 * V_184 )
{
while ( V_183 -- )
F_102 ( & V_184 [ V_183 ] ) ;
}
void F_115 ( struct V_3 * V_4 , unsigned int V_81 )
{
unsigned long V_32 = 0 ;
unsigned long V_106 ;
unsigned long V_107 = V_78 ;
F_9 ( V_4 ) ;
V_106 = V_4 -> V_77 + V_4 -> V_74 ;
if ( F_42 ( V_72 , & V_4 -> V_31 ) &&
V_4 -> V_15 . V_108 == V_109 ) {
if ( F_65 ( V_107 , V_106 ) )
V_32 = V_106 - V_107 ;
if ( F_42 ( V_103 , & V_4 -> V_31 ) )
V_32 = V_4 -> V_74 ;
}
F_16 ( & V_4 -> V_19 . V_36 ) ;
F_95 ( V_4 , V_81 , V_32 , true ) ;
F_25 ( V_4 , V_32 ) ;
F_21 ( & V_4 -> V_19 . V_36 ) ;
}
static int F_116 ( const struct V_3 * V_4 )
{
const struct V_46 * V_47 ;
if ( V_4 -> V_104 & ~ V_82 )
return 0 ;
if ( V_4 -> V_73 == V_23 )
return 0 ;
F_46 (gh, &gl->gl_holders, gh_list) {
if ( F_42 ( V_62 , & V_47 -> V_59 ) )
continue;
if ( V_168 & V_47 -> V_53 )
return 0 ;
}
return 1 ;
}
void F_117 ( struct V_3 * V_4 , int V_60 )
{
struct V_188 * V_189 = & V_4 -> V_15 . V_16 -> V_43 ;
F_16 ( & V_4 -> V_19 . V_36 ) ;
V_4 -> V_104 = V_60 ;
if ( F_52 ( F_42 ( V_190 , & V_189 -> V_191 ) ) ) {
if ( F_116 ( V_4 ) ) {
F_20 ( V_169 , & V_4 -> V_31 ) ;
F_21 ( & V_4 -> V_19 . V_36 ) ;
return;
}
}
V_4 -> V_19 . V_35 ++ ;
F_20 ( V_103 , & V_4 -> V_31 ) ;
F_25 ( V_4 , 0 ) ;
F_21 ( & V_4 -> V_19 . V_36 ) ;
}
static int F_118 ( void * V_192 , struct V_193 * V_181 , struct V_193 * V_182 )
{
struct V_3 * V_194 , * V_195 ;
V_194 = F_36 ( V_181 , struct V_3 , V_27 ) ;
V_195 = F_36 ( V_182 , struct V_3 , V_27 ) ;
if ( V_194 -> V_15 . V_99 > V_195 -> V_15 . V_99 )
return 1 ;
if ( V_194 -> V_15 . V_99 < V_195 -> V_15 . V_99 )
return - 1 ;
return 0 ;
}
static void F_119 ( struct V_193 * V_196 )
__releases( &lru_lock
static long F_120 ( int V_197 )
{
struct V_3 * V_4 ;
F_121 ( V_198 ) ;
F_121 ( V_199 ) ;
long V_200 = 0 ;
F_16 ( & V_26 ) ;
while ( ( V_197 -- >= 0 ) && ! F_14 ( & V_29 ) ) {
V_4 = F_36 ( V_29 . V_49 , struct V_3 , V_27 ) ;
if ( ! F_42 ( V_91 , & V_4 -> V_31 ) ) {
F_122 ( & V_4 -> V_27 , & V_199 ) ;
F_23 ( & V_28 ) ;
V_200 ++ ;
continue;
}
F_122 ( & V_4 -> V_27 , & V_198 ) ;
}
F_123 ( & V_198 , & V_29 ) ;
if ( ! F_14 ( & V_199 ) )
F_119 ( & V_199 ) ;
F_21 ( & V_26 ) ;
return V_200 ;
}
static unsigned long F_124 ( struct V_201 * V_202 ,
struct V_203 * V_204 )
{
if ( ! ( V_204 -> V_205 & V_206 ) )
return V_207 ;
return F_120 ( V_204 -> V_208 ) ;
}
static unsigned long F_125 ( struct V_201 * V_202 ,
struct V_203 * V_204 )
{
return F_126 ( F_127 ( & V_28 ) ) ;
}
static void F_128 ( T_4 V_209 , const struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_210 V_211 ;
F_129 ( & V_39 , & V_211 ) ;
do {
V_4 = F_130 ( F_131 ( & V_211 ) ) ;
if ( V_4 )
continue;
while ( ( V_4 = F_132 ( & V_211 ) ) && ! F_61 ( V_4 ) )
if ( ( V_4 -> V_15 . V_16 == V_14 ) &&
F_69 ( & V_4 -> V_19 ) )
V_209 ( V_4 ) ;
F_133 ( & V_211 ) ;
} while ( F_81 () , V_4 == F_130 ( - V_212 ) );
F_134 ( & V_211 ) ;
}
static void F_135 ( struct V_3 * V_4 )
{
if ( ! F_56 ( V_169 , & V_4 -> V_31 ) ) {
F_33 ( V_4 ) ;
return;
}
F_20 ( V_103 , & V_4 -> V_31 ) ;
F_27 ( V_4 , 0 ) ;
}
static void F_136 ( struct V_3 * V_4 )
{
F_22 ( V_4 ) ;
F_16 ( & V_4 -> V_19 . V_36 ) ;
if ( V_4 -> V_22 != V_23 )
F_95 ( V_4 , V_23 , 0 , false ) ;
F_25 ( V_4 , 0 ) ;
F_21 ( & V_4 -> V_19 . V_36 ) ;
}
void F_137 ( struct V_13 * V_14 )
{
F_128 ( F_135 , V_14 ) ;
}
static void F_138 ( struct V_160 * V_161 , struct V_3 * V_4 )
{
F_16 ( & V_4 -> V_19 . V_36 ) ;
F_139 ( V_161 , V_4 ) ;
F_21 ( & V_4 -> V_19 . V_36 ) ;
}
static void F_140 ( struct V_3 * V_4 )
{
F_138 ( NULL , V_4 ) ;
}
void F_141 ( struct V_13 * V_14 )
{
F_20 ( V_213 , & V_14 -> V_167 ) ;
F_142 ( V_33 ) ;
F_128 ( F_136 , V_14 ) ;
F_142 ( V_33 ) ;
F_143 ( V_14 -> V_18 ,
F_127 ( & V_14 -> V_17 ) == 0 ,
V_153 * 600 ) ;
F_128 ( F_140 , V_14 ) ;
}
void F_144 ( struct V_214 * V_215 )
{
struct V_3 * V_4 = V_215 -> V_216 ;
int V_60 ;
V_60 = F_145 ( V_215 ) ;
F_146 ( V_4 -> V_15 . V_16 , V_60 == 0 ) ;
F_16 ( & V_4 -> V_19 . V_36 ) ;
F_24 ( V_91 , & V_4 -> V_31 ) ;
F_58 ( V_4 , 1 ) ;
F_21 ( & V_4 -> V_19 . V_36 ) ;
}
static const char * F_147 ( unsigned V_81 )
{
switch( V_81 ) {
case V_23 :
return L_3 ;
case V_55 :
return L_4 ;
case V_56 :
return L_5 ;
case V_52 :
return L_6 ;
}
return L_7 ;
}
static const char * F_148 ( char * V_217 , T_2 V_141 , unsigned long V_218 )
{
char * V_185 = V_217 ;
if ( V_141 & V_66 )
* V_185 ++ = 't' ;
if ( V_141 & V_67 )
* V_185 ++ = 'T' ;
if ( V_141 & V_168 )
* V_185 ++ = 'e' ;
if ( V_141 & V_57 )
* V_185 ++ = 'A' ;
if ( V_141 & V_86 )
* V_185 ++ = 'p' ;
if ( V_141 & V_170 )
* V_185 ++ = 'a' ;
if ( V_141 & V_54 )
* V_185 ++ = 'E' ;
if ( V_141 & V_172 )
* V_185 ++ = 'c' ;
if ( F_42 ( V_62 , & V_218 ) )
* V_185 ++ = 'H' ;
if ( F_42 ( V_58 , & V_218 ) )
* V_185 ++ = 'W' ;
if ( F_42 ( V_219 , & V_218 ) )
* V_185 ++ = 'F' ;
* V_185 = 0 ;
return V_217 ;
}
static void F_149 ( struct V_160 * V_161 , const struct V_46 * V_47 )
{
struct V_220 * V_221 = NULL ;
char V_222 [ 32 ] ;
F_67 () ;
if ( V_47 -> V_149 )
V_221 = F_150 ( V_47 -> V_149 , V_223 ) ;
F_97 ( V_161 , L_8 ,
F_147 ( V_47 -> V_51 ) ,
F_148 ( V_222 , V_47 -> V_53 , V_47 -> V_59 ) ,
V_47 -> V_64 ,
V_47 -> V_149 ? ( long ) F_151 ( V_47 -> V_149 ) : - 1 ,
V_221 ? V_221 -> V_224 : L_9 ,
( void * ) V_47 -> V_147 ) ;
F_70 () ;
}
static const char * F_152 ( char * V_217 , const struct V_3 * V_4 )
{
const unsigned long * V_225 = & V_4 -> V_31 ;
char * V_185 = V_217 ;
if ( F_42 ( V_91 , V_225 ) )
* V_185 ++ = 'l' ;
if ( F_42 ( V_80 , V_225 ) )
* V_185 ++ = 'D' ;
if ( F_42 ( V_105 , V_225 ) )
* V_185 ++ = 'd' ;
if ( F_42 ( V_84 , V_225 ) )
* V_185 ++ = 'p' ;
if ( F_42 ( V_226 , V_225 ) )
* V_185 ++ = 'y' ;
if ( F_42 ( V_174 , V_225 ) )
* V_185 ++ = 'f' ;
if ( F_42 ( V_227 , V_225 ) )
* V_185 ++ = 'i' ;
if ( F_42 ( V_103 , V_225 ) )
* V_185 ++ = 'r' ;
if ( F_42 ( V_228 , V_225 ) )
* V_185 ++ = 'I' ;
if ( F_42 ( V_169 , V_225 ) )
* V_185 ++ = 'F' ;
if ( F_42 ( V_72 , V_225 ) )
* V_185 ++ = 'q' ;
if ( F_42 ( V_30 , V_225 ) )
* V_185 ++ = 'L' ;
if ( V_4 -> V_134 )
* V_185 ++ = 'o' ;
if ( F_42 ( V_229 , V_225 ) )
* V_185 ++ = 'b' ;
* V_185 = 0 ;
return V_217 ;
}
void F_139 ( struct V_160 * V_161 , const struct V_3 * V_4 )
{
const struct V_20 * V_21 = V_4 -> V_6 ;
unsigned long long V_230 ;
const struct V_46 * V_47 ;
char V_231 [ 32 ] ;
V_230 = V_78 - V_4 -> V_158 ;
V_230 *= 1000000 / V_153 ;
if ( ! F_42 ( V_80 , & V_4 -> V_31 ) )
V_230 = 0 ;
F_97 ( V_161 , L_10 ,
F_147 ( V_4 -> V_22 ) ,
V_4 -> V_15 . V_108 ,
( unsigned long long ) V_4 -> V_15 . V_99 ,
F_152 ( V_231 , V_4 ) ,
F_147 ( V_4 -> V_73 ) ,
F_147 ( V_4 -> V_79 ) , V_230 ,
F_127 ( & V_4 -> V_232 ) ,
F_127 ( & V_4 -> V_233 ) ,
( int ) V_4 -> V_19 . V_35 , V_4 -> V_74 ) ;
F_46 (gh, &gl->gl_holders, gh_list)
F_149 ( V_161 , V_47 ) ;
if ( V_4 -> V_22 != V_23 && V_21 -> V_234 )
V_21 -> V_234 ( V_161 , V_4 ) ;
}
static int F_153 ( struct V_160 * V_161 , void * V_235 )
{
struct V_3 * V_4 = V_235 ;
F_154 ( V_161 , L_11 ,
V_4 -> V_15 . V_108 ,
( unsigned long long ) V_4 -> V_15 . V_99 ,
( unsigned long long ) V_4 -> V_128 . V_131 [ V_236 ] ,
( unsigned long long ) V_4 -> V_128 . V_131 [ V_237 ] ,
( unsigned long long ) V_4 -> V_128 . V_131 [ V_238 ] ,
( unsigned long long ) V_4 -> V_128 . V_131 [ V_239 ] ,
( unsigned long long ) V_4 -> V_128 . V_131 [ V_240 ] ,
( unsigned long long ) V_4 -> V_128 . V_131 [ V_241 ] ,
( unsigned long long ) V_4 -> V_128 . V_131 [ V_132 ] ,
( unsigned long long ) V_4 -> V_128 . V_131 [ V_133 ] ) ;
return 0 ;
}
static int F_155 ( struct V_160 * V_161 , void * V_235 )
{
struct V_13 * V_14 = V_161 -> V_242 ;
T_5 V_243 = * ( T_5 * ) V_235 ;
unsigned V_244 = V_243 >> 3 ;
unsigned V_245 = V_243 & 0x07 ;
int V_246 ;
if ( V_244 == 0 && V_245 != 0 )
return 0 ;
F_154 ( V_161 , L_12 , V_247 [ V_244 ] ,
( V_244 == 0 ) ? L_13 : V_248 [ V_245 ] ) ;
F_156 (i) {
const struct V_249 * V_130 = F_157 ( V_14 -> V_129 , V_246 ) ;
if ( V_244 == 0 )
F_154 ( V_161 , L_14 , V_246 ) ;
else
F_154 ( V_161 , L_15 , ( unsigned long long ) V_130 ->
V_130 [ V_244 - 1 ] . V_131 [ V_245 ] ) ;
}
F_158 ( V_161 , '\n' ) ;
return 0 ;
}
int T_6 F_159 ( void )
{
int V_60 ;
V_60 = F_160 ( & V_39 , & V_41 ) ;
if ( V_60 < 0 )
return V_60 ;
V_33 = F_161 ( L_16 , V_250 |
V_251 | V_252 , 0 ) ;
if ( ! V_33 ) {
F_162 ( & V_39 ) ;
return - V_123 ;
}
V_253 = F_161 ( L_17 ,
V_250 | V_252 ,
0 ) ;
if ( ! V_253 ) {
F_163 ( V_33 ) ;
F_162 ( & V_39 ) ;
return - V_123 ;
}
V_60 = F_164 ( & V_254 ) ;
if ( V_60 ) {
F_163 ( V_253 ) ;
F_163 ( V_33 ) ;
F_162 ( & V_39 ) ;
return V_60 ;
}
return 0 ;
}
void F_165 ( void )
{
F_166 ( & V_254 ) ;
F_162 ( & V_39 ) ;
F_163 ( V_33 ) ;
F_163 ( V_253 ) ;
}
static void F_167 ( struct V_255 * V_256 )
{
while ( ( V_256 -> V_4 = F_132 ( & V_256 -> V_257 ) ) ) {
if ( F_61 ( V_256 -> V_4 ) ) {
if ( F_80 ( V_256 -> V_4 ) == - V_212 )
continue;
V_256 -> V_4 = NULL ;
return;
}
if ( V_256 -> V_14 == V_256 -> V_4 -> V_15 . V_16 &&
! F_11 ( & V_256 -> V_4 -> V_19 ) )
return;
}
}
static void * F_168 ( struct V_160 * V_161 , T_5 * V_243 )
{
struct V_255 * V_256 = V_161 -> V_242 ;
T_5 V_258 = * V_243 ;
int V_60 ;
if ( V_256 -> V_259 <= * V_243 )
V_258 = ( * V_243 - V_256 -> V_259 ) ;
V_60 = F_131 ( & V_256 -> V_257 ) ;
if ( V_60 )
return NULL ;
do {
F_167 ( V_256 ) ;
} while ( V_256 -> V_4 && V_258 -- );
V_256 -> V_259 = * V_243 ;
return V_256 -> V_4 ;
}
static void * F_169 ( struct V_160 * V_161 , void * V_235 ,
T_5 * V_243 )
{
struct V_255 * V_256 = V_161 -> V_242 ;
( * V_243 ) ++ ;
V_256 -> V_259 = * V_243 ;
F_167 ( V_256 ) ;
return V_256 -> V_4 ;
}
static void F_170 ( struct V_160 * V_161 , void * V_235 )
{
struct V_255 * V_256 = V_161 -> V_242 ;
V_256 -> V_4 = NULL ;
F_133 ( & V_256 -> V_257 ) ;
}
static int F_171 ( struct V_160 * V_161 , void * V_235 )
{
F_138 ( V_161 , V_235 ) ;
return 0 ;
}
static void * F_172 ( struct V_160 * V_161 , T_5 * V_243 )
{
F_73 () ;
if ( * V_243 >= V_260 )
return NULL ;
return V_243 ;
}
static void * F_173 ( struct V_160 * V_161 , void * V_235 ,
T_5 * V_243 )
{
( * V_243 ) ++ ;
if ( * V_243 >= V_260 )
return NULL ;
return V_243 ;
}
static void F_174 ( struct V_160 * V_161 , void * V_235 )
{
F_75 () ;
}
static int F_175 ( struct V_97 * V_97 , struct V_261 * V_261 ,
const struct V_262 * V_263 )
{
int V_60 = F_176 ( V_261 , V_263 , sizeof( struct V_255 ) ) ;
if ( V_60 == 0 ) {
struct V_160 * V_161 = V_261 -> V_142 ;
struct V_255 * V_256 = V_161 -> V_242 ;
V_256 -> V_14 = V_97 -> V_264 ;
V_256 -> V_259 = 0 ;
V_161 -> V_217 = F_113 ( V_265 , V_266 | V_267 ) ;
if ( V_161 -> V_217 )
V_161 -> V_268 = V_265 ;
V_256 -> V_4 = NULL ;
F_129 ( & V_39 , & V_256 -> V_257 ) ;
}
return V_60 ;
}
static int F_177 ( struct V_97 * V_97 , struct V_261 * V_261 )
{
return F_175 ( V_97 , V_261 , & V_269 ) ;
}
static int F_178 ( struct V_97 * V_97 , struct V_261 * V_261 )
{
struct V_160 * V_161 = V_261 -> V_142 ;
struct V_255 * V_256 = V_161 -> V_242 ;
V_256 -> V_4 = NULL ;
F_134 ( & V_256 -> V_257 ) ;
return F_179 ( V_97 , V_261 ) ;
}
static int F_180 ( struct V_97 * V_97 , struct V_261 * V_261 )
{
return F_175 ( V_97 , V_261 , & V_270 ) ;
}
static int F_181 ( struct V_97 * V_97 , struct V_261 * V_261 )
{
int V_60 = F_182 ( V_261 , & V_271 ) ;
if ( V_60 == 0 ) {
struct V_160 * V_161 = V_261 -> V_142 ;
V_161 -> V_242 = V_97 -> V_264 ;
}
return V_60 ;
}
int F_183 ( struct V_13 * V_14 )
{
struct V_272 * V_273 ;
V_273 = F_184 ( V_14 -> V_274 , V_275 ) ;
if ( F_185 ( V_273 ) )
goto V_276;
V_14 -> V_277 = V_273 ;
V_273 = F_186 ( L_18 ,
V_278 | V_279 ,
V_14 -> V_277 , V_14 ,
& V_280 ) ;
if ( F_185 ( V_273 ) )
goto V_276;
V_14 -> V_281 = V_273 ;
V_273 = F_186 ( L_19 ,
V_278 | V_279 ,
V_14 -> V_277 , V_14 ,
& V_282 ) ;
if ( F_185 ( V_273 ) )
goto V_276;
V_14 -> V_283 = V_273 ;
V_273 = F_186 ( L_20 ,
V_278 | V_279 ,
V_14 -> V_277 , V_14 ,
& V_284 ) ;
if ( F_185 ( V_273 ) )
goto V_276;
V_14 -> V_285 = V_273 ;
return 0 ;
V_276:
F_187 ( V_14 ) ;
return V_273 ? F_80 ( V_273 ) : - V_123 ;
}
void F_187 ( struct V_13 * V_14 )
{
if ( V_14 -> V_277 ) {
if ( V_14 -> V_281 ) {
F_188 ( V_14 -> V_281 ) ;
V_14 -> V_281 = NULL ;
}
if ( V_14 -> V_283 ) {
F_188 ( V_14 -> V_283 ) ;
V_14 -> V_283 = NULL ;
}
if ( V_14 -> V_285 ) {
F_188 ( V_14 -> V_285 ) ;
V_14 -> V_285 = NULL ;
}
F_188 ( V_14 -> V_277 ) ;
V_14 -> V_277 = NULL ;
}
}
int F_189 ( void )
{
V_275 = F_184 ( L_21 , NULL ) ;
if ( F_61 ( V_275 ) )
return F_80 ( V_275 ) ;
return V_275 ? 0 : - V_123 ;
}
void F_190 ( void )
{
F_188 ( V_275 ) ;
V_275 = NULL ;
}
