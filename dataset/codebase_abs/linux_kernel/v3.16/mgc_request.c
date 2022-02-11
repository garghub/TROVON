static int F_1 ( char * V_1 , int V_2 , struct V_3 * V_4 ,
int type )
{
T_1 V_5 = 0 ;
if ( V_2 > sizeof( V_5 ) ) {
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
case V_10 :
V_5 = type ;
break;
default:
F_4 () ;
}
V_4 -> V_1 [ 1 ] = F_3 ( V_5 ) ;
F_5 ( V_11 , L_3 V_12 L_4 V_12 L_5 , V_1 ,
V_4 -> V_1 [ 0 ] , V_4 -> V_1 [ 1 ] , ( char * ) & V_4 -> V_1 [ 0 ] ) ;
return 0 ;
}
int F_6 ( char * V_13 , struct V_3 * V_4 , int type )
{
return F_1 ( V_13 , strlen ( V_13 ) , V_4 , type ) ;
}
int F_7 ( char * V_14 , struct V_3 * V_4 , int type )
{
char * V_15 ;
int V_2 ;
V_15 = strrchr ( V_14 , '-' ) ;
if ( ! V_15 )
V_2 = strlen ( V_14 ) ;
else
V_2 = V_15 - V_14 ;
return F_1 ( V_14 , V_2 , V_4 , type ) ;
}
static int F_8 ( struct V_16 * V_17 )
{
F_9 ( & V_17 -> V_18 ) ;
F_5 ( V_19 , L_6 , V_17 -> V_20 ,
F_10 ( & V_17 -> V_18 ) ) ;
return 0 ;
}
static void F_11 ( struct V_16 * V_17 )
{
F_5 ( V_19 , L_6 , V_17 -> V_20 ,
F_10 ( & V_17 -> V_18 ) ) ;
F_12 ( F_10 ( & V_17 -> V_18 ) > 0 ) ;
if ( F_13 ( & V_17 -> V_18 , & V_21 ) ) {
F_14 ( & V_17 -> V_22 ) ;
F_15 ( & V_21 ) ;
F_5 ( V_11 , L_7 , V_17 -> V_20 ) ;
if ( V_17 -> V_23 )
F_11 ( V_17 -> V_23 ) ;
if ( V_17 -> V_24 )
F_11 ( V_17 -> V_24 ) ;
if ( V_17 -> V_25 )
F_11 ( V_17 -> V_25 ) ;
if ( F_16 ( V_17 ) )
F_17 ( V_17 -> V_20 ) ;
F_18 ( V_17 -> V_26 ) ;
F_19 ( V_17 , sizeof( * V_17 ) + strlen ( V_17 -> V_20 ) + 1 ) ;
}
}
static
struct V_16 * F_20 ( char * V_14 ,
struct V_27 * V_28 )
{
struct V_16 * V_17 ;
struct V_16 * V_29 = NULL ;
void * V_30 ;
F_12 ( V_14 != NULL ) ;
V_30 = V_28 ? V_28 -> V_31 : NULL ;
F_21 ( & V_21 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_30 != V_17 -> V_32 . V_31 )
continue;
if ( strcmp ( V_14 , V_17 -> V_20 ) == 0 ) {
V_29 = V_17 ;
break;
}
}
if ( V_29 ) {
F_9 ( & V_29 -> V_18 ) ;
F_12 ( V_29 -> V_33 == 0 || F_16 ( V_29 ) == 0 ) ;
}
F_15 ( & V_21 ) ;
return V_29 ;
}
static
struct V_16 * F_23 ( struct V_34 * V_35 ,
char * V_14 ,
int type ,
struct V_27 * V_28 ,
struct V_36 * V_37 )
{
struct V_16 * V_17 ;
int V_38 ;
F_5 ( V_11 , L_8 , V_14 ,
V_28 ? V_28 -> V_31 : 0 ) ;
F_24 ( V_17 , sizeof( * V_17 ) + strlen ( V_14 ) + 1 ) ;
if ( ! V_17 )
return F_25 ( - V_39 ) ;
strcpy ( V_17 -> V_20 , V_14 ) ;
if ( V_28 )
V_17 -> V_32 = * V_28 ;
else
V_17 -> V_32 . V_40 = V_41 ;
F_26 ( & V_17 -> V_42 ) ;
V_17 -> V_32 . V_43 = 0 ;
V_17 -> V_32 . V_44 = 0 ;
V_17 -> V_32 . V_45 = V_37 ;
V_17 -> V_46 = type ;
F_27 ( & V_17 -> V_18 , 1 ) ;
V_17 -> V_26 = F_28 ( V_35 -> V_47 ) ;
if ( F_16 ( V_17 ) ) {
F_29 ( V_14 ) ;
V_17 -> V_32 . V_48 = V_35 -> V_49 ;
}
V_38 = F_7 ( V_14 , & V_17 -> V_50 , type ) ;
F_21 ( & V_21 ) ;
F_30 ( & V_17 -> V_22 , & V_51 ) ;
F_15 ( & V_21 ) ;
if ( V_38 ) {
F_11 ( V_17 ) ;
return F_25 ( V_38 ) ;
}
if ( F_16 ( V_17 ) ) {
V_38 = F_31 ( V_35 , V_17 ) ;
if ( V_38 && V_38 != - V_52 )
F_2 ( L_9 , V_38 ) ;
}
return V_17 ;
}
static struct V_16 * F_32 ( struct V_34 * V_35 ,
char * V_13 ,
struct V_27 * V_28 ,
struct V_36 * V_37 )
{
struct V_27 V_53 = * V_28 ;
struct V_54 * V_55 = F_33 ( V_37 ) ;
struct V_16 * V_17 ;
char V_14 [ 32 ] ;
if ( F_34 ( V_55 ) )
return NULL ;
if ( F_35 ( V_55 ) && V_53 . V_31 )
return NULL ;
F_12 ( strlen ( V_13 ) < sizeof( V_14 ) / 2 ) ;
strcpy ( V_14 , V_13 ) ;
if ( F_36 ( V_55 ) ) {
F_12 ( V_53 . V_31 == NULL ) ;
V_53 . V_31 = V_37 ;
strcat ( V_14 , L_10 ) ;
} else {
F_12 ( V_53 . V_31 != NULL ) ;
strcat ( V_14 , L_11 ) ;
}
V_17 = F_23 ( V_35 , V_14 , V_9 , & V_53 , V_37 ) ;
return V_17 ;
}
static struct V_16 * F_37 ( struct V_34 * V_35 ,
struct V_27 * V_28 , struct V_36 * V_37 )
{
struct V_27 V_53 = * V_28 ;
struct V_16 * V_17 ;
V_53 . V_31 = V_37 ;
V_17 = F_23 ( V_35 , V_56 , V_10 ,
& V_53 , V_37 ) ;
return V_17 ;
}
static int F_38 ( struct V_34 * V_35 , char * V_14 ,
struct V_27 * V_28 ,
struct V_36 * V_37 )
{
struct V_54 * V_55 = F_33 ( V_37 ) ;
struct V_16 * V_17 ;
struct V_16 * V_57 ;
struct V_16 * V_58 ;
char V_59 [ 32 ] ;
char * V_60 ;
int V_38 ;
F_5 ( V_11 , L_12 , V_14 , V_28 -> V_31 ) ;
V_60 = strrchr ( V_14 , '-' ) ;
if ( V_60 == NULL || V_60 - V_14 > 8 ) {
F_2 ( L_13 , V_14 ) ;
return - V_6 ;
}
memcpy ( V_59 , V_14 , V_60 - V_14 ) ;
strcpy ( V_59 + ( V_60 - V_14 ) , L_14 ) ;
V_57 = F_20 ( V_59 , NULL ) ;
if ( V_57 == NULL ) {
V_57 = F_23 ( V_35 , V_59 ,
V_8 , NULL , NULL ) ;
if ( F_39 ( V_57 ) ) {
F_2 ( L_15 , V_59 ) ;
GOTO ( V_61 , V_38 = F_40 ( V_57 ) ) ;
}
}
V_58 = F_37 ( V_35 , V_28 , V_37 ) ;
if ( F_39 ( V_58 ) ) {
V_38 = F_40 ( V_58 ) ;
F_2 ( L_16 ,
V_35 -> V_49 , V_38 ) ;
GOTO ( V_62 , V_38 ) ;
}
V_17 = F_23 ( V_35 , V_14 , V_7 , V_28 , V_37 ) ;
if ( F_39 ( V_17 ) ) {
F_2 ( L_17 , V_14 ) ;
GOTO ( V_63 , V_38 = F_40 ( V_17 ) ) ;
}
V_17 -> V_24 = V_57 ;
V_17 -> V_25 = V_58 ;
F_12 ( V_55 -> V_64 ) ;
if ( ! ( V_55 -> V_64 -> V_65 & V_66 ) ) {
struct V_16 * V_67 ;
* strrchr ( V_59 , '-' ) = 0 ;
V_67 = F_32 ( V_35 , V_59 , V_28 , V_37 ) ;
if ( F_39 ( V_67 ) )
GOTO ( V_68 , V_38 = F_40 ( V_67 ) ) ;
V_17 -> V_23 = V_67 ;
}
return 0 ;
V_68:
F_11 ( V_17 ) ;
V_63:
F_11 ( V_58 ) ;
V_62:
F_11 ( V_57 ) ;
V_61:
return V_38 ;
}
static int F_41 ( char * V_14 , struct V_27 * V_28 )
{
struct V_16 * V_17 ;
struct V_16 * V_24 = NULL ;
struct V_16 * V_25 = NULL ;
struct V_16 * V_23 = NULL ;
int V_38 = 0 ;
V_17 = F_20 ( V_14 , V_28 ) ;
if ( V_17 == NULL )
return - V_52 ;
F_42 ( & V_17 -> V_42 ) ;
if ( F_43 ( V_17 -> V_33 ) ) {
F_44 ( & V_17 -> V_42 ) ;
F_11 ( V_17 ) ;
return V_38 ;
}
V_17 -> V_33 = 1 ;
V_23 = V_17 -> V_23 ;
V_17 -> V_23 = NULL ;
F_44 ( & V_17 -> V_42 ) ;
if ( V_23 ) {
F_42 ( & V_23 -> V_42 ) ;
V_23 -> V_33 = 1 ;
F_44 ( & V_23 -> V_42 ) ;
F_11 ( V_23 ) ;
}
F_21 ( & V_21 ) ;
V_24 = V_17 -> V_24 ;
V_17 -> V_24 = NULL ;
V_25 = V_17 -> V_25 ;
V_17 -> V_25 = NULL ;
F_15 ( & V_21 ) ;
if ( V_24 )
F_11 ( V_24 ) ;
if ( V_25 ) {
F_42 ( & V_25 -> V_42 ) ;
V_25 -> V_33 = 1 ;
F_44 ( & V_25 -> V_42 ) ;
F_11 ( V_25 ) ;
}
F_11 ( V_17 ) ;
F_11 ( V_17 ) ;
F_5 ( V_11 , L_18 , V_14 ? V_14 : L_19 ,
V_38 ) ;
return V_38 ;
}
int F_45 ( struct V_69 * V_70 , void * V_71 )
{
struct V_34 * V_35 = V_71 ;
struct V_72 * V_73 = V_35 -> V_74 . V_75 . V_76 ;
struct V_77 * V_78 = & V_73 -> V_79 ;
struct V_16 * V_17 ;
F_46 ( V_70 , L_20 ,
F_47 ( V_78 , V_80 ) ? L_21 : L_22 ) ;
F_46 ( V_70 , L_23 ) ;
F_21 ( & V_21 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_17 -> V_23 == NULL )
continue;
F_46 ( V_70 , L_24 ,
V_17 -> V_20 ,
V_17 -> V_23 -> V_32 . V_43 ) ;
}
F_15 ( & V_21 ) ;
return 0 ;
}
static void F_48 ( struct V_16 * V_17 )
{
F_12 ( F_10 ( & V_17 -> V_18 ) > 0 ) ;
F_49 ( & V_17 -> V_26 -> V_81 -> V_74 . V_75 . V_82 ) ;
if ( V_17 -> V_26 -> V_81 -> V_74 . V_75 . V_83 != 0 ) {
F_5 ( V_11 , L_25 , V_17 -> V_20 ) ;
F_31 ( V_17 -> V_26 -> V_81 , V_17 ) ;
} else {
F_5 ( V_11 , L_26 ,
V_17 -> V_20 ) ;
}
F_50 ( & V_17 -> V_26 -> V_81 -> V_74 . V_75 . V_82 ) ;
}
static int F_51 ( void * V_71 )
{
int V_38 = 0 ;
F_5 ( V_11 , L_27 ) ;
F_21 ( & V_21 ) ;
V_84 |= V_85 ;
while ( 1 ) {
struct V_86 V_87 ;
struct V_16 * V_17 , * V_88 ;
int rand = F_52 () & V_89 ;
int V_90 = ! ! ( V_84 & V_91 ) ;
int V_92 ;
V_84 &= ~ ( V_93 | V_94 ) ;
F_15 ( & V_21 ) ;
V_92 = V_95 * V_96 ;
V_92 += rand * V_96 / 100 ;
V_87 = F_53 ( V_92 , NULL , NULL ) ;
F_54 ( V_97 , V_84 & V_91 , & V_87 ) ;
V_88 = NULL ;
F_21 ( & V_21 ) ;
F_22 (cld, &config_llog_list,
cld_list_chain) {
if ( ! V_17 -> V_98 )
continue;
F_15 ( & V_21 ) ;
F_12 ( F_10 ( & V_17 -> V_18 ) > 0 ) ;
if ( V_88 )
F_11 ( V_88 ) ;
V_88 = V_17 ;
V_17 -> V_98 = 0 ;
if ( F_55 ( ! V_90 ) )
F_48 ( V_17 ) ;
F_21 ( & V_21 ) ;
}
F_15 ( & V_21 ) ;
if ( V_88 )
F_11 ( V_88 ) ;
if ( F_43 ( V_90 ) ) {
F_21 ( & V_21 ) ;
break;
}
V_87 = (struct V_86 ) { 0 } ;
F_54 ( V_97 , V_84 & ( V_93 | V_91 ) ,
& V_87 ) ;
F_21 ( & V_21 ) ;
}
V_84 &= ~ V_85 ;
F_15 ( & V_21 ) ;
F_56 ( & V_99 ) ;
F_5 ( V_11 , L_28 ) ;
return V_38 ;
}
static void F_57 ( struct V_16 * V_17 )
{
F_5 ( V_19 , L_29 ,
V_17 -> V_20 , F_10 ( & V_17 -> V_18 ) ,
V_17 -> V_33 , V_84 ) ;
F_12 ( F_10 ( & V_17 -> V_18 ) > 0 ) ;
F_42 ( & V_17 -> V_42 ) ;
if ( V_17 -> V_33 || V_17 -> V_98 ) {
F_44 ( & V_17 -> V_42 ) ;
return;
}
F_8 ( V_17 ) ;
V_17 -> V_98 = 1 ;
F_44 ( & V_17 -> V_42 ) ;
F_21 ( & V_21 ) ;
if ( V_84 & V_91 ) {
F_15 ( & V_21 ) ;
V_17 -> V_98 = 0 ;
F_11 ( V_17 ) ;
} else {
V_84 |= V_93 ;
F_15 ( & V_21 ) ;
F_58 ( & V_97 ) ;
}
}
static int F_59 ( const struct V_100 * V_101 ,
struct V_34 * V_35 ,
struct V_34 * V_102 )
{
struct V_103 * V_104 ;
int V_38 ;
V_38 = F_60 ( V_101 , V_35 , & V_35 -> V_105 , V_106 , V_102 ,
& V_107 ) ;
if ( V_38 )
return V_38 ;
V_104 = F_61 ( V_35 , V_106 ) ;
F_12 ( V_104 ) ;
V_104 -> V_108 = V_35 -> V_74 . V_75 . V_109 ;
F_62 ( V_104 ) ;
return 0 ;
}
static int F_63 ( const struct V_100 * V_101 ,
struct V_34 * V_35 )
{
struct V_103 * V_104 ;
V_104 = F_61 ( V_35 , V_106 ) ;
F_64 ( V_101 , V_104 ) ;
return 0 ;
}
static int F_65 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_54 * V_55 = F_33 ( V_37 ) ;
struct V_110 * V_75 = & V_35 -> V_74 . V_75 ;
struct V_111 V_112 , V_113 ;
struct V_114 * V_115 , * V_116 ;
struct V_100 * V_101 ;
int V_38 = 0 ;
F_12 ( V_55 ) ;
F_12 ( V_55 -> V_117 ) ;
F_66 ( V_101 ) ;
if ( V_101 == NULL )
return - V_39 ;
F_42 ( & V_75 -> V_118 ) ;
F_67 () ;
V_38 = F_68 ( V_101 , V_119 ) ;
if ( V_38 )
GOTO ( V_61 , V_38 ) ;
V_113 . V_120 = V_121 ;
V_113 . V_122 = 1 ;
V_113 . V_123 = 0 ;
V_38 = F_69 ( V_101 , V_55 -> V_117 , & V_113 ,
& V_75 -> V_124 ) ;
if ( V_38 )
GOTO ( V_125 , V_38 ) ;
V_38 = F_70 ( V_101 , V_55 -> V_117 , & V_112 ) ;
if ( V_38 )
GOTO ( V_125 , V_38 ) ;
V_115 = F_71 ( V_101 , V_55 -> V_117 , & V_112 ,
& V_75 -> V_124 -> V_126 -> V_127 ) ;
if ( F_43 ( F_39 ( V_115 ) ) )
GOTO ( V_128 , V_38 = F_40 ( V_115 ) ) ;
V_116 = F_72 ( V_101 , V_75 -> V_124 , V_115 ,
V_129 ,
V_130 | V_131 | V_132 | V_133 ) ;
F_73 ( V_101 , & V_115 -> V_134 ) ;
if ( F_39 ( V_116 ) )
GOTO ( V_128 , V_38 = F_40 ( V_116 ) ) ;
V_75 -> V_109 = V_116 ;
F_12 ( V_55 -> V_135 -> V_81 -> V_136 . V_137 ) ;
V_38 = F_59 ( V_101 , V_35 , V_55 -> V_135 -> V_81 ) ;
if ( V_38 )
GOTO ( V_138 , V_38 ) ;
F_74 ( V_35 , L_30 , V_35 ) ;
V_138:
if ( V_38 ) {
F_75 ( V_101 , & V_75 -> V_109 -> V_134 ) ;
V_75 -> V_109 = NULL ;
}
V_128:
if ( V_38 < 0 ) {
F_76 ( V_101 , V_75 -> V_124 ) ;
V_75 -> V_124 = NULL ;
F_44 ( & V_75 -> V_118 ) ;
}
V_125:
F_77 ( V_101 ) ;
V_61:
F_78 ( V_101 ) ;
return V_38 ;
}
static int F_79 ( struct V_34 * V_35 )
{
struct V_100 V_101 ;
struct V_110 * V_75 = & V_35 -> V_74 . V_75 ;
int V_38 ;
F_12 ( V_75 -> V_124 != NULL ) ;
V_38 = F_68 ( & V_101 , V_119 ) ;
if ( V_38 )
GOTO ( V_139 , V_38 ) ;
F_63 ( & V_101 , V_35 ) ;
F_73 ( & V_101 , & V_75 -> V_109 -> V_134 ) ;
V_75 -> V_109 = NULL ;
F_76 ( & V_101 , V_75 -> V_124 ) ;
V_75 -> V_124 = NULL ;
F_77 ( & V_101 ) ;
V_139:
F_80 ( V_35 , L_30 , V_35 ) ;
F_44 ( & V_75 -> V_118 ) ;
return 0 ;
}
static int F_81 ( const struct V_100 * V_101 , struct V_34 * V_35 )
{
struct V_103 * V_104 ;
int V_38 ;
V_38 = F_60 ( V_101 , V_35 , & V_35 -> V_105 , V_140 , V_35 ,
& V_141 ) ;
if ( V_38 )
return V_38 ;
V_104 = F_61 ( V_35 , V_140 ) ;
F_12 ( V_104 ) ;
F_82 ( V_104 ) ;
F_62 ( V_104 ) ;
return 0 ;
}
static int F_83 ( const struct V_100 * V_101 , struct V_34 * V_35 )
{
struct V_103 * V_104 ;
V_104 = F_61 ( V_35 , V_140 ) ;
if ( V_104 )
F_64 ( V_101 , V_104 ) ;
return 0 ;
}
static int F_84 ( struct V_34 * V_35 , enum V_142 V_143 )
{
int V_38 = 0 ;
switch ( V_143 ) {
case V_144 :
break;
case V_145 :
if ( F_85 ( & V_146 ) ) {
int V_147 ;
F_21 ( & V_21 ) ;
V_147 = V_84 & V_85 ;
if ( V_147 )
V_84 |= V_91 ;
F_15 ( & V_21 ) ;
if ( V_147 ) {
F_58 ( & V_97 ) ;
F_86 ( & V_99 ) ;
}
}
F_87 ( V_35 ) ;
V_38 = F_83 ( NULL , V_35 ) ;
if ( V_38 != 0 )
F_2 ( L_31 ) ;
break;
}
return V_38 ;
}
static int F_88 ( struct V_34 * V_35 )
{
int V_38 ;
if ( V_35 -> V_148 -> V_149 <= 1 )
F_89 () ;
F_90 ( V_35 ) ;
F_91 () ;
V_38 = F_92 ( V_35 ) ;
return V_38 ;
}
static int F_93 ( struct V_34 * V_35 , struct V_150 * V_53 )
{
struct V_151 V_152 ;
int V_38 ;
F_94 () ;
V_38 = F_95 ( V_35 , V_53 ) ;
if ( V_38 )
GOTO ( V_153 , V_38 ) ;
V_38 = F_81 ( NULL , V_35 ) ;
if ( V_38 ) {
F_2 ( L_32 ) ;
GOTO ( V_154 , V_38 ) ;
}
F_96 ( & V_152 ) ;
F_97 ( V_35 , V_152 . V_155 ) ;
F_98 ( V_35 ) ;
if ( F_99 ( & V_146 ) == 1 ) {
V_84 = 0 ;
F_100 ( & V_97 ) ;
V_38 = F_40 ( F_101 ( F_51 , NULL ,
L_33 ) ) ;
if ( F_102 ( V_38 ) ) {
F_2 ( L_34
L_35 ,
V_35 -> V_49 , V_38 ) ;
GOTO ( V_154 , V_38 ) ;
}
V_38 = 0 ;
}
return V_38 ;
V_154:
F_92 ( V_35 ) ;
V_153:
F_91 () ;
return V_38 ;
}
static int F_103 ( struct V_156 * V_157 , struct V_158 * V_159 ,
void * V_71 , int V_160 )
{
struct V_161 V_162 ;
struct V_16 * V_17 = (struct V_16 * ) V_71 ;
int V_38 = 0 ;
switch ( V_160 ) {
case V_163 :
F_104 ( V_157 , L_36 ) ;
F_105 ( V_157 , & V_162 ) ;
V_38 = F_106 ( & V_162 , V_164 ) ;
break;
case V_165 :
F_104 ( V_157 , L_37 ) ;
F_5 ( V_11 , L_38 V_166 L_5 ,
F_107 ( V_157 -> V_167 ) ,
( char * ) & V_157 -> V_167 -> V_168 . V_1 [ 0 ] ) ;
if ( ! V_17 ) {
F_5 ( V_19 , L_39 ) ;
break;
}
F_12 ( F_10 ( & V_17 -> V_18 ) > 0 ) ;
if ( V_17 -> V_33 ) {
F_5 ( V_11 , L_40 ,
V_17 -> V_20 ) ;
F_11 ( V_17 ) ;
break;
}
if ( ! V_157 -> V_169 ||
! V_157 -> V_169 -> V_81 -> V_74 . V_75 . V_83 ) {
F_5 ( V_11 , L_41 ,
V_17 -> V_20 ) ;
F_11 ( V_17 ) ;
break;
}
F_57 ( V_17 ) ;
F_11 ( V_17 ) ;
break;
default:
F_4 () ;
}
return V_38 ;
}
static int F_108 ( struct V_170 * exp ,
struct V_171 * V_172 )
{
struct V_173 * V_174 ;
struct V_171 * V_175 , * V_176 ;
int V_38 ;
V_174 = F_109 ( F_110 ( exp ) ,
& V_177 , V_178 ,
V_179 ) ;
if ( ! V_174 )
return - V_39 ;
V_175 = F_111 ( & V_174 -> V_180 , & V_181 ) ;
if ( ! V_175 ) {
F_112 ( V_174 ) ;
return - V_39 ;
}
memcpy ( V_175 , V_172 , sizeof( * V_175 ) ) ;
F_113 ( V_174 ) ;
V_174 -> V_182 = V_183 ;
V_38 = F_114 ( V_174 ) ;
if ( ! V_38 ) {
V_176 = F_115 ( & V_174 -> V_180 , & V_181 ) ;
memcpy ( V_172 , V_176 , sizeof( * V_176 ) ) ;
}
F_112 ( V_174 ) ;
return V_38 ;
}
static int F_116 ( struct V_170 * exp , struct V_184 * V_185 ,
T_2 type , T_3 * V_186 , T_2 V_187 ,
T_1 * V_188 , void * V_189 , void * V_190 , void * V_191 ,
void * V_71 , T_2 V_192 , void * V_193 ,
struct V_161 * V_162 )
{
struct V_16 * V_17 = (struct V_16 * ) V_71 ;
struct V_194 V_195 = {
. V_196 = type ,
. V_197 = V_187 ,
. V_198 = F_103 ,
. V_199 = V_200 ,
} ;
struct V_173 * V_174 ;
int V_201 = F_16 ( V_17 ) ;
int V_38 ;
F_5 ( V_11 , L_42 V_12 L_43 , V_17 -> V_20 ,
V_17 -> V_50 . V_1 [ 0 ] ) ;
V_174 = F_109 ( F_110 ( exp ) ,
& V_202 , V_203 ,
V_204 ) ;
if ( V_174 == NULL )
return - V_39 ;
F_117 ( & V_174 -> V_180 , & V_205 , V_206 , 0 ) ;
F_113 ( V_174 ) ;
if ( V_17 -> V_32 . V_45 ) {
struct V_54 * V_55 = F_33 ( V_17 -> V_32 . V_45 ) ;
if ( V_55 && F_36 ( V_55 ) )
V_201 = 1 ;
}
V_174 -> V_182 = V_201 ? 5 : V_207 ;
V_38 = F_118 ( exp , & V_174 , & V_195 , & V_17 -> V_50 , NULL , V_188 ,
NULL , 0 , V_208 , V_162 , 0 ) ;
F_112 ( V_174 ) ;
return V_38 ;
}
static int F_119 ( struct V_170 * exp , struct V_184 * V_209 ,
T_2 V_187 , struct V_161 * V_162 )
{
F_120 ( V_162 , V_187 ) ;
return 0 ;
}
static void F_121 ( struct V_34 * V_210 )
{
F_21 ( & V_21 ) ;
V_84 |= V_93 ;
F_15 ( & V_21 ) ;
F_58 ( & V_97 ) ;
}
static int F_122 ( struct V_170 * exp ,
struct V_211 * V_212 )
{
struct V_173 * V_174 ;
struct V_211 * V_213 , * V_214 ;
int V_38 ;
V_174 = F_109 ( F_110 ( exp ) ,
& V_215 , V_178 ,
V_216 ) ;
if ( V_174 == NULL )
return - V_39 ;
V_213 = F_111 ( & V_174 -> V_180 , & V_217 ) ;
if ( ! V_213 ) {
F_112 ( V_174 ) ;
return - V_39 ;
}
memcpy ( V_213 , V_212 , sizeof( * V_213 ) ) ;
F_113 ( V_174 ) ;
F_5 ( V_11 , L_44 , V_212 -> V_218 ) ;
V_174 -> V_182 = V_219 ;
V_38 = F_114 ( V_174 ) ;
if ( ! V_38 ) {
V_214 = F_115 ( & V_174 -> V_180 ,
& V_217 ) ;
memcpy ( V_212 , V_214 , sizeof( * V_214 ) ) ;
F_5 ( V_11 , L_45 ,
V_212 -> V_218 , V_212 -> V_220 ) ;
}
F_112 ( V_174 ) ;
return V_38 ;
}
int F_123 ( const struct V_100 * V_101 , struct V_170 * exp ,
T_4 V_221 , void * V_222 , T_4 V_223 ,
void * V_224 , struct V_225 * V_226 )
{
int V_38 = - V_6 ;
if ( F_124 ( V_227 ) ) {
struct V_72 * V_73 = F_110 ( exp ) ;
int V_228 ;
if ( V_223 != sizeof( int ) )
return - V_6 ;
V_228 = * ( int * ) V_224 ;
F_5 ( V_11 , L_46 ,
V_73 -> V_229 -> V_49 , V_228 ,
V_73 -> V_230 , V_73 -> V_231 ,
V_73 -> V_232 , V_73 -> V_229 -> V_233 ,
F_125 ( V_73 -> V_234 ) ) ;
if ( ( V_73 -> V_234 != V_235 &&
V_73 -> V_234 != V_236 ) || V_228 > 1 )
F_126 ( V_73 ) ;
return 0 ;
}
if ( F_124 ( V_237 ) ) {
struct V_211 * V_212 ;
if ( V_223 != sizeof( struct V_211 ) )
return - V_6 ;
V_212 = (struct V_211 * ) V_224 ;
F_5 ( V_11 , L_47 ,
V_212 -> V_218 , V_212 -> V_238 ) ;
V_38 = F_122 ( exp , V_212 ) ;
return V_38 ;
}
if ( F_124 ( V_239 ) ) {
struct V_36 * V_37 = (struct V_36 * ) V_224 ;
if ( V_223 != sizeof( struct V_36 ) )
return - V_6 ;
V_38 = F_65 ( exp -> V_81 , V_37 ) ;
if ( V_38 )
F_2 ( L_48 , V_38 ) ;
return V_38 ;
}
if ( F_124 ( V_240 ) ) {
if ( V_223 != 0 )
return - V_6 ;
V_38 = F_79 ( exp -> V_81 ) ;
if ( V_38 )
F_2 ( L_49 , V_38 ) ;
return V_38 ;
}
if ( F_124 ( V_241 ) ) {
struct V_171 * V_172 ;
V_172 = (struct V_171 * ) V_224 ;
V_38 = F_108 ( exp , V_172 ) ;
return V_38 ;
}
if ( F_124 ( V_242 ) ) {
struct V_110 * V_75 = & exp -> V_81 -> V_74 . V_75 ;
struct V_243 V_244 ;
if ( V_223 == 0 ) {
if ( V_75 -> V_245 . V_246 != V_247 )
return 0 ;
V_224 = L_50 ;
V_223 = 4 ;
}
V_38 = F_127 ( V_224 , & V_244 ) ;
if ( V_38 ) {
F_2 ( L_51 ,
( char * ) V_224 ) ;
return V_38 ;
}
if ( V_75 -> V_245 . V_246 == V_247 ) {
V_75 -> V_245 = V_244 ;
} else if ( memcmp ( & V_75 -> V_245 , & V_244 ,
sizeof( V_244 ) ) != 0 ) {
char V_248 [ 20 ] ;
F_128 ( & V_75 -> V_245 ,
V_248 , sizeof( V_248 ) ) ;
F_129 ( L_52
L_53 ,
( char * ) V_224 , V_248 ) ;
V_38 = - V_249 ;
}
return V_38 ;
}
return V_38 ;
}
static int F_130 ( const struct V_100 * V_101 , struct V_170 * exp ,
T_2 V_221 , void * V_222 , T_2 * V_223 , void * V_224 ,
struct V_184 * V_210 )
{
int V_38 = - V_6 ;
if ( F_124 ( V_250 ) ) {
struct V_72 * V_73 = F_110 ( exp ) ;
struct V_77 * V_71 = V_224 ;
if ( * V_223 == sizeof( * V_71 ) ) {
* V_71 = V_73 -> V_79 ;
V_38 = 0 ;
}
}
return V_38 ;
}
static int F_131 ( struct V_34 * V_35 ,
struct V_72 * V_73 ,
enum V_251 V_252 )
{
int V_38 = 0 ;
F_12 ( V_73 -> V_229 == V_35 ) ;
F_5 ( V_11 , L_54 , V_252 ) ;
switch ( V_252 ) {
case V_253 :
if ( F_47 ( & V_73 -> V_79 , V_80 ) )
F_132 () ;
break;
case V_254 :
break;
case V_255 : {
struct V_256 * V_257 = V_35 -> V_258 ;
F_133 ( V_257 , V_259 ) ;
break;
}
case V_260 :
F_5 ( V_19 , L_55 , V_35 -> V_49 ) ;
V_35 -> V_261 = 0 ;
F_121 ( V_35 ) ;
if ( F_47 ( & V_73 -> V_79 , V_80 ) )
F_134 () ;
break;
case V_262 :
break;
case V_263 :
case V_264 :
break;
default:
F_2 ( L_56 , V_252 ) ;
F_4 () ;
}
return V_38 ;
}
static int F_135 ( struct V_34 * V_265 ,
struct V_16 * V_17 ,
T_1 V_266 ,
void * V_71 , int V_267 , bool V_268 )
{
struct V_27 * V_28 = & V_17 -> V_32 ;
struct V_54 * V_55 = F_33 ( V_28 -> V_45 ) ;
struct V_269 * V_270 ;
struct V_150 * V_53 ;
struct V_271 V_272 ;
T_5 V_273 = 0 ;
char * V_274 ;
char * V_275 ;
int V_276 ;
int V_277 ;
int V_38 = 0 ;
int V_278 = 0 ;
F_12 ( V_28 -> V_31 != NULL ) ;
F_12 ( V_28 -> V_45 == V_28 -> V_31 ) ;
F_24 ( V_274 , V_279 ) ;
if ( V_274 == NULL )
return - V_39 ;
if ( ! F_36 ( V_55 ) ) {
V_277 = snprintf ( V_274 , V_279 , L_57 , V_28 -> V_31 ) ;
if ( V_277 >= V_279 ) {
F_19 ( V_274 , V_279 ) ;
return - V_280 ;
}
} else {
F_12 ( F_35 ( V_55 ) ) ;
V_38 = F_136 ( V_55 -> V_281 , V_274 , NULL ,
V_279 ) ;
if ( V_38 ) {
F_19 ( V_274 , V_279 ) ;
return - V_6 ;
}
V_277 = strlen ( V_274 ) ;
}
++ V_277 ;
V_275 = V_274 + V_277 ;
V_276 = V_279 - V_277 ;
while ( V_267 > 0 ) {
int V_282 = sizeof( * V_270 ) ;
int V_283 ;
struct V_34 * V_35 ;
char * V_284 ;
char * V_285 ;
char * V_286 ;
char * V_287 ;
V_38 = - V_6 ;
if ( V_267 < sizeof( * V_270 ) )
break;
V_270 = ( F_137 ( V_270 ) ) ( V_71 + V_278 ) ;
if ( V_270 -> V_288 != 0 )
break;
if ( V_270 -> V_289 == 0 )
break;
if ( V_270 -> V_290 != sizeof( V_291 ) )
break;
V_282 += V_270 -> V_289 * V_270 -> V_290 ;
if ( V_267 < V_282 )
break;
if ( V_268 )
F_138 ( V_270 ) ;
if ( V_270 -> V_292 > V_279 ) {
F_2 ( L_58 , V_270 -> V_292 ) ;
break;
}
if ( V_270 -> V_292 < V_282 )
break;
V_278 += V_270 -> V_292 ;
V_267 -= V_270 -> V_292 ;
if ( V_267 < 0 )
break;
if ( V_270 -> V_293 > V_266 ) {
F_2 ( L_59 ,
V_270 -> V_293 , V_266 ) ;
break;
}
if ( V_273 >= V_270 -> V_293 ) {
F_2 ( L_60 ,
V_273 , V_270 -> V_293 ) ;
break;
}
V_273 = V_270 -> V_293 ;
V_283 = V_270 -> V_294 == V_295 ;
memset ( V_275 , 0 , V_276 ) ;
V_284 = V_275 ;
V_277 = 0 ;
strcpy ( V_284 , V_17 -> V_20 ) ;
V_285 = strrchr ( V_284 , '-' ) ;
if ( V_285 == NULL ) {
F_2 ( L_61 ,
V_265 -> V_49 , V_284 ) ;
break;
}
V_277 = V_285 - V_284 ;
V_284 [ V_277 ] = 0 ;
V_277 += sprintf ( V_284 + V_277 , L_62 ,
V_283 ? L_63 : L_64 , V_270 -> V_296 ) ;
V_285 = V_283 ? L_65 : L_66 ,
V_277 += sprintf ( V_284 + V_277 , L_67 , V_285 , V_274 ) ;
F_139 ( & V_272 , V_284 ) ;
V_35 = F_140 ( V_284 ) ;
if ( V_35 == NULL ) {
F_5 ( V_19 , L_68 ,
V_265 -> V_49 , V_284 ) ;
V_38 = 0 ;
continue;
}
++ V_277 ;
V_286 = V_275 + V_277 ;
V_277 += sprintf ( V_286 , L_69 , V_285 , L_70 ) ;
V_287 = V_275 + V_277 ;
F_49 ( & V_35 -> V_74 . V_75 . V_82 ) ;
if ( V_35 -> V_74 . V_75 . V_76 == NULL ) {
F_50 ( & V_35 -> V_74 . V_75 . V_82 ) ;
V_38 = 0 ;
continue;
}
V_38 = F_141 ( V_35 -> V_74 . V_75 . V_76 ,
V_270 -> V_74 . V_297 [ 0 ] ,
(struct V_298 * ) V_287 ) ;
F_50 ( & V_35 -> V_74 . V_75 . V_82 ) ;
if ( V_38 < 0 ) {
F_2 ( L_71 ,
F_142 ( V_270 -> V_74 . V_297 [ 0 ] ) ) ;
break;
}
F_5 ( V_19 , L_72 ,
V_287 , F_142 ( V_270 -> V_74 . V_297 [ 0 ] ) ) ;
V_277 += strlen ( V_287 ) ;
V_277 += sprintf ( V_275 + V_277 , L_73 , V_270 -> V_299 ) ;
F_12 ( V_277 < V_276 ) ;
F_143 ( & V_272 , 1 , V_286 ) ;
V_38 = - V_39 ;
V_53 = F_144 ( V_300 , & V_272 ) ;
if ( V_53 == NULL ) {
F_2 ( L_74 ) ;
break;
}
F_5 ( V_19 , L_75 V_301 L_4 V_301 L_76 ,
V_273 , V_266 , V_284 , V_286 ) ;
V_38 = F_145 ( V_53 ) ;
F_146 ( V_53 ) ;
if ( V_38 )
F_5 ( V_19 , L_77 ,
V_284 , V_38 ) ;
}
F_19 ( V_274 , V_279 ) ;
return V_38 ;
}
static int F_147 ( struct V_34 * V_35 ,
struct V_16 * V_17 )
{
struct V_173 * V_174 = NULL ;
struct V_27 * V_28 = & V_17 -> V_32 ;
struct V_302 * V_303 ;
struct V_304 * V_305 ;
struct V_306 * V_159 ;
struct V_307 * * V_308 ;
int V_309 ;
bool V_310 = true ;
bool V_268 = false ;
int V_311 ;
int V_312 ;
int V_38 ;
V_309 = V_313 ;
if ( V_28 -> V_43 == 0 )
V_309 = V_314 ;
F_24 ( V_308 , sizeof( * V_308 ) * V_309 ) ;
if ( V_308 == NULL )
GOTO ( V_315 , V_38 = - V_39 ) ;
for ( V_311 = 0 ; V_311 < V_309 ; V_311 ++ ) {
V_308 [ V_311 ] = F_148 ( V_316 ) ;
if ( V_308 [ V_311 ] == NULL )
GOTO ( V_315 , V_38 = - V_39 ) ;
}
V_317:
F_12 ( F_149 ( V_17 ) ) ;
F_12 ( F_150 ( & V_17 -> V_42 ) ) ;
V_174 = F_151 ( F_110 ( V_17 -> V_26 ) ,
& V_318 ) ;
if ( V_174 == NULL )
GOTO ( V_315 , V_38 = - V_39 ) ;
V_38 = F_152 ( V_174 , V_178 , V_319 ) ;
if ( V_38 )
GOTO ( V_315 , V_38 ) ;
V_303 = F_111 ( & V_174 -> V_180 , & V_320 ) ;
F_12 ( V_303 != NULL ) ;
F_12 ( sizeof( V_303 -> V_321 ) > strlen ( V_17 -> V_20 ) ) ;
if ( F_153 ( V_303 -> V_321 , V_17 -> V_20 , sizeof( V_303 -> V_321 ) )
>= sizeof( V_303 -> V_321 ) )
GOTO ( V_315 , V_38 = - V_280 ) ;
V_303 -> V_322 = V_28 -> V_43 + 1 ;
V_303 -> V_323 = V_17 -> V_46 ;
V_303 -> V_324 = V_325 ;
V_303 -> V_326 = V_309 ;
V_159 = F_154 ( V_174 , V_309 , 1 , V_327 ,
V_328 ) ;
if ( V_159 == NULL )
GOTO ( V_315 , V_38 = - V_39 ) ;
for ( V_311 = 0 ; V_311 < V_309 ; V_311 ++ )
F_155 ( V_159 , V_308 [ V_311 ] , 0 , V_279 ) ;
F_113 ( V_174 ) ;
V_38 = F_114 ( V_174 ) ;
if ( V_38 )
GOTO ( V_315 , V_38 ) ;
V_305 = F_115 ( & V_174 -> V_180 , & V_329 ) ;
if ( V_305 -> V_330 < V_305 -> V_331 )
GOTO ( V_315 , V_38 = - V_6 ) ;
V_28 -> V_43 = V_305 -> V_331 ;
V_310 = V_305 -> V_331 == V_305 -> V_330 ;
F_5 ( V_19 , L_78 V_301 L_79 ,
V_305 -> V_331 , V_310 == false ) ;
V_312 = F_156 ( V_174 , V_174 -> V_332 , 0 ) ;
if ( V_312 < 0 )
GOTO ( V_315 , V_38 = V_312 ) ;
if ( V_312 > V_309 << V_325 )
GOTO ( V_315 , V_38 = - V_6 ) ;
if ( V_312 == 0 ) {
if ( ! V_310 )
V_38 = - V_6 ;
GOTO ( V_315 , V_38 ) ;
}
V_268 = ! ! F_157 ( V_174 ) ;
#if V_333 < F_158 ( 3 , 2 , 50 , 0 )
if ( F_43 ( V_174 -> V_334 -> V_335 ) )
V_268 = ! V_268 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_311 = 0 ; V_311 < V_309 && V_312 > 0 ; V_311 ++ ) {
int V_336 ;
void * V_60 ;
V_60 = F_159 ( V_308 [ V_311 ] ) ;
V_336 = F_135 ( V_35 , V_17 , V_305 -> V_331 , V_60 ,
F_160 ( int , V_312 , V_279 ) ,
V_268 ) ;
F_161 ( V_308 [ V_311 ] ) ;
if ( V_336 < 0 ) {
F_162 ( L_80 ,
V_17 -> V_20 , V_336 ) ;
break;
}
V_312 -= V_279 ;
}
V_315:
if ( V_174 )
F_112 ( V_174 ) ;
if ( V_38 == 0 && ! V_310 )
goto V_317;
if ( V_308 ) {
for ( V_311 = 0 ; V_311 < V_309 ; V_311 ++ ) {
if ( V_308 [ V_311 ] == NULL )
break;
F_163 ( V_308 [ V_311 ] ) ;
}
F_19 ( V_308 , sizeof( * V_308 ) * V_309 ) ;
}
return V_38 ;
}
static int F_164 ( const struct V_100 * V_101 ,
struct V_34 * V_35 ,
struct V_103 * V_337 ,
struct V_103 * V_338 , char * V_14 )
{
char * V_339 ;
int V_38 ;
F_24 ( V_339 , strlen ( V_14 ) + 1 ) ;
if ( ! V_339 )
return - V_39 ;
sprintf ( V_339 , L_81 , V_14 ) ;
V_38 = F_165 ( V_101 , V_35 , V_338 , V_338 , V_14 , V_339 ) ;
if ( V_38 < 0 && V_38 != - V_52 )
GOTO ( V_315 , V_38 ) ;
V_38 = F_165 ( V_101 , V_35 , V_337 , V_338 , V_14 , V_14 ) ;
if ( V_38 == - V_52 ) {
F_166 ( V_101 , V_338 , NULL , V_14 ) ;
} else if ( V_38 < 0 ) {
F_165 ( V_101 , V_35 , V_338 , V_338 , V_339 , V_14 ) ;
V_315:
F_2 ( L_82 ,
V_35 -> V_49 , V_14 , V_38 ) ;
}
F_166 ( V_101 , V_338 , NULL , V_339 ) ;
F_19 ( V_339 , strlen ( V_14 ) + 1 ) ;
return V_38 ;
}
static int F_167 ( struct V_34 * V_265 ,
struct V_16 * V_17 , int V_340 )
{
struct V_103 * V_104 , * V_338 = NULL ;
struct V_114 * V_341 = V_265 -> V_74 . V_75 . V_109 ;
struct V_54 * V_55 = NULL ;
int V_38 = 0 ;
bool V_342 = false ;
struct V_100 * V_101 ;
F_12 ( V_17 ) ;
F_12 ( F_150 ( & V_17 -> V_42 ) ) ;
if ( F_16 ( V_17 ) && V_340 )
return 0 ;
if ( V_17 -> V_32 . V_45 )
V_55 = F_33 ( V_17 -> V_32 . V_45 ) ;
F_66 ( V_101 ) ;
if ( V_101 == NULL )
return - V_39 ;
V_38 = F_68 ( V_101 , V_119 ) ;
if ( V_38 )
GOTO ( V_343 , V_38 ) ;
V_104 = F_61 ( V_265 , V_140 ) ;
F_12 ( V_104 ) ;
V_338 = F_61 ( V_265 , V_106 ) ;
if ( V_338 && V_55 && F_36 ( V_55 ) && ! F_168 ( V_55 ) &&
V_341 != NULL &&
F_169 ( V_341 -> V_134 . V_344 ) == V_55 -> V_117 ) {
if ( ! V_340 )
V_38 = F_164 ( V_101 , V_265 , V_104 , V_338 ,
V_17 -> V_20 ) ;
if ( V_340 || V_38 ) {
if ( F_170 ( V_101 , V_338 , V_17 -> V_20 ) ) {
F_171 ( 0x13a ,
L_83 ,
V_17 -> V_20 ) ;
GOTO ( V_345 , V_38 = - V_52 ) ;
}
F_5 ( V_11 ,
L_84 ,
V_17 -> V_20 ) ;
}
F_62 ( V_104 ) ;
V_104 = V_338 ;
V_338 = NULL ;
} else {
if ( V_340 )
GOTO ( V_345 , V_38 = - V_346 ) ;
}
if ( F_16 ( V_17 ) ) {
F_172 ( V_17 -> V_20 ) ;
V_342 = true ;
}
V_38 = F_173 ( V_101 , V_104 , V_17 -> V_20 ,
& V_17 -> V_32 ) ;
V_345:
F_174 ( V_101 , V_104 ) ;
if ( V_338 )
F_174 ( V_101 , V_338 ) ;
if ( V_342 ) {
F_12 ( F_16 ( V_17 ) ) ;
F_175 ( V_17 -> V_20 ) ;
F_176 ( V_17 -> V_20 ,
strlen ( V_17 -> V_20 ) -
strlen ( L_14 ) ) ;
}
F_77 ( V_101 ) ;
V_343:
F_78 ( V_101 ) ;
return V_38 ;
}
int F_31 ( struct V_34 * V_265 , struct V_16 * V_17 )
{
struct V_161 V_162 = { 0 } ;
T_1 V_188 = V_347 ;
int V_38 = 0 , V_348 ;
F_12 ( V_17 ) ;
F_42 ( & V_17 -> V_42 ) ;
if ( V_17 -> V_33 ) {
F_44 ( & V_17 -> V_42 ) ;
return 0 ;
}
F_177 ( V_349 , 20 ) ;
F_5 ( V_11 , L_85 , V_17 -> V_20 ,
V_17 -> V_32 . V_31 , V_17 -> V_32 . V_43 + 1 ) ;
V_348 = F_116 ( V_265 -> V_74 . V_75 . V_350 , NULL , V_351 , NULL ,
V_352 , & V_188 , NULL , NULL , NULL ,
V_17 , 0 , NULL , & V_162 ) ;
if ( V_348 == 0 ) {
F_8 ( V_17 ) ;
V_38 = F_178 ( & V_162 , ( void * ) V_17 ) ;
F_12 ( V_38 == 0 ) ;
} else {
F_5 ( V_11 , L_86 , V_348 ) ;
V_17 -> V_98 = 1 ;
F_8 ( V_17 ) ;
}
if ( F_149 ( V_17 ) ) {
V_38 = 0 ;
if ( V_348 == 0 )
V_38 = F_147 ( V_265 , V_17 ) ;
} else {
V_38 = F_167 ( V_265 , V_17 , V_348 != 0 ) ;
}
F_5 ( V_11 , L_87 ,
V_265 -> V_49 , V_17 -> V_20 , V_38 ? L_88 : L_89 , V_38 ) ;
F_44 ( & V_17 -> V_42 ) ;
if ( ! V_348 ) {
V_348 = F_119 ( V_265 -> V_74 . V_75 . V_350 , NULL ,
V_352 , & V_162 ) ;
if ( V_348 )
F_2 ( L_90 , V_348 ) ;
}
return V_38 ;
}
static int F_179 ( struct V_34 * V_35 , T_4 V_2 , void * V_275 )
{
struct V_150 * V_53 = V_275 ;
struct V_27 * V_28 = NULL ;
char * V_14 ;
int V_38 = 0 ;
switch ( V_53 -> V_353 ) {
case V_354 : {
struct V_211 * V_212 ;
if ( F_180 ( V_53 , 1 ) !=
sizeof( struct V_211 ) )
GOTO ( V_315 , V_38 = - V_6 ) ;
V_212 = (struct V_211 * ) F_181 ( V_53 , 1 ) ;
F_5 ( V_11 , L_91 ,
V_212 -> V_218 , V_212 -> V_238 ) ;
V_38 = F_122 ( V_35 -> V_74 . V_75 . V_350 , V_212 ) ;
break;
}
case V_355 :
F_2 ( L_92 ) ;
V_38 = - V_356 ;
break;
case V_357 : {
V_38 = F_182 ( V_53 ) ;
break;
}
case V_358 : {
struct V_16 * V_17 ;
struct V_36 * V_37 ;
V_14 = F_183 ( V_53 , 1 ) ;
V_28 = (struct V_27 * ) F_181 ( V_53 , 2 ) ;
V_37 = * (struct V_36 * * ) F_181 ( V_53 , 3 ) ;
F_5 ( V_11 , L_93 , V_14 ,
V_28 -> V_43 ) ;
V_38 = F_38 ( V_35 , V_14 , V_28 , V_37 ) ;
if ( V_38 )
break;
V_17 = F_20 ( V_14 , V_28 ) ;
if ( V_17 == NULL ) {
V_38 = - V_52 ;
break;
}
V_17 -> V_32 . V_44 |= V_359 ;
V_38 = F_31 ( V_35 , V_17 ) ;
if ( V_38 == 0 && V_17 -> V_23 != NULL ) {
if ( F_47 ( & V_35 -> V_74 . V_75 . V_76 ->
V_79 , V_80 ) ) {
V_38 = F_31 ( V_35 , V_17 -> V_23 ) ;
} else {
struct V_16 * V_360 = V_17 -> V_23 ;
V_17 -> V_23 = NULL ;
F_11 ( V_360 ) ;
}
if ( V_38 )
F_2 ( L_94 , V_38 ) ;
}
if ( V_38 == 0 && V_17 -> V_25 != NULL ) {
V_38 = F_31 ( V_35 , V_17 -> V_25 ) ;
if ( V_38 == - V_52 ) {
F_5 ( V_11 ,
L_95 ) ;
V_38 = 0 ;
}
if ( V_38 )
F_2 (
L_96 ,
V_35 -> V_49 , V_38 ) ;
}
F_11 ( V_17 ) ;
break;
}
case V_361 : {
V_14 = F_183 ( V_53 , 1 ) ;
if ( V_53 -> V_362 >= 2 )
V_28 = (struct V_27 * ) F_181 (
V_53 , 2 ) ;
V_38 = F_41 ( V_14 , V_28 ) ;
break;
}
default: {
F_2 ( L_97 , V_53 -> V_353 ) ;
GOTO ( V_315 , V_38 = - V_6 ) ;
}
}
V_315:
return V_38 ;
}
int T_6 F_184 ( void )
{
return F_185 ( & V_363 , NULL , NULL ,
V_364 , NULL ) ;
}
static void F_186 ( void )
{
F_187 ( V_364 ) ;
}
