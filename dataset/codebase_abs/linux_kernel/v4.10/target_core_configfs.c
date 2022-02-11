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
if ( ! F_14 ( F_15 ( V_14 ) -> V_21 ) ) {
F_16 ( V_14 , NULL ) ;
F_10 ( & V_15 ) ;
F_11 ( L_9 , V_19 ) ;
return - V_17 ;
}
F_16 ( V_14 , NULL ) ;
strncpy ( V_10 , V_19 , V_12 ) ;
F_10 ( & V_15 ) ;
return V_12 ;
}
static struct V_22 * F_17 (
const char * V_23 )
{
struct V_22 * V_24 ;
if ( ! V_23 )
return NULL ;
F_8 ( & V_15 ) ;
F_18 (tf, &g_tf_list, tf_list) {
if ( ! strcmp ( V_24 -> V_25 -> V_23 , V_23 ) ) {
F_19 ( & V_24 -> V_26 ) ;
F_10 ( & V_15 ) ;
return V_24 ;
}
}
F_10 ( & V_15 ) ;
return NULL ;
}
static struct V_27 * F_20 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_22 * V_24 ;
int V_29 ;
F_21 ( L_10
L_11 , V_28 , V_23 ) ;
V_24 = F_17 ( V_23 ) ;
if ( ! V_24 ) {
F_21 ( L_12 ,
V_23 ) ;
if ( ! strncmp ( V_23 , L_13 , 5 ) ) {
V_29 = F_22 ( L_14 ) ;
if ( V_29 < 0 ) {
F_21 ( L_15
L_16 , V_29 ) ;
return F_23 ( - V_17 ) ;
}
} else if ( ! strncmp ( V_23 , L_17 , 8 ) ) {
V_29 = F_22 ( L_18 ) ;
if ( V_29 < 0 ) {
F_21 ( L_15
L_19 , V_29 ) ;
return F_23 ( - V_17 ) ;
}
}
V_24 = F_17 ( V_23 ) ;
}
if ( ! V_24 ) {
F_21 ( L_20 ,
V_23 ) ;
return F_23 ( - V_17 ) ;
}
F_21 ( L_21
L_11 , V_24 -> V_25 -> V_23 ) ;
F_21 ( L_22 ,
& V_24 -> V_30 ) ;
F_24 ( & V_24 -> V_31 , V_23 , & V_24 -> V_30 ) ;
F_24 ( & V_24 -> V_32 , L_23 ,
& V_24 -> V_33 ) ;
F_25 ( & V_24 -> V_32 , & V_24 -> V_31 ) ;
F_21 ( L_24
L_11 , V_24 -> V_31 . V_34 . V_35 ) ;
return & V_24 -> V_31 ;
}
static void F_26 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_22 * V_24 = F_2 (
F_3 ( V_3 ) , struct V_22 , V_31 ) ;
F_21 ( L_25
L_26 , F_27 ( V_3 ) ) ;
F_21 ( L_27
L_11 , V_24 -> V_25 -> V_23 ) ;
F_28 ( & V_24 -> V_26 ) ;
F_21 ( L_28
L_11 , F_27 ( V_3 ) ) ;
F_29 ( & V_24 -> V_31 ) ;
F_30 ( V_3 ) ;
}
int F_31 ( struct V_2 * V_3 )
{
return F_32 ( & V_36 , V_3 ) ;
}
void F_33 ( struct V_2 * V_3 )
{
return F_34 ( V_3 ) ;
}
static int F_35 ( const struct V_37 * V_38 )
{
if ( ! V_38 -> V_23 ) {
F_11 ( L_29 ) ;
return - V_17 ;
}
if ( strlen ( V_38 -> V_23 ) >= V_39 ) {
F_11 ( L_30
L_31 , V_38 -> V_23 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_40 ) {
F_11 ( L_32 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_41 ) {
F_11 ( L_33 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_42 ) {
F_11 ( L_34 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_43 ) {
F_11 ( L_35 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_44 ) {
F_11 ( L_36 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_45 ) {
F_11 ( L_37 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_46 ) {
F_11 ( L_38 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_47 ) {
F_11 ( L_39 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_48 ) {
F_11 ( L_40 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_49 ) {
F_11 ( L_41 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_50 ) {
F_11 ( L_42 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_51 ) {
F_11 ( L_43 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_52 ) {
F_11 ( L_44 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_53 ) {
F_11 ( L_45 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_54 ) {
F_11 ( L_46 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_55 ) {
F_11 ( L_47 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_56 ) {
F_11 ( L_48 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_57 ) {
F_11 ( L_49 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_58 ) {
F_11 ( L_50 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_59 ) {
F_11 ( L_51 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_60 ) {
F_11 ( L_52 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_61 ) {
F_11 ( L_53 ) ;
return - V_17 ;
}
return 0 ;
}
int F_36 ( const struct V_37 * V_62 )
{
struct V_22 * V_24 ;
int V_29 ;
V_29 = F_35 ( V_62 ) ;
if ( V_29 )
return V_29 ;
V_24 = F_37 ( sizeof( struct V_22 ) , V_63 ) ;
if ( ! V_24 ) {
F_11 ( L_54 , V_64 ) ;
return - V_65 ;
}
F_38 ( & V_24 -> V_66 ) ;
F_39 ( & V_24 -> V_26 , 0 ) ;
V_24 -> V_25 = V_62 ;
F_40 ( V_24 ) ;
F_8 ( & V_15 ) ;
F_41 ( & V_24 -> V_66 , & V_16 ) ;
F_10 ( & V_15 ) ;
return 0 ;
}
void F_42 ( const struct V_37 * V_62 )
{
struct V_22 * V_67 ;
F_8 ( & V_15 ) ;
F_18 (t, &g_tf_list, tf_list) {
if ( ! strcmp ( V_67 -> V_25 -> V_23 , V_62 -> V_23 ) ) {
F_43 ( F_44 ( & V_67 -> V_26 ) ) ;
F_45 ( & V_67 -> V_66 ) ;
F_10 ( & V_15 ) ;
F_46 () ;
F_47 ( V_67 ) ;
return;
}
}
F_10 ( & V_15 ) ;
}
static inline struct V_68 * F_48 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_68 ,
V_69 ) ;
}
static void F_49 ( struct V_70 * V_71 )
{
const char * V_72 ;
V_72 = F_27 ( & V_71 -> V_73 . V_34 ) ;
if ( strlen ( V_72 ) >= 16 ) {
F_50 ( L_55
L_56 , V_71 ,
V_72 ) ;
}
snprintf ( & V_71 -> V_74 . V_75 [ 0 ] , 16 , L_7 , V_72 ) ;
}
static T_1 F_51 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
struct V_70 * V_71 = V_76 -> V_77 ;
bool V_78 ;
int V_29 ;
if ( V_71 -> V_79 ) {
F_11 ( L_57
L_58 ,
V_71 , V_71 -> V_79 ) ;
return - V_17 ;
}
V_29 = F_52 ( V_5 , & V_78 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_78 ) {
F_49 ( V_71 ) ;
} else {
strncpy ( & V_71 -> V_74 . V_75 [ 0 ] ,
V_71 -> V_80 -> V_81 , 16 ) ;
}
V_76 -> V_82 = V_78 ;
return V_11 ;
}
static T_1 F_53 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
bool V_78 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_78 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_78 && V_76 -> V_77 -> V_80 -> V_83 ) {
F_11 ( L_59 ) ;
return - V_17 ;
}
V_76 -> V_84 = V_78 ;
F_21 ( L_60 ,
V_76 -> V_77 , V_78 ) ;
return V_11 ;
}
static T_1 F_54 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
T_3 V_85 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_85 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_85 != 0 && V_85 != 1 && V_85 != 2 ) {
F_11 ( L_61 , V_85 ) ;
return - V_17 ;
}
if ( V_76 -> V_77 -> V_79 ) {
F_11 ( L_62
L_63 ,
V_76 -> V_77 , V_76 -> V_77 -> V_79 ) ;
return - V_17 ;
}
V_76 -> V_86 = V_85 ;
F_21 ( L_64 ,
V_76 -> V_77 , V_85 ) ;
return V_11 ;
}
static T_1 F_56 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
bool V_78 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_78 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_76 -> V_77 -> V_79 ) {
F_11 ( L_65
L_66 ,
V_76 -> V_77 , V_76 -> V_77 -> V_79 ) ;
return - V_17 ;
}
V_76 -> V_87 = V_78 ;
F_21 ( L_67 ,
V_76 -> V_77 , V_78 ? L_68 : L_69 ) ;
return V_11 ;
}
static T_1 F_57 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
bool V_78 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_78 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_78 && ! V_76 -> V_88 ) {
F_11 ( L_70 ) ;
return - V_89 ;
}
V_76 -> V_90 = V_78 ;
F_21 ( L_71 ,
V_76 -> V_77 , V_78 ) ;
return V_11 ;
}
static T_1 F_58 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
bool V_78 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_78 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_78 && ! V_76 -> V_88 ) {
F_11 ( L_70 ) ;
return - V_89 ;
}
V_76 -> V_91 = V_78 ;
F_21 ( L_72 ,
V_76 -> V_77 , V_78 ) ;
return V_11 ;
}
static T_1 F_59 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
int V_92 = V_76 -> V_93 , V_29 ;
struct V_70 * V_71 = V_76 -> V_77 ;
T_3 V_78 ;
V_29 = F_55 ( V_5 , 0 , & V_78 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_78 != 0 && V_78 != 1 && V_78 != 2 && V_78 != 3 ) {
F_11 ( L_73 , V_78 ) ;
return - V_17 ;
}
if ( V_78 == 2 ) {
F_11 ( L_74 ) ;
return - V_89 ;
}
if ( V_76 -> V_94 ) {
F_50 ( L_75
L_76 ) ;
return V_11 ;
}
if ( ! V_71 -> V_80 -> V_95 || ! V_71 -> V_80 -> V_96 ) {
if ( V_78 == 0 )
return V_11 ;
F_11 ( L_77 ,
V_71 -> V_80 -> V_23 ) ;
return - V_89 ;
}
if ( ! ( V_71 -> V_97 & V_98 ) ) {
F_11 ( L_78 ) ;
return - V_99 ;
}
if ( V_71 -> V_79 ) {
F_11 ( L_79
L_66 , V_71 , V_71 -> V_79 ) ;
return - V_17 ;
}
V_76 -> V_93 = V_78 ;
if ( V_78 && ! V_92 ) {
V_29 = V_71 -> V_80 -> V_95 ( V_71 ) ;
if ( V_29 ) {
V_76 -> V_93 = V_92 ;
return V_29 ;
}
} else if ( ! V_78 && V_92 ) {
V_71 -> V_80 -> V_96 ( V_71 ) ;
}
F_21 ( L_80 , V_71 , V_78 ) ;
return V_11 ;
}
static T_1 F_60 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
struct V_70 * V_71 = V_76 -> V_77 ;
bool V_78 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_78 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! V_78 )
return V_11 ;
if ( ! V_71 -> V_80 -> V_100 ) {
F_11 ( L_81 ,
V_71 -> V_80 -> V_23 ) ;
return - V_89 ;
}
if ( ! ( V_71 -> V_97 & V_98 ) ) {
F_11 ( L_82 ) ;
return - V_99 ;
}
if ( V_71 -> V_79 ) {
F_11 ( L_83
L_66 , V_71 , V_71 -> V_79 ) ;
return - V_17 ;
}
V_29 = V_71 -> V_80 -> V_100 ( V_71 ) ;
if ( V_29 )
return V_29 ;
F_21 ( L_84 , V_71 ) ;
return V_11 ;
}
static T_1 F_61 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
bool V_78 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_78 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_76 -> V_77 -> V_79 ) {
F_11 ( L_85
L_66 ,
V_76 -> V_77 , V_76 -> V_77 -> V_79 ) ;
return - V_17 ;
}
V_76 -> V_101 = V_78 ;
F_21 ( L_86 , V_76 -> V_77 , V_78 ) ;
return V_11 ;
}
static T_1 F_62 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
bool V_78 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_78 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_78 != 0 ) {
F_63 ( V_102 L_87
L_88 , V_76 -> V_77 ) ;
return - V_89 ;
}
V_76 -> V_103 = V_78 ;
F_21 ( L_89 ,
V_76 -> V_77 , V_78 ) ;
return V_11 ;
}
static T_1 F_64 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
bool V_78 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_78 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_76 -> V_77 -> V_79 ) {
F_11 ( L_62
L_90 ,
V_76 -> V_77 , V_76 -> V_77 -> V_79 ) ;
return - V_17 ;
}
if ( V_78 && ! V_76 -> V_88 ) {
F_11 ( L_91
L_92 ,
V_76 -> V_77 ) ;
return - V_89 ;
}
V_76 -> V_104 = V_78 ;
F_21 ( L_93 ,
V_76 -> V_77 , V_78 ) ;
return V_11 ;
}
static T_1 F_65 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
struct V_70 * V_71 = V_76 -> V_77 ;
T_3 V_85 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_85 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_71 -> V_79 ) {
F_11 ( L_94
L_66 ,
V_71 , V_71 -> V_79 ) ;
return - V_17 ;
}
if ( ! V_85 ) {
F_11 ( L_95 , V_71 ) ;
return - V_17 ;
}
if ( V_85 > V_71 -> V_105 . V_106 ) {
if ( V_85 > V_71 -> V_105 . V_107 ) {
F_11 ( L_96
L_97
L_98 , V_71 , V_85 ,
V_71 -> V_105 . V_107 ) ;
return - V_17 ;
}
}
V_76 -> V_106 = V_71 -> V_106 = V_85 ;
F_21 ( L_99 , V_71 , V_85 ) ;
return V_11 ;
}
static T_1 F_66 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
T_3 V_85 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_85 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_76 -> V_77 -> V_79 ) {
F_11 ( L_62
L_100 ,
V_76 -> V_77 , V_76 -> V_77 -> V_79 ) ;
return - V_17 ;
}
if ( V_85 > V_76 -> V_108 ) {
F_11 ( L_101
L_102 ,
V_76 -> V_77 , V_85 , V_76 -> V_108 ) ;
return - V_17 ;
}
V_76 -> V_109 = V_85 ;
F_21 ( L_103 ,
V_76 -> V_77 , V_85 ) ;
return V_11 ;
}
static T_1 F_67 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_68 * V_76 = F_48 ( V_3 ) ;
T_3 V_85 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_85 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_76 -> V_77 -> V_79 ) {
F_11 ( L_104
L_58 ,
V_76 -> V_77 , V_76 -> V_77 -> V_79 ) ;
return - V_17 ;
}
if ( V_85 != 512 && V_85 != 1024 && V_85 != 2048 && V_85 != 4096 ) {
F_11 ( L_105
L_106 ,
V_76 -> V_77 , V_85 ) ;
return - V_17 ;
}
V_76 -> V_110 = V_85 ;
if ( V_76 -> V_111 )
V_76 -> V_108 = V_76 -> V_111 / V_85 ;
F_21 ( L_107 ,
V_76 -> V_77 , V_85 ) ;
return V_11 ;
}
static struct V_74 * F_68 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_74 , V_112 ) ;
}
static T_1 F_69 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_108 ,
& F_68 ( V_3 ) -> V_113 [ 0 ] ) ;
}
static T_1 F_70 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_74 * V_74 = F_68 ( V_3 ) ;
struct V_70 * V_71 = V_74 -> V_114 ;
unsigned char V_115 [ V_116 ] ;
if ( V_71 -> V_97 & V_117 ) {
F_11 ( L_109
L_110 ) ;
return - V_118 ;
}
if ( strlen ( V_5 ) >= V_116 ) {
F_11 ( L_111
L_112 , V_116 ) ;
return - V_119 ;
}
if ( V_71 -> V_79 ) {
F_11 ( L_113
L_114 ,
V_71 -> V_79 ) ;
return - V_17 ;
}
memset ( V_115 , 0 , V_116 ) ;
snprintf ( V_115 , V_116 , L_7 , V_5 ) ;
snprintf ( V_71 -> V_74 . V_113 , V_116 ,
L_7 , F_71 ( V_115 ) ) ;
V_71 -> V_97 |= V_120 ;
F_21 ( L_115
L_11 , V_71 -> V_74 . V_113 ) ;
return V_11 ;
}
static T_1 F_72 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_74 * V_74 = F_68 ( V_3 ) ;
struct V_121 * V_122 ;
unsigned char V_115 [ V_123 ] ;
T_1 V_124 = 0 ;
memset ( V_115 , 0 , V_123 ) ;
F_73 ( & V_74 -> V_125 ) ;
F_18 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_122 -> V_126 )
continue;
F_74 ( V_122 , V_115 , V_123 ) ;
if ( V_124 + strlen ( V_115 ) >= V_127 )
break;
V_124 += sprintf ( V_5 + V_124 , L_7 , V_115 ) ;
}
F_75 ( & V_74 -> V_125 ) ;
return V_124 ;
}
static struct V_70 * F_76 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_70 ,
V_128 ) ;
}
static T_1 F_77 ( struct V_70 * V_71 ,
char * V_5 )
{
struct V_129 * V_130 ;
struct V_131 * V_132 ;
char V_133 [ V_134 ] ;
memset ( V_133 , 0 , V_134 ) ;
V_132 = V_71 -> V_135 ;
if ( ! V_132 )
return sprintf ( V_5 , L_116 ) ;
V_130 = V_132 -> V_136 ;
F_78 ( V_132 , V_133 , V_134 ) ;
return sprintf ( V_5 , L_117 ,
V_130 -> V_137 -> V_138 -> V_40 () ,
V_130 -> V_139 , V_133 ) ;
}
static T_1 F_79 ( struct V_70 * V_71 ,
char * V_5 )
{
struct V_129 * V_130 ;
T_1 V_124 ;
V_130 = V_71 -> V_140 ;
if ( V_130 ) {
V_124 = sprintf ( V_5 ,
L_118 ,
V_130 -> V_137 -> V_138 -> V_40 () ,
V_130 -> V_139 ) ;
} else {
V_124 = sprintf ( V_5 , L_119 ) ;
}
return V_124 ;
}
static T_1 F_80 ( struct V_2 * V_3 , char * V_5 )
{
struct V_70 * V_71 = F_76 ( V_3 ) ;
int V_29 ;
if ( V_71 -> V_80 -> V_141 & V_142 )
return sprintf ( V_5 , L_120 ) ;
F_73 ( & V_71 -> V_143 ) ;
if ( V_71 -> V_144 & V_145 )
V_29 = F_79 ( V_71 , V_5 ) ;
else
V_29 = F_77 ( V_71 , V_5 ) ;
F_75 ( & V_71 -> V_143 ) ;
return V_29 ;
}
static T_1 F_81 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_70 * V_71 = F_76 ( V_3 ) ;
T_1 V_124 = 0 ;
F_73 ( & V_71 -> V_143 ) ;
if ( ! V_71 -> V_135 ) {
V_124 = sprintf ( V_5 , L_116 ) ;
} else if ( V_71 -> V_135 -> V_146 ) {
V_124 = sprintf ( V_5 , L_121
L_122 ) ;
} else {
V_124 = sprintf ( V_5 , L_123
L_124 ) ;
}
F_75 ( & V_71 -> V_143 ) ;
return V_124 ;
}
static T_1 F_82 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_125 , F_76 ( V_3 ) -> V_147 . V_148 ) ;
}
static T_1 F_83 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_70 * V_71 = F_76 ( V_3 ) ;
struct V_129 * V_130 ;
struct V_149 * V_137 ;
struct V_131 * V_132 ;
const struct V_37 * V_38 ;
T_1 V_124 = 0 ;
F_73 ( & V_71 -> V_143 ) ;
V_132 = V_71 -> V_135 ;
if ( ! V_132 ) {
V_124 = sprintf ( V_5 , L_116 ) ;
goto V_150;
}
V_130 = V_132 -> V_136 ;
V_137 = V_130 -> V_137 ;
V_38 = V_137 -> V_138 ;
V_124 += sprintf ( V_5 + V_124 , L_126
L_127 , V_38 -> V_40 () ,
V_38 -> V_41 ( V_137 ) ) ;
V_124 += sprintf ( V_5 + V_124 , L_128
L_129
L_130 , V_132 -> V_151 ,
V_38 -> V_40 () , V_38 -> V_42 ( V_137 ) ,
V_38 -> V_40 () , V_132 -> V_152 ) ;
V_150:
F_75 ( & V_71 -> V_143 ) ;
return V_124 ;
}
static T_1 F_84 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_70 * V_71 = F_76 ( V_3 ) ;
const struct V_37 * V_38 ;
struct V_131 * V_132 ;
unsigned char V_115 [ 384 ] ;
char V_133 [ V_134 ] ;
T_1 V_124 = 0 ;
int V_153 = 0 ;
V_124 += sprintf ( V_5 + V_124 , L_131 ) ;
F_73 ( & V_71 -> V_147 . V_154 ) ;
F_18 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_115 , 0 , 384 ) ;
memset ( V_133 , 0 , V_134 ) ;
V_38 = V_132 -> V_136 -> V_137 -> V_138 ;
F_78 ( V_132 , V_133 ,
V_134 ) ;
sprintf ( V_115 , L_132 ,
V_38 -> V_40 () ,
V_132 -> V_136 -> V_139 , V_133 , V_132 -> V_155 ,
V_132 -> V_156 ) ;
if ( V_124 + strlen ( V_115 ) >= V_127 )
break;
V_124 += sprintf ( V_5 + V_124 , L_7 , V_115 ) ;
V_153 ++ ;
}
F_75 ( & V_71 -> V_147 . V_154 ) ;
if ( ! V_153 )
V_124 += sprintf ( V_5 + V_124 , L_133 ) ;
return V_124 ;
}
static T_1 F_85 ( struct V_2 * V_3 , char * V_5 )
{
struct V_70 * V_71 = F_76 ( V_3 ) ;
struct V_131 * V_132 ;
T_1 V_124 = 0 ;
F_73 ( & V_71 -> V_143 ) ;
V_132 = V_71 -> V_135 ;
if ( V_132 ) {
V_124 = sprintf ( V_5 , L_134 ,
F_86 ( V_132 -> V_157 ) ) ;
} else {
V_124 = sprintf ( V_5 , L_116 ) ;
}
F_75 ( & V_71 -> V_143 ) ;
return V_124 ;
}
static T_1 F_87 ( struct V_2 * V_3 , char * V_5 )
{
struct V_70 * V_71 = F_76 ( V_3 ) ;
if ( V_71 -> V_80 -> V_141 & V_142 )
return sprintf ( V_5 , L_135 ) ;
else if ( V_71 -> V_144 & V_145 )
return sprintf ( V_5 , L_136 ) ;
else
return sprintf ( V_5 , L_137 ) ;
}
static T_1 F_88 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_70 * V_71 = F_76 ( V_3 ) ;
if ( V_71 -> V_80 -> V_141 & V_142 )
return 0 ;
return sprintf ( V_5 , L_138 ,
( V_71 -> V_147 . V_158 ) ? L_139 : L_69 ) ;
}
static T_1 F_89 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_70 * V_71 = F_76 ( V_3 ) ;
if ( V_71 -> V_80 -> V_141 & V_142 )
return 0 ;
return sprintf ( V_5 , L_140 ) ;
}
static T_1 F_90 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_70 * V_71 = F_76 ( V_3 ) ;
unsigned char * V_159 = NULL , * V_160 = NULL , * V_161 = NULL ;
unsigned char * V_162 = NULL , * V_163 = NULL ;
char * V_164 , * V_165 , * V_166 ;
T_4 args [ V_167 ] ;
unsigned long long V_168 ;
T_5 V_169 = 0 ;
T_5 V_170 = 0 , V_171 = 0 ;
int V_29 = - 1 , V_172 = 0 , V_173 = 0 , V_174 , V_175 ;
T_6 V_176 = 0 ;
T_7 type = 0 ;
if ( V_71 -> V_80 -> V_141 & V_142 )
return V_11 ;
if ( V_71 -> V_144 & V_145 )
return V_11 ;
if ( V_71 -> V_79 ) {
F_21 ( L_141
L_142 ) ;
return - V_17 ;
}
V_166 = F_91 ( V_5 , V_63 ) ;
if ( ! V_166 )
return - V_65 ;
V_164 = V_166 ;
while ( ( V_165 = F_92 ( & V_166 , L_143 ) ) != NULL ) {
if ( ! * V_165 )
continue;
V_175 = F_93 ( V_165 , V_177 , args ) ;
switch ( V_175 ) {
case V_178 :
V_159 = F_94 ( args ) ;
if ( ! V_159 ) {
V_29 = - V_65 ;
goto V_179;
}
break;
case V_180 :
V_160 = F_94 ( args ) ;
if ( ! V_160 ) {
V_29 = - V_65 ;
goto V_179;
}
if ( strlen ( V_160 ) >= V_181 ) {
F_11 ( L_144
L_145 ,
V_181 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_182 :
V_161 = F_94 ( args ) ;
if ( ! V_161 ) {
V_29 = - V_65 ;
goto V_179;
}
if ( strlen ( V_161 ) >= V_183 ) {
F_11 ( L_146
L_147 ,
V_183 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_184 :
V_29 = F_95 ( args -> V_185 , 0 , & V_168 ) ;
if ( V_29 < 0 ) {
F_11 ( L_148 ) ;
goto V_179;
}
V_169 = ( T_5 ) V_168 ;
break;
case V_186 :
V_29 = F_96 ( args , & V_174 ) ;
if ( V_29 )
goto V_179;
V_172 = V_174 ;
break;
case V_187 :
V_29 = F_96 ( args , & V_174 ) ;
if ( V_29 )
goto V_179;
type = ( T_7 ) V_174 ;
break;
case V_188 :
V_29 = F_96 ( args , & V_174 ) ;
if ( V_29 )
goto V_179;
break;
case V_189 :
V_29 = F_96 ( args , & V_174 ) ;
if ( V_29 )
goto V_179;
V_173 = ( int ) V_174 ;
break;
case V_190 :
V_29 = F_96 ( args , & V_174 ) ;
if ( V_29 )
goto V_179;
V_170 = ( T_5 ) V_174 ;
break;
case V_191 :
V_162 = F_94 ( args ) ;
if ( ! V_162 ) {
V_29 = - V_65 ;
goto V_179;
}
break;
case V_192 :
V_163 = F_94 ( args ) ;
if ( ! V_163 ) {
V_29 = - V_65 ;
goto V_179;
}
if ( strlen ( V_163 ) >= V_193 ) {
F_11 ( L_149
L_150 ,
V_193 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_194 :
V_29 = F_96 ( args , & V_174 ) ;
if ( V_29 )
goto V_179;
V_176 = ( T_6 ) V_174 ;
break;
case V_195 :
V_29 = F_96 ( args , & V_174 ) ;
if ( V_29 )
goto V_179;
break;
case V_196 :
V_29 = F_96 ( args , & V_174 ) ;
if ( V_29 )
goto V_179;
V_171 = ( T_5 ) V_174 ;
break;
default:
break;
}
}
if ( ! V_160 || ! V_163 || ! V_169 ) {
F_11 ( L_151 ) ;
V_29 = - V_17 ;
goto V_179;
}
if ( V_172 && ! ( type ) ) {
F_11 ( L_152
L_153 , type ) ;
V_29 = - V_17 ;
goto V_179;
}
V_29 = F_97 ( & V_71 -> V_147 , V_169 ,
V_160 , V_161 , V_170 , V_163 , V_176 , V_171 ,
V_172 , V_173 , type ) ;
V_179:
F_47 ( V_159 ) ;
F_47 ( V_160 ) ;
F_47 ( V_161 ) ;
F_47 ( V_162 ) ;
F_47 ( V_163 ) ;
F_47 ( V_164 ) ;
return ( V_29 == 0 ) ? V_11 : V_29 ;
}
static inline struct V_70 * F_98 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_70 , V_73 ) ;
}
static T_1 F_99 ( struct V_2 * V_3 , char * V_5 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
int V_197 = 0 ;
T_1 V_12 = 0 ;
F_100 ( V_71 , V_5 , & V_197 ) ;
V_12 += V_197 ;
V_12 += V_71 -> V_80 -> V_198 ( V_71 ,
V_5 + V_12 ) ;
return V_12 ;
}
static T_1 F_101 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
return V_71 -> V_80 -> V_199 ( V_71 , V_5 , V_11 ) ;
}
static T_1 F_102 ( struct V_2 * V_3 , char * V_5 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
if ( ! ( V_71 -> V_97 & V_200 ) )
return 0 ;
return snprintf ( V_5 , V_127 , L_4 , V_71 -> V_201 ) ;
}
static T_1 F_103 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
struct V_1 * V_202 = V_71 -> V_1 ;
T_1 V_12 ;
if ( V_11 > ( V_203 - 1 ) ) {
F_11 ( L_154
L_155 , ( int ) V_11 ,
V_203 - 1 ) ;
return - V_17 ;
}
V_12 = snprintf ( & V_71 -> V_201 [ 0 ] , V_203 , L_7 , V_5 ) ;
if ( ! V_12 )
return - V_17 ;
if ( V_71 -> V_201 [ V_12 - 1 ] == '\n' )
V_71 -> V_201 [ V_12 - 1 ] = '\0' ;
V_71 -> V_97 |= V_200 ;
F_21 ( L_156 ,
F_27 ( & V_202 -> V_4 . V_34 ) ,
F_27 ( & V_71 -> V_73 . V_34 ) ,
V_71 -> V_201 ) ;
return V_12 ;
}
static T_1 F_104 ( struct V_2 * V_3 , char * V_5 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
if ( ! ( V_71 -> V_97 & V_204 ) )
return 0 ;
return snprintf ( V_5 , V_127 , L_4 , V_71 -> V_205 ) ;
}
static T_1 F_105 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
struct V_1 * V_202 = V_71 -> V_1 ;
T_1 V_12 ;
if ( V_11 > ( V_206 - 1 ) ) {
F_11 ( L_157
L_158 , ( int ) V_11 ,
V_206 - 1 ) ;
return - V_17 ;
}
V_12 = snprintf ( & V_71 -> V_205 [ 0 ] , V_206 ,
L_7 , V_5 ) ;
if ( ! V_12 )
return - V_17 ;
if ( V_71 -> V_205 [ V_12 - 1 ] == '\n' )
V_71 -> V_205 [ V_12 - 1 ] = '\0' ;
V_71 -> V_97 |= V_204 ;
F_21 ( L_159 ,
F_27 ( & V_202 -> V_4 . V_34 ) ,
F_27 ( & V_71 -> V_73 . V_34 ) ,
V_71 -> V_205 ) ;
return V_12 ;
}
static T_1 F_106 ( struct V_2 * V_3 , char * V_5 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
return snprintf ( V_5 , V_127 , L_160 , ! ! ( V_71 -> V_97 & V_98 ) ) ;
}
static T_1 F_107 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
char * V_165 ;
int V_29 ;
V_165 = strstr ( V_5 , L_161 ) ;
if ( ! V_165 ) {
F_11 ( L_162
L_163 ) ;
return - V_17 ;
}
V_29 = F_108 ( V_71 ) ;
if ( V_29 )
return V_29 ;
return V_11 ;
}
static T_1 F_109 ( struct V_2 * V_3 , char * V_5 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
struct V_2 * V_207 ;
struct V_208 * V_209 ;
struct V_210 * V_211 ;
T_1 V_124 = 0 ;
V_211 = V_71 -> V_212 ;
if ( ! V_211 )
return 0 ;
F_73 ( & V_211 -> V_213 ) ;
V_209 = V_211 -> V_209 ;
if ( V_209 ) {
V_207 = & V_209 -> V_214 . V_34 ;
V_124 += sprintf ( V_5 , L_164 ,
F_27 ( V_207 ) , V_209 -> V_215 ) ;
}
F_75 ( & V_211 -> V_213 ) ;
return V_124 ;
}
static T_1 F_110 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
struct V_1 * V_202 = V_71 -> V_1 ;
struct V_208 * V_209 = NULL , * V_216 = NULL ;
struct V_210 * V_211 ;
unsigned char V_115 [ V_217 ] ;
int V_218 = 0 ;
V_211 = V_71 -> V_212 ;
if ( ! V_211 )
return V_11 ;
if ( V_11 > V_217 ) {
F_11 ( L_165 ) ;
return - V_17 ;
}
memset ( V_115 , 0 , V_217 ) ;
memcpy ( V_115 , V_5 , V_11 ) ;
if ( strcmp ( F_71 ( V_115 ) , L_166 ) ) {
V_216 = F_111 ( F_71 ( V_115 ) ) ;
if ( ! V_216 )
return - V_99 ;
}
F_73 ( & V_211 -> V_213 ) ;
V_209 = V_211 -> V_209 ;
if ( V_209 ) {
if ( ! V_216 ) {
F_21 ( L_167
L_168
L_169 ,
F_27 ( & V_202 -> V_4 . V_34 ) ,
F_27 ( & V_71 -> V_73 . V_34 ) ,
F_27 ( & V_209 -> V_214 . V_34 ) ,
V_209 -> V_215 ) ;
F_112 ( V_211 , V_209 ) ;
F_75 ( & V_211 -> V_213 ) ;
return V_11 ;
}
F_112 ( V_211 , V_209 ) ;
V_218 = 1 ;
}
F_113 ( V_211 , V_216 ) ;
F_75 ( & V_211 -> V_213 ) ;
F_21 ( L_170
L_171 ,
( V_218 ) ? L_172 : L_173 ,
F_27 ( & V_202 -> V_4 . V_34 ) ,
F_27 ( & V_71 -> V_73 . V_34 ) ,
F_27 ( & V_216 -> V_214 . V_34 ) ,
V_216 -> V_215 ) ;
F_114 ( V_216 ) ;
return V_11 ;
}
static T_1 F_115 ( struct V_2 * V_3 , char * V_5 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
struct V_219 * V_220 ;
struct V_221 * V_222 ;
char * V_223 = V_5 ;
int V_197 = 0 ;
char V_224 ;
F_73 ( & V_71 -> V_225 . V_226 ) ;
if ( ! F_9 ( & V_71 -> V_225 . V_227 ) )
V_197 += sprintf ( V_223 + V_197 , L_174 ,
V_71 -> V_225 . V_228 ,
V_71 -> V_225 . V_229 ) ;
F_18 (map, &dev->t10_alua.lba_map_list, lba_map_list) {
V_197 += sprintf ( V_223 + V_197 , L_175 ,
V_220 -> V_230 , V_220 -> V_231 ) ;
F_18 (mem, &map->lba_map_mem_list,
lba_map_mem_list) {
switch ( V_222 -> V_232 ) {
case V_233 :
V_224 = 'O' ;
break;
case V_234 :
V_224 = 'A' ;
break;
case V_235 :
V_224 = 'S' ;
break;
case V_236 :
V_224 = 'U' ;
break;
default:
V_224 = '.' ;
break;
}
V_197 += sprintf ( V_223 + V_197 , L_176 ,
V_222 -> V_237 , V_224 ) ;
}
V_197 += sprintf ( V_223 + V_197 , L_3 ) ;
}
F_75 ( & V_71 -> V_225 . V_226 ) ;
return V_197 ;
}
static T_1 F_116 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_70 * V_71 = F_98 ( V_3 ) ;
struct V_219 * V_238 = NULL ;
struct V_239 V_240 ;
char * V_241 , * V_164 , * V_165 ;
char V_224 ;
int V_242 = - 1 , V_243 ;
int V_29 = 0 , V_244 = 0 , V_245 , V_246 ;
unsigned long V_247 = - 1 , V_248 = - 1 ;
unsigned long V_249 = - 1 , V_250 = - 1 ;
V_164 = V_241 = F_91 ( V_5 , V_63 ) ;
if ( ! V_241 )
return - V_65 ;
F_38 ( & V_240 ) ;
while ( ( V_165 = F_92 ( & V_241 , L_3 ) ) != NULL ) {
if ( ! * V_165 )
continue;
if ( V_244 == 0 ) {
if ( sscanf ( V_165 , L_177 ,
& V_249 , & V_250 ) != 2 ) {
F_11 ( L_178 , V_244 ) ;
V_29 = - V_17 ;
break;
}
V_244 ++ ;
continue;
}
if ( sscanf ( V_165 , L_179 , & V_247 , & V_248 ) != 2 ) {
F_11 ( L_178 , V_244 ) ;
V_29 = - V_17 ;
break;
}
V_165 = strchr ( V_165 , ' ' ) ;
if ( ! V_165 ) {
F_11 ( L_180 , V_244 ) ;
V_29 = - V_17 ;
break;
}
V_165 ++ ;
V_165 = strchr ( V_165 , ' ' ) ;
if ( ! V_165 ) {
F_11 ( L_181 ,
V_244 ) ;
V_29 = - V_17 ;
break;
}
V_165 ++ ;
V_238 = F_117 ( & V_240 ,
V_247 , V_248 ) ;
if ( F_13 ( V_238 ) ) {
V_29 = F_118 ( V_238 ) ;
break;
}
V_243 = 0 ;
while ( sscanf ( V_165 , L_182 , & V_245 , & V_224 ) == 2 ) {
switch ( V_224 ) {
case 'O' :
V_246 = V_233 ;
break;
case 'A' :
V_246 = V_234 ;
break;
case 'S' :
V_246 = V_235 ;
break;
case 'U' :
V_246 = V_236 ;
break;
default:
F_11 ( L_183 , V_224 ) ;
V_29 = - V_17 ;
goto V_179;
}
V_29 = F_119 ( V_238 ,
V_245 , V_246 ) ;
if ( V_29 ) {
F_11 ( L_184
L_185 ,
V_245 , V_224 , V_244 ) ;
break;
}
V_243 ++ ;
V_165 = strchr ( V_165 , ' ' ) ;
if ( V_165 )
V_165 ++ ;
else
break;
}
if ( V_242 == - 1 )
V_242 = V_243 ;
else if ( V_243 != V_242 ) {
F_11 ( L_186
L_185 , V_243 , V_242 , V_244 ) ;
V_29 = - V_17 ;
break;
}
V_244 ++ ;
}
V_179:
if ( V_29 ) {
F_120 ( & V_240 ) ;
V_11 = V_29 ;
} else
F_121 ( V_71 , & V_240 ,
V_249 , V_250 ) ;
F_47 ( V_164 ) ;
return V_11 ;
}
static void F_122 ( struct V_2 * V_3 )
{
struct V_27 * V_251 = F_3 ( V_3 ) ;
struct V_70 * V_71 =
F_2 ( V_251 , struct V_70 , V_73 ) ;
F_123 ( V_71 ) ;
}
static inline struct V_208 * F_124 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_208 ,
V_214 ) ;
}
static T_1 F_125 ( struct V_2 * V_3 , char * V_5 )
{
struct V_208 * V_209 = F_124 ( V_3 ) ;
if ( ! V_209 -> V_252 )
return 0 ;
return sprintf ( V_5 , L_187 , V_209 -> V_215 ) ;
}
static T_1 F_126 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_208 * V_209 = F_124 ( V_3 ) ;
struct V_27 * V_253 = & V_209 -> V_214 ;
unsigned long V_215 ;
int V_29 ;
V_29 = F_127 ( V_5 , 0 , & V_215 ) ;
if ( V_29 < 0 ) {
F_11 ( L_188
L_189 , V_29 ) ;
return V_29 ;
}
if ( V_215 > 0x0000ffff ) {
F_11 ( L_190
L_191 , V_215 ) ;
return - V_17 ;
}
V_29 = F_128 ( V_209 , ( T_6 ) V_215 ) ;
if ( V_29 < 0 )
return - V_17 ;
F_21 ( L_192
L_193 ,
F_27 ( & V_253 -> V_34 ) ,
V_209 -> V_215 ) ;
return V_11 ;
}
static T_1 F_129 ( struct V_2 * V_3 , char * V_5 )
{
struct V_208 * V_209 = F_124 ( V_3 ) ;
struct V_70 * V_71 ;
struct V_1 * V_202 ;
struct V_210 * V_211 ;
T_1 V_124 = 0 , V_254 ;
unsigned char V_115 [ V_217 ] ;
memset ( V_115 , 0 , V_217 ) ;
F_73 ( & V_209 -> V_255 ) ;
F_18 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_71 = V_211 -> V_256 ;
V_202 = V_71 -> V_1 ;
V_254 = snprintf ( V_115 , V_217 , L_194 ,
F_27 ( & V_202 -> V_4 . V_34 ) ,
F_27 ( & V_71 -> V_73 . V_34 ) ) ;
V_254 ++ ;
if ( ( V_254 + V_124 ) > V_127 ) {
F_50 ( L_195
L_196 ) ;
break;
}
memcpy ( V_5 + V_124 , V_115 , V_254 ) ;
V_124 += V_254 ;
}
F_75 ( & V_209 -> V_255 ) ;
return V_124 ;
}
static void F_130 ( struct V_2 * V_3 )
{
struct V_208 * V_209 = F_2 ( F_3 ( V_3 ) ,
struct V_208 , V_214 ) ;
F_131 ( V_209 ) ;
}
static struct V_27 * F_132 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_208 * V_209 ;
struct V_27 * V_253 = NULL ;
struct V_2 * V_257 = NULL ;
V_209 = F_133 ( V_23 , 0 ) ;
if ( F_13 ( V_209 ) )
return NULL ;
V_253 = & V_209 -> V_214 ;
V_257 = & V_253 -> V_34 ;
F_24 ( V_253 , V_23 ,
& V_258 ) ;
F_21 ( L_197
L_198 ,
F_27 ( V_257 ) ) ;
return V_253 ;
}
static void F_134 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_208 * V_209 = F_2 ( F_3 ( V_3 ) ,
struct V_208 , V_214 ) ;
F_21 ( L_199
L_200 ,
F_27 ( V_3 ) , V_209 -> V_215 ) ;
F_30 ( V_3 ) ;
}
static inline struct V_259 * F_135 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_259 ,
V_260 ) ;
}
static T_1 F_136 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_160 ,
F_44 ( & F_135 ( V_3 ) -> V_261 ) ) ;
}
static T_1 F_137 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_259 * V_262 = F_135 ( V_3 ) ;
struct V_70 * V_71 = V_262 -> V_263 ;
unsigned long V_264 ;
int V_265 , V_29 ;
if ( ! V_262 -> V_266 ) {
F_11 ( L_201
L_202 , V_262 -> V_266 ) ;
return - V_17 ;
}
if ( ! ( V_71 -> V_97 & V_98 ) ) {
F_11 ( L_203
L_204 ) ;
return - V_99 ;
}
V_29 = F_127 ( V_5 , 0 , & V_264 ) ;
if ( V_29 < 0 ) {
F_11 ( L_205
L_11 , V_5 ) ;
return V_29 ;
}
V_265 = ( int ) V_264 ;
if ( ! ( V_262 -> V_267 & V_268 ) ) {
F_11 ( L_206
L_207 ) ;
return - V_17 ;
}
if ( V_262 -> V_267 & V_269 &&
V_265 == V_270 ) {
F_11 ( L_208
L_209 ) ;
return - V_17 ;
}
V_29 = F_138 ( V_262 , V_71 ,
NULL , NULL , V_265 , 0 ) ;
return ( ! V_29 ) ? V_11 : - V_17 ;
}
static T_1 F_139 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_259 * V_262 = F_135 ( V_3 ) ;
return sprintf ( V_5 , L_4 ,
F_140 ( V_262 -> V_271 ) ) ;
}
static T_1 F_141 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
struct V_259 * V_262 = F_135 ( V_3 ) ;
unsigned long V_264 ;
int V_272 , V_29 ;
if ( ! V_262 -> V_266 ) {
F_11 ( L_210
L_211 ,
V_262 -> V_266 ) ;
return - V_17 ;
}
V_29 = F_127 ( V_5 , 0 , & V_264 ) ;
if ( V_29 < 0 ) {
F_11 ( L_212
L_213 , V_5 ) ;
return V_29 ;
}
V_272 = ( int ) V_264 ;
if ( ( V_272 != V_273 ) &&
( V_272 != V_274 ) &&
( V_272 != V_275 ) ) {
F_11 ( L_214 ,
V_272 ) ;
return - V_17 ;
}
V_262 -> V_271 = V_272 ;
return V_11 ;
}
static T_1 F_142 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_143 ( F_135 ( V_3 ) , V_5 ) ;
}
static T_1 F_144 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_145 ( F_135 ( V_3 ) , V_5 , V_11 ) ;
}
static T_1 F_146 (
struct V_2 * V_3 , char * V_5 )
{
return sprintf ( V_5 , L_160 ,
F_135 ( V_3 ) -> V_276 ) ;
}
static T_1 F_147 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
struct V_259 * V_262 = F_135 ( V_3 ) ;
unsigned long V_264 ;
int V_29 ;
V_29 = F_127 ( V_5 , 0 , & V_264 ) ;
if ( V_29 < 0 ) {
F_11 ( L_215 ) ;
return V_29 ;
}
if ( ( V_264 != 0 ) && ( V_264 != 1 ) ) {
F_11 ( L_216
L_217 , V_264 ) ;
return - V_17 ;
}
V_262 -> V_276 = ( int ) V_264 ;
return V_11 ;
}
static T_1 F_148 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_149 ( F_135 ( V_3 ) , V_5 ) ;
}
static T_1 F_150 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_151 ( F_135 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_152 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_153 ( F_135 ( V_3 ) , V_5 ) ;
}
static T_1 F_154 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_155 ( F_135 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_156 (
struct V_2 * V_3 , char * V_5 )
{
return F_157 ( F_135 ( V_3 ) , V_5 ) ;
}
static T_1 F_158 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
return F_159 ( F_135 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_160 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_161 ( F_135 ( V_3 ) , V_5 ) ;
}
static T_1 F_162 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_163 ( F_135 ( V_3 ) , V_5 , V_11 ) ;
}
static T_1 F_164 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_259 * V_262 = F_135 ( V_3 ) ;
if ( ! V_262 -> V_266 )
return 0 ;
return sprintf ( V_5 , L_187 , V_262 -> V_277 ) ;
}
static T_1 F_165 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_259 * V_262 = F_135 ( V_3 ) ;
struct V_27 * V_278 = & V_262 -> V_260 ;
unsigned long V_277 ;
int V_29 ;
V_29 = F_127 ( V_5 , 0 , & V_277 ) ;
if ( V_29 < 0 ) {
F_11 ( L_188
L_218 , V_29 ) ;
return V_29 ;
}
if ( V_277 > 0x0000ffff ) {
F_11 ( L_219
L_191 , V_277 ) ;
return - V_17 ;
}
V_29 = F_166 ( V_262 , ( T_6 ) V_277 ) ;
if ( V_29 < 0 )
return - V_17 ;
F_21 ( L_220
L_221 ,
F_27 ( & V_278 -> V_34 ) ,
V_262 -> V_277 ) ;
return V_11 ;
}
static T_1 F_167 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_259 * V_262 = F_135 ( V_3 ) ;
struct V_279 * V_280 ;
T_1 V_124 = 0 , V_254 ;
unsigned char V_115 [ V_281 ] ;
memset ( V_115 , 0 , V_281 ) ;
F_73 ( & V_262 -> V_282 ) ;
F_18 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
struct V_149 * V_283 = V_280 -> V_284 ;
V_254 = snprintf ( V_115 , V_281 , L_222
L_223 , V_283 -> V_138 -> V_40 () ,
V_283 -> V_138 -> V_41 ( V_283 ) ,
V_283 -> V_138 -> V_42 ( V_283 ) ,
F_27 ( & V_280 -> V_285 . V_34 ) ) ;
V_254 ++ ;
if ( ( V_254 + V_124 ) > V_127 ) {
F_50 ( L_195
L_196 ) ;
break;
}
memcpy ( V_5 + V_124 , V_115 , V_254 ) ;
V_124 += V_254 ;
}
F_75 ( & V_262 -> V_282 ) ;
return V_124 ;
}
static void F_168 ( struct V_2 * V_3 )
{
struct V_259 * V_262 = F_2 ( F_3 ( V_3 ) ,
struct V_259 , V_260 ) ;
F_169 ( V_262 ) ;
}
static struct V_27 * F_170 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_225 * V_286 = F_2 ( V_28 , struct V_225 ,
V_287 ) ;
struct V_259 * V_262 ;
struct V_27 * V_278 = NULL ;
struct V_2 * V_288 = NULL ;
V_262 = F_171 ( V_286 -> V_114 , V_23 , 0 ) ;
if ( ! V_262 )
return NULL ;
V_278 = & V_262 -> V_260 ;
V_288 = & V_278 -> V_34 ;
F_24 ( V_278 , V_23 ,
& V_289 ) ;
F_21 ( L_224
L_225 ,
F_27 ( V_288 ) ) ;
return V_278 ;
}
static void F_172 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_259 * V_262 = F_2 ( F_3 ( V_3 ) ,
struct V_259 , V_260 ) ;
F_21 ( L_226
L_227 ,
F_27 ( V_3 ) , V_262 -> V_277 ) ;
F_30 ( V_3 ) ;
}
static struct V_27 * F_173 (
struct V_27 * V_28 ,
const char * V_23 )
{
return F_23 ( - V_89 ) ;
}
static void F_174 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
return;
}
static struct V_27 * F_175 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_259 * V_262 ;
struct V_2 * V_290 = & V_28 -> V_34 ;
struct V_1 * V_202 = F_1 ( V_290 ) ;
struct V_291 * V_292 = V_202 -> V_293 ;
struct V_70 * V_71 ;
int V_294 = - V_65 , V_29 ;
V_29 = F_176 ( & V_202 -> V_295 ) ;
if ( V_29 )
return F_23 ( V_29 ) ;
V_71 = F_177 ( V_202 , V_23 ) ;
if ( ! V_71 )
goto V_150;
F_24 ( & V_71 -> V_73 , V_23 , & V_292 -> V_296 ) ;
F_24 ( & V_71 -> V_105 . V_69 , L_228 ,
& V_292 -> V_297 ) ;
F_25 ( & V_71 -> V_105 . V_69 , & V_71 -> V_73 ) ;
F_24 ( & V_71 -> V_128 , L_229 ,
& V_292 -> V_298 ) ;
F_25 ( & V_71 -> V_128 , & V_71 -> V_73 ) ;
F_24 ( & V_71 -> V_74 . V_112 , L_230 ,
& V_292 -> V_299 ) ;
F_25 ( & V_71 -> V_74 . V_112 ,
& V_71 -> V_73 ) ;
F_24 ( & V_71 -> V_225 . V_287 ,
L_231 , & V_292 -> V_300 ) ;
F_25 ( & V_71 -> V_225 . V_287 ,
& V_71 -> V_73 ) ;
F_24 ( & V_71 -> V_301 . V_302 ,
L_232 , & V_292 -> V_303 ) ;
F_25 ( & V_71 -> V_301 . V_302 ,
& V_71 -> V_73 ) ;
V_262 = F_171 ( V_71 , L_233 , 1 ) ;
if ( ! V_262 )
goto V_304;
V_71 -> V_225 . V_305 = V_262 ;
F_24 ( & V_262 -> V_260 ,
L_233 , & V_289 ) ;
F_25 ( & V_262 -> V_260 ,
& V_71 -> V_225 . V_287 ) ;
F_178 ( V_71 ) ;
F_10 ( & V_202 -> V_295 ) ;
return & V_71 -> V_73 ;
V_304:
F_123 ( V_71 ) ;
V_150:
F_10 ( & V_202 -> V_295 ) ;
return F_23 ( V_294 ) ;
}
static void F_179 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_27 * V_251 = F_3 ( V_3 ) ;
struct V_70 * V_71 =
F_2 ( V_251 , struct V_70 , V_73 ) ;
struct V_1 * V_202 ;
V_202 = F_1 ( & V_71 -> V_1 -> V_4 . V_34 ) ;
F_8 ( & V_202 -> V_295 ) ;
F_29 ( & V_71 -> V_301 . V_302 ) ;
F_29 ( & V_71 -> V_225 . V_287 ) ;
V_71 -> V_225 . V_305 = NULL ;
F_29 ( V_251 ) ;
F_30 ( V_3 ) ;
F_10 ( & V_202 -> V_295 ) ;
}
static inline struct V_1 * F_180 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_181 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_202 = F_180 ( V_3 ) ;
return sprintf ( V_5 , L_234 ,
V_202 -> V_306 , V_202 -> V_293 -> V_307 -> V_23 ,
V_7 ) ;
}
static T_1 F_182 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_202 = F_180 ( V_3 ) ;
int V_308 = 0 ;
if ( V_202 -> V_309 & V_310 )
V_308 = 1 ;
return sprintf ( V_5 , L_160 , V_308 ) ;
}
static T_1 F_183 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_1 * V_202 = F_180 ( V_3 ) ;
unsigned long V_311 ;
int V_29 ;
if ( V_202 -> V_293 -> V_307 -> V_312 == NULL )
return - V_17 ;
V_29 = F_127 ( V_5 , 0 , & V_311 ) ;
if ( V_29 < 0 ) {
F_11 ( L_235 , V_29 ) ;
return V_29 ;
}
if ( V_202 -> V_313 ) {
F_11 ( L_236 ) ;
return - V_17 ;
}
V_29 = V_202 -> V_293 -> V_307 -> V_312 ( V_202 , V_311 ) ;
if ( V_29 < 0 )
return - V_17 ;
if ( V_29 > 0 )
V_202 -> V_309 |= V_310 ;
else if ( V_29 == 0 )
V_202 -> V_309 &= ~ V_310 ;
return V_11 ;
}
static void F_184 ( struct V_2 * V_3 )
{
struct V_1 * V_202 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_185 ( V_202 ) ;
}
static struct V_27 * F_186 (
struct V_27 * V_28 ,
const char * V_23 )
{
char * V_314 , * V_315 , * V_316 ;
struct V_1 * V_202 ;
char V_115 [ V_317 ] ;
unsigned long V_318 = 0 ;
int V_29 ;
memset ( V_115 , 0 , V_317 ) ;
if ( strlen ( V_23 ) >= V_317 ) {
F_11 ( L_237
L_238 , ( int ) strlen ( V_23 ) ,
V_317 ) ;
return F_23 ( - V_319 ) ;
}
snprintf ( V_115 , V_317 , L_7 , V_23 ) ;
V_315 = strstr ( V_115 , L_239 ) ;
if ( ! V_315 ) {
F_11 ( L_240 ) ;
return F_23 ( - V_17 ) ;
}
V_314 = V_115 ;
V_316 = strstr ( V_315 + 1 , L_239 ) ;
if ( V_316 ) {
* V_316 = '\0' ;
V_316 ++ ;
V_315 = V_316 ;
} else {
* V_315 = '\0' ;
V_315 ++ ;
}
V_29 = F_127 ( V_315 , 0 , & V_318 ) ;
if ( V_29 < 0 ) {
F_11 ( L_188
L_241 , V_29 ) ;
return F_23 ( V_29 ) ;
}
F_187 () ;
V_202 = F_188 ( V_314 , V_318 , 0 ) ;
if ( F_13 ( V_202 ) )
return F_189 ( V_202 ) ;
F_24 ( & V_202 -> V_4 , V_23 ,
& V_320 ) ;
return & V_202 -> V_4 ;
}
static void F_190 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
F_30 ( V_3 ) ;
}
void F_191 ( struct V_291 * V_292 )
{
F_192 ( V_292 ) ;
F_193 ( V_292 ) ;
F_194 ( V_292 ) ;
F_195 ( V_292 ) ;
F_196 ( V_292 ) ;
F_197 ( V_292 ) ;
}
static int T_8 F_198 ( void )
{
struct V_321 * V_322 = & V_36 ;
struct V_208 * V_209 ;
int V_29 ;
F_21 ( L_242
L_243 V_6 L_3 ,
V_7 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
F_199 ( & V_322 -> V_323 ) ;
F_200 ( & V_322 -> V_324 ) ;
V_29 = F_201 () ;
if ( V_29 < 0 )
return V_29 ;
F_24 ( & V_325 , L_244 ,
& V_326 ) ;
F_25 ( & V_325 , & V_322 -> V_323 ) ;
F_24 ( & V_327 , L_231 , & V_328 ) ;
F_25 ( & V_327 , & V_325 ) ;
F_24 ( & V_329 , L_245 ,
& V_330 ) ;
F_25 ( & V_329 , & V_327 ) ;
V_209 = F_133 ( L_246 , 1 ) ;
if ( F_13 ( V_209 ) ) {
V_29 = - V_65 ;
goto V_331;
}
F_24 ( & V_209 -> V_214 , L_246 ,
& V_258 ) ;
F_25 ( & V_209 -> V_214 , & V_329 ) ;
V_332 = V_209 ;
V_29 = F_202 ( V_322 ) ;
if ( V_29 < 0 ) {
F_11 ( L_247 ,
V_29 , V_322 -> V_323 . V_34 . V_333 ) ;
goto V_331;
}
F_21 ( L_248
L_249 V_7 L_250
L_251 V_6 L_3 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
V_29 = F_203 () ;
if ( V_29 < 0 )
goto V_179;
V_29 = F_204 () ;
if ( V_29 < 0 )
goto V_179;
V_29 = F_205 () ;
if ( V_29 < 0 )
goto V_179;
return 0 ;
V_179:
F_206 ( V_322 ) ;
F_207 () ;
F_208 () ;
V_331:
if ( V_332 ) {
F_131 ( V_332 ) ;
V_332 = NULL ;
}
F_209 () ;
return V_29 ;
}
static void T_9 F_210 ( void )
{
F_29 ( & V_329 ) ;
F_29 ( & V_327 ) ;
F_29 ( & V_325 ) ;
F_206 ( & V_36 ) ;
F_131 ( V_332 ) ;
V_332 = NULL ;
F_21 ( L_252
L_253 ) ;
F_207 () ;
F_208 () ;
F_211 () ;
F_209 () ;
}
