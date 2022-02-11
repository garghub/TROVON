static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 , int V_7 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_10 * V_11 = & V_9 -> V_11 ;
V_11 -> V_12 |= V_6 ;
switch ( V_6 ) {
case V_13 : {
struct V_14 * V_15 = V_2 -> V_15 ;
int V_16 = V_15 -> V_17 . V_18 ? : 1 ;
int V_19 = V_16 * V_4 -> V_20 . V_21 ;
F_3 ( V_2 , L_1 , V_7 ) ;
if ( V_7 * V_22 < 3 * V_19 )
F_4 ( V_2 ,
L_2 ,
V_7 * V_22 , 3 * V_19 ) ;
V_11 -> V_23 = V_7 ;
break;
}
case V_24 :
F_3 ( V_2 , L_3 ,
V_7 ? L_4 : L_5 ) ;
V_11 -> V_25 = V_7 ;
break;
case V_26 :
F_3 ( V_2 , L_6 , V_7 ) ;
V_11 -> V_27 = V_7 ;
break;
case V_28 :
F_3 ( V_2 , L_7 , V_7 ) ;
V_11 -> V_29 = V_7 ;
break;
case V_30 :
F_3 ( V_2 , L_8 , V_7 ) ;
V_11 -> V_31 = V_7 ;
break;
case V_32 :
F_3 ( V_2 , L_9 , V_7 ? L_4 : L_5 ) ;
V_11 -> V_33 = V_7 ;
break;
case V_34 :
F_3 ( V_2 , L_10 , V_7 ) ;
V_11 -> V_35 = V_7 ;
break;
case V_36 :
F_3 ( V_2 , L_11 , V_7 ) ;
V_11 -> V_37 = V_7 ;
break;
case V_38 :
F_3 ( V_2 , L_12 , V_7 ) ;
V_11 -> V_39 = V_7 ;
break;
}
}
static T_1 F_5 ( struct V_3 * V_4 , char * V_40 ,
T_2 V_41 , T_3 * V_42 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
enum V_5 V_6 ;
int V_7 , V_43 ;
if ( ! strncmp ( L_13 , V_40 , 11 ) ) {
if ( sscanf ( V_40 + 11 , L_14 , & V_7 ) != 1 )
return - V_44 ;
V_6 = V_13 ;
} else if ( ! strncmp ( L_15 , V_40 , 15 ) ) {
if ( sscanf ( V_40 + 15 , L_14 , & V_7 ) != 1 )
return - V_44 ;
V_6 = V_24 ;
} else if ( ! strncmp ( L_16 , V_40 , 18 ) ) {
if ( sscanf ( V_40 + 18 , L_14 , & V_7 ) != 1 )
return - V_44 ;
V_6 = V_26 ;
} else if ( ! strncmp ( L_17 , V_40 , 16 ) ) {
if ( sscanf ( V_40 + 16 , L_14 , & V_7 ) != 1 )
return - V_44 ;
V_6 = V_28 ;
} else if ( ! strncmp ( L_18 , V_40 , 16 ) ) {
if ( sscanf ( V_40 + 16 , L_14 , & V_7 ) != 1 )
return - V_44 ;
V_6 = V_30 ;
} else if ( ! strncmp ( L_19 , V_40 , 5 ) ) {
if ( sscanf ( V_40 + 5 , L_14 , & V_7 ) != 1 )
return - V_44 ;
V_6 = V_32 ;
} else if ( ! strncmp ( L_20 , V_40 , 20 ) ) {
if ( sscanf ( V_40 + 20 , L_14 , & V_7 ) != 1 )
return - V_44 ;
if ( V_7 > V_45 || V_7 <
V_46 )
return - V_44 ;
V_6 = V_34 ;
} else if ( ! strncmp ( L_21 , V_40 , 14 ) ) {
if ( sscanf ( V_40 + 14 , L_14 , & V_7 ) != 1 )
return - V_44 ;
V_6 = V_36 ;
} else if ( ! strncmp ( L_22 , V_40 , 18 ) ) {
if ( sscanf ( V_40 + 18 , L_14 , & V_7 ) != 1 )
return - V_44 ;
V_6 = V_38 ;
} else {
return - V_44 ;
}
F_6 ( & V_2 -> V_47 ) ;
F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
V_43 = F_7 ( V_2 ) ;
F_8 ( & V_2 -> V_47 ) ;
return V_43 ? : V_41 ;
}
static T_1 F_9 ( struct V_48 * V_48 ,
char T_4 * V_49 ,
T_2 V_41 , T_3 * V_42 )
{
struct V_3 * V_4 = V_48 -> V_50 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
char V_40 [ 512 ] ;
int V_51 = sizeof( V_40 ) ;
int V_52 ;
V_52 = F_10 ( V_2 , V_4 , V_40 , V_51 ) ;
return F_11 ( V_49 , V_41 , V_42 , V_40 , V_52 ) ;
}
static T_1 F_12 ( struct V_48 * V_48 ,
char T_4 * V_49 ,
T_2 V_41 , T_3 * V_42 )
{
struct V_3 * V_4 = V_48 -> V_50 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_5 V_53 ;
struct V_54 * V_55 ;
char V_40 [ 512 ] ;
int V_51 = sizeof( V_40 ) ;
int V_52 = 0 ;
int V_56 ;
F_6 ( & V_2 -> V_47 ) ;
V_53 = V_9 -> V_53 ;
switch ( F_13 ( V_4 ) ) {
case V_57 :
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_23 ) ;
break;
case V_58 :
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_24 ) ;
break;
case V_59 :
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_25 ) ;
break;
case V_60 :
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_26 ) ;
break;
case V_61 :
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_27 ) ;
break;
case V_62 :
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_28 ) ;
break;
default:
break;
}
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_29 ,
V_9 -> V_63 , V_9 -> V_64 ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_30 ,
V_4 -> V_20 . V_65 ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_31 ) ;
for ( V_56 = 0 ; V_56 < F_15 ( V_9 -> V_66 ) ; V_56 ++ )
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 ,
L_32 ,
V_56 , V_9 -> V_66 [ V_56 ] . V_67 ,
V_9 -> V_66 [ V_56 ] . V_68 ,
V_9 -> V_66 [ V_56 ] . V_69 ,
V_9 -> V_66 [ V_56 ] . V_70 ,
V_9 -> V_66 [ V_56 ] . V_71 ) ;
if ( V_4 -> type == V_58 &&
V_53 != V_72 ) {
struct V_73 * V_74 ;
V_74 = F_16 ( V_2 -> V_75 [ V_53 ] ,
F_17 ( & V_2 -> V_47 ) ) ;
if ( ! F_18 ( V_74 ) ) {
struct V_76 * V_77 = ( void * ) V_74 -> V_78 ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 ,
L_33 ,
V_53 ,
V_77 -> V_79 ) ;
}
}
F_19 () ;
V_55 = F_20 ( V_4 -> V_55 ) ;
if ( V_55 )
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 ,
L_34 ,
V_55 -> V_80 ,
V_55 -> V_81 ) ;
F_21 () ;
F_8 ( & V_2 -> V_47 ) ;
return F_11 ( V_49 , V_41 , V_42 , V_40 , V_52 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
enum V_82 V_6 , int V_83 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_84 * V_85 = & V_9 -> V_85 ;
V_85 -> V_12 |= V_6 ;
switch ( V_6 ) {
case V_86 :
V_85 -> V_87 = V_83 ;
break;
case V_88 :
V_85 -> V_89 = V_83 ;
break;
case V_90 :
V_85 -> V_91 = V_83 ;
break;
case V_92 :
V_85 -> V_93 = V_83 ;
break;
case V_94 :
V_85 -> V_95 = V_83 ;
break;
case V_96 :
V_85 -> V_97 = V_83 ;
break;
case V_98 :
V_85 -> V_99 = V_83 ;
break;
case V_100 :
V_85 -> V_101 = V_83 ;
break;
case V_102 :
V_85 -> V_103 = V_83 ;
break;
case V_104 :
V_85 -> V_105 = V_83 ;
break;
case V_106 :
V_85 -> V_107 = V_83 ;
break;
}
}
static T_1 F_23 ( struct V_3 * V_4 , char * V_40 ,
T_2 V_41 , T_3 * V_42 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
enum V_82 V_6 ;
int V_83 , V_43 = 0 ;
if ( ! strncmp ( L_35 , V_40 , 16 ) ) {
if ( sscanf ( V_40 + 16 , L_14 , & V_83 ) != 1 )
return - V_44 ;
if ( V_83 < V_108 ||
V_83 > V_109 )
return - V_44 ;
V_6 = V_86 ;
} else if ( ! strncmp ( L_36 , V_40 , 24 ) ) {
if ( sscanf ( V_40 + 24 , L_14 , & V_83 ) != 1 )
return - V_44 ;
if ( V_83 < V_110 ||
V_83 > V_111 )
return - V_44 ;
V_6 = V_88 ;
} else if ( ! strncmp ( L_37 , V_40 , 17 ) ) {
if ( sscanf ( V_40 + 17 , L_14 , & V_83 ) != 1 )
return - V_44 ;
if ( V_83 < V_112 ||
V_83 > V_113 )
return - V_44 ;
V_6 = V_90 ;
} else if ( ! strncmp ( L_38 , V_40 , 18 ) ) {
if ( sscanf ( V_40 + 18 , L_14 , & V_83 ) != 1 )
return - V_44 ;
if ( V_83 < V_114 ||
V_83 > V_115 )
return - V_44 ;
V_6 = V_92 ;
} else if ( ! strncmp ( L_39 , V_40 , 20 ) ) {
if ( sscanf ( V_40 + 20 , L_14 , & V_83 ) != 1 )
return - V_44 ;
if ( V_83 < V_116 ||
V_83 > V_117 )
return - V_44 ;
V_6 = V_94 ;
} else if ( ! strncmp ( L_40 , V_40 , 20 ) ) {
if ( sscanf ( V_40 + 20 , L_14 , & V_83 ) != 1 )
return - V_44 ;
if ( V_83 < V_118 ||
V_83 > V_119 )
return - V_44 ;
V_6 = V_96 ;
} else if ( ! strncmp ( L_41 , V_40 , 24 ) ) {
if ( sscanf ( V_40 + 24 , L_14 , & V_83 ) != 1 )
return - V_44 ;
if ( V_83 < 0 || V_83 > 1 )
return - V_44 ;
V_6 = V_98 ;
} else if ( ! strncmp ( L_42 , V_40 , 14 ) ) {
if ( sscanf ( V_40 + 14 , L_14 , & V_83 ) != 1 )
return - V_44 ;
if ( V_83 < 0 || V_83 > 1 )
return - V_44 ;
V_6 = V_100 ;
} else if ( ! strncmp ( L_43 , V_40 , 16 ) ) {
if ( sscanf ( V_40 + 16 , L_14 , & V_83 ) != 1 )
return - V_44 ;
if ( V_83 < V_120 ||
V_83 > V_121 )
return - V_44 ;
V_6 = V_102 ;
} else if ( ! strncmp ( L_44 , V_40 , 16 ) ) {
if ( sscanf ( V_40 + 16 , L_14 , & V_83 ) != 1 )
return - V_44 ;
if ( V_83 < V_122 ||
V_83 > V_123 )
return - V_44 ;
V_6 = V_106 ;
} else if ( ! strncmp ( L_45 , V_40 , 23 ) ) {
if ( sscanf ( V_40 + 23 , L_14 , & V_83 ) != 1 )
return - V_44 ;
if ( V_83 < 0 || V_83 > 1 )
return - V_44 ;
V_6 = V_104 ;
} else {
return - V_44 ;
}
F_6 ( & V_2 -> V_47 ) ;
F_22 ( V_4 , V_6 , V_83 ) ;
if ( V_6 == V_98 && ! V_83 )
V_43 = F_24 ( V_2 , V_4 , 0 ) ;
else
V_43 = F_25 ( V_2 , V_4 , 0 ) ;
F_8 ( & V_2 -> V_47 ) ;
return V_43 ? : V_41 ;
}
static T_1 F_26 ( struct V_48 * V_48 ,
char T_4 * V_49 ,
T_2 V_41 , T_3 * V_42 )
{
struct V_3 * V_4 = V_48 -> V_50 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_40 [ 256 ] ;
int V_52 = 0 ;
const T_2 V_51 = sizeof( V_40 ) ;
struct V_124 V_125 = {
V_126 ,
. V_99 =
F_27 ( V_127 ) ,
. V_105 =
F_27 ( V_128 ) ,
} ;
F_28 ( V_4 , & V_125 ) ;
if ( V_9 -> V_129 . V_130 )
V_125 . V_99 = F_27 ( 1 ) ;
else
V_125 . V_99 = 0 ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_46 ,
F_29 ( V_125 . V_87 ) ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_47 ,
F_29 ( V_125 . V_89 ) ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_48 ,
F_29 ( V_125 . V_91 ) ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_49 ,
F_29 ( V_125 . V_93 ) ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_50 ,
F_29 ( V_125 . V_95 ) ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_51 ,
F_29 ( V_125 . V_97 ) ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_52 ,
F_29 ( V_125 . V_99 ) ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_53 ,
F_29 ( V_125 . V_101 ) ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_54 ,
F_29 ( V_125 . V_103 ) ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_55 ,
F_29 ( V_125 . V_107 ) ) ;
V_52 += F_14 ( V_40 + V_52 , V_51 - V_52 , L_56 ,
F_29 ( V_125 . V_105 ) ) ;
return F_11 ( V_49 , V_41 , V_42 , V_40 , V_52 ) ;
}
static T_1 F_30 ( struct V_3 * V_4 , char * V_40 ,
T_2 V_41 , T_3 * V_42 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_5 V_83 ;
int V_43 ;
V_43 = F_31 ( V_40 , 0 , & V_83 ) ;
if ( V_43 )
return V_43 ;
if ( V_83 > 1 )
return - V_44 ;
F_6 ( & V_2 -> V_47 ) ;
F_32 ( V_2 , V_4 , V_83 ) ;
F_8 ( & V_2 -> V_47 ) ;
return V_41 ;
}
static T_1 F_33 ( struct V_48 * V_48 ,
char T_4 * V_49 ,
T_2 V_41 , T_3 * V_42 )
{
struct V_3 * V_4 = V_48 -> V_50 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_40 [ 3 ] ;
V_40 [ 0 ] = V_9 -> V_131 ? '1' : '0' ;
V_40 [ 1 ] = '\n' ;
V_40 [ 2 ] = '\0' ;
return F_11 ( V_49 , V_41 , V_42 , V_40 , sizeof( V_40 ) ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_132 * V_133 = V_4 -> V_134 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_40 [ 100 ] ;
if ( ! V_133 || V_9 -> V_133 )
return;
V_9 -> V_133 = F_35 ( L_57 , V_133 ) ;
V_9 -> V_2 = V_2 ;
if ( ! V_9 -> V_133 ) {
F_36 ( V_2 , L_58 ,
V_133 -> V_135 . V_136 ) ;
return;
}
if ( V_137 . V_138 != V_139 &&
( ( V_4 -> type == V_58 && ! V_4 -> V_140 ) ||
( V_4 -> type == V_58 && V_4 -> V_140 &&
V_2 -> V_141 -> V_142 . V_143 & V_144 ) ) )
F_37 ( V_145 , V_9 -> V_133 , V_146 |
V_147 ) ;
F_37 ( V_148 , V_9 -> V_133 , V_147 ) ;
F_37 ( V_131 , V_9 -> V_133 ,
V_147 | V_146 ) ;
if ( V_4 -> type == V_58 && ! V_4 -> V_140 &&
V_9 == V_2 -> V_149 )
F_37 ( V_150 , V_9 -> V_133 ,
V_147 | V_146 ) ;
snprintf ( V_40 , 100 , L_59 ,
V_133 -> V_151 -> V_151 -> V_135 . V_136 ,
V_133 -> V_151 -> V_135 . V_136 ,
V_133 -> V_135 . V_136 ,
V_9 -> V_133 -> V_135 . V_136 ) ;
V_9 -> V_152 = F_38 ( V_133 -> V_135 . V_136 ,
V_2 -> V_134 , V_40 ) ;
if ( ! V_9 -> V_152 )
F_36 ( V_2 , L_60 ,
V_133 -> V_135 . V_136 ) ;
return;
V_153:
F_36 ( V_2 , L_61 ) ;
}
void F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
F_40 ( V_9 -> V_152 ) ;
V_9 -> V_152 = NULL ;
F_41 ( V_9 -> V_133 ) ;
V_9 -> V_133 = NULL ;
}
