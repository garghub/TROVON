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
static void F_35 ( struct V_6 * V_7 ,
int V_40 , enum V_41 V_42 )
{
int V_44 ;
V_7 -> V_45 -> V_46 ( V_7 , V_40 , & V_44 ) ;
if ( V_44 <= 0 || V_7 -> V_47 < V_44 )
return;
F_36 ( V_7 , V_40 , V_42 ) ;
if ( V_7 -> V_45 -> V_48 )
V_7 -> V_45 -> V_48 ( V_7 , V_40 , V_42 ) ;
if ( V_42 == V_49 ) {
F_37 ( & V_7 -> V_11 ,
L_5 ,
V_7 -> V_47 / 1000 ) ;
F_38 ( true ) ;
}
}
static void F_39 ( struct V_6 * V_7 , int V_40 )
{
enum V_41 type ;
if ( F_40 ( V_40 , & V_7 -> V_50 ) )
return;
V_7 -> V_45 -> V_51 ( V_7 , V_40 , & type ) ;
if ( type == V_49 || type == V_52 )
F_35 ( V_7 , V_40 , type ) ;
else
F_34 ( V_7 , V_40 , type ) ;
F_33 ( V_7 ) ;
}
static void F_41 ( struct V_6 * V_7 )
{
int V_53 , V_13 ;
V_13 = F_42 ( V_7 , & V_53 ) ;
if ( V_13 ) {
if ( V_13 != - V_54 )
F_43 ( & V_7 -> V_11 ,
L_6 ,
V_13 ) ;
return;
}
F_7 ( & V_7 -> V_28 ) ;
V_7 -> V_55 = V_7 -> V_47 ;
V_7 -> V_47 = V_53 ;
F_9 ( & V_7 -> V_28 ) ;
F_44 ( V_7 ) ;
if ( V_7 -> V_55 == V_56 )
F_45 ( & V_7 -> V_11 , L_7 ,
V_7 -> V_47 ) ;
else
F_45 ( & V_7 -> V_11 , L_8 ,
V_7 -> V_55 , V_7 -> V_47 ) ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_57 * V_3 ;
V_7 -> V_47 = V_56 ;
V_7 -> V_37 = 0 ;
F_2 (pos, &tz->thermal_instances, tz_node)
V_3 -> V_58 = false ;
}
void F_47 ( struct V_6 * V_7 ,
enum V_59 V_60 )
{
int V_30 ;
if ( F_48 ( & V_61 ) )
return;
if ( ! V_7 -> V_45 -> V_62 )
return;
F_41 ( V_7 ) ;
F_49 ( V_7 ) ;
V_7 -> V_63 = V_60 ;
for ( V_30 = 0 ; V_30 < V_7 -> V_64 ; V_30 ++ )
F_39 ( V_7 , V_30 ) ;
}
void F_50 ( struct V_6 * V_7 , int V_40 )
{
F_39 ( V_7 , V_40 ) ;
}
static void F_51 ( struct V_65 * V_66 )
{
struct V_6 * V_7 = F_52 ( V_66 , struct
V_6 ,
V_36 . V_66 ) ;
F_47 ( V_7 , V_67 ) ;
}
int F_53 ( struct V_68 * V_69 ,
struct V_6 * V_7 , T_3 * V_70 )
{
if ( ! F_54 ( V_69 ) )
return - V_16 ;
return V_69 -> V_45 -> V_71 ( V_69 , V_7 , 0 , V_70 ) ;
}
int F_55 ( struct V_68 * V_69 ,
struct V_6 * V_7 , T_3 * V_72 )
{
unsigned long V_73 ;
int V_13 ;
if ( ! F_54 ( V_69 ) )
return - V_16 ;
V_13 = V_69 -> V_45 -> V_74 ( V_69 , & V_73 ) ;
if ( V_13 )
return V_13 ;
return V_69 -> V_45 -> V_71 ( V_69 , V_7 , V_73 , V_72 ) ;
}
int F_56 ( struct V_68 * V_69 ,
struct V_57 * V_75 , T_3 V_76 )
{
unsigned long V_77 ;
int V_13 ;
if ( ! F_54 ( V_69 ) )
return - V_16 ;
V_13 = V_69 -> V_45 -> V_78 ( V_69 , V_75 -> V_7 , V_76 , & V_77 ) ;
if ( V_13 )
return V_13 ;
V_75 -> V_79 = V_77 ;
F_7 ( & V_69 -> V_28 ) ;
V_69 -> V_80 = false ;
F_9 ( & V_69 -> V_28 ) ;
F_57 ( V_69 ) ;
return 0 ;
}
void F_58 ( struct V_6 * V_7 ,
const char * V_81 , T_4 V_31 )
{
struct V_68 * V_69 = NULL ;
F_7 ( & V_23 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( strncmp ( V_81 , V_69 -> type , V_31 ) )
continue;
F_59 ( V_7 , V_82 , V_69 ,
V_83 ,
V_83 ,
V_84 ) ;
}
F_9 ( & V_23 ) ;
}
void F_60 ( struct V_6 * V_7 ,
const char * V_81 , T_4 V_31 )
{
struct V_68 * V_69 = NULL ;
F_7 ( & V_23 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( strncmp ( V_81 , V_69 -> type , V_31 ) )
continue;
F_61 ( V_7 , V_82 ,
V_69 ) ;
}
F_9 ( & V_23 ) ;
}
static int F_62 ( struct V_85 * V_85 , struct V_86 * V_28 , int * V_87 )
{
int V_13 ;
if ( V_28 )
F_7 ( V_28 ) ;
V_13 = F_63 ( V_85 , NULL , 0 , 0 , V_88 ) ;
if ( V_28 )
F_9 ( V_28 ) ;
if ( F_64 ( V_13 < 0 ) )
return V_13 ;
* V_87 = V_13 ;
return 0 ;
}
static void F_65 ( struct V_85 * V_85 , struct V_86 * V_28 , int V_87 )
{
if ( V_28 )
F_7 ( V_28 ) ;
F_66 ( V_85 , V_87 ) ;
if ( V_28 )
F_9 ( V_28 ) ;
}
int F_59 ( struct V_6 * V_7 ,
int V_40 ,
struct V_68 * V_69 ,
unsigned long V_89 , unsigned long V_90 ,
unsigned int V_91 )
{
struct V_57 * V_92 ;
struct V_57 * V_3 ;
struct V_6 * V_93 ;
struct V_68 * V_94 ;
unsigned long V_73 ;
int V_33 , V_13 ;
if ( V_40 >= V_7 -> V_64 || ( V_40 < 0 && V_40 != V_82 ) )
return - V_16 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_93 == V_7 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_94 == V_69 )
break;
}
if ( V_7 != V_93 || V_69 != V_94 )
return - V_16 ;
V_13 = V_69 -> V_45 -> V_74 ( V_69 , & V_73 ) ;
if ( V_13 )
return V_13 ;
V_90 = V_90 == V_83 ? 0 : V_90 ;
V_89 = V_89 == V_83 ? V_73 : V_89 ;
if ( V_90 > V_89 || V_89 > V_73 )
return - V_16 ;
V_92 = F_67 ( sizeof( * V_92 ) , V_88 ) ;
if ( ! V_92 )
return - V_95 ;
V_92 -> V_7 = V_7 ;
V_92 -> V_69 = V_69 ;
V_92 -> V_40 = V_40 ;
V_92 -> V_89 = V_89 ;
V_92 -> V_90 = V_90 ;
V_92 -> V_79 = V_96 ;
V_92 -> V_91 = V_91 ;
V_33 = F_62 ( & V_7 -> V_85 , & V_7 -> V_28 , & V_92 -> V_87 ) ;
if ( V_33 )
goto V_97;
sprintf ( V_92 -> V_2 , L_9 , V_92 -> V_87 ) ;
V_33 =
F_68 ( & V_7 -> V_11 . V_98 , & V_69 -> V_11 . V_98 , V_92 -> V_2 ) ;
if ( V_33 )
goto F_65;
sprintf ( V_92 -> V_99 , L_10 , V_92 -> V_87 ) ;
F_69 ( & V_92 -> V_100 . V_100 ) ;
V_92 -> V_100 . V_100 . V_2 = V_92 -> V_99 ;
V_92 -> V_100 . V_100 . V_101 = 0444 ;
V_92 -> V_100 . V_102 = V_103 ;
V_33 = F_70 ( & V_7 -> V_11 , & V_92 -> V_100 ) ;
if ( V_33 )
goto V_104;
sprintf ( V_92 -> V_105 , L_11 , V_92 -> V_87 ) ;
F_69 ( & V_92 -> V_106 . V_100 ) ;
V_92 -> V_106 . V_100 . V_2 = V_92 -> V_105 ;
V_92 -> V_106 . V_100 . V_101 = V_107 | V_108 ;
V_92 -> V_106 . V_102 = V_109 ;
V_92 -> V_106 . V_110 = V_111 ;
V_33 = F_70 ( & V_7 -> V_11 , & V_92 -> V_106 ) ;
if ( V_33 )
goto V_112;
F_7 ( & V_7 -> V_28 ) ;
F_7 ( & V_69 -> V_28 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_7 == V_7 && V_3 -> V_40 == V_40 && V_3 -> V_69 == V_69 ) {
V_33 = - V_113 ;
break;
}
if ( ! V_33 ) {
F_71 ( & V_92 -> V_114 , & V_7 -> V_115 ) ;
F_71 ( & V_92 -> V_116 , & V_69 -> V_115 ) ;
F_72 ( & V_7 -> V_117 , 1 ) ;
}
F_9 ( & V_69 -> V_28 ) ;
F_9 ( & V_7 -> V_28 ) ;
if ( ! V_33 )
return 0 ;
F_73 ( & V_7 -> V_11 , & V_92 -> V_106 ) ;
V_112:
F_73 ( & V_7 -> V_11 , & V_92 -> V_100 ) ;
V_104:
F_74 ( & V_7 -> V_11 . V_98 , V_92 -> V_2 ) ;
F_65:
F_65 ( & V_7 -> V_85 , & V_7 -> V_28 , V_92 -> V_87 ) ;
V_97:
F_75 ( V_92 ) ;
return V_33 ;
}
int F_61 ( struct V_6 * V_7 ,
int V_40 ,
struct V_68 * V_69 )
{
struct V_57 * V_3 , * V_118 ;
F_7 ( & V_7 -> V_28 ) ;
F_7 ( & V_69 -> V_28 ) ;
F_76 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_7 == V_7 && V_3 -> V_40 == V_40 && V_3 -> V_69 == V_69 ) {
F_11 ( & V_3 -> V_114 ) ;
F_11 ( & V_3 -> V_116 ) ;
F_9 ( & V_69 -> V_28 ) ;
F_9 ( & V_7 -> V_28 ) ;
goto V_119;
}
}
F_9 ( & V_69 -> V_28 ) ;
F_9 ( & V_7 -> V_28 ) ;
return - V_120 ;
V_119:
F_73 ( & V_7 -> V_11 , & V_3 -> V_106 ) ;
F_73 ( & V_7 -> V_11 , & V_3 -> V_100 ) ;
F_74 ( & V_7 -> V_11 . V_98 , V_3 -> V_2 ) ;
F_65 ( & V_7 -> V_85 , & V_7 -> V_28 , V_3 -> V_87 ) ;
F_75 ( V_3 ) ;
return 0 ;
}
static void F_77 ( struct V_11 * V_92 )
{
struct V_6 * V_7 ;
struct V_68 * V_69 ;
if ( ! strncmp ( F_78 ( V_92 ) , L_12 ,
sizeof( L_12 ) - 1 ) ) {
V_7 = F_79 ( V_92 ) ;
F_75 ( V_7 -> V_121 ) ;
F_75 ( V_7 -> V_122 ) ;
F_75 ( V_7 -> V_123 ) ;
F_75 ( V_7 -> V_124 . V_125 ) ;
F_75 ( V_7 -> V_11 . V_126 ) ;
F_75 ( V_7 ) ;
} else if ( ! strncmp ( F_78 ( V_92 ) , L_13 ,
sizeof( L_13 ) - 1 ) ) {
V_69 = F_80 ( V_92 ) ;
F_75 ( V_69 ) ;
}
}
static inline
void F_81 ( struct V_6 * V_7 ,
struct V_68 * V_69 , int V_13 )
{
F_4 ( & V_7 -> V_11 , L_14 ,
V_7 -> type , V_69 -> type , V_13 ) ;
}
static void F_82 ( struct V_6 * V_7 , int V_127 ,
struct V_68 * V_69 ,
unsigned long * V_128 ,
unsigned int V_91 )
{
int V_129 , V_13 ;
for ( V_129 = 0 ; V_129 < V_7 -> V_64 ; V_129 ++ ) {
if ( V_127 & ( 1 << V_129 ) ) {
unsigned long V_89 , V_90 ;
V_89 = V_83 ;
V_90 = V_83 ;
if ( V_128 ) {
V_90 = V_128 [ V_129 * 2 ] ;
V_89 = V_128 [ V_129 * 2 + 1 ] ;
}
V_13 = F_59 ( V_7 , V_129 , V_69 ,
V_89 , V_90 ,
V_91 ) ;
if ( V_13 )
F_81 ( V_7 , V_69 , V_13 ) ;
}
}
}
static void F_83 ( struct V_68 * V_69 )
{
int V_129 , V_13 ;
const struct V_130 * V_24 ;
struct V_6 * V_3 = NULL ;
F_7 ( & V_23 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! V_3 -> V_24 && ! V_3 -> V_45 -> V_131 )
continue;
if ( V_3 -> V_45 -> V_131 ) {
V_13 = V_3 -> V_45 -> V_131 ( V_3 , V_69 ) ;
if ( V_13 )
F_81 ( V_3 , V_69 , V_13 ) ;
continue;
}
V_24 = V_3 -> V_24 ;
if ( ! V_24 || ! V_24 -> V_132 )
continue;
for ( V_129 = 0 ; V_129 < V_24 -> V_133 ; V_129 ++ ) {
if ( V_24 -> V_132 [ V_129 ] . V_69 || ! V_24 -> V_132 [ V_129 ] . V_134 )
continue;
if ( V_24 -> V_132 [ V_129 ] . V_134 ( V_3 , V_69 ) )
continue;
V_24 -> V_132 [ V_129 ] . V_69 = V_69 ;
F_82 ( V_3 , V_24 -> V_132 [ V_129 ] . V_135 , V_69 ,
V_24 -> V_132 [ V_129 ] . V_136 ,
V_24 -> V_132 [ V_129 ] . V_91 ) ;
}
}
F_9 ( & V_23 ) ;
}
static struct V_68 *
F_84 ( struct V_137 * V_138 ,
char * type , void * V_139 ,
const struct V_140 * V_45 )
{
struct V_68 * V_69 ;
struct V_6 * V_3 = NULL ;
int V_33 ;
if ( type && strlen ( type ) >= V_5 )
return F_85 ( - V_16 ) ;
if ( ! V_45 || ! V_45 -> V_74 || ! V_45 -> V_141 ||
! V_45 -> V_142 )
return F_85 ( - V_16 ) ;
V_69 = F_67 ( sizeof( * V_69 ) , V_88 ) ;
if ( ! V_69 )
return F_85 ( - V_95 ) ;
V_33 = F_62 ( & V_143 , & V_144 , & V_69 -> V_87 ) ;
if ( V_33 ) {
F_75 ( V_69 ) ;
return F_85 ( V_33 ) ;
}
F_86 ( V_69 -> type , type ? : L_15 , sizeof( V_69 -> type ) ) ;
F_87 ( & V_69 -> V_28 ) ;
F_88 ( & V_69 -> V_115 ) ;
V_69 -> V_138 = V_138 ;
V_69 -> V_45 = V_45 ;
V_69 -> V_80 = false ;
V_69 -> V_11 . V_145 = & V_146 ;
F_89 ( V_69 ) ;
V_69 -> V_139 = V_139 ;
F_90 ( & V_69 -> V_11 , L_16 , V_69 -> V_87 ) ;
V_33 = F_91 ( & V_69 -> V_11 ) ;
if ( V_33 ) {
F_65 ( & V_143 , & V_144 , V_69 -> V_87 ) ;
F_75 ( V_69 ) ;
return F_85 ( V_33 ) ;
}
F_7 ( & V_23 ) ;
F_8 ( & V_69 -> V_147 , & V_148 ) ;
F_9 ( & V_23 ) ;
F_83 ( V_69 ) ;
F_7 ( & V_23 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( F_92 ( & V_3 -> V_117 , 1 , 0 ) )
F_47 ( V_3 ,
V_67 ) ;
F_9 ( & V_23 ) ;
return V_69 ;
}
struct V_68 *
F_93 ( char * type , void * V_139 ,
const struct V_140 * V_45 )
{
return F_84 ( NULL , type , V_139 , V_45 ) ;
}
struct V_68 *
F_94 ( struct V_137 * V_138 ,
char * type , void * V_139 ,
const struct V_140 * V_45 )
{
return F_84 ( V_138 , type , V_139 , V_45 ) ;
}
static void F_95 ( struct V_6 * V_7 , int V_127 ,
struct V_68 * V_69 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_7 -> V_64 ; V_129 ++ )
if ( V_127 & ( 1 << V_129 ) )
F_61 ( V_7 , V_129 , V_69 ) ;
}
void F_96 ( struct V_68 * V_69 )
{
int V_129 ;
const struct V_130 * V_24 ;
struct V_6 * V_7 ;
struct V_68 * V_3 = NULL ;
if ( ! V_69 )
return;
F_7 ( & V_23 ) ;
F_2 (pos, &thermal_cdev_list, node)
if ( V_3 == V_69 )
break;
if ( V_3 != V_69 ) {
F_9 ( & V_23 ) ;
return;
}
F_11 ( & V_69 -> V_147 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_7 -> V_45 -> V_119 ) {
V_7 -> V_45 -> V_119 ( V_7 , V_69 ) ;
continue;
}
if ( ! V_7 -> V_24 || ! V_7 -> V_24 -> V_132 )
continue;
V_24 = V_7 -> V_24 ;
for ( V_129 = 0 ; V_129 < V_24 -> V_133 ; V_129 ++ ) {
if ( V_24 -> V_132 [ V_129 ] . V_69 == V_69 ) {
F_95 ( V_7 , V_24 -> V_132 [ V_129 ] . V_135 , V_69 ) ;
V_24 -> V_132 [ V_129 ] . V_69 = NULL ;
}
}
}
F_9 ( & V_23 ) ;
F_65 ( & V_143 , & V_144 , V_69 -> V_87 ) ;
F_97 ( & V_69 -> V_11 ) ;
}
static void F_98 ( struct V_6 * V_7 )
{
int V_129 , V_13 ;
struct V_68 * V_3 = NULL ;
const struct V_130 * V_24 = V_7 -> V_24 ;
if ( ! V_24 && ! V_7 -> V_45 -> V_131 )
return;
F_7 ( & V_23 ) ;
if ( V_7 -> V_45 -> V_131 ) {
F_2 (pos, &thermal_cdev_list, node) {
V_13 = V_7 -> V_45 -> V_131 ( V_7 , V_3 ) ;
if ( V_13 )
F_81 ( V_7 , V_3 , V_13 ) ;
}
goto exit;
}
if ( ! V_24 || ! V_24 -> V_132 )
goto exit;
F_2 (pos, &thermal_cdev_list, node) {
for ( V_129 = 0 ; V_129 < V_24 -> V_133 ; V_129 ++ ) {
if ( V_24 -> V_132 [ V_129 ] . V_69 || ! V_24 -> V_132 [ V_129 ] . V_134 )
continue;
if ( V_24 -> V_132 [ V_129 ] . V_134 ( V_7 , V_3 ) )
continue;
V_24 -> V_132 [ V_129 ] . V_69 = V_3 ;
F_82 ( V_7 , V_24 -> V_132 [ V_129 ] . V_135 , V_3 ,
V_24 -> V_132 [ V_129 ] . V_136 ,
V_24 -> V_132 [ V_129 ] . V_91 ) ;
}
}
exit:
F_9 ( & V_23 ) ;
}
struct V_6 *
F_99 ( const char * type , int V_64 , int V_127 ,
void * V_139 , struct V_149 * V_45 ,
struct V_130 * V_24 , int V_38 ,
int V_39 )
{
struct V_6 * V_7 ;
enum V_41 V_42 ;
int V_44 ;
int V_33 ;
int V_30 ;
struct V_1 * V_9 ;
if ( ! type || strlen ( type ) == 0 )
return F_85 ( - V_16 ) ;
if ( type && strlen ( type ) >= V_5 )
return F_85 ( - V_16 ) ;
if ( V_64 > V_150 || V_64 < 0 || V_127 > > V_64 )
return F_85 ( - V_16 ) ;
if ( ! V_45 )
return F_85 ( - V_16 ) ;
if ( V_64 > 0 && ( ! V_45 -> V_51 || ! V_45 -> V_46 ) )
return F_85 ( - V_16 ) ;
V_7 = F_67 ( sizeof( * V_7 ) , V_88 ) ;
if ( ! V_7 )
return F_85 ( - V_95 ) ;
F_88 ( & V_7 -> V_115 ) ;
F_100 ( & V_7 -> V_85 ) ;
F_87 ( & V_7 -> V_28 ) ;
V_33 = F_62 ( & V_151 , & V_144 , & V_7 -> V_87 ) ;
if ( V_33 ) {
F_75 ( V_7 ) ;
return F_85 ( V_33 ) ;
}
F_86 ( V_7 -> type , type , sizeof( V_7 -> type ) ) ;
V_7 -> V_45 = V_45 ;
V_7 -> V_24 = V_24 ;
V_7 -> V_11 . V_145 = & V_146 ;
V_7 -> V_139 = V_139 ;
V_7 -> V_64 = V_64 ;
V_7 -> V_38 = V_38 ;
V_7 -> V_39 = V_39 ;
V_33 = F_101 ( V_7 , V_127 ) ;
if ( V_33 )
goto V_152;
F_72 ( & V_7 -> V_117 , 1 ) ;
F_90 ( & V_7 -> V_11 , L_17 , V_7 -> V_87 ) ;
V_33 = F_91 ( & V_7 -> V_11 ) ;
if ( V_33 ) {
F_65 ( & V_151 , & V_144 , V_7 -> V_87 ) ;
F_75 ( V_7 ) ;
return F_85 ( V_33 ) ;
}
for ( V_30 = 0 ; V_30 < V_64 ; V_30 ++ ) {
if ( V_7 -> V_45 -> V_51 ( V_7 , V_30 , & V_42 ) )
F_102 ( V_30 , & V_7 -> V_50 ) ;
if ( V_7 -> V_45 -> V_46 ( V_7 , V_30 , & V_44 ) )
F_102 ( V_30 , & V_7 -> V_50 ) ;
if ( V_44 == 0 )
F_102 ( V_30 , & V_7 -> V_50 ) ;
}
F_7 ( & V_17 ) ;
if ( V_7 -> V_24 )
V_9 = F_1 ( V_7 -> V_24 -> V_25 ) ;
else
V_9 = V_4 ;
V_33 = F_5 ( V_7 , V_9 ) ;
if ( V_33 ) {
F_9 ( & V_17 ) ;
goto V_152;
}
F_9 ( & V_17 ) ;
if ( ! V_7 -> V_24 || ! V_7 -> V_24 -> V_153 ) {
V_33 = F_103 ( V_7 ) ;
if ( V_33 )
goto V_152;
}
F_7 ( & V_23 ) ;
F_71 ( & V_7 -> V_147 , & V_154 ) ;
F_9 ( & V_23 ) ;
F_98 ( V_7 ) ;
F_104 ( & V_7 -> V_36 , F_51 ) ;
F_46 ( V_7 ) ;
if ( F_92 ( & V_7 -> V_117 , 1 , 0 ) )
F_47 ( V_7 , V_67 ) ;
return V_7 ;
V_152:
F_65 ( & V_151 , & V_144 , V_7 -> V_87 ) ;
F_97 ( & V_7 -> V_11 ) ;
return F_85 ( V_33 ) ;
}
void F_105 ( struct V_6 * V_7 )
{
int V_129 ;
const struct V_130 * V_24 ;
struct V_68 * V_69 ;
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
F_11 ( & V_7 -> V_147 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( V_7 -> V_45 -> V_119 ) {
V_7 -> V_45 -> V_119 ( V_7 , V_69 ) ;
continue;
}
if ( ! V_24 || ! V_24 -> V_132 )
break;
for ( V_129 = 0 ; V_129 < V_24 -> V_133 ; V_129 ++ ) {
if ( V_24 -> V_132 [ V_129 ] . V_69 == V_69 ) {
F_95 ( V_7 , V_24 -> V_132 [ V_129 ] . V_135 , V_69 ) ;
V_24 -> V_132 [ V_129 ] . V_69 = NULL ;
}
}
}
F_9 ( & V_23 ) ;
F_28 ( V_7 , 0 ) ;
F_5 ( V_7 , NULL ) ;
F_106 ( V_7 ) ;
F_65 ( & V_151 , & V_144 , V_7 -> V_87 ) ;
F_107 ( & V_7 -> V_85 ) ;
F_108 ( & V_7 -> V_28 ) ;
F_97 ( & V_7 -> V_11 ) ;
}
struct V_6 * F_109 ( const char * V_2 )
{
struct V_6 * V_3 = NULL , * V_155 = F_85 ( - V_16 ) ;
unsigned int V_156 = 0 ;
if ( ! V_2 )
goto exit;
F_7 ( & V_23 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( ! strncasecmp ( V_2 , V_3 -> type , V_5 ) ) {
V_156 ++ ;
V_155 = V_3 ;
}
F_9 ( & V_23 ) ;
if ( V_156 == 0 )
V_155 = F_85 ( - V_120 ) ;
else if ( V_156 > 1 )
V_155 = F_85 ( - V_113 ) ;
exit:
return V_155 ;
}
int F_110 ( struct V_6 * V_7 ,
enum V_157 V_60 )
{
struct V_158 * V_159 ;
struct V_160 * V_100 ;
struct V_161 * V_162 ;
void * V_163 ;
int V_31 ;
int V_33 ;
static unsigned int V_164 ;
if ( ! V_7 )
return - V_16 ;
V_31 = F_111 ( sizeof( struct V_161 ) ) +
F_111 ( 0 ) ;
V_159 = F_112 ( V_31 , V_165 ) ;
if ( ! V_159 )
return - V_95 ;
V_163 = F_113 ( V_159 , 0 , V_164 ++ ,
& V_166 , 0 ,
V_167 ) ;
if ( ! V_163 ) {
F_114 ( V_159 ) ;
return - V_95 ;
}
V_100 = F_115 ( V_159 , V_168 ,
sizeof( struct V_161 ) ) ;
if ( ! V_100 ) {
F_114 ( V_159 ) ;
return - V_16 ;
}
V_162 = F_116 ( V_100 ) ;
if ( ! V_162 ) {
F_114 ( V_159 ) ;
return - V_16 ;
}
memset ( V_162 , 0 , sizeof( struct V_161 ) ) ;
V_162 -> V_169 = V_7 -> V_87 ;
V_162 -> V_60 = V_60 ;
F_117 ( V_159 , V_163 ) ;
V_33 = F_118 ( & V_166 , V_159 , 0 ,
0 , V_165 ) ;
if ( V_33 )
F_4 ( & V_7 -> V_11 , L_18 , V_33 ) ;
return V_33 ;
}
static int T_2 F_119 ( void )
{
return F_120 ( & V_166 ) ;
}
static void F_121 ( void )
{
F_122 ( & V_166 ) ;
}
static inline int F_119 ( void ) { return 0 ; }
static inline void F_121 ( void ) {}
static int F_123 ( struct V_170 * V_171 ,
unsigned long V_101 , void * V_172 )
{
struct V_6 * V_7 ;
switch ( V_101 ) {
case V_173 :
case V_174 :
case V_175 :
F_72 ( & V_61 , 1 ) ;
break;
case V_176 :
case V_177 :
case V_178 :
F_72 ( & V_61 , 0 ) ;
F_2 (tz, &thermal_tz_list, node) {
F_46 ( V_7 ) ;
F_47 ( V_7 ,
V_67 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int T_2 F_124 ( void )
{
int V_33 ;
V_33 = F_16 () ;
if ( V_33 )
goto error;
V_33 = F_125 ( & V_146 ) ;
if ( V_33 )
goto V_179;
V_33 = F_119 () ;
if ( V_33 )
goto V_180;
V_33 = F_126 () ;
if ( V_33 )
goto V_181;
V_33 = F_127 ( & V_182 ) ;
if ( V_33 )
F_128 ( L_19 ,
V_33 ) ;
return 0 ;
V_181:
F_121 () ;
V_180:
F_129 ( & V_146 ) ;
V_179:
F_22 () ;
error:
F_107 ( & V_151 ) ;
F_107 ( & V_143 ) ;
F_108 ( & V_144 ) ;
F_108 ( & V_23 ) ;
F_108 ( & V_17 ) ;
return V_33 ;
}
static void T_5 F_130 ( void )
{
F_131 ( & V_182 ) ;
F_132 () ;
F_121 () ;
F_129 ( & V_146 ) ;
F_22 () ;
F_107 ( & V_151 ) ;
F_107 ( & V_143 ) ;
F_108 ( & V_144 ) ;
F_108 ( & V_23 ) ;
F_108 ( & V_17 ) ;
}
