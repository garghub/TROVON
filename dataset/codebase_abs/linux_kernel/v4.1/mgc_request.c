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
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_15 * V_16 ;
F_46 ( V_34 ) ;
V_72 = V_34 -> V_75 . V_76 . V_77 ;
V_74 = & V_72 -> V_78 ;
F_47 ( V_69 , L_18 ,
F_48 ( V_74 , V_79 ) ? L_19 : L_20 ) ;
F_47 ( V_69 , L_21 ) ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( V_16 -> V_22 == NULL )
continue;
F_47 ( V_69 , L_22 ,
V_16 -> V_19 ,
V_16 -> V_22 -> V_31 . V_42 ) ;
}
F_15 ( & V_20 ) ;
F_49 ( V_34 ) ;
return 0 ;
}
static void F_50 ( struct V_15 * V_16 )
{
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_51 ( & V_16 -> V_25 -> V_80 -> V_75 . V_76 . V_81 ) ;
if ( V_16 -> V_25 -> V_80 -> V_75 . V_76 . V_82 != 0 ) {
F_5 ( V_11 , L_23 , V_16 -> V_19 ) ;
F_31 ( V_16 -> V_25 -> V_80 , V_16 ) ;
} else {
F_5 ( V_11 , L_24 ,
V_16 -> V_19 ) ;
}
F_52 ( & V_16 -> V_25 -> V_80 -> V_75 . V_76 . V_81 ) ;
}
static int F_53 ( void * V_70 )
{
bool V_83 = true ;
F_5 ( V_11 , L_25 ) ;
F_21 ( & V_20 ) ;
V_84 |= V_85 ;
while ( 1 ) {
struct V_86 V_87 ;
struct V_15 * V_16 , * V_88 ;
int rand = F_54 () & V_89 ;
int V_90 = ! ! ( V_84 & V_91 ) ;
int V_92 ;
V_84 &= ~ ( V_93 | V_94 ) ;
F_15 ( & V_20 ) ;
if ( V_83 ) {
V_83 = false ;
F_55 ( & V_95 ) ;
}
V_92 = V_96 * V_97 ;
V_92 += rand * V_97 / 100 ;
V_87 = F_56 ( V_92 , NULL , NULL ) ;
F_57 ( V_98 , V_84 & ( V_91 | V_99 ) ,
& V_87 ) ;
V_88 = NULL ;
F_21 ( & V_20 ) ;
V_84 &= ~ V_99 ;
F_22 (cld, &config_llog_list,
cld_list_chain) {
if ( ! V_16 -> V_100 )
continue;
F_15 ( & V_20 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_88 )
F_11 ( V_88 ) ;
V_88 = V_16 ;
V_16 -> V_100 = 0 ;
if ( F_58 ( ! V_90 ) )
F_50 ( V_16 ) ;
F_21 ( & V_20 ) ;
}
F_15 ( & V_20 ) ;
if ( V_88 )
F_11 ( V_88 ) ;
if ( F_43 ( V_90 ) ) {
F_21 ( & V_20 ) ;
break;
}
V_87 = (struct V_86 ) { 0 } ;
F_57 ( V_98 , V_84 & ( V_93 | V_91 ) ,
& V_87 ) ;
F_21 ( & V_20 ) ;
}
V_84 &= ~ V_85 ;
F_15 ( & V_20 ) ;
F_55 ( & V_101 ) ;
F_5 ( V_11 , L_26 ) ;
return 0 ;
}
static void F_59 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_27 ,
V_16 -> V_19 , F_10 ( & V_16 -> V_17 ) ,
V_16 -> V_32 , V_84 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_42 ( & V_16 -> V_41 ) ;
if ( V_16 -> V_32 || V_16 -> V_100 ) {
F_44 ( & V_16 -> V_41 ) ;
return;
}
F_8 ( V_16 ) ;
V_16 -> V_100 = 1 ;
F_44 ( & V_16 -> V_41 ) ;
F_21 ( & V_20 ) ;
if ( V_84 & V_91 ) {
F_15 ( & V_20 ) ;
V_16 -> V_100 = 0 ;
F_11 ( V_16 ) ;
} else {
V_84 |= V_93 ;
F_15 ( & V_20 ) ;
F_60 ( & V_98 ) ;
}
}
static int F_61 ( const struct V_102 * V_103 , struct V_33 * V_34 )
{
struct V_104 * V_105 ;
int V_37 ;
V_37 = F_62 ( V_103 , V_34 , & V_34 -> V_106 , V_107 , V_34 ,
& V_108 ) ;
if ( V_37 )
return V_37 ;
V_105 = F_63 ( V_34 , V_107 ) ;
F_12 ( V_105 ) ;
F_64 ( V_105 ) ;
F_65 ( V_105 ) ;
return 0 ;
}
static int F_66 ( const struct V_102 * V_103 , struct V_33 * V_34 )
{
struct V_104 * V_105 ;
V_105 = F_63 ( V_34 , V_107 ) ;
if ( V_105 )
F_67 ( V_103 , V_105 ) ;
return 0 ;
}
static int F_68 ( struct V_33 * V_34 , enum V_109 V_110 )
{
int V_37 = 0 ;
int V_111 ;
switch ( V_110 ) {
case V_112 :
break;
case V_113 :
if ( F_69 ( & V_114 ) ) {
F_12 ( V_84 & V_85 ) ;
V_111 = V_91 ;
} else {
V_111 = V_93 | V_99 ;
}
F_21 ( & V_20 ) ;
V_84 |= V_111 ;
F_15 ( & V_20 ) ;
F_60 ( & V_98 ) ;
if ( V_111 & V_91 )
F_70 ( & V_101 ) ;
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
if ( V_34 -> V_115 -> V_116 <= 1 )
F_73 () ;
F_74 ( V_34 ) ;
F_75 () ;
return F_76 ( V_34 ) ;
}
static int F_77 ( struct V_33 * V_34 , struct V_117 * V_52 )
{
struct V_118 V_119 ;
int V_37 ;
F_78 () ;
V_37 = F_79 ( V_34 , V_52 ) ;
if ( V_37 )
goto V_120;
V_37 = F_61 ( NULL , V_34 ) ;
if ( V_37 ) {
F_2 ( L_29 ) ;
goto V_121;
}
F_80 ( & V_119 ) ;
F_81 ( V_34 , V_119 . V_122 ) ;
F_82 ( V_34 ) ;
if ( F_83 ( & V_114 ) == 1 ) {
V_84 = 0 ;
F_84 ( & V_98 ) ;
V_37 = F_40 ( F_85 ( F_53 , NULL ,
L_30 ) ) ;
if ( F_86 ( V_37 ) ) {
F_2 ( L_31 ,
V_34 -> V_48 , V_37 ) ;
goto V_121;
}
V_37 = 0 ;
F_70 ( & V_95 ) ;
}
return V_37 ;
V_121:
F_76 ( V_34 ) ;
V_120:
F_75 () ;
return V_37 ;
}
static int F_87 ( struct V_123 * V_124 , struct V_125 * V_126 ,
void * V_70 , int V_127 )
{
struct V_128 V_129 ;
struct V_15 * V_16 = (struct V_15 * ) V_70 ;
int V_37 = 0 ;
switch ( V_127 ) {
case V_130 :
F_88 ( V_124 , L_32 ) ;
F_89 ( V_124 , & V_129 ) ;
V_37 = F_90 ( & V_129 , V_131 ) ;
break;
case V_132 :
F_88 ( V_124 , L_33 ) ;
F_5 ( V_11 , L_34 V_133 L_35 ,
F_91 ( V_124 -> V_134 ) ,
( char * ) & V_124 -> V_134 -> V_135 . V_1 [ 0 ] ) ;
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
if ( ! V_124 -> V_136 ||
! V_124 -> V_136 -> V_80 -> V_75 . V_76 . V_82 ) {
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
static int F_92 ( struct V_137 * exp ,
struct V_138 * V_139 )
{
struct V_140 * V_141 ;
struct V_138 * V_142 , * V_143 ;
int V_37 ;
V_141 = F_93 ( F_94 ( exp ) ,
& V_144 , V_145 ,
V_146 ) ;
if ( ! V_141 )
return - V_38 ;
V_142 = F_95 ( & V_141 -> V_147 , & V_148 ) ;
if ( ! V_142 ) {
F_96 ( V_141 ) ;
return - V_38 ;
}
memcpy ( V_142 , V_139 , sizeof( * V_142 ) ) ;
F_97 ( V_141 ) ;
V_141 -> V_149 = V_150 ;
V_37 = F_98 ( V_141 ) ;
if ( ! V_37 ) {
V_143 = F_99 ( & V_141 -> V_147 , & V_148 ) ;
memcpy ( V_139 , V_143 , sizeof( * V_143 ) ) ;
}
F_96 ( V_141 ) ;
return V_37 ;
}
static int F_100 ( struct V_137 * exp , struct V_151 * V_152 ,
T_2 type , T_3 * V_153 , T_2 V_154 ,
T_1 * V_155 , void * V_156 , void * V_157 , void * V_158 ,
void * V_70 , T_2 V_159 , void * V_160 ,
struct V_128 * V_129 )
{
struct V_15 * V_16 = (struct V_15 * ) V_70 ;
struct V_161 V_162 = {
. V_163 = type ,
. V_164 = V_154 ,
. V_165 = F_87 ,
. V_166 = V_167 ,
} ;
struct V_140 * V_141 ;
int V_168 = F_16 ( V_16 ) ;
int V_37 ;
F_5 ( V_11 , L_39 , V_16 -> V_19 ,
V_16 -> V_49 . V_1 [ 0 ] ) ;
V_141 = F_93 ( F_94 ( exp ) ,
& V_169 , V_170 ,
V_171 ) ;
if ( V_141 == NULL )
return - V_38 ;
F_101 ( & V_141 -> V_147 , & V_172 , V_173 , 0 ) ;
F_97 ( V_141 ) ;
if ( V_16 -> V_31 . V_44 ) {
struct V_53 * V_54 = F_33 ( V_16 -> V_31 . V_44 ) ;
if ( V_54 && F_36 ( V_54 ) )
V_168 = 1 ;
}
V_141 -> V_149 = V_168 ? 5 : V_174 ;
V_37 = F_102 ( exp , & V_141 , & V_162 , & V_16 -> V_49 , NULL , V_155 ,
NULL , 0 , V_175 , V_129 , 0 ) ;
F_96 ( V_141 ) ;
return V_37 ;
}
static void F_103 ( struct V_33 * V_176 )
{
F_21 ( & V_20 ) ;
V_84 |= V_93 ;
F_15 ( & V_20 ) ;
F_60 ( & V_98 ) ;
}
static int F_104 ( struct V_137 * exp ,
struct V_177 * V_178 )
{
struct V_140 * V_141 ;
struct V_177 * V_179 , * V_180 ;
int V_37 ;
V_141 = F_93 ( F_94 ( exp ) ,
& V_181 , V_145 ,
V_182 ) ;
if ( V_141 == NULL )
return - V_38 ;
V_179 = F_95 ( & V_141 -> V_147 , & V_183 ) ;
if ( ! V_179 ) {
F_96 ( V_141 ) ;
return - V_38 ;
}
memcpy ( V_179 , V_178 , sizeof( * V_179 ) ) ;
F_97 ( V_141 ) ;
F_5 ( V_11 , L_40 , V_178 -> V_184 ) ;
V_141 -> V_149 = V_185 ;
V_37 = F_98 ( V_141 ) ;
if ( ! V_37 ) {
V_180 = F_99 ( & V_141 -> V_147 ,
& V_183 ) ;
memcpy ( V_178 , V_180 , sizeof( * V_180 ) ) ;
F_5 ( V_11 , L_41 ,
V_178 -> V_184 , V_178 -> V_186 ) ;
}
F_96 ( V_141 ) ;
return V_37 ;
}
static int F_105 ( const struct V_102 * V_103 , struct V_137 * exp ,
T_4 V_187 , void * V_188 , T_4 V_189 ,
void * V_190 , struct V_191 * V_192 )
{
int V_37 = - V_6 ;
if ( F_106 ( V_193 ) ) {
struct V_71 * V_72 = F_94 ( exp ) ;
int V_194 ;
if ( V_189 != sizeof( int ) )
return - V_6 ;
V_194 = * ( int * ) V_190 ;
F_5 ( V_11 , L_42 ,
V_72 -> V_195 -> V_48 , V_194 ,
V_72 -> V_196 , V_72 -> V_197 ,
V_72 -> V_198 , V_72 -> V_195 -> V_199 ,
F_107 ( V_72 -> V_200 ) ) ;
if ( ( V_72 -> V_200 != V_201 &&
V_72 -> V_200 != V_202 ) || V_194 > 1 )
F_108 ( V_72 ) ;
return 0 ;
}
if ( F_106 ( V_203 ) ) {
struct V_138 * V_139 ;
V_139 = (struct V_138 * ) V_190 ;
V_37 = F_92 ( exp , V_139 ) ;
return V_37 ;
}
if ( F_106 ( V_204 ) ) {
struct V_205 * V_76 = & exp -> V_80 -> V_75 . V_76 ;
struct V_206 V_207 ;
if ( V_189 == 0 ) {
if ( V_76 -> V_208 . V_209 != V_210 )
return 0 ;
V_190 = L_43 ;
V_189 = 4 ;
}
V_37 = F_109 ( V_190 , & V_207 ) ;
if ( V_37 ) {
F_2 ( L_44 ,
( char * ) V_190 ) ;
return V_37 ;
}
if ( V_76 -> V_208 . V_209 == V_210 ) {
V_76 -> V_208 = V_207 ;
} else if ( memcmp ( & V_76 -> V_208 , & V_207 ,
sizeof( V_207 ) ) != 0 ) {
char V_211 [ 20 ] ;
F_110 ( & V_76 -> V_208 ,
V_211 , sizeof( V_211 ) ) ;
F_111 ( L_45 ,
( char * ) V_190 , V_211 ) ;
V_37 = - V_212 ;
}
return V_37 ;
}
return V_37 ;
}
static int F_112 ( const struct V_102 * V_103 , struct V_137 * exp ,
T_2 V_187 , void * V_188 , T_2 * V_189 , void * V_190 ,
struct V_151 * V_176 )
{
int V_37 = - V_6 ;
if ( F_106 ( V_213 ) ) {
struct V_71 * V_72 = F_94 ( exp ) ;
struct V_73 * V_70 = V_190 ;
if ( * V_189 == sizeof( * V_70 ) ) {
* V_70 = V_72 -> V_78 ;
V_37 = 0 ;
}
}
return V_37 ;
}
static int F_113 ( struct V_33 * V_34 ,
struct V_71 * V_72 ,
enum V_214 V_215 )
{
F_12 ( V_72 -> V_195 == V_34 ) ;
F_5 ( V_11 , L_46 , V_215 ) ;
switch ( V_215 ) {
case V_216 :
if ( F_48 ( & V_72 -> V_78 , V_79 ) )
F_114 () ;
break;
case V_217 :
break;
case V_218 : {
struct V_219 * V_220 = V_34 -> V_221 ;
F_115 ( V_220 , V_222 ) ;
break;
}
case V_223 :
F_5 ( V_18 , L_47 , V_34 -> V_48 ) ;
V_34 -> V_224 = 0 ;
F_103 ( V_34 ) ;
if ( F_48 ( & V_72 -> V_78 , V_79 ) )
F_116 () ;
break;
case V_225 :
break;
case V_226 :
case V_227 :
break;
default:
F_2 ( L_48 , V_215 ) ;
F_4 () ;
}
return 0 ;
}
static int F_117 ( struct V_33 * V_228 ,
struct V_15 * V_16 ,
T_1 V_229 ,
void * V_70 , int V_230 , bool V_231 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_53 * V_54 = F_33 ( V_27 -> V_44 ) ;
struct V_232 * V_233 ;
struct V_117 * V_52 ;
struct V_234 V_235 ;
T_5 V_236 = 0 ;
char * V_237 ;
char * V_238 ;
int V_239 ;
int V_240 ;
int V_37 = 0 ;
int V_241 = 0 ;
F_12 ( V_27 -> V_30 != NULL ) ;
F_12 ( V_27 -> V_44 == V_27 -> V_30 ) ;
F_24 ( V_237 , V_242 ) ;
if ( V_237 == NULL )
return - V_38 ;
if ( ! F_36 ( V_54 ) ) {
V_240 = snprintf ( V_237 , V_242 , L_49 , V_27 -> V_30 ) ;
if ( V_240 >= V_242 ) {
F_19 ( V_237 , V_242 ) ;
return - V_243 ;
}
} else {
F_12 ( F_35 ( V_54 ) ) ;
V_37 = F_118 ( V_54 -> V_244 , V_237 , NULL ,
V_242 ) ;
if ( V_37 ) {
F_19 ( V_237 , V_242 ) ;
return - V_6 ;
}
V_240 = strlen ( V_237 ) ;
}
++ V_240 ;
V_238 = V_237 + V_240 ;
V_239 = V_242 - V_240 ;
while ( V_230 > 0 ) {
int V_245 = sizeof( * V_233 ) ;
int V_246 ;
struct V_33 * V_34 ;
char * V_247 ;
char * V_248 ;
char * V_249 ;
char * V_250 ;
V_37 = - V_6 ;
if ( V_230 < sizeof( * V_233 ) )
break;
V_233 = ( F_119 ( V_233 ) ) ( V_70 + V_241 ) ;
if ( V_233 -> V_251 != 0 )
break;
if ( V_233 -> V_252 == 0 )
break;
if ( V_233 -> V_253 != sizeof( V_254 ) )
break;
V_245 += V_233 -> V_252 * V_233 -> V_253 ;
if ( V_230 < V_245 )
break;
if ( V_231 )
F_120 ( V_233 ) ;
if ( V_233 -> V_255 > V_242 ) {
F_2 ( L_50 , V_233 -> V_255 ) ;
break;
}
if ( V_233 -> V_255 < V_245 )
break;
V_241 += V_233 -> V_255 ;
V_230 -= V_233 -> V_255 ;
if ( V_230 < 0 )
break;
if ( V_233 -> V_256 > V_229 ) {
F_2 ( L_51 ,
V_233 -> V_256 , V_229 ) ;
break;
}
if ( V_236 >= V_233 -> V_256 ) {
F_2 ( L_52 ,
V_236 , V_233 -> V_256 ) ;
break;
}
V_236 = V_233 -> V_256 ;
V_246 = V_233 -> V_257 == V_258 ;
memset ( V_238 , 0 , V_239 ) ;
V_247 = V_238 ;
V_240 = 0 ;
strcpy ( V_247 , V_16 -> V_19 ) ;
V_248 = strrchr ( V_247 , '-' ) ;
if ( V_248 == NULL ) {
F_2 ( L_53 ,
V_228 -> V_48 , V_247 ) ;
break;
}
V_240 = V_248 - V_247 ;
V_247 [ V_240 ] = 0 ;
V_240 += sprintf ( V_247 + V_240 , L_54 ,
V_246 ? L_55 : L_56 , V_233 -> V_259 ) ;
V_248 = V_246 ? L_57 : L_58 ,
V_240 += sprintf ( V_247 + V_240 , L_59 , V_248 , V_237 ) ;
F_121 ( & V_235 , V_247 ) ;
V_34 = F_122 ( V_247 ) ;
if ( V_34 == NULL ) {
F_5 ( V_18 , L_60 ,
V_228 -> V_48 , V_247 ) ;
V_37 = 0 ;
continue;
}
++ V_240 ;
V_249 = V_238 + V_240 ;
V_240 += sprintf ( V_249 , L_61 , V_248 , L_62 ) ;
V_250 = V_238 + V_240 ;
F_51 ( & V_34 -> V_75 . V_76 . V_81 ) ;
if ( V_34 -> V_75 . V_76 . V_77 == NULL ) {
F_52 ( & V_34 -> V_75 . V_76 . V_81 ) ;
V_37 = 0 ;
continue;
}
V_37 = F_123 ( V_34 -> V_75 . V_76 . V_77 ,
V_233 -> V_75 . V_260 [ 0 ] ,
(struct V_261 * ) V_250 ) ;
F_52 ( & V_34 -> V_75 . V_76 . V_81 ) ;
if ( V_37 < 0 ) {
F_2 ( L_63 ,
F_124 ( V_233 -> V_75 . V_260 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_64 ,
V_250 , F_124 ( V_233 -> V_75 . V_260 [ 0 ] ) ) ;
V_240 += strlen ( V_250 ) ;
V_240 += sprintf ( V_238 + V_240 , L_65 , V_233 -> V_262 ) ;
F_12 ( V_240 < V_239 ) ;
F_125 ( & V_235 , 1 , V_249 ) ;
V_37 = - V_38 ;
V_52 = F_126 ( V_263 , & V_235 ) ;
if ( V_52 == NULL ) {
F_2 ( L_66 ) ;
break;
}
F_5 ( V_18 , L_67 ,
V_236 , V_229 , V_247 , V_249 ) ;
V_37 = F_127 ( V_52 ) ;
F_128 ( V_52 ) ;
if ( V_37 )
F_5 ( V_18 , L_68 ,
V_247 , V_37 ) ;
}
F_19 ( V_237 , V_242 ) ;
return V_37 ;
}
static int F_129 ( struct V_33 * V_34 ,
struct V_15 * V_16 )
{
struct V_140 * V_141 = NULL ;
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_264 * V_265 ;
struct V_266 * V_267 ;
struct V_268 * V_126 ;
struct V_269 * * V_270 ;
int V_271 ;
bool V_272 = true ;
bool V_231 = false ;
int V_273 ;
int V_274 ;
int V_37 ;
V_271 = V_275 ;
if ( V_27 -> V_42 == 0 )
V_271 = V_276 ;
F_24 ( V_270 , sizeof( * V_270 ) * V_271 ) ;
if ( V_270 == NULL ) {
V_37 = - V_38 ;
goto V_277;
}
for ( V_273 = 0 ; V_273 < V_271 ; V_273 ++ ) {
V_270 [ V_273 ] = F_130 ( V_278 ) ;
if ( V_270 [ V_273 ] == NULL ) {
V_37 = - V_38 ;
goto V_277;
}
}
V_279:
F_12 ( F_131 ( V_16 ) ) ;
F_12 ( F_132 ( & V_16 -> V_41 ) ) ;
V_141 = F_133 ( F_94 ( V_16 -> V_25 ) ,
& V_280 ) ;
if ( V_141 == NULL ) {
V_37 = - V_38 ;
goto V_277;
}
V_37 = F_134 ( V_141 , V_145 , V_281 ) ;
if ( V_37 )
goto V_277;
V_265 = F_95 ( & V_141 -> V_147 , & V_282 ) ;
F_12 ( V_265 != NULL ) ;
F_12 ( sizeof( V_265 -> V_283 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_135 ( V_265 -> V_283 , V_16 -> V_19 , sizeof( V_265 -> V_283 ) )
>= sizeof( V_265 -> V_283 ) ) {
V_37 = - V_243 ;
goto V_277;
}
V_265 -> V_284 = V_27 -> V_42 + 1 ;
V_265 -> V_285 = V_16 -> V_45 ;
V_265 -> V_286 = V_287 ;
V_265 -> V_288 = V_271 ;
V_126 = F_136 ( V_141 , V_271 , 1 , V_289 ,
V_290 ) ;
if ( V_126 == NULL ) {
V_37 = - V_38 ;
goto V_277;
}
for ( V_273 = 0 ; V_273 < V_271 ; V_273 ++ )
F_137 ( V_126 , V_270 [ V_273 ] , 0 , V_242 ) ;
F_97 ( V_141 ) ;
V_37 = F_98 ( V_141 ) ;
if ( V_37 )
goto V_277;
V_267 = F_99 ( & V_141 -> V_147 , & V_291 ) ;
if ( V_267 -> V_292 < V_267 -> V_293 ) {
V_37 = - V_6 ;
goto V_277;
}
V_27 -> V_42 = V_267 -> V_293 ;
V_272 = V_267 -> V_293 == V_267 -> V_292 ;
F_5 ( V_18 , L_69 ,
V_267 -> V_293 , V_272 == false ) ;
V_274 = F_138 ( V_141 , V_141 -> V_294 , 0 ) ;
if ( V_274 < 0 ) {
V_37 = V_274 ;
goto V_277;
}
if ( V_274 > V_271 << V_287 ) {
V_37 = - V_6 ;
goto V_277;
}
if ( V_274 == 0 ) {
if ( ! V_272 )
V_37 = - V_6 ;
goto V_277;
}
V_231 = ! ! F_139 ( V_141 ) ;
#if V_295 < F_140 ( 3 , 2 , 50 , 0 )
if ( F_43 ( V_141 -> V_296 -> V_297 ) )
V_231 = ! V_231 ;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for ( V_273 = 0 ; V_273 < V_271 && V_274 > 0 ; V_273 ++ ) {
int V_298 ;
void * V_59 ;
V_59 = F_141 ( V_270 [ V_273 ] ) ;
V_298 = F_117 ( V_34 , V_16 , V_267 -> V_293 , V_59 ,
F_142 ( int , V_274 , V_242 ) ,
V_231 ) ;
F_143 ( V_270 [ V_273 ] ) ;
if ( V_298 < 0 ) {
F_144 ( L_70 ,
V_16 -> V_19 , V_298 ) ;
break;
}
V_274 -= V_242 ;
}
V_277:
if ( V_141 )
F_96 ( V_141 ) ;
if ( V_37 == 0 && ! V_272 )
goto V_279;
if ( V_270 ) {
for ( V_273 = 0 ; V_273 < V_271 ; V_273 ++ ) {
if ( V_270 [ V_273 ] == NULL )
break;
F_145 ( V_270 [ V_273 ] ) ;
}
F_19 ( V_270 , sizeof( * V_270 ) * V_271 ) ;
}
return V_37 ;
}
static int F_146 ( struct V_33 * V_228 ,
struct V_15 * V_16 , int V_299 )
{
struct V_104 * V_105 ;
struct V_53 * V_54 = NULL ;
int V_37 = 0 ;
bool V_300 = false ;
struct V_102 * V_103 ;
F_12 ( V_16 ) ;
F_12 ( F_132 ( & V_16 -> V_41 ) ) ;
if ( F_16 ( V_16 ) && V_299 )
return 0 ;
if ( V_16 -> V_31 . V_44 )
V_54 = F_33 ( V_16 -> V_31 . V_44 ) ;
F_147 ( V_103 ) ;
if ( V_103 == NULL )
return - V_38 ;
V_37 = F_148 ( V_103 , V_301 ) ;
if ( V_37 )
goto V_302;
V_105 = F_63 ( V_228 , V_107 ) ;
F_12 ( V_105 ) ;
if ( V_299 ) {
V_37 = - V_303 ;
goto V_304;
}
if ( F_16 ( V_16 ) ) {
F_149 ( V_16 -> V_19 ) ;
V_300 = true ;
}
V_37 = F_150 ( V_103 , V_105 , V_16 -> V_19 ,
& V_16 -> V_31 ) ;
V_304:
F_151 ( V_103 , V_105 ) ;
if ( V_300 ) {
F_12 ( F_16 ( V_16 ) ) ;
F_152 ( V_16 -> V_19 ) ;
F_153 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_12 ) ) ;
}
F_154 ( V_103 ) ;
V_302:
F_155 ( V_103 ) ;
return V_37 ;
}
int F_31 ( struct V_33 * V_228 , struct V_15 * V_16 )
{
struct V_128 V_129 = { 0 } ;
T_1 V_155 = V_305 ;
int V_37 = 0 , V_306 ;
F_12 ( V_16 ) ;
F_42 ( & V_16 -> V_41 ) ;
if ( V_16 -> V_32 ) {
F_44 ( & V_16 -> V_41 ) ;
return 0 ;
}
F_156 ( V_307 , 20 ) ;
F_5 ( V_11 , L_71 , V_16 -> V_19 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_42 + 1 ) ;
V_306 = F_100 ( V_228 -> V_75 . V_76 . V_308 , NULL , V_309 , NULL ,
V_310 , & V_155 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_129 ) ;
if ( V_306 == 0 ) {
F_8 ( V_16 ) ;
V_37 = F_157 ( & V_129 , ( void * ) V_16 ) ;
F_12 ( V_37 == 0 ) ;
} else {
F_5 ( V_11 , L_72 , V_306 ) ;
V_16 -> V_100 = 1 ;
F_8 ( V_16 ) ;
}
if ( F_131 ( V_16 ) ) {
V_37 = 0 ;
if ( V_306 == 0 )
V_37 = F_129 ( V_228 , V_16 ) ;
} else {
V_37 = F_146 ( V_228 , V_16 , V_306 != 0 ) ;
}
F_5 ( V_11 , L_73 ,
V_228 -> V_48 , V_16 -> V_19 , V_37 ? L_74 : L_75 , V_37 ) ;
F_44 ( & V_16 -> V_41 ) ;
if ( ! V_306 )
F_158 ( & V_129 , V_310 ) ;
return V_37 ;
}
static int F_159 ( struct V_33 * V_34 , T_4 V_2 , void * V_238 )
{
struct V_117 * V_52 = V_238 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_37 = 0 ;
switch ( V_52 -> V_311 ) {
case V_312 : {
struct V_177 * V_178 ;
if ( F_160 ( V_52 , 1 ) !=
sizeof( struct V_177 ) ) {
V_37 = - V_6 ;
goto V_277;
}
V_178 = (struct V_177 * ) F_161 ( V_52 , 1 ) ;
F_5 ( V_11 , L_76 ,
V_178 -> V_184 , V_178 -> V_313 ) ;
V_37 = F_104 ( V_34 -> V_75 . V_76 . V_308 , V_178 ) ;
break;
}
case V_314 :
F_2 ( L_77 ) ;
V_37 = - V_315 ;
break;
case V_316 : {
V_37 = F_162 ( V_52 ) ;
break;
}
case V_317 : {
struct V_15 * V_16 ;
struct V_35 * V_36 ;
V_13 = F_163 ( V_52 , 1 ) ;
V_27 = (struct V_26 * ) F_161 ( V_52 , 2 ) ;
V_36 = * (struct V_35 * * ) F_161 ( V_52 , 3 ) ;
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
V_16 -> V_31 . V_43 |= V_318 ;
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 == 0 && V_16 -> V_22 != NULL ) {
if ( F_48 ( & V_34 -> V_75 . V_76 . V_77 ->
V_78 , V_79 ) ) {
V_37 = F_31 ( V_34 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_319 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_11 ( V_319 ) ;
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
case V_320 : {
V_13 = F_163 ( V_52 , 1 ) ;
if ( V_52 -> V_321 >= 2 )
V_27 = (struct V_26 * ) F_161 (
V_52 , 2 ) ;
V_37 = F_41 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_82 , V_52 -> V_311 ) ;
V_37 = - V_6 ;
goto V_277;
}
}
V_277:
return V_37 ;
}
static int T_6 F_164 ( void )
{
return F_165 ( & V_322 , NULL , NULL ,
V_323 , NULL ) ;
}
static void F_166 ( void )
{
F_167 ( V_323 ) ;
}
