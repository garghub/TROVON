static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
int V_7 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
F_3 ( & V_5 -> V_10 ) ;
F_4 ( V_2 -> V_2 , V_2 ) ;
V_2 -> V_11 = ( void * ) V_5 ;
V_6 = F_5 ( V_2 ) ;
if ( V_6 < 0 ) {
F_6 ( L_1 ) ;
goto V_12;
}
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ ) {
struct V_14 * V_15 ;
unsigned long V_16 = ( 1 << V_17 ) - 1 ;
V_15 = F_9 ( V_2 , V_16 ,
V_18 ) ;
if ( ! F_10 ( V_15 ) )
continue;
V_6 = F_11 ( V_15 ) ;
goto V_19;
}
F_12 ( V_2 ) ;
F_13 ( V_2 -> V_20 , V_2 ) ;
V_6 = F_14 ( V_2 -> V_2 , V_2 ) ;
if ( V_6 )
goto V_19;
V_6 = F_15 ( V_2 , V_2 -> V_21 . V_22 ) ;
if ( V_6 )
goto V_23;
V_6 = F_16 ( V_2 ) ;
if ( V_6 )
goto V_24;
V_2 -> V_25 = true ;
V_2 -> V_26 = true ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
return 0 ;
V_24:
F_19 ( V_2 ) ;
V_23:
F_20 ( V_2 -> V_2 , V_2 ) ;
V_19:
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
V_12:
F_23 ( V_5 ) ;
return V_6 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_2 , V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_27 )
{
struct V_28 * V_29 ;
F_29 ( V_2 ) ;
F_30 (connector, &dev->mode_config.connector_list, head) {
int V_30 = V_29 -> V_31 ;
if ( V_29 -> V_32 -> V_31 )
V_29 -> V_32 -> V_31 ( V_29 , V_33 ) ;
V_29 -> V_31 = V_30 ;
}
F_31 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
F_29 ( V_2 ) ;
F_30 (connector, &dev->mode_config.connector_list, head) {
if ( V_29 -> V_32 -> V_31 ) {
int V_31 = V_29 -> V_31 ;
V_29 -> V_31 = V_33 ;
V_29 -> V_32 -> V_31 ( V_29 , V_31 ) ;
}
}
F_31 ( V_2 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_36 * V_37 ;
int V_6 ;
V_37 = F_2 ( sizeof( * V_37 ) , V_8 ) ;
if ( ! V_37 )
return - V_9 ;
V_35 -> V_38 = V_37 ;
V_6 = F_35 ( V_2 , V_35 ) ;
if ( V_6 )
goto V_39;
return V_6 ;
V_39:
F_23 ( V_37 ) ;
V_35 -> V_38 = NULL ;
return V_6 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
F_37 ( V_2 , V_35 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_40 * V_41 , * V_42 ;
struct V_43 * V_44 , * V_45 ;
unsigned long V_3 ;
if ( ! V_35 -> V_38 )
return;
F_39 ( & V_2 -> V_46 , V_3 ) ;
F_40 (v, vt, &private->pageflip_event_list,
base.link) {
if ( V_41 -> V_47 . V_37 == V_35 ) {
F_41 ( & V_41 -> V_47 . V_48 ) ;
F_42 ( V_2 , V_41 -> V_49 ) ;
V_41 -> V_47 . V_50 ( & V_41 -> V_47 ) ;
}
}
F_40 (e, et, &file->event_list, link) {
F_41 ( & V_44 -> V_48 ) ;
V_44 -> V_50 ( V_44 ) ;
}
F_43 ( & V_2 -> V_46 , V_3 ) ;
F_23 ( V_35 -> V_38 ) ;
V_35 -> V_38 = NULL ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
}
static int F_46 ( struct V_51 * V_2 )
{
struct V_1 * V_52 = F_47 ( V_2 ) ;
T_1 V_53 ;
if ( F_48 ( V_2 ) || ! V_52 )
return 0 ;
V_53 . V_54 = V_55 ;
return F_28 ( V_52 , V_53 ) ;
}
static int F_49 ( struct V_51 * V_2 )
{
struct V_1 * V_52 = F_47 ( V_2 ) ;
if ( F_48 ( V_2 ) || ! V_52 )
return 0 ;
return F_32 ( V_52 ) ;
}
int F_50 ( struct V_51 * V_2 ,
enum V_56 V_57 ,
enum V_58 V_59 )
{
struct V_60 * V_61 ;
if ( V_57 != V_62 &&
V_57 != V_63 ) {
F_6 ( L_2 ) ;
return - V_64 ;
}
F_51 ( & V_65 ) ;
F_30 (cdev, &drm_component_list, list) {
if ( V_61 -> V_59 == V_59 ) {
if ( V_61 -> V_66 == ( V_62 |
V_63 ) ) {
F_52 ( & V_65 ) ;
return 0 ;
}
if ( V_57 == V_62 ) {
V_61 -> V_67 = V_2 ;
V_61 -> V_66 |= V_57 ;
}
if ( V_57 == V_63 ) {
V_61 -> V_68 = V_2 ;
V_61 -> V_66 |= V_57 ;
}
F_52 ( & V_65 ) ;
return 0 ;
}
}
F_52 ( & V_65 ) ;
V_61 = F_2 ( sizeof( * V_61 ) , V_8 ) ;
if ( ! V_61 )
return - V_9 ;
if ( V_57 == V_62 )
V_61 -> V_67 = V_2 ;
if ( V_57 == V_63 )
V_61 -> V_68 = V_2 ;
V_61 -> V_59 = V_59 ;
V_61 -> V_66 = V_57 ;
F_51 ( & V_65 ) ;
F_53 ( & V_61 -> V_69 , & V_70 ) ;
F_52 ( & V_65 ) ;
return 0 ;
}
void F_54 ( struct V_51 * V_2 ,
enum V_56 V_57 )
{
struct V_60 * V_61 , * V_71 ;
F_51 ( & V_65 ) ;
F_40 (cdev, next, &drm_component_list, list) {
if ( V_57 == V_62 ) {
if ( V_61 -> V_67 == V_2 ) {
V_61 -> V_67 = NULL ;
V_61 -> V_66 &= ~ V_57 ;
}
}
if ( V_57 == V_63 ) {
if ( V_61 -> V_68 == V_2 ) {
V_61 -> V_68 = NULL ;
V_61 -> V_66 &= ~ V_57 ;
}
}
if ( ! V_61 -> V_67 && ! V_61 -> V_68 ) {
F_41 ( & V_61 -> V_69 ) ;
F_23 ( V_61 ) ;
}
break;
}
F_52 ( & V_65 ) ;
}
static int F_55 ( struct V_51 * V_2 , void * V_72 )
{
return V_2 == (struct V_51 * ) V_72 ;
}
static struct V_73 * F_56 ( struct V_51 * V_2 )
{
struct V_73 * V_74 = NULL ;
struct V_60 * V_61 ;
unsigned int V_75 = 0 ;
F_51 ( & V_65 ) ;
if ( F_57 ( & V_70 ) ) {
F_52 ( & V_65 ) ;
return F_58 ( - V_76 ) ;
}
F_30 (cdev, &drm_component_list, list) {
if ( ! V_61 -> V_67 || ! V_61 -> V_68 )
continue;
V_75 ++ ;
F_52 ( & V_65 ) ;
if ( V_61 -> V_67 == V_61 -> V_68 ) {
F_59 ( V_2 , & V_74 , F_55 ,
V_61 -> V_67 ) ;
goto V_77;
}
F_59 ( V_2 , & V_74 , F_55 , V_61 -> V_67 ) ;
F_59 ( V_2 , & V_74 , F_55 , V_61 -> V_68 ) ;
V_77:
F_51 ( & V_65 ) ;
}
F_52 ( & V_65 ) ;
return V_75 ? V_74 : F_58 ( - V_78 ) ;
}
static int F_60 ( struct V_51 * V_2 )
{
return F_61 ( & V_79 , F_62 ( V_2 ) ) ;
}
static void F_63 ( struct V_51 * V_2 )
{
F_64 ( F_47 ( V_2 ) ) ;
}
static int F_65 ( struct V_80 * V_81 )
{
struct V_73 * V_74 ;
int V_6 ;
V_81 -> V_2 . V_82 = F_66 ( 32 ) ;
V_79 . V_83 = F_67 ( V_84 ) ;
#ifdef F_68
V_6 = F_69 ( & V_85 ) ;
if ( V_6 < 0 )
return V_6 ;
#endif
#ifdef F_70
V_6 = F_69 ( & V_86 ) ;
if ( V_6 < 0 )
goto V_87;
#endif
#ifdef F_71
V_6 = F_69 ( & V_88 ) ;
if ( V_6 < 0 )
goto V_89;
#endif
#ifdef F_72
V_6 = F_69 ( & V_90 ) ;
if ( V_6 < 0 )
goto V_91;
V_6 = F_69 ( & V_92 ) ;
if ( V_6 < 0 )
goto V_93;
#endif
V_74 = F_56 ( & V_81 -> V_2 ) ;
if ( F_10 ( V_74 ) ) {
V_6 = F_11 ( V_74 ) ;
goto V_94;
}
V_6 = F_73 ( & V_81 -> V_2 , & V_95 ,
V_74 ) ;
if ( V_6 < 0 )
goto V_94;
#ifdef F_74
V_6 = F_69 ( & V_96 ) ;
if ( V_6 < 0 )
goto V_97;
#endif
#ifdef F_75
V_6 = F_69 ( & V_98 ) ;
if ( V_6 < 0 )
goto V_99;
#endif
#ifdef F_76
V_6 = F_69 ( & V_100 ) ;
if ( V_6 < 0 )
goto V_101;
#endif
#ifdef F_77
V_6 = F_69 ( & V_102 ) ;
if ( V_6 < 0 )
goto V_103;
#endif
#ifdef F_78
V_6 = F_69 ( & V_104 ) ;
if ( V_6 < 0 )
goto V_105;
V_6 = F_79 () ;
if ( V_6 < 0 )
goto V_106;
#endif
return V_6 ;
#ifdef F_78
V_106:
F_80 ( & V_104 ) ;
V_105:
#endif
#ifdef F_77
F_80 ( & V_102 ) ;
V_103:
#endif
#ifdef F_76
F_80 ( & V_100 ) ;
V_101:
#endif
#ifdef F_75
F_80 ( & V_98 ) ;
V_99:
#endif
#ifdef F_74
F_80 ( & V_96 ) ;
V_97:
#endif
F_81 ( & V_81 -> V_2 , & V_95 ) ;
V_94:
#ifdef F_72
F_80 ( & V_92 ) ;
V_93:
F_80 ( & V_90 ) ;
V_91:
#endif
#ifdef F_71
F_80 ( & V_88 ) ;
V_89:
#endif
#ifdef F_70
F_80 ( & V_86 ) ;
V_87:
#endif
#ifdef F_68
F_80 ( & V_85 ) ;
#endif
return V_6 ;
}
static int F_82 ( struct V_80 * V_81 )
{
#ifdef F_78
F_83 () ;
F_80 ( & V_104 ) ;
#endif
#ifdef F_77
F_80 ( & V_102 ) ;
#endif
#ifdef F_76
F_80 ( & V_100 ) ;
#endif
#ifdef F_75
F_80 ( & V_98 ) ;
#endif
#ifdef F_74
F_80 ( & V_96 ) ;
#endif
#ifdef F_72
F_80 ( & V_90 ) ;
F_80 ( & V_92 ) ;
#endif
#ifdef F_68
F_80 ( & V_85 ) ;
#endif
#ifdef F_71
F_80 ( & V_88 ) ;
#endif
#ifdef F_70
F_80 ( & V_86 ) ;
#endif
F_81 ( & V_81 -> V_2 , & V_95 ) ;
return 0 ;
}
static int F_84 ( void )
{
int V_6 ;
if ( ! F_85 ( L_3 ) &&
! F_85 ( L_4 ) &&
! F_85 ( L_5 ) )
return - V_76 ;
V_107 = F_86 ( L_6 , - 1 ,
NULL , 0 ) ;
if ( F_10 ( V_107 ) )
return F_11 ( V_107 ) ;
#ifdef F_87
V_6 = F_88 () ;
if ( V_6 < 0 )
goto V_108;
#endif
V_6 = F_69 ( & V_109 ) ;
if ( V_6 )
goto V_110;
return 0 ;
V_110:
#ifdef F_87
F_89 () ;
V_108:
#endif
F_90 ( V_107 ) ;
return V_6 ;
}
static void F_91 ( void )
{
F_80 ( & V_109 ) ;
#ifdef F_87
F_89 () ;
#endif
F_90 ( V_107 ) ;
}
