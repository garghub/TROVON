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
if ( ! V_45 -> V_76 ) {
F_14 ( L_63 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_77 ) {
F_14 ( L_64 ) ;
return - V_21 ;
}
return 0 ;
}
int F_32 (
struct V_12 * V_14 )
{
int V_20 ;
if ( ! V_14 ) {
F_14 ( L_65
L_66 ) ;
return - V_21 ;
}
if ( ! V_14 -> V_31 ) {
F_14 ( L_67
L_66 ) ;
return - V_21 ;
}
V_20 = F_31 ( V_14 ) ;
if ( V_20 < 0 )
return V_20 ;
F_12 ( L_68
L_69 ) ;
return 0 ;
}
void F_33 (
struct V_12 * V_14 )
{
struct V_78 * V_79 ;
if ( ! V_14 ) {
F_14 ( L_70
L_71 ) ;
return;
}
V_79 = V_14 -> V_31 ;
if ( ! V_79 ) {
F_14 ( L_72
L_66 ) ;
return;
}
F_12 ( L_73
L_74 ) ;
F_7 ( & V_15 ) ;
if ( F_34 ( & V_14 -> V_17 ) ) {
F_10 ( & V_15 ) ;
F_14 ( L_75 ,
V_14 -> V_16 ) ;
F_35 () ;
}
F_29 ( & V_14 -> V_40 ) ;
F_10 ( & V_15 ) ;
F_12 ( L_76
L_5 , V_14 -> V_16 ) ;
V_14 -> V_41 = NULL ;
V_14 -> V_31 = NULL ;
F_30 ( V_14 ) ;
F_12 ( L_77
L_78 ) ;
}
static T_1 F_36 (
struct V_80 * V_80 ,
char * V_7 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
struct V_84 * V_85 ;
V_85 = V_82 -> V_86 ;
if ( ! V_85 )
return - V_87 ;
return sprintf ( V_7 , L_79 ,
& V_80 -> V_88 [ 0 ] ) ;
}
static T_1 F_37 (
struct V_80 * V_80 ,
const char * V_7 ,
T_2 V_89 )
{
struct V_81 * V_90 = V_80 -> V_83 ;
struct V_84 * V_85 ;
unsigned char V_91 [ V_92 ] ;
if ( V_90 -> V_93 & V_94 ) {
F_14 ( L_80
L_81 ) ;
return - V_95 ;
}
if ( strlen ( V_7 ) >= V_92 ) {
F_14 ( L_82
L_83 , V_92 ) ;
return - V_96 ;
}
V_85 = V_90 -> V_86 ;
if ( V_85 ) {
if ( F_34 ( & V_85 -> V_97 . V_98 ) ) {
F_14 ( L_84
L_85 ,
F_34 ( & V_85 -> V_97 . V_98 ) ) ;
return - V_21 ;
}
}
memset ( V_91 , 0 , V_92 ) ;
snprintf ( V_91 , V_92 , L_29 , V_7 ) ;
snprintf ( V_90 -> V_80 . V_88 , V_92 ,
L_29 , F_38 ( V_91 ) ) ;
V_90 -> V_93 |= V_99 ;
F_12 ( L_86
L_5 , V_90 -> V_80 . V_88 ) ;
return V_89 ;
}
static T_1 F_39 (
struct V_80 * V_80 ,
char * V_7 )
{
struct V_81 * V_82 = V_80 -> V_83 ;
struct V_84 * V_85 ;
struct V_100 * V_101 ;
unsigned char V_91 [ V_102 ] ;
T_1 V_103 = 0 ;
V_85 = V_82 -> V_86 ;
if ( ! V_85 )
return - V_87 ;
memset ( V_91 , 0 , V_102 ) ;
F_40 ( & V_80 -> V_104 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_101 -> V_105 )
continue;
F_41 ( V_101 , V_91 , V_102 ) ;
if ( V_103 + strlen ( V_91 ) >= V_106 )
break;
V_103 += sprintf ( V_7 + V_103 , L_29 , V_91 ) ;
}
F_42 ( & V_80 -> V_104 ) ;
return V_103 ;
}
static T_1 F_43 (
struct V_80 * V_80 ,
const char * V_7 ,
T_2 V_89 )
{
return - V_107 ;
}
static T_1 F_44 (
struct V_80 * V_80 ,
const char * V_7 ,
T_2 V_89 )
{
return - V_107 ;
}
static T_1 F_45 (
struct V_80 * V_80 ,
const char * V_7 ,
T_2 V_89 )
{
return - V_107 ;
}
static T_1 F_46 (
struct V_80 * V_80 ,
const char * V_7 ,
T_2 V_89 )
{
return - V_107 ;
}
static T_1 F_47 (
struct V_84 * V_85 ,
char * V_7 ,
T_1 * V_103 )
{
struct V_108 * V_109 ;
struct V_110 * V_111 ;
char V_112 [ V_113 ] ;
int V_114 ;
memset ( V_112 , 0 , V_113 ) ;
F_40 ( & V_85 -> V_115 ) ;
V_111 = V_85 -> V_116 ;
if ( ! V_111 ) {
* V_103 += sprintf ( V_7 + * V_103 , L_87 ) ;
F_42 ( & V_85 -> V_115 ) ;
return * V_103 ;
}
V_109 = V_111 -> V_117 ;
V_114 = F_48 ( V_111 , & V_112 [ 0 ] ,
V_113 ) ;
* V_103 += sprintf ( V_7 + * V_103 , L_88 ,
V_109 -> V_118 -> V_119 -> V_46 () ,
V_109 -> V_120 , ( V_114 ) ? & V_112 [ 0 ] : L_89 ) ;
F_42 ( & V_85 -> V_115 ) ;
return * V_103 ;
}
static T_1 F_49 (
struct V_84 * V_85 ,
char * V_7 ,
T_1 * V_103 )
{
struct V_108 * V_109 ;
F_40 ( & V_85 -> V_115 ) ;
V_109 = V_85 -> V_121 ;
if ( ! V_109 ) {
* V_103 += sprintf ( V_7 + * V_103 , L_90 ) ;
F_42 ( & V_85 -> V_115 ) ;
return * V_103 ;
}
* V_103 += sprintf ( V_7 + * V_103 , L_91 ,
V_109 -> V_118 -> V_119 -> V_46 () ,
V_109 -> V_120 ) ;
F_42 ( & V_85 -> V_115 ) ;
return * V_103 ;
}
static T_1 F_50 (
struct V_81 * V_90 ,
char * V_7 )
{
T_1 V_103 = 0 ;
if ( ! V_90 -> V_86 )
return - V_87 ;
switch ( V_90 -> V_122 . V_123 ) {
case V_124 :
F_47 ( V_90 -> V_86 ,
V_7 , & V_103 ) ;
break;
case V_125 :
F_49 ( V_90 -> V_86 ,
V_7 , & V_103 ) ;
break;
case V_126 :
V_103 += sprintf ( V_7 + V_103 , L_92 ) ;
break;
default:
V_103 += sprintf ( V_7 + V_103 , L_93 ) ;
break;
}
return V_103 ;
}
static T_1 F_51 (
struct V_81 * V_90 ,
char * V_7 )
{
struct V_84 * V_85 ;
struct V_110 * V_111 ;
T_1 V_103 = 0 ;
V_85 = V_90 -> V_86 ;
if ( ! V_85 )
return - V_87 ;
if ( V_90 -> V_122 . V_123 != V_124 )
return V_103 ;
F_40 ( & V_85 -> V_115 ) ;
V_111 = V_85 -> V_116 ;
if ( ! V_111 ) {
V_103 = sprintf ( V_7 , L_87 ) ;
F_42 ( & V_85 -> V_115 ) ;
return V_103 ;
}
if ( V_111 -> V_127 )
V_103 = sprintf ( V_7 , L_94
L_95 ) ;
else
V_103 = sprintf ( V_7 , L_96
L_97 ) ;
F_42 ( & V_85 -> V_115 ) ;
return V_103 ;
}
static T_1 F_52 (
struct V_81 * V_90 ,
char * V_7 )
{
if ( ! V_90 -> V_86 )
return - V_87 ;
if ( V_90 -> V_122 . V_123 != V_124 )
return 0 ;
return sprintf ( V_7 , L_98 , V_90 -> V_122 . V_128 ) ;
}
static T_1 F_53 (
struct V_81 * V_90 ,
char * V_7 )
{
struct V_84 * V_85 ;
struct V_108 * V_109 ;
struct V_129 * V_130 ;
struct V_131 * V_118 ;
struct V_110 * V_111 ;
struct V_44 * V_45 ;
T_1 V_103 = 0 ;
V_85 = V_90 -> V_86 ;
if ( ! V_85 )
return - V_87 ;
if ( V_90 -> V_122 . V_123 != V_124 )
return V_103 ;
F_40 ( & V_85 -> V_115 ) ;
V_111 = V_85 -> V_116 ;
if ( ! V_111 ) {
V_103 = sprintf ( V_7 , L_87 ) ;
F_42 ( & V_85 -> V_115 ) ;
return V_103 ;
}
V_109 = V_111 -> V_117 ;
V_118 = V_109 -> V_118 ;
V_130 = V_111 -> V_132 ;
V_45 = V_118 -> V_119 ;
V_103 += sprintf ( V_7 + V_103 , L_99
L_100 , V_45 -> V_46 () ,
V_45 -> V_48 ( V_118 ) ) ;
V_103 += sprintf ( V_7 + V_103 , L_101
L_102
L_103 , V_130 -> V_133 -> V_134 ,
V_45 -> V_46 () , V_45 -> V_49 ( V_118 ) ,
V_45 -> V_46 () , V_130 -> V_135 ) ;
F_42 ( & V_85 -> V_115 ) ;
return V_103 ;
}
static T_1 F_54 (
struct V_81 * V_90 ,
char * V_7 )
{
struct V_44 * V_45 ;
struct V_110 * V_111 ;
unsigned char V_91 [ 384 ] ;
char V_112 [ V_113 ] ;
T_1 V_103 = 0 ;
int V_136 = 0 , V_114 ;
if ( ! V_90 -> V_86 )
return - V_87 ;
if ( V_90 -> V_122 . V_123 != V_124 )
return V_103 ;
V_103 += sprintf ( V_7 + V_103 , L_104 ) ;
F_40 ( & V_90 -> V_122 . V_137 ) ;
F_8 (pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_91 , 0 , 384 ) ;
memset ( V_112 , 0 , V_113 ) ;
V_45 = V_111 -> V_117 -> V_118 -> V_119 ;
V_114 = F_48 ( V_111 , & V_112 [ 0 ] ,
V_113 ) ;
sprintf ( V_91 , L_105 ,
V_45 -> V_46 () ,
V_111 -> V_117 -> V_120 , ( V_114 ) ?
& V_112 [ 0 ] : L_89 , V_111 -> V_138 ,
V_111 -> V_139 ) ;
if ( V_103 + strlen ( V_91 ) >= V_106 )
break;
V_103 += sprintf ( V_7 + V_103 , L_29 , V_91 ) ;
V_136 ++ ;
}
F_42 ( & V_90 -> V_122 . V_137 ) ;
if ( ! V_136 )
V_103 += sprintf ( V_7 + V_103 , L_106 ) ;
return V_103 ;
}
static T_1 F_55 (
struct V_81 * V_90 ,
char * V_7 )
{
struct V_84 * V_85 ;
struct V_110 * V_111 ;
T_1 V_103 = 0 ;
V_85 = V_90 -> V_86 ;
if ( ! V_85 )
return - V_87 ;
if ( V_90 -> V_122 . V_123 != V_124 )
return V_103 ;
F_40 ( & V_85 -> V_115 ) ;
V_111 = V_85 -> V_116 ;
if ( ! V_111 ) {
V_103 = sprintf ( V_7 , L_87 ) ;
F_42 ( & V_85 -> V_115 ) ;
return V_103 ;
}
V_103 = sprintf ( V_7 , L_107 ,
F_56 ( V_111 -> V_140 ) ) ;
F_42 ( & V_85 -> V_115 ) ;
return V_103 ;
}
static T_1 F_57 (
struct V_81 * V_90 ,
char * V_7 )
{
T_1 V_103 = 0 ;
if ( ! V_90 -> V_86 )
return - V_87 ;
switch ( V_90 -> V_122 . V_123 ) {
case V_124 :
V_103 = sprintf ( V_7 , L_108 ) ;
break;
case V_125 :
V_103 = sprintf ( V_7 , L_109 ) ;
break;
case V_126 :
V_103 = sprintf ( V_7 , L_110 ) ;
break;
default:
V_103 = sprintf ( V_7 , L_111 ) ;
break;
}
return V_103 ;
}
static T_1 F_58 (
struct V_81 * V_90 ,
char * V_7 )
{
if ( ! V_90 -> V_86 )
return - V_87 ;
if ( V_90 -> V_122 . V_123 != V_124 )
return 0 ;
return sprintf ( V_7 , L_112 ,
( V_90 -> V_122 . V_141 ) ? L_113 : L_114 ) ;
}
static T_1 F_59 (
struct V_81 * V_90 ,
char * V_7 )
{
if ( ! V_90 -> V_86 )
return - V_87 ;
if ( V_90 -> V_122 . V_123 != V_124 )
return 0 ;
return sprintf ( V_7 , L_115 ) ;
}
static T_1 F_60 (
struct V_81 * V_90 ,
const char * V_7 ,
T_2 V_89 )
{
struct V_84 * V_85 ;
unsigned char * V_142 = NULL , * V_143 = NULL , * V_144 = NULL ;
unsigned char * V_145 = NULL , * V_146 = NULL ;
char * V_147 , * V_148 , * V_149 , * V_150 ;
T_3 args [ V_151 ] ;
unsigned long long V_152 ;
T_4 V_153 = 0 ;
T_5 V_154 = 0 , V_155 = 0 ;
int V_20 = - 1 , V_156 = 0 , V_157 = 0 , V_158 , V_159 ;
T_6 V_160 = 0 , V_161 = 0 ;
T_7 type = 0 , V_162 ;
V_85 = V_90 -> V_86 ;
if ( ! V_85 )
return - V_87 ;
if ( V_90 -> V_122 . V_123 != V_124 )
return 0 ;
if ( F_34 ( & V_85 -> V_97 . V_98 ) ) {
F_12 ( L_116
L_117 ) ;
return - V_21 ;
}
V_150 = F_61 ( V_7 , V_38 ) ;
if ( ! V_150 )
return - V_39 ;
V_147 = V_150 ;
while ( ( V_148 = F_62 ( & V_150 , L_118 ) ) != NULL ) {
if ( ! * V_148 )
continue;
V_159 = F_63 ( V_148 , V_163 , args ) ;
switch ( V_159 ) {
case V_164 :
V_142 = F_64 ( & args [ 0 ] ) ;
if ( ! V_142 ) {
V_20 = - V_39 ;
goto V_165;
}
break;
case V_166 :
V_143 = F_64 ( & args [ 0 ] ) ;
if ( ! V_143 ) {
V_20 = - V_39 ;
goto V_165;
}
if ( strlen ( V_143 ) >= V_167 ) {
F_14 ( L_119
L_120 ,
V_167 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_168 :
V_144 = F_64 ( & args [ 0 ] ) ;
if ( ! V_144 ) {
V_20 = - V_39 ;
goto V_165;
}
if ( strlen ( V_144 ) >= V_169 ) {
F_14 ( L_121
L_122 ,
V_169 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_170 :
V_149 = F_64 ( & args [ 0 ] ) ;
if ( ! V_149 ) {
V_20 = - V_39 ;
goto V_165;
}
V_20 = F_65 ( V_149 , 0 , & V_152 ) ;
if ( V_20 < 0 ) {
F_14 ( L_123
L_124 ) ;
goto V_165;
}
V_153 = ( T_4 ) V_152 ;
break;
case V_171 :
F_66 ( args , & V_158 ) ;
V_156 = V_158 ;
break;
case V_172 :
F_66 ( args , & V_158 ) ;
type = ( T_7 ) V_158 ;
break;
case V_173 :
F_66 ( args , & V_158 ) ;
V_162 = ( T_7 ) V_158 ;
break;
case V_174 :
F_66 ( args , & V_158 ) ;
V_157 = ( int ) V_158 ;
break;
case V_175 :
F_66 ( args , & V_158 ) ;
V_154 = ( T_5 ) V_158 ;
break;
case V_176 :
V_145 = F_64 ( & args [ 0 ] ) ;
if ( ! V_145 ) {
V_20 = - V_39 ;
goto V_165;
}
break;
case V_177 :
V_146 = F_64 ( & args [ 0 ] ) ;
if ( ! V_146 ) {
V_20 = - V_39 ;
goto V_165;
}
if ( strlen ( V_146 ) >= V_178 ) {
F_14 ( L_125
L_126 ,
V_178 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_179 :
F_66 ( args , & V_158 ) ;
V_161 = ( T_6 ) V_158 ;
break;
case V_180 :
F_66 ( args , & V_158 ) ;
V_160 = ( T_6 ) V_158 ;
break;
case V_181 :
F_66 ( args , & V_158 ) ;
V_155 = ( T_5 ) V_158 ;
break;
default:
break;
}
}
if ( ! V_143 || ! V_146 || ! V_153 ) {
F_14 ( L_127 ) ;
V_20 = - V_21 ;
goto V_165;
}
if ( V_156 && ! ( type ) ) {
F_14 ( L_128
L_129 , type ) ;
V_20 = - V_21 ;
goto V_165;
}
V_20 = F_67 ( & V_90 -> V_122 , V_153 ,
V_143 , V_144 , V_154 , V_146 , V_161 , V_155 ,
V_156 , V_157 , type ) ;
V_165:
F_30 ( V_142 ) ;
F_30 ( V_143 ) ;
F_30 ( V_144 ) ;
F_30 ( V_145 ) ;
F_30 ( V_146 ) ;
F_30 ( V_147 ) ;
return ( V_20 == 0 ) ? V_89 : V_20 ;
}
static T_1 F_68 ( void * V_182 , char * V_7 )
{
struct V_81 * V_82 = V_182 ;
struct V_1 * V_183 = V_82 -> V_184 ;
struct V_185 * V_186 = V_183 -> V_187 ;
int V_188 = 0 ;
T_1 V_189 = 0 ;
if ( ! V_82 -> V_86 )
return - V_87 ;
F_69 ( V_82 -> V_86 , V_7 , & V_188 ) ;
V_189 += V_188 ;
V_189 += V_186 -> V_190 ( V_183 , V_82 , V_7 + V_189 ) ;
return V_189 ;
}
static T_1 F_70 (
void * V_182 ,
const char * V_7 ,
T_2 V_89 )
{
struct V_81 * V_82 = V_182 ;
struct V_1 * V_183 = V_82 -> V_184 ;
struct V_185 * V_186 = V_183 -> V_187 ;
if ( ! V_82 -> V_191 ) {
F_14 ( L_130
L_131 ) ;
return - V_21 ;
}
return V_186 -> V_192 ( V_183 , V_82 , V_7 , V_89 ) ;
}
static T_1 F_71 ( void * V_182 , char * V_7 )
{
struct V_81 * V_82 = V_182 ;
if ( ! ( V_82 -> V_93 & V_193 ) )
return 0 ;
return snprintf ( V_7 , V_106 , L_132 , V_82 -> V_194 ) ;
}
static T_1 F_72 (
void * V_182 ,
const char * V_7 ,
T_2 V_89 )
{
struct V_81 * V_82 = V_182 ;
struct V_1 * V_183 = V_82 -> V_184 ;
T_1 V_189 ;
if ( V_89 > ( V_195 - 1 ) ) {
F_14 ( L_133
L_134 , ( int ) V_89 ,
V_195 - 1 ) ;
return - V_21 ;
}
V_189 = snprintf ( & V_82 -> V_194 [ 0 ] , V_195 ,
L_29 , V_7 ) ;
if ( ! V_189 )
return - V_21 ;
if ( V_82 -> V_194 [ V_189 - 1 ] == '\n' )
V_82 -> V_194 [ V_189 - 1 ] = '\0' ;
V_82 -> V_93 |= V_193 ;
F_12 ( L_135 ,
F_19 ( & V_183 -> V_4 . V_28 ) ,
F_19 ( & V_82 -> V_196 . V_28 ) ,
V_82 -> V_194 ) ;
return V_189 ;
}
static T_1 F_73 ( void * V_182 , char * V_7 )
{
struct V_81 * V_82 = V_182 ;
if ( ! ( V_82 -> V_93 & V_197 ) )
return 0 ;
return snprintf ( V_7 , V_106 , L_132 , V_82 -> V_198 ) ;
}
static T_1 F_74 (
void * V_182 ,
const char * V_7 ,
T_2 V_89 )
{
struct V_81 * V_82 = V_182 ;
struct V_1 * V_183 = V_82 -> V_184 ;
T_1 V_189 ;
if ( V_89 > ( V_199 - 1 ) ) {
F_14 ( L_136
L_137 , ( int ) V_89 ,
V_199 - 1 ) ;
return - V_21 ;
}
V_189 = snprintf ( & V_82 -> V_198 [ 0 ] , V_199 ,
L_29 , V_7 ) ;
if ( ! V_189 )
return - V_21 ;
if ( V_82 -> V_198 [ V_189 - 1 ] == '\n' )
V_82 -> V_198 [ V_189 - 1 ] = '\0' ;
V_82 -> V_93 |= V_197 ;
F_12 ( L_138 ,
F_19 ( & V_183 -> V_4 . V_28 ) ,
F_19 ( & V_82 -> V_196 . V_28 ) ,
V_82 -> V_198 ) ;
return V_189 ;
}
static T_1 F_75 (
void * V_182 ,
const char * V_7 ,
T_2 V_89 )
{
struct V_81 * V_82 = V_182 ;
struct V_84 * V_85 ;
struct V_1 * V_183 = V_82 -> V_184 ;
struct V_185 * V_186 = V_183 -> V_187 ;
char * V_148 ;
V_148 = strstr ( V_7 , L_139 ) ;
if ( ! V_148 ) {
F_14 ( L_140
L_141 ) ;
return - V_21 ;
}
if ( V_82 -> V_86 ) {
F_14 ( L_142
L_143 ) ;
return - V_200 ;
}
if ( V_186 -> V_201 ( V_183 , V_82 ) < 0 )
return - V_21 ;
V_85 = V_186 -> V_202 ( V_183 , V_82 , V_82 -> V_191 ) ;
if ( F_76 ( V_85 ) )
return F_77 ( V_85 ) ;
else if ( ! V_85 )
return - V_21 ;
V_82 -> V_86 = V_85 ;
F_12 ( L_144
L_145 , V_82 -> V_86 ) ;
return V_89 ;
}
static T_1 F_78 ( void * V_182 , char * V_7 )
{
struct V_84 * V_85 ;
struct V_81 * V_90 = V_182 ;
struct V_2 * V_203 ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
T_1 V_103 = 0 ;
V_85 = V_90 -> V_86 ;
if ( ! V_85 )
return - V_87 ;
if ( V_90 -> V_208 . V_209 != V_210 )
return V_103 ;
V_207 = V_85 -> V_211 ;
if ( ! V_207 ) {
F_14 ( L_146
L_66 ) ;
return - V_21 ;
}
F_40 ( & V_207 -> V_212 ) ;
V_205 = V_207 -> V_205 ;
if ( V_205 ) {
V_203 = & V_205 -> V_213 . V_28 ;
V_103 += sprintf ( V_7 , L_147 ,
F_19 ( V_203 ) , V_205 -> V_214 ) ;
}
F_42 ( & V_207 -> V_212 ) ;
return V_103 ;
}
static T_1 F_79 (
void * V_182 ,
const char * V_7 ,
T_2 V_89 )
{
struct V_84 * V_85 ;
struct V_81 * V_90 = V_182 ;
struct V_1 * V_183 = V_90 -> V_184 ;
struct V_204 * V_205 = NULL , * V_215 = NULL ;
struct V_206 * V_207 ;
unsigned char V_91 [ V_216 ] ;
int V_217 = 0 ;
V_85 = V_90 -> V_86 ;
if ( ! V_85 )
return - V_87 ;
if ( V_90 -> V_208 . V_209 != V_210 ) {
F_80 ( L_148 ,
F_19 ( & V_183 -> V_4 . V_28 ) ,
F_19 ( & V_90 -> V_196 . V_28 ) ) ;
return - V_21 ;
}
if ( V_89 > V_216 ) {
F_14 ( L_149 ) ;
return - V_21 ;
}
memset ( V_91 , 0 , V_216 ) ;
memcpy ( V_91 , V_7 , V_89 ) ;
if ( strcmp ( F_38 ( V_91 ) , L_150 ) ) {
V_215 = F_81 ( F_38 ( V_91 ) ) ;
if ( ! V_215 )
return - V_87 ;
}
V_207 = V_85 -> V_211 ;
if ( ! V_207 ) {
if ( V_215 )
F_82 ( V_215 ) ;
F_14 ( L_146
L_66 ) ;
return - V_21 ;
}
F_40 ( & V_207 -> V_212 ) ;
V_205 = V_207 -> V_205 ;
if ( V_205 ) {
if ( ! V_215 ) {
F_12 ( L_151
L_152
L_153 ,
F_19 ( & V_183 -> V_4 . V_28 ) ,
F_19 ( & V_90 -> V_196 . V_28 ) ,
F_19 ( & V_205 -> V_213 . V_28 ) ,
V_205 -> V_214 ) ;
F_83 ( V_207 , V_205 ) ;
F_42 ( & V_207 -> V_212 ) ;
return V_89 ;
}
F_83 ( V_207 , V_205 ) ;
V_217 = 1 ;
}
F_84 ( V_207 , V_215 ) ;
F_42 ( & V_207 -> V_212 ) ;
F_12 ( L_154
L_155 ,
( V_217 ) ? L_156 : L_157 ,
F_19 ( & V_183 -> V_4 . V_28 ) ,
F_19 ( & V_90 -> V_196 . V_28 ) ,
F_19 ( & V_215 -> V_213 . V_28 ) ,
V_215 -> V_214 ) ;
F_82 ( V_215 ) ;
return V_89 ;
}
static void F_85 ( struct V_2 * V_3 )
{
struct V_81 * V_82 = F_2 ( F_3 ( V_3 ) ,
struct V_81 , V_196 ) ;
struct V_1 * V_183 = F_1 ( & V_82 -> V_184 -> V_4 . V_28 ) ;
struct V_185 * V_186 = V_183 -> V_187 ;
struct V_18 * V_218 = & V_82 -> V_196 ;
F_30 ( V_218 -> V_24 ) ;
if ( V_82 -> V_86 ) {
F_12 ( L_158
L_159 ,
V_82 -> V_86 ) ;
F_86 ( V_82 -> V_86 , V_183 ) ;
} else {
F_12 ( L_160
L_161 ,
V_82 -> V_191 ) ;
V_186 -> V_219 ( V_82 -> V_191 ) ;
}
F_12 ( L_162
L_163 , V_82 ) ;
F_30 ( V_82 ) ;
}
static T_1 F_87 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
char * V_7 )
{
struct V_81 * V_82 = F_2 (
F_3 ( V_3 ) , struct V_81 ,
V_196 ) ;
struct V_220 * V_221 = F_2 (
V_6 , struct V_220 , V_6 ) ;
if ( ! V_221 -> V_222 )
return - V_21 ;
return V_221 -> V_222 ( V_82 , V_7 ) ;
}
static T_1 F_88 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
const char * V_7 , T_2 V_89 )
{
struct V_81 * V_82 = F_2 (
F_3 ( V_3 ) , struct V_81 ,
V_196 ) ;
struct V_220 * V_221 = F_2 (
V_6 , struct V_220 , V_6 ) ;
if ( ! V_221 -> V_223 )
return - V_21 ;
return V_221 -> V_223 ( V_82 , V_7 , V_89 ) ;
}
static T_1 F_89 (
struct V_204 * V_205 ,
char * V_7 )
{
if ( ! V_205 -> V_224 )
return 0 ;
return sprintf ( V_7 , L_164 , V_205 -> V_214 ) ;
}
static T_1 F_90 (
struct V_204 * V_205 ,
const char * V_7 ,
T_2 V_89 )
{
struct V_18 * V_225 = & V_205 -> V_213 ;
unsigned long V_214 ;
int V_20 ;
V_20 = F_91 ( V_7 , 0 , & V_214 ) ;
if ( V_20 < 0 ) {
F_14 ( L_165
L_166 , V_20 ) ;
return - V_21 ;
}
if ( V_214 > 0x0000ffff ) {
F_14 ( L_167
L_168 , V_214 ) ;
return - V_21 ;
}
V_20 = F_92 ( V_205 , ( T_6 ) V_214 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_169
L_170 ,
F_19 ( & V_225 -> V_28 ) ,
V_205 -> V_214 ) ;
return V_89 ;
}
static T_1 F_93 (
struct V_204 * V_205 ,
char * V_7 )
{
struct V_84 * V_85 ;
struct V_1 * V_183 ;
struct V_81 * V_90 ;
struct V_206 * V_207 ;
T_1 V_103 = 0 , V_226 ;
unsigned char V_91 [ V_216 ] ;
memset ( V_91 , 0 , V_216 ) ;
F_40 ( & V_205 -> V_227 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_85 = V_207 -> V_228 ;
V_90 = V_85 -> V_229 ;
V_183 = V_90 -> V_184 ;
V_226 = snprintf ( V_91 , V_216 , L_171 ,
F_19 ( & V_183 -> V_4 . V_28 ) ,
F_19 ( & V_90 -> V_196 . V_28 ) ) ;
V_226 ++ ;
if ( ( V_226 + V_103 ) > V_106 ) {
F_80 ( L_172
L_173 ) ;
break;
}
memcpy ( V_7 + V_103 , V_91 , V_226 ) ;
V_103 += V_226 ;
}
F_42 ( & V_205 -> V_227 ) ;
return V_103 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_204 * V_205 = F_2 ( F_3 ( V_3 ) ,
struct V_204 , V_213 ) ;
F_95 ( V_205 ) ;
}
static struct V_18 * F_96 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_204 * V_205 ;
struct V_18 * V_225 = NULL ;
struct V_2 * V_230 = NULL ;
V_205 = F_97 ( V_13 , 0 ) ;
if ( F_76 ( V_205 ) )
return NULL ;
V_225 = & V_205 -> V_213 ;
V_230 = & V_225 -> V_28 ;
F_17 ( V_225 , V_13 ,
& V_231 ) ;
F_12 ( L_174
L_175 ,
F_19 ( V_230 ) ) ;
return V_225 ;
}
static void F_98 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_204 * V_205 = F_2 ( F_3 ( V_3 ) ,
struct V_204 , V_213 ) ;
F_12 ( L_176
L_177 ,
F_19 ( V_3 ) , V_205 -> V_214 ) ;
F_21 ( V_3 ) ;
}
static T_1 F_99 (
struct V_232 * V_233 ,
char * V_7 )
{
return sprintf ( V_7 , L_178 ,
F_34 ( & V_233 -> V_234 ) ) ;
}
static T_1 F_100 (
struct V_232 * V_233 ,
const char * V_7 ,
T_2 V_89 )
{
struct V_81 * V_90 = V_233 -> V_235 ;
unsigned long V_236 ;
int V_237 , V_20 ;
if ( ! V_233 -> V_238 ) {
F_14 ( L_179
L_180 , V_233 -> V_238 ) ;
return - V_21 ;
}
V_20 = F_91 ( V_7 , 0 , & V_236 ) ;
if ( V_20 < 0 ) {
F_14 ( L_181
L_5 , V_7 ) ;
return - V_21 ;
}
V_237 = ( int ) V_236 ;
if ( ! ( V_233 -> V_239 & V_240 ) ) {
F_14 ( L_182
L_183 ) ;
return - V_21 ;
}
V_20 = F_101 ( V_233 , V_90 -> V_86 ,
NULL , NULL , V_237 , 0 ) ;
return ( ! V_20 ) ? V_89 : - V_21 ;
}
static T_1 F_102 (
struct V_232 * V_233 ,
char * V_7 )
{
return sprintf ( V_7 , L_132 ,
F_103 ( V_233 -> V_241 ) ) ;
}
static T_1 F_104 (
struct V_232 * V_233 ,
const char * V_7 ,
T_2 V_89 )
{
unsigned long V_236 ;
int V_242 , V_20 ;
if ( ! V_233 -> V_238 ) {
F_14 ( L_184
L_185 ,
V_233 -> V_238 ) ;
return - V_21 ;
}
V_20 = F_91 ( V_7 , 0 , & V_236 ) ;
if ( V_20 < 0 ) {
F_14 ( L_186
L_187 , V_7 ) ;
return - V_21 ;
}
V_242 = ( int ) V_236 ;
if ( ( V_242 != V_243 ) &&
( V_242 != V_244 ) &&
( V_242 != V_245 ) ) {
F_14 ( L_188 ,
V_242 ) ;
return - V_21 ;
}
V_233 -> V_241 = V_242 ;
return V_89 ;
}
static T_1 F_105 (
struct V_232 * V_233 ,
char * V_7 )
{
return F_106 ( V_233 , V_7 ) ;
}
static T_1 F_107 (
struct V_232 * V_233 ,
const char * V_7 ,
T_2 V_89 )
{
return F_108 ( V_233 , V_7 , V_89 ) ;
}
static T_1 F_109 (
struct V_232 * V_233 ,
char * V_7 )
{
return sprintf ( V_7 , L_178 , V_233 -> V_246 ) ;
}
static T_1 F_110 (
struct V_232 * V_233 ,
const char * V_7 ,
T_2 V_89 )
{
unsigned long V_236 ;
int V_20 ;
V_20 = F_91 ( V_7 , 0 , & V_236 ) ;
if ( V_20 < 0 ) {
F_14 ( L_189 ) ;
return - V_21 ;
}
if ( ( V_236 != 0 ) && ( V_236 != 1 ) ) {
F_14 ( L_190
L_191 , V_236 ) ;
return - V_21 ;
}
V_233 -> V_246 = ( int ) V_236 ;
return V_89 ;
}
static T_1 F_111 (
struct V_232 * V_233 ,
char * V_7 )
{
return F_112 ( V_233 , V_7 ) ;
}
static T_1 F_113 (
struct V_232 * V_233 ,
const char * V_7 ,
T_2 V_89 )
{
return F_114 ( V_233 , V_7 , V_89 ) ;
}
static T_1 F_115 (
struct V_232 * V_233 ,
char * V_7 )
{
return F_116 ( V_233 , V_7 ) ;
}
static T_1 F_117 (
struct V_232 * V_233 ,
const char * V_7 ,
T_2 V_89 )
{
return F_118 ( V_233 , V_7 , V_89 ) ;
}
static T_1 F_119 (
struct V_232 * V_233 ,
char * V_7 )
{
return F_120 ( V_233 , V_7 ) ;
}
static T_1 F_121 (
struct V_232 * V_233 ,
const char * V_7 ,
T_2 V_89 )
{
return F_122 ( V_233 , V_7 , V_89 ) ;
}
static T_1 F_123 (
struct V_232 * V_233 ,
char * V_7 )
{
return F_124 ( V_233 , V_7 ) ;
}
static T_1 F_125 (
struct V_232 * V_233 ,
const char * V_7 ,
T_2 V_89 )
{
return F_126 ( V_233 , V_7 , V_89 ) ;
}
static T_1 F_127 (
struct V_232 * V_233 ,
char * V_7 )
{
if ( ! V_233 -> V_238 )
return 0 ;
return sprintf ( V_7 , L_164 , V_233 -> V_247 ) ;
}
static T_1 F_128 (
struct V_232 * V_233 ,
const char * V_7 ,
T_2 V_89 )
{
struct V_18 * V_248 = & V_233 -> V_249 ;
unsigned long V_247 ;
int V_20 ;
V_20 = F_91 ( V_7 , 0 , & V_247 ) ;
if ( V_20 < 0 ) {
F_14 ( L_165
L_192 , V_20 ) ;
return - V_21 ;
}
if ( V_247 > 0x0000ffff ) {
F_14 ( L_193
L_168 , V_247 ) ;
return - V_21 ;
}
V_20 = F_129 ( V_233 , ( T_6 ) V_247 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_194
L_195 ,
F_19 ( & V_248 -> V_28 ) ,
V_233 -> V_247 ) ;
return V_89 ;
}
static T_1 F_130 (
struct V_232 * V_233 ,
char * V_7 )
{
struct V_250 * V_251 ;
struct V_131 * V_252 ;
struct V_129 * V_130 ;
struct V_253 * V_254 ;
T_1 V_103 = 0 , V_226 ;
unsigned char V_91 [ V_255 ] ;
memset ( V_91 , 0 , V_255 ) ;
F_40 ( & V_233 -> V_256 ) ;
F_8 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_251 = V_254 -> V_257 ;
V_252 = V_251 -> V_258 ;
V_130 = V_251 -> V_259 ;
V_226 = snprintf ( V_91 , V_255 , L_196
L_197 , V_252 -> V_119 -> V_46 () ,
V_252 -> V_119 -> V_48 ( V_252 ) ,
V_252 -> V_119 -> V_49 ( V_252 ) ,
F_19 ( & V_130 -> V_260 . V_28 ) ) ;
V_226 ++ ;
if ( ( V_226 + V_103 ) > V_106 ) {
F_80 ( L_172
L_173 ) ;
break;
}
memcpy ( V_7 + V_103 , V_91 , V_226 ) ;
V_103 += V_226 ;
}
F_42 ( & V_233 -> V_256 ) ;
return V_103 ;
}
static void F_131 ( struct V_2 * V_3 )
{
struct V_232 * V_233 = F_2 ( F_3 ( V_3 ) ,
struct V_232 , V_249 ) ;
F_132 ( V_233 ) ;
}
static struct V_18 * F_133 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_208 * V_261 = F_2 ( V_19 , struct V_208 ,
V_262 ) ;
struct V_232 * V_233 ;
struct V_81 * V_90 = V_261 -> V_83 ;
struct V_18 * V_248 = NULL ;
struct V_2 * V_263 = NULL ;
V_233 = F_134 ( V_90 , V_13 , 0 ) ;
if ( ! V_233 )
return NULL ;
V_248 = & V_233 -> V_249 ;
V_263 = & V_248 -> V_28 ;
F_17 ( V_248 , V_13 ,
& V_264 ) ;
F_12 ( L_198
L_199 ,
F_19 ( V_263 ) ) ;
return V_248 ;
}
static void F_135 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_232 * V_233 = F_2 ( F_3 ( V_3 ) ,
struct V_232 , V_249 ) ;
F_12 ( L_200
L_201 ,
F_19 ( V_3 ) , V_233 -> V_247 ) ;
F_21 ( V_3 ) ;
}
static struct V_18 * F_136 (
struct V_18 * V_19 ,
const char * V_13 )
{
return F_15 ( - V_107 ) ;
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
struct V_232 * V_233 ;
struct V_81 * V_82 ;
struct V_185 * V_186 ;
struct V_2 * V_265 = & V_19 -> V_28 ;
struct V_1 * V_183 = F_1 ( V_265 ) ;
struct V_18 * V_218 = NULL , * V_266 = NULL ;
struct V_18 * V_267 = NULL ;
int V_268 = - V_39 , V_20 ;
V_20 = F_139 ( & V_183 -> V_269 ) ;
if ( V_20 )
return F_15 ( V_20 ) ;
V_186 = V_183 -> V_187 ;
V_82 = F_23 ( sizeof( struct V_81 ) , V_38 ) ;
if ( ! V_82 ) {
F_14 ( L_202
L_203 ) ;
goto V_270;
}
F_24 ( & V_82 -> V_80 . V_271 ) ;
F_140 ( & V_82 -> V_80 . V_104 ) ;
F_24 ( & V_82 -> V_122 . V_272 ) ;
F_24 ( & V_82 -> V_122 . V_273 ) ;
F_140 ( & V_82 -> V_122 . V_137 ) ;
F_140 ( & V_82 -> V_122 . V_274 ) ;
F_24 ( & V_82 -> V_208 . V_275 ) ;
F_140 ( & V_82 -> V_208 . V_276 ) ;
F_140 ( & V_82 -> V_277 ) ;
V_82 -> V_122 . V_278 = V_279 ;
V_82 -> V_80 . V_83 = V_82 ;
V_82 -> V_208 . V_83 = V_82 ;
V_82 -> V_280 . V_281 = V_82 ;
V_82 -> V_184 = V_183 ;
V_218 = & V_82 -> V_196 ;
V_218 -> V_24 = F_23 ( sizeof( struct V_18 ) * 7 ,
V_38 ) ;
if ( ! V_218 -> V_24 )
goto V_165;
V_82 -> V_191 = V_186 -> V_282 ( V_183 , V_13 ) ;
if ( ! V_82 -> V_191 ) {
F_14 ( L_204
L_205 ) ;
goto V_165;
}
F_17 ( & V_82 -> V_196 , V_13 ,
& V_283 ) ;
F_17 ( & V_82 -> V_280 . V_284 , L_206 ,
& V_285 ) ;
F_17 ( & V_82 -> V_286 , L_207 ,
& V_287 ) ;
F_17 ( & V_82 -> V_80 . V_288 , L_208 ,
& V_289 ) ;
F_17 ( & V_82 -> V_208 . V_262 ,
L_209 , & V_290 ) ;
F_17 ( & V_82 -> V_291 . V_292 ,
L_210 , & V_293 ) ;
V_218 -> V_24 [ 0 ] = & V_82 -> V_280 . V_284 ;
V_218 -> V_24 [ 1 ] = & V_82 -> V_286 ;
V_218 -> V_24 [ 2 ] = & V_82 -> V_80 . V_288 ;
V_218 -> V_24 [ 3 ] = & V_82 -> V_208 . V_262 ;
V_218 -> V_24 [ 4 ] = & V_82 -> V_291 . V_292 ;
V_218 -> V_24 [ 5 ] = NULL ;
V_233 = F_134 ( V_82 , L_211 , 1 ) ;
if ( ! V_233 )
goto V_165;
V_266 = & V_82 -> V_208 . V_262 ;
V_266 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_266 -> V_24 ) {
F_14 ( L_212
L_213 ) ;
goto V_165;
}
F_17 ( & V_233 -> V_249 ,
L_211 , & V_264 ) ;
V_266 -> V_24 [ 0 ] = & V_233 -> V_249 ;
V_266 -> V_24 [ 1 ] = NULL ;
V_82 -> V_208 . V_294 = V_233 ;
V_267 = & V_82 -> V_291 . V_292 ;
V_267 -> V_24 = F_23 ( sizeof( struct V_18 ) * 4 ,
V_38 ) ;
if ( ! V_267 -> V_24 ) {
F_14 ( L_214 ) ;
goto V_165;
}
F_141 ( V_82 ) ;
F_12 ( L_215
L_216 , V_82 , V_82 -> V_191 ) ;
F_10 ( & V_183 -> V_269 ) ;
return & V_82 -> V_196 ;
V_165:
if ( V_82 -> V_208 . V_294 ) {
F_132 ( V_82 -> V_208 . V_294 ) ;
V_82 -> V_208 . V_294 = NULL ;
}
if ( V_267 )
F_30 ( V_267 -> V_24 ) ;
if ( V_266 )
F_30 ( V_266 -> V_24 ) ;
if ( V_218 )
F_30 ( V_218 -> V_24 ) ;
if ( V_82 -> V_191 )
V_186 -> V_219 ( V_82 -> V_191 ) ;
F_30 ( V_82 ) ;
V_270:
F_10 ( & V_183 -> V_269 ) ;
return F_15 ( V_268 ) ;
}
static void F_142 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_81 * V_82 = F_2 ( F_3 ( V_3 ) ,
struct V_81 , V_196 ) ;
struct V_1 * V_183 ;
struct V_2 * V_33 ;
struct V_18 * V_218 , * V_266 , * V_267 ;
int V_34 ;
V_183 = F_1 ( & V_82 -> V_184 -> V_4 . V_28 ) ;
F_7 ( & V_183 -> V_269 ) ;
V_267 = & V_82 -> V_291 . V_292 ;
for ( V_34 = 0 ; V_267 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_267 -> V_24 [ V_34 ] -> V_28 ;
V_267 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_30 ( V_267 -> V_24 ) ;
V_266 = & V_82 -> V_208 . V_262 ;
for ( V_34 = 0 ; V_266 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_266 -> V_24 [ V_34 ] -> V_28 ;
V_266 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_30 ( V_266 -> V_24 ) ;
V_82 -> V_208 . V_294 = NULL ;
V_218 = & V_82 -> V_196 ;
for ( V_34 = 0 ; V_218 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_218 -> V_24 [ V_34 ] -> V_28 ;
V_218 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_21 ( V_3 ) ;
F_10 ( & V_183 -> V_269 ) ;
}
static T_1 F_143 (
struct V_1 * V_183 ,
char * V_7 )
{
return sprintf ( V_7 , L_217 ,
V_183 -> V_295 , V_183 -> V_187 -> V_13 ,
V_9 ) ;
}
static T_1 F_144 ( struct V_1 * V_183 ,
char * V_7 )
{
int V_296 = 0 ;
if ( V_183 -> V_297 & V_298 )
V_296 = 1 ;
return sprintf ( V_7 , L_178 , V_296 ) ;
}
static T_1 F_145 ( struct V_1 * V_183 ,
const char * V_7 , T_2 V_89 )
{
struct V_185 * V_187 = V_183 -> V_187 ;
unsigned long V_299 ;
int V_20 ;
if ( V_187 -> V_300 == NULL )
return - V_21 ;
V_20 = F_91 ( V_7 , 0 , & V_299 ) ;
if ( V_20 < 0 ) {
F_14 ( L_218 , V_20 ) ;
return - V_21 ;
}
F_40 ( & V_183 -> V_301 ) ;
if ( ! F_146 ( & V_183 -> V_302 ) ) {
F_14 ( L_219 ) ;
F_42 ( & V_183 -> V_301 ) ;
return - V_21 ;
}
F_42 ( & V_183 -> V_301 ) ;
V_20 = V_187 -> V_300 ( V_183 , V_299 ) ;
if ( V_20 < 0 )
return - V_21 ;
if ( V_20 > 0 )
V_183 -> V_297 |= V_298 ;
else if ( V_20 == 0 )
V_183 -> V_297 &= ~ V_298 ;
return V_89 ;
}
static void F_147 ( struct V_2 * V_3 )
{
struct V_1 * V_183 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_148 ( V_183 ) ;
}
static struct V_18 * F_149 (
struct V_18 * V_19 ,
const char * V_13 )
{
char * V_303 , * V_304 , * V_305 ;
struct V_1 * V_183 ;
char V_91 [ V_306 ] ;
unsigned long V_307 = 0 ;
int V_20 ;
memset ( V_91 , 0 , V_306 ) ;
if ( strlen ( V_13 ) >= V_306 ) {
F_14 ( L_220
L_221 , ( int ) strlen ( V_13 ) ,
V_306 ) ;
return F_15 ( - V_308 ) ;
}
snprintf ( V_91 , V_306 , L_29 , V_13 ) ;
V_304 = strstr ( V_91 , L_222 ) ;
if ( ! V_304 ) {
F_14 ( L_223 ) ;
return F_15 ( - V_21 ) ;
}
V_303 = V_91 ;
V_305 = strstr ( V_304 + 1 , L_222 ) ;
if ( V_305 ) {
* V_305 = '\0' ;
V_305 ++ ;
V_304 = V_305 ;
} else {
* V_304 = '\0' ;
V_304 ++ ;
}
V_20 = F_91 ( V_304 , 0 , & V_307 ) ;
if ( V_20 < 0 ) {
F_14 ( L_165
L_224 , V_20 ) ;
return F_15 ( - V_21 ) ;
}
F_150 () ;
V_183 = F_151 ( V_303 , V_307 , 0 ) ;
if ( F_76 ( V_183 ) )
return F_152 ( V_183 ) ;
F_17 ( & V_183 -> V_4 , V_13 ,
& V_309 ) ;
return & V_183 -> V_4 ;
}
static void F_153 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
F_21 ( V_3 ) ;
}
static int T_8 F_154 ( void )
{
struct V_18 * V_310 , * V_311 = NULL , * V_312 = NULL ;
struct V_18 * V_313 = NULL ;
struct V_78 * V_314 ;
struct V_204 * V_205 ;
int V_20 ;
F_12 ( L_225
L_226 V_8 L_3 ,
V_315 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_314 = V_42 [ 0 ] ;
F_155 ( & V_314 -> V_316 ) ;
F_156 ( & V_314 -> V_317 ) ;
V_20 = F_157 () ;
if ( V_20 < 0 )
return V_20 ;
V_310 = & V_314 -> V_316 ;
V_310 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_310 -> V_24 ) {
F_14 ( L_227 ) ;
goto V_318;
}
F_17 ( & V_319 ,
L_228 , & V_320 ) ;
V_310 -> V_24 [ 0 ] = & V_319 ;
V_310 -> V_24 [ 1 ] = NULL ;
V_311 = & V_319 ;
V_311 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_311 -> V_24 ) {
F_14 ( L_229 ) ;
goto V_318;
}
F_17 ( & V_321 ,
L_209 , & V_322 ) ;
V_311 -> V_24 [ 0 ] = & V_321 ;
V_311 -> V_24 [ 1 ] = NULL ;
V_312 = & V_321 ;
V_312 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_312 -> V_24 ) {
F_14 ( L_230 ) ;
goto V_318;
}
F_17 ( & V_323 ,
L_231 , & V_324 ) ;
V_312 -> V_24 [ 0 ] = & V_323 ;
V_312 -> V_24 [ 1 ] = NULL ;
V_205 = F_97 ( L_232 , 1 ) ;
if ( F_76 ( V_205 ) )
goto V_318;
V_313 = & V_323 ;
V_313 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_313 -> V_24 ) {
F_14 ( L_233 ) ;
goto V_318;
}
F_17 ( & V_205 -> V_213 , L_232 ,
& V_231 ) ;
V_313 -> V_24 [ 0 ] = & V_205 -> V_213 ;
V_313 -> V_24 [ 1 ] = NULL ;
V_325 = V_205 ;
V_20 = F_158 ( V_314 ) ;
if ( V_20 < 0 ) {
F_14 ( L_234 ,
V_20 , V_314 -> V_316 . V_28 . V_326 ) ;
goto V_318;
}
F_12 ( L_235
L_236 V_9 L_237
L_238 V_8 L_3 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_20 = F_159 () ;
if ( V_20 < 0 )
goto V_165;
if ( F_160 () < 0 )
goto V_165;
return 0 ;
V_165:
F_161 ( V_314 ) ;
F_162 () ;
F_163 () ;
V_318:
if ( V_325 ) {
F_95 ( V_325 ) ;
V_325 = NULL ;
}
if ( V_313 )
F_30 ( V_313 -> V_24 ) ;
if ( V_312 )
F_30 ( V_312 -> V_24 ) ;
if ( V_311 )
F_30 ( V_311 -> V_24 ) ;
F_30 ( V_310 -> V_24 ) ;
F_164 () ;
return V_20 ;
}
static void T_9 F_165 ( void )
{
struct V_78 * V_314 ;
struct V_18 * V_311 , * V_312 , * V_313 ;
struct V_2 * V_3 ;
int V_34 ;
V_314 = V_42 [ 0 ] ;
V_313 = & V_323 ;
for ( V_34 = 0 ; V_313 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_313 -> V_24 [ V_34 ] -> V_28 ;
V_313 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_313 -> V_24 ) ;
V_313 -> V_24 = NULL ;
V_312 = & V_321 ;
for ( V_34 = 0 ; V_312 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_312 -> V_24 [ V_34 ] -> V_28 ;
V_312 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_312 -> V_24 ) ;
V_312 -> V_24 = NULL ;
V_311 = & V_319 ;
for ( V_34 = 0 ; V_311 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_311 -> V_24 [ V_34 ] -> V_28 ;
V_311 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_311 -> V_24 ) ;
V_311 -> V_24 = NULL ;
F_161 ( V_314 ) ;
F_30 ( V_314 -> V_316 . V_24 ) ;
F_95 ( V_325 ) ;
V_325 = NULL ;
F_12 ( L_239
L_240 ) ;
F_162 () ;
F_163 () ;
F_164 () ;
}
