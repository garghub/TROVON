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
F_5 ( V_11 , L_3 , V_1 ,
V_4 -> V_1 [ 0 ] , V_4 -> V_1 [ 1 ] , ( char * ) & V_4 -> V_1 [ 0 ] ) ;
return 0 ;
}
int F_6 ( char * V_12 , struct V_3 * V_4 , int type )
{
return F_1 ( V_12 , strlen ( V_12 ) , V_4 , type ) ;
}
static int F_7 ( char * V_13 , struct V_3 * V_4 , int type )
{
char * V_14 ;
int V_2 ;
V_14 = strrchr ( V_13 , '-' ) ;
if ( ! V_14 )
V_2 = strlen ( V_13 ) ;
else
V_2 = V_14 - V_13 ;
return F_1 ( V_13 , V_2 , V_4 , type ) ;
}
static int F_8 ( struct V_15 * V_16 )
{
F_9 ( & V_16 -> V_17 ) ;
F_5 ( V_18 , L_4 , V_16 -> V_19 ,
F_10 ( & V_16 -> V_17 ) ) ;
return 0 ;
}
static void F_11 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_4 , V_16 -> V_19 ,
F_10 ( & V_16 -> V_17 ) ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( F_13 ( & V_16 -> V_17 , & V_20 ) ) {
F_14 ( & V_16 -> V_21 ) ;
F_15 ( & V_20 ) ;
F_5 ( V_11 , L_5 , V_16 -> V_19 ) ;
if ( V_16 -> V_22 )
F_11 ( V_16 -> V_22 ) ;
if ( V_16 -> V_23 )
F_11 ( V_16 -> V_23 ) ;
if ( V_16 -> V_24 )
F_11 ( V_16 -> V_24 ) ;
if ( F_16 ( V_16 ) )
F_17 ( V_16 -> V_19 ) ;
F_18 ( V_16 -> V_25 ) ;
F_19 ( V_16 ) ;
}
}
static
struct V_15 * F_20 ( char * V_13 ,
struct V_26 * V_27 )
{
struct V_15 * V_16 ;
struct V_15 * V_28 = NULL ;
void * V_29 ;
F_12 ( V_13 != NULL ) ;
V_29 = V_27 ? V_27 -> V_30 : NULL ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_29 != V_16 -> V_31 . V_30 )
continue;
if ( strcmp ( V_13 , V_16 -> V_19 ) == 0 ) {
V_28 = V_16 ;
break;
}
}
if ( V_28 ) {
F_9 ( & V_28 -> V_17 ) ;
F_12 ( V_28 -> V_32 == 0 || F_16 ( V_28 ) == 0 ) ;
}
F_15 ( & V_20 ) ;
return V_28 ;
}
static
struct V_15 * F_23 ( struct V_33 * V_34 ,
char * V_13 ,
int type ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_15 * V_16 ;
int V_37 ;
F_5 ( V_11 , L_6 , V_13 ,
V_27 ? V_27 -> V_30 : NULL ) ;
V_16 = F_24 ( sizeof( * V_16 ) + strlen ( V_13 ) + 1 , V_38 ) ;
if ( ! V_16 )
return F_25 ( - V_39 ) ;
strcpy ( V_16 -> V_19 , V_13 ) ;
if ( V_27 )
V_16 -> V_31 = * V_27 ;
else
V_16 -> V_31 . V_40 = V_41 ;
F_26 ( & V_16 -> V_42 ) ;
V_16 -> V_31 . V_43 = 0 ;
V_16 -> V_31 . V_44 = 0 ;
V_16 -> V_31 . V_45 = V_36 ;
V_16 -> V_46 = type ;
F_27 ( & V_16 -> V_17 , 1 ) ;
V_16 -> V_25 = F_28 ( V_34 -> V_47 ) ;
if ( F_16 ( V_16 ) ) {
F_29 ( V_13 ) ;
V_16 -> V_31 . V_48 = V_34 -> V_49 ;
}
V_37 = F_7 ( V_13 , & V_16 -> V_50 , type ) ;
F_21 ( & V_20 ) ;
F_30 ( & V_16 -> V_21 , & V_51 ) ;
F_15 ( & V_20 ) ;
if ( V_37 ) {
F_11 ( V_16 ) ;
return F_25 ( V_37 ) ;
}
if ( F_16 ( V_16 ) ) {
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 && V_37 != - V_52 )
F_2 ( L_7 , V_37 ) ;
}
return V_16 ;
}
static struct V_15 * F_32 ( struct V_33 * V_34 ,
char * V_12 ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_26 V_53 = * V_27 ;
struct V_54 * V_55 = F_33 ( V_36 ) ;
struct V_15 * V_16 ;
char V_13 [ 32 ] ;
if ( F_34 ( V_55 ) )
return NULL ;
if ( F_35 ( V_55 ) && V_53 . V_30 )
return NULL ;
F_12 ( strlen ( V_12 ) < sizeof( V_13 ) / 2 ) ;
strcpy ( V_13 , V_12 ) ;
if ( F_36 ( V_55 ) ) {
F_12 ( V_53 . V_30 == NULL ) ;
V_53 . V_30 = V_36 ;
strcat ( V_13 , L_8 ) ;
} else {
F_12 ( V_53 . V_30 != NULL ) ;
strcat ( V_13 , L_9 ) ;
}
V_16 = F_23 ( V_34 , V_13 , V_9 , & V_53 , V_36 ) ;
return V_16 ;
}
static struct V_15 * F_37 ( struct V_33 * V_34 ,
struct V_26 * V_27 , struct V_35 * V_36 )
{
struct V_26 V_53 = * V_27 ;
struct V_15 * V_16 ;
V_53 . V_30 = V_36 ;
V_16 = F_23 ( V_34 , V_56 , V_10 ,
& V_53 , V_36 ) ;
return V_16 ;
}
static int F_38 ( struct V_33 * V_34 , char * V_13 ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_54 * V_55 = F_33 ( V_36 ) ;
struct V_15 * V_16 ;
struct V_15 * V_57 ;
struct V_15 * V_58 ;
char V_59 [ 32 ] ;
char * V_60 ;
int V_37 ;
F_5 ( V_11 , L_10 , V_13 , V_27 -> V_30 ) ;
V_60 = strrchr ( V_13 , '-' ) ;
if ( V_60 == NULL || V_60 - V_13 > 8 ) {
F_2 ( L_11 , V_13 ) ;
return - V_6 ;
}
memcpy ( V_59 , V_13 , V_60 - V_13 ) ;
strcpy ( V_59 + ( V_60 - V_13 ) , L_12 ) ;
V_57 = F_20 ( V_59 , NULL ) ;
if ( V_57 == NULL ) {
V_57 = F_23 ( V_34 , V_59 ,
V_8 , NULL , NULL ) ;
if ( F_39 ( V_57 ) ) {
F_2 ( L_13 , V_59 ) ;
V_37 = F_40 ( V_57 ) ;
goto V_61;
}
}
V_58 = F_37 ( V_34 , V_27 , V_36 ) ;
if ( F_39 ( V_58 ) ) {
V_37 = F_40 ( V_58 ) ;
F_2 ( L_14 ,
V_34 -> V_49 , V_37 ) ;
goto V_62;
}
V_16 = F_23 ( V_34 , V_13 , V_7 , V_27 , V_36 ) ;
if ( F_39 ( V_16 ) ) {
F_2 ( L_15 , V_13 ) ;
V_37 = F_40 ( V_16 ) ;
goto V_63;
}
V_16 -> V_23 = V_57 ;
V_16 -> V_24 = V_58 ;
F_12 ( V_55 -> V_64 ) ;
if ( ! ( V_55 -> V_64 -> V_65 & V_66 ) ) {
struct V_15 * V_67 ;
* strrchr ( V_59 , '-' ) = 0 ;
V_67 = F_32 ( V_34 , V_59 , V_27 , V_36 ) ;
if ( F_39 ( V_67 ) ) {
V_37 = F_40 ( V_67 ) ;
goto V_68;
}
V_16 -> V_22 = V_67 ;
}
return 0 ;
V_68:
F_11 ( V_16 ) ;
V_63:
F_11 ( V_58 ) ;
V_62:
F_11 ( V_57 ) ;
V_61:
return V_37 ;
}
static int F_41 ( char * V_13 , struct V_26 * V_27 )
{
struct V_15 * V_16 ;
struct V_15 * V_23 = NULL ;
struct V_15 * V_24 = NULL ;
struct V_15 * V_22 = NULL ;
int V_37 = 0 ;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( V_16 == NULL )
return - V_52 ;
F_42 ( & V_16 -> V_42 ) ;
if ( F_43 ( V_16 -> V_32 ) ) {
F_44 ( & V_16 -> V_42 ) ;
F_11 ( V_16 ) ;
return V_37 ;
}
V_16 -> V_32 = 1 ;
V_22 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_44 ( & V_16 -> V_42 ) ;
if ( V_22 ) {
F_42 ( & V_22 -> V_42 ) ;
V_22 -> V_32 = 1 ;
F_44 ( & V_22 -> V_42 ) ;
F_11 ( V_22 ) ;
}
F_21 ( & V_20 ) ;
V_23 = V_16 -> V_23 ;
V_16 -> V_23 = NULL ;
V_24 = V_16 -> V_24 ;
V_16 -> V_24 = NULL ;
F_15 ( & V_20 ) ;
if ( V_23 )
F_11 ( V_23 ) ;
if ( V_24 ) {
F_42 ( & V_24 -> V_42 ) ;
V_24 -> V_32 = 1 ;
F_44 ( & V_24 -> V_42 ) ;
F_11 ( V_24 ) ;
}
F_11 ( V_16 ) ;
F_11 ( V_16 ) ;
F_5 ( V_11 , L_16 , V_13 ? V_13 : L_17 ,
V_37 ) ;
return V_37 ;
}
int F_45 ( struct V_69 * V_70 , void * V_71 )
{
struct V_33 * V_34 = V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_15 * V_16 ;
F_46 ( V_34 ) ;
V_73 = V_34 -> V_76 . V_77 . V_78 ;
V_75 = & V_73 -> V_79 ;
F_47 ( V_70 , L_18 ,
F_48 ( V_75 , V_80 ) ? L_19 : L_20 ) ;
F_47 ( V_70 , L_21 ) ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_16 -> V_22 == NULL )
continue;
F_47 ( V_70 , L_22 ,
V_16 -> V_19 ,
V_16 -> V_22 -> V_31 . V_43 ) ;
}
F_15 ( & V_20 ) ;
F_49 ( V_34 ) ;
return 0 ;
}
static void F_50 ( struct V_15 * V_16 )
{
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_51 ( & V_16 -> V_25 -> V_81 -> V_76 . V_77 . V_82 ) ;
if ( V_16 -> V_25 -> V_81 -> V_76 . V_77 . V_83 != 0 ) {
F_5 ( V_11 , L_23 , V_16 -> V_19 ) ;
F_31 ( V_16 -> V_25 -> V_81 , V_16 ) ;
} else {
F_5 ( V_11 , L_24 ,
V_16 -> V_19 ) ;
}
F_52 ( & V_16 -> V_25 -> V_81 -> V_76 . V_77 . V_82 ) ;
}
static int F_53 ( void * V_71 )
{
bool V_84 = true ;
F_5 ( V_11 , L_25 ) ;
F_21 ( & V_20 ) ;
V_85 |= V_86 ;
while ( 1 ) {
struct V_87 V_88 ;
struct V_15 * V_16 , * V_89 ;
int rand = F_54 () & V_90 ;
int V_91 = ! ! ( V_85 & V_92 ) ;
int V_93 ;
V_85 &= ~ ( V_94 | V_95 ) ;
F_15 ( & V_20 ) ;
if ( V_84 ) {
V_84 = false ;
F_55 ( & V_96 ) ;
}
V_93 = V_97 * V_98 ;
V_93 += rand * V_98 / 100 ;
V_88 = F_56 ( V_93 , NULL , NULL ) ;
F_57 ( V_99 , V_85 & ( V_92 | V_100 ) ,
& V_88 ) ;
V_89 = NULL ;
F_21 ( & V_20 ) ;
V_85 &= ~ V_100 ;
F_22 (cld, &config_llog_list,
cld_list_chain) {
if ( ! V_16 -> V_101 )
continue;
F_15 ( & V_20 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_89 )
F_11 ( V_89 ) ;
V_89 = V_16 ;
V_16 -> V_101 = 0 ;
if ( F_58 ( ! V_91 ) )
F_50 ( V_16 ) ;
F_21 ( & V_20 ) ;
}
F_15 ( & V_20 ) ;
if ( V_89 )
F_11 ( V_89 ) ;
if ( F_43 ( V_91 ) ) {
F_21 ( & V_20 ) ;
break;
}
V_88 = (struct V_87 ) { 0 } ;
F_57 ( V_99 , V_85 & ( V_94 | V_92 ) ,
& V_88 ) ;
F_21 ( & V_20 ) ;
}
V_85 &= ~ V_86 ;
F_15 ( & V_20 ) ;
F_55 ( & V_102 ) ;
F_5 ( V_11 , L_26 ) ;
return 0 ;
}
static void F_59 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_27 ,
V_16 -> V_19 , F_10 ( & V_16 -> V_17 ) ,
V_16 -> V_32 , V_85 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_42 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_32 || V_16 -> V_101 ) {
F_44 ( & V_16 -> V_42 ) ;
return;
}
F_8 ( V_16 ) ;
V_16 -> V_101 = 1 ;
F_44 ( & V_16 -> V_42 ) ;
F_21 ( & V_20 ) ;
if ( V_85 & V_92 ) {
F_15 ( & V_20 ) ;
V_16 -> V_101 = 0 ;
F_11 ( V_16 ) ;
} else {
V_85 |= V_94 ;
F_15 ( & V_20 ) ;
F_60 ( & V_99 ) ;
}
}
static int F_61 ( const struct V_103 * V_104 , struct V_33 * V_34 )
{
struct V_105 * V_106 ;
int V_37 ;
V_37 = F_62 ( V_104 , V_34 , & V_34 -> V_107 , V_108 , V_34 ,
& V_109 ) ;
if ( V_37 )
return V_37 ;
V_106 = F_63 ( V_34 , V_108 ) ;
F_12 ( V_106 ) ;
F_64 ( V_106 ) ;
F_65 ( V_106 ) ;
return 0 ;
}
static int F_66 ( const struct V_103 * V_104 , struct V_33 * V_34 )
{
struct V_105 * V_106 ;
V_106 = F_63 ( V_34 , V_108 ) ;
if ( V_106 )
F_67 ( V_104 , V_106 ) ;
return 0 ;
}
static int F_68 ( struct V_33 * V_34 , enum V_110 V_111 )
{
int V_37 = 0 ;
int V_112 ;
switch ( V_111 ) {
case V_113 :
break;
case V_114 :
if ( F_69 ( & V_115 ) ) {
F_12 ( V_85 & V_86 ) ;
V_112 = V_92 ;
} else {
V_112 = V_94 | V_100 ;
}
F_21 ( & V_20 ) ;
V_85 |= V_112 ;
F_15 ( & V_20 ) ;
F_60 ( & V_99 ) ;
if ( V_112 & V_92 )
F_70 ( & V_102 ) ;
F_71 ( V_34 ) ;
V_37 = F_66 ( NULL , V_34 ) ;
if ( V_37 != 0 )
F_2 ( L_28 ) ;
break;
}
return V_37 ;
}
static int F_72 ( struct V_33 * V_34 )
{
if ( V_34 -> V_116 -> V_117 <= 1 )
F_73 () ;
F_74 ( V_34 ) ;
F_75 () ;
return F_76 ( V_34 ) ;
}
static int F_77 ( struct V_33 * V_34 , struct V_118 * V_53 )
{
struct V_119 V_120 = { NULL } ;
int V_37 ;
F_78 () ;
V_37 = F_79 ( V_34 , V_53 ) ;
if ( V_37 )
goto V_121;
V_37 = F_61 ( NULL , V_34 ) ;
if ( V_37 ) {
F_2 ( L_29 ) ;
goto V_122;
}
F_80 ( & V_120 ) ;
F_81 ( V_34 , V_120 . V_123 , V_120 . V_124 ) ;
F_82 ( V_34 ) ;
if ( F_83 ( & V_115 ) == 1 ) {
V_85 = 0 ;
F_84 ( & V_99 ) ;
V_37 = F_40 ( F_85 ( F_53 , NULL ,
L_30 ) ) ;
if ( F_86 ( V_37 ) ) {
F_2 ( L_31 ,
V_34 -> V_49 , V_37 ) ;
goto V_122;
}
V_37 = 0 ;
F_70 ( & V_96 ) ;
}
return V_37 ;
V_122:
F_76 ( V_34 ) ;
V_121:
F_75 () ;
return V_37 ;
}
static int F_87 ( struct V_125 * V_126 , struct V_127 * V_128 ,
void * V_71 , int V_129 )
{
struct V_130 V_131 ;
struct V_15 * V_16 = (struct V_15 * ) V_71 ;
int V_37 = 0 ;
switch ( V_129 ) {
case V_132 :
F_88 ( V_126 , L_32 ) ;
F_89 ( V_126 , & V_131 ) ;
V_37 = F_90 ( & V_131 , V_133 ) ;
break;
case V_134 :
F_88 ( V_126 , L_33 ) ;
F_5 ( V_11 , L_34 V_135 L_35 ,
F_91 ( V_126 -> V_136 ) ,
( char * ) & V_126 -> V_136 -> V_137 . V_1 [ 0 ] ) ;
if ( ! V_16 ) {
F_5 ( V_18 , L_36 ) ;
break;
}
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_16 -> V_32 ) {
F_5 ( V_11 , L_37 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
if ( ! V_126 -> V_138 ||
! V_126 -> V_138 -> V_81 -> V_76 . V_77 . V_83 ) {
F_5 ( V_11 , L_38 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
F_59 ( V_16 ) ;
F_11 ( V_16 ) ;
break;
default:
F_4 () ;
}
return V_37 ;
}
static int F_92 ( struct V_139 * exp ,
struct V_140 * V_141 )
{
struct V_142 * V_143 ;
struct V_140 * V_144 , * V_145 ;
int V_37 ;
V_143 = F_93 ( F_94 ( exp ) ,
& V_146 , V_147 ,
V_148 ) ;
if ( ! V_143 )
return - V_39 ;
V_144 = F_95 ( & V_143 -> V_149 , & V_150 ) ;
if ( ! V_144 ) {
F_96 ( V_143 ) ;
return - V_39 ;
}
memcpy ( V_144 , V_141 , sizeof( * V_144 ) ) ;
F_97 ( V_143 ) ;
V_143 -> V_151 = V_152 ;
V_37 = F_98 ( V_143 ) ;
if ( ! V_37 ) {
V_145 = F_99 ( & V_143 -> V_149 , & V_150 ) ;
memcpy ( V_141 , V_145 , sizeof( * V_145 ) ) ;
}
F_96 ( V_143 ) ;
return V_37 ;
}
static int F_100 ( struct V_139 * exp , struct V_153 * V_154 ,
T_2 type , T_3 * V_155 , T_2 V_156 ,
T_1 * V_157 , void * V_158 , void * V_159 , void * V_160 ,
void * V_71 , T_2 V_161 , void * V_162 ,
struct V_130 * V_131 )
{
struct V_15 * V_16 = (struct V_15 * ) V_71 ;
struct V_163 V_164 = {
. V_165 = type ,
. V_166 = V_156 ,
. V_167 = F_87 ,
. V_168 = V_169 ,
} ;
struct V_142 * V_143 ;
int V_170 = F_16 ( V_16 ) ;
int V_37 ;
F_5 ( V_11 , L_39 , V_16 -> V_19 ,
V_16 -> V_50 . V_1 [ 0 ] ) ;
V_143 = F_93 ( F_94 ( exp ) ,
& V_171 , V_172 ,
V_173 ) ;
if ( V_143 == NULL )
return - V_39 ;
F_101 ( & V_143 -> V_149 , & V_174 , V_175 , 0 ) ;
F_97 ( V_143 ) ;
if ( V_16 -> V_31 . V_45 ) {
struct V_54 * V_55 = F_33 ( V_16 -> V_31 . V_45 ) ;
if ( V_55 && F_36 ( V_55 ) )
V_170 = 1 ;
}
V_143 -> V_151 = V_170 ? 5 : V_176 ;
V_37 = F_102 ( exp , & V_143 , & V_164 , & V_16 -> V_50 , NULL , V_157 ,
NULL , 0 , V_177 , V_131 , 0 ) ;
F_96 ( V_143 ) ;
return V_37 ;
}
static void F_103 ( struct V_33 * V_178 )
{
F_21 ( & V_20 ) ;
V_85 |= V_94 ;
F_15 ( & V_20 ) ;
F_60 ( & V_99 ) ;
}
static int F_104 ( struct V_139 * exp ,
struct V_179 * V_180 )
{
struct V_142 * V_143 ;
struct V_179 * V_181 , * V_182 ;
int V_37 ;
V_143 = F_93 ( F_94 ( exp ) ,
& V_183 , V_147 ,
V_184 ) ;
if ( V_143 == NULL )
return - V_39 ;
V_181 = F_95 ( & V_143 -> V_149 , & V_185 ) ;
if ( ! V_181 ) {
F_96 ( V_143 ) ;
return - V_39 ;
}
memcpy ( V_181 , V_180 , sizeof( * V_181 ) ) ;
F_97 ( V_143 ) ;
F_5 ( V_11 , L_40 , V_180 -> V_186 ) ;
V_143 -> V_151 = V_187 ;
V_37 = F_98 ( V_143 ) ;
if ( ! V_37 ) {
V_182 = F_99 ( & V_143 -> V_149 ,
& V_185 ) ;
memcpy ( V_180 , V_182 , sizeof( * V_182 ) ) ;
F_5 ( V_11 , L_41 ,
V_180 -> V_186 , V_180 -> V_188 ) ;
}
F_96 ( V_143 ) ;
return V_37 ;
}
static int F_105 ( const struct V_103 * V_104 , struct V_139 * exp ,
T_4 V_189 , void * V_190 , T_4 V_191 ,
void * V_192 , struct V_193 * V_194 )
{
int V_37 = - V_6 ;
if ( F_106 ( V_195 ) ) {
struct V_72 * V_73 = F_94 ( exp ) ;
int V_196 ;
if ( V_191 != sizeof( int ) )
return - V_6 ;
V_196 = * ( int * ) V_192 ;
F_5 ( V_11 , L_42 ,
V_73 -> V_197 -> V_49 , V_196 ,
V_73 -> V_198 , V_73 -> V_199 ,
V_73 -> V_200 , V_73 -> V_197 -> V_201 ,
F_107 ( V_73 -> V_202 ) ) ;
if ( ( V_73 -> V_202 != V_203 &&
V_73 -> V_202 != V_204 ) || V_196 > 1 )
F_108 ( V_73 ) ;
return 0 ;
}
if ( F_106 ( V_205 ) ) {
struct V_140 * V_141 ;
V_141 = (struct V_140 * ) V_192 ;
V_37 = F_92 ( exp , V_141 ) ;
return V_37 ;
}
if ( F_106 ( V_206 ) ) {
struct V_207 * V_77 = & exp -> V_81 -> V_76 . V_77 ;
struct V_208 V_209 ;
if ( V_191 == 0 ) {
if ( V_77 -> V_210 . V_211 != V_212 )
return 0 ;
V_192 = L_43 ;
V_191 = 4 ;
}
V_37 = F_109 ( V_192 , & V_209 ) ;
if ( V_37 ) {
F_2 ( L_44 ,
( char * ) V_192 ) ;
return V_37 ;
}
if ( V_77 -> V_210 . V_211 == V_212 ) {
V_77 -> V_210 = V_209 ;
} else if ( memcmp ( & V_77 -> V_210 , & V_209 ,
sizeof( V_209 ) ) != 0 ) {
char V_213 [ 20 ] ;
F_110 ( & V_77 -> V_210 ,
V_213 , sizeof( V_213 ) ) ;
F_111 ( L_45 ,
( char * ) V_192 , V_213 ) ;
V_37 = - V_214 ;
}
return V_37 ;
}
return V_37 ;
}
static int F_112 ( const struct V_103 * V_104 , struct V_139 * exp ,
T_2 V_189 , void * V_190 , T_2 * V_191 , void * V_192 ,
struct V_153 * V_178 )
{
int V_37 = - V_6 ;
if ( F_106 ( V_215 ) ) {
struct V_72 * V_73 = F_94 ( exp ) ;
struct V_74 * V_71 = V_192 ;
if ( * V_191 == sizeof( * V_71 ) ) {
* V_71 = V_73 -> V_79 ;
V_37 = 0 ;
}
}
return V_37 ;
}
static int F_113 ( struct V_33 * V_34 ,
struct V_72 * V_73 ,
enum V_216 V_217 )
{
F_12 ( V_73 -> V_197 == V_34 ) ;
F_5 ( V_11 , L_46 , V_217 ) ;
switch ( V_217 ) {
case V_218 :
if ( F_48 ( & V_73 -> V_79 , V_80 ) )
F_114 () ;
break;
case V_219 :
break;
case V_220 : {
struct V_221 * V_222 = V_34 -> V_223 ;
F_115 ( V_222 , V_224 ) ;
break;
}
case V_225 :
F_5 ( V_18 , L_47 , V_34 -> V_49 ) ;
V_34 -> V_226 = 0 ;
F_103 ( V_34 ) ;
if ( F_48 ( & V_73 -> V_79 , V_80 ) )
F_116 () ;
break;
case V_227 :
break;
case V_228 :
case V_229 :
break;
default:
F_2 ( L_48 , V_217 ) ;
F_4 () ;
}
return 0 ;
}
static int F_117 ( struct V_33 * V_230 ,
struct V_15 * V_16 ,
T_1 V_231 ,
void * V_71 , int V_232 , bool V_233 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_54 * V_55 = F_33 ( V_27 -> V_45 ) ;
struct V_234 * V_235 ;
struct V_118 * V_53 ;
struct V_236 V_237 ;
T_5 V_238 = 0 ;
char * V_239 ;
char * V_240 ;
int V_241 ;
int V_242 ;
int V_37 = 0 ;
int V_243 = 0 ;
F_12 ( V_27 -> V_30 != NULL ) ;
F_12 ( V_27 -> V_45 == V_27 -> V_30 ) ;
V_239 = F_24 ( V_244 , V_38 ) ;
if ( V_239 == NULL )
return - V_39 ;
if ( ! F_36 ( V_55 ) ) {
V_242 = snprintf ( V_239 , V_244 , L_49 , V_27 -> V_30 ) ;
if ( V_242 >= V_244 ) {
F_19 ( V_239 ) ;
return - V_245 ;
}
} else {
F_12 ( F_35 ( V_55 ) ) ;
V_37 = F_118 ( V_55 -> V_246 , V_239 , NULL ,
V_244 ) ;
if ( V_37 ) {
F_19 ( V_239 ) ;
return - V_6 ;
}
V_242 = strlen ( V_239 ) ;
}
++ V_242 ;
V_240 = V_239 + V_242 ;
V_241 = V_244 - V_242 ;
while ( V_232 > 0 ) {
int V_247 = sizeof( * V_235 ) ;
int V_248 ;
struct V_33 * V_34 ;
char * V_249 ;
char * V_250 ;
char * V_251 ;
char * V_252 ;
V_37 = - V_6 ;
if ( V_232 < sizeof( * V_235 ) )
break;
V_235 = ( F_119 ( V_235 ) ) ( V_71 + V_243 ) ;
if ( V_235 -> V_253 != 0 )
break;
if ( V_235 -> V_254 == 0 )
break;
if ( V_235 -> V_255 != sizeof( V_256 ) )
break;
V_247 += V_235 -> V_254 * V_235 -> V_255 ;
if ( V_232 < V_247 )
break;
if ( V_233 )
F_120 ( V_235 ) ;
if ( V_235 -> V_257 > V_244 ) {
F_2 ( L_50 , V_235 -> V_257 ) ;
break;
}
if ( V_235 -> V_257 < V_247 )
break;
V_243 += V_235 -> V_257 ;
V_232 -= V_235 -> V_257 ;
if ( V_232 < 0 )
break;
if ( V_235 -> V_258 > V_231 ) {
F_2 ( L_51 ,
V_235 -> V_258 , V_231 ) ;
break;
}
if ( V_238 >= V_235 -> V_258 ) {
F_2 ( L_52 ,
V_238 , V_235 -> V_258 ) ;
break;
}
V_238 = V_235 -> V_258 ;
V_248 = V_235 -> V_259 == V_260 ;
memset ( V_240 , 0 , V_241 ) ;
V_249 = V_240 ;
V_242 = 0 ;
strcpy ( V_249 , V_16 -> V_19 ) ;
V_250 = strrchr ( V_249 , '-' ) ;
if ( V_250 == NULL ) {
F_2 ( L_53 ,
V_230 -> V_49 , V_249 ) ;
break;
}
V_242 = V_250 - V_249 ;
V_249 [ V_242 ] = 0 ;
V_242 += sprintf ( V_249 + V_242 , L_54 ,
V_248 ? L_55 : L_56 , V_235 -> V_261 ) ;
V_250 = V_248 ? L_57 : L_58 ,
V_242 += sprintf ( V_249 + V_242 , L_59 , V_250 , V_239 ) ;
F_121 ( & V_237 , V_249 ) ;
V_34 = F_122 ( V_249 ) ;
if ( V_34 == NULL ) {
F_5 ( V_18 , L_60 ,
V_230 -> V_49 , V_249 ) ;
V_37 = 0 ;
continue;
}
++ V_242 ;
V_251 = V_240 + V_242 ;
V_242 += sprintf ( V_251 , L_61 , V_250 , L_62 ) ;
V_252 = V_240 + V_242 ;
F_51 ( & V_34 -> V_76 . V_77 . V_82 ) ;
if ( V_34 -> V_76 . V_77 . V_78 == NULL ) {
F_52 ( & V_34 -> V_76 . V_77 . V_82 ) ;
V_37 = 0 ;
continue;
}
V_37 = F_123 ( V_34 -> V_76 . V_77 . V_78 ,
V_235 -> V_76 . V_262 [ 0 ] ,
(struct V_263 * ) V_252 ) ;
F_52 ( & V_34 -> V_76 . V_77 . V_82 ) ;
if ( V_37 < 0 ) {
F_2 ( L_63 ,
F_124 ( V_235 -> V_76 . V_262 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_64 ,
V_252 , F_124 ( V_235 -> V_76 . V_262 [ 0 ] ) ) ;
V_242 += strlen ( V_252 ) ;
V_242 += sprintf ( V_240 + V_242 , L_65 , V_235 -> V_264 ) ;
F_12 ( V_242 < V_241 ) ;
F_125 ( & V_237 , 1 , V_251 ) ;
V_37 = - V_39 ;
V_53 = F_126 ( V_265 , & V_237 ) ;
if ( V_53 == NULL ) {
F_2 ( L_66 ) ;
break;
}
F_5 ( V_18 , L_67 ,
V_238 , V_231 , V_249 , V_251 ) ;
V_37 = F_127 ( V_53 ) ;
F_128 ( V_53 ) ;
if ( V_37 )
F_5 ( V_18 , L_68 ,
V_249 , V_37 ) ;
}
F_19 ( V_239 ) ;
return V_37 ;
}
static int F_129 ( struct V_33 * V_34 ,
struct V_15 * V_16 )
{
struct V_142 * V_143 = NULL ;
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_266 * V_267 ;
struct V_268 * V_269 ;
struct V_270 * V_128 ;
struct V_271 * * V_272 ;
int V_273 ;
bool V_274 = true ;
bool V_233 = false ;
int V_275 ;
int V_276 ;
int V_37 ;
V_273 = V_277 ;
if ( V_27 -> V_43 == 0 )
V_273 = V_278 ;
V_272 = F_130 ( V_273 , sizeof( * V_272 ) , V_38 ) ;
if ( V_272 == NULL ) {
V_37 = - V_39 ;
goto V_279;
}
for ( V_275 = 0 ; V_275 < V_273 ; V_275 ++ ) {
V_272 [ V_275 ] = F_131 ( V_280 ) ;
if ( V_272 [ V_275 ] == NULL ) {
V_37 = - V_39 ;
goto V_279;
}
}
V_281:
F_12 ( F_132 ( V_16 ) ) ;
F_12 ( F_133 ( & V_16 -> V_42 ) ) ;
V_143 = F_134 ( F_94 ( V_16 -> V_25 ) ,
& V_282 ) ;
if ( V_143 == NULL ) {
V_37 = - V_39 ;
goto V_279;
}
V_37 = F_135 ( V_143 , V_147 , V_283 ) ;
if ( V_37 )
goto V_279;
V_267 = F_95 ( & V_143 -> V_149 , & V_284 ) ;
F_12 ( V_267 != NULL ) ;
F_12 ( sizeof( V_267 -> V_285 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_136 ( V_267 -> V_285 , V_16 -> V_19 , sizeof( V_267 -> V_285 ) )
>= sizeof( V_267 -> V_285 ) ) {
V_37 = - V_245 ;
goto V_279;
}
V_267 -> V_286 = V_27 -> V_43 + 1 ;
V_267 -> V_287 = V_16 -> V_46 ;
V_267 -> V_288 = V_289 ;
V_267 -> V_290 = V_273 ;
V_128 = F_137 ( V_143 , V_273 , 1 , V_291 ,
V_292 ) ;
if ( V_128 == NULL ) {
V_37 = - V_39 ;
goto V_279;
}
for ( V_275 = 0 ; V_275 < V_273 ; V_275 ++ )
F_138 ( V_128 , V_272 [ V_275 ] , 0 , V_244 ) ;
F_97 ( V_143 ) ;
V_37 = F_98 ( V_143 ) ;
if ( V_37 )
goto V_279;
V_269 = F_99 ( & V_143 -> V_149 , & V_293 ) ;
if ( V_269 -> V_294 < V_269 -> V_295 ) {
V_37 = - V_6 ;
goto V_279;
}
V_27 -> V_43 = V_269 -> V_295 ;
V_274 = V_269 -> V_295 == V_269 -> V_294 ;
F_5 ( V_18 , L_69 ,
V_269 -> V_295 , V_274 == false ) ;
V_276 = F_139 ( V_143 , V_143 -> V_296 , 0 ) ;
if ( V_276 < 0 ) {
V_37 = V_276 ;
goto V_279;
}
if ( V_276 > V_273 << V_289 ) {
V_37 = - V_6 ;
goto V_279;
}
if ( V_276 == 0 ) {
if ( ! V_274 )
V_37 = - V_6 ;
goto V_279;
}
V_233 = ! ! F_140 ( V_143 ) ;
#if V_297 < F_141 ( 3 , 2 , 50 , 0 )
if ( F_43 ( V_143 -> V_298 -> V_299 ) )
V_233 = ! V_233 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_275 = 0 ; V_275 < V_273 && V_276 > 0 ; V_275 ++ ) {
int V_300 ;
void * V_60 ;
V_60 = F_142 ( V_272 [ V_275 ] ) ;
V_300 = F_117 ( V_34 , V_16 , V_269 -> V_295 , V_60 ,
F_143 ( int , V_276 , V_244 ) ,
V_233 ) ;
F_144 ( V_272 [ V_275 ] ) ;
if ( V_300 < 0 ) {
F_145 ( L_70 ,
V_16 -> V_19 , V_300 ) ;
break;
}
V_276 -= V_244 ;
}
V_279:
if ( V_143 )
F_96 ( V_143 ) ;
if ( V_37 == 0 && ! V_274 )
goto V_281;
if ( V_272 ) {
for ( V_275 = 0 ; V_275 < V_273 ; V_275 ++ ) {
if ( V_272 [ V_275 ] == NULL )
break;
F_146 ( V_272 [ V_275 ] ) ;
}
F_19 ( V_272 ) ;
}
return V_37 ;
}
static int F_147 ( struct V_33 * V_230 ,
struct V_15 * V_16 , int V_301 )
{
struct V_105 * V_106 ;
struct V_54 * V_55 = NULL ;
int V_37 = 0 ;
bool V_302 = false ;
struct V_103 * V_104 ;
F_12 ( V_16 ) ;
F_12 ( F_133 ( & V_16 -> V_42 ) ) ;
if ( F_16 ( V_16 ) && V_301 )
return 0 ;
if ( V_16 -> V_31 . V_45 )
V_55 = F_33 ( V_16 -> V_31 . V_45 ) ;
V_104 = F_24 ( sizeof( * V_104 ) , V_38 ) ;
if ( V_104 == NULL )
return - V_39 ;
V_37 = F_148 ( V_104 , V_303 ) ;
if ( V_37 )
goto V_304;
V_106 = F_63 ( V_230 , V_108 ) ;
F_12 ( V_106 ) ;
if ( V_301 ) {
V_37 = - V_305 ;
goto V_306;
}
if ( F_16 ( V_16 ) ) {
F_149 ( V_16 -> V_19 ) ;
V_302 = true ;
}
V_37 = F_150 ( V_104 , V_106 , V_16 -> V_19 ,
& V_16 -> V_31 ) ;
V_306:
F_151 ( V_104 , V_106 ) ;
if ( V_302 ) {
F_12 ( F_16 ( V_16 ) ) ;
F_152 ( V_16 -> V_19 ) ;
F_153 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_12 ) ) ;
}
F_154 ( V_104 ) ;
V_304:
F_19 ( V_104 ) ;
return V_37 ;
}
int F_31 ( struct V_33 * V_230 , struct V_15 * V_16 )
{
struct V_130 V_131 = { 0 } ;
T_1 V_157 = V_307 ;
int V_37 = 0 , V_308 ;
F_12 ( V_16 ) ;
F_42 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_32 ) {
F_44 ( & V_16 -> V_42 ) ;
return 0 ;
}
F_155 ( V_309 , 20 ) ;
F_5 ( V_11 , L_71 , V_16 -> V_19 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_43 + 1 ) ;
V_308 = F_100 ( V_230 -> V_76 . V_77 . V_310 , NULL , V_311 , NULL ,
V_312 , & V_157 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_131 ) ;
if ( V_308 == 0 ) {
F_8 ( V_16 ) ;
V_37 = F_156 ( & V_131 , ( void * ) V_16 ) ;
F_12 ( V_37 == 0 ) ;
} else {
F_5 ( V_11 , L_72 , V_308 ) ;
V_16 -> V_101 = 1 ;
F_8 ( V_16 ) ;
}
if ( F_132 ( V_16 ) ) {
V_37 = 0 ;
if ( V_308 == 0 )
V_37 = F_129 ( V_230 , V_16 ) ;
} else {
V_37 = F_147 ( V_230 , V_16 , V_308 != 0 ) ;
}
F_5 ( V_11 , L_73 ,
V_230 -> V_49 , V_16 -> V_19 , V_37 ? L_74 : L_75 , V_37 ) ;
F_44 ( & V_16 -> V_42 ) ;
if ( ! V_308 )
F_157 ( & V_131 , V_312 ) ;
return V_37 ;
}
static int F_158 ( struct V_33 * V_34 , T_4 V_2 , void * V_240 )
{
struct V_118 * V_53 = V_240 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_37 = 0 ;
switch ( V_53 -> V_313 ) {
case V_314 : {
struct V_179 * V_180 ;
if ( F_159 ( V_53 , 1 ) !=
sizeof( struct V_179 ) ) {
V_37 = - V_6 ;
goto V_279;
}
V_180 = (struct V_179 * ) F_160 ( V_53 , 1 ) ;
F_5 ( V_11 , L_76 ,
V_180 -> V_186 , V_180 -> V_315 ) ;
V_37 = F_104 ( V_34 -> V_76 . V_77 . V_310 , V_180 ) ;
break;
}
case V_316 :
F_2 ( L_77 ) ;
V_37 = - V_317 ;
break;
case V_318 : {
V_37 = F_161 ( V_53 ) ;
break;
}
case V_319 : {
struct V_15 * V_16 ;
struct V_35 * V_36 ;
V_13 = F_162 ( V_53 , 1 ) ;
V_27 = (struct V_26 * ) F_160 ( V_53 , 2 ) ;
V_36 = * (struct V_35 * * ) F_160 ( V_53 , 3 ) ;
F_5 ( V_11 , L_78 , V_13 ,
V_27 -> V_43 ) ;
V_37 = F_38 ( V_34 , V_13 , V_27 , V_36 ) ;
if ( V_37 )
break;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( V_16 == NULL ) {
V_37 = - V_52 ;
break;
}
V_16 -> V_31 . V_44 |= V_320 ;
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 == 0 && V_16 -> V_22 != NULL ) {
if ( F_48 ( & V_34 -> V_76 . V_77 . V_78 ->
V_79 , V_80 ) ) {
V_37 = F_31 ( V_34 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_321 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_11 ( V_321 ) ;
}
if ( V_37 )
F_2 ( L_79 , V_37 ) ;
}
if ( V_37 == 0 && V_16 -> V_24 != NULL ) {
V_37 = F_31 ( V_34 , V_16 -> V_24 ) ;
if ( V_37 == - V_52 ) {
F_5 ( V_11 ,
L_80 ) ;
V_37 = 0 ;
}
if ( V_37 )
F_2 (
L_81 ,
V_34 -> V_49 , V_37 ) ;
}
F_11 ( V_16 ) ;
break;
}
case V_322 : {
V_13 = F_162 ( V_53 , 1 ) ;
if ( V_53 -> V_323 >= 2 )
V_27 = (struct V_26 * ) F_160 (
V_53 , 2 ) ;
V_37 = F_41 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_82 , V_53 -> V_313 ) ;
V_37 = - V_6 ;
goto V_279;
}
}
V_279:
return V_37 ;
}
static int T_6 F_163 ( void )
{
return F_164 ( & V_324 , NULL ,
V_325 , NULL ) ;
}
static void F_165 ( void )
{
F_166 ( V_325 ) ;
}
