static inline void F_1 ( unsigned int V_1 , char * V_2 )
{
if ( V_1 == 0 || V_1 > ( V_3 * 8 ) )
return;
V_2 [ ( V_1 - 1 ) / 8 ] |= 0x80 >> ( ( V_1 - 1 ) % 8 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 () ;
V_5 -> V_8 = F_4 ( V_9 ) ;
V_5 -> V_10 = F_5 ( V_9 ) ;
V_5 -> V_11 = V_7 -> V_12 ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_18 , int V_19 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 = 0 ;
int V_25 = 0 ;
F_7 ( V_18 ) ;
F_8 (sp, rule_list, list) {
if ( V_21 -> V_26 == V_14 -> V_26 &&
V_21 -> V_27 == V_14 -> V_27 ) {
V_24 = 1 ;
V_21 -> V_28 |= V_14 -> V_29 ;
V_21 -> V_28 &= ~ V_14 -> V_30 ;
break;
}
}
if ( V_24 == 0 ) {
V_21 = F_9 ( sizeof( * V_21 ) , V_31 ) ;
if ( V_21 == NULL ) {
V_25 = - V_32 ;
goto V_33;
}
V_21 -> V_27 = V_14 -> V_27 ;
V_21 -> V_26 = V_14 -> V_26 ;
V_21 -> V_28 = V_14 -> V_29 & ~ V_14 -> V_30 ;
F_10 ( & V_21 -> V_34 , V_16 ) ;
if ( V_19 ) {
V_23 = F_9 ( sizeof( * V_23 ) , V_31 ) ;
if ( V_23 != NULL ) {
V_23 -> V_35 = V_21 ;
F_10 ( & V_23 -> V_34 , & V_36 ) ;
} else
V_25 = - V_32 ;
}
}
V_33:
F_11 ( V_18 ) ;
return V_25 ;
}
static int F_12 ( const char * string )
{
int V_37 = 0 ;
const char * V_38 ;
for ( V_38 = string ; ; V_38 ++ )
switch ( * V_38 ) {
case '-' :
break;
case 'r' :
case 'R' :
V_37 |= V_39 ;
break;
case 'w' :
case 'W' :
V_37 |= V_40 ;
break;
case 'x' :
case 'X' :
V_37 |= V_41 ;
break;
case 'a' :
case 'A' :
V_37 |= V_42 ;
break;
case 't' :
case 'T' :
V_37 |= V_43 ;
break;
default:
return V_37 ;
}
}
static int F_13 ( const char * V_44 , const char * V_45 ,
const char * V_46 , const char * V_47 ,
struct V_13 * V_48 , int V_49 ,
int V_50 )
{
const char * V_38 ;
struct V_6 * V_7 ;
if ( V_49 ) {
V_48 -> V_27 = F_14 ( V_44 , V_50 ) ;
if ( V_48 -> V_27 == NULL )
return - 1 ;
V_48 -> V_26 = F_15 ( V_45 , V_50 ) ;
if ( V_48 -> V_26 == NULL )
return - 1 ;
} else {
V_38 = F_16 ( V_44 , V_50 ) ;
if ( V_38 == NULL )
return - 1 ;
V_7 = F_17 ( V_38 ) ;
F_18 ( V_38 ) ;
if ( V_7 == NULL )
return - 1 ;
V_48 -> V_27 = V_7 ;
V_38 = F_16 ( V_45 , V_50 ) ;
if ( V_38 == NULL )
return - 1 ;
V_7 = F_17 ( V_38 ) ;
F_18 ( V_38 ) ;
if ( V_7 == NULL )
return - 1 ;
V_48 -> V_26 = V_7 -> V_51 ;
}
V_48 -> V_29 = F_12 ( V_46 ) ;
if ( V_47 )
V_48 -> V_30 = F_12 ( V_47 ) ;
else
V_48 -> V_30 = ~ V_48 -> V_29 ;
return 0 ;
}
static int F_19 ( const char * V_52 , struct V_13 * V_48 ,
int V_49 )
{
int V_25 ;
V_25 = F_13 ( V_52 , V_52 + V_53 ,
V_52 + V_53 + V_53 , NULL , V_48 ,
V_49 , V_53 ) ;
return V_25 ;
}
static T_1 F_20 ( char * V_52 , struct V_13 * V_48 ,
int V_49 , int V_54 )
{
T_1 V_55 = 0 ;
char * V_56 [ 4 ] ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_54 ; ++ V_57 ) {
while ( isspace ( V_52 [ V_55 ] ) )
V_52 [ V_55 ++ ] = '\0' ;
if ( V_52 [ V_55 ] == '\0' )
return - 1 ;
V_56 [ V_57 ] = V_52 + V_55 ;
while ( V_52 [ V_55 ] && ! isspace ( V_52 [ V_55 ] ) )
++ V_55 ;
}
while ( isspace ( V_52 [ V_55 ] ) )
V_52 [ V_55 ++ ] = '\0' ;
while ( V_57 < 4 )
V_56 [ V_57 ++ ] = NULL ;
if ( F_13 ( V_56 [ 0 ] , V_56 [ 1 ] , V_56 [ 2 ] , V_56 [ 3 ] , V_48 , V_49 , 0 ) )
return - 1 ;
return V_55 ;
}
static T_1 F_21 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 ,
struct V_15 * V_16 ,
struct V_17 * V_18 , int V_62 )
{
struct V_13 V_48 ;
char * V_52 ;
int V_25 ;
int V_63 = 0 ;
int V_54 ;
T_1 V_55 = 0 ;
if ( * V_61 != 0 )
return - V_64 ;
if ( V_62 == V_65 ) {
if ( V_60 != V_66 && V_60 != V_67 )
return - V_64 ;
} else {
if ( V_60 >= V_68 ) {
V_60 = V_68 - 1 ;
V_63 = 1 ;
}
}
V_52 = F_22 ( V_60 + 1 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_23 ( V_52 , V_59 , V_60 ) != 0 ) {
V_25 = - V_69 ;
goto V_33;
}
if ( V_63 ) {
while ( V_60 > 0 && ( V_52 [ V_60 - 1 ] != '\n' ) )
-- V_60 ;
if ( V_60 == 0 ) {
V_25 = - V_64 ;
goto V_33;
}
}
V_52 [ V_60 ] = '\0' ;
V_54 = ( V_62 == V_70 ? 4 : 3 ) ;
while ( V_55 < V_60 ) {
if ( V_62 == V_65 ) {
V_25 = F_19 ( V_52 , & V_48 , 1 ) ;
if ( V_25 != 0 ) {
V_25 = - V_64 ;
goto V_33;
}
V_55 = V_60 ;
} else {
V_25 = F_20 ( V_52 + V_55 , & V_48 , 1 , V_54 ) ;
if ( V_25 <= 0 ) {
V_25 = - V_64 ;
goto V_33;
}
V_55 += V_25 ;
}
if ( V_16 == NULL )
V_25 = F_6 ( & V_48 , & V_48 . V_27 -> V_71 ,
& V_48 . V_27 -> V_72 , 1 ) ;
else
V_25 = F_6 ( & V_48 , V_16 , V_18 , 0 ) ;
if ( V_25 )
goto V_33;
}
V_25 = V_55 ;
V_33:
F_18 ( V_52 ) ;
return V_25 ;
}
static void * F_24 ( struct V_73 * V_74 , T_4 * V_75 ,
struct V_15 * V_76 )
{
struct V_15 * V_34 ;
if ( V_74 -> V_77 == 0 )
V_74 -> V_78 = V_76 ;
if ( V_74 -> V_78 == NULL )
return NULL ;
V_34 = V_74 -> V_78 ;
if ( F_25 ( V_34 ) )
return NULL ;
if ( V_74 -> V_77 == 0 )
return V_34 -> V_79 ;
return V_34 ;
}
static void * F_26 ( struct V_73 * V_74 , void * V_80 , T_4 * V_75 ,
struct V_15 * V_76 )
{
struct V_15 * V_34 = V_80 ;
if ( F_27 ( V_34 , V_76 ) ) {
V_74 -> V_78 = NULL ;
return NULL ;
}
V_74 -> V_78 = V_34 -> V_79 ;
return V_34 -> V_79 ;
}
static void F_28 ( struct V_73 * V_74 , void * V_80 )
{
}
static void F_29 ( struct V_73 * V_74 , struct V_20 * V_14 , int V_81 )
{
if ( strlen ( V_14 -> V_27 -> V_51 ) >= V_81 ||
strlen ( V_14 -> V_26 ) >= V_81 )
return;
if ( V_14 -> V_28 == 0 )
return;
F_30 ( V_74 , L_1 , V_14 -> V_27 -> V_51 , V_14 -> V_26 ) ;
F_31 ( V_74 , ' ' ) ;
if ( V_14 -> V_28 & V_39 )
F_31 ( V_74 , 'r' ) ;
if ( V_14 -> V_28 & V_40 )
F_31 ( V_74 , 'w' ) ;
if ( V_14 -> V_28 & V_41 )
F_31 ( V_74 , 'x' ) ;
if ( V_14 -> V_28 & V_42 )
F_31 ( V_74 , 'a' ) ;
if ( V_14 -> V_28 & V_43 )
F_31 ( V_74 , 't' ) ;
F_31 ( V_74 , '\n' ) ;
}
static void * F_32 ( struct V_73 * V_74 , T_4 * V_75 )
{
return F_24 ( V_74 , V_75 , & V_36 ) ;
}
static void * F_33 ( struct V_73 * V_74 , void * V_80 , T_4 * V_75 )
{
return F_26 ( V_74 , V_80 , V_75 , & V_36 ) ;
}
static int F_34 ( struct V_73 * V_74 , void * V_80 )
{
struct V_15 * V_34 = V_80 ;
struct V_22 * V_23 =
F_35 ( V_34 , struct V_22 , V_34 ) ;
F_29 ( V_74 , V_23 -> V_35 , V_53 ) ;
return 0 ;
}
static int F_36 ( struct V_82 * V_82 , struct V_58 * V_58 )
{
return F_37 ( V_58 , & V_83 ) ;
}
static T_1 F_38 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
if ( ! F_39 ( V_84 ) )
return - V_85 ;
return F_21 ( V_58 , V_59 , V_60 , V_61 , NULL , NULL ,
V_65 ) ;
}
static void F_40 ( void )
{
int V_25 ;
struct V_86 * V_87 ;
struct V_4 V_88 ;
F_2 ( & V_88 ) ;
V_25 = F_41 ( NULL , V_89 , NULL , NULL , & V_88 ) ;
if ( V_25 != 0 )
F_42 ( V_90 L_2 ,
V_91 , __LINE__ , V_25 ) ;
V_87 = F_22 ( sizeof( struct V_86 ) , V_31 ) ;
if ( V_87 == NULL )
F_43 ( L_3 ) ;
V_87 -> V_92 . V_93 = NULL ;
V_87 -> V_94 = V_95 ;
V_87 -> type = V_96 ;
V_87 -> V_97 [ 0 ] = V_98 ;
for ( V_25 = 1 ; V_25 < V_99 ; V_25 ++ )
V_87 -> V_97 [ V_25 ] = V_100 ;
V_25 = F_44 ( V_87 , & V_88 ) ;
if ( V_25 != 0 ) {
F_42 ( V_90 L_4 ,
V_91 , __LINE__ , V_25 ) ;
F_18 ( V_87 ) ;
return;
}
V_25 = F_45 ( V_87 -> V_94 , NULL , NULL , NULL , & V_88 ) ;
if ( V_25 != 0 ) {
F_42 ( V_90 L_5 ,
V_91 , __LINE__ , V_25 ) ;
F_18 ( V_87 ) ;
return;
}
}
static void F_46 ( char * V_101 )
{
int V_25 ;
struct V_4 V_88 ;
F_2 ( & V_88 ) ;
if ( V_101 != NULL ) {
V_25 = F_41 ( V_101 , V_89 , NULL , NULL , & V_88 ) ;
if ( V_25 != 0 )
F_42 ( V_90 L_2 ,
V_91 , __LINE__ , V_25 ) ;
}
if ( V_102 == NULL )
V_102 = & V_103 ;
V_25 = F_47 ( V_102 -> V_51 , V_89 ,
NULL , NULL , & V_88 ) ;
if ( V_25 != 0 )
F_42 ( V_90 L_6 ,
V_91 , __LINE__ , V_25 ) ;
}
static void * F_48 ( struct V_73 * V_74 , T_4 * V_75 )
{
return F_24 ( V_74 , V_75 , & V_104 ) ;
}
static void * F_49 ( struct V_73 * V_74 , void * V_80 , T_4 * V_75 )
{
return F_26 ( V_74 , V_80 , V_75 , & V_104 ) ;
}
static int F_50 ( struct V_73 * V_74 , void * V_80 )
{
struct V_15 * V_34 = V_80 ;
struct V_6 * V_7 =
F_35 ( V_34 , struct V_6 , V_34 ) ;
struct V_105 * V_106 = V_7 -> V_107 . V_108 . V_109 . V_1 ;
char V_110 = '/' ;
int V_57 ;
if ( strlen ( V_7 -> V_51 ) >= V_53 )
return 0 ;
F_30 ( V_74 , L_7 , V_7 -> V_51 , V_7 -> V_107 . V_108 . V_109 . V_111 ) ;
for ( V_57 = F_51 ( V_106 , 0 ) ; V_57 >= 0 ;
V_57 = F_51 ( V_106 , V_57 + 1 ) ) {
F_30 ( V_74 , L_8 , V_110 , V_57 ) ;
V_110 = ',' ;
}
F_31 ( V_74 , '\n' ) ;
return 0 ;
}
static int F_52 ( struct V_82 * V_82 , struct V_58 * V_58 )
{
return F_37 ( V_58 , & V_112 ) ;
}
static T_1 F_53 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 , int V_62 )
{
struct V_6 * V_7 ;
struct V_113 V_114 ;
char V_115 [ V_3 ] ;
int V_116 ;
unsigned int V_1 ;
int V_117 ;
T_1 V_25 = - V_64 ;
char * V_52 = NULL ;
char * V_48 ;
int V_118 ;
int V_57 ;
if ( ! F_39 ( V_84 ) )
return - V_85 ;
if ( * V_61 != 0 )
return - V_64 ;
if ( V_62 == V_65 &&
( V_60 < V_119 || V_60 > V_120 ) )
return - V_64 ;
V_52 = F_9 ( V_60 + 1 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_23 ( V_52 , V_59 , V_60 ) != 0 ) {
V_25 = - V_69 ;
goto V_121;
}
V_52 [ V_60 ] = '\0' ;
V_48 = V_52 ;
F_7 ( & V_122 ) ;
V_7 = F_14 ( V_48 , 0 ) ;
if ( V_7 == NULL )
goto V_33;
if ( V_62 == V_65 )
V_48 += V_53 ;
else
V_48 += strlen ( V_7 -> V_51 ) + 1 ;
V_118 = sscanf ( V_48 , L_9 , & V_116 ) ;
if ( V_118 != 1 || V_116 > V_123 )
goto V_33;
V_48 += V_124 ;
V_118 = sscanf ( V_48 , L_9 , & V_117 ) ;
if ( V_118 != 1 || V_117 > V_125 )
goto V_33;
if ( V_62 == V_65 &&
V_60 != ( V_119 + V_117 * V_124 ) )
goto V_33;
memset ( V_115 , 0 , sizeof( V_115 ) ) ;
for ( V_57 = 0 ; V_57 < V_117 ; V_57 ++ ) {
V_48 += V_124 ;
V_118 = sscanf ( V_48 , L_10 , & V_1 ) ;
if ( V_118 != 1 || V_1 > V_125 )
goto V_33;
F_1 ( V_1 , V_115 ) ;
}
V_25 = F_54 ( V_116 , V_115 , & V_114 , V_3 ) ;
if ( V_25 >= 0 ) {
F_55 ( V_7 -> V_107 . V_108 . V_109 . V_1 ) ;
V_7 -> V_107 . V_108 . V_109 . V_1 = V_114 . V_108 . V_109 . V_1 ;
V_7 -> V_107 . V_108 . V_109 . V_111 = V_114 . V_108 . V_109 . V_111 ;
V_25 = V_60 ;
}
V_33:
F_11 ( & V_122 ) ;
V_121:
F_18 ( V_52 ) ;
return V_25 ;
}
static T_1 F_56 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
return F_53 ( V_58 , V_59 , V_60 , V_61 , V_65 ) ;
}
static int F_57 ( struct V_73 * V_74 , void * V_80 )
{
struct V_15 * V_34 = V_80 ;
struct V_6 * V_7 =
F_35 ( V_34 , struct V_6 , V_34 ) ;
struct V_105 * V_106 = V_7 -> V_107 . V_108 . V_109 . V_1 ;
char V_110 = '/' ;
int V_57 ;
F_30 ( V_74 , L_7 , V_7 -> V_51 , V_7 -> V_107 . V_108 . V_109 . V_111 ) ;
for ( V_57 = F_51 ( V_106 , 0 ) ; V_57 >= 0 ;
V_57 = F_51 ( V_106 , V_57 + 1 ) ) {
F_30 ( V_74 , L_8 , V_110 , V_57 ) ;
V_110 = ',' ;
}
F_31 ( V_74 , '\n' ) ;
return 0 ;
}
static int F_58 ( struct V_82 * V_82 , struct V_58 * V_58 )
{
return F_37 ( V_58 , & V_126 ) ;
}
static T_1 F_59 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
return F_53 ( V_58 , V_59 , V_60 , V_61 , V_127 ) ;
}
static void * F_60 ( struct V_73 * V_74 , T_4 * V_75 )
{
return F_24 ( V_74 , V_75 , & V_128 ) ;
}
static void * F_61 ( struct V_73 * V_74 , void * V_80 , T_4 * V_75 )
{
return F_26 ( V_74 , V_80 , V_75 , & V_128 ) ;
}
static int F_62 ( struct V_73 * V_74 , void * V_80 )
{
struct V_15 * V_34 = V_80 ;
struct V_129 * V_7 =
F_35 ( V_34 , struct V_129 , V_34 ) ;
unsigned char * V_130 = ( char * ) & V_7 -> V_131 . V_132 . V_133 ;
int V_134 ;
T_5 V_135 = F_63 ( V_7 -> V_136 . V_133 ) ;
for ( V_134 = 0 ; V_135 ; V_135 <<= 1 , V_134 ++ ) ;
F_30 ( V_74 , L_11 ,
V_130 [ 0 ] , V_130 [ 1 ] , V_130 [ 2 ] , V_130 [ 3 ] , V_134 , V_7 -> V_137 ) ;
return 0 ;
}
static int F_64 ( struct V_82 * V_82 , struct V_58 * V_58 )
{
return F_37 ( V_58 , & V_138 ) ;
}
static void F_65 ( struct V_129 * V_139 )
{
struct V_129 * V_140 , * V_141 ;
if ( F_25 ( & V_128 ) ) {
F_10 ( & V_139 -> V_34 , & V_128 ) ;
return;
}
V_140 = F_66 ( V_128 . V_79 ,
struct V_129 , V_34 ) ;
if ( V_139 -> V_136 . V_133 > V_140 -> V_136 . V_133 ) {
F_10 ( & V_139 -> V_34 , & V_128 ) ;
return;
}
F_8 (m, &smk_netlbladdr_list, list) {
if ( F_27 ( & V_140 -> V_34 , & V_128 ) ) {
F_10 ( & V_139 -> V_34 , & V_140 -> V_34 ) ;
return;
}
V_141 = F_66 ( V_140 -> V_34 . V_79 ,
struct V_129 , V_34 ) ;
if ( V_139 -> V_136 . V_133 > V_141 -> V_136 . V_133 ) {
F_10 ( & V_139 -> V_34 , & V_140 -> V_34 ) ;
return;
}
}
}
static T_1 F_67 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
struct V_129 * V_7 ;
struct V_142 V_143 ;
char * V_144 ;
char * V_21 ;
char * V_52 ;
char * V_145 = ( char * ) & V_143 . V_132 . V_133 ;
int V_25 ;
struct V_4 V_146 ;
struct V_147 V_148 ;
unsigned int V_140 ;
int V_24 ;
T_5 V_149 = ( 1 << 31 ) ;
T_6 V_150 ;
T_5 V_135 ;
if ( ! F_39 ( V_84 ) )
return - V_85 ;
if ( * V_61 != 0 )
return - V_64 ;
if ( V_60 < V_151 )
return - V_64 ;
V_52 = F_9 ( V_60 + 1 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_23 ( V_52 , V_59 , V_60 ) != 0 ) {
V_25 = - V_69 ;
goto V_152;
}
V_144 = F_9 ( V_60 + 1 , V_31 ) ;
if ( V_144 == NULL ) {
V_25 = - V_32 ;
goto V_152;
}
V_52 [ V_60 ] = '\0' ;
V_25 = sscanf ( V_52 , L_12 ,
& V_145 [ 0 ] , & V_145 [ 1 ] , & V_145 [ 2 ] , & V_145 [ 3 ] , & V_140 , V_144 ) ;
if ( V_25 != 6 ) {
V_25 = sscanf ( V_52 , L_13 ,
& V_145 [ 0 ] , & V_145 [ 1 ] , & V_145 [ 2 ] , & V_145 [ 3 ] , V_144 ) ;
if ( V_25 != 5 ) {
V_25 = - V_64 ;
goto V_153;
}
V_140 = V_154 ;
}
if ( V_140 > V_154 ) {
V_25 = - V_64 ;
goto V_153;
}
if ( V_144 [ 0 ] != '-' ) {
V_21 = F_15 ( V_144 , 0 ) ;
if ( V_21 == NULL ) {
V_25 = - V_64 ;
goto V_153;
}
} else {
if ( strcmp ( V_144 , V_155 ) == 0 )
V_21 = ( char * ) V_155 ;
else {
V_25 = - V_64 ;
goto V_153;
}
}
for ( V_135 = 0 ; V_140 > 0 ; V_140 -- ) {
V_135 |= V_149 ;
V_149 >>= 1 ;
}
V_148 . V_133 = F_68 ( V_135 ) ;
V_143 . V_132 . V_133 &= V_148 . V_133 ;
F_7 ( & V_156 ) ;
V_150 = V_143 . V_132 . V_133 ;
V_24 = 0 ;
F_8 (skp, &smk_netlbladdr_list, list) {
if ( V_7 -> V_131 . V_132 . V_133 == V_150 &&
V_7 -> V_136 . V_133 == V_148 . V_133 ) {
V_24 = 1 ;
break;
}
}
F_2 ( & V_146 ) ;
if ( V_24 == 0 ) {
V_7 = F_9 ( sizeof( * V_7 ) , V_31 ) ;
if ( V_7 == NULL )
V_25 = - V_32 ;
else {
V_25 = 0 ;
V_7 -> V_131 . V_132 . V_133 = V_143 . V_132 . V_133 ;
V_7 -> V_136 . V_133 = V_148 . V_133 ;
V_7 -> V_137 = V_21 ;
F_65 ( V_7 ) ;
}
} else {
if ( V_7 -> V_137 != V_155 )
V_25 = F_69 ( & V_157 , NULL ,
& V_7 -> V_131 . V_132 , & V_7 -> V_136 ,
V_89 , & V_146 ) ;
else
V_25 = 0 ;
V_7 -> V_137 = V_21 ;
}
if ( V_25 == 0 && V_21 != V_155 )
V_25 = F_70 ( & V_157 , NULL ,
& V_7 -> V_131 . V_132 , & V_7 -> V_136 , V_89 ,
F_71 ( V_7 -> V_137 ) , & V_146 ) ;
if ( V_25 == 0 )
V_25 = V_60 ;
F_11 ( & V_156 ) ;
V_153:
F_18 ( V_144 ) ;
V_152:
F_18 ( V_52 ) ;
return V_25 ;
}
static T_1 F_72 ( struct V_58 * V_158 , char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_159 [ 80 ] ;
T_1 V_25 ;
if ( * V_61 != 0 )
return 0 ;
sprintf ( V_159 , L_9 , V_95 ) ;
V_25 = F_73 ( V_59 , V_60 , V_61 , V_159 , strlen ( V_159 ) ) ;
return V_25 ;
}
static T_1 F_74 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_159 [ 80 ] ;
int V_57 ;
if ( ! F_39 ( V_84 ) )
return - V_85 ;
if ( V_60 >= sizeof( V_159 ) || V_60 == 0 )
return - V_64 ;
if ( F_23 ( V_159 , V_59 , V_60 ) != 0 )
return - V_69 ;
V_159 [ V_60 ] = '\0' ;
if ( sscanf ( V_159 , L_9 , & V_57 ) != 1 )
return - V_64 ;
V_95 = V_57 ;
F_40 () ;
return V_60 ;
}
static T_1 F_75 ( struct V_58 * V_158 , char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_159 [ 80 ] ;
T_1 V_25 ;
if ( * V_61 != 0 )
return 0 ;
sprintf ( V_159 , L_9 , V_160 ) ;
V_25 = F_73 ( V_59 , V_60 , V_61 , V_159 , strlen ( V_159 ) ) ;
return V_25 ;
}
static T_1 F_76 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
struct V_6 * V_7 ;
char V_159 [ 80 ] ;
int V_57 ;
if ( ! F_39 ( V_84 ) )
return - V_85 ;
if ( V_60 >= sizeof( V_159 ) || V_60 == 0 )
return - V_64 ;
if ( F_23 ( V_159 , V_59 , V_60 ) != 0 )
return - V_69 ;
V_159 [ V_60 ] = '\0' ;
if ( sscanf ( V_159 , L_9 , & V_57 ) != 1 )
return - V_64 ;
if ( V_160 != V_57 ) {
F_7 ( & V_161 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_107 . V_108 . V_109 . V_111 ==
V_160 )
V_7 -> V_107 . V_108 . V_109 . V_111 = V_57 ;
V_160 = V_57 ;
F_11 ( & V_161 ) ;
}
return V_60 ;
}
static T_1 F_77 ( struct V_58 * V_158 , char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_159 [ 80 ] ;
T_1 V_25 ;
if ( * V_61 != 0 )
return 0 ;
sprintf ( V_159 , L_9 , V_162 ) ;
V_25 = F_73 ( V_59 , V_60 , V_61 , V_159 , strlen ( V_159 ) ) ;
return V_25 ;
}
static T_1 F_78 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
struct V_6 * V_7 ;
char V_159 [ 80 ] ;
int V_57 ;
if ( ! F_39 ( V_84 ) )
return - V_85 ;
if ( V_60 >= sizeof( V_159 ) || V_60 == 0 )
return - V_64 ;
if ( F_23 ( V_159 , V_59 , V_60 ) != 0 )
return - V_69 ;
V_159 [ V_60 ] = '\0' ;
if ( sscanf ( V_159 , L_9 , & V_57 ) != 1 )
return - V_64 ;
if ( V_162 != V_57 ) {
F_7 ( & V_161 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_107 . V_108 . V_109 . V_111 ==
V_162 )
V_7 -> V_107 . V_108 . V_109 . V_111 = V_57 ;
V_162 = V_57 ;
F_11 ( & V_161 ) ;
}
return V_60 ;
}
static T_1 F_79 ( struct V_58 * V_158 , char T_2 * V_59 ,
T_3 V_163 , T_4 * V_61 )
{
T_1 V_25 ;
int V_164 ;
if ( * V_61 != 0 )
return 0 ;
F_7 ( & V_165 ) ;
V_164 = strlen ( V_102 -> V_51 ) + 1 ;
if ( V_163 >= V_164 )
V_25 = F_73 ( V_59 , V_163 , V_61 ,
V_102 -> V_51 ,
V_164 ) ;
else
V_25 = - V_64 ;
F_11 ( & V_165 ) ;
return V_25 ;
}
static T_1 F_80 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
struct V_6 * V_7 ;
char * V_101 ;
char * V_52 ;
int V_25 = V_60 ;
if ( ! F_39 ( V_84 ) )
return - V_85 ;
V_52 = F_9 ( V_60 + 1 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_23 ( V_52 , V_59 , V_60 ) != 0 ) {
V_25 = - V_69 ;
goto V_33;
}
V_7 = F_14 ( V_52 , V_60 ) ;
if ( V_7 == NULL ) {
V_25 = - V_64 ;
goto V_33;
}
F_7 ( & V_165 ) ;
V_101 = V_102 -> V_51 ;
V_102 = V_7 ;
F_46 ( V_101 ) ;
F_11 ( & V_165 ) ;
V_33:
F_18 ( V_52 ) ;
return V_25 ;
}
static T_1 F_81 ( struct V_58 * V_158 , char T_2 * V_59 ,
T_3 V_163 , T_4 * V_61 )
{
char * V_144 = L_14 ;
T_1 V_25 = - V_64 ;
int V_164 ;
if ( * V_61 != 0 )
return 0 ;
if ( V_166 != NULL )
V_144 = V_166 ;
V_164 = strlen ( V_144 ) + 1 ;
if ( V_163 >= V_164 )
V_25 = F_73 ( V_59 , V_163 , V_61 , V_144 , V_164 ) ;
return V_25 ;
}
static T_1 F_82 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char * V_52 ;
struct V_6 * V_7 = F_83 ( V_9 -> V_167 -> V_168 ) ;
int V_25 = V_60 ;
if ( ! F_39 ( V_84 ) )
return - V_85 ;
if ( V_166 != NULL && V_166 != V_7 -> V_51 )
return - V_85 ;
V_52 = F_9 ( V_60 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_23 ( V_52 , V_59 , V_60 ) != 0 )
V_25 = - V_69 ;
else
V_166 = F_15 ( V_52 , V_60 ) ;
F_18 ( V_52 ) ;
return V_25 ;
}
static T_1 F_84 ( struct V_58 * V_158 , char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_159 [ 32 ] ;
T_1 V_25 ;
if ( * V_61 != 0 )
return 0 ;
sprintf ( V_159 , L_15 , V_169 ) ;
V_25 = F_73 ( V_59 , V_60 , V_61 , V_159 , strlen ( V_159 ) ) ;
return V_25 ;
}
static T_1 F_85 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char V_159 [ 32 ] ;
int V_57 ;
if ( ! F_39 ( V_84 ) )
return - V_85 ;
if ( V_60 >= sizeof( V_159 ) || V_60 == 0 )
return - V_64 ;
if ( F_23 ( V_159 , V_59 , V_60 ) != 0 )
return - V_69 ;
V_159 [ V_60 ] = '\0' ;
if ( sscanf ( V_159 , L_9 , & V_57 ) != 1 )
return - V_64 ;
if ( V_57 < 0 || V_57 > 3 )
return - V_64 ;
V_169 = V_57 ;
return V_60 ;
}
static void * F_86 ( struct V_73 * V_74 , T_4 * V_75 )
{
struct V_170 * V_171 = F_87 () ;
return F_24 ( V_74 , V_75 , & V_171 -> V_71 ) ;
}
static void * F_88 ( struct V_73 * V_74 , void * V_80 , T_4 * V_75 )
{
struct V_170 * V_171 = F_87 () ;
return F_26 ( V_74 , V_80 , V_75 , & V_171 -> V_71 ) ;
}
static int F_89 ( struct V_73 * V_74 , void * V_80 )
{
struct V_15 * V_34 = V_80 ;
struct V_20 * V_14 =
F_35 ( V_34 , struct V_20 , V_34 ) ;
F_29 ( V_74 , V_14 , V_53 ) ;
return 0 ;
}
static int F_90 ( struct V_82 * V_82 , struct V_58 * V_58 )
{
return F_37 ( V_58 , & V_172 ) ;
}
static T_1 F_91 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
struct V_170 * V_171 = F_87 () ;
return F_21 ( V_58 , V_59 , V_60 , V_61 , & V_171 -> V_71 ,
& V_171 -> V_72 , V_65 ) ;
}
static T_1 F_92 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 , int V_62 )
{
struct V_13 V_48 ;
char * V_52 ;
int V_173 ;
V_52 = F_93 ( V_58 , V_59 , V_60 ) ;
if ( F_94 ( V_52 ) )
return F_95 ( V_52 ) ;
if ( V_62 == V_65 ) {
if ( V_60 < V_67 )
return - V_64 ;
V_173 = F_19 ( V_52 , & V_48 , 0 ) ;
} else {
V_173 = F_20 ( V_52 , & V_48 , 0 , 3 ) ;
}
if ( V_173 < 0 )
return - V_64 ;
V_173 = V_28 ( V_48 . V_27 , V_48 . V_26 ,
V_48 . V_29 , NULL ) ;
V_52 [ 0 ] = V_173 == 0 ? '1' : '0' ;
V_52 [ 1 ] = '\0' ;
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
static int F_98 ( struct V_73 * V_74 , void * V_80 )
{
struct V_15 * V_34 = V_80 ;
struct V_22 * V_23 =
F_35 ( V_34 , struct V_22 , V_34 ) ;
F_29 ( V_74 , V_23 -> V_35 , V_174 ) ;
return 0 ;
}
static int F_99 ( struct V_82 * V_82 , struct V_58 * V_58 )
{
return F_37 ( V_58 , & V_175 ) ;
}
static T_1 F_100 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
if ( ! F_39 ( V_84 ) )
return - V_85 ;
return F_21 ( V_58 , V_59 , V_60 , V_61 , NULL , NULL ,
V_127 ) ;
}
static void * F_101 ( struct V_73 * V_74 , T_4 * V_75 )
{
struct V_170 * V_171 = F_87 () ;
return F_24 ( V_74 , V_75 , & V_171 -> V_71 ) ;
}
static void * F_102 ( struct V_73 * V_74 , void * V_80 , T_4 * V_75 )
{
struct V_170 * V_171 = F_87 () ;
return F_26 ( V_74 , V_80 , V_75 , & V_171 -> V_71 ) ;
}
static int F_103 ( struct V_73 * V_74 , void * V_80 )
{
struct V_15 * V_34 = V_80 ;
struct V_20 * V_14 =
F_35 ( V_34 , struct V_20 , V_34 ) ;
F_29 ( V_74 , V_14 , V_174 ) ;
return 0 ;
}
static int F_104 ( struct V_82 * V_82 , struct V_58 * V_58 )
{
return F_37 ( V_58 , & V_176 ) ;
}
static T_1 F_105 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
struct V_170 * V_171 = F_87 () ;
return F_21 ( V_58 , V_59 , V_60 , V_61 , & V_171 -> V_71 ,
& V_171 -> V_72 , V_127 ) ;
}
static T_1 F_106 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
return F_92 ( V_58 , V_59 , V_60 , V_61 , V_127 ) ;
}
static T_1 F_107 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
char * V_52 = NULL ;
const char * V_38 = NULL ;
struct V_6 * V_7 ;
struct V_20 * V_21 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_25 = V_60 ;
if ( * V_61 != 0 )
return - V_64 ;
if ( ! F_39 ( V_84 ) )
return - V_85 ;
if ( V_60 == 0 || V_60 > V_174 )
return - V_64 ;
V_52 = F_9 ( V_60 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_23 ( V_52 , V_59 , V_60 ) != 0 ) {
V_25 = - V_69 ;
goto V_153;
}
V_38 = F_16 ( V_52 , V_60 ) ;
if ( V_38 == NULL ) {
V_25 = - V_64 ;
goto V_153;
}
V_7 = F_17 ( V_38 ) ;
if ( V_7 == NULL )
goto V_153;
V_16 = & V_7 -> V_71 ;
V_18 = & V_7 -> V_72 ;
F_7 ( V_18 ) ;
F_8 (sp, rule_list, list)
V_21 -> V_28 = 0 ;
F_11 ( V_18 ) ;
V_153:
F_18 ( V_52 ) ;
F_18 ( V_38 ) ;
return V_25 ;
}
static int F_108 ( void )
{
V_177 = F_109 ( L_16 , NULL , V_178 ) ;
if ( ! V_177 )
return - V_32 ;
return 0 ;
}
static T_1 F_110 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
if ( ! F_111 ( V_84 ) )
return - V_85 ;
return F_21 ( V_58 , V_59 , V_60 , V_61 , NULL , NULL ,
V_70 ) ;
}
static int F_112 ( struct V_179 * V_180 , void * V_52 , int V_181 )
{
int V_25 ;
struct V_82 * V_182 ;
static struct V_183 V_184 [] = {
[ V_185 ] = {
L_17 , & V_186 , V_187 | V_188 } ,
[ V_189 ] = {
L_18 , & V_190 , V_187 | V_188 } ,
[ V_191 ] = {
L_19 , & V_192 , V_187 | V_188 } ,
[ V_193 ] = {
L_20 , & V_194 , V_187 | V_188 } ,
[ V_195 ] = {
L_21 , & V_196 , V_187 | V_188 } ,
[ V_197 ] = {
L_22 , & V_198 , V_187 | V_188 } ,
[ V_199 ] = {
L_23 , & V_200 , V_187 | V_188 } ,
[ V_201 ] = {
L_24 , & V_202 , V_187 | V_188 } ,
[ V_203 ] = {
L_25 , & V_204 , V_187 | V_205 } ,
[ V_206 ] = {
L_26 , & V_207 , V_187 | V_205 } ,
[ V_208 ] = {
L_27 , & V_209 , V_187 | V_188 } ,
[ V_210 ] = {
L_28 , & V_211 , V_187 | V_188 } ,
[ V_212 ] = {
L_29 , & V_213 , V_187 | V_205 } ,
[ V_214 ] = {
L_30 , & V_215 , V_187 | V_205 } ,
[ V_216 ] = {
L_31 , & V_217 , V_187 | V_188 } ,
[ V_218 ] = {
L_32 , & V_219 ,
V_187 | V_188 } ,
[ V_220 ] = {
L_33 , & V_221 , V_187 | V_188 } ,
{ L_14 }
} ;
V_25 = F_113 ( V_180 , V_222 , V_184 ) ;
if ( V_25 != 0 ) {
F_42 ( V_223 L_34 ,
V_91 , V_25 ) ;
return V_25 ;
}
V_182 = V_180 -> V_224 -> V_225 ;
return 0 ;
}
static struct V_226 * F_114 ( struct V_227 * V_228 ,
int V_229 , const char * V_230 , void * V_52 )
{
return F_115 ( V_228 , V_229 , V_52 , F_112 ) ;
}
static int T_7 F_116 ( struct V_6 * V_7 )
{
V_7 -> V_107 . V_231 = V_7 -> V_51 ;
V_7 -> V_107 . V_229 =
V_232 | V_233 ;
return F_54 ( V_160 , V_7 -> V_51 ,
& V_7 -> V_107 , strlen ( V_7 -> V_51 ) ) ;
}
static int T_7 F_117 ( void )
{
int V_234 ;
int V_25 ;
if ( ! F_118 ( & V_235 ) )
return 0 ;
V_234 = F_108 () ;
if ( V_234 )
F_42 ( V_223 L_35 ) ;
V_234 = F_119 ( & V_236 ) ;
if ( ! V_234 ) {
V_237 = F_120 ( & V_236 ) ;
if ( F_94 ( V_237 ) ) {
F_42 ( V_223 L_36 ) ;
V_234 = F_95 ( V_237 ) ;
V_237 = NULL ;
}
}
F_40 () ;
F_46 ( NULL ) ;
V_25 = F_116 ( & V_103 ) ;
if ( V_234 == 0 && V_25 < 0 )
V_234 = V_25 ;
V_25 = F_116 ( & V_238 ) ;
if ( V_234 == 0 && V_25 < 0 )
V_234 = V_25 ;
V_25 = F_116 ( & V_239 ) ;
if ( V_234 == 0 && V_25 < 0 )
V_234 = V_25 ;
V_25 = F_116 ( & V_240 ) ;
if ( V_234 == 0 && V_25 < 0 )
V_234 = V_25 ;
V_25 = F_116 ( & V_241 ) ;
if ( V_234 == 0 && V_25 < 0 )
V_234 = V_25 ;
V_25 = F_116 ( & V_242 ) ;
if ( V_234 == 0 && V_25 < 0 )
V_234 = V_25 ;
return V_234 ;
}
