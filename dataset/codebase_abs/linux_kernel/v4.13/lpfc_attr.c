static void
F_1 ( int V_1 , char V_2 [] )
{
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_4 = ( V_1 & 0xf ) ;
if ( V_4 <= 9 )
V_2 [ 7 - V_3 ] = 0x30 + V_4 ;
else
V_2 [ 7 - V_3 ] = 0x61 + V_4 - 10 ;
V_1 = ( V_1 >> 4 ) ;
}
V_2 [ 8 ] = 0 ;
return;
}
static T_1
F_2 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
return snprintf ( V_9 , V_10 , V_11 L_1 ) ;
}
static T_1
F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_19 & V_20 )
return snprintf ( V_9 , V_10 , L_2 ) ;
else
return snprintf ( V_9 , V_10 , L_3 ) ;
}
static T_1
F_5 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
T_2 V_29 , V_30 , V_31 , V_32 ;
char * V_33 ;
int V_34 = 0 ;
if ( ! ( V_18 -> V_35 & V_36 ) ) {
V_34 += snprintf ( V_9 , V_10 , L_4 ) ;
return V_34 ;
}
if ( V_18 -> V_37 ) {
if ( ! V_18 -> V_38 ) {
V_34 = snprintf ( V_9 , V_10 ,
L_5 ,
F_7 ( V_15 -> V_39 . V_40 . V_41 ) ) ;
return V_34 ;
}
if ( V_18 -> V_38 -> V_42 )
V_33 = L_6 ;
else
V_33 = L_7 ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_8 ,
V_33 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_9 ,
L_10 ,
V_18 -> V_43 ,
F_7 ( V_15 -> V_39 . V_40 . V_41 ) ,
F_7 ( V_15 -> V_44 . V_40 . V_41 ) ,
V_18 -> V_38 -> V_42 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_11 ) ;
V_22 = (struct V_21 * ) V_18 -> V_38 -> V_45 ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_12 ,
F_8 ( & V_22 -> V_46 ) ,
F_8 ( & V_22 -> V_47 ) ,
F_8 ( & V_22 -> V_48 ) ) ;
if ( F_8 ( & V_22 -> V_46 ) !=
F_8 ( & V_22 -> V_49 ) ) {
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_13 ,
F_8 ( & V_22 -> V_46 ) ,
F_8 ( & V_22 -> V_49 ) ) ;
}
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_14 ,
F_8 ( & V_22 -> V_50 ) ,
F_8 ( & V_22 -> V_51 ) ,
F_8 ( & V_22 -> V_52 ) ,
F_8 ( & V_22 -> V_53 ) ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_15
L_16 ,
F_8 ( & V_22 -> V_54 ) ,
F_8 ( & V_22 -> V_55 ) ,
F_8 ( & V_22 -> V_56 ) ,
F_8 ( & V_22 -> V_57 ) ) ;
if ( F_8 ( & V_22 -> V_54 ) !=
F_8 ( & V_22 -> V_58 ) ) {
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_17 ,
F_8 ( & V_22 -> V_54 ) ,
F_8 ( & V_22 -> V_58 ) ) ;
}
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_18
L_19 ,
F_8 ( & V_22 -> V_59 ) ,
F_8 ( & V_22 -> V_60 ) ,
F_8 ( & V_22 -> V_61 ) ,
F_8 ( & V_22 -> V_62 ) ,
F_8 ( & V_22 -> V_63 ) ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_20 ,
F_8 ( & V_22 -> V_64 ) ,
F_8 ( & V_22 -> V_65 ) ,
F_8 ( & V_22 -> V_66 ) ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_21 ,
F_8 ( & V_22 -> V_67 ) ,
F_8 ( & V_22 -> V_68 ) ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_22 ,
F_8 ( & V_22 -> V_69 ) ,
F_8 ( & V_22 -> V_70 ) ,
F_8 ( & V_22 -> V_71 ) ,
F_8 ( & V_22 -> V_72 ) ) ;
F_9 ( & V_18 -> V_73 . V_74 ) ;
F_9 ( & V_18 -> V_73 . V_75 ) ;
V_32 = V_18 -> V_73 . V_76 -
( V_18 -> V_73 . V_77 +
V_18 -> V_73 . V_78 ) ;
F_10 ( & V_18 -> V_73 . V_75 ) ;
F_10 ( & V_18 -> V_73 . V_74 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_23
L_24 ,
V_18 -> V_73 . V_76 ,
V_18 -> V_73 . V_79 ,
V_18 -> V_73 . V_80 ,
V_32 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_1 ) ;
return V_34 ;
}
V_24 = V_15 -> V_24 ;
if ( ! V_24 ) {
V_34 = snprintf ( V_9 , V_10 ,
L_25 ,
F_7 ( V_15 -> V_39 . V_40 . V_41 ) ) ;
return V_34 ;
}
V_34 = snprintf ( V_9 , V_10 , L_26 ) ;
F_11 ( V_13 -> V_81 ) ;
if ( V_24 -> V_42 )
V_33 = L_27 ;
else
V_33 = L_28 ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_29 ,
L_30 ,
V_18 -> V_43 ,
F_7 ( V_15 -> V_39 . V_40 . V_41 ) ,
F_7 ( V_15 -> V_44 . V_40 . V_41 ) ,
V_24 -> V_42 , V_33 ) ;
F_12 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! V_26 -> V_28 )
continue;
V_28 = V_26 -> V_28 -> V_82 ;
switch ( V_28 -> V_83 ) {
case V_84 :
V_33 = L_27 ;
break;
case V_85 :
V_33 = L_28 ;
break;
default:
V_33 = L_31 ;
break;
}
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_32 ) ;
if ( V_18 -> V_43 >= 10 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_33 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_34 ,
V_28 -> V_86 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_35 ,
V_28 -> V_87 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_36 ,
V_28 -> V_42 ) ;
if ( V_28 -> V_88 & V_89 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_37 ) ;
if ( V_28 -> V_88 & V_90 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_38 ) ;
if ( V_28 -> V_88 & V_91 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_39 ) ;
if ( V_28 -> V_88 & ~ ( V_89 |
V_90 |
V_91 ) )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_40 ,
V_28 -> V_88 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_41 , V_33 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_1 ) ;
}
F_13 ( V_13 -> V_81 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_42 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_43 ,
F_8 ( & V_18 -> V_92 ) ,
F_8 ( & V_18 -> V_93 ) ) ;
V_32 = F_8 ( & V_18 -> V_94 ) ;
V_29 = F_8 ( & V_18 -> V_95 ) ;
V_30 = F_8 ( & V_18 -> V_96 ) ;
V_31 = F_8 ( & V_18 -> V_97 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_44 ,
V_29 , V_30 , V_31 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_45 ,
V_32 , ( V_29 + V_30 + V_31 ) - V_32 ) ;
return V_34 ;
}
static T_1
F_14 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_98 )
if ( V_18 -> V_99 & V_100 )
return snprintf ( V_9 , V_10 , L_46 ) ;
else
return snprintf ( V_9 , V_10 ,
L_47 ) ;
else
return snprintf ( V_9 , V_10 ,
L_48 ) ;
}
static T_1
F_15 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 ,
( unsigned long long ) V_18 -> V_101 ) ;
}
static T_1
F_16 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 ,
( unsigned long long ) V_18 -> V_102 ) ;
}
static T_1
F_17 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 ,
( unsigned long long ) V_18 -> V_103 ) ;
}
static T_1
F_18 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_104 = F_4 ( V_6 ) ;
return snprintf ( V_9 , V_10 , L_50 , F_19 ( V_104 ) ) ;
}
static T_1
F_20 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_50 , V_18 -> V_105 ) ;
}
static T_1
F_21 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_106 ) ;
}
static T_1
F_22 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_50 , V_18 -> V_107 ) ;
}
static T_1
F_23 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_50 , V_18 -> V_108 ) ;
}
static T_1
F_24 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_50 , V_18 -> V_109 ) ;
}
static T_1
F_25 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 ,
( V_18 -> V_110 . V_111 & V_112 ) ) ;
}
static T_1
F_26 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_50 , V_18 -> V_113 ) ;
}
static T_1
F_27 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_114 ;
T_4 V_115 ;
char V_116 [ V_117 ] ;
int V_34 ;
F_28 ( V_18 , V_116 , 1 ) ;
V_114 = V_18 -> V_73 . V_118 . V_114 ;
V_115 = V_18 -> V_73 . V_118 . V_115 ;
if ( V_18 -> V_119 < V_120 )
V_34 = snprintf ( V_9 , V_10 , L_52 ,
V_116 , V_18 -> V_119 ) ;
else
V_34 = snprintf ( V_9 , V_10 , L_53 ,
V_116 , V_18 -> V_119 , V_114 , V_115 ) ;
return V_34 ;
}
static T_1
F_29 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
char V_2 [ 9 ] ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 * V_121 = & V_18 -> V_122 ;
F_1 ( V_121 -> V_123 . V_124 , V_2 ) ;
return snprintf ( V_9 , V_10 , L_50 , V_2 ) ;
}
static T_1
F_30 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char V_116 [ V_117 ] ;
if ( V_18 -> V_119 < V_120 )
return snprintf ( V_9 , V_10 , L_50 , V_18 -> V_125 ) ;
F_28 ( V_18 , V_116 , 1 ) ;
return snprintf ( V_9 , V_10 , L_50 , V_116 ) ;
}
static T_1
F_31 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_34 = 0 ;
switch ( V_18 -> V_126 ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
if ( V_18 -> V_19 & V_133 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_54 ) ;
else
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_55 ) ;
break;
case V_134 :
case V_135 :
case V_136 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_56 ) ;
switch ( V_15 -> V_83 ) {
case V_137 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_57 ) ;
break;
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_58 ) ;
break;
case V_145 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_59 ) ;
break;
case V_146 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_60 ) ;
break;
case V_147 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_61 ) ;
break;
}
if ( V_18 -> V_110 . V_111 & V_112 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_62 ) ;
else if ( V_18 -> V_148 == V_149 ) {
if ( V_15 -> V_150 & V_151 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_63 ) ;
else
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_64 ) ;
} else {
if ( V_15 -> V_150 & V_152 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_65 ) ;
else
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_66 ) ;
}
}
return V_34 ;
}
static T_1
F_32 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_119 < V_120 )
return snprintf ( V_9 , V_10 , L_67 ) ;
if ( V_18 -> V_73 . V_153 . V_154 == V_155 ) {
if ( V_18 -> V_73 . V_153 . V_156 == V_157 )
return snprintf ( V_9 , V_10 , L_68 ) ;
if ( V_18 -> V_73 . V_153 . V_156 == V_158 )
return snprintf ( V_9 , V_10 , L_67 ) ;
}
return snprintf ( V_9 , V_10 , L_69 ) ;
}
static T_1
F_33 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 ,
V_18 -> V_73 . V_118 . V_159 ) ;
}
static T_1
F_34 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_161 = - V_162 ;
if ( ( strncmp ( V_9 , L_70 , sizeof( L_70 ) - 1 ) == 0 ) &&
( V_18 -> V_126 == V_131 ) )
V_161 = V_18 -> V_163 ( V_18 , V_164 ) ;
else if ( ( strncmp ( V_9 , L_71 , sizeof( L_71 ) - 1 ) == 0 ) &&
( V_18 -> V_126 >= V_134 ) )
V_161 = V_18 -> V_165 ( V_18 , V_164 ) ;
if ( V_161 == 0 )
return strlen ( V_9 ) ;
else
return V_161 ;
}
static T_1
F_35 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_51 ,
V_15 -> V_166 + V_15 -> V_167 ) ;
}
static int
F_36 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_7 * V_168 ;
int V_169 = V_170 ;
if ( ( V_15 -> V_150 & V_171 ) ||
( V_18 -> V_110 . V_111 & V_172 ) )
return - V_173 ;
V_168 = F_37 ( V_18 -> V_174 , V_175 ) ;
if ( ! V_168 )
return - V_176 ;
memset ( ( void * ) V_168 , 0 , sizeof ( T_7 ) ) ;
V_168 -> V_40 . V_177 . V_178 = V_179 ;
V_168 -> V_40 . V_177 . V_180 = V_181 ;
V_169 = F_38 ( V_18 , V_168 , V_182 * 2 ) ;
if ( ( V_169 == V_183 ) &&
( V_168 -> V_40 . V_177 . V_184 == 0 ||
V_168 -> V_40 . V_177 . V_184 == V_185 ) ) {
memset ( ( void * ) V_168 , 0 , sizeof ( T_7 ) ) ;
F_39 ( V_18 , V_168 , V_18 -> V_186 ,
V_18 -> V_187 ) ;
V_169 = F_38 ( V_18 , V_168 ,
V_18 -> V_188 * 2 ) ;
if ( ( V_169 == V_183 ) &&
( V_168 -> V_40 . V_177 . V_184 == V_189 ) )
F_40 ( V_18 , V_190 , V_191 | V_192 ,
L_72
L_73 ) ;
}
F_41 ( V_18 ) ;
if ( V_169 != V_193 )
F_42 ( V_168 , V_18 -> V_174 ) ;
if ( V_169 == V_170 )
return - V_194 ;
return 0 ;
}
int
F_43 ( struct V_17 * V_18 , struct V_195 * V_196 , T_8 * V_197 )
{
int V_198 = 0 ;
F_11 ( V_197 ) ;
while ( ! F_44 ( V_196 ) ) {
F_13 ( V_197 ) ;
F_45 ( 20 ) ;
if ( V_198 ++ > 250 ) {
F_40 ( V_18 , V_199 , V_200 ,
L_74 ,
L_75 ,
L_76 ) ;
return 0 ;
}
F_11 ( V_197 ) ;
}
F_13 ( V_197 ) ;
return 1 ;
}
static int
F_46 ( struct V_17 * V_18 , T_3 type )
{
struct V_201 V_202 ;
struct V_203 * V_204 = NULL ;
struct V_205 * V_206 ;
struct V_207 * V_208 ;
int V_161 = 0 ;
int V_3 ;
int V_209 ;
F_47 ( & V_202 ) ;
V_209 = F_48 ( V_18 , & V_161 , & V_202 ,
V_210 ) ;
if ( V_209 == 0 )
return - V_176 ;
F_49 ( & V_202 ) ;
if ( V_161 != 0 )
return - V_194 ;
V_208 = & V_18 -> V_110 ;
if ( V_18 -> V_119 != V_120 ) {
for ( V_3 = 0 ; V_3 < V_208 -> V_211 ; V_3 ++ ) {
V_206 = & V_208 -> V_212 [ V_3 ] ;
if ( ! F_43 ( V_18 , & V_206 -> V_213 ,
& V_18 -> V_214 ) )
goto V_215;
}
} else {
F_12 (qp, &phba->sli4_hba.lpfc_wq_list, wq_list) {
V_206 = V_204 -> V_206 ;
if ( ! V_206 )
continue;
if ( ! F_43 ( V_18 , & V_206 -> V_213 ,
& V_206 -> V_216 ) )
goto V_215;
}
}
V_215:
F_47 ( & V_202 ) ;
V_209 = F_48 ( V_18 , & V_161 , & V_202 , type ) ;
if ( V_209 == 0 )
return - V_176 ;
F_49 ( & V_202 ) ;
if ( V_161 != 0 )
return - V_194 ;
return 0 ;
}
int
F_50 ( struct V_17 * V_18 )
{
struct V_201 V_202 ;
int V_161 = 0 ;
int V_209 ;
if ( ! V_18 -> V_217 )
return - V_218 ;
if ( ! ( V_18 -> V_219 -> V_150 & V_171 ) ) {
V_161 = F_46 ( V_18 , V_220 ) ;
if ( V_161 != 0 )
return V_161 ;
}
F_47 ( & V_202 ) ;
V_209 = F_48 ( V_18 , & V_161 , & V_202 ,
V_221 ) ;
if ( V_209 == 0 )
return - V_176 ;
F_49 ( & V_202 ) ;
if ( V_161 != 0 )
return - V_194 ;
return 0 ;
}
static T_1
F_51 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_161 = - V_162 ;
if ( ! V_18 -> V_217 )
return - V_218 ;
if ( strncmp ( V_9 , L_77 , sizeof( L_77 ) - 1 ) == 0 )
V_161 = V_18 -> F_50 ( V_18 ) ;
if ( V_161 == 0 )
return strlen ( V_9 ) ;
else
return V_161 ;
}
int
F_52 ( struct V_17 * V_18 )
{
struct V_222 V_223 = { 0 } ;
int V_3 ;
F_45 ( 100 ) ;
F_53 ( V_18 -> V_73 . V_40 . V_224 . V_225 ,
& V_223 . V_226 ) ;
if ( ! F_54 ( V_227 , & V_223 ) &&
! F_54 ( V_228 , & V_223 ) )
return - V_173 ;
for ( V_3 = 0 ; V_3 < V_229 ; V_3 ++ ) {
F_45 ( 10 ) ;
F_53 ( V_18 -> V_73 . V_40 . V_224 . V_225 ,
& V_223 . V_226 ) ;
if ( ! F_54 ( V_228 , & V_223 ) )
continue;
if ( ! F_54 ( V_227 , & V_223 ) )
continue;
if ( ! F_54 ( V_230 , & V_223 ) )
continue;
break;
}
if ( V_3 < V_229 )
return 0 ;
else
return - V_194 ;
}
static T_1
F_55 ( struct V_17 * V_18 , T_3 V_231 )
{
struct V_201 V_202 ;
struct V_232 * V_233 = V_18 -> V_234 ;
T_3 V_235 ;
T_3 V_236 ;
T_3 V_237 ;
int V_161 = 0 , V_209 = 0 ;
int V_238 = 1 , V_239 ;
if ( ! V_18 -> V_217 )
return - V_218 ;
if ( ( V_18 -> V_119 < V_120 ) ||
( F_54 ( V_240 , & V_18 -> V_73 . V_241 ) !=
V_242 ) )
return - V_173 ;
V_235 = V_18 -> V_219 -> V_150 ;
V_236 = V_18 -> V_243 ;
if ( V_18 -> V_243 ) {
F_56 ( V_233 ) ;
V_18 -> V_243 = 0 ;
}
if ( V_231 == V_244 )
V_18 -> V_19 |= V_245 ;
V_161 = F_46 ( V_18 , V_220 ) ;
if ( V_161 != 0 ) {
V_18 -> V_19 &= ~ V_245 ;
return V_161 ;
}
F_45 ( 100 ) ;
V_237 = F_57 ( V_18 -> V_73 . V_246 +
V_247 ) ;
if ( V_231 == V_244 )
V_237 |= V_248 ;
else if ( V_231 == V_249 )
V_237 |= V_250 ;
else if ( V_231 == V_251 )
V_237 |= V_252 ;
F_58 ( V_237 , V_18 -> V_73 . V_246 +
V_247 ) ;
F_57 ( V_18 -> V_73 . V_246 + V_247 ) ;
V_209 = F_52 ( V_18 ) ;
if ( V_209 == - V_173 ) {
F_40 ( V_18 , V_190 , V_192 ,
L_78
L_79 , V_237 ) ;
} else if ( V_209 == - V_194 ) {
F_40 ( V_18 , V_190 , V_192 ,
L_80
L_79 , V_237 ) ;
return V_209 ;
}
if ( V_235 & V_171 )
goto V_215;
F_47 ( & V_202 ) ;
V_238 = F_48 ( V_18 , & V_161 , & V_202 ,
V_221 ) ;
if ( ! V_238 )
goto V_215;
F_49 ( & V_202 ) ;
V_215:
if ( V_236 ) {
V_239 =
F_59 ( V_18 , V_236 ) ;
if ( ! V_239 )
V_18 -> V_243 = V_236 ;
}
if ( ! V_209 ) {
if ( ! V_238 )
V_209 = - V_176 ;
else if ( V_161 )
V_209 = - V_194 ;
}
return V_209 ;
}
static T_1
F_60 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_253 ) ;
}
static T_1
F_61 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char * V_254 ;
if ( V_18 -> V_126 == V_132 )
V_254 = L_81 ;
else if ( V_18 -> V_126 == V_128 )
V_254 = L_82 ;
else if ( V_18 -> V_126 == V_129 )
V_254 = L_83 ;
else
V_254 = L_84 ;
return snprintf ( V_9 , V_10 , L_50 , V_254 ) ;
}
static T_1
F_62 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_201 V_202 ;
char * V_255 = NULL ;
int V_161 = 0 ;
int V_209 ;
if ( ! V_18 -> V_217 ) {
V_161 = - V_218 ;
goto V_256;
}
F_63 ( V_15 , V_190 , V_200 ,
L_85 , V_9 ) ;
F_47 ( & V_202 ) ;
if( strncmp ( V_9 , L_84 , sizeof( L_84 ) - 1 ) == 0 ) {
V_209 = F_48 ( V_18 , & V_161 , & V_202 ,
V_221 ) ;
if ( V_209 == 0 ) {
V_161 = - V_176 ;
goto V_256;
}
F_49 ( & V_202 ) ;
if ( V_161 )
V_161 = - V_194 ;
} else if ( strncmp ( V_9 , L_83 , sizeof( L_83 ) - 1 ) == 0 )
V_161 = F_46 ( V_18 , V_220 ) ;
else if ( strncmp ( V_9 , L_86 , sizeof( L_86 ) - 1 ) == 0 )
if ( V_18 -> V_119 == V_120 )
V_161 = - V_162 ;
else
V_161 = F_46 ( V_18 , V_257 ) ;
else if ( strncmp ( V_9 , L_81 , sizeof( L_81 ) - 1 ) == 0 )
if ( V_18 -> V_119 == V_120 )
V_161 = - V_162 ;
else
V_161 = F_46 ( V_18 , V_258 ) ;
else if ( strncmp ( V_9 , L_87 , sizeof( L_87 ) - 1 ) == 0 )
V_161 = F_55 ( V_18 , V_244 ) ;
else if ( strncmp ( V_9 , L_88 , sizeof( L_88 ) - 1 ) == 0 )
V_161 = F_55 ( V_18 , V_249 ) ;
else if ( strncmp ( V_9 , L_89 , sizeof( L_89 ) - 1 ) == 0 )
V_161 = F_55 ( V_18 , V_251 ) ;
else
V_161 = - V_162 ;
V_256:
if ( ! V_161 )
return strlen ( V_9 ) ;
else {
V_255 = strchr ( V_9 , '\n' ) ;
if ( V_255 )
* V_255 = '\0' ;
F_63 ( V_15 , V_190 , V_200 ,
L_90
L_91 ,
V_9 , V_161 , V_18 -> V_219 -> V_150 ) ;
return V_161 ;
}
}
static int
F_64 ( struct V_17 * V_18 ,
T_3 * V_259 , T_3 * V_260 ,
T_3 * V_261 , T_3 * V_262 ,
T_3 * V_263 , T_3 * V_264 )
{
struct V_265 * V_266 ;
T_7 * V_168 ;
T_9 * V_267 ;
int V_209 = 0 ;
T_3 V_268 ;
if ( V_18 -> V_126 < V_131 ||
! V_18 -> V_174 ||
( V_18 -> V_110 . V_111 & V_269 ) == 0 )
return 0 ;
if ( V_18 -> V_110 . V_111 & V_172 )
return 0 ;
V_168 = F_37 ( V_18 -> V_174 , V_175 ) ;
if ( ! V_168 )
return 0 ;
memset ( V_168 , 0 , sizeof ( T_7 ) ) ;
V_267 = & V_168 -> V_40 . V_177 ;
V_267 -> V_178 = V_270 ;
V_267 -> V_180 = V_181 ;
V_168 -> V_271 = NULL ;
if ( V_18 -> V_219 -> V_150 & V_171 )
V_209 = V_272 ;
else
V_209 = F_38 ( V_18 , V_168 , V_18 -> V_188 * 2 ) ;
if ( V_209 != V_183 ) {
if ( V_209 != V_193 )
F_42 ( V_168 , V_18 -> V_174 ) ;
return 0 ;
}
if ( V_18 -> V_119 == V_120 ) {
V_266 = & V_168 -> V_40 . V_273 . V_274 . V_266 ;
if ( V_261 )
* V_261 = F_54 ( V_275 , V_266 ) ;
if ( V_262 )
* V_262 = F_54 ( V_275 , V_266 ) -
V_18 -> V_73 . V_276 . V_277 ;
if ( V_259 )
* V_259 = F_54 ( V_278 , V_266 ) ;
if ( V_260 )
* V_260 = F_54 ( V_278 , V_266 ) -
V_18 -> V_73 . V_276 . V_279 ;
V_268 = ( F_54 ( V_280 , V_266 ) > 0 ) ?
( F_54 ( V_280 , V_266 ) - 1 ) : 0 ;
if ( V_263 )
* V_263 = V_268 ;
if ( V_264 )
* V_264 = V_268 - V_18 -> V_73 . V_276 . V_281 ;
} else {
if ( V_261 )
* V_261 = V_267 -> V_274 . V_282 . V_283 ;
if ( V_262 )
* V_262 = V_267 -> V_274 . V_282 . V_284 ;
if ( V_259 )
* V_259 = V_267 -> V_274 . V_282 . V_285 ;
if ( V_260 )
* V_260 = V_267 -> V_274 . V_282 . V_286 ;
if ( V_263 )
* V_263 = V_267 -> V_274 . V_282 . V_268 ;
if ( V_264 )
* V_264 = V_267 -> V_274 . V_282 . V_287 ;
}
F_42 ( V_168 , V_18 -> V_174 ) ;
return 1 ;
}
static T_1
F_65 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_198 ;
if ( F_64 ( V_18 , NULL , NULL , & V_198 , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_51 , V_198 ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_66 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_198 , V_288 ;
if ( F_64 ( V_18 , NULL , NULL , & V_198 , & V_288 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_51 , ( V_198 - V_288 ) ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_67 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_198 ;
if ( F_64 ( V_18 , & V_198 , NULL , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_51 , V_198 ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_68 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_198 , V_288 ;
if ( F_64 ( V_18 , & V_198 , & V_288 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_51 , ( V_198 - V_288 ) ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_69 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_198 ;
if ( F_64 ( V_18 , NULL , NULL , NULL , NULL , & V_198 , NULL ) )
return snprintf ( V_9 , V_10 , L_51 , V_198 ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_70 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_198 , V_288 ;
if ( F_64 ( V_18 , NULL , NULL , NULL , NULL , & V_198 , & V_288 ) )
return snprintf ( V_9 , V_10 , L_51 , ( V_198 - V_288 ) ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_71 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_268 ) )
return snprintf ( V_9 , V_10 , L_92 ) ;
if ( V_15 -> V_289 == V_290 )
return snprintf ( V_9 , V_10 , L_93 ) ;
return snprintf ( V_9 , V_10 , L_94 , V_15 -> V_291 ) ;
}
static T_1
F_72 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_95 , V_18 -> V_292 ) ;
}
static T_1
F_73 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_293 ;
T_3 V_294 ;
int V_295 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_162 ;
if ( sscanf ( V_9 , L_96 , & V_295 ) != 1 )
return - V_162 ;
if ( ( V_295 & 0x3 ) != V_295 )
return - V_162 ;
if ( V_18 -> V_119 == V_120 )
V_295 = 0 ;
F_63 ( V_15 , V_190 , V_200 ,
L_97 ,
V_18 -> V_292 , V_295 ) ;
F_11 ( & V_18 -> V_214 ) ;
V_294 = V_18 -> V_292 ;
if ( V_295 & V_296 ) {
if ( ( V_295 & V_297 ) &&
! ( V_294 & V_297 ) ) {
if ( F_53 ( V_18 -> V_298 , & V_293 ) ) {
F_13 ( & V_18 -> V_214 ) ;
return - V_162 ;
}
V_293 &= ~ ( V_299 << V_300 ) ;
F_58 ( V_293 , V_18 -> V_298 ) ;
F_57 ( V_18 -> V_298 ) ;
F_74 ( V_18 ) ;
}
} else if ( V_295 != 0x0 ) {
F_13 ( & V_18 -> V_214 ) ;
return - V_162 ;
}
if ( ! ( V_295 & V_297 ) &&
( V_294 & V_297 ) )
{
F_13 ( & V_18 -> V_214 ) ;
F_75 ( & V_18 -> V_301 ) ;
F_11 ( & V_18 -> V_214 ) ;
if ( F_53 ( V_18 -> V_298 , & V_293 ) ) {
F_13 ( & V_18 -> V_214 ) ;
return - V_162 ;
}
V_293 |= ( V_299 << V_300 ) ;
F_58 ( V_293 , V_18 -> V_298 ) ;
F_57 ( V_18 -> V_298 ) ;
}
V_18 -> V_292 = V_295 ;
F_13 ( & V_18 -> V_214 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_76 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_302 ) ;
}
static T_1
F_77 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_303 ) ;
}
static T_1
F_78 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_98 ,
( V_18 -> V_304 ) ? L_99 : L_100 ,
( V_18 -> V_99 & V_305 ) ?
L_101 : L_102 ) ;
}
static T_1
F_79 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_10 V_306 ;
V_306 = F_80 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_51 , V_306 ) ;
}
static inline bool F_81 ( T_11 V_295 , T_11 V_307 , T_11 V_308 )
{
return V_295 >= V_307 && V_295 <= V_308 ;
}
static T_6
F_82 ( const char * V_9 , T_6 V_198 , char V_41 [] )
{
unsigned int V_3 , V_4 ;
if ( V_9 [ V_198 - 1 ] == '\n' )
V_198 -- ;
if ( ( V_198 < 16 ) || ( V_198 > 18 ) || ( ( V_198 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_198 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_162 ;
memset ( V_41 , 0 , V_309 ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( ( * V_9 >= 'a' ) && ( * V_9 <= 'f' ) )
V_4 = ( ( V_4 << 4 ) | ( ( * V_9 ++ - 'a' ) + 10 ) ) ;
else if ( ( * V_9 >= 'A' ) && ( * V_9 <= 'F' ) )
V_4 = ( ( V_4 << 4 ) | ( ( * V_9 ++ - 'A' ) + 10 ) ) ;
else if ( ( * V_9 >= '0' ) && ( * V_9 <= '9' ) )
V_4 = ( ( V_4 << 4 ) | ( * V_9 ++ - '0' ) ) ;
else
return - V_162 ;
if ( V_3 % 2 ) {
V_41 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
return 0 ;
}
static T_1
F_83 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
unsigned int V_198 = V_160 ;
T_4 V_310 = V_15 -> V_311 . V_312 . V_313 ;
T_12 * V_314 = ( T_3 * ) & V_15 -> V_311 . V_274 . V_315 [ 0 ] ;
if ( V_310 == 1 && F_84 ( * V_314 ) == V_316 ) {
F_40 ( V_18 , V_190 , V_200 ,
L_103 V_317 L_104
L_105 ) ;
return - V_162 ;
}
if ( V_9 [ V_198 - 1 ] == '\n' )
V_198 -- ;
if ( ( V_198 != strlen ( V_318 ) ) ||
( strncmp ( V_9 , V_318 , strlen ( V_318 ) ) != 0 ) )
return - V_162 ;
V_18 -> V_319 = 1 ;
F_85 ( V_199 , & V_18 -> V_234 -> V_6 ,
L_106 ,
V_18 -> V_43 ) ;
F_85 ( V_199 , & V_18 -> V_234 -> V_6 ,
L_107 ) ;
return V_160 ;
}
static T_1
F_86 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_108 ,
( unsigned long long ) V_18 -> V_320 ) ;
}
static T_1
F_87 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_201 V_202 ;
int V_321 = 0 , V_322 = 0 ;
unsigned int V_198 = V_160 ;
T_13 V_323 [ V_309 ] ;
int V_209 ;
if ( ! V_18 -> V_217 )
return - V_218 ;
F_11 ( & V_18 -> V_214 ) ;
if ( V_18 -> V_324 == V_325 ) {
F_13 ( & V_18 -> V_214 ) ;
return - V_218 ;
}
F_13 ( & V_18 -> V_214 ) ;
if ( V_9 [ V_198 - 1 ] == '\n' )
V_198 -- ;
if ( ! V_18 -> V_319 )
return - V_162 ;
V_18 -> V_319 = 0 ;
V_209 = F_82 ( V_9 , V_198 , V_323 ) ;
if ( V_209 ) {
V_18 -> V_319 = 1 ;
return V_209 ;
}
V_18 -> V_320 = F_7 ( V_323 ) ;
F_88 ( V_13 ) = V_18 -> V_320 ;
if ( V_18 -> V_326 )
F_89 ( V_13 ) = V_18 -> V_326 ;
F_85 ( V_327 , & V_18 -> V_234 -> V_6 ,
L_109 , V_18 -> V_43 ) ;
V_321 = F_46 ( V_18 , V_220 ) ;
if ( V_321 )
F_40 ( V_18 , V_190 , V_200 ,
L_110
L_111 , V_321 ) ;
F_47 ( & V_202 ) ;
V_209 = F_48 ( V_18 , & V_322 , & V_202 ,
V_221 ) ;
if ( V_209 == 0 )
return - V_176 ;
F_49 ( & V_202 ) ;
if ( V_322 )
F_40 ( V_18 , V_190 , V_200 ,
L_112
L_111 , V_322 ) ;
return ( V_321 || V_322 ) ? - V_194 : V_160 ;
}
static T_1
F_90 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_108 ,
( unsigned long long ) V_18 -> V_326 ) ;
}
static T_1
F_91 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_198 = V_160 ;
T_13 V_328 [ V_309 ] ;
int V_209 ;
if ( V_9 [ V_198 - 1 ] == '\n' )
V_198 -- ;
if ( ! V_18 -> V_319 )
return - V_162 ;
V_209 = F_82 ( V_9 , V_198 , V_328 ) ;
if ( V_209 ) {
return V_209 ;
}
V_18 -> V_326 = F_7 ( V_328 ) ;
F_85 ( V_327 , & V_18 -> V_234 -> V_6 ,
L_113
L_114 , V_18 -> V_43 ) ;
return V_160 ;
}
static T_1
F_92 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_108 ,
F_7 ( V_18 -> V_329 ) ) ;
}
static T_1
F_93 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_198 = V_160 ;
T_4 V_323 [ V_309 ] ;
int V_209 ;
if ( ! V_18 -> V_330 )
return - V_173 ;
if ( V_9 [ V_198 - 1 ] == '\n' )
V_198 -- ;
V_209 = F_82 ( V_9 , V_198 , V_323 ) ;
if ( V_209 )
return V_209 ;
memcpy ( V_18 -> V_329 , V_323 , ( 8 * sizeof( T_4 ) ) ) ;
memcpy ( V_18 -> V_73 . V_331 , V_323 , ( 8 * sizeof( T_4 ) ) ) ;
if ( F_7 ( V_323 ) == 0 )
V_18 -> V_332 |= V_333 ;
else
V_18 -> V_332 &= ~ V_333 ;
V_18 -> V_332 &= ~ V_334 ;
V_18 -> V_73 . V_335 = V_336 ;
return V_160 ;
}
static T_1
F_94 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_337 ) ;
}
static T_1
F_95 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_198 = V_160 ;
unsigned long V_295 ;
int V_338 ;
if ( ! V_18 -> V_330 )
return - V_173 ;
if ( V_9 [ V_198 - 1 ] == '\n' )
V_198 -- ;
V_338 = F_96 ( V_9 , 0 , & V_295 ) ;
if ( V_338 || ( V_295 > 0x7f ) )
return - V_162 ;
if ( V_295 )
V_18 -> V_337 = ( T_4 ) V_295 ;
else
V_18 -> V_337 = V_18 -> V_339 ;
return V_160 ;
}
static T_1
F_97 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_108 ,
F_7 ( V_18 -> V_340 ) ) ;
}
static T_1
F_98 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_198 = V_160 ;
T_4 V_323 [ V_309 ] ;
int V_209 ;
if ( ! V_18 -> V_330 )
return - V_173 ;
if ( V_9 [ V_198 - 1 ] == '\n' )
V_198 -- ;
V_209 = F_82 ( V_9 , V_198 , V_323 ) ;
if ( V_209 )
return V_209 ;
memcpy ( V_18 -> V_340 , V_323 , ( 8 * sizeof( T_4 ) ) ) ;
memcpy ( V_18 -> V_73 . V_341 , V_323 , ( 8 * sizeof( T_4 ) ) ) ;
if ( F_7 ( V_323 ) == 0 )
V_18 -> V_332 |= V_342 ;
else
V_18 -> V_332 &= ~ V_342 ;
V_18 -> V_332 &= ~ V_334 ;
if ( V_18 -> V_337 == 0 )
V_18 -> V_337 = V_18 -> V_339 ;
V_18 -> V_73 . V_335 = V_336 ;
return V_160 ;
}
static T_1
F_99 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_343 ) ;
}
static T_1
F_100 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
int V_295 = 0 ;
if ( ! V_18 -> V_330 )
return - V_173 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_162 ;
if ( sscanf ( V_9 , L_96 , & V_295 ) != 1 )
return - V_162 ;
if ( ( V_295 != 0 ) && ( V_295 != 1 ) )
return - V_162 ;
V_18 -> V_343 = V_295 ;
return strlen ( V_9 ) ;
}
static T_1
F_101 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
if ( ! ( V_18 -> V_332 & V_334 ) )
return - V_344 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_345 ) ;
}
static T_6
F_102 ( struct V_17 * V_18 , T_4 V_346 [] ,
T_4 V_347 [] , T_2 V_348 ,
T_3 V_349 , T_4 V_350 )
{
int V_209 = 0 ;
if ( ! V_18 -> V_330 )
return - V_173 ;
if ( V_349 ) {
if ( ! F_103 ( V_18 , (struct V_351 * ) V_346 ,
(struct V_351 * ) V_347 ,
V_348 , V_350 ) )
V_209 = - V_176 ;
} else {
F_104 ( V_18 , (struct V_351 * ) V_346 ,
(struct V_351 * ) V_347 , V_348 , V_350 ) ;
}
return V_209 ;
}
static T_2
F_105 ( struct V_17 * V_18 , T_4 V_346 [] ,
T_4 V_347 [] , T_3 * V_352 ,
T_3 * V_353 )
{
T_2 V_354 ;
if ( F_106 ( ! V_18 ) || ! V_346 || ! V_347 )
return V_355 ;
if ( F_107 ( V_18 , (struct V_351 * )
V_18 -> V_73 . V_341 ,
(struct V_351 * )
V_18 -> V_73 . V_331 ,
& V_18 -> V_73 . V_335 ,
(struct V_351 * ) V_346 ,
(struct V_351 * ) V_347 ,
& V_354 , V_352 , V_353 ) )
return V_354 ;
else
return V_355 ;
}
static T_1
F_108 ( struct V_17 * V_18 , T_4 V_346 [] ,
T_4 V_347 [] , T_2 V_348 ,
T_3 V_349 , T_4 V_350 )
{
int V_209 ;
V_209 = F_102 ( V_18 , V_346 , V_347 , V_348 ,
V_349 , V_350 ) ;
return V_209 ;
}
static T_1
F_109 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_2 V_356 ;
int V_34 = 0 ;
if ( ! V_18 -> V_330 )
return - V_173 ;
if ( F_7 ( V_18 -> V_340 ) == 0 )
if ( ! ( V_18 -> V_332 & V_342 ) )
return - V_344 ;
if ( F_7 ( V_18 -> V_329 ) == 0 )
if ( ! ( V_18 -> V_332 & V_333 ) )
return - V_344 ;
V_356 = F_105 ( V_18 , V_18 -> V_340 ,
V_18 -> V_329 ,
& V_18 -> V_345 ,
& V_18 -> V_337 ) ;
if ( V_356 != V_355 )
V_18 -> V_332 |= V_334 ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_115 , V_356 ) ;
return V_34 ;
}
static T_1
F_110 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_2 V_357 ;
T_3 V_350 ;
T_1 V_209 ;
if ( ! V_18 -> V_330 )
return - V_173 ;
if ( F_7 ( V_18 -> V_340 ) == 0 )
return - V_344 ;
if ( F_7 ( V_18 -> V_329 ) == 0 )
return - V_344 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_162 ;
if ( sscanf ( V_9 , L_115 , & V_357 ) != 1 )
return - V_162 ;
V_350 = V_18 -> V_337 ;
if ( V_350 == 0 )
V_350 = V_18 -> V_339 ;
F_40 ( V_18 , V_358 , V_200 ,
L_116
L_117 ,
F_7 ( V_18 -> V_340 ) ,
F_7 ( V_18 -> V_329 ) , V_357 ,
V_350 , V_18 -> V_343 ) ;
V_209 = F_108 ( V_18 , V_18 -> V_340 ,
V_18 -> V_329 , V_357 ,
V_18 -> V_343 , V_350 ) ;
if ( V_209 )
return V_209 ;
return V_160 ;
}
static T_1
F_111 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_359 ) ;
}
static T_1
F_112 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
struct V_205 * V_206 = F_113 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_51 , V_206 -> V_360 ) ;
}
static T_1
F_114 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
struct V_205 * V_206 = F_113 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_51 , V_206 -> V_361 ) ;
}
static T_1
F_115 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_51 , V_15 -> V_362 ) ;
}
static int
F_116 ( struct V_14 * V_15 , int V_295 )
{
if ( V_15 -> V_362 != V_363 ) {
V_15 -> V_364 = V_15 -> V_362 ;
if ( V_295 != V_363 )
F_63 ( V_15 , V_190 , V_200 ,
L_118
L_119
L_120 ) ;
return 0 ;
}
if ( V_295 >= V_365 && V_295 <= V_366 ) {
V_15 -> V_364 = V_295 ;
V_15 -> V_362 = V_295 ;
return 0 ;
}
F_63 ( V_15 , V_190 , V_200 ,
L_121
L_122 ,
V_295 , V_365 , V_366 ) ;
V_15 -> V_364 = V_363 ;
return - V_162 ;
}
static void
F_117 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_25 * V_26 ;
V_13 = F_118 ( V_15 ) ;
F_11 ( V_13 -> V_81 ) ;
F_12 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_119 ( V_26 ) )
continue;
if ( V_26 -> V_367 )
V_26 -> V_367 -> V_368 = V_15 -> V_362 ;
}
F_13 ( V_13 -> V_81 ) ;
}
static int
F_120 ( struct V_14 * V_15 , int V_295 )
{
if ( V_15 -> V_369 ||
( V_370 != V_363 ) ) {
F_63 ( V_15 , V_190 , V_200 ,
L_123
L_124 ) ;
return 0 ;
}
if ( V_295 >= V_365 && V_295 <= V_366 ) {
V_15 -> V_364 = V_295 ;
V_15 -> V_362 = V_295 ;
F_121 ( F_118 ( V_15 ) ) = V_295 ;
F_117 ( V_15 ) ;
return 0 ;
}
F_63 ( V_15 , V_190 , V_200 ,
L_125
L_126 ,
V_295 , V_365 , V_366 ) ;
return - V_162 ;
}
static int
F_122 ( struct V_14 * V_15 , int V_295 )
{
if ( V_295 >= V_365 && V_295 <= V_366 ) {
V_15 -> V_364 = V_295 ;
V_15 -> V_362 = V_295 ;
V_15 -> V_369 = 1 ;
F_121 ( F_118 ( V_15 ) ) = V_295 ;
F_117 ( V_15 ) ;
return 0 ;
}
F_63 ( V_15 , V_190 , V_200 ,
L_127
L_126 ,
V_295 , V_365 , V_366 ) ;
return - V_162 ;
}
static int
F_123 ( struct V_14 * V_15 , int V_295 )
{
if ( V_295 < 0 || V_295 > 1 ) {
F_63 ( V_15 , V_190 , V_200 ,
L_128
L_129 ,
V_295 ) ;
V_15 -> V_371 = 1 ;
return - V_162 ;
}
if ( V_15 -> V_289 == V_290 ) {
V_15 -> V_371 = 0 ;
return 0 ;
}
V_15 -> V_371 = V_295 ;
return 0 ;
}
static int
F_124 ( struct V_14 * V_15 , int V_295 )
{
if ( V_295 < 0 || V_295 > 1 ) {
F_63 ( V_15 , V_190 , V_200 ,
L_130
L_129 ,
V_295 ) ;
V_15 -> V_371 = 1 ;
return - V_162 ;
}
if ( V_15 -> V_289 == V_290 && V_295 != 0 ) {
F_63 ( V_15 , V_190 , V_200 ,
L_131
L_132 ) ;
V_15 -> V_371 = 0 ;
return 0 ;
}
V_15 -> V_371 = V_295 ;
return 0 ;
}
static T_1
F_125 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_295 = 0 ;
int V_372 = 0 ;
const char * V_373 = V_9 ;
int V_374 ;
T_3 V_375 ;
if ( ! strncmp ( V_9 , L_133 , strlen ( L_133 ) ) ) {
V_372 = 1 ;
V_373 = & V_9 [ strlen ( L_133 ) ] ;
}
if ( ! isdigit ( V_373 [ 0 ] ) )
return - V_162 ;
if ( sscanf ( V_373 , L_96 , & V_295 ) != 1 )
return - V_162 ;
if ( V_295 >= 0 && V_295 <= 6 ) {
V_375 = V_18 -> V_186 ;
if ( V_18 -> V_187 == V_376 &&
V_295 == 4 ) {
F_63 ( V_15 , V_190 , V_200 ,
L_134 ,
V_295 ) ;
return - V_162 ;
}
if ( V_18 -> V_234 -> V_5 == V_377 &&
V_295 == 4 ) {
F_63 ( V_15 , V_190 , V_200 ,
L_135 ) ;
return - V_162 ;
}
V_18 -> V_186 = V_295 ;
if ( V_372 )
return strlen ( V_9 ) ;
F_63 ( V_15 , V_190 , V_200 ,
L_136 ,
V_375 , V_295 ) ;
if ( V_375 != V_295 && V_18 -> V_119 == V_120 )
V_18 -> V_378 = 1 ;
V_374 = F_36 ( F_118 ( V_18 -> V_219 ) ) ;
if ( V_374 ) {
V_18 -> V_186 = V_375 ;
return - V_162 ;
} else
return strlen ( V_9 ) ;
}
F_40 ( V_18 , V_190 , V_200 ,
L_137
L_138 ,
V_18 -> V_43 , V_295 ) ;
return - V_162 ;
}
static T_1
F_126 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_379 & V_380 )
sprintf ( V_9 , L_2 ) ;
else
sprintf ( V_9 , L_3 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_127 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
#define F_128 1024
static char V_381 [ F_128 ] ;
unsigned long V_3 ;
char * V_382 , * V_383 ;
struct V_14 * * V_384 ;
struct V_12 * V_385 ;
char * V_386 , * V_387 , * V_388 ;
unsigned long V_389 , V_390 , V_391 ;
if ( ! strncmp ( V_9 , L_139 , strlen ( L_139 ) ) ) {
if ( strlen ( V_9 ) > ( F_128 - 1 ) )
return - V_162 ;
strncpy ( V_381 , V_9 , F_128 ) ;
V_382 = & V_381 [ 0 ] ;
V_383 = F_129 ( & V_382 , L_140 ) ;
if ( ! V_383 )
return - V_162 ;
V_386 = F_129 ( & V_382 , L_140 ) ;
if ( ! V_386 )
return - V_162 ;
if ( ! strncmp ( V_386 , L_141 , strlen ( L_141 ) ) )
V_391 = V_392 ;
else if ( ! strncmp ( V_386 , L_142 , strlen ( L_142 ) ) )
V_391 = V_393 ;
else
return - V_162 ;
V_387 = F_129 ( & V_382 , L_140 ) ;
if ( ! V_387 )
return - V_162 ;
V_389 = F_130 ( V_387 , NULL , 0 ) ;
V_388 = F_129 ( & V_382 , L_140 ) ;
if ( ! V_388 )
return - V_162 ;
V_390 = F_130 ( V_388 , NULL , 0 ) ;
if ( ! V_390 )
return - V_162 ;
V_384 = F_131 ( V_18 ) ;
if ( V_384 == NULL )
return - V_176 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_394 && V_384 [ V_3 ] != NULL ; V_3 ++ ) {
V_385 = F_118 ( V_384 [ V_3 ] ) ;
F_11 ( V_385 -> V_81 ) ;
V_384 [ V_3 ] -> V_395 = 1 ;
if ( V_384 [ V_3 ] -> V_396 )
F_132 ( V_384 [ V_3 ] ) ;
F_13 ( V_385 -> V_81 ) ;
}
V_18 -> V_391 = V_391 ;
V_18 -> V_397 = V_389 ;
V_18 -> V_398 = V_390 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_394 && V_384 [ V_3 ] != NULL ; V_3 ++ ) {
V_385 = F_118 ( V_384 [ V_3 ] ) ;
F_11 ( V_385 -> V_81 ) ;
V_384 [ V_3 ] -> V_395 = 0 ;
F_13 ( V_385 -> V_81 ) ;
}
F_133 ( V_18 , V_384 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_143 , strlen ( L_143 ) ) ) {
V_384 = F_131 ( V_18 ) ;
if ( V_384 == NULL )
return - V_176 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_394 && V_384 [ V_3 ] != NULL ; V_3 ++ ) {
V_385 = F_118 ( V_384 [ V_3 ] ) ;
F_11 ( V_13 -> V_81 ) ;
V_384 [ V_3 ] -> V_395 = 1 ;
F_134 ( V_15 ) ;
V_15 -> V_396 = 0 ;
V_384 [ V_3 ] -> V_395 = 0 ;
F_13 ( V_13 -> V_81 ) ;
}
F_133 ( V_18 , V_384 ) ;
V_18 -> V_391 = V_399 ;
V_18 -> V_397 = 0 ;
V_18 -> V_398 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_144 , strlen ( L_144 ) ) ) {
if ( V_18 -> V_391 == V_399 )
return - V_162 ;
F_11 ( V_13 -> V_81 ) ;
if ( V_15 -> V_396 ) {
F_13 ( V_13 -> V_81 ) ;
return strlen ( V_9 ) ;
}
F_135 ( V_15 ) ;
V_15 -> V_396 = 1 ;
F_13 ( V_13 -> V_81 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_145 , strlen ( L_145 ) ) ) {
F_11 ( V_13 -> V_81 ) ;
if ( V_15 -> V_396 == 0 ) {
F_13 ( V_13 -> V_81 ) ;
return strlen ( V_9 ) ;
}
F_134 ( V_15 ) ;
V_15 -> V_396 = 0 ;
F_13 ( V_13 -> V_81 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_146 , strlen ( L_146 ) ) ) {
if ( ( V_18 -> V_391 == V_399 )
|| ! V_15 -> V_396 )
return strlen ( V_9 ) ;
F_11 ( V_13 -> V_81 ) ;
V_15 -> V_395 = 1 ;
F_132 ( V_15 ) ;
V_15 -> V_395 = 0 ;
F_13 ( V_13 -> V_81 ) ;
return strlen ( V_9 ) ;
}
return - V_162 ;
}
static T_1
F_136 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_400 = 0 ;
int V_3 ;
char * V_391 ;
unsigned long V_401 ;
switch ( V_18 -> V_391 ) {
case V_392 :
V_391 = L_141 ;
break;
case V_393 :
V_391 = L_142 ;
break;
default:
V_391 = L_147 ;
break;
}
sprintf ( & V_9 [ V_400 ] , L_148
L_149
L_150 ,
V_15 -> V_396 , V_15 -> V_395 ,
V_391 , V_18 -> V_397 , V_18 -> V_398 ) ;
V_400 = strlen ( V_9 ) ;
if ( V_18 -> V_391 != V_399 ) {
for ( V_3 = 0 ; V_3 < V_402 ; V_3 ++ ) {
if ( V_18 -> V_391 == V_392 )
V_401 = V_18 -> V_397 +
V_18 -> V_398 * V_3 ;
else
V_401 = V_18 -> V_397 +
( 1 << V_3 ) * V_18 -> V_398 ;
if ( V_400 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_400 ] , L_151 , V_401 ) ;
V_400 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_400 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_137 ( struct V_403 * V_404 , struct V_405 * V_406 ,
struct V_407 * V_408 ,
char * V_9 , T_14 V_409 , T_6 V_160 )
{
struct V_5 * V_6 = F_138 ( V_406 , struct V_5 ,
V_406 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_400 = 0 ;
unsigned long V_410 ;
struct V_25 * V_26 = NULL ;
V_410 = ( unsigned long ) V_409 /
V_411 ;
if ( ! V_15 -> V_396 || V_15 -> V_395
|| ( V_18 -> V_391 == V_399 ) )
return 0 ;
F_11 ( V_13 -> V_81 ) ;
F_12 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_119 ( V_26 ) || ! V_26 -> V_412 )
continue;
if ( V_410 > 0 ) {
V_410 -- ;
continue;
}
if ( ( V_400 + V_411 )
> V_160 )
break;
if ( ! V_26 -> V_412 )
continue;
sprintf ( & V_9 [ V_400 ] , L_152 ,
V_26 -> V_413 . V_40 . V_41 [ 0 ] ,
V_26 -> V_413 . V_40 . V_41 [ 1 ] ,
V_26 -> V_413 . V_40 . V_41 [ 2 ] ,
V_26 -> V_413 . V_40 . V_41 [ 3 ] ,
V_26 -> V_413 . V_40 . V_41 [ 4 ] ,
V_26 -> V_413 . V_40 . V_41 [ 5 ] ,
V_26 -> V_413 . V_40 . V_41 [ 6 ] ,
V_26 -> V_413 . V_40 . V_41 [ 7 ] ) ;
V_400 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_402 ; V_3 ++ ) {
sprintf ( & V_9 [ V_400 ] , L_153 ,
V_26 -> V_412 [ V_3 ] . V_414 ) ;
V_400 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_400 ] , L_1 ) ;
V_400 = strlen ( V_9 ) ;
}
F_13 ( V_13 -> V_81 ) ;
return V_400 ;
}
static T_1
F_139 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_295 = V_415 ;
int V_372 = 0 ;
const char * V_373 = V_9 ;
int V_374 ;
T_3 V_375 , V_114 ;
V_114 = F_54 ( V_240 , & V_18 -> V_73 . V_241 ) ;
if ( V_114 == V_242 &&
V_18 -> V_19 & V_416 )
return - V_173 ;
if ( ! strncmp ( V_9 , L_133 , strlen ( L_133 ) ) ) {
V_372 = 1 ;
V_373 = & V_9 [ strlen ( L_133 ) ] ;
}
if ( ! isdigit ( V_373 [ 0 ] ) )
return - V_162 ;
if ( sscanf ( V_373 , L_96 , & V_295 ) != 1 )
return - V_162 ;
F_63 ( V_15 , V_190 , V_200 ,
L_154 ,
V_18 -> V_187 , V_295 , V_372 ? L_155 : L_156 ) ;
if ( ( ( V_295 == V_417 ) && ! ( V_18 -> V_418 & V_419 ) ) ||
( ( V_295 == V_420 ) && ! ( V_18 -> V_418 & V_421 ) ) ||
( ( V_295 == V_422 ) && ! ( V_18 -> V_418 & V_423 ) ) ||
( ( V_295 == V_424 ) && ! ( V_18 -> V_418 & V_425 ) ) ||
( ( V_295 == V_426 ) && ! ( V_18 -> V_418 & V_427 ) ) ||
( ( V_295 == V_376 ) && ! ( V_18 -> V_418 & V_428 ) ) ||
( ( V_295 == V_429 ) && ! ( V_18 -> V_418 & V_430 ) ) ) {
F_40 ( V_18 , V_190 , V_200 ,
L_157
L_158 ,
V_295 ) ;
return - V_162 ;
}
if ( V_295 == V_376 &&
V_18 -> V_148 == V_149 ) {
F_40 ( V_18 , V_190 , V_200 ,
L_159
L_160 ,
V_295 ) ;
return - V_162 ;
}
if ( ( V_295 >= 0 ) && ( V_295 <= V_431 ) &&
( V_432 & ( 1 << V_295 ) ) ) {
V_375 = V_18 -> V_187 ;
V_18 -> V_187 = V_295 ;
if ( V_372 )
return strlen ( V_9 ) ;
V_374 = F_36 ( F_118 ( V_18 -> V_219 ) ) ;
if ( V_374 ) {
V_18 -> V_187 = V_375 ;
return - V_162 ;
} else
return strlen ( V_9 ) ;
}
F_40 ( V_18 , V_190 , V_200 ,
L_161
L_162 V_433 L_163 , V_295 ) ;
return - V_162 ;
}
static int
F_140 ( struct V_17 * V_18 , int V_295 )
{
if ( V_295 == V_376 && V_18 -> V_186 == 4 ) {
F_40 ( V_18 , V_190 , V_200 ,
L_164
L_165 ,
V_295 ) ;
V_18 -> V_186 = 0 ;
}
if ( ( V_295 >= 0 ) && ( V_295 <= V_431 ) &&
( V_432 & ( 1 << V_295 ) ) ) {
V_18 -> V_187 = V_295 ;
return 0 ;
}
F_40 ( V_18 , V_190 , V_200 ,
L_166
L_167
L_168 V_433 L_163 , V_295 ) ;
V_18 -> V_187 = V_415 ;
return - V_162 ;
}
static T_1
F_141 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_295 = 0 , V_209 = - V_162 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_162 ;
if ( sscanf ( V_9 , L_96 , & V_295 ) != 1 )
return - V_162 ;
switch ( V_295 ) {
case 0 :
if ( V_18 -> V_19 & V_434 ) {
V_209 = F_142 ( V_18 -> V_234 ) ;
if ( ! V_209 ) {
F_11 ( & V_18 -> V_214 ) ;
V_18 -> V_19 &= ~ V_434 ;
F_13 ( & V_18 -> V_214 ) ;
V_18 -> V_435 = 0 ;
V_209 = strlen ( V_9 ) ;
} else
V_209 = - V_173 ;
} else {
V_18 -> V_435 = 0 ;
V_209 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_434 ) ) {
V_209 = F_143 ( V_18 -> V_234 ) ;
if ( ! V_209 ) {
F_11 ( & V_18 -> V_214 ) ;
V_18 -> V_19 |= V_434 ;
F_13 ( & V_18 -> V_214 ) ;
V_18 -> V_435 = 1 ;
V_209 = strlen ( V_9 ) ;
} else
V_209 = - V_173 ;
} else {
V_18 -> V_435 = 1 ;
V_209 = strlen ( V_9 ) ;
}
break;
default:
V_209 = - V_162 ;
break;
}
return V_209 ;
}
static T_1
F_144 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_295 , V_209 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_162 ;
if ( sscanf ( V_9 , L_96 , & V_295 ) != 1 )
return - V_162 ;
if ( V_295 != 1 )
return - V_162 ;
if ( V_18 -> V_19 & V_434 )
V_209 = F_145 ( V_18 -> V_234 ) ;
if ( V_209 == 0 )
return strlen ( V_9 ) ;
else
return - V_173 ;
}
static T_1
F_146 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_232 * V_233 = V_18 -> V_234 ;
int V_295 = 0 , V_209 = - V_162 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_162 ;
if ( sscanf ( V_9 , L_96 , & V_295 ) != 1 )
return - V_162 ;
if ( V_295 < 0 )
return - V_162 ;
if ( V_295 == 0 ) {
if ( V_18 -> V_243 > 0 ) {
F_56 ( V_233 ) ;
V_18 -> V_243 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_243 > 0 ) {
F_40 ( V_18 , V_190 , V_200 ,
L_169
L_170 ,
V_18 -> V_243 ) ;
return - V_436 ;
}
if ( V_295 <= V_437 )
V_18 -> V_243 = V_295 ;
else {
F_40 ( V_18 , V_190 , V_200 ,
L_171
L_172 , V_295 ) ;
return - V_162 ;
}
V_209 = F_59 ( V_18 , V_18 -> V_243 ) ;
if ( V_209 ) {
V_18 -> V_243 = 0 ;
V_209 = - V_173 ;
} else
V_209 = strlen ( V_9 ) ;
return V_209 ;
}
static T_1
F_147 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_295 = 0 , V_209 = - V_162 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_162 ;
if ( sscanf ( V_9 , L_96 , & V_295 ) != 1 )
return - V_162 ;
if ( V_295 != 1 )
return - V_162 ;
V_209 = F_148 ( V_18 , V_438 ) ;
if ( V_209 )
V_209 = - V_173 ;
else
V_209 = strlen ( V_9 ) ;
return V_209 ;
}
static int
F_149 ( struct V_17 * V_18 , int V_295 )
{
if ( V_295 >= 0 && V_295 <= 1 ) {
V_18 -> V_439 = V_295 ;
return 0 ;
}
return - V_162 ;
}
static T_1
F_150 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_295 = 0 , V_3 ;
if ( V_18 -> V_119 != V_120 )
return - V_162 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_162 ;
if ( sscanf ( V_9 , L_96 , & V_295 ) != 1 )
return - V_162 ;
if ( V_295 && ( V_295 < V_440 || V_295 > V_441 ) )
return - V_162 ;
V_18 -> V_442 = ( T_3 ) V_295 ;
V_18 -> V_443 = V_18 -> V_442 ;
for ( V_3 = 0 ; V_3 < V_18 -> V_444 ; V_3 += V_445 )
F_151 ( V_18 , V_3 , V_445 ,
V_295 ) ;
return strlen ( V_9 ) ;
}
static int
F_152 ( struct V_17 * V_18 , int V_295 )
{
if ( V_18 -> V_119 != V_120 ) {
V_18 -> V_442 = 0 ;
return 0 ;
}
if ( ( V_295 >= V_440 && V_295 <= V_441 ) ||
( V_295 == 0 ) ) {
V_18 -> V_442 = V_295 ;
return 0 ;
}
F_40 ( V_18 , V_190 , V_200 ,
L_173 ,
V_295 ) ;
V_18 -> V_442 = V_446 ;
return 0 ;
}
static T_1
F_153 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_447 * V_448 ;
int V_34 = 0 ;
if ( ( V_18 -> V_119 != V_120 ) ||
( V_18 -> V_449 != V_450 ) )
return V_34 ;
switch ( V_18 -> V_451 ) {
case 0 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_174 ,
V_18 -> V_451 ) ;
return V_34 ;
case 1 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_175
L_176 ,
V_18 -> V_451 ,
V_18 -> V_73 . V_452 ) ;
break;
case 2 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_177
L_176 ,
V_18 -> V_451 ,
V_18 -> V_73 . V_452 ) ;
break;
}
while ( V_18 -> V_73 . V_453 < V_18 -> V_73 . V_454 ) {
V_448 = & V_18 -> V_73 . V_455 [ V_18 -> V_73 . V_453 ] ;
if ( V_448 -> V_456 == V_457 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_178
L_179 ,
V_18 -> V_73 . V_453 ,
V_448 -> V_458 , V_448 -> V_459 ,
V_448 -> V_460 ) ;
else
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_178
L_180 ,
V_18 -> V_73 . V_453 ,
V_448 -> V_458 , V_448 -> V_459 ,
V_448 -> V_460 , V_448 -> V_456 ) ;
V_18 -> V_73 . V_453 ++ ;
if ( V_18 -> V_73 . V_453 <
V_18 -> V_73 . V_454 &&
( V_34 >= ( V_10 - 64 ) ) ) {
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_181 ) ;
break;
}
}
if ( V_18 -> V_73 . V_453 == V_18 -> V_73 . V_454 )
V_18 -> V_73 . V_453 = 0 ;
return V_34 ;
}
static T_1
F_154 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_160 )
{
int V_161 = - V_162 ;
return V_161 ;
}
static int
F_155 ( struct V_17 * V_18 , int V_295 )
{
if ( V_18 -> V_119 != V_120 ) {
V_18 -> V_451 = 0 ;
return 0 ;
}
if ( V_295 >= V_461 && V_295 <= V_462 ) {
V_18 -> V_451 = V_295 ;
return 0 ;
}
F_40 ( V_18 , V_190 , V_200 ,
L_182
L_183 , V_295 ) ;
V_18 -> V_451 = V_463 ;
return 0 ;
}
static int
F_156 ( struct V_14 * V_15 , int V_295 )
{
struct V_12 * V_13 = F_118 ( V_15 ) ;
struct V_25 * V_26 , * V_464 ;
if ( V_295 == V_15 -> V_465 )
return 0 ;
if ( ( V_295 < 0 ) || ( V_295 > 60000 ) )
return - V_162 ;
V_15 -> V_465 = V_295 ;
F_11 ( V_13 -> V_81 ) ;
F_157 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_119 ( V_26 ) )
continue;
if ( V_26 -> V_466 == V_467 )
continue;
V_26 -> V_468 = V_15 -> V_469 ;
}
F_13 ( V_13 -> V_81 ) ;
return 0 ;
}
static T_1
F_158 ( struct V_403 * V_404 , struct V_405 * V_406 ,
struct V_407 * V_408 ,
char * V_9 , T_14 V_409 , T_6 V_160 )
{
T_6 V_470 ;
struct V_5 * V_6 = F_138 ( V_406 , struct V_5 , V_406 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_119 >= V_120 )
return - V_173 ;
if ( ( V_409 + V_160 ) > V_471 )
return - V_472 ;
if ( V_160 <= V_473 )
return 0 ;
if ( V_409 % 4 || V_160 % 4 || ( unsigned long ) V_9 % 4 )
return - V_162 ;
if ( memcmp ( V_9 , V_474 , V_473 ) )
return - V_162 ;
if ( ! ( V_15 -> V_150 & V_171 ) )
return - V_173 ;
F_11 ( & V_18 -> V_214 ) ;
for ( V_470 = 0 ; V_470 < V_160 - V_473 ;
V_470 += sizeof( T_3 ) )
F_58 ( * ( ( T_3 * ) ( V_9 + V_470 + V_473 ) ) ,
V_18 -> V_475 + V_409 + V_470 ) ;
F_13 ( & V_18 -> V_214 ) ;
return V_160 ;
}
static T_1
F_159 ( struct V_403 * V_404 , struct V_405 * V_406 ,
struct V_407 * V_408 ,
char * V_9 , T_14 V_409 , T_6 V_160 )
{
T_6 V_470 ;
T_3 * V_476 ;
struct V_5 * V_6 = F_138 ( V_406 , struct V_5 , V_406 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_119 >= V_120 )
return - V_173 ;
if ( V_409 > V_471 )
return - V_472 ;
if ( ( V_409 + V_160 ) > V_471 )
V_160 = V_471 - V_409 ;
if ( V_160 == 0 ) return 0 ;
if ( V_409 % 4 || V_160 % 4 || ( unsigned long ) V_9 % 4 )
return - V_162 ;
F_11 ( & V_18 -> V_214 ) ;
for ( V_470 = 0 ; V_470 < V_160 ; V_470 += sizeof( T_3 ) ) {
V_476 = ( T_3 * ) ( V_9 + V_470 ) ;
* V_476 = F_57 ( V_18 -> V_475 + V_409 + V_470 ) ;
}
F_13 ( & V_18 -> V_214 ) ;
return V_160 ;
}
static T_1
F_160 ( struct V_403 * V_404 , struct V_405 * V_406 ,
struct V_407 * V_408 ,
char * V_9 , T_14 V_409 , T_6 V_160 )
{
return - V_173 ;
}
static T_1
F_161 ( struct V_403 * V_404 , struct V_405 * V_406 ,
struct V_407 * V_408 ,
char * V_9 , T_14 V_409 , T_6 V_160 )
{
return - V_173 ;
}
int
F_162 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_118 ( V_15 ) ;
int error ;
error = F_163 ( & V_13 -> V_477 . V_406 ,
& V_478 ) ;
if ( error || V_15 -> V_289 == V_479 )
goto V_215;
error = F_163 ( & V_13 -> V_477 . V_406 ,
& V_480 ) ;
if ( error )
goto V_481;
error = F_163 ( & V_13 -> V_477 . V_406 ,
& V_482 ) ;
if ( error )
goto V_483;
return 0 ;
V_483:
F_164 ( & V_13 -> V_477 . V_406 , & V_480 ) ;
V_481:
F_164 ( & V_13 -> V_477 . V_406 ,
& V_478 ) ;
V_215:
return error ;
}
void
F_165 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_118 ( V_15 ) ;
F_164 ( & V_13 -> V_477 . V_406 ,
& V_478 ) ;
if ( V_15 -> V_289 == V_479 )
return;
F_164 ( & V_13 -> V_477 . V_406 , & V_482 ) ;
F_164 ( & V_13 -> V_477 . V_406 , & V_480 ) ;
}
static void
F_166 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_167 ( V_15 , F_168 ( V_13 ) ,
sizeof F_168 ( V_13 ) ) ;
}
static void
F_169 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_170 ( V_13 ) = V_15 -> V_484 ;
}
static void
F_171 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_11 ( V_13 -> V_81 ) ;
if ( V_15 -> V_289 == V_479 ) {
F_172 ( V_13 ) = V_485 ;
} else if ( F_173 ( V_18 ) ) {
if ( V_18 -> V_148 == V_149 ) {
if ( V_15 -> V_150 & V_151 )
F_172 ( V_13 ) = V_486 ;
else
F_172 ( V_13 ) = V_487 ;
} else {
if ( V_15 -> V_150 & V_152 )
F_172 ( V_13 ) = V_488 ;
else
F_172 ( V_13 ) = V_489 ;
}
} else
F_172 ( V_13 ) = V_490 ;
F_13 ( V_13 -> V_81 ) ;
}
static void
F_174 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_11 ( V_13 -> V_81 ) ;
if ( V_15 -> V_150 & V_171 )
F_175 ( V_13 ) = V_491 ;
else {
switch ( V_18 -> V_126 ) {
case V_127 :
case V_131 :
F_175 ( V_13 ) = V_492 ;
break;
case V_134 :
case V_135 :
case V_136 :
if ( V_15 -> V_83 < V_145 )
F_175 ( V_13 ) =
V_493 ;
else
F_175 ( V_13 ) =
V_494 ;
break;
case V_132 :
F_175 ( V_13 ) = V_495 ;
break;
default:
F_175 ( V_13 ) = V_496 ;
break;
}
}
F_13 ( V_13 -> V_81 ) ;
}
static void
F_176 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_11 ( V_13 -> V_81 ) ;
if ( ( F_173 ( V_18 ) ) && ( ! ( V_18 -> V_19 & V_497 ) ) ) {
switch( V_18 -> V_498 ) {
case V_499 :
F_177 ( V_13 ) = V_500 ;
break;
case V_501 :
F_177 ( V_13 ) = V_502 ;
break;
case V_503 :
F_177 ( V_13 ) = V_504 ;
break;
case V_505 :
F_177 ( V_13 ) = V_506 ;
break;
case V_507 :
F_177 ( V_13 ) = V_508 ;
break;
case V_509 :
F_177 ( V_13 ) = V_510 ;
break;
case V_511 :
F_177 ( V_13 ) = V_512 ;
break;
default:
F_177 ( V_13 ) = V_513 ;
break;
}
} else
F_177 ( V_13 ) = V_513 ;
F_13 ( V_13 -> V_81 ) ;
}
static void
F_178 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_15 V_87 ;
F_11 ( V_13 -> V_81 ) ;
if ( ( V_15 -> V_83 > V_139 ) &&
( ( V_15 -> V_150 & V_152 ) ||
( ( V_18 -> V_148 == V_149 ) &&
( V_15 -> V_150 & V_151 ) ) ) )
V_87 = F_7 ( V_18 -> V_514 . V_515 . V_40 . V_41 ) ;
else
V_87 = 0 ;
F_13 ( V_13 -> V_81 ) ;
F_179 ( V_13 ) = V_87 ;
}
static struct V_516 *
F_180 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_207 * V_208 = & V_18 -> V_110 ;
struct V_516 * V_517 = & V_18 -> V_518 ;
struct V_519 * V_520 = & V_208 -> V_521 ;
T_7 * V_168 ;
T_9 * V_267 ;
unsigned long V_522 ;
int V_209 = 0 ;
if ( V_18 -> V_126 < V_131 ||
! V_18 -> V_174 ||
( V_18 -> V_110 . V_111 & V_269 ) == 0 )
return NULL ;
if ( V_18 -> V_110 . V_111 & V_172 )
return NULL ;
V_168 = F_37 ( V_18 -> V_174 , V_175 ) ;
if ( ! V_168 )
return NULL ;
memset ( V_168 , 0 , sizeof ( T_7 ) ) ;
V_267 = & V_168 -> V_40 . V_177 ;
V_267 -> V_178 = V_523 ;
V_267 -> V_180 = V_181 ;
V_168 -> V_271 = NULL ;
V_168 -> V_15 = V_15 ;
if ( V_15 -> V_150 & V_171 )
V_209 = F_181 ( V_18 , V_168 , V_524 ) ;
else
V_209 = F_38 ( V_18 , V_168 , V_18 -> V_188 * 2 ) ;
if ( V_209 != V_183 ) {
if ( V_209 != V_193 )
F_42 ( V_168 , V_18 -> V_174 ) ;
return NULL ;
}
memset ( V_517 , 0 , sizeof ( struct V_516 ) ) ;
V_517 -> V_525 = V_267 -> V_274 . V_526 . V_527 ;
V_517 -> V_528 = ( T_2 )
( ( T_2 ) V_267 -> V_274 . V_526 . V_529
* ( T_2 ) 256 ) ;
V_517 -> V_530 = V_267 -> V_274 . V_526 . V_531 ;
V_517 -> V_532 = ( T_2 )
( ( T_2 ) V_267 -> V_274 . V_526 . V_533
* ( T_2 ) 256 ) ;
memset ( V_168 , 0 , sizeof ( T_7 ) ) ;
V_267 -> V_178 = V_534 ;
V_267 -> V_180 = V_181 ;
V_168 -> V_271 = NULL ;
V_168 -> V_15 = V_15 ;
if ( V_15 -> V_150 & V_171 )
V_209 = F_181 ( V_18 , V_168 , V_524 ) ;
else
V_209 = F_38 ( V_18 , V_168 , V_18 -> V_188 * 2 ) ;
if ( V_209 != V_183 ) {
if ( V_209 != V_193 )
F_42 ( V_168 , V_18 -> V_174 ) ;
return NULL ;
}
V_517 -> V_535 = V_267 -> V_274 . V_536 . V_537 ;
V_517 -> V_538 = V_267 -> V_274 . V_536 . V_539 ;
V_517 -> V_540 = V_267 -> V_274 . V_536 . V_541 ;
V_517 -> V_542 = V_267 -> V_274 . V_536 . V_543 ;
V_517 -> V_544 = V_267 -> V_274 . V_536 . V_545 ;
V_517 -> V_546 = V_267 -> V_274 . V_536 . V_547 ;
V_517 -> V_548 = V_267 -> V_274 . V_536 . V_547 ;
V_517 -> V_535 -= V_520 -> V_535 ;
V_517 -> V_538 -= V_520 -> V_538 ;
V_517 -> V_540 -= V_520 -> V_540 ;
V_517 -> V_542 -= V_520 -> V_542 ;
V_517 -> V_544 -= V_520 -> V_544 ;
V_517 -> V_546 -= V_520 -> V_546 ;
V_517 -> V_548 -= V_520 -> V_548 ;
if ( V_18 -> V_19 & V_497 ) {
V_517 -> V_549 = - 1 ;
V_517 -> V_550 = ( V_18 -> V_551 >> 1 ) ;
V_517 -> V_550 -= V_520 -> V_551 ;
} else if ( V_18 -> V_148 == V_149 ) {
V_517 -> V_549 = ( V_18 -> V_552 >> 1 ) ;
V_517 -> V_549 -= V_520 -> V_551 ;
V_517 -> V_550 = - 1 ;
} else {
V_517 -> V_549 = - 1 ;
V_517 -> V_550 = ( V_18 -> V_552 >> 1 ) ;
V_517 -> V_550 -= V_520 -> V_551 ;
}
V_517 -> V_553 = - 1 ;
V_522 = F_182 () ;
if ( V_522 < V_208 -> V_554 )
V_517 -> V_555 = V_522 +
( ( unsigned long ) - 1 - V_208 -> V_554 ) ;
else
V_517 -> V_555 = V_522 - V_208 -> V_554 ;
F_42 ( V_168 , V_18 -> V_174 ) ;
return V_517 ;
}
static void
F_183 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_207 * V_208 = & V_18 -> V_110 ;
struct V_519 * V_520 = & V_208 -> V_521 ;
T_7 * V_168 ;
T_9 * V_267 ;
int V_209 = 0 ;
if ( V_18 -> V_110 . V_111 & V_172 )
return;
V_168 = F_37 ( V_18 -> V_174 , V_175 ) ;
if ( ! V_168 )
return;
memset ( V_168 , 0 , sizeof( T_7 ) ) ;
V_267 = & V_168 -> V_40 . V_177 ;
V_267 -> V_178 = V_523 ;
V_267 -> V_180 = V_181 ;
V_267 -> V_274 . V_556 [ 0 ] = 0x1 ;
V_168 -> V_271 = NULL ;
V_168 -> V_15 = V_15 ;
if ( ( V_15 -> V_150 & V_171 ) ||
( ! ( V_208 -> V_111 & V_269 ) ) )
V_209 = F_181 ( V_18 , V_168 , V_524 ) ;
else
V_209 = F_38 ( V_18 , V_168 , V_18 -> V_188 * 2 ) ;
if ( V_209 != V_183 ) {
if ( V_209 != V_193 )
F_42 ( V_168 , V_18 -> V_174 ) ;
return;
}
memset ( V_168 , 0 , sizeof( T_7 ) ) ;
V_267 -> V_178 = V_534 ;
V_267 -> V_180 = V_181 ;
V_168 -> V_271 = NULL ;
V_168 -> V_15 = V_15 ;
if ( ( V_15 -> V_150 & V_171 ) ||
( ! ( V_208 -> V_111 & V_269 ) ) )
V_209 = F_181 ( V_18 , V_168 , V_524 ) ;
else
V_209 = F_38 ( V_18 , V_168 , V_18 -> V_188 * 2 ) ;
if ( V_209 != V_183 ) {
if ( V_209 != V_193 )
F_42 ( V_168 , V_18 -> V_174 ) ;
return;
}
V_520 -> V_535 = V_267 -> V_274 . V_536 . V_537 ;
V_520 -> V_538 = V_267 -> V_274 . V_536 . V_539 ;
V_520 -> V_540 = V_267 -> V_274 . V_536 . V_541 ;
V_520 -> V_542 = V_267 -> V_274 . V_536 . V_543 ;
V_520 -> V_544 = V_267 -> V_274 . V_536 . V_545 ;
V_520 -> V_546 = V_267 -> V_274 . V_536 . V_547 ;
V_520 -> V_548 = V_267 -> V_274 . V_536 . V_547 ;
if ( V_18 -> V_19 & V_497 )
V_520 -> V_551 = ( V_18 -> V_551 >> 1 ) ;
else
V_520 -> V_551 = ( V_18 -> V_552 >> 1 ) ;
V_208 -> V_554 = F_182 () ;
F_42 ( V_168 , V_18 -> V_174 ) ;
return;
}
static struct V_25 *
F_184 ( struct V_557 * V_558 )
{
struct V_12 * V_13 = F_185 ( V_558 -> V_6 . V_559 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_25 * V_26 ;
F_11 ( V_13 -> V_81 ) ;
F_12 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_119 ( V_26 ) &&
V_26 -> V_466 == V_560 &&
V_558 -> V_561 == V_26 -> V_562 ) {
F_13 ( V_13 -> V_81 ) ;
return V_26 ;
}
}
F_13 ( V_13 -> V_81 ) ;
return NULL ;
}
static void
F_186 ( struct V_557 * V_558 )
{
struct V_25 * V_26 = F_184 ( V_558 ) ;
F_187 ( V_558 ) = V_26 ? V_26 -> V_563 : - 1 ;
}
static void
F_188 ( struct V_557 * V_558 )
{
struct V_25 * V_26 = F_184 ( V_558 ) ;
F_189 ( V_558 ) =
V_26 ? F_7 ( V_26 -> V_564 . V_40 . V_41 ) : 0 ;
}
static void
F_190 ( struct V_557 * V_558 )
{
struct V_25 * V_26 = F_184 ( V_558 ) ;
F_191 ( V_558 ) =
V_26 ? F_7 ( V_26 -> V_413 . V_40 . V_41 ) : 0 ;
}
static void
F_192 ( struct V_565 * V_367 , T_3 V_566 )
{
if ( V_566 )
V_367 -> V_368 = V_566 ;
else
V_367 -> V_368 = 1 ;
}
static void
F_193 ( struct V_567 * V_567 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_567 -> V_568 ;
if ( V_15 -> V_83 == V_145 )
F_194 ( V_15 , V_569 , 0 , 0 ) ;
}
static void
F_195 ( struct V_17 * V_18 , T_3 V_570 )
{
V_18 -> V_571 = V_570 ;
}
void
F_196 ( struct V_17 * V_18 )
{
F_197 ( V_18 , V_572 ) ;
F_198 ( V_18 , V_573 ) ;
F_199 ( V_18 , V_574 ) ;
F_200 ( V_18 , V_575 ) ;
F_201 ( V_18 , V_576 ) ;
F_202 ( V_18 , V_577 ) ;
F_203 ( V_18 , V_578 ) ;
F_204 ( V_18 , V_579 ) ;
F_205 ( V_18 , V_580 ) ;
F_140 ( V_18 , V_581 ) ;
F_206 ( V_18 , V_582 ) ;
F_207 ( V_18 , V_583 ) ;
F_208 ( V_18 , V_584 ) ;
F_209 ( V_18 , V_585 ) ;
F_210 ( V_18 , V_586 ) ;
F_211 ( V_18 , V_587 ) ;
F_212 ( V_18 , V_588 ) ;
F_213 ( V_18 , V_589 ) ;
F_214 ( V_18 , V_590 ) ;
F_215 ( V_18 , V_591 ) ;
F_152 ( V_18 , V_592 ) ;
F_155 ( V_18 , V_593 ) ;
F_216 ( V_18 , V_594 ) ;
F_217 ( V_18 , V_595 ) ;
F_218 ( V_18 , V_596 ) ;
if ( V_18 -> V_119 != V_120 )
V_18 -> V_597 = 0 ;
F_219 ( V_18 , V_598 ) ;
memset ( V_18 -> V_329 , 0 , ( 8 * sizeof( T_4 ) ) ) ;
memset ( V_18 -> V_340 , 0 , ( 8 * sizeof( T_4 ) ) ) ;
V_18 -> V_343 = 0 ;
V_18 -> V_345 = 0 ;
V_18 -> V_332 = 0 ;
V_18 -> V_337 = 0 ;
F_220 ( V_18 , V_599 ) ;
F_221 ( V_18 , V_600 ) ;
F_222 ( V_18 , V_601 ) ;
if ( V_18 -> V_119 == V_120 )
V_18 -> V_292 = 0 ;
else
V_18 -> V_292 = V_602 ;
F_223 ( V_18 , V_603 ) ;
F_224 ( V_18 , V_604 ) ;
F_225 ( V_18 , V_605 ) ;
F_226 ( V_18 , V_606 ) ;
F_227 ( V_18 , V_607 ) ;
F_228 ( V_18 , V_608 ) ;
F_229 ( V_18 , V_609 ) ;
if ( V_18 -> V_119 != V_120 ) {
V_18 -> V_37 = 0 ;
V_18 -> V_35 = V_610 ;
} else {
if ( ! ( V_18 -> V_35 & V_610 ) )
V_18 -> V_35 |= V_610 ;
}
if ( V_18 -> V_611 && ! V_18 -> V_442 )
V_18 -> V_611 = 0 ;
V_18 -> V_443 = V_18 -> V_442 ;
if ( V_18 -> V_612 == 0 )
V_18 -> V_612 = V_18 -> V_73 . V_454 ;
if ( V_18 -> V_613 == 0 )
V_18 -> V_613 = V_18 -> V_73 . V_454 ;
if ( V_18 -> V_35 == V_36 )
V_18 -> V_612 = 0 ;
if ( V_18 -> V_35 == V_610 )
V_18 -> V_613 = 0 ;
if ( V_18 -> V_612 > V_18 -> V_613 )
V_18 -> V_444 = V_18 -> V_612 ;
else
V_18 -> V_444 = V_18 -> V_613 ;
V_18 -> V_326 = 0L ;
V_18 -> V_320 = 0L ;
F_230 ( V_18 , V_614 ) ;
F_231 ( V_18 , V_615 ) ;
F_232 ( V_18 , V_616 ) ;
F_195 ( V_18 , V_617 ) ;
F_233 ( V_18 , V_618 ) ;
F_234 ( V_18 , V_619 ) ;
F_149 ( V_18 , V_620 ) ;
F_235 ( V_18 , V_621 ) ;
F_236 ( V_18 , V_622 ) ;
F_237 ( V_18 , V_623 ) ;
F_238 ( V_18 , V_624 ) ;
V_18 -> V_304 = 1 ;
F_239 ( V_18 , V_625 ) ;
return;
}
void
F_240 ( struct V_17 * V_18 )
{
if ( V_18 -> V_613 > V_18 -> V_73 . V_454 )
V_18 -> V_613 = V_18 -> V_73 . V_454 ;
if ( V_18 -> V_612 > V_18 -> V_73 . V_454 )
V_18 -> V_612 = V_18 -> V_73 . V_454 ;
if ( V_18 -> V_35 & V_36 &&
V_18 -> V_37 ) {
V_18 -> V_35 &= ~ V_610 ;
V_18 -> V_612 = 0 ;
F_40 ( V_18 , V_358 , V_626 ,
L_184 ,
L_185 ,
V_18 -> V_627 ,
V_18 -> V_628 ,
V_629 ) ;
if ( V_18 -> V_627 == 0 )
V_18 -> V_628 = 0 ;
else {
if ( V_18 -> V_628 > V_629 )
V_18 -> V_628 = V_629 ;
}
if ( V_18 -> V_630 > V_18 -> V_613 ) {
V_18 -> V_630 = V_18 -> V_613 ;
F_40 ( V_18 , V_190 , V_626 ,
L_186 ,
V_18 -> V_630 ) ;
}
} else {
V_18 -> V_37 = 0 ;
V_18 -> V_630 = 0 ;
V_18 -> V_628 = 0 ;
}
if ( V_18 -> V_612 > V_18 -> V_613 )
V_18 -> V_444 = V_18 -> V_612 ;
else
V_18 -> V_444 = V_18 -> V_613 ;
}
void
F_241 ( struct V_14 * V_15 )
{
F_242 ( V_15 , V_617 ) ;
F_243 ( V_15 , V_631 ) ;
F_244 ( V_15 , V_632 ) ;
F_245 ( V_15 , V_370 ) ;
F_116 ( V_15 , V_633 ) ;
F_246 ( V_15 , V_634 ) ;
F_123 ( V_15 , V_635 ) ;
F_247 ( V_15 , V_636 ) ;
F_248 ( V_15 , V_637 ) ;
F_249 ( V_15 , V_638 ) ;
F_250 ( V_15 , V_639 ) ;
F_251 ( V_15 , V_640 ) ;
F_252 ( V_15 , V_641 ) ;
F_253 ( V_15 , V_642 ) ;
F_254 ( V_15 , V_643 ) ;
return;
}
