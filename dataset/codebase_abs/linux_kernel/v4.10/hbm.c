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
V_39 -> V_45 = 0 ;
}
static inline
void F_12 ( struct V_46 * V_47 , T_2 V_48 , void * V_49 , T_1 V_50 )
{
struct V_51 * V_52 = V_49 ;
memset ( V_52 , 0 , V_50 ) ;
V_52 -> V_48 = V_48 ;
V_52 -> V_41 = F_13 ( V_47 ) ;
V_52 -> V_42 = F_14 ( V_47 ) ;
}
static inline
int F_15 ( struct V_33 * V_34 , struct V_46 * V_47 ,
T_2 V_48 , T_2 * V_49 , T_1 V_50 )
{
struct V_38 V_53 ;
F_11 ( & V_53 , V_50 ) ;
F_12 ( V_47 , V_48 , V_49 , V_50 ) ;
return F_16 ( V_34 , & V_53 , V_49 ) ;
}
static inline
bool F_17 ( struct V_46 * V_47 , struct V_51 * V_52 )
{
return F_13 ( V_47 ) == V_52 -> V_41 &&
F_14 ( V_47 ) == V_52 -> V_42 ;
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
int V_54 ;
if ( V_34 -> V_36 > V_55 )
return 0 ;
F_21 ( & V_34 -> V_56 ) ;
V_54 = F_22 ( V_34 -> V_57 ,
V_34 -> V_36 != V_55 ,
F_23 ( V_58 ) ) ;
F_24 ( & V_34 -> V_56 ) ;
if ( V_54 == 0 && ( V_34 -> V_36 <= V_55 ) ) {
V_34 -> V_36 = V_37 ;
F_25 ( V_34 -> V_34 , L_2 ) ;
return - V_59 ;
}
return 0 ;
}
int F_26 ( struct V_33 * V_34 )
{
struct V_38 V_53 ;
struct V_60 V_61 ;
const T_1 V_50 = sizeof( struct V_60 ) ;
int V_54 ;
F_9 ( V_34 ) ;
F_11 ( & V_53 , V_50 ) ;
memset ( & V_61 , 0 , V_50 ) ;
V_61 . V_48 = V_62 ;
V_61 . V_63 . V_64 = V_65 ;
V_61 . V_63 . V_66 = V_67 ;
V_34 -> V_36 = V_37 ;
V_54 = F_16 ( V_34 , & V_53 , & V_61 ) ;
if ( V_54 ) {
F_25 ( V_34 -> V_34 , L_3 ,
V_54 ) ;
return V_54 ;
}
V_34 -> V_36 = V_55 ;
V_34 -> V_35 = V_68 ;
F_27 ( V_34 ) ;
return 0 ;
}
static int F_28 ( struct V_33 * V_34 )
{
struct V_38 V_53 ;
struct V_69 V_70 ;
const T_1 V_50 = sizeof( struct V_69 ) ;
int V_54 ;
F_11 ( & V_53 , V_50 ) ;
memset ( & V_70 , 0 , V_50 ) ;
V_70 . V_48 = V_71 ;
V_70 . V_72 |= V_34 -> V_73 ?
V_74 : 0 ;
V_70 . V_72 |= V_34 -> V_75 ?
V_76 : 0 ;
V_54 = F_16 ( V_34 , & V_53 , & V_70 ) ;
if ( V_54 ) {
F_25 ( V_34 -> V_34 , L_4 ,
V_54 ) ;
return V_54 ;
}
V_34 -> V_36 = V_77 ;
V_34 -> V_35 = V_68 ;
F_27 ( V_34 ) ;
return 0 ;
}
static int F_29 ( struct V_33 * V_34 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 ;
const T_3 * V_82 = & V_79 -> V_83 . V_84 ;
F_30 ( V_34 , V_82 ) ;
V_81 = F_31 ( sizeof( struct V_80 ) , V_85 ) ;
if ( ! V_81 )
return - V_86 ;
F_32 ( V_81 ) ;
V_81 -> V_87 = V_79 -> V_83 ;
V_81 -> V_88 = V_79 -> V_42 ;
V_81 -> V_89 = 0 ;
F_33 ( V_34 , V_81 ) ;
return 0 ;
}
static int F_34 ( struct V_33 * V_34 , T_2 V_90 , T_2 V_2 )
{
struct V_38 V_53 ;
struct V_91 V_92 ;
const T_1 V_50 = sizeof( struct V_91 ) ;
int V_54 ;
F_35 ( V_34 -> V_34 , L_5 ) ;
F_11 ( & V_53 , V_50 ) ;
memset ( & V_92 , 0 , sizeof( struct V_91 ) ) ;
V_92 . V_48 = V_93 ;
V_92 . V_42 = V_90 ;
V_92 . V_2 = V_2 ;
V_54 = F_16 ( V_34 , & V_53 , & V_92 ) ;
if ( V_54 )
F_25 ( V_34 -> V_34 , L_6 ,
V_54 ) ;
return V_54 ;
}
static int F_36 ( struct V_33 * V_34 ,
struct V_94 * V_95 )
{
int V_54 ;
T_2 V_2 = V_96 ;
F_37 ( sizeof( struct V_94 ) !=
sizeof( struct V_78 ) ) ;
V_54 = F_29 ( V_34 , (struct V_78 * ) V_95 ) ;
if ( V_54 )
V_2 = ! V_96 ;
if ( V_34 -> V_97 == V_98 )
F_38 ( & V_34 -> V_99 ) ;
return F_34 ( V_34 , V_95 -> V_42 , V_2 ) ;
}
int F_39 ( struct V_33 * V_34 ,
struct V_46 * V_47 , T_2 V_100 )
{
struct V_38 V_53 ;
struct V_101 V_95 ;
const T_1 V_50 = sizeof( struct V_101 ) ;
int V_54 ;
F_11 ( & V_53 , V_50 ) ;
F_12 ( V_47 , V_102 , & V_95 , V_50 ) ;
V_95 . V_100 = V_100 ;
V_54 = F_16 ( V_34 , & V_53 , & V_95 ) ;
if ( V_54 )
F_25 ( V_34 -> V_34 , L_7 , V_54 ) ;
return V_54 ;
}
static inline enum V_103 F_40 ( struct V_51 * V_52 )
{
struct V_104 * V_105 =
(struct V_104 * ) V_52 ;
return F_41 ( V_105 -> V_100 ) ;
}
static void F_42 ( struct V_33 * V_34 ,
struct V_46 * V_47 ,
struct V_51 * V_52 )
{
struct V_104 * V_105 =
(struct V_104 * ) V_52 ;
F_43 ( V_34 , V_47 , L_8 , V_105 -> V_2 ) ;
if ( V_105 -> V_2 == V_96 ||
V_105 -> V_2 == V_106 ) {
V_47 -> V_107 = true ;
V_47 -> V_2 = 0 ;
} else {
V_47 -> V_2 = - V_31 ;
}
}
static void F_44 ( struct V_33 * V_34 ,
struct V_46 * V_47 ,
struct V_51 * V_52 )
{
struct V_104 * V_105 =
(struct V_104 * ) V_52 ;
F_43 ( V_34 , V_47 , L_9 , V_105 -> V_2 ) ;
if ( V_105 -> V_2 == V_96 ||
V_105 -> V_2 == V_108 ) {
V_47 -> V_107 = false ;
V_47 -> V_2 = 0 ;
} else {
V_47 -> V_2 = - V_31 ;
}
}
static void F_45 ( struct V_33 * V_34 ,
struct V_51 * V_52 )
{
struct V_46 * V_47 ;
V_47 = F_18 ( V_34 , V_52 ) ;
if ( V_47 )
F_46 ( V_47 ) ;
}
static int F_47 ( struct V_33 * V_34 , unsigned long V_109 )
{
struct V_38 V_53 ;
struct V_110 V_111 ;
const T_1 V_50 = sizeof( struct V_110 ) ;
unsigned long V_90 ;
int V_54 ;
V_90 = F_48 ( V_34 -> V_112 , V_113 , V_109 ) ;
if ( V_90 == V_113 ) {
V_34 -> V_36 = V_114 ;
F_49 ( V_34 ) ;
return 0 ;
}
F_11 ( & V_53 , V_50 ) ;
memset ( & V_111 , 0 , sizeof( struct V_110 ) ) ;
V_111 . V_48 = V_115 ;
V_111 . V_42 = V_90 ;
V_54 = F_16 ( V_34 , & V_53 , & V_111 ) ;
if ( V_54 ) {
F_25 ( V_34 -> V_34 , L_10 ,
V_54 ) ;
return V_54 ;
}
V_34 -> V_35 = V_68 ;
F_27 ( V_34 ) ;
return 0 ;
}
int F_50 ( struct V_33 * V_34 , T_2 V_116 )
{
struct V_38 V_53 ;
struct V_117 V_95 ;
const T_1 V_50 = sizeof( struct V_117 ) ;
int V_54 ;
if ( ! V_34 -> V_118 )
return - V_119 ;
F_11 ( & V_53 , V_50 ) ;
memset ( & V_95 , 0 , V_50 ) ;
V_95 . V_48 = V_116 ;
V_54 = F_16 ( V_34 , & V_53 , & V_95 ) ;
if ( V_54 )
F_25 ( V_34 -> V_34 , L_11 ) ;
return V_54 ;
}
static int F_51 ( struct V_33 * V_34 )
{
struct V_38 V_53 ;
struct V_120 V_95 ;
const T_1 V_50 = sizeof( struct V_120 ) ;
F_11 ( & V_53 , V_50 ) ;
memset ( & V_95 , 0 , V_50 ) ;
V_95 . V_48 = V_121 ;
V_95 . V_122 = V_123 ;
return F_16 ( V_34 , & V_53 , & V_95 ) ;
}
int F_52 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
const T_1 V_50 = sizeof( struct V_124 ) ;
T_2 V_49 [ V_50 ] ;
F_43 ( V_34 , V_47 , L_12 ) ;
return F_15 ( V_34 , V_47 , V_125 , V_49 , V_50 ) ;
}
static int F_53 ( struct V_33 * V_34 ,
struct V_124 * V_126 )
{
struct V_80 * V_81 ;
int V_127 ;
V_81 = F_54 ( V_34 , V_126 -> V_42 ) ;
if ( ! V_81 ) {
F_25 ( V_34 -> V_34 , L_13 , V_126 -> V_42 ) ;
return - V_128 ;
}
if ( F_55 ( V_81 -> V_87 . V_129 == 0 ) ) {
V_127 = - V_31 ;
goto V_130;
}
V_81 -> V_89 ++ ;
F_35 ( V_34 -> V_34 , L_14 ,
V_126 -> V_42 , V_81 -> V_89 ) ;
V_127 = 0 ;
V_130:
F_56 ( V_81 ) ;
return V_127 ;
}
static void F_57 ( struct V_33 * V_34 ,
struct V_124 * V_126 )
{
struct V_46 * V_47 ;
if ( ! V_126 -> V_41 ) {
F_53 ( V_34 , V_126 ) ;
return;
}
V_47 = F_18 ( V_34 , V_126 ) ;
if ( V_47 ) {
V_47 -> V_89 ++ ;
F_43 ( V_34 , V_47 , L_15 ,
V_47 -> V_89 ) ;
}
}
int F_58 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
const T_1 V_50 = sizeof( struct V_131 ) ;
T_2 V_49 [ V_50 ] ;
return F_15 ( V_34 , V_47 , V_132 , V_49 , V_50 ) ;
}
int F_59 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
const T_1 V_50 = sizeof( struct V_133 ) ;
T_2 V_49 [ V_50 ] ;
return F_15 ( V_34 , V_47 , V_134 , V_49 , V_50 ) ;
}
static void F_60 ( struct V_33 * V_34 , struct V_46 * V_47 ,
struct V_51 * V_52 )
{
struct V_133 * V_105 =
(struct V_133 * ) V_52 ;
F_43 ( V_34 , V_47 , L_16 , V_105 -> V_2 ) ;
if ( V_105 -> V_2 == V_135 )
V_47 -> V_17 = V_136 ;
V_47 -> V_2 = 0 ;
}
int F_61 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
const T_1 V_50 = sizeof( struct V_131 ) ;
T_2 V_49 [ V_50 ] ;
return F_15 ( V_34 , V_47 , V_137 , V_49 , V_50 ) ;
}
static void F_62 ( struct V_33 * V_34 , struct V_46 * V_47 ,
struct V_51 * V_52 )
{
struct V_133 * V_105 =
(struct V_133 * ) V_52 ;
F_43 ( V_34 , V_47 , L_17 ,
F_3 ( V_105 -> V_2 ) ) ;
if ( V_105 -> V_2 == V_24 )
V_47 -> V_17 = V_138 ;
else {
V_47 -> V_17 = V_136 ;
if ( V_105 -> V_2 == V_25 ) {
F_63 ( V_34 , V_47 -> V_81 ) ;
if ( V_34 -> V_97 == V_98 )
F_38 ( & V_34 -> V_99 ) ;
}
}
V_47 -> V_2 = F_7 ( V_105 -> V_2 ) ;
}
static void F_64 ( struct V_33 * V_34 ,
struct V_51 * V_105 ,
enum V_103 V_139 )
{
struct V_46 * V_47 ;
struct V_140 * V_141 , * V_142 ;
V_47 = NULL ;
F_65 (cb, next, &dev->ctrl_rd_list.list, list) {
V_47 = V_141 -> V_47 ;
if ( V_141 -> V_139 != V_139 )
continue;
if ( F_17 ( V_47 , V_105 ) ) {
F_66 ( & V_141 -> V_143 ) ;
break;
}
}
if ( ! V_47 )
return;
switch ( V_139 ) {
case V_144 :
F_62 ( V_34 , V_47 , V_105 ) ;
break;
case V_145 :
F_60 ( V_34 , V_47 , V_105 ) ;
break;
case V_146 :
F_42 ( V_34 , V_47 , V_105 ) ;
break;
case V_147 :
F_44 ( V_34 , V_47 , V_105 ) ;
break;
default:
return;
}
V_47 -> V_148 = 0 ;
F_67 ( & V_47 -> V_149 ) ;
}
static int F_68 ( struct V_33 * V_34 ,
struct V_131 * V_150 )
{
struct V_46 * V_47 ;
struct V_140 * V_141 ;
V_47 = F_18 ( V_34 , V_150 ) ;
if ( V_47 ) {
F_69 ( V_34 , V_47 , L_18 ) ;
V_47 -> V_17 = V_151 ;
V_47 -> V_148 = 0 ;
V_141 = F_70 ( V_47 , 0 , V_152 ,
NULL ) ;
if ( ! V_141 )
return - V_86 ;
}
return 0 ;
}
static int F_71 ( struct V_33 * V_34 )
{
if ( F_72 ( V_34 ) != V_153 ||
V_34 -> V_154 != V_155 ) {
F_25 ( V_34 -> V_34 , L_19 ,
F_73 ( F_72 ( V_34 ) ) , V_34 -> V_154 ) ;
return - V_156 ;
}
V_34 -> V_154 = V_157 ;
F_67 ( & V_34 -> V_158 ) ;
return 0 ;
}
void F_74 ( struct V_33 * V_34 )
{
F_75 ( V_34 -> V_34 ) ;
}
static int F_76 ( struct V_33 * V_34 )
{
if ( F_72 ( V_34 ) != V_159 ||
( V_34 -> V_154 != V_155 &&
V_34 -> V_154 != V_160 ) ) {
F_25 ( V_34 -> V_34 , L_20 ,
F_73 ( F_72 ( V_34 ) ) , V_34 -> V_154 ) ;
return - V_156 ;
}
switch ( V_34 -> V_154 ) {
case V_155 :
V_34 -> V_154 = V_157 ;
F_67 ( & V_34 -> V_158 ) ;
break;
case V_160 :
V_34 -> V_154 = V_157 ;
F_74 ( V_34 ) ;
break;
default:
F_77 ( 1 , L_21 ,
V_34 -> V_154 ) ;
return - V_156 ;
}
return 0 ;
}
static void F_78 ( struct V_33 * V_34 )
{
V_34 -> V_118 = 0 ;
if ( V_34 -> V_161 . V_64 > V_162 )
V_34 -> V_118 = 1 ;
if ( V_34 -> V_161 . V_64 == V_162 &&
V_34 -> V_161 . V_66 >= V_163 )
V_34 -> V_118 = 1 ;
if ( V_34 -> V_161 . V_64 >= V_164 )
V_34 -> V_73 = 1 ;
if ( V_34 -> V_161 . V_64 >= V_165 )
V_34 -> V_75 = 1 ;
if ( V_34 -> V_161 . V_64 >= V_166 )
V_34 -> V_167 = 1 ;
if ( V_34 -> V_161 . V_64 >= V_168 )
V_34 -> V_169 = 1 ;
if ( V_34 -> V_161 . V_64 >= V_170 )
V_34 -> V_171 = 1 ;
if ( V_34 -> V_161 . V_64 >= V_172 )
V_34 -> V_173 = 1 ;
}
bool F_79 ( struct V_33 * V_34 )
{
return ( V_34 -> V_161 . V_64 < V_65 ) ||
( V_34 -> V_161 . V_64 == V_65 &&
V_34 -> V_161 . V_66 <= V_67 ) ;
}
int F_80 ( struct V_33 * V_34 , struct V_38 * V_39 )
{
struct V_174 * V_175 ;
struct V_176 * V_177 ;
struct V_78 * V_178 ;
struct V_179 * V_180 ;
struct V_94 * V_181 ;
int V_54 ;
struct V_51 * V_182 ;
struct V_131 * V_150 ;
struct V_124 * V_126 ;
F_81 ( V_39 -> V_40 >= sizeof( V_34 -> V_183 ) ) ;
F_82 ( V_34 , V_34 -> V_183 , V_39 -> V_40 ) ;
V_175 = (struct V_174 * ) V_34 -> V_183 ;
V_182 = (struct V_51 * ) V_175 ;
if ( V_34 -> V_36 == V_37 ) {
F_35 ( V_34 -> V_34 , L_22 ) ;
return 0 ;
}
switch ( V_175 -> V_48 ) {
case V_184 :
F_35 ( V_34 -> V_34 , L_23 ) ;
V_34 -> V_35 = 0 ;
V_177 = (struct V_176 * ) V_175 ;
F_35 ( V_34 -> V_34 , L_24 ,
V_65 , V_67 ,
V_177 -> V_185 . V_64 ,
V_177 -> V_185 . V_66 ) ;
if ( V_177 -> V_186 ) {
V_34 -> V_161 . V_64 = V_65 ;
V_34 -> V_161 . V_66 = V_67 ;
} else {
V_34 -> V_161 . V_64 =
V_177 -> V_185 . V_64 ;
V_34 -> V_161 . V_66 =
V_177 -> V_185 . V_66 ;
}
if ( ! F_79 ( V_34 ) ) {
F_83 ( V_34 -> V_34 , L_25 ) ;
V_34 -> V_36 = V_187 ;
if ( F_51 ( V_34 ) ) {
F_25 ( V_34 -> V_34 , L_26 ) ;
return - V_188 ;
}
break;
}
F_78 ( V_34 ) ;
if ( V_34 -> V_97 != V_189 ||
V_34 -> V_36 != V_55 ) {
F_25 ( V_34 -> V_34 , L_27 ,
V_34 -> V_97 , V_34 -> V_36 ) ;
return - V_156 ;
}
if ( F_28 ( V_34 ) ) {
F_25 ( V_34 -> V_34 , L_28 ) ;
return - V_188 ;
}
F_67 ( & V_34 -> V_57 ) ;
break;
case V_190 :
F_35 ( V_34 -> V_34 , L_29 ) ;
F_64 ( V_34 , V_182 , V_144 ) ;
break;
case V_134 :
F_35 ( V_34 -> V_34 , L_30 ) ;
F_64 ( V_34 , V_182 , V_145 ) ;
break;
case V_125 :
F_35 ( V_34 -> V_34 , L_31 ) ;
V_126 = (struct V_124 * ) V_175 ;
F_57 ( V_34 , V_126 ) ;
break;
case V_191 :
F_35 ( V_34 -> V_34 , L_32 ) ;
V_54 = F_71 ( V_34 ) ;
if ( V_54 )
return V_54 ;
break;
case V_192 :
F_35 ( V_34 -> V_34 , L_33 ) ;
V_54 = F_76 ( V_34 ) ;
if ( V_54 )
return V_54 ;
break;
case V_193 :
F_35 ( V_34 -> V_34 , L_34 ) ;
V_34 -> V_35 = 0 ;
if ( V_34 -> V_97 != V_189 ||
V_34 -> V_36 != V_194 ) {
F_25 ( V_34 -> V_34 , L_35 ,
V_34 -> V_97 , V_34 -> V_36 ) ;
return - V_156 ;
}
V_178 = (struct V_78 * ) V_175 ;
if ( V_178 -> V_2 ) {
F_25 ( V_34 -> V_34 , L_36 ,
V_178 -> V_2 ,
F_1 ( V_178 -> V_2 ) ) ;
return - V_156 ;
}
F_29 ( V_34 , V_178 ) ;
if ( F_47 ( V_34 , V_178 -> V_42 + 1 ) )
return - V_188 ;
break;
case V_195 :
F_35 ( V_34 -> V_34 , L_37 ) ;
V_34 -> V_35 = 0 ;
V_180 = (struct V_179 * ) V_175 ;
F_37 ( sizeof( V_34 -> V_112 )
< sizeof( V_180 -> V_196 ) ) ;
memcpy ( V_34 -> V_112 , V_180 -> V_196 ,
sizeof( V_180 -> V_196 ) ) ;
if ( V_34 -> V_97 != V_189 ||
V_34 -> V_36 != V_77 ) {
F_25 ( V_34 -> V_34 , L_38 ,
V_34 -> V_97 , V_34 -> V_36 ) ;
return - V_156 ;
}
V_34 -> V_36 = V_194 ;
if ( F_47 ( V_34 , 0 ) )
return - V_188 ;
break;
case V_197 :
F_35 ( V_34 -> V_34 , L_39 ) ;
V_34 -> V_35 = 0 ;
if ( V_34 -> V_36 != V_187 ) {
F_25 ( V_34 -> V_34 , L_40 ,
V_34 -> V_97 , V_34 -> V_36 ) ;
return - V_156 ;
}
V_34 -> V_97 = V_198 ;
F_84 ( V_34 -> V_34 , L_41 ) ;
return - V_156 ;
break;
case V_132 :
F_35 ( V_34 -> V_34 , L_42 ) ;
V_150 = (struct V_131 * ) V_175 ;
F_68 ( V_34 , V_150 ) ;
break;
case V_199 :
F_35 ( V_34 -> V_34 , L_43 ) ;
V_34 -> V_36 = V_187 ;
if ( F_51 ( V_34 ) ) {
F_25 ( V_34 -> V_34 , L_44 ) ;
return - V_188 ;
}
break;
case V_200 :
F_35 ( V_34 -> V_34 , L_45 ) ;
if ( V_34 -> V_36 <= V_77 ||
V_34 -> V_36 >= V_187 ) {
F_25 ( V_34 -> V_34 , L_46 ,
V_34 -> V_97 , V_34 -> V_36 ) ;
return - V_156 ;
}
V_181 = (struct V_94 * ) V_175 ;
V_54 = F_36 ( V_34 , V_181 ) ;
if ( V_54 ) {
F_25 ( V_34 -> V_34 , L_47 ,
V_54 ) ;
return - V_188 ;
}
F_35 ( V_34 -> V_34 , L_48 ) ;
break;
case V_201 :
F_35 ( V_34 -> V_34 , L_49 ) ;
F_64 ( V_34 , V_182 , F_40 ( V_182 ) ) ;
break;
case V_202 :
F_35 ( V_34 -> V_34 , L_50 ) ;
F_45 ( V_34 , V_182 ) ;
break;
default:
F_85 () ;
break;
}
return 0 ;
}
