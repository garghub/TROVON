static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
short V_5 [ 3 ] ;
V_2 -> V_6 -> V_7 ( V_2 -> V_8 , V_9 , V_10 - V_9 + 1 , V_5 ) ;
F_2 ( & V_2 -> V_11 ) ;
V_2 -> V_12 . V_13 = ( V_14 ) F_3 ( V_5 [ 0 ] ) ;
V_4 -> V_13 = V_2 -> V_12 . V_13 ;
V_2 -> V_12 . V_15 = ( V_14 ) F_3 ( V_5 [ 1 ] ) ;
V_4 -> V_15 = V_2 -> V_12 . V_15 ;
V_2 -> V_12 . V_16 = ( V_14 ) F_3 ( V_5 [ 2 ] ) ;
V_4 -> V_16 = V_2 -> V_12 . V_16 ;
F_4 ( & V_2 -> V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
struct V_3 V_4 ;
F_1 ( V_2 , & V_4 ) ;
F_6 ( V_2 -> V_19 , V_18 -> V_20 , V_18 -> V_21 ,
V_4 . V_13 - V_2 -> V_22 . V_13 ) ;
F_6 ( V_2 -> V_19 , V_18 -> V_20 , V_18 -> V_23 ,
V_4 . V_15 - V_2 -> V_22 . V_15 ) ;
F_6 ( V_2 -> V_19 , V_18 -> V_20 , V_18 -> V_24 ,
V_4 . V_16 - V_2 -> V_22 . V_16 ) ;
}
static void F_7 ( struct V_25 * V_19 , int V_26 )
{
F_8 ( V_19 , V_26 , true ) ;
F_9 ( V_19 ) ;
F_8 ( V_19 , V_26 , false ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_17 * V_18 , int V_27 , int V_28 )
{
int V_29 ;
for ( V_29 = V_30 ; V_29 <= V_31 ; V_29 ++ ) {
if ( V_27 & ( 1 << ( V_31 - V_29 ) ) )
F_8 ( V_2 -> V_19 ,
V_18 -> V_32 [ V_29 ] , V_28 ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_17 * V_18 , int V_27 )
{
F_10 ( V_2 , V_18 , V_27 , true ) ;
F_9 ( V_2 -> V_19 ) ;
F_10 ( V_2 , V_18 , V_27 , false ) ;
}
static T_1 F_12 ( int V_33 , void * V_34 )
{
struct V_1 * V_2 = V_34 ;
struct V_17 * V_18 = & V_2 -> V_18 ;
int V_35 , V_36 , V_37 , V_38 , V_39 ;
if ( V_18 -> V_40 & ( V_41 | V_42 | V_43 ) )
V_36 = F_13 ( V_2 , V_44 ) ;
else
V_36 = 0 ;
V_35 = F_13 ( V_2 , V_45 ) ;
if ( V_35 & V_46 )
F_7 ( V_2 -> V_19 , V_18 -> V_47 ) ;
if ( V_35 & V_48 )
F_14 ( V_2 -> V_8 , L_1 ) ;
if ( V_35 & ( V_49 | V_50 ) ) {
F_11 ( V_2 , V_18 , V_36 ) ;
if ( V_35 & V_50 )
F_11 ( V_2 , V_18 , V_36 ) ;
}
if ( V_18 -> V_51 ) {
if ( V_35 & V_52 )
F_8 ( V_2 -> V_19 ,
V_18 -> V_51 , 1 ) ;
if ( V_35 & V_53 )
F_8 ( V_2 -> V_19 ,
V_18 -> V_51 , 0 ) ;
}
if ( V_18 -> V_54 ) {
V_38 = F_13 ( V_2 , V_55 ) ;
if ( ( V_18 -> V_54 & V_56 ) &&
( V_38 & V_57 ) ) {
V_39 = F_15 ( V_38 ) ;
if ( V_2 -> V_58 != V_39 ) {
V_2 -> V_58 = V_39 ;
F_7 ( V_2 -> V_19 ,
V_18 -> V_59 [ V_39 ] ) ;
}
}
if ( ( V_18 -> V_54 & V_60 ) &&
( V_38 & V_61 ) ) {
V_39 = F_16 ( V_38 ) - 1 ;
if ( V_2 -> V_62 != V_39 ) {
V_2 -> V_62 = V_39 ;
F_7 ( V_2 -> V_19 ,
V_18 -> V_63 [ V_39 ] ) ;
}
}
}
if ( V_35 & ( V_64 | V_65 ) ) {
if ( V_18 -> V_66 )
V_37 = F_17 ( F_13 ( V_2 , V_67 ) ) + 1 ;
else
V_37 = 1 ;
for (; V_37 > 0 ; V_37 -- ) {
F_5 ( V_2 ) ;
if ( V_2 -> V_68 && ( V_37 > 1 ) )
F_18 ( 3 ) ;
}
}
F_9 ( V_2 -> V_19 ) ;
return V_69 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_70 , 0 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_70 , V_2 -> V_18 . V_71 | V_72 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_11 ) ;
if ( ! V_2 -> V_73 && ! V_2 -> V_74 && V_2 -> V_75 )
F_19 ( V_2 ) ;
V_2 -> V_73 = true ;
F_4 ( & V_2 -> V_11 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_73 && ! V_2 -> V_74 && V_2 -> V_75 )
F_21 ( V_2 ) ;
V_2 -> V_73 = false ;
F_4 ( & V_2 -> V_11 ) ;
}
static T_2 F_24 ( struct V_76 * V_8 ,
struct V_77 * V_78 , char * V_5 )
{
struct V_1 * V_2 = F_25 ( V_8 ) ;
return sprintf ( V_5 , L_2 , V_2 -> V_74 ) ;
}
static T_2 F_26 ( struct V_76 * V_8 ,
struct V_77 * V_78 ,
const char * V_5 , T_3 V_79 )
{
struct V_1 * V_2 = F_25 ( V_8 ) ;
unsigned long V_80 ;
int error ;
error = F_27 ( V_5 , 10 , & V_80 ) ;
if ( error )
return error ;
F_2 ( & V_2 -> V_11 ) ;
if ( ! V_2 -> V_73 && V_2 -> V_75 ) {
if ( V_80 ) {
if ( ! V_2 -> V_74 )
F_19 ( V_2 ) ;
} else {
if ( V_2 -> V_74 )
F_21 ( V_2 ) ;
}
}
V_2 -> V_74 = ! ! V_80 ;
F_4 ( & V_2 -> V_11 ) ;
return V_79 ;
}
static T_2 F_28 ( struct V_76 * V_8 ,
struct V_77 * V_78 , char * V_5 )
{
struct V_1 * V_2 = F_25 ( V_8 ) ;
T_2 V_79 ;
F_2 ( & V_2 -> V_11 ) ;
V_79 = sprintf ( V_5 , L_3 ,
V_2 -> V_81 . V_13 * 4 + V_2 -> V_22 . V_13 ,
V_2 -> V_81 . V_15 * 4 + V_2 -> V_22 . V_15 ,
V_2 -> V_81 . V_16 * 4 + V_2 -> V_22 . V_16 ) ;
F_4 ( & V_2 -> V_11 ) ;
return V_79 ;
}
static T_2 F_29 ( struct V_76 * V_8 ,
struct V_77 * V_78 ,
const char * V_5 , T_3 V_79 )
{
struct V_1 * V_2 = F_25 ( V_8 ) ;
F_2 ( & V_2 -> V_11 ) ;
V_2 -> V_81 . V_13 -= ( V_2 -> V_12 . V_13 / 4 ) ;
V_2 -> V_22 . V_13 = V_2 -> V_12 . V_13 % 4 ;
V_2 -> V_81 . V_15 -= ( V_2 -> V_12 . V_15 / 4 ) ;
V_2 -> V_22 . V_15 = V_2 -> V_12 . V_15 % 4 ;
V_2 -> V_81 . V_16 -= ( V_2 -> V_12 . V_16 / 4 ) ;
V_2 -> V_22 . V_16 = V_2 -> V_12 . V_16 % 4 ;
F_20 ( V_2 , V_82 , ( V_83 ) V_2 -> V_81 . V_13 ) ;
F_20 ( V_2 , V_84 , ( V_83 ) V_2 -> V_81 . V_15 ) ;
F_20 ( V_2 , V_85 , ( V_83 ) V_2 -> V_81 . V_16 ) ;
F_4 ( & V_2 -> V_11 ) ;
return V_79 ;
}
static T_2 F_30 ( struct V_76 * V_8 ,
struct V_77 * V_78 , char * V_5 )
{
struct V_1 * V_2 = F_25 ( V_8 ) ;
return sprintf ( V_5 , L_2 , F_31 ( V_2 -> V_18 . V_86 ) ) ;
}
static T_2 F_32 ( struct V_76 * V_8 ,
struct V_77 * V_78 ,
const char * V_5 , T_3 V_79 )
{
struct V_1 * V_2 = F_25 ( V_8 ) ;
unsigned long V_80 ;
int error ;
error = F_27 ( V_5 , 10 , & V_80 ) ;
if ( error )
return error ;
F_2 ( & V_2 -> V_11 ) ;
V_2 -> V_18 . V_86 = F_31 ( V_80 ) ;
F_20 ( V_2 , V_87 ,
V_2 -> V_18 . V_86 |
( V_2 -> V_18 . V_88 ? V_89 : 0 ) ) ;
F_4 ( & V_2 -> V_11 ) ;
return V_79 ;
}
static T_2 F_33 ( struct V_76 * V_8 ,
struct V_77 * V_78 , char * V_5 )
{
struct V_1 * V_2 = F_25 ( V_8 ) ;
return sprintf ( V_5 , L_2 ,
V_2 -> V_18 . V_71 & ( V_90 | V_91 ) ? 1 : 0 ) ;
}
static T_2 F_34 ( struct V_76 * V_8 ,
struct V_77 * V_78 ,
const char * V_5 , T_3 V_79 )
{
struct V_1 * V_2 = F_25 ( V_8 ) ;
unsigned long V_80 ;
int error ;
error = F_27 ( V_5 , 10 , & V_80 ) ;
if ( error )
return error ;
F_2 ( & V_2 -> V_11 ) ;
if ( V_80 )
V_2 -> V_18 . V_71 |= ( V_90 | V_91 ) ;
else
V_2 -> V_18 . V_71 &= ~ ( V_90 | V_91 ) ;
if ( ! V_2 -> V_74 && ! V_2 -> V_73 && V_2 -> V_75 )
F_20 ( V_2 , V_70 , V_2 -> V_18 . V_71 | V_72 ) ;
F_4 ( & V_2 -> V_11 ) ;
return V_79 ;
}
static T_2 F_35 ( struct V_76 * V_8 ,
struct V_77 * V_78 , char * V_5 )
{
struct V_1 * V_2 = F_25 ( V_8 ) ;
T_2 V_79 ;
F_2 ( & V_2 -> V_11 ) ;
V_79 = sprintf ( V_5 , L_4 ,
V_2 -> V_12 . V_13 , V_2 -> V_12 . V_15 , V_2 -> V_12 . V_16 ) ;
F_4 ( & V_2 -> V_11 ) ;
return V_79 ;
}
static T_2 F_36 ( struct V_76 * V_8 ,
struct V_77 * V_78 ,
const char * V_5 , T_3 V_79 )
{
struct V_1 * V_2 = F_25 ( V_8 ) ;
unsigned long V_80 ;
int error ;
error = F_27 ( V_5 , 16 , & V_80 ) ;
if ( error )
return error ;
F_2 ( & V_2 -> V_11 ) ;
F_20 ( V_2 , V_80 >> 8 , V_80 & 0xFF ) ;
F_4 ( & V_2 -> V_11 ) ;
return V_79 ;
}
static int F_37 ( struct V_25 * V_19 )
{
struct V_1 * V_2 = F_38 ( V_19 ) ;
F_2 ( & V_2 -> V_11 ) ;
if ( ! V_2 -> V_73 && ! V_2 -> V_74 )
F_21 ( V_2 ) ;
V_2 -> V_75 = true ;
F_4 ( & V_2 -> V_11 ) ;
return 0 ;
}
static void F_39 ( struct V_25 * V_19 )
{
struct V_1 * V_2 = F_38 ( V_19 ) ;
F_2 ( & V_2 -> V_11 ) ;
if ( ! V_2 -> V_73 && ! V_2 -> V_74 )
F_19 ( V_2 ) ;
V_2 -> V_75 = false ;
F_4 ( & V_2 -> V_11 ) ;
}
struct V_1 * F_40 ( struct V_76 * V_8 , int V_33 ,
bool V_92 ,
const struct V_93 * V_6 )
{
struct V_1 * V_2 ;
struct V_25 * V_25 ;
const struct V_17 * V_18 ;
int V_94 , V_95 , V_29 ;
unsigned char V_96 ;
if ( ! V_33 ) {
F_41 ( V_8 , L_5 ) ;
V_94 = - V_97 ;
goto V_98;
}
V_2 = F_42 ( sizeof( * V_2 ) , V_99 ) ;
V_25 = F_43 () ;
if ( ! V_2 || ! V_25 ) {
V_94 = - V_100 ;
goto V_101;
}
V_2 -> V_68 = V_92 ;
V_18 = V_8 -> V_102 ;
if ( ! V_18 ) {
F_14 ( V_8 ,
L_6 ) ;
V_18 = & V_103 ;
}
V_2 -> V_18 = * V_18 ;
V_18 = & V_2 -> V_18 ;
V_2 -> V_19 = V_25 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_6 = V_6 ;
F_44 ( & V_2 -> V_11 ) ;
V_25 -> V_104 = L_7 ;
V_96 = V_2 -> V_6 -> V_105 ( V_8 , V_106 ) ;
switch ( V_96 ) {
case V_107 :
V_2 -> V_108 = 345 ;
break;
case V_109 :
V_2 -> V_108 = 346 ;
break;
default:
F_41 ( V_8 , L_8 , V_25 -> V_104 ) ;
V_94 = - V_97 ;
goto V_101;
}
snprintf ( V_2 -> V_110 , sizeof( V_2 -> V_110 ) , L_9 , F_45 ( V_8 ) ) ;
V_25 -> V_110 = V_2 -> V_110 ;
V_25 -> V_8 . V_111 = V_8 ;
V_25 -> V_112 . V_113 = V_2 -> V_108 ;
V_25 -> V_112 . V_114 = V_6 -> V_114 ;
V_25 -> V_115 = F_37 ;
V_25 -> V_116 = F_39 ;
F_46 ( V_25 , V_2 ) ;
F_47 ( V_2 -> V_18 . V_20 , V_25 -> V_117 ) ;
if ( V_2 -> V_18 . V_20 == V_118 ) {
F_47 ( V_119 , V_25 -> V_120 ) ;
F_47 ( V_121 , V_25 -> V_120 ) ;
F_47 ( V_122 , V_25 -> V_120 ) ;
} else {
F_47 ( V_123 , V_25 -> V_124 ) ;
F_47 ( V_125 , V_25 -> V_124 ) ;
F_47 ( V_126 , V_25 -> V_124 ) ;
if ( V_18 -> V_127 & V_128 )
V_95 = V_129 ;
else
V_95 = V_130 ;
F_48 ( V_25 , V_123 , - V_95 , V_95 , 3 , 3 ) ;
F_48 ( V_25 , V_125 , - V_95 , V_95 , 3 , 3 ) ;
F_48 ( V_25 , V_126 , - V_95 , V_95 , 3 , 3 ) ;
}
F_47 ( V_131 , V_25 -> V_117 ) ;
F_47 ( V_18 -> V_32 [ V_30 ] , V_25 -> V_132 ) ;
F_47 ( V_18 -> V_32 [ V_133 ] , V_25 -> V_132 ) ;
F_47 ( V_18 -> V_32 [ V_31 ] , V_25 -> V_132 ) ;
if ( V_18 -> V_47 ) {
V_2 -> V_134 = V_46 ;
F_47 ( V_18 -> V_47 , V_25 -> V_132 ) ;
}
if ( V_18 -> V_51 )
F_47 ( V_18 -> V_51 , V_25 -> V_132 ) ;
V_2 -> V_134 |= V_52 | V_53 ;
if ( V_18 -> V_135 ) {
V_2 -> V_134 |= V_65 ;
if ( ! F_49 ( V_18 -> V_66 ) )
V_2 -> V_18 . V_66 |= V_136 ;
} else {
V_2 -> V_134 |= V_64 ;
}
if ( V_18 -> V_40 & ( V_41 | V_42 | V_43 ) )
V_2 -> V_134 |= V_49 | V_50 ;
if ( F_49 ( V_18 -> V_66 ) == V_137 )
V_2 -> V_68 = false ;
V_2 -> V_6 -> V_138 ( V_8 , V_70 , 0 ) ;
V_94 = F_50 ( V_2 -> V_33 , NULL , F_12 ,
V_139 | V_140 ,
F_45 ( V_8 ) , V_2 ) ;
if ( V_94 ) {
F_41 ( V_8 , L_10 , V_2 -> V_33 ) ;
goto V_101;
}
V_94 = F_51 ( & V_8 -> V_141 , & V_142 ) ;
if ( V_94 )
goto V_143;
V_94 = F_52 ( V_25 ) ;
if ( V_94 )
goto V_144;
F_20 ( V_2 , V_145 , V_18 -> V_146 ) ;
F_20 ( V_2 , V_82 , V_18 -> V_147 ) ;
V_2 -> V_81 . V_13 = V_18 -> V_147 ;
F_20 ( V_2 , V_84 , V_18 -> V_148 ) ;
V_2 -> V_81 . V_15 = V_18 -> V_148 ;
F_20 ( V_2 , V_85 , V_18 -> V_149 ) ;
V_2 -> V_81 . V_16 = V_18 -> V_149 ;
F_20 ( V_2 , V_145 , V_18 -> V_146 ) ;
F_20 ( V_2 , V_150 , V_18 -> V_151 ) ;
F_20 ( V_2 , V_152 , V_18 -> V_153 ) ;
F_20 ( V_2 , V_154 , V_18 -> V_155 ) ;
F_20 ( V_2 , V_156 , V_18 -> V_157 ) ;
F_20 ( V_2 , V_158 , V_18 -> V_159 ) ;
F_20 ( V_2 , V_160 , V_18 -> V_161 ) ;
F_20 ( V_2 , V_162 , V_18 -> V_163 ) ;
F_20 ( V_2 , V_164 , V_18 -> V_165 ) ;
F_20 ( V_2 , V_166 , V_18 -> V_40 ) ;
F_20 ( V_2 , V_167 , V_18 -> V_168 ) ;
F_20 ( V_2 , V_87 , F_31 ( V_2 -> V_18 . V_86 ) |
( V_18 -> V_88 ? V_89 : 0 ) ) ;
F_20 ( V_2 , V_169 , V_18 -> V_127 ) ;
F_20 ( V_2 , V_170 , F_49 ( V_18 -> V_66 ) |
F_53 ( V_18 -> V_135 ) ) ;
if ( V_18 -> V_171 ) {
F_20 ( V_2 , V_172 , V_2 -> V_134 | V_48 ) ;
} else {
F_20 ( V_2 , V_172 , 0 ) ;
}
if ( V_2 -> V_108 == 346 && V_2 -> V_18 . V_54 ) {
F_20 ( V_2 , V_173 ,
F_54 ( V_2 -> V_18 . V_174 ) |
F_55 ( V_2 -> V_18 . V_175 ) ) ;
V_2 -> V_58 = 1234 ;
V_2 -> V_62 = 1234 ;
if ( V_18 -> V_54 & V_60 )
for ( V_29 = 0 ; V_29 < F_56 ( V_18 -> V_63 ) ; V_29 ++ )
F_47 ( V_18 -> V_63 [ V_29 ] ,
V_25 -> V_132 ) ;
if ( V_18 -> V_54 & V_56 )
for ( V_29 = 0 ; V_29 < F_56 ( V_18 -> V_59 ) ; V_29 ++ )
F_47 ( V_18 -> V_59 [ V_29 ] ,
V_25 -> V_132 ) ;
} else {
V_2 -> V_18 . V_54 = 0 ;
}
F_20 ( V_2 , V_176 , V_2 -> V_134 | V_48 ) ;
V_2 -> V_18 . V_71 &= ( V_90 | V_91 ) ;
return V_2 ;
V_144:
F_57 ( & V_8 -> V_141 , & V_142 ) ;
V_143:
F_58 ( V_2 -> V_33 , V_2 ) ;
V_101:
F_59 ( V_25 ) ;
F_60 ( V_2 ) ;
V_98:
return F_61 ( V_94 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
F_57 ( & V_2 -> V_8 -> V_141 , & V_142 ) ;
F_58 ( V_2 -> V_33 , V_2 ) ;
F_63 ( V_2 -> V_19 ) ;
F_14 ( V_2 -> V_8 , L_11 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
