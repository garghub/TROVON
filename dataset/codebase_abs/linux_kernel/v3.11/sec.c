int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ;
F_2 ( V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_7 ) ;
if ( V_3 >= V_8 )
return - V_9 ;
F_3 ( & V_10 ) ;
if ( F_4 ( V_11 [ V_3 ] ) ) {
F_5 ( & V_10 ) ;
return - V_12 ;
}
V_11 [ V_3 ] = V_2 ;
F_5 ( & V_10 ) ;
F_6 ( V_13 , L_1 , V_2 -> V_5 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ;
F_2 ( V_3 < V_8 ) ;
F_3 ( & V_10 ) ;
if ( F_4 ( V_11 [ V_3 ] == NULL ) ) {
F_5 ( & V_10 ) ;
F_8 ( L_2 , V_2 -> V_5 ) ;
return - V_9 ;
}
F_2 ( V_11 [ V_3 ] == V_2 ) ;
V_11 [ V_3 ] = NULL ;
F_5 ( & V_10 ) ;
F_6 ( V_13 , L_3 , V_2 -> V_5 ) ;
return 0 ;
}
static
struct V_1 * F_9 ( T_2 V_14 )
{
static F_10 ( V_15 ) ;
static T_3 V_16 = F_11 ( 0 ) ;
struct V_1 * V_2 ;
T_1 V_3 = F_12 ( V_14 ) ;
T_1 V_17 = 0 ;
if ( V_3 >= V_8 )
return NULL ;
while ( 1 ) {
F_13 ( & V_10 ) ;
V_2 = V_11 [ V_3 ] ;
if ( V_2 && ! F_14 ( V_2 -> V_18 ) )
V_2 = NULL ;
if ( V_2 == NULL )
V_17 = F_15 ( & V_16 ) ;
F_16 ( & V_10 ) ;
if ( V_2 != NULL || V_17 != 0 ||
V_3 != V_19 )
break;
F_17 ( & V_15 ) ;
if ( F_15 ( & V_16 ) == 0 ) {
if ( F_18 ( L_4 ) == 0 )
F_6 ( V_13 ,
L_5 ) ;
else
F_8 ( L_6 ) ;
F_19 ( & V_16 , 1 ) ;
}
F_20 ( & V_15 ) ;
}
return V_2 ;
}
T_2 F_21 ( const char * V_20 )
{
if ( ! strcmp ( V_20 , L_7 ) )
return V_21 ;
if ( ! strcmp ( V_20 , L_8 ) )
return V_22 ;
if ( ! strcmp ( V_20 , L_9 ) )
return V_23 ;
if ( ! strcmp ( V_20 , L_10 ) )
return V_24 ;
if ( ! strcmp ( V_20 , L_11 ) )
return V_25 ;
if ( ! strcmp ( V_20 , L_12 ) )
return V_26 ;
return V_27 ;
}
const char * F_22 ( T_2 V_28 )
{
T_2 V_29 = F_23 ( V_28 ) ;
if ( V_29 == F_23 ( V_21 ) )
return L_7 ;
else if ( V_29 == F_23 ( V_22 ) )
return L_8 ;
else if ( V_29 == F_23 ( V_23 ) )
return L_9 ;
else if ( V_29 == F_23 ( V_24 ) )
return L_10 ;
else if ( V_29 == F_23 ( V_25 ) )
return L_11 ;
else if ( V_29 == F_23 ( V_26 ) )
return L_12 ;
F_8 ( L_13 , V_28 ) ;
return L_14 ;
}
char * F_24 ( struct V_30 * V_31 ,
char * V_32 , int V_33 )
{
if ( F_12 ( V_31 -> V_34 ) == V_35 )
snprintf ( V_32 , V_33 , L_15 ,
F_25 ( V_31 -> V_36 . V_37 . V_38 ) ) ;
else
snprintf ( V_32 , V_33 , L_16 ,
F_22 ( V_31 -> V_34 ) ) ;
V_32 [ V_33 - 1 ] = '\0' ;
return V_32 ;
}
char * F_26 ( struct V_30 * V_31 , char * V_32 , int V_33 )
{
snprintf ( V_32 , V_33 , L_16 , F_22 ( V_31 -> V_34 ) ) ;
if ( F_12 ( V_31 -> V_34 ) == V_35 ) {
char V_39 [ 16 ] ;
V_39 [ 0 ] = '-' ;
F_24 ( V_31 , & V_39 [ 1 ] , sizeof( V_39 ) - 1 ) ;
strncat ( V_32 , V_39 , V_33 ) ;
}
V_32 [ V_33 - 1 ] = '\0' ;
return V_32 ;
}
char * F_27 ( T_2 V_40 , char * V_32 , int V_33 )
{
V_32 [ 0 ] = '\0' ;
if ( V_40 & V_41 )
F_28 ( V_32 , L_17 , V_33 ) ;
if ( V_40 & V_42 )
F_28 ( V_32 , L_18 , V_33 ) ;
if ( V_40 & V_43 )
F_28 ( V_32 , L_19 , V_33 ) ;
if ( V_40 & V_44 )
F_28 ( V_32 , L_20 , V_33 ) ;
if ( V_32 [ 0 ] == '\0' )
F_28 ( V_32 , L_21 , V_33 ) ;
return V_32 ;
}
static
struct V_45 * F_29 ( struct V_46 * V_47 )
{
struct V_48 V_49 ;
int V_50 = 1 , V_51 = 1 ;
F_2 ( V_47 ) ;
F_2 ( V_47 -> V_52 -> V_6 -> V_53 ) ;
if ( V_47 -> V_54 . V_55 & ( V_41 |
V_42 ) ) {
V_49 . V_56 = 0 ;
V_49 . V_57 = 0 ;
if ( V_47 -> V_54 . V_55 & V_41 ) {
V_50 = 0 ;
V_51 = 0 ;
}
} else {
V_49 . V_56 = F_30 () ;
V_49 . V_57 = F_31 () ;
}
return V_47 -> V_52 -> V_6 -> V_53 ( V_47 , & V_49 ,
V_50 , V_51 ) ;
}
struct V_45 * F_32 ( struct V_45 * V_58 )
{
F_33 ( & V_58 -> V_59 ) ;
return V_58 ;
}
void F_34 ( struct V_45 * V_58 , int V_60 )
{
struct V_46 * V_47 = V_58 -> V_61 ;
F_2 ( V_47 ) ;
F_35 ( & V_58 -> V_59 ) ;
if ( ! F_36 ( & V_58 -> V_59 ) )
return;
V_47 -> V_52 -> V_6 -> V_62 ( V_47 , V_58 , V_60 ) ;
}
void F_37 ( struct V_45 * V_58 )
{
F_2 ( V_58 -> V_63 -> V_64 ) ;
V_58 -> V_63 -> V_64 ( V_58 , 0 ) ;
}
void F_38 ( struct V_45 * V_58 )
{
struct V_65 * V_66 , * V_67 ;
F_39 ( & V_58 -> V_68 ) ;
F_40 (req, next, &ctx->cc_req_list,
rq_ctx_chain) {
F_41 ( & V_66 -> V_69 ) ;
F_42 ( V_66 ) ;
}
F_43 ( & V_58 -> V_68 ) ;
}
int F_44 ( struct V_45 * V_58 , char * V_32 , int V_33 )
{
F_2 ( V_58 -> V_63 ) ;
if ( V_58 -> V_63 -> V_70 == NULL )
return 0 ;
return V_58 -> V_63 -> V_70 ( V_58 , V_32 , V_33 ) ;
}
static int F_45 ( struct V_71 * V_72 )
{
int V_73 = 0 ;
F_39 ( & V_72 -> V_74 ) ;
if ( V_72 -> V_75 &&
V_72 -> V_75 < F_46 () ) {
V_73 = 1 ;
V_72 -> V_75 = 0 ;
}
F_43 ( & V_72 -> V_74 ) ;
if ( ! V_73 )
return 0 ;
F_6 ( V_13 , L_22 ) ;
return F_47 ( V_72 , NULL , 0 ) ;
}
static int F_48 ( struct V_71 * V_72 ,
struct V_46 * * V_47 )
{
int V_76 ;
if ( F_4 ( V_72 -> V_75 ) ) {
V_76 = F_45 ( V_72 ) ;
if ( V_76 )
return V_76 ;
}
* V_47 = F_49 ( V_72 ) ;
if ( * V_47 == NULL ) {
F_8 ( L_23 ,
V_72 , F_50 ( V_72 -> V_77 ) ) ;
return - V_78 ;
}
if ( F_4 ( ( * V_47 ) -> V_79 ) ) {
F_8 ( L_24 , V_47 ) ;
F_51 ( * V_47 ) ;
return - V_78 ;
}
return 0 ;
}
int F_52 ( struct V_65 * V_66 )
{
struct V_71 * V_72 = V_66 -> V_80 ;
struct V_46 * V_47 ;
int V_76 ;
V_81 ;
F_2 ( ! V_66 -> V_82 ) ;
F_2 ( V_72 ) ;
V_76 = F_48 ( V_72 , & V_47 ) ;
if ( V_76 )
RETURN ( V_76 ) ;
V_66 -> V_82 = F_29 ( V_47 ) ;
F_51 ( V_47 ) ;
if ( ! V_66 -> V_82 ) {
F_8 ( L_25 , V_66 ) ;
RETURN ( - V_83 ) ;
}
RETURN ( 0 ) ;
}
void F_53 ( struct V_65 * V_66 , int V_60 )
{
V_81 ;
F_2 ( V_66 ) ;
F_2 ( V_66 -> V_82 ) ;
if ( ! F_54 ( & V_66 -> V_69 ) ) {
F_39 ( & V_66 -> V_82 -> V_68 ) ;
F_41 ( & V_66 -> V_69 ) ;
F_43 ( & V_66 -> V_82 -> V_68 ) ;
}
F_34 ( V_66 -> V_82 , V_60 ) ;
V_66 -> V_82 = NULL ;
EXIT ;
}
static
int F_55 ( struct V_65 * V_66 ,
struct V_45 * V_84 ,
struct V_45 * V_85 )
{
struct V_30 V_86 ;
char * V_87 = NULL ;
int V_88 ;
int V_76 = 0 ;
F_2 ( V_66 -> V_89 ) ;
F_2 ( V_66 -> V_90 ) ;
F_2 ( V_66 -> V_91 ) ;
F_6 ( V_13 , L_26
L_27 , V_66 ,
V_84 , V_84 -> V_92 . V_56 , F_56 ( V_84 -> V_61 ) ,
V_85 , V_85 -> V_92 . V_56 , F_56 ( V_85 -> V_61 ) ,
V_84 -> V_61 , V_84 -> V_61 -> V_52 -> V_5 ,
V_85 -> V_61 , V_85 -> V_61 -> V_52 -> V_5 ) ;
V_86 = V_66 -> V_93 ;
V_88 = V_66 -> V_90 ;
if ( V_88 != 0 ) {
F_57 ( V_87 , V_88 ) ;
if ( V_87 == NULL )
return - V_83 ;
memcpy ( V_87 , V_66 -> V_89 , V_88 ) ;
}
V_66 -> V_82 = V_84 ;
F_58 ( V_66 ) ;
F_59 ( V_66 ) ;
V_66 -> V_82 = V_85 ;
F_60 ( V_66 , 0 ) ;
if ( V_88 != 0 ) {
V_76 = F_61 ( V_66 , V_88 ) ;
if ( ! V_76 ) {
F_2 ( V_66 -> V_89 ) ;
memcpy ( V_66 -> V_89 , V_87 , V_88 ) ;
} else {
F_62 ( L_28 , V_76 ) ;
V_66 -> V_93 = V_86 ;
}
F_63 ( V_87 , V_88 ) ;
}
return V_76 ;
}
int F_64 ( struct V_65 * V_66 )
{
struct V_45 * V_84 = V_66 -> V_82 ;
struct V_45 * V_85 ;
int V_76 ;
V_81 ;
F_2 ( V_84 ) ;
F_32 ( V_84 ) ;
F_53 ( V_66 , 0 ) ;
V_76 = F_52 ( V_66 ) ;
if ( F_4 ( V_76 ) ) {
F_2 ( ! V_66 -> V_82 ) ;
V_66 -> V_82 = V_84 ;
RETURN ( V_76 ) ;
}
V_85 = V_66 -> V_82 ;
F_2 ( V_85 ) ;
if ( F_4 ( V_85 == V_84 &&
F_65 ( V_94 , & V_84 -> V_95 ) ) ) {
F_6 ( V_13 ,
L_29 ,
V_85 , V_85 -> V_95 ) ;
F_66 ( V_96 ,
V_97 ) ;
} else {
V_76 = F_55 ( V_66 , V_84 , V_85 ) ;
if ( V_76 ) {
F_53 ( V_66 , 0 ) ;
V_66 -> V_82 = V_84 ;
RETURN ( V_76 ) ;
}
F_2 ( V_66 -> V_82 == V_85 ) ;
}
F_34 ( V_84 , 1 ) ;
RETURN ( 0 ) ;
}
static
int F_67 ( struct V_45 * V_58 )
{
if ( F_68 ( V_58 ) )
return 1 ;
return 0 ;
}
static
int F_69 ( void * V_98 )
{
struct V_65 * V_66 = V_98 ;
int V_76 ;
F_70 ( V_66 -> V_89 , V_66 -> V_80 -> V_99 ) ;
V_76 = F_71 ( V_66 , 1 ) ;
if ( V_76 == 0 )
V_66 -> V_82 -> V_63 -> V_64 ( V_66 -> V_82 , 0 ) ;
return V_76 ;
}
static
void F_72 ( void * V_98 )
{
struct V_65 * V_66 = V_98 ;
F_39 ( & V_66 -> V_100 ) ;
V_66 -> V_101 = 1 ;
F_43 ( & V_66 -> V_100 ) ;
}
static
void F_73 ( struct V_65 * V_66 , struct V_45 * V_58 )
{
F_39 ( & V_58 -> V_68 ) ;
if ( ! F_54 ( & V_66 -> V_69 ) )
F_41 ( & V_66 -> V_69 ) ;
F_43 ( & V_58 -> V_68 ) ;
}
int F_74 ( struct V_65 * V_66 , long V_102 )
{
struct V_45 * V_58 = V_66 -> V_82 ;
struct V_46 * V_47 ;
struct V_103 V_104 ;
int V_76 ;
V_81 ;
F_2 ( V_58 ) ;
if ( V_66 -> V_105 || V_66 -> V_106 )
RETURN ( 0 ) ;
V_107:
V_76 = F_48 ( V_66 -> V_80 , & V_47 ) ;
if ( V_76 )
RETURN ( V_76 ) ;
if ( V_47 -> V_54 . V_34 != V_66 -> V_93 . V_34 ) {
F_6 ( V_13 , L_30 ,
V_66 , V_66 -> V_93 . V_34 , V_47 -> V_54 . V_34 ) ;
F_73 ( V_66 , V_58 ) ;
F_64 ( V_66 ) ;
V_58 = V_66 -> V_82 ;
}
F_51 ( V_47 ) ;
if ( F_75 ( V_58 ) )
RETURN ( 0 ) ;
if ( F_4 ( F_65 ( V_108 , & V_58 -> V_95 ) ) ) {
F_2 ( V_58 -> V_63 -> V_109 ) ;
V_58 -> V_63 -> V_109 ( V_58 ) ;
}
F_2 ( F_65 ( V_108 , & V_58 -> V_95 ) == 0 ) ;
F_2 ( V_58 -> V_63 -> V_110 ) ;
if ( V_58 -> V_63 -> V_110 ( V_58 ) == 0 ) {
F_73 ( V_66 , V_58 ) ;
RETURN ( 0 ) ;
}
if ( F_4 ( F_65 ( V_111 , & V_58 -> V_95 ) ) ) {
F_39 ( & V_66 -> V_100 ) ;
V_66 -> V_112 = 1 ;
F_43 ( & V_66 -> V_100 ) ;
F_73 ( V_66 , V_58 ) ;
RETURN ( - V_113 ) ;
}
if ( F_65 ( V_114 , & V_58 -> V_95 ) &&
F_4 ( V_66 -> V_89 ) &&
F_76 ( V_66 -> V_89 ) & V_115 ) {
F_73 ( V_66 , V_58 ) ;
RETURN ( 0 ) ;
}
if ( F_4 ( F_65 ( V_94 , & V_58 -> V_95 ) ) ) {
F_73 ( V_66 , V_58 ) ;
if ( V_66 -> V_80 -> V_116 ) {
F_39 ( & V_66 -> V_100 ) ;
V_66 -> V_112 = 1 ;
F_43 ( & V_66 -> V_100 ) ;
RETURN ( - V_117 ) ;
}
V_76 = F_64 ( V_66 ) ;
if ( V_76 ) {
F_2 ( V_58 == V_66 -> V_82 ) ;
F_8 ( L_31 ,
V_66 , V_58 , V_76 ) ;
F_39 ( & V_66 -> V_100 ) ;
V_66 -> V_112 = 1 ;
F_43 ( & V_66 -> V_100 ) ;
RETURN ( V_76 ) ;
}
V_58 = V_66 -> V_82 ;
goto V_107;
}
F_39 ( & V_58 -> V_68 ) ;
if ( F_54 ( & V_66 -> V_69 ) )
F_77 ( & V_66 -> V_69 , & V_58 -> V_118 ) ;
F_43 ( & V_58 -> V_68 ) ;
if ( V_102 < 0 )
RETURN ( - V_119 ) ;
F_2 ( V_66 -> V_120 == 0 ) ;
F_39 ( & V_66 -> V_100 ) ;
V_66 -> V_112 = 0 ;
V_66 -> V_121 = 0 ;
V_66 -> V_122 = 0 ;
V_66 -> V_123 = 0 ;
F_43 ( & V_66 -> V_100 ) ;
V_104 = F_78 ( V_102 * V_97 , F_69 ,
F_72 , V_66 ) ;
V_76 = F_79 ( V_66 -> V_124 , F_67 ( V_58 ) , & V_104 ) ;
if ( ! F_68 ( V_58 ) ) {
F_73 ( V_66 , V_58 ) ;
F_2 ( V_76 != 0 ) ;
RETURN ( V_76 ) ;
}
goto V_107;
}
void F_60 ( struct V_65 * V_66 , int V_125 )
{
struct V_46 * V_47 ;
F_2 ( V_66 -> V_80 ) ;
F_2 ( V_66 -> V_82 ) ;
F_2 ( V_66 -> V_82 -> V_61 ) ;
F_2 ( V_66 -> V_126 == 0 || V_66 -> V_127 == 0 ) ;
switch ( V_125 ) {
case V_128 :
case V_129 :
case V_130 :
case V_131 :
V_66 -> V_126 = 1 ;
break;
case V_132 :
case V_133 :
V_66 -> V_127 = 1 ;
break;
case V_134 :
V_66 -> V_105 = 1 ;
break;
case V_135 :
V_66 -> V_106 = 1 ;
break;
case 0 :
F_2 ( V_66 -> V_105 == 0 ) ;
F_2 ( V_66 -> V_106 == 0 ) ;
V_66 -> V_136 = 0 ;
V_66 -> V_137 = 0 ;
break;
}
V_47 = V_66 -> V_82 -> V_61 ;
F_39 ( & V_47 -> V_138 ) ;
V_66 -> V_93 = V_47 -> V_54 ;
F_43 ( & V_47 -> V_138 ) ;
if ( F_4 ( V_66 -> V_105 ) )
F_80 ( & V_66 -> V_93 . V_34 , V_139 ) ;
else if ( F_4 ( V_66 -> V_106 ) )
F_80 ( & V_66 -> V_93 . V_34 , V_140 ) ;
if ( ( V_47 -> V_54 . V_55 & V_43 ) &&
( V_66 -> V_93 . V_34 != V_21 ) )
V_66 -> V_136 = 1 ;
if ( ( V_66 -> V_126 || V_66 -> V_127 ) &&
F_81 ( & V_66 -> V_93 ) )
V_66 -> V_137 = 1 ;
}
void F_82 ( struct V_65 * V_66 )
{
if ( F_83 ( V_66 -> V_93 . V_34 ) != V_141 )
return;
F_2 ( V_66 -> V_142 ) ;
if ( V_66 -> V_143 || ! V_66 -> V_144 )
return;
F_84 ( V_66 -> V_144 , V_66 -> V_145 ) ;
V_66 -> V_144 = NULL ;
V_66 -> V_145 = 0 ;
}
int F_85 ( struct V_71 * V_72 )
{
struct V_46 * V_47 ;
struct V_45 * V_58 ;
struct V_65 * V_66 = NULL ;
int V_76 ;
V_81 ;
F_86 () ;
V_47 = F_49 ( V_72 ) ;
V_58 = F_29 ( V_47 ) ;
F_51 ( V_47 ) ;
if ( ! V_58 )
RETURN ( - V_83 ) ;
if ( F_75 ( V_58 ) ||
V_58 -> V_63 -> V_110 ( V_58 ) == 0 ) {
F_34 ( V_58 , 1 ) ;
RETURN ( 0 ) ;
}
if ( F_87 ( V_58 ) ) {
F_34 ( V_58 , 1 ) ;
RETURN ( - V_78 ) ;
}
F_88 ( V_66 ) ;
if ( ! V_66 )
RETURN ( - V_83 ) ;
F_89 ( & V_66 -> V_100 ) ;
F_19 ( & V_66 -> V_146 , 10000 ) ;
F_90 ( & V_66 -> V_69 ) ;
F_91 ( & V_66 -> V_124 ) ;
F_91 ( & V_66 -> V_147 ) ;
V_66 -> V_80 = V_72 ;
V_66 -> V_93 = V_47 -> V_54 ;
V_66 -> V_82 = V_58 ;
V_76 = F_74 ( V_66 , 0 ) ;
F_2 ( F_54 ( & V_66 -> V_69 ) ) ;
F_34 ( V_66 -> V_82 , 1 ) ;
F_92 ( V_66 ) ;
RETURN ( V_76 ) ;
}
int F_93 ( struct V_65 * V_66 )
{
struct V_45 * V_58 = V_66 -> V_82 ;
int V_76 = 0 ;
V_81 ;
F_2 ( V_58 ) ;
F_2 ( V_58 -> V_61 ) ;
F_2 ( V_66 -> V_144 || V_66 -> V_142 ) ;
if ( V_66 -> V_148 ) {
V_76 = F_94 ( V_66 , V_66 -> V_148 ) ;
if ( V_76 )
RETURN ( V_76 ) ;
}
switch ( F_83 ( V_66 -> V_93 . V_34 ) ) {
case V_139 :
case V_149 :
case V_140 :
F_2 ( V_58 -> V_63 -> V_150 ) ;
V_76 = V_58 -> V_63 -> V_150 ( V_58 , V_66 ) ;
break;
case V_141 :
F_2 ( V_58 -> V_63 -> V_151 ) ;
V_76 = V_58 -> V_63 -> V_151 ( V_58 , V_66 ) ;
break;
default:
F_95 () ;
}
if ( V_76 == 0 ) {
F_2 ( V_66 -> V_152 ) ;
F_2 ( V_66 -> V_152 % 8 == 0 ) ;
F_2 ( V_66 -> V_152 <= V_66 -> V_145 ) ;
}
RETURN ( V_76 ) ;
}
static int F_96 ( struct V_65 * V_66 )
{
struct V_45 * V_58 = V_66 -> V_82 ;
int V_76 ;
V_81 ;
F_2 ( V_58 ) ;
F_2 ( V_58 -> V_61 ) ;
F_2 ( V_66 -> V_153 ) ;
F_2 ( V_66 -> V_154 ) ;
F_2 ( V_66 -> V_155 == NULL ) ;
V_66 -> V_156 = 0 ;
V_76 = F_97 ( V_66 -> V_154 , V_66 -> V_157 ) ;
switch ( V_76 ) {
case 1 :
F_98 ( V_66 , V_158 ) ;
case 0 :
break;
default:
F_8 ( L_32 V_159 L_33 , V_66 -> V_160 ) ;
RETURN ( - V_161 ) ;
}
if ( V_66 -> V_157 < sizeof( struct V_162 ) ) {
F_8 ( L_34 ,
V_66 -> V_157 ) ;
RETURN ( - V_161 ) ;
}
if ( F_12 ( V_66 -> V_154 -> V_163 ) !=
F_12 ( V_66 -> V_93 . V_34 ) ) {
F_8 ( L_35 ,
F_12 ( V_66 -> V_154 -> V_163 ) ,
F_12 ( V_66 -> V_93 . V_34 ) ) ;
RETURN ( - V_161 ) ;
}
switch ( F_83 ( V_66 -> V_93 . V_34 ) ) {
case V_139 :
case V_149 :
case V_140 :
F_2 ( V_58 -> V_63 -> V_164 ) ;
V_76 = V_58 -> V_63 -> V_164 ( V_58 , V_66 ) ;
break;
case V_141 :
F_2 ( V_58 -> V_63 -> V_165 ) ;
V_76 = V_58 -> V_63 -> V_165 ( V_58 , V_66 ) ;
break;
default:
F_95 () ;
}
F_2 ( V_76 || V_66 -> V_155 || V_66 -> V_122 ) ;
if ( F_12 ( V_66 -> V_93 . V_34 ) != V_166 &&
! V_66 -> V_105 )
V_66 -> V_156 = 0 ;
RETURN ( V_76 ) ;
}
int F_99 ( struct V_65 * V_66 )
{
F_2 ( V_66 -> V_153 ) ;
F_2 ( V_66 -> V_154 == NULL ) ;
F_2 ( V_66 -> V_155 == NULL ) ;
F_2 ( V_66 -> V_167 + V_66 -> V_168 <= V_66 -> V_169 ) ;
if ( V_66 -> V_167 == 0 &&
( F_100 ( V_66 -> V_89 ) & V_170 ) ) {
F_8 ( L_36 ) ;
return - V_161 ;
}
if ( V_66 -> V_167 % 8 != 0 ) {
F_8 ( L_37 , V_66 -> V_167 ) ;
return - V_161 ;
}
V_66 -> V_154 = (struct V_162 * )
( V_66 -> V_153 + V_66 -> V_167 ) ;
V_66 -> V_157 = V_66 -> V_168 ;
return F_96 ( V_66 ) ;
}
int F_101 ( struct V_65 * V_66 ,
struct V_65 * * V_171 )
{
struct V_65 * V_172 ;
char * V_173 ;
int V_174 , V_175 ;
int V_76 ;
V_81 ;
F_88 ( V_172 ) ;
if ( V_172 == NULL )
RETURN ( - V_83 ) ;
V_175 = V_66 -> V_168 ;
V_174 = F_102 ( V_175 ) ;
F_57 ( V_173 , V_174 ) ;
if ( V_173 == NULL )
GOTO ( V_176 , V_76 = - V_83 ) ;
F_39 ( & V_66 -> V_100 ) ;
if ( V_66 -> V_177 ) {
F_43 ( & V_66 -> V_100 ) ;
GOTO ( V_178 , V_76 = - V_12 ) ;
}
F_2 ( V_66 -> V_153 ) ;
F_2 ( V_66 -> V_154 == NULL ) ;
F_2 ( V_66 -> V_155 == NULL ) ;
if ( V_66 -> V_167 != 0 ) {
F_8 ( L_38 , V_66 -> V_167 ) ;
F_43 ( & V_66 -> V_100 ) ;
GOTO ( V_178 , V_76 = - V_161 ) ;
}
if ( V_66 -> V_168 != V_175 ) {
F_8 ( L_39 ,
V_175 , V_66 -> V_168 ) ;
F_43 ( & V_66 -> V_100 ) ;
GOTO ( V_178 , V_76 = - V_9 ) ;
}
if ( V_66 -> V_168 < sizeof( struct V_162 ) ) {
F_8 ( L_40 ,
V_66 -> V_168 ) ;
F_43 ( & V_66 -> V_100 ) ;
GOTO ( V_178 , V_76 = - V_12 ) ;
}
memcpy ( V_173 , V_66 -> V_153 , V_175 ) ;
F_43 ( & V_66 -> V_100 ) ;
F_89 ( & V_172 -> V_100 ) ;
V_172 -> V_82 = F_32 ( V_66 -> V_82 ) ;
V_172 -> V_93 = V_66 -> V_93 ;
V_172 -> V_153 = V_173 ;
V_172 -> V_169 = V_174 ;
V_172 -> V_154 = (struct V_162 * ) V_173 ;
V_172 -> V_157 = V_175 ;
V_172 -> V_179 = 1 ;
V_172 -> V_89 = V_66 -> V_89 ;
V_76 = F_96 ( V_172 ) ;
if ( V_76 ) {
F_103 ( V_180 , V_172 ,
L_41 , V_76 ) ;
GOTO ( V_181 , V_76 ) ;
}
F_2 ( V_172 -> V_155 ) ;
* V_171 = V_172 ;
RETURN ( 0 ) ;
V_181:
F_34 ( V_172 -> V_82 , 1 ) ;
V_178:
F_63 ( V_173 , V_174 ) ;
V_176:
F_92 ( V_172 ) ;
RETURN ( V_76 ) ;
}
void F_104 ( struct V_65 * V_172 )
{
F_2 ( V_172 -> V_153 ) ;
F_2 ( V_172 -> V_154 ) ;
F_2 ( V_172 -> V_155 ) ;
F_34 ( V_172 -> V_82 , 1 ) ;
F_63 ( V_172 -> V_153 , V_172 -> V_169 ) ;
F_92 ( V_172 ) ;
}
int F_105 ( void )
{
return F_106 ( & V_182 ) ;
}
static int F_107 ( struct V_46 * V_47 , T_4 V_183 ,
int V_184 , int V_185 )
{
struct V_1 * V_2 = V_47 -> V_52 ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_6 -> V_186 ) ;
return V_2 -> V_6 -> V_186 ( V_47 , V_183 , V_184 , V_185 ) ;
}
static void F_108 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_52 ;
F_109 ( & V_47 -> V_187 ) ;
F_109 ( & V_47 -> V_188 ) ;
F_2 ( V_2 -> V_6 -> V_189 ) ;
F_6 ( V_13 , L_42 , V_47 -> V_52 -> V_5 , V_47 ) ;
V_2 -> V_6 -> V_189 ( V_47 ) ;
F_110 ( V_2 ) ;
}
void F_111 ( struct V_46 * V_47 )
{
F_108 ( V_47 ) ;
}
static void F_112 ( struct V_46 * V_47 )
{
F_35 ( & V_47 -> V_187 ) ;
if ( V_47 -> V_52 -> V_6 -> V_190 ) {
V_47 -> V_52 -> V_6 -> V_190 ( V_47 ) ;
F_107 ( V_47 , - 1 , 1 , 1 ) ;
}
}
struct V_46 * F_113 ( struct V_46 * V_47 )
{
if ( V_47 )
F_33 ( & V_47 -> V_187 ) ;
return V_47 ;
}
void F_51 ( struct V_46 * V_47 )
{
if ( V_47 ) {
F_35 ( & V_47 -> V_187 ) ;
if ( F_36 ( & V_47 -> V_187 ) ) {
F_114 ( V_47 ) ;
F_108 ( V_47 ) ;
}
}
}
static
struct V_46 * F_115 ( struct V_71 * V_72 ,
struct V_191 * V_192 ,
struct V_30 * V_31 ,
enum V_193 V_194 )
{
struct V_1 * V_2 ;
struct V_46 * V_47 ;
char V_195 [ 32 ] ;
V_81 ;
if ( V_192 ) {
F_2 ( V_72 -> V_196 == 1 ) ;
F_6 ( V_13 , L_43 ,
V_72 -> V_197 -> V_198 -> V_199 ,
V_72 -> V_197 -> V_200 ,
F_26 ( V_31 , V_195 , sizeof( V_195 ) ) ) ;
V_2 = F_116 ( V_192 -> V_201 ) ;
V_31 -> V_55 |= V_41 | V_42 ;
} else {
F_2 ( V_72 -> V_196 == 0 ) ;
F_6 ( V_13 , L_44 ,
V_72 -> V_197 -> V_198 -> V_199 ,
V_72 -> V_197 -> V_200 ,
F_26 ( V_31 , V_195 , sizeof( V_195 ) ) ) ;
V_2 = F_9 ( V_31 -> V_34 ) ;
if ( ! V_2 ) {
F_8 ( L_45 , V_31 -> V_34 ) ;
RETURN ( NULL ) ;
}
}
V_47 = V_2 -> V_6 -> V_202 ( V_72 , V_192 , V_31 ) ;
if ( V_47 ) {
F_33 ( & V_47 -> V_187 ) ;
V_47 -> V_203 = V_194 ;
if ( V_47 -> V_204 && V_2 -> V_6 -> V_205 )
F_117 ( V_47 ) ;
} else {
F_110 ( V_2 ) ;
}
RETURN ( V_47 ) ;
}
struct V_46 * F_49 ( struct V_71 * V_72 )
{
struct V_46 * V_47 ;
F_39 ( & V_72 -> V_74 ) ;
V_47 = F_113 ( V_72 -> V_206 ) ;
F_43 ( & V_72 -> V_74 ) ;
return V_47 ;
}
static void F_118 ( struct V_71 * V_72 ,
struct V_46 * V_47 )
{
struct V_46 * V_207 ;
F_35 ( & V_47 -> V_187 ) ;
F_39 ( & V_72 -> V_74 ) ;
V_207 = V_72 -> V_206 ;
V_72 -> V_206 = V_47 ;
F_43 ( & V_72 -> V_74 ) ;
if ( V_207 ) {
F_112 ( V_207 ) ;
F_51 ( V_207 ) ;
}
}
static inline
int F_119 ( struct V_30 * V_208 , struct V_30 * V_209 )
{
return ( memcmp ( V_208 , V_209 , sizeof( * V_208 ) ) == 0 ) ;
}
static inline
void F_120 ( struct V_30 * V_210 , struct V_30 * V_211 )
{
* V_210 = * V_211 ;
}
static void F_121 ( struct V_71 * V_72 ,
struct V_46 * V_47 ,
struct V_30 * V_31 )
{
char V_212 [ 32 ] , V_213 [ 32 ] ;
if ( V_47 -> V_54 . V_55 != V_31 -> V_55 )
F_6 ( V_13 , L_46 ,
F_27 ( V_47 -> V_54 . V_55 ,
V_212 , sizeof( V_212 ) ) ,
F_27 ( V_31 -> V_55 ,
V_213 , sizeof( V_213 ) ) ) ;
F_39 ( & V_47 -> V_138 ) ;
F_120 ( & V_47 -> V_54 , V_31 ) ;
F_43 ( & V_47 -> V_138 ) ;
}
int F_47 ( struct V_71 * V_72 ,
struct V_191 * V_192 ,
struct V_30 * V_28 )
{
struct V_214 * V_215 ;
struct V_30 V_31 ;
struct V_46 * V_47 , * V_216 ;
enum V_193 V_194 ;
char V_195 [ 24 ] ;
int V_76 = 0 ;
V_81 ;
F_86 () ;
if ( V_72 == NULL )
RETURN ( 0 ) ;
V_215 = V_72 -> V_217 ;
if ( V_192 == NULL ) {
struct V_218 * V_219 = & V_72 -> V_197 -> V_220 . V_221 ;
if ( V_219 -> V_222 == V_223 )
V_31 = V_219 -> V_224 ;
else
F_122 ( V_219 -> V_222 ,
V_219 -> V_225 ,
& V_219 -> V_226 ,
V_215 -> V_227 , & V_31 ) ;
V_194 = V_72 -> V_197 -> V_220 . V_221 . V_222 ;
} else {
V_31 = * V_28 ;
if ( V_31 . V_34 != V_21 )
V_31 . V_55 = V_41 |
V_42 ;
V_194 = F_123 ( V_72 -> V_197 ) ;
}
V_47 = F_49 ( V_72 ) ;
if ( V_47 ) {
char V_213 [ 24 ] ;
if ( F_119 ( & V_31 , & V_47 -> V_54 ) )
GOTO ( V_228 , V_76 ) ;
F_6 ( V_13 , L_47 ,
V_72 -> V_197 -> V_200 ,
F_124 ( & V_215 -> V_229 ) ,
F_26 ( & V_47 -> V_54 , V_195 , sizeof( V_195 ) ) ,
F_26 ( & V_31 , V_213 , sizeof( V_213 ) ) ) ;
if ( F_12 ( V_31 . V_34 ) ==
F_12 ( V_47 -> V_54 . V_34 ) &&
F_125 ( V_31 . V_34 ) ==
F_125 ( V_47 -> V_54 . V_34 ) ) {
F_121 ( V_72 , V_47 , & V_31 ) ;
GOTO ( V_228 , V_76 ) ;
}
} else if ( F_23 ( V_31 . V_34 ) !=
F_23 ( V_21 ) ) {
F_6 ( V_13 , L_48 ,
V_72 -> V_197 -> V_200 ,
F_124 ( & V_215 -> V_229 ) ,
F_126 ( V_215 -> V_227 ) ,
F_26 ( & V_31 , V_195 , sizeof( V_195 ) ) ) ;
}
F_17 ( & V_72 -> V_230 ) ;
V_216 = F_115 ( V_72 , V_192 , & V_31 , V_194 ) ;
if ( V_216 ) {
F_118 ( V_72 , V_216 ) ;
} else {
F_8 ( L_49 ,
V_72 -> V_197 -> V_200 ,
F_124 ( & V_215 -> V_229 ) ) ;
V_76 = - V_113 ;
}
F_20 ( & V_72 -> V_230 ) ;
V_228:
F_51 ( V_47 ) ;
RETURN ( V_76 ) ;
}
void F_127 ( struct V_71 * V_72 )
{
if ( V_72 -> V_206 ) {
F_112 ( V_72 -> V_206 ) ;
F_51 ( V_72 -> V_206 ) ;
V_72 -> V_206 = NULL ;
}
}
static void F_128 ( struct V_71 * V_72 ,
T_4 V_183 , int V_184 , int V_185 )
{
struct V_46 * V_47 ;
if ( V_72 == NULL )
return;
V_47 = F_49 ( V_72 ) ;
if ( V_47 == NULL )
return;
F_107 ( V_47 , V_183 , V_184 , V_185 ) ;
F_51 ( V_47 ) ;
}
void F_129 ( struct V_71 * V_72 )
{
F_128 ( V_72 , 0 , 1 , 1 ) ;
}
void F_130 ( struct V_71 * V_72 )
{
F_128 ( V_72 , F_30 () , 1 , 1 ) ;
}
void F_131 ( struct V_71 * V_72 )
{
F_128 ( V_72 , - 1 , 1 , 1 ) ;
}
int F_61 ( struct V_65 * V_66 , int V_231 )
{
struct V_45 * V_58 = V_66 -> V_82 ;
struct V_1 * V_2 ;
int V_76 ;
F_2 ( V_58 ) ;
F_2 ( V_58 -> V_61 ) ;
F_2 ( V_58 -> V_61 -> V_52 ) ;
F_2 ( V_66 -> V_89 == NULL ) ;
F_35 ( & V_58 -> V_59 ) ;
V_2 = V_58 -> V_61 -> V_52 ;
V_76 = V_2 -> V_6 -> V_232 ( V_58 -> V_61 , V_66 , V_231 ) ;
if ( ! V_76 ) {
F_2 ( V_66 -> V_89 ) ;
F_2 ( V_66 -> V_144 || V_66 -> V_142 ) ;
if ( V_66 -> V_143 )
memset ( V_66 -> V_89 , 0 , V_231 ) ;
}
return V_76 ;
}
void F_58 ( struct V_65 * V_66 )
{
struct V_45 * V_58 = V_66 -> V_82 ;
struct V_1 * V_2 ;
F_2 ( V_58 ) ;
F_2 ( V_58 -> V_61 ) ;
F_2 ( V_58 -> V_61 -> V_52 ) ;
F_35 ( & V_58 -> V_59 ) ;
if ( V_66 -> V_144 == NULL && V_66 -> V_142 == NULL )
return;
V_2 = V_58 -> V_61 -> V_52 ;
V_2 -> V_6 -> V_233 ( V_58 -> V_61 , V_66 ) ;
V_66 -> V_89 = NULL ;
}
void F_132 ( struct V_162 * V_234 ,
int V_235 , int V_236 )
{
void * V_211 , * V_210 ;
int V_237 , V_238 , V_239 ;
F_2 ( V_235 < V_234 -> V_240 ) ;
F_2 ( V_234 -> V_241 [ V_235 ] <= V_236 ) ;
if ( V_234 -> V_241 [ V_235 ] == V_236 )
return;
if ( V_235 == V_234 -> V_240 - 1 ) {
V_234 -> V_241 [ V_235 ] = V_236 ;
return;
}
V_237 = V_234 -> V_241 [ V_235 ] ;
V_211 = F_133 ( V_234 , V_235 + 1 , 0 ) ;
V_234 -> V_241 [ V_235 ] = V_236 ;
V_210 = F_133 ( V_234 , V_235 + 1 , 0 ) ;
V_234 -> V_241 [ V_235 ] = V_237 ;
F_2 ( V_234 -> V_242 == V_243 ) ;
V_238 = F_134 ( V_234 -> V_240 , V_234 -> V_241 ) ;
V_239 = V_238 - ( ( unsigned long ) V_211 - ( unsigned long ) V_234 ) ;
F_2 ( V_239 >= 0 ) ;
if ( V_239 )
memmove ( V_210 , V_211 , V_239 ) ;
V_234 -> V_241 [ V_235 ] = V_236 ;
}
int F_135 ( struct V_65 * V_66 ,
int V_235 , int V_236 )
{
struct V_45 * V_58 = V_66 -> V_82 ;
struct V_244 * V_245 ;
struct V_162 * V_234 = V_66 -> V_89 ;
F_2 ( V_58 ) ;
F_2 ( V_234 ) ;
F_2 ( V_234 -> V_240 > V_235 ) ;
F_2 ( V_234 -> V_241 [ V_235 ] <= V_236 ) ;
if ( V_234 -> V_241 [ V_235 ] == V_236 )
return 0 ;
V_245 = V_58 -> V_61 -> V_52 -> V_6 ;
F_2 ( V_245 -> V_246 ) ;
return V_245 -> V_246 ( V_58 -> V_61 , V_66 , V_235 , V_236 ) ;
}
int F_136 ( struct V_65 * V_66 , int V_231 )
{
struct V_45 * V_58 = V_66 -> V_82 ;
struct V_1 * V_2 ;
V_81 ;
F_2 ( V_58 ) ;
F_2 ( V_58 -> V_61 ) ;
F_2 ( V_58 -> V_61 -> V_52 ) ;
if ( V_66 -> V_153 )
RETURN ( 0 ) ;
V_2 = V_58 -> V_61 -> V_52 ;
RETURN ( V_2 -> V_6 -> V_247 ( V_58 -> V_61 , V_66 , V_231 ) ) ;
}
void F_59 ( struct V_65 * V_66 )
{
struct V_45 * V_58 = V_66 -> V_82 ;
struct V_1 * V_2 ;
V_81 ;
F_2 ( V_58 ) ;
F_2 ( V_58 -> V_61 ) ;
F_2 ( V_58 -> V_61 -> V_52 ) ;
F_35 ( & V_58 -> V_59 ) ;
if ( V_66 -> V_153 == NULL )
return;
F_2 ( V_66 -> V_169 ) ;
V_2 = V_58 -> V_61 -> V_52 ;
V_2 -> V_6 -> V_248 ( V_58 -> V_61 , V_66 ) ;
V_66 -> V_155 = NULL ;
EXIT ;
}
int F_137 ( struct V_71 * V_72 ,
struct V_45 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_61 -> V_52 ;
if ( ! V_2 -> V_6 -> V_249 )
return 0 ;
return V_2 -> V_6 -> V_249 ( V_72 , V_58 -> V_61 , V_58 ) ;
}
int F_138 ( struct V_71 * V_72 ,
struct V_191 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_201 ;
if ( ! V_2 -> V_7 -> V_249 )
return 0 ;
return V_2 -> V_7 -> V_249 ( V_72 , V_58 ) ;
}
static int F_139 ( struct V_30 * exp ,
struct V_65 * V_66 )
{
struct V_30 * V_28 = & V_66 -> V_93 ;
if ( exp -> V_34 == V_250 || exp -> V_34 == V_28 -> V_34 )
return 1 ;
if ( ( V_66 -> V_105 || V_66 -> V_106 ) &&
F_12 ( exp -> V_34 ) ==
F_12 ( V_28 -> V_34 ) &&
F_125 ( exp -> V_34 ) == F_125 ( V_28 -> V_34 ) )
return 1 ;
return 0 ;
}
int F_140 ( struct V_251 * exp ,
struct V_65 * V_66 )
{
struct V_30 V_14 ;
if ( exp == NULL )
return 0 ;
if ( exp -> V_252 == NULL )
return 0 ;
if ( V_66 -> V_106 )
return 0 ;
F_39 ( & exp -> V_253 ) ;
if ( F_4 ( exp -> V_254 ) &&
F_139 ( & exp -> V_255 [ 1 ] , V_66 ) ) {
F_6 ( V_13 , L_50 , exp ,
exp -> V_256 . V_34 , exp -> V_255 [ 1 ] . V_34 ) ;
V_14 = exp -> V_255 [ 1 ] ;
exp -> V_255 [ 1 ] = exp -> V_255 [ 0 ] ;
exp -> V_257 [ 1 ] = exp -> V_257 [ 0 ] ;
exp -> V_255 [ 0 ] = exp -> V_256 ;
exp -> V_257 [ 0 ] = F_46 () +
V_258 ;
exp -> V_256 = V_14 ;
exp -> V_254 = 0 ;
F_2 ( exp -> V_259 == 1 ) ;
if ( V_66 -> V_260 &&
! ( V_66 -> V_105 &&
( V_66 -> V_261 || V_66 -> V_262 ||
V_66 -> V_263 ) ) ) {
F_43 ( & exp -> V_253 ) ;
F_6 ( V_13 , L_51 ,
V_66 -> V_260 , V_66 -> V_105 ,
V_66 -> V_261 , V_66 -> V_262 ,
V_66 -> V_263 ) ;
return 0 ;
}
exp -> V_259 = 0 ;
F_43 ( & exp -> V_253 ) ;
return F_47 ( exp -> V_252 ,
V_66 -> V_264 , & V_14 ) ;
}
if ( F_141 ( F_139 ( & exp -> V_256 , V_66 ) ) ) {
if ( ! V_66 -> V_260 || ! V_66 -> V_105 ||
( ! V_66 -> V_261 && ! V_66 -> V_262 &&
! V_66 -> V_263 ) ) {
F_43 ( & exp -> V_253 ) ;
return 0 ;
}
if ( exp -> V_254 ) {
F_2 ( exp -> V_259 ) ;
F_43 ( & exp -> V_253 ) ;
return 0 ;
}
if ( exp -> V_259 ) {
exp -> V_259 = 0 ;
F_6 ( V_13 , L_52 ,
exp , exp -> V_256 . V_34 ,
exp -> V_255 [ 0 ] . V_34 ,
exp -> V_255 [ 1 ] . V_34 ) ;
V_14 = exp -> V_256 ;
F_43 ( & exp -> V_253 ) ;
return F_47 ( exp -> V_252 ,
V_66 -> V_264 ,
& V_14 ) ;
} else {
F_6 ( V_13 , L_53
L_54 , exp , exp -> V_256 . V_34 ,
exp -> V_255 [ 0 ] . V_34 ,
exp -> V_255 [ 1 ] . V_34 ) ;
F_43 ( & exp -> V_253 ) ;
return F_138 ( exp -> V_252 ,
V_66 -> V_264 ) ;
}
}
if ( exp -> V_257 [ 0 ] ) {
if ( exp -> V_257 [ 0 ] >= F_46 () ) {
if ( F_139 ( & exp -> V_255 [ 0 ] , V_66 ) ) {
F_6 ( V_13 , L_55
L_56 V_265 L_57 , exp ,
exp -> V_256 . V_34 ,
exp -> V_255 [ 0 ] . V_34 ,
exp -> V_255 [ 1 ] . V_34 ,
exp -> V_257 [ 0 ] -
F_46 () ) ;
F_43 ( & exp -> V_253 ) ;
return 0 ;
}
} else {
F_6 ( V_13 , L_58 ) ;
exp -> V_257 [ 0 ] = 0 ;
}
F_6 ( V_13 , L_59 , exp ,
exp -> V_256 . V_34 ,
exp -> V_255 [ 0 ] . V_34 , exp -> V_255 [ 1 ] . V_34 ,
V_66 -> V_93 . V_34 ) ;
}
if ( exp -> V_254 == 0 && exp -> V_257 [ 1 ] ) {
if ( exp -> V_257 [ 1 ] >= F_46 () ) {
if ( F_139 ( & exp -> V_255 [ 1 ] , V_66 ) ) {
F_6 ( V_13 , L_55
L_60 V_265 L_57 , exp ,
exp -> V_256 . V_34 ,
exp -> V_255 [ 0 ] . V_34 ,
exp -> V_255 [ 1 ] . V_34 ,
exp -> V_257 [ 1 ] -
F_46 () ) ;
F_43 ( & exp -> V_253 ) ;
return 0 ;
}
} else {
F_6 ( V_13 , L_61 ) ;
exp -> V_257 [ 1 ] = 0 ;
}
F_6 ( V_13 , L_62 ,
exp , exp -> V_256 . V_34 ,
exp -> V_255 [ 0 ] . V_34 , exp -> V_255 [ 1 ] . V_34 ,
V_66 -> V_93 . V_34 ) ;
} else {
F_6 ( V_13 , L_63 ,
exp , exp -> V_256 . V_34 , exp -> V_255 [ 0 ] . V_34 ,
exp -> V_255 [ 1 ] . V_34 ) ;
}
F_43 ( & exp -> V_253 ) ;
F_62 ( L_64
L_65 ,
exp , exp -> V_266 -> V_200 ,
V_66 , V_66 -> V_260 , V_66 -> V_105 , V_66 -> V_106 ,
V_66 -> V_261 , V_66 -> V_262 , V_66 -> V_263 ,
V_66 -> V_93 . V_34 ,
exp -> V_256 . V_34 ,
exp -> V_255 [ 0 ] . V_34 ,
exp -> V_257 [ 0 ] ?
( unsigned long ) ( exp -> V_257 [ 0 ] -
F_46 () ) : 0 ,
exp -> V_255 [ 1 ] . V_34 ,
exp -> V_257 [ 1 ] ?
( unsigned long ) ( exp -> V_257 [ 1 ] -
F_46 () ) : 0 ) ;
return - V_78 ;
}
void F_142 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
struct V_251 * exp ;
struct V_30 V_271 ;
F_2 ( V_268 ) ;
F_39 ( & V_268 -> V_272 ) ;
F_143 (exp, &obd->obd_exports, exp_obd_chain) {
if ( exp -> V_273 == NULL )
continue;
F_39 ( & exp -> V_253 ) ;
F_144 ( V_270 , exp -> V_274 ,
exp -> V_273 -> V_275 . V_276 ,
& V_271 ) ;
if ( exp -> V_254 ||
! F_119 ( & V_271 , & exp -> V_256 ) ) {
exp -> V_255 [ 1 ] = V_271 ;
exp -> V_257 [ 1 ] = 0 ;
exp -> V_254 = 1 ;
exp -> V_259 = 1 ;
F_6 ( V_13 , L_66 ,
exp , F_145 ( exp -> V_274 ) ,
exp -> V_256 . V_34 ,
exp -> V_255 [ 1 ] . V_34 ) ;
}
F_43 ( & exp -> V_253 ) ;
}
F_43 ( & V_268 -> V_272 ) ;
}
static int F_146 ( struct V_65 * V_66 , int V_277 )
{
if ( ! V_66 -> V_260 || V_277 == V_278 )
return V_277 ;
switch ( V_66 -> V_279 ) {
case V_280 :
if ( V_66 -> V_262 || V_66 -> V_263 ) {
F_103 ( V_281 , V_66 , L_67 ) ;
V_277 = V_278 ;
}
break;
case V_282 :
if ( ! V_66 -> V_262 ) {
F_103 ( V_281 , V_66 , L_68 ) ;
V_277 = V_278 ;
}
break;
case V_283 :
if ( ! V_66 -> V_263 ) {
F_103 ( V_281 , V_66 , L_69 ) ;
V_277 = V_278 ;
}
break;
case V_284 :
case V_223 :
if ( ! V_66 -> V_261 && ! V_66 -> V_262 &&
! V_66 -> V_263 ) {
F_103 ( V_281 , V_66 , L_70 ) ;
V_277 = V_278 ;
}
break;
case V_285 :
default:
F_103 ( V_281 , V_66 , L_71 , V_66 -> V_279 ) ;
V_277 = V_278 ;
}
return V_277 ;
}
int F_147 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
struct V_162 * V_234 = V_66 -> V_144 ;
int V_76 ;
V_81 ;
F_2 ( V_234 ) ;
F_2 ( V_66 -> V_89 == NULL ) ;
F_2 ( V_66 -> V_155 == NULL ) ;
F_2 ( V_66 -> V_264 == NULL ) ;
V_66 -> V_286 = 0 ;
V_76 = F_97 ( V_234 , V_66 -> V_152 ) ;
switch ( V_76 ) {
case 1 :
F_148 ( V_66 , V_158 ) ;
case 0 :
break;
default:
F_8 ( L_72 V_159 L_33 ,
F_149 ( V_66 -> V_287 ) , V_66 -> V_160 ) ;
RETURN ( V_278 ) ;
}
V_66 -> V_93 . V_34 = F_150 ( V_234 -> V_163 ) ;
V_66 -> V_279 = V_285 ;
V_66 -> V_288 = V_289 ;
V_66 -> V_290 = V_289 ;
V_2 = F_9 ( V_66 -> V_93 . V_34 ) ;
if ( ! V_2 ) {
F_8 ( L_73 , V_66 -> V_93 . V_34 ) ;
RETURN ( V_278 ) ;
}
F_2 ( V_2 -> V_7 -> V_291 ) ;
V_76 = V_2 -> V_7 -> V_291 ( V_66 ) ;
F_110 ( V_2 ) ;
F_2 ( V_66 -> V_89 || V_76 != V_292 ) ;
F_2 ( V_66 -> V_264 || V_76 == V_278 ) ;
if ( F_12 ( V_66 -> V_93 . V_34 ) != V_166 )
V_66 -> V_286 = 0 ;
V_76 = F_146 ( V_66 , V_76 ) ;
RETURN ( V_76 ) ;
}
int F_151 ( struct V_65 * V_66 , int V_293 )
{
struct V_1 * V_2 ;
struct V_294 * V_295 ;
int V_76 ;
V_81 ;
F_2 ( V_66 -> V_264 ) ;
F_2 ( V_66 -> V_264 -> V_201 ) ;
V_2 = V_66 -> V_264 -> V_201 ;
F_2 ( V_2 -> V_7 -> V_296 ) ;
V_76 = V_2 -> V_7 -> V_296 ( V_66 , V_293 ) ;
if ( F_4 ( V_76 == - V_83 ) ) {
V_295 = F_152 ( V_66 -> V_297 -> V_298 ) ;
if ( V_295 == NULL )
RETURN ( - V_83 ) ;
V_66 -> V_299 = V_295 ;
V_76 = V_2 -> V_7 -> V_296 ( V_66 , V_293 ) ;
if ( V_76 ) {
F_153 ( V_295 ) ;
V_66 -> V_299 = NULL ;
}
}
F_2 ( V_76 != 0 ||
( V_66 -> V_299 && V_66 -> V_299 -> V_300 ) ) ;
RETURN ( V_76 ) ;
}
int F_154 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
int V_76 ;
V_81 ;
F_2 ( V_66 -> V_264 ) ;
F_2 ( V_66 -> V_264 -> V_201 ) ;
V_2 = V_66 -> V_264 -> V_201 ;
F_2 ( V_2 -> V_7 -> V_301 ) ;
V_76 = V_2 -> V_7 -> V_301 ( V_66 ) ;
F_2 ( V_76 || V_66 -> V_299 -> V_302 ) ;
RETURN ( V_76 ) ;
}
void F_155 ( struct V_294 * V_295 )
{
struct V_1 * V_2 ;
unsigned int V_303 ;
V_81 ;
F_2 ( V_295 -> V_304 ) ;
F_2 ( V_295 -> V_304 -> V_201 ) ;
V_2 = V_295 -> V_304 -> V_201 ;
F_2 ( V_2 -> V_7 -> V_305 ) ;
V_303 = V_295 -> V_306 ;
V_2 -> V_7 -> V_305 ( V_295 ) ;
if ( V_303 )
F_153 ( V_295 ) ;
EXIT ;
}
void F_156 ( struct V_65 * V_66 )
{
struct V_191 * V_58 = V_66 -> V_264 ;
if ( V_58 != NULL )
F_33 ( & V_58 -> V_307 ) ;
}
void F_157 ( struct V_65 * V_66 )
{
struct V_191 * V_58 = V_66 -> V_264 ;
if ( V_58 == NULL )
return;
F_35 ( & V_58 -> V_307 ) ;
if ( F_36 ( & V_58 -> V_307 ) ) {
if ( V_58 -> V_201 -> V_7 -> V_308 )
V_58 -> V_201 -> V_7 -> V_308 ( V_58 ) ;
}
V_66 -> V_264 = NULL ;
}
void F_158 ( struct V_65 * V_66 )
{
struct V_191 * V_58 = V_66 -> V_264 ;
if ( V_58 == NULL )
return;
F_35 ( & V_58 -> V_307 ) ;
if ( V_58 -> V_201 -> V_7 -> V_309 )
V_58 -> V_201 -> V_7 -> V_309 ( V_58 ) ;
}
int F_94 ( struct V_65 * V_66 ,
struct V_310 * V_311 )
{
struct V_45 * V_58 ;
F_2 ( V_66 -> V_126 || V_66 -> V_127 ) ;
if ( ! V_66 -> V_137 )
return 0 ;
V_58 = V_66 -> V_82 ;
if ( V_58 -> V_63 -> V_312 )
return V_58 -> V_63 -> V_312 ( V_58 , V_66 , V_311 ) ;
return 0 ;
}
int F_159 ( struct V_65 * V_66 ,
struct V_310 * V_311 ,
int V_313 )
{
struct V_45 * V_58 ;
int V_76 ;
F_2 ( V_66 -> V_126 && ! V_66 -> V_127 ) ;
if ( ! V_66 -> V_137 )
return V_311 -> V_314 ;
V_58 = V_66 -> V_82 ;
if ( V_58 -> V_63 -> V_315 ) {
V_76 = V_58 -> V_63 -> V_315 ( V_58 , V_66 , V_311 ) ;
if ( V_76 < 0 )
return V_76 ;
}
return V_311 -> V_314 ;
}
int F_160 ( struct V_65 * V_66 ,
struct V_310 * V_311 )
{
struct V_45 * V_58 ;
int V_76 ;
F_2 ( ! V_66 -> V_126 && V_66 -> V_127 ) ;
if ( ! V_66 -> V_137 )
return 0 ;
V_58 = V_66 -> V_82 ;
if ( V_58 -> V_63 -> V_315 ) {
V_76 = V_58 -> V_63 -> V_315 ( V_58 , V_66 , V_311 ) ;
if ( V_76 < 0 )
return V_76 ;
}
if ( V_311 -> V_316 != V_311 -> V_314 ) {
F_8 ( L_74 ,
V_311 -> V_316 , V_311 -> V_314 ) ;
return - V_161 ;
}
return 0 ;
}
int F_161 ( void )
{
int V_317 ;
V_317 = V_318 ;
if ( V_317 > V_319 )
V_317 = V_319 ;
return F_162 ( V_317 ) ;
}
int F_163 ( struct V_162 * V_234 , int V_320 )
{
struct V_321 * V_322 ;
V_322 = F_133 ( V_234 , V_320 , 0 ) ;
V_322 -> V_323 = F_30 () ;
V_322 -> V_324 = F_31 () ;
V_322 -> V_325 = F_164 () ;
V_322 -> V_326 = F_165 () ;
V_322 -> V_327 = F_166 () ;
V_322 -> V_328 = ( V_234 -> V_241 [ V_320 ] - sizeof( * V_322 ) ) / 4 ;
F_167 ( V_329 ) ;
if ( V_322 -> V_328 > V_318 )
V_322 -> V_328 = V_318 ;
memcpy ( V_322 -> V_330 , F_168 () -> V_331 -> V_332 [ 0 ] ,
V_322 -> V_328 * sizeof( T_2 ) ) ;
F_169 ( V_329 ) ;
return 0 ;
}
int F_170 ( struct V_162 * V_234 , int V_320 , int V_333 )
{
struct V_321 * V_322 ;
int V_334 ;
V_322 = F_133 ( V_234 , V_320 , sizeof( * V_322 ) ) ;
if ( ! V_322 )
return - V_9 ;
if ( V_333 ) {
F_171 ( & V_322 -> V_323 ) ;
F_171 ( & V_322 -> V_324 ) ;
F_171 ( & V_322 -> V_325 ) ;
F_171 ( & V_322 -> V_326 ) ;
F_171 ( & V_322 -> V_327 ) ;
F_171 ( & V_322 -> V_328 ) ;
}
if ( V_322 -> V_328 > V_319 ) {
F_8 ( L_75 , V_322 -> V_328 ) ;
return - V_9 ;
}
if ( sizeof( * V_322 ) + V_322 -> V_328 * sizeof( T_2 ) >
V_234 -> V_241 [ V_320 ] ) {
F_8 ( L_76 ,
V_322 -> V_328 , V_234 -> V_241 [ V_320 ] ) ;
return - V_9 ;
}
if ( V_333 ) {
for ( V_334 = 0 ; V_334 < V_322 -> V_328 ; V_334 ++ )
F_171 ( & V_322 -> V_330 [ V_334 ] ) ;
}
return 0 ;
}
const char * F_56 ( struct V_46 * V_47 )
{
if ( ! V_47 || ! V_47 -> V_335 || ! V_47 -> V_335 -> V_197 )
return L_77 ;
if ( F_172 ( V_47 ) )
return L_78 ;
return F_124 ( & V_47 -> V_335 -> V_197 -> V_220 . V_221 . V_226 ) ;
}
int F_81 ( struct V_30 * V_28 )
{
switch ( F_173 ( V_28 -> V_34 ) ) {
case V_336 :
case V_337 :
return 1 ;
default:
return 0 ;
}
}
int F_174 ( void )
{
int V_76 ;
F_175 ( & V_10 ) ;
V_76 = F_176 () ;
if ( V_76 )
goto V_228;
V_76 = F_177 () ;
if ( V_76 )
goto V_338;
V_76 = F_178 () ;
if ( V_76 )
goto V_339;
V_76 = F_179 () ;
if ( V_76 )
goto V_340;
V_76 = F_180 () ;
if ( V_76 )
goto V_341;
V_76 = F_181 () ;
if ( V_76 )
goto V_342;
return 0 ;
V_342:
F_182 () ;
V_341:
F_183 () ;
V_340:
F_184 () ;
V_339:
F_185 () ;
V_338:
F_186 () ;
V_228:
return V_76 ;
}
void F_187 ( void )
{
F_188 () ;
F_182 () ;
F_183 () ;
F_184 () ;
F_185 () ;
F_186 () ;
}
