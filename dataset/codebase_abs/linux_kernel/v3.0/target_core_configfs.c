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
if ( ! ( V_13 ) )
return NULL ;
F_7 ( & V_15 ) ;
F_8 (tf, &g_tf_list, tf_list) {
if ( ! ( strcmp ( V_14 -> V_16 , V_13 ) ) ) {
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
F_12 ( V_21 L_4
L_5 , V_19 , V_13 ) ;
if ( F_13 () < 0 )
return F_14 ( - V_22 ) ;
if ( ! ( strncmp ( V_13 , L_6 , 5 ) ) ) {
V_20 = F_15 ( L_7 ) ;
if ( V_20 < 0 ) {
F_12 ( V_23 L_8
L_9 , V_20 ) ;
return F_14 ( - V_22 ) ;
}
} else if ( ! ( strncmp ( V_13 , L_10 , 8 ) ) ) {
V_20 = F_15 ( L_11 ) ;
if ( V_20 < 0 ) {
F_12 ( V_23 L_8
L_12 , V_20 ) ;
return F_14 ( - V_22 ) ;
}
}
V_14 = F_6 ( V_13 ) ;
if ( ! ( V_14 ) ) {
F_12 ( V_23 L_13 ,
V_13 ) ;
return F_14 ( - V_22 ) ;
}
F_12 ( V_21 L_14
L_5 , V_14 -> V_16 ) ;
F_12 ( V_21 L_15 ,
& F_16 ( V_14 ) -> V_24 ) ;
V_14 -> V_25 . V_26 = V_14 -> V_27 ;
V_14 -> V_25 . V_26 [ 0 ] = & V_14 -> V_28 ;
V_14 -> V_25 . V_26 [ 1 ] = NULL ;
F_17 ( & V_14 -> V_25 , V_13 ,
& F_16 ( V_14 ) -> V_24 ) ;
F_17 ( & V_14 -> V_28 , L_16 ,
& F_16 ( V_14 ) -> V_29 ) ;
F_12 ( V_21 L_17
L_5 , V_14 -> V_25 . V_30 . V_31 ) ;
V_14 -> V_32 . V_33 = V_14 -> V_33 ;
V_14 -> V_34 = & V_14 -> V_25 . V_30 ;
F_12 ( V_21 L_18
L_19 , V_13 ) ;
return & V_14 -> V_25 ;
}
static void F_18 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_12 * V_14 = F_2 (
F_3 ( V_3 ) , struct V_12 , V_25 ) ;
struct V_18 * V_25 ;
struct V_2 * V_35 ;
int V_36 ;
F_12 ( V_21 L_20
L_21 , F_19 ( V_3 ) ) ;
F_12 ( V_21 L_22
L_5 , V_14 -> V_16 ) ;
F_20 ( & V_14 -> V_17 ) ;
F_12 ( V_21 L_23
L_24 , V_14 -> V_16 ) ;
V_14 -> V_34 = NULL ;
F_12 ( V_21 L_25
L_5 , F_19 ( V_3 ) ) ;
V_25 = & V_14 -> V_25 ;
for ( V_36 = 0 ; V_25 -> V_26 [ V_36 ] ; V_36 ++ ) {
V_35 = & V_25 -> V_26 [ V_36 ] -> V_30 ;
V_25 -> V_26 [ V_36 ] = NULL ;
F_21 ( V_35 ) ;
}
F_21 ( V_3 ) ;
}
struct V_12 * F_22 (
struct V_37 * V_38 ,
const char * V_13 )
{
struct V_12 * V_14 ;
if ( ! ( V_38 ) ) {
F_12 ( V_23 L_26 ) ;
return NULL ;
}
if ( ! ( V_13 ) ) {
F_12 ( V_23 L_27 ) ;
return NULL ;
}
if ( strlen ( V_13 ) >= V_39 ) {
F_12 ( V_23 L_28
L_29 , V_13 ) ;
return NULL ;
}
V_14 = F_23 ( sizeof( struct V_12 ) , V_40 ) ;
if ( ! ( V_14 ) )
return NULL ;
F_24 ( & V_14 -> V_41 ) ;
F_25 ( & V_14 -> V_17 , 0 ) ;
V_14 -> V_42 = V_38 ;
F_26 ( V_14 ) ;
V_14 -> V_33 = V_43 [ 0 ] ;
snprintf ( V_14 -> V_16 , V_39 , L_30 , V_13 ) ;
F_7 ( & V_15 ) ;
F_27 ( & V_14 -> V_41 , & V_44 ) ;
F_10 ( & V_15 ) ;
F_12 ( V_21 L_31
L_32 ) ;
F_12 ( V_21 L_33
L_5 , V_14 , V_14 -> V_16 ) ;
return V_14 ;
}
void F_28 (
struct V_12 * V_14 )
{
F_7 ( & V_15 ) ;
F_29 ( & V_14 -> V_41 ) ;
F_10 ( & V_15 ) ;
F_30 ( V_14 ) ;
}
static int F_31 (
struct V_12 * V_14 )
{
struct V_45 * V_46 = & V_14 -> V_32 ;
if ( ! ( V_46 -> V_47 ) ) {
F_12 ( V_23 L_34 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_48 ) ) {
F_12 ( V_23 L_35 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_49 ) ) {
F_12 ( V_23 L_36 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_50 ) ) {
F_12 ( V_23 L_37 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_51 ) ) {
F_12 ( V_23 L_38 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_52 ) ) {
F_12 ( V_23 L_39 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_53 ) ) {
F_12 ( V_23 L_40 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_54 ) ) {
F_12 ( V_23 L_41 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_55 ) ) {
F_12 ( V_23 L_42 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_56 ) ) {
F_12 ( V_23 L_43 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_57 ) ) {
F_12 ( V_23 L_44 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_58 ) ) {
F_12 ( V_23 L_45 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_59 ) ) {
F_12 ( V_23 L_46 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_60 ) ) {
F_12 ( V_23 L_47 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_61 ) ) {
F_12 ( V_23 L_48 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_62 ) ) {
F_12 ( V_23 L_49 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_63 ) ) {
F_12 ( V_23 L_50 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_64 ) ) {
F_12 ( V_23 L_51 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_65 ) ) {
F_12 ( V_23 L_52 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_66 ) ) {
F_12 ( V_23 L_53 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_67 ) ) {
F_12 ( V_23 L_54 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_68 ) ) {
F_12 ( V_23 L_55 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_69 ) ) {
F_12 ( V_23 L_56 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_70 ) ) {
F_12 ( V_23 L_57 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_71 ) ) {
F_12 ( V_23 L_58 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_72 ) ) {
F_12 ( V_23 L_59 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_73 ) ) {
F_12 ( V_23 L_60 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_74 ) ) {
F_12 ( V_23 L_61 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_75 ) ) {
F_12 ( V_23 L_62 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_76 ) ) {
F_12 ( V_23 L_63 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_77 ) ) {
F_12 ( V_23 L_64 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_78 ) ) {
F_12 ( V_23 L_65 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_79 ) ) {
F_12 ( V_23 L_66 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_80 ) ) {
F_12 ( V_23 L_67 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_81 ) ) {
F_12 ( V_23 L_68 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_82 ) ) {
F_12 ( V_23 L_69 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_83 ) ) {
F_12 ( V_23 L_70 ) ;
return - V_22 ;
}
if ( ! ( V_46 -> V_84 ) ) {
F_12 ( V_23 L_71 ) ;
return - V_22 ;
}
return 0 ;
}
int F_32 (
struct V_12 * V_14 )
{
struct V_18 * V_85 ;
int V_20 ;
if ( ! ( V_14 ) ) {
F_12 ( V_23 L_72
L_73 ) ;
return - V_22 ;
}
if ( ! ( V_14 -> V_33 ) ) {
F_12 ( V_23 L_74
L_73 ) ;
return - V_22 ;
}
V_85 = & V_14 -> V_33 -> V_85 ;
if ( ! ( V_85 ) ) {
F_12 ( V_23 L_75
L_73 ) ;
return - V_22 ;
}
V_20 = F_31 ( V_14 ) ;
if ( V_20 < 0 )
return V_20 ;
F_12 ( V_21 L_76
L_77 ) ;
return 0 ;
}
void F_33 (
struct V_12 * V_14 )
{
struct V_18 * V_85 ;
struct V_86 * V_87 ;
if ( ! ( V_14 ) ) {
F_12 ( V_23 L_78
L_79 ) ;
return;
}
V_87 = V_14 -> V_33 ;
if ( ! ( V_87 ) ) {
F_12 ( V_23 L_80
L_73 ) ;
return;
}
V_85 = & V_14 -> V_33 -> V_85 ;
if ( ! ( V_85 ) ) {
F_12 ( V_23 L_75
L_73 ) ;
return;
}
F_12 ( V_21 L_81
L_82 ) ;
F_7 ( & V_15 ) ;
if ( F_34 ( & V_14 -> V_17 ) ) {
F_10 ( & V_15 ) ;
F_12 ( V_23 L_83 ,
V_14 -> V_16 ) ;
F_35 () ;
}
F_29 ( & V_14 -> V_41 ) ;
F_10 ( & V_15 ) ;
F_12 ( V_21 L_84
L_5 , V_14 -> V_16 ) ;
V_14 -> V_42 = NULL ;
V_14 -> V_33 = NULL ;
F_30 ( V_14 ) ;
F_12 ( L_85
L_86 ) ;
return;
}
static T_1 F_36 (
struct V_88 * V_88 ,
char * V_7 )
{
struct V_89 * V_90 = V_88 -> V_91 ;
struct V_92 * V_93 ;
V_93 = V_90 -> V_94 ;
if ( ! ( V_93 ) )
return - V_95 ;
return sprintf ( V_7 , L_87 ,
& V_88 -> V_96 [ 0 ] ) ;
}
static T_1 F_37 (
struct V_88 * V_88 ,
const char * V_7 ,
T_2 V_97 )
{
struct V_89 * V_98 = V_88 -> V_91 ;
struct V_92 * V_93 ;
unsigned char V_99 [ V_100 ] ;
if ( V_98 -> V_101 & V_102 ) {
F_12 ( V_23 L_88
L_89 ) ;
return - V_103 ;
}
if ( strlen ( V_7 ) >= V_100 ) {
F_12 ( V_23 L_90
L_91 , V_100 ) ;
return - V_104 ;
}
V_93 = V_98 -> V_94 ;
if ( ( V_93 ) ) {
if ( F_34 ( & V_93 -> V_105 . V_106 ) ) {
F_12 ( V_23 L_92
L_93 ,
F_34 ( & V_93 -> V_105 . V_106 ) ) ;
return - V_22 ;
}
}
memset ( V_99 , 0 , V_100 ) ;
snprintf ( V_99 , V_100 , L_30 , V_7 ) ;
snprintf ( V_98 -> V_88 . V_96 , V_100 ,
L_30 , F_38 ( V_99 ) ) ;
V_98 -> V_101 |= V_107 ;
F_12 ( V_21 L_94
L_5 , V_98 -> V_88 . V_96 ) ;
return V_97 ;
}
static T_1 F_39 (
struct V_88 * V_88 ,
char * V_7 )
{
struct V_89 * V_90 = V_88 -> V_91 ;
struct V_92 * V_93 ;
struct V_108 * V_109 ;
unsigned char V_99 [ V_110 ] ;
T_1 V_111 = 0 ;
V_93 = V_90 -> V_94 ;
if ( ! ( V_93 ) )
return - V_95 ;
memset ( V_99 , 0 , V_110 ) ;
F_40 ( & V_88 -> V_112 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! ( V_109 -> V_113 ) )
continue;
F_41 ( V_109 , V_99 , V_110 ) ;
if ( ( V_111 + strlen ( V_99 ) >= V_114 ) )
break;
V_111 += sprintf ( V_7 + V_111 , L_30 , V_99 ) ;
}
F_42 ( & V_88 -> V_112 ) ;
return V_111 ;
}
static T_1 F_43 (
struct V_88 * V_88 ,
const char * V_7 ,
T_2 V_97 )
{
return - V_115 ;
}
static T_1 F_44 (
struct V_88 * V_88 ,
const char * V_7 ,
T_2 V_97 )
{
return - V_115 ;
}
static T_1 F_45 (
struct V_88 * V_88 ,
const char * V_7 ,
T_2 V_97 )
{
return - V_115 ;
}
static T_1 F_46 (
struct V_88 * V_88 ,
const char * V_7 ,
T_2 V_97 )
{
return - V_115 ;
}
static T_1 F_47 (
struct V_92 * V_93 ,
char * V_7 ,
T_1 * V_111 )
{
struct V_116 * V_117 ;
struct V_118 * V_119 ;
char V_120 [ V_121 ] ;
int V_122 ;
memset ( V_120 , 0 , V_121 ) ;
F_40 ( & V_93 -> V_123 ) ;
V_119 = V_93 -> V_124 ;
if ( ! ( V_119 ) ) {
* V_111 += sprintf ( V_7 + * V_111 , L_95 ) ;
F_42 ( & V_93 -> V_123 ) ;
return * V_111 ;
}
V_117 = V_119 -> V_125 ;
V_122 = F_48 ( V_119 , & V_120 [ 0 ] ,
V_121 ) ;
* V_111 += sprintf ( V_7 + * V_111 , L_96 ,
F_49 ( V_117 -> V_126 ) -> V_47 () ,
V_117 -> V_127 , ( V_122 ) ? & V_120 [ 0 ] : L_97 ) ;
F_42 ( & V_93 -> V_123 ) ;
return * V_111 ;
}
static T_1 F_50 (
struct V_92 * V_93 ,
char * V_7 ,
T_1 * V_111 )
{
struct V_116 * V_117 ;
F_40 ( & V_93 -> V_123 ) ;
V_117 = V_93 -> V_128 ;
if ( ! ( V_117 ) ) {
* V_111 += sprintf ( V_7 + * V_111 , L_98 ) ;
F_42 ( & V_93 -> V_123 ) ;
return * V_111 ;
}
* V_111 += sprintf ( V_7 + * V_111 , L_99 ,
F_49 ( V_117 -> V_126 ) -> V_47 () ,
V_117 -> V_127 ) ;
F_42 ( & V_93 -> V_123 ) ;
return * V_111 ;
}
static T_1 F_51 (
struct V_89 * V_98 ,
char * V_7 )
{
T_1 V_111 = 0 ;
if ( ! ( V_98 -> V_94 ) )
return - V_95 ;
switch ( F_52 ( V_98 ) -> V_129 ) {
case V_130 :
F_47 ( V_98 -> V_94 ,
V_7 , & V_111 ) ;
break;
case V_131 :
F_50 ( V_98 -> V_94 ,
V_7 , & V_111 ) ;
break;
case V_132 :
V_111 += sprintf ( V_7 + V_111 , L_100 ) ;
break;
default:
V_111 += sprintf ( V_7 + V_111 , L_101 ) ;
break;
}
return V_111 ;
}
static T_1 F_53 (
struct V_89 * V_98 ,
char * V_7 )
{
struct V_92 * V_93 ;
struct V_118 * V_119 ;
T_1 V_111 = 0 ;
V_93 = V_98 -> V_94 ;
if ( ! ( V_93 ) )
return - V_95 ;
if ( F_52 ( V_98 ) -> V_129 != V_130 )
return V_111 ;
F_40 ( & V_93 -> V_123 ) ;
V_119 = V_93 -> V_124 ;
if ( ! ( V_119 ) ) {
V_111 = sprintf ( V_7 , L_95 ) ;
F_42 ( & V_93 -> V_123 ) ;
return V_111 ;
}
if ( V_119 -> V_133 )
V_111 = sprintf ( V_7 , L_102
L_103 ) ;
else
V_111 = sprintf ( V_7 , L_104
L_105 ) ;
F_42 ( & V_93 -> V_123 ) ;
return V_111 ;
}
static T_1 F_54 (
struct V_89 * V_98 ,
char * V_7 )
{
if ( ! ( V_98 -> V_94 ) )
return - V_95 ;
if ( F_52 ( V_98 ) -> V_129 != V_130 )
return 0 ;
return sprintf ( V_7 , L_106 , F_52 ( V_98 ) -> V_134 ) ;
}
static T_1 F_55 (
struct V_89 * V_98 ,
char * V_7 )
{
struct V_92 * V_93 ;
struct V_116 * V_117 ;
struct V_135 * V_136 ;
struct V_137 * V_126 ;
struct V_118 * V_119 ;
struct V_45 * V_46 ;
T_1 V_111 = 0 ;
V_93 = V_98 -> V_94 ;
if ( ! ( V_93 ) )
return - V_95 ;
if ( F_52 ( V_98 ) -> V_129 != V_130 )
return V_111 ;
F_40 ( & V_93 -> V_123 ) ;
V_119 = V_93 -> V_124 ;
if ( ! ( V_119 ) ) {
V_111 = sprintf ( V_7 , L_95 ) ;
F_42 ( & V_93 -> V_123 ) ;
return V_111 ;
}
V_117 = V_119 -> V_125 ;
V_126 = V_117 -> V_126 ;
V_136 = V_119 -> V_138 ;
V_46 = F_49 ( V_126 ) ;
V_111 += sprintf ( V_7 + V_111 , L_107
L_108 , V_46 -> V_47 () ,
V_46 -> V_49 ( V_126 ) ) ;
V_111 += sprintf ( V_7 + V_111 , L_109
L_110
L_111 , V_136 -> V_139 -> V_140 ,
V_46 -> V_47 () , V_46 -> V_50 ( V_126 ) ,
V_46 -> V_47 () , V_136 -> V_141 ) ;
F_42 ( & V_93 -> V_123 ) ;
return V_111 ;
}
static T_1 F_56 (
struct V_89 * V_98 ,
char * V_7 )
{
struct V_45 * V_46 ;
struct V_118 * V_119 ;
unsigned char V_99 [ 384 ] ;
char V_120 [ V_121 ] ;
T_1 V_111 = 0 ;
int V_142 = 0 , V_122 ;
if ( ! ( V_98 -> V_94 ) )
return - V_95 ;
if ( F_52 ( V_98 ) -> V_129 != V_130 )
return V_111 ;
V_111 += sprintf ( V_7 + V_111 , L_112 ) ;
F_40 ( & F_52 ( V_98 ) -> V_143 ) ;
F_8 (pr_reg, &T10_RES(su_dev)->registration_list,
pr_reg_list) {
memset ( V_99 , 0 , 384 ) ;
memset ( V_120 , 0 , V_121 ) ;
V_46 = V_119 -> V_125 -> V_126 -> V_144 ;
V_122 = F_48 ( V_119 , & V_120 [ 0 ] ,
V_121 ) ;
sprintf ( V_99 , L_113 ,
V_46 -> V_47 () ,
V_119 -> V_125 -> V_127 , ( V_122 ) ?
& V_120 [ 0 ] : L_97 , V_119 -> V_145 ,
V_119 -> V_146 ) ;
if ( ( V_111 + strlen ( V_99 ) >= V_114 ) )
break;
V_111 += sprintf ( V_7 + V_111 , L_30 , V_99 ) ;
V_142 ++ ;
}
F_42 ( & F_52 ( V_98 ) -> V_143 ) ;
if ( ! ( V_142 ) )
V_111 += sprintf ( V_7 + V_111 , L_114 ) ;
return V_111 ;
}
static T_1 F_57 (
struct V_89 * V_98 ,
char * V_7 )
{
struct V_92 * V_93 ;
struct V_118 * V_119 ;
T_1 V_111 = 0 ;
V_93 = V_98 -> V_94 ;
if ( ! ( V_93 ) )
return - V_95 ;
if ( F_52 ( V_98 ) -> V_129 != V_130 )
return V_111 ;
F_40 ( & V_93 -> V_123 ) ;
V_119 = V_93 -> V_124 ;
if ( ! ( V_119 ) ) {
V_111 = sprintf ( V_7 , L_95 ) ;
F_42 ( & V_93 -> V_123 ) ;
return V_111 ;
}
V_111 = sprintf ( V_7 , L_115 ,
F_58 ( V_119 -> V_147 ) ) ;
F_42 ( & V_93 -> V_123 ) ;
return V_111 ;
}
static T_1 F_59 (
struct V_89 * V_98 ,
char * V_7 )
{
T_1 V_111 = 0 ;
if ( ! ( V_98 -> V_94 ) )
return - V_95 ;
switch ( F_52 ( V_98 ) -> V_129 ) {
case V_130 :
V_111 = sprintf ( V_7 , L_116 ) ;
break;
case V_131 :
V_111 = sprintf ( V_7 , L_117 ) ;
break;
case V_132 :
V_111 = sprintf ( V_7 , L_118 ) ;
break;
default:
V_111 = sprintf ( V_7 , L_119 ) ;
break;
}
return V_111 ;
}
static T_1 F_60 (
struct V_89 * V_98 ,
char * V_7 )
{
if ( ! ( V_98 -> V_94 ) )
return - V_95 ;
if ( F_52 ( V_98 ) -> V_129 != V_130 )
return 0 ;
return sprintf ( V_7 , L_120 ,
( F_52 ( V_98 ) -> V_148 ) ? L_121 : L_122 ) ;
}
static T_1 F_61 (
struct V_89 * V_98 ,
char * V_7 )
{
if ( ! ( V_98 -> V_94 ) )
return - V_95 ;
if ( F_52 ( V_98 ) -> V_129 != V_130 )
return 0 ;
return sprintf ( V_7 , L_123 ) ;
}
static T_1 F_62 (
struct V_89 * V_98 ,
const char * V_7 ,
T_2 V_97 )
{
struct V_92 * V_93 ;
unsigned char * V_149 = NULL , * V_150 = NULL , * V_151 = NULL ;
unsigned char * V_152 = NULL , * V_153 = NULL ;
char * V_154 , * V_155 , * V_156 , * V_157 ;
T_3 args [ V_158 ] ;
unsigned long long V_159 ;
T_4 V_160 = 0 ;
T_5 V_161 = 0 , V_162 = 0 ;
int V_20 = - 1 , V_163 = 0 , V_164 = 0 , V_165 , V_166 ;
T_6 V_167 = 0 , V_168 = 0 ;
T_7 type = 0 , V_169 ;
V_93 = V_98 -> V_94 ;
if ( ! ( V_93 ) )
return - V_95 ;
if ( F_52 ( V_98 ) -> V_129 != V_130 )
return 0 ;
if ( F_34 ( & V_93 -> V_105 . V_106 ) ) {
F_12 ( V_21 L_124
L_125 ) ;
return - V_22 ;
}
V_157 = F_63 ( V_7 , V_40 ) ;
if ( ! V_157 )
return - V_170 ;
V_154 = V_157 ;
while ( ( V_155 = F_64 ( & V_157 , L_126 ) ) != NULL ) {
if ( ! * V_155 )
continue;
V_166 = F_65 ( V_155 , V_171 , args ) ;
switch ( V_166 ) {
case V_172 :
V_149 = F_66 ( & args [ 0 ] ) ;
if ( ! V_149 ) {
V_20 = - V_170 ;
goto V_173;
}
break;
case V_174 :
V_150 = F_66 ( & args [ 0 ] ) ;
if ( ! V_150 ) {
V_20 = - V_170 ;
goto V_173;
}
if ( strlen ( V_150 ) >= V_175 ) {
F_12 ( V_23 L_127
L_128 ,
V_175 ) ;
V_20 = - V_22 ;
break;
}
break;
case V_176 :
V_151 = F_66 ( & args [ 0 ] ) ;
if ( ! V_151 ) {
V_20 = - V_170 ;
goto V_173;
}
if ( strlen ( V_151 ) >= V_177 ) {
F_12 ( V_23 L_129
L_130 ,
V_177 ) ;
V_20 = - V_22 ;
break;
}
break;
case V_178 :
V_156 = F_66 ( & args [ 0 ] ) ;
if ( ! V_156 ) {
V_20 = - V_170 ;
goto V_173;
}
V_20 = F_67 ( V_156 , 0 , & V_159 ) ;
if ( V_20 < 0 ) {
F_12 ( V_23 L_131
L_132 ) ;
goto V_173;
}
V_160 = ( T_4 ) V_159 ;
break;
case V_179 :
F_68 ( args , & V_165 ) ;
V_163 = V_165 ;
break;
case V_180 :
F_68 ( args , & V_165 ) ;
type = ( T_7 ) V_165 ;
break;
case V_181 :
F_68 ( args , & V_165 ) ;
V_169 = ( T_7 ) V_165 ;
break;
case V_182 :
F_68 ( args , & V_165 ) ;
V_164 = ( int ) V_165 ;
break;
case V_183 :
F_68 ( args , & V_165 ) ;
V_161 = ( T_5 ) V_165 ;
break;
case V_184 :
V_152 = F_66 ( & args [ 0 ] ) ;
if ( ! V_152 ) {
V_20 = - V_170 ;
goto V_173;
}
break;
case V_185 :
V_153 = F_66 ( & args [ 0 ] ) ;
if ( ! V_153 ) {
V_20 = - V_170 ;
goto V_173;
}
if ( strlen ( V_153 ) >= V_186 ) {
F_12 ( V_23 L_133
L_134 ,
V_186 ) ;
V_20 = - V_22 ;
break;
}
break;
case V_187 :
F_68 ( args , & V_165 ) ;
V_168 = ( T_6 ) V_165 ;
break;
case V_188 :
F_68 ( args , & V_165 ) ;
V_167 = ( T_6 ) V_165 ;
break;
case V_189 :
F_68 ( args , & V_165 ) ;
V_162 = ( T_5 ) V_165 ;
break;
default:
break;
}
}
if ( ! ( V_150 ) || ! ( V_153 ) || ! ( V_160 ) ) {
F_12 ( V_23 L_135 ) ;
V_20 = - V_22 ;
goto V_173;
}
if ( V_163 && ! ( type ) ) {
F_12 ( V_23 L_136
L_137 , type ) ;
V_20 = - V_22 ;
goto V_173;
}
V_20 = F_69 ( F_52 ( V_98 ) , V_160 ,
V_150 , V_151 , V_161 , V_153 , V_168 , V_162 ,
V_163 , V_164 , type ) ;
V_173:
F_30 ( V_149 ) ;
F_30 ( V_150 ) ;
F_30 ( V_151 ) ;
F_30 ( V_152 ) ;
F_30 ( V_153 ) ;
F_30 ( V_154 ) ;
return ( V_20 == 0 ) ? V_97 : V_20 ;
}
static T_1 F_70 ( void * V_190 , char * V_7 )
{
struct V_89 * V_90 = (struct V_89 * ) V_190 ;
struct V_1 * V_191 = V_90 -> V_192 ;
struct V_193 * V_194 = V_191 -> V_195 ;
int V_196 = 0 ;
T_1 V_197 = 0 ;
if ( ! ( V_90 -> V_94 ) )
return - V_95 ;
F_71 ( V_90 -> V_94 , V_7 , & V_196 ) ;
V_197 += V_196 ;
V_197 += V_194 -> V_198 ( V_191 , V_90 , V_7 + V_197 ) ;
return V_197 ;
}
static T_1 F_72 (
void * V_190 ,
const char * V_7 ,
T_2 V_97 )
{
struct V_89 * V_90 = (struct V_89 * ) V_190 ;
struct V_1 * V_191 = V_90 -> V_192 ;
struct V_193 * V_194 = V_191 -> V_195 ;
if ( ! ( V_90 -> V_199 ) ) {
F_12 ( V_23 L_138
L_139 ) ;
return - V_22 ;
}
return V_194 -> V_200 ( V_191 , V_90 , V_7 , V_97 ) ;
}
static T_1 F_73 ( void * V_190 , char * V_7 )
{
struct V_89 * V_90 = (struct V_89 * ) V_190 ;
if ( ! ( V_90 -> V_101 & V_201 ) )
return 0 ;
return snprintf ( V_7 , V_114 , L_140 , V_90 -> V_202 ) ;
}
static T_1 F_74 (
void * V_190 ,
const char * V_7 ,
T_2 V_97 )
{
struct V_89 * V_90 = (struct V_89 * ) V_190 ;
struct V_1 * V_191 = V_90 -> V_192 ;
T_1 V_197 ;
if ( V_97 > ( V_203 - 1 ) ) {
F_12 ( V_23 L_141
L_142 , ( int ) V_97 ,
V_203 - 1 ) ;
return - V_22 ;
}
V_90 -> V_101 |= V_201 ;
V_197 = snprintf ( & V_90 -> V_202 [ 0 ] , V_203 ,
L_30 , V_7 ) ;
F_12 ( V_21 L_143 ,
F_19 ( & V_191 -> V_4 . V_30 ) ,
F_19 ( & V_90 -> V_204 . V_30 ) ,
V_90 -> V_202 ) ;
return V_197 ;
}
static T_1 F_75 ( void * V_190 , char * V_7 )
{
struct V_89 * V_90 = (struct V_89 * ) V_190 ;
if ( ! ( V_90 -> V_101 & V_205 ) )
return 0 ;
return snprintf ( V_7 , V_114 , L_140 , V_90 -> V_206 ) ;
}
static T_1 F_76 (
void * V_190 ,
const char * V_7 ,
T_2 V_97 )
{
struct V_89 * V_90 = (struct V_89 * ) V_190 ;
struct V_1 * V_191 = V_90 -> V_192 ;
T_1 V_197 ;
if ( V_97 > ( V_207 - 1 ) ) {
F_12 ( V_23 L_144
L_145 , ( int ) V_97 ,
V_207 - 1 ) ;
return - V_22 ;
}
V_90 -> V_101 |= V_205 ;
V_197 = snprintf ( & V_90 -> V_206 [ 0 ] , V_207 ,
L_30 , V_7 ) ;
F_12 ( V_21 L_146 ,
F_19 ( & V_191 -> V_4 . V_30 ) ,
F_19 ( & V_90 -> V_204 . V_30 ) ,
V_90 -> V_206 ) ;
return V_197 ;
}
static T_1 F_77 (
void * V_190 ,
const char * V_7 ,
T_2 V_97 )
{
struct V_89 * V_90 = (struct V_89 * ) V_190 ;
struct V_92 * V_93 ;
struct V_1 * V_191 = V_90 -> V_192 ;
struct V_193 * V_194 = V_191 -> V_195 ;
char * V_155 ;
V_155 = strstr ( V_7 , L_147 ) ;
if ( ! ( V_155 ) ) {
F_12 ( V_23 L_148
L_149 ) ;
return - V_22 ;
}
if ( ( V_90 -> V_94 ) ) {
F_12 ( V_23 L_150
L_151 ) ;
return - V_208 ;
}
if ( V_194 -> V_209 ( V_191 , V_90 ) < 0 )
return - V_22 ;
V_93 = V_194 -> V_210 ( V_191 , V_90 , V_90 -> V_199 ) ;
if ( F_78 ( V_93 ) )
return F_79 ( V_93 ) ;
else if ( ! V_93 )
return - V_22 ;
V_90 -> V_94 = V_93 ;
F_12 ( V_21 L_152
L_153 , V_90 -> V_94 ) ;
return V_97 ;
}
static T_1 F_80 ( void * V_190 , char * V_7 )
{
struct V_92 * V_93 ;
struct V_89 * V_98 = (struct V_89 * ) V_190 ;
struct V_2 * V_211 ;
struct V_212 * V_213 ;
struct V_214 * V_215 ;
T_1 V_111 = 0 ;
V_93 = V_98 -> V_94 ;
if ( ! ( V_93 ) )
return - V_95 ;
if ( F_81 ( V_98 ) -> V_216 != V_217 )
return V_111 ;
V_215 = V_93 -> V_218 ;
if ( ! ( V_215 ) ) {
F_12 ( V_23 L_154
L_73 ) ;
return - V_22 ;
}
F_40 ( & V_215 -> V_219 ) ;
V_213 = V_215 -> V_213 ;
if ( ( V_213 ) ) {
V_211 = & V_213 -> V_220 . V_30 ;
V_111 += sprintf ( V_7 , L_155 ,
F_19 ( V_211 ) , V_213 -> V_221 ) ;
}
F_42 ( & V_215 -> V_219 ) ;
return V_111 ;
}
static T_1 F_82 (
void * V_190 ,
const char * V_7 ,
T_2 V_97 )
{
struct V_92 * V_93 ;
struct V_89 * V_98 = (struct V_89 * ) V_190 ;
struct V_1 * V_191 = V_98 -> V_192 ;
struct V_212 * V_213 = NULL , * V_222 = NULL ;
struct V_214 * V_215 ;
unsigned char V_99 [ V_223 ] ;
int V_224 = 0 ;
V_93 = V_98 -> V_94 ;
if ( ! ( V_93 ) )
return - V_95 ;
if ( F_81 ( V_98 ) -> V_216 != V_217 ) {
F_12 ( V_225 L_156 ,
F_19 ( & V_191 -> V_4 . V_30 ) ,
F_19 ( & V_98 -> V_204 . V_30 ) ) ;
return - V_22 ;
}
if ( V_97 > V_223 ) {
F_12 ( V_23 L_157 ) ;
return - V_22 ;
}
memset ( V_99 , 0 , V_223 ) ;
memcpy ( V_99 , V_7 , V_97 ) ;
if ( strcmp ( F_38 ( V_99 ) , L_158 ) ) {
V_222 = F_83 ( F_38 ( V_99 ) ) ;
if ( ! ( V_222 ) )
return - V_95 ;
}
V_215 = V_93 -> V_218 ;
if ( ! ( V_215 ) ) {
if ( V_222 )
F_84 ( V_222 ) ;
F_12 ( V_23 L_154
L_73 ) ;
return - V_22 ;
}
F_40 ( & V_215 -> V_219 ) ;
V_213 = V_215 -> V_213 ;
if ( ( V_213 ) ) {
if ( ! ( V_222 ) ) {
F_12 ( V_21 L_159
L_160
L_161 ,
F_19 ( & V_191 -> V_4 . V_30 ) ,
F_19 ( & V_98 -> V_204 . V_30 ) ,
F_19 ( & V_213 -> V_220 . V_30 ) ,
V_213 -> V_221 ) ;
F_85 ( V_215 , V_213 ) ;
F_42 ( & V_215 -> V_219 ) ;
return V_97 ;
}
F_85 ( V_215 , V_213 ) ;
V_224 = 1 ;
}
F_86 ( V_215 , V_222 ) ;
F_42 ( & V_215 -> V_219 ) ;
F_12 ( V_21 L_162
L_163 ,
( V_224 ) ? L_164 : L_165 ,
F_19 ( & V_191 -> V_4 . V_30 ) ,
F_19 ( & V_98 -> V_204 . V_30 ) ,
F_19 ( & V_222 -> V_220 . V_30 ) ,
V_222 -> V_221 ) ;
F_84 ( V_222 ) ;
return V_97 ;
}
static void F_87 ( struct V_2 * V_3 )
{
struct V_89 * V_90 = F_2 ( F_3 ( V_3 ) ,
struct V_89 , V_204 ) ;
struct V_1 * V_191 = F_1 ( & V_90 -> V_192 -> V_4 . V_30 ) ;
struct V_193 * V_194 = V_191 -> V_195 ;
struct V_18 * V_226 = & V_90 -> V_204 ;
F_30 ( V_226 -> V_26 ) ;
if ( V_90 -> V_94 ) {
F_12 ( V_21 L_166
L_167 ,
V_90 -> V_94 ) ;
F_88 ( V_90 -> V_94 , V_191 ) ;
} else {
F_12 ( V_21 L_168
L_169 ,
V_90 -> V_199 ) ;
V_194 -> V_227 ( V_90 -> V_199 ) ;
}
F_12 ( V_21 L_170
L_171 , V_90 ) ;
F_30 ( V_90 ) ;
}
static T_1 F_89 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
char * V_7 )
{
struct V_89 * V_90 = F_2 (
F_3 ( V_3 ) , struct V_89 ,
V_204 ) ;
struct V_228 * V_229 = F_2 (
V_6 , struct V_228 , V_6 ) ;
if ( ! ( V_229 -> V_230 ) )
return - V_22 ;
return V_229 -> V_230 ( ( void * ) V_90 , V_7 ) ;
}
static T_1 F_90 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
const char * V_7 , T_2 V_97 )
{
struct V_89 * V_90 = F_2 (
F_3 ( V_3 ) , struct V_89 ,
V_204 ) ;
struct V_228 * V_229 = F_2 (
V_6 , struct V_228 , V_6 ) ;
if ( ! ( V_229 -> V_231 ) )
return - V_22 ;
return V_229 -> V_231 ( ( void * ) V_90 , V_7 , V_97 ) ;
}
static T_1 F_91 (
struct V_212 * V_213 ,
char * V_7 )
{
if ( ! ( V_213 -> V_232 ) )
return 0 ;
return sprintf ( V_7 , L_172 , V_213 -> V_221 ) ;
}
static T_1 F_92 (
struct V_212 * V_213 ,
const char * V_7 ,
T_2 V_97 )
{
struct V_18 * V_233 = & V_213 -> V_220 ;
unsigned long V_221 ;
int V_20 ;
V_20 = F_93 ( V_7 , 0 , & V_221 ) ;
if ( V_20 < 0 ) {
F_12 ( V_23 L_173
L_174 , V_20 ) ;
return - V_22 ;
}
if ( V_221 > 0x0000ffff ) {
F_12 ( V_23 L_175
L_176 , V_221 ) ;
return - V_22 ;
}
V_20 = F_94 ( V_213 , ( T_6 ) V_221 ) ;
if ( V_20 < 0 )
return - V_22 ;
F_12 ( V_21 L_177
L_178 ,
F_19 ( & V_233 -> V_30 ) ,
V_213 -> V_221 ) ;
return V_97 ;
}
static T_1 F_95 (
struct V_212 * V_213 ,
char * V_7 )
{
struct V_92 * V_93 ;
struct V_1 * V_191 ;
struct V_89 * V_98 ;
struct V_214 * V_215 ;
T_1 V_111 = 0 , V_234 ;
unsigned char V_99 [ V_223 ] ;
memset ( V_99 , 0 , V_223 ) ;
F_40 ( & V_213 -> V_235 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_93 = V_215 -> V_236 ;
V_98 = V_93 -> V_237 ;
V_191 = V_98 -> V_192 ;
V_234 = snprintf ( V_99 , V_223 , L_179 ,
F_19 ( & V_191 -> V_4 . V_30 ) ,
F_19 ( & V_98 -> V_204 . V_30 ) ) ;
V_234 ++ ;
if ( ( V_234 + V_111 ) > V_114 ) {
F_12 ( V_225 L_180
L_181 ) ;
break;
}
memcpy ( V_7 + V_111 , V_99 , V_234 ) ;
V_111 += V_234 ;
}
F_42 ( & V_213 -> V_235 ) ;
return V_111 ;
}
static void F_96 ( struct V_2 * V_3 )
{
struct V_212 * V_213 = F_2 ( F_3 ( V_3 ) ,
struct V_212 , V_220 ) ;
F_97 ( V_213 ) ;
}
static struct V_18 * F_98 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_212 * V_213 ;
struct V_18 * V_233 = NULL ;
struct V_2 * V_238 = NULL ;
V_213 = F_99 ( V_13 , 0 ) ;
if ( F_78 ( V_213 ) )
return NULL ;
V_233 = & V_213 -> V_220 ;
V_238 = & V_233 -> V_30 ;
F_17 ( V_233 , V_13 ,
& V_239 ) ;
F_12 ( V_21 L_182
L_183 ,
F_19 ( V_238 ) ) ;
return V_233 ;
}
static void F_100 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_212 * V_213 = F_2 ( F_3 ( V_3 ) ,
struct V_212 , V_220 ) ;
F_12 ( V_21 L_184
L_185 ,
F_19 ( V_3 ) , V_213 -> V_221 ) ;
F_21 ( V_3 ) ;
}
static T_1 F_101 (
struct V_240 * V_241 ,
char * V_7 )
{
return sprintf ( V_7 , L_186 ,
F_34 ( & V_241 -> V_242 ) ) ;
}
static T_1 F_102 (
struct V_240 * V_241 ,
const char * V_7 ,
T_2 V_97 )
{
struct V_89 * V_98 = V_241 -> V_243 ;
unsigned long V_244 ;
int V_245 , V_20 ;
if ( ! ( V_241 -> V_246 ) ) {
F_12 ( V_23 L_187
L_188 , V_241 -> V_246 ) ;
return - V_22 ;
}
V_20 = F_93 ( V_7 , 0 , & V_244 ) ;
if ( V_20 < 0 ) {
F_12 ( L_189
L_5 , V_7 ) ;
return - V_22 ;
}
V_245 = ( int ) V_244 ;
if ( ! ( V_241 -> V_247 & V_248 ) ) {
F_12 ( V_23 L_190
L_191 ) ;
return - V_22 ;
}
V_20 = F_103 ( V_241 , V_98 -> V_94 ,
NULL , NULL , V_245 , 0 ) ;
return ( ! V_20 ) ? V_97 : - V_22 ;
}
static T_1 F_104 (
struct V_240 * V_241 ,
char * V_7 )
{
return sprintf ( V_7 , L_140 ,
F_105 ( V_241 -> V_249 ) ) ;
}
static T_1 F_106 (
struct V_240 * V_241 ,
const char * V_7 ,
T_2 V_97 )
{
unsigned long V_244 ;
int V_250 , V_20 ;
if ( ! ( V_241 -> V_246 ) ) {
F_12 ( V_23 L_192
L_193 ,
V_241 -> V_246 ) ;
return - V_22 ;
}
V_20 = F_93 ( V_7 , 0 , & V_244 ) ;
if ( V_20 < 0 ) {
F_12 ( V_23 L_194
L_195 , V_7 ) ;
return - V_22 ;
}
V_250 = ( int ) V_244 ;
if ( ( V_250 != V_251 ) &&
( V_250 != V_252 ) &&
( V_250 != V_253 ) ) {
F_12 ( V_23 L_196 ,
V_250 ) ;
return - V_22 ;
}
V_241 -> V_249 = V_250 ;
return V_97 ;
}
static T_1 F_107 (
struct V_240 * V_241 ,
char * V_7 )
{
return F_108 ( V_241 , V_7 ) ;
}
static T_1 F_109 (
struct V_240 * V_241 ,
const char * V_7 ,
T_2 V_97 )
{
return F_110 ( V_241 , V_7 , V_97 ) ;
}
static T_1 F_111 (
struct V_240 * V_241 ,
char * V_7 )
{
return sprintf ( V_7 , L_186 , V_241 -> V_254 ) ;
}
static T_1 F_112 (
struct V_240 * V_241 ,
const char * V_7 ,
T_2 V_97 )
{
unsigned long V_244 ;
int V_20 ;
V_20 = F_93 ( V_7 , 0 , & V_244 ) ;
if ( V_20 < 0 ) {
F_12 ( V_23 L_197 ) ;
return - V_22 ;
}
if ( ( V_244 != 0 ) && ( V_244 != 1 ) ) {
F_12 ( V_23 L_198
L_199 , V_244 ) ;
return - V_22 ;
}
V_241 -> V_254 = ( int ) V_244 ;
return V_97 ;
}
static T_1 F_113 (
struct V_240 * V_241 ,
char * V_7 )
{
return F_114 ( V_241 , V_7 ) ;
}
static T_1 F_115 (
struct V_240 * V_241 ,
const char * V_7 ,
T_2 V_97 )
{
return F_116 ( V_241 , V_7 , V_97 ) ;
}
static T_1 F_117 (
struct V_240 * V_241 ,
char * V_7 )
{
return F_118 ( V_241 , V_7 ) ;
}
static T_1 F_119 (
struct V_240 * V_241 ,
const char * V_7 ,
T_2 V_97 )
{
return F_120 ( V_241 , V_7 , V_97 ) ;
}
static T_1 F_121 (
struct V_240 * V_241 ,
char * V_7 )
{
return F_122 ( V_241 , V_7 ) ;
}
static T_1 F_123 (
struct V_240 * V_241 ,
const char * V_7 ,
T_2 V_97 )
{
return F_124 ( V_241 , V_7 , V_97 ) ;
}
static T_1 F_125 (
struct V_240 * V_241 ,
char * V_7 )
{
if ( ! ( V_241 -> V_246 ) )
return 0 ;
return sprintf ( V_7 , L_172 , V_241 -> V_255 ) ;
}
static T_1 F_126 (
struct V_240 * V_241 ,
const char * V_7 ,
T_2 V_97 )
{
struct V_18 * V_256 = & V_241 -> V_257 ;
unsigned long V_255 ;
int V_20 ;
V_20 = F_93 ( V_7 , 0 , & V_255 ) ;
if ( V_20 < 0 ) {
F_12 ( V_23 L_173
L_200 , V_20 ) ;
return - V_22 ;
}
if ( V_255 > 0x0000ffff ) {
F_12 ( V_23 L_201
L_176 , V_255 ) ;
return - V_22 ;
}
V_20 = F_127 ( V_241 , ( T_6 ) V_255 ) ;
if ( V_20 < 0 )
return - V_22 ;
F_12 ( V_21 L_202
L_203 ,
F_19 ( & V_256 -> V_30 ) ,
V_241 -> V_255 ) ;
return V_97 ;
}
static T_1 F_128 (
struct V_240 * V_241 ,
char * V_7 )
{
struct V_258 * V_259 ;
struct V_137 * V_260 ;
struct V_135 * V_136 ;
struct V_261 * V_262 ;
T_1 V_111 = 0 , V_234 ;
unsigned char V_99 [ V_263 ] ;
memset ( V_99 , 0 , V_263 ) ;
F_40 ( & V_241 -> V_264 ) ;
F_8 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_259 = V_262 -> V_265 ;
V_260 = V_259 -> V_266 ;
V_136 = V_259 -> V_267 ;
V_234 = snprintf ( V_99 , V_263 , L_204
L_205 , F_49 ( V_260 ) -> V_47 () ,
F_49 ( V_260 ) -> V_49 ( V_260 ) ,
F_49 ( V_260 ) -> V_50 ( V_260 ) ,
F_19 ( & V_136 -> V_268 . V_30 ) ) ;
V_234 ++ ;
if ( ( V_234 + V_111 ) > V_114 ) {
F_12 ( V_225 L_180
L_181 ) ;
break;
}
memcpy ( V_7 + V_111 , V_99 , V_234 ) ;
V_111 += V_234 ;
}
F_42 ( & V_241 -> V_264 ) ;
return V_111 ;
}
static void F_129 ( struct V_2 * V_3 )
{
struct V_240 * V_241 = F_2 ( F_3 ( V_3 ) ,
struct V_240 , V_257 ) ;
F_130 ( V_241 ) ;
}
static struct V_18 * F_131 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_269 * V_270 = F_2 ( V_19 , struct V_269 ,
V_271 ) ;
struct V_240 * V_241 ;
struct V_89 * V_98 = V_270 -> V_91 ;
struct V_18 * V_256 = NULL ;
struct V_2 * V_272 = NULL ;
V_241 = F_132 ( V_98 , V_13 , 0 ) ;
if ( ! ( V_241 ) )
return NULL ;
V_256 = & V_241 -> V_257 ;
V_272 = & V_256 -> V_30 ;
F_17 ( V_256 , V_13 ,
& V_273 ) ;
F_12 ( V_21 L_206
L_207 ,
F_19 ( V_272 ) ) ;
return V_256 ;
}
static void F_133 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_240 * V_241 = F_2 ( F_3 ( V_3 ) ,
struct V_240 , V_257 ) ;
F_12 ( V_21 L_208
L_209 ,
F_19 ( V_3 ) , V_241 -> V_255 ) ;
F_21 ( V_3 ) ;
}
static struct V_18 * F_134 (
struct V_18 * V_19 ,
const char * V_13 )
{
return F_14 ( - V_115 ) ;
}
static void F_135 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
return;
}
static struct V_18 * F_136 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_240 * V_241 ;
struct V_89 * V_90 ;
struct V_193 * V_194 ;
struct V_2 * V_274 = & V_19 -> V_30 ;
struct V_1 * V_191 = F_1 ( V_274 ) ;
struct V_18 * V_226 = NULL , * V_275 = NULL ;
struct V_18 * V_276 = NULL ;
int V_277 = - V_170 , V_20 ;
V_20 = F_137 ( & V_191 -> V_278 ) ;
if ( V_20 )
return F_14 ( V_20 ) ;
V_194 = V_191 -> V_195 ;
V_90 = F_23 ( sizeof( struct V_89 ) , V_40 ) ;
if ( ! V_90 ) {
F_12 ( V_23 L_210
L_211 ) ;
goto V_279;
}
F_24 ( & V_90 -> V_280 ) ;
F_24 ( & V_90 -> V_88 . V_281 ) ;
F_138 ( & V_90 -> V_88 . V_112 ) ;
F_24 ( & V_90 -> V_282 . V_283 ) ;
F_24 ( & V_90 -> V_282 . V_284 ) ;
F_138 ( & V_90 -> V_282 . V_143 ) ;
F_138 ( & V_90 -> V_282 . V_285 ) ;
F_24 ( & V_90 -> V_269 . V_286 ) ;
F_138 ( & V_90 -> V_269 . V_287 ) ;
F_138 ( & V_90 -> V_288 ) ;
V_90 -> V_282 . V_289 = V_290 ;
V_90 -> V_88 . V_91 = V_90 ;
V_90 -> V_269 . V_91 = V_90 ;
V_90 -> V_291 . V_292 = V_90 ;
V_90 -> V_192 = V_191 ;
V_226 = & V_90 -> V_204 ;
V_226 -> V_26 = F_23 ( sizeof( struct V_18 ) * 7 ,
V_40 ) ;
if ( ! ( V_226 -> V_26 ) )
goto V_173;
V_90 -> V_199 = V_194 -> V_293 ( V_191 , V_13 ) ;
if ( ! ( V_90 -> V_199 ) ) {
F_12 ( V_23 L_212
L_213 ) ;
goto V_173;
}
F_40 ( & V_294 -> V_295 ) ;
F_27 ( & V_90 -> V_280 , & V_294 -> V_280 ) ;
F_42 ( & V_294 -> V_295 ) ;
F_17 ( & V_90 -> V_204 , V_13 ,
& V_296 ) ;
F_17 ( & V_90 -> V_291 . V_297 , L_214 ,
& V_298 ) ;
F_17 ( & V_90 -> V_299 , L_215 ,
& V_300 ) ;
F_17 ( & V_90 -> V_88 . V_301 , L_216 ,
& V_302 ) ;
F_17 ( & V_90 -> V_269 . V_271 ,
L_217 , & V_303 ) ;
F_17 ( & V_90 -> V_304 . V_305 ,
L_218 , & V_306 ) ;
V_226 -> V_26 [ 0 ] = & V_90 -> V_291 . V_297 ;
V_226 -> V_26 [ 1 ] = & V_90 -> V_299 ;
V_226 -> V_26 [ 2 ] = & V_90 -> V_88 . V_301 ;
V_226 -> V_26 [ 3 ] = & V_90 -> V_269 . V_271 ;
V_226 -> V_26 [ 4 ] = & V_90 -> V_304 . V_305 ;
V_226 -> V_26 [ 5 ] = NULL ;
V_241 = F_132 ( V_90 , L_219 , 1 ) ;
if ( ! ( V_241 ) )
goto V_173;
V_275 = & F_81 ( V_90 ) -> V_271 ;
V_275 -> V_26 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_40 ) ;
if ( ! ( V_275 -> V_26 ) ) {
F_12 ( V_23 L_220
L_221 ) ;
goto V_173;
}
F_17 ( & V_241 -> V_257 ,
L_219 , & V_273 ) ;
V_275 -> V_26 [ 0 ] = & V_241 -> V_257 ;
V_275 -> V_26 [ 1 ] = NULL ;
F_81 ( V_90 ) -> V_307 = V_241 ;
V_276 = & F_139 ( V_90 ) -> V_305 ;
V_276 -> V_26 = F_23 ( sizeof( struct V_18 ) * 4 ,
V_40 ) ;
if ( ! V_276 -> V_26 ) {
F_12 ( V_23 L_222 ) ;
goto V_173;
}
F_140 ( V_90 ) ;
F_12 ( V_21 L_223
L_224 , V_90 , V_90 -> V_199 ) ;
F_10 ( & V_191 -> V_278 ) ;
return & V_90 -> V_204 ;
V_173:
if ( F_81 ( V_90 ) -> V_307 ) {
F_130 ( F_81 ( V_90 ) -> V_307 ) ;
F_81 ( V_90 ) -> V_307 = NULL ;
}
if ( V_276 )
F_30 ( V_276 -> V_26 ) ;
if ( V_275 )
F_30 ( V_275 -> V_26 ) ;
if ( V_226 )
F_30 ( V_226 -> V_26 ) ;
if ( V_90 -> V_199 )
V_194 -> V_227 ( V_90 -> V_199 ) ;
F_30 ( V_90 ) ;
V_279:
F_10 ( & V_191 -> V_278 ) ;
return F_14 ( V_277 ) ;
}
static void F_141 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_89 * V_90 = F_2 ( F_3 ( V_3 ) ,
struct V_89 , V_204 ) ;
struct V_1 * V_191 ;
struct V_193 * V_194 ;
struct V_2 * V_35 ;
struct V_18 * V_226 , * V_275 , * V_276 ;
int V_36 ;
V_191 = F_1 ( & V_90 -> V_192 -> V_4 . V_30 ) ;
F_7 ( & V_191 -> V_278 ) ;
V_194 = V_191 -> V_195 ;
F_40 ( & V_294 -> V_295 ) ;
F_29 ( & V_90 -> V_280 ) ;
F_42 ( & V_294 -> V_295 ) ;
V_276 = & F_139 ( V_90 ) -> V_305 ;
for ( V_36 = 0 ; V_276 -> V_26 [ V_36 ] ; V_36 ++ ) {
V_35 = & V_276 -> V_26 [ V_36 ] -> V_30 ;
V_276 -> V_26 [ V_36 ] = NULL ;
F_21 ( V_35 ) ;
}
F_30 ( V_276 -> V_26 ) ;
V_275 = & F_81 ( V_90 ) -> V_271 ;
for ( V_36 = 0 ; V_275 -> V_26 [ V_36 ] ; V_36 ++ ) {
V_35 = & V_275 -> V_26 [ V_36 ] -> V_30 ;
V_275 -> V_26 [ V_36 ] = NULL ;
F_21 ( V_35 ) ;
}
F_30 ( V_275 -> V_26 ) ;
F_81 ( V_90 ) -> V_307 = NULL ;
V_226 = & V_90 -> V_204 ;
for ( V_36 = 0 ; V_226 -> V_26 [ V_36 ] ; V_36 ++ ) {
V_35 = & V_226 -> V_26 [ V_36 ] -> V_30 ;
V_226 -> V_26 [ V_36 ] = NULL ;
F_21 ( V_35 ) ;
}
F_21 ( V_3 ) ;
F_10 ( & V_191 -> V_278 ) ;
}
static T_1 F_142 (
struct V_1 * V_191 ,
char * V_7 )
{
return sprintf ( V_7 , L_225 ,
V_191 -> V_308 , V_191 -> V_195 -> V_13 ,
V_9 ) ;
}
static T_1 F_143 ( struct V_1 * V_191 ,
char * V_7 )
{
int V_309 = 0 ;
if ( V_191 -> V_310 & V_311 )
V_309 = 1 ;
return sprintf ( V_7 , L_186 , V_309 ) ;
}
static T_1 F_144 ( struct V_1 * V_191 ,
const char * V_7 , T_2 V_97 )
{
struct V_193 * V_195 = V_191 -> V_195 ;
unsigned long V_312 ;
int V_20 ;
if ( V_195 -> V_313 == NULL )
return - V_22 ;
V_20 = F_93 ( V_7 , 0 , & V_312 ) ;
if ( V_20 < 0 ) {
F_12 ( V_23 L_226 , V_20 ) ;
return - V_22 ;
}
F_40 ( & V_191 -> V_314 ) ;
if ( ! ( F_145 ( & V_191 -> V_315 ) ) ) {
F_12 ( V_23 L_227 ) ;
F_42 ( & V_191 -> V_314 ) ;
return - V_22 ;
}
F_42 ( & V_191 -> V_314 ) ;
V_20 = V_195 -> V_313 ( V_191 , V_312 ) ;
if ( V_20 < 0 )
return - V_22 ;
if ( V_20 > 0 )
V_191 -> V_310 |= V_311 ;
else if ( V_20 == 0 )
V_191 -> V_310 &= ~ V_311 ;
return V_97 ;
}
static void F_146 ( struct V_2 * V_3 )
{
struct V_1 * V_191 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_147 ( V_191 ) ;
}
static struct V_18 * F_148 (
struct V_18 * V_19 ,
const char * V_13 )
{
char * V_316 , * V_317 , * V_318 ;
struct V_1 * V_191 ;
char V_99 [ V_319 ] ;
unsigned long V_320 = 0 ;
int V_20 ;
memset ( V_99 , 0 , V_319 ) ;
if ( strlen ( V_13 ) >= V_319 ) {
F_12 ( V_23 L_228
L_229 , ( int ) strlen ( V_13 ) ,
V_319 ) ;
return F_14 ( - V_321 ) ;
}
snprintf ( V_99 , V_319 , L_30 , V_13 ) ;
V_317 = strstr ( V_99 , L_230 ) ;
if ( ! ( V_317 ) ) {
F_12 ( V_23 L_231 ) ;
return F_14 ( - V_22 ) ;
}
V_316 = V_99 ;
V_318 = strstr ( V_317 + 1 , L_230 ) ;
if ( ( V_318 ) ) {
* V_318 = '\0' ;
V_318 ++ ;
V_317 = V_318 ;
} else {
* V_317 = '\0' ;
V_317 ++ ;
}
V_20 = F_93 ( V_317 , 0 , & V_320 ) ;
if ( V_20 < 0 ) {
F_12 ( V_23 L_173
L_232 , V_20 ) ;
return F_14 ( - V_22 ) ;
}
if ( F_13 () < 0 )
return F_14 ( - V_22 ) ;
V_191 = F_149 ( V_316 , V_320 , 0 ) ;
if ( F_78 ( V_191 ) )
return F_150 ( V_191 ) ;
F_17 ( & V_191 -> V_4 , V_13 ,
& V_322 ) ;
return & V_191 -> V_4 ;
}
static void F_151 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
F_21 ( V_3 ) ;
}
static int T_8 F_152 ( void )
{
struct V_18 * V_323 , * V_324 = NULL , * V_325 = NULL ;
struct V_18 * V_326 = NULL ;
struct V_86 * V_327 ;
struct V_212 * V_213 ;
int V_20 ;
F_12 ( V_21 L_233
L_234 V_8 L_3 ,
V_328 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_327 = V_43 [ 0 ] ;
F_153 ( & V_327 -> V_85 ) ;
F_154 ( & V_327 -> V_329 ) ;
F_24 ( & V_44 ) ;
F_154 ( & V_15 ) ;
F_155 () ;
V_20 = F_156 () ;
if ( V_20 < 0 )
return - 1 ;
V_323 = & V_327 -> V_85 ;
V_323 -> V_26 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_40 ) ;
if ( ! ( V_323 -> V_26 ) ) {
F_12 ( V_23 L_235 ) ;
goto V_330;
}
F_17 ( & V_294 -> V_331 ,
L_236 , & V_332 ) ;
V_323 -> V_26 [ 0 ] = & V_294 -> V_331 ;
V_323 -> V_26 [ 1 ] = NULL ;
V_324 = & V_294 -> V_331 ;
V_324 -> V_26 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_40 ) ;
if ( ! ( V_324 -> V_26 ) ) {
F_12 ( V_23 L_237 ) ;
goto V_330;
}
F_17 ( & V_294 -> V_333 ,
L_217 , & V_334 ) ;
V_324 -> V_26 [ 0 ] = & V_294 -> V_333 ;
V_324 -> V_26 [ 1 ] = NULL ;
V_325 = & V_294 -> V_333 ;
V_325 -> V_26 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_40 ) ;
if ( ! ( V_325 -> V_26 ) ) {
F_12 ( V_23 L_238 ) ;
goto V_330;
}
F_17 ( & V_294 -> V_335 ,
L_239 , & V_336 ) ;
V_325 -> V_26 [ 0 ] = & V_294 -> V_335 ;
V_325 -> V_26 [ 1 ] = NULL ;
V_213 = F_99 ( L_240 , 1 ) ;
if ( F_78 ( V_213 ) )
goto V_330;
V_326 = & V_294 -> V_335 ;
V_326 -> V_26 = F_23 ( sizeof( struct V_18 ) * 2 ,
V_40 ) ;
if ( ! ( V_326 -> V_26 ) ) {
F_12 ( V_23 L_241 ) ;
goto V_330;
}
F_17 ( & V_213 -> V_220 , L_240 ,
& V_239 ) ;
V_326 -> V_26 [ 0 ] = & V_213 -> V_220 ;
V_326 -> V_26 [ 1 ] = NULL ;
V_294 -> V_337 = V_213 ;
V_20 = F_157 ( V_327 ) ;
if ( V_20 < 0 ) {
F_12 ( V_23 L_242 ,
V_20 , V_327 -> V_85 . V_30 . V_338 ) ;
goto V_330;
}
F_12 ( V_21 L_243
L_244 V_9 L_245
L_246 V_8 L_3 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_20 = F_158 () ;
if ( V_20 < 0 )
goto V_173;
if ( F_159 () < 0 )
goto V_173;
return 0 ;
V_173:
F_160 ( V_327 ) ;
F_161 () ;
F_162 () ;
V_330:
if ( V_294 -> V_337 ) {
F_97 ( V_294 -> V_337 ) ;
V_294 -> V_337 = NULL ;
}
if ( V_326 )
F_30 ( V_326 -> V_26 ) ;
if ( V_325 )
F_30 ( V_325 -> V_26 ) ;
if ( V_324 )
F_30 ( V_324 -> V_26 ) ;
F_30 ( V_323 -> V_26 ) ;
F_163 () ;
return - 1 ;
}
static void T_9 F_164 ( void )
{
struct V_86 * V_327 ;
struct V_18 * V_324 , * V_325 , * V_326 ;
struct V_2 * V_3 ;
int V_36 ;
V_294 -> V_339 = 1 ;
V_327 = V_43 [ 0 ] ;
V_326 = & V_294 -> V_335 ;
for ( V_36 = 0 ; V_326 -> V_26 [ V_36 ] ; V_36 ++ ) {
V_3 = & V_326 -> V_26 [ V_36 ] -> V_30 ;
V_326 -> V_26 [ V_36 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_326 -> V_26 ) ;
V_326 -> V_26 = NULL ;
V_325 = & V_294 -> V_333 ;
for ( V_36 = 0 ; V_325 -> V_26 [ V_36 ] ; V_36 ++ ) {
V_3 = & V_325 -> V_26 [ V_36 ] -> V_30 ;
V_325 -> V_26 [ V_36 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_325 -> V_26 ) ;
V_325 -> V_26 = NULL ;
V_324 = & V_294 -> V_331 ;
for ( V_36 = 0 ; V_324 -> V_26 [ V_36 ] ; V_36 ++ ) {
V_3 = & V_324 -> V_26 [ V_36 ] -> V_30 ;
V_324 -> V_26 [ V_36 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_324 -> V_26 ) ;
V_324 -> V_26 = NULL ;
F_160 ( V_327 ) ;
F_30 ( V_327 -> V_85 . V_26 ) ;
F_97 ( V_294 -> V_337 ) ;
V_294 -> V_337 = NULL ;
F_12 ( V_21 L_247
L_248 ) ;
F_161 () ;
F_162 () ;
F_163 () ;
return;
}
