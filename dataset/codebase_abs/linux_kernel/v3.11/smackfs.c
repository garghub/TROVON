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
static int F_20 ( const char * V_52 , struct V_13 * V_48 ,
int V_49 , int V_54 )
{
char * V_44 ;
char * V_45 ;
char * V_46 ;
char * V_47 ;
int V_55 ;
int V_25 = - 1 ;
V_55 = strlen ( V_52 ) ;
V_44 = F_9 ( V_55 + 1 , V_31 ) ;
if ( V_44 == NULL )
return - 1 ;
V_45 = F_9 ( V_55 , V_31 ) ;
if ( V_45 == NULL )
goto V_56;
V_46 = F_9 ( V_55 , V_31 ) ;
if ( V_46 == NULL )
goto V_57;
V_47 = F_9 ( V_55 , V_31 ) ;
if ( V_47 == NULL )
goto V_58;
if ( V_54 ) {
if ( sscanf ( V_52 , L_1 ,
V_44 , V_45 , V_46 , V_47 ) == 4 )
V_25 = F_13 ( V_44 , V_45 , V_46 , V_47 ,
V_48 , V_49 , 0 ) ;
} else {
if ( sscanf ( V_52 , L_2 , V_44 , V_45 , V_46 ) == 3 )
V_25 = F_13 ( V_44 , V_45 , V_46 , NULL ,
V_48 , V_49 , 0 ) ;
}
F_18 ( V_47 ) ;
V_58:
F_18 ( V_46 ) ;
V_57:
F_18 ( V_45 ) ;
V_56:
F_18 ( V_44 ) ;
return V_25 ;
}
static T_1 F_21 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 ,
struct V_15 * V_16 ,
struct V_17 * V_18 , int V_63 )
{
struct V_13 * V_48 ;
char * V_52 ;
int V_55 ;
int V_25 = - V_64 ;
int V_65 = 0 ;
if ( * V_62 != 0 )
return - V_64 ;
if ( V_63 == V_66 ) {
if ( V_61 != V_67 && V_61 != V_68 )
return - V_64 ;
V_55 = V_68 ;
} else
V_55 = V_61 + 1 ;
V_52 = F_9 ( V_55 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_22 ( V_52 , V_60 , V_61 ) != 0 ) {
V_25 = - V_69 ;
goto V_33;
}
V_48 = F_9 ( sizeof( * V_48 ) , V_31 ) ;
if ( V_48 == NULL ) {
V_25 = - V_32 ;
goto V_33;
}
if ( V_63 == V_70 ) {
V_52 [ V_61 ] = '\0' ;
if ( F_20 ( V_52 , V_48 , 1 , 0 ) )
goto V_71;
} else if ( V_63 == V_72 ) {
V_52 [ V_61 ] = '\0' ;
if ( F_20 ( V_52 , V_48 , 1 , 1 ) )
goto V_71;
} else {
if ( V_61 == ( V_67 ) )
V_52 [ V_67 ] = '-' ;
if ( F_19 ( V_52 , V_48 , 1 ) )
goto V_71;
}
if ( V_16 == NULL ) {
V_65 = 1 ;
V_16 = & V_48 -> V_27 -> V_73 ;
V_18 = & V_48 -> V_27 -> V_74 ;
}
V_25 = F_6 ( V_48 , V_16 , V_18 , V_65 ) ;
if ( V_25 == 0 ) {
V_25 = V_61 ;
goto V_33;
}
V_71:
F_18 ( V_48 ) ;
V_33:
F_18 ( V_52 ) ;
return V_25 ;
}
static void * F_23 ( struct V_75 * V_76 , T_4 * V_77 ,
struct V_15 * V_78 )
{
struct V_15 * V_34 ;
if ( V_76 -> V_79 == 0 )
V_76 -> V_80 = V_78 ;
if ( V_76 -> V_80 == NULL )
return NULL ;
V_34 = V_76 -> V_80 ;
if ( F_24 ( V_34 ) )
return NULL ;
if ( V_76 -> V_79 == 0 )
return V_34 -> V_81 ;
return V_34 ;
}
static void * F_25 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 ,
struct V_15 * V_78 )
{
struct V_15 * V_34 = V_82 ;
if ( F_26 ( V_34 , V_78 ) ) {
V_76 -> V_80 = NULL ;
return NULL ;
}
V_76 -> V_80 = V_34 -> V_81 ;
return V_34 -> V_81 ;
}
static void F_27 ( struct V_75 * V_76 , void * V_82 )
{
}
static void F_28 ( struct V_75 * V_76 , struct V_20 * V_14 , int V_83 )
{
if ( strlen ( V_14 -> V_27 -> V_51 ) >= V_83 ||
strlen ( V_14 -> V_26 ) >= V_83 )
return;
if ( V_14 -> V_28 == 0 )
return;
F_29 ( V_76 , L_3 , V_14 -> V_27 -> V_51 , V_14 -> V_26 ) ;
F_30 ( V_76 , ' ' ) ;
if ( V_14 -> V_28 & V_39 )
F_30 ( V_76 , 'r' ) ;
if ( V_14 -> V_28 & V_40 )
F_30 ( V_76 , 'w' ) ;
if ( V_14 -> V_28 & V_41 )
F_30 ( V_76 , 'x' ) ;
if ( V_14 -> V_28 & V_42 )
F_30 ( V_76 , 'a' ) ;
if ( V_14 -> V_28 & V_43 )
F_30 ( V_76 , 't' ) ;
F_30 ( V_76 , '\n' ) ;
}
static void * F_31 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_23 ( V_76 , V_77 , & V_36 ) ;
}
static void * F_32 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
return F_25 ( V_76 , V_82 , V_77 , & V_36 ) ;
}
static int F_33 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_22 * V_23 =
F_34 ( V_34 , struct V_22 , V_34 ) ;
F_28 ( V_76 , V_23 -> V_35 , V_53 ) ;
return 0 ;
}
static int F_35 ( struct V_84 * V_84 , struct V_59 * V_59 )
{
return F_36 ( V_59 , & V_85 ) ;
}
static T_1 F_37 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
if ( ! F_38 ( V_86 ) )
return - V_87 ;
return F_21 ( V_59 , V_60 , V_61 , V_62 , NULL , NULL ,
V_66 ) ;
}
static void F_39 ( void )
{
int V_25 ;
struct V_88 * V_89 ;
struct V_4 V_90 ;
F_2 ( & V_90 ) ;
V_25 = F_40 ( NULL , V_91 , NULL , NULL , & V_90 ) ;
if ( V_25 != 0 )
F_41 ( V_92 L_4 ,
V_93 , __LINE__ , V_25 ) ;
V_89 = F_42 ( sizeof( struct V_88 ) , V_31 ) ;
if ( V_89 == NULL )
F_43 ( L_5 ) ;
V_89 -> V_94 . V_95 = NULL ;
V_89 -> V_96 = V_97 ;
V_89 -> type = V_98 ;
V_89 -> V_99 [ 0 ] = V_100 ;
for ( V_25 = 1 ; V_25 < V_101 ; V_25 ++ )
V_89 -> V_99 [ V_25 ] = V_102 ;
V_25 = F_44 ( V_89 , & V_90 ) ;
if ( V_25 != 0 ) {
F_41 ( V_92 L_6 ,
V_93 , __LINE__ , V_25 ) ;
F_18 ( V_89 ) ;
return;
}
V_25 = F_45 ( V_89 -> V_96 , NULL , NULL , NULL , & V_90 ) ;
if ( V_25 != 0 ) {
F_41 ( V_92 L_7 ,
V_93 , __LINE__ , V_25 ) ;
F_18 ( V_89 ) ;
return;
}
}
static void F_46 ( char * V_103 )
{
int V_25 ;
struct V_4 V_90 ;
F_2 ( & V_90 ) ;
if ( V_103 != NULL ) {
V_25 = F_40 ( V_103 , V_91 , NULL , NULL , & V_90 ) ;
if ( V_25 != 0 )
F_41 ( V_92 L_4 ,
V_93 , __LINE__ , V_25 ) ;
}
if ( V_104 == NULL )
V_104 = & V_105 ;
V_25 = F_47 ( V_104 -> V_51 , V_91 ,
NULL , NULL , & V_90 ) ;
if ( V_25 != 0 )
F_41 ( V_92 L_8 ,
V_93 , __LINE__ , V_25 ) ;
}
static void * F_48 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_23 ( V_76 , V_77 , & V_106 ) ;
}
static void * F_49 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
return F_25 ( V_76 , V_82 , V_77 , & V_106 ) ;
}
static int F_50 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_6 * V_7 =
F_34 ( V_34 , struct V_6 , V_34 ) ;
struct V_107 * V_108 = V_7 -> V_109 . V_110 . V_111 . V_1 ;
char V_112 = '/' ;
int V_113 ;
if ( strlen ( V_7 -> V_51 ) >= V_53 )
return 0 ;
F_29 ( V_76 , L_9 , V_7 -> V_51 , V_7 -> V_109 . V_110 . V_111 . V_114 ) ;
for ( V_113 = F_51 ( V_108 , 0 ) ; V_113 >= 0 ;
V_113 = F_51 ( V_108 , V_113 + 1 ) ) {
F_29 ( V_76 , L_10 , V_112 , V_113 ) ;
V_112 = ',' ;
}
F_30 ( V_76 , '\n' ) ;
return 0 ;
}
static int F_52 ( struct V_84 * V_84 , struct V_59 * V_59 )
{
return F_36 ( V_59 , & V_115 ) ;
}
static T_1 F_53 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 , int V_63 )
{
struct V_6 * V_7 ;
struct V_116 V_117 ;
char V_118 [ V_3 ] ;
int V_119 ;
unsigned int V_1 ;
int V_120 ;
T_1 V_25 = - V_64 ;
char * V_52 = NULL ;
char * V_48 ;
int V_121 ;
int V_113 ;
if ( ! F_38 ( V_86 ) )
return - V_87 ;
if ( * V_62 != 0 )
return - V_64 ;
if ( V_63 == V_66 &&
( V_61 < V_122 || V_61 > V_123 ) )
return - V_64 ;
V_52 = F_9 ( V_61 + 1 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_22 ( V_52 , V_60 , V_61 ) != 0 ) {
V_25 = - V_69 ;
goto V_124;
}
V_52 [ V_61 ] = '\0' ;
V_48 = V_52 ;
F_7 ( & V_125 ) ;
V_7 = F_14 ( V_48 , 0 ) ;
if ( V_7 == NULL )
goto V_33;
if ( V_63 == V_66 )
V_48 += V_53 ;
else
V_48 += strlen ( V_7 -> V_51 ) + 1 ;
V_121 = sscanf ( V_48 , L_11 , & V_119 ) ;
if ( V_121 != 1 || V_119 > V_126 )
goto V_33;
V_48 += V_127 ;
V_121 = sscanf ( V_48 , L_11 , & V_120 ) ;
if ( V_121 != 1 || V_120 > V_128 )
goto V_33;
if ( V_63 == V_66 &&
V_61 != ( V_122 + V_120 * V_127 ) )
goto V_33;
memset ( V_118 , 0 , sizeof( V_118 ) ) ;
for ( V_113 = 0 ; V_113 < V_120 ; V_113 ++ ) {
V_48 += V_127 ;
V_121 = sscanf ( V_48 , L_12 , & V_1 ) ;
if ( V_121 != 1 || V_1 > V_129 )
goto V_33;
F_1 ( V_1 , V_118 ) ;
}
V_25 = F_54 ( V_119 , V_118 , & V_117 , V_3 ) ;
if ( V_25 >= 0 ) {
F_55 ( V_7 -> V_109 . V_110 . V_111 . V_1 ) ;
V_7 -> V_109 . V_110 . V_111 . V_1 = V_117 . V_110 . V_111 . V_1 ;
V_7 -> V_109 . V_110 . V_111 . V_114 = V_117 . V_110 . V_111 . V_114 ;
V_25 = V_61 ;
}
V_33:
F_11 ( & V_125 ) ;
V_124:
F_18 ( V_52 ) ;
return V_25 ;
}
static T_1 F_56 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
return F_53 ( V_59 , V_60 , V_61 , V_62 , V_66 ) ;
}
static int F_57 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_6 * V_7 =
F_34 ( V_34 , struct V_6 , V_34 ) ;
struct V_107 * V_108 = V_7 -> V_109 . V_110 . V_111 . V_1 ;
char V_112 = '/' ;
int V_113 ;
F_29 ( V_76 , L_9 , V_7 -> V_51 , V_7 -> V_109 . V_110 . V_111 . V_114 ) ;
for ( V_113 = F_51 ( V_108 , 0 ) ; V_113 >= 0 ;
V_113 = F_51 ( V_108 , V_113 + 1 ) ) {
F_29 ( V_76 , L_10 , V_112 , V_113 ) ;
V_112 = ',' ;
}
F_30 ( V_76 , '\n' ) ;
return 0 ;
}
static int F_58 ( struct V_84 * V_84 , struct V_59 * V_59 )
{
return F_36 ( V_59 , & V_130 ) ;
}
static T_1 F_59 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
return F_53 ( V_59 , V_60 , V_61 , V_62 , V_70 ) ;
}
static void * F_60 ( struct V_75 * V_76 , T_4 * V_77 )
{
return F_23 ( V_76 , V_77 , & V_131 ) ;
}
static void * F_61 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
return F_25 ( V_76 , V_82 , V_77 , & V_131 ) ;
}
static int F_62 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_132 * V_7 =
F_34 ( V_34 , struct V_132 , V_34 ) ;
unsigned char * V_133 = ( char * ) & V_7 -> V_134 . V_135 . V_136 ;
int V_137 ;
T_5 V_138 = F_63 ( V_7 -> V_139 . V_136 ) ;
for ( V_137 = 0 ; V_138 ; V_138 <<= 1 , V_137 ++ ) ;
F_29 ( V_76 , L_13 ,
V_133 [ 0 ] , V_133 [ 1 ] , V_133 [ 2 ] , V_133 [ 3 ] , V_137 , V_7 -> V_140 ) ;
return 0 ;
}
static int F_64 ( struct V_84 * V_84 , struct V_59 * V_59 )
{
return F_36 ( V_59 , & V_141 ) ;
}
static void F_65 ( struct V_132 * V_142 )
{
struct V_132 * V_143 , * V_144 ;
if ( F_24 ( & V_131 ) ) {
F_10 ( & V_142 -> V_34 , & V_131 ) ;
return;
}
V_143 = F_66 ( V_131 . V_81 ,
struct V_132 , V_34 ) ;
if ( V_142 -> V_139 . V_136 > V_143 -> V_139 . V_136 ) {
F_10 ( & V_142 -> V_34 , & V_131 ) ;
return;
}
F_8 (m, &smk_netlbladdr_list, list) {
if ( F_26 ( & V_143 -> V_34 , & V_131 ) ) {
F_10 ( & V_142 -> V_34 , & V_143 -> V_34 ) ;
return;
}
V_144 = F_66 ( V_143 -> V_34 . V_81 ,
struct V_132 , V_34 ) ;
if ( V_142 -> V_139 . V_136 > V_144 -> V_139 . V_136 ) {
F_10 ( & V_142 -> V_34 , & V_143 -> V_34 ) ;
return;
}
}
}
static T_1 F_67 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_132 * V_7 ;
struct V_145 V_146 ;
char * V_147 ;
char * V_21 ;
char * V_52 ;
char * V_148 = ( char * ) & V_146 . V_135 . V_136 ;
int V_25 ;
struct V_4 V_149 ;
struct V_150 V_151 ;
unsigned int V_143 ;
int V_24 ;
T_5 V_152 = ( 1 << 31 ) ;
T_6 V_153 ;
T_5 V_138 ;
if ( ! F_38 ( V_86 ) )
return - V_87 ;
if ( * V_62 != 0 )
return - V_64 ;
if ( V_61 < V_154 )
return - V_64 ;
V_52 = F_9 ( V_61 + 1 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_22 ( V_52 , V_60 , V_61 ) != 0 ) {
V_25 = - V_69 ;
goto V_155;
}
V_147 = F_9 ( V_61 + 1 , V_31 ) ;
if ( V_147 == NULL ) {
V_25 = - V_32 ;
goto V_155;
}
V_52 [ V_61 ] = '\0' ;
V_25 = sscanf ( V_52 , L_14 ,
& V_148 [ 0 ] , & V_148 [ 1 ] , & V_148 [ 2 ] , & V_148 [ 3 ] , & V_143 , V_147 ) ;
if ( V_25 != 6 ) {
V_25 = sscanf ( V_52 , L_15 ,
& V_148 [ 0 ] , & V_148 [ 1 ] , & V_148 [ 2 ] , & V_148 [ 3 ] , V_147 ) ;
if ( V_25 != 5 ) {
V_25 = - V_64 ;
goto V_156;
}
V_143 = V_157 ;
}
if ( V_143 > V_157 ) {
V_25 = - V_64 ;
goto V_156;
}
if ( V_147 [ 0 ] != '-' ) {
V_21 = F_15 ( V_147 , 0 ) ;
if ( V_21 == NULL ) {
V_25 = - V_64 ;
goto V_156;
}
} else {
if ( strcmp ( V_147 , V_158 ) == 0 )
V_21 = ( char * ) V_158 ;
else {
V_25 = - V_64 ;
goto V_156;
}
}
for ( V_138 = 0 ; V_143 > 0 ; V_143 -- ) {
V_138 |= V_152 ;
V_152 >>= 1 ;
}
V_151 . V_136 = F_68 ( V_138 ) ;
V_146 . V_135 . V_136 &= V_151 . V_136 ;
F_7 ( & V_159 ) ;
V_153 = V_146 . V_135 . V_136 ;
V_24 = 0 ;
F_8 (skp, &smk_netlbladdr_list, list) {
if ( V_7 -> V_134 . V_135 . V_136 == V_153 &&
V_7 -> V_139 . V_136 == V_151 . V_136 ) {
V_24 = 1 ;
break;
}
}
F_2 ( & V_149 ) ;
if ( V_24 == 0 ) {
V_7 = F_9 ( sizeof( * V_7 ) , V_31 ) ;
if ( V_7 == NULL )
V_25 = - V_32 ;
else {
V_25 = 0 ;
V_7 -> V_134 . V_135 . V_136 = V_146 . V_135 . V_136 ;
V_7 -> V_139 . V_136 = V_151 . V_136 ;
V_7 -> V_140 = V_21 ;
F_65 ( V_7 ) ;
}
} else {
if ( V_7 -> V_140 != V_158 )
V_25 = F_69 ( & V_160 , NULL ,
& V_7 -> V_134 . V_135 , & V_7 -> V_139 ,
V_91 , & V_149 ) ;
else
V_25 = 0 ;
V_7 -> V_140 = V_21 ;
}
if ( V_25 == 0 && V_21 != V_158 )
V_25 = F_70 ( & V_160 , NULL ,
& V_7 -> V_134 . V_135 , & V_7 -> V_139 , V_91 ,
F_71 ( V_7 -> V_140 ) , & V_149 ) ;
if ( V_25 == 0 )
V_25 = V_61 ;
F_11 ( & V_159 ) ;
V_156:
F_18 ( V_147 ) ;
V_155:
F_18 ( V_52 ) ;
return V_25 ;
}
static T_1 F_72 ( struct V_59 * V_161 , char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_162 [ 80 ] ;
T_1 V_25 ;
if ( * V_62 != 0 )
return 0 ;
sprintf ( V_162 , L_11 , V_97 ) ;
V_25 = F_73 ( V_60 , V_61 , V_62 , V_162 , strlen ( V_162 ) ) ;
return V_25 ;
}
static T_1 F_74 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_162 [ 80 ] ;
int V_113 ;
if ( ! F_38 ( V_86 ) )
return - V_87 ;
if ( V_61 >= sizeof( V_162 ) || V_61 == 0 )
return - V_64 ;
if ( F_22 ( V_162 , V_60 , V_61 ) != 0 )
return - V_69 ;
V_162 [ V_61 ] = '\0' ;
if ( sscanf ( V_162 , L_11 , & V_113 ) != 1 )
return - V_64 ;
V_97 = V_113 ;
F_39 () ;
return V_61 ;
}
static T_1 F_75 ( struct V_59 * V_161 , char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_162 [ 80 ] ;
T_1 V_25 ;
if ( * V_62 != 0 )
return 0 ;
sprintf ( V_162 , L_11 , V_163 ) ;
V_25 = F_73 ( V_60 , V_61 , V_62 , V_162 , strlen ( V_162 ) ) ;
return V_25 ;
}
static T_1 F_76 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_6 * V_7 ;
char V_162 [ 80 ] ;
int V_113 ;
if ( ! F_38 ( V_86 ) )
return - V_87 ;
if ( V_61 >= sizeof( V_162 ) || V_61 == 0 )
return - V_64 ;
if ( F_22 ( V_162 , V_60 , V_61 ) != 0 )
return - V_69 ;
V_162 [ V_61 ] = '\0' ;
if ( sscanf ( V_162 , L_11 , & V_113 ) != 1 )
return - V_64 ;
if ( V_163 != V_113 ) {
F_7 ( & V_164 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_109 . V_110 . V_111 . V_114 ==
V_163 )
V_7 -> V_109 . V_110 . V_111 . V_114 = V_113 ;
V_163 = V_113 ;
F_11 ( & V_164 ) ;
}
return V_61 ;
}
static T_1 F_77 ( struct V_59 * V_161 , char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_162 [ 80 ] ;
T_1 V_25 ;
if ( * V_62 != 0 )
return 0 ;
sprintf ( V_162 , L_11 , V_165 ) ;
V_25 = F_73 ( V_60 , V_61 , V_62 , V_162 , strlen ( V_162 ) ) ;
return V_25 ;
}
static T_1 F_78 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_6 * V_7 ;
char V_162 [ 80 ] ;
int V_113 ;
if ( ! F_38 ( V_86 ) )
return - V_87 ;
if ( V_61 >= sizeof( V_162 ) || V_61 == 0 )
return - V_64 ;
if ( F_22 ( V_162 , V_60 , V_61 ) != 0 )
return - V_69 ;
V_162 [ V_61 ] = '\0' ;
if ( sscanf ( V_162 , L_11 , & V_113 ) != 1 )
return - V_64 ;
if ( V_165 != V_113 ) {
F_7 ( & V_164 ) ;
F_8 (skp, &smack_known_list, list)
if ( V_7 -> V_109 . V_110 . V_111 . V_114 ==
V_165 )
V_7 -> V_109 . V_110 . V_111 . V_114 = V_113 ;
V_165 = V_113 ;
F_11 ( & V_164 ) ;
}
return V_61 ;
}
static T_1 F_79 ( struct V_59 * V_161 , char T_2 * V_60 ,
T_3 V_166 , T_4 * V_62 )
{
T_1 V_25 ;
int V_167 ;
if ( * V_62 != 0 )
return 0 ;
F_7 ( & V_168 ) ;
V_167 = strlen ( V_104 -> V_51 ) + 1 ;
if ( V_166 >= V_167 )
V_25 = F_73 ( V_60 , V_166 , V_62 ,
V_104 -> V_51 ,
V_167 ) ;
else
V_25 = - V_64 ;
F_11 ( & V_168 ) ;
return V_25 ;
}
static T_1 F_80 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_6 * V_7 ;
char * V_103 ;
char * V_52 ;
int V_25 = V_61 ;
if ( ! F_38 ( V_86 ) )
return - V_87 ;
V_52 = F_9 ( V_61 + 1 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_22 ( V_52 , V_60 , V_61 ) != 0 ) {
V_25 = - V_69 ;
goto V_33;
}
V_7 = F_14 ( V_52 , V_61 ) ;
if ( V_7 == NULL ) {
V_25 = - V_64 ;
goto V_33;
}
F_7 ( & V_168 ) ;
V_103 = V_104 -> V_51 ;
V_104 = V_7 ;
F_46 ( V_103 ) ;
F_11 ( & V_168 ) ;
V_33:
F_18 ( V_52 ) ;
return V_25 ;
}
static T_1 F_81 ( struct V_59 * V_161 , char T_2 * V_60 ,
T_3 V_166 , T_4 * V_62 )
{
char * V_147 = L_16 ;
T_1 V_25 = - V_64 ;
int V_167 ;
if ( * V_62 != 0 )
return 0 ;
if ( V_169 != NULL )
V_147 = V_169 ;
V_167 = strlen ( V_147 ) + 1 ;
if ( V_166 >= V_167 )
V_25 = F_73 ( V_60 , V_166 , V_62 , V_147 , V_167 ) ;
return V_25 ;
}
static T_1 F_82 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char * V_52 ;
struct V_6 * V_7 = F_83 ( V_9 -> V_170 -> V_171 ) ;
int V_25 = V_61 ;
if ( ! F_38 ( V_86 ) )
return - V_87 ;
if ( V_169 != NULL && V_169 != V_7 -> V_51 )
return - V_87 ;
V_52 = F_9 ( V_61 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_22 ( V_52 , V_60 , V_61 ) != 0 )
V_25 = - V_69 ;
else
V_169 = F_15 ( V_52 , V_61 ) ;
F_18 ( V_52 ) ;
return V_25 ;
}
static T_1 F_84 ( struct V_59 * V_161 , char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_162 [ 32 ] ;
T_1 V_25 ;
if ( * V_62 != 0 )
return 0 ;
sprintf ( V_162 , L_17 , V_172 ) ;
V_25 = F_73 ( V_60 , V_61 , V_62 , V_162 , strlen ( V_162 ) ) ;
return V_25 ;
}
static T_1 F_85 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_162 [ 32 ] ;
int V_113 ;
if ( ! F_38 ( V_86 ) )
return - V_87 ;
if ( V_61 >= sizeof( V_162 ) || V_61 == 0 )
return - V_64 ;
if ( F_22 ( V_162 , V_60 , V_61 ) != 0 )
return - V_69 ;
V_162 [ V_61 ] = '\0' ;
if ( sscanf ( V_162 , L_11 , & V_113 ) != 1 )
return - V_64 ;
if ( V_113 < 0 || V_113 > 3 )
return - V_64 ;
V_172 = V_113 ;
return V_61 ;
}
static void * F_86 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_173 * V_174 = F_87 () ;
return F_23 ( V_76 , V_77 , & V_174 -> V_73 ) ;
}
static void * F_88 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
struct V_173 * V_174 = F_87 () ;
return F_25 ( V_76 , V_82 , V_77 , & V_174 -> V_73 ) ;
}
static int F_89 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_20 * V_14 =
F_34 ( V_34 , struct V_20 , V_34 ) ;
F_28 ( V_76 , V_14 , V_53 ) ;
return 0 ;
}
static int F_90 ( struct V_84 * V_84 , struct V_59 * V_59 )
{
return F_36 ( V_59 , & V_175 ) ;
}
static T_1 F_91 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_173 * V_174 = F_87 () ;
return F_21 ( V_59 , V_60 , V_61 , V_62 , & V_174 -> V_73 ,
& V_174 -> V_74 , V_66 ) ;
}
static T_1 F_92 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 , int V_63 )
{
struct V_13 V_48 ;
char * V_52 ;
char * V_176 ;
int V_177 ;
V_52 = F_93 ( V_59 , V_60 , V_61 ) ;
if ( F_94 ( V_52 ) )
return F_95 ( V_52 ) ;
if ( V_63 == V_66 ) {
if ( V_61 < V_68 )
return - V_64 ;
V_177 = F_19 ( V_52 , & V_48 , 0 ) ;
} else {
V_176 = F_9 ( V_61 + 1 , V_31 ) ;
if ( V_176 == NULL )
return - V_32 ;
memcpy ( V_176 , V_52 , V_61 ) ;
V_176 [ V_61 ] = '\0' ;
V_177 = F_20 ( V_176 , & V_48 , 0 , 0 ) ;
F_18 ( V_176 ) ;
}
if ( V_177 )
return - V_64 ;
V_177 = V_28 ( V_48 . V_27 , V_48 . V_26 ,
V_48 . V_29 , NULL ) ;
V_52 [ 0 ] = V_177 == 0 ? '1' : '0' ;
V_52 [ 1 ] = '\0' ;
F_96 ( V_59 , 2 ) ;
if ( V_63 == V_66 )
return V_68 ;
return V_61 ;
}
static T_1 F_97 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
return F_92 ( V_59 , V_60 , V_61 , V_62 , V_66 ) ;
}
static int F_98 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_22 * V_23 =
F_34 ( V_34 , struct V_22 , V_34 ) ;
F_28 ( V_76 , V_23 -> V_35 , V_178 ) ;
return 0 ;
}
static int F_99 ( struct V_84 * V_84 , struct V_59 * V_59 )
{
return F_36 ( V_59 , & V_179 ) ;
}
static T_1 F_100 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
if ( ! F_38 ( V_86 ) )
return - V_87 ;
return F_21 ( V_59 , V_60 , V_61 , V_62 , NULL , NULL ,
V_70 ) ;
}
static void * F_101 ( struct V_75 * V_76 , T_4 * V_77 )
{
struct V_173 * V_174 = F_87 () ;
return F_23 ( V_76 , V_77 , & V_174 -> V_73 ) ;
}
static void * F_102 ( struct V_75 * V_76 , void * V_82 , T_4 * V_77 )
{
struct V_173 * V_174 = F_87 () ;
return F_25 ( V_76 , V_82 , V_77 , & V_174 -> V_73 ) ;
}
static int F_103 ( struct V_75 * V_76 , void * V_82 )
{
struct V_15 * V_34 = V_82 ;
struct V_20 * V_14 =
F_34 ( V_34 , struct V_20 , V_34 ) ;
F_28 ( V_76 , V_14 , V_178 ) ;
return 0 ;
}
static int F_104 ( struct V_84 * V_84 , struct V_59 * V_59 )
{
return F_36 ( V_59 , & V_180 ) ;
}
static T_1 F_105 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
struct V_173 * V_174 = F_87 () ;
return F_21 ( V_59 , V_60 , V_61 , V_62 , & V_174 -> V_73 ,
& V_174 -> V_74 , V_70 ) ;
}
static T_1 F_106 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
return F_92 ( V_59 , V_60 , V_61 , V_62 , V_70 ) ;
}
static T_1 F_107 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char * V_52 = NULL ;
const char * V_38 = NULL ;
struct V_6 * V_7 ;
struct V_20 * V_21 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_25 = V_61 ;
if ( * V_62 != 0 )
return - V_64 ;
if ( ! F_38 ( V_86 ) )
return - V_87 ;
if ( V_61 == 0 || V_61 > V_178 )
return - V_64 ;
V_52 = F_9 ( V_61 , V_31 ) ;
if ( V_52 == NULL )
return - V_32 ;
if ( F_22 ( V_52 , V_60 , V_61 ) != 0 ) {
V_25 = - V_69 ;
goto V_156;
}
V_38 = F_16 ( V_52 , V_61 ) ;
if ( V_38 == NULL ) {
V_25 = - V_64 ;
goto V_156;
}
V_7 = F_17 ( V_38 ) ;
if ( V_7 == NULL )
goto V_156;
V_16 = & V_7 -> V_73 ;
V_18 = & V_7 -> V_74 ;
F_7 ( V_18 ) ;
F_8 (sp, rule_list, list)
V_21 -> V_28 = 0 ;
F_11 ( V_18 ) ;
V_156:
F_18 ( V_52 ) ;
F_18 ( V_38 ) ;
return V_25 ;
}
static int F_108 ( void )
{
V_181 = F_109 ( L_18 , NULL , V_182 ) ;
if ( ! V_181 )
return - V_32 ;
return 0 ;
}
static T_1 F_110 ( struct V_59 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
if ( ! F_111 ( V_86 ) )
return - V_87 ;
return F_21 ( V_59 , V_60 , V_61 , V_62 , NULL , NULL ,
V_72 ) ;
}
static int F_112 ( struct V_183 * V_184 , void * V_52 , int V_185 )
{
int V_25 ;
struct V_84 * V_186 ;
static struct V_187 V_188 [] = {
[ V_189 ] = {
L_19 , & V_190 , V_191 | V_192 } ,
[ V_193 ] = {
L_20 , & V_194 , V_191 | V_192 } ,
[ V_195 ] = {
L_21 , & V_196 , V_191 | V_192 } ,
[ V_197 ] = {
L_22 , & V_198 , V_191 | V_192 } ,
[ V_199 ] = {
L_23 , & V_200 , V_191 | V_192 } ,
[ V_201 ] = {
L_24 , & V_202 , V_191 | V_192 } ,
[ V_203 ] = {
L_25 , & V_204 , V_191 | V_192 } ,
[ V_205 ] = {
L_26 , & V_206 , V_191 | V_192 } ,
[ V_207 ] = {
L_27 , & V_208 , V_191 | V_209 } ,
[ V_210 ] = {
L_28 , & V_211 , V_191 | V_209 } ,
[ V_212 ] = {
L_29 , & V_213 , V_191 | V_192 } ,
[ V_214 ] = {
L_30 , & V_215 , V_191 | V_192 } ,
[ V_216 ] = {
L_31 , & V_217 , V_191 | V_209 } ,
[ V_218 ] = {
L_32 , & V_219 , V_191 | V_209 } ,
[ V_220 ] = {
L_33 , & V_221 , V_191 | V_192 } ,
[ V_222 ] = {
L_34 , & V_223 ,
V_191 | V_192 } ,
[ V_224 ] = {
L_35 , & V_225 , V_191 | V_192 } ,
{ L_16 }
} ;
V_25 = F_113 ( V_184 , V_226 , V_188 ) ;
if ( V_25 != 0 ) {
F_41 ( V_227 L_36 ,
V_93 , V_25 ) ;
return V_25 ;
}
V_186 = V_184 -> V_228 -> V_229 ;
return 0 ;
}
static struct V_230 * F_114 ( struct V_231 * V_232 ,
int V_233 , const char * V_234 , void * V_52 )
{
return F_115 ( V_232 , V_233 , V_52 , F_112 ) ;
}
static int T_7 F_116 ( struct V_6 * V_7 )
{
V_7 -> V_109 . V_235 = V_7 -> V_51 ;
V_7 -> V_109 . V_233 =
V_236 | V_237 ;
return F_54 ( V_163 , V_7 -> V_51 ,
& V_7 -> V_109 , strlen ( V_7 -> V_51 ) ) ;
}
static int T_7 F_117 ( void )
{
int V_238 ;
int V_25 ;
if ( ! F_118 ( & V_239 ) )
return 0 ;
V_238 = F_108 () ;
if ( V_238 )
F_41 ( V_227 L_37 ) ;
V_238 = F_119 ( & V_240 ) ;
if ( ! V_238 ) {
V_241 = F_120 ( & V_240 ) ;
if ( F_94 ( V_241 ) ) {
F_41 ( V_227 L_38 ) ;
V_238 = F_95 ( V_241 ) ;
V_241 = NULL ;
}
}
F_39 () ;
F_46 ( NULL ) ;
V_25 = F_116 ( & V_105 ) ;
if ( V_238 == 0 && V_25 < 0 )
V_238 = V_25 ;
V_25 = F_116 ( & V_242 ) ;
if ( V_238 == 0 && V_25 < 0 )
V_238 = V_25 ;
V_25 = F_116 ( & V_243 ) ;
if ( V_238 == 0 && V_25 < 0 )
V_238 = V_25 ;
V_25 = F_116 ( & V_244 ) ;
if ( V_238 == 0 && V_25 < 0 )
V_238 = V_25 ;
V_25 = F_116 ( & V_245 ) ;
if ( V_238 == 0 && V_25 < 0 )
V_238 = V_25 ;
V_25 = F_116 ( & V_246 ) ;
if ( V_238 == 0 && V_25 < 0 )
V_238 = V_25 ;
return V_238 ;
}
