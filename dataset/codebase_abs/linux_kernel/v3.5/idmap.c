void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
}
static void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_6 &= ~ V_7 ;
F_3 ( V_2 -> V_4 -> V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_6 &= ~ V_9 ;
F_3 ( V_2 -> V_5 -> V_8 ) ;
}
static bool F_5 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_3 * V_12 = V_2 -> V_4 ;
T_1 V_13 ;
if ( ! ( V_2 -> V_6 & V_7 ) )
return false ;
if ( F_6 ( V_11 , V_12 -> V_8 , V_12 -> V_14 , & V_13 ) == 0 ) {
V_2 -> V_13 = V_13 ;
V_2 -> V_6 |= V_15 ;
}
return true ;
}
static bool F_7 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_3 * V_16 = V_2 -> V_5 ;
T_1 V_17 ;
if ( ! ( V_2 -> V_6 & V_9 ) )
return false ;
if ( F_8 ( V_11 , V_16 -> V_8 , V_16 -> V_14 , & V_17 ) == 0 ) {
V_2 -> V_17 = V_17 ;
V_2 -> V_6 |= V_18 ;
}
return true ;
}
void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 & V_7 )
F_2 ( V_2 ) ;
if ( V_2 -> V_6 & V_9 )
F_4 ( V_2 ) ;
}
void F_10 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
if ( F_5 ( V_11 , V_2 ) )
F_2 ( V_2 ) ;
if ( F_7 ( V_11 , V_2 ) )
F_4 ( V_2 ) ;
}
static int F_11 ( const char * V_19 , T_2 V_20 , T_1 * V_21 )
{
unsigned long V_22 ;
char V_23 [ 16 ] ;
if ( memchr ( V_19 , '@' , V_20 ) != NULL || V_20 >= sizeof( V_23 ) )
return 0 ;
memcpy ( V_23 , V_19 , V_20 ) ;
V_23 [ V_20 ] = '\0' ;
if ( F_12 ( V_23 , 0 , & V_22 ) != 0 )
return 0 ;
* V_21 = V_22 ;
return 1 ;
}
static int F_13 ( T_1 V_24 , char * V_23 , T_2 V_25 )
{
return snprintf ( V_23 , V_25 , L_1 , V_24 ) ;
}
static int F_14 ( void )
{
struct V_26 * V_26 ;
struct V_27 * V_28 ;
int V_29 = 0 ;
F_15 ( V_30 L_2 ,
V_31 . V_19 ) ;
V_26 = F_16 ( NULL ) ;
if ( ! V_26 )
return - V_32 ;
V_28 = F_17 ( & V_33 , L_3 , 0 , 0 , V_26 ,
( V_34 & ~ V_35 ) |
V_36 | V_37 ,
V_38 ) ;
if ( F_18 ( V_28 ) ) {
V_29 = F_19 ( V_28 ) ;
goto V_39;
}
V_29 = F_20 ( V_28 , NULL , 0 , NULL , NULL ) ;
if ( V_29 < 0 )
goto V_40;
V_29 = F_21 ( & V_31 ) ;
if ( V_29 < 0 )
goto V_40;
F_22 ( V_41 , & V_28 -> V_42 ) ;
V_26 -> V_43 = V_28 ;
V_26 -> V_44 = V_45 ;
V_46 = V_26 ;
return 0 ;
V_40:
F_23 ( V_28 ) ;
V_39:
F_24 ( V_26 ) ;
return V_29 ;
}
static void F_25 ( void )
{
F_26 ( V_46 -> V_43 ) ;
F_27 ( & V_31 ) ;
F_24 ( V_46 ) ;
}
static T_3 F_28 ( const char * V_19 , T_2 V_20 ,
const char * type , T_2 V_47 , char * * V_48 )
{
char * V_49 ;
T_2 V_50 = V_47 + V_20 + 2 ;
* V_48 = F_29 ( V_50 , V_51 ) ;
if ( ! * V_48 )
return - V_32 ;
V_49 = * V_48 ;
memcpy ( V_49 , type , V_47 ) ;
V_49 += V_47 ;
* V_49 ++ = ':' ;
memcpy ( V_49 , V_19 , V_20 ) ;
V_49 += V_20 ;
* V_49 = '\0' ;
return V_50 ;
}
static T_3 F_30 ( struct V_52 * V_52 ,
const char * V_19 , T_2 V_20 ,
const char * type , void * V_8 ,
T_2 V_53 , struct V_54 * V_54 )
{
const struct V_26 * V_55 ;
struct V_27 * V_56 ;
char * V_48 ;
struct V_57 * V_58 ;
T_3 V_29 ;
V_29 = F_28 ( V_19 , V_20 , type , strlen ( type ) , & V_48 ) ;
if ( V_29 <= 0 )
goto V_59;
V_55 = F_31 ( V_46 ) ;
if ( V_54 )
V_56 = F_32 ( V_52 , V_48 , L_4 , 0 , V_54 ) ;
else
V_56 = F_33 ( & V_31 , V_48 , L_4 ) ;
F_34 ( V_55 ) ;
F_3 ( V_48 ) ;
if ( F_18 ( V_56 ) ) {
V_29 = F_19 ( V_56 ) ;
goto V_59;
}
F_35 () ;
V_56 -> V_60 |= V_36 ;
V_29 = F_36 ( V_56 ) ;
if ( V_29 < 0 )
goto V_61;
V_58 = F_37 ( V_56 -> V_58 . V_8 ) ;
if ( F_38 ( V_58 ) ) {
V_29 = F_19 ( V_58 ) ;
goto V_61;
}
V_29 = V_58 -> V_62 ;
if ( V_29 > 0 && V_29 <= V_53 )
memcpy ( V_8 , V_58 -> V_8 , V_29 ) ;
else
V_29 = - V_63 ;
V_61:
F_39 () ;
F_23 ( V_56 ) ;
V_59:
return V_29 ;
}
static T_3 F_40 ( const char * V_19 , T_2 V_20 ,
const char * type , void * V_8 ,
T_2 V_53 , struct V_54 * V_54 )
{
T_3 V_29 = F_30 ( & V_31 ,
V_19 , V_20 , type , V_8 ,
V_53 , NULL ) ;
if ( V_29 < 0 ) {
F_41 ( & V_54 -> V_64 ) ;
V_29 = F_30 ( & V_65 ,
V_19 , V_20 , type , V_8 ,
V_53 , V_54 ) ;
F_42 ( & V_54 -> V_64 ) ;
}
return V_29 ;
}
static T_3 F_43 ( T_1 V_24 , const char * type , char * V_23 ,
T_2 V_25 , struct V_54 * V_54 )
{
char V_66 [ V_67 ] ;
int V_68 ;
T_3 V_29 ;
V_68 = snprintf ( V_66 , sizeof( V_66 ) , L_1 , V_24 ) ;
V_29 = F_40 ( V_66 , V_68 , type , V_23 , V_25 , V_54 ) ;
if ( V_29 < 0 )
return - V_63 ;
return V_29 ;
}
static int F_44 ( const char * V_19 , T_2 V_20 , const char * type ,
T_1 * V_24 , struct V_54 * V_54 )
{
char V_66 [ V_67 ] ;
long V_69 ;
T_3 V_53 ;
int V_29 = 0 ;
V_53 = F_40 ( V_19 , V_20 , type , V_66 , V_67 , V_54 ) ;
if ( V_53 <= 0 ) {
V_29 = - V_63 ;
} else {
V_29 = F_45 ( V_66 , 10 , & V_69 ) ;
* V_24 = ( T_1 ) V_69 ;
}
return V_29 ;
}
static void F_46 ( struct V_70 * V_71 )
{
if ( V_71 -> V_72 )
F_47 ( V_71 -> V_72 ) ;
}
static int F_48 ( struct V_72 * V_73 ,
struct V_54 * V_54 ,
struct V_70 * V_71 )
{
struct V_72 * V_72 ;
V_72 = F_49 ( V_73 , L_5 , V_54 , V_71 ) ;
if ( F_18 ( V_72 ) )
return F_19 ( V_72 ) ;
V_71 -> V_72 = V_72 ;
return 0 ;
}
static void F_50 ( struct V_74 * V_75 ,
struct V_70 * V_71 )
{
struct V_76 * V_76 = V_75 -> V_77 ;
struct V_78 * V_79 ;
V_79 = F_51 ( V_76 ) ;
if ( V_79 ) {
F_46 ( V_71 ) ;
F_52 ( V_76 ) ;
}
}
static int F_53 ( struct V_74 * V_75 ,
struct V_54 * V_54 ,
struct V_70 * V_71 )
{
struct V_76 * V_76 = V_75 -> V_77 ;
struct V_78 * V_79 ;
int V_80 = 0 ;
V_79 = F_51 ( V_76 ) ;
if ( V_79 ) {
if ( V_75 -> V_81 -> V_82 )
V_80 = F_48 ( V_75 -> V_81 -> V_82 ,
V_54 , V_71 ) ;
F_52 ( V_76 ) ;
}
return V_80 ;
}
int
F_54 ( struct V_74 * V_75 )
{
struct V_54 * V_54 ;
struct V_70 * V_71 ;
int error ;
F_55 ( V_75 -> V_83 != NULL ) ;
V_54 = F_56 ( sizeof( * V_54 ) , V_51 ) ;
if ( V_54 == NULL )
return - V_32 ;
V_71 = F_57 ( & V_84 , 0 ) ;
if ( F_18 ( V_71 ) ) {
error = F_19 ( V_71 ) ;
F_3 ( V_54 ) ;
return error ;
}
error = F_53 ( V_75 , V_54 , V_71 ) ;
if ( error ) {
F_58 ( V_71 ) ;
F_3 ( V_54 ) ;
return error ;
}
V_54 -> V_85 = V_71 ;
F_59 ( & V_54 -> V_64 ) ;
V_75 -> V_83 = V_54 ;
return 0 ;
}
void
F_60 ( struct V_74 * V_75 )
{
struct V_54 * V_54 = V_75 -> V_83 ;
if ( ! V_54 )
return;
F_50 ( V_75 , V_54 -> V_85 ) ;
F_58 ( V_54 -> V_85 ) ;
V_75 -> V_83 = NULL ;
F_3 ( V_54 ) ;
}
static int F_61 ( struct V_74 * V_75 , unsigned long V_86 ,
struct V_78 * V_87 )
{
int V_80 = 0 ;
switch ( V_86 ) {
case V_88 :
F_55 ( V_75 -> V_81 -> V_82 == NULL ) ;
V_80 = F_48 ( V_75 -> V_81 -> V_82 ,
V_75 -> V_83 ,
V_75 -> V_83 -> V_85 ) ;
break;
case V_89 :
if ( V_75 -> V_83 -> V_85 ) {
struct V_72 * V_90 ;
V_90 = V_75 -> V_83 -> V_85 -> V_72 -> V_91 ;
F_46 ( V_75 -> V_83 -> V_85 ) ;
if ( F_62 ( V_90 ) )
F_15 ( V_92 L_6
L_7 , V_93 ) ;
}
break;
default:
F_15 ( V_92 L_8 , V_93 ,
V_86 ) ;
return - V_94 ;
}
return V_80 ;
}
static struct V_74 * F_63 ( struct V_76 * V_76 , int V_86 )
{
struct V_95 * V_96 = F_64 ( V_76 , V_97 ) ;
struct V_72 * V_82 ;
struct V_74 * V_75 ;
int V_80 ;
V_98:
F_65 ( & V_96 -> V_99 ) ;
F_66 (clp, &nn->nfs_client_list, cl_share_link) {
if ( V_75 -> V_100 == V_101 ) {
F_67 ( & V_75 -> V_102 ) ;
F_68 ( & V_96 -> V_99 ) ;
V_80 = F_69 ( V_75 ) ;
F_70 ( V_75 ) ;
if ( V_80 )
return NULL ;
goto V_98;
}
if ( V_75 -> V_100 < 0 )
continue;
F_71 () ;
if ( V_75 -> V_103 != & V_104 )
continue;
V_82 = V_75 -> V_83 -> V_85 -> V_72 ;
if ( ( ( V_86 == V_88 ) && V_82 ) ||
( ( V_86 == V_89 ) && ! V_82 ) )
continue;
F_67 ( & V_75 -> V_102 ) ;
F_68 ( & V_96 -> V_99 ) ;
return V_75 ;
}
F_68 ( & V_96 -> V_99 ) ;
return NULL ;
}
static int F_72 ( struct V_105 * V_106 , unsigned long V_86 ,
void * V_107 )
{
struct V_78 * V_87 = V_107 ;
struct V_74 * V_75 ;
int error = 0 ;
if ( ! F_73 ( V_108 ) )
return 0 ;
while ( ( V_75 = F_63 ( V_87 -> V_109 , V_86 ) ) ) {
error = F_61 ( V_75 , V_86 , V_87 ) ;
F_70 ( V_75 ) ;
if ( error )
break;
}
F_74 ( V_108 ) ;
return error ;
}
int F_75 ( void )
{
int V_29 ;
V_29 = F_14 () ;
if ( V_29 != 0 )
goto V_59;
V_29 = F_76 ( & V_110 ) ;
if ( V_29 != 0 )
F_25 () ;
V_59:
return V_29 ;
}
void F_77 ( void )
{
F_78 ( & V_110 ) ;
F_25 () ;
}
static int F_79 ( char * V_48 , struct V_111 * V_112 ,
struct V_113 * V_114 )
{
T_4 V_115 ;
int V_116 , V_29 ;
memset ( V_112 , 0 , sizeof( * V_112 ) ) ;
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
V_112 -> V_117 = V_118 ;
V_116 = F_80 ( V_48 , V_119 , & V_115 ) ;
switch ( V_116 ) {
case V_120 :
V_112 -> V_117 = V_121 ;
case V_122 :
V_112 -> V_123 = V_124 ;
V_29 = F_81 ( V_112 -> V_125 , & V_115 , V_126 ) ;
break;
case V_127 :
V_112 -> V_117 = V_121 ;
case V_128 :
V_112 -> V_123 = V_129 ;
V_29 = F_82 ( & V_115 , & V_112 -> V_130 ) ;
break;
default:
V_29 = - V_63 ;
goto V_59;
}
V_114 -> V_8 = V_112 ;
V_114 -> V_14 = sizeof( struct V_111 ) ;
V_59:
return V_29 ;
}
static int F_83 ( struct V_131 * V_132 ,
const char * V_133 ,
void * V_134 )
{
struct V_113 * V_114 ;
struct V_111 * V_112 ;
struct V_54 * V_54 = (struct V_54 * ) V_134 ;
struct V_27 * V_27 = V_132 -> V_27 ;
int V_29 = - V_32 ;
V_114 = F_29 ( sizeof( * V_114 ) , V_51 ) ;
if ( ! V_114 )
goto V_135;
V_112 = F_29 ( sizeof( * V_112 ) , V_51 ) ;
if ( ! V_112 )
goto V_136;
V_29 = F_79 ( V_27 -> V_137 , V_112 , V_114 ) ;
if ( V_29 < 0 )
goto V_138;
V_54 -> V_139 = V_132 ;
V_29 = F_84 ( V_54 -> V_85 , V_114 ) ;
if ( V_29 < 0 )
goto V_138;
return V_29 ;
V_138:
F_3 ( V_112 ) ;
V_136:
F_3 ( V_114 ) ;
V_135:
F_26 ( V_132 -> V_27 ) ;
F_26 ( V_132 -> V_140 ) ;
return V_29 ;
}
static int F_85 ( struct V_27 * V_27 , struct V_27 * V_140 , char * V_8 )
{
return F_20 ( V_27 , V_8 , strlen ( V_8 ) + 1 ,
V_46 -> V_43 ,
V_140 ) ;
}
static int F_86 ( struct V_111 * V_112 , struct V_27 * V_27 , struct V_27 * V_140 )
{
char V_66 [ V_67 ] ;
int V_29 = - V_63 ;
switch ( V_112 -> V_123 ) {
case V_124 :
sprintf ( V_66 , L_9 , V_112 -> V_130 ) ;
V_29 = F_85 ( V_27 , V_140 , V_66 ) ;
break;
case V_129 :
V_29 = F_85 ( V_27 , V_140 , V_112 -> V_125 ) ;
break;
}
return V_29 ;
}
static T_3
F_87 ( struct V_141 * V_142 , const char T_5 * V_143 , T_2 V_144 )
{
struct V_145 * V_146 = F_88 ( V_142 -> V_147 . V_72 -> V_148 ) ;
struct V_54 * V_54 = (struct V_54 * ) V_146 -> V_149 ;
struct V_131 * V_132 = V_54 -> V_139 ;
struct V_111 V_112 ;
T_2 V_150 ;
int V_29 ;
if ( V_144 != sizeof( V_112 ) ) {
V_29 = - V_151 ;
goto V_59;
}
if ( F_89 ( & V_112 , V_143 , V_144 ) != 0 ) {
V_29 = - V_152 ;
goto V_59;
}
if ( ! ( V_112 . V_153 & V_154 ) ) {
V_29 = V_144 ;
F_90 ( V_54 -> V_139 , - V_155 ) ;
goto V_156;
}
V_150 = F_91 ( V_112 . V_125 , V_126 ) ;
if ( V_150 == 0 || V_150 == V_126 ) {
V_29 = - V_63 ;
goto V_59;
}
V_29 = F_86 ( & V_112 , V_132 -> V_27 , V_132 -> V_140 ) ;
if ( V_29 >= 0 ) {
F_92 ( V_132 -> V_27 , V_157 ) ;
V_29 = V_144 ;
}
V_59:
F_90 ( V_54 -> V_139 , V_29 ) ;
V_156:
return V_29 ;
}
static void
F_93 ( struct V_113 * V_114 )
{
F_3 ( V_114 -> V_8 ) ;
F_3 ( V_114 ) ;
}
int F_6 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_13 )
{
struct V_54 * V_54 = V_11 -> V_74 -> V_83 ;
if ( F_11 ( V_19 , V_20 , V_13 ) )
return 0 ;
return F_44 ( V_19 , V_20 , L_10 , V_13 , V_54 ) ;
}
int F_8 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_17 )
{
struct V_54 * V_54 = V_11 -> V_74 -> V_83 ;
if ( F_11 ( V_19 , V_20 , V_17 ) )
return 0 ;
return F_44 ( V_19 , V_20 , L_11 , V_17 , V_54 ) ;
}
int F_94 ( const struct V_10 * V_11 , T_1 V_13 , char * V_23 , T_2 V_25 )
{
struct V_54 * V_54 = V_11 -> V_74 -> V_83 ;
int V_29 = - V_63 ;
if ( ! ( V_11 -> V_158 & V_159 ) )
V_29 = F_43 ( V_13 , L_12 , V_23 , V_25 , V_54 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_13 , V_23 , V_25 ) ;
return V_29 ;
}
int F_95 ( const struct V_10 * V_11 , T_1 V_17 , char * V_23 , T_2 V_25 )
{
struct V_54 * V_54 = V_11 -> V_74 -> V_83 ;
int V_29 = - V_63 ;
if ( ! ( V_11 -> V_158 & V_159 ) )
V_29 = F_43 ( V_17 , L_13 , V_23 , V_25 , V_54 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_17 , V_23 , V_25 ) ;
return V_29 ;
}
