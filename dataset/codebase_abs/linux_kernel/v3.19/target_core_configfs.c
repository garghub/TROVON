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
V_14 = F_6 ( V_13 ) ;
if ( ! V_14 ) {
F_13 ( L_6 ,
V_13 ) ;
if ( ! strncmp ( V_13 , L_7 , 5 ) ) {
V_20 = F_14 ( L_8 ) ;
if ( V_20 < 0 ) {
F_13 ( L_9
L_10 , V_20 ) ;
return F_15 ( - V_21 ) ;
}
} else if ( ! strncmp ( V_13 , L_11 , 8 ) ) {
V_20 = F_14 ( L_12 ) ;
if ( V_20 < 0 ) {
F_13 ( L_9
L_13 , V_20 ) ;
return F_15 ( - V_21 ) ;
}
}
V_14 = F_6 ( V_13 ) ;
}
if ( ! V_14 ) {
F_13 ( L_14 ,
V_13 ) ;
return F_15 ( - V_21 ) ;
}
F_12 ( L_15
L_5 , V_14 -> V_16 ) ;
F_12 ( L_16 ,
& V_14 -> V_22 . V_23 ) ;
V_14 -> V_24 . V_25 = V_14 -> V_26 ;
V_14 -> V_24 . V_25 [ 0 ] = & V_14 -> V_27 ;
V_14 -> V_24 . V_25 [ 1 ] = NULL ;
F_16 ( & V_14 -> V_24 , V_13 ,
& V_14 -> V_22 . V_23 ) ;
F_16 ( & V_14 -> V_27 , L_17 ,
& V_14 -> V_22 . V_28 ) ;
F_12 ( L_18
L_5 , V_14 -> V_24 . V_29 . V_30 ) ;
V_14 -> V_31 . V_32 = V_14 -> V_32 ;
V_14 -> V_33 = & V_14 -> V_24 . V_29 ;
F_12 ( L_19
L_20 , V_13 ) ;
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
F_12 ( L_21
L_22 , F_18 ( V_3 ) ) ;
F_12 ( L_23
L_5 , V_14 -> V_16 ) ;
F_19 ( & V_14 -> V_17 ) ;
F_12 ( L_24
L_25 , V_14 -> V_16 ) ;
V_14 -> V_33 = NULL ;
F_12 ( L_26
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
F_13 ( L_27 ) ;
return F_15 ( - V_21 ) ;
}
if ( strlen ( V_13 ) >= V_38 ) {
F_13 ( L_28
L_29 , V_13 ) ;
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
snprintf ( V_14 -> V_16 , V_38 , L_30 , V_13 ) ;
F_7 ( & V_15 ) ;
F_26 ( & V_14 -> V_41 , & V_44 ) ;
F_10 ( & V_15 ) ;
F_12 ( L_31
L_32 ) ;
F_12 ( L_33
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
F_13 ( L_34 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_48 ) {
F_13 ( L_35 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_49 ) {
F_13 ( L_36 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_50 ) {
F_13 ( L_37 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_51 ) {
F_13 ( L_38 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_52 ) {
F_13 ( L_39 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_53 ) {
F_13 ( L_40 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_54 ) {
F_13 ( L_41 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_55 ) {
F_13 ( L_42 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_56 ) {
F_13 ( L_43 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_57 ) {
F_13 ( L_44 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_58 ) {
F_13 ( L_45 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_59 ) {
F_13 ( L_46 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_60 ) {
F_13 ( L_47 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_61 ) {
F_13 ( L_48 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_62 ) {
F_13 ( L_49 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_63 ) {
F_13 ( L_50 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_64 ) {
F_13 ( L_51 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_65 ) {
F_13 ( L_52 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_66 ) {
F_13 ( L_53 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_67 ) {
F_13 ( L_54 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_68 ) {
F_13 ( L_55 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_69 ) {
F_13 ( L_56 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_70 ) {
F_13 ( L_57 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_71 ) {
F_13 ( L_58 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_72 ) {
F_13 ( L_59 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_73 ) {
F_13 ( L_60 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_74 ) {
F_13 ( L_61 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_75 ) {
F_13 ( L_62 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_76 ) {
F_13 ( L_63 ) ;
return - V_21 ;
}
if ( ! V_46 -> V_77 ) {
F_13 ( L_64 ) ;
return - V_21 ;
}
return 0 ;
}
int F_31 (
struct V_12 * V_14 )
{
int V_20 ;
if ( ! V_14 ) {
F_13 ( L_65
L_66 ) ;
return - V_21 ;
}
if ( ! V_14 -> V_32 ) {
F_13 ( L_67
L_66 ) ;
return - V_21 ;
}
V_20 = F_30 ( V_14 ) ;
if ( V_20 < 0 )
return V_20 ;
F_12 ( L_68
L_69 ) ;
return 0 ;
}
void F_32 (
struct V_12 * V_14 )
{
struct V_78 * V_79 ;
if ( ! V_14 ) {
F_13 ( L_70
L_71 ) ;
return;
}
V_79 = V_14 -> V_32 ;
if ( ! V_79 ) {
F_13 ( L_72
L_66 ) ;
return;
}
F_12 ( L_73
L_74 ) ;
F_7 ( & V_15 ) ;
if ( F_33 ( & V_14 -> V_17 ) ) {
F_10 ( & V_15 ) ;
F_13 ( L_75 ,
V_14 -> V_16 ) ;
F_34 () ;
}
F_28 ( & V_14 -> V_41 ) ;
F_10 ( & V_15 ) ;
F_12 ( L_76
L_5 , V_14 -> V_16 ) ;
V_14 -> V_42 = NULL ;
V_14 -> V_32 = NULL ;
F_29 ( V_14 ) ;
F_12 ( L_77
L_78 ) ;
}
static T_1 F_35 (
struct V_80 * V_80 ,
char * V_7 )
{
return sprintf ( V_7 , L_79 ,
& V_80 -> V_81 [ 0 ] ) ;
}
static T_1 F_36 (
struct V_80 * V_80 ,
const char * V_7 ,
T_2 V_82 )
{
struct V_83 * V_84 = V_80 -> V_85 ;
unsigned char V_86 [ V_87 ] ;
if ( V_84 -> V_88 & V_89 ) {
F_13 ( L_80
L_81 ) ;
return - V_90 ;
}
if ( strlen ( V_7 ) >= V_87 ) {
F_13 ( L_82
L_83 , V_87 ) ;
return - V_91 ;
}
if ( V_84 -> V_92 ) {
F_13 ( L_84
L_85 ,
V_84 -> V_92 ) ;
return - V_21 ;
}
memset ( V_86 , 0 , V_87 ) ;
snprintf ( V_86 , V_87 , L_30 , V_7 ) ;
snprintf ( V_84 -> V_80 . V_81 , V_87 ,
L_30 , F_37 ( V_86 ) ) ;
V_84 -> V_88 |= V_93 ;
F_12 ( L_86
L_5 , V_84 -> V_80 . V_81 ) ;
return V_82 ;
}
static T_1 F_38 (
struct V_80 * V_80 ,
char * V_7 )
{
struct V_94 * V_95 ;
unsigned char V_86 [ V_96 ] ;
T_1 V_97 = 0 ;
memset ( V_86 , 0 , V_96 ) ;
F_39 ( & V_80 -> V_98 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_95 -> V_99 )
continue;
F_40 ( V_95 , V_86 , V_96 ) ;
if ( V_97 + strlen ( V_86 ) >= V_100 )
break;
V_97 += sprintf ( V_7 + V_97 , L_30 , V_86 ) ;
}
F_41 ( & V_80 -> V_98 ) ;
return V_97 ;
}
static T_1 F_42 (
struct V_80 * V_80 ,
const char * V_7 ,
T_2 V_82 )
{
return - V_101 ;
}
static T_1 F_43 (
struct V_80 * V_80 ,
const char * V_7 ,
T_2 V_82 )
{
return - V_101 ;
}
static T_1 F_44 (
struct V_80 * V_80 ,
const char * V_7 ,
T_2 V_82 )
{
return - V_101 ;
}
static T_1 F_45 (
struct V_80 * V_80 ,
const char * V_7 ,
T_2 V_82 )
{
return - V_101 ;
}
static T_1 F_46 ( struct V_83 * V_84 ,
char * V_7 )
{
struct V_102 * V_103 ;
struct V_104 * V_105 ;
char V_106 [ V_107 ] ;
memset ( V_106 , 0 , V_107 ) ;
V_105 = V_84 -> V_108 ;
if ( ! V_105 )
return sprintf ( V_7 , L_87 ) ;
V_103 = V_105 -> V_109 ;
F_47 ( V_105 , V_106 , V_107 ) ;
return sprintf ( V_7 , L_88 ,
V_103 -> V_110 -> V_111 -> V_47 () ,
V_103 -> V_112 , V_106 ) ;
}
static T_1 F_48 ( struct V_83 * V_84 ,
char * V_7 )
{
struct V_102 * V_103 ;
T_1 V_97 ;
V_103 = V_84 -> V_113 ;
if ( V_103 ) {
V_97 = sprintf ( V_7 ,
L_89 ,
V_103 -> V_110 -> V_111 -> V_47 () ,
V_103 -> V_112 ) ;
} else {
V_97 = sprintf ( V_7 , L_90 ) ;
}
return V_97 ;
}
static T_1 F_49 ( struct V_83 * V_84 ,
char * V_7 )
{
int V_20 ;
if ( V_84 -> V_114 -> V_115 == V_116 )
return sprintf ( V_7 , L_91 ) ;
F_39 ( & V_84 -> V_117 ) ;
if ( V_84 -> V_118 & V_119 )
V_20 = F_48 ( V_84 , V_7 ) ;
else
V_20 = F_46 ( V_84 , V_7 ) ;
F_41 ( & V_84 -> V_117 ) ;
return V_20 ;
}
static T_1 F_50 (
struct V_83 * V_84 , char * V_7 )
{
T_1 V_97 = 0 ;
F_39 ( & V_84 -> V_117 ) ;
if ( ! V_84 -> V_108 ) {
V_97 = sprintf ( V_7 , L_87 ) ;
} else if ( V_84 -> V_108 -> V_120 ) {
V_97 = sprintf ( V_7 , L_92
L_93 ) ;
} else {
V_97 = sprintf ( V_7 , L_94
L_95 ) ;
}
F_41 ( & V_84 -> V_117 ) ;
return V_97 ;
}
static T_1 F_51 (
struct V_83 * V_84 , char * V_7 )
{
return sprintf ( V_7 , L_96 , V_84 -> V_121 . V_122 ) ;
}
static T_1 F_52 (
struct V_83 * V_84 , char * V_7 )
{
struct V_102 * V_103 ;
struct V_123 * V_124 ;
struct V_125 * V_110 ;
struct V_104 * V_105 ;
struct V_45 * V_46 ;
T_1 V_97 = 0 ;
F_39 ( & V_84 -> V_117 ) ;
V_105 = V_84 -> V_108 ;
if ( ! V_105 ) {
V_97 = sprintf ( V_7 , L_87 ) ;
goto V_126;
}
V_103 = V_105 -> V_109 ;
V_110 = V_103 -> V_110 ;
V_124 = V_105 -> V_127 ;
V_46 = V_110 -> V_111 ;
V_97 += sprintf ( V_7 + V_97 , L_97
L_98 , V_46 -> V_47 () ,
V_46 -> V_49 ( V_110 ) ) ;
V_97 += sprintf ( V_7 + V_97 , L_99
L_100
L_101 , V_124 -> V_128 -> V_129 ,
V_46 -> V_47 () , V_46 -> V_50 ( V_110 ) ,
V_46 -> V_47 () , V_124 -> V_130 ) ;
V_126:
F_41 ( & V_84 -> V_117 ) ;
return V_97 ;
}
static T_1 F_53 (
struct V_83 * V_84 , char * V_7 )
{
struct V_45 * V_46 ;
struct V_104 * V_105 ;
unsigned char V_86 [ 384 ] ;
char V_106 [ V_107 ] ;
T_1 V_97 = 0 ;
int V_131 = 0 ;
V_97 += sprintf ( V_7 + V_97 , L_102 ) ;
F_39 ( & V_84 -> V_121 . V_132 ) ;
F_8 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_86 , 0 , 384 ) ;
memset ( V_106 , 0 , V_107 ) ;
V_46 = V_105 -> V_109 -> V_110 -> V_111 ;
F_47 ( V_105 , V_106 ,
V_107 ) ;
sprintf ( V_86 , L_103 ,
V_46 -> V_47 () ,
V_105 -> V_109 -> V_112 , V_106 , V_105 -> V_133 ,
V_105 -> V_134 ) ;
if ( V_97 + strlen ( V_86 ) >= V_100 )
break;
V_97 += sprintf ( V_7 + V_97 , L_30 , V_86 ) ;
V_131 ++ ;
}
F_41 ( & V_84 -> V_121 . V_132 ) ;
if ( ! V_131 )
V_97 += sprintf ( V_7 + V_97 , L_104 ) ;
return V_97 ;
}
static T_1 F_54 (
struct V_83 * V_84 , char * V_7 )
{
struct V_104 * V_105 ;
T_1 V_97 = 0 ;
F_39 ( & V_84 -> V_117 ) ;
V_105 = V_84 -> V_108 ;
if ( V_105 ) {
V_97 = sprintf ( V_7 , L_105 ,
F_55 ( V_105 -> V_135 ) ) ;
} else {
V_97 = sprintf ( V_7 , L_87 ) ;
}
F_41 ( & V_84 -> V_117 ) ;
return V_97 ;
}
static T_1 F_56 (
struct V_83 * V_84 , char * V_7 )
{
if ( V_84 -> V_114 -> V_115 == V_116 )
return sprintf ( V_7 , L_106 ) ;
else if ( V_84 -> V_118 & V_119 )
return sprintf ( V_7 , L_107 ) ;
else
return sprintf ( V_7 , L_108 ) ;
}
static T_1 F_57 (
struct V_83 * V_84 , char * V_7 )
{
if ( V_84 -> V_114 -> V_115 == V_116 )
return 0 ;
return sprintf ( V_7 , L_109 ,
( V_84 -> V_121 . V_136 ) ? L_110 : L_111 ) ;
}
static T_1 F_58 (
struct V_83 * V_84 , char * V_7 )
{
if ( V_84 -> V_114 -> V_115 == V_116 )
return 0 ;
return sprintf ( V_7 , L_112 ) ;
}
static T_1 F_59 (
struct V_83 * V_84 ,
const char * V_7 ,
T_2 V_82 )
{
unsigned char * V_137 = NULL , * V_138 = NULL , * V_139 = NULL ;
unsigned char * V_140 = NULL , * V_141 = NULL ;
char * V_142 , * V_143 , * V_144 ;
T_3 args [ V_145 ] ;
unsigned long long V_146 ;
T_4 V_147 = 0 ;
T_5 V_148 = 0 , V_149 = 0 ;
int V_20 = - 1 , V_150 = 0 , V_151 = 0 , V_152 , V_153 ;
T_6 V_154 = 0 , V_155 = 0 ;
T_7 type = 0 , V_156 ;
if ( V_84 -> V_114 -> V_115 == V_116 )
return 0 ;
if ( V_84 -> V_118 & V_119 )
return 0 ;
if ( V_84 -> V_92 ) {
F_12 ( L_113
L_114 ) ;
return - V_21 ;
}
V_144 = F_60 ( V_7 , V_39 ) ;
if ( ! V_144 )
return - V_40 ;
V_142 = V_144 ;
while ( ( V_143 = F_61 ( & V_144 , L_115 ) ) != NULL ) {
if ( ! * V_143 )
continue;
V_153 = F_62 ( V_143 , V_157 , args ) ;
switch ( V_153 ) {
case V_158 :
V_137 = F_63 ( args ) ;
if ( ! V_137 ) {
V_20 = - V_40 ;
goto V_159;
}
break;
case V_160 :
V_138 = F_63 ( args ) ;
if ( ! V_138 ) {
V_20 = - V_40 ;
goto V_159;
}
if ( strlen ( V_138 ) >= V_161 ) {
F_13 ( L_116
L_117 ,
V_161 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_162 :
V_139 = F_63 ( args ) ;
if ( ! V_139 ) {
V_20 = - V_40 ;
goto V_159;
}
if ( strlen ( V_139 ) >= V_163 ) {
F_13 ( L_118
L_119 ,
V_163 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_164 :
V_20 = F_64 ( args -> V_165 , 0 , & V_146 ) ;
if ( V_20 < 0 ) {
F_13 ( L_120 ) ;
goto V_159;
}
V_147 = ( T_4 ) V_146 ;
break;
case V_166 :
F_65 ( args , & V_152 ) ;
V_150 = V_152 ;
break;
case V_167 :
F_65 ( args , & V_152 ) ;
type = ( T_7 ) V_152 ;
break;
case V_168 :
F_65 ( args , & V_152 ) ;
V_156 = ( T_7 ) V_152 ;
break;
case V_169 :
F_65 ( args , & V_152 ) ;
V_151 = ( int ) V_152 ;
break;
case V_170 :
F_65 ( args , & V_152 ) ;
V_148 = ( T_5 ) V_152 ;
break;
case V_171 :
V_140 = F_63 ( args ) ;
if ( ! V_140 ) {
V_20 = - V_40 ;
goto V_159;
}
break;
case V_172 :
V_141 = F_63 ( args ) ;
if ( ! V_141 ) {
V_20 = - V_40 ;
goto V_159;
}
if ( strlen ( V_141 ) >= V_173 ) {
F_13 ( L_121
L_122 ,
V_173 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_174 :
F_65 ( args , & V_152 ) ;
V_155 = ( T_6 ) V_152 ;
break;
case V_175 :
F_65 ( args , & V_152 ) ;
V_154 = ( T_6 ) V_152 ;
break;
case V_176 :
F_65 ( args , & V_152 ) ;
V_149 = ( T_5 ) V_152 ;
break;
default:
break;
}
}
if ( ! V_138 || ! V_141 || ! V_147 ) {
F_13 ( L_123 ) ;
V_20 = - V_21 ;
goto V_159;
}
if ( V_150 && ! ( type ) ) {
F_13 ( L_124
L_125 , type ) ;
V_20 = - V_21 ;
goto V_159;
}
V_20 = F_66 ( & V_84 -> V_121 , V_147 ,
V_138 , V_139 , V_148 , V_141 , V_155 , V_149 ,
V_150 , V_151 , type ) ;
V_159:
F_29 ( V_137 ) ;
F_29 ( V_138 ) ;
F_29 ( V_139 ) ;
F_29 ( V_140 ) ;
F_29 ( V_141 ) ;
F_29 ( V_142 ) ;
return ( V_20 == 0 ) ? V_82 : V_20 ;
}
static T_1 F_67 ( void * V_177 , char * V_7 )
{
struct V_83 * V_84 = V_177 ;
struct V_178 * V_179 = V_84 -> V_114 ;
int V_180 = 0 ;
T_1 V_181 = 0 ;
F_68 ( V_84 , V_7 , & V_180 ) ;
V_181 += V_180 ;
V_181 += V_179 -> V_182 ( V_84 , V_7 + V_181 ) ;
return V_181 ;
}
static T_1 F_69 (
void * V_177 ,
const char * V_7 ,
T_2 V_82 )
{
struct V_83 * V_84 = V_177 ;
struct V_178 * V_179 = V_84 -> V_114 ;
return V_179 -> V_183 ( V_84 , V_7 , V_82 ) ;
}
static T_1 F_70 ( void * V_177 , char * V_7 )
{
struct V_83 * V_84 = V_177 ;
if ( ! ( V_84 -> V_88 & V_184 ) )
return 0 ;
return snprintf ( V_7 , V_100 , L_126 , V_84 -> V_185 ) ;
}
static T_1 F_71 (
void * V_177 ,
const char * V_7 ,
T_2 V_82 )
{
struct V_83 * V_84 = V_177 ;
struct V_1 * V_186 = V_84 -> V_1 ;
T_1 V_181 ;
if ( V_82 > ( V_187 - 1 ) ) {
F_13 ( L_127
L_128 , ( int ) V_82 ,
V_187 - 1 ) ;
return - V_21 ;
}
V_181 = snprintf ( & V_84 -> V_185 [ 0 ] , V_187 , L_30 , V_7 ) ;
if ( ! V_181 )
return - V_21 ;
if ( V_84 -> V_185 [ V_181 - 1 ] == '\n' )
V_84 -> V_185 [ V_181 - 1 ] = '\0' ;
V_84 -> V_88 |= V_184 ;
F_12 ( L_129 ,
F_18 ( & V_186 -> V_4 . V_29 ) ,
F_18 ( & V_84 -> V_188 . V_29 ) ,
V_84 -> V_185 ) ;
return V_181 ;
}
static T_1 F_72 ( void * V_177 , char * V_7 )
{
struct V_83 * V_84 = V_177 ;
if ( ! ( V_84 -> V_88 & V_189 ) )
return 0 ;
return snprintf ( V_7 , V_100 , L_126 , V_84 -> V_190 ) ;
}
static T_1 F_73 (
void * V_177 ,
const char * V_7 ,
T_2 V_82 )
{
struct V_83 * V_84 = V_177 ;
struct V_1 * V_186 = V_84 -> V_1 ;
T_1 V_181 ;
if ( V_82 > ( V_191 - 1 ) ) {
F_13 ( L_130
L_131 , ( int ) V_82 ,
V_191 - 1 ) ;
return - V_21 ;
}
V_181 = snprintf ( & V_84 -> V_190 [ 0 ] , V_191 ,
L_30 , V_7 ) ;
if ( ! V_181 )
return - V_21 ;
if ( V_84 -> V_190 [ V_181 - 1 ] == '\n' )
V_84 -> V_190 [ V_181 - 1 ] = '\0' ;
V_84 -> V_88 |= V_189 ;
F_12 ( L_132 ,
F_18 ( & V_186 -> V_4 . V_29 ) ,
F_18 ( & V_84 -> V_188 . V_29 ) ,
V_84 -> V_190 ) ;
return V_181 ;
}
static T_1 F_74 ( void * V_177 , char * V_7 )
{
struct V_83 * V_84 = V_177 ;
return snprintf ( V_7 , V_100 , L_133 , ! ! ( V_84 -> V_88 & V_192 ) ) ;
}
static T_1 F_75 (
void * V_177 ,
const char * V_7 ,
T_2 V_82 )
{
struct V_83 * V_84 = V_177 ;
char * V_143 ;
int V_20 ;
V_143 = strstr ( V_7 , L_134 ) ;
if ( ! V_143 ) {
F_13 ( L_135
L_136 ) ;
return - V_21 ;
}
V_20 = F_76 ( V_84 ) ;
if ( V_20 )
return V_20 ;
return V_82 ;
}
static T_1 F_77 ( void * V_177 , char * V_7 )
{
struct V_83 * V_84 = V_177 ;
struct V_2 * V_193 ;
struct V_194 * V_195 ;
struct V_196 * V_197 ;
T_1 V_97 = 0 ;
V_197 = V_84 -> V_198 ;
if ( ! V_197 )
return 0 ;
F_39 ( & V_197 -> V_199 ) ;
V_195 = V_197 -> V_195 ;
if ( V_195 ) {
V_193 = & V_195 -> V_200 . V_29 ;
V_97 += sprintf ( V_7 , L_137 ,
F_18 ( V_193 ) , V_195 -> V_201 ) ;
}
F_41 ( & V_197 -> V_199 ) ;
return V_97 ;
}
static T_1 F_78 (
void * V_177 ,
const char * V_7 ,
T_2 V_82 )
{
struct V_83 * V_84 = V_177 ;
struct V_1 * V_186 = V_84 -> V_1 ;
struct V_194 * V_195 = NULL , * V_202 = NULL ;
struct V_196 * V_197 ;
unsigned char V_86 [ V_203 ] ;
int V_204 = 0 ;
V_197 = V_84 -> V_198 ;
if ( ! V_197 )
return 0 ;
if ( V_82 > V_203 ) {
F_13 ( L_138 ) ;
return - V_21 ;
}
memset ( V_86 , 0 , V_203 ) ;
memcpy ( V_86 , V_7 , V_82 ) ;
if ( strcmp ( F_37 ( V_86 ) , L_139 ) ) {
V_202 = F_79 ( F_37 ( V_86 ) ) ;
if ( ! V_202 )
return - V_205 ;
}
F_39 ( & V_197 -> V_199 ) ;
V_195 = V_197 -> V_195 ;
if ( V_195 ) {
if ( ! V_202 ) {
F_12 ( L_140
L_141
L_142 ,
F_18 ( & V_186 -> V_4 . V_29 ) ,
F_18 ( & V_84 -> V_188 . V_29 ) ,
F_18 ( & V_195 -> V_200 . V_29 ) ,
V_195 -> V_201 ) ;
F_80 ( V_197 , V_195 ) ;
F_41 ( & V_197 -> V_199 ) ;
return V_82 ;
}
F_80 ( V_197 , V_195 ) ;
V_204 = 1 ;
}
F_81 ( V_197 , V_202 ) ;
F_41 ( & V_197 -> V_199 ) ;
F_12 ( L_143
L_144 ,
( V_204 ) ? L_145 : L_146 ,
F_18 ( & V_186 -> V_4 . V_29 ) ,
F_18 ( & V_84 -> V_188 . V_29 ) ,
F_18 ( & V_202 -> V_200 . V_29 ) ,
V_202 -> V_201 ) ;
F_82 ( V_202 ) ;
return V_82 ;
}
static T_1 F_83 ( void * V_177 , char * V_7 )
{
struct V_83 * V_84 = V_177 ;
struct V_206 * V_207 ;
struct V_208 * V_209 ;
char * V_210 = V_7 ;
int V_180 = 0 ;
char V_211 ;
F_39 ( & V_84 -> V_212 . V_213 ) ;
if ( ! F_84 ( & V_84 -> V_212 . V_214 ) )
V_180 += sprintf ( V_210 + V_180 , L_147 ,
V_84 -> V_212 . V_215 ,
V_84 -> V_212 . V_216 ) ;
F_8 (map, &dev->t10_alua.lba_map_list, lba_map_list) {
V_180 += sprintf ( V_210 + V_180 , L_148 ,
V_207 -> V_217 , V_207 -> V_218 ) ;
F_8 (mem, &map->lba_map_mem_list,
lba_map_mem_list) {
switch ( V_209 -> V_219 ) {
case V_220 :
V_211 = 'O' ;
break;
case V_221 :
V_211 = 'A' ;
break;
case V_222 :
V_211 = 'S' ;
break;
case V_223 :
V_211 = 'U' ;
break;
default:
V_211 = '.' ;
break;
}
V_180 += sprintf ( V_210 + V_180 , L_149 ,
V_209 -> V_224 , V_211 ) ;
}
V_180 += sprintf ( V_210 + V_180 , L_3 ) ;
}
F_41 ( & V_84 -> V_212 . V_213 ) ;
return V_180 ;
}
static T_1 F_85 (
void * V_177 ,
const char * V_7 ,
T_2 V_82 )
{
struct V_83 * V_84 = V_177 ;
struct V_206 * V_225 = NULL ;
struct V_226 V_227 ;
char * V_228 , * V_143 ;
char V_211 ;
int V_229 = - 1 , V_230 ;
int V_20 = 0 , V_231 = 0 , V_232 , V_233 ;
unsigned long V_234 = - 1 , V_235 = - 1 ;
unsigned long V_236 = - 1 , V_237 = - 1 ;
V_228 = F_60 ( V_7 , V_39 ) ;
if ( ! V_228 )
return - V_40 ;
F_23 ( & V_227 ) ;
while ( ( V_143 = F_61 ( & V_228 , L_3 ) ) != NULL ) {
if ( ! * V_143 )
continue;
if ( V_231 == 0 ) {
if ( sscanf ( V_143 , L_150 ,
& V_236 , & V_237 ) != 2 ) {
F_13 ( L_151 , V_231 ) ;
V_20 = - V_21 ;
break;
}
V_231 ++ ;
continue;
}
if ( sscanf ( V_143 , L_152 , & V_234 , & V_235 ) != 2 ) {
F_13 ( L_151 , V_231 ) ;
V_20 = - V_21 ;
break;
}
V_143 = strchr ( V_143 , ' ' ) ;
if ( ! V_143 ) {
F_13 ( L_153 , V_231 ) ;
V_20 = - V_21 ;
break;
}
V_143 ++ ;
V_143 = strchr ( V_143 , ' ' ) ;
if ( ! V_143 ) {
F_13 ( L_154 ,
V_231 ) ;
V_20 = - V_21 ;
break;
}
V_143 ++ ;
V_225 = F_86 ( & V_227 ,
V_234 , V_235 ) ;
if ( F_87 ( V_225 ) ) {
V_20 = F_88 ( V_225 ) ;
break;
}
V_230 = 0 ;
while ( sscanf ( V_143 , L_155 , & V_232 , & V_211 ) == 2 ) {
switch ( V_211 ) {
case 'O' :
V_233 = V_220 ;
break;
case 'A' :
V_233 = V_221 ;
break;
case 'S' :
V_233 = V_222 ;
break;
case 'U' :
V_233 = V_223 ;
break;
default:
F_13 ( L_156 , V_211 ) ;
V_20 = - V_21 ;
goto V_159;
}
V_20 = F_89 ( V_225 ,
V_232 , V_233 ) ;
if ( V_20 ) {
F_13 ( L_157
L_158 ,
V_232 , V_211 , V_231 ) ;
break;
}
V_230 ++ ;
V_143 = strchr ( V_143 , ' ' ) ;
if ( V_143 )
V_143 ++ ;
else
break;
}
if ( V_229 == - 1 )
V_229 = V_230 ;
else if ( V_230 != V_229 ) {
F_13 ( L_159
L_158 , V_230 , V_229 , V_231 ) ;
V_20 = - V_21 ;
break;
}
V_231 ++ ;
}
V_159:
if ( V_20 ) {
F_90 ( & V_227 ) ;
V_82 = V_20 ;
} else
F_91 ( V_84 , & V_227 ,
V_236 , V_237 ) ;
F_29 ( V_228 ) ;
return V_82 ;
}
static void F_92 ( struct V_2 * V_3 )
{
struct V_18 * V_238 = F_3 ( V_3 ) ;
struct V_83 * V_84 =
F_2 ( V_238 , struct V_83 , V_188 ) ;
F_29 ( V_238 -> V_25 ) ;
F_93 ( V_84 ) ;
}
static T_1 F_94 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
char * V_7 )
{
struct V_18 * V_238 = F_3 ( V_3 ) ;
struct V_83 * V_84 =
F_2 ( V_238 , struct V_83 , V_188 ) ;
struct V_239 * V_240 = F_2 (
V_6 , struct V_239 , V_6 ) ;
if ( ! V_240 -> V_241 )
return - V_21 ;
return V_240 -> V_241 ( V_84 , V_7 ) ;
}
static T_1 F_95 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
const char * V_7 , T_2 V_82 )
{
struct V_18 * V_238 = F_3 ( V_3 ) ;
struct V_83 * V_84 =
F_2 ( V_238 , struct V_83 , V_188 ) ;
struct V_239 * V_240 = F_2 (
V_6 , struct V_239 , V_6 ) ;
if ( ! V_240 -> V_242 )
return - V_21 ;
return V_240 -> V_242 ( V_84 , V_7 , V_82 ) ;
}
static T_1 F_96 (
struct V_194 * V_195 ,
char * V_7 )
{
if ( ! V_195 -> V_243 )
return 0 ;
return sprintf ( V_7 , L_160 , V_195 -> V_201 ) ;
}
static T_1 F_97 (
struct V_194 * V_195 ,
const char * V_7 ,
T_2 V_82 )
{
struct V_18 * V_244 = & V_195 -> V_200 ;
unsigned long V_201 ;
int V_20 ;
V_20 = F_98 ( V_7 , 0 , & V_201 ) ;
if ( V_20 < 0 ) {
F_13 ( L_161
L_162 , V_20 ) ;
return V_20 ;
}
if ( V_201 > 0x0000ffff ) {
F_13 ( L_163
L_164 , V_201 ) ;
return - V_21 ;
}
V_20 = F_99 ( V_195 , ( T_6 ) V_201 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_165
L_166 ,
F_18 ( & V_244 -> V_29 ) ,
V_195 -> V_201 ) ;
return V_82 ;
}
static T_1 F_100 (
struct V_194 * V_195 ,
char * V_7 )
{
struct V_83 * V_84 ;
struct V_1 * V_186 ;
struct V_196 * V_197 ;
T_1 V_97 = 0 , V_245 ;
unsigned char V_86 [ V_203 ] ;
memset ( V_86 , 0 , V_203 ) ;
F_39 ( & V_195 -> V_246 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_84 = V_197 -> V_247 ;
V_186 = V_84 -> V_1 ;
V_245 = snprintf ( V_86 , V_203 , L_167 ,
F_18 ( & V_186 -> V_4 . V_29 ) ,
F_18 ( & V_84 -> V_188 . V_29 ) ) ;
V_245 ++ ;
if ( ( V_245 + V_97 ) > V_100 ) {
F_101 ( L_168
L_169 ) ;
break;
}
memcpy ( V_7 + V_97 , V_86 , V_245 ) ;
V_97 += V_245 ;
}
F_41 ( & V_195 -> V_246 ) ;
return V_97 ;
}
static void F_102 ( struct V_2 * V_3 )
{
struct V_194 * V_195 = F_2 ( F_3 ( V_3 ) ,
struct V_194 , V_200 ) ;
F_103 ( V_195 ) ;
}
static struct V_18 * F_104 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_194 * V_195 ;
struct V_18 * V_244 = NULL ;
struct V_2 * V_248 = NULL ;
V_195 = F_105 ( V_13 , 0 ) ;
if ( F_87 ( V_195 ) )
return NULL ;
V_244 = & V_195 -> V_200 ;
V_248 = & V_244 -> V_29 ;
F_16 ( V_244 , V_13 ,
& V_249 ) ;
F_12 ( L_170
L_171 ,
F_18 ( V_248 ) ) ;
return V_244 ;
}
static void F_106 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_194 * V_195 = F_2 ( F_3 ( V_3 ) ,
struct V_194 , V_200 ) ;
F_12 ( L_172
L_173 ,
F_18 ( V_3 ) , V_195 -> V_201 ) ;
F_20 ( V_3 ) ;
}
static T_1 F_107 (
struct V_250 * V_251 ,
char * V_7 )
{
return sprintf ( V_7 , L_133 ,
F_33 ( & V_251 -> V_252 ) ) ;
}
static T_1 F_108 (
struct V_250 * V_251 ,
const char * V_7 ,
T_2 V_82 )
{
struct V_83 * V_84 = V_251 -> V_253 ;
unsigned long V_254 ;
int V_255 , V_20 ;
if ( ! V_251 -> V_256 ) {
F_13 ( L_174
L_175 , V_251 -> V_256 ) ;
return - V_21 ;
}
if ( ! ( V_84 -> V_88 & V_192 ) ) {
F_13 ( L_176
L_177 ) ;
return - V_205 ;
}
V_20 = F_98 ( V_7 , 0 , & V_254 ) ;
if ( V_20 < 0 ) {
F_13 ( L_178
L_5 , V_7 ) ;
return V_20 ;
}
V_255 = ( int ) V_254 ;
if ( ! ( V_251 -> V_257 & V_258 ) ) {
F_13 ( L_179
L_180 ) ;
return - V_21 ;
}
if ( V_251 -> V_257 & V_259 &&
V_255 == V_260 ) {
F_13 ( L_181
L_182 ) ;
return - V_21 ;
}
V_20 = F_109 ( V_251 , V_84 ,
NULL , NULL , V_255 , 0 ) ;
return ( ! V_20 ) ? V_82 : - V_21 ;
}
static T_1 F_110 (
struct V_250 * V_251 ,
char * V_7 )
{
return sprintf ( V_7 , L_126 ,
F_111 ( V_251 -> V_261 ) ) ;
}
static T_1 F_112 (
struct V_250 * V_251 ,
const char * V_7 ,
T_2 V_82 )
{
unsigned long V_254 ;
int V_262 , V_20 ;
if ( ! V_251 -> V_256 ) {
F_13 ( L_183
L_184 ,
V_251 -> V_256 ) ;
return - V_21 ;
}
V_20 = F_98 ( V_7 , 0 , & V_254 ) ;
if ( V_20 < 0 ) {
F_13 ( L_185
L_186 , V_7 ) ;
return V_20 ;
}
V_262 = ( int ) V_254 ;
if ( ( V_262 != V_263 ) &&
( V_262 != V_264 ) &&
( V_262 != V_265 ) ) {
F_13 ( L_187 ,
V_262 ) ;
return - V_21 ;
}
V_251 -> V_261 = V_262 ;
return V_82 ;
}
static T_1 F_113 (
struct V_250 * V_251 ,
char * V_7 )
{
return F_114 ( V_251 , V_7 ) ;
}
static T_1 F_115 (
struct V_250 * V_251 ,
const char * V_7 ,
T_2 V_82 )
{
return F_116 ( V_251 , V_7 , V_82 ) ;
}
static T_1 F_117 (
struct V_250 * V_251 ,
char * V_7 )
{
return sprintf ( V_7 , L_133 , V_251 -> V_266 ) ;
}
static T_1 F_118 (
struct V_250 * V_251 ,
const char * V_7 ,
T_2 V_82 )
{
unsigned long V_254 ;
int V_20 ;
V_20 = F_98 ( V_7 , 0 , & V_254 ) ;
if ( V_20 < 0 ) {
F_13 ( L_188 ) ;
return V_20 ;
}
if ( ( V_254 != 0 ) && ( V_254 != 1 ) ) {
F_13 ( L_189
L_190 , V_254 ) ;
return - V_21 ;
}
V_251 -> V_266 = ( int ) V_254 ;
return V_82 ;
}
static T_1 F_119 (
struct V_250 * V_251 ,
char * V_7 )
{
return F_120 ( V_251 , V_7 ) ;
}
static T_1 F_121 (
struct V_250 * V_251 ,
const char * V_7 ,
T_2 V_82 )
{
return F_122 ( V_251 , V_7 , V_82 ) ;
}
static T_1 F_123 (
struct V_250 * V_251 ,
char * V_7 )
{
return F_124 ( V_251 , V_7 ) ;
}
static T_1 F_125 (
struct V_250 * V_251 ,
const char * V_7 ,
T_2 V_82 )
{
return F_126 ( V_251 , V_7 , V_82 ) ;
}
static T_1 F_127 (
struct V_250 * V_251 ,
char * V_7 )
{
return F_128 ( V_251 , V_7 ) ;
}
static T_1 F_129 (
struct V_250 * V_251 ,
const char * V_7 ,
T_2 V_82 )
{
return F_130 ( V_251 , V_7 , V_82 ) ;
}
static T_1 F_131 (
struct V_250 * V_251 ,
char * V_7 )
{
return F_132 ( V_251 , V_7 ) ;
}
static T_1 F_133 (
struct V_250 * V_251 ,
const char * V_7 ,
T_2 V_82 )
{
return F_134 ( V_251 , V_7 , V_82 ) ;
}
static T_1 F_135 (
struct V_250 * V_251 ,
char * V_7 )
{
if ( ! V_251 -> V_256 )
return 0 ;
return sprintf ( V_7 , L_160 , V_251 -> V_267 ) ;
}
static T_1 F_136 (
struct V_250 * V_251 ,
const char * V_7 ,
T_2 V_82 )
{
struct V_18 * V_268 = & V_251 -> V_269 ;
unsigned long V_267 ;
int V_20 ;
V_20 = F_98 ( V_7 , 0 , & V_267 ) ;
if ( V_20 < 0 ) {
F_13 ( L_161
L_191 , V_20 ) ;
return V_20 ;
}
if ( V_267 > 0x0000ffff ) {
F_13 ( L_192
L_164 , V_267 ) ;
return - V_21 ;
}
V_20 = F_137 ( V_251 , ( T_6 ) V_267 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_193
L_194 ,
F_18 ( & V_268 -> V_29 ) ,
V_251 -> V_267 ) ;
return V_82 ;
}
static T_1 F_138 (
struct V_250 * V_251 ,
char * V_7 )
{
struct V_270 * V_271 ;
struct V_125 * V_272 ;
struct V_123 * V_124 ;
struct V_273 * V_274 ;
T_1 V_97 = 0 , V_245 ;
unsigned char V_86 [ V_275 ] ;
memset ( V_86 , 0 , V_275 ) ;
F_39 ( & V_251 -> V_276 ) ;
F_8 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_271 = V_274 -> V_277 ;
V_272 = V_271 -> V_278 ;
V_124 = V_271 -> V_279 ;
V_245 = snprintf ( V_86 , V_275 , L_195
L_196 , V_272 -> V_111 -> V_47 () ,
V_272 -> V_111 -> V_49 ( V_272 ) ,
V_272 -> V_111 -> V_50 ( V_272 ) ,
F_18 ( & V_124 -> V_280 . V_29 ) ) ;
V_245 ++ ;
if ( ( V_245 + V_97 ) > V_100 ) {
F_101 ( L_168
L_169 ) ;
break;
}
memcpy ( V_7 + V_97 , V_86 , V_245 ) ;
V_97 += V_245 ;
}
F_41 ( & V_251 -> V_276 ) ;
return V_97 ;
}
static void F_139 ( struct V_2 * V_3 )
{
struct V_250 * V_251 = F_2 ( F_3 ( V_3 ) ,
struct V_250 , V_269 ) ;
F_140 ( V_251 ) ;
}
static struct V_18 * F_141 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_212 * V_281 = F_2 ( V_19 , struct V_212 ,
V_282 ) ;
struct V_250 * V_251 ;
struct V_18 * V_268 = NULL ;
struct V_2 * V_283 = NULL ;
V_251 = F_142 ( V_281 -> V_85 , V_13 , 0 ) ;
if ( ! V_251 )
return NULL ;
V_268 = & V_251 -> V_269 ;
V_283 = & V_268 -> V_29 ;
F_16 ( V_268 , V_13 ,
& V_284 ) ;
F_12 ( L_197
L_198 ,
F_18 ( V_283 ) ) ;
return V_268 ;
}
static void F_143 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_250 * V_251 = F_2 ( F_3 ( V_3 ) ,
struct V_250 , V_269 ) ;
F_12 ( L_199
L_200 ,
F_18 ( V_3 ) , V_251 -> V_267 ) ;
F_20 ( V_3 ) ;
}
static struct V_18 * F_144 (
struct V_18 * V_19 ,
const char * V_13 )
{
return F_15 ( - V_101 ) ;
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
struct V_250 * V_251 ;
struct V_178 * V_179 ;
struct V_2 * V_285 = & V_19 -> V_29 ;
struct V_1 * V_186 = F_1 ( V_285 ) ;
struct V_83 * V_84 ;
struct V_18 * V_238 = NULL , * V_286 = NULL ;
struct V_18 * V_287 = NULL ;
int V_288 = - V_40 , V_20 ;
V_20 = F_147 ( & V_186 -> V_289 ) ;
if ( V_20 )
return F_15 ( V_20 ) ;
V_179 = V_186 -> V_114 ;
V_84 = F_148 ( V_186 , V_13 ) ;
if ( ! V_84 )
goto V_126;
V_238 = & V_84 -> V_188 ;
V_238 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 6 ,
V_39 ) ;
if ( ! V_238 -> V_25 )
goto V_290;
F_16 ( V_238 , V_13 , & V_179 -> V_291 . V_292 ) ;
F_16 ( & V_84 -> V_293 . V_294 , L_201 ,
& V_179 -> V_291 . V_295 ) ;
F_16 ( & V_84 -> V_296 , L_202 ,
& V_179 -> V_291 . V_297 ) ;
F_16 ( & V_84 -> V_80 . V_298 , L_203 ,
& V_179 -> V_291 . V_299 ) ;
F_16 ( & V_84 -> V_212 . V_282 ,
L_204 , & V_179 -> V_291 . V_300 ) ;
F_16 ( & V_84 -> V_301 . V_302 ,
L_205 , & V_179 -> V_291 . V_303 ) ;
V_238 -> V_25 [ 0 ] = & V_84 -> V_293 . V_294 ;
V_238 -> V_25 [ 1 ] = & V_84 -> V_296 ;
V_238 -> V_25 [ 2 ] = & V_84 -> V_80 . V_298 ;
V_238 -> V_25 [ 3 ] = & V_84 -> V_212 . V_282 ;
V_238 -> V_25 [ 4 ] = & V_84 -> V_301 . V_302 ;
V_238 -> V_25 [ 5 ] = NULL ;
V_251 = F_142 ( V_84 , L_206 , 1 ) ;
if ( ! V_251 )
goto V_304;
V_84 -> V_212 . V_305 = V_251 ;
V_286 = & V_84 -> V_212 . V_282 ;
V_286 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 2 ,
V_39 ) ;
if ( ! V_286 -> V_25 ) {
F_13 ( L_207
L_208 ) ;
goto V_306;
}
F_16 ( & V_251 -> V_269 ,
L_206 , & V_284 ) ;
V_286 -> V_25 [ 0 ] = & V_251 -> V_269 ;
V_286 -> V_25 [ 1 ] = NULL ;
V_287 = & V_84 -> V_301 . V_302 ;
V_287 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 4 ,
V_39 ) ;
if ( ! V_287 -> V_25 ) {
F_13 ( L_209 ) ;
goto V_307;
}
F_150 ( V_84 ) ;
F_10 ( & V_186 -> V_289 ) ;
return V_238 ;
V_307:
F_29 ( V_286 -> V_25 ) ;
V_306:
F_140 ( V_251 ) ;
V_304:
F_29 ( V_238 -> V_25 ) ;
V_290:
F_93 ( V_84 ) ;
V_126:
F_10 ( & V_186 -> V_289 ) ;
return F_15 ( V_288 ) ;
}
static void F_151 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_18 * V_238 = F_3 ( V_3 ) ;
struct V_83 * V_84 =
F_2 ( V_238 , struct V_83 , V_188 ) ;
struct V_1 * V_186 ;
struct V_2 * V_34 ;
struct V_18 * V_286 , * V_287 ;
int V_35 ;
V_186 = F_1 ( & V_84 -> V_1 -> V_4 . V_29 ) ;
F_7 ( & V_186 -> V_289 ) ;
V_287 = & V_84 -> V_301 . V_302 ;
for ( V_35 = 0 ; V_287 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_34 = & V_287 -> V_25 [ V_35 ] -> V_29 ;
V_287 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_34 ) ;
}
F_29 ( V_287 -> V_25 ) ;
V_286 = & V_84 -> V_212 . V_282 ;
for ( V_35 = 0 ; V_286 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_34 = & V_286 -> V_25 [ V_35 ] -> V_29 ;
V_286 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_34 ) ;
}
F_29 ( V_286 -> V_25 ) ;
V_84 -> V_212 . V_305 = NULL ;
for ( V_35 = 0 ; V_238 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_34 = & V_238 -> V_25 [ V_35 ] -> V_29 ;
V_238 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_34 ) ;
}
F_20 ( V_3 ) ;
F_10 ( & V_186 -> V_289 ) ;
}
static T_1 F_152 (
struct V_1 * V_186 ,
char * V_7 )
{
return sprintf ( V_7 , L_210 ,
V_186 -> V_308 , V_186 -> V_114 -> V_13 ,
V_9 ) ;
}
static T_1 F_153 ( struct V_1 * V_186 ,
char * V_7 )
{
int V_309 = 0 ;
if ( V_186 -> V_310 & V_311 )
V_309 = 1 ;
return sprintf ( V_7 , L_133 , V_309 ) ;
}
static T_1 F_154 ( struct V_1 * V_186 ,
const char * V_7 , T_2 V_82 )
{
struct V_178 * V_114 = V_186 -> V_114 ;
unsigned long V_312 ;
int V_20 ;
if ( V_114 -> V_313 == NULL )
return - V_21 ;
V_20 = F_98 ( V_7 , 0 , & V_312 ) ;
if ( V_20 < 0 ) {
F_13 ( L_211 , V_20 ) ;
return V_20 ;
}
if ( V_186 -> V_314 ) {
F_13 ( L_212 ) ;
return - V_21 ;
}
V_20 = V_114 -> V_313 ( V_186 , V_312 ) ;
if ( V_20 < 0 )
return - V_21 ;
if ( V_20 > 0 )
V_186 -> V_310 |= V_311 ;
else if ( V_20 == 0 )
V_186 -> V_310 &= ~ V_311 ;
return V_82 ;
}
static void F_155 ( struct V_2 * V_3 )
{
struct V_1 * V_186 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_156 ( V_186 ) ;
}
static struct V_18 * F_157 (
struct V_18 * V_19 ,
const char * V_13 )
{
char * V_315 , * V_316 , * V_317 ;
struct V_1 * V_186 ;
char V_86 [ V_318 ] ;
unsigned long V_319 = 0 ;
int V_20 ;
memset ( V_86 , 0 , V_318 ) ;
if ( strlen ( V_13 ) >= V_318 ) {
F_13 ( L_213
L_214 , ( int ) strlen ( V_13 ) ,
V_318 ) ;
return F_15 ( - V_320 ) ;
}
snprintf ( V_86 , V_318 , L_30 , V_13 ) ;
V_316 = strstr ( V_86 , L_215 ) ;
if ( ! V_316 ) {
F_13 ( L_216 ) ;
return F_15 ( - V_21 ) ;
}
V_315 = V_86 ;
V_317 = strstr ( V_316 + 1 , L_215 ) ;
if ( V_317 ) {
* V_317 = '\0' ;
V_317 ++ ;
V_316 = V_317 ;
} else {
* V_316 = '\0' ;
V_316 ++ ;
}
V_20 = F_98 ( V_316 , 0 , & V_319 ) ;
if ( V_20 < 0 ) {
F_13 ( L_161
L_217 , V_20 ) ;
return F_15 ( V_20 ) ;
}
F_158 () ;
V_186 = F_159 ( V_315 , V_319 , 0 ) ;
if ( F_87 ( V_186 ) )
return F_160 ( V_186 ) ;
F_16 ( & V_186 -> V_4 , V_13 ,
& V_321 ) ;
return & V_186 -> V_4 ;
}
static void F_161 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
F_20 ( V_3 ) ;
}
void F_162 ( struct V_178 * V_322 )
{
F_163 ( V_322 ) ;
F_164 ( V_322 ) ;
F_165 ( V_322 ) ;
F_166 ( V_322 ) ;
F_167 ( V_322 ) ;
F_168 ( V_322 ) ;
}
static int T_8 F_169 ( void )
{
struct V_18 * V_323 , * V_324 = NULL , * V_325 = NULL ;
struct V_18 * V_326 = NULL ;
struct V_78 * V_327 ;
struct V_194 * V_195 ;
int V_20 ;
F_12 ( L_218
L_219 V_8 L_3 ,
V_328 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_327 = V_43 [ 0 ] ;
F_170 ( & V_327 -> V_329 ) ;
F_171 ( & V_327 -> V_330 ) ;
V_20 = F_172 () ;
if ( V_20 < 0 )
return V_20 ;
V_323 = & V_327 -> V_329 ;
V_323 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 2 ,
V_39 ) ;
if ( ! V_323 -> V_25 ) {
F_13 ( L_220 ) ;
V_20 = - V_40 ;
goto V_331;
}
F_16 ( & V_332 ,
L_221 , & V_333 ) ;
V_323 -> V_25 [ 0 ] = & V_332 ;
V_323 -> V_25 [ 1 ] = NULL ;
V_324 = & V_332 ;
V_324 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 2 ,
V_39 ) ;
if ( ! V_324 -> V_25 ) {
F_13 ( L_222 ) ;
V_20 = - V_40 ;
goto V_331;
}
F_16 ( & V_334 ,
L_204 , & V_335 ) ;
V_324 -> V_25 [ 0 ] = & V_334 ;
V_324 -> V_25 [ 1 ] = NULL ;
V_325 = & V_334 ;
V_325 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 2 ,
V_39 ) ;
if ( ! V_325 -> V_25 ) {
F_13 ( L_223 ) ;
V_20 = - V_40 ;
goto V_331;
}
F_16 ( & V_336 ,
L_224 , & V_337 ) ;
V_325 -> V_25 [ 0 ] = & V_336 ;
V_325 -> V_25 [ 1 ] = NULL ;
V_195 = F_105 ( L_225 , 1 ) ;
if ( F_87 ( V_195 ) ) {
V_20 = - V_40 ;
goto V_331;
}
V_326 = & V_336 ;
V_326 -> V_25 = F_149 ( sizeof( struct V_18 * ) * 2 ,
V_39 ) ;
if ( ! V_326 -> V_25 ) {
F_13 ( L_226 ) ;
V_20 = - V_40 ;
goto V_331;
}
F_16 ( & V_195 -> V_200 , L_225 ,
& V_249 ) ;
V_326 -> V_25 [ 0 ] = & V_195 -> V_200 ;
V_326 -> V_25 [ 1 ] = NULL ;
V_338 = V_195 ;
V_20 = F_173 ( V_327 ) ;
if ( V_20 < 0 ) {
F_13 ( L_227 ,
V_20 , V_327 -> V_329 . V_29 . V_339 ) ;
goto V_331;
}
F_12 ( L_228
L_229 V_9 L_230
L_231 V_8 L_3 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_20 = F_174 () ;
if ( V_20 < 0 )
goto V_159;
V_20 = F_175 () ;
if ( V_20 < 0 )
goto V_159;
V_20 = F_176 () ;
if ( V_20 < 0 )
goto V_159;
return 0 ;
V_159:
F_177 ( V_327 ) ;
F_178 () ;
F_179 () ;
V_331:
if ( V_338 ) {
F_103 ( V_338 ) ;
V_338 = NULL ;
}
if ( V_326 )
F_29 ( V_326 -> V_25 ) ;
if ( V_325 )
F_29 ( V_325 -> V_25 ) ;
if ( V_324 )
F_29 ( V_324 -> V_25 ) ;
F_29 ( V_323 -> V_25 ) ;
F_180 () ;
return V_20 ;
}
static void T_9 F_181 ( void )
{
struct V_78 * V_327 ;
struct V_18 * V_324 , * V_325 , * V_326 ;
struct V_2 * V_3 ;
int V_35 ;
V_327 = V_43 [ 0 ] ;
V_326 = & V_336 ;
for ( V_35 = 0 ; V_326 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_3 = & V_326 -> V_25 [ V_35 ] -> V_29 ;
V_326 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_3 ) ;
}
F_29 ( V_326 -> V_25 ) ;
V_326 -> V_25 = NULL ;
V_325 = & V_334 ;
for ( V_35 = 0 ; V_325 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_3 = & V_325 -> V_25 [ V_35 ] -> V_29 ;
V_325 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_3 ) ;
}
F_29 ( V_325 -> V_25 ) ;
V_325 -> V_25 = NULL ;
V_324 = & V_332 ;
for ( V_35 = 0 ; V_324 -> V_25 [ V_35 ] ; V_35 ++ ) {
V_3 = & V_324 -> V_25 [ V_35 ] -> V_29 ;
V_324 -> V_25 [ V_35 ] = NULL ;
F_20 ( V_3 ) ;
}
F_29 ( V_324 -> V_25 ) ;
V_324 -> V_25 = NULL ;
F_177 ( V_327 ) ;
F_29 ( V_327 -> V_329 . V_25 ) ;
F_103 ( V_338 ) ;
V_338 = NULL ;
F_12 ( L_232
L_233 ) ;
F_178 () ;
F_179 () ;
F_182 () ;
F_180 () ;
}
