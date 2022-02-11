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
L_5 , V_14 -> V_16 ) ;
F_12 ( L_16 ,
& V_14 -> V_22 . V_23 ) ;
V_14 -> V_24 . V_25 = V_14 -> V_26 ;
V_14 -> V_24 . V_25 [ 0 ] = & V_14 -> V_27 ;
V_14 -> V_24 . V_25 [ 1 ] = NULL ;
F_15 ( & V_14 -> V_24 , V_13 ,
& V_14 -> V_22 . V_23 ) ;
F_15 ( & V_14 -> V_27 , L_17 ,
& V_14 -> V_22 . V_28 ) ;
F_12 ( L_18
L_5 , V_14 -> V_24 . V_29 . V_30 ) ;
V_14 -> V_31 = & V_14 -> V_24 . V_29 ;
F_12 ( L_19
L_20 , V_13 ) ;
return & V_14 -> V_24 ;
}
static void F_16 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_12 * V_14 = F_2 (
F_3 ( V_3 ) , struct V_12 , V_24 ) ;
struct V_18 * V_24 ;
struct V_2 * V_32 ;
int V_33 ;
F_12 ( L_21
L_22 , F_17 ( V_3 ) ) ;
F_12 ( L_23
L_5 , V_14 -> V_16 ) ;
F_18 ( & V_14 -> V_17 ) ;
F_12 ( L_24
L_25 , V_14 -> V_16 ) ;
V_14 -> V_31 = NULL ;
F_12 ( L_26
L_5 , F_17 ( V_3 ) ) ;
V_24 = & V_14 -> V_24 ;
for ( V_33 = 0 ; V_24 -> V_25 [ V_33 ] ; V_33 ++ ) {
V_32 = & V_24 -> V_25 [ V_33 ] -> V_29 ;
V_24 -> V_25 [ V_33 ] = NULL ;
F_19 ( V_32 ) ;
}
F_19 ( V_3 ) ;
}
int F_20 ( struct V_2 * V_3 )
{
return F_21 ( & V_34 , V_3 ) ;
}
void F_22 ( struct V_2 * V_3 )
{
return F_23 ( & V_34 , V_3 ) ;
}
static int F_24 ( const struct V_35 * V_36 )
{
if ( ! V_36 -> V_13 ) {
F_25 ( L_27 ) ;
return - V_21 ;
}
if ( strlen ( V_36 -> V_13 ) >= V_37 ) {
F_25 ( L_28
L_29 , V_36 -> V_13 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_38 ) {
F_25 ( L_30 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_39 ) {
F_25 ( L_31 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_40 ) {
F_25 ( L_32 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_41 ) {
F_25 ( L_33 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_42 ) {
F_25 ( L_34 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_43 ) {
F_25 ( L_35 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_44 ) {
F_25 ( L_36 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_45 ) {
F_25 ( L_37 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_46 ) {
F_25 ( L_38 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_47 ) {
F_25 ( L_39 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_48 ) {
F_25 ( L_40 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_49 ) {
F_25 ( L_41 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_50 ) {
F_25 ( L_42 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_51 ) {
F_25 ( L_43 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_52 ) {
F_25 ( L_44 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_53 ) {
F_25 ( L_45 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_54 ) {
F_25 ( L_46 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_55 ) {
F_25 ( L_47 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_56 ) {
F_25 ( L_48 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_57 ) {
F_25 ( L_49 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_58 ) {
F_25 ( L_50 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_59 ) {
F_25 ( L_51 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_60 ) {
F_25 ( L_52 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_61 ) {
F_25 ( L_53 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_62 ) {
F_25 ( L_54 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_63 ) {
F_25 ( L_55 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_64 ) {
F_25 ( L_56 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_65 ) {
F_25 ( L_57 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_66 ) {
F_25 ( L_58 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_67 ) {
F_25 ( L_59 ) ;
return - V_21 ;
}
if ( ! V_36 -> V_68 ) {
F_25 ( L_60 ) ;
return - V_21 ;
}
return 0 ;
}
int F_26 ( const struct V_35 * V_69 )
{
struct V_12 * V_14 ;
int V_20 ;
V_20 = F_24 ( V_69 ) ;
if ( V_20 )
return V_20 ;
V_14 = F_27 ( sizeof( struct V_12 ) , V_70 ) ;
if ( ! V_14 ) {
F_25 ( L_61 , V_71 ) ;
return - V_72 ;
}
F_28 ( & V_14 -> V_73 ) ;
F_29 ( & V_14 -> V_17 , 0 ) ;
V_14 -> V_74 = V_69 -> V_75 ;
snprintf ( V_14 -> V_16 , V_37 , L_62 , V_69 -> V_13 ) ;
V_14 -> V_76 = * V_69 ;
F_30 ( V_14 ) ;
F_7 ( & V_15 ) ;
F_31 ( & V_14 -> V_73 , & V_77 ) ;
F_10 ( & V_15 ) ;
return 0 ;
}
void F_32 ( const struct V_35 * V_69 )
{
struct V_12 * V_78 ;
F_7 ( & V_15 ) ;
F_8 (t, &g_tf_list, tf_list) {
if ( ! strcmp ( V_78 -> V_16 , V_69 -> V_13 ) ) {
F_33 ( F_34 ( & V_78 -> V_17 ) ) ;
F_35 ( & V_78 -> V_73 ) ;
F_36 ( V_78 ) ;
break;
}
}
F_10 ( & V_15 ) ;
}
static T_1 F_37 (
struct V_79 * V_79 ,
char * V_7 )
{
return sprintf ( V_7 , L_63 ,
& V_79 -> V_80 [ 0 ] ) ;
}
static T_1 F_38 (
struct V_79 * V_79 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_79 -> V_84 ;
unsigned char V_85 [ V_86 ] ;
if ( V_83 -> V_87 & V_88 ) {
F_25 ( L_64
L_65 ) ;
return - V_89 ;
}
if ( strlen ( V_7 ) >= V_86 ) {
F_25 ( L_66
L_67 , V_86 ) ;
return - V_90 ;
}
if ( V_83 -> V_91 ) {
F_25 ( L_68
L_69 ,
V_83 -> V_91 ) ;
return - V_21 ;
}
memset ( V_85 , 0 , V_86 ) ;
snprintf ( V_85 , V_86 , L_62 , V_7 ) ;
snprintf ( V_83 -> V_79 . V_80 , V_86 ,
L_62 , F_39 ( V_85 ) ) ;
V_83 -> V_87 |= V_92 ;
F_12 ( L_70
L_5 , V_83 -> V_79 . V_80 ) ;
return V_81 ;
}
static T_1 F_40 (
struct V_79 * V_79 ,
char * V_7 )
{
struct V_93 * V_94 ;
unsigned char V_85 [ V_95 ] ;
T_1 V_96 = 0 ;
memset ( V_85 , 0 , V_95 ) ;
F_41 ( & V_79 -> V_97 ) ;
F_8 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_94 -> V_98 )
continue;
F_42 ( V_94 , V_85 , V_95 ) ;
if ( V_96 + strlen ( V_85 ) >= V_99 )
break;
V_96 += sprintf ( V_7 + V_96 , L_62 , V_85 ) ;
}
F_43 ( & V_79 -> V_97 ) ;
return V_96 ;
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
static T_1 F_46 (
struct V_79 * V_79 ,
const char * V_7 ,
T_2 V_81 )
{
return - V_100 ;
}
static T_1 F_47 (
struct V_79 * V_79 ,
const char * V_7 ,
T_2 V_81 )
{
return - V_100 ;
}
static T_1 F_48 ( struct V_82 * V_83 ,
char * V_7 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
char V_105 [ V_106 ] ;
memset ( V_105 , 0 , V_106 ) ;
V_104 = V_83 -> V_107 ;
if ( ! V_104 )
return sprintf ( V_7 , L_71 ) ;
V_102 = V_104 -> V_108 ;
F_49 ( V_104 , V_105 , V_106 ) ;
return sprintf ( V_7 , L_72 ,
V_102 -> V_109 -> V_110 -> V_38 () ,
V_102 -> V_111 , V_105 ) ;
}
static T_1 F_50 ( struct V_82 * V_83 ,
char * V_7 )
{
struct V_101 * V_102 ;
T_1 V_96 ;
V_102 = V_83 -> V_112 ;
if ( V_102 ) {
V_96 = sprintf ( V_7 ,
L_73 ,
V_102 -> V_109 -> V_110 -> V_38 () ,
V_102 -> V_111 ) ;
} else {
V_96 = sprintf ( V_7 , L_74 ) ;
}
return V_96 ;
}
static T_1 F_51 ( struct V_82 * V_83 ,
char * V_7 )
{
int V_20 ;
if ( V_83 -> V_113 -> V_114 & V_115 )
return sprintf ( V_7 , L_75 ) ;
F_41 ( & V_83 -> V_116 ) ;
if ( V_83 -> V_117 & V_118 )
V_20 = F_50 ( V_83 , V_7 ) ;
else
V_20 = F_48 ( V_83 , V_7 ) ;
F_43 ( & V_83 -> V_116 ) ;
return V_20 ;
}
static T_1 F_52 (
struct V_82 * V_83 , char * V_7 )
{
T_1 V_96 = 0 ;
F_41 ( & V_83 -> V_116 ) ;
if ( ! V_83 -> V_107 ) {
V_96 = sprintf ( V_7 , L_71 ) ;
} else if ( V_83 -> V_107 -> V_119 ) {
V_96 = sprintf ( V_7 , L_76
L_77 ) ;
} else {
V_96 = sprintf ( V_7 , L_78
L_79 ) ;
}
F_43 ( & V_83 -> V_116 ) ;
return V_96 ;
}
static T_1 F_53 (
struct V_82 * V_83 , char * V_7 )
{
return sprintf ( V_7 , L_80 , V_83 -> V_120 . V_121 ) ;
}
static T_1 F_54 (
struct V_82 * V_83 , char * V_7 )
{
struct V_101 * V_102 ;
struct V_122 * V_123 ;
struct V_124 * V_109 ;
struct V_103 * V_104 ;
const struct V_35 * V_36 ;
T_1 V_96 = 0 ;
F_41 ( & V_83 -> V_116 ) ;
V_104 = V_83 -> V_107 ;
if ( ! V_104 ) {
V_96 = sprintf ( V_7 , L_71 ) ;
goto V_125;
}
V_102 = V_104 -> V_108 ;
V_109 = V_102 -> V_109 ;
V_123 = V_104 -> V_126 ;
V_36 = V_109 -> V_110 ;
V_96 += sprintf ( V_7 + V_96 , L_81
L_82 , V_36 -> V_38 () ,
V_36 -> V_40 ( V_109 ) ) ;
V_96 += sprintf ( V_7 + V_96 , L_83
L_84
L_85 , V_123 -> V_127 -> V_128 ,
V_36 -> V_38 () , V_36 -> V_41 ( V_109 ) ,
V_36 -> V_38 () , V_123 -> V_129 ) ;
V_125:
F_43 ( & V_83 -> V_116 ) ;
return V_96 ;
}
static T_1 F_55 (
struct V_82 * V_83 , char * V_7 )
{
const struct V_35 * V_36 ;
struct V_103 * V_104 ;
unsigned char V_85 [ 384 ] ;
char V_105 [ V_106 ] ;
T_1 V_96 = 0 ;
int V_130 = 0 ;
V_96 += sprintf ( V_7 + V_96 , L_86 ) ;
F_41 ( & V_83 -> V_120 . V_131 ) ;
F_8 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_85 , 0 , 384 ) ;
memset ( V_105 , 0 , V_106 ) ;
V_36 = V_104 -> V_108 -> V_109 -> V_110 ;
F_49 ( V_104 , V_105 ,
V_106 ) ;
sprintf ( V_85 , L_87 ,
V_36 -> V_38 () ,
V_104 -> V_108 -> V_111 , V_105 , V_104 -> V_132 ,
V_104 -> V_133 ) ;
if ( V_96 + strlen ( V_85 ) >= V_99 )
break;
V_96 += sprintf ( V_7 + V_96 , L_62 , V_85 ) ;
V_130 ++ ;
}
F_43 ( & V_83 -> V_120 . V_131 ) ;
if ( ! V_130 )
V_96 += sprintf ( V_7 + V_96 , L_88 ) ;
return V_96 ;
}
static T_1 F_56 (
struct V_82 * V_83 , char * V_7 )
{
struct V_103 * V_104 ;
T_1 V_96 = 0 ;
F_41 ( & V_83 -> V_116 ) ;
V_104 = V_83 -> V_107 ;
if ( V_104 ) {
V_96 = sprintf ( V_7 , L_89 ,
F_57 ( V_104 -> V_134 ) ) ;
} else {
V_96 = sprintf ( V_7 , L_71 ) ;
}
F_43 ( & V_83 -> V_116 ) ;
return V_96 ;
}
static T_1 F_58 (
struct V_82 * V_83 , char * V_7 )
{
if ( V_83 -> V_113 -> V_114 & V_115 )
return sprintf ( V_7 , L_90 ) ;
else if ( V_83 -> V_117 & V_118 )
return sprintf ( V_7 , L_91 ) ;
else
return sprintf ( V_7 , L_92 ) ;
}
static T_1 F_59 (
struct V_82 * V_83 , char * V_7 )
{
if ( V_83 -> V_113 -> V_114 & V_115 )
return 0 ;
return sprintf ( V_7 , L_93 ,
( V_83 -> V_120 . V_135 ) ? L_94 : L_95 ) ;
}
static T_1 F_60 (
struct V_82 * V_83 , char * V_7 )
{
if ( V_83 -> V_113 -> V_114 & V_115 )
return 0 ;
return sprintf ( V_7 , L_96 ) ;
}
static T_1 F_61 (
struct V_82 * V_83 ,
const char * V_7 ,
T_2 V_81 )
{
unsigned char * V_136 = NULL , * V_137 = NULL , * V_138 = NULL ;
unsigned char * V_139 = NULL , * V_140 = NULL ;
char * V_141 , * V_142 , * V_143 ;
T_3 args [ V_144 ] ;
unsigned long long V_145 ;
T_4 V_146 = 0 ;
T_5 V_147 = 0 , V_148 = 0 ;
int V_20 = - 1 , V_149 = 0 , V_150 = 0 , V_151 , V_152 ;
T_6 V_153 = 0 , V_154 = 0 ;
T_7 type = 0 , V_155 ;
if ( V_83 -> V_113 -> V_114 & V_115 )
return 0 ;
if ( V_83 -> V_117 & V_118 )
return 0 ;
if ( V_83 -> V_91 ) {
F_12 ( L_97
L_98 ) ;
return - V_21 ;
}
V_143 = F_62 ( V_7 , V_70 ) ;
if ( ! V_143 )
return - V_72 ;
V_141 = V_143 ;
while ( ( V_142 = F_63 ( & V_143 , L_99 ) ) != NULL ) {
if ( ! * V_142 )
continue;
V_152 = F_64 ( V_142 , V_156 , args ) ;
switch ( V_152 ) {
case V_157 :
V_136 = F_65 ( args ) ;
if ( ! V_136 ) {
V_20 = - V_72 ;
goto V_158;
}
break;
case V_159 :
V_137 = F_65 ( args ) ;
if ( ! V_137 ) {
V_20 = - V_72 ;
goto V_158;
}
if ( strlen ( V_137 ) >= V_160 ) {
F_25 ( L_100
L_101 ,
V_160 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_161 :
V_138 = F_65 ( args ) ;
if ( ! V_138 ) {
V_20 = - V_72 ;
goto V_158;
}
if ( strlen ( V_138 ) >= V_162 ) {
F_25 ( L_102
L_103 ,
V_162 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_163 :
V_20 = F_66 ( args -> V_164 , 0 , & V_145 ) ;
if ( V_20 < 0 ) {
F_25 ( L_104 ) ;
goto V_158;
}
V_146 = ( T_4 ) V_145 ;
break;
case V_165 :
F_67 ( args , & V_151 ) ;
V_149 = V_151 ;
break;
case V_166 :
F_67 ( args , & V_151 ) ;
type = ( T_7 ) V_151 ;
break;
case V_167 :
F_67 ( args , & V_151 ) ;
V_155 = ( T_7 ) V_151 ;
break;
case V_168 :
F_67 ( args , & V_151 ) ;
V_150 = ( int ) V_151 ;
break;
case V_169 :
F_67 ( args , & V_151 ) ;
V_147 = ( T_5 ) V_151 ;
break;
case V_170 :
V_139 = F_65 ( args ) ;
if ( ! V_139 ) {
V_20 = - V_72 ;
goto V_158;
}
break;
case V_171 :
V_140 = F_65 ( args ) ;
if ( ! V_140 ) {
V_20 = - V_72 ;
goto V_158;
}
if ( strlen ( V_140 ) >= V_172 ) {
F_25 ( L_105
L_106 ,
V_172 ) ;
V_20 = - V_21 ;
break;
}
break;
case V_173 :
F_67 ( args , & V_151 ) ;
V_154 = ( T_6 ) V_151 ;
break;
case V_174 :
F_67 ( args , & V_151 ) ;
V_153 = ( T_6 ) V_151 ;
break;
case V_175 :
F_67 ( args , & V_151 ) ;
V_148 = ( T_5 ) V_151 ;
break;
default:
break;
}
}
if ( ! V_137 || ! V_140 || ! V_146 ) {
F_25 ( L_107 ) ;
V_20 = - V_21 ;
goto V_158;
}
if ( V_149 && ! ( type ) ) {
F_25 ( L_108
L_109 , type ) ;
V_20 = - V_21 ;
goto V_158;
}
V_20 = F_68 ( & V_83 -> V_120 , V_146 ,
V_137 , V_138 , V_147 , V_140 , V_154 , V_148 ,
V_149 , V_150 , type ) ;
V_158:
F_36 ( V_136 ) ;
F_36 ( V_137 ) ;
F_36 ( V_138 ) ;
F_36 ( V_139 ) ;
F_36 ( V_140 ) ;
F_36 ( V_141 ) ;
return ( V_20 == 0 ) ? V_81 : V_20 ;
}
static T_1 F_69 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
struct V_177 * V_78 = V_83 -> V_113 ;
int V_178 = 0 ;
T_1 V_179 = 0 ;
F_70 ( V_83 , V_7 , & V_178 ) ;
V_179 += V_178 ;
V_179 += V_78 -> V_180 ( V_83 , V_7 + V_179 ) ;
return V_179 ;
}
static T_1 F_71 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
struct V_177 * V_78 = V_83 -> V_113 ;
return V_78 -> V_181 ( V_83 , V_7 , V_81 ) ;
}
static T_1 F_72 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
if ( ! ( V_83 -> V_87 & V_182 ) )
return 0 ;
return snprintf ( V_7 , V_99 , L_110 , V_83 -> V_183 ) ;
}
static T_1 F_73 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
struct V_1 * V_184 = V_83 -> V_1 ;
T_1 V_179 ;
if ( V_81 > ( V_185 - 1 ) ) {
F_25 ( L_111
L_112 , ( int ) V_81 ,
V_185 - 1 ) ;
return - V_21 ;
}
V_179 = snprintf ( & V_83 -> V_183 [ 0 ] , V_185 , L_62 , V_7 ) ;
if ( ! V_179 )
return - V_21 ;
if ( V_83 -> V_183 [ V_179 - 1 ] == '\n' )
V_83 -> V_183 [ V_179 - 1 ] = '\0' ;
V_83 -> V_87 |= V_182 ;
F_12 ( L_113 ,
F_17 ( & V_184 -> V_4 . V_29 ) ,
F_17 ( & V_83 -> V_186 . V_29 ) ,
V_83 -> V_183 ) ;
return V_179 ;
}
static T_1 F_74 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
if ( ! ( V_83 -> V_87 & V_187 ) )
return 0 ;
return snprintf ( V_7 , V_99 , L_110 , V_83 -> V_188 ) ;
}
static T_1 F_75 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
struct V_1 * V_184 = V_83 -> V_1 ;
T_1 V_179 ;
if ( V_81 > ( V_189 - 1 ) ) {
F_25 ( L_114
L_115 , ( int ) V_81 ,
V_189 - 1 ) ;
return - V_21 ;
}
V_179 = snprintf ( & V_83 -> V_188 [ 0 ] , V_189 ,
L_62 , V_7 ) ;
if ( ! V_179 )
return - V_21 ;
if ( V_83 -> V_188 [ V_179 - 1 ] == '\n' )
V_83 -> V_188 [ V_179 - 1 ] = '\0' ;
V_83 -> V_87 |= V_187 ;
F_12 ( L_116 ,
F_17 ( & V_184 -> V_4 . V_29 ) ,
F_17 ( & V_83 -> V_186 . V_29 ) ,
V_83 -> V_188 ) ;
return V_179 ;
}
static T_1 F_76 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
return snprintf ( V_7 , V_99 , L_117 , ! ! ( V_83 -> V_87 & V_190 ) ) ;
}
static T_1 F_77 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
char * V_142 ;
int V_20 ;
V_142 = strstr ( V_7 , L_118 ) ;
if ( ! V_142 ) {
F_25 ( L_119
L_120 ) ;
return - V_21 ;
}
V_20 = F_78 ( V_83 ) ;
if ( V_20 )
return V_20 ;
return V_81 ;
}
static T_1 F_79 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
struct V_2 * V_191 ;
struct V_192 * V_193 ;
struct V_194 * V_195 ;
T_1 V_96 = 0 ;
V_195 = V_83 -> V_196 ;
if ( ! V_195 )
return 0 ;
F_41 ( & V_195 -> V_197 ) ;
V_193 = V_195 -> V_193 ;
if ( V_193 ) {
V_191 = & V_193 -> V_198 . V_29 ;
V_96 += sprintf ( V_7 , L_121 ,
F_17 ( V_191 ) , V_193 -> V_199 ) ;
}
F_43 ( & V_195 -> V_197 ) ;
return V_96 ;
}
static T_1 F_80 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
struct V_1 * V_184 = V_83 -> V_1 ;
struct V_192 * V_193 = NULL , * V_200 = NULL ;
struct V_194 * V_195 ;
unsigned char V_85 [ V_201 ] ;
int V_202 = 0 ;
V_195 = V_83 -> V_196 ;
if ( ! V_195 )
return 0 ;
if ( V_81 > V_201 ) {
F_25 ( L_122 ) ;
return - V_21 ;
}
memset ( V_85 , 0 , V_201 ) ;
memcpy ( V_85 , V_7 , V_81 ) ;
if ( strcmp ( F_39 ( V_85 ) , L_123 ) ) {
V_200 = F_81 ( F_39 ( V_85 ) ) ;
if ( ! V_200 )
return - V_203 ;
}
F_41 ( & V_195 -> V_197 ) ;
V_193 = V_195 -> V_193 ;
if ( V_193 ) {
if ( ! V_200 ) {
F_12 ( L_124
L_125
L_126 ,
F_17 ( & V_184 -> V_4 . V_29 ) ,
F_17 ( & V_83 -> V_186 . V_29 ) ,
F_17 ( & V_193 -> V_198 . V_29 ) ,
V_193 -> V_199 ) ;
F_82 ( V_195 , V_193 ) ;
F_43 ( & V_195 -> V_197 ) ;
return V_81 ;
}
F_82 ( V_195 , V_193 ) ;
V_202 = 1 ;
}
F_83 ( V_195 , V_200 ) ;
F_43 ( & V_195 -> V_197 ) ;
F_12 ( L_127
L_128 ,
( V_202 ) ? L_129 : L_130 ,
F_17 ( & V_184 -> V_4 . V_29 ) ,
F_17 ( & V_83 -> V_186 . V_29 ) ,
F_17 ( & V_200 -> V_198 . V_29 ) ,
V_200 -> V_199 ) ;
F_84 ( V_200 ) ;
return V_81 ;
}
static T_1 F_85 ( void * V_176 , char * V_7 )
{
struct V_82 * V_83 = V_176 ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
char * V_208 = V_7 ;
int V_178 = 0 ;
char V_209 ;
F_41 ( & V_83 -> V_210 . V_211 ) ;
if ( ! F_86 ( & V_83 -> V_210 . V_212 ) )
V_178 += sprintf ( V_208 + V_178 , L_131 ,
V_83 -> V_210 . V_213 ,
V_83 -> V_210 . V_214 ) ;
F_8 (map, &dev->t10_alua.lba_map_list, lba_map_list) {
V_178 += sprintf ( V_208 + V_178 , L_132 ,
V_205 -> V_215 , V_205 -> V_216 ) ;
F_8 (mem, &map->lba_map_mem_list,
lba_map_mem_list) {
switch ( V_207 -> V_217 ) {
case V_218 :
V_209 = 'O' ;
break;
case V_219 :
V_209 = 'A' ;
break;
case V_220 :
V_209 = 'S' ;
break;
case V_221 :
V_209 = 'U' ;
break;
default:
V_209 = '.' ;
break;
}
V_178 += sprintf ( V_208 + V_178 , L_133 ,
V_207 -> V_222 , V_209 ) ;
}
V_178 += sprintf ( V_208 + V_178 , L_3 ) ;
}
F_43 ( & V_83 -> V_210 . V_211 ) ;
return V_178 ;
}
static T_1 F_87 (
void * V_176 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_176 ;
struct V_204 * V_223 = NULL ;
struct V_224 V_225 ;
char * V_226 , * V_142 ;
char V_209 ;
int V_227 = - 1 , V_228 ;
int V_20 = 0 , V_229 = 0 , V_230 , V_231 ;
unsigned long V_232 = - 1 , V_233 = - 1 ;
unsigned long V_234 = - 1 , V_235 = - 1 ;
V_226 = F_62 ( V_7 , V_70 ) ;
if ( ! V_226 )
return - V_72 ;
F_28 ( & V_225 ) ;
while ( ( V_142 = F_63 ( & V_226 , L_3 ) ) != NULL ) {
if ( ! * V_142 )
continue;
if ( V_229 == 0 ) {
if ( sscanf ( V_142 , L_134 ,
& V_234 , & V_235 ) != 2 ) {
F_25 ( L_135 , V_229 ) ;
V_20 = - V_21 ;
break;
}
V_229 ++ ;
continue;
}
if ( sscanf ( V_142 , L_136 , & V_232 , & V_233 ) != 2 ) {
F_25 ( L_135 , V_229 ) ;
V_20 = - V_21 ;
break;
}
V_142 = strchr ( V_142 , ' ' ) ;
if ( ! V_142 ) {
F_25 ( L_137 , V_229 ) ;
V_20 = - V_21 ;
break;
}
V_142 ++ ;
V_142 = strchr ( V_142 , ' ' ) ;
if ( ! V_142 ) {
F_25 ( L_138 ,
V_229 ) ;
V_20 = - V_21 ;
break;
}
V_142 ++ ;
V_223 = F_88 ( & V_225 ,
V_232 , V_233 ) ;
if ( F_89 ( V_223 ) ) {
V_20 = F_90 ( V_223 ) ;
break;
}
V_228 = 0 ;
while ( sscanf ( V_142 , L_139 , & V_230 , & V_209 ) == 2 ) {
switch ( V_209 ) {
case 'O' :
V_231 = V_218 ;
break;
case 'A' :
V_231 = V_219 ;
break;
case 'S' :
V_231 = V_220 ;
break;
case 'U' :
V_231 = V_221 ;
break;
default:
F_25 ( L_140 , V_209 ) ;
V_20 = - V_21 ;
goto V_158;
}
V_20 = F_91 ( V_223 ,
V_230 , V_231 ) ;
if ( V_20 ) {
F_25 ( L_141
L_142 ,
V_230 , V_209 , V_229 ) ;
break;
}
V_228 ++ ;
V_142 = strchr ( V_142 , ' ' ) ;
if ( V_142 )
V_142 ++ ;
else
break;
}
if ( V_227 == - 1 )
V_227 = V_228 ;
else if ( V_228 != V_227 ) {
F_25 ( L_143
L_142 , V_228 , V_227 , V_229 ) ;
V_20 = - V_21 ;
break;
}
V_229 ++ ;
}
V_158:
if ( V_20 ) {
F_92 ( & V_225 ) ;
V_81 = V_20 ;
} else
F_93 ( V_83 , & V_225 ,
V_234 , V_235 ) ;
F_36 ( V_226 ) ;
return V_81 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_18 * V_236 = F_3 ( V_3 ) ;
struct V_82 * V_83 =
F_2 ( V_236 , struct V_82 , V_186 ) ;
F_36 ( V_236 -> V_25 ) ;
F_95 ( V_83 ) ;
}
static T_1 F_96 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
char * V_7 )
{
struct V_18 * V_236 = F_3 ( V_3 ) ;
struct V_82 * V_83 =
F_2 ( V_236 , struct V_82 , V_186 ) ;
struct V_237 * V_238 = F_2 (
V_6 , struct V_237 , V_6 ) ;
if ( ! V_238 -> V_239 )
return - V_21 ;
return V_238 -> V_239 ( V_83 , V_7 ) ;
}
static T_1 F_97 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
const char * V_7 , T_2 V_81 )
{
struct V_18 * V_236 = F_3 ( V_3 ) ;
struct V_82 * V_83 =
F_2 ( V_236 , struct V_82 , V_186 ) ;
struct V_237 * V_238 = F_2 (
V_6 , struct V_237 , V_6 ) ;
if ( ! V_238 -> V_240 )
return - V_21 ;
return V_238 -> V_240 ( V_83 , V_7 , V_81 ) ;
}
static T_1 F_98 (
struct V_192 * V_193 ,
char * V_7 )
{
if ( ! V_193 -> V_241 )
return 0 ;
return sprintf ( V_7 , L_144 , V_193 -> V_199 ) ;
}
static T_1 F_99 (
struct V_192 * V_193 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_18 * V_242 = & V_193 -> V_198 ;
unsigned long V_199 ;
int V_20 ;
V_20 = F_100 ( V_7 , 0 , & V_199 ) ;
if ( V_20 < 0 ) {
F_25 ( L_145
L_146 , V_20 ) ;
return V_20 ;
}
if ( V_199 > 0x0000ffff ) {
F_25 ( L_147
L_148 , V_199 ) ;
return - V_21 ;
}
V_20 = F_101 ( V_193 , ( T_6 ) V_199 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_149
L_150 ,
F_17 ( & V_242 -> V_29 ) ,
V_193 -> V_199 ) ;
return V_81 ;
}
static T_1 F_102 (
struct V_192 * V_193 ,
char * V_7 )
{
struct V_82 * V_83 ;
struct V_1 * V_184 ;
struct V_194 * V_195 ;
T_1 V_96 = 0 , V_243 ;
unsigned char V_85 [ V_201 ] ;
memset ( V_85 , 0 , V_201 ) ;
F_41 ( & V_193 -> V_244 ) ;
F_8 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_83 = V_195 -> V_245 ;
V_184 = V_83 -> V_1 ;
V_243 = snprintf ( V_85 , V_201 , L_151 ,
F_17 ( & V_184 -> V_4 . V_29 ) ,
F_17 ( & V_83 -> V_186 . V_29 ) ) ;
V_243 ++ ;
if ( ( V_243 + V_96 ) > V_99 ) {
F_103 ( L_152
L_153 ) ;
break;
}
memcpy ( V_7 + V_96 , V_85 , V_243 ) ;
V_96 += V_243 ;
}
F_43 ( & V_193 -> V_244 ) ;
return V_96 ;
}
static void F_104 ( struct V_2 * V_3 )
{
struct V_192 * V_193 = F_2 ( F_3 ( V_3 ) ,
struct V_192 , V_198 ) ;
F_105 ( V_193 ) ;
}
static struct V_18 * F_106 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_192 * V_193 ;
struct V_18 * V_242 = NULL ;
struct V_2 * V_246 = NULL ;
V_193 = F_107 ( V_13 , 0 ) ;
if ( F_89 ( V_193 ) )
return NULL ;
V_242 = & V_193 -> V_198 ;
V_246 = & V_242 -> V_29 ;
F_15 ( V_242 , V_13 ,
& V_247 ) ;
F_12 ( L_154
L_155 ,
F_17 ( V_246 ) ) ;
return V_242 ;
}
static void F_108 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_192 * V_193 = F_2 ( F_3 ( V_3 ) ,
struct V_192 , V_198 ) ;
F_12 ( L_156
L_157 ,
F_17 ( V_3 ) , V_193 -> V_199 ) ;
F_19 ( V_3 ) ;
}
static T_1 F_109 (
struct V_248 * V_249 ,
char * V_7 )
{
return sprintf ( V_7 , L_117 ,
F_34 ( & V_249 -> V_250 ) ) ;
}
static T_1 F_110 (
struct V_248 * V_249 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_82 * V_83 = V_249 -> V_251 ;
unsigned long V_252 ;
int V_253 , V_20 ;
if ( ! V_249 -> V_254 ) {
F_25 ( L_158
L_159 , V_249 -> V_254 ) ;
return - V_21 ;
}
if ( ! ( V_83 -> V_87 & V_190 ) ) {
F_25 ( L_160
L_161 ) ;
return - V_203 ;
}
V_20 = F_100 ( V_7 , 0 , & V_252 ) ;
if ( V_20 < 0 ) {
F_25 ( L_162
L_5 , V_7 ) ;
return V_20 ;
}
V_253 = ( int ) V_252 ;
if ( ! ( V_249 -> V_255 & V_256 ) ) {
F_25 ( L_163
L_164 ) ;
return - V_21 ;
}
if ( V_249 -> V_255 & V_257 &&
V_253 == V_258 ) {
F_25 ( L_165
L_166 ) ;
return - V_21 ;
}
V_20 = F_111 ( V_249 , V_83 ,
NULL , NULL , V_253 , 0 ) ;
return ( ! V_20 ) ? V_81 : - V_21 ;
}
static T_1 F_112 (
struct V_248 * V_249 ,
char * V_7 )
{
return sprintf ( V_7 , L_110 ,
F_113 ( V_249 -> V_259 ) ) ;
}
static T_1 F_114 (
struct V_248 * V_249 ,
const char * V_7 ,
T_2 V_81 )
{
unsigned long V_252 ;
int V_260 , V_20 ;
if ( ! V_249 -> V_254 ) {
F_25 ( L_167
L_168 ,
V_249 -> V_254 ) ;
return - V_21 ;
}
V_20 = F_100 ( V_7 , 0 , & V_252 ) ;
if ( V_20 < 0 ) {
F_25 ( L_169
L_170 , V_7 ) ;
return V_20 ;
}
V_260 = ( int ) V_252 ;
if ( ( V_260 != V_261 ) &&
( V_260 != V_262 ) &&
( V_260 != V_263 ) ) {
F_25 ( L_171 ,
V_260 ) ;
return - V_21 ;
}
V_249 -> V_259 = V_260 ;
return V_81 ;
}
static T_1 F_115 (
struct V_248 * V_249 ,
char * V_7 )
{
return F_116 ( V_249 , V_7 ) ;
}
static T_1 F_117 (
struct V_248 * V_249 ,
const char * V_7 ,
T_2 V_81 )
{
return F_118 ( V_249 , V_7 , V_81 ) ;
}
static T_1 F_119 (
struct V_248 * V_249 ,
char * V_7 )
{
return sprintf ( V_7 , L_117 , V_249 -> V_264 ) ;
}
static T_1 F_120 (
struct V_248 * V_249 ,
const char * V_7 ,
T_2 V_81 )
{
unsigned long V_252 ;
int V_20 ;
V_20 = F_100 ( V_7 , 0 , & V_252 ) ;
if ( V_20 < 0 ) {
F_25 ( L_172 ) ;
return V_20 ;
}
if ( ( V_252 != 0 ) && ( V_252 != 1 ) ) {
F_25 ( L_173
L_174 , V_252 ) ;
return - V_21 ;
}
V_249 -> V_264 = ( int ) V_252 ;
return V_81 ;
}
static T_1 F_121 (
struct V_248 * V_249 ,
char * V_7 )
{
return F_122 ( V_249 , V_7 ) ;
}
static T_1 F_123 (
struct V_248 * V_249 ,
const char * V_7 ,
T_2 V_81 )
{
return F_124 ( V_249 , V_7 , V_81 ) ;
}
static T_1 F_125 (
struct V_248 * V_249 ,
char * V_7 )
{
return F_126 ( V_249 , V_7 ) ;
}
static T_1 F_127 (
struct V_248 * V_249 ,
const char * V_7 ,
T_2 V_81 )
{
return F_128 ( V_249 , V_7 , V_81 ) ;
}
static T_1 F_129 (
struct V_248 * V_249 ,
char * V_7 )
{
return F_130 ( V_249 , V_7 ) ;
}
static T_1 F_131 (
struct V_248 * V_249 ,
const char * V_7 ,
T_2 V_81 )
{
return F_132 ( V_249 , V_7 , V_81 ) ;
}
static T_1 F_133 (
struct V_248 * V_249 ,
char * V_7 )
{
return F_134 ( V_249 , V_7 ) ;
}
static T_1 F_135 (
struct V_248 * V_249 ,
const char * V_7 ,
T_2 V_81 )
{
return F_136 ( V_249 , V_7 , V_81 ) ;
}
static T_1 F_137 (
struct V_248 * V_249 ,
char * V_7 )
{
if ( ! V_249 -> V_254 )
return 0 ;
return sprintf ( V_7 , L_144 , V_249 -> V_265 ) ;
}
static T_1 F_138 (
struct V_248 * V_249 ,
const char * V_7 ,
T_2 V_81 )
{
struct V_18 * V_266 = & V_249 -> V_267 ;
unsigned long V_265 ;
int V_20 ;
V_20 = F_100 ( V_7 , 0 , & V_265 ) ;
if ( V_20 < 0 ) {
F_25 ( L_145
L_175 , V_20 ) ;
return V_20 ;
}
if ( V_265 > 0x0000ffff ) {
F_25 ( L_176
L_148 , V_265 ) ;
return - V_21 ;
}
V_20 = F_139 ( V_249 , ( T_6 ) V_265 ) ;
if ( V_20 < 0 )
return - V_21 ;
F_12 ( L_177
L_178 ,
F_17 ( & V_266 -> V_29 ) ,
V_249 -> V_265 ) ;
return V_81 ;
}
static T_1 F_140 (
struct V_248 * V_249 ,
char * V_7 )
{
struct V_268 * V_269 ;
struct V_124 * V_270 ;
struct V_122 * V_123 ;
struct V_271 * V_272 ;
T_1 V_96 = 0 , V_243 ;
unsigned char V_85 [ V_273 ] ;
memset ( V_85 , 0 , V_273 ) ;
F_41 ( & V_249 -> V_274 ) ;
F_8 (tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
V_269 = V_272 -> V_275 ;
V_270 = V_269 -> V_276 ;
V_123 = V_269 -> V_277 ;
V_243 = snprintf ( V_85 , V_273 , L_179
L_180 , V_270 -> V_110 -> V_38 () ,
V_270 -> V_110 -> V_40 ( V_270 ) ,
V_270 -> V_110 -> V_41 ( V_270 ) ,
F_17 ( & V_123 -> V_278 . V_29 ) ) ;
V_243 ++ ;
if ( ( V_243 + V_96 ) > V_99 ) {
F_103 ( L_152
L_153 ) ;
break;
}
memcpy ( V_7 + V_96 , V_85 , V_243 ) ;
V_96 += V_243 ;
}
F_43 ( & V_249 -> V_274 ) ;
return V_96 ;
}
static void F_141 ( struct V_2 * V_3 )
{
struct V_248 * V_249 = F_2 ( F_3 ( V_3 ) ,
struct V_248 , V_267 ) ;
F_142 ( V_249 ) ;
}
static struct V_18 * F_143 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_210 * V_279 = F_2 ( V_19 , struct V_210 ,
V_280 ) ;
struct V_248 * V_249 ;
struct V_18 * V_266 = NULL ;
struct V_2 * V_281 = NULL ;
V_249 = F_144 ( V_279 -> V_84 , V_13 , 0 ) ;
if ( ! V_249 )
return NULL ;
V_266 = & V_249 -> V_267 ;
V_281 = & V_266 -> V_29 ;
F_15 ( V_266 , V_13 ,
& V_282 ) ;
F_12 ( L_181
L_182 ,
F_17 ( V_281 ) ) ;
return V_266 ;
}
static void F_145 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_248 * V_249 = F_2 ( F_3 ( V_3 ) ,
struct V_248 , V_267 ) ;
F_12 ( L_183
L_184 ,
F_17 ( V_3 ) , V_249 -> V_265 ) ;
F_19 ( V_3 ) ;
}
static struct V_18 * F_146 (
struct V_18 * V_19 ,
const char * V_13 )
{
return F_14 ( - V_100 ) ;
}
static void F_147 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
return;
}
static struct V_18 * F_148 (
struct V_18 * V_19 ,
const char * V_13 )
{
struct V_248 * V_249 ;
struct V_177 * V_78 ;
struct V_2 * V_283 = & V_19 -> V_29 ;
struct V_1 * V_184 = F_1 ( V_283 ) ;
struct V_82 * V_83 ;
struct V_18 * V_236 = NULL , * V_284 = NULL ;
struct V_18 * V_285 = NULL ;
int V_286 = - V_72 , V_20 ;
V_20 = F_149 ( & V_184 -> V_287 ) ;
if ( V_20 )
return F_14 ( V_20 ) ;
V_78 = V_184 -> V_113 ;
V_83 = F_150 ( V_184 , V_13 ) ;
if ( ! V_83 )
goto V_125;
V_236 = & V_83 -> V_186 ;
V_236 -> V_25 = F_151 ( sizeof( struct V_18 * ) * 6 ,
V_70 ) ;
if ( ! V_236 -> V_25 )
goto V_288;
F_15 ( V_236 , V_13 , & V_78 -> V_289 . V_290 ) ;
F_15 ( & V_83 -> V_291 . V_292 , L_185 ,
& V_78 -> V_289 . V_293 ) ;
F_15 ( & V_83 -> V_294 , L_186 ,
& V_78 -> V_289 . V_295 ) ;
F_15 ( & V_83 -> V_79 . V_296 , L_187 ,
& V_78 -> V_289 . V_297 ) ;
F_15 ( & V_83 -> V_210 . V_280 ,
L_188 , & V_78 -> V_289 . V_298 ) ;
F_15 ( & V_83 -> V_299 . V_300 ,
L_189 , & V_78 -> V_289 . V_301 ) ;
V_236 -> V_25 [ 0 ] = & V_83 -> V_291 . V_292 ;
V_236 -> V_25 [ 1 ] = & V_83 -> V_294 ;
V_236 -> V_25 [ 2 ] = & V_83 -> V_79 . V_296 ;
V_236 -> V_25 [ 3 ] = & V_83 -> V_210 . V_280 ;
V_236 -> V_25 [ 4 ] = & V_83 -> V_299 . V_300 ;
V_236 -> V_25 [ 5 ] = NULL ;
V_249 = F_144 ( V_83 , L_190 , 1 ) ;
if ( ! V_249 )
goto V_302;
V_83 -> V_210 . V_303 = V_249 ;
V_284 = & V_83 -> V_210 . V_280 ;
V_284 -> V_25 = F_151 ( sizeof( struct V_18 * ) * 2 ,
V_70 ) ;
if ( ! V_284 -> V_25 ) {
F_25 ( L_191
L_192 ) ;
goto V_304;
}
F_15 ( & V_249 -> V_267 ,
L_190 , & V_282 ) ;
V_284 -> V_25 [ 0 ] = & V_249 -> V_267 ;
V_284 -> V_25 [ 1 ] = NULL ;
V_285 = & V_83 -> V_299 . V_300 ;
V_285 -> V_25 = F_151 ( sizeof( struct V_18 * ) * 4 ,
V_70 ) ;
if ( ! V_285 -> V_25 ) {
F_25 ( L_193 ) ;
goto V_305;
}
F_152 ( V_83 ) ;
F_10 ( & V_184 -> V_287 ) ;
return V_236 ;
V_305:
F_36 ( V_284 -> V_25 ) ;
V_304:
F_142 ( V_249 ) ;
V_302:
F_36 ( V_236 -> V_25 ) ;
V_288:
F_95 ( V_83 ) ;
V_125:
F_10 ( & V_184 -> V_287 ) ;
return F_14 ( V_286 ) ;
}
static void F_153 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_18 * V_236 = F_3 ( V_3 ) ;
struct V_82 * V_83 =
F_2 ( V_236 , struct V_82 , V_186 ) ;
struct V_1 * V_184 ;
struct V_2 * V_32 ;
struct V_18 * V_284 , * V_285 ;
int V_33 ;
V_184 = F_1 ( & V_83 -> V_1 -> V_4 . V_29 ) ;
F_7 ( & V_184 -> V_287 ) ;
V_285 = & V_83 -> V_299 . V_300 ;
for ( V_33 = 0 ; V_285 -> V_25 [ V_33 ] ; V_33 ++ ) {
V_32 = & V_285 -> V_25 [ V_33 ] -> V_29 ;
V_285 -> V_25 [ V_33 ] = NULL ;
F_19 ( V_32 ) ;
}
F_36 ( V_285 -> V_25 ) ;
V_284 = & V_83 -> V_210 . V_280 ;
for ( V_33 = 0 ; V_284 -> V_25 [ V_33 ] ; V_33 ++ ) {
V_32 = & V_284 -> V_25 [ V_33 ] -> V_29 ;
V_284 -> V_25 [ V_33 ] = NULL ;
F_19 ( V_32 ) ;
}
F_36 ( V_284 -> V_25 ) ;
V_83 -> V_210 . V_303 = NULL ;
for ( V_33 = 0 ; V_236 -> V_25 [ V_33 ] ; V_33 ++ ) {
V_32 = & V_236 -> V_25 [ V_33 ] -> V_29 ;
V_236 -> V_25 [ V_33 ] = NULL ;
F_19 ( V_32 ) ;
}
F_19 ( V_3 ) ;
F_10 ( & V_184 -> V_287 ) ;
}
static T_1 F_154 (
struct V_1 * V_184 ,
char * V_7 )
{
return sprintf ( V_7 , L_194 ,
V_184 -> V_306 , V_184 -> V_113 -> V_13 ,
V_9 ) ;
}
static T_1 F_155 ( struct V_1 * V_184 ,
char * V_7 )
{
int V_307 = 0 ;
if ( V_184 -> V_308 & V_309 )
V_307 = 1 ;
return sprintf ( V_7 , L_117 , V_307 ) ;
}
static T_1 F_156 ( struct V_1 * V_184 ,
const char * V_7 , T_2 V_81 )
{
struct V_177 * V_113 = V_184 -> V_113 ;
unsigned long V_310 ;
int V_20 ;
if ( V_113 -> V_311 == NULL )
return - V_21 ;
V_20 = F_100 ( V_7 , 0 , & V_310 ) ;
if ( V_20 < 0 ) {
F_25 ( L_195 , V_20 ) ;
return V_20 ;
}
if ( V_184 -> V_312 ) {
F_25 ( L_196 ) ;
return - V_21 ;
}
V_20 = V_113 -> V_311 ( V_184 , V_310 ) ;
if ( V_20 < 0 )
return - V_21 ;
if ( V_20 > 0 )
V_184 -> V_308 |= V_309 ;
else if ( V_20 == 0 )
V_184 -> V_308 &= ~ V_309 ;
return V_81 ;
}
static void F_157 ( struct V_2 * V_3 )
{
struct V_1 * V_184 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_158 ( V_184 ) ;
}
static struct V_18 * F_159 (
struct V_18 * V_19 ,
const char * V_13 )
{
char * V_313 , * V_314 , * V_315 ;
struct V_1 * V_184 ;
char V_85 [ V_316 ] ;
unsigned long V_317 = 0 ;
int V_20 ;
memset ( V_85 , 0 , V_316 ) ;
if ( strlen ( V_13 ) >= V_316 ) {
F_25 ( L_197
L_198 , ( int ) strlen ( V_13 ) ,
V_316 ) ;
return F_14 ( - V_318 ) ;
}
snprintf ( V_85 , V_316 , L_62 , V_13 ) ;
V_314 = strstr ( V_85 , L_199 ) ;
if ( ! V_314 ) {
F_25 ( L_200 ) ;
return F_14 ( - V_21 ) ;
}
V_313 = V_85 ;
V_315 = strstr ( V_314 + 1 , L_199 ) ;
if ( V_315 ) {
* V_315 = '\0' ;
V_315 ++ ;
V_314 = V_315 ;
} else {
* V_314 = '\0' ;
V_314 ++ ;
}
V_20 = F_100 ( V_314 , 0 , & V_317 ) ;
if ( V_20 < 0 ) {
F_25 ( L_145
L_201 , V_20 ) ;
return F_14 ( V_20 ) ;
}
F_160 () ;
V_184 = F_161 ( V_313 , V_317 , 0 ) ;
if ( F_89 ( V_184 ) )
return F_162 ( V_184 ) ;
F_15 ( & V_184 -> V_4 , V_13 ,
& V_319 ) ;
return & V_184 -> V_4 ;
}
static void F_163 (
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
F_19 ( V_3 ) ;
}
void F_164 ( struct V_177 * V_320 )
{
F_165 ( V_320 ) ;
F_166 ( V_320 ) ;
F_167 ( V_320 ) ;
F_168 ( V_320 ) ;
F_169 ( V_320 ) ;
F_170 ( V_320 ) ;
}
static int T_8 F_171 ( void )
{
struct V_18 * V_321 , * V_322 = NULL , * V_323 = NULL ;
struct V_18 * V_324 = NULL ;
struct V_325 * V_326 = & V_34 ;
struct V_192 * V_193 ;
int V_20 ;
F_12 ( L_202
L_203 V_8 L_3 ,
V_327 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
F_172 ( & V_326 -> V_328 ) ;
F_173 ( & V_326 -> V_329 ) ;
V_20 = F_174 () ;
if ( V_20 < 0 )
return V_20 ;
V_321 = & V_326 -> V_328 ;
V_321 -> V_25 = F_151 ( sizeof( struct V_18 * ) * 2 ,
V_70 ) ;
if ( ! V_321 -> V_25 ) {
F_25 ( L_204 ) ;
V_20 = - V_72 ;
goto V_330;
}
F_15 ( & V_331 ,
L_205 , & V_332 ) ;
V_321 -> V_25 [ 0 ] = & V_331 ;
V_321 -> V_25 [ 1 ] = NULL ;
V_322 = & V_331 ;
V_322 -> V_25 = F_151 ( sizeof( struct V_18 * ) * 2 ,
V_70 ) ;
if ( ! V_322 -> V_25 ) {
F_25 ( L_206 ) ;
V_20 = - V_72 ;
goto V_330;
}
F_15 ( & V_333 ,
L_188 , & V_334 ) ;
V_322 -> V_25 [ 0 ] = & V_333 ;
V_322 -> V_25 [ 1 ] = NULL ;
V_323 = & V_333 ;
V_323 -> V_25 = F_151 ( sizeof( struct V_18 * ) * 2 ,
V_70 ) ;
if ( ! V_323 -> V_25 ) {
F_25 ( L_207 ) ;
V_20 = - V_72 ;
goto V_330;
}
F_15 ( & V_335 ,
L_208 , & V_336 ) ;
V_323 -> V_25 [ 0 ] = & V_335 ;
V_323 -> V_25 [ 1 ] = NULL ;
V_193 = F_107 ( L_209 , 1 ) ;
if ( F_89 ( V_193 ) ) {
V_20 = - V_72 ;
goto V_330;
}
V_324 = & V_335 ;
V_324 -> V_25 = F_151 ( sizeof( struct V_18 * ) * 2 ,
V_70 ) ;
if ( ! V_324 -> V_25 ) {
F_25 ( L_210 ) ;
V_20 = - V_72 ;
goto V_330;
}
F_15 ( & V_193 -> V_198 , L_209 ,
& V_247 ) ;
V_324 -> V_25 [ 0 ] = & V_193 -> V_198 ;
V_324 -> V_25 [ 1 ] = NULL ;
V_337 = V_193 ;
V_20 = F_175 ( V_326 ) ;
if ( V_20 < 0 ) {
F_25 ( L_211 ,
V_20 , V_326 -> V_328 . V_29 . V_338 ) ;
goto V_330;
}
F_12 ( L_212
L_213 V_9 L_214
L_215 V_8 L_3 , F_5 () -> V_10 , F_5 () -> V_11 ) ;
V_20 = F_176 () ;
if ( V_20 < 0 )
goto V_158;
V_20 = F_177 () ;
if ( V_20 < 0 )
goto V_158;
V_20 = F_178 () ;
if ( V_20 < 0 )
goto V_158;
return 0 ;
V_158:
F_179 ( V_326 ) ;
F_180 () ;
F_181 () ;
V_330:
if ( V_337 ) {
F_105 ( V_337 ) ;
V_337 = NULL ;
}
if ( V_324 )
F_36 ( V_324 -> V_25 ) ;
if ( V_323 )
F_36 ( V_323 -> V_25 ) ;
if ( V_322 )
F_36 ( V_322 -> V_25 ) ;
F_36 ( V_321 -> V_25 ) ;
F_182 () ;
return V_20 ;
}
static void T_9 F_183 ( void )
{
struct V_18 * V_322 , * V_323 , * V_324 ;
struct V_2 * V_3 ;
int V_33 ;
V_324 = & V_335 ;
for ( V_33 = 0 ; V_324 -> V_25 [ V_33 ] ; V_33 ++ ) {
V_3 = & V_324 -> V_25 [ V_33 ] -> V_29 ;
V_324 -> V_25 [ V_33 ] = NULL ;
F_19 ( V_3 ) ;
}
F_36 ( V_324 -> V_25 ) ;
V_324 -> V_25 = NULL ;
V_323 = & V_333 ;
for ( V_33 = 0 ; V_323 -> V_25 [ V_33 ] ; V_33 ++ ) {
V_3 = & V_323 -> V_25 [ V_33 ] -> V_29 ;
V_323 -> V_25 [ V_33 ] = NULL ;
F_19 ( V_3 ) ;
}
F_36 ( V_323 -> V_25 ) ;
V_323 -> V_25 = NULL ;
V_322 = & V_331 ;
for ( V_33 = 0 ; V_322 -> V_25 [ V_33 ] ; V_33 ++ ) {
V_3 = & V_322 -> V_25 [ V_33 ] -> V_29 ;
V_322 -> V_25 [ V_33 ] = NULL ;
F_19 ( V_3 ) ;
}
F_36 ( V_322 -> V_25 ) ;
V_322 -> V_25 = NULL ;
F_179 ( & V_34 ) ;
F_36 ( V_34 . V_328 . V_25 ) ;
F_105 ( V_337 ) ;
V_337 = NULL ;
F_12 ( L_216
L_217 ) ;
F_180 () ;
F_181 () ;
F_184 () ;
F_182 () ;
}
