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
V_28 = F_17 ( L_3 , 0 , 0 , V_26 ,
( V_33 & ~ V_34 ) |
V_35 | V_36 ,
V_37 , NULL ) ;
if ( F_18 ( V_28 ) ) {
V_29 = F_19 ( V_28 ) ;
goto V_38;
}
V_29 = F_20 ( & V_31 ) ;
if ( V_29 < 0 )
goto V_39;
V_29 = F_20 ( & V_40 ) ;
if ( V_29 < 0 )
goto V_41;
F_21 ( V_42 , & V_28 -> V_43 ) ;
V_26 -> V_44 = V_28 ;
V_26 -> V_45 = V_46 ;
V_47 = V_26 ;
return 0 ;
V_41:
F_22 ( & V_31 ) ;
V_39:
F_23 ( V_28 ) ;
V_38:
F_24 ( V_26 ) ;
return V_29 ;
}
static void F_25 ( void )
{
F_26 ( V_47 -> V_44 ) ;
F_22 ( & V_31 ) ;
F_22 ( & V_40 ) ;
F_24 ( V_47 ) ;
}
static T_3 F_27 ( const char * V_19 , T_2 V_20 ,
const char * type , T_2 V_48 , char * * V_49 )
{
char * V_50 ;
T_2 V_51 = V_48 + V_20 + 2 ;
* V_49 = F_28 ( V_51 , V_52 ) ;
if ( ! * V_49 )
return - V_32 ;
V_50 = * V_49 ;
memcpy ( V_50 , type , V_48 ) ;
V_50 += V_48 ;
* V_50 ++ = ':' ;
memcpy ( V_50 , V_19 , V_20 ) ;
V_50 += V_20 ;
* V_50 = '\0' ;
return V_51 ;
}
static T_3 F_29 ( struct V_53 * V_53 ,
const char * V_19 , T_2 V_20 ,
const char * type , void * V_8 ,
T_2 V_54 , struct V_55 * V_55 )
{
const struct V_26 * V_56 ;
struct V_27 * V_57 ;
char * V_49 ;
struct V_58 * V_59 ;
T_3 V_29 ;
V_29 = F_27 ( V_19 , V_20 , type , strlen ( type ) , & V_49 ) ;
if ( V_29 <= 0 )
goto V_60;
V_56 = F_30 ( V_47 ) ;
if ( V_55 )
V_57 = F_31 ( V_53 , V_49 , L_4 , 0 , V_55 ) ;
else
V_57 = F_32 ( & V_31 , V_49 , L_4 ) ;
F_33 ( V_56 ) ;
F_3 ( V_49 ) ;
if ( F_18 ( V_57 ) ) {
V_29 = F_19 ( V_57 ) ;
goto V_60;
}
F_34 () ;
V_57 -> V_61 |= V_35 ;
V_29 = F_35 ( V_57 ) ;
if ( V_29 < 0 )
goto V_62;
V_59 = F_36 ( V_57 -> V_59 . V_8 ) ;
if ( F_37 ( V_59 ) ) {
V_29 = F_19 ( V_59 ) ;
goto V_62;
}
V_29 = V_59 -> V_63 ;
if ( V_29 > 0 && V_29 <= V_54 )
memcpy ( V_8 , V_59 -> V_8 , V_29 ) ;
else
V_29 = - V_64 ;
V_62:
F_38 () ;
F_23 ( V_57 ) ;
V_60:
return V_29 ;
}
static T_3 F_39 ( const char * V_19 , T_2 V_20 ,
const char * type , void * V_8 ,
T_2 V_54 , struct V_55 * V_55 )
{
T_3 V_29 = F_29 ( & V_31 ,
V_19 , V_20 , type , V_8 ,
V_54 , NULL ) ;
if ( V_29 < 0 ) {
F_40 ( & V_55 -> V_65 ) ;
V_29 = F_29 ( & V_40 ,
V_19 , V_20 , type , V_8 ,
V_54 , V_55 ) ;
F_41 ( & V_55 -> V_65 ) ;
}
return V_29 ;
}
static T_3 F_42 ( T_1 V_24 , const char * type , char * V_23 ,
T_2 V_25 , struct V_55 * V_55 )
{
char V_66 [ V_67 ] ;
int V_68 ;
T_3 V_29 ;
V_68 = snprintf ( V_66 , sizeof( V_66 ) , L_1 , V_24 ) ;
V_29 = F_39 ( V_66 , V_68 , type , V_23 , V_25 , V_55 ) ;
if ( V_29 < 0 )
return - V_64 ;
return V_29 ;
}
static int F_43 ( const char * V_19 , T_2 V_20 , const char * type ,
T_1 * V_24 , struct V_55 * V_55 )
{
char V_66 [ V_67 ] ;
long V_69 ;
T_3 V_54 ;
int V_29 = 0 ;
V_54 = F_39 ( V_19 , V_20 , type , V_66 , V_67 , V_55 ) ;
if ( V_54 <= 0 ) {
V_29 = - V_64 ;
} else {
V_29 = F_44 ( V_66 , 10 , & V_69 ) ;
* V_24 = ( T_1 ) V_69 ;
}
return V_29 ;
}
static void F_45 ( struct V_70 * V_71 )
{
if ( V_71 -> V_72 )
F_46 ( V_71 -> V_72 ) ;
}
static int F_47 ( struct V_72 * V_73 ,
struct V_55 * V_55 ,
struct V_70 * V_71 )
{
struct V_72 * V_72 ;
V_72 = F_48 ( V_73 , L_5 , V_55 , V_71 ) ;
if ( F_18 ( V_72 ) )
return F_19 ( V_72 ) ;
V_71 -> V_72 = V_72 ;
return 0 ;
}
static void F_49 ( struct V_74 * V_75 ,
struct V_70 * V_71 )
{
struct V_76 * V_76 = V_75 -> V_77 ;
struct V_78 * V_79 ;
V_79 = F_50 ( V_76 ) ;
if ( V_79 ) {
F_45 ( V_71 ) ;
F_51 ( V_76 ) ;
}
}
static int F_52 ( struct V_74 * V_75 ,
struct V_55 * V_55 ,
struct V_70 * V_71 )
{
struct V_76 * V_76 = V_75 -> V_77 ;
struct V_78 * V_79 ;
int V_80 = 0 ;
V_79 = F_50 ( V_76 ) ;
if ( V_79 ) {
if ( V_75 -> V_81 -> V_82 )
V_80 = F_47 ( V_75 -> V_81 -> V_82 ,
V_55 , V_71 ) ;
F_51 ( V_76 ) ;
}
return V_80 ;
}
int
F_53 ( struct V_74 * V_75 )
{
struct V_55 * V_55 ;
struct V_70 * V_71 ;
int error ;
V_55 = F_54 ( sizeof( * V_55 ) , V_52 ) ;
if ( V_55 == NULL )
return - V_32 ;
V_71 = F_55 ( & V_83 , 0 ) ;
if ( F_18 ( V_71 ) ) {
error = F_19 ( V_71 ) ;
F_3 ( V_55 ) ;
return error ;
}
error = F_52 ( V_75 , V_55 , V_71 ) ;
if ( error ) {
F_56 ( V_71 ) ;
F_3 ( V_55 ) ;
return error ;
}
V_55 -> V_84 = V_71 ;
F_57 ( & V_55 -> V_65 ) ;
V_75 -> V_85 = V_55 ;
return 0 ;
}
void
F_58 ( struct V_74 * V_75 )
{
struct V_55 * V_55 = V_75 -> V_85 ;
if ( ! V_55 )
return;
F_49 ( V_75 , V_55 -> V_84 ) ;
F_56 ( V_55 -> V_84 ) ;
V_75 -> V_85 = NULL ;
F_3 ( V_55 ) ;
}
static int F_59 ( struct V_74 * V_75 , unsigned long V_86 ,
struct V_78 * V_87 )
{
int V_80 = 0 ;
switch ( V_86 ) {
case V_88 :
V_80 = F_47 ( V_75 -> V_81 -> V_82 ,
V_75 -> V_85 ,
V_75 -> V_85 -> V_84 ) ;
break;
case V_89 :
if ( V_75 -> V_85 -> V_84 ) {
struct V_72 * V_90 ;
V_90 = V_75 -> V_85 -> V_84 -> V_72 -> V_91 ;
F_45 ( V_75 -> V_85 -> V_84 ) ;
if ( F_60 ( V_90 ) )
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
static struct V_74 * F_61 ( struct V_76 * V_76 , int V_86 )
{
struct V_95 * V_96 = F_62 ( V_76 , V_97 ) ;
struct V_72 * V_82 ;
struct V_74 * V_75 ;
int V_80 ;
V_98:
F_63 ( & V_96 -> V_99 ) ;
F_64 (clp, &nn->nfs_client_list, cl_share_link) {
if ( V_75 -> V_100 == V_101 ) {
F_65 ( & V_75 -> V_102 ) ;
F_66 ( & V_96 -> V_99 ) ;
V_80 = F_67 ( V_75 ) ;
F_68 ( V_75 ) ;
if ( V_80 )
return NULL ;
goto V_98;
}
if ( V_75 -> V_100 < 0 )
continue;
F_69 () ;
if ( V_75 -> V_103 != & V_104 )
continue;
V_82 = V_75 -> V_85 -> V_84 -> V_72 ;
if ( ( ( V_86 == V_88 ) && V_82 ) ||
( ( V_86 == V_89 ) && ! V_82 ) )
continue;
F_65 ( & V_75 -> V_102 ) ;
F_66 ( & V_96 -> V_99 ) ;
return V_75 ;
}
F_66 ( & V_96 -> V_99 ) ;
return NULL ;
}
static int F_70 ( struct V_105 * V_106 , unsigned long V_86 ,
void * V_107 )
{
struct V_78 * V_87 = V_107 ;
struct V_74 * V_75 ;
int error = 0 ;
if ( ! F_71 ( V_108 ) )
return 0 ;
while ( ( V_75 = F_61 ( V_87 -> V_109 , V_86 ) ) ) {
error = F_59 ( V_75 , V_86 , V_87 ) ;
F_68 ( V_75 ) ;
if ( error )
break;
}
F_72 ( V_108 ) ;
return error ;
}
int F_73 ( void )
{
int V_29 ;
V_29 = F_14 () ;
if ( V_29 != 0 )
goto V_60;
V_29 = F_74 ( & V_110 ) ;
if ( V_29 != 0 )
F_25 () ;
V_60:
return V_29 ;
}
void F_75 ( void )
{
F_76 ( & V_110 ) ;
F_25 () ;
}
static int F_77 ( char * V_49 , struct V_55 * V_55 ,
struct V_111 * V_112 ,
struct V_113 * V_114 )
{
T_4 V_115 ;
int V_116 , V_29 ;
V_112 -> V_117 = V_118 ;
V_116 = F_78 ( V_49 , V_119 , & V_115 ) ;
switch ( V_116 ) {
case V_120 :
V_112 -> V_117 = V_121 ;
case V_122 :
V_112 -> V_123 = V_124 ;
V_29 = F_79 ( V_112 -> V_125 , & V_115 , V_126 ) ;
break;
case V_127 :
V_112 -> V_117 = V_121 ;
case V_128 :
V_112 -> V_123 = V_129 ;
V_29 = F_80 ( & V_115 , & V_112 -> V_130 ) ;
break;
default:
V_29 = - V_64 ;
goto V_60;
}
V_114 -> V_8 = V_112 ;
V_114 -> V_14 = sizeof( struct V_111 ) ;
V_60:
return V_29 ;
}
static bool
F_81 ( struct V_55 * V_55 ,
struct V_131 * V_8 )
{
if ( V_55 -> V_132 != NULL ) {
F_82 ( 1 ) ;
return false ;
}
V_55 -> V_132 = V_8 ;
return true ;
}
static void
F_83 ( struct V_55 * V_55 , int V_29 )
{
struct V_133 * V_134 = V_55 -> V_132 -> V_135 ;
F_3 ( V_55 -> V_132 ) ;
V_55 -> V_132 = NULL ;
F_84 ( V_134 , V_29 ) ;
}
static void
F_85 ( struct V_55 * V_55 , int V_29 )
{
if ( V_55 -> V_132 != NULL )
F_83 ( V_55 , V_29 ) ;
}
static int F_86 ( struct V_133 * V_134 ,
const char * V_136 ,
void * V_137 )
{
struct V_131 * V_8 ;
struct V_113 * V_114 ;
struct V_111 * V_112 ;
struct V_55 * V_55 = (struct V_55 * ) V_137 ;
struct V_27 * V_27 = V_134 -> V_27 ;
int V_29 = - V_32 ;
V_8 = F_54 ( sizeof( * V_8 ) , V_52 ) ;
if ( ! V_8 )
goto V_138;
V_114 = & V_8 -> V_139 ;
V_112 = & V_8 -> V_111 ;
V_8 -> V_55 = V_55 ;
V_8 -> V_135 = V_134 ;
V_29 = F_77 ( V_27 -> V_140 , V_55 , V_112 , V_114 ) ;
if ( V_29 < 0 )
goto V_141;
V_29 = - V_142 ;
if ( ! F_81 ( V_55 , V_8 ) )
goto V_141;
V_29 = F_87 ( V_55 -> V_84 , V_114 ) ;
if ( V_29 < 0 )
F_85 ( V_55 , V_29 ) ;
return V_29 ;
V_141:
F_3 ( V_8 ) ;
V_138:
F_84 ( V_134 , V_29 ) ;
return V_29 ;
}
static int F_88 ( struct V_27 * V_27 , struct V_27 * V_143 , char * V_8 )
{
return F_89 ( V_27 , V_8 , strlen ( V_8 ) + 1 ,
V_47 -> V_44 ,
V_143 ) ;
}
static int F_90 ( struct V_111 * V_112 ,
struct V_111 * V_144 ,
struct V_27 * V_27 , struct V_27 * V_143 )
{
char V_66 [ V_67 ] ;
int V_29 = - V_145 ;
if ( V_144 -> V_117 != V_112 -> V_117 || V_144 -> V_123 != V_112 -> V_123 )
goto V_60;
switch ( V_112 -> V_123 ) {
case V_124 :
if ( strcmp ( V_144 -> V_125 , V_112 -> V_125 ) != 0 )
break;
sprintf ( V_66 , L_9 , V_112 -> V_130 ) ;
V_29 = F_88 ( V_27 , V_143 , V_66 ) ;
break;
case V_129 :
if ( V_144 -> V_130 != V_112 -> V_130 )
break;
V_29 = F_88 ( V_27 , V_143 , V_112 -> V_125 ) ;
break;
default:
V_29 = - V_64 ;
}
V_60:
return V_29 ;
}
static T_3
F_91 ( struct V_146 * V_147 , const char T_5 * V_148 , T_2 V_149 )
{
struct V_150 * V_151 = F_92 ( V_147 -> V_152 . V_72 -> V_153 ) ;
struct V_55 * V_55 = (struct V_55 * ) V_151 -> V_154 ;
struct V_133 * V_134 ;
struct V_111 V_112 ;
T_2 V_155 ;
int V_29 = - V_145 ;
if ( V_55 -> V_132 == NULL )
goto V_156;
V_134 = V_55 -> V_132 -> V_135 ;
if ( V_149 != sizeof( V_112 ) ) {
V_29 = - V_157 ;
goto V_60;
}
if ( F_93 ( & V_112 , V_148 , V_149 ) != 0 ) {
V_29 = - V_158 ;
goto V_60;
}
if ( ! ( V_112 . V_159 & V_160 ) ) {
V_29 = - V_145 ;
goto V_60;
}
V_155 = F_94 ( V_112 . V_125 , V_126 ) ;
if ( V_155 == 0 || V_155 == V_126 ) {
V_29 = - V_64 ;
goto V_60;
}
V_29 = F_90 ( & V_112 ,
& V_55 -> V_132 -> V_111 ,
V_134 -> V_27 , V_134 -> V_143 ) ;
if ( V_29 >= 0 ) {
F_95 ( V_134 -> V_27 , V_161 ) ;
V_29 = V_149 ;
}
V_60:
F_83 ( V_55 , V_29 ) ;
V_156:
return V_29 ;
}
static void
F_96 ( struct V_113 * V_114 )
{
struct V_131 * V_8 = F_97 ( V_114 ,
struct V_131 ,
V_139 ) ;
struct V_55 * V_55 = V_8 -> V_55 ;
if ( V_114 -> V_162 )
F_85 ( V_55 , V_114 -> V_162 ) ;
}
static void
F_98 ( struct V_163 * V_163 )
{
struct V_150 * V_151 = F_92 ( V_163 ) ;
struct V_55 * V_55 = (struct V_55 * ) V_151 -> V_154 ;
F_85 ( V_55 , - V_164 ) ;
}
int F_6 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_13 )
{
struct V_55 * V_55 = V_11 -> V_74 -> V_85 ;
if ( F_11 ( V_19 , V_20 , V_13 ) )
return 0 ;
return F_43 ( V_19 , V_20 , L_10 , V_13 , V_55 ) ;
}
int F_8 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_17 )
{
struct V_55 * V_55 = V_11 -> V_74 -> V_85 ;
if ( F_11 ( V_19 , V_20 , V_17 ) )
return 0 ;
return F_43 ( V_19 , V_20 , L_11 , V_17 , V_55 ) ;
}
int F_99 ( const struct V_10 * V_11 , T_1 V_13 , char * V_23 , T_2 V_25 )
{
struct V_55 * V_55 = V_11 -> V_74 -> V_85 ;
int V_29 = - V_64 ;
if ( ! ( V_11 -> V_165 & V_166 ) )
V_29 = F_42 ( V_13 , L_12 , V_23 , V_25 , V_55 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_13 , V_23 , V_25 ) ;
return V_29 ;
}
int F_100 ( const struct V_10 * V_11 , T_1 V_17 , char * V_23 , T_2 V_25 )
{
struct V_55 * V_55 = V_11 -> V_74 -> V_85 ;
int V_29 = - V_64 ;
if ( ! ( V_11 -> V_165 & V_166 ) )
V_29 = F_42 ( V_17 , L_13 , V_23 , V_25 , V_55 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_17 , V_23 , V_25 ) ;
return V_29 ;
}
