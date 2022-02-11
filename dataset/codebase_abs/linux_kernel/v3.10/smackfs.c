static inline void F_1 ( unsigned int V_1 , char * V_2 )
{
if ( V_1 == 0 || V_1 > ( V_3 * 8 ) )
return;
V_2 [ ( V_1 - 1 ) / 8 ] |= 0x80 >> ( ( V_1 - 1 ) % 8 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
V_5 -> V_6 = F_3 ( V_7 ) ;
V_5 -> V_8 = F_4 ( V_7 ) ;
V_5 -> V_9 = F_5 ( F_6 () ) ;
}
static int F_7 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , int V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 = 0 ;
int V_22 = 0 ;
F_8 ( V_15 ) ;
F_9 (sp, rule_list, list) {
if ( V_18 -> V_23 == V_11 -> V_23 &&
V_18 -> V_24 == V_11 -> V_24 ) {
V_21 = 1 ;
V_18 -> V_25 |= V_11 -> V_26 ;
V_18 -> V_25 &= ~ V_11 -> V_27 ;
break;
}
}
if ( V_21 == 0 ) {
V_18 = F_10 ( sizeof( * V_18 ) , V_28 ) ;
if ( V_18 == NULL ) {
V_22 = - V_29 ;
goto V_30;
}
V_18 -> V_24 = V_11 -> V_24 ;
V_18 -> V_23 = V_11 -> V_23 ;
V_18 -> V_25 = V_11 -> V_26 & ~ V_11 -> V_27 ;
F_11 ( & V_18 -> V_31 , V_13 ) ;
if ( V_16 ) {
V_20 = F_10 ( sizeof( * V_20 ) , V_28 ) ;
if ( V_20 != NULL ) {
V_20 -> V_32 = V_18 ;
F_11 ( & V_20 -> V_31 , & V_33 ) ;
} else
V_22 = - V_29 ;
}
}
V_30:
F_12 ( V_15 ) ;
return V_22 ;
}
static int F_13 ( const char * string )
{
int V_34 = 0 ;
const char * V_35 ;
for ( V_35 = string ; ; V_35 ++ )
switch ( * V_35 ) {
case '-' :
break;
case 'r' :
case 'R' :
V_34 |= V_36 ;
break;
case 'w' :
case 'W' :
V_34 |= V_37 ;
break;
case 'x' :
case 'X' :
V_34 |= V_38 ;
break;
case 'a' :
case 'A' :
V_34 |= V_39 ;
break;
case 't' :
case 'T' :
V_34 |= V_40 ;
break;
default:
return V_34 ;
}
}
static int F_14 ( const char * V_41 , const char * V_42 ,
const char * V_43 , const char * V_44 ,
struct V_10 * V_45 , int V_46 ,
int V_47 )
{
const char * V_35 ;
struct V_48 * V_49 ;
if ( V_46 ) {
V_45 -> V_24 = F_15 ( V_41 , V_47 ) ;
if ( V_45 -> V_24 == NULL )
return - 1 ;
V_45 -> V_23 = F_15 ( V_42 , V_47 ) ;
if ( V_45 -> V_23 == NULL )
return - 1 ;
} else {
V_35 = F_16 ( V_41 , V_47 ) ;
if ( V_35 == NULL )
return - 1 ;
V_49 = F_17 ( V_35 ) ;
F_18 ( V_35 ) ;
if ( V_49 == NULL )
return - 1 ;
V_45 -> V_24 = V_49 -> V_50 ;
V_35 = F_16 ( V_42 , V_47 ) ;
if ( V_35 == NULL )
return - 1 ;
V_49 = F_17 ( V_35 ) ;
F_18 ( V_35 ) ;
if ( V_49 == NULL )
return - 1 ;
V_45 -> V_23 = V_49 -> V_50 ;
}
V_45 -> V_26 = F_13 ( V_43 ) ;
if ( V_44 )
V_45 -> V_27 = F_13 ( V_44 ) ;
else
V_45 -> V_27 = ~ V_45 -> V_26 ;
return 0 ;
}
static int F_19 ( const char * V_51 , struct V_10 * V_45 ,
int V_46 )
{
int V_22 ;
V_22 = F_14 ( V_51 , V_51 + V_52 ,
V_51 + V_52 + V_52 , NULL , V_45 ,
V_46 , V_52 ) ;
return V_22 ;
}
static int F_20 ( const char * V_51 , struct V_10 * V_45 ,
int V_46 , int V_53 )
{
char * V_41 ;
char * V_42 ;
char * V_43 ;
char * V_44 ;
int V_54 ;
int V_22 = - 1 ;
V_54 = strlen ( V_51 ) ;
V_41 = F_10 ( V_54 + 1 , V_28 ) ;
if ( V_41 == NULL )
return - 1 ;
V_42 = F_10 ( V_54 , V_28 ) ;
if ( V_42 == NULL )
goto V_55;
V_43 = F_10 ( V_54 , V_28 ) ;
if ( V_43 == NULL )
goto V_56;
V_44 = F_10 ( V_54 , V_28 ) ;
if ( V_44 == NULL )
goto V_57;
if ( V_53 ) {
if ( sscanf ( V_51 , L_1 ,
V_41 , V_42 , V_43 , V_44 ) == 4 )
V_22 = F_14 ( V_41 , V_42 , V_43 , V_44 ,
V_45 , V_46 , 0 ) ;
} else {
if ( sscanf ( V_51 , L_2 , V_41 , V_42 , V_43 ) == 3 )
V_22 = F_14 ( V_41 , V_42 , V_43 , NULL ,
V_45 , V_46 , 0 ) ;
}
F_18 ( V_44 ) ;
V_57:
F_18 ( V_43 ) ;
V_56:
F_18 ( V_42 ) ;
V_55:
F_18 ( V_41 ) ;
return V_22 ;
}
static T_1 F_21 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , int V_62 )
{
struct V_48 * V_49 ;
struct V_10 * V_45 ;
char * V_51 ;
int V_54 ;
int V_22 = - V_63 ;
int V_64 = 0 ;
if ( * V_61 != 0 )
return - V_63 ;
if ( V_62 == V_65 ) {
if ( V_60 != V_66 && V_60 != V_67 )
return - V_63 ;
V_54 = V_67 ;
} else
V_54 = V_60 + 1 ;
V_51 = F_10 ( V_54 , V_28 ) ;
if ( V_51 == NULL )
return - V_29 ;
if ( F_22 ( V_51 , V_59 , V_60 ) != 0 ) {
V_22 = - V_68 ;
goto V_30;
}
V_45 = F_10 ( sizeof( * V_45 ) , V_28 ) ;
if ( V_45 == NULL ) {
V_22 = - V_29 ;
goto V_30;
}
if ( V_62 == V_69 ) {
V_51 [ V_60 ] = '\0' ;
if ( F_20 ( V_51 , V_45 , 1 , 0 ) )
goto V_70;
} else if ( V_62 == V_71 ) {
V_51 [ V_60 ] = '\0' ;
if ( F_20 ( V_51 , V_45 , 1 , 1 ) )
goto V_70;
} else {
if ( V_60 == ( V_66 ) )
V_51 [ V_66 ] = '-' ;
if ( F_19 ( V_51 , V_45 , 1 ) )
goto V_70;
}
if ( V_13 == NULL ) {
V_64 = 1 ;
V_49 = F_17 ( V_45 -> V_24 ) ;
V_13 = & V_49 -> V_72 ;
V_15 = & V_49 -> V_73 ;
}
V_22 = F_7 ( V_45 , V_13 , V_15 , V_64 ) ;
if ( V_22 == 0 ) {
V_22 = V_60 ;
goto V_30;
}
V_70:
F_18 ( V_45 ) ;
V_30:
F_18 ( V_51 ) ;
return V_22 ;
}
static void * F_23 ( struct V_74 * V_75 , T_4 * V_76 ,
struct V_12 * V_77 )
{
struct V_12 * V_31 ;
if ( V_75 -> V_78 == 0 )
V_75 -> V_79 = V_77 ;
if ( V_75 -> V_79 == NULL )
return NULL ;
V_31 = V_75 -> V_79 ;
if ( F_24 ( V_31 ) )
return NULL ;
if ( V_75 -> V_78 == 0 )
return V_31 -> V_80 ;
return V_31 ;
}
static void * F_25 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 ,
struct V_12 * V_77 )
{
struct V_12 * V_31 = V_81 ;
if ( F_26 ( V_31 , V_77 ) ) {
V_75 -> V_79 = NULL ;
return NULL ;
}
V_75 -> V_79 = V_31 -> V_80 ;
return V_31 -> V_80 ;
}
static void F_27 ( struct V_74 * V_75 , void * V_81 )
{
}
static void F_28 ( struct V_74 * V_75 , struct V_17 * V_11 , int V_82 )
{
if ( strlen ( V_11 -> V_24 ) >= V_82 || strlen ( V_11 -> V_23 ) >= V_82 )
return;
if ( V_11 -> V_25 == 0 )
return;
F_29 ( V_75 , L_3 , V_11 -> V_24 , V_11 -> V_23 ) ;
F_30 ( V_75 , ' ' ) ;
if ( V_11 -> V_25 & V_36 )
F_30 ( V_75 , 'r' ) ;
if ( V_11 -> V_25 & V_37 )
F_30 ( V_75 , 'w' ) ;
if ( V_11 -> V_25 & V_38 )
F_30 ( V_75 , 'x' ) ;
if ( V_11 -> V_25 & V_39 )
F_30 ( V_75 , 'a' ) ;
if ( V_11 -> V_25 & V_40 )
F_30 ( V_75 , 't' ) ;
F_30 ( V_75 , '\n' ) ;
}
static void * F_31 ( struct V_74 * V_75 , T_4 * V_76 )
{
return F_23 ( V_75 , V_76 , & V_33 ) ;
}
static void * F_32 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 )
{
return F_25 ( V_75 , V_81 , V_76 , & V_33 ) ;
}
static int F_33 ( struct V_74 * V_75 , void * V_81 )
{
struct V_12 * V_31 = V_81 ;
struct V_19 * V_20 =
F_34 ( V_31 , struct V_19 , V_31 ) ;
F_28 ( V_75 , V_20 -> V_32 , V_52 ) ;
return 0 ;
}
static int F_35 ( struct V_83 * V_83 , struct V_58 * V_58 )
{
return F_36 ( V_58 , & V_84 ) ;
}
static T_1 F_37 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
if ( ! F_38 ( V_85 ) )
return - V_86 ;
return F_21 ( V_58 , V_59 , V_60 , V_61 , NULL , NULL ,
V_65 ) ;
}
static void F_39 ( void )
{
int V_22 ;
struct V_87 * V_88 ;
struct V_4 V_89 ;
F_2 ( & V_89 ) ;
V_22 = F_40 ( NULL , V_90 , NULL , NULL , & V_89 ) ;
if ( V_22 != 0 )
F_41 ( V_91 L_4 ,
V_92 , __LINE__ , V_22 ) ;
V_88 = F_42 ( sizeof( struct V_87 ) , V_28 ) ;
if ( V_88 == NULL )
F_43 ( L_5 ) ;
V_88 -> V_93 . V_94 = NULL ;
V_88 -> V_95 = V_96 ;
V_88 -> type = V_97 ;
V_88 -> V_98 [ 0 ] = V_99 ;
for ( V_22 = 1 ; V_22 < V_100 ; V_22 ++ )
V_88 -> V_98 [ V_22 ] = V_101 ;
V_22 = F_44 ( V_88 , & V_89 ) ;
if ( V_22 != 0 ) {
F_41 ( V_91 L_6 ,
V_92 , __LINE__ , V_22 ) ;
F_18 ( V_88 ) ;
return;
}
V_22 = F_45 ( V_88 -> V_95 , NULL , NULL , NULL , & V_89 ) ;
if ( V_22 != 0 ) {
F_41 ( V_91 L_7 ,
V_92 , __LINE__ , V_22 ) ;
F_18 ( V_88 ) ;
return;
}
}
static void F_46 ( char * V_102 )
{
int V_22 ;
struct V_4 V_89 ;
F_2 ( & V_89 ) ;
if ( V_102 != NULL ) {
V_22 = F_40 ( V_102 , V_90 , NULL , NULL , & V_89 ) ;
if ( V_22 != 0 )
F_41 ( V_91 L_4 ,
V_92 , __LINE__ , V_22 ) ;
}
if ( V_103 == NULL )
V_103 = V_104 . V_50 ;
V_22 = F_47 ( V_103 , V_90 ,
NULL , NULL , & V_89 ) ;
if ( V_22 != 0 )
F_41 ( V_91 L_8 ,
V_92 , __LINE__ , V_22 ) ;
}
static void * F_48 ( struct V_74 * V_75 , T_4 * V_76 )
{
return F_23 ( V_75 , V_76 , & V_105 ) ;
}
static void * F_49 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 )
{
return F_25 ( V_75 , V_81 , V_76 , & V_105 ) ;
}
static int F_50 ( struct V_74 * V_75 , void * V_81 )
{
struct V_12 * V_31 = V_81 ;
struct V_48 * V_49 =
F_34 ( V_31 , struct V_48 , V_31 ) ;
struct V_106 * V_107 = V_49 -> V_108 . V_109 . V_110 . V_1 ;
char V_111 = '/' ;
int V_112 ;
if ( strlen ( V_49 -> V_50 ) >= V_52 )
return 0 ;
F_29 ( V_75 , L_9 , V_49 -> V_50 , V_49 -> V_108 . V_109 . V_110 . V_113 ) ;
for ( V_112 = F_51 ( V_107 , 0 ) ; V_112 >= 0 ;
V_112 = F_51 ( V_107 , V_112 + 1 ) ) {
F_29 ( V_75 , L_10 , V_111 , V_112 ) ;
V_111 = ',' ;
}
F_30 ( V_75 , '\n' ) ;
return 0 ;
}
static int F_52 ( struct V_83 * V_83 , struct V_58 * V_58 )
{
return F_36 ( V_58 , & V_114 ) ;
}
static T_1 F_53 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 , int V_62 )
{
struct V_48 * V_49 ;
struct V_115 V_116 ;
char V_117 [ V_3 ] ;
int V_118 ;
unsigned int V_1 ;
int V_119 ;
T_1 V_22 = - V_63 ;
char * V_51 = NULL ;
char * V_45 ;
int V_120 ;
int V_112 ;
if ( ! F_38 ( V_85 ) )
return - V_86 ;
if ( * V_61 != 0 )
return - V_63 ;
if ( V_62 == V_65 &&
( V_60 < V_121 || V_60 > V_122 ) )
return - V_63 ;
V_51 = F_10 ( V_60 + 1 , V_28 ) ;
if ( V_51 == NULL )
return - V_29 ;
if ( F_22 ( V_51 , V_59 , V_60 ) != 0 ) {
V_22 = - V_68 ;
goto V_123;
}
V_51 [ V_60 ] = '\0' ;
V_45 = V_51 ;
F_8 ( & V_124 ) ;
V_49 = F_54 ( V_45 , 0 ) ;
if ( V_49 == NULL )
goto V_30;
if ( V_62 == V_65 )
V_45 += V_52 ;
else
V_45 += strlen ( V_49 -> V_50 ) ;
V_120 = sscanf ( V_45 , L_11 , & V_118 ) ;
if ( V_120 != 1 || V_118 > V_125 )
goto V_30;
V_45 += V_126 ;
V_120 = sscanf ( V_45 , L_11 , & V_119 ) ;
if ( V_120 != 1 || V_119 > V_127 )
goto V_30;
if ( V_62 == V_65 &&
V_60 != ( V_121 + V_119 * V_126 ) )
goto V_30;
memset ( V_117 , 0 , sizeof( V_117 ) ) ;
for ( V_112 = 0 ; V_112 < V_119 ; V_112 ++ ) {
V_45 += V_126 ;
V_120 = sscanf ( V_45 , L_12 , & V_1 ) ;
if ( V_120 != 1 || V_1 > V_128 )
goto V_30;
F_1 ( V_1 , V_117 ) ;
}
V_22 = F_55 ( V_118 , V_117 , & V_116 , V_3 ) ;
if ( V_22 >= 0 ) {
F_56 ( V_49 -> V_108 . V_109 . V_110 . V_1 ) ;
V_49 -> V_108 . V_109 . V_110 . V_1 = V_116 . V_109 . V_110 . V_1 ;
V_49 -> V_108 . V_109 . V_110 . V_113 = V_116 . V_109 . V_110 . V_113 ;
V_22 = V_60 ;
}
V_30:
F_12 ( & V_124 ) ;
V_123:
F_18 ( V_51 ) ;
return V_22 ;
}
static T_1 F_57 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
return F_53 ( V_58 , V_59 , V_60 , V_61 , V_65 ) ;
}
static int F_58 ( struct V_74 * V_75 , void * V_81 )
{
struct V_12 * V_31 = V_81 ;
struct V_48 * V_49 =
F_34 ( V_31 , struct V_48 , V_31 ) ;
struct V_106 * V_107 = V_49 -> V_108 . V_109 . V_110 . V_1 ;
char V_111 = '/' ;
int V_112 ;
F_29 ( V_75 , L_9 , V_49 -> V_50 , V_49 -> V_108 . V_109 . V_110 . V_113 ) ;
for ( V_112 = F_51 ( V_107 , 0 ) ; V_112 >= 0 ;
V_112 = F_51 ( V_107 , V_112 + 1 ) ) {
F_29 ( V_75 , L_10 , V_111 , V_112 ) ;
V_111 = ',' ;
}
F_30 ( V_75 , '\n' ) ;
return 0 ;
}
static int F_59 ( struct V_83 * V_83 , struct V_58 * V_58 )
{
return F_36 ( V_58 , & V_129 ) ;
}
static T_1 F_60 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
return F_53 ( V_58 , V_59 , V_60 , V_61 , V_69 ) ;
}
static void * F_61 ( struct V_74 * V_75 , T_4 * V_76 )
{
return F_23 ( V_75 , V_76 , & V_130 ) ;
}
static void * F_62 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 )
{
return F_25 ( V_75 , V_81 , V_76 , & V_130 ) ;
}
static int F_63 ( struct V_74 * V_75 , void * V_81 )
{
struct V_12 * V_31 = V_81 ;
struct V_131 * V_49 =
F_34 ( V_31 , struct V_131 , V_31 ) ;
unsigned char * V_132 = ( char * ) & V_49 -> V_133 . V_134 . V_135 ;
int V_136 ;
T_5 V_137 = F_64 ( V_49 -> V_138 . V_135 ) ;
for ( V_136 = 0 ; V_137 ; V_137 <<= 1 , V_136 ++ ) ;
F_29 ( V_75 , L_13 ,
V_132 [ 0 ] , V_132 [ 1 ] , V_132 [ 2 ] , V_132 [ 3 ] , V_136 , V_49 -> V_139 ) ;
return 0 ;
}
static int F_65 ( struct V_83 * V_83 , struct V_58 * V_58 )
{
return F_36 ( V_58 , & V_140 ) ;
}
static void F_66 ( struct V_131 * V_141 )
{
struct V_131 * V_142 , * V_143 ;
if ( F_24 ( & V_130 ) ) {
F_11 ( & V_141 -> V_31 , & V_130 ) ;
return;
}
V_142 = F_67 ( V_130 . V_80 ,
struct V_131 , V_31 ) ;
if ( V_141 -> V_138 . V_135 > V_142 -> V_138 . V_135 ) {
F_11 ( & V_141 -> V_31 , & V_130 ) ;
return;
}
F_9 (m, &smk_netlbladdr_list, list) {
if ( F_26 ( & V_142 -> V_31 , & V_130 ) ) {
F_11 ( & V_141 -> V_31 , & V_142 -> V_31 ) ;
return;
}
V_143 = F_67 ( V_142 -> V_31 . V_80 ,
struct V_131 , V_31 ) ;
if ( V_141 -> V_138 . V_135 > V_143 -> V_138 . V_135 ) {
F_11 ( & V_141 -> V_31 , & V_142 -> V_31 ) ;
return;
}
}
}
static T_1 F_68 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
struct V_131 * V_49 ;
struct V_144 V_145 ;
char * V_146 ;
char * V_18 ;
char * V_51 ;
char * V_147 = ( char * ) & V_145 . V_134 . V_135 ;
int V_22 ;
struct V_4 V_148 ;
struct V_149 V_150 ;
unsigned int V_142 ;
int V_21 ;
T_5 V_151 = ( 1 << 31 ) ;
T_6 V_152 ;
T_5 V_137 ;
if ( ! F_38 ( V_85 ) )
return - V_86 ;
if ( * V_61 != 0 )
return - V_63 ;
if ( V_60 < V_153 )
return - V_63 ;
V_51 = F_10 ( V_60 + 1 , V_28 ) ;
if ( V_51 == NULL )
return - V_29 ;
if ( F_22 ( V_51 , V_59 , V_60 ) != 0 ) {
V_22 = - V_68 ;
goto V_154;
}
V_146 = F_10 ( V_60 + 1 , V_28 ) ;
if ( V_146 == NULL ) {
V_22 = - V_29 ;
goto V_154;
}
V_51 [ V_60 ] = '\0' ;
V_22 = sscanf ( V_51 , L_14 ,
& V_147 [ 0 ] , & V_147 [ 1 ] , & V_147 [ 2 ] , & V_147 [ 3 ] , & V_142 , V_146 ) ;
if ( V_22 != 6 ) {
V_22 = sscanf ( V_51 , L_15 ,
& V_147 [ 0 ] , & V_147 [ 1 ] , & V_147 [ 2 ] , & V_147 [ 3 ] , V_146 ) ;
if ( V_22 != 5 ) {
V_22 = - V_63 ;
goto V_155;
}
V_142 = V_156 ;
}
if ( V_142 > V_156 ) {
V_22 = - V_63 ;
goto V_155;
}
if ( V_146 [ 0 ] != '-' ) {
V_18 = F_15 ( V_146 , 0 ) ;
if ( V_18 == NULL ) {
V_22 = - V_63 ;
goto V_155;
}
} else {
if ( strcmp ( V_146 , V_157 ) == 0 )
V_18 = ( char * ) V_157 ;
else {
V_22 = - V_63 ;
goto V_155;
}
}
for ( V_137 = 0 ; V_142 > 0 ; V_142 -- ) {
V_137 |= V_151 ;
V_151 >>= 1 ;
}
V_150 . V_135 = F_69 ( V_137 ) ;
V_145 . V_134 . V_135 &= V_150 . V_135 ;
F_8 ( & V_158 ) ;
V_152 = V_145 . V_134 . V_135 ;
V_21 = 0 ;
F_9 (skp, &smk_netlbladdr_list, list) {
if ( V_49 -> V_133 . V_134 . V_135 == V_152 &&
V_49 -> V_138 . V_135 == V_150 . V_135 ) {
V_21 = 1 ;
break;
}
}
F_2 ( & V_148 ) ;
if ( V_21 == 0 ) {
V_49 = F_10 ( sizeof( * V_49 ) , V_28 ) ;
if ( V_49 == NULL )
V_22 = - V_29 ;
else {
V_22 = 0 ;
V_49 -> V_133 . V_134 . V_135 = V_145 . V_134 . V_135 ;
V_49 -> V_138 . V_135 = V_150 . V_135 ;
V_49 -> V_139 = V_18 ;
F_66 ( V_49 ) ;
}
} else {
if ( V_49 -> V_139 != V_157 )
V_22 = F_70 ( & V_159 , NULL ,
& V_49 -> V_133 . V_134 , & V_49 -> V_138 ,
V_90 , & V_148 ) ;
else
V_22 = 0 ;
V_49 -> V_139 = V_18 ;
}
if ( V_22 == 0 && V_18 != V_157 )
V_22 = F_71 ( & V_159 , NULL ,
& V_49 -> V_133 . V_134 , & V_49 -> V_138 , V_90 ,
F_5 ( V_49 -> V_139 ) , & V_148 ) ;
if ( V_22 == 0 )
V_22 = V_60 ;
F_12 ( & V_158 ) ;
V_155:
F_18 ( V_146 ) ;
V_154:
F_18 ( V_51 ) ;
return V_22 ;
}
static T_1 F_72 ( struct V_58 * V_160 , char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_161 [ 80 ] ;
T_1 V_22 ;
if ( * V_61 != 0 )
return 0 ;
sprintf ( V_161 , L_11 , V_96 ) ;
V_22 = F_73 ( V_59 , V_60 , V_61 , V_161 , strlen ( V_161 ) ) ;
return V_22 ;
}
static T_1 F_74 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_161 [ 80 ] ;
int V_112 ;
if ( ! F_38 ( V_85 ) )
return - V_86 ;
if ( V_60 >= sizeof( V_161 ) || V_60 == 0 )
return - V_63 ;
if ( F_22 ( V_161 , V_59 , V_60 ) != 0 )
return - V_68 ;
V_161 [ V_60 ] = '\0' ;
if ( sscanf ( V_161 , L_11 , & V_112 ) != 1 )
return - V_63 ;
V_96 = V_112 ;
F_39 () ;
return V_60 ;
}
static T_1 F_75 ( struct V_58 * V_160 , char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_161 [ 80 ] ;
T_1 V_22 ;
if ( * V_61 != 0 )
return 0 ;
sprintf ( V_161 , L_11 , V_162 ) ;
V_22 = F_73 ( V_59 , V_60 , V_61 , V_161 , strlen ( V_161 ) ) ;
return V_22 ;
}
static T_1 F_76 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
struct V_48 * V_49 ;
char V_161 [ 80 ] ;
int V_112 ;
if ( ! F_38 ( V_85 ) )
return - V_86 ;
if ( V_60 >= sizeof( V_161 ) || V_60 == 0 )
return - V_63 ;
if ( F_22 ( V_161 , V_59 , V_60 ) != 0 )
return - V_68 ;
V_161 [ V_60 ] = '\0' ;
if ( sscanf ( V_161 , L_11 , & V_112 ) != 1 )
return - V_63 ;
if ( V_162 != V_112 ) {
F_8 ( & V_163 ) ;
F_9 (skp, &smack_known_list, list)
if ( V_49 -> V_108 . V_109 . V_110 . V_113 ==
V_162 )
V_49 -> V_108 . V_109 . V_110 . V_113 = V_112 ;
V_162 = V_112 ;
F_12 ( & V_163 ) ;
}
return V_60 ;
}
static T_1 F_77 ( struct V_58 * V_160 , char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_161 [ 80 ] ;
T_1 V_22 ;
if ( * V_61 != 0 )
return 0 ;
sprintf ( V_161 , L_11 , V_164 ) ;
V_22 = F_73 ( V_59 , V_60 , V_61 , V_161 , strlen ( V_161 ) ) ;
return V_22 ;
}
static T_1 F_78 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
struct V_48 * V_49 ;
char V_161 [ 80 ] ;
int V_112 ;
if ( ! F_38 ( V_85 ) )
return - V_86 ;
if ( V_60 >= sizeof( V_161 ) || V_60 == 0 )
return - V_63 ;
if ( F_22 ( V_161 , V_59 , V_60 ) != 0 )
return - V_68 ;
V_161 [ V_60 ] = '\0' ;
if ( sscanf ( V_161 , L_11 , & V_112 ) != 1 )
return - V_63 ;
if ( V_164 != V_112 ) {
F_8 ( & V_163 ) ;
F_9 (skp, &smack_known_list, list)
if ( V_49 -> V_108 . V_109 . V_110 . V_113 ==
V_164 )
V_49 -> V_108 . V_109 . V_110 . V_113 = V_112 ;
V_164 = V_112 ;
F_12 ( & V_163 ) ;
}
return V_60 ;
}
static T_1 F_79 ( struct V_58 * V_160 , char T_2 * V_59 ,
T_3 V_165 , T_4 * V_61 )
{
T_1 V_22 ;
int V_166 ;
if ( * V_61 != 0 )
return 0 ;
F_8 ( & V_167 ) ;
V_166 = strlen ( V_103 ) + 1 ;
if ( V_165 >= V_166 )
V_22 = F_73 ( V_59 , V_165 , V_61 ,
V_103 , V_166 ) ;
else
V_22 = - V_63 ;
F_12 ( & V_167 ) ;
return V_22 ;
}
static T_1 F_80 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char * V_102 ;
char * V_146 = NULL ;
char * V_51 ;
int V_22 = V_60 ;
if ( ! F_38 ( V_85 ) )
return - V_86 ;
V_51 = F_10 ( V_60 + 1 , V_28 ) ;
if ( V_51 == NULL )
return - V_29 ;
if ( F_22 ( V_51 , V_59 , V_60 ) != 0 ) {
V_22 = - V_68 ;
goto V_30;
}
V_146 = F_15 ( V_51 , V_60 ) ;
if ( V_146 == NULL ) {
V_22 = - V_63 ;
goto V_30;
}
F_8 ( & V_167 ) ;
V_102 = V_103 ;
V_103 = V_146 ;
F_46 ( V_102 ) ;
F_12 ( & V_167 ) ;
V_30:
F_18 ( V_51 ) ;
return V_22 ;
}
static T_1 F_81 ( struct V_58 * V_160 , char T_2 * V_59 ,
T_3 V_165 , T_4 * V_61 )
{
char * V_146 = L_16 ;
T_1 V_22 = - V_63 ;
int V_166 ;
if ( * V_61 != 0 )
return 0 ;
if ( V_168 != NULL )
V_146 = V_168 ;
V_166 = strlen ( V_146 ) + 1 ;
if ( V_165 >= V_166 )
V_22 = F_73 ( V_59 , V_165 , V_61 , V_146 , V_166 ) ;
return V_22 ;
}
static T_1 F_82 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char * V_51 ;
char * V_18 = F_83 ( V_7 -> V_169 -> V_170 ) ;
int V_22 = V_60 ;
if ( ! F_38 ( V_85 ) )
return - V_86 ;
if ( V_168 != NULL && V_168 != V_18 )
return - V_86 ;
V_51 = F_10 ( V_60 , V_28 ) ;
if ( V_51 == NULL )
return - V_29 ;
if ( F_22 ( V_51 , V_59 , V_60 ) != 0 )
V_22 = - V_68 ;
else
V_168 = F_15 ( V_51 , V_60 ) ;
F_18 ( V_51 ) ;
return V_22 ;
}
static T_1 F_84 ( struct V_58 * V_160 , char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_161 [ 32 ] ;
T_1 V_22 ;
if ( * V_61 != 0 )
return 0 ;
sprintf ( V_161 , L_17 , V_171 ) ;
V_22 = F_73 ( V_59 , V_60 , V_61 , V_161 , strlen ( V_161 ) ) ;
return V_22 ;
}
static T_1 F_85 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_161 [ 32 ] ;
int V_112 ;
if ( ! F_38 ( V_85 ) )
return - V_86 ;
if ( V_60 >= sizeof( V_161 ) || V_60 == 0 )
return - V_63 ;
if ( F_22 ( V_161 , V_59 , V_60 ) != 0 )
return - V_68 ;
V_161 [ V_60 ] = '\0' ;
if ( sscanf ( V_161 , L_11 , & V_112 ) != 1 )
return - V_63 ;
if ( V_112 < 0 || V_112 > 3 )
return - V_63 ;
V_171 = V_112 ;
return V_60 ;
}
static void * F_86 ( struct V_74 * V_75 , T_4 * V_76 )
{
struct V_172 * V_173 = F_87 () ;
return F_23 ( V_75 , V_76 , & V_173 -> V_72 ) ;
}
static void * F_88 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 )
{
struct V_172 * V_173 = F_87 () ;
return F_25 ( V_75 , V_81 , V_76 , & V_173 -> V_72 ) ;
}
static int F_89 ( struct V_74 * V_75 , void * V_81 )
{
struct V_12 * V_31 = V_81 ;
struct V_17 * V_11 =
F_34 ( V_31 , struct V_17 , V_31 ) ;
F_28 ( V_75 , V_11 , V_52 ) ;
return 0 ;
}
static int F_90 ( struct V_83 * V_83 , struct V_58 * V_58 )
{
return F_36 ( V_58 , & V_174 ) ;
}
static T_1 F_91 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
struct V_172 * V_173 = F_87 () ;
return F_21 ( V_58 , V_59 , V_60 , V_61 , & V_173 -> V_72 ,
& V_173 -> V_73 , V_65 ) ;
}
static T_1 F_92 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 , int V_62 )
{
struct V_10 V_45 ;
char * V_51 ;
char * V_175 ;
int V_176 ;
V_51 = F_93 ( V_58 , V_59 , V_60 ) ;
if ( F_94 ( V_51 ) )
return F_95 ( V_51 ) ;
if ( V_62 == V_65 ) {
if ( V_60 < V_67 )
return - V_63 ;
V_176 = F_19 ( V_51 , & V_45 , 0 ) ;
} else {
V_175 = F_10 ( V_60 + 1 , V_28 ) ;
if ( V_175 == NULL )
return - V_29 ;
memcpy ( V_175 , V_51 , V_60 ) ;
V_175 [ V_60 ] = '\0' ;
V_176 = F_20 ( V_175 , & V_45 , 0 , 0 ) ;
F_18 ( V_175 ) ;
}
if ( V_176 )
return - V_63 ;
V_176 = V_25 ( V_45 . V_24 , V_45 . V_23 , V_45 . V_26 ,
NULL ) ;
V_51 [ 0 ] = V_176 == 0 ? '1' : '0' ;
V_51 [ 1 ] = '\0' ;
F_96 ( V_58 , 2 ) ;
if ( V_62 == V_65 )
return V_67 ;
return V_60 ;
}
static T_1 F_97 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
return F_92 ( V_58 , V_59 , V_60 , V_61 , V_65 ) ;
}
static int F_98 ( struct V_74 * V_75 , void * V_81 )
{
struct V_12 * V_31 = V_81 ;
struct V_19 * V_20 =
F_34 ( V_31 , struct V_19 , V_31 ) ;
F_28 ( V_75 , V_20 -> V_32 , V_177 ) ;
return 0 ;
}
static int F_99 ( struct V_83 * V_83 , struct V_58 * V_58 )
{
return F_36 ( V_58 , & V_178 ) ;
}
static T_1 F_100 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
if ( ! F_38 ( V_85 ) )
return - V_86 ;
return F_21 ( V_58 , V_59 , V_60 , V_61 , NULL , NULL ,
V_69 ) ;
}
static void * F_101 ( struct V_74 * V_75 , T_4 * V_76 )
{
struct V_172 * V_173 = F_87 () ;
return F_23 ( V_75 , V_76 , & V_173 -> V_72 ) ;
}
static void * F_102 ( struct V_74 * V_75 , void * V_81 , T_4 * V_76 )
{
struct V_172 * V_173 = F_87 () ;
return F_25 ( V_75 , V_81 , V_76 , & V_173 -> V_72 ) ;
}
static int F_103 ( struct V_74 * V_75 , void * V_81 )
{
struct V_12 * V_31 = V_81 ;
struct V_17 * V_11 =
F_34 ( V_31 , struct V_17 , V_31 ) ;
F_28 ( V_75 , V_11 , V_177 ) ;
return 0 ;
}
static int F_104 ( struct V_83 * V_83 , struct V_58 * V_58 )
{
return F_36 ( V_58 , & V_179 ) ;
}
static T_1 F_105 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
struct V_172 * V_173 = F_87 () ;
return F_21 ( V_58 , V_59 , V_60 , V_61 , & V_173 -> V_72 ,
& V_173 -> V_73 , V_69 ) ;
}
static T_1 F_106 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
return F_92 ( V_58 , V_59 , V_60 , V_61 , V_69 ) ;
}
static T_1 F_107 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char * V_51 = NULL ;
const char * V_35 = NULL ;
struct V_48 * V_49 ;
struct V_17 * V_18 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_22 = V_60 ;
if ( * V_61 != 0 )
return - V_63 ;
if ( ! F_38 ( V_85 ) )
return - V_86 ;
if ( V_60 == 0 || V_60 > V_177 )
return - V_63 ;
V_51 = F_10 ( V_60 , V_28 ) ;
if ( V_51 == NULL )
return - V_29 ;
if ( F_22 ( V_51 , V_59 , V_60 ) != 0 ) {
V_22 = - V_68 ;
goto V_155;
}
V_35 = F_16 ( V_51 , V_60 ) ;
if ( V_35 == NULL ) {
V_22 = - V_63 ;
goto V_155;
}
V_49 = F_17 ( V_35 ) ;
if ( V_49 == NULL )
goto V_155;
V_13 = & V_49 -> V_72 ;
V_15 = & V_49 -> V_73 ;
F_8 ( V_15 ) ;
F_9 (sp, rule_list, list)
V_18 -> V_25 = 0 ;
F_12 ( V_15 ) ;
V_155:
F_18 ( V_51 ) ;
F_18 ( V_35 ) ;
return V_22 ;
}
static int F_108 ( void )
{
V_180 = F_109 ( L_18 , NULL , V_181 ) ;
if ( ! V_180 )
return - V_29 ;
return 0 ;
}
static T_1 F_110 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
if ( ! F_111 ( V_85 ) )
return - V_86 ;
return F_21 ( V_58 , V_59 , V_60 , V_61 , NULL , NULL ,
V_71 ) ;
}
static int F_112 ( struct V_182 * V_183 , void * V_51 , int V_184 )
{
int V_22 ;
struct V_83 * V_185 ;
static struct V_186 V_187 [] = {
[ V_188 ] = {
L_19 , & V_189 , V_190 | V_191 } ,
[ V_192 ] = {
L_20 , & V_193 , V_190 | V_191 } ,
[ V_194 ] = {
L_21 , & V_195 , V_190 | V_191 } ,
[ V_196 ] = {
L_22 , & V_197 , V_190 | V_191 } ,
[ V_198 ] = {
L_23 , & V_199 , V_190 | V_191 } ,
[ V_200 ] = {
L_24 , & V_201 , V_190 | V_191 } ,
[ V_202 ] = {
L_25 , & V_203 , V_190 | V_191 } ,
[ V_204 ] = {
L_26 , & V_205 , V_190 | V_191 } ,
[ V_206 ] = {
L_27 , & V_207 , V_190 | V_208 } ,
[ V_209 ] = {
L_28 , & V_210 , V_190 | V_208 } ,
[ V_211 ] = {
L_29 , & V_212 , V_190 | V_191 } ,
[ V_213 ] = {
L_30 , & V_214 , V_190 | V_191 } ,
[ V_215 ] = {
L_31 , & V_216 , V_190 | V_208 } ,
[ V_217 ] = {
L_32 , & V_218 , V_190 | V_208 } ,
[ V_219 ] = {
L_33 , & V_220 , V_190 | V_191 } ,
[ V_221 ] = {
L_34 , & V_222 ,
V_190 | V_191 } ,
[ V_223 ] = {
L_35 , & V_224 , V_190 | V_191 } ,
{ L_16 }
} ;
V_22 = F_113 ( V_183 , V_225 , V_187 ) ;
if ( V_22 != 0 ) {
F_41 ( V_226 L_36 ,
V_92 , V_22 ) ;
return V_22 ;
}
V_185 = V_183 -> V_227 -> V_228 ;
return 0 ;
}
static struct V_229 * F_114 ( struct V_230 * V_231 ,
int V_232 , const char * V_233 , void * V_51 )
{
return F_115 ( V_231 , V_232 , V_51 , F_112 ) ;
}
static int T_7 F_116 ( struct V_48 * V_49 )
{
V_49 -> V_108 . V_234 = V_49 -> V_50 ;
V_49 -> V_108 . V_232 =
V_235 | V_236 ;
return F_55 ( V_162 , V_49 -> V_50 ,
& V_49 -> V_108 , strlen ( V_49 -> V_50 ) ) ;
}
static int T_7 F_117 ( void )
{
int V_237 ;
int V_22 ;
if ( ! F_118 ( & V_238 ) )
return 0 ;
V_237 = F_108 () ;
if ( V_237 )
F_41 ( V_226 L_37 ) ;
V_237 = F_119 ( & V_239 ) ;
if ( ! V_237 ) {
V_240 = F_120 ( & V_239 ) ;
if ( F_94 ( V_240 ) ) {
F_41 ( V_226 L_38 ) ;
V_237 = F_95 ( V_240 ) ;
V_240 = NULL ;
}
}
F_39 () ;
F_46 ( NULL ) ;
V_22 = F_116 ( & V_104 ) ;
if ( V_237 == 0 && V_22 < 0 )
V_237 = V_22 ;
V_22 = F_116 ( & V_241 ) ;
if ( V_237 == 0 && V_22 < 0 )
V_237 = V_22 ;
V_22 = F_116 ( & V_242 ) ;
if ( V_237 == 0 && V_22 < 0 )
V_237 = V_22 ;
V_22 = F_116 ( & V_243 ) ;
if ( V_237 == 0 && V_22 < 0 )
V_237 = V_22 ;
V_22 = F_116 ( & V_244 ) ;
if ( V_237 == 0 && V_22 < 0 )
V_237 = V_22 ;
V_22 = F_116 ( & V_245 ) ;
if ( V_237 == 0 && V_22 < 0 )
V_237 = V_22 ;
return V_237 ;
}
