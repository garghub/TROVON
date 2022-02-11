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
if ( ! V_6 )
return - V_7 ;
F_8 ( & V_8 ) ;
F_9 ( & V_6 -> V_9 , & V_10 ) ;
F_10 ( & V_8 ) ;
return 0 ;
}
int F_11 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return - V_7 ;
F_8 ( & V_8 ) ;
F_12 ( & V_6 -> V_9 ) ;
F_10 ( & V_8 ) ;
return 0 ;
}
static int F_13 ( struct V_11 * V_12 , struct V_13 * V_14 , void * V_15 ,
T_1 * V_16 )
{
int V_17 ;
F_8 ( V_14 ) ;
V_17 = F_14 ( V_12 , V_15 , 1 , 0 , V_18 ) ;
F_10 ( V_14 ) ;
if ( V_17 < 0 )
return V_17 ;
* V_16 = V_17 ;
return 0 ;
}
static void * F_15 ( struct V_11 * V_12 , struct V_13 * V_14 , T_1 V_19 )
{
void * V_15 ;
F_16 ( L_2 , V_19 ) ;
F_8 ( V_14 ) ;
V_15 = F_17 ( V_12 , V_19 ) ;
if ( ! V_15 ) {
F_18 ( L_3 ) ;
F_10 ( V_14 ) ;
return F_19 ( - V_20 ) ;
}
F_10 ( V_14 ) ;
return V_15 ;
}
static inline bool F_20 ( struct V_5 * V_6 ,
enum V_21 V_22 )
{
if ( V_6 -> V_23 || ( ! F_21 ( V_22 ) &&
! F_22 ( V_6 -> V_24 ) ) )
return true ;
return false ;
}
static struct V_5 * F_23 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 ;
T_1 V_29 = V_28 -> V_29 ;
F_16 ( L_4 , V_29 ) ;
if ( V_29 ) {
V_6 = F_15 ( & V_26 -> V_30 , & V_26 -> V_31 ,
V_29 ) ;
if ( F_3 ( V_6 ) ) {
F_18 ( L_5 , V_29 ) ;
return V_6 ;
}
if ( F_20 ( V_6 , V_28 -> V_22 ) ) {
F_18 ( L_6 ) ;
return F_19 ( - V_32 ) ;
}
if ( V_6 -> V_33 &&
V_6 -> V_33 ( V_6 -> V_24 , V_28 ) ) {
F_18 ( L_7 ) ;
return F_19 ( - V_7 ) ;
}
return V_6 ;
} else {
F_24 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
if ( F_20 ( V_6 , V_28 -> V_22 ) ) {
F_16 ( L_8 ) ;
continue;
}
if ( V_6 -> V_33 &&
V_6 -> V_33 ( V_6 -> V_24 , V_28 ) ) {
F_16 ( L_7 ) ;
continue;
}
return V_6 ;
}
F_18 ( L_9 ) ;
}
return F_19 ( - V_20 ) ;
}
static struct V_5 * F_25 ( T_1 V_34 )
{
struct V_5 * V_6 ;
struct V_35 * V_36 ;
int V_37 = 0 ;
F_16 ( L_10 , V_34 ) ;
if ( F_26 ( & V_10 ) ) {
F_16 ( L_11 ) ;
return F_19 ( - V_20 ) ;
}
F_24 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
F_16 ( L_12 , V_37 ++ , ( int ) V_6 ) ;
if ( ! F_26 ( & V_6 -> V_38 ) ) {
F_24 (c_node, &ippdrv->cmd_list, list)
if ( V_36 -> V_28 . V_34 == V_34 )
return V_6 ;
}
}
return F_19 ( - V_20 ) ;
}
int F_27 ( struct V_39 * V_40 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_50 * V_24 = V_48 -> V_24 ;
struct V_25 * V_26 = F_28 ( V_24 ) ;
struct V_51 * V_52 = V_41 ;
struct V_5 * V_6 ;
int V_37 = 0 ;
if ( ! V_26 ) {
F_18 ( L_13 ) ;
return - V_7 ;
}
if ( ! V_52 ) {
F_18 ( L_14 ) ;
return - V_7 ;
}
F_16 ( L_4 , V_52 -> V_29 ) ;
if ( ! V_52 -> V_29 ) {
F_24 (ippdrv, &exynos_drm_ippdrv_list, drv_list)
V_37 ++ ;
V_52 -> V_37 = V_37 ;
} else {
V_6 = F_15 ( & V_26 -> V_30 , & V_26 -> V_31 ,
V_52 -> V_29 ) ;
if ( F_3 ( V_6 ) ) {
F_18 ( L_5 ,
V_52 -> V_29 ) ;
return F_4 ( V_6 ) ;
}
V_52 = V_6 -> V_52 ;
}
return 0 ;
}
static void F_29 ( struct V_27 * V_28 ,
int V_53 )
{
struct V_54 * V_55 = & V_28 -> V_55 [ V_53 ] ;
struct V_56 * V_57 = & V_55 -> V_57 ;
struct V_58 * V_59 = & V_55 -> V_59 ;
F_16 ( L_15 ,
V_28 -> V_34 , V_53 ? L_16 : L_17 , V_55 -> V_60 ) ;
F_16 ( L_18 ,
V_57 -> V_61 , V_57 -> V_62 , V_57 -> V_63 , V_57 -> V_64 ,
V_59 -> V_65 , V_59 -> V_66 , V_55 -> V_67 , V_55 -> V_68 ) ;
}
static int F_30 ( struct V_27 * V_28 )
{
struct V_5 * V_6 ;
struct V_35 * V_36 ;
T_1 V_34 = V_28 -> V_34 ;
F_16 ( L_10 , V_34 ) ;
V_6 = F_25 ( V_34 ) ;
if ( F_3 ( V_6 ) ) {
F_18 ( L_19 ) ;
return - V_7 ;
}
F_24 (c_node, &ippdrv->cmd_list, list) {
if ( ( V_36 -> V_28 . V_34 == V_34 ) &&
( V_36 -> V_69 == V_70 ) ) {
F_16 ( L_20 ,
V_28 -> V_22 , ( int ) V_6 ) ;
V_36 -> V_28 = * V_28 ;
return 0 ;
}
}
F_18 ( L_21 ) ;
return - V_7 ;
}
static struct V_71 * F_31 ( void )
{
struct V_71 * V_72 ;
V_72 = F_32 ( sizeof( * V_72 ) , V_18 ) ;
if ( ! V_72 ) {
F_18 ( L_22 ) ;
return F_19 ( - V_73 ) ;
}
F_33 ( (struct V_74 * ) V_72 , V_75 ) ;
return V_72 ;
}
static struct V_76 * F_34 ( void )
{
struct V_76 * V_77 ;
V_77 = F_32 ( sizeof( * V_77 ) , V_18 ) ;
if ( ! V_77 ) {
F_18 ( L_23 ) ;
return F_19 ( - V_73 ) ;
}
F_33 ( (struct V_74 * ) V_77 , V_78 ) ;
return V_77 ;
}
int F_35 ( struct V_39 * V_40 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_50 * V_24 = V_48 -> V_24 ;
struct V_25 * V_26 = F_28 ( V_24 ) ;
struct V_27 * V_28 = V_41 ;
struct V_5 * V_6 ;
struct V_35 * V_36 ;
int V_17 , V_79 ;
if ( ! V_26 ) {
F_18 ( L_13 ) ;
return - V_7 ;
}
if ( ! V_28 ) {
F_18 ( L_14 ) ;
return - V_7 ;
}
F_36 (i)
F_29 ( V_28 , V_79 ) ;
if ( V_28 -> V_34 ) {
F_16 ( L_10 , V_28 -> V_34 ) ;
return F_30 ( V_28 ) ;
}
V_6 = F_23 ( V_26 , V_28 ) ;
if ( F_3 ( V_6 ) ) {
F_18 ( L_19 ) ;
return - V_7 ;
}
V_36 = F_32 ( sizeof( * V_36 ) , V_18 ) ;
if ( ! V_36 ) {
F_18 ( L_24 ) ;
return - V_73 ;
}
V_17 = F_13 ( & V_26 -> V_80 , & V_26 -> V_81 , V_36 ,
& V_28 -> V_34 ) ;
if ( V_17 ) {
F_18 ( L_25 ) ;
goto V_82;
}
F_16 ( L_26 ,
V_28 -> V_34 , V_28 -> V_22 , ( int ) V_6 ) ;
V_36 -> V_48 = V_48 ;
V_36 -> V_28 = * V_28 ;
V_36 -> V_69 = V_83 ;
V_36 -> V_84 = F_31 () ;
if ( F_3 ( V_36 -> V_84 ) ) {
F_18 ( L_27 ) ;
goto V_82;
}
V_36 -> V_85 = F_31 () ;
if ( F_3 ( V_36 -> V_85 ) ) {
F_18 ( L_28 ) ;
goto V_86;
}
V_36 -> V_77 = F_34 () ;
if ( F_3 ( V_36 -> V_77 ) ) {
F_18 ( L_29 ) ;
goto V_87;
}
F_37 ( & V_36 -> V_88 ) ;
F_37 ( & V_36 -> V_89 ) ;
F_37 ( & V_36 -> V_90 ) ;
F_38 ( & V_36 -> V_91 ) ;
F_38 ( & V_36 -> V_92 ) ;
F_36 (i)
F_39 ( & V_36 -> V_93 [ V_79 ] ) ;
F_39 ( & V_36 -> V_94 ) ;
F_40 ( & V_48 -> V_94 , & V_36 -> V_94 ) ;
F_9 ( & V_36 -> V_95 , & V_6 -> V_38 ) ;
if ( ! F_21 ( V_28 -> V_22 ) )
V_6 -> V_23 = true ;
return 0 ;
V_87:
F_41 ( V_36 -> V_85 ) ;
V_86:
F_41 ( V_36 -> V_84 ) ;
V_82:
F_41 ( V_36 ) ;
return V_17 ;
}
static void F_42 ( struct V_35 * V_36 )
{
F_12 ( & V_36 -> V_95 ) ;
F_43 ( & V_36 -> V_88 ) ;
F_43 ( & V_36 -> V_89 ) ;
F_43 ( & V_36 -> V_90 ) ;
F_41 ( V_36 -> V_84 ) ;
F_41 ( V_36 -> V_85 ) ;
F_41 ( V_36 -> V_77 ) ;
F_41 ( V_36 ) ;
}
static int F_44 ( struct V_35 * V_36 )
{
struct V_27 * V_28 = & V_36 -> V_28 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
int V_17 , V_79 , V_37 [ V_100 ] = { 0 , } ;
F_8 ( & V_36 -> V_89 ) ;
F_36 (i) {
V_99 = & V_36 -> V_93 [ V_79 ] ;
if ( F_26 ( V_99 ) ) {
F_16 ( L_30 , V_79 ? L_16 : L_17 ) ;
continue;
}
F_24 (m_node, head, list) {
F_16 ( L_31 ,
V_79 ? L_16 : L_17 , V_37 [ V_79 ] , ( int ) V_97 ) ;
V_37 [ V_79 ] ++ ;
}
}
F_16 ( L_32 ,
F_45 ( V_37 [ V_101 ] , V_37 [ V_102 ] ) ,
F_46 ( V_37 [ V_101 ] , V_37 [ V_102 ] ) ) ;
if ( F_21 ( V_28 -> V_22 ) )
V_17 = F_45 ( V_37 [ V_101 ] ,
V_37 [ V_102 ] ) ;
else
V_17 = F_46 ( V_37 [ V_101 ] ,
V_37 [ V_102 ] ) ;
F_10 ( & V_36 -> V_89 ) ;
return V_17 ;
}
static struct V_96
* F_47 ( struct V_35 * V_36 ,
struct V_103 * V_104 )
{
struct V_96 * V_97 ;
struct V_98 * V_99 ;
int V_37 = 0 ;
F_16 ( L_33 , V_104 -> V_105 ) ;
V_99 = & V_36 -> V_93 [ V_104 -> V_106 ] ;
F_24 (m_node, head, list) {
F_16 ( L_34 , V_37 ++ , ( int ) V_97 ) ;
if ( V_97 -> V_105 == V_104 -> V_105 )
return V_97 ;
}
return NULL ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_35 * V_36 ,
struct V_96 * V_97 )
{
struct V_107 * V_108 = NULL ;
int V_17 = 0 ;
F_16 ( L_35 , ( int ) V_97 ) ;
if ( ! V_97 ) {
F_18 ( L_36 ) ;
return - V_109 ;
}
F_8 ( & V_36 -> V_89 ) ;
F_16 ( L_37 , V_97 -> V_106 ) ;
V_108 = V_6 -> V_108 [ V_97 -> V_106 ] ;
if ( ! V_108 ) {
F_18 ( L_38 ) ;
V_17 = - V_109 ;
goto V_110;
}
if ( V_108 -> V_111 ) {
V_17 = V_108 -> V_111 ( V_6 -> V_24 , & V_97 -> V_112 ,
V_97 -> V_105 , V_113 ) ;
if ( V_17 ) {
F_18 ( L_39 ) ;
goto V_110;
}
}
V_110:
F_10 ( & V_36 -> V_89 ) ;
return V_17 ;
}
static struct V_96
* F_49 ( struct V_39 * V_40 ,
struct V_42 * V_43 ,
struct V_35 * V_36 ,
struct V_103 * V_104 )
{
struct V_96 * V_97 ;
struct V_114 V_112 ;
void * V_115 ;
int V_79 ;
F_8 ( & V_36 -> V_89 ) ;
V_97 = F_32 ( sizeof( * V_97 ) , V_18 ) ;
if ( ! V_97 ) {
F_18 ( L_40 ) ;
goto V_110;
}
memset ( & V_112 , 0x0 , sizeof( V_112 ) ) ;
V_97 -> V_106 = V_104 -> V_106 ;
V_97 -> V_34 = V_104 -> V_34 ;
V_97 -> V_105 = V_104 -> V_105 ;
F_16 ( L_41 , ( int ) V_97 , V_104 -> V_106 ) ;
F_16 ( L_42 , V_104 -> V_34 , V_97 -> V_105 ) ;
F_50 (i) {
F_16 ( L_43 , V_79 , V_104 -> V_116 [ V_79 ] ) ;
if ( V_104 -> V_116 [ V_79 ] ) {
V_115 = F_51 ( V_40 ,
V_104 -> V_116 [ V_79 ] , V_43 ) ;
if ( F_3 ( V_115 ) ) {
F_18 ( L_44 ) ;
goto V_82;
}
V_112 . V_117 [ V_79 ] = V_104 -> V_116 [ V_79 ] ;
V_112 . V_118 [ V_79 ] = * ( V_119 * ) V_115 ;
F_16 ( L_45 ,
V_79 , V_112 . V_118 [ V_79 ] , ( int ) V_112 . V_117 [ V_79 ] ) ;
}
}
V_97 -> V_120 = V_43 ;
V_97 -> V_112 = V_112 ;
F_9 ( & V_97 -> V_95 , & V_36 -> V_93 [ V_104 -> V_106 ] ) ;
F_10 ( & V_36 -> V_89 ) ;
return V_97 ;
V_82:
F_41 ( V_97 ) ;
V_110:
F_10 ( & V_36 -> V_89 ) ;
return F_19 ( - V_109 ) ;
}
static int F_52 ( struct V_39 * V_40 ,
struct V_35 * V_36 ,
struct V_96 * V_97 )
{
int V_79 ;
F_16 ( L_35 , ( int ) V_97 ) ;
if ( ! V_97 ) {
F_18 ( L_46 ) ;
return - V_109 ;
}
if ( F_26 ( & V_97 -> V_95 ) ) {
F_18 ( L_47 ) ;
return - V_73 ;
}
F_8 ( & V_36 -> V_89 ) ;
F_16 ( L_37 , V_97 -> V_106 ) ;
F_50 (i) {
unsigned long V_116 = V_97 -> V_112 . V_117 [ V_79 ] ;
if ( V_116 )
F_53 ( V_40 , V_116 ,
V_97 -> V_120 ) ;
}
F_12 ( & V_97 -> V_95 ) ;
F_41 ( V_97 ) ;
F_10 ( & V_36 -> V_89 ) ;
return 0 ;
}
static void F_54 ( struct V_121 * V_122 )
{
F_41 ( V_122 ) ;
}
static int F_55 ( struct V_39 * V_40 ,
struct V_42 * V_43 ,
struct V_35 * V_36 ,
struct V_103 * V_104 )
{
struct V_123 * V_124 ;
unsigned long V_125 ;
F_16 ( L_48 , V_104 -> V_106 , V_104 -> V_105 ) ;
V_124 = F_32 ( sizeof( * V_124 ) , V_18 ) ;
if ( ! V_124 ) {
F_18 ( L_49 ) ;
F_56 ( & V_40 -> V_90 , V_125 ) ;
V_43 -> V_126 += sizeof( V_124 -> V_122 ) ;
F_57 ( & V_40 -> V_90 , V_125 ) ;
return - V_73 ;
}
V_124 -> V_122 . V_118 . type = V_127 ;
V_124 -> V_122 . V_118 . V_128 = sizeof( V_124 -> V_122 ) ;
V_124 -> V_122 . V_129 = V_104 -> V_129 ;
V_124 -> V_122 . V_34 = V_104 -> V_34 ;
V_124 -> V_122 . V_105 [ V_102 ] = V_104 -> V_105 ;
V_124 -> V_118 . V_122 = & V_124 -> V_122 . V_118 ;
V_124 -> V_118 . V_45 = V_43 ;
V_124 -> V_118 . V_130 = F_54 ;
F_9 ( & V_124 -> V_118 . V_131 , & V_36 -> V_94 ) ;
return 0 ;
}
static void F_58 ( struct V_35 * V_36 ,
struct V_103 * V_104 )
{
struct V_123 * V_124 , * V_132 ;
int V_37 = 0 ;
if ( F_26 ( & V_36 -> V_94 ) ) {
F_16 ( L_50 ) ;
return;
}
F_59 (e, te, &c_node->event_list, base.link) {
F_16 ( L_51 , V_37 ++ , ( int ) V_124 ) ;
if ( ! V_104 ) {
F_12 ( & V_124 -> V_118 . V_131 ) ;
F_41 ( V_124 ) ;
}
if ( V_104 && ( V_104 -> V_105 ==
V_124 -> V_122 . V_105 [ V_102 ] ) ) {
F_12 ( & V_124 -> V_118 . V_131 ) ;
F_41 ( V_124 ) ;
return;
}
}
}
static void F_60 ( struct V_50 * V_24 ,
struct V_5 * V_6 ,
struct V_71 * V_72 ,
struct V_35 * V_36 )
{
struct V_25 * V_26 = F_28 ( V_24 ) ;
V_72 -> V_6 = V_6 ;
V_72 -> V_36 = V_36 ;
F_61 ( V_26 -> V_133 , (struct V_74 * ) V_72 ) ;
}
static int F_62 ( struct V_50 * V_24 ,
struct V_35 * V_36 ,
struct V_96 * V_97 ,
struct V_103 * V_104 )
{
struct V_5 * V_6 ;
struct V_27 * V_28 ;
struct V_107 * V_108 ;
int V_17 ;
V_6 = F_25 ( V_104 -> V_34 ) ;
if ( F_3 ( V_6 ) ) {
F_18 ( L_19 ) ;
return - V_109 ;
}
V_108 = V_6 -> V_108 [ V_104 -> V_106 ] ;
if ( ! V_108 ) {
F_18 ( L_52 ) ;
return - V_109 ;
}
V_28 = & V_36 -> V_28 ;
if ( V_36 -> V_69 != V_134 ) {
F_16 ( L_53 ) ;
return 0 ;
}
if ( ! F_44 ( V_36 ) ) {
F_16 ( L_54 ) ;
return 0 ;
}
if ( F_21 ( V_28 -> V_22 ) ) {
struct V_71 * V_72 = V_36 -> V_84 ;
V_72 -> V_135 = V_136 ;
F_60 ( V_24 , V_6 , V_72 , V_36 ) ;
} else {
V_17 = F_48 ( V_6 , V_36 , V_97 ) ;
if ( V_17 ) {
F_18 ( L_55 ) ;
return V_17 ;
}
}
return 0 ;
}
static void F_63 ( struct V_39 * V_40 ,
struct V_35 * V_36 ,
struct V_103 * V_104 )
{
struct V_96 * V_97 , * V_137 ;
if ( ! F_26 ( & V_36 -> V_93 [ V_104 -> V_106 ] ) ) {
F_59 (m_node, tm_node,
&c_node->mem_list[qbuf->ops_id], list) {
if ( V_97 -> V_105 == V_104 -> V_105 &&
V_97 -> V_106 == V_104 -> V_106 )
F_52 ( V_40 , V_36 , V_97 ) ;
}
}
}
int F_64 ( struct V_39 * V_40 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_50 * V_24 = V_48 -> V_24 ;
struct V_25 * V_26 = F_28 ( V_24 ) ;
struct V_103 * V_104 = V_41 ;
struct V_35 * V_36 ;
struct V_96 * V_97 ;
int V_17 ;
if ( ! V_104 ) {
F_18 ( L_56 ) ;
return - V_7 ;
}
if ( V_104 -> V_106 >= V_100 ) {
F_18 ( L_57 ) ;
return - V_7 ;
}
F_16 ( L_58 ,
V_104 -> V_34 , V_104 -> V_106 ? L_16 : L_17 ,
V_104 -> V_105 , V_104 -> V_138 ) ;
V_36 = F_15 ( & V_26 -> V_80 , & V_26 -> V_81 ,
V_104 -> V_34 ) ;
if ( F_3 ( V_36 ) ) {
F_18 ( L_59 ) ;
return F_4 ( V_36 ) ;
}
switch ( V_104 -> V_138 ) {
case V_113 :
V_97 = F_49 ( V_40 , V_43 , V_36 , V_104 ) ;
if ( F_3 ( V_97 ) ) {
F_18 ( L_60 ) ;
return F_4 ( V_97 ) ;
}
if ( V_104 -> V_106 == V_102 ) {
V_17 = F_55 ( V_40 , V_43 , V_36 , V_104 ) ;
if ( V_17 ) {
F_18 ( L_61 ) ;
goto V_139;
}
V_17 = F_62 ( V_24 , V_36 , V_97 , V_104 ) ;
if ( V_17 ) {
F_18 ( L_62 ) ;
goto V_139;
}
}
break;
case V_140 :
F_8 ( & V_36 -> V_88 ) ;
if ( V_104 -> V_106 == V_102 )
F_58 ( V_36 , V_104 ) ;
F_63 ( V_40 , V_36 , V_104 ) ;
F_10 ( & V_36 -> V_88 ) ;
break;
default:
F_18 ( L_63 ) ;
return - V_7 ;
}
return 0 ;
V_139:
F_18 ( L_64 ) ;
F_63 ( V_40 , V_36 , V_104 ) ;
return V_17 ;
}
static bool F_65 ( struct V_50 * V_24 ,
enum V_141 V_135 , enum V_142 V_69 )
{
if ( V_135 != V_136 ) {
if ( F_22 ( V_24 ) ) {
F_18 ( L_65 ) ;
goto V_143;
}
}
switch ( V_135 ) {
case V_136 :
if ( V_69 != V_83 )
goto V_143;
break;
case V_144 :
if ( V_69 == V_70 )
goto V_143;
break;
case V_145 :
if ( V_69 != V_134 )
goto V_143;
break;
case V_146 :
if ( V_69 != V_70 )
goto V_143;
break;
default:
F_18 ( L_66 ) ;
goto V_143;
}
return true ;
V_143:
F_18 ( L_67 , V_135 , V_69 ) ;
return false ;
}
int F_66 ( struct V_39 * V_40 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_5 * V_6 = NULL ;
struct V_50 * V_24 = V_48 -> V_24 ;
struct V_25 * V_26 = F_28 ( V_24 ) ;
struct V_147 * V_148 = V_41 ;
struct V_71 * V_72 ;
struct V_35 * V_36 ;
if ( ! V_26 ) {
F_18 ( L_13 ) ;
return - V_7 ;
}
if ( ! V_148 ) {
F_18 ( L_68 ) ;
return - V_7 ;
}
F_16 ( L_69 ,
V_148 -> V_135 , V_148 -> V_34 ) ;
V_6 = F_25 ( V_148 -> V_34 ) ;
if ( F_3 ( V_6 ) ) {
F_18 ( L_19 ) ;
return F_4 ( V_6 ) ;
}
V_36 = F_15 ( & V_26 -> V_80 , & V_26 -> V_81 ,
V_148 -> V_34 ) ;
if ( F_3 ( V_36 ) ) {
F_18 ( L_70 ) ;
return F_4 ( V_36 ) ;
}
if ( ! F_65 ( V_6 -> V_24 , V_148 -> V_135 ,
V_36 -> V_69 ) ) {
F_18 ( L_66 ) ;
return - V_7 ;
}
switch ( V_148 -> V_135 ) {
case V_136 :
if ( F_22 ( V_6 -> V_24 ) )
F_67 ( V_6 -> V_24 ) ;
V_36 -> V_69 = V_134 ;
V_72 = V_36 -> V_84 ;
V_72 -> V_135 = V_148 -> V_135 ;
F_60 ( V_24 , V_6 , V_72 , V_36 ) ;
V_36 -> V_69 = V_134 ;
break;
case V_144 :
V_72 = V_36 -> V_85 ;
V_72 -> V_135 = V_148 -> V_135 ;
F_60 ( V_24 , V_6 , V_72 , V_36 ) ;
if ( ! F_68 ( & V_36 -> V_92 ,
F_69 ( 300 ) ) ) {
F_18 ( L_71 ,
V_36 -> V_28 . V_34 ) ;
}
V_36 -> V_69 = V_70 ;
V_6 -> V_23 = false ;
F_42 ( V_36 ) ;
if ( F_26 ( & V_6 -> V_38 ) )
F_70 ( V_6 -> V_24 ) ;
break;
case V_145 :
V_72 = V_36 -> V_85 ;
V_72 -> V_135 = V_148 -> V_135 ;
F_60 ( V_24 , V_6 , V_72 , V_36 ) ;
if ( ! F_68 ( & V_36 -> V_92 ,
F_69 ( 200 ) ) ) {
F_18 ( L_71 ,
V_36 -> V_28 . V_34 ) ;
}
V_36 -> V_69 = V_70 ;
break;
case V_146 :
V_36 -> V_69 = V_134 ;
V_72 = V_36 -> V_84 ;
V_72 -> V_135 = V_148 -> V_135 ;
F_60 ( V_24 , V_6 , V_72 , V_36 ) ;
break;
default:
F_18 ( L_72 ) ;
return - V_7 ;
}
F_16 ( L_73 ,
V_148 -> V_135 , V_148 -> V_34 ) ;
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
struct V_27 * V_28 )
{
struct V_107 * V_108 = NULL ;
bool V_154 = false ;
int V_17 , V_79 ;
if ( ! V_28 ) {
F_18 ( L_14 ) ;
return - V_7 ;
}
F_16 ( L_10 , V_28 -> V_34 ) ;
if ( V_6 -> V_155 &&
V_6 -> V_155 ( V_6 -> V_24 ) ) {
F_18 ( L_74 ) ;
return - V_7 ;
}
F_36 (i) {
struct V_54 * V_55 =
& V_28 -> V_55 [ V_79 ] ;
V_108 = V_6 -> V_108 [ V_79 ] ;
if ( ! V_108 || ! V_55 ) {
F_18 ( L_75 ) ;
return - V_7 ;
}
if ( V_108 -> V_156 ) {
V_17 = V_108 -> V_156 ( V_6 -> V_24 , V_55 -> V_60 ) ;
if ( V_17 ) {
F_18 ( L_76 ) ;
return V_17 ;
}
}
if ( V_108 -> V_157 ) {
V_17 = V_108 -> V_157 ( V_6 -> V_24 , V_55 -> V_68 ,
V_55 -> V_67 , & V_154 ) ;
if ( V_17 ) {
F_18 ( L_77 ) ;
return - V_7 ;
}
}
if ( V_108 -> V_158 ) {
V_17 = V_108 -> V_158 ( V_6 -> V_24 , V_154 , & V_55 -> V_57 ,
& V_55 -> V_59 ) ;
if ( V_17 ) {
F_18 ( L_78 ) ;
return V_17 ;
}
}
}
return 0 ;
}
static int F_78 ( struct V_5 * V_6 ,
struct V_35 * V_36 )
{
struct V_96 * V_97 ;
struct V_27 * V_28 = & V_36 -> V_28 ;
struct V_98 * V_99 ;
int V_17 , V_79 ;
F_16 ( L_10 , V_28 -> V_34 ) ;
V_6 -> V_36 = V_36 ;
if ( ! F_44 ( V_36 ) ) {
F_16 ( L_54 ) ;
return - V_73 ;
}
V_17 = F_77 ( V_6 , V_28 ) ;
if ( V_17 ) {
F_18 ( L_79 ) ;
V_6 -> V_36 = NULL ;
return V_17 ;
}
switch ( V_28 -> V_22 ) {
case V_159 :
F_36 (i) {
V_99 = & V_36 -> V_93 [ V_79 ] ;
V_97 = F_79 ( V_99 ,
struct V_96 , V_95 ) ;
if ( ! V_97 ) {
F_18 ( L_80 ) ;
V_17 = - V_109 ;
return V_17 ;
}
F_16 ( L_81 , ( int ) V_97 ) ;
V_17 = F_48 ( V_6 , V_36 , V_97 ) ;
if ( V_17 ) {
F_18 ( L_55 ) ;
return V_17 ;
}
}
break;
case V_160 :
V_99 = & V_36 -> V_93 [ V_102 ] ;
F_24 (m_node, head, list) {
V_17 = F_48 ( V_6 , V_36 , V_97 ) ;
if ( V_17 ) {
F_18 ( L_55 ) ;
return V_17 ;
}
}
break;
case V_161 :
V_99 = & V_36 -> V_93 [ V_101 ] ;
F_24 (m_node, head, list) {
V_17 = F_48 ( V_6 , V_36 , V_97 ) ;
if ( V_17 ) {
F_18 ( L_55 ) ;
return V_17 ;
}
}
break;
default:
F_18 ( L_82 ) ;
return - V_7 ;
}
F_16 ( L_83 , V_28 -> V_22 ) ;
if ( V_6 -> V_162 ) {
V_17 = V_6 -> V_162 ( V_6 -> V_24 , V_28 -> V_22 ) ;
if ( V_17 ) {
F_18 ( L_84 ) ;
return V_17 ;
}
}
return 0 ;
}
static int F_80 ( struct V_39 * V_40 ,
struct V_5 * V_6 ,
struct V_35 * V_36 )
{
struct V_96 * V_97 , * V_137 ;
struct V_27 * V_28 = & V_36 -> V_28 ;
struct V_98 * V_99 ;
int V_17 = 0 , V_79 ;
F_16 ( L_10 , V_28 -> V_34 ) ;
F_58 ( V_36 , NULL ) ;
switch ( V_28 -> V_22 ) {
case V_159 :
F_36 (i) {
V_99 = & V_36 -> V_93 [ V_79 ] ;
if ( F_26 ( V_99 ) ) {
F_16 ( L_85 ) ;
break;
}
F_59 (m_node, tm_node,
head, list) {
V_17 = F_52 ( V_40 , V_36 ,
V_97 ) ;
if ( V_17 ) {
F_18 ( L_86 ) ;
goto V_82;
}
}
}
break;
case V_160 :
V_99 = & V_36 -> V_93 [ V_102 ] ;
if ( F_26 ( V_99 ) ) {
F_16 ( L_85 ) ;
break;
}
F_59 (m_node, tm_node, head, list) {
V_17 = F_52 ( V_40 , V_36 , V_97 ) ;
if ( V_17 ) {
F_18 ( L_86 ) ;
goto V_82;
}
}
break;
case V_161 :
V_99 = & V_36 -> V_93 [ V_101 ] ;
if ( F_26 ( V_99 ) ) {
F_16 ( L_85 ) ;
break;
}
F_59 (m_node, tm_node, head, list) {
V_17 = F_52 ( V_40 , V_36 , V_97 ) ;
if ( V_17 ) {
F_18 ( L_86 ) ;
goto V_82;
}
}
break;
default:
F_18 ( L_82 ) ;
V_17 = - V_7 ;
goto V_82;
}
V_82:
if ( V_6 -> V_163 )
V_6 -> V_163 ( V_6 -> V_24 , V_28 -> V_22 ) ;
return V_17 ;
}
void V_75 ( struct V_74 * V_164 )
{
struct V_71 * V_72 =
(struct V_71 * ) V_164 ;
struct V_5 * V_6 ;
struct V_35 * V_36 ;
struct V_27 * V_28 ;
int V_17 ;
V_6 = V_72 -> V_6 ;
if ( ! V_6 ) {
F_18 ( L_87 ) ;
return;
}
V_36 = V_72 -> V_36 ;
if ( ! V_36 ) {
F_18 ( L_70 ) ;
return;
}
F_8 ( & V_36 -> V_88 ) ;
V_28 = & V_36 -> V_28 ;
switch ( V_72 -> V_135 ) {
case V_136 :
case V_146 :
V_17 = F_78 ( V_6 , V_36 ) ;
if ( V_17 ) {
F_18 ( L_88 ,
V_36 -> V_28 . V_34 ) ;
goto V_110;
}
if ( F_21 ( V_28 -> V_22 ) ) {
if ( ! F_68
( & V_36 -> V_91 , F_69 ( 200 ) ) ) {
F_18 ( L_89 ,
V_36 -> V_28 . V_34 ) ;
goto V_110;
}
}
break;
case V_144 :
case V_145 :
V_17 = F_80 ( V_6 -> V_40 , V_6 ,
V_36 ) ;
if ( V_17 ) {
F_18 ( L_90 ) ;
goto V_110;
}
F_81 ( & V_36 -> V_92 ) ;
break;
default:
F_18 ( L_91 ) ;
break;
}
F_16 ( L_92 , V_72 -> V_135 ) ;
V_110:
F_10 ( & V_36 -> V_88 ) ;
}
static int F_82 ( struct V_5 * V_6 ,
struct V_35 * V_36 , int * V_105 )
{
struct V_39 * V_40 = V_6 -> V_40 ;
struct V_27 * V_28 = & V_36 -> V_28 ;
struct V_96 * V_97 ;
struct V_103 V_104 ;
struct V_123 * V_124 ;
struct V_98 * V_99 ;
struct V_165 V_166 ;
unsigned long V_125 ;
T_1 V_167 [ V_100 ] = { 0 , } ;
int V_17 , V_79 ;
F_36 (i)
F_16 ( L_93 , V_79 ? L_16 : L_17 , V_105 [ V_79 ] ) ;
if ( ! V_40 ) {
F_18 ( L_94 ) ;
return - V_7 ;
}
if ( ! V_28 ) {
F_18 ( L_95 ) ;
return - V_7 ;
}
if ( F_26 ( & V_36 -> V_94 ) ) {
F_16 ( L_96 ) ;
return 0 ;
}
if ( ! F_44 ( V_36 ) ) {
F_16 ( L_54 ) ;
return 0 ;
}
switch ( V_28 -> V_22 ) {
case V_159 :
F_36 (i) {
V_99 = & V_36 -> V_93 [ V_79 ] ;
V_97 = F_79 ( V_99 ,
struct V_96 , V_95 ) ;
if ( ! V_97 ) {
F_18 ( L_47 ) ;
return - V_73 ;
}
V_167 [ V_79 ] = V_97 -> V_105 ;
F_16 ( L_93 ,
V_79 ? L_16 : L_17 , V_167 [ V_79 ] ) ;
V_17 = F_52 ( V_40 , V_36 , V_97 ) ;
if ( V_17 )
F_18 ( L_86 ) ;
}
break;
case V_160 :
memset ( & V_104 , 0x0 , sizeof( V_104 ) ) ;
V_104 . V_106 = V_102 ;
V_104 . V_105 = V_105 [ V_102 ] ;
V_97 = F_47 ( V_36 , & V_104 ) ;
if ( ! V_97 ) {
F_18 ( L_47 ) ;
return - V_73 ;
}
V_167 [ V_102 ] = V_97 -> V_105 ;
V_17 = F_52 ( V_40 , V_36 , V_97 ) ;
if ( V_17 )
F_18 ( L_86 ) ;
break;
case V_161 :
V_99 = & V_36 -> V_93 [ V_101 ] ;
V_97 = F_79 ( V_99 ,
struct V_96 , V_95 ) ;
if ( ! V_97 ) {
F_18 ( L_47 ) ;
return - V_73 ;
}
V_167 [ V_101 ] = V_97 -> V_105 ;
V_17 = F_52 ( V_40 , V_36 , V_97 ) ;
if ( V_17 )
F_18 ( L_86 ) ;
break;
default:
F_18 ( L_82 ) ;
return - V_7 ;
}
if ( V_167 [ V_102 ] != V_105 [ V_102 ] )
F_18 ( L_97 ,
V_167 [ 1 ] , V_105 [ 1 ] , V_28 -> V_34 ) ;
V_124 = F_79 ( & V_36 -> V_94 ,
struct V_123 , V_118 . V_131 ) ;
if ( ! V_124 ) {
F_18 ( L_98 ) ;
return - V_7 ;
}
F_83 ( & V_166 ) ;
F_16 ( L_99 , V_166 . V_168 , V_166 . V_169 ) ;
V_124 -> V_122 . V_168 = V_166 . V_168 ;
V_124 -> V_122 . V_169 = V_166 . V_169 ;
V_124 -> V_122 . V_34 = V_28 -> V_34 ;
F_36 (i)
V_124 -> V_122 . V_105 [ V_79 ] = V_167 [ V_79 ] ;
F_56 ( & V_40 -> V_90 , V_125 ) ;
F_84 ( & V_124 -> V_118 . V_131 , & V_124 -> V_118 . V_45 -> V_94 ) ;
F_85 ( & V_124 -> V_118 . V_45 -> V_170 ) ;
F_57 ( & V_40 -> V_90 , V_125 ) ;
F_16 ( L_100 ,
V_28 -> V_22 , V_28 -> V_34 , V_167 [ V_102 ] ) ;
return 0 ;
}
void V_78 ( struct V_74 * V_164 )
{
struct V_76 * V_77 =
(struct V_76 * ) V_164 ;
struct V_5 * V_6 ;
struct V_35 * V_36 ;
int V_17 ;
if ( ! V_77 ) {
F_18 ( L_101 ) ;
return;
}
F_16 ( L_33 , V_77 -> V_105 [ V_102 ] ) ;
V_6 = V_77 -> V_6 ;
if ( ! V_6 ) {
F_18 ( L_19 ) ;
return;
}
V_36 = V_6 -> V_36 ;
if ( ! V_36 ) {
F_18 ( L_59 ) ;
return;
}
if ( V_36 -> V_69 != V_134 ) {
F_16 ( L_102 ,
V_36 -> V_69 , V_36 -> V_28 . V_34 ) ;
goto V_171;
}
F_8 ( & V_36 -> V_90 ) ;
V_17 = F_82 ( V_6 , V_36 , V_77 -> V_105 ) ;
if ( V_17 ) {
F_18 ( L_103 ) ;
goto V_171;
}
V_171:
if ( F_21 ( V_36 -> V_28 . V_22 ) )
F_81 ( & V_36 -> V_91 ) ;
F_10 ( & V_36 -> V_90 ) ;
}
static int F_86 ( struct V_39 * V_40 , struct V_50 * V_24 )
{
struct V_25 * V_26 = F_28 ( V_24 ) ;
struct V_5 * V_6 ;
int V_17 , V_37 = 0 ;
F_24 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
V_6 -> V_40 = V_40 ;
V_17 = F_13 ( & V_26 -> V_30 , & V_26 -> V_31 , V_6 ,
& V_6 -> V_29 ) ;
if ( V_17 ) {
F_18 ( L_25 ) ;
goto V_172;
}
F_16 ( L_104 ,
V_37 ++ , ( int ) V_6 , V_6 -> V_29 ) ;
if ( V_6 -> V_29 == 0 ) {
F_18 ( L_105 ,
V_6 -> V_29 ) ;
goto V_172;
}
V_6 -> V_173 = V_24 ;
V_6 -> V_174 = V_26 -> V_174 ;
V_6 -> V_175 = V_78 ;
F_39 ( & V_6 -> V_38 ) ;
if ( F_87 ( V_40 ) ) {
V_17 = F_88 ( V_40 , V_6 -> V_24 ) ;
if ( V_17 ) {
F_18 ( L_106 ) ;
goto V_176;
}
}
}
return 0 ;
V_176:
F_89 (ippdrv, &exynos_drm_ippdrv_list, drv_list)
if ( F_87 ( V_40 ) )
F_90 ( V_40 , V_6 -> V_24 ) ;
V_172:
F_91 ( & V_26 -> V_30 ) ;
F_91 ( & V_26 -> V_80 ) ;
return V_17 ;
}
static void F_92 ( struct V_39 * V_40 , struct V_50 * V_24 )
{
struct V_5 * V_6 ;
F_24 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
if ( F_87 ( V_40 ) )
F_90 ( V_40 , V_6 -> V_24 ) ;
V_6 -> V_40 = NULL ;
F_11 ( V_6 ) ;
}
}
static int F_93 ( struct V_39 * V_40 , struct V_50 * V_24 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 ;
V_48 = F_32 ( sizeof( * V_48 ) , V_18 ) ;
if ( ! V_48 ) {
F_18 ( L_107 ) ;
return - V_73 ;
}
V_48 -> V_24 = V_24 ;
V_45 -> V_49 = V_48 ;
F_39 ( & V_48 -> V_94 ) ;
F_16 ( L_108 , ( int ) V_48 ) ;
return 0 ;
}
static void F_94 ( struct V_39 * V_40 , struct V_50 * V_24 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_5 * V_6 = NULL ;
struct V_35 * V_36 , * V_177 ;
int V_37 = 0 ;
F_16 ( L_109 , ( int ) V_48 ) ;
if ( F_26 ( & V_10 ) ) {
F_16 ( L_11 ) ;
goto V_82;
}
F_24 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
if ( F_26 ( & V_6 -> V_38 ) )
continue;
F_59 (c_node, tc_node,
&ippdrv->cmd_list, list) {
F_16 ( L_12 ,
V_37 ++ , ( int ) V_6 ) ;
if ( V_36 -> V_48 == V_48 ) {
if ( V_36 -> V_69 == V_134 ) {
F_80 ( V_40 , V_6 ,
V_36 ) ;
V_36 -> V_69 = V_70 ;
}
V_6 -> V_23 = false ;
F_42 ( V_36 ) ;
if ( F_26 ( & V_6 -> V_38 ) )
F_70 ( V_6 -> V_24 ) ;
}
}
}
V_82:
F_41 ( V_48 ) ;
return;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_50 * V_24 = & V_2 -> V_24 ;
struct V_25 * V_26 ;
struct V_178 * V_179 ;
int V_17 ;
V_26 = F_96 ( V_24 , sizeof( * V_26 ) , V_18 ) ;
if ( ! V_26 )
return - V_73 ;
F_37 ( & V_26 -> V_31 ) ;
F_37 ( & V_26 -> V_81 ) ;
F_97 ( & V_26 -> V_30 ) ;
F_97 ( & V_26 -> V_80 ) ;
V_26 -> V_174 = F_98 ( L_110 ) ;
if ( ! V_26 -> V_174 ) {
F_99 ( V_24 , L_111 ) ;
return - V_7 ;
}
V_26 -> V_133 = F_98 ( L_112 ) ;
if ( ! V_26 -> V_133 ) {
F_99 ( V_24 , L_113 ) ;
V_17 = - V_7 ;
goto V_180;
}
V_179 = & V_26 -> V_179 ;
V_179 -> V_24 = V_24 ;
V_179 -> V_181 = F_86 ;
V_179 -> remove = F_92 ;
V_179 -> V_182 = F_93 ;
V_179 -> V_183 = F_94 ;
F_100 ( V_2 , V_26 ) ;
V_17 = F_101 ( V_179 ) ;
if ( V_17 < 0 ) {
F_18 ( L_114 ) ;
goto V_184;
}
F_102 ( V_24 , L_115 ) ;
return 0 ;
V_184:
F_103 ( V_26 -> V_133 ) ;
V_180:
F_103 ( V_26 -> V_174 ) ;
return V_17 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_105 ( V_2 ) ;
F_106 ( & V_26 -> V_179 ) ;
F_91 ( & V_26 -> V_30 ) ;
F_91 ( & V_26 -> V_80 ) ;
F_43 ( & V_26 -> V_31 ) ;
F_43 ( & V_26 -> V_81 ) ;
F_103 ( V_26 -> V_133 ) ;
F_103 ( V_26 -> V_174 ) ;
return 0 ;
}
static int F_107 ( struct V_25 * V_26 , bool V_185 )
{
F_16 ( L_116 , V_185 ) ;
return 0 ;
}
static int F_108 ( struct V_50 * V_24 )
{
struct V_25 * V_26 = F_28 ( V_24 ) ;
if ( F_22 ( V_24 ) )
return 0 ;
return F_107 ( V_26 , false ) ;
}
static int F_109 ( struct V_50 * V_24 )
{
struct V_25 * V_26 = F_28 ( V_24 ) ;
if ( ! F_22 ( V_24 ) )
return F_107 ( V_26 , true ) ;
return 0 ;
}
static int F_110 ( struct V_50 * V_24 )
{
struct V_25 * V_26 = F_28 ( V_24 ) ;
return F_107 ( V_26 , false ) ;
}
static int F_111 ( struct V_50 * V_24 )
{
struct V_25 * V_26 = F_28 ( V_24 ) ;
return F_107 ( V_26 , true ) ;
}
