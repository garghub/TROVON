static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
T_1 V_7 = V_8 ;
T_3 V_9 ;
T_3 V_10 = 0 ;
V_9 = F_2 ( & V_6 -> V_9 ) & V_11 ;
if ( V_9 & V_12 ) {
V_4 -> V_13 . V_14 ++ ;
V_10 |= V_12 ;
V_7 = V_15 ;
}
if ( V_9 & V_16 ) {
V_4 -> V_13 . V_17 ++ ;
V_10 |= V_16 ;
V_7 = V_15 ;
}
if ( V_9 & V_18 ) {
V_4 -> V_13 . V_19 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_20 ) {
V_4 -> V_13 . V_21 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_22 ) {
V_4 -> V_13 . V_23 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_24 ) {
V_4 -> V_13 . V_25 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_26 ) {
V_4 -> V_13 . V_27 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_28 ) {
V_4 -> V_13 . V_29 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_30 ) {
V_4 -> V_13 . V_31 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_32 ) {
V_4 -> V_13 . V_33 ++ ;
V_10 |= V_32 ;
V_7 = V_15 ;
}
if ( V_9 & V_34 ) {
V_4 -> V_13 . V_35 ++ ;
V_10 |= V_34 ;
V_7 = V_15 ;
}
if ( V_9 & V_36 ) {
V_4 -> V_13 . V_37 ++ ;
V_10 |= V_36 ;
V_7 = V_15 ;
}
if ( V_9 & V_38 ) {
V_4 -> V_13 . V_39 ++ ;
V_10 |= V_38 ;
V_7 = V_15 ;
}
if ( V_9 & V_40 ) {
V_4 -> V_13 . V_41 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_42 ) {
V_4 -> V_13 . V_43 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_44 ) {
V_4 -> V_13 . V_45 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_46 ) {
V_4 -> V_13 . V_47 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_48 ) {
V_4 -> V_13 . V_49 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_50 ) {
V_4 -> V_13 . V_51 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_52 ) {
V_4 -> V_13 . V_53 ++ ;
V_7 = V_15 ;
}
if ( V_9 & V_54 ) {
V_4 -> V_13 . V_55 ++ ;
V_7 = V_15 ;
}
if ( V_10 )
F_3 ( & V_6 -> V_9 , V_10 ) ;
return V_7 ;
}
static int F_4 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = V_57 -> V_62 ;
struct V_3 * V_4 =
F_5 ( V_61 -> V_63 ) ;
int V_64 = V_4 -> V_65 . V_66 ;
if ( ! V_4 -> V_67 ) {
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
V_4 -> V_67 = V_57 ;
F_6 ( & V_6 -> V_68 , V_69 ) ;
F_7 ( & V_6 -> V_68 ,
V_70 | V_71 ,
V_72 | V_73
| ( V_64 ? V_71 : 0 ) ) ;
F_3 ( & V_6 -> V_74 ,
V_75 | V_76 |
V_77 | V_78 |
V_79 ) ;
F_3 ( & V_6 -> V_80 ,
V_81 | V_82 |
V_83 | V_84 |
V_85 ) ;
F_3 ( & V_6 -> V_86 , V_11 ) ;
F_3 ( & V_6 -> V_87 ,
F_8 ( V_4 -> V_88 - 2 ) |
F_9 ( V_4 -> V_88 - 2 ) ) ;
} else {
if ( V_64 ) {
struct V_89 * V_90 =
V_4 -> V_67 -> V_91 ;
if ( ! V_90 -> V_92 ) {
F_10 ( V_57 -> V_93 -> V_94 -> V_95 ,
L_1 ,
V_57 -> V_96 ==
V_97
? L_2 : L_3 ) ;
return - V_98 ;
}
F_11 ( V_57 -> V_91 ,
V_99 ,
V_90 -> V_92 ,
V_90 -> V_92 ) ;
}
V_4 -> V_100 = V_57 ;
}
return 0 ;
}
static int F_12 ( struct V_56 * V_57 ,
struct V_101 * V_102 , struct V_58 * V_63 )
{
struct V_3 * V_4 = F_5 ( V_63 ) ;
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
unsigned int V_103 =
F_13 ( F_14 ( V_102 ) ) ;
T_4 V_104 = F_15 ( V_103 ) ;
int V_105 = F_2 ( & V_6 -> V_68 ) & V_69 ;
if ( V_105 && V_4 -> V_65 . V_66 )
return 0 ;
if ( ( V_57 -> V_96 == V_97 ) ||
V_4 -> V_65 . V_66 )
F_7 ( & V_6 -> V_106 , V_107 , V_104 ) ;
else
F_7 ( & V_6 -> V_108 , V_107 , V_104 ) ;
return 0 ;
}
static int F_16 ( struct V_56 * V_57 , int V_109 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = V_57 -> V_62 ;
struct V_3 * V_4 = F_5 ( V_61 -> V_63 ) ;
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
switch ( V_109 ) {
case V_110 :
case V_111 :
if ( V_57 -> V_96 == V_97 )
F_17 ( & V_6 -> V_68 ,
V_69 | V_112 ) ;
else
F_17 ( & V_6 -> V_68 ,
V_69 | V_113 ) ;
break;
case V_114 :
case V_115 :
if ( V_57 -> V_96 == V_97 )
F_6 ( & V_6 -> V_68 , V_112 ) ;
else
F_6 ( & V_6 -> V_68 , V_113 ) ;
break;
default:
return - V_116 ;
}
return 0 ;
}
static void F_18 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = V_57 -> V_62 ;
struct V_3 * V_4 = F_5 ( V_61 -> V_63 ) ;
if ( V_4 -> V_67 == V_57 )
V_4 -> V_67 = V_4 -> V_100 ;
V_4 -> V_100 = NULL ;
if ( ! V_4 -> V_67 ) {
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
F_6 ( & V_6 -> V_68 , V_69 ) ;
}
}
static T_5 F_19 ( struct V_117 * V_95 ,
struct V_118 * V_119 , char * V_120 )
{
struct V_3 * V_4 =
F_20 ( V_119 , struct V_3 , V_121 ) ;
T_5 V_122 = 0 ;
F_21 ( V_123 , V_14 ) ;
F_21 ( V_124 , V_17 ) ;
F_21 ( V_125 , V_19 ) ;
F_21 ( V_126 , V_21 ) ;
F_21 ( V_127 , V_23 ) ;
F_21 ( V_128 , V_25 ) ;
F_21 ( V_129 , V_27 ) ;
F_21 ( V_130 , V_29 ) ;
F_21 ( V_131 , V_31 ) ;
F_21 ( V_132 , V_33 ) ;
F_21 ( V_133 , V_35 ) ;
F_21 ( V_134 , V_37 ) ;
F_21 ( V_135 , V_39 ) ;
F_21 ( V_136 , V_41 ) ;
F_21 ( V_137 , V_43 ) ;
F_21 ( V_138 , V_45 ) ;
F_21 ( V_139 , V_47 ) ;
F_21 ( V_140 , V_49 ) ;
F_21 ( V_141 , V_51 ) ;
F_21 ( V_142 , V_53 ) ;
F_21 ( V_143 , V_55 ) ;
return V_122 ;
}
static void F_22 ( char * V_144 )
{
char * V_145 = V_144 ;
char V_146 ;
while ( ( V_146 = * V_145 ) ) {
if ( ( V_146 >= 'A' ) && ( V_146 <= 'Z' ) )
* V_145 = V_146 + ( 'a' - 'A' ) ;
V_145 ++ ;
}
}
static int T_6 F_23 ( struct V_147 * V_148 )
{
struct V_3 * V_4 ;
int V_7 = 0 ;
struct V_118 * V_121 = NULL ;
struct V_149 * V_150 = V_148 -> V_95 . V_151 ;
const char * V_145 , * V_152 ;
const T_7 * V_153 ;
struct V_154 V_155 ;
char V_156 [ 64 ] ;
if ( ! F_24 ( V_150 ) )
return - V_157 ;
if ( ! F_25 ( V_150 , L_4 , NULL ) ) {
F_10 ( & V_148 -> V_95 , L_5 ) ;
return - V_157 ;
}
V_152 = F_25 ( V_150 , L_6 , NULL ) ;
if ( ! V_152 || strcmp ( V_152 , L_7 ) ) {
F_26 ( & V_148 -> V_95 , L_8 , V_152 ) ;
return - V_157 ;
}
V_145 = strrchr ( V_150 -> V_158 , '/' ) + 1 ;
V_4 = F_27 ( sizeof( struct V_3 ) + strlen ( V_145 ) ,
V_159 ) ;
if ( ! V_4 ) {
F_10 ( & V_148 -> V_95 , L_9 ) ;
return - V_160 ;
}
strcpy ( V_4 -> V_156 , V_145 ) ;
memcpy ( & V_4 -> V_65 , & V_161 ,
sizeof( V_161 ) ) ;
V_4 -> V_65 . V_156 = V_4 -> V_156 ;
V_7 = F_28 ( V_150 , 0 , & V_155 ) ;
if ( V_7 ) {
F_10 ( & V_148 -> V_95 , L_10 ) ;
goto V_162;
}
V_4 -> V_6 = F_29 ( V_150 , 0 ) ;
if ( ! V_4 -> V_6 ) {
F_10 ( & V_148 -> V_95 , L_11 ) ;
V_7 = - V_160 ;
goto V_162;
}
V_4 -> V_163 = V_155 . V_164 ;
V_4 -> V_1 = F_30 ( V_150 , 0 ) ;
if ( V_4 -> V_1 == V_165 ) {
F_10 ( & V_148 -> V_95 , L_12 , V_150 -> V_158 ) ;
V_7 = - V_166 ;
goto V_167;
}
V_7 = F_31 ( V_4 -> V_1 , F_1 , 0 , V_4 -> V_156 ,
V_4 ) ;
if ( V_7 < 0 ) {
F_10 ( & V_148 -> V_95 , L_13 , V_4 -> V_1 ) ;
goto V_168;
}
if ( ! F_32 ( V_150 , L_14 , NULL ) )
V_4 -> V_65 . V_66 = 1 ;
V_153 = F_25 ( V_150 , L_15 , NULL ) ;
if ( V_153 )
V_4 -> V_88 = F_33 ( V_153 ) ;
else
V_4 -> V_88 = 8 ;
V_121 = & V_4 -> V_121 ;
F_34 ( & V_121 -> V_119 ) ;
V_121 -> V_119 . V_156 = L_16 ;
V_121 -> V_119 . V_169 = V_170 ;
V_121 -> V_171 = F_19 ;
V_7 = F_35 ( & V_148 -> V_95 , V_121 ) ;
if ( V_7 ) {
F_10 ( & V_148 -> V_95 , L_17 ,
V_4 -> V_121 . V_119 . V_156 ) ;
goto V_172;
}
F_36 ( & V_148 -> V_95 , V_4 ) ;
V_7 = F_37 ( & V_148 -> V_95 , & V_4 -> V_65 ) ;
if ( V_7 ) {
F_10 ( & V_148 -> V_95 , L_18 , V_7 ) ;
goto V_173;
}
V_152 = F_25 ( F_38 ( L_19 ) , L_20 , NULL ) ;
V_145 = strrchr ( V_152 , ',' ) ;
if ( V_145 )
V_152 = V_145 + 1 ;
snprintf ( V_156 , sizeof( V_156 ) , L_21 , V_152 ) ;
F_22 ( V_156 ) ;
V_4 -> V_148 =
F_39 ( & V_148 -> V_95 , V_156 , 0 , NULL , 0 ) ;
if ( F_40 ( V_4 -> V_148 ) ) {
V_7 = F_41 ( V_4 -> V_148 ) ;
F_10 ( & V_148 -> V_95 , L_22 , V_7 ) ;
goto V_174;
}
return 0 ;
V_174:
F_42 ( & V_148 -> V_95 ) ;
V_173:
F_36 ( & V_148 -> V_95 , NULL ) ;
F_43 ( & V_148 -> V_95 , V_121 ) ;
V_172:
F_44 ( V_4 -> V_1 , V_4 ) ;
V_168:
F_45 ( V_4 -> V_1 ) ;
V_167:
F_46 ( V_4 -> V_6 ) ;
V_162:
F_47 ( V_4 ) ;
return V_7 ;
}
static int F_48 ( struct V_147 * V_148 )
{
struct V_3 * V_4 = F_49 ( & V_148 -> V_95 ) ;
F_50 ( V_4 -> V_148 ) ;
F_42 ( & V_148 -> V_95 ) ;
F_43 ( & V_148 -> V_95 , & V_4 -> V_121 ) ;
F_44 ( V_4 -> V_1 , V_4 ) ;
F_45 ( V_4 -> V_1 ) ;
F_47 ( V_4 ) ;
F_36 ( & V_148 -> V_95 , NULL ) ;
return 0 ;
}
