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
int F_7 ( char * V_13 , struct V_3 * V_4 , int type )
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
F_19 ( V_16 , sizeof( * V_16 ) + strlen ( V_16 -> V_19 ) + 1 ) ;
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
F_24 ( V_16 , sizeof( * V_16 ) + strlen ( V_13 ) + 1 ) ;
if ( ! V_16 )
return F_25 ( - V_38 ) ;
strcpy ( V_16 -> V_19 , V_13 ) ;
if ( V_27 )
V_16 -> V_31 = * V_27 ;
else
V_16 -> V_31 . V_39 = V_40 ;
F_26 ( & V_16 -> V_41 ) ;
V_16 -> V_31 . V_42 = 0 ;
V_16 -> V_31 . V_43 = 0 ;
V_16 -> V_31 . V_44 = V_36 ;
V_16 -> V_45 = type ;
F_27 ( & V_16 -> V_17 , 1 ) ;
V_16 -> V_25 = F_28 ( V_34 -> V_46 ) ;
if ( F_16 ( V_16 ) ) {
F_29 ( V_13 ) ;
V_16 -> V_31 . V_47 = V_34 -> V_48 ;
}
V_37 = F_7 ( V_13 , & V_16 -> V_49 , type ) ;
F_21 ( & V_20 ) ;
F_30 ( & V_16 -> V_21 , & V_50 ) ;
F_15 ( & V_20 ) ;
if ( V_37 ) {
F_11 ( V_16 ) ;
return F_25 ( V_37 ) ;
}
if ( F_16 ( V_16 ) ) {
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 && V_37 != - V_51 )
F_2 ( L_7 , V_37 ) ;
}
return V_16 ;
}
static struct V_15 * F_32 ( struct V_33 * V_34 ,
char * V_12 ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_26 V_52 = * V_27 ;
struct V_53 * V_54 = F_33 ( V_36 ) ;
struct V_15 * V_16 ;
char V_13 [ 32 ] ;
if ( F_34 ( V_54 ) )
return NULL ;
if ( F_35 ( V_54 ) && V_52 . V_30 )
return NULL ;
F_12 ( strlen ( V_12 ) < sizeof( V_13 ) / 2 ) ;
strcpy ( V_13 , V_12 ) ;
if ( F_36 ( V_54 ) ) {
F_12 ( V_52 . V_30 == NULL ) ;
V_52 . V_30 = V_36 ;
strcat ( V_13 , L_8 ) ;
} else {
F_12 ( V_52 . V_30 != NULL ) ;
strcat ( V_13 , L_9 ) ;
}
V_16 = F_23 ( V_34 , V_13 , V_9 , & V_52 , V_36 ) ;
return V_16 ;
}
static struct V_15 * F_37 ( struct V_33 * V_34 ,
struct V_26 * V_27 , struct V_35 * V_36 )
{
struct V_26 V_52 = * V_27 ;
struct V_15 * V_16 ;
V_52 . V_30 = V_36 ;
V_16 = F_23 ( V_34 , V_55 , V_10 ,
& V_52 , V_36 ) ;
return V_16 ;
}
static int F_38 ( struct V_33 * V_34 , char * V_13 ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_53 * V_54 = F_33 ( V_36 ) ;
struct V_15 * V_16 ;
struct V_15 * V_56 ;
struct V_15 * V_57 ;
char V_58 [ 32 ] ;
char * V_59 ;
int V_37 ;
F_5 ( V_11 , L_10 , V_13 , V_27 -> V_30 ) ;
V_59 = strrchr ( V_13 , '-' ) ;
if ( V_59 == NULL || V_59 - V_13 > 8 ) {
F_2 ( L_11 , V_13 ) ;
return - V_6 ;
}
memcpy ( V_58 , V_13 , V_59 - V_13 ) ;
strcpy ( V_58 + ( V_59 - V_13 ) , L_12 ) ;
V_56 = F_20 ( V_58 , NULL ) ;
if ( V_56 == NULL ) {
V_56 = F_23 ( V_34 , V_58 ,
V_8 , NULL , NULL ) ;
if ( F_39 ( V_56 ) ) {
F_2 ( L_13 , V_58 ) ;
V_37 = F_40 ( V_56 ) ;
goto V_60;
}
}
V_57 = F_37 ( V_34 , V_27 , V_36 ) ;
if ( F_39 ( V_57 ) ) {
V_37 = F_40 ( V_57 ) ;
F_2 ( L_14 ,
V_34 -> V_48 , V_37 ) ;
goto V_61;
}
V_16 = F_23 ( V_34 , V_13 , V_7 , V_27 , V_36 ) ;
if ( F_39 ( V_16 ) ) {
F_2 ( L_15 , V_13 ) ;
V_37 = F_40 ( V_16 ) ;
goto V_62;
}
V_16 -> V_23 = V_56 ;
V_16 -> V_24 = V_57 ;
F_12 ( V_54 -> V_63 ) ;
if ( ! ( V_54 -> V_63 -> V_64 & V_65 ) ) {
struct V_15 * V_66 ;
* strrchr ( V_58 , '-' ) = 0 ;
V_66 = F_32 ( V_34 , V_58 , V_27 , V_36 ) ;
if ( F_39 ( V_66 ) ) {
V_37 = F_40 ( V_66 ) ;
goto V_67;
}
V_16 -> V_22 = V_66 ;
}
return 0 ;
V_67:
F_11 ( V_16 ) ;
V_62:
F_11 ( V_57 ) ;
V_61:
F_11 ( V_56 ) ;
V_60:
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
return - V_51 ;
F_42 ( & V_16 -> V_41 ) ;
if ( F_43 ( V_16 -> V_32 ) ) {
F_44 ( & V_16 -> V_41 ) ;
F_11 ( V_16 ) ;
return V_37 ;
}
V_16 -> V_32 = 1 ;
V_22 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_44 ( & V_16 -> V_41 ) ;
if ( V_22 ) {
F_42 ( & V_22 -> V_41 ) ;
V_22 -> V_32 = 1 ;
F_44 ( & V_22 -> V_41 ) ;
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
F_42 ( & V_24 -> V_41 ) ;
V_24 -> V_32 = 1 ;
F_44 ( & V_24 -> V_41 ) ;
F_11 ( V_24 ) ;
}
F_11 ( V_16 ) ;
F_11 ( V_16 ) ;
F_5 ( V_11 , L_16 , V_13 ? V_13 : L_17 ,
V_37 ) ;
return V_37 ;
}
int F_45 ( struct V_68 * V_69 , void * V_70 )
{
struct V_33 * V_34 = V_70 ;
struct V_71 * V_72 = V_34 -> V_73 . V_74 . V_75 ;
struct V_76 * V_77 = & V_72 -> V_78 ;
struct V_15 * V_16 ;
F_46 ( V_69 , L_18 ,
F_47 ( V_77 , V_79 ) ? L_19 : L_20 ) ;
F_46 ( V_69 , L_21 ) ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_16 -> V_22 == NULL )
continue;
F_46 ( V_69 , L_22 ,
V_16 -> V_19 ,
V_16 -> V_22 -> V_31 . V_42 ) ;
}
F_15 ( & V_20 ) ;
return 0 ;
}
static void F_48 ( struct V_15 * V_16 )
{
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_49 ( & V_16 -> V_25 -> V_80 -> V_73 . V_74 . V_81 ) ;
if ( V_16 -> V_25 -> V_80 -> V_73 . V_74 . V_82 != 0 ) {
F_5 ( V_11 , L_23 , V_16 -> V_19 ) ;
F_31 ( V_16 -> V_25 -> V_80 , V_16 ) ;
} else {
F_5 ( V_11 , L_24 ,
V_16 -> V_19 ) ;
}
F_50 ( & V_16 -> V_25 -> V_80 -> V_73 . V_74 . V_81 ) ;
}
static int F_51 ( void * V_70 )
{
F_5 ( V_11 , L_25 ) ;
F_21 ( & V_20 ) ;
V_83 |= V_84 ;
while ( 1 ) {
struct V_85 V_86 ;
struct V_15 * V_16 , * V_87 ;
int rand = F_52 () & V_88 ;
int V_89 = ! ! ( V_83 & V_90 ) ;
int V_91 ;
V_83 &= ~ ( V_92 | V_93 ) ;
F_15 ( & V_20 ) ;
V_91 = V_94 * V_95 ;
V_91 += rand * V_95 / 100 ;
V_86 = F_53 ( V_91 , NULL , NULL ) ;
F_54 ( V_96 , V_83 & V_90 , & V_86 ) ;
V_87 = NULL ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list,
cld_list_chain) {
if ( ! V_16 -> V_97 )
continue;
F_15 ( & V_20 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_87 )
F_11 ( V_87 ) ;
V_87 = V_16 ;
V_16 -> V_97 = 0 ;
if ( F_55 ( ! V_89 ) )
F_48 ( V_16 ) ;
F_21 ( & V_20 ) ;
}
F_15 ( & V_20 ) ;
if ( V_87 )
F_11 ( V_87 ) ;
if ( F_43 ( V_89 ) ) {
F_21 ( & V_20 ) ;
break;
}
V_86 = (struct V_85 ) { 0 } ;
F_54 ( V_96 , V_83 & ( V_92 | V_90 ) ,
& V_86 ) ;
F_21 ( & V_20 ) ;
}
V_83 &= ~ V_84 ;
F_15 ( & V_20 ) ;
F_56 ( & V_98 ) ;
F_5 ( V_11 , L_26 ) ;
return 0 ;
}
static void F_57 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_27 ,
V_16 -> V_19 , F_10 ( & V_16 -> V_17 ) ,
V_16 -> V_32 , V_83 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_42 ( & V_16 -> V_41 ) ;
if ( V_16 -> V_32 || V_16 -> V_97 ) {
F_44 ( & V_16 -> V_41 ) ;
return;
}
F_8 ( V_16 ) ;
V_16 -> V_97 = 1 ;
F_44 ( & V_16 -> V_41 ) ;
F_21 ( & V_20 ) ;
if ( V_83 & V_90 ) {
F_15 ( & V_20 ) ;
V_16 -> V_97 = 0 ;
F_11 ( V_16 ) ;
} else {
V_83 |= V_92 ;
F_15 ( & V_20 ) ;
F_58 ( & V_96 ) ;
}
}
static int F_59 ( const struct V_99 * V_100 , struct V_33 * V_34 )
{
struct V_101 * V_102 ;
int V_37 ;
V_37 = F_60 ( V_100 , V_34 , & V_34 -> V_103 , V_104 , V_34 ,
& V_105 ) ;
if ( V_37 )
return V_37 ;
V_102 = F_61 ( V_34 , V_104 ) ;
F_12 ( V_102 ) ;
F_62 ( V_102 ) ;
F_63 ( V_102 ) ;
return 0 ;
}
static int F_64 ( const struct V_99 * V_100 , struct V_33 * V_34 )
{
struct V_101 * V_102 ;
V_102 = F_61 ( V_34 , V_104 ) ;
if ( V_102 )
F_65 ( V_100 , V_102 ) ;
return 0 ;
}
static int F_66 ( struct V_33 * V_34 , enum V_106 V_107 )
{
int V_37 = 0 ;
switch ( V_107 ) {
case V_108 :
break;
case V_109 :
if ( F_67 ( & V_110 ) ) {
int V_111 ;
F_21 ( & V_20 ) ;
V_111 = V_83 & V_84 ;
if ( V_111 )
V_83 |= V_90 ;
F_15 ( & V_20 ) ;
if ( V_111 ) {
F_58 ( & V_96 ) ;
F_68 ( & V_98 ) ;
}
}
F_69 ( V_34 ) ;
V_37 = F_64 ( NULL , V_34 ) ;
if ( V_37 != 0 )
F_2 ( L_28 ) ;
break;
}
return V_37 ;
}
static int F_70 ( struct V_33 * V_34 )
{
int V_37 ;
if ( V_34 -> V_112 -> V_113 <= 1 )
F_71 () ;
F_72 ( V_34 ) ;
F_73 () ;
V_37 = F_74 ( V_34 ) ;
return V_37 ;
}
static int F_75 ( struct V_33 * V_34 , struct V_114 * V_52 )
{
struct V_115 V_116 ;
int V_37 ;
F_76 () ;
V_37 = F_77 ( V_34 , V_52 ) ;
if ( V_37 )
goto V_117;
V_37 = F_59 ( NULL , V_34 ) ;
if ( V_37 ) {
F_2 ( L_29 ) ;
goto V_118;
}
F_78 ( & V_116 ) ;
F_79 ( V_34 , V_116 . V_119 ) ;
F_80 ( V_34 ) ;
if ( F_81 ( & V_110 ) == 1 ) {
V_83 = 0 ;
F_82 ( & V_96 ) ;
V_37 = F_40 ( F_83 ( F_51 , NULL ,
L_30 ) ) ;
if ( F_84 ( V_37 ) ) {
F_2 ( L_31 ,
V_34 -> V_48 , V_37 ) ;
goto V_118;
}
V_37 = 0 ;
}
return V_37 ;
V_118:
F_74 ( V_34 ) ;
V_117:
F_73 () ;
return V_37 ;
}
static int F_85 ( struct V_120 * V_121 , struct V_122 * V_123 ,
void * V_70 , int V_124 )
{
struct V_125 V_126 ;
struct V_15 * V_16 = (struct V_15 * ) V_70 ;
int V_37 = 0 ;
switch ( V_124 ) {
case V_127 :
F_86 ( V_121 , L_32 ) ;
F_87 ( V_121 , & V_126 ) ;
V_37 = F_88 ( & V_126 , V_128 ) ;
break;
case V_129 :
F_86 ( V_121 , L_33 ) ;
F_5 ( V_11 , L_34 V_130 L_35 ,
F_89 ( V_121 -> V_131 ) ,
( char * ) & V_121 -> V_131 -> V_132 . V_1 [ 0 ] ) ;
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
if ( ! V_121 -> V_133 ||
! V_121 -> V_133 -> V_80 -> V_73 . V_74 . V_82 ) {
F_5 ( V_11 , L_38 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
F_57 ( V_16 ) ;
F_11 ( V_16 ) ;
break;
default:
F_4 () ;
}
return V_37 ;
}
static int F_90 ( struct V_134 * exp ,
struct V_135 * V_136 )
{
struct V_137 * V_138 ;
struct V_135 * V_139 , * V_140 ;
int V_37 ;
V_138 = F_91 ( F_92 ( exp ) ,
& V_141 , V_142 ,
V_143 ) ;
if ( ! V_138 )
return - V_38 ;
V_139 = F_93 ( & V_138 -> V_144 , & V_145 ) ;
if ( ! V_139 ) {
F_94 ( V_138 ) ;
return - V_38 ;
}
memcpy ( V_139 , V_136 , sizeof( * V_139 ) ) ;
F_95 ( V_138 ) ;
V_138 -> V_146 = V_147 ;
V_37 = F_96 ( V_138 ) ;
if ( ! V_37 ) {
V_140 = F_97 ( & V_138 -> V_144 , & V_145 ) ;
memcpy ( V_136 , V_140 , sizeof( * V_140 ) ) ;
}
F_94 ( V_138 ) ;
return V_37 ;
}
static int F_98 ( struct V_134 * exp , struct V_148 * V_149 ,
T_2 type , T_3 * V_150 , T_2 V_151 ,
T_1 * V_152 , void * V_153 , void * V_154 , void * V_155 ,
void * V_70 , T_2 V_156 , void * V_157 ,
struct V_125 * V_126 )
{
struct V_15 * V_16 = (struct V_15 * ) V_70 ;
struct V_158 V_159 = {
. V_160 = type ,
. V_161 = V_151 ,
. V_162 = F_85 ,
. V_163 = V_164 ,
} ;
struct V_137 * V_138 ;
int V_165 = F_16 ( V_16 ) ;
int V_37 ;
F_5 ( V_11 , L_39 , V_16 -> V_19 ,
V_16 -> V_49 . V_1 [ 0 ] ) ;
V_138 = F_91 ( F_92 ( exp ) ,
& V_166 , V_167 ,
V_168 ) ;
if ( V_138 == NULL )
return - V_38 ;
F_99 ( & V_138 -> V_144 , & V_169 , V_170 , 0 ) ;
F_95 ( V_138 ) ;
if ( V_16 -> V_31 . V_44 ) {
struct V_53 * V_54 = F_33 ( V_16 -> V_31 . V_44 ) ;
if ( V_54 && F_36 ( V_54 ) )
V_165 = 1 ;
}
V_138 -> V_146 = V_165 ? 5 : V_171 ;
V_37 = F_100 ( exp , & V_138 , & V_159 , & V_16 -> V_49 , NULL , V_152 ,
NULL , 0 , V_172 , V_126 , 0 ) ;
F_94 ( V_138 ) ;
return V_37 ;
}
static void F_101 ( struct V_33 * V_173 )
{
F_21 ( & V_20 ) ;
V_83 |= V_92 ;
F_15 ( & V_20 ) ;
F_58 ( & V_96 ) ;
}
static int F_102 ( struct V_134 * exp ,
struct V_174 * V_175 )
{
struct V_137 * V_138 ;
struct V_174 * V_176 , * V_177 ;
int V_37 ;
V_138 = F_91 ( F_92 ( exp ) ,
& V_178 , V_142 ,
V_179 ) ;
if ( V_138 == NULL )
return - V_38 ;
V_176 = F_93 ( & V_138 -> V_144 , & V_180 ) ;
if ( ! V_176 ) {
F_94 ( V_138 ) ;
return - V_38 ;
}
memcpy ( V_176 , V_175 , sizeof( * V_176 ) ) ;
F_95 ( V_138 ) ;
F_5 ( V_11 , L_40 , V_175 -> V_181 ) ;
V_138 -> V_146 = V_182 ;
V_37 = F_96 ( V_138 ) ;
if ( ! V_37 ) {
V_177 = F_97 ( & V_138 -> V_144 ,
& V_180 ) ;
memcpy ( V_175 , V_177 , sizeof( * V_177 ) ) ;
F_5 ( V_11 , L_41 ,
V_175 -> V_181 , V_175 -> V_183 ) ;
}
F_94 ( V_138 ) ;
return V_37 ;
}
int F_103 ( const struct V_99 * V_100 , struct V_134 * exp ,
T_4 V_184 , void * V_185 , T_4 V_186 ,
void * V_187 , struct V_188 * V_189 )
{
int V_37 = - V_6 ;
if ( F_104 ( V_190 ) ) {
struct V_71 * V_72 = F_92 ( exp ) ;
int V_191 ;
if ( V_186 != sizeof( int ) )
return - V_6 ;
V_191 = * ( int * ) V_187 ;
F_5 ( V_11 , L_42 ,
V_72 -> V_192 -> V_48 , V_191 ,
V_72 -> V_193 , V_72 -> V_194 ,
V_72 -> V_195 , V_72 -> V_192 -> V_196 ,
F_105 ( V_72 -> V_197 ) ) ;
if ( ( V_72 -> V_197 != V_198 &&
V_72 -> V_197 != V_199 ) || V_191 > 1 )
F_106 ( V_72 ) ;
return 0 ;
}
if ( F_104 ( V_200 ) ) {
struct V_135 * V_136 ;
V_136 = (struct V_135 * ) V_187 ;
V_37 = F_90 ( exp , V_136 ) ;
return V_37 ;
}
if ( F_104 ( V_201 ) ) {
struct V_202 * V_74 = & exp -> V_80 -> V_73 . V_74 ;
struct V_203 V_204 ;
if ( V_186 == 0 ) {
if ( V_74 -> V_205 . V_206 != V_207 )
return 0 ;
V_187 = L_43 ;
V_186 = 4 ;
}
V_37 = F_107 ( V_187 , & V_204 ) ;
if ( V_37 ) {
F_2 ( L_44 ,
( char * ) V_187 ) ;
return V_37 ;
}
if ( V_74 -> V_205 . V_206 == V_207 ) {
V_74 -> V_205 = V_204 ;
} else if ( memcmp ( & V_74 -> V_205 , & V_204 ,
sizeof( V_204 ) ) != 0 ) {
char V_208 [ 20 ] ;
F_108 ( & V_74 -> V_205 ,
V_208 , sizeof( V_208 ) ) ;
F_109 ( L_45 ,
( char * ) V_187 , V_208 ) ;
V_37 = - V_209 ;
}
return V_37 ;
}
return V_37 ;
}
static int F_110 ( const struct V_99 * V_100 , struct V_134 * exp ,
T_2 V_184 , void * V_185 , T_2 * V_186 , void * V_187 ,
struct V_148 * V_173 )
{
int V_37 = - V_6 ;
if ( F_104 ( V_210 ) ) {
struct V_71 * V_72 = F_92 ( exp ) ;
struct V_76 * V_70 = V_187 ;
if ( * V_186 == sizeof( * V_70 ) ) {
* V_70 = V_72 -> V_78 ;
V_37 = 0 ;
}
}
return V_37 ;
}
static int F_111 ( struct V_33 * V_34 ,
struct V_71 * V_72 ,
enum V_211 V_212 )
{
F_12 ( V_72 -> V_192 == V_34 ) ;
F_5 ( V_11 , L_46 , V_212 ) ;
switch ( V_212 ) {
case V_213 :
if ( F_47 ( & V_72 -> V_78 , V_79 ) )
F_112 () ;
break;
case V_214 :
break;
case V_215 : {
struct V_216 * V_217 = V_34 -> V_218 ;
F_113 ( V_217 , V_219 ) ;
break;
}
case V_220 :
F_5 ( V_18 , L_47 , V_34 -> V_48 ) ;
V_34 -> V_221 = 0 ;
F_101 ( V_34 ) ;
if ( F_47 ( & V_72 -> V_78 , V_79 ) )
F_114 () ;
break;
case V_222 :
break;
case V_223 :
case V_224 :
break;
default:
F_2 ( L_48 , V_212 ) ;
F_4 () ;
}
return 0 ;
}
static int F_115 ( struct V_33 * V_225 ,
struct V_15 * V_16 ,
T_1 V_226 ,
void * V_70 , int V_227 , bool V_228 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_53 * V_54 = F_33 ( V_27 -> V_44 ) ;
struct V_229 * V_230 ;
struct V_114 * V_52 ;
struct V_231 V_232 ;
T_5 V_233 = 0 ;
char * V_234 ;
char * V_235 ;
int V_236 ;
int V_237 ;
int V_37 = 0 ;
int V_238 = 0 ;
F_12 ( V_27 -> V_30 != NULL ) ;
F_12 ( V_27 -> V_44 == V_27 -> V_30 ) ;
F_24 ( V_234 , V_239 ) ;
if ( V_234 == NULL )
return - V_38 ;
if ( ! F_36 ( V_54 ) ) {
V_237 = snprintf ( V_234 , V_239 , L_49 , V_27 -> V_30 ) ;
if ( V_237 >= V_239 ) {
F_19 ( V_234 , V_239 ) ;
return - V_240 ;
}
} else {
F_12 ( F_35 ( V_54 ) ) ;
V_37 = F_116 ( V_54 -> V_241 , V_234 , NULL ,
V_239 ) ;
if ( V_37 ) {
F_19 ( V_234 , V_239 ) ;
return - V_6 ;
}
V_237 = strlen ( V_234 ) ;
}
++ V_237 ;
V_235 = V_234 + V_237 ;
V_236 = V_239 - V_237 ;
while ( V_227 > 0 ) {
int V_242 = sizeof( * V_230 ) ;
int V_243 ;
struct V_33 * V_34 ;
char * V_244 ;
char * V_245 ;
char * V_246 ;
char * V_247 ;
V_37 = - V_6 ;
if ( V_227 < sizeof( * V_230 ) )
break;
V_230 = ( F_117 ( V_230 ) ) ( V_70 + V_238 ) ;
if ( V_230 -> V_248 != 0 )
break;
if ( V_230 -> V_249 == 0 )
break;
if ( V_230 -> V_250 != sizeof( V_251 ) )
break;
V_242 += V_230 -> V_249 * V_230 -> V_250 ;
if ( V_227 < V_242 )
break;
if ( V_228 )
F_118 ( V_230 ) ;
if ( V_230 -> V_252 > V_239 ) {
F_2 ( L_50 , V_230 -> V_252 ) ;
break;
}
if ( V_230 -> V_252 < V_242 )
break;
V_238 += V_230 -> V_252 ;
V_227 -= V_230 -> V_252 ;
if ( V_227 < 0 )
break;
if ( V_230 -> V_253 > V_226 ) {
F_2 ( L_51 ,
V_230 -> V_253 , V_226 ) ;
break;
}
if ( V_233 >= V_230 -> V_253 ) {
F_2 ( L_52 ,
V_233 , V_230 -> V_253 ) ;
break;
}
V_233 = V_230 -> V_253 ;
V_243 = V_230 -> V_254 == V_255 ;
memset ( V_235 , 0 , V_236 ) ;
V_244 = V_235 ;
V_237 = 0 ;
strcpy ( V_244 , V_16 -> V_19 ) ;
V_245 = strrchr ( V_244 , '-' ) ;
if ( V_245 == NULL ) {
F_2 ( L_53 ,
V_225 -> V_48 , V_244 ) ;
break;
}
V_237 = V_245 - V_244 ;
V_244 [ V_237 ] = 0 ;
V_237 += sprintf ( V_244 + V_237 , L_54 ,
V_243 ? L_55 : L_56 , V_230 -> V_256 ) ;
V_245 = V_243 ? L_57 : L_58 ,
V_237 += sprintf ( V_244 + V_237 , L_59 , V_245 , V_234 ) ;
F_119 ( & V_232 , V_244 ) ;
V_34 = F_120 ( V_244 ) ;
if ( V_34 == NULL ) {
F_5 ( V_18 , L_60 ,
V_225 -> V_48 , V_244 ) ;
V_37 = 0 ;
continue;
}
++ V_237 ;
V_246 = V_235 + V_237 ;
V_237 += sprintf ( V_246 , L_61 , V_245 , L_62 ) ;
V_247 = V_235 + V_237 ;
F_49 ( & V_34 -> V_73 . V_74 . V_81 ) ;
if ( V_34 -> V_73 . V_74 . V_75 == NULL ) {
F_50 ( & V_34 -> V_73 . V_74 . V_81 ) ;
V_37 = 0 ;
continue;
}
V_37 = F_121 ( V_34 -> V_73 . V_74 . V_75 ,
V_230 -> V_73 . V_257 [ 0 ] ,
(struct V_258 * ) V_247 ) ;
F_50 ( & V_34 -> V_73 . V_74 . V_81 ) ;
if ( V_37 < 0 ) {
F_2 ( L_63 ,
F_122 ( V_230 -> V_73 . V_257 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_64 ,
V_247 , F_122 ( V_230 -> V_73 . V_257 [ 0 ] ) ) ;
V_237 += strlen ( V_247 ) ;
V_237 += sprintf ( V_235 + V_237 , L_65 , V_230 -> V_259 ) ;
F_12 ( V_237 < V_236 ) ;
F_123 ( & V_232 , 1 , V_246 ) ;
V_37 = - V_38 ;
V_52 = F_124 ( V_260 , & V_232 ) ;
if ( V_52 == NULL ) {
F_2 ( L_66 ) ;
break;
}
F_5 ( V_18 , L_67 ,
V_233 , V_226 , V_244 , V_246 ) ;
V_37 = F_125 ( V_52 ) ;
F_126 ( V_52 ) ;
if ( V_37 )
F_5 ( V_18 , L_68 ,
V_244 , V_37 ) ;
}
F_19 ( V_234 , V_239 ) ;
return V_37 ;
}
static int F_127 ( struct V_33 * V_34 ,
struct V_15 * V_16 )
{
struct V_137 * V_138 = NULL ;
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_261 * V_262 ;
struct V_263 * V_264 ;
struct V_265 * V_123 ;
struct V_266 * * V_267 ;
int V_268 ;
bool V_269 = true ;
bool V_228 = false ;
int V_270 ;
int V_271 ;
int V_37 ;
V_268 = V_272 ;
if ( V_27 -> V_42 == 0 )
V_268 = V_273 ;
F_24 ( V_267 , sizeof( * V_267 ) * V_268 ) ;
if ( V_267 == NULL ) {
V_37 = - V_38 ;
goto V_274;
}
for ( V_270 = 0 ; V_270 < V_268 ; V_270 ++ ) {
V_267 [ V_270 ] = F_128 ( V_275 ) ;
if ( V_267 [ V_270 ] == NULL ) {
V_37 = - V_38 ;
goto V_274;
}
}
V_276:
F_12 ( F_129 ( V_16 ) ) ;
F_12 ( F_130 ( & V_16 -> V_41 ) ) ;
V_138 = F_131 ( F_92 ( V_16 -> V_25 ) ,
& V_277 ) ;
if ( V_138 == NULL ) {
V_37 = - V_38 ;
goto V_274;
}
V_37 = F_132 ( V_138 , V_142 , V_278 ) ;
if ( V_37 )
goto V_274;
V_262 = F_93 ( & V_138 -> V_144 , & V_279 ) ;
F_12 ( V_262 != NULL ) ;
F_12 ( sizeof( V_262 -> V_280 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_133 ( V_262 -> V_280 , V_16 -> V_19 , sizeof( V_262 -> V_280 ) )
>= sizeof( V_262 -> V_280 ) ) {
V_37 = - V_240 ;
goto V_274;
}
V_262 -> V_281 = V_27 -> V_42 + 1 ;
V_262 -> V_282 = V_16 -> V_45 ;
V_262 -> V_283 = V_284 ;
V_262 -> V_285 = V_268 ;
V_123 = F_134 ( V_138 , V_268 , 1 , V_286 ,
V_287 ) ;
if ( V_123 == NULL ) {
V_37 = - V_38 ;
goto V_274;
}
for ( V_270 = 0 ; V_270 < V_268 ; V_270 ++ )
F_135 ( V_123 , V_267 [ V_270 ] , 0 , V_239 ) ;
F_95 ( V_138 ) ;
V_37 = F_96 ( V_138 ) ;
if ( V_37 )
goto V_274;
V_264 = F_97 ( & V_138 -> V_144 , & V_288 ) ;
if ( V_264 -> V_289 < V_264 -> V_290 ) {
V_37 = - V_6 ;
goto V_274;
}
V_27 -> V_42 = V_264 -> V_290 ;
V_269 = V_264 -> V_290 == V_264 -> V_289 ;
F_5 ( V_18 , L_69 ,
V_264 -> V_290 , V_269 == false ) ;
V_271 = F_136 ( V_138 , V_138 -> V_291 , 0 ) ;
if ( V_271 < 0 ) {
V_37 = V_271 ;
goto V_274;
}
if ( V_271 > V_268 << V_284 ) {
V_37 = - V_6 ;
goto V_274;
}
if ( V_271 == 0 ) {
if ( ! V_269 )
V_37 = - V_6 ;
goto V_274;
}
V_228 = ! ! F_137 ( V_138 ) ;
#if V_292 < F_138 ( 3 , 2 , 50 , 0 )
if ( F_43 ( V_138 -> V_293 -> V_294 ) )
V_228 = ! V_228 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_270 = 0 ; V_270 < V_268 && V_271 > 0 ; V_270 ++ ) {
int V_295 ;
void * V_59 ;
V_59 = F_139 ( V_267 [ V_270 ] ) ;
V_295 = F_115 ( V_34 , V_16 , V_264 -> V_290 , V_59 ,
F_140 ( int , V_271 , V_239 ) ,
V_228 ) ;
F_141 ( V_267 [ V_270 ] ) ;
if ( V_295 < 0 ) {
F_142 ( L_70 ,
V_16 -> V_19 , V_295 ) ;
break;
}
V_271 -= V_239 ;
}
V_274:
if ( V_138 )
F_94 ( V_138 ) ;
if ( V_37 == 0 && ! V_269 )
goto V_276;
if ( V_267 ) {
for ( V_270 = 0 ; V_270 < V_268 ; V_270 ++ ) {
if ( V_267 [ V_270 ] == NULL )
break;
F_143 ( V_267 [ V_270 ] ) ;
}
F_19 ( V_267 , sizeof( * V_267 ) * V_268 ) ;
}
return V_37 ;
}
static int F_144 ( struct V_33 * V_225 ,
struct V_15 * V_16 , int V_296 )
{
struct V_101 * V_102 ;
struct V_53 * V_54 = NULL ;
int V_37 = 0 ;
bool V_297 = false ;
struct V_99 * V_100 ;
F_12 ( V_16 ) ;
F_12 ( F_130 ( & V_16 -> V_41 ) ) ;
if ( F_16 ( V_16 ) && V_296 )
return 0 ;
if ( V_16 -> V_31 . V_44 )
V_54 = F_33 ( V_16 -> V_31 . V_44 ) ;
F_145 ( V_100 ) ;
if ( V_100 == NULL )
return - V_38 ;
V_37 = F_146 ( V_100 , V_298 ) ;
if ( V_37 )
goto V_299;
V_102 = F_61 ( V_225 , V_104 ) ;
F_12 ( V_102 ) ;
if ( V_296 ) {
V_37 = - V_300 ;
goto V_301;
}
if ( F_16 ( V_16 ) ) {
F_147 ( V_16 -> V_19 ) ;
V_297 = true ;
}
V_37 = F_148 ( V_100 , V_102 , V_16 -> V_19 ,
& V_16 -> V_31 ) ;
V_301:
F_149 ( V_100 , V_102 ) ;
if ( V_297 ) {
F_12 ( F_16 ( V_16 ) ) ;
F_150 ( V_16 -> V_19 ) ;
F_151 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_12 ) ) ;
}
F_152 ( V_100 ) ;
V_299:
F_153 ( V_100 ) ;
return V_37 ;
}
int F_31 ( struct V_33 * V_225 , struct V_15 * V_16 )
{
struct V_125 V_126 = { 0 } ;
T_1 V_152 = V_302 ;
int V_37 = 0 , V_303 ;
F_12 ( V_16 ) ;
F_42 ( & V_16 -> V_41 ) ;
if ( V_16 -> V_32 ) {
F_44 ( & V_16 -> V_41 ) ;
return 0 ;
}
F_154 ( V_304 , 20 ) ;
F_5 ( V_11 , L_71 , V_16 -> V_19 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_42 + 1 ) ;
V_303 = F_98 ( V_225 -> V_73 . V_74 . V_305 , NULL , V_306 , NULL ,
V_307 , & V_152 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_126 ) ;
if ( V_303 == 0 ) {
F_8 ( V_16 ) ;
V_37 = F_155 ( & V_126 , ( void * ) V_16 ) ;
F_12 ( V_37 == 0 ) ;
} else {
F_5 ( V_11 , L_72 , V_303 ) ;
V_16 -> V_97 = 1 ;
F_8 ( V_16 ) ;
}
if ( F_129 ( V_16 ) ) {
V_37 = 0 ;
if ( V_303 == 0 )
V_37 = F_127 ( V_225 , V_16 ) ;
} else {
V_37 = F_144 ( V_225 , V_16 , V_303 != 0 ) ;
}
F_5 ( V_11 , L_73 ,
V_225 -> V_48 , V_16 -> V_19 , V_37 ? L_74 : L_75 , V_37 ) ;
F_44 ( & V_16 -> V_41 ) ;
if ( ! V_303 )
F_156 ( & V_126 , V_307 ) ;
return V_37 ;
}
static int F_157 ( struct V_33 * V_34 , T_4 V_2 , void * V_235 )
{
struct V_114 * V_52 = V_235 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_37 = 0 ;
switch ( V_52 -> V_308 ) {
case V_309 : {
struct V_174 * V_175 ;
if ( F_158 ( V_52 , 1 ) !=
sizeof( struct V_174 ) ) {
V_37 = - V_6 ;
goto V_274;
}
V_175 = (struct V_174 * ) F_159 ( V_52 , 1 ) ;
F_5 ( V_11 , L_76 ,
V_175 -> V_181 , V_175 -> V_310 ) ;
V_37 = F_102 ( V_34 -> V_73 . V_74 . V_305 , V_175 ) ;
break;
}
case V_311 :
F_2 ( L_77 ) ;
V_37 = - V_312 ;
break;
case V_313 : {
V_37 = F_160 ( V_52 ) ;
break;
}
case V_314 : {
struct V_15 * V_16 ;
struct V_35 * V_36 ;
V_13 = F_161 ( V_52 , 1 ) ;
V_27 = (struct V_26 * ) F_159 ( V_52 , 2 ) ;
V_36 = * (struct V_35 * * ) F_159 ( V_52 , 3 ) ;
F_5 ( V_11 , L_78 , V_13 ,
V_27 -> V_42 ) ;
V_37 = F_38 ( V_34 , V_13 , V_27 , V_36 ) ;
if ( V_37 )
break;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( V_16 == NULL ) {
V_37 = - V_51 ;
break;
}
V_16 -> V_31 . V_43 |= V_315 ;
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 == 0 && V_16 -> V_22 != NULL ) {
if ( F_47 ( & V_34 -> V_73 . V_74 . V_75 ->
V_78 , V_79 ) ) {
V_37 = F_31 ( V_34 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_316 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_11 ( V_316 ) ;
}
if ( V_37 )
F_2 ( L_79 , V_37 ) ;
}
if ( V_37 == 0 && V_16 -> V_24 != NULL ) {
V_37 = F_31 ( V_34 , V_16 -> V_24 ) ;
if ( V_37 == - V_51 ) {
F_5 ( V_11 ,
L_80 ) ;
V_37 = 0 ;
}
if ( V_37 )
F_2 (
L_81 ,
V_34 -> V_48 , V_37 ) ;
}
F_11 ( V_16 ) ;
break;
}
case V_317 : {
V_13 = F_161 ( V_52 , 1 ) ;
if ( V_52 -> V_318 >= 2 )
V_27 = (struct V_26 * ) F_159 (
V_52 , 2 ) ;
V_37 = F_41 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_82 , V_52 -> V_308 ) ;
V_37 = - V_6 ;
goto V_274;
}
}
V_274:
return V_37 ;
}
int T_6 F_162 ( void )
{
return F_163 ( & V_319 , NULL , NULL ,
V_320 , NULL ) ;
}
static void F_164 ( void )
{
F_165 ( V_320 ) ;
}
