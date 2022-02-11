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
static int F_4 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
int V_21 ;
V_18 -> V_22 = 0 ;
V_18 -> V_23 = 0 ;
V_18 -> V_24 = 0 ;
F_5 (b, dev->me_clients_map, MEI_CLIENTS_MAX)
V_18 -> V_22 ++ ;
if ( V_18 -> V_22 == 0 )
return 0 ;
F_6 ( V_18 -> V_25 ) ;
V_18 -> V_25 = NULL ;
F_7 ( & V_18 -> V_26 -> V_18 , L_2 ,
V_18 -> V_22 * sizeof( struct V_19 ) ) ;
V_20 = F_8 ( V_18 -> V_22 ,
sizeof( struct V_19 ) , V_27 ) ;
if ( ! V_20 ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_3 ) ;
return - V_28 ;
}
V_18 -> V_25 = V_20 ;
return 0 ;
}
static inline
void F_10 ( struct V_29 * V_30 , T_1 V_31 , void * V_32 , T_2 V_33 )
{
struct V_34 * V_35 = V_32 ;
memset ( V_35 , 0 , V_33 ) ;
V_35 -> V_31 = V_31 ;
V_35 -> V_36 = V_30 -> V_37 ;
V_35 -> V_38 = V_30 -> V_39 ;
}
static inline
bool F_11 ( struct V_29 * V_30 , void * V_32 )
{
struct V_34 * V_35 = V_32 ;
return V_30 -> V_37 == V_35 -> V_36 &&
V_30 -> V_39 == V_35 -> V_38 ;
}
void F_12 ( struct V_17 * V_18 )
{
V_18 -> V_40 = 0 ;
V_18 -> V_41 = V_42 ;
}
int F_13 ( struct V_17 * V_18 )
{
int V_43 ;
if ( V_18 -> V_41 > V_44 )
return 0 ;
F_14 ( & V_18 -> V_45 ) ;
V_43 = F_15 ( V_18 -> V_46 ,
V_18 -> V_41 == V_42 ||
V_18 -> V_41 >= V_47 ,
F_16 ( V_48 ) ) ;
F_17 ( & V_18 -> V_45 ) ;
if ( V_43 <= 0 && ( V_18 -> V_41 <= V_44 ) ) {
V_18 -> V_41 = V_42 ;
F_9 ( & V_18 -> V_26 -> V_18 , L_4 ) ;
return - V_49 ;
}
return 0 ;
}
int F_18 ( struct V_17 * V_18 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
struct V_54 * V_55 ;
const T_2 V_33 = sizeof( struct V_54 ) ;
int V_43 ;
F_19 ( V_51 , V_33 ) ;
V_55 = (struct V_54 * ) V_18 -> V_52 . V_56 ;
memset ( V_55 , 0 , V_33 ) ;
V_55 -> V_31 = V_57 ;
V_55 -> V_58 . V_59 = V_60 ;
V_55 -> V_58 . V_61 = V_62 ;
V_18 -> V_41 = V_42 ;
V_43 = F_20 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
if ( V_43 ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_5 ,
V_43 ) ;
return V_43 ;
}
V_18 -> V_41 = V_44 ;
V_18 -> V_40 = V_63 ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
struct V_64 * V_65 ;
const T_2 V_33 = sizeof( struct V_64 ) ;
int V_43 ;
F_19 ( V_51 , V_33 ) ;
V_65 = (struct V_64 * ) V_18 -> V_52 . V_56 ;
memset ( V_65 , 0 , V_33 ) ;
V_65 -> V_31 = V_66 ;
V_43 = F_20 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
if ( V_43 ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_6 ,
V_43 ) ;
return V_43 ;
}
V_18 -> V_41 = V_67 ;
V_18 -> V_40 = V_63 ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
struct V_68 * V_69 ;
const T_2 V_33 = sizeof( struct V_68 ) ;
unsigned long V_70 ;
unsigned long V_71 ;
int V_43 ;
V_71 = V_18 -> V_23 ;
V_70 = F_23 ( V_18 -> V_72 , V_73 ,
V_18 -> V_24 ) ;
if ( V_70 == V_73 ) {
V_18 -> V_41 = V_47 ;
F_24 ( & V_18 -> V_74 ) ;
return 0 ;
}
V_18 -> V_25 [ V_71 ] . V_75 = V_70 ;
V_18 -> V_25 [ V_71 ] . V_76 = 0 ;
F_19 ( V_51 , V_33 ) ;
V_69 = (struct V_68 * ) V_18 -> V_52 . V_56 ;
memset ( V_69 , 0 , sizeof( struct V_68 ) ) ;
V_69 -> V_31 = V_77 ;
V_69 -> V_78 = V_70 ;
V_43 = F_20 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
if ( V_43 ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_7 ,
V_43 ) ;
return V_43 ;
}
V_18 -> V_40 = V_63 ;
V_18 -> V_24 = V_70 ;
return 0 ;
}
static int F_25 ( struct V_17 * V_18 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
struct V_79 * V_80 =
(struct V_79 * ) V_18 -> V_52 . V_56 ;
const T_2 V_33 = sizeof( struct V_79 ) ;
F_19 ( V_51 , V_33 ) ;
memset ( V_80 , 0 , V_33 ) ;
V_80 -> V_31 = V_81 ;
V_80 -> V_82 = V_83 ;
return F_20 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
}
int F_26 ( struct V_17 * V_18 , struct V_29 * V_30 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
const T_2 V_33 = sizeof( struct V_84 ) ;
F_19 ( V_51 , V_33 ) ;
F_10 ( V_30 , V_85 , V_18 -> V_52 . V_56 , V_33 ) ;
F_27 ( V_18 , V_30 , L_8 ) ;
return F_20 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
}
static int F_28 ( struct V_17 * V_18 ,
struct V_84 * V_86 )
{
struct V_19 * V_87 ;
int V_88 ;
V_88 = F_29 ( V_18 , V_86 -> V_38 ) ;
if ( V_88 < 0 ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_9 ,
V_86 -> V_38 ) ;
return V_88 ;
}
V_87 = & V_18 -> V_25 [ V_88 ] ;
if ( V_87 -> V_89 . V_90 ) {
V_87 -> V_76 ++ ;
F_7 ( & V_18 -> V_26 -> V_18 , L_10 ,
V_86 -> V_38 ) ;
F_7 ( & V_18 -> V_26 -> V_18 , L_11 ,
V_87 -> V_76 ) ;
} else {
F_30 () ;
}
return 0 ;
}
static void F_31 ( struct V_17 * V_18 ,
struct V_84 * V_91 )
{
struct V_29 * V_30 ;
if ( ! V_91 -> V_36 ) {
F_28 ( V_18 , V_91 ) ;
return;
}
F_32 (cl, &dev->file_list, link) {
if ( F_11 ( V_30 , V_91 ) ) {
V_30 -> V_76 ++ ;
F_7 ( & V_18 -> V_26 -> V_18 , L_12 ,
V_91 -> V_36 , V_91 -> V_38 ) ;
F_7 ( & V_18 -> V_26 -> V_18 , L_13 ,
V_30 -> V_76 ) ;
break;
}
}
}
int F_33 ( struct V_17 * V_18 , struct V_29 * V_30 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
const T_2 V_33 = sizeof( struct V_92 ) ;
F_19 ( V_51 , V_33 ) ;
F_10 ( V_30 , V_93 , V_18 -> V_52 . V_56 , V_33 ) ;
return F_20 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
}
int F_34 ( struct V_17 * V_18 , struct V_29 * V_30 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
const T_2 V_33 = sizeof( struct V_94 ) ;
F_19 ( V_51 , V_33 ) ;
F_10 ( V_30 , V_95 , V_18 -> V_52 . V_56 , V_33 ) ;
return F_20 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
}
static void F_35 ( struct V_17 * V_18 ,
struct V_94 * V_96 )
{
struct V_29 * V_30 ;
struct V_97 * V_98 , * V_99 ;
F_7 ( & V_18 -> V_26 -> V_18 , L_14 ,
V_96 -> V_38 , V_96 -> V_36 , V_96 -> V_2 ) ;
F_36 (cb, next, &dev->ctrl_rd_list.list, list) {
V_30 = V_98 -> V_30 ;
if ( F_37 ( ! V_30 ) ) {
F_38 ( & V_98 -> V_100 ) ;
return;
}
if ( F_11 ( V_30 , V_96 ) ) {
F_38 ( & V_98 -> V_100 ) ;
if ( V_96 -> V_2 == V_101 )
V_30 -> V_102 = V_103 ;
V_30 -> V_2 = 0 ;
V_30 -> V_104 = 0 ;
break;
}
}
}
int F_39 ( struct V_17 * V_18 , struct V_29 * V_30 )
{
struct V_50 * V_51 = & V_18 -> V_52 . V_53 ;
const T_2 V_33 = sizeof( struct V_92 ) ;
F_19 ( V_51 , V_33 ) ;
F_10 ( V_30 , V_105 , V_18 -> V_52 . V_56 , V_33 ) ;
return F_20 ( V_18 , V_51 , V_18 -> V_52 . V_56 ) ;
}
static void F_40 ( struct V_17 * V_18 ,
struct V_94 * V_96 )
{
struct V_29 * V_30 ;
struct V_97 * V_98 , * V_99 ;
F_7 ( & V_18 -> V_26 -> V_18 , L_15 ,
V_96 -> V_38 , V_96 -> V_36 ,
F_1 ( V_96 -> V_2 ) ) ;
V_30 = NULL ;
F_36 (cb, next, &dev->ctrl_rd_list.list, list) {
V_30 = V_98 -> V_30 ;
if ( F_37 ( ! V_30 ) ) {
F_41 ( & V_98 -> V_100 ) ;
continue;
}
if ( V_98 -> V_106 != V_107 )
continue;
if ( F_11 ( V_30 , V_96 ) ) {
F_38 ( & V_98 -> V_100 ) ;
break;
}
}
if ( ! V_30 )
return;
V_30 -> V_104 = 0 ;
if ( V_96 -> V_2 == V_9 )
V_30 -> V_102 = V_108 ;
else
V_30 -> V_102 = V_103 ;
V_30 -> V_2 = F_3 ( V_96 -> V_2 ) ;
}
static int F_42 ( struct V_17 * V_18 ,
struct V_92 * V_109 )
{
struct V_29 * V_30 ;
struct V_97 * V_98 ;
F_32 (cl, &dev->file_list, link) {
if ( F_11 ( V_30 , V_109 ) ) {
F_7 ( & V_18 -> V_26 -> V_18 , L_16 ,
V_109 -> V_36 ,
V_109 -> V_38 ) ;
V_30 -> V_102 = V_103 ;
V_30 -> V_104 = 0 ;
V_98 = F_43 ( V_30 , NULL ) ;
if ( ! V_98 )
return - V_28 ;
V_98 -> V_106 = V_110 ;
F_27 ( V_18 , V_30 , L_17 ) ;
F_44 ( & V_98 -> V_100 , & V_18 -> V_111 . V_100 ) ;
break;
}
}
return 0 ;
}
bool F_45 ( struct V_17 * V_18 )
{
return ( V_18 -> V_112 . V_59 < V_60 ) ||
( V_18 -> V_112 . V_59 == V_60 &&
V_18 -> V_112 . V_61 <= V_62 ) ;
}
int F_46 ( struct V_17 * V_18 , struct V_50 * V_53 )
{
struct V_113 * V_114 ;
struct V_19 * V_115 ;
struct V_116 * V_117 ;
struct V_94 * V_118 ;
struct V_94 * V_119 ;
struct V_92 * V_109 ;
struct V_84 * V_91 ;
struct V_120 * V_121 ;
struct V_122 * V_123 ;
F_47 ( V_53 -> V_124 >= sizeof( V_18 -> V_125 ) ) ;
F_48 ( V_18 , V_18 -> V_125 , V_53 -> V_124 ) ;
V_114 = (struct V_113 * ) V_18 -> V_125 ;
if ( V_18 -> V_41 == V_42 ) {
F_7 ( & V_18 -> V_26 -> V_18 , L_18 ) ;
return 0 ;
}
switch ( V_114 -> V_31 ) {
case V_126 :
F_7 ( & V_18 -> V_26 -> V_18 , L_19 ) ;
V_18 -> V_40 = 0 ;
V_117 = (struct V_116 * ) V_114 ;
F_7 ( & V_18 -> V_26 -> V_18 , L_20 ,
V_60 , V_62 ,
V_117 -> V_127 . V_59 ,
V_117 -> V_127 . V_61 ) ;
if ( V_117 -> V_128 ) {
V_18 -> V_112 . V_59 = V_60 ;
V_18 -> V_112 . V_61 = V_62 ;
} else {
V_18 -> V_112 . V_59 =
V_117 -> V_127 . V_59 ;
V_18 -> V_112 . V_61 =
V_117 -> V_127 . V_61 ;
}
if ( ! F_45 ( V_18 ) ) {
F_49 ( & V_18 -> V_26 -> V_18 , L_21 ) ;
V_18 -> V_41 = V_129 ;
if ( F_25 ( V_18 ) ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_22 ) ;
return - V_130 ;
}
break;
}
if ( V_18 -> V_131 != V_132 ||
V_18 -> V_41 != V_44 ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_23 ,
V_18 -> V_131 , V_18 -> V_41 ) ;
return - V_133 ;
}
V_18 -> V_41 = V_47 ;
if ( F_21 ( V_18 ) ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_24 ) ;
return - V_130 ;
}
F_50 ( & V_18 -> V_46 ) ;
break;
case V_134 :
F_7 ( & V_18 -> V_26 -> V_18 , L_25 ) ;
V_118 = (struct V_94 * ) V_114 ;
F_40 ( V_18 , V_118 ) ;
F_51 ( & V_18 -> V_46 ) ;
break;
case V_95 :
F_7 ( & V_18 -> V_26 -> V_18 , L_26 ) ;
V_119 = (struct V_94 * ) V_114 ;
F_35 ( V_18 , V_119 ) ;
F_51 ( & V_18 -> V_46 ) ;
break;
case V_85 :
F_7 ( & V_18 -> V_26 -> V_18 , L_27 ) ;
V_91 = (struct V_84 * ) V_114 ;
F_31 ( V_18 , V_91 ) ;
break;
case V_135 :
F_7 ( & V_18 -> V_26 -> V_18 , L_28 ) ;
V_18 -> V_40 = 0 ;
if ( V_18 -> V_25 == NULL ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_29 ) ;
return - V_133 ;
}
V_121 = (struct V_120 * ) V_114 ;
V_115 = & V_18 -> V_25 [ V_18 -> V_23 ] ;
if ( V_121 -> V_2 ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_30 ,
V_121 -> V_2 ) ;
return - V_133 ;
}
if ( V_115 -> V_75 != V_121 -> V_78 ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_31 ,
V_115 -> V_75 , V_121 -> V_78 ) ;
return - V_133 ;
}
if ( V_18 -> V_131 != V_132 ||
V_18 -> V_41 != V_136 ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_32 ,
V_18 -> V_131 , V_18 -> V_41 ) ;
return - V_133 ;
}
V_115 -> V_89 = V_121 -> V_137 ;
V_18 -> V_24 ++ ;
V_18 -> V_23 ++ ;
if ( F_22 ( V_18 ) )
return - V_130 ;
break;
case V_138 :
F_7 ( & V_18 -> V_26 -> V_18 , L_33 ) ;
V_18 -> V_40 = 0 ;
V_123 = (struct V_122 * ) V_114 ;
F_52 ( sizeof( V_18 -> V_72 )
< sizeof( V_123 -> V_139 ) ) ;
memcpy ( V_18 -> V_72 , V_123 -> V_139 ,
sizeof( V_123 -> V_139 ) ) ;
if ( V_18 -> V_131 != V_132 ||
V_18 -> V_41 != V_67 ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_34 ,
V_18 -> V_131 , V_18 -> V_41 ) ;
return - V_133 ;
}
if ( F_4 ( V_18 ) ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_35 ) ;
return - V_28 ;
}
V_18 -> V_41 = V_136 ;
if ( F_22 ( V_18 ) )
return - V_130 ;
break;
case V_140 :
F_7 ( & V_18 -> V_26 -> V_18 , L_36 ) ;
V_18 -> V_40 = 0 ;
if ( V_18 -> V_41 != V_129 ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_37 ,
V_18 -> V_131 , V_18 -> V_41 ) ;
return - V_133 ;
}
V_18 -> V_131 = V_141 ;
F_53 ( & V_18 -> V_26 -> V_18 , L_38 ) ;
return - V_133 ;
break;
case V_93 :
F_7 ( & V_18 -> V_26 -> V_18 , L_39 ) ;
V_109 = (struct V_92 * ) V_114 ;
F_42 ( V_18 , V_109 ) ;
break;
case V_142 :
F_7 ( & V_18 -> V_26 -> V_18 , L_40 ) ;
V_18 -> V_41 = V_129 ;
if ( F_25 ( V_18 ) ) {
F_9 ( & V_18 -> V_26 -> V_18 , L_22 ) ;
return - V_130 ;
}
break;
default:
F_30 () ;
break;
}
return 0 ;
}
