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
default: return - V_31 ;
}
}
void F_8 ( struct V_32 * V_33 )
{
V_33 -> V_34 = 0 ;
V_33 -> V_35 = V_36 ;
}
void F_9 ( struct V_32 * V_33 )
{
V_33 -> V_37 = 0 ;
F_10 ( V_33 ) ;
F_8 ( V_33 ) ;
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
int F_15 ( struct V_32 * V_33 ,
struct V_45 * V_46 , T_2 V_47 , T_1 V_49 )
{
struct V_38 * V_52 = & V_33 -> V_53 . V_39 ;
F_11 ( V_52 , V_49 ) ;
F_12 ( V_46 , V_47 , V_33 -> V_53 . V_54 , V_49 ) ;
return F_16 ( V_33 , V_52 , V_33 -> V_53 . V_54 ) ;
}
static inline
bool F_17 ( struct V_45 * V_46 , struct V_50 * V_51 )
{
return F_13 ( V_46 ) == V_51 -> V_41 &&
F_14 ( V_46 ) == V_51 -> V_42 ;
}
static inline
struct V_45 * F_18 ( struct V_32 * V_33 , void * V_48 )
{
struct V_50 * V_51 = (struct V_50 * ) V_48 ;
struct V_45 * V_46 ;
F_19 (cl, &dev->file_list, link)
if ( F_17 ( V_46 , V_51 ) )
return V_46 ;
return NULL ;
}
int F_20 ( struct V_32 * V_33 )
{
int V_55 ;
if ( V_33 -> V_35 > V_56 )
return 0 ;
F_21 ( & V_33 -> V_57 ) ;
V_55 = F_22 ( V_33 -> V_58 ,
V_33 -> V_35 != V_56 ,
F_23 ( V_59 ) ) ;
F_24 ( & V_33 -> V_57 ) ;
if ( V_55 == 0 && ( V_33 -> V_35 <= V_56 ) ) {
V_33 -> V_35 = V_36 ;
F_25 ( V_33 -> V_33 , L_2 ) ;
return - V_60 ;
}
return 0 ;
}
int F_26 ( struct V_32 * V_33 )
{
struct V_38 * V_52 = & V_33 -> V_53 . V_39 ;
struct V_61 * V_62 ;
const T_1 V_49 = sizeof( struct V_61 ) ;
int V_55 ;
F_9 ( V_33 ) ;
F_11 ( V_52 , V_49 ) ;
V_62 = (struct V_61 * ) V_33 -> V_53 . V_54 ;
memset ( V_62 , 0 , V_49 ) ;
V_62 -> V_47 = V_63 ;
V_62 -> V_64 . V_65 = V_66 ;
V_62 -> V_64 . V_67 = V_68 ;
V_33 -> V_35 = V_36 ;
V_55 = F_16 ( V_33 , V_52 , V_33 -> V_53 . V_54 ) ;
if ( V_55 ) {
F_25 ( V_33 -> V_33 , L_3 ,
V_55 ) ;
return V_55 ;
}
V_33 -> V_35 = V_56 ;
V_33 -> V_34 = V_69 ;
return 0 ;
}
static int F_27 ( struct V_32 * V_33 )
{
struct V_38 * V_52 = & V_33 -> V_53 . V_39 ;
struct V_70 * V_71 ;
const T_1 V_49 = sizeof( struct V_70 ) ;
int V_55 ;
F_11 ( V_52 , V_49 ) ;
V_71 = (struct V_70 * ) V_33 -> V_53 . V_54 ;
memset ( V_71 , 0 , V_49 ) ;
V_71 -> V_47 = V_72 ;
V_55 = F_16 ( V_33 , V_52 , V_33 -> V_53 . V_54 ) ;
if ( V_55 ) {
F_25 ( V_33 -> V_33 , L_4 ,
V_55 ) ;
return V_55 ;
}
V_33 -> V_35 = V_73 ;
V_33 -> V_34 = V_69 ;
return 0 ;
}
static int F_28 ( struct V_32 * V_33 ,
struct V_74 * V_75 )
{
struct V_76 * V_77 ;
const T_3 * V_78 = & V_75 -> V_79 . V_80 ;
F_29 ( V_33 , V_78 ) ;
V_77 = F_30 ( sizeof( struct V_76 ) , V_81 ) ;
if ( ! V_77 )
return - V_82 ;
F_31 ( V_77 ) ;
V_77 -> V_83 = V_75 -> V_79 ;
V_77 -> V_84 = V_75 -> V_42 ;
V_77 -> V_85 = 0 ;
F_32 ( V_33 , V_77 ) ;
return 0 ;
}
static int F_33 ( struct V_32 * V_33 )
{
struct V_38 * V_52 = & V_33 -> V_53 . V_39 ;
struct V_86 * V_87 ;
const T_1 V_49 = sizeof( struct V_86 ) ;
unsigned long V_88 ;
int V_55 ;
V_88 = F_34 ( V_33 -> V_89 , V_90 ,
V_33 -> V_37 ) ;
if ( V_88 == V_90 ) {
V_33 -> V_35 = V_91 ;
F_35 ( & V_33 -> V_92 ) ;
return 0 ;
}
F_11 ( V_52 , V_49 ) ;
V_87 = (struct V_86 * ) V_33 -> V_53 . V_54 ;
memset ( V_87 , 0 , sizeof( struct V_86 ) ) ;
V_87 -> V_47 = V_93 ;
V_87 -> V_42 = V_88 ;
V_55 = F_16 ( V_33 , V_52 , V_33 -> V_53 . V_54 ) ;
if ( V_55 ) {
F_25 ( V_33 -> V_33 , L_5 ,
V_55 ) ;
return V_55 ;
}
V_33 -> V_34 = V_69 ;
V_33 -> V_37 = V_88 ;
return 0 ;
}
int F_36 ( struct V_32 * V_33 , T_2 V_94 )
{
struct V_38 * V_52 = & V_33 -> V_53 . V_39 ;
struct V_95 * V_96 ;
const T_1 V_49 = sizeof( struct V_95 ) ;
int V_55 ;
if ( ! V_33 -> V_97 )
return - V_98 ;
F_11 ( V_52 , V_49 ) ;
V_96 = (struct V_95 * ) V_33 -> V_53 . V_54 ;
memset ( V_96 , 0 , V_49 ) ;
V_96 -> V_47 = V_94 ;
V_55 = F_16 ( V_33 , V_52 , V_33 -> V_53 . V_54 ) ;
if ( V_55 )
F_25 ( V_33 -> V_33 , L_6 ) ;
return V_55 ;
}
static int F_37 ( struct V_32 * V_33 )
{
struct V_38 * V_52 = & V_33 -> V_53 . V_39 ;
struct V_99 * V_96 =
(struct V_99 * ) V_33 -> V_53 . V_54 ;
const T_1 V_49 = sizeof( struct V_99 ) ;
F_11 ( V_52 , V_49 ) ;
memset ( V_96 , 0 , V_49 ) ;
V_96 -> V_47 = V_100 ;
V_96 -> V_101 = V_102 ;
return F_16 ( V_33 , V_52 , V_33 -> V_53 . V_54 ) ;
}
int F_38 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_103 ) ;
F_39 ( V_33 , V_46 , L_7 ) ;
return F_15 ( V_33 , V_46 , V_104 , V_49 ) ;
}
static int F_40 ( struct V_32 * V_33 ,
struct V_103 * V_105 )
{
struct V_76 * V_77 ;
int V_106 ;
V_77 = F_41 ( V_33 , V_105 -> V_42 ) ;
if ( ! V_77 ) {
F_25 ( V_33 -> V_33 , L_8 ,
V_105 -> V_42 ) ;
return - V_107 ;
}
if ( F_42 ( V_77 -> V_83 . V_108 == 0 ) ) {
V_106 = - V_31 ;
goto V_109;
}
V_77 -> V_85 ++ ;
F_43 ( V_33 -> V_33 , L_9 ,
V_105 -> V_42 , V_77 -> V_85 ) ;
V_106 = 0 ;
V_109:
F_44 ( V_77 ) ;
return V_106 ;
}
static void F_45 ( struct V_32 * V_33 ,
struct V_103 * V_110 )
{
struct V_45 * V_46 ;
if ( ! V_110 -> V_41 ) {
F_40 ( V_33 , V_110 ) ;
return;
}
V_46 = F_18 ( V_33 , V_110 ) ;
if ( V_46 ) {
V_46 -> V_85 ++ ;
F_39 ( V_33 , V_46 , L_10 ,
V_46 -> V_85 ) ;
}
}
int F_46 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_111 ) ;
return F_15 ( V_33 , V_46 , V_112 , V_49 ) ;
}
int F_47 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_113 ) ;
return F_15 ( V_33 , V_46 , V_114 , V_49 ) ;
}
static void F_48 ( struct V_32 * V_33 , struct V_45 * V_46 ,
struct V_50 * V_51 )
{
struct V_113 * V_115 =
(struct V_113 * ) V_51 ;
F_39 ( V_33 , V_46 , L_11 , V_115 -> V_2 ) ;
if ( V_115 -> V_2 == V_116 )
V_46 -> V_17 = V_117 ;
V_46 -> V_2 = 0 ;
}
int F_49 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_111 ) ;
return F_15 ( V_33 , V_46 , V_118 , V_49 ) ;
}
static void F_50 ( struct V_32 * V_33 , struct V_45 * V_46 ,
struct V_50 * V_51 )
{
struct V_113 * V_115 =
(struct V_113 * ) V_51 ;
F_39 ( V_33 , V_46 , L_12 ,
F_3 ( V_115 -> V_2 ) ) ;
if ( V_115 -> V_2 == V_24 )
V_46 -> V_17 = V_119 ;
else
V_46 -> V_17 = V_117 ;
V_46 -> V_2 = F_7 ( V_115 -> V_2 ) ;
}
static void F_51 ( struct V_32 * V_33 ,
struct V_50 * V_115 ,
enum V_120 V_121 )
{
struct V_45 * V_46 ;
struct V_122 * V_123 , * V_124 ;
V_46 = NULL ;
F_52 (cb, next, &dev->ctrl_rd_list.list, list) {
V_46 = V_123 -> V_46 ;
if ( V_123 -> V_121 != V_121 )
continue;
if ( F_17 ( V_46 , V_115 ) ) {
F_53 ( & V_123 -> V_125 ) ;
break;
}
}
if ( ! V_46 )
return;
switch ( V_121 ) {
case V_126 :
F_50 ( V_33 , V_46 , V_115 ) ;
break;
case V_127 :
F_48 ( V_33 , V_46 , V_115 ) ;
break;
default:
return;
}
V_46 -> V_128 = 0 ;
F_54 ( & V_46 -> V_129 ) ;
}
static int F_55 ( struct V_32 * V_33 ,
struct V_111 * V_130 )
{
struct V_45 * V_46 ;
struct V_122 * V_123 ;
V_46 = F_18 ( V_33 , V_130 ) ;
if ( V_46 ) {
F_39 ( V_33 , V_46 , L_13 ) ;
V_46 -> V_17 = V_131 ;
V_46 -> V_128 = 0 ;
V_123 = F_56 ( V_46 , V_132 , NULL ) ;
if ( ! V_123 )
return - V_82 ;
F_39 ( V_33 , V_46 , L_14 ) ;
F_57 ( & V_123 -> V_125 , & V_33 -> V_133 . V_125 ) ;
}
return 0 ;
}
static void F_58 ( struct V_32 * V_33 )
{
V_33 -> V_97 = 0 ;
if ( V_33 -> V_134 . V_65 > V_135 )
V_33 -> V_97 = 1 ;
if ( V_33 -> V_134 . V_65 == V_135 &&
V_33 -> V_134 . V_67 >= V_136 )
V_33 -> V_97 = 1 ;
}
bool F_59 ( struct V_32 * V_33 )
{
return ( V_33 -> V_134 . V_65 < V_66 ) ||
( V_33 -> V_134 . V_65 == V_66 &&
V_33 -> V_134 . V_67 <= V_68 ) ;
}
int F_60 ( struct V_32 * V_33 , struct V_38 * V_39 )
{
struct V_137 * V_138 ;
struct V_139 * V_140 ;
struct V_74 * V_141 ;
struct V_142 * V_143 ;
struct V_50 * V_144 ;
struct V_111 * V_130 ;
struct V_103 * V_110 ;
F_61 ( V_39 -> V_40 >= sizeof( V_33 -> V_145 ) ) ;
F_62 ( V_33 , V_33 -> V_145 , V_39 -> V_40 ) ;
V_138 = (struct V_137 * ) V_33 -> V_145 ;
V_144 = (struct V_50 * ) V_138 ;
if ( V_33 -> V_35 == V_36 ) {
F_43 ( V_33 -> V_33 , L_15 ) ;
return 0 ;
}
switch ( V_138 -> V_47 ) {
case V_146 :
F_43 ( V_33 -> V_33 , L_16 ) ;
V_33 -> V_34 = 0 ;
V_140 = (struct V_139 * ) V_138 ;
F_43 ( V_33 -> V_33 , L_17 ,
V_66 , V_68 ,
V_140 -> V_147 . V_65 ,
V_140 -> V_147 . V_67 ) ;
if ( V_140 -> V_148 ) {
V_33 -> V_134 . V_65 = V_66 ;
V_33 -> V_134 . V_67 = V_68 ;
} else {
V_33 -> V_134 . V_65 =
V_140 -> V_147 . V_65 ;
V_33 -> V_134 . V_67 =
V_140 -> V_147 . V_67 ;
}
if ( ! F_59 ( V_33 ) ) {
F_63 ( V_33 -> V_33 , L_18 ) ;
V_33 -> V_35 = V_149 ;
if ( F_37 ( V_33 ) ) {
F_25 ( V_33 -> V_33 , L_19 ) ;
return - V_150 ;
}
break;
}
F_58 ( V_33 ) ;
if ( V_33 -> V_151 != V_152 ||
V_33 -> V_35 != V_56 ) {
F_25 ( V_33 -> V_33 , L_20 ,
V_33 -> V_151 , V_33 -> V_35 ) ;
return - V_153 ;
}
if ( F_27 ( V_33 ) ) {
F_25 ( V_33 -> V_33 , L_21 ) ;
return - V_150 ;
}
F_54 ( & V_33 -> V_58 ) ;
break;
case V_154 :
F_43 ( V_33 -> V_33 , L_22 ) ;
F_51 ( V_33 , V_144 , V_126 ) ;
break;
case V_114 :
F_43 ( V_33 -> V_33 , L_23 ) ;
F_51 ( V_33 , V_144 , V_127 ) ;
break;
case V_104 :
F_43 ( V_33 -> V_33 , L_24 ) ;
V_110 = (struct V_103 * ) V_138 ;
F_45 ( V_33 , V_110 ) ;
break;
case V_155 :
F_43 ( V_33 -> V_33 , L_25 ) ;
V_33 -> V_156 = V_157 ;
if ( F_64 ( & V_33 -> V_158 ) )
F_54 ( & V_33 -> V_158 ) ;
break;
case V_159 :
F_43 ( V_33 -> V_33 , L_26 ) ;
V_33 -> V_156 = V_157 ;
if ( F_64 ( & V_33 -> V_158 ) )
F_54 ( & V_33 -> V_158 ) ;
else
F_65 ( V_33 -> V_33 ) ;
break;
case V_160 :
F_43 ( V_33 -> V_33 , L_27 ) ;
V_33 -> V_34 = 0 ;
if ( V_33 -> V_151 != V_152 ||
V_33 -> V_35 != V_161 ) {
F_25 ( V_33 -> V_33 , L_28 ,
V_33 -> V_151 , V_33 -> V_35 ) ;
return - V_153 ;
}
V_141 = (struct V_74 * ) V_138 ;
if ( V_141 -> V_2 ) {
F_25 ( V_33 -> V_33 , L_29 ,
V_141 -> V_2 ,
F_1 ( V_141 -> V_2 ) ) ;
return - V_153 ;
}
F_28 ( V_33 , V_141 ) ;
V_33 -> V_37 ++ ;
if ( F_33 ( V_33 ) )
return - V_150 ;
break;
case V_162 :
F_43 ( V_33 -> V_33 , L_30 ) ;
V_33 -> V_34 = 0 ;
V_143 = (struct V_142 * ) V_138 ;
F_66 ( sizeof( V_33 -> V_89 )
< sizeof( V_143 -> V_163 ) ) ;
memcpy ( V_33 -> V_89 , V_143 -> V_163 ,
sizeof( V_143 -> V_163 ) ) ;
if ( V_33 -> V_151 != V_152 ||
V_33 -> V_35 != V_73 ) {
F_25 ( V_33 -> V_33 , L_31 ,
V_33 -> V_151 , V_33 -> V_35 ) ;
return - V_153 ;
}
V_33 -> V_35 = V_161 ;
if ( F_33 ( V_33 ) )
return - V_150 ;
break;
case V_164 :
F_43 ( V_33 -> V_33 , L_32 ) ;
V_33 -> V_34 = 0 ;
if ( V_33 -> V_35 != V_149 ) {
F_25 ( V_33 -> V_33 , L_33 ,
V_33 -> V_151 , V_33 -> V_35 ) ;
return - V_153 ;
}
V_33 -> V_151 = V_165 ;
F_67 ( V_33 -> V_33 , L_34 ) ;
return - V_153 ;
break;
case V_112 :
F_43 ( V_33 -> V_33 , L_35 ) ;
V_130 = (struct V_111 * ) V_138 ;
F_55 ( V_33 , V_130 ) ;
break;
case V_166 :
F_43 ( V_33 -> V_33 , L_36 ) ;
V_33 -> V_35 = V_149 ;
if ( F_37 ( V_33 ) ) {
F_25 ( V_33 -> V_33 , L_37 ) ;
return - V_150 ;
}
break;
default:
F_68 () ;
break;
}
return 0 ;
}
