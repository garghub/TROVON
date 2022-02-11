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
char V_39 [ V_40 ] ;
if ( V_18 -> V_44 < V_45 )
return snprintf ( V_9 , V_10 , L_8 , V_18 -> V_50 ) ;
F_19 ( V_18 , V_39 , 1 ) ;
return snprintf ( V_9 , V_10 , L_8 , V_39 ) ;
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
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_42 . V_43 . V_85 ) ;
}
static T_1
F_25 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_87 = - V_88 ;
if ( ( strncmp ( V_9 , L_28 , sizeof( L_28 ) - 1 ) == 0 ) &&
( V_18 -> V_51 == V_56 ) )
V_87 = V_18 -> V_89 ( V_18 , V_90 ) ;
else if ( ( strncmp ( V_9 , L_29 , sizeof( L_29 ) - 1 ) == 0 ) &&
( V_18 -> V_51 >= V_59 ) )
V_87 = V_18 -> V_91 ( V_18 , V_90 ) ;
if ( V_87 == 0 )
return strlen ( V_9 ) ;
else
return V_87 ;
}
static T_1
F_26 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_15 -> V_92 + V_15 -> V_93 ) ;
}
static int
F_27 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_6 * V_94 ;
int V_95 = V_96 ;
if ( ( V_15 -> V_76 & V_97 ) ||
( V_18 -> V_33 . V_34 & V_98 ) )
return - V_99 ;
V_94 = F_28 ( V_18 -> V_100 , V_101 ) ;
if ( ! V_94 )
return - V_102 ;
memset ( ( void * ) V_94 , 0 , sizeof ( T_6 ) ) ;
V_94 -> V_103 . V_104 . V_105 = V_106 ;
V_94 -> V_103 . V_104 . V_107 = V_108 ;
V_95 = F_29 ( V_18 , V_94 , V_109 * 2 ) ;
if ( ( V_95 == V_110 ) &&
( V_94 -> V_103 . V_104 . V_111 == 0 ||
V_94 -> V_103 . V_104 . V_111 == V_112 ) ) {
memset ( ( void * ) V_94 , 0 , sizeof ( T_6 ) ) ;
F_30 ( V_18 , V_94 , V_18 -> V_113 ,
V_18 -> V_114 ) ;
V_95 = F_29 ( V_18 , V_94 ,
V_18 -> V_115 * 2 ) ;
if ( ( V_95 == V_110 ) &&
( V_94 -> V_103 . V_104 . V_111 == V_116 ) )
F_31 ( V_18 , V_117 , V_118 | V_119 ,
L_30
L_31 ) ;
}
F_32 ( V_18 ) ;
if ( V_95 != V_120 )
F_33 ( V_94 , V_18 -> V_100 ) ;
if ( V_95 == V_96 )
return - V_121 ;
return 0 ;
}
static int
F_34 ( struct V_17 * V_18 , T_2 type )
{
struct V_122 V_123 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
int V_87 = 0 ;
int V_128 = 0 ;
int V_3 ;
int V_129 ;
F_35 ( & V_123 ) ;
V_129 = F_36 ( V_18 , & V_87 , & V_123 ,
V_130 ) ;
if ( V_129 == 0 )
return - V_102 ;
F_37 ( & V_123 ) ;
if ( V_87 != 0 )
return - V_121 ;
V_127 = & V_18 -> V_33 ;
for ( V_3 = 0 ; V_3 < V_127 -> V_131 ; V_3 ++ ) {
V_125 = & V_127 -> V_132 [ V_3 ] ;
while ( ! F_38 ( & V_125 -> V_133 ) ) {
F_39 ( 10 ) ;
if ( V_128 ++ > 500 ) {
F_31 ( V_18 ,
V_134 , V_135 ,
L_32
L_33 ) ;
break;
}
}
}
F_35 ( & V_123 ) ;
V_129 = F_36 ( V_18 , & V_87 , & V_123 , type ) ;
if ( V_129 == 0 )
return - V_102 ;
F_37 ( & V_123 ) ;
if ( V_87 != 0 )
return - V_121 ;
return 0 ;
}
int
F_40 ( struct V_17 * V_18 )
{
struct V_122 V_123 ;
int V_87 = 0 ;
int V_129 ;
if ( ! V_18 -> V_136 )
return - V_137 ;
if ( ! ( V_18 -> V_138 -> V_76 & V_97 ) ) {
V_87 = F_34 ( V_18 , V_139 ) ;
if ( V_87 != 0 )
return V_87 ;
}
F_35 ( & V_123 ) ;
V_129 = F_36 ( V_18 , & V_87 , & V_123 ,
V_140 ) ;
if ( V_129 == 0 )
return - V_102 ;
F_37 ( & V_123 ) ;
if ( V_87 != 0 )
return - V_121 ;
return 0 ;
}
static T_1
F_41 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_87 = - V_88 ;
if ( ! V_18 -> V_136 )
return - V_137 ;
if ( strncmp ( V_9 , L_34 , sizeof( L_34 ) - 1 ) == 0 )
V_87 = V_18 -> F_40 ( V_18 ) ;
if ( V_87 == 0 )
return strlen ( V_9 ) ;
else
return V_87 ;
}
int
F_42 ( struct V_17 * V_18 )
{
struct V_141 V_142 = { 0 } ;
int V_3 ;
F_39 ( 100 ) ;
F_43 ( V_18 -> V_42 . V_103 . V_143 . V_144 ,
& V_142 . V_145 ) ;
if ( ! F_44 ( V_146 , & V_142 ) &&
! F_44 ( V_147 , & V_142 ) )
return - V_99 ;
for ( V_3 = 0 ; V_3 < V_148 ; V_3 ++ ) {
F_39 ( 10 ) ;
F_43 ( V_18 -> V_42 . V_103 . V_143 . V_144 ,
& V_142 . V_145 ) ;
if ( ! F_44 ( V_147 , & V_142 ) )
continue;
if ( ! F_44 ( V_146 , & V_142 ) )
continue;
if ( ! F_44 ( V_149 , & V_142 ) )
continue;
break;
}
if ( V_3 < V_148 )
return 0 ;
else
return - V_121 ;
}
static T_1
F_45 ( struct V_17 * V_18 , T_2 V_150 )
{
struct V_122 V_123 ;
struct V_151 * V_152 = V_18 -> V_153 ;
T_2 V_154 ;
T_2 V_155 ;
T_2 V_156 ;
int V_87 = 0 , V_129 = 0 ;
int V_157 = 1 , V_158 ;
if ( ! V_18 -> V_136 )
return - V_137 ;
if ( ( V_18 -> V_44 < V_45 ) ||
( F_44 ( V_159 , & V_18 -> V_42 . V_160 ) !=
V_161 ) )
return - V_99 ;
V_154 = V_18 -> V_138 -> V_76 ;
V_155 = V_18 -> V_162 ;
if ( V_18 -> V_162 ) {
F_46 ( V_152 ) ;
V_18 -> V_162 = 0 ;
}
if ( V_150 == V_163 )
V_18 -> V_19 |= V_164 ;
V_87 = F_34 ( V_18 , V_139 ) ;
if ( V_87 != 0 ) {
V_18 -> V_19 &= ~ V_164 ;
return V_87 ;
}
F_39 ( 100 ) ;
V_156 = F_47 ( V_18 -> V_42 . V_165 +
V_166 ) ;
if ( V_150 == V_163 )
V_156 |= V_167 ;
else if ( V_150 == V_168 )
V_156 |= V_169 ;
else if ( V_150 == V_170 )
V_156 |= V_171 ;
F_48 ( V_156 , V_18 -> V_42 . V_165 +
V_166 ) ;
F_47 ( V_18 -> V_42 . V_165 + V_166 ) ;
V_129 = F_42 ( V_18 ) ;
if ( V_129 == - V_99 ) {
F_31 ( V_18 , V_117 , V_119 ,
L_35
L_36 , V_156 ) ;
} else if ( V_129 == - V_121 ) {
F_31 ( V_18 , V_117 , V_119 ,
L_37
L_36 , V_156 ) ;
return V_129 ;
}
if ( V_154 & V_97 )
goto V_172;
F_35 ( & V_123 ) ;
V_157 = F_36 ( V_18 , & V_87 , & V_123 ,
V_140 ) ;
if ( ! V_157 )
goto V_172;
F_37 ( & V_123 ) ;
V_172:
if ( V_155 ) {
V_158 =
F_49 ( V_18 , V_155 ) ;
if ( ! V_158 )
V_18 -> V_162 = V_155 ;
}
if ( ! V_129 ) {
if ( ! V_157 )
V_129 = - V_102 ;
else if ( V_87 )
V_129 = - V_121 ;
}
return V_129 ;
}
static T_1
F_50 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_173 ) ;
}
static T_1
F_51 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char * V_174 ;
if ( V_18 -> V_51 == V_57 )
V_174 = L_38 ;
else if ( V_18 -> V_51 == V_53 )
V_174 = L_39 ;
else if ( V_18 -> V_51 == V_54 )
V_174 = L_40 ;
else
V_174 = L_41 ;
return snprintf ( V_9 , V_10 , L_8 , V_174 ) ;
}
static T_1
F_52 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_122 V_123 ;
char * V_175 = NULL ;
int V_87 = 0 ;
int V_129 ;
if ( ! V_18 -> V_136 ) {
V_87 = - V_137 ;
goto V_176;
}
F_53 ( V_15 , V_117 , V_135 ,
L_42 , V_9 ) ;
F_35 ( & V_123 ) ;
if( strncmp ( V_9 , L_41 , sizeof( L_41 ) - 1 ) == 0 ) {
V_129 = F_36 ( V_18 , & V_87 , & V_123 ,
V_140 ) ;
if ( V_129 == 0 ) {
V_87 = - V_102 ;
goto V_176;
}
F_37 ( & V_123 ) ;
} else if ( strncmp ( V_9 , L_40 , sizeof( L_40 ) - 1 ) == 0 )
V_87 = F_34 ( V_18 , V_139 ) ;
else if ( strncmp ( V_9 , L_43 , sizeof( L_43 ) - 1 ) == 0 )
if ( V_18 -> V_44 == V_45 )
V_87 = - V_88 ;
else
V_87 = F_34 ( V_18 , V_177 ) ;
else if ( strncmp ( V_9 , L_38 , sizeof( L_38 ) - 1 ) == 0 )
if ( V_18 -> V_44 == V_45 )
V_87 = - V_88 ;
else
V_87 = F_34 ( V_18 , V_178 ) ;
else if ( strncmp ( V_9 , L_44 , sizeof( L_44 ) - 1 ) == 0 )
V_87 = F_45 ( V_18 , V_163 ) ;
else if ( strncmp ( V_9 , L_45 , sizeof( L_45 ) - 1 ) == 0 )
V_87 = F_45 ( V_18 , V_168 ) ;
else if ( strncmp ( V_9 , L_46 , sizeof( L_46 ) - 1 ) == 0 )
V_87 = F_45 ( V_18 , V_170 ) ;
else
V_87 = - V_88 ;
V_176:
if ( ! V_87 )
return strlen ( V_9 ) ;
else {
V_175 = strchr ( V_9 , '\n' ) ;
if ( V_175 )
* V_175 = '\0' ;
F_53 ( V_15 , V_117 , V_135 ,
L_47
L_48 ,
V_9 , V_87 , V_18 -> V_138 -> V_76 ) ;
return V_87 ;
}
}
static int
F_54 ( struct V_17 * V_18 ,
T_2 * V_179 , T_2 * V_180 ,
T_2 * V_181 , T_2 * V_182 ,
T_2 * V_183 , T_2 * V_184 )
{
struct V_185 * V_186 ;
T_6 * V_94 ;
T_7 * V_187 ;
int V_129 = 0 ;
T_2 V_188 ;
if ( V_18 -> V_51 < V_56 ||
! V_18 -> V_100 ||
( V_18 -> V_33 . V_34 & V_189 ) == 0 )
return 0 ;
if ( V_18 -> V_33 . V_34 & V_98 )
return 0 ;
V_94 = F_28 ( V_18 -> V_100 , V_101 ) ;
if ( ! V_94 )
return 0 ;
memset ( V_94 , 0 , sizeof ( T_6 ) ) ;
V_187 = & V_94 -> V_103 . V_104 ;
V_187 -> V_105 = V_190 ;
V_187 -> V_107 = V_108 ;
V_94 -> V_191 = NULL ;
if ( V_18 -> V_138 -> V_76 & V_97 )
V_129 = V_192 ;
else
V_129 = F_29 ( V_18 , V_94 , V_18 -> V_115 * 2 ) ;
if ( V_129 != V_110 ) {
if ( V_129 != V_120 )
F_33 ( V_94 , V_18 -> V_100 ) ;
return 0 ;
}
if ( V_18 -> V_44 == V_45 ) {
V_186 = & V_94 -> V_103 . V_193 . V_194 . V_186 ;
if ( V_181 )
* V_181 = F_44 ( V_195 , V_186 ) ;
if ( V_182 )
* V_182 = F_44 ( V_195 , V_186 ) -
V_18 -> V_42 . V_196 . V_197 ;
if ( V_179 )
* V_179 = F_44 ( V_198 , V_186 ) ;
if ( V_180 )
* V_180 = F_44 ( V_198 , V_186 ) -
V_18 -> V_42 . V_196 . V_199 ;
V_188 = ( F_44 ( V_200 , V_186 ) > 0 ) ?
( F_44 ( V_200 , V_186 ) - 1 ) : 0 ;
if ( V_183 )
* V_183 = V_188 ;
if ( V_184 )
* V_184 = V_188 - V_18 -> V_42 . V_196 . V_201 ;
} else {
if ( V_181 )
* V_181 = V_187 -> V_194 . V_202 . V_203 ;
if ( V_182 )
* V_182 = V_187 -> V_194 . V_202 . V_204 ;
if ( V_179 )
* V_179 = V_187 -> V_194 . V_202 . V_205 ;
if ( V_180 )
* V_180 = V_187 -> V_194 . V_202 . V_206 ;
if ( V_183 )
* V_183 = V_187 -> V_194 . V_202 . V_188 ;
if ( V_184 )
* V_184 = V_187 -> V_194 . V_202 . V_207 ;
}
F_33 ( V_94 , V_18 -> V_100 ) ;
return 1 ;
}
static T_1
F_55 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_128 ;
if ( F_54 ( V_18 , NULL , NULL , & V_128 , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_128 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_56 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_128 , V_208 ;
if ( F_54 ( V_18 , NULL , NULL , & V_128 , & V_208 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_128 - V_208 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_57 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_128 ;
if ( F_54 ( V_18 , & V_128 , NULL , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_128 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_58 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_128 , V_208 ;
if ( F_54 ( V_18 , & V_128 , & V_208 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_128 - V_208 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_59 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_128 ;
if ( F_54 ( V_18 , NULL , NULL , NULL , NULL , & V_128 , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , V_128 ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_60 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_128 , V_208 ;
if ( F_54 ( V_18 , NULL , NULL , NULL , NULL , & V_128 , & V_208 ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_128 - V_208 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_61 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_188 ) )
return snprintf ( V_9 , V_10 , L_49 ) ;
if ( V_15 -> V_209 == V_210 )
return snprintf ( V_9 , V_10 , L_50 ) ;
return snprintf ( V_9 , V_10 , L_51 , V_15 -> V_211 ) ;
}
static T_1
F_62 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_52 , V_18 -> V_212 ) ;
}
static T_1
F_63 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_213 ;
T_2 V_214 ;
int V_215 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_215 ) != 1 )
return - V_88 ;
if ( ( V_215 & 0x3 ) != V_215 )
return - V_88 ;
if ( V_18 -> V_44 == V_45 )
V_215 = 0 ;
F_53 ( V_15 , V_117 , V_135 ,
L_54 ,
V_18 -> V_212 , V_215 ) ;
F_64 ( & V_18 -> V_216 ) ;
V_214 = V_18 -> V_212 ;
if ( V_215 & V_217 ) {
if ( ( V_215 & V_218 ) &&
! ( V_214 & V_218 ) ) {
if ( F_43 ( V_18 -> V_219 , & V_213 ) ) {
F_65 ( & V_18 -> V_216 ) ;
return - V_88 ;
}
V_213 &= ~ ( V_220 << V_221 ) ;
F_48 ( V_213 , V_18 -> V_219 ) ;
F_47 ( V_18 -> V_219 ) ;
F_66 ( V_18 ) ;
}
} else if ( V_215 != 0x0 ) {
F_65 ( & V_18 -> V_216 ) ;
return - V_88 ;
}
if ( ! ( V_215 & V_218 ) &&
( V_214 & V_218 ) )
{
F_65 ( & V_18 -> V_216 ) ;
F_67 ( & V_18 -> V_222 ) ;
F_64 ( & V_18 -> V_216 ) ;
if ( F_43 ( V_18 -> V_219 , & V_213 ) ) {
F_65 ( & V_18 -> V_216 ) ;
return - V_88 ;
}
V_213 |= ( V_220 << V_221 ) ;
F_48 ( V_213 , V_18 -> V_219 ) ;
F_47 ( V_18 -> V_219 ) ;
}
V_18 -> V_212 = V_215 ;
F_65 ( & V_18 -> V_216 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_68 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_223 ) ;
}
static T_1
F_69 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_224 ) ;
}
static T_1
F_70 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_55 ,
( V_18 -> V_225 ) ? L_56 : L_57 ,
( V_18 -> V_22 & V_226 ) ?
L_58 : L_59 ) ;
}
static T_1
F_71 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_8 V_227 ;
V_227 = F_72 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_9 , V_227 ) ;
}
static T_5
F_73 ( const char * V_9 , T_5 V_128 , char V_228 [] )
{
unsigned int V_3 , V_4 ;
if ( V_9 [ V_128 - 1 ] == '\n' )
V_128 -- ;
if ( ( V_128 < 16 ) || ( V_128 > 18 ) || ( ( V_128 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_128 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_88 ;
memset ( V_228 , 0 , V_229 ) ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( ( * V_9 >= 'a' ) && ( * V_9 <= 'f' ) )
V_4 = ( ( V_4 << 4 ) | ( ( * V_9 ++ - 'a' ) + 10 ) ) ;
else if ( ( * V_9 >= 'A' ) && ( * V_9 <= 'F' ) )
V_4 = ( ( V_4 << 4 ) | ( ( * V_9 ++ - 'A' ) + 10 ) ) ;
else if ( ( * V_9 >= '0' ) && ( * V_9 <= '9' ) )
V_4 = ( ( V_4 << 4 ) | ( * V_9 ++ - '0' ) ) ;
else
return - V_88 ;
if ( V_3 % 2 ) {
V_228 [ V_3 / 2 ] = V_4 & 0xff ;
V_4 = 0 ;
}
}
return 0 ;
}
static T_1
F_74 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
unsigned int V_128 = V_86 ;
if ( V_9 [ V_128 - 1 ] == '\n' )
V_128 -- ;
if ( ( V_128 != strlen ( V_230 ) ) ||
( strncmp ( V_9 , V_230 , strlen ( V_230 ) ) != 0 ) )
return - V_88 ;
V_18 -> V_231 = 1 ;
return V_86 ;
}
static T_1
F_75 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_60 ,
( unsigned long long ) V_18 -> V_232 ) ;
}
static T_1
F_76 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_122 V_123 ;
int V_233 = 0 , V_234 = 0 ;
unsigned int V_128 = V_86 ;
T_9 V_235 [ V_229 ] ;
int V_129 ;
if ( ! V_18 -> V_136 )
return - V_137 ;
F_64 ( & V_18 -> V_216 ) ;
if ( V_18 -> V_236 == V_237 ) {
F_65 ( & V_18 -> V_216 ) ;
return - V_137 ;
}
F_65 ( & V_18 -> V_216 ) ;
if ( V_9 [ V_128 - 1 ] == '\n' )
V_128 -- ;
if ( ! V_18 -> V_231 )
return - V_88 ;
V_18 -> V_231 = 0 ;
V_129 = F_73 ( V_9 , V_128 , V_235 ) ;
if ( ! V_129 ) {
V_18 -> V_231 = 1 ;
return V_129 ;
}
V_18 -> V_232 = F_77 ( V_235 ) ;
F_78 ( V_13 ) = V_18 -> V_232 ;
if ( V_18 -> V_238 )
F_79 ( V_13 ) = V_18 -> V_238 ;
F_80 ( V_239 , & V_18 -> V_153 -> V_6 ,
L_61 , V_18 -> V_240 ) ;
V_233 = F_34 ( V_18 , V_139 ) ;
if ( V_233 )
F_31 ( V_18 , V_117 , V_135 ,
L_62
L_63 , V_233 ) ;
F_35 ( & V_123 ) ;
V_129 = F_36 ( V_18 , & V_234 , & V_123 ,
V_140 ) ;
if ( V_129 == 0 )
return - V_102 ;
F_37 ( & V_123 ) ;
if ( V_234 )
F_31 ( V_18 , V_117 , V_135 ,
L_64
L_63 , V_234 ) ;
return ( V_233 || V_234 ) ? - V_121 : V_86 ;
}
static T_1
F_81 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_60 ,
( unsigned long long ) V_18 -> V_238 ) ;
}
static T_1
F_82 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_128 = V_86 ;
T_9 V_241 [ V_229 ] ;
int V_129 ;
if ( V_9 [ V_128 - 1 ] == '\n' )
V_128 -- ;
if ( ! V_18 -> V_231 )
return - V_88 ;
V_129 = F_73 ( V_9 , V_128 , V_241 ) ;
if ( ! V_129 ) {
return V_129 ;
}
V_18 -> V_238 = F_77 ( V_241 ) ;
F_80 ( V_239 , & V_18 -> V_153 -> V_6 ,
L_65
L_66 , V_18 -> V_240 ) ;
return V_86 ;
}
static T_1
F_83 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_60 ,
F_77 ( V_18 -> V_242 ) ) ;
}
static T_1
F_84 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_128 = V_86 ;
T_3 V_235 [ V_229 ] ;
int V_129 ;
if ( ! V_18 -> V_243 )
return - V_99 ;
if ( V_9 [ V_128 - 1 ] == '\n' )
V_128 -- ;
V_129 = F_73 ( V_9 , V_128 , V_235 ) ;
if ( V_129 )
return V_129 ;
memcpy ( V_18 -> V_242 , V_235 , ( 8 * sizeof( T_3 ) ) ) ;
memcpy ( V_18 -> V_42 . V_244 , V_235 , ( 8 * sizeof( T_3 ) ) ) ;
if ( F_77 ( V_235 ) == 0 )
V_18 -> V_245 |= V_246 ;
else
V_18 -> V_245 &= ~ V_246 ;
V_18 -> V_245 &= ~ V_247 ;
V_18 -> V_42 . V_248 = V_249 ;
return V_86 ;
}
static T_1
F_85 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_60 ,
F_77 ( V_18 -> V_250 ) ) ;
}
static T_1
F_86 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_128 = V_86 ;
T_3 V_235 [ V_229 ] ;
int V_129 ;
if ( ! V_18 -> V_243 )
return - V_99 ;
if ( V_9 [ V_128 - 1 ] == '\n' )
V_128 -- ;
V_129 = F_73 ( V_9 , V_128 , V_235 ) ;
if ( V_129 )
return V_129 ;
memcpy ( V_18 -> V_250 , V_235 , ( 8 * sizeof( T_3 ) ) ) ;
memcpy ( V_18 -> V_42 . V_251 , V_235 , ( 8 * sizeof( T_3 ) ) ) ;
if ( F_77 ( V_235 ) == 0 )
V_18 -> V_245 |= V_252 ;
else
V_18 -> V_245 &= ~ V_252 ;
V_18 -> V_245 &= ~ V_247 ;
V_18 -> V_42 . V_248 = V_249 ;
return V_86 ;
}
static T_1
F_87 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_253 ) ;
}
static T_1
F_88 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
int V_215 = 0 ;
if ( ! V_18 -> V_243 )
return - V_99 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_215 ) != 1 )
return - V_88 ;
if ( ( V_215 != 0 ) && ( V_215 != 1 ) )
return - V_88 ;
V_18 -> V_253 = V_215 ;
return strlen ( V_9 ) ;
}
static T_1
F_89 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
if ( ! ( V_18 -> V_245 & V_247 ) )
return - V_254 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_255 ) ;
}
static T_5
F_90 ( struct V_17 * V_18 , T_3 V_256 [] ,
T_3 V_257 [] , T_10 V_258 , T_2 V_259 )
{
int V_129 = 0 ;
if ( ! V_18 -> V_243 )
return - V_99 ;
if ( V_259 ) {
if ( ! F_91 ( V_18 , (struct V_260 * ) V_256 ,
(struct V_260 * ) V_257 , V_258 ) )
V_129 = - V_102 ;
} else {
F_92 ( V_18 , (struct V_260 * ) V_256 ,
(struct V_260 * ) V_257 , V_258 ) ;
}
return V_129 ;
}
static T_10
F_93 ( struct V_17 * V_18 , T_3 V_256 [] ,
T_3 V_257 [] , T_2 * V_261 )
{
T_10 V_262 ;
if ( F_94 ( ! V_18 ) || ! V_256 || ! V_257 )
return V_263 ;
if ( F_95 ( V_18 , (struct V_260 * )
V_18 -> V_42 . V_251 ,
(struct V_260 * )
V_18 -> V_42 . V_244 ,
& V_18 -> V_42 . V_248 ,
(struct V_260 * ) V_256 ,
(struct V_260 * ) V_257 ,
& V_262 , V_261 ) )
return V_262 ;
else
return V_263 ;
}
static T_1
F_96 ( struct V_17 * V_18 , T_3 V_256 [] ,
T_3 V_257 [] , T_10 V_258 ,
T_2 V_259 )
{
int V_129 ;
V_129 = F_90 ( V_18 , V_256 , V_257 , V_258 ,
V_259 ) ;
return V_129 ;
}
static T_1
F_97 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_10 V_264 ;
int V_41 = 0 ;
if ( ! V_18 -> V_243 )
return - V_99 ;
if ( F_77 ( V_18 -> V_250 ) == 0 )
if ( ! ( V_18 -> V_245 & V_252 ) )
return - V_254 ;
if ( F_77 ( V_18 -> V_242 ) == 0 )
if ( ! ( V_18 -> V_245 & V_246 ) )
return - V_254 ;
V_264 = F_93 ( V_18 , V_18 -> V_250 ,
V_18 -> V_242 ,
& V_18 -> V_255 ) ;
if ( V_264 != V_263 )
V_18 -> V_245 |= V_247 ;
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 , L_67 , V_264 ) ;
return V_41 ;
}
static T_1
F_98 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_10 V_265 ;
T_1 V_129 ;
if ( ! V_18 -> V_243 )
return - V_99 ;
if ( F_77 ( V_18 -> V_250 ) == 0 )
return - V_254 ;
if ( F_77 ( V_18 -> V_242 ) == 0 )
return - V_254 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_67 , & V_265 ) != 1 )
return - V_88 ;
F_31 ( V_18 , V_266 , V_135 ,
L_68
L_69 ,
F_77 ( V_18 -> V_250 ) ,
F_77 ( V_18 -> V_242 ) , V_265 ,
V_18 -> V_253 ) ;
V_129 = F_96 ( V_18 , V_18 -> V_250 ,
V_18 -> V_242 , V_265 ,
V_18 -> V_253 ) ;
if ( V_129 )
return V_129 ;
return V_86 ;
}
static T_1
F_99 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_267 ) ;
}
static T_1
F_100 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_132 [ V_268 ] . V_269 ) ;
}
static T_1
F_101 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_132 [ V_268 ] . V_270 ) ;
}
static T_1
F_102 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 , V_15 -> V_271 ) ;
}
static int
F_103 ( struct V_14 * V_15 , int V_215 )
{
if ( V_15 -> V_271 != V_272 ) {
V_15 -> V_273 = V_15 -> V_271 ;
if ( V_215 != V_272 )
F_53 ( V_15 , V_117 , V_135 ,
L_70
L_71
L_72 ) ;
return 0 ;
}
if ( V_215 >= V_274 && V_215 <= V_275 ) {
V_15 -> V_273 = V_215 ;
V_15 -> V_271 = V_215 ;
return 0 ;
}
F_53 ( V_15 , V_117 , V_135 ,
L_73
L_74 ,
V_215 , V_274 , V_275 ) ;
V_15 -> V_273 = V_272 ;
return - V_88 ;
}
static void
F_104 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_276 * V_277 ;
V_13 = F_105 ( V_15 ) ;
F_64 ( V_13 -> V_278 ) ;
F_106 (ndlp, &vport->fc_nodes, nlp_listp)
if ( F_107 ( V_277 ) && V_277 -> V_279 )
V_277 -> V_279 -> V_280 = V_15 -> V_271 ;
F_65 ( V_13 -> V_278 ) ;
}
static int
F_108 ( struct V_14 * V_15 , int V_215 )
{
if ( V_15 -> V_281 ||
( V_282 != V_272 ) ) {
F_53 ( V_15 , V_117 , V_135 ,
L_75
L_76 ) ;
return 0 ;
}
if ( V_215 >= V_274 && V_215 <= V_275 ) {
V_15 -> V_273 = V_215 ;
V_15 -> V_271 = V_215 ;
F_109 ( F_105 ( V_15 ) ) = V_215 ;
F_104 ( V_15 ) ;
return 0 ;
}
F_53 ( V_15 , V_117 , V_135 ,
L_77
L_78 ,
V_215 , V_274 , V_275 ) ;
return - V_88 ;
}
static int
F_110 ( struct V_14 * V_15 , int V_215 )
{
if ( V_215 >= V_274 && V_215 <= V_275 ) {
V_15 -> V_273 = V_215 ;
V_15 -> V_271 = V_215 ;
V_15 -> V_281 = 1 ;
F_109 ( F_105 ( V_15 ) ) = V_215 ;
F_104 ( V_15 ) ;
return 0 ;
}
F_53 ( V_15 , V_117 , V_135 ,
L_79
L_74 ,
V_215 , V_274 , V_275 ) ;
return - V_88 ;
}
static int
F_111 ( struct V_14 * V_15 , int V_215 )
{
if ( V_215 < 0 || V_215 > 1 ) {
F_53 ( V_15 , V_117 , V_135 ,
L_80
L_81 ,
V_215 ) ;
V_15 -> V_283 = 1 ;
return - V_88 ;
}
if ( V_15 -> V_209 == V_210 ) {
V_15 -> V_283 = 0 ;
return 0 ;
}
V_15 -> V_283 = V_215 ;
return 0 ;
}
static int
F_112 ( struct V_14 * V_15 , int V_215 )
{
if ( V_215 < 0 || V_215 > 1 ) {
F_53 ( V_15 , V_117 , V_135 ,
L_82
L_81 ,
V_215 ) ;
V_15 -> V_283 = 1 ;
return - V_88 ;
}
if ( V_15 -> V_209 == V_210 && V_215 != 0 ) {
F_53 ( V_15 , V_117 , V_135 ,
L_83
L_84 ) ;
V_15 -> V_283 = 0 ;
return 0 ;
}
V_15 -> V_283 = V_215 ;
return 0 ;
}
static T_1
F_113 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_215 = 0 ;
int V_284 = 0 ;
const char * V_285 = V_9 ;
int V_286 ;
T_2 V_287 ;
if ( ! strncmp ( V_9 , L_85 , strlen ( L_85 ) ) ) {
V_284 = 1 ;
V_285 = & V_9 [ strlen ( L_85 ) ] ;
}
if ( ! isdigit ( V_285 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_285 , L_53 , & V_215 ) != 1 )
return - V_88 ;
if ( V_215 >= 0 && V_215 <= 6 ) {
V_287 = V_18 -> V_113 ;
if ( V_18 -> V_114 == V_288 &&
V_215 == 4 ) {
F_53 ( V_15 , V_117 , V_135 ,
L_86 ,
V_215 ) ;
return - V_88 ;
}
if ( V_18 -> V_153 -> V_5 == V_289 &&
V_215 == 4 ) {
F_53 ( V_15 , V_117 , V_135 ,
L_87 ) ;
return - V_88 ;
}
V_18 -> V_113 = V_215 ;
if ( V_284 )
return strlen ( V_9 ) ;
F_53 ( V_15 , V_117 , V_135 ,
L_88 ,
V_287 , V_215 ) ;
if ( V_287 != V_215 && V_18 -> V_44 == V_45 )
V_18 -> V_290 = 1 ;
V_286 = F_27 ( F_105 ( V_18 -> V_138 ) ) ;
if ( V_286 ) {
V_18 -> V_113 = V_287 ;
return - V_88 ;
} else
return strlen ( V_9 ) ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_89
L_90 ,
V_18 -> V_240 , V_215 ) ;
return - V_88 ;
}
static T_1
F_114 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_291 & V_292 )
sprintf ( V_9 , L_2 ) ;
else
sprintf ( V_9 , L_3 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_115 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
#define F_116 1024
static char V_293 [ F_116 ] ;
unsigned long V_3 ;
char * V_294 , * V_295 ;
struct V_14 * * V_296 ;
struct V_12 * V_297 ;
char * V_298 , * V_299 , * V_300 ;
unsigned long V_301 , V_302 , V_303 ;
if ( ! strncmp ( V_9 , L_91 , strlen ( L_91 ) ) ) {
if ( strlen ( V_9 ) > ( F_116 - 1 ) )
return - V_88 ;
strncpy ( V_293 , V_9 , F_116 ) ;
V_294 = & V_293 [ 0 ] ;
V_295 = F_117 ( & V_294 , L_92 ) ;
if ( ! V_295 )
return - V_88 ;
V_298 = F_117 ( & V_294 , L_92 ) ;
if ( ! V_298 )
return - V_88 ;
if ( ! strncmp ( V_298 , L_93 , strlen ( L_93 ) ) )
V_303 = V_304 ;
else if ( ! strncmp ( V_298 , L_94 , strlen ( L_94 ) ) )
V_303 = V_305 ;
else
return - V_88 ;
V_299 = F_117 ( & V_294 , L_92 ) ;
if ( ! V_299 )
return - V_88 ;
V_301 = F_118 ( V_299 , NULL , 0 ) ;
V_300 = F_117 ( & V_294 , L_92 ) ;
if ( ! V_300 )
return - V_88 ;
V_302 = F_118 ( V_300 , NULL , 0 ) ;
if ( ! V_302 )
return - V_88 ;
V_296 = F_119 ( V_18 ) ;
if ( V_296 == NULL )
return - V_102 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_306 && V_296 [ V_3 ] != NULL ; V_3 ++ ) {
V_297 = F_105 ( V_296 [ V_3 ] ) ;
F_64 ( V_297 -> V_278 ) ;
V_296 [ V_3 ] -> V_307 = 1 ;
if ( V_296 [ V_3 ] -> V_308 )
F_120 ( V_296 [ V_3 ] ) ;
F_65 ( V_297 -> V_278 ) ;
}
V_18 -> V_303 = V_303 ;
V_18 -> V_309 = V_301 ;
V_18 -> V_310 = V_302 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_306 && V_296 [ V_3 ] != NULL ; V_3 ++ ) {
V_297 = F_105 ( V_296 [ V_3 ] ) ;
F_64 ( V_297 -> V_278 ) ;
V_296 [ V_3 ] -> V_307 = 0 ;
F_65 ( V_297 -> V_278 ) ;
}
F_121 ( V_18 , V_296 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_95 , strlen ( L_95 ) ) ) {
V_296 = F_119 ( V_18 ) ;
if ( V_296 == NULL )
return - V_102 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_306 && V_296 [ V_3 ] != NULL ; V_3 ++ ) {
V_297 = F_105 ( V_296 [ V_3 ] ) ;
F_64 ( V_13 -> V_278 ) ;
V_296 [ V_3 ] -> V_307 = 1 ;
F_122 ( V_15 ) ;
V_15 -> V_308 = 0 ;
V_296 [ V_3 ] -> V_307 = 0 ;
F_65 ( V_13 -> V_278 ) ;
}
F_121 ( V_18 , V_296 ) ;
V_18 -> V_303 = V_311 ;
V_18 -> V_309 = 0 ;
V_18 -> V_310 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_96 , strlen ( L_96 ) ) ) {
if ( V_18 -> V_303 == V_311 )
return - V_88 ;
F_64 ( V_13 -> V_278 ) ;
if ( V_15 -> V_308 ) {
F_65 ( V_13 -> V_278 ) ;
return strlen ( V_9 ) ;
}
F_123 ( V_15 ) ;
V_15 -> V_308 = 1 ;
F_65 ( V_13 -> V_278 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_97 , strlen ( L_97 ) ) ) {
F_64 ( V_13 -> V_278 ) ;
if ( V_15 -> V_308 == 0 ) {
F_65 ( V_13 -> V_278 ) ;
return strlen ( V_9 ) ;
}
F_122 ( V_15 ) ;
V_15 -> V_308 = 0 ;
F_65 ( V_13 -> V_278 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_98 , strlen ( L_98 ) ) ) {
if ( ( V_18 -> V_303 == V_311 )
|| ! V_15 -> V_308 )
return strlen ( V_9 ) ;
F_64 ( V_13 -> V_278 ) ;
V_15 -> V_307 = 1 ;
F_120 ( V_15 ) ;
V_15 -> V_307 = 0 ;
F_65 ( V_13 -> V_278 ) ;
return strlen ( V_9 ) ;
}
return - V_88 ;
}
static T_1
F_124 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_312 = 0 ;
int V_3 ;
char * V_303 ;
unsigned long V_313 ;
switch ( V_18 -> V_303 ) {
case V_304 :
V_303 = L_93 ;
break;
case V_305 :
V_303 = L_94 ;
break;
default:
V_303 = L_99 ;
break;
}
sprintf ( & V_9 [ V_312 ] , L_100
L_101
L_102 ,
V_15 -> V_308 , V_15 -> V_307 ,
V_303 , V_18 -> V_309 , V_18 -> V_310 ) ;
V_312 = strlen ( V_9 ) ;
if ( V_18 -> V_303 != V_311 ) {
for ( V_3 = 0 ; V_3 < V_314 ; V_3 ++ ) {
if ( V_18 -> V_303 == V_304 )
V_313 = V_18 -> V_309 +
V_18 -> V_310 * V_3 ;
else
V_313 = V_18 -> V_309 +
( 1 << V_3 ) * V_18 -> V_310 ;
if ( V_312 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_312 ] , L_103 , V_313 ) ;
V_312 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_312 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_125 ( struct V_315 * V_316 , struct V_317 * V_318 ,
struct V_319 * V_320 ,
char * V_9 , T_11 V_321 , T_5 V_86 )
{
struct V_5 * V_6 = F_126 ( V_318 , struct V_5 ,
V_318 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_312 = 0 ;
unsigned long V_322 ;
struct V_276 * V_277 = NULL ;
V_322 = ( unsigned long ) V_321 /
V_323 ;
if ( ! V_15 -> V_308 || V_15 -> V_307
|| ( V_18 -> V_303 == V_311 ) )
return 0 ;
F_64 ( V_13 -> V_278 ) ;
F_106 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_107 ( V_277 ) || ! V_277 -> V_324 )
continue;
if ( V_322 > 0 ) {
V_322 -- ;
continue;
}
if ( ( V_312 + V_323 )
> V_86 )
break;
if ( ! V_277 -> V_324 )
continue;
sprintf ( & V_9 [ V_312 ] , L_104 ,
V_277 -> V_325 . V_103 . V_228 [ 0 ] ,
V_277 -> V_325 . V_103 . V_228 [ 1 ] ,
V_277 -> V_325 . V_103 . V_228 [ 2 ] ,
V_277 -> V_325 . V_103 . V_228 [ 3 ] ,
V_277 -> V_325 . V_103 . V_228 [ 4 ] ,
V_277 -> V_325 . V_103 . V_228 [ 5 ] ,
V_277 -> V_325 . V_103 . V_228 [ 6 ] ,
V_277 -> V_325 . V_103 . V_228 [ 7 ] ) ;
V_312 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_314 ; V_3 ++ ) {
sprintf ( & V_9 [ V_312 ] , L_105 ,
V_277 -> V_324 [ V_3 ] . V_326 ) ;
V_312 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_312 ] , L_1 ) ;
V_312 = strlen ( V_9 ) ;
}
F_65 ( V_13 -> V_278 ) ;
return V_312 ;
}
static T_1
F_127 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_215 = V_327 ;
int V_284 = 0 ;
const char * V_285 = V_9 ;
int V_286 ;
T_2 V_287 ;
if ( ! strncmp ( V_9 , L_85 , strlen ( L_85 ) ) ) {
V_284 = 1 ;
V_285 = & V_9 [ strlen ( L_85 ) ] ;
}
if ( ! isdigit ( V_285 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_285 , L_53 , & V_215 ) != 1 )
return - V_88 ;
F_53 ( V_15 , V_117 , V_135 ,
L_106 ,
V_18 -> V_114 , V_215 , V_284 ? L_107 : L_108 ) ;
if ( ( ( V_215 == V_328 ) && ! ( V_18 -> V_329 & V_330 ) ) ||
( ( V_215 == V_331 ) && ! ( V_18 -> V_329 & V_332 ) ) ||
( ( V_215 == V_333 ) && ! ( V_18 -> V_329 & V_334 ) ) ||
( ( V_215 == V_335 ) && ! ( V_18 -> V_329 & V_336 ) ) ||
( ( V_215 == V_337 ) && ! ( V_18 -> V_329 & V_338 ) ) ||
( ( V_215 == V_288 ) && ! ( V_18 -> V_329 & V_339 ) ) ||
( ( V_215 == V_340 ) && ! ( V_18 -> V_329 & V_341 ) ) ) {
F_31 ( V_18 , V_117 , V_135 ,
L_109
L_110 ,
V_215 ) ;
return - V_88 ;
}
if ( V_215 == V_288 &&
V_18 -> V_74 == V_75 ) {
F_31 ( V_18 , V_117 , V_135 ,
L_111
L_112 ,
V_215 ) ;
return - V_88 ;
}
if ( ( V_215 >= 0 ) && ( V_215 <= V_342 ) &&
( V_343 & ( 1 << V_215 ) ) ) {
V_287 = V_18 -> V_114 ;
V_18 -> V_114 = V_215 ;
if ( V_284 )
return strlen ( V_9 ) ;
V_286 = F_27 ( F_105 ( V_18 -> V_138 ) ) ;
if ( V_286 ) {
V_18 -> V_114 = V_287 ;
return - V_88 ;
} else
return strlen ( V_9 ) ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_113
L_114 V_344 L_115 , V_215 ) ;
return - V_88 ;
}
static int
F_128 ( struct V_17 * V_18 , int V_215 )
{
if ( V_215 == V_288 && V_18 -> V_113 == 4 ) {
F_31 ( V_18 , V_117 , V_135 ,
L_116
L_117 ,
V_215 ) ;
V_18 -> V_113 = 0 ;
}
if ( ( V_215 >= 0 ) && ( V_215 <= V_342 ) &&
( V_343 & ( 1 << V_215 ) ) ) {
V_18 -> V_114 = V_215 ;
return 0 ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_118
L_119
L_120 V_344 L_115 , V_215 ) ;
V_18 -> V_114 = V_327 ;
return - V_88 ;
}
static T_1
F_129 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_215 = 0 , V_129 = - V_88 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_215 ) != 1 )
return - V_88 ;
switch ( V_215 ) {
case 0 :
if ( V_18 -> V_19 & V_345 ) {
V_129 = F_130 ( V_18 -> V_153 ) ;
if ( ! V_129 ) {
F_64 ( & V_18 -> V_216 ) ;
V_18 -> V_19 &= ~ V_345 ;
F_65 ( & V_18 -> V_216 ) ;
V_18 -> V_346 = 0 ;
V_129 = strlen ( V_9 ) ;
} else
V_129 = - V_99 ;
} else {
V_18 -> V_346 = 0 ;
V_129 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_345 ) ) {
V_129 = F_131 ( V_18 -> V_153 ) ;
if ( ! V_129 ) {
F_64 ( & V_18 -> V_216 ) ;
V_18 -> V_19 |= V_345 ;
F_65 ( & V_18 -> V_216 ) ;
V_18 -> V_346 = 1 ;
V_129 = strlen ( V_9 ) ;
} else
V_129 = - V_99 ;
} else {
V_18 -> V_346 = 1 ;
V_129 = strlen ( V_9 ) ;
}
break;
default:
V_129 = - V_88 ;
break;
}
return V_129 ;
}
static int
F_132 ( struct V_17 * V_18 , int V_215 )
{
if ( V_215 == 0 || V_215 == 1 ) {
V_18 -> V_346 = V_215 ;
return 0 ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_121
L_122
L_123 , V_215 ) ;
V_18 -> V_346 = 1 ;
return - V_88 ;
}
static T_1
F_133 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_215 , V_129 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_215 ) != 1 )
return - V_88 ;
if ( V_215 != 1 )
return - V_88 ;
if ( V_18 -> V_19 & V_345 )
V_129 = F_134 ( V_18 -> V_153 ) ;
if ( V_129 == 0 )
return strlen ( V_9 ) ;
else
return - V_99 ;
}
static T_1
F_135 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_151 * V_152 = V_18 -> V_153 ;
int V_215 = 0 , V_129 = - V_88 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_215 ) != 1 )
return - V_88 ;
if ( V_215 < 0 )
return - V_88 ;
if ( V_215 == 0 ) {
if ( V_18 -> V_162 > 0 ) {
F_46 ( V_152 ) ;
V_18 -> V_162 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_162 > 0 ) {
F_31 ( V_18 , V_117 , V_135 ,
L_124
L_125 ,
V_18 -> V_162 ) ;
return - V_347 ;
}
if ( V_215 <= V_348 )
V_18 -> V_162 = V_215 ;
else {
F_31 ( V_18 , V_117 , V_135 ,
L_126
L_127 , V_215 ) ;
return - V_88 ;
}
V_129 = F_49 ( V_18 , V_18 -> V_162 ) ;
if ( V_129 ) {
V_18 -> V_162 = 0 ;
V_129 = - V_99 ;
} else
V_129 = strlen ( V_9 ) ;
return V_129 ;
}
static int
F_136 ( struct V_17 * V_18 , int V_215 )
{
if ( V_215 >= 0 && V_215 <= V_348 ) {
V_18 -> V_162 = V_215 ;
return 0 ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_128
L_127 , V_215 ) ;
return - V_88 ;
}
static T_1
F_137 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_215 = 0 , V_129 = - V_88 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_215 ) != 1 )
return - V_88 ;
if ( V_215 != 1 )
return - V_88 ;
V_129 = F_138 ( V_18 , V_349 ) ;
if ( V_129 )
V_129 = - V_99 ;
else
V_129 = strlen ( V_9 ) ;
return V_129 ;
}
static int
F_139 ( struct V_17 * V_18 , int V_215 )
{
if ( V_215 >= 0 && V_215 <= 1 ) {
V_18 -> V_350 = V_215 ;
return 0 ;
}
return - V_88 ;
}
static T_1
F_140 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_215 = 0 , V_3 ;
if ( V_18 -> V_44 != V_45 )
return - V_88 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_215 ) != 1 )
return - V_88 ;
if ( V_215 < V_351 || V_215 > V_352 )
return - V_88 ;
V_18 -> V_353 = ( T_2 ) V_215 ;
for ( V_3 = 0 ; V_3 < V_18 -> V_354 ; V_3 += V_355 )
F_141 ( V_18 , V_3 ) ;
return strlen ( V_9 ) ;
}
static int
F_142 ( struct V_17 * V_18 , int V_215 )
{
if ( V_18 -> V_44 != V_45 ) {
V_18 -> V_353 = 0 ;
return 0 ;
}
if ( V_215 >= V_351 && V_215 <= V_352 ) {
V_18 -> V_353 = V_215 ;
return 0 ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_129 , V_215 ) ;
V_18 -> V_353 = V_356 ;
return 0 ;
}
static T_1
F_143 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_357 * V_358 ;
int V_41 = 0 ;
if ( ( V_18 -> V_44 != V_45 ) ||
( V_18 -> V_359 != V_360 ) )
return V_41 ;
switch ( V_18 -> V_361 ) {
case 0 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_130 ,
V_18 -> V_361 ) ;
return V_41 ;
case 1 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_131
L_132 ,
V_18 -> V_361 ,
V_18 -> V_42 . V_362 ) ;
break;
case 2 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_133
L_132 ,
V_18 -> V_361 ,
V_18 -> V_42 . V_362 ) ;
break;
}
while ( V_18 -> V_42 . V_363 < V_18 -> V_42 . V_364 ) {
V_358 = & V_18 -> V_42 . V_365 [ V_18 -> V_42 . V_363 ] ;
if ( V_358 -> V_366 == V_367 )
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_134
L_135 ,
V_18 -> V_42 . V_363 ,
V_358 -> V_368 , V_358 -> V_369 ,
V_358 -> V_370 ) ;
else
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_134
L_136 ,
V_18 -> V_42 . V_363 ,
V_358 -> V_368 , V_358 -> V_369 ,
V_358 -> V_370 , V_358 -> V_366 ) ;
V_18 -> V_42 . V_363 ++ ;
if ( V_18 -> V_42 . V_363 <
V_18 -> V_42 . V_364 &&
( V_41 >= ( V_10 - 64 ) ) ) {
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 , L_137 ) ;
break;
}
}
if ( V_18 -> V_42 . V_363 == V_18 -> V_42 . V_364 )
V_18 -> V_42 . V_363 = 0 ;
return V_41 ;
}
static T_1
F_144 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
int V_87 = - V_88 ;
return V_87 ;
}
static int
F_145 ( struct V_17 * V_18 , int V_215 )
{
if ( V_18 -> V_44 != V_45 ) {
V_18 -> V_361 = 0 ;
return 0 ;
}
if ( V_215 >= V_371 && V_215 <= V_372 ) {
V_18 -> V_361 = V_215 ;
return 0 ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_138 ,
V_215 ) ;
V_18 -> V_361 = V_373 ;
return 0 ;
}
static int
F_146 ( struct V_14 * V_15 , int V_215 )
{
struct V_12 * V_13 = F_105 ( V_15 ) ;
struct V_276 * V_277 , * V_374 ;
if ( V_215 == V_15 -> V_375 )
return 0 ;
if ( ( V_215 < 0 ) || ( V_215 > 60000 ) )
return - V_88 ;
V_15 -> V_375 = V_215 ;
F_64 ( V_13 -> V_278 ) ;
F_147 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_107 ( V_277 ) )
continue;
if ( V_277 -> V_376 == V_377 )
continue;
V_277 -> V_378 = V_15 -> V_379 ;
}
F_65 ( V_13 -> V_278 ) ;
return 0 ;
}
static T_1
F_148 ( struct V_315 * V_316 , struct V_317 * V_318 ,
struct V_319 * V_320 ,
char * V_9 , T_11 V_321 , T_5 V_86 )
{
T_5 V_380 ;
struct V_5 * V_6 = F_126 ( V_318 , struct V_5 , V_318 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_44 >= V_45 )
return - V_99 ;
if ( ( V_321 + V_86 ) > V_381 )
return - V_382 ;
if ( V_86 <= V_383 )
return 0 ;
if ( V_321 % 4 || V_86 % 4 || ( unsigned long ) V_9 % 4 )
return - V_88 ;
if ( memcmp ( V_9 , V_384 , V_383 ) )
return - V_88 ;
if ( ! ( V_15 -> V_76 & V_97 ) )
return - V_99 ;
F_64 ( & V_18 -> V_216 ) ;
for ( V_380 = 0 ; V_380 < V_86 - V_383 ;
V_380 += sizeof( T_2 ) )
F_48 ( * ( ( T_2 * ) ( V_9 + V_380 + V_383 ) ) ,
V_18 -> V_385 + V_321 + V_380 ) ;
F_65 ( & V_18 -> V_216 ) ;
return V_86 ;
}
static T_1
F_149 ( struct V_315 * V_316 , struct V_317 * V_318 ,
struct V_319 * V_320 ,
char * V_9 , T_11 V_321 , T_5 V_86 )
{
T_5 V_380 ;
T_2 * V_386 ;
struct V_5 * V_6 = F_126 ( V_318 , struct V_5 , V_318 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_44 >= V_45 )
return - V_99 ;
if ( V_321 > V_381 )
return - V_382 ;
if ( ( V_321 + V_86 ) > V_381 )
V_86 = V_381 - V_321 ;
if ( V_86 == 0 ) return 0 ;
if ( V_321 % 4 || V_86 % 4 || ( unsigned long ) V_9 % 4 )
return - V_88 ;
F_64 ( & V_18 -> V_216 ) ;
for ( V_380 = 0 ; V_380 < V_86 ; V_380 += sizeof( T_2 ) ) {
V_386 = ( T_2 * ) ( V_9 + V_380 ) ;
* V_386 = F_47 ( V_18 -> V_385 + V_321 + V_380 ) ;
}
F_65 ( & V_18 -> V_216 ) ;
return V_86 ;
}
static T_1
F_150 ( struct V_315 * V_316 , struct V_317 * V_318 ,
struct V_319 * V_320 ,
char * V_9 , T_11 V_321 , T_5 V_86 )
{
return - V_99 ;
}
static T_1
F_151 ( struct V_315 * V_316 , struct V_317 * V_318 ,
struct V_319 * V_320 ,
char * V_9 , T_11 V_321 , T_5 V_86 )
{
return - V_99 ;
}
int
F_152 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_105 ( V_15 ) ;
int error ;
error = F_153 ( & V_13 -> V_387 . V_318 ,
& V_388 ) ;
if ( error || V_15 -> V_209 == V_389 )
goto V_172;
error = F_153 ( & V_13 -> V_387 . V_318 ,
& V_390 ) ;
if ( error )
goto V_391;
error = F_153 ( & V_13 -> V_387 . V_318 ,
& V_392 ) ;
if ( error )
goto V_393;
return 0 ;
V_393:
F_154 ( & V_13 -> V_387 . V_318 , & V_390 ) ;
V_391:
F_154 ( & V_13 -> V_387 . V_318 ,
& V_388 ) ;
V_172:
return error ;
}
void
F_155 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_105 ( V_15 ) ;
F_154 ( & V_13 -> V_387 . V_318 ,
& V_388 ) ;
if ( V_15 -> V_209 == V_389 )
return;
F_154 ( & V_13 -> V_387 . V_318 , & V_392 ) ;
F_154 ( & V_13 -> V_387 . V_318 , & V_390 ) ;
}
static void
F_156 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_157 ( V_13 ) = V_15 -> V_394 ;
}
static void
F_158 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_64 ( V_13 -> V_278 ) ;
if ( V_15 -> V_209 == V_389 ) {
F_159 ( V_13 ) = V_395 ;
} else if ( F_160 ( V_18 ) ) {
if ( V_18 -> V_74 == V_75 ) {
if ( V_15 -> V_76 & V_77 )
F_159 ( V_13 ) = V_396 ;
else
F_159 ( V_13 ) = V_397 ;
} else {
if ( V_15 -> V_76 & V_78 )
F_159 ( V_13 ) = V_398 ;
else
F_159 ( V_13 ) = V_399 ;
}
} else
F_159 ( V_13 ) = V_400 ;
F_65 ( V_13 -> V_278 ) ;
}
static void
F_161 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_64 ( V_13 -> V_278 ) ;
if ( V_15 -> V_76 & V_97 )
F_162 ( V_13 ) = V_401 ;
else {
switch ( V_18 -> V_51 ) {
case V_52 :
case V_56 :
F_162 ( V_13 ) = V_402 ;
break;
case V_59 :
case V_60 :
case V_61 :
if ( V_15 -> V_62 < V_71 )
F_162 ( V_13 ) =
V_403 ;
else
F_162 ( V_13 ) =
V_404 ;
break;
case V_57 :
F_162 ( V_13 ) = V_405 ;
break;
default:
F_162 ( V_13 ) = V_406 ;
break;
}
}
F_65 ( V_13 -> V_278 ) ;
}
static void
F_163 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_64 ( V_13 -> V_278 ) ;
if ( ( F_160 ( V_18 ) ) && ( ! ( V_18 -> V_19 & V_407 ) ) ) {
switch( V_18 -> V_408 ) {
case V_409 :
F_164 ( V_13 ) = V_410 ;
break;
case V_411 :
F_164 ( V_13 ) = V_412 ;
break;
case V_413 :
F_164 ( V_13 ) = V_414 ;
break;
case V_415 :
F_164 ( V_13 ) = V_416 ;
break;
case V_417 :
F_164 ( V_13 ) = V_418 ;
break;
case V_419 :
F_164 ( V_13 ) = V_420 ;
break;
case V_421 :
F_164 ( V_13 ) = V_422 ;
break;
default:
F_164 ( V_13 ) = V_423 ;
break;
}
} else
F_164 ( V_13 ) = V_423 ;
F_65 ( V_13 -> V_278 ) ;
}
static void
F_165 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_12 V_424 ;
F_64 ( V_13 -> V_278 ) ;
if ( ( V_15 -> V_62 > V_65 ) &&
( ( V_15 -> V_76 & V_78 ) ||
( ( V_18 -> V_74 == V_75 ) &&
( V_15 -> V_76 & V_77 ) ) ) )
V_424 = F_77 ( V_18 -> V_425 . V_426 . V_103 . V_228 ) ;
else
V_424 = 0 ;
F_65 ( V_13 -> V_278 ) ;
F_166 ( V_13 ) = V_424 ;
}
static struct V_427 *
F_167 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_126 * V_127 = & V_18 -> V_33 ;
struct V_427 * V_428 = & V_18 -> V_429 ;
struct V_430 * V_431 = & V_127 -> V_432 ;
T_6 * V_94 ;
T_7 * V_187 ;
unsigned long V_433 ;
int V_129 = 0 ;
if ( V_18 -> V_51 < V_56 ||
! V_18 -> V_100 ||
( V_18 -> V_33 . V_34 & V_189 ) == 0 )
return NULL ;
if ( V_18 -> V_33 . V_34 & V_98 )
return NULL ;
V_94 = F_28 ( V_18 -> V_100 , V_101 ) ;
if ( ! V_94 )
return NULL ;
memset ( V_94 , 0 , sizeof ( T_6 ) ) ;
V_187 = & V_94 -> V_103 . V_104 ;
V_187 -> V_105 = V_434 ;
V_187 -> V_107 = V_108 ;
V_94 -> V_191 = NULL ;
V_94 -> V_15 = V_15 ;
if ( V_15 -> V_76 & V_97 )
V_129 = F_168 ( V_18 , V_94 , V_435 ) ;
else
V_129 = F_29 ( V_18 , V_94 , V_18 -> V_115 * 2 ) ;
if ( V_129 != V_110 ) {
if ( V_129 != V_120 )
F_33 ( V_94 , V_18 -> V_100 ) ;
return NULL ;
}
memset ( V_428 , 0 , sizeof ( struct V_427 ) ) ;
V_428 -> V_436 = V_187 -> V_194 . V_437 . V_438 ;
V_428 -> V_439 = ( T_10 )
( ( T_10 ) V_187 -> V_194 . V_437 . V_440
* ( T_10 ) 256 ) ;
V_428 -> V_441 = V_187 -> V_194 . V_437 . V_442 ;
V_428 -> V_443 = ( T_10 )
( ( T_10 ) V_187 -> V_194 . V_437 . V_444
* ( T_10 ) 256 ) ;
memset ( V_94 , 0 , sizeof ( T_6 ) ) ;
V_187 -> V_105 = V_445 ;
V_187 -> V_107 = V_108 ;
V_94 -> V_191 = NULL ;
V_94 -> V_15 = V_15 ;
if ( V_15 -> V_76 & V_97 )
V_129 = F_168 ( V_18 , V_94 , V_435 ) ;
else
V_129 = F_29 ( V_18 , V_94 , V_18 -> V_115 * 2 ) ;
if ( V_129 != V_110 ) {
if ( V_129 != V_120 )
F_33 ( V_94 , V_18 -> V_100 ) ;
return NULL ;
}
V_428 -> V_446 = V_187 -> V_194 . V_447 . V_448 ;
V_428 -> V_449 = V_187 -> V_194 . V_447 . V_450 ;
V_428 -> V_451 = V_187 -> V_194 . V_447 . V_452 ;
V_428 -> V_453 = V_187 -> V_194 . V_447 . V_454 ;
V_428 -> V_455 = V_187 -> V_194 . V_447 . V_456 ;
V_428 -> V_457 = V_187 -> V_194 . V_447 . V_458 ;
V_428 -> V_459 = V_187 -> V_194 . V_447 . V_458 ;
V_428 -> V_446 -= V_431 -> V_446 ;
V_428 -> V_449 -= V_431 -> V_449 ;
V_428 -> V_451 -= V_431 -> V_451 ;
V_428 -> V_453 -= V_431 -> V_453 ;
V_428 -> V_455 -= V_431 -> V_455 ;
V_428 -> V_457 -= V_431 -> V_457 ;
V_428 -> V_459 -= V_431 -> V_459 ;
if ( V_18 -> V_19 & V_407 ) {
V_428 -> V_460 = - 1 ;
V_428 -> V_461 = ( V_18 -> V_462 >> 1 ) ;
V_428 -> V_461 -= V_431 -> V_462 ;
} else if ( V_18 -> V_74 == V_75 ) {
V_428 -> V_460 = ( V_18 -> V_463 >> 1 ) ;
V_428 -> V_460 -= V_431 -> V_462 ;
V_428 -> V_461 = - 1 ;
} else {
V_428 -> V_460 = - 1 ;
V_428 -> V_461 = ( V_18 -> V_463 >> 1 ) ;
V_428 -> V_461 -= V_431 -> V_462 ;
}
V_428 -> V_464 = - 1 ;
V_433 = F_169 () ;
if ( V_433 < V_127 -> V_465 )
V_428 -> V_466 = V_433 +
( ( unsigned long ) - 1 - V_127 -> V_465 ) ;
else
V_428 -> V_466 = V_433 - V_127 -> V_465 ;
F_33 ( V_94 , V_18 -> V_100 ) ;
return V_428 ;
}
static void
F_170 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_126 * V_127 = & V_18 -> V_33 ;
struct V_430 * V_431 = & V_127 -> V_432 ;
T_6 * V_94 ;
T_7 * V_187 ;
int V_129 = 0 ;
if ( V_18 -> V_33 . V_34 & V_98 )
return;
V_94 = F_28 ( V_18 -> V_100 , V_101 ) ;
if ( ! V_94 )
return;
memset ( V_94 , 0 , sizeof( T_6 ) ) ;
V_187 = & V_94 -> V_103 . V_104 ;
V_187 -> V_105 = V_434 ;
V_187 -> V_107 = V_108 ;
V_187 -> V_194 . V_467 [ 0 ] = 0x1 ;
V_94 -> V_191 = NULL ;
V_94 -> V_15 = V_15 ;
if ( ( V_15 -> V_76 & V_97 ) ||
( ! ( V_127 -> V_34 & V_189 ) ) )
V_129 = F_168 ( V_18 , V_94 , V_435 ) ;
else
V_129 = F_29 ( V_18 , V_94 , V_18 -> V_115 * 2 ) ;
if ( V_129 != V_110 ) {
if ( V_129 != V_120 )
F_33 ( V_94 , V_18 -> V_100 ) ;
return;
}
memset ( V_94 , 0 , sizeof( T_6 ) ) ;
V_187 -> V_105 = V_445 ;
V_187 -> V_107 = V_108 ;
V_94 -> V_191 = NULL ;
V_94 -> V_15 = V_15 ;
if ( ( V_15 -> V_76 & V_97 ) ||
( ! ( V_127 -> V_34 & V_189 ) ) )
V_129 = F_168 ( V_18 , V_94 , V_435 ) ;
else
V_129 = F_29 ( V_18 , V_94 , V_18 -> V_115 * 2 ) ;
if ( V_129 != V_110 ) {
if ( V_129 != V_120 )
F_33 ( V_94 , V_18 -> V_100 ) ;
return;
}
V_431 -> V_446 = V_187 -> V_194 . V_447 . V_448 ;
V_431 -> V_449 = V_187 -> V_194 . V_447 . V_450 ;
V_431 -> V_451 = V_187 -> V_194 . V_447 . V_452 ;
V_431 -> V_453 = V_187 -> V_194 . V_447 . V_454 ;
V_431 -> V_455 = V_187 -> V_194 . V_447 . V_456 ;
V_431 -> V_457 = V_187 -> V_194 . V_447 . V_458 ;
V_431 -> V_459 = V_187 -> V_194 . V_447 . V_458 ;
if ( V_18 -> V_19 & V_407 )
V_431 -> V_462 = ( V_18 -> V_462 >> 1 ) ;
else
V_431 -> V_462 = ( V_18 -> V_463 >> 1 ) ;
V_127 -> V_465 = F_169 () ;
F_33 ( V_94 , V_18 -> V_100 ) ;
return;
}
static struct V_276 *
F_171 ( struct V_468 * V_469 )
{
struct V_12 * V_13 = F_172 ( V_469 -> V_6 . V_470 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_276 * V_277 ;
F_64 ( V_13 -> V_278 ) ;
F_106 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_107 ( V_277 ) &&
V_277 -> V_376 == V_471 &&
V_469 -> V_472 == V_277 -> V_473 ) {
F_65 ( V_13 -> V_278 ) ;
return V_277 ;
}
}
F_65 ( V_13 -> V_278 ) ;
return NULL ;
}
static void
F_173 ( struct V_468 * V_469 )
{
struct V_276 * V_277 = F_171 ( V_469 ) ;
F_174 ( V_469 ) = V_277 ? V_277 -> V_474 : - 1 ;
}
static void
F_175 ( struct V_468 * V_469 )
{
struct V_276 * V_277 = F_171 ( V_469 ) ;
F_176 ( V_469 ) =
V_277 ? F_77 ( V_277 -> V_475 . V_103 . V_228 ) : 0 ;
}
static void
F_177 ( struct V_468 * V_469 )
{
struct V_276 * V_277 = F_171 ( V_469 ) ;
F_178 ( V_469 ) =
V_277 ? F_77 ( V_277 -> V_325 . V_103 . V_228 ) : 0 ;
}
static void
F_179 ( struct V_476 * V_279 , T_2 V_477 )
{
if ( V_477 )
V_279 -> V_280 = V_477 ;
else
V_279 -> V_280 = 1 ;
}
static void
F_180 ( struct V_478 * V_478 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_478 -> V_479 ;
if ( V_15 -> V_62 == V_71 )
F_181 ( V_15 , V_480 , 0 , 0 ) ;
}
static void
F_182 ( struct V_17 * V_18 , T_2 V_481 )
{
V_18 -> V_482 = V_481 ;
}
void
F_183 ( struct V_17 * V_18 )
{
F_184 ( V_18 , V_483 ) ;
F_185 ( V_18 , V_484 ) ;
F_186 ( V_18 , V_485 ) ;
F_187 ( V_18 , V_486 ) ;
F_188 ( V_18 , V_487 ) ;
F_189 ( V_18 , V_488 ) ;
F_190 ( V_18 , V_489 ) ;
F_191 ( V_18 , V_490 ) ;
F_192 ( V_18 , V_491 ) ;
F_128 ( V_18 , V_492 ) ;
F_193 ( V_18 , V_493 ) ;
F_194 ( V_18 , V_494 ) ;
F_195 ( V_18 , V_495 ) ;
F_196 ( V_18 , V_496 ) ;
F_197 ( V_18 , V_497 ) ;
F_198 ( V_18 , V_498 ) ;
F_199 ( V_18 , V_499 ) ;
F_200 ( V_18 , V_500 ) ;
F_142 ( V_18 , V_501 ) ;
F_145 ( V_18 , V_502 ) ;
F_201 ( V_18 , V_503 ) ;
F_202 ( V_18 , V_504 ) ;
F_203 ( V_18 , V_505 ) ;
F_204 ( V_18 , V_506 ) ;
if ( V_18 -> V_44 != V_45 )
V_18 -> V_507 = 0 ;
F_205 ( V_18 , V_508 ) ;
memset ( V_18 -> V_242 , 0 , ( 8 * sizeof( T_3 ) ) ) ;
memset ( V_18 -> V_250 , 0 , ( 8 * sizeof( T_3 ) ) ) ;
V_18 -> V_253 = 0 ;
V_18 -> V_255 = 0 ;
V_18 -> V_245 = 0 ;
F_206 ( V_18 , V_509 ) ;
if ( V_18 -> V_44 == V_45 )
V_18 -> V_212 = 0 ;
else
V_18 -> V_212 = V_510 ;
if ( V_18 -> V_511 ) {
V_18 -> V_512 = V_513 ;
} else {
if ( V_18 -> V_512 == V_513 )
V_18 -> V_512 = V_514 ;
}
V_18 -> V_238 = 0L ;
V_18 -> V_232 = 0L ;
F_207 ( V_18 , V_515 ) ;
F_208 ( V_18 , V_516 ) ;
F_209 ( V_18 , V_517 ) ;
F_182 ( V_18 , V_518 ) ;
F_132 ( V_18 , V_519 ) ;
F_136 ( V_18 , V_520 ) ;
F_139 ( V_18 , V_521 ) ;
F_210 ( V_18 , V_522 ) ;
F_211 ( V_18 , V_523 ) ;
V_18 -> V_225 = 1 ;
return;
}
void
F_212 ( struct V_14 * V_15 )
{
F_213 ( V_15 , V_518 ) ;
F_214 ( V_15 , V_524 ) ;
F_215 ( V_15 , V_525 ) ;
F_216 ( V_15 , V_282 ) ;
F_103 ( V_15 , V_526 ) ;
F_217 ( V_15 , V_527 ) ;
F_111 ( V_15 , V_528 ) ;
F_218 ( V_15 , V_529 ) ;
F_219 ( V_15 , V_530 ) ;
F_220 ( V_15 , V_531 ) ;
F_221 ( V_15 , V_532 ) ;
F_222 ( V_15 , V_533 ) ;
F_223 ( V_15 , V_534 ) ;
F_224 ( V_15 , V_535 ) ;
F_225 ( V_15 , V_536 ) ;
return;
}
