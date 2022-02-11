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
if ( ! V_45 -> V_78 ) {
F_14 ( L_65 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_79 ) {
F_14 ( L_66 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_80 ) {
F_14 ( L_67 ) ;
return - V_21 ;
}
if ( ! V_45 -> V_81 ) {
F_14 ( L_68 ) ;
return - V_21 ;
}
return 0 ;
}
int F_32 (
struct V_12 * V_14 )
{
int V_20 ;
if ( ! V_14 ) {
F_14 ( L_69
L_70 ) ;
return - V_21 ;
}
if ( ! V_14 -> V_31 ) {
F_14 ( L_71
L_70 ) ;
return - V_21 ;
}
V_20 = F_31 ( V_14 ) ;
if ( V_20 < 0 )
return V_20 ;
F_12 ( L_72
L_73 ) ;
return 0 ;
}
void F_33 (
struct V_12 * V_14 )
{
struct V_82 * V_83 ;
if ( ! V_14 ) {
F_14 ( L_74
L_75 ) ;
return;
}
V_83 = V_14 -> V_31 ;
if ( ! V_83 ) {
F_14 ( L_76
L_70 ) ;
return;
}
F_12 ( L_77
L_78 ) ;
F_7 ( & V_15 ) ;
if ( F_34 ( & V_14 -> V_17 ) ) {
F_10 ( & V_15 ) ;
F_14 ( L_79 ,
V_14 -> V_16 ) ;
F_35 () ;
}
F_29 ( & V_14 -> V_40 ) ;
F_10 ( & V_15 ) ;
F_12 ( L_80
L_5 , V_14 -> V_16 ) ;
V_14 -> V_41 = NULL ;
V_14 -> V_31 = NULL ;
F_30 ( V_14 ) ;
F_12 ( L_81
L_82 ) ;
}
static T_1 F_36 (
struct V_84 * V_84 ,
char * V_7 )
{
struct V_85 * V_86 = V_84 -> V_87 ;
struct V_88 * V_89 ;
V_89 = V_86 -> V_90 ;
if ( ! V_89 )
return - V_91 ;
return sprintf ( V_7 , L_83 ,
& V_84 -> V_92 [ 0 ] ) ;
}
static T_1 F_37 (
struct V_84 * V_84 ,
const char * V_7 ,
T_2 V_93 )
{
struct V_85 * V_94 = V_84 -> V_87 ;
struct V_88 * V_89 ;
unsigned char V_95 [ V_96 ] ;
if ( V_94 -> V_97 & V_98 ) {
F_14 ( L_84
L_85 ) ;
return - V_99 ;
}
if ( strlen ( V_7 ) >= V_96 ) {
F_14 ( L_86
L_87 , V_96 ) ;
return - V_100 ;
}
V_89 = V_94 -> V_90 ;
if ( V_89 ) {
if ( F_34 ( & V_89 -> V_101 . V_102 ) ) {
F_14 ( L_88
L_89 ,
F_34 ( & V_89 -> V_101 . V_102 ) ) ;
return - V_21 ;
}
}
memset ( V_95 , 0 , V_96 ) ;
snprintf ( V_95 , V_96 , L_29 , V_7 ) ;
snprintf ( V_94 -> V_84 . V_92 , V_96 ,
L_29 , F_38 ( V_95 ) ) ;
V_94 -> V_97 |= V_103 ;
F_12 ( L_90
L_5 , V_94 -> V_84 . V_92 ) ;
return V_93 ;
}
static T_1 F_39 (
struct V_84 * V_84 ,
char * V_7 )
{
struct V_85 * V_86 = V_84 -> V_87 ;
struct V_88 * V_89 ;
struct V_104 * V_105 ;
unsigned char V_95 [ V_106 ] ;
T_1 V_107 = 0 ;
V_89 = V_86 -> V_90 ;
if ( ! V_89 )
return - V_91 ;
memset ( V_95 , 0 , V_106 ) ;
F_40 ( & V_84 -> V_108 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_105 -> V_109 )
continue;
F_41 ( V_105 , V_95 , V_106 ) ;
if ( V_107 + strlen ( V_95 ) >= V_110 )
break;
V_107 += sprintf ( V_7 + V_107 , L_29 , V_95 ) ;
}
F_42 ( & V_84 -> V_108 ) ;
return V_107 ;
}
static T_1 F_43 (
struct V_84 * V_84 ,
const char * V_7 ,
T_2 V_93 )
{
return - V_111 ;
}
static T_1 F_44 (
struct V_84 * V_84 ,
const char * V_7 ,
T_2 V_93 )
{
return - V_111 ;
}
static T_1 F_45 (
struct V_84 * V_84 ,
const char * V_7 ,
T_2 V_93 )
{
return - V_111 ;
}
static T_1 F_46 (
struct V_84 * V_84 ,
const char * V_7 ,
T_2 V_93 )
{
return - V_111 ;
}
static T_1 F_47 (
struct V_88 * V_89 ,
char * V_7 ,
T_1 * V_107 )
{
struct V_112 * V_113 ;
struct V_114 * V_115 ;
char V_116 [ V_117 ] ;
int V_118 ;
memset ( V_116 , 0 , V_117 ) ;
F_40 ( & V_89 -> V_119 ) ;
V_115 = V_89 -> V_120 ;
if ( ! V_115 ) {
* V_107 += sprintf ( V_7 + * V_107 , L_91 ) ;
F_42 ( & V_89 -> V_119 ) ;
return * V_107 ;
}
V_113 = V_115 -> V_121 ;
V_118 = F_48 ( V_115 , & V_116 [ 0 ] ,
V_117 ) ;
* V_107 += sprintf ( V_7 + * V_107 , L_92 ,
V_113 -> V_122 -> V_123 -> V_46 () ,
V_113 -> V_124 , ( V_118 ) ? & V_116 [ 0 ] : L_93 ) ;
F_42 ( & V_89 -> V_119 ) ;
return * V_107 ;
}
static T_1 F_49 (
struct V_88 * V_89 ,
char * V_7 ,
T_1 * V_107 )
{
struct V_112 * V_113 ;
F_40 ( & V_89 -> V_119 ) ;
V_113 = V_89 -> V_125 ;
if ( ! V_113 ) {
* V_107 += sprintf ( V_7 + * V_107 , L_94 ) ;
F_42 ( & V_89 -> V_119 ) ;
return * V_107 ;
}
* V_107 += sprintf ( V_7 + * V_107 , L_95 ,
V_113 -> V_122 -> V_123 -> V_46 () ,
V_113 -> V_124 ) ;
F_42 ( & V_89 -> V_119 ) ;
return * V_107 ;
}
static T_1 F_50 (
struct V_85 * V_94 ,
char * V_7 )
{
T_1 V_107 = 0 ;
if ( ! V_94 -> V_90 )
return - V_91 ;
switch ( V_94 -> V_126 . V_127 ) {
case V_128 :
F_47 ( V_94 -> V_90 ,
V_7 , & V_107 ) ;
break;
case V_129 :
F_49 ( V_94 -> V_90 ,
V_7 , & V_107 ) ;
break;
case V_130 :
V_107 += sprintf ( V_7 + V_107 , L_96 ) ;
break;
default:
V_107 += sprintf ( V_7 + V_107 , L_97 ) ;
break;
}
return V_107 ;
}
static T_1 F_51 (
struct V_85 * V_94 ,
char * V_7 )
{
struct V_88 * V_89 ;
struct V_114 * V_115 ;
T_1 V_107 = 0 ;
V_89 = V_94 -> V_90 ;
if ( ! V_89 )
return - V_91 ;
if ( V_94 -> V_126 . V_127 != V_128 )
return V_107 ;
F_40 ( & V_89 -> V_119 ) ;
V_115 = V_89 -> V_120 ;
if ( ! V_115 ) {
V_107 = sprintf ( V_7 , L_91 ) ;
F_42 ( & V_89 -> V_119 ) ;
return V_107 ;
}
if ( V_115 -> V_131 )
V_107 = sprintf ( V_7 , L_98
L_99 ) ;
else
V_107 = sprintf ( V_7 , L_100
L_101 ) ;
F_42 ( & V_89 -> V_119 ) ;
return V_107 ;
}
static T_1 F_52 (
struct V_85 * V_94 ,
char * V_7 )
{
if ( ! V_94 -> V_90 )
return - V_91 ;
if ( V_94 -> V_126 . V_127 != V_128 )
return 0 ;
return sprintf ( V_7 , L_102 , V_94 -> V_126 . V_132 ) ;
}
static T_1 F_53 (
struct V_85 * V_94 ,
char * V_7 )
{
struct V_88 * V_89 ;
struct V_112 * V_113 ;
struct V_133 * V_134 ;
struct V_135 * V_122 ;
struct V_114 * V_115 ;
struct V_44 * V_45 ;
T_1 V_107 = 0 ;
V_89 = V_94 -> V_90 ;
if ( ! V_89 )
return - V_91 ;
if ( V_94 -> V_126 . V_127 != V_128 )
return V_107 ;
F_40 ( & V_89 -> V_119 ) ;
V_115 = V_89 -> V_120 ;
if ( ! V_115 ) {
V_107 = sprintf ( V_7 , L_91 ) ;
F_42 ( & V_89 -> V_119 ) ;
return V_107 ;
}
V_113 = V_115 -> V_121 ;
V_122 = V_113 -> V_122 ;
V_134 = V_115 -> V_136 ;
V_45 = V_122 -> V_123 ;
V_107 += sprintf ( V_7 + V_107 , L_103
L_104 , V_45 -> V_46 () ,
V_45 -> V_48 ( V_122 ) ) ;
V_107 += sprintf ( V_7 + V_107 , L_105
L_106
L_107 , V_134 -> V_137 -> V_138 ,
V_45 -> V_46 () , V_45 -> V_49 ( V_122 ) ,
V_45 -> V_46 () , V_134 -> V_139 ) ;
F_42 ( & V_89 -> V_119 ) ;
return V_107 ;
}
static T_1 F_54 (
struct V_85 * V_94 ,
char * V_7 )
{
struct V_44 * V_45 ;
struct V_114 * V_115 ;
unsigned char V_95 [ 384 ] ;
char V_116 [ V_117 ] ;
T_1 V_107 = 0 ;
int V_140 = 0 , V_118 ;
if ( ! V_94 -> V_90 )
return - V_91 ;
if ( V_94 -> V_126 . V_127 != V_128 )
return V_107 ;
V_107 += sprintf ( V_7 + V_107 , L_108 ) ;
F_40 ( & V_94 -> V_126 . V_141 ) ;
F_8 (pr_reg, &su_dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_95 , 0 , 384 ) ;
memset ( V_116 , 0 , V_117 ) ;
V_45 = V_115 -> V_121 -> V_122 -> V_123 ;
V_118 = F_48 ( V_115 , & V_116 [ 0 ] ,
V_117 ) ;
sprintf ( V_95 , L_109 ,
V_45 -> V_46 () ,
V_115 -> V_121 -> V_124 , ( V_118 ) ?
& V_116 [ 0 ] : L_93 , V_115 -> V_142 ,
V_115 -> V_143 ) ;
if ( V_107 + strlen ( V_95 ) >= V_110 )
break;
V_107 += sprintf ( V_7 + V_107 , L_29 , V_95 ) ;
V_140 ++ ;
}
F_42 ( & V_94 -> V_126 . V_141 ) ;
if ( ! V_140 )
V_107 += sprintf ( V_7 + V_107 , L_110 ) ;
return V_107 ;
}
static T_1 F_55 (
struct V_85 * V_94 ,
char * V_7 )
{
struct V_88 * V_89 ;
struct V_114 * V_115 ;
T_1 V_107 = 0 ;
V_89 = V_94 -> V_90 ;
if ( ! V_89 )
return - V_91 ;
if ( V_94 -> V_126 . V_127 != V_128 )
return V_107 ;
F_40 ( & V_89 -> V_119 ) ;
V_115 = V_89 -> V_120 ;
if ( ! V_115 ) {
V_107 = sprintf ( V_7 , L_91 ) ;
F_42 ( & V_89 -> V_119 ) ;
return V_107 ;
}
V_107 = sprintf ( V_7 , L_111 ,
F_56 ( V_115 -> V_144 ) ) ;
F_42 ( & V_89 -> V_119 ) ;
return V_107 ;
}
static T_1 F_57 (
struct V_85 * V_94 ,
char * V_7 )
{
T_1 V_107 = 0 ;
if ( ! V_94 -> V_90 )
return - V_91 ;
switch ( V_94 -> V_126 . V_127 ) {
case V_128 :
V_107 = sprintf ( V_7 , L_112 ) ;
break;
case V_129 :
V_107 = sprintf ( V_7 , L_113 ) ;
break;
case V_130 :
V_107 = sprintf ( V_7 , L_114 ) ;
break;
default:
V_107 = sprintf ( V_7 , L_115 ) ;
break;
}
return V_107 ;
}
static T_1 F_58 (
struct V_85 * V_94 ,
char * V_7 )
{
if ( ! V_94 -> V_90 )
return - V_91 ;
if ( V_94 -> V_126 . V_127 != V_128 )
return 0 ;
return sprintf ( V_7 , L_116 ,
( V_94 -> V_126 . V_145 ) ? L_117 : L_118 ) ;
}
static T_1 F_59 (
struct V_85 * V_94 ,
char * V_7 )
{
if ( ! V_94 -> V_90 )
return - V_91 ;
if ( V_94 -> V_126 . V_127 != V_128 )
return 0 ;
return sprintf ( V_7 , L_119 ) ;
}
static T_1 F_60 (
struct V_85 * V_94 ,
const char * V_7 ,
T_2 V_93 )
{
struct V_88 * V_89 ;
unsigned char * V_146 = NULL , * V_147 = NULL , * V_148 = NULL ;
unsigned char * V_149 = NULL , * V_150 = NULL ;
char * V_151 , * V_152 , * V_153 , * V_154 ;
T_3 args [ V_155 ] ;
unsigned long long V_156 ;
T_4 V_157 = 0 ;
T_5 V_158 = 0 , V_159 = 0 ;
int V_20 = - 1 , V_160 = 0 , V_161 = 0 , V_162 , V_163 ;
T_6 V_164 = 0 , V_165 = 0 ;
T_7 type = 0 , V_166 ;
V_89 = V_94 -> V_90 ;
if ( ! V_89 )
return - V_91 ;
if ( V_94 -> V_126 . V_127 != V_128 )
return 0 ;
if ( F_34 ( & V_89 -> V_101 . V_102 ) ) {
F_12 ( L_120
L_121 ) ;
return - V_21 ;
}
V_154 = F_61 ( V_7 , V_38 ) ;
if ( ! V_154 )
return - V_39 ;
V_151 = V_154 ;
while ( ( V_152 = F_62 ( & V_154 , L_122 ) ) != NULL ) {
if ( ! * V_152 )
continue;
V_163 = F_63 ( V_152 , V_167 , args ) ;
switch ( V_163 ) {
case V_168 :
V_146 = F_64 ( & args [ 0 ] ) ;
if ( ! V_146 ) {
V_20 = - V_39 ;
goto V_169;
}
break;
case V_170 :
V_147 = F_64 ( & args [ 0 ] ) ;
if ( ! V_147 ) {
V_20 = - V_39 ;
goto V_169;
}
if ( strlen ( V_147 ) >= V_171 ) {
F_14 ( L_123
L_124 ,
V_171 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_172 :
V_148 = F_64 ( & args [ 0 ] ) ;
if ( ! V_148 ) {
V_20 = - V_39 ;
goto V_169;
}
if ( strlen ( V_148 ) >= V_173 ) {
F_14 ( L_125
L_126 ,
V_173 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_174 :
V_153 = F_64 ( & args [ 0 ] ) ;
if ( ! V_153 ) {
V_20 = - V_39 ;
goto V_169;
}
V_20 = F_65 ( V_153 , 0 , & V_156 ) ;
if ( V_20 < 0 ) {
F_14 ( L_127
L_128 ) ;
goto V_169;
}
V_157 = ( T_4 ) V_156 ;
break;
case V_175 :
F_66 ( args , & V_162 ) ;
V_160 = V_162 ;
break;
case V_176 :
F_66 ( args , & V_162 ) ;
type = ( T_7 ) V_162 ;
break;
case V_177 :
F_66 ( args , & V_162 ) ;
V_166 = ( T_7 ) V_162 ;
break;
case V_178 :
F_66 ( args , & V_162 ) ;
V_161 = ( int ) V_162 ;
break;
case V_179 :
F_66 ( args , & V_162 ) ;
V_158 = ( T_5 ) V_162 ;
break;
case V_180 :
V_149 = F_64 ( & args [ 0 ] ) ;
if ( ! V_149 ) {
V_20 = - V_39 ;
goto V_169;
}
break;
case V_181 :
V_150 = F_64 ( & args [ 0 ] ) ;
if ( ! V_150 ) {
V_20 = - V_39 ;
goto V_169;
}
if ( strlen ( V_150 ) >= V_182 ) {
F_14 ( L_129
L_130 ,
V_182 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_183 :
F_66 ( args , & V_162 ) ;
V_165 = ( T_6 ) V_162 ;
break;
case V_184 :
F_66 ( args , & V_162 ) ;
V_164 = ( T_6 ) V_162 ;
break;
case V_185 :
F_66 ( args , & V_162 ) ;
V_159 = ( T_5 ) V_162 ;
break;
default:
break;
}
}
if ( ! V_147 || ! V_150 || ! V_157 ) {
F_14 ( L_131 ) ;
V_20 = - V_21 ;
goto V_169;
}
if ( V_160 && ! ( type ) ) {
F_14 ( L_132
L_133 , type ) ;
V_20 = - V_21 ;
goto V_169;
}
V_20 = F_67 ( & V_94 -> V_126 , V_157 ,
V_147 , V_148 , V_158 , V_150 , V_165 , V_159 ,
V_160 , V_161 , type ) ;
V_169:
F_30 ( V_146 ) ;
F_30 ( V_147 ) ;
F_30 ( V_148 ) ;
F_30 ( V_149 ) ;
F_30 ( V_150 ) ;
F_30 ( V_151 ) ;
return ( V_20 == 0 ) ? V_93 : V_20 ;
}
static T_1 F_68 ( void * V_186 , char * V_7 )
{
struct V_85 * V_86 = (struct V_85 * ) V_186 ;
struct V_1 * V_187 = V_86 -> V_188 ;
struct V_189 * V_190 = V_187 -> V_191 ;
int V_192 = 0 ;
T_1 V_193 = 0 ;
if ( ! V_86 -> V_90 )
return - V_91 ;
F_69 ( V_86 -> V_90 , V_7 , & V_192 ) ;
V_193 += V_192 ;
V_193 += V_190 -> V_194 ( V_187 , V_86 , V_7 + V_193 ) ;
return V_193 ;
}
static T_1 F_70 (
void * V_186 ,
const char * V_7 ,
T_2 V_93 )
{
struct V_85 * V_86 = (struct V_85 * ) V_186 ;
struct V_1 * V_187 = V_86 -> V_188 ;
struct V_189 * V_190 = V_187 -> V_191 ;
if ( ! V_86 -> V_195 ) {
F_14 ( L_134
L_135 ) ;
return - V_21 ;
}
return V_190 -> V_196 ( V_187 , V_86 , V_7 , V_93 ) ;
}
static T_1 F_71 ( void * V_186 , char * V_7 )
{
struct V_85 * V_86 = (struct V_85 * ) V_186 ;
if ( ! ( V_86 -> V_97 & V_197 ) )
return 0 ;
return snprintf ( V_7 , V_110 , L_136 , V_86 -> V_198 ) ;
}
static T_1 F_72 (
void * V_186 ,
const char * V_7 ,
T_2 V_93 )
{
struct V_85 * V_86 = (struct V_85 * ) V_186 ;
struct V_1 * V_187 = V_86 -> V_188 ;
T_1 V_193 ;
if ( V_93 > ( V_199 - 1 ) ) {
F_14 ( L_137
L_138 , ( int ) V_93 ,
V_199 - 1 ) ;
return - V_21 ;
}
V_86 -> V_97 |= V_197 ;
V_193 = snprintf ( & V_86 -> V_198 [ 0 ] , V_199 ,
L_29 , V_7 ) ;
F_12 ( L_139 ,
F_19 ( & V_187 -> V_4 . V_28 ) ,
F_19 ( & V_86 -> V_200 . V_28 ) ,
V_86 -> V_198 ) ;
return V_193 ;
}
static T_1 F_73 ( void * V_186 , char * V_7 )
{
struct V_85 * V_86 = (struct V_85 * ) V_186 ;
if ( ! ( V_86 -> V_97 & V_201 ) )
return 0 ;
return snprintf ( V_7 , V_110 , L_136 , V_86 -> V_202 ) ;
}
static T_1 F_74 (
void * V_186 ,
const char * V_7 ,
T_2 V_93 )
{
struct V_85 * V_86 = (struct V_85 * ) V_186 ;
struct V_1 * V_187 = V_86 -> V_188 ;
T_1 V_193 ;
if ( V_93 > ( V_203 - 1 ) ) {
F_14 ( L_140
L_141 , ( int ) V_93 ,
V_203 - 1 ) ;
return - V_21 ;
}
V_86 -> V_97 |= V_201 ;
V_193 = snprintf ( & V_86 -> V_202 [ 0 ] , V_203 ,
L_29 , V_7 ) ;
F_12 ( L_142 ,
F_19 ( & V_187 -> V_4 . V_28 ) ,
F_19 ( & V_86 -> V_200 . V_28 ) ,
V_86 -> V_202 ) ;
return V_193 ;
}
static T_1 F_75 (
void * V_186 ,
const char * V_7 ,
T_2 V_93 )
{
struct V_85 * V_86 = (struct V_85 * ) V_186 ;
struct V_88 * V_89 ;
struct V_1 * V_187 = V_86 -> V_188 ;
struct V_189 * V_190 = V_187 -> V_191 ;
char * V_152 ;
V_152 = strstr ( V_7 , L_143 ) ;
if ( ! V_152 ) {
F_14 ( L_144
L_145 ) ;
return - V_21 ;
}
if ( V_86 -> V_90 ) {
F_14 ( L_146
L_147 ) ;
return - V_204 ;
}
if ( V_190 -> V_205 ( V_187 , V_86 ) < 0 )
return - V_21 ;
V_89 = V_190 -> V_206 ( V_187 , V_86 , V_86 -> V_195 ) ;
if ( F_76 ( V_89 ) )
return F_77 ( V_89 ) ;
else if ( ! V_89 )
return - V_21 ;
V_86 -> V_90 = V_89 ;
F_12 ( L_148
L_149 , V_86 -> V_90 ) ;
return V_93 ;
}
static T_1 F_78 ( void * V_186 , char * V_7 )
{
struct V_88 * V_89 ;
struct V_85 * V_94 = (struct V_85 * ) V_186 ;
struct V_2 * V_207 ;
struct V_208 * V_209 ;
struct V_210 * V_211 ;
T_1 V_107 = 0 ;
V_89 = V_94 -> V_90 ;
if ( ! V_89 )
return - V_91 ;
if ( V_94 -> V_212 . V_213 != V_214 )
return V_107 ;
V_211 = V_89 -> V_215 ;
if ( ! V_211 ) {
F_14 ( L_150
L_70 ) ;
return - V_21 ;
}
F_40 ( & V_211 -> V_216 ) ;
V_209 = V_211 -> V_209 ;
if ( V_209 ) {
V_207 = & V_209 -> V_217 . V_28 ;
V_107 += sprintf ( V_7 , L_151 ,
F_19 ( V_207 ) , V_209 -> V_218 ) ;
}
F_42 ( & V_211 -> V_216 ) ;
return V_107 ;
}
static T_1 F_79 (
void * V_186 ,
const char * V_7 ,
T_2 V_93 )
{
struct V_88 * V_89 ;
struct V_85 * V_94 = (struct V_85 * ) V_186 ;
struct V_1 * V_187 = V_94 -> V_188 ;
struct V_208 * V_209 = NULL , * V_219 = NULL ;
struct V_210 * V_211 ;
unsigned char V_95 [ V_220 ] ;
int V_221 = 0 ;
V_89 = V_94 -> V_90 ;
if ( ! V_89 )
return - V_91 ;
if ( V_94 -> V_212 . V_213 != V_214 ) {
F_80 ( L_152 ,
F_19 ( & V_187 -> V_4 . V_28 ) ,
F_19 ( & V_94 -> V_200 . V_28 ) ) ;
return - V_21 ;
}
if ( V_93 > V_220 ) {
F_14 ( L_153 ) ;
return - V_21 ;
}
memset ( V_95 , 0 , V_220 ) ;
memcpy ( V_95 , V_7 , V_93 ) ;
if ( strcmp ( F_38 ( V_95 ) , L_154 ) ) {
V_219 = F_81 ( F_38 ( V_95 ) ) ;
if ( ! V_219 )
return - V_91 ;
}
V_211 = V_89 -> V_215 ;
if ( ! V_211 ) {
if ( V_219 )
F_82 ( V_219 ) ;
F_14 ( L_150
L_70 ) ;
return - V_21 ;
}
F_40 ( & V_211 -> V_216 ) ;
V_209 = V_211 -> V_209 ;
if ( V_209 ) {
if ( ! V_219 ) {
F_12 ( L_155
L_156
L_157 ,
F_19 ( & V_187 -> V_4 . V_28 ) ,
F_19 ( & V_94 -> V_200 . V_28 ) ,
F_19 ( & V_209 -> V_217 . V_28 ) ,
V_209 -> V_218 ) ;
F_83 ( V_211 , V_209 ) ;
F_42 ( & V_211 -> V_216 ) ;
return V_93 ;
}
F_83 ( V_211 , V_209 ) ;
V_221 = 1 ;
}
F_84 ( V_211 , V_219 ) ;
F_42 ( & V_211 -> V_216 ) ;
F_12 ( L_158
L_159 ,
( V_221 ) ? L_160 : L_161 ,
F_19 ( & V_187 -> V_4 . V_28 ) ,
F_19 ( & V_94 -> V_200 . V_28 ) ,
F_19 ( & V_219 -> V_217 . V_28 ) ,
V_219 -> V_218 ) ;
F_82 ( V_219 ) ;
return V_93 ;
}
static void F_85 ( struct V_2 * V_3 )
{
struct V_85 * V_86 = F_2 ( F_3 ( V_3 ) ,
struct V_85 , V_200 ) ;
struct V_1 * V_187 = F_1 ( & V_86 -> V_188 -> V_4 . V_28 ) ;
struct V_189 * V_190 = V_187 -> V_191 ;
struct V_18 * V_222 = & V_86 -> V_200 ;
F_30 ( V_222 -> V_24 ) ;
if ( V_86 -> V_90 ) {
F_12 ( L_162
L_163 ,
V_86 -> V_90 ) ;
F_86 ( V_86 -> V_90 , V_187 ) ;
} else {
F_12 ( L_164
L_165 ,
V_86 -> V_195 ) ;
V_190 -> V_223 ( V_86 -> V_195 ) ;
}
F_12 ( L_166
L_167 , V_86 ) ;
F_30 ( V_86 ) ;
}
static T_1 F_87 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
char * V_7 )
{
struct V_85 * V_86 = F_2 (
F_3 ( V_3 ) , struct V_85 ,
V_200 ) ;
struct V_224 * V_225 = F_2 (
V_6 , struct V_224 , V_6 ) ;
if ( ! V_225 -> V_226 )
return - V_21 ;
return V_225 -> V_226 ( V_86 , V_7 ) ;
}
static T_1 F_88 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
const char * V_7 , T_2 V_93 )
{
struct V_85 * V_86 = F_2 (
F_3 ( V_3 ) , struct V_85 ,
V_200 ) ;
struct V_224 * V_225 = F_2 (
V_6 , struct V_224 , V_6 ) ;
if ( ! V_225 -> V_227 )
return - V_21 ;
return V_225 -> V_227 ( V_86 , V_7 , V_93 ) ;
}
static T_1 F_89 (
struct V_208 * V_209 ,
char * V_7 )
{
if ( ! V_209 -> V_228 )
return 0 ;
return sprintf ( V_7 , L_168 , V_209 -> V_218 ) ;
}
static T_1 F_90 (
struct V_208 * V_209 ,
const char * V_7 ,
T_2 V_93 )
{
struct V_18 * V_229 = & V_209 -> V_217 ;
unsigned long V_218 ;
int V_20 ;
V_20 = F_91 ( V_7 , 0 , & V_218 ) ;
if ( V_20 < 0 ) {
F_14 ( L_169
L_170 , V_20 ) ;
return - V_21 ;
}
if ( V_218 > 0x0000ffff ) {
F_14 ( L_171
L_172 , V_218 ) ;
return - V_21 ;
}
V_20 = F_92 ( V_209 , ( T_6 ) V_218 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_173
L_174 ,
F_19 ( & V_229 -> V_28 ) ,
V_209 -> V_218 ) ;
return V_93 ;
}
static T_1 F_93 (
struct V_208 * V_209 ,
char * V_7 )
{
struct V_88 * V_89 ;
struct V_1 * V_187 ;
struct V_85 * V_94 ;
struct V_210 * V_211 ;
T_1 V_107 = 0 , V_230 ;
unsigned char V_95 [ V_220 ] ;
memset ( V_95 , 0 , V_220 ) ;
F_40 ( & V_209 -> V_231 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_89 = V_211 -> V_232 ;
V_94 = V_89 -> V_233 ;
V_187 = V_94 -> V_188 ;
V_230 = snprintf ( V_95 , V_220 , L_175 ,
F_19 ( & V_187 -> V_4 . V_28 ) ,
F_19 ( & V_94 -> V_200 . V_28 ) ) ;
V_230 ++ ;
if ( ( V_230 + V_107 ) > V_110 ) {
F_80 ( L_176
L_177 ) ;
break;
}
memcpy ( V_7 + V_107 , V_95 , V_230 ) ;
V_107 += V_230 ;
}
F_42 ( & V_209 -> V_231 ) ;
return V_107 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_208 * V_209 = F_2 ( F_3 ( V_3 ) ,
struct V_208 , V_217 ) ;
F_95 ( V_209 ) ;
}
static struct V_18 * F_96 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_208 * V_209 ;
struct V_18 * V_229 = NULL ;
struct V_2 * V_234 = NULL ;
V_209 = F_97 ( V_13 , 0 ) ;
if ( F_76 ( V_209 ) )
return NULL ;
V_229 = & V_209 -> V_217 ;
V_234 = & V_229 -> V_28 ;
F_17 ( V_229 , V_13 ,
& V_235 ) ;
F_12 ( L_178
L_179 ,
F_19 ( V_234 ) ) ;
return V_229 ;
}
static void F_98 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_208 * V_209 = F_2 ( F_3 ( V_3 ) ,
struct V_208 , V_217 ) ;
F_12 ( L_180
L_181 ,
F_19 ( V_3 ) , V_209 -> V_218 ) ;
F_21 ( V_3 ) ;
}
static T_1 F_99 (
struct V_236 * V_237 ,
char * V_7 )
{
return sprintf ( V_7 , L_182 ,
F_34 ( & V_237 -> V_238 ) ) ;
}
static T_1 F_100 (
struct V_236 * V_237 ,
const char * V_7 ,
T_2 V_93 )
{
struct V_85 * V_94 = V_237 -> V_239 ;
unsigned long V_240 ;
int V_241 , V_20 ;
if ( ! V_237 -> V_242 ) {
F_14 ( L_183
L_184 , V_237 -> V_242 ) ;
return - V_21 ;
}
V_20 = F_91 ( V_7 , 0 , & V_240 ) ;
if ( V_20 < 0 ) {
F_14 ( L_185
L_5 , V_7 ) ;
return - V_21 ;
}
V_241 = ( int ) V_240 ;
if ( ! ( V_237 -> V_243 & V_244 ) ) {
F_14 ( L_186
L_187 ) ;
return - V_21 ;
}
V_20 = F_101 ( V_237 , V_94 -> V_90 ,
NULL , NULL , V_241 , 0 ) ;
return ( ! V_20 ) ? V_93 : - V_21 ;
}
static T_1 F_102 (
struct V_236 * V_237 ,
char * V_7 )
{
return sprintf ( V_7 , L_136 ,
F_103 ( V_237 -> V_245 ) ) ;
}
static T_1 F_104 (
struct V_236 * V_237 ,
const char * V_7 ,
T_2 V_93 )
{
unsigned long V_240 ;
int V_246 , V_20 ;
if ( ! V_237 -> V_242 ) {
F_14 ( L_188
L_189 ,
V_237 -> V_242 ) ;
return - V_21 ;
}
V_20 = F_91 ( V_7 , 0 , & V_240 ) ;
if ( V_20 < 0 ) {
F_14 ( L_190
L_191 , V_7 ) ;
return - V_21 ;
}
V_246 = ( int ) V_240 ;
if ( ( V_246 != V_247 ) &&
( V_246 != V_248 ) &&
( V_246 != V_249 ) ) {
F_14 ( L_192 ,
V_246 ) ;
return - V_21 ;
}
V_237 -> V_245 = V_246 ;
return V_93 ;
}
static T_1 F_105 (
struct V_236 * V_237 ,
char * V_7 )
{
return F_106 ( V_237 , V_7 ) ;
}
static T_1 F_107 (
struct V_236 * V_237 ,
const char * V_7 ,
T_2 V_93 )
{
return F_108 ( V_237 , V_7 , V_93 ) ;
}
static T_1 F_109 (
struct V_236 * V_237 ,
char * V_7 )
{
return sprintf ( V_7 , L_182 , V_237 -> V_250 ) ;
}
static T_1 F_110 (
struct V_236 * V_237 ,
const char * V_7 ,
T_2 V_93 )
{
unsigned long V_240 ;
int V_20 ;
V_20 = F_91 ( V_7 , 0 , & V_240 ) ;
if ( V_20 < 0 ) {
F_14 ( L_193 ) ;
return - V_21 ;
}
if ( ( V_240 != 0 ) && ( V_240 != 1 ) ) {
F_14 ( L_194
L_195 , V_240 ) ;
return - V_21 ;
}
V_237 -> V_250 = ( int ) V_240 ;
return V_93 ;
}
static T_1 F_111 (
struct V_236 * V_237 ,
char * V_7 )
{
return F_112 ( V_237 , V_7 ) ;
}
static T_1 F_113 (
struct V_236 * V_237 ,
const char * V_7 ,
T_2 V_93 )
{
return F_114 ( V_237 , V_7 , V_93 ) ;
}
static T_1 F_115 (
struct V_236 * V_237 ,
char * V_7 )
{
return F_116 ( V_237 , V_7 ) ;
}
static T_1 F_117 (
struct V_236 * V_237 ,
const char * V_7 ,
T_2 V_93 )
{
return F_118 ( V_237 , V_7 , V_93 ) ;
}
static T_1 F_119 (
struct V_236 * V_237 ,
char * V_7 )
{
return F_120 ( V_237 , V_7 ) ;
}
static T_1 F_121 (
struct V_236 * V_237 ,
const char * V_7 ,
T_2 V_93 )
{
return F_122 ( V_237 , V_7 , V_93 ) ;
}
static T_1 F_123 (
struct V_236 * V_237 ,
char * V_7 )
{
if ( ! V_237 -> V_242 )
return 0 ;
return sprintf ( V_7 , L_168 , V_237 -> V_251 ) ;
}
static T_1 F_124 (
struct V_236 * V_237 ,
const char * V_7 ,
T_2 V_93 )
{
struct V_18 * V_252 = & V_237 -> V_253 ;
unsigned long V_251 ;
int V_20 ;
V_20 = F_91 ( V_7 , 0 , & V_251 ) ;
if ( V_20 < 0 ) {
F_14 ( L_169
L_196 , V_20 ) ;
return - V_21 ;
}
if ( V_251 > 0x0000ffff ) {
F_14 ( L_197
L_172 , V_251 ) ;
return - V_21 ;
}
V_20 = F_125 ( V_237 , ( T_6 ) V_251 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_198
L_199 ,
F_19 ( & V_252 -> V_28 ) ,
V_237 -> V_251 ) ;
return V_93 ;
}
static T_1 F_126 (
struct V_236 * V_237 ,
char * V_7 )
{
struct V_254 * V_255 ;
struct V_135 * V_256 ;
struct V_133 * V_134 ;
struct V_257 * V_258 ;
T_1 V_107 = 0 , V_230 ;
unsigned char V_95 [ V_259 ] ;
memset ( V_95 , 0 , V_259 ) ;
F_40 ( & V_237 -> V_260 ) ;
F_8 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_255 = V_258 -> V_261 ;
V_256 = V_255 -> V_262 ;
V_134 = V_255 -> V_263 ;
V_230 = snprintf ( V_95 , V_259 , L_200
L_201 , V_256 -> V_123 -> V_46 () ,
V_256 -> V_123 -> V_48 ( V_256 ) ,
V_256 -> V_123 -> V_49 ( V_256 ) ,
F_19 ( & V_134 -> V_264 . V_28 ) ) ;
V_230 ++ ;
if ( ( V_230 + V_107 ) > V_110 ) {
F_80 ( L_176
L_177 ) ;
break;
}
memcpy ( V_7 + V_107 , V_95 , V_230 ) ;
V_107 += V_230 ;
}
F_42 ( & V_237 -> V_260 ) ;
return V_107 ;
}
static void F_127 ( struct V_2 * V_3 )
{
struct V_236 * V_237 = F_2 ( F_3 ( V_3 ) ,
struct V_236 , V_253 ) ;
F_128 ( V_237 ) ;
}
static struct V_18 * F_129 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_212 * V_265 = F_2 ( V_19 , struct V_212 ,
V_266 ) ;
struct V_236 * V_237 ;
struct V_85 * V_94 = V_265 -> V_87 ;
struct V_18 * V_252 = NULL ;
struct V_2 * V_267 = NULL ;
V_237 = F_130 ( V_94 , V_13 , 0 ) ;
if ( ! V_237 )
return NULL ;
V_252 = & V_237 -> V_253 ;
V_267 = & V_252 -> V_28 ;
F_17 ( V_252 , V_13 ,
& V_268 ) ;
F_12 ( L_202
L_203 ,
F_19 ( V_267 ) ) ;
return V_252 ;
}
static void F_131 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_236 * V_237 = F_2 ( F_3 ( V_3 ) ,
struct V_236 , V_253 ) ;
F_12 ( L_204
L_205 ,
F_19 ( V_3 ) , V_237 -> V_251 ) ;
F_21 ( V_3 ) ;
}
static struct V_18 * F_132 (
struct V_18 * V_19 ,
const char * V_13 )
{
return F_15 ( - V_111 ) ;
}
static void F_133 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
return;
}
static struct V_18 * F_134 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_236 * V_237 ;
struct V_85 * V_86 ;
struct V_189 * V_190 ;
struct V_2 * V_269 = & V_19 -> V_28 ;
struct V_1 * V_187 = F_1 ( V_269 ) ;
struct V_18 * V_222 = NULL , * V_270 = NULL ;
struct V_18 * V_271 = NULL ;
int V_272 = - V_39 , V_20 ;
V_20 = F_135 ( & V_187 -> V_273 ) ;
if ( V_20 )
return F_15 ( V_20 ) ;
V_190 = V_187 -> V_191 ;
V_86 = F_23 ( sizeof( struct V_85 ) , V_38 ) ;
if ( ! V_86 ) {
F_14 ( L_206
L_207 ) ;
goto V_274;
}
F_24 ( & V_86 -> V_84 . V_275 ) ;
F_136 ( & V_86 -> V_84 . V_108 ) ;
F_24 ( & V_86 -> V_126 . V_276 ) ;
F_24 ( & V_86 -> V_126 . V_277 ) ;
F_136 ( & V_86 -> V_126 . V_141 ) ;
F_136 ( & V_86 -> V_126 . V_278 ) ;
F_24 ( & V_86 -> V_212 . V_279 ) ;
F_136 ( & V_86 -> V_212 . V_280 ) ;
F_136 ( & V_86 -> V_281 ) ;
V_86 -> V_126 . V_282 = V_283 ;
V_86 -> V_84 . V_87 = V_86 ;
V_86 -> V_212 . V_87 = V_86 ;
V_86 -> V_284 . V_285 = V_86 ;
V_86 -> V_188 = V_187 ;
V_222 = & V_86 -> V_200 ;
V_222 -> V_24 = F_23 ( sizeof( struct V_18 ) * 7 ,
V_38 ) ;
if ( ! V_222 -> V_24 )
goto V_169;
V_86 -> V_195 = V_190 -> V_286 ( V_187 , V_13 ) ;
if ( ! V_86 -> V_195 ) {
F_14 ( L_208
L_209 ) ;
goto V_169;
}
F_17 ( & V_86 -> V_200 , V_13 ,
& V_287 ) ;
F_17 ( & V_86 -> V_284 . V_288 , L_210 ,
& V_289 ) ;
F_17 ( & V_86 -> V_290 , L_211 ,
& V_291 ) ;
F_17 ( & V_86 -> V_84 . V_292 , L_212 ,
& V_293 ) ;
F_17 ( & V_86 -> V_212 . V_266 ,
L_213 , & V_294 ) ;
F_17 ( & V_86 -> V_295 . V_296 ,
L_214 , & V_297 ) ;
V_222 -> V_24 [ 0 ] = & V_86 -> V_284 . V_288 ;
V_222 -> V_24 [ 1 ] = & V_86 -> V_290 ;
V_222 -> V_24 [ 2 ] = & V_86 -> V_84 . V_292 ;
V_222 -> V_24 [ 3 ] = & V_86 -> V_212 . V_266 ;
V_222 -> V_24 [ 4 ] = & V_86 -> V_295 . V_296 ;
V_222 -> V_24 [ 5 ] = NULL ;
V_237 = F_130 ( V_86 , L_215 , 1 ) ;
if ( ! V_237 )
goto V_169;
V_270 = & V_86 -> V_212 . V_266 ;
V_270 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_270 -> V_24 ) {
F_14 ( L_216
L_217 ) ;
goto V_169;
}
F_17 ( & V_237 -> V_253 ,
L_215 , & V_268 ) ;
V_270 -> V_24 [ 0 ] = & V_237 -> V_253 ;
V_270 -> V_24 [ 1 ] = NULL ;
V_86 -> V_212 . V_298 = V_237 ;
V_271 = & V_86 -> V_295 . V_296 ;
V_271 -> V_24 = F_23 ( sizeof( struct V_18 ) * 4 ,
V_38 ) ;
if ( ! V_271 -> V_24 ) {
F_14 ( L_218 ) ;
goto V_169;
}
F_137 ( V_86 ) ;
F_12 ( L_219
L_220 , V_86 , V_86 -> V_195 ) ;
F_10 ( & V_187 -> V_273 ) ;
return & V_86 -> V_200 ;
V_169:
if ( V_86 -> V_212 . V_298 ) {
F_128 ( V_86 -> V_212 . V_298 ) ;
V_86 -> V_212 . V_298 = NULL ;
}
if ( V_271 )
F_30 ( V_271 -> V_24 ) ;
if ( V_270 )
F_30 ( V_270 -> V_24 ) ;
if ( V_222 )
F_30 ( V_222 -> V_24 ) ;
if ( V_86 -> V_195 )
V_190 -> V_223 ( V_86 -> V_195 ) ;
F_30 ( V_86 ) ;
V_274:
F_10 ( & V_187 -> V_273 ) ;
return F_15 ( V_272 ) ;
}
static void F_138 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_85 * V_86 = F_2 ( F_3 ( V_3 ) ,
struct V_85 , V_200 ) ;
struct V_1 * V_187 ;
struct V_189 * V_190 ;
struct V_2 * V_33 ;
struct V_18 * V_222 , * V_270 , * V_271 ;
int V_34 ;
V_187 = F_1 ( & V_86 -> V_188 -> V_4 . V_28 ) ;
F_7 ( & V_187 -> V_273 ) ;
V_190 = V_187 -> V_191 ;
V_271 = & V_86 -> V_295 . V_296 ;
for ( V_34 = 0 ; V_271 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_271 -> V_24 [ V_34 ] -> V_28 ;
V_271 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_30 ( V_271 -> V_24 ) ;
V_270 = & V_86 -> V_212 . V_266 ;
for ( V_34 = 0 ; V_270 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_270 -> V_24 [ V_34 ] -> V_28 ;
V_270 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_30 ( V_270 -> V_24 ) ;
V_86 -> V_212 . V_298 = NULL ;
V_222 = & V_86 -> V_200 ;
for ( V_34 = 0 ; V_222 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_222 -> V_24 [ V_34 ] -> V_28 ;
V_222 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_21 ( V_3 ) ;
F_10 ( & V_187 -> V_273 ) ;
}
static T_1 F_139 (
struct V_1 * V_187 ,
char * V_7 )
{
return sprintf ( V_7 , L_221 ,
V_187 -> V_299 , V_187 -> V_191 -> V_13 ,
V_9 ) ;
}
static T_1 F_140 ( struct V_1 * V_187 ,
char * V_7 )
{
int V_300 = 0 ;
if ( V_187 -> V_301 & V_302 )
V_300 = 1 ;
return sprintf ( V_7 , L_182 , V_300 ) ;
}
static T_1 F_141 ( struct V_1 * V_187 ,
const char * V_7 , T_2 V_93 )
{
struct V_189 * V_191 = V_187 -> V_191 ;
unsigned long V_303 ;
int V_20 ;
if ( V_191 -> V_304 == NULL )
return - V_21 ;
V_20 = F_91 ( V_7 , 0 , & V_303 ) ;
if ( V_20 < 0 ) {
F_14 ( L_222 , V_20 ) ;
return - V_21 ;
}
F_40 ( & V_187 -> V_305 ) ;
if ( ! F_142 ( & V_187 -> V_306 ) ) {
F_14 ( L_223 ) ;
F_42 ( & V_187 -> V_305 ) ;
return - V_21 ;
}
F_42 ( & V_187 -> V_305 ) ;
V_20 = V_191 -> V_304 ( V_187 , V_303 ) ;
if ( V_20 < 0 )
return - V_21 ;
if ( V_20 > 0 )
V_187 -> V_301 |= V_302 ;
else if ( V_20 == 0 )
V_187 -> V_301 &= ~ V_302 ;
return V_93 ;
}
static void F_143 ( struct V_2 * V_3 )
{
struct V_1 * V_187 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_144 ( V_187 ) ;
}
static struct V_18 * F_145 (
struct V_18 * V_19 ,
const char * V_13 )
{
char * V_307 , * V_308 , * V_309 ;
struct V_1 * V_187 ;
char V_95 [ V_310 ] ;
unsigned long V_311 = 0 ;
int V_20 ;
memset ( V_95 , 0 , V_310 ) ;
if ( strlen ( V_13 ) >= V_310 ) {
F_14 ( L_224
L_225 , ( int ) strlen ( V_13 ) ,
V_310 ) ;
return F_15 ( - V_312 ) ;
}
snprintf ( V_95 , V_310 , L_29 , V_13 ) ;
V_308 = strstr ( V_95 , L_226 ) ;
if ( ! V_308 ) {
F_14 ( L_227 ) ;
return F_15 ( - V_21 ) ;
}
V_307 = V_95 ;
V_309 = strstr ( V_308 + 1 , L_226 ) ;
if ( V_309 ) {
* V_309 = '\0' ;
V_309 ++ ;
V_308 = V_309 ;
} else {
* V_308 = '\0' ;
V_308 ++ ;
}
V_20 = F_91 ( V_308 , 0 , & V_311 ) ;
if ( V_20 < 0 ) {
F_14 ( L_169
L_228 , V_20 ) ;
return F_15 ( - V_21 ) ;
}
F_146 () ;
V_187 = F_147 ( V_307 , V_311 , 0 ) ;
if ( F_76 ( V_187 ) )
return F_148 ( V_187 ) ;
F_17 ( & V_187 -> V_4 , V_13 ,
& V_313 ) ;
return & V_187 -> V_4 ;
}
static void F_149 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
F_21 ( V_3 ) ;
}
static int T_8 F_150 ( void )
{
struct V_18 * V_314 , * V_315 = NULL , * V_316 = NULL ;
struct V_18 * V_317 = NULL ;
struct V_82 * V_318 ;
struct V_208 * V_209 ;
int V_20 ;
F_12 ( L_229
L_230 V_8 L_3 ,
V_319 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_318 = V_42 [ 0 ] ;
F_151 ( & V_318 -> V_320 ) ;
F_152 ( & V_318 -> V_321 ) ;
F_24 ( & V_43 ) ;
F_152 ( & V_15 ) ;
V_20 = F_153 () ;
if ( V_20 < 0 )
return V_20 ;
V_314 = & V_318 -> V_320 ;
V_314 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_314 -> V_24 ) {
F_14 ( L_231 ) ;
goto V_322;
}
F_17 ( & V_323 ,
L_232 , & V_324 ) ;
V_314 -> V_24 [ 0 ] = & V_323 ;
V_314 -> V_24 [ 1 ] = NULL ;
V_315 = & V_323 ;
V_315 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_315 -> V_24 ) {
F_14 ( L_233 ) ;
goto V_322;
}
F_17 ( & V_325 ,
L_213 , & V_326 ) ;
V_315 -> V_24 [ 0 ] = & V_325 ;
V_315 -> V_24 [ 1 ] = NULL ;
V_316 = & V_325 ;
V_316 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_316 -> V_24 ) {
F_14 ( L_234 ) ;
goto V_322;
}
F_17 ( & V_327 ,
L_235 , & V_328 ) ;
V_316 -> V_24 [ 0 ] = & V_327 ;
V_316 -> V_24 [ 1 ] = NULL ;
V_209 = F_97 ( L_236 , 1 ) ;
if ( F_76 ( V_209 ) )
goto V_322;
V_317 = & V_327 ;
V_317 -> V_24 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_317 -> V_24 ) {
F_14 ( L_237 ) ;
goto V_322;
}
F_17 ( & V_209 -> V_217 , L_236 ,
& V_235 ) ;
V_317 -> V_24 [ 0 ] = & V_209 -> V_217 ;
V_317 -> V_24 [ 1 ] = NULL ;
V_329 = V_209 ;
V_20 = F_154 ( V_318 ) ;
if ( V_20 < 0 ) {
F_14 ( L_238 ,
V_20 , V_318 -> V_320 . V_28 . V_330 ) ;
goto V_322;
}
F_12 ( L_239
L_240 V_9 L_241
L_242 V_8 L_3 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_20 = F_155 () ;
if ( V_20 < 0 )
goto V_169;
if ( F_156 () < 0 )
goto V_169;
return 0 ;
V_169:
F_157 ( V_318 ) ;
F_158 () ;
F_159 () ;
V_322:
if ( V_329 ) {
F_95 ( V_329 ) ;
V_329 = NULL ;
}
if ( V_317 )
F_30 ( V_317 -> V_24 ) ;
if ( V_316 )
F_30 ( V_316 -> V_24 ) ;
if ( V_315 )
F_30 ( V_315 -> V_24 ) ;
F_30 ( V_314 -> V_24 ) ;
F_160 () ;
return V_20 ;
}
static void T_9 F_161 ( void )
{
struct V_82 * V_318 ;
struct V_18 * V_315 , * V_316 , * V_317 ;
struct V_2 * V_3 ;
int V_34 ;
V_318 = V_42 [ 0 ] ;
V_317 = & V_327 ;
for ( V_34 = 0 ; V_317 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_317 -> V_24 [ V_34 ] -> V_28 ;
V_317 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_317 -> V_24 ) ;
V_317 -> V_24 = NULL ;
V_316 = & V_325 ;
for ( V_34 = 0 ; V_316 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_316 -> V_24 [ V_34 ] -> V_28 ;
V_316 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_316 -> V_24 ) ;
V_316 -> V_24 = NULL ;
V_315 = & V_323 ;
for ( V_34 = 0 ; V_315 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_315 -> V_24 [ V_34 ] -> V_28 ;
V_315 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_315 -> V_24 ) ;
V_315 -> V_24 = NULL ;
F_157 ( V_318 ) ;
F_30 ( V_318 -> V_320 . V_24 ) ;
F_95 ( V_329 ) ;
V_329 = NULL ;
F_12 ( L_243
L_244 ) ;
F_158 () ;
F_159 () ;
F_160 () ;
}
