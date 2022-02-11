int F_1 ( const char * V_1 ,
struct V_2 * V_3 )
{
unsigned V_4 ;
unsigned V_5 ;
T_1 V_6 ;
int V_7 ;
V_7 = F_2 ( V_1 , 0 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_4 = V_6 & 0x3ff ;
V_5 = V_6 >> 10 ;
switch ( V_4 ) {
case 0 :
case 0x62 ... 0xfe :
case 0x100 ... 0x3ff :
return - V_8 ;
}
if ( ! V_5 )
return - V_8 ;
V_3 -> V_9 = V_6 ;
return 0 ;
}
static int F_3 ( const char * V_10 , char * * V_11 )
{
int V_7 ;
char * V_12 ;
char * V_13 = * V_11 ;
V_7 = strlen ( V_10 ) ;
if ( V_7 > 126 )
return - V_14 ;
V_12 = F_4 ( V_10 , V_15 ) ;
if ( ! V_12 )
return - V_16 ;
if ( V_12 [ V_7 - 1 ] == '\n' )
V_12 [ V_7 - 1 ] = '\0' ;
F_5 ( V_13 ) ;
* V_11 = V_12 ;
return 0 ;
}
static T_2 F_6 ( T_1 V_17 )
{
if ( ( V_17 & 0xf ) > 9 )
return - V_8 ;
if ( ( ( V_17 >> 4 ) & 0xf ) > 9 )
return - V_8 ;
if ( ( ( V_17 >> 8 ) & 0xf ) > 9 )
return - V_8 ;
if ( ( ( V_17 >> 12 ) & 0xf ) > 9 )
return - V_8 ;
return 0 ;
}
static T_2 F_7 ( struct V_18 * V_19 ,
const char * V_20 , T_3 V_21 )
{
T_1 V_22 ;
int V_7 ;
V_7 = F_2 ( V_20 , 0 , & V_22 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_22 ) ;
if ( V_7 )
return V_7 ;
V_19 -> V_23 . V_24 . V_22 = F_8 ( V_22 ) ;
return V_21 ;
}
static T_2 F_9 ( struct V_18 * V_19 ,
const char * V_20 , T_3 V_21 )
{
T_1 V_25 ;
int V_7 ;
V_7 = F_2 ( V_20 , 0 , & V_25 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_25 ) ;
if ( V_7 )
return V_7 ;
V_19 -> V_23 . V_24 . V_25 = F_8 ( V_25 ) ;
return V_21 ;
}
static T_2 F_10 ( struct V_18 * V_19 , char * V_20 )
{
return sprintf ( V_20 , L_1 , V_19 -> V_26 ? : L_2 ) ;
}
static int F_11 ( struct V_18 * V_19 )
{
int V_7 ;
if ( ! V_19 -> V_26 )
return - V_27 ;
V_7 = F_12 ( & V_19 -> V_28 . V_29 ) ;
if ( V_7 )
return V_7 ;
F_5 ( V_19 -> V_26 ) ;
V_19 -> V_26 = NULL ;
return 0 ;
}
static T_2 F_13 ( struct V_18 * V_19 ,
const char * V_20 , T_3 V_21 )
{
char * V_1 ;
int V_7 ;
V_1 = F_4 ( V_20 , V_15 ) ;
if ( ! V_1 )
return - V_16 ;
if ( V_1 [ V_21 - 1 ] == '\n' )
V_1 [ V_21 - 1 ] = '\0' ;
F_14 ( & V_19 -> V_30 ) ;
if ( ! strlen ( V_1 ) ) {
V_7 = F_11 ( V_19 ) ;
if ( V_7 )
goto V_31;
} else {
if ( V_19 -> V_26 ) {
V_7 = - V_32 ;
goto V_31;
}
V_7 = F_15 ( V_1 , & V_19 -> V_28 . V_29 ) ;
if ( V_7 )
goto V_31;
V_19 -> V_26 = V_1 ;
}
F_16 ( & V_19 -> V_30 ) ;
return V_21 ;
V_31:
F_5 ( V_1 ) ;
F_16 ( & V_19 -> V_30 ) ;
return V_7 ;
}
static inline struct V_18 * F_17 ( struct V_33 * V_34 )
{
return F_18 ( F_19 ( V_34 ) , struct V_18 , V_35 ) ;
}
static inline struct V_36 * F_20 ( struct V_33 * V_34 )
{
return F_18 ( F_19 ( V_34 ) , struct V_36 ,
V_35 ) ;
}
static inline struct V_37 * F_21 (
struct V_33 * V_34 )
{
return F_18 ( F_19 ( V_34 ) , struct V_37 ,
V_35 ) ;
}
static inline struct V_38 * F_22 ( struct V_33 * V_34 )
{
return F_18 ( F_19 ( V_34 ) , struct V_38 ,
V_35 ) ;
}
static inline struct V_39 * F_23 (
struct V_33 * V_34 )
{
return F_18 ( F_19 ( V_34 ) ,
struct V_39 , V_35 ) ;
}
static void F_24 ( struct V_33 * V_34 )
{
struct V_18 * V_19 = F_17 ( V_34 ) ;
F_25 ( ! F_26 ( & V_19 -> V_23 . V_40 ) ) ;
F_25 ( ! F_26 ( & V_19 -> V_41 ) ) ;
F_25 ( ! F_26 ( & V_19 -> V_42 ) ) ;
F_5 ( V_19 -> V_28 . V_29 . V_43 ) ;
F_5 ( V_19 ) ;
}
static void F_27 ( struct V_33 * V_34 )
{
struct V_38 * V_44 = F_22 ( V_34 ) ;
F_25 ( ! F_26 ( & V_44 -> V_45 . V_46 ) ) ;
F_28 ( & V_44 -> V_45 . V_47 ) ;
F_5 ( V_44 -> V_45 . V_48 ) ;
F_5 ( V_44 ) ;
}
static int F_29 (
struct V_33 * V_49 ,
struct V_33 * V_50 )
{
struct V_38 * V_44 = F_22 ( V_49 ) ;
struct V_51 * V_23 = V_44 -> V_45 . V_23 ;
struct V_18 * V_19 = F_18 ( V_23 , struct V_18 , V_23 ) ;
struct V_52 * V_35 = F_19 ( V_50 ) ;
struct V_39 * V_53 = F_18 ( V_35 ,
struct V_39 , V_35 ) ;
struct V_39 * V_54 ;
struct V_55 * V_56 ;
int V_7 ;
F_14 ( & V_19 -> V_30 ) ;
F_30 (a_fi, &gi->available_func, cfs_list) {
if ( V_54 == V_53 )
break;
}
if ( V_54 != V_53 ) {
V_7 = - V_8 ;
goto V_57;
}
F_30 (f, &cfg->func_list, list) {
if ( V_56 -> V_53 == V_53 ) {
V_7 = - V_58 ;
goto V_57;
}
}
V_56 = F_31 ( V_53 ) ;
if ( F_32 ( V_56 ) ) {
V_7 = F_33 ( V_56 ) ;
goto V_57;
}
F_34 ( & V_56 -> V_47 , & V_44 -> V_59 ) ;
V_7 = 0 ;
V_57:
F_16 ( & V_19 -> V_30 ) ;
return V_7 ;
}
static int F_35 (
struct V_33 * V_49 ,
struct V_33 * V_50 )
{
struct V_38 * V_44 = F_22 ( V_49 ) ;
struct V_51 * V_23 = V_44 -> V_45 . V_23 ;
struct V_18 * V_19 = F_18 ( V_23 , struct V_18 , V_23 ) ;
struct V_52 * V_35 = F_19 ( V_50 ) ;
struct V_39 * V_53 = F_18 ( V_35 ,
struct V_39 , V_35 ) ;
struct V_55 * V_56 ;
F_14 ( & V_19 -> V_30 ) ;
if ( V_19 -> V_26 )
F_11 ( V_19 ) ;
F_25 ( V_19 -> V_26 ) ;
F_30 (f, &cfg->func_list, list) {
if ( V_56 -> V_53 == V_53 ) {
F_28 ( & V_56 -> V_47 ) ;
F_36 ( V_56 ) ;
F_16 ( & V_19 -> V_30 ) ;
return 0 ;
}
}
F_16 ( & V_19 -> V_30 ) ;
F_37 ( 1 , L_3 ) ;
return 0 ;
}
static T_2 F_38 ( struct V_38 * V_44 ,
char * V_20 )
{
return sprintf ( V_20 , L_4 , V_44 -> V_45 . V_60 ) ;
}
static T_2 F_39 ( struct V_38 * V_44 ,
const char * V_20 , T_3 V_21 )
{
T_1 V_61 ;
int V_7 ;
V_7 = F_2 ( V_20 , 0 , & V_61 ) ;
if ( V_7 )
return V_7 ;
if ( F_40 ( V_61 , 8 ) > 0xff )
return - V_62 ;
V_44 -> V_45 . V_60 = V_61 ;
return V_21 ;
}
static T_2 F_41 ( struct V_38 * V_44 ,
char * V_20 )
{
return sprintf ( V_20 , L_5 , V_44 -> V_45 . V_63 ) ;
}
static T_2 F_42 ( struct V_38 * V_44 ,
const char * V_20 , T_3 V_21 )
{
T_4 V_61 ;
int V_7 ;
V_7 = F_43 ( V_20 , 0 , & V_61 ) ;
if ( V_7 )
return V_7 ;
if ( ! ( V_61 & V_64 ) )
return - V_8 ;
if ( V_61 & ~ ( V_64 | V_65 |
V_66 ) )
return - V_8 ;
V_44 -> V_45 . V_63 = V_61 ;
return V_21 ;
}
static void F_44 ( struct V_51 * V_23 )
{
F_45 ( & V_23 -> V_30 ) ;
F_46 ( & V_23 -> V_40 ) ;
F_46 ( & V_23 -> V_67 ) ;
}
static struct V_52 * F_47 (
struct V_52 * V_35 ,
const char * V_1 )
{
struct V_18 * V_19 ;
struct V_39 * V_53 ;
char V_68 [ V_69 ] ;
char * V_70 ;
char * V_71 ;
int V_7 ;
V_7 = snprintf ( V_68 , V_69 , L_6 , V_1 ) ;
if ( V_7 >= V_69 )
return F_48 ( - V_72 ) ;
V_70 = V_68 ;
V_71 = strchr ( V_70 , '.' ) ;
if ( ! V_71 ) {
F_49 ( L_7 ) ;
return F_48 ( - V_8 ) ;
}
* V_71 = '\0' ;
V_71 ++ ;
V_53 = F_50 ( V_70 ) ;
if ( F_32 ( V_53 ) )
return F_48 ( F_33 ( V_53 ) ) ;
V_7 = F_51 ( & V_53 -> V_35 . V_73 , V_1 ) ;
if ( V_7 ) {
F_52 ( V_53 ) ;
return F_48 ( V_7 ) ;
}
V_19 = F_18 ( V_35 , struct V_18 , V_74 ) ;
F_14 ( & V_19 -> V_30 ) ;
F_34 ( & V_53 -> V_75 , & V_19 -> V_42 ) ;
F_16 ( & V_19 -> V_30 ) ;
return & V_53 -> V_35 ;
}
static void F_53 (
struct V_52 * V_35 ,
struct V_33 * V_34 )
{
struct V_39 * V_53 = F_23 ( V_34 ) ;
struct V_18 * V_19 ;
V_19 = F_18 ( V_35 , struct V_18 , V_74 ) ;
F_14 ( & V_19 -> V_30 ) ;
F_28 ( & V_53 -> V_75 ) ;
F_16 ( & V_19 -> V_30 ) ;
F_54 ( V_34 ) ;
}
static void F_55 ( struct V_33 * V_34 )
{
struct V_37 * V_76 = F_21 ( V_34 ) ;
F_5 ( V_76 -> V_77 ) ;
F_28 ( & V_76 -> V_47 ) ;
F_5 ( V_76 ) ;
}
static struct V_52 * F_56 (
struct V_52 * V_35 ,
const char * V_1 )
{
struct V_18 * V_19 ;
struct V_38 * V_44 ;
char V_68 [ V_69 ] ;
char * V_78 ;
T_4 V_6 ;
int V_7 ;
V_19 = F_18 ( V_35 , struct V_18 , V_79 ) ;
V_7 = snprintf ( V_68 , V_69 , L_6 , V_1 ) ;
if ( V_7 >= V_69 )
return F_48 ( - V_72 ) ;
V_78 = strchr ( V_68 , '.' ) ;
if ( ! V_78 ) {
F_49 ( L_8 ) ;
return F_48 ( - V_8 ) ;
}
* V_78 = '\0' ;
V_78 ++ ;
if ( ! strlen ( V_68 ) )
return F_48 ( - V_8 ) ;
V_7 = F_43 ( V_78 , 0 , & V_6 ) ;
if ( V_7 )
return F_48 ( V_7 ) ;
V_44 = F_57 ( sizeof( * V_44 ) , V_15 ) ;
if ( ! V_44 )
return F_48 ( - V_16 ) ;
V_44 -> V_45 . V_48 = F_4 ( V_68 , V_15 ) ;
if ( ! V_44 -> V_45 . V_48 ) {
V_7 = - V_16 ;
goto V_31;
}
V_44 -> V_45 . V_80 = V_6 ;
V_44 -> V_45 . V_60 = V_81 ;
V_44 -> V_45 . V_63 = V_64 ;
F_46 ( & V_44 -> V_41 ) ;
F_46 ( & V_44 -> V_59 ) ;
V_44 -> V_35 . V_82 = V_44 -> V_82 ;
V_44 -> V_82 [ 0 ] = & V_44 -> V_83 ;
F_58 ( & V_44 -> V_35 , V_1 ,
& V_84 ) ;
F_58 ( & V_44 -> V_83 , L_9 ,
& V_85 ) ;
V_7 = F_59 ( & V_19 -> V_23 , & V_44 -> V_45 ) ;
if ( V_7 )
goto V_31;
return & V_44 -> V_35 ;
V_31:
F_5 ( V_44 -> V_45 . V_48 ) ;
F_5 ( V_44 ) ;
return F_48 ( V_7 ) ;
}
static void F_60 (
struct V_52 * V_35 ,
struct V_33 * V_34 )
{
F_54 ( V_34 ) ;
}
static void F_61 ( struct V_33 * V_34 )
{
struct V_36 * V_86 = F_20 ( V_34 ) ;
F_5 ( V_86 -> V_87 ) ;
F_5 ( V_86 -> V_88 ) ;
F_5 ( V_86 -> V_89 ) ;
F_28 ( & V_86 -> V_47 ) ;
F_5 ( V_86 ) ;
}
static int F_62 ( struct V_51 * V_23 )
{
F_25 ( 1 ) ;
return - V_8 ;
}
static void F_63 ( struct V_18 * V_19 )
{
struct V_90 * V_45 ;
F_30 (c, &gi->cdev.configs, list) {
struct V_55 * V_56 , * V_91 ;
struct V_38 * V_44 ;
V_44 = F_18 ( V_45 , struct V_38 , V_45 ) ;
F_64 (f, tmp, &c->functions, list) {
F_65 ( & V_56 -> V_47 , & V_44 -> V_59 ) ;
if ( V_56 -> V_92 ) {
F_66 ( & V_19 -> V_23 . V_93 -> V_94 , L_10
L_11 , V_56 -> V_1 , V_56 ) ;
V_56 -> V_92 ( V_45 , V_56 ) ;
}
}
V_45 -> V_95 = 0 ;
V_45 -> V_96 = 0 ;
V_45 -> V_97 = 0 ;
V_45 -> V_98 = 0 ;
}
}
static int F_67 ( struct V_99 * V_93 ,
struct V_100 * V_101 )
{
struct V_102 * V_28 = F_68 ( V_101 ) ;
struct V_18 * V_19 = F_18 ( V_28 ,
struct V_18 , V_28 ) ;
struct V_51 * V_23 = & V_19 -> V_23 ;
struct V_90 * V_45 ;
struct V_103 * V_10 ;
unsigned V_104 ;
int V_7 ;
V_23 -> V_93 = V_93 ;
F_69 ( V_93 , V_23 ) ;
V_7 = F_70 ( V_28 , V_23 ) ;
if ( V_7 )
return V_7 ;
V_7 = - V_8 ;
if ( F_26 ( & V_19 -> V_23 . V_40 ) ) {
F_49 ( L_12 ,
V_19 -> V_28 . V_1 ) ;
goto V_105;
}
F_30 (c, &gi->cdev.configs, list) {
struct V_38 * V_44 ;
V_44 = F_18 ( V_45 , struct V_38 , V_45 ) ;
if ( F_26 ( & V_44 -> V_59 ) ) {
F_49 ( L_13 ,
V_45 -> V_48 , V_45 -> V_80 ,
V_19 -> V_28 . V_1 ) ;
goto V_105;
}
}
if ( ! F_26 ( & V_19 -> V_41 ) ) {
struct V_36 * V_86 ;
V_104 = 0 ;
F_30 (gs, &gi->string_list, list) {
V_19 -> V_67 [ V_104 ] = & V_86 -> V_3 ;
V_86 -> V_3 . V_106 = V_86 -> V_106 ;
V_86 -> V_106 [ V_107 ] . V_10 =
V_86 -> V_87 ;
V_86 -> V_106 [ V_108 ] . V_10 = V_86 -> V_88 ;
V_86 -> V_106 [ V_109 ] . V_10 = V_86 -> V_89 ;
V_104 ++ ;
}
V_19 -> V_67 [ V_104 ] = NULL ;
V_10 = F_71 ( & V_19 -> V_23 , V_19 -> V_67 ,
V_110 ) ;
if ( F_32 ( V_10 ) ) {
V_7 = F_33 ( V_10 ) ;
goto V_105;
}
V_19 -> V_23 . V_24 . V_111 = V_10 [ V_107 ] . V_112 ;
V_19 -> V_23 . V_24 . V_113 = V_10 [ V_108 ] . V_112 ;
V_19 -> V_23 . V_24 . V_114 = V_10 [ V_109 ] . V_112 ;
}
F_30 (c, &gi->cdev.configs, list) {
struct V_38 * V_44 ;
struct V_55 * V_56 ;
struct V_55 * V_91 ;
struct V_37 * V_76 ;
V_44 = F_18 ( V_45 , struct V_38 , V_45 ) ;
if ( ! F_26 ( & V_44 -> V_41 ) ) {
V_104 = 0 ;
F_30 (cn, &cfg->string_list, list) {
V_44 -> V_67 [ V_104 ] = & V_76 -> V_3 ;
V_76 -> V_3 . V_106 = & V_76 -> V_106 ;
V_76 -> V_106 . V_10 = V_76 -> V_77 ;
V_104 ++ ;
}
V_44 -> V_67 [ V_104 ] = NULL ;
V_10 = F_71 ( & V_19 -> V_23 , V_44 -> V_67 , 1 ) ;
if ( F_32 ( V_10 ) ) {
V_7 = F_33 ( V_10 ) ;
goto V_105;
}
V_45 -> V_115 = V_10 [ 0 ] . V_112 ;
}
F_64 (f, tmp, &cfg->func_list, list) {
F_28 ( & V_56 -> V_47 ) ;
V_7 = F_72 ( V_45 , V_56 ) ;
if ( V_7 ) {
F_73 ( & V_56 -> V_47 , & V_44 -> V_59 ) ;
goto V_116;
}
}
F_74 ( V_23 -> V_93 ) ;
}
F_74 ( V_23 -> V_93 ) ;
return 0 ;
V_116:
F_63 ( V_19 ) ;
V_105:
F_75 ( V_23 ) ;
return V_7 ;
}
static void F_76 ( struct V_99 * V_93 )
{
struct V_51 * V_23 ;
struct V_18 * V_19 ;
V_23 = F_77 ( V_93 ) ;
V_19 = F_18 ( V_23 , struct V_18 , V_23 ) ;
F_63 ( V_19 ) ;
F_75 ( V_23 ) ;
F_74 ( V_23 -> V_93 ) ;
V_23 -> V_93 = NULL ;
F_69 ( V_93 , NULL ) ;
}
static struct V_52 * F_78 (
struct V_52 * V_35 ,
const char * V_1 )
{
struct V_18 * V_19 ;
V_19 = F_57 ( sizeof( * V_19 ) , V_15 ) ;
if ( ! V_19 )
return F_48 ( - V_16 ) ;
V_19 -> V_35 . V_82 = V_19 -> V_82 ;
V_19 -> V_35 . V_82 [ 0 ] = & V_19 -> V_74 ;
V_19 -> V_35 . V_82 [ 1 ] = & V_19 -> V_79 ;
V_19 -> V_35 . V_82 [ 2 ] = & V_19 -> V_83 ;
F_58 ( & V_19 -> V_74 , L_14 ,
& V_117 ) ;
F_58 ( & V_19 -> V_79 , L_15 ,
& V_118 ) ;
F_58 ( & V_19 -> V_83 , L_9 ,
& V_119 ) ;
V_19 -> V_28 . V_120 = F_62 ;
V_19 -> V_28 . V_92 = F_62 ;
V_19 -> V_28 . V_121 = NULL ;
V_19 -> V_28 . V_122 = NULL ;
V_19 -> V_28 . V_123 = V_124 ;
F_79 ( & V_19 -> V_30 ) ;
F_46 ( & V_19 -> V_41 ) ;
F_46 ( & V_19 -> V_42 ) ;
F_44 ( & V_19 -> V_23 ) ;
V_19 -> V_23 . V_24 . V_125 = V_126 ;
V_19 -> V_23 . V_24 . V_127 = V_128 ;
V_19 -> V_23 . V_24 . V_22 = F_8 ( F_80 () ) ;
V_19 -> V_28 . V_29 = V_129 ;
V_19 -> V_28 . V_29 . V_43 = F_4 ( V_1 , V_15 ) ;
V_19 -> V_28 . V_1 = V_19 -> V_28 . V_29 . V_43 ;
if ( ! V_19 -> V_28 . V_29 . V_43 )
goto V_31;
#ifdef F_81
V_19 -> V_130 . V_125 = sizeof( struct V_131 ) ;
V_19 -> V_130 . V_127 = V_132 ;
V_19 -> V_130 . V_63 = V_133 | V_134 ;
#endif
F_58 ( & V_19 -> V_35 , V_1 ,
& V_135 ) ;
return & V_19 -> V_35 ;
V_31:
F_5 ( V_19 ) ;
return F_48 ( - V_16 ) ;
}
static void F_82 ( struct V_52 * V_35 , struct V_33 * V_34 )
{
F_54 ( V_34 ) ;
}
static int T_5 F_83 ( void )
{
int V_7 ;
F_84 ( & V_136 . V_137 ) ;
V_7 = F_85 ( & V_136 ) ;
return V_7 ;
}
static void T_6 F_86 ( void )
{
F_87 ( & V_136 ) ;
}
