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
if ( ! V_38 -> V_62 ) {
F_11 ( L_54 ) ;
return - V_17 ;
}
return 0 ;
}
int F_36 ( const struct V_37 * V_63 )
{
struct V_22 * V_24 ;
int V_29 ;
V_29 = F_35 ( V_63 ) ;
if ( V_29 )
return V_29 ;
V_24 = F_37 ( sizeof( struct V_22 ) , V_64 ) ;
if ( ! V_24 ) {
F_11 ( L_55 , V_65 ) ;
return - V_66 ;
}
F_38 ( & V_24 -> V_67 ) ;
F_39 ( & V_24 -> V_26 , 0 ) ;
V_24 -> V_25 = V_63 ;
F_40 ( V_24 ) ;
F_8 ( & V_15 ) ;
F_41 ( & V_24 -> V_67 , & V_16 ) ;
F_10 ( & V_15 ) ;
return 0 ;
}
void F_42 ( const struct V_37 * V_63 )
{
struct V_22 * V_68 ;
F_8 ( & V_15 ) ;
F_18 (t, &g_tf_list, tf_list) {
if ( ! strcmp ( V_68 -> V_25 -> V_23 , V_63 -> V_23 ) ) {
F_43 ( F_44 ( & V_68 -> V_26 ) ) ;
F_45 ( & V_68 -> V_67 ) ;
F_10 ( & V_15 ) ;
F_46 () ;
F_47 ( V_68 ) ;
return;
}
}
F_10 ( & V_15 ) ;
}
static inline struct V_69 * F_48 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_69 ,
V_70 ) ;
}
static void F_49 ( struct V_71 * V_72 )
{
const char * V_73 ;
V_73 = F_27 ( & V_72 -> V_74 . V_34 ) ;
if ( strlen ( V_73 ) >= 16 ) {
F_50 ( L_56
L_57 , V_72 ,
V_73 ) ;
}
snprintf ( & V_72 -> V_75 . V_76 [ 0 ] , 16 , L_7 , V_73 ) ;
}
static T_1 F_51 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
struct V_71 * V_72 = V_77 -> V_78 ;
bool V_79 ;
int V_29 ;
if ( V_72 -> V_80 ) {
F_11 ( L_58
L_59 ,
V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 ) {
F_49 ( V_72 ) ;
} else {
strncpy ( & V_72 -> V_75 . V_76 [ 0 ] ,
V_72 -> V_81 -> V_82 , 16 ) ;
}
V_77 -> V_83 = V_79 ;
return V_11 ;
}
static T_1 F_53 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 && V_77 -> V_78 -> V_81 -> V_84 ) {
F_11 ( L_60 ) ;
return - V_17 ;
}
V_77 -> V_85 = V_79 ;
F_21 ( L_61 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_54 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
T_3 V_86 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_86 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_86 != 0 && V_86 != 1 && V_86 != 2 ) {
F_11 ( L_62 , V_86 ) ;
return - V_17 ;
}
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_63
L_64 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_87 = V_86 ;
F_21 ( L_65 ,
V_77 -> V_78 , V_86 ) ;
return V_11 ;
}
static T_1 F_56 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_66
L_67 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_88 = V_79 ;
F_21 ( L_68 ,
V_77 -> V_78 , V_79 ? L_69 : L_70 ) ;
return V_11 ;
}
static T_1 F_57 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 && ! V_77 -> V_89 ) {
F_11 ( L_71 ) ;
return - V_90 ;
}
V_77 -> V_91 = V_79 ;
F_21 ( L_72 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_58 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 && ! V_77 -> V_89 ) {
F_11 ( L_71 ) ;
return - V_90 ;
}
V_77 -> V_92 = V_79 ;
F_21 ( L_73 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_59 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
int V_93 = V_77 -> V_94 , V_29 ;
struct V_71 * V_72 = V_77 -> V_78 ;
T_3 V_79 ;
V_29 = F_55 ( V_5 , 0 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 != 0 && V_79 != 1 && V_79 != 2 && V_79 != 3 ) {
F_11 ( L_74 , V_79 ) ;
return - V_17 ;
}
if ( V_79 == 2 ) {
F_11 ( L_75 ) ;
return - V_90 ;
}
if ( V_77 -> V_95 ) {
F_50 ( L_76
L_77 ) ;
return V_11 ;
}
if ( ! V_72 -> V_81 -> V_96 || ! V_72 -> V_81 -> V_97 ) {
if ( V_79 == 0 )
return V_11 ;
F_11 ( L_78 ,
V_72 -> V_81 -> V_23 ) ;
return - V_90 ;
}
if ( ! ( V_72 -> V_98 & V_99 ) ) {
F_11 ( L_79 ) ;
return - V_100 ;
}
if ( V_72 -> V_80 ) {
F_11 ( L_80
L_67 , V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_94 = V_79 ;
if ( V_79 && ! V_93 ) {
V_29 = V_72 -> V_81 -> V_96 ( V_72 ) ;
if ( V_29 ) {
V_77 -> V_94 = V_93 ;
return V_29 ;
}
} else if ( ! V_79 && V_93 ) {
V_72 -> V_81 -> V_97 ( V_72 ) ;
}
F_21 ( L_81 , V_72 , V_79 ) ;
return V_11 ;
}
static T_1 F_60 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
struct V_71 * V_72 = V_77 -> V_78 ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! V_79 )
return V_11 ;
if ( ! V_72 -> V_81 -> V_101 ) {
F_11 ( L_82 ,
V_72 -> V_81 -> V_23 ) ;
return - V_90 ;
}
if ( ! ( V_72 -> V_98 & V_99 ) ) {
F_11 ( L_83 ) ;
return - V_100 ;
}
if ( V_72 -> V_80 ) {
F_11 ( L_84
L_67 , V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
V_29 = V_72 -> V_81 -> V_101 ( V_72 ) ;
if ( V_29 )
return V_29 ;
F_21 ( L_85 , V_72 ) ;
return V_11 ;
}
static T_1 F_61 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_86
L_67 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_102 = V_79 ;
F_21 ( L_87 , V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_62 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 != 0 ) {
F_63 ( V_103 L_88
L_89 , V_77 -> V_78 ) ;
return - V_90 ;
}
V_77 -> V_104 = V_79 ;
F_21 ( L_90 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_64 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_63
L_91 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
if ( V_79 && ! V_77 -> V_89 ) {
F_11 ( L_92
L_93 ,
V_77 -> V_78 ) ;
return - V_90 ;
}
V_77 -> V_105 = V_79 ;
F_21 ( L_94 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_65 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
struct V_71 * V_72 = V_77 -> V_78 ;
T_3 V_86 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_86 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_72 -> V_80 ) {
F_11 ( L_95
L_67 ,
V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
if ( ! V_86 ) {
F_11 ( L_96 , V_72 ) ;
return - V_17 ;
}
if ( V_86 > V_72 -> V_106 . V_107 ) {
if ( V_86 > V_72 -> V_106 . V_108 ) {
F_11 ( L_97
L_98
L_99 , V_72 , V_86 ,
V_72 -> V_106 . V_108 ) ;
return - V_17 ;
}
}
V_77 -> V_107 = V_72 -> V_107 = V_86 ;
F_21 ( L_100 , V_72 , V_86 ) ;
return V_11 ;
}
static T_1 F_66 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
T_3 V_86 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_86 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_63
L_101 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
if ( V_86 > V_77 -> V_109 ) {
F_11 ( L_102
L_103 ,
V_77 -> V_78 , V_86 , V_77 -> V_109 ) ;
return - V_17 ;
}
V_77 -> V_110 = V_86 ;
F_21 ( L_104 ,
V_77 -> V_78 , V_86 ) ;
return V_11 ;
}
static T_1 F_67 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
T_3 V_86 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_86 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_105
L_59 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
if ( V_86 != 512 && V_86 != 1024 && V_86 != 2048 && V_86 != 4096 ) {
F_11 ( L_106
L_107 ,
V_77 -> V_78 , V_86 ) ;
return - V_17 ;
}
V_77 -> V_111 = V_86 ;
if ( V_77 -> V_112 )
V_77 -> V_109 = V_77 -> V_112 / V_86 ;
F_21 ( L_108 ,
V_77 -> V_78 , V_86 ) ;
return V_11 ;
}
static struct V_75 * F_68 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_75 , V_113 ) ;
}
static T_1 F_69 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_109 ,
& F_68 ( V_3 ) -> V_114 [ 0 ] ) ;
}
static T_1 F_70 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_75 * V_75 = F_68 ( V_3 ) ;
struct V_71 * V_72 = V_75 -> V_115 ;
unsigned char V_116 [ V_117 ] ;
if ( V_72 -> V_98 & V_118 ) {
F_11 ( L_110
L_111 ) ;
return - V_119 ;
}
if ( strlen ( V_5 ) >= V_117 ) {
F_11 ( L_112
L_113 , V_117 ) ;
return - V_120 ;
}
if ( V_72 -> V_80 ) {
F_11 ( L_114
L_115 ,
V_72 -> V_80 ) ;
return - V_17 ;
}
memset ( V_116 , 0 , V_117 ) ;
snprintf ( V_116 , V_117 , L_7 , V_5 ) ;
snprintf ( V_72 -> V_75 . V_114 , V_117 ,
L_7 , F_71 ( V_116 ) ) ;
V_72 -> V_98 |= V_121 ;
F_21 ( L_116
L_11 , V_72 -> V_75 . V_114 ) ;
return V_11 ;
}
static T_1 F_72 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_75 * V_75 = F_68 ( V_3 ) ;
struct V_122 * V_123 ;
unsigned char V_116 [ V_124 ] ;
T_1 V_125 = 0 ;
memset ( V_116 , 0 , V_124 ) ;
F_73 ( & V_75 -> V_126 ) ;
F_18 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_123 -> V_127 )
continue;
F_74 ( V_123 , V_116 , V_124 ) ;
if ( V_125 + strlen ( V_116 ) >= V_128 )
break;
V_125 += sprintf ( V_5 + V_125 , L_7 , V_116 ) ;
}
F_75 ( & V_75 -> V_126 ) ;
return V_125 ;
}
static struct V_71 * F_76 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_71 ,
V_129 ) ;
}
static T_1 F_77 ( struct V_71 * V_72 ,
char * V_5 )
{
struct V_130 * V_131 ;
struct V_132 * V_133 ;
char V_134 [ V_135 ] ;
memset ( V_134 , 0 , V_135 ) ;
V_133 = V_72 -> V_136 ;
if ( ! V_133 )
return sprintf ( V_5 , L_117 ) ;
V_131 = V_133 -> V_137 ;
F_78 ( V_133 , V_134 , V_135 ) ;
return sprintf ( V_5 , L_118 ,
V_131 -> V_138 -> V_139 -> V_40 () ,
V_131 -> V_140 , V_134 ) ;
}
static T_1 F_79 ( struct V_71 * V_72 ,
char * V_5 )
{
struct V_130 * V_131 ;
T_1 V_125 ;
V_131 = V_72 -> V_141 ;
if ( V_131 ) {
V_125 = sprintf ( V_5 ,
L_119 ,
V_131 -> V_138 -> V_139 -> V_40 () ,
V_131 -> V_140 ) ;
} else {
V_125 = sprintf ( V_5 , L_120 ) ;
}
return V_125 ;
}
static T_1 F_80 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_76 ( V_3 ) ;
int V_29 ;
if ( V_72 -> V_81 -> V_142 & V_143 )
return sprintf ( V_5 , L_121 ) ;
F_73 ( & V_72 -> V_144 ) ;
if ( V_72 -> V_145 & V_146 )
V_29 = F_79 ( V_72 , V_5 ) ;
else
V_29 = F_77 ( V_72 , V_5 ) ;
F_75 ( & V_72 -> V_144 ) ;
return V_29 ;
}
static T_1 F_81 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_76 ( V_3 ) ;
T_1 V_125 = 0 ;
F_73 ( & V_72 -> V_144 ) ;
if ( ! V_72 -> V_136 ) {
V_125 = sprintf ( V_5 , L_117 ) ;
} else if ( V_72 -> V_136 -> V_147 ) {
V_125 = sprintf ( V_5 , L_122
L_123 ) ;
} else {
V_125 = sprintf ( V_5 , L_124
L_125 ) ;
}
F_75 ( & V_72 -> V_144 ) ;
return V_125 ;
}
static T_1 F_82 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_126 , F_76 ( V_3 ) -> V_148 . V_149 ) ;
}
static T_1 F_83 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_76 ( V_3 ) ;
struct V_130 * V_131 ;
struct V_150 * V_138 ;
struct V_132 * V_133 ;
const struct V_37 * V_38 ;
T_1 V_125 = 0 ;
F_73 ( & V_72 -> V_144 ) ;
V_133 = V_72 -> V_136 ;
if ( ! V_133 ) {
V_125 = sprintf ( V_5 , L_117 ) ;
goto V_151;
}
V_131 = V_133 -> V_137 ;
V_138 = V_131 -> V_138 ;
V_38 = V_138 -> V_139 ;
V_125 += sprintf ( V_5 + V_125 , L_127
L_128 , V_38 -> V_40 () ,
V_38 -> V_41 ( V_138 ) ) ;
V_125 += sprintf ( V_5 + V_125 , L_129
L_130
L_131 , V_133 -> V_152 ,
V_38 -> V_40 () , V_38 -> V_42 ( V_138 ) ,
V_38 -> V_40 () , V_133 -> V_153 ) ;
V_151:
F_75 ( & V_72 -> V_144 ) ;
return V_125 ;
}
static T_1 F_84 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_76 ( V_3 ) ;
const struct V_37 * V_38 ;
struct V_132 * V_133 ;
unsigned char V_116 [ 384 ] ;
char V_134 [ V_135 ] ;
T_1 V_125 = 0 ;
int V_154 = 0 ;
V_125 += sprintf ( V_5 + V_125 , L_132 ) ;
F_73 ( & V_72 -> V_148 . V_155 ) ;
F_18 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_116 , 0 , 384 ) ;
memset ( V_134 , 0 , V_135 ) ;
V_38 = V_133 -> V_137 -> V_138 -> V_139 ;
F_78 ( V_133 , V_134 ,
V_135 ) ;
sprintf ( V_116 , L_133 ,
V_38 -> V_40 () ,
V_133 -> V_137 -> V_140 , V_134 , V_133 -> V_156 ,
V_133 -> V_157 ) ;
if ( V_125 + strlen ( V_116 ) >= V_128 )
break;
V_125 += sprintf ( V_5 + V_125 , L_7 , V_116 ) ;
V_154 ++ ;
}
F_75 ( & V_72 -> V_148 . V_155 ) ;
if ( ! V_154 )
V_125 += sprintf ( V_5 + V_125 , L_134 ) ;
return V_125 ;
}
static T_1 F_85 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_76 ( V_3 ) ;
struct V_132 * V_133 ;
T_1 V_125 = 0 ;
F_73 ( & V_72 -> V_144 ) ;
V_133 = V_72 -> V_136 ;
if ( V_133 ) {
V_125 = sprintf ( V_5 , L_135 ,
F_86 ( V_133 -> V_158 ) ) ;
} else {
V_125 = sprintf ( V_5 , L_117 ) ;
}
F_75 ( & V_72 -> V_144 ) ;
return V_125 ;
}
static T_1 F_87 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_76 ( V_3 ) ;
if ( V_72 -> V_81 -> V_142 & V_143 )
return sprintf ( V_5 , L_136 ) ;
else if ( V_72 -> V_145 & V_146 )
return sprintf ( V_5 , L_137 ) ;
else
return sprintf ( V_5 , L_138 ) ;
}
static T_1 F_88 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_76 ( V_3 ) ;
if ( V_72 -> V_81 -> V_142 & V_143 )
return 0 ;
return sprintf ( V_5 , L_139 ,
( V_72 -> V_148 . V_159 ) ? L_140 : L_70 ) ;
}
static T_1 F_89 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_76 ( V_3 ) ;
if ( V_72 -> V_81 -> V_142 & V_143 )
return 0 ;
return sprintf ( V_5 , L_141 ) ;
}
static T_1 F_90 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_76 ( V_3 ) ;
unsigned char * V_160 = NULL , * V_161 = NULL , * V_162 = NULL ;
unsigned char * V_163 = NULL , * V_164 = NULL ;
char * V_165 , * V_166 , * V_167 ;
T_4 args [ V_168 ] ;
unsigned long long V_169 ;
T_5 V_170 = 0 ;
T_5 V_171 = 0 , V_172 = 0 ;
int V_29 = - 1 , V_173 = 0 , V_174 = 0 , V_175 , V_176 ;
T_6 V_177 = 0 ;
T_7 type = 0 ;
if ( V_72 -> V_81 -> V_142 & V_143 )
return V_11 ;
if ( V_72 -> V_145 & V_146 )
return V_11 ;
if ( V_72 -> V_80 ) {
F_21 ( L_142
L_143 ) ;
return - V_17 ;
}
V_167 = F_91 ( V_5 , V_64 ) ;
if ( ! V_167 )
return - V_66 ;
V_165 = V_167 ;
while ( ( V_166 = F_92 ( & V_167 , L_144 ) ) != NULL ) {
if ( ! * V_166 )
continue;
V_176 = F_93 ( V_166 , V_178 , args ) ;
switch ( V_176 ) {
case V_179 :
V_160 = F_94 ( args ) ;
if ( ! V_160 ) {
V_29 = - V_66 ;
goto V_180;
}
break;
case V_181 :
V_161 = F_94 ( args ) ;
if ( ! V_161 ) {
V_29 = - V_66 ;
goto V_180;
}
if ( strlen ( V_161 ) >= V_182 ) {
F_11 ( L_145
L_146 ,
V_182 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_183 :
V_162 = F_94 ( args ) ;
if ( ! V_162 ) {
V_29 = - V_66 ;
goto V_180;
}
if ( strlen ( V_162 ) >= V_184 ) {
F_11 ( L_147
L_148 ,
V_184 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_185 :
V_29 = F_95 ( args -> V_186 , 0 , & V_169 ) ;
if ( V_29 < 0 ) {
F_11 ( L_149 ) ;
goto V_180;
}
V_170 = ( T_5 ) V_169 ;
break;
case V_187 :
V_29 = F_96 ( args , & V_175 ) ;
if ( V_29 )
goto V_180;
V_173 = V_175 ;
break;
case V_188 :
V_29 = F_96 ( args , & V_175 ) ;
if ( V_29 )
goto V_180;
type = ( T_7 ) V_175 ;
break;
case V_189 :
V_29 = F_96 ( args , & V_175 ) ;
if ( V_29 )
goto V_180;
break;
case V_190 :
V_29 = F_96 ( args , & V_175 ) ;
if ( V_29 )
goto V_180;
V_174 = ( int ) V_175 ;
break;
case V_191 :
V_29 = F_96 ( args , & V_175 ) ;
if ( V_29 )
goto V_180;
V_171 = ( T_5 ) V_175 ;
break;
case V_192 :
V_163 = F_94 ( args ) ;
if ( ! V_163 ) {
V_29 = - V_66 ;
goto V_180;
}
break;
case V_193 :
V_164 = F_94 ( args ) ;
if ( ! V_164 ) {
V_29 = - V_66 ;
goto V_180;
}
if ( strlen ( V_164 ) >= V_194 ) {
F_11 ( L_150
L_151 ,
V_194 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_195 :
V_29 = F_96 ( args , & V_175 ) ;
if ( V_29 )
goto V_180;
V_177 = ( T_6 ) V_175 ;
break;
case V_196 :
V_29 = F_96 ( args , & V_175 ) ;
if ( V_29 )
goto V_180;
break;
case V_197 :
V_29 = F_96 ( args , & V_175 ) ;
if ( V_29 )
goto V_180;
V_172 = ( T_5 ) V_175 ;
break;
default:
break;
}
}
if ( ! V_161 || ! V_164 || ! V_170 ) {
F_11 ( L_152 ) ;
V_29 = - V_17 ;
goto V_180;
}
if ( V_173 && ! ( type ) ) {
F_11 ( L_153
L_154 , type ) ;
V_29 = - V_17 ;
goto V_180;
}
V_29 = F_97 ( & V_72 -> V_148 , V_170 ,
V_161 , V_162 , V_171 , V_164 , V_177 , V_172 ,
V_173 , V_174 , type ) ;
V_180:
F_47 ( V_160 ) ;
F_47 ( V_161 ) ;
F_47 ( V_162 ) ;
F_47 ( V_163 ) ;
F_47 ( V_164 ) ;
F_47 ( V_165 ) ;
return ( V_29 == 0 ) ? V_11 : V_29 ;
}
static inline struct V_71 * F_98 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_71 , V_74 ) ;
}
static T_1 F_99 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
int V_198 = 0 ;
T_1 V_12 = 0 ;
F_100 ( V_72 , V_5 , & V_198 ) ;
V_12 += V_198 ;
V_12 += V_72 -> V_81 -> V_199 ( V_72 ,
V_5 + V_12 ) ;
return V_12 ;
}
static T_1 F_101 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
return V_72 -> V_81 -> V_200 ( V_72 , V_5 , V_11 ) ;
}
static T_1 F_102 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
if ( ! ( V_72 -> V_98 & V_201 ) )
return 0 ;
return snprintf ( V_5 , V_128 , L_4 , V_72 -> V_202 ) ;
}
static T_1 F_103 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
struct V_1 * V_203 = V_72 -> V_1 ;
T_1 V_12 ;
if ( V_11 > ( V_204 - 1 ) ) {
F_11 ( L_155
L_156 , ( int ) V_11 ,
V_204 - 1 ) ;
return - V_17 ;
}
V_12 = snprintf ( & V_72 -> V_202 [ 0 ] , V_204 , L_7 , V_5 ) ;
if ( ! V_12 )
return - V_17 ;
if ( V_72 -> V_202 [ V_12 - 1 ] == '\n' )
V_72 -> V_202 [ V_12 - 1 ] = '\0' ;
V_72 -> V_98 |= V_201 ;
F_21 ( L_157 ,
F_27 ( & V_203 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
V_72 -> V_202 ) ;
return V_12 ;
}
static T_1 F_104 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
if ( ! ( V_72 -> V_98 & V_205 ) )
return 0 ;
return snprintf ( V_5 , V_128 , L_4 , V_72 -> V_206 ) ;
}
static T_1 F_105 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
struct V_1 * V_203 = V_72 -> V_1 ;
T_1 V_12 ;
if ( V_11 > ( V_207 - 1 ) ) {
F_11 ( L_158
L_159 , ( int ) V_11 ,
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
F_21 ( L_160 ,
F_27 ( & V_203 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
V_72 -> V_206 ) ;
return V_12 ;
}
static T_1 F_106 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
return snprintf ( V_5 , V_128 , L_161 , ! ! ( V_72 -> V_98 & V_99 ) ) ;
}
static T_1 F_107 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
char * V_166 ;
int V_29 ;
V_166 = strstr ( V_5 , L_162 ) ;
if ( ! V_166 ) {
F_11 ( L_163
L_164 ) ;
return - V_17 ;
}
V_29 = F_108 ( V_72 ) ;
if ( V_29 )
return V_29 ;
return V_11 ;
}
static T_1 F_109 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
struct V_2 * V_208 ;
struct V_209 * V_210 ;
struct V_211 * V_212 ;
T_1 V_125 = 0 ;
V_212 = V_72 -> V_213 ;
if ( ! V_212 )
return 0 ;
F_73 ( & V_212 -> V_214 ) ;
V_210 = V_212 -> V_210 ;
if ( V_210 ) {
V_208 = & V_210 -> V_215 . V_34 ;
V_125 += sprintf ( V_5 , L_165 ,
F_27 ( V_208 ) , V_210 -> V_216 ) ;
}
F_75 ( & V_212 -> V_214 ) ;
return V_125 ;
}
static T_1 F_110 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
struct V_1 * V_203 = V_72 -> V_1 ;
struct V_209 * V_210 = NULL , * V_217 = NULL ;
struct V_211 * V_212 ;
unsigned char V_116 [ V_218 ] ;
int V_219 = 0 ;
V_212 = V_72 -> V_213 ;
if ( ! V_212 )
return V_11 ;
if ( V_11 > V_218 ) {
F_11 ( L_166 ) ;
return - V_17 ;
}
memset ( V_116 , 0 , V_218 ) ;
memcpy ( V_116 , V_5 , V_11 ) ;
if ( strcmp ( F_71 ( V_116 ) , L_167 ) ) {
V_217 = F_111 ( F_71 ( V_116 ) ) ;
if ( ! V_217 )
return - V_100 ;
}
F_73 ( & V_212 -> V_214 ) ;
V_210 = V_212 -> V_210 ;
if ( V_210 ) {
if ( ! V_217 ) {
F_21 ( L_168
L_169
L_170 ,
F_27 ( & V_203 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
F_27 ( & V_210 -> V_215 . V_34 ) ,
V_210 -> V_216 ) ;
F_112 ( V_212 , V_210 ) ;
F_75 ( & V_212 -> V_214 ) ;
return V_11 ;
}
F_112 ( V_212 , V_210 ) ;
V_219 = 1 ;
}
F_113 ( V_212 , V_217 ) ;
F_75 ( & V_212 -> V_214 ) ;
F_21 ( L_171
L_172 ,
( V_219 ) ? L_173 : L_174 ,
F_27 ( & V_203 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
F_27 ( & V_217 -> V_215 . V_34 ) ,
V_217 -> V_216 ) ;
F_114 ( V_217 ) ;
return V_11 ;
}
static T_1 F_115 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
struct V_220 * V_221 ;
struct V_222 * V_223 ;
char * V_224 = V_5 ;
int V_198 = 0 ;
char V_225 ;
F_73 ( & V_72 -> V_226 . V_227 ) ;
if ( ! F_9 ( & V_72 -> V_226 . V_228 ) )
V_198 += sprintf ( V_224 + V_198 , L_175 ,
V_72 -> V_226 . V_229 ,
V_72 -> V_226 . V_230 ) ;
F_18 (map, &dev->t10_alua.lba_map_list, lba_map_list) {
V_198 += sprintf ( V_224 + V_198 , L_176 ,
V_221 -> V_231 , V_221 -> V_232 ) ;
F_18 (mem, &map->lba_map_mem_list,
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
V_198 += sprintf ( V_224 + V_198 , L_177 ,
V_223 -> V_238 , V_225 ) ;
}
V_198 += sprintf ( V_224 + V_198 , L_3 ) ;
}
F_75 ( & V_72 -> V_226 . V_227 ) ;
return V_198 ;
}
static T_1 F_116 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_98 ( V_3 ) ;
struct V_220 * V_239 = NULL ;
struct V_240 V_241 ;
char * V_242 , * V_165 , * V_166 ;
char V_225 ;
int V_243 = - 1 , V_244 ;
int V_29 = 0 , V_245 = 0 , V_246 , V_247 ;
unsigned long V_248 = - 1 , V_249 = - 1 ;
unsigned long V_250 = - 1 , V_251 = - 1 ;
V_165 = V_242 = F_91 ( V_5 , V_64 ) ;
if ( ! V_242 )
return - V_66 ;
F_38 ( & V_241 ) ;
while ( ( V_166 = F_92 ( & V_242 , L_3 ) ) != NULL ) {
if ( ! * V_166 )
continue;
if ( V_245 == 0 ) {
if ( sscanf ( V_166 , L_178 ,
& V_250 , & V_251 ) != 2 ) {
F_11 ( L_179 , V_245 ) ;
V_29 = - V_17 ;
break;
}
V_245 ++ ;
continue;
}
if ( sscanf ( V_166 , L_180 , & V_248 , & V_249 ) != 2 ) {
F_11 ( L_179 , V_245 ) ;
V_29 = - V_17 ;
break;
}
V_166 = strchr ( V_166 , ' ' ) ;
if ( ! V_166 ) {
F_11 ( L_181 , V_245 ) ;
V_29 = - V_17 ;
break;
}
V_166 ++ ;
V_166 = strchr ( V_166 , ' ' ) ;
if ( ! V_166 ) {
F_11 ( L_182 ,
V_245 ) ;
V_29 = - V_17 ;
break;
}
V_166 ++ ;
V_239 = F_117 ( & V_241 ,
V_248 , V_249 ) ;
if ( F_13 ( V_239 ) ) {
V_29 = F_118 ( V_239 ) ;
break;
}
V_244 = 0 ;
while ( sscanf ( V_166 , L_183 , & V_246 , & V_225 ) == 2 ) {
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
F_11 ( L_184 , V_225 ) ;
V_29 = - V_17 ;
goto V_180;
}
V_29 = F_119 ( V_239 ,
V_246 , V_247 ) ;
if ( V_29 ) {
F_11 ( L_185
L_186 ,
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
F_11 ( L_187
L_186 , V_244 , V_243 , V_245 ) ;
V_29 = - V_17 ;
break;
}
V_245 ++ ;
}
V_180:
if ( V_29 ) {
F_120 ( & V_241 ) ;
V_11 = V_29 ;
} else
F_121 ( V_72 , & V_241 ,
V_250 , V_251 ) ;
F_47 ( V_165 ) ;
return V_11 ;
}
static void F_122 ( struct V_2 * V_3 )
{
struct V_27 * V_252 = F_3 ( V_3 ) ;
struct V_71 * V_72 =
F_2 ( V_252 , struct V_71 , V_74 ) ;
F_123 ( V_72 ) ;
}
static inline struct V_209 * F_124 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_209 ,
V_215 ) ;
}
static T_1 F_125 ( struct V_2 * V_3 , char * V_5 )
{
struct V_209 * V_210 = F_124 ( V_3 ) ;
if ( ! V_210 -> V_253 )
return 0 ;
return sprintf ( V_5 , L_188 , V_210 -> V_216 ) ;
}
static T_1 F_126 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_209 * V_210 = F_124 ( V_3 ) ;
struct V_27 * V_254 = & V_210 -> V_215 ;
unsigned long V_216 ;
int V_29 ;
V_29 = F_127 ( V_5 , 0 , & V_216 ) ;
if ( V_29 < 0 ) {
F_11 ( L_189
L_190 , V_29 ) ;
return V_29 ;
}
if ( V_216 > 0x0000ffff ) {
F_11 ( L_191
L_192 , V_216 ) ;
return - V_17 ;
}
V_29 = F_128 ( V_210 , ( T_6 ) V_216 ) ;
if ( V_29 < 0 )
return - V_17 ;
F_21 ( L_193
L_194 ,
F_27 ( & V_254 -> V_34 ) ,
V_210 -> V_216 ) ;
return V_11 ;
}
static T_1 F_129 ( struct V_2 * V_3 , char * V_5 )
{
struct V_209 * V_210 = F_124 ( V_3 ) ;
struct V_71 * V_72 ;
struct V_1 * V_203 ;
struct V_211 * V_212 ;
T_1 V_125 = 0 , V_255 ;
unsigned char V_116 [ V_218 ] ;
memset ( V_116 , 0 , V_218 ) ;
F_73 ( & V_210 -> V_256 ) ;
F_18 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_72 = V_212 -> V_257 ;
V_203 = V_72 -> V_1 ;
V_255 = snprintf ( V_116 , V_218 , L_195 ,
F_27 ( & V_203 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ) ;
V_255 ++ ;
if ( ( V_255 + V_125 ) > V_128 ) {
F_50 ( L_196
L_197 ) ;
break;
}
memcpy ( V_5 + V_125 , V_116 , V_255 ) ;
V_125 += V_255 ;
}
F_75 ( & V_210 -> V_256 ) ;
return V_125 ;
}
static void F_130 ( struct V_2 * V_3 )
{
struct V_209 * V_210 = F_2 ( F_3 ( V_3 ) ,
struct V_209 , V_215 ) ;
F_131 ( V_210 ) ;
}
static struct V_27 * F_132 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_209 * V_210 ;
struct V_27 * V_254 = NULL ;
struct V_2 * V_258 = NULL ;
V_210 = F_133 ( V_23 , 0 ) ;
if ( F_13 ( V_210 ) )
return NULL ;
V_254 = & V_210 -> V_215 ;
V_258 = & V_254 -> V_34 ;
F_24 ( V_254 , V_23 ,
& V_259 ) ;
F_21 ( L_198
L_199 ,
F_27 ( V_258 ) ) ;
return V_254 ;
}
static void F_134 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_209 * V_210 = F_2 ( F_3 ( V_3 ) ,
struct V_209 , V_215 ) ;
F_21 ( L_200
L_201 ,
F_27 ( V_3 ) , V_210 -> V_216 ) ;
F_30 ( V_3 ) ;
}
static inline struct V_260 * F_135 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_260 ,
V_261 ) ;
}
static T_1 F_136 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_161 ,
F_135 ( V_3 ) -> V_262 ) ;
}
static T_1 F_137 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_260 * V_263 = F_135 ( V_3 ) ;
struct V_71 * V_72 = V_263 -> V_264 ;
unsigned long V_265 ;
int V_266 , V_29 ;
if ( ! V_263 -> V_267 ) {
F_11 ( L_202
L_203 , V_263 -> V_267 ) ;
return - V_17 ;
}
if ( ! ( V_72 -> V_98 & V_99 ) ) {
F_11 ( L_204
L_205 ) ;
return - V_100 ;
}
V_29 = F_127 ( V_5 , 0 , & V_265 ) ;
if ( V_29 < 0 ) {
F_11 ( L_206
L_11 , V_5 ) ;
return V_29 ;
}
V_266 = ( int ) V_265 ;
if ( ! ( V_263 -> V_268 & V_269 ) ) {
F_11 ( L_207
L_208 ) ;
return - V_17 ;
}
if ( V_263 -> V_268 & V_270 &&
V_266 == V_271 ) {
F_11 ( L_209
L_210 ) ;
return - V_17 ;
}
V_29 = F_138 ( V_263 , V_72 ,
NULL , NULL , V_266 , 0 ) ;
return ( ! V_29 ) ? V_11 : - V_17 ;
}
static T_1 F_139 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_260 * V_263 = F_135 ( V_3 ) ;
return sprintf ( V_5 , L_4 ,
F_140 ( V_263 -> V_272 ) ) ;
}
static T_1 F_141 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
struct V_260 * V_263 = F_135 ( V_3 ) ;
unsigned long V_265 ;
int V_273 , V_29 ;
if ( ! V_263 -> V_267 ) {
F_11 ( L_211
L_212 ,
V_263 -> V_267 ) ;
return - V_17 ;
}
V_29 = F_127 ( V_5 , 0 , & V_265 ) ;
if ( V_29 < 0 ) {
F_11 ( L_213
L_214 , V_5 ) ;
return V_29 ;
}
V_273 = ( int ) V_265 ;
if ( ( V_273 != V_274 ) &&
( V_273 != V_275 ) &&
( V_273 != V_276 ) ) {
F_11 ( L_215 ,
V_273 ) ;
return - V_17 ;
}
V_263 -> V_272 = V_273 ;
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
return sprintf ( V_5 , L_161 ,
F_135 ( V_3 ) -> V_277 ) ;
}
static T_1 F_147 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
struct V_260 * V_263 = F_135 ( V_3 ) ;
unsigned long V_265 ;
int V_29 ;
V_29 = F_127 ( V_5 , 0 , & V_265 ) ;
if ( V_29 < 0 ) {
F_11 ( L_216 ) ;
return V_29 ;
}
if ( ( V_265 != 0 ) && ( V_265 != 1 ) ) {
F_11 ( L_217
L_218 , V_265 ) ;
return - V_17 ;
}
V_263 -> V_277 = ( int ) V_265 ;
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
struct V_260 * V_263 = F_135 ( V_3 ) ;
if ( ! V_263 -> V_267 )
return 0 ;
return sprintf ( V_5 , L_188 , V_263 -> V_278 ) ;
}
static T_1 F_165 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_260 * V_263 = F_135 ( V_3 ) ;
struct V_27 * V_279 = & V_263 -> V_261 ;
unsigned long V_278 ;
int V_29 ;
V_29 = F_127 ( V_5 , 0 , & V_278 ) ;
if ( V_29 < 0 ) {
F_11 ( L_189
L_219 , V_29 ) ;
return V_29 ;
}
if ( V_278 > 0x0000ffff ) {
F_11 ( L_220
L_192 , V_278 ) ;
return - V_17 ;
}
V_29 = F_166 ( V_263 , ( T_6 ) V_278 ) ;
if ( V_29 < 0 )
return - V_17 ;
F_21 ( L_221
L_222 ,
F_27 ( & V_279 -> V_34 ) ,
V_263 -> V_278 ) ;
return V_11 ;
}
static T_1 F_167 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_260 * V_263 = F_135 ( V_3 ) ;
struct V_280 * V_281 ;
T_1 V_125 = 0 , V_255 ;
unsigned char V_116 [ V_282 ] ;
memset ( V_116 , 0 , V_282 ) ;
F_73 ( & V_263 -> V_283 ) ;
F_18 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
struct V_150 * V_284 = V_281 -> V_285 ;
V_255 = snprintf ( V_116 , V_282 , L_223
L_224 , V_284 -> V_139 -> V_40 () ,
V_284 -> V_139 -> V_41 ( V_284 ) ,
V_284 -> V_139 -> V_42 ( V_284 ) ,
F_27 ( & V_281 -> V_286 . V_34 ) ) ;
V_255 ++ ;
if ( ( V_255 + V_125 ) > V_128 ) {
F_50 ( L_196
L_197 ) ;
break;
}
memcpy ( V_5 + V_125 , V_116 , V_255 ) ;
V_125 += V_255 ;
}
F_75 ( & V_263 -> V_283 ) ;
return V_125 ;
}
static void F_168 ( struct V_2 * V_3 )
{
struct V_260 * V_263 = F_2 ( F_3 ( V_3 ) ,
struct V_260 , V_261 ) ;
F_169 ( V_263 ) ;
}
static struct V_27 * F_170 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_226 * V_287 = F_2 ( V_28 , struct V_226 ,
V_288 ) ;
struct V_260 * V_263 ;
struct V_27 * V_279 = NULL ;
struct V_2 * V_289 = NULL ;
V_263 = F_171 ( V_287 -> V_115 , V_23 , 0 ) ;
if ( ! V_263 )
return NULL ;
V_279 = & V_263 -> V_261 ;
V_289 = & V_279 -> V_34 ;
F_24 ( V_279 , V_23 ,
& V_290 ) ;
F_21 ( L_225
L_226 ,
F_27 ( V_289 ) ) ;
return V_279 ;
}
static void F_172 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_260 * V_263 = F_2 ( F_3 ( V_3 ) ,
struct V_260 , V_261 ) ;
F_21 ( L_227
L_228 ,
F_27 ( V_3 ) , V_263 -> V_278 ) ;
F_30 ( V_3 ) ;
}
static struct V_27 * F_173 (
struct V_27 * V_28 ,
const char * V_23 )
{
return F_23 ( - V_90 ) ;
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
struct V_260 * V_263 ;
struct V_2 * V_291 = & V_28 -> V_34 ;
struct V_1 * V_203 = F_1 ( V_291 ) ;
struct V_292 * V_293 = V_203 -> V_294 ;
struct V_71 * V_72 ;
int V_295 = - V_66 , V_29 ;
V_29 = F_176 ( & V_203 -> V_296 ) ;
if ( V_29 )
return F_23 ( V_29 ) ;
V_72 = F_177 ( V_203 , V_23 ) ;
if ( ! V_72 )
goto V_151;
F_24 ( & V_72 -> V_74 , V_23 , & V_293 -> V_297 ) ;
F_24 ( & V_72 -> V_106 . V_70 , L_229 ,
& V_293 -> V_298 ) ;
F_25 ( & V_72 -> V_106 . V_70 , & V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_129 , L_230 ,
& V_293 -> V_299 ) ;
F_25 ( & V_72 -> V_129 , & V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_75 . V_113 , L_231 ,
& V_293 -> V_300 ) ;
F_25 ( & V_72 -> V_75 . V_113 ,
& V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_226 . V_288 ,
L_232 , & V_293 -> V_301 ) ;
F_25 ( & V_72 -> V_226 . V_288 ,
& V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_302 . V_303 ,
L_233 , & V_293 -> V_304 ) ;
F_25 ( & V_72 -> V_302 . V_303 ,
& V_72 -> V_74 ) ;
V_263 = F_171 ( V_72 , L_234 , 1 ) ;
if ( ! V_263 )
goto V_305;
V_72 -> V_226 . V_306 = V_263 ;
F_24 ( & V_263 -> V_261 ,
L_234 , & V_290 ) ;
F_25 ( & V_263 -> V_261 ,
& V_72 -> V_226 . V_288 ) ;
F_178 ( V_72 ) ;
F_10 ( & V_203 -> V_296 ) ;
return & V_72 -> V_74 ;
V_305:
F_123 ( V_72 ) ;
V_151:
F_10 ( & V_203 -> V_296 ) ;
return F_23 ( V_295 ) ;
}
static void F_179 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_27 * V_252 = F_3 ( V_3 ) ;
struct V_71 * V_72 =
F_2 ( V_252 , struct V_71 , V_74 ) ;
struct V_1 * V_203 ;
V_203 = F_1 ( & V_72 -> V_1 -> V_4 . V_34 ) ;
F_8 ( & V_203 -> V_296 ) ;
F_29 ( & V_72 -> V_302 . V_303 ) ;
F_29 ( & V_72 -> V_226 . V_288 ) ;
V_72 -> V_226 . V_306 = NULL ;
F_29 ( V_252 ) ;
F_30 ( V_3 ) ;
F_10 ( & V_203 -> V_296 ) ;
}
static inline struct V_1 * F_180 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_181 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_203 = F_180 ( V_3 ) ;
return sprintf ( V_5 , L_235 ,
V_203 -> V_307 , V_203 -> V_294 -> V_308 -> V_23 ,
V_7 ) ;
}
static T_1 F_182 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_203 = F_180 ( V_3 ) ;
int V_309 = 0 ;
if ( V_203 -> V_310 & V_311 )
V_309 = 1 ;
return sprintf ( V_5 , L_161 , V_309 ) ;
}
static T_1 F_183 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_1 * V_203 = F_180 ( V_3 ) ;
unsigned long V_312 ;
int V_29 ;
if ( V_203 -> V_294 -> V_308 -> V_313 == NULL )
return - V_17 ;
V_29 = F_127 ( V_5 , 0 , & V_312 ) ;
if ( V_29 < 0 ) {
F_11 ( L_236 , V_29 ) ;
return V_29 ;
}
if ( V_203 -> V_314 ) {
F_11 ( L_237 ) ;
return - V_17 ;
}
V_29 = V_203 -> V_294 -> V_308 -> V_313 ( V_203 , V_312 ) ;
if ( V_29 < 0 )
return - V_17 ;
if ( V_29 > 0 )
V_203 -> V_310 |= V_311 ;
else if ( V_29 == 0 )
V_203 -> V_310 &= ~ V_311 ;
return V_11 ;
}
static void F_184 ( struct V_2 * V_3 )
{
struct V_1 * V_203 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_185 ( V_203 ) ;
}
static struct V_27 * F_186 (
struct V_27 * V_28 ,
const char * V_23 )
{
char * V_315 , * V_316 , * V_317 ;
struct V_1 * V_203 ;
char V_116 [ V_318 ] ;
unsigned long V_319 = 0 ;
int V_29 ;
memset ( V_116 , 0 , V_318 ) ;
if ( strlen ( V_23 ) >= V_318 ) {
F_11 ( L_238
L_239 , ( int ) strlen ( V_23 ) ,
V_318 ) ;
return F_23 ( - V_320 ) ;
}
snprintf ( V_116 , V_318 , L_7 , V_23 ) ;
V_316 = strstr ( V_116 , L_240 ) ;
if ( ! V_316 ) {
F_11 ( L_241 ) ;
return F_23 ( - V_17 ) ;
}
V_315 = V_116 ;
V_317 = strstr ( V_316 + 1 , L_240 ) ;
if ( V_317 ) {
* V_317 = '\0' ;
V_317 ++ ;
V_316 = V_317 ;
} else {
* V_316 = '\0' ;
V_316 ++ ;
}
V_29 = F_127 ( V_316 , 0 , & V_319 ) ;
if ( V_29 < 0 ) {
F_11 ( L_189
L_242 , V_29 ) ;
return F_23 ( V_29 ) ;
}
F_187 () ;
V_203 = F_188 ( V_315 , V_319 , 0 ) ;
if ( F_13 ( V_203 ) )
return F_189 ( V_203 ) ;
F_24 ( & V_203 -> V_4 , V_23 ,
& V_321 ) ;
return & V_203 -> V_4 ;
}
static void F_190 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
F_30 ( V_3 ) ;
}
void F_191 ( struct V_292 * V_293 )
{
F_192 ( V_293 ) ;
F_193 ( V_293 ) ;
F_194 ( V_293 ) ;
F_195 ( V_293 ) ;
F_196 ( V_293 ) ;
F_197 ( V_293 ) ;
}
static int T_8 F_198 ( void )
{
struct V_322 * V_323 = & V_36 ;
struct V_209 * V_210 ;
int V_29 ;
F_21 ( L_243
L_244 V_6 L_3 ,
V_7 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
F_199 ( & V_323 -> V_324 ) ;
F_200 ( & V_323 -> V_325 ) ;
V_29 = F_201 () ;
if ( V_29 < 0 )
return V_29 ;
F_24 ( & V_326 , L_245 ,
& V_327 ) ;
F_25 ( & V_326 , & V_323 -> V_324 ) ;
F_24 ( & V_328 , L_232 , & V_329 ) ;
F_25 ( & V_328 , & V_326 ) ;
F_24 ( & V_330 , L_246 ,
& V_331 ) ;
F_25 ( & V_330 , & V_328 ) ;
V_210 = F_133 ( L_247 , 1 ) ;
if ( F_13 ( V_210 ) ) {
V_29 = - V_66 ;
goto V_332;
}
F_24 ( & V_210 -> V_215 , L_247 ,
& V_259 ) ;
F_25 ( & V_210 -> V_215 , & V_330 ) ;
V_333 = V_210 ;
V_29 = F_202 ( V_323 ) ;
if ( V_29 < 0 ) {
F_11 ( L_248 ,
V_29 , V_323 -> V_324 . V_34 . V_334 ) ;
goto V_332;
}
F_21 ( L_249
L_250 V_7 L_251
L_252 V_6 L_3 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
V_29 = F_203 () ;
if ( V_29 < 0 )
goto V_180;
V_29 = F_204 () ;
if ( V_29 < 0 )
goto V_180;
V_29 = F_205 () ;
if ( V_29 < 0 )
goto V_180;
return 0 ;
V_180:
F_206 ( V_323 ) ;
F_207 () ;
F_208 () ;
V_332:
if ( V_333 ) {
F_131 ( V_333 ) ;
V_333 = NULL ;
}
F_209 () ;
return V_29 ;
}
static void T_9 F_210 ( void )
{
F_29 ( & V_330 ) ;
F_29 ( & V_328 ) ;
F_29 ( & V_326 ) ;
F_206 ( & V_36 ) ;
F_131 ( V_333 ) ;
V_333 = NULL ;
F_21 ( L_253
L_254 ) ;
F_207 () ;
F_208 () ;
F_211 () ;
F_209 () ;
}
