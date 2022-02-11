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
V_87 = F_34 ( V_18 , V_139 ) ;
if ( V_87 != 0 )
return V_87 ;
F_39 ( 100 ) ;
V_156 = F_47 ( V_18 -> V_42 . V_163 +
V_164 ) ;
if ( V_150 == V_165 )
V_156 |= V_166 ;
else if ( V_150 == V_167 )
V_156 |= V_168 ;
else if ( V_150 == V_169 )
V_156 |= V_170 ;
F_48 ( V_156 , V_18 -> V_42 . V_163 +
V_164 ) ;
F_47 ( V_18 -> V_42 . V_163 + V_164 ) ;
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
goto V_171;
F_35 ( & V_123 ) ;
V_157 = F_36 ( V_18 , & V_87 , & V_123 ,
V_140 ) ;
if ( ! V_157 )
goto V_171;
F_37 ( & V_123 ) ;
V_171:
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
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_172 ) ;
}
static T_1
F_51 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
char * V_173 ;
if ( V_18 -> V_51 == V_57 )
V_173 = L_38 ;
else if ( V_18 -> V_51 == V_53 )
V_173 = L_39 ;
else if ( V_18 -> V_51 == V_54 )
V_173 = L_40 ;
else
V_173 = L_41 ;
return snprintf ( V_9 , V_10 , L_8 , V_173 ) ;
}
static T_1
F_52 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_122 V_123 ;
char * V_174 = NULL ;
int V_87 = 0 ;
int V_129 ;
if ( ! V_18 -> V_136 ) {
V_87 = - V_137 ;
goto V_175;
}
F_53 ( V_15 , V_117 , V_135 ,
L_42 , V_9 ) ;
F_35 ( & V_123 ) ;
if( strncmp ( V_9 , L_41 , sizeof( L_41 ) - 1 ) == 0 ) {
V_129 = F_36 ( V_18 , & V_87 , & V_123 ,
V_140 ) ;
if ( V_129 == 0 ) {
V_87 = - V_102 ;
goto V_175;
}
F_37 ( & V_123 ) ;
} else if ( strncmp ( V_9 , L_40 , sizeof( L_40 ) - 1 ) == 0 )
V_87 = F_34 ( V_18 , V_139 ) ;
else if ( strncmp ( V_9 , L_43 , sizeof( L_43 ) - 1 ) == 0 )
if ( V_18 -> V_44 == V_45 )
V_87 = - V_88 ;
else
V_87 = F_34 ( V_18 , V_176 ) ;
else if ( strncmp ( V_9 , L_38 , sizeof( L_38 ) - 1 ) == 0 )
if ( V_18 -> V_44 == V_45 )
V_87 = - V_88 ;
else
V_87 = F_34 ( V_18 , V_177 ) ;
else if ( strncmp ( V_9 , L_44 , sizeof( L_44 ) - 1 ) == 0 )
V_87 = F_45 ( V_18 , V_165 ) ;
else if ( strncmp ( V_9 , L_45 , sizeof( L_45 ) - 1 ) == 0 )
V_87 = F_45 ( V_18 , V_167 ) ;
else if ( strncmp ( V_9 , L_46 , sizeof( L_46 ) - 1 ) == 0 )
V_87 = F_45 ( V_18 , V_169 ) ;
else
V_87 = - V_88 ;
V_175:
if ( ! V_87 )
return strlen ( V_9 ) ;
else {
V_174 = strchr ( V_9 , '\n' ) ;
if ( V_174 )
* V_174 = '\0' ;
F_53 ( V_15 , V_117 , V_135 ,
L_47
L_48 ,
V_9 , V_87 , V_18 -> V_138 -> V_76 ) ;
return V_87 ;
}
}
static int
F_54 ( struct V_17 * V_18 ,
T_2 * V_178 , T_2 * V_179 ,
T_2 * V_180 , T_2 * V_181 ,
T_2 * V_182 , T_2 * V_183 )
{
struct V_184 * V_185 ;
T_6 * V_94 ;
T_7 * V_186 ;
int V_129 = 0 ;
T_2 V_187 ;
if ( V_18 -> V_51 < V_56 ||
! V_18 -> V_100 ||
( V_18 -> V_33 . V_34 & V_188 ) == 0 )
return 0 ;
if ( V_18 -> V_33 . V_34 & V_98 )
return 0 ;
V_94 = F_28 ( V_18 -> V_100 , V_101 ) ;
if ( ! V_94 )
return 0 ;
memset ( V_94 , 0 , sizeof ( T_6 ) ) ;
V_186 = & V_94 -> V_103 . V_104 ;
V_186 -> V_105 = V_189 ;
V_186 -> V_107 = V_108 ;
V_94 -> V_190 = NULL ;
if ( V_18 -> V_138 -> V_76 & V_97 )
V_129 = V_191 ;
else
V_129 = F_29 ( V_18 , V_94 , V_18 -> V_115 * 2 ) ;
if ( V_129 != V_110 ) {
if ( V_129 != V_120 )
F_33 ( V_94 , V_18 -> V_100 ) ;
return 0 ;
}
if ( V_18 -> V_44 == V_45 ) {
V_185 = & V_94 -> V_103 . V_192 . V_193 . V_185 ;
if ( V_180 )
* V_180 = F_44 ( V_194 , V_185 ) ;
if ( V_181 )
* V_181 = F_44 ( V_194 , V_185 ) -
V_18 -> V_42 . V_195 . V_196 ;
if ( V_178 )
* V_178 = F_44 ( V_197 , V_185 ) ;
if ( V_179 )
* V_179 = F_44 ( V_197 , V_185 ) -
V_18 -> V_42 . V_195 . V_198 ;
V_187 = ( F_44 ( V_199 , V_185 ) > 0 ) ?
( F_44 ( V_199 , V_185 ) - 1 ) : 0 ;
if ( V_182 )
* V_182 = V_187 ;
if ( V_183 )
* V_183 = V_187 - V_18 -> V_42 . V_195 . V_200 ;
} else {
if ( V_180 )
* V_180 = V_186 -> V_193 . V_201 . V_202 ;
if ( V_181 )
* V_181 = V_186 -> V_193 . V_201 . V_203 ;
if ( V_178 )
* V_178 = V_186 -> V_193 . V_201 . V_204 ;
if ( V_179 )
* V_179 = V_186 -> V_193 . V_201 . V_205 ;
if ( V_182 )
* V_182 = V_186 -> V_193 . V_201 . V_187 ;
if ( V_183 )
* V_183 = V_186 -> V_193 . V_201 . V_206 ;
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
T_2 V_128 , V_207 ;
if ( F_54 ( V_18 , NULL , NULL , & V_128 , & V_207 , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_128 - V_207 ) ) ;
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
T_2 V_128 , V_207 ;
if ( F_54 ( V_18 , & V_128 , & V_207 , NULL , NULL , NULL , NULL ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_128 - V_207 ) ) ;
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
T_2 V_128 , V_207 ;
if ( F_54 ( V_18 , NULL , NULL , NULL , NULL , & V_128 , & V_207 ) )
return snprintf ( V_9 , V_10 , L_9 , ( V_128 - V_207 ) ) ;
return snprintf ( V_9 , V_10 , L_19 ) ;
}
static T_1
F_61 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! ( V_18 -> V_187 ) )
return snprintf ( V_9 , V_10 , L_49 ) ;
if ( V_15 -> V_208 == V_209 )
return snprintf ( V_9 , V_10 , L_50 ) ;
return snprintf ( V_9 , V_10 , L_51 , V_15 -> V_210 ) ;
}
static T_1
F_62 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_52 , V_18 -> V_211 ) ;
}
static T_1
F_63 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_2 V_212 ;
T_2 V_213 ;
int V_214 = 0 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_214 ) != 1 )
return - V_88 ;
if ( ( V_214 & 0x3 ) != V_214 )
return - V_88 ;
if ( V_18 -> V_44 == V_45 )
V_214 = 0 ;
F_53 ( V_15 , V_117 , V_135 ,
L_54 ,
V_18 -> V_211 , V_214 ) ;
F_64 ( & V_18 -> V_215 ) ;
V_213 = V_18 -> V_211 ;
if ( V_214 & V_216 ) {
if ( ( V_214 & V_217 ) &&
! ( V_213 & V_217 ) ) {
if ( F_43 ( V_18 -> V_218 , & V_212 ) ) {
F_65 ( & V_18 -> V_215 ) ;
return - V_88 ;
}
V_212 &= ~ ( V_219 << V_220 ) ;
F_48 ( V_212 , V_18 -> V_218 ) ;
F_47 ( V_18 -> V_218 ) ;
F_66 ( V_18 ) ;
}
} else if ( V_214 != 0x0 ) {
F_65 ( & V_18 -> V_215 ) ;
return - V_88 ;
}
if ( ! ( V_214 & V_217 ) &&
( V_213 & V_217 ) )
{
F_65 ( & V_18 -> V_215 ) ;
F_67 ( & V_18 -> V_221 ) ;
F_64 ( & V_18 -> V_215 ) ;
if ( F_43 ( V_18 -> V_218 , & V_212 ) ) {
F_65 ( & V_18 -> V_215 ) ;
return - V_88 ;
}
V_212 |= ( V_219 << V_220 ) ;
F_48 ( V_212 , V_18 -> V_218 ) ;
F_47 ( V_18 -> V_218 ) ;
}
V_18 -> V_211 = V_214 ;
F_65 ( & V_18 -> V_215 ) ;
return strlen ( V_9 ) ;
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
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_223 ) ;
}
static T_1
F_70 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
return snprintf ( V_9 , V_10 , L_55 ,
( V_18 -> V_224 ) ? L_56 : L_57 ,
( V_18 -> V_22 & V_225 ) ?
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
T_8 V_226 ;
V_226 = F_72 ( V_18 ) ;
return snprintf ( V_9 , V_10 , L_9 , V_226 ) ;
}
static T_5
F_73 ( const char * V_9 , T_5 V_128 , char V_227 [] )
{
unsigned int V_3 , V_4 ;
if ( V_9 [ V_128 - 1 ] == '\n' )
V_128 -- ;
if ( ( V_128 < 16 ) || ( V_128 > 18 ) || ( ( V_128 == 17 ) && ( * V_9 ++ != 'x' ) ) ||
( ( V_128 == 18 ) && ( ( * V_9 ++ != '0' ) || ( * V_9 ++ != 'x' ) ) ) )
return - V_88 ;
memset ( V_227 , 0 , V_228 ) ;
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
V_227 [ V_3 / 2 ] = V_4 & 0xff ;
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
if ( ( V_128 != strlen ( V_229 ) ) ||
( strncmp ( V_9 , V_229 , strlen ( V_229 ) ) != 0 ) )
return - V_88 ;
V_18 -> V_230 = 1 ;
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
( unsigned long long ) V_18 -> V_231 ) ;
}
static T_1
F_76 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_122 V_123 ;
int V_232 = 0 , V_233 = 0 ;
unsigned int V_128 = V_86 ;
T_9 V_234 [ V_228 ] ;
int V_129 ;
if ( ! V_18 -> V_136 )
return - V_137 ;
F_64 ( & V_18 -> V_215 ) ;
if ( V_18 -> V_235 == V_236 ) {
F_65 ( & V_18 -> V_215 ) ;
return - V_137 ;
}
F_65 ( & V_18 -> V_215 ) ;
if ( V_9 [ V_128 - 1 ] == '\n' )
V_128 -- ;
if ( ! V_18 -> V_230 )
return - V_88 ;
V_18 -> V_230 = 0 ;
V_129 = F_73 ( V_9 , V_128 , V_234 ) ;
if ( ! V_129 ) {
V_18 -> V_230 = 1 ;
return V_129 ;
}
V_18 -> V_231 = F_77 ( V_234 ) ;
F_78 ( V_13 ) = V_18 -> V_231 ;
if ( V_18 -> V_237 )
F_79 ( V_13 ) = V_18 -> V_237 ;
F_80 ( V_238 , & V_18 -> V_153 -> V_6 ,
L_61 , V_18 -> V_239 ) ;
V_232 = F_34 ( V_18 , V_139 ) ;
if ( V_232 )
F_31 ( V_18 , V_117 , V_135 ,
L_62
L_63 , V_232 ) ;
F_35 ( & V_123 ) ;
V_129 = F_36 ( V_18 , & V_233 , & V_123 ,
V_140 ) ;
if ( V_129 == 0 )
return - V_102 ;
F_37 ( & V_123 ) ;
if ( V_233 )
F_31 ( V_18 , V_117 , V_135 ,
L_64
L_63 , V_233 ) ;
return ( V_232 || V_233 ) ? - V_121 : V_86 ;
}
static T_1
F_81 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_60 ,
( unsigned long long ) V_18 -> V_237 ) ;
}
static T_1
F_82 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_128 = V_86 ;
T_9 V_240 [ V_228 ] ;
int V_129 ;
if ( V_9 [ V_128 - 1 ] == '\n' )
V_128 -- ;
if ( ! V_18 -> V_230 )
return - V_88 ;
V_129 = F_73 ( V_9 , V_128 , V_240 ) ;
if ( ! V_129 ) {
return V_129 ;
}
V_18 -> V_237 = F_77 ( V_240 ) ;
F_80 ( V_238 , & V_18 -> V_153 -> V_6 ,
L_65
L_66 , V_18 -> V_239 ) ;
return V_86 ;
}
static T_1
F_83 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_60 ,
F_77 ( V_18 -> V_241 ) ) ;
}
static T_1
F_84 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_128 = V_86 ;
T_3 V_234 [ V_228 ] ;
int V_129 ;
if ( ! V_18 -> V_242 )
return - V_99 ;
if ( V_9 [ V_128 - 1 ] == '\n' )
V_128 -- ;
V_129 = F_73 ( V_9 , V_128 , V_234 ) ;
if ( V_129 )
return V_129 ;
memcpy ( V_18 -> V_241 , V_234 , ( 8 * sizeof( T_3 ) ) ) ;
memcpy ( V_18 -> V_42 . V_243 , V_234 , ( 8 * sizeof( T_3 ) ) ) ;
if ( F_77 ( V_234 ) == 0 )
V_18 -> V_244 |= V_245 ;
else
V_18 -> V_244 &= ~ V_245 ;
V_18 -> V_244 &= ~ V_246 ;
V_18 -> V_42 . V_247 = V_248 ;
return V_86 ;
}
static T_1
F_85 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_60 ,
F_77 ( V_18 -> V_249 ) ) ;
}
static T_1
F_86 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
unsigned int V_128 = V_86 ;
T_3 V_234 [ V_228 ] ;
int V_129 ;
if ( ! V_18 -> V_242 )
return - V_99 ;
if ( V_9 [ V_128 - 1 ] == '\n' )
V_128 -- ;
V_129 = F_73 ( V_9 , V_128 , V_234 ) ;
if ( V_129 )
return V_129 ;
memcpy ( V_18 -> V_249 , V_234 , ( 8 * sizeof( T_3 ) ) ) ;
memcpy ( V_18 -> V_42 . V_250 , V_234 , ( 8 * sizeof( T_3 ) ) ) ;
if ( F_77 ( V_234 ) == 0 )
V_18 -> V_244 |= V_251 ;
else
V_18 -> V_244 &= ~ V_251 ;
V_18 -> V_244 &= ~ V_246 ;
V_18 -> V_42 . V_247 = V_248 ;
return V_86 ;
}
static T_1
F_87 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_252 ) ;
}
static T_1
F_88 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
int V_214 = 0 ;
if ( ! V_18 -> V_242 )
return - V_99 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_214 ) != 1 )
return - V_88 ;
if ( ( V_214 != 0 ) && ( V_214 != 1 ) )
return - V_88 ;
V_18 -> V_252 = V_214 ;
return strlen ( V_9 ) ;
}
static T_1
F_89 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
if ( ! ( V_18 -> V_244 & V_246 ) )
return - V_253 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_254 ) ;
}
static T_5
F_90 ( struct V_17 * V_18 , T_3 V_255 [] ,
T_3 V_256 [] , T_10 V_257 , T_2 V_258 )
{
int V_129 = 0 ;
if ( ! V_18 -> V_242 )
return - V_99 ;
if ( V_258 ) {
if ( ! F_91 ( V_18 , (struct V_259 * ) V_255 ,
(struct V_259 * ) V_256 , V_257 ) )
V_129 = - V_102 ;
} else {
F_92 ( V_18 , (struct V_259 * ) V_255 ,
(struct V_259 * ) V_256 , V_257 ) ;
}
return V_129 ;
}
static T_10
F_93 ( struct V_17 * V_18 , T_3 V_255 [] ,
T_3 V_256 [] , T_2 * V_260 )
{
T_10 V_261 ;
if ( F_94 ( ! V_18 ) || ! V_255 || ! V_256 )
return V_262 ;
if ( F_95 ( V_18 , (struct V_259 * )
V_18 -> V_42 . V_250 ,
(struct V_259 * )
V_18 -> V_42 . V_243 ,
& V_18 -> V_42 . V_247 ,
(struct V_259 * ) V_255 ,
(struct V_259 * ) V_256 ,
& V_261 , V_260 ) )
return V_261 ;
else
return V_262 ;
}
static T_1
F_96 ( struct V_17 * V_18 , T_3 V_255 [] ,
T_3 V_256 [] , T_10 V_257 ,
T_2 V_258 )
{
int V_129 ;
V_129 = F_90 ( V_18 , V_255 , V_256 , V_257 ,
V_258 ) ;
return V_129 ;
}
static T_1
F_97 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_10 V_263 ;
int V_41 = 0 ;
if ( ! V_18 -> V_242 )
return - V_99 ;
if ( F_77 ( V_18 -> V_249 ) == 0 )
if ( ! ( V_18 -> V_244 & V_251 ) )
return - V_253 ;
if ( F_77 ( V_18 -> V_241 ) == 0 )
if ( ! ( V_18 -> V_244 & V_245 ) )
return - V_253 ;
V_263 = F_93 ( V_18 , V_18 -> V_249 ,
V_18 -> V_241 ,
& V_18 -> V_254 ) ;
if ( V_263 != V_262 )
V_18 -> V_244 |= V_246 ;
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 , L_67 , V_263 ) ;
return V_41 ;
}
static T_1
F_98 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
T_10 V_264 ;
T_1 V_129 ;
if ( ! V_18 -> V_242 )
return - V_99 ;
if ( F_77 ( V_18 -> V_249 ) == 0 )
return - V_253 ;
if ( F_77 ( V_18 -> V_241 ) == 0 )
return - V_253 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_67 , & V_264 ) != 1 )
return - V_88 ;
F_31 ( V_18 , V_265 , V_135 ,
L_68
L_69 ,
F_77 ( V_18 -> V_249 ) ,
F_77 ( V_18 -> V_241 ) , V_264 ,
V_18 -> V_252 ) ;
V_129 = F_96 ( V_18 , V_18 -> V_249 ,
V_18 -> V_241 , V_264 ,
V_18 -> V_252 ) ;
if ( V_129 )
return V_129 ;
return V_86 ;
}
static T_1
F_99 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 , V_18 -> V_266 ) ;
}
static T_1
F_100 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_132 [ V_267 ] . V_268 ) ;
}
static T_1
F_101 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_17 * V_18 = ( (struct V_14 * ) V_13 -> V_16 ) -> V_18 ;
return snprintf ( V_9 , V_10 , L_9 ,
V_18 -> V_33 . V_132 [ V_267 ] . V_269 ) ;
}
static T_1
F_102 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_9 , V_10 , L_9 , V_15 -> V_270 ) ;
}
static int
F_103 ( struct V_14 * V_15 , int V_214 )
{
if ( V_15 -> V_270 != V_271 ) {
V_15 -> V_272 = V_15 -> V_270 ;
if ( V_214 != V_271 )
F_53 ( V_15 , V_117 , V_135 ,
L_70
L_71
L_72 ) ;
return 0 ;
}
if ( V_214 >= V_273 && V_214 <= V_274 ) {
V_15 -> V_272 = V_214 ;
V_15 -> V_270 = V_214 ;
return 0 ;
}
F_53 ( V_15 , V_117 , V_135 ,
L_73
L_74 ,
V_214 , V_273 , V_274 ) ;
V_15 -> V_272 = V_271 ;
return - V_88 ;
}
static void
F_104 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_275 * V_276 ;
V_13 = F_105 ( V_15 ) ;
F_64 ( V_13 -> V_277 ) ;
F_106 (ndlp, &vport->fc_nodes, nlp_listp)
if ( F_107 ( V_276 ) && V_276 -> V_278 )
V_276 -> V_278 -> V_279 = V_15 -> V_270 ;
F_65 ( V_13 -> V_277 ) ;
}
static int
F_108 ( struct V_14 * V_15 , int V_214 )
{
if ( V_15 -> V_280 ||
( V_281 != V_271 ) ) {
F_53 ( V_15 , V_117 , V_135 ,
L_75
L_76 ) ;
return 0 ;
}
if ( V_214 >= V_273 && V_214 <= V_274 ) {
V_15 -> V_272 = V_214 ;
V_15 -> V_270 = V_214 ;
F_109 ( F_105 ( V_15 ) ) = V_214 ;
F_104 ( V_15 ) ;
return 0 ;
}
F_53 ( V_15 , V_117 , V_135 ,
L_77
L_78 ,
V_214 , V_273 , V_274 ) ;
return - V_88 ;
}
static int
F_110 ( struct V_14 * V_15 , int V_214 )
{
if ( V_214 >= V_273 && V_214 <= V_274 ) {
V_15 -> V_272 = V_214 ;
V_15 -> V_270 = V_214 ;
V_15 -> V_280 = 1 ;
F_109 ( F_105 ( V_15 ) ) = V_214 ;
F_104 ( V_15 ) ;
return 0 ;
}
F_53 ( V_15 , V_117 , V_135 ,
L_79
L_74 ,
V_214 , V_273 , V_274 ) ;
return - V_88 ;
}
static int
F_111 ( struct V_14 * V_15 , int V_214 )
{
if ( V_214 < 0 || V_214 > 1 ) {
F_53 ( V_15 , V_117 , V_135 ,
L_80
L_81 ,
V_214 ) ;
V_15 -> V_282 = 1 ;
return - V_88 ;
}
if ( V_15 -> V_208 == V_209 ) {
V_15 -> V_282 = 0 ;
return 0 ;
}
V_15 -> V_282 = V_214 ;
return 0 ;
}
static int
F_112 ( struct V_14 * V_15 , int V_214 )
{
if ( V_214 < 0 || V_214 > 1 ) {
F_53 ( V_15 , V_117 , V_135 ,
L_82
L_81 ,
V_214 ) ;
V_15 -> V_282 = 1 ;
return - V_88 ;
}
if ( V_15 -> V_208 == V_209 && V_214 != 0 ) {
F_53 ( V_15 , V_117 , V_135 ,
L_83
L_84 ) ;
V_15 -> V_282 = 0 ;
return 0 ;
}
V_15 -> V_282 = V_214 ;
return 0 ;
}
static T_1
F_113 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_214 = 0 ;
int V_283 = 0 ;
const char * V_284 = V_9 ;
int V_285 ;
T_2 V_286 ;
if ( ! strncmp ( V_9 , L_85 , strlen ( L_85 ) ) ) {
V_283 = 1 ;
V_284 = & V_9 [ strlen ( L_85 ) ] ;
}
if ( ! isdigit ( V_284 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_284 , L_53 , & V_214 ) != 1 )
return - V_88 ;
if ( V_214 >= 0 && V_214 <= 6 ) {
V_286 = V_18 -> V_113 ;
V_18 -> V_113 = V_214 ;
if ( V_18 -> V_114 == V_287 &&
V_214 == 4 ) {
F_53 ( V_15 , V_117 , V_135 ,
L_86 ,
V_18 -> V_114 ) ;
V_18 -> V_113 = V_286 ;
return - V_88 ;
}
if ( V_283 )
return strlen ( V_9 ) ;
F_53 ( V_15 , V_117 , V_135 ,
L_87 ,
V_286 , V_214 ) ;
if ( V_286 != V_214 && V_18 -> V_44 == V_45 )
V_18 -> V_288 = 1 ;
V_285 = F_27 ( F_105 ( V_18 -> V_138 ) ) ;
if ( V_285 ) {
V_18 -> V_113 = V_286 ;
return - V_88 ;
} else
return strlen ( V_9 ) ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_88
L_89 ,
V_18 -> V_239 , V_214 ) ;
return - V_88 ;
}
static T_1
F_114 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_289 & V_290 )
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
static char V_291 [ F_116 ] ;
unsigned long V_3 ;
char * V_292 , * V_293 ;
struct V_14 * * V_294 ;
struct V_12 * V_295 ;
char * V_296 , * V_297 , * V_298 ;
unsigned long V_299 , V_300 , V_301 ;
if ( ! strncmp ( V_9 , L_90 , strlen ( L_90 ) ) ) {
if ( strlen ( V_9 ) > ( F_116 - 1 ) )
return - V_88 ;
strcpy ( V_291 , V_9 ) ;
V_292 = & V_291 [ 0 ] ;
V_293 = F_117 ( & V_292 , L_91 ) ;
if ( ! V_293 )
return - V_88 ;
V_296 = F_117 ( & V_292 , L_91 ) ;
if ( ! V_296 )
return - V_88 ;
if ( ! strncmp ( V_296 , L_92 , strlen ( L_92 ) ) )
V_301 = V_302 ;
else if ( ! strncmp ( V_296 , L_93 , strlen ( L_93 ) ) )
V_301 = V_303 ;
else
return - V_88 ;
V_297 = F_117 ( & V_292 , L_91 ) ;
if ( ! V_297 )
return - V_88 ;
V_299 = F_118 ( V_297 , NULL , 0 ) ;
V_298 = F_117 ( & V_292 , L_91 ) ;
if ( ! V_298 )
return - V_88 ;
V_300 = F_118 ( V_298 , NULL , 0 ) ;
if ( ! V_300 )
return - V_88 ;
V_294 = F_119 ( V_18 ) ;
if ( V_294 == NULL )
return - V_102 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_304 && V_294 [ V_3 ] != NULL ; V_3 ++ ) {
V_295 = F_105 ( V_294 [ V_3 ] ) ;
F_64 ( V_295 -> V_277 ) ;
V_294 [ V_3 ] -> V_305 = 1 ;
if ( V_294 [ V_3 ] -> V_306 )
F_120 ( V_294 [ V_3 ] ) ;
F_65 ( V_295 -> V_277 ) ;
}
V_18 -> V_301 = V_301 ;
V_18 -> V_307 = V_299 ;
V_18 -> V_308 = V_300 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_304 && V_294 [ V_3 ] != NULL ; V_3 ++ ) {
V_295 = F_105 ( V_294 [ V_3 ] ) ;
F_64 ( V_295 -> V_277 ) ;
V_294 [ V_3 ] -> V_305 = 0 ;
F_65 ( V_295 -> V_277 ) ;
}
F_121 ( V_18 , V_294 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_94 , strlen ( L_94 ) ) ) {
V_294 = F_119 ( V_18 ) ;
if ( V_294 == NULL )
return - V_102 ;
for ( V_3 = 0 ; V_3 <= V_18 -> V_304 && V_294 [ V_3 ] != NULL ; V_3 ++ ) {
V_295 = F_105 ( V_294 [ V_3 ] ) ;
F_64 ( V_13 -> V_277 ) ;
V_294 [ V_3 ] -> V_305 = 1 ;
F_122 ( V_15 ) ;
V_15 -> V_306 = 0 ;
V_294 [ V_3 ] -> V_305 = 0 ;
F_65 ( V_13 -> V_277 ) ;
}
F_121 ( V_18 , V_294 ) ;
V_18 -> V_301 = V_309 ;
V_18 -> V_307 = 0 ;
V_18 -> V_308 = 0 ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_95 , strlen ( L_95 ) ) ) {
if ( V_18 -> V_301 == V_309 )
return - V_88 ;
F_64 ( V_13 -> V_277 ) ;
if ( V_15 -> V_306 ) {
F_65 ( V_13 -> V_277 ) ;
return strlen ( V_9 ) ;
}
F_123 ( V_15 ) ;
V_15 -> V_306 = 1 ;
F_65 ( V_13 -> V_277 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_96 , strlen ( L_96 ) ) ) {
F_64 ( V_13 -> V_277 ) ;
if ( V_15 -> V_306 == 0 ) {
F_65 ( V_13 -> V_277 ) ;
return strlen ( V_9 ) ;
}
F_122 ( V_15 ) ;
V_15 -> V_306 = 0 ;
F_65 ( V_13 -> V_277 ) ;
return strlen ( V_9 ) ;
}
if ( ! strncmp ( V_9 , L_97 , strlen ( L_97 ) ) ) {
if ( ( V_18 -> V_301 == V_309 )
|| ! V_15 -> V_306 )
return strlen ( V_9 ) ;
F_64 ( V_13 -> V_277 ) ;
V_15 -> V_305 = 1 ;
F_120 ( V_15 ) ;
V_15 -> V_305 = 0 ;
F_65 ( V_13 -> V_277 ) ;
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
int V_310 = 0 ;
int V_3 ;
char * V_301 ;
unsigned long V_311 ;
switch ( V_18 -> V_301 ) {
case V_302 :
V_301 = L_92 ;
break;
case V_303 :
V_301 = L_93 ;
break;
default:
V_301 = L_98 ;
break;
}
sprintf ( & V_9 [ V_310 ] , L_99
L_100
L_101 ,
V_15 -> V_306 , V_15 -> V_305 ,
V_301 , V_18 -> V_307 , V_18 -> V_308 ) ;
V_310 = strlen ( V_9 ) ;
if ( V_18 -> V_301 != V_309 ) {
for ( V_3 = 0 ; V_3 < V_312 ; V_3 ++ ) {
if ( V_18 -> V_301 == V_302 )
V_311 = V_18 -> V_307 +
V_18 -> V_308 * V_3 ;
else
V_311 = V_18 -> V_307 +
( 1 << V_3 ) * V_18 -> V_308 ;
if ( V_310 + 10 > V_10 )
break;
sprintf ( & V_9 [ V_310 ] , L_102 , V_311 ) ;
V_310 = strlen ( V_9 ) ;
}
}
sprintf ( & V_9 [ V_310 ] , L_1 ) ;
return strlen ( V_9 ) ;
}
static T_1
F_125 ( struct V_313 * V_314 , struct V_315 * V_316 ,
struct V_317 * V_318 ,
char * V_9 , T_11 V_319 , T_5 V_86 )
{
struct V_5 * V_6 = F_126 ( V_316 , struct V_5 ,
V_316 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_3 = 0 , V_310 = 0 ;
unsigned long V_320 ;
struct V_275 * V_276 = NULL ;
V_320 = ( unsigned long ) V_319 /
V_321 ;
if ( ! V_15 -> V_306 || V_15 -> V_305
|| ( V_18 -> V_301 == V_309 ) )
return 0 ;
F_64 ( V_13 -> V_277 ) ;
F_106 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_107 ( V_276 ) || ! V_276 -> V_322 )
continue;
if ( V_320 > 0 ) {
V_320 -- ;
continue;
}
if ( ( V_310 + V_321 )
> V_86 )
break;
if ( ! V_276 -> V_322 )
continue;
sprintf ( & V_9 [ V_310 ] , L_103 ,
V_276 -> V_323 . V_103 . V_227 [ 0 ] ,
V_276 -> V_323 . V_103 . V_227 [ 1 ] ,
V_276 -> V_323 . V_103 . V_227 [ 2 ] ,
V_276 -> V_323 . V_103 . V_227 [ 3 ] ,
V_276 -> V_323 . V_103 . V_227 [ 4 ] ,
V_276 -> V_323 . V_103 . V_227 [ 5 ] ,
V_276 -> V_323 . V_103 . V_227 [ 6 ] ,
V_276 -> V_323 . V_103 . V_227 [ 7 ] ) ;
V_310 = strlen ( V_9 ) ;
for ( V_3 = 0 ; V_3 < V_312 ; V_3 ++ ) {
sprintf ( & V_9 [ V_310 ] , L_104 ,
V_276 -> V_322 [ V_3 ] . V_324 ) ;
V_310 = strlen ( V_9 ) ;
}
sprintf ( & V_9 [ V_310 ] , L_1 ) ;
V_310 = strlen ( V_9 ) ;
}
F_65 ( V_13 -> V_277 ) ;
return V_310 ;
}
static T_1
F_127 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_214 = V_325 ;
int V_283 = 0 ;
const char * V_284 = V_9 ;
int V_285 ;
T_2 V_286 ;
if ( ! strncmp ( V_9 , L_85 , strlen ( L_85 ) ) ) {
V_283 = 1 ;
V_284 = & V_9 [ strlen ( L_85 ) ] ;
}
if ( ! isdigit ( V_284 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_284 , L_53 , & V_214 ) != 1 )
return - V_88 ;
F_53 ( V_15 , V_117 , V_135 ,
L_105 ,
V_18 -> V_114 , V_214 , V_283 ? L_106 : L_107 ) ;
if ( ( ( V_214 == V_326 ) && ! ( V_18 -> V_327 & V_328 ) ) ||
( ( V_214 == V_329 ) && ! ( V_18 -> V_327 & V_330 ) ) ||
( ( V_214 == V_331 ) && ! ( V_18 -> V_327 & V_332 ) ) ||
( ( V_214 == V_333 ) && ! ( V_18 -> V_327 & V_334 ) ) ||
( ( V_214 == V_335 ) && ! ( V_18 -> V_327 & V_336 ) ) ||
( ( V_214 == V_287 ) && ! ( V_18 -> V_327 & V_337 ) ) ) {
F_31 ( V_18 , V_117 , V_135 ,
L_108
L_109 ,
V_214 ) ;
return - V_88 ;
}
if ( V_214 == V_287 &&
V_18 -> V_74 == V_75 ) {
F_31 ( V_18 , V_117 , V_135 ,
L_110
L_111 ,
V_214 ) ;
return - V_88 ;
}
if ( ( V_214 >= 0 ) && ( V_214 <= V_338 ) &&
( V_339 & ( 1 << V_214 ) ) ) {
V_286 = V_18 -> V_114 ;
V_18 -> V_114 = V_214 ;
if ( V_283 )
return strlen ( V_9 ) ;
V_285 = F_27 ( F_105 ( V_18 -> V_138 ) ) ;
if ( V_285 ) {
V_18 -> V_114 = V_286 ;
return - V_88 ;
} else
return strlen ( V_9 ) ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_112
L_113 V_340 L_114 , V_214 ) ;
return - V_88 ;
}
static int
F_128 ( struct V_17 * V_18 , int V_214 )
{
if ( V_214 == V_287 && V_18 -> V_113 == 4 ) {
F_31 ( V_18 , V_117 , V_135 ,
L_115
L_116 ,
V_214 ) ;
V_18 -> V_113 = 0 ;
}
if ( ( V_214 >= 0 ) && ( V_214 <= V_338 ) &&
( V_339 & ( 1 << V_214 ) ) ) {
V_18 -> V_114 = V_214 ;
return 0 ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_117
L_118
L_119 V_340 L_114 , V_214 ) ;
V_18 -> V_114 = V_325 ;
return - V_88 ;
}
static T_1
F_129 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_214 = 0 , V_129 = - V_88 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_214 ) != 1 )
return - V_88 ;
switch ( V_214 ) {
case 0 :
if ( V_18 -> V_19 & V_341 ) {
V_129 = F_130 ( V_18 -> V_153 ) ;
if ( ! V_129 ) {
F_64 ( & V_18 -> V_215 ) ;
V_18 -> V_19 &= ~ V_341 ;
F_65 ( & V_18 -> V_215 ) ;
V_18 -> V_342 = 0 ;
V_129 = strlen ( V_9 ) ;
} else
V_129 = - V_99 ;
} else {
V_18 -> V_342 = 0 ;
V_129 = strlen ( V_9 ) ;
}
break;
case 1 :
if ( ! ( V_18 -> V_19 & V_341 ) ) {
V_129 = F_131 ( V_18 -> V_153 ) ;
if ( ! V_129 ) {
F_64 ( & V_18 -> V_215 ) ;
V_18 -> V_19 |= V_341 ;
F_65 ( & V_18 -> V_215 ) ;
V_18 -> V_342 = 1 ;
V_129 = strlen ( V_9 ) ;
} else
V_129 = - V_99 ;
} else {
V_18 -> V_342 = 1 ;
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
F_132 ( struct V_17 * V_18 , int V_214 )
{
if ( V_214 == 0 || V_214 == 1 ) {
V_18 -> V_342 = V_214 ;
return 0 ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_120
L_121
L_122 , V_214 ) ;
V_18 -> V_342 = 1 ;
return - V_88 ;
}
static T_1
F_133 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_5 V_86 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_214 , V_129 = - 1 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_214 ) != 1 )
return - V_88 ;
if ( V_214 != 1 )
return - V_88 ;
if ( V_18 -> V_19 & V_341 )
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
int V_214 = 0 , V_129 = - V_88 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_214 ) != 1 )
return - V_88 ;
if ( V_214 < 0 )
return - V_88 ;
if ( V_214 == 0 ) {
if ( V_18 -> V_162 > 0 ) {
F_46 ( V_152 ) ;
V_18 -> V_162 = 0 ;
}
return strlen ( V_9 ) ;
}
if ( V_18 -> V_162 > 0 ) {
F_31 ( V_18 , V_117 , V_135 ,
L_123
L_124 ,
V_18 -> V_162 ) ;
return - V_343 ;
}
if ( V_214 <= V_344 )
V_18 -> V_162 = V_214 ;
else {
F_31 ( V_18 , V_117 , V_135 ,
L_125
L_126 , V_214 ) ;
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
F_136 ( struct V_17 * V_18 , int V_214 )
{
if ( V_214 >= 0 && V_214 <= V_344 ) {
V_18 -> V_162 = V_214 ;
return 0 ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_127
L_126 , V_214 ) ;
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
int V_214 = 0 , V_129 = - V_88 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_214 ) != 1 )
return - V_88 ;
if ( V_214 != 1 )
return - V_88 ;
V_129 = F_138 ( V_18 , V_345 ) ;
if ( V_129 )
V_129 = - V_99 ;
else
V_129 = strlen ( V_9 ) ;
return V_129 ;
}
static int
F_139 ( struct V_17 * V_18 , int V_214 )
{
if ( V_214 >= 0 && V_214 <= 1 ) {
V_18 -> V_346 = V_214 ;
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
int V_214 = 0 , V_3 ;
if ( V_18 -> V_44 != V_45 )
return - V_88 ;
if ( ! isdigit ( V_9 [ 0 ] ) )
return - V_88 ;
if ( sscanf ( V_9 , L_53 , & V_214 ) != 1 )
return - V_88 ;
if ( V_214 < V_347 || V_214 > V_348 )
return - V_88 ;
V_18 -> V_349 = ( T_2 ) V_214 ;
for ( V_3 = 0 ; V_3 < V_18 -> V_350 ; V_3 += V_351 )
F_141 ( V_18 , V_3 ) ;
return strlen ( V_9 ) ;
}
static int
F_142 ( struct V_17 * V_18 , int V_214 )
{
if ( V_18 -> V_44 != V_45 ) {
V_18 -> V_349 = 0 ;
return 0 ;
}
if ( V_214 >= V_347 && V_214 <= V_348 ) {
V_18 -> V_349 = V_214 ;
return 0 ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_128 , V_214 ) ;
V_18 -> V_349 = V_352 ;
return 0 ;
}
static T_1
F_143 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_353 * V_354 ;
int V_41 = 0 ;
if ( ( V_18 -> V_44 != V_45 ) ||
( V_18 -> V_355 != V_356 ) )
return V_41 ;
switch ( V_18 -> V_357 ) {
case 0 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_129 ,
V_18 -> V_357 ) ;
return V_41 ;
case 1 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_130
L_131 ,
V_18 -> V_357 ,
V_18 -> V_42 . V_358 ) ;
break;
case 2 :
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_132
L_131 ,
V_18 -> V_357 ,
V_18 -> V_42 . V_358 ) ;
break;
}
while ( V_18 -> V_42 . V_359 < V_18 -> V_42 . V_360 ) {
V_354 = & V_18 -> V_42 . V_361 [ V_18 -> V_42 . V_359 ] ;
if ( V_354 -> V_362 == V_363 )
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_133
L_134 ,
V_18 -> V_42 . V_359 ,
V_354 -> V_364 , V_354 -> V_365 ,
V_354 -> V_366 ) ;
else
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 ,
L_133
L_135 ,
V_18 -> V_42 . V_359 ,
V_354 -> V_364 , V_354 -> V_365 ,
V_354 -> V_366 , V_354 -> V_362 ) ;
V_18 -> V_42 . V_359 ++ ;
if ( V_18 -> V_42 . V_359 <
V_18 -> V_42 . V_360 &&
( V_41 >= ( V_10 - 64 ) ) ) {
V_41 += snprintf ( V_9 + V_41 , V_10 - V_41 , L_136 ) ;
break;
}
}
if ( V_18 -> V_42 . V_359 == V_18 -> V_42 . V_360 )
V_18 -> V_42 . V_359 = 0 ;
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
F_145 ( struct V_17 * V_18 , int V_214 )
{
if ( V_18 -> V_44 != V_45 ) {
V_18 -> V_357 = 0 ;
return 0 ;
}
if ( V_214 >= V_367 && V_214 <= V_368 ) {
V_18 -> V_357 = V_214 ;
return 0 ;
}
F_31 ( V_18 , V_117 , V_135 ,
L_137 ,
V_214 ) ;
V_18 -> V_357 = V_369 ;
return 0 ;
}
static int
F_146 ( struct V_14 * V_15 , int V_214 )
{
struct V_12 * V_13 = F_105 ( V_15 ) ;
struct V_275 * V_276 , * V_370 ;
if ( V_214 == V_15 -> V_371 )
return 0 ;
if ( ( V_214 < 0 ) || ( V_214 > 60000 ) )
return - V_88 ;
V_15 -> V_371 = V_214 ;
F_64 ( V_13 -> V_277 ) ;
F_147 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_107 ( V_276 ) )
continue;
if ( V_276 -> V_372 == V_373 )
continue;
V_276 -> V_374 = V_15 -> V_375 ;
}
F_65 ( V_13 -> V_277 ) ;
return 0 ;
}
static T_1
F_148 ( struct V_313 * V_314 , struct V_315 * V_316 ,
struct V_317 * V_318 ,
char * V_9 , T_11 V_319 , T_5 V_86 )
{
T_5 V_376 ;
struct V_5 * V_6 = F_126 ( V_316 , struct V_5 , V_316 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_44 >= V_45 )
return - V_99 ;
if ( ( V_319 + V_86 ) > V_377 )
return - V_378 ;
if ( V_86 <= V_379 )
return 0 ;
if ( V_319 % 4 || V_86 % 4 || ( unsigned long ) V_9 % 4 )
return - V_88 ;
if ( memcmp ( V_9 , V_380 , V_379 ) )
return - V_88 ;
if ( ! ( V_15 -> V_76 & V_97 ) )
return - V_99 ;
F_64 ( & V_18 -> V_215 ) ;
for ( V_376 = 0 ; V_376 < V_86 - V_379 ;
V_376 += sizeof( T_2 ) )
F_48 ( * ( ( T_2 * ) ( V_9 + V_376 + V_379 ) ) ,
V_18 -> V_381 + V_319 + V_376 ) ;
F_65 ( & V_18 -> V_215 ) ;
return V_86 ;
}
static T_1
F_149 ( struct V_313 * V_314 , struct V_315 * V_316 ,
struct V_317 * V_318 ,
char * V_9 , T_11 V_319 , T_5 V_86 )
{
T_5 V_376 ;
T_2 * V_382 ;
struct V_5 * V_6 = F_126 ( V_316 , struct V_5 , V_316 ) ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( V_18 -> V_44 >= V_45 )
return - V_99 ;
if ( V_319 > V_377 )
return - V_378 ;
if ( ( V_319 + V_86 ) > V_377 )
V_86 = V_377 - V_319 ;
if ( V_86 == 0 ) return 0 ;
if ( V_319 % 4 || V_86 % 4 || ( unsigned long ) V_9 % 4 )
return - V_88 ;
F_64 ( & V_18 -> V_215 ) ;
for ( V_376 = 0 ; V_376 < V_86 ; V_376 += sizeof( T_2 ) ) {
V_382 = ( T_2 * ) ( V_9 + V_376 ) ;
* V_382 = F_47 ( V_18 -> V_381 + V_319 + V_376 ) ;
}
F_65 ( & V_18 -> V_215 ) ;
return V_86 ;
}
static T_1
F_150 ( struct V_313 * V_314 , struct V_315 * V_316 ,
struct V_317 * V_318 ,
char * V_9 , T_11 V_319 , T_5 V_86 )
{
return - V_99 ;
}
static T_1
F_151 ( struct V_313 * V_314 , struct V_315 * V_316 ,
struct V_317 * V_318 ,
char * V_9 , T_11 V_319 , T_5 V_86 )
{
return - V_99 ;
}
int
F_152 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_105 ( V_15 ) ;
int error ;
error = F_153 ( & V_13 -> V_383 . V_316 ,
& V_384 ) ;
if ( error || V_15 -> V_208 == V_385 )
goto V_171;
error = F_153 ( & V_13 -> V_383 . V_316 ,
& V_386 ) ;
if ( error )
goto V_387;
error = F_153 ( & V_13 -> V_383 . V_316 ,
& V_388 ) ;
if ( error )
goto V_389;
return 0 ;
V_389:
F_154 ( & V_13 -> V_383 . V_316 , & V_386 ) ;
V_387:
F_154 ( & V_13 -> V_383 . V_316 ,
& V_384 ) ;
V_171:
return error ;
}
void
F_155 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_105 ( V_15 ) ;
F_154 ( & V_13 -> V_383 . V_316 ,
& V_384 ) ;
if ( V_15 -> V_208 == V_385 )
return;
F_154 ( & V_13 -> V_383 . V_316 , & V_388 ) ;
F_154 ( & V_13 -> V_383 . V_316 , & V_386 ) ;
}
static void
F_156 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
F_157 ( V_13 ) = V_15 -> V_390 ;
}
static void
F_158 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_64 ( V_13 -> V_277 ) ;
if ( V_15 -> V_208 == V_385 ) {
F_159 ( V_13 ) = V_391 ;
} else if ( F_160 ( V_18 ) ) {
if ( V_18 -> V_74 == V_75 ) {
if ( V_15 -> V_76 & V_77 )
F_159 ( V_13 ) = V_392 ;
else
F_159 ( V_13 ) = V_393 ;
} else {
if ( V_15 -> V_76 & V_78 )
F_159 ( V_13 ) = V_394 ;
else
F_159 ( V_13 ) = V_395 ;
}
} else
F_159 ( V_13 ) = V_396 ;
F_65 ( V_13 -> V_277 ) ;
}
static void
F_161 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_64 ( V_13 -> V_277 ) ;
if ( V_15 -> V_76 & V_97 )
F_162 ( V_13 ) = V_397 ;
else {
switch ( V_18 -> V_51 ) {
case V_52 :
case V_56 :
F_162 ( V_13 ) = V_398 ;
break;
case V_59 :
case V_60 :
case V_61 :
if ( V_15 -> V_62 < V_71 )
F_162 ( V_13 ) =
V_399 ;
else
F_162 ( V_13 ) =
V_400 ;
break;
case V_57 :
F_162 ( V_13 ) = V_401 ;
break;
default:
F_162 ( V_13 ) = V_402 ;
break;
}
}
F_65 ( V_13 -> V_277 ) ;
}
static void
F_163 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
F_64 ( V_13 -> V_277 ) ;
if ( F_160 ( V_18 ) ) {
switch( V_18 -> V_403 ) {
case V_404 :
F_164 ( V_13 ) = V_405 ;
break;
case V_406 :
F_164 ( V_13 ) = V_407 ;
break;
case V_408 :
F_164 ( V_13 ) = V_409 ;
break;
case V_410 :
F_164 ( V_13 ) = V_411 ;
break;
case V_412 :
F_164 ( V_13 ) = V_413 ;
break;
case V_414 :
F_164 ( V_13 ) = V_415 ;
break;
default:
F_164 ( V_13 ) = V_416 ;
break;
}
} else
F_164 ( V_13 ) = V_416 ;
F_65 ( V_13 -> V_277 ) ;
}
static void
F_165 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
T_12 V_417 ;
F_64 ( V_13 -> V_277 ) ;
if ( ( V_15 -> V_62 > V_65 ) &&
( ( V_15 -> V_76 & V_78 ) ||
( ( V_18 -> V_74 == V_75 ) &&
( V_15 -> V_76 & V_77 ) ) ) )
V_417 = F_77 ( V_18 -> V_418 . V_419 . V_103 . V_227 ) ;
else
V_417 = 0 ;
F_65 ( V_13 -> V_277 ) ;
F_166 ( V_13 ) = V_417 ;
}
static struct V_420 *
F_167 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_126 * V_127 = & V_18 -> V_33 ;
struct V_420 * V_421 = & V_18 -> V_422 ;
struct V_423 * V_424 = & V_127 -> V_425 ;
T_6 * V_94 ;
T_7 * V_186 ;
unsigned long V_426 ;
int V_129 = 0 ;
if ( V_18 -> V_51 < V_56 ||
! V_18 -> V_100 ||
( V_18 -> V_33 . V_34 & V_188 ) == 0 )
return NULL ;
if ( V_18 -> V_33 . V_34 & V_98 )
return NULL ;
V_94 = F_28 ( V_18 -> V_100 , V_101 ) ;
if ( ! V_94 )
return NULL ;
memset ( V_94 , 0 , sizeof ( T_6 ) ) ;
V_186 = & V_94 -> V_103 . V_104 ;
V_186 -> V_105 = V_427 ;
V_186 -> V_107 = V_108 ;
V_94 -> V_190 = NULL ;
V_94 -> V_15 = V_15 ;
if ( V_15 -> V_76 & V_97 )
V_129 = F_168 ( V_18 , V_94 , V_428 ) ;
else
V_129 = F_29 ( V_18 , V_94 , V_18 -> V_115 * 2 ) ;
if ( V_129 != V_110 ) {
if ( V_129 != V_120 )
F_33 ( V_94 , V_18 -> V_100 ) ;
return NULL ;
}
memset ( V_421 , 0 , sizeof ( struct V_420 ) ) ;
V_421 -> V_429 = V_186 -> V_193 . V_430 . V_431 ;
V_421 -> V_432 = ( T_10 )
( ( T_10 ) V_186 -> V_193 . V_430 . V_433
* ( T_10 ) 256 ) ;
V_421 -> V_434 = V_186 -> V_193 . V_430 . V_435 ;
V_421 -> V_436 = ( T_10 )
( ( T_10 ) V_186 -> V_193 . V_430 . V_437
* ( T_10 ) 256 ) ;
memset ( V_94 , 0 , sizeof ( T_6 ) ) ;
V_186 -> V_105 = V_438 ;
V_186 -> V_107 = V_108 ;
V_94 -> V_190 = NULL ;
V_94 -> V_15 = V_15 ;
if ( V_15 -> V_76 & V_97 )
V_129 = F_168 ( V_18 , V_94 , V_428 ) ;
else
V_129 = F_29 ( V_18 , V_94 , V_18 -> V_115 * 2 ) ;
if ( V_129 != V_110 ) {
if ( V_129 != V_120 )
F_33 ( V_94 , V_18 -> V_100 ) ;
return NULL ;
}
V_421 -> V_439 = V_186 -> V_193 . V_440 . V_441 ;
V_421 -> V_442 = V_186 -> V_193 . V_440 . V_443 ;
V_421 -> V_444 = V_186 -> V_193 . V_440 . V_445 ;
V_421 -> V_446 = V_186 -> V_193 . V_440 . V_447 ;
V_421 -> V_448 = V_186 -> V_193 . V_440 . V_449 ;
V_421 -> V_450 = V_186 -> V_193 . V_440 . V_451 ;
V_421 -> V_452 = V_186 -> V_193 . V_440 . V_451 ;
V_421 -> V_439 -= V_424 -> V_439 ;
V_421 -> V_442 -= V_424 -> V_442 ;
V_421 -> V_444 -= V_424 -> V_444 ;
V_421 -> V_446 -= V_424 -> V_446 ;
V_421 -> V_448 -= V_424 -> V_448 ;
V_421 -> V_450 -= V_424 -> V_450 ;
V_421 -> V_452 -= V_424 -> V_452 ;
if ( V_18 -> V_19 & V_453 ) {
V_421 -> V_454 = - 1 ;
V_421 -> V_455 = ( V_18 -> V_456 >> 1 ) ;
V_421 -> V_455 -= V_424 -> V_456 ;
} else if ( V_18 -> V_74 == V_75 ) {
V_421 -> V_454 = ( V_18 -> V_457 >> 1 ) ;
V_421 -> V_454 -= V_424 -> V_456 ;
V_421 -> V_455 = - 1 ;
} else {
V_421 -> V_454 = - 1 ;
V_421 -> V_455 = ( V_18 -> V_457 >> 1 ) ;
V_421 -> V_455 -= V_424 -> V_456 ;
}
V_421 -> V_458 = - 1 ;
V_426 = F_169 () ;
if ( V_426 < V_127 -> V_459 )
V_421 -> V_460 = V_426 +
( ( unsigned long ) - 1 - V_127 -> V_459 ) ;
else
V_421 -> V_460 = V_426 - V_127 -> V_459 ;
F_33 ( V_94 , V_18 -> V_100 ) ;
return V_421 ;
}
static void
F_170 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_126 * V_127 = & V_18 -> V_33 ;
struct V_423 * V_424 = & V_127 -> V_425 ;
T_6 * V_94 ;
T_7 * V_186 ;
int V_129 = 0 ;
if ( V_18 -> V_33 . V_34 & V_98 )
return;
V_94 = F_28 ( V_18 -> V_100 , V_101 ) ;
if ( ! V_94 )
return;
memset ( V_94 , 0 , sizeof( T_6 ) ) ;
V_186 = & V_94 -> V_103 . V_104 ;
V_186 -> V_105 = V_427 ;
V_186 -> V_107 = V_108 ;
V_186 -> V_193 . V_461 [ 0 ] = 0x1 ;
V_94 -> V_190 = NULL ;
V_94 -> V_15 = V_15 ;
if ( ( V_15 -> V_76 & V_97 ) ||
( ! ( V_127 -> V_34 & V_188 ) ) )
V_129 = F_168 ( V_18 , V_94 , V_428 ) ;
else
V_129 = F_29 ( V_18 , V_94 , V_18 -> V_115 * 2 ) ;
if ( V_129 != V_110 ) {
if ( V_129 != V_120 )
F_33 ( V_94 , V_18 -> V_100 ) ;
return;
}
memset ( V_94 , 0 , sizeof( T_6 ) ) ;
V_186 -> V_105 = V_438 ;
V_186 -> V_107 = V_108 ;
V_94 -> V_190 = NULL ;
V_94 -> V_15 = V_15 ;
if ( ( V_15 -> V_76 & V_97 ) ||
( ! ( V_127 -> V_34 & V_188 ) ) )
V_129 = F_168 ( V_18 , V_94 , V_428 ) ;
else
V_129 = F_29 ( V_18 , V_94 , V_18 -> V_115 * 2 ) ;
if ( V_129 != V_110 ) {
if ( V_129 != V_120 )
F_33 ( V_94 , V_18 -> V_100 ) ;
return;
}
V_424 -> V_439 = V_186 -> V_193 . V_440 . V_441 ;
V_424 -> V_442 = V_186 -> V_193 . V_440 . V_443 ;
V_424 -> V_444 = V_186 -> V_193 . V_440 . V_445 ;
V_424 -> V_446 = V_186 -> V_193 . V_440 . V_447 ;
V_424 -> V_448 = V_186 -> V_193 . V_440 . V_449 ;
V_424 -> V_450 = V_186 -> V_193 . V_440 . V_451 ;
V_424 -> V_452 = V_186 -> V_193 . V_440 . V_451 ;
if ( V_18 -> V_19 & V_453 )
V_424 -> V_456 = ( V_18 -> V_456 >> 1 ) ;
else
V_424 -> V_456 = ( V_18 -> V_457 >> 1 ) ;
V_127 -> V_459 = F_169 () ;
F_33 ( V_94 , V_18 -> V_100 ) ;
return;
}
static struct V_275 *
F_171 ( struct V_462 * V_463 )
{
struct V_12 * V_13 = F_172 ( V_463 -> V_6 . V_464 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_275 * V_276 ;
F_64 ( V_13 -> V_277 ) ;
F_106 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( F_107 ( V_276 ) &&
V_276 -> V_372 == V_465 &&
V_463 -> V_466 == V_276 -> V_467 ) {
F_65 ( V_13 -> V_277 ) ;
return V_276 ;
}
}
F_65 ( V_13 -> V_277 ) ;
return NULL ;
}
static void
F_173 ( struct V_462 * V_463 )
{
struct V_275 * V_276 = F_171 ( V_463 ) ;
F_174 ( V_463 ) = V_276 ? V_276 -> V_468 : - 1 ;
}
static void
F_175 ( struct V_462 * V_463 )
{
struct V_275 * V_276 = F_171 ( V_463 ) ;
F_176 ( V_463 ) =
V_276 ? F_77 ( V_276 -> V_469 . V_103 . V_227 ) : 0 ;
}
static void
F_177 ( struct V_462 * V_463 )
{
struct V_275 * V_276 = F_171 ( V_463 ) ;
F_178 ( V_463 ) =
V_276 ? F_77 ( V_276 -> V_323 . V_103 . V_227 ) : 0 ;
}
static void
F_179 ( struct V_470 * V_278 , T_2 V_471 )
{
if ( V_471 )
V_278 -> V_279 = V_471 ;
else
V_278 -> V_279 = 1 ;
}
static void
F_180 ( struct V_472 * V_472 )
{
struct V_14 * V_15 = * (struct V_14 * * ) V_472 -> V_473 ;
if ( V_15 -> V_62 == V_71 )
F_181 ( V_15 , V_474 , 0 , 0 ) ;
}
static void
F_182 ( struct V_17 * V_18 , T_2 V_475 )
{
V_18 -> V_476 = V_475 ;
}
void
F_183 ( struct V_17 * V_18 )
{
F_184 ( V_18 , V_477 ) ;
F_185 ( V_18 , V_478 ) ;
F_186 ( V_18 , V_479 ) ;
F_187 ( V_18 , V_480 ) ;
F_188 ( V_18 , V_481 ) ;
F_189 ( V_18 , V_482 ) ;
F_190 ( V_18 , V_483 ) ;
F_191 ( V_18 , V_484 ) ;
F_192 ( V_18 , V_485 ) ;
F_128 ( V_18 , V_486 ) ;
F_193 ( V_18 , V_487 ) ;
F_194 ( V_18 , V_488 ) ;
F_195 ( V_18 , V_489 ) ;
F_196 ( V_18 , V_490 ) ;
F_197 ( V_18 , V_491 ) ;
F_198 ( V_18 , V_492 ) ;
F_142 ( V_18 , V_493 ) ;
F_145 ( V_18 , V_494 ) ;
F_199 ( V_18 , V_495 ) ;
F_200 ( V_18 , V_496 ) ;
F_201 ( V_18 , V_497 ) ;
F_202 ( V_18 , V_498 ) ;
if ( V_18 -> V_44 != V_45 )
V_18 -> V_242 = 0 ;
F_203 ( V_18 , V_499 ) ;
memset ( V_18 -> V_241 , 0 , ( 8 * sizeof( T_3 ) ) ) ;
memset ( V_18 -> V_249 , 0 , ( 8 * sizeof( T_3 ) ) ) ;
V_18 -> V_252 = 0 ;
V_18 -> V_254 = 0 ;
V_18 -> V_244 = 0 ;
F_204 ( V_18 , V_500 ) ;
if ( V_18 -> V_44 == V_45 )
V_18 -> V_211 = 0 ;
else
V_18 -> V_211 = V_501 ;
V_18 -> V_237 = 0L ;
V_18 -> V_231 = 0L ;
F_205 ( V_18 , V_502 ) ;
F_206 ( V_18 , V_503 ) ;
F_207 ( V_18 , V_504 ) ;
F_182 ( V_18 , V_505 ) ;
F_132 ( V_18 , V_506 ) ;
F_136 ( V_18 , V_507 ) ;
F_139 ( V_18 , V_508 ) ;
F_208 ( V_18 , V_509 ) ;
F_209 ( V_18 , V_510 ) ;
V_18 -> V_224 = 1 ;
return;
}
void
F_210 ( struct V_14 * V_15 )
{
F_211 ( V_15 , V_505 ) ;
F_212 ( V_15 , V_511 ) ;
F_213 ( V_15 , V_512 ) ;
F_214 ( V_15 , V_281 ) ;
F_103 ( V_15 , V_513 ) ;
F_215 ( V_15 , V_514 ) ;
F_111 ( V_15 , V_515 ) ;
F_216 ( V_15 , V_516 ) ;
F_217 ( V_15 , V_517 ) ;
F_218 ( V_15 , V_518 ) ;
F_219 ( V_15 , V_519 ) ;
F_220 ( V_15 , V_520 ) ;
F_221 ( V_15 , V_521 ) ;
F_222 ( V_15 , V_522 ) ;
F_223 ( V_15 , V_523 ) ;
F_224 ( V_15 , V_524 ) ;
return;
}
