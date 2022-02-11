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
V_51 -> V_41 = V_46 -> V_52 ;
V_51 -> V_42 = V_46 -> V_53 ;
}
static inline
int F_13 ( struct V_32 * V_33 ,
struct V_45 * V_46 , T_2 V_47 , T_1 V_49 )
{
struct V_38 * V_54 = & V_33 -> V_55 . V_39 ;
F_11 ( V_54 , V_49 ) ;
F_12 ( V_46 , V_47 , V_33 -> V_55 . V_56 , V_49 ) ;
return F_14 ( V_33 , V_54 , V_33 -> V_55 . V_56 ) ;
}
static inline
bool F_15 ( struct V_45 * V_46 , struct V_50 * V_51 )
{
return V_46 -> V_52 == V_51 -> V_41 &&
V_46 -> V_53 == V_51 -> V_42 ;
}
static inline
struct V_45 * F_16 ( struct V_32 * V_33 , void * V_48 )
{
struct V_50 * V_51 = (struct V_50 * ) V_48 ;
struct V_45 * V_46 ;
F_17 (cl, &dev->file_list, link)
if ( F_15 ( V_46 , V_51 ) )
return V_46 ;
return NULL ;
}
int F_18 ( struct V_32 * V_33 )
{
int V_57 ;
if ( V_33 -> V_35 > V_58 )
return 0 ;
F_19 ( & V_33 -> V_59 ) ;
V_57 = F_20 ( V_33 -> V_60 ,
V_33 -> V_35 != V_58 ,
F_21 ( V_61 ) ) ;
F_22 ( & V_33 -> V_59 ) ;
if ( V_57 == 0 && ( V_33 -> V_35 <= V_58 ) ) {
V_33 -> V_35 = V_36 ;
F_23 ( V_33 -> V_33 , L_2 ) ;
return - V_62 ;
}
return 0 ;
}
int F_24 ( struct V_32 * V_33 )
{
struct V_38 * V_54 = & V_33 -> V_55 . V_39 ;
struct V_63 * V_64 ;
const T_1 V_49 = sizeof( struct V_63 ) ;
int V_57 ;
F_9 ( V_33 ) ;
F_11 ( V_54 , V_49 ) ;
V_64 = (struct V_63 * ) V_33 -> V_55 . V_56 ;
memset ( V_64 , 0 , V_49 ) ;
V_64 -> V_47 = V_65 ;
V_64 -> V_66 . V_67 = V_68 ;
V_64 -> V_66 . V_69 = V_70 ;
V_33 -> V_35 = V_36 ;
V_57 = F_14 ( V_33 , V_54 , V_33 -> V_55 . V_56 ) ;
if ( V_57 ) {
F_23 ( V_33 -> V_33 , L_3 ,
V_57 ) ;
return V_57 ;
}
V_33 -> V_35 = V_58 ;
V_33 -> V_34 = V_71 ;
return 0 ;
}
static int F_25 ( struct V_32 * V_33 )
{
struct V_38 * V_54 = & V_33 -> V_55 . V_39 ;
struct V_72 * V_73 ;
const T_1 V_49 = sizeof( struct V_72 ) ;
int V_57 ;
F_11 ( V_54 , V_49 ) ;
V_73 = (struct V_72 * ) V_33 -> V_55 . V_56 ;
memset ( V_73 , 0 , V_49 ) ;
V_73 -> V_47 = V_74 ;
V_57 = F_14 ( V_33 , V_54 , V_33 -> V_55 . V_56 ) ;
if ( V_57 ) {
F_23 ( V_33 -> V_33 , L_4 ,
V_57 ) ;
return V_57 ;
}
V_33 -> V_35 = V_75 ;
V_33 -> V_34 = V_71 ;
return 0 ;
}
static int F_26 ( struct V_32 * V_33 ,
struct V_76 * V_77 )
{
struct V_78 * V_79 ;
const T_3 * V_80 = & V_77 -> V_81 . V_82 ;
F_27 ( V_33 , V_80 ) ;
V_79 = F_28 ( sizeof( struct V_78 ) , V_83 ) ;
if ( ! V_79 )
return - V_84 ;
F_29 ( V_79 ) ;
V_79 -> V_85 = V_77 -> V_81 ;
V_79 -> V_86 = V_77 -> V_42 ;
V_79 -> V_87 = 0 ;
F_30 ( V_33 , V_79 ) ;
return 0 ;
}
static int F_31 ( struct V_32 * V_33 )
{
struct V_38 * V_54 = & V_33 -> V_55 . V_39 ;
struct V_88 * V_89 ;
const T_1 V_49 = sizeof( struct V_88 ) ;
unsigned long V_90 ;
int V_57 ;
V_90 = F_32 ( V_33 -> V_91 , V_92 ,
V_33 -> V_37 ) ;
if ( V_90 == V_92 ) {
V_33 -> V_35 = V_93 ;
F_33 ( & V_33 -> V_94 ) ;
return 0 ;
}
F_11 ( V_54 , V_49 ) ;
V_89 = (struct V_88 * ) V_33 -> V_55 . V_56 ;
memset ( V_89 , 0 , sizeof( struct V_88 ) ) ;
V_89 -> V_47 = V_95 ;
V_89 -> V_42 = V_90 ;
V_57 = F_14 ( V_33 , V_54 , V_33 -> V_55 . V_56 ) ;
if ( V_57 ) {
F_23 ( V_33 -> V_33 , L_5 ,
V_57 ) ;
return V_57 ;
}
V_33 -> V_34 = V_71 ;
V_33 -> V_37 = V_90 ;
return 0 ;
}
int F_34 ( struct V_32 * V_33 , T_2 V_96 )
{
struct V_38 * V_54 = & V_33 -> V_55 . V_39 ;
struct V_97 * V_98 ;
const T_1 V_49 = sizeof( struct V_97 ) ;
int V_57 ;
if ( ! V_33 -> V_99 )
return - V_100 ;
F_11 ( V_54 , V_49 ) ;
V_98 = (struct V_97 * ) V_33 -> V_55 . V_56 ;
memset ( V_98 , 0 , V_49 ) ;
V_98 -> V_47 = V_96 ;
V_57 = F_14 ( V_33 , V_54 , V_33 -> V_55 . V_56 ) ;
if ( V_57 )
F_23 ( V_33 -> V_33 , L_6 ) ;
return V_57 ;
}
static int F_35 ( struct V_32 * V_33 )
{
struct V_38 * V_54 = & V_33 -> V_55 . V_39 ;
struct V_101 * V_98 =
(struct V_101 * ) V_33 -> V_55 . V_56 ;
const T_1 V_49 = sizeof( struct V_101 ) ;
F_11 ( V_54 , V_49 ) ;
memset ( V_98 , 0 , V_49 ) ;
V_98 -> V_47 = V_102 ;
V_98 -> V_103 = V_104 ;
return F_14 ( V_33 , V_54 , V_33 -> V_55 . V_56 ) ;
}
int F_36 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_105 ) ;
F_37 ( V_33 , V_46 , L_7 ) ;
return F_13 ( V_33 , V_46 , V_106 , V_49 ) ;
}
static int F_38 ( struct V_32 * V_33 ,
struct V_105 * V_107 )
{
struct V_78 * V_79 ;
int V_108 ;
V_79 = F_39 ( V_33 , V_107 -> V_42 ) ;
if ( ! V_79 ) {
F_23 ( V_33 -> V_33 , L_8 ,
V_107 -> V_42 ) ;
return - V_109 ;
}
if ( F_40 ( V_79 -> V_85 . V_110 == 0 ) ) {
V_108 = - V_31 ;
goto V_111;
}
V_79 -> V_87 ++ ;
F_41 ( V_33 -> V_33 , L_9 ,
V_107 -> V_42 , V_79 -> V_87 ) ;
V_108 = 0 ;
V_111:
F_42 ( V_79 ) ;
return V_108 ;
}
static void F_43 ( struct V_32 * V_33 ,
struct V_105 * V_112 )
{
struct V_45 * V_46 ;
if ( ! V_112 -> V_41 ) {
F_38 ( V_33 , V_112 ) ;
return;
}
V_46 = F_16 ( V_33 , V_112 ) ;
if ( V_46 ) {
V_46 -> V_87 ++ ;
F_37 ( V_33 , V_46 , L_10 ,
V_46 -> V_87 ) ;
}
}
int F_44 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_113 ) ;
return F_13 ( V_33 , V_46 , V_114 , V_49 ) ;
}
int F_45 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_115 ) ;
return F_13 ( V_33 , V_46 , V_116 , V_49 ) ;
}
static void F_46 ( struct V_32 * V_33 , struct V_45 * V_46 ,
struct V_50 * V_51 )
{
struct V_115 * V_117 =
(struct V_115 * ) V_51 ;
F_37 ( V_33 , V_46 , L_11 , V_117 -> V_2 ) ;
if ( V_117 -> V_2 == V_118 )
V_46 -> V_17 = V_119 ;
V_46 -> V_2 = 0 ;
}
int F_47 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
const T_1 V_49 = sizeof( struct V_113 ) ;
return F_13 ( V_33 , V_46 , V_120 , V_49 ) ;
}
static void F_48 ( struct V_32 * V_33 , struct V_45 * V_46 ,
struct V_50 * V_51 )
{
struct V_115 * V_117 =
(struct V_115 * ) V_51 ;
F_37 ( V_33 , V_46 , L_12 ,
F_3 ( V_117 -> V_2 ) ) ;
if ( V_117 -> V_2 == V_24 )
V_46 -> V_17 = V_121 ;
else
V_46 -> V_17 = V_119 ;
V_46 -> V_2 = F_7 ( V_117 -> V_2 ) ;
}
static void F_49 ( struct V_32 * V_33 ,
struct V_50 * V_117 ,
enum V_122 V_123 )
{
struct V_45 * V_46 ;
struct V_124 * V_125 , * V_126 ;
V_46 = NULL ;
F_50 (cb, next, &dev->ctrl_rd_list.list, list) {
V_46 = V_125 -> V_46 ;
if ( V_125 -> V_123 != V_123 )
continue;
if ( F_15 ( V_46 , V_117 ) ) {
F_51 ( & V_125 -> V_127 ) ;
break;
}
}
if ( ! V_46 )
return;
switch ( V_123 ) {
case V_128 :
F_48 ( V_33 , V_46 , V_117 ) ;
break;
case V_129 :
F_46 ( V_33 , V_46 , V_117 ) ;
break;
default:
return;
}
V_46 -> V_130 = 0 ;
F_52 ( & V_46 -> V_131 ) ;
}
static int F_53 ( struct V_32 * V_33 ,
struct V_113 * V_132 )
{
struct V_45 * V_46 ;
struct V_124 * V_125 ;
V_46 = F_16 ( V_33 , V_132 ) ;
if ( V_46 ) {
F_37 ( V_33 , V_46 , L_13 ) ;
V_46 -> V_17 = V_119 ;
V_46 -> V_130 = 0 ;
V_125 = F_54 ( V_46 , V_133 , NULL ) ;
if ( ! V_125 )
return - V_84 ;
F_37 ( V_33 , V_46 , L_14 ) ;
F_55 ( & V_125 -> V_127 , & V_33 -> V_134 . V_127 ) ;
}
return 0 ;
}
static void F_56 ( struct V_32 * V_33 )
{
V_33 -> V_99 = 0 ;
if ( V_33 -> V_135 . V_67 > V_136 )
V_33 -> V_99 = 1 ;
if ( V_33 -> V_135 . V_67 == V_136 &&
V_33 -> V_135 . V_69 >= V_137 )
V_33 -> V_99 = 1 ;
}
bool F_57 ( struct V_32 * V_33 )
{
return ( V_33 -> V_135 . V_67 < V_68 ) ||
( V_33 -> V_135 . V_67 == V_68 &&
V_33 -> V_135 . V_69 <= V_70 ) ;
}
int F_58 ( struct V_32 * V_33 , struct V_38 * V_39 )
{
struct V_138 * V_139 ;
struct V_140 * V_141 ;
struct V_76 * V_142 ;
struct V_143 * V_144 ;
struct V_50 * V_145 ;
struct V_113 * V_132 ;
struct V_105 * V_112 ;
F_59 ( V_39 -> V_40 >= sizeof( V_33 -> V_146 ) ) ;
F_60 ( V_33 , V_33 -> V_146 , V_39 -> V_40 ) ;
V_139 = (struct V_138 * ) V_33 -> V_146 ;
V_145 = (struct V_50 * ) V_139 ;
if ( V_33 -> V_35 == V_36 ) {
F_41 ( V_33 -> V_33 , L_15 ) ;
return 0 ;
}
switch ( V_139 -> V_47 ) {
case V_147 :
F_41 ( V_33 -> V_33 , L_16 ) ;
V_33 -> V_34 = 0 ;
V_141 = (struct V_140 * ) V_139 ;
F_41 ( V_33 -> V_33 , L_17 ,
V_68 , V_70 ,
V_141 -> V_148 . V_67 ,
V_141 -> V_148 . V_69 ) ;
if ( V_141 -> V_149 ) {
V_33 -> V_135 . V_67 = V_68 ;
V_33 -> V_135 . V_69 = V_70 ;
} else {
V_33 -> V_135 . V_67 =
V_141 -> V_148 . V_67 ;
V_33 -> V_135 . V_69 =
V_141 -> V_148 . V_69 ;
}
if ( ! F_57 ( V_33 ) ) {
F_61 ( V_33 -> V_33 , L_18 ) ;
V_33 -> V_35 = V_150 ;
if ( F_35 ( V_33 ) ) {
F_23 ( V_33 -> V_33 , L_19 ) ;
return - V_151 ;
}
break;
}
F_56 ( V_33 ) ;
if ( V_33 -> V_152 != V_153 ||
V_33 -> V_35 != V_58 ) {
F_23 ( V_33 -> V_33 , L_20 ,
V_33 -> V_152 , V_33 -> V_35 ) ;
return - V_154 ;
}
if ( F_25 ( V_33 ) ) {
F_23 ( V_33 -> V_33 , L_21 ) ;
return - V_151 ;
}
F_52 ( & V_33 -> V_60 ) ;
break;
case V_155 :
F_41 ( V_33 -> V_33 , L_22 ) ;
F_49 ( V_33 , V_145 , V_128 ) ;
break;
case V_116 :
F_41 ( V_33 -> V_33 , L_23 ) ;
F_49 ( V_33 , V_145 , V_129 ) ;
break;
case V_106 :
F_41 ( V_33 -> V_33 , L_24 ) ;
V_112 = (struct V_105 * ) V_139 ;
F_43 ( V_33 , V_112 ) ;
break;
case V_156 :
F_41 ( V_33 -> V_33 , L_25 ) ;
V_33 -> V_157 = V_158 ;
if ( F_62 ( & V_33 -> V_159 ) )
F_52 ( & V_33 -> V_159 ) ;
break;
case V_160 :
F_41 ( V_33 -> V_33 , L_26 ) ;
V_33 -> V_157 = V_158 ;
if ( F_62 ( & V_33 -> V_159 ) )
F_52 ( & V_33 -> V_159 ) ;
else
F_63 ( V_33 -> V_33 ) ;
break;
case V_161 :
F_41 ( V_33 -> V_33 , L_27 ) ;
V_33 -> V_34 = 0 ;
if ( V_33 -> V_152 != V_153 ||
V_33 -> V_35 != V_162 ) {
F_23 ( V_33 -> V_33 , L_28 ,
V_33 -> V_152 , V_33 -> V_35 ) ;
return - V_154 ;
}
V_142 = (struct V_76 * ) V_139 ;
if ( V_142 -> V_2 ) {
F_23 ( V_33 -> V_33 , L_29 ,
V_142 -> V_2 ,
F_1 ( V_142 -> V_2 ) ) ;
return - V_154 ;
}
F_26 ( V_33 , V_142 ) ;
V_33 -> V_37 ++ ;
if ( F_31 ( V_33 ) )
return - V_151 ;
break;
case V_163 :
F_41 ( V_33 -> V_33 , L_30 ) ;
V_33 -> V_34 = 0 ;
V_144 = (struct V_143 * ) V_139 ;
F_64 ( sizeof( V_33 -> V_91 )
< sizeof( V_144 -> V_164 ) ) ;
memcpy ( V_33 -> V_91 , V_144 -> V_164 ,
sizeof( V_144 -> V_164 ) ) ;
if ( V_33 -> V_152 != V_153 ||
V_33 -> V_35 != V_75 ) {
F_23 ( V_33 -> V_33 , L_31 ,
V_33 -> V_152 , V_33 -> V_35 ) ;
return - V_154 ;
}
V_33 -> V_35 = V_162 ;
if ( F_31 ( V_33 ) )
return - V_151 ;
break;
case V_165 :
F_41 ( V_33 -> V_33 , L_32 ) ;
V_33 -> V_34 = 0 ;
if ( V_33 -> V_35 != V_150 ) {
F_23 ( V_33 -> V_33 , L_33 ,
V_33 -> V_152 , V_33 -> V_35 ) ;
return - V_154 ;
}
V_33 -> V_152 = V_166 ;
F_65 ( V_33 -> V_33 , L_34 ) ;
return - V_154 ;
break;
case V_114 :
F_41 ( V_33 -> V_33 , L_35 ) ;
V_132 = (struct V_113 * ) V_139 ;
F_53 ( V_33 , V_132 ) ;
break;
case V_167 :
F_41 ( V_33 -> V_33 , L_36 ) ;
V_33 -> V_35 = V_150 ;
if ( F_35 ( V_33 ) ) {
F_23 ( V_33 -> V_33 , L_37 ) ;
return - V_151 ;
}
break;
default:
F_66 () ;
break;
}
return 0 ;
}
