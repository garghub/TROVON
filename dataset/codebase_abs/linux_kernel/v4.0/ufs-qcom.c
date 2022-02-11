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
T_2 V_33 ;
T_3 V_34 , V_35 ;
bool V_36 = ( V_37 == V_38 )
? true : false ;
F_23 ( V_2 ) ;
F_19 ( 1000 , 1100 ) ;
F_24 ( V_2 , & V_33 , & V_34 , & V_35 ) ;
F_25 ( V_24 , V_33 , V_34 , V_35 ) ;
V_32 = F_26 ( V_24 , V_36 ) ;
if ( V_32 ) {
F_4 ( V_2 -> V_6 , L_11 ,
V_7 , V_32 ) ;
goto V_19;
}
F_27 ( V_2 ) ;
F_19 ( 1000 , 1100 ) ;
V_32 = F_28 ( V_24 ) ;
if ( V_32 ) {
F_4 ( V_2 -> V_6 , L_12 ,
V_7 , V_32 ) ;
goto V_19;
}
V_32 = F_29 ( V_24 ) ;
if ( V_32 )
F_4 ( V_2 -> V_6 , L_13 ,
V_7 , V_32 ) ;
V_19:
return V_32 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 ,
F_32 ( V_2 , V_39 ) | V_40 ,
V_39 ) ;
F_33 () ;
}
static int F_34 ( struct V_1 * V_2 , bool V_41 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
int V_4 = 0 ;
switch ( V_41 ) {
case V_42 :
F_22 ( V_2 ) ;
V_4 = F_13 ( V_13 ) ;
break;
case V_43 :
V_4 = F_17 ( V_2 ) ;
F_30 ( V_2 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_14 , V_7 , V_41 ) ;
V_4 = - V_44 ;
break;
}
return V_4 ;
}
static unsigned long
F_35 ( struct V_1 * V_2 , T_1 V_45 , T_1 V_46 , T_1 V_47 )
{
struct V_48 * V_49 ;
T_1 V_50 ;
T_1 V_51 = 0 ;
unsigned long V_52 = 0 ;
T_1 V_53 = 0 ;
static T_1 V_54 [] [ 2 ] = {
{ V_55 , 0x1 } ,
{ V_56 , 0x1 } ,
{ V_57 , 0x1 } ,
{ V_58 , 0x1 } ,
} ;
static T_1 V_59 [] [ 2 ] = {
{ V_60 , 0x1F } ,
{ V_61 , 0x3e } ,
} ;
static T_1 V_62 [] [ 2 ] = {
{ V_60 , 0x24 } ,
{ V_61 , 0x49 } ,
} ;
if ( V_45 == 0 ) {
F_4 ( V_2 -> V_6 , L_15 , V_7 , V_45 ) ;
goto V_63;
}
F_36 (clki, &hba->clk_list_head, list) {
if ( ! strcmp ( V_49 -> V_9 , L_16 ) )
V_52 = F_37 ( V_49 -> V_10 ) ;
}
if ( V_52 < V_64 )
V_52 = V_64 ;
V_53 = V_52 / V_65 ;
F_31 ( V_2 , V_53 , V_66 ) ;
V_50 = V_67 / V_52 ;
V_50 <<= V_68 ;
V_50 &= V_69 ;
switch ( V_46 ) {
case V_70 :
case V_71 :
if ( V_47 == V_72 ) {
if ( V_45 > F_38 ( V_59 ) ) {
F_4 ( V_2 -> V_6 ,
L_17 ,
V_7 , V_45 ,
F_38 ( V_59 ) ) ;
goto V_63;
}
V_51 = V_59 [ V_45 - 1 ] [ 1 ] ;
} else if ( V_47 == V_38 ) {
if ( V_45 > F_38 ( V_62 ) ) {
F_4 ( V_2 -> V_6 ,
L_17 ,
V_7 , V_45 ,
F_38 ( V_62 ) ) ;
goto V_63;
}
V_51 = V_62 [ V_45 - 1 ] [ 1 ] ;
} else {
F_4 ( V_2 -> V_6 , L_18 ,
V_7 , V_47 ) ;
goto V_63;
}
break;
case V_73 :
case V_74 :
if ( V_45 > F_38 ( V_54 ) ) {
F_4 ( V_2 -> V_6 ,
L_17 ,
V_7 , V_45 ,
F_38 ( V_54 ) ) ;
goto V_63;
}
V_51 = V_54 [ V_45 - 1 ] [ 1 ] ;
break;
case V_75 :
default:
F_4 ( V_2 -> V_6 , L_19 , V_7 , V_46 ) ;
goto V_63;
}
F_31 ( V_2 , V_50 | V_51 ,
V_76 ) ;
goto V_19;
V_63:
V_52 = 0 ;
V_19:
return V_52 ;
}
static int F_39 ( struct V_1 * V_2 , bool V_41 )
{
unsigned long V_52 = 0 ;
T_1 V_77 ;
switch ( V_41 ) {
case V_42 :
V_52 = F_35 ( V_2 , V_55 ,
V_73 , 0 ) ;
if ( ! V_52 ) {
F_4 ( V_2 -> V_6 , L_20 ,
V_7 ) ;
return - V_44 ;
}
V_77 =
( V_52 / V_78 ) * 100 ;
F_31 ( V_2 , V_77 ,
V_79 ) ;
break;
case V_43 :
F_15 ( V_2 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , enum V_80 V_81 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
struct V_24 * V_24 = V_13 -> V_25 ;
int V_32 = 0 ;
if ( F_41 ( V_2 ) ) {
F_11 ( V_13 ) ;
F_42 ( V_24 ) ;
F_23 ( V_2 ) ;
goto V_19;
}
if ( ! F_43 ( V_2 ) )
F_42 ( V_24 ) ;
V_19:
return V_32 ;
}
static int F_44 ( struct V_1 * V_2 , enum V_80 V_81 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
struct V_24 * V_24 = V_13 -> V_25 ;
int V_4 ;
V_4 = F_45 ( V_24 ) ;
if ( V_4 ) {
F_4 ( V_2 -> V_6 , L_21 ,
V_7 , V_4 ) ;
goto V_19;
}
V_2 -> V_82 = false ;
V_19:
return V_4 ;
}
static int F_46 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
struct V_85 * V_87 )
{
int V_88 ;
int V_89 ;
bool V_90 = false ;
bool V_91 = false ;
if ( V_86 -> V_92 == V_71 )
V_90 = true ;
if ( V_84 -> V_93 == V_94 ) {
V_91 = true ;
V_88 = F_47 ( T_1 , V_84 -> V_95 ,
V_84 -> V_96 ) ;
} else {
V_88 = F_47 ( T_1 , V_84 -> V_97 ,
V_84 -> V_98 ) ;
}
if ( ! V_90 && V_91 ) {
F_48 ( L_22 ,
V_7 ) ;
return - V_99 ;
} else if ( V_90 && V_91 ) {
V_87 -> V_92 = V_87 -> V_100 =
V_84 -> V_101 ;
} else {
V_87 -> V_92 = V_87 -> V_100 =
V_84 -> V_102 ;
}
V_87 -> V_103 = F_47 ( T_1 , V_86 -> V_103 ,
V_84 -> V_3 ) ;
V_87 -> V_104 = F_47 ( T_1 , V_86 -> V_104 ,
V_84 -> V_105 ) ;
V_89 = F_47 ( T_1 , V_86 -> V_106 , V_86 -> V_107 ) ;
if ( ( V_90 && V_91 ) ||
( ! V_90 && ! V_91 ) )
V_87 -> V_106 = V_87 -> V_107 =
F_47 ( T_1 , V_89 , V_88 ) ;
else if ( ! V_90 )
V_87 -> V_106 = V_87 -> V_107 = V_89 ;
else
V_87 -> V_106 = V_87 -> V_107 = V_88 ;
V_87 -> V_108 = V_84 -> V_108 ;
return 0 ;
}
static int F_49 ( struct V_12 * V_13 )
{
int V_109 ;
int V_4 = 0 ;
char V_110 [ V_111 ] ;
F_50 ( & V_13 -> V_112 , V_110 ) ;
V_109 = F_51 ( V_13 , V_110 ) ;
if ( V_109 >= 0 )
V_4 = F_52 ( V_13 , V_109 ) ;
else
V_4 = V_109 ;
if ( V_4 )
F_4 ( V_13 -> V_2 -> V_6 , L_23 , V_7 , V_4 ) ;
else
V_13 -> V_113 . V_114 = V_109 ;
return V_4 ;
}
static int F_53 ( struct V_1 * V_2 ,
bool V_41 ,
struct V_85 * V_115 ,
struct V_85 * V_112 )
{
T_1 V_116 ;
struct V_12 * V_13 = V_2 -> V_23 ;
struct V_24 * V_24 = V_13 -> V_25 ;
struct V_83 V_117 ;
int V_32 = 0 ;
int V_118 = 0 ;
if ( ! V_112 ) {
F_48 ( L_24 , V_7 ) ;
V_32 = - V_44 ;
goto V_19;
}
switch ( V_41 ) {
case V_42 :
V_117 . V_3 = V_119 ;
V_117 . V_105 = V_120 ;
V_117 . V_95 = V_121 ;
V_117 . V_96 = V_122 ;
V_117 . V_97 = V_123 ;
V_117 . V_98 = V_124 ;
V_117 . V_102 = V_125 ;
V_117 . V_126 = V_127 ;
V_117 . V_101 = V_128 ;
V_117 . V_129 = V_130 ;
V_117 . V_108 = V_37 ;
V_117 . V_93 =
V_131 ;
V_32 = F_46 ( & V_117 ,
V_115 ,
V_112 ) ;
if ( V_32 ) {
F_48 ( L_25 ,
V_7 ) ;
goto V_19;
}
break;
case V_43 :
if ( ! F_35 ( V_2 , V_112 -> V_106 ,
V_112 -> V_92 ,
V_112 -> V_108 ) ) {
F_4 ( V_2 -> V_6 , L_20 ,
V_7 ) ;
V_32 = - V_44 ;
}
V_116 = ~ ( V_132 << V_112 -> V_103 ) ;
V_118 = F_16 ( V_24 , V_116 ) ;
if ( V_118 ) {
F_4 ( V_2 -> V_6 , L_26 ,
V_7 , V_118 ) ;
V_32 = V_118 ;
}
memcpy ( & V_13 -> V_112 ,
V_112 , sizeof( * V_112 ) ) ;
F_49 ( V_13 ) ;
break;
default:
V_32 = - V_44 ;
break;
}
V_19:
return V_32 ;
}
static void F_54 ( struct V_1 * V_2 )
{
T_2 V_33 ;
T_3 V_34 , V_35 ;
F_24 ( V_2 , & V_33 , & V_34 , & V_35 ) ;
}
static int F_51 ( struct V_12 * V_13 ,
const char * V_133 )
{
struct V_8 * V_6 = V_13 -> V_2 -> V_6 ;
struct V_134 * V_135 = V_6 -> V_136 ;
int V_4 ;
const char * V_137 = L_27 ;
if ( ! V_133 ) {
V_4 = - V_44 ;
goto V_19;
}
if ( V_13 -> V_113 . V_138 && ! ! strcmp ( V_133 , L_28 ) )
V_4 = F_55 ( V_135 , V_137 , L_29 ) ;
else
V_4 = F_55 ( V_135 , V_137 , V_133 ) ;
V_19:
if ( V_4 < 0 )
F_4 ( V_6 , L_30 ,
V_7 , V_133 , V_4 ) ;
return V_4 ;
}
static int F_52 ( struct V_12 * V_13 , int V_109 )
{
int V_4 = 0 ;
if ( V_109 != V_13 -> V_113 . V_139 )
V_13 -> V_113 . V_139 = V_109 ;
return V_4 ;
}
static void F_50 ( struct V_85 * V_140 , char * V_141 )
{
int V_45 = F_56 ( T_1 , V_140 -> V_106 , V_140 -> V_107 ) ;
int V_142 = F_56 ( T_1 , V_140 -> V_104 , V_140 -> V_103 ) ;
int V_143 ;
if ( ! V_45 )
V_45 = 1 ;
if ( ! V_142 )
V_142 = 1 ;
if ( ! V_140 -> V_92 && ! V_140 -> V_100 ) {
V_143 = V_73 ;
snprintf ( V_141 , V_111 , L_28 ) ;
} else if ( V_140 -> V_92 == V_71 || V_140 -> V_92 == V_70 ||
V_140 -> V_100 == V_71 || V_140 -> V_100 == V_70 ) {
V_143 = V_71 ;
snprintf ( V_141 , V_111 , L_31 , L_32 ,
V_140 -> V_108 == V_38 ? L_33 : L_34 , V_45 , V_142 ) ;
} else {
V_143 = V_74 ;
snprintf ( V_141 , V_111 , L_35 ,
L_36 , V_45 , V_142 ) ;
}
}
static int F_57 ( struct V_1 * V_2 , bool V_144 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
int V_4 = 0 ;
int V_109 = 0 ;
if ( ! V_13 )
return 0 ;
if ( V_144 ) {
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
V_109 = V_13 -> V_113 . V_114 ;
if ( V_109 == V_13 -> V_113 . V_145 )
F_49 ( V_13 ) ;
} else {
F_60 ( V_13 -> V_25 ) ;
if ( ! F_43 ( V_2 ) ) {
F_62 ( V_13 -> V_25 ) ;
F_63 ( V_13 -> V_25 ) ;
}
V_109 = V_13 -> V_113 . V_145 ;
}
V_4 = F_52 ( V_13 , V_109 ) ;
if ( V_4 )
F_4 ( V_2 -> V_6 , L_38 ,
V_7 , V_4 ) ;
V_19:
return V_4 ;
}
static T_4
F_64 ( struct V_8 * V_6 , struct V_146 * V_147 ,
char * V_148 )
{
struct V_1 * V_2 = F_65 ( V_6 ) ;
struct V_12 * V_13 = V_2 -> V_23 ;
return snprintf ( V_148 , V_149 , L_39 ,
V_13 -> V_113 . V_138 ) ;
}
static T_4
F_66 ( struct V_8 * V_6 , struct V_146 * V_147 ,
const char * V_148 , T_5 V_150 )
{
struct V_1 * V_2 = F_65 ( V_6 ) ;
struct V_12 * V_13 = V_2 -> V_23 ;
T_6 V_151 ;
if ( ! F_67 ( V_148 , 0 , & V_151 ) ) {
V_13 -> V_113 . V_138 = ! ! V_151 ;
F_49 ( V_13 ) ;
}
return V_150 ;
}
static int F_68 ( struct V_12 * V_13 )
{
int V_4 ;
struct V_8 * V_6 = V_13 -> V_2 -> V_6 ;
struct V_134 * V_135 = V_6 -> V_136 ;
V_4 = F_69 ( V_135 , L_27 ) ;
if ( V_4 < 0 ) {
F_4 ( V_6 , L_40 ,
V_7 , V_4 ) ;
goto V_19;
}
V_13 -> V_113 . V_145 = F_51 ( V_13 , L_28 ) ;
V_13 -> V_113 . V_152 = F_51 ( V_13 , L_29 ) ;
V_13 -> V_113 . V_153 . V_154 = F_64 ;
V_13 -> V_113 . V_153 . V_155 = F_66 ;
F_70 ( & V_13 -> V_113 . V_153 . V_147 ) ;
V_13 -> V_113 . V_153 . V_147 . V_9 = L_41 ;
V_13 -> V_113 . V_153 . V_147 . V_110 = V_156 | V_157 ;
V_4 = F_71 ( V_6 , & V_13 -> V_113 . V_153 ) ;
V_19:
return V_4 ;
}
static int F_72 ( char * V_158 )
{
F_73 ( V_159 , V_158 , V_160 ) ;
return 1 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_8 * V_6 = V_2 -> V_6 ;
struct V_12 * V_13 ;
if ( strlen ( V_159 ) && strcmp ( V_159 , F_75 ( V_6 ) ) )
return - V_161 ;
V_13 = F_76 ( V_6 , sizeof( * V_13 ) , V_162 ) ;
if ( ! V_13 ) {
V_4 = - V_163 ;
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
goto V_164;
F_78 ( V_13 -> V_25 ) ;
V_4 = F_45 ( V_13 -> V_25 ) ;
if ( V_4 )
goto V_165;
V_4 = F_14 ( V_13 ) ;
if ( V_4 )
goto V_166;
F_54 ( V_2 ) ;
V_2 -> V_167 |= V_168 | V_169 ;
V_2 -> V_167 |= V_170 ;
F_57 ( V_2 , true ) ;
if ( V_2 -> V_6 -> V_171 < V_172 )
V_173 [ V_2 -> V_6 -> V_171 ] = V_13 ;
goto V_19;
V_166:
F_42 ( V_13 -> V_25 ) ;
V_165:
F_79 ( V_13 -> V_25 ) ;
V_164:
F_80 ( V_6 , V_13 ) ;
V_2 -> V_23 = NULL ;
V_19:
return V_4 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
F_11 ( V_13 ) ;
F_42 ( V_13 -> V_25 ) ;
}
static
void F_82 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_23 ;
struct V_85 * V_112 = & V_13 -> V_112 ;
if ( ! V_112 )
return;
F_35 ( V_2 , V_112 -> V_106 ,
V_112 -> V_92 ,
V_112 -> V_108 ) ;
}
