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
F_10 ( V_34 ) ;
F_8 ( V_34 ) ;
}
static inline void F_11 ( struct V_38 * V_39 , T_1 V_40 )
{
V_39 -> V_41 = 0 ;
V_39 -> V_42 = 0 ;
V_39 -> V_40 = V_40 ;
V_39 -> V_43 = 1 ;
V_39 -> V_44 = 0 ;
}
static inline
void F_12 ( struct V_45 * V_46 , T_2 V_47 , void * V_48 , T_1 V_49 )
{
struct V_50 * V_51 = V_48 ;
memset ( V_51 , 0 , V_49 ) ;
V_51 -> V_47 = V_47 ;
V_51 -> V_41 = F_13 ( V_46 ) ;
V_51 -> V_42 = F_14 ( V_46 ) ;
}
static inline
int F_15 ( struct V_33 * V_34 ,
struct V_45 * V_46 , T_2 V_47 , T_1 V_49 )
{
struct V_38 * V_52 = & V_34 -> V_53 . V_39 ;
F_11 ( V_52 , V_49 ) ;
F_12 ( V_46 , V_47 , V_34 -> V_53 . V_54 , V_49 ) ;
return F_16 ( V_34 , V_52 , V_34 -> V_53 . V_54 ) ;
}
static inline
bool F_17 ( struct V_45 * V_46 , struct V_50 * V_51 )
{
return F_13 ( V_46 ) == V_51 -> V_41 &&
F_14 ( V_46 ) == V_51 -> V_42 ;
}
static inline
struct V_45 * F_18 ( struct V_33 * V_34 , void * V_48 )
{
struct V_50 * V_51 = (struct V_50 * ) V_48 ;
struct V_45 * V_46 ;
F_19 (cl, &dev->file_list, link)
if ( F_17 ( V_46 , V_51 ) )
return V_46 ;
return NULL ;
}
int F_20 ( struct V_33 * V_34 )
{
int V_55 ;
if ( V_34 -> V_36 > V_56 )
return 0 ;
F_21 ( & V_34 -> V_57 ) ;
V_55 = F_22 ( V_34 -> V_58 ,
V_34 -> V_36 != V_56 ,
F_23 ( V_59 ) ) ;
F_24 ( & V_34 -> V_57 ) ;
if ( V_55 == 0 && ( V_34 -> V_36 <= V_56 ) ) {
V_34 -> V_36 = V_37 ;
F_25 ( V_34 -> V_34 , L_2 ) ;
return - V_60 ;
}
return 0 ;
}
int F_26 ( struct V_33 * V_34 )
{
struct V_38 * V_52 = & V_34 -> V_53 . V_39 ;
struct V_61 * V_62 ;
const T_1 V_49 = sizeof( struct V_61 ) ;
int V_55 ;
F_9 ( V_34 ) ;
F_11 ( V_52 , V_49 ) ;
V_62 = (struct V_61 * ) V_34 -> V_53 . V_54 ;
memset ( V_62 , 0 , V_49 ) ;
V_62 -> V_47 = V_63 ;
V_62 -> V_64 . V_65 = V_66 ;
V_62 -> V_64 . V_67 = V_68 ;
V_34 -> V_36 = V_37 ;
V_55 = F_16 ( V_34 , V_52 , V_34 -> V_53 . V_54 ) ;
if ( V_55 ) {
F_25 ( V_34 -> V_34 , L_3 ,
V_55 ) ;
return V_55 ;
}
V_34 -> V_36 = V_56 ;
V_34 -> V_35 = V_69 ;
return 0 ;
}
static int F_27 ( struct V_33 * V_34 )
{
struct V_38 * V_52 = & V_34 -> V_53 . V_39 ;
struct V_70 * V_71 ;
const T_1 V_49 = sizeof( struct V_70 ) ;
int V_55 ;
F_11 ( V_52 , V_49 ) ;
V_71 = (struct V_70 * ) V_34 -> V_53 . V_54 ;
memset ( V_71 , 0 , V_49 ) ;
V_71 -> V_47 = V_72 ;
V_71 -> V_73 |= V_34 -> V_74 ?
V_75 : 0 ;
V_71 -> V_73 |= V_34 -> V_76 ?
V_77 : 0 ;
V_55 = F_16 ( V_34 , V_52 , V_34 -> V_53 . V_54 ) ;
if ( V_55 ) {
F_25 ( V_34 -> V_34 , L_4 ,
V_55 ) ;
return V_55 ;
}
V_34 -> V_36 = V_78 ;
V_34 -> V_35 = V_69 ;
return 0 ;
}
static int F_28 ( struct V_33 * V_34 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 ;
const T_3 * V_83 = & V_80 -> V_84 . V_85 ;
F_29 ( V_34 , V_83 ) ;
V_82 = F_30 ( sizeof( struct V_81 ) , V_86 ) ;
if ( ! V_82 )
return - V_87 ;
F_31 ( V_82 ) ;
V_82 -> V_88 = V_80 -> V_84 ;
V_82 -> V_89 = V_80 -> V_42 ;
V_82 -> V_90 = 0 ;
F_32 ( V_34 , V_82 ) ;
return 0 ;
}
static int F_33 ( struct V_33 * V_34 , T_2 V_91 , T_2 V_2 )
{
struct V_38 * V_52 = & V_34 -> V_53 . V_39 ;
struct V_92 * V_93 ;
const T_1 V_49 = sizeof( struct V_92 ) ;
int V_55 ;
F_34 ( V_34 -> V_34 , L_5 ) ;
V_93 = (struct V_92 * ) V_34 -> V_53 . V_54 ;
F_11 ( V_52 , V_49 ) ;
memset ( V_93 , 0 , sizeof( struct V_92 ) ) ;
V_93 -> V_47 = V_94 ;
V_93 -> V_42 = V_91 ;
V_93 -> V_2 = V_2 ;
V_55 = F_16 ( V_34 , V_52 , V_34 -> V_53 . V_54 ) ;
if ( V_55 )
F_25 ( V_34 -> V_34 , L_6 ,
V_55 ) ;
return V_55 ;
}
static int F_35 ( struct V_33 * V_34 ,
struct V_95 * V_96 )
{
int V_55 ;
T_2 V_2 = V_97 ;
F_36 ( sizeof( struct V_95 ) !=
sizeof( struct V_79 ) ) ;
V_55 = F_28 ( V_34 , (struct V_79 * ) V_96 ) ;
if ( V_55 )
V_2 = ! V_97 ;
if ( V_34 -> V_98 == V_99 )
F_37 ( & V_34 -> V_100 ) ;
return F_33 ( V_34 , V_96 -> V_42 , V_2 ) ;
}
int F_38 ( struct V_33 * V_34 ,
struct V_45 * V_46 , T_2 V_101 )
{
struct V_38 * V_52 = & V_34 -> V_53 . V_39 ;
struct V_102 * V_96 ;
const T_1 V_49 = sizeof( struct V_102 ) ;
int V_55 ;
F_11 ( V_52 , V_49 ) ;
F_12 ( V_46 , V_103 , V_34 -> V_53 . V_54 , V_49 ) ;
V_96 = (struct V_102 * ) V_34 -> V_53 . V_54 ;
V_96 -> V_101 = V_101 ;
V_55 = F_16 ( V_34 , V_52 , V_34 -> V_53 . V_54 ) ;
if ( V_55 )
F_25 ( V_34 -> V_34 , L_7 , V_55 ) ;
return V_55 ;
}
static inline enum V_104 F_39 ( struct V_50 * V_51 )
{
struct V_105 * V_106 =
(struct V_105 * ) V_51 ;
return F_40 ( V_106 -> V_101 ) ;
}
static void F_41 ( struct V_33 * V_34 ,
struct V_45 * V_46 ,
struct V_50 * V_51 )
{
struct V_105 * V_106 =
(struct V_105 * ) V_51 ;
F_42 ( V_34 , V_46 , L_8 , V_106 -> V_2 ) ;
if ( V_106 -> V_2 == V_97 ||
V_106 -> V_2 == V_107 ) {
V_46 -> V_108 = true ;
V_46 -> V_2 = 0 ;
} else {
V_46 -> V_2 = - V_31 ;
}
}
static void F_43 ( struct V_33 * V_34 ,
struct V_45 * V_46 ,
struct V_50 * V_51 )
{
struct V_105 * V_106 =
(struct V_105 * ) V_51 ;
F_42 ( V_34 , V_46 , L_9 , V_106 -> V_2 ) ;
if ( V_106 -> V_2 == V_97 ||
V_106 -> V_2 == V_109 ) {
V_46 -> V_108 = false ;
V_46 -> V_2 = 0 ;
} else {
V_46 -> V_2 = - V_31 ;
}
}
static void F_44 ( struct V_33 * V_34 ,
struct V_50 * V_51 )
{
struct V_45 * V_46 ;
V_46 = F_18 ( V_34 , V_51 ) ;
if ( V_46 )
F_45 ( V_46 ) ;
}
static int F_46 ( struct V_33 * V_34 , unsigned long V_110 )
{
struct V_38 * V_52 = & V_34 -> V_53 . V_39 ;
struct V_111 * V_112 ;
const T_1 V_49 = sizeof( struct V_111 ) ;
unsigned long V_91 ;
int V_55 ;
V_91 = F_47 ( V_34 -> V_113 , V_114 , V_110 ) ;
if ( V_91 == V_114 ) {
V_34 -> V_36 = V_115 ;
F_48 ( V_34 ) ;
return 0 ;
}
F_11 ( V_52 , V_49 ) ;
V_112 = (struct V_111 * ) V_34 -> V_53 . V_54 ;
memset ( V_112 , 0 , sizeof( struct V_111 ) ) ;
V_112 -> V_47 = V_116 ;
V_112 -> V_42 = V_91 ;
V_55 = F_16 ( V_34 , V_52 , V_34 -> V_53 . V_54 ) ;
if ( V_55 ) {
F_25 ( V_34 -> V_34 , L_10 ,
V_55 ) ;
return V_55 ;
}
V_34 -> V_35 = V_69 ;
return 0 ;
}
int F_49 ( struct V_33 * V_34 , T_2 V_117 )
{
struct V_38 * V_52 = & V_34 -> V_53 . V_39 ;
struct V_118 * V_96 ;
const T_1 V_49 = sizeof( struct V_118 ) ;
int V_55 ;
if ( ! V_34 -> V_119 )
return - V_120 ;
F_11 ( V_52 , V_49 ) ;
V_96 = (struct V_118 * ) V_34 -> V_53 . V_54 ;
memset ( V_96 , 0 , V_49 ) ;
V_96 -> V_47 = V_117 ;
V_55 = F_16 ( V_34 , V_52 , V_34 -> V_53 . V_54 ) ;
if ( V_55 )
F_25 ( V_34 -> V_34 , L_11 ) ;
return V_55 ;
}
static int F_50 ( struct V_33 * V_34 )
{
struct V_38 * V_52 = & V_34 -> V_53 . V_39 ;
struct V_121 * V_96 =
(struct V_121 * ) V_34 -> V_53 . V_54 ;
const T_1 V_49 = sizeof( struct V_121 ) ;
F_11 ( V_52 , V_49 ) ;
memset ( V_96 , 0 , V_49 ) ;
V_96 -> V_47 = V_122 ;
V_96 -> V_123 = V_124 ;
return F_16 ( V_34 , V_52 , V_34 -> V_53 . V_54 ) ;
}
int F_51 ( struct V_33 * V_34 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_125 ) ;
F_42 ( V_34 , V_46 , L_12 ) ;
return F_15 ( V_34 , V_46 , V_126 , V_49 ) ;
}
static int F_52 ( struct V_33 * V_34 ,
struct V_125 * V_127 )
{
struct V_81 * V_82 ;
int V_128 ;
V_82 = F_53 ( V_34 , V_127 -> V_42 ) ;
if ( ! V_82 ) {
F_25 ( V_34 -> V_34 , L_13 ,
V_127 -> V_42 ) ;
return - V_129 ;
}
if ( F_54 ( V_82 -> V_88 . V_130 == 0 ) ) {
V_128 = - V_31 ;
goto V_131;
}
V_82 -> V_90 ++ ;
F_34 ( V_34 -> V_34 , L_14 ,
V_127 -> V_42 , V_82 -> V_90 ) ;
V_128 = 0 ;
V_131:
F_55 ( V_82 ) ;
return V_128 ;
}
static void F_56 ( struct V_33 * V_34 ,
struct V_125 * V_132 )
{
struct V_45 * V_46 ;
if ( ! V_132 -> V_41 ) {
F_52 ( V_34 , V_132 ) ;
return;
}
V_46 = F_18 ( V_34 , V_132 ) ;
if ( V_46 ) {
V_46 -> V_90 ++ ;
F_42 ( V_34 , V_46 , L_15 ,
V_46 -> V_90 ) ;
}
}
int F_57 ( struct V_33 * V_34 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_133 ) ;
return F_15 ( V_34 , V_46 , V_134 , V_49 ) ;
}
int F_58 ( struct V_33 * V_34 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_135 ) ;
return F_15 ( V_34 , V_46 , V_136 , V_49 ) ;
}
static void F_59 ( struct V_33 * V_34 , struct V_45 * V_46 ,
struct V_50 * V_51 )
{
struct V_135 * V_106 =
(struct V_135 * ) V_51 ;
F_42 ( V_34 , V_46 , L_16 , V_106 -> V_2 ) ;
if ( V_106 -> V_2 == V_137 )
V_46 -> V_17 = V_138 ;
V_46 -> V_2 = 0 ;
}
int F_60 ( struct V_33 * V_34 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_133 ) ;
return F_15 ( V_34 , V_46 , V_139 , V_49 ) ;
}
static void F_61 ( struct V_33 * V_34 , struct V_45 * V_46 ,
struct V_50 * V_51 )
{
struct V_135 * V_106 =
(struct V_135 * ) V_51 ;
F_42 ( V_34 , V_46 , L_17 ,
F_3 ( V_106 -> V_2 ) ) ;
if ( V_106 -> V_2 == V_24 )
V_46 -> V_17 = V_140 ;
else {
V_46 -> V_17 = V_138 ;
if ( V_106 -> V_2 == V_25 ) {
F_62 ( V_34 , V_46 -> V_82 ) ;
if ( V_34 -> V_98 == V_99 )
F_37 ( & V_34 -> V_100 ) ;
}
}
V_46 -> V_2 = F_7 ( V_106 -> V_2 ) ;
}
static void F_63 ( struct V_33 * V_34 ,
struct V_50 * V_106 ,
enum V_104 V_141 )
{
struct V_45 * V_46 ;
struct V_142 * V_143 , * V_144 ;
V_46 = NULL ;
F_64 (cb, next, &dev->ctrl_rd_list.list, list) {
V_46 = V_143 -> V_46 ;
if ( V_143 -> V_141 != V_141 )
continue;
if ( F_17 ( V_46 , V_106 ) ) {
F_65 ( & V_143 -> V_145 ) ;
break;
}
}
if ( ! V_46 )
return;
switch ( V_141 ) {
case V_146 :
F_61 ( V_34 , V_46 , V_106 ) ;
break;
case V_147 :
F_59 ( V_34 , V_46 , V_106 ) ;
break;
case V_148 :
F_41 ( V_34 , V_46 , V_106 ) ;
break;
case V_149 :
F_43 ( V_34 , V_46 , V_106 ) ;
break;
default:
return;
}
V_46 -> V_150 = 0 ;
F_66 ( & V_46 -> V_151 ) ;
}
static int F_67 ( struct V_33 * V_34 ,
struct V_133 * V_152 )
{
struct V_45 * V_46 ;
struct V_142 * V_143 ;
V_46 = F_18 ( V_34 , V_152 ) ;
if ( V_46 ) {
F_68 ( V_34 , V_46 , L_18 ) ;
V_46 -> V_17 = V_153 ;
V_46 -> V_150 = 0 ;
V_143 = F_69 ( V_46 , V_154 , NULL ) ;
if ( ! V_143 )
return - V_87 ;
F_70 ( & V_143 -> V_145 , & V_34 -> V_155 . V_145 ) ;
}
return 0 ;
}
static int F_71 ( struct V_33 * V_34 )
{
if ( F_72 ( V_34 ) != V_156 ||
V_34 -> V_157 != V_158 ) {
F_25 ( V_34 -> V_34 , L_19 ,
F_73 ( F_72 ( V_34 ) ) , V_34 -> V_157 ) ;
return - V_159 ;
}
V_34 -> V_157 = V_160 ;
F_66 ( & V_34 -> V_161 ) ;
return 0 ;
}
void F_74 ( struct V_33 * V_34 )
{
F_75 ( V_34 -> V_34 ) ;
}
static int F_76 ( struct V_33 * V_34 )
{
if ( F_72 ( V_34 ) != V_162 ||
( V_34 -> V_157 != V_158 &&
V_34 -> V_157 != V_163 ) ) {
F_25 ( V_34 -> V_34 , L_20 ,
F_73 ( F_72 ( V_34 ) ) , V_34 -> V_157 ) ;
return - V_159 ;
}
switch ( V_34 -> V_157 ) {
case V_158 :
V_34 -> V_157 = V_160 ;
F_66 ( & V_34 -> V_161 ) ;
break;
case V_163 :
V_34 -> V_157 = V_160 ;
F_74 ( V_34 ) ;
break;
default:
F_77 ( 1 , L_21 ,
V_34 -> V_157 ) ;
return - V_159 ;
}
return 0 ;
}
static void F_78 ( struct V_33 * V_34 )
{
V_34 -> V_119 = 0 ;
if ( V_34 -> V_164 . V_65 > V_165 )
V_34 -> V_119 = 1 ;
if ( V_34 -> V_164 . V_65 == V_165 &&
V_34 -> V_164 . V_67 >= V_166 )
V_34 -> V_119 = 1 ;
if ( V_34 -> V_164 . V_65 >= V_167 )
V_34 -> V_74 = 1 ;
if ( V_34 -> V_164 . V_65 >= V_168 )
V_34 -> V_76 = 1 ;
if ( V_34 -> V_164 . V_65 >= V_169 )
V_34 -> V_170 = 1 ;
if ( V_34 -> V_164 . V_65 >= V_171 )
V_34 -> V_172 = 1 ;
if ( V_34 -> V_164 . V_65 >= V_173 )
V_34 -> V_174 = 1 ;
}
bool F_79 ( struct V_33 * V_34 )
{
return ( V_34 -> V_164 . V_65 < V_66 ) ||
( V_34 -> V_164 . V_65 == V_66 &&
V_34 -> V_164 . V_67 <= V_68 ) ;
}
int F_80 ( struct V_33 * V_34 , struct V_38 * V_39 )
{
struct V_175 * V_176 ;
struct V_177 * V_178 ;
struct V_79 * V_179 ;
struct V_180 * V_181 ;
struct V_95 * V_182 ;
int V_55 ;
struct V_50 * V_183 ;
struct V_133 * V_152 ;
struct V_125 * V_132 ;
F_81 ( V_39 -> V_40 >= sizeof( V_34 -> V_184 ) ) ;
F_82 ( V_34 , V_34 -> V_184 , V_39 -> V_40 ) ;
V_176 = (struct V_175 * ) V_34 -> V_184 ;
V_183 = (struct V_50 * ) V_176 ;
if ( V_34 -> V_36 == V_37 ) {
F_34 ( V_34 -> V_34 , L_22 ) ;
return 0 ;
}
switch ( V_176 -> V_47 ) {
case V_185 :
F_34 ( V_34 -> V_34 , L_23 ) ;
V_34 -> V_35 = 0 ;
V_178 = (struct V_177 * ) V_176 ;
F_34 ( V_34 -> V_34 , L_24 ,
V_66 , V_68 ,
V_178 -> V_186 . V_65 ,
V_178 -> V_186 . V_67 ) ;
if ( V_178 -> V_187 ) {
V_34 -> V_164 . V_65 = V_66 ;
V_34 -> V_164 . V_67 = V_68 ;
} else {
V_34 -> V_164 . V_65 =
V_178 -> V_186 . V_65 ;
V_34 -> V_164 . V_67 =
V_178 -> V_186 . V_67 ;
}
if ( ! F_79 ( V_34 ) ) {
F_83 ( V_34 -> V_34 , L_25 ) ;
V_34 -> V_36 = V_188 ;
if ( F_50 ( V_34 ) ) {
F_25 ( V_34 -> V_34 , L_26 ) ;
return - V_189 ;
}
break;
}
F_78 ( V_34 ) ;
if ( V_34 -> V_98 != V_190 ||
V_34 -> V_36 != V_56 ) {
F_25 ( V_34 -> V_34 , L_27 ,
V_34 -> V_98 , V_34 -> V_36 ) ;
return - V_159 ;
}
if ( F_27 ( V_34 ) ) {
F_25 ( V_34 -> V_34 , L_28 ) ;
return - V_189 ;
}
F_66 ( & V_34 -> V_58 ) ;
break;
case V_191 :
F_34 ( V_34 -> V_34 , L_29 ) ;
F_63 ( V_34 , V_183 , V_146 ) ;
break;
case V_136 :
F_34 ( V_34 -> V_34 , L_30 ) ;
F_63 ( V_34 , V_183 , V_147 ) ;
break;
case V_126 :
F_34 ( V_34 -> V_34 , L_31 ) ;
V_132 = (struct V_125 * ) V_176 ;
F_56 ( V_34 , V_132 ) ;
break;
case V_192 :
F_34 ( V_34 -> V_34 , L_32 ) ;
V_55 = F_71 ( V_34 ) ;
if ( V_55 )
return V_55 ;
break;
case V_193 :
F_34 ( V_34 -> V_34 , L_33 ) ;
V_55 = F_76 ( V_34 ) ;
if ( V_55 )
return V_55 ;
break;
case V_194 :
F_34 ( V_34 -> V_34 , L_34 ) ;
V_34 -> V_35 = 0 ;
if ( V_34 -> V_98 != V_190 ||
V_34 -> V_36 != V_195 ) {
F_25 ( V_34 -> V_34 , L_35 ,
V_34 -> V_98 , V_34 -> V_36 ) ;
return - V_159 ;
}
V_179 = (struct V_79 * ) V_176 ;
if ( V_179 -> V_2 ) {
F_25 ( V_34 -> V_34 , L_36 ,
V_179 -> V_2 ,
F_1 ( V_179 -> V_2 ) ) ;
return - V_159 ;
}
F_28 ( V_34 , V_179 ) ;
if ( F_46 ( V_34 , V_179 -> V_42 + 1 ) )
return - V_189 ;
break;
case V_196 :
F_34 ( V_34 -> V_34 , L_37 ) ;
V_34 -> V_35 = 0 ;
V_181 = (struct V_180 * ) V_176 ;
F_36 ( sizeof( V_34 -> V_113 )
< sizeof( V_181 -> V_197 ) ) ;
memcpy ( V_34 -> V_113 , V_181 -> V_197 ,
sizeof( V_181 -> V_197 ) ) ;
if ( V_34 -> V_98 != V_190 ||
V_34 -> V_36 != V_78 ) {
F_25 ( V_34 -> V_34 , L_38 ,
V_34 -> V_98 , V_34 -> V_36 ) ;
return - V_159 ;
}
V_34 -> V_36 = V_195 ;
if ( F_46 ( V_34 , 0 ) )
return - V_189 ;
break;
case V_198 :
F_34 ( V_34 -> V_34 , L_39 ) ;
V_34 -> V_35 = 0 ;
if ( V_34 -> V_36 != V_188 ) {
F_25 ( V_34 -> V_34 , L_40 ,
V_34 -> V_98 , V_34 -> V_36 ) ;
return - V_159 ;
}
V_34 -> V_98 = V_199 ;
F_84 ( V_34 -> V_34 , L_41 ) ;
return - V_159 ;
break;
case V_134 :
F_34 ( V_34 -> V_34 , L_42 ) ;
V_152 = (struct V_133 * ) V_176 ;
F_67 ( V_34 , V_152 ) ;
break;
case V_200 :
F_34 ( V_34 -> V_34 , L_43 ) ;
V_34 -> V_36 = V_188 ;
if ( F_50 ( V_34 ) ) {
F_25 ( V_34 -> V_34 , L_44 ) ;
return - V_189 ;
}
break;
case V_201 :
F_34 ( V_34 -> V_34 , L_45 ) ;
if ( V_34 -> V_36 <= V_78 ||
V_34 -> V_36 >= V_188 ) {
F_25 ( V_34 -> V_34 , L_46 ,
V_34 -> V_98 , V_34 -> V_36 ) ;
return - V_159 ;
}
V_182 = (struct V_95 * ) V_176 ;
V_55 = F_35 ( V_34 , V_182 ) ;
if ( V_55 ) {
F_25 ( V_34 -> V_34 , L_47 ,
V_55 ) ;
return - V_189 ;
}
F_34 ( V_34 -> V_34 , L_48 ) ;
break;
case V_202 :
F_34 ( V_34 -> V_34 , L_49 ) ;
F_63 ( V_34 , V_183 , F_39 ( V_183 ) ) ;
break;
case V_203 :
F_34 ( V_34 -> V_34 , L_50 ) ;
F_44 ( V_34 , V_183 ) ;
break;
default:
F_85 () ;
break;
}
return 0 ;
}
