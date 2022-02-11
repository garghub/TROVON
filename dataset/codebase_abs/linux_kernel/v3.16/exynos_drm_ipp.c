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
static void F_15 ( struct V_11 * V_12 , struct V_13 * V_14 , T_1 V_19 )
{
F_8 ( V_14 ) ;
F_16 ( V_12 , V_19 ) ;
F_10 ( V_14 ) ;
}
static void * F_17 ( struct V_11 * V_12 , struct V_13 * V_14 , T_1 V_19 )
{
void * V_15 ;
F_18 ( L_2 , V_19 ) ;
F_8 ( V_14 ) ;
V_15 = F_19 ( V_12 , V_19 ) ;
if ( ! V_15 ) {
F_20 ( L_3 ) ;
F_10 ( V_14 ) ;
return F_21 ( - V_20 ) ;
}
F_10 ( V_14 ) ;
return V_15 ;
}
static inline bool F_22 ( struct V_5 * V_6 ,
enum V_21 V_22 )
{
if ( V_6 -> V_23 || ( ! F_23 ( V_22 ) &&
! F_24 ( V_6 -> V_24 ) ) )
return true ;
return false ;
}
static struct V_5 * F_25 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 ;
T_1 V_29 = V_28 -> V_29 ;
F_18 ( L_4 , V_29 ) ;
if ( V_29 ) {
V_6 = F_17 ( & V_26 -> V_30 , & V_26 -> V_31 ,
V_29 ) ;
if ( F_3 ( V_6 ) ) {
F_20 ( L_5 , V_29 ) ;
return V_6 ;
}
if ( F_22 ( V_6 , V_28 -> V_22 ) ) {
F_20 ( L_6 ) ;
return F_21 ( - V_32 ) ;
}
if ( V_6 -> V_33 &&
V_6 -> V_33 ( V_6 -> V_24 , V_28 ) ) {
F_20 ( L_7 ) ;
return F_21 ( - V_7 ) ;
}
return V_6 ;
} else {
F_26 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
if ( F_22 ( V_6 , V_28 -> V_22 ) ) {
F_18 ( L_8 ) ;
continue;
}
if ( V_6 -> V_33 &&
V_6 -> V_33 ( V_6 -> V_24 , V_28 ) ) {
F_18 ( L_7 ) ;
continue;
}
return V_6 ;
}
F_20 ( L_9 ) ;
}
return F_21 ( - V_20 ) ;
}
static struct V_5 * F_27 ( T_1 V_34 )
{
struct V_5 * V_6 ;
struct V_35 * V_36 ;
int V_37 = 0 ;
F_18 ( L_10 , V_34 ) ;
F_26 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
F_18 ( L_11 , V_37 ++ , ( int ) V_6 ) ;
F_8 ( & V_6 -> V_38 ) ;
F_26 (c_node, &ippdrv->cmd_list, list) {
if ( V_36 -> V_28 . V_34 == V_34 ) {
F_10 ( & V_6 -> V_38 ) ;
return V_6 ;
}
}
F_10 ( & V_6 -> V_38 ) ;
}
return F_21 ( - V_20 ) ;
}
int F_28 ( struct V_39 * V_40 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_50 * V_24 = V_48 -> V_24 ;
struct V_25 * V_26 = F_29 ( V_24 ) ;
struct V_51 * V_52 = V_41 ;
struct V_5 * V_6 ;
int V_37 = 0 ;
if ( ! V_26 ) {
F_20 ( L_12 ) ;
return - V_7 ;
}
if ( ! V_52 ) {
F_20 ( L_13 ) ;
return - V_7 ;
}
F_18 ( L_4 , V_52 -> V_29 ) ;
if ( ! V_52 -> V_29 ) {
F_26 (ippdrv, &exynos_drm_ippdrv_list, drv_list)
V_37 ++ ;
V_52 -> V_37 = V_37 ;
} else {
V_6 = F_17 ( & V_26 -> V_30 , & V_26 -> V_31 ,
V_52 -> V_29 ) ;
if ( F_3 ( V_6 ) ) {
F_20 ( L_5 ,
V_52 -> V_29 ) ;
return F_4 ( V_6 ) ;
}
* V_52 = V_6 -> V_52 ;
}
return 0 ;
}
static void F_30 ( struct V_27 * V_28 ,
int V_53 )
{
struct V_54 * V_55 = & V_28 -> V_55 [ V_53 ] ;
struct V_56 * V_57 = & V_55 -> V_57 ;
struct V_58 * V_59 = & V_55 -> V_59 ;
F_18 ( L_14 ,
V_28 -> V_34 , V_53 ? L_15 : L_16 , V_55 -> V_60 ) ;
F_18 ( L_17 ,
V_57 -> V_61 , V_57 -> V_62 , V_57 -> V_63 , V_57 -> V_64 ,
V_59 -> V_65 , V_59 -> V_66 , V_55 -> V_67 , V_55 -> V_68 ) ;
}
static int F_31 ( struct V_27 * V_28 )
{
struct V_5 * V_6 ;
struct V_35 * V_36 ;
T_1 V_34 = V_28 -> V_34 ;
F_18 ( L_10 , V_34 ) ;
V_6 = F_27 ( V_34 ) ;
if ( F_3 ( V_6 ) ) {
F_20 ( L_18 ) ;
return - V_7 ;
}
F_8 ( & V_6 -> V_38 ) ;
F_26 (c_node, &ippdrv->cmd_list, list) {
if ( ( V_36 -> V_28 . V_34 == V_34 ) &&
( V_36 -> V_69 == V_70 ) ) {
F_10 ( & V_6 -> V_38 ) ;
F_18 ( L_19 ,
V_28 -> V_22 , ( int ) V_6 ) ;
V_36 -> V_28 = * V_28 ;
return 0 ;
}
}
F_10 ( & V_6 -> V_38 ) ;
F_20 ( L_20 ) ;
return - V_7 ;
}
static struct V_71 * F_32 ( void )
{
struct V_71 * V_72 ;
V_72 = F_33 ( sizeof( * V_72 ) , V_18 ) ;
if ( ! V_72 )
return F_21 ( - V_73 ) ;
F_34 ( (struct V_74 * ) V_72 , V_75 ) ;
return V_72 ;
}
static struct V_76 * F_35 ( void )
{
struct V_76 * V_77 ;
V_77 = F_33 ( sizeof( * V_77 ) , V_18 ) ;
if ( ! V_77 )
return F_21 ( - V_73 ) ;
F_34 ( (struct V_74 * ) V_77 , V_78 ) ;
return V_77 ;
}
int F_36 ( struct V_39 * V_40 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_50 * V_24 = V_48 -> V_24 ;
struct V_25 * V_26 = F_29 ( V_24 ) ;
struct V_27 * V_28 = V_41 ;
struct V_5 * V_6 ;
struct V_35 * V_36 ;
int V_17 , V_79 ;
if ( ! V_26 ) {
F_20 ( L_12 ) ;
return - V_7 ;
}
if ( ! V_28 ) {
F_20 ( L_13 ) ;
return - V_7 ;
}
F_37 (i)
F_30 ( V_28 , V_79 ) ;
if ( V_28 -> V_34 ) {
F_18 ( L_10 , V_28 -> V_34 ) ;
return F_31 ( V_28 ) ;
}
V_6 = F_25 ( V_26 , V_28 ) ;
if ( F_3 ( V_6 ) ) {
F_20 ( L_18 ) ;
return - V_7 ;
}
V_36 = F_33 ( sizeof( * V_36 ) , V_18 ) ;
if ( ! V_36 )
return - V_73 ;
V_17 = F_13 ( & V_26 -> V_80 , & V_26 -> V_81 , V_36 ,
& V_28 -> V_34 ) ;
if ( V_17 ) {
F_20 ( L_21 ) ;
goto V_82;
}
F_18 ( L_22 ,
V_28 -> V_34 , V_28 -> V_22 , ( int ) V_6 ) ;
V_36 -> V_48 = V_48 ;
V_36 -> V_28 = * V_28 ;
V_36 -> V_69 = V_83 ;
V_36 -> V_84 = F_32 () ;
if ( F_3 ( V_36 -> V_84 ) ) {
F_20 ( L_23 ) ;
goto V_85;
}
V_36 -> V_86 = F_32 () ;
if ( F_3 ( V_36 -> V_86 ) ) {
F_20 ( L_24 ) ;
goto V_87;
}
V_36 -> V_77 = F_35 () ;
if ( F_3 ( V_36 -> V_77 ) ) {
F_20 ( L_25 ) ;
goto V_88;
}
F_38 ( & V_36 -> V_14 ) ;
F_38 ( & V_36 -> V_89 ) ;
F_38 ( & V_36 -> V_90 ) ;
F_39 ( & V_36 -> V_91 ) ;
F_39 ( & V_36 -> V_92 ) ;
F_37 (i)
F_40 ( & V_36 -> V_93 [ V_79 ] ) ;
F_40 ( & V_36 -> V_94 ) ;
F_41 ( & V_48 -> V_94 , & V_36 -> V_94 ) ;
F_8 ( & V_6 -> V_38 ) ;
F_9 ( & V_36 -> V_95 , & V_6 -> V_96 ) ;
F_10 ( & V_6 -> V_38 ) ;
if ( ! F_23 ( V_28 -> V_22 ) )
V_6 -> V_23 = true ;
return 0 ;
V_88:
F_42 ( V_36 -> V_86 ) ;
V_87:
F_42 ( V_36 -> V_84 ) ;
V_85:
F_15 ( & V_26 -> V_80 , & V_26 -> V_81 , V_28 -> V_34 ) ;
V_82:
F_42 ( V_36 ) ;
return V_17 ;
}
static void F_43 ( struct V_25 * V_26 ,
struct V_35 * V_36 )
{
F_12 ( & V_36 -> V_95 ) ;
F_15 ( & V_26 -> V_80 , & V_26 -> V_81 ,
V_36 -> V_28 . V_34 ) ;
F_44 ( & V_36 -> V_14 ) ;
F_44 ( & V_36 -> V_89 ) ;
F_44 ( & V_36 -> V_90 ) ;
F_42 ( V_36 -> V_84 ) ;
F_42 ( V_36 -> V_86 ) ;
F_42 ( V_36 -> V_77 ) ;
F_42 ( V_36 ) ;
}
static int F_45 ( struct V_35 * V_36 )
{
struct V_27 * V_28 = & V_36 -> V_28 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
int V_17 , V_79 , V_37 [ V_101 ] = { 0 , } ;
F_37 (i) {
V_100 = & V_36 -> V_93 [ V_79 ] ;
F_26 (m_node, head, list) {
F_18 ( L_26 ,
V_79 ? L_15 : L_16 , V_37 [ V_79 ] , ( int ) V_98 ) ;
V_37 [ V_79 ] ++ ;
}
}
F_18 ( L_27 ,
F_46 ( V_37 [ V_102 ] , V_37 [ V_103 ] ) ,
F_47 ( V_37 [ V_102 ] , V_37 [ V_103 ] ) ) ;
if ( F_23 ( V_28 -> V_22 ) )
V_17 = F_46 ( V_37 [ V_102 ] ,
V_37 [ V_103 ] ) ;
else
V_17 = F_47 ( V_37 [ V_102 ] ,
V_37 [ V_103 ] ) ;
return V_17 ;
}
static struct V_97
* F_48 ( struct V_35 * V_36 ,
struct V_104 * V_105 )
{
struct V_97 * V_98 ;
struct V_99 * V_100 ;
int V_37 = 0 ;
F_18 ( L_28 , V_105 -> V_106 ) ;
V_100 = & V_36 -> V_93 [ V_105 -> V_107 ] ;
F_26 (m_node, head, list) {
F_18 ( L_29 , V_37 ++ , ( int ) V_98 ) ;
if ( V_98 -> V_106 == V_105 -> V_106 )
return V_98 ;
}
return NULL ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_35 * V_36 ,
struct V_97 * V_98 )
{
struct V_108 * V_109 = NULL ;
int V_17 = 0 ;
F_18 ( L_30 , ( int ) V_98 ) ;
if ( ! V_98 ) {
F_20 ( L_31 ) ;
return - V_110 ;
}
F_18 ( L_32 , V_98 -> V_107 ) ;
V_109 = V_6 -> V_109 [ V_98 -> V_107 ] ;
if ( ! V_109 ) {
F_20 ( L_33 ) ;
return - V_110 ;
}
if ( V_109 -> V_111 ) {
V_17 = V_109 -> V_111 ( V_6 -> V_24 , & V_98 -> V_112 ,
V_98 -> V_106 , V_113 ) ;
if ( V_17 ) {
F_20 ( L_34 ) ;
return V_17 ;
}
}
return V_17 ;
}
static struct V_97
* F_50 ( struct V_39 * V_40 ,
struct V_42 * V_43 ,
struct V_35 * V_36 ,
struct V_104 * V_105 )
{
struct V_97 * V_98 ;
struct V_114 V_112 ;
void * V_115 ;
int V_79 ;
V_98 = F_33 ( sizeof( * V_98 ) , V_18 ) ;
if ( ! V_98 )
return F_21 ( - V_73 ) ;
memset ( & V_112 , 0x0 , sizeof( V_112 ) ) ;
V_98 -> V_107 = V_105 -> V_107 ;
V_98 -> V_34 = V_105 -> V_34 ;
V_98 -> V_106 = V_105 -> V_106 ;
F_18 ( L_35 , ( int ) V_98 , V_105 -> V_107 ) ;
F_18 ( L_36 , V_105 -> V_34 , V_98 -> V_106 ) ;
F_51 (i) {
F_18 ( L_37 , V_79 , V_105 -> V_116 [ V_79 ] ) ;
if ( V_105 -> V_116 [ V_79 ] ) {
V_115 = F_52 ( V_40 ,
V_105 -> V_116 [ V_79 ] , V_43 ) ;
if ( F_3 ( V_115 ) ) {
F_20 ( L_38 ) ;
goto V_82;
}
V_112 . V_117 [ V_79 ] = V_105 -> V_116 [ V_79 ] ;
V_112 . V_118 [ V_79 ] = * ( V_119 * ) V_115 ;
F_18 ( L_39 ,
V_79 , V_112 . V_118 [ V_79 ] , ( int ) V_112 . V_117 [ V_79 ] ) ;
}
}
V_98 -> V_120 = V_43 ;
V_98 -> V_112 = V_112 ;
F_8 ( & V_36 -> V_89 ) ;
F_9 ( & V_98 -> V_95 , & V_36 -> V_93 [ V_105 -> V_107 ] ) ;
F_10 ( & V_36 -> V_89 ) ;
return V_98 ;
V_82:
F_42 ( V_98 ) ;
return F_21 ( - V_110 ) ;
}
static int F_53 ( struct V_39 * V_40 ,
struct V_35 * V_36 ,
struct V_97 * V_98 )
{
int V_79 ;
F_18 ( L_30 , ( int ) V_98 ) ;
if ( ! V_98 ) {
F_20 ( L_40 ) ;
return - V_110 ;
}
F_18 ( L_32 , V_98 -> V_107 ) ;
F_51 (i) {
unsigned long V_116 = V_98 -> V_112 . V_117 [ V_79 ] ;
if ( V_116 )
F_54 ( V_40 , V_116 ,
V_98 -> V_120 ) ;
}
F_12 ( & V_98 -> V_95 ) ;
F_42 ( V_98 ) ;
return 0 ;
}
static void F_55 ( struct V_121 * V_122 )
{
F_42 ( V_122 ) ;
}
static int F_56 ( struct V_39 * V_40 ,
struct V_42 * V_43 ,
struct V_35 * V_36 ,
struct V_104 * V_105 )
{
struct V_123 * V_124 ;
unsigned long V_125 ;
F_18 ( L_41 , V_105 -> V_107 , V_105 -> V_106 ) ;
V_124 = F_33 ( sizeof( * V_124 ) , V_18 ) ;
if ( ! V_124 ) {
F_57 ( & V_40 -> V_90 , V_125 ) ;
V_43 -> V_126 += sizeof( V_124 -> V_122 ) ;
F_58 ( & V_40 -> V_90 , V_125 ) ;
return - V_73 ;
}
V_124 -> V_122 . V_118 . type = V_127 ;
V_124 -> V_122 . V_118 . V_128 = sizeof( V_124 -> V_122 ) ;
V_124 -> V_122 . V_129 = V_105 -> V_129 ;
V_124 -> V_122 . V_34 = V_105 -> V_34 ;
V_124 -> V_122 . V_106 [ V_103 ] = V_105 -> V_106 ;
V_124 -> V_118 . V_122 = & V_124 -> V_122 . V_118 ;
V_124 -> V_118 . V_45 = V_43 ;
V_124 -> V_118 . V_130 = F_55 ;
F_8 ( & V_36 -> V_90 ) ;
F_9 ( & V_124 -> V_118 . V_131 , & V_36 -> V_94 ) ;
F_10 ( & V_36 -> V_90 ) ;
return 0 ;
}
static void F_59 ( struct V_35 * V_36 ,
struct V_104 * V_105 )
{
struct V_123 * V_124 , * V_132 ;
int V_37 = 0 ;
F_8 ( & V_36 -> V_90 ) ;
F_60 (e, te, &c_node->event_list, base.link) {
F_18 ( L_42 , V_37 ++ , ( int ) V_124 ) ;
if ( ! V_105 ) {
F_12 ( & V_124 -> V_118 . V_131 ) ;
F_42 ( V_124 ) ;
}
if ( V_105 && ( V_105 -> V_106 ==
V_124 -> V_122 . V_106 [ V_103 ] ) ) {
F_12 ( & V_124 -> V_118 . V_131 ) ;
F_42 ( V_124 ) ;
goto V_133;
}
}
V_133:
F_10 ( & V_36 -> V_90 ) ;
return;
}
static void F_61 ( struct V_50 * V_24 ,
struct V_5 * V_6 ,
struct V_71 * V_72 ,
struct V_35 * V_36 )
{
struct V_25 * V_26 = F_29 ( V_24 ) ;
V_72 -> V_6 = V_6 ;
V_72 -> V_36 = V_36 ;
F_62 ( V_26 -> V_134 , (struct V_74 * ) V_72 ) ;
}
static int F_63 ( struct V_50 * V_24 ,
struct V_35 * V_36 ,
struct V_97 * V_98 ,
struct V_104 * V_105 )
{
struct V_5 * V_6 ;
struct V_27 * V_28 ;
struct V_108 * V_109 ;
int V_17 ;
V_6 = F_27 ( V_105 -> V_34 ) ;
if ( F_3 ( V_6 ) ) {
F_20 ( L_18 ) ;
return - V_110 ;
}
V_109 = V_6 -> V_109 [ V_105 -> V_107 ] ;
if ( ! V_109 ) {
F_20 ( L_43 ) ;
return - V_110 ;
}
V_28 = & V_36 -> V_28 ;
if ( V_36 -> V_69 != V_135 ) {
F_18 ( L_44 ) ;
return 0 ;
}
F_8 ( & V_36 -> V_89 ) ;
if ( ! F_45 ( V_36 ) ) {
F_10 ( & V_36 -> V_89 ) ;
F_18 ( L_45 ) ;
return 0 ;
}
if ( F_23 ( V_28 -> V_22 ) ) {
struct V_71 * V_72 = V_36 -> V_84 ;
V_72 -> V_136 = V_137 ;
F_61 ( V_24 , V_6 , V_72 , V_36 ) ;
} else {
V_17 = F_49 ( V_6 , V_36 , V_98 ) ;
if ( V_17 ) {
F_10 ( & V_36 -> V_89 ) ;
F_20 ( L_46 ) ;
return V_17 ;
}
}
F_10 ( & V_36 -> V_89 ) ;
return 0 ;
}
static void F_64 ( struct V_39 * V_40 ,
struct V_35 * V_36 ,
struct V_104 * V_105 )
{
struct V_97 * V_98 , * V_138 ;
F_8 ( & V_36 -> V_89 ) ;
F_60 (m_node, tm_node,
&c_node->mem_list[qbuf->ops_id], list) {
if ( V_98 -> V_106 == V_105 -> V_106 &&
V_98 -> V_107 == V_105 -> V_107 )
F_53 ( V_40 , V_36 , V_98 ) ;
}
F_10 ( & V_36 -> V_89 ) ;
}
int F_65 ( struct V_39 * V_40 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_50 * V_24 = V_48 -> V_24 ;
struct V_25 * V_26 = F_29 ( V_24 ) ;
struct V_104 * V_105 = V_41 ;
struct V_35 * V_36 ;
struct V_97 * V_98 ;
int V_17 ;
if ( ! V_105 ) {
F_20 ( L_47 ) ;
return - V_7 ;
}
if ( V_105 -> V_107 >= V_101 ) {
F_20 ( L_48 ) ;
return - V_7 ;
}
F_18 ( L_49 ,
V_105 -> V_34 , V_105 -> V_107 ? L_15 : L_16 ,
V_105 -> V_106 , V_105 -> V_139 ) ;
V_36 = F_17 ( & V_26 -> V_80 , & V_26 -> V_81 ,
V_105 -> V_34 ) ;
if ( F_3 ( V_36 ) ) {
F_20 ( L_50 ) ;
return F_4 ( V_36 ) ;
}
switch ( V_105 -> V_139 ) {
case V_113 :
V_98 = F_50 ( V_40 , V_43 , V_36 , V_105 ) ;
if ( F_3 ( V_98 ) ) {
F_20 ( L_51 ) ;
return F_4 ( V_98 ) ;
}
if ( V_105 -> V_107 == V_103 ) {
V_17 = F_56 ( V_40 , V_43 , V_36 , V_105 ) ;
if ( V_17 ) {
F_20 ( L_52 ) ;
goto V_140;
}
V_17 = F_63 ( V_24 , V_36 , V_98 , V_105 ) ;
if ( V_17 ) {
F_20 ( L_53 ) ;
goto V_140;
}
}
break;
case V_141 :
F_8 ( & V_36 -> V_14 ) ;
if ( V_105 -> V_107 == V_103 )
F_59 ( V_36 , V_105 ) ;
F_64 ( V_40 , V_36 , V_105 ) ;
F_10 ( & V_36 -> V_14 ) ;
break;
default:
F_20 ( L_54 ) ;
return - V_7 ;
}
return 0 ;
V_140:
F_20 ( L_55 ) ;
F_64 ( V_40 , V_36 , V_105 ) ;
return V_17 ;
}
static bool F_66 ( struct V_50 * V_24 ,
enum V_142 V_136 , enum V_143 V_69 )
{
if ( V_136 != V_137 ) {
if ( F_24 ( V_24 ) ) {
F_20 ( L_56 ) ;
goto V_144;
}
}
switch ( V_136 ) {
case V_137 :
if ( V_69 != V_83 )
goto V_144;
break;
case V_145 :
if ( V_69 == V_70 )
goto V_144;
break;
case V_146 :
if ( V_69 != V_135 )
goto V_144;
break;
case V_147 :
if ( V_69 != V_70 )
goto V_144;
break;
default:
F_20 ( L_57 ) ;
goto V_144;
}
return true ;
V_144:
F_20 ( L_58 , V_136 , V_69 ) ;
return false ;
}
int F_67 ( struct V_39 * V_40 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_5 * V_6 = NULL ;
struct V_50 * V_24 = V_48 -> V_24 ;
struct V_25 * V_26 = F_29 ( V_24 ) ;
struct V_148 * V_149 = V_41 ;
struct V_71 * V_72 ;
struct V_35 * V_36 ;
if ( ! V_26 ) {
F_20 ( L_12 ) ;
return - V_7 ;
}
if ( ! V_149 ) {
F_20 ( L_59 ) ;
return - V_7 ;
}
F_18 ( L_60 ,
V_149 -> V_136 , V_149 -> V_34 ) ;
V_6 = F_27 ( V_149 -> V_34 ) ;
if ( F_3 ( V_6 ) ) {
F_20 ( L_18 ) ;
return F_4 ( V_6 ) ;
}
V_36 = F_17 ( & V_26 -> V_80 , & V_26 -> V_81 ,
V_149 -> V_34 ) ;
if ( F_3 ( V_36 ) ) {
F_20 ( L_61 ) ;
return F_4 ( V_36 ) ;
}
if ( ! F_66 ( V_6 -> V_24 , V_149 -> V_136 ,
V_36 -> V_69 ) ) {
F_20 ( L_57 ) ;
return - V_7 ;
}
switch ( V_149 -> V_136 ) {
case V_137 :
if ( F_24 ( V_6 -> V_24 ) )
F_68 ( V_6 -> V_24 ) ;
V_36 -> V_69 = V_135 ;
V_72 = V_36 -> V_84 ;
V_72 -> V_136 = V_149 -> V_136 ;
F_61 ( V_24 , V_6 , V_72 , V_36 ) ;
break;
case V_145 :
V_72 = V_36 -> V_86 ;
V_72 -> V_136 = V_149 -> V_136 ;
F_61 ( V_24 , V_6 , V_72 , V_36 ) ;
if ( ! F_69 ( & V_36 -> V_92 ,
F_70 ( 300 ) ) ) {
F_20 ( L_62 ,
V_36 -> V_28 . V_34 ) ;
}
V_36 -> V_69 = V_70 ;
V_6 -> V_23 = false ;
F_8 ( & V_6 -> V_38 ) ;
F_43 ( V_26 , V_36 ) ;
if ( F_71 ( & V_6 -> V_96 ) )
F_72 ( V_6 -> V_24 ) ;
F_10 ( & V_6 -> V_38 ) ;
break;
case V_146 :
V_72 = V_36 -> V_86 ;
V_72 -> V_136 = V_149 -> V_136 ;
F_61 ( V_24 , V_6 , V_72 , V_36 ) ;
if ( ! F_69 ( & V_36 -> V_92 ,
F_70 ( 200 ) ) ) {
F_20 ( L_62 ,
V_36 -> V_28 . V_34 ) ;
}
V_36 -> V_69 = V_70 ;
break;
case V_147 :
V_36 -> V_69 = V_135 ;
V_72 = V_36 -> V_84 ;
V_72 -> V_136 = V_149 -> V_136 ;
F_61 ( V_24 , V_6 , V_72 , V_36 ) ;
break;
default:
F_20 ( L_63 ) ;
return - V_7 ;
}
F_18 ( L_64 ,
V_149 -> V_136 , V_149 -> V_34 ) ;
return 0 ;
}
int F_73 ( struct V_150 * V_151 )
{
return F_74 (
& V_152 , V_151 ) ;
}
int F_75 ( struct V_150 * V_151 )
{
return F_76 (
& V_152 , V_151 ) ;
}
int F_77 ( unsigned long V_153 , void * V_154 )
{
return F_78 (
& V_152 , V_153 , V_154 ) ;
}
static int F_79 ( struct V_5 * V_6 ,
struct V_27 * V_28 )
{
struct V_108 * V_109 = NULL ;
bool V_155 = false ;
int V_17 , V_79 ;
if ( ! V_28 ) {
F_20 ( L_13 ) ;
return - V_7 ;
}
F_18 ( L_10 , V_28 -> V_34 ) ;
if ( V_6 -> V_156 &&
V_6 -> V_156 ( V_6 -> V_24 ) ) {
F_20 ( L_65 ) ;
return - V_7 ;
}
F_37 (i) {
struct V_54 * V_55 =
& V_28 -> V_55 [ V_79 ] ;
V_109 = V_6 -> V_109 [ V_79 ] ;
if ( ! V_109 || ! V_55 ) {
F_20 ( L_66 ) ;
return - V_7 ;
}
if ( V_109 -> V_157 ) {
V_17 = V_109 -> V_157 ( V_6 -> V_24 , V_55 -> V_60 ) ;
if ( V_17 ) {
F_20 ( L_67 ) ;
return V_17 ;
}
}
if ( V_109 -> V_158 ) {
V_17 = V_109 -> V_158 ( V_6 -> V_24 , V_55 -> V_68 ,
V_55 -> V_67 , & V_155 ) ;
if ( V_17 ) {
F_20 ( L_68 ) ;
return - V_7 ;
}
}
if ( V_109 -> V_159 ) {
V_17 = V_109 -> V_159 ( V_6 -> V_24 , V_155 , & V_55 -> V_57 ,
& V_55 -> V_59 ) ;
if ( V_17 ) {
F_20 ( L_69 ) ;
return V_17 ;
}
}
}
return 0 ;
}
static int F_80 ( struct V_5 * V_6 ,
struct V_35 * V_36 )
{
struct V_97 * V_98 ;
struct V_27 * V_28 = & V_36 -> V_28 ;
struct V_99 * V_100 ;
int V_17 , V_79 ;
F_18 ( L_10 , V_28 -> V_34 ) ;
V_6 -> V_36 = V_36 ;
F_8 ( & V_36 -> V_89 ) ;
if ( ! F_45 ( V_36 ) ) {
F_18 ( L_45 ) ;
V_17 = - V_73 ;
goto V_160;
}
V_17 = F_79 ( V_6 , V_28 ) ;
if ( V_17 ) {
F_20 ( L_70 ) ;
V_6 -> V_36 = NULL ;
goto V_160;
}
switch ( V_28 -> V_22 ) {
case V_161 :
F_37 (i) {
V_100 = & V_36 -> V_93 [ V_79 ] ;
V_98 = F_81 ( V_100 ,
struct V_97 , V_95 ) ;
if ( ! V_98 ) {
F_20 ( L_71 ) ;
V_17 = - V_110 ;
goto V_160;
}
F_18 ( L_72 , ( int ) V_98 ) ;
V_17 = F_49 ( V_6 , V_36 , V_98 ) ;
if ( V_17 ) {
F_20 ( L_46 ) ;
goto V_160;
}
}
break;
case V_162 :
V_100 = & V_36 -> V_93 [ V_103 ] ;
F_26 (m_node, head, list) {
V_17 = F_49 ( V_6 , V_36 , V_98 ) ;
if ( V_17 ) {
F_20 ( L_46 ) ;
goto V_160;
}
}
break;
case V_163 :
V_100 = & V_36 -> V_93 [ V_102 ] ;
F_26 (m_node, head, list) {
V_17 = F_49 ( V_6 , V_36 , V_98 ) ;
if ( V_17 ) {
F_20 ( L_46 ) ;
goto V_160;
}
}
break;
default:
F_20 ( L_73 ) ;
V_17 = - V_7 ;
goto V_160;
}
F_10 ( & V_36 -> V_89 ) ;
F_18 ( L_74 , V_28 -> V_22 ) ;
if ( V_6 -> V_164 ) {
V_17 = V_6 -> V_164 ( V_6 -> V_24 , V_28 -> V_22 ) ;
if ( V_17 ) {
F_20 ( L_75 ) ;
V_6 -> V_36 = NULL ;
return V_17 ;
}
}
return 0 ;
V_160:
F_10 ( & V_36 -> V_89 ) ;
V_6 -> V_36 = NULL ;
return V_17 ;
}
static int F_82 ( struct V_39 * V_40 ,
struct V_5 * V_6 ,
struct V_35 * V_36 )
{
struct V_97 * V_98 , * V_138 ;
struct V_27 * V_28 = & V_36 -> V_28 ;
struct V_99 * V_100 ;
int V_17 = 0 , V_79 ;
F_18 ( L_10 , V_28 -> V_34 ) ;
F_59 ( V_36 , NULL ) ;
F_8 ( & V_36 -> V_89 ) ;
switch ( V_28 -> V_22 ) {
case V_161 :
F_37 (i) {
V_100 = & V_36 -> V_93 [ V_79 ] ;
F_60 (m_node, tm_node,
head, list) {
V_17 = F_53 ( V_40 , V_36 ,
V_98 ) ;
if ( V_17 ) {
F_20 ( L_76 ) ;
goto V_82;
}
}
}
break;
case V_162 :
V_100 = & V_36 -> V_93 [ V_103 ] ;
F_60 (m_node, tm_node, head, list) {
V_17 = F_53 ( V_40 , V_36 , V_98 ) ;
if ( V_17 ) {
F_20 ( L_76 ) ;
goto V_82;
}
}
break;
case V_163 :
V_100 = & V_36 -> V_93 [ V_102 ] ;
F_60 (m_node, tm_node, head, list) {
V_17 = F_53 ( V_40 , V_36 , V_98 ) ;
if ( V_17 ) {
F_20 ( L_76 ) ;
goto V_82;
}
}
break;
default:
F_20 ( L_73 ) ;
V_17 = - V_7 ;
goto V_82;
}
V_82:
F_10 ( & V_36 -> V_89 ) ;
if ( V_6 -> V_165 )
V_6 -> V_165 ( V_6 -> V_24 , V_28 -> V_22 ) ;
return V_17 ;
}
void V_75 ( struct V_74 * V_166 )
{
struct V_71 * V_72 =
(struct V_71 * ) V_166 ;
struct V_5 * V_6 ;
struct V_35 * V_36 ;
struct V_27 * V_28 ;
int V_17 ;
V_6 = V_72 -> V_6 ;
if ( ! V_6 ) {
F_20 ( L_77 ) ;
return;
}
V_36 = V_72 -> V_36 ;
if ( ! V_36 ) {
F_20 ( L_61 ) ;
return;
}
F_8 ( & V_36 -> V_14 ) ;
V_28 = & V_36 -> V_28 ;
switch ( V_72 -> V_136 ) {
case V_137 :
case V_147 :
V_17 = F_80 ( V_6 , V_36 ) ;
if ( V_17 ) {
F_20 ( L_78 ,
V_36 -> V_28 . V_34 ) ;
goto V_160;
}
if ( F_23 ( V_28 -> V_22 ) ) {
if ( ! F_69
( & V_36 -> V_91 , F_70 ( 200 ) ) ) {
F_20 ( L_79 ,
V_36 -> V_28 . V_34 ) ;
goto V_160;
}
}
break;
case V_145 :
case V_146 :
V_17 = F_82 ( V_6 -> V_40 , V_6 ,
V_36 ) ;
if ( V_17 ) {
F_20 ( L_80 ) ;
goto V_160;
}
F_83 ( & V_36 -> V_92 ) ;
break;
default:
F_20 ( L_81 ) ;
break;
}
F_18 ( L_82 , V_72 -> V_136 ) ;
V_160:
F_10 ( & V_36 -> V_14 ) ;
}
static int F_84 ( struct V_5 * V_6 ,
struct V_35 * V_36 , int * V_106 )
{
struct V_39 * V_40 = V_6 -> V_40 ;
struct V_27 * V_28 = & V_36 -> V_28 ;
struct V_97 * V_98 ;
struct V_104 V_105 ;
struct V_123 * V_124 ;
struct V_99 * V_100 ;
struct V_167 V_168 ;
unsigned long V_125 ;
T_1 V_169 [ V_101 ] = { 0 , } ;
int V_17 , V_79 ;
F_37 (i)
F_18 ( L_83 , V_79 ? L_15 : L_16 , V_106 [ V_79 ] ) ;
if ( ! V_40 ) {
F_20 ( L_84 ) ;
return - V_7 ;
}
if ( ! V_28 ) {
F_20 ( L_85 ) ;
return - V_7 ;
}
F_8 ( & V_36 -> V_90 ) ;
if ( F_71 ( & V_36 -> V_94 ) ) {
F_18 ( L_86 ) ;
V_17 = 0 ;
goto V_170;
}
F_8 ( & V_36 -> V_89 ) ;
if ( ! F_45 ( V_36 ) ) {
F_18 ( L_45 ) ;
V_17 = 0 ;
goto V_171;
}
switch ( V_28 -> V_22 ) {
case V_161 :
F_37 (i) {
V_100 = & V_36 -> V_93 [ V_79 ] ;
V_98 = F_81 ( V_100 ,
struct V_97 , V_95 ) ;
if ( ! V_98 ) {
F_20 ( L_87 ) ;
V_17 = - V_73 ;
goto V_171;
}
V_169 [ V_79 ] = V_98 -> V_106 ;
F_18 ( L_83 ,
V_79 ? L_15 : L_16 , V_169 [ V_79 ] ) ;
V_17 = F_53 ( V_40 , V_36 , V_98 ) ;
if ( V_17 )
F_20 ( L_76 ) ;
}
break;
case V_162 :
memset ( & V_105 , 0x0 , sizeof( V_105 ) ) ;
V_105 . V_107 = V_103 ;
V_105 . V_106 = V_106 [ V_103 ] ;
V_98 = F_48 ( V_36 , & V_105 ) ;
if ( ! V_98 ) {
F_20 ( L_87 ) ;
V_17 = - V_73 ;
goto V_171;
}
V_169 [ V_103 ] = V_98 -> V_106 ;
V_17 = F_53 ( V_40 , V_36 , V_98 ) ;
if ( V_17 )
F_20 ( L_76 ) ;
break;
case V_163 :
V_100 = & V_36 -> V_93 [ V_102 ] ;
V_98 = F_81 ( V_100 ,
struct V_97 , V_95 ) ;
if ( ! V_98 ) {
F_20 ( L_87 ) ;
V_17 = - V_73 ;
goto V_171;
}
V_169 [ V_102 ] = V_98 -> V_106 ;
V_17 = F_53 ( V_40 , V_36 , V_98 ) ;
if ( V_17 )
F_20 ( L_76 ) ;
break;
default:
F_20 ( L_73 ) ;
V_17 = - V_7 ;
goto V_171;
}
F_10 ( & V_36 -> V_89 ) ;
if ( V_169 [ V_103 ] != V_106 [ V_103 ] )
F_20 ( L_88 ,
V_169 [ 1 ] , V_106 [ 1 ] , V_28 -> V_34 ) ;
V_124 = F_81 ( & V_36 -> V_94 ,
struct V_123 , V_118 . V_131 ) ;
F_85 ( & V_168 ) ;
F_18 ( L_89 , V_168 . V_172 , V_168 . V_173 ) ;
V_124 -> V_122 . V_172 = V_168 . V_172 ;
V_124 -> V_122 . V_173 = V_168 . V_173 ;
V_124 -> V_122 . V_34 = V_28 -> V_34 ;
F_37 (i)
V_124 -> V_122 . V_106 [ V_79 ] = V_169 [ V_79 ] ;
F_57 ( & V_40 -> V_90 , V_125 ) ;
F_86 ( & V_124 -> V_118 . V_131 , & V_124 -> V_118 . V_45 -> V_94 ) ;
F_87 ( & V_124 -> V_118 . V_45 -> V_174 ) ;
F_58 ( & V_40 -> V_90 , V_125 ) ;
F_10 ( & V_36 -> V_90 ) ;
F_18 ( L_90 ,
V_28 -> V_22 , V_28 -> V_34 , V_169 [ V_103 ] ) ;
return 0 ;
V_171:
F_10 ( & V_36 -> V_89 ) ;
V_170:
F_10 ( & V_36 -> V_90 ) ;
return V_17 ;
}
void V_78 ( struct V_74 * V_166 )
{
struct V_76 * V_77 =
(struct V_76 * ) V_166 ;
struct V_5 * V_6 ;
struct V_35 * V_36 ;
int V_17 ;
if ( ! V_77 ) {
F_20 ( L_91 ) ;
return;
}
F_18 ( L_28 , V_77 -> V_106 [ V_103 ] ) ;
V_6 = V_77 -> V_6 ;
if ( ! V_6 ) {
F_20 ( L_18 ) ;
return;
}
V_36 = V_6 -> V_36 ;
if ( ! V_36 ) {
F_20 ( L_50 ) ;
return;
}
if ( V_36 -> V_69 != V_135 ) {
F_18 ( L_92 ,
V_36 -> V_69 , V_36 -> V_28 . V_34 ) ;
goto V_175;
}
V_17 = F_84 ( V_6 , V_36 , V_77 -> V_106 ) ;
if ( V_17 ) {
F_20 ( L_93 ) ;
goto V_175;
}
V_175:
if ( F_23 ( V_36 -> V_28 . V_22 ) )
F_83 ( & V_36 -> V_91 ) ;
}
static int F_88 ( struct V_39 * V_40 , struct V_50 * V_24 )
{
struct V_25 * V_26 = F_29 ( V_24 ) ;
struct V_5 * V_6 ;
int V_17 , V_37 = 0 ;
F_26 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
T_1 V_29 ;
V_6 -> V_40 = V_40 ;
V_17 = F_13 ( & V_26 -> V_30 , & V_26 -> V_31 , V_6 ,
& V_29 ) ;
if ( V_17 || V_29 == 0 ) {
F_20 ( L_21 ) ;
goto V_176;
}
F_18 ( L_94 ,
V_37 ++ , ( int ) V_6 , V_29 ) ;
V_6 -> V_52 . V_29 = V_29 ;
V_6 -> V_177 = V_24 ;
V_6 -> V_178 = V_26 -> V_178 ;
V_6 -> V_179 = V_78 ;
F_40 ( & V_6 -> V_96 ) ;
F_38 ( & V_6 -> V_38 ) ;
if ( F_89 ( V_40 ) ) {
V_17 = F_90 ( V_40 , V_6 -> V_24 ) ;
if ( V_17 ) {
F_20 ( L_95 ) ;
goto V_176;
}
}
}
return 0 ;
V_176:
F_91 (ippdrv, &exynos_drm_ippdrv_list,
drv_list) {
if ( F_89 ( V_40 ) )
F_92 ( V_40 , V_6 -> V_24 ) ;
F_15 ( & V_26 -> V_30 , & V_26 -> V_31 ,
V_6 -> V_52 . V_29 ) ;
}
return V_17 ;
}
static void F_93 ( struct V_39 * V_40 , struct V_50 * V_24 )
{
struct V_5 * V_6 ;
struct V_25 * V_26 = F_29 ( V_24 ) ;
F_26 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
if ( F_89 ( V_40 ) )
F_92 ( V_40 , V_6 -> V_24 ) ;
F_15 ( & V_26 -> V_30 , & V_26 -> V_31 ,
V_6 -> V_52 . V_29 ) ;
V_6 -> V_40 = NULL ;
F_11 ( V_6 ) ;
}
}
static int F_94 ( struct V_39 * V_40 , struct V_50 * V_24 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 ;
V_48 = F_33 ( sizeof( * V_48 ) , V_18 ) ;
if ( ! V_48 )
return - V_73 ;
V_48 -> V_24 = V_24 ;
V_45 -> V_49 = V_48 ;
F_40 ( & V_48 -> V_94 ) ;
F_18 ( L_96 , ( int ) V_48 ) ;
return 0 ;
}
static void F_95 ( struct V_39 * V_40 , struct V_50 * V_24 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_5 * V_6 = NULL ;
struct V_25 * V_26 = F_29 ( V_24 ) ;
struct V_35 * V_36 , * V_180 ;
int V_37 = 0 ;
F_18 ( L_97 , ( int ) V_48 ) ;
F_26 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
F_8 ( & V_6 -> V_38 ) ;
F_60 (c_node, tc_node,
&ippdrv->cmd_list, list) {
F_18 ( L_11 ,
V_37 ++ , ( int ) V_6 ) ;
if ( V_36 -> V_48 == V_48 ) {
if ( V_36 -> V_69 == V_135 ) {
F_82 ( V_40 , V_6 ,
V_36 ) ;
V_36 -> V_69 = V_70 ;
}
V_6 -> V_23 = false ;
F_43 ( V_26 , V_36 ) ;
if ( F_71 ( & V_6 -> V_96 ) )
F_72 ( V_6 -> V_24 ) ;
}
}
F_10 ( & V_6 -> V_38 ) ;
}
F_42 ( V_48 ) ;
return;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_50 * V_24 = & V_2 -> V_24 ;
struct V_25 * V_26 ;
struct V_181 * V_182 ;
int V_17 ;
V_26 = F_97 ( V_24 , sizeof( * V_26 ) , V_18 ) ;
if ( ! V_26 )
return - V_73 ;
F_38 ( & V_26 -> V_31 ) ;
F_38 ( & V_26 -> V_81 ) ;
F_98 ( & V_26 -> V_30 ) ;
F_98 ( & V_26 -> V_80 ) ;
V_26 -> V_178 = F_99 ( L_98 ) ;
if ( ! V_26 -> V_178 ) {
F_100 ( V_24 , L_99 ) ;
return - V_7 ;
}
V_26 -> V_134 = F_99 ( L_100 ) ;
if ( ! V_26 -> V_134 ) {
F_100 ( V_24 , L_101 ) ;
V_17 = - V_7 ;
goto V_183;
}
V_182 = & V_26 -> V_182 ;
V_182 -> V_24 = V_24 ;
V_182 -> V_184 = F_88 ;
V_182 -> remove = F_93 ;
V_182 -> V_185 = F_94 ;
V_182 -> V_186 = F_95 ;
F_101 ( V_2 , V_26 ) ;
V_17 = F_102 ( V_182 ) ;
if ( V_17 < 0 ) {
F_20 ( L_102 ) ;
goto V_187;
}
F_103 ( V_24 , L_103 ) ;
return 0 ;
V_187:
F_104 ( V_26 -> V_134 ) ;
V_183:
F_104 ( V_26 -> V_178 ) ;
return V_17 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_106 ( V_2 ) ;
F_107 ( & V_26 -> V_182 ) ;
F_108 ( & V_26 -> V_30 ) ;
F_108 ( & V_26 -> V_80 ) ;
F_44 ( & V_26 -> V_31 ) ;
F_44 ( & V_26 -> V_81 ) ;
F_104 ( V_26 -> V_134 ) ;
F_104 ( V_26 -> V_178 ) ;
return 0 ;
}
static int F_109 ( struct V_25 * V_26 , bool V_188 )
{
F_18 ( L_104 , V_188 ) ;
return 0 ;
}
static int F_110 ( struct V_50 * V_24 )
{
struct V_25 * V_26 = F_29 ( V_24 ) ;
if ( F_24 ( V_24 ) )
return 0 ;
return F_109 ( V_26 , false ) ;
}
static int F_111 ( struct V_50 * V_24 )
{
struct V_25 * V_26 = F_29 ( V_24 ) ;
if ( ! F_24 ( V_24 ) )
return F_109 ( V_26 , true ) ;
return 0 ;
}
static int F_112 ( struct V_50 * V_24 )
{
struct V_25 * V_26 = F_29 ( V_24 ) ;
return F_109 ( V_26 , false ) ;
}
static int F_113 ( struct V_50 * V_24 )
{
struct V_25 * V_26 = F_29 ( V_24 ) ;
return F_109 ( V_26 , true ) ;
}
