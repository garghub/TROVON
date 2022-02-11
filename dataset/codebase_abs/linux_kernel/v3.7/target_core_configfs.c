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
if ( ! strcmp ( V_14 -> V_16 , V_13 ) ) {
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
if ( ! strncmp ( V_13 , L_6 , 5 ) ) {
V_20 = F_13 ( L_7 ) ;
if ( V_20 < 0 ) {
F_14 ( L_8
L_9 , V_20 ) ;
return F_15 ( - V_21 ) ;
}
} else if ( ! strncmp ( V_13 , L_10 , 8 ) ) {
V_20 = F_13 ( L_11 ) ;
if ( V_20 < 0 ) {
F_14 ( L_8
L_12 , V_20 ) ;
return F_15 ( - V_21 ) ;
}
}
V_14 = F_6 ( V_13 ) ;
if ( ! V_14 ) {
F_14 ( L_13 ,
V_13 ) ;
return F_15 ( - V_21 ) ;
}
F_12 ( L_14
L_5 , V_14 -> V_16 ) ;
F_12 ( L_15 ,
& F_16 ( V_14 ) -> V_22 ) ;
V_14 -> V_23 . V_24 = V_14 -> V_25 ;
V_14 -> V_23 . V_24 [ 0 ] = & V_14 -> V_26 ;
V_14 -> V_23 . V_24 [ 1 ] = NULL ;
F_17 ( & V_14 -> V_23 , V_13 ,
& F_16 ( V_14 ) -> V_22 ) ;
F_17 ( & V_14 -> V_26 , L_16 ,
& F_16 ( V_14 ) -> V_27 ) ;
F_12 ( L_17
L_5 , V_14 -> V_23 . V_28 . V_29 ) ;
V_14 -> V_30 . V_31 = V_14 -> V_31 ;
V_14 -> V_32 = & V_14 -> V_23 . V_28 ;
F_12 ( L_18
L_19 , V_13 ) ;
return & V_14 -> V_23 ;
}
static void F_18 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_12 * V_14 = F_2 (
F_3 ( V_3 ) , struct V_12 , V_23 ) ;
struct V_18 * V_23 ;
struct V_2 * V_33 ;
int V_34 ;
F_12 ( L_20
L_21 , F_19 ( V_3 ) ) ;
F_12 ( L_22
L_5 , V_14 -> V_16 ) ;
F_20 ( & V_14 -> V_17 ) ;
F_12 ( L_23
L_24 , V_14 -> V_16 ) ;
V_14 -> V_32 = NULL ;
F_12 ( L_25
L_5 , F_19 ( V_3 ) ) ;
V_23 = & V_14 -> V_23 ;
for ( V_34 = 0 ; V_23 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_23 -> V_24 [ V_34 ] -> V_28 ;
V_23 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_21 ( V_3 ) ;
}
struct V_12 * F_22 (
struct V_35 * V_36 ,
const char * V_13 )
{
struct V_12 * V_14 ;
if ( ! ( V_13 ) ) {
F_14 ( L_26 ) ;
return F_15 ( - V_21 ) ;
}
if ( strlen ( V_13 ) >= V_37 ) {
F_14 ( L_27
L_28 , V_13 ) ;
return F_15 ( - V_21 ) ;
}
V_14 = F_23 ( sizeof( struct V_12 ) , V_38 ) ;
if ( ! V_14 )
return F_15 ( - V_39 ) ;
F_24 ( & V_14 -> V_40 ) ;
F_25 ( & V_14 -> V_17 , 0 ) ;
V_14 -> V_41 = V_36 ;
F_26 ( V_14 ) ;
V_14 -> V_31 = V_42 [ 0 ] ;
snprintf ( V_14 -> V_16 , V_37 , L_29 , V_13 ) ;
F_7 ( & V_15 ) ;
F_27 ( & V_14 -> V_40 , & V_43 ) ;
F_10 ( & V_15 ) ;
F_12 ( L_30
L_31 ) ;
F_12 ( L_32
L_5 , V_14 , V_14 -> V_16 ) ;
return V_14 ;
}
void F_28 (
struct V_12 * V_14 )
{
F_7 ( & V_15 ) ;
F_29 ( & V_14 -> V_40 ) ;
F_10 ( & V_15 ) ;
F_30 ( V_14 ) ;
}
static int F_31 (
struct V_12 * V_14 )
{
struct V_44 * V_45 = & V_14 -> V_30 ;
if ( ! V_45 -> V_46 ) {
F_14 ( L_33 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_47 ) {
F_14 ( L_34 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_48 ) {
F_14 ( L_35 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_49 ) {
F_14 ( L_36 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_50 ) {
F_14 ( L_37 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_51 ) {
F_14 ( L_38 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_52 ) {
F_14 ( L_39 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_53 ) {
F_14 ( L_40 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_54 ) {
F_14 ( L_41 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_55 ) {
F_14 ( L_42 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_56 ) {
F_14 ( L_43 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_57 ) {
F_14 ( L_44 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_58 ) {
F_14 ( L_45 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_59 ) {
F_14 ( L_46 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_60 ) {
F_14 ( L_47 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_61 ) {
F_14 ( L_48 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_62 ) {
F_14 ( L_49 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_63 ) {
F_14 ( L_50 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_64 ) {
F_14 ( L_51 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_65 ) {
F_14 ( L_52 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_66 ) {
F_14 ( L_53 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_67 ) {
F_14 ( L_54 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_68 ) {
F_14 ( L_55 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_69 ) {
F_14 ( L_56 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_70 ) {
F_14 ( L_57 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_71 ) {
F_14 ( L_58 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_72 ) {
F_14 ( L_59 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_73 ) {
F_14 ( L_60 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_74 ) {
F_14 ( L_61 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_75 ) {
F_14 ( L_62 ) ;
return - V_21 ;
}
return 0 ;
}
int F_32 (
struct V_12 * V_14 )
{
int V_20 ;
if ( ! V_14 ) {
F_14 ( L_63
L_64 ) ;
return - V_21 ;
}
if ( ! V_14 -> V_31 ) {
F_14 ( L_65
L_64 ) ;
return - V_21 ;
}
V_20 = F_31 ( V_14 ) ;
if ( V_20 < 0 )
return V_20 ;
F_12 ( L_66
L_67 ) ;
return 0 ;
}
void F_33 (
struct V_12 * V_14 )
{
struct V_76 * V_77 ;
if ( ! V_14 ) {
F_14 ( L_68
L_69 ) ;
return;
}
V_77 = V_14 -> V_31 ;
if ( ! V_77 ) {
F_14 ( L_70
L_64 ) ;
return;
}
F_12 ( L_71
L_72 ) ;
F_7 ( & V_15 ) ;
if ( F_34 ( & V_14 -> V_17 ) ) {
F_10 ( & V_15 ) ;
F_14 ( L_73 ,
V_14 -> V_16 ) ;
F_35 () ;
}
F_29 ( & V_14 -> V_40 ) ;
F_10 ( & V_15 ) ;
F_12 ( L_74
L_5 , V_14 -> V_16 ) ;
V_14 -> V_41 = NULL ;
V_14 -> V_31 = NULL ;
F_30 ( V_14 ) ;
F_12 ( L_75
L_76 ) ;
}
static T_1 F_36 (
struct V_78 * V_78 ,
char * V_7 )
{
struct V_79 * V_80 = V_78 -> V_81 ;
struct V_82 * V_83 ;
V_83 = V_80 -> V_84 ;
if ( ! V_83 )
return - V_85 ;
return sprintf ( V_7 , L_77 ,
& V_78 -> V_86 [ 0 ] ) ;
}
static T_1 F_37 (
struct V_78 * V_78 ,
const char * V_7 ,
T_2 V_87 )
{
struct V_79 * V_88 = V_78 -> V_81 ;
struct V_82 * V_83 ;
unsigned char V_89 [ V_90 ] ;
if ( V_88 -> V_91 & V_92 ) {
F_14 ( L_78
L_79 ) ;
return - V_93 ;
}
if ( strlen ( V_7 ) >= V_90 ) {
F_14 ( L_80
L_81 , V_90 ) ;
return - V_94 ;
}
V_83 = V_88 -> V_84 ;
if ( V_83 ) {
if ( F_34 ( & V_83 -> V_95 . V_96 ) ) {
F_14 ( L_82
L_83 ,
F_34 ( & V_83 -> V_95 . V_96 ) ) ;
return - V_21 ;
}
}
memset ( V_89 , 0 , V_90 ) ;
snprintf ( V_89 , V_90 , L_29 , V_7 ) ;
snprintf ( V_88 -> V_78 . V_86 , V_90 ,
L_29 , F_38 ( V_89 ) ) ;
V_88 -> V_91 |= V_97 ;
F_12 ( L_84
L_5 , V_88 -> V_78 . V_86 ) ;
return V_87 ;
}
static T_1 F_39 (
struct V_78 * V_78 ,
char * V_7 )
{
struct V_79 * V_80 = V_78 -> V_81 ;
struct V_82 * V_83 ;
struct V_98 * V_99 ;
unsigned char V_89 [ V_100 ] ;
T_1 V_101 = 0 ;
V_83 = V_80 -> V_84 ;
if ( ! V_83 )
return - V_85 ;
memset ( V_89 , 0 , V_100 ) ;
F_40 ( & V_78 -> V_102 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_99 -> V_103 )
continue;
F_41 ( V_99 , V_89 , V_100 ) ;
if ( V_101 + strlen ( V_89 ) >= V_104 )
break;
V_101 += sprintf ( V_7 + V_101 , L_29 , V_89 ) ;
}
F_42 ( & V_78 -> V_102 ) ;
return V_101 ;
}
static T_1 F_43 (
struct V_78 * V_78 ,
const char * V_7 ,
T_2 V_87 )
{
return - V_105 ;
}
static T_1 F_44 (
struct V_78 * V_78 ,
const char * V_7 ,
T_2 V_87 )
{
return - V_105 ;
}
static T_1 F_45 (
struct V_78 * V_78 ,
const char * V_7 ,
T_2 V_87 )
{
return - V_105 ;
}
static T_1 F_46 (
struct V_78 * V_78 ,
const char * V_7 ,
T_2 V_87 )
{
return - V_105 ;
}
static T_1 F_47 (
struct V_82 * V_83 ,
char * V_7 ,
T_1 * V_101 )
{
struct V_106 * V_107 ;
struct V_108 * V_109 ;
char V_110 [ V_111 ] ;
int V_112 ;
memset ( V_110 , 0 , V_111 ) ;
F_40 ( & V_83 -> V_113 ) ;
V_109 = V_83 -> V_114 ;
if ( ! V_109 ) {
* V_101 += sprintf ( V_7 + * V_101 , L_85 ) ;
F_42 ( & V_83 -> V_113 ) ;
return * V_101 ;
}
V_107 = V_109 -> V_115 ;
V_112 = F_48 ( V_109 , & V_110 [ 0 ] ,
V_111 ) ;
* V_101 += sprintf ( V_7 + * V_101 , L_86 ,
V_107 -> V_116 -> V_117 -> V_46 () ,
V_107 -> V_118 , ( V_112 ) ? & V_110 [ 0 ] : L_87 ) ;
F_42 ( & V_83 -> V_113 ) ;
return * V_101 ;
}
static T_1 F_49 (
struct V_82 * V_83 ,
char * V_7 ,
T_1 * V_101 )
{
struct V_106 * V_107 ;
F_40 ( & V_83 -> V_113 ) ;
V_107 = V_83 -> V_119 ;
if ( ! V_107 ) {
* V_101 += sprintf ( V_7 + * V_101 , L_88 ) ;
F_42 ( & V_83 -> V_113 ) ;
return * V_101 ;
}
* V_101 += sprintf ( V_7 + * V_101 , L_89 ,
V_107 -> V_116 -> V_117 -> V_46 () ,
V_107 -> V_118 ) ;
F_42 ( & V_83 -> V_113 ) ;
return * V_101 ;
}
static T_1 F_50 (
struct V_79 * V_88 ,
char * V_7 )
{
T_1 V_101 = 0 ;
if ( ! V_88 -> V_84 )
return - V_85 ;
switch ( V_88 -> V_120 . V_121 ) {
case V_122 :
F_47 ( V_88 -> V_84 ,
V_7 , & V_101 ) ;
break;
case V_123 :
F_49 ( V_88 -> V_84 ,
V_7 , & V_101 ) ;
break;
case V_124 :
V_101 += sprintf ( V_7 + V_101 , L_90 ) ;
break;
default:
V_101 += sprintf ( V_7 + V_101 , L_91 ) ;
break;
}
return V_101 ;
}
static T_1 F_51 (
struct V_79 * V_88 ,
char * V_7 )
{
struct V_82 * V_83 ;
struct V_108 * V_109 ;
T_1 V_101 = 0 ;
V_83 = V_88 -> V_84 ;
if ( ! V_83 )
return - V_85 ;
if ( V_88 -> V_120 . V_121 != V_122 )
return V_101 ;
F_40 ( & V_83 -> V_113 ) ;
V_109 = V_83 -> V_114 ;
if ( ! V_109 ) {
V_101 = sprintf ( V_7 , L_85 ) ;
F_42 ( & V_83 -> V_113 ) ;
return V_101 ;
}
if ( V_109 -> V_125 )
V_101 = sprintf ( V_7 , L_92
L_93 ) ;
else
V_101 = sprintf ( V_7 , L_94
L_95 ) ;
F_42 ( & V_83 -> V_113 ) ;
return V_101 ;
}
static T_1 F_52 (
struct V_79 * V_88 ,
char * V_7 )
{
if ( ! V_88 -> V_84 )
return - V_85 ;
if ( V_88 -> V_120 . V_121 != V_122 )
return 0 ;
return sprintf ( V_7 , L_96 , V_88 -> V_120 . V_126 ) ;
}
static T_1 F_53 (
struct V_79 * V_88 ,
char * V_7 )
{
struct V_82 * V_83 ;
struct V_106 * V_107 ;
struct V_127 * V_128 ;
struct V_129 * V_116 ;
struct V_108 * V_109 ;
struct V_44 * V_45 ;
T_1 V_101 = 0 ;
V_83 = V_88 -> V_84 ;
if ( ! V_83 )
return - V_85 ;
if ( V_88 -> V_120 . V_121 != V_122 )
return V_101 ;
F_40 ( & V_83 -> V_113 ) ;
V_109 = V_83 -> V_114 ;
if ( ! V_109 ) {
V_101 = sprintf ( V_7 , L_85 ) ;
F_42 ( & V_83 -> V_113 ) ;
return V_101 ;
}
V_107 = V_109 -> V_115 ;
V_116 = V_107 -> V_116 ;
V_128 = V_109 -> V_130 ;
V_45 = V_116 -> V_117 ;
V_101 += sprintf ( V_7 + V_101 , L_97
L_98 , V_45 -> V_46 () ,
V_45 -> V_48 ( V_116 ) ) ;
V_101 += sprintf ( V_7 + V_101 , L_99
L_100
L_101 , V_128 -> V_131 -> V_132 ,
V_45 -> V_46 () , V_45 -> V_49 ( V_116 ) ,
V_45 -> V_46 () , V_128 -> V_133 ) ;
F_42 ( & V_83 -> V_113 ) ;
return V_101 ;
}
static T_1 F_54 (
struct V_79 * V_88 ,
char * V_7 )
{
struct V_44 * V_45 ;
struct V_108 * V_109 ;
unsigned char V_89 [ 384 ] ;
char V_110 [ V_111 ] ;
T_1 V_101 = 0 ;
int V_134 = 0 , V_112 ;
if ( ! V_88 -> V_84 )
return - V_85 ;
if ( V_88 -> V_120 . V_121 != V_122 )
return V_101 ;
V_101 += sprintf ( V_7 + V_101 , L_102 ) ;
F_40 ( & V_88 -> V_120 . V_135 ) ;
F_8 (pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_89 , 0 , 384 ) ;
memset ( V_110 , 0 , V_111 ) ;
V_45 = V_109 -> V_115 -> V_116 -> V_117 ;
V_112 = F_48 ( V_109 , & V_110 [ 0 ] ,
V_111 ) ;
sprintf ( V_89 , L_103 ,
V_45 -> V_46 () ,
V_109 -> V_115 -> V_118 , ( V_112 ) ?
& V_110 [ 0 ] : L_87 , V_109 -> V_136 ,
V_109 -> V_137 ) ;
if ( V_101 + strlen ( V_89 ) >= V_104 )
break;
V_101 += sprintf ( V_7 + V_101 , L_29 , V_89 ) ;
V_134 ++ ;
}
F_42 ( & V_88 -> V_120 . V_135 ) ;
if ( ! V_134 )
V_101 += sprintf ( V_7 + V_101 , L_104 ) ;
return V_101 ;
}
static T_1 F_55 (
struct V_79 * V_88 ,
char * V_7 )
{
struct V_82 * V_83 ;
struct V_108 * V_109 ;
T_1 V_101 = 0 ;
V_83 = V_88 -> V_84 ;
if ( ! V_83 )
return - V_85 ;
if ( V_88 -> V_120 . V_121 != V_122 )
return V_101 ;
F_40 ( & V_83 -> V_113 ) ;
V_109 = V_83 -> V_114 ;
if ( ! V_109 ) {
V_101 = sprintf ( V_7 , L_85 ) ;
F_42 ( & V_83 -> V_113 ) ;
return V_101 ;
}
V_101 = sprintf ( V_7 , L_105 ,
F_56 ( V_109 -> V_138 ) ) ;
F_42 ( & V_83 -> V_113 ) ;
return V_101 ;
}
static T_1 F_57 (
struct V_79 * V_88 ,
char * V_7 )
{
T_1 V_101 = 0 ;
if ( ! V_88 -> V_84 )
return - V_85 ;
switch ( V_88 -> V_120 . V_121 ) {
case V_122 :
V_101 = sprintf ( V_7 , L_106 ) ;
break;
case V_123 :
V_101 = sprintf ( V_7 , L_107 ) ;
break;
case V_124 :
V_101 = sprintf ( V_7 , L_108 ) ;
break;
default:
V_101 = sprintf ( V_7 , L_109 ) ;
break;
}
return V_101 ;
}
static T_1 F_58 (
struct V_79 * V_88 ,
char * V_7 )
{
if ( ! V_88 -> V_84 )
return - V_85 ;
if ( V_88 -> V_120 . V_121 != V_122 )
return 0 ;
return sprintf ( V_7 , L_110 ,
( V_88 -> V_120 . V_139 ) ? L_111 : L_112 ) ;
}
static T_1 F_59 (
struct V_79 * V_88 ,
char * V_7 )
{
if ( ! V_88 -> V_84 )
return - V_85 ;
if ( V_88 -> V_120 . V_121 != V_122 )
return 0 ;
return sprintf ( V_7 , L_113 ) ;
}
static T_1 F_60 (
struct V_79 * V_88 ,
const char * V_7 ,
T_2 V_87 )
{
struct V_82 * V_83 ;
unsigned char * V_140 = NULL , * V_141 = NULL , * V_142 = NULL ;
unsigned char * V_143 = NULL , * V_144 = NULL ;
char * V_145 , * V_146 , * V_147 , * V_148 ;
T_3 args [ V_149 ] ;
unsigned long long V_150 ;
T_4 V_151 = 0 ;
T_5 V_152 = 0 , V_153 = 0 ;
int V_20 = - 1 , V_154 = 0 , V_155 = 0 , V_156 , V_157 ;
T_6 V_158 = 0 , V_159 = 0 ;
T_7 type = 0 , V_160 ;
V_83 = V_88 -> V_84 ;
if ( ! V_83 )
return - V_85 ;
if ( V_88 -> V_120 . V_121 != V_122 )
return 0 ;
if ( F_34 ( & V_83 -> V_95 . V_96 ) ) {
F_12 ( L_114
L_115 ) ;
return - V_21 ;
}
V_148 = F_61 ( V_7 , V_38 ) ;
if ( ! V_148 )
return - V_39 ;
V_145 = V_148 ;
while ( ( V_146 = F_62 ( & V_148 , L_116 ) ) != NULL ) {
if ( ! * V_146 )
continue;
V_157 = F_63 ( V_146 , V_161 , args ) ;
switch ( V_157 ) {
case V_162 :
V_140 = F_64 ( & args [ 0 ] ) ;
if ( ! V_140 ) {
V_20 = - V_39 ;
goto V_163;
}
break;
case V_164 :
V_141 = F_64 ( & args [ 0 ] ) ;
if ( ! V_141 ) {
V_20 = - V_39 ;
goto V_163;
}
if ( strlen ( V_141 ) >= V_165 ) {
F_14 ( L_117
L_118 ,
V_165 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_166 :
V_142 = F_64 ( & args [ 0 ] ) ;
if ( ! V_142 ) {
V_20 = - V_39 ;
goto V_163;
}
if ( strlen ( V_142 ) >= V_167 ) {
F_14 ( L_119
L_120 ,
V_167 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_168 :
V_147 = F_64 ( & args [ 0 ] ) ;
if ( ! V_147 ) {
V_20 = - V_39 ;
goto V_163;
}
V_20 = F_65 ( V_147 , 0 , & V_150 ) ;
if ( V_20 < 0 ) {
F_14 ( L_121
L_122 ) ;
goto V_163;
}
V_151 = ( T_4 ) V_150 ;
break;
case V_169 :
F_66 ( args , & V_156 ) ;
V_154 = V_156 ;
break;
case V_170 :
F_66 ( args , & V_156 ) ;
type = ( T_7 ) V_156 ;
break;
case V_171 :
F_66 ( args , & V_156 ) ;
V_160 = ( T_7 ) V_156 ;
break;
case V_172 :
F_66 ( args , & V_156 ) ;
V_155 = ( int ) V_156 ;
break;
case V_173 :
F_66 ( args , & V_156 ) ;
V_152 = ( T_5 ) V_156 ;
break;
case V_174 :
V_143 = F_64 ( & args [ 0 ] ) ;
if ( ! V_143 ) {
V_20 = - V_39 ;
goto V_163;
}
break;
case V_175 :
V_144 = F_64 ( & args [ 0 ] ) ;
if ( ! V_144 ) {
V_20 = - V_39 ;
goto V_163;
}
if ( strlen ( V_144 ) >= V_176 ) {
F_14 ( L_123
L_124 ,
V_176 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_177 :
F_66 ( args , & V_156 ) ;
V_159 = ( T_6 ) V_156 ;
break;
case V_178 :
F_66 ( args , & V_156 ) ;
V_158 = ( T_6 ) V_156 ;
break;
case V_179 :
F_66 ( args , & V_156 ) ;
V_153 = ( T_5 ) V_156 ;
break;
default:
break;
}
}
if ( ! V_141 || ! V_144 || ! V_151 ) {
F_14 ( L_125 ) ;
V_20 = - V_21 ;
goto V_163;
}
if ( V_154 && ! ( type ) ) {
F_14 ( L_126
L_127 , type ) ;
V_20 = - V_21 ;
goto V_163;
}
V_20 = F_67 ( & V_88 -> V_120 , V_151 ,
V_141 , V_142 , V_152 , V_144 , V_159 , V_153 ,
V_154 , V_155 , type ) ;
V_163:
F_30 ( V_140 ) ;
F_30 ( V_141 ) ;
F_30 ( V_142 ) ;
F_30 ( V_143 ) ;
F_30 ( V_144 ) ;
F_30 ( V_145 ) ;
return ( V_20 == 0 ) ? V_87 : V_20 ;
}
static T_1 F_68 ( void * V_180 , char * V_7 )
{
struct V_79 * V_80 = V_180 ;
struct V_1 * V_181 = V_80 -> V_182 ;
struct V_183 * V_184 = V_181 -> V_185 ;
int V_186 = 0 ;
T_1 V_187 = 0 ;
if ( ! V_80 -> V_84 )
return - V_85 ;
F_69 ( V_80 -> V_84 , V_7 , & V_186 ) ;
V_187 += V_186 ;
V_187 += V_184 -> V_188 ( V_181 , V_80 , V_7 + V_187 ) ;
return V_187 ;
}
static T_1 F_70 (
void * V_180 ,
const char * V_7 ,
T_2 V_87 )
{
struct V_79 * V_80 = V_180 ;
struct V_1 * V_181 = V_80 -> V_182 ;
struct V_183 * V_184 = V_181 -> V_185 ;
if ( ! V_80 -> V_189 ) {
F_14 ( L_128
L_129 ) ;
return - V_21 ;
}
return V_184 -> V_190 ( V_181 , V_80 , V_7 , V_87 ) ;
}
static T_1 F_71 ( void * V_180 , char * V_7 )
{
struct V_79 * V_80 = V_180 ;
if ( ! ( V_80 -> V_91 & V_191 ) )
return 0 ;
return snprintf ( V_7 , V_104 , L_130 , V_80 -> V_192 ) ;
}
static T_1 F_72 (
void * V_180 ,
const char * V_7 ,
T_2 V_87 )
{
struct V_79 * V_80 = V_180 ;
struct V_1 * V_181 = V_80 -> V_182 ;
T_1 V_187 ;
if ( V_87 > ( V_193 - 1 ) ) {
F_14 ( L_131
L_132 , ( int ) V_87 ,
V_193 - 1 ) ;
return - V_21 ;
}
V_187 = snprintf ( & V_80 -> V_192 [ 0 ] , V_193 ,
L_29 , V_7 ) ;
if ( ! V_187 )
return - V_21 ;
if ( V_80 -> V_192 [ V_187 - 1 ] == '\n' )
V_80 -> V_192 [ V_187 - 1 ] = '\0' ;
V_80 -> V_91 |= V_191 ;
F_12 ( L_133 ,
F_19 ( & V_181 -> V_4 . V_28 ) ,
F_19 ( & V_80 -> V_194 . V_28 ) ,
V_80 -> V_192 ) ;
return V_187 ;
}
static T_1 F_73 ( void * V_180 , char * V_7 )
{
struct V_79 * V_80 = V_180 ;
if ( ! ( V_80 -> V_91 & V_195 ) )
return 0 ;
return snprintf ( V_7 , V_104 , L_130 , V_80 -> V_196 ) ;
}
static T_1 F_74 (
void * V_180 ,
const char * V_7 ,
T_2 V_87 )
{
struct V_79 * V_80 = V_180 ;
struct V_1 * V_181 = V_80 -> V_182 ;
T_1 V_187 ;
if ( V_87 > ( V_197 - 1 ) ) {
F_14 ( L_134
L_135 , ( int ) V_87 ,
V_197 - 1 ) ;
return - V_21 ;
}
V_187 = snprintf ( & V_80 -> V_196 [ 0 ] , V_197 ,
L_29 , V_7 ) ;
if ( ! V_187 )
return - V_21 ;
if ( V_80 -> V_196 [ V_187 - 1 ] == '\n' )
V_80 -> V_196 [ V_187 - 1 ] = '\0' ;
V_80 -> V_91 |= V_195 ;
F_12 ( L_136 ,
F_19 ( & V_181 -> V_4 . V_28 ) ,
F_19 ( & V_80 -> V_194 . V_28 ) ,
V_80 -> V_196 ) ;
return V_187 ;
}
static T_1 F_75 (
void * V_180 ,
const char * V_7 ,
T_2 V_87 )
{
struct V_79 * V_80 = V_180 ;
struct V_82 * V_83 ;
struct V_1 * V_181 = V_80 -> V_182 ;
struct V_183 * V_184 = V_181 -> V_185 ;
char * V_146 ;
V_146 = strstr ( V_7 , L_137 ) ;
if ( ! V_146 ) {
F_14 ( L_138
L_139 ) ;
return - V_21 ;
}
if ( V_80 -> V_84 ) {
F_14 ( L_140
L_141 ) ;
return - V_198 ;
}
if ( V_184 -> V_199 ( V_181 , V_80 ) < 0 )
return - V_21 ;
V_83 = V_184 -> V_200 ( V_181 , V_80 , V_80 -> V_189 ) ;
if ( F_76 ( V_83 ) )
return F_77 ( V_83 ) ;
else if ( ! V_83 )
return - V_21 ;
V_80 -> V_84 = V_83 ;
F_12 ( L_142
L_143 , V_80 -> V_84 ) ;
return V_87 ;
}
static T_1 F_78 ( void * V_180 , char * V_7 )
{
struct V_82 * V_83 ;
struct V_79 * V_88 = V_180 ;
struct V_2 * V_201 ;
struct V_202 * V_203 ;
struct V_204 * V_205 ;
T_1 V_101 = 0 ;
V_83 = V_88 -> V_84 ;
if ( ! V_83 )
return - V_85 ;
if ( V_88 -> V_206 . V_207 != V_208 )
return V_101 ;
V_205 = V_83 -> V_209 ;
if ( ! V_205 ) {
F_14 ( L_144
L_64 ) ;
return - V_21 ;
}
F_40 ( & V_205 -> V_210 ) ;
V_203 = V_205 -> V_203 ;
if ( V_203 ) {
V_201 = & V_203 -> V_211 . V_28 ;
V_101 += sprintf ( V_7 , L_145 ,
F_19 ( V_201 ) , V_203 -> V_212 ) ;
}
F_42 ( & V_205 -> V_210 ) ;
return V_101 ;
}
static T_1 F_79 (
void * V_180 ,
const char * V_7 ,
T_2 V_87 )
{
struct V_82 * V_83 ;
struct V_79 * V_88 = V_180 ;
struct V_1 * V_181 = V_88 -> V_182 ;
struct V_202 * V_203 = NULL , * V_213 = NULL ;
struct V_204 * V_205 ;
unsigned char V_89 [ V_214 ] ;
int V_215 = 0 ;
V_83 = V_88 -> V_84 ;
if ( ! V_83 )
return - V_85 ;
if ( V_88 -> V_206 . V_207 != V_208 ) {
F_80 ( L_146 ,
F_19 ( & V_181 -> V_4 . V_28 ) ,
F_19 ( & V_88 -> V_194 . V_28 ) ) ;
return - V_21 ;
}
if ( V_87 > V_214 ) {
F_14 ( L_147 ) ;
return - V_21 ;
}
memset ( V_89 , 0 , V_214 ) ;
memcpy ( V_89 , V_7 , V_87 ) ;
if ( strcmp ( F_38 ( V_89 ) , L_148 ) ) {
V_213 = F_81 ( F_38 ( V_89 ) ) ;
if ( ! V_213 )
return - V_85 ;
}
V_205 = V_83 -> V_209 ;
if ( ! V_205 ) {
if ( V_213 )
F_82 ( V_213 ) ;
F_14 ( L_144
L_64 ) ;
return - V_21 ;
}
F_40 ( & V_205 -> V_210 ) ;
V_203 = V_205 -> V_203 ;
if ( V_203 ) {
if ( ! V_213 ) {
F_12 ( L_149
L_150
L_151 ,
F_19 ( & V_181 -> V_4 . V_28 ) ,
F_19 ( & V_88 -> V_194 . V_28 ) ,
F_19 ( & V_203 -> V_211 . V_28 ) ,
V_203 -> V_212 ) ;
F_83 ( V_205 , V_203 ) ;
F_42 ( & V_205 -> V_210 ) ;
return V_87 ;
}
F_83 ( V_205 , V_203 ) ;
V_215 = 1 ;
}
F_84 ( V_205 , V_213 ) ;
F_42 ( & V_205 -> V_210 ) ;
F_12 ( L_152
L_153 ,
( V_215 ) ? L_154 : L_155 ,
F_19 ( & V_181 -> V_4 . V_28 ) ,
F_19 ( & V_88 -> V_194 . V_28 ) ,
F_19 ( & V_213 -> V_211 . V_28 ) ,
V_213 -> V_212 ) ;
F_82 ( V_213 ) ;
return V_87 ;
}
static void F_85 ( struct V_2 * V_3 )
{
struct V_79 * V_80 = F_2 ( F_3 ( V_3 ) ,
struct V_79 , V_194 ) ;
struct V_1 * V_181 = F_1 ( & V_80 -> V_182 -> V_4 . V_28 ) ;
struct V_183 * V_184 = V_181 -> V_185 ;
struct V_18 * V_216 = & V_80 -> V_194 ;
F_30 ( V_216 -> V_24 ) ;
if ( V_80 -> V_84 ) {
F_12 ( L_156
L_157 ,
V_80 -> V_84 ) ;
F_86 ( V_80 -> V_84 , V_181 ) ;
} else {
F_12 ( L_158
L_159 ,
V_80 -> V_189 ) ;
V_184 -> V_217 ( V_80 -> V_189 ) ;
}
F_12 ( L_160
L_161 , V_80 ) ;
F_30 ( V_80 ) ;
}
static T_1 F_87 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
char * V_7 )
{
struct V_79 * V_80 = F_2 (
F_3 ( V_3 ) , struct V_79 ,
V_194 ) ;
struct V_218 * V_219 = F_2 (
V_6 , struct V_218 , V_6 ) ;
if ( ! V_219 -> V_220 )
return - V_21 ;
return V_219 -> V_220 ( V_80 , V_7 ) ;
}
static T_1 F_88 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
const char * V_7 , T_2 V_87 )
{
struct V_79 * V_80 = F_2 (
F_3 ( V_3 ) , struct V_79 ,
V_194 ) ;
struct V_218 * V_219 = F_2 (
V_6 , struct V_218 , V_6 ) ;
if ( ! V_219 -> V_221 )
return - V_21 ;
return V_219 -> V_221 ( V_80 , V_7 , V_87 ) ;
}
static T_1 F_89 (
struct V_202 * V_203 ,
char * V_7 )
{
if ( ! V_203 -> V_222 )
return 0 ;
return sprintf ( V_7 , L_162 , V_203 -> V_212 ) ;
}
static T_1 F_90 (
struct V_202 * V_203 ,
const char * V_7 ,
T_2 V_87 )
{
struct V_18 * V_223 = & V_203 -> V_211 ;
unsigned long V_212 ;
int V_20 ;
V_20 = F_91 ( V_7 , 0 , & V_212 ) ;
if ( V_20 < 0 ) {
F_14 ( L_163
L_164 , V_20 ) ;
return - V_21 ;
}
if ( V_212 > 0x0000ffff ) {
F_14 ( L_165
L_166 , V_212 ) ;
return - V_21 ;
}
V_20 = F_92 ( V_203 , ( T_6 ) V_212 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_167
L_168 ,
F_19 ( & V_223 -> V_28 ) ,
V_203 -> V_212 ) ;
return V_87 ;
}
static T_1 F_93 (
struct V_202 * V_203 ,
char * V_7 )
{
struct V_82 * V_83 ;
struct V_1 * V_181 ;
struct V_79 * V_88 ;
struct V_204 * V_205 ;
T_1 V_101 = 0 , V_224 ;
unsigned char V_89 [ V_214 ] ;
memset ( V_89 , 0 , V_214 ) ;
F_40 ( & V_203 -> V_225 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_83 = V_205 -> V_226 ;
V_88 = V_83 -> V_227 ;
V_181 = V_88 -> V_182 ;
V_224 = snprintf ( V_89 , V_214 , L_169 ,
F_19 ( & V_181 -> V_4 . V_28 ) ,
F_19 ( & V_88 -> V_194 . V_28 ) ) ;
V_224 ++ ;
if ( ( V_224 + V_101 ) > V_104 ) {
F_80 ( L_170
L_171 ) ;
break;
}
memcpy ( V_7 + V_101 , V_89 , V_224 ) ;
V_101 += V_224 ;
}
F_42 ( & V_203 -> V_225 ) ;
return V_101 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_202 * V_203 = F_2 ( F_3 ( V_3 ) ,
struct V_202 , V_211 ) ;
F_95 ( V_203 ) ;
}
static struct V_18 * F_96 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_202 * V_203 ;
struct V_18 * V_223 = NULL ;
struct V_2 * V_228 = NULL ;
V_203 = F_97 ( V_13 , 0 ) ;
if ( F_76 ( V_203 ) )
return NULL ;
V_223 = & V_203 -> V_211 ;
V_228 = & V_223 -> V_28 ;
F_17 ( V_223 , V_13 ,
& V_229 ) ;
F_12 ( L_172
L_173 ,
F_19 ( V_228 ) ) ;
return V_223 ;
}
static void F_98 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_202 * V_203 = F_2 ( F_3 ( V_3 ) ,
struct V_202 , V_211 ) ;
F_12 ( L_174
L_175 ,
F_19 ( V_3 ) , V_203 -> V_212 ) ;
F_21 ( V_3 ) ;
}
static T_1 F_99 (
struct V_230 * V_231 ,
char * V_7 )
{
return sprintf ( V_7 , L_176 ,
F_34 ( & V_231 -> V_232 ) ) ;
}
static T_1 F_100 (
struct V_230 * V_231 ,
const char * V_7 ,
T_2 V_87 )
{
struct V_79 * V_88 = V_231 -> V_233 ;
unsigned long V_234 ;
int V_235 , V_20 ;
if ( ! V_231 -> V_236 ) {
F_14 ( L_177
L_178 , V_231 -> V_236 ) ;
return - V_21 ;
}
V_20 = F_91 ( V_7 , 0 , & V_234 ) ;
if ( V_20 < 0 ) {
F_14 ( L_179
L_5 , V_7 ) ;
return - V_21 ;
}
V_235 = ( int ) V_234 ;
if ( ! ( V_231 -> V_237 & V_238 ) ) {
F_14 ( L_180
L_181 ) ;
return - V_21 ;
}
V_20 = F_101 ( V_231 , V_88 -> V_84 ,
NULL , NULL , V_235 , 0 ) ;
return ( ! V_20 ) ? V_87 : - V_21 ;
}
static T_1 F_102 (
struct V_230 * V_231 ,
char * V_7 )
{
return sprintf ( V_7 , L_130 ,
F_103 ( V_231 -> V_239 ) ) ;
}
static T_1 F_104 (
struct V_230 * V_231 ,
const char * V_7 ,
T_2 V_87 )
{
unsigned long V_234 ;
int V_240 , V_20 ;
if ( ! V_231 -> V_236 ) {
F_14 ( L_182
L_183 ,
V_231 -> V_236 ) ;
return - V_21 ;
}
V_20 = F_91 ( V_7 , 0 , & V_234 ) ;
if ( V_20 < 0 ) {
F_14 ( L_184
L_185 , V_7 ) ;
return - V_21 ;
}
V_240 = ( int ) V_234 ;
if ( ( V_240 != V_241 ) &&
( V_240 != V_242 ) &&
( V_240 != V_243 ) ) {
F_14 ( L_186 ,
V_240 ) ;
return - V_21 ;
}
V_231 -> V_239 = V_240 ;
return V_87 ;
}
static T_1 F_105 (
struct V_230 * V_231 ,
char * V_7 )
{
return F_106 ( V_231 , V_7 ) ;
}
static T_1 F_107 (
struct V_230 * V_231 ,
const char * V_7 ,
T_2 V_87 )
{
return F_108 ( V_231 , V_7 , V_87 ) ;
}
static T_1 F_109 (
struct V_230 * V_231 ,
char * V_7 )
{
return sprintf ( V_7 , L_176 , V_231 -> V_244 ) ;
}
static T_1 F_110 (
struct V_230 * V_231 ,
const char * V_7 ,
T_2 V_87 )
{
unsigned long V_234 ;
int V_20 ;
V_20 = F_91 ( V_7 , 0 , & V_234 ) ;
if ( V_20 < 0 ) {
F_14 ( L_187 ) ;
return - V_21 ;
}
if ( ( V_234 != 0 ) && ( V_234 != 1 ) ) {
F_14 ( L_188
L_189 , V_234 ) ;
return - V_21 ;
}
V_231 -> V_244 = ( int ) V_234 ;
return V_87 ;
}
static T_1 F_111 (
struct V_230 * V_231 ,
char * V_7 )
{
return F_112 ( V_231 , V_7 ) ;
}
static T_1 F_113 (
struct V_230 * V_231 ,
const char * V_7 ,
T_2 V_87 )
{
return F_114 ( V_231 , V_7 , V_87 ) ;
}
static T_1 F_115 (
struct V_230 * V_231 ,
char * V_7 )
{
return F_116 ( V_231 , V_7 ) ;
}
static T_1 F_117 (
struct V_230 * V_231 ,
const char * V_7 ,
T_2 V_87 )
{
return F_118 ( V_231 , V_7 , V_87 ) ;
}
static T_1 F_119 (
struct V_230 * V_231 ,
char * V_7 )
{
return F_120 ( V_231 , V_7 ) ;
}
static T_1 F_121 (
struct V_230 * V_231 ,
const char * V_7 ,
T_2 V_87 )
{
return F_122 ( V_231 , V_7 , V_87 ) ;
}
static T_1 F_123 (
struct V_230 * V_231 ,
char * V_7 )
{
return F_124 ( V_231 , V_7 ) ;
}
static T_1 F_125 (
struct V_230 * V_231 ,
const char * V_7 ,
T_2 V_87 )
{
return F_126 ( V_231 , V_7 , V_87 ) ;
}
static T_1 F_127 (
struct V_230 * V_231 ,
char * V_7 )
{
if ( ! V_231 -> V_236 )
return 0 ;
return sprintf ( V_7 , L_162 , V_231 -> V_245 ) ;
}
static T_1 F_128 (
struct V_230 * V_231 ,
const char * V_7 ,
T_2 V_87 )
{
struct V_18 * V_246 = & V_231 -> V_247 ;
unsigned long V_245 ;
int V_20 ;
V_20 = F_91 ( V_7 , 0 , & V_245 ) ;
if ( V_20 < 0 ) {
F_14 ( L_163
L_190 , V_20 ) ;
return - V_21 ;
}
if ( V_245 > 0x0000ffff ) {
F_14 ( L_191
L_166 , V_245 ) ;
return - V_21 ;
}
V_20 = F_129 ( V_231 , ( T_6 ) V_245 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_192
L_193 ,
F_19 ( & V_246 -> V_28 ) ,
V_231 -> V_245 ) ;
return V_87 ;
}
static T_1 F_130 (
struct V_230 * V_231 ,
char * V_7 )
{
struct V_248 * V_249 ;
struct V_129 * V_250 ;
struct V_127 * V_128 ;
struct V_251 * V_252 ;
T_1 V_101 = 0 , V_224 ;
unsigned char V_89 [ V_253 ] ;
memset ( V_89 , 0 , V_253 ) ;
F_40 ( & V_231 -> V_254 ) ;
F_8 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_249 = V_252 -> V_255 ;
V_250 = V_249 -> V_256 ;
V_128 = V_249 -> V_257 ;
V_224 = snprintf ( V_89 , V_253 , L_194
L_195 , V_250 -> V_117 -> V_46 () ,
V_250 -> V_117 -> V_48 ( V_250 ) ,
V_250 -> V_117 -> V_49 ( V_250 ) ,
F_19 ( & V_128 -> V_258 . V_28 ) ) ;
V_224 ++ ;
if ( ( V_224 + V_101 ) > V_104 ) {
F_80 ( L_170
L_171 ) ;
break;
}
memcpy ( V_7 + V_101 , V_89 , V_224 ) ;
V_101 += V_224 ;
}
F_42 ( & V_231 -> V_254 ) ;
return V_101 ;
}
static void F_131 ( struct V_2 * V_3 )
{
struct V_230 * V_231 = F_2 ( F_3 ( V_3 ) ,
struct V_230 , V_247 ) ;
F_132 ( V_231 ) ;
}
static struct V_18 * F_133 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_206 * V_259 = F_2 ( V_19 , struct V_206 ,
V_260 ) ;
struct V_230 * V_231 ;
struct V_79 * V_88 = V_259 -> V_81 ;
struct V_18 * V_246 = NULL ;
struct V_2 * V_261 = NULL ;
V_231 = F_134 ( V_88 , V_13 , 0 ) ;
if ( ! V_231 )
return NULL ;
V_246 = & V_231 -> V_247 ;
V_261 = & V_246 -> V_28 ;
F_17 ( V_246 , V_13 ,
& V_262 ) ;
F_12 ( L_196
L_197 ,
F_19 ( V_261 ) ) ;
return V_246 ;
}
static void F_135 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_230 * V_231 = F_2 ( F_3 ( V_3 ) ,
struct V_230 , V_247 ) ;
F_12 ( L_198
L_199 ,
F_19 ( V_3 ) , V_231 -> V_245 ) ;
F_21 ( V_3 ) ;
}
static struct V_18 * F_136 (
struct V_18 * V_19 ,
const char * V_13 )
{
return F_15 ( - V_105 ) ;
}
static void F_137 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
return;
}
static struct V_18 * F_138 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_230 * V_231 ;
struct V_79 * V_80 ;
struct V_183 * V_184 ;
struct V_2 * V_263 = & V_19 -> V_28 ;
struct V_1 * V_181 = F_1 ( V_263 ) ;
struct V_18 * V_216 = NULL , * V_264 = NULL ;
struct V_18 * V_265 = NULL ;
int V_266 = - V_39 , V_20 ;
V_20 = F_139 ( & V_181 -> V_267 ) ;
if ( V_20 )
return F_15 ( V_20 ) ;
V_184 = V_181 -> V_185 ;
V_80 = F_23 ( sizeof( struct V_79 ) , V_38 ) ;
if ( ! V_80 ) {
F_14 ( L_200
L_201 ) ;
goto V_268;
}
F_24 ( & V_80 -> V_78 . V_269 ) ;
F_140 ( & V_80 -> V_78 . V_102 ) ;
F_24 ( & V_80 -> V_120 . V_270 ) ;
F_24 ( & V_80 -> V_120 . V_271 ) ;
F_140 ( & V_80 -> V_120 . V_135 ) ;
F_140 ( & V_80 -> V_120 . V_272 ) ;
F_24 ( & V_80 -> V_206 . V_273 ) ;
F_140 ( & V_80 -> V_206 . V_274 ) ;
F_140 ( & V_80 -> V_275 ) ;
V_80 -> V_120 . V_276 = V_277 ;
V_80 -> V_78 . V_81 = V_80 ;
V_80 -> V_206 . V_81 = V_80 ;
V_80 -> V_278 . V_279 = V_80 ;
V_80 -> V_182 = V_181 ;
V_216 = & V_80 -> V_194 ;
V_216 -> V_24 = F_23 ( sizeof( struct V_18 ) * 7 ,
V_38 ) ;
if ( ! V_216 -> V_24 )
goto V_163;
V_80 -> V_189 = V_184 -> V_280 ( V_181 , V_13 ) ;
if ( ! V_80 -> V_189 ) {
F_14 ( L_202
L_203 ) ;
goto V_163;
}
F_17 ( & V_80 -> V_194 , V_13 ,
& V_281 ) ;
F_17 ( & V_80 -> V_278 . V_282 , L_204 ,
& V_283 ) ;
F_17 ( & V_80 -> V_284 , L_205 ,
& V_285 ) ;
F_17 ( & V_80 -> V_78 . V_286 , L_206 ,
& V_287 ) ;
F_17 ( & V_80 -> V_206 . V_260 ,
L_207 , & V_288 ) ;
F_17 ( & V_80 -> V_289 . V_290 ,
L_208 , & V_291 ) ;
V_216 -> V_24 [ 0 ] = & V_80 -> V_278 . V_282 ;
V_216 -> V_24 [ 1 ] = & V_80 -> V_284 ;
V_216 -> V_24 [ 2 ] = & V_80 -> V_78 . V_286 ;
V_216 -> V_24 [ 3 ] = & V_80 -> V_206 . V_260 ;
V_216 -> V_24 [ 4 ] = & V_80 -> V_289 . V_290 ;
V_216 -> V_24 [ 5 ] = NULL ;
V_231 = F_134 ( V_80 , L_209 , 1 ) ;
if ( ! V_231 )
goto V_163;
V_264 = & V_80 -> V_206 . V_260 ;
V_264 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_264 -> V_24 ) {
F_14 ( L_210
L_211 ) ;
goto V_163;
}
F_17 ( & V_231 -> V_247 ,
L_209 , & V_262 ) ;
V_264 -> V_24 [ 0 ] = & V_231 -> V_247 ;
V_264 -> V_24 [ 1 ] = NULL ;
V_80 -> V_206 . V_292 = V_231 ;
V_265 = & V_80 -> V_289 . V_290 ;
V_265 -> V_24 = F_23 ( sizeof( struct V_18 ) * 4 ,
V_38 ) ;
if ( ! V_265 -> V_24 ) {
F_14 ( L_212 ) ;
goto V_163;
}
F_141 ( V_80 ) ;
F_12 ( L_213
L_214 , V_80 , V_80 -> V_189 ) ;
F_10 ( & V_181 -> V_267 ) ;
return & V_80 -> V_194 ;
V_163:
if ( V_80 -> V_206 . V_292 ) {
F_132 ( V_80 -> V_206 . V_292 ) ;
V_80 -> V_206 . V_292 = NULL ;
}
if ( V_265 )
F_30 ( V_265 -> V_24 ) ;
if ( V_264 )
F_30 ( V_264 -> V_24 ) ;
if ( V_216 )
F_30 ( V_216 -> V_24 ) ;
if ( V_80 -> V_189 )
V_184 -> V_217 ( V_80 -> V_189 ) ;
F_30 ( V_80 ) ;
V_268:
F_10 ( & V_181 -> V_267 ) ;
return F_15 ( V_266 ) ;
}
static void F_142 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_79 * V_80 = F_2 ( F_3 ( V_3 ) ,
struct V_79 , V_194 ) ;
struct V_1 * V_181 ;
struct V_2 * V_33 ;
struct V_18 * V_216 , * V_264 , * V_265 ;
int V_34 ;
V_181 = F_1 ( & V_80 -> V_182 -> V_4 . V_28 ) ;
F_7 ( & V_181 -> V_267 ) ;
V_265 = & V_80 -> V_289 . V_290 ;
for ( V_34 = 0 ; V_265 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_265 -> V_24 [ V_34 ] -> V_28 ;
V_265 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_30 ( V_265 -> V_24 ) ;
V_264 = & V_80 -> V_206 . V_260 ;
for ( V_34 = 0 ; V_264 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_264 -> V_24 [ V_34 ] -> V_28 ;
V_264 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_30 ( V_264 -> V_24 ) ;
V_80 -> V_206 . V_292 = NULL ;
V_216 = & V_80 -> V_194 ;
for ( V_34 = 0 ; V_216 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_216 -> V_24 [ V_34 ] -> V_28 ;
V_216 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_21 ( V_3 ) ;
F_10 ( & V_181 -> V_267 ) ;
}
static T_1 F_143 (
struct V_1 * V_181 ,
char * V_7 )
{
return sprintf ( V_7 , L_215 ,
V_181 -> V_293 , V_181 -> V_185 -> V_13 ,
V_9 ) ;
}
static T_1 F_144 ( struct V_1 * V_181 ,
char * V_7 )
{
int V_294 = 0 ;
if ( V_181 -> V_295 & V_296 )
V_294 = 1 ;
return sprintf ( V_7 , L_176 , V_294 ) ;
}
static T_1 F_145 ( struct V_1 * V_181 ,
const char * V_7 , T_2 V_87 )
{
struct V_183 * V_185 = V_181 -> V_185 ;
unsigned long V_297 ;
int V_20 ;
if ( V_185 -> V_298 == NULL )
return - V_21 ;
V_20 = F_91 ( V_7 , 0 , & V_297 ) ;
if ( V_20 < 0 ) {
F_14 ( L_216 , V_20 ) ;
return - V_21 ;
}
F_40 ( & V_181 -> V_299 ) ;
if ( ! F_146 ( & V_181 -> V_300 ) ) {
F_14 ( L_217 ) ;
F_42 ( & V_181 -> V_299 ) ;
return - V_21 ;
}
F_42 ( & V_181 -> V_299 ) ;
V_20 = V_185 -> V_298 ( V_181 , V_297 ) ;
if ( V_20 < 0 )
return - V_21 ;
if ( V_20 > 0 )
V_181 -> V_295 |= V_296 ;
else if ( V_20 == 0 )
V_181 -> V_295 &= ~ V_296 ;
return V_87 ;
}
static void F_147 ( struct V_2 * V_3 )
{
struct V_1 * V_181 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_148 ( V_181 ) ;
}
static struct V_18 * F_149 (
struct V_18 * V_19 ,
const char * V_13 )
{
char * V_301 , * V_302 , * V_303 ;
struct V_1 * V_181 ;
char V_89 [ V_304 ] ;
unsigned long V_305 = 0 ;
int V_20 ;
memset ( V_89 , 0 , V_304 ) ;
if ( strlen ( V_13 ) >= V_304 ) {
F_14 ( L_218
L_219 , ( int ) strlen ( V_13 ) ,
V_304 ) ;
return F_15 ( - V_306 ) ;
}
snprintf ( V_89 , V_304 , L_29 , V_13 ) ;
V_302 = strstr ( V_89 , L_220 ) ;
if ( ! V_302 ) {
F_14 ( L_221 ) ;
return F_15 ( - V_21 ) ;
}
V_301 = V_89 ;
V_303 = strstr ( V_302 + 1 , L_220 ) ;
if ( V_303 ) {
* V_303 = '\0' ;
V_303 ++ ;
V_302 = V_303 ;
} else {
* V_302 = '\0' ;
V_302 ++ ;
}
V_20 = F_91 ( V_302 , 0 , & V_305 ) ;
if ( V_20 < 0 ) {
F_14 ( L_163
L_222 , V_20 ) ;
return F_15 ( - V_21 ) ;
}
F_150 () ;
V_181 = F_151 ( V_301 , V_305 , 0 ) ;
if ( F_76 ( V_181 ) )
return F_152 ( V_181 ) ;
F_17 ( & V_181 -> V_4 , V_13 ,
& V_307 ) ;
return & V_181 -> V_4 ;
}
static void F_153 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
F_21 ( V_3 ) ;
}
static int T_8 F_154 ( void )
{
struct V_18 * V_308 , * V_309 = NULL , * V_310 = NULL ;
struct V_18 * V_311 = NULL ;
struct V_76 * V_312 ;
struct V_202 * V_203 ;
int V_20 ;
F_12 ( L_223
L_224 V_8 L_3 ,
V_313 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_312 = V_42 [ 0 ] ;
F_155 ( & V_312 -> V_314 ) ;
F_156 ( & V_312 -> V_315 ) ;
V_20 = F_157 () ;
if ( V_20 < 0 )
return V_20 ;
V_308 = & V_312 -> V_314 ;
V_308 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_308 -> V_24 ) {
F_14 ( L_225 ) ;
V_20 = - V_39 ;
goto V_316;
}
F_17 ( & V_317 ,
L_226 , & V_318 ) ;
V_308 -> V_24 [ 0 ] = & V_317 ;
V_308 -> V_24 [ 1 ] = NULL ;
V_309 = & V_317 ;
V_309 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_309 -> V_24 ) {
F_14 ( L_227 ) ;
V_20 = - V_39 ;
goto V_316;
}
F_17 ( & V_319 ,
L_207 , & V_320 ) ;
V_309 -> V_24 [ 0 ] = & V_319 ;
V_309 -> V_24 [ 1 ] = NULL ;
V_310 = & V_319 ;
V_310 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_310 -> V_24 ) {
F_14 ( L_228 ) ;
V_20 = - V_39 ;
goto V_316;
}
F_17 ( & V_321 ,
L_229 , & V_322 ) ;
V_310 -> V_24 [ 0 ] = & V_321 ;
V_310 -> V_24 [ 1 ] = NULL ;
V_203 = F_97 ( L_230 , 1 ) ;
if ( F_76 ( V_203 ) ) {
V_20 = - V_39 ;
goto V_316;
}
V_311 = & V_321 ;
V_311 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_311 -> V_24 ) {
F_14 ( L_231 ) ;
V_20 = - V_39 ;
goto V_316;
}
F_17 ( & V_203 -> V_211 , L_230 ,
& V_229 ) ;
V_311 -> V_24 [ 0 ] = & V_203 -> V_211 ;
V_311 -> V_24 [ 1 ] = NULL ;
V_323 = V_203 ;
V_20 = F_158 ( V_312 ) ;
if ( V_20 < 0 ) {
F_14 ( L_232 ,
V_20 , V_312 -> V_314 . V_28 . V_324 ) ;
goto V_316;
}
F_12 ( L_233
L_234 V_9 L_235
L_236 V_8 L_3 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_20 = F_159 () ;
if ( V_20 < 0 )
goto V_163;
V_20 = F_160 () ;
if ( V_20 < 0 )
goto V_163;
return 0 ;
V_163:
F_161 ( V_312 ) ;
F_162 () ;
F_163 () ;
V_316:
if ( V_323 ) {
F_95 ( V_323 ) ;
V_323 = NULL ;
}
if ( V_311 )
F_30 ( V_311 -> V_24 ) ;
if ( V_310 )
F_30 ( V_310 -> V_24 ) ;
if ( V_309 )
F_30 ( V_309 -> V_24 ) ;
F_30 ( V_308 -> V_24 ) ;
F_164 () ;
return V_20 ;
}
static void T_9 F_165 ( void )
{
struct V_76 * V_312 ;
struct V_18 * V_309 , * V_310 , * V_311 ;
struct V_2 * V_3 ;
int V_34 ;
V_312 = V_42 [ 0 ] ;
V_311 = & V_321 ;
for ( V_34 = 0 ; V_311 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_311 -> V_24 [ V_34 ] -> V_28 ;
V_311 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_311 -> V_24 ) ;
V_311 -> V_24 = NULL ;
V_310 = & V_319 ;
for ( V_34 = 0 ; V_310 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_310 -> V_24 [ V_34 ] -> V_28 ;
V_310 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_310 -> V_24 ) ;
V_310 -> V_24 = NULL ;
V_309 = & V_317 ;
for ( V_34 = 0 ; V_309 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_309 -> V_24 [ V_34 ] -> V_28 ;
V_309 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_309 -> V_24 ) ;
V_309 -> V_24 = NULL ;
F_161 ( V_312 ) ;
F_30 ( V_312 -> V_314 . V_24 ) ;
F_95 ( V_323 ) ;
V_323 = NULL ;
F_12 ( L_237
L_238 ) ;
F_162 () ;
F_163 () ;
F_164 () ;
}
