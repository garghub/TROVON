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
V_29 = F_30 ( & V_64 ,
V_19 , V_20 , type , V_8 ,
V_53 , V_54 ) ;
}
return V_29 ;
}
static T_3 F_41 ( T_1 V_24 , const char * type , char * V_23 ,
T_2 V_25 , struct V_54 * V_54 )
{
char V_65 [ V_66 ] ;
int V_67 ;
T_3 V_29 ;
V_67 = snprintf ( V_65 , sizeof( V_65 ) , L_1 , V_24 ) ;
V_29 = F_40 ( V_65 , V_67 , type , V_23 , V_25 , V_54 ) ;
if ( V_29 < 0 )
return - V_63 ;
return V_29 ;
}
static int F_42 ( const char * V_19 , T_2 V_20 , const char * type ,
T_1 * V_24 , struct V_54 * V_54 )
{
char V_65 [ V_66 ] ;
long V_68 ;
T_3 V_53 ;
int V_29 = 0 ;
V_53 = F_40 ( V_19 , V_20 , type , V_65 , V_66 , V_54 ) ;
if ( V_53 <= 0 ) {
V_29 = - V_63 ;
} else {
V_29 = F_43 ( V_65 , 10 , & V_68 ) ;
* V_24 = ( T_1 ) V_68 ;
}
return V_29 ;
}
static void F_44 ( struct V_69 * V_70 )
{
if ( V_70 -> V_71 )
F_45 ( V_70 -> V_71 ) ;
}
static int F_46 ( struct V_71 * V_72 ,
struct V_54 * V_54 ,
struct V_69 * V_70 )
{
struct V_71 * V_71 ;
V_71 = F_47 ( V_72 , L_5 , V_54 , V_70 ) ;
if ( F_18 ( V_71 ) )
return F_19 ( V_71 ) ;
V_70 -> V_71 = V_71 ;
return 0 ;
}
static void F_48 ( struct V_73 * V_74 ,
struct V_69 * V_70 )
{
struct V_75 * V_75 = V_74 -> V_75 ;
struct V_76 * V_77 ;
V_77 = F_49 ( V_75 ) ;
if ( V_77 ) {
F_44 ( V_70 ) ;
F_50 ( V_75 ) ;
}
}
static int F_51 ( struct V_73 * V_74 ,
struct V_54 * V_54 ,
struct V_69 * V_70 )
{
struct V_75 * V_75 = V_74 -> V_75 ;
struct V_76 * V_77 ;
int V_78 = 0 ;
V_77 = F_49 ( V_75 ) ;
if ( V_77 ) {
if ( V_74 -> V_79 -> V_80 )
V_78 = F_46 ( V_74 -> V_79 -> V_80 ,
V_54 , V_70 ) ;
F_50 ( V_75 ) ;
}
return V_78 ;
}
int
F_52 ( struct V_73 * V_74 )
{
struct V_54 * V_54 ;
struct V_69 * V_70 ;
int error ;
F_53 ( V_74 -> V_81 != NULL ) ;
V_54 = F_54 ( sizeof( * V_54 ) , V_51 ) ;
if ( V_54 == NULL )
return - V_32 ;
V_70 = F_55 ( & V_82 , 0 ) ;
if ( F_18 ( V_70 ) ) {
error = F_19 ( V_70 ) ;
F_3 ( V_54 ) ;
return error ;
}
error = F_51 ( V_74 , V_54 , V_70 ) ;
if ( error ) {
F_56 ( V_70 ) ;
F_3 ( V_54 ) ;
return error ;
}
V_54 -> V_83 = V_70 ;
V_74 -> V_81 = V_54 ;
return 0 ;
}
void
F_57 ( struct V_73 * V_74 )
{
struct V_54 * V_54 = V_74 -> V_81 ;
if ( ! V_54 )
return;
F_48 ( V_74 , V_54 -> V_83 ) ;
F_56 ( V_54 -> V_83 ) ;
V_74 -> V_81 = NULL ;
F_3 ( V_54 ) ;
}
static int F_58 ( struct V_73 * V_74 , unsigned long V_84 ,
struct V_76 * V_85 )
{
int V_78 = 0 ;
switch ( V_84 ) {
case V_86 :
F_53 ( V_74 -> V_79 -> V_80 == NULL ) ;
V_78 = F_46 ( V_74 -> V_79 -> V_80 ,
V_74 -> V_81 ,
V_74 -> V_81 -> V_83 ) ;
break;
case V_87 :
if ( V_74 -> V_81 -> V_83 ) {
struct V_71 * V_88 ;
V_88 = V_74 -> V_81 -> V_83 -> V_71 -> V_89 ;
F_44 ( V_74 -> V_81 -> V_83 ) ;
if ( F_59 ( V_88 ) )
F_15 ( V_90 L_6
L_7 , V_91 ) ;
}
break;
default:
F_15 ( V_90 L_8 , V_91 ,
V_84 ) ;
return - V_92 ;
}
return V_78 ;
}
static struct V_73 * F_60 ( struct V_75 * V_75 , int V_84 )
{
struct V_93 * V_94 = F_61 ( V_75 , V_95 ) ;
struct V_71 * V_80 ;
struct V_73 * V_74 ;
F_62 ( & V_94 -> V_96 ) ;
F_63 (clp, &nn->nfs_client_list, cl_share_link) {
if ( V_74 -> V_97 != & V_98 )
continue;
V_80 = V_74 -> V_81 -> V_83 -> V_71 ;
if ( ( ( V_84 == V_86 ) && V_80 ) ||
( ( V_84 == V_87 ) && ! V_80 ) )
continue;
F_64 ( & V_74 -> V_99 ) ;
F_65 ( & V_94 -> V_96 ) ;
return V_74 ;
}
F_65 ( & V_94 -> V_96 ) ;
return NULL ;
}
static int F_66 ( struct V_100 * V_101 , unsigned long V_84 ,
void * V_102 )
{
struct V_76 * V_85 = V_102 ;
struct V_73 * V_74 ;
int error = 0 ;
if ( ! F_67 ( V_103 ) )
return 0 ;
while ( ( V_74 = F_60 ( V_85 -> V_104 , V_84 ) ) ) {
error = F_58 ( V_74 , V_84 , V_85 ) ;
F_68 ( V_74 ) ;
if ( error )
break;
}
F_69 ( V_103 ) ;
return error ;
}
int F_70 ( void )
{
int V_29 ;
V_29 = F_14 () ;
if ( V_29 != 0 )
goto V_59;
V_29 = F_71 ( & V_105 ) ;
if ( V_29 != 0 )
F_25 () ;
V_59:
return V_29 ;
}
void F_72 ( void )
{
F_73 ( & V_105 ) ;
F_25 () ;
}
static int F_74 ( char * V_48 , struct V_106 * V_107 ,
struct V_108 * V_109 )
{
T_4 V_110 ;
int V_111 , V_29 ;
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_107 -> V_112 = V_113 ;
V_111 = F_75 ( V_48 , V_114 , & V_110 ) ;
switch ( V_111 ) {
case V_115 :
V_107 -> V_112 = V_116 ;
case V_117 :
V_107 -> V_118 = V_119 ;
V_29 = F_76 ( V_107 -> V_120 , & V_110 , V_121 ) ;
break;
case V_122 :
V_107 -> V_112 = V_116 ;
case V_123 :
V_107 -> V_118 = V_124 ;
V_29 = F_77 ( & V_110 , & V_107 -> V_125 ) ;
break;
default:
V_29 = - V_63 ;
goto V_59;
}
V_109 -> V_8 = V_107 ;
V_109 -> V_14 = sizeof( struct V_106 ) ;
V_59:
return V_29 ;
}
static int F_78 ( struct V_126 * V_127 ,
const char * V_128 ,
void * V_129 )
{
struct V_108 * V_109 ;
struct V_106 * V_107 ;
struct V_54 * V_54 = (struct V_54 * ) V_129 ;
struct V_27 * V_27 = V_127 -> V_27 ;
int V_29 ;
V_109 = F_29 ( sizeof( * V_109 ) , V_51 ) ;
if ( F_18 ( V_109 ) ) {
V_29 = F_19 ( V_109 ) ;
goto V_130;
}
V_107 = F_29 ( sizeof( * V_107 ) , V_51 ) ;
if ( F_18 ( V_107 ) ) {
V_29 = F_19 ( V_107 ) ;
goto V_131;
}
V_29 = F_74 ( V_27 -> V_132 , V_107 , V_109 ) ;
if ( V_29 < 0 )
goto V_133;
V_54 -> V_134 = V_127 ;
V_29 = F_79 ( V_54 -> V_83 , V_109 ) ;
if ( V_29 < 0 )
goto V_133;
return V_29 ;
V_133:
F_3 ( V_107 ) ;
V_131:
F_3 ( V_109 ) ;
V_130:
F_26 ( V_127 -> V_27 ) ;
F_26 ( V_127 -> V_135 ) ;
return V_29 ;
}
static int F_80 ( struct V_27 * V_27 , struct V_27 * V_135 , char * V_8 )
{
return F_20 ( V_27 , V_8 , strlen ( V_8 ) + 1 ,
V_46 -> V_43 ,
V_135 ) ;
}
static int F_81 ( struct V_106 * V_107 , struct V_27 * V_27 , struct V_27 * V_135 )
{
char V_65 [ V_66 ] ;
int V_29 = - V_63 ;
switch ( V_107 -> V_118 ) {
case V_119 :
sprintf ( V_65 , L_9 , V_107 -> V_125 ) ;
V_29 = F_80 ( V_27 , V_135 , V_65 ) ;
break;
case V_124 :
V_29 = F_80 ( V_27 , V_135 , V_107 -> V_120 ) ;
break;
}
return V_29 ;
}
static T_3
F_82 ( struct V_136 * V_137 , const char T_5 * V_138 , T_2 V_139 )
{
struct V_140 * V_141 = F_83 ( V_137 -> V_142 . V_71 -> V_143 ) ;
struct V_54 * V_54 = (struct V_54 * ) V_141 -> V_144 ;
struct V_126 * V_127 = V_54 -> V_134 ;
struct V_106 V_107 ;
T_2 V_145 ;
int V_29 ;
if ( V_139 != sizeof( V_107 ) ) {
V_29 = - V_146 ;
goto V_59;
}
if ( F_84 ( & V_107 , V_138 , V_139 ) != 0 ) {
V_29 = - V_147 ;
goto V_59;
}
if ( ! ( V_107 . V_148 & V_149 ) ) {
V_29 = V_139 ;
F_85 ( V_54 -> V_134 , - V_150 ) ;
goto V_151;
}
V_145 = F_86 ( V_107 . V_120 , V_121 ) ;
if ( V_145 == 0 || V_145 == V_121 ) {
V_29 = - V_63 ;
goto V_59;
}
V_29 = F_81 ( & V_107 , V_127 -> V_27 , V_127 -> V_135 ) ;
if ( V_29 >= 0 ) {
F_87 ( V_127 -> V_27 , V_152 ) ;
V_29 = V_139 ;
}
V_59:
F_85 ( V_54 -> V_134 , V_29 ) ;
V_151:
return V_29 ;
}
static void
F_88 ( struct V_108 * V_109 )
{
F_3 ( V_109 -> V_8 ) ;
F_3 ( V_109 ) ;
}
int F_6 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_13 )
{
struct V_54 * V_54 = V_11 -> V_73 -> V_81 ;
if ( F_11 ( V_19 , V_20 , V_13 ) )
return 0 ;
return F_42 ( V_19 , V_20 , L_10 , V_13 , V_54 ) ;
}
int F_8 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_17 )
{
struct V_54 * V_54 = V_11 -> V_73 -> V_81 ;
if ( F_11 ( V_19 , V_20 , V_17 ) )
return 0 ;
return F_42 ( V_19 , V_20 , L_11 , V_17 , V_54 ) ;
}
int F_89 ( const struct V_10 * V_11 , T_1 V_13 , char * V_23 , T_2 V_25 )
{
struct V_54 * V_54 = V_11 -> V_73 -> V_81 ;
int V_29 = - V_63 ;
if ( ! ( V_11 -> V_153 & V_154 ) )
V_29 = F_41 ( V_13 , L_12 , V_23 , V_25 , V_54 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_13 , V_23 , V_25 ) ;
return V_29 ;
}
int F_90 ( const struct V_10 * V_11 , T_1 V_17 , char * V_23 , T_2 V_25 )
{
struct V_54 * V_54 = V_11 -> V_73 -> V_81 ;
int V_29 = - V_63 ;
if ( ! ( V_11 -> V_153 & V_154 ) )
V_29 = F_41 ( V_17 , L_13 , V_23 , V_25 , V_54 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_17 , V_23 , V_25 ) ;
return V_29 ;
}
