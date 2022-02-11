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
static struct V_10 * F_6 (
const char * V_11 )
{
struct V_10 * V_12 ;
if ( ! V_11 )
return NULL ;
F_7 ( & V_13 ) ;
F_8 (tf, &g_tf_list, tf_list) {
if ( ! strcmp ( V_12 -> V_14 -> V_11 , V_11 ) ) {
F_9 ( & V_12 -> V_15 ) ;
F_10 ( & V_13 ) ;
return V_12 ;
}
}
F_10 ( & V_13 ) ;
return NULL ;
}
static struct V_16 * F_11 (
struct V_16 * V_17 ,
const char * V_11 )
{
struct V_10 * V_12 ;
int V_18 ;
F_12 ( L_4
L_5 , V_17 , V_11 ) ;
V_12 = F_6 ( V_11 ) ;
if ( ! V_12 ) {
F_12 ( L_6 ,
V_11 ) ;
if ( ! strncmp ( V_11 , L_7 , 5 ) ) {
V_18 = F_13 ( L_8 ) ;
if ( V_18 < 0 ) {
F_12 ( L_9
L_10 , V_18 ) ;
return F_14 ( - V_19 ) ;
}
} else if ( ! strncmp ( V_11 , L_11 , 8 ) ) {
V_18 = F_13 ( L_12 ) ;
if ( V_18 < 0 ) {
F_12 ( L_9
L_13 , V_18 ) ;
return F_14 ( - V_19 ) ;
}
}
V_12 = F_6 ( V_11 ) ;
}
if ( ! V_12 ) {
F_12 ( L_14 ,
V_11 ) ;
return F_14 ( - V_19 ) ;
}
F_12 ( L_15
L_5 , V_12 -> V_14 -> V_11 ) ;
F_12 ( L_16 ,
& V_12 -> V_20 ) ;
F_15 ( & V_12 -> V_21 , V_11 , & V_12 -> V_20 ) ;
F_15 ( & V_12 -> V_22 , L_17 ,
& V_12 -> V_23 ) ;
F_16 ( & V_12 -> V_22 , & V_12 -> V_21 ) ;
F_12 ( L_18
L_5 , V_12 -> V_21 . V_24 . V_25 ) ;
return & V_12 -> V_21 ;
}
static void F_17 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_10 * V_12 = F_2 (
F_3 ( V_3 ) , struct V_10 , V_21 ) ;
F_12 ( L_19
L_20 , F_18 ( V_3 ) ) ;
F_12 ( L_21
L_5 , V_12 -> V_14 -> V_11 ) ;
F_19 ( & V_12 -> V_15 ) ;
F_12 ( L_22
L_5 , F_18 ( V_3 ) ) ;
F_20 ( & V_12 -> V_21 ) ;
F_21 ( V_3 ) ;
}
int F_22 ( struct V_2 * V_3 )
{
return F_23 ( & V_26 , V_3 ) ;
}
void F_24 ( struct V_2 * V_3 )
{
return F_25 ( V_3 ) ;
}
static int F_26 ( const struct V_27 * V_28 )
{
if ( ! V_28 -> V_11 ) {
F_27 ( L_23 ) ;
return - V_19 ;
}
if ( strlen ( V_28 -> V_11 ) >= V_29 ) {
F_27 ( L_24
L_25 , V_28 -> V_11 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_30 ) {
F_27 ( L_26 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_31 ) {
F_27 ( L_27 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_32 ) {
F_27 ( L_28 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_33 ) {
F_27 ( L_29 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_34 ) {
F_27 ( L_30 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_35 ) {
F_27 ( L_31 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_36 ) {
F_27 ( L_32 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_37 ) {
F_27 ( L_33 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_38 ) {
F_27 ( L_34 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_39 ) {
F_27 ( L_35 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_40 ) {
F_27 ( L_36 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_41 ) {
F_27 ( L_37 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_42 ) {
F_27 ( L_38 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_43 ) {
F_27 ( L_39 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_44 ) {
F_27 ( L_40 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_45 ) {
F_27 ( L_41 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_46 ) {
F_27 ( L_42 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_47 ) {
F_27 ( L_43 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_48 ) {
F_27 ( L_44 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_49 ) {
F_27 ( L_45 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_50 ) {
F_27 ( L_46 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_51 ) {
F_27 ( L_47 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_52 ) {
F_27 ( L_48 ) ;
return - V_19 ;
}
if ( ! V_28 -> V_53 ) {
F_27 ( L_49 ) ;
return - V_19 ;
}
return 0 ;
}
int F_28 ( const struct V_27 * V_54 )
{
struct V_10 * V_12 ;
int V_18 ;
V_18 = F_26 ( V_54 ) ;
if ( V_18 )
return V_18 ;
V_12 = F_29 ( sizeof( struct V_10 ) , V_55 ) ;
if ( ! V_12 ) {
F_27 ( L_50 , V_56 ) ;
return - V_57 ;
}
F_30 ( & V_12 -> V_58 ) ;
F_31 ( & V_12 -> V_15 , 0 ) ;
V_12 -> V_14 = V_54 ;
F_32 ( V_12 ) ;
F_7 ( & V_13 ) ;
F_33 ( & V_12 -> V_58 , & V_59 ) ;
F_10 ( & V_13 ) ;
return 0 ;
}
void F_34 ( const struct V_27 * V_54 )
{
struct V_10 * V_60 ;
F_7 ( & V_13 ) ;
F_8 (t, &g_tf_list, tf_list) {
if ( ! strcmp ( V_60 -> V_14 -> V_11 , V_54 -> V_11 ) ) {
F_35 ( F_36 ( & V_60 -> V_15 ) ) ;
F_37 ( & V_60 -> V_58 ) ;
F_10 ( & V_13 ) ;
F_38 () ;
F_39 ( V_60 ) ;
return;
}
}
F_10 ( & V_13 ) ;
}
static inline struct V_61 * F_40 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_61 ,
V_62 ) ;
}
static void F_41 ( struct V_63 * V_64 )
{
const char * V_65 ;
V_65 = F_18 ( & V_64 -> V_66 . V_24 ) ;
if ( strlen ( V_65 ) >= 16 ) {
F_42 ( L_51
L_52 , V_64 ,
V_65 ) ;
}
snprintf ( & V_64 -> V_67 . V_68 [ 0 ] , 16 , L_53 , V_65 ) ;
}
static T_1 F_43 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
struct V_63 * V_64 = V_70 -> V_71 ;
bool V_72 ;
int V_18 ;
if ( V_64 -> V_73 ) {
F_27 ( L_54
L_55 ,
V_64 , V_64 -> V_73 ) ;
return - V_19 ;
}
V_18 = F_44 ( V_5 , & V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_72 ) {
F_41 ( V_64 ) ;
} else {
strncpy ( & V_64 -> V_67 . V_68 [ 0 ] ,
V_64 -> V_74 -> V_75 , 16 ) ;
}
V_70 -> V_76 = V_72 ;
return V_69 ;
}
static T_1 F_45 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
bool V_72 ;
int V_18 ;
V_18 = F_44 ( V_5 , & V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_72 && V_70 -> V_71 -> V_74 -> V_77 ) {
F_27 ( L_56 ) ;
return - V_19 ;
}
V_70 -> V_78 = V_72 ;
F_12 ( L_57 ,
V_70 -> V_71 , V_72 ) ;
return V_69 ;
}
static T_1 F_46 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
T_3 V_79 ;
int V_18 ;
V_18 = F_47 ( V_5 , 0 , & V_79 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_79 != 0 && V_79 != 1 && V_79 != 2 ) {
F_27 ( L_58 , V_79 ) ;
return - V_19 ;
}
if ( V_70 -> V_71 -> V_73 ) {
F_27 ( L_59
L_60 ,
V_70 -> V_71 , V_70 -> V_71 -> V_73 ) ;
return - V_19 ;
}
V_70 -> V_80 = V_79 ;
F_12 ( L_61 ,
V_70 -> V_71 , V_79 ) ;
return V_69 ;
}
static T_1 F_48 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
bool V_72 ;
int V_18 ;
V_18 = F_44 ( V_5 , & V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_70 -> V_71 -> V_73 ) {
F_27 ( L_62
L_63 ,
V_70 -> V_71 , V_70 -> V_71 -> V_73 ) ;
return - V_19 ;
}
V_70 -> V_81 = V_72 ;
F_12 ( L_64 ,
V_70 -> V_71 , V_72 ? L_65 : L_66 ) ;
return V_69 ;
}
static T_1 F_49 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
bool V_72 ;
int V_18 ;
V_18 = F_44 ( V_5 , & V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_72 && ! V_70 -> V_82 ) {
F_27 ( L_67 ) ;
return - V_83 ;
}
V_70 -> V_84 = V_72 ;
F_12 ( L_68 ,
V_70 -> V_71 , V_72 ) ;
return V_69 ;
}
static T_1 F_50 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
bool V_72 ;
int V_18 ;
V_18 = F_44 ( V_5 , & V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_72 && ! V_70 -> V_82 ) {
F_27 ( L_67 ) ;
return - V_83 ;
}
V_70 -> V_85 = V_72 ;
F_12 ( L_69 ,
V_70 -> V_71 , V_72 ) ;
return V_69 ;
}
static T_1 F_51 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
int V_86 = V_70 -> V_87 , V_18 ;
struct V_63 * V_64 = V_70 -> V_71 ;
T_3 V_72 ;
V_18 = F_47 ( V_5 , 0 , & V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_72 != 0 && V_72 != 1 && V_72 != 2 && V_72 != 3 ) {
F_27 ( L_70 , V_72 ) ;
return - V_19 ;
}
if ( V_72 == 2 ) {
F_27 ( L_71 ) ;
return - V_83 ;
}
if ( V_70 -> V_88 ) {
F_42 ( L_72
L_73 ) ;
return V_69 ;
}
if ( ! V_64 -> V_74 -> V_89 || ! V_64 -> V_74 -> V_90 ) {
if ( V_72 == 0 )
return V_69 ;
F_27 ( L_74 ,
V_64 -> V_74 -> V_11 ) ;
return - V_83 ;
}
if ( ! ( V_64 -> V_91 & V_92 ) ) {
F_27 ( L_75 ) ;
return - V_93 ;
}
if ( V_64 -> V_73 ) {
F_27 ( L_76
L_63 , V_64 , V_64 -> V_73 ) ;
return - V_19 ;
}
V_70 -> V_87 = V_72 ;
if ( V_72 && ! V_86 ) {
V_18 = V_64 -> V_74 -> V_89 ( V_64 ) ;
if ( V_18 ) {
V_70 -> V_87 = V_86 ;
return V_18 ;
}
} else if ( ! V_72 && V_86 ) {
V_64 -> V_74 -> V_90 ( V_64 ) ;
}
F_12 ( L_77 , V_64 , V_72 ) ;
return V_69 ;
}
static T_1 F_52 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
struct V_63 * V_64 = V_70 -> V_71 ;
bool V_72 ;
int V_18 ;
V_18 = F_44 ( V_5 , & V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( ! V_72 )
return V_69 ;
if ( ! V_64 -> V_74 -> V_94 ) {
F_27 ( L_78 ,
V_64 -> V_74 -> V_11 ) ;
return - V_83 ;
}
if ( ! ( V_64 -> V_91 & V_92 ) ) {
F_27 ( L_79 ) ;
return - V_93 ;
}
if ( V_64 -> V_73 ) {
F_27 ( L_80
L_63 , V_64 , V_64 -> V_73 ) ;
return - V_19 ;
}
V_18 = V_64 -> V_74 -> V_94 ( V_64 ) ;
if ( V_18 )
return V_18 ;
F_12 ( L_81 , V_64 ) ;
return V_69 ;
}
static T_1 F_53 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
bool V_72 ;
int V_18 ;
V_18 = F_44 ( V_5 , & V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_70 -> V_71 -> V_73 ) {
F_27 ( L_82
L_63 ,
V_70 -> V_71 , V_70 -> V_71 -> V_73 ) ;
return - V_19 ;
}
V_70 -> V_95 = V_72 ;
F_12 ( L_83 , V_70 -> V_71 , V_72 ) ;
return V_69 ;
}
static T_1 F_54 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
bool V_72 ;
int V_18 ;
V_18 = F_44 ( V_5 , & V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_72 != 0 ) {
F_55 ( V_96 L_84
L_85 , V_70 -> V_71 ) ;
return - V_83 ;
}
V_70 -> V_97 = V_72 ;
F_12 ( L_86 ,
V_70 -> V_71 , V_72 ) ;
return V_69 ;
}
static T_1 F_56 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
bool V_72 ;
int V_18 ;
V_18 = F_44 ( V_5 , & V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_70 -> V_71 -> V_73 ) {
F_27 ( L_59
L_87 ,
V_70 -> V_71 , V_70 -> V_71 -> V_73 ) ;
return - V_19 ;
}
if ( V_72 && ! V_70 -> V_82 ) {
F_27 ( L_88
L_89 ,
V_70 -> V_71 ) ;
return - V_83 ;
}
V_70 -> V_98 = V_72 ;
F_12 ( L_90 ,
V_70 -> V_71 , V_72 ) ;
return V_69 ;
}
static T_1 F_57 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
struct V_63 * V_64 = V_70 -> V_71 ;
T_3 V_79 ;
int V_18 ;
V_18 = F_47 ( V_5 , 0 , & V_79 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_64 -> V_73 ) {
F_27 ( L_91
L_63 ,
V_64 , V_64 -> V_73 ) ;
return - V_19 ;
}
if ( ! V_79 ) {
F_27 ( L_92 , V_64 ) ;
return - V_19 ;
}
if ( V_79 > V_64 -> V_99 . V_100 ) {
if ( V_79 > V_64 -> V_99 . V_101 ) {
F_27 ( L_93
L_94
L_95 , V_64 , V_79 ,
V_64 -> V_99 . V_101 ) ;
return - V_19 ;
}
}
V_70 -> V_100 = V_64 -> V_100 = V_79 ;
F_12 ( L_96 , V_64 , V_79 ) ;
return V_69 ;
}
static T_1 F_58 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
T_3 V_79 ;
int V_18 ;
V_18 = F_47 ( V_5 , 0 , & V_79 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_70 -> V_71 -> V_73 ) {
F_27 ( L_59
L_97 ,
V_70 -> V_71 , V_70 -> V_71 -> V_73 ) ;
return - V_19 ;
}
if ( V_79 > V_70 -> V_102 ) {
F_27 ( L_98
L_99 ,
V_70 -> V_71 , V_79 , V_70 -> V_102 ) ;
return - V_19 ;
}
V_70 -> V_103 = V_79 ;
F_12 ( L_100 ,
V_70 -> V_71 , V_79 ) ;
return V_69 ;
}
static T_1 F_59 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_61 * V_70 = F_40 ( V_3 ) ;
T_3 V_79 ;
int V_18 ;
V_18 = F_47 ( V_5 , 0 , & V_79 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_70 -> V_71 -> V_73 ) {
F_27 ( L_101
L_55 ,
V_70 -> V_71 , V_70 -> V_71 -> V_73 ) ;
return - V_19 ;
}
if ( V_79 != 512 && V_79 != 1024 && V_79 != 2048 && V_79 != 4096 ) {
F_27 ( L_102
L_103 ,
V_70 -> V_71 , V_79 ) ;
return - V_19 ;
}
V_70 -> V_104 = V_79 ;
if ( V_70 -> V_105 )
V_70 -> V_102 = V_70 -> V_105 / V_79 ;
F_12 ( L_104 ,
V_70 -> V_71 , V_79 ) ;
return V_69 ;
}
static struct V_67 * F_60 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_67 , V_106 ) ;
}
static T_1 F_61 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_105 ,
& F_60 ( V_3 ) -> V_107 [ 0 ] ) ;
}
static T_1 F_62 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_67 * V_67 = F_60 ( V_3 ) ;
struct V_63 * V_64 = V_67 -> V_108 ;
unsigned char V_109 [ V_110 ] ;
if ( V_64 -> V_91 & V_111 ) {
F_27 ( L_106
L_107 ) ;
return - V_112 ;
}
if ( strlen ( V_5 ) >= V_110 ) {
F_27 ( L_108
L_109 , V_110 ) ;
return - V_113 ;
}
if ( V_64 -> V_73 ) {
F_27 ( L_110
L_111 ,
V_64 -> V_73 ) ;
return - V_19 ;
}
memset ( V_109 , 0 , V_110 ) ;
snprintf ( V_109 , V_110 , L_53 , V_5 ) ;
snprintf ( V_64 -> V_67 . V_107 , V_110 ,
L_53 , F_63 ( V_109 ) ) ;
V_64 -> V_91 |= V_114 ;
F_12 ( L_112
L_5 , V_64 -> V_67 . V_107 ) ;
return V_69 ;
}
static T_1 F_64 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_67 * V_67 = F_60 ( V_3 ) ;
struct V_115 * V_116 ;
unsigned char V_109 [ V_117 ] ;
T_1 V_118 = 0 ;
memset ( V_109 , 0 , V_117 ) ;
F_65 ( & V_67 -> V_119 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_116 -> V_120 )
continue;
F_66 ( V_116 , V_109 , V_117 ) ;
if ( V_118 + strlen ( V_109 ) >= V_121 )
break;
V_118 += sprintf ( V_5 + V_118 , L_53 , V_109 ) ;
}
F_67 ( & V_67 -> V_119 ) ;
return V_118 ;
}
static struct V_63 * F_68 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_63 ,
V_122 ) ;
}
static T_1 F_69 ( struct V_63 * V_64 ,
char * V_5 )
{
struct V_123 * V_124 ;
struct V_125 * V_126 ;
char V_127 [ V_128 ] ;
memset ( V_127 , 0 , V_128 ) ;
V_126 = V_64 -> V_129 ;
if ( ! V_126 )
return sprintf ( V_5 , L_113 ) ;
V_124 = V_126 -> V_130 ;
F_70 ( V_126 , V_127 , V_128 ) ;
return sprintf ( V_5 , L_114 ,
V_124 -> V_131 -> V_132 -> V_30 () ,
V_124 -> V_133 , V_127 ) ;
}
static T_1 F_71 ( struct V_63 * V_64 ,
char * V_5 )
{
struct V_123 * V_124 ;
T_1 V_118 ;
V_124 = V_64 -> V_134 ;
if ( V_124 ) {
V_118 = sprintf ( V_5 ,
L_115 ,
V_124 -> V_131 -> V_132 -> V_30 () ,
V_124 -> V_133 ) ;
} else {
V_118 = sprintf ( V_5 , L_116 ) ;
}
return V_118 ;
}
static T_1 F_72 ( struct V_2 * V_3 , char * V_5 )
{
struct V_63 * V_64 = F_68 ( V_3 ) ;
int V_18 ;
if ( V_64 -> V_74 -> V_135 & V_136 )
return sprintf ( V_5 , L_117 ) ;
F_65 ( & V_64 -> V_137 ) ;
if ( V_64 -> V_138 & V_139 )
V_18 = F_71 ( V_64 , V_5 ) ;
else
V_18 = F_69 ( V_64 , V_5 ) ;
F_67 ( & V_64 -> V_137 ) ;
return V_18 ;
}
static T_1 F_73 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_63 * V_64 = F_68 ( V_3 ) ;
T_1 V_118 = 0 ;
F_65 ( & V_64 -> V_137 ) ;
if ( ! V_64 -> V_129 ) {
V_118 = sprintf ( V_5 , L_113 ) ;
} else if ( V_64 -> V_129 -> V_140 ) {
V_118 = sprintf ( V_5 , L_118
L_119 ) ;
} else {
V_118 = sprintf ( V_5 , L_120
L_121 ) ;
}
F_67 ( & V_64 -> V_137 ) ;
return V_118 ;
}
static T_1 F_74 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_122 , F_68 ( V_3 ) -> V_141 . V_142 ) ;
}
static T_1 F_75 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_63 * V_64 = F_68 ( V_3 ) ;
struct V_123 * V_124 ;
struct V_143 * V_131 ;
struct V_125 * V_126 ;
const struct V_27 * V_28 ;
T_1 V_118 = 0 ;
F_65 ( & V_64 -> V_137 ) ;
V_126 = V_64 -> V_129 ;
if ( ! V_126 ) {
V_118 = sprintf ( V_5 , L_113 ) ;
goto V_144;
}
V_124 = V_126 -> V_130 ;
V_131 = V_124 -> V_131 ;
V_28 = V_131 -> V_132 ;
V_118 += sprintf ( V_5 + V_118 , L_123
L_124 , V_28 -> V_30 () ,
V_28 -> V_31 ( V_131 ) ) ;
V_118 += sprintf ( V_5 + V_118 , L_125
L_126
L_127 , V_126 -> V_145 ,
V_28 -> V_30 () , V_28 -> V_32 ( V_131 ) ,
V_28 -> V_30 () , V_126 -> V_146 ) ;
V_144:
F_67 ( & V_64 -> V_137 ) ;
return V_118 ;
}
static T_1 F_76 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_63 * V_64 = F_68 ( V_3 ) ;
const struct V_27 * V_28 ;
struct V_125 * V_126 ;
unsigned char V_109 [ 384 ] ;
char V_127 [ V_128 ] ;
T_1 V_118 = 0 ;
int V_147 = 0 ;
V_118 += sprintf ( V_5 + V_118 , L_128 ) ;
F_65 ( & V_64 -> V_141 . V_148 ) ;
F_8 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_109 , 0 , 384 ) ;
memset ( V_127 , 0 , V_128 ) ;
V_28 = V_126 -> V_130 -> V_131 -> V_132 ;
F_70 ( V_126 , V_127 ,
V_128 ) ;
sprintf ( V_109 , L_129 ,
V_28 -> V_30 () ,
V_126 -> V_130 -> V_133 , V_127 , V_126 -> V_149 ,
V_126 -> V_150 ) ;
if ( V_118 + strlen ( V_109 ) >= V_121 )
break;
V_118 += sprintf ( V_5 + V_118 , L_53 , V_109 ) ;
V_147 ++ ;
}
F_67 ( & V_64 -> V_141 . V_148 ) ;
if ( ! V_147 )
V_118 += sprintf ( V_5 + V_118 , L_130 ) ;
return V_118 ;
}
static T_1 F_77 ( struct V_2 * V_3 , char * V_5 )
{
struct V_63 * V_64 = F_68 ( V_3 ) ;
struct V_125 * V_126 ;
T_1 V_118 = 0 ;
F_65 ( & V_64 -> V_137 ) ;
V_126 = V_64 -> V_129 ;
if ( V_126 ) {
V_118 = sprintf ( V_5 , L_131 ,
F_78 ( V_126 -> V_151 ) ) ;
} else {
V_118 = sprintf ( V_5 , L_113 ) ;
}
F_67 ( & V_64 -> V_137 ) ;
return V_118 ;
}
static T_1 F_79 ( struct V_2 * V_3 , char * V_5 )
{
struct V_63 * V_64 = F_68 ( V_3 ) ;
if ( V_64 -> V_74 -> V_135 & V_136 )
return sprintf ( V_5 , L_132 ) ;
else if ( V_64 -> V_138 & V_139 )
return sprintf ( V_5 , L_133 ) ;
else
return sprintf ( V_5 , L_134 ) ;
}
static T_1 F_80 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_63 * V_64 = F_68 ( V_3 ) ;
if ( V_64 -> V_74 -> V_135 & V_136 )
return 0 ;
return sprintf ( V_5 , L_135 ,
( V_64 -> V_141 . V_152 ) ? L_136 : L_66 ) ;
}
static T_1 F_81 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_63 * V_64 = F_68 ( V_3 ) ;
if ( V_64 -> V_74 -> V_135 & V_136 )
return 0 ;
return sprintf ( V_5 , L_137 ) ;
}
static T_1 F_82 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_63 * V_64 = F_68 ( V_3 ) ;
unsigned char * V_153 = NULL , * V_154 = NULL , * V_155 = NULL ;
unsigned char * V_156 = NULL , * V_157 = NULL ;
char * V_158 , * V_159 , * V_160 ;
T_4 args [ V_161 ] ;
unsigned long long V_162 ;
T_5 V_163 = 0 ;
T_5 V_164 = 0 , V_165 = 0 ;
int V_18 = - 1 , V_166 = 0 , V_167 = 0 , V_168 , V_169 ;
T_6 V_170 = 0 ;
T_7 type = 0 ;
if ( V_64 -> V_74 -> V_135 & V_136 )
return V_69 ;
if ( V_64 -> V_138 & V_139 )
return V_69 ;
if ( V_64 -> V_73 ) {
F_12 ( L_138
L_139 ) ;
return - V_19 ;
}
V_160 = F_83 ( V_5 , V_55 ) ;
if ( ! V_160 )
return - V_57 ;
V_158 = V_160 ;
while ( ( V_159 = F_84 ( & V_160 , L_140 ) ) != NULL ) {
if ( ! * V_159 )
continue;
V_169 = F_85 ( V_159 , V_171 , args ) ;
switch ( V_169 ) {
case V_172 :
V_153 = F_86 ( args ) ;
if ( ! V_153 ) {
V_18 = - V_57 ;
goto V_173;
}
break;
case V_174 :
V_154 = F_86 ( args ) ;
if ( ! V_154 ) {
V_18 = - V_57 ;
goto V_173;
}
if ( strlen ( V_154 ) >= V_175 ) {
F_27 ( L_141
L_142 ,
V_175 ) ;
V_18 = - V_19 ;
break;
}
break;
case V_176 :
V_155 = F_86 ( args ) ;
if ( ! V_155 ) {
V_18 = - V_57 ;
goto V_173;
}
if ( strlen ( V_155 ) >= V_177 ) {
F_27 ( L_143
L_144 ,
V_177 ) ;
V_18 = - V_19 ;
break;
}
break;
case V_178 :
V_18 = F_87 ( args -> V_179 , 0 , & V_162 ) ;
if ( V_18 < 0 ) {
F_27 ( L_145 ) ;
goto V_173;
}
V_163 = ( T_5 ) V_162 ;
break;
case V_180 :
V_18 = F_88 ( args , & V_168 ) ;
if ( V_18 )
goto V_173;
V_166 = V_168 ;
break;
case V_181 :
V_18 = F_88 ( args , & V_168 ) ;
if ( V_18 )
goto V_173;
type = ( T_7 ) V_168 ;
break;
case V_182 :
V_18 = F_88 ( args , & V_168 ) ;
if ( V_18 )
goto V_173;
break;
case V_183 :
V_18 = F_88 ( args , & V_168 ) ;
if ( V_18 )
goto V_173;
V_167 = ( int ) V_168 ;
break;
case V_184 :
V_18 = F_88 ( args , & V_168 ) ;
if ( V_18 )
goto V_173;
V_164 = ( T_5 ) V_168 ;
break;
case V_185 :
V_156 = F_86 ( args ) ;
if ( ! V_156 ) {
V_18 = - V_57 ;
goto V_173;
}
break;
case V_186 :
V_157 = F_86 ( args ) ;
if ( ! V_157 ) {
V_18 = - V_57 ;
goto V_173;
}
if ( strlen ( V_157 ) >= V_187 ) {
F_27 ( L_146
L_147 ,
V_187 ) ;
V_18 = - V_19 ;
break;
}
break;
case V_188 :
V_18 = F_88 ( args , & V_168 ) ;
if ( V_18 )
goto V_173;
V_170 = ( T_6 ) V_168 ;
break;
case V_189 :
V_18 = F_88 ( args , & V_168 ) ;
if ( V_18 )
goto V_173;
break;
case V_190 :
V_18 = F_88 ( args , & V_168 ) ;
if ( V_18 )
goto V_173;
V_165 = ( T_5 ) V_168 ;
break;
default:
break;
}
}
if ( ! V_154 || ! V_157 || ! V_163 ) {
F_27 ( L_148 ) ;
V_18 = - V_19 ;
goto V_173;
}
if ( V_166 && ! ( type ) ) {
F_27 ( L_149
L_150 , type ) ;
V_18 = - V_19 ;
goto V_173;
}
V_18 = F_89 ( & V_64 -> V_141 , V_163 ,
V_154 , V_155 , V_164 , V_157 , V_170 , V_165 ,
V_166 , V_167 , type ) ;
V_173:
F_39 ( V_153 ) ;
F_39 ( V_154 ) ;
F_39 ( V_155 ) ;
F_39 ( V_156 ) ;
F_39 ( V_157 ) ;
F_39 ( V_158 ) ;
return ( V_18 == 0 ) ? V_69 : V_18 ;
}
static inline struct V_63 * F_90 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_63 , V_66 ) ;
}
static T_1 F_91 ( struct V_2 * V_3 , char * V_5 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
int V_191 = 0 ;
T_1 V_192 = 0 ;
F_92 ( V_64 , V_5 , & V_191 ) ;
V_192 += V_191 ;
V_192 += V_64 -> V_74 -> V_193 ( V_64 ,
V_5 + V_192 ) ;
return V_192 ;
}
static T_1 F_93 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
return V_64 -> V_74 -> V_194 ( V_64 , V_5 , V_69 ) ;
}
static T_1 F_94 ( struct V_2 * V_3 , char * V_5 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
if ( ! ( V_64 -> V_91 & V_195 ) )
return 0 ;
return snprintf ( V_5 , V_121 , L_151 , V_64 -> V_196 ) ;
}
static T_1 F_95 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
struct V_1 * V_197 = V_64 -> V_1 ;
T_1 V_192 ;
if ( V_69 > ( V_198 - 1 ) ) {
F_27 ( L_152
L_153 , ( int ) V_69 ,
V_198 - 1 ) ;
return - V_19 ;
}
V_192 = snprintf ( & V_64 -> V_196 [ 0 ] , V_198 , L_53 , V_5 ) ;
if ( ! V_192 )
return - V_19 ;
if ( V_64 -> V_196 [ V_192 - 1 ] == '\n' )
V_64 -> V_196 [ V_192 - 1 ] = '\0' ;
V_64 -> V_91 |= V_195 ;
F_12 ( L_154 ,
F_18 ( & V_197 -> V_4 . V_24 ) ,
F_18 ( & V_64 -> V_66 . V_24 ) ,
V_64 -> V_196 ) ;
return V_192 ;
}
static T_1 F_96 ( struct V_2 * V_3 , char * V_5 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
if ( ! ( V_64 -> V_91 & V_199 ) )
return 0 ;
return snprintf ( V_5 , V_121 , L_151 , V_64 -> V_200 ) ;
}
static T_1 F_97 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
struct V_1 * V_197 = V_64 -> V_1 ;
T_1 V_192 ;
if ( V_69 > ( V_201 - 1 ) ) {
F_27 ( L_155
L_156 , ( int ) V_69 ,
V_201 - 1 ) ;
return - V_19 ;
}
V_192 = snprintf ( & V_64 -> V_200 [ 0 ] , V_201 ,
L_53 , V_5 ) ;
if ( ! V_192 )
return - V_19 ;
if ( V_64 -> V_200 [ V_192 - 1 ] == '\n' )
V_64 -> V_200 [ V_192 - 1 ] = '\0' ;
V_64 -> V_91 |= V_199 ;
F_12 ( L_157 ,
F_18 ( & V_197 -> V_4 . V_24 ) ,
F_18 ( & V_64 -> V_66 . V_24 ) ,
V_64 -> V_200 ) ;
return V_192 ;
}
static T_1 F_98 ( struct V_2 * V_3 , char * V_5 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
return snprintf ( V_5 , V_121 , L_158 , ! ! ( V_64 -> V_91 & V_92 ) ) ;
}
static T_1 F_99 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
char * V_159 ;
int V_18 ;
V_159 = strstr ( V_5 , L_159 ) ;
if ( ! V_159 ) {
F_27 ( L_160
L_161 ) ;
return - V_19 ;
}
V_18 = F_100 ( V_64 ) ;
if ( V_18 )
return V_18 ;
return V_69 ;
}
static T_1 F_101 ( struct V_2 * V_3 , char * V_5 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
struct V_2 * V_202 ;
struct V_203 * V_204 ;
struct V_205 * V_206 ;
T_1 V_118 = 0 ;
V_206 = V_64 -> V_207 ;
if ( ! V_206 )
return 0 ;
F_65 ( & V_206 -> V_208 ) ;
V_204 = V_206 -> V_204 ;
if ( V_204 ) {
V_202 = & V_204 -> V_209 . V_24 ;
V_118 += sprintf ( V_5 , L_162 ,
F_18 ( V_202 ) , V_204 -> V_210 ) ;
}
F_67 ( & V_206 -> V_208 ) ;
return V_118 ;
}
static T_1 F_102 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
struct V_1 * V_197 = V_64 -> V_1 ;
struct V_203 * V_204 = NULL , * V_211 = NULL ;
struct V_205 * V_206 ;
unsigned char V_109 [ V_212 ] ;
int V_213 = 0 ;
V_206 = V_64 -> V_207 ;
if ( ! V_206 )
return V_69 ;
if ( V_69 > V_212 ) {
F_27 ( L_163 ) ;
return - V_19 ;
}
memset ( V_109 , 0 , V_212 ) ;
memcpy ( V_109 , V_5 , V_69 ) ;
if ( strcmp ( F_63 ( V_109 ) , L_164 ) ) {
V_211 = F_103 ( F_63 ( V_109 ) ) ;
if ( ! V_211 )
return - V_93 ;
}
F_65 ( & V_206 -> V_208 ) ;
V_204 = V_206 -> V_204 ;
if ( V_204 ) {
if ( ! V_211 ) {
F_12 ( L_165
L_166
L_167 ,
F_18 ( & V_197 -> V_4 . V_24 ) ,
F_18 ( & V_64 -> V_66 . V_24 ) ,
F_18 ( & V_204 -> V_209 . V_24 ) ,
V_204 -> V_210 ) ;
F_104 ( V_206 , V_204 ) ;
F_67 ( & V_206 -> V_208 ) ;
return V_69 ;
}
F_104 ( V_206 , V_204 ) ;
V_213 = 1 ;
}
F_105 ( V_206 , V_211 ) ;
F_67 ( & V_206 -> V_208 ) ;
F_12 ( L_168
L_169 ,
( V_213 ) ? L_170 : L_171 ,
F_18 ( & V_197 -> V_4 . V_24 ) ,
F_18 ( & V_64 -> V_66 . V_24 ) ,
F_18 ( & V_211 -> V_209 . V_24 ) ,
V_211 -> V_210 ) ;
F_106 ( V_211 ) ;
return V_69 ;
}
static T_1 F_107 ( struct V_2 * V_3 , char * V_5 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
struct V_214 * V_215 ;
struct V_216 * V_217 ;
char * V_218 = V_5 ;
int V_191 = 0 ;
char V_219 ;
F_65 ( & V_64 -> V_220 . V_221 ) ;
if ( ! F_108 ( & V_64 -> V_220 . V_222 ) )
V_191 += sprintf ( V_218 + V_191 , L_172 ,
V_64 -> V_220 . V_223 ,
V_64 -> V_220 . V_224 ) ;
F_8 (map, &dev->t10_alua.lba_map_list, lba_map_list) {
V_191 += sprintf ( V_218 + V_191 , L_173 ,
V_215 -> V_225 , V_215 -> V_226 ) ;
F_8 (mem, &map->lba_map_mem_list,
lba_map_mem_list) {
switch ( V_217 -> V_227 ) {
case V_228 :
V_219 = 'O' ;
break;
case V_229 :
V_219 = 'A' ;
break;
case V_230 :
V_219 = 'S' ;
break;
case V_231 :
V_219 = 'U' ;
break;
default:
V_219 = '.' ;
break;
}
V_191 += sprintf ( V_218 + V_191 , L_174 ,
V_217 -> V_232 , V_219 ) ;
}
V_191 += sprintf ( V_218 + V_191 , L_3 ) ;
}
F_67 ( & V_64 -> V_220 . V_221 ) ;
return V_191 ;
}
static T_1 F_109 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_63 * V_64 = F_90 ( V_3 ) ;
struct V_214 * V_233 = NULL ;
struct V_234 V_235 ;
char * V_236 , * V_158 , * V_159 ;
char V_219 ;
int V_237 = - 1 , V_238 ;
int V_18 = 0 , V_239 = 0 , V_240 , V_241 ;
unsigned long V_242 = - 1 , V_243 = - 1 ;
unsigned long V_244 = - 1 , V_245 = - 1 ;
V_158 = V_236 = F_83 ( V_5 , V_55 ) ;
if ( ! V_236 )
return - V_57 ;
F_30 ( & V_235 ) ;
while ( ( V_159 = F_84 ( & V_236 , L_3 ) ) != NULL ) {
if ( ! * V_159 )
continue;
if ( V_239 == 0 ) {
if ( sscanf ( V_159 , L_175 ,
& V_244 , & V_245 ) != 2 ) {
F_27 ( L_176 , V_239 ) ;
V_18 = - V_19 ;
break;
}
V_239 ++ ;
continue;
}
if ( sscanf ( V_159 , L_177 , & V_242 , & V_243 ) != 2 ) {
F_27 ( L_176 , V_239 ) ;
V_18 = - V_19 ;
break;
}
V_159 = strchr ( V_159 , ' ' ) ;
if ( ! V_159 ) {
F_27 ( L_178 , V_239 ) ;
V_18 = - V_19 ;
break;
}
V_159 ++ ;
V_159 = strchr ( V_159 , ' ' ) ;
if ( ! V_159 ) {
F_27 ( L_179 ,
V_239 ) ;
V_18 = - V_19 ;
break;
}
V_159 ++ ;
V_233 = F_110 ( & V_235 ,
V_242 , V_243 ) ;
if ( F_111 ( V_233 ) ) {
V_18 = F_112 ( V_233 ) ;
break;
}
V_238 = 0 ;
while ( sscanf ( V_159 , L_180 , & V_240 , & V_219 ) == 2 ) {
switch ( V_219 ) {
case 'O' :
V_241 = V_228 ;
break;
case 'A' :
V_241 = V_229 ;
break;
case 'S' :
V_241 = V_230 ;
break;
case 'U' :
V_241 = V_231 ;
break;
default:
F_27 ( L_181 , V_219 ) ;
V_18 = - V_19 ;
goto V_173;
}
V_18 = F_113 ( V_233 ,
V_240 , V_241 ) ;
if ( V_18 ) {
F_27 ( L_182
L_183 ,
V_240 , V_219 , V_239 ) ;
break;
}
V_238 ++ ;
V_159 = strchr ( V_159 , ' ' ) ;
if ( V_159 )
V_159 ++ ;
else
break;
}
if ( V_237 == - 1 )
V_237 = V_238 ;
else if ( V_238 != V_237 ) {
F_27 ( L_184
L_183 , V_238 , V_237 , V_239 ) ;
V_18 = - V_19 ;
break;
}
V_239 ++ ;
}
V_173:
if ( V_18 ) {
F_114 ( & V_235 ) ;
V_69 = V_18 ;
} else
F_115 ( V_64 , & V_235 ,
V_244 , V_245 ) ;
F_39 ( V_158 ) ;
return V_69 ;
}
static void F_116 ( struct V_2 * V_3 )
{
struct V_16 * V_246 = F_3 ( V_3 ) ;
struct V_63 * V_64 =
F_2 ( V_246 , struct V_63 , V_66 ) ;
F_117 ( V_64 ) ;
}
static inline struct V_203 * F_118 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_203 ,
V_209 ) ;
}
static T_1 F_119 ( struct V_2 * V_3 , char * V_5 )
{
struct V_203 * V_204 = F_118 ( V_3 ) ;
if ( ! V_204 -> V_247 )
return 0 ;
return sprintf ( V_5 , L_185 , V_204 -> V_210 ) ;
}
static T_1 F_120 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_203 * V_204 = F_118 ( V_3 ) ;
struct V_16 * V_248 = & V_204 -> V_209 ;
unsigned long V_210 ;
int V_18 ;
V_18 = F_121 ( V_5 , 0 , & V_210 ) ;
if ( V_18 < 0 ) {
F_27 ( L_186
L_187 , V_18 ) ;
return V_18 ;
}
if ( V_210 > 0x0000ffff ) {
F_27 ( L_188
L_189 , V_210 ) ;
return - V_19 ;
}
V_18 = F_122 ( V_204 , ( T_6 ) V_210 ) ;
if ( V_18 < 0 )
return - V_19 ;
F_12 ( L_190
L_191 ,
F_18 ( & V_248 -> V_24 ) ,
V_204 -> V_210 ) ;
return V_69 ;
}
static T_1 F_123 ( struct V_2 * V_3 , char * V_5 )
{
struct V_203 * V_204 = F_118 ( V_3 ) ;
struct V_63 * V_64 ;
struct V_1 * V_197 ;
struct V_205 * V_206 ;
T_1 V_118 = 0 , V_249 ;
unsigned char V_109 [ V_212 ] ;
memset ( V_109 , 0 , V_212 ) ;
F_65 ( & V_204 -> V_250 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_64 = V_206 -> V_251 ;
V_197 = V_64 -> V_1 ;
V_249 = snprintf ( V_109 , V_212 , L_192 ,
F_18 ( & V_197 -> V_4 . V_24 ) ,
F_18 ( & V_64 -> V_66 . V_24 ) ) ;
V_249 ++ ;
if ( ( V_249 + V_118 ) > V_121 ) {
F_42 ( L_193
L_194 ) ;
break;
}
memcpy ( V_5 + V_118 , V_109 , V_249 ) ;
V_118 += V_249 ;
}
F_67 ( & V_204 -> V_250 ) ;
return V_118 ;
}
static void F_124 ( struct V_2 * V_3 )
{
struct V_203 * V_204 = F_2 ( F_3 ( V_3 ) ,
struct V_203 , V_209 ) ;
F_125 ( V_204 ) ;
}
static struct V_16 * F_126 (
struct V_16 * V_17 ,
const char * V_11 )
{
struct V_203 * V_204 ;
struct V_16 * V_248 = NULL ;
struct V_2 * V_252 = NULL ;
V_204 = F_127 ( V_11 , 0 ) ;
if ( F_111 ( V_204 ) )
return NULL ;
V_248 = & V_204 -> V_209 ;
V_252 = & V_248 -> V_24 ;
F_15 ( V_248 , V_11 ,
& V_253 ) ;
F_12 ( L_195
L_196 ,
F_18 ( V_252 ) ) ;
return V_248 ;
}
static void F_128 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_203 * V_204 = F_2 ( F_3 ( V_3 ) ,
struct V_203 , V_209 ) ;
F_12 ( L_197
L_198 ,
F_18 ( V_3 ) , V_204 -> V_210 ) ;
F_21 ( V_3 ) ;
}
static inline struct V_254 * F_129 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_254 ,
V_255 ) ;
}
static T_1 F_130 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_158 ,
F_36 ( & F_129 ( V_3 ) -> V_256 ) ) ;
}
static T_1 F_131 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_254 * V_257 = F_129 ( V_3 ) ;
struct V_63 * V_64 = V_257 -> V_258 ;
unsigned long V_259 ;
int V_260 , V_18 ;
if ( ! V_257 -> V_261 ) {
F_27 ( L_199
L_200 , V_257 -> V_261 ) ;
return - V_19 ;
}
if ( ! ( V_64 -> V_91 & V_92 ) ) {
F_27 ( L_201
L_202 ) ;
return - V_93 ;
}
V_18 = F_121 ( V_5 , 0 , & V_259 ) ;
if ( V_18 < 0 ) {
F_27 ( L_203
L_5 , V_5 ) ;
return V_18 ;
}
V_260 = ( int ) V_259 ;
if ( ! ( V_257 -> V_262 & V_263 ) ) {
F_27 ( L_204
L_205 ) ;
return - V_19 ;
}
if ( V_257 -> V_262 & V_264 &&
V_260 == V_265 ) {
F_27 ( L_206
L_207 ) ;
return - V_19 ;
}
V_18 = F_132 ( V_257 , V_64 ,
NULL , NULL , V_260 , 0 ) ;
return ( ! V_18 ) ? V_69 : - V_19 ;
}
static T_1 F_133 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_254 * V_257 = F_129 ( V_3 ) ;
return sprintf ( V_5 , L_151 ,
F_134 ( V_257 -> V_266 ) ) ;
}
static T_1 F_135 (
struct V_2 * V_3 , const char * V_5 , T_2 V_69 )
{
struct V_254 * V_257 = F_129 ( V_3 ) ;
unsigned long V_259 ;
int V_267 , V_18 ;
if ( ! V_257 -> V_261 ) {
F_27 ( L_208
L_209 ,
V_257 -> V_261 ) ;
return - V_19 ;
}
V_18 = F_121 ( V_5 , 0 , & V_259 ) ;
if ( V_18 < 0 ) {
F_27 ( L_210
L_211 , V_5 ) ;
return V_18 ;
}
V_267 = ( int ) V_259 ;
if ( ( V_267 != V_268 ) &&
( V_267 != V_269 ) &&
( V_267 != V_270 ) ) {
F_27 ( L_212 ,
V_267 ) ;
return - V_19 ;
}
V_257 -> V_266 = V_267 ;
return V_69 ;
}
static T_1 F_136 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_137 ( F_129 ( V_3 ) , V_5 ) ;
}
static T_1 F_138 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
return F_139 ( F_129 ( V_3 ) , V_5 , V_69 ) ;
}
static T_1 F_140 (
struct V_2 * V_3 , char * V_5 )
{
return sprintf ( V_5 , L_158 ,
F_129 ( V_3 ) -> V_271 ) ;
}
static T_1 F_141 (
struct V_2 * V_3 , const char * V_5 , T_2 V_69 )
{
struct V_254 * V_257 = F_129 ( V_3 ) ;
unsigned long V_259 ;
int V_18 ;
V_18 = F_121 ( V_5 , 0 , & V_259 ) ;
if ( V_18 < 0 ) {
F_27 ( L_213 ) ;
return V_18 ;
}
if ( ( V_259 != 0 ) && ( V_259 != 1 ) ) {
F_27 ( L_214
L_215 , V_259 ) ;
return - V_19 ;
}
V_257 -> V_271 = ( int ) V_259 ;
return V_69 ;
}
static T_1 F_142 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_143 ( F_129 ( V_3 ) , V_5 ) ;
}
static T_1 F_144 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
return F_145 ( F_129 ( V_3 ) , V_5 ,
V_69 ) ;
}
static T_1 F_146 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_147 ( F_129 ( V_3 ) , V_5 ) ;
}
static T_1 F_148 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
return F_149 ( F_129 ( V_3 ) , V_5 ,
V_69 ) ;
}
static T_1 F_150 (
struct V_2 * V_3 , char * V_5 )
{
return F_151 ( F_129 ( V_3 ) , V_5 ) ;
}
static T_1 F_152 (
struct V_2 * V_3 , const char * V_5 , T_2 V_69 )
{
return F_153 ( F_129 ( V_3 ) , V_5 ,
V_69 ) ;
}
static T_1 F_154 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_155 ( F_129 ( V_3 ) , V_5 ) ;
}
static T_1 F_156 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
return F_157 ( F_129 ( V_3 ) , V_5 , V_69 ) ;
}
static T_1 F_158 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_254 * V_257 = F_129 ( V_3 ) ;
if ( ! V_257 -> V_261 )
return 0 ;
return sprintf ( V_5 , L_185 , V_257 -> V_272 ) ;
}
static T_1 F_159 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_254 * V_257 = F_129 ( V_3 ) ;
struct V_16 * V_273 = & V_257 -> V_255 ;
unsigned long V_272 ;
int V_18 ;
V_18 = F_121 ( V_5 , 0 , & V_272 ) ;
if ( V_18 < 0 ) {
F_27 ( L_186
L_216 , V_18 ) ;
return V_18 ;
}
if ( V_272 > 0x0000ffff ) {
F_27 ( L_217
L_189 , V_272 ) ;
return - V_19 ;
}
V_18 = F_160 ( V_257 , ( T_6 ) V_272 ) ;
if ( V_18 < 0 )
return - V_19 ;
F_12 ( L_218
L_219 ,
F_18 ( & V_273 -> V_24 ) ,
V_257 -> V_272 ) ;
return V_69 ;
}
static T_1 F_161 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_254 * V_257 = F_129 ( V_3 ) ;
struct V_274 * V_275 ;
T_1 V_118 = 0 , V_249 ;
unsigned char V_109 [ V_276 ] ;
memset ( V_109 , 0 , V_276 ) ;
F_65 ( & V_257 -> V_277 ) ;
F_8 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
struct V_143 * V_278 = V_275 -> V_279 ;
V_249 = snprintf ( V_109 , V_276 , L_220
L_221 , V_278 -> V_132 -> V_30 () ,
V_278 -> V_132 -> V_31 ( V_278 ) ,
V_278 -> V_132 -> V_32 ( V_278 ) ,
F_18 ( & V_275 -> V_280 . V_24 ) ) ;
V_249 ++ ;
if ( ( V_249 + V_118 ) > V_121 ) {
F_42 ( L_193
L_194 ) ;
break;
}
memcpy ( V_5 + V_118 , V_109 , V_249 ) ;
V_118 += V_249 ;
}
F_67 ( & V_257 -> V_277 ) ;
return V_118 ;
}
static void F_162 ( struct V_2 * V_3 )
{
struct V_254 * V_257 = F_2 ( F_3 ( V_3 ) ,
struct V_254 , V_255 ) ;
F_163 ( V_257 ) ;
}
static struct V_16 * F_164 (
struct V_16 * V_17 ,
const char * V_11 )
{
struct V_220 * V_281 = F_2 ( V_17 , struct V_220 ,
V_282 ) ;
struct V_254 * V_257 ;
struct V_16 * V_273 = NULL ;
struct V_2 * V_283 = NULL ;
V_257 = F_165 ( V_281 -> V_108 , V_11 , 0 ) ;
if ( ! V_257 )
return NULL ;
V_273 = & V_257 -> V_255 ;
V_283 = & V_273 -> V_24 ;
F_15 ( V_273 , V_11 ,
& V_284 ) ;
F_12 ( L_222
L_223 ,
F_18 ( V_283 ) ) ;
return V_273 ;
}
static void F_166 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_254 * V_257 = F_2 ( F_3 ( V_3 ) ,
struct V_254 , V_255 ) ;
F_12 ( L_224
L_225 ,
F_18 ( V_3 ) , V_257 -> V_272 ) ;
F_21 ( V_3 ) ;
}
static struct V_16 * F_167 (
struct V_16 * V_17 ,
const char * V_11 )
{
return F_14 ( - V_83 ) ;
}
static void F_168 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
return;
}
static struct V_16 * F_169 (
struct V_16 * V_17 ,
const char * V_11 )
{
struct V_254 * V_257 ;
struct V_2 * V_285 = & V_17 -> V_24 ;
struct V_1 * V_197 = F_1 ( V_285 ) ;
struct V_286 * V_287 = V_197 -> V_288 ;
struct V_63 * V_64 ;
int V_289 = - V_57 , V_18 ;
V_18 = F_170 ( & V_197 -> V_290 ) ;
if ( V_18 )
return F_14 ( V_18 ) ;
V_64 = F_171 ( V_197 , V_11 ) ;
if ( ! V_64 )
goto V_144;
F_15 ( & V_64 -> V_66 , V_11 , & V_287 -> V_291 ) ;
F_15 ( & V_64 -> V_99 . V_62 , L_226 ,
& V_287 -> V_292 ) ;
F_16 ( & V_64 -> V_99 . V_62 , & V_64 -> V_66 ) ;
F_15 ( & V_64 -> V_122 , L_227 ,
& V_287 -> V_293 ) ;
F_16 ( & V_64 -> V_122 , & V_64 -> V_66 ) ;
F_15 ( & V_64 -> V_67 . V_106 , L_228 ,
& V_287 -> V_294 ) ;
F_16 ( & V_64 -> V_67 . V_106 ,
& V_64 -> V_66 ) ;
F_15 ( & V_64 -> V_220 . V_282 ,
L_229 , & V_287 -> V_295 ) ;
F_16 ( & V_64 -> V_220 . V_282 ,
& V_64 -> V_66 ) ;
F_15 ( & V_64 -> V_296 . V_297 ,
L_230 , & V_287 -> V_298 ) ;
F_16 ( & V_64 -> V_296 . V_297 ,
& V_64 -> V_66 ) ;
V_257 = F_165 ( V_64 , L_231 , 1 ) ;
if ( ! V_257 )
goto V_299;
V_64 -> V_220 . V_300 = V_257 ;
F_15 ( & V_257 -> V_255 ,
L_231 , & V_284 ) ;
F_16 ( & V_257 -> V_255 ,
& V_64 -> V_220 . V_282 ) ;
F_172 ( V_64 ) ;
F_10 ( & V_197 -> V_290 ) ;
return & V_64 -> V_66 ;
V_299:
F_117 ( V_64 ) ;
V_144:
F_10 ( & V_197 -> V_290 ) ;
return F_14 ( V_289 ) ;
}
static void F_173 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_16 * V_246 = F_3 ( V_3 ) ;
struct V_63 * V_64 =
F_2 ( V_246 , struct V_63 , V_66 ) ;
struct V_1 * V_197 ;
V_197 = F_1 ( & V_64 -> V_1 -> V_4 . V_24 ) ;
F_7 ( & V_197 -> V_290 ) ;
F_20 ( & V_64 -> V_296 . V_297 ) ;
F_20 ( & V_64 -> V_220 . V_282 ) ;
V_64 -> V_220 . V_300 = NULL ;
F_20 ( V_246 ) ;
F_21 ( V_3 ) ;
F_10 ( & V_197 -> V_290 ) ;
}
static inline struct V_1 * F_174 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_175 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_197 = F_174 ( V_3 ) ;
return sprintf ( V_5 , L_232 ,
V_197 -> V_301 , V_197 -> V_288 -> V_302 -> V_11 ,
V_7 ) ;
}
static T_1 F_176 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_197 = F_174 ( V_3 ) ;
int V_303 = 0 ;
if ( V_197 -> V_304 & V_305 )
V_303 = 1 ;
return sprintf ( V_5 , L_158 , V_303 ) ;
}
static T_1 F_177 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_69 )
{
struct V_1 * V_197 = F_174 ( V_3 ) ;
unsigned long V_306 ;
int V_18 ;
if ( V_197 -> V_288 -> V_302 -> V_307 == NULL )
return - V_19 ;
V_18 = F_121 ( V_5 , 0 , & V_306 ) ;
if ( V_18 < 0 ) {
F_27 ( L_233 , V_18 ) ;
return V_18 ;
}
if ( V_197 -> V_308 ) {
F_27 ( L_234 ) ;
return - V_19 ;
}
V_18 = V_197 -> V_288 -> V_302 -> V_307 ( V_197 , V_306 ) ;
if ( V_18 < 0 )
return - V_19 ;
if ( V_18 > 0 )
V_197 -> V_304 |= V_305 ;
else if ( V_18 == 0 )
V_197 -> V_304 &= ~ V_305 ;
return V_69 ;
}
static void F_178 ( struct V_2 * V_3 )
{
struct V_1 * V_197 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_179 ( V_197 ) ;
}
static struct V_16 * F_180 (
struct V_16 * V_17 ,
const char * V_11 )
{
char * V_309 , * V_310 , * V_311 ;
struct V_1 * V_197 ;
char V_109 [ V_312 ] ;
unsigned long V_313 = 0 ;
int V_18 ;
memset ( V_109 , 0 , V_312 ) ;
if ( strlen ( V_11 ) >= V_312 ) {
F_27 ( L_235
L_236 , ( int ) strlen ( V_11 ) ,
V_312 ) ;
return F_14 ( - V_314 ) ;
}
snprintf ( V_109 , V_312 , L_53 , V_11 ) ;
V_310 = strstr ( V_109 , L_237 ) ;
if ( ! V_310 ) {
F_27 ( L_238 ) ;
return F_14 ( - V_19 ) ;
}
V_309 = V_109 ;
V_311 = strstr ( V_310 + 1 , L_237 ) ;
if ( V_311 ) {
* V_311 = '\0' ;
V_311 ++ ;
V_310 = V_311 ;
} else {
* V_310 = '\0' ;
V_310 ++ ;
}
V_18 = F_121 ( V_310 , 0 , & V_313 ) ;
if ( V_18 < 0 ) {
F_27 ( L_186
L_239 , V_18 ) ;
return F_14 ( V_18 ) ;
}
F_181 () ;
V_197 = F_182 ( V_309 , V_313 , 0 ) ;
if ( F_111 ( V_197 ) )
return F_183 ( V_197 ) ;
F_15 ( & V_197 -> V_4 , V_11 ,
& V_315 ) ;
return & V_197 -> V_4 ;
}
static void F_184 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
F_21 ( V_3 ) ;
}
void F_185 ( struct V_286 * V_287 )
{
F_186 ( V_287 ) ;
F_187 ( V_287 ) ;
F_188 ( V_287 ) ;
F_189 ( V_287 ) ;
F_190 ( V_287 ) ;
F_191 ( V_287 ) ;
}
static int T_8 F_192 ( void )
{
struct V_316 * V_317 = & V_26 ;
struct V_203 * V_204 ;
int V_18 ;
F_12 ( L_240
L_241 V_6 L_3 ,
V_7 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
F_193 ( & V_317 -> V_318 ) ;
F_194 ( & V_317 -> V_319 ) ;
V_18 = F_195 () ;
if ( V_18 < 0 )
return V_18 ;
F_15 ( & V_320 , L_242 ,
& V_321 ) ;
F_16 ( & V_320 , & V_317 -> V_318 ) ;
F_15 ( & V_322 , L_229 , & V_323 ) ;
F_16 ( & V_322 , & V_320 ) ;
F_15 ( & V_324 , L_243 ,
& V_325 ) ;
F_16 ( & V_324 , & V_322 ) ;
V_204 = F_127 ( L_244 , 1 ) ;
if ( F_111 ( V_204 ) ) {
V_18 = - V_57 ;
goto V_326;
}
F_15 ( & V_204 -> V_209 , L_244 ,
& V_253 ) ;
F_16 ( & V_204 -> V_209 , & V_324 ) ;
V_327 = V_204 ;
V_18 = F_196 ( V_317 ) ;
if ( V_18 < 0 ) {
F_27 ( L_245 ,
V_18 , V_317 -> V_318 . V_24 . V_328 ) ;
goto V_326;
}
F_12 ( L_246
L_247 V_7 L_248
L_249 V_6 L_3 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
V_18 = F_197 () ;
if ( V_18 < 0 )
goto V_173;
V_18 = F_198 () ;
if ( V_18 < 0 )
goto V_173;
V_18 = F_199 () ;
if ( V_18 < 0 )
goto V_173;
return 0 ;
V_173:
F_200 ( V_317 ) ;
F_201 () ;
F_202 () ;
V_326:
if ( V_327 ) {
F_125 ( V_327 ) ;
V_327 = NULL ;
}
F_203 () ;
return V_18 ;
}
static void T_9 F_204 ( void )
{
F_20 ( & V_324 ) ;
F_20 ( & V_322 ) ;
F_20 ( & V_320 ) ;
F_200 ( & V_26 ) ;
F_125 ( V_327 ) ;
V_327 = NULL ;
F_12 ( L_250
L_251 ) ;
F_201 () ;
F_202 () ;
F_205 () ;
F_203 () ;
}
