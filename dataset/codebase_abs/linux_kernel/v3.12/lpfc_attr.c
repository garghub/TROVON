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
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_21 )
if ( V_18 -> V_22 & V_23 )
return snprintf ( V_9 , V_10 , L_4 ) ;
else
return snprintf ( V_9 , V_10 ,
L_5 ) ;
else
return snprintf ( V_9 , V_10 ,
L_6 ) ;
}
static T_1
F_6 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_7 ,
( unsigned long long ) V_18 -> V_24 ) ;
}
static T_1
F_7 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_7 ,
( unsigned long long ) V_18 -> V_25 ) ;
}
static T_1
F_8 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_7 ,
( unsigned long long ) V_18 -> V_26 ) ;
}
static T_1
F_9 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_27 = F_4 ( V_6 ) ;
return snprintf ( V_9 , V_10 , L_8 , F_10 ( V_27 ) ) ;
}
static T_1
F_11 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_28 ) ;
}
static T_1
F_12 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_29 ) ;
}
static T_1
F_13 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_30 ) ;
}
static T_1
F_14 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_31 ) ;
}
static T_1
F_15 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_32 ) ;
}
static T_1
F_16 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
( V_18 -> V_33 . V_34 & V_35 ) ) ;
}
static T_1
F_17 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_36 ) ;
}
static T_1
F_18 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_37 ;
T_3 V_38 ;
char V_39 [ V_40 ] ;
int V_41 ;
F_19 ( V_18 , V_39 , 1 ) ;
V_37 = V_18 -> V_42 . V_43 . V_37 ;
V_38 = V_18 -> V_42 . V_43 . V_38 ;
if ( V_18 -> V_44 < V_45 )
V_41 = snprintf ( V_9 , V_10 , L_10 ,
V_39 , V_18 -> V_44 ) ;
else
V_41 = snprintf ( V_9 , V_10 , L_11 ,
V_39 , V_18 -> V_44 , V_37 , V_38 ) ;
return V_41 ;
}
static T_1
F_20 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
char V_2 [ 9 ] ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_4 * V_46 = & V_18 -> V_47 ;
F_1 ( V_46 -> V_48 . V_49 , V_2 ) ;
return snprintf ( V_9 , V_10 , L_8 , V_2 ) ;
}
static T_1
F_21 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_50 ) ;
}
static T_1
F_22 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_41 = 0 ;
switch ( V_18 -> V_51 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
if ( V_18 -> V_19 & V_58 )
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_12 ) ;
else
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_13 ) ;
break;
case V_59 :
case V_60 :
case V_61 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 , L_14 ) ;
switch ( V_15 -> V_62 ) {
case V_63 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_15 ) ;
break;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_16 ) ;
break;
case V_71 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 , L_17 ) ;
break;
case V_72 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 , L_18 ) ;
break;
case V_73 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_19 ) ;
break;
}
if ( V_18 -> V_33 . V_34 & V_35 )
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_20 ) ;
else if ( V_18 -> V_74 == V_75 ) {
if ( V_15 -> V_76 & V_77 )
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_21 ) ;
else
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_22 ) ;
} else {
if ( V_15 -> V_76 & V_78 )
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_23 ) ;
else
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_24 ) ;
}
}
return V_41 ;
}
static T_1
F_23 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_44 < V_45 )
return snprintf ( V_9 , V_10 , L_25 ) ;
if ( V_18 -> V_42 . V_79 . V_80 == V_81 ) {
if ( V_18 -> V_42 . V_79 . V_82 == V_83 )
return snprintf ( V_9 , V_10 , L_26 ) ;
if ( V_18 -> V_42 . V_79 . V_82 == V_84 )
return snprintf ( V_9 , V_10 , L_25 ) ;
}
return snprintf ( V_9 , V_10 , L_27 ) ;
}
static T_1
F_24 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_86 = - V_87 ;
if ( ( strncmp ( V_9 , L_28 , sizeof( L_28 ) - 1 ) == 0 ) &&
( V_18 -> V_51 == V_56 ) )
V_86 = V_18 -> V_88 ( V_18 , V_89 ) ;
else if ( ( strncmp ( V_9 , L_29 , sizeof( L_29 ) - 1 ) == 0 ) &&
( V_18 -> V_51 >= V_59 ) )
V_86 = V_18 -> V_90 ( V_18 , V_89 ) ;
if ( V_86 == 0 )
return strlen ( V_9 ) ;
else
return V_86 ;
}
static T_1
F_25 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_15 -> V_91 + V_15 -> V_92 ) ;
}
static int
F_26 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_6 * V_93 ;
int V_94 = V_95 ;
if ( ( V_15 -> V_76 & V_96 ) ||
( V_18 -> V_33 . V_34 & V_97 ) )
return - V_98 ;
V_93 = F_27 ( V_18 -> V_99 , V_100 ) ;
if ( ! V_93 )
return - V_101 ;
memset ( ( void * ) V_93 , 0 , sizeof ( T_6 ) ) ;
V_93 -> V_102 . V_103 . V_104 = V_105 ;
V_93 -> V_102 . V_103 . V_106 = V_107 ;
V_94 = F_28 ( V_18 , V_93 , V_108 * 2 ) ;
if ( ( V_94 == V_109 ) &&
( V_93 -> V_102 . V_103 . V_110 == 0 ||
V_93 -> V_102 . V_103 . V_110 == V_111 ) ) {
memset ( ( void * ) V_93 , 0 , sizeof ( T_6 ) ) ;
F_29 ( V_18 , V_93 , V_18 -> V_112 ,
V_18 -> V_113 ) ;
V_94 = F_28 ( V_18 , V_93 ,
V_18 -> V_114 * 2 ) ;
if ( ( V_94 == V_109 ) &&
( V_93 -> V_102 . V_103 . V_110 == V_115 ) )
F_30 ( V_18 , V_116 , V_117 | V_118 ,
L_30
L_31 ) ;
}
F_31 ( V_18 ) ;
if ( V_94 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
if ( V_94 == V_95 )
return - V_120 ;
return 0 ;
}
static int
F_33 ( struct V_17 * V_18 , T_2 type )
{
struct V_121 V_122 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
int V_86 = 0 ;
int V_127 = 0 ;
int V_3 ;
int V_128 ;
F_34 ( & V_122 ) ;
V_128 = F_35 ( V_18 , & V_86 , & V_122 ,
V_129 ) ;
if ( V_128 == 0 )
return - V_101 ;
F_36 ( & V_122 ) ;
if ( V_86 != 0 )
return - V_120 ;
V_126 = & V_18 -> V_33 ;
for ( V_3 = 0 ; V_3 < V_126 -> V_130 ; V_3 ++ ) {
V_124 = & V_126 -> V_131 [ V_3 ] ;
while ( ! F_37 ( & V_124 -> V_132 ) ) {
F_38 ( 10 ) ;
if ( V_127 ++ > 500 ) {
F_30 ( V_18 ,
V_133 , V_134 ,
L_32
L_33 ) ;
break;
}
}
}
F_34 ( & V_122 ) ;
V_128 = F_35 ( V_18 , & V_86 , & V_122 , type ) ;
if ( V_128 == 0 )
return - V_101 ;
F_36 ( & V_122 ) ;
if ( V_86 != 0 )
return - V_120 ;
return 0 ;
}
int
F_39 ( struct V_17 * V_18 )
{
struct V_121 V_122 ;
int V_86 = 0 ;
int V_128 ;
if ( ! V_18 -> V_135 )
return - V_136 ;
if ( ! ( V_18 -> V_137 -> V_76 & V_96 ) ) {
V_86 = F_33 ( V_18 , V_138 ) ;
if ( V_86 != 0 )
return V_86 ;
}
F_34 ( & V_122 ) ;
V_128 = F_35 ( V_18 , & V_86 , & V_122 ,
V_139 ) ;
if ( V_128 == 0 )
return - V_101 ;
F_36 ( & V_122 ) ;
if ( V_86 != 0 )
return - V_120 ;
return 0 ;
}
static T_1
F_40 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_86 = - V_87 ;
if ( ! V_18 -> V_135 )
return - V_136 ;
if ( strncmp ( V_9 , L_34 , sizeof( L_34 ) - 1 ) == 0 )
V_86 = V_18 -> F_39 ( V_18 ) ;
if ( V_86 == 0 )
return strlen ( V_9 ) ;
else
return V_86 ;
}
int
F_41 ( struct V_17 * V_18 )
{
struct V_140 V_141 = { 0 } ;
int V_3 ;
F_38 ( 100 ) ;
F_42 ( V_18 -> V_42 . V_102 . V_142 . V_143 ,
& V_141 . V_144 ) ;
if ( ! F_43 ( V_145 , & V_141 ) &&
! F_43 ( V_146 , & V_141 ) )
return - V_98 ;
for ( V_3 = 0 ; V_3 < V_147 ; V_3 ++ ) {
F_38 ( 10 ) ;
F_42 ( V_18 -> V_42 . V_102 . V_142 . V_143 ,
& V_141 . V_144 ) ;
if ( ! F_43 ( V_146 , & V_141 ) )
continue;
if ( ! F_43 ( V_145 , & V_141 ) )
continue;
if ( ! F_43 ( V_148 , & V_141 ) )
continue;
break;
}
if ( V_3 < V_147 )
return 0 ;
else
return - V_120 ;
}
static T_1
F_44 ( struct V_17 * V_18 , T_2 V_149 )
{
struct V_121 V_122 ;
struct V_150 * V_151 = V_18 -> V_152 ;
T_2 V_153 ;
T_2 V_154 ;
T_2 V_155 ;
int V_86 = 0 , V_128 = 0 ;
int V_156 = 1 , V_157 ;
if ( ! V_18 -> V_135 )
return - V_136 ;
if ( ( V_18 -> V_44 < V_45 ) ||
( F_43 ( V_158 , & V_18 -> V_42 . V_159 ) !=
V_160 ) )
return - V_98 ;
V_153 = V_18 -> V_137 -> V_76 ;
V_154 = V_18 -> V_161 ;
if ( V_18 -> V_161 ) {
F_45 ( V_151 ) ;
V_18 -> V_161 = 0 ;
}
V_86 = F_33 ( V_18 , V_138 ) ;
if ( V_86 != 0 )
return V_86 ;
F_38 ( 100 ) ;
V_155 = F_46 ( V_18 -> V_42 . V_162 +
V_163 ) ;
if ( V_149 == V_164 )
V_155 |= V_165 ;
else if ( V_149 == V_166 )
V_155 |= V_167 ;
else if ( V_149 == V_168 )
V_155 |= V_169 ;
F_47 ( V_155 , V_18 -> V_42 . V_162 +
V_163 ) ;
F_46 ( V_18 -> V_42 . V_162 + V_163 ) ;
V_128 = F_41 ( V_18 ) ;
if ( V_128 == - V_98 ) {
F_30 ( V_18 , V_116 , V_118 ,
L_35
L_36 , V_155 ) ;
} else if ( V_128 == - V_120 ) {
F_30 ( V_18 , V_116 , V_118 ,
L_37
L_36 , V_155 ) ;
return V_128 ;
}
if ( V_153 & V_96 )
goto V_170;
F_34 ( & V_122 ) ;
V_156 = F_35 ( V_18 , & V_86 , & V_122 ,
V_139 ) ;
if ( ! V_156 )
goto V_170;
F_36 ( & V_122 ) ;
V_170:
if ( V_154 ) {
V_157 =
F_48 ( V_18 , V_154 ) ;
if ( ! V_157 )
V_18 -> V_161 = V_154 ;
}
if ( ! V_128 ) {
if ( ! V_156 )
V_128 = - V_101 ;
else if ( V_86 )
V_128 = - V_120 ;
}
return V_128 ;
}
static T_1
F_49 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_171 ) ;
}
static T_1
F_50 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char * V_172 ;
if ( V_18 -> V_51 == V_57 )
V_172 = L_38 ;
else if ( V_18 -> V_51 == V_53 )
V_172 = L_39 ;
else if ( V_18 -> V_51 == V_54 )
V_172 = L_40 ;
else
V_172 = L_41 ;
return snprintf ( V_9 , V_10 , L_8 , V_172 ) ;
}
static T_1
F_51 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_121 V_122 ;
char * V_173 = NULL ;
int V_86 = 0 ;
int V_128 ;
if ( ! V_18 -> V_135 ) {
V_86 = - V_136 ;
goto V_174;
}
F_52 ( V_15 , V_116 , V_134 ,
L_42 , V_9 ) ;
F_34 ( & V_122 ) ;
if( strncmp ( V_9 , L_41 , sizeof( L_41 ) - 1 ) == 0 ) {
V_128 = F_35 ( V_18 , & V_86 , & V_122 ,
V_139 ) ;
if ( V_128 == 0 ) {
V_86 = - V_101 ;
goto V_174;
}
F_36 ( & V_122 ) ;
} else if ( strncmp ( V_9 , L_40 , sizeof( L_40 ) - 1 ) == 0 )
V_86 = F_33 ( V_18 , V_138 ) ;
else if ( strncmp ( V_9 , L_43 , sizeof( L_43 ) - 1 ) == 0 )
if ( V_18 -> V_44 == V_45 )
V_86 = - V_87 ;
else
V_86 = F_33 ( V_18 , V_175 ) ;
else if ( strncmp ( V_9 , L_38 , sizeof( L_38 ) - 1 ) == 0 )
if ( V_18 -> V_44 == V_45 )
V_86 = - V_87 ;
else
V_86 = F_33 ( V_18 , V_176 ) ;
else if ( strncmp ( V_9 , L_44 , sizeof( L_44 ) - 1 ) == 0 )
V_86 = F_44 ( V_18 , V_164 ) ;
else if ( strncmp ( V_9 , L_45 , sizeof( L_45 ) - 1 ) == 0 )
V_86 = F_44 ( V_18 , V_166 ) ;
else if ( strncmp ( V_9 , L_46 , sizeof( L_46 ) - 1 ) == 0 )
V_86 = F_44 ( V_18 , V_168 ) ;
else
V_86 = - V_87 ;
V_174:
if ( ! V_86 )
return strlen ( V_9 ) ;
else {
V_173 = strchr ( V_9 , '\n' ) ;
if ( V_173 )
* V_173 = '\0' ;
F_52 ( V_15 , V_116 , V_134 ,
L_47
L_48 ,
V_9 , V_86 , V_18 -> V_137 -> V_76 ) ;
return V_86 ;
}
}
static int
F_53 ( struct V_17 * V_18 ,
T_2 * V_177 , T_2 * V_178 ,
T_2 * V_179 , T_2 * V_180 ,
T_2 * V_181 , T_2 * V_182 )
{
struct V_183 * V_184 ;
T_6 * V_93 ;
T_7 * V_185 ;
int V_128 = 0 ;
T_2 V_186 ;
if ( V_18 -> V_51 < V_56 ||
! V_18 -> V_99 ||
( V_18 -> V_33 . V_34 & V_187 ) == 0 )
return 0 ;
if ( V_18 -> V_33 . V_34 & V_97 )
return 0 ;
V_93 = F_27 ( V_18 -> V_99 , V_100 ) ;
if ( ! V_93 )
return 0 ;
memset ( V_93 , 0 , sizeof ( T_6 ) ) ;
V_185 = & V_93 -> V_102 . V_103 ;
V_185 -> V_104 = V_188 ;
V_185 -> V_106 = V_107 ;
V_93 -> V_189 = NULL ;
if ( V_18 -> V_137 -> V_76 & V_96 )
V_128 = V_190 ;
else
V_128 = F_28 ( V_18 , V_93 , V_18 -> V_114 * 2 ) ;
if ( V_128 != V_109 ) {
if ( V_128 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
return 0 ;
}
if ( V_18 -> V_44 == V_45 ) {
V_184 = & V_93 -> V_102 . V_191 . V_192 . V_184 ;
if ( V_179 )
* V_179 = F_43 ( V_193 , V_184 ) ;
if ( V_180 )
* V_180 = F_43 ( V_193 , V_184 ) -
V_18 -> V_42 . V_194 . V_195 ;
if ( V_177 )
* V_177 = F_43 ( V_196 , V_184 ) ;
if ( V_178 )
* V_178 = F_43 ( V_196 , V_184 ) -
V_18 -> V_42 . V_194 . V_197 ;
V_186 = ( F_43 ( V_198 , V_184 ) > 0 ) ?
( F_43 ( V_198 , V_184 ) - 1 ) : 0 ;
if ( V_181 )
* V_181 = V_186 ;
if ( V_182 )
* V_182 = V_186 - V_18 -> V_42 . V_194 . V_199 ;
} else {
if ( V_179 )
* V_179 = V_185 -> V_192 . V_200 . V_201 ;
if ( V_180 )
* V_180 = V_185 -> V_192 . V_200 . V_202 ;
if ( V_177 )
* V_177 = V_185 -> V_192 . V_200 . V_203 ;
if ( V_178 )
* V_178 = V_185 -> V_192 . V_200 . V_204 ;
if ( V_181 )
* V_181 = V_185 -> V_192 . V_200 . V_186 ;
if ( V_182 )
* V_182 = V_185 -> V_192 . V_200 . V_205 ;
}
F_32 ( V_93 , V_18 -> V_99 ) ;
return 1 ;
}
static T_1
F_54 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 ;
if ( F_53 ( V_18 , NULL , NULL , & V_127 , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_127 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_55 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 , V_206 ;
if ( F_53 ( V_18 , NULL , NULL , & V_127 , & V_206 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_127 - V_206 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_56 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 ;
if ( F_53 ( V_18 , & V_127 , NULL , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_127 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_57 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 , V_206 ;
if ( F_53 ( V_18 , & V_127 , & V_206 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_127 - V_206 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_58 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 ;
if ( F_53 ( V_18 , NULL , NULL , NULL , NULL , & V_127 , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_127 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_59 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_127 , V_206 ;
if ( F_53 ( V_18 , NULL , NULL , NULL , NULL , & V_127 , & V_206 ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_127 - V_206 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_60 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_186 ) )
return snprintf ( V_9 , V_10 , L_49 ) ;
if ( V_15 -> V_207 == V_208 )
return snprintf ( V_9 , V_10 , L_50 ) ;
return snprintf ( V_9 , V_10 , L_51 , V_15 -> V_209 ) ;
}
static T_1
F_61 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_52 , V_18 -> V_210 ) ;
}
static T_1
F_62 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_211 ;
T_2 V_212 ;
int V_213 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_9 , L_53 , & V_213 ) != 1 )
return - V_87 ;
if ( ( V_213 & 0x3 ) != V_213 )
return - V_87 ;
if ( V_18 -> V_44 == V_45 )
V_213 = 0 ;
F_52 ( V_15 , V_116 , V_134 ,
L_54 ,
V_18 -> V_210 , V_213 ) ;
F_63 ( & V_18 -> V_214 ) ;
V_212 = V_18 -> V_210 ;
if ( V_213 & V_215 ) {
if ( ( V_213 & V_216 ) &&
! ( V_212 & V_216 ) ) {
if ( F_42 ( V_18 -> V_217 , & V_211 ) ) {
F_64 ( & V_18 -> V_214 ) ;
return - V_87 ;
}
V_211 &= ~ ( V_218 << V_219 ) ;
F_47 ( V_211 , V_18 -> V_217 ) ;
F_46 ( V_18 -> V_217 ) ;
F_65 ( V_18 ) ;
}
} else if ( V_213 != 0x0 ) {
F_64 ( & V_18 -> V_214 ) ;
return - V_87 ;
}
if ( ! ( V_213 & V_216 ) &&
( V_212 & V_216 ) )
{
F_64 ( & V_18 -> V_214 ) ;
F_66 ( & V_18 -> V_220 ) ;
F_63 ( & V_18 -> V_214 ) ;
if ( F_42 ( V_18 -> V_217 , & V_211 ) ) {
F_64 ( & V_18 -> V_214 ) ;
return - V_87 ;
}
V_211 |= ( V_218 << V_219 ) ;
F_47 ( V_211 , V_18 -> V_217 ) ;
F_46 ( V_18 -> V_217 ) ;
}
V_18 -> V_210 = V_213 ;
F_64 ( & V_18 -> V_214 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_67 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_221 ) ;
}
static T_1
F_68 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_222 ) ;
}
static T_1
F_69 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_55 ,
( V_18 -> V_223 ) ? L_56 : L_57 ,
( V_18 -> V_22 & V_224 ) ?
L_58 : L_59 ) ;
}
static T_1
F_70 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_8 V_225 ;
V_225 = F_71 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_9 , V_225 ) ;
}
static T_1
F_72 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
unsigned int V_127 = V_85 ;
if ( V_9 [ V_127 - 1 ] == '\n' )
V_127 -- ;
if ( ( V_127 != strlen ( V_226 ) ) ||
( strncmp ( V_9 , V_226 , strlen ( V_226 ) ) != 0 ) )
return - V_87 ;
V_18 -> V_227 = 1 ;
return V_85 ;
}
static T_1
F_73 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_60 ,
( unsigned long long ) V_18 -> V_228 ) ;
}
static T_1
F_74 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_121 V_122 ;
int V_229 = 0 , V_230 = 0 ;
unsigned int V_3 , V_4 , V_127 = V_85 ;
T_9 V_231 [ 8 ] ;
int V_128 ;
if ( ! V_18 -> V_135 )
return - V_136 ;
F_63 ( & V_18 -> V_214 ) ;
if ( V_18 -> V_232 == V_233 ) {
F_64 ( & V_18 -> V_214 ) ;
return - V_136 ;
}
F_64 ( & V_18 -> V_214 ) ;
if ( V_9 [ V_127 - 1 ] == '\n' )
V_127 -- ;
if ( ! V_18 -> V_227 || ( V_127 < 16 ) || ( V_127 > 18 ) ||
( ( V_127 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_127 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_87 ;
V_18 -> V_227 = 0 ;
memset ( V_231 , 0 , sizeof( V_231 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_234 ;
V_234 = F_75 ( * V_9 ++ ) ;
if ( V_234 >= 0 )
V_4 = ( V_4 << 4 ) | V_234 ;
else
return - V_87 ;
if ( V_3 % 2 ) {
V_231 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_228 = F_76 ( V_231 ) ;
F_77 ( V_13 ) = V_18 -> V_228 ;
if ( V_18 -> V_235 )
F_78 ( V_13 ) = V_18 -> V_235 ;
F_79 ( V_236 , & V_18 -> V_152 -> V_6 ,
L_61 , V_18 -> V_237 ) ;
V_229 = F_33 ( V_18 , V_138 ) ;
if ( V_229 )
F_30 ( V_18 , V_116 , V_134 ,
L_62
L_63 , V_229 ) ;
F_34 ( & V_122 ) ;
V_128 = F_35 ( V_18 , & V_230 , & V_122 ,
V_139 ) ;
if ( V_128 == 0 )
return - V_101 ;
F_36 ( & V_122 ) ;
if ( V_230 )
F_30 ( V_18 , V_116 , V_134 ,
L_64
L_63 , V_230 ) ;
return ( V_229 || V_230 ) ? - V_120 : V_85 ;
}
static T_1
F_80 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_60 ,
( unsigned long long ) V_18 -> V_235 ) ;
}
static T_1
F_81 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_3 , V_4 , V_127 = V_85 ;
T_9 V_238 [ 8 ] ;
if ( V_9 [ V_127 - 1 ] == '\n' )
V_127 -- ;
if ( ! V_18 -> V_227 || ( V_127 < 16 ) || ( V_127 > 18 ) ||
( ( V_127 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_127 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_87 ;
memset ( V_238 , 0 , sizeof( V_238 ) ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
int V_234 ;
V_234 = F_75 ( * V_9 ++ ) ;
if ( V_234 >= 0 )
V_4 = ( V_4 << 4 ) | V_234 ;
else
return - V_87 ;
if ( V_3 % 2 ) {
V_238 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
V_18 -> V_235 = F_76 ( V_238 ) ;
F_79 ( V_236 , & V_18 -> V_152 -> V_6 ,
L_65
L_66 , V_18 -> V_237 ) ;
return V_85 ;
}
static T_1
F_82 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_239 ) ;
}
static T_1
F_83 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_131 [ V_240 ] . V_241 ) ;
}
static T_1
F_84 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_131 [ V_240 ] . V_242 ) ;
}
static T_1
F_85 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 , V_15 -> V_243 ) ;
}
static int
F_86 ( struct V_14 * V_15 , int V_213 )
{
if ( V_15 -> V_243 != V_244 ) {
V_15 -> V_245 = V_15 -> V_243 ;
if ( V_213 != V_244 )
F_52 ( V_15 , V_116 , V_134 ,
L_67
L_68
L_69 ) ;
return 0 ;
}
if ( V_213 >= V_246 && V_213 <= V_247 ) {
V_15 -> V_245 = V_213 ;
V_15 -> V_243 = V_213 ;
return 0 ;
}
F_52 ( V_15 , V_116 , V_134 ,
L_70
L_71 ,
V_213 , V_246 , V_247 ) ;
V_15 -> V_245 = V_244 ;
return - V_87 ;
}
static void
F_87 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_248 * V_249 ;
V_13 = F_88 ( V_15 ) ;
F_63 ( V_13 -> V_250 ) ;
F_89 (ndlp, &vport->fc_nodes, nlp_listp)
if ( F_90 ( V_249 ) && V_249 -> V_251 )
V_249 -> V_251 -> V_252 = V_15 -> V_243 ;
F_64 ( V_13 -> V_250 ) ;
}
static int
F_91 ( struct V_14 * V_15 , int V_213 )
{
if ( V_15 -> V_253 ||
( V_254 != V_244 ) ) {
F_52 ( V_15 , V_116 , V_134 ,
L_72
L_73 ) ;
return 0 ;
}
if ( V_213 >= V_246 && V_213 <= V_247 ) {
V_15 -> V_245 = V_213 ;
V_15 -> V_243 = V_213 ;
F_92 ( F_88 ( V_15 ) ) = V_213 ;
F_87 ( V_15 ) ;
return 0 ;
}
F_52 ( V_15 , V_116 , V_134 ,
L_74
L_75 ,
V_213 , V_246 , V_247 ) ;
return - V_87 ;
}
static int
F_93 ( struct V_14 * V_15 , int V_213 )
{
if ( V_213 >= V_246 && V_213 <= V_247 ) {
V_15 -> V_245 = V_213 ;
V_15 -> V_243 = V_213 ;
V_15 -> V_253 = 1 ;
F_92 ( F_88 ( V_15 ) ) = V_213 ;
F_87 ( V_15 ) ;
return 0 ;
}
F_52 ( V_15 , V_116 , V_134 ,
L_76
L_71 ,
V_213 , V_246 , V_247 ) ;
return - V_87 ;
}
static int
F_94 ( struct V_14 * V_15 , int V_213 )
{
if ( V_213 < 0 || V_213 > 1 ) {
F_52 ( V_15 , V_116 , V_134 ,
L_77
L_78 ,
V_213 ) ;
V_15 -> V_255 = 1 ;
return - V_87 ;
}
if ( V_15 -> V_207 == V_208 ) {
V_15 -> V_255 = 0 ;
return 0 ;
}
V_15 -> V_255 = V_213 ;
return 0 ;
}
static int
F_95 ( struct V_14 * V_15 , int V_213 )
{
if ( V_213 < 0 || V_213 > 1 ) {
F_52 ( V_15 , V_116 , V_134 ,
L_79
L_78 ,
V_213 ) ;
V_15 -> V_255 = 1 ;
return - V_87 ;
}
if ( V_15 -> V_207 == V_208 && V_213 != 0 ) {
F_52 ( V_15 , V_116 , V_134 ,
L_80
L_81 ) ;
V_15 -> V_255 = 0 ;
return 0 ;
}
V_15 -> V_255 = V_213 ;
return 0 ;
}
static T_1
F_96 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_213 = 0 ;
int V_256 = 0 ;
const char * V_257 = V_9 ;
int V_258 ;
T_2 V_259 ;
if ( ! strncmp ( V_9 , L_82 , strlen ( L_82 ) ) ) {
V_256 = 1 ;
V_257 = & V_9 [ strlen ( L_82 ) ] ;
}
if ( ! isdigit ( V_257 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_257 , L_53 , & V_213 ) != 1 )
return - V_87 ;
if ( V_213 >= 0 && V_213 <= 6 ) {
V_259 = V_18 -> V_112 ;
V_18 -> V_112 = V_213 ;
if ( V_18 -> V_113 == V_260 &&
V_213 == 4 ) {
F_52 ( V_15 , V_116 , V_134 ,
L_83 ,
V_18 -> V_113 ) ;
V_18 -> V_112 = V_259 ;
return - V_87 ;
}
if ( V_256 )
return strlen ( V_9 ) ;
F_52 ( V_15 , V_116 , V_134 ,
L_84 ,
V_259 , V_213 ) ;
if ( V_259 != V_213 && V_18 -> V_44 == V_45 )
V_18 -> V_261 = 1 ;
V_258 = F_26 ( F_88 ( V_18 -> V_137 ) ) ;
if ( V_258 ) {
V_18 -> V_112 = V_259 ;
return - V_87 ;
} else
return strlen ( V_9 ) ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_85
L_86 ,
V_18 -> V_237 , V_213 ) ;
return - V_87 ;
}
static T_1
F_97 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_262 & V_263 )
sprintf ( V_9 , L_2 ) ;
else
sprintf ( V_9 , L_3 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_98 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
#define F_99 1024
static char V_264 [ F_99 ] ;
unsigned long V_3 ;
char * V_265 , * V_266 ;
struct V_14 * * V_267 ;
struct V_12 * V_268 ;
char * V_269 , * V_270 , * V_271 ;
unsigned long V_272 , V_273 , V_274 ;
if ( ! strncmp ( V_9 , L_87 , strlen ( L_87 ) ) ) {
if ( strlen ( V_9 ) > ( F_99 - 1 ) )
return - V_87 ;
strcpy ( V_264 , V_9 ) ;
V_265 = & V_264 [ 0 ] ;
V_266 = F_100 ( & V_265 , L_88 ) ;
if ( ! V_266 )
return - V_87 ;
V_269 = F_100 ( & V_265 , L_88 ) ;
if ( ! V_269 )
return - V_87 ;
if ( ! strncmp ( V_269 , L_89 , strlen ( L_89 ) ) )
V_274 = V_275 ;
else if ( ! strncmp ( V_269 , L_90 , strlen ( L_90 ) ) )
V_274 = V_276 ;
else
return - V_87 ;
V_270 = F_100 ( & V_265 , L_88 ) ;
if ( ! V_270 )
return - V_87 ;
V_272 = F_101 ( V_270 , NULL , 0 ) ;
V_271 = F_100 ( & V_265 , L_88 ) ;
if ( ! V_271 )
return - V_87 ;
V_273 = F_101 ( V_271 , NULL , 0 ) ;
if ( ! V_273 )
return - V_87 ;
V_267 = F_102 ( V_18 ) ;
if ( V_267 == NULL )
return - V_101 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_277 && V_267 [ V_3 ] != NULL ; V_3 ++ ) {
V_268 = F_88 ( V_267 [ V_3 ] ) ;
F_63 ( V_268 -> V_250 ) ;
V_267 [ V_3 ] -> V_278 = 1 ;
if ( V_267 [ V_3 ] -> V_279 )
F_103 ( V_267 [ V_3 ] ) ;
F_64 ( V_268 -> V_250 ) ;
}
V_18 -> V_274 = V_274 ;
V_18 -> V_280 = V_272 ;
V_18 -> V_281 = V_273 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_277 && V_267 [ V_3 ] != NULL ; V_3 ++ ) {
V_268 = F_88 ( V_267 [ V_3 ] ) ;
F_63 ( V_268 -> V_250 ) ;
V_267 [ V_3 ] -> V_278 = 0 ;
F_64 ( V_268 -> V_250 ) ;
}
F_104 ( V_18 , V_267 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_91 , strlen ( L_91 ) ) ) {
V_267 = F_102 ( V_18 ) ;
if ( V_267 == NULL )
return - V_101 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_277 && V_267 [ V_3 ] != NULL ; V_3 ++ ) {
V_268 = F_88 ( V_267 [ V_3 ] ) ;
F_63 ( V_13 -> V_250 ) ;
V_267 [ V_3 ] -> V_278 = 1 ;
F_105 ( V_15 ) ;
V_15 -> V_279 = 0 ;
V_267 [ V_3 ] -> V_278 = 0 ;
F_64 ( V_13 -> V_250 ) ;
}
F_104 ( V_18 , V_267 ) ;
V_18 -> V_274 = V_282 ;
V_18 -> V_280 = 0 ;
V_18 -> V_281 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_92 , strlen ( L_92 ) ) ) {
if ( V_18 -> V_274 == V_282 )
return - V_87 ;
F_63 ( V_13 -> V_250 ) ;
if ( V_15 -> V_279 ) {
F_64 ( V_13 -> V_250 ) ;
return strlen ( V_9 ) ;
}
F_106 ( V_15 ) ;
V_15 -> V_279 = 1 ;
F_64 ( V_13 -> V_250 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_93 , strlen ( L_93 ) ) ) {
F_63 ( V_13 -> V_250 ) ;
if ( V_15 -> V_279 == 0 ) {
F_64 ( V_13 -> V_250 ) ;
return strlen ( V_9 ) ;
}
F_105 ( V_15 ) ;
V_15 -> V_279 = 0 ;
F_64 ( V_13 -> V_250 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_94 , strlen ( L_94 ) ) ) {
if ( ( V_18 -> V_274 == V_282 )
|| ! V_15 -> V_279 )
return strlen ( V_9 ) ;
F_63 ( V_13 -> V_250 ) ;
V_15 -> V_278 = 1 ;
F_103 ( V_15 ) ;
V_15 -> V_278 = 0 ;
F_64 ( V_13 -> V_250 ) ;
return strlen ( V_9 ) ;
}
return - V_87 ;
}
static T_1
F_107 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_283 = 0 ;
int V_3 ;
char * V_274 ;
unsigned long V_284 ;
switch ( V_18 -> V_274 ) {
case V_275 :
V_274 = L_89 ;
break;
case V_276 :
V_274 = L_90 ;
break;
default:
V_274 = L_95 ;
break;
}
sprintf ( & V_9 [ V_283 ] , L_96
L_97
L_98 ,
V_15 -> V_279 , V_15 -> V_278 ,
V_274 , V_18 -> V_280 , V_18 -> V_281 ) ;
V_283 = strlen ( V_9 ) ;
if ( V_18 -> V_274 != V_282 ) {
for ( V_3 = 0 ; V_3 < V_285 ; V_3 ++ ) {
if ( V_18 -> V_274 == V_275 )
V_284 = V_18 -> V_280 +
V_18 -> V_281 * V_3 ;
else
V_284 = V_18 -> V_280 +
( 1 << V_3 ) * V_18 -> V_281 ;
if ( V_283 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_283 ] , L_99 , V_284 ) ;
V_283 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_283 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_108 ( struct V_286 * V_287 , struct V_288 * V_289 ,
struct V_290 * V_291 ,
char * V_9 , T_10 V_292 , T_5 V_85 )
{
struct V_5 * V_6 = F_109 ( V_289 , struct V_5 ,
V_289 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_283 = 0 ;
unsigned long V_293 ;
struct V_248 * V_249 = NULL ;
V_293 = ( unsigned long ) V_292 /
V_294 ;
if ( ! V_15 -> V_279 || V_15 -> V_278
|| ( V_18 -> V_274 == V_282 ) )
return 0 ;
F_63 ( V_13 -> V_250 ) ;
F_89 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_90 ( V_249 ) || ! V_249 -> V_295 )
continue;
if ( V_293 > 0 ) {
V_293 -- ;
continue;
}
if ( ( V_283 + V_294 )
> V_85 )
break;
if ( ! V_249 -> V_295 )
continue;
sprintf ( & V_9 [ V_283 ] , L_100 ,
V_249 -> V_296 . V_102 . V_297 [ 0 ] ,
V_249 -> V_296 . V_102 . V_297 [ 1 ] ,
V_249 -> V_296 . V_102 . V_297 [ 2 ] ,
V_249 -> V_296 . V_102 . V_297 [ 3 ] ,
V_249 -> V_296 . V_102 . V_297 [ 4 ] ,
V_249 -> V_296 . V_102 . V_297 [ 5 ] ,
V_249 -> V_296 . V_102 . V_297 [ 6 ] ,
V_249 -> V_296 . V_102 . V_297 [ 7 ] ) ;
V_283 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_285 ; V_3 ++ ) {
sprintf ( & V_9 [ V_283 ] , L_101 ,
V_249 -> V_295 [ V_3 ] . V_298 ) ;
V_283 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_283 ] , L_1 ) ;
V_283 = strlen ( V_9 ) ;
}
F_64 ( V_13 -> V_250 ) ;
return V_283 ;
}
static T_1
F_110 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_213 = V_299 ;
int V_256 = 0 ;
const char * V_257 = V_9 ;
int V_258 ;
T_2 V_259 ;
if ( ! strncmp ( V_9 , L_82 , strlen ( L_82 ) ) ) {
V_256 = 1 ;
V_257 = & V_9 [ strlen ( L_82 ) ] ;
}
if ( ! isdigit ( V_257 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_257 , L_53 , & V_213 ) != 1 )
return - V_87 ;
F_52 ( V_15 , V_116 , V_134 ,
L_102 ,
V_18 -> V_113 , V_213 , V_256 ? L_103 : L_104 ) ;
if ( ( ( V_213 == V_300 ) && ! ( V_18 -> V_301 & V_302 ) ) ||
( ( V_213 == V_303 ) && ! ( V_18 -> V_301 & V_304 ) ) ||
( ( V_213 == V_305 ) && ! ( V_18 -> V_301 & V_306 ) ) ||
( ( V_213 == V_307 ) && ! ( V_18 -> V_301 & V_308 ) ) ||
( ( V_213 == V_309 ) && ! ( V_18 -> V_301 & V_310 ) ) ||
( ( V_213 == V_260 ) && ! ( V_18 -> V_301 & V_311 ) ) ) {
F_30 ( V_18 , V_116 , V_134 ,
L_105
L_106 ,
V_213 ) ;
return - V_87 ;
}
if ( V_213 == V_260 &&
V_18 -> V_74 == V_75 ) {
F_30 ( V_18 , V_116 , V_134 ,
L_107
L_108 ,
V_213 ) ;
return - V_87 ;
}
if ( ( V_213 >= 0 ) && ( V_213 <= V_312 ) &&
( V_313 & ( 1 << V_213 ) ) ) {
V_259 = V_18 -> V_113 ;
V_18 -> V_113 = V_213 ;
if ( V_256 )
return strlen ( V_9 ) ;
V_258 = F_26 ( F_88 ( V_18 -> V_137 ) ) ;
if ( V_258 ) {
V_18 -> V_113 = V_259 ;
return - V_87 ;
} else
return strlen ( V_9 ) ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_109
L_110 V_314 L_111 , V_213 ) ;
return - V_87 ;
}
static int
F_111 ( struct V_17 * V_18 , int V_213 )
{
if ( V_213 == V_260 && V_18 -> V_112 == 4 ) {
F_30 ( V_18 , V_116 , V_134 ,
L_112
L_113 ,
V_213 ) ;
V_18 -> V_112 = 0 ;
}
if ( ( V_213 >= 0 ) && ( V_213 <= V_312 ) &&
( V_313 & ( 1 << V_213 ) ) ) {
V_18 -> V_113 = V_213 ;
return 0 ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_114
L_115
L_116 V_314 L_111 , V_213 ) ;
V_18 -> V_113 = V_299 ;
return - V_87 ;
}
static T_1
F_112 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_213 = 0 , V_128 = - V_87 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_9 , L_53 , & V_213 ) != 1 )
return - V_87 ;
switch ( V_213 ) {
case 0 :
if ( V_18 -> V_19 & V_315 ) {
V_128 = F_113 ( V_18 -> V_152 ) ;
if ( ! V_128 ) {
F_63 ( & V_18 -> V_214 ) ;
V_18 -> V_19 &= ~ V_315 ;
F_64 ( & V_18 -> V_214 ) ;
V_18 -> V_316 = 0 ;
V_128 = strlen ( V_9 ) ;
} else
V_128 = - V_98 ;
} else {
V_18 -> V_316 = 0 ;
V_128 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_315 ) ) {
V_128 = F_114 ( V_18 -> V_152 ) ;
if ( ! V_128 ) {
F_63 ( & V_18 -> V_214 ) ;
V_18 -> V_19 |= V_315 ;
F_64 ( & V_18 -> V_214 ) ;
V_18 -> V_316 = 1 ;
V_128 = strlen ( V_9 ) ;
} else
V_128 = - V_98 ;
} else {
V_18 -> V_316 = 1 ;
V_128 = strlen ( V_9 ) ;
}
break;
default:
V_128 = - V_87 ;
break;
}
return V_128 ;
}
static int
F_115 ( struct V_17 * V_18 , int V_213 )
{
if ( V_213 == 0 || V_213 == 1 ) {
V_18 -> V_316 = V_213 ;
return 0 ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_117
L_118
L_119 , V_213 ) ;
V_18 -> V_316 = 1 ;
return - V_87 ;
}
static T_1
F_116 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_213 , V_128 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_9 , L_53 , & V_213 ) != 1 )
return - V_87 ;
if ( V_213 != 1 )
return - V_87 ;
if ( V_18 -> V_19 & V_315 )
V_128 = F_117 ( V_18 -> V_152 ) ;
if ( V_128 == 0 )
return strlen ( V_9 ) ;
else
return - V_98 ;
}
static T_1
F_118 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_150 * V_151 = V_18 -> V_152 ;
int V_213 = 0 , V_128 = - V_87 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_9 , L_53 , & V_213 ) != 1 )
return - V_87 ;
if ( V_213 < 0 )
return - V_87 ;
if ( V_213 == 0 ) {
if ( V_18 -> V_161 > 0 ) {
F_45 ( V_151 ) ;
V_18 -> V_161 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_161 > 0 ) {
F_30 ( V_18 , V_116 , V_134 ,
L_120
L_121 ,
V_18 -> V_161 ) ;
return - V_317 ;
}
if ( V_213 <= V_318 )
V_18 -> V_161 = V_213 ;
else {
F_30 ( V_18 , V_116 , V_134 ,
L_122
L_123 , V_213 ) ;
return - V_87 ;
}
V_128 = F_48 ( V_18 , V_18 -> V_161 ) ;
if ( V_128 ) {
V_18 -> V_161 = 0 ;
V_128 = - V_98 ;
} else
V_128 = strlen ( V_9 ) ;
return V_128 ;
}
static int
F_119 ( struct V_17 * V_18 , int V_213 )
{
if ( V_213 >= 0 && V_213 <= V_318 ) {
V_18 -> V_161 = V_213 ;
return 0 ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_124
L_123 , V_213 ) ;
return - V_87 ;
}
static T_1
F_120 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_213 = 0 , V_128 = - V_87 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_9 , L_53 , & V_213 ) != 1 )
return - V_87 ;
if ( V_213 != 1 )
return - V_87 ;
V_128 = F_121 ( V_18 , V_319 ) ;
if ( V_128 )
V_128 = - V_98 ;
else
V_128 = strlen ( V_9 ) ;
return V_128 ;
}
static int
F_122 ( struct V_17 * V_18 , int V_213 )
{
if ( V_213 >= 0 && V_213 <= 1 ) {
V_18 -> V_320 = V_213 ;
return 0 ;
}
return - V_87 ;
}
static T_1
F_123 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_213 = 0 , V_3 ;
if ( V_18 -> V_44 != V_45 )
return - V_87 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_87 ;
if ( sscanf ( V_9 , L_53 , & V_213 ) != 1 )
return - V_87 ;
if ( V_213 < V_321 || V_213 > V_322 )
return - V_87 ;
V_18 -> V_323 = ( T_2 ) V_213 ;
for ( V_3 = 0 ; V_3 < V_18 -> V_324 ; V_3 += V_325 )
F_124 ( V_18 , V_3 ) ;
return strlen ( V_9 ) ;
}
static int
F_125 ( struct V_17 * V_18 , int V_213 )
{
if ( V_18 -> V_44 != V_45 ) {
V_18 -> V_323 = 0 ;
return 0 ;
}
if ( V_213 >= V_321 && V_213 <= V_322 ) {
V_18 -> V_323 = V_213 ;
return 0 ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_125 , V_213 ) ;
V_18 -> V_323 = V_326 ;
return 0 ;
}
static T_1
F_126 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_327 * V_328 ;
int V_329 , V_41 = 0 ;
if ( ( V_18 -> V_44 != V_45 ) ||
( V_18 -> V_330 != V_331 ) )
return V_41 ;
switch ( V_18 -> V_332 ) {
case 0 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_126 ,
V_18 -> V_332 ) ;
return V_41 ;
case 1 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_127
L_128 ,
V_18 -> V_332 ,
V_18 -> V_42 . V_333 ) ;
break;
case 2 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_129
L_128 ,
V_18 -> V_332 ,
V_18 -> V_42 . V_333 ) ;
break;
}
V_328 = V_18 -> V_42 . V_334 ;
for ( V_329 = 0 ; V_329 < V_18 -> V_42 . V_335 ; V_329 ++ ) {
if ( V_328 -> V_336 == V_337 )
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_130
L_131 ,
V_329 , V_328 -> V_338 , V_328 -> V_339 ,
V_328 -> V_340 ) ;
else
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_130
L_132 ,
V_329 , V_328 -> V_338 , V_328 -> V_339 ,
V_328 -> V_340 , V_328 -> V_336 ) ;
V_328 ++ ;
}
return V_41 ;
}
static T_1
F_127 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_85 )
{
int V_86 = - V_87 ;
return V_86 ;
}
static int
F_128 ( struct V_17 * V_18 , int V_213 )
{
if ( V_18 -> V_44 != V_45 ) {
V_18 -> V_332 = 0 ;
return 0 ;
}
if ( V_213 >= V_341 && V_213 <= V_342 ) {
V_18 -> V_332 = V_213 ;
return 0 ;
}
F_30 ( V_18 , V_116 , V_134 ,
L_133 ,
V_213 ) ;
V_18 -> V_332 = V_343 ;
return 0 ;
}
static int
F_129 ( struct V_14 * V_15 , int V_213 )
{
struct V_12 * V_13 = F_88 ( V_15 ) ;
struct V_248 * V_249 , * V_344 ;
if ( V_213 == V_15 -> V_345 )
return 0 ;
if ( ( V_213 < 0 ) || ( V_213 > 60000 ) )
return - V_87 ;
V_15 -> V_345 = V_213 ;
F_63 ( V_13 -> V_250 ) ;
F_130 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_90 ( V_249 ) )
continue;
if ( V_249 -> V_346 == V_347 )
continue;
V_249 -> V_348 = V_15 -> V_349 ;
}
F_64 ( V_13 -> V_250 ) ;
return 0 ;
}
static T_1
F_131 ( struct V_286 * V_287 , struct V_288 * V_289 ,
struct V_290 * V_291 ,
char * V_9 , T_10 V_292 , T_5 V_85 )
{
T_5 V_350 ;
struct V_5 * V_6 = F_109 ( V_289 , struct V_5 , V_289 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_44 >= V_45 )
return - V_98 ;
if ( ( V_292 + V_85 ) > V_351 )
return - V_352 ;
if ( V_85 <= V_353 )
return 0 ;
if ( V_292 % 4 || V_85 % 4 || ( unsigned long ) V_9 % 4 )
return - V_87 ;
if ( memcmp ( V_9 , V_354 , V_353 ) )
return - V_87 ;
if ( ! ( V_15 -> V_76 & V_96 ) )
return - V_98 ;
F_63 ( & V_18 -> V_214 ) ;
for ( V_350 = 0 ; V_350 < V_85 - V_353 ;
V_350 += sizeof( T_2 ) )
F_47 ( * ( ( T_2 * ) ( V_9 + V_350 + V_353 ) ) ,
V_18 -> V_355 + V_292 + V_350 ) ;
F_64 ( & V_18 -> V_214 ) ;
return V_85 ;
}
static T_1
F_132 ( struct V_286 * V_287 , struct V_288 * V_289 ,
struct V_290 * V_291 ,
char * V_9 , T_10 V_292 , T_5 V_85 )
{
T_5 V_350 ;
T_2 * V_356 ;
struct V_5 * V_6 = F_109 ( V_289 , struct V_5 , V_289 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_44 >= V_45 )
return - V_98 ;
if ( V_292 > V_351 )
return - V_352 ;
if ( ( V_292 + V_85 ) > V_351 )
V_85 = V_351 - V_292 ;
if ( V_85 == 0 ) return 0 ;
if ( V_292 % 4 || V_85 % 4 || ( unsigned long ) V_9 % 4 )
return - V_87 ;
F_63 ( & V_18 -> V_214 ) ;
for ( V_350 = 0 ; V_350 < V_85 ; V_350 += sizeof( T_2 ) ) {
V_356 = ( T_2 * ) ( V_9 + V_350 ) ;
* V_356 = F_46 ( V_18 -> V_355 + V_292 + V_350 ) ;
}
F_64 ( & V_18 -> V_214 ) ;
return V_85 ;
}
static T_1
F_133 ( struct V_286 * V_287 , struct V_288 * V_289 ,
struct V_290 * V_291 ,
char * V_9 , T_10 V_292 , T_5 V_85 )
{
return - V_98 ;
}
static T_1
F_134 ( struct V_286 * V_287 , struct V_288 * V_289 ,
struct V_290 * V_291 ,
char * V_9 , T_10 V_292 , T_5 V_85 )
{
return - V_98 ;
}
int
F_135 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_88 ( V_15 ) ;
int error ;
error = F_136 ( & V_13 -> V_357 . V_289 ,
& V_358 ) ;
if ( error || V_15 -> V_207 == V_359 )
goto V_170;
error = F_136 ( & V_13 -> V_357 . V_289 ,
& V_360 ) ;
if ( error )
goto V_361;
error = F_136 ( & V_13 -> V_357 . V_289 ,
& V_362 ) ;
if ( error )
goto V_363;
return 0 ;
V_363:
F_137 ( & V_13 -> V_357 . V_289 , & V_360 ) ;
V_361:
F_137 ( & V_13 -> V_357 . V_289 ,
& V_358 ) ;
V_170:
return error ;
}
void
F_138 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_88 ( V_15 ) ;
F_137 ( & V_13 -> V_357 . V_289 ,
& V_358 ) ;
if ( V_15 -> V_207 == V_359 )
return;
F_137 ( & V_13 -> V_357 . V_289 , & V_362 ) ;
F_137 ( & V_13 -> V_357 . V_289 , & V_360 ) ;
}
static void
F_139 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_140 ( V_13 ) = V_15 -> V_364 ;
}
static void
F_141 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_63 ( V_13 -> V_250 ) ;
if ( V_15 -> V_207 == V_359 ) {
F_142 ( V_13 ) = V_365 ;
} else if ( F_143 ( V_18 ) ) {
if ( V_18 -> V_74 == V_75 ) {
if ( V_15 -> V_76 & V_77 )
F_142 ( V_13 ) = V_366 ;
else
F_142 ( V_13 ) = V_367 ;
} else {
if ( V_15 -> V_76 & V_78 )
F_142 ( V_13 ) = V_368 ;
else
F_142 ( V_13 ) = V_369 ;
}
} else
F_142 ( V_13 ) = V_370 ;
F_64 ( V_13 -> V_250 ) ;
}
static void
F_144 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_63 ( V_13 -> V_250 ) ;
if ( V_15 -> V_76 & V_96 )
F_145 ( V_13 ) = V_371 ;
else {
switch ( V_18 -> V_51 ) {
case V_52 :
case V_56 :
F_145 ( V_13 ) = V_372 ;
break;
case V_59 :
case V_60 :
case V_61 :
if ( V_15 -> V_62 < V_71 )
F_145 ( V_13 ) =
V_373 ;
else
F_145 ( V_13 ) =
V_374 ;
break;
case V_57 :
F_145 ( V_13 ) = V_375 ;
break;
default:
F_145 ( V_13 ) = V_376 ;
break;
}
}
F_64 ( V_13 -> V_250 ) ;
}
static void
F_146 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_63 ( V_13 -> V_250 ) ;
if ( F_143 ( V_18 ) ) {
switch( V_18 -> V_377 ) {
case V_378 :
F_147 ( V_13 ) = V_379 ;
break;
case V_380 :
F_147 ( V_13 ) = V_381 ;
break;
case V_382 :
F_147 ( V_13 ) = V_383 ;
break;
case V_384 :
F_147 ( V_13 ) = V_385 ;
break;
case V_386 :
F_147 ( V_13 ) = V_387 ;
break;
case V_388 :
F_147 ( V_13 ) = V_389 ;
break;
default:
F_147 ( V_13 ) = V_390 ;
break;
}
} else
F_147 ( V_13 ) = V_390 ;
F_64 ( V_13 -> V_250 ) ;
}
static void
F_148 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_11 V_391 ;
F_63 ( V_13 -> V_250 ) ;
if ( ( V_15 -> V_62 > V_65 ) &&
( ( V_15 -> V_76 & V_78 ) ||
( ( V_18 -> V_74 == V_75 ) &&
( V_15 -> V_76 & V_77 ) ) ) )
V_391 = F_76 ( V_18 -> V_392 . V_393 . V_102 . V_297 ) ;
else
V_391 = 0 ;
F_64 ( V_13 -> V_250 ) ;
F_149 ( V_13 ) = V_391 ;
}
static struct V_394 *
F_150 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_125 * V_126 = & V_18 -> V_33 ;
struct V_394 * V_395 = & V_18 -> V_396 ;
struct V_397 * V_398 = & V_126 -> V_399 ;
T_6 * V_93 ;
T_7 * V_185 ;
unsigned long V_400 ;
int V_128 = 0 ;
if ( V_18 -> V_51 < V_56 ||
! V_18 -> V_99 ||
( V_18 -> V_33 . V_34 & V_187 ) == 0 )
return NULL ;
if ( V_18 -> V_33 . V_34 & V_97 )
return NULL ;
V_93 = F_27 ( V_18 -> V_99 , V_100 ) ;
if ( ! V_93 )
return NULL ;
memset ( V_93 , 0 , sizeof ( T_6 ) ) ;
V_185 = & V_93 -> V_102 . V_103 ;
V_185 -> V_104 = V_401 ;
V_185 -> V_106 = V_107 ;
V_93 -> V_189 = NULL ;
V_93 -> V_15 = V_15 ;
if ( V_15 -> V_76 & V_96 )
V_128 = F_151 ( V_18 , V_93 , V_402 ) ;
else
V_128 = F_28 ( V_18 , V_93 , V_18 -> V_114 * 2 ) ;
if ( V_128 != V_109 ) {
if ( V_128 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
return NULL ;
}
memset ( V_395 , 0 , sizeof ( struct V_394 ) ) ;
V_395 -> V_403 = V_185 -> V_192 . V_404 . V_405 ;
V_395 -> V_406 = ( V_407 )
( ( V_407 ) V_185 -> V_192 . V_404 . V_408
* ( V_407 ) 256 ) ;
V_395 -> V_409 = V_185 -> V_192 . V_404 . V_410 ;
V_395 -> V_411 = ( V_407 )
( ( V_407 ) V_185 -> V_192 . V_404 . V_412
* ( V_407 ) 256 ) ;
memset ( V_93 , 0 , sizeof ( T_6 ) ) ;
V_185 -> V_104 = V_413 ;
V_185 -> V_106 = V_107 ;
V_93 -> V_189 = NULL ;
V_93 -> V_15 = V_15 ;
if ( V_15 -> V_76 & V_96 )
V_128 = F_151 ( V_18 , V_93 , V_402 ) ;
else
V_128 = F_28 ( V_18 , V_93 , V_18 -> V_114 * 2 ) ;
if ( V_128 != V_109 ) {
if ( V_128 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
return NULL ;
}
V_395 -> V_414 = V_185 -> V_192 . V_415 . V_416 ;
V_395 -> V_417 = V_185 -> V_192 . V_415 . V_418 ;
V_395 -> V_419 = V_185 -> V_192 . V_415 . V_420 ;
V_395 -> V_421 = V_185 -> V_192 . V_415 . V_422 ;
V_395 -> V_423 = V_185 -> V_192 . V_415 . V_424 ;
V_395 -> V_425 = V_185 -> V_192 . V_415 . V_426 ;
V_395 -> V_427 = V_185 -> V_192 . V_415 . V_426 ;
V_395 -> V_414 -= V_398 -> V_414 ;
V_395 -> V_417 -= V_398 -> V_417 ;
V_395 -> V_419 -= V_398 -> V_419 ;
V_395 -> V_421 -= V_398 -> V_421 ;
V_395 -> V_423 -= V_398 -> V_423 ;
V_395 -> V_425 -= V_398 -> V_425 ;
V_395 -> V_427 -= V_398 -> V_427 ;
if ( V_18 -> V_19 & V_428 ) {
V_395 -> V_429 = - 1 ;
V_395 -> V_430 = ( V_18 -> V_431 >> 1 ) ;
V_395 -> V_430 -= V_398 -> V_431 ;
} else if ( V_18 -> V_74 == V_75 ) {
V_395 -> V_429 = ( V_18 -> V_432 >> 1 ) ;
V_395 -> V_429 -= V_398 -> V_431 ;
V_395 -> V_430 = - 1 ;
} else {
V_395 -> V_429 = - 1 ;
V_395 -> V_430 = ( V_18 -> V_432 >> 1 ) ;
V_395 -> V_430 -= V_398 -> V_431 ;
}
V_395 -> V_433 = - 1 ;
V_400 = F_152 () ;
if ( V_400 < V_126 -> V_434 )
V_395 -> V_435 = V_400 +
( ( unsigned long ) - 1 - V_126 -> V_434 ) ;
else
V_395 -> V_435 = V_400 - V_126 -> V_434 ;
F_32 ( V_93 , V_18 -> V_99 ) ;
return V_395 ;
}
static void
F_153 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_125 * V_126 = & V_18 -> V_33 ;
struct V_397 * V_398 = & V_126 -> V_399 ;
T_6 * V_93 ;
T_7 * V_185 ;
int V_128 = 0 ;
if ( V_18 -> V_33 . V_34 & V_97 )
return;
V_93 = F_27 ( V_18 -> V_99 , V_100 ) ;
if ( ! V_93 )
return;
memset ( V_93 , 0 , sizeof( T_6 ) ) ;
V_185 = & V_93 -> V_102 . V_103 ;
V_185 -> V_104 = V_401 ;
V_185 -> V_106 = V_107 ;
V_185 -> V_192 . V_436 [ 0 ] = 0x1 ;
V_93 -> V_189 = NULL ;
V_93 -> V_15 = V_15 ;
if ( ( V_15 -> V_76 & V_96 ) ||
( ! ( V_126 -> V_34 & V_187 ) ) )
V_128 = F_151 ( V_18 , V_93 , V_402 ) ;
else
V_128 = F_28 ( V_18 , V_93 , V_18 -> V_114 * 2 ) ;
if ( V_128 != V_109 ) {
if ( V_128 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
return;
}
memset ( V_93 , 0 , sizeof( T_6 ) ) ;
V_185 -> V_104 = V_413 ;
V_185 -> V_106 = V_107 ;
V_93 -> V_189 = NULL ;
V_93 -> V_15 = V_15 ;
if ( ( V_15 -> V_76 & V_96 ) ||
( ! ( V_126 -> V_34 & V_187 ) ) )
V_128 = F_151 ( V_18 , V_93 , V_402 ) ;
else
V_128 = F_28 ( V_18 , V_93 , V_18 -> V_114 * 2 ) ;
if ( V_128 != V_109 ) {
if ( V_128 != V_119 )
F_32 ( V_93 , V_18 -> V_99 ) ;
return;
}
V_398 -> V_414 = V_185 -> V_192 . V_415 . V_416 ;
V_398 -> V_417 = V_185 -> V_192 . V_415 . V_418 ;
V_398 -> V_419 = V_185 -> V_192 . V_415 . V_420 ;
V_398 -> V_421 = V_185 -> V_192 . V_415 . V_422 ;
V_398 -> V_423 = V_185 -> V_192 . V_415 . V_424 ;
V_398 -> V_425 = V_185 -> V_192 . V_415 . V_426 ;
V_398 -> V_427 = V_185 -> V_192 . V_415 . V_426 ;
if ( V_18 -> V_19 & V_428 )
V_398 -> V_431 = ( V_18 -> V_431 >> 1 ) ;
else
V_398 -> V_431 = ( V_18 -> V_432 >> 1 ) ;
V_126 -> V_434 = F_152 () ;
F_32 ( V_93 , V_18 -> V_99 ) ;
return;
}
static struct V_248 *
F_154 ( struct V_437 * V_438 )
{
struct V_12 * V_13 = F_155 ( V_438 -> V_6 . V_439 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_248 * V_249 ;
F_63 ( V_13 -> V_250 ) ;
F_89 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_90 ( V_249 ) &&
V_249 -> V_346 == V_440 &&
V_438 -> V_441 == V_249 -> V_442 ) {
F_64 ( V_13 -> V_250 ) ;
return V_249 ;
}
}
F_64 ( V_13 -> V_250 ) ;
return NULL ;
}
static void
F_156 ( struct V_437 * V_438 )
{
struct V_248 * V_249 = F_154 ( V_438 ) ;
F_157 ( V_438 ) = V_249 ? V_249 -> V_443 : - 1 ;
}
static void
F_158 ( struct V_437 * V_438 )
{
struct V_248 * V_249 = F_154 ( V_438 ) ;
F_159 ( V_438 ) =
V_249 ? F_76 ( V_249 -> V_444 . V_102 . V_297 ) : 0 ;
}
static void
F_160 ( struct V_437 * V_438 )
{
struct V_248 * V_249 = F_154 ( V_438 ) ;
F_161 ( V_438 ) =
V_249 ? F_76 ( V_249 -> V_296 . V_102 . V_297 ) : 0 ;
}
static void
F_162 ( struct V_445 * V_251 , T_2 V_446 )
{
if ( V_446 )
V_251 -> V_252 = V_446 ;
else
V_251 -> V_252 = 1 ;
}
static void
F_163 ( struct V_447 * V_447 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_447 -> V_448 ;
if ( V_15 -> V_62 == V_71 )
F_164 ( V_15 , V_449 , 0 , 0 ) ;
}
static void
F_165 ( struct V_17 * V_18 , T_2 V_450 )
{
V_18 -> V_451 = V_450 ;
}
void
F_166 ( struct V_17 * V_18 )
{
F_167 ( V_18 , V_452 ) ;
F_168 ( V_18 , V_453 ) ;
F_169 ( V_18 , V_454 ) ;
F_170 ( V_18 , V_455 ) ;
F_171 ( V_18 , V_456 ) ;
F_172 ( V_18 , V_457 ) ;
F_173 ( V_18 , V_458 ) ;
F_174 ( V_18 , V_459 ) ;
F_175 ( V_18 , V_460 ) ;
F_111 ( V_18 , V_461 ) ;
F_176 ( V_18 , V_462 ) ;
F_177 ( V_18 , V_463 ) ;
F_178 ( V_18 , V_464 ) ;
F_179 ( V_18 , V_465 ) ;
F_180 ( V_18 , V_466 ) ;
F_181 ( V_18 , V_467 ) ;
F_125 ( V_18 , V_468 ) ;
F_128 ( V_18 , V_469 ) ;
F_182 ( V_18 , V_470 ) ;
F_183 ( V_18 , V_471 ) ;
F_184 ( V_18 , V_472 ) ;
F_185 ( V_18 , V_473 ) ;
if ( V_18 -> V_44 == V_45 )
V_18 -> V_210 = 0 ;
else
V_18 -> V_210 = V_474 ;
V_18 -> V_235 = 0L ;
V_18 -> V_228 = 0L ;
F_186 ( V_18 , V_475 ) ;
F_187 ( V_18 , V_476 ) ;
F_188 ( V_18 , V_477 ) ;
F_165 ( V_18 , V_478 ) ;
F_115 ( V_18 , V_479 ) ;
F_119 ( V_18 , V_480 ) ;
F_122 ( V_18 , V_481 ) ;
F_189 ( V_18 , V_482 ) ;
F_190 ( V_18 , V_483 ) ;
V_18 -> V_223 = 1 ;
return;
}
void
F_191 ( struct V_14 * V_15 )
{
F_192 ( V_15 , V_478 ) ;
F_193 ( V_15 , V_484 ) ;
F_194 ( V_15 , V_485 ) ;
F_195 ( V_15 , V_254 ) ;
F_86 ( V_15 , V_486 ) ;
F_196 ( V_15 , V_487 ) ;
F_94 ( V_15 , V_488 ) ;
F_197 ( V_15 , V_489 ) ;
F_198 ( V_15 , V_490 ) ;
F_199 ( V_15 , V_491 ) ;
F_200 ( V_15 , V_492 ) ;
F_201 ( V_15 , V_493 ) ;
F_202 ( V_15 , V_494 ) ;
F_203 ( V_15 , V_495 ) ;
F_204 ( V_15 , V_496 ) ;
F_205 ( V_15 , V_497 ) ;
return;
}
