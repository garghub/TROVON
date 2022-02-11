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
V_32 = F_8 ( & V_22 -> V_57 ) ;
V_32 += F_8 ( & V_22 -> V_56 ) ;
V_32 = F_8 ( & V_22 -> V_54 ) - V_32 ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_23
L_24 ,
V_18 -> V_73 . V_74 ,
V_18 -> V_73 . V_75 ,
V_18 -> V_73 . V_76 ,
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
F_9 ( V_13 -> V_77 ) ;
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
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! V_26 -> V_28 )
continue;
V_28 = V_26 -> V_28 -> V_78 ;
switch ( V_28 -> V_79 ) {
case V_80 :
V_33 = L_27 ;
break;
case V_81 :
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
V_28 -> V_82 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_35 ,
V_28 -> V_83 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_36 ,
V_28 -> V_42 ) ;
if ( V_28 -> V_84 & V_85 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_37 ) ;
if ( V_28 -> V_84 & V_86 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_38 ) ;
if ( V_28 -> V_84 & V_87 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_39 ) ;
if ( V_28 -> V_84 & ~ ( V_85 |
V_86 |
V_87 ) )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_40 ,
V_28 -> V_84 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_41 , V_33 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_1 ) ;
}
F_11 ( V_13 -> V_77 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_42 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_43 ,
F_8 ( & V_18 -> V_88 ) ,
F_8 ( & V_18 -> V_89 ) ) ;
V_32 = F_8 ( & V_18 -> V_90 ) ;
V_29 = F_8 ( & V_18 -> V_91 ) ;
V_30 = F_8 ( & V_18 -> V_92 ) ;
V_31 = F_8 ( & V_18 -> V_93 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_44 ,
V_29 , V_30 , V_31 ) ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_45 ,
V_32 , ( V_29 + V_30 + V_31 ) - V_32 ) ;
return V_34 ;
}
static T_1
F_12 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_94 )
if ( V_18 -> V_95 & V_96 )
return snprintf ( V_9 , V_10 , L_46 ) ;
else
return snprintf ( V_9 , V_10 ,
L_47 ) ;
else
return snprintf ( V_9 , V_10 ,
L_48 ) ;
}
static T_1
F_13 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 ,
( unsigned long long ) V_18 -> V_97 ) ;
}
static T_1
F_14 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 ,
( unsigned long long ) V_18 -> V_98 ) ;
}
static T_1
F_15 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_49 ,
( unsigned long long ) V_18 -> V_99 ) ;
}
static T_1
F_16 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_100 = F_4 ( V_6 ) ;
return snprintf ( V_9 , V_10 , L_50 , F_17 ( V_100 ) ) ;
}
static T_1
F_18 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_50 , V_18 -> V_101 ) ;
}
static T_1
F_19 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_102 ) ;
}
static T_1
F_20 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_50 , V_18 -> V_103 ) ;
}
static T_1
F_21 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_50 , V_18 -> V_104 ) ;
}
static T_1
F_22 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_50 , V_18 -> V_105 ) ;
}
static T_1
F_23 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 ,
( V_18 -> V_106 . V_107 & V_108 ) ) ;
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
F_25 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_110 ;
T_4 V_111 ;
char V_112 [ V_113 ] ;
int V_34 ;
F_26 ( V_18 , V_112 , 1 ) ;
V_110 = V_18 -> V_73 . V_114 . V_110 ;
V_111 = V_18 -> V_73 . V_114 . V_111 ;
if ( V_18 -> V_115 < V_116 )
V_34 = snprintf ( V_9 , V_10 , L_52 ,
V_112 , V_18 -> V_115 ) ;
else
V_34 = snprintf ( V_9 , V_10 , L_53 ,
V_112 , V_18 -> V_115 , V_110 , V_111 ) ;
return V_34 ;
}
static T_1
F_27 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
char V_2 [ 9 ] ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_5 * V_117 = & V_18 -> V_118 ;
F_1 ( V_117 -> V_119 . V_120 , V_2 ) ;
return snprintf ( V_9 , V_10 , L_50 , V_2 ) ;
}
static T_1
F_28 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char V_112 [ V_113 ] ;
if ( V_18 -> V_115 < V_116 )
return snprintf ( V_9 , V_10 , L_50 , V_18 -> V_121 ) ;
F_26 ( V_18 , V_112 , 1 ) ;
return snprintf ( V_9 , V_10 , L_50 , V_112 ) ;
}
static T_1
F_29 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_34 = 0 ;
switch ( V_18 -> V_122 ) {
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
if ( V_18 -> V_19 & V_129 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_54 ) ;
else
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_55 ) ;
break;
case V_130 :
case V_131 :
case V_132 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_56 ) ;
switch ( V_15 -> V_79 ) {
case V_133 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_57 ) ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_58 ) ;
break;
case V_141 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_59 ) ;
break;
case V_142 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_60 ) ;
break;
case V_143 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_61 ) ;
break;
}
if ( V_18 -> V_106 . V_107 & V_108 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_62 ) ;
else if ( V_18 -> V_144 == V_145 ) {
if ( V_15 -> V_146 & V_147 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_63 ) ;
else
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_64 ) ;
} else {
if ( V_15 -> V_146 & V_148 )
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
F_30 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_115 < V_116 )
return snprintf ( V_9 , V_10 , L_67 ) ;
if ( V_18 -> V_73 . V_149 . V_150 == V_151 ) {
if ( V_18 -> V_73 . V_149 . V_152 == V_153 )
return snprintf ( V_9 , V_10 , L_68 ) ;
if ( V_18 -> V_73 . V_149 . V_152 == V_154 )
return snprintf ( V_9 , V_10 , L_67 ) ;
}
return snprintf ( V_9 , V_10 , L_69 ) ;
}
static T_1
F_31 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 ,
V_18 -> V_73 . V_114 . V_155 ) ;
}
static T_1
F_32 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_157 = - V_158 ;
if ( ( strncmp ( V_9 , L_70 , sizeof( L_70 ) - 1 ) == 0 ) &&
( V_18 -> V_122 == V_127 ) )
V_157 = V_18 -> V_159 ( V_18 , V_160 ) ;
else if ( ( strncmp ( V_9 , L_71 , sizeof( L_71 ) - 1 ) == 0 ) &&
( V_18 -> V_122 >= V_130 ) )
V_157 = V_18 -> V_161 ( V_18 , V_160 ) ;
if ( V_157 == 0 )
return strlen ( V_9 ) ;
else
return V_157 ;
}
static T_1
F_33 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_51 ,
V_15 -> V_162 + V_15 -> V_163 ) ;
}
static int
F_34 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_7 * V_164 ;
int V_165 = V_166 ;
if ( ( V_15 -> V_146 & V_167 ) ||
( V_18 -> V_106 . V_107 & V_168 ) )
return - V_169 ;
V_164 = F_35 ( V_18 -> V_170 , V_171 ) ;
if ( ! V_164 )
return - V_172 ;
memset ( ( void * ) V_164 , 0 , sizeof ( T_7 ) ) ;
V_164 -> V_40 . V_173 . V_174 = V_175 ;
V_164 -> V_40 . V_173 . V_176 = V_177 ;
V_165 = F_36 ( V_18 , V_164 , V_178 * 2 ) ;
if ( ( V_165 == V_179 ) &&
( V_164 -> V_40 . V_173 . V_180 == 0 ||
V_164 -> V_40 . V_173 . V_180 == V_181 ) ) {
memset ( ( void * ) V_164 , 0 , sizeof ( T_7 ) ) ;
F_37 ( V_18 , V_164 , V_18 -> V_182 ,
V_18 -> V_183 ) ;
V_165 = F_36 ( V_18 , V_164 ,
V_18 -> V_184 * 2 ) ;
if ( ( V_165 == V_179 ) &&
( V_164 -> V_40 . V_173 . V_180 == V_185 ) )
F_38 ( V_18 , V_186 , V_187 | V_188 ,
L_72
L_73 ) ;
}
F_39 ( V_18 ) ;
if ( V_165 != V_189 )
F_40 ( V_164 , V_18 -> V_170 ) ;
if ( V_165 == V_166 )
return - V_190 ;
return 0 ;
}
int
F_41 ( struct V_17 * V_18 , struct V_191 * V_192 , T_8 * V_193 )
{
int V_194 = 0 ;
F_9 ( V_193 ) ;
while ( ! F_42 ( V_192 ) ) {
F_11 ( V_193 ) ;
F_43 ( 20 ) ;
if ( V_194 ++ > 250 ) {
F_38 ( V_18 , V_195 , V_196 ,
L_74 ,
L_75 ,
L_76 ) ;
return 0 ;
}
F_9 ( V_193 ) ;
}
F_11 ( V_193 ) ;
return 1 ;
}
static int
F_44 ( struct V_17 * V_18 , T_3 type )
{
struct V_197 V_198 ;
struct V_199 * V_200 = NULL ;
struct V_201 * V_202 ;
struct V_203 * V_204 ;
int V_157 = 0 ;
int V_3 ;
int V_205 ;
F_45 ( & V_198 ) ;
V_205 = F_46 ( V_18 , & V_157 , & V_198 ,
V_206 ) ;
if ( V_205 == 0 )
return - V_172 ;
F_47 ( & V_198 ) ;
if ( V_157 != 0 )
return - V_190 ;
V_204 = & V_18 -> V_106 ;
if ( V_18 -> V_115 != V_116 ) {
for ( V_3 = 0 ; V_3 < V_204 -> V_207 ; V_3 ++ ) {
V_202 = & V_204 -> V_208 [ V_3 ] ;
if ( ! F_41 ( V_18 , & V_202 -> V_209 ,
& V_18 -> V_210 ) )
goto V_211;
}
} else {
F_10 (qp, &phba->sli4_hba.lpfc_wq_list, wq_list) {
V_202 = V_200 -> V_202 ;
if ( ! V_202 )
continue;
if ( ! F_41 ( V_18 , & V_202 -> V_209 ,
& V_202 -> V_212 ) )
goto V_211;
}
}
V_211:
F_45 ( & V_198 ) ;
V_205 = F_46 ( V_18 , & V_157 , & V_198 , type ) ;
if ( V_205 == 0 )
return - V_172 ;
F_47 ( & V_198 ) ;
if ( V_157 != 0 )
return - V_190 ;
return 0 ;
}
int
F_48 ( struct V_17 * V_18 )
{
struct V_197 V_198 ;
int V_157 = 0 ;
int V_205 ;
if ( ! V_18 -> V_213 )
return - V_214 ;
if ( ! ( V_18 -> V_215 -> V_146 & V_167 ) ) {
V_157 = F_44 ( V_18 , V_216 ) ;
if ( V_157 != 0 )
return V_157 ;
}
F_45 ( & V_198 ) ;
V_205 = F_46 ( V_18 , & V_157 , & V_198 ,
V_217 ) ;
if ( V_205 == 0 )
return - V_172 ;
F_47 ( & V_198 ) ;
if ( V_157 != 0 )
return - V_190 ;
return 0 ;
}
static T_1
F_49 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_157 = - V_158 ;
if ( ! V_18 -> V_213 )
return - V_214 ;
if ( strncmp ( V_9 , L_77 , sizeof( L_77 ) - 1 ) == 0 )
V_157 = V_18 -> F_48 ( V_18 ) ;
if ( V_157 == 0 )
return strlen ( V_9 ) ;
else
return V_157 ;
}
int
F_50 ( struct V_17 * V_18 )
{
struct V_218 V_219 = { 0 } ;
int V_3 ;
F_43 ( 100 ) ;
F_51 ( V_18 -> V_73 . V_40 . V_220 . V_221 ,
& V_219 . V_222 ) ;
if ( ! F_52 ( V_223 , & V_219 ) &&
! F_52 ( V_224 , & V_219 ) )
return - V_169 ;
for ( V_3 = 0 ; V_3 < V_225 ; V_3 ++ ) {
F_43 ( 10 ) ;
F_51 ( V_18 -> V_73 . V_40 . V_220 . V_221 ,
& V_219 . V_222 ) ;
if ( ! F_52 ( V_224 , & V_219 ) )
continue;
if ( ! F_52 ( V_223 , & V_219 ) )
continue;
if ( ! F_52 ( V_226 , & V_219 ) )
continue;
break;
}
if ( V_3 < V_225 )
return 0 ;
else
return - V_190 ;
}
static T_1
F_53 ( struct V_17 * V_18 , T_3 V_227 )
{
struct V_197 V_198 ;
struct V_228 * V_229 = V_18 -> V_230 ;
T_3 V_231 ;
T_3 V_232 ;
T_3 V_233 ;
int V_157 = 0 , V_205 = 0 ;
int V_234 = 1 , V_235 ;
if ( ! V_18 -> V_213 )
return - V_214 ;
if ( ( V_18 -> V_115 < V_116 ) ||
( F_52 ( V_236 , & V_18 -> V_73 . V_237 ) !=
V_238 ) )
return - V_169 ;
V_231 = V_18 -> V_215 -> V_146 ;
V_232 = V_18 -> V_239 ;
if ( V_18 -> V_239 ) {
F_54 ( V_229 ) ;
V_18 -> V_239 = 0 ;
}
if ( V_227 == V_240 )
V_18 -> V_19 |= V_241 ;
V_157 = F_44 ( V_18 , V_216 ) ;
if ( V_157 != 0 ) {
V_18 -> V_19 &= ~ V_241 ;
return V_157 ;
}
F_43 ( 100 ) ;
V_233 = F_55 ( V_18 -> V_73 . V_242 +
V_243 ) ;
if ( V_227 == V_240 )
V_233 |= V_244 ;
else if ( V_227 == V_245 )
V_233 |= V_246 ;
else if ( V_227 == V_247 )
V_233 |= V_248 ;
F_56 ( V_233 , V_18 -> V_73 . V_242 +
V_243 ) ;
F_55 ( V_18 -> V_73 . V_242 + V_243 ) ;
V_205 = F_50 ( V_18 ) ;
if ( V_205 == - V_169 ) {
F_38 ( V_18 , V_186 , V_188 ,
L_78
L_79 , V_233 ) ;
} else if ( V_205 == - V_190 ) {
F_38 ( V_18 , V_186 , V_188 ,
L_80
L_79 , V_233 ) ;
return V_205 ;
}
if ( V_231 & V_167 )
goto V_211;
F_45 ( & V_198 ) ;
V_234 = F_46 ( V_18 , & V_157 , & V_198 ,
V_217 ) ;
if ( ! V_234 )
goto V_211;
F_47 ( & V_198 ) ;
V_211:
if ( V_232 ) {
V_235 =
F_57 ( V_18 , V_232 ) ;
if ( ! V_235 )
V_18 -> V_239 = V_232 ;
}
if ( ! V_205 ) {
if ( ! V_234 )
V_205 = - V_172 ;
else if ( V_157 )
V_205 = - V_190 ;
}
return V_205 ;
}
static T_1
F_58 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_249 ) ;
}
static T_1
F_59 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char * V_250 ;
if ( V_18 -> V_122 == V_128 )
V_250 = L_81 ;
else if ( V_18 -> V_122 == V_124 )
V_250 = L_82 ;
else if ( V_18 -> V_122 == V_125 )
V_250 = L_83 ;
else
V_250 = L_84 ;
return snprintf ( V_9 , V_10 , L_50 , V_250 ) ;
}
static T_1
F_60 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_197 V_198 ;
char * V_251 = NULL ;
int V_157 = 0 ;
int V_205 ;
if ( ! V_18 -> V_213 ) {
V_157 = - V_214 ;
goto V_252;
}
F_61 ( V_15 , V_186 , V_196 ,
L_85 , V_9 ) ;
F_45 ( & V_198 ) ;
if( strncmp ( V_9 , L_84 , sizeof( L_84 ) - 1 ) == 0 ) {
V_205 = F_46 ( V_18 , & V_157 , & V_198 ,
V_217 ) ;
if ( V_205 == 0 ) {
V_157 = - V_172 ;
goto V_252;
}
F_47 ( & V_198 ) ;
if ( V_157 )
V_157 = - V_190 ;
} else if ( strncmp ( V_9 , L_83 , sizeof( L_83 ) - 1 ) == 0 )
V_157 = F_44 ( V_18 , V_216 ) ;
else if ( strncmp ( V_9 , L_86 , sizeof( L_86 ) - 1 ) == 0 )
if ( V_18 -> V_115 == V_116 )
V_157 = - V_158 ;
else
V_157 = F_44 ( V_18 , V_253 ) ;
else if ( strncmp ( V_9 , L_81 , sizeof( L_81 ) - 1 ) == 0 )
if ( V_18 -> V_115 == V_116 )
V_157 = - V_158 ;
else
V_157 = F_44 ( V_18 , V_254 ) ;
else if ( strncmp ( V_9 , L_87 , sizeof( L_87 ) - 1 ) == 0 )
V_157 = F_53 ( V_18 , V_240 ) ;
else if ( strncmp ( V_9 , L_88 , sizeof( L_88 ) - 1 ) == 0 )
V_157 = F_53 ( V_18 , V_245 ) ;
else if ( strncmp ( V_9 , L_89 , sizeof( L_89 ) - 1 ) == 0 )
V_157 = F_53 ( V_18 , V_247 ) ;
else
V_157 = - V_158 ;
V_252:
if ( ! V_157 )
return strlen ( V_9 ) ;
else {
V_251 = strchr ( V_9 , '\n' ) ;
if ( V_251 )
* V_251 = '\0' ;
F_61 ( V_15 , V_186 , V_196 ,
L_90
L_91 ,
V_9 , V_157 , V_18 -> V_215 -> V_146 ) ;
return V_157 ;
}
}
static int
F_62 ( struct V_17 * V_18 ,
T_3 * V_255 , T_3 * V_256 ,
T_3 * V_257 , T_3 * V_258 ,
T_3 * V_259 , T_3 * V_260 )
{
struct V_261 * V_262 ;
T_7 * V_164 ;
T_9 * V_263 ;
int V_205 = 0 ;
T_3 V_264 ;
if ( V_18 -> V_122 < V_127 ||
! V_18 -> V_170 ||
( V_18 -> V_106 . V_107 & V_265 ) == 0 )
return 0 ;
if ( V_18 -> V_106 . V_107 & V_168 )
return 0 ;
V_164 = F_35 ( V_18 -> V_170 , V_171 ) ;
if ( ! V_164 )
return 0 ;
memset ( V_164 , 0 , sizeof ( T_7 ) ) ;
V_263 = & V_164 -> V_40 . V_173 ;
V_263 -> V_174 = V_266 ;
V_263 -> V_176 = V_177 ;
V_164 -> V_267 = NULL ;
if ( V_18 -> V_215 -> V_146 & V_167 )
V_205 = V_268 ;
else
V_205 = F_36 ( V_18 , V_164 , V_18 -> V_184 * 2 ) ;
if ( V_205 != V_179 ) {
if ( V_205 != V_189 )
F_40 ( V_164 , V_18 -> V_170 ) ;
return 0 ;
}
if ( V_18 -> V_115 == V_116 ) {
V_262 = & V_164 -> V_40 . V_269 . V_270 . V_262 ;
if ( V_257 )
* V_257 = F_52 ( V_271 , V_262 ) ;
if ( V_258 )
* V_258 = F_52 ( V_271 , V_262 ) -
V_18 -> V_73 . V_272 . V_273 ;
if ( V_255 )
* V_255 = F_52 ( V_274 , V_262 ) ;
if ( V_256 )
* V_256 = F_52 ( V_274 , V_262 ) -
V_18 -> V_73 . V_272 . V_275 ;
V_264 = ( F_52 ( V_276 , V_262 ) > 0 ) ?
( F_52 ( V_276 , V_262 ) - 1 ) : 0 ;
if ( V_259 )
* V_259 = V_264 ;
if ( V_260 )
* V_260 = V_264 - V_18 -> V_73 . V_272 . V_277 ;
} else {
if ( V_257 )
* V_257 = V_263 -> V_270 . V_278 . V_279 ;
if ( V_258 )
* V_258 = V_263 -> V_270 . V_278 . V_280 ;
if ( V_255 )
* V_255 = V_263 -> V_270 . V_278 . V_281 ;
if ( V_256 )
* V_256 = V_263 -> V_270 . V_278 . V_282 ;
if ( V_259 )
* V_259 = V_263 -> V_270 . V_278 . V_264 ;
if ( V_260 )
* V_260 = V_263 -> V_270 . V_278 . V_283 ;
}
F_40 ( V_164 , V_18 -> V_170 ) ;
return 1 ;
}
static T_1
F_63 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_194 ;
if ( F_62 ( V_18 , NULL , NULL , & V_194 , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_51 , V_194 ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_64 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_194 , V_284 ;
if ( F_62 ( V_18 , NULL , NULL , & V_194 , & V_284 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_51 , ( V_194 - V_284 ) ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_65 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_194 ;
if ( F_62 ( V_18 , & V_194 , NULL , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_51 , V_194 ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_66 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_194 , V_284 ;
if ( F_62 ( V_18 , & V_194 , & V_284 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_51 , ( V_194 - V_284 ) ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_67 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_194 ;
if ( F_62 ( V_18 , NULL , NULL , NULL , NULL , & V_194 , NULL ) )
return snprintf ( V_9 , V_10 , L_51 , V_194 ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_68 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_194 , V_284 ;
if ( F_62 ( V_18 , NULL , NULL , NULL , NULL , & V_194 , & V_284 ) )
return snprintf ( V_9 , V_10 , L_51 , ( V_194 - V_284 ) ) ;
return snprintf ( V_9 , V_10 , L_61 ) ;
}
static T_1
F_69 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_264 ) )
return snprintf ( V_9 , V_10 , L_92 ) ;
if ( V_15 -> V_285 == V_286 )
return snprintf ( V_9 , V_10 , L_93 ) ;
return snprintf ( V_9 , V_10 , L_94 , V_15 -> V_287 ) ;
}
static T_1
F_70 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_95 , V_18 -> V_288 ) ;
}
static T_1
F_71 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_3 V_289 ;
T_3 V_290 ;
int V_291 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_158 ;
if ( sscanf ( V_9 , L_96 , & V_291 ) != 1 )
return - V_158 ;
if ( ( V_291 & 0x3 ) != V_291 )
return - V_158 ;
if ( V_18 -> V_115 == V_116 )
V_291 = 0 ;
F_61 ( V_15 , V_186 , V_196 ,
L_97 ,
V_18 -> V_288 , V_291 ) ;
F_9 ( & V_18 -> V_210 ) ;
V_290 = V_18 -> V_288 ;
if ( V_291 & V_292 ) {
if ( ( V_291 & V_293 ) &&
! ( V_290 & V_293 ) ) {
if ( F_51 ( V_18 -> V_294 , & V_289 ) ) {
F_11 ( & V_18 -> V_210 ) ;
return - V_158 ;
}
V_289 &= ~ ( V_295 << V_296 ) ;
F_56 ( V_289 , V_18 -> V_294 ) ;
F_55 ( V_18 -> V_294 ) ;
F_72 ( V_18 ) ;
}
} else if ( V_291 != 0x0 ) {
F_11 ( & V_18 -> V_210 ) ;
return - V_158 ;
}
if ( ! ( V_291 & V_293 ) &&
( V_290 & V_293 ) )
{
F_11 ( & V_18 -> V_210 ) ;
F_73 ( & V_18 -> V_297 ) ;
F_9 ( & V_18 -> V_210 ) ;
if ( F_51 ( V_18 -> V_294 , & V_289 ) ) {
F_11 ( & V_18 -> V_210 ) ;
return - V_158 ;
}
V_289 |= ( V_295 << V_296 ) ;
F_56 ( V_289 , V_18 -> V_294 ) ;
F_55 ( V_18 -> V_294 ) ;
}
V_18 -> V_288 = V_291 ;
F_11 ( & V_18 -> V_210 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_74 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_298 ) ;
}
static T_1
F_75 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_299 ) ;
}
static T_1
F_76 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_98 ,
( V_18 -> V_300 ) ? L_99 : L_100 ,
( V_18 -> V_95 & V_301 ) ?
L_101 : L_102 ) ;
}
static T_1
F_77 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_10 V_302 ;
V_302 = F_78 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_51 , V_302 ) ;
}
static inline bool F_79 ( T_11 V_291 , T_11 V_303 , T_11 V_304 )
{
return V_291 >= V_303 && V_291 <= V_304 ;
}
static T_1
F_80 ( struct V_17 * V_18 , T_11 V_291 )
{
if ( F_79 ( V_291 , 0 , 1 ) && V_18 -> V_115 == V_116 ) {
F_38 ( V_18 , V_186 , V_196 ,
L_103 ,
V_305 , V_18 -> V_306 , V_291 ) ;
V_18 -> V_306 = V_291 ;
return 0 ;
}
F_38 ( V_18 , V_186 , V_196 ,
L_104 ,
V_305 , V_291 ) ;
return - V_158 ;
}
static T_6
F_81 ( const char * V_9 , T_6 V_194 , char V_41 [] )
{
unsigned int V_3 , V_4 ;
if ( V_9 [ V_194 - 1 ] == '\n' )
V_194 -- ;
if ( ( V_194 < 16 ) || ( V_194 > 18 ) || ( ( V_194 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_194 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_158 ;
memset ( V_41 , 0 , V_307 ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( ( * V_9 >= 'a' ) && ( * V_9 <= 'f' ) )
V_4 = ( ( V_4 << 4 ) | ( ( * V_9 ++ - 'a' ) + 10 ) ) ;
else if ( ( * V_9 >= 'A' ) && ( * V_9 <= 'F' ) )
V_4 = ( ( V_4 << 4 ) | ( ( * V_9 ++ - 'A' ) + 10 ) ) ;
else if ( ( * V_9 >= '0' ) && ( * V_9 <= '9' ) )
V_4 = ( ( V_4 << 4 ) | ( * V_9 ++ - '0' ) ) ;
else
return - V_158 ;
if ( V_3 % 2 ) {
V_41 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
return 0 ;
}
static T_1
F_82 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
unsigned int V_194 = V_156 ;
T_4 V_308 = V_15 -> V_309 . V_310 . V_311 ;
T_12 * V_312 = ( T_3 * ) & V_15 -> V_309 . V_270 . V_313 [ 0 ] ;
if ( V_308 == 1 && F_83 ( * V_312 ) == V_314 ) {
F_38 ( V_18 , V_186 , V_196 ,
L_105 V_305 L_106
L_107 ) ;
return - V_158 ;
}
if ( V_9 [ V_194 - 1 ] == '\n' )
V_194 -- ;
if ( ( V_194 != strlen ( V_315 ) ) ||
( strncmp ( V_9 , V_315 , strlen ( V_315 ) ) != 0 ) )
return - V_158 ;
V_18 -> V_316 = 1 ;
F_84 ( V_195 , & V_18 -> V_230 -> V_6 ,
L_108 ,
V_18 -> V_43 ) ;
F_84 ( V_195 , & V_18 -> V_230 -> V_6 ,
L_109 ) ;
return V_156 ;
}
static T_1
F_85 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_110 ,
( unsigned long long ) V_18 -> V_317 ) ;
}
static T_1
F_86 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_197 V_198 ;
int V_318 = 0 , V_319 = 0 ;
unsigned int V_194 = V_156 ;
T_13 V_320 [ V_307 ] ;
int V_205 ;
if ( ! V_18 -> V_213 )
return - V_214 ;
F_9 ( & V_18 -> V_210 ) ;
if ( V_18 -> V_321 == V_322 ) {
F_11 ( & V_18 -> V_210 ) ;
return - V_214 ;
}
F_11 ( & V_18 -> V_210 ) ;
if ( V_9 [ V_194 - 1 ] == '\n' )
V_194 -- ;
if ( ! V_18 -> V_316 )
return - V_158 ;
V_18 -> V_316 = 0 ;
V_205 = F_81 ( V_9 , V_194 , V_320 ) ;
if ( V_205 ) {
V_18 -> V_316 = 1 ;
return V_205 ;
}
V_18 -> V_317 = F_7 ( V_320 ) ;
F_87 ( V_13 ) = V_18 -> V_317 ;
if ( V_18 -> V_323 )
F_88 ( V_13 ) = V_18 -> V_323 ;
F_84 ( V_324 , & V_18 -> V_230 -> V_6 ,
L_111 , V_18 -> V_43 ) ;
V_318 = F_44 ( V_18 , V_216 ) ;
if ( V_318 )
F_38 ( V_18 , V_186 , V_196 ,
L_112
L_113 , V_318 ) ;
F_45 ( & V_198 ) ;
V_205 = F_46 ( V_18 , & V_319 , & V_198 ,
V_217 ) ;
if ( V_205 == 0 )
return - V_172 ;
F_47 ( & V_198 ) ;
if ( V_319 )
F_38 ( V_18 , V_186 , V_196 ,
L_114
L_113 , V_319 ) ;
return ( V_318 || V_319 ) ? - V_190 : V_156 ;
}
static T_1
F_89 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_110 ,
( unsigned long long ) V_18 -> V_323 ) ;
}
static T_1
F_90 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_194 = V_156 ;
T_13 V_325 [ V_307 ] ;
int V_205 ;
if ( V_9 [ V_194 - 1 ] == '\n' )
V_194 -- ;
if ( ! V_18 -> V_316 )
return - V_158 ;
V_205 = F_81 ( V_9 , V_194 , V_325 ) ;
if ( V_205 ) {
return V_205 ;
}
V_18 -> V_323 = F_7 ( V_325 ) ;
F_84 ( V_324 , & V_18 -> V_230 -> V_6 ,
L_115
L_116 , V_18 -> V_43 ) ;
return V_156 ;
}
static T_1
F_91 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_110 ,
F_7 ( V_18 -> V_326 ) ) ;
}
static T_1
F_92 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_194 = V_156 ;
T_4 V_320 [ V_307 ] ;
int V_205 ;
if ( ! V_18 -> V_327 )
return - V_169 ;
if ( V_9 [ V_194 - 1 ] == '\n' )
V_194 -- ;
V_205 = F_81 ( V_9 , V_194 , V_320 ) ;
if ( V_205 )
return V_205 ;
memcpy ( V_18 -> V_326 , V_320 , ( 8 * sizeof( T_4 ) ) ) ;
memcpy ( V_18 -> V_73 . V_328 , V_320 , ( 8 * sizeof( T_4 ) ) ) ;
if ( F_7 ( V_320 ) == 0 )
V_18 -> V_329 |= V_330 ;
else
V_18 -> V_329 &= ~ V_330 ;
V_18 -> V_329 &= ~ V_331 ;
V_18 -> V_73 . V_332 = V_333 ;
return V_156 ;
}
static T_1
F_93 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_334 ) ;
}
static T_1
F_94 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_194 = V_156 ;
unsigned long V_291 ;
int V_335 ;
if ( ! V_18 -> V_327 )
return - V_169 ;
if ( V_9 [ V_194 - 1 ] == '\n' )
V_194 -- ;
V_335 = F_95 ( V_9 , 0 , & V_291 ) ;
if ( V_335 || ( V_291 > 0x7f ) )
return - V_158 ;
if ( V_291 )
V_18 -> V_334 = ( T_4 ) V_291 ;
else
V_18 -> V_334 = V_18 -> V_336 ;
return V_156 ;
}
static T_1
F_96 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_110 ,
F_7 ( V_18 -> V_337 ) ) ;
}
static T_1
F_97 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_194 = V_156 ;
T_4 V_320 [ V_307 ] ;
int V_205 ;
if ( ! V_18 -> V_327 )
return - V_169 ;
if ( V_9 [ V_194 - 1 ] == '\n' )
V_194 -- ;
V_205 = F_81 ( V_9 , V_194 , V_320 ) ;
if ( V_205 )
return V_205 ;
memcpy ( V_18 -> V_337 , V_320 , ( 8 * sizeof( T_4 ) ) ) ;
memcpy ( V_18 -> V_73 . V_338 , V_320 , ( 8 * sizeof( T_4 ) ) ) ;
if ( F_7 ( V_320 ) == 0 )
V_18 -> V_329 |= V_339 ;
else
V_18 -> V_329 &= ~ V_339 ;
V_18 -> V_329 &= ~ V_331 ;
if ( V_18 -> V_334 == 0 )
V_18 -> V_334 = V_18 -> V_336 ;
V_18 -> V_73 . V_332 = V_333 ;
return V_156 ;
}
static T_1
F_98 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_340 ) ;
}
static T_1
F_99 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
int V_291 = 0 ;
if ( ! V_18 -> V_327 )
return - V_169 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_158 ;
if ( sscanf ( V_9 , L_96 , & V_291 ) != 1 )
return - V_158 ;
if ( ( V_291 != 0 ) && ( V_291 != 1 ) )
return - V_158 ;
V_18 -> V_340 = V_291 ;
return strlen ( V_9 ) ;
}
static T_1
F_100 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
if ( ! ( V_18 -> V_329 & V_331 ) )
return - V_341 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_342 ) ;
}
static T_6
F_101 ( struct V_17 * V_18 , T_4 V_343 [] ,
T_4 V_344 [] , T_2 V_345 ,
T_3 V_346 , T_4 V_347 )
{
int V_205 = 0 ;
if ( ! V_18 -> V_327 )
return - V_169 ;
if ( V_346 ) {
if ( ! F_102 ( V_18 , (struct V_348 * ) V_343 ,
(struct V_348 * ) V_344 ,
V_345 , V_347 ) )
V_205 = - V_172 ;
} else {
F_103 ( V_18 , (struct V_348 * ) V_343 ,
(struct V_348 * ) V_344 , V_345 , V_347 ) ;
}
return V_205 ;
}
static T_2
F_104 ( struct V_17 * V_18 , T_4 V_343 [] ,
T_4 V_344 [] , T_3 * V_349 ,
T_3 * V_350 )
{
T_2 V_351 ;
if ( F_105 ( ! V_18 ) || ! V_343 || ! V_344 )
return V_352 ;
if ( F_106 ( V_18 , (struct V_348 * )
V_18 -> V_73 . V_338 ,
(struct V_348 * )
V_18 -> V_73 . V_328 ,
& V_18 -> V_73 . V_332 ,
(struct V_348 * ) V_343 ,
(struct V_348 * ) V_344 ,
& V_351 , V_349 , V_350 ) )
return V_351 ;
else
return V_352 ;
}
static T_1
F_107 ( struct V_17 * V_18 , T_4 V_343 [] ,
T_4 V_344 [] , T_2 V_345 ,
T_3 V_346 , T_4 V_347 )
{
int V_205 ;
V_205 = F_101 ( V_18 , V_343 , V_344 , V_345 ,
V_346 , V_347 ) ;
return V_205 ;
}
static T_1
F_108 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_2 V_353 ;
int V_34 = 0 ;
if ( ! V_18 -> V_327 )
return - V_169 ;
if ( F_7 ( V_18 -> V_337 ) == 0 )
if ( ! ( V_18 -> V_329 & V_339 ) )
return - V_341 ;
if ( F_7 ( V_18 -> V_326 ) == 0 )
if ( ! ( V_18 -> V_329 & V_330 ) )
return - V_341 ;
V_353 = F_104 ( V_18 , V_18 -> V_337 ,
V_18 -> V_326 ,
& V_18 -> V_342 ,
& V_18 -> V_334 ) ;
if ( V_353 != V_352 )
V_18 -> V_329 |= V_331 ;
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_117 , V_353 ) ;
return V_34 ;
}
static T_1
F_109 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_2 V_354 ;
T_3 V_347 ;
T_1 V_205 ;
if ( ! V_18 -> V_327 )
return - V_169 ;
if ( F_7 ( V_18 -> V_337 ) == 0 )
return - V_341 ;
if ( F_7 ( V_18 -> V_326 ) == 0 )
return - V_341 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_158 ;
if ( sscanf ( V_9 , L_117 , & V_354 ) != 1 )
return - V_158 ;
V_347 = V_18 -> V_334 ;
if ( V_347 == 0 )
V_347 = V_18 -> V_336 ;
F_38 ( V_18 , V_355 , V_196 ,
L_118
L_119 ,
F_7 ( V_18 -> V_337 ) ,
F_7 ( V_18 -> V_326 ) , V_354 ,
V_347 , V_18 -> V_340 ) ;
V_205 = F_107 ( V_18 , V_18 -> V_337 ,
V_18 -> V_326 , V_354 ,
V_18 -> V_340 , V_347 ) ;
if ( V_205 )
return V_205 ;
return V_156 ;
}
static T_1
F_110 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_51 , V_18 -> V_356 ) ;
}
static T_1
F_111 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
struct V_201 * V_202 = F_112 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_51 , V_202 -> V_357 ) ;
}
static T_1
F_113 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
struct V_201 * V_202 = F_112 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_51 , V_202 -> V_358 ) ;
}
static T_1
F_114 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_51 , V_15 -> V_359 ) ;
}
static int
F_115 ( struct V_14 * V_15 , int V_291 )
{
if ( V_15 -> V_359 != V_360 ) {
V_15 -> V_361 = V_15 -> V_359 ;
if ( V_291 != V_360 )
F_61 ( V_15 , V_186 , V_196 ,
L_120
L_121
L_122 ) ;
return 0 ;
}
if ( V_291 >= V_362 && V_291 <= V_363 ) {
V_15 -> V_361 = V_291 ;
V_15 -> V_359 = V_291 ;
return 0 ;
}
F_61 ( V_15 , V_186 , V_196 ,
L_123
L_124 ,
V_291 , V_362 , V_363 ) ;
V_15 -> V_361 = V_360 ;
return - V_158 ;
}
static void
F_116 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_25 * V_26 ;
V_13 = F_117 ( V_15 ) ;
F_9 ( V_13 -> V_77 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_118 ( V_26 ) )
continue;
if ( V_26 -> V_364 )
V_26 -> V_364 -> V_365 = V_15 -> V_359 ;
}
F_11 ( V_13 -> V_77 ) ;
}
static int
F_119 ( struct V_14 * V_15 , int V_291 )
{
if ( V_15 -> V_366 ||
( V_367 != V_360 ) ) {
F_61 ( V_15 , V_186 , V_196 ,
L_125
L_126 ) ;
return 0 ;
}
if ( V_291 >= V_362 && V_291 <= V_363 ) {
V_15 -> V_361 = V_291 ;
V_15 -> V_359 = V_291 ;
F_120 ( F_117 ( V_15 ) ) = V_291 ;
F_116 ( V_15 ) ;
return 0 ;
}
F_61 ( V_15 , V_186 , V_196 ,
L_127
L_128 ,
V_291 , V_362 , V_363 ) ;
return - V_158 ;
}
static int
F_121 ( struct V_14 * V_15 , int V_291 )
{
if ( V_291 >= V_362 && V_291 <= V_363 ) {
V_15 -> V_361 = V_291 ;
V_15 -> V_359 = V_291 ;
V_15 -> V_366 = 1 ;
F_120 ( F_117 ( V_15 ) ) = V_291 ;
F_116 ( V_15 ) ;
return 0 ;
}
F_61 ( V_15 , V_186 , V_196 ,
L_129
L_128 ,
V_291 , V_362 , V_363 ) ;
return - V_158 ;
}
static int
F_122 ( struct V_14 * V_15 , int V_291 )
{
if ( V_291 < 0 || V_291 > 1 ) {
F_61 ( V_15 , V_186 , V_196 ,
L_130
L_131 ,
V_291 ) ;
V_15 -> V_368 = 1 ;
return - V_158 ;
}
if ( V_15 -> V_285 == V_286 ) {
V_15 -> V_368 = 0 ;
return 0 ;
}
V_15 -> V_368 = V_291 ;
return 0 ;
}
static int
F_123 ( struct V_14 * V_15 , int V_291 )
{
if ( V_291 < 0 || V_291 > 1 ) {
F_61 ( V_15 , V_186 , V_196 ,
L_132
L_131 ,
V_291 ) ;
V_15 -> V_368 = 1 ;
return - V_158 ;
}
if ( V_15 -> V_285 == V_286 && V_291 != 0 ) {
F_61 ( V_15 , V_186 , V_196 ,
L_133
L_134 ) ;
V_15 -> V_368 = 0 ;
return 0 ;
}
V_15 -> V_368 = V_291 ;
return 0 ;
}
static T_1
F_124 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_291 = 0 ;
int V_369 = 0 ;
const char * V_370 = V_9 ;
int V_371 ;
T_3 V_372 ;
if ( ! strncmp ( V_9 , L_135 , strlen ( L_135 ) ) ) {
V_369 = 1 ;
V_370 = & V_9 [ strlen ( L_135 ) ] ;
}
if ( ! isdigit ( V_370 [ 0 ] ) )
return - V_158 ;
if ( sscanf ( V_370 , L_96 , & V_291 ) != 1 )
return - V_158 ;
if ( V_291 >= 0 && V_291 <= 6 ) {
V_372 = V_18 -> V_182 ;
if ( V_18 -> V_183 == V_373 &&
V_291 == 4 ) {
F_61 ( V_15 , V_186 , V_196 ,
L_136 ,
V_291 ) ;
return - V_158 ;
}
if ( V_18 -> V_230 -> V_5 == V_374 &&
V_291 == 4 ) {
F_61 ( V_15 , V_186 , V_196 ,
L_137 ) ;
return - V_158 ;
}
V_18 -> V_182 = V_291 ;
if ( V_369 )
return strlen ( V_9 ) ;
F_61 ( V_15 , V_186 , V_196 ,
L_138 ,
V_372 , V_291 ) ;
if ( V_372 != V_291 && V_18 -> V_115 == V_116 )
V_18 -> V_375 = 1 ;
V_371 = F_34 ( F_117 ( V_18 -> V_215 ) ) ;
if ( V_371 ) {
V_18 -> V_182 = V_372 ;
return - V_158 ;
} else
return strlen ( V_9 ) ;
}
F_38 ( V_18 , V_186 , V_196 ,
L_139
L_140 ,
V_18 -> V_43 , V_291 ) ;
return - V_158 ;
}
static T_1
F_125 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_376 & V_377 )
sprintf ( V_9 , L_2 ) ;
else
sprintf ( V_9 , L_3 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_126 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
#define F_127 1024
static char V_378 [ F_127 ] ;
unsigned long V_3 ;
char * V_379 , * V_380 ;
struct V_14 * * V_381 ;
struct V_12 * V_382 ;
char * V_383 , * V_384 , * V_385 ;
unsigned long V_386 , V_387 , V_388 ;
if ( ! strncmp ( V_9 , L_141 , strlen ( L_141 ) ) ) {
if ( strlen ( V_9 ) > ( F_127 - 1 ) )
return - V_158 ;
strncpy ( V_378 , V_9 , F_127 ) ;
V_379 = & V_378 [ 0 ] ;
V_380 = F_128 ( & V_379 , L_142 ) ;
if ( ! V_380 )
return - V_158 ;
V_383 = F_128 ( & V_379 , L_142 ) ;
if ( ! V_383 )
return - V_158 ;
if ( ! strncmp ( V_383 , L_143 , strlen ( L_143 ) ) )
V_388 = V_389 ;
else if ( ! strncmp ( V_383 , L_144 , strlen ( L_144 ) ) )
V_388 = V_390 ;
else
return - V_158 ;
V_384 = F_128 ( & V_379 , L_142 ) ;
if ( ! V_384 )
return - V_158 ;
V_386 = F_129 ( V_384 , NULL , 0 ) ;
V_385 = F_128 ( & V_379 , L_142 ) ;
if ( ! V_385 )
return - V_158 ;
V_387 = F_129 ( V_385 , NULL , 0 ) ;
if ( ! V_387 )
return - V_158 ;
V_381 = F_130 ( V_18 ) ;
if ( V_381 == NULL )
return - V_172 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_391 && V_381 [ V_3 ] != NULL ; V_3 ++ ) {
V_382 = F_117 ( V_381 [ V_3 ] ) ;
F_9 ( V_382 -> V_77 ) ;
V_381 [ V_3 ] -> V_392 = 1 ;
if ( V_381 [ V_3 ] -> V_393 )
F_131 ( V_381 [ V_3 ] ) ;
F_11 ( V_382 -> V_77 ) ;
}
V_18 -> V_388 = V_388 ;
V_18 -> V_394 = V_386 ;
V_18 -> V_395 = V_387 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_391 && V_381 [ V_3 ] != NULL ; V_3 ++ ) {
V_382 = F_117 ( V_381 [ V_3 ] ) ;
F_9 ( V_382 -> V_77 ) ;
V_381 [ V_3 ] -> V_392 = 0 ;
F_11 ( V_382 -> V_77 ) ;
}
F_132 ( V_18 , V_381 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_145 , strlen ( L_145 ) ) ) {
V_381 = F_130 ( V_18 ) ;
if ( V_381 == NULL )
return - V_172 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_391 && V_381 [ V_3 ] != NULL ; V_3 ++ ) {
V_382 = F_117 ( V_381 [ V_3 ] ) ;
F_9 ( V_13 -> V_77 ) ;
V_381 [ V_3 ] -> V_392 = 1 ;
F_133 ( V_15 ) ;
V_15 -> V_393 = 0 ;
V_381 [ V_3 ] -> V_392 = 0 ;
F_11 ( V_13 -> V_77 ) ;
}
F_132 ( V_18 , V_381 ) ;
V_18 -> V_388 = V_396 ;
V_18 -> V_394 = 0 ;
V_18 -> V_395 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_146 , strlen ( L_146 ) ) ) {
if ( V_18 -> V_388 == V_396 )
return - V_158 ;
F_9 ( V_13 -> V_77 ) ;
if ( V_15 -> V_393 ) {
F_11 ( V_13 -> V_77 ) ;
return strlen ( V_9 ) ;
}
F_134 ( V_15 ) ;
V_15 -> V_393 = 1 ;
F_11 ( V_13 -> V_77 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_147 , strlen ( L_147 ) ) ) {
F_9 ( V_13 -> V_77 ) ;
if ( V_15 -> V_393 == 0 ) {
F_11 ( V_13 -> V_77 ) ;
return strlen ( V_9 ) ;
}
F_133 ( V_15 ) ;
V_15 -> V_393 = 0 ;
F_11 ( V_13 -> V_77 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_148 , strlen ( L_148 ) ) ) {
if ( ( V_18 -> V_388 == V_396 )
|| ! V_15 -> V_393 )
return strlen ( V_9 ) ;
F_9 ( V_13 -> V_77 ) ;
V_15 -> V_392 = 1 ;
F_131 ( V_15 ) ;
V_15 -> V_392 = 0 ;
F_11 ( V_13 -> V_77 ) ;
return strlen ( V_9 ) ;
}
return - V_158 ;
}
static T_1
F_135 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_397 = 0 ;
int V_3 ;
char * V_388 ;
unsigned long V_398 ;
switch ( V_18 -> V_388 ) {
case V_389 :
V_388 = L_143 ;
break;
case V_390 :
V_388 = L_144 ;
break;
default:
V_388 = L_149 ;
break;
}
sprintf ( & V_9 [ V_397 ] , L_150
L_151
L_152 ,
V_15 -> V_393 , V_15 -> V_392 ,
V_388 , V_18 -> V_394 , V_18 -> V_395 ) ;
V_397 = strlen ( V_9 ) ;
if ( V_18 -> V_388 != V_396 ) {
for ( V_3 = 0 ; V_3 < V_399 ; V_3 ++ ) {
if ( V_18 -> V_388 == V_389 )
V_398 = V_18 -> V_394 +
V_18 -> V_395 * V_3 ;
else
V_398 = V_18 -> V_394 +
( 1 << V_3 ) * V_18 -> V_395 ;
if ( V_397 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_397 ] , L_153 , V_398 ) ;
V_397 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_397 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_136 ( struct V_400 * V_401 , struct V_402 * V_403 ,
struct V_404 * V_405 ,
char * V_9 , T_14 V_406 , T_6 V_156 )
{
struct V_5 * V_6 = F_137 ( V_403 , struct V_5 ,
V_403 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_397 = 0 ;
unsigned long V_407 ;
struct V_25 * V_26 = NULL ;
V_407 = ( unsigned long ) V_406 /
V_408 ;
if ( ! V_15 -> V_393 || V_15 -> V_392
|| ( V_18 -> V_388 == V_396 ) )
return 0 ;
F_9 ( V_13 -> V_77 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_118 ( V_26 ) || ! V_26 -> V_409 )
continue;
if ( V_407 > 0 ) {
V_407 -- ;
continue;
}
if ( ( V_397 + V_408 )
> V_156 )
break;
if ( ! V_26 -> V_409 )
continue;
sprintf ( & V_9 [ V_397 ] , L_154 ,
V_26 -> V_410 . V_40 . V_41 [ 0 ] ,
V_26 -> V_410 . V_40 . V_41 [ 1 ] ,
V_26 -> V_410 . V_40 . V_41 [ 2 ] ,
V_26 -> V_410 . V_40 . V_41 [ 3 ] ,
V_26 -> V_410 . V_40 . V_41 [ 4 ] ,
V_26 -> V_410 . V_40 . V_41 [ 5 ] ,
V_26 -> V_410 . V_40 . V_41 [ 6 ] ,
V_26 -> V_410 . V_40 . V_41 [ 7 ] ) ;
V_397 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_399 ; V_3 ++ ) {
sprintf ( & V_9 [ V_397 ] , L_155 ,
V_26 -> V_409 [ V_3 ] . V_411 ) ;
V_397 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_397 ] , L_1 ) ;
V_397 = strlen ( V_9 ) ;
}
F_11 ( V_13 -> V_77 ) ;
return V_397 ;
}
static T_1
F_138 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_291 = V_412 ;
int V_369 = 0 ;
const char * V_370 = V_9 ;
int V_371 ;
T_3 V_372 , V_110 ;
V_110 = F_52 ( V_236 , & V_18 -> V_73 . V_237 ) ;
if ( V_110 == V_238 &&
V_18 -> V_19 & V_413 )
return - V_169 ;
if ( ! strncmp ( V_9 , L_135 , strlen ( L_135 ) ) ) {
V_369 = 1 ;
V_370 = & V_9 [ strlen ( L_135 ) ] ;
}
if ( ! isdigit ( V_370 [ 0 ] ) )
return - V_158 ;
if ( sscanf ( V_370 , L_96 , & V_291 ) != 1 )
return - V_158 ;
F_61 ( V_15 , V_186 , V_196 ,
L_156 ,
V_18 -> V_183 , V_291 , V_369 ? L_157 : L_158 ) ;
if ( ( ( V_291 == V_414 ) && ! ( V_18 -> V_415 & V_416 ) ) ||
( ( V_291 == V_417 ) && ! ( V_18 -> V_415 & V_418 ) ) ||
( ( V_291 == V_419 ) && ! ( V_18 -> V_415 & V_420 ) ) ||
( ( V_291 == V_421 ) && ! ( V_18 -> V_415 & V_422 ) ) ||
( ( V_291 == V_423 ) && ! ( V_18 -> V_415 & V_424 ) ) ||
( ( V_291 == V_373 ) && ! ( V_18 -> V_415 & V_425 ) ) ||
( ( V_291 == V_426 ) && ! ( V_18 -> V_415 & V_427 ) ) ) {
F_38 ( V_18 , V_186 , V_196 ,
L_159
L_160 ,
V_291 ) ;
return - V_158 ;
}
if ( V_291 == V_373 &&
V_18 -> V_144 == V_145 ) {
F_38 ( V_18 , V_186 , V_196 ,
L_161
L_162 ,
V_291 ) ;
return - V_158 ;
}
if ( ( V_291 >= 0 ) && ( V_291 <= V_428 ) &&
( V_429 & ( 1 << V_291 ) ) ) {
V_372 = V_18 -> V_183 ;
V_18 -> V_183 = V_291 ;
if ( V_369 )
return strlen ( V_9 ) ;
V_371 = F_34 ( F_117 ( V_18 -> V_215 ) ) ;
if ( V_371 ) {
V_18 -> V_183 = V_372 ;
return - V_158 ;
} else
return strlen ( V_9 ) ;
}
F_38 ( V_18 , V_186 , V_196 ,
L_163
L_164 V_430 L_165 , V_291 ) ;
return - V_158 ;
}
static int
F_139 ( struct V_17 * V_18 , int V_291 )
{
if ( V_291 == V_373 && V_18 -> V_182 == 4 ) {
F_38 ( V_18 , V_186 , V_196 ,
L_166
L_167 ,
V_291 ) ;
V_18 -> V_182 = 0 ;
}
if ( ( V_291 >= 0 ) && ( V_291 <= V_428 ) &&
( V_429 & ( 1 << V_291 ) ) ) {
V_18 -> V_183 = V_291 ;
return 0 ;
}
F_38 ( V_18 , V_186 , V_196 ,
L_168
L_169
L_170 V_430 L_165 , V_291 ) ;
V_18 -> V_183 = V_412 ;
return - V_158 ;
}
static T_1
F_140 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_291 = 0 , V_205 = - V_158 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_158 ;
if ( sscanf ( V_9 , L_96 , & V_291 ) != 1 )
return - V_158 ;
switch ( V_291 ) {
case 0 :
if ( V_18 -> V_19 & V_431 ) {
V_205 = F_141 ( V_18 -> V_230 ) ;
if ( ! V_205 ) {
F_9 ( & V_18 -> V_210 ) ;
V_18 -> V_19 &= ~ V_431 ;
F_11 ( & V_18 -> V_210 ) ;
V_18 -> V_432 = 0 ;
V_205 = strlen ( V_9 ) ;
} else
V_205 = - V_169 ;
} else {
V_18 -> V_432 = 0 ;
V_205 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_431 ) ) {
V_205 = F_142 ( V_18 -> V_230 ) ;
if ( ! V_205 ) {
F_9 ( & V_18 -> V_210 ) ;
V_18 -> V_19 |= V_431 ;
F_11 ( & V_18 -> V_210 ) ;
V_18 -> V_432 = 1 ;
V_205 = strlen ( V_9 ) ;
} else
V_205 = - V_169 ;
} else {
V_18 -> V_432 = 1 ;
V_205 = strlen ( V_9 ) ;
}
break;
default:
V_205 = - V_158 ;
break;
}
return V_205 ;
}
static T_1
F_143 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_291 , V_205 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_158 ;
if ( sscanf ( V_9 , L_96 , & V_291 ) != 1 )
return - V_158 ;
if ( V_291 != 1 )
return - V_158 ;
if ( V_18 -> V_19 & V_431 )
V_205 = F_144 ( V_18 -> V_230 ) ;
if ( V_205 == 0 )
return strlen ( V_9 ) ;
else
return - V_169 ;
}
static T_1
F_145 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_228 * V_229 = V_18 -> V_230 ;
int V_291 = 0 , V_205 = - V_158 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_158 ;
if ( sscanf ( V_9 , L_96 , & V_291 ) != 1 )
return - V_158 ;
if ( V_291 < 0 )
return - V_158 ;
if ( V_291 == 0 ) {
if ( V_18 -> V_239 > 0 ) {
F_54 ( V_229 ) ;
V_18 -> V_239 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_239 > 0 ) {
F_38 ( V_18 , V_186 , V_196 ,
L_171
L_172 ,
V_18 -> V_239 ) ;
return - V_433 ;
}
if ( V_291 <= V_434 )
V_18 -> V_239 = V_291 ;
else {
F_38 ( V_18 , V_186 , V_196 ,
L_173
L_174 , V_291 ) ;
return - V_158 ;
}
V_205 = F_57 ( V_18 , V_18 -> V_239 ) ;
if ( V_205 ) {
V_18 -> V_239 = 0 ;
V_205 = - V_169 ;
} else
V_205 = strlen ( V_9 ) ;
return V_205 ;
}
static T_1
F_146 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_291 = 0 , V_205 = - V_158 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_158 ;
if ( sscanf ( V_9 , L_96 , & V_291 ) != 1 )
return - V_158 ;
if ( V_291 != 1 )
return - V_158 ;
V_205 = F_147 ( V_18 , V_435 ) ;
if ( V_205 )
V_205 = - V_169 ;
else
V_205 = strlen ( V_9 ) ;
return V_205 ;
}
static int
F_148 ( struct V_17 * V_18 , int V_291 )
{
if ( V_291 >= 0 && V_291 <= 1 ) {
V_18 -> V_436 = V_291 ;
return 0 ;
}
return - V_158 ;
}
static T_1
F_149 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_291 = 0 , V_3 ;
if ( V_18 -> V_115 != V_116 )
return - V_158 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_158 ;
if ( sscanf ( V_9 , L_96 , & V_291 ) != 1 )
return - V_158 ;
if ( V_291 && ( V_291 < V_437 || V_291 > V_438 ) )
return - V_158 ;
V_18 -> V_439 = ( T_3 ) V_291 ;
V_18 -> V_440 = V_18 -> V_439 ;
for ( V_3 = 0 ; V_3 < V_18 -> V_441 ; V_3 += V_442 )
F_150 ( V_18 , V_3 , V_442 ,
V_291 ) ;
return strlen ( V_9 ) ;
}
static int
F_151 ( struct V_17 * V_18 , int V_291 )
{
if ( V_18 -> V_115 != V_116 ) {
V_18 -> V_439 = 0 ;
return 0 ;
}
if ( ( V_291 >= V_437 && V_291 <= V_438 ) ||
( V_291 == 0 ) ) {
V_18 -> V_439 = V_291 ;
return 0 ;
}
F_38 ( V_18 , V_186 , V_196 ,
L_175 ,
V_291 ) ;
V_18 -> V_439 = V_443 ;
return 0 ;
}
static T_1
F_152 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_444 * V_445 ;
int V_34 = 0 ;
if ( ( V_18 -> V_115 != V_116 ) ||
( V_18 -> V_446 != V_447 ) )
return V_34 ;
switch ( V_18 -> V_448 ) {
case 0 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_176 ,
V_18 -> V_448 ) ;
return V_34 ;
case 1 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_177
L_178 ,
V_18 -> V_448 ,
V_18 -> V_73 . V_449 ) ;
break;
case 2 :
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_179
L_178 ,
V_18 -> V_448 ,
V_18 -> V_73 . V_449 ) ;
break;
}
while ( V_18 -> V_73 . V_450 < V_18 -> V_73 . V_451 ) {
V_445 = & V_18 -> V_73 . V_452 [ V_18 -> V_73 . V_450 ] ;
if ( V_445 -> V_453 == V_454 )
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_180
L_181 ,
V_18 -> V_73 . V_450 ,
V_445 -> V_455 , V_445 -> V_456 ,
V_445 -> V_457 ) ;
else
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 ,
L_180
L_182 ,
V_18 -> V_73 . V_450 ,
V_445 -> V_455 , V_445 -> V_456 ,
V_445 -> V_457 , V_445 -> V_453 ) ;
V_18 -> V_73 . V_450 ++ ;
if ( V_18 -> V_73 . V_450 <
V_18 -> V_73 . V_451 &&
( V_34 >= ( V_10 - 64 ) ) ) {
V_34 += snprintf ( V_9 + V_34 , V_10 - V_34 , L_183 ) ;
break;
}
}
if ( V_18 -> V_73 . V_450 == V_18 -> V_73 . V_451 )
V_18 -> V_73 . V_450 = 0 ;
return V_34 ;
}
static T_1
F_153 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_6 V_156 )
{
int V_157 = - V_158 ;
return V_157 ;
}
static int
F_154 ( struct V_17 * V_18 , int V_291 )
{
if ( V_18 -> V_115 != V_116 ) {
V_18 -> V_448 = 0 ;
return 0 ;
}
if ( V_291 >= V_458 && V_291 <= V_459 ) {
V_18 -> V_448 = V_291 ;
return 0 ;
}
F_38 ( V_18 , V_186 , V_196 ,
L_184
L_185 , V_291 ) ;
V_18 -> V_448 = V_460 ;
return 0 ;
}
static int
F_155 ( struct V_14 * V_15 , int V_291 )
{
struct V_12 * V_13 = F_117 ( V_15 ) ;
struct V_25 * V_26 , * V_461 ;
if ( V_291 == V_15 -> V_462 )
return 0 ;
if ( ( V_291 < 0 ) || ( V_291 > 60000 ) )
return - V_158 ;
V_15 -> V_462 = V_291 ;
F_9 ( V_13 -> V_77 ) ;
F_156 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_118 ( V_26 ) )
continue;
if ( V_26 -> V_463 == V_464 )
continue;
V_26 -> V_465 = V_15 -> V_466 ;
}
F_11 ( V_13 -> V_77 ) ;
return 0 ;
}
static T_1
F_157 ( struct V_400 * V_401 , struct V_402 * V_403 ,
struct V_404 * V_405 ,
char * V_9 , T_14 V_406 , T_6 V_156 )
{
T_6 V_467 ;
struct V_5 * V_6 = F_137 ( V_403 , struct V_5 , V_403 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_115 >= V_116 )
return - V_169 ;
if ( ( V_406 + V_156 ) > V_468 )
return - V_469 ;
if ( V_156 <= V_470 )
return 0 ;
if ( V_406 % 4 || V_156 % 4 || ( unsigned long ) V_9 % 4 )
return - V_158 ;
if ( memcmp ( V_9 , V_471 , V_470 ) )
return - V_158 ;
if ( ! ( V_15 -> V_146 & V_167 ) )
return - V_169 ;
F_9 ( & V_18 -> V_210 ) ;
for ( V_467 = 0 ; V_467 < V_156 - V_470 ;
V_467 += sizeof( T_3 ) )
F_56 ( * ( ( T_3 * ) ( V_9 + V_467 + V_470 ) ) ,
V_18 -> V_472 + V_406 + V_467 ) ;
F_11 ( & V_18 -> V_210 ) ;
return V_156 ;
}
static T_1
F_158 ( struct V_400 * V_401 , struct V_402 * V_403 ,
struct V_404 * V_405 ,
char * V_9 , T_14 V_406 , T_6 V_156 )
{
T_6 V_467 ;
T_3 * V_473 ;
struct V_5 * V_6 = F_137 ( V_403 , struct V_5 , V_403 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_115 >= V_116 )
return - V_169 ;
if ( V_406 > V_468 )
return - V_469 ;
if ( ( V_406 + V_156 ) > V_468 )
V_156 = V_468 - V_406 ;
if ( V_156 == 0 ) return 0 ;
if ( V_406 % 4 || V_156 % 4 || ( unsigned long ) V_9 % 4 )
return - V_158 ;
F_9 ( & V_18 -> V_210 ) ;
for ( V_467 = 0 ; V_467 < V_156 ; V_467 += sizeof( T_3 ) ) {
V_473 = ( T_3 * ) ( V_9 + V_467 ) ;
* V_473 = F_55 ( V_18 -> V_472 + V_406 + V_467 ) ;
}
F_11 ( & V_18 -> V_210 ) ;
return V_156 ;
}
static T_1
F_159 ( struct V_400 * V_401 , struct V_402 * V_403 ,
struct V_404 * V_405 ,
char * V_9 , T_14 V_406 , T_6 V_156 )
{
return - V_169 ;
}
static T_1
F_160 ( struct V_400 * V_401 , struct V_402 * V_403 ,
struct V_404 * V_405 ,
char * V_9 , T_14 V_406 , T_6 V_156 )
{
return - V_169 ;
}
int
F_161 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_117 ( V_15 ) ;
int error ;
error = F_162 ( & V_13 -> V_474 . V_403 ,
& V_475 ) ;
if ( error || V_15 -> V_285 == V_476 )
goto V_211;
error = F_162 ( & V_13 -> V_474 . V_403 ,
& V_477 ) ;
if ( error )
goto V_478;
error = F_162 ( & V_13 -> V_474 . V_403 ,
& V_479 ) ;
if ( error )
goto V_480;
return 0 ;
V_480:
F_163 ( & V_13 -> V_474 . V_403 , & V_477 ) ;
V_478:
F_163 ( & V_13 -> V_474 . V_403 ,
& V_475 ) ;
V_211:
return error ;
}
void
F_164 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_117 ( V_15 ) ;
F_163 ( & V_13 -> V_474 . V_403 ,
& V_475 ) ;
if ( V_15 -> V_285 == V_476 )
return;
F_163 ( & V_13 -> V_474 . V_403 , & V_479 ) ;
F_163 ( & V_13 -> V_474 . V_403 , & V_477 ) ;
}
static void
F_165 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_166 ( V_15 , F_167 ( V_13 ) ,
sizeof F_167 ( V_13 ) ) ;
}
static void
F_168 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_169 ( V_13 ) = V_15 -> V_481 ;
}
static void
F_170 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_9 ( V_13 -> V_77 ) ;
if ( V_15 -> V_285 == V_476 ) {
F_171 ( V_13 ) = V_482 ;
} else if ( F_172 ( V_18 ) ) {
if ( V_18 -> V_144 == V_145 ) {
if ( V_15 -> V_146 & V_147 )
F_171 ( V_13 ) = V_483 ;
else
F_171 ( V_13 ) = V_484 ;
} else {
if ( V_15 -> V_146 & V_148 )
F_171 ( V_13 ) = V_485 ;
else
F_171 ( V_13 ) = V_486 ;
}
} else
F_171 ( V_13 ) = V_487 ;
F_11 ( V_13 -> V_77 ) ;
}
static void
F_173 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_9 ( V_13 -> V_77 ) ;
if ( V_15 -> V_146 & V_167 )
F_174 ( V_13 ) = V_488 ;
else {
switch ( V_18 -> V_122 ) {
case V_123 :
case V_127 :
F_174 ( V_13 ) = V_489 ;
break;
case V_130 :
case V_131 :
case V_132 :
if ( V_15 -> V_79 < V_141 )
F_174 ( V_13 ) =
V_490 ;
else
F_174 ( V_13 ) =
V_491 ;
break;
case V_128 :
F_174 ( V_13 ) = V_492 ;
break;
default:
F_174 ( V_13 ) = V_493 ;
break;
}
}
F_11 ( V_13 -> V_77 ) ;
}
static void
F_175 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_9 ( V_13 -> V_77 ) ;
if ( ( F_172 ( V_18 ) ) && ( ! ( V_18 -> V_19 & V_494 ) ) ) {
switch( V_18 -> V_495 ) {
case V_496 :
F_176 ( V_13 ) = V_497 ;
break;
case V_498 :
F_176 ( V_13 ) = V_499 ;
break;
case V_500 :
F_176 ( V_13 ) = V_501 ;
break;
case V_502 :
F_176 ( V_13 ) = V_503 ;
break;
case V_504 :
F_176 ( V_13 ) = V_505 ;
break;
case V_506 :
F_176 ( V_13 ) = V_507 ;
break;
case V_508 :
F_176 ( V_13 ) = V_509 ;
break;
default:
F_176 ( V_13 ) = V_510 ;
break;
}
} else
F_176 ( V_13 ) = V_510 ;
F_11 ( V_13 -> V_77 ) ;
}
static void
F_177 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_15 V_83 ;
F_9 ( V_13 -> V_77 ) ;
if ( ( V_15 -> V_79 > V_135 ) &&
( ( V_15 -> V_146 & V_148 ) ||
( ( V_18 -> V_144 == V_145 ) &&
( V_15 -> V_146 & V_147 ) ) ) )
V_83 = F_7 ( V_18 -> V_511 . V_512 . V_40 . V_41 ) ;
else
V_83 = 0 ;
F_11 ( V_13 -> V_77 ) ;
F_178 ( V_13 ) = V_83 ;
}
static struct V_513 *
F_179 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_203 * V_204 = & V_18 -> V_106 ;
struct V_513 * V_514 = & V_18 -> V_515 ;
struct V_516 * V_517 = & V_204 -> V_518 ;
T_7 * V_164 ;
T_9 * V_263 ;
unsigned long V_519 ;
int V_205 = 0 ;
if ( V_18 -> V_122 < V_127 ||
! V_18 -> V_170 ||
( V_18 -> V_106 . V_107 & V_265 ) == 0 )
return NULL ;
if ( V_18 -> V_106 . V_107 & V_168 )
return NULL ;
V_164 = F_35 ( V_18 -> V_170 , V_171 ) ;
if ( ! V_164 )
return NULL ;
memset ( V_164 , 0 , sizeof ( T_7 ) ) ;
V_263 = & V_164 -> V_40 . V_173 ;
V_263 -> V_174 = V_520 ;
V_263 -> V_176 = V_177 ;
V_164 -> V_267 = NULL ;
V_164 -> V_15 = V_15 ;
if ( V_15 -> V_146 & V_167 )
V_205 = F_180 ( V_18 , V_164 , V_521 ) ;
else
V_205 = F_36 ( V_18 , V_164 , V_18 -> V_184 * 2 ) ;
if ( V_205 != V_179 ) {
if ( V_205 != V_189 )
F_40 ( V_164 , V_18 -> V_170 ) ;
return NULL ;
}
memset ( V_514 , 0 , sizeof ( struct V_513 ) ) ;
V_514 -> V_522 = V_263 -> V_270 . V_523 . V_524 ;
V_514 -> V_525 = ( T_2 )
( ( T_2 ) V_263 -> V_270 . V_523 . V_526
* ( T_2 ) 256 ) ;
V_514 -> V_527 = V_263 -> V_270 . V_523 . V_528 ;
V_514 -> V_529 = ( T_2 )
( ( T_2 ) V_263 -> V_270 . V_523 . V_530
* ( T_2 ) 256 ) ;
memset ( V_164 , 0 , sizeof ( T_7 ) ) ;
V_263 -> V_174 = V_531 ;
V_263 -> V_176 = V_177 ;
V_164 -> V_267 = NULL ;
V_164 -> V_15 = V_15 ;
if ( V_15 -> V_146 & V_167 )
V_205 = F_180 ( V_18 , V_164 , V_521 ) ;
else
V_205 = F_36 ( V_18 , V_164 , V_18 -> V_184 * 2 ) ;
if ( V_205 != V_179 ) {
if ( V_205 != V_189 )
F_40 ( V_164 , V_18 -> V_170 ) ;
return NULL ;
}
V_514 -> V_532 = V_263 -> V_270 . V_533 . V_534 ;
V_514 -> V_535 = V_263 -> V_270 . V_533 . V_536 ;
V_514 -> V_537 = V_263 -> V_270 . V_533 . V_538 ;
V_514 -> V_539 = V_263 -> V_270 . V_533 . V_540 ;
V_514 -> V_541 = V_263 -> V_270 . V_533 . V_542 ;
V_514 -> V_543 = V_263 -> V_270 . V_533 . V_544 ;
V_514 -> V_545 = V_263 -> V_270 . V_533 . V_544 ;
V_514 -> V_532 -= V_517 -> V_532 ;
V_514 -> V_535 -= V_517 -> V_535 ;
V_514 -> V_537 -= V_517 -> V_537 ;
V_514 -> V_539 -= V_517 -> V_539 ;
V_514 -> V_541 -= V_517 -> V_541 ;
V_514 -> V_543 -= V_517 -> V_543 ;
V_514 -> V_545 -= V_517 -> V_545 ;
if ( V_18 -> V_19 & V_494 ) {
V_514 -> V_546 = - 1 ;
V_514 -> V_547 = ( V_18 -> V_548 >> 1 ) ;
V_514 -> V_547 -= V_517 -> V_548 ;
} else if ( V_18 -> V_144 == V_145 ) {
V_514 -> V_546 = ( V_18 -> V_549 >> 1 ) ;
V_514 -> V_546 -= V_517 -> V_548 ;
V_514 -> V_547 = - 1 ;
} else {
V_514 -> V_546 = - 1 ;
V_514 -> V_547 = ( V_18 -> V_549 >> 1 ) ;
V_514 -> V_547 -= V_517 -> V_548 ;
}
V_514 -> V_550 = - 1 ;
V_519 = F_181 () ;
if ( V_519 < V_204 -> V_551 )
V_514 -> V_552 = V_519 +
( ( unsigned long ) - 1 - V_204 -> V_551 ) ;
else
V_514 -> V_552 = V_519 - V_204 -> V_551 ;
F_40 ( V_164 , V_18 -> V_170 ) ;
return V_514 ;
}
static void
F_182 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_203 * V_204 = & V_18 -> V_106 ;
struct V_516 * V_517 = & V_204 -> V_518 ;
T_7 * V_164 ;
T_9 * V_263 ;
int V_205 = 0 ;
if ( V_18 -> V_106 . V_107 & V_168 )
return;
V_164 = F_35 ( V_18 -> V_170 , V_171 ) ;
if ( ! V_164 )
return;
memset ( V_164 , 0 , sizeof( T_7 ) ) ;
V_263 = & V_164 -> V_40 . V_173 ;
V_263 -> V_174 = V_520 ;
V_263 -> V_176 = V_177 ;
V_263 -> V_270 . V_553 [ 0 ] = 0x1 ;
V_164 -> V_267 = NULL ;
V_164 -> V_15 = V_15 ;
if ( ( V_15 -> V_146 & V_167 ) ||
( ! ( V_204 -> V_107 & V_265 ) ) )
V_205 = F_180 ( V_18 , V_164 , V_521 ) ;
else
V_205 = F_36 ( V_18 , V_164 , V_18 -> V_184 * 2 ) ;
if ( V_205 != V_179 ) {
if ( V_205 != V_189 )
F_40 ( V_164 , V_18 -> V_170 ) ;
return;
}
memset ( V_164 , 0 , sizeof( T_7 ) ) ;
V_263 -> V_174 = V_531 ;
V_263 -> V_176 = V_177 ;
V_164 -> V_267 = NULL ;
V_164 -> V_15 = V_15 ;
if ( ( V_15 -> V_146 & V_167 ) ||
( ! ( V_204 -> V_107 & V_265 ) ) )
V_205 = F_180 ( V_18 , V_164 , V_521 ) ;
else
V_205 = F_36 ( V_18 , V_164 , V_18 -> V_184 * 2 ) ;
if ( V_205 != V_179 ) {
if ( V_205 != V_189 )
F_40 ( V_164 , V_18 -> V_170 ) ;
return;
}
V_517 -> V_532 = V_263 -> V_270 . V_533 . V_534 ;
V_517 -> V_535 = V_263 -> V_270 . V_533 . V_536 ;
V_517 -> V_537 = V_263 -> V_270 . V_533 . V_538 ;
V_517 -> V_539 = V_263 -> V_270 . V_533 . V_540 ;
V_517 -> V_541 = V_263 -> V_270 . V_533 . V_542 ;
V_517 -> V_543 = V_263 -> V_270 . V_533 . V_544 ;
V_517 -> V_545 = V_263 -> V_270 . V_533 . V_544 ;
if ( V_18 -> V_19 & V_494 )
V_517 -> V_548 = ( V_18 -> V_548 >> 1 ) ;
else
V_517 -> V_548 = ( V_18 -> V_549 >> 1 ) ;
V_204 -> V_551 = F_181 () ;
F_40 ( V_164 , V_18 -> V_170 ) ;
return;
}
static struct V_25 *
F_183 ( struct V_554 * V_555 )
{
struct V_12 * V_13 = F_184 ( V_555 -> V_6 . V_556 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_25 * V_26 ;
F_9 ( V_13 -> V_77 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_118 ( V_26 ) &&
V_26 -> V_463 == V_557 &&
V_555 -> V_558 == V_26 -> V_559 ) {
F_11 ( V_13 -> V_77 ) ;
return V_26 ;
}
}
F_11 ( V_13 -> V_77 ) ;
return NULL ;
}
static void
F_185 ( struct V_554 * V_555 )
{
struct V_25 * V_26 = F_183 ( V_555 ) ;
F_186 ( V_555 ) = V_26 ? V_26 -> V_560 : - 1 ;
}
static void
F_187 ( struct V_554 * V_555 )
{
struct V_25 * V_26 = F_183 ( V_555 ) ;
F_188 ( V_555 ) =
V_26 ? F_7 ( V_26 -> V_561 . V_40 . V_41 ) : 0 ;
}
static void
F_189 ( struct V_554 * V_555 )
{
struct V_25 * V_26 = F_183 ( V_555 ) ;
F_190 ( V_555 ) =
V_26 ? F_7 ( V_26 -> V_410 . V_40 . V_41 ) : 0 ;
}
static void
F_191 ( struct V_562 * V_364 , T_3 V_563 )
{
if ( V_563 )
V_364 -> V_365 = V_563 ;
else
V_364 -> V_365 = 1 ;
}
static void
F_192 ( struct V_564 * V_564 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_564 -> V_565 ;
if ( V_15 -> V_79 == V_141 )
F_193 ( V_15 , V_566 , 0 , 0 ) ;
}
static void
F_194 ( struct V_17 * V_18 , T_3 V_567 )
{
V_18 -> V_568 = V_567 ;
}
void
F_195 ( struct V_17 * V_18 )
{
F_196 ( V_18 , V_569 ) ;
F_197 ( V_18 , V_570 ) ;
F_198 ( V_18 , V_571 ) ;
F_199 ( V_18 , V_572 ) ;
F_200 ( V_18 , V_573 ) ;
F_201 ( V_18 , V_574 ) ;
F_202 ( V_18 , V_575 ) ;
F_203 ( V_18 , V_576 ) ;
F_204 ( V_18 , V_577 ) ;
F_139 ( V_18 , V_578 ) ;
F_205 ( V_18 , V_579 ) ;
F_206 ( V_18 , V_580 ) ;
F_207 ( V_18 , V_581 ) ;
F_208 ( V_18 , V_582 ) ;
F_209 ( V_18 , V_583 ) ;
F_210 ( V_18 , V_584 ) ;
F_211 ( V_18 , V_585 ) ;
F_212 ( V_18 , V_586 ) ;
F_213 ( V_18 , V_587 ) ;
F_214 ( V_18 , V_588 ) ;
F_151 ( V_18 , V_589 ) ;
F_154 ( V_18 , V_590 ) ;
F_215 ( V_18 , V_591 ) ;
F_216 ( V_18 , V_592 ) ;
F_217 ( V_18 , V_593 ) ;
if ( V_18 -> V_115 != V_116 )
V_18 -> V_594 = 0 ;
F_218 ( V_18 , V_595 ) ;
memset ( V_18 -> V_326 , 0 , ( 8 * sizeof( T_4 ) ) ) ;
memset ( V_18 -> V_337 , 0 , ( 8 * sizeof( T_4 ) ) ) ;
V_18 -> V_340 = 0 ;
V_18 -> V_342 = 0 ;
V_18 -> V_329 = 0 ;
V_18 -> V_334 = 0 ;
F_219 ( V_18 , V_596 ) ;
F_220 ( V_18 , V_597 ) ;
F_221 ( V_18 , V_598 ) ;
if ( V_18 -> V_115 == V_116 )
V_18 -> V_288 = 0 ;
else
V_18 -> V_288 = V_599 ;
F_222 ( V_18 , V_600 ) ;
F_223 ( V_18 , V_601 ) ;
F_224 ( V_18 , V_602 ) ;
F_225 ( V_18 , V_603 ) ;
F_226 ( V_18 , V_604 ) ;
F_227 ( V_18 , V_605 ) ;
F_228 ( V_18 , V_606 ) ;
F_229 ( V_18 , V_607 ) ;
if ( V_18 -> V_115 != V_116 ) {
V_18 -> V_37 = 0 ;
V_18 -> V_35 = V_608 ;
V_18 -> V_306 = 0 ;
} else {
if ( ! ( V_18 -> V_35 & V_608 ) )
V_18 -> V_35 |= V_608 ;
}
if ( V_18 -> V_609 && ! V_18 -> V_439 )
V_18 -> V_609 = 0 ;
V_18 -> V_440 = V_18 -> V_439 ;
if ( V_18 -> V_610 == 0 )
V_18 -> V_610 = V_18 -> V_73 . V_451 ;
if ( V_18 -> V_611 == 0 )
V_18 -> V_611 = V_18 -> V_73 . V_451 ;
if ( V_18 -> V_35 == V_36 )
V_18 -> V_610 = 0 ;
if ( V_18 -> V_35 == V_608 )
V_18 -> V_611 = 0 ;
if ( V_18 -> V_610 > V_18 -> V_611 )
V_18 -> V_441 = V_18 -> V_610 ;
else
V_18 -> V_441 = V_18 -> V_611 ;
V_18 -> V_323 = 0L ;
V_18 -> V_317 = 0L ;
F_230 ( V_18 , V_612 ) ;
F_231 ( V_18 , V_613 ) ;
F_232 ( V_18 , V_614 ) ;
F_194 ( V_18 , V_615 ) ;
F_233 ( V_18 , V_616 ) ;
F_234 ( V_18 , V_617 ) ;
F_148 ( V_18 , V_618 ) ;
F_235 ( V_18 , V_619 ) ;
F_236 ( V_18 , V_620 ) ;
F_237 ( V_18 , V_621 ) ;
F_238 ( V_18 , V_622 ) ;
V_18 -> V_300 = 1 ;
F_239 ( V_18 , V_623 ) ;
return;
}
void
F_240 ( struct V_17 * V_18 )
{
if ( V_18 -> V_611 > V_18 -> V_73 . V_451 )
V_18 -> V_611 = V_18 -> V_73 . V_451 ;
if ( V_18 -> V_610 > V_18 -> V_73 . V_451 )
V_18 -> V_610 = V_18 -> V_73 . V_451 ;
if ( V_18 -> V_35 & V_36 &&
V_18 -> V_37 ) {
V_18 -> V_35 &= ~ V_608 ;
V_18 -> V_610 = 0 ;
F_38 ( V_18 , V_355 , V_624 ,
L_186 ,
L_187 ,
V_18 -> V_625 ,
V_18 -> V_626 ,
V_627 ) ;
if ( V_18 -> V_625 == 0 )
V_18 -> V_626 = 0 ;
else {
if ( V_18 -> V_626 > V_627 )
V_18 -> V_626 = V_627 ;
}
if ( V_18 -> V_628 > V_18 -> V_611 ) {
V_18 -> V_628 = V_18 -> V_611 ;
F_38 ( V_18 , V_186 , V_624 ,
L_188 ,
V_18 -> V_628 ) ;
}
} else {
V_18 -> V_37 = 0 ;
V_18 -> V_628 = 0 ;
V_18 -> V_626 = 0 ;
}
if ( V_18 -> V_610 > V_18 -> V_611 )
V_18 -> V_441 = V_18 -> V_610 ;
else
V_18 -> V_441 = V_18 -> V_611 ;
}
void
F_241 ( struct V_14 * V_15 )
{
F_242 ( V_15 , V_615 ) ;
F_243 ( V_15 , V_629 ) ;
F_244 ( V_15 , V_630 ) ;
F_245 ( V_15 , V_367 ) ;
F_115 ( V_15 , V_631 ) ;
F_246 ( V_15 , V_632 ) ;
F_122 ( V_15 , V_633 ) ;
F_247 ( V_15 , V_634 ) ;
F_248 ( V_15 , V_635 ) ;
F_249 ( V_15 , V_636 ) ;
F_250 ( V_15 , V_637 ) ;
F_251 ( V_15 , V_638 ) ;
F_252 ( V_15 , V_639 ) ;
F_253 ( V_15 , V_640 ) ;
F_254 ( V_15 , V_641 ) ;
return;
}
