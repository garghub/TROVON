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
V_49 . V_56 = F_30 ( & V_58 , F_31 () ) ;
V_49 . V_57 = F_32 ( & V_58 , F_33 () ) ;
}
return V_47 -> V_52 -> V_6 -> V_53 ( V_47 , & V_49 ,
V_50 , V_51 ) ;
}
struct V_45 * F_34 ( struct V_45 * V_59 )
{
F_35 ( & V_59 -> V_60 ) ;
return V_59 ;
}
void F_36 ( struct V_45 * V_59 , int V_61 )
{
struct V_46 * V_47 = V_59 -> V_62 ;
F_2 ( V_47 ) ;
F_37 ( & V_59 -> V_60 ) ;
if ( ! F_38 ( & V_59 -> V_60 ) )
return;
V_47 -> V_52 -> V_6 -> V_63 ( V_47 , V_59 , V_61 ) ;
}
void F_39 ( struct V_45 * V_59 )
{
F_2 ( V_59 -> V_64 -> V_65 ) ;
V_59 -> V_64 -> V_65 ( V_59 , 0 ) ;
}
void F_40 ( struct V_45 * V_59 )
{
struct V_66 * V_67 , * V_68 ;
F_41 ( & V_59 -> V_69 ) ;
F_42 (req, next, &ctx->cc_req_list,
rq_ctx_chain) {
F_43 ( & V_67 -> V_70 ) ;
F_44 ( V_67 ) ;
}
F_45 ( & V_59 -> V_69 ) ;
}
int F_46 ( struct V_45 * V_59 , char * V_32 , int V_33 )
{
F_2 ( V_59 -> V_64 ) ;
if ( V_59 -> V_64 -> V_71 == NULL )
return 0 ;
return V_59 -> V_64 -> V_71 ( V_59 , V_32 , V_33 ) ;
}
static int F_47 ( struct V_72 * V_73 )
{
int V_74 = 0 ;
F_41 ( & V_73 -> V_75 ) ;
if ( V_73 -> V_76 &&
V_73 -> V_76 < F_48 () ) {
V_74 = 1 ;
V_73 -> V_76 = 0 ;
}
F_45 ( & V_73 -> V_75 ) ;
if ( ! V_74 )
return 0 ;
F_6 ( V_13 , L_22 ) ;
return F_49 ( V_73 , NULL , NULL ) ;
}
static int F_50 ( struct V_72 * V_73 ,
struct V_46 * * V_47 )
{
int V_77 ;
if ( F_4 ( V_73 -> V_76 ) ) {
V_77 = F_47 ( V_73 ) ;
if ( V_77 )
return V_77 ;
}
* V_47 = F_51 ( V_73 ) ;
if ( * V_47 == NULL ) {
F_8 ( L_23 ,
V_73 , F_52 ( V_73 -> V_78 ) ) ;
return - V_79 ;
}
if ( F_4 ( ( * V_47 ) -> V_80 ) ) {
F_8 ( L_24 , V_47 ) ;
F_53 ( * V_47 ) ;
return - V_79 ;
}
return 0 ;
}
int F_54 ( struct V_66 * V_67 )
{
struct V_72 * V_73 = V_67 -> V_81 ;
struct V_46 * V_47 ;
int V_77 ;
F_2 ( ! V_67 -> V_82 ) ;
F_2 ( V_73 ) ;
V_77 = F_50 ( V_73 , & V_47 ) ;
if ( V_77 )
return V_77 ;
V_67 -> V_82 = F_29 ( V_47 ) ;
F_53 ( V_47 ) ;
if ( ! V_67 -> V_82 ) {
F_8 ( L_25 , V_67 ) ;
return - V_83 ;
}
return 0 ;
}
void F_55 ( struct V_66 * V_67 , int V_61 )
{
F_2 ( V_67 ) ;
F_2 ( V_67 -> V_82 ) ;
if ( ! F_56 ( & V_67 -> V_70 ) ) {
F_41 ( & V_67 -> V_82 -> V_69 ) ;
F_43 ( & V_67 -> V_70 ) ;
F_45 ( & V_67 -> V_82 -> V_69 ) ;
}
F_36 ( V_67 -> V_82 , V_61 ) ;
V_67 -> V_82 = NULL ;
}
static
int F_57 ( struct V_66 * V_67 ,
struct V_45 * V_84 ,
struct V_45 * V_85 )
{
struct V_30 V_86 ;
char * V_87 = NULL ;
int V_88 ;
int V_77 = 0 ;
F_2 ( V_67 -> V_89 ) ;
F_2 ( V_67 -> V_90 ) ;
F_2 ( V_67 -> V_91 ) ;
F_6 ( V_13 , L_26
L_27 , V_67 ,
V_84 , V_84 -> V_92 . V_56 , F_58 ( V_84 -> V_62 ) ,
V_85 , V_85 -> V_92 . V_56 , F_58 ( V_85 -> V_62 ) ,
V_84 -> V_62 , V_84 -> V_62 -> V_52 -> V_5 ,
V_85 -> V_62 , V_85 -> V_62 -> V_52 -> V_5 ) ;
V_86 = V_67 -> V_93 ;
V_88 = V_67 -> V_90 ;
if ( V_88 != 0 ) {
F_59 ( V_87 , V_88 ) ;
if ( V_87 == NULL )
return - V_83 ;
memcpy ( V_87 , V_67 -> V_89 , V_88 ) ;
}
V_67 -> V_82 = V_84 ;
F_60 ( V_67 ) ;
F_61 ( V_67 ) ;
V_67 -> V_82 = V_85 ;
F_62 ( V_67 , 0 ) ;
if ( V_88 != 0 ) {
V_77 = F_63 ( V_67 , V_88 ) ;
if ( ! V_77 ) {
F_2 ( V_67 -> V_89 ) ;
memcpy ( V_67 -> V_89 , V_87 , V_88 ) ;
} else {
F_64 ( L_28 , V_77 ) ;
V_67 -> V_93 = V_86 ;
}
F_65 ( V_87 , V_88 ) ;
}
return V_77 ;
}
int F_66 ( struct V_66 * V_67 )
{
struct V_45 * V_84 = V_67 -> V_82 ;
struct V_45 * V_85 ;
int V_77 ;
F_2 ( V_84 ) ;
F_34 ( V_84 ) ;
F_55 ( V_67 , 0 ) ;
V_77 = F_54 ( V_67 ) ;
if ( F_4 ( V_77 ) ) {
F_2 ( ! V_67 -> V_82 ) ;
V_67 -> V_82 = V_84 ;
return V_77 ;
}
V_85 = V_67 -> V_82 ;
F_2 ( V_85 ) ;
if ( F_4 ( V_85 == V_84 &&
F_67 ( V_94 , & V_84 -> V_95 ) ) ) {
F_6 ( V_13 ,
L_29 ,
V_85 , V_85 -> V_95 ) ;
F_68 ( V_96 ) ;
F_69 ( V_97 ) ;
} else {
V_77 = F_57 ( V_67 , V_84 , V_85 ) ;
if ( V_77 ) {
F_55 ( V_67 , 0 ) ;
V_67 -> V_82 = V_84 ;
return V_77 ;
}
F_2 ( V_67 -> V_82 == V_85 ) ;
}
F_36 ( V_84 , 1 ) ;
return 0 ;
}
static
int F_70 ( struct V_45 * V_59 )
{
if ( F_71 ( V_59 ) )
return 1 ;
return 0 ;
}
static
int F_72 ( void * V_98 )
{
struct V_66 * V_67 = V_98 ;
int V_77 ;
F_73 ( V_67 -> V_89 , V_67 -> V_81 -> V_99 ) ;
V_77 = F_74 ( V_67 , 1 ) ;
if ( V_77 == 0 )
V_67 -> V_82 -> V_64 -> V_65 ( V_67 -> V_82 , 0 ) ;
return V_77 ;
}
static
void F_75 ( void * V_98 )
{
struct V_66 * V_67 = V_98 ;
F_41 ( & V_67 -> V_100 ) ;
V_67 -> V_101 = 1 ;
F_45 ( & V_67 -> V_100 ) ;
}
static
void F_76 ( struct V_66 * V_67 , struct V_45 * V_59 )
{
F_41 ( & V_59 -> V_69 ) ;
if ( ! F_56 ( & V_67 -> V_70 ) )
F_43 ( & V_67 -> V_70 ) ;
F_45 ( & V_59 -> V_69 ) ;
}
int F_77 ( struct V_66 * V_67 , long V_102 )
{
struct V_45 * V_59 = V_67 -> V_82 ;
struct V_46 * V_47 ;
struct V_103 V_104 ;
int V_77 ;
F_2 ( V_59 ) ;
if ( V_67 -> V_105 || V_67 -> V_106 )
return 0 ;
V_107:
V_77 = F_50 ( V_67 -> V_81 , & V_47 ) ;
if ( V_77 )
return V_77 ;
if ( V_47 -> V_54 . V_34 != V_67 -> V_93 . V_34 ) {
F_6 ( V_13 , L_30 ,
V_67 , V_67 -> V_93 . V_34 , V_47 -> V_54 . V_34 ) ;
F_76 ( V_67 , V_59 ) ;
F_66 ( V_67 ) ;
V_59 = V_67 -> V_82 ;
}
F_53 ( V_47 ) ;
if ( F_78 ( V_59 ) )
return 0 ;
if ( F_4 ( F_67 ( V_108 , & V_59 -> V_95 ) ) ) {
F_2 ( V_59 -> V_64 -> V_109 ) ;
V_59 -> V_64 -> V_109 ( V_59 ) ;
}
F_2 ( F_67 ( V_108 , & V_59 -> V_95 ) == 0 ) ;
F_2 ( V_59 -> V_64 -> V_110 ) ;
if ( V_59 -> V_64 -> V_110 ( V_59 ) == 0 ) {
F_76 ( V_67 , V_59 ) ;
return 0 ;
}
if ( F_4 ( F_67 ( V_111 , & V_59 -> V_95 ) ) ) {
F_41 ( & V_67 -> V_100 ) ;
V_67 -> V_112 = 1 ;
F_45 ( & V_67 -> V_100 ) ;
F_76 ( V_67 , V_59 ) ;
return - V_113 ;
}
if ( F_67 ( V_114 , & V_59 -> V_95 ) &&
F_4 ( V_67 -> V_89 ) &&
F_79 ( V_67 -> V_89 ) & V_115 ) {
F_76 ( V_67 , V_59 ) ;
return 0 ;
}
if ( F_4 ( F_67 ( V_94 , & V_59 -> V_95 ) ) ) {
F_76 ( V_67 , V_59 ) ;
if ( V_67 -> V_81 -> V_116 ) {
F_41 ( & V_67 -> V_100 ) ;
V_67 -> V_112 = 1 ;
F_45 ( & V_67 -> V_100 ) ;
return - V_117 ;
}
V_77 = F_66 ( V_67 ) ;
if ( V_77 ) {
F_2 ( V_59 == V_67 -> V_82 ) ;
F_8 ( L_31 ,
V_67 , V_59 , V_77 ) ;
F_41 ( & V_67 -> V_100 ) ;
V_67 -> V_112 = 1 ;
F_45 ( & V_67 -> V_100 ) ;
return V_77 ;
}
V_59 = V_67 -> V_82 ;
goto V_107;
}
F_41 ( & V_59 -> V_69 ) ;
if ( F_56 ( & V_67 -> V_70 ) )
F_80 ( & V_67 -> V_70 , & V_59 -> V_118 ) ;
F_45 ( & V_59 -> V_69 ) ;
if ( V_102 < 0 )
return - V_119 ;
F_2 ( V_67 -> V_120 == 0 ) ;
F_41 ( & V_67 -> V_100 ) ;
V_67 -> V_112 = 0 ;
V_67 -> V_121 = 0 ;
V_67 -> V_122 = 0 ;
V_67 -> V_123 = 0 ;
F_45 ( & V_67 -> V_100 ) ;
V_104 = F_81 ( V_102 * V_97 , F_72 ,
F_75 , V_67 ) ;
V_77 = F_82 ( V_67 -> V_124 , F_70 ( V_59 ) , & V_104 ) ;
if ( ! F_71 ( V_59 ) ) {
F_76 ( V_67 , V_59 ) ;
F_2 ( V_77 != 0 ) ;
return V_77 ;
}
goto V_107;
}
void F_62 ( struct V_66 * V_67 , int V_125 )
{
struct V_46 * V_47 ;
F_2 ( V_67 -> V_81 ) ;
F_2 ( V_67 -> V_82 ) ;
F_2 ( V_67 -> V_82 -> V_62 ) ;
F_2 ( V_67 -> V_126 == 0 || V_67 -> V_127 == 0 ) ;
switch ( V_125 ) {
case V_128 :
case V_129 :
case V_130 :
case V_131 :
V_67 -> V_126 = 1 ;
break;
case V_132 :
case V_133 :
V_67 -> V_127 = 1 ;
break;
case V_134 :
V_67 -> V_105 = 1 ;
break;
case V_135 :
V_67 -> V_106 = 1 ;
break;
case 0 :
F_2 ( V_67 -> V_105 == 0 ) ;
F_2 ( V_67 -> V_106 == 0 ) ;
V_67 -> V_136 = 0 ;
V_67 -> V_137 = 0 ;
break;
}
V_47 = V_67 -> V_82 -> V_62 ;
F_41 ( & V_47 -> V_138 ) ;
V_67 -> V_93 = V_47 -> V_54 ;
F_45 ( & V_47 -> V_138 ) ;
if ( F_4 ( V_67 -> V_105 ) )
F_83 ( & V_67 -> V_93 . V_34 , V_139 ) ;
else if ( F_4 ( V_67 -> V_106 ) )
F_83 ( & V_67 -> V_93 . V_34 , V_140 ) ;
if ( ( V_47 -> V_54 . V_55 & V_43 ) &&
( V_67 -> V_93 . V_34 != V_21 ) )
V_67 -> V_136 = 1 ;
if ( ( V_67 -> V_126 || V_67 -> V_127 ) &&
F_84 ( & V_67 -> V_93 ) )
V_67 -> V_137 = 1 ;
}
void F_85 ( struct V_66 * V_67 )
{
if ( F_86 ( V_67 -> V_93 . V_34 ) != V_141 )
return;
F_2 ( V_67 -> V_142 ) ;
if ( V_67 -> V_143 || ! V_67 -> V_144 )
return;
F_87 ( V_67 -> V_144 , V_67 -> V_145 ) ;
V_67 -> V_144 = NULL ;
V_67 -> V_145 = 0 ;
}
int F_88 ( struct V_72 * V_73 )
{
struct V_46 * V_47 ;
struct V_45 * V_59 ;
struct V_66 * V_67 = NULL ;
int V_77 ;
F_89 () ;
V_47 = F_51 ( V_73 ) ;
V_59 = F_29 ( V_47 ) ;
F_53 ( V_47 ) ;
if ( ! V_59 )
return - V_83 ;
if ( F_78 ( V_59 ) ||
V_59 -> V_64 -> V_110 ( V_59 ) == 0 ) {
F_36 ( V_59 , 1 ) ;
return 0 ;
}
if ( F_90 ( V_59 ) ) {
F_36 ( V_59 , 1 ) ;
return - V_79 ;
}
V_67 = F_91 ( V_146 ) ;
if ( ! V_67 )
return - V_83 ;
F_92 ( & V_67 -> V_100 ) ;
F_19 ( & V_67 -> V_147 , 10000 ) ;
F_93 ( & V_67 -> V_70 ) ;
F_94 ( & V_67 -> V_124 ) ;
F_94 ( & V_67 -> V_148 ) ;
V_67 -> V_81 = V_73 ;
V_67 -> V_93 = V_47 -> V_54 ;
V_67 -> V_82 = V_59 ;
V_77 = F_77 ( V_67 , 0 ) ;
F_2 ( F_56 ( & V_67 -> V_70 ) ) ;
F_36 ( V_67 -> V_82 , 1 ) ;
F_95 ( V_67 ) ;
return V_77 ;
}
int F_96 ( struct V_66 * V_67 )
{
struct V_45 * V_59 = V_67 -> V_82 ;
int V_77 = 0 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_67 -> V_144 || V_67 -> V_142 ) ;
if ( V_67 -> V_149 ) {
V_77 = F_97 ( V_67 , V_67 -> V_149 ) ;
if ( V_77 )
return V_77 ;
}
switch ( F_86 ( V_67 -> V_93 . V_34 ) ) {
case V_139 :
case V_150 :
case V_140 :
F_2 ( V_59 -> V_64 -> V_151 ) ;
V_77 = V_59 -> V_64 -> V_151 ( V_59 , V_67 ) ;
break;
case V_141 :
F_2 ( V_59 -> V_64 -> V_152 ) ;
V_77 = V_59 -> V_64 -> V_152 ( V_59 , V_67 ) ;
break;
default:
F_98 () ;
}
if ( V_77 == 0 ) {
F_2 ( V_67 -> V_153 ) ;
F_2 ( V_67 -> V_153 % 8 == 0 ) ;
F_2 ( V_67 -> V_153 <= V_67 -> V_145 ) ;
}
return V_77 ;
}
static int F_99 ( struct V_66 * V_67 )
{
struct V_45 * V_59 = V_67 -> V_82 ;
int V_77 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_67 -> V_154 ) ;
F_2 ( V_67 -> V_155 ) ;
F_2 ( V_67 -> V_156 == NULL ) ;
V_67 -> V_157 = 0 ;
V_77 = F_100 ( V_67 -> V_155 , V_67 -> V_158 ) ;
switch ( V_77 ) {
case 1 :
F_101 ( V_67 , V_159 ) ;
case 0 :
break;
default:
F_8 ( L_32 V_160 L_33 , V_67 -> V_161 ) ;
return - V_162 ;
}
if ( V_67 -> V_158 < sizeof( struct V_163 ) ) {
F_8 ( L_34 ,
V_67 -> V_158 ) ;
return - V_162 ;
}
if ( F_12 ( V_67 -> V_155 -> V_164 ) !=
F_12 ( V_67 -> V_93 . V_34 ) ) {
F_8 ( L_35 ,
F_12 ( V_67 -> V_155 -> V_164 ) ,
F_12 ( V_67 -> V_93 . V_34 ) ) ;
return - V_162 ;
}
switch ( F_86 ( V_67 -> V_93 . V_34 ) ) {
case V_139 :
case V_150 :
case V_140 :
F_2 ( V_59 -> V_64 -> V_165 ) ;
V_77 = V_59 -> V_64 -> V_165 ( V_59 , V_67 ) ;
break;
case V_141 :
F_2 ( V_59 -> V_64 -> V_166 ) ;
V_77 = V_59 -> V_64 -> V_166 ( V_59 , V_67 ) ;
break;
default:
F_98 () ;
}
F_2 ( V_77 || V_67 -> V_156 || V_67 -> V_122 ) ;
if ( F_12 ( V_67 -> V_93 . V_34 ) != V_167 &&
! V_67 -> V_105 )
V_67 -> V_157 = 0 ;
return V_77 ;
}
int F_102 ( struct V_66 * V_67 )
{
F_2 ( V_67 -> V_154 ) ;
F_2 ( V_67 -> V_155 == NULL ) ;
F_2 ( V_67 -> V_156 == NULL ) ;
F_2 ( V_67 -> V_168 + V_67 -> V_169 <= V_67 -> V_170 ) ;
if ( V_67 -> V_168 == 0 &&
( F_103 ( V_67 -> V_89 ) & V_171 ) ) {
F_8 ( L_36 ) ;
return - V_162 ;
}
if ( V_67 -> V_168 % 8 != 0 ) {
F_8 ( L_37 , V_67 -> V_168 ) ;
return - V_162 ;
}
V_67 -> V_155 = (struct V_163 * )
( V_67 -> V_154 + V_67 -> V_168 ) ;
V_67 -> V_158 = V_67 -> V_169 ;
return F_99 ( V_67 ) ;
}
int F_104 ( struct V_66 * V_67 ,
struct V_66 * * V_172 )
{
struct V_66 * V_173 ;
char * V_174 ;
int V_175 , V_176 ;
int V_77 ;
V_173 = F_91 ( V_146 ) ;
if ( V_173 == NULL )
return - V_83 ;
V_176 = V_67 -> V_169 ;
V_175 = F_105 ( V_176 ) ;
F_59 ( V_174 , V_175 ) ;
if ( V_174 == NULL )
GOTO ( V_177 , V_77 = - V_83 ) ;
F_41 ( & V_67 -> V_100 ) ;
if ( V_67 -> V_178 ) {
F_45 ( & V_67 -> V_100 ) ;
GOTO ( V_179 , V_77 = - V_12 ) ;
}
F_2 ( V_67 -> V_154 ) ;
F_2 ( V_67 -> V_155 == NULL ) ;
F_2 ( V_67 -> V_156 == NULL ) ;
if ( V_67 -> V_168 != 0 ) {
F_8 ( L_38 , V_67 -> V_168 ) ;
F_45 ( & V_67 -> V_100 ) ;
GOTO ( V_179 , V_77 = - V_162 ) ;
}
if ( V_67 -> V_169 != V_176 ) {
F_8 ( L_39 ,
V_176 , V_67 -> V_169 ) ;
F_45 ( & V_67 -> V_100 ) ;
GOTO ( V_179 , V_77 = - V_9 ) ;
}
if ( V_67 -> V_169 < sizeof( struct V_163 ) ) {
F_8 ( L_40 ,
V_67 -> V_169 ) ;
F_45 ( & V_67 -> V_100 ) ;
GOTO ( V_179 , V_77 = - V_12 ) ;
}
memcpy ( V_174 , V_67 -> V_154 , V_176 ) ;
F_45 ( & V_67 -> V_100 ) ;
F_92 ( & V_173 -> V_100 ) ;
V_173 -> V_82 = F_34 ( V_67 -> V_82 ) ;
V_173 -> V_93 = V_67 -> V_93 ;
V_173 -> V_154 = V_174 ;
V_173 -> V_170 = V_175 ;
V_173 -> V_155 = (struct V_163 * ) V_174 ;
V_173 -> V_158 = V_176 ;
V_173 -> V_180 = 1 ;
V_173 -> V_89 = V_67 -> V_89 ;
V_77 = F_99 ( V_173 ) ;
if ( V_77 ) {
F_106 ( V_181 , V_173 ,
L_41 , V_77 ) ;
GOTO ( V_182 , V_77 ) ;
}
F_2 ( V_173 -> V_156 ) ;
* V_172 = V_173 ;
return 0 ;
V_182:
F_36 ( V_173 -> V_82 , 1 ) ;
V_179:
F_65 ( V_174 , V_175 ) ;
V_177:
F_95 ( V_173 ) ;
return V_77 ;
}
void F_107 ( struct V_66 * V_173 )
{
F_2 ( V_173 -> V_154 ) ;
F_2 ( V_173 -> V_155 ) ;
F_2 ( V_173 -> V_156 ) ;
F_36 ( V_173 -> V_82 , 1 ) ;
F_65 ( V_173 -> V_154 , V_173 -> V_170 ) ;
F_95 ( V_173 ) ;
}
int F_108 ( void )
{
return F_109 ( & V_183 ) ;
}
static int F_110 ( struct V_46 * V_47 , T_4 V_184 ,
int V_185 , int V_186 )
{
struct V_1 * V_2 = V_47 -> V_52 ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_6 -> V_187 ) ;
return V_2 -> V_6 -> V_187 ( V_47 , V_184 , V_185 , V_186 ) ;
}
static void F_111 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_52 ;
F_112 ( & V_47 -> V_188 ) ;
F_112 ( & V_47 -> V_189 ) ;
F_2 ( V_2 -> V_6 -> V_190 ) ;
F_6 ( V_13 , L_42 , V_47 -> V_52 -> V_5 , V_47 ) ;
V_2 -> V_6 -> V_190 ( V_47 ) ;
F_113 ( V_2 ) ;
}
void F_114 ( struct V_46 * V_47 )
{
F_111 ( V_47 ) ;
}
static void F_115 ( struct V_46 * V_47 )
{
F_37 ( & V_47 -> V_188 ) ;
if ( V_47 -> V_52 -> V_6 -> V_191 ) {
V_47 -> V_52 -> V_6 -> V_191 ( V_47 ) ;
F_110 ( V_47 , - 1 , 1 , 1 ) ;
}
}
struct V_46 * F_116 ( struct V_46 * V_47 )
{
if ( V_47 )
F_35 ( & V_47 -> V_188 ) ;
return V_47 ;
}
void F_53 ( struct V_46 * V_47 )
{
if ( V_47 ) {
F_37 ( & V_47 -> V_188 ) ;
if ( F_38 ( & V_47 -> V_188 ) ) {
F_117 ( V_47 ) ;
F_111 ( V_47 ) ;
}
}
}
static
struct V_46 * F_118 ( struct V_72 * V_73 ,
struct V_192 * V_193 ,
struct V_30 * V_31 ,
enum V_194 V_195 )
{
struct V_1 * V_2 ;
struct V_46 * V_47 ;
char V_196 [ 32 ] ;
if ( V_193 ) {
F_2 ( V_73 -> V_197 == 1 ) ;
F_6 ( V_13 , L_43 ,
V_73 -> V_198 -> V_199 -> V_200 ,
V_73 -> V_198 -> V_201 ,
F_26 ( V_31 , V_196 , sizeof( V_196 ) ) ) ;
V_2 = F_119 ( V_193 -> V_202 ) ;
V_31 -> V_55 |= V_41 | V_42 ;
} else {
F_2 ( V_73 -> V_197 == 0 ) ;
F_6 ( V_13 , L_44 ,
V_73 -> V_198 -> V_199 -> V_200 ,
V_73 -> V_198 -> V_201 ,
F_26 ( V_31 , V_196 , sizeof( V_196 ) ) ) ;
V_2 = F_9 ( V_31 -> V_34 ) ;
if ( ! V_2 ) {
F_8 ( L_45 , V_31 -> V_34 ) ;
return NULL ;
}
}
V_47 = V_2 -> V_6 -> V_203 ( V_73 , V_193 , V_31 ) ;
if ( V_47 ) {
F_35 ( & V_47 -> V_188 ) ;
V_47 -> V_204 = V_195 ;
if ( V_47 -> V_205 && V_2 -> V_6 -> V_206 )
F_120 ( V_47 ) ;
} else {
F_113 ( V_2 ) ;
}
return V_47 ;
}
struct V_46 * F_51 ( struct V_72 * V_73 )
{
struct V_46 * V_47 ;
F_41 ( & V_73 -> V_75 ) ;
V_47 = F_116 ( V_73 -> V_207 ) ;
F_45 ( & V_73 -> V_75 ) ;
return V_47 ;
}
static void F_121 ( struct V_72 * V_73 ,
struct V_46 * V_47 )
{
struct V_46 * V_208 ;
F_37 ( & V_47 -> V_188 ) ;
F_41 ( & V_73 -> V_75 ) ;
V_208 = V_73 -> V_207 ;
V_73 -> V_207 = V_47 ;
F_45 ( & V_73 -> V_75 ) ;
if ( V_208 ) {
F_115 ( V_208 ) ;
F_53 ( V_208 ) ;
}
}
static inline
int F_122 ( struct V_30 * V_209 , struct V_30 * V_210 )
{
return ( memcmp ( V_209 , V_210 , sizeof( * V_209 ) ) == 0 ) ;
}
static inline
void F_123 ( struct V_30 * V_211 , struct V_30 * V_212 )
{
* V_211 = * V_212 ;
}
static void F_124 ( struct V_72 * V_73 ,
struct V_46 * V_47 ,
struct V_30 * V_31 )
{
char V_213 [ 32 ] , V_214 [ 32 ] ;
if ( V_47 -> V_54 . V_55 != V_31 -> V_55 )
F_6 ( V_13 , L_46 ,
F_27 ( V_47 -> V_54 . V_55 ,
V_213 , sizeof( V_213 ) ) ,
F_27 ( V_31 -> V_55 ,
V_214 , sizeof( V_214 ) ) ) ;
F_41 ( & V_47 -> V_138 ) ;
F_123 ( & V_47 -> V_54 , V_31 ) ;
F_45 ( & V_47 -> V_138 ) ;
}
int F_49 ( struct V_72 * V_73 ,
struct V_192 * V_193 ,
struct V_30 * V_28 )
{
struct V_215 * V_216 ;
struct V_30 V_31 ;
struct V_46 * V_47 , * V_217 ;
enum V_194 V_195 ;
char V_196 [ 24 ] ;
int V_77 = 0 ;
F_89 () ;
if ( V_73 == NULL )
return 0 ;
V_216 = V_73 -> V_218 ;
if ( V_193 == NULL ) {
struct V_219 * V_220 = & V_73 -> V_198 -> V_221 . V_222 ;
if ( V_220 -> V_223 == V_224 )
V_31 = V_220 -> V_225 ;
else
F_125 ( V_220 -> V_223 ,
V_220 -> V_226 ,
& V_220 -> V_227 ,
V_216 -> V_228 , & V_31 ) ;
V_195 = V_73 -> V_198 -> V_221 . V_222 . V_223 ;
} else {
V_31 = * V_28 ;
if ( V_31 . V_34 != V_21 )
V_31 . V_55 = V_41 |
V_42 ;
V_195 = F_126 ( V_73 -> V_198 ) ;
}
V_47 = F_51 ( V_73 ) ;
if ( V_47 ) {
char V_214 [ 24 ] ;
if ( F_122 ( & V_31 , & V_47 -> V_54 ) )
GOTO ( V_229 , V_77 ) ;
F_6 ( V_13 , L_47 ,
V_73 -> V_198 -> V_201 ,
F_127 ( & V_216 -> V_230 ) ,
F_26 ( & V_47 -> V_54 , V_196 , sizeof( V_196 ) ) ,
F_26 ( & V_31 , V_214 , sizeof( V_214 ) ) ) ;
if ( F_12 ( V_31 . V_34 ) ==
F_12 ( V_47 -> V_54 . V_34 ) &&
F_128 ( V_31 . V_34 ) ==
F_128 ( V_47 -> V_54 . V_34 ) ) {
F_124 ( V_73 , V_47 , & V_31 ) ;
GOTO ( V_229 , V_77 ) ;
}
} else if ( F_23 ( V_31 . V_34 ) !=
F_23 ( V_21 ) ) {
F_6 ( V_13 , L_48 ,
V_73 -> V_198 -> V_201 ,
F_127 ( & V_216 -> V_230 ) ,
F_129 ( V_216 -> V_228 ) ,
F_26 ( & V_31 , V_196 , sizeof( V_196 ) ) ) ;
}
F_17 ( & V_73 -> V_231 ) ;
V_217 = F_118 ( V_73 , V_193 , & V_31 , V_195 ) ;
if ( V_217 ) {
F_121 ( V_73 , V_217 ) ;
} else {
F_8 ( L_49 ,
V_73 -> V_198 -> V_201 ,
F_127 ( & V_216 -> V_230 ) ) ;
V_77 = - V_113 ;
}
F_20 ( & V_73 -> V_231 ) ;
V_229:
F_53 ( V_47 ) ;
return V_77 ;
}
void F_130 ( struct V_72 * V_73 )
{
if ( V_73 -> V_207 ) {
F_115 ( V_73 -> V_207 ) ;
F_53 ( V_73 -> V_207 ) ;
V_73 -> V_207 = NULL ;
}
}
static void F_131 ( struct V_72 * V_73 ,
T_4 V_184 , int V_185 , int V_186 )
{
struct V_46 * V_47 ;
if ( V_73 == NULL )
return;
V_47 = F_51 ( V_73 ) ;
if ( V_47 == NULL )
return;
F_110 ( V_47 , V_184 , V_185 , V_186 ) ;
F_53 ( V_47 ) ;
}
void F_132 ( struct V_72 * V_73 )
{
F_131 ( V_73 , 0 , 1 , 1 ) ;
}
void F_133 ( struct V_72 * V_73 )
{
F_131 ( V_73 , F_30 ( & V_58 , F_31 () ) ,
1 , 1 ) ;
}
void F_134 ( struct V_72 * V_73 )
{
F_131 ( V_73 , - 1 , 1 , 1 ) ;
}
int F_63 ( struct V_66 * V_67 , int V_232 )
{
struct V_45 * V_59 = V_67 -> V_82 ;
struct V_1 * V_2 ;
int V_77 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_59 -> V_62 -> V_52 ) ;
F_2 ( V_67 -> V_89 == NULL ) ;
F_37 ( & V_59 -> V_60 ) ;
V_2 = V_59 -> V_62 -> V_52 ;
V_77 = V_2 -> V_6 -> V_233 ( V_59 -> V_62 , V_67 , V_232 ) ;
if ( ! V_77 ) {
F_2 ( V_67 -> V_89 ) ;
F_2 ( V_67 -> V_144 || V_67 -> V_142 ) ;
if ( V_67 -> V_143 )
memset ( V_67 -> V_89 , 0 , V_232 ) ;
}
return V_77 ;
}
void F_60 ( struct V_66 * V_67 )
{
struct V_45 * V_59 = V_67 -> V_82 ;
struct V_1 * V_2 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_59 -> V_62 -> V_52 ) ;
F_37 ( & V_59 -> V_60 ) ;
if ( V_67 -> V_144 == NULL && V_67 -> V_142 == NULL )
return;
V_2 = V_59 -> V_62 -> V_52 ;
V_2 -> V_6 -> V_234 ( V_59 -> V_62 , V_67 ) ;
V_67 -> V_89 = NULL ;
}
void F_135 ( struct V_163 * V_235 ,
int V_236 , int V_237 )
{
void * V_212 , * V_211 ;
int V_238 , V_239 , V_240 ;
F_2 ( V_236 < V_235 -> V_241 ) ;
F_2 ( V_235 -> V_242 [ V_236 ] <= V_237 ) ;
if ( V_235 -> V_242 [ V_236 ] == V_237 )
return;
if ( V_236 == V_235 -> V_241 - 1 ) {
V_235 -> V_242 [ V_236 ] = V_237 ;
return;
}
V_238 = V_235 -> V_242 [ V_236 ] ;
V_212 = F_136 ( V_235 , V_236 + 1 , 0 ) ;
V_235 -> V_242 [ V_236 ] = V_237 ;
V_211 = F_136 ( V_235 , V_236 + 1 , 0 ) ;
V_235 -> V_242 [ V_236 ] = V_238 ;
F_2 ( V_235 -> V_243 == V_244 ) ;
V_239 = F_137 ( V_235 -> V_241 , V_235 -> V_242 ) ;
V_240 = V_239 - ( ( unsigned long ) V_212 - ( unsigned long ) V_235 ) ;
F_2 ( V_240 >= 0 ) ;
if ( V_240 )
memmove ( V_211 , V_212 , V_240 ) ;
V_235 -> V_242 [ V_236 ] = V_237 ;
}
int F_138 ( struct V_66 * V_67 ,
int V_236 , int V_237 )
{
struct V_45 * V_59 = V_67 -> V_82 ;
struct V_245 * V_246 ;
struct V_163 * V_235 = V_67 -> V_89 ;
F_2 ( V_59 ) ;
F_2 ( V_235 ) ;
F_2 ( V_235 -> V_241 > V_236 ) ;
F_2 ( V_235 -> V_242 [ V_236 ] <= V_237 ) ;
if ( V_235 -> V_242 [ V_236 ] == V_237 )
return 0 ;
V_246 = V_59 -> V_62 -> V_52 -> V_6 ;
F_2 ( V_246 -> V_247 ) ;
return V_246 -> V_247 ( V_59 -> V_62 , V_67 , V_236 , V_237 ) ;
}
int F_139 ( struct V_66 * V_67 , int V_232 )
{
struct V_45 * V_59 = V_67 -> V_82 ;
struct V_1 * V_2 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_59 -> V_62 -> V_52 ) ;
if ( V_67 -> V_154 )
return 0 ;
V_2 = V_59 -> V_62 -> V_52 ;
return V_2 -> V_6 -> V_248 ( V_59 -> V_62 , V_67 , V_232 ) ;
}
void F_61 ( struct V_66 * V_67 )
{
struct V_45 * V_59 = V_67 -> V_82 ;
struct V_1 * V_2 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_59 -> V_62 -> V_52 ) ;
F_37 ( & V_59 -> V_60 ) ;
if ( V_67 -> V_154 == NULL )
return;
F_2 ( V_67 -> V_170 ) ;
V_2 = V_59 -> V_62 -> V_52 ;
V_2 -> V_6 -> V_249 ( V_59 -> V_62 , V_67 ) ;
V_67 -> V_156 = NULL ;
}
int F_140 ( struct V_72 * V_73 ,
struct V_45 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_62 -> V_52 ;
if ( ! V_2 -> V_6 -> V_250 )
return 0 ;
return V_2 -> V_6 -> V_250 ( V_73 , V_59 -> V_62 , V_59 ) ;
}
int F_141 ( struct V_72 * V_73 ,
struct V_192 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_202 ;
if ( ! V_2 -> V_7 -> V_250 )
return 0 ;
return V_2 -> V_7 -> V_250 ( V_73 , V_59 ) ;
}
static int F_142 ( struct V_30 * exp ,
struct V_66 * V_67 )
{
struct V_30 * V_28 = & V_67 -> V_93 ;
if ( exp -> V_34 == V_251 || exp -> V_34 == V_28 -> V_34 )
return 1 ;
if ( ( V_67 -> V_105 || V_67 -> V_106 ) &&
F_12 ( exp -> V_34 ) ==
F_12 ( V_28 -> V_34 ) &&
F_128 ( exp -> V_34 ) == F_128 ( V_28 -> V_34 ) )
return 1 ;
return 0 ;
}
int F_143 ( struct V_252 * exp ,
struct V_66 * V_67 )
{
struct V_30 V_14 ;
if ( exp == NULL )
return 0 ;
if ( exp -> V_253 == NULL )
return 0 ;
if ( V_67 -> V_106 )
return 0 ;
F_41 ( & exp -> V_254 ) ;
if ( F_4 ( exp -> V_255 ) &&
F_142 ( & exp -> V_256 [ 1 ] , V_67 ) ) {
F_6 ( V_13 , L_50 , exp ,
exp -> V_257 . V_34 , exp -> V_256 [ 1 ] . V_34 ) ;
V_14 = exp -> V_256 [ 1 ] ;
exp -> V_256 [ 1 ] = exp -> V_256 [ 0 ] ;
exp -> V_258 [ 1 ] = exp -> V_258 [ 0 ] ;
exp -> V_256 [ 0 ] = exp -> V_257 ;
exp -> V_258 [ 0 ] = F_48 () +
V_259 ;
exp -> V_257 = V_14 ;
exp -> V_255 = 0 ;
F_2 ( exp -> V_260 == 1 ) ;
if ( V_67 -> V_261 &&
! ( V_67 -> V_105 &&
( V_67 -> V_262 || V_67 -> V_263 ||
V_67 -> V_264 ) ) ) {
F_45 ( & exp -> V_254 ) ;
F_6 ( V_13 , L_51 ,
V_67 -> V_261 , V_67 -> V_105 ,
V_67 -> V_262 , V_67 -> V_263 ,
V_67 -> V_264 ) ;
return 0 ;
}
exp -> V_260 = 0 ;
F_45 ( & exp -> V_254 ) ;
return F_49 ( exp -> V_253 ,
V_67 -> V_265 , & V_14 ) ;
}
if ( F_144 ( F_142 ( & exp -> V_257 , V_67 ) ) ) {
if ( ! V_67 -> V_261 || ! V_67 -> V_105 ||
( ! V_67 -> V_262 && ! V_67 -> V_263 &&
! V_67 -> V_264 ) ) {
F_45 ( & exp -> V_254 ) ;
return 0 ;
}
if ( exp -> V_255 ) {
F_2 ( exp -> V_260 ) ;
F_45 ( & exp -> V_254 ) ;
return 0 ;
}
if ( exp -> V_260 ) {
exp -> V_260 = 0 ;
F_6 ( V_13 , L_52 ,
exp , exp -> V_257 . V_34 ,
exp -> V_256 [ 0 ] . V_34 ,
exp -> V_256 [ 1 ] . V_34 ) ;
V_14 = exp -> V_257 ;
F_45 ( & exp -> V_254 ) ;
return F_49 ( exp -> V_253 ,
V_67 -> V_265 ,
& V_14 ) ;
} else {
F_6 ( V_13 , L_53
L_54 , exp , exp -> V_257 . V_34 ,
exp -> V_256 [ 0 ] . V_34 ,
exp -> V_256 [ 1 ] . V_34 ) ;
F_45 ( & exp -> V_254 ) ;
return F_141 ( exp -> V_253 ,
V_67 -> V_265 ) ;
}
}
if ( exp -> V_258 [ 0 ] ) {
if ( exp -> V_258 [ 0 ] >= F_48 () ) {
if ( F_142 ( & exp -> V_256 [ 0 ] , V_67 ) ) {
F_6 ( V_13 , L_55
L_56 V_266 L_57 , exp ,
exp -> V_257 . V_34 ,
exp -> V_256 [ 0 ] . V_34 ,
exp -> V_256 [ 1 ] . V_34 ,
exp -> V_258 [ 0 ] -
F_48 () ) ;
F_45 ( & exp -> V_254 ) ;
return 0 ;
}
} else {
F_6 ( V_13 , L_58 ) ;
exp -> V_258 [ 0 ] = 0 ;
}
F_6 ( V_13 , L_59 , exp ,
exp -> V_257 . V_34 ,
exp -> V_256 [ 0 ] . V_34 , exp -> V_256 [ 1 ] . V_34 ,
V_67 -> V_93 . V_34 ) ;
}
if ( exp -> V_255 == 0 && exp -> V_258 [ 1 ] ) {
if ( exp -> V_258 [ 1 ] >= F_48 () ) {
if ( F_142 ( & exp -> V_256 [ 1 ] , V_67 ) ) {
F_6 ( V_13 , L_55
L_60 V_266 L_57 , exp ,
exp -> V_257 . V_34 ,
exp -> V_256 [ 0 ] . V_34 ,
exp -> V_256 [ 1 ] . V_34 ,
exp -> V_258 [ 1 ] -
F_48 () ) ;
F_45 ( & exp -> V_254 ) ;
return 0 ;
}
} else {
F_6 ( V_13 , L_61 ) ;
exp -> V_258 [ 1 ] = 0 ;
}
F_6 ( V_13 , L_62 ,
exp , exp -> V_257 . V_34 ,
exp -> V_256 [ 0 ] . V_34 , exp -> V_256 [ 1 ] . V_34 ,
V_67 -> V_93 . V_34 ) ;
} else {
F_6 ( V_13 , L_63 ,
exp , exp -> V_257 . V_34 , exp -> V_256 [ 0 ] . V_34 ,
exp -> V_256 [ 1 ] . V_34 ) ;
}
F_45 ( & exp -> V_254 ) ;
F_64 ( L_64
L_65 ,
exp , exp -> V_267 -> V_201 ,
V_67 , V_67 -> V_261 , V_67 -> V_105 , V_67 -> V_106 ,
V_67 -> V_262 , V_67 -> V_263 , V_67 -> V_264 ,
V_67 -> V_93 . V_34 ,
exp -> V_257 . V_34 ,
exp -> V_256 [ 0 ] . V_34 ,
exp -> V_258 [ 0 ] ?
( unsigned long ) ( exp -> V_258 [ 0 ] -
F_48 () ) : 0 ,
exp -> V_256 [ 1 ] . V_34 ,
exp -> V_258 [ 1 ] ?
( unsigned long ) ( exp -> V_258 [ 1 ] -
F_48 () ) : 0 ) ;
return - V_79 ;
}
void F_145 ( struct V_268 * V_269 ,
struct V_270 * V_271 )
{
struct V_252 * exp ;
struct V_30 V_272 ;
F_2 ( V_269 ) ;
F_41 ( & V_269 -> V_273 ) ;
F_146 (exp, &obd->obd_exports, exp_obd_chain) {
if ( exp -> V_274 == NULL )
continue;
F_41 ( & exp -> V_254 ) ;
F_147 ( V_271 , exp -> V_275 ,
exp -> V_274 -> V_276 . V_277 ,
& V_272 ) ;
if ( exp -> V_255 ||
! F_122 ( & V_272 , & exp -> V_257 ) ) {
exp -> V_256 [ 1 ] = V_272 ;
exp -> V_258 [ 1 ] = 0 ;
exp -> V_255 = 1 ;
exp -> V_260 = 1 ;
F_6 ( V_13 , L_66 ,
exp , F_148 ( exp -> V_275 ) ,
exp -> V_257 . V_34 ,
exp -> V_256 [ 1 ] . V_34 ) ;
}
F_45 ( & exp -> V_254 ) ;
}
F_45 ( & V_269 -> V_273 ) ;
}
static int F_149 ( struct V_66 * V_67 , int V_278 )
{
if ( ! V_67 -> V_261 || V_278 == V_279 )
return V_278 ;
switch ( V_67 -> V_280 ) {
case V_281 :
if ( V_67 -> V_263 || V_67 -> V_264 ) {
F_106 ( V_282 , V_67 , L_67 ) ;
V_278 = V_279 ;
}
break;
case V_283 :
if ( ! V_67 -> V_263 ) {
F_106 ( V_282 , V_67 , L_68 ) ;
V_278 = V_279 ;
}
break;
case V_284 :
if ( ! V_67 -> V_264 ) {
F_106 ( V_282 , V_67 , L_69 ) ;
V_278 = V_279 ;
}
break;
case V_285 :
case V_224 :
if ( ! V_67 -> V_262 && ! V_67 -> V_263 &&
! V_67 -> V_264 ) {
F_106 ( V_282 , V_67 , L_70 ) ;
V_278 = V_279 ;
}
break;
case V_286 :
default:
F_106 ( V_282 , V_67 , L_71 , V_67 -> V_280 ) ;
V_278 = V_279 ;
}
return V_278 ;
}
int F_150 ( struct V_66 * V_67 )
{
struct V_1 * V_2 ;
struct V_163 * V_235 = V_67 -> V_144 ;
int V_77 ;
F_2 ( V_235 ) ;
F_2 ( V_67 -> V_89 == NULL ) ;
F_2 ( V_67 -> V_156 == NULL ) ;
F_2 ( V_67 -> V_265 == NULL ) ;
V_67 -> V_287 = 0 ;
V_77 = F_100 ( V_235 , V_67 -> V_153 ) ;
switch ( V_77 ) {
case 1 :
F_151 ( V_67 , V_159 ) ;
case 0 :
break;
default:
F_8 ( L_72 V_160 L_33 ,
F_152 ( V_67 -> V_288 ) , V_67 -> V_161 ) ;
return V_279 ;
}
V_67 -> V_93 . V_34 = F_153 ( V_235 -> V_164 ) ;
V_67 -> V_280 = V_286 ;
V_67 -> V_289 = - 1 ;
V_67 -> V_290 = - 1 ;
V_2 = F_9 ( V_67 -> V_93 . V_34 ) ;
if ( ! V_2 ) {
F_8 ( L_73 , V_67 -> V_93 . V_34 ) ;
return V_279 ;
}
F_2 ( V_2 -> V_7 -> V_291 ) ;
V_77 = V_2 -> V_7 -> V_291 ( V_67 ) ;
F_113 ( V_2 ) ;
F_2 ( V_67 -> V_89 || V_77 != V_292 ) ;
F_2 ( V_67 -> V_265 || V_77 == V_279 ) ;
if ( F_12 ( V_67 -> V_93 . V_34 ) != V_167 )
V_67 -> V_287 = 0 ;
V_77 = F_149 ( V_67 , V_77 ) ;
return V_77 ;
}
int F_154 ( struct V_66 * V_67 , int V_293 )
{
struct V_1 * V_2 ;
struct V_294 * V_295 ;
int V_77 ;
F_2 ( V_67 -> V_265 ) ;
F_2 ( V_67 -> V_265 -> V_202 ) ;
V_2 = V_67 -> V_265 -> V_202 ;
F_2 ( V_2 -> V_7 -> V_296 ) ;
V_77 = V_2 -> V_7 -> V_296 ( V_67 , V_293 ) ;
if ( F_4 ( V_77 == - V_83 ) ) {
struct V_297 * V_298 = V_67 -> V_299 -> V_300 ;
if ( V_298 -> V_301 -> V_302 <
V_293 + sizeof( struct V_294 ) ) {
F_8 ( L_74 ,
V_293 + sizeof( struct V_294 ) ,
V_298 -> V_301 -> V_302 ) ;
return - V_83 ;
}
V_295 = F_155 ( V_298 ) ;
if ( V_295 == NULL )
return - V_83 ;
V_67 -> V_303 = V_295 ;
V_77 = V_2 -> V_7 -> V_296 ( V_67 , V_293 ) ;
if ( V_77 ) {
F_156 ( V_295 ) ;
V_67 -> V_303 = NULL ;
}
}
F_2 ( V_77 != 0 ||
( V_67 -> V_303 && V_67 -> V_303 -> V_304 ) ) ;
return V_77 ;
}
int F_157 ( struct V_66 * V_67 )
{
struct V_1 * V_2 ;
int V_77 ;
F_2 ( V_67 -> V_265 ) ;
F_2 ( V_67 -> V_265 -> V_202 ) ;
V_2 = V_67 -> V_265 -> V_202 ;
F_2 ( V_2 -> V_7 -> V_305 ) ;
V_77 = V_2 -> V_7 -> V_305 ( V_67 ) ;
F_2 ( V_77 || V_67 -> V_303 -> V_306 ) ;
return V_77 ;
}
void F_158 ( struct V_294 * V_295 )
{
struct V_1 * V_2 ;
unsigned int V_307 ;
F_2 ( V_295 -> V_308 ) ;
F_2 ( V_295 -> V_308 -> V_202 ) ;
V_2 = V_295 -> V_308 -> V_202 ;
F_2 ( V_2 -> V_7 -> V_309 ) ;
V_307 = V_295 -> V_310 ;
V_2 -> V_7 -> V_309 ( V_295 ) ;
if ( V_307 )
F_156 ( V_295 ) ;
}
void F_159 ( struct V_66 * V_67 )
{
struct V_192 * V_59 = V_67 -> V_265 ;
if ( V_59 != NULL )
F_35 ( & V_59 -> V_311 ) ;
}
void F_160 ( struct V_66 * V_67 )
{
struct V_192 * V_59 = V_67 -> V_265 ;
if ( V_59 == NULL )
return;
F_37 ( & V_59 -> V_311 ) ;
if ( F_38 ( & V_59 -> V_311 ) ) {
if ( V_59 -> V_202 -> V_7 -> V_312 )
V_59 -> V_202 -> V_7 -> V_312 ( V_59 ) ;
}
V_67 -> V_265 = NULL ;
}
void F_161 ( struct V_66 * V_67 )
{
struct V_192 * V_59 = V_67 -> V_265 ;
if ( V_59 == NULL )
return;
F_37 ( & V_59 -> V_311 ) ;
if ( V_59 -> V_202 -> V_7 -> V_313 )
V_59 -> V_202 -> V_7 -> V_313 ( V_59 ) ;
}
int F_97 ( struct V_66 * V_67 ,
struct V_314 * V_315 )
{
struct V_45 * V_59 ;
F_2 ( V_67 -> V_126 || V_67 -> V_127 ) ;
if ( ! V_67 -> V_137 )
return 0 ;
V_59 = V_67 -> V_82 ;
if ( V_59 -> V_64 -> V_316 )
return V_59 -> V_64 -> V_316 ( V_59 , V_67 , V_315 ) ;
return 0 ;
}
int F_162 ( struct V_66 * V_67 ,
struct V_314 * V_315 ,
int V_317 )
{
struct V_45 * V_59 ;
int V_77 ;
F_2 ( V_67 -> V_126 && ! V_67 -> V_127 ) ;
if ( ! V_67 -> V_137 )
return V_315 -> V_318 ;
V_59 = V_67 -> V_82 ;
if ( V_59 -> V_64 -> V_319 ) {
V_77 = V_59 -> V_64 -> V_319 ( V_59 , V_67 , V_315 ) ;
if ( V_77 < 0 )
return V_77 ;
}
return V_315 -> V_318 ;
}
int F_163 ( struct V_66 * V_67 ,
struct V_314 * V_315 )
{
struct V_45 * V_59 ;
int V_77 ;
F_2 ( ! V_67 -> V_126 && V_67 -> V_127 ) ;
if ( ! V_67 -> V_137 )
return 0 ;
V_59 = V_67 -> V_82 ;
if ( V_59 -> V_64 -> V_319 ) {
V_77 = V_59 -> V_64 -> V_319 ( V_59 , V_67 , V_315 ) ;
if ( V_77 < 0 )
return V_77 ;
}
if ( V_315 -> V_320 != V_315 -> V_318 ) {
F_8 ( L_75 ,
V_315 -> V_320 , V_315 -> V_318 ) ;
return - V_162 ;
}
return 0 ;
}
int F_164 ( void )
{
int V_321 ;
V_321 = V_322 ;
if ( V_321 > V_323 )
V_321 = V_323 ;
return F_165 ( V_321 ) ;
}
int F_166 ( struct V_163 * V_235 , int V_324 )
{
struct V_325 * V_326 ;
V_326 = F_136 ( V_235 , V_324 , 0 ) ;
V_326 -> V_327 = F_30 ( & V_58 , F_31 () ) ;
V_326 -> V_328 = F_32 ( & V_58 , F_33 () ) ;
V_326 -> V_329 = F_30 ( & V_58 , F_167 () ) ;
V_326 -> V_330 = F_32 ( & V_58 , F_168 () ) ;
V_326 -> V_331 = F_169 () ;
V_326 -> V_332 = ( V_235 -> V_242 [ V_324 ] - sizeof( * V_326 ) ) / 4 ;
F_170 ( V_333 ) ;
if ( V_326 -> V_332 > V_322 )
V_326 -> V_332 = V_322 ;
memcpy ( V_326 -> V_334 , F_171 () -> V_335 -> V_336 [ 0 ] ,
V_326 -> V_332 * sizeof( T_2 ) ) ;
F_172 ( V_333 ) ;
return 0 ;
}
int F_173 ( struct V_163 * V_235 , int V_324 , int V_337 )
{
struct V_325 * V_326 ;
int V_338 ;
V_326 = F_136 ( V_235 , V_324 , sizeof( * V_326 ) ) ;
if ( ! V_326 )
return - V_9 ;
if ( V_337 ) {
F_174 ( & V_326 -> V_327 ) ;
F_174 ( & V_326 -> V_328 ) ;
F_174 ( & V_326 -> V_329 ) ;
F_174 ( & V_326 -> V_330 ) ;
F_174 ( & V_326 -> V_331 ) ;
F_174 ( & V_326 -> V_332 ) ;
}
if ( V_326 -> V_332 > V_323 ) {
F_8 ( L_76 , V_326 -> V_332 ) ;
return - V_9 ;
}
if ( sizeof( * V_326 ) + V_326 -> V_332 * sizeof( T_2 ) >
V_235 -> V_242 [ V_324 ] ) {
F_8 ( L_77 ,
V_326 -> V_332 , V_235 -> V_242 [ V_324 ] ) ;
return - V_9 ;
}
if ( V_337 ) {
for ( V_338 = 0 ; V_338 < V_326 -> V_332 ; V_338 ++ )
F_174 ( & V_326 -> V_334 [ V_338 ] ) ;
}
return 0 ;
}
const char * F_58 ( struct V_46 * V_47 )
{
if ( ! V_47 || ! V_47 -> V_339 || ! V_47 -> V_339 -> V_198 )
return L_78 ;
if ( F_175 ( V_47 ) )
return L_79 ;
return F_127 ( & V_47 -> V_339 -> V_198 -> V_221 . V_222 . V_227 ) ;
}
int F_84 ( struct V_30 * V_28 )
{
switch ( F_176 ( V_28 -> V_34 ) ) {
case V_340 :
case V_341 :
return 1 ;
default:
return 0 ;
}
}
int F_177 ( void )
{
int V_77 ;
F_178 ( & V_10 ) ;
V_77 = F_179 () ;
if ( V_77 )
goto V_229;
V_77 = F_180 () ;
if ( V_77 )
goto V_342;
V_77 = F_181 () ;
if ( V_77 )
goto V_343;
V_77 = F_182 () ;
if ( V_77 )
goto V_344;
V_77 = F_183 () ;
if ( V_77 )
goto V_345;
V_77 = F_184 () ;
if ( V_77 )
goto V_346;
return 0 ;
V_346:
F_185 () ;
V_345:
F_186 () ;
V_344:
F_187 () ;
V_343:
F_188 () ;
V_342:
F_189 () ;
V_229:
return V_77 ;
}
void F_190 ( void )
{
F_191 () ;
F_185 () ;
F_186 () ;
F_187 () ;
F_188 () ;
F_189 () ;
}
