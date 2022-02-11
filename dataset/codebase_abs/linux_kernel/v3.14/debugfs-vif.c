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
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_25 ,
V_9 -> V_63 , V_9 -> V_64 ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_26 ,
V_4 -> V_20 . V_65 ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_27 ) ;
for ( V_62 = 0 ; V_62 < F_14 ( V_9 -> V_66 ) ; V_62 ++ )
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 ,
L_28 ,
V_62 , V_9 -> V_66 [ V_62 ] . V_67 ,
V_9 -> V_66 [ V_62 ] . V_68 ,
V_9 -> V_66 [ V_62 ] . V_69 ,
V_9 -> V_66 [ V_62 ] . V_70 ,
V_9 -> V_66 [ V_62 ] . V_71 ) ;
if ( V_4 -> type == V_72 &&
V_59 != V_73 ) {
struct V_74 * V_75 ;
V_75 = F_15 ( V_2 -> V_76 [ V_59 ] ,
F_16 ( & V_2 -> V_53 ) ) ;
if ( ! F_17 ( V_75 ) ) {
struct V_77 * V_78 = ( void * ) V_75 -> V_79 ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 ,
L_29 ,
V_59 ,
V_78 -> V_80 ) ;
}
}
F_18 () ;
V_61 = F_19 ( V_4 -> V_61 ) ;
if ( V_61 )
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 ,
L_30 ,
V_61 -> V_81 ,
V_61 -> V_82 ) ;
F_20 () ;
F_8 ( & V_2 -> V_53 ) ;
return F_11 ( V_55 , V_43 , V_44 , V_42 , V_58 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
enum V_83 V_6 , int V_84 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_85 * V_86 = & V_9 -> V_86 ;
V_86 -> V_12 |= V_6 ;
switch ( V_6 ) {
case V_87 :
V_86 -> V_88 = V_84 ;
break;
case V_89 :
V_86 -> V_90 = V_84 ;
break;
case V_91 :
V_86 -> V_92 = V_84 ;
break;
case V_93 :
V_86 -> V_94 = V_84 ;
break;
case V_95 :
V_86 -> V_96 = V_84 ;
break;
case V_97 :
V_86 -> V_98 = V_84 ;
break;
case V_99 :
V_86 -> V_100 = V_84 ;
break;
case V_101 :
V_86 -> V_102 = V_84 ;
break;
case V_103 :
V_86 -> V_104 = V_84 ;
break;
case V_105 :
V_86 -> V_106 = V_84 ;
break;
case V_107 :
V_86 -> V_108 = V_84 ;
break;
}
}
static T_1 F_22 ( struct V_3 * V_4 , char * V_42 ,
T_2 V_43 , T_3 * V_44 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
enum V_83 V_6 ;
int V_84 , V_45 = 0 ;
if ( ! strncmp ( L_31 , V_42 , 16 ) ) {
if ( sscanf ( V_42 + 16 , L_15 , & V_84 ) != 1 )
return - V_46 ;
if ( V_84 < V_109 ||
V_84 > V_110 )
return - V_46 ;
V_6 = V_87 ;
} else if ( ! strncmp ( L_32 , V_42 , 24 ) ) {
if ( sscanf ( V_42 + 24 , L_15 , & V_84 ) != 1 )
return - V_46 ;
if ( V_84 < V_111 ||
V_84 > V_112 )
return - V_46 ;
V_6 = V_89 ;
} else if ( ! strncmp ( L_33 , V_42 , 17 ) ) {
if ( sscanf ( V_42 + 17 , L_15 , & V_84 ) != 1 )
return - V_46 ;
if ( V_84 < V_113 ||
V_84 > V_114 )
return - V_46 ;
V_6 = V_91 ;
} else if ( ! strncmp ( L_34 , V_42 , 18 ) ) {
if ( sscanf ( V_42 + 18 , L_15 , & V_84 ) != 1 )
return - V_46 ;
if ( V_84 < V_115 ||
V_84 > V_116 )
return - V_46 ;
V_6 = V_93 ;
} else if ( ! strncmp ( L_35 , V_42 , 20 ) ) {
if ( sscanf ( V_42 + 20 , L_15 , & V_84 ) != 1 )
return - V_46 ;
if ( V_84 < V_117 ||
V_84 > V_118 )
return - V_46 ;
V_6 = V_95 ;
} else if ( ! strncmp ( L_36 , V_42 , 20 ) ) {
if ( sscanf ( V_42 + 20 , L_15 , & V_84 ) != 1 )
return - V_46 ;
if ( V_84 < V_119 ||
V_84 > V_120 )
return - V_46 ;
V_6 = V_97 ;
} else if ( ! strncmp ( L_37 , V_42 , 24 ) ) {
if ( sscanf ( V_42 + 24 , L_15 , & V_84 ) != 1 )
return - V_46 ;
if ( V_84 < 0 || V_84 > 1 )
return - V_46 ;
V_6 = V_99 ;
} else if ( ! strncmp ( L_38 , V_42 , 14 ) ) {
if ( sscanf ( V_42 + 14 , L_15 , & V_84 ) != 1 )
return - V_46 ;
if ( V_84 < 0 || V_84 > 1 )
return - V_46 ;
V_6 = V_101 ;
} else if ( ! strncmp ( L_39 , V_42 , 16 ) ) {
if ( sscanf ( V_42 + 16 , L_15 , & V_84 ) != 1 )
return - V_46 ;
if ( V_84 < V_121 ||
V_84 > V_122 )
return - V_46 ;
V_6 = V_103 ;
} else if ( ! strncmp ( L_40 , V_42 , 16 ) ) {
if ( sscanf ( V_42 + 16 , L_15 , & V_84 ) != 1 )
return - V_46 ;
if ( V_84 < V_123 ||
V_84 > V_124 )
return - V_46 ;
V_6 = V_107 ;
} else if ( ! strncmp ( L_41 , V_42 , 23 ) ) {
if ( sscanf ( V_42 + 23 , L_15 , & V_84 ) != 1 )
return - V_46 ;
if ( V_84 < 0 || V_84 > 1 )
return - V_46 ;
V_6 = V_105 ;
} else {
return - V_46 ;
}
F_6 ( & V_2 -> V_53 ) ;
F_21 ( V_4 , V_6 , V_84 ) ;
if ( V_6 == V_99 && ! V_84 )
V_45 = F_23 ( V_2 , V_4 ) ;
else
V_45 = F_24 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_53 ) ;
return V_45 ? : V_43 ;
}
static T_1 F_25 ( struct V_54 * V_54 ,
char T_4 * V_55 ,
T_2 V_43 , T_3 * V_44 )
{
struct V_3 * V_4 = V_54 -> V_56 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_42 [ 256 ] ;
int V_58 = 0 ;
const T_2 V_57 = sizeof( V_42 ) ;
struct V_125 V_126 = {
V_127 ,
. V_100 =
F_26 ( V_128 ) ,
. V_106 =
F_26 ( V_129 ) ,
} ;
F_27 ( V_4 , & V_126 ) ;
if ( V_9 -> V_130 . V_131 )
V_126 . V_100 = F_26 ( 1 ) ;
else
V_126 . V_100 = 0 ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_42 ,
F_28 ( V_126 . V_88 ) ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_43 ,
F_28 ( V_126 . V_90 ) ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_44 ,
F_28 ( V_126 . V_92 ) ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_45 ,
F_28 ( V_126 . V_94 ) ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_46 ,
F_28 ( V_126 . V_96 ) ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_47 ,
F_28 ( V_126 . V_98 ) ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_48 ,
F_28 ( V_126 . V_100 ) ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_49 ,
F_28 ( V_126 . V_102 ) ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_50 ,
F_28 ( V_126 . V_104 ) ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_51 ,
F_28 ( V_126 . V_108 ) ) ;
V_58 += F_13 ( V_42 + V_58 , V_57 - V_58 , L_52 ,
F_28 ( V_126 . V_106 ) ) ;
return F_11 ( V_55 , V_43 , V_44 , V_42 , V_58 ) ;
}
void F_29 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_132 * V_133 = V_4 -> V_134 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
char V_42 [ 100 ] ;
if ( ! V_133 || V_9 -> V_133 )
return;
V_9 -> V_133 = F_30 ( L_53 , V_133 ) ;
V_9 -> V_2 = V_2 ;
if ( ! V_9 -> V_133 ) {
F_31 ( V_2 , L_54 ,
V_133 -> V_135 . V_136 ) ;
return;
}
if ( V_137 . V_138 != V_139 &&
( ( V_4 -> type == V_72 && ! V_4 -> V_140 ) ||
( V_4 -> type == V_72 && V_4 -> V_140 &&
V_2 -> V_47 -> V_48 . V_49 & V_141 ) ) )
F_32 ( V_142 , V_9 -> V_133 , V_143 |
V_144 ) ;
F_32 ( V_145 , V_9 -> V_133 ,
V_144 ) ;
if ( V_4 -> type == V_72 && ! V_4 -> V_140 &&
V_9 == V_2 -> V_146 )
F_32 ( V_147 , V_9 -> V_133 ,
V_144 | V_143 ) ;
snprintf ( V_42 , 100 , L_55 ,
V_133 -> V_148 -> V_148 -> V_135 . V_136 ,
V_133 -> V_148 -> V_135 . V_136 ,
V_133 -> V_135 . V_136 ,
V_9 -> V_133 -> V_135 . V_136 ) ;
V_9 -> V_149 = F_33 ( V_133 -> V_135 . V_136 ,
V_2 -> V_134 , V_42 ) ;
if ( ! V_9 -> V_149 )
F_31 ( V_2 , L_56 ,
V_133 -> V_135 . V_136 ) ;
return;
V_150:
F_31 ( V_2 , L_57 ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
F_35 ( V_9 -> V_149 ) ;
V_9 -> V_149 = NULL ;
F_36 ( V_9 -> V_133 ) ;
V_9 -> V_133 = NULL ;
}
