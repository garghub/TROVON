static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 || ! V_2 [ 0 ] )
return V_4 ;
F_2 (pos, &thermal_governor_list, governor_list)
if ( ! strncasecmp ( V_2 , V_3 -> V_2 , V_5 ) )
return V_3 ;
return NULL ;
}
static void F_3 ( struct V_6 * V_7 ,
const char * V_8 )
{
if ( V_7 -> V_9 && V_7 -> V_9 -> V_10 ) {
if ( V_7 -> V_9 -> V_10 ( V_7 ) ) {
F_4 ( & V_7 -> V_11 ,
L_1 ,
V_8 , V_7 -> V_9 -> V_2 , V_7 -> type ) ;
V_7 -> V_9 = NULL ;
}
}
}
static int F_5 ( struct V_6 * V_7 ,
struct V_1 * V_12 )
{
int V_13 = 0 ;
if ( V_7 -> V_9 && V_7 -> V_9 -> V_14 )
V_7 -> V_9 -> V_14 ( V_7 ) ;
if ( V_12 && V_12 -> V_10 ) {
V_13 = V_12 -> V_10 ( V_7 ) ;
if ( V_13 ) {
F_3 ( V_7 , V_12 -> V_2 ) ;
return V_13 ;
}
}
V_7 -> V_9 = V_12 ;
return V_13 ;
}
int F_6 ( struct V_1 * V_9 )
{
int V_15 ;
const char * V_2 ;
struct V_6 * V_3 ;
if ( ! V_9 )
return - V_16 ;
F_7 ( & V_17 ) ;
V_15 = - V_18 ;
if ( ! F_1 ( V_9 -> V_2 ) ) {
bool V_19 ;
V_15 = 0 ;
F_8 ( & V_9 -> V_20 , & V_21 ) ;
V_19 = ! strncmp ( V_9 -> V_2 ,
V_22 ,
V_5 ) ;
if ( ! V_4 && V_19 )
V_4 = V_9 ;
}
F_7 ( & V_23 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( V_3 -> V_9 )
continue;
V_2 = V_3 -> V_24 -> V_25 ;
if ( ! strncasecmp ( V_2 , V_9 -> V_2 , V_5 ) ) {
int V_13 ;
V_13 = F_5 ( V_3 , V_9 ) ;
if ( V_13 )
F_4 ( & V_3 -> V_11 ,
L_2 ,
V_9 -> V_2 , V_3 -> type , V_13 ) ;
}
}
F_9 ( & V_23 ) ;
F_9 ( & V_17 ) ;
return V_15 ;
}
void F_10 ( struct V_1 * V_9 )
{
struct V_6 * V_3 ;
if ( ! V_9 )
return;
F_7 ( & V_17 ) ;
if ( ! F_1 ( V_9 -> V_2 ) )
goto exit;
F_7 ( & V_23 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! strncasecmp ( V_3 -> V_9 -> V_2 , V_9 -> V_2 ,
V_5 ) )
F_5 ( V_3 , NULL ) ;
}
F_9 ( & V_23 ) ;
F_11 ( & V_9 -> V_20 ) ;
exit:
F_9 ( & V_17 ) ;
}
int F_12 ( struct V_6 * V_7 ,
char * V_26 )
{
struct V_1 * V_27 ;
int V_13 = - V_16 ;
F_7 ( & V_17 ) ;
F_7 ( & V_7 -> V_28 ) ;
V_27 = F_1 ( F_13 ( V_26 ) ) ;
if ( ! V_27 )
goto exit;
V_13 = F_5 ( V_7 , V_27 ) ;
exit:
F_9 ( & V_7 -> V_28 ) ;
F_9 ( & V_17 ) ;
return V_13 ;
}
int F_14 ( char * V_29 )
{
struct V_1 * V_3 ;
T_1 V_30 = 0 ;
T_1 V_31 = V_32 ;
F_7 ( & V_17 ) ;
F_2 (pos, &thermal_governor_list, governor_list) {
V_31 = V_32 - V_30 ;
V_30 += F_15 ( V_29 + V_30 , V_31 , L_3 , V_3 -> V_2 ) ;
}
V_30 += F_15 ( V_29 + V_30 , V_31 , L_4 ) ;
F_9 ( & V_17 ) ;
return V_30 ;
}
static int T_2 F_16 ( void )
{
int V_33 ;
V_33 = F_17 () ;
if ( V_33 )
return V_33 ;
V_33 = F_18 () ;
if ( V_33 )
return V_33 ;
V_33 = F_19 () ;
if ( V_33 )
return V_33 ;
V_33 = F_20 () ;
if ( V_33 )
return V_33 ;
return F_21 () ;
}
static void F_22 ( void )
{
F_23 () ;
F_24 () ;
F_25 () ;
F_26 () ;
F_27 () ;
}
static void F_28 ( struct V_6 * V_7 ,
int V_34 )
{
if ( V_34 > 1000 )
F_29 ( V_35 , & V_7 -> V_36 ,
F_30 ( F_31 ( V_34 ) ) ) ;
else if ( V_34 )
F_29 ( V_35 , & V_7 -> V_36 ,
F_31 ( V_34 ) ) ;
else
F_32 ( & V_7 -> V_36 ) ;
}
static void F_33 ( struct V_6 * V_7 )
{
F_7 ( & V_7 -> V_28 ) ;
if ( V_7 -> V_37 )
F_28 ( V_7 , V_7 -> V_38 ) ;
else if ( V_7 -> V_39 )
F_28 ( V_7 , V_7 -> V_39 ) ;
else
F_28 ( V_7 , 0 ) ;
F_9 ( & V_7 -> V_28 ) ;
}
static void F_34 ( struct V_6 * V_7 ,
int V_40 ,
enum V_41 V_42 )
{
V_7 -> V_9 ? V_7 -> V_9 -> V_43 ( V_7 , V_40 ) :
V_4 -> V_43 ( V_7 , V_40 ) ;
}
static void F_35 ( struct V_44 * V_45 )
{
F_36 ( 1 , L_5 ) ;
F_37 () ;
F_36 ( 1 , L_6 ) ;
F_38 () ;
}
static void F_39 ( void )
{
int V_46 = V_47 ;
if ( V_46 <= 0 )
return;
F_40 ( & V_48 ,
F_31 ( V_46 ) ) ;
}
static void F_41 ( struct V_6 * V_7 ,
int V_40 , enum V_41 V_42 )
{
int V_49 ;
V_7 -> V_50 -> V_51 ( V_7 , V_40 , & V_49 ) ;
if ( V_49 <= 0 || V_7 -> V_52 < V_49 )
return;
F_42 ( V_7 , V_40 , V_42 ) ;
if ( V_7 -> V_50 -> V_53 )
V_7 -> V_50 -> V_53 ( V_7 , V_40 , V_42 ) ;
if ( V_42 == V_54 ) {
F_43 ( & V_7 -> V_11 ,
L_7 ,
V_7 -> V_52 / 1000 ) ;
F_7 ( & V_55 ) ;
if ( ! V_56 ) {
F_39 () ;
F_44 ( true ) ;
V_56 = true ;
}
F_9 ( & V_55 ) ;
}
}
static void F_45 ( struct V_6 * V_7 , int V_40 )
{
enum V_41 type ;
if ( F_46 ( V_40 , & V_7 -> V_57 ) )
return;
V_7 -> V_50 -> V_58 ( V_7 , V_40 , & type ) ;
if ( type == V_54 || type == V_59 )
F_41 ( V_7 , V_40 , type ) ;
else
F_34 ( V_7 , V_40 , type ) ;
F_33 ( V_7 ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
int V_60 , V_13 ;
V_13 = F_48 ( V_7 , & V_60 ) ;
if ( V_13 ) {
if ( V_13 != - V_61 )
F_49 ( & V_7 -> V_11 ,
L_8 ,
V_13 ) ;
return;
}
F_7 ( & V_7 -> V_28 ) ;
V_7 -> V_62 = V_7 -> V_52 ;
V_7 -> V_52 = V_60 ;
F_9 ( & V_7 -> V_28 ) ;
F_50 ( V_7 ) ;
if ( V_7 -> V_62 == V_63 )
F_51 ( & V_7 -> V_11 , L_9 ,
V_7 -> V_52 ) ;
else
F_51 ( & V_7 -> V_11 , L_10 ,
V_7 -> V_62 , V_7 -> V_52 ) ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_64 * V_3 ;
V_7 -> V_52 = V_63 ;
V_7 -> V_37 = 0 ;
F_2 (pos, &tz->thermal_instances, tz_node)
V_3 -> V_65 = false ;
}
void F_53 ( struct V_6 * V_7 ,
enum V_66 V_67 )
{
int V_30 ;
if ( F_54 ( & V_68 ) )
return;
if ( ! V_7 -> V_50 -> V_69 )
return;
F_47 ( V_7 ) ;
F_55 ( V_7 ) ;
V_7 -> V_70 = V_67 ;
for ( V_30 = 0 ; V_30 < V_7 -> V_71 ; V_30 ++ )
F_45 ( V_7 , V_30 ) ;
}
void F_56 ( struct V_6 * V_7 , int V_40 )
{
F_45 ( V_7 , V_40 ) ;
}
static void F_57 ( struct V_44 * V_45 )
{
struct V_6 * V_7 = F_58 ( V_45 , struct
V_6 ,
V_36 . V_45 ) ;
F_53 ( V_7 , V_72 ) ;
}
int F_59 ( struct V_73 * V_74 ,
struct V_6 * V_7 , T_3 * V_75 )
{
if ( ! F_60 ( V_74 ) )
return - V_16 ;
return V_74 -> V_50 -> V_76 ( V_74 , V_7 , 0 , V_75 ) ;
}
int F_61 ( struct V_73 * V_74 ,
struct V_6 * V_7 , T_3 * V_77 )
{
unsigned long V_78 ;
int V_13 ;
if ( ! F_60 ( V_74 ) )
return - V_16 ;
V_13 = V_74 -> V_50 -> V_79 ( V_74 , & V_78 ) ;
if ( V_13 )
return V_13 ;
return V_74 -> V_50 -> V_76 ( V_74 , V_7 , V_78 , V_77 ) ;
}
int F_62 ( struct V_73 * V_74 ,
struct V_64 * V_80 , T_3 V_81 )
{
unsigned long V_82 ;
int V_13 ;
if ( ! F_60 ( V_74 ) )
return - V_16 ;
V_13 = V_74 -> V_50 -> V_83 ( V_74 , V_80 -> V_7 , V_81 , & V_82 ) ;
if ( V_13 )
return V_13 ;
V_80 -> V_84 = V_82 ;
F_7 ( & V_74 -> V_28 ) ;
V_74 -> V_85 = false ;
F_9 ( & V_74 -> V_28 ) ;
F_63 ( V_74 ) ;
return 0 ;
}
void F_64 ( struct V_6 * V_7 ,
const char * V_86 , T_4 V_31 )
{
struct V_73 * V_74 = NULL ;
F_7 ( & V_23 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( strncmp ( V_86 , V_74 -> type , V_31 ) )
continue;
F_65 ( V_7 , V_87 , V_74 ,
V_88 ,
V_88 ,
V_89 ) ;
}
F_9 ( & V_23 ) ;
}
void F_66 ( struct V_6 * V_7 ,
const char * V_86 , T_4 V_31 )
{
struct V_73 * V_74 = NULL ;
F_7 ( & V_23 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( strncmp ( V_86 , V_74 -> type , V_31 ) )
continue;
F_67 ( V_7 , V_87 ,
V_74 ) ;
}
F_9 ( & V_23 ) ;
}
int F_65 ( struct V_6 * V_7 ,
int V_40 ,
struct V_73 * V_74 ,
unsigned long V_90 , unsigned long V_91 ,
unsigned int V_92 )
{
struct V_64 * V_93 ;
struct V_64 * V_3 ;
struct V_6 * V_94 ;
struct V_73 * V_95 ;
unsigned long V_78 ;
int V_33 , V_13 ;
if ( V_40 >= V_7 -> V_71 || ( V_40 < 0 && V_40 != V_87 ) )
return - V_16 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_94 == V_7 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_95 == V_74 )
break;
}
if ( V_7 != V_94 || V_74 != V_95 )
return - V_16 ;
V_13 = V_74 -> V_50 -> V_79 ( V_74 , & V_78 ) ;
if ( V_13 )
return V_13 ;
V_91 = V_91 == V_88 ? 0 : V_91 ;
V_90 = V_90 == V_88 ? V_78 : V_90 ;
if ( V_91 > V_90 || V_90 > V_78 )
return - V_16 ;
V_93 = F_68 ( sizeof( * V_93 ) , V_96 ) ;
if ( ! V_93 )
return - V_97 ;
V_93 -> V_7 = V_7 ;
V_93 -> V_74 = V_74 ;
V_93 -> V_40 = V_40 ;
V_93 -> V_90 = V_90 ;
V_93 -> V_91 = V_91 ;
V_93 -> V_84 = V_98 ;
V_93 -> V_92 = V_92 ;
V_33 = F_69 ( & V_7 -> V_99 , 0 , 0 , V_96 ) ;
if ( V_33 < 0 )
goto V_100;
V_93 -> V_101 = V_33 ;
sprintf ( V_93 -> V_2 , L_11 , V_93 -> V_101 ) ;
V_33 =
F_70 ( & V_7 -> V_11 . V_102 , & V_74 -> V_11 . V_102 , V_93 -> V_2 ) ;
if ( V_33 )
goto V_103;
sprintf ( V_93 -> V_104 , L_12 , V_93 -> V_101 ) ;
F_71 ( & V_93 -> V_105 . V_105 ) ;
V_93 -> V_105 . V_105 . V_2 = V_93 -> V_104 ;
V_93 -> V_105 . V_105 . V_106 = 0444 ;
V_93 -> V_105 . V_107 = V_108 ;
V_33 = F_72 ( & V_7 -> V_11 , & V_93 -> V_105 ) ;
if ( V_33 )
goto V_109;
sprintf ( V_93 -> V_110 , L_13 , V_93 -> V_101 ) ;
F_71 ( & V_93 -> V_111 . V_105 ) ;
V_93 -> V_111 . V_105 . V_2 = V_93 -> V_110 ;
V_93 -> V_111 . V_105 . V_106 = V_112 | V_113 ;
V_93 -> V_111 . V_107 = V_114 ;
V_93 -> V_111 . V_115 = V_116 ;
V_33 = F_72 ( & V_7 -> V_11 , & V_93 -> V_111 ) ;
if ( V_33 )
goto V_117;
F_7 ( & V_7 -> V_28 ) ;
F_7 ( & V_74 -> V_28 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_7 == V_7 && V_3 -> V_40 == V_40 && V_3 -> V_74 == V_74 ) {
V_33 = - V_118 ;
break;
}
if ( ! V_33 ) {
F_73 ( & V_93 -> V_119 , & V_7 -> V_120 ) ;
F_73 ( & V_93 -> V_121 , & V_74 -> V_120 ) ;
F_74 ( & V_7 -> V_122 , 1 ) ;
}
F_9 ( & V_74 -> V_28 ) ;
F_9 ( & V_7 -> V_28 ) ;
if ( ! V_33 )
return 0 ;
F_75 ( & V_7 -> V_11 , & V_93 -> V_111 ) ;
V_117:
F_75 ( & V_7 -> V_11 , & V_93 -> V_105 ) ;
V_109:
F_76 ( & V_7 -> V_11 . V_102 , V_93 -> V_2 ) ;
V_103:
F_77 ( & V_7 -> V_99 , V_93 -> V_101 ) ;
V_100:
F_78 ( V_93 ) ;
return V_33 ;
}
int F_67 ( struct V_6 * V_7 ,
int V_40 ,
struct V_73 * V_74 )
{
struct V_64 * V_3 , * V_123 ;
F_7 ( & V_7 -> V_28 ) ;
F_7 ( & V_74 -> V_28 ) ;
F_79 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_7 == V_7 && V_3 -> V_40 == V_40 && V_3 -> V_74 == V_74 ) {
F_11 ( & V_3 -> V_119 ) ;
F_11 ( & V_3 -> V_121 ) ;
F_9 ( & V_74 -> V_28 ) ;
F_9 ( & V_7 -> V_28 ) ;
goto V_124;
}
}
F_9 ( & V_74 -> V_28 ) ;
F_9 ( & V_7 -> V_28 ) ;
return - V_125 ;
V_124:
F_75 ( & V_7 -> V_11 , & V_3 -> V_111 ) ;
F_75 ( & V_7 -> V_11 , & V_3 -> V_105 ) ;
F_76 ( & V_7 -> V_11 . V_102 , V_3 -> V_2 ) ;
F_77 ( & V_7 -> V_99 , V_3 -> V_101 ) ;
F_78 ( V_3 ) ;
return 0 ;
}
static void F_80 ( struct V_11 * V_93 )
{
struct V_6 * V_7 ;
struct V_73 * V_74 ;
if ( ! strncmp ( F_81 ( V_93 ) , L_14 ,
sizeof( L_14 ) - 1 ) ) {
V_7 = F_82 ( V_93 ) ;
F_83 ( V_7 ) ;
F_78 ( V_7 ) ;
} else if ( ! strncmp ( F_81 ( V_93 ) , L_15 ,
sizeof( L_15 ) - 1 ) ) {
V_74 = F_84 ( V_93 ) ;
F_78 ( V_74 ) ;
}
}
static inline
void F_85 ( struct V_6 * V_7 ,
struct V_73 * V_74 , int V_13 )
{
F_4 ( & V_7 -> V_11 , L_16 ,
V_7 -> type , V_74 -> type , V_13 ) ;
}
static void F_86 ( struct V_6 * V_7 , int V_126 ,
struct V_73 * V_74 ,
unsigned long * V_127 ,
unsigned int V_92 )
{
int V_128 , V_13 ;
for ( V_128 = 0 ; V_128 < V_7 -> V_71 ; V_128 ++ ) {
if ( V_126 & ( 1 << V_128 ) ) {
unsigned long V_90 , V_91 ;
V_90 = V_88 ;
V_91 = V_88 ;
if ( V_127 ) {
V_91 = V_127 [ V_128 * 2 ] ;
V_90 = V_127 [ V_128 * 2 + 1 ] ;
}
V_13 = F_65 ( V_7 , V_128 , V_74 ,
V_90 , V_91 ,
V_92 ) ;
if ( V_13 )
F_85 ( V_7 , V_74 , V_13 ) ;
}
}
}
static void F_87 ( struct V_73 * V_74 )
{
int V_128 , V_13 ;
const struct V_129 * V_24 ;
struct V_6 * V_3 = NULL ;
F_7 ( & V_23 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! V_3 -> V_24 && ! V_3 -> V_50 -> V_130 )
continue;
if ( V_3 -> V_50 -> V_130 ) {
V_13 = V_3 -> V_50 -> V_130 ( V_3 , V_74 ) ;
if ( V_13 )
F_85 ( V_3 , V_74 , V_13 ) ;
continue;
}
V_24 = V_3 -> V_24 ;
if ( ! V_24 || ! V_24 -> V_131 )
continue;
for ( V_128 = 0 ; V_128 < V_24 -> V_132 ; V_128 ++ ) {
if ( V_24 -> V_131 [ V_128 ] . V_74 || ! V_24 -> V_131 [ V_128 ] . V_133 )
continue;
if ( V_24 -> V_131 [ V_128 ] . V_133 ( V_3 , V_74 ) )
continue;
V_24 -> V_131 [ V_128 ] . V_74 = V_74 ;
F_86 ( V_3 , V_24 -> V_131 [ V_128 ] . V_134 , V_74 ,
V_24 -> V_131 [ V_128 ] . V_135 ,
V_24 -> V_131 [ V_128 ] . V_92 ) ;
}
}
F_9 ( & V_23 ) ;
}
static struct V_73 *
F_88 ( struct V_136 * V_137 ,
char * type , void * V_138 ,
const struct V_139 * V_50 )
{
struct V_73 * V_74 ;
struct V_6 * V_3 = NULL ;
int V_33 ;
if ( type && strlen ( type ) >= V_5 )
return F_89 ( - V_16 ) ;
if ( ! V_50 || ! V_50 -> V_79 || ! V_50 -> V_140 ||
! V_50 -> V_141 )
return F_89 ( - V_16 ) ;
V_74 = F_68 ( sizeof( * V_74 ) , V_96 ) ;
if ( ! V_74 )
return F_89 ( - V_97 ) ;
V_33 = F_69 ( & V_142 , 0 , 0 , V_96 ) ;
if ( V_33 < 0 ) {
F_78 ( V_74 ) ;
return F_89 ( V_33 ) ;
}
V_74 -> V_101 = V_33 ;
F_90 ( V_74 -> type , type ? : L_17 , sizeof( V_74 -> type ) ) ;
F_91 ( & V_74 -> V_28 ) ;
F_92 ( & V_74 -> V_120 ) ;
V_74 -> V_137 = V_137 ;
V_74 -> V_50 = V_50 ;
V_74 -> V_85 = false ;
V_74 -> V_11 . V_143 = & V_144 ;
F_93 ( V_74 ) ;
V_74 -> V_138 = V_138 ;
F_94 ( & V_74 -> V_11 , L_18 , V_74 -> V_101 ) ;
V_33 = F_95 ( & V_74 -> V_11 ) ;
if ( V_33 ) {
F_77 ( & V_142 , V_74 -> V_101 ) ;
F_78 ( V_74 ) ;
return F_89 ( V_33 ) ;
}
F_7 ( & V_23 ) ;
F_8 ( & V_74 -> V_145 , & V_146 ) ;
F_9 ( & V_23 ) ;
F_87 ( V_74 ) ;
F_7 ( & V_23 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( F_96 ( & V_3 -> V_122 , 1 , 0 ) )
F_53 ( V_3 ,
V_72 ) ;
F_9 ( & V_23 ) ;
return V_74 ;
}
struct V_73 *
F_97 ( char * type , void * V_138 ,
const struct V_139 * V_50 )
{
return F_88 ( NULL , type , V_138 , V_50 ) ;
}
struct V_73 *
F_98 ( struct V_136 * V_137 ,
char * type , void * V_138 ,
const struct V_139 * V_50 )
{
return F_88 ( V_137 , type , V_138 , V_50 ) ;
}
static void F_99 ( struct V_6 * V_7 , int V_126 ,
struct V_73 * V_74 )
{
int V_128 ;
for ( V_128 = 0 ; V_128 < V_7 -> V_71 ; V_128 ++ )
if ( V_126 & ( 1 << V_128 ) )
F_67 ( V_7 , V_128 , V_74 ) ;
}
void F_100 ( struct V_73 * V_74 )
{
int V_128 ;
const struct V_129 * V_24 ;
struct V_6 * V_7 ;
struct V_73 * V_3 = NULL ;
if ( ! V_74 )
return;
F_7 ( & V_23 ) ;
F_2 (pos, &thermal_cdev_list, node)
if ( V_3 == V_74 )
break;
if ( V_3 != V_74 ) {
F_9 ( & V_23 ) ;
return;
}
F_11 ( & V_74 -> V_145 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_7 -> V_50 -> V_124 ) {
V_7 -> V_50 -> V_124 ( V_7 , V_74 ) ;
continue;
}
if ( ! V_7 -> V_24 || ! V_7 -> V_24 -> V_131 )
continue;
V_24 = V_7 -> V_24 ;
for ( V_128 = 0 ; V_128 < V_24 -> V_132 ; V_128 ++ ) {
if ( V_24 -> V_131 [ V_128 ] . V_74 == V_74 ) {
F_99 ( V_7 , V_24 -> V_131 [ V_128 ] . V_134 , V_74 ) ;
V_24 -> V_131 [ V_128 ] . V_74 = NULL ;
}
}
}
F_9 ( & V_23 ) ;
F_77 ( & V_142 , V_74 -> V_101 ) ;
F_101 ( & V_74 -> V_11 ) ;
}
static void F_102 ( struct V_6 * V_7 )
{
int V_128 , V_13 ;
struct V_73 * V_3 = NULL ;
const struct V_129 * V_24 = V_7 -> V_24 ;
if ( ! V_24 && ! V_7 -> V_50 -> V_130 )
return;
F_7 ( & V_23 ) ;
if ( V_7 -> V_50 -> V_130 ) {
F_2 (pos, &thermal_cdev_list, node) {
V_13 = V_7 -> V_50 -> V_130 ( V_7 , V_3 ) ;
if ( V_13 )
F_85 ( V_7 , V_3 , V_13 ) ;
}
goto exit;
}
if ( ! V_24 || ! V_24 -> V_131 )
goto exit;
F_2 (pos, &thermal_cdev_list, node) {
for ( V_128 = 0 ; V_128 < V_24 -> V_132 ; V_128 ++ ) {
if ( V_24 -> V_131 [ V_128 ] . V_74 || ! V_24 -> V_131 [ V_128 ] . V_133 )
continue;
if ( V_24 -> V_131 [ V_128 ] . V_133 ( V_7 , V_3 ) )
continue;
V_24 -> V_131 [ V_128 ] . V_74 = V_3 ;
F_86 ( V_7 , V_24 -> V_131 [ V_128 ] . V_134 , V_3 ,
V_24 -> V_131 [ V_128 ] . V_135 ,
V_24 -> V_131 [ V_128 ] . V_92 ) ;
}
}
exit:
F_9 ( & V_23 ) ;
}
struct V_6 *
F_103 ( const char * type , int V_71 , int V_126 ,
void * V_138 , struct V_147 * V_50 ,
struct V_129 * V_24 , int V_38 ,
int V_39 )
{
struct V_6 * V_7 ;
enum V_41 V_42 ;
int V_49 ;
int V_33 ;
int V_30 ;
struct V_1 * V_9 ;
if ( ! type || strlen ( type ) == 0 )
return F_89 ( - V_16 ) ;
if ( type && strlen ( type ) >= V_5 )
return F_89 ( - V_16 ) ;
if ( V_71 > V_148 || V_71 < 0 || V_126 > > V_71 )
return F_89 ( - V_16 ) ;
if ( ! V_50 )
return F_89 ( - V_16 ) ;
if ( V_71 > 0 && ( ! V_50 -> V_58 || ! V_50 -> V_51 ) )
return F_89 ( - V_16 ) ;
V_7 = F_68 ( sizeof( * V_7 ) , V_96 ) ;
if ( ! V_7 )
return F_89 ( - V_97 ) ;
F_92 ( & V_7 -> V_120 ) ;
F_104 ( & V_7 -> V_99 ) ;
F_91 ( & V_7 -> V_28 ) ;
V_33 = F_69 ( & V_149 , 0 , 0 , V_96 ) ;
if ( V_33 < 0 )
goto V_150;
V_7 -> V_101 = V_33 ;
F_90 ( V_7 -> type , type , sizeof( V_7 -> type ) ) ;
V_7 -> V_50 = V_50 ;
V_7 -> V_24 = V_24 ;
V_7 -> V_11 . V_143 = & V_144 ;
V_7 -> V_138 = V_138 ;
V_7 -> V_71 = V_71 ;
V_7 -> V_38 = V_38 ;
V_7 -> V_39 = V_39 ;
V_33 = F_105 ( V_7 , V_126 ) ;
if ( V_33 )
goto V_151;
F_74 ( & V_7 -> V_122 , 1 ) ;
F_94 ( & V_7 -> V_11 , L_19 , V_7 -> V_101 ) ;
V_33 = F_95 ( & V_7 -> V_11 ) ;
if ( V_33 )
goto V_152;
for ( V_30 = 0 ; V_30 < V_71 ; V_30 ++ ) {
if ( V_7 -> V_50 -> V_58 ( V_7 , V_30 , & V_42 ) )
F_106 ( V_30 , & V_7 -> V_57 ) ;
if ( V_7 -> V_50 -> V_51 ( V_7 , V_30 , & V_49 ) )
F_106 ( V_30 , & V_7 -> V_57 ) ;
if ( V_49 == 0 )
F_106 ( V_30 , & V_7 -> V_57 ) ;
}
F_7 ( & V_17 ) ;
if ( V_7 -> V_24 )
V_9 = F_1 ( V_7 -> V_24 -> V_25 ) ;
else
V_9 = V_4 ;
V_33 = F_5 ( V_7 , V_9 ) ;
if ( V_33 ) {
F_9 ( & V_17 ) ;
goto V_153;
}
F_9 ( & V_17 ) ;
if ( ! V_7 -> V_24 || ! V_7 -> V_24 -> V_154 ) {
V_33 = F_107 ( V_7 ) ;
if ( V_33 )
goto V_153;
}
F_7 ( & V_23 ) ;
F_73 ( & V_7 -> V_145 , & V_155 ) ;
F_9 ( & V_23 ) ;
F_102 ( V_7 ) ;
F_108 ( & V_7 -> V_36 , F_57 ) ;
F_52 ( V_7 ) ;
if ( F_96 ( & V_7 -> V_122 , 1 , 0 ) )
F_53 ( V_7 , V_72 ) ;
return V_7 ;
V_153:
F_77 ( & V_149 , V_7 -> V_101 ) ;
F_101 ( & V_7 -> V_11 ) ;
return F_89 ( V_33 ) ;
V_152:
F_83 ( V_7 ) ;
V_151:
F_77 ( & V_149 , V_7 -> V_101 ) ;
V_150:
F_78 ( V_7 ) ;
return F_89 ( V_33 ) ;
}
void F_109 ( struct V_6 * V_7 )
{
int V_128 ;
const struct V_129 * V_24 ;
struct V_73 * V_74 ;
struct V_6 * V_3 = NULL ;
if ( ! V_7 )
return;
V_24 = V_7 -> V_24 ;
F_7 ( & V_23 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( V_3 == V_7 )
break;
if ( V_3 != V_7 ) {
F_9 ( & V_23 ) ;
return;
}
F_11 ( & V_7 -> V_145 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( V_7 -> V_50 -> V_124 ) {
V_7 -> V_50 -> V_124 ( V_7 , V_74 ) ;
continue;
}
if ( ! V_24 || ! V_24 -> V_131 )
break;
for ( V_128 = 0 ; V_128 < V_24 -> V_132 ; V_128 ++ ) {
if ( V_24 -> V_131 [ V_128 ] . V_74 == V_74 ) {
F_99 ( V_7 , V_24 -> V_131 [ V_128 ] . V_134 , V_74 ) ;
V_24 -> V_131 [ V_128 ] . V_74 = NULL ;
}
}
}
F_9 ( & V_23 ) ;
F_28 ( V_7 , 0 ) ;
F_5 ( V_7 , NULL ) ;
F_110 ( V_7 ) ;
F_77 ( & V_149 , V_7 -> V_101 ) ;
F_111 ( & V_7 -> V_99 ) ;
F_112 ( & V_7 -> V_28 ) ;
F_101 ( & V_7 -> V_11 ) ;
}
struct V_6 * F_113 ( const char * V_2 )
{
struct V_6 * V_3 = NULL , * V_156 = F_89 ( - V_16 ) ;
unsigned int V_157 = 0 ;
if ( ! V_2 )
goto exit;
F_7 ( & V_23 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( ! strncasecmp ( V_2 , V_3 -> type , V_5 ) ) {
V_157 ++ ;
V_156 = V_3 ;
}
F_9 ( & V_23 ) ;
if ( V_157 == 0 )
V_156 = F_89 ( - V_125 ) ;
else if ( V_157 > 1 )
V_156 = F_89 ( - V_118 ) ;
exit:
return V_156 ;
}
int F_114 ( struct V_6 * V_7 ,
enum V_158 V_67 )
{
struct V_159 * V_160 ;
struct V_161 * V_105 ;
struct V_162 * V_163 ;
void * V_164 ;
int V_31 ;
int V_33 ;
static unsigned int V_165 ;
if ( ! V_7 )
return - V_16 ;
V_31 = F_115 ( sizeof( struct V_162 ) ) +
F_115 ( 0 ) ;
V_160 = F_116 ( V_31 , V_166 ) ;
if ( ! V_160 )
return - V_97 ;
V_164 = F_117 ( V_160 , 0 , V_165 ++ ,
& V_167 , 0 ,
V_168 ) ;
if ( ! V_164 ) {
F_118 ( V_160 ) ;
return - V_97 ;
}
V_105 = F_119 ( V_160 , V_169 ,
sizeof( struct V_162 ) ) ;
if ( ! V_105 ) {
F_118 ( V_160 ) ;
return - V_16 ;
}
V_163 = F_120 ( V_105 ) ;
if ( ! V_163 ) {
F_118 ( V_160 ) ;
return - V_16 ;
}
memset ( V_163 , 0 , sizeof( struct V_162 ) ) ;
V_163 -> V_170 = V_7 -> V_101 ;
V_163 -> V_67 = V_67 ;
F_121 ( V_160 , V_164 ) ;
V_33 = F_122 ( & V_167 , V_160 , 0 ,
0 , V_166 ) ;
if ( V_33 )
F_4 ( & V_7 -> V_11 , L_20 , V_33 ) ;
return V_33 ;
}
static int T_2 F_123 ( void )
{
return F_124 ( & V_167 ) ;
}
static void F_125 ( void )
{
F_126 ( & V_167 ) ;
}
static inline int F_123 ( void ) { return 0 ; }
static inline void F_125 ( void ) {}
static int F_127 ( struct V_171 * V_172 ,
unsigned long V_106 , void * V_173 )
{
struct V_6 * V_7 ;
switch ( V_106 ) {
case V_174 :
case V_175 :
case V_176 :
F_74 ( & V_68 , 1 ) ;
break;
case V_177 :
case V_178 :
case V_179 :
F_74 ( & V_68 , 0 ) ;
F_2 (tz, &thermal_tz_list, node) {
F_52 ( V_7 ) ;
F_53 ( V_7 ,
V_72 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int T_2 F_128 ( void )
{
int V_33 ;
F_91 ( & V_55 ) ;
V_33 = F_16 () ;
if ( V_33 )
goto error;
V_33 = F_129 ( & V_144 ) ;
if ( V_33 )
goto V_180;
V_33 = F_123 () ;
if ( V_33 )
goto V_181;
V_33 = F_130 () ;
if ( V_33 )
goto V_182;
V_33 = F_131 ( & V_183 ) ;
if ( V_33 )
F_132 ( L_21 ,
V_33 ) ;
return 0 ;
V_182:
F_125 () ;
V_181:
F_133 ( & V_144 ) ;
V_180:
F_22 () ;
error:
F_111 ( & V_149 ) ;
F_111 ( & V_142 ) ;
F_112 ( & V_23 ) ;
F_112 ( & V_17 ) ;
F_112 ( & V_55 ) ;
return V_33 ;
}
static void T_5 F_134 ( void )
{
F_135 ( & V_183 ) ;
F_136 () ;
F_125 () ;
F_133 ( & V_144 ) ;
F_22 () ;
F_111 ( & V_149 ) ;
F_111 ( & V_142 ) ;
F_112 ( & V_23 ) ;
F_112 ( & V_17 ) ;
}
