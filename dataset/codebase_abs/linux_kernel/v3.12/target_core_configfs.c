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
return sprintf ( V_7 , L_77 ,
& V_78 -> V_79 [ 0 ] ) ;
}
static T_1 F_37 (
struct V_78 * V_78 ,
const char * V_7 ,
T_2 V_80 )
{
struct V_81 * V_82 = V_78 -> V_83 ;
unsigned char V_84 [ V_85 ] ;
if ( V_82 -> V_86 & V_87 ) {
F_14 ( L_78
L_79 ) ;
return - V_88 ;
}
if ( strlen ( V_7 ) >= V_85 ) {
F_14 ( L_80
L_81 , V_85 ) ;
return - V_89 ;
}
if ( V_82 -> V_90 ) {
F_14 ( L_82
L_83 ,
V_82 -> V_90 ) ;
return - V_21 ;
}
memset ( V_84 , 0 , V_85 ) ;
snprintf ( V_84 , V_85 , L_29 , V_7 ) ;
snprintf ( V_82 -> V_78 . V_79 , V_85 ,
L_29 , F_38 ( V_84 ) ) ;
V_82 -> V_86 |= V_91 ;
F_12 ( L_84
L_5 , V_82 -> V_78 . V_79 ) ;
return V_80 ;
}
static T_1 F_39 (
struct V_78 * V_78 ,
char * V_7 )
{
struct V_92 * V_93 ;
unsigned char V_84 [ V_94 ] ;
T_1 V_95 = 0 ;
memset ( V_84 , 0 , V_94 ) ;
F_40 ( & V_78 -> V_96 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_93 -> V_97 )
continue;
F_41 ( V_93 , V_84 , V_94 ) ;
if ( V_95 + strlen ( V_84 ) >= V_98 )
break;
V_95 += sprintf ( V_7 + V_95 , L_29 , V_84 ) ;
}
F_42 ( & V_78 -> V_96 ) ;
return V_95 ;
}
static T_1 F_43 (
struct V_78 * V_78 ,
const char * V_7 ,
T_2 V_80 )
{
return - V_99 ;
}
static T_1 F_44 (
struct V_78 * V_78 ,
const char * V_7 ,
T_2 V_80 )
{
return - V_99 ;
}
static T_1 F_45 (
struct V_78 * V_78 ,
const char * V_7 ,
T_2 V_80 )
{
return - V_99 ;
}
static T_1 F_46 (
struct V_78 * V_78 ,
const char * V_7 ,
T_2 V_80 )
{
return - V_99 ;
}
static T_1 F_47 ( struct V_81 * V_82 ,
char * V_7 )
{
struct V_100 * V_101 ;
struct V_102 * V_103 ;
char V_104 [ V_105 ] ;
memset ( V_104 , 0 , V_105 ) ;
V_103 = V_82 -> V_106 ;
if ( ! V_103 )
return sprintf ( V_7 , L_85 ) ;
V_101 = V_103 -> V_107 ;
F_48 ( V_103 , V_104 , V_105 ) ;
return sprintf ( V_7 , L_86 ,
V_101 -> V_108 -> V_109 -> V_46 () ,
V_101 -> V_110 , V_104 ) ;
}
static T_1 F_49 ( struct V_81 * V_82 ,
char * V_7 )
{
struct V_100 * V_101 ;
T_1 V_95 ;
V_101 = V_82 -> V_111 ;
if ( V_101 ) {
V_95 = sprintf ( V_7 ,
L_87 ,
V_101 -> V_108 -> V_109 -> V_46 () ,
V_101 -> V_110 ) ;
} else {
V_95 = sprintf ( V_7 , L_88 ) ;
}
return V_95 ;
}
static T_1 F_50 ( struct V_81 * V_82 ,
char * V_7 )
{
int V_20 ;
if ( V_82 -> V_112 -> V_113 == V_114 )
return sprintf ( V_7 , L_89 ) ;
F_40 ( & V_82 -> V_115 ) ;
if ( V_82 -> V_116 & V_117 )
V_20 = F_49 ( V_82 , V_7 ) ;
else
V_20 = F_47 ( V_82 , V_7 ) ;
F_42 ( & V_82 -> V_115 ) ;
return V_20 ;
}
static T_1 F_51 (
struct V_81 * V_82 , char * V_7 )
{
T_1 V_95 = 0 ;
F_40 ( & V_82 -> V_115 ) ;
if ( ! V_82 -> V_106 ) {
V_95 = sprintf ( V_7 , L_85 ) ;
} else if ( V_82 -> V_106 -> V_118 ) {
V_95 = sprintf ( V_7 , L_90
L_91 ) ;
} else {
V_95 = sprintf ( V_7 , L_92
L_93 ) ;
}
F_42 ( & V_82 -> V_115 ) ;
return V_95 ;
}
static T_1 F_52 (
struct V_81 * V_82 , char * V_7 )
{
return sprintf ( V_7 , L_94 , V_82 -> V_119 . V_120 ) ;
}
static T_1 F_53 (
struct V_81 * V_82 , char * V_7 )
{
struct V_100 * V_101 ;
struct V_121 * V_122 ;
struct V_123 * V_108 ;
struct V_102 * V_103 ;
struct V_44 * V_45 ;
T_1 V_95 = 0 ;
F_40 ( & V_82 -> V_115 ) ;
V_103 = V_82 -> V_106 ;
if ( ! V_103 ) {
V_95 = sprintf ( V_7 , L_85 ) ;
goto V_124;
}
V_101 = V_103 -> V_107 ;
V_108 = V_101 -> V_108 ;
V_122 = V_103 -> V_125 ;
V_45 = V_108 -> V_109 ;
V_95 += sprintf ( V_7 + V_95 , L_95
L_96 , V_45 -> V_46 () ,
V_45 -> V_48 ( V_108 ) ) ;
V_95 += sprintf ( V_7 + V_95 , L_97
L_98
L_99 , V_122 -> V_126 -> V_127 ,
V_45 -> V_46 () , V_45 -> V_49 ( V_108 ) ,
V_45 -> V_46 () , V_122 -> V_128 ) ;
V_124:
F_42 ( & V_82 -> V_115 ) ;
return V_95 ;
}
static T_1 F_54 (
struct V_81 * V_82 , char * V_7 )
{
struct V_44 * V_45 ;
struct V_102 * V_103 ;
unsigned char V_84 [ 384 ] ;
char V_104 [ V_105 ] ;
T_1 V_95 = 0 ;
int V_129 = 0 ;
V_95 += sprintf ( V_7 + V_95 , L_100 ) ;
F_40 ( & V_82 -> V_119 . V_130 ) ;
F_8 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_84 , 0 , 384 ) ;
memset ( V_104 , 0 , V_105 ) ;
V_45 = V_103 -> V_107 -> V_108 -> V_109 ;
F_48 ( V_103 , V_104 ,
V_105 ) ;
sprintf ( V_84 , L_101 ,
V_45 -> V_46 () ,
V_103 -> V_107 -> V_110 , V_104 , V_103 -> V_131 ,
V_103 -> V_132 ) ;
if ( V_95 + strlen ( V_84 ) >= V_98 )
break;
V_95 += sprintf ( V_7 + V_95 , L_29 , V_84 ) ;
V_129 ++ ;
}
F_42 ( & V_82 -> V_119 . V_130 ) ;
if ( ! V_129 )
V_95 += sprintf ( V_7 + V_95 , L_102 ) ;
return V_95 ;
}
static T_1 F_55 (
struct V_81 * V_82 , char * V_7 )
{
struct V_102 * V_103 ;
T_1 V_95 = 0 ;
F_40 ( & V_82 -> V_115 ) ;
V_103 = V_82 -> V_106 ;
if ( V_103 ) {
V_95 = sprintf ( V_7 , L_103 ,
F_56 ( V_103 -> V_133 ) ) ;
} else {
V_95 = sprintf ( V_7 , L_85 ) ;
}
F_42 ( & V_82 -> V_115 ) ;
return V_95 ;
}
static T_1 F_57 (
struct V_81 * V_82 , char * V_7 )
{
if ( V_82 -> V_112 -> V_113 == V_114 )
return sprintf ( V_7 , L_104 ) ;
else if ( V_82 -> V_116 & V_117 )
return sprintf ( V_7 , L_105 ) ;
else
return sprintf ( V_7 , L_106 ) ;
}
static T_1 F_58 (
struct V_81 * V_82 , char * V_7 )
{
if ( V_82 -> V_112 -> V_113 == V_114 )
return 0 ;
return sprintf ( V_7 , L_107 ,
( V_82 -> V_119 . V_134 ) ? L_108 : L_109 ) ;
}
static T_1 F_59 (
struct V_81 * V_82 , char * V_7 )
{
if ( V_82 -> V_112 -> V_113 == V_114 )
return 0 ;
return sprintf ( V_7 , L_110 ) ;
}
static T_1 F_60 (
struct V_81 * V_82 ,
const char * V_7 ,
T_2 V_80 )
{
unsigned char * V_135 = NULL , * V_136 = NULL , * V_137 = NULL ;
unsigned char * V_138 = NULL , * V_139 = NULL ;
char * V_140 , * V_141 , * V_142 , * V_143 ;
T_3 args [ V_144 ] ;
unsigned long long V_145 ;
T_4 V_146 = 0 ;
T_5 V_147 = 0 , V_148 = 0 ;
int V_20 = - 1 , V_149 = 0 , V_150 = 0 , V_151 , V_152 ;
T_6 V_153 = 0 , V_154 = 0 ;
T_7 type = 0 , V_155 ;
if ( V_82 -> V_112 -> V_113 == V_114 )
return 0 ;
if ( V_82 -> V_116 & V_117 )
return 0 ;
if ( V_82 -> V_90 ) {
F_12 ( L_111
L_112 ) ;
return - V_21 ;
}
V_143 = F_61 ( V_7 , V_38 ) ;
if ( ! V_143 )
return - V_39 ;
V_140 = V_143 ;
while ( ( V_141 = F_62 ( & V_143 , L_113 ) ) != NULL ) {
if ( ! * V_141 )
continue;
V_152 = F_63 ( V_141 , V_156 , args ) ;
switch ( V_152 ) {
case V_157 :
V_135 = F_64 ( & args [ 0 ] ) ;
if ( ! V_135 ) {
V_20 = - V_39 ;
goto V_158;
}
break;
case V_159 :
V_136 = F_64 ( & args [ 0 ] ) ;
if ( ! V_136 ) {
V_20 = - V_39 ;
goto V_158;
}
if ( strlen ( V_136 ) >= V_160 ) {
F_14 ( L_114
L_115 ,
V_160 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_161 :
V_137 = F_64 ( & args [ 0 ] ) ;
if ( ! V_137 ) {
V_20 = - V_39 ;
goto V_158;
}
if ( strlen ( V_137 ) >= V_162 ) {
F_14 ( L_116
L_117 ,
V_162 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_163 :
V_142 = F_64 ( & args [ 0 ] ) ;
if ( ! V_142 ) {
V_20 = - V_39 ;
goto V_158;
}
V_20 = F_65 ( V_142 , 0 , & V_145 ) ;
if ( V_20 < 0 ) {
F_14 ( L_118
L_119 ) ;
goto V_158;
}
V_146 = ( T_4 ) V_145 ;
break;
case V_164 :
F_66 ( args , & V_151 ) ;
V_149 = V_151 ;
break;
case V_165 :
F_66 ( args , & V_151 ) ;
type = ( T_7 ) V_151 ;
break;
case V_166 :
F_66 ( args , & V_151 ) ;
V_155 = ( T_7 ) V_151 ;
break;
case V_167 :
F_66 ( args , & V_151 ) ;
V_150 = ( int ) V_151 ;
break;
case V_168 :
F_66 ( args , & V_151 ) ;
V_147 = ( T_5 ) V_151 ;
break;
case V_169 :
V_138 = F_64 ( & args [ 0 ] ) ;
if ( ! V_138 ) {
V_20 = - V_39 ;
goto V_158;
}
break;
case V_170 :
V_139 = F_64 ( & args [ 0 ] ) ;
if ( ! V_139 ) {
V_20 = - V_39 ;
goto V_158;
}
if ( strlen ( V_139 ) >= V_171 ) {
F_14 ( L_120
L_121 ,
V_171 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_172 :
F_66 ( args , & V_151 ) ;
V_154 = ( T_6 ) V_151 ;
break;
case V_173 :
F_66 ( args , & V_151 ) ;
V_153 = ( T_6 ) V_151 ;
break;
case V_174 :
F_66 ( args , & V_151 ) ;
V_148 = ( T_5 ) V_151 ;
break;
default:
break;
}
}
if ( ! V_136 || ! V_139 || ! V_146 ) {
F_14 ( L_122 ) ;
V_20 = - V_21 ;
goto V_158;
}
if ( V_149 && ! ( type ) ) {
F_14 ( L_123
L_124 , type ) ;
V_20 = - V_21 ;
goto V_158;
}
V_20 = F_67 ( & V_82 -> V_119 , V_146 ,
V_136 , V_137 , V_147 , V_139 , V_154 , V_148 ,
V_149 , V_150 , type ) ;
V_158:
F_30 ( V_135 ) ;
F_30 ( V_136 ) ;
F_30 ( V_137 ) ;
F_30 ( V_138 ) ;
F_30 ( V_139 ) ;
F_30 ( V_140 ) ;
return ( V_20 == 0 ) ? V_80 : V_20 ;
}
static T_1 F_68 ( void * V_175 , char * V_7 )
{
struct V_81 * V_82 = V_175 ;
struct V_176 * V_177 = V_82 -> V_112 ;
int V_178 = 0 ;
T_1 V_179 = 0 ;
F_69 ( V_82 , V_7 , & V_178 ) ;
V_179 += V_178 ;
V_179 += V_177 -> V_180 ( V_82 , V_7 + V_179 ) ;
return V_179 ;
}
static T_1 F_70 (
void * V_175 ,
const char * V_7 ,
T_2 V_80 )
{
struct V_81 * V_82 = V_175 ;
struct V_176 * V_177 = V_82 -> V_112 ;
return V_177 -> V_181 ( V_82 , V_7 , V_80 ) ;
}
static T_1 F_71 ( void * V_175 , char * V_7 )
{
struct V_81 * V_82 = V_175 ;
if ( ! ( V_82 -> V_86 & V_182 ) )
return 0 ;
return snprintf ( V_7 , V_98 , L_125 , V_82 -> V_183 ) ;
}
static T_1 F_72 (
void * V_175 ,
const char * V_7 ,
T_2 V_80 )
{
struct V_81 * V_82 = V_175 ;
struct V_1 * V_184 = V_82 -> V_1 ;
T_1 V_179 ;
if ( V_80 > ( V_185 - 1 ) ) {
F_14 ( L_126
L_127 , ( int ) V_80 ,
V_185 - 1 ) ;
return - V_21 ;
}
V_179 = snprintf ( & V_82 -> V_183 [ 0 ] , V_185 , L_29 , V_7 ) ;
if ( ! V_179 )
return - V_21 ;
if ( V_82 -> V_183 [ V_179 - 1 ] == '\n' )
V_82 -> V_183 [ V_179 - 1 ] = '\0' ;
V_82 -> V_86 |= V_182 ;
F_12 ( L_128 ,
F_19 ( & V_184 -> V_4 . V_28 ) ,
F_19 ( & V_82 -> V_186 . V_28 ) ,
V_82 -> V_183 ) ;
return V_179 ;
}
static T_1 F_73 ( void * V_175 , char * V_7 )
{
struct V_81 * V_82 = V_175 ;
if ( ! ( V_82 -> V_86 & V_187 ) )
return 0 ;
return snprintf ( V_7 , V_98 , L_125 , V_82 -> V_188 ) ;
}
static T_1 F_74 (
void * V_175 ,
const char * V_7 ,
T_2 V_80 )
{
struct V_81 * V_82 = V_175 ;
struct V_1 * V_184 = V_82 -> V_1 ;
T_1 V_179 ;
if ( V_80 > ( V_189 - 1 ) ) {
F_14 ( L_129
L_130 , ( int ) V_80 ,
V_189 - 1 ) ;
return - V_21 ;
}
V_179 = snprintf ( & V_82 -> V_188 [ 0 ] , V_189 ,
L_29 , V_7 ) ;
if ( ! V_179 )
return - V_21 ;
if ( V_82 -> V_188 [ V_179 - 1 ] == '\n' )
V_82 -> V_188 [ V_179 - 1 ] = '\0' ;
V_82 -> V_86 |= V_187 ;
F_12 ( L_131 ,
F_19 ( & V_184 -> V_4 . V_28 ) ,
F_19 ( & V_82 -> V_186 . V_28 ) ,
V_82 -> V_188 ) ;
return V_179 ;
}
static T_1 F_75 ( void * V_175 , char * V_7 )
{
struct V_81 * V_82 = V_175 ;
return snprintf ( V_7 , V_98 , L_132 , ! ! ( V_82 -> V_86 & V_190 ) ) ;
}
static T_1 F_76 (
void * V_175 ,
const char * V_7 ,
T_2 V_80 )
{
struct V_81 * V_82 = V_175 ;
char * V_141 ;
int V_20 ;
V_141 = strstr ( V_7 , L_133 ) ;
if ( ! V_141 ) {
F_14 ( L_134
L_135 ) ;
return - V_21 ;
}
V_20 = F_77 ( V_82 ) ;
if ( V_20 )
return V_20 ;
return V_80 ;
}
static T_1 F_78 ( void * V_175 , char * V_7 )
{
struct V_81 * V_82 = V_175 ;
struct V_2 * V_191 ;
struct V_192 * V_193 ;
struct V_194 * V_195 ;
T_1 V_95 = 0 ;
V_195 = V_82 -> V_196 ;
if ( ! V_195 )
return 0 ;
F_40 ( & V_195 -> V_197 ) ;
V_193 = V_195 -> V_193 ;
if ( V_193 ) {
V_191 = & V_193 -> V_198 . V_28 ;
V_95 += sprintf ( V_7 , L_136 ,
F_19 ( V_191 ) , V_193 -> V_199 ) ;
}
F_42 ( & V_195 -> V_197 ) ;
return V_95 ;
}
static T_1 F_79 (
void * V_175 ,
const char * V_7 ,
T_2 V_80 )
{
struct V_81 * V_82 = V_175 ;
struct V_1 * V_184 = V_82 -> V_1 ;
struct V_192 * V_193 = NULL , * V_200 = NULL ;
struct V_194 * V_195 ;
unsigned char V_84 [ V_201 ] ;
int V_202 = 0 ;
V_195 = V_82 -> V_196 ;
if ( ! V_195 )
return 0 ;
if ( V_80 > V_201 ) {
F_14 ( L_137 ) ;
return - V_21 ;
}
memset ( V_84 , 0 , V_201 ) ;
memcpy ( V_84 , V_7 , V_80 ) ;
if ( strcmp ( F_38 ( V_84 ) , L_138 ) ) {
V_200 = F_80 ( F_38 ( V_84 ) ) ;
if ( ! V_200 )
return - V_203 ;
}
F_40 ( & V_195 -> V_197 ) ;
V_193 = V_195 -> V_193 ;
if ( V_193 ) {
if ( ! V_200 ) {
F_12 ( L_139
L_140
L_141 ,
F_19 ( & V_184 -> V_4 . V_28 ) ,
F_19 ( & V_82 -> V_186 . V_28 ) ,
F_19 ( & V_193 -> V_198 . V_28 ) ,
V_193 -> V_199 ) ;
F_81 ( V_195 , V_193 ) ;
F_42 ( & V_195 -> V_197 ) ;
return V_80 ;
}
F_81 ( V_195 , V_193 ) ;
V_202 = 1 ;
}
F_82 ( V_195 , V_200 ) ;
F_42 ( & V_195 -> V_197 ) ;
F_12 ( L_142
L_143 ,
( V_202 ) ? L_144 : L_145 ,
F_19 ( & V_184 -> V_4 . V_28 ) ,
F_19 ( & V_82 -> V_186 . V_28 ) ,
F_19 ( & V_200 -> V_198 . V_28 ) ,
V_200 -> V_199 ) ;
F_83 ( V_200 ) ;
return V_80 ;
}
static void F_84 ( struct V_2 * V_3 )
{
struct V_18 * V_204 = F_3 ( V_3 ) ;
struct V_81 * V_82 =
F_2 ( V_204 , struct V_81 , V_186 ) ;
F_30 ( V_204 -> V_24 ) ;
F_85 ( V_82 ) ;
}
static T_1 F_86 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
char * V_7 )
{
struct V_18 * V_204 = F_3 ( V_3 ) ;
struct V_81 * V_82 =
F_2 ( V_204 , struct V_81 , V_186 ) ;
struct V_205 * V_206 = F_2 (
V_6 , struct V_205 , V_6 ) ;
if ( ! V_206 -> V_207 )
return - V_21 ;
return V_206 -> V_207 ( V_82 , V_7 ) ;
}
static T_1 F_87 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
const char * V_7 , T_2 V_80 )
{
struct V_18 * V_204 = F_3 ( V_3 ) ;
struct V_81 * V_82 =
F_2 ( V_204 , struct V_81 , V_186 ) ;
struct V_205 * V_206 = F_2 (
V_6 , struct V_205 , V_6 ) ;
if ( ! V_206 -> V_208 )
return - V_21 ;
return V_206 -> V_208 ( V_82 , V_7 , V_80 ) ;
}
static T_1 F_88 (
struct V_192 * V_193 ,
char * V_7 )
{
if ( ! V_193 -> V_209 )
return 0 ;
return sprintf ( V_7 , L_146 , V_193 -> V_199 ) ;
}
static T_1 F_89 (
struct V_192 * V_193 ,
const char * V_7 ,
T_2 V_80 )
{
struct V_18 * V_210 = & V_193 -> V_198 ;
unsigned long V_199 ;
int V_20 ;
V_20 = F_90 ( V_7 , 0 , & V_199 ) ;
if ( V_20 < 0 ) {
F_14 ( L_147
L_148 , V_20 ) ;
return V_20 ;
}
if ( V_199 > 0x0000ffff ) {
F_14 ( L_149
L_150 , V_199 ) ;
return - V_21 ;
}
V_20 = F_91 ( V_193 , ( T_6 ) V_199 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_151
L_152 ,
F_19 ( & V_210 -> V_28 ) ,
V_193 -> V_199 ) ;
return V_80 ;
}
static T_1 F_92 (
struct V_192 * V_193 ,
char * V_7 )
{
struct V_81 * V_82 ;
struct V_1 * V_184 ;
struct V_194 * V_195 ;
T_1 V_95 = 0 , V_211 ;
unsigned char V_84 [ V_201 ] ;
memset ( V_84 , 0 , V_201 ) ;
F_40 ( & V_193 -> V_212 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_82 = V_195 -> V_213 ;
V_184 = V_82 -> V_1 ;
V_211 = snprintf ( V_84 , V_201 , L_153 ,
F_19 ( & V_184 -> V_4 . V_28 ) ,
F_19 ( & V_82 -> V_186 . V_28 ) ) ;
V_211 ++ ;
if ( ( V_211 + V_95 ) > V_98 ) {
F_93 ( L_154
L_155 ) ;
break;
}
memcpy ( V_7 + V_95 , V_84 , V_211 ) ;
V_95 += V_211 ;
}
F_42 ( & V_193 -> V_212 ) ;
return V_95 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_192 * V_193 = F_2 ( F_3 ( V_3 ) ,
struct V_192 , V_198 ) ;
F_95 ( V_193 ) ;
}
static struct V_18 * F_96 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_192 * V_193 ;
struct V_18 * V_210 = NULL ;
struct V_2 * V_214 = NULL ;
V_193 = F_97 ( V_13 , 0 ) ;
if ( F_98 ( V_193 ) )
return NULL ;
V_210 = & V_193 -> V_198 ;
V_214 = & V_210 -> V_28 ;
F_17 ( V_210 , V_13 ,
& V_215 ) ;
F_12 ( L_156
L_157 ,
F_19 ( V_214 ) ) ;
return V_210 ;
}
static void F_99 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_192 * V_193 = F_2 ( F_3 ( V_3 ) ,
struct V_192 , V_198 ) ;
F_12 ( L_158
L_159 ,
F_19 ( V_3 ) , V_193 -> V_199 ) ;
F_21 ( V_3 ) ;
}
static T_1 F_100 (
struct V_216 * V_217 ,
char * V_7 )
{
return sprintf ( V_7 , L_132 ,
F_34 ( & V_217 -> V_218 ) ) ;
}
static T_1 F_101 (
struct V_216 * V_217 ,
const char * V_7 ,
T_2 V_80 )
{
struct V_81 * V_82 = V_217 -> V_219 ;
unsigned long V_220 ;
int V_221 , V_20 ;
if ( ! V_217 -> V_222 ) {
F_14 ( L_160
L_161 , V_217 -> V_222 ) ;
return - V_21 ;
}
V_20 = F_90 ( V_7 , 0 , & V_220 ) ;
if ( V_20 < 0 ) {
F_14 ( L_162
L_5 , V_7 ) ;
return V_20 ;
}
V_221 = ( int ) V_220 ;
if ( ! ( V_217 -> V_223 & V_224 ) ) {
F_14 ( L_163
L_164 ) ;
return - V_21 ;
}
V_20 = F_102 ( V_217 , V_82 ,
NULL , NULL , V_221 , 0 ) ;
return ( ! V_20 ) ? V_80 : - V_21 ;
}
static T_1 F_103 (
struct V_216 * V_217 ,
char * V_7 )
{
return sprintf ( V_7 , L_125 ,
F_104 ( V_217 -> V_225 ) ) ;
}
static T_1 F_105 (
struct V_216 * V_217 ,
const char * V_7 ,
T_2 V_80 )
{
unsigned long V_220 ;
int V_226 , V_20 ;
if ( ! V_217 -> V_222 ) {
F_14 ( L_165
L_166 ,
V_217 -> V_222 ) ;
return - V_21 ;
}
V_20 = F_90 ( V_7 , 0 , & V_220 ) ;
if ( V_20 < 0 ) {
F_14 ( L_167
L_168 , V_7 ) ;
return V_20 ;
}
V_226 = ( int ) V_220 ;
if ( ( V_226 != V_227 ) &&
( V_226 != V_228 ) &&
( V_226 != V_229 ) ) {
F_14 ( L_169 ,
V_226 ) ;
return - V_21 ;
}
V_217 -> V_225 = V_226 ;
return V_80 ;
}
static T_1 F_106 (
struct V_216 * V_217 ,
char * V_7 )
{
return F_107 ( V_217 , V_7 ) ;
}
static T_1 F_108 (
struct V_216 * V_217 ,
const char * V_7 ,
T_2 V_80 )
{
return F_109 ( V_217 , V_7 , V_80 ) ;
}
static T_1 F_110 (
struct V_216 * V_217 ,
char * V_7 )
{
return sprintf ( V_7 , L_132 , V_217 -> V_230 ) ;
}
static T_1 F_111 (
struct V_216 * V_217 ,
const char * V_7 ,
T_2 V_80 )
{
unsigned long V_220 ;
int V_20 ;
V_20 = F_90 ( V_7 , 0 , & V_220 ) ;
if ( V_20 < 0 ) {
F_14 ( L_170 ) ;
return V_20 ;
}
if ( ( V_220 != 0 ) && ( V_220 != 1 ) ) {
F_14 ( L_171
L_172 , V_220 ) ;
return - V_21 ;
}
V_217 -> V_230 = ( int ) V_220 ;
return V_80 ;
}
static T_1 F_112 (
struct V_216 * V_217 ,
char * V_7 )
{
return F_113 ( V_217 , V_7 ) ;
}
static T_1 F_114 (
struct V_216 * V_217 ,
const char * V_7 ,
T_2 V_80 )
{
return F_115 ( V_217 , V_7 , V_80 ) ;
}
static T_1 F_116 (
struct V_216 * V_217 ,
char * V_7 )
{
return F_117 ( V_217 , V_7 ) ;
}
static T_1 F_118 (
struct V_216 * V_217 ,
const char * V_7 ,
T_2 V_80 )
{
return F_119 ( V_217 , V_7 , V_80 ) ;
}
static T_1 F_120 (
struct V_216 * V_217 ,
char * V_7 )
{
return F_121 ( V_217 , V_7 ) ;
}
static T_1 F_122 (
struct V_216 * V_217 ,
const char * V_7 ,
T_2 V_80 )
{
return F_123 ( V_217 , V_7 , V_80 ) ;
}
static T_1 F_124 (
struct V_216 * V_217 ,
char * V_7 )
{
return F_125 ( V_217 , V_7 ) ;
}
static T_1 F_126 (
struct V_216 * V_217 ,
const char * V_7 ,
T_2 V_80 )
{
return F_127 ( V_217 , V_7 , V_80 ) ;
}
static T_1 F_128 (
struct V_216 * V_217 ,
char * V_7 )
{
if ( ! V_217 -> V_222 )
return 0 ;
return sprintf ( V_7 , L_146 , V_217 -> V_231 ) ;
}
static T_1 F_129 (
struct V_216 * V_217 ,
const char * V_7 ,
T_2 V_80 )
{
struct V_18 * V_232 = & V_217 -> V_233 ;
unsigned long V_231 ;
int V_20 ;
V_20 = F_90 ( V_7 , 0 , & V_231 ) ;
if ( V_20 < 0 ) {
F_14 ( L_147
L_173 , V_20 ) ;
return V_20 ;
}
if ( V_231 > 0x0000ffff ) {
F_14 ( L_174
L_150 , V_231 ) ;
return - V_21 ;
}
V_20 = F_130 ( V_217 , ( T_6 ) V_231 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_175
L_176 ,
F_19 ( & V_232 -> V_28 ) ,
V_217 -> V_231 ) ;
return V_80 ;
}
static T_1 F_131 (
struct V_216 * V_217 ,
char * V_7 )
{
struct V_234 * V_235 ;
struct V_123 * V_236 ;
struct V_121 * V_122 ;
struct V_237 * V_238 ;
T_1 V_95 = 0 , V_211 ;
unsigned char V_84 [ V_239 ] ;
memset ( V_84 , 0 , V_239 ) ;
F_40 ( & V_217 -> V_240 ) ;
F_8 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_235 = V_238 -> V_241 ;
V_236 = V_235 -> V_242 ;
V_122 = V_235 -> V_243 ;
V_211 = snprintf ( V_84 , V_239 , L_177
L_178 , V_236 -> V_109 -> V_46 () ,
V_236 -> V_109 -> V_48 ( V_236 ) ,
V_236 -> V_109 -> V_49 ( V_236 ) ,
F_19 ( & V_122 -> V_244 . V_28 ) ) ;
V_211 ++ ;
if ( ( V_211 + V_95 ) > V_98 ) {
F_93 ( L_154
L_155 ) ;
break;
}
memcpy ( V_7 + V_95 , V_84 , V_211 ) ;
V_95 += V_211 ;
}
F_42 ( & V_217 -> V_240 ) ;
return V_95 ;
}
static void F_132 ( struct V_2 * V_3 )
{
struct V_216 * V_217 = F_2 ( F_3 ( V_3 ) ,
struct V_216 , V_233 ) ;
F_133 ( V_217 ) ;
}
static struct V_18 * F_134 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_245 * V_246 = F_2 ( V_19 , struct V_245 ,
V_247 ) ;
struct V_216 * V_217 ;
struct V_18 * V_232 = NULL ;
struct V_2 * V_248 = NULL ;
V_217 = F_135 ( V_246 -> V_83 , V_13 , 0 ) ;
if ( ! V_217 )
return NULL ;
V_232 = & V_217 -> V_233 ;
V_248 = & V_232 -> V_28 ;
F_17 ( V_232 , V_13 ,
& V_249 ) ;
F_12 ( L_179
L_180 ,
F_19 ( V_248 ) ) ;
return V_232 ;
}
static void F_136 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_216 * V_217 = F_2 ( F_3 ( V_3 ) ,
struct V_216 , V_233 ) ;
F_12 ( L_181
L_182 ,
F_19 ( V_3 ) , V_217 -> V_231 ) ;
F_21 ( V_3 ) ;
}
static struct V_18 * F_137 (
struct V_18 * V_19 ,
const char * V_13 )
{
return F_15 ( - V_99 ) ;
}
static void F_138 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
return;
}
static struct V_18 * F_139 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_216 * V_217 ;
struct V_176 * V_177 ;
struct V_2 * V_250 = & V_19 -> V_28 ;
struct V_1 * V_184 = F_1 ( V_250 ) ;
struct V_81 * V_82 ;
struct V_18 * V_204 = NULL , * V_251 = NULL ;
struct V_18 * V_252 = NULL ;
int V_253 = - V_39 , V_20 ;
V_20 = F_140 ( & V_184 -> V_254 ) ;
if ( V_20 )
return F_15 ( V_20 ) ;
V_177 = V_184 -> V_112 ;
V_82 = F_141 ( V_184 , V_13 ) ;
if ( ! V_82 )
goto V_124;
V_204 = & V_82 -> V_186 ;
V_204 -> V_24 = F_142 ( sizeof( struct V_18 * ) * 6 ,
V_38 ) ;
if ( ! V_204 -> V_24 )
goto V_255;
F_17 ( V_204 , V_13 , & V_256 ) ;
F_17 ( & V_82 -> V_257 . V_258 , L_183 ,
& V_259 ) ;
F_17 ( & V_82 -> V_260 , L_184 ,
& V_261 ) ;
F_17 ( & V_82 -> V_78 . V_262 , L_185 ,
& V_263 ) ;
F_17 ( & V_82 -> V_245 . V_247 ,
L_186 , & V_264 ) ;
F_17 ( & V_82 -> V_265 . V_266 ,
L_187 , & V_267 ) ;
V_204 -> V_24 [ 0 ] = & V_82 -> V_257 . V_258 ;
V_204 -> V_24 [ 1 ] = & V_82 -> V_260 ;
V_204 -> V_24 [ 2 ] = & V_82 -> V_78 . V_262 ;
V_204 -> V_24 [ 3 ] = & V_82 -> V_245 . V_247 ;
V_204 -> V_24 [ 4 ] = & V_82 -> V_265 . V_266 ;
V_204 -> V_24 [ 5 ] = NULL ;
V_217 = F_135 ( V_82 , L_188 , 1 ) ;
if ( ! V_217 )
goto V_268;
V_82 -> V_245 . V_269 = V_217 ;
V_251 = & V_82 -> V_245 . V_247 ;
V_251 -> V_24 = F_142 ( sizeof( struct V_18 * ) * 2 ,
V_38 ) ;
if ( ! V_251 -> V_24 ) {
F_14 ( L_189
L_190 ) ;
goto V_270;
}
F_17 ( & V_217 -> V_233 ,
L_188 , & V_249 ) ;
V_251 -> V_24 [ 0 ] = & V_217 -> V_233 ;
V_251 -> V_24 [ 1 ] = NULL ;
V_252 = & V_82 -> V_265 . V_266 ;
V_252 -> V_24 = F_142 ( sizeof( struct V_18 * ) * 4 ,
V_38 ) ;
if ( ! V_252 -> V_24 ) {
F_14 ( L_191 ) ;
goto V_271;
}
F_143 ( V_82 ) ;
F_10 ( & V_184 -> V_254 ) ;
return V_204 ;
V_271:
F_30 ( V_251 -> V_24 ) ;
V_270:
F_133 ( V_217 ) ;
V_268:
F_30 ( V_204 -> V_24 ) ;
V_255:
F_85 ( V_82 ) ;
V_124:
F_10 ( & V_184 -> V_254 ) ;
return F_15 ( V_253 ) ;
}
static void F_144 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_18 * V_204 = F_3 ( V_3 ) ;
struct V_81 * V_82 =
F_2 ( V_204 , struct V_81 , V_186 ) ;
struct V_1 * V_184 ;
struct V_2 * V_33 ;
struct V_18 * V_251 , * V_252 ;
int V_34 ;
V_184 = F_1 ( & V_82 -> V_1 -> V_4 . V_28 ) ;
F_7 ( & V_184 -> V_254 ) ;
V_252 = & V_82 -> V_265 . V_266 ;
for ( V_34 = 0 ; V_252 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_252 -> V_24 [ V_34 ] -> V_28 ;
V_252 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_30 ( V_252 -> V_24 ) ;
V_251 = & V_82 -> V_245 . V_247 ;
for ( V_34 = 0 ; V_251 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_251 -> V_24 [ V_34 ] -> V_28 ;
V_251 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_30 ( V_251 -> V_24 ) ;
V_82 -> V_245 . V_269 = NULL ;
for ( V_34 = 0 ; V_204 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_33 = & V_204 -> V_24 [ V_34 ] -> V_28 ;
V_204 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_33 ) ;
}
F_21 ( V_3 ) ;
F_10 ( & V_184 -> V_254 ) ;
}
static T_1 F_145 (
struct V_1 * V_184 ,
char * V_7 )
{
return sprintf ( V_7 , L_192 ,
V_184 -> V_272 , V_184 -> V_112 -> V_13 ,
V_9 ) ;
}
static T_1 F_146 ( struct V_1 * V_184 ,
char * V_7 )
{
int V_273 = 0 ;
if ( V_184 -> V_274 & V_275 )
V_273 = 1 ;
return sprintf ( V_7 , L_132 , V_273 ) ;
}
static T_1 F_147 ( struct V_1 * V_184 ,
const char * V_7 , T_2 V_80 )
{
struct V_176 * V_112 = V_184 -> V_112 ;
unsigned long V_276 ;
int V_20 ;
if ( V_112 -> V_277 == NULL )
return - V_21 ;
V_20 = F_90 ( V_7 , 0 , & V_276 ) ;
if ( V_20 < 0 ) {
F_14 ( L_193 , V_20 ) ;
return V_20 ;
}
if ( V_184 -> V_278 ) {
F_14 ( L_194 ) ;
return - V_21 ;
}
V_20 = V_112 -> V_277 ( V_184 , V_276 ) ;
if ( V_20 < 0 )
return - V_21 ;
if ( V_20 > 0 )
V_184 -> V_274 |= V_275 ;
else if ( V_20 == 0 )
V_184 -> V_274 &= ~ V_275 ;
return V_80 ;
}
static void F_148 ( struct V_2 * V_3 )
{
struct V_1 * V_184 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_149 ( V_184 ) ;
}
static struct V_18 * F_150 (
struct V_18 * V_19 ,
const char * V_13 )
{
char * V_279 , * V_280 , * V_281 ;
struct V_1 * V_184 ;
char V_84 [ V_282 ] ;
unsigned long V_283 = 0 ;
int V_20 ;
memset ( V_84 , 0 , V_282 ) ;
if ( strlen ( V_13 ) >= V_282 ) {
F_14 ( L_195
L_196 , ( int ) strlen ( V_13 ) ,
V_282 ) ;
return F_15 ( - V_284 ) ;
}
snprintf ( V_84 , V_282 , L_29 , V_13 ) ;
V_280 = strstr ( V_84 , L_197 ) ;
if ( ! V_280 ) {
F_14 ( L_198 ) ;
return F_15 ( - V_21 ) ;
}
V_279 = V_84 ;
V_281 = strstr ( V_280 + 1 , L_197 ) ;
if ( V_281 ) {
* V_281 = '\0' ;
V_281 ++ ;
V_280 = V_281 ;
} else {
* V_280 = '\0' ;
V_280 ++ ;
}
V_20 = F_90 ( V_280 , 0 , & V_283 ) ;
if ( V_20 < 0 ) {
F_14 ( L_147
L_199 , V_20 ) ;
return F_15 ( V_20 ) ;
}
F_151 () ;
V_184 = F_152 ( V_279 , V_283 , 0 ) ;
if ( F_98 ( V_184 ) )
return F_153 ( V_184 ) ;
F_17 ( & V_184 -> V_4 , V_13 ,
& V_285 ) ;
return & V_184 -> V_4 ;
}
static void F_154 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
F_21 ( V_3 ) ;
}
static int T_8 F_155 ( void )
{
struct V_18 * V_286 , * V_287 = NULL , * V_288 = NULL ;
struct V_18 * V_289 = NULL ;
struct V_76 * V_290 ;
struct V_192 * V_193 ;
int V_20 ;
F_12 ( L_200
L_201 V_8 L_3 ,
V_291 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_290 = V_42 [ 0 ] ;
F_156 ( & V_290 -> V_292 ) ;
F_157 ( & V_290 -> V_293 ) ;
V_20 = F_158 () ;
if ( V_20 < 0 )
return V_20 ;
V_286 = & V_290 -> V_292 ;
V_286 -> V_24 = F_142 ( sizeof( struct V_18 ) * 2 ,
V_38 ) ;
if ( ! V_286 -> V_24 ) {
F_14 ( L_202 ) ;
V_20 = - V_39 ;
goto V_294;
}
F_17 ( & V_295 ,
L_203 , & V_296 ) ;
V_286 -> V_24 [ 0 ] = & V_295 ;
V_286 -> V_24 [ 1 ] = NULL ;
V_287 = & V_295 ;
V_287 -> V_24 = F_142 ( sizeof( struct V_18 * ) * 2 ,
V_38 ) ;
if ( ! V_287 -> V_24 ) {
F_14 ( L_204 ) ;
V_20 = - V_39 ;
goto V_294;
}
F_17 ( & V_297 ,
L_186 , & V_298 ) ;
V_287 -> V_24 [ 0 ] = & V_297 ;
V_287 -> V_24 [ 1 ] = NULL ;
V_288 = & V_297 ;
V_288 -> V_24 = F_142 ( sizeof( struct V_18 * ) * 2 ,
V_38 ) ;
if ( ! V_288 -> V_24 ) {
F_14 ( L_205 ) ;
V_20 = - V_39 ;
goto V_294;
}
F_17 ( & V_299 ,
L_206 , & V_300 ) ;
V_288 -> V_24 [ 0 ] = & V_299 ;
V_288 -> V_24 [ 1 ] = NULL ;
V_193 = F_97 ( L_207 , 1 ) ;
if ( F_98 ( V_193 ) ) {
V_20 = - V_39 ;
goto V_294;
}
V_289 = & V_299 ;
V_289 -> V_24 = F_142 ( sizeof( struct V_18 * ) * 2 ,
V_38 ) ;
if ( ! V_289 -> V_24 ) {
F_14 ( L_208 ) ;
V_20 = - V_39 ;
goto V_294;
}
F_17 ( & V_193 -> V_198 , L_207 ,
& V_215 ) ;
V_289 -> V_24 [ 0 ] = & V_193 -> V_198 ;
V_289 -> V_24 [ 1 ] = NULL ;
V_301 = V_193 ;
V_20 = F_159 ( V_290 ) ;
if ( V_20 < 0 ) {
F_14 ( L_209 ,
V_20 , V_290 -> V_292 . V_28 . V_302 ) ;
goto V_294;
}
F_12 ( L_210
L_211 V_9 L_212
L_213 V_8 L_3 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_20 = F_160 () ;
if ( V_20 < 0 )
goto V_158;
V_20 = F_161 () ;
if ( V_20 < 0 )
goto V_158;
V_20 = F_162 () ;
if ( V_20 < 0 )
goto V_158;
return 0 ;
V_158:
F_163 ( V_290 ) ;
F_164 () ;
F_165 () ;
V_294:
if ( V_301 ) {
F_95 ( V_301 ) ;
V_301 = NULL ;
}
if ( V_289 )
F_30 ( V_289 -> V_24 ) ;
if ( V_288 )
F_30 ( V_288 -> V_24 ) ;
if ( V_287 )
F_30 ( V_287 -> V_24 ) ;
F_30 ( V_286 -> V_24 ) ;
F_166 () ;
return V_20 ;
}
static void T_9 F_167 ( void )
{
struct V_76 * V_290 ;
struct V_18 * V_287 , * V_288 , * V_289 ;
struct V_2 * V_3 ;
int V_34 ;
V_290 = V_42 [ 0 ] ;
V_289 = & V_299 ;
for ( V_34 = 0 ; V_289 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_289 -> V_24 [ V_34 ] -> V_28 ;
V_289 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_289 -> V_24 ) ;
V_289 -> V_24 = NULL ;
V_288 = & V_297 ;
for ( V_34 = 0 ; V_288 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_288 -> V_24 [ V_34 ] -> V_28 ;
V_288 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_288 -> V_24 ) ;
V_288 -> V_24 = NULL ;
V_287 = & V_295 ;
for ( V_34 = 0 ; V_287 -> V_24 [ V_34 ] ; V_34 ++ ) {
V_3 = & V_287 -> V_24 [ V_34 ] -> V_28 ;
V_287 -> V_24 [ V_34 ] = NULL ;
F_21 ( V_3 ) ;
}
F_30 ( V_287 -> V_24 ) ;
V_287 -> V_24 = NULL ;
F_163 ( V_290 ) ;
F_30 ( V_290 -> V_292 . V_24 ) ;
F_95 ( V_301 ) ;
V_301 = NULL ;
F_12 ( L_214
L_215 ) ;
F_164 () ;
F_165 () ;
F_168 () ;
F_166 () ;
}
