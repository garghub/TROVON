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
V_15 = F_9 ( V_2 , V_16 , false ) ;
if ( ! V_15 )
goto V_18;
}
F_10 ( V_2 ) ;
V_6 = F_11 ( V_2 , V_17 ) ;
if ( V_6 )
goto V_18;
F_12 ( V_2 ) ;
V_19 = V_20 ;
F_13 ( V_2 -> V_21 , V_2 ) ;
V_6 = F_14 ( V_2 -> V_2 , V_2 ) ;
if ( V_6 )
goto V_22;
V_6 = F_15 ( V_2 ) ;
if ( V_6 )
goto V_23;
F_16 ( V_2 ) ;
return 0 ;
V_23:
F_17 ( V_2 -> V_2 , V_2 ) ;
V_22:
F_18 ( V_2 ) ;
V_18:
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
V_12:
F_21 ( V_5 ) ;
return V_6 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_18 ( V_2 ) ;
F_25 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 -> V_11 ) ;
F_17 ( V_2 -> V_2 , V_2 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_25 * V_26 ;
F_27 ( V_2 ) ;
F_28 (connector, &dev->mode_config.connector_list, head) {
int V_27 = V_26 -> V_28 ;
if ( V_26 -> V_29 -> V_28 )
V_26 -> V_29 -> V_28 ( V_26 , V_30 ) ;
V_26 -> V_28 = V_27 ;
}
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
F_27 ( V_2 ) ;
F_28 (connector, &dev->mode_config.connector_list, head) {
if ( V_26 -> V_29 -> V_28 )
V_26 -> V_29 -> V_28 ( V_26 , V_26 -> V_28 ) ;
}
F_29 ( V_2 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_33 * V_34 ;
struct V_32 * V_35 ;
int V_6 ;
V_34 = F_2 ( sizeof( * V_34 ) , V_8 ) ;
if ( ! V_34 )
return - V_9 ;
V_32 -> V_36 = V_34 ;
V_6 = F_33 ( V_2 , V_32 ) ;
if ( V_6 )
goto V_37;
V_35 = F_34 ( L_2 , & V_38 ,
NULL , 0 ) ;
if ( F_35 ( V_35 ) ) {
V_6 = F_36 ( V_35 ) ;
goto V_39;
}
V_35 -> V_40 = V_41 | V_42 ;
V_34 -> V_35 = V_35 ;
return V_6 ;
V_39:
F_37 ( V_2 , V_32 ) ;
V_37:
F_21 ( V_34 ) ;
V_32 -> V_36 = NULL ;
return V_6 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
F_37 ( V_2 , V_32 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_33 * V_34 ;
struct V_43 * V_44 , * V_45 ;
struct V_46 * V_47 , * V_48 ;
unsigned long V_3 ;
if ( ! V_32 -> V_36 )
return;
F_40 ( & V_2 -> V_49 , V_3 ) ;
F_41 (v, vt, &private->pageflip_event_list,
base.link) {
if ( V_44 -> V_50 . V_34 == V_32 ) {
F_42 ( & V_44 -> V_50 . V_51 ) ;
F_43 ( V_2 , V_44 -> V_52 ) ;
V_44 -> V_50 . V_53 ( & V_44 -> V_50 ) ;
}
}
F_41 (e, et, &file->event_list, link) {
F_42 ( & V_47 -> V_51 ) ;
V_47 -> V_53 ( V_47 ) ;
}
F_44 ( & V_2 -> V_49 , V_3 ) ;
V_34 = V_32 -> V_36 ;
if ( V_34 -> V_35 )
F_45 ( V_34 -> V_35 ) ;
F_21 ( V_32 -> V_36 ) ;
V_32 -> V_36 = NULL ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 ) ;
}
static int F_48 ( struct V_54 * V_2 )
{
struct V_1 * V_55 = F_49 ( V_2 ) ;
T_1 V_56 ;
if ( F_50 ( V_2 ) )
return 0 ;
V_56 . V_57 = V_58 ;
return F_26 ( V_55 , V_56 ) ;
}
static int F_51 ( struct V_54 * V_2 )
{
struct V_1 * V_55 = F_49 ( V_2 ) ;
if ( F_50 ( V_2 ) )
return 0 ;
return F_30 ( V_55 ) ;
}
int F_52 ( struct V_54 * V_2 ,
enum V_59 V_60 ,
enum V_61 V_62 )
{
struct V_63 * V_64 ;
if ( V_60 != V_65 &&
V_60 != V_66 ) {
F_6 ( L_3 ) ;
return - V_67 ;
}
F_53 ( & V_68 ) ;
F_28 (cdev, &drm_component_list, list) {
if ( V_64 -> V_62 == V_62 ) {
if ( V_64 -> V_69 == ( V_65 |
V_66 ) ) {
F_54 ( & V_68 ) ;
return 0 ;
}
if ( V_60 == V_65 ) {
V_64 -> V_70 = V_2 ;
V_64 -> V_69 |= V_60 ;
}
if ( V_60 == V_66 ) {
V_64 -> V_71 = V_2 ;
V_64 -> V_69 |= V_60 ;
}
F_54 ( & V_68 ) ;
return 0 ;
}
}
F_54 ( & V_68 ) ;
V_64 = F_2 ( sizeof( * V_64 ) , V_8 ) ;
if ( ! V_64 )
return - V_9 ;
if ( V_60 == V_65 )
V_64 -> V_70 = V_2 ;
if ( V_60 == V_66 )
V_64 -> V_71 = V_2 ;
V_64 -> V_62 = V_62 ;
V_64 -> V_69 = V_60 ;
F_53 ( & V_68 ) ;
F_55 ( & V_64 -> V_72 , & V_73 ) ;
F_54 ( & V_68 ) ;
return 0 ;
}
void F_56 ( struct V_54 * V_2 ,
enum V_59 V_60 )
{
struct V_63 * V_64 , * V_74 ;
F_53 ( & V_68 ) ;
F_41 (cdev, next, &drm_component_list, list) {
if ( V_60 == V_65 ) {
if ( V_64 -> V_70 == V_2 ) {
V_64 -> V_70 = NULL ;
V_64 -> V_69 &= ~ V_60 ;
}
}
if ( V_60 == V_66 ) {
if ( V_64 -> V_71 == V_2 ) {
V_64 -> V_71 = NULL ;
V_64 -> V_69 &= ~ V_60 ;
}
}
if ( ! V_64 -> V_70 && ! V_64 -> V_71 ) {
F_42 ( & V_64 -> V_72 ) ;
F_21 ( V_64 ) ;
}
break;
}
F_54 ( & V_68 ) ;
}
static int F_57 ( struct V_54 * V_2 , void * V_75 )
{
return V_2 == (struct V_54 * ) V_75 ;
}
static int F_58 ( struct V_54 * V_2 , struct V_76 * V_77 )
{
struct V_63 * V_64 ;
unsigned int V_78 = 0 ;
F_53 ( & V_68 ) ;
F_28 (cdev, &drm_component_list, list) {
int V_6 ;
if ( ! V_64 -> V_70 || ! V_64 -> V_71 )
continue;
V_78 ++ ;
F_54 ( & V_68 ) ;
if ( V_64 -> V_70 == V_64 -> V_71 ) {
V_6 = F_59 ( V_77 , F_57 ,
V_64 -> V_70 ) ;
if ( V_6 < 0 )
return V_6 ;
goto V_79;
}
V_6 = F_59 ( V_77 , F_57 , V_64 -> V_70 ) ;
V_6 |= F_59 ( V_77 , F_57 ,
V_64 -> V_71 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79:
F_53 ( & V_68 ) ;
}
F_54 ( & V_68 ) ;
return V_78 ? 0 : - V_80 ;
}
static int F_60 ( struct V_54 * V_2 )
{
return F_61 ( & V_81 , F_62 ( V_2 ) ) ;
}
static void F_63 ( struct V_54 * V_2 )
{
F_64 ( F_49 ( V_2 ) ) ;
}
static int F_65 ( struct V_82 * V_83 )
{
int V_6 ;
V_83 -> V_2 . V_84 = F_66 ( 32 ) ;
V_81 . V_85 = F_67 ( V_86 ) ;
#ifdef F_68
V_6 = F_69 ( & V_87 ) ;
if ( V_6 < 0 )
return V_6 ;
#endif
#ifdef F_70
V_6 = F_69 ( & V_88 ) ;
if ( V_6 < 0 )
goto V_89;
#endif
#ifdef F_71
V_6 = F_69 ( & V_90 ) ;
if ( V_6 < 0 )
goto V_91;
#endif
#ifdef F_72
V_6 = F_69 ( & V_92 ) ;
if ( V_6 < 0 )
goto V_93;
V_6 = F_69 ( & V_94 ) ;
if ( V_6 < 0 )
goto V_95;
#endif
#ifdef F_73
V_6 = F_69 ( & V_96 ) ;
if ( V_6 < 0 )
goto V_97;
#endif
#ifdef F_74
V_6 = F_69 ( & V_98 ) ;
if ( V_6 < 0 )
goto V_99;
#endif
#ifdef F_75
V_6 = F_69 ( & V_100 ) ;
if ( V_6 < 0 )
goto V_101;
#endif
#ifdef F_76
V_6 = F_69 ( & V_102 ) ;
if ( V_6 < 0 )
goto V_103;
#endif
#ifdef F_77
V_6 = F_69 ( & V_104 ) ;
if ( V_6 < 0 )
goto V_105;
V_6 = F_78 () ;
if ( V_6 < 0 )
goto V_106;
#endif
V_6 = F_79 ( & V_83 -> V_2 , & V_107 ) ;
if ( V_6 < 0 )
F_80 ( L_4 ) ;
return 0 ;
#ifdef F_77
V_106:
F_81 ( & V_104 ) ;
V_105:
#endif
#ifdef F_76
F_81 ( & V_102 ) ;
V_103:
#endif
#ifdef F_75
F_81 ( & V_100 ) ;
V_101:
#endif
#ifdef F_74
F_81 ( & V_98 ) ;
V_99:
#endif
#ifdef F_73
F_81 ( & V_96 ) ;
V_97:
#endif
#ifdef F_72
F_81 ( & V_94 ) ;
V_95:
F_81 ( & V_92 ) ;
V_93:
#endif
#ifdef F_71
F_81 ( & V_90 ) ;
V_91:
#endif
#ifdef F_70
F_81 ( & V_88 ) ;
V_89:
#endif
#ifdef F_68
F_81 ( & V_87 ) ;
#endif
return V_6 ;
}
static int F_82 ( struct V_82 * V_83 )
{
#ifdef F_77
F_83 () ;
F_81 ( & V_104 ) ;
#endif
#ifdef F_76
F_81 ( & V_102 ) ;
#endif
#ifdef F_75
F_81 ( & V_100 ) ;
#endif
#ifdef F_74
F_81 ( & V_98 ) ;
#endif
#ifdef F_73
F_81 ( & V_96 ) ;
#endif
#ifdef F_72
F_81 ( & V_92 ) ;
F_81 ( & V_94 ) ;
#endif
#ifdef F_68
F_81 ( & V_87 ) ;
#endif
#ifdef F_71
F_81 ( & V_90 ) ;
#endif
#ifdef F_70
F_81 ( & V_88 ) ;
#endif
F_84 ( & V_83 -> V_2 , & V_107 ) ;
return 0 ;
}
static int F_85 ( void )
{
int V_6 ;
V_108 = F_86 ( L_5 , - 1 ,
NULL , 0 ) ;
if ( F_35 ( V_108 ) )
return F_36 ( V_108 ) ;
#ifdef F_87
V_6 = F_88 () ;
if ( V_6 < 0 )
goto V_109;
#endif
V_6 = F_69 ( & V_110 ) ;
if ( V_6 )
goto V_111;
return 0 ;
V_111:
#ifdef F_87
F_89 () ;
V_109:
#endif
F_90 ( V_108 ) ;
return V_6 ;
}
static void F_91 ( void )
{
F_81 ( & V_110 ) ;
#ifdef F_87
F_89 () ;
#endif
F_90 ( V_108 ) ;
}
