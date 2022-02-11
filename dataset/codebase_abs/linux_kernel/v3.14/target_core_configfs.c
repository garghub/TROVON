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
& V_14 -> V_22 . V_23 ) ;
V_14 -> V_24 . V_25 = V_14 -> V_26 ;
V_14 -> V_24 . V_25 [ 0 ] = & V_14 -> V_27 ;
V_14 -> V_24 . V_25 [ 1 ] = NULL ;
F_16 ( & V_14 -> V_24 , V_13 ,
& V_14 -> V_22 . V_23 ) ;
F_16 ( & V_14 -> V_27 , L_16 ,
& V_14 -> V_22 . V_28 ) ;
F_12 ( L_17
L_5 , V_14 -> V_24 . V_29 . V_30 ) ;
V_14 -> V_31 . V_32 = V_14 -> V_32 ;
V_14 -> V_33 = & V_14 -> V_24 . V_29 ;
F_12 ( L_18
L_19 , V_13 ) ;
return & V_14 -> V_24 ;
}
static void F_17 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_12 * V_14 = F_2 (
F_3 ( V_3 ) , struct V_12 , V_24 ) ;
struct V_18 * V_24 ;
struct V_2 * V_34 ;
int V_35 ;
F_12 ( L_20
L_21 , F_18 ( V_3 ) ) ;
F_12 ( L_22
L_5 , V_14 -> V_16 ) ;
F_19 ( & V_14 -> V_17 ) ;
F_12 ( L_23
L_24 , V_14 -> V_16 ) ;
V_14 -> V_33 = NULL ;
F_12 ( L_25
L_5 , F_18 ( V_3 ) ) ;
V_24 = & V_14 -> V_24 ;
for ( V_35 = 0 ; V_24 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_34 = & V_24 -> V_25 [ V_35 ] -> V_29 ;
V_24 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_34 ) ;
}
F_20 ( V_3 ) ;
}
struct V_12 * F_21 (
struct V_36 * V_37 ,
const char * V_13 )
{
struct V_12 * V_14 ;
if ( ! ( V_13 ) ) {
F_14 ( L_26 ) ;
return F_15 ( - V_21 ) ;
}
if ( strlen ( V_13 ) >= V_38 ) {
F_14 ( L_27
L_28 , V_13 ) ;
return F_15 ( - V_21 ) ;
}
V_14 = F_22 ( sizeof( struct V_12 ) , V_39 ) ;
if ( ! V_14 )
return F_15 ( - V_40 ) ;
F_23 ( & V_14 -> V_41 ) ;
F_24 ( & V_14 -> V_17 , 0 ) ;
V_14 -> V_42 = V_37 ;
F_25 ( V_14 ) ;
V_14 -> V_32 = V_43 [ 0 ] ;
snprintf ( V_14 -> V_16 , V_38 , L_29 , V_13 ) ;
F_7 ( & V_15 ) ;
F_26 ( & V_14 -> V_41 , & V_44 ) ;
F_10 ( & V_15 ) ;
F_12 ( L_30
L_31 ) ;
F_12 ( L_32
L_5 , V_14 , V_14 -> V_16 ) ;
return V_14 ;
}
void F_27 (
struct V_12 * V_14 )
{
F_7 ( & V_15 ) ;
F_28 ( & V_14 -> V_41 ) ;
F_10 ( & V_15 ) ;
F_29 ( V_14 ) ;
}
static int F_30 (
struct V_12 * V_14 )
{
struct V_45 * V_46 = & V_14 -> V_31 ;
if ( ! V_46 -> V_47 ) {
F_14 ( L_33 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_48 ) {
F_14 ( L_34 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_49 ) {
F_14 ( L_35 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_50 ) {
F_14 ( L_36 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_51 ) {
F_14 ( L_37 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_52 ) {
F_14 ( L_38 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_53 ) {
F_14 ( L_39 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_54 ) {
F_14 ( L_40 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_55 ) {
F_14 ( L_41 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_56 ) {
F_14 ( L_42 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_57 ) {
F_14 ( L_43 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_58 ) {
F_14 ( L_44 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_59 ) {
F_14 ( L_45 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_60 ) {
F_14 ( L_46 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_61 ) {
F_14 ( L_47 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_62 ) {
F_14 ( L_48 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_63 ) {
F_14 ( L_49 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_64 ) {
F_14 ( L_50 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_65 ) {
F_14 ( L_51 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_66 ) {
F_14 ( L_52 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_67 ) {
F_14 ( L_53 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_68 ) {
F_14 ( L_54 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_69 ) {
F_14 ( L_55 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_70 ) {
F_14 ( L_56 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_71 ) {
F_14 ( L_57 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_72 ) {
F_14 ( L_58 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_73 ) {
F_14 ( L_59 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_74 ) {
F_14 ( L_60 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_75 ) {
F_14 ( L_61 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_76 ) {
F_14 ( L_62 ) ;
return - V_21 ;
}
return 0 ;
}
int F_31 (
struct V_12 * V_14 )
{
int V_20 ;
if ( ! V_14 ) {
F_14 ( L_63
L_64 ) ;
return - V_21 ;
}
if ( ! V_14 -> V_32 ) {
F_14 ( L_65
L_64 ) ;
return - V_21 ;
}
V_20 = F_30 ( V_14 ) ;
if ( V_20 < 0 )
return V_20 ;
F_12 ( L_66
L_67 ) ;
return 0 ;
}
void F_32 (
struct V_12 * V_14 )
{
struct V_77 * V_78 ;
if ( ! V_14 ) {
F_14 ( L_68
L_69 ) ;
return;
}
V_78 = V_14 -> V_32 ;
if ( ! V_78 ) {
F_14 ( L_70
L_64 ) ;
return;
}
F_12 ( L_71
L_72 ) ;
F_7 ( & V_15 ) ;
if ( F_33 ( & V_14 -> V_17 ) ) {
F_10 ( & V_15 ) ;
F_14 ( L_73 ,
V_14 -> V_16 ) ;
F_34 () ;
}
F_28 ( & V_14 -> V_41 ) ;
F_10 ( & V_15 ) ;
F_12 ( L_74
L_5 , V_14 -> V_16 ) ;
V_14 -> V_42 = NULL ;
V_14 -> V_32 = NULL ;
F_29 ( V_14 ) ;
F_12 ( L_75
L_76 ) ;
}
static T_1 F_35 (
struct V_79 * V_79 ,
char * V_7 )
{
return sprintf ( V_7 , L_77 ,
& V_79 -> V_80 [ 0 ] ) ;
}
static T_1 F_36 (
struct V_79 * V_79 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_79 -> V_84 ;
unsigned char V_85 [ V_86 ] ;
if ( V_83 -> V_87 & V_88 ) {
F_14 ( L_78
L_79 ) ;
return - V_89 ;
}
if ( strlen ( V_7 ) >= V_86 ) {
F_14 ( L_80
L_81 , V_86 ) ;
return - V_90 ;
}
if ( V_83 -> V_91 ) {
F_14 ( L_82
L_83 ,
V_83 -> V_91 ) ;
return - V_21 ;
}
memset ( V_85 , 0 , V_86 ) ;
snprintf ( V_85 , V_86 , L_29 , V_7 ) ;
snprintf ( V_83 -> V_79 . V_80 , V_86 ,
L_29 , F_37 ( V_85 ) ) ;
V_83 -> V_87 |= V_92 ;
F_12 ( L_84
L_5 , V_83 -> V_79 . V_80 ) ;
return V_81 ;
}
static T_1 F_38 (
struct V_79 * V_79 ,
char * V_7 )
{
struct V_93 * V_94 ;
unsigned char V_85 [ V_95 ] ;
T_1 V_96 = 0 ;
memset ( V_85 , 0 , V_95 ) ;
F_39 ( & V_79 -> V_97 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_94 -> V_98 )
continue;
F_40 ( V_94 , V_85 , V_95 ) ;
if ( V_96 + strlen ( V_85 ) >= V_99 )
break;
V_96 += sprintf ( V_7 + V_96 , L_29 , V_85 ) ;
}
F_41 ( & V_79 -> V_97 ) ;
return V_96 ;
}
static T_1 F_42 (
struct V_79 * V_79 ,
const char * V_7 ,
T_2 V_81 )
{
return - V_100 ;
}
static T_1 F_43 (
struct V_79 * V_79 ,
const char * V_7 ,
T_2 V_81 )
{
return - V_100 ;
}
static T_1 F_44 (
struct V_79 * V_79 ,
const char * V_7 ,
T_2 V_81 )
{
return - V_100 ;
}
static T_1 F_45 (
struct V_79 * V_79 ,
const char * V_7 ,
T_2 V_81 )
{
return - V_100 ;
}
static T_1 F_46 ( struct V_82 * V_83 ,
char * V_7 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
char V_105 [ V_106 ] ;
memset ( V_105 , 0 , V_106 ) ;
V_104 = V_83 -> V_107 ;
if ( ! V_104 )
return sprintf ( V_7 , L_85 ) ;
V_102 = V_104 -> V_108 ;
F_47 ( V_104 , V_105 , V_106 ) ;
return sprintf ( V_7 , L_86 ,
V_102 -> V_109 -> V_110 -> V_47 () ,
V_102 -> V_111 , V_105 ) ;
}
static T_1 F_48 ( struct V_82 * V_83 ,
char * V_7 )
{
struct V_101 * V_102 ;
T_1 V_96 ;
V_102 = V_83 -> V_112 ;
if ( V_102 ) {
V_96 = sprintf ( V_7 ,
L_87 ,
V_102 -> V_109 -> V_110 -> V_47 () ,
V_102 -> V_111 ) ;
} else {
V_96 = sprintf ( V_7 , L_88 ) ;
}
return V_96 ;
}
static T_1 F_49 ( struct V_82 * V_83 ,
char * V_7 )
{
int V_20 ;
if ( V_83 -> V_113 -> V_114 == V_115 )
return sprintf ( V_7 , L_89 ) ;
F_39 ( & V_83 -> V_116 ) ;
if ( V_83 -> V_117 & V_118 )
V_20 = F_48 ( V_83 , V_7 ) ;
else
V_20 = F_46 ( V_83 , V_7 ) ;
F_41 ( & V_83 -> V_116 ) ;
return V_20 ;
}
static T_1 F_50 (
struct V_82 * V_83 , char * V_7 )
{
T_1 V_96 = 0 ;
F_39 ( & V_83 -> V_116 ) ;
if ( ! V_83 -> V_107 ) {
V_96 = sprintf ( V_7 , L_85 ) ;
} else if ( V_83 -> V_107 -> V_119 ) {
V_96 = sprintf ( V_7 , L_90
L_91 ) ;
} else {
V_96 = sprintf ( V_7 , L_92
L_93 ) ;
}
F_41 ( & V_83 -> V_116 ) ;
return V_96 ;
}
static T_1 F_51 (
struct V_82 * V_83 , char * V_7 )
{
return sprintf ( V_7 , L_94 , V_83 -> V_120 . V_121 ) ;
}
static T_1 F_52 (
struct V_82 * V_83 , char * V_7 )
{
struct V_101 * V_102 ;
struct V_122 * V_123 ;
struct V_124 * V_109 ;
struct V_103 * V_104 ;
struct V_45 * V_46 ;
T_1 V_96 = 0 ;
F_39 ( & V_83 -> V_116 ) ;
V_104 = V_83 -> V_107 ;
if ( ! V_104 ) {
V_96 = sprintf ( V_7 , L_85 ) ;
goto V_125;
}
V_102 = V_104 -> V_108 ;
V_109 = V_102 -> V_109 ;
V_123 = V_104 -> V_126 ;
V_46 = V_109 -> V_110 ;
V_96 += sprintf ( V_7 + V_96 , L_95
L_96 , V_46 -> V_47 () ,
V_46 -> V_49 ( V_109 ) ) ;
V_96 += sprintf ( V_7 + V_96 , L_97
L_98
L_99 , V_123 -> V_127 -> V_128 ,
V_46 -> V_47 () , V_46 -> V_50 ( V_109 ) ,
V_46 -> V_47 () , V_123 -> V_129 ) ;
V_125:
F_41 ( & V_83 -> V_116 ) ;
return V_96 ;
}
static T_1 F_53 (
struct V_82 * V_83 , char * V_7 )
{
struct V_45 * V_46 ;
struct V_103 * V_104 ;
unsigned char V_85 [ 384 ] ;
char V_105 [ V_106 ] ;
T_1 V_96 = 0 ;
int V_130 = 0 ;
V_96 += sprintf ( V_7 + V_96 , L_100 ) ;
F_39 ( & V_83 -> V_120 . V_131 ) ;
F_8 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_85 , 0 , 384 ) ;
memset ( V_105 , 0 , V_106 ) ;
V_46 = V_104 -> V_108 -> V_109 -> V_110 ;
F_47 ( V_104 , V_105 ,
V_106 ) ;
sprintf ( V_85 , L_101 ,
V_46 -> V_47 () ,
V_104 -> V_108 -> V_111 , V_105 , V_104 -> V_132 ,
V_104 -> V_133 ) ;
if ( V_96 + strlen ( V_85 ) >= V_99 )
break;
V_96 += sprintf ( V_7 + V_96 , L_29 , V_85 ) ;
V_130 ++ ;
}
F_41 ( & V_83 -> V_120 . V_131 ) ;
if ( ! V_130 )
V_96 += sprintf ( V_7 + V_96 , L_102 ) ;
return V_96 ;
}
static T_1 F_54 (
struct V_82 * V_83 , char * V_7 )
{
struct V_103 * V_104 ;
T_1 V_96 = 0 ;
F_39 ( & V_83 -> V_116 ) ;
V_104 = V_83 -> V_107 ;
if ( V_104 ) {
V_96 = sprintf ( V_7 , L_103 ,
F_55 ( V_104 -> V_134 ) ) ;
} else {
V_96 = sprintf ( V_7 , L_85 ) ;
}
F_41 ( & V_83 -> V_116 ) ;
return V_96 ;
}
static T_1 F_56 (
struct V_82 * V_83 , char * V_7 )
{
if ( V_83 -> V_113 -> V_114 == V_115 )
return sprintf ( V_7 , L_104 ) ;
else if ( V_83 -> V_117 & V_118 )
return sprintf ( V_7 , L_105 ) ;
else
return sprintf ( V_7 , L_106 ) ;
}
static T_1 F_57 (
struct V_82 * V_83 , char * V_7 )
{
if ( V_83 -> V_113 -> V_114 == V_115 )
return 0 ;
return sprintf ( V_7 , L_107 ,
( V_83 -> V_120 . V_135 ) ? L_108 : L_109 ) ;
}
static T_1 F_58 (
struct V_82 * V_83 , char * V_7 )
{
if ( V_83 -> V_113 -> V_114 == V_115 )
return 0 ;
return sprintf ( V_7 , L_110 ) ;
}
static T_1 F_59 (
struct V_82 * V_83 ,
const char * V_7 ,
T_2 V_81 )
{
unsigned char * V_136 = NULL , * V_137 = NULL , * V_138 = NULL ;
unsigned char * V_139 = NULL , * V_140 = NULL ;
char * V_141 , * V_142 , * V_143 , * V_144 ;
T_3 args [ V_145 ] ;
unsigned long long V_146 ;
T_4 V_147 = 0 ;
T_5 V_148 = 0 , V_149 = 0 ;
int V_20 = - 1 , V_150 = 0 , V_151 = 0 , V_152 , V_153 ;
T_6 V_154 = 0 , V_155 = 0 ;
T_7 type = 0 , V_156 ;
if ( V_83 -> V_113 -> V_114 == V_115 )
return 0 ;
if ( V_83 -> V_117 & V_118 )
return 0 ;
if ( V_83 -> V_91 ) {
F_12 ( L_111
L_112 ) ;
return - V_21 ;
}
V_144 = F_60 ( V_7 , V_39 ) ;
if ( ! V_144 )
return - V_40 ;
V_141 = V_144 ;
while ( ( V_142 = F_61 ( & V_144 , L_113 ) ) != NULL ) {
if ( ! * V_142 )
continue;
V_153 = F_62 ( V_142 , V_157 , args ) ;
switch ( V_153 ) {
case V_158 :
V_136 = F_63 ( & args [ 0 ] ) ;
if ( ! V_136 ) {
V_20 = - V_40 ;
goto V_159;
}
break;
case V_160 :
V_137 = F_63 ( & args [ 0 ] ) ;
if ( ! V_137 ) {
V_20 = - V_40 ;
goto V_159;
}
if ( strlen ( V_137 ) >= V_161 ) {
F_14 ( L_114
L_115 ,
V_161 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_162 :
V_138 = F_63 ( & args [ 0 ] ) ;
if ( ! V_138 ) {
V_20 = - V_40 ;
goto V_159;
}
if ( strlen ( V_138 ) >= V_163 ) {
F_14 ( L_116
L_117 ,
V_163 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_164 :
V_143 = F_63 ( & args [ 0 ] ) ;
if ( ! V_143 ) {
V_20 = - V_40 ;
goto V_159;
}
V_20 = F_64 ( V_143 , 0 , & V_146 ) ;
if ( V_20 < 0 ) {
F_14 ( L_118
L_119 ) ;
goto V_159;
}
V_147 = ( T_4 ) V_146 ;
break;
case V_165 :
F_65 ( args , & V_152 ) ;
V_150 = V_152 ;
break;
case V_166 :
F_65 ( args , & V_152 ) ;
type = ( T_7 ) V_152 ;
break;
case V_167 :
F_65 ( args , & V_152 ) ;
V_156 = ( T_7 ) V_152 ;
break;
case V_168 :
F_65 ( args , & V_152 ) ;
V_151 = ( int ) V_152 ;
break;
case V_169 :
F_65 ( args , & V_152 ) ;
V_148 = ( T_5 ) V_152 ;
break;
case V_170 :
V_139 = F_63 ( & args [ 0 ] ) ;
if ( ! V_139 ) {
V_20 = - V_40 ;
goto V_159;
}
break;
case V_171 :
V_140 = F_63 ( & args [ 0 ] ) ;
if ( ! V_140 ) {
V_20 = - V_40 ;
goto V_159;
}
if ( strlen ( V_140 ) >= V_172 ) {
F_14 ( L_120
L_121 ,
V_172 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_173 :
F_65 ( args , & V_152 ) ;
V_155 = ( T_6 ) V_152 ;
break;
case V_174 :
F_65 ( args , & V_152 ) ;
V_154 = ( T_6 ) V_152 ;
break;
case V_175 :
F_65 ( args , & V_152 ) ;
V_149 = ( T_5 ) V_152 ;
break;
default:
break;
}
}
if ( ! V_137 || ! V_140 || ! V_147 ) {
F_14 ( L_122 ) ;
V_20 = - V_21 ;
goto V_159;
}
if ( V_150 && ! ( type ) ) {
F_14 ( L_123
L_124 , type ) ;
V_20 = - V_21 ;
goto V_159;
}
V_20 = F_66 ( & V_83 -> V_120 , V_147 ,
V_137 , V_138 , V_148 , V_140 , V_155 , V_149 ,
V_150 , V_151 , type ) ;
V_159:
F_29 ( V_136 ) ;
F_29 ( V_137 ) ;
F_29 ( V_138 ) ;
F_29 ( V_139 ) ;
F_29 ( V_140 ) ;
F_29 ( V_141 ) ;
return ( V_20 == 0 ) ? V_81 : V_20 ;
}
static T_1 F_67 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
struct V_177 * V_178 = V_83 -> V_113 ;
int V_179 = 0 ;
T_1 V_180 = 0 ;
F_68 ( V_83 , V_7 , & V_179 ) ;
V_180 += V_179 ;
V_180 += V_178 -> V_181 ( V_83 , V_7 + V_180 ) ;
return V_180 ;
}
static T_1 F_69 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
struct V_177 * V_178 = V_83 -> V_113 ;
return V_178 -> V_182 ( V_83 , V_7 , V_81 ) ;
}
static T_1 F_70 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
if ( ! ( V_83 -> V_87 & V_183 ) )
return 0 ;
return snprintf ( V_7 , V_99 , L_125 , V_83 -> V_184 ) ;
}
static T_1 F_71 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
struct V_1 * V_185 = V_83 -> V_1 ;
T_1 V_180 ;
if ( V_81 > ( V_186 - 1 ) ) {
F_14 ( L_126
L_127 , ( int ) V_81 ,
V_186 - 1 ) ;
return - V_21 ;
}
V_180 = snprintf ( & V_83 -> V_184 [ 0 ] , V_186 , L_29 , V_7 ) ;
if ( ! V_180 )
return - V_21 ;
if ( V_83 -> V_184 [ V_180 - 1 ] == '\n' )
V_83 -> V_184 [ V_180 - 1 ] = '\0' ;
V_83 -> V_87 |= V_183 ;
F_12 ( L_128 ,
F_18 ( & V_185 -> V_4 . V_29 ) ,
F_18 ( & V_83 -> V_187 . V_29 ) ,
V_83 -> V_184 ) ;
return V_180 ;
}
static T_1 F_72 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
if ( ! ( V_83 -> V_87 & V_188 ) )
return 0 ;
return snprintf ( V_7 , V_99 , L_125 , V_83 -> V_189 ) ;
}
static T_1 F_73 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
struct V_1 * V_185 = V_83 -> V_1 ;
T_1 V_180 ;
if ( V_81 > ( V_190 - 1 ) ) {
F_14 ( L_129
L_130 , ( int ) V_81 ,
V_190 - 1 ) ;
return - V_21 ;
}
V_180 = snprintf ( & V_83 -> V_189 [ 0 ] , V_190 ,
L_29 , V_7 ) ;
if ( ! V_180 )
return - V_21 ;
if ( V_83 -> V_189 [ V_180 - 1 ] == '\n' )
V_83 -> V_189 [ V_180 - 1 ] = '\0' ;
V_83 -> V_87 |= V_188 ;
F_12 ( L_131 ,
F_18 ( & V_185 -> V_4 . V_29 ) ,
F_18 ( & V_83 -> V_187 . V_29 ) ,
V_83 -> V_189 ) ;
return V_180 ;
}
static T_1 F_74 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
return snprintf ( V_7 , V_99 , L_132 , ! ! ( V_83 -> V_87 & V_191 ) ) ;
}
static T_1 F_75 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
char * V_142 ;
int V_20 ;
V_142 = strstr ( V_7 , L_133 ) ;
if ( ! V_142 ) {
F_14 ( L_134
L_135 ) ;
return - V_21 ;
}
V_20 = F_76 ( V_83 ) ;
if ( V_20 )
return V_20 ;
return V_81 ;
}
static T_1 F_77 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
struct V_2 * V_192 ;
struct V_193 * V_194 ;
struct V_195 * V_196 ;
T_1 V_96 = 0 ;
V_196 = V_83 -> V_197 ;
if ( ! V_196 )
return 0 ;
F_39 ( & V_196 -> V_198 ) ;
V_194 = V_196 -> V_194 ;
if ( V_194 ) {
V_192 = & V_194 -> V_199 . V_29 ;
V_96 += sprintf ( V_7 , L_136 ,
F_18 ( V_192 ) , V_194 -> V_200 ) ;
}
F_41 ( & V_196 -> V_198 ) ;
return V_96 ;
}
static T_1 F_78 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
struct V_1 * V_185 = V_83 -> V_1 ;
struct V_193 * V_194 = NULL , * V_201 = NULL ;
struct V_195 * V_196 ;
unsigned char V_85 [ V_202 ] ;
int V_203 = 0 ;
V_196 = V_83 -> V_197 ;
if ( ! V_196 )
return 0 ;
if ( V_81 > V_202 ) {
F_14 ( L_137 ) ;
return - V_21 ;
}
memset ( V_85 , 0 , V_202 ) ;
memcpy ( V_85 , V_7 , V_81 ) ;
if ( strcmp ( F_37 ( V_85 ) , L_138 ) ) {
V_201 = F_79 ( F_37 ( V_85 ) ) ;
if ( ! V_201 )
return - V_204 ;
}
F_39 ( & V_196 -> V_198 ) ;
V_194 = V_196 -> V_194 ;
if ( V_194 ) {
if ( ! V_201 ) {
F_12 ( L_139
L_140
L_141 ,
F_18 ( & V_185 -> V_4 . V_29 ) ,
F_18 ( & V_83 -> V_187 . V_29 ) ,
F_18 ( & V_194 -> V_199 . V_29 ) ,
V_194 -> V_200 ) ;
F_80 ( V_196 , V_194 ) ;
F_41 ( & V_196 -> V_198 ) ;
return V_81 ;
}
F_80 ( V_196 , V_194 ) ;
V_203 = 1 ;
}
F_81 ( V_196 , V_201 ) ;
F_41 ( & V_196 -> V_198 ) ;
F_12 ( L_142
L_143 ,
( V_203 ) ? L_144 : L_145 ,
F_18 ( & V_185 -> V_4 . V_29 ) ,
F_18 ( & V_83 -> V_187 . V_29 ) ,
F_18 ( & V_201 -> V_199 . V_29 ) ,
V_201 -> V_200 ) ;
F_82 ( V_201 ) ;
return V_81 ;
}
static T_1 F_83 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
struct V_205 * V_206 ;
struct V_207 * V_208 ;
char * V_209 = V_7 ;
int V_179 = 0 ;
char V_210 ;
F_39 ( & V_83 -> V_211 . V_212 ) ;
if ( ! F_84 ( & V_83 -> V_211 . V_213 ) )
V_179 += sprintf ( V_209 + V_179 , L_146 ,
V_83 -> V_211 . V_214 ,
V_83 -> V_211 . V_215 ) ;
F_8 (map, &dev->t10_alua.lba_map_list, lba_map_list) {
V_179 += sprintf ( V_209 + V_179 , L_147 ,
V_206 -> V_216 , V_206 -> V_217 ) ;
F_8 (mem, &map->lba_map_mem_list,
lba_map_mem_list) {
switch ( V_208 -> V_218 ) {
case V_219 :
V_210 = 'O' ;
break;
case V_220 :
V_210 = 'A' ;
break;
case V_221 :
V_210 = 'S' ;
break;
case V_222 :
V_210 = 'U' ;
break;
default:
V_210 = '.' ;
break;
}
V_179 += sprintf ( V_209 + V_179 , L_148 ,
V_208 -> V_223 , V_210 ) ;
}
V_179 += sprintf ( V_209 + V_179 , L_3 ) ;
}
F_41 ( & V_83 -> V_211 . V_212 ) ;
return V_179 ;
}
static T_1 F_85 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
struct V_205 * V_224 = NULL ;
struct V_225 V_226 ;
char * V_227 , * V_142 ;
char V_210 ;
int V_228 = - 1 , V_229 ;
int V_20 = 0 , V_230 = 0 , V_231 , V_232 ;
unsigned long V_233 = - 1 , V_234 = - 1 ;
unsigned long V_235 = - 1 , V_236 = - 1 ;
V_227 = F_60 ( V_7 , V_39 ) ;
if ( ! V_227 )
return - V_40 ;
F_23 ( & V_226 ) ;
while ( ( V_142 = F_61 ( & V_227 , L_3 ) ) != NULL ) {
if ( ! * V_142 )
continue;
if ( V_230 == 0 ) {
if ( sscanf ( V_142 , L_149 ,
& V_235 , & V_236 ) != 2 ) {
F_14 ( L_150 , V_230 ) ;
V_20 = - V_21 ;
break;
}
V_230 ++ ;
continue;
}
if ( sscanf ( V_142 , L_151 , & V_233 , & V_234 ) != 2 ) {
F_14 ( L_150 , V_230 ) ;
V_20 = - V_21 ;
break;
}
V_142 = strchr ( V_142 , ' ' ) ;
if ( ! V_142 ) {
F_14 ( L_152 , V_230 ) ;
V_20 = - V_21 ;
break;
}
V_142 ++ ;
V_142 = strchr ( V_142 , ' ' ) ;
if ( ! V_142 ) {
F_14 ( L_153 ,
V_230 ) ;
V_20 = - V_21 ;
break;
}
V_142 ++ ;
V_224 = F_86 ( & V_226 ,
V_233 , V_234 ) ;
if ( F_87 ( V_224 ) ) {
V_20 = F_88 ( V_224 ) ;
break;
}
V_229 = 0 ;
while ( sscanf ( V_142 , L_154 , & V_231 , & V_210 ) == 2 ) {
switch ( V_210 ) {
case 'O' :
V_232 = V_219 ;
break;
case 'A' :
V_232 = V_220 ;
break;
case 'S' :
V_232 = V_221 ;
break;
case 'U' :
V_232 = V_222 ;
break;
default:
F_14 ( L_155 , V_210 ) ;
V_20 = - V_21 ;
goto V_159;
}
V_20 = F_89 ( V_224 ,
V_231 , V_232 ) ;
if ( V_20 ) {
F_14 ( L_156
L_157 ,
V_231 , V_210 , V_230 ) ;
break;
}
V_229 ++ ;
V_142 = strchr ( V_142 , ' ' ) ;
if ( V_142 )
V_142 ++ ;
else
break;
}
if ( V_228 == - 1 )
V_228 = V_229 ;
else if ( V_229 != V_228 ) {
F_14 ( L_158
L_157 , V_229 , V_228 , V_230 ) ;
V_20 = - V_21 ;
break;
}
V_230 ++ ;
}
V_159:
if ( V_20 ) {
F_90 ( & V_226 ) ;
V_81 = V_20 ;
} else
F_91 ( V_83 , & V_226 ,
V_235 , V_236 ) ;
F_29 ( V_227 ) ;
return V_81 ;
}
static void F_92 ( struct V_2 * V_3 )
{
struct V_18 * V_237 = F_3 ( V_3 ) ;
struct V_82 * V_83 =
F_2 ( V_237 , struct V_82 , V_187 ) ;
F_29 ( V_237 -> V_25 ) ;
F_93 ( V_83 ) ;
}
static T_1 F_94 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
char * V_7 )
{
struct V_18 * V_237 = F_3 ( V_3 ) ;
struct V_82 * V_83 =
F_2 ( V_237 , struct V_82 , V_187 ) ;
struct V_238 * V_239 = F_2 (
V_6 , struct V_238 , V_6 ) ;
if ( ! V_239 -> V_240 )
return - V_21 ;
return V_239 -> V_240 ( V_83 , V_7 ) ;
}
static T_1 F_95 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
const char * V_7 , T_2 V_81 )
{
struct V_18 * V_237 = F_3 ( V_3 ) ;
struct V_82 * V_83 =
F_2 ( V_237 , struct V_82 , V_187 ) ;
struct V_238 * V_239 = F_2 (
V_6 , struct V_238 , V_6 ) ;
if ( ! V_239 -> V_241 )
return - V_21 ;
return V_239 -> V_241 ( V_83 , V_7 , V_81 ) ;
}
static T_1 F_96 (
struct V_193 * V_194 ,
char * V_7 )
{
if ( ! V_194 -> V_242 )
return 0 ;
return sprintf ( V_7 , L_159 , V_194 -> V_200 ) ;
}
static T_1 F_97 (
struct V_193 * V_194 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_18 * V_243 = & V_194 -> V_199 ;
unsigned long V_200 ;
int V_20 ;
V_20 = F_98 ( V_7 , 0 , & V_200 ) ;
if ( V_20 < 0 ) {
F_14 ( L_160
L_161 , V_20 ) ;
return V_20 ;
}
if ( V_200 > 0x0000ffff ) {
F_14 ( L_162
L_163 , V_200 ) ;
return - V_21 ;
}
V_20 = F_99 ( V_194 , ( T_6 ) V_200 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_164
L_165 ,
F_18 ( & V_243 -> V_29 ) ,
V_194 -> V_200 ) ;
return V_81 ;
}
static T_1 F_100 (
struct V_193 * V_194 ,
char * V_7 )
{
struct V_82 * V_83 ;
struct V_1 * V_185 ;
struct V_195 * V_196 ;
T_1 V_96 = 0 , V_244 ;
unsigned char V_85 [ V_202 ] ;
memset ( V_85 , 0 , V_202 ) ;
F_39 ( & V_194 -> V_245 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_83 = V_196 -> V_246 ;
V_185 = V_83 -> V_1 ;
V_244 = snprintf ( V_85 , V_202 , L_166 ,
F_18 ( & V_185 -> V_4 . V_29 ) ,
F_18 ( & V_83 -> V_187 . V_29 ) ) ;
V_244 ++ ;
if ( ( V_244 + V_96 ) > V_99 ) {
F_101 ( L_167
L_168 ) ;
break;
}
memcpy ( V_7 + V_96 , V_85 , V_244 ) ;
V_96 += V_244 ;
}
F_41 ( & V_194 -> V_245 ) ;
return V_96 ;
}
static void F_102 ( struct V_2 * V_3 )
{
struct V_193 * V_194 = F_2 ( F_3 ( V_3 ) ,
struct V_193 , V_199 ) ;
F_103 ( V_194 ) ;
}
static struct V_18 * F_104 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_193 * V_194 ;
struct V_18 * V_243 = NULL ;
struct V_2 * V_247 = NULL ;
V_194 = F_105 ( V_13 , 0 ) ;
if ( F_87 ( V_194 ) )
return NULL ;
V_243 = & V_194 -> V_199 ;
V_247 = & V_243 -> V_29 ;
F_16 ( V_243 , V_13 ,
& V_248 ) ;
F_12 ( L_169
L_170 ,
F_18 ( V_247 ) ) ;
return V_243 ;
}
static void F_106 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_193 * V_194 = F_2 ( F_3 ( V_3 ) ,
struct V_193 , V_199 ) ;
F_12 ( L_171
L_172 ,
F_18 ( V_3 ) , V_194 -> V_200 ) ;
F_20 ( V_3 ) ;
}
static T_1 F_107 (
struct V_249 * V_250 ,
char * V_7 )
{
return sprintf ( V_7 , L_132 ,
F_33 ( & V_250 -> V_251 ) ) ;
}
static T_1 F_108 (
struct V_249 * V_250 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_250 -> V_252 ;
unsigned long V_253 ;
int V_254 , V_20 ;
if ( ! V_250 -> V_255 ) {
F_14 ( L_173
L_174 , V_250 -> V_255 ) ;
return - V_21 ;
}
V_20 = F_98 ( V_7 , 0 , & V_253 ) ;
if ( V_20 < 0 ) {
F_14 ( L_175
L_5 , V_7 ) ;
return V_20 ;
}
V_254 = ( int ) V_253 ;
if ( ! ( V_250 -> V_256 & V_257 ) ) {
F_14 ( L_176
L_177 ) ;
return - V_21 ;
}
if ( V_250 -> V_256 & V_258 &&
V_254 == V_259 ) {
F_14 ( L_178
L_179 ) ;
return - V_21 ;
}
V_20 = F_109 ( V_250 , V_83 ,
NULL , NULL , V_254 , 0 ) ;
return ( ! V_20 ) ? V_81 : - V_21 ;
}
static T_1 F_110 (
struct V_249 * V_250 ,
char * V_7 )
{
return sprintf ( V_7 , L_125 ,
F_111 ( V_250 -> V_260 ) ) ;
}
static T_1 F_112 (
struct V_249 * V_250 ,
const char * V_7 ,
T_2 V_81 )
{
unsigned long V_253 ;
int V_261 , V_20 ;
if ( ! V_250 -> V_255 ) {
F_14 ( L_180
L_181 ,
V_250 -> V_255 ) ;
return - V_21 ;
}
V_20 = F_98 ( V_7 , 0 , & V_253 ) ;
if ( V_20 < 0 ) {
F_14 ( L_182
L_183 , V_7 ) ;
return V_20 ;
}
V_261 = ( int ) V_253 ;
if ( ( V_261 != V_262 ) &&
( V_261 != V_263 ) &&
( V_261 != V_264 ) ) {
F_14 ( L_184 ,
V_261 ) ;
return - V_21 ;
}
V_250 -> V_260 = V_261 ;
return V_81 ;
}
static T_1 F_113 (
struct V_249 * V_250 ,
char * V_7 )
{
return F_114 ( V_250 , V_7 ) ;
}
static T_1 F_115 (
struct V_249 * V_250 ,
const char * V_7 ,
T_2 V_81 )
{
return F_116 ( V_250 , V_7 , V_81 ) ;
}
static T_1 F_117 (
struct V_249 * V_250 ,
char * V_7 )
{
return sprintf ( V_7 , L_132 , V_250 -> V_265 ) ;
}
static T_1 F_118 (
struct V_249 * V_250 ,
const char * V_7 ,
T_2 V_81 )
{
unsigned long V_253 ;
int V_20 ;
V_20 = F_98 ( V_7 , 0 , & V_253 ) ;
if ( V_20 < 0 ) {
F_14 ( L_185 ) ;
return V_20 ;
}
if ( ( V_253 != 0 ) && ( V_253 != 1 ) ) {
F_14 ( L_186
L_187 , V_253 ) ;
return - V_21 ;
}
V_250 -> V_265 = ( int ) V_253 ;
return V_81 ;
}
static T_1 F_119 (
struct V_249 * V_250 ,
char * V_7 )
{
return F_120 ( V_250 , V_7 ) ;
}
static T_1 F_121 (
struct V_249 * V_250 ,
const char * V_7 ,
T_2 V_81 )
{
return F_122 ( V_250 , V_7 , V_81 ) ;
}
static T_1 F_123 (
struct V_249 * V_250 ,
char * V_7 )
{
return F_124 ( V_250 , V_7 ) ;
}
static T_1 F_125 (
struct V_249 * V_250 ,
const char * V_7 ,
T_2 V_81 )
{
return F_126 ( V_250 , V_7 , V_81 ) ;
}
static T_1 F_127 (
struct V_249 * V_250 ,
char * V_7 )
{
return F_128 ( V_250 , V_7 ) ;
}
static T_1 F_129 (
struct V_249 * V_250 ,
const char * V_7 ,
T_2 V_81 )
{
return F_130 ( V_250 , V_7 , V_81 ) ;
}
static T_1 F_131 (
struct V_249 * V_250 ,
char * V_7 )
{
return F_132 ( V_250 , V_7 ) ;
}
static T_1 F_133 (
struct V_249 * V_250 ,
const char * V_7 ,
T_2 V_81 )
{
return F_134 ( V_250 , V_7 , V_81 ) ;
}
static T_1 F_135 (
struct V_249 * V_250 ,
char * V_7 )
{
if ( ! V_250 -> V_255 )
return 0 ;
return sprintf ( V_7 , L_159 , V_250 -> V_266 ) ;
}
static T_1 F_136 (
struct V_249 * V_250 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_18 * V_267 = & V_250 -> V_268 ;
unsigned long V_266 ;
int V_20 ;
V_20 = F_98 ( V_7 , 0 , & V_266 ) ;
if ( V_20 < 0 ) {
F_14 ( L_160
L_188 , V_20 ) ;
return V_20 ;
}
if ( V_266 > 0x0000ffff ) {
F_14 ( L_189
L_163 , V_266 ) ;
return - V_21 ;
}
V_20 = F_137 ( V_250 , ( T_6 ) V_266 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_190
L_191 ,
F_18 ( & V_267 -> V_29 ) ,
V_250 -> V_266 ) ;
return V_81 ;
}
static T_1 F_138 (
struct V_249 * V_250 ,
char * V_7 )
{
struct V_269 * V_270 ;
struct V_124 * V_271 ;
struct V_122 * V_123 ;
struct V_272 * V_273 ;
T_1 V_96 = 0 , V_244 ;
unsigned char V_85 [ V_274 ] ;
memset ( V_85 , 0 , V_274 ) ;
F_39 ( & V_250 -> V_275 ) ;
F_8 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_270 = V_273 -> V_276 ;
V_271 = V_270 -> V_277 ;
V_123 = V_270 -> V_278 ;
V_244 = snprintf ( V_85 , V_274 , L_192
L_193 , V_271 -> V_110 -> V_47 () ,
V_271 -> V_110 -> V_49 ( V_271 ) ,
V_271 -> V_110 -> V_50 ( V_271 ) ,
F_18 ( & V_123 -> V_279 . V_29 ) ) ;
V_244 ++ ;
if ( ( V_244 + V_96 ) > V_99 ) {
F_101 ( L_167
L_168 ) ;
break;
}
memcpy ( V_7 + V_96 , V_85 , V_244 ) ;
V_96 += V_244 ;
}
F_41 ( & V_250 -> V_275 ) ;
return V_96 ;
}
static void F_139 ( struct V_2 * V_3 )
{
struct V_249 * V_250 = F_2 ( F_3 ( V_3 ) ,
struct V_249 , V_268 ) ;
F_140 ( V_250 ) ;
}
static struct V_18 * F_141 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_211 * V_280 = F_2 ( V_19 , struct V_211 ,
V_281 ) ;
struct V_249 * V_250 ;
struct V_18 * V_267 = NULL ;
struct V_2 * V_282 = NULL ;
V_250 = F_142 ( V_280 -> V_84 , V_13 , 0 ) ;
if ( ! V_250 )
return NULL ;
V_267 = & V_250 -> V_268 ;
V_282 = & V_267 -> V_29 ;
F_16 ( V_267 , V_13 ,
& V_283 ) ;
F_12 ( L_194
L_195 ,
F_18 ( V_282 ) ) ;
return V_267 ;
}
static void F_143 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_249 * V_250 = F_2 ( F_3 ( V_3 ) ,
struct V_249 , V_268 ) ;
F_12 ( L_196
L_197 ,
F_18 ( V_3 ) , V_250 -> V_266 ) ;
F_20 ( V_3 ) ;
}
static struct V_18 * F_144 (
struct V_18 * V_19 ,
const char * V_13 )
{
return F_15 ( - V_100 ) ;
}
static void F_145 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
return;
}
static struct V_18 * F_146 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_249 * V_250 ;
struct V_177 * V_178 ;
struct V_2 * V_284 = & V_19 -> V_29 ;
struct V_1 * V_185 = F_1 ( V_284 ) ;
struct V_82 * V_83 ;
struct V_18 * V_237 = NULL , * V_285 = NULL ;
struct V_18 * V_286 = NULL ;
int V_287 = - V_40 , V_20 ;
V_20 = F_147 ( & V_185 -> V_288 ) ;
if ( V_20 )
return F_15 ( V_20 ) ;
V_178 = V_185 -> V_113 ;
V_83 = F_148 ( V_185 , V_13 ) ;
if ( ! V_83 )
goto V_125;
V_237 = & V_83 -> V_187 ;
V_237 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 6 ,
V_39 ) ;
if ( ! V_237 -> V_25 )
goto V_289;
F_16 ( V_237 , V_13 , & V_290 ) ;
F_16 ( & V_83 -> V_291 . V_292 , L_198 ,
& V_293 ) ;
F_16 ( & V_83 -> V_294 , L_199 ,
& V_295 ) ;
F_16 ( & V_83 -> V_79 . V_296 , L_200 ,
& V_297 ) ;
F_16 ( & V_83 -> V_211 . V_281 ,
L_201 , & V_298 ) ;
F_16 ( & V_83 -> V_299 . V_300 ,
L_202 , & V_301 ) ;
V_237 -> V_25 [ 0 ] = & V_83 -> V_291 . V_292 ;
V_237 -> V_25 [ 1 ] = & V_83 -> V_294 ;
V_237 -> V_25 [ 2 ] = & V_83 -> V_79 . V_296 ;
V_237 -> V_25 [ 3 ] = & V_83 -> V_211 . V_281 ;
V_237 -> V_25 [ 4 ] = & V_83 -> V_299 . V_300 ;
V_237 -> V_25 [ 5 ] = NULL ;
V_250 = F_142 ( V_83 , L_203 , 1 ) ;
if ( ! V_250 )
goto V_302;
V_83 -> V_211 . V_303 = V_250 ;
V_285 = & V_83 -> V_211 . V_281 ;
V_285 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 2 ,
V_39 ) ;
if ( ! V_285 -> V_25 ) {
F_14 ( L_204
L_205 ) ;
goto V_304;
}
F_16 ( & V_250 -> V_268 ,
L_203 , & V_283 ) ;
V_285 -> V_25 [ 0 ] = & V_250 -> V_268 ;
V_285 -> V_25 [ 1 ] = NULL ;
V_286 = & V_83 -> V_299 . V_300 ;
V_286 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 4 ,
V_39 ) ;
if ( ! V_286 -> V_25 ) {
F_14 ( L_206 ) ;
goto V_305;
}
F_150 ( V_83 ) ;
F_10 ( & V_185 -> V_288 ) ;
return V_237 ;
V_305:
F_29 ( V_285 -> V_25 ) ;
V_304:
F_140 ( V_250 ) ;
V_302:
F_29 ( V_237 -> V_25 ) ;
V_289:
F_93 ( V_83 ) ;
V_125:
F_10 ( & V_185 -> V_288 ) ;
return F_15 ( V_287 ) ;
}
static void F_151 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_18 * V_237 = F_3 ( V_3 ) ;
struct V_82 * V_83 =
F_2 ( V_237 , struct V_82 , V_187 ) ;
struct V_1 * V_185 ;
struct V_2 * V_34 ;
struct V_18 * V_285 , * V_286 ;
int V_35 ;
V_185 = F_1 ( & V_83 -> V_1 -> V_4 . V_29 ) ;
F_7 ( & V_185 -> V_288 ) ;
V_286 = & V_83 -> V_299 . V_300 ;
for ( V_35 = 0 ; V_286 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_34 = & V_286 -> V_25 [ V_35 ] -> V_29 ;
V_286 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_34 ) ;
}
F_29 ( V_286 -> V_25 ) ;
V_285 = & V_83 -> V_211 . V_281 ;
for ( V_35 = 0 ; V_285 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_34 = & V_285 -> V_25 [ V_35 ] -> V_29 ;
V_285 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_34 ) ;
}
F_29 ( V_285 -> V_25 ) ;
V_83 -> V_211 . V_303 = NULL ;
for ( V_35 = 0 ; V_237 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_34 = & V_237 -> V_25 [ V_35 ] -> V_29 ;
V_237 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_34 ) ;
}
F_20 ( V_3 ) ;
F_10 ( & V_185 -> V_288 ) ;
}
static T_1 F_152 (
struct V_1 * V_185 ,
char * V_7 )
{
return sprintf ( V_7 , L_207 ,
V_185 -> V_306 , V_185 -> V_113 -> V_13 ,
V_9 ) ;
}
static T_1 F_153 ( struct V_1 * V_185 ,
char * V_7 )
{
int V_307 = 0 ;
if ( V_185 -> V_308 & V_309 )
V_307 = 1 ;
return sprintf ( V_7 , L_132 , V_307 ) ;
}
static T_1 F_154 ( struct V_1 * V_185 ,
const char * V_7 , T_2 V_81 )
{
struct V_177 * V_113 = V_185 -> V_113 ;
unsigned long V_310 ;
int V_20 ;
if ( V_113 -> V_311 == NULL )
return - V_21 ;
V_20 = F_98 ( V_7 , 0 , & V_310 ) ;
if ( V_20 < 0 ) {
F_14 ( L_208 , V_20 ) ;
return V_20 ;
}
if ( V_185 -> V_312 ) {
F_14 ( L_209 ) ;
return - V_21 ;
}
V_20 = V_113 -> V_311 ( V_185 , V_310 ) ;
if ( V_20 < 0 )
return - V_21 ;
if ( V_20 > 0 )
V_185 -> V_308 |= V_309 ;
else if ( V_20 == 0 )
V_185 -> V_308 &= ~ V_309 ;
return V_81 ;
}
static void F_155 ( struct V_2 * V_3 )
{
struct V_1 * V_185 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_156 ( V_185 ) ;
}
static struct V_18 * F_157 (
struct V_18 * V_19 ,
const char * V_13 )
{
char * V_313 , * V_314 , * V_315 ;
struct V_1 * V_185 ;
char V_85 [ V_316 ] ;
unsigned long V_317 = 0 ;
int V_20 ;
memset ( V_85 , 0 , V_316 ) ;
if ( strlen ( V_13 ) >= V_316 ) {
F_14 ( L_210
L_211 , ( int ) strlen ( V_13 ) ,
V_316 ) ;
return F_15 ( - V_318 ) ;
}
snprintf ( V_85 , V_316 , L_29 , V_13 ) ;
V_314 = strstr ( V_85 , L_212 ) ;
if ( ! V_314 ) {
F_14 ( L_213 ) ;
return F_15 ( - V_21 ) ;
}
V_313 = V_85 ;
V_315 = strstr ( V_314 + 1 , L_212 ) ;
if ( V_315 ) {
* V_315 = '\0' ;
V_315 ++ ;
V_314 = V_315 ;
} else {
* V_314 = '\0' ;
V_314 ++ ;
}
V_20 = F_98 ( V_314 , 0 , & V_317 ) ;
if ( V_20 < 0 ) {
F_14 ( L_160
L_214 , V_20 ) ;
return F_15 ( V_20 ) ;
}
F_158 () ;
V_185 = F_159 ( V_313 , V_317 , 0 ) ;
if ( F_87 ( V_185 ) )
return F_160 ( V_185 ) ;
F_16 ( & V_185 -> V_4 , V_13 ,
& V_319 ) ;
return & V_185 -> V_4 ;
}
static void F_161 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
F_20 ( V_3 ) ;
}
static int T_8 F_162 ( void )
{
struct V_18 * V_320 , * V_321 = NULL , * V_322 = NULL ;
struct V_18 * V_323 = NULL ;
struct V_77 * V_324 ;
struct V_193 * V_194 ;
int V_20 ;
F_12 ( L_215
L_216 V_8 L_3 ,
V_325 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_324 = V_43 [ 0 ] ;
F_163 ( & V_324 -> V_326 ) ;
F_164 ( & V_324 -> V_327 ) ;
V_20 = F_165 () ;
if ( V_20 < 0 )
return V_20 ;
V_320 = & V_324 -> V_326 ;
V_320 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 2 ,
V_39 ) ;
if ( ! V_320 -> V_25 ) {
F_14 ( L_217 ) ;
V_20 = - V_40 ;
goto V_328;
}
F_16 ( & V_329 ,
L_218 , & V_330 ) ;
V_320 -> V_25 [ 0 ] = & V_329 ;
V_320 -> V_25 [ 1 ] = NULL ;
V_321 = & V_329 ;
V_321 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 2 ,
V_39 ) ;
if ( ! V_321 -> V_25 ) {
F_14 ( L_219 ) ;
V_20 = - V_40 ;
goto V_328;
}
F_16 ( & V_331 ,
L_201 , & V_332 ) ;
V_321 -> V_25 [ 0 ] = & V_331 ;
V_321 -> V_25 [ 1 ] = NULL ;
V_322 = & V_331 ;
V_322 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 2 ,
V_39 ) ;
if ( ! V_322 -> V_25 ) {
F_14 ( L_220 ) ;
V_20 = - V_40 ;
goto V_328;
}
F_16 ( & V_333 ,
L_221 , & V_334 ) ;
V_322 -> V_25 [ 0 ] = & V_333 ;
V_322 -> V_25 [ 1 ] = NULL ;
V_194 = F_105 ( L_222 , 1 ) ;
if ( F_87 ( V_194 ) ) {
V_20 = - V_40 ;
goto V_328;
}
V_323 = & V_333 ;
V_323 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 2 ,
V_39 ) ;
if ( ! V_323 -> V_25 ) {
F_14 ( L_223 ) ;
V_20 = - V_40 ;
goto V_328;
}
F_16 ( & V_194 -> V_199 , L_222 ,
& V_248 ) ;
V_323 -> V_25 [ 0 ] = & V_194 -> V_199 ;
V_323 -> V_25 [ 1 ] = NULL ;
V_335 = V_194 ;
V_20 = F_166 ( V_324 ) ;
if ( V_20 < 0 ) {
F_14 ( L_224 ,
V_20 , V_324 -> V_326 . V_29 . V_336 ) ;
goto V_328;
}
F_12 ( L_225
L_226 V_9 L_227
L_228 V_8 L_3 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_20 = F_167 () ;
if ( V_20 < 0 )
goto V_159;
V_20 = F_168 () ;
if ( V_20 < 0 )
goto V_159;
V_20 = F_169 () ;
if ( V_20 < 0 )
goto V_159;
return 0 ;
V_159:
F_170 ( V_324 ) ;
F_171 () ;
F_172 () ;
V_328:
if ( V_335 ) {
F_103 ( V_335 ) ;
V_335 = NULL ;
}
if ( V_323 )
F_29 ( V_323 -> V_25 ) ;
if ( V_322 )
F_29 ( V_322 -> V_25 ) ;
if ( V_321 )
F_29 ( V_321 -> V_25 ) ;
F_29 ( V_320 -> V_25 ) ;
F_173 () ;
return V_20 ;
}
static void T_9 F_174 ( void )
{
struct V_77 * V_324 ;
struct V_18 * V_321 , * V_322 , * V_323 ;
struct V_2 * V_3 ;
int V_35 ;
V_324 = V_43 [ 0 ] ;
V_323 = & V_333 ;
for ( V_35 = 0 ; V_323 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_3 = & V_323 -> V_25 [ V_35 ] -> V_29 ;
V_323 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_3 ) ;
}
F_29 ( V_323 -> V_25 ) ;
V_323 -> V_25 = NULL ;
V_322 = & V_331 ;
for ( V_35 = 0 ; V_322 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_3 = & V_322 -> V_25 [ V_35 ] -> V_29 ;
V_322 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_3 ) ;
}
F_29 ( V_322 -> V_25 ) ;
V_322 -> V_25 = NULL ;
V_321 = & V_329 ;
for ( V_35 = 0 ; V_321 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_3 = & V_321 -> V_25 [ V_35 ] -> V_29 ;
V_321 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_3 ) ;
}
F_29 ( V_321 -> V_25 ) ;
V_321 -> V_25 = NULL ;
F_170 ( V_324 ) ;
F_29 ( V_324 -> V_326 . V_25 ) ;
F_103 ( V_335 ) ;
V_335 = NULL ;
F_12 ( L_229
L_230 ) ;
F_171 () ;
F_172 () ;
F_175 () ;
F_173 () ;
}
