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
F_12 ( V_13 ) ;
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
static struct V_15 *
F_32 ( struct V_33 * V_34 , char * V_12 ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_26 V_53 = * V_27 ;
struct V_15 * V_16 ;
char V_13 [ 32 ] ;
F_12 ( strlen ( V_12 ) < sizeof( V_13 ) / 2 ) ;
strcpy ( V_13 , V_12 ) ;
F_12 ( V_53 . V_30 ) ;
strcat ( V_13 , L_8 ) ;
V_16 = F_23 ( V_34 , V_13 , V_9 , & V_53 , V_36 ) ;
return V_16 ;
}
static struct V_15 *
F_33 ( struct V_33 * V_34 ,
struct V_26 * V_27 , struct V_35 * V_36 )
{
struct V_26 V_53 = * V_27 ;
struct V_15 * V_16 ;
V_53 . V_30 = V_36 ;
V_16 = F_23 ( V_34 , V_54 , V_10 ,
& V_53 , V_36 ) ;
return V_16 ;
}
static int F_34 ( struct V_33 * V_34 , char * V_13 ,
struct V_26 * V_27 ,
struct V_35 * V_36 )
{
struct V_55 * V_56 = F_35 ( V_36 ) ;
struct V_15 * V_16 ;
struct V_15 * V_57 ;
struct V_15 * V_58 ;
char V_59 [ 32 ] ;
char * V_60 ;
int V_37 ;
F_5 ( V_11 , L_9 , V_13 , V_27 -> V_30 ) ;
V_60 = strrchr ( V_13 , '-' ) ;
if ( ! V_60 || V_60 - V_13 > 8 ) {
F_2 ( L_10 , V_13 ) ;
return - V_6 ;
}
memcpy ( V_59 , V_13 , V_60 - V_13 ) ;
strcpy ( V_59 + ( V_60 - V_13 ) , L_11 ) ;
V_57 = F_20 ( V_59 , NULL ) ;
if ( ! V_57 ) {
V_57 = F_23 ( V_34 , V_59 ,
V_8 , NULL , NULL ) ;
if ( F_36 ( V_57 ) ) {
F_2 ( L_12 , V_59 ) ;
V_37 = F_37 ( V_57 ) ;
goto V_61;
}
}
V_58 = F_33 ( V_34 , V_27 , V_36 ) ;
if ( F_36 ( V_58 ) ) {
V_37 = F_37 ( V_58 ) ;
F_2 ( L_13 ,
V_34 -> V_49 , V_37 ) ;
goto V_62;
}
V_16 = F_23 ( V_34 , V_13 , V_7 , V_27 , V_36 ) ;
if ( F_36 ( V_16 ) ) {
F_2 ( L_14 , V_13 ) ;
V_37 = F_37 ( V_16 ) ;
goto V_63;
}
V_16 -> V_23 = V_57 ;
V_16 -> V_24 = V_58 ;
F_12 ( V_56 -> V_64 ) ;
if ( ! ( V_56 -> V_64 -> V_65 & V_66 ) ) {
struct V_15 * V_67 ;
V_60 = strrchr ( V_59 , '-' ) ;
if ( V_60 ) {
* V_60 = 0 ;
} else {
F_2 ( L_15 ,
V_34 -> V_49 , V_59 , - V_6 ) ;
F_11 ( V_16 ) ;
return - V_6 ;
}
V_67 = F_32 ( V_34 , V_59 , V_27 , V_36 ) ;
if ( F_36 ( V_67 ) ) {
V_37 = F_37 ( V_67 ) ;
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
static int F_38 ( char * V_13 , struct V_26 * V_27 )
{
struct V_15 * V_16 ;
struct V_15 * V_23 = NULL ;
struct V_15 * V_24 = NULL ;
struct V_15 * V_22 = NULL ;
int V_37 = 0 ;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( ! V_16 )
return - V_52 ;
F_39 ( & V_16 -> V_42 ) ;
if ( F_40 ( V_16 -> V_32 ) ) {
F_41 ( & V_16 -> V_42 ) ;
F_11 ( V_16 ) ;
return V_37 ;
}
V_16 -> V_32 = 1 ;
V_22 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_41 ( & V_16 -> V_42 ) ;
if ( V_22 ) {
F_39 ( & V_22 -> V_42 ) ;
V_22 -> V_32 = 1 ;
F_41 ( & V_22 -> V_42 ) ;
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
F_39 ( & V_24 -> V_42 ) ;
V_24 -> V_32 = 1 ;
F_41 ( & V_24 -> V_42 ) ;
F_11 ( V_24 ) ;
}
F_11 ( V_16 ) ;
F_11 ( V_16 ) ;
F_5 ( V_11 , L_16 , V_13 ? V_13 : L_17 ,
V_37 ) ;
return V_37 ;
}
int F_42 ( struct V_69 * V_70 , void * V_71 )
{
struct V_33 * V_34 = V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_15 * V_16 ;
int V_37 ;
V_37 = F_43 ( V_34 ) ;
if ( V_37 )
return V_37 ;
V_73 = V_34 -> V_76 . V_77 . V_78 ;
V_75 = & V_73 -> V_79 ;
F_44 ( V_70 , L_18 ,
F_45 ( V_75 , V_80 ) ? L_19 : L_20 ) ;
F_44 ( V_70 , L_21 ) ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( ! V_16 -> V_22 )
continue;
F_44 ( V_70 , L_22 ,
V_16 -> V_19 ,
V_16 -> V_22 -> V_31 . V_43 ) ;
}
F_15 ( & V_20 ) ;
F_46 ( & V_34 -> V_76 . V_77 . V_81 ) ;
return 0 ;
}
static void F_47 ( struct V_15 * V_16 )
{
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_48 ( & V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_81 ,
V_83 ) ;
if ( V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_84 != 0 ) {
int V_37 ;
F_5 ( V_11 , L_23 , V_16 -> V_19 ) ;
V_37 = F_31 ( V_16 -> V_25 -> V_82 , V_16 ) ;
if ( V_37 && V_37 != - V_52 )
F_2 ( L_24 , V_37 ) ;
} else {
F_5 ( V_11 , L_25 ,
V_16 -> V_19 ) ;
}
F_46 ( & V_16 -> V_25 -> V_82 -> V_76 . V_77 . V_81 ) ;
}
static int F_49 ( void * V_71 )
{
bool V_85 = true ;
F_5 ( V_11 , L_26 ) ;
F_21 ( & V_20 ) ;
V_86 |= V_87 ;
while ( 1 ) {
struct V_88 V_89 ;
struct V_15 * V_16 , * V_90 ;
int rand = F_50 () & V_91 ;
int V_92 = ! ! ( V_86 & V_93 ) ;
int V_94 ;
V_86 &= ~ ( V_95 | V_96 ) ;
F_15 ( & V_20 ) ;
if ( V_85 ) {
V_85 = false ;
F_51 ( & V_97 ) ;
}
V_94 = F_52 ( V_98 * V_99 ) ;
V_94 += F_52 ( rand * V_99 / 100 ) ;
V_89 = F_53 ( V_94 , NULL , NULL ) ;
F_54 ( V_100 , V_86 & ( V_93 | V_101 ) ,
& V_89 ) ;
V_90 = NULL ;
F_21 ( & V_20 ) ;
V_86 &= ~ V_101 ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( ! V_16 -> V_102 )
continue;
F_15 ( & V_20 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_90 )
F_11 ( V_90 ) ;
V_90 = V_16 ;
V_16 -> V_102 = 0 ;
if ( F_55 ( ! V_92 ) )
F_47 ( V_16 ) ;
F_21 ( & V_20 ) ;
}
F_15 ( & V_20 ) ;
if ( V_90 )
F_11 ( V_90 ) ;
if ( F_40 ( V_92 ) ) {
F_21 ( & V_20 ) ;
break;
}
V_89 = (struct V_88 ) { 0 } ;
F_54 ( V_100 , V_86 & ( V_95 | V_93 ) ,
& V_89 ) ;
F_21 ( & V_20 ) ;
}
V_86 &= ~ V_87 ;
F_15 ( & V_20 ) ;
F_51 ( & V_103 ) ;
F_5 ( V_11 , L_27 ) ;
return 0 ;
}
static void F_56 ( struct V_15 * V_16 )
{
F_5 ( V_18 , L_28 ,
V_16 -> V_19 , F_10 ( & V_16 -> V_17 ) ,
V_16 -> V_32 , V_86 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_39 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_32 || V_16 -> V_102 ) {
F_41 ( & V_16 -> V_42 ) ;
return;
}
F_8 ( V_16 ) ;
V_16 -> V_102 = 1 ;
F_41 ( & V_16 -> V_42 ) ;
F_21 ( & V_20 ) ;
if ( V_86 & V_93 ) {
F_15 ( & V_20 ) ;
V_16 -> V_102 = 0 ;
F_11 ( V_16 ) ;
} else {
V_86 |= V_95 ;
F_15 ( & V_20 ) ;
F_57 ( & V_100 ) ;
}
}
static int F_58 ( const struct V_104 * V_105 , struct V_33 * V_34 )
{
struct V_106 * V_107 ;
int V_37 ;
V_37 = F_59 ( V_105 , V_34 , & V_34 -> V_108 , V_109 , V_34 ,
& V_110 ) ;
if ( V_37 )
return V_37 ;
V_107 = F_60 ( V_34 , V_109 ) ;
F_12 ( V_107 ) ;
F_61 ( V_107 ) ;
F_62 ( V_107 ) ;
return 0 ;
}
static int F_63 ( const struct V_104 * V_105 , struct V_33 * V_34 )
{
struct V_106 * V_107 ;
V_107 = F_60 ( V_34 , V_109 ) ;
if ( V_107 )
F_64 ( V_105 , V_107 ) ;
return 0 ;
}
static int F_65 ( struct V_33 * V_34 )
{
int V_37 = 0 ;
int V_111 ;
if ( F_66 ( & V_112 ) ) {
F_12 ( V_86 & V_87 ) ;
V_111 = V_93 ;
} else {
V_111 = V_95 | V_101 ;
}
F_21 ( & V_20 ) ;
V_86 |= V_111 ;
F_15 ( & V_20 ) ;
F_57 ( & V_100 ) ;
if ( V_111 & V_93 )
F_67 ( & V_103 ) ;
F_68 ( V_34 ) ;
V_37 = F_63 ( NULL , V_34 ) ;
if ( V_37 )
F_2 ( L_29 ) ;
return V_37 ;
}
static int F_69 ( struct V_33 * V_34 )
{
if ( V_34 -> V_113 -> V_114 <= 1 )
F_70 () ;
F_71 ( V_34 ) ;
F_72 () ;
return F_73 ( V_34 ) ;
}
static int F_74 ( struct V_33 * V_34 , struct V_115 * V_53 )
{
struct V_116 V_117 = { NULL } ;
struct V_118 * V_119 ;
int V_37 ;
V_37 = F_75 () ;
if ( V_37 < 0 )
goto V_120;
V_37 = F_76 ( V_34 , V_53 ) ;
if ( V_37 )
goto V_121;
V_37 = F_58 ( NULL , V_34 ) ;
if ( V_37 ) {
F_2 ( L_30 ) ;
goto V_122;
}
F_77 ( & V_117 ) ;
F_78 ( V_34 , V_117 . V_123 , V_117 . V_124 ) ;
F_79 ( V_34 ) ;
if ( F_80 ( & V_112 ) == 1 ) {
V_86 = 0 ;
F_81 ( & V_100 ) ;
V_119 = F_82 ( F_49 , NULL , L_31 ) ;
if ( F_36 ( V_119 ) ) {
V_37 = F_37 ( V_119 ) ;
F_2 ( L_32 ,
V_34 -> V_49 , V_37 ) ;
goto V_122;
}
V_37 = 0 ;
F_67 ( & V_97 ) ;
}
return V_37 ;
V_122:
F_73 ( V_34 ) ;
V_121:
F_72 () ;
V_120:
return V_37 ;
}
static int F_83 ( struct V_125 * V_126 , struct V_127 * V_128 ,
void * V_71 , int V_129 )
{
struct V_130 V_131 ;
struct V_15 * V_16 = V_71 ;
int V_37 = 0 ;
switch ( V_129 ) {
case V_132 :
F_84 ( V_126 , L_33 ) ;
F_85 ( V_126 , & V_131 ) ;
V_37 = F_86 ( & V_131 , V_133 ) ;
break;
case V_134 :
F_84 ( V_126 , L_34 ) ;
F_5 ( V_11 , L_35 V_135 L_36 ,
F_87 ( V_126 -> V_136 ) ,
( char * ) & V_126 -> V_136 -> V_137 . V_1 [ 0 ] ) ;
if ( ! V_16 ) {
F_5 ( V_18 , L_37 ) ;
break;
}
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
if ( V_16 -> V_32 ) {
F_5 ( V_11 , L_38 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
if ( ! V_126 -> V_138 ||
! V_126 -> V_138 -> V_82 -> V_76 . V_77 . V_84 ) {
F_5 ( V_11 , L_39 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
F_56 ( V_16 ) ;
F_11 ( V_16 ) ;
break;
default:
F_4 () ;
}
return V_37 ;
}
static int F_88 ( struct V_139 * exp ,
struct V_140 * V_141 )
{
struct V_142 * V_143 ;
struct V_140 * V_144 , * V_145 ;
int V_37 ;
V_143 = F_89 ( F_90 ( exp ) ,
& V_146 , V_147 ,
V_148 ) ;
if ( ! V_143 )
return - V_39 ;
V_144 = F_91 ( & V_143 -> V_149 , & V_150 ) ;
if ( ! V_144 ) {
F_92 ( V_143 ) ;
return - V_39 ;
}
memcpy ( V_144 , V_141 , sizeof( * V_144 ) ) ;
F_93 ( V_143 ) ;
V_143 -> V_151 = V_152 ;
V_37 = F_94 ( V_143 ) ;
if ( ! V_37 ) {
V_145 = F_95 ( & V_143 -> V_149 , & V_150 ) ;
memcpy ( V_141 , V_145 , sizeof( * V_145 ) ) ;
}
F_92 ( V_143 ) ;
return V_37 ;
}
static int F_96 ( struct V_139 * exp , T_2 type ,
union V_153 * V_154 , T_2 V_155 ,
T_1 * V_156 , void * V_157 , void * V_158 , void * V_159 ,
void * V_71 , T_2 V_160 , void * V_161 ,
struct V_130 * V_131 )
{
struct V_15 * V_16 = V_71 ;
struct V_162 V_163 = {
. V_164 = type ,
. V_165 = V_155 ,
. V_166 = F_83 ,
. V_167 = V_168 ,
} ;
struct V_142 * V_143 ;
int V_169 = F_16 ( V_16 ) ;
int V_37 ;
F_5 ( V_11 , L_40 , V_16 -> V_19 ,
V_16 -> V_50 . V_1 [ 0 ] ) ;
V_143 = F_89 ( F_90 ( exp ) ,
& V_170 , V_171 ,
V_172 ) ;
if ( ! V_143 )
return - V_39 ;
F_97 ( & V_143 -> V_149 , & V_173 , V_174 , 0 ) ;
F_93 ( V_143 ) ;
V_143 -> V_151 = V_169 ? 5 : V_175 ;
V_37 = F_98 ( exp , & V_143 , & V_163 , & V_16 -> V_50 , NULL , V_156 ,
NULL , 0 , V_176 , V_131 , 0 ) ;
F_92 ( V_143 ) ;
return V_37 ;
}
static void F_99 ( struct V_33 * V_177 )
{
F_21 ( & V_20 ) ;
V_86 |= V_95 ;
F_15 ( & V_20 ) ;
F_57 ( & V_100 ) ;
}
static int F_100 ( struct V_139 * exp ,
struct V_178 * V_179 )
{
struct V_142 * V_143 ;
struct V_178 * V_180 , * V_181 ;
int V_37 ;
V_143 = F_89 ( F_90 ( exp ) ,
& V_182 , V_147 ,
V_183 ) ;
if ( ! V_143 )
return - V_39 ;
V_180 = F_91 ( & V_143 -> V_149 , & V_184 ) ;
if ( ! V_180 ) {
F_92 ( V_143 ) ;
return - V_39 ;
}
memcpy ( V_180 , V_179 , sizeof( * V_180 ) ) ;
F_93 ( V_143 ) ;
F_5 ( V_11 , L_41 , V_179 -> V_185 ) ;
V_143 -> V_151 = V_186 ;
V_37 = F_94 ( V_143 ) ;
if ( ! V_37 ) {
V_181 = F_95 ( & V_143 -> V_149 ,
& V_184 ) ;
memcpy ( V_179 , V_181 , sizeof( * V_181 ) ) ;
F_5 ( V_11 , L_42 ,
V_179 -> V_185 , V_179 -> V_187 ) ;
}
F_92 ( V_143 ) ;
return V_37 ;
}
static int F_101 ( const struct V_104 * V_105 , struct V_139 * exp ,
T_3 V_188 , void * V_189 , T_3 V_190 ,
void * V_191 , struct V_192 * V_193 )
{
int V_37 = - V_6 ;
if ( F_102 ( V_194 ) ) {
struct V_72 * V_73 = F_90 ( exp ) ;
int V_195 ;
if ( V_190 != sizeof( int ) )
return - V_6 ;
V_195 = * ( int * ) V_191 ;
F_5 ( V_11 , L_43 ,
V_73 -> V_196 -> V_49 , V_195 ,
V_73 -> V_197 , V_73 -> V_198 ,
V_73 -> V_199 , V_73 -> V_196 -> V_200 ,
F_103 ( V_73 -> V_201 ) ) ;
if ( ( V_73 -> V_201 != V_202 &&
V_73 -> V_201 != V_203 ) || V_195 > 1 )
F_104 ( V_73 ) ;
return 0 ;
}
if ( F_102 ( V_204 ) ) {
struct V_140 * V_141 ;
V_141 = V_191 ;
V_37 = F_88 ( exp , V_141 ) ;
return V_37 ;
}
if ( F_102 ( V_205 ) ) {
struct V_206 * V_77 = & exp -> V_82 -> V_76 . V_77 ;
struct V_207 V_208 ;
if ( V_190 == 0 ) {
if ( V_77 -> V_209 . V_210 != V_211 )
return 0 ;
V_191 = L_44 ;
V_190 = 4 ;
}
V_37 = F_105 ( V_191 , & V_208 ) ;
if ( V_37 ) {
F_2 ( L_45 ,
( char * ) V_191 ) ;
return V_37 ;
}
if ( V_77 -> V_209 . V_210 == V_211 ) {
V_77 -> V_209 = V_208 ;
} else if ( memcmp ( & V_77 -> V_209 , & V_208 ,
sizeof( V_208 ) ) != 0 ) {
char V_212 [ 20 ] ;
F_106 ( & V_77 -> V_209 ,
V_212 , sizeof( V_212 ) ) ;
F_107 ( L_46 ,
( char * ) V_191 , V_212 ) ;
V_37 = - V_213 ;
}
return V_37 ;
}
return V_37 ;
}
static int F_108 ( const struct V_104 * V_105 , struct V_139 * exp ,
T_2 V_188 , void * V_189 , T_2 * V_190 , void * V_191 )
{
int V_37 = - V_6 ;
if ( F_102 ( V_214 ) ) {
struct V_72 * V_73 = F_90 ( exp ) ;
struct V_74 * V_71 = V_191 ;
if ( * V_190 == sizeof( * V_71 ) ) {
* V_71 = V_73 -> V_79 ;
V_37 = 0 ;
}
}
return V_37 ;
}
static int F_109 ( struct V_33 * V_34 ,
struct V_72 * V_73 ,
enum V_215 V_216 )
{
F_12 ( V_73 -> V_196 == V_34 ) ;
F_5 ( V_11 , L_47 , V_216 ) ;
switch ( V_216 ) {
case V_217 :
if ( F_45 ( & V_73 -> V_79 , V_80 ) )
F_110 () ;
break;
case V_218 :
break;
case V_219 : {
struct V_220 * V_221 = V_34 -> V_222 ;
F_111 ( V_221 , V_223 ) ;
break;
}
case V_224 :
F_5 ( V_18 , L_48 , V_34 -> V_49 ) ;
V_34 -> V_225 = 0 ;
F_99 ( V_34 ) ;
if ( F_45 ( & V_73 -> V_79 , V_80 ) )
F_112 () ;
break;
case V_226 :
break;
case V_227 :
case V_228 :
break;
default:
F_2 ( L_49 , V_216 ) ;
F_4 () ;
}
return 0 ;
}
static int F_113 ( struct V_33 * V_229 ,
struct V_15 * V_16 ,
T_1 V_230 ,
void * V_71 , int V_231 , bool V_232 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_233 * V_234 ;
struct V_115 * V_53 ;
struct V_235 V_236 ;
T_4 V_237 = 0 ;
char * V_238 ;
char * V_239 ;
int V_240 ;
int V_241 ;
int V_37 = 0 ;
int V_242 = 0 ;
F_12 ( V_27 -> V_30 ) ;
F_12 ( V_27 -> V_45 == V_27 -> V_30 ) ;
V_238 = F_24 ( V_243 , V_244 ) ;
if ( ! V_238 )
return - V_39 ;
V_241 = snprintf ( V_238 , V_243 , L_50 , V_27 -> V_30 ) ;
if ( V_241 >= V_243 ) {
F_19 ( V_238 ) ;
return - V_245 ;
}
++ V_241 ;
V_239 = V_238 + V_241 ;
V_240 = V_243 - V_241 ;
while ( V_231 > 0 ) {
int V_246 = sizeof( * V_234 ) ;
int V_247 , V_248 ;
struct V_33 * V_34 ;
char * V_249 ;
char * V_250 ;
char * V_251 ;
char * V_252 ;
V_37 = - V_6 ;
if ( V_231 < sizeof( * V_234 ) )
break;
V_234 = ( F_114 ( V_234 ) ) ( V_71 + V_242 ) ;
if ( V_234 -> V_253 != 0 )
break;
if ( V_234 -> V_254 == 0 )
break;
if ( V_234 -> V_255 != sizeof( V_256 ) )
break;
V_246 += V_234 -> V_254 * V_234 -> V_255 ;
if ( V_231 < V_246 )
break;
if ( V_232 )
F_115 ( V_234 ) ;
if ( V_234 -> V_257 > V_243 ) {
F_2 ( L_51 , V_234 -> V_257 ) ;
break;
}
if ( V_234 -> V_257 < V_246 )
break;
V_242 += V_234 -> V_257 ;
V_231 -= V_234 -> V_257 ;
if ( V_231 < 0 )
break;
if ( V_234 -> V_258 > V_230 ) {
F_2 ( L_52 ,
V_234 -> V_258 , V_230 ) ;
break;
}
if ( V_237 >= V_234 -> V_258 ) {
F_2 ( L_53 ,
V_237 , V_234 -> V_258 ) ;
break;
}
V_237 = V_234 -> V_258 ;
V_247 = V_234 -> V_259 == V_260 ;
memset ( V_239 , 0 , V_240 ) ;
V_249 = V_239 ;
V_241 = 0 ;
strcpy ( V_249 , V_16 -> V_19 ) ;
V_250 = strrchr ( V_249 , '-' ) ;
if ( ! V_250 ) {
F_2 ( L_54 ,
V_229 -> V_49 , V_249 ) ;
break;
}
V_241 = V_250 - V_249 ;
V_249 [ V_241 ] = 0 ;
V_241 += sprintf ( V_249 + V_241 , L_55 ,
V_247 ? L_56 : L_57 , V_234 -> V_261 ) ;
V_250 = V_247 ? L_58 : L_59 ;
V_241 += sprintf ( V_249 + V_241 , L_60 , V_250 , V_238 ) ;
F_116 ( & V_236 , V_249 ) ;
V_34 = F_117 ( V_249 ) ;
if ( ! V_34 ) {
F_5 ( V_18 , L_61 ,
V_229 -> V_49 , V_249 ) ;
V_37 = 0 ;
continue;
}
++ V_241 ;
V_251 = V_239 + V_241 ;
V_241 += sprintf ( V_251 , L_62 , V_250 , L_63 ) ;
V_252 = V_239 + V_241 ;
F_118 ( & V_34 -> V_76 . V_77 . V_81 ) ;
if ( ! V_34 -> V_76 . V_77 . V_78 ) {
F_46 ( & V_34 -> V_76 . V_77 . V_81 ) ;
V_37 = 0 ;
continue;
}
V_37 = - V_52 ;
for ( V_248 = 0 ; V_248 < V_234 -> V_254 ; V_248 ++ ) {
V_37 = F_119 ( V_34 -> V_76 . V_77 . V_78 ,
V_234 -> V_76 . V_262 [ 0 ] ,
(struct V_263 * ) V_252 ) ;
if ( ! V_37 )
break;
}
F_46 ( & V_34 -> V_76 . V_77 . V_81 ) ;
if ( V_37 < 0 ) {
F_2 ( L_64 ,
F_120 ( V_234 -> V_76 . V_262 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_65 ,
V_252 , F_120 ( V_234 -> V_76 . V_262 [ 0 ] ) ) ;
V_241 += strlen ( V_252 ) ;
V_241 += sprintf ( V_239 + V_241 , L_66 , V_234 -> V_264 ) ;
F_12 ( V_241 < V_240 ) ;
F_121 ( & V_236 , 1 , V_251 ) ;
V_37 = - V_39 ;
V_53 = F_122 ( V_265 , & V_236 ) ;
if ( F_36 ( V_53 ) ) {
F_2 ( L_67 ) ;
break;
}
F_5 ( V_18 , L_68 ,
V_237 , V_230 , V_249 , V_251 ) ;
V_37 = F_123 ( V_53 ) ;
F_124 ( V_53 ) ;
if ( V_37 )
F_5 ( V_18 , L_69 ,
V_249 , V_37 ) ;
}
F_19 ( V_238 ) ;
return V_37 ;
}
static int F_125 ( struct V_33 * V_34 ,
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
bool V_232 ;
int V_248 ;
int V_275 ;
int V_37 ;
V_273 = V_276 ;
if ( V_27 -> V_43 == 0 )
V_273 = V_277 ;
V_272 = F_126 ( V_273 , sizeof( * V_272 ) , V_244 ) ;
if ( ! V_272 ) {
V_37 = - V_39 ;
goto V_278;
}
for ( V_248 = 0 ; V_248 < V_273 ; V_248 ++ ) {
V_272 [ V_248 ] = F_127 ( V_244 ) ;
if ( ! V_272 [ V_248 ] ) {
V_37 = - V_39 ;
goto V_278;
}
}
V_279:
F_12 ( F_128 ( V_16 ) ) ;
F_12 ( F_129 ( & V_16 -> V_42 ) ) ;
V_143 = F_130 ( F_90 ( V_16 -> V_25 ) ,
& V_280 ) ;
if ( ! V_143 ) {
V_37 = - V_39 ;
goto V_278;
}
V_37 = F_131 ( V_143 , V_147 , V_281 ) ;
if ( V_37 )
goto V_278;
V_267 = F_91 ( & V_143 -> V_149 , & V_282 ) ;
F_12 ( sizeof( V_267 -> V_283 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_132 ( V_267 -> V_283 , V_16 -> V_19 , sizeof( V_267 -> V_283 ) )
>= sizeof( V_267 -> V_283 ) ) {
V_37 = - V_245 ;
goto V_278;
}
V_267 -> V_284 = V_27 -> V_43 + 1 ;
V_267 -> V_285 = V_16 -> V_46 ;
V_267 -> V_286 = V_287 ;
V_267 -> V_288 = V_273 ;
V_128 = F_133 ( V_143 , V_273 , 1 ,
V_289 | V_290 ,
V_291 ,
& V_292 ) ;
if ( ! V_128 ) {
V_37 = - V_39 ;
goto V_278;
}
for ( V_248 = 0 ; V_248 < V_273 ; V_248 ++ )
V_128 -> V_293 -> V_294 ( V_128 , V_272 [ V_248 ] , 0 , V_243 ) ;
F_93 ( V_143 ) ;
V_37 = F_94 ( V_143 ) ;
if ( V_37 )
goto V_278;
V_269 = F_95 ( & V_143 -> V_149 , & V_295 ) ;
if ( V_269 -> V_296 < V_269 -> V_297 ) {
V_37 = - V_6 ;
goto V_278;
}
V_27 -> V_43 = V_269 -> V_297 ;
V_274 = V_269 -> V_297 == V_269 -> V_296 ;
F_5 ( V_18 , L_70 ,
V_269 -> V_297 , V_274 == false ) ;
V_275 = F_134 ( V_143 , V_143 -> V_298 , 0 ) ;
if ( V_275 < 0 ) {
V_37 = V_275 ;
goto V_278;
}
if ( V_275 > V_273 << V_287 ) {
V_37 = - V_6 ;
goto V_278;
}
if ( V_275 == 0 ) {
if ( ! V_274 )
V_37 = - V_6 ;
goto V_278;
}
V_232 = ! ! F_135 ( V_143 ) ;
#if F_136 ( 3 , 0 , 53 , 0 ) > V_299
if ( F_40 ( V_143 -> V_300 -> V_301 ) )
V_232 = ! V_232 ;
#endif
for ( V_248 = 0 ; V_248 < V_273 && V_275 > 0 ; V_248 ++ ) {
int V_302 ;
void * V_60 ;
V_60 = F_137 ( V_272 [ V_248 ] ) ;
V_302 = F_113 ( V_34 , V_16 , V_269 -> V_297 , V_60 ,
F_138 ( int , V_275 , V_243 ) ,
V_232 ) ;
F_139 ( V_272 [ V_248 ] ) ;
if ( V_302 < 0 ) {
F_140 ( L_71 ,
V_16 -> V_19 , V_302 ) ;
break;
}
V_275 -= V_243 ;
}
V_278:
if ( V_143 )
F_92 ( V_143 ) ;
if ( V_37 == 0 && ! V_274 )
goto V_279;
if ( V_272 ) {
for ( V_248 = 0 ; V_248 < V_273 ; V_248 ++ ) {
if ( ! V_272 [ V_248 ] )
break;
F_141 ( V_272 [ V_248 ] ) ;
}
F_19 ( V_272 ) ;
}
return V_37 ;
}
static int F_142 ( struct V_33 * V_229 ,
struct V_15 * V_16 , int V_303 )
{
struct V_106 * V_107 ;
struct V_55 * V_56 = NULL ;
int V_37 = 0 ;
bool V_304 = false ;
struct V_104 * V_105 ;
F_12 ( V_16 ) ;
F_12 ( F_129 ( & V_16 -> V_42 ) ) ;
if ( F_16 ( V_16 ) && V_303 )
return 0 ;
if ( V_16 -> V_31 . V_45 )
V_56 = F_35 ( V_16 -> V_31 . V_45 ) ;
V_105 = F_24 ( sizeof( * V_105 ) , V_244 ) ;
if ( ! V_105 )
return - V_39 ;
V_37 = F_143 ( V_105 , V_305 ) ;
if ( V_37 )
goto V_306;
V_107 = F_60 ( V_229 , V_109 ) ;
F_12 ( V_107 ) ;
if ( V_303 ) {
V_37 = - V_307 ;
goto V_308;
}
if ( F_16 ( V_16 ) ) {
F_144 ( V_16 -> V_19 ) ;
V_304 = true ;
}
V_37 = F_145 ( V_105 , V_107 , V_16 -> V_19 ,
& V_16 -> V_31 ) ;
V_308:
F_146 ( V_105 , V_107 ) ;
if ( V_304 ) {
F_12 ( F_16 ( V_16 ) ) ;
F_147 ( V_16 -> V_19 ) ;
F_148 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_11 ) ) ;
}
F_149 ( V_105 ) ;
V_306:
F_19 ( V_105 ) ;
return V_37 ;
}
static bool F_150 ( struct V_72 * V_73 )
{
bool V_309 = true ;
F_21 ( & V_73 -> V_310 ) ;
if ( V_73 -> V_201 == V_202 ||
V_73 -> V_201 == V_311 )
V_309 = false ;
F_15 ( & V_73 -> V_310 ) ;
return V_309 ;
}
int F_31 ( struct V_33 * V_229 , struct V_15 * V_16 )
{
struct V_130 V_131 = { 0 } ;
T_1 V_156 = V_312 ;
bool V_313 = false ;
int V_37 = 0 , V_314 ;
F_12 ( V_16 ) ;
V_315:
F_39 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_32 ) {
F_41 ( & V_16 -> V_42 ) ;
return 0 ;
}
F_151 ( V_316 , 20 ) ;
F_5 ( V_11 , L_72 , V_16 -> V_19 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_43 + 1 ) ;
V_314 = F_96 ( V_229 -> V_76 . V_77 . V_317 , V_318 , NULL ,
V_319 , & V_156 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_131 ) ;
if ( V_314 == 0 ) {
F_8 ( V_16 ) ;
V_37 = F_152 ( & V_131 , ( void * ) V_16 ) ;
F_12 ( V_37 == 0 ) ;
} else {
F_5 ( V_11 , L_73 , V_314 ) ;
if ( V_314 == - V_320 &&
F_10 ( & V_229 -> V_76 . V_77 . V_321 ) > 0 && ! V_313 ) {
int V_322 = F_153 ( V_323 ) ;
struct V_72 * V_73 ;
struct V_88 V_89 ;
F_41 ( & V_16 -> V_42 ) ;
V_73 = F_90 ( V_229 -> V_76 . V_77 . V_317 ) ;
F_154 ( V_73 ) ;
V_89 = F_53 ( V_322 , NULL , NULL ) ;
F_54 ( V_73 -> V_324 ,
! F_150 ( V_73 ) , & V_89 ) ;
if ( V_73 -> V_201 == V_202 ) {
V_313 = true ;
goto V_315;
} else {
F_39 ( & V_16 -> V_42 ) ;
V_16 -> V_102 = 1 ;
}
} else {
V_16 -> V_102 = 1 ;
}
F_8 ( V_16 ) ;
}
if ( F_128 ( V_16 ) ) {
V_37 = 0 ;
if ( ! V_314 ) {
V_37 = F_125 ( V_229 , V_16 ) ;
if ( V_37 ) {
F_2 ( L_74 ,
V_229 -> V_49 , V_16 -> V_19 , V_37 ) ;
V_37 = 0 ;
V_16 -> V_102 = 1 ;
}
}
} else {
V_37 = F_142 ( V_229 , V_16 , V_314 != 0 ) ;
}
F_5 ( V_11 , L_75 ,
V_229 -> V_49 , V_16 -> V_19 , V_37 ? L_76 : L_77 , V_37 ) ;
F_41 ( & V_16 -> V_42 ) ;
if ( ! V_314 )
F_155 ( & V_131 , V_319 ) ;
return V_37 ;
}
static int F_156 ( struct V_33 * V_34 , T_3 V_2 , void * V_239 )
{
struct V_115 * V_53 = V_239 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_37 = 0 ;
switch ( V_53 -> V_325 ) {
case V_326 : {
struct V_178 * V_179 ;
if ( F_157 ( V_53 , 1 ) !=
sizeof( struct V_178 ) ) {
V_37 = - V_6 ;
goto V_278;
}
V_179 = (struct V_178 * ) F_158 ( V_53 , 1 ) ;
F_5 ( V_11 , L_78 ,
V_179 -> V_185 , V_179 -> V_327 ) ;
V_37 = F_100 ( V_34 -> V_76 . V_77 . V_317 , V_179 ) ;
break;
}
case V_328 :
F_2 ( L_79 ) ;
V_37 = - V_329 ;
break;
case V_330 : {
V_37 = F_159 ( V_53 ) ;
break;
}
case V_331 : {
struct V_15 * V_16 ;
struct V_35 * V_36 ;
V_13 = F_160 ( V_53 , 1 ) ;
V_27 = (struct V_26 * ) F_158 ( V_53 , 2 ) ;
V_36 = * (struct V_35 * * ) F_158 ( V_53 , 3 ) ;
F_5 ( V_11 , L_80 , V_13 ,
V_27 -> V_43 ) ;
V_37 = F_34 ( V_34 , V_13 , V_27 , V_36 ) ;
if ( V_37 )
break;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( ! V_16 ) {
V_37 = - V_52 ;
break;
}
V_16 -> V_31 . V_44 |= V_332 ;
V_37 = F_31 ( V_34 , V_16 ) ;
if ( V_37 == 0 && V_16 -> V_22 ) {
if ( F_45 ( & V_34 -> V_76 . V_77 . V_78 ->
V_79 , V_80 ) ) {
V_37 = F_31 ( V_34 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_333 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_11 ( V_333 ) ;
}
if ( V_37 )
F_2 ( L_81 , V_37 ) ;
}
if ( V_37 == 0 && V_16 -> V_24 ) {
V_37 = F_31 ( V_34 , V_16 -> V_24 ) ;
if ( V_37 == - V_52 ) {
F_5 ( V_11 ,
L_82 ) ;
V_37 = 0 ;
}
if ( V_37 )
F_2 (
L_83 ,
V_34 -> V_49 , V_37 ) ;
}
F_11 ( V_16 ) ;
break;
}
case V_334 : {
V_13 = F_160 ( V_53 , 1 ) ;
if ( V_53 -> V_335 >= 2 )
V_27 = (struct V_26 * ) F_158 (
V_53 , 2 ) ;
V_37 = F_38 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_84 , V_53 -> V_325 ) ;
V_37 = - V_6 ;
goto V_278;
}
}
V_278:
return V_37 ;
}
static int T_5 F_161 ( void )
{
return F_162 ( & V_336 , NULL ,
V_337 , NULL ) ;
}
static void F_163 ( void )
{
F_164 ( V_337 ) ;
}
