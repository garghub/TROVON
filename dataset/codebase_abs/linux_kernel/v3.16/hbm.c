static const char * F_1 ( enum V_1 V_2 )
{
#define F_2 ( V_2 ) case MEI_CL_CONN_##status: return #status
switch ( V_2 ) {
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
default: return L_1 ;
}
#undef V_8
}
static int F_3 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_9 : return 0 ;
case V_10 : return - V_11 ;
case V_12 : return - V_13 ;
case V_14 : return - V_13 ;
case V_15 : return - V_16 ;
default: return - V_16 ;
}
}
void F_4 ( struct V_17 * V_18 )
{
V_18 -> V_19 = 0 ;
V_18 -> V_20 = V_21 ;
}
void F_5 ( struct V_17 * V_18 )
{
V_18 -> V_22 = 0 ;
V_18 -> V_23 = 0 ;
V_18 -> V_24 = 0 ;
F_6 ( V_18 -> V_25 ) ;
V_18 -> V_25 = NULL ;
F_4 ( V_18 ) ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_26 * V_27 ;
int V_28 ;
F_5 ( V_18 ) ;
F_8 (b, dev->me_clients_map, MEI_CLIENTS_MAX)
V_18 -> V_22 ++ ;
if ( V_18 -> V_22 == 0 )
return 0 ;
F_9 ( & V_18 -> V_29 -> V_18 , L_2 ,
V_18 -> V_22 * sizeof( struct V_26 ) ) ;
V_27 = F_10 ( V_18 -> V_22 ,
sizeof( struct V_26 ) , V_30 ) ;
if ( ! V_27 ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_3 ) ;
return - V_31 ;
}
V_18 -> V_25 = V_27 ;
return 0 ;
}
static inline
void F_12 ( struct V_32 * V_33 , T_1 V_34 , void * V_35 , T_2 V_36 )
{
struct V_37 * V_38 = V_35 ;
memset ( V_38 , 0 , V_36 ) ;
V_38 -> V_34 = V_34 ;
V_38 -> V_39 = V_33 -> V_40 ;
V_38 -> V_41 = V_33 -> V_42 ;
}
static inline
bool F_13 ( struct V_32 * V_33 , void * V_35 )
{
struct V_37 * V_38 = V_35 ;
return V_33 -> V_40 == V_38 -> V_39 &&
V_33 -> V_42 == V_38 -> V_41 ;
}
int F_14 ( struct V_17 * V_18 )
{
int V_43 ;
if ( V_18 -> V_20 > V_44 )
return 0 ;
F_15 ( & V_18 -> V_45 ) ;
V_43 = F_16 ( V_18 -> V_46 ,
V_18 -> V_20 == V_21 ||
V_18 -> V_20 >= V_47 ,
F_17 ( V_48 ) ) ;
F_18 ( & V_18 -> V_45 ) ;
if ( V_43 <= 0 && ( V_18 -> V_20 <= V_44 ) ) {
V_18 -> V_20 = V_21 ;
F_11 ( & V_18 -> V_29 -> V_18 , L_4 ) ;
return - V_49 ;
}
return 0 ;
}
int F_19 ( struct V_17 * V_18 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
struct V_54 * V_55 ;
const T_2 V_36 = sizeof( struct V_54 ) ;
int V_43 ;
F_20 ( V_51 , V_36 ) ;
V_55 = (struct V_54 * ) V_18 -> V_52 . V_56 ;
memset ( V_55 , 0 , V_36 ) ;
V_55 -> V_34 = V_57 ;
V_55 -> V_58 . V_59 = V_60 ;
V_55 -> V_58 . V_61 = V_62 ;
V_18 -> V_20 = V_21 ;
V_43 = F_21 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
if ( V_43 ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_5 ,
V_43 ) ;
return V_43 ;
}
V_18 -> V_20 = V_44 ;
V_18 -> V_19 = V_63 ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
struct V_64 * V_65 ;
const T_2 V_36 = sizeof( struct V_64 ) ;
int V_43 ;
F_20 ( V_51 , V_36 ) ;
V_65 = (struct V_64 * ) V_18 -> V_52 . V_56 ;
memset ( V_65 , 0 , V_36 ) ;
V_65 -> V_34 = V_66 ;
V_43 = F_21 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
if ( V_43 ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_6 ,
V_43 ) ;
return V_43 ;
}
V_18 -> V_20 = V_67 ;
V_18 -> V_19 = V_63 ;
return 0 ;
}
static int F_23 ( struct V_17 * V_18 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
struct V_68 * V_69 ;
const T_2 V_36 = sizeof( struct V_68 ) ;
unsigned long V_70 ;
unsigned long V_71 ;
int V_43 ;
V_71 = V_18 -> V_23 ;
V_70 = F_24 ( V_18 -> V_72 , V_73 ,
V_18 -> V_24 ) ;
if ( V_70 == V_73 ) {
V_18 -> V_20 = V_47 ;
F_25 ( & V_18 -> V_74 ) ;
return 0 ;
}
V_18 -> V_25 [ V_71 ] . V_75 = V_70 ;
V_18 -> V_25 [ V_71 ] . V_76 = 0 ;
F_20 ( V_51 , V_36 ) ;
V_69 = (struct V_68 * ) V_18 -> V_52 . V_56 ;
memset ( V_69 , 0 , sizeof( struct V_68 ) ) ;
V_69 -> V_34 = V_77 ;
V_69 -> V_78 = V_70 ;
V_43 = F_21 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
if ( V_43 ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_7 ,
V_43 ) ;
return V_43 ;
}
V_18 -> V_19 = V_63 ;
V_18 -> V_24 = V_70 ;
return 0 ;
}
int F_26 ( struct V_17 * V_18 , T_1 V_79 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
struct V_80 * V_81 ;
const T_2 V_36 = sizeof( struct V_80 ) ;
int V_43 ;
F_20 ( V_51 , V_36 ) ;
V_81 = (struct V_80 * ) V_18 -> V_52 . V_56 ;
memset ( V_81 , 0 , V_36 ) ;
V_81 -> V_34 = V_79 ;
V_43 = F_21 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
if ( V_43 )
F_11 ( & V_18 -> V_29 -> V_18 , L_8 ) ;
return V_43 ;
}
static int F_27 ( struct V_17 * V_18 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
struct V_82 * V_81 =
(struct V_82 * ) V_18 -> V_52 . V_56 ;
const T_2 V_36 = sizeof( struct V_82 ) ;
F_20 ( V_51 , V_36 ) ;
memset ( V_81 , 0 , V_36 ) ;
V_81 -> V_34 = V_83 ;
V_81 -> V_84 = V_85 ;
return F_21 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
}
int F_28 ( struct V_17 * V_18 , struct V_32 * V_33 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
const T_2 V_36 = sizeof( struct V_86 ) ;
F_20 ( V_51 , V_36 ) ;
F_12 ( V_33 , V_87 , V_18 -> V_52 . V_56 , V_36 ) ;
F_29 ( V_18 , V_33 , L_9 ) ;
return F_21 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
}
static int F_30 ( struct V_17 * V_18 ,
struct V_86 * V_88 )
{
struct V_26 * V_89 ;
int V_90 ;
V_90 = F_31 ( V_18 , V_88 -> V_41 ) ;
if ( V_90 < 0 ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_10 ,
V_88 -> V_41 ) ;
return V_90 ;
}
V_89 = & V_18 -> V_25 [ V_90 ] ;
if ( V_89 -> V_91 . V_92 ) {
V_89 -> V_76 ++ ;
F_9 ( & V_18 -> V_29 -> V_18 , L_11 ,
V_88 -> V_41 ) ;
F_9 ( & V_18 -> V_29 -> V_18 , L_12 ,
V_89 -> V_76 ) ;
} else {
F_32 () ;
}
return 0 ;
}
static void F_33 ( struct V_17 * V_18 ,
struct V_86 * V_93 )
{
struct V_32 * V_33 ;
if ( ! V_93 -> V_39 ) {
F_30 ( V_18 , V_93 ) ;
return;
}
F_34 (cl, &dev->file_list, link) {
if ( F_13 ( V_33 , V_93 ) ) {
V_33 -> V_76 ++ ;
F_9 ( & V_18 -> V_29 -> V_18 , L_13 ,
V_93 -> V_39 , V_93 -> V_41 ) ;
F_9 ( & V_18 -> V_29 -> V_18 , L_14 ,
V_33 -> V_76 ) ;
break;
}
}
}
int F_35 ( struct V_17 * V_18 , struct V_32 * V_33 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
const T_2 V_36 = sizeof( struct V_94 ) ;
F_20 ( V_51 , V_36 ) ;
F_12 ( V_33 , V_95 , V_18 -> V_52 . V_56 , V_36 ) ;
return F_21 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
}
int F_36 ( struct V_17 * V_18 , struct V_32 * V_33 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
const T_2 V_36 = sizeof( struct V_96 ) ;
F_20 ( V_51 , V_36 ) ;
F_12 ( V_33 , V_97 , V_18 -> V_52 . V_56 , V_36 ) ;
return F_21 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
}
static void F_37 ( struct V_17 * V_18 ,
struct V_96 * V_98 )
{
struct V_32 * V_33 ;
struct V_99 * V_100 , * V_101 ;
F_9 ( & V_18 -> V_29 -> V_18 , L_15 ,
V_98 -> V_41 , V_98 -> V_39 , V_98 -> V_2 ) ;
F_38 (cb, next, &dev->ctrl_rd_list.list, list) {
V_33 = V_100 -> V_33 ;
if ( F_39 ( ! V_33 ) ) {
F_40 ( & V_100 -> V_102 ) ;
return;
}
if ( F_13 ( V_33 , V_98 ) ) {
F_40 ( & V_100 -> V_102 ) ;
if ( V_98 -> V_2 == V_103 )
V_33 -> V_104 = V_105 ;
V_33 -> V_2 = 0 ;
V_33 -> V_106 = 0 ;
break;
}
}
}
int F_41 ( struct V_17 * V_18 , struct V_32 * V_33 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
const T_2 V_36 = sizeof( struct V_94 ) ;
F_20 ( V_51 , V_36 ) ;
F_12 ( V_33 , V_107 , V_18 -> V_52 . V_56 , V_36 ) ;
return F_21 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
}
static void F_42 ( struct V_17 * V_18 ,
struct V_96 * V_98 )
{
struct V_32 * V_33 ;
struct V_99 * V_100 , * V_101 ;
F_9 ( & V_18 -> V_29 -> V_18 , L_16 ,
V_98 -> V_41 , V_98 -> V_39 ,
F_1 ( V_98 -> V_2 ) ) ;
V_33 = NULL ;
F_38 (cb, next, &dev->ctrl_rd_list.list, list) {
V_33 = V_100 -> V_33 ;
if ( F_39 ( ! V_33 ) ) {
F_43 ( & V_100 -> V_102 ) ;
continue;
}
if ( V_100 -> V_108 != V_109 )
continue;
if ( F_13 ( V_33 , V_98 ) ) {
F_40 ( & V_100 -> V_102 ) ;
break;
}
}
if ( ! V_33 )
return;
V_33 -> V_106 = 0 ;
if ( V_98 -> V_2 == V_9 )
V_33 -> V_104 = V_110 ;
else
V_33 -> V_104 = V_105 ;
V_33 -> V_2 = F_3 ( V_98 -> V_2 ) ;
}
static int F_44 ( struct V_17 * V_18 ,
struct V_94 * V_111 )
{
struct V_32 * V_33 ;
struct V_99 * V_100 ;
F_34 (cl, &dev->file_list, link) {
if ( F_13 ( V_33 , V_111 ) ) {
F_9 ( & V_18 -> V_29 -> V_18 , L_17 ,
V_111 -> V_39 ,
V_111 -> V_41 ) ;
V_33 -> V_104 = V_105 ;
V_33 -> V_106 = 0 ;
V_100 = F_45 ( V_33 , NULL ) ;
if ( ! V_100 )
return - V_31 ;
V_100 -> V_108 = V_112 ;
F_29 ( V_18 , V_33 , L_18 ) ;
F_46 ( & V_100 -> V_102 , & V_18 -> V_113 . V_102 ) ;
break;
}
}
return 0 ;
}
bool F_47 ( struct V_17 * V_18 )
{
return ( V_18 -> V_114 . V_59 < V_60 ) ||
( V_18 -> V_114 . V_59 == V_60 &&
V_18 -> V_114 . V_61 <= V_62 ) ;
}
int F_48 ( struct V_17 * V_18 , struct V_50 * V_53 )
{
struct V_115 * V_116 ;
struct V_26 * V_117 ;
struct V_118 * V_119 ;
struct V_96 * V_120 ;
struct V_96 * V_121 ;
struct V_94 * V_111 ;
struct V_86 * V_93 ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
F_49 ( V_53 -> V_126 >= sizeof( V_18 -> V_127 ) ) ;
F_50 ( V_18 , V_18 -> V_127 , V_53 -> V_126 ) ;
V_116 = (struct V_115 * ) V_18 -> V_127 ;
if ( V_18 -> V_20 == V_21 ) {
F_9 ( & V_18 -> V_29 -> V_18 , L_19 ) ;
return 0 ;
}
switch ( V_116 -> V_34 ) {
case V_128 :
F_9 ( & V_18 -> V_29 -> V_18 , L_20 ) ;
V_18 -> V_19 = 0 ;
V_119 = (struct V_118 * ) V_116 ;
F_9 ( & V_18 -> V_29 -> V_18 , L_21 ,
V_60 , V_62 ,
V_119 -> V_129 . V_59 ,
V_119 -> V_129 . V_61 ) ;
if ( V_119 -> V_130 ) {
V_18 -> V_114 . V_59 = V_60 ;
V_18 -> V_114 . V_61 = V_62 ;
} else {
V_18 -> V_114 . V_59 =
V_119 -> V_129 . V_59 ;
V_18 -> V_114 . V_61 =
V_119 -> V_129 . V_61 ;
}
if ( ! F_47 ( V_18 ) ) {
F_51 ( & V_18 -> V_29 -> V_18 , L_22 ) ;
V_18 -> V_20 = V_131 ;
if ( F_27 ( V_18 ) ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_23 ) ;
return - V_132 ;
}
break;
}
if ( V_18 -> V_133 != V_134 ||
V_18 -> V_20 != V_44 ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_24 ,
V_18 -> V_133 , V_18 -> V_20 ) ;
return - V_135 ;
}
V_18 -> V_20 = V_47 ;
if ( F_22 ( V_18 ) ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_25 ) ;
return - V_132 ;
}
F_52 ( & V_18 -> V_46 ) ;
break;
case V_136 :
F_9 ( & V_18 -> V_29 -> V_18 , L_26 ) ;
V_120 = (struct V_96 * ) V_116 ;
F_42 ( V_18 , V_120 ) ;
F_53 ( & V_18 -> V_46 ) ;
break;
case V_97 :
F_9 ( & V_18 -> V_29 -> V_18 , L_27 ) ;
V_121 = (struct V_96 * ) V_116 ;
F_37 ( V_18 , V_121 ) ;
F_53 ( & V_18 -> V_46 ) ;
break;
case V_87 :
F_9 ( & V_18 -> V_29 -> V_18 , L_28 ) ;
V_93 = (struct V_86 * ) V_116 ;
F_33 ( V_18 , V_93 ) ;
break;
case V_137 :
F_9 ( & V_18 -> V_29 -> V_18 , L_29 ) ;
V_18 -> V_138 = V_139 ;
if ( F_54 ( & V_18 -> V_140 ) )
F_53 ( & V_18 -> V_140 ) ;
break;
case V_141 :
F_9 ( & V_18 -> V_29 -> V_18 , L_30 ) ;
V_18 -> V_138 = V_139 ;
if ( F_54 ( & V_18 -> V_140 ) )
F_53 ( & V_18 -> V_140 ) ;
else
F_55 ( & V_18 -> V_29 -> V_18 ) ;
break;
case V_142 :
F_9 ( & V_18 -> V_29 -> V_18 , L_31 ) ;
V_18 -> V_19 = 0 ;
if ( V_18 -> V_25 == NULL ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_32 ) ;
return - V_135 ;
}
V_123 = (struct V_122 * ) V_116 ;
V_117 = & V_18 -> V_25 [ V_18 -> V_23 ] ;
if ( V_123 -> V_2 ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_33 ,
V_123 -> V_2 ) ;
return - V_135 ;
}
if ( V_117 -> V_75 != V_123 -> V_78 ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_34 ,
V_117 -> V_75 , V_123 -> V_78 ) ;
return - V_135 ;
}
if ( V_18 -> V_133 != V_134 ||
V_18 -> V_20 != V_143 ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_35 ,
V_18 -> V_133 , V_18 -> V_20 ) ;
return - V_135 ;
}
V_117 -> V_91 = V_123 -> V_144 ;
V_18 -> V_24 ++ ;
V_18 -> V_23 ++ ;
if ( F_23 ( V_18 ) )
return - V_132 ;
break;
case V_145 :
F_9 ( & V_18 -> V_29 -> V_18 , L_36 ) ;
V_18 -> V_19 = 0 ;
V_125 = (struct V_124 * ) V_116 ;
F_56 ( sizeof( V_18 -> V_72 )
< sizeof( V_125 -> V_146 ) ) ;
memcpy ( V_18 -> V_72 , V_125 -> V_146 ,
sizeof( V_125 -> V_146 ) ) ;
if ( V_18 -> V_133 != V_134 ||
V_18 -> V_20 != V_67 ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_37 ,
V_18 -> V_133 , V_18 -> V_20 ) ;
return - V_135 ;
}
if ( F_7 ( V_18 ) ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_38 ) ;
return - V_31 ;
}
V_18 -> V_20 = V_143 ;
if ( F_23 ( V_18 ) )
return - V_132 ;
break;
case V_147 :
F_9 ( & V_18 -> V_29 -> V_18 , L_39 ) ;
V_18 -> V_19 = 0 ;
if ( V_18 -> V_20 != V_131 ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_40 ,
V_18 -> V_133 , V_18 -> V_20 ) ;
return - V_135 ;
}
V_18 -> V_133 = V_148 ;
F_57 ( & V_18 -> V_29 -> V_18 , L_41 ) ;
return - V_135 ;
break;
case V_95 :
F_9 ( & V_18 -> V_29 -> V_18 , L_42 ) ;
V_111 = (struct V_94 * ) V_116 ;
F_44 ( V_18 , V_111 ) ;
break;
case V_149 :
F_9 ( & V_18 -> V_29 -> V_18 , L_43 ) ;
V_18 -> V_20 = V_131 ;
if ( F_27 ( V_18 ) ) {
F_11 ( & V_18 -> V_29 -> V_18 , L_23 ) ;
return - V_132 ;
}
break;
default:
F_32 () ;
break;
}
return 0 ;
}
