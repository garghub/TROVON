static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
char * V_5 )
{
F_2 ( V_6 , V_5 ,
V_4 > 4 ? V_7 : V_8 ,
16 , 4 , ( void V_9 * ) V_2 -> V_10 + V_3 ,
V_4 * 4 , false ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 , int V_4 ,
char * V_5 , void * V_11 )
{
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_12 )
{
int V_13 = 0 ;
V_13 = F_5 ( V_2 ,
F_6 ( V_14 ) , V_12 ) ;
if ( V_13 )
F_7 ( V_2 -> V_15 , L_1 ,
V_16 , V_13 ) ;
return V_13 ;
}
static int F_8 ( struct V_17 * V_15 ,
const char * V_18 , struct V_19 * * V_20 )
{
struct V_19 * V_19 ;
int V_13 = 0 ;
V_19 = F_9 ( V_15 , V_18 ) ;
if ( F_10 ( V_19 ) ) {
V_13 = F_11 ( V_19 ) ;
F_7 ( V_15 , L_2 ,
V_16 , V_18 , V_13 ) ;
} else {
* V_20 = V_19 ;
}
return V_13 ;
}
static int F_12 ( struct V_17 * V_15 ,
const char * V_18 , struct V_19 * V_19 )
{
int V_13 = 0 ;
V_13 = F_13 ( V_19 ) ;
if ( V_13 )
F_7 ( V_15 , L_3 , V_16 , V_18 , V_13 ) ;
return V_13 ;
}
static void F_14 ( struct V_21 * V_22 )
{
if ( ! V_22 -> V_23 )
return;
if ( V_22 -> V_2 -> V_24 > 1 )
F_15 ( V_22 -> V_25 ) ;
F_15 ( V_22 -> V_26 ) ;
if ( V_22 -> V_2 -> V_24 > 1 )
F_15 ( V_22 -> V_27 ) ;
F_15 ( V_22 -> V_28 ) ;
V_22 -> V_23 = false ;
}
static int F_16 ( struct V_21 * V_22 )
{
int V_13 = 0 ;
struct V_17 * V_15 = V_22 -> V_2 -> V_15 ;
if ( V_22 -> V_23 )
return 0 ;
V_13 = F_12 ( V_15 , L_4 ,
V_22 -> V_28 ) ;
if ( V_13 )
goto V_29;
V_13 = F_12 ( V_15 , L_5 ,
V_22 -> V_26 ) ;
if ( V_13 )
goto V_30;
if ( V_22 -> V_2 -> V_24 > 1 ) {
V_13 = F_12 ( V_15 , L_6 ,
V_22 -> V_27 ) ;
if ( V_13 )
goto V_31;
V_13 = F_12 ( V_15 , L_7 ,
V_22 -> V_25 ) ;
if ( V_13 )
goto V_32;
}
V_22 -> V_23 = true ;
goto V_29;
V_32:
if ( V_22 -> V_2 -> V_24 > 1 )
F_15 ( V_22 -> V_27 ) ;
V_31:
F_15 ( V_22 -> V_26 ) ;
V_30:
F_15 ( V_22 -> V_28 ) ;
V_29:
return V_13 ;
}
static int F_17 ( struct V_21 * V_22 )
{
int V_13 = 0 ;
struct V_17 * V_15 = V_22 -> V_2 -> V_15 ;
V_13 = F_8 ( V_15 ,
L_4 , & V_22 -> V_28 ) ;
if ( V_13 )
goto V_29;
V_13 = F_8 ( V_15 ,
L_5 , & V_22 -> V_26 ) ;
if ( V_13 )
goto V_29;
if ( V_22 -> V_2 -> V_24 > 1 ) {
V_13 = F_8 ( V_15 , L_6 ,
& V_22 -> V_27 ) ;
if ( V_13 )
goto V_29;
V_13 = F_8 ( V_15 , L_7 ,
& V_22 -> V_25 ) ;
}
V_29:
return V_13 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
struct V_33 * V_33 = V_22 -> V_34 ;
T_1 V_12 ;
int V_13 = 0 ;
V_13 = F_4 ( V_2 , & V_12 ) ;
if ( V_13 )
goto V_29;
V_13 = F_20 ( V_33 , V_12 ) ;
if ( V_13 )
F_7 ( V_2 -> V_15 , L_8 ,
V_16 ) ;
V_29:
return V_13 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_13 ;
T_1 V_35 = 0 ;
unsigned long V_36 = V_37 + F_22 ( V_38 ) ;
do {
V_13 = F_5 ( V_2 ,
F_23 ( V_39 ,
F_24 ( 0 ) ) ,
& V_35 ) ;
if ( V_13 || V_35 == V_40 )
break;
F_25 ( 100 , 200 ) ;
} while ( F_26 ( V_37 , V_36 ) );
if ( F_27 ( V_37 , V_36 ) )
V_13 = F_5 ( V_2 ,
F_23 ( V_39 ,
F_24 ( 0 ) ) ,
& V_35 ) ;
if ( V_13 ) {
F_7 ( V_2 -> V_15 , L_9 ,
V_16 , V_13 ) ;
} else if ( V_35 != V_40 ) {
V_13 = V_35 ;
F_7 ( V_2 -> V_15 , L_10 ,
V_16 , V_13 ) ;
}
return V_13 ;
}
static void F_28 ( struct V_21 * V_22 )
{
F_29 ( V_22 -> V_2 , V_41 ,
F_30 ( V_22 ) ? V_41 : 0 ,
V_42 ) ;
F_31 () ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
struct V_33 * V_33 = V_22 -> V_34 ;
int V_43 = 0 ;
bool V_44 = ( V_45 == V_46 )
? true : false ;
F_33 ( V_2 ) ;
F_25 ( 1000 , 1100 ) ;
V_43 = F_34 ( V_33 , V_44 ) ;
if ( V_43 ) {
F_7 ( V_2 -> V_15 , L_11 ,
V_16 , V_43 ) ;
goto V_29;
}
F_35 ( V_2 ) ;
F_25 ( 1000 , 1100 ) ;
V_43 = F_36 ( V_33 ) ;
if ( V_43 ) {
F_7 ( V_2 -> V_15 , L_12 ,
V_16 , V_43 ) ;
goto V_29;
}
V_43 = F_37 ( V_33 ) ;
if ( V_43 )
F_7 ( V_2 -> V_15 ,
L_13 ,
V_16 , V_43 ) ;
F_28 ( V_22 ) ;
V_29:
return V_43 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 ,
F_40 ( V_2 , V_47 ) | V_48 ,
V_47 ) ;
F_31 () ;
}
static int F_41 ( struct V_1 * V_2 ,
enum V_49 V_50 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
int V_13 = 0 ;
switch ( V_50 ) {
case V_51 :
F_32 ( V_2 ) ;
V_13 = F_16 ( V_22 ) ;
break;
case V_52 :
V_13 = F_21 ( V_2 ) ;
F_38 ( V_2 ) ;
break;
default:
F_7 ( V_2 -> V_15 , L_14 , V_16 , V_50 ) ;
V_13 = - V_53 ;
break;
}
return V_13 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_54 ,
T_1 V_55 , T_1 V_56 , bool V_57 )
{
int V_43 = 0 ;
struct V_21 * V_22 = F_19 ( V_2 ) ;
struct V_58 * V_59 ;
T_1 V_60 ;
T_1 V_61 = 0 ;
unsigned long V_62 = 0 ;
T_1 V_63 = 0 ;
static T_1 V_64 [] [ 2 ] = {
{ V_65 , 0x1 } ,
{ V_66 , 0x1 } ,
{ V_67 , 0x1 } ,
{ V_68 , 0x1 } ,
} ;
static T_1 V_69 [] [ 2 ] = {
{ V_70 , 0x1F } ,
{ V_71 , 0x3e } ,
{ V_72 , 0x7D } ,
} ;
static T_1 V_73 [] [ 2 ] = {
{ V_70 , 0x24 } ,
{ V_71 , 0x49 } ,
{ V_72 , 0x92 } ,
} ;
if ( F_30 ( V_22 ) && ! F_43 ( V_2 ) )
goto V_29;
if ( V_54 == 0 ) {
F_7 ( V_2 -> V_15 , L_15 , V_16 , V_54 ) ;
goto V_74;
}
F_44 (clki, &hba->clk_list_head, list) {
if ( ! strcmp ( V_59 -> V_18 , L_16 ) )
V_62 = F_45 ( V_59 -> V_19 ) ;
}
if ( V_62 < V_75 )
V_62 = V_75 ;
V_63 = V_62 / V_76 ;
if ( F_40 ( V_2 , V_77 ) != V_63 ) {
F_39 ( V_2 , V_63 , V_77 ) ;
F_31 () ;
}
if ( F_30 ( V_22 ) )
goto V_29;
V_60 = V_78 / V_62 ;
V_60 <<= V_79 ;
V_60 &= V_80 ;
switch ( V_55 ) {
case V_81 :
case V_82 :
if ( V_56 == V_83 ) {
if ( V_54 > F_46 ( V_69 ) ) {
F_7 ( V_2 -> V_15 ,
L_17 ,
V_16 , V_54 ,
F_46 ( V_69 ) ) ;
goto V_74;
}
V_61 = V_69 [ V_54 - 1 ] [ 1 ] ;
} else if ( V_56 == V_46 ) {
if ( V_54 > F_46 ( V_73 ) ) {
F_7 ( V_2 -> V_15 ,
L_17 ,
V_16 , V_54 ,
F_46 ( V_73 ) ) ;
goto V_74;
}
V_61 = V_73 [ V_54 - 1 ] [ 1 ] ;
} else {
F_7 ( V_2 -> V_15 , L_18 ,
V_16 , V_56 ) ;
goto V_74;
}
break;
case V_84 :
case V_85 :
if ( V_54 > F_46 ( V_64 ) ) {
F_7 ( V_2 -> V_15 ,
L_17 ,
V_16 , V_54 ,
F_46 ( V_64 ) ) ;
goto V_74;
}
V_61 = V_64 [ V_54 - 1 ] [ 1 ] ;
break;
case V_86 :
default:
F_7 ( V_2 -> V_15 , L_19 , V_16 , V_55 ) ;
goto V_74;
}
if ( F_40 ( V_2 , V_87 ) !=
( V_60 | V_61 ) ) {
F_39 ( V_2 , V_60 | V_61 ,
V_87 ) ;
F_31 () ;
}
if ( V_57 ) {
F_39 ( V_2 , ( ( V_62 / V_88 ) * 100 ) ,
V_89 ) ;
F_31 () ;
}
goto V_29;
V_74:
V_43 = - V_53 ;
V_29:
return V_43 ;
}
static int F_47 ( struct V_1 * V_2 ,
enum V_49 V_50 )
{
int V_13 = 0 ;
struct V_21 * V_22 = F_19 ( V_2 ) ;
switch ( V_50 ) {
case V_51 :
if ( F_42 ( V_2 , V_65 , V_84 ,
0 , true ) ) {
F_7 ( V_2 -> V_15 , L_20 ,
V_16 ) ;
V_13 = - V_53 ;
goto V_29;
}
if ( F_30 ( V_22 ) )
V_13 = F_48 ( V_2 ,
150 ) ;
if ( F_49 ( V_2 ) != V_90 )
V_13 = F_50 ( V_2 ,
F_6 ( V_91 ) ,
0 ) ;
break;
case V_52 :
F_18 ( V_2 ) ;
break;
default:
break;
}
V_29:
return V_13 ;
}
static int F_51 ( struct V_1 * V_2 , enum V_92 V_93 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
struct V_33 * V_33 = V_22 -> V_34 ;
int V_43 = 0 ;
if ( F_52 ( V_2 ) ) {
F_14 ( V_22 ) ;
F_53 ( V_33 ) ;
F_33 ( V_2 ) ;
goto V_29;
}
if ( ! F_54 ( V_2 ) ) {
F_14 ( V_22 ) ;
F_53 ( V_33 ) ;
}
V_29:
return V_43 ;
}
static int F_55 ( struct V_1 * V_2 , enum V_92 V_93 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
struct V_33 * V_33 = V_22 -> V_34 ;
int V_13 ;
V_13 = F_56 ( V_33 ) ;
if ( V_13 ) {
F_7 ( V_2 -> V_15 , L_21 ,
V_16 , V_13 ) ;
goto V_29;
}
V_13 = F_16 ( V_22 ) ;
if ( V_13 )
goto V_29;
V_2 -> V_94 = false ;
V_29:
return V_13 ;
}
static int F_57 ( struct V_95 * V_96 ,
struct V_97 * V_98 ,
struct V_97 * V_99 )
{
int V_100 ;
int V_101 ;
bool V_102 = false ;
bool V_103 = false ;
if ( V_98 -> V_104 == V_82 )
V_102 = true ;
if ( V_96 -> V_105 == V_106 ) {
V_103 = true ;
V_100 = F_58 ( T_1 , V_96 -> V_107 ,
V_96 -> V_108 ) ;
} else {
V_100 = F_58 ( T_1 , V_96 -> V_109 ,
V_96 -> V_110 ) ;
}
if ( ! V_102 && V_103 ) {
F_59 ( L_22 ,
V_16 ) ;
return - V_111 ;
} else if ( V_102 && V_103 ) {
V_99 -> V_104 = V_99 -> V_112 =
V_96 -> V_113 ;
} else {
V_99 -> V_104 = V_99 -> V_112 =
V_96 -> V_114 ;
}
V_99 -> V_115 = F_58 ( T_1 , V_98 -> V_115 ,
V_96 -> V_12 ) ;
V_99 -> V_116 = F_58 ( T_1 , V_98 -> V_116 ,
V_96 -> V_117 ) ;
V_101 = F_58 ( T_1 , V_98 -> V_118 , V_98 -> V_119 ) ;
if ( ( V_102 && V_103 ) ||
( ! V_102 && ! V_103 ) )
V_99 -> V_118 = V_99 -> V_119 =
F_58 ( T_1 , V_101 , V_100 ) ;
else if ( ! V_102 )
V_99 -> V_118 = V_99 -> V_119 = V_101 ;
else
V_99 -> V_118 = V_99 -> V_119 = V_100 ;
V_99 -> V_120 = V_96 -> V_120 ;
return 0 ;
}
static int F_60 ( struct V_21 * V_22 ,
const char * V_121 )
{
struct V_17 * V_15 = V_22 -> V_2 -> V_15 ;
struct V_122 * V_123 = V_15 -> V_124 ;
int V_13 ;
const char * V_125 = L_23 ;
if ( ! V_121 ) {
V_13 = - V_53 ;
goto V_29;
}
if ( V_22 -> V_126 . V_127 && ! ! strcmp ( V_121 , L_24 ) )
V_13 = F_61 ( V_123 , V_125 , L_25 ) ;
else
V_13 = F_61 ( V_123 , V_125 , V_121 ) ;
V_29:
if ( V_13 < 0 )
F_7 ( V_15 , L_26 ,
V_16 , V_121 , V_13 ) ;
return V_13 ;
}
static void F_62 ( struct V_97 * V_128 , char * V_129 )
{
int V_54 = F_63 ( T_1 , V_128 -> V_118 , V_128 -> V_119 ) ;
int V_130 = F_63 ( T_1 , V_128 -> V_116 , V_128 -> V_115 ) ;
int V_131 ;
if ( ! V_54 )
V_54 = 1 ;
if ( ! V_130 )
V_130 = 1 ;
if ( ! V_128 -> V_104 && ! V_128 -> V_112 ) {
V_131 = V_84 ;
snprintf ( V_129 , V_132 , L_24 ) ;
} else if ( V_128 -> V_104 == V_82 || V_128 -> V_104 == V_81 ||
V_128 -> V_112 == V_82 || V_128 -> V_112 == V_81 ) {
V_131 = V_82 ;
snprintf ( V_129 , V_132 , L_27 , L_28 ,
V_128 -> V_120 == V_46 ? L_29 : L_30 , V_54 , V_130 ) ;
} else {
V_131 = V_85 ;
snprintf ( V_129 , V_132 , L_31 ,
L_32 , V_54 , V_130 ) ;
}
}
static int F_64 ( struct V_21 * V_22 , int V_133 )
{
int V_13 = 0 ;
if ( V_133 != V_22 -> V_126 . V_134 ) {
V_13 = F_65 (
V_22 -> V_126 . V_135 , V_133 ) ;
if ( V_13 ) {
F_7 ( V_22 -> V_2 -> V_15 ,
L_33 ,
V_16 , V_22 -> V_126 . V_135 ,
V_133 , V_13 ) ;
goto V_29;
}
V_22 -> V_126 . V_134 = V_133 ;
}
V_29:
return V_13 ;
}
static int F_66 ( struct V_21 * V_22 )
{
int V_133 ;
int V_13 = 0 ;
char V_136 [ V_132 ] ;
F_62 ( & V_22 -> V_137 , V_136 ) ;
V_133 = F_60 ( V_22 , V_136 ) ;
if ( V_133 >= 0 )
V_13 = F_64 ( V_22 , V_133 ) ;
else
V_13 = V_133 ;
if ( V_13 )
F_7 ( V_22 -> V_2 -> V_15 , L_34 , V_16 , V_13 ) ;
else
V_22 -> V_126 . V_138 = V_133 ;
return V_13 ;
}
static T_2
F_67 ( struct V_17 * V_15 , struct V_139 * V_140 ,
char * V_141 )
{
struct V_1 * V_2 = F_68 ( V_15 ) ;
struct V_21 * V_22 = F_19 ( V_2 ) ;
return snprintf ( V_141 , V_142 , L_35 ,
V_22 -> V_126 . V_127 ) ;
}
static T_2
F_69 ( struct V_17 * V_15 , struct V_139 * V_140 ,
const char * V_141 , T_3 V_143 )
{
struct V_1 * V_2 = F_68 ( V_15 ) ;
struct V_21 * V_22 = F_19 ( V_2 ) ;
T_4 V_144 ;
if ( ! F_70 ( V_141 , 0 , & V_144 ) ) {
V_22 -> V_126 . V_127 = ! ! V_144 ;
F_66 ( V_22 ) ;
}
return V_143 ;
}
static int F_71 ( struct V_21 * V_22 )
{
int V_13 ;
struct V_145 * V_146 ;
struct V_17 * V_15 = V_22 -> V_2 -> V_15 ;
struct V_147 * V_148 = F_72 ( V_15 ) ;
struct V_122 * V_123 = V_15 -> V_124 ;
V_146 = F_73 ( V_148 ) ;
if ( ! V_146 ) {
F_7 ( V_15 , L_36 , V_16 ) ;
V_13 = - V_149 ;
goto V_29;
}
V_13 = F_74 ( V_123 , L_23 ) ;
if ( V_13 < 0 || V_13 != V_146 -> V_150 ) {
F_7 ( V_15 , L_37 ,
V_16 , V_13 ) ;
goto V_29;
}
V_22 -> V_126 . V_135 = F_75 ( V_146 ) ;
if ( ! V_22 -> V_126 . V_135 ) {
F_7 ( V_15 , L_38 ,
V_16 ) ;
V_13 = - V_151 ;
goto V_29;
}
V_22 -> V_126 . V_152 = F_60 ( V_22 , L_24 ) ;
V_22 -> V_126 . V_153 = F_60 ( V_22 , L_25 ) ;
V_22 -> V_126 . V_154 . V_155 = F_67 ;
V_22 -> V_126 . V_154 . V_156 = F_69 ;
F_76 ( & V_22 -> V_126 . V_154 . V_140 ) ;
V_22 -> V_126 . V_154 . V_140 . V_18 = L_39 ;
V_22 -> V_126 . V_154 . V_140 . V_136 = V_157 | V_158 ;
V_13 = F_77 ( V_15 , & V_22 -> V_126 . V_154 ) ;
V_29:
return V_13 ;
}
static int F_66 ( struct V_21 * V_22 )
{
return 0 ;
}
static int F_64 ( struct V_21 * V_22 , int V_133 )
{
return 0 ;
}
static int F_71 ( struct V_21 * V_22 )
{
return 0 ;
}
static void F_78 ( struct V_21 * V_22 , bool V_159 )
{
if ( V_22 -> V_160 &&
( V_159 ^ V_22 -> V_161 ) ) {
T_1 V_162 = F_79 ( V_22 -> V_160 ) ;
if ( V_159 )
V_162 |= V_22 -> V_163 ;
else
V_162 &= ~ V_22 -> V_163 ;
if ( ! V_159 )
F_80 ( 1 ) ;
F_81 ( V_162 , V_22 -> V_160 ) ;
F_82 () ;
if ( V_159 )
F_80 ( 1 ) ;
V_22 -> V_161 = V_159 ;
}
}
static int F_83 ( struct V_1 * V_2 ,
enum V_49 V_50 ,
struct V_97 * V_164 ,
struct V_97 * V_137 )
{
T_1 V_165 ;
struct V_21 * V_22 = F_19 ( V_2 ) ;
struct V_33 * V_33 = V_22 -> V_34 ;
struct V_95 V_166 ;
int V_43 = 0 ;
int V_167 = 0 ;
if ( ! V_137 ) {
F_59 ( L_40 , V_16 ) ;
V_43 = - V_53 ;
goto V_29;
}
switch ( V_50 ) {
case V_51 :
V_166 . V_12 = V_168 ;
V_166 . V_117 = V_169 ;
V_166 . V_107 = V_170 ;
V_166 . V_108 = V_171 ;
V_166 . V_109 = V_172 ;
V_166 . V_110 = V_173 ;
V_166 . V_114 = V_174 ;
V_166 . V_175 = V_176 ;
V_166 . V_113 = V_177 ;
V_166 . V_178 = V_179 ;
V_166 . V_120 = V_45 ;
V_166 . V_105 =
V_180 ;
if ( V_22 -> V_181 . V_182 == 0x1 ) {
if ( V_166 . V_108 > V_71 )
V_166 . V_108 = V_71 ;
if ( V_166 . V_107 > V_71 )
V_166 . V_107 = V_71 ;
}
V_43 = F_57 ( & V_166 ,
V_164 ,
V_137 ) ;
if ( V_43 ) {
F_59 ( L_41 ,
V_16 ) ;
goto V_29;
}
if ( ! F_84 ( & V_2 -> V_183 ) &&
F_84 ( V_137 ) )
F_78 ( V_22 , true ) ;
break;
case V_52 :
if ( F_42 ( V_2 , V_137 -> V_118 ,
V_137 -> V_104 ,
V_137 -> V_120 , false ) ) {
F_7 ( V_2 -> V_15 , L_20 ,
V_16 ) ;
V_43 = - V_53 ;
}
V_165 = ~ ( V_184 << V_137 -> V_115 ) ;
V_167 = F_20 ( V_33 , V_165 ) ;
if ( V_167 ) {
F_7 ( V_2 -> V_15 , L_42 ,
V_16 , V_167 ) ;
V_43 = V_167 ;
}
memcpy ( & V_22 -> V_137 ,
V_137 , sizeof( * V_137 ) ) ;
F_66 ( V_22 ) ;
if ( F_84 ( & V_2 -> V_183 ) &&
! F_84 ( V_137 ) )
F_78 ( V_22 , false ) ;
break;
default:
V_43 = - V_53 ;
break;
}
V_29:
return V_43 ;
}
static T_1 F_85 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
if ( V_22 -> V_181 . V_182 == 0x1 )
return V_185 ;
else
return V_186 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
if ( V_22 -> V_181 . V_182 == 0x01 ) {
V_2 -> V_187 |= V_188
| V_189
| V_190 ;
if ( V_22 -> V_181 . V_191 == 0x0001 && V_22 -> V_181 . V_192 == 0x0001 )
V_2 -> V_187 |= V_193 ;
V_2 -> V_187 |= V_194 ;
}
if ( V_22 -> V_181 . V_182 >= 0x2 ) {
V_2 -> V_187 |= V_195 ;
if ( ! F_30 ( V_22 ) )
V_2 -> V_187 |= ( V_188
| V_190
| V_189 ) ;
}
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
V_2 -> V_196 |= V_197 | V_198 ;
V_2 -> V_196 |= V_199 ;
V_2 -> V_196 |= V_200 ;
if ( V_22 -> V_181 . V_182 >= 0x2 ) {
V_22 -> V_196 = V_201 |
V_202 ;
}
}
static int F_88 ( struct V_1 * V_2 , bool V_203 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
int V_13 ;
int V_133 = 0 ;
if ( ! V_22 )
return 0 ;
if ( V_203 ) {
V_13 = F_89 ( V_22 -> V_34 ) ;
if ( V_13 )
goto V_29;
V_13 = F_90 ( V_22 -> V_34 ) ;
if ( V_13 ) {
F_7 ( V_2 -> V_15 , L_43 ,
V_16 , V_13 ) ;
F_91 ( V_22 -> V_34 ) ;
goto V_29;
}
if ( F_84 ( & V_2 -> V_183 ) )
F_78 ( V_22 , true ) ;
V_133 = V_22 -> V_126 . V_138 ;
if ( V_133 == V_22 -> V_126 . V_152 )
F_66 ( V_22 ) ;
} else {
F_91 ( V_22 -> V_34 ) ;
if ( ! F_54 ( V_2 ) )
F_78 ( V_22 , false ) ;
V_133 = V_22 -> V_126 . V_152 ;
}
V_13 = F_64 ( V_22 , V_133 ) ;
if ( V_13 )
F_7 ( V_2 -> V_15 , L_44 ,
V_16 , V_13 ) ;
V_29:
return V_13 ;
}
static int T_5 F_92 ( char * V_204 )
{
F_93 ( V_205 , V_204 , V_206 ) ;
return 1 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_147 * V_148 = F_72 ( V_15 ) ;
struct V_21 * V_22 ;
struct V_207 * V_167 ;
if ( strlen ( V_205 ) && strcmp ( V_205 , F_95 ( V_15 ) ) )
return - V_208 ;
V_22 = F_96 ( V_15 , sizeof( * V_22 ) , V_209 ) ;
if ( ! V_22 ) {
V_13 = - V_210 ;
F_7 ( V_15 , L_45 , V_16 ) ;
goto V_29;
}
V_22 -> V_2 = V_2 ;
F_97 ( V_2 , V_22 ) ;
V_22 -> V_34 = F_98 ( V_15 , L_46 ) ;
if ( F_10 ( V_22 -> V_34 ) ) {
V_13 = F_11 ( V_22 -> V_34 ) ;
F_7 ( V_15 , L_47 , V_16 , V_13 ) ;
goto V_29;
}
V_13 = F_71 ( V_22 ) ;
if ( V_13 )
goto V_211;
F_99 ( V_2 , & V_22 -> V_181 . V_182 ,
& V_22 -> V_181 . V_191 , & V_22 -> V_181 . V_192 ) ;
if ( V_22 -> V_181 . V_182 >= 0x02 ) {
V_22 -> V_160 = V_2 -> V_10 + V_42 ;
V_22 -> V_163 = F_100 ( 26 ) ;
} else {
V_167 = F_101 ( V_148 , V_212 , 1 ) ;
if ( V_167 ) {
V_22 -> V_160 =
F_102 ( V_15 , V_167 ) ;
if ( F_10 ( V_22 -> V_160 ) ) {
F_103 ( V_15 ,
L_48 ,
V_16 ,
F_11 ( V_22 -> V_160 ) ) ;
V_22 -> V_160 = NULL ;
}
V_22 -> V_163 = F_100 ( 5 ) ;
}
}
F_104 ( V_22 -> V_34 ,
V_22 -> V_181 . V_182 , V_22 -> V_181 . V_191 , V_22 -> V_181 . V_192 ) ;
F_105 ( V_22 -> V_34 ) ;
V_13 = F_56 ( V_22 -> V_34 ) ;
if ( V_13 )
goto V_213;
V_13 = F_17 ( V_22 ) ;
if ( V_13 )
goto V_214;
F_87 ( V_2 ) ;
F_86 ( V_2 ) ;
F_88 ( V_2 , true ) ;
if ( V_2 -> V_15 -> V_215 < V_216 )
V_217 [ V_2 -> V_15 -> V_215 ] = V_22 ;
V_22 -> V_218 |= V_219 ;
F_106 ( V_22 ) ;
V_13 = F_107 ( V_22 ) ;
if ( V_13 ) {
F_103 ( V_15 , L_49 ,
V_16 , V_13 ) ;
V_13 = 0 ;
}
goto V_29;
V_214:
F_53 ( V_22 -> V_34 ) ;
V_213:
F_108 ( V_22 -> V_34 ) ;
V_211:
F_109 ( V_15 , V_22 ) ;
F_97 ( V_2 , NULL ) ;
V_29:
return V_13 ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
F_14 ( V_22 ) ;
F_53 ( V_22 -> V_34 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
T_1 V_220 )
{
int V_13 ;
T_1 V_221 ;
if ( V_220 > V_222 )
return - V_53 ;
V_13 = F_5 ( V_2 ,
F_6 ( V_223 ) ,
& V_221 ) ;
if ( V_13 )
goto V_29;
V_221 &= ~ V_222 ;
V_221 |= V_220 ;
V_221 &= ~ V_224 ;
V_13 = F_50 ( V_2 ,
F_6 ( V_223 ) ,
V_221 ) ;
V_29:
return V_13 ;
}
static int F_111 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_112 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
if ( ! F_30 ( V_22 ) )
return 0 ;
return F_48 ( V_2 , 150 ) ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
int V_13 ;
T_1 V_221 ;
if ( ! F_30 ( V_22 ) )
return 0 ;
V_13 = F_5 ( V_2 ,
F_6 ( V_223 ) ,
& V_221 ) ;
if ( ! V_13 &&
( V_221 & V_224 ) ) {
V_221 &= ~ V_224 ;
V_13 = F_50 ( V_2 ,
F_6 ( V_223 ) ,
V_221 ) ;
}
return V_13 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
if ( ! F_30 ( V_22 ) )
return 0 ;
return F_48 ( V_2 , 75 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
bool V_225 , enum V_49 V_50 )
{
struct V_21 * V_22 = F_19 ( V_2 ) ;
struct V_97 * V_137 = & V_22 -> V_137 ;
int V_13 = 0 ;
if ( V_50 == V_51 ) {
if ( V_225 )
V_13 = F_111 ( V_2 ) ;
else
V_13 = F_113 ( V_2 ) ;
} else {
if ( V_225 )
V_13 = F_112 ( V_2 ) ;
else
V_13 = F_114 ( V_2 ) ;
if ( V_13 || ! V_137 )
goto V_29;
F_42 ( V_2 ,
V_137 -> V_118 ,
V_137 -> V_104 ,
V_137 -> V_120 ,
false ) ;
F_66 ( V_22 ) ;
}
V_29:
return V_13 ;
}
static void F_116 ( struct V_1 * V_2 ,
void * V_11 , void (* F_117)( struct V_1 * V_2 ,
int V_3 , int V_226 , char * V_204 , void * V_11 ) )
{
T_1 V_227 ;
struct V_21 * V_22 ;
if ( F_118 ( ! V_2 ) ) {
F_59 ( L_50 , V_16 ) ;
return;
}
if ( F_118 ( ! F_117 ) ) {
F_7 ( V_2 -> V_15 , L_51 , V_16 ) ;
return;
}
V_22 = F_19 ( V_2 ) ;
if ( ! ( V_22 -> V_218 & V_228 ) )
return;
V_227 = F_119 ( V_22 , V_229 ) ;
F_117 ( V_2 , V_227 , 44 , L_52 , V_11 ) ;
V_227 = F_40 ( V_2 , V_42 ) ;
V_227 |= F_120 ( 17 ) ;
F_39 ( V_2 , V_227 , V_42 ) ;
V_227 = F_119 ( V_22 , V_230 ) ;
F_117 ( V_2 , V_227 , 32 , L_53 , V_11 ) ;
V_227 = F_119 ( V_22 , V_231 ) ;
F_117 ( V_2 , V_227 , 128 , L_54 , V_11 ) ;
V_227 = F_119 ( V_22 , V_232 ) ;
F_117 ( V_2 , V_227 , 64 , L_55 , V_11 ) ;
F_39 ( V_2 , ( V_227 & ~ F_120 ( 17 ) ) , V_42 ) ;
V_227 = F_119 ( V_22 , V_233 ) ;
F_117 ( V_2 , V_227 , 4 , L_56 , V_11 ) ;
V_227 = F_119 ( V_22 , V_234 ) ;
F_117 ( V_2 , V_227 , 4 , L_57 , V_11 ) ;
V_227 = F_119 ( V_22 , V_235 ) ;
F_117 ( V_2 , V_227 , 48 , L_58 , V_11 ) ;
V_227 = F_119 ( V_22 , V_236 ) ;
F_117 ( V_2 , V_227 , 27 , L_59 , V_11 ) ;
V_227 = F_119 ( V_22 , V_237 ) ;
F_117 ( V_2 , V_227 , 19 , L_60 , V_11 ) ;
V_227 = F_119 ( V_22 , V_238 ) ;
F_117 ( V_2 , V_227 , 34 , L_61 , V_11 ) ;
V_227 = F_119 ( V_22 , V_239 ) ;
F_117 ( V_2 , V_227 , 9 , L_62 , V_11 ) ;
}
static void F_121 ( struct V_21 * V_22 )
{
if ( V_22 -> V_218 & V_240 )
F_29 ( V_22 -> V_2 , V_241 , V_241 , V_42 ) ;
else
F_29 ( V_22 -> V_2 , V_241 , 0 , V_42 ) ;
}
static void F_106 ( struct V_21 * V_22 )
{
V_22 -> V_242 . V_243 = V_244 ;
V_22 -> V_242 . V_245 = 1 ;
}
static bool F_122 ( struct V_21 * V_22 )
{
if ( V_22 -> V_242 . V_243 >= V_246 ) {
F_7 ( V_22 -> V_2 -> V_15 ,
L_63 ,
V_16 , V_22 -> V_242 . V_243 ) ;
return false ;
}
if ( V_22 -> V_242 . V_245 > 0x1F ) {
F_7 ( V_22 -> V_2 -> V_15 ,
L_64 ,
V_16 , V_22 -> V_242 . V_245 ) ;
return false ;
}
return true ;
}
int F_107 ( struct V_21 * V_22 )
{
int V_227 ;
int V_3 ;
T_1 V_247 = V_248 ;
if ( ! V_22 )
return - V_53 ;
if ( ! F_122 ( V_22 ) )
return - V_249 ;
switch ( V_22 -> V_242 . V_243 ) {
case V_244 :
V_227 = V_250 ;
V_3 = 24 ;
break;
case V_251 :
V_227 = V_250 ;
V_3 = 16 ;
break;
case V_252 :
V_227 = V_250 ;
V_3 = 8 ;
break;
case V_253 :
V_227 = V_250 ;
V_3 = 0 ;
break;
case V_254 :
V_227 = V_255 ;
V_3 = 24 ;
break;
case V_256 :
V_227 = V_255 ;
V_3 = 16 ;
break;
case V_257 :
V_227 = V_255 ;
V_3 = 8 ;
break;
case V_258 :
V_227 = V_255 ;
V_3 = 0 ;
break;
case V_259 :
V_227 = V_260 ;
V_3 = 16 ;
break;
case V_261 :
V_227 = V_260 ;
V_3 = 8 ;
break;
case V_262 :
V_227 = V_260 ;
V_3 = 0 ;
break;
case V_263 :
V_227 = V_264 ;
V_3 = 1 ;
break;
}
V_247 <<= V_3 ;
F_123 ( V_22 -> V_2 -> V_15 ) ;
F_124 ( V_22 -> V_2 , false ) ;
F_29 ( V_22 -> V_2 , V_265 ,
( T_1 ) V_22 -> V_242 . V_243 << 19 ,
V_42 ) ;
F_29 ( V_22 -> V_2 , V_247 ,
( T_1 ) V_22 -> V_242 . V_245 << V_3 ,
V_227 ) ;
F_121 ( V_22 ) ;
F_125 ( V_22 -> V_2 ) ;
F_126 ( V_22 -> V_2 -> V_15 ) ;
return 0 ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_266 , 1 , L_65 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_77 , 16 ,
L_66 ) ;
F_116 ( V_2 , NULL , F_3 ) ;
F_127 ( V_2 ) ;
}
static int F_129 ( struct V_147 * V_148 )
{
int V_13 ;
struct V_17 * V_15 = & V_148 -> V_15 ;
V_13 = F_130 ( V_148 , & V_267 ) ;
if ( V_13 )
F_7 ( V_15 , L_67 , V_13 ) ;
return V_13 ;
}
static int F_131 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = F_132 ( V_148 ) ;
F_123 ( & ( V_148 ) -> V_15 ) ;
F_133 ( V_2 ) ;
return 0 ;
}
