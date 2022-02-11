static const char * F_1 ( enum V_1 V_2 )
{
#define F_2 ( V_2 ) case MEI_HBMS_##status: return #status
switch ( V_2 ) {
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
default: return L_1 ;
}
#undef F_2
}
static const char * F_3 ( enum V_11 V_2 )
{
#define F_4 ( V_2 ) case MEI_CL_CONN_##status: return #status
switch ( V_2 ) {
F_4 ( V_3 ) ;
F_4 ( V_12 ) ;
F_4 ( V_9 ) ;
F_4 ( V_13 ) ;
F_4 ( V_14 ) ;
F_4 ( V_8 ) ;
default: return L_1 ;
}
#undef V_15
}
const char * F_5 ( enum V_16 V_17 )
{
#define F_6 ( V_17 ) case MEI_HBM_##state: return #state
switch ( V_17 ) {
F_6 ( V_18 ) ;
F_6 ( V_19 ) ;
F_6 ( V_20 ) ;
F_6 ( V_21 ) ;
F_6 ( V_22 ) ;
F_6 ( V_23 ) ;
default:
return L_1 ;
}
#undef F_6
}
static int F_7 ( enum V_11 V_2 )
{
switch ( V_2 ) {
case V_24 : return 0 ;
case V_25 : return - V_26 ;
case V_27 : return - V_28 ;
case V_29 : return - V_28 ;
case V_30 : return - V_31 ;
case V_32 : return - V_28 ;
default: return - V_31 ;
}
}
void F_8 ( struct V_33 * V_34 )
{
V_34 -> V_35 = 0 ;
V_34 -> V_36 = V_37 ;
}
void F_9 ( struct V_33 * V_34 )
{
V_34 -> V_38 = 0 ;
F_10 ( V_34 ) ;
F_8 ( V_34 ) ;
}
static inline void F_11 ( struct V_39 * V_40 , T_1 V_41 )
{
V_40 -> V_42 = 0 ;
V_40 -> V_43 = 0 ;
V_40 -> V_41 = V_41 ;
V_40 -> V_44 = 1 ;
V_40 -> V_45 = 0 ;
}
static inline
void F_12 ( struct V_46 * V_47 , T_2 V_48 , void * V_49 , T_1 V_50 )
{
struct V_51 * V_52 = V_49 ;
memset ( V_52 , 0 , V_50 ) ;
V_52 -> V_48 = V_48 ;
V_52 -> V_42 = F_13 ( V_47 ) ;
V_52 -> V_43 = F_14 ( V_47 ) ;
}
static inline
int F_15 ( struct V_33 * V_34 ,
struct V_46 * V_47 , T_2 V_48 , T_1 V_50 )
{
struct V_39 * V_53 = & V_34 -> V_54 . V_40 ;
F_11 ( V_53 , V_50 ) ;
F_12 ( V_47 , V_48 , V_34 -> V_54 . V_55 , V_50 ) ;
return F_16 ( V_34 , V_53 , V_34 -> V_54 . V_55 ) ;
}
static inline
bool F_17 ( struct V_46 * V_47 , struct V_51 * V_52 )
{
return F_13 ( V_47 ) == V_52 -> V_42 &&
F_14 ( V_47 ) == V_52 -> V_43 ;
}
static inline
struct V_46 * F_18 ( struct V_33 * V_34 , void * V_49 )
{
struct V_51 * V_52 = (struct V_51 * ) V_49 ;
struct V_46 * V_47 ;
F_19 (cl, &dev->file_list, link)
if ( F_17 ( V_47 , V_52 ) )
return V_47 ;
return NULL ;
}
int F_20 ( struct V_33 * V_34 )
{
int V_56 ;
if ( V_34 -> V_36 > V_57 )
return 0 ;
F_21 ( & V_34 -> V_58 ) ;
V_56 = F_22 ( V_34 -> V_59 ,
V_34 -> V_36 != V_57 ,
F_23 ( V_60 ) ) ;
F_24 ( & V_34 -> V_58 ) ;
if ( V_56 == 0 && ( V_34 -> V_36 <= V_57 ) ) {
V_34 -> V_36 = V_37 ;
F_25 ( V_34 -> V_34 , L_2 ) ;
return - V_61 ;
}
return 0 ;
}
int F_26 ( struct V_33 * V_34 )
{
struct V_39 * V_53 = & V_34 -> V_54 . V_40 ;
struct V_62 * V_63 ;
const T_1 V_50 = sizeof( struct V_62 ) ;
int V_56 ;
F_9 ( V_34 ) ;
F_11 ( V_53 , V_50 ) ;
V_63 = (struct V_62 * ) V_34 -> V_54 . V_55 ;
memset ( V_63 , 0 , V_50 ) ;
V_63 -> V_48 = V_64 ;
V_63 -> V_65 . V_66 = V_67 ;
V_63 -> V_65 . V_68 = V_69 ;
V_34 -> V_36 = V_37 ;
V_56 = F_16 ( V_34 , V_53 , V_34 -> V_54 . V_55 ) ;
if ( V_56 ) {
F_25 ( V_34 -> V_34 , L_3 ,
V_56 ) ;
return V_56 ;
}
V_34 -> V_36 = V_57 ;
V_34 -> V_35 = V_70 ;
return 0 ;
}
static int F_27 ( struct V_33 * V_34 )
{
struct V_39 * V_53 = & V_34 -> V_54 . V_40 ;
struct V_71 * V_72 ;
const T_1 V_50 = sizeof( struct V_71 ) ;
int V_56 ;
F_11 ( V_53 , V_50 ) ;
V_72 = (struct V_71 * ) V_34 -> V_54 . V_55 ;
memset ( V_72 , 0 , V_50 ) ;
V_72 -> V_48 = V_73 ;
V_72 -> V_74 |= V_34 -> V_75 ?
V_76 : 0 ;
V_72 -> V_74 |= V_34 -> V_77 ?
V_78 : 0 ;
V_56 = F_16 ( V_34 , V_53 , V_34 -> V_54 . V_55 ) ;
if ( V_56 ) {
F_25 ( V_34 -> V_34 , L_4 ,
V_56 ) ;
return V_56 ;
}
V_34 -> V_36 = V_79 ;
V_34 -> V_35 = V_70 ;
return 0 ;
}
static int F_28 ( struct V_33 * V_34 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 ;
const T_3 * V_84 = & V_81 -> V_85 . V_86 ;
F_29 ( V_34 , V_84 ) ;
V_83 = F_30 ( sizeof( struct V_82 ) , V_87 ) ;
if ( ! V_83 )
return - V_88 ;
F_31 ( V_83 ) ;
V_83 -> V_89 = V_81 -> V_85 ;
V_83 -> V_90 = V_81 -> V_43 ;
V_83 -> V_91 = 0 ;
F_32 ( V_34 , V_83 ) ;
return 0 ;
}
static int F_33 ( struct V_33 * V_34 , T_2 V_92 , T_2 V_2 )
{
struct V_39 * V_53 = & V_34 -> V_54 . V_40 ;
struct V_93 * V_94 ;
const T_1 V_50 = sizeof( struct V_93 ) ;
int V_56 ;
F_34 ( V_34 -> V_34 , L_5 ) ;
V_94 = (struct V_93 * ) V_34 -> V_54 . V_55 ;
F_11 ( V_53 , V_50 ) ;
memset ( V_94 , 0 , sizeof( struct V_93 ) ) ;
V_94 -> V_48 = V_95 ;
V_94 -> V_43 = V_92 ;
V_94 -> V_2 = V_2 ;
V_56 = F_16 ( V_34 , V_53 , V_34 -> V_54 . V_55 ) ;
if ( V_56 )
F_25 ( V_34 -> V_34 , L_6 ,
V_56 ) ;
return V_56 ;
}
static int F_35 ( struct V_33 * V_34 ,
struct V_96 * V_97 )
{
int V_56 ;
T_2 V_2 = V_98 ;
F_36 ( sizeof( struct V_96 ) !=
sizeof( struct V_80 ) ) ;
V_56 = F_28 ( V_34 , (struct V_80 * ) V_97 ) ;
if ( V_56 )
V_2 = ! V_98 ;
if ( V_34 -> V_99 == V_100 )
F_37 ( & V_34 -> V_101 ) ;
return F_33 ( V_34 , V_97 -> V_43 , V_2 ) ;
}
int F_38 ( struct V_33 * V_34 ,
struct V_46 * V_47 , T_2 V_102 )
{
struct V_39 * V_53 = & V_34 -> V_54 . V_40 ;
struct V_103 * V_97 ;
const T_1 V_50 = sizeof( struct V_103 ) ;
int V_56 ;
F_11 ( V_53 , V_50 ) ;
F_12 ( V_47 , V_104 , V_34 -> V_54 . V_55 , V_50 ) ;
V_97 = (struct V_103 * ) V_34 -> V_54 . V_55 ;
V_97 -> V_102 = V_102 ;
V_56 = F_16 ( V_34 , V_53 , V_34 -> V_54 . V_55 ) ;
if ( V_56 )
F_25 ( V_34 -> V_34 , L_7 , V_56 ) ;
return V_56 ;
}
static inline enum V_105 F_39 ( struct V_51 * V_52 )
{
struct V_106 * V_107 =
(struct V_106 * ) V_52 ;
return F_40 ( V_107 -> V_102 ) ;
}
static void F_41 ( struct V_33 * V_34 ,
struct V_46 * V_47 ,
struct V_51 * V_52 )
{
struct V_106 * V_107 =
(struct V_106 * ) V_52 ;
F_42 ( V_34 , V_47 , L_8 , V_107 -> V_2 ) ;
if ( V_107 -> V_2 == V_98 ||
V_107 -> V_2 == V_108 ) {
V_47 -> V_109 = true ;
V_47 -> V_2 = 0 ;
} else {
V_47 -> V_2 = - V_31 ;
}
}
static void F_43 ( struct V_33 * V_34 ,
struct V_46 * V_47 ,
struct V_51 * V_52 )
{
struct V_106 * V_107 =
(struct V_106 * ) V_52 ;
F_42 ( V_34 , V_47 , L_9 , V_107 -> V_2 ) ;
if ( V_107 -> V_2 == V_98 ||
V_107 -> V_2 == V_110 ) {
V_47 -> V_109 = false ;
V_47 -> V_2 = 0 ;
} else {
V_47 -> V_2 = - V_31 ;
}
}
static void F_44 ( struct V_33 * V_34 ,
struct V_51 * V_52 )
{
struct V_46 * V_47 ;
V_47 = F_18 ( V_34 , V_52 ) ;
if ( V_47 )
F_45 ( V_47 ) ;
}
static int F_46 ( struct V_33 * V_34 )
{
struct V_39 * V_53 = & V_34 -> V_54 . V_40 ;
struct V_111 * V_112 ;
const T_1 V_50 = sizeof( struct V_111 ) ;
unsigned long V_113 ;
int V_56 ;
V_113 = F_47 ( V_34 -> V_114 , V_115 ,
V_34 -> V_38 ) ;
if ( V_113 == V_115 ) {
V_34 -> V_36 = V_116 ;
F_48 ( V_34 ) ;
return 0 ;
}
F_11 ( V_53 , V_50 ) ;
V_112 = (struct V_111 * ) V_34 -> V_54 . V_55 ;
memset ( V_112 , 0 , sizeof( struct V_111 ) ) ;
V_112 -> V_48 = V_117 ;
V_112 -> V_43 = V_113 ;
V_56 = F_16 ( V_34 , V_53 , V_34 -> V_54 . V_55 ) ;
if ( V_56 ) {
F_25 ( V_34 -> V_34 , L_10 ,
V_56 ) ;
return V_56 ;
}
V_34 -> V_35 = V_70 ;
V_34 -> V_38 = V_113 ;
return 0 ;
}
int F_49 ( struct V_33 * V_34 , T_2 V_118 )
{
struct V_39 * V_53 = & V_34 -> V_54 . V_40 ;
struct V_119 * V_97 ;
const T_1 V_50 = sizeof( struct V_119 ) ;
int V_56 ;
if ( ! V_34 -> V_120 )
return - V_121 ;
F_11 ( V_53 , V_50 ) ;
V_97 = (struct V_119 * ) V_34 -> V_54 . V_55 ;
memset ( V_97 , 0 , V_50 ) ;
V_97 -> V_48 = V_118 ;
V_56 = F_16 ( V_34 , V_53 , V_34 -> V_54 . V_55 ) ;
if ( V_56 )
F_25 ( V_34 -> V_34 , L_11 ) ;
return V_56 ;
}
static int F_50 ( struct V_33 * V_34 )
{
struct V_39 * V_53 = & V_34 -> V_54 . V_40 ;
struct V_122 * V_97 =
(struct V_122 * ) V_34 -> V_54 . V_55 ;
const T_1 V_50 = sizeof( struct V_122 ) ;
F_11 ( V_53 , V_50 ) ;
memset ( V_97 , 0 , V_50 ) ;
V_97 -> V_48 = V_123 ;
V_97 -> V_124 = V_125 ;
return F_16 ( V_34 , V_53 , V_34 -> V_54 . V_55 ) ;
}
int F_51 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
const T_1 V_50 = sizeof( struct V_126 ) ;
F_42 ( V_34 , V_47 , L_12 ) ;
return F_15 ( V_34 , V_47 , V_127 , V_50 ) ;
}
static int F_52 ( struct V_33 * V_34 ,
struct V_126 * V_128 )
{
struct V_82 * V_83 ;
int V_129 ;
V_83 = F_53 ( V_34 , V_128 -> V_43 ) ;
if ( ! V_83 ) {
F_25 ( V_34 -> V_34 , L_13 ,
V_128 -> V_43 ) ;
return - V_130 ;
}
if ( F_54 ( V_83 -> V_89 . V_131 == 0 ) ) {
V_129 = - V_31 ;
goto V_132;
}
V_83 -> V_91 ++ ;
F_34 ( V_34 -> V_34 , L_14 ,
V_128 -> V_43 , V_83 -> V_91 ) ;
V_129 = 0 ;
V_132:
F_55 ( V_83 ) ;
return V_129 ;
}
static void F_56 ( struct V_33 * V_34 ,
struct V_126 * V_133 )
{
struct V_46 * V_47 ;
if ( ! V_133 -> V_42 ) {
F_52 ( V_34 , V_133 ) ;
return;
}
V_47 = F_18 ( V_34 , V_133 ) ;
if ( V_47 ) {
V_47 -> V_91 ++ ;
F_42 ( V_34 , V_47 , L_15 ,
V_47 -> V_91 ) ;
}
}
int F_57 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
const T_1 V_50 = sizeof( struct V_134 ) ;
return F_15 ( V_34 , V_47 , V_135 , V_50 ) ;
}
int F_58 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
const T_1 V_50 = sizeof( struct V_136 ) ;
return F_15 ( V_34 , V_47 , V_137 , V_50 ) ;
}
static void F_59 ( struct V_33 * V_34 , struct V_46 * V_47 ,
struct V_51 * V_52 )
{
struct V_136 * V_107 =
(struct V_136 * ) V_52 ;
F_42 ( V_34 , V_47 , L_16 , V_107 -> V_2 ) ;
if ( V_107 -> V_2 == V_138 )
V_47 -> V_17 = V_139 ;
V_47 -> V_2 = 0 ;
}
int F_60 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
const T_1 V_50 = sizeof( struct V_134 ) ;
return F_15 ( V_34 , V_47 , V_140 , V_50 ) ;
}
static void F_61 ( struct V_33 * V_34 , struct V_46 * V_47 ,
struct V_51 * V_52 )
{
struct V_136 * V_107 =
(struct V_136 * ) V_52 ;
F_42 ( V_34 , V_47 , L_17 ,
F_3 ( V_107 -> V_2 ) ) ;
if ( V_107 -> V_2 == V_24 )
V_47 -> V_17 = V_141 ;
else {
V_47 -> V_17 = V_139 ;
if ( V_107 -> V_2 == V_25 ) {
F_62 ( V_34 , V_47 -> V_83 ) ;
if ( V_34 -> V_99 == V_100 )
F_37 ( & V_34 -> V_101 ) ;
}
}
V_47 -> V_2 = F_7 ( V_107 -> V_2 ) ;
}
static void F_63 ( struct V_33 * V_34 ,
struct V_51 * V_107 ,
enum V_105 V_142 )
{
struct V_46 * V_47 ;
struct V_143 * V_144 , * V_145 ;
V_47 = NULL ;
F_64 (cb, next, &dev->ctrl_rd_list.list, list) {
V_47 = V_144 -> V_47 ;
if ( V_144 -> V_142 != V_142 )
continue;
if ( F_17 ( V_47 , V_107 ) ) {
F_65 ( & V_144 -> V_146 ) ;
break;
}
}
if ( ! V_47 )
return;
switch ( V_142 ) {
case V_147 :
F_61 ( V_34 , V_47 , V_107 ) ;
break;
case V_148 :
F_59 ( V_34 , V_47 , V_107 ) ;
break;
case V_149 :
F_41 ( V_34 , V_47 , V_107 ) ;
break;
case V_150 :
F_43 ( V_34 , V_47 , V_107 ) ;
break;
default:
return;
}
V_47 -> V_151 = 0 ;
F_66 ( & V_47 -> V_152 ) ;
}
static int F_67 ( struct V_33 * V_34 ,
struct V_134 * V_153 )
{
struct V_46 * V_47 ;
struct V_143 * V_144 ;
V_47 = F_18 ( V_34 , V_153 ) ;
if ( V_47 ) {
F_68 ( V_34 , V_47 , L_18 ) ;
V_47 -> V_17 = V_154 ;
V_47 -> V_151 = 0 ;
V_144 = F_69 ( V_47 , V_155 , NULL ) ;
if ( ! V_144 )
return - V_88 ;
F_42 ( V_34 , V_47 , L_19 ) ;
F_70 ( & V_144 -> V_146 , & V_34 -> V_156 . V_146 ) ;
}
return 0 ;
}
static int F_71 ( struct V_33 * V_34 )
{
if ( F_72 ( V_34 ) != V_157 ||
V_34 -> V_158 != V_159 ) {
F_25 ( V_34 -> V_34 , L_20 ,
F_73 ( F_72 ( V_34 ) ) , V_34 -> V_158 ) ;
return - V_160 ;
}
V_34 -> V_158 = V_161 ;
F_66 ( & V_34 -> V_162 ) ;
return 0 ;
}
void F_74 ( struct V_33 * V_34 )
{
F_75 ( V_34 -> V_34 ) ;
}
static int F_76 ( struct V_33 * V_34 )
{
if ( F_72 ( V_34 ) != V_163 ||
( V_34 -> V_158 != V_159 &&
V_34 -> V_158 != V_164 ) ) {
F_25 ( V_34 -> V_34 , L_21 ,
F_73 ( F_72 ( V_34 ) ) , V_34 -> V_158 ) ;
return - V_160 ;
}
switch ( V_34 -> V_158 ) {
case V_159 :
V_34 -> V_158 = V_161 ;
F_66 ( & V_34 -> V_162 ) ;
break;
case V_164 :
V_34 -> V_158 = V_161 ;
F_74 ( V_34 ) ;
break;
default:
F_77 ( 1 , L_22 ,
V_34 -> V_158 ) ;
return - V_160 ;
}
return 0 ;
}
static void F_78 ( struct V_33 * V_34 )
{
V_34 -> V_120 = 0 ;
if ( V_34 -> V_165 . V_66 > V_166 )
V_34 -> V_120 = 1 ;
if ( V_34 -> V_165 . V_66 == V_166 &&
V_34 -> V_165 . V_68 >= V_167 )
V_34 -> V_120 = 1 ;
if ( V_34 -> V_165 . V_66 >= V_168 )
V_34 -> V_75 = 1 ;
if ( V_34 -> V_165 . V_66 >= V_169 )
V_34 -> V_77 = 1 ;
if ( V_34 -> V_165 . V_66 >= V_170 )
V_34 -> V_171 = 1 ;
if ( V_34 -> V_165 . V_66 >= V_172 )
V_34 -> V_173 = 1 ;
if ( V_34 -> V_165 . V_66 >= V_174 )
V_34 -> V_175 = 1 ;
}
bool F_79 ( struct V_33 * V_34 )
{
return ( V_34 -> V_165 . V_66 < V_67 ) ||
( V_34 -> V_165 . V_66 == V_67 &&
V_34 -> V_165 . V_68 <= V_69 ) ;
}
int F_80 ( struct V_33 * V_34 , struct V_39 * V_40 )
{
struct V_176 * V_177 ;
struct V_178 * V_179 ;
struct V_80 * V_180 ;
struct V_181 * V_182 ;
struct V_96 * V_183 ;
int V_56 ;
struct V_51 * V_184 ;
struct V_134 * V_153 ;
struct V_126 * V_133 ;
F_81 ( V_40 -> V_41 >= sizeof( V_34 -> V_185 ) ) ;
F_82 ( V_34 , V_34 -> V_185 , V_40 -> V_41 ) ;
V_177 = (struct V_176 * ) V_34 -> V_185 ;
V_184 = (struct V_51 * ) V_177 ;
if ( V_34 -> V_36 == V_37 ) {
F_34 ( V_34 -> V_34 , L_23 ) ;
return 0 ;
}
switch ( V_177 -> V_48 ) {
case V_186 :
F_34 ( V_34 -> V_34 , L_24 ) ;
V_34 -> V_35 = 0 ;
V_179 = (struct V_178 * ) V_177 ;
F_34 ( V_34 -> V_34 , L_25 ,
V_67 , V_69 ,
V_179 -> V_187 . V_66 ,
V_179 -> V_187 . V_68 ) ;
if ( V_179 -> V_188 ) {
V_34 -> V_165 . V_66 = V_67 ;
V_34 -> V_165 . V_68 = V_69 ;
} else {
V_34 -> V_165 . V_66 =
V_179 -> V_187 . V_66 ;
V_34 -> V_165 . V_68 =
V_179 -> V_187 . V_68 ;
}
if ( ! F_79 ( V_34 ) ) {
F_83 ( V_34 -> V_34 , L_26 ) ;
V_34 -> V_36 = V_189 ;
if ( F_50 ( V_34 ) ) {
F_25 ( V_34 -> V_34 , L_27 ) ;
return - V_190 ;
}
break;
}
F_78 ( V_34 ) ;
if ( V_34 -> V_99 != V_191 ||
V_34 -> V_36 != V_57 ) {
F_25 ( V_34 -> V_34 , L_28 ,
V_34 -> V_99 , V_34 -> V_36 ) ;
return - V_160 ;
}
if ( F_27 ( V_34 ) ) {
F_25 ( V_34 -> V_34 , L_29 ) ;
return - V_190 ;
}
F_66 ( & V_34 -> V_59 ) ;
break;
case V_192 :
F_34 ( V_34 -> V_34 , L_30 ) ;
F_63 ( V_34 , V_184 , V_147 ) ;
break;
case V_137 :
F_34 ( V_34 -> V_34 , L_31 ) ;
F_63 ( V_34 , V_184 , V_148 ) ;
break;
case V_127 :
F_34 ( V_34 -> V_34 , L_32 ) ;
V_133 = (struct V_126 * ) V_177 ;
F_56 ( V_34 , V_133 ) ;
break;
case V_193 :
F_34 ( V_34 -> V_34 , L_33 ) ;
V_56 = F_71 ( V_34 ) ;
if ( V_56 )
return V_56 ;
break;
case V_194 :
F_34 ( V_34 -> V_34 , L_34 ) ;
V_56 = F_76 ( V_34 ) ;
if ( V_56 )
return V_56 ;
break;
case V_195 :
F_34 ( V_34 -> V_34 , L_35 ) ;
V_34 -> V_35 = 0 ;
if ( V_34 -> V_99 != V_191 ||
V_34 -> V_36 != V_196 ) {
F_25 ( V_34 -> V_34 , L_36 ,
V_34 -> V_99 , V_34 -> V_36 ) ;
return - V_160 ;
}
V_180 = (struct V_80 * ) V_177 ;
if ( V_180 -> V_2 ) {
F_25 ( V_34 -> V_34 , L_37 ,
V_180 -> V_2 ,
F_1 ( V_180 -> V_2 ) ) ;
return - V_160 ;
}
F_28 ( V_34 , V_180 ) ;
V_34 -> V_38 ++ ;
if ( F_46 ( V_34 ) )
return - V_190 ;
break;
case V_197 :
F_34 ( V_34 -> V_34 , L_38 ) ;
V_34 -> V_35 = 0 ;
V_182 = (struct V_181 * ) V_177 ;
F_36 ( sizeof( V_34 -> V_114 )
< sizeof( V_182 -> V_198 ) ) ;
memcpy ( V_34 -> V_114 , V_182 -> V_198 ,
sizeof( V_182 -> V_198 ) ) ;
if ( V_34 -> V_99 != V_191 ||
V_34 -> V_36 != V_79 ) {
F_25 ( V_34 -> V_34 , L_39 ,
V_34 -> V_99 , V_34 -> V_36 ) ;
return - V_160 ;
}
V_34 -> V_36 = V_196 ;
if ( F_46 ( V_34 ) )
return - V_190 ;
break;
case V_199 :
F_34 ( V_34 -> V_34 , L_40 ) ;
V_34 -> V_35 = 0 ;
if ( V_34 -> V_36 != V_189 ) {
F_25 ( V_34 -> V_34 , L_41 ,
V_34 -> V_99 , V_34 -> V_36 ) ;
return - V_160 ;
}
V_34 -> V_99 = V_200 ;
F_84 ( V_34 -> V_34 , L_42 ) ;
return - V_160 ;
break;
case V_135 :
F_34 ( V_34 -> V_34 , L_43 ) ;
V_153 = (struct V_134 * ) V_177 ;
F_67 ( V_34 , V_153 ) ;
break;
case V_201 :
F_34 ( V_34 -> V_34 , L_44 ) ;
V_34 -> V_36 = V_189 ;
if ( F_50 ( V_34 ) ) {
F_25 ( V_34 -> V_34 , L_45 ) ;
return - V_190 ;
}
break;
case V_202 :
F_34 ( V_34 -> V_34 , L_46 ) ;
if ( V_34 -> V_36 <= V_79 ||
V_34 -> V_36 >= V_189 ) {
F_25 ( V_34 -> V_34 , L_47 ,
V_34 -> V_99 , V_34 -> V_36 ) ;
return - V_160 ;
}
V_183 = (struct V_96 * ) V_177 ;
V_56 = F_35 ( V_34 , V_183 ) ;
if ( V_56 ) {
F_25 ( V_34 -> V_34 , L_48 ,
V_56 ) ;
return - V_190 ;
}
F_34 ( V_34 -> V_34 , L_49 ) ;
break;
case V_203 :
F_34 ( V_34 -> V_34 , L_50 ) ;
F_63 ( V_34 , V_184 , F_39 ( V_184 ) ) ;
break;
case V_204 :
F_34 ( V_34 -> V_34 , L_51 ) ;
F_44 ( V_34 , V_184 ) ;
break;
default:
F_85 () ;
break;
}
return 0 ;
}
