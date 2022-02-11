static int F_1 ( char * V_1 , int V_2 , struct V_3 * V_4 ,
int type )
{
T_1 V_5 = 0 ;
if ( V_2 > 8 ) {
F_2 ( L_1 , V_1 ) ;
return - V_6 ;
}
if ( V_2 <= 0 ) {
F_2 ( L_2 , V_1 ) ;
return - V_6 ;
}
memcpy ( & V_5 , V_1 , V_2 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_1 [ 0 ] = F_3 ( V_5 ) ;
switch ( type ) {
case V_7 :
case V_8 :
V_5 = 0 ;
break;
case V_9 :
V_5 = type ;
break;
default:
F_4 () ;
}
V_4 -> V_1 [ 1 ] = F_3 ( V_5 ) ;
F_5 ( V_10 , L_3 V_11 L_4 V_11 L_5 , V_1 ,
V_4 -> V_1 [ 0 ] , V_4 -> V_1 [ 1 ] , ( char * ) & V_4 -> V_1 [ 0 ] ) ;
return 0 ;
}
int F_6 ( char * V_12 , struct V_3 * V_4 , int type )
{
return F_1 ( V_12 , strlen ( V_12 ) , V_4 , type ) ;
}
int F_7 ( char * V_13 , struct V_3 * V_4 , int type )
{
char * V_14 ;
int V_2 ;
V_14 = strrchr ( V_13 , '-' ) ;
F_8 ( V_14 ) ;
V_2 = V_14 - V_13 ;
return F_1 ( V_13 , V_2 , V_4 , type ) ;
}
static int F_9 ( struct V_15 * V_16 )
{
F_10 ( & V_16 -> V_17 ) ;
F_5 ( V_18 , L_6 , V_16 -> V_19 ,
F_11 ( & V_16 -> V_17 ) ) ;
return 0 ;
}
static void F_12 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_6 , V_16 -> V_19 ,
F_11 ( & V_16 -> V_17 ) ) ;
F_8 ( F_11 ( & V_16 -> V_17 ) > 0 ) ;
if ( F_13 ( & V_16 -> V_17 , & V_20 ) ) {
F_14 ( & V_16 -> V_21 ) ;
F_15 ( & V_20 ) ;
F_5 ( V_10 , L_7 , V_16 -> V_19 ) ;
if ( V_16 -> V_22 )
F_12 ( V_16 -> V_22 ) ;
if ( V_16 -> V_23 )
F_12 ( V_16 -> V_23 ) ;
if ( F_16 ( V_16 ) )
F_17 ( V_16 -> V_19 ) ;
F_18 ( V_16 -> V_24 ) ;
F_19 ( V_16 , sizeof( * V_16 ) + strlen ( V_16 -> V_19 ) + 1 ) ;
}
}
static
struct V_15 * F_20 ( char * V_13 ,
struct V_25 * V_26 )
{
struct V_15 * V_16 ;
struct V_15 * V_27 = NULL ;
void * V_28 ;
F_8 ( V_13 != NULL ) ;
V_28 = V_26 ? V_26 -> V_29 : NULL ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_28 != V_16 -> V_30 . V_29 )
continue;
if ( strcmp ( V_13 , V_16 -> V_19 ) == 0 ) {
V_27 = V_16 ;
break;
}
}
if ( V_27 ) {
F_10 ( & V_27 -> V_17 ) ;
F_8 ( V_27 -> V_31 == 0 || F_16 ( V_27 ) == 0 ) ;
}
F_15 ( & V_20 ) ;
return V_27 ;
}
static
struct V_15 * F_23 ( struct V_32 * V_33 ,
char * V_13 ,
int type ,
struct V_25 * V_26 ,
struct V_34 * V_35 )
{
struct V_15 * V_16 ;
int V_36 ;
F_5 ( V_10 , L_8 , V_13 ,
V_26 ? V_26 -> V_29 : 0 ) ;
F_24 ( V_16 , sizeof( * V_16 ) + strlen ( V_13 ) + 1 ) ;
if ( ! V_16 )
return F_25 ( - V_37 ) ;
strcpy ( V_16 -> V_19 , V_13 ) ;
if ( V_26 )
V_16 -> V_30 = * V_26 ;
else
V_16 -> V_30 . V_38 = V_39 ;
F_26 ( & V_16 -> V_40 ) ;
V_16 -> V_30 . V_41 = 0 ;
V_16 -> V_30 . V_42 = 0 ;
V_16 -> V_30 . V_43 = V_35 ;
V_16 -> V_44 = type ;
F_27 ( & V_16 -> V_17 , 1 ) ;
V_16 -> V_24 = F_28 ( V_33 -> V_45 ) ;
if ( F_16 ( V_16 ) ) {
F_29 ( V_13 ) ;
V_16 -> V_30 . V_46 = V_33 -> V_47 ;
}
V_36 = F_7 ( V_13 , & V_16 -> V_48 , type ) ;
F_21 ( & V_20 ) ;
F_30 ( & V_16 -> V_21 , & V_49 ) ;
F_15 ( & V_20 ) ;
if ( V_36 ) {
F_12 ( V_16 ) ;
return F_25 ( V_36 ) ;
}
if ( F_16 ( V_16 ) ) {
V_36 = F_31 ( V_33 , V_16 ) ;
if ( V_36 && V_36 != - V_50 )
F_2 ( L_9 , V_36 ) ;
}
return V_16 ;
}
static struct V_15 * F_32 ( struct V_32 * V_33 ,
char * V_12 ,
struct V_25 * V_26 ,
struct V_34 * V_35 )
{
struct V_25 V_51 = * V_26 ;
struct V_52 * V_53 = F_33 ( V_35 ) ;
struct V_15 * V_16 ;
char V_13 [ 32 ] ;
if ( F_34 ( V_53 ) )
return NULL ;
if ( F_35 ( V_53 ) && V_51 . V_29 )
return NULL ;
F_8 ( strlen ( V_12 ) < sizeof( V_13 ) / 2 ) ;
strcpy ( V_13 , V_12 ) ;
if ( F_36 ( V_53 ) ) {
F_8 ( V_51 . V_29 == NULL ) ;
V_51 . V_29 = V_35 ;
strcat ( V_13 , L_10 ) ;
} else {
F_8 ( V_51 . V_29 != NULL ) ;
strcat ( V_13 , L_11 ) ;
}
V_16 = F_23 ( V_33 , V_13 , V_9 , & V_51 , V_35 ) ;
return V_16 ;
}
static int F_37 ( struct V_32 * V_33 , char * V_13 ,
struct V_25 * V_26 ,
struct V_34 * V_35 )
{
struct V_52 * V_53 = F_33 ( V_35 ) ;
struct V_15 * V_16 ;
struct V_15 * V_54 ;
char V_55 [ 32 ] ;
char * V_56 ;
F_5 ( V_10 , L_12 , V_13 , V_26 -> V_29 ) ;
V_56 = strrchr ( V_13 , '-' ) ;
if ( V_56 == NULL || V_56 - V_13 > 8 ) {
F_2 ( L_13 , V_13 ) ;
return - V_6 ;
}
memcpy ( V_55 , V_13 , V_56 - V_13 ) ;
strcpy ( V_55 + ( V_56 - V_13 ) , L_14 ) ;
V_54 = F_20 ( V_55 , NULL ) ;
if ( V_54 == NULL ) {
V_54 = F_23 ( V_33 , V_55 ,
V_8 , NULL , NULL ) ;
if ( F_38 ( V_54 ) ) {
F_2 ( L_15 , V_55 ) ;
return F_39 ( V_54 ) ;
}
}
V_16 = F_23 ( V_33 , V_13 , V_7 , V_26 , V_35 ) ;
if ( F_38 ( V_16 ) ) {
F_2 ( L_16 , V_13 ) ;
F_12 ( V_54 ) ;
return F_39 ( V_16 ) ;
}
V_16 -> V_23 = V_54 ;
F_8 ( V_53 -> V_57 ) ;
if ( ! ( V_53 -> V_57 -> V_58 & V_59 ) ) {
struct V_15 * V_60 ;
* strrchr ( V_55 , '-' ) = 0 ;
V_60 = F_32 ( V_33 , V_55 , V_26 , V_35 ) ;
if ( F_38 ( V_60 ) ) {
F_12 ( V_16 ) ;
return F_39 ( V_60 ) ;
}
V_16 -> V_22 = V_60 ;
}
return 0 ;
}
static int F_40 ( char * V_13 , struct V_25 * V_26 )
{
struct V_15 * V_16 ;
struct V_15 * V_23 = NULL ;
struct V_15 * V_22 = NULL ;
int V_36 = 0 ;
V_16 = F_20 ( V_13 , V_26 ) ;
if ( V_16 == NULL )
return - V_50 ;
F_41 ( & V_16 -> V_40 ) ;
if ( F_42 ( V_16 -> V_31 ) ) {
F_43 ( & V_16 -> V_40 ) ;
F_12 ( V_16 ) ;
return V_36 ;
}
V_16 -> V_31 = 1 ;
V_22 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_43 ( & V_16 -> V_40 ) ;
if ( V_22 ) {
F_41 ( & V_22 -> V_40 ) ;
V_22 -> V_31 = 1 ;
F_43 ( & V_22 -> V_40 ) ;
F_12 ( V_22 ) ;
}
F_21 ( & V_20 ) ;
V_23 = V_16 -> V_23 ;
V_16 -> V_23 = NULL ;
F_15 ( & V_20 ) ;
if ( V_23 )
F_12 ( V_23 ) ;
F_12 ( V_16 ) ;
F_12 ( V_16 ) ;
F_5 ( V_10 , L_17 , V_13 ? V_13 : L_18 ,
V_36 ) ;
return V_36 ;
}
int F_44 ( struct V_61 * V_62 , void * V_63 )
{
struct V_32 * V_33 = V_63 ;
struct V_64 * V_65 = V_33 -> V_66 . V_67 . V_68 ;
struct V_69 * V_70 = & V_65 -> V_71 ;
struct V_15 * V_16 ;
F_45 ( V_62 , L_19 ,
F_46 ( V_70 , V_72 ) ? L_20 : L_21 ) ;
F_45 ( V_62 , L_22 ) ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_16 -> V_22 == NULL )
continue;
F_45 ( V_62 , L_23 ,
V_16 -> V_19 ,
V_16 -> V_22 -> V_30 . V_41 ) ;
}
F_15 ( & V_20 ) ;
return 0 ;
}
static void F_47 ( struct V_15 * V_16 )
{
F_8 ( F_11 ( & V_16 -> V_17 ) > 0 ) ;
F_48 ( & V_16 -> V_24 -> V_73 -> V_66 . V_67 . V_74 ) ;
if ( V_16 -> V_24 -> V_73 -> V_66 . V_67 . V_75 != 0 ) {
F_5 ( V_10 , L_24 , V_16 -> V_19 ) ;
F_31 ( V_16 -> V_24 -> V_73 , V_16 ) ;
} else {
F_5 ( V_10 , L_25 ,
V_16 -> V_19 ) ;
}
F_49 ( & V_16 -> V_24 -> V_73 -> V_66 . V_67 . V_74 ) ;
}
static int F_50 ( void * V_63 )
{
int V_36 = 0 ;
F_5 ( V_10 , L_26 ) ;
F_21 ( & V_20 ) ;
V_76 |= V_77 ;
while ( 1 ) {
struct V_78 V_79 ;
struct V_15 * V_16 , * V_80 ;
int rand = F_51 () & V_81 ;
int V_82 = ! ! ( V_76 & V_83 ) ;
int V_84 ;
V_76 &= ~ ( V_85 | V_86 ) ;
F_15 ( & V_20 ) ;
V_84 = V_87 * V_88 ;
V_84 += rand * V_88 / 100 ;
V_79 = F_52 ( V_84 , NULL , NULL ) ;
F_53 ( V_89 , V_76 & V_83 , & V_79 ) ;
V_80 = NULL ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list,
cld_list_chain) {
if ( ! V_16 -> V_90 )
continue;
F_15 ( & V_20 ) ;
F_8 ( F_11 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_80 )
F_12 ( V_80 ) ;
V_80 = V_16 ;
V_16 -> V_90 = 0 ;
if ( F_54 ( ! V_82 ) )
F_47 ( V_16 ) ;
F_21 ( & V_20 ) ;
}
F_15 ( & V_20 ) ;
if ( V_80 )
F_12 ( V_80 ) ;
if ( F_42 ( V_82 ) ) {
F_21 ( & V_20 ) ;
break;
}
V_79 = (struct V_78 ) { 0 } ;
F_53 ( V_89 , V_76 & ( V_85 | V_83 ) ,
& V_79 ) ;
F_21 ( & V_20 ) ;
}
V_76 &= ~ V_77 ;
F_15 ( & V_20 ) ;
F_55 ( & V_91 ) ;
F_5 ( V_10 , L_27 ) ;
return V_36 ;
}
static void F_56 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_28 ,
V_16 -> V_19 , F_11 ( & V_16 -> V_17 ) ,
V_16 -> V_31 , V_76 ) ;
F_8 ( F_11 ( & V_16 -> V_17 ) > 0 ) ;
F_41 ( & V_16 -> V_40 ) ;
if ( V_16 -> V_31 || V_16 -> V_90 ) {
F_43 ( & V_16 -> V_40 ) ;
return;
}
F_9 ( V_16 ) ;
V_16 -> V_90 = 1 ;
F_43 ( & V_16 -> V_40 ) ;
F_21 ( & V_20 ) ;
if ( V_76 & V_83 ) {
F_15 ( & V_20 ) ;
V_16 -> V_90 = 0 ;
F_12 ( V_16 ) ;
} else {
V_76 |= V_85 ;
F_15 ( & V_20 ) ;
F_57 ( & V_89 ) ;
}
}
static int F_58 ( const struct V_92 * V_93 ,
struct V_32 * V_33 ,
struct V_32 * V_94 )
{
struct V_95 * V_96 ;
int V_36 ;
V_36 = F_59 ( V_93 , V_33 , & V_33 -> V_97 , V_98 , V_94 ,
& V_99 ) ;
if ( V_36 )
return V_36 ;
V_96 = F_60 ( V_33 , V_98 ) ;
F_8 ( V_96 ) ;
V_96 -> V_100 = V_33 -> V_66 . V_67 . V_101 ;
F_61 ( V_96 ) ;
return 0 ;
}
static int F_62 ( const struct V_92 * V_93 ,
struct V_32 * V_33 )
{
struct V_95 * V_96 ;
V_96 = F_60 ( V_33 , V_98 ) ;
F_63 ( V_93 , V_96 ) ;
return 0 ;
}
static int F_64 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
struct V_52 * V_53 = F_33 ( V_35 ) ;
struct V_102 * V_67 = & V_33 -> V_66 . V_67 ;
struct V_103 V_104 , V_105 ;
struct V_106 * V_107 , * V_108 ;
struct V_92 * V_93 ;
int V_36 = 0 ;
F_8 ( V_53 ) ;
F_8 ( V_53 -> V_109 ) ;
F_65 ( V_93 ) ;
if ( V_93 == NULL )
return - V_37 ;
F_66 ( & V_67 -> V_110 ) ;
F_67 () ;
V_36 = F_68 ( V_93 , V_111 ) ;
if ( V_36 )
GOTO ( V_112 , V_36 ) ;
V_105 . V_113 = V_114 ;
V_105 . V_115 = 1 ;
V_105 . V_116 = 0 ;
V_36 = F_69 ( V_93 , V_53 -> V_109 , & V_105 ,
& V_67 -> V_117 ) ;
if ( V_36 )
GOTO ( V_118 , V_36 ) ;
V_36 = F_70 ( V_93 , V_53 -> V_109 , & V_104 ) ;
if ( V_36 )
GOTO ( V_118 , V_36 ) ;
V_107 = F_71 ( V_93 , V_53 -> V_109 , & V_104 ,
& V_67 -> V_117 -> V_119 -> V_120 ) ;
if ( F_42 ( F_38 ( V_107 ) ) )
GOTO ( V_121 , V_36 = F_39 ( V_107 ) ) ;
V_108 = F_72 ( V_93 , V_67 -> V_117 , V_107 ,
V_122 ,
V_123 | V_124 | V_125 | V_126 ) ;
F_73 ( V_93 , & V_107 -> V_127 ) ;
if ( F_38 ( V_108 ) )
GOTO ( V_121 , V_36 = F_39 ( V_108 ) ) ;
V_67 -> V_101 = V_108 ;
F_8 ( V_53 -> V_128 -> V_73 -> V_129 . V_130 ) ;
V_36 = F_58 ( V_93 , V_33 , V_53 -> V_128 -> V_73 ) ;
if ( V_36 )
GOTO ( V_131 , V_36 ) ;
F_74 ( V_33 , L_29 , V_33 ) ;
V_131:
if ( V_36 ) {
F_75 ( V_93 , & V_67 -> V_101 -> V_127 ) ;
V_67 -> V_101 = NULL ;
}
V_121:
if ( V_36 < 0 ) {
F_76 ( V_93 , V_67 -> V_117 ) ;
V_67 -> V_117 = NULL ;
F_77 ( & V_67 -> V_110 ) ;
}
V_118:
F_78 ( V_93 ) ;
V_112:
F_79 ( V_93 ) ;
return V_36 ;
}
static int F_80 ( struct V_32 * V_33 )
{
struct V_92 V_93 ;
struct V_102 * V_67 = & V_33 -> V_66 . V_67 ;
int V_36 ;
F_8 ( V_67 -> V_117 != NULL ) ;
V_36 = F_68 ( & V_93 , V_111 ) ;
if ( V_36 )
GOTO ( V_132 , V_36 ) ;
F_62 ( & V_93 , V_33 ) ;
F_73 ( & V_93 , & V_67 -> V_101 -> V_127 ) ;
V_67 -> V_101 = NULL ;
F_76 ( & V_93 , V_67 -> V_117 ) ;
V_67 -> V_117 = NULL ;
F_78 ( & V_93 ) ;
V_132:
F_81 ( V_33 , L_29 , V_33 ) ;
F_77 ( & V_67 -> V_110 ) ;
return 0 ;
}
static int F_82 ( const struct V_92 * V_93 , struct V_32 * V_33 )
{
struct V_95 * V_96 ;
int V_36 ;
V_36 = F_59 ( V_93 , V_33 , & V_33 -> V_97 , V_133 , V_33 ,
& V_134 ) ;
if ( V_36 )
return V_36 ;
V_96 = F_60 ( V_33 , V_133 ) ;
F_8 ( V_96 ) ;
F_83 ( V_96 ) ;
F_61 ( V_96 ) ;
return 0 ;
}
static int F_84 ( const struct V_92 * V_93 , struct V_32 * V_33 )
{
struct V_95 * V_96 ;
V_96 = F_60 ( V_33 , V_133 ) ;
if ( V_96 )
F_63 ( V_93 , V_96 ) ;
return 0 ;
}
static int F_85 ( struct V_32 * V_33 , enum V_135 V_136 )
{
int V_36 = 0 ;
switch ( V_136 ) {
case V_137 :
break;
case V_138 :
if ( F_86 ( & V_139 ) ) {
int V_140 ;
F_21 ( & V_20 ) ;
V_140 = V_76 & V_77 ;
if ( V_140 )
V_76 |= V_83 ;
F_15 ( & V_20 ) ;
if ( V_140 ) {
F_57 ( & V_89 ) ;
F_87 ( & V_91 ) ;
}
}
F_88 ( V_33 ) ;
V_36 = F_84 ( NULL , V_33 ) ;
if ( V_36 != 0 )
F_2 ( L_30 ) ;
break;
}
return V_36 ;
}
static int F_89 ( struct V_32 * V_33 )
{
int V_36 ;
if ( V_33 -> V_141 -> V_142 <= 1 )
F_90 () ;
F_91 ( V_33 ) ;
F_92 () ;
V_36 = F_93 ( V_33 ) ;
return V_36 ;
}
static int F_94 ( struct V_32 * V_33 , struct V_143 * V_51 )
{
struct V_144 V_145 ;
int V_36 ;
F_95 () ;
V_36 = F_96 ( V_33 , V_51 ) ;
if ( V_36 )
GOTO ( V_146 , V_36 ) ;
V_36 = F_82 ( NULL , V_33 ) ;
if ( V_36 ) {
F_2 ( L_31 ) ;
GOTO ( V_147 , V_36 ) ;
}
F_97 ( & V_145 ) ;
F_98 ( V_33 , V_145 . V_148 ) ;
F_99 ( V_33 ) ;
if ( F_100 ( & V_139 ) == 1 ) {
V_76 = 0 ;
F_101 ( & V_89 ) ;
V_36 = F_39 ( F_102 ( F_50 , NULL ,
L_32 ) ) ;
if ( F_103 ( V_36 ) ) {
F_2 ( L_33
L_34 ,
V_33 -> V_47 , V_36 ) ;
GOTO ( V_147 , V_36 ) ;
}
V_36 = 0 ;
}
return V_36 ;
V_147:
F_93 ( V_33 ) ;
V_146:
F_92 () ;
return V_36 ;
}
static int F_104 ( struct V_149 * V_150 , struct V_151 * V_152 ,
void * V_63 , int V_153 )
{
struct V_154 V_155 ;
struct V_15 * V_16 = (struct V_15 * ) V_63 ;
int V_36 = 0 ;
switch ( V_153 ) {
case V_156 :
F_105 ( V_150 , L_35 ) ;
F_106 ( V_150 , & V_155 ) ;
V_36 = F_107 ( & V_155 , V_157 ) ;
break;
case V_158 :
F_105 ( V_150 , L_36 ) ;
F_5 ( V_10 , L_37 V_159 L_5 ,
F_108 ( V_150 -> V_160 ) ,
( char * ) & V_150 -> V_160 -> V_161 . V_1 [ 0 ] ) ;
if ( ! V_16 ) {
F_5 ( V_18 , L_38 ) ;
break;
}
F_8 ( F_11 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_16 -> V_31 ) {
F_5 ( V_10 , L_39 ,
V_16 -> V_19 ) ;
F_12 ( V_16 ) ;
break;
}
if ( ! V_150 -> V_162 ||
! V_150 -> V_162 -> V_73 -> V_66 . V_67 . V_75 ) {
F_5 ( V_10 , L_40 ,
V_16 -> V_19 ) ;
F_12 ( V_16 ) ;
break;
}
F_56 ( V_16 ) ;
F_12 ( V_16 ) ;
break;
default:
F_4 () ;
}
return V_36 ;
}
static int F_109 ( struct V_163 * exp ,
struct V_164 * V_165 )
{
struct V_166 * V_167 ;
struct V_164 * V_168 , * V_169 ;
int V_36 ;
V_167 = F_110 ( F_111 ( exp ) ,
& V_170 , V_171 ,
V_172 ) ;
if ( ! V_167 )
return - V_37 ;
V_168 = F_112 ( & V_167 -> V_173 , & V_174 ) ;
if ( ! V_168 ) {
F_113 ( V_167 ) ;
return - V_37 ;
}
memcpy ( V_168 , V_165 , sizeof( * V_168 ) ) ;
F_114 ( V_167 ) ;
V_167 -> V_175 = V_176 ;
V_36 = F_115 ( V_167 ) ;
if ( ! V_36 ) {
V_169 = F_116 ( & V_167 -> V_173 , & V_174 ) ;
memcpy ( V_165 , V_169 , sizeof( * V_169 ) ) ;
}
F_113 ( V_167 ) ;
return V_36 ;
}
static int F_117 ( struct V_163 * exp , struct V_177 * V_178 ,
T_2 type , T_3 * V_179 , T_2 V_180 ,
T_1 * V_181 , void * V_182 , void * V_183 , void * V_184 ,
void * V_63 , T_2 V_185 , void * V_186 ,
struct V_154 * V_155 )
{
struct V_15 * V_16 = (struct V_15 * ) V_63 ;
struct V_187 V_188 = {
. V_189 = type ,
. V_190 = V_180 ,
. V_191 = F_104 ,
. V_192 = V_193 ,
} ;
struct V_166 * V_167 ;
int V_194 = F_16 ( V_16 ) ;
int V_36 ;
F_5 ( V_10 , L_41 V_11 L_42 , V_16 -> V_19 ,
V_16 -> V_48 . V_1 [ 0 ] ) ;
V_167 = F_110 ( F_111 ( exp ) ,
& V_195 , V_196 ,
V_197 ) ;
if ( V_167 == NULL )
return - V_37 ;
F_118 ( & V_167 -> V_173 , & V_198 , V_199 , 0 ) ;
F_114 ( V_167 ) ;
if ( V_16 -> V_30 . V_43 ) {
struct V_52 * V_53 = F_33 ( V_16 -> V_30 . V_43 ) ;
if ( V_53 && F_36 ( V_53 ) )
V_194 = 1 ;
}
V_167 -> V_175 = V_194 ? 5 : V_200 ;
V_36 = F_119 ( exp , & V_167 , & V_188 , & V_16 -> V_48 , NULL , V_181 ,
NULL , 0 , V_201 , V_155 , 0 ) ;
F_113 ( V_167 ) ;
return V_36 ;
}
static int F_120 ( struct V_163 * exp , struct V_177 * V_202 ,
T_2 V_180 , struct V_154 * V_155 )
{
F_121 ( V_155 , V_180 ) ;
return 0 ;
}
static void F_122 ( struct V_32 * V_203 )
{
F_21 ( & V_20 ) ;
V_76 |= V_85 ;
F_15 ( & V_20 ) ;
F_57 ( & V_89 ) ;
}
static int F_123 ( struct V_163 * exp ,
struct V_204 * V_205 )
{
struct V_166 * V_167 ;
struct V_204 * V_206 , * V_207 ;
int V_36 ;
V_167 = F_110 ( F_111 ( exp ) ,
& V_208 , V_171 ,
V_209 ) ;
if ( V_167 == NULL )
return - V_37 ;
V_206 = F_112 ( & V_167 -> V_173 , & V_210 ) ;
if ( ! V_206 ) {
F_113 ( V_167 ) ;
return - V_37 ;
}
memcpy ( V_206 , V_205 , sizeof( * V_206 ) ) ;
F_114 ( V_167 ) ;
F_5 ( V_10 , L_43 , V_205 -> V_211 ) ;
V_167 -> V_175 = V_212 ;
V_36 = F_115 ( V_167 ) ;
if ( ! V_36 ) {
V_207 = F_116 ( & V_167 -> V_173 ,
& V_210 ) ;
memcpy ( V_205 , V_207 , sizeof( * V_207 ) ) ;
F_5 ( V_10 , L_44 ,
V_205 -> V_211 , V_205 -> V_213 ) ;
}
F_113 ( V_167 ) ;
return V_36 ;
}
int F_124 ( const struct V_92 * V_93 , struct V_163 * exp ,
T_4 V_214 , void * V_215 , T_4 V_216 ,
void * V_217 , struct V_218 * V_219 )
{
int V_36 = - V_6 ;
if ( F_125 ( V_220 ) ) {
struct V_64 * V_65 = F_111 ( exp ) ;
int V_221 ;
if ( V_216 != sizeof( int ) )
return - V_6 ;
V_221 = * ( int * ) V_217 ;
F_5 ( V_10 , L_45 ,
V_65 -> V_222 -> V_47 , V_221 ,
V_65 -> V_223 , V_65 -> V_224 ,
V_65 -> V_225 , V_65 -> V_222 -> V_226 ,
F_126 ( V_65 -> V_227 ) ) ;
if ( ( V_65 -> V_227 != V_228 &&
V_65 -> V_227 != V_229 ) || V_221 > 1 )
F_127 ( V_65 ) ;
return 0 ;
}
if ( F_125 ( V_230 ) ) {
struct V_204 * V_205 ;
if ( V_216 != sizeof( struct V_204 ) )
return - V_6 ;
V_205 = (struct V_204 * ) V_217 ;
F_5 ( V_10 , L_46 ,
V_205 -> V_211 , V_205 -> V_231 ) ;
V_36 = F_123 ( exp , V_205 ) ;
return V_36 ;
}
if ( F_125 ( V_232 ) ) {
struct V_34 * V_35 = (struct V_34 * ) V_217 ;
if ( V_216 != sizeof( struct V_34 ) )
return - V_6 ;
V_36 = F_64 ( exp -> V_73 , V_35 ) ;
if ( V_36 )
F_2 ( L_47 , V_36 ) ;
return V_36 ;
}
if ( F_125 ( V_233 ) ) {
if ( V_216 != 0 )
return - V_6 ;
V_36 = F_80 ( exp -> V_73 ) ;
if ( V_36 )
F_2 ( L_48 , V_36 ) ;
return V_36 ;
}
if ( F_125 ( V_234 ) ) {
struct V_164 * V_165 ;
V_165 = (struct V_164 * ) V_217 ;
V_36 = F_109 ( exp , V_165 ) ;
return V_36 ;
}
if ( F_125 ( V_235 ) ) {
struct V_102 * V_67 = & exp -> V_73 -> V_66 . V_67 ;
struct V_236 V_237 ;
if ( V_216 == 0 ) {
if ( V_67 -> V_238 . V_239 != V_240 )
return 0 ;
V_217 = L_49 ;
V_216 = 4 ;
}
V_36 = F_128 ( V_217 , & V_237 ) ;
if ( V_36 ) {
F_2 ( L_50 ,
( char * ) V_217 ) ;
return V_36 ;
}
if ( V_67 -> V_238 . V_239 == V_240 ) {
V_67 -> V_238 = V_237 ;
} else if ( memcmp ( & V_67 -> V_238 , & V_237 ,
sizeof( V_237 ) ) != 0 ) {
char V_241 [ 20 ] ;
F_129 ( & V_67 -> V_238 ,
V_241 , sizeof( V_241 ) ) ;
F_130 ( L_51
L_52 ,
( char * ) V_217 , V_241 ) ;
V_36 = - V_242 ;
}
return V_36 ;
}
return V_36 ;
}
static int F_131 ( const struct V_92 * V_93 , struct V_163 * exp ,
T_2 V_214 , void * V_215 , T_2 * V_216 , void * V_217 ,
struct V_177 * V_203 )
{
int V_36 = - V_6 ;
if ( F_125 ( V_243 ) ) {
struct V_64 * V_65 = F_111 ( exp ) ;
struct V_69 * V_63 = V_217 ;
if ( * V_216 == sizeof( * V_63 ) ) {
* V_63 = V_65 -> V_71 ;
V_36 = 0 ;
}
}
return V_36 ;
}
static int F_132 ( struct V_32 * V_33 ,
struct V_64 * V_65 ,
enum V_244 V_245 )
{
int V_36 = 0 ;
F_8 ( V_65 -> V_222 == V_33 ) ;
F_5 ( V_10 , L_53 , V_245 ) ;
switch ( V_245 ) {
case V_246 :
if ( F_46 ( & V_65 -> V_71 , V_72 ) )
F_133 () ;
break;
case V_247 :
break;
case V_248 : {
struct V_249 * V_250 = V_33 -> V_251 ;
F_134 ( V_250 , V_252 ) ;
break;
}
case V_253 :
F_5 ( V_18 , L_54 , V_33 -> V_47 ) ;
V_33 -> V_254 = 0 ;
F_122 ( V_33 ) ;
if ( F_46 ( & V_65 -> V_71 , V_72 ) )
F_135 () ;
break;
case V_255 :
break;
case V_256 :
case V_257 :
break;
default:
F_2 ( L_55 , V_245 ) ;
F_4 () ;
}
return V_36 ;
}
static int F_136 ( struct V_32 * V_258 ,
struct V_15 * V_16 ,
T_1 V_259 ,
void * V_63 , int V_260 , bool V_261 )
{
struct V_25 * V_26 = & V_16 -> V_30 ;
struct V_52 * V_53 = F_33 ( V_26 -> V_43 ) ;
struct V_262 * V_263 ;
struct V_143 * V_51 ;
struct V_264 V_265 ;
T_5 V_266 = 0 ;
char * V_267 ;
char * V_268 ;
int V_269 ;
int V_270 ;
int V_36 = 0 ;
int V_271 = 0 ;
F_8 ( V_26 -> V_29 != NULL ) ;
F_8 ( V_26 -> V_43 == V_26 -> V_29 ) ;
F_24 ( V_267 , V_272 ) ;
if ( V_267 == NULL )
return - V_37 ;
if ( ! F_36 ( V_53 ) ) {
V_270 = snprintf ( V_267 , V_272 , L_56 , V_26 -> V_29 ) ;
if ( V_270 >= V_272 ) {
F_19 ( V_267 , V_272 ) ;
return - V_273 ;
}
} else {
F_8 ( F_35 ( V_53 ) ) ;
V_36 = F_137 ( V_53 -> V_274 , V_267 , NULL ,
V_272 ) ;
if ( V_36 ) {
F_19 ( V_267 , V_272 ) ;
return - V_6 ;
}
V_270 = strlen ( V_267 ) ;
}
++ V_270 ;
V_268 = V_267 + V_270 ;
V_269 = V_272 - V_270 ;
while ( V_260 > 0 ) {
int V_275 = sizeof( * V_263 ) ;
int V_276 ;
struct V_32 * V_33 ;
char * V_277 ;
char * V_278 ;
char * V_279 ;
char * V_280 ;
V_36 = - V_6 ;
if ( V_260 < sizeof( * V_263 ) )
break;
V_263 = ( F_138 ( V_263 ) ) ( V_63 + V_271 ) ;
if ( V_263 -> V_281 != 0 )
break;
if ( V_263 -> V_282 == 0 )
break;
if ( V_263 -> V_283 != sizeof( V_284 ) )
break;
V_275 += V_263 -> V_282 * V_263 -> V_283 ;
if ( V_260 < V_275 )
break;
if ( V_261 )
F_139 ( V_263 ) ;
if ( V_263 -> V_285 > V_272 ) {
F_2 ( L_57 , V_263 -> V_285 ) ;
break;
}
if ( V_263 -> V_285 < V_275 )
break;
V_271 += V_263 -> V_285 ;
V_260 -= V_263 -> V_285 ;
if ( V_260 < 0 )
break;
if ( V_263 -> V_286 > V_259 ) {
F_2 ( L_58 ,
V_263 -> V_286 , V_259 ) ;
break;
}
if ( V_266 >= V_263 -> V_286 ) {
F_2 ( L_59 ,
V_266 , V_263 -> V_286 ) ;
break;
}
V_266 = V_263 -> V_286 ;
V_276 = V_263 -> V_287 == V_288 ;
memset ( V_268 , 0 , V_269 ) ;
V_277 = V_268 ;
V_270 = 0 ;
strcpy ( V_277 , V_16 -> V_19 ) ;
V_278 = strrchr ( V_277 , '-' ) ;
if ( V_278 == NULL ) {
F_2 ( L_60 ,
V_258 -> V_47 , V_277 ) ;
break;
}
V_270 = V_278 - V_277 ;
V_277 [ V_270 ] = 0 ;
V_270 += sprintf ( V_277 + V_270 , L_61 ,
V_276 ? L_62 : L_63 , V_263 -> V_289 ) ;
V_278 = V_276 ? L_64 : L_65 ,
V_270 += sprintf ( V_277 + V_270 , L_66 , V_278 , V_267 ) ;
F_140 ( & V_265 , V_277 ) ;
V_33 = F_141 ( V_277 ) ;
if ( V_33 == NULL ) {
F_5 ( V_18 , L_67 ,
V_258 -> V_47 , V_277 ) ;
V_36 = 0 ;
continue;
}
++ V_270 ;
V_279 = V_268 + V_270 ;
V_270 += sprintf ( V_279 , L_68 , V_278 , L_69 ) ;
V_280 = V_268 + V_270 ;
F_48 ( & V_33 -> V_66 . V_67 . V_74 ) ;
if ( V_33 -> V_66 . V_67 . V_68 == NULL ) {
F_49 ( & V_33 -> V_66 . V_67 . V_74 ) ;
V_36 = 0 ;
continue;
}
V_36 = F_142 ( V_33 -> V_66 . V_67 . V_68 ,
V_263 -> V_66 . V_290 [ 0 ] ,
(struct V_291 * ) V_280 ) ;
F_49 ( & V_33 -> V_66 . V_67 . V_74 ) ;
if ( V_36 < 0 ) {
F_2 ( L_70 ,
F_143 ( V_263 -> V_66 . V_290 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_71 ,
V_280 , F_143 ( V_263 -> V_66 . V_290 [ 0 ] ) ) ;
V_270 += strlen ( V_280 ) ;
V_270 += sprintf ( V_268 + V_270 , L_72 , V_263 -> V_292 ) ;
F_8 ( V_270 < V_269 ) ;
F_144 ( & V_265 , 1 , V_279 ) ;
V_36 = - V_37 ;
V_51 = F_145 ( V_293 , & V_265 ) ;
if ( V_51 == NULL ) {
F_2 ( L_73 ) ;
break;
}
F_5 ( V_18 , L_74 V_294 L_4 V_294 L_75 ,
V_266 , V_259 , V_277 , V_279 ) ;
V_36 = F_146 ( V_51 ) ;
F_147 ( V_51 ) ;
if ( V_36 )
F_5 ( V_18 , L_76 ,
V_277 , V_36 ) ;
}
F_19 ( V_267 , V_272 ) ;
return V_36 ;
}
static int F_148 ( struct V_32 * V_33 ,
struct V_15 * V_16 )
{
struct V_166 * V_167 = NULL ;
struct V_25 * V_26 = & V_16 -> V_30 ;
struct V_295 * V_296 ;
struct V_297 * V_298 ;
struct V_299 * V_152 ;
struct V_300 * * V_301 ;
int V_302 ;
bool V_303 = true ;
bool V_261 = false ;
int V_304 ;
int V_305 ;
int V_36 ;
V_302 = V_306 ;
if ( V_26 -> V_41 == 0 )
V_302 = V_307 ;
F_24 ( V_301 , sizeof( * V_301 ) * V_302 ) ;
if ( V_301 == NULL )
GOTO ( V_308 , V_36 = - V_37 ) ;
for ( V_304 = 0 ; V_304 < V_302 ; V_304 ++ ) {
V_301 [ V_304 ] = F_149 ( V_309 ) ;
if ( V_301 [ V_304 ] == NULL )
GOTO ( V_308 , V_36 = - V_37 ) ;
}
V_310:
F_8 ( F_150 ( V_16 ) ) ;
F_8 ( F_151 ( & V_16 -> V_40 ) ) ;
V_167 = F_152 ( F_111 ( V_16 -> V_24 ) ,
& V_311 ) ;
if ( V_167 == NULL )
GOTO ( V_308 , V_36 = - V_37 ) ;
V_36 = F_153 ( V_167 , V_171 , V_312 ) ;
if ( V_36 )
GOTO ( V_308 , V_36 ) ;
V_296 = F_112 ( & V_167 -> V_173 , & V_313 ) ;
F_8 ( V_296 != NULL ) ;
F_8 ( sizeof( V_296 -> V_314 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_154 ( V_296 -> V_314 , V_16 -> V_19 , sizeof( V_296 -> V_314 ) )
>= sizeof( V_296 -> V_314 ) )
GOTO ( V_308 , V_36 = - V_273 ) ;
V_296 -> V_315 = V_26 -> V_41 + 1 ;
V_296 -> V_316 = V_16 -> V_44 ;
V_296 -> V_317 = V_318 ;
V_296 -> V_319 = V_302 ;
V_152 = F_155 ( V_167 , V_302 , 1 , V_320 ,
V_321 ) ;
if ( V_152 == NULL )
GOTO ( V_308 , V_36 = - V_37 ) ;
for ( V_304 = 0 ; V_304 < V_302 ; V_304 ++ )
F_156 ( V_152 , V_301 [ V_304 ] , 0 , V_272 ) ;
F_114 ( V_167 ) ;
V_36 = F_115 ( V_167 ) ;
if ( V_36 )
GOTO ( V_308 , V_36 ) ;
V_298 = F_116 ( & V_167 -> V_173 , & V_322 ) ;
if ( V_298 -> V_323 < V_298 -> V_324 )
GOTO ( V_308 , V_36 = - V_6 ) ;
V_26 -> V_41 = V_298 -> V_324 ;
V_303 = V_298 -> V_324 == V_298 -> V_323 ;
F_5 ( V_18 , L_77 V_294 L_78 ,
V_298 -> V_324 , V_303 == false ) ;
V_305 = F_157 ( V_167 , V_167 -> V_325 , 0 ) ;
if ( V_305 < 0 )
GOTO ( V_308 , V_36 = V_305 ) ;
if ( V_305 > V_302 << V_318 )
GOTO ( V_308 , V_36 = - V_6 ) ;
if ( V_305 == 0 ) {
if ( ! V_303 )
V_36 = - V_6 ;
GOTO ( V_308 , V_36 ) ;
}
V_261 = ! ! F_158 ( V_167 ) ;
#if V_326 < F_159 ( 3 , 2 , 50 , 0 )
if ( F_42 ( V_167 -> V_327 -> V_328 ) )
V_261 = ! V_261 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_304 = 0 ; V_304 < V_302 && V_305 > 0 ; V_304 ++ ) {
int V_329 ;
void * V_56 ;
V_56 = F_160 ( V_301 [ V_304 ] ) ;
V_329 = F_136 ( V_33 , V_16 , V_298 -> V_324 , V_56 ,
F_161 ( int , V_305 , V_272 ) ,
V_261 ) ;
F_162 ( V_301 [ V_304 ] ) ;
if ( V_329 < 0 ) {
F_163 ( L_79 ,
V_16 -> V_19 , V_329 ) ;
break;
}
V_305 -= V_272 ;
}
V_308:
if ( V_167 )
F_113 ( V_167 ) ;
if ( V_36 == 0 && ! V_303 )
goto V_310;
if ( V_301 ) {
for ( V_304 = 0 ; V_304 < V_302 ; V_304 ++ ) {
if ( V_301 [ V_304 ] == NULL )
break;
F_164 ( V_301 [ V_304 ] ) ;
}
F_19 ( V_301 , sizeof( * V_301 ) * V_302 ) ;
}
return V_36 ;
}
static int F_165 ( const struct V_92 * V_93 ,
struct V_32 * V_33 ,
struct V_95 * V_330 ,
struct V_95 * V_331 , char * V_13 )
{
char * V_332 ;
int V_36 ;
F_24 ( V_332 , strlen ( V_13 ) + 1 ) ;
if ( ! V_332 )
return - V_37 ;
sprintf ( V_332 , L_80 , V_13 ) ;
V_36 = F_166 ( V_93 , V_33 , V_331 , V_331 , V_13 , V_332 ) ;
if ( V_36 < 0 && V_36 != - V_50 )
GOTO ( V_308 , V_36 ) ;
V_36 = F_166 ( V_93 , V_33 , V_330 , V_331 , V_13 , V_13 ) ;
if ( V_36 == - V_50 ) {
F_167 ( V_93 , V_331 , NULL , V_13 ) ;
} else if ( V_36 < 0 ) {
F_166 ( V_93 , V_33 , V_331 , V_331 , V_332 , V_13 ) ;
V_308:
F_2 ( L_81 ,
V_33 -> V_47 , V_13 , V_36 ) ;
}
F_167 ( V_93 , V_331 , NULL , V_332 ) ;
F_19 ( V_332 , strlen ( V_13 ) + 1 ) ;
return V_36 ;
}
static int F_168 ( struct V_32 * V_258 ,
struct V_15 * V_16 , int V_333 )
{
struct V_95 * V_96 , * V_331 = NULL ;
struct V_106 * V_334 = V_258 -> V_66 . V_67 . V_101 ;
struct V_52 * V_53 = NULL ;
int V_36 = 0 ;
bool V_335 = false ;
struct V_92 * V_93 ;
F_8 ( V_16 ) ;
F_8 ( F_151 ( & V_16 -> V_40 ) ) ;
if ( F_16 ( V_16 ) && V_333 )
return 0 ;
if ( V_16 -> V_30 . V_43 )
V_53 = F_33 ( V_16 -> V_30 . V_43 ) ;
F_65 ( V_93 ) ;
if ( V_93 == NULL )
return - V_37 ;
V_36 = F_68 ( V_93 , V_111 ) ;
if ( V_36 )
GOTO ( V_336 , V_36 ) ;
V_96 = F_60 ( V_258 , V_133 ) ;
F_8 ( V_96 ) ;
V_331 = F_60 ( V_258 , V_98 ) ;
if ( V_331 && V_53 && F_36 ( V_53 ) && ! F_169 ( V_53 ) &&
V_334 != NULL &&
F_170 ( V_334 -> V_127 . V_337 ) == V_53 -> V_109 ) {
if ( ! V_333 )
V_36 = F_165 ( V_93 , V_258 , V_96 , V_331 ,
V_16 -> V_19 ) ;
if ( V_333 || V_36 ) {
if ( F_171 ( V_93 , V_331 , V_16 -> V_19 ) ) {
F_172 ( 0x13a ,
L_82 ,
V_16 -> V_19 ) ;
GOTO ( V_338 , V_36 = - V_339 ) ;
}
F_5 ( V_10 ,
L_83 ,
V_16 -> V_19 ) ;
}
F_61 ( V_96 ) ;
V_96 = V_331 ;
V_331 = NULL ;
} else {
if ( V_333 )
GOTO ( V_338 , V_36 = - V_340 ) ;
}
if ( F_16 ( V_16 ) ) {
F_173 ( V_16 -> V_19 ) ;
V_335 = true ;
}
V_36 = F_174 ( V_93 , V_96 , V_16 -> V_19 ,
& V_16 -> V_30 ) ;
V_338:
F_175 ( V_93 , V_96 ) ;
if ( V_331 )
F_175 ( V_93 , V_331 ) ;
if ( V_335 ) {
F_8 ( F_16 ( V_16 ) ) ;
F_176 ( V_16 -> V_19 ) ;
F_177 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_14 ) ) ;
}
F_78 ( V_93 ) ;
V_336:
F_79 ( V_93 ) ;
return V_36 ;
}
int F_31 ( struct V_32 * V_258 , struct V_15 * V_16 )
{
struct V_154 V_155 = { 0 } ;
T_1 V_181 = V_341 ;
int V_36 = 0 , V_342 ;
F_8 ( V_16 ) ;
F_41 ( & V_16 -> V_40 ) ;
if ( V_16 -> V_31 ) {
F_43 ( & V_16 -> V_40 ) ;
return 0 ;
}
F_178 ( V_343 , 20 ) ;
F_5 ( V_10 , L_84 , V_16 -> V_19 ,
V_16 -> V_30 . V_29 , V_16 -> V_30 . V_41 + 1 ) ;
V_342 = F_117 ( V_258 -> V_66 . V_67 . V_344 , NULL , V_345 , NULL ,
V_346 , & V_181 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_155 ) ;
if ( V_342 == 0 ) {
F_9 ( V_16 ) ;
V_36 = F_179 ( & V_155 , ( void * ) V_16 ) ;
F_8 ( V_36 == 0 ) ;
} else {
F_5 ( V_10 , L_85 , V_342 ) ;
V_16 -> V_90 = 1 ;
F_9 ( V_16 ) ;
}
if ( F_150 ( V_16 ) ) {
V_36 = 0 ;
if ( V_342 == 0 )
V_36 = F_148 ( V_258 , V_16 ) ;
} else {
V_36 = F_168 ( V_258 , V_16 , V_342 != 0 ) ;
}
F_5 ( V_10 , L_86 ,
V_258 -> V_47 , V_16 -> V_19 , V_36 ? L_87 : L_88 , V_36 ) ;
F_43 ( & V_16 -> V_40 ) ;
if ( ! V_342 ) {
V_342 = F_120 ( V_258 -> V_66 . V_67 . V_344 , NULL ,
V_346 , & V_155 ) ;
if ( V_342 )
F_2 ( L_89 , V_342 ) ;
}
return V_36 ;
}
static int F_180 ( struct V_32 * V_33 , T_4 V_2 , void * V_268 )
{
struct V_143 * V_51 = V_268 ;
struct V_25 * V_26 = NULL ;
char * V_13 ;
int V_36 = 0 ;
switch ( V_51 -> V_347 ) {
case V_348 : {
struct V_204 * V_205 ;
if ( F_181 ( V_51 , 1 ) !=
sizeof( struct V_204 ) )
GOTO ( V_308 , V_36 = - V_6 ) ;
V_205 = (struct V_204 * ) F_182 ( V_51 , 1 ) ;
F_5 ( V_10 , L_90 ,
V_205 -> V_211 , V_205 -> V_231 ) ;
V_36 = F_123 ( V_33 -> V_66 . V_67 . V_344 , V_205 ) ;
break;
}
case V_349 :
F_2 ( L_91 ) ;
V_36 = - V_350 ;
break;
case V_351 : {
V_36 = F_183 ( V_51 ) ;
break;
}
case V_352 : {
struct V_15 * V_16 ;
struct V_34 * V_35 ;
V_13 = F_184 ( V_51 , 1 ) ;
V_26 = (struct V_25 * ) F_182 ( V_51 , 2 ) ;
V_35 = * (struct V_34 * * ) F_182 ( V_51 , 3 ) ;
F_5 ( V_10 , L_92 , V_13 ,
V_26 -> V_41 ) ;
V_36 = F_37 ( V_33 , V_13 , V_26 , V_35 ) ;
if ( V_36 )
break;
V_16 = F_20 ( V_13 , V_26 ) ;
if ( V_16 == NULL ) {
V_36 = - V_50 ;
break;
}
V_16 -> V_30 . V_42 |= V_353 ;
V_36 = F_31 ( V_33 , V_16 ) ;
if ( V_36 == 0 && V_16 -> V_22 != NULL ) {
if ( F_46 ( & V_33 -> V_66 . V_67 . V_68 ->
V_71 , V_72 ) ) {
V_36 = F_31 ( V_33 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_354 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_12 ( V_354 ) ;
}
if ( V_36 )
F_2 ( L_93 , V_36 ) ;
}
F_12 ( V_16 ) ;
break;
}
case V_355 : {
V_13 = F_184 ( V_51 , 1 ) ;
if ( V_51 -> V_356 >= 2 )
V_26 = (struct V_25 * ) F_182 (
V_51 , 2 ) ;
V_36 = F_40 ( V_13 , V_26 ) ;
break;
}
default: {
F_2 ( L_94 , V_51 -> V_347 ) ;
GOTO ( V_308 , V_36 = - V_6 ) ;
}
}
V_308:
return V_36 ;
}
int T_6 F_185 ( void )
{
return F_186 ( & V_357 , NULL , NULL ,
V_358 , NULL ) ;
}
static void F_187 ( void )
{
F_188 ( V_358 ) ;
}
