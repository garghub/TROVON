static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_1
L_2 V_6 L_3 , V_7 ,
F_5 () -> V_8 , F_5 () -> V_9 ) ;
}
static T_1 F_6 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_4 , V_10 ) ;
}
static T_1 F_7 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
T_1 V_12 ;
struct V_13 * V_14 ;
F_8 ( & V_15 ) ;
if ( ! F_9 ( & V_16 ) ) {
F_10 ( & V_15 ) ;
F_11 ( L_5 ) ;
return - V_17 ;
}
if ( V_11 > ( V_18 - 1 ) ) {
F_10 ( & V_15 ) ;
F_11 ( L_6 ,
( int ) V_11 , V_18 - 1 ) ;
return - V_17 ;
}
V_12 = snprintf ( V_19 , V_18 , L_7 , V_5 ) ;
if ( ! V_12 ) {
F_10 ( & V_15 ) ;
return - V_17 ;
}
if ( V_19 [ V_12 - 1 ] == '\n' )
V_19 [ V_12 - 1 ] = '\0' ;
V_14 = F_12 ( V_19 , V_20 , 0 ) ;
if ( F_13 ( V_14 ) ) {
F_10 ( & V_15 ) ;
F_11 ( L_8 , V_19 ) ;
return - V_17 ;
}
if ( ! F_14 ( V_14 -> V_21 -> V_22 ) ) {
F_15 ( V_14 , 0 ) ;
F_10 ( & V_15 ) ;
F_11 ( L_9 , V_19 ) ;
return - V_17 ;
}
F_15 ( V_14 , 0 ) ;
strncpy ( V_10 , V_19 , V_12 ) ;
F_10 ( & V_15 ) ;
return V_12 ;
}
static struct V_23 * F_16 (
const char * V_24 )
{
struct V_23 * V_25 ;
if ( ! V_24 )
return NULL ;
F_8 ( & V_15 ) ;
F_17 (tf, &g_tf_list, tf_list) {
if ( ! strcmp ( V_25 -> V_26 -> V_24 , V_24 ) ) {
F_18 ( & V_25 -> V_27 ) ;
F_10 ( & V_15 ) ;
return V_25 ;
}
}
F_10 ( & V_15 ) ;
return NULL ;
}
static struct V_28 * F_19 (
struct V_28 * V_29 ,
const char * V_24 )
{
struct V_23 * V_25 ;
int V_30 ;
F_20 ( L_10
L_11 , V_29 , V_24 ) ;
V_25 = F_16 ( V_24 ) ;
if ( ! V_25 ) {
F_20 ( L_12 ,
V_24 ) ;
if ( ! strncmp ( V_24 , L_13 , 5 ) ) {
V_30 = F_21 ( L_14 ) ;
if ( V_30 < 0 ) {
F_20 ( L_15
L_16 , V_30 ) ;
return F_22 ( - V_17 ) ;
}
} else if ( ! strncmp ( V_24 , L_17 , 8 ) ) {
V_30 = F_21 ( L_18 ) ;
if ( V_30 < 0 ) {
F_20 ( L_15
L_19 , V_30 ) ;
return F_22 ( - V_17 ) ;
}
}
V_25 = F_16 ( V_24 ) ;
}
if ( ! V_25 ) {
F_20 ( L_20 ,
V_24 ) ;
return F_22 ( - V_17 ) ;
}
F_20 ( L_21
L_11 , V_25 -> V_26 -> V_24 ) ;
F_20 ( L_22 ,
& V_25 -> V_31 ) ;
F_23 ( & V_25 -> V_32 , V_24 , & V_25 -> V_31 ) ;
F_23 ( & V_25 -> V_33 , L_23 ,
& V_25 -> V_34 ) ;
F_24 ( & V_25 -> V_33 , & V_25 -> V_32 ) ;
F_20 ( L_24
L_11 , V_25 -> V_32 . V_35 . V_36 ) ;
return & V_25 -> V_32 ;
}
static void F_25 (
struct V_28 * V_29 ,
struct V_2 * V_3 )
{
struct V_23 * V_25 = F_2 (
F_3 ( V_3 ) , struct V_23 , V_32 ) ;
F_20 ( L_25
L_26 , F_26 ( V_3 ) ) ;
F_20 ( L_27
L_11 , V_25 -> V_26 -> V_24 ) ;
F_27 ( & V_25 -> V_27 ) ;
F_20 ( L_28
L_11 , F_26 ( V_3 ) ) ;
F_28 ( & V_25 -> V_32 ) ;
F_29 ( V_3 ) ;
}
int F_30 ( struct V_2 * V_3 )
{
return F_31 ( & V_37 , V_3 ) ;
}
void F_32 ( struct V_2 * V_3 )
{
return F_33 ( V_3 ) ;
}
static int F_34 ( const struct V_38 * V_39 )
{
if ( ! V_39 -> V_24 ) {
F_11 ( L_29 ) ;
return - V_17 ;
}
if ( strlen ( V_39 -> V_24 ) >= V_40 ) {
F_11 ( L_30
L_31 , V_39 -> V_24 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_41 ) {
F_11 ( L_32 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_42 ) {
F_11 ( L_33 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_43 ) {
F_11 ( L_34 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_44 ) {
F_11 ( L_35 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_45 ) {
F_11 ( L_36 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_46 ) {
F_11 ( L_37 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_47 ) {
F_11 ( L_38 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_48 ) {
F_11 ( L_39 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_49 ) {
F_11 ( L_40 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_50 ) {
F_11 ( L_41 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_51 ) {
F_11 ( L_42 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_52 ) {
F_11 ( L_43 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_53 ) {
F_11 ( L_44 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_54 ) {
F_11 ( L_45 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_55 ) {
F_11 ( L_46 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_56 ) {
F_11 ( L_47 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_57 ) {
F_11 ( L_48 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_58 ) {
F_11 ( L_49 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_59 ) {
F_11 ( L_50 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_60 ) {
F_11 ( L_51 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_61 ) {
F_11 ( L_52 ) ;
return - V_17 ;
}
if ( ! V_39 -> V_62 ) {
F_11 ( L_53 ) ;
return - V_17 ;
}
return 0 ;
}
int F_35 ( const struct V_38 * V_63 )
{
struct V_23 * V_25 ;
int V_30 ;
V_30 = F_34 ( V_63 ) ;
if ( V_30 )
return V_30 ;
V_25 = F_36 ( sizeof( struct V_23 ) , V_64 ) ;
if ( ! V_25 ) {
F_11 ( L_54 , V_65 ) ;
return - V_66 ;
}
F_37 ( & V_25 -> V_67 ) ;
F_38 ( & V_25 -> V_27 , 0 ) ;
V_25 -> V_26 = V_63 ;
F_39 ( V_25 ) ;
F_8 ( & V_15 ) ;
F_40 ( & V_25 -> V_67 , & V_16 ) ;
F_10 ( & V_15 ) ;
return 0 ;
}
void F_41 ( const struct V_38 * V_63 )
{
struct V_23 * V_68 ;
F_8 ( & V_15 ) ;
F_17 (t, &g_tf_list, tf_list) {
if ( ! strcmp ( V_68 -> V_26 -> V_24 , V_63 -> V_24 ) ) {
F_42 ( F_43 ( & V_68 -> V_27 ) ) ;
F_44 ( & V_68 -> V_67 ) ;
F_10 ( & V_15 ) ;
F_45 () ;
F_46 ( V_68 ) ;
return;
}
}
F_10 ( & V_15 ) ;
}
static inline struct V_69 * F_47 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_69 ,
V_70 ) ;
}
static void F_48 ( struct V_71 * V_72 )
{
const char * V_73 ;
V_73 = F_26 ( & V_72 -> V_74 . V_35 ) ;
if ( strlen ( V_73 ) >= 16 ) {
F_49 ( L_55
L_56 , V_72 ,
V_73 ) ;
}
snprintf ( & V_72 -> V_75 . V_76 [ 0 ] , 16 , L_7 , V_73 ) ;
}
static T_1 F_50 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
struct V_71 * V_72 = V_77 -> V_78 ;
bool V_79 ;
int V_30 ;
if ( V_72 -> V_80 ) {
F_11 ( L_57
L_58 ,
V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
V_30 = F_51 ( V_5 , & V_79 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_79 ) {
F_48 ( V_72 ) ;
} else {
strncpy ( & V_72 -> V_75 . V_76 [ 0 ] ,
V_72 -> V_81 -> V_82 , 16 ) ;
}
V_77 -> V_83 = V_79 ;
return V_11 ;
}
static T_1 F_52 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
bool V_79 ;
int V_30 ;
V_30 = F_51 ( V_5 , & V_79 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_79 && V_77 -> V_78 -> V_81 -> V_84 ) {
F_11 ( L_59 ) ;
return - V_17 ;
}
V_77 -> V_85 = V_79 ;
F_20 ( L_60 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_53 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
T_3 V_86 ;
int V_30 ;
V_30 = F_54 ( V_5 , 0 , & V_86 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_86 != 0 && V_86 != 1 && V_86 != 2 ) {
F_11 ( L_61 , V_86 ) ;
return - V_17 ;
}
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_62
L_63 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_87 = V_86 ;
F_20 ( L_64 ,
V_77 -> V_78 , V_86 ) ;
return V_11 ;
}
static T_1 F_55 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
bool V_79 ;
int V_30 ;
V_30 = F_51 ( V_5 , & V_79 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_65
L_66 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_88 = V_79 ;
F_20 ( L_67 ,
V_77 -> V_78 , V_79 ? L_68 : L_69 ) ;
return V_11 ;
}
static T_1 F_56 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
bool V_79 ;
int V_30 ;
V_30 = F_51 ( V_5 , & V_79 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_79 && ! V_77 -> V_89 ) {
F_11 ( L_70 ) ;
return - V_90 ;
}
V_77 -> V_91 = V_79 ;
F_20 ( L_71 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_57 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
bool V_79 ;
int V_30 ;
V_30 = F_51 ( V_5 , & V_79 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_79 && ! V_77 -> V_89 ) {
F_11 ( L_70 ) ;
return - V_90 ;
}
V_77 -> V_92 = V_79 ;
F_20 ( L_72 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_58 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
int V_93 = V_77 -> V_94 , V_30 ;
struct V_71 * V_72 = V_77 -> V_78 ;
T_3 V_79 ;
V_30 = F_54 ( V_5 , 0 , & V_79 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_79 != 0 && V_79 != 1 && V_79 != 2 && V_79 != 3 ) {
F_11 ( L_73 , V_79 ) ;
return - V_17 ;
}
if ( V_79 == 2 ) {
F_11 ( L_74 ) ;
return - V_90 ;
}
if ( V_77 -> V_95 ) {
F_49 ( L_75
L_76 ) ;
return V_11 ;
}
if ( ! V_72 -> V_81 -> V_96 || ! V_72 -> V_81 -> V_97 ) {
if ( V_79 == 0 )
return V_11 ;
F_11 ( L_77 ,
V_72 -> V_81 -> V_24 ) ;
return - V_90 ;
}
if ( ! ( V_72 -> V_98 & V_99 ) ) {
F_11 ( L_78 ) ;
return - V_100 ;
}
if ( V_72 -> V_80 ) {
F_11 ( L_79
L_66 , V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_94 = V_79 ;
if ( V_79 && ! V_93 ) {
V_30 = V_72 -> V_81 -> V_96 ( V_72 ) ;
if ( V_30 ) {
V_77 -> V_94 = V_93 ;
return V_30 ;
}
} else if ( ! V_79 && V_93 ) {
V_72 -> V_81 -> V_97 ( V_72 ) ;
}
F_20 ( L_80 , V_72 , V_79 ) ;
return V_11 ;
}
static T_1 F_59 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
struct V_71 * V_72 = V_77 -> V_78 ;
bool V_79 ;
int V_30 ;
V_30 = F_51 ( V_5 , & V_79 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ! V_79 )
return V_11 ;
if ( ! V_72 -> V_81 -> V_101 ) {
F_11 ( L_81 ,
V_72 -> V_81 -> V_24 ) ;
return - V_90 ;
}
if ( ! ( V_72 -> V_98 & V_99 ) ) {
F_11 ( L_82 ) ;
return - V_100 ;
}
if ( V_72 -> V_80 ) {
F_11 ( L_83
L_66 , V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
V_30 = V_72 -> V_81 -> V_101 ( V_72 ) ;
if ( V_30 )
return V_30 ;
F_20 ( L_84 , V_72 ) ;
return V_11 ;
}
static T_1 F_60 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
bool V_79 ;
int V_30 ;
V_30 = F_51 ( V_5 , & V_79 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_85
L_66 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_102 = V_79 ;
F_20 ( L_86 , V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_61 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
bool V_79 ;
int V_30 ;
V_30 = F_51 ( V_5 , & V_79 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_79 != 0 ) {
F_62 ( V_103 L_87
L_88 , V_77 -> V_78 ) ;
return - V_90 ;
}
V_77 -> V_104 = V_79 ;
F_20 ( L_89 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_63 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
bool V_79 ;
int V_30 ;
V_30 = F_51 ( V_5 , & V_79 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_62
L_90 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
if ( V_79 && ! V_77 -> V_89 ) {
F_11 ( L_91
L_92 ,
V_77 -> V_78 ) ;
return - V_90 ;
}
V_77 -> V_105 = V_79 ;
F_20 ( L_93 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_64 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
struct V_71 * V_72 = V_77 -> V_78 ;
T_3 V_86 ;
int V_30 ;
V_30 = F_54 ( V_5 , 0 , & V_86 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_72 -> V_80 ) {
F_11 ( L_94
L_66 ,
V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
if ( ! V_86 ) {
F_11 ( L_95 , V_72 ) ;
return - V_17 ;
}
if ( V_86 > V_72 -> V_106 . V_107 ) {
if ( V_86 > V_72 -> V_106 . V_108 ) {
F_11 ( L_96
L_97
L_98 , V_72 , V_86 ,
V_72 -> V_106 . V_108 ) ;
return - V_17 ;
}
}
V_77 -> V_107 = V_72 -> V_107 = V_86 ;
F_20 ( L_99 , V_72 , V_86 ) ;
return V_11 ;
}
static T_1 F_65 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
T_3 V_86 ;
int V_30 ;
V_30 = F_54 ( V_5 , 0 , & V_86 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_62
L_100 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
if ( V_86 > V_77 -> V_109 ) {
F_11 ( L_101
L_102 ,
V_77 -> V_78 , V_86 , V_77 -> V_109 ) ;
return - V_17 ;
}
V_77 -> V_110 = V_86 ;
F_20 ( L_103 ,
V_77 -> V_78 , V_86 ) ;
return V_11 ;
}
static T_1 F_66 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_47 ( V_3 ) ;
T_3 V_86 ;
int V_30 ;
V_30 = F_54 ( V_5 , 0 , & V_86 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_104
L_58 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
if ( V_86 != 512 && V_86 != 1024 && V_86 != 2048 && V_86 != 4096 ) {
F_11 ( L_105
L_106 ,
V_77 -> V_78 , V_86 ) ;
return - V_17 ;
}
V_77 -> V_111 = V_86 ;
if ( V_77 -> V_112 )
V_77 -> V_109 = V_77 -> V_112 / V_86 ;
F_20 ( L_107 ,
V_77 -> V_78 , V_86 ) ;
return V_11 ;
}
static struct V_75 * F_67 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_75 , V_113 ) ;
}
static T_1 F_68 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_108 ,
& F_67 ( V_3 ) -> V_114 [ 0 ] ) ;
}
static T_1 F_69 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_75 * V_75 = F_67 ( V_3 ) ;
struct V_71 * V_72 = V_75 -> V_115 ;
unsigned char V_116 [ V_117 ] ;
if ( V_72 -> V_98 & V_118 ) {
F_11 ( L_109
L_110 ) ;
return - V_119 ;
}
if ( strlen ( V_5 ) >= V_117 ) {
F_11 ( L_111
L_112 , V_117 ) ;
return - V_120 ;
}
if ( V_72 -> V_80 ) {
F_11 ( L_113
L_114 ,
V_72 -> V_80 ) ;
return - V_17 ;
}
memset ( V_116 , 0 , V_117 ) ;
snprintf ( V_116 , V_117 , L_7 , V_5 ) ;
snprintf ( V_72 -> V_75 . V_114 , V_117 ,
L_7 , F_70 ( V_116 ) ) ;
V_72 -> V_98 |= V_121 ;
F_20 ( L_115
L_11 , V_72 -> V_75 . V_114 ) ;
return V_11 ;
}
static T_1 F_71 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_75 * V_75 = F_67 ( V_3 ) ;
struct V_122 * V_123 ;
unsigned char V_116 [ V_124 ] ;
T_1 V_125 = 0 ;
memset ( V_116 , 0 , V_124 ) ;
F_72 ( & V_75 -> V_126 ) ;
F_17 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_123 -> V_127 )
continue;
F_73 ( V_123 , V_116 , V_124 ) ;
if ( V_125 + strlen ( V_116 ) >= V_128 )
break;
V_125 += sprintf ( V_5 + V_125 , L_7 , V_116 ) ;
}
F_74 ( & V_75 -> V_126 ) ;
return V_125 ;
}
static struct V_71 * F_75 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_71 ,
V_129 ) ;
}
static T_1 F_76 ( struct V_71 * V_72 ,
char * V_5 )
{
struct V_130 * V_131 ;
struct V_132 * V_133 ;
char V_134 [ V_135 ] ;
memset ( V_134 , 0 , V_135 ) ;
V_133 = V_72 -> V_136 ;
if ( ! V_133 )
return sprintf ( V_5 , L_116 ) ;
V_131 = V_133 -> V_137 ;
F_77 ( V_133 , V_134 , V_135 ) ;
return sprintf ( V_5 , L_117 ,
V_131 -> V_138 -> V_139 -> V_41 () ,
V_131 -> V_140 , V_134 ) ;
}
static T_1 F_78 ( struct V_71 * V_72 ,
char * V_5 )
{
struct V_130 * V_131 ;
T_1 V_125 ;
V_131 = V_72 -> V_141 ;
if ( V_131 ) {
V_125 = sprintf ( V_5 ,
L_118 ,
V_131 -> V_138 -> V_139 -> V_41 () ,
V_131 -> V_140 ) ;
} else {
V_125 = sprintf ( V_5 , L_119 ) ;
}
return V_125 ;
}
static T_1 F_79 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_75 ( V_3 ) ;
int V_30 ;
if ( V_72 -> V_81 -> V_142 & V_143 )
return sprintf ( V_5 , L_120 ) ;
F_72 ( & V_72 -> V_144 ) ;
if ( V_72 -> V_145 & V_146 )
V_30 = F_78 ( V_72 , V_5 ) ;
else
V_30 = F_76 ( V_72 , V_5 ) ;
F_74 ( & V_72 -> V_144 ) ;
return V_30 ;
}
static T_1 F_80 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_75 ( V_3 ) ;
T_1 V_125 = 0 ;
F_72 ( & V_72 -> V_144 ) ;
if ( ! V_72 -> V_136 ) {
V_125 = sprintf ( V_5 , L_116 ) ;
} else if ( V_72 -> V_136 -> V_147 ) {
V_125 = sprintf ( V_5 , L_121
L_122 ) ;
} else {
V_125 = sprintf ( V_5 , L_123
L_124 ) ;
}
F_74 ( & V_72 -> V_144 ) ;
return V_125 ;
}
static T_1 F_81 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_125 , F_75 ( V_3 ) -> V_148 . V_149 ) ;
}
static T_1 F_82 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_75 ( V_3 ) ;
struct V_130 * V_131 ;
struct V_150 * V_138 ;
struct V_132 * V_133 ;
const struct V_38 * V_39 ;
T_1 V_125 = 0 ;
F_72 ( & V_72 -> V_144 ) ;
V_133 = V_72 -> V_136 ;
if ( ! V_133 ) {
V_125 = sprintf ( V_5 , L_116 ) ;
goto V_151;
}
V_131 = V_133 -> V_137 ;
V_138 = V_131 -> V_138 ;
V_39 = V_138 -> V_139 ;
V_125 += sprintf ( V_5 + V_125 , L_126
L_127 , V_39 -> V_41 () ,
V_39 -> V_42 ( V_138 ) ) ;
V_125 += sprintf ( V_5 + V_125 , L_128
L_129
L_130 , V_133 -> V_152 ,
V_39 -> V_41 () , V_39 -> V_43 ( V_138 ) ,
V_39 -> V_41 () , V_133 -> V_153 ) ;
V_151:
F_74 ( & V_72 -> V_144 ) ;
return V_125 ;
}
static T_1 F_83 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_75 ( V_3 ) ;
const struct V_38 * V_39 ;
struct V_132 * V_133 ;
unsigned char V_116 [ 384 ] ;
char V_134 [ V_135 ] ;
T_1 V_125 = 0 ;
int V_154 = 0 ;
V_125 += sprintf ( V_5 + V_125 , L_131 ) ;
F_72 ( & V_72 -> V_148 . V_155 ) ;
F_17 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_116 , 0 , 384 ) ;
memset ( V_134 , 0 , V_135 ) ;
V_39 = V_133 -> V_137 -> V_138 -> V_139 ;
F_77 ( V_133 , V_134 ,
V_135 ) ;
sprintf ( V_116 , L_132 ,
V_39 -> V_41 () ,
V_133 -> V_137 -> V_140 , V_134 , V_133 -> V_156 ,
V_133 -> V_157 ) ;
if ( V_125 + strlen ( V_116 ) >= V_128 )
break;
V_125 += sprintf ( V_5 + V_125 , L_7 , V_116 ) ;
V_154 ++ ;
}
F_74 ( & V_72 -> V_148 . V_155 ) ;
if ( ! V_154 )
V_125 += sprintf ( V_5 + V_125 , L_133 ) ;
return V_125 ;
}
static T_1 F_84 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_75 ( V_3 ) ;
struct V_132 * V_133 ;
T_1 V_125 = 0 ;
F_72 ( & V_72 -> V_144 ) ;
V_133 = V_72 -> V_136 ;
if ( V_133 ) {
V_125 = sprintf ( V_5 , L_134 ,
F_85 ( V_133 -> V_158 ) ) ;
} else {
V_125 = sprintf ( V_5 , L_116 ) ;
}
F_74 ( & V_72 -> V_144 ) ;
return V_125 ;
}
static T_1 F_86 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_75 ( V_3 ) ;
if ( V_72 -> V_81 -> V_142 & V_143 )
return sprintf ( V_5 , L_135 ) ;
else if ( V_72 -> V_145 & V_146 )
return sprintf ( V_5 , L_136 ) ;
else
return sprintf ( V_5 , L_137 ) ;
}
static T_1 F_87 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_75 ( V_3 ) ;
if ( V_72 -> V_81 -> V_142 & V_143 )
return 0 ;
return sprintf ( V_5 , L_138 ,
( V_72 -> V_148 . V_159 ) ? L_139 : L_69 ) ;
}
static T_1 F_88 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_75 ( V_3 ) ;
if ( V_72 -> V_81 -> V_142 & V_143 )
return 0 ;
return sprintf ( V_5 , L_140 ) ;
}
static T_1 F_89 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_75 ( V_3 ) ;
unsigned char * V_160 = NULL , * V_161 = NULL , * V_162 = NULL ;
unsigned char * V_163 = NULL , * V_164 = NULL ;
char * V_165 , * V_166 , * V_167 ;
T_4 args [ V_168 ] ;
unsigned long long V_169 ;
T_5 V_170 = 0 ;
T_5 V_171 = 0 , V_172 = 0 ;
int V_30 = - 1 , V_173 = 0 , V_174 = 0 , V_175 , V_176 ;
T_6 V_177 = 0 ;
T_7 type = 0 ;
if ( V_72 -> V_81 -> V_142 & V_143 )
return V_11 ;
if ( V_72 -> V_145 & V_146 )
return V_11 ;
if ( V_72 -> V_80 ) {
F_20 ( L_141
L_142 ) ;
return - V_17 ;
}
V_167 = F_90 ( V_5 , V_64 ) ;
if ( ! V_167 )
return - V_66 ;
V_165 = V_167 ;
while ( ( V_166 = F_91 ( & V_167 , L_143 ) ) != NULL ) {
if ( ! * V_166 )
continue;
V_176 = F_92 ( V_166 , V_178 , args ) ;
switch ( V_176 ) {
case V_179 :
V_160 = F_93 ( args ) ;
if ( ! V_160 ) {
V_30 = - V_66 ;
goto V_180;
}
break;
case V_181 :
V_161 = F_93 ( args ) ;
if ( ! V_161 ) {
V_30 = - V_66 ;
goto V_180;
}
if ( strlen ( V_161 ) >= V_182 ) {
F_11 ( L_144
L_145 ,
V_182 ) ;
V_30 = - V_17 ;
break;
}
break;
case V_183 :
V_162 = F_93 ( args ) ;
if ( ! V_162 ) {
V_30 = - V_66 ;
goto V_180;
}
if ( strlen ( V_162 ) >= V_184 ) {
F_11 ( L_146
L_147 ,
V_184 ) ;
V_30 = - V_17 ;
break;
}
break;
case V_185 :
V_30 = F_94 ( args -> V_186 , 0 , & V_169 ) ;
if ( V_30 < 0 ) {
F_11 ( L_148 ) ;
goto V_180;
}
V_170 = ( T_5 ) V_169 ;
break;
case V_187 :
V_30 = F_95 ( args , & V_175 ) ;
if ( V_30 )
goto V_180;
V_173 = V_175 ;
break;
case V_188 :
V_30 = F_95 ( args , & V_175 ) ;
if ( V_30 )
goto V_180;
type = ( T_7 ) V_175 ;
break;
case V_189 :
V_30 = F_95 ( args , & V_175 ) ;
if ( V_30 )
goto V_180;
break;
case V_190 :
V_30 = F_95 ( args , & V_175 ) ;
if ( V_30 )
goto V_180;
V_174 = ( int ) V_175 ;
break;
case V_191 :
V_30 = F_95 ( args , & V_175 ) ;
if ( V_30 )
goto V_180;
V_171 = ( T_5 ) V_175 ;
break;
case V_192 :
V_163 = F_93 ( args ) ;
if ( ! V_163 ) {
V_30 = - V_66 ;
goto V_180;
}
break;
case V_193 :
V_164 = F_93 ( args ) ;
if ( ! V_164 ) {
V_30 = - V_66 ;
goto V_180;
}
if ( strlen ( V_164 ) >= V_194 ) {
F_11 ( L_149
L_150 ,
V_194 ) ;
V_30 = - V_17 ;
break;
}
break;
case V_195 :
V_30 = F_95 ( args , & V_175 ) ;
if ( V_30 )
goto V_180;
V_177 = ( T_6 ) V_175 ;
break;
case V_196 :
V_30 = F_95 ( args , & V_175 ) ;
if ( V_30 )
goto V_180;
break;
case V_197 :
V_30 = F_95 ( args , & V_175 ) ;
if ( V_30 )
goto V_180;
V_172 = ( T_5 ) V_175 ;
break;
default:
break;
}
}
if ( ! V_161 || ! V_164 || ! V_170 ) {
F_11 ( L_151 ) ;
V_30 = - V_17 ;
goto V_180;
}
if ( V_173 && ! ( type ) ) {
F_11 ( L_152
L_153 , type ) ;
V_30 = - V_17 ;
goto V_180;
}
V_30 = F_96 ( & V_72 -> V_148 , V_170 ,
V_161 , V_162 , V_171 , V_164 , V_177 , V_172 ,
V_173 , V_174 , type ) ;
V_180:
F_46 ( V_160 ) ;
F_46 ( V_161 ) ;
F_46 ( V_162 ) ;
F_46 ( V_163 ) ;
F_46 ( V_164 ) ;
F_46 ( V_165 ) ;
return ( V_30 == 0 ) ? V_11 : V_30 ;
}
static inline struct V_71 * F_97 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_71 , V_74 ) ;
}
static T_1 F_98 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
int V_198 = 0 ;
T_1 V_12 = 0 ;
F_99 ( V_72 , V_5 , & V_198 ) ;
V_12 += V_198 ;
V_12 += V_72 -> V_81 -> V_199 ( V_72 ,
V_5 + V_12 ) ;
return V_12 ;
}
static T_1 F_100 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
return V_72 -> V_81 -> V_200 ( V_72 , V_5 , V_11 ) ;
}
static T_1 F_101 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
if ( ! ( V_72 -> V_98 & V_201 ) )
return 0 ;
return snprintf ( V_5 , V_128 , L_4 , V_72 -> V_202 ) ;
}
static T_1 F_102 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
struct V_1 * V_203 = V_72 -> V_1 ;
T_1 V_12 ;
if ( V_11 > ( V_204 - 1 ) ) {
F_11 ( L_154
L_155 , ( int ) V_11 ,
V_204 - 1 ) ;
return - V_17 ;
}
V_12 = snprintf ( & V_72 -> V_202 [ 0 ] , V_204 , L_7 , V_5 ) ;
if ( ! V_12 )
return - V_17 ;
if ( V_72 -> V_202 [ V_12 - 1 ] == '\n' )
V_72 -> V_202 [ V_12 - 1 ] = '\0' ;
V_72 -> V_98 |= V_201 ;
F_20 ( L_156 ,
F_26 ( & V_203 -> V_4 . V_35 ) ,
F_26 ( & V_72 -> V_74 . V_35 ) ,
V_72 -> V_202 ) ;
return V_12 ;
}
static T_1 F_103 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
if ( ! ( V_72 -> V_98 & V_205 ) )
return 0 ;
return snprintf ( V_5 , V_128 , L_4 , V_72 -> V_206 ) ;
}
static T_1 F_104 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
struct V_1 * V_203 = V_72 -> V_1 ;
T_1 V_12 ;
if ( V_11 > ( V_207 - 1 ) ) {
F_11 ( L_157
L_158 , ( int ) V_11 ,
V_207 - 1 ) ;
return - V_17 ;
}
V_12 = snprintf ( & V_72 -> V_206 [ 0 ] , V_207 ,
L_7 , V_5 ) ;
if ( ! V_12 )
return - V_17 ;
if ( V_72 -> V_206 [ V_12 - 1 ] == '\n' )
V_72 -> V_206 [ V_12 - 1 ] = '\0' ;
V_72 -> V_98 |= V_205 ;
F_20 ( L_159 ,
F_26 ( & V_203 -> V_4 . V_35 ) ,
F_26 ( & V_72 -> V_74 . V_35 ) ,
V_72 -> V_206 ) ;
return V_12 ;
}
static T_1 F_105 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
return snprintf ( V_5 , V_128 , L_160 , ! ! ( V_72 -> V_98 & V_99 ) ) ;
}
static T_1 F_106 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
char * V_166 ;
int V_30 ;
V_166 = strstr ( V_5 , L_161 ) ;
if ( ! V_166 ) {
F_11 ( L_162
L_163 ) ;
return - V_17 ;
}
V_30 = F_107 ( V_72 ) ;
if ( V_30 )
return V_30 ;
return V_11 ;
}
static T_1 F_108 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
struct V_2 * V_208 ;
struct V_209 * V_210 ;
struct V_211 * V_212 ;
T_1 V_125 = 0 ;
V_212 = V_72 -> V_213 ;
if ( ! V_212 )
return 0 ;
F_72 ( & V_212 -> V_214 ) ;
V_210 = V_212 -> V_210 ;
if ( V_210 ) {
V_208 = & V_210 -> V_215 . V_35 ;
V_125 += sprintf ( V_5 , L_164 ,
F_26 ( V_208 ) , V_210 -> V_216 ) ;
}
F_74 ( & V_212 -> V_214 ) ;
return V_125 ;
}
static T_1 F_109 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
struct V_1 * V_203 = V_72 -> V_1 ;
struct V_209 * V_210 = NULL , * V_217 = NULL ;
struct V_211 * V_212 ;
unsigned char V_116 [ V_218 ] ;
int V_219 = 0 ;
V_212 = V_72 -> V_213 ;
if ( ! V_212 )
return V_11 ;
if ( V_11 > V_218 ) {
F_11 ( L_165 ) ;
return - V_17 ;
}
memset ( V_116 , 0 , V_218 ) ;
memcpy ( V_116 , V_5 , V_11 ) ;
if ( strcmp ( F_70 ( V_116 ) , L_166 ) ) {
V_217 = F_110 ( F_70 ( V_116 ) ) ;
if ( ! V_217 )
return - V_100 ;
}
F_72 ( & V_212 -> V_214 ) ;
V_210 = V_212 -> V_210 ;
if ( V_210 ) {
if ( ! V_217 ) {
F_20 ( L_167
L_168
L_169 ,
F_26 ( & V_203 -> V_4 . V_35 ) ,
F_26 ( & V_72 -> V_74 . V_35 ) ,
F_26 ( & V_210 -> V_215 . V_35 ) ,
V_210 -> V_216 ) ;
F_111 ( V_212 , V_210 ) ;
F_74 ( & V_212 -> V_214 ) ;
return V_11 ;
}
F_111 ( V_212 , V_210 ) ;
V_219 = 1 ;
}
F_112 ( V_212 , V_217 ) ;
F_74 ( & V_212 -> V_214 ) ;
F_20 ( L_170
L_171 ,
( V_219 ) ? L_172 : L_173 ,
F_26 ( & V_203 -> V_4 . V_35 ) ,
F_26 ( & V_72 -> V_74 . V_35 ) ,
F_26 ( & V_217 -> V_215 . V_35 ) ,
V_217 -> V_216 ) ;
F_113 ( V_217 ) ;
return V_11 ;
}
static T_1 F_114 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
struct V_220 * V_221 ;
struct V_222 * V_223 ;
char * V_224 = V_5 ;
int V_198 = 0 ;
char V_225 ;
F_72 ( & V_72 -> V_226 . V_227 ) ;
if ( ! F_9 ( & V_72 -> V_226 . V_228 ) )
V_198 += sprintf ( V_224 + V_198 , L_174 ,
V_72 -> V_226 . V_229 ,
V_72 -> V_226 . V_230 ) ;
F_17 (map, &dev->t10_alua.lba_map_list, lba_map_list) {
V_198 += sprintf ( V_224 + V_198 , L_175 ,
V_221 -> V_231 , V_221 -> V_232 ) ;
F_17 (mem, &map->lba_map_mem_list,
lba_map_mem_list) {
switch ( V_223 -> V_233 ) {
case V_234 :
V_225 = 'O' ;
break;
case V_235 :
V_225 = 'A' ;
break;
case V_236 :
V_225 = 'S' ;
break;
case V_237 :
V_225 = 'U' ;
break;
default:
V_225 = '.' ;
break;
}
V_198 += sprintf ( V_224 + V_198 , L_176 ,
V_223 -> V_238 , V_225 ) ;
}
V_198 += sprintf ( V_224 + V_198 , L_3 ) ;
}
F_74 ( & V_72 -> V_226 . V_227 ) ;
return V_198 ;
}
static T_1 F_115 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_97 ( V_3 ) ;
struct V_220 * V_239 = NULL ;
struct V_240 V_241 ;
char * V_242 , * V_165 , * V_166 ;
char V_225 ;
int V_243 = - 1 , V_244 ;
int V_30 = 0 , V_245 = 0 , V_246 , V_247 ;
unsigned long V_248 = - 1 , V_249 = - 1 ;
unsigned long V_250 = - 1 , V_251 = - 1 ;
V_165 = V_242 = F_90 ( V_5 , V_64 ) ;
if ( ! V_242 )
return - V_66 ;
F_37 ( & V_241 ) ;
while ( ( V_166 = F_91 ( & V_242 , L_3 ) ) != NULL ) {
if ( ! * V_166 )
continue;
if ( V_245 == 0 ) {
if ( sscanf ( V_166 , L_177 ,
& V_250 , & V_251 ) != 2 ) {
F_11 ( L_178 , V_245 ) ;
V_30 = - V_17 ;
break;
}
V_245 ++ ;
continue;
}
if ( sscanf ( V_166 , L_179 , & V_248 , & V_249 ) != 2 ) {
F_11 ( L_178 , V_245 ) ;
V_30 = - V_17 ;
break;
}
V_166 = strchr ( V_166 , ' ' ) ;
if ( ! V_166 ) {
F_11 ( L_180 , V_245 ) ;
V_30 = - V_17 ;
break;
}
V_166 ++ ;
V_166 = strchr ( V_166 , ' ' ) ;
if ( ! V_166 ) {
F_11 ( L_181 ,
V_245 ) ;
V_30 = - V_17 ;
break;
}
V_166 ++ ;
V_239 = F_116 ( & V_241 ,
V_248 , V_249 ) ;
if ( F_13 ( V_239 ) ) {
V_30 = F_117 ( V_239 ) ;
break;
}
V_244 = 0 ;
while ( sscanf ( V_166 , L_182 , & V_246 , & V_225 ) == 2 ) {
switch ( V_225 ) {
case 'O' :
V_247 = V_234 ;
break;
case 'A' :
V_247 = V_235 ;
break;
case 'S' :
V_247 = V_236 ;
break;
case 'U' :
V_247 = V_237 ;
break;
default:
F_11 ( L_183 , V_225 ) ;
V_30 = - V_17 ;
goto V_180;
}
V_30 = F_118 ( V_239 ,
V_246 , V_247 ) ;
if ( V_30 ) {
F_11 ( L_184
L_185 ,
V_246 , V_225 , V_245 ) ;
break;
}
V_244 ++ ;
V_166 = strchr ( V_166 , ' ' ) ;
if ( V_166 )
V_166 ++ ;
else
break;
}
if ( V_243 == - 1 )
V_243 = V_244 ;
else if ( V_244 != V_243 ) {
F_11 ( L_186
L_185 , V_244 , V_243 , V_245 ) ;
V_30 = - V_17 ;
break;
}
V_245 ++ ;
}
V_180:
if ( V_30 ) {
F_119 ( & V_241 ) ;
V_11 = V_30 ;
} else
F_120 ( V_72 , & V_241 ,
V_250 , V_251 ) ;
F_46 ( V_165 ) ;
return V_11 ;
}
static void F_121 ( struct V_2 * V_3 )
{
struct V_28 * V_252 = F_3 ( V_3 ) ;
struct V_71 * V_72 =
F_2 ( V_252 , struct V_71 , V_74 ) ;
F_122 ( V_72 ) ;
}
static inline struct V_209 * F_123 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_209 ,
V_215 ) ;
}
static T_1 F_124 ( struct V_2 * V_3 , char * V_5 )
{
struct V_209 * V_210 = F_123 ( V_3 ) ;
if ( ! V_210 -> V_253 )
return 0 ;
return sprintf ( V_5 , L_187 , V_210 -> V_216 ) ;
}
static T_1 F_125 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_209 * V_210 = F_123 ( V_3 ) ;
struct V_28 * V_254 = & V_210 -> V_215 ;
unsigned long V_216 ;
int V_30 ;
V_30 = F_126 ( V_5 , 0 , & V_216 ) ;
if ( V_30 < 0 ) {
F_11 ( L_188
L_189 , V_30 ) ;
return V_30 ;
}
if ( V_216 > 0x0000ffff ) {
F_11 ( L_190
L_191 , V_216 ) ;
return - V_17 ;
}
V_30 = F_127 ( V_210 , ( T_6 ) V_216 ) ;
if ( V_30 < 0 )
return - V_17 ;
F_20 ( L_192
L_193 ,
F_26 ( & V_254 -> V_35 ) ,
V_210 -> V_216 ) ;
return V_11 ;
}
static T_1 F_128 ( struct V_2 * V_3 , char * V_5 )
{
struct V_209 * V_210 = F_123 ( V_3 ) ;
struct V_71 * V_72 ;
struct V_1 * V_203 ;
struct V_211 * V_212 ;
T_1 V_125 = 0 , V_255 ;
unsigned char V_116 [ V_218 ] ;
memset ( V_116 , 0 , V_218 ) ;
F_72 ( & V_210 -> V_256 ) ;
F_17 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_72 = V_212 -> V_257 ;
V_203 = V_72 -> V_1 ;
V_255 = snprintf ( V_116 , V_218 , L_194 ,
F_26 ( & V_203 -> V_4 . V_35 ) ,
F_26 ( & V_72 -> V_74 . V_35 ) ) ;
V_255 ++ ;
if ( ( V_255 + V_125 ) > V_128 ) {
F_49 ( L_195
L_196 ) ;
break;
}
memcpy ( V_5 + V_125 , V_116 , V_255 ) ;
V_125 += V_255 ;
}
F_74 ( & V_210 -> V_256 ) ;
return V_125 ;
}
static void F_129 ( struct V_2 * V_3 )
{
struct V_209 * V_210 = F_2 ( F_3 ( V_3 ) ,
struct V_209 , V_215 ) ;
F_130 ( V_210 ) ;
}
static struct V_28 * F_131 (
struct V_28 * V_29 ,
const char * V_24 )
{
struct V_209 * V_210 ;
struct V_28 * V_254 = NULL ;
struct V_2 * V_258 = NULL ;
V_210 = F_132 ( V_24 , 0 ) ;
if ( F_13 ( V_210 ) )
return NULL ;
V_254 = & V_210 -> V_215 ;
V_258 = & V_254 -> V_35 ;
F_23 ( V_254 , V_24 ,
& V_259 ) ;
F_20 ( L_197
L_198 ,
F_26 ( V_258 ) ) ;
return V_254 ;
}
static void F_133 (
struct V_28 * V_29 ,
struct V_2 * V_3 )
{
struct V_209 * V_210 = F_2 ( F_3 ( V_3 ) ,
struct V_209 , V_215 ) ;
F_20 ( L_199
L_200 ,
F_26 ( V_3 ) , V_210 -> V_216 ) ;
F_29 ( V_3 ) ;
}
static inline struct V_260 * F_134 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_260 ,
V_261 ) ;
}
static T_1 F_135 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_160 ,
F_43 ( & F_134 ( V_3 ) -> V_262 ) ) ;
}
static T_1 F_136 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_260 * V_263 = F_134 ( V_3 ) ;
struct V_71 * V_72 = V_263 -> V_264 ;
unsigned long V_265 ;
int V_266 , V_30 ;
if ( ! V_263 -> V_267 ) {
F_11 ( L_201
L_202 , V_263 -> V_267 ) ;
return - V_17 ;
}
if ( ! ( V_72 -> V_98 & V_99 ) ) {
F_11 ( L_203
L_204 ) ;
return - V_100 ;
}
V_30 = F_126 ( V_5 , 0 , & V_265 ) ;
if ( V_30 < 0 ) {
F_11 ( L_205
L_11 , V_5 ) ;
return V_30 ;
}
V_266 = ( int ) V_265 ;
if ( ! ( V_263 -> V_268 & V_269 ) ) {
F_11 ( L_206
L_207 ) ;
return - V_17 ;
}
if ( V_263 -> V_268 & V_270 &&
V_266 == V_271 ) {
F_11 ( L_208
L_209 ) ;
return - V_17 ;
}
V_30 = F_137 ( V_263 , V_72 ,
NULL , NULL , V_266 , 0 ) ;
return ( ! V_30 ) ? V_11 : - V_17 ;
}
static T_1 F_138 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_260 * V_263 = F_134 ( V_3 ) ;
return sprintf ( V_5 , L_4 ,
F_139 ( V_263 -> V_272 ) ) ;
}
static T_1 F_140 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
struct V_260 * V_263 = F_134 ( V_3 ) ;
unsigned long V_265 ;
int V_273 , V_30 ;
if ( ! V_263 -> V_267 ) {
F_11 ( L_210
L_211 ,
V_263 -> V_267 ) ;
return - V_17 ;
}
V_30 = F_126 ( V_5 , 0 , & V_265 ) ;
if ( V_30 < 0 ) {
F_11 ( L_212
L_213 , V_5 ) ;
return V_30 ;
}
V_273 = ( int ) V_265 ;
if ( ( V_273 != V_274 ) &&
( V_273 != V_275 ) &&
( V_273 != V_276 ) ) {
F_11 ( L_214 ,
V_273 ) ;
return - V_17 ;
}
V_263 -> V_272 = V_273 ;
return V_11 ;
}
static T_1 F_141 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_142 ( F_134 ( V_3 ) , V_5 ) ;
}
static T_1 F_143 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_144 ( F_134 ( V_3 ) , V_5 , V_11 ) ;
}
static T_1 F_145 (
struct V_2 * V_3 , char * V_5 )
{
return sprintf ( V_5 , L_160 ,
F_134 ( V_3 ) -> V_277 ) ;
}
static T_1 F_146 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
struct V_260 * V_263 = F_134 ( V_3 ) ;
unsigned long V_265 ;
int V_30 ;
V_30 = F_126 ( V_5 , 0 , & V_265 ) ;
if ( V_30 < 0 ) {
F_11 ( L_215 ) ;
return V_30 ;
}
if ( ( V_265 != 0 ) && ( V_265 != 1 ) ) {
F_11 ( L_216
L_217 , V_265 ) ;
return - V_17 ;
}
V_263 -> V_277 = ( int ) V_265 ;
return V_11 ;
}
static T_1 F_147 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_148 ( F_134 ( V_3 ) , V_5 ) ;
}
static T_1 F_149 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_150 ( F_134 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_151 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_152 ( F_134 ( V_3 ) , V_5 ) ;
}
static T_1 F_153 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_154 ( F_134 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_155 (
struct V_2 * V_3 , char * V_5 )
{
return F_156 ( F_134 ( V_3 ) , V_5 ) ;
}
static T_1 F_157 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
return F_158 ( F_134 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_159 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_160 ( F_134 ( V_3 ) , V_5 ) ;
}
static T_1 F_161 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_162 ( F_134 ( V_3 ) , V_5 , V_11 ) ;
}
static T_1 F_163 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_260 * V_263 = F_134 ( V_3 ) ;
if ( ! V_263 -> V_267 )
return 0 ;
return sprintf ( V_5 , L_187 , V_263 -> V_278 ) ;
}
static T_1 F_164 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_260 * V_263 = F_134 ( V_3 ) ;
struct V_28 * V_279 = & V_263 -> V_261 ;
unsigned long V_278 ;
int V_30 ;
V_30 = F_126 ( V_5 , 0 , & V_278 ) ;
if ( V_30 < 0 ) {
F_11 ( L_188
L_218 , V_30 ) ;
return V_30 ;
}
if ( V_278 > 0x0000ffff ) {
F_11 ( L_219
L_191 , V_278 ) ;
return - V_17 ;
}
V_30 = F_165 ( V_263 , ( T_6 ) V_278 ) ;
if ( V_30 < 0 )
return - V_17 ;
F_20 ( L_220
L_221 ,
F_26 ( & V_279 -> V_35 ) ,
V_263 -> V_278 ) ;
return V_11 ;
}
static T_1 F_166 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_260 * V_263 = F_134 ( V_3 ) ;
struct V_280 * V_281 ;
T_1 V_125 = 0 , V_255 ;
unsigned char V_116 [ V_282 ] ;
memset ( V_116 , 0 , V_282 ) ;
F_72 ( & V_263 -> V_283 ) ;
F_17 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
struct V_150 * V_284 = V_281 -> V_285 ;
V_255 = snprintf ( V_116 , V_282 , L_222
L_223 , V_284 -> V_139 -> V_41 () ,
V_284 -> V_139 -> V_42 ( V_284 ) ,
V_284 -> V_139 -> V_43 ( V_284 ) ,
F_26 ( & V_281 -> V_286 . V_35 ) ) ;
V_255 ++ ;
if ( ( V_255 + V_125 ) > V_128 ) {
F_49 ( L_195
L_196 ) ;
break;
}
memcpy ( V_5 + V_125 , V_116 , V_255 ) ;
V_125 += V_255 ;
}
F_74 ( & V_263 -> V_283 ) ;
return V_125 ;
}
static void F_167 ( struct V_2 * V_3 )
{
struct V_260 * V_263 = F_2 ( F_3 ( V_3 ) ,
struct V_260 , V_261 ) ;
F_168 ( V_263 ) ;
}
static struct V_28 * F_169 (
struct V_28 * V_29 ,
const char * V_24 )
{
struct V_226 * V_287 = F_2 ( V_29 , struct V_226 ,
V_288 ) ;
struct V_260 * V_263 ;
struct V_28 * V_279 = NULL ;
struct V_2 * V_289 = NULL ;
V_263 = F_170 ( V_287 -> V_115 , V_24 , 0 ) ;
if ( ! V_263 )
return NULL ;
V_279 = & V_263 -> V_261 ;
V_289 = & V_279 -> V_35 ;
F_23 ( V_279 , V_24 ,
& V_290 ) ;
F_20 ( L_224
L_225 ,
F_26 ( V_289 ) ) ;
return V_279 ;
}
static void F_171 (
struct V_28 * V_29 ,
struct V_2 * V_3 )
{
struct V_260 * V_263 = F_2 ( F_3 ( V_3 ) ,
struct V_260 , V_261 ) ;
F_20 ( L_226
L_227 ,
F_26 ( V_3 ) , V_263 -> V_278 ) ;
F_29 ( V_3 ) ;
}
static struct V_28 * F_172 (
struct V_28 * V_29 ,
const char * V_24 )
{
return F_22 ( - V_90 ) ;
}
static void F_173 (
struct V_28 * V_29 ,
struct V_2 * V_3 )
{
return;
}
static struct V_28 * F_174 (
struct V_28 * V_29 ,
const char * V_24 )
{
struct V_260 * V_263 ;
struct V_2 * V_291 = & V_29 -> V_35 ;
struct V_1 * V_203 = F_1 ( V_291 ) ;
struct V_292 * V_293 = V_203 -> V_294 ;
struct V_71 * V_72 ;
int V_295 = - V_66 , V_30 ;
V_30 = F_175 ( & V_203 -> V_296 ) ;
if ( V_30 )
return F_22 ( V_30 ) ;
V_72 = F_176 ( V_203 , V_24 ) ;
if ( ! V_72 )
goto V_151;
F_23 ( & V_72 -> V_74 , V_24 , & V_293 -> V_297 ) ;
F_23 ( & V_72 -> V_106 . V_70 , L_228 ,
& V_293 -> V_298 ) ;
F_24 ( & V_72 -> V_106 . V_70 , & V_72 -> V_74 ) ;
F_23 ( & V_72 -> V_129 , L_229 ,
& V_293 -> V_299 ) ;
F_24 ( & V_72 -> V_129 , & V_72 -> V_74 ) ;
F_23 ( & V_72 -> V_75 . V_113 , L_230 ,
& V_293 -> V_300 ) ;
F_24 ( & V_72 -> V_75 . V_113 ,
& V_72 -> V_74 ) ;
F_23 ( & V_72 -> V_226 . V_288 ,
L_231 , & V_293 -> V_301 ) ;
F_24 ( & V_72 -> V_226 . V_288 ,
& V_72 -> V_74 ) ;
F_23 ( & V_72 -> V_302 . V_303 ,
L_232 , & V_293 -> V_304 ) ;
F_24 ( & V_72 -> V_302 . V_303 ,
& V_72 -> V_74 ) ;
V_263 = F_170 ( V_72 , L_233 , 1 ) ;
if ( ! V_263 )
goto V_305;
V_72 -> V_226 . V_306 = V_263 ;
F_23 ( & V_263 -> V_261 ,
L_233 , & V_290 ) ;
F_24 ( & V_263 -> V_261 ,
& V_72 -> V_226 . V_288 ) ;
F_177 ( V_72 ) ;
F_10 ( & V_203 -> V_296 ) ;
return & V_72 -> V_74 ;
V_305:
F_122 ( V_72 ) ;
V_151:
F_10 ( & V_203 -> V_296 ) ;
return F_22 ( V_295 ) ;
}
static void F_178 (
struct V_28 * V_29 ,
struct V_2 * V_3 )
{
struct V_28 * V_252 = F_3 ( V_3 ) ;
struct V_71 * V_72 =
F_2 ( V_252 , struct V_71 , V_74 ) ;
struct V_1 * V_203 ;
V_203 = F_1 ( & V_72 -> V_1 -> V_4 . V_35 ) ;
F_8 ( & V_203 -> V_296 ) ;
F_28 ( & V_72 -> V_302 . V_303 ) ;
F_28 ( & V_72 -> V_226 . V_288 ) ;
V_72 -> V_226 . V_306 = NULL ;
F_28 ( V_252 ) ;
F_29 ( V_3 ) ;
F_10 ( & V_203 -> V_296 ) ;
}
static inline struct V_1 * F_179 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_180 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_203 = F_179 ( V_3 ) ;
return sprintf ( V_5 , L_234 ,
V_203 -> V_307 , V_203 -> V_294 -> V_308 -> V_24 ,
V_7 ) ;
}
static T_1 F_181 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_203 = F_179 ( V_3 ) ;
int V_309 = 0 ;
if ( V_203 -> V_310 & V_311 )
V_309 = 1 ;
return sprintf ( V_5 , L_160 , V_309 ) ;
}
static T_1 F_182 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_1 * V_203 = F_179 ( V_3 ) ;
unsigned long V_312 ;
int V_30 ;
if ( V_203 -> V_294 -> V_308 -> V_313 == NULL )
return - V_17 ;
V_30 = F_126 ( V_5 , 0 , & V_312 ) ;
if ( V_30 < 0 ) {
F_11 ( L_235 , V_30 ) ;
return V_30 ;
}
if ( V_203 -> V_314 ) {
F_11 ( L_236 ) ;
return - V_17 ;
}
V_30 = V_203 -> V_294 -> V_308 -> V_313 ( V_203 , V_312 ) ;
if ( V_30 < 0 )
return - V_17 ;
if ( V_30 > 0 )
V_203 -> V_310 |= V_311 ;
else if ( V_30 == 0 )
V_203 -> V_310 &= ~ V_311 ;
return V_11 ;
}
static void F_183 ( struct V_2 * V_3 )
{
struct V_1 * V_203 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_184 ( V_203 ) ;
}
static struct V_28 * F_185 (
struct V_28 * V_29 ,
const char * V_24 )
{
char * V_315 , * V_316 , * V_317 ;
struct V_1 * V_203 ;
char V_116 [ V_318 ] ;
unsigned long V_319 = 0 ;
int V_30 ;
memset ( V_116 , 0 , V_318 ) ;
if ( strlen ( V_24 ) >= V_318 ) {
F_11 ( L_237
L_238 , ( int ) strlen ( V_24 ) ,
V_318 ) ;
return F_22 ( - V_320 ) ;
}
snprintf ( V_116 , V_318 , L_7 , V_24 ) ;
V_316 = strstr ( V_116 , L_239 ) ;
if ( ! V_316 ) {
F_11 ( L_240 ) ;
return F_22 ( - V_17 ) ;
}
V_315 = V_116 ;
V_317 = strstr ( V_316 + 1 , L_239 ) ;
if ( V_317 ) {
* V_317 = '\0' ;
V_317 ++ ;
V_316 = V_317 ;
} else {
* V_316 = '\0' ;
V_316 ++ ;
}
V_30 = F_126 ( V_316 , 0 , & V_319 ) ;
if ( V_30 < 0 ) {
F_11 ( L_188
L_241 , V_30 ) ;
return F_22 ( V_30 ) ;
}
F_186 () ;
V_203 = F_187 ( V_315 , V_319 , 0 ) ;
if ( F_13 ( V_203 ) )
return F_188 ( V_203 ) ;
F_23 ( & V_203 -> V_4 , V_24 ,
& V_321 ) ;
return & V_203 -> V_4 ;
}
static void F_189 (
struct V_28 * V_29 ,
struct V_2 * V_3 )
{
F_29 ( V_3 ) ;
}
void F_190 ( struct V_292 * V_293 )
{
F_191 ( V_293 ) ;
F_192 ( V_293 ) ;
F_193 ( V_293 ) ;
F_194 ( V_293 ) ;
F_195 ( V_293 ) ;
F_196 ( V_293 ) ;
}
static int T_8 F_197 ( void )
{
struct V_322 * V_323 = & V_37 ;
struct V_209 * V_210 ;
int V_30 ;
F_20 ( L_242
L_243 V_6 L_3 ,
V_7 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
F_198 ( & V_323 -> V_324 ) ;
F_199 ( & V_323 -> V_325 ) ;
V_30 = F_200 () ;
if ( V_30 < 0 )
return V_30 ;
F_23 ( & V_326 , L_244 ,
& V_327 ) ;
F_24 ( & V_326 , & V_323 -> V_324 ) ;
F_23 ( & V_328 , L_231 , & V_329 ) ;
F_24 ( & V_328 , & V_326 ) ;
F_23 ( & V_330 , L_245 ,
& V_331 ) ;
F_24 ( & V_330 , & V_328 ) ;
V_210 = F_132 ( L_246 , 1 ) ;
if ( F_13 ( V_210 ) ) {
V_30 = - V_66 ;
goto V_332;
}
F_23 ( & V_210 -> V_215 , L_246 ,
& V_259 ) ;
F_24 ( & V_210 -> V_215 , & V_330 ) ;
V_333 = V_210 ;
V_30 = F_201 ( V_323 ) ;
if ( V_30 < 0 ) {
F_11 ( L_247 ,
V_30 , V_323 -> V_324 . V_35 . V_334 ) ;
goto V_332;
}
F_20 ( L_248
L_249 V_7 L_250
L_251 V_6 L_3 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
V_30 = F_202 () ;
if ( V_30 < 0 )
goto V_180;
V_30 = F_203 () ;
if ( V_30 < 0 )
goto V_180;
V_30 = F_204 () ;
if ( V_30 < 0 )
goto V_180;
return 0 ;
V_180:
F_205 ( V_323 ) ;
F_206 () ;
F_207 () ;
V_332:
if ( V_333 ) {
F_130 ( V_333 ) ;
V_333 = NULL ;
}
F_208 () ;
return V_30 ;
}
static void T_9 F_209 ( void )
{
F_28 ( & V_330 ) ;
F_28 ( & V_328 ) ;
F_28 ( & V_326 ) ;
F_205 ( & V_37 ) ;
F_130 ( V_333 ) ;
V_333 = NULL ;
F_20 ( L_252
L_253 ) ;
F_206 () ;
F_207 () ;
F_210 () ;
F_208 () ;
}
