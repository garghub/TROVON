static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
char * V_7 )
{
return sprintf ( V_7 , L_1
L_2 V_8 L_3 , V_9 ,
F_5 () -> V_10 , F_5 () -> V_11 ) ;
}
static struct V_12 * F_6 (
const char * V_13 )
{
struct V_12 * V_14 ;
if ( ! V_13 )
return NULL ;
F_7 ( & V_15 ) ;
F_8 (tf, &g_tf_list, tf_list) {
if ( ! strcmp ( V_14 -> V_16 -> V_13 , V_13 ) ) {
F_9 ( & V_14 -> V_17 ) ;
F_10 ( & V_15 ) ;
return V_14 ;
}
}
F_10 ( & V_15 ) ;
return NULL ;
}
static struct V_18 * F_11 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_12 * V_14 ;
int V_20 ;
F_12 ( L_4
L_5 , V_19 , V_13 ) ;
V_14 = F_6 ( V_13 ) ;
if ( ! V_14 ) {
F_12 ( L_6 ,
V_13 ) ;
if ( ! strncmp ( V_13 , L_7 , 5 ) ) {
V_20 = F_13 ( L_8 ) ;
if ( V_20 < 0 ) {
F_12 ( L_9
L_10 , V_20 ) ;
return F_14 ( - V_21 ) ;
}
} else if ( ! strncmp ( V_13 , L_11 , 8 ) ) {
V_20 = F_13 ( L_12 ) ;
if ( V_20 < 0 ) {
F_12 ( L_9
L_13 , V_20 ) ;
return F_14 ( - V_21 ) ;
}
}
V_14 = F_6 ( V_13 ) ;
}
if ( ! V_14 ) {
F_12 ( L_14 ,
V_13 ) ;
return F_14 ( - V_21 ) ;
}
F_12 ( L_15
L_5 , V_14 -> V_16 -> V_13 ) ;
F_12 ( L_16 ,
& V_14 -> V_22 ) ;
V_14 -> V_23 . V_24 = V_14 -> V_25 ;
V_14 -> V_23 . V_24 [ 0 ] = & V_14 -> V_26 ;
V_14 -> V_23 . V_24 [ 1 ] = NULL ;
F_15 ( & V_14 -> V_23 , V_13 , & V_14 -> V_22 ) ;
F_15 ( & V_14 -> V_26 , L_17 ,
& V_14 -> V_27 ) ;
F_12 ( L_18
L_5 , V_14 -> V_23 . V_28 . V_29 ) ;
return & V_14 -> V_23 ;
}
static void F_16 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_12 * V_14 = F_2 (
F_3 ( V_3 ) , struct V_12 , V_23 ) ;
struct V_18 * V_23 ;
struct V_2 * V_30 ;
int V_31 ;
F_12 ( L_19
L_20 , F_17 ( V_3 ) ) ;
F_12 ( L_21
L_5 , V_14 -> V_16 -> V_13 ) ;
F_18 ( & V_14 -> V_17 ) ;
F_12 ( L_22
L_5 , F_17 ( V_3 ) ) ;
V_23 = & V_14 -> V_23 ;
for ( V_31 = 0 ; V_23 -> V_24 [ V_31 ] ; V_31 ++ ) {
V_30 = & V_23 -> V_24 [ V_31 ] -> V_28 ;
V_23 -> V_24 [ V_31 ] = NULL ;
F_19 ( V_30 ) ;
}
F_19 ( V_3 ) ;
}
int F_20 ( struct V_2 * V_3 )
{
return F_21 ( & V_32 , V_3 ) ;
}
void F_22 ( struct V_2 * V_3 )
{
return F_23 ( & V_32 , V_3 ) ;
}
static int F_24 ( const struct V_33 * V_34 )
{
if ( ! V_34 -> V_13 ) {
F_25 ( L_23 ) ;
return - V_21 ;
}
if ( strlen ( V_34 -> V_13 ) >= V_35 ) {
F_25 ( L_24
L_25 , V_34 -> V_13 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_36 ) {
F_25 ( L_26 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_37 ) {
F_25 ( L_27 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_38 ) {
F_25 ( L_28 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_39 ) {
F_25 ( L_29 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_40 ) {
F_25 ( L_30 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_41 ) {
F_25 ( L_31 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_42 ) {
F_25 ( L_32 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_43 ) {
F_25 ( L_33 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_44 ) {
F_25 ( L_34 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_45 ) {
F_25 ( L_35 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_46 ) {
F_25 ( L_36 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_47 ) {
F_25 ( L_37 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_48 ) {
F_25 ( L_38 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_49 ) {
F_25 ( L_39 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_50 ) {
F_25 ( L_40 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_51 ) {
F_25 ( L_41 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_52 ) {
F_25 ( L_42 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_53 ) {
F_25 ( L_43 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_54 ) {
F_25 ( L_44 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_55 ) {
F_25 ( L_45 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_56 ) {
F_25 ( L_46 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_57 ) {
F_25 ( L_47 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_58 ) {
F_25 ( L_48 ) ;
return - V_21 ;
}
if ( ! V_34 -> V_59 ) {
F_25 ( L_49 ) ;
return - V_21 ;
}
return 0 ;
}
int F_26 ( const struct V_33 * V_60 )
{
struct V_12 * V_14 ;
int V_20 ;
V_20 = F_24 ( V_60 ) ;
if ( V_20 )
return V_20 ;
V_14 = F_27 ( sizeof( struct V_12 ) , V_61 ) ;
if ( ! V_14 ) {
F_25 ( L_50 , V_62 ) ;
return - V_63 ;
}
F_28 ( & V_14 -> V_64 ) ;
F_29 ( & V_14 -> V_17 , 0 ) ;
V_14 -> V_16 = V_60 ;
F_30 ( V_14 ) ;
F_7 ( & V_15 ) ;
F_31 ( & V_14 -> V_64 , & V_65 ) ;
F_10 ( & V_15 ) ;
return 0 ;
}
void F_32 ( const struct V_33 * V_60 )
{
struct V_12 * V_66 ;
F_7 ( & V_15 ) ;
F_8 (t, &g_tf_list, tf_list) {
if ( ! strcmp ( V_66 -> V_16 -> V_13 , V_60 -> V_13 ) ) {
F_33 ( F_34 ( & V_66 -> V_17 ) ) ;
F_35 ( & V_66 -> V_64 ) ;
F_10 ( & V_15 ) ;
F_36 () ;
F_37 ( V_66 ) ;
return;
}
}
F_10 ( & V_15 ) ;
}
static void F_38 ( struct V_67 * V_68 )
{
const char * V_69 ;
V_69 = F_17 ( & V_68 -> V_70 . V_28 ) ;
if ( strlen ( V_69 ) >= 16 ) {
F_39 ( L_51
L_52 , V_68 ,
V_69 ) ;
}
snprintf ( & V_68 -> V_71 . V_72 [ 0 ] , 16 , L_53 , V_69 ) ;
}
static T_1 F_40 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
struct V_67 * V_68 = V_74 -> V_76 ;
bool V_77 ;
int V_20 ;
if ( V_68 -> V_78 ) {
F_25 ( L_54
L_55 ,
V_68 , V_68 -> V_78 ) ;
return - V_21 ;
}
V_20 = F_41 ( V_7 , & V_77 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_77 ) {
F_38 ( V_68 ) ;
} else {
strncpy ( & V_68 -> V_71 . V_72 [ 0 ] ,
V_68 -> V_79 -> V_80 , 16 ) ;
}
V_74 -> V_81 = V_77 ;
return V_75 ;
}
static T_1 F_42 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
bool V_77 ;
int V_20 ;
V_20 = F_41 ( V_7 , & V_77 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_77 && V_74 -> V_76 -> V_79 -> V_82 ) {
F_25 ( L_56 ) ;
return - V_21 ;
}
V_74 -> V_83 = V_77 ;
F_12 ( L_57 ,
V_74 -> V_76 , V_77 ) ;
return V_75 ;
}
static T_1 F_43 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
T_3 V_84 ;
int V_20 ;
V_20 = F_44 ( V_7 , 0 , & V_84 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_84 != 0 && V_84 != 1 && V_84 != 2 ) {
F_25 ( L_58 , V_84 ) ;
return - V_21 ;
}
if ( V_74 -> V_76 -> V_78 ) {
F_25 ( L_59
L_60 ,
V_74 -> V_76 , V_74 -> V_76 -> V_78 ) ;
return - V_21 ;
}
V_74 -> V_85 = V_84 ;
F_12 ( L_61 ,
V_74 -> V_76 , V_84 ) ;
return V_75 ;
}
static T_1 F_45 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
bool V_77 ;
int V_20 ;
V_20 = F_41 ( V_7 , & V_77 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_74 -> V_76 -> V_78 ) {
F_25 ( L_62
L_63 ,
V_74 -> V_76 , V_74 -> V_76 -> V_78 ) ;
return - V_21 ;
}
V_74 -> V_86 = V_77 ;
F_12 ( L_64 ,
V_74 -> V_76 , V_77 ? L_65 : L_66 ) ;
return V_75 ;
}
static T_1 F_46 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
bool V_77 ;
int V_20 ;
V_20 = F_41 ( V_7 , & V_77 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_77 && ! V_74 -> V_87 ) {
F_25 ( L_67 ) ;
return - V_88 ;
}
V_74 -> V_89 = V_77 ;
F_12 ( L_68 ,
V_74 -> V_76 , V_77 ) ;
return V_75 ;
}
static T_1 F_47 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
bool V_77 ;
int V_20 ;
V_20 = F_41 ( V_7 , & V_77 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_77 && ! V_74 -> V_87 ) {
F_25 ( L_67 ) ;
return - V_88 ;
}
V_74 -> V_90 = V_77 ;
F_12 ( L_69 ,
V_74 -> V_76 , V_77 ) ;
return V_75 ;
}
static T_1 F_48 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
int V_91 = V_74 -> V_92 , V_20 ;
struct V_67 * V_68 = V_74 -> V_76 ;
T_3 V_77 ;
V_20 = F_44 ( V_7 , 0 , & V_77 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_77 != 0 && V_77 != 1 && V_77 != 2 && V_77 != 3 ) {
F_25 ( L_70 , V_77 ) ;
return - V_21 ;
}
if ( V_77 == 2 ) {
F_25 ( L_71 ) ;
return - V_88 ;
}
if ( V_74 -> V_93 ) {
F_39 ( L_72
L_73 ) ;
return V_75 ;
}
if ( ! V_68 -> V_79 -> V_94 || ! V_68 -> V_79 -> V_95 ) {
if ( V_77 == 0 )
return V_75 ;
F_25 ( L_74 ,
V_68 -> V_79 -> V_13 ) ;
return - V_88 ;
}
if ( ! ( V_68 -> V_96 & V_97 ) ) {
F_25 ( L_75 ) ;
return - V_98 ;
}
if ( V_68 -> V_78 ) {
F_25 ( L_76
L_63 , V_68 , V_68 -> V_78 ) ;
return - V_21 ;
}
V_74 -> V_92 = V_77 ;
if ( V_77 && ! V_91 ) {
V_20 = V_68 -> V_79 -> V_94 ( V_68 ) ;
if ( V_20 ) {
V_74 -> V_92 = V_91 ;
return V_20 ;
}
} else if ( ! V_77 && V_91 ) {
V_68 -> V_79 -> V_95 ( V_68 ) ;
}
F_12 ( L_77 , V_68 , V_77 ) ;
return V_75 ;
}
static T_1 F_49 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
struct V_67 * V_68 = V_74 -> V_76 ;
bool V_77 ;
int V_20 ;
V_20 = F_41 ( V_7 , & V_77 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! V_77 )
return V_75 ;
if ( ! V_68 -> V_79 -> V_99 ) {
F_25 ( L_78 ,
V_68 -> V_79 -> V_13 ) ;
return - V_88 ;
}
if ( ! ( V_68 -> V_96 & V_97 ) ) {
F_25 ( L_79 ) ;
return - V_98 ;
}
if ( V_68 -> V_78 ) {
F_25 ( L_80
L_63 , V_68 , V_68 -> V_78 ) ;
return - V_21 ;
}
V_20 = V_68 -> V_79 -> V_99 ( V_68 ) ;
if ( V_20 )
return V_20 ;
F_12 ( L_81 , V_68 ) ;
return V_75 ;
}
static T_1 F_50 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
bool V_77 ;
int V_20 ;
V_20 = F_41 ( V_7 , & V_77 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_74 -> V_76 -> V_78 ) {
F_25 ( L_82
L_63 ,
V_74 -> V_76 , V_74 -> V_76 -> V_78 ) ;
return - V_21 ;
}
V_74 -> V_100 = V_77 ;
F_12 ( L_83 , V_74 -> V_76 , V_77 ) ;
return V_75 ;
}
static T_1 F_51 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
bool V_77 ;
int V_20 ;
V_20 = F_41 ( V_7 , & V_77 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_77 != 0 ) {
F_52 ( V_101 L_84
L_85 , V_74 -> V_76 ) ;
return - V_88 ;
}
V_74 -> V_102 = V_77 ;
F_12 ( L_86 ,
V_74 -> V_76 , V_77 ) ;
return V_75 ;
}
static T_1 F_53 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
struct V_67 * V_68 = V_74 -> V_76 ;
T_3 V_84 ;
int V_20 ;
V_20 = F_44 ( V_7 , 0 , & V_84 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_68 -> V_78 ) {
F_25 ( L_87
L_63 ,
V_68 , V_68 -> V_78 ) ;
return - V_21 ;
}
if ( ! V_84 ) {
F_25 ( L_88 , V_68 ) ;
return - V_21 ;
}
if ( V_84 > V_68 -> V_103 . V_104 ) {
if ( V_84 > V_68 -> V_103 . V_105 ) {
F_25 ( L_89
L_90
L_91 , V_68 , V_84 ,
V_68 -> V_103 . V_105 ) ;
return - V_21 ;
}
}
V_74 -> V_104 = V_68 -> V_104 = V_84 ;
F_12 ( L_92 , V_68 , V_84 ) ;
return V_75 ;
}
static T_1 F_54 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
T_3 V_84 ;
int V_20 ;
V_20 = F_44 ( V_7 , 0 , & V_84 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_74 -> V_76 -> V_78 ) {
F_25 ( L_59
L_93 ,
V_74 -> V_76 , V_74 -> V_76 -> V_78 ) ;
return - V_21 ;
}
if ( V_84 > V_74 -> V_106 ) {
F_25 ( L_94
L_95 ,
V_74 -> V_76 , V_84 , V_74 -> V_106 ) ;
return - V_21 ;
}
V_74 -> V_107 = V_84 ;
F_12 ( L_96 ,
V_74 -> V_76 , V_84 ) ;
return V_75 ;
}
static T_1 F_55 ( struct V_73 * V_74 ,
const char * V_7 , T_2 V_75 )
{
T_3 V_84 ;
int V_20 ;
V_20 = F_44 ( V_7 , 0 , & V_84 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_74 -> V_76 -> V_78 ) {
F_25 ( L_97
L_55 ,
V_74 -> V_76 , V_74 -> V_76 -> V_78 ) ;
return - V_21 ;
}
if ( V_84 != 512 && V_84 != 1024 && V_84 != 2048 && V_84 != 4096 ) {
F_25 ( L_98
L_99 ,
V_74 -> V_76 , V_84 ) ;
return - V_21 ;
}
V_74 -> V_108 = V_84 ;
if ( V_74 -> V_109 )
V_74 -> V_106 = V_74 -> V_109 / V_84 ;
F_12 ( L_100 ,
V_74 -> V_76 , V_84 ) ;
return V_75 ;
}
static T_1 F_56 (
struct V_71 * V_71 ,
char * V_7 )
{
return sprintf ( V_7 , L_101 ,
& V_71 -> V_110 [ 0 ] ) ;
}
static T_1 F_57 (
struct V_71 * V_71 ,
const char * V_7 ,
T_2 V_75 )
{
struct V_67 * V_68 = V_71 -> V_111 ;
unsigned char V_112 [ V_113 ] ;
if ( V_68 -> V_96 & V_114 ) {
F_25 ( L_102
L_103 ) ;
return - V_115 ;
}
if ( strlen ( V_7 ) >= V_113 ) {
F_25 ( L_104
L_105 , V_113 ) ;
return - V_116 ;
}
if ( V_68 -> V_78 ) {
F_25 ( L_106
L_107 ,
V_68 -> V_78 ) ;
return - V_21 ;
}
memset ( V_112 , 0 , V_113 ) ;
snprintf ( V_112 , V_113 , L_53 , V_7 ) ;
snprintf ( V_68 -> V_71 . V_110 , V_113 ,
L_53 , F_58 ( V_112 ) ) ;
V_68 -> V_96 |= V_117 ;
F_12 ( L_108
L_5 , V_68 -> V_71 . V_110 ) ;
return V_75 ;
}
static T_1 F_59 (
struct V_71 * V_71 ,
char * V_7 )
{
struct V_118 * V_119 ;
unsigned char V_112 [ V_120 ] ;
T_1 V_121 = 0 ;
memset ( V_112 , 0 , V_120 ) ;
F_60 ( & V_71 -> V_122 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_119 -> V_123 )
continue;
F_61 ( V_119 , V_112 , V_120 ) ;
if ( V_121 + strlen ( V_112 ) >= V_124 )
break;
V_121 += sprintf ( V_7 + V_121 , L_53 , V_112 ) ;
}
F_62 ( & V_71 -> V_122 ) ;
return V_121 ;
}
static T_1 F_63 (
struct V_71 * V_71 ,
const char * V_7 ,
T_2 V_75 )
{
return - V_88 ;
}
static T_1 F_64 (
struct V_71 * V_71 ,
const char * V_7 ,
T_2 V_75 )
{
return - V_88 ;
}
static T_1 F_65 (
struct V_71 * V_71 ,
const char * V_7 ,
T_2 V_75 )
{
return - V_88 ;
}
static T_1 F_66 (
struct V_71 * V_71 ,
const char * V_7 ,
T_2 V_75 )
{
return - V_88 ;
}
static T_1 F_67 ( struct V_67 * V_68 ,
char * V_7 )
{
struct V_125 * V_126 ;
struct V_127 * V_128 ;
char V_129 [ V_130 ] ;
memset ( V_129 , 0 , V_130 ) ;
V_128 = V_68 -> V_131 ;
if ( ! V_128 )
return sprintf ( V_7 , L_109 ) ;
V_126 = V_128 -> V_132 ;
F_68 ( V_128 , V_129 , V_130 ) ;
return sprintf ( V_7 , L_110 ,
V_126 -> V_133 -> V_134 -> V_36 () ,
V_126 -> V_135 , V_129 ) ;
}
static T_1 F_69 ( struct V_67 * V_68 ,
char * V_7 )
{
struct V_125 * V_126 ;
T_1 V_121 ;
V_126 = V_68 -> V_136 ;
if ( V_126 ) {
V_121 = sprintf ( V_7 ,
L_111 ,
V_126 -> V_133 -> V_134 -> V_36 () ,
V_126 -> V_135 ) ;
} else {
V_121 = sprintf ( V_7 , L_112 ) ;
}
return V_121 ;
}
static T_1 F_70 ( struct V_67 * V_68 ,
char * V_7 )
{
int V_20 ;
if ( V_68 -> V_79 -> V_137 & V_138 )
return sprintf ( V_7 , L_113 ) ;
F_60 ( & V_68 -> V_139 ) ;
if ( V_68 -> V_140 & V_141 )
V_20 = F_69 ( V_68 , V_7 ) ;
else
V_20 = F_67 ( V_68 , V_7 ) ;
F_62 ( & V_68 -> V_139 ) ;
return V_20 ;
}
static T_1 F_71 (
struct V_67 * V_68 , char * V_7 )
{
T_1 V_121 = 0 ;
F_60 ( & V_68 -> V_139 ) ;
if ( ! V_68 -> V_131 ) {
V_121 = sprintf ( V_7 , L_109 ) ;
} else if ( V_68 -> V_131 -> V_142 ) {
V_121 = sprintf ( V_7 , L_114
L_115 ) ;
} else {
V_121 = sprintf ( V_7 , L_116
L_117 ) ;
}
F_62 ( & V_68 -> V_139 ) ;
return V_121 ;
}
static T_1 F_72 (
struct V_67 * V_68 , char * V_7 )
{
return sprintf ( V_7 , L_118 , V_68 -> V_143 . V_144 ) ;
}
static T_1 F_73 (
struct V_67 * V_68 , char * V_7 )
{
struct V_125 * V_126 ;
struct V_145 * V_133 ;
struct V_127 * V_128 ;
const struct V_33 * V_34 ;
T_1 V_121 = 0 ;
F_60 ( & V_68 -> V_139 ) ;
V_128 = V_68 -> V_131 ;
if ( ! V_128 ) {
V_121 = sprintf ( V_7 , L_109 ) ;
goto V_146;
}
V_126 = V_128 -> V_132 ;
V_133 = V_126 -> V_133 ;
V_34 = V_133 -> V_134 ;
V_121 += sprintf ( V_7 + V_121 , L_119
L_120 , V_34 -> V_36 () ,
V_34 -> V_37 ( V_133 ) ) ;
V_121 += sprintf ( V_7 + V_121 , L_121
L_122
L_123 , V_128 -> V_147 ,
V_34 -> V_36 () , V_34 -> V_38 ( V_133 ) ,
V_34 -> V_36 () , V_128 -> V_148 ) ;
V_146:
F_62 ( & V_68 -> V_139 ) ;
return V_121 ;
}
static T_1 F_74 (
struct V_67 * V_68 , char * V_7 )
{
const struct V_33 * V_34 ;
struct V_127 * V_128 ;
unsigned char V_112 [ 384 ] ;
char V_129 [ V_130 ] ;
T_1 V_121 = 0 ;
int V_149 = 0 ;
V_121 += sprintf ( V_7 + V_121 , L_124 ) ;
F_60 ( & V_68 -> V_143 . V_150 ) ;
F_8 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_112 , 0 , 384 ) ;
memset ( V_129 , 0 , V_130 ) ;
V_34 = V_128 -> V_132 -> V_133 -> V_134 ;
F_68 ( V_128 , V_129 ,
V_130 ) ;
sprintf ( V_112 , L_125 ,
V_34 -> V_36 () ,
V_128 -> V_132 -> V_135 , V_129 , V_128 -> V_151 ,
V_128 -> V_152 ) ;
if ( V_121 + strlen ( V_112 ) >= V_124 )
break;
V_121 += sprintf ( V_7 + V_121 , L_53 , V_112 ) ;
V_149 ++ ;
}
F_62 ( & V_68 -> V_143 . V_150 ) ;
if ( ! V_149 )
V_121 += sprintf ( V_7 + V_121 , L_126 ) ;
return V_121 ;
}
static T_1 F_75 (
struct V_67 * V_68 , char * V_7 )
{
struct V_127 * V_128 ;
T_1 V_121 = 0 ;
F_60 ( & V_68 -> V_139 ) ;
V_128 = V_68 -> V_131 ;
if ( V_128 ) {
V_121 = sprintf ( V_7 , L_127 ,
F_76 ( V_128 -> V_153 ) ) ;
} else {
V_121 = sprintf ( V_7 , L_109 ) ;
}
F_62 ( & V_68 -> V_139 ) ;
return V_121 ;
}
static T_1 F_77 (
struct V_67 * V_68 , char * V_7 )
{
if ( V_68 -> V_79 -> V_137 & V_138 )
return sprintf ( V_7 , L_128 ) ;
else if ( V_68 -> V_140 & V_141 )
return sprintf ( V_7 , L_129 ) ;
else
return sprintf ( V_7 , L_130 ) ;
}
static T_1 F_78 (
struct V_67 * V_68 , char * V_7 )
{
if ( V_68 -> V_79 -> V_137 & V_138 )
return 0 ;
return sprintf ( V_7 , L_131 ,
( V_68 -> V_143 . V_154 ) ? L_132 : L_66 ) ;
}
static T_1 F_79 (
struct V_67 * V_68 , char * V_7 )
{
if ( V_68 -> V_79 -> V_137 & V_138 )
return 0 ;
return sprintf ( V_7 , L_133 ) ;
}
static T_1 F_80 (
struct V_67 * V_68 ,
const char * V_7 ,
T_2 V_75 )
{
unsigned char * V_155 = NULL , * V_156 = NULL , * V_157 = NULL ;
unsigned char * V_158 = NULL , * V_159 = NULL ;
char * V_160 , * V_161 , * V_162 ;
T_4 args [ V_163 ] ;
unsigned long long V_164 ;
T_5 V_165 = 0 ;
T_5 V_166 = 0 , V_167 = 0 ;
int V_20 = - 1 , V_168 = 0 , V_169 = 0 , V_170 , V_171 ;
T_6 V_172 = 0 ;
T_7 type = 0 ;
if ( V_68 -> V_79 -> V_137 & V_138 )
return V_75 ;
if ( V_68 -> V_140 & V_141 )
return V_75 ;
if ( V_68 -> V_78 ) {
F_12 ( L_134
L_135 ) ;
return - V_21 ;
}
V_162 = F_81 ( V_7 , V_61 ) ;
if ( ! V_162 )
return - V_63 ;
V_160 = V_162 ;
while ( ( V_161 = F_82 ( & V_162 , L_136 ) ) != NULL ) {
if ( ! * V_161 )
continue;
V_171 = F_83 ( V_161 , V_173 , args ) ;
switch ( V_171 ) {
case V_174 :
V_155 = F_84 ( args ) ;
if ( ! V_155 ) {
V_20 = - V_63 ;
goto V_175;
}
break;
case V_176 :
V_156 = F_84 ( args ) ;
if ( ! V_156 ) {
V_20 = - V_63 ;
goto V_175;
}
if ( strlen ( V_156 ) >= V_177 ) {
F_25 ( L_137
L_138 ,
V_177 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_178 :
V_157 = F_84 ( args ) ;
if ( ! V_157 ) {
V_20 = - V_63 ;
goto V_175;
}
if ( strlen ( V_157 ) >= V_179 ) {
F_25 ( L_139
L_140 ,
V_179 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_180 :
V_20 = F_85 ( args -> V_181 , 0 , & V_164 ) ;
if ( V_20 < 0 ) {
F_25 ( L_141 ) ;
goto V_175;
}
V_165 = ( T_5 ) V_164 ;
break;
case V_182 :
V_20 = F_86 ( args , & V_170 ) ;
if ( V_20 )
goto V_175;
V_168 = V_170 ;
break;
case V_183 :
V_20 = F_86 ( args , & V_170 ) ;
if ( V_20 )
goto V_175;
type = ( T_7 ) V_170 ;
break;
case V_184 :
V_20 = F_86 ( args , & V_170 ) ;
if ( V_20 )
goto V_175;
break;
case V_185 :
V_20 = F_86 ( args , & V_170 ) ;
if ( V_20 )
goto V_175;
V_169 = ( int ) V_170 ;
break;
case V_186 :
V_20 = F_86 ( args , & V_170 ) ;
if ( V_20 )
goto V_175;
V_166 = ( T_5 ) V_170 ;
break;
case V_187 :
V_158 = F_84 ( args ) ;
if ( ! V_158 ) {
V_20 = - V_63 ;
goto V_175;
}
break;
case V_188 :
V_159 = F_84 ( args ) ;
if ( ! V_159 ) {
V_20 = - V_63 ;
goto V_175;
}
if ( strlen ( V_159 ) >= V_189 ) {
F_25 ( L_142
L_143 ,
V_189 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_190 :
V_20 = F_86 ( args , & V_170 ) ;
if ( V_20 )
goto V_175;
V_172 = ( T_6 ) V_170 ;
break;
case V_191 :
V_20 = F_86 ( args , & V_170 ) ;
if ( V_20 )
goto V_175;
break;
case V_192 :
V_20 = F_86 ( args , & V_170 ) ;
if ( V_20 )
goto V_175;
V_167 = ( T_5 ) V_170 ;
break;
default:
break;
}
}
if ( ! V_156 || ! V_159 || ! V_165 ) {
F_25 ( L_144 ) ;
V_20 = - V_21 ;
goto V_175;
}
if ( V_168 && ! ( type ) ) {
F_25 ( L_145
L_146 , type ) ;
V_20 = - V_21 ;
goto V_175;
}
V_20 = F_87 ( & V_68 -> V_143 , V_165 ,
V_156 , V_157 , V_166 , V_159 , V_172 , V_167 ,
V_168 , V_169 , type ) ;
V_175:
F_37 ( V_155 ) ;
F_37 ( V_156 ) ;
F_37 ( V_157 ) ;
F_37 ( V_158 ) ;
F_37 ( V_159 ) ;
F_37 ( V_160 ) ;
return ( V_20 == 0 ) ? V_75 : V_20 ;
}
static T_1 F_88 ( void * V_193 , char * V_7 )
{
struct V_67 * V_68 = V_193 ;
int V_194 = 0 ;
T_1 V_195 = 0 ;
F_89 ( V_68 , V_7 , & V_194 ) ;
V_195 += V_194 ;
V_195 += V_68 -> V_79 -> V_196 ( V_68 ,
V_7 + V_195 ) ;
return V_195 ;
}
static T_1 F_90 (
void * V_193 ,
const char * V_7 ,
T_2 V_75 )
{
struct V_67 * V_68 = V_193 ;
return V_68 -> V_79 -> V_197 ( V_68 , V_7 , V_75 ) ;
}
static T_1 F_91 ( void * V_193 , char * V_7 )
{
struct V_67 * V_68 = V_193 ;
if ( ! ( V_68 -> V_96 & V_198 ) )
return 0 ;
return snprintf ( V_7 , V_124 , L_147 , V_68 -> V_199 ) ;
}
static T_1 F_92 (
void * V_193 ,
const char * V_7 ,
T_2 V_75 )
{
struct V_67 * V_68 = V_193 ;
struct V_1 * V_200 = V_68 -> V_1 ;
T_1 V_195 ;
if ( V_75 > ( V_201 - 1 ) ) {
F_25 ( L_148
L_149 , ( int ) V_75 ,
V_201 - 1 ) ;
return - V_21 ;
}
V_195 = snprintf ( & V_68 -> V_199 [ 0 ] , V_201 , L_53 , V_7 ) ;
if ( ! V_195 )
return - V_21 ;
if ( V_68 -> V_199 [ V_195 - 1 ] == '\n' )
V_68 -> V_199 [ V_195 - 1 ] = '\0' ;
V_68 -> V_96 |= V_198 ;
F_12 ( L_150 ,
F_17 ( & V_200 -> V_4 . V_28 ) ,
F_17 ( & V_68 -> V_70 . V_28 ) ,
V_68 -> V_199 ) ;
return V_195 ;
}
static T_1 F_93 ( void * V_193 , char * V_7 )
{
struct V_67 * V_68 = V_193 ;
if ( ! ( V_68 -> V_96 & V_202 ) )
return 0 ;
return snprintf ( V_7 , V_124 , L_147 , V_68 -> V_203 ) ;
}
static T_1 F_94 (
void * V_193 ,
const char * V_7 ,
T_2 V_75 )
{
struct V_67 * V_68 = V_193 ;
struct V_1 * V_200 = V_68 -> V_1 ;
T_1 V_195 ;
if ( V_75 > ( V_204 - 1 ) ) {
F_25 ( L_151
L_152 , ( int ) V_75 ,
V_204 - 1 ) ;
return - V_21 ;
}
V_195 = snprintf ( & V_68 -> V_203 [ 0 ] , V_204 ,
L_53 , V_7 ) ;
if ( ! V_195 )
return - V_21 ;
if ( V_68 -> V_203 [ V_195 - 1 ] == '\n' )
V_68 -> V_203 [ V_195 - 1 ] = '\0' ;
V_68 -> V_96 |= V_202 ;
F_12 ( L_153 ,
F_17 ( & V_200 -> V_4 . V_28 ) ,
F_17 ( & V_68 -> V_70 . V_28 ) ,
V_68 -> V_203 ) ;
return V_195 ;
}
static T_1 F_95 ( void * V_193 , char * V_7 )
{
struct V_67 * V_68 = V_193 ;
return snprintf ( V_7 , V_124 , L_154 , ! ! ( V_68 -> V_96 & V_97 ) ) ;
}
static T_1 F_96 (
void * V_193 ,
const char * V_7 ,
T_2 V_75 )
{
struct V_67 * V_68 = V_193 ;
char * V_161 ;
int V_20 ;
V_161 = strstr ( V_7 , L_155 ) ;
if ( ! V_161 ) {
F_25 ( L_156
L_157 ) ;
return - V_21 ;
}
V_20 = F_97 ( V_68 ) ;
if ( V_20 )
return V_20 ;
return V_75 ;
}
static T_1 F_98 ( void * V_193 , char * V_7 )
{
struct V_67 * V_68 = V_193 ;
struct V_2 * V_205 ;
struct V_206 * V_207 ;
struct V_208 * V_209 ;
T_1 V_121 = 0 ;
V_209 = V_68 -> V_210 ;
if ( ! V_209 )
return 0 ;
F_60 ( & V_209 -> V_211 ) ;
V_207 = V_209 -> V_207 ;
if ( V_207 ) {
V_205 = & V_207 -> V_212 . V_28 ;
V_121 += sprintf ( V_7 , L_158 ,
F_17 ( V_205 ) , V_207 -> V_213 ) ;
}
F_62 ( & V_209 -> V_211 ) ;
return V_121 ;
}
static T_1 F_99 (
void * V_193 ,
const char * V_7 ,
T_2 V_75 )
{
struct V_67 * V_68 = V_193 ;
struct V_1 * V_200 = V_68 -> V_1 ;
struct V_206 * V_207 = NULL , * V_214 = NULL ;
struct V_208 * V_209 ;
unsigned char V_112 [ V_215 ] ;
int V_216 = 0 ;
V_209 = V_68 -> V_210 ;
if ( ! V_209 )
return V_75 ;
if ( V_75 > V_215 ) {
F_25 ( L_159 ) ;
return - V_21 ;
}
memset ( V_112 , 0 , V_215 ) ;
memcpy ( V_112 , V_7 , V_75 ) ;
if ( strcmp ( F_58 ( V_112 ) , L_160 ) ) {
V_214 = F_100 ( F_58 ( V_112 ) ) ;
if ( ! V_214 )
return - V_98 ;
}
F_60 ( & V_209 -> V_211 ) ;
V_207 = V_209 -> V_207 ;
if ( V_207 ) {
if ( ! V_214 ) {
F_12 ( L_161
L_162
L_163 ,
F_17 ( & V_200 -> V_4 . V_28 ) ,
F_17 ( & V_68 -> V_70 . V_28 ) ,
F_17 ( & V_207 -> V_212 . V_28 ) ,
V_207 -> V_213 ) ;
F_101 ( V_209 , V_207 ) ;
F_62 ( & V_209 -> V_211 ) ;
return V_75 ;
}
F_101 ( V_209 , V_207 ) ;
V_216 = 1 ;
}
F_102 ( V_209 , V_214 ) ;
F_62 ( & V_209 -> V_211 ) ;
F_12 ( L_164
L_165 ,
( V_216 ) ? L_166 : L_167 ,
F_17 ( & V_200 -> V_4 . V_28 ) ,
F_17 ( & V_68 -> V_70 . V_28 ) ,
F_17 ( & V_214 -> V_212 . V_28 ) ,
V_214 -> V_213 ) ;
F_103 ( V_214 ) ;
return V_75 ;
}
static T_1 F_104 ( void * V_193 , char * V_7 )
{
struct V_67 * V_68 = V_193 ;
struct V_217 * V_218 ;
struct V_219 * V_220 ;
char * V_221 = V_7 ;
int V_194 = 0 ;
char V_222 ;
F_60 ( & V_68 -> V_223 . V_224 ) ;
if ( ! F_105 ( & V_68 -> V_223 . V_225 ) )
V_194 += sprintf ( V_221 + V_194 , L_168 ,
V_68 -> V_223 . V_226 ,
V_68 -> V_223 . V_227 ) ;
F_8 (map, &dev->t10_alua.lba_map_list, lba_map_list) {
V_194 += sprintf ( V_221 + V_194 , L_169 ,
V_218 -> V_228 , V_218 -> V_229 ) ;
F_8 (mem, &map->lba_map_mem_list,
lba_map_mem_list) {
switch ( V_220 -> V_230 ) {
case V_231 :
V_222 = 'O' ;
break;
case V_232 :
V_222 = 'A' ;
break;
case V_233 :
V_222 = 'S' ;
break;
case V_234 :
V_222 = 'U' ;
break;
default:
V_222 = '.' ;
break;
}
V_194 += sprintf ( V_221 + V_194 , L_170 ,
V_220 -> V_235 , V_222 ) ;
}
V_194 += sprintf ( V_221 + V_194 , L_3 ) ;
}
F_62 ( & V_68 -> V_223 . V_224 ) ;
return V_194 ;
}
static T_1 F_106 (
void * V_193 ,
const char * V_7 ,
T_2 V_75 )
{
struct V_67 * V_68 = V_193 ;
struct V_217 * V_236 = NULL ;
struct V_237 V_238 ;
char * V_239 , * V_161 ;
char V_222 ;
int V_240 = - 1 , V_241 ;
int V_20 = 0 , V_242 = 0 , V_243 , V_244 ;
unsigned long V_245 = - 1 , V_246 = - 1 ;
unsigned long V_247 = - 1 , V_248 = - 1 ;
V_239 = F_81 ( V_7 , V_61 ) ;
if ( ! V_239 )
return - V_63 ;
F_28 ( & V_238 ) ;
while ( ( V_161 = F_82 ( & V_239 , L_3 ) ) != NULL ) {
if ( ! * V_161 )
continue;
if ( V_242 == 0 ) {
if ( sscanf ( V_161 , L_171 ,
& V_247 , & V_248 ) != 2 ) {
F_25 ( L_172 , V_242 ) ;
V_20 = - V_21 ;
break;
}
V_242 ++ ;
continue;
}
if ( sscanf ( V_161 , L_173 , & V_245 , & V_246 ) != 2 ) {
F_25 ( L_172 , V_242 ) ;
V_20 = - V_21 ;
break;
}
V_161 = strchr ( V_161 , ' ' ) ;
if ( ! V_161 ) {
F_25 ( L_174 , V_242 ) ;
V_20 = - V_21 ;
break;
}
V_161 ++ ;
V_161 = strchr ( V_161 , ' ' ) ;
if ( ! V_161 ) {
F_25 ( L_175 ,
V_242 ) ;
V_20 = - V_21 ;
break;
}
V_161 ++ ;
V_236 = F_107 ( & V_238 ,
V_245 , V_246 ) ;
if ( F_108 ( V_236 ) ) {
V_20 = F_109 ( V_236 ) ;
break;
}
V_241 = 0 ;
while ( sscanf ( V_161 , L_176 , & V_243 , & V_222 ) == 2 ) {
switch ( V_222 ) {
case 'O' :
V_244 = V_231 ;
break;
case 'A' :
V_244 = V_232 ;
break;
case 'S' :
V_244 = V_233 ;
break;
case 'U' :
V_244 = V_234 ;
break;
default:
F_25 ( L_177 , V_222 ) ;
V_20 = - V_21 ;
goto V_175;
}
V_20 = F_110 ( V_236 ,
V_243 , V_244 ) ;
if ( V_20 ) {
F_25 ( L_178
L_179 ,
V_243 , V_222 , V_242 ) ;
break;
}
V_241 ++ ;
V_161 = strchr ( V_161 , ' ' ) ;
if ( V_161 )
V_161 ++ ;
else
break;
}
if ( V_240 == - 1 )
V_240 = V_241 ;
else if ( V_241 != V_240 ) {
F_25 ( L_180
L_179 , V_241 , V_240 , V_242 ) ;
V_20 = - V_21 ;
break;
}
V_242 ++ ;
}
V_175:
if ( V_20 ) {
F_111 ( & V_238 ) ;
V_75 = V_20 ;
} else
F_112 ( V_68 , & V_238 ,
V_247 , V_248 ) ;
F_37 ( V_239 ) ;
return V_75 ;
}
static void F_113 ( struct V_2 * V_3 )
{
struct V_18 * V_249 = F_3 ( V_3 ) ;
struct V_67 * V_68 =
F_2 ( V_249 , struct V_67 , V_70 ) ;
F_37 ( V_249 -> V_24 ) ;
F_114 ( V_68 ) ;
}
static T_1 F_115 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
char * V_7 )
{
struct V_18 * V_249 = F_3 ( V_3 ) ;
struct V_67 * V_68 =
F_2 ( V_249 , struct V_67 , V_70 ) ;
struct V_250 * V_251 = F_2 (
V_6 , struct V_250 , V_6 ) ;
if ( ! V_251 -> V_252 )
return - V_21 ;
return V_251 -> V_252 ( V_68 , V_7 ) ;
}
static T_1 F_116 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
const char * V_7 , T_2 V_75 )
{
struct V_18 * V_249 = F_3 ( V_3 ) ;
struct V_67 * V_68 =
F_2 ( V_249 , struct V_67 , V_70 ) ;
struct V_250 * V_251 = F_2 (
V_6 , struct V_250 , V_6 ) ;
if ( ! V_251 -> V_253 )
return - V_21 ;
return V_251 -> V_253 ( V_68 , V_7 , V_75 ) ;
}
static T_1 F_117 (
struct V_206 * V_207 ,
char * V_7 )
{
if ( ! V_207 -> V_254 )
return 0 ;
return sprintf ( V_7 , L_181 , V_207 -> V_213 ) ;
}
static T_1 F_118 (
struct V_206 * V_207 ,
const char * V_7 ,
T_2 V_75 )
{
struct V_18 * V_255 = & V_207 -> V_212 ;
unsigned long V_213 ;
int V_20 ;
V_20 = F_119 ( V_7 , 0 , & V_213 ) ;
if ( V_20 < 0 ) {
F_25 ( L_182
L_183 , V_20 ) ;
return V_20 ;
}
if ( V_213 > 0x0000ffff ) {
F_25 ( L_184
L_185 , V_213 ) ;
return - V_21 ;
}
V_20 = F_120 ( V_207 , ( T_6 ) V_213 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_186
L_187 ,
F_17 ( & V_255 -> V_28 ) ,
V_207 -> V_213 ) ;
return V_75 ;
}
static T_1 F_121 (
struct V_206 * V_207 ,
char * V_7 )
{
struct V_67 * V_68 ;
struct V_1 * V_200 ;
struct V_208 * V_209 ;
T_1 V_121 = 0 , V_256 ;
unsigned char V_112 [ V_215 ] ;
memset ( V_112 , 0 , V_215 ) ;
F_60 ( & V_207 -> V_257 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_68 = V_209 -> V_258 ;
V_200 = V_68 -> V_1 ;
V_256 = snprintf ( V_112 , V_215 , L_188 ,
F_17 ( & V_200 -> V_4 . V_28 ) ,
F_17 ( & V_68 -> V_70 . V_28 ) ) ;
V_256 ++ ;
if ( ( V_256 + V_121 ) > V_124 ) {
F_39 ( L_189
L_190 ) ;
break;
}
memcpy ( V_7 + V_121 , V_112 , V_256 ) ;
V_121 += V_256 ;
}
F_62 ( & V_207 -> V_257 ) ;
return V_121 ;
}
static void F_122 ( struct V_2 * V_3 )
{
struct V_206 * V_207 = F_2 ( F_3 ( V_3 ) ,
struct V_206 , V_212 ) ;
F_123 ( V_207 ) ;
}
static struct V_18 * F_124 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_206 * V_207 ;
struct V_18 * V_255 = NULL ;
struct V_2 * V_259 = NULL ;
V_207 = F_125 ( V_13 , 0 ) ;
if ( F_108 ( V_207 ) )
return NULL ;
V_255 = & V_207 -> V_212 ;
V_259 = & V_255 -> V_28 ;
F_15 ( V_255 , V_13 ,
& V_260 ) ;
F_12 ( L_191
L_192 ,
F_17 ( V_259 ) ) ;
return V_255 ;
}
static void F_126 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_206 * V_207 = F_2 ( F_3 ( V_3 ) ,
struct V_206 , V_212 ) ;
F_12 ( L_193
L_194 ,
F_17 ( V_3 ) , V_207 -> V_213 ) ;
F_19 ( V_3 ) ;
}
static T_1 F_127 (
struct V_261 * V_262 ,
char * V_7 )
{
return sprintf ( V_7 , L_154 ,
F_34 ( & V_262 -> V_263 ) ) ;
}
static T_1 F_128 (
struct V_261 * V_262 ,
const char * V_7 ,
T_2 V_75 )
{
struct V_67 * V_68 = V_262 -> V_264 ;
unsigned long V_265 ;
int V_266 , V_20 ;
if ( ! V_262 -> V_267 ) {
F_25 ( L_195
L_196 , V_262 -> V_267 ) ;
return - V_21 ;
}
if ( ! ( V_68 -> V_96 & V_97 ) ) {
F_25 ( L_197
L_198 ) ;
return - V_98 ;
}
V_20 = F_119 ( V_7 , 0 , & V_265 ) ;
if ( V_20 < 0 ) {
F_25 ( L_199
L_5 , V_7 ) ;
return V_20 ;
}
V_266 = ( int ) V_265 ;
if ( ! ( V_262 -> V_268 & V_269 ) ) {
F_25 ( L_200
L_201 ) ;
return - V_21 ;
}
if ( V_262 -> V_268 & V_270 &&
V_266 == V_271 ) {
F_25 ( L_202
L_203 ) ;
return - V_21 ;
}
V_20 = F_129 ( V_262 , V_68 ,
NULL , NULL , V_266 , 0 ) ;
return ( ! V_20 ) ? V_75 : - V_21 ;
}
static T_1 F_130 (
struct V_261 * V_262 ,
char * V_7 )
{
return sprintf ( V_7 , L_147 ,
F_131 ( V_262 -> V_272 ) ) ;
}
static T_1 F_132 (
struct V_261 * V_262 ,
const char * V_7 ,
T_2 V_75 )
{
unsigned long V_265 ;
int V_273 , V_20 ;
if ( ! V_262 -> V_267 ) {
F_25 ( L_204
L_205 ,
V_262 -> V_267 ) ;
return - V_21 ;
}
V_20 = F_119 ( V_7 , 0 , & V_265 ) ;
if ( V_20 < 0 ) {
F_25 ( L_206
L_207 , V_7 ) ;
return V_20 ;
}
V_273 = ( int ) V_265 ;
if ( ( V_273 != V_274 ) &&
( V_273 != V_275 ) &&
( V_273 != V_276 ) ) {
F_25 ( L_208 ,
V_273 ) ;
return - V_21 ;
}
V_262 -> V_272 = V_273 ;
return V_75 ;
}
static T_1 F_133 (
struct V_261 * V_262 ,
char * V_7 )
{
return F_134 ( V_262 , V_7 ) ;
}
static T_1 F_135 (
struct V_261 * V_262 ,
const char * V_7 ,
T_2 V_75 )
{
return F_136 ( V_262 , V_7 , V_75 ) ;
}
static T_1 F_137 (
struct V_261 * V_262 ,
char * V_7 )
{
return sprintf ( V_7 , L_154 , V_262 -> V_277 ) ;
}
static T_1 F_138 (
struct V_261 * V_262 ,
const char * V_7 ,
T_2 V_75 )
{
unsigned long V_265 ;
int V_20 ;
V_20 = F_119 ( V_7 , 0 , & V_265 ) ;
if ( V_20 < 0 ) {
F_25 ( L_209 ) ;
return V_20 ;
}
if ( ( V_265 != 0 ) && ( V_265 != 1 ) ) {
F_25 ( L_210
L_211 , V_265 ) ;
return - V_21 ;
}
V_262 -> V_277 = ( int ) V_265 ;
return V_75 ;
}
static T_1 F_139 (
struct V_261 * V_262 ,
char * V_7 )
{
return F_140 ( V_262 , V_7 ) ;
}
static T_1 F_141 (
struct V_261 * V_262 ,
const char * V_7 ,
T_2 V_75 )
{
return F_142 ( V_262 , V_7 , V_75 ) ;
}
static T_1 F_143 (
struct V_261 * V_262 ,
char * V_7 )
{
return F_144 ( V_262 , V_7 ) ;
}
static T_1 F_145 (
struct V_261 * V_262 ,
const char * V_7 ,
T_2 V_75 )
{
return F_146 ( V_262 , V_7 , V_75 ) ;
}
static T_1 F_147 (
struct V_261 * V_262 ,
char * V_7 )
{
return F_148 ( V_262 , V_7 ) ;
}
static T_1 F_149 (
struct V_261 * V_262 ,
const char * V_7 ,
T_2 V_75 )
{
return F_150 ( V_262 , V_7 , V_75 ) ;
}
static T_1 F_151 (
struct V_261 * V_262 ,
char * V_7 )
{
return F_152 ( V_262 , V_7 ) ;
}
static T_1 F_153 (
struct V_261 * V_262 ,
const char * V_7 ,
T_2 V_75 )
{
return F_154 ( V_262 , V_7 , V_75 ) ;
}
static T_1 F_155 (
struct V_261 * V_262 ,
char * V_7 )
{
if ( ! V_262 -> V_267 )
return 0 ;
return sprintf ( V_7 , L_181 , V_262 -> V_278 ) ;
}
static T_1 F_156 (
struct V_261 * V_262 ,
const char * V_7 ,
T_2 V_75 )
{
struct V_18 * V_279 = & V_262 -> V_280 ;
unsigned long V_278 ;
int V_20 ;
V_20 = F_119 ( V_7 , 0 , & V_278 ) ;
if ( V_20 < 0 ) {
F_25 ( L_182
L_212 , V_20 ) ;
return V_20 ;
}
if ( V_278 > 0x0000ffff ) {
F_25 ( L_213
L_185 , V_278 ) ;
return - V_21 ;
}
V_20 = F_157 ( V_262 , ( T_6 ) V_278 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_214
L_215 ,
F_17 ( & V_279 -> V_28 ) ,
V_262 -> V_278 ) ;
return V_75 ;
}
static T_1 F_158 (
struct V_261 * V_262 ,
char * V_7 )
{
struct V_281 * V_282 ;
T_1 V_121 = 0 , V_256 ;
unsigned char V_112 [ V_283 ] ;
memset ( V_112 , 0 , V_283 ) ;
F_60 ( & V_262 -> V_284 ) ;
F_8 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
struct V_145 * V_285 = V_282 -> V_286 ;
V_256 = snprintf ( V_112 , V_283 , L_216
L_217 , V_285 -> V_134 -> V_36 () ,
V_285 -> V_134 -> V_37 ( V_285 ) ,
V_285 -> V_134 -> V_38 ( V_285 ) ,
F_17 ( & V_282 -> V_287 . V_28 ) ) ;
V_256 ++ ;
if ( ( V_256 + V_121 ) > V_124 ) {
F_39 ( L_189
L_190 ) ;
break;
}
memcpy ( V_7 + V_121 , V_112 , V_256 ) ;
V_121 += V_256 ;
}
F_62 ( & V_262 -> V_284 ) ;
return V_121 ;
}
static void F_159 ( struct V_2 * V_3 )
{
struct V_261 * V_262 = F_2 ( F_3 ( V_3 ) ,
struct V_261 , V_280 ) ;
F_160 ( V_262 ) ;
}
static struct V_18 * F_161 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_223 * V_288 = F_2 ( V_19 , struct V_223 ,
V_289 ) ;
struct V_261 * V_262 ;
struct V_18 * V_279 = NULL ;
struct V_2 * V_290 = NULL ;
V_262 = F_162 ( V_288 -> V_111 , V_13 , 0 ) ;
if ( ! V_262 )
return NULL ;
V_279 = & V_262 -> V_280 ;
V_290 = & V_279 -> V_28 ;
F_15 ( V_279 , V_13 ,
& V_291 ) ;
F_12 ( L_218
L_219 ,
F_17 ( V_290 ) ) ;
return V_279 ;
}
static void F_163 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_261 * V_262 = F_2 ( F_3 ( V_3 ) ,
struct V_261 , V_280 ) ;
F_12 ( L_220
L_221 ,
F_17 ( V_3 ) , V_262 -> V_278 ) ;
F_19 ( V_3 ) ;
}
static struct V_18 * F_164 (
struct V_18 * V_19 ,
const char * V_13 )
{
return F_14 ( - V_88 ) ;
}
static void F_165 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
return;
}
static struct V_18 * F_166 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_261 * V_262 ;
struct V_2 * V_292 = & V_19 -> V_28 ;
struct V_1 * V_200 = F_1 ( V_292 ) ;
struct V_293 * V_294 = V_200 -> V_295 ;
struct V_67 * V_68 ;
struct V_18 * V_249 = NULL , * V_296 = NULL ;
struct V_18 * V_297 = NULL ;
int V_298 = - V_63 , V_20 ;
V_20 = F_167 ( & V_200 -> V_299 ) ;
if ( V_20 )
return F_14 ( V_20 ) ;
V_68 = F_168 ( V_200 , V_13 ) ;
if ( ! V_68 )
goto V_146;
V_249 = & V_68 -> V_70 ;
V_249 -> V_24 = F_169 ( sizeof( struct V_18 * ) * 6 ,
V_61 ) ;
if ( ! V_249 -> V_24 )
goto V_300;
F_15 ( V_249 , V_13 , & V_294 -> V_301 ) ;
F_15 ( & V_68 -> V_103 . V_302 , L_222 ,
& V_294 -> V_303 ) ;
F_15 ( & V_68 -> V_304 , L_223 ,
& V_294 -> V_305 ) ;
F_15 ( & V_68 -> V_71 . V_306 , L_224 ,
& V_294 -> V_307 ) ;
F_15 ( & V_68 -> V_223 . V_289 ,
L_225 , & V_294 -> V_308 ) ;
F_15 ( & V_68 -> V_309 . V_310 ,
L_226 , & V_294 -> V_311 ) ;
V_249 -> V_24 [ 0 ] = & V_68 -> V_103 . V_302 ;
V_249 -> V_24 [ 1 ] = & V_68 -> V_304 ;
V_249 -> V_24 [ 2 ] = & V_68 -> V_71 . V_306 ;
V_249 -> V_24 [ 3 ] = & V_68 -> V_223 . V_289 ;
V_249 -> V_24 [ 4 ] = & V_68 -> V_309 . V_310 ;
V_249 -> V_24 [ 5 ] = NULL ;
V_262 = F_162 ( V_68 , L_227 , 1 ) ;
if ( ! V_262 )
goto V_312;
V_68 -> V_223 . V_313 = V_262 ;
V_296 = & V_68 -> V_223 . V_289 ;
V_296 -> V_24 = F_169 ( sizeof( struct V_18 * ) * 2 ,
V_61 ) ;
if ( ! V_296 -> V_24 ) {
F_25 ( L_228
L_229 ) ;
goto V_314;
}
F_15 ( & V_262 -> V_280 ,
L_227 , & V_291 ) ;
V_296 -> V_24 [ 0 ] = & V_262 -> V_280 ;
V_296 -> V_24 [ 1 ] = NULL ;
V_297 = & V_68 -> V_309 . V_310 ;
V_297 -> V_24 = F_169 ( sizeof( struct V_18 * ) * 4 ,
V_61 ) ;
if ( ! V_297 -> V_24 ) {
F_25 ( L_230 ) ;
goto V_315;
}
F_170 ( V_68 ) ;
F_10 ( & V_200 -> V_299 ) ;
return V_249 ;
V_315:
F_37 ( V_296 -> V_24 ) ;
V_314:
F_160 ( V_262 ) ;
V_312:
F_37 ( V_249 -> V_24 ) ;
V_300:
F_114 ( V_68 ) ;
V_146:
F_10 ( & V_200 -> V_299 ) ;
return F_14 ( V_298 ) ;
}
static void F_171 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_18 * V_249 = F_3 ( V_3 ) ;
struct V_67 * V_68 =
F_2 ( V_249 , struct V_67 , V_70 ) ;
struct V_1 * V_200 ;
struct V_2 * V_30 ;
struct V_18 * V_296 , * V_297 ;
int V_31 ;
V_200 = F_1 ( & V_68 -> V_1 -> V_4 . V_28 ) ;
F_7 ( & V_200 -> V_299 ) ;
V_297 = & V_68 -> V_309 . V_310 ;
for ( V_31 = 0 ; V_297 -> V_24 [ V_31 ] ; V_31 ++ ) {
V_30 = & V_297 -> V_24 [ V_31 ] -> V_28 ;
V_297 -> V_24 [ V_31 ] = NULL ;
F_19 ( V_30 ) ;
}
F_37 ( V_297 -> V_24 ) ;
V_296 = & V_68 -> V_223 . V_289 ;
for ( V_31 = 0 ; V_296 -> V_24 [ V_31 ] ; V_31 ++ ) {
V_30 = & V_296 -> V_24 [ V_31 ] -> V_28 ;
V_296 -> V_24 [ V_31 ] = NULL ;
F_19 ( V_30 ) ;
}
F_37 ( V_296 -> V_24 ) ;
V_68 -> V_223 . V_313 = NULL ;
for ( V_31 = 0 ; V_249 -> V_24 [ V_31 ] ; V_31 ++ ) {
V_30 = & V_249 -> V_24 [ V_31 ] -> V_28 ;
V_249 -> V_24 [ V_31 ] = NULL ;
F_19 ( V_30 ) ;
}
F_19 ( V_3 ) ;
F_10 ( & V_200 -> V_299 ) ;
}
static T_1 F_172 (
struct V_1 * V_200 ,
char * V_7 )
{
return sprintf ( V_7 , L_231 ,
V_200 -> V_316 , V_200 -> V_295 -> V_317 -> V_13 ,
V_9 ) ;
}
static T_1 F_173 ( struct V_1 * V_200 ,
char * V_7 )
{
int V_318 = 0 ;
if ( V_200 -> V_319 & V_320 )
V_318 = 1 ;
return sprintf ( V_7 , L_154 , V_318 ) ;
}
static T_1 F_174 ( struct V_1 * V_200 ,
const char * V_7 , T_2 V_75 )
{
unsigned long V_321 ;
int V_20 ;
if ( V_200 -> V_295 -> V_317 -> V_322 == NULL )
return - V_21 ;
V_20 = F_119 ( V_7 , 0 , & V_321 ) ;
if ( V_20 < 0 ) {
F_25 ( L_232 , V_20 ) ;
return V_20 ;
}
if ( V_200 -> V_323 ) {
F_25 ( L_233 ) ;
return - V_21 ;
}
V_20 = V_200 -> V_295 -> V_317 -> V_322 ( V_200 , V_321 ) ;
if ( V_20 < 0 )
return - V_21 ;
if ( V_20 > 0 )
V_200 -> V_319 |= V_320 ;
else if ( V_20 == 0 )
V_200 -> V_319 &= ~ V_320 ;
return V_75 ;
}
static void F_175 ( struct V_2 * V_3 )
{
struct V_1 * V_200 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_176 ( V_200 ) ;
}
static struct V_18 * F_177 (
struct V_18 * V_19 ,
const char * V_13 )
{
char * V_324 , * V_325 , * V_326 ;
struct V_1 * V_200 ;
char V_112 [ V_327 ] ;
unsigned long V_328 = 0 ;
int V_20 ;
memset ( V_112 , 0 , V_327 ) ;
if ( strlen ( V_13 ) >= V_327 ) {
F_25 ( L_234
L_235 , ( int ) strlen ( V_13 ) ,
V_327 ) ;
return F_14 ( - V_329 ) ;
}
snprintf ( V_112 , V_327 , L_53 , V_13 ) ;
V_325 = strstr ( V_112 , L_236 ) ;
if ( ! V_325 ) {
F_25 ( L_237 ) ;
return F_14 ( - V_21 ) ;
}
V_324 = V_112 ;
V_326 = strstr ( V_325 + 1 , L_236 ) ;
if ( V_326 ) {
* V_326 = '\0' ;
V_326 ++ ;
V_325 = V_326 ;
} else {
* V_325 = '\0' ;
V_325 ++ ;
}
V_20 = F_119 ( V_325 , 0 , & V_328 ) ;
if ( V_20 < 0 ) {
F_25 ( L_182
L_238 , V_20 ) ;
return F_14 ( V_20 ) ;
}
F_178 () ;
V_200 = F_179 ( V_324 , V_328 , 0 ) ;
if ( F_108 ( V_200 ) )
return F_180 ( V_200 ) ;
F_15 ( & V_200 -> V_4 , V_13 ,
& V_330 ) ;
return & V_200 -> V_4 ;
}
static void F_181 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
F_19 ( V_3 ) ;
}
void F_182 ( struct V_293 * V_294 )
{
F_183 ( V_294 ) ;
F_184 ( V_294 ) ;
F_185 ( V_294 ) ;
F_186 ( V_294 ) ;
F_187 ( V_294 ) ;
F_188 ( V_294 ) ;
}
static int T_8 F_189 ( void )
{
struct V_18 * V_331 , * V_332 = NULL , * V_333 = NULL ;
struct V_18 * V_334 = NULL ;
struct V_335 * V_336 = & V_32 ;
struct V_206 * V_207 ;
int V_20 ;
F_12 ( L_239
L_240 V_8 L_3 ,
V_9 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
F_190 ( & V_336 -> V_337 ) ;
F_191 ( & V_336 -> V_338 ) ;
V_20 = F_192 () ;
if ( V_20 < 0 )
return V_20 ;
V_331 = & V_336 -> V_337 ;
V_331 -> V_24 = F_169 ( sizeof( struct V_18 * ) * 2 ,
V_61 ) ;
if ( ! V_331 -> V_24 ) {
F_25 ( L_241 ) ;
V_20 = - V_63 ;
goto V_339;
}
F_15 ( & V_340 ,
L_242 , & V_341 ) ;
V_331 -> V_24 [ 0 ] = & V_340 ;
V_331 -> V_24 [ 1 ] = NULL ;
V_332 = & V_340 ;
V_332 -> V_24 = F_169 ( sizeof( struct V_18 * ) * 2 ,
V_61 ) ;
if ( ! V_332 -> V_24 ) {
F_25 ( L_243 ) ;
V_20 = - V_63 ;
goto V_339;
}
F_15 ( & V_342 ,
L_225 , & V_343 ) ;
V_332 -> V_24 [ 0 ] = & V_342 ;
V_332 -> V_24 [ 1 ] = NULL ;
V_333 = & V_342 ;
V_333 -> V_24 = F_169 ( sizeof( struct V_18 * ) * 2 ,
V_61 ) ;
if ( ! V_333 -> V_24 ) {
F_25 ( L_244 ) ;
V_20 = - V_63 ;
goto V_339;
}
F_15 ( & V_344 ,
L_245 , & V_345 ) ;
V_333 -> V_24 [ 0 ] = & V_344 ;
V_333 -> V_24 [ 1 ] = NULL ;
V_207 = F_125 ( L_246 , 1 ) ;
if ( F_108 ( V_207 ) ) {
V_20 = - V_63 ;
goto V_339;
}
V_334 = & V_344 ;
V_334 -> V_24 = F_169 ( sizeof( struct V_18 * ) * 2 ,
V_61 ) ;
if ( ! V_334 -> V_24 ) {
F_25 ( L_247 ) ;
V_20 = - V_63 ;
goto V_339;
}
F_15 ( & V_207 -> V_212 , L_246 ,
& V_260 ) ;
V_334 -> V_24 [ 0 ] = & V_207 -> V_212 ;
V_334 -> V_24 [ 1 ] = NULL ;
V_346 = V_207 ;
V_20 = F_193 ( V_336 ) ;
if ( V_20 < 0 ) {
F_25 ( L_248 ,
V_20 , V_336 -> V_337 . V_28 . V_347 ) ;
goto V_339;
}
F_12 ( L_249
L_250 V_9 L_251
L_252 V_8 L_3 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_20 = F_194 () ;
if ( V_20 < 0 )
goto V_175;
V_20 = F_195 () ;
if ( V_20 < 0 )
goto V_175;
V_20 = F_196 () ;
if ( V_20 < 0 )
goto V_175;
return 0 ;
V_175:
F_197 ( V_336 ) ;
F_198 () ;
F_199 () ;
V_339:
if ( V_346 ) {
F_123 ( V_346 ) ;
V_346 = NULL ;
}
if ( V_334 )
F_37 ( V_334 -> V_24 ) ;
if ( V_333 )
F_37 ( V_333 -> V_24 ) ;
if ( V_332 )
F_37 ( V_332 -> V_24 ) ;
F_37 ( V_331 -> V_24 ) ;
F_200 () ;
return V_20 ;
}
static void T_9 F_201 ( void )
{
struct V_18 * V_332 , * V_333 , * V_334 ;
struct V_2 * V_3 ;
int V_31 ;
V_334 = & V_344 ;
for ( V_31 = 0 ; V_334 -> V_24 [ V_31 ] ; V_31 ++ ) {
V_3 = & V_334 -> V_24 [ V_31 ] -> V_28 ;
V_334 -> V_24 [ V_31 ] = NULL ;
F_19 ( V_3 ) ;
}
F_37 ( V_334 -> V_24 ) ;
V_334 -> V_24 = NULL ;
V_333 = & V_342 ;
for ( V_31 = 0 ; V_333 -> V_24 [ V_31 ] ; V_31 ++ ) {
V_3 = & V_333 -> V_24 [ V_31 ] -> V_28 ;
V_333 -> V_24 [ V_31 ] = NULL ;
F_19 ( V_3 ) ;
}
F_37 ( V_333 -> V_24 ) ;
V_333 -> V_24 = NULL ;
V_332 = & V_340 ;
for ( V_31 = 0 ; V_332 -> V_24 [ V_31 ] ; V_31 ++ ) {
V_3 = & V_332 -> V_24 [ V_31 ] -> V_28 ;
V_332 -> V_24 [ V_31 ] = NULL ;
F_19 ( V_3 ) ;
}
F_37 ( V_332 -> V_24 ) ;
V_332 -> V_24 = NULL ;
F_197 ( & V_32 ) ;
F_37 ( V_32 . V_337 . V_24 ) ;
F_123 ( V_346 ) ;
V_346 = NULL ;
F_12 ( L_253
L_254 ) ;
F_198 () ;
F_199 () ;
F_202 () ;
F_200 () ;
}
