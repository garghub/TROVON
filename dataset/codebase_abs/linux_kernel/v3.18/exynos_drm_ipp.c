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
static struct V_65 * F_32 ( void )
{
struct V_65 * V_66 ;
V_66 = F_33 ( sizeof( * V_66 ) , V_16 ) ;
if ( ! V_66 )
return F_24 ( - V_67 ) ;
F_34 ( (struct V_68 * ) V_66 , V_69 ) ;
return V_66 ;
}
static struct V_70 * F_35 ( void )
{
struct V_70 * V_71 ;
V_71 = F_33 ( sizeof( * V_71 ) , V_16 ) ;
if ( ! V_71 )
return F_24 ( - V_67 ) ;
F_34 ( & V_71 -> V_72 , V_73 ) ;
return V_71 ;
}
int F_36 ( struct V_37 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_45 * V_22 = V_43 -> V_46 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_18 * V_19 = V_39 ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
T_1 V_32 ;
int V_15 , V_74 ;
if ( ! V_27 ) {
F_30 ( L_7 ) ;
return - V_25 ;
}
if ( ! V_19 ) {
F_30 ( L_8 ) ;
return - V_25 ;
}
V_32 = V_19 -> V_32 ;
F_37 (i)
F_31 ( V_19 , V_74 ) ;
if ( V_32 ) {
V_34 = F_17 ( & V_27 -> V_75 , & V_27 -> V_76 , V_32 ) ;
if ( ! V_34 || V_34 -> V_77 != V_41 ) {
F_27 ( L_15 , V_32 ) ;
return - V_25 ;
}
if ( V_34 -> V_78 != V_79 ) {
F_27 ( L_16 , V_32 ) ;
return - V_25 ;
}
V_34 -> V_19 = * V_19 ;
return 0 ;
}
V_6 = F_22 ( V_27 , V_19 ) ;
if ( F_3 ( V_6 ) ) {
F_30 ( L_17 ) ;
return - V_25 ;
}
V_34 = F_33 ( sizeof( * V_34 ) , V_16 ) ;
if ( ! V_34 )
return - V_67 ;
V_15 = F_13 ( & V_27 -> V_75 , & V_27 -> V_76 , V_34 ) ;
if ( V_15 < 0 ) {
F_30 ( L_18 ) ;
goto V_80;
}
V_19 -> V_32 = V_15 ;
F_27 ( L_19 ,
V_19 -> V_32 , V_19 -> V_21 , ( int ) V_6 ) ;
V_34 -> V_19 = * V_19 ;
V_34 -> V_78 = V_81 ;
V_34 -> V_77 = V_41 ;
V_34 -> V_82 = F_32 () ;
if ( F_3 ( V_34 -> V_82 ) ) {
F_30 ( L_20 ) ;
goto V_83;
}
V_34 -> V_84 = F_32 () ;
if ( F_3 ( V_34 -> V_84 ) ) {
F_30 ( L_21 ) ;
goto V_85;
}
V_34 -> V_71 = F_35 () ;
if ( F_3 ( V_34 -> V_71 ) ) {
F_30 ( L_22 ) ;
goto V_86;
}
F_38 ( & V_34 -> V_13 ) ;
F_38 ( & V_34 -> V_87 ) ;
F_38 ( & V_34 -> V_88 ) ;
F_39 ( & V_34 -> V_89 ) ;
F_39 ( & V_34 -> V_90 ) ;
F_37 (i)
F_40 ( & V_34 -> V_91 [ V_74 ] ) ;
F_40 ( & V_34 -> V_92 ) ;
F_8 ( & V_6 -> V_36 ) ;
F_9 ( & V_34 -> V_93 , & V_6 -> V_94 ) ;
F_10 ( & V_6 -> V_36 ) ;
if ( ! F_20 ( V_19 -> V_21 ) )
V_6 -> V_20 = true ;
return 0 ;
V_86:
F_41 ( V_34 -> V_84 ) ;
V_85:
F_41 ( V_34 -> V_82 ) ;
V_83:
F_15 ( & V_27 -> V_75 , & V_27 -> V_76 , V_19 -> V_32 ) ;
V_80:
F_41 ( V_34 ) ;
return V_15 ;
}
static int F_42 ( struct V_37 * V_38 ,
struct V_33 * V_34 ,
struct V_95 * V_96 )
{
int V_74 ;
F_27 ( L_23 , ( int ) V_96 ) ;
if ( ! V_96 ) {
F_30 ( L_24 ) ;
return - V_97 ;
}
F_27 ( L_25 , V_96 -> V_98 ) ;
F_43 (i) {
unsigned long V_99 = V_96 -> V_100 . V_101 [ V_74 ] ;
if ( V_99 )
F_44 ( V_38 , V_99 ,
V_34 -> V_77 ) ;
}
F_12 ( & V_96 -> V_93 ) ;
F_41 ( V_96 ) ;
return 0 ;
}
static struct V_95
* F_45 ( struct V_37 * V_38 ,
struct V_33 * V_34 ,
struct V_102 * V_103 )
{
struct V_95 * V_96 ;
struct V_104 * V_100 ;
int V_74 ;
V_96 = F_33 ( sizeof( * V_96 ) , V_16 ) ;
if ( ! V_96 )
return F_24 ( - V_67 ) ;
V_100 = & V_96 -> V_100 ;
V_96 -> V_98 = V_103 -> V_98 ;
V_96 -> V_32 = V_103 -> V_32 ;
V_96 -> V_105 = V_103 -> V_105 ;
F_40 ( & V_96 -> V_93 ) ;
F_27 ( L_26 , ( int ) V_96 , V_103 -> V_98 ) ;
F_27 ( L_27 , V_103 -> V_32 , V_96 -> V_105 ) ;
F_43 (i) {
F_27 ( L_28 , V_74 , V_103 -> V_99 [ V_74 ] ) ;
if ( V_103 -> V_99 [ V_74 ] ) {
T_2 * V_106 ;
V_106 = F_46 ( V_38 ,
V_103 -> V_99 [ V_74 ] , V_34 -> V_77 ) ;
if ( F_3 ( V_106 ) ) {
F_30 ( L_29 ) ;
F_42 ( V_38 , V_34 , V_96 ) ;
return F_24 ( - V_97 ) ;
}
V_100 -> V_101 [ V_74 ] = V_103 -> V_99 [ V_74 ] ;
V_100 -> V_107 [ V_74 ] = * V_106 ;
F_27 ( L_30 , V_74 ,
V_100 -> V_107 [ V_74 ] , V_100 -> V_101 [ V_74 ] ) ;
}
}
F_8 ( & V_34 -> V_87 ) ;
F_9 ( & V_96 -> V_93 , & V_34 -> V_91 [ V_103 -> V_98 ] ) ;
F_10 ( & V_34 -> V_87 ) ;
return V_96 ;
}
static void F_47 ( struct V_37 * V_38 ,
struct V_33 * V_34 , int V_108 )
{
struct V_95 * V_96 , * V_109 ;
struct V_110 * V_111 = & V_34 -> V_91 [ V_108 ] ;
F_8 ( & V_34 -> V_87 ) ;
F_48 (m_node, tm_node, head, list) {
int V_15 ;
V_15 = F_42 ( V_38 , V_34 , V_96 ) ;
if ( V_15 )
F_30 ( L_31 ) ;
}
F_10 ( & V_34 -> V_87 ) ;
}
static void F_49 ( struct V_112 * V_113 )
{
F_41 ( V_113 ) ;
}
static int F_50 ( struct V_37 * V_38 ,
struct V_33 * V_34 ,
struct V_102 * V_103 )
{
struct V_114 * V_115 ;
unsigned long V_116 ;
F_27 ( L_32 , V_103 -> V_98 , V_103 -> V_105 ) ;
V_115 = F_33 ( sizeof( * V_115 ) , V_16 ) ;
if ( ! V_115 ) {
F_51 ( & V_38 -> V_88 , V_116 ) ;
V_34 -> V_77 -> V_117 += sizeof( V_115 -> V_113 ) ;
F_52 ( & V_38 -> V_88 , V_116 ) ;
return - V_67 ;
}
V_115 -> V_113 . V_107 . type = V_118 ;
V_115 -> V_113 . V_107 . V_119 = sizeof( V_115 -> V_113 ) ;
V_115 -> V_113 . V_120 = V_103 -> V_120 ;
V_115 -> V_113 . V_32 = V_103 -> V_32 ;
V_115 -> V_113 . V_105 [ V_121 ] = V_103 -> V_105 ;
V_115 -> V_107 . V_113 = & V_115 -> V_113 . V_107 ;
V_115 -> V_107 . V_43 = V_34 -> V_77 ;
V_115 -> V_107 . V_122 = F_49 ;
F_8 ( & V_34 -> V_88 ) ;
F_9 ( & V_115 -> V_107 . V_123 , & V_34 -> V_92 ) ;
F_10 ( & V_34 -> V_88 ) ;
return 0 ;
}
static void F_53 ( struct V_33 * V_34 ,
struct V_102 * V_103 )
{
struct V_114 * V_115 , * V_124 ;
int V_35 = 0 ;
F_8 ( & V_34 -> V_88 ) ;
F_48 (e, te, &c_node->event_list, base.link) {
F_27 ( L_33 , V_35 ++ , ( int ) V_115 ) ;
if ( ! V_103 ) {
F_12 ( & V_115 -> V_107 . V_123 ) ;
F_41 ( V_115 ) ;
}
if ( V_103 && ( V_103 -> V_105 ==
V_115 -> V_113 . V_105 [ V_121 ] ) ) {
F_12 ( & V_115 -> V_107 . V_123 ) ;
F_41 ( V_115 ) ;
goto V_125;
}
}
V_125:
F_10 ( & V_34 -> V_88 ) ;
return;
}
static void F_54 ( struct V_26 * V_27 ,
struct V_33 * V_34 )
{
int V_74 ;
F_55 ( & V_34 -> V_82 -> V_72 ) ;
F_55 ( & V_34 -> V_84 -> V_72 ) ;
F_55 ( & V_34 -> V_71 -> V_72 ) ;
F_53 ( V_34 , NULL ) ;
F_37 (i)
F_47 ( V_27 -> V_126 . V_38 , V_34 , V_74 ) ;
F_12 ( & V_34 -> V_93 ) ;
F_15 ( & V_27 -> V_75 , & V_27 -> V_76 ,
V_34 -> V_19 . V_32 ) ;
F_56 ( & V_34 -> V_13 ) ;
F_56 ( & V_34 -> V_87 ) ;
F_56 ( & V_34 -> V_88 ) ;
F_41 ( V_34 -> V_82 ) ;
F_41 ( V_34 -> V_84 ) ;
F_41 ( V_34 -> V_71 ) ;
F_41 ( V_34 ) ;
}
static bool F_57 ( struct V_33 * V_34 )
{
switch ( V_34 -> V_19 . V_21 ) {
case V_127 :
return ! F_58 ( & V_34 -> V_91 [ V_121 ] ) ;
case V_128 :
return ! F_58 ( & V_34 -> V_91 [ V_129 ] ) ;
case V_130 :
default:
return ! F_58 ( & V_34 -> V_91 [ V_129 ] ) &&
! F_58 ( & V_34 -> V_91 [ V_121 ] ) ;
}
}
static struct V_95
* F_59 ( struct V_33 * V_34 ,
struct V_102 * V_103 )
{
struct V_95 * V_96 ;
struct V_110 * V_111 ;
int V_35 = 0 ;
F_27 ( L_34 , V_103 -> V_105 ) ;
V_111 = & V_34 -> V_91 [ V_103 -> V_98 ] ;
F_25 (m_node, head, list) {
F_27 ( L_35 , V_35 ++ , ( int ) V_96 ) ;
if ( V_96 -> V_105 == V_103 -> V_105 )
return V_96 ;
}
return NULL ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_33 * V_34 ,
struct V_95 * V_96 )
{
struct V_131 * V_108 = NULL ;
int V_15 = 0 ;
F_27 ( L_23 , ( int ) V_96 ) ;
if ( ! V_96 ) {
F_30 ( L_36 ) ;
return - V_97 ;
}
F_27 ( L_25 , V_96 -> V_98 ) ;
V_108 = V_6 -> V_108 [ V_96 -> V_98 ] ;
if ( ! V_108 ) {
F_30 ( L_37 ) ;
return - V_97 ;
}
if ( V_108 -> V_132 ) {
V_15 = V_108 -> V_132 ( V_6 -> V_22 , & V_96 -> V_100 ,
V_96 -> V_105 , V_133 ) ;
if ( V_15 ) {
F_30 ( L_38 ) ;
return V_15 ;
}
}
return V_15 ;
}
static void F_61 ( struct V_45 * V_22 ,
struct V_5 * V_6 ,
struct V_65 * V_66 ,
struct V_33 * V_34 )
{
struct V_26 * V_27 = F_29 ( V_22 ) ;
V_66 -> V_6 = V_6 ;
V_66 -> V_34 = V_34 ;
F_62 ( V_27 -> V_134 , & V_66 -> V_72 ) ;
}
static int F_63 ( struct V_45 * V_22 ,
struct V_33 * V_34 ,
struct V_95 * V_96 ,
struct V_102 * V_103 )
{
struct V_5 * V_6 ;
struct V_18 * V_19 ;
struct V_131 * V_108 ;
int V_15 ;
V_6 = F_26 ( V_103 -> V_32 ) ;
if ( F_3 ( V_6 ) ) {
F_30 ( L_17 ) ;
return - V_97 ;
}
V_108 = V_6 -> V_108 [ V_103 -> V_98 ] ;
if ( ! V_108 ) {
F_30 ( L_39 ) ;
return - V_97 ;
}
V_19 = & V_34 -> V_19 ;
if ( V_34 -> V_78 != V_135 ) {
F_27 ( L_40 ) ;
return 0 ;
}
F_8 ( & V_34 -> V_87 ) ;
if ( ! F_57 ( V_34 ) ) {
F_10 ( & V_34 -> V_87 ) ;
F_27 ( L_41 ) ;
return 0 ;
}
if ( F_20 ( V_19 -> V_21 ) ) {
struct V_65 * V_66 = V_34 -> V_82 ;
V_66 -> V_136 = V_137 ;
F_61 ( V_22 , V_6 , V_66 , V_34 ) ;
} else {
V_15 = F_60 ( V_6 , V_34 , V_96 ) ;
if ( V_15 ) {
F_10 ( & V_34 -> V_87 ) ;
F_30 ( L_42 ) ;
return V_15 ;
}
}
F_10 ( & V_34 -> V_87 ) ;
return 0 ;
}
static void F_64 ( struct V_37 * V_38 ,
struct V_33 * V_34 ,
struct V_102 * V_103 )
{
struct V_95 * V_96 , * V_109 ;
F_8 ( & V_34 -> V_87 ) ;
F_48 (m_node, tm_node,
&c_node->mem_list[qbuf->ops_id], list) {
if ( V_96 -> V_105 == V_103 -> V_105 &&
V_96 -> V_98 == V_103 -> V_98 )
F_42 ( V_38 , V_34 , V_96 ) ;
}
F_10 ( & V_34 -> V_87 ) ;
}
int F_65 ( struct V_37 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_45 * V_22 = V_43 -> V_46 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_102 * V_103 = V_39 ;
struct V_33 * V_34 ;
struct V_95 * V_96 ;
int V_15 ;
if ( ! V_103 ) {
F_30 ( L_43 ) ;
return - V_25 ;
}
if ( V_103 -> V_98 >= V_138 ) {
F_30 ( L_44 ) ;
return - V_25 ;
}
F_27 ( L_45 ,
V_103 -> V_32 , V_103 -> V_98 ? L_12 : L_13 ,
V_103 -> V_105 , V_103 -> V_139 ) ;
V_34 = F_17 ( & V_27 -> V_75 , & V_27 -> V_76 ,
V_103 -> V_32 ) ;
if ( ! V_34 || V_34 -> V_77 != V_41 ) {
F_30 ( L_46 ) ;
return - V_31 ;
}
switch ( V_103 -> V_139 ) {
case V_133 :
V_96 = F_45 ( V_38 , V_34 , V_103 ) ;
if ( F_3 ( V_96 ) ) {
F_30 ( L_47 ) ;
return F_4 ( V_96 ) ;
}
if ( V_103 -> V_98 == V_121 ) {
V_15 = F_50 ( V_38 , V_34 , V_103 ) ;
if ( V_15 ) {
F_30 ( L_48 ) ;
goto V_140;
}
V_15 = F_63 ( V_22 , V_34 , V_96 , V_103 ) ;
if ( V_15 ) {
F_30 ( L_49 ) ;
goto V_140;
}
}
break;
case V_141 :
F_8 ( & V_34 -> V_13 ) ;
if ( V_103 -> V_98 == V_121 )
F_53 ( V_34 , V_103 ) ;
F_64 ( V_38 , V_34 , V_103 ) ;
F_10 ( & V_34 -> V_13 ) ;
break;
default:
F_30 ( L_50 ) ;
return - V_25 ;
}
return 0 ;
V_140:
F_30 ( L_51 ) ;
F_64 ( V_38 , V_34 , V_103 ) ;
return V_15 ;
}
static bool F_66 ( struct V_45 * V_22 ,
enum V_142 V_136 , enum V_143 V_78 )
{
if ( V_136 != V_137 ) {
if ( F_21 ( V_22 ) ) {
F_30 ( L_52 ) ;
goto V_144;
}
}
switch ( V_136 ) {
case V_137 :
if ( V_78 != V_81 )
goto V_144;
break;
case V_145 :
if ( V_78 == V_79 )
goto V_144;
break;
case V_146 :
if ( V_78 != V_135 )
goto V_144;
break;
case V_147 :
if ( V_78 != V_79 )
goto V_144;
break;
default:
F_30 ( L_53 ) ;
goto V_144;
}
return true ;
V_144:
F_30 ( L_54 , V_136 , V_78 ) ;
return false ;
}
int F_67 ( struct V_37 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_5 * V_6 = NULL ;
struct V_45 * V_22 = V_43 -> V_46 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_148 * V_149 = V_39 ;
struct V_65 * V_66 ;
struct V_33 * V_34 ;
if ( ! V_27 ) {
F_30 ( L_7 ) ;
return - V_25 ;
}
if ( ! V_149 ) {
F_30 ( L_55 ) ;
return - V_25 ;
}
F_27 ( L_56 ,
V_149 -> V_136 , V_149 -> V_32 ) ;
V_6 = F_26 ( V_149 -> V_32 ) ;
if ( F_3 ( V_6 ) ) {
F_30 ( L_17 ) ;
return F_4 ( V_6 ) ;
}
V_34 = F_17 ( & V_27 -> V_75 , & V_27 -> V_76 ,
V_149 -> V_32 ) ;
if ( ! V_34 || V_34 -> V_77 != V_41 ) {
F_30 ( L_57 ) ;
return - V_31 ;
}
if ( ! F_66 ( V_6 -> V_22 , V_149 -> V_136 ,
V_34 -> V_78 ) ) {
F_30 ( L_53 ) ;
return - V_25 ;
}
switch ( V_149 -> V_136 ) {
case V_137 :
if ( F_21 ( V_6 -> V_22 ) )
F_68 ( V_6 -> V_22 ) ;
V_34 -> V_78 = V_135 ;
V_66 = V_34 -> V_82 ;
V_66 -> V_136 = V_149 -> V_136 ;
F_61 ( V_22 , V_6 , V_66 , V_34 ) ;
break;
case V_145 :
V_66 = V_34 -> V_84 ;
V_66 -> V_136 = V_149 -> V_136 ;
F_61 ( V_22 , V_6 , V_66 , V_34 ) ;
if ( ! F_69 ( & V_34 -> V_90 ,
F_70 ( 300 ) ) ) {
F_30 ( L_58 ,
V_34 -> V_19 . V_32 ) ;
}
V_34 -> V_78 = V_79 ;
V_6 -> V_20 = false ;
F_8 ( & V_6 -> V_36 ) ;
F_54 ( V_27 , V_34 ) ;
if ( F_58 ( & V_6 -> V_94 ) )
F_71 ( V_6 -> V_22 ) ;
F_10 ( & V_6 -> V_36 ) ;
break;
case V_146 :
V_66 = V_34 -> V_84 ;
V_66 -> V_136 = V_149 -> V_136 ;
F_61 ( V_22 , V_6 , V_66 , V_34 ) ;
if ( ! F_69 ( & V_34 -> V_90 ,
F_70 ( 200 ) ) ) {
F_30 ( L_58 ,
V_34 -> V_19 . V_32 ) ;
}
V_34 -> V_78 = V_79 ;
break;
case V_147 :
V_34 -> V_78 = V_135 ;
V_66 = V_34 -> V_82 ;
V_66 -> V_136 = V_149 -> V_136 ;
F_61 ( V_22 , V_6 , V_66 , V_34 ) ;
break;
default:
F_30 ( L_59 ) ;
return - V_25 ;
}
F_27 ( L_60 ,
V_149 -> V_136 , V_149 -> V_32 ) ;
return 0 ;
}
int F_72 ( struct V_150 * V_151 )
{
return F_73 (
& V_152 , V_151 ) ;
}
int F_74 ( struct V_150 * V_151 )
{
return F_75 (
& V_152 , V_151 ) ;
}
int F_76 ( unsigned long V_153 , void * V_154 )
{
return F_77 (
& V_152 , V_153 , V_154 ) ;
}
static int F_78 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
struct V_131 * V_108 = NULL ;
bool V_155 = false ;
int V_15 , V_74 ;
if ( ! V_19 ) {
F_30 ( L_8 ) ;
return - V_25 ;
}
F_27 ( L_5 , V_19 -> V_32 ) ;
if ( V_6 -> V_156 &&
V_6 -> V_156 ( V_6 -> V_22 ) ) {
return - V_25 ;
}
F_37 (i) {
struct V_50 * V_51 =
& V_19 -> V_51 [ V_74 ] ;
V_108 = V_6 -> V_108 [ V_74 ] ;
if ( ! V_108 || ! V_51 ) {
F_30 ( L_61 ) ;
return - V_25 ;
}
if ( V_108 -> V_157 ) {
V_15 = V_108 -> V_157 ( V_6 -> V_22 , V_51 -> V_56 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_108 -> V_158 ) {
V_15 = V_108 -> V_158 ( V_6 -> V_22 , V_51 -> V_64 ,
V_51 -> V_63 , & V_155 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_108 -> V_159 ) {
V_15 = V_108 -> V_159 ( V_6 -> V_22 , V_155 , & V_51 -> V_53 ,
& V_51 -> V_55 ) ;
if ( V_15 )
return V_15 ;
}
}
return 0 ;
}
static int F_79 ( struct V_5 * V_6 ,
struct V_33 * V_34 )
{
struct V_95 * V_96 ;
struct V_18 * V_19 = & V_34 -> V_19 ;
struct V_110 * V_111 ;
int V_15 , V_74 ;
F_27 ( L_5 , V_19 -> V_32 ) ;
V_6 -> V_34 = V_34 ;
F_8 ( & V_34 -> V_87 ) ;
if ( ! F_57 ( V_34 ) ) {
F_27 ( L_41 ) ;
V_15 = - V_67 ;
goto V_160;
}
V_15 = F_78 ( V_6 , V_19 ) ;
if ( V_15 ) {
F_30 ( L_62 ) ;
V_6 -> V_34 = NULL ;
goto V_160;
}
switch ( V_19 -> V_21 ) {
case V_130 :
F_37 (i) {
V_111 = & V_34 -> V_91 [ V_74 ] ;
V_96 = F_80 ( V_111 ,
struct V_95 , V_93 ) ;
F_27 ( L_63 , ( int ) V_96 ) ;
V_15 = F_60 ( V_6 , V_34 , V_96 ) ;
if ( V_15 ) {
F_30 ( L_42 ) ;
goto V_160;
}
}
break;
case V_127 :
V_111 = & V_34 -> V_91 [ V_121 ] ;
F_25 (m_node, head, list) {
V_15 = F_60 ( V_6 , V_34 , V_96 ) ;
if ( V_15 ) {
F_30 ( L_42 ) ;
goto V_160;
}
}
break;
case V_128 :
V_111 = & V_34 -> V_91 [ V_129 ] ;
F_25 (m_node, head, list) {
V_15 = F_60 ( V_6 , V_34 , V_96 ) ;
if ( V_15 ) {
F_30 ( L_42 ) ;
goto V_160;
}
}
break;
default:
F_30 ( L_64 ) ;
V_15 = - V_25 ;
goto V_160;
}
F_10 ( & V_34 -> V_87 ) ;
F_27 ( L_65 , V_19 -> V_21 ) ;
if ( V_6 -> V_161 ) {
V_15 = V_6 -> V_161 ( V_6 -> V_22 , V_19 -> V_21 ) ;
if ( V_15 ) {
F_30 ( L_66 ) ;
V_6 -> V_34 = NULL ;
return V_15 ;
}
}
return 0 ;
V_160:
F_10 ( & V_34 -> V_87 ) ;
V_6 -> V_34 = NULL ;
return V_15 ;
}
static int F_81 ( struct V_37 * V_38 ,
struct V_5 * V_6 ,
struct V_33 * V_34 )
{
struct V_18 * V_19 = & V_34 -> V_19 ;
int V_74 ;
F_27 ( L_5 , V_19 -> V_32 ) ;
if ( V_6 -> V_162 )
V_6 -> V_162 ( V_6 -> V_22 , V_19 -> V_21 ) ;
switch ( V_19 -> V_21 ) {
case V_130 :
F_37 (i)
F_47 ( V_38 , V_34 , V_74 ) ;
break;
case V_127 :
F_47 ( V_38 , V_34 , V_121 ) ;
break;
case V_128 :
F_47 ( V_38 , V_34 , V_129 ) ;
break;
default:
F_30 ( L_64 ) ;
return - V_25 ;
}
return 0 ;
}
void V_69 ( struct V_68 * V_72 )
{
struct V_65 * V_66 =
F_82 ( V_72 , struct V_65 , V_72 ) ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
struct V_18 * V_19 ;
int V_15 ;
V_6 = V_66 -> V_6 ;
if ( ! V_6 ) {
F_30 ( L_67 ) ;
return;
}
V_34 = V_66 -> V_34 ;
if ( ! V_34 ) {
F_30 ( L_57 ) ;
return;
}
F_8 ( & V_34 -> V_13 ) ;
V_19 = & V_34 -> V_19 ;
switch ( V_66 -> V_136 ) {
case V_137 :
case V_147 :
V_15 = F_79 ( V_6 , V_34 ) ;
if ( V_15 ) {
F_30 ( L_68 ,
V_34 -> V_19 . V_32 ) ;
goto V_160;
}
if ( F_20 ( V_19 -> V_21 ) ) {
if ( ! F_69
( & V_34 -> V_89 , F_70 ( 200 ) ) ) {
F_30 ( L_69 ,
V_34 -> V_19 . V_32 ) ;
goto V_160;
}
}
break;
case V_145 :
case V_146 :
V_15 = F_81 ( V_6 -> V_38 , V_6 ,
V_34 ) ;
if ( V_15 ) {
F_30 ( L_70 ) ;
goto V_160;
}
F_83 ( & V_34 -> V_90 ) ;
break;
default:
F_30 ( L_71 ) ;
break;
}
F_27 ( L_72 , V_66 -> V_136 ) ;
V_160:
F_10 ( & V_34 -> V_13 ) ;
}
static int F_84 ( struct V_5 * V_6 ,
struct V_33 * V_34 , int * V_105 )
{
struct V_37 * V_38 = V_6 -> V_38 ;
struct V_18 * V_19 = & V_34 -> V_19 ;
struct V_95 * V_96 ;
struct V_102 V_103 ;
struct V_114 * V_115 ;
struct V_110 * V_111 ;
struct V_163 V_164 ;
unsigned long V_116 ;
T_1 V_165 [ V_138 ] = { 0 , } ;
int V_15 , V_74 ;
F_37 (i)
F_27 ( L_73 , V_74 ? L_12 : L_13 , V_105 [ V_74 ] ) ;
if ( ! V_38 ) {
F_30 ( L_74 ) ;
return - V_25 ;
}
if ( ! V_19 ) {
F_30 ( L_75 ) ;
return - V_25 ;
}
F_8 ( & V_34 -> V_88 ) ;
if ( F_58 ( & V_34 -> V_92 ) ) {
F_27 ( L_76 ) ;
V_15 = 0 ;
goto V_166;
}
F_8 ( & V_34 -> V_87 ) ;
if ( ! F_57 ( V_34 ) ) {
F_27 ( L_41 ) ;
V_15 = 0 ;
goto V_167;
}
switch ( V_19 -> V_21 ) {
case V_130 :
F_37 (i) {
V_111 = & V_34 -> V_91 [ V_74 ] ;
V_96 = F_80 ( V_111 ,
struct V_95 , V_93 ) ;
V_165 [ V_74 ] = V_96 -> V_105 ;
F_27 ( L_73 ,
V_74 ? L_12 : L_13 , V_165 [ V_74 ] ) ;
V_15 = F_42 ( V_38 , V_34 , V_96 ) ;
if ( V_15 )
F_30 ( L_31 ) ;
}
break;
case V_127 :
memset ( & V_103 , 0x0 , sizeof( V_103 ) ) ;
V_103 . V_98 = V_121 ;
V_103 . V_105 = V_105 [ V_121 ] ;
V_96 = F_59 ( V_34 , & V_103 ) ;
if ( ! V_96 ) {
F_30 ( L_77 ) ;
V_15 = - V_67 ;
goto V_167;
}
V_165 [ V_121 ] = V_96 -> V_105 ;
V_15 = F_42 ( V_38 , V_34 , V_96 ) ;
if ( V_15 )
F_30 ( L_31 ) ;
break;
case V_128 :
V_111 = & V_34 -> V_91 [ V_129 ] ;
V_96 = F_80 ( V_111 ,
struct V_95 , V_93 ) ;
V_165 [ V_129 ] = V_96 -> V_105 ;
V_15 = F_42 ( V_38 , V_34 , V_96 ) ;
if ( V_15 )
F_30 ( L_31 ) ;
break;
default:
F_30 ( L_64 ) ;
V_15 = - V_25 ;
goto V_167;
}
F_10 ( & V_34 -> V_87 ) ;
if ( V_165 [ V_121 ] != V_105 [ V_121 ] )
F_30 ( L_78 ,
V_165 [ 1 ] , V_105 [ 1 ] , V_19 -> V_32 ) ;
V_115 = F_80 ( & V_34 -> V_92 ,
struct V_114 , V_107 . V_123 ) ;
F_85 ( & V_164 ) ;
F_27 ( L_79 , V_164 . V_168 , V_164 . V_169 ) ;
V_115 -> V_113 . V_168 = V_164 . V_168 ;
V_115 -> V_113 . V_169 = V_164 . V_169 ;
V_115 -> V_113 . V_32 = V_19 -> V_32 ;
F_37 (i)
V_115 -> V_113 . V_105 [ V_74 ] = V_165 [ V_74 ] ;
F_51 ( & V_38 -> V_88 , V_116 ) ;
F_86 ( & V_115 -> V_107 . V_123 , & V_115 -> V_107 . V_43 -> V_92 ) ;
F_87 ( & V_115 -> V_107 . V_43 -> V_170 ) ;
F_52 ( & V_38 -> V_88 , V_116 ) ;
F_10 ( & V_34 -> V_88 ) ;
F_27 ( L_80 ,
V_19 -> V_21 , V_19 -> V_32 , V_165 [ V_121 ] ) ;
return 0 ;
V_167:
F_10 ( & V_34 -> V_87 ) ;
V_166:
F_10 ( & V_34 -> V_88 ) ;
return V_15 ;
}
void V_73 ( struct V_68 * V_72 )
{
struct V_70 * V_71 =
F_82 ( V_72 , struct V_70 , V_72 ) ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
int V_15 ;
if ( ! V_71 ) {
F_30 ( L_81 ) ;
return;
}
F_27 ( L_34 , V_71 -> V_105 [ V_121 ] ) ;
V_6 = V_71 -> V_6 ;
if ( ! V_6 ) {
F_30 ( L_17 ) ;
return;
}
V_34 = V_6 -> V_34 ;
if ( ! V_34 ) {
F_30 ( L_46 ) ;
return;
}
if ( V_34 -> V_78 != V_135 ) {
F_27 ( L_82 ,
V_34 -> V_78 , V_34 -> V_19 . V_32 ) ;
goto V_171;
}
V_15 = F_84 ( V_6 , V_34 , V_71 -> V_105 ) ;
if ( V_15 ) {
F_30 ( L_83 ) ;
goto V_171;
}
V_171:
if ( F_20 ( V_34 -> V_19 . V_21 ) )
F_83 ( & V_34 -> V_89 ) ;
}
static int F_88 ( struct V_37 * V_38 , struct V_45 * V_22 )
{
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_5 * V_6 ;
int V_15 , V_35 = 0 ;
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
V_6 -> V_38 = V_38 ;
V_15 = F_13 ( & V_27 -> V_29 , & V_27 -> V_30 , V_6 ) ;
if ( V_15 < 0 ) {
F_30 ( L_18 ) ;
goto V_172;
}
V_6 -> V_48 . V_28 = V_15 ;
F_27 ( L_84 ,
V_35 ++ , ( int ) V_6 , V_15 ) ;
V_6 -> V_173 = V_22 ;
V_6 -> V_174 = V_27 -> V_174 ;
V_6 -> V_175 = V_73 ;
F_40 ( & V_6 -> V_94 ) ;
F_38 ( & V_6 -> V_36 ) ;
if ( F_89 ( V_38 ) ) {
V_15 = F_90 ( V_38 , V_6 -> V_22 ) ;
if ( V_15 ) {
F_30 ( L_85 ) ;
goto V_172;
}
}
}
return 0 ;
V_172:
F_91 (ippdrv, &exynos_drm_ippdrv_list,
drv_list) {
if ( F_89 ( V_38 ) )
F_92 ( V_38 , V_6 -> V_22 ) ;
F_15 ( & V_27 -> V_29 , & V_27 -> V_30 ,
V_6 -> V_48 . V_28 ) ;
}
return V_15 ;
}
static void F_93 ( struct V_37 * V_38 , struct V_45 * V_22 )
{
struct V_5 * V_6 , * V_176 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
F_48 (ippdrv, t, &exynos_drm_ippdrv_list, drv_list) {
if ( F_89 ( V_38 ) )
F_92 ( V_38 , V_6 -> V_22 ) ;
F_15 ( & V_27 -> V_29 , & V_27 -> V_30 ,
V_6 -> V_48 . V_28 ) ;
V_6 -> V_38 = NULL ;
F_11 ( V_6 ) ;
}
}
static int F_94 ( struct V_37 * V_38 , struct V_45 * V_22 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
V_43 -> V_46 = V_22 ;
F_27 ( L_86 , ( int ) V_22 ) ;
return 0 ;
}
static void F_95 ( struct V_37 * V_38 , struct V_45 * V_22 ,
struct V_40 * V_41 )
{
struct V_5 * V_6 = NULL ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_33 * V_34 , * V_177 ;
int V_35 = 0 ;
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
F_8 ( & V_6 -> V_36 ) ;
F_48 (c_node, tc_node,
&ippdrv->cmd_list, list) {
F_27 ( L_6 ,
V_35 ++ , ( int ) V_6 ) ;
if ( V_34 -> V_77 == V_41 ) {
if ( V_34 -> V_78 == V_135 ) {
F_81 ( V_38 , V_6 ,
V_34 ) ;
V_34 -> V_78 = V_79 ;
}
V_6 -> V_20 = false ;
F_54 ( V_27 , V_34 ) ;
if ( F_58 ( & V_6 -> V_94 ) )
F_71 ( V_6 -> V_22 ) ;
}
}
F_10 ( & V_6 -> V_36 ) ;
}
return;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_45 * V_22 = & V_2 -> V_22 ;
struct V_26 * V_27 ;
struct V_178 * V_126 ;
int V_15 ;
V_27 = F_97 ( V_22 , sizeof( * V_27 ) , V_16 ) ;
if ( ! V_27 )
return - V_67 ;
F_38 ( & V_27 -> V_30 ) ;
F_38 ( & V_27 -> V_76 ) ;
F_98 ( & V_27 -> V_29 ) ;
F_98 ( & V_27 -> V_75 ) ;
V_27 -> V_174 = F_99 ( L_87 ) ;
if ( ! V_27 -> V_174 ) {
F_100 ( V_22 , L_88 ) ;
return - V_25 ;
}
V_27 -> V_134 = F_99 ( L_89 ) ;
if ( ! V_27 -> V_134 ) {
F_100 ( V_22 , L_90 ) ;
V_15 = - V_25 ;
goto V_179;
}
V_126 = & V_27 -> V_126 ;
V_126 -> V_22 = V_22 ;
V_126 -> V_180 = F_88 ;
V_126 -> remove = F_93 ;
V_126 -> V_181 = F_94 ;
V_126 -> V_182 = F_95 ;
F_101 ( V_2 , V_27 ) ;
V_15 = F_102 ( V_126 ) ;
if ( V_15 < 0 ) {
F_30 ( L_91 ) ;
goto V_183;
}
F_103 ( V_22 , L_92 ) ;
return 0 ;
V_183:
F_104 ( V_27 -> V_134 ) ;
V_179:
F_104 ( V_27 -> V_174 ) ;
return V_15 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_106 ( V_2 ) ;
F_107 ( & V_27 -> V_126 ) ;
F_108 ( & V_27 -> V_29 ) ;
F_108 ( & V_27 -> V_75 ) ;
F_56 ( & V_27 -> V_30 ) ;
F_56 ( & V_27 -> V_76 ) ;
F_104 ( V_27 -> V_134 ) ;
F_104 ( V_27 -> V_174 ) ;
return 0 ;
}
