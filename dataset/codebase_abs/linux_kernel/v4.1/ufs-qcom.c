static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 = 0 ;
V_4 = F_2 ( V_2 ,
F_3 ( V_5 ) , V_3 ) ;
if ( V_4 )
F_4 ( V_2 -> V_6 , L_1 ,
V_7 , V_4 ) ;
return V_4 ;
}
static int F_5 ( struct V_8 * V_6 ,
const char * V_9 , struct V_10 * * V_11 )
{
struct V_10 * V_10 ;
int V_4 = 0 ;
V_10 = F_6 ( V_6 , V_9 ) ;
if ( F_7 ( V_10 ) ) {
V_4 = F_8 ( V_10 ) ;
F_4 ( V_6 , L_2 ,
V_7 , V_9 , V_4 ) ;
} else {
* V_11 = V_10 ;
}
return V_4 ;
}
static int F_9 ( struct V_8 * V_6 ,
const char * V_9 , struct V_10 * V_10 )
{
int V_4 = 0 ;
V_4 = F_10 ( V_10 ) ;
if ( V_4 )
F_4 ( V_6 , L_3 , V_7 , V_9 , V_4 ) ;
return V_4 ;
}
static void F_11 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_14 )
return;
F_12 ( V_13 -> V_15 ) ;
F_12 ( V_13 -> V_16 ) ;
F_12 ( V_13 -> V_17 ) ;
F_12 ( V_13 -> V_18 ) ;
V_13 -> V_14 = false ;
}
static int F_13 ( struct V_12 * V_13 )
{
int V_4 = 0 ;
struct V_8 * V_6 = V_13 -> V_2 -> V_6 ;
if ( V_13 -> V_14 )
return 0 ;
V_4 = F_9 ( V_6 , L_4 ,
V_13 -> V_18 ) ;
if ( V_4 )
goto V_19;
V_4 = F_9 ( V_6 , L_5 ,
V_13 -> V_16 ) ;
if ( V_4 )
goto V_20;
V_4 = F_9 ( V_6 , L_6 ,
V_13 -> V_17 ) ;
if ( V_4 )
goto V_21;
V_4 = F_9 ( V_6 , L_7 ,
V_13 -> V_15 ) ;
if ( V_4 )
goto V_22;
V_13 -> V_14 = true ;
goto V_19;
V_22:
F_12 ( V_13 -> V_17 ) ;
V_21:
F_12 ( V_13 -> V_16 ) ;
V_20:
F_12 ( V_13 -> V_18 ) ;
V_19:
return V_4 ;
}
static int F_14 ( struct V_12 * V_13 )
{
int V_4 = 0 ;
struct V_8 * V_6 = V_13 -> V_2 -> V_6 ;
V_4 = F_5 ( V_6 ,
L_4 , & V_13 -> V_18 ) ;
if ( V_4 )
goto V_19;
V_4 = F_5 ( V_6 ,
L_5 , & V_13 -> V_16 ) ;
if ( V_4 )
goto V_19;
V_4 = F_5 ( V_6 , L_6 ,
& V_13 -> V_17 ) ;
if ( V_4 )
goto V_19;
V_4 = F_5 ( V_6 , L_7 ,
& V_13 -> V_15 ) ;
V_19:
return V_4 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
struct V_24 * V_24 = V_13 -> V_25 ;
T_1 V_3 ;
int V_4 = 0 ;
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( V_4 )
goto V_19;
V_4 = F_16 ( V_24 , V_3 ) ;
if ( V_4 )
F_4 ( V_2 -> V_6 , L_8 ,
V_7 ) ;
V_19:
return V_4 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_4 ;
T_1 V_26 = 0 ;
unsigned long V_27 = V_28 + F_18 ( V_29 ) ;
do {
V_4 = F_2 ( V_2 ,
F_3 ( V_30 ) , & V_26 ) ;
if ( V_4 || V_26 == V_31 )
break;
F_19 ( 100 , 200 ) ;
} while ( F_20 ( V_28 , V_27 ) );
if ( F_21 ( V_28 , V_27 ) )
V_4 = F_2 ( V_2 ,
F_3 ( V_30 ) , & V_26 ) ;
if ( V_4 ) {
F_4 ( V_2 -> V_6 , L_9 ,
V_7 , V_4 ) ;
} else if ( V_26 != V_31 ) {
V_4 = V_26 ;
F_4 ( V_2 -> V_6 , L_10 ,
V_7 , V_4 ) ;
}
return V_4 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
struct V_24 * V_24 = V_13 -> V_25 ;
int V_32 = 0 ;
bool V_33 = ( V_34 == V_35 )
? true : false ;
F_23 ( V_2 ) ;
F_19 ( 1000 , 1100 ) ;
V_32 = F_24 ( V_24 , V_33 ) ;
if ( V_32 ) {
F_4 ( V_2 -> V_6 , L_11 ,
V_7 , V_32 ) ;
goto V_19;
}
F_25 ( V_2 ) ;
F_19 ( 1000 , 1100 ) ;
V_32 = F_26 ( V_24 ) ;
if ( V_32 ) {
F_4 ( V_2 -> V_6 , L_12 ,
V_7 , V_32 ) ;
goto V_19;
}
V_32 = F_27 ( V_24 ) ;
if ( V_32 )
F_4 ( V_2 -> V_6 , L_13 ,
V_7 , V_32 ) ;
V_19:
return V_32 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 ,
F_30 ( V_2 , V_36 ) | V_37 ,
V_36 ) ;
F_31 () ;
}
static int F_32 ( struct V_1 * V_2 , bool V_38 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
int V_4 = 0 ;
switch ( V_38 ) {
case V_39 :
F_22 ( V_2 ) ;
V_4 = F_13 ( V_13 ) ;
break;
case V_40 :
V_4 = F_17 ( V_2 ) ;
F_28 ( V_2 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_14 , V_7 , V_38 ) ;
V_4 = - V_41 ;
break;
}
return V_4 ;
}
static unsigned long
F_33 ( struct V_1 * V_2 , T_1 V_42 , T_1 V_43 , T_1 V_44 )
{
struct V_45 * V_46 ;
T_1 V_47 ;
T_1 V_48 = 0 ;
unsigned long V_49 = 0 ;
T_1 V_50 = 0 ;
static T_1 V_51 [] [ 2 ] = {
{ V_52 , 0x1 } ,
{ V_53 , 0x1 } ,
{ V_54 , 0x1 } ,
{ V_55 , 0x1 } ,
} ;
static T_1 V_56 [] [ 2 ] = {
{ V_57 , 0x1F } ,
{ V_58 , 0x3e } ,
} ;
static T_1 V_59 [] [ 2 ] = {
{ V_57 , 0x24 } ,
{ V_58 , 0x49 } ,
} ;
if ( V_42 == 0 ) {
F_4 ( V_2 -> V_6 , L_15 , V_7 , V_42 ) ;
goto V_60;
}
F_34 (clki, &hba->clk_list_head, list) {
if ( ! strcmp ( V_46 -> V_9 , L_16 ) )
V_49 = F_35 ( V_46 -> V_10 ) ;
}
if ( V_49 < V_61 )
V_49 = V_61 ;
V_50 = V_49 / V_62 ;
F_29 ( V_2 , V_50 , V_63 ) ;
V_47 = V_64 / V_49 ;
V_47 <<= V_65 ;
V_47 &= V_66 ;
switch ( V_43 ) {
case V_67 :
case V_68 :
if ( V_44 == V_69 ) {
if ( V_42 > F_36 ( V_56 ) ) {
F_4 ( V_2 -> V_6 ,
L_17 ,
V_7 , V_42 ,
F_36 ( V_56 ) ) ;
goto V_60;
}
V_48 = V_56 [ V_42 - 1 ] [ 1 ] ;
} else if ( V_44 == V_35 ) {
if ( V_42 > F_36 ( V_59 ) ) {
F_4 ( V_2 -> V_6 ,
L_17 ,
V_7 , V_42 ,
F_36 ( V_59 ) ) ;
goto V_60;
}
V_48 = V_59 [ V_42 - 1 ] [ 1 ] ;
} else {
F_4 ( V_2 -> V_6 , L_18 ,
V_7 , V_44 ) ;
goto V_60;
}
break;
case V_70 :
case V_71 :
if ( V_42 > F_36 ( V_51 ) ) {
F_4 ( V_2 -> V_6 ,
L_17 ,
V_7 , V_42 ,
F_36 ( V_51 ) ) ;
goto V_60;
}
V_48 = V_51 [ V_42 - 1 ] [ 1 ] ;
break;
case V_72 :
default:
F_4 ( V_2 -> V_6 , L_19 , V_7 , V_43 ) ;
goto V_60;
}
F_29 ( V_2 , V_47 | V_48 ,
V_73 ) ;
goto V_19;
V_60:
V_49 = 0 ;
V_19:
return V_49 ;
}
static int F_37 ( struct V_1 * V_2 , bool V_38 )
{
unsigned long V_49 = 0 ;
T_1 V_74 ;
switch ( V_38 ) {
case V_39 :
V_49 = F_33 ( V_2 , V_52 ,
V_70 , 0 ) ;
if ( ! V_49 ) {
F_4 ( V_2 -> V_6 , L_20 ,
V_7 ) ;
return - V_41 ;
}
V_74 =
( V_49 / V_75 ) * 100 ;
F_29 ( V_2 , V_74 ,
V_76 ) ;
break;
case V_40 :
F_15 ( V_2 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , enum V_77 V_78 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
struct V_24 * V_24 = V_13 -> V_25 ;
int V_32 = 0 ;
if ( F_39 ( V_2 ) ) {
F_11 ( V_13 ) ;
F_40 ( V_24 ) ;
F_23 ( V_2 ) ;
goto V_19;
}
if ( ! F_41 ( V_2 ) )
F_40 ( V_24 ) ;
V_19:
return V_32 ;
}
static int F_42 ( struct V_1 * V_2 , enum V_77 V_78 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
struct V_24 * V_24 = V_13 -> V_25 ;
int V_4 ;
V_4 = F_43 ( V_24 ) ;
if ( V_4 ) {
F_4 ( V_2 -> V_6 , L_21 ,
V_7 , V_4 ) ;
goto V_19;
}
V_2 -> V_79 = false ;
V_19:
return V_4 ;
}
static int F_44 ( struct V_80 * V_81 ,
struct V_82 * V_83 ,
struct V_82 * V_84 )
{
int V_85 ;
int V_86 ;
bool V_87 = false ;
bool V_88 = false ;
if ( V_83 -> V_89 == V_68 )
V_87 = true ;
if ( V_81 -> V_90 == V_91 ) {
V_88 = true ;
V_85 = F_45 ( T_1 , V_81 -> V_92 ,
V_81 -> V_93 ) ;
} else {
V_85 = F_45 ( T_1 , V_81 -> V_94 ,
V_81 -> V_95 ) ;
}
if ( ! V_87 && V_88 ) {
F_46 ( L_22 ,
V_7 ) ;
return - V_96 ;
} else if ( V_87 && V_88 ) {
V_84 -> V_89 = V_84 -> V_97 =
V_81 -> V_98 ;
} else {
V_84 -> V_89 = V_84 -> V_97 =
V_81 -> V_99 ;
}
V_84 -> V_100 = F_45 ( T_1 , V_83 -> V_100 ,
V_81 -> V_3 ) ;
V_84 -> V_101 = F_45 ( T_1 , V_83 -> V_101 ,
V_81 -> V_102 ) ;
V_86 = F_45 ( T_1 , V_83 -> V_103 , V_83 -> V_104 ) ;
if ( ( V_87 && V_88 ) ||
( ! V_87 && ! V_88 ) )
V_84 -> V_103 = V_84 -> V_104 =
F_45 ( T_1 , V_86 , V_85 ) ;
else if ( ! V_87 )
V_84 -> V_103 = V_84 -> V_104 = V_86 ;
else
V_84 -> V_103 = V_84 -> V_104 = V_85 ;
V_84 -> V_105 = V_81 -> V_105 ;
return 0 ;
}
static int F_47 ( struct V_12 * V_13 )
{
int V_106 ;
int V_4 = 0 ;
char V_107 [ V_108 ] ;
F_48 ( & V_13 -> V_109 , V_107 ) ;
V_106 = F_49 ( V_13 , V_107 ) ;
if ( V_106 >= 0 )
V_4 = F_50 ( V_13 , V_106 ) ;
else
V_4 = V_106 ;
if ( V_4 )
F_4 ( V_13 -> V_2 -> V_6 , L_23 , V_7 , V_4 ) ;
else
V_13 -> V_110 . V_111 = V_106 ;
return V_4 ;
}
static int F_51 ( struct V_1 * V_2 ,
bool V_38 ,
struct V_82 * V_112 ,
struct V_82 * V_109 )
{
T_1 V_113 ;
struct V_12 * V_13 = V_2 -> V_23 ;
struct V_24 * V_24 = V_13 -> V_25 ;
struct V_80 V_114 ;
int V_32 = 0 ;
int V_115 = 0 ;
if ( ! V_109 ) {
F_46 ( L_24 , V_7 ) ;
V_32 = - V_41 ;
goto V_19;
}
switch ( V_38 ) {
case V_39 :
V_114 . V_3 = V_116 ;
V_114 . V_102 = V_117 ;
V_114 . V_92 = V_118 ;
V_114 . V_93 = V_119 ;
V_114 . V_94 = V_120 ;
V_114 . V_95 = V_121 ;
V_114 . V_99 = V_122 ;
V_114 . V_123 = V_124 ;
V_114 . V_98 = V_125 ;
V_114 . V_126 = V_127 ;
V_114 . V_105 = V_34 ;
V_114 . V_90 =
V_128 ;
V_32 = F_44 ( & V_114 ,
V_112 ,
V_109 ) ;
if ( V_32 ) {
F_46 ( L_25 ,
V_7 ) ;
goto V_19;
}
break;
case V_40 :
if ( ! F_33 ( V_2 , V_109 -> V_103 ,
V_109 -> V_89 ,
V_109 -> V_105 ) ) {
F_4 ( V_2 -> V_6 , L_20 ,
V_7 ) ;
V_32 = - V_41 ;
}
V_113 = ~ ( V_129 << V_109 -> V_100 ) ;
V_115 = F_16 ( V_24 , V_113 ) ;
if ( V_115 ) {
F_4 ( V_2 -> V_6 , L_26 ,
V_7 , V_115 ) ;
V_32 = V_115 ;
}
memcpy ( & V_13 -> V_109 ,
V_109 , sizeof( * V_109 ) ) ;
F_47 ( V_13 ) ;
break;
default:
V_32 = - V_41 ;
break;
}
V_19:
return V_32 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
if ( V_13 -> V_130 . V_131 == 0x1 )
V_2 -> V_132 |= V_133 ;
if ( V_13 -> V_130 . V_131 >= 0x2 ) {
if ( ! F_53 ( V_13 ) )
V_2 -> V_132 |= V_133 ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
if ( V_13 -> V_130 . V_131 >= 0x2 )
V_13 -> V_134 = V_135 ;
}
static int F_49 ( struct V_12 * V_13 ,
const char * V_136 )
{
struct V_8 * V_6 = V_13 -> V_2 -> V_6 ;
struct V_137 * V_138 = V_6 -> V_139 ;
int V_4 ;
const char * V_140 = L_27 ;
if ( ! V_136 ) {
V_4 = - V_41 ;
goto V_19;
}
if ( V_13 -> V_110 . V_141 && ! ! strcmp ( V_136 , L_28 ) )
V_4 = F_55 ( V_138 , V_140 , L_29 ) ;
else
V_4 = F_55 ( V_138 , V_140 , V_136 ) ;
V_19:
if ( V_4 < 0 )
F_4 ( V_6 , L_30 ,
V_7 , V_136 , V_4 ) ;
return V_4 ;
}
static int F_50 ( struct V_12 * V_13 , int V_106 )
{
int V_4 = 0 ;
if ( V_106 != V_13 -> V_110 . V_142 )
V_13 -> V_110 . V_142 = V_106 ;
return V_4 ;
}
static void F_48 ( struct V_82 * V_143 , char * V_144 )
{
int V_42 = F_56 ( T_1 , V_143 -> V_103 , V_143 -> V_104 ) ;
int V_145 = F_56 ( T_1 , V_143 -> V_101 , V_143 -> V_100 ) ;
int V_146 ;
if ( ! V_42 )
V_42 = 1 ;
if ( ! V_145 )
V_145 = 1 ;
if ( ! V_143 -> V_89 && ! V_143 -> V_97 ) {
V_146 = V_70 ;
snprintf ( V_144 , V_108 , L_28 ) ;
} else if ( V_143 -> V_89 == V_68 || V_143 -> V_89 == V_67 ||
V_143 -> V_97 == V_68 || V_143 -> V_97 == V_67 ) {
V_146 = V_68 ;
snprintf ( V_144 , V_108 , L_31 , L_32 ,
V_143 -> V_105 == V_35 ? L_33 : L_34 , V_42 , V_145 ) ;
} else {
V_146 = V_71 ;
snprintf ( V_144 , V_108 , L_35 ,
L_36 , V_42 , V_145 ) ;
}
}
static int F_57 ( struct V_1 * V_2 , bool V_147 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
int V_4 = 0 ;
int V_106 = 0 ;
if ( ! V_13 )
return 0 ;
if ( V_147 ) {
V_4 = F_58 ( V_13 -> V_25 ) ;
if ( V_4 )
goto V_19;
V_4 = F_59 ( V_13 -> V_25 ) ;
if ( V_4 ) {
F_4 ( V_2 -> V_6 , L_37 ,
V_7 , V_4 ) ;
F_60 ( V_13 -> V_25 ) ;
goto V_19;
}
F_61 ( V_13 -> V_25 ) ;
V_106 = V_13 -> V_110 . V_111 ;
if ( V_106 == V_13 -> V_110 . V_148 )
F_47 ( V_13 ) ;
} else {
F_60 ( V_13 -> V_25 ) ;
if ( ! F_41 ( V_2 ) ) {
F_62 ( V_13 -> V_25 ) ;
F_63 ( V_13 -> V_25 ) ;
}
V_106 = V_13 -> V_110 . V_148 ;
}
V_4 = F_50 ( V_13 , V_106 ) ;
if ( V_4 )
F_4 ( V_2 -> V_6 , L_38 ,
V_7 , V_4 ) ;
V_19:
return V_4 ;
}
static T_2
F_64 ( struct V_8 * V_6 , struct V_149 * V_150 ,
char * V_151 )
{
struct V_1 * V_2 = F_65 ( V_6 ) ;
struct V_12 * V_13 = V_2 -> V_23 ;
return snprintf ( V_151 , V_152 , L_39 ,
V_13 -> V_110 . V_141 ) ;
}
static T_2
F_66 ( struct V_8 * V_6 , struct V_149 * V_150 ,
const char * V_151 , T_3 V_153 )
{
struct V_1 * V_2 = F_65 ( V_6 ) ;
struct V_12 * V_13 = V_2 -> V_23 ;
T_4 V_154 ;
if ( ! F_67 ( V_151 , 0 , & V_154 ) ) {
V_13 -> V_110 . V_141 = ! ! V_154 ;
F_47 ( V_13 ) ;
}
return V_153 ;
}
static int F_68 ( struct V_12 * V_13 )
{
int V_4 ;
struct V_8 * V_6 = V_13 -> V_2 -> V_6 ;
struct V_137 * V_138 = V_6 -> V_139 ;
V_4 = F_69 ( V_138 , L_27 ) ;
if ( V_4 < 0 ) {
F_4 ( V_6 , L_40 ,
V_7 , V_4 ) ;
goto V_19;
}
V_13 -> V_110 . V_148 = F_49 ( V_13 , L_28 ) ;
V_13 -> V_110 . V_155 = F_49 ( V_13 , L_29 ) ;
V_13 -> V_110 . V_156 . V_157 = F_64 ;
V_13 -> V_110 . V_156 . V_158 = F_66 ;
F_70 ( & V_13 -> V_110 . V_156 . V_150 ) ;
V_13 -> V_110 . V_156 . V_150 . V_9 = L_41 ;
V_13 -> V_110 . V_156 . V_150 . V_107 = V_159 | V_160 ;
V_4 = F_71 ( V_6 , & V_13 -> V_110 . V_156 ) ;
V_19:
return V_4 ;
}
static int F_72 ( char * V_161 )
{
F_73 ( V_162 , V_161 , V_163 ) ;
return 1 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_8 * V_6 = V_2 -> V_6 ;
struct V_12 * V_13 ;
if ( strlen ( V_162 ) && strcmp ( V_162 , F_75 ( V_6 ) ) )
return - V_164 ;
V_13 = F_76 ( V_6 , sizeof( * V_13 ) , V_165 ) ;
if ( ! V_13 ) {
V_4 = - V_166 ;
F_4 ( V_6 , L_42 , V_7 ) ;
goto V_19;
}
V_13 -> V_2 = V_2 ;
V_2 -> V_23 = ( void * ) V_13 ;
V_13 -> V_25 = F_77 ( V_6 , L_43 ) ;
if ( F_7 ( V_13 -> V_25 ) ) {
V_4 = F_8 ( V_13 -> V_25 ) ;
F_4 ( V_6 , L_44 , V_7 , V_4 ) ;
goto V_19;
}
V_4 = F_68 ( V_13 ) ;
if ( V_4 )
goto V_167;
F_78 ( V_2 , & V_13 -> V_130 . V_131 ,
& V_13 -> V_130 . V_168 , & V_13 -> V_130 . V_169 ) ;
F_79 ( V_13 -> V_25 ,
V_13 -> V_130 . V_131 , V_13 -> V_130 . V_168 , V_13 -> V_130 . V_169 ) ;
F_80 ( V_13 -> V_25 ) ;
V_4 = F_43 ( V_13 -> V_25 ) ;
if ( V_4 )
goto V_170;
V_4 = F_14 ( V_13 ) ;
if ( V_4 )
goto V_171;
F_54 ( V_2 ) ;
F_52 ( V_2 ) ;
V_2 -> V_134 |= V_172 | V_173 ;
V_2 -> V_134 |= V_174 ;
F_57 ( V_2 , true ) ;
if ( V_2 -> V_6 -> V_175 < V_176 )
V_177 [ V_2 -> V_6 -> V_175 ] = V_13 ;
goto V_19;
V_171:
F_40 ( V_13 -> V_25 ) ;
V_170:
F_81 ( V_13 -> V_25 ) ;
V_167:
F_82 ( V_6 , V_13 ) ;
V_2 -> V_23 = NULL ;
V_19:
return V_4 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
F_11 ( V_13 ) ;
F_40 ( V_13 -> V_25 ) ;
}
static
void F_84 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
struct V_82 * V_109 = & V_13 -> V_109 ;
if ( ! V_109 )
return;
F_33 ( V_2 , V_109 -> V_103 ,
V_109 -> V_89 ,
V_109 -> V_105 ) ;
}
