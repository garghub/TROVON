static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 , int V_7 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_10 * V_11 = & V_9 -> V_11 ;
V_11 -> V_12 |= V_6 ;
switch ( V_6 ) {
case V_13 : {
int V_14 = V_4 -> V_15 . V_16 ? : 1 ;
int V_17 = V_14 * V_4 -> V_15 . V_18 ;
F_3 ( V_2 , L_1 , V_7 ) ;
if ( V_7 * V_19 < 3 * V_17 )
F_4 ( V_2 ,
L_2 ,
V_7 * V_19 , 3 * V_17 ) ;
V_11 -> V_20 = V_7 ;
break;
}
case V_21 :
F_3 ( V_2 , L_3 ,
V_7 ? L_4 : L_5 ) ;
V_11 -> V_22 = V_7 ;
break;
case V_23 :
F_3 ( V_2 , L_6 , V_7 ) ;
V_11 -> V_24 = V_7 ;
break;
case V_25 :
F_3 ( V_2 , L_7 , V_7 ) ;
V_11 -> V_26 = V_7 ;
break;
case V_27 :
F_3 ( V_2 , L_8 , V_7 ) ;
V_11 -> V_28 = V_7 ;
break;
case V_29 :
F_3 ( V_2 , L_9 , V_7 ? L_4 : L_5 ) ;
V_11 -> V_30 = V_7 ;
break;
case V_31 :
F_3 ( V_2 , L_10 , V_7 ) ;
V_11 -> V_32 = V_7 ;
break;
case V_33 :
F_3 ( V_2 , L_11 , V_7 ) ;
V_11 -> V_34 = V_7 ;
break;
case V_35 :
F_3 ( V_2 , L_12 , V_7 ) ;
V_11 -> V_36 = V_7 ;
break;
case V_37 :
F_3 ( V_2 , L_13 , V_7 ) ;
V_11 -> V_38 = V_7 ;
break;
}
}
static T_1 F_5 ( struct V_3 * V_4 , char * V_39 ,
T_2 V_40 , T_3 * V_41 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
enum V_5 V_6 ;
int V_7 , V_42 ;
if ( ! strncmp ( L_14 , V_39 , 11 ) ) {
if ( sscanf ( V_39 + 11 , L_15 , & V_7 ) != 1 )
return - V_43 ;
V_6 = V_13 ;
} else if ( ! strncmp ( L_16 , V_39 , 15 ) ) {
if ( sscanf ( V_39 + 15 , L_15 , & V_7 ) != 1 )
return - V_43 ;
V_6 = V_21 ;
} else if ( ! strncmp ( L_17 , V_39 , 18 ) ) {
if ( sscanf ( V_39 + 18 , L_15 , & V_7 ) != 1 )
return - V_43 ;
V_6 = V_23 ;
} else if ( ! strncmp ( L_18 , V_39 , 16 ) ) {
if ( sscanf ( V_39 + 16 , L_15 , & V_7 ) != 1 )
return - V_43 ;
V_6 = V_25 ;
} else if ( ! strncmp ( L_19 , V_39 , 16 ) ) {
if ( sscanf ( V_39 + 16 , L_15 , & V_7 ) != 1 )
return - V_43 ;
V_6 = V_27 ;
} else if ( ! strncmp ( L_20 , V_39 , 5 ) ) {
if ( sscanf ( V_39 + 5 , L_15 , & V_7 ) != 1 )
return - V_43 ;
V_6 = V_29 ;
} else if ( ! strncmp ( L_21 , V_39 , 20 ) ) {
if ( sscanf ( V_39 + 20 , L_15 , & V_7 ) != 1 )
return - V_43 ;
if ( V_7 > V_44 || V_7 <
V_45 )
return - V_43 ;
V_6 = V_31 ;
} else if ( ! strncmp ( L_22 , V_39 , 14 ) ) {
if ( sscanf ( V_39 + 14 , L_15 , & V_7 ) != 1 )
return - V_43 ;
V_6 = V_33 ;
} else if ( ! strncmp ( L_23 , V_39 , 18 ) ) {
if ( sscanf ( V_39 + 18 , L_15 , & V_7 ) != 1 )
return - V_43 ;
V_6 = V_35 ;
} else if ( ! strncmp ( L_24 , V_39 , 12 ) ) {
if ( sscanf ( V_39 + 12 , L_15 , & V_7 ) != 1 )
return - V_43 ;
V_6 = V_37 ;
} else {
return - V_43 ;
}
F_6 ( & V_2 -> V_46 ) ;
F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
V_42 = F_7 ( V_2 ) ;
F_8 ( & V_2 -> V_46 ) ;
return V_42 ? : V_40 ;
}
static T_1 F_9 ( struct V_47 * V_47 ,
char T_4 * V_48 ,
T_2 V_40 , T_3 * V_41 )
{
struct V_3 * V_4 = V_47 -> V_49 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
char V_39 [ 512 ] ;
int V_50 = sizeof( V_39 ) ;
int V_51 ;
V_51 = F_10 ( V_2 , V_4 , V_39 , V_50 ) ;
return F_11 ( V_48 , V_40 , V_41 , V_39 , V_51 ) ;
}
static T_1 F_12 ( struct V_47 * V_47 ,
char T_4 * V_48 ,
T_2 V_40 , T_3 * V_41 )
{
struct V_3 * V_4 = V_47 -> V_49 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_5 V_52 ;
struct V_53 * V_54 ;
char V_39 [ 512 ] ;
int V_50 = sizeof( V_39 ) ;
int V_51 = 0 ;
int V_55 ;
F_6 ( & V_2 -> V_46 ) ;
V_52 = V_9 -> V_52 ;
switch ( F_13 ( V_4 ) ) {
case V_56 :
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_25 ) ;
break;
case V_57 :
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_26 ) ;
break;
case V_58 :
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_27 ) ;
break;
case V_59 :
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_28 ) ;
break;
case V_60 :
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_29 ) ;
break;
case V_61 :
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_30 ) ;
break;
default:
break;
}
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_31 ,
V_9 -> V_62 , V_9 -> V_63 ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_32 ,
V_4 -> V_15 . V_64 ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_33 ) ;
for ( V_55 = 0 ; V_55 < F_15 ( V_9 -> V_65 ) ; V_55 ++ )
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 ,
L_34 ,
V_55 , V_9 -> V_65 [ V_55 ] . V_66 ,
V_9 -> V_65 [ V_55 ] . V_67 ,
V_9 -> V_65 [ V_55 ] . V_68 ,
V_9 -> V_65 [ V_55 ] . V_69 ,
V_9 -> V_65 [ V_55 ] . V_70 ) ;
if ( V_4 -> type == V_57 &&
V_52 != V_71 ) {
struct V_72 * V_73 ;
V_73 = F_16 ( V_2 -> V_74 [ V_52 ] ,
F_17 ( & V_2 -> V_46 ) ) ;
if ( ! F_18 ( V_73 ) ) {
struct V_75 * V_76 = F_19 ( V_73 ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 ,
L_35 ,
V_52 ,
V_76 -> V_77 ) ;
}
}
F_20 () ;
V_54 = F_21 ( V_4 -> V_54 ) ;
if ( V_54 )
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 ,
L_36 ,
V_54 -> V_78 ,
V_54 -> V_79 ) ;
F_22 () ;
F_8 ( & V_2 -> V_46 ) ;
return F_11 ( V_48 , V_40 , V_41 , V_39 , V_51 ) ;
}
static void F_23 ( struct V_3 * V_4 ,
enum V_80 V_6 , int V_81 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_82 * V_83 = & V_9 -> V_83 ;
V_83 -> V_12 |= V_6 ;
switch ( V_6 ) {
case V_84 :
V_83 -> V_85 = V_81 ;
break;
case V_86 :
V_83 -> V_87 = V_81 ;
break;
case V_88 :
V_83 -> V_89 = V_81 ;
break;
case V_90 :
V_83 -> V_91 = V_81 ;
break;
case V_92 :
V_83 -> V_93 = V_81 ;
break;
case V_94 :
V_83 -> V_95 = V_81 ;
break;
case V_96 :
V_83 -> V_97 = V_81 ;
break;
case V_98 :
V_83 -> V_99 = V_81 ;
break;
case V_100 :
V_83 -> V_101 = V_81 ;
break;
case V_102 :
V_83 -> V_103 = V_81 ;
break;
case V_104 :
V_83 -> V_105 = V_81 ;
break;
}
}
static T_1 F_24 ( struct V_3 * V_4 , char * V_39 ,
T_2 V_40 , T_3 * V_41 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
enum V_80 V_6 ;
int V_81 , V_42 = 0 ;
if ( ! strncmp ( L_37 , V_39 , 16 ) ) {
if ( sscanf ( V_39 + 16 , L_15 , & V_81 ) != 1 )
return - V_43 ;
if ( V_81 < V_106 ||
V_81 > V_107 )
return - V_43 ;
V_6 = V_84 ;
} else if ( ! strncmp ( L_38 , V_39 , 24 ) ) {
if ( sscanf ( V_39 + 24 , L_15 , & V_81 ) != 1 )
return - V_43 ;
if ( V_81 < V_108 ||
V_81 > V_109 )
return - V_43 ;
V_6 = V_86 ;
} else if ( ! strncmp ( L_39 , V_39 , 17 ) ) {
if ( sscanf ( V_39 + 17 , L_15 , & V_81 ) != 1 )
return - V_43 ;
if ( V_81 < V_110 ||
V_81 > V_111 )
return - V_43 ;
V_6 = V_88 ;
} else if ( ! strncmp ( L_40 , V_39 , 18 ) ) {
if ( sscanf ( V_39 + 18 , L_15 , & V_81 ) != 1 )
return - V_43 ;
if ( V_81 < V_112 ||
V_81 > V_113 )
return - V_43 ;
V_6 = V_90 ;
} else if ( ! strncmp ( L_41 , V_39 , 20 ) ) {
if ( sscanf ( V_39 + 20 , L_15 , & V_81 ) != 1 )
return - V_43 ;
if ( V_81 < V_114 ||
V_81 > V_115 )
return - V_43 ;
V_6 = V_92 ;
} else if ( ! strncmp ( L_42 , V_39 , 20 ) ) {
if ( sscanf ( V_39 + 20 , L_15 , & V_81 ) != 1 )
return - V_43 ;
if ( V_81 < V_116 ||
V_81 > V_117 )
return - V_43 ;
V_6 = V_94 ;
} else if ( ! strncmp ( L_43 , V_39 , 24 ) ) {
if ( sscanf ( V_39 + 24 , L_15 , & V_81 ) != 1 )
return - V_43 ;
if ( V_81 < 0 || V_81 > 1 )
return - V_43 ;
V_6 = V_96 ;
} else if ( ! strncmp ( L_44 , V_39 , 14 ) ) {
if ( sscanf ( V_39 + 14 , L_15 , & V_81 ) != 1 )
return - V_43 ;
if ( V_81 < 0 || V_81 > 1 )
return - V_43 ;
V_6 = V_98 ;
} else if ( ! strncmp ( L_45 , V_39 , 16 ) ) {
if ( sscanf ( V_39 + 16 , L_15 , & V_81 ) != 1 )
return - V_43 ;
if ( V_81 < V_118 ||
V_81 > V_119 )
return - V_43 ;
V_6 = V_100 ;
} else if ( ! strncmp ( L_46 , V_39 , 16 ) ) {
if ( sscanf ( V_39 + 16 , L_15 , & V_81 ) != 1 )
return - V_43 ;
if ( V_81 < V_120 ||
V_81 > V_121 )
return - V_43 ;
V_6 = V_104 ;
} else if ( ! strncmp ( L_47 , V_39 , 23 ) ) {
if ( sscanf ( V_39 + 23 , L_15 , & V_81 ) != 1 )
return - V_43 ;
if ( V_81 < 0 || V_81 > 1 )
return - V_43 ;
V_6 = V_102 ;
} else {
return - V_43 ;
}
F_6 ( & V_2 -> V_46 ) ;
F_23 ( V_4 , V_6 , V_81 ) ;
if ( V_6 == V_96 && ! V_81 )
V_42 = F_25 ( V_2 , V_4 , 0 ) ;
else
V_42 = F_26 ( V_2 , V_4 , 0 ) ;
F_8 ( & V_2 -> V_46 ) ;
return V_42 ? : V_40 ;
}
static T_1 F_27 ( struct V_47 * V_47 ,
char T_4 * V_48 ,
T_2 V_40 , T_3 * V_41 )
{
struct V_3 * V_4 = V_47 -> V_49 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_39 [ 256 ] ;
int V_51 = 0 ;
const T_2 V_50 = sizeof( V_39 ) ;
struct V_122 V_123 = {
V_124 ,
. V_97 =
F_28 ( V_125 ) ,
. V_103 =
F_28 ( V_126 ) ,
} ;
F_29 ( V_4 , & V_123 ) ;
if ( V_9 -> V_127 . V_128 )
V_123 . V_97 = F_28 ( 1 ) ;
else
V_123 . V_97 = 0 ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_48 ,
F_30 ( V_123 . V_85 ) ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_49 ,
F_30 ( V_123 . V_87 ) ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_50 ,
F_30 ( V_123 . V_89 ) ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_51 ,
F_30 ( V_123 . V_91 ) ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_52 ,
F_30 ( V_123 . V_93 ) ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_53 ,
F_30 ( V_123 . V_95 ) ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_54 ,
F_30 ( V_123 . V_97 ) ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_55 ,
F_30 ( V_123 . V_99 ) ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_56 ,
F_30 ( V_123 . V_101 ) ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_57 ,
F_30 ( V_123 . V_105 ) ) ;
V_51 += F_14 ( V_39 + V_51 , V_50 - V_51 , L_58 ,
F_30 ( V_123 . V_103 ) ) ;
return F_11 ( V_48 , V_40 , V_41 , V_39 , V_51 ) ;
}
static T_1 F_31 ( struct V_3 * V_4 , char * V_39 ,
T_2 V_40 , T_3 * V_41 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_5 V_81 ;
int V_42 ;
V_42 = F_32 ( V_39 , 0 , & V_81 ) ;
if ( V_42 )
return V_42 ;
if ( V_81 > 1 )
return - V_43 ;
F_6 ( & V_2 -> V_46 ) ;
F_33 ( V_2 , V_4 , V_81 ) ;
F_8 ( & V_2 -> V_46 ) ;
return V_40 ;
}
static T_1 F_34 ( struct V_47 * V_47 ,
char T_4 * V_48 ,
T_2 V_40 , T_3 * V_41 )
{
struct V_3 * V_4 = V_47 -> V_49 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_39 [ 3 ] ;
V_39 [ 0 ] = V_9 -> V_129 ? '1' : '0' ;
V_39 [ 1 ] = '\n' ;
V_39 [ 2 ] = '\0' ;
return F_11 ( V_48 , V_40 , V_41 , V_39 , sizeof( V_39 ) ) ;
}
static T_1 F_35 ( struct V_47 * V_47 ,
char T_4 * V_48 ,
T_2 V_40 , T_3 * V_41 )
{
struct V_3 * V_4 = V_47 -> V_49 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_39 [ 20 ] ;
int V_130 ;
V_130 = sprintf ( V_39 , L_59 , V_9 -> V_131 ) ;
return F_11 ( V_48 , V_40 , V_41 , V_39 , V_130 ) ;
}
static T_1 F_36 ( struct V_3 * V_4 ,
char * V_39 , T_2 V_40 ,
T_3 * V_41 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
bool V_42 ;
F_6 ( & V_2 -> V_46 ) ;
V_42 = F_37 ( V_39 , V_9 -> V_131 ) ;
F_8 ( & V_2 -> V_46 ) ;
return V_42 ? V_40 : - V_43 ;
}
static T_1 F_38 ( struct V_3 * V_4 , char * V_39 ,
T_2 V_40 , T_3 * V_41 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_53 * V_54 ;
struct V_132 * V_133 ;
T_6 V_81 ;
int V_42 ;
V_42 = F_39 ( V_39 , 0 , & V_81 ) ;
if ( V_42 )
return V_42 ;
F_6 ( & V_2 -> V_46 ) ;
F_20 () ;
V_54 = F_21 ( V_4 -> V_54 ) ;
if ( ! V_54 ) {
F_22 () ;
F_8 ( & V_2 -> V_46 ) ;
return - V_43 ;
}
V_133 = & V_2 -> V_134 [ * ( T_6 * ) V_54 -> V_135 ] ;
F_22 () ;
V_2 -> V_136 = V_81 ;
V_42 = F_40 ( V_2 , V_133 , & V_54 -> V_137 ,
V_54 -> V_78 ,
V_54 -> V_79 ) ;
F_8 ( & V_2 -> V_46 ) ;
return V_42 ? : V_40 ;
}
static T_1 F_41 ( struct V_47 * V_47 ,
char T_4 * V_48 ,
T_2 V_40 , T_3 * V_41 )
{
struct V_3 * V_4 = V_47 -> V_49 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_39 [ 8 ] ;
snprintf ( V_39 , sizeof( V_39 ) , L_60 , V_9 -> V_2 -> V_136 ) ;
return F_11 ( V_48 , V_40 , V_41 , V_39 , sizeof( V_39 ) ) ;
}
void F_42 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_138 * V_139 = V_4 -> V_140 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_39 [ 100 ] ;
if ( ! V_139 || V_9 -> V_139 )
return;
V_9 -> V_139 = F_43 ( L_61 , V_139 ) ;
if ( ! V_9 -> V_139 ) {
F_44 ( V_2 , L_62 ,
V_139 -> V_141 . V_142 ) ;
return;
}
if ( V_143 . V_144 != V_145 &&
( ( V_4 -> type == V_57 && ! V_4 -> V_146 ) ||
( V_4 -> type == V_57 && V_4 -> V_146 &&
V_2 -> V_147 -> V_148 . V_149 & V_150 ) ) )
F_45 ( V_151 , V_9 -> V_139 , V_152 |
V_153 ) ;
F_45 ( V_154 , V_9 -> V_139 , V_153 ) ;
F_45 ( V_129 , V_9 -> V_139 ,
V_153 | V_152 ) ;
F_45 ( V_36 , V_9 -> V_139 ,
V_153 | V_152 ) ;
F_45 ( V_155 , V_9 -> V_139 ,
V_153 | V_152 ) ;
if ( V_4 -> type == V_57 && ! V_4 -> V_146 &&
V_9 == V_2 -> V_156 )
F_45 ( V_157 , V_9 -> V_139 ,
V_153 | V_152 ) ;
snprintf ( V_39 , 100 , L_63 ,
V_139 -> V_158 -> V_158 -> V_141 . V_142 ,
V_139 -> V_158 -> V_141 . V_142 ,
V_139 -> V_141 . V_142 ,
V_9 -> V_139 -> V_141 . V_142 ) ;
V_9 -> V_159 = F_46 ( V_139 -> V_141 . V_142 ,
V_2 -> V_140 , V_39 ) ;
if ( ! V_9 -> V_159 )
F_44 ( V_2 , L_64 ,
V_139 -> V_141 . V_142 ) ;
return;
V_160:
F_44 ( V_2 , L_65 ) ;
}
void F_47 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
F_48 ( V_9 -> V_159 ) ;
V_9 -> V_159 = NULL ;
F_49 ( V_9 -> V_139 ) ;
V_9 -> V_139 = NULL ;
}
