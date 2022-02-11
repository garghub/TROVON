int F_1 ( void )
{
struct V_1 * V_2 ;
if ( V_3 )
return - V_4 ;
V_2 = F_2 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_3 ( V_2 ) )
return F_4 ( V_2 ) ;
V_3 = V_2 ;
return 0 ;
}
void F_5 ( void )
{
if ( V_3 ) {
F_6 ( V_3 ) ;
V_3 = NULL ;
}
}
int F_7 ( struct V_5 * V_6 )
{
F_8 ( & V_7 ) ;
F_9 ( & V_6 -> V_8 , & V_9 ) ;
F_10 ( & V_7 ) ;
return 0 ;
}
int F_11 ( struct V_5 * V_6 )
{
F_8 ( & V_7 ) ;
F_12 ( & V_6 -> V_8 ) ;
F_10 ( & V_7 ) ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 , struct V_12 * V_13 , void * V_14 )
{
int V_15 ;
F_8 ( V_13 ) ;
V_15 = F_14 ( V_11 , V_14 , 1 , 0 , V_16 ) ;
F_10 ( V_13 ) ;
return V_15 ;
}
static void F_15 ( struct V_10 * V_11 , struct V_12 * V_13 , T_1 V_17 )
{
F_8 ( V_13 ) ;
F_16 ( V_11 , V_17 ) ;
F_10 ( V_13 ) ;
}
static void * F_17 ( struct V_10 * V_11 , struct V_12 * V_13 , T_1 V_17 )
{
void * V_14 ;
F_8 ( V_13 ) ;
V_14 = F_18 ( V_11 , V_17 ) ;
F_10 ( V_13 ) ;
return V_14 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
if ( V_6 -> V_20 || ( ! F_20 ( V_19 -> V_21 ) &&
! F_21 ( V_6 -> V_22 ) ) )
return - V_23 ;
if ( V_6 -> V_24 &&
V_6 -> V_24 ( V_6 -> V_22 , V_19 ) )
return - V_25 ;
return 0 ;
}
static struct V_5 * F_22 ( struct V_26 * V_27 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 ;
T_1 V_28 = V_19 -> V_28 ;
int V_15 ;
if ( V_28 ) {
V_6 = F_17 ( & V_27 -> V_29 , & V_27 -> V_30 , V_28 ) ;
if ( ! V_6 ) {
F_23 ( L_2 , V_28 ) ;
return F_24 ( - V_31 ) ;
}
V_15 = F_19 ( V_6 , V_19 ) ;
if ( V_15 < 0 ) {
F_23 ( L_3 , V_28 , V_15 ) ;
return F_24 ( V_15 ) ;
}
return V_6 ;
} else {
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
V_15 = F_19 ( V_6 , V_19 ) ;
if ( V_15 == 0 )
return V_6 ;
}
F_23 ( L_4 ) ;
}
return F_24 ( - V_31 ) ;
}
static struct V_5 * F_26 ( T_1 V_32 )
{
struct V_5 * V_6 ;
struct V_33 * V_34 ;
int V_35 = 0 ;
F_27 ( L_5 , V_32 ) ;
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
F_27 ( L_6 , V_35 ++ , ( int ) V_6 ) ;
F_8 ( & V_6 -> V_36 ) ;
F_25 (c_node, &ippdrv->cmd_list, list) {
if ( V_34 -> V_19 . V_32 == V_32 ) {
F_10 ( & V_6 -> V_36 ) ;
return V_6 ;
}
}
F_10 ( & V_6 -> V_36 ) ;
}
return F_24 ( - V_31 ) ;
}
int F_28 ( struct V_37 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_45 * V_22 = V_43 -> V_46 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_47 * V_48 = V_39 ;
struct V_5 * V_6 ;
int V_35 = 0 ;
if ( ! V_27 ) {
F_30 ( L_7 ) ;
return - V_25 ;
}
if ( ! V_48 ) {
F_30 ( L_8 ) ;
return - V_25 ;
}
F_27 ( L_9 , V_48 -> V_28 ) ;
if ( ! V_48 -> V_28 ) {
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list)
V_35 ++ ;
V_48 -> V_35 = V_35 ;
} else {
V_6 = F_17 ( & V_27 -> V_29 , & V_27 -> V_30 ,
V_48 -> V_28 ) ;
if ( ! V_6 ) {
F_30 ( L_10 ,
V_48 -> V_28 ) ;
return - V_31 ;
}
* V_48 = V_6 -> V_48 ;
}
return 0 ;
}
static void F_31 ( struct V_18 * V_19 ,
int V_49 )
{
struct V_50 * V_51 = & V_19 -> V_51 [ V_49 ] ;
struct V_52 * V_53 = & V_51 -> V_53 ;
struct V_54 * V_55 = & V_51 -> V_55 ;
F_27 ( L_11 ,
V_19 -> V_32 , V_49 ? L_12 : L_13 , V_51 -> V_56 ) ;
F_27 ( L_14 ,
V_53 -> V_57 , V_53 -> V_58 , V_53 -> V_59 , V_53 -> V_60 ,
V_55 -> V_61 , V_55 -> V_62 , V_51 -> V_63 , V_51 -> V_64 ) ;
}
static int F_32 ( struct V_18 * V_19 )
{
struct V_5 * V_6 ;
struct V_33 * V_34 ;
T_1 V_32 = V_19 -> V_32 ;
F_27 ( L_5 , V_32 ) ;
V_6 = F_26 ( V_32 ) ;
if ( F_3 ( V_6 ) ) {
F_30 ( L_15 ) ;
return - V_25 ;
}
F_8 ( & V_6 -> V_36 ) ;
F_25 (c_node, &ippdrv->cmd_list, list) {
if ( ( V_34 -> V_19 . V_32 == V_32 ) &&
( V_34 -> V_65 == V_66 ) ) {
F_10 ( & V_6 -> V_36 ) ;
F_27 ( L_16 ,
V_19 -> V_21 , ( int ) V_6 ) ;
V_34 -> V_19 = * V_19 ;
return 0 ;
}
}
F_10 ( & V_6 -> V_36 ) ;
F_30 ( L_17 ) ;
return - V_25 ;
}
static struct V_67 * F_33 ( void )
{
struct V_67 * V_68 ;
V_68 = F_34 ( sizeof( * V_68 ) , V_16 ) ;
if ( ! V_68 )
return F_24 ( - V_69 ) ;
F_35 ( (struct V_70 * ) V_68 , V_71 ) ;
return V_68 ;
}
static struct V_72 * F_36 ( void )
{
struct V_72 * V_73 ;
V_73 = F_34 ( sizeof( * V_73 ) , V_16 ) ;
if ( ! V_73 )
return F_24 ( - V_69 ) ;
F_35 ( & V_73 -> V_74 , V_75 ) ;
return V_73 ;
}
int F_37 ( struct V_37 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_45 * V_22 = V_43 -> V_46 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_18 * V_19 = V_39 ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
int V_15 , V_76 ;
if ( ! V_27 ) {
F_30 ( L_7 ) ;
return - V_25 ;
}
if ( ! V_19 ) {
F_30 ( L_8 ) ;
return - V_25 ;
}
F_38 (i)
F_31 ( V_19 , V_76 ) ;
if ( V_19 -> V_32 ) {
F_27 ( L_5 , V_19 -> V_32 ) ;
return F_32 ( V_19 ) ;
}
V_6 = F_22 ( V_27 , V_19 ) ;
if ( F_3 ( V_6 ) ) {
F_30 ( L_15 ) ;
return - V_25 ;
}
V_34 = F_34 ( sizeof( * V_34 ) , V_16 ) ;
if ( ! V_34 )
return - V_69 ;
V_15 = F_13 ( & V_27 -> V_77 , & V_27 -> V_78 , V_34 ) ;
if ( V_15 < 0 ) {
F_30 ( L_18 ) ;
goto V_79;
}
V_19 -> V_32 = V_15 ;
F_27 ( L_19 ,
V_19 -> V_32 , V_19 -> V_21 , ( int ) V_6 ) ;
V_34 -> V_22 = V_22 ;
V_34 -> V_19 = * V_19 ;
V_34 -> V_65 = V_80 ;
V_34 -> V_81 = F_33 () ;
if ( F_3 ( V_34 -> V_81 ) ) {
F_30 ( L_20 ) ;
goto V_82;
}
V_34 -> V_83 = F_33 () ;
if ( F_3 ( V_34 -> V_83 ) ) {
F_30 ( L_21 ) ;
goto V_84;
}
V_34 -> V_73 = F_36 () ;
if ( F_3 ( V_34 -> V_73 ) ) {
F_30 ( L_22 ) ;
goto V_85;
}
F_39 ( & V_34 -> V_13 ) ;
F_39 ( & V_34 -> V_86 ) ;
F_39 ( & V_34 -> V_87 ) ;
F_40 ( & V_34 -> V_88 ) ;
F_40 ( & V_34 -> V_89 ) ;
F_38 (i)
F_41 ( & V_34 -> V_90 [ V_76 ] ) ;
F_41 ( & V_34 -> V_91 ) ;
F_8 ( & V_6 -> V_36 ) ;
F_9 ( & V_34 -> V_92 , & V_6 -> V_93 ) ;
F_10 ( & V_6 -> V_36 ) ;
if ( ! F_20 ( V_19 -> V_21 ) )
V_6 -> V_20 = true ;
return 0 ;
V_85:
F_42 ( V_34 -> V_83 ) ;
V_84:
F_42 ( V_34 -> V_81 ) ;
V_82:
F_15 ( & V_27 -> V_77 , & V_27 -> V_78 , V_19 -> V_32 ) ;
V_79:
F_42 ( V_34 ) ;
return V_15 ;
}
static void F_43 ( struct V_26 * V_27 ,
struct V_33 * V_34 )
{
F_12 ( & V_34 -> V_92 ) ;
F_15 ( & V_27 -> V_77 , & V_27 -> V_78 ,
V_34 -> V_19 . V_32 ) ;
F_44 ( & V_34 -> V_13 ) ;
F_44 ( & V_34 -> V_86 ) ;
F_44 ( & V_34 -> V_87 ) ;
F_42 ( V_34 -> V_81 ) ;
F_42 ( V_34 -> V_83 ) ;
F_42 ( V_34 -> V_73 ) ;
F_42 ( V_34 ) ;
}
static bool F_45 ( struct V_33 * V_34 )
{
switch ( V_34 -> V_19 . V_21 ) {
case V_94 :
return ! F_46 ( & V_34 -> V_90 [ V_95 ] ) ;
case V_96 :
return ! F_46 ( & V_34 -> V_90 [ V_97 ] ) ;
case V_98 :
default:
return ! F_46 ( & V_34 -> V_90 [ V_97 ] ) &&
! F_46 ( & V_34 -> V_90 [ V_95 ] ) ;
}
}
static struct V_99
* F_47 ( struct V_33 * V_34 ,
struct V_100 * V_101 )
{
struct V_99 * V_102 ;
struct V_103 * V_104 ;
int V_35 = 0 ;
F_27 ( L_23 , V_101 -> V_105 ) ;
V_104 = & V_34 -> V_90 [ V_101 -> V_106 ] ;
F_25 (m_node, head, list) {
F_27 ( L_24 , V_35 ++ , ( int ) V_102 ) ;
if ( V_102 -> V_105 == V_101 -> V_105 )
return V_102 ;
}
return NULL ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_33 * V_34 ,
struct V_99 * V_102 )
{
struct V_107 * V_108 = NULL ;
int V_15 = 0 ;
F_27 ( L_25 , ( int ) V_102 ) ;
if ( ! V_102 ) {
F_30 ( L_26 ) ;
return - V_109 ;
}
F_27 ( L_27 , V_102 -> V_106 ) ;
V_108 = V_6 -> V_108 [ V_102 -> V_106 ] ;
if ( ! V_108 ) {
F_30 ( L_28 ) ;
return - V_109 ;
}
if ( V_108 -> V_110 ) {
V_15 = V_108 -> V_110 ( V_6 -> V_22 , & V_102 -> V_111 ,
V_102 -> V_105 , V_112 ) ;
if ( V_15 ) {
F_30 ( L_29 ) ;
return V_15 ;
}
}
return V_15 ;
}
static struct V_99
* F_49 ( struct V_37 * V_38 ,
struct V_40 * V_41 ,
struct V_33 * V_34 ,
struct V_100 * V_101 )
{
struct V_99 * V_102 ;
struct V_113 * V_111 ;
int V_76 ;
V_102 = F_34 ( sizeof( * V_102 ) , V_16 ) ;
if ( ! V_102 )
return F_24 ( - V_69 ) ;
V_111 = & V_102 -> V_111 ;
V_102 -> V_106 = V_101 -> V_106 ;
V_102 -> V_32 = V_101 -> V_32 ;
V_102 -> V_105 = V_101 -> V_105 ;
F_27 ( L_30 , ( int ) V_102 , V_101 -> V_106 ) ;
F_27 ( L_31 , V_101 -> V_32 , V_102 -> V_105 ) ;
F_50 (i) {
F_27 ( L_32 , V_76 , V_101 -> V_114 [ V_76 ] ) ;
if ( V_101 -> V_114 [ V_76 ] ) {
T_2 * V_115 ;
V_115 = F_51 ( V_38 ,
V_101 -> V_114 [ V_76 ] , V_41 ) ;
if ( F_3 ( V_115 ) ) {
F_30 ( L_33 ) ;
goto V_79;
}
V_111 -> V_116 [ V_76 ] = V_101 -> V_114 [ V_76 ] ;
V_111 -> V_117 [ V_76 ] = * V_115 ;
F_27 ( L_34 , V_76 ,
V_111 -> V_117 [ V_76 ] , V_111 -> V_116 [ V_76 ] ) ;
}
}
V_102 -> V_118 = V_41 ;
F_8 ( & V_34 -> V_86 ) ;
F_9 ( & V_102 -> V_92 , & V_34 -> V_90 [ V_101 -> V_106 ] ) ;
F_10 ( & V_34 -> V_86 ) ;
return V_102 ;
V_79:
F_42 ( V_102 ) ;
return F_24 ( - V_109 ) ;
}
static int F_52 ( struct V_37 * V_38 ,
struct V_33 * V_34 ,
struct V_99 * V_102 )
{
int V_76 ;
F_27 ( L_25 , ( int ) V_102 ) ;
if ( ! V_102 ) {
F_30 ( L_35 ) ;
return - V_109 ;
}
F_27 ( L_27 , V_102 -> V_106 ) ;
F_50 (i) {
unsigned long V_114 = V_102 -> V_111 . V_116 [ V_76 ] ;
if ( V_114 )
F_53 ( V_38 , V_114 ,
V_102 -> V_118 ) ;
}
F_12 ( & V_102 -> V_92 ) ;
F_42 ( V_102 ) ;
return 0 ;
}
static void F_54 ( struct V_119 * V_120 )
{
F_42 ( V_120 ) ;
}
static int F_55 ( struct V_37 * V_38 ,
struct V_40 * V_41 ,
struct V_33 * V_34 ,
struct V_100 * V_101 )
{
struct V_121 * V_122 ;
unsigned long V_123 ;
F_27 ( L_36 , V_101 -> V_106 , V_101 -> V_105 ) ;
V_122 = F_34 ( sizeof( * V_122 ) , V_16 ) ;
if ( ! V_122 ) {
F_56 ( & V_38 -> V_87 , V_123 ) ;
V_41 -> V_124 += sizeof( V_122 -> V_120 ) ;
F_57 ( & V_38 -> V_87 , V_123 ) ;
return - V_69 ;
}
V_122 -> V_120 . V_117 . type = V_125 ;
V_122 -> V_120 . V_117 . V_126 = sizeof( V_122 -> V_120 ) ;
V_122 -> V_120 . V_127 = V_101 -> V_127 ;
V_122 -> V_120 . V_32 = V_101 -> V_32 ;
V_122 -> V_120 . V_105 [ V_95 ] = V_101 -> V_105 ;
V_122 -> V_117 . V_120 = & V_122 -> V_120 . V_117 ;
V_122 -> V_117 . V_43 = V_41 ;
V_122 -> V_117 . V_128 = F_54 ;
F_8 ( & V_34 -> V_87 ) ;
F_9 ( & V_122 -> V_117 . V_129 , & V_34 -> V_91 ) ;
F_10 ( & V_34 -> V_87 ) ;
return 0 ;
}
static void F_58 ( struct V_33 * V_34 ,
struct V_100 * V_101 )
{
struct V_121 * V_122 , * V_130 ;
int V_35 = 0 ;
F_8 ( & V_34 -> V_87 ) ;
F_59 (e, te, &c_node->event_list, base.link) {
F_27 ( L_37 , V_35 ++ , ( int ) V_122 ) ;
if ( ! V_101 ) {
F_12 ( & V_122 -> V_117 . V_129 ) ;
F_42 ( V_122 ) ;
}
if ( V_101 && ( V_101 -> V_105 ==
V_122 -> V_120 . V_105 [ V_95 ] ) ) {
F_12 ( & V_122 -> V_117 . V_129 ) ;
F_42 ( V_122 ) ;
goto V_131;
}
}
V_131:
F_10 ( & V_34 -> V_87 ) ;
return;
}
static void F_60 ( struct V_45 * V_22 ,
struct V_5 * V_6 ,
struct V_67 * V_68 ,
struct V_33 * V_34 )
{
struct V_26 * V_27 = F_29 ( V_22 ) ;
V_68 -> V_6 = V_6 ;
V_68 -> V_34 = V_34 ;
F_61 ( V_27 -> V_132 , (struct V_70 * ) V_68 ) ;
}
static int F_62 ( struct V_45 * V_22 ,
struct V_33 * V_34 ,
struct V_99 * V_102 ,
struct V_100 * V_101 )
{
struct V_5 * V_6 ;
struct V_18 * V_19 ;
struct V_107 * V_108 ;
int V_15 ;
V_6 = F_26 ( V_101 -> V_32 ) ;
if ( F_3 ( V_6 ) ) {
F_30 ( L_15 ) ;
return - V_109 ;
}
V_108 = V_6 -> V_108 [ V_101 -> V_106 ] ;
if ( ! V_108 ) {
F_30 ( L_38 ) ;
return - V_109 ;
}
V_19 = & V_34 -> V_19 ;
if ( V_34 -> V_65 != V_133 ) {
F_27 ( L_39 ) ;
return 0 ;
}
F_8 ( & V_34 -> V_86 ) ;
if ( ! F_45 ( V_34 ) ) {
F_10 ( & V_34 -> V_86 ) ;
F_27 ( L_40 ) ;
return 0 ;
}
if ( F_20 ( V_19 -> V_21 ) ) {
struct V_67 * V_68 = V_34 -> V_81 ;
V_68 -> V_134 = V_135 ;
F_60 ( V_22 , V_6 , V_68 , V_34 ) ;
} else {
V_15 = F_48 ( V_6 , V_34 , V_102 ) ;
if ( V_15 ) {
F_10 ( & V_34 -> V_86 ) ;
F_30 ( L_41 ) ;
return V_15 ;
}
}
F_10 ( & V_34 -> V_86 ) ;
return 0 ;
}
static void F_63 ( struct V_37 * V_38 ,
struct V_33 * V_34 ,
struct V_100 * V_101 )
{
struct V_99 * V_102 , * V_136 ;
F_8 ( & V_34 -> V_86 ) ;
F_59 (m_node, tm_node,
&c_node->mem_list[qbuf->ops_id], list) {
if ( V_102 -> V_105 == V_101 -> V_105 &&
V_102 -> V_106 == V_101 -> V_106 )
F_52 ( V_38 , V_34 , V_102 ) ;
}
F_10 ( & V_34 -> V_86 ) ;
}
int F_64 ( struct V_37 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_45 * V_22 = V_43 -> V_46 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_100 * V_101 = V_39 ;
struct V_33 * V_34 ;
struct V_99 * V_102 ;
int V_15 ;
if ( ! V_101 ) {
F_30 ( L_42 ) ;
return - V_25 ;
}
if ( V_101 -> V_106 >= V_137 ) {
F_30 ( L_43 ) ;
return - V_25 ;
}
F_27 ( L_44 ,
V_101 -> V_32 , V_101 -> V_106 ? L_12 : L_13 ,
V_101 -> V_105 , V_101 -> V_138 ) ;
V_34 = F_17 ( & V_27 -> V_77 , & V_27 -> V_78 ,
V_101 -> V_32 ) ;
if ( ! V_34 ) {
F_30 ( L_45 ) ;
return - V_31 ;
}
switch ( V_101 -> V_138 ) {
case V_112 :
V_102 = F_49 ( V_38 , V_41 , V_34 , V_101 ) ;
if ( F_3 ( V_102 ) ) {
F_30 ( L_46 ) ;
return F_4 ( V_102 ) ;
}
if ( V_101 -> V_106 == V_95 ) {
V_15 = F_55 ( V_38 , V_41 , V_34 , V_101 ) ;
if ( V_15 ) {
F_30 ( L_47 ) ;
goto V_139;
}
V_15 = F_62 ( V_22 , V_34 , V_102 , V_101 ) ;
if ( V_15 ) {
F_30 ( L_48 ) ;
goto V_139;
}
}
break;
case V_140 :
F_8 ( & V_34 -> V_13 ) ;
if ( V_101 -> V_106 == V_95 )
F_58 ( V_34 , V_101 ) ;
F_63 ( V_38 , V_34 , V_101 ) ;
F_10 ( & V_34 -> V_13 ) ;
break;
default:
F_30 ( L_49 ) ;
return - V_25 ;
}
return 0 ;
V_139:
F_30 ( L_50 ) ;
F_63 ( V_38 , V_34 , V_101 ) ;
return V_15 ;
}
static bool F_65 ( struct V_45 * V_22 ,
enum V_141 V_134 , enum V_142 V_65 )
{
if ( V_134 != V_135 ) {
if ( F_21 ( V_22 ) ) {
F_30 ( L_51 ) ;
goto V_143;
}
}
switch ( V_134 ) {
case V_135 :
if ( V_65 != V_80 )
goto V_143;
break;
case V_144 :
if ( V_65 == V_66 )
goto V_143;
break;
case V_145 :
if ( V_65 != V_133 )
goto V_143;
break;
case V_146 :
if ( V_65 != V_66 )
goto V_143;
break;
default:
F_30 ( L_52 ) ;
goto V_143;
}
return true ;
V_143:
F_30 ( L_53 , V_134 , V_65 ) ;
return false ;
}
int F_66 ( struct V_37 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_5 * V_6 = NULL ;
struct V_45 * V_22 = V_43 -> V_46 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_147 * V_148 = V_39 ;
struct V_67 * V_68 ;
struct V_33 * V_34 ;
if ( ! V_27 ) {
F_30 ( L_7 ) ;
return - V_25 ;
}
if ( ! V_148 ) {
F_30 ( L_54 ) ;
return - V_25 ;
}
F_27 ( L_55 ,
V_148 -> V_134 , V_148 -> V_32 ) ;
V_6 = F_26 ( V_148 -> V_32 ) ;
if ( F_3 ( V_6 ) ) {
F_30 ( L_15 ) ;
return F_4 ( V_6 ) ;
}
V_34 = F_17 ( & V_27 -> V_77 , & V_27 -> V_78 ,
V_148 -> V_32 ) ;
if ( ! V_34 ) {
F_30 ( L_56 ) ;
return - V_31 ;
}
if ( ! F_65 ( V_6 -> V_22 , V_148 -> V_134 ,
V_34 -> V_65 ) ) {
F_30 ( L_52 ) ;
return - V_25 ;
}
switch ( V_148 -> V_134 ) {
case V_135 :
if ( F_21 ( V_6 -> V_22 ) )
F_67 ( V_6 -> V_22 ) ;
V_34 -> V_65 = V_133 ;
V_68 = V_34 -> V_81 ;
V_68 -> V_134 = V_148 -> V_134 ;
F_60 ( V_22 , V_6 , V_68 , V_34 ) ;
break;
case V_144 :
V_68 = V_34 -> V_83 ;
V_68 -> V_134 = V_148 -> V_134 ;
F_60 ( V_22 , V_6 , V_68 , V_34 ) ;
if ( ! F_68 ( & V_34 -> V_89 ,
F_69 ( 300 ) ) ) {
F_30 ( L_57 ,
V_34 -> V_19 . V_32 ) ;
}
V_34 -> V_65 = V_66 ;
V_6 -> V_20 = false ;
F_8 ( & V_6 -> V_36 ) ;
F_43 ( V_27 , V_34 ) ;
if ( F_46 ( & V_6 -> V_93 ) )
F_70 ( V_6 -> V_22 ) ;
F_10 ( & V_6 -> V_36 ) ;
break;
case V_145 :
V_68 = V_34 -> V_83 ;
V_68 -> V_134 = V_148 -> V_134 ;
F_60 ( V_22 , V_6 , V_68 , V_34 ) ;
if ( ! F_68 ( & V_34 -> V_89 ,
F_69 ( 200 ) ) ) {
F_30 ( L_57 ,
V_34 -> V_19 . V_32 ) ;
}
V_34 -> V_65 = V_66 ;
break;
case V_146 :
V_34 -> V_65 = V_133 ;
V_68 = V_34 -> V_81 ;
V_68 -> V_134 = V_148 -> V_134 ;
F_60 ( V_22 , V_6 , V_68 , V_34 ) ;
break;
default:
F_30 ( L_58 ) ;
return - V_25 ;
}
F_27 ( L_59 ,
V_148 -> V_134 , V_148 -> V_32 ) ;
return 0 ;
}
int F_71 ( struct V_149 * V_150 )
{
return F_72 (
& V_151 , V_150 ) ;
}
int F_73 ( struct V_149 * V_150 )
{
return F_74 (
& V_151 , V_150 ) ;
}
int F_75 ( unsigned long V_152 , void * V_153 )
{
return F_76 (
& V_151 , V_152 , V_153 ) ;
}
static int F_77 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
struct V_107 * V_108 = NULL ;
bool V_154 = false ;
int V_15 , V_76 ;
if ( ! V_19 ) {
F_30 ( L_8 ) ;
return - V_25 ;
}
F_27 ( L_5 , V_19 -> V_32 ) ;
if ( V_6 -> V_155 &&
V_6 -> V_155 ( V_6 -> V_22 ) ) {
return - V_25 ;
}
F_38 (i) {
struct V_50 * V_51 =
& V_19 -> V_51 [ V_76 ] ;
V_108 = V_6 -> V_108 [ V_76 ] ;
if ( ! V_108 || ! V_51 ) {
F_30 ( L_60 ) ;
return - V_25 ;
}
if ( V_108 -> V_156 ) {
V_15 = V_108 -> V_156 ( V_6 -> V_22 , V_51 -> V_56 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_108 -> V_157 ) {
V_15 = V_108 -> V_157 ( V_6 -> V_22 , V_51 -> V_64 ,
V_51 -> V_63 , & V_154 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_108 -> V_158 ) {
V_15 = V_108 -> V_158 ( V_6 -> V_22 , V_154 , & V_51 -> V_53 ,
& V_51 -> V_55 ) ;
if ( V_15 )
return V_15 ;
}
}
return 0 ;
}
static int F_78 ( struct V_5 * V_6 ,
struct V_33 * V_34 )
{
struct V_99 * V_102 ;
struct V_18 * V_19 = & V_34 -> V_19 ;
struct V_103 * V_104 ;
int V_15 , V_76 ;
F_27 ( L_5 , V_19 -> V_32 ) ;
V_6 -> V_34 = V_34 ;
F_8 ( & V_34 -> V_86 ) ;
if ( ! F_45 ( V_34 ) ) {
F_27 ( L_40 ) ;
V_15 = - V_69 ;
goto V_159;
}
V_15 = F_77 ( V_6 , V_19 ) ;
if ( V_15 ) {
F_30 ( L_61 ) ;
V_6 -> V_34 = NULL ;
goto V_159;
}
switch ( V_19 -> V_21 ) {
case V_98 :
F_38 (i) {
V_104 = & V_34 -> V_90 [ V_76 ] ;
V_102 = F_79 ( V_104 ,
struct V_99 , V_92 ) ;
F_27 ( L_62 , ( int ) V_102 ) ;
V_15 = F_48 ( V_6 , V_34 , V_102 ) ;
if ( V_15 ) {
F_30 ( L_41 ) ;
goto V_159;
}
}
break;
case V_94 :
V_104 = & V_34 -> V_90 [ V_95 ] ;
F_25 (m_node, head, list) {
V_15 = F_48 ( V_6 , V_34 , V_102 ) ;
if ( V_15 ) {
F_30 ( L_41 ) ;
goto V_159;
}
}
break;
case V_96 :
V_104 = & V_34 -> V_90 [ V_97 ] ;
F_25 (m_node, head, list) {
V_15 = F_48 ( V_6 , V_34 , V_102 ) ;
if ( V_15 ) {
F_30 ( L_41 ) ;
goto V_159;
}
}
break;
default:
F_30 ( L_63 ) ;
V_15 = - V_25 ;
goto V_159;
}
F_10 ( & V_34 -> V_86 ) ;
F_27 ( L_64 , V_19 -> V_21 ) ;
if ( V_6 -> V_160 ) {
V_15 = V_6 -> V_160 ( V_6 -> V_22 , V_19 -> V_21 ) ;
if ( V_15 ) {
F_30 ( L_65 ) ;
V_6 -> V_34 = NULL ;
return V_15 ;
}
}
return 0 ;
V_159:
F_10 ( & V_34 -> V_86 ) ;
V_6 -> V_34 = NULL ;
return V_15 ;
}
static int F_80 ( struct V_37 * V_38 ,
struct V_5 * V_6 ,
struct V_33 * V_34 )
{
struct V_99 * V_102 , * V_136 ;
struct V_18 * V_19 = & V_34 -> V_19 ;
struct V_103 * V_104 ;
int V_15 = 0 , V_76 ;
F_27 ( L_5 , V_19 -> V_32 ) ;
F_58 ( V_34 , NULL ) ;
F_8 ( & V_34 -> V_86 ) ;
switch ( V_19 -> V_21 ) {
case V_98 :
F_38 (i) {
V_104 = & V_34 -> V_90 [ V_76 ] ;
F_59 (m_node, tm_node,
head, list) {
V_15 = F_52 ( V_38 , V_34 ,
V_102 ) ;
if ( V_15 ) {
F_30 ( L_66 ) ;
goto V_79;
}
}
}
break;
case V_94 :
V_104 = & V_34 -> V_90 [ V_95 ] ;
F_59 (m_node, tm_node, head, list) {
V_15 = F_52 ( V_38 , V_34 , V_102 ) ;
if ( V_15 ) {
F_30 ( L_66 ) ;
goto V_79;
}
}
break;
case V_96 :
V_104 = & V_34 -> V_90 [ V_97 ] ;
F_59 (m_node, tm_node, head, list) {
V_15 = F_52 ( V_38 , V_34 , V_102 ) ;
if ( V_15 ) {
F_30 ( L_66 ) ;
goto V_79;
}
}
break;
default:
F_30 ( L_63 ) ;
V_15 = - V_25 ;
goto V_79;
}
V_79:
F_10 ( & V_34 -> V_86 ) ;
if ( V_6 -> V_161 )
V_6 -> V_161 ( V_6 -> V_22 , V_19 -> V_21 ) ;
return V_15 ;
}
void V_71 ( struct V_70 * V_74 )
{
struct V_67 * V_68 =
(struct V_67 * ) V_74 ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
struct V_18 * V_19 ;
int V_15 ;
V_6 = V_68 -> V_6 ;
if ( ! V_6 ) {
F_30 ( L_67 ) ;
return;
}
V_34 = V_68 -> V_34 ;
if ( ! V_34 ) {
F_30 ( L_56 ) ;
return;
}
F_8 ( & V_34 -> V_13 ) ;
V_19 = & V_34 -> V_19 ;
switch ( V_68 -> V_134 ) {
case V_135 :
case V_146 :
V_15 = F_78 ( V_6 , V_34 ) ;
if ( V_15 ) {
F_30 ( L_68 ,
V_34 -> V_19 . V_32 ) ;
goto V_159;
}
if ( F_20 ( V_19 -> V_21 ) ) {
if ( ! F_68
( & V_34 -> V_88 , F_69 ( 200 ) ) ) {
F_30 ( L_69 ,
V_34 -> V_19 . V_32 ) ;
goto V_159;
}
}
break;
case V_144 :
case V_145 :
V_15 = F_80 ( V_6 -> V_38 , V_6 ,
V_34 ) ;
if ( V_15 ) {
F_30 ( L_70 ) ;
goto V_159;
}
F_81 ( & V_34 -> V_89 ) ;
break;
default:
F_30 ( L_71 ) ;
break;
}
F_27 ( L_72 , V_68 -> V_134 ) ;
V_159:
F_10 ( & V_34 -> V_13 ) ;
}
static int F_82 ( struct V_5 * V_6 ,
struct V_33 * V_34 , int * V_105 )
{
struct V_37 * V_38 = V_6 -> V_38 ;
struct V_18 * V_19 = & V_34 -> V_19 ;
struct V_99 * V_102 ;
struct V_100 V_101 ;
struct V_121 * V_122 ;
struct V_103 * V_104 ;
struct V_162 V_163 ;
unsigned long V_123 ;
T_1 V_164 [ V_137 ] = { 0 , } ;
int V_15 , V_76 ;
F_38 (i)
F_27 ( L_73 , V_76 ? L_12 : L_13 , V_105 [ V_76 ] ) ;
if ( ! V_38 ) {
F_30 ( L_74 ) ;
return - V_25 ;
}
if ( ! V_19 ) {
F_30 ( L_75 ) ;
return - V_25 ;
}
F_8 ( & V_34 -> V_87 ) ;
if ( F_46 ( & V_34 -> V_91 ) ) {
F_27 ( L_76 ) ;
V_15 = 0 ;
goto V_165;
}
F_8 ( & V_34 -> V_86 ) ;
if ( ! F_45 ( V_34 ) ) {
F_27 ( L_40 ) ;
V_15 = 0 ;
goto V_166;
}
switch ( V_19 -> V_21 ) {
case V_98 :
F_38 (i) {
V_104 = & V_34 -> V_90 [ V_76 ] ;
V_102 = F_79 ( V_104 ,
struct V_99 , V_92 ) ;
V_164 [ V_76 ] = V_102 -> V_105 ;
F_27 ( L_73 ,
V_76 ? L_12 : L_13 , V_164 [ V_76 ] ) ;
V_15 = F_52 ( V_38 , V_34 , V_102 ) ;
if ( V_15 )
F_30 ( L_66 ) ;
}
break;
case V_94 :
memset ( & V_101 , 0x0 , sizeof( V_101 ) ) ;
V_101 . V_106 = V_95 ;
V_101 . V_105 = V_105 [ V_95 ] ;
V_102 = F_47 ( V_34 , & V_101 ) ;
if ( ! V_102 ) {
F_30 ( L_77 ) ;
V_15 = - V_69 ;
goto V_166;
}
V_164 [ V_95 ] = V_102 -> V_105 ;
V_15 = F_52 ( V_38 , V_34 , V_102 ) ;
if ( V_15 )
F_30 ( L_66 ) ;
break;
case V_96 :
V_104 = & V_34 -> V_90 [ V_97 ] ;
V_102 = F_79 ( V_104 ,
struct V_99 , V_92 ) ;
V_164 [ V_97 ] = V_102 -> V_105 ;
V_15 = F_52 ( V_38 , V_34 , V_102 ) ;
if ( V_15 )
F_30 ( L_66 ) ;
break;
default:
F_30 ( L_63 ) ;
V_15 = - V_25 ;
goto V_166;
}
F_10 ( & V_34 -> V_86 ) ;
if ( V_164 [ V_95 ] != V_105 [ V_95 ] )
F_30 ( L_78 ,
V_164 [ 1 ] , V_105 [ 1 ] , V_19 -> V_32 ) ;
V_122 = F_79 ( & V_34 -> V_91 ,
struct V_121 , V_117 . V_129 ) ;
F_83 ( & V_163 ) ;
F_27 ( L_79 , V_163 . V_167 , V_163 . V_168 ) ;
V_122 -> V_120 . V_167 = V_163 . V_167 ;
V_122 -> V_120 . V_168 = V_163 . V_168 ;
V_122 -> V_120 . V_32 = V_19 -> V_32 ;
F_38 (i)
V_122 -> V_120 . V_105 [ V_76 ] = V_164 [ V_76 ] ;
F_56 ( & V_38 -> V_87 , V_123 ) ;
F_84 ( & V_122 -> V_117 . V_129 , & V_122 -> V_117 . V_43 -> V_91 ) ;
F_85 ( & V_122 -> V_117 . V_43 -> V_169 ) ;
F_57 ( & V_38 -> V_87 , V_123 ) ;
F_10 ( & V_34 -> V_87 ) ;
F_27 ( L_80 ,
V_19 -> V_21 , V_19 -> V_32 , V_164 [ V_95 ] ) ;
return 0 ;
V_166:
F_10 ( & V_34 -> V_86 ) ;
V_165:
F_10 ( & V_34 -> V_87 ) ;
return V_15 ;
}
void V_75 ( struct V_70 * V_74 )
{
struct V_72 * V_73 =
(struct V_72 * ) V_74 ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
int V_15 ;
if ( ! V_73 ) {
F_30 ( L_81 ) ;
return;
}
F_27 ( L_23 , V_73 -> V_105 [ V_95 ] ) ;
V_6 = V_73 -> V_6 ;
if ( ! V_6 ) {
F_30 ( L_15 ) ;
return;
}
V_34 = V_6 -> V_34 ;
if ( ! V_34 ) {
F_30 ( L_45 ) ;
return;
}
if ( V_34 -> V_65 != V_133 ) {
F_27 ( L_82 ,
V_34 -> V_65 , V_34 -> V_19 . V_32 ) ;
goto V_170;
}
V_15 = F_82 ( V_6 , V_34 , V_73 -> V_105 ) ;
if ( V_15 ) {
F_30 ( L_83 ) ;
goto V_170;
}
V_170:
if ( F_20 ( V_34 -> V_19 . V_21 ) )
F_81 ( & V_34 -> V_88 ) ;
}
static int F_86 ( struct V_37 * V_38 , struct V_45 * V_22 )
{
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_5 * V_6 ;
int V_15 , V_35 = 0 ;
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
V_6 -> V_38 = V_38 ;
V_15 = F_13 ( & V_27 -> V_29 , & V_27 -> V_30 , V_6 ) ;
if ( V_15 < 0 ) {
F_30 ( L_18 ) ;
goto V_171;
}
V_6 -> V_48 . V_28 = V_15 ;
F_27 ( L_84 ,
V_35 ++ , ( int ) V_6 , V_15 ) ;
V_6 -> V_172 = V_22 ;
V_6 -> V_173 = V_27 -> V_173 ;
V_6 -> V_174 = V_75 ;
F_41 ( & V_6 -> V_93 ) ;
F_39 ( & V_6 -> V_36 ) ;
if ( F_87 ( V_38 ) ) {
V_15 = F_88 ( V_38 , V_6 -> V_22 ) ;
if ( V_15 ) {
F_30 ( L_85 ) ;
goto V_171;
}
}
}
return 0 ;
V_171:
F_89 (ippdrv, &exynos_drm_ippdrv_list,
drv_list) {
if ( F_87 ( V_38 ) )
F_90 ( V_38 , V_6 -> V_22 ) ;
F_15 ( & V_27 -> V_29 , & V_27 -> V_30 ,
V_6 -> V_48 . V_28 ) ;
}
return V_15 ;
}
static void F_91 ( struct V_37 * V_38 , struct V_45 * V_22 )
{
struct V_5 * V_6 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
if ( F_87 ( V_38 ) )
F_90 ( V_38 , V_6 -> V_22 ) ;
F_15 ( & V_27 -> V_29 , & V_27 -> V_30 ,
V_6 -> V_48 . V_28 ) ;
V_6 -> V_38 = NULL ;
F_11 ( V_6 ) ;
}
}
static int F_92 ( struct V_37 * V_38 , struct V_45 * V_22 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
V_43 -> V_46 = V_22 ;
F_27 ( L_86 , ( int ) V_22 ) ;
return 0 ;
}
static void F_93 ( struct V_37 * V_38 , struct V_45 * V_22 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_5 * V_6 = NULL ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_33 * V_34 , * V_175 ;
int V_35 = 0 ;
F_27 ( L_87 , ( int ) V_43 -> V_46 ) ;
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
F_8 ( & V_6 -> V_36 ) ;
F_59 (c_node, tc_node,
&ippdrv->cmd_list, list) {
F_27 ( L_6 ,
V_35 ++ , ( int ) V_6 ) ;
if ( V_34 -> V_22 == V_43 -> V_46 ) {
if ( V_34 -> V_65 == V_133 ) {
F_80 ( V_38 , V_6 ,
V_34 ) ;
V_34 -> V_65 = V_66 ;
}
V_6 -> V_20 = false ;
F_43 ( V_27 , V_34 ) ;
if ( F_46 ( & V_6 -> V_93 ) )
F_70 ( V_6 -> V_22 ) ;
}
}
F_10 ( & V_6 -> V_36 ) ;
}
return;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_45 * V_22 = & V_2 -> V_22 ;
struct V_26 * V_27 ;
struct V_176 * V_177 ;
int V_15 ;
V_27 = F_95 ( V_22 , sizeof( * V_27 ) , V_16 ) ;
if ( ! V_27 )
return - V_69 ;
F_39 ( & V_27 -> V_30 ) ;
F_39 ( & V_27 -> V_78 ) ;
F_96 ( & V_27 -> V_29 ) ;
F_96 ( & V_27 -> V_77 ) ;
V_27 -> V_173 = F_97 ( L_88 ) ;
if ( ! V_27 -> V_173 ) {
F_98 ( V_22 , L_89 ) ;
return - V_25 ;
}
V_27 -> V_132 = F_97 ( L_90 ) ;
if ( ! V_27 -> V_132 ) {
F_98 ( V_22 , L_91 ) ;
V_15 = - V_25 ;
goto V_178;
}
V_177 = & V_27 -> V_177 ;
V_177 -> V_22 = V_22 ;
V_177 -> V_179 = F_86 ;
V_177 -> remove = F_91 ;
V_177 -> V_180 = F_92 ;
V_177 -> V_181 = F_93 ;
F_99 ( V_2 , V_27 ) ;
V_15 = F_100 ( V_177 ) ;
if ( V_15 < 0 ) {
F_30 ( L_92 ) ;
goto V_182;
}
F_101 ( V_22 , L_93 ) ;
return 0 ;
V_182:
F_102 ( V_27 -> V_132 ) ;
V_178:
F_102 ( V_27 -> V_173 ) ;
return V_15 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_104 ( V_2 ) ;
F_105 ( & V_27 -> V_177 ) ;
F_106 ( & V_27 -> V_29 ) ;
F_106 ( & V_27 -> V_77 ) ;
F_44 ( & V_27 -> V_30 ) ;
F_44 ( & V_27 -> V_78 ) ;
F_102 ( V_27 -> V_132 ) ;
F_102 ( V_27 -> V_173 ) ;
return 0 ;
}
static int F_107 ( struct V_26 * V_27 , bool V_183 )
{
F_27 ( L_94 , V_183 ) ;
return 0 ;
}
static int F_108 ( struct V_45 * V_22 )
{
struct V_26 * V_27 = F_29 ( V_22 ) ;
if ( F_21 ( V_22 ) )
return 0 ;
return F_107 ( V_27 , false ) ;
}
static int F_109 ( struct V_45 * V_22 )
{
struct V_26 * V_27 = F_29 ( V_22 ) ;
if ( ! F_21 ( V_22 ) )
return F_107 ( V_27 , true ) ;
return 0 ;
}
static int F_110 ( struct V_45 * V_22 )
{
struct V_26 * V_27 = F_29 ( V_22 ) ;
return F_107 ( V_27 , false ) ;
}
static int F_111 ( struct V_45 * V_22 )
{
struct V_26 * V_27 = F_29 ( V_22 ) ;
return F_107 ( V_27 , true ) ;
}
