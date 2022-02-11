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
F_3 ( V_2 , L_9 , V_7 ) ;
V_11 -> V_33 = V_7 ;
break;
case V_34 :
F_3 ( V_2 , L_10 , V_7 ? L_4 : L_5 ) ;
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
case V_40 :
F_3 ( V_2 , L_13 , V_7 ) ;
V_11 -> V_41 = V_7 ;
break;
}
}
static T_1 F_5 ( struct V_3 * V_4 , char * V_42 ,
T_2 V_43 , T_3 * V_44 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
enum V_5 V_6 ;
int V_7 , V_45 ;
if ( ! strncmp ( L_14 , V_42 , 11 ) ) {
if ( sscanf ( V_42 + 11 , L_15 , & V_7 ) != 1 )
return - V_46 ;
V_6 = V_13 ;
} else if ( ! strncmp ( L_16 , V_42 , 15 ) ) {
if ( sscanf ( V_42 + 15 , L_15 , & V_7 ) != 1 )
return - V_46 ;
V_6 = V_24 ;
} else if ( ! strncmp ( L_17 , V_42 , 18 ) ) {
if ( sscanf ( V_42 + 18 , L_15 , & V_7 ) != 1 )
return - V_46 ;
V_6 = V_26 ;
} else if ( ! strncmp ( L_18 , V_42 , 16 ) ) {
if ( sscanf ( V_42 + 16 , L_15 , & V_7 ) != 1 )
return - V_46 ;
V_6 = V_28 ;
} else if ( ! strncmp ( L_19 , V_42 , 16 ) ) {
if ( sscanf ( V_42 + 16 , L_15 , & V_7 ) != 1 )
return - V_46 ;
V_6 = V_30 ;
} else if ( ! strncmp ( L_20 , V_42 , 18 ) &&
! ( V_2 -> V_47 -> V_48 . V_49 &
V_50 ) ) {
if ( sscanf ( V_42 + 18 , L_15 , & V_7 ) != 1 )
return - V_46 ;
V_6 = V_32 ;
} else if ( ! strncmp ( L_21 , V_42 , 5 ) ) {
if ( sscanf ( V_42 + 5 , L_15 , & V_7 ) != 1 )
return - V_46 ;
V_6 = V_34 ;
} else if ( ! strncmp ( L_22 , V_42 , 20 ) ) {
if ( sscanf ( V_42 + 20 , L_15 , & V_7 ) != 1 )
return - V_46 ;
if ( V_7 > V_51 || V_7 <
V_52 )
return - V_46 ;
V_6 = V_36 ;
} else if ( ! strncmp ( L_23 , V_42 , 14 ) ) {
if ( sscanf ( V_42 + 14 , L_15 , & V_7 ) != 1 )
return - V_46 ;
V_6 = V_38 ;
} else if ( ! strncmp ( L_24 , V_42 , 18 ) ) {
if ( sscanf ( V_42 + 18 , L_15 , & V_7 ) != 1 )
return - V_46 ;
V_6 = V_40 ;
} else {
return - V_46 ;
}
F_6 ( & V_2 -> V_53 ) ;
F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
V_45 = F_7 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_53 ) ;
return V_45 ? : V_43 ;
}
static T_1 F_9 ( struct V_54 * V_54 ,
char T_4 * V_55 ,
T_2 V_43 , T_3 * V_44 )
{
struct V_3 * V_4 = V_54 -> V_56 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
char V_42 [ 512 ] ;
int V_57 = sizeof( V_42 ) ;
int V_58 ;
V_58 = F_10 ( V_2 , V_4 , V_42 , V_57 ) ;
return F_11 ( V_55 , V_43 , V_44 , V_42 , V_58 ) ;
}
static T_1 F_12 ( struct V_54 * V_54 ,
char T_4 * V_55 ,
T_2 V_43 , T_3 * V_44 )
{
struct V_3 * V_4 = V_54 -> V_56 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_5 V_59 ;
struct V_60 * V_61 ;
char V_42 [ 512 ] ;
int V_57 = sizeof( V_42 ) ;
int V_58 = 0 ;
int V_62 ;
F_6 ( & V_2 -> V_53 ) ;
V_59 = V_9 -> V_59 ;
switch ( F_13 ( V_4 ) ) {
case V_63 :
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_25 ) ;
break;
case V_64 :
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_26 ) ;
break;
case V_65 :
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_27 ) ;
break;
case V_66 :
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_28 ) ;
break;
case V_67 :
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_29 ) ;
break;
case V_68 :
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_30 ) ;
break;
default:
break;
}
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_31 ,
V_9 -> V_69 , V_9 -> V_70 ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_32 ,
V_4 -> V_20 . V_71 ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_33 ) ;
for ( V_62 = 0 ; V_62 < F_15 ( V_9 -> V_72 ) ; V_62 ++ )
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 ,
L_34 ,
V_62 , V_9 -> V_72 [ V_62 ] . V_73 ,
V_9 -> V_72 [ V_62 ] . V_74 ,
V_9 -> V_72 [ V_62 ] . V_75 ,
V_9 -> V_72 [ V_62 ] . V_76 ,
V_9 -> V_72 [ V_62 ] . V_77 ) ;
if ( V_4 -> type == V_64 &&
V_59 != V_78 ) {
struct V_79 * V_80 ;
V_80 = F_16 ( V_2 -> V_81 [ V_59 ] ,
F_17 ( & V_2 -> V_53 ) ) ;
if ( ! F_18 ( V_80 ) ) {
struct V_82 * V_83 = ( void * ) V_80 -> V_84 ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 ,
L_35 ,
V_59 ,
V_83 -> V_85 ,
V_83 -> V_86 ) ;
}
}
F_19 () ;
V_61 = F_20 ( V_4 -> V_61 ) ;
if ( V_61 )
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 ,
L_36 ,
V_61 -> V_87 ,
V_61 -> V_88 ) ;
F_21 () ;
F_8 ( & V_2 -> V_53 ) ;
return F_11 ( V_55 , V_43 , V_44 , V_42 , V_58 ) ;
}
static T_1 F_22 ( struct V_3 * V_4 ,
char * V_42 , T_2 V_43 ,
T_3 * V_44 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_82 * V_89 ;
bool V_90 ;
int V_45 ;
if ( V_9 -> V_59 >= F_15 ( V_2 -> V_81 ) )
return - V_91 ;
if ( F_23 ( V_42 , & V_90 ) != 0 )
return - V_46 ;
F_6 ( & V_2 -> V_53 ) ;
V_89 = F_24 ( V_2 , V_9 -> V_59 ) ;
if ( F_18 ( V_89 ) ) {
F_8 ( & V_2 -> V_53 ) ;
return - V_91 ;
}
V_89 -> V_86 = false ;
V_45 = F_25 ( V_2 , V_9 -> V_59 ,
V_90 ) ;
if ( ! V_45 )
V_89 -> V_86 = true ;
F_8 ( & V_2 -> V_53 ) ;
return V_45 ? : V_43 ;
}
static void F_26 ( struct V_3 * V_4 ,
enum V_92 V_6 , int V_93 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_94 * V_95 = & V_9 -> V_95 ;
V_95 -> V_12 |= V_6 ;
switch ( V_6 ) {
case V_96 :
V_95 -> V_97 = V_93 ;
break;
case V_98 :
V_95 -> V_99 = V_93 ;
break;
case V_100 :
V_95 -> V_101 = V_93 ;
break;
case V_102 :
V_95 -> V_103 = V_93 ;
break;
case V_104 :
V_95 -> V_105 = V_93 ;
break;
case V_106 :
V_95 -> V_107 = V_93 ;
break;
case V_108 :
V_95 -> V_109 = V_93 ;
break;
case V_110 :
V_95 -> V_111 = V_93 ;
break;
case V_112 :
V_95 -> V_113 = V_93 ;
break;
case V_114 :
V_95 -> V_115 = V_93 ;
break;
case V_116 :
V_95 -> V_117 = V_93 ;
break;
}
}
static T_1 F_27 ( struct V_3 * V_4 , char * V_42 ,
T_2 V_43 , T_3 * V_44 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
enum V_92 V_6 ;
int V_93 , V_45 = 0 ;
if ( ! strncmp ( L_37 , V_42 , 16 ) ) {
if ( sscanf ( V_42 + 16 , L_15 , & V_93 ) != 1 )
return - V_46 ;
if ( V_93 < V_118 ||
V_93 > V_119 )
return - V_46 ;
V_6 = V_96 ;
} else if ( ! strncmp ( L_38 , V_42 , 24 ) ) {
if ( sscanf ( V_42 + 24 , L_15 , & V_93 ) != 1 )
return - V_46 ;
if ( V_93 < V_120 ||
V_93 > V_121 )
return - V_46 ;
V_6 = V_98 ;
} else if ( ! strncmp ( L_39 , V_42 , 17 ) ) {
if ( sscanf ( V_42 + 17 , L_15 , & V_93 ) != 1 )
return - V_46 ;
if ( V_93 < V_122 ||
V_93 > V_123 )
return - V_46 ;
V_6 = V_100 ;
} else if ( ! strncmp ( L_40 , V_42 , 18 ) ) {
if ( sscanf ( V_42 + 18 , L_15 , & V_93 ) != 1 )
return - V_46 ;
if ( V_93 < V_124 ||
V_93 > V_125 )
return - V_46 ;
V_6 = V_102 ;
} else if ( ! strncmp ( L_41 , V_42 , 20 ) ) {
if ( sscanf ( V_42 + 20 , L_15 , & V_93 ) != 1 )
return - V_46 ;
if ( V_93 < V_126 ||
V_93 > V_127 )
return - V_46 ;
V_6 = V_104 ;
} else if ( ! strncmp ( L_42 , V_42 , 20 ) ) {
if ( sscanf ( V_42 + 20 , L_15 , & V_93 ) != 1 )
return - V_46 ;
if ( V_93 < V_128 ||
V_93 > V_129 )
return - V_46 ;
V_6 = V_106 ;
} else if ( ! strncmp ( L_43 , V_42 , 24 ) ) {
if ( sscanf ( V_42 + 24 , L_15 , & V_93 ) != 1 )
return - V_46 ;
if ( V_93 < 0 || V_93 > 1 )
return - V_46 ;
V_6 = V_108 ;
} else if ( ! strncmp ( L_44 , V_42 , 14 ) ) {
if ( sscanf ( V_42 + 14 , L_15 , & V_93 ) != 1 )
return - V_46 ;
if ( V_93 < 0 || V_93 > 1 )
return - V_46 ;
V_6 = V_110 ;
} else if ( ! strncmp ( L_45 , V_42 , 16 ) ) {
if ( sscanf ( V_42 + 16 , L_15 , & V_93 ) != 1 )
return - V_46 ;
if ( V_93 < V_130 ||
V_93 > V_131 )
return - V_46 ;
V_6 = V_112 ;
} else if ( ! strncmp ( L_46 , V_42 , 16 ) ) {
if ( sscanf ( V_42 + 16 , L_15 , & V_93 ) != 1 )
return - V_46 ;
if ( V_93 < V_132 ||
V_93 > V_133 )
return - V_46 ;
V_6 = V_116 ;
} else if ( ! strncmp ( L_47 , V_42 , 23 ) ) {
if ( sscanf ( V_42 + 23 , L_15 , & V_93 ) != 1 )
return - V_46 ;
if ( V_93 < 0 || V_93 > 1 )
return - V_46 ;
V_6 = V_114 ;
} else {
return - V_46 ;
}
F_6 ( & V_2 -> V_53 ) ;
F_26 ( V_4 , V_6 , V_93 ) ;
if ( V_6 == V_108 && ! V_93 )
V_45 = F_28 ( V_2 , V_4 , V_134 ) ;
else
V_45 = F_29 ( V_2 , V_4 , V_134 ) ;
F_8 ( & V_2 -> V_53 ) ;
return V_45 ? : V_43 ;
}
static T_1 F_30 ( struct V_54 * V_54 ,
char T_4 * V_55 ,
T_2 V_43 , T_3 * V_44 )
{
struct V_3 * V_4 = V_54 -> V_56 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_42 [ 256 ] ;
int V_58 = 0 ;
const T_2 V_57 = sizeof( V_42 ) ;
struct V_135 V_136 = {
V_137 ,
. V_109 =
F_31 ( V_138 ) ,
. V_115 =
F_31 ( V_139 ) ,
} ;
F_32 ( V_4 , & V_136 ) ;
if ( V_9 -> V_140 . V_141 )
V_136 . V_109 = F_31 ( 1 ) ;
else
V_136 . V_109 = 0 ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_48 ,
F_33 ( V_136 . V_97 ) ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_49 ,
F_33 ( V_136 . V_99 ) ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_50 ,
F_33 ( V_136 . V_101 ) ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_51 ,
F_33 ( V_136 . V_103 ) ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_52 ,
F_33 ( V_136 . V_105 ) ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_53 ,
F_33 ( V_136 . V_107 ) ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_54 ,
F_33 ( V_136 . V_109 ) ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_55 ,
F_33 ( V_136 . V_111 ) ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_56 ,
F_33 ( V_136 . V_113 ) ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_57 ,
F_33 ( V_136 . V_117 ) ) ;
V_58 += F_14 ( V_42 + V_58 , V_57 - V_58 , L_58 ,
F_33 ( V_136 . V_115 ) ) ;
return F_11 ( V_55 , V_43 , V_44 , V_42 , V_58 ) ;
}
static T_1 F_34 ( struct V_3 * V_4 , char * V_42 ,
T_2 V_43 , T_3 * V_44 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_5 V_93 ;
int V_45 ;
V_45 = F_35 ( V_42 , 0 , & V_93 ) ;
if ( V_45 )
return V_45 ;
if ( V_93 > 1 )
return - V_46 ;
F_6 ( & V_2 -> V_53 ) ;
F_36 ( V_2 , V_4 , V_93 ) ;
F_8 ( & V_2 -> V_53 ) ;
return V_43 ;
}
static T_1 F_37 ( struct V_54 * V_54 ,
char T_4 * V_55 ,
T_2 V_43 , T_3 * V_44 )
{
struct V_3 * V_4 = V_54 -> V_56 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_42 [ 3 ] ;
V_42 [ 0 ] = V_9 -> V_142 ? '1' : '0' ;
V_42 [ 1 ] = '\n' ;
V_42 [ 2 ] = '\0' ;
return F_11 ( V_55 , V_43 , V_44 , V_42 , sizeof( V_42 ) ) ;
}
void F_38 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_143 * V_144 = V_4 -> V_145 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_42 [ 100 ] ;
if ( ! V_144 || V_9 -> V_144 )
return;
V_9 -> V_144 = F_39 ( L_59 , V_144 ) ;
V_9 -> V_2 = V_2 ;
if ( ! V_9 -> V_144 ) {
F_40 ( V_2 , L_60 ,
V_144 -> V_146 . V_147 ) ;
return;
}
if ( ( V_2 -> V_47 -> V_48 . V_49 & V_148 ) &&
V_149 . V_150 != V_151 &&
( ( V_4 -> type == V_64 && ! V_4 -> V_152 ) ||
( V_4 -> type == V_64 && V_4 -> V_152 &&
V_2 -> V_47 -> V_48 . V_49 & V_153 ) ) )
F_41 ( V_154 , V_9 -> V_144 , V_155 |
V_156 ) ;
F_41 ( V_157 , V_9 -> V_144 , V_156 ) ;
F_41 ( V_158 , V_9 -> V_144 , V_155 ) ;
F_41 ( V_142 , V_9 -> V_144 ,
V_156 | V_155 ) ;
if ( V_4 -> type == V_64 && ! V_4 -> V_152 &&
V_9 == V_2 -> V_159 )
F_41 ( V_160 , V_9 -> V_144 ,
V_156 | V_155 ) ;
snprintf ( V_42 , 100 , L_61 ,
V_144 -> V_161 -> V_161 -> V_146 . V_147 ,
V_144 -> V_161 -> V_146 . V_147 ,
V_144 -> V_146 . V_147 ,
V_9 -> V_144 -> V_146 . V_147 ) ;
V_9 -> V_162 = F_42 ( V_144 -> V_146 . V_147 ,
V_2 -> V_145 , V_42 ) ;
if ( ! V_9 -> V_162 )
F_40 ( V_2 , L_62 ,
V_144 -> V_146 . V_147 ) ;
return;
V_163:
F_40 ( V_2 , L_63 ) ;
}
void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
F_44 ( V_9 -> V_162 ) ;
V_9 -> V_162 = NULL ;
F_45 ( V_9 -> V_144 ) ;
V_9 -> V_144 = NULL ;
}
