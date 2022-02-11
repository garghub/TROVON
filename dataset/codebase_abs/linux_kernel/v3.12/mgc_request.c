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
switch( type ) {
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
static int F_58 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_92 * V_93 )
{
struct V_94 V_95 ;
struct V_52 * V_53 = F_33 ( V_35 ) ;
struct V_96 * V_67 = & V_33 -> V_66 . V_67 ;
struct V_97 * V_97 ;
char * V_98 ;
int V_99 = 0 ;
F_8 ( V_53 ) ;
F_8 ( V_53 -> V_100 == V_93 ) ;
F_59 ( & V_67 -> V_101 ) ;
F_60 () ;
V_33 -> V_102 = F_61 ( V_53 -> V_103 ) ;
if ( F_38 ( V_33 -> V_102 ) ) {
F_62 ( & V_67 -> V_101 ) ;
F_2 ( L_29 , V_53 -> V_103 ,
V_33 -> V_47 , F_39 ( V_33 -> V_102 ) ) ;
return F_39 ( V_33 -> V_102 ) ;
}
V_67 -> V_104 = V_93 ;
V_99 = F_63 ( V_33 , V_93 -> V_105 ) ;
if ( V_99 )
GOTO ( V_106 , V_99 ) ;
F_64 ( & V_33 -> V_107 ) ;
V_33 -> V_107 . V_108 = V_93 ;
V_33 -> V_107 . V_109 = V_93 -> V_110 ;
V_33 -> V_107 . V_111 = F_65 () ;
F_66 ( & V_95 , & V_33 -> V_107 , NULL ) ;
V_97 = F_67 ( V_112 , F_68 ( V_113 -> V_111 ) ,
strlen ( V_112 ) ) ;
F_69 ( & V_95 , & V_33 -> V_107 , NULL ) ;
if ( F_38 ( V_97 ) ) {
V_99 = F_39 ( V_97 ) ;
F_2 ( L_30 ,
V_112 , V_99 ) ;
GOTO ( V_106 , V_99 ) ;
}
V_67 -> V_114 = V_97 ;
F_70 ( V_33 , L_31 , V_33 ) ;
V_98 = F_71 ( V_33 , V_93 -> V_105 ) ;
if ( V_98 )
F_5 ( V_10 , L_32 , V_98 ) ;
return 0 ;
V_106:
F_72 ( V_33 -> V_102 ) ;
V_33 -> V_102 = NULL ;
V_67 -> V_104 = NULL ;
F_62 ( & V_67 -> V_101 ) ;
return V_99 ;
}
static int F_73 ( struct V_32 * V_33 )
{
struct V_96 * V_67 = & V_33 -> V_66 . V_67 ;
int V_36 = 0 ;
F_8 ( V_67 -> V_104 != NULL ) ;
if ( V_67 -> V_114 != NULL ) {
struct V_94 V_95 ;
F_66 ( & V_95 , & V_33 -> V_107 , NULL ) ;
F_74 ( V_67 -> V_114 ) ;
V_67 -> V_114 = NULL ;
F_69 ( & V_95 , & V_33 -> V_107 , NULL ) ;
F_75 ( V_33 , L_31 , V_33 ) ;
}
V_67 -> V_104 = NULL ;
if ( V_33 -> V_102 )
F_72 ( V_33 -> V_102 ) ;
F_62 ( & V_67 -> V_101 ) ;
return V_36 ;
}
static int F_76 ( struct V_32 * V_33 , enum V_115 V_116 )
{
int V_36 = 0 ;
switch ( V_116 ) {
case V_117 :
break;
case V_118 :
if ( F_77 ( & V_119 ) ) {
int V_120 ;
F_21 ( & V_20 ) ;
V_120 = V_76 & V_77 ;
if ( V_120 )
V_76 |= V_83 ;
F_15 ( & V_20 ) ;
if ( V_120 ) {
F_57 ( & V_89 ) ;
F_78 ( & V_91 ) ;
}
}
F_79 ( V_33 ) ;
V_36 = F_80 ( V_33 , 0 ) ;
if ( V_36 != 0 )
F_2 ( L_33 ) ;
break;
}
return V_36 ;
}
static int F_81 ( struct V_32 * V_33 )
{
struct V_96 * V_67 = & V_33 -> V_66 . V_67 ;
int V_36 ;
F_8 ( V_67 -> V_104 == NULL ) ;
if ( V_33 -> V_121 -> V_122 <= 1 )
F_82 () ;
F_83 ( V_33 ) ;
F_84 () ;
V_36 = F_85 ( V_33 ) ;
return V_36 ;
}
static int F_86 ( struct V_32 * V_33 , struct V_123 * V_51 )
{
struct V_124 V_125 ;
int V_36 ;
F_87 () ;
V_36 = F_88 ( V_33 , V_51 ) ;
if ( V_36 )
GOTO ( V_126 , V_36 ) ;
V_36 = F_89 ( V_33 , & V_33 -> V_127 , V_33 , NULL ) ;
if ( V_36 ) {
F_2 ( L_34 ) ;
GOTO ( V_128 , V_36 ) ;
}
F_90 ( & V_125 ) ;
F_91 ( V_33 , V_125 . V_129 ) ;
F_92 ( V_33 ) ;
if ( F_93 ( & V_119 ) == 1 ) {
V_76 = 0 ;
F_94 ( & V_89 ) ;
V_36 = F_39 ( F_95 ( F_50 , NULL ,
L_35 ) ) ;
if ( F_96 ( V_36 ) ) {
F_2 ( L_36
L_37 ,
V_33 -> V_47 , V_36 ) ;
GOTO ( V_128 , V_36 ) ;
}
V_36 = 0 ;
}
return V_36 ;
V_128:
F_85 ( V_33 ) ;
V_126:
F_84 () ;
return V_36 ;
}
static int F_97 ( struct V_130 * V_131 , struct V_132 * V_133 ,
void * V_63 , int V_134 )
{
struct V_135 V_136 ;
struct V_15 * V_16 = (struct V_15 * ) V_63 ;
int V_36 = 0 ;
switch ( V_134 ) {
case V_137 :
F_98 ( V_131 , L_38 ) ;
F_99 ( V_131 , & V_136 ) ;
V_36 = F_100 ( & V_136 , V_138 ) ;
break;
case V_139 :
F_98 ( V_131 , L_39 ) ;
F_5 ( V_10 , L_40 V_11 L_5 ,
V_131 -> V_140 -> V_141 . V_1 [ 0 ] ,
( char * ) & V_131 -> V_140 -> V_141 . V_1 [ 0 ] ) ;
if ( ! V_16 ) {
F_5 ( V_18 , L_41 ) ;
break;
}
F_8 ( F_11 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_16 -> V_31 ) {
F_5 ( V_10 , L_42 ,
V_16 -> V_19 ) ;
F_12 ( V_16 ) ;
break;
}
if ( ! V_131 -> V_142 ||
! V_131 -> V_142 -> V_73 -> V_66 . V_67 . V_75 ) {
F_5 ( V_10 , L_43 ,
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
static int F_101 ( struct V_143 * exp ,
struct V_144 * V_145 )
{
struct V_146 * V_147 ;
struct V_144 * V_148 , * V_149 ;
int V_36 ;
V_147 = F_102 ( F_103 ( exp ) ,
& V_150 , V_151 ,
V_152 ) ;
if ( ! V_147 )
return - V_37 ;
V_148 = F_104 ( & V_147 -> V_153 , & V_154 ) ;
if ( ! V_148 ) {
F_105 ( V_147 ) ;
return - V_37 ;
}
memcpy ( V_148 , V_145 , sizeof( * V_148 ) ) ;
F_106 ( V_147 ) ;
V_147 -> V_155 = V_156 ;
V_36 = F_107 ( V_147 ) ;
if ( ! V_36 ) {
V_149 = F_108 ( & V_147 -> V_153 , & V_154 ) ;
memcpy ( V_145 , V_149 , sizeof( * V_149 ) ) ;
}
F_105 ( V_147 ) ;
return V_36 ;
}
static int F_109 ( struct V_143 * exp , struct V_157 * V_158 ,
T_2 type , T_3 * V_159 , T_2 V_160 ,
T_1 * V_161 , void * V_162 , void * V_163 , void * V_164 ,
void * V_63 , T_2 V_165 , void * V_166 ,
struct V_135 * V_136 )
{
struct V_15 * V_16 = (struct V_15 * ) V_63 ;
struct V_167 V_168 = {
. V_169 = type ,
. V_170 = V_160 ,
. V_171 = F_97 ,
. V_172 = V_173 ,
} ;
struct V_146 * V_147 ;
int V_174 = F_16 ( V_16 ) ;
int V_36 ;
F_5 ( V_10 , L_44 V_11 L_45 , V_16 -> V_19 ,
V_16 -> V_48 . V_1 [ 0 ] ) ;
V_147 = F_102 ( F_103 ( exp ) ,
& V_175 , V_176 ,
V_177 ) ;
if ( V_147 == NULL )
return - V_37 ;
F_110 ( & V_147 -> V_153 , & V_178 , V_179 , 0 ) ;
F_106 ( V_147 ) ;
if ( V_16 -> V_30 . V_43 ) {
struct V_52 * V_53 = F_33 ( V_16 -> V_30 . V_43 ) ;
if ( V_53 && F_36 ( V_53 ) )
V_174 = 1 ;
}
V_147 -> V_155 = V_174 ? 5 : V_180 ;
V_36 = F_111 ( exp , & V_147 , & V_168 , & V_16 -> V_48 , NULL , V_161 ,
NULL , 0 , V_181 , V_136 , 0 ) ;
F_105 ( V_147 ) ;
return V_36 ;
}
static int F_112 ( struct V_143 * exp , struct V_157 * V_182 ,
T_2 V_160 , struct V_135 * V_136 )
{
F_113 ( V_136 , V_160 ) ;
return 0 ;
}
static void F_114 ( struct V_32 * V_183 )
{
F_21 ( & V_20 ) ;
V_76 |= V_85 ;
F_15 ( & V_20 ) ;
F_57 ( & V_89 ) ;
}
static int F_115 ( struct V_143 * exp ,
struct V_184 * V_185 )
{
struct V_146 * V_147 ;
struct V_184 * V_186 , * V_187 ;
int V_36 ;
V_147 = F_102 ( F_103 ( exp ) ,
& V_188 , V_151 ,
V_189 ) ;
if ( V_147 == NULL )
return - V_37 ;
V_186 = F_104 ( & V_147 -> V_153 , & V_190 ) ;
if ( ! V_186 ) {
F_105 ( V_147 ) ;
return - V_37 ;
}
memcpy ( V_186 , V_185 , sizeof( * V_186 ) ) ;
F_106 ( V_147 ) ;
F_5 ( V_10 , L_46 , V_185 -> V_191 ) ;
V_147 -> V_155 = V_192 ;
V_36 = F_107 ( V_147 ) ;
if ( ! V_36 ) {
V_187 = F_108 ( & V_147 -> V_153 ,
& V_190 ) ;
memcpy ( V_185 , V_187 , sizeof( * V_187 ) ) ;
F_5 ( V_10 , L_47 ,
V_185 -> V_191 , V_185 -> V_193 ) ;
}
F_105 ( V_147 ) ;
return V_36 ;
}
int F_116 ( const struct V_194 * V_195 , struct V_143 * exp ,
T_4 V_196 , void * V_197 , T_4 V_198 ,
void * V_199 , struct V_200 * V_201 )
{
int V_36 = - V_6 ;
if ( F_117 ( V_202 ) ) {
struct V_64 * V_65 = F_103 ( exp ) ;
int V_203 ;
if ( V_198 != sizeof( int ) )
return - V_6 ;
V_203 = * ( int * ) V_199 ;
F_5 ( V_10 , L_48 ,
V_65 -> V_204 -> V_47 , V_203 ,
V_65 -> V_205 , V_65 -> V_206 ,
V_65 -> V_207 , V_65 -> V_204 -> V_208 ,
F_118 ( V_65 -> V_209 ) ) ;
if ( ( V_65 -> V_209 != V_210 &&
V_65 -> V_209 != V_211 ) || V_203 > 1 )
F_119 ( V_65 ) ;
return 0 ;
}
if ( F_117 ( V_212 ) ) {
struct V_184 * V_185 ;
if ( V_198 != sizeof( struct V_184 ) )
return - V_6 ;
V_185 = (struct V_184 * ) V_199 ;
F_5 ( V_10 , L_49 ,
V_185 -> V_191 , V_185 -> V_213 ) ;
V_36 = F_115 ( exp , V_185 ) ;
return V_36 ;
}
if ( F_117 ( V_214 ) ) {
struct V_34 * V_35 = (struct V_34 * ) V_199 ;
struct V_52 * V_53 ;
if ( V_198 != sizeof( struct V_34 ) )
return - V_6 ;
V_53 = F_33 ( V_35 ) ;
V_36 = F_58 ( exp -> V_73 , V_35 , V_53 -> V_100 ) ;
if ( V_36 ) {
F_2 ( L_50 , V_36 ) ;
}
return V_36 ;
}
if ( F_117 ( V_215 ) ) {
if ( V_198 != 0 )
return - V_6 ;
V_36 = F_73 ( exp -> V_73 ) ;
if ( V_36 ) {
F_2 ( L_51 , V_36 ) ;
}
return V_36 ;
}
if ( F_117 ( V_216 ) ) {
struct V_144 * V_145 ;
V_145 = (struct V_144 * ) V_199 ;
V_36 = F_101 ( exp , V_145 ) ;
return V_36 ;
}
if ( F_117 ( V_217 ) ) {
struct V_96 * V_67 = & exp -> V_73 -> V_66 . V_67 ;
struct V_218 V_219 ;
if ( V_198 == 0 ) {
if ( V_67 -> V_220 . V_221 != V_222 )
return 0 ;
V_199 = L_52 ;
V_198 = 4 ;
}
V_36 = F_120 ( V_199 , & V_219 ) ;
if ( V_36 ) {
F_2 ( L_53 ,
( char * ) V_199 ) ;
return V_36 ;
}
if ( V_67 -> V_220 . V_221 == V_222 ) {
V_67 -> V_220 = V_219 ;
} else if ( memcmp ( & V_67 -> V_220 , & V_219 ,
sizeof( V_219 ) ) != 0 ) {
char V_223 [ 20 ] ;
F_121 ( & V_67 -> V_220 ,
V_223 , sizeof( V_223 ) ) ;
F_122 ( L_54
L_55 ,
( char * ) V_199 , V_223 ) ;
V_36 = - V_224 ;
}
return V_36 ;
}
return V_36 ;
}
static int F_123 ( const struct V_194 * V_195 , struct V_143 * exp ,
T_2 V_196 , void * V_197 , T_2 * V_198 , void * V_199 ,
struct V_157 * V_183 )
{
int V_36 = - V_6 ;
if ( F_117 ( V_225 ) ) {
struct V_64 * V_65 = F_103 ( exp ) ;
struct V_69 * V_63 = V_199 ;
if ( * V_198 == sizeof( * V_63 ) ) {
* V_63 = V_65 -> V_71 ;
V_36 = 0 ;
}
}
return V_36 ;
}
static int F_124 ( struct V_32 * V_33 ,
struct V_64 * V_65 ,
enum V_226 V_227 )
{
int V_36 = 0 ;
F_8 ( V_65 -> V_204 == V_33 ) ;
F_5 ( V_10 , L_56 , V_227 ) ;
switch ( V_227 ) {
case V_228 :
if ( F_46 ( & V_65 -> V_71 , V_72 ) )
F_125 () ;
break;
case V_229 :
break;
case V_230 : {
struct V_231 * V_232 = V_33 -> V_233 ;
F_126 ( V_232 , V_234 ) ;
break;
}
case V_235 :
F_5 ( V_18 , L_57 , V_33 -> V_47 ) ;
V_33 -> V_236 = 0 ;
F_114 ( V_33 ) ;
if ( F_46 ( & V_65 -> V_71 , V_72 ) )
F_127 () ;
break;
case V_237 :
break;
case V_238 :
case V_239 :
break;
default:
F_2 ( L_58 , V_227 ) ;
F_4 () ;
}
return V_36 ;
}
static int F_128 ( struct V_32 * V_33 , struct V_240 * V_241 ,
struct V_32 * V_242 , int * V_243 )
{
struct V_244 * V_245 ;
int V_36 ;
F_8 ( V_241 == & V_33 -> V_127 ) ;
V_36 = F_129 ( NULL , V_33 , V_241 , V_246 , V_242 ,
& V_247 ) ;
if ( V_36 )
GOTO ( V_248 , V_36 ) ;
V_245 = F_130 ( V_241 , V_246 ) ;
if ( ! V_245 )
GOTO ( V_248 , V_36 = - V_249 ) ;
F_131 ( V_245 ) ;
F_132 ( V_245 ) ;
return 0 ;
V_248:
V_245 = F_133 ( V_33 , V_250 ) ;
if ( V_245 )
F_134 ( NULL , V_245 ) ;
return V_36 ;
}
static int F_135 ( struct V_32 * V_33 , int V_251 )
{
struct V_244 * V_245 ;
V_245 = F_133 ( V_33 , V_246 ) ;
if ( V_245 )
F_134 ( NULL , V_245 ) ;
V_245 = F_133 ( V_33 , V_250 ) ;
if ( V_245 )
F_134 ( NULL , V_245 ) ;
return 0 ;
}
static int F_136 ( struct V_32 * V_252 ,
struct V_15 * V_16 ,
T_1 V_253 ,
void * V_63 , int V_254 , bool V_255 )
{
struct V_25 * V_26 = & V_16 -> V_30 ;
struct V_52 * V_53 = F_33 ( V_26 -> V_43 ) ;
struct V_256 * V_257 ;
struct V_123 * V_51 ;
struct V_258 V_259 ;
T_5 V_260 = 0 ;
char * V_261 ;
char * V_262 ;
int V_263 ;
int V_264 ;
int V_36 = 0 ;
int V_265 = 0 ;
F_8 ( V_26 -> V_29 != NULL ) ;
F_8 ( V_26 -> V_43 == V_26 -> V_29 ) ;
F_24 ( V_261 , V_266 ) ;
if ( V_261 == NULL )
return - V_37 ;
if ( ! F_36 ( V_53 ) ) {
V_264 = snprintf ( V_261 , V_266 , L_59 , V_26 -> V_29 ) ;
if ( V_264 >= V_266 ) {
F_19 ( V_261 , V_266 ) ;
return - V_267 ;
}
} else {
F_8 ( F_35 ( V_53 ) ) ;
V_36 = F_137 ( V_53 -> V_268 , V_261 , NULL ,
V_266 ) ;
if ( V_36 ) {
F_19 ( V_261 , V_266 ) ;
return - V_6 ;
}
V_264 = strlen ( V_261 ) ;
}
++ V_264 ;
V_262 = V_261 + V_264 ;
V_263 = V_266 - V_264 ;
while ( V_254 > 0 ) {
int V_269 = sizeof( * V_257 ) ;
int V_270 ;
struct V_32 * V_33 ;
char * V_271 ;
char * V_272 ;
char * V_273 ;
char * V_274 ;
V_36 = - V_6 ;
if ( V_254 < sizeof( * V_257 ) )
break;
V_257 = ( F_138 ( V_257 ) ) ( V_63 + V_265 ) ;
if ( V_257 -> V_275 != 0 )
break;
if ( V_257 -> V_276 == 0 )
break;
if ( V_257 -> V_277 != sizeof( V_278 ) )
break;
V_269 += V_257 -> V_276 * V_257 -> V_277 ;
if ( V_254 < V_269 )
break;
if ( V_255 )
F_139 ( V_257 ) ;
if ( V_257 -> V_279 > V_266 ) {
F_2 ( L_60 , V_257 -> V_279 ) ;
break;
}
if ( V_257 -> V_279 < V_269 )
break;
V_265 += V_257 -> V_279 ;
V_254 -= V_257 -> V_279 ;
if ( V_254 < 0 )
break;
if ( V_257 -> V_280 > V_253 ) {
F_2 ( L_61 ,
V_257 -> V_280 , V_253 ) ;
break;
}
if ( V_260 >= V_257 -> V_280 ) {
F_2 ( L_62 ,
V_260 , V_257 -> V_280 ) ;
break;
}
V_260 = V_257 -> V_280 ;
V_270 = V_257 -> V_281 == V_282 ;
memset ( V_262 , 0 , V_263 ) ;
V_271 = V_262 ;
V_264 = 0 ;
strcpy ( V_271 , V_16 -> V_19 ) ;
V_272 = strrchr ( V_271 , '-' ) ;
if ( V_272 == NULL ) {
F_2 ( L_63 ,
V_252 -> V_47 , V_271 ) ;
break;
}
V_264 = V_272 - V_271 ;
V_271 [ V_264 ] = 0 ;
V_264 += sprintf ( V_271 + V_264 , L_64 ,
V_270 ? L_65 : L_66 , V_257 -> V_283 ) ;
V_272 = V_270 ? L_67 : L_68 ,
V_264 += sprintf ( V_271 + V_264 , L_69 , V_272 , V_261 ) ;
F_140 ( & V_259 , V_271 ) ;
V_33 = F_141 ( V_271 ) ;
if ( V_33 == NULL ) {
F_5 ( V_18 , L_70 ,
V_252 -> V_47 , V_271 ) ;
V_36 = 0 ;
continue;
}
++ V_264 ;
V_273 = V_262 + V_264 ;
V_264 += sprintf ( V_273 , L_71 , V_272 , L_72 ) ;
V_274 = V_262 + V_264 ;
F_48 ( & V_33 -> V_66 . V_67 . V_74 ) ;
if ( V_33 -> V_66 . V_67 . V_68 == NULL ) {
F_49 ( & V_33 -> V_66 . V_67 . V_74 ) ;
V_36 = 0 ;
continue;
}
V_36 = F_142 ( V_33 -> V_66 . V_67 . V_68 ,
V_257 -> V_66 . V_284 [ 0 ] ,
(struct V_285 * ) V_274 ) ;
F_49 ( & V_33 -> V_66 . V_67 . V_74 ) ;
if ( V_36 < 0 ) {
F_2 ( L_73 ,
F_143 ( V_257 -> V_66 . V_284 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_74 ,
V_274 , F_143 ( V_257 -> V_66 . V_284 [ 0 ] ) ) ;
V_264 += strlen ( V_274 ) ;
V_264 += sprintf ( V_262 + V_264 , L_75 , V_257 -> V_286 ) ;
F_8 ( V_264 < V_263 ) ;
F_144 ( & V_259 , 1 , V_273 ) ;
V_36 = - V_37 ;
V_51 = F_145 ( V_287 , & V_259 ) ;
if ( V_51 == NULL ) {
F_2 ( L_76 ) ;
break;
}
F_5 ( V_18 , L_77 V_288 L_4 V_288 L_78 ,
V_260 , V_253 , V_271 , V_273 ) ;
V_36 = F_146 ( V_51 ) ;
F_147 ( V_51 ) ;
if ( V_36 )
F_5 ( V_18 , L_79 ,
V_271 , V_36 ) ;
}
F_19 ( V_261 , V_266 ) ;
return V_36 ;
}
static int F_148 ( struct V_32 * V_33 ,
struct V_15 * V_16 )
{
struct V_146 * V_147 = NULL ;
struct V_25 * V_26 = & V_16 -> V_30 ;
struct V_289 * V_290 ;
struct V_291 * V_292 ;
struct V_293 * V_133 ;
struct V_294 * * V_295 ;
int V_296 ;
bool V_297 = true ;
bool V_255 = false ;
int V_298 ;
int V_299 ;
int V_36 ;
V_296 = V_300 ;
if ( V_26 -> V_41 == 0 )
V_296 = V_301 ;
F_24 ( V_295 , sizeof( * V_295 ) * V_296 ) ;
if ( V_295 == NULL )
GOTO ( V_248 , V_36 = - V_37 ) ;
for ( V_298 = 0 ; V_298 < V_296 ; V_298 ++ ) {
V_295 [ V_298 ] = F_149 ( V_302 ) ;
if ( V_295 [ V_298 ] == NULL )
GOTO ( V_248 , V_36 = - V_37 ) ;
}
V_303:
F_8 ( F_150 ( V_16 ) ) ;
F_8 ( F_151 ( & V_16 -> V_40 ) ) ;
V_147 = F_152 ( F_103 ( V_16 -> V_24 ) ,
& V_304 ) ;
if ( V_147 == NULL )
GOTO ( V_248 , V_36 = - V_37 ) ;
V_36 = F_153 ( V_147 , V_151 , V_305 ) ;
if ( V_36 )
GOTO ( V_248 , V_36 ) ;
V_290 = F_104 ( & V_147 -> V_153 , & V_306 ) ;
F_8 ( V_290 != NULL ) ;
F_8 ( sizeof( V_290 -> V_307 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_154 ( V_290 -> V_307 , V_16 -> V_19 , sizeof( V_290 -> V_307 ) )
>= sizeof( V_290 -> V_307 ) )
GOTO ( V_248 , V_36 = - V_267 ) ;
V_290 -> V_308 = V_26 -> V_41 + 1 ;
V_290 -> V_309 = V_16 -> V_44 ;
V_290 -> V_310 = V_311 ;
V_290 -> V_312 = V_296 ;
V_133 = F_155 ( V_147 , V_296 , 1 , V_313 ,
V_314 ) ;
if ( V_133 == NULL )
GOTO ( V_248 , V_36 = - V_37 ) ;
for ( V_298 = 0 ; V_298 < V_296 ; V_298 ++ )
F_156 ( V_133 , V_295 [ V_298 ] , 0 , V_266 ) ;
F_106 ( V_147 ) ;
V_36 = F_107 ( V_147 ) ;
if ( V_36 )
GOTO ( V_248 , V_36 ) ;
V_292 = F_108 ( & V_147 -> V_153 , & V_315 ) ;
if ( V_292 -> V_316 < V_292 -> V_317 )
GOTO ( V_248 , V_36 = - V_6 ) ;
V_26 -> V_41 = V_292 -> V_317 ;
V_297 = V_292 -> V_317 == V_292 -> V_316 ;
F_5 ( V_18 , L_80 V_288 L_81 ,
V_292 -> V_317 , V_297 == false ) ;
V_299 = F_157 ( V_147 , V_147 -> V_318 , 0 ) ;
if ( V_299 < 0 )
GOTO ( V_248 , V_36 = V_299 ) ;
if ( V_299 > V_296 << V_311 )
GOTO ( V_248 , V_36 = - V_6 ) ;
if ( V_299 == 0 ) {
if ( ! V_297 )
V_36 = - V_6 ;
GOTO ( V_248 , V_36 ) ;
}
V_255 = ! ! F_158 ( V_147 ) ;
#if V_319 < F_159 ( 3 , 2 , 50 , 0 )
if ( F_42 ( V_147 -> V_320 -> V_321 ) )
V_255 = ! V_255 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_298 = 0 ; V_298 < V_296 && V_299 > 0 ; V_298 ++ ) {
int V_322 ;
void * V_56 ;
V_56 = F_160 ( V_295 [ V_298 ] ) ;
V_322 = F_136 ( V_33 , V_16 , V_292 -> V_317 , V_56 ,
F_161 ( int , V_299 , V_266 ) ,
V_255 ) ;
F_162 ( V_295 [ V_298 ] ) ;
if ( V_322 < 0 ) {
F_163 ( L_82 ,
V_16 -> V_19 , V_322 ) ;
break;
}
V_299 -= V_266 ;
}
V_248:
if ( V_147 )
F_105 ( V_147 ) ;
if ( V_36 == 0 && ! V_297 )
goto V_303;
if ( V_295 ) {
for ( V_298 = 0 ; V_298 < V_296 ; V_298 ++ ) {
if ( V_295 [ V_298 ] == NULL )
break;
F_164 ( V_295 [ V_298 ] ) ;
}
F_19 ( V_295 , sizeof( * V_295 ) * V_296 ) ;
}
return V_36 ;
}
static int F_165 ( struct V_32 * V_252 ,
struct V_15 * V_16 ,
int V_323 )
{
struct V_244 * V_245 , * V_324 = NULL ;
struct V_94 * V_325 ;
struct V_52 * V_53 = NULL ;
int V_36 = 0 , V_326 = 0 ;
bool V_327 = false ;
F_8 ( V_16 ) ;
F_8 ( F_151 ( & V_16 -> V_40 ) ) ;
if ( F_16 ( V_16 ) && V_323 )
return 0 ;
if ( V_16 -> V_30 . V_43 )
V_53 = F_33 ( V_16 -> V_30 . V_43 ) ;
V_245 = F_133 ( V_252 , V_246 ) ;
if ( ! V_245 ) {
F_2 ( L_83 ) ;
return - V_6 ;
}
F_166 ( V_325 ) ;
if ( V_325 == NULL )
return - V_37 ;
V_324 = F_133 ( V_252 , V_250 ) ;
if ( V_323 ) {
GOTO ( V_328 , V_36 = - V_329 ) ;
}
if ( F_16 ( V_16 ) ) {
F_167 ( V_16 -> V_19 ) ;
V_327 = true ;
}
V_36 = F_168 ( NULL , V_245 , V_16 -> V_19 ,
& V_16 -> V_30 ) ;
V_328:
F_132 ( V_245 ) ;
if ( V_324 )
F_132 ( V_324 ) ;
if ( V_326 )
F_69 ( V_325 , & V_252 -> V_107 , NULL ) ;
F_169 ( V_325 ) ;
if ( V_327 ) {
F_8 ( F_16 ( V_16 ) ) ;
F_170 ( V_16 -> V_19 ) ;
F_171 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_14 ) ) ;
}
return V_36 ;
}
int F_31 ( struct V_32 * V_252 , struct V_15 * V_16 )
{
struct V_135 V_136 = { 0 } ;
T_1 V_161 = V_330 ;
int V_36 = 0 , V_331 ;
F_8 ( V_16 ) ;
F_41 ( & V_16 -> V_40 ) ;
if ( V_16 -> V_31 ) {
F_43 ( & V_16 -> V_40 ) ;
return 0 ;
}
F_172 ( V_332 , 20 ) ;
F_5 ( V_10 , L_84 , V_16 -> V_19 ,
V_16 -> V_30 . V_29 , V_16 -> V_30 . V_41 + 1 ) ;
V_331 = F_109 ( V_252 -> V_66 . V_67 . V_333 , NULL , V_334 , NULL ,
V_335 , & V_161 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_136 ) ;
if ( V_331 == 0 ) {
F_9 ( V_16 ) ;
V_36 = F_173 ( & V_136 , ( void * ) V_16 ) ;
F_8 ( V_36 == 0 ) ;
} else {
F_5 ( V_10 , L_85 , V_331 ) ;
V_16 -> V_90 = 1 ;
F_9 ( V_16 ) ;
}
if ( F_150 ( V_16 ) ) {
V_36 = 0 ;
if ( V_331 == 0 )
V_36 = F_148 ( V_252 , V_16 ) ;
} else {
V_36 = F_165 ( V_252 , V_16 , V_331 != 0 ) ;
}
F_5 ( V_10 , L_86 ,
V_252 -> V_47 , V_16 -> V_19 , V_36 ? L_87 : L_88 , V_36 ) ;
F_43 ( & V_16 -> V_40 ) ;
if ( ! V_331 ) {
V_331 = F_112 ( V_252 -> V_66 . V_67 . V_333 , NULL ,
V_335 , & V_136 ) ;
if ( V_331 )
F_2 ( L_89 , V_331 ) ;
}
return V_36 ;
}
static int F_174 ( struct V_32 * V_33 , T_4 V_2 , void * V_262 )
{
struct V_123 * V_51 = V_262 ;
struct V_25 * V_26 = NULL ;
char * V_13 ;
int V_36 = 0 ;
switch( V_51 -> V_336 ) {
case V_337 : {
struct V_184 * V_185 ;
if ( F_175 ( V_51 , 1 ) !=
sizeof( struct V_184 ) )
GOTO ( V_248 , V_36 = - V_6 ) ;
V_185 = (struct V_184 * ) F_176 ( V_51 , 1 ) ;
F_5 ( V_10 , L_90 ,
V_185 -> V_191 , V_185 -> V_213 ) ;
V_36 = F_115 ( V_33 -> V_66 . V_67 . V_333 , V_185 ) ;
break;
}
case V_338 :
F_2 ( L_91 ) ;
V_36 = - V_339 ;
break;
case V_340 : {
V_36 = F_177 ( V_51 ) ;
break;
}
case V_341 : {
struct V_15 * V_16 ;
struct V_34 * V_35 ;
V_13 = F_178 ( V_51 , 1 ) ;
V_26 = (struct V_25 * ) F_176 ( V_51 , 2 ) ;
V_35 = * (struct V_34 * * ) F_176 ( V_51 , 3 ) ;
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
V_16 -> V_30 . V_42 |= V_342 ;
V_36 = F_31 ( V_33 , V_16 ) ;
if ( V_36 == 0 && V_16 -> V_22 != NULL ) {
if ( F_46 ( & V_33 -> V_66 . V_67 . V_68 ->
V_71 , V_72 ) ) {
V_36 = F_31 ( V_33 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_343 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_12 ( V_343 ) ;
}
if ( V_36 )
F_2 ( L_93 , V_36 ) ;
}
F_12 ( V_16 ) ;
break;
}
case V_344 : {
V_13 = F_178 ( V_51 , 1 ) ;
if ( V_51 -> V_345 >= 2 )
V_26 = (struct V_25 * ) F_176 (
V_51 , 2 ) ;
V_36 = F_40 ( V_13 , V_26 ) ;
break;
}
default: {
F_2 ( L_94 , V_51 -> V_336 ) ;
GOTO ( V_248 , V_36 = - V_6 ) ;
}
}
V_248:
return V_36 ;
}
int T_6 F_179 ( void )
{
return F_180 ( & V_346 , NULL , NULL ,
V_347 , NULL ) ;
}
static void F_181 ( void )
{
F_182 ( V_347 ) ;
}
