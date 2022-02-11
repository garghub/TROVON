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
}
}
static T_1 F_5 ( struct V_3 * V_4 , char * V_37 ,
T_2 V_38 , T_3 * V_39 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
enum V_5 V_6 ;
int V_7 , V_40 ;
if ( ! strncmp ( L_13 , V_37 , 11 ) ) {
if ( sscanf ( V_37 + 11 , L_14 , & V_7 ) != 1 )
return - V_41 ;
V_6 = V_13 ;
} else if ( ! strncmp ( L_15 , V_37 , 15 ) ) {
if ( sscanf ( V_37 + 15 , L_14 , & V_7 ) != 1 )
return - V_41 ;
V_6 = V_21 ;
} else if ( ! strncmp ( L_16 , V_37 , 18 ) ) {
if ( sscanf ( V_37 + 18 , L_14 , & V_7 ) != 1 )
return - V_41 ;
V_6 = V_23 ;
} else if ( ! strncmp ( L_17 , V_37 , 16 ) ) {
if ( sscanf ( V_37 + 16 , L_14 , & V_7 ) != 1 )
return - V_41 ;
V_6 = V_25 ;
} else if ( ! strncmp ( L_18 , V_37 , 16 ) ) {
if ( sscanf ( V_37 + 16 , L_14 , & V_7 ) != 1 )
return - V_41 ;
V_6 = V_27 ;
} else if ( ! strncmp ( L_19 , V_37 , 5 ) ) {
if ( sscanf ( V_37 + 5 , L_14 , & V_7 ) != 1 )
return - V_41 ;
V_6 = V_29 ;
} else if ( ! strncmp ( L_20 , V_37 , 20 ) ) {
if ( sscanf ( V_37 + 20 , L_14 , & V_7 ) != 1 )
return - V_41 ;
if ( V_7 > V_42 || V_7 <
V_43 )
return - V_41 ;
V_6 = V_31 ;
} else if ( ! strncmp ( L_21 , V_37 , 14 ) ) {
if ( sscanf ( V_37 + 14 , L_14 , & V_7 ) != 1 )
return - V_41 ;
V_6 = V_33 ;
} else if ( ! strncmp ( L_22 , V_37 , 18 ) ) {
if ( sscanf ( V_37 + 18 , L_14 , & V_7 ) != 1 )
return - V_41 ;
V_6 = V_35 ;
} else {
return - V_41 ;
}
F_6 ( & V_2 -> V_44 ) ;
F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
V_40 = F_7 ( V_2 ) ;
F_8 ( & V_2 -> V_44 ) ;
return V_40 ? : V_38 ;
}
static T_1 F_9 ( struct V_45 * V_45 ,
char T_4 * V_46 ,
T_2 V_38 , T_3 * V_39 )
{
struct V_3 * V_4 = V_45 -> V_47 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
char V_37 [ 512 ] ;
int V_48 = sizeof( V_37 ) ;
int V_49 ;
V_49 = F_10 ( V_2 , V_4 , V_37 , V_48 ) ;
return F_11 ( V_46 , V_38 , V_39 , V_37 , V_49 ) ;
}
static T_1 F_12 ( struct V_45 * V_45 ,
char T_4 * V_46 ,
T_2 V_38 , T_3 * V_39 )
{
struct V_3 * V_4 = V_45 -> V_47 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_5 V_50 ;
struct V_51 * V_52 ;
char V_37 [ 512 ] ;
int V_48 = sizeof( V_37 ) ;
int V_49 = 0 ;
int V_53 ;
F_6 ( & V_2 -> V_44 ) ;
V_50 = V_9 -> V_50 ;
switch ( F_13 ( V_4 ) ) {
case V_54 :
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_23 ) ;
break;
case V_55 :
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_24 ) ;
break;
case V_56 :
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_25 ) ;
break;
case V_57 :
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_26 ) ;
break;
case V_58 :
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_27 ) ;
break;
case V_59 :
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_28 ) ;
break;
default:
break;
}
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_29 ,
V_9 -> V_60 , V_9 -> V_61 ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_30 ,
V_4 -> V_15 . V_62 ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_31 ) ;
for ( V_53 = 0 ; V_53 < F_15 ( V_9 -> V_63 ) ; V_53 ++ )
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 ,
L_32 ,
V_53 , V_9 -> V_63 [ V_53 ] . V_64 ,
V_9 -> V_63 [ V_53 ] . V_65 ,
V_9 -> V_63 [ V_53 ] . V_66 ,
V_9 -> V_63 [ V_53 ] . V_67 ,
V_9 -> V_63 [ V_53 ] . V_68 ) ;
if ( V_4 -> type == V_55 &&
V_50 != V_69 ) {
struct V_70 * V_71 ;
V_71 = F_16 ( V_2 -> V_72 [ V_50 ] ,
F_17 ( & V_2 -> V_44 ) ) ;
if ( ! F_18 ( V_71 ) ) {
struct V_73 * V_74 = ( void * ) V_71 -> V_75 ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 ,
L_33 ,
V_50 ,
V_74 -> V_76 ) ;
}
}
F_19 () ;
V_52 = F_20 ( V_4 -> V_52 ) ;
if ( V_52 )
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 ,
L_34 ,
V_52 -> V_77 ,
V_52 -> V_78 ) ;
F_21 () ;
F_8 ( & V_2 -> V_44 ) ;
return F_11 ( V_46 , V_38 , V_39 , V_37 , V_49 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
enum V_79 V_6 , int V_80 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_81 * V_82 = & V_9 -> V_82 ;
V_82 -> V_12 |= V_6 ;
switch ( V_6 ) {
case V_83 :
V_82 -> V_84 = V_80 ;
break;
case V_85 :
V_82 -> V_86 = V_80 ;
break;
case V_87 :
V_82 -> V_88 = V_80 ;
break;
case V_89 :
V_82 -> V_90 = V_80 ;
break;
case V_91 :
V_82 -> V_92 = V_80 ;
break;
case V_93 :
V_82 -> V_94 = V_80 ;
break;
case V_95 :
V_82 -> V_96 = V_80 ;
break;
case V_97 :
V_82 -> V_98 = V_80 ;
break;
case V_99 :
V_82 -> V_100 = V_80 ;
break;
case V_101 :
V_82 -> V_102 = V_80 ;
break;
case V_103 :
V_82 -> V_104 = V_80 ;
break;
}
}
static T_1 F_23 ( struct V_3 * V_4 , char * V_37 ,
T_2 V_38 , T_3 * V_39 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
enum V_79 V_6 ;
int V_80 , V_40 = 0 ;
if ( ! strncmp ( L_35 , V_37 , 16 ) ) {
if ( sscanf ( V_37 + 16 , L_14 , & V_80 ) != 1 )
return - V_41 ;
if ( V_80 < V_105 ||
V_80 > V_106 )
return - V_41 ;
V_6 = V_83 ;
} else if ( ! strncmp ( L_36 , V_37 , 24 ) ) {
if ( sscanf ( V_37 + 24 , L_14 , & V_80 ) != 1 )
return - V_41 ;
if ( V_80 < V_107 ||
V_80 > V_108 )
return - V_41 ;
V_6 = V_85 ;
} else if ( ! strncmp ( L_37 , V_37 , 17 ) ) {
if ( sscanf ( V_37 + 17 , L_14 , & V_80 ) != 1 )
return - V_41 ;
if ( V_80 < V_109 ||
V_80 > V_110 )
return - V_41 ;
V_6 = V_87 ;
} else if ( ! strncmp ( L_38 , V_37 , 18 ) ) {
if ( sscanf ( V_37 + 18 , L_14 , & V_80 ) != 1 )
return - V_41 ;
if ( V_80 < V_111 ||
V_80 > V_112 )
return - V_41 ;
V_6 = V_89 ;
} else if ( ! strncmp ( L_39 , V_37 , 20 ) ) {
if ( sscanf ( V_37 + 20 , L_14 , & V_80 ) != 1 )
return - V_41 ;
if ( V_80 < V_113 ||
V_80 > V_114 )
return - V_41 ;
V_6 = V_91 ;
} else if ( ! strncmp ( L_40 , V_37 , 20 ) ) {
if ( sscanf ( V_37 + 20 , L_14 , & V_80 ) != 1 )
return - V_41 ;
if ( V_80 < V_115 ||
V_80 > V_116 )
return - V_41 ;
V_6 = V_93 ;
} else if ( ! strncmp ( L_41 , V_37 , 24 ) ) {
if ( sscanf ( V_37 + 24 , L_14 , & V_80 ) != 1 )
return - V_41 ;
if ( V_80 < 0 || V_80 > 1 )
return - V_41 ;
V_6 = V_95 ;
} else if ( ! strncmp ( L_42 , V_37 , 14 ) ) {
if ( sscanf ( V_37 + 14 , L_14 , & V_80 ) != 1 )
return - V_41 ;
if ( V_80 < 0 || V_80 > 1 )
return - V_41 ;
V_6 = V_97 ;
} else if ( ! strncmp ( L_43 , V_37 , 16 ) ) {
if ( sscanf ( V_37 + 16 , L_14 , & V_80 ) != 1 )
return - V_41 ;
if ( V_80 < V_117 ||
V_80 > V_118 )
return - V_41 ;
V_6 = V_99 ;
} else if ( ! strncmp ( L_44 , V_37 , 16 ) ) {
if ( sscanf ( V_37 + 16 , L_14 , & V_80 ) != 1 )
return - V_41 ;
if ( V_80 < V_119 ||
V_80 > V_120 )
return - V_41 ;
V_6 = V_103 ;
} else if ( ! strncmp ( L_45 , V_37 , 23 ) ) {
if ( sscanf ( V_37 + 23 , L_14 , & V_80 ) != 1 )
return - V_41 ;
if ( V_80 < 0 || V_80 > 1 )
return - V_41 ;
V_6 = V_101 ;
} else {
return - V_41 ;
}
F_6 ( & V_2 -> V_44 ) ;
F_22 ( V_4 , V_6 , V_80 ) ;
if ( V_6 == V_95 && ! V_80 )
V_40 = F_24 ( V_2 , V_4 , 0 ) ;
else
V_40 = F_25 ( V_2 , V_4 , 0 ) ;
F_8 ( & V_2 -> V_44 ) ;
return V_40 ? : V_38 ;
}
static T_1 F_26 ( struct V_45 * V_45 ,
char T_4 * V_46 ,
T_2 V_38 , T_3 * V_39 )
{
struct V_3 * V_4 = V_45 -> V_47 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_37 [ 256 ] ;
int V_49 = 0 ;
const T_2 V_48 = sizeof( V_37 ) ;
struct V_121 V_122 = {
V_123 ,
. V_96 =
F_27 ( V_124 ) ,
. V_102 =
F_27 ( V_125 ) ,
} ;
F_28 ( V_4 , & V_122 ) ;
if ( V_9 -> V_126 . V_127 )
V_122 . V_96 = F_27 ( 1 ) ;
else
V_122 . V_96 = 0 ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_46 ,
F_29 ( V_122 . V_84 ) ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_47 ,
F_29 ( V_122 . V_86 ) ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_48 ,
F_29 ( V_122 . V_88 ) ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_49 ,
F_29 ( V_122 . V_90 ) ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_50 ,
F_29 ( V_122 . V_92 ) ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_51 ,
F_29 ( V_122 . V_94 ) ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_52 ,
F_29 ( V_122 . V_96 ) ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_53 ,
F_29 ( V_122 . V_98 ) ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_54 ,
F_29 ( V_122 . V_100 ) ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_55 ,
F_29 ( V_122 . V_104 ) ) ;
V_49 += F_14 ( V_37 + V_49 , V_48 - V_49 , L_56 ,
F_29 ( V_122 . V_102 ) ) ;
return F_11 ( V_46 , V_38 , V_39 , V_37 , V_49 ) ;
}
static T_1 F_30 ( struct V_3 * V_4 , char * V_37 ,
T_2 V_38 , T_3 * V_39 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_5 V_80 ;
int V_40 ;
V_40 = F_31 ( V_37 , 0 , & V_80 ) ;
if ( V_40 )
return V_40 ;
if ( V_80 > 1 )
return - V_41 ;
F_6 ( & V_2 -> V_44 ) ;
F_32 ( V_2 , V_4 , V_80 ) ;
F_8 ( & V_2 -> V_44 ) ;
return V_38 ;
}
static T_1 F_33 ( struct V_45 * V_45 ,
char T_4 * V_46 ,
T_2 V_38 , T_3 * V_39 )
{
struct V_3 * V_4 = V_45 -> V_47 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_37 [ 3 ] ;
V_37 [ 0 ] = V_9 -> V_128 ? '1' : '0' ;
V_37 [ 1 ] = '\n' ;
V_37 [ 2 ] = '\0' ;
return F_11 ( V_46 , V_38 , V_39 , V_37 , sizeof( V_37 ) ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_129 * V_130 = V_4 -> V_131 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_37 [ 100 ] ;
if ( ! V_130 || V_9 -> V_130 )
return;
V_9 -> V_130 = F_35 ( L_57 , V_130 ) ;
V_9 -> V_2 = V_2 ;
if ( ! V_9 -> V_130 ) {
F_36 ( V_2 , L_58 ,
V_130 -> V_132 . V_133 ) ;
return;
}
if ( V_134 . V_135 != V_136 &&
( ( V_4 -> type == V_55 && ! V_4 -> V_137 ) ||
( V_4 -> type == V_55 && V_4 -> V_137 &&
V_2 -> V_138 -> V_139 . V_140 & V_141 ) ) )
F_37 ( V_142 , V_9 -> V_130 , V_143 |
V_144 ) ;
F_37 ( V_145 , V_9 -> V_130 , V_144 ) ;
F_37 ( V_128 , V_9 -> V_130 ,
V_144 | V_143 ) ;
if ( V_4 -> type == V_55 && ! V_4 -> V_137 &&
V_9 == V_2 -> V_146 )
F_37 ( V_147 , V_9 -> V_130 ,
V_144 | V_143 ) ;
snprintf ( V_37 , 100 , L_59 ,
V_130 -> V_148 -> V_148 -> V_132 . V_133 ,
V_130 -> V_148 -> V_132 . V_133 ,
V_130 -> V_132 . V_133 ,
V_9 -> V_130 -> V_132 . V_133 ) ;
V_9 -> V_149 = F_38 ( V_130 -> V_132 . V_133 ,
V_2 -> V_131 , V_37 ) ;
if ( ! V_9 -> V_149 )
F_36 ( V_2 , L_60 ,
V_130 -> V_132 . V_133 ) ;
return;
V_150:
F_36 ( V_2 , L_61 ) ;
}
void F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
F_40 ( V_9 -> V_149 ) ;
V_9 -> V_149 = NULL ;
F_41 ( V_9 -> V_130 ) ;
V_9 -> V_130 = NULL ;
}
