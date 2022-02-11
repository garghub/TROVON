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
F_8 ( V_28 ) ;
break;
}
}
F_15 ( & V_20 ) ;
return V_28 ;
}
static
struct V_15 * F_23 ( struct V_32 * V_33 ,
char * V_13 ,
int type ,
struct V_26 * V_27 ,
struct V_34 * V_35 )
{
struct V_15 * V_16 ;
int V_36 ;
F_5 ( V_11 , L_6 , V_13 ,
V_27 ? V_27 -> V_30 : NULL ) ;
V_16 = F_24 ( sizeof( * V_16 ) + strlen ( V_13 ) + 1 , V_37 ) ;
if ( ! V_16 )
return F_25 ( - V_38 ) ;
V_36 = F_7 ( V_13 , & V_16 -> V_39 , type ) ;
if ( V_36 ) {
F_19 ( V_16 ) ;
return F_25 ( V_36 ) ;
}
strcpy ( V_16 -> V_19 , V_13 ) ;
if ( V_27 )
V_16 -> V_31 = * V_27 ;
else
V_16 -> V_31 . V_40 = V_41 ;
F_26 ( & V_16 -> V_42 ) ;
V_16 -> V_31 . V_43 = 0 ;
V_16 -> V_31 . V_44 = 0 ;
V_16 -> V_31 . V_45 = V_35 ;
V_16 -> V_46 = type ;
F_27 ( & V_16 -> V_17 , 1 ) ;
V_16 -> V_25 = F_28 ( V_33 -> V_47 ) ;
if ( F_16 ( V_16 ) ) {
F_29 ( V_13 ) ;
V_16 -> V_31 . V_48 = V_33 -> V_49 ;
}
F_21 ( & V_20 ) ;
F_30 ( & V_16 -> V_21 , & V_50 ) ;
F_15 ( & V_20 ) ;
if ( F_16 ( V_16 ) ) {
V_36 = F_31 ( V_33 , V_16 ) ;
if ( V_36 && V_36 != - V_51 )
F_2 ( L_7 , V_36 ) ;
}
return V_16 ;
}
static struct V_15 *
F_32 ( struct V_32 * V_33 , char * V_12 ,
struct V_26 * V_27 ,
struct V_34 * V_35 )
{
struct V_26 V_52 = * V_27 ;
struct V_15 * V_16 ;
char V_13 [ 32 ] ;
F_12 ( strlen ( V_12 ) < sizeof( V_13 ) / 2 ) ;
strcpy ( V_13 , V_12 ) ;
F_12 ( V_52 . V_30 ) ;
strcat ( V_13 , L_8 ) ;
V_16 = F_23 ( V_33 , V_13 , V_9 , & V_52 , V_35 ) ;
return V_16 ;
}
static struct V_15 *
F_33 ( struct V_32 * V_33 ,
struct V_26 * V_27 , struct V_34 * V_35 )
{
struct V_26 V_52 = * V_27 ;
struct V_15 * V_16 ;
V_52 . V_30 = V_35 ;
V_16 = F_23 ( V_33 , V_53 , V_10 ,
& V_52 , V_35 ) ;
return V_16 ;
}
static struct V_15 *
F_34 ( struct V_32 * V_33 , char * V_13 ,
struct V_26 * V_27 , struct V_34 * V_35 )
{
struct V_54 * V_55 = F_35 ( V_35 ) ;
struct V_15 * V_16 ;
struct V_15 * V_56 ;
struct V_15 * V_57 ;
bool V_58 = false ;
char V_59 [ 32 ] ;
char * V_60 ;
int V_36 ;
F_5 ( V_11 , L_9 , V_13 , V_27 -> V_30 ) ;
V_60 = strrchr ( V_13 , '-' ) ;
if ( ! V_60 || V_60 - V_13 > 8 ) {
F_2 ( L_10 , V_13 ) ;
return F_25 ( - V_6 ) ;
}
memcpy ( V_59 , V_13 , V_60 - V_13 ) ;
strcpy ( V_59 + ( V_60 - V_13 ) , L_11 ) ;
V_56 = F_20 ( V_59 , NULL ) ;
if ( ! V_56 ) {
V_56 = F_23 ( V_33 , V_59 ,
V_8 , NULL , NULL ) ;
if ( F_36 ( V_56 ) ) {
F_2 ( L_12 , V_59 ) ;
V_36 = F_37 ( V_56 ) ;
goto V_61;
}
}
V_57 = F_33 ( V_33 , V_27 , V_35 ) ;
if ( F_36 ( V_57 ) ) {
V_36 = F_37 ( V_57 ) ;
F_2 ( L_13 ,
V_33 -> V_49 , V_36 ) ;
goto V_62;
}
V_16 = F_23 ( V_33 , V_13 , V_7 , V_27 , V_35 ) ;
if ( F_36 ( V_16 ) ) {
F_2 ( L_14 , V_13 ) ;
V_36 = F_37 ( V_16 ) ;
goto V_63;
}
V_16 -> V_24 = V_56 ;
V_16 -> V_23 = V_57 ;
F_12 ( V_55 -> V_64 ) ;
if ( ! ( V_55 -> V_64 -> V_65 & V_66 ) ) {
struct V_15 * V_67 ;
V_60 = strrchr ( V_59 , '-' ) ;
if ( V_60 ) {
* V_60 = 0 ;
} else {
F_2 ( L_15 ,
V_33 -> V_49 , V_59 , - V_6 ) ;
F_11 ( V_16 ) ;
V_36 = - V_6 ;
goto V_68;
}
V_67 = F_32 ( V_33 , V_59 , V_27 , V_35 ) ;
if ( F_36 ( V_67 ) ) {
V_36 = F_37 ( V_67 ) ;
goto V_68;
}
F_38 ( & V_16 -> V_42 ) ;
V_58 = true ;
V_16 -> V_22 = V_67 ;
}
if ( ! V_58 )
F_38 ( & V_16 -> V_42 ) ;
V_16 -> V_23 = V_57 ;
V_16 -> V_24 = V_56 ;
F_39 ( & V_16 -> V_42 ) ;
return V_16 ;
V_68:
F_11 ( V_16 ) ;
V_63:
F_11 ( V_57 ) ;
V_62:
F_11 ( V_56 ) ;
V_61:
return F_25 ( V_36 ) ;
}
static inline void F_40 ( struct V_15 * V_16 )
{
F_38 ( & V_16 -> V_42 ) ;
F_21 ( & V_20 ) ;
V_16 -> V_69 = 1 ;
F_15 ( & V_20 ) ;
F_39 ( & V_16 -> V_42 ) ;
}
static int F_41 ( char * V_13 , struct V_26 * V_27 )
{
struct V_15 * V_16 ;
struct V_15 * V_24 = NULL ;
struct V_15 * V_23 = NULL ;
struct V_15 * V_22 = NULL ;
int V_36 = 0 ;
V_16 = F_20 ( V_13 , V_27 ) ;
if ( ! V_16 )
return - V_51 ;
F_38 ( & V_16 -> V_42 ) ;
if ( F_42 ( V_16 -> V_69 ) ) {
F_39 ( & V_16 -> V_42 ) ;
F_11 ( V_16 ) ;
return V_36 ;
}
F_21 ( & V_20 ) ;
V_16 -> V_69 = 1 ;
F_15 ( & V_20 ) ;
V_22 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
V_23 = V_16 -> V_23 ;
V_16 -> V_23 = NULL ;
V_24 = V_16 -> V_24 ;
V_16 -> V_24 = NULL ;
F_39 ( & V_16 -> V_42 ) ;
if ( V_22 ) {
F_40 ( V_22 ) ;
F_11 ( V_22 ) ;
}
if ( V_23 ) {
F_40 ( V_23 ) ;
F_11 ( V_23 ) ;
}
if ( V_24 )
F_11 ( V_24 ) ;
F_11 ( V_16 ) ;
F_11 ( V_16 ) ;
F_5 ( V_11 , L_16 , V_13 ? V_13 : L_17 ,
V_36 ) ;
return V_36 ;
}
int F_43 ( struct V_70 * V_71 , void * V_72 )
{
struct V_32 * V_33 = V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
struct V_15 * V_16 ;
int V_36 ;
V_36 = F_44 ( V_33 ) ;
if ( V_36 )
return V_36 ;
V_74 = V_33 -> V_77 . V_78 . V_79 ;
V_76 = & V_74 -> V_80 ;
F_45 ( V_71 , L_18 ,
F_46 ( V_76 , V_81 ) ? L_19 : L_20 ) ;
F_45 ( V_71 , L_21 ) ;
F_21 ( & V_20 ) ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( ! V_16 -> V_22 )
continue;
F_45 ( V_71 , L_22 ,
V_16 -> V_19 ,
V_16 -> V_22 -> V_31 . V_43 ) ;
}
F_15 ( & V_20 ) ;
F_47 ( & V_33 -> V_77 . V_78 . V_82 ) ;
return 0 ;
}
static void F_48 ( struct V_15 * V_16 )
{
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_49 ( & V_16 -> V_25 -> V_83 -> V_77 . V_78 . V_82 ,
V_84 ) ;
if ( V_16 -> V_25 -> V_83 -> V_77 . V_78 . V_85 != 0 ) {
int V_36 ;
F_5 ( V_11 , L_23 , V_16 -> V_19 ) ;
V_36 = F_31 ( V_16 -> V_25 -> V_83 , V_16 ) ;
if ( V_36 && V_36 != - V_51 )
F_2 ( L_24 , V_36 ) ;
} else {
F_5 ( V_11 , L_25 ,
V_16 -> V_19 ) ;
}
F_47 ( & V_16 -> V_25 -> V_83 -> V_77 . V_78 . V_82 ) ;
}
static int F_50 ( void * V_72 )
{
bool V_86 = true ;
F_5 ( V_11 , L_26 ) ;
F_21 ( & V_20 ) ;
V_87 |= V_88 ;
while ( ! ( V_87 & V_89 ) ) {
struct V_90 V_91 ;
struct V_15 * V_16 , * V_92 ;
int rand = F_51 () & V_93 ;
int V_94 ;
V_87 &= ~ ( V_95 | V_96 ) ;
F_15 ( & V_20 ) ;
if ( V_86 ) {
V_86 = false ;
F_52 ( & V_97 ) ;
}
V_94 = F_53 ( V_98 * V_99 ) ;
V_94 += F_53 ( rand * V_99 / 100 ) ;
V_91 = F_54 ( V_94 , NULL , NULL ) ;
F_55 ( V_100 , V_87 & ( V_89 | V_101 ) ,
& V_91 ) ;
V_92 = NULL ;
F_21 ( & V_20 ) ;
V_87 &= ~ V_101 ;
F_22 (cld, &config_llog_list, cld_list_chain) {
if ( ! V_16 -> V_102 || V_16 -> V_69 )
continue;
F_8 ( V_16 ) ;
V_16 -> V_102 = 0 ;
F_15 ( & V_20 ) ;
if ( V_92 )
F_11 ( V_92 ) ;
V_92 = V_16 ;
if ( F_56 ( ! ( V_87 & V_89 ) ) ) {
F_48 ( V_16 ) ;
F_21 ( & V_20 ) ;
} else {
F_21 ( & V_20 ) ;
break;
}
}
F_15 ( & V_20 ) ;
if ( V_92 )
F_11 ( V_92 ) ;
V_91 = (struct V_90 ) { 0 } ;
F_55 ( V_100 , V_87 & ( V_95 | V_89 ) ,
& V_91 ) ;
F_21 ( & V_20 ) ;
}
V_87 &= ~ V_88 ;
F_15 ( & V_20 ) ;
F_52 ( & V_103 ) ;
F_5 ( V_11 , L_27 ) ;
return 0 ;
}
static void F_57 ( struct V_15 * V_16 )
{
bool V_104 = false ;
F_5 ( V_18 , L_28 ,
V_16 -> V_19 , F_10 ( & V_16 -> V_17 ) ,
V_16 -> V_69 , V_87 ) ;
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
F_38 ( & V_16 -> V_42 ) ;
F_21 ( & V_20 ) ;
if ( ! ( V_87 & V_89 ) && ! V_16 -> V_69 && ! V_16 -> V_102 ) {
V_16 -> V_102 = 1 ;
V_87 |= V_95 ;
V_104 = true ;
}
F_15 ( & V_20 ) ;
F_39 ( & V_16 -> V_42 ) ;
if ( V_104 )
F_58 ( & V_100 ) ;
}
static int F_59 ( const struct V_105 * V_106 , struct V_32 * V_33 )
{
struct V_107 * V_108 ;
int V_36 ;
V_36 = F_60 ( V_106 , V_33 , & V_33 -> V_109 , V_110 , V_33 ,
& V_111 ) ;
if ( V_36 )
return V_36 ;
V_108 = F_61 ( V_33 , V_110 ) ;
F_12 ( V_108 ) ;
F_62 ( V_108 ) ;
F_63 ( V_108 ) ;
return 0 ;
}
static int F_64 ( const struct V_105 * V_106 , struct V_32 * V_33 )
{
struct V_107 * V_108 ;
V_108 = F_61 ( V_33 , V_110 ) ;
if ( V_108 )
F_65 ( V_106 , V_108 ) ;
return 0 ;
}
static int F_66 ( struct V_32 * V_33 )
{
int V_36 = 0 ;
int V_112 ;
if ( F_67 ( & V_113 ) ) {
F_12 ( V_87 & V_88 ) ;
V_112 = V_89 ;
} else {
V_112 = V_95 | V_101 ;
}
F_21 ( & V_20 ) ;
V_87 |= V_112 ;
F_15 ( & V_20 ) ;
F_58 ( & V_100 ) ;
if ( V_112 & V_89 )
F_68 ( & V_103 ) ;
F_69 ( V_33 ) ;
V_36 = F_64 ( NULL , V_33 ) ;
if ( V_36 )
F_2 ( L_29 ) ;
return V_36 ;
}
static int F_70 ( struct V_32 * V_33 )
{
if ( V_33 -> V_114 -> V_115 <= 1 )
F_71 () ;
F_72 ( V_33 ) ;
F_73 () ;
return F_74 ( V_33 ) ;
}
static int F_75 ( struct V_32 * V_33 , struct V_116 * V_52 )
{
struct V_117 V_118 = { NULL } ;
struct V_119 * V_120 ;
int V_36 ;
V_36 = F_76 () ;
if ( V_36 < 0 )
goto V_121;
V_36 = F_77 ( V_33 , V_52 ) ;
if ( V_36 )
goto V_122;
V_36 = F_59 ( NULL , V_33 ) ;
if ( V_36 ) {
F_2 ( L_30 ) ;
goto V_123;
}
F_78 ( & V_118 ) ;
F_79 ( V_33 , V_118 . V_124 , V_118 . V_125 ) ;
F_80 ( V_33 ) ;
if ( F_81 ( & V_113 ) == 1 ) {
V_87 = 0 ;
F_82 ( & V_100 ) ;
V_120 = F_83 ( F_50 , NULL , L_31 ) ;
if ( F_36 ( V_120 ) ) {
V_36 = F_37 ( V_120 ) ;
F_2 ( L_32 ,
V_33 -> V_49 , V_36 ) ;
goto V_123;
}
V_36 = 0 ;
F_68 ( & V_97 ) ;
}
return V_36 ;
V_123:
F_74 ( V_33 ) ;
V_122:
F_73 () ;
V_121:
return V_36 ;
}
static int F_84 ( struct V_126 * V_127 , struct V_128 * V_129 ,
void * V_72 , int V_130 )
{
struct V_131 V_132 ;
struct V_15 * V_16 = V_72 ;
int V_36 = 0 ;
switch ( V_130 ) {
case V_133 :
F_85 ( V_127 , L_33 ) ;
F_86 ( V_127 , & V_132 ) ;
V_36 = F_87 ( & V_132 , V_134 ) ;
break;
case V_135 :
F_85 ( V_127 , L_34 ) ;
F_5 ( V_11 , L_35 V_136 L_36 ,
F_88 ( V_127 -> V_137 ) ,
( char * ) & V_127 -> V_137 -> V_138 . V_1 [ 0 ] ) ;
if ( ! V_16 ) {
F_5 ( V_18 , L_37 ) ;
break;
}
F_12 ( F_10 ( & V_16 -> V_17 ) > 0 ) ;
V_127 -> V_139 = NULL ;
if ( V_16 -> V_69 ) {
F_5 ( V_11 , L_38 ,
V_16 -> V_19 ) ;
F_11 ( V_16 ) ;
break;
}
if ( ! V_127 -> V_140 ||
! V_127 -> V_140 -> V_83 -> V_77 . V_78 . V_85 ) {
F_5 ( V_11 , L_39 ,
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
return V_36 ;
}
static int F_89 ( struct V_141 * exp ,
struct V_142 * V_143 )
{
struct V_144 * V_145 ;
struct V_142 * V_146 , * V_147 ;
int V_36 ;
V_145 = F_90 ( F_91 ( exp ) ,
& V_148 , V_149 ,
V_150 ) ;
if ( ! V_145 )
return - V_38 ;
V_146 = F_92 ( & V_145 -> V_151 , & V_152 ) ;
if ( ! V_146 ) {
F_93 ( V_145 ) ;
return - V_38 ;
}
memcpy ( V_146 , V_143 , sizeof( * V_146 ) ) ;
F_94 ( V_145 ) ;
V_145 -> V_153 = V_154 ;
V_36 = F_95 ( V_145 ) ;
if ( ! V_36 ) {
V_147 = F_96 ( & V_145 -> V_151 , & V_152 ) ;
memcpy ( V_143 , V_147 , sizeof( * V_147 ) ) ;
}
F_93 ( V_145 ) ;
return V_36 ;
}
static int F_97 ( struct V_141 * exp , T_2 type ,
union V_155 * V_156 , T_2 V_157 ,
T_1 * V_158 , void * V_159 , void * V_160 , void * V_161 ,
void * V_72 , T_2 V_162 , void * V_163 ,
struct V_131 * V_132 )
{
struct V_15 * V_16 = V_72 ;
struct V_164 V_165 = {
. V_166 = type ,
. V_167 = V_157 ,
. V_168 = F_84 ,
. V_169 = V_170 ,
} ;
struct V_144 * V_145 ;
int V_171 = F_16 ( V_16 ) ;
int V_36 ;
F_5 ( V_11 , L_40 , V_16 -> V_19 ,
V_16 -> V_39 . V_1 [ 0 ] ) ;
V_145 = F_90 ( F_91 ( exp ) ,
& V_172 , V_173 ,
V_174 ) ;
if ( ! V_145 )
return - V_38 ;
F_98 ( & V_145 -> V_151 , & V_175 , V_176 , 0 ) ;
F_94 ( V_145 ) ;
V_145 -> V_153 = V_171 ? 5 : V_177 ;
V_36 = F_99 ( exp , & V_145 , & V_165 , & V_16 -> V_39 , NULL , V_158 ,
NULL , 0 , V_178 , V_132 , 0 ) ;
F_93 ( V_145 ) ;
return V_36 ;
}
static void F_100 ( struct V_32 * V_179 )
{
F_21 ( & V_20 ) ;
V_87 |= V_95 ;
F_15 ( & V_20 ) ;
F_58 ( & V_100 ) ;
}
static int F_101 ( struct V_141 * exp ,
struct V_180 * V_181 )
{
struct V_144 * V_145 ;
struct V_180 * V_182 , * V_183 ;
int V_36 ;
V_145 = F_90 ( F_91 ( exp ) ,
& V_184 , V_149 ,
V_185 ) ;
if ( ! V_145 )
return - V_38 ;
V_182 = F_92 ( & V_145 -> V_151 , & V_186 ) ;
if ( ! V_182 ) {
F_93 ( V_145 ) ;
return - V_38 ;
}
memcpy ( V_182 , V_181 , sizeof( * V_182 ) ) ;
F_94 ( V_145 ) ;
F_5 ( V_11 , L_41 , V_181 -> V_187 ) ;
V_145 -> V_153 = V_188 ;
V_36 = F_95 ( V_145 ) ;
if ( ! V_36 ) {
V_183 = F_96 ( & V_145 -> V_151 ,
& V_186 ) ;
memcpy ( V_181 , V_183 , sizeof( * V_183 ) ) ;
F_5 ( V_11 , L_42 ,
V_181 -> V_187 , V_181 -> V_189 ) ;
}
F_93 ( V_145 ) ;
return V_36 ;
}
static int F_102 ( const struct V_105 * V_106 , struct V_141 * exp ,
T_3 V_190 , void * V_191 , T_3 V_192 ,
void * V_193 , struct V_194 * V_195 )
{
int V_36 = - V_6 ;
if ( F_103 ( V_196 ) ) {
struct V_73 * V_74 = F_91 ( exp ) ;
int V_197 ;
if ( V_192 != sizeof( int ) )
return - V_6 ;
V_197 = * ( int * ) V_193 ;
F_5 ( V_11 , L_43 ,
V_74 -> V_198 -> V_49 , V_197 ,
V_74 -> V_199 , V_74 -> V_200 ,
V_74 -> V_201 , V_74 -> V_198 -> V_202 ,
F_104 ( V_74 -> V_203 ) ) ;
if ( ( V_74 -> V_203 != V_204 &&
V_74 -> V_203 != V_205 ) || V_197 > 1 )
F_105 ( V_74 ) ;
return 0 ;
}
if ( F_103 ( V_206 ) ) {
struct V_142 * V_143 ;
V_143 = V_193 ;
V_36 = F_89 ( exp , V_143 ) ;
return V_36 ;
}
if ( F_103 ( V_207 ) ) {
struct V_208 * V_78 = & exp -> V_83 -> V_77 . V_78 ;
struct V_209 V_210 ;
if ( V_192 == 0 ) {
if ( V_78 -> V_211 . V_212 != V_213 )
return 0 ;
V_193 = L_44 ;
V_192 = 4 ;
}
V_36 = F_106 ( V_193 , & V_210 ) ;
if ( V_36 ) {
F_2 ( L_45 ,
( char * ) V_193 ) ;
return V_36 ;
}
if ( V_78 -> V_211 . V_212 == V_213 ) {
V_78 -> V_211 = V_210 ;
} else if ( memcmp ( & V_78 -> V_211 , & V_210 ,
sizeof( V_210 ) ) != 0 ) {
char V_214 [ 20 ] ;
F_107 ( & V_78 -> V_211 ,
V_214 , sizeof( V_214 ) ) ;
F_108 ( L_46 ,
( char * ) V_193 , V_214 ) ;
V_36 = - V_215 ;
}
return V_36 ;
}
return V_36 ;
}
static int F_109 ( const struct V_105 * V_106 , struct V_141 * exp ,
T_2 V_190 , void * V_191 , T_2 * V_192 , void * V_193 )
{
int V_36 = - V_6 ;
if ( F_103 ( V_216 ) ) {
struct V_73 * V_74 = F_91 ( exp ) ;
struct V_75 * V_72 = V_193 ;
if ( * V_192 == sizeof( * V_72 ) ) {
* V_72 = V_74 -> V_80 ;
V_36 = 0 ;
}
}
return V_36 ;
}
static int F_110 ( struct V_32 * V_33 ,
struct V_73 * V_74 ,
enum V_217 V_218 )
{
F_12 ( V_74 -> V_198 == V_33 ) ;
F_5 ( V_11 , L_47 , V_218 ) ;
switch ( V_218 ) {
case V_219 :
if ( F_46 ( & V_74 -> V_80 , V_81 ) )
F_111 () ;
break;
case V_220 :
break;
case V_221 : {
struct V_222 * V_223 = V_33 -> V_224 ;
F_112 ( V_223 , V_225 ) ;
break;
}
case V_226 :
F_5 ( V_18 , L_48 , V_33 -> V_49 ) ;
V_33 -> V_227 = 0 ;
F_100 ( V_33 ) ;
if ( F_46 ( & V_74 -> V_80 , V_81 ) )
F_113 () ;
break;
case V_228 :
break;
case V_229 :
case V_230 :
break;
default:
F_2 ( L_49 , V_218 ) ;
F_4 () ;
}
return 0 ;
}
static int F_114 ( struct V_32 * V_231 ,
struct V_15 * V_16 ,
T_1 V_232 ,
void * V_72 , int V_233 , bool V_234 )
{
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_235 * V_236 ;
struct V_116 * V_52 ;
struct V_237 V_238 ;
T_4 V_239 = 0 ;
char * V_240 ;
char * V_241 ;
int V_242 ;
int V_243 ;
int V_36 = 0 ;
int V_244 = 0 ;
F_12 ( V_27 -> V_30 ) ;
F_12 ( V_27 -> V_45 == V_27 -> V_30 ) ;
V_240 = F_24 ( V_245 , V_246 ) ;
if ( ! V_240 )
return - V_38 ;
V_243 = snprintf ( V_240 , V_245 , L_50 , V_27 -> V_30 ) ;
if ( V_243 >= V_245 ) {
F_19 ( V_240 ) ;
return - V_247 ;
}
++ V_243 ;
V_241 = V_240 + V_243 ;
V_242 = V_245 - V_243 ;
while ( V_233 > 0 ) {
int V_248 = sizeof( * V_236 ) ;
int V_249 , V_250 ;
struct V_32 * V_33 ;
char * V_251 ;
char * V_252 ;
char * V_253 ;
char * V_254 ;
V_36 = - V_6 ;
if ( V_233 < sizeof( * V_236 ) )
break;
V_236 = ( F_115 ( V_236 ) ) ( V_72 + V_244 ) ;
if ( V_236 -> V_255 != 0 )
break;
if ( V_236 -> V_256 == 0 )
break;
if ( V_236 -> V_257 != sizeof( V_258 ) )
break;
V_248 += V_236 -> V_256 * V_236 -> V_257 ;
if ( V_233 < V_248 )
break;
if ( V_234 )
F_116 ( V_236 ) ;
if ( V_236 -> V_259 > V_245 ) {
F_2 ( L_51 , V_236 -> V_259 ) ;
break;
}
if ( V_236 -> V_259 < V_248 )
break;
V_244 += V_236 -> V_259 ;
V_233 -= V_236 -> V_259 ;
if ( V_233 < 0 )
break;
if ( V_236 -> V_260 > V_232 ) {
F_2 ( L_52 ,
V_236 -> V_260 , V_232 ) ;
break;
}
if ( V_239 >= V_236 -> V_260 ) {
F_2 ( L_53 ,
V_239 , V_236 -> V_260 ) ;
break;
}
V_239 = V_236 -> V_260 ;
V_249 = V_236 -> V_261 == V_262 ;
memset ( V_241 , 0 , V_242 ) ;
V_251 = V_241 ;
V_243 = 0 ;
strcpy ( V_251 , V_16 -> V_19 ) ;
V_252 = strrchr ( V_251 , '-' ) ;
if ( ! V_252 ) {
F_2 ( L_54 ,
V_231 -> V_49 , V_251 ) ;
break;
}
V_243 = V_252 - V_251 ;
V_251 [ V_243 ] = 0 ;
V_243 += sprintf ( V_251 + V_243 , L_55 ,
V_249 ? L_56 : L_57 , V_236 -> V_263 ) ;
V_252 = V_249 ? L_58 : L_59 ;
V_243 += sprintf ( V_251 + V_243 , L_60 , V_252 , V_240 ) ;
F_117 ( & V_238 , V_251 ) ;
V_33 = F_118 ( V_251 ) ;
if ( ! V_33 ) {
F_5 ( V_18 , L_61 ,
V_231 -> V_49 , V_251 ) ;
V_36 = 0 ;
continue;
}
++ V_243 ;
V_253 = V_241 + V_243 ;
V_243 += sprintf ( V_253 , L_62 , V_252 , L_63 ) ;
V_254 = V_241 + V_243 ;
F_119 ( & V_33 -> V_77 . V_78 . V_82 ) ;
if ( ! V_33 -> V_77 . V_78 . V_79 ) {
F_47 ( & V_33 -> V_77 . V_78 . V_82 ) ;
V_36 = 0 ;
continue;
}
V_36 = - V_51 ;
for ( V_250 = 0 ; V_250 < V_236 -> V_256 ; V_250 ++ ) {
V_36 = F_120 ( V_33 -> V_77 . V_78 . V_79 ,
V_236 -> V_77 . V_264 [ 0 ] ,
(struct V_265 * ) V_254 ) ;
if ( ! V_36 )
break;
}
F_47 ( & V_33 -> V_77 . V_78 . V_82 ) ;
if ( V_36 < 0 ) {
F_2 ( L_64 ,
F_121 ( V_236 -> V_77 . V_264 [ 0 ] ) ) ;
break;
}
F_5 ( V_18 , L_65 ,
V_254 , F_121 ( V_236 -> V_77 . V_264 [ 0 ] ) ) ;
V_243 += strlen ( V_254 ) ;
V_243 += sprintf ( V_241 + V_243 , L_66 , V_236 -> V_266 ) ;
F_12 ( V_243 < V_242 ) ;
F_122 ( & V_238 , 1 , V_253 ) ;
V_36 = - V_38 ;
V_52 = F_123 ( V_267 , & V_238 ) ;
if ( F_36 ( V_52 ) ) {
F_2 ( L_67 ) ;
break;
}
F_5 ( V_18 , L_68 ,
V_239 , V_232 , V_251 , V_253 ) ;
V_36 = F_124 ( V_52 ) ;
F_125 ( V_52 ) ;
if ( V_36 )
F_5 ( V_18 , L_69 ,
V_251 , V_36 ) ;
}
F_19 ( V_240 ) ;
return V_36 ;
}
static int F_126 ( struct V_32 * V_33 ,
struct V_15 * V_16 )
{
struct V_144 * V_145 = NULL ;
struct V_26 * V_27 = & V_16 -> V_31 ;
struct V_268 * V_269 ;
struct V_270 * V_271 ;
struct V_272 * V_129 ;
struct V_273 * * V_274 ;
int V_275 ;
bool V_276 = true ;
bool V_234 ;
int V_250 ;
int V_277 ;
int V_36 ;
V_275 = V_278 ;
if ( V_27 -> V_43 == 0 )
V_275 = V_279 ;
V_274 = F_127 ( V_275 , sizeof( * V_274 ) , V_246 ) ;
if ( ! V_274 ) {
V_36 = - V_38 ;
goto V_280;
}
for ( V_250 = 0 ; V_250 < V_275 ; V_250 ++ ) {
V_274 [ V_250 ] = F_128 ( V_246 ) ;
if ( ! V_274 [ V_250 ] ) {
V_36 = - V_38 ;
goto V_280;
}
}
V_281:
F_12 ( F_129 ( V_16 ) ) ;
F_12 ( F_130 ( & V_16 -> V_42 ) ) ;
V_145 = F_131 ( F_91 ( V_16 -> V_25 ) ,
& V_282 ) ;
if ( ! V_145 ) {
V_36 = - V_38 ;
goto V_280;
}
V_36 = F_132 ( V_145 , V_149 , V_283 ) ;
if ( V_36 )
goto V_280;
V_269 = F_92 ( & V_145 -> V_151 , & V_284 ) ;
F_12 ( sizeof( V_269 -> V_285 ) > strlen ( V_16 -> V_19 ) ) ;
if ( F_133 ( V_269 -> V_285 , V_16 -> V_19 , sizeof( V_269 -> V_285 ) )
>= sizeof( V_269 -> V_285 ) ) {
V_36 = - V_247 ;
goto V_280;
}
V_269 -> V_286 = V_27 -> V_43 + 1 ;
V_269 -> V_287 = V_16 -> V_46 ;
V_269 -> V_288 = V_289 ;
V_269 -> V_290 = V_275 ;
V_129 = F_134 ( V_145 , V_275 , 1 ,
V_291 | V_292 ,
V_293 ,
& V_294 ) ;
if ( ! V_129 ) {
V_36 = - V_38 ;
goto V_280;
}
for ( V_250 = 0 ; V_250 < V_275 ; V_250 ++ )
V_129 -> V_295 -> V_296 ( V_129 , V_274 [ V_250 ] , 0 , V_245 ) ;
F_94 ( V_145 ) ;
V_36 = F_95 ( V_145 ) ;
if ( V_36 )
goto V_280;
V_271 = F_96 ( & V_145 -> V_151 , & V_297 ) ;
if ( V_271 -> V_298 < V_271 -> V_299 ) {
V_36 = - V_6 ;
goto V_280;
}
V_27 -> V_43 = V_271 -> V_299 ;
V_276 = V_271 -> V_299 == V_271 -> V_298 ;
F_5 ( V_18 , L_70 ,
V_271 -> V_299 , V_276 == false ) ;
V_277 = F_135 ( V_145 , V_145 -> V_300 , 0 ) ;
if ( V_277 < 0 ) {
V_36 = V_277 ;
goto V_280;
}
if ( V_277 > V_275 << V_289 ) {
V_36 = - V_6 ;
goto V_280;
}
if ( V_277 == 0 ) {
if ( ! V_276 )
V_36 = - V_6 ;
goto V_280;
}
V_234 = ! ! F_136 ( V_145 ) ;
#if F_137 ( 3 , 0 , 53 , 0 ) > V_301
if ( F_42 ( V_145 -> V_302 -> V_303 ) )
V_234 = ! V_234 ;
#endif
for ( V_250 = 0 ; V_250 < V_275 && V_277 > 0 ; V_250 ++ ) {
int V_304 ;
void * V_60 ;
V_60 = F_138 ( V_274 [ V_250 ] ) ;
V_304 = F_114 ( V_33 , V_16 , V_271 -> V_299 , V_60 ,
F_139 ( int , V_277 , V_245 ) ,
V_234 ) ;
F_140 ( V_274 [ V_250 ] ) ;
if ( V_304 < 0 ) {
F_141 ( L_71 ,
V_16 -> V_19 , V_304 ) ;
break;
}
V_277 -= V_245 ;
}
V_280:
if ( V_145 )
F_93 ( V_145 ) ;
if ( V_36 == 0 && ! V_276 )
goto V_281;
if ( V_274 ) {
for ( V_250 = 0 ; V_250 < V_275 ; V_250 ++ ) {
if ( ! V_274 [ V_250 ] )
break;
F_142 ( V_274 [ V_250 ] ) ;
}
F_19 ( V_274 ) ;
}
return V_36 ;
}
static int F_143 ( struct V_32 * V_231 ,
struct V_15 * V_16 , int V_305 )
{
struct V_107 * V_108 ;
struct V_54 * V_55 = NULL ;
int V_36 = 0 ;
bool V_306 = false ;
struct V_105 * V_106 ;
F_12 ( V_16 ) ;
F_12 ( F_130 ( & V_16 -> V_42 ) ) ;
if ( F_16 ( V_16 ) && V_305 )
return 0 ;
if ( V_16 -> V_31 . V_45 )
V_55 = F_35 ( V_16 -> V_31 . V_45 ) ;
V_106 = F_24 ( sizeof( * V_106 ) , V_246 ) ;
if ( ! V_106 )
return - V_38 ;
V_36 = F_144 ( V_106 , V_307 ) ;
if ( V_36 )
goto V_308;
V_108 = F_61 ( V_231 , V_110 ) ;
F_12 ( V_108 ) ;
if ( V_305 ) {
V_36 = - V_309 ;
goto V_310;
}
if ( F_16 ( V_16 ) ) {
F_145 ( V_16 -> V_19 ) ;
V_306 = true ;
}
V_36 = F_146 ( V_106 , V_108 , V_16 -> V_19 ,
& V_16 -> V_31 ) ;
V_310:
F_147 ( V_106 , V_108 ) ;
if ( V_306 ) {
F_12 ( F_16 ( V_16 ) ) ;
F_148 ( V_16 -> V_19 ) ;
F_149 ( V_16 -> V_19 ,
strlen ( V_16 -> V_19 ) -
strlen ( L_11 ) ) ;
}
F_150 ( V_106 ) ;
V_308:
F_19 ( V_106 ) ;
return V_36 ;
}
static bool F_151 ( struct V_73 * V_74 )
{
bool V_311 = true ;
F_21 ( & V_74 -> V_312 ) ;
if ( V_74 -> V_203 == V_204 ||
V_74 -> V_203 == V_313 )
V_311 = false ;
F_15 ( & V_74 -> V_312 ) ;
return V_311 ;
}
int F_31 ( struct V_32 * V_231 , struct V_15 * V_16 )
{
struct V_131 V_132 = { 0 } ;
T_1 V_158 = V_314 ;
bool V_315 = false ;
int V_36 = 0 , V_316 ;
F_12 ( V_16 ) ;
V_317:
F_38 ( & V_16 -> V_42 ) ;
if ( V_16 -> V_69 ) {
F_39 ( & V_16 -> V_42 ) ;
return 0 ;
}
F_152 ( V_318 , 20 ) ;
F_5 ( V_11 , L_72 , V_16 -> V_19 ,
V_16 -> V_31 . V_30 , V_16 -> V_31 . V_43 + 1 ) ;
V_316 = F_97 ( V_231 -> V_77 . V_78 . V_319 , V_320 , NULL ,
V_321 , & V_158 , NULL , NULL , NULL ,
V_16 , 0 , NULL , & V_132 ) ;
if ( V_316 == 0 ) {
F_8 ( V_16 ) ;
V_36 = F_153 ( & V_132 , ( void * ) V_16 ) ;
F_12 ( V_36 == 0 ) ;
} else {
F_5 ( V_11 , L_73 , V_316 ) ;
if ( V_316 == - V_322 &&
F_10 ( & V_231 -> V_77 . V_78 . V_323 ) > 0 && ! V_315 ) {
int V_324 = F_154 ( V_325 ) ;
struct V_73 * V_74 ;
struct V_90 V_91 ;
F_39 ( & V_16 -> V_42 ) ;
V_74 = F_91 ( V_231 -> V_77 . V_78 . V_319 ) ;
F_155 ( V_74 ) ;
V_91 = F_54 ( V_324 , NULL , NULL ) ;
F_55 ( V_74 -> V_326 ,
! F_151 ( V_74 ) , & V_91 ) ;
if ( V_74 -> V_203 == V_204 ) {
V_315 = true ;
goto V_317;
} else {
F_38 ( & V_16 -> V_42 ) ;
F_21 ( & V_20 ) ;
V_16 -> V_102 = 1 ;
F_15 ( & V_20 ) ;
}
} else {
F_21 ( & V_20 ) ;
V_16 -> V_102 = 1 ;
F_15 ( & V_20 ) ;
}
}
if ( F_129 ( V_16 ) ) {
V_36 = 0 ;
if ( ! V_316 ) {
V_36 = F_126 ( V_231 , V_16 ) ;
if ( V_36 ) {
F_2 ( L_74 ,
V_231 -> V_49 , V_16 -> V_19 , V_36 ) ;
V_36 = 0 ;
F_21 ( & V_20 ) ;
V_16 -> V_102 = 1 ;
F_15 ( & V_20 ) ;
}
}
} else {
V_36 = F_143 ( V_231 , V_16 , V_316 != 0 ) ;
}
F_5 ( V_11 , L_75 ,
V_231 -> V_49 , V_16 -> V_19 , V_36 ? L_76 : L_77 , V_36 ) ;
F_39 ( & V_16 -> V_42 ) ;
if ( ! V_316 )
F_156 ( & V_132 , V_321 ) ;
return V_36 ;
}
static int F_157 ( struct V_32 * V_33 , T_3 V_2 , void * V_241 )
{
struct V_116 * V_52 = V_241 ;
struct V_26 * V_27 = NULL ;
char * V_13 ;
int V_36 = 0 ;
switch ( V_52 -> V_327 ) {
case V_328 : {
struct V_180 * V_181 ;
if ( F_158 ( V_52 , 1 ) !=
sizeof( struct V_180 ) ) {
V_36 = - V_6 ;
goto V_280;
}
V_181 = (struct V_180 * ) F_159 ( V_52 , 1 ) ;
F_5 ( V_11 , L_78 ,
V_181 -> V_187 , V_181 -> V_329 ) ;
V_36 = F_101 ( V_33 -> V_77 . V_78 . V_319 , V_181 ) ;
break;
}
case V_330 :
F_2 ( L_79 ) ;
V_36 = - V_331 ;
break;
case V_332 : {
V_36 = F_160 ( V_52 ) ;
break;
}
case V_333 : {
struct V_15 * V_16 ;
struct V_34 * V_35 ;
V_13 = F_161 ( V_52 , 1 ) ;
V_27 = (struct V_26 * ) F_159 ( V_52 , 2 ) ;
V_35 = * (struct V_34 * * ) F_159 ( V_52 , 3 ) ;
F_5 ( V_11 , L_80 , V_13 ,
V_27 -> V_43 ) ;
V_16 = F_34 ( V_33 , V_13 , V_27 , V_35 ) ;
if ( F_36 ( V_16 ) ) {
V_36 = F_37 ( V_16 ) ;
break;
}
V_16 -> V_31 . V_44 |= V_334 ;
V_36 = F_31 ( V_33 , V_16 ) ;
if ( V_36 == 0 && V_16 -> V_22 ) {
if ( F_46 ( & V_33 -> V_77 . V_78 . V_79 ->
V_80 , V_81 ) ) {
V_36 = F_31 ( V_33 , V_16 -> V_22 ) ;
} else {
struct V_15 * V_335 ;
F_38 ( & V_16 -> V_42 ) ;
V_335 = V_16 -> V_22 ;
V_16 -> V_22 = NULL ;
F_39 ( & V_16 -> V_42 ) ;
F_11 ( V_335 ) ;
}
if ( V_36 )
F_2 ( L_81 , V_36 ) ;
}
if ( V_36 == 0 && V_16 -> V_23 ) {
V_36 = F_31 ( V_33 , V_16 -> V_23 ) ;
if ( V_36 == - V_51 ) {
F_5 ( V_11 ,
L_82 ) ;
V_36 = 0 ;
}
if ( V_36 )
F_2 (
L_83 ,
V_33 -> V_49 , V_36 ) ;
}
break;
}
case V_336 : {
V_13 = F_161 ( V_52 , 1 ) ;
if ( V_52 -> V_337 >= 2 )
V_27 = (struct V_26 * ) F_159 (
V_52 , 2 ) ;
V_36 = F_41 ( V_13 , V_27 ) ;
break;
}
default: {
F_2 ( L_84 , V_52 -> V_327 ) ;
V_36 = - V_6 ;
goto V_280;
}
}
V_280:
return V_36 ;
}
static int T_5 F_162 ( void )
{
return F_163 ( & V_338 , NULL ,
V_339 , NULL ) ;
}
static void F_164 ( void )
{
F_165 ( V_339 ) ;
}
