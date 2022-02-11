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
static void F_9 ( struct V_32 * V_33 )
{
struct V_37 * V_38 , * V_39 ;
F_10 (me_cl, next, &dev->me_clients, list) {
F_11 ( & V_38 -> V_40 ) ;
F_12 ( V_38 ) ;
}
}
void F_13 ( struct V_32 * V_33 )
{
V_33 -> V_41 = 0 ;
F_9 ( V_33 ) ;
F_8 ( V_33 ) ;
}
static inline void F_14 ( struct V_42 * V_43 , T_1 V_44 )
{
V_43 -> V_45 = 0 ;
V_43 -> V_46 = 0 ;
V_43 -> V_44 = V_44 ;
V_43 -> V_47 = 1 ;
V_43 -> V_48 = 0 ;
}
static inline
void F_15 ( struct V_49 * V_50 , T_2 V_51 , void * V_52 , T_1 V_53 )
{
struct V_54 * V_55 = V_52 ;
memset ( V_55 , 0 , V_53 ) ;
V_55 -> V_51 = V_51 ;
V_55 -> V_45 = V_50 -> V_56 ;
V_55 -> V_46 = V_50 -> V_57 ;
}
static inline
int F_16 ( struct V_32 * V_33 ,
struct V_49 * V_50 , T_2 V_51 , T_1 V_53 )
{
struct V_42 * V_58 = & V_33 -> V_59 . V_43 ;
F_14 ( V_58 , V_53 ) ;
F_15 ( V_50 , V_51 , V_33 -> V_59 . V_60 , V_53 ) ;
return F_17 ( V_33 , V_58 , V_33 -> V_59 . V_60 ) ;
}
static inline
bool F_18 ( struct V_49 * V_50 , struct V_54 * V_55 )
{
return V_50 -> V_56 == V_55 -> V_45 &&
V_50 -> V_57 == V_55 -> V_46 ;
}
static inline
struct V_49 * F_19 ( struct V_32 * V_33 , void * V_52 )
{
struct V_54 * V_55 = (struct V_54 * ) V_52 ;
struct V_49 * V_50 ;
F_20 (cl, &dev->file_list, link)
if ( F_18 ( V_50 , V_55 ) )
return V_50 ;
return NULL ;
}
int F_21 ( struct V_32 * V_33 )
{
int V_61 ;
if ( V_33 -> V_35 > V_62 )
return 0 ;
F_22 ( & V_33 -> V_63 ) ;
V_61 = F_23 ( V_33 -> V_64 ,
V_33 -> V_35 != V_62 ,
F_24 ( V_65 ) ) ;
F_25 ( & V_33 -> V_63 ) ;
if ( V_61 == 0 && ( V_33 -> V_35 <= V_62 ) ) {
V_33 -> V_35 = V_36 ;
F_26 ( V_33 -> V_33 , L_2 ) ;
return - V_66 ;
}
return 0 ;
}
int F_27 ( struct V_32 * V_33 )
{
struct V_42 * V_58 = & V_33 -> V_59 . V_43 ;
struct V_67 * V_68 ;
const T_1 V_53 = sizeof( struct V_67 ) ;
int V_61 ;
F_13 ( V_33 ) ;
F_14 ( V_58 , V_53 ) ;
V_68 = (struct V_67 * ) V_33 -> V_59 . V_60 ;
memset ( V_68 , 0 , V_53 ) ;
V_68 -> V_51 = V_69 ;
V_68 -> V_70 . V_71 = V_72 ;
V_68 -> V_70 . V_73 = V_74 ;
V_33 -> V_35 = V_36 ;
V_61 = F_17 ( V_33 , V_58 , V_33 -> V_59 . V_60 ) ;
if ( V_61 ) {
F_26 ( V_33 -> V_33 , L_3 ,
V_61 ) ;
return V_61 ;
}
V_33 -> V_35 = V_62 ;
V_33 -> V_34 = V_75 ;
return 0 ;
}
static int F_28 ( struct V_32 * V_33 )
{
struct V_42 * V_58 = & V_33 -> V_59 . V_43 ;
struct V_76 * V_77 ;
const T_1 V_53 = sizeof( struct V_76 ) ;
int V_61 ;
F_14 ( V_58 , V_53 ) ;
V_77 = (struct V_76 * ) V_33 -> V_59 . V_60 ;
memset ( V_77 , 0 , V_53 ) ;
V_77 -> V_51 = V_78 ;
V_61 = F_17 ( V_33 , V_58 , V_33 -> V_59 . V_60 ) ;
if ( V_61 ) {
F_26 ( V_33 -> V_33 , L_4 ,
V_61 ) ;
return V_61 ;
}
V_33 -> V_35 = V_79 ;
V_33 -> V_34 = V_75 ;
return 0 ;
}
static int F_29 ( struct V_32 * V_33 ,
struct V_80 * V_81 )
{
struct V_37 * V_38 ;
V_38 = F_30 ( sizeof( struct V_37 ) , V_82 ) ;
if ( ! V_38 )
return - V_83 ;
V_38 -> V_84 = V_81 -> V_85 ;
V_38 -> V_86 = V_81 -> V_46 ;
V_38 -> V_87 = 0 ;
F_31 ( & V_38 -> V_40 , & V_33 -> V_88 ) ;
return 0 ;
}
static int F_32 ( struct V_32 * V_33 )
{
struct V_42 * V_58 = & V_33 -> V_59 . V_43 ;
struct V_89 * V_90 ;
const T_1 V_53 = sizeof( struct V_89 ) ;
unsigned long V_91 ;
int V_61 ;
V_91 = F_33 ( V_33 -> V_92 , V_93 ,
V_33 -> V_41 ) ;
if ( V_91 == V_93 ) {
V_33 -> V_35 = V_94 ;
F_34 ( & V_33 -> V_95 ) ;
return 0 ;
}
F_14 ( V_58 , V_53 ) ;
V_90 = (struct V_89 * ) V_33 -> V_59 . V_60 ;
memset ( V_90 , 0 , sizeof( struct V_89 ) ) ;
V_90 -> V_51 = V_96 ;
V_90 -> V_46 = V_91 ;
V_61 = F_17 ( V_33 , V_58 , V_33 -> V_59 . V_60 ) ;
if ( V_61 ) {
F_26 ( V_33 -> V_33 , L_5 ,
V_61 ) ;
return V_61 ;
}
V_33 -> V_34 = V_75 ;
V_33 -> V_41 = V_91 ;
return 0 ;
}
int F_35 ( struct V_32 * V_33 , T_2 V_97 )
{
struct V_42 * V_58 = & V_33 -> V_59 . V_43 ;
struct V_98 * V_99 ;
const T_1 V_53 = sizeof( struct V_98 ) ;
int V_61 ;
if ( ! V_33 -> V_100 )
return - V_101 ;
F_14 ( V_58 , V_53 ) ;
V_99 = (struct V_98 * ) V_33 -> V_59 . V_60 ;
memset ( V_99 , 0 , V_53 ) ;
V_99 -> V_51 = V_97 ;
V_61 = F_17 ( V_33 , V_58 , V_33 -> V_59 . V_60 ) ;
if ( V_61 )
F_26 ( V_33 -> V_33 , L_6 ) ;
return V_61 ;
}
static int F_36 ( struct V_32 * V_33 )
{
struct V_42 * V_58 = & V_33 -> V_59 . V_43 ;
struct V_102 * V_99 =
(struct V_102 * ) V_33 -> V_59 . V_60 ;
const T_1 V_53 = sizeof( struct V_102 ) ;
F_14 ( V_58 , V_53 ) ;
memset ( V_99 , 0 , V_53 ) ;
V_99 -> V_51 = V_103 ;
V_99 -> V_104 = V_105 ;
return F_17 ( V_33 , V_58 , V_33 -> V_59 . V_60 ) ;
}
int F_37 ( struct V_32 * V_33 , struct V_49 * V_50 )
{
const T_1 V_53 = sizeof( struct V_106 ) ;
F_38 ( V_33 , V_50 , L_7 ) ;
return F_16 ( V_33 , V_50 , V_107 , V_53 ) ;
}
static int F_39 ( struct V_32 * V_33 ,
struct V_106 * V_108 )
{
struct V_37 * V_38 ;
V_38 = F_40 ( V_33 , V_108 -> V_46 ) ;
if ( ! V_38 ) {
F_26 ( V_33 -> V_33 , L_8 ,
V_108 -> V_46 ) ;
return - V_109 ;
}
if ( F_41 ( V_38 -> V_84 . V_110 == 0 ) )
return - V_31 ;
V_38 -> V_87 ++ ;
F_42 ( V_33 -> V_33 , L_9 ,
V_108 -> V_46 , V_38 -> V_87 ) ;
return 0 ;
}
static void F_43 ( struct V_32 * V_33 ,
struct V_106 * V_111 )
{
struct V_49 * V_50 ;
if ( ! V_111 -> V_45 ) {
F_39 ( V_33 , V_111 ) ;
return;
}
V_50 = F_19 ( V_33 , V_111 ) ;
if ( V_50 ) {
V_50 -> V_87 ++ ;
F_38 ( V_33 , V_50 , L_10 ,
V_50 -> V_87 ) ;
}
}
int F_44 ( struct V_32 * V_33 , struct V_49 * V_50 )
{
const T_1 V_53 = sizeof( struct V_112 ) ;
return F_16 ( V_33 , V_50 , V_113 , V_53 ) ;
}
int F_45 ( struct V_32 * V_33 , struct V_49 * V_50 )
{
const T_1 V_53 = sizeof( struct V_114 ) ;
return F_16 ( V_33 , V_50 , V_115 , V_53 ) ;
}
static void F_46 ( struct V_32 * V_33 , struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_114 * V_116 =
(struct V_114 * ) V_55 ;
F_38 ( V_33 , V_50 , L_11 , V_116 -> V_2 ) ;
if ( V_116 -> V_2 == V_117 )
V_50 -> V_17 = V_118 ;
V_50 -> V_2 = 0 ;
}
int F_47 ( struct V_32 * V_33 , struct V_49 * V_50 )
{
const T_1 V_53 = sizeof( struct V_112 ) ;
return F_16 ( V_33 , V_50 , V_119 , V_53 ) ;
}
static void F_48 ( struct V_32 * V_33 , struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_114 * V_116 =
(struct V_114 * ) V_55 ;
F_38 ( V_33 , V_50 , L_12 ,
F_3 ( V_116 -> V_2 ) ) ;
if ( V_116 -> V_2 == V_24 )
V_50 -> V_17 = V_120 ;
else
V_50 -> V_17 = V_118 ;
V_50 -> V_2 = F_7 ( V_116 -> V_2 ) ;
}
static void F_49 ( struct V_32 * V_33 ,
struct V_54 * V_116 ,
enum V_121 V_122 )
{
struct V_49 * V_50 ;
struct V_123 * V_124 , * V_39 ;
V_50 = NULL ;
F_10 (cb, next, &dev->ctrl_rd_list.list, list) {
V_50 = V_124 -> V_50 ;
if ( V_124 -> V_122 != V_122 )
continue;
if ( F_18 ( V_50 , V_116 ) ) {
F_11 ( & V_124 -> V_40 ) ;
break;
}
}
if ( ! V_50 )
return;
switch ( V_122 ) {
case V_125 :
F_48 ( V_33 , V_50 , V_116 ) ;
break;
case V_126 :
F_46 ( V_33 , V_50 , V_116 ) ;
break;
default:
return;
}
V_50 -> V_127 = 0 ;
F_50 ( & V_50 -> V_128 ) ;
}
static int F_51 ( struct V_32 * V_33 ,
struct V_112 * V_129 )
{
struct V_49 * V_50 ;
struct V_123 * V_124 ;
V_50 = F_19 ( V_33 , V_129 ) ;
if ( V_50 ) {
F_38 ( V_33 , V_50 , L_13 ) ;
V_50 -> V_17 = V_118 ;
V_50 -> V_127 = 0 ;
V_124 = F_52 ( V_50 , NULL ) ;
if ( ! V_124 )
return - V_83 ;
V_124 -> V_122 = V_130 ;
F_38 ( V_33 , V_50 , L_14 ) ;
F_31 ( & V_124 -> V_40 , & V_33 -> V_131 . V_40 ) ;
}
return 0 ;
}
static void F_53 ( struct V_32 * V_33 )
{
V_33 -> V_100 = 0 ;
if ( V_33 -> V_132 . V_71 > V_133 )
V_33 -> V_100 = 1 ;
if ( V_33 -> V_132 . V_71 == V_133 &&
V_33 -> V_132 . V_73 >= V_134 )
V_33 -> V_100 = 1 ;
}
bool F_54 ( struct V_32 * V_33 )
{
return ( V_33 -> V_132 . V_71 < V_72 ) ||
( V_33 -> V_132 . V_71 == V_72 &&
V_33 -> V_132 . V_73 <= V_74 ) ;
}
int F_55 ( struct V_32 * V_33 , struct V_42 * V_43 )
{
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_80 * V_139 ;
struct V_140 * V_141 ;
struct V_54 * V_142 ;
struct V_112 * V_129 ;
struct V_106 * V_111 ;
F_56 ( V_43 -> V_44 >= sizeof( V_33 -> V_143 ) ) ;
F_57 ( V_33 , V_33 -> V_143 , V_43 -> V_44 ) ;
V_136 = (struct V_135 * ) V_33 -> V_143 ;
V_142 = (struct V_54 * ) V_136 ;
if ( V_33 -> V_35 == V_36 ) {
F_42 ( V_33 -> V_33 , L_15 ) ;
return 0 ;
}
switch ( V_136 -> V_51 ) {
case V_144 :
F_42 ( V_33 -> V_33 , L_16 ) ;
V_33 -> V_34 = 0 ;
V_138 = (struct V_137 * ) V_136 ;
F_42 ( V_33 -> V_33 , L_17 ,
V_72 , V_74 ,
V_138 -> V_145 . V_71 ,
V_138 -> V_145 . V_73 ) ;
if ( V_138 -> V_146 ) {
V_33 -> V_132 . V_71 = V_72 ;
V_33 -> V_132 . V_73 = V_74 ;
} else {
V_33 -> V_132 . V_71 =
V_138 -> V_145 . V_71 ;
V_33 -> V_132 . V_73 =
V_138 -> V_145 . V_73 ;
}
if ( ! F_54 ( V_33 ) ) {
F_58 ( V_33 -> V_33 , L_18 ) ;
V_33 -> V_35 = V_147 ;
if ( F_36 ( V_33 ) ) {
F_26 ( V_33 -> V_33 , L_19 ) ;
return - V_148 ;
}
break;
}
F_53 ( V_33 ) ;
if ( V_33 -> V_149 != V_150 ||
V_33 -> V_35 != V_62 ) {
F_26 ( V_33 -> V_33 , L_20 ,
V_33 -> V_149 , V_33 -> V_35 ) ;
return - V_151 ;
}
if ( F_28 ( V_33 ) ) {
F_26 ( V_33 -> V_33 , L_21 ) ;
return - V_148 ;
}
F_50 ( & V_33 -> V_64 ) ;
break;
case V_152 :
F_42 ( V_33 -> V_33 , L_22 ) ;
F_49 ( V_33 , V_142 , V_125 ) ;
break;
case V_115 :
F_42 ( V_33 -> V_33 , L_23 ) ;
F_49 ( V_33 , V_142 , V_126 ) ;
break;
case V_107 :
F_42 ( V_33 -> V_33 , L_24 ) ;
V_111 = (struct V_106 * ) V_136 ;
F_43 ( V_33 , V_111 ) ;
break;
case V_153 :
F_42 ( V_33 -> V_33 , L_25 ) ;
V_33 -> V_154 = V_155 ;
if ( F_59 ( & V_33 -> V_156 ) )
F_50 ( & V_33 -> V_156 ) ;
break;
case V_157 :
F_42 ( V_33 -> V_33 , L_26 ) ;
V_33 -> V_154 = V_155 ;
if ( F_59 ( & V_33 -> V_156 ) )
F_50 ( & V_33 -> V_156 ) ;
else
F_60 ( V_33 -> V_33 ) ;
break;
case V_158 :
F_42 ( V_33 -> V_33 , L_27 ) ;
V_33 -> V_34 = 0 ;
if ( V_33 -> V_149 != V_150 ||
V_33 -> V_35 != V_159 ) {
F_26 ( V_33 -> V_33 , L_28 ,
V_33 -> V_149 , V_33 -> V_35 ) ;
return - V_151 ;
}
V_139 = (struct V_80 * ) V_136 ;
if ( V_139 -> V_2 ) {
F_26 ( V_33 -> V_33 , L_29 ,
V_139 -> V_2 ,
F_1 ( V_139 -> V_2 ) ) ;
return - V_151 ;
}
F_29 ( V_33 , V_139 ) ;
V_33 -> V_41 ++ ;
if ( F_32 ( V_33 ) )
return - V_148 ;
break;
case V_160 :
F_42 ( V_33 -> V_33 , L_30 ) ;
V_33 -> V_34 = 0 ;
V_141 = (struct V_140 * ) V_136 ;
F_61 ( sizeof( V_33 -> V_92 )
< sizeof( V_141 -> V_161 ) ) ;
memcpy ( V_33 -> V_92 , V_141 -> V_161 ,
sizeof( V_141 -> V_161 ) ) ;
if ( V_33 -> V_149 != V_150 ||
V_33 -> V_35 != V_79 ) {
F_26 ( V_33 -> V_33 , L_31 ,
V_33 -> V_149 , V_33 -> V_35 ) ;
return - V_151 ;
}
V_33 -> V_35 = V_159 ;
if ( F_32 ( V_33 ) )
return - V_148 ;
break;
case V_162 :
F_42 ( V_33 -> V_33 , L_32 ) ;
V_33 -> V_34 = 0 ;
if ( V_33 -> V_35 != V_147 ) {
F_26 ( V_33 -> V_33 , L_33 ,
V_33 -> V_149 , V_33 -> V_35 ) ;
return - V_151 ;
}
V_33 -> V_149 = V_163 ;
F_62 ( V_33 -> V_33 , L_34 ) ;
return - V_151 ;
break;
case V_113 :
F_42 ( V_33 -> V_33 , L_35 ) ;
V_129 = (struct V_112 * ) V_136 ;
F_51 ( V_33 , V_129 ) ;
break;
case V_164 :
F_42 ( V_33 -> V_33 , L_36 ) ;
V_33 -> V_35 = V_147 ;
if ( F_36 ( V_33 ) ) {
F_26 ( V_33 -> V_33 , L_37 ) ;
return - V_148 ;
}
break;
default:
F_63 () ;
break;
}
return 0 ;
}
