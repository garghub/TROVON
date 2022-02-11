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
V_12 -> V_21 . V_22 = V_12 -> V_23 ;
V_12 -> V_21 . V_22 [ 0 ] = & V_12 -> V_24 ;
V_12 -> V_21 . V_22 [ 1 ] = NULL ;
F_15 ( & V_12 -> V_21 , V_11 , & V_12 -> V_20 ) ;
F_15 ( & V_12 -> V_24 , L_17 ,
& V_12 -> V_25 ) ;
F_12 ( L_18
L_5 , V_12 -> V_21 . V_26 . V_27 ) ;
return & V_12 -> V_21 ;
}
static void F_16 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_10 * V_12 = F_2 (
F_3 ( V_3 ) , struct V_10 , V_21 ) ;
struct V_16 * V_21 ;
struct V_2 * V_28 ;
int V_29 ;
F_12 ( L_19
L_20 , F_17 ( V_3 ) ) ;
F_12 ( L_21
L_5 , V_12 -> V_14 -> V_11 ) ;
F_18 ( & V_12 -> V_15 ) ;
F_12 ( L_22
L_5 , F_17 ( V_3 ) ) ;
V_21 = & V_12 -> V_21 ;
for ( V_29 = 0 ; V_21 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_28 = & V_21 -> V_22 [ V_29 ] -> V_26 ;
V_21 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_28 ) ;
}
F_19 ( V_3 ) ;
}
int F_20 ( struct V_2 * V_3 )
{
return F_21 ( & V_30 , V_3 ) ;
}
void F_22 ( struct V_2 * V_3 )
{
return F_23 ( & V_30 , V_3 ) ;
}
static int F_24 ( const struct V_31 * V_32 )
{
if ( ! V_32 -> V_11 ) {
F_25 ( L_23 ) ;
return - V_19 ;
}
if ( strlen ( V_32 -> V_11 ) >= V_33 ) {
F_25 ( L_24
L_25 , V_32 -> V_11 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_34 ) {
F_25 ( L_26 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_35 ) {
F_25 ( L_27 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_36 ) {
F_25 ( L_28 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_37 ) {
F_25 ( L_29 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_38 ) {
F_25 ( L_30 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_39 ) {
F_25 ( L_31 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_40 ) {
F_25 ( L_32 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_41 ) {
F_25 ( L_33 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_42 ) {
F_25 ( L_34 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_43 ) {
F_25 ( L_35 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_44 ) {
F_25 ( L_36 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_45 ) {
F_25 ( L_37 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_46 ) {
F_25 ( L_38 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_47 ) {
F_25 ( L_39 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_48 ) {
F_25 ( L_40 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_49 ) {
F_25 ( L_41 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_50 ) {
F_25 ( L_42 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_51 ) {
F_25 ( L_43 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_52 ) {
F_25 ( L_44 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_53 ) {
F_25 ( L_45 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_54 ) {
F_25 ( L_46 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_55 ) {
F_25 ( L_47 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_56 ) {
F_25 ( L_48 ) ;
return - V_19 ;
}
if ( ! V_32 -> V_57 ) {
F_25 ( L_49 ) ;
return - V_19 ;
}
return 0 ;
}
int F_26 ( const struct V_31 * V_58 )
{
struct V_10 * V_12 ;
int V_18 ;
V_18 = F_24 ( V_58 ) ;
if ( V_18 )
return V_18 ;
V_12 = F_27 ( sizeof( struct V_10 ) , V_59 ) ;
if ( ! V_12 ) {
F_25 ( L_50 , V_60 ) ;
return - V_61 ;
}
F_28 ( & V_12 -> V_62 ) ;
F_29 ( & V_12 -> V_15 , 0 ) ;
V_12 -> V_14 = V_58 ;
F_30 ( V_12 ) ;
F_7 ( & V_13 ) ;
F_31 ( & V_12 -> V_62 , & V_63 ) ;
F_10 ( & V_13 ) ;
return 0 ;
}
void F_32 ( const struct V_31 * V_58 )
{
struct V_10 * V_64 ;
F_7 ( & V_13 ) ;
F_8 (t, &g_tf_list, tf_list) {
if ( ! strcmp ( V_64 -> V_14 -> V_11 , V_58 -> V_11 ) ) {
F_33 ( F_34 ( & V_64 -> V_15 ) ) ;
F_35 ( & V_64 -> V_62 ) ;
F_10 ( & V_13 ) ;
F_36 () ;
F_37 ( V_64 ) ;
return;
}
}
F_10 ( & V_13 ) ;
}
static inline struct V_65 * F_38 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_65 ,
V_66 ) ;
}
static void F_39 ( struct V_67 * V_68 )
{
const char * V_69 ;
V_69 = F_17 ( & V_68 -> V_70 . V_26 ) ;
if ( strlen ( V_69 ) >= 16 ) {
F_40 ( L_51
L_52 , V_68 ,
V_69 ) ;
}
snprintf ( & V_68 -> V_71 . V_72 [ 0 ] , 16 , L_53 , V_69 ) ;
}
static T_1 F_41 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
struct V_67 * V_68 = V_74 -> V_75 ;
bool V_76 ;
int V_18 ;
if ( V_68 -> V_77 ) {
F_25 ( L_54
L_55 ,
V_68 , V_68 -> V_77 ) ;
return - V_19 ;
}
V_18 = F_42 ( V_5 , & V_76 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_76 ) {
F_39 ( V_68 ) ;
} else {
strncpy ( & V_68 -> V_71 . V_72 [ 0 ] ,
V_68 -> V_78 -> V_79 , 16 ) ;
}
V_74 -> V_80 = V_76 ;
return V_73 ;
}
static T_1 F_43 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
bool V_76 ;
int V_18 ;
V_18 = F_42 ( V_5 , & V_76 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_76 && V_74 -> V_75 -> V_78 -> V_81 ) {
F_25 ( L_56 ) ;
return - V_19 ;
}
V_74 -> V_82 = V_76 ;
F_12 ( L_57 ,
V_74 -> V_75 , V_76 ) ;
return V_73 ;
}
static T_1 F_44 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
T_3 V_83 ;
int V_18 ;
V_18 = F_45 ( V_5 , 0 , & V_83 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_83 != 0 && V_83 != 1 && V_83 != 2 ) {
F_25 ( L_58 , V_83 ) ;
return - V_19 ;
}
if ( V_74 -> V_75 -> V_77 ) {
F_25 ( L_59
L_60 ,
V_74 -> V_75 , V_74 -> V_75 -> V_77 ) ;
return - V_19 ;
}
V_74 -> V_84 = V_83 ;
F_12 ( L_61 ,
V_74 -> V_75 , V_83 ) ;
return V_73 ;
}
static T_1 F_46 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
bool V_76 ;
int V_18 ;
V_18 = F_42 ( V_5 , & V_76 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_74 -> V_75 -> V_77 ) {
F_25 ( L_62
L_63 ,
V_74 -> V_75 , V_74 -> V_75 -> V_77 ) ;
return - V_19 ;
}
V_74 -> V_85 = V_76 ;
F_12 ( L_64 ,
V_74 -> V_75 , V_76 ? L_65 : L_66 ) ;
return V_73 ;
}
static T_1 F_47 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
bool V_76 ;
int V_18 ;
V_18 = F_42 ( V_5 , & V_76 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_76 && ! V_74 -> V_86 ) {
F_25 ( L_67 ) ;
return - V_87 ;
}
V_74 -> V_88 = V_76 ;
F_12 ( L_68 ,
V_74 -> V_75 , V_76 ) ;
return V_73 ;
}
static T_1 F_48 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
bool V_76 ;
int V_18 ;
V_18 = F_42 ( V_5 , & V_76 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_76 && ! V_74 -> V_86 ) {
F_25 ( L_67 ) ;
return - V_87 ;
}
V_74 -> V_89 = V_76 ;
F_12 ( L_69 ,
V_74 -> V_75 , V_76 ) ;
return V_73 ;
}
static T_1 F_49 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
int V_90 = V_74 -> V_91 , V_18 ;
struct V_67 * V_68 = V_74 -> V_75 ;
T_3 V_76 ;
V_18 = F_45 ( V_5 , 0 , & V_76 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_76 != 0 && V_76 != 1 && V_76 != 2 && V_76 != 3 ) {
F_25 ( L_70 , V_76 ) ;
return - V_19 ;
}
if ( V_76 == 2 ) {
F_25 ( L_71 ) ;
return - V_87 ;
}
if ( V_74 -> V_92 ) {
F_40 ( L_72
L_73 ) ;
return V_73 ;
}
if ( ! V_68 -> V_78 -> V_93 || ! V_68 -> V_78 -> V_94 ) {
if ( V_76 == 0 )
return V_73 ;
F_25 ( L_74 ,
V_68 -> V_78 -> V_11 ) ;
return - V_87 ;
}
if ( ! ( V_68 -> V_95 & V_96 ) ) {
F_25 ( L_75 ) ;
return - V_97 ;
}
if ( V_68 -> V_77 ) {
F_25 ( L_76
L_63 , V_68 , V_68 -> V_77 ) ;
return - V_19 ;
}
V_74 -> V_91 = V_76 ;
if ( V_76 && ! V_90 ) {
V_18 = V_68 -> V_78 -> V_93 ( V_68 ) ;
if ( V_18 ) {
V_74 -> V_91 = V_90 ;
return V_18 ;
}
} else if ( ! V_76 && V_90 ) {
V_68 -> V_78 -> V_94 ( V_68 ) ;
}
F_12 ( L_77 , V_68 , V_76 ) ;
return V_73 ;
}
static T_1 F_50 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
struct V_67 * V_68 = V_74 -> V_75 ;
bool V_76 ;
int V_18 ;
V_18 = F_42 ( V_5 , & V_76 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( ! V_76 )
return V_73 ;
if ( ! V_68 -> V_78 -> V_98 ) {
F_25 ( L_78 ,
V_68 -> V_78 -> V_11 ) ;
return - V_87 ;
}
if ( ! ( V_68 -> V_95 & V_96 ) ) {
F_25 ( L_79 ) ;
return - V_97 ;
}
if ( V_68 -> V_77 ) {
F_25 ( L_80
L_63 , V_68 , V_68 -> V_77 ) ;
return - V_19 ;
}
V_18 = V_68 -> V_78 -> V_98 ( V_68 ) ;
if ( V_18 )
return V_18 ;
F_12 ( L_81 , V_68 ) ;
return V_73 ;
}
static T_1 F_51 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
bool V_76 ;
int V_18 ;
V_18 = F_42 ( V_5 , & V_76 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_74 -> V_75 -> V_77 ) {
F_25 ( L_82
L_63 ,
V_74 -> V_75 , V_74 -> V_75 -> V_77 ) ;
return - V_19 ;
}
V_74 -> V_99 = V_76 ;
F_12 ( L_83 , V_74 -> V_75 , V_76 ) ;
return V_73 ;
}
static T_1 F_52 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
bool V_76 ;
int V_18 ;
V_18 = F_42 ( V_5 , & V_76 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_76 != 0 ) {
F_53 ( V_100 L_84
L_85 , V_74 -> V_75 ) ;
return - V_87 ;
}
V_74 -> V_101 = V_76 ;
F_12 ( L_86 ,
V_74 -> V_75 , V_76 ) ;
return V_73 ;
}
static T_1 F_54 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
struct V_67 * V_68 = V_74 -> V_75 ;
T_3 V_83 ;
int V_18 ;
V_18 = F_45 ( V_5 , 0 , & V_83 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_68 -> V_77 ) {
F_25 ( L_87
L_63 ,
V_68 , V_68 -> V_77 ) ;
return - V_19 ;
}
if ( ! V_83 ) {
F_25 ( L_88 , V_68 ) ;
return - V_19 ;
}
if ( V_83 > V_68 -> V_102 . V_103 ) {
if ( V_83 > V_68 -> V_102 . V_104 ) {
F_25 ( L_89
L_90
L_91 , V_68 , V_83 ,
V_68 -> V_102 . V_104 ) ;
return - V_19 ;
}
}
V_74 -> V_103 = V_68 -> V_103 = V_83 ;
F_12 ( L_92 , V_68 , V_83 ) ;
return V_73 ;
}
static T_1 F_55 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
T_3 V_83 ;
int V_18 ;
V_18 = F_45 ( V_5 , 0 , & V_83 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_74 -> V_75 -> V_77 ) {
F_25 ( L_59
L_93 ,
V_74 -> V_75 , V_74 -> V_75 -> V_77 ) ;
return - V_19 ;
}
if ( V_83 > V_74 -> V_105 ) {
F_25 ( L_94
L_95 ,
V_74 -> V_75 , V_83 , V_74 -> V_105 ) ;
return - V_19 ;
}
V_74 -> V_106 = V_83 ;
F_12 ( L_96 ,
V_74 -> V_75 , V_83 ) ;
return V_73 ;
}
static T_1 F_56 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
T_3 V_83 ;
int V_18 ;
V_18 = F_45 ( V_5 , 0 , & V_83 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_74 -> V_75 -> V_77 ) {
F_25 ( L_97
L_55 ,
V_74 -> V_75 , V_74 -> V_75 -> V_77 ) ;
return - V_19 ;
}
if ( V_83 != 512 && V_83 != 1024 && V_83 != 2048 && V_83 != 4096 ) {
F_25 ( L_98
L_99 ,
V_74 -> V_75 , V_83 ) ;
return - V_19 ;
}
V_74 -> V_107 = V_83 ;
if ( V_74 -> V_108 )
V_74 -> V_105 = V_74 -> V_108 / V_83 ;
F_12 ( L_100 ,
V_74 -> V_75 , V_83 ) ;
return V_73 ;
}
static struct V_71 * F_57 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_71 , V_109 ) ;
}
static T_1 F_58 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_101 ,
& F_57 ( V_3 ) -> V_110 [ 0 ] ) ;
}
static T_1 F_59 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_71 * V_71 = F_57 ( V_3 ) ;
struct V_67 * V_68 = V_71 -> V_111 ;
unsigned char V_112 [ V_113 ] ;
if ( V_68 -> V_95 & V_114 ) {
F_25 ( L_102
L_103 ) ;
return - V_115 ;
}
if ( strlen ( V_5 ) >= V_113 ) {
F_25 ( L_104
L_105 , V_113 ) ;
return - V_116 ;
}
if ( V_68 -> V_77 ) {
F_25 ( L_106
L_107 ,
V_68 -> V_77 ) ;
return - V_19 ;
}
memset ( V_112 , 0 , V_113 ) ;
snprintf ( V_112 , V_113 , L_53 , V_5 ) ;
snprintf ( V_68 -> V_71 . V_110 , V_113 ,
L_53 , F_60 ( V_112 ) ) ;
V_68 -> V_95 |= V_117 ;
F_12 ( L_108
L_5 , V_68 -> V_71 . V_110 ) ;
return V_73 ;
}
static T_1 F_61 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_71 = F_57 ( V_3 ) ;
struct V_118 * V_119 ;
unsigned char V_112 [ V_120 ] ;
T_1 V_121 = 0 ;
memset ( V_112 , 0 , V_120 ) ;
F_62 ( & V_71 -> V_122 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_119 -> V_123 )
continue;
F_63 ( V_119 , V_112 , V_120 ) ;
if ( V_121 + strlen ( V_112 ) >= V_124 )
break;
V_121 += sprintf ( V_5 + V_121 , L_53 , V_112 ) ;
}
F_64 ( & V_71 -> V_122 ) ;
return V_121 ;
}
static struct V_67 * F_65 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_67 ,
V_125 ) ;
}
static T_1 F_66 ( struct V_67 * V_68 ,
char * V_5 )
{
struct V_126 * V_127 ;
struct V_128 * V_129 ;
char V_130 [ V_131 ] ;
memset ( V_130 , 0 , V_131 ) ;
V_129 = V_68 -> V_132 ;
if ( ! V_129 )
return sprintf ( V_5 , L_109 ) ;
V_127 = V_129 -> V_133 ;
F_67 ( V_129 , V_130 , V_131 ) ;
return sprintf ( V_5 , L_110 ,
V_127 -> V_134 -> V_135 -> V_34 () ,
V_127 -> V_136 , V_130 ) ;
}
static T_1 F_68 ( struct V_67 * V_68 ,
char * V_5 )
{
struct V_126 * V_127 ;
T_1 V_121 ;
V_127 = V_68 -> V_137 ;
if ( V_127 ) {
V_121 = sprintf ( V_5 ,
L_111 ,
V_127 -> V_134 -> V_135 -> V_34 () ,
V_127 -> V_136 ) ;
} else {
V_121 = sprintf ( V_5 , L_112 ) ;
}
return V_121 ;
}
static T_1 F_69 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_65 ( V_3 ) ;
int V_18 ;
if ( V_68 -> V_78 -> V_138 & V_139 )
return sprintf ( V_5 , L_113 ) ;
F_62 ( & V_68 -> V_140 ) ;
if ( V_68 -> V_141 & V_142 )
V_18 = F_68 ( V_68 , V_5 ) ;
else
V_18 = F_66 ( V_68 , V_5 ) ;
F_64 ( & V_68 -> V_140 ) ;
return V_18 ;
}
static T_1 F_70 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_67 * V_68 = F_65 ( V_3 ) ;
T_1 V_121 = 0 ;
F_62 ( & V_68 -> V_140 ) ;
if ( ! V_68 -> V_132 ) {
V_121 = sprintf ( V_5 , L_109 ) ;
} else if ( V_68 -> V_132 -> V_143 ) {
V_121 = sprintf ( V_5 , L_114
L_115 ) ;
} else {
V_121 = sprintf ( V_5 , L_116
L_117 ) ;
}
F_64 ( & V_68 -> V_140 ) ;
return V_121 ;
}
static T_1 F_71 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_118 , F_65 ( V_3 ) -> V_144 . V_145 ) ;
}
static T_1 F_72 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_67 * V_68 = F_65 ( V_3 ) ;
struct V_126 * V_127 ;
struct V_146 * V_134 ;
struct V_128 * V_129 ;
const struct V_31 * V_32 ;
T_1 V_121 = 0 ;
F_62 ( & V_68 -> V_140 ) ;
V_129 = V_68 -> V_132 ;
if ( ! V_129 ) {
V_121 = sprintf ( V_5 , L_109 ) ;
goto V_147;
}
V_127 = V_129 -> V_133 ;
V_134 = V_127 -> V_134 ;
V_32 = V_134 -> V_135 ;
V_121 += sprintf ( V_5 + V_121 , L_119
L_120 , V_32 -> V_34 () ,
V_32 -> V_35 ( V_134 ) ) ;
V_121 += sprintf ( V_5 + V_121 , L_121
L_122
L_123 , V_129 -> V_148 ,
V_32 -> V_34 () , V_32 -> V_36 ( V_134 ) ,
V_32 -> V_34 () , V_129 -> V_149 ) ;
V_147:
F_64 ( & V_68 -> V_140 ) ;
return V_121 ;
}
static T_1 F_73 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_67 * V_68 = F_65 ( V_3 ) ;
const struct V_31 * V_32 ;
struct V_128 * V_129 ;
unsigned char V_112 [ 384 ] ;
char V_130 [ V_131 ] ;
T_1 V_121 = 0 ;
int V_150 = 0 ;
V_121 += sprintf ( V_5 + V_121 , L_124 ) ;
F_62 ( & V_68 -> V_144 . V_151 ) ;
F_8 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_112 , 0 , 384 ) ;
memset ( V_130 , 0 , V_131 ) ;
V_32 = V_129 -> V_133 -> V_134 -> V_135 ;
F_67 ( V_129 , V_130 ,
V_131 ) ;
sprintf ( V_112 , L_125 ,
V_32 -> V_34 () ,
V_129 -> V_133 -> V_136 , V_130 , V_129 -> V_152 ,
V_129 -> V_153 ) ;
if ( V_121 + strlen ( V_112 ) >= V_124 )
break;
V_121 += sprintf ( V_5 + V_121 , L_53 , V_112 ) ;
V_150 ++ ;
}
F_64 ( & V_68 -> V_144 . V_151 ) ;
if ( ! V_150 )
V_121 += sprintf ( V_5 + V_121 , L_126 ) ;
return V_121 ;
}
static T_1 F_74 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_65 ( V_3 ) ;
struct V_128 * V_129 ;
T_1 V_121 = 0 ;
F_62 ( & V_68 -> V_140 ) ;
V_129 = V_68 -> V_132 ;
if ( V_129 ) {
V_121 = sprintf ( V_5 , L_127 ,
F_75 ( V_129 -> V_154 ) ) ;
} else {
V_121 = sprintf ( V_5 , L_109 ) ;
}
F_64 ( & V_68 -> V_140 ) ;
return V_121 ;
}
static T_1 F_76 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_65 ( V_3 ) ;
if ( V_68 -> V_78 -> V_138 & V_139 )
return sprintf ( V_5 , L_128 ) ;
else if ( V_68 -> V_141 & V_142 )
return sprintf ( V_5 , L_129 ) ;
else
return sprintf ( V_5 , L_130 ) ;
}
static T_1 F_77 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_67 * V_68 = F_65 ( V_3 ) ;
if ( V_68 -> V_78 -> V_138 & V_139 )
return 0 ;
return sprintf ( V_5 , L_131 ,
( V_68 -> V_144 . V_155 ) ? L_132 : L_66 ) ;
}
static T_1 F_78 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_67 * V_68 = F_65 ( V_3 ) ;
if ( V_68 -> V_78 -> V_138 & V_139 )
return 0 ;
return sprintf ( V_5 , L_133 ) ;
}
static T_1 F_79 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_65 ( V_3 ) ;
unsigned char * V_156 = NULL , * V_157 = NULL , * V_158 = NULL ;
unsigned char * V_159 = NULL , * V_160 = NULL ;
char * V_161 , * V_162 , * V_163 ;
T_4 args [ V_164 ] ;
unsigned long long V_165 ;
T_5 V_166 = 0 ;
T_5 V_167 = 0 , V_168 = 0 ;
int V_18 = - 1 , V_169 = 0 , V_170 = 0 , V_171 , V_172 ;
T_6 V_173 = 0 ;
T_7 type = 0 ;
if ( V_68 -> V_78 -> V_138 & V_139 )
return V_73 ;
if ( V_68 -> V_141 & V_142 )
return V_73 ;
if ( V_68 -> V_77 ) {
F_12 ( L_134
L_135 ) ;
return - V_19 ;
}
V_163 = F_80 ( V_5 , V_59 ) ;
if ( ! V_163 )
return - V_61 ;
V_161 = V_163 ;
while ( ( V_162 = F_81 ( & V_163 , L_136 ) ) != NULL ) {
if ( ! * V_162 )
continue;
V_172 = F_82 ( V_162 , V_174 , args ) ;
switch ( V_172 ) {
case V_175 :
V_156 = F_83 ( args ) ;
if ( ! V_156 ) {
V_18 = - V_61 ;
goto V_176;
}
break;
case V_177 :
V_157 = F_83 ( args ) ;
if ( ! V_157 ) {
V_18 = - V_61 ;
goto V_176;
}
if ( strlen ( V_157 ) >= V_178 ) {
F_25 ( L_137
L_138 ,
V_178 ) ;
V_18 = - V_19 ;
break;
}
break;
case V_179 :
V_158 = F_83 ( args ) ;
if ( ! V_158 ) {
V_18 = - V_61 ;
goto V_176;
}
if ( strlen ( V_158 ) >= V_180 ) {
F_25 ( L_139
L_140 ,
V_180 ) ;
V_18 = - V_19 ;
break;
}
break;
case V_181 :
V_18 = F_84 ( args -> V_182 , 0 , & V_165 ) ;
if ( V_18 < 0 ) {
F_25 ( L_141 ) ;
goto V_176;
}
V_166 = ( T_5 ) V_165 ;
break;
case V_183 :
V_18 = F_85 ( args , & V_171 ) ;
if ( V_18 )
goto V_176;
V_169 = V_171 ;
break;
case V_184 :
V_18 = F_85 ( args , & V_171 ) ;
if ( V_18 )
goto V_176;
type = ( T_7 ) V_171 ;
break;
case V_185 :
V_18 = F_85 ( args , & V_171 ) ;
if ( V_18 )
goto V_176;
break;
case V_186 :
V_18 = F_85 ( args , & V_171 ) ;
if ( V_18 )
goto V_176;
V_170 = ( int ) V_171 ;
break;
case V_187 :
V_18 = F_85 ( args , & V_171 ) ;
if ( V_18 )
goto V_176;
V_167 = ( T_5 ) V_171 ;
break;
case V_188 :
V_159 = F_83 ( args ) ;
if ( ! V_159 ) {
V_18 = - V_61 ;
goto V_176;
}
break;
case V_189 :
V_160 = F_83 ( args ) ;
if ( ! V_160 ) {
V_18 = - V_61 ;
goto V_176;
}
if ( strlen ( V_160 ) >= V_190 ) {
F_25 ( L_142
L_143 ,
V_190 ) ;
V_18 = - V_19 ;
break;
}
break;
case V_191 :
V_18 = F_85 ( args , & V_171 ) ;
if ( V_18 )
goto V_176;
V_173 = ( T_6 ) V_171 ;
break;
case V_192 :
V_18 = F_85 ( args , & V_171 ) ;
if ( V_18 )
goto V_176;
break;
case V_193 :
V_18 = F_85 ( args , & V_171 ) ;
if ( V_18 )
goto V_176;
V_168 = ( T_5 ) V_171 ;
break;
default:
break;
}
}
if ( ! V_157 || ! V_160 || ! V_166 ) {
F_25 ( L_144 ) ;
V_18 = - V_19 ;
goto V_176;
}
if ( V_169 && ! ( type ) ) {
F_25 ( L_145
L_146 , type ) ;
V_18 = - V_19 ;
goto V_176;
}
V_18 = F_86 ( & V_68 -> V_144 , V_166 ,
V_157 , V_158 , V_167 , V_160 , V_173 , V_168 ,
V_169 , V_170 , type ) ;
V_176:
F_37 ( V_156 ) ;
F_37 ( V_157 ) ;
F_37 ( V_158 ) ;
F_37 ( V_159 ) ;
F_37 ( V_160 ) ;
F_37 ( V_161 ) ;
return ( V_18 == 0 ) ? V_73 : V_18 ;
}
static inline struct V_67 * F_87 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_67 , V_70 ) ;
}
static T_1 F_88 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
int V_194 = 0 ;
T_1 V_195 = 0 ;
F_89 ( V_68 , V_5 , & V_194 ) ;
V_195 += V_194 ;
V_195 += V_68 -> V_78 -> V_196 ( V_68 ,
V_5 + V_195 ) ;
return V_195 ;
}
static T_1 F_90 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
return V_68 -> V_78 -> V_197 ( V_68 , V_5 , V_73 ) ;
}
static T_1 F_91 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
if ( ! ( V_68 -> V_95 & V_198 ) )
return 0 ;
return snprintf ( V_5 , V_124 , L_147 , V_68 -> V_199 ) ;
}
static T_1 F_92 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
struct V_1 * V_200 = V_68 -> V_1 ;
T_1 V_195 ;
if ( V_73 > ( V_201 - 1 ) ) {
F_25 ( L_148
L_149 , ( int ) V_73 ,
V_201 - 1 ) ;
return - V_19 ;
}
V_195 = snprintf ( & V_68 -> V_199 [ 0 ] , V_201 , L_53 , V_5 ) ;
if ( ! V_195 )
return - V_19 ;
if ( V_68 -> V_199 [ V_195 - 1 ] == '\n' )
V_68 -> V_199 [ V_195 - 1 ] = '\0' ;
V_68 -> V_95 |= V_198 ;
F_12 ( L_150 ,
F_17 ( & V_200 -> V_4 . V_26 ) ,
F_17 ( & V_68 -> V_70 . V_26 ) ,
V_68 -> V_199 ) ;
return V_195 ;
}
static T_1 F_93 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
if ( ! ( V_68 -> V_95 & V_202 ) )
return 0 ;
return snprintf ( V_5 , V_124 , L_147 , V_68 -> V_203 ) ;
}
static T_1 F_94 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
struct V_1 * V_200 = V_68 -> V_1 ;
T_1 V_195 ;
if ( V_73 > ( V_204 - 1 ) ) {
F_25 ( L_151
L_152 , ( int ) V_73 ,
V_204 - 1 ) ;
return - V_19 ;
}
V_195 = snprintf ( & V_68 -> V_203 [ 0 ] , V_204 ,
L_53 , V_5 ) ;
if ( ! V_195 )
return - V_19 ;
if ( V_68 -> V_203 [ V_195 - 1 ] == '\n' )
V_68 -> V_203 [ V_195 - 1 ] = '\0' ;
V_68 -> V_95 |= V_202 ;
F_12 ( L_153 ,
F_17 ( & V_200 -> V_4 . V_26 ) ,
F_17 ( & V_68 -> V_70 . V_26 ) ,
V_68 -> V_203 ) ;
return V_195 ;
}
static T_1 F_95 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
return snprintf ( V_5 , V_124 , L_154 , ! ! ( V_68 -> V_95 & V_96 ) ) ;
}
static T_1 F_96 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
char * V_162 ;
int V_18 ;
V_162 = strstr ( V_5 , L_155 ) ;
if ( ! V_162 ) {
F_25 ( L_156
L_157 ) ;
return - V_19 ;
}
V_18 = F_97 ( V_68 ) ;
if ( V_18 )
return V_18 ;
return V_73 ;
}
static T_1 F_98 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
struct V_2 * V_205 ;
struct V_206 * V_207 ;
struct V_208 * V_209 ;
T_1 V_121 = 0 ;
V_209 = V_68 -> V_210 ;
if ( ! V_209 )
return 0 ;
F_62 ( & V_209 -> V_211 ) ;
V_207 = V_209 -> V_207 ;
if ( V_207 ) {
V_205 = & V_207 -> V_212 . V_26 ;
V_121 += sprintf ( V_5 , L_158 ,
F_17 ( V_205 ) , V_207 -> V_213 ) ;
}
F_64 ( & V_209 -> V_211 ) ;
return V_121 ;
}
static T_1 F_99 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
struct V_1 * V_200 = V_68 -> V_1 ;
struct V_206 * V_207 = NULL , * V_214 = NULL ;
struct V_208 * V_209 ;
unsigned char V_112 [ V_215 ] ;
int V_216 = 0 ;
V_209 = V_68 -> V_210 ;
if ( ! V_209 )
return V_73 ;
if ( V_73 > V_215 ) {
F_25 ( L_159 ) ;
return - V_19 ;
}
memset ( V_112 , 0 , V_215 ) ;
memcpy ( V_112 , V_5 , V_73 ) ;
if ( strcmp ( F_60 ( V_112 ) , L_160 ) ) {
V_214 = F_100 ( F_60 ( V_112 ) ) ;
if ( ! V_214 )
return - V_97 ;
}
F_62 ( & V_209 -> V_211 ) ;
V_207 = V_209 -> V_207 ;
if ( V_207 ) {
if ( ! V_214 ) {
F_12 ( L_161
L_162
L_163 ,
F_17 ( & V_200 -> V_4 . V_26 ) ,
F_17 ( & V_68 -> V_70 . V_26 ) ,
F_17 ( & V_207 -> V_212 . V_26 ) ,
V_207 -> V_213 ) ;
F_101 ( V_209 , V_207 ) ;
F_64 ( & V_209 -> V_211 ) ;
return V_73 ;
}
F_101 ( V_209 , V_207 ) ;
V_216 = 1 ;
}
F_102 ( V_209 , V_214 ) ;
F_64 ( & V_209 -> V_211 ) ;
F_12 ( L_164
L_165 ,
( V_216 ) ? L_166 : L_167 ,
F_17 ( & V_200 -> V_4 . V_26 ) ,
F_17 ( & V_68 -> V_70 . V_26 ) ,
F_17 ( & V_214 -> V_212 . V_26 ) ,
V_214 -> V_213 ) ;
F_103 ( V_214 ) ;
return V_73 ;
}
static T_1 F_104 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
struct V_217 * V_218 ;
struct V_219 * V_220 ;
char * V_221 = V_5 ;
int V_194 = 0 ;
char V_222 ;
F_62 ( & V_68 -> V_223 . V_224 ) ;
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
F_64 ( & V_68 -> V_223 . V_224 ) ;
return V_194 ;
}
static T_1 F_106 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_87 ( V_3 ) ;
struct V_217 * V_236 = NULL ;
struct V_237 V_238 ;
char * V_239 , * V_162 ;
char V_222 ;
int V_240 = - 1 , V_241 ;
int V_18 = 0 , V_242 = 0 , V_243 , V_244 ;
unsigned long V_245 = - 1 , V_246 = - 1 ;
unsigned long V_247 = - 1 , V_248 = - 1 ;
V_239 = F_80 ( V_5 , V_59 ) ;
if ( ! V_239 )
return - V_61 ;
F_28 ( & V_238 ) ;
while ( ( V_162 = F_81 ( & V_239 , L_3 ) ) != NULL ) {
if ( ! * V_162 )
continue;
if ( V_242 == 0 ) {
if ( sscanf ( V_162 , L_171 ,
& V_247 , & V_248 ) != 2 ) {
F_25 ( L_172 , V_242 ) ;
V_18 = - V_19 ;
break;
}
V_242 ++ ;
continue;
}
if ( sscanf ( V_162 , L_173 , & V_245 , & V_246 ) != 2 ) {
F_25 ( L_172 , V_242 ) ;
V_18 = - V_19 ;
break;
}
V_162 = strchr ( V_162 , ' ' ) ;
if ( ! V_162 ) {
F_25 ( L_174 , V_242 ) ;
V_18 = - V_19 ;
break;
}
V_162 ++ ;
V_162 = strchr ( V_162 , ' ' ) ;
if ( ! V_162 ) {
F_25 ( L_175 ,
V_242 ) ;
V_18 = - V_19 ;
break;
}
V_162 ++ ;
V_236 = F_107 ( & V_238 ,
V_245 , V_246 ) ;
if ( F_108 ( V_236 ) ) {
V_18 = F_109 ( V_236 ) ;
break;
}
V_241 = 0 ;
while ( sscanf ( V_162 , L_176 , & V_243 , & V_222 ) == 2 ) {
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
V_18 = - V_19 ;
goto V_176;
}
V_18 = F_110 ( V_236 ,
V_243 , V_244 ) ;
if ( V_18 ) {
F_25 ( L_178
L_179 ,
V_243 , V_222 , V_242 ) ;
break;
}
V_241 ++ ;
V_162 = strchr ( V_162 , ' ' ) ;
if ( V_162 )
V_162 ++ ;
else
break;
}
if ( V_240 == - 1 )
V_240 = V_241 ;
else if ( V_241 != V_240 ) {
F_25 ( L_180
L_179 , V_241 , V_240 , V_242 ) ;
V_18 = - V_19 ;
break;
}
V_242 ++ ;
}
V_176:
if ( V_18 ) {
F_111 ( & V_238 ) ;
V_73 = V_18 ;
} else
F_112 ( V_68 , & V_238 ,
V_247 , V_248 ) ;
F_37 ( V_239 ) ;
return V_73 ;
}
static void F_113 ( struct V_2 * V_3 )
{
struct V_16 * V_249 = F_3 ( V_3 ) ;
struct V_67 * V_68 =
F_2 ( V_249 , struct V_67 , V_70 ) ;
F_37 ( V_249 -> V_22 ) ;
F_114 ( V_68 ) ;
}
static inline struct V_206 * F_115 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_206 ,
V_212 ) ;
}
static T_1 F_116 ( struct V_2 * V_3 , char * V_5 )
{
struct V_206 * V_207 = F_115 ( V_3 ) ;
if ( ! V_207 -> V_250 )
return 0 ;
return sprintf ( V_5 , L_181 , V_207 -> V_213 ) ;
}
static T_1 F_117 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_206 * V_207 = F_115 ( V_3 ) ;
struct V_16 * V_251 = & V_207 -> V_212 ;
unsigned long V_213 ;
int V_18 ;
V_18 = F_118 ( V_5 , 0 , & V_213 ) ;
if ( V_18 < 0 ) {
F_25 ( L_182
L_183 , V_18 ) ;
return V_18 ;
}
if ( V_213 > 0x0000ffff ) {
F_25 ( L_184
L_185 , V_213 ) ;
return - V_19 ;
}
V_18 = F_119 ( V_207 , ( T_6 ) V_213 ) ;
if ( V_18 < 0 )
return - V_19 ;
F_12 ( L_186
L_187 ,
F_17 ( & V_251 -> V_26 ) ,
V_207 -> V_213 ) ;
return V_73 ;
}
static T_1 F_120 ( struct V_2 * V_3 , char * V_5 )
{
struct V_206 * V_207 = F_115 ( V_3 ) ;
struct V_67 * V_68 ;
struct V_1 * V_200 ;
struct V_208 * V_209 ;
T_1 V_121 = 0 , V_252 ;
unsigned char V_112 [ V_215 ] ;
memset ( V_112 , 0 , V_215 ) ;
F_62 ( & V_207 -> V_253 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_68 = V_209 -> V_254 ;
V_200 = V_68 -> V_1 ;
V_252 = snprintf ( V_112 , V_215 , L_188 ,
F_17 ( & V_200 -> V_4 . V_26 ) ,
F_17 ( & V_68 -> V_70 . V_26 ) ) ;
V_252 ++ ;
if ( ( V_252 + V_121 ) > V_124 ) {
F_40 ( L_189
L_190 ) ;
break;
}
memcpy ( V_5 + V_121 , V_112 , V_252 ) ;
V_121 += V_252 ;
}
F_64 ( & V_207 -> V_253 ) ;
return V_121 ;
}
static void F_121 ( struct V_2 * V_3 )
{
struct V_206 * V_207 = F_2 ( F_3 ( V_3 ) ,
struct V_206 , V_212 ) ;
F_122 ( V_207 ) ;
}
static struct V_16 * F_123 (
struct V_16 * V_17 ,
const char * V_11 )
{
struct V_206 * V_207 ;
struct V_16 * V_251 = NULL ;
struct V_2 * V_255 = NULL ;
V_207 = F_124 ( V_11 , 0 ) ;
if ( F_108 ( V_207 ) )
return NULL ;
V_251 = & V_207 -> V_212 ;
V_255 = & V_251 -> V_26 ;
F_15 ( V_251 , V_11 ,
& V_256 ) ;
F_12 ( L_191
L_192 ,
F_17 ( V_255 ) ) ;
return V_251 ;
}
static void F_125 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_206 * V_207 = F_2 ( F_3 ( V_3 ) ,
struct V_206 , V_212 ) ;
F_12 ( L_193
L_194 ,
F_17 ( V_3 ) , V_207 -> V_213 ) ;
F_19 ( V_3 ) ;
}
static inline struct V_257 * F_126 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_257 ,
V_258 ) ;
}
static T_1 F_127 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_154 ,
F_34 ( & F_126 ( V_3 ) -> V_259 ) ) ;
}
static T_1 F_128 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_257 * V_260 = F_126 ( V_3 ) ;
struct V_67 * V_68 = V_260 -> V_261 ;
unsigned long V_262 ;
int V_263 , V_18 ;
if ( ! V_260 -> V_264 ) {
F_25 ( L_195
L_196 , V_260 -> V_264 ) ;
return - V_19 ;
}
if ( ! ( V_68 -> V_95 & V_96 ) ) {
F_25 ( L_197
L_198 ) ;
return - V_97 ;
}
V_18 = F_118 ( V_5 , 0 , & V_262 ) ;
if ( V_18 < 0 ) {
F_25 ( L_199
L_5 , V_5 ) ;
return V_18 ;
}
V_263 = ( int ) V_262 ;
if ( ! ( V_260 -> V_265 & V_266 ) ) {
F_25 ( L_200
L_201 ) ;
return - V_19 ;
}
if ( V_260 -> V_265 & V_267 &&
V_263 == V_268 ) {
F_25 ( L_202
L_203 ) ;
return - V_19 ;
}
V_18 = F_129 ( V_260 , V_68 ,
NULL , NULL , V_263 , 0 ) ;
return ( ! V_18 ) ? V_73 : - V_19 ;
}
static T_1 F_130 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_257 * V_260 = F_126 ( V_3 ) ;
return sprintf ( V_5 , L_147 ,
F_131 ( V_260 -> V_269 ) ) ;
}
static T_1 F_132 (
struct V_2 * V_3 , const char * V_5 , T_2 V_73 )
{
struct V_257 * V_260 = F_126 ( V_3 ) ;
unsigned long V_262 ;
int V_270 , V_18 ;
if ( ! V_260 -> V_264 ) {
F_25 ( L_204
L_205 ,
V_260 -> V_264 ) ;
return - V_19 ;
}
V_18 = F_118 ( V_5 , 0 , & V_262 ) ;
if ( V_18 < 0 ) {
F_25 ( L_206
L_207 , V_5 ) ;
return V_18 ;
}
V_270 = ( int ) V_262 ;
if ( ( V_270 != V_271 ) &&
( V_270 != V_272 ) &&
( V_270 != V_273 ) ) {
F_25 ( L_208 ,
V_270 ) ;
return - V_19 ;
}
V_260 -> V_269 = V_270 ;
return V_73 ;
}
static T_1 F_133 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_134 ( F_126 ( V_3 ) , V_5 ) ;
}
static T_1 F_135 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
return F_136 ( F_126 ( V_3 ) , V_5 , V_73 ) ;
}
static T_1 F_137 (
struct V_2 * V_3 , char * V_5 )
{
return sprintf ( V_5 , L_154 ,
F_126 ( V_3 ) -> V_274 ) ;
}
static T_1 F_138 (
struct V_2 * V_3 , const char * V_5 , T_2 V_73 )
{
struct V_257 * V_260 = F_126 ( V_3 ) ;
unsigned long V_262 ;
int V_18 ;
V_18 = F_118 ( V_5 , 0 , & V_262 ) ;
if ( V_18 < 0 ) {
F_25 ( L_209 ) ;
return V_18 ;
}
if ( ( V_262 != 0 ) && ( V_262 != 1 ) ) {
F_25 ( L_210
L_211 , V_262 ) ;
return - V_19 ;
}
V_260 -> V_274 = ( int ) V_262 ;
return V_73 ;
}
static T_1 F_139 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_140 ( F_126 ( V_3 ) , V_5 ) ;
}
static T_1 F_141 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
return F_142 ( F_126 ( V_3 ) , V_5 ,
V_73 ) ;
}
static T_1 F_143 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_144 ( F_126 ( V_3 ) , V_5 ) ;
}
static T_1 F_145 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
return F_146 ( F_126 ( V_3 ) , V_5 ,
V_73 ) ;
}
static T_1 F_147 (
struct V_2 * V_3 , char * V_5 )
{
return F_148 ( F_126 ( V_3 ) , V_5 ) ;
}
static T_1 F_149 (
struct V_2 * V_3 , const char * V_5 , T_2 V_73 )
{
return F_150 ( F_126 ( V_3 ) , V_5 ,
V_73 ) ;
}
static T_1 F_151 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_152 ( F_126 ( V_3 ) , V_5 ) ;
}
static T_1 F_153 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
return F_154 ( F_126 ( V_3 ) , V_5 , V_73 ) ;
}
static T_1 F_155 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_257 * V_260 = F_126 ( V_3 ) ;
if ( ! V_260 -> V_264 )
return 0 ;
return sprintf ( V_5 , L_181 , V_260 -> V_275 ) ;
}
static T_1 F_156 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_257 * V_260 = F_126 ( V_3 ) ;
struct V_16 * V_276 = & V_260 -> V_258 ;
unsigned long V_275 ;
int V_18 ;
V_18 = F_118 ( V_5 , 0 , & V_275 ) ;
if ( V_18 < 0 ) {
F_25 ( L_182
L_212 , V_18 ) ;
return V_18 ;
}
if ( V_275 > 0x0000ffff ) {
F_25 ( L_213
L_185 , V_275 ) ;
return - V_19 ;
}
V_18 = F_157 ( V_260 , ( T_6 ) V_275 ) ;
if ( V_18 < 0 )
return - V_19 ;
F_12 ( L_214
L_215 ,
F_17 ( & V_276 -> V_26 ) ,
V_260 -> V_275 ) ;
return V_73 ;
}
static T_1 F_158 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_257 * V_260 = F_126 ( V_3 ) ;
struct V_277 * V_278 ;
T_1 V_121 = 0 , V_252 ;
unsigned char V_112 [ V_279 ] ;
memset ( V_112 , 0 , V_279 ) ;
F_62 ( & V_260 -> V_280 ) ;
F_8 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
struct V_146 * V_281 = V_278 -> V_282 ;
V_252 = snprintf ( V_112 , V_279 , L_216
L_217 , V_281 -> V_135 -> V_34 () ,
V_281 -> V_135 -> V_35 ( V_281 ) ,
V_281 -> V_135 -> V_36 ( V_281 ) ,
F_17 ( & V_278 -> V_283 . V_26 ) ) ;
V_252 ++ ;
if ( ( V_252 + V_121 ) > V_124 ) {
F_40 ( L_189
L_190 ) ;
break;
}
memcpy ( V_5 + V_121 , V_112 , V_252 ) ;
V_121 += V_252 ;
}
F_64 ( & V_260 -> V_280 ) ;
return V_121 ;
}
static void F_159 ( struct V_2 * V_3 )
{
struct V_257 * V_260 = F_2 ( F_3 ( V_3 ) ,
struct V_257 , V_258 ) ;
F_160 ( V_260 ) ;
}
static struct V_16 * F_161 (
struct V_16 * V_17 ,
const char * V_11 )
{
struct V_223 * V_284 = F_2 ( V_17 , struct V_223 ,
V_285 ) ;
struct V_257 * V_260 ;
struct V_16 * V_276 = NULL ;
struct V_2 * V_286 = NULL ;
V_260 = F_162 ( V_284 -> V_111 , V_11 , 0 ) ;
if ( ! V_260 )
return NULL ;
V_276 = & V_260 -> V_258 ;
V_286 = & V_276 -> V_26 ;
F_15 ( V_276 , V_11 ,
& V_287 ) ;
F_12 ( L_218
L_219 ,
F_17 ( V_286 ) ) ;
return V_276 ;
}
static void F_163 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_257 * V_260 = F_2 ( F_3 ( V_3 ) ,
struct V_257 , V_258 ) ;
F_12 ( L_220
L_221 ,
F_17 ( V_3 ) , V_260 -> V_275 ) ;
F_19 ( V_3 ) ;
}
static struct V_16 * F_164 (
struct V_16 * V_17 ,
const char * V_11 )
{
return F_14 ( - V_87 ) ;
}
static void F_165 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
return;
}
static struct V_16 * F_166 (
struct V_16 * V_17 ,
const char * V_11 )
{
struct V_257 * V_260 ;
struct V_2 * V_288 = & V_17 -> V_26 ;
struct V_1 * V_200 = F_1 ( V_288 ) ;
struct V_289 * V_290 = V_200 -> V_291 ;
struct V_67 * V_68 ;
struct V_16 * V_249 = NULL , * V_292 = NULL ;
struct V_16 * V_293 = NULL ;
int V_294 = - V_61 , V_18 ;
V_18 = F_167 ( & V_200 -> V_295 ) ;
if ( V_18 )
return F_14 ( V_18 ) ;
V_68 = F_168 ( V_200 , V_11 ) ;
if ( ! V_68 )
goto V_147;
V_249 = & V_68 -> V_70 ;
V_249 -> V_22 = F_169 ( sizeof( struct V_16 * ) * 6 ,
V_59 ) ;
if ( ! V_249 -> V_22 )
goto V_296;
F_15 ( V_249 , V_11 , & V_290 -> V_297 ) ;
F_15 ( & V_68 -> V_102 . V_66 , L_222 ,
& V_290 -> V_298 ) ;
F_15 ( & V_68 -> V_125 , L_223 ,
& V_290 -> V_299 ) ;
F_15 ( & V_68 -> V_71 . V_109 , L_224 ,
& V_290 -> V_300 ) ;
F_15 ( & V_68 -> V_223 . V_285 ,
L_225 , & V_290 -> V_301 ) ;
F_15 ( & V_68 -> V_302 . V_303 ,
L_226 , & V_290 -> V_304 ) ;
V_249 -> V_22 [ 0 ] = & V_68 -> V_102 . V_66 ;
V_249 -> V_22 [ 1 ] = & V_68 -> V_125 ;
V_249 -> V_22 [ 2 ] = & V_68 -> V_71 . V_109 ;
V_249 -> V_22 [ 3 ] = & V_68 -> V_223 . V_285 ;
V_249 -> V_22 [ 4 ] = & V_68 -> V_302 . V_303 ;
V_249 -> V_22 [ 5 ] = NULL ;
V_260 = F_162 ( V_68 , L_227 , 1 ) ;
if ( ! V_260 )
goto V_305;
V_68 -> V_223 . V_306 = V_260 ;
V_292 = & V_68 -> V_223 . V_285 ;
V_292 -> V_22 = F_169 ( sizeof( struct V_16 * ) * 2 ,
V_59 ) ;
if ( ! V_292 -> V_22 ) {
F_25 ( L_228
L_229 ) ;
goto V_307;
}
F_15 ( & V_260 -> V_258 ,
L_227 , & V_287 ) ;
V_292 -> V_22 [ 0 ] = & V_260 -> V_258 ;
V_292 -> V_22 [ 1 ] = NULL ;
V_293 = & V_68 -> V_302 . V_303 ;
V_293 -> V_22 = F_169 ( sizeof( struct V_16 * ) * 4 ,
V_59 ) ;
if ( ! V_293 -> V_22 ) {
F_25 ( L_230 ) ;
goto V_308;
}
F_170 ( V_68 ) ;
F_10 ( & V_200 -> V_295 ) ;
return V_249 ;
V_308:
F_37 ( V_292 -> V_22 ) ;
V_307:
F_160 ( V_260 ) ;
V_305:
F_37 ( V_249 -> V_22 ) ;
V_296:
F_114 ( V_68 ) ;
V_147:
F_10 ( & V_200 -> V_295 ) ;
return F_14 ( V_294 ) ;
}
static void F_171 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_16 * V_249 = F_3 ( V_3 ) ;
struct V_67 * V_68 =
F_2 ( V_249 , struct V_67 , V_70 ) ;
struct V_1 * V_200 ;
struct V_2 * V_28 ;
struct V_16 * V_292 , * V_293 ;
int V_29 ;
V_200 = F_1 ( & V_68 -> V_1 -> V_4 . V_26 ) ;
F_7 ( & V_200 -> V_295 ) ;
V_293 = & V_68 -> V_302 . V_303 ;
for ( V_29 = 0 ; V_293 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_28 = & V_293 -> V_22 [ V_29 ] -> V_26 ;
V_293 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_28 ) ;
}
F_37 ( V_293 -> V_22 ) ;
V_292 = & V_68 -> V_223 . V_285 ;
for ( V_29 = 0 ; V_292 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_28 = & V_292 -> V_22 [ V_29 ] -> V_26 ;
V_292 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_28 ) ;
}
F_37 ( V_292 -> V_22 ) ;
V_68 -> V_223 . V_306 = NULL ;
for ( V_29 = 0 ; V_249 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_28 = & V_249 -> V_22 [ V_29 ] -> V_26 ;
V_249 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_28 ) ;
}
F_19 ( V_3 ) ;
F_10 ( & V_200 -> V_295 ) ;
}
static inline struct V_1 * F_172 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_173 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_200 = F_172 ( V_3 ) ;
return sprintf ( V_5 , L_231 ,
V_200 -> V_309 , V_200 -> V_291 -> V_310 -> V_11 ,
V_7 ) ;
}
static T_1 F_174 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_200 = F_172 ( V_3 ) ;
int V_311 = 0 ;
if ( V_200 -> V_312 & V_313 )
V_311 = 1 ;
return sprintf ( V_5 , L_154 , V_311 ) ;
}
static T_1 F_175 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_1 * V_200 = F_172 ( V_3 ) ;
unsigned long V_314 ;
int V_18 ;
if ( V_200 -> V_291 -> V_310 -> V_315 == NULL )
return - V_19 ;
V_18 = F_118 ( V_5 , 0 , & V_314 ) ;
if ( V_18 < 0 ) {
F_25 ( L_232 , V_18 ) ;
return V_18 ;
}
if ( V_200 -> V_316 ) {
F_25 ( L_233 ) ;
return - V_19 ;
}
V_18 = V_200 -> V_291 -> V_310 -> V_315 ( V_200 , V_314 ) ;
if ( V_18 < 0 )
return - V_19 ;
if ( V_18 > 0 )
V_200 -> V_312 |= V_313 ;
else if ( V_18 == 0 )
V_200 -> V_312 &= ~ V_313 ;
return V_73 ;
}
static void F_176 ( struct V_2 * V_3 )
{
struct V_1 * V_200 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_177 ( V_200 ) ;
}
static struct V_16 * F_178 (
struct V_16 * V_17 ,
const char * V_11 )
{
char * V_317 , * V_318 , * V_319 ;
struct V_1 * V_200 ;
char V_112 [ V_320 ] ;
unsigned long V_321 = 0 ;
int V_18 ;
memset ( V_112 , 0 , V_320 ) ;
if ( strlen ( V_11 ) >= V_320 ) {
F_25 ( L_234
L_235 , ( int ) strlen ( V_11 ) ,
V_320 ) ;
return F_14 ( - V_322 ) ;
}
snprintf ( V_112 , V_320 , L_53 , V_11 ) ;
V_318 = strstr ( V_112 , L_236 ) ;
if ( ! V_318 ) {
F_25 ( L_237 ) ;
return F_14 ( - V_19 ) ;
}
V_317 = V_112 ;
V_319 = strstr ( V_318 + 1 , L_236 ) ;
if ( V_319 ) {
* V_319 = '\0' ;
V_319 ++ ;
V_318 = V_319 ;
} else {
* V_318 = '\0' ;
V_318 ++ ;
}
V_18 = F_118 ( V_318 , 0 , & V_321 ) ;
if ( V_18 < 0 ) {
F_25 ( L_182
L_238 , V_18 ) ;
return F_14 ( V_18 ) ;
}
F_179 () ;
V_200 = F_180 ( V_317 , V_321 , 0 ) ;
if ( F_108 ( V_200 ) )
return F_181 ( V_200 ) ;
F_15 ( & V_200 -> V_4 , V_11 ,
& V_323 ) ;
return & V_200 -> V_4 ;
}
static void F_182 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
F_19 ( V_3 ) ;
}
void F_183 ( struct V_289 * V_290 )
{
F_184 ( V_290 ) ;
F_185 ( V_290 ) ;
F_186 ( V_290 ) ;
F_187 ( V_290 ) ;
F_188 ( V_290 ) ;
F_189 ( V_290 ) ;
}
static int T_8 F_190 ( void )
{
struct V_16 * V_324 , * V_325 = NULL , * V_326 = NULL ;
struct V_16 * V_327 = NULL ;
struct V_328 * V_329 = & V_30 ;
struct V_206 * V_207 ;
int V_18 ;
F_12 ( L_239
L_240 V_6 L_3 ,
V_7 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
F_191 ( & V_329 -> V_330 ) ;
F_192 ( & V_329 -> V_331 ) ;
V_18 = F_193 () ;
if ( V_18 < 0 )
return V_18 ;
V_324 = & V_329 -> V_330 ;
V_324 -> V_22 = F_169 ( sizeof( struct V_16 * ) * 2 ,
V_59 ) ;
if ( ! V_324 -> V_22 ) {
F_25 ( L_241 ) ;
V_18 = - V_61 ;
goto V_332;
}
F_15 ( & V_333 ,
L_242 , & V_334 ) ;
V_324 -> V_22 [ 0 ] = & V_333 ;
V_324 -> V_22 [ 1 ] = NULL ;
V_325 = & V_333 ;
V_325 -> V_22 = F_169 ( sizeof( struct V_16 * ) * 2 ,
V_59 ) ;
if ( ! V_325 -> V_22 ) {
F_25 ( L_243 ) ;
V_18 = - V_61 ;
goto V_332;
}
F_15 ( & V_335 ,
L_225 , & V_336 ) ;
V_325 -> V_22 [ 0 ] = & V_335 ;
V_325 -> V_22 [ 1 ] = NULL ;
V_326 = & V_335 ;
V_326 -> V_22 = F_169 ( sizeof( struct V_16 * ) * 2 ,
V_59 ) ;
if ( ! V_326 -> V_22 ) {
F_25 ( L_244 ) ;
V_18 = - V_61 ;
goto V_332;
}
F_15 ( & V_337 ,
L_245 , & V_338 ) ;
V_326 -> V_22 [ 0 ] = & V_337 ;
V_326 -> V_22 [ 1 ] = NULL ;
V_207 = F_124 ( L_246 , 1 ) ;
if ( F_108 ( V_207 ) ) {
V_18 = - V_61 ;
goto V_332;
}
V_327 = & V_337 ;
V_327 -> V_22 = F_169 ( sizeof( struct V_16 * ) * 2 ,
V_59 ) ;
if ( ! V_327 -> V_22 ) {
F_25 ( L_247 ) ;
V_18 = - V_61 ;
goto V_332;
}
F_15 ( & V_207 -> V_212 , L_246 ,
& V_256 ) ;
V_327 -> V_22 [ 0 ] = & V_207 -> V_212 ;
V_327 -> V_22 [ 1 ] = NULL ;
V_339 = V_207 ;
V_18 = F_194 ( V_329 ) ;
if ( V_18 < 0 ) {
F_25 ( L_248 ,
V_18 , V_329 -> V_330 . V_26 . V_340 ) ;
goto V_332;
}
F_12 ( L_249
L_250 V_7 L_251
L_252 V_6 L_3 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
V_18 = F_195 () ;
if ( V_18 < 0 )
goto V_176;
V_18 = F_196 () ;
if ( V_18 < 0 )
goto V_176;
V_18 = F_197 () ;
if ( V_18 < 0 )
goto V_176;
return 0 ;
V_176:
F_198 ( V_329 ) ;
F_199 () ;
F_200 () ;
V_332:
if ( V_339 ) {
F_122 ( V_339 ) ;
V_339 = NULL ;
}
if ( V_327 )
F_37 ( V_327 -> V_22 ) ;
if ( V_326 )
F_37 ( V_326 -> V_22 ) ;
if ( V_325 )
F_37 ( V_325 -> V_22 ) ;
F_37 ( V_324 -> V_22 ) ;
F_201 () ;
return V_18 ;
}
static void T_9 F_202 ( void )
{
struct V_16 * V_325 , * V_326 , * V_327 ;
struct V_2 * V_3 ;
int V_29 ;
V_327 = & V_337 ;
for ( V_29 = 0 ; V_327 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_3 = & V_327 -> V_22 [ V_29 ] -> V_26 ;
V_327 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_3 ) ;
}
F_37 ( V_327 -> V_22 ) ;
V_327 -> V_22 = NULL ;
V_326 = & V_335 ;
for ( V_29 = 0 ; V_326 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_3 = & V_326 -> V_22 [ V_29 ] -> V_26 ;
V_326 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_3 ) ;
}
F_37 ( V_326 -> V_22 ) ;
V_326 -> V_22 = NULL ;
V_325 = & V_333 ;
for ( V_29 = 0 ; V_325 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_3 = & V_325 -> V_22 [ V_29 ] -> V_26 ;
V_325 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_3 ) ;
}
F_37 ( V_325 -> V_22 ) ;
V_325 -> V_22 = NULL ;
F_198 ( & V_30 ) ;
F_37 ( V_30 . V_330 . V_22 ) ;
F_122 ( V_339 ) ;
V_339 = NULL ;
F_12 ( L_253
L_254 ) ;
F_199 () ;
F_200 () ;
F_203 () ;
F_201 () ;
}
