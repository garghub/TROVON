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
static inline struct V_10 * F_3 ( struct V_11 * V_12 )
{
return F_4 ( F_5 ( V_12 ) , struct V_10 , V_13 ) ;
}
static inline struct V_14 * F_6 ( struct V_11 * V_12 )
{
return F_4 ( F_5 ( V_12 ) , struct V_14 ,
V_13 ) ;
}
static int F_7 ( const char * V_15 , char * * V_16 )
{
int V_7 ;
char * V_17 ;
char * V_18 = * V_16 ;
V_7 = strlen ( V_15 ) ;
if ( V_7 > 126 )
return - V_19 ;
V_17 = F_8 ( V_15 , V_20 ) ;
if ( ! V_17 )
return - V_21 ;
if ( V_17 [ V_7 - 1 ] == '\n' )
V_17 [ V_7 - 1 ] = '\0' ;
F_9 ( V_18 ) ;
* V_16 = V_17 ;
return 0 ;
}
static T_2 F_10 ( T_1 V_22 )
{
if ( ( V_22 & 0xf ) > 9 )
return - V_8 ;
if ( ( ( V_22 >> 4 ) & 0xf ) > 9 )
return - V_8 ;
if ( ( ( V_22 >> 8 ) & 0xf ) > 9 )
return - V_8 ;
if ( ( ( V_22 >> 12 ) & 0xf ) > 9 )
return - V_8 ;
return 0 ;
}
static T_2 F_11 ( struct V_11 * V_12 ,
const char * V_23 , T_3 V_24 )
{
T_1 V_25 ;
int V_7 ;
V_7 = F_2 ( V_23 , 0 , & V_25 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_10 ( V_25 ) ;
if ( V_7 )
return V_7 ;
F_3 ( V_12 ) -> V_26 . V_27 . V_25 = F_12 ( V_25 ) ;
return V_24 ;
}
static T_2 F_13 ( struct V_11 * V_12 ,
const char * V_23 , T_3 V_24 )
{
T_1 V_28 ;
int V_7 ;
V_7 = F_2 ( V_23 , 0 , & V_28 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_10 ( V_28 ) ;
if ( V_7 )
return V_7 ;
F_3 ( V_12 ) -> V_26 . V_27 . V_28 = F_12 ( V_28 ) ;
return V_24 ;
}
static T_2 F_14 ( struct V_11 * V_12 , char * V_23 )
{
char * V_29 = F_3 ( V_12 ) -> V_30 . V_31 . V_29 ;
return sprintf ( V_23 , L_1 , V_29 ? : L_2 ) ;
}
static int F_15 ( struct V_10 * V_32 )
{
int V_7 ;
if ( ! V_32 -> V_30 . V_31 . V_29 )
return - V_33 ;
V_7 = F_16 ( & V_32 -> V_30 . V_31 ) ;
if ( V_7 )
return V_7 ;
F_9 ( V_32 -> V_30 . V_31 . V_29 ) ;
V_32 -> V_30 . V_31 . V_29 = NULL ;
return 0 ;
}
static T_2 F_17 ( struct V_11 * V_12 ,
const char * V_23 , T_3 V_24 )
{
struct V_10 * V_32 = F_3 ( V_12 ) ;
char * V_1 ;
int V_7 ;
V_1 = F_8 ( V_23 , V_20 ) ;
if ( ! V_1 )
return - V_21 ;
if ( V_1 [ V_24 - 1 ] == '\n' )
V_1 [ V_24 - 1 ] = '\0' ;
F_18 ( & V_32 -> V_34 ) ;
if ( ! strlen ( V_1 ) ) {
V_7 = F_15 ( V_32 ) ;
if ( V_7 )
goto V_35;
F_9 ( V_1 ) ;
} else {
if ( V_32 -> V_30 . V_31 . V_29 ) {
V_7 = - V_36 ;
goto V_35;
}
V_32 -> V_30 . V_31 . V_29 = V_1 ;
V_7 = F_19 ( & V_32 -> V_30 . V_31 ) ;
if ( V_7 ) {
V_32 -> V_30 . V_31 . V_29 = NULL ;
goto V_35;
}
}
F_20 ( & V_32 -> V_34 ) ;
return V_24 ;
V_35:
F_9 ( V_1 ) ;
F_20 ( & V_32 -> V_34 ) ;
return V_7 ;
}
static inline struct V_37 * F_21 ( struct V_11 * V_12 )
{
return F_4 ( F_5 ( V_12 ) , struct V_37 ,
V_13 ) ;
}
static inline struct V_38 * F_22 (
struct V_11 * V_12 )
{
return F_4 ( F_5 ( V_12 ) , struct V_38 ,
V_13 ) ;
}
static inline struct V_39 * F_23 (
struct V_11 * V_12 )
{
return F_4 ( F_5 ( V_12 ) ,
struct V_39 , V_13 ) ;
}
static void F_24 ( struct V_11 * V_12 )
{
struct V_10 * V_32 = F_3 ( V_12 ) ;
F_25 ( ! F_26 ( & V_32 -> V_26 . V_40 ) ) ;
F_25 ( ! F_26 ( & V_32 -> V_41 ) ) ;
F_25 ( ! F_26 ( & V_32 -> V_42 ) ) ;
F_9 ( V_32 -> V_30 . V_31 . V_43 ) ;
F_9 ( V_32 ) ;
}
static void F_27 ( struct V_11 * V_12 )
{
struct V_14 * V_44 = F_6 ( V_12 ) ;
F_25 ( ! F_26 ( & V_44 -> V_45 . V_46 ) ) ;
F_28 ( & V_44 -> V_45 . V_47 ) ;
F_9 ( V_44 -> V_45 . V_48 ) ;
F_9 ( V_44 ) ;
}
static int F_29 (
struct V_11 * V_49 ,
struct V_11 * V_50 )
{
struct V_14 * V_44 = F_6 ( V_49 ) ;
struct V_51 * V_26 = V_44 -> V_45 . V_26 ;
struct V_10 * V_32 = F_4 ( V_26 , struct V_10 , V_26 ) ;
struct V_52 * V_13 = F_5 ( V_50 ) ;
struct V_39 * V_53 = F_4 ( V_13 ,
struct V_39 , V_13 ) ;
struct V_39 * V_54 ;
struct V_55 * V_56 ;
int V_7 ;
F_18 ( & V_32 -> V_34 ) ;
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
F_20 ( & V_32 -> V_34 ) ;
return V_7 ;
}
static void F_35 (
struct V_11 * V_49 ,
struct V_11 * V_50 )
{
struct V_14 * V_44 = F_6 ( V_49 ) ;
struct V_51 * V_26 = V_44 -> V_45 . V_26 ;
struct V_10 * V_32 = F_4 ( V_26 , struct V_10 , V_26 ) ;
struct V_52 * V_13 = F_5 ( V_50 ) ;
struct V_39 * V_53 = F_4 ( V_13 ,
struct V_39 , V_13 ) ;
struct V_55 * V_56 ;
F_18 ( & V_32 -> V_34 ) ;
if ( V_32 -> V_30 . V_31 . V_29 )
F_15 ( V_32 ) ;
F_25 ( V_32 -> V_30 . V_31 . V_29 ) ;
F_30 (f, &cfg->func_list, list) {
if ( V_56 -> V_53 == V_53 ) {
F_28 ( & V_56 -> V_47 ) ;
F_36 ( V_56 ) ;
F_20 ( & V_32 -> V_34 ) ;
return;
}
}
F_20 ( & V_32 -> V_34 ) ;
F_37 ( 1 , L_3 ) ;
}
static T_2 F_38 ( struct V_11 * V_12 ,
char * V_23 )
{
return sprintf ( V_23 , L_4 , F_6 ( V_12 ) -> V_45 . V_60 ) ;
}
static T_2 F_39 ( struct V_11 * V_12 ,
const char * V_23 , T_3 V_24 )
{
T_1 V_61 ;
int V_7 ;
V_7 = F_2 ( V_23 , 0 , & V_61 ) ;
if ( V_7 )
return V_7 ;
if ( F_40 ( V_61 , 8 ) > 0xff )
return - V_62 ;
F_6 ( V_12 ) -> V_45 . V_60 = V_61 ;
return V_24 ;
}
static T_2 F_41 ( struct V_11 * V_12 ,
char * V_23 )
{
return sprintf ( V_23 , L_5 ,
F_6 ( V_12 ) -> V_45 . V_63 ) ;
}
static T_2 F_42 ( struct V_11 * V_12 ,
const char * V_23 , T_3 V_24 )
{
T_4 V_61 ;
int V_7 ;
V_7 = F_43 ( V_23 , 0 , & V_61 ) ;
if ( V_7 )
return V_7 ;
if ( ! ( V_61 & V_64 ) )
return - V_8 ;
if ( V_61 & ~ ( V_64 | V_65 |
V_66 ) )
return - V_8 ;
F_6 ( V_12 ) -> V_45 . V_63 = V_61 ;
return V_24 ;
}
static void F_44 ( struct V_51 * V_26 )
{
F_45 ( & V_26 -> V_34 ) ;
F_46 ( & V_26 -> V_40 ) ;
F_46 ( & V_26 -> V_67 ) ;
}
static struct V_52 * F_47 (
struct V_52 * V_13 ,
const char * V_1 )
{
struct V_10 * V_32 ;
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
return F_51 ( V_53 ) ;
V_7 = F_52 ( & V_53 -> V_13 . V_73 , L_6 , V_1 ) ;
if ( V_7 ) {
F_53 ( V_53 ) ;
return F_48 ( V_7 ) ;
}
if ( V_53 -> V_74 ) {
V_7 = V_53 -> V_74 ( V_53 , V_71 ) ;
if ( V_7 ) {
F_53 ( V_53 ) ;
return F_48 ( V_7 ) ;
}
}
V_32 = F_4 ( V_13 , struct V_10 , V_75 ) ;
F_18 ( & V_32 -> V_34 ) ;
F_34 ( & V_53 -> V_76 , & V_32 -> V_42 ) ;
F_20 ( & V_32 -> V_34 ) ;
return & V_53 -> V_13 ;
}
static void F_54 (
struct V_52 * V_13 ,
struct V_11 * V_12 )
{
struct V_39 * V_53 = F_23 ( V_12 ) ;
struct V_10 * V_32 ;
V_32 = F_4 ( V_13 , struct V_10 , V_75 ) ;
F_18 ( & V_32 -> V_34 ) ;
F_28 ( & V_53 -> V_76 ) ;
F_20 ( & V_32 -> V_34 ) ;
F_55 ( V_12 ) ;
}
static void F_56 ( struct V_11 * V_12 )
{
struct V_38 * V_77 = F_22 ( V_12 ) ;
F_9 ( V_77 -> V_78 ) ;
F_28 ( & V_77 -> V_47 ) ;
F_9 ( V_77 ) ;
}
static struct V_52 * F_57 (
struct V_52 * V_13 ,
const char * V_1 )
{
struct V_10 * V_32 ;
struct V_14 * V_44 ;
char V_68 [ V_69 ] ;
char * V_79 ;
T_4 V_6 ;
int V_7 ;
V_32 = F_4 ( V_13 , struct V_10 , V_80 ) ;
V_7 = snprintf ( V_68 , V_69 , L_6 , V_1 ) ;
if ( V_7 >= V_69 )
return F_48 ( - V_72 ) ;
V_79 = strchr ( V_68 , '.' ) ;
if ( ! V_79 ) {
F_49 ( L_8 ) ;
return F_48 ( - V_8 ) ;
}
* V_79 = '\0' ;
V_79 ++ ;
if ( ! strlen ( V_68 ) )
return F_48 ( - V_8 ) ;
V_7 = F_43 ( V_79 , 0 , & V_6 ) ;
if ( V_7 )
return F_48 ( V_7 ) ;
V_44 = F_58 ( sizeof( * V_44 ) , V_20 ) ;
if ( ! V_44 )
return F_48 ( - V_21 ) ;
V_44 -> V_45 . V_48 = F_8 ( V_68 , V_20 ) ;
if ( ! V_44 -> V_45 . V_48 ) {
V_7 = - V_21 ;
goto V_35;
}
V_44 -> V_45 . V_81 = V_6 ;
V_44 -> V_45 . V_60 = V_82 ;
V_44 -> V_45 . V_63 = V_64 ;
F_46 ( & V_44 -> V_41 ) ;
F_46 ( & V_44 -> V_59 ) ;
F_59 ( & V_44 -> V_13 , V_1 ,
& V_83 ) ;
F_59 ( & V_44 -> V_84 , L_9 ,
& V_85 ) ;
F_60 ( & V_44 -> V_84 , & V_44 -> V_13 ) ;
V_7 = F_61 ( & V_32 -> V_26 , & V_44 -> V_45 ) ;
if ( V_7 )
goto V_35;
return & V_44 -> V_13 ;
V_35:
F_9 ( V_44 -> V_45 . V_48 ) ;
F_9 ( V_44 ) ;
return F_48 ( V_7 ) ;
}
static void F_62 (
struct V_52 * V_13 ,
struct V_11 * V_12 )
{
F_55 ( V_12 ) ;
}
static void F_63 ( struct V_11 * V_12 )
{
struct V_37 * V_86 = F_21 ( V_12 ) ;
F_9 ( V_86 -> V_87 ) ;
F_9 ( V_86 -> V_88 ) ;
F_9 ( V_86 -> V_89 ) ;
F_28 ( & V_86 -> V_47 ) ;
F_9 ( V_86 ) ;
}
static inline struct V_90 * F_64 ( struct V_11 * V_12 )
{
return F_4 ( F_5 ( V_12 ) , struct V_90 , V_13 ) ;
}
static inline struct V_10 * F_65 (
struct V_11 * V_12 )
{
return F_3 ( F_64 ( V_12 ) -> V_13 . V_73 . V_91 ) ;
}
static T_2 F_66 ( struct V_11 * V_12 , char * V_23 )
{
return sprintf ( V_23 , L_10 ,
F_65 ( V_12 ) -> V_92 ) ;
}
static T_2 F_67 ( struct V_11 * V_12 , const char * V_23 ,
T_3 V_24 )
{
struct V_10 * V_32 = F_65 ( V_12 ) ;
int V_7 ;
bool V_93 ;
F_18 ( & V_32 -> V_34 ) ;
V_7 = F_68 ( V_23 , & V_93 ) ;
if ( ! V_7 ) {
V_32 -> V_92 = V_93 ;
V_7 = V_24 ;
}
F_20 ( & V_32 -> V_34 ) ;
return V_7 ;
}
static T_2 F_69 ( struct V_11 * V_12 , char * V_23 )
{
return sprintf ( V_23 , L_5 ,
F_65 ( V_12 ) -> V_94 ) ;
}
static T_2 F_70 ( struct V_11 * V_12 ,
const char * V_23 , T_3 V_24 )
{
struct V_10 * V_32 = F_65 ( V_12 ) ;
int V_7 ;
T_4 V_94 ;
F_18 ( & V_32 -> V_34 ) ;
V_7 = F_43 ( V_23 , 0 , & V_94 ) ;
if ( ! V_7 ) {
V_32 -> V_94 = V_94 ;
V_7 = V_24 ;
}
F_20 ( & V_32 -> V_34 ) ;
return V_7 ;
}
static T_2 F_71 ( struct V_11 * V_12 , char * V_23 )
{
struct V_10 * V_32 = F_65 ( V_12 ) ;
int V_95 ;
V_95 = F_72 ( ( V_96 * ) V_32 -> V_97 , V_98 ,
V_99 , V_23 , V_100 - 1 ) ;
V_23 [ V_95 ++ ] = '\n' ;
return V_95 ;
}
static T_2 F_73 ( struct V_11 * V_12 , const char * V_23 ,
T_3 V_24 )
{
struct V_10 * V_32 = F_65 ( V_12 ) ;
int V_95 , V_101 ;
V_101 = F_74 ( ( int ) V_24 , V_98 >> 1 ) ;
if ( V_23 [ V_101 - 1 ] == '\n' )
-- V_101 ;
F_18 ( & V_32 -> V_34 ) ;
V_95 = F_75 ( V_23 , V_101 ,
V_99 , ( V_96 * ) V_32 -> V_97 ,
V_98 ) ;
if ( V_95 > 0 )
V_95 = V_24 ;
F_20 ( & V_32 -> V_34 ) ;
return V_95 ;
}
static void F_76 ( struct V_11 * V_12 )
{
struct V_90 * V_90 = F_64 ( V_12 ) ;
F_9 ( V_90 ) ;
}
static int F_77 ( struct V_11 * V_102 ,
struct V_11 * V_49 )
{
struct V_10 * V_32 = F_4 ( F_5 ( V_102 ) ,
struct V_10 , V_103 ) ;
struct V_51 * V_26 = & V_32 -> V_26 ;
struct V_14 * V_104 =
F_4 ( F_5 ( V_49 ) ,
struct V_14 , V_13 ) ;
struct V_105 * V_45 ;
int V_7 ;
F_18 ( & V_32 -> V_34 ) ;
F_30 (c, &cdev->configs, list) {
if ( V_45 == & V_104 -> V_45 )
break;
}
if ( V_45 != & V_104 -> V_45 ) {
V_7 = - V_8 ;
goto V_57;
}
if ( V_26 -> V_106 ) {
V_7 = - V_36 ;
goto V_57;
}
V_26 -> V_106 = & V_104 -> V_45 ;
V_7 = 0 ;
V_57:
F_20 ( & V_32 -> V_34 ) ;
return V_7 ;
}
static void F_78 ( struct V_11 * V_102 ,
struct V_11 * V_49 )
{
struct V_10 * V_32 = F_4 ( F_5 ( V_102 ) ,
struct V_10 , V_103 ) ;
struct V_51 * V_26 = & V_32 -> V_26 ;
F_18 ( & V_32 -> V_34 ) ;
if ( V_32 -> V_30 . V_31 . V_29 )
F_15 ( V_32 ) ;
V_26 -> V_106 = NULL ;
F_25 ( V_32 -> V_30 . V_31 . V_29 ) ;
F_20 ( & V_32 -> V_34 ) ;
}
static inline struct V_107
* F_79 ( struct V_11 * V_12 )
{
return F_4 ( V_12 , struct V_107 , V_12 ) ;
}
static T_2 F_80 ( struct V_11 * V_12 , char * V_23 )
{
return sprintf ( V_23 , L_10 , F_79 ( V_12 ) -> type ) ;
}
static T_2 F_81 ( struct V_11 * V_12 ,
const char * V_23 , T_3 V_24 )
{
struct V_107 * V_108 = F_79 ( V_12 ) ;
struct V_109 * V_27 = F_82 ( V_108 -> V_12 . V_91 ) ;
T_4 type ;
int V_7 ;
if ( V_27 -> V_110 )
F_18 ( V_27 -> V_110 ) ;
V_7 = F_43 ( V_23 , 0 , & type ) ;
if ( V_7 )
goto V_111;
if ( type < V_112 || type > V_113 ) {
V_7 = - V_8 ;
goto V_111;
}
if ( ( V_108 -> type == V_114 ||
V_108 -> type == V_115 ||
V_108 -> type == V_116 ) &&
( type == V_112 ||
type == V_117 ||
type == V_118 ) )
V_108 -> V_119 <<= 1 ;
else if ( ( V_108 -> type == V_112 ||
V_108 -> type == V_117 ||
V_108 -> type == V_118 ) &&
( type == V_114 ||
type == V_115 ||
type == V_116 ) )
V_108 -> V_119 >>= 1 ;
V_108 -> type = type ;
V_7 = V_24 ;
V_111:
if ( V_27 -> V_110 )
F_20 ( V_27 -> V_110 ) ;
return V_7 ;
}
static T_2 F_83 ( struct V_11 * V_12 , char * V_23 )
{
struct V_107 * V_108 = F_79 ( V_12 ) ;
int V_24 = V_108 -> V_119 ;
if ( V_108 -> type == V_112 ||
V_108 -> type == V_117 ||
V_108 -> type == V_118 )
V_24 >>= 1 ;
memcpy ( V_23 , V_108 -> V_120 , V_24 ) ;
return V_24 ;
}
static T_2 F_84 ( struct V_11 * V_12 ,
const char * V_23 , T_3 V_24 )
{
struct V_107 * V_108 = F_79 ( V_12 ) ;
struct V_109 * V_27 = F_82 ( V_108 -> V_12 . V_91 ) ;
char * V_121 ;
T_3 V_122 = V_24 ;
if ( V_23 [ V_24 - 1 ] == '\n' || V_23 [ V_24 - 1 ] == '\0' )
-- V_24 ;
V_121 = F_85 ( V_23 , V_24 , V_20 ) ;
if ( ! V_121 )
return - V_21 ;
if ( V_27 -> V_110 )
F_18 ( V_27 -> V_110 ) ;
F_9 ( V_108 -> V_120 ) ;
V_108 -> V_120 = V_121 ;
V_27 -> V_123 -= V_108 -> V_119 ;
V_108 -> V_119 = V_24 ;
V_27 -> V_123 += V_108 -> V_119 ;
if ( V_108 -> type == V_112 ||
V_108 -> type == V_117 ||
V_108 -> type == V_118 ) {
V_27 -> V_123 -= V_108 -> V_119 ;
V_108 -> V_119 <<= 1 ;
V_108 -> V_119 += 2 ;
V_27 -> V_123 += V_108 -> V_119 ;
}
if ( V_27 -> V_110 )
F_20 ( V_27 -> V_110 ) ;
return V_122 ;
}
static void F_86 ( struct V_11 * V_12 )
{
struct V_107 * V_108 = F_79 ( V_12 ) ;
F_9 ( V_108 ) ;
}
static struct V_11 * F_87 (
struct V_52 * V_13 ,
const char * V_1 )
{
struct V_107 * V_108 ;
struct V_124 * V_125 ;
struct V_109 * V_27 ;
char * V_126 ;
F_88 ( V_127 ) ;
F_89 ( V_127 , struct V_107 , V_108 , 1 ) ;
F_89 ( V_127 , struct V_124 , V_125 , 1 ) ;
V_126 = F_58 ( F_90 ( V_127 ) , V_20 ) ;
if ( ! V_126 )
return F_48 ( - V_21 ) ;
V_108 = F_91 ( V_126 , V_127 , V_108 ) ;
V_125 = F_91 ( V_126 , V_127 , V_125 ) ;
V_27 = F_4 ( V_13 , struct V_109 , V_13 ) ;
V_125 -> V_128 = & V_129 ;
V_125 -> V_130 = V_131 ;
V_125 -> V_132 = V_27 -> V_133 ;
F_92 ( & V_108 -> V_12 , V_1 , V_125 ) ;
V_108 -> V_1 = F_8 ( V_1 , V_20 ) ;
if ( ! V_108 -> V_1 ) {
F_9 ( V_126 ) ;
return F_48 ( - V_21 ) ;
}
V_27 -> V_123 += 14 ;
V_108 -> V_134 = 2 * strlen ( V_108 -> V_1 ) + 2 ;
if ( V_27 -> V_110 )
F_18 ( V_27 -> V_110 ) ;
V_27 -> V_123 += V_108 -> V_134 ;
F_34 ( & V_108 -> V_135 , & V_27 -> V_108 ) ;
++ V_27 -> V_136 ;
if ( V_27 -> V_110 )
F_20 ( V_27 -> V_110 ) ;
return & V_108 -> V_12 ;
}
static void F_93 ( struct V_52 * V_13 , struct V_11 * V_12 )
{
struct V_107 * V_108 = F_79 ( V_12 ) ;
struct V_109 * V_27 = F_82 ( & V_13 -> V_73 ) ;
if ( V_27 -> V_110 )
F_18 ( V_27 -> V_110 ) ;
F_28 ( & V_108 -> V_135 ) ;
-- V_27 -> V_136 ;
F_9 ( V_108 -> V_1 ) ;
V_27 -> V_123 -= ( V_108 -> V_134 + V_108 -> V_119 + 14 ) ;
if ( V_27 -> V_110 )
F_20 ( V_27 -> V_110 ) ;
F_55 ( V_12 ) ;
}
static T_2 F_94 ( struct V_11 * V_12 ,
char * V_23 )
{
memcpy ( V_23 , F_82 ( V_12 ) -> V_137 , 8 ) ;
return 8 ;
}
static T_2 F_95 ( struct V_11 * V_12 ,
const char * V_23 , T_3 V_24 )
{
struct V_109 * V_27 = F_82 ( V_12 ) ;
int V_101 ;
V_101 = F_96 ( int , 8 , V_24 ) ;
if ( V_23 [ V_101 - 1 ] == '\n' )
-- V_101 ;
if ( V_27 -> V_110 )
F_18 ( V_27 -> V_110 ) ;
memcpy ( V_27 -> V_137 , V_23 , V_101 ) ;
if ( V_27 -> V_110 )
F_20 ( V_27 -> V_110 ) ;
return V_24 ;
}
static T_2 F_97 ( struct V_11 * V_12 ,
char * V_23 )
{
memcpy ( V_23 , F_82 ( V_12 ) -> V_137 + 8 , 8 ) ;
return 8 ;
}
static T_2 F_98 ( struct V_11 * V_12 ,
const char * V_23 , T_3 V_24 )
{
struct V_109 * V_27 = F_82 ( V_12 ) ;
int V_101 ;
V_101 = F_96 ( int , 8 , V_24 ) ;
if ( V_23 [ V_101 - 1 ] == '\n' )
-- V_101 ;
if ( V_27 -> V_110 )
F_18 ( V_27 -> V_110 ) ;
memcpy ( V_27 -> V_137 + 8 , V_23 , V_101 ) ;
if ( V_27 -> V_110 )
F_20 ( V_27 -> V_110 ) ;
return V_24 ;
}
struct V_52 * F_99 (
struct V_52 * V_138 ,
int V_139 ,
struct V_109 * * V_27 ,
char * * V_140 ,
struct V_141 * V_133 )
{
struct V_52 * V_103 ;
struct V_124 * V_142 , * V_143 ;
F_88 ( V_127 ) ;
F_89 ( V_127 , struct V_52 , V_103 , 1 ) ;
F_89 ( V_127 , struct V_124 , V_142 , 1 ) ;
F_89 ( V_127 , struct V_124 , V_143 , 1 ) ;
char * V_126 = F_58 ( F_90 ( V_127 ) , V_20 ) ;
if ( ! V_126 )
return F_48 ( - V_21 ) ;
V_103 = F_91 ( V_126 , V_127 , V_103 ) ;
V_142 = F_91 ( V_126 , V_127 , V_142 ) ;
V_143 = F_91 ( V_126 , V_127 , V_143 ) ;
V_142 -> V_132 = V_133 ;
F_59 ( V_103 , L_11 , V_142 ) ;
F_60 ( V_103 , V_138 ) ;
V_143 -> V_144 = & V_145 ;
V_143 -> V_130 = V_146 ;
V_143 -> V_132 = V_133 ;
while ( V_139 -- ) {
struct V_109 * V_147 ;
V_147 = V_27 [ V_139 ] ;
V_147 -> V_133 = V_133 ;
F_59 ( & V_147 -> V_13 , L_2 , V_143 ) ;
F_52 ( & V_147 -> V_13 . V_73 , L_12 ,
V_140 [ V_139 ] ) ;
F_60 ( & V_147 -> V_13 , V_103 ) ;
}
return V_103 ;
}
static int F_100 ( struct V_51 * V_26 )
{
F_25 ( 1 ) ;
return - V_8 ;
}
static void F_101 ( struct V_10 * V_32 )
{
struct V_105 * V_45 ;
F_30 (c, &gi->cdev.configs, list) {
struct V_55 * V_56 , * V_148 ;
struct V_14 * V_44 ;
V_44 = F_4 ( V_45 , struct V_14 , V_45 ) ;
F_102 (f, tmp, &c->functions, list) {
F_103 ( & V_56 -> V_47 , & V_44 -> V_59 ) ;
if ( V_56 -> V_149 ) {
F_104 ( & V_32 -> V_26 . V_150 -> V_151 ,
L_13 ,
V_56 -> V_1 , V_56 ) ;
V_56 -> V_149 ( V_45 , V_56 ) ;
}
}
V_45 -> V_152 = 0 ;
memset ( V_45 -> V_153 , 0 , sizeof( V_45 -> V_153 ) ) ;
V_45 -> V_154 = 0 ;
V_45 -> V_155 = 0 ;
V_45 -> V_156 = 0 ;
V_45 -> V_157 = 0 ;
}
}
static int F_105 ( struct V_158 * V_150 ,
struct V_159 * V_160 )
{
struct V_161 * V_30 = F_106 ( V_160 ) ;
struct V_10 * V_32 = F_4 ( V_30 ,
struct V_10 , V_30 ) ;
struct V_51 * V_26 = & V_32 -> V_26 ;
struct V_105 * V_45 ;
struct V_162 * V_15 ;
unsigned V_163 ;
int V_7 ;
V_26 -> V_150 = V_150 ;
F_107 ( V_150 , V_26 ) ;
V_7 = F_108 ( V_30 , V_26 ) ;
if ( V_7 )
return V_7 ;
V_7 = - V_8 ;
if ( F_26 ( & V_32 -> V_26 . V_40 ) ) {
F_49 ( L_14 ,
V_32 -> V_30 . V_1 ) ;
goto V_164;
}
F_30 (c, &gi->cdev.configs, list) {
struct V_14 * V_44 ;
V_44 = F_4 ( V_45 , struct V_14 , V_45 ) ;
if ( F_26 ( & V_44 -> V_59 ) ) {
F_49 ( L_15 ,
V_45 -> V_48 , V_45 -> V_81 ,
V_32 -> V_30 . V_1 ) ;
goto V_164;
}
}
if ( ! F_26 ( & V_32 -> V_41 ) ) {
struct V_37 * V_86 ;
V_163 = 0 ;
F_30 (gs, &gi->string_list, list) {
V_32 -> V_67 [ V_163 ] = & V_86 -> V_3 ;
V_86 -> V_3 . V_165 = V_86 -> V_165 ;
V_86 -> V_165 [ V_166 ] . V_15 =
V_86 -> V_87 ;
V_86 -> V_165 [ V_167 ] . V_15 = V_86 -> V_88 ;
V_86 -> V_165 [ V_168 ] . V_15 = V_86 -> V_89 ;
V_163 ++ ;
}
V_32 -> V_67 [ V_163 ] = NULL ;
V_15 = F_109 ( & V_32 -> V_26 , V_32 -> V_67 ,
V_169 ) ;
if ( F_32 ( V_15 ) ) {
V_7 = F_33 ( V_15 ) ;
goto V_164;
}
V_32 -> V_26 . V_27 . V_170 = V_15 [ V_166 ] . V_171 ;
V_32 -> V_26 . V_27 . V_172 = V_15 [ V_167 ] . V_171 ;
V_32 -> V_26 . V_27 . V_173 = V_15 [ V_168 ] . V_171 ;
}
if ( V_32 -> V_92 ) {
V_26 -> V_174 = true ;
V_26 -> V_94 = V_32 -> V_94 ;
memcpy ( V_26 -> V_97 , V_32 -> V_97 , V_98 ) ;
}
if ( F_110 ( V_150 ) && ! V_175 [ 0 ] ) {
struct V_176 * V_177 ;
V_177 = F_111 ( V_150 ) ;
if ( ! V_177 ) {
V_7 = - V_21 ;
goto V_164;
}
F_112 ( V_150 , V_177 ) ;
V_175 [ 0 ] = V_177 ;
V_175 [ 1 ] = NULL ;
}
F_30 (c, &gi->cdev.configs, list) {
struct V_14 * V_44 ;
struct V_55 * V_56 ;
struct V_55 * V_148 ;
struct V_38 * V_77 ;
if ( F_110 ( V_150 ) )
V_45 -> V_178 = V_175 ;
V_44 = F_4 ( V_45 , struct V_14 , V_45 ) ;
if ( ! F_26 ( & V_44 -> V_41 ) ) {
V_163 = 0 ;
F_30 (cn, &cfg->string_list, list) {
V_44 -> V_67 [ V_163 ] = & V_77 -> V_3 ;
V_77 -> V_3 . V_165 = & V_77 -> V_165 ;
V_77 -> V_165 . V_15 = V_77 -> V_78 ;
V_163 ++ ;
}
V_44 -> V_67 [ V_163 ] = NULL ;
V_15 = F_109 ( & V_32 -> V_26 , V_44 -> V_67 , 1 ) ;
if ( F_32 ( V_15 ) ) {
V_7 = F_33 ( V_15 ) ;
goto V_164;
}
V_45 -> V_179 = V_15 [ 0 ] . V_171 ;
}
F_102 (f, tmp, &cfg->func_list, list) {
F_28 ( & V_56 -> V_47 ) ;
V_7 = F_113 ( V_45 , V_56 ) ;
if ( V_7 ) {
F_114 ( & V_56 -> V_47 , & V_44 -> V_59 ) ;
goto V_180;
}
}
F_115 ( V_26 -> V_150 ) ;
}
if ( V_26 -> V_174 ) {
V_7 = F_116 ( V_26 , V_150 -> V_181 ) ;
if ( V_7 )
goto V_180;
}
F_115 ( V_26 -> V_150 ) ;
return 0 ;
V_180:
F_101 ( V_32 ) ;
V_164:
F_117 ( V_26 ) ;
return V_7 ;
}
static void F_118 ( struct V_158 * V_150 )
{
struct V_51 * V_26 ;
struct V_10 * V_32 ;
V_26 = F_119 ( V_150 ) ;
V_32 = F_4 ( V_26 , struct V_10 , V_26 ) ;
F_9 ( V_175 [ 0 ] ) ;
V_175 [ 0 ] = NULL ;
F_101 ( V_32 ) ;
F_117 ( V_26 ) ;
F_115 ( V_26 -> V_150 ) ;
V_26 -> V_150 = NULL ;
F_107 ( V_150 , NULL ) ;
}
static struct V_52 * F_120 (
struct V_52 * V_13 ,
const char * V_1 )
{
struct V_10 * V_32 ;
V_32 = F_58 ( sizeof( * V_32 ) , V_20 ) ;
if ( ! V_32 )
return F_48 ( - V_21 ) ;
F_59 ( & V_32 -> V_13 , V_1 , & V_182 ) ;
F_59 ( & V_32 -> V_75 , L_16 ,
& V_183 ) ;
F_60 ( & V_32 -> V_75 , & V_32 -> V_13 ) ;
F_59 ( & V_32 -> V_80 , L_17 ,
& V_184 ) ;
F_60 ( & V_32 -> V_80 , & V_32 -> V_13 ) ;
F_59 ( & V_32 -> V_84 , L_9 ,
& V_185 ) ;
F_60 ( & V_32 -> V_84 , & V_32 -> V_13 ) ;
F_59 ( & V_32 -> V_103 , L_11 ,
& V_142 ) ;
F_60 ( & V_32 -> V_103 , & V_32 -> V_13 ) ;
V_32 -> V_30 . V_186 = F_100 ;
V_32 -> V_30 . V_149 = F_100 ;
V_32 -> V_30 . V_187 = NULL ;
V_32 -> V_30 . V_188 = NULL ;
V_32 -> V_30 . V_189 = V_190 ;
F_121 ( & V_32 -> V_34 ) ;
F_46 ( & V_32 -> V_41 ) ;
F_46 ( & V_32 -> V_42 ) ;
F_44 ( & V_32 -> V_26 ) ;
V_32 -> V_26 . V_27 . V_191 = V_192 ;
V_32 -> V_26 . V_27 . V_193 = V_194 ;
V_32 -> V_26 . V_27 . V_25 = F_12 ( F_122 () ) ;
V_32 -> V_30 . V_31 = V_195 ;
V_32 -> V_30 . V_31 . V_43 = F_8 ( V_1 , V_20 ) ;
V_32 -> V_30 . V_1 = V_32 -> V_30 . V_31 . V_43 ;
if ( ! V_32 -> V_30 . V_31 . V_43 )
goto V_35;
return & V_32 -> V_13 ;
V_35:
F_9 ( V_32 ) ;
return F_48 ( - V_21 ) ;
}
static void F_123 ( struct V_52 * V_13 , struct V_11 * V_12 )
{
F_55 ( V_12 ) ;
}
void F_124 ( struct V_11 * V_12 )
{
struct V_10 * V_32 = F_3 ( V_12 ) ;
F_18 ( & V_32 -> V_34 ) ;
F_15 ( V_32 ) ;
F_20 ( & V_32 -> V_34 ) ;
}
static int T_5 F_125 ( void )
{
int V_7 ;
F_126 ( & V_196 . V_197 ) ;
V_7 = F_127 ( & V_196 ) ;
return V_7 ;
}
static void T_6 F_128 ( void )
{
F_129 ( & V_196 ) ;
}
