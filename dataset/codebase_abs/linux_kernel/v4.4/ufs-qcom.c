static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
char * V_5 )
{
F_2 ( V_6 , V_5 ,
V_4 > 4 ? V_7 : V_8 ,
16 , 4 , ( void V_9 * ) V_2 -> V_10 + V_3 ,
V_4 * 4 , false ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_11 )
{
int V_12 = 0 ;
V_12 = F_4 ( V_2 ,
F_5 ( V_13 ) , V_11 ) ;
if ( V_12 )
F_6 ( V_2 -> V_14 , L_1 ,
V_15 , V_12 ) ;
return V_12 ;
}
static int F_7 ( struct V_16 * V_14 ,
const char * V_17 , struct V_18 * * V_19 )
{
struct V_18 * V_18 ;
int V_12 = 0 ;
V_18 = F_8 ( V_14 , V_17 ) ;
if ( F_9 ( V_18 ) ) {
V_12 = F_10 ( V_18 ) ;
F_6 ( V_14 , L_2 ,
V_15 , V_17 , V_12 ) ;
} else {
* V_19 = V_18 ;
}
return V_12 ;
}
static int F_11 ( struct V_16 * V_14 ,
const char * V_17 , struct V_18 * V_18 )
{
int V_12 = 0 ;
V_12 = F_12 ( V_18 ) ;
if ( V_12 )
F_6 ( V_14 , L_3 , V_15 , V_17 , V_12 ) ;
return V_12 ;
}
static void F_13 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_22 )
return;
F_14 ( V_21 -> V_23 ) ;
F_14 ( V_21 -> V_24 ) ;
F_14 ( V_21 -> V_25 ) ;
F_14 ( V_21 -> V_26 ) ;
V_21 -> V_22 = false ;
}
static int F_15 ( struct V_20 * V_21 )
{
int V_12 = 0 ;
struct V_16 * V_14 = V_21 -> V_2 -> V_14 ;
if ( V_21 -> V_22 )
return 0 ;
V_12 = F_11 ( V_14 , L_4 ,
V_21 -> V_26 ) ;
if ( V_12 )
goto V_27;
V_12 = F_11 ( V_14 , L_5 ,
V_21 -> V_24 ) ;
if ( V_12 )
goto V_28;
V_12 = F_11 ( V_14 , L_6 ,
V_21 -> V_25 ) ;
if ( V_12 )
goto V_29;
V_12 = F_11 ( V_14 , L_7 ,
V_21 -> V_23 ) ;
if ( V_12 )
goto V_30;
V_21 -> V_22 = true ;
goto V_27;
V_30:
F_14 ( V_21 -> V_25 ) ;
V_29:
F_14 ( V_21 -> V_24 ) ;
V_28:
F_14 ( V_21 -> V_26 ) ;
V_27:
return V_12 ;
}
static int F_16 ( struct V_20 * V_21 )
{
int V_12 = 0 ;
struct V_16 * V_14 = V_21 -> V_2 -> V_14 ;
V_12 = F_7 ( V_14 ,
L_4 , & V_21 -> V_26 ) ;
if ( V_12 )
goto V_27;
V_12 = F_7 ( V_14 ,
L_5 , & V_21 -> V_24 ) ;
if ( V_12 )
goto V_27;
V_12 = F_7 ( V_14 , L_6 ,
& V_21 -> V_25 ) ;
if ( V_12 )
goto V_27;
V_12 = F_7 ( V_14 , L_7 ,
& V_21 -> V_23 ) ;
V_27:
return V_12 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
struct V_31 * V_31 = V_21 -> V_32 ;
T_1 V_11 ;
int V_12 = 0 ;
V_12 = F_3 ( V_2 , & V_11 ) ;
if ( V_12 )
goto V_27;
V_12 = F_19 ( V_31 , V_11 ) ;
if ( V_12 )
F_6 ( V_2 -> V_14 , L_8 ,
V_15 ) ;
V_27:
return V_12 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_12 ;
T_1 V_33 = 0 ;
unsigned long V_34 = V_35 + F_21 ( V_36 ) ;
do {
V_12 = F_4 ( V_2 ,
F_22 ( V_37 ,
F_23 ( 0 ) ) ,
& V_33 ) ;
if ( V_12 || V_33 == V_38 )
break;
F_24 ( 100 , 200 ) ;
} while ( F_25 ( V_35 , V_34 ) );
if ( F_26 ( V_35 , V_34 ) )
V_12 = F_4 ( V_2 ,
F_22 ( V_37 ,
F_23 ( 0 ) ) ,
& V_33 ) ;
if ( V_12 ) {
F_6 ( V_2 -> V_14 , L_9 ,
V_15 , V_12 ) ;
} else if ( V_33 != V_38 ) {
V_12 = V_33 ;
F_6 ( V_2 -> V_14 , L_10 ,
V_15 , V_12 ) ;
}
return V_12 ;
}
static void F_27 ( struct V_20 * V_21 )
{
F_28 ( V_21 -> V_2 , V_39 ,
F_29 ( V_21 ) ? V_39 : 0 ,
V_40 ) ;
F_30 () ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
struct V_31 * V_31 = V_21 -> V_32 ;
int V_41 = 0 ;
bool V_42 = ( V_43 == V_44 )
? true : false ;
F_32 ( V_2 ) ;
F_24 ( 1000 , 1100 ) ;
V_41 = F_33 ( V_31 , V_42 ) ;
if ( V_41 ) {
F_6 ( V_2 -> V_14 ,
L_11 ,
V_15 , V_41 ) ;
goto V_27;
}
F_34 ( V_2 ) ;
F_24 ( 1000 , 1100 ) ;
V_41 = F_35 ( V_31 ) ;
if ( V_41 ) {
F_6 ( V_2 -> V_14 , L_12 ,
V_15 , V_41 ) ;
goto V_27;
}
V_41 = F_36 ( V_31 ) ;
if ( V_41 )
F_6 ( V_2 -> V_14 ,
L_13 ,
V_15 , V_41 ) ;
F_27 ( V_21 ) ;
V_27:
return V_41 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_38 ( V_2 ,
F_39 ( V_2 , V_45 ) | V_46 ,
V_45 ) ;
F_30 () ;
}
static int F_40 ( struct V_1 * V_2 ,
enum V_47 V_48 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
int V_12 = 0 ;
switch ( V_48 ) {
case V_49 :
F_31 ( V_2 ) ;
V_12 = F_15 ( V_21 ) ;
break;
case V_50 :
V_12 = F_20 ( V_2 ) ;
F_37 ( V_2 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_14 , V_15 , V_48 ) ;
V_12 = - V_51 ;
break;
}
return V_12 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_52 ,
T_1 V_53 , T_1 V_54 , bool V_55 )
{
int V_41 = 0 ;
struct V_20 * V_21 = F_18 ( V_2 ) ;
struct V_56 * V_57 ;
T_1 V_58 ;
T_1 V_59 = 0 ;
unsigned long V_60 = 0 ;
T_1 V_61 = 0 ;
static T_1 V_62 [] [ 2 ] = {
{ V_63 , 0x1 } ,
{ V_64 , 0x1 } ,
{ V_65 , 0x1 } ,
{ V_66 , 0x1 } ,
} ;
static T_1 V_67 [] [ 2 ] = {
{ V_68 , 0x1F } ,
{ V_69 , 0x3e } ,
{ V_70 , 0x7D } ,
} ;
static T_1 V_71 [] [ 2 ] = {
{ V_68 , 0x24 } ,
{ V_69 , 0x49 } ,
{ V_70 , 0x92 } ,
} ;
if ( F_29 ( V_21 ) && ! F_42 ( V_2 ) )
goto V_27;
if ( V_52 == 0 ) {
F_6 ( V_2 -> V_14 , L_15 , V_15 , V_52 ) ;
goto V_72;
}
F_43 (clki, &hba->clk_list_head, list) {
if ( ! strcmp ( V_57 -> V_17 , L_16 ) )
V_60 = F_44 ( V_57 -> V_18 ) ;
}
if ( V_60 < V_73 )
V_60 = V_73 ;
V_61 = V_60 / V_74 ;
if ( F_39 ( V_2 , V_75 ) != V_61 ) {
F_38 ( V_2 , V_61 , V_75 ) ;
F_30 () ;
}
if ( F_29 ( V_21 ) )
goto V_27;
V_58 = V_76 / V_60 ;
V_58 <<= V_77 ;
V_58 &= V_78 ;
switch ( V_53 ) {
case V_79 :
case V_80 :
if ( V_54 == V_81 ) {
if ( V_52 > F_45 ( V_67 ) ) {
F_6 ( V_2 -> V_14 ,
L_17 ,
V_15 , V_52 ,
F_45 ( V_67 ) ) ;
goto V_72;
}
V_59 = V_67 [ V_52 - 1 ] [ 1 ] ;
} else if ( V_54 == V_44 ) {
if ( V_52 > F_45 ( V_71 ) ) {
F_6 ( V_2 -> V_14 ,
L_17 ,
V_15 , V_52 ,
F_45 ( V_71 ) ) ;
goto V_72;
}
V_59 = V_71 [ V_52 - 1 ] [ 1 ] ;
} else {
F_6 ( V_2 -> V_14 , L_18 ,
V_15 , V_54 ) ;
goto V_72;
}
break;
case V_82 :
case V_83 :
if ( V_52 > F_45 ( V_62 ) ) {
F_6 ( V_2 -> V_14 ,
L_17 ,
V_15 , V_52 ,
F_45 ( V_62 ) ) ;
goto V_72;
}
V_59 = V_62 [ V_52 - 1 ] [ 1 ] ;
break;
case V_84 :
default:
F_6 ( V_2 -> V_14 , L_19 , V_15 , V_53 ) ;
goto V_72;
}
if ( F_39 ( V_2 , V_85 ) !=
( V_58 | V_59 ) ) {
F_38 ( V_2 , V_58 | V_59 ,
V_85 ) ;
F_30 () ;
}
if ( V_55 ) {
F_38 ( V_2 , ( ( V_60 / V_86 ) * 100 ) ,
V_87 ) ;
F_30 () ;
}
goto V_27;
V_72:
V_41 = - V_51 ;
V_27:
return V_41 ;
}
static int F_46 ( struct V_1 * V_2 ,
enum V_47 V_48 )
{
int V_12 = 0 ;
struct V_20 * V_21 = F_18 ( V_2 ) ;
switch ( V_48 ) {
case V_49 :
if ( F_41 ( V_2 , V_63 , V_82 ,
0 , true ) ) {
F_6 ( V_2 -> V_14 , L_20 ,
V_15 ) ;
V_12 = - V_51 ;
goto V_27;
}
if ( F_29 ( V_21 ) )
V_12 = F_47 ( V_2 ,
150 ) ;
break;
case V_50 :
F_17 ( V_2 ) ;
break;
default:
break;
}
V_27:
return V_12 ;
}
static int F_48 ( struct V_1 * V_2 , enum V_88 V_89 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
struct V_31 * V_31 = V_21 -> V_32 ;
int V_41 = 0 ;
if ( F_49 ( V_2 ) ) {
F_13 ( V_21 ) ;
F_50 ( V_31 ) ;
F_32 ( V_2 ) ;
goto V_27;
}
if ( ! F_51 ( V_2 ) ) {
F_13 ( V_21 ) ;
F_50 ( V_31 ) ;
}
V_27:
return V_41 ;
}
static int F_52 ( struct V_1 * V_2 , enum V_88 V_89 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
struct V_31 * V_31 = V_21 -> V_32 ;
int V_12 ;
V_12 = F_53 ( V_31 ) ;
if ( V_12 ) {
F_6 ( V_2 -> V_14 , L_21 ,
V_15 , V_12 ) ;
goto V_27;
}
V_12 = F_15 ( V_21 ) ;
if ( V_12 )
goto V_27;
V_2 -> V_90 = false ;
V_27:
return V_12 ;
}
static int F_54 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
struct V_93 * V_95 )
{
int V_96 ;
int V_97 ;
bool V_98 = false ;
bool V_99 = false ;
if ( V_94 -> V_100 == V_80 )
V_98 = true ;
if ( V_92 -> V_101 == V_102 ) {
V_99 = true ;
V_96 = F_55 ( T_1 , V_92 -> V_103 ,
V_92 -> V_104 ) ;
} else {
V_96 = F_55 ( T_1 , V_92 -> V_105 ,
V_92 -> V_106 ) ;
}
if ( ! V_98 && V_99 ) {
F_56 ( L_22 ,
V_15 ) ;
return - V_107 ;
} else if ( V_98 && V_99 ) {
V_95 -> V_100 = V_95 -> V_108 =
V_92 -> V_109 ;
} else {
V_95 -> V_100 = V_95 -> V_108 =
V_92 -> V_110 ;
}
V_95 -> V_111 = F_55 ( T_1 , V_94 -> V_111 ,
V_92 -> V_11 ) ;
V_95 -> V_112 = F_55 ( T_1 , V_94 -> V_112 ,
V_92 -> V_113 ) ;
V_97 = F_55 ( T_1 , V_94 -> V_114 , V_94 -> V_115 ) ;
if ( ( V_98 && V_99 ) ||
( ! V_98 && ! V_99 ) )
V_95 -> V_114 = V_95 -> V_115 =
F_55 ( T_1 , V_97 , V_96 ) ;
else if ( ! V_98 )
V_95 -> V_114 = V_95 -> V_115 = V_97 ;
else
V_95 -> V_114 = V_95 -> V_115 = V_96 ;
V_95 -> V_116 = V_92 -> V_116 ;
return 0 ;
}
static int F_57 ( struct V_20 * V_21 ,
const char * V_117 )
{
struct V_16 * V_14 = V_21 -> V_2 -> V_14 ;
struct V_118 * V_119 = V_14 -> V_120 ;
int V_12 ;
const char * V_121 = L_23 ;
if ( ! V_117 ) {
V_12 = - V_51 ;
goto V_27;
}
if ( V_21 -> V_122 . V_123 && ! ! strcmp ( V_117 , L_24 ) )
V_12 = F_58 ( V_119 , V_121 , L_25 ) ;
else
V_12 = F_58 ( V_119 , V_121 , V_117 ) ;
V_27:
if ( V_12 < 0 )
F_6 ( V_14 , L_26 ,
V_15 , V_117 , V_12 ) ;
return V_12 ;
}
static void F_59 ( struct V_93 * V_124 , char * V_125 )
{
int V_52 = F_60 ( T_1 , V_124 -> V_114 , V_124 -> V_115 ) ;
int V_126 = F_60 ( T_1 , V_124 -> V_112 , V_124 -> V_111 ) ;
int V_127 ;
if ( ! V_52 )
V_52 = 1 ;
if ( ! V_126 )
V_126 = 1 ;
if ( ! V_124 -> V_100 && ! V_124 -> V_108 ) {
V_127 = V_82 ;
snprintf ( V_125 , V_128 , L_24 ) ;
} else if ( V_124 -> V_100 == V_80 || V_124 -> V_100 == V_79 ||
V_124 -> V_108 == V_80 || V_124 -> V_108 == V_79 ) {
V_127 = V_80 ;
snprintf ( V_125 , V_128 , L_27 , L_28 ,
V_124 -> V_116 == V_44 ? L_29 : L_30 , V_52 , V_126 ) ;
} else {
V_127 = V_83 ;
snprintf ( V_125 , V_128 , L_31 ,
L_32 , V_52 , V_126 ) ;
}
}
static int F_61 ( struct V_20 * V_21 , int V_129 )
{
int V_12 = 0 ;
if ( V_129 != V_21 -> V_122 . V_130 ) {
V_12 = F_62 (
V_21 -> V_122 . V_131 , V_129 ) ;
if ( V_12 ) {
F_6 ( V_21 -> V_2 -> V_14 ,
L_33 ,
V_15 , V_21 -> V_122 . V_131 ,
V_129 , V_12 ) ;
goto V_27;
}
V_21 -> V_122 . V_130 = V_129 ;
}
V_27:
return V_12 ;
}
static int F_63 ( struct V_20 * V_21 )
{
int V_129 ;
int V_12 = 0 ;
char V_132 [ V_128 ] ;
F_59 ( & V_21 -> V_133 , V_132 ) ;
V_129 = F_57 ( V_21 , V_132 ) ;
if ( V_129 >= 0 )
V_12 = F_61 ( V_21 , V_129 ) ;
else
V_12 = V_129 ;
if ( V_12 )
F_6 ( V_21 -> V_2 -> V_14 , L_34 , V_15 , V_12 ) ;
else
V_21 -> V_122 . V_134 = V_129 ;
return V_12 ;
}
static T_2
F_64 ( struct V_16 * V_14 , struct V_135 * V_136 ,
char * V_137 )
{
struct V_1 * V_2 = F_65 ( V_14 ) ;
struct V_20 * V_21 = F_18 ( V_2 ) ;
return snprintf ( V_137 , V_138 , L_35 ,
V_21 -> V_122 . V_123 ) ;
}
static T_2
F_66 ( struct V_16 * V_14 , struct V_135 * V_136 ,
const char * V_137 , T_3 V_139 )
{
struct V_1 * V_2 = F_65 ( V_14 ) ;
struct V_20 * V_21 = F_18 ( V_2 ) ;
T_4 V_140 ;
if ( ! F_67 ( V_137 , 0 , & V_140 ) ) {
V_21 -> V_122 . V_123 = ! ! V_140 ;
F_63 ( V_21 ) ;
}
return V_139 ;
}
static int F_68 ( struct V_20 * V_21 )
{
int V_12 ;
struct V_141 * V_142 ;
struct V_16 * V_14 = V_21 -> V_2 -> V_14 ;
struct V_143 * V_144 = F_69 ( V_14 ) ;
struct V_118 * V_119 = V_14 -> V_120 ;
V_142 = F_70 ( V_144 ) ;
if ( ! V_142 ) {
F_6 ( V_14 , L_36 , V_15 ) ;
V_12 = - V_145 ;
goto V_27;
}
V_12 = F_71 ( V_119 , L_23 ) ;
if ( V_12 < 0 || V_12 != V_142 -> V_146 ) {
F_6 ( V_14 , L_37 ,
V_15 , V_12 ) ;
goto V_27;
}
V_21 -> V_122 . V_131 = F_72 ( V_142 ) ;
if ( ! V_21 -> V_122 . V_131 ) {
F_6 ( V_14 , L_38 ,
V_15 ) ;
V_12 = - V_147 ;
goto V_27;
}
V_21 -> V_122 . V_148 = F_57 ( V_21 , L_24 ) ;
V_21 -> V_122 . V_149 = F_57 ( V_21 , L_25 ) ;
V_21 -> V_122 . V_150 . V_151 = F_64 ;
V_21 -> V_122 . V_150 . V_152 = F_66 ;
F_73 ( & V_21 -> V_122 . V_150 . V_136 ) ;
V_21 -> V_122 . V_150 . V_136 . V_17 = L_39 ;
V_21 -> V_122 . V_150 . V_136 . V_132 = V_153 | V_154 ;
V_12 = F_74 ( V_14 , & V_21 -> V_122 . V_150 ) ;
V_27:
return V_12 ;
}
static int F_63 ( struct V_20 * V_21 )
{
return 0 ;
}
static int F_61 ( struct V_20 * V_21 , int V_129 )
{
return 0 ;
}
static int F_68 ( struct V_20 * V_21 )
{
return 0 ;
}
static void F_75 ( struct V_20 * V_21 , bool V_155 )
{
if ( V_21 -> V_156 &&
( V_155 ^ V_21 -> V_157 ) ) {
T_1 V_158 = F_76 ( V_21 -> V_156 ) ;
if ( V_155 )
V_158 |= V_21 -> V_159 ;
else
V_158 &= ~ V_21 -> V_159 ;
if ( ! V_155 )
F_77 ( 1 ) ;
F_78 ( V_158 , V_21 -> V_156 ) ;
F_79 () ;
if ( V_155 )
F_77 ( 1 ) ;
V_21 -> V_157 = V_155 ;
}
}
static int F_80 ( struct V_1 * V_2 ,
enum V_47 V_48 ,
struct V_93 * V_160 ,
struct V_93 * V_133 )
{
T_1 V_161 ;
struct V_20 * V_21 = F_18 ( V_2 ) ;
struct V_31 * V_31 = V_21 -> V_32 ;
struct V_91 V_162 ;
int V_41 = 0 ;
int V_163 = 0 ;
if ( ! V_133 ) {
F_56 ( L_40 , V_15 ) ;
V_41 = - V_51 ;
goto V_27;
}
switch ( V_48 ) {
case V_49 :
V_162 . V_11 = V_164 ;
V_162 . V_113 = V_165 ;
V_162 . V_103 = V_166 ;
V_162 . V_104 = V_167 ;
V_162 . V_105 = V_168 ;
V_162 . V_106 = V_169 ;
V_162 . V_110 = V_170 ;
V_162 . V_171 = V_172 ;
V_162 . V_109 = V_173 ;
V_162 . V_174 = V_175 ;
V_162 . V_116 = V_43 ;
V_162 . V_101 =
V_176 ;
if ( V_21 -> V_177 . V_178 == 0x1 ) {
if ( V_162 . V_104 > V_69 )
V_162 . V_104 = V_69 ;
if ( V_162 . V_103 > V_69 )
V_162 . V_103 = V_69 ;
}
V_41 = F_54 ( & V_162 ,
V_160 ,
V_133 ) ;
if ( V_41 ) {
F_56 ( L_41 ,
V_15 ) ;
goto V_27;
}
break;
case V_50 :
if ( F_41 ( V_2 , V_133 -> V_114 ,
V_133 -> V_100 ,
V_133 -> V_116 , false ) ) {
F_6 ( V_2 -> V_14 , L_20 ,
V_15 ) ;
V_41 = - V_51 ;
}
V_161 = ~ ( V_179 << V_133 -> V_111 ) ;
V_163 = F_19 ( V_31 , V_161 ) ;
if ( V_163 ) {
F_6 ( V_2 -> V_14 , L_42 ,
V_15 , V_163 ) ;
V_41 = V_163 ;
}
memcpy ( & V_21 -> V_133 ,
V_133 , sizeof( * V_133 ) ) ;
F_63 ( V_21 ) ;
break;
default:
V_41 = - V_51 ;
break;
}
V_27:
return V_41 ;
}
static T_1 F_81 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
if ( V_21 -> V_177 . V_178 == 0x1 )
return V_180 ;
else
return V_181 ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
if ( V_21 -> V_177 . V_178 == 0x01 ) {
V_2 -> V_182 |= V_183
| V_184
| V_185 ;
if ( V_21 -> V_177 . V_186 == 0x0001 && V_21 -> V_177 . V_187 == 0x0001 )
V_2 -> V_182 |= V_188 ;
V_2 -> V_182 |= V_189 ;
}
if ( V_21 -> V_177 . V_178 >= 0x2 ) {
V_2 -> V_182 |= V_190 ;
if ( ! F_29 ( V_21 ) )
V_2 -> V_182 |= ( V_183
| V_185
| V_184 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
V_2 -> V_191 |= V_192 | V_193 ;
V_2 -> V_191 |= V_194 ;
V_2 -> V_191 |= V_195 ;
if ( V_21 -> V_177 . V_178 >= 0x2 ) {
V_21 -> V_191 = V_196 |
V_197 ;
}
}
static int F_84 ( struct V_1 * V_2 , bool V_198 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
int V_12 ;
int V_129 = 0 ;
if ( ! V_21 )
return 0 ;
if ( V_198 ) {
V_12 = F_85 ( V_21 -> V_32 ) ;
if ( V_12 )
goto V_27;
V_12 = F_86 ( V_21 -> V_32 ) ;
if ( V_12 ) {
F_6 ( V_2 -> V_14 , L_43 ,
V_15 , V_12 ) ;
F_87 ( V_21 -> V_32 ) ;
goto V_27;
}
V_129 = V_21 -> V_122 . V_134 ;
if ( V_129 == V_21 -> V_122 . V_148 )
F_63 ( V_21 ) ;
} else {
F_87 ( V_21 -> V_32 ) ;
if ( ! F_51 ( V_2 ) )
F_75 ( V_21 , false ) ;
V_129 = V_21 -> V_122 . V_148 ;
}
V_12 = F_61 ( V_21 , V_129 ) ;
if ( V_12 )
F_6 ( V_2 -> V_14 , L_44 ,
V_15 , V_12 ) ;
V_27:
return V_12 ;
}
static int T_5 F_88 ( char * V_199 )
{
F_89 ( V_200 , V_199 , V_201 ) ;
return 1 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_16 * V_14 = V_2 -> V_14 ;
struct V_143 * V_144 = F_69 ( V_14 ) ;
struct V_20 * V_21 ;
struct V_202 * V_163 ;
if ( strlen ( V_200 ) && strcmp ( V_200 , F_91 ( V_14 ) ) )
return - V_203 ;
V_21 = F_92 ( V_14 , sizeof( * V_21 ) , V_204 ) ;
if ( ! V_21 ) {
V_12 = - V_205 ;
F_6 ( V_14 , L_45 , V_15 ) ;
goto V_27;
}
V_21 -> V_2 = V_2 ;
F_93 ( V_2 , V_21 ) ;
V_21 -> V_32 = F_94 ( V_14 , L_46 ) ;
if ( F_9 ( V_21 -> V_32 ) ) {
V_12 = F_10 ( V_21 -> V_32 ) ;
F_6 ( V_14 , L_47 , V_15 , V_12 ) ;
goto V_27;
}
V_12 = F_68 ( V_21 ) ;
if ( V_12 )
goto V_206;
F_95 ( V_2 , & V_21 -> V_177 . V_178 ,
& V_21 -> V_177 . V_186 , & V_21 -> V_177 . V_187 ) ;
if ( V_21 -> V_177 . V_178 >= 0x02 ) {
V_21 -> V_156 = V_2 -> V_10 + V_40 ;
V_21 -> V_159 = F_96 ( 26 ) ;
} else {
V_163 = F_97 ( V_144 , V_207 , 1 ) ;
if ( V_163 ) {
V_21 -> V_156 =
F_98 ( V_14 , V_163 ) ;
if ( F_9 ( V_21 -> V_156 ) ) {
F_99 ( V_14 ,
L_48 ,
V_15 ,
F_10 ( V_21 -> V_156 ) ) ;
V_21 -> V_156 = NULL ;
}
V_21 -> V_159 = F_96 ( 5 ) ;
}
}
F_100 ( V_21 -> V_32 ,
V_21 -> V_177 . V_178 , V_21 -> V_177 . V_186 , V_21 -> V_177 . V_187 ) ;
F_101 ( V_21 -> V_32 ) ;
V_12 = F_53 ( V_21 -> V_32 ) ;
if ( V_12 )
goto V_208;
V_12 = F_16 ( V_21 ) ;
if ( V_12 )
goto V_209;
F_83 ( V_2 ) ;
F_82 ( V_2 ) ;
F_84 ( V_2 , true ) ;
if ( V_2 -> V_14 -> V_210 < V_211 )
V_212 [ V_2 -> V_14 -> V_210 ] = V_21 ;
V_21 -> V_213 |= V_214 ;
F_102 ( V_21 ) ;
V_12 = F_103 ( V_21 ) ;
if ( V_12 ) {
F_99 ( V_14 , L_49 ,
V_15 , V_12 ) ;
V_12 = 0 ;
}
goto V_27;
V_209:
F_50 ( V_21 -> V_32 ) ;
V_208:
F_104 ( V_21 -> V_32 ) ;
V_206:
F_105 ( V_14 , V_21 ) ;
F_93 ( V_2 , NULL ) ;
V_27:
return V_12 ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
F_13 ( V_21 ) ;
F_50 ( V_21 -> V_32 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
T_1 V_215 )
{
int V_12 ;
T_1 V_216 ;
if ( V_215 > V_217 )
return - V_51 ;
V_12 = F_4 ( V_2 ,
F_5 ( V_218 ) ,
& V_216 ) ;
if ( V_12 )
goto V_27;
V_216 &= ~ V_217 ;
V_216 |= V_215 ;
V_216 &= ~ V_219 ;
V_12 = F_107 ( V_2 ,
F_5 ( V_218 ) ,
V_216 ) ;
V_27:
return V_12 ;
}
static int F_108 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
if ( ! F_29 ( V_21 ) )
return 0 ;
return F_47 ( V_2 , 150 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
int V_12 ;
T_1 V_216 ;
if ( ! F_29 ( V_21 ) )
return 0 ;
V_12 = F_4 ( V_2 ,
F_5 ( V_218 ) ,
& V_216 ) ;
if ( ! V_12 &&
( V_216 & V_219 ) ) {
V_216 &= ~ V_219 ;
V_12 = F_107 ( V_2 ,
F_5 ( V_218 ) ,
V_216 ) ;
}
return V_12 ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
if ( ! F_29 ( V_21 ) )
return 0 ;
return F_47 ( V_2 , 75 ) ;
}
static int F_112 ( struct V_1 * V_2 ,
bool V_220 , enum V_47 V_48 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
struct V_93 * V_133 = & V_21 -> V_133 ;
int V_12 = 0 ;
if ( V_48 == V_49 ) {
if ( V_220 )
V_12 = F_108 ( V_2 ) ;
else
V_12 = F_110 ( V_2 ) ;
} else {
if ( V_220 )
V_12 = F_109 ( V_2 ) ;
else
V_12 = F_111 ( V_2 ) ;
if ( V_12 || ! V_133 )
goto V_27;
F_41 ( V_2 ,
V_133 -> V_114 ,
V_133 -> V_100 ,
V_133 -> V_116 ,
false ) ;
F_63 ( V_21 ) ;
}
V_27:
return V_12 ;
}
static void F_102 ( struct V_20 * V_21 )
{
V_21 -> V_221 . V_222 = V_223 ;
V_21 -> V_221 . V_224 = 1 ;
}
static bool F_113 ( struct V_20 * V_21 )
{
if ( V_21 -> V_221 . V_222 >= V_225 ) {
F_6 ( V_21 -> V_2 -> V_14 ,
L_50 ,
V_15 , V_21 -> V_221 . V_222 ) ;
return false ;
}
if ( V_21 -> V_221 . V_224 > 0x1F ) {
F_6 ( V_21 -> V_2 -> V_14 ,
L_51 ,
V_15 , V_21 -> V_221 . V_224 ) ;
return false ;
}
return true ;
}
int F_103 ( struct V_20 * V_21 )
{
int V_226 ;
int V_3 ;
T_1 V_227 = V_228 ;
if ( ! V_21 )
return - V_51 ;
if ( ! F_113 ( V_21 ) )
return - V_229 ;
switch ( V_21 -> V_221 . V_222 ) {
case V_223 :
V_226 = V_230 ;
V_3 = 24 ;
break;
case V_231 :
V_226 = V_230 ;
V_3 = 16 ;
break;
case V_232 :
V_226 = V_230 ;
V_3 = 8 ;
break;
case V_233 :
V_226 = V_230 ;
V_3 = 0 ;
break;
case V_234 :
V_226 = V_235 ;
V_3 = 24 ;
break;
case V_236 :
V_226 = V_235 ;
V_3 = 16 ;
break;
case V_237 :
V_226 = V_235 ;
V_3 = 8 ;
break;
case V_238 :
V_226 = V_235 ;
V_3 = 0 ;
break;
case V_239 :
V_226 = V_240 ;
V_3 = 16 ;
break;
case V_241 :
V_226 = V_240 ;
V_3 = 8 ;
break;
case V_242 :
V_226 = V_240 ;
V_3 = 0 ;
break;
case V_243 :
V_226 = V_244 ;
V_3 = 1 ;
break;
}
V_227 <<= V_3 ;
F_114 ( V_21 -> V_2 -> V_14 ) ;
F_115 ( V_21 -> V_2 , false ) ;
F_28 ( V_21 -> V_2 , V_245 ,
( T_1 ) V_21 -> V_221 . V_222 << 19 ,
V_40 ) ;
F_28 ( V_21 -> V_2 , V_227 ,
( T_1 ) V_21 -> V_221 . V_224 << V_3 ,
V_226 ) ;
F_116 ( V_21 -> V_2 ) ;
F_117 ( V_21 -> V_2 -> V_14 ) ;
return 0 ;
}
static void F_118 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_246 , 1 , L_52 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_75 , 16 ,
L_53 ) ;
F_118 ( V_2 ) ;
}
static int F_120 ( struct V_143 * V_144 )
{
int V_12 ;
struct V_16 * V_14 = & V_144 -> V_14 ;
V_12 = F_121 ( V_144 , & V_247 ) ;
if ( V_12 )
F_6 ( V_14 , L_54 , V_12 ) ;
return V_12 ;
}
static int F_122 ( struct V_143 * V_144 )
{
struct V_1 * V_2 = F_123 ( V_144 ) ;
F_114 ( & ( V_144 ) -> V_14 ) ;
F_124 ( V_2 ) ;
return 0 ;
}
