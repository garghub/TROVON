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
return F_23 ( V_3 ) ;
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
bool V_76 ;
int V_18 ;
V_18 = F_42 ( V_5 , & V_76 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_74 -> V_75 -> V_77 ) {
F_25 ( L_59
L_87 ,
V_74 -> V_75 , V_74 -> V_75 -> V_77 ) ;
return - V_19 ;
}
if ( V_76 && ! V_74 -> V_86 ) {
F_25 ( L_88
L_89 ,
V_74 -> V_75 ) ;
return - V_87 ;
}
V_74 -> V_102 = V_76 ;
F_12 ( L_90 ,
V_74 -> V_75 , V_76 ) ;
return V_73 ;
}
static T_1 F_55 ( struct V_2 * V_3 ,
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
F_25 ( L_91
L_63 ,
V_68 , V_68 -> V_77 ) ;
return - V_19 ;
}
if ( ! V_83 ) {
F_25 ( L_92 , V_68 ) ;
return - V_19 ;
}
if ( V_83 > V_68 -> V_103 . V_104 ) {
if ( V_83 > V_68 -> V_103 . V_105 ) {
F_25 ( L_93
L_94
L_95 , V_68 , V_83 ,
V_68 -> V_103 . V_105 ) ;
return - V_19 ;
}
}
V_74 -> V_104 = V_68 -> V_104 = V_83 ;
F_12 ( L_96 , V_68 , V_83 ) ;
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
F_25 ( L_59
L_97 ,
V_74 -> V_75 , V_74 -> V_75 -> V_77 ) ;
return - V_19 ;
}
if ( V_83 > V_74 -> V_106 ) {
F_25 ( L_98
L_99 ,
V_74 -> V_75 , V_83 , V_74 -> V_106 ) ;
return - V_19 ;
}
V_74 -> V_107 = V_83 ;
F_12 ( L_100 ,
V_74 -> V_75 , V_83 ) ;
return V_73 ;
}
static T_1 F_57 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_65 * V_74 = F_38 ( V_3 ) ;
T_3 V_83 ;
int V_18 ;
V_18 = F_45 ( V_5 , 0 , & V_83 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_74 -> V_75 -> V_77 ) {
F_25 ( L_101
L_55 ,
V_74 -> V_75 , V_74 -> V_75 -> V_77 ) ;
return - V_19 ;
}
if ( V_83 != 512 && V_83 != 1024 && V_83 != 2048 && V_83 != 4096 ) {
F_25 ( L_102
L_103 ,
V_74 -> V_75 , V_83 ) ;
return - V_19 ;
}
V_74 -> V_108 = V_83 ;
if ( V_74 -> V_109 )
V_74 -> V_106 = V_74 -> V_109 / V_83 ;
F_12 ( L_104 ,
V_74 -> V_75 , V_83 ) ;
return V_73 ;
}
static struct V_71 * F_58 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_71 , V_110 ) ;
}
static T_1 F_59 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_105 ,
& F_58 ( V_3 ) -> V_111 [ 0 ] ) ;
}
static T_1 F_60 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_71 * V_71 = F_58 ( V_3 ) ;
struct V_67 * V_68 = V_71 -> V_112 ;
unsigned char V_113 [ V_114 ] ;
if ( V_68 -> V_95 & V_115 ) {
F_25 ( L_106
L_107 ) ;
return - V_116 ;
}
if ( strlen ( V_5 ) >= V_114 ) {
F_25 ( L_108
L_109 , V_114 ) ;
return - V_117 ;
}
if ( V_68 -> V_77 ) {
F_25 ( L_110
L_111 ,
V_68 -> V_77 ) ;
return - V_19 ;
}
memset ( V_113 , 0 , V_114 ) ;
snprintf ( V_113 , V_114 , L_53 , V_5 ) ;
snprintf ( V_68 -> V_71 . V_111 , V_114 ,
L_53 , F_61 ( V_113 ) ) ;
V_68 -> V_95 |= V_118 ;
F_12 ( L_112
L_5 , V_68 -> V_71 . V_111 ) ;
return V_73 ;
}
static T_1 F_62 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_71 = F_58 ( V_3 ) ;
struct V_119 * V_120 ;
unsigned char V_113 [ V_121 ] ;
T_1 V_122 = 0 ;
memset ( V_113 , 0 , V_121 ) ;
F_63 ( & V_71 -> V_123 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_120 -> V_124 )
continue;
F_64 ( V_120 , V_113 , V_121 ) ;
if ( V_122 + strlen ( V_113 ) >= V_125 )
break;
V_122 += sprintf ( V_5 + V_122 , L_53 , V_113 ) ;
}
F_65 ( & V_71 -> V_123 ) ;
return V_122 ;
}
static struct V_67 * F_66 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_67 ,
V_126 ) ;
}
static T_1 F_67 ( struct V_67 * V_68 ,
char * V_5 )
{
struct V_127 * V_128 ;
struct V_129 * V_130 ;
char V_131 [ V_132 ] ;
memset ( V_131 , 0 , V_132 ) ;
V_130 = V_68 -> V_133 ;
if ( ! V_130 )
return sprintf ( V_5 , L_113 ) ;
V_128 = V_130 -> V_134 ;
F_68 ( V_130 , V_131 , V_132 ) ;
return sprintf ( V_5 , L_114 ,
V_128 -> V_135 -> V_136 -> V_34 () ,
V_128 -> V_137 , V_131 ) ;
}
static T_1 F_69 ( struct V_67 * V_68 ,
char * V_5 )
{
struct V_127 * V_128 ;
T_1 V_122 ;
V_128 = V_68 -> V_138 ;
if ( V_128 ) {
V_122 = sprintf ( V_5 ,
L_115 ,
V_128 -> V_135 -> V_136 -> V_34 () ,
V_128 -> V_137 ) ;
} else {
V_122 = sprintf ( V_5 , L_116 ) ;
}
return V_122 ;
}
static T_1 F_70 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_66 ( V_3 ) ;
int V_18 ;
if ( V_68 -> V_78 -> V_139 & V_140 )
return sprintf ( V_5 , L_117 ) ;
F_63 ( & V_68 -> V_141 ) ;
if ( V_68 -> V_142 & V_143 )
V_18 = F_69 ( V_68 , V_5 ) ;
else
V_18 = F_67 ( V_68 , V_5 ) ;
F_65 ( & V_68 -> V_141 ) ;
return V_18 ;
}
static T_1 F_71 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_67 * V_68 = F_66 ( V_3 ) ;
T_1 V_122 = 0 ;
F_63 ( & V_68 -> V_141 ) ;
if ( ! V_68 -> V_133 ) {
V_122 = sprintf ( V_5 , L_113 ) ;
} else if ( V_68 -> V_133 -> V_144 ) {
V_122 = sprintf ( V_5 , L_118
L_119 ) ;
} else {
V_122 = sprintf ( V_5 , L_120
L_121 ) ;
}
F_65 ( & V_68 -> V_141 ) ;
return V_122 ;
}
static T_1 F_72 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_122 , F_66 ( V_3 ) -> V_145 . V_146 ) ;
}
static T_1 F_73 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_67 * V_68 = F_66 ( V_3 ) ;
struct V_127 * V_128 ;
struct V_147 * V_135 ;
struct V_129 * V_130 ;
const struct V_31 * V_32 ;
T_1 V_122 = 0 ;
F_63 ( & V_68 -> V_141 ) ;
V_130 = V_68 -> V_133 ;
if ( ! V_130 ) {
V_122 = sprintf ( V_5 , L_113 ) ;
goto V_148;
}
V_128 = V_130 -> V_134 ;
V_135 = V_128 -> V_135 ;
V_32 = V_135 -> V_136 ;
V_122 += sprintf ( V_5 + V_122 , L_123
L_124 , V_32 -> V_34 () ,
V_32 -> V_35 ( V_135 ) ) ;
V_122 += sprintf ( V_5 + V_122 , L_125
L_126
L_127 , V_130 -> V_149 ,
V_32 -> V_34 () , V_32 -> V_36 ( V_135 ) ,
V_32 -> V_34 () , V_130 -> V_150 ) ;
V_148:
F_65 ( & V_68 -> V_141 ) ;
return V_122 ;
}
static T_1 F_74 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_67 * V_68 = F_66 ( V_3 ) ;
const struct V_31 * V_32 ;
struct V_129 * V_130 ;
unsigned char V_113 [ 384 ] ;
char V_131 [ V_132 ] ;
T_1 V_122 = 0 ;
int V_151 = 0 ;
V_122 += sprintf ( V_5 + V_122 , L_128 ) ;
F_63 ( & V_68 -> V_145 . V_152 ) ;
F_8 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_113 , 0 , 384 ) ;
memset ( V_131 , 0 , V_132 ) ;
V_32 = V_130 -> V_134 -> V_135 -> V_136 ;
F_68 ( V_130 , V_131 ,
V_132 ) ;
sprintf ( V_113 , L_129 ,
V_32 -> V_34 () ,
V_130 -> V_134 -> V_137 , V_131 , V_130 -> V_153 ,
V_130 -> V_154 ) ;
if ( V_122 + strlen ( V_113 ) >= V_125 )
break;
V_122 += sprintf ( V_5 + V_122 , L_53 , V_113 ) ;
V_151 ++ ;
}
F_65 ( & V_68 -> V_145 . V_152 ) ;
if ( ! V_151 )
V_122 += sprintf ( V_5 + V_122 , L_130 ) ;
return V_122 ;
}
static T_1 F_75 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_66 ( V_3 ) ;
struct V_129 * V_130 ;
T_1 V_122 = 0 ;
F_63 ( & V_68 -> V_141 ) ;
V_130 = V_68 -> V_133 ;
if ( V_130 ) {
V_122 = sprintf ( V_5 , L_131 ,
F_76 ( V_130 -> V_155 ) ) ;
} else {
V_122 = sprintf ( V_5 , L_113 ) ;
}
F_65 ( & V_68 -> V_141 ) ;
return V_122 ;
}
static T_1 F_77 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_66 ( V_3 ) ;
if ( V_68 -> V_78 -> V_139 & V_140 )
return sprintf ( V_5 , L_132 ) ;
else if ( V_68 -> V_142 & V_143 )
return sprintf ( V_5 , L_133 ) ;
else
return sprintf ( V_5 , L_134 ) ;
}
static T_1 F_78 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_67 * V_68 = F_66 ( V_3 ) ;
if ( V_68 -> V_78 -> V_139 & V_140 )
return 0 ;
return sprintf ( V_5 , L_135 ,
( V_68 -> V_145 . V_156 ) ? L_136 : L_66 ) ;
}
static T_1 F_79 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_67 * V_68 = F_66 ( V_3 ) ;
if ( V_68 -> V_78 -> V_139 & V_140 )
return 0 ;
return sprintf ( V_5 , L_137 ) ;
}
static T_1 F_80 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_66 ( V_3 ) ;
unsigned char * V_157 = NULL , * V_158 = NULL , * V_159 = NULL ;
unsigned char * V_160 = NULL , * V_161 = NULL ;
char * V_162 , * V_163 , * V_164 ;
T_4 args [ V_165 ] ;
unsigned long long V_166 ;
T_5 V_167 = 0 ;
T_5 V_168 = 0 , V_169 = 0 ;
int V_18 = - 1 , V_170 = 0 , V_171 = 0 , V_172 , V_173 ;
T_6 V_174 = 0 ;
T_7 type = 0 ;
if ( V_68 -> V_78 -> V_139 & V_140 )
return V_73 ;
if ( V_68 -> V_142 & V_143 )
return V_73 ;
if ( V_68 -> V_77 ) {
F_12 ( L_138
L_139 ) ;
return - V_19 ;
}
V_164 = F_81 ( V_5 , V_59 ) ;
if ( ! V_164 )
return - V_61 ;
V_162 = V_164 ;
while ( ( V_163 = F_82 ( & V_164 , L_140 ) ) != NULL ) {
if ( ! * V_163 )
continue;
V_173 = F_83 ( V_163 , V_175 , args ) ;
switch ( V_173 ) {
case V_176 :
V_157 = F_84 ( args ) ;
if ( ! V_157 ) {
V_18 = - V_61 ;
goto V_177;
}
break;
case V_178 :
V_158 = F_84 ( args ) ;
if ( ! V_158 ) {
V_18 = - V_61 ;
goto V_177;
}
if ( strlen ( V_158 ) >= V_179 ) {
F_25 ( L_141
L_142 ,
V_179 ) ;
V_18 = - V_19 ;
break;
}
break;
case V_180 :
V_159 = F_84 ( args ) ;
if ( ! V_159 ) {
V_18 = - V_61 ;
goto V_177;
}
if ( strlen ( V_159 ) >= V_181 ) {
F_25 ( L_143
L_144 ,
V_181 ) ;
V_18 = - V_19 ;
break;
}
break;
case V_182 :
V_18 = F_85 ( args -> V_183 , 0 , & V_166 ) ;
if ( V_18 < 0 ) {
F_25 ( L_145 ) ;
goto V_177;
}
V_167 = ( T_5 ) V_166 ;
break;
case V_184 :
V_18 = F_86 ( args , & V_172 ) ;
if ( V_18 )
goto V_177;
V_170 = V_172 ;
break;
case V_185 :
V_18 = F_86 ( args , & V_172 ) ;
if ( V_18 )
goto V_177;
type = ( T_7 ) V_172 ;
break;
case V_186 :
V_18 = F_86 ( args , & V_172 ) ;
if ( V_18 )
goto V_177;
break;
case V_187 :
V_18 = F_86 ( args , & V_172 ) ;
if ( V_18 )
goto V_177;
V_171 = ( int ) V_172 ;
break;
case V_188 :
V_18 = F_86 ( args , & V_172 ) ;
if ( V_18 )
goto V_177;
V_168 = ( T_5 ) V_172 ;
break;
case V_189 :
V_160 = F_84 ( args ) ;
if ( ! V_160 ) {
V_18 = - V_61 ;
goto V_177;
}
break;
case V_190 :
V_161 = F_84 ( args ) ;
if ( ! V_161 ) {
V_18 = - V_61 ;
goto V_177;
}
if ( strlen ( V_161 ) >= V_191 ) {
F_25 ( L_146
L_147 ,
V_191 ) ;
V_18 = - V_19 ;
break;
}
break;
case V_192 :
V_18 = F_86 ( args , & V_172 ) ;
if ( V_18 )
goto V_177;
V_174 = ( T_6 ) V_172 ;
break;
case V_193 :
V_18 = F_86 ( args , & V_172 ) ;
if ( V_18 )
goto V_177;
break;
case V_194 :
V_18 = F_86 ( args , & V_172 ) ;
if ( V_18 )
goto V_177;
V_169 = ( T_5 ) V_172 ;
break;
default:
break;
}
}
if ( ! V_158 || ! V_161 || ! V_167 ) {
F_25 ( L_148 ) ;
V_18 = - V_19 ;
goto V_177;
}
if ( V_170 && ! ( type ) ) {
F_25 ( L_149
L_150 , type ) ;
V_18 = - V_19 ;
goto V_177;
}
V_18 = F_87 ( & V_68 -> V_145 , V_167 ,
V_158 , V_159 , V_168 , V_161 , V_174 , V_169 ,
V_170 , V_171 , type ) ;
V_177:
F_37 ( V_157 ) ;
F_37 ( V_158 ) ;
F_37 ( V_159 ) ;
F_37 ( V_160 ) ;
F_37 ( V_161 ) ;
F_37 ( V_162 ) ;
return ( V_18 == 0 ) ? V_73 : V_18 ;
}
static inline struct V_67 * F_88 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_67 , V_70 ) ;
}
static T_1 F_89 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
int V_195 = 0 ;
T_1 V_196 = 0 ;
F_90 ( V_68 , V_5 , & V_195 ) ;
V_196 += V_195 ;
V_196 += V_68 -> V_78 -> V_197 ( V_68 ,
V_5 + V_196 ) ;
return V_196 ;
}
static T_1 F_91 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
return V_68 -> V_78 -> V_198 ( V_68 , V_5 , V_73 ) ;
}
static T_1 F_92 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
if ( ! ( V_68 -> V_95 & V_199 ) )
return 0 ;
return snprintf ( V_5 , V_125 , L_151 , V_68 -> V_200 ) ;
}
static T_1 F_93 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
struct V_1 * V_201 = V_68 -> V_1 ;
T_1 V_196 ;
if ( V_73 > ( V_202 - 1 ) ) {
F_25 ( L_152
L_153 , ( int ) V_73 ,
V_202 - 1 ) ;
return - V_19 ;
}
V_196 = snprintf ( & V_68 -> V_200 [ 0 ] , V_202 , L_53 , V_5 ) ;
if ( ! V_196 )
return - V_19 ;
if ( V_68 -> V_200 [ V_196 - 1 ] == '\n' )
V_68 -> V_200 [ V_196 - 1 ] = '\0' ;
V_68 -> V_95 |= V_199 ;
F_12 ( L_154 ,
F_17 ( & V_201 -> V_4 . V_26 ) ,
F_17 ( & V_68 -> V_70 . V_26 ) ,
V_68 -> V_200 ) ;
return V_196 ;
}
static T_1 F_94 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
if ( ! ( V_68 -> V_95 & V_203 ) )
return 0 ;
return snprintf ( V_5 , V_125 , L_151 , V_68 -> V_204 ) ;
}
static T_1 F_95 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
struct V_1 * V_201 = V_68 -> V_1 ;
T_1 V_196 ;
if ( V_73 > ( V_205 - 1 ) ) {
F_25 ( L_155
L_156 , ( int ) V_73 ,
V_205 - 1 ) ;
return - V_19 ;
}
V_196 = snprintf ( & V_68 -> V_204 [ 0 ] , V_205 ,
L_53 , V_5 ) ;
if ( ! V_196 )
return - V_19 ;
if ( V_68 -> V_204 [ V_196 - 1 ] == '\n' )
V_68 -> V_204 [ V_196 - 1 ] = '\0' ;
V_68 -> V_95 |= V_203 ;
F_12 ( L_157 ,
F_17 ( & V_201 -> V_4 . V_26 ) ,
F_17 ( & V_68 -> V_70 . V_26 ) ,
V_68 -> V_204 ) ;
return V_196 ;
}
static T_1 F_96 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
return snprintf ( V_5 , V_125 , L_158 , ! ! ( V_68 -> V_95 & V_96 ) ) ;
}
static T_1 F_97 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
char * V_163 ;
int V_18 ;
V_163 = strstr ( V_5 , L_159 ) ;
if ( ! V_163 ) {
F_25 ( L_160
L_161 ) ;
return - V_19 ;
}
V_18 = F_98 ( V_68 ) ;
if ( V_18 )
return V_18 ;
return V_73 ;
}
static T_1 F_99 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
struct V_2 * V_206 ;
struct V_207 * V_208 ;
struct V_209 * V_210 ;
T_1 V_122 = 0 ;
V_210 = V_68 -> V_211 ;
if ( ! V_210 )
return 0 ;
F_63 ( & V_210 -> V_212 ) ;
V_208 = V_210 -> V_208 ;
if ( V_208 ) {
V_206 = & V_208 -> V_213 . V_26 ;
V_122 += sprintf ( V_5 , L_162 ,
F_17 ( V_206 ) , V_208 -> V_214 ) ;
}
F_65 ( & V_210 -> V_212 ) ;
return V_122 ;
}
static T_1 F_100 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
struct V_1 * V_201 = V_68 -> V_1 ;
struct V_207 * V_208 = NULL , * V_215 = NULL ;
struct V_209 * V_210 ;
unsigned char V_113 [ V_216 ] ;
int V_217 = 0 ;
V_210 = V_68 -> V_211 ;
if ( ! V_210 )
return V_73 ;
if ( V_73 > V_216 ) {
F_25 ( L_163 ) ;
return - V_19 ;
}
memset ( V_113 , 0 , V_216 ) ;
memcpy ( V_113 , V_5 , V_73 ) ;
if ( strcmp ( F_61 ( V_113 ) , L_164 ) ) {
V_215 = F_101 ( F_61 ( V_113 ) ) ;
if ( ! V_215 )
return - V_97 ;
}
F_63 ( & V_210 -> V_212 ) ;
V_208 = V_210 -> V_208 ;
if ( V_208 ) {
if ( ! V_215 ) {
F_12 ( L_165
L_166
L_167 ,
F_17 ( & V_201 -> V_4 . V_26 ) ,
F_17 ( & V_68 -> V_70 . V_26 ) ,
F_17 ( & V_208 -> V_213 . V_26 ) ,
V_208 -> V_214 ) ;
F_102 ( V_210 , V_208 ) ;
F_65 ( & V_210 -> V_212 ) ;
return V_73 ;
}
F_102 ( V_210 , V_208 ) ;
V_217 = 1 ;
}
F_103 ( V_210 , V_215 ) ;
F_65 ( & V_210 -> V_212 ) ;
F_12 ( L_168
L_169 ,
( V_217 ) ? L_170 : L_171 ,
F_17 ( & V_201 -> V_4 . V_26 ) ,
F_17 ( & V_68 -> V_70 . V_26 ) ,
F_17 ( & V_215 -> V_213 . V_26 ) ,
V_215 -> V_214 ) ;
F_104 ( V_215 ) ;
return V_73 ;
}
static T_1 F_105 ( struct V_2 * V_3 , char * V_5 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
struct V_218 * V_219 ;
struct V_220 * V_221 ;
char * V_222 = V_5 ;
int V_195 = 0 ;
char V_223 ;
F_63 ( & V_68 -> V_224 . V_225 ) ;
if ( ! F_106 ( & V_68 -> V_224 . V_226 ) )
V_195 += sprintf ( V_222 + V_195 , L_172 ,
V_68 -> V_224 . V_227 ,
V_68 -> V_224 . V_228 ) ;
F_8 (map, &dev->t10_alua.lba_map_list, lba_map_list) {
V_195 += sprintf ( V_222 + V_195 , L_173 ,
V_219 -> V_229 , V_219 -> V_230 ) ;
F_8 (mem, &map->lba_map_mem_list,
lba_map_mem_list) {
switch ( V_221 -> V_231 ) {
case V_232 :
V_223 = 'O' ;
break;
case V_233 :
V_223 = 'A' ;
break;
case V_234 :
V_223 = 'S' ;
break;
case V_235 :
V_223 = 'U' ;
break;
default:
V_223 = '.' ;
break;
}
V_195 += sprintf ( V_222 + V_195 , L_174 ,
V_221 -> V_236 , V_223 ) ;
}
V_195 += sprintf ( V_222 + V_195 , L_3 ) ;
}
F_65 ( & V_68 -> V_224 . V_225 ) ;
return V_195 ;
}
static T_1 F_107 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_67 * V_68 = F_88 ( V_3 ) ;
struct V_218 * V_237 = NULL ;
struct V_238 V_239 ;
char * V_240 , * V_162 , * V_163 ;
char V_223 ;
int V_241 = - 1 , V_242 ;
int V_18 = 0 , V_243 = 0 , V_244 , V_245 ;
unsigned long V_246 = - 1 , V_247 = - 1 ;
unsigned long V_248 = - 1 , V_249 = - 1 ;
V_162 = V_240 = F_81 ( V_5 , V_59 ) ;
if ( ! V_240 )
return - V_61 ;
F_28 ( & V_239 ) ;
while ( ( V_163 = F_82 ( & V_240 , L_3 ) ) != NULL ) {
if ( ! * V_163 )
continue;
if ( V_243 == 0 ) {
if ( sscanf ( V_163 , L_175 ,
& V_248 , & V_249 ) != 2 ) {
F_25 ( L_176 , V_243 ) ;
V_18 = - V_19 ;
break;
}
V_243 ++ ;
continue;
}
if ( sscanf ( V_163 , L_177 , & V_246 , & V_247 ) != 2 ) {
F_25 ( L_176 , V_243 ) ;
V_18 = - V_19 ;
break;
}
V_163 = strchr ( V_163 , ' ' ) ;
if ( ! V_163 ) {
F_25 ( L_178 , V_243 ) ;
V_18 = - V_19 ;
break;
}
V_163 ++ ;
V_163 = strchr ( V_163 , ' ' ) ;
if ( ! V_163 ) {
F_25 ( L_179 ,
V_243 ) ;
V_18 = - V_19 ;
break;
}
V_163 ++ ;
V_237 = F_108 ( & V_239 ,
V_246 , V_247 ) ;
if ( F_109 ( V_237 ) ) {
V_18 = F_110 ( V_237 ) ;
break;
}
V_242 = 0 ;
while ( sscanf ( V_163 , L_180 , & V_244 , & V_223 ) == 2 ) {
switch ( V_223 ) {
case 'O' :
V_245 = V_232 ;
break;
case 'A' :
V_245 = V_233 ;
break;
case 'S' :
V_245 = V_234 ;
break;
case 'U' :
V_245 = V_235 ;
break;
default:
F_25 ( L_181 , V_223 ) ;
V_18 = - V_19 ;
goto V_177;
}
V_18 = F_111 ( V_237 ,
V_244 , V_245 ) ;
if ( V_18 ) {
F_25 ( L_182
L_183 ,
V_244 , V_223 , V_243 ) ;
break;
}
V_242 ++ ;
V_163 = strchr ( V_163 , ' ' ) ;
if ( V_163 )
V_163 ++ ;
else
break;
}
if ( V_241 == - 1 )
V_241 = V_242 ;
else if ( V_242 != V_241 ) {
F_25 ( L_184
L_183 , V_242 , V_241 , V_243 ) ;
V_18 = - V_19 ;
break;
}
V_243 ++ ;
}
V_177:
if ( V_18 ) {
F_112 ( & V_239 ) ;
V_73 = V_18 ;
} else
F_113 ( V_68 , & V_239 ,
V_248 , V_249 ) ;
F_37 ( V_162 ) ;
return V_73 ;
}
static void F_114 ( struct V_2 * V_3 )
{
struct V_16 * V_250 = F_3 ( V_3 ) ;
struct V_67 * V_68 =
F_2 ( V_250 , struct V_67 , V_70 ) ;
F_37 ( V_250 -> V_22 ) ;
F_115 ( V_68 ) ;
}
static inline struct V_207 * F_116 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_207 ,
V_213 ) ;
}
static T_1 F_117 ( struct V_2 * V_3 , char * V_5 )
{
struct V_207 * V_208 = F_116 ( V_3 ) ;
if ( ! V_208 -> V_251 )
return 0 ;
return sprintf ( V_5 , L_185 , V_208 -> V_214 ) ;
}
static T_1 F_118 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_207 * V_208 = F_116 ( V_3 ) ;
struct V_16 * V_252 = & V_208 -> V_213 ;
unsigned long V_214 ;
int V_18 ;
V_18 = F_119 ( V_5 , 0 , & V_214 ) ;
if ( V_18 < 0 ) {
F_25 ( L_186
L_187 , V_18 ) ;
return V_18 ;
}
if ( V_214 > 0x0000ffff ) {
F_25 ( L_188
L_189 , V_214 ) ;
return - V_19 ;
}
V_18 = F_120 ( V_208 , ( T_6 ) V_214 ) ;
if ( V_18 < 0 )
return - V_19 ;
F_12 ( L_190
L_191 ,
F_17 ( & V_252 -> V_26 ) ,
V_208 -> V_214 ) ;
return V_73 ;
}
static T_1 F_121 ( struct V_2 * V_3 , char * V_5 )
{
struct V_207 * V_208 = F_116 ( V_3 ) ;
struct V_67 * V_68 ;
struct V_1 * V_201 ;
struct V_209 * V_210 ;
T_1 V_122 = 0 , V_253 ;
unsigned char V_113 [ V_216 ] ;
memset ( V_113 , 0 , V_216 ) ;
F_63 ( & V_208 -> V_254 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_68 = V_210 -> V_255 ;
V_201 = V_68 -> V_1 ;
V_253 = snprintf ( V_113 , V_216 , L_192 ,
F_17 ( & V_201 -> V_4 . V_26 ) ,
F_17 ( & V_68 -> V_70 . V_26 ) ) ;
V_253 ++ ;
if ( ( V_253 + V_122 ) > V_125 ) {
F_40 ( L_193
L_194 ) ;
break;
}
memcpy ( V_5 + V_122 , V_113 , V_253 ) ;
V_122 += V_253 ;
}
F_65 ( & V_208 -> V_254 ) ;
return V_122 ;
}
static void F_122 ( struct V_2 * V_3 )
{
struct V_207 * V_208 = F_2 ( F_3 ( V_3 ) ,
struct V_207 , V_213 ) ;
F_123 ( V_208 ) ;
}
static struct V_16 * F_124 (
struct V_16 * V_17 ,
const char * V_11 )
{
struct V_207 * V_208 ;
struct V_16 * V_252 = NULL ;
struct V_2 * V_256 = NULL ;
V_208 = F_125 ( V_11 , 0 ) ;
if ( F_109 ( V_208 ) )
return NULL ;
V_252 = & V_208 -> V_213 ;
V_256 = & V_252 -> V_26 ;
F_15 ( V_252 , V_11 ,
& V_257 ) ;
F_12 ( L_195
L_196 ,
F_17 ( V_256 ) ) ;
return V_252 ;
}
static void F_126 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_207 * V_208 = F_2 ( F_3 ( V_3 ) ,
struct V_207 , V_213 ) ;
F_12 ( L_197
L_198 ,
F_17 ( V_3 ) , V_208 -> V_214 ) ;
F_19 ( V_3 ) ;
}
static inline struct V_258 * F_127 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_258 ,
V_259 ) ;
}
static T_1 F_128 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_158 ,
F_34 ( & F_127 ( V_3 ) -> V_260 ) ) ;
}
static T_1 F_129 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_258 * V_261 = F_127 ( V_3 ) ;
struct V_67 * V_68 = V_261 -> V_262 ;
unsigned long V_263 ;
int V_264 , V_18 ;
if ( ! V_261 -> V_265 ) {
F_25 ( L_199
L_200 , V_261 -> V_265 ) ;
return - V_19 ;
}
if ( ! ( V_68 -> V_95 & V_96 ) ) {
F_25 ( L_201
L_202 ) ;
return - V_97 ;
}
V_18 = F_119 ( V_5 , 0 , & V_263 ) ;
if ( V_18 < 0 ) {
F_25 ( L_203
L_5 , V_5 ) ;
return V_18 ;
}
V_264 = ( int ) V_263 ;
if ( ! ( V_261 -> V_266 & V_267 ) ) {
F_25 ( L_204
L_205 ) ;
return - V_19 ;
}
if ( V_261 -> V_266 & V_268 &&
V_264 == V_269 ) {
F_25 ( L_206
L_207 ) ;
return - V_19 ;
}
V_18 = F_130 ( V_261 , V_68 ,
NULL , NULL , V_264 , 0 ) ;
return ( ! V_18 ) ? V_73 : - V_19 ;
}
static T_1 F_131 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_258 * V_261 = F_127 ( V_3 ) ;
return sprintf ( V_5 , L_151 ,
F_132 ( V_261 -> V_270 ) ) ;
}
static T_1 F_133 (
struct V_2 * V_3 , const char * V_5 , T_2 V_73 )
{
struct V_258 * V_261 = F_127 ( V_3 ) ;
unsigned long V_263 ;
int V_271 , V_18 ;
if ( ! V_261 -> V_265 ) {
F_25 ( L_208
L_209 ,
V_261 -> V_265 ) ;
return - V_19 ;
}
V_18 = F_119 ( V_5 , 0 , & V_263 ) ;
if ( V_18 < 0 ) {
F_25 ( L_210
L_211 , V_5 ) ;
return V_18 ;
}
V_271 = ( int ) V_263 ;
if ( ( V_271 != V_272 ) &&
( V_271 != V_273 ) &&
( V_271 != V_274 ) ) {
F_25 ( L_212 ,
V_271 ) ;
return - V_19 ;
}
V_261 -> V_270 = V_271 ;
return V_73 ;
}
static T_1 F_134 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_135 ( F_127 ( V_3 ) , V_5 ) ;
}
static T_1 F_136 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
return F_137 ( F_127 ( V_3 ) , V_5 , V_73 ) ;
}
static T_1 F_138 (
struct V_2 * V_3 , char * V_5 )
{
return sprintf ( V_5 , L_158 ,
F_127 ( V_3 ) -> V_275 ) ;
}
static T_1 F_139 (
struct V_2 * V_3 , const char * V_5 , T_2 V_73 )
{
struct V_258 * V_261 = F_127 ( V_3 ) ;
unsigned long V_263 ;
int V_18 ;
V_18 = F_119 ( V_5 , 0 , & V_263 ) ;
if ( V_18 < 0 ) {
F_25 ( L_213 ) ;
return V_18 ;
}
if ( ( V_263 != 0 ) && ( V_263 != 1 ) ) {
F_25 ( L_214
L_215 , V_263 ) ;
return - V_19 ;
}
V_261 -> V_275 = ( int ) V_263 ;
return V_73 ;
}
static T_1 F_140 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_141 ( F_127 ( V_3 ) , V_5 ) ;
}
static T_1 F_142 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
return F_143 ( F_127 ( V_3 ) , V_5 ,
V_73 ) ;
}
static T_1 F_144 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_145 ( F_127 ( V_3 ) , V_5 ) ;
}
static T_1 F_146 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
return F_147 ( F_127 ( V_3 ) , V_5 ,
V_73 ) ;
}
static T_1 F_148 (
struct V_2 * V_3 , char * V_5 )
{
return F_149 ( F_127 ( V_3 ) , V_5 ) ;
}
static T_1 F_150 (
struct V_2 * V_3 , const char * V_5 , T_2 V_73 )
{
return F_151 ( F_127 ( V_3 ) , V_5 ,
V_73 ) ;
}
static T_1 F_152 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_153 ( F_127 ( V_3 ) , V_5 ) ;
}
static T_1 F_154 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
return F_155 ( F_127 ( V_3 ) , V_5 , V_73 ) ;
}
static T_1 F_156 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_258 * V_261 = F_127 ( V_3 ) ;
if ( ! V_261 -> V_265 )
return 0 ;
return sprintf ( V_5 , L_185 , V_261 -> V_276 ) ;
}
static T_1 F_157 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_258 * V_261 = F_127 ( V_3 ) ;
struct V_16 * V_277 = & V_261 -> V_259 ;
unsigned long V_276 ;
int V_18 ;
V_18 = F_119 ( V_5 , 0 , & V_276 ) ;
if ( V_18 < 0 ) {
F_25 ( L_186
L_216 , V_18 ) ;
return V_18 ;
}
if ( V_276 > 0x0000ffff ) {
F_25 ( L_217
L_189 , V_276 ) ;
return - V_19 ;
}
V_18 = F_158 ( V_261 , ( T_6 ) V_276 ) ;
if ( V_18 < 0 )
return - V_19 ;
F_12 ( L_218
L_219 ,
F_17 ( & V_277 -> V_26 ) ,
V_261 -> V_276 ) ;
return V_73 ;
}
static T_1 F_159 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_258 * V_261 = F_127 ( V_3 ) ;
struct V_278 * V_279 ;
T_1 V_122 = 0 , V_253 ;
unsigned char V_113 [ V_280 ] ;
memset ( V_113 , 0 , V_280 ) ;
F_63 ( & V_261 -> V_281 ) ;
F_8 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
struct V_147 * V_282 = V_279 -> V_283 ;
V_253 = snprintf ( V_113 , V_280 , L_220
L_221 , V_282 -> V_136 -> V_34 () ,
V_282 -> V_136 -> V_35 ( V_282 ) ,
V_282 -> V_136 -> V_36 ( V_282 ) ,
F_17 ( & V_279 -> V_284 . V_26 ) ) ;
V_253 ++ ;
if ( ( V_253 + V_122 ) > V_125 ) {
F_40 ( L_193
L_194 ) ;
break;
}
memcpy ( V_5 + V_122 , V_113 , V_253 ) ;
V_122 += V_253 ;
}
F_65 ( & V_261 -> V_281 ) ;
return V_122 ;
}
static void F_160 ( struct V_2 * V_3 )
{
struct V_258 * V_261 = F_2 ( F_3 ( V_3 ) ,
struct V_258 , V_259 ) ;
F_161 ( V_261 ) ;
}
static struct V_16 * F_162 (
struct V_16 * V_17 ,
const char * V_11 )
{
struct V_224 * V_285 = F_2 ( V_17 , struct V_224 ,
V_286 ) ;
struct V_258 * V_261 ;
struct V_16 * V_277 = NULL ;
struct V_2 * V_287 = NULL ;
V_261 = F_163 ( V_285 -> V_112 , V_11 , 0 ) ;
if ( ! V_261 )
return NULL ;
V_277 = & V_261 -> V_259 ;
V_287 = & V_277 -> V_26 ;
F_15 ( V_277 , V_11 ,
& V_288 ) ;
F_12 ( L_222
L_223 ,
F_17 ( V_287 ) ) ;
return V_277 ;
}
static void F_164 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_258 * V_261 = F_2 ( F_3 ( V_3 ) ,
struct V_258 , V_259 ) ;
F_12 ( L_224
L_225 ,
F_17 ( V_3 ) , V_261 -> V_276 ) ;
F_19 ( V_3 ) ;
}
static struct V_16 * F_165 (
struct V_16 * V_17 ,
const char * V_11 )
{
return F_14 ( - V_87 ) ;
}
static void F_166 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
return;
}
static struct V_16 * F_167 (
struct V_16 * V_17 ,
const char * V_11 )
{
struct V_258 * V_261 ;
struct V_2 * V_289 = & V_17 -> V_26 ;
struct V_1 * V_201 = F_1 ( V_289 ) ;
struct V_290 * V_291 = V_201 -> V_292 ;
struct V_67 * V_68 ;
struct V_16 * V_250 = NULL , * V_293 = NULL ;
struct V_16 * V_294 = NULL ;
int V_295 = - V_61 , V_18 ;
V_18 = F_168 ( & V_201 -> V_296 ) ;
if ( V_18 )
return F_14 ( V_18 ) ;
V_68 = F_169 ( V_201 , V_11 ) ;
if ( ! V_68 )
goto V_148;
V_250 = & V_68 -> V_70 ;
V_250 -> V_22 = F_170 ( sizeof( struct V_16 * ) * 6 ,
V_59 ) ;
if ( ! V_250 -> V_22 )
goto V_297;
F_15 ( V_250 , V_11 , & V_291 -> V_298 ) ;
F_15 ( & V_68 -> V_103 . V_66 , L_226 ,
& V_291 -> V_299 ) ;
F_15 ( & V_68 -> V_126 , L_227 ,
& V_291 -> V_300 ) ;
F_15 ( & V_68 -> V_71 . V_110 , L_228 ,
& V_291 -> V_301 ) ;
F_15 ( & V_68 -> V_224 . V_286 ,
L_229 , & V_291 -> V_302 ) ;
F_15 ( & V_68 -> V_303 . V_304 ,
L_230 , & V_291 -> V_305 ) ;
V_250 -> V_22 [ 0 ] = & V_68 -> V_103 . V_66 ;
V_250 -> V_22 [ 1 ] = & V_68 -> V_126 ;
V_250 -> V_22 [ 2 ] = & V_68 -> V_71 . V_110 ;
V_250 -> V_22 [ 3 ] = & V_68 -> V_224 . V_286 ;
V_250 -> V_22 [ 4 ] = & V_68 -> V_303 . V_304 ;
V_250 -> V_22 [ 5 ] = NULL ;
V_261 = F_163 ( V_68 , L_231 , 1 ) ;
if ( ! V_261 )
goto V_306;
V_68 -> V_224 . V_307 = V_261 ;
V_293 = & V_68 -> V_224 . V_286 ;
V_293 -> V_22 = F_170 ( sizeof( struct V_16 * ) * 2 ,
V_59 ) ;
if ( ! V_293 -> V_22 ) {
F_25 ( L_232
L_233 ) ;
goto V_308;
}
F_15 ( & V_261 -> V_259 ,
L_231 , & V_288 ) ;
V_293 -> V_22 [ 0 ] = & V_261 -> V_259 ;
V_293 -> V_22 [ 1 ] = NULL ;
V_294 = & V_68 -> V_303 . V_304 ;
V_294 -> V_22 = F_170 ( sizeof( struct V_16 * ) * 4 ,
V_59 ) ;
if ( ! V_294 -> V_22 ) {
F_25 ( L_234 ) ;
goto V_309;
}
F_171 ( V_68 ) ;
F_10 ( & V_201 -> V_296 ) ;
return V_250 ;
V_309:
F_37 ( V_293 -> V_22 ) ;
V_308:
F_161 ( V_261 ) ;
V_306:
F_37 ( V_250 -> V_22 ) ;
V_297:
F_115 ( V_68 ) ;
V_148:
F_10 ( & V_201 -> V_296 ) ;
return F_14 ( V_295 ) ;
}
static void F_172 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_16 * V_250 = F_3 ( V_3 ) ;
struct V_67 * V_68 =
F_2 ( V_250 , struct V_67 , V_70 ) ;
struct V_1 * V_201 ;
struct V_2 * V_28 ;
struct V_16 * V_293 , * V_294 ;
int V_29 ;
V_201 = F_1 ( & V_68 -> V_1 -> V_4 . V_26 ) ;
F_7 ( & V_201 -> V_296 ) ;
V_294 = & V_68 -> V_303 . V_304 ;
for ( V_29 = 0 ; V_294 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_28 = & V_294 -> V_22 [ V_29 ] -> V_26 ;
V_294 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_28 ) ;
}
F_37 ( V_294 -> V_22 ) ;
V_293 = & V_68 -> V_224 . V_286 ;
for ( V_29 = 0 ; V_293 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_28 = & V_293 -> V_22 [ V_29 ] -> V_26 ;
V_293 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_28 ) ;
}
F_37 ( V_293 -> V_22 ) ;
V_68 -> V_224 . V_307 = NULL ;
for ( V_29 = 0 ; V_250 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_28 = & V_250 -> V_22 [ V_29 ] -> V_26 ;
V_250 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_28 ) ;
}
F_19 ( V_3 ) ;
F_10 ( & V_201 -> V_296 ) ;
}
static inline struct V_1 * F_173 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_174 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_201 = F_173 ( V_3 ) ;
return sprintf ( V_5 , L_235 ,
V_201 -> V_310 , V_201 -> V_292 -> V_311 -> V_11 ,
V_7 ) ;
}
static T_1 F_175 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_201 = F_173 ( V_3 ) ;
int V_312 = 0 ;
if ( V_201 -> V_313 & V_314 )
V_312 = 1 ;
return sprintf ( V_5 , L_158 , V_312 ) ;
}
static T_1 F_176 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_73 )
{
struct V_1 * V_201 = F_173 ( V_3 ) ;
unsigned long V_315 ;
int V_18 ;
if ( V_201 -> V_292 -> V_311 -> V_316 == NULL )
return - V_19 ;
V_18 = F_119 ( V_5 , 0 , & V_315 ) ;
if ( V_18 < 0 ) {
F_25 ( L_236 , V_18 ) ;
return V_18 ;
}
if ( V_201 -> V_317 ) {
F_25 ( L_237 ) ;
return - V_19 ;
}
V_18 = V_201 -> V_292 -> V_311 -> V_316 ( V_201 , V_315 ) ;
if ( V_18 < 0 )
return - V_19 ;
if ( V_18 > 0 )
V_201 -> V_313 |= V_314 ;
else if ( V_18 == 0 )
V_201 -> V_313 &= ~ V_314 ;
return V_73 ;
}
static void F_177 ( struct V_2 * V_3 )
{
struct V_1 * V_201 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_178 ( V_201 ) ;
}
static struct V_16 * F_179 (
struct V_16 * V_17 ,
const char * V_11 )
{
char * V_318 , * V_319 , * V_320 ;
struct V_1 * V_201 ;
char V_113 [ V_321 ] ;
unsigned long V_322 = 0 ;
int V_18 ;
memset ( V_113 , 0 , V_321 ) ;
if ( strlen ( V_11 ) >= V_321 ) {
F_25 ( L_238
L_239 , ( int ) strlen ( V_11 ) ,
V_321 ) ;
return F_14 ( - V_323 ) ;
}
snprintf ( V_113 , V_321 , L_53 , V_11 ) ;
V_319 = strstr ( V_113 , L_240 ) ;
if ( ! V_319 ) {
F_25 ( L_241 ) ;
return F_14 ( - V_19 ) ;
}
V_318 = V_113 ;
V_320 = strstr ( V_319 + 1 , L_240 ) ;
if ( V_320 ) {
* V_320 = '\0' ;
V_320 ++ ;
V_319 = V_320 ;
} else {
* V_319 = '\0' ;
V_319 ++ ;
}
V_18 = F_119 ( V_319 , 0 , & V_322 ) ;
if ( V_18 < 0 ) {
F_25 ( L_186
L_242 , V_18 ) ;
return F_14 ( V_18 ) ;
}
F_180 () ;
V_201 = F_181 ( V_318 , V_322 , 0 ) ;
if ( F_109 ( V_201 ) )
return F_182 ( V_201 ) ;
F_15 ( & V_201 -> V_4 , V_11 ,
& V_324 ) ;
return & V_201 -> V_4 ;
}
static void F_183 (
struct V_16 * V_17 ,
struct V_2 * V_3 )
{
F_19 ( V_3 ) ;
}
void F_184 ( struct V_290 * V_291 )
{
F_185 ( V_291 ) ;
F_186 ( V_291 ) ;
F_187 ( V_291 ) ;
F_188 ( V_291 ) ;
F_189 ( V_291 ) ;
F_190 ( V_291 ) ;
}
static int T_8 F_191 ( void )
{
struct V_16 * V_325 , * V_326 = NULL , * V_327 = NULL ;
struct V_16 * V_328 = NULL ;
struct V_329 * V_330 = & V_30 ;
struct V_207 * V_208 ;
int V_18 ;
F_12 ( L_243
L_244 V_6 L_3 ,
V_7 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
F_192 ( & V_330 -> V_331 ) ;
F_193 ( & V_330 -> V_332 ) ;
V_18 = F_194 () ;
if ( V_18 < 0 )
return V_18 ;
V_325 = & V_330 -> V_331 ;
V_325 -> V_22 = F_170 ( sizeof( struct V_16 * ) * 2 ,
V_59 ) ;
if ( ! V_325 -> V_22 ) {
F_25 ( L_245 ) ;
V_18 = - V_61 ;
goto V_333;
}
F_15 ( & V_334 ,
L_246 , & V_335 ) ;
V_325 -> V_22 [ 0 ] = & V_334 ;
V_325 -> V_22 [ 1 ] = NULL ;
V_326 = & V_334 ;
V_326 -> V_22 = F_170 ( sizeof( struct V_16 * ) * 2 ,
V_59 ) ;
if ( ! V_326 -> V_22 ) {
F_25 ( L_247 ) ;
V_18 = - V_61 ;
goto V_333;
}
F_15 ( & V_336 ,
L_229 , & V_337 ) ;
V_326 -> V_22 [ 0 ] = & V_336 ;
V_326 -> V_22 [ 1 ] = NULL ;
V_327 = & V_336 ;
V_327 -> V_22 = F_170 ( sizeof( struct V_16 * ) * 2 ,
V_59 ) ;
if ( ! V_327 -> V_22 ) {
F_25 ( L_248 ) ;
V_18 = - V_61 ;
goto V_333;
}
F_15 ( & V_338 ,
L_249 , & V_339 ) ;
V_327 -> V_22 [ 0 ] = & V_338 ;
V_327 -> V_22 [ 1 ] = NULL ;
V_208 = F_125 ( L_250 , 1 ) ;
if ( F_109 ( V_208 ) ) {
V_18 = - V_61 ;
goto V_333;
}
V_328 = & V_338 ;
V_328 -> V_22 = F_170 ( sizeof( struct V_16 * ) * 2 ,
V_59 ) ;
if ( ! V_328 -> V_22 ) {
F_25 ( L_251 ) ;
V_18 = - V_61 ;
goto V_333;
}
F_15 ( & V_208 -> V_213 , L_250 ,
& V_257 ) ;
V_328 -> V_22 [ 0 ] = & V_208 -> V_213 ;
V_328 -> V_22 [ 1 ] = NULL ;
V_340 = V_208 ;
V_18 = F_195 ( V_330 ) ;
if ( V_18 < 0 ) {
F_25 ( L_252 ,
V_18 , V_330 -> V_331 . V_26 . V_341 ) ;
goto V_333;
}
F_12 ( L_253
L_254 V_7 L_255
L_256 V_6 L_3 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
V_18 = F_196 () ;
if ( V_18 < 0 )
goto V_177;
V_18 = F_197 () ;
if ( V_18 < 0 )
goto V_177;
V_18 = F_198 () ;
if ( V_18 < 0 )
goto V_177;
return 0 ;
V_177:
F_199 ( V_330 ) ;
F_200 () ;
F_201 () ;
V_333:
if ( V_340 ) {
F_123 ( V_340 ) ;
V_340 = NULL ;
}
if ( V_328 )
F_37 ( V_328 -> V_22 ) ;
if ( V_327 )
F_37 ( V_327 -> V_22 ) ;
if ( V_326 )
F_37 ( V_326 -> V_22 ) ;
F_37 ( V_325 -> V_22 ) ;
F_202 () ;
return V_18 ;
}
static void T_9 F_203 ( void )
{
struct V_16 * V_326 , * V_327 , * V_328 ;
struct V_2 * V_3 ;
int V_29 ;
V_328 = & V_338 ;
for ( V_29 = 0 ; V_328 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_3 = & V_328 -> V_22 [ V_29 ] -> V_26 ;
V_328 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_3 ) ;
}
F_37 ( V_328 -> V_22 ) ;
V_328 -> V_22 = NULL ;
V_327 = & V_336 ;
for ( V_29 = 0 ; V_327 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_3 = & V_327 -> V_22 [ V_29 ] -> V_26 ;
V_327 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_3 ) ;
}
F_37 ( V_327 -> V_22 ) ;
V_327 -> V_22 = NULL ;
V_326 = & V_334 ;
for ( V_29 = 0 ; V_326 -> V_22 [ V_29 ] ; V_29 ++ ) {
V_3 = & V_326 -> V_22 [ V_29 ] -> V_26 ;
V_326 -> V_22 [ V_29 ] = NULL ;
F_19 ( V_3 ) ;
}
F_37 ( V_326 -> V_22 ) ;
V_326 -> V_22 = NULL ;
F_199 ( & V_30 ) ;
F_37 ( V_30 . V_331 . V_22 ) ;
F_123 ( V_340 ) ;
V_340 = NULL ;
F_12 ( L_257
L_258 ) ;
F_200 () ;
F_201 () ;
F_204 () ;
F_202 () ;
}
