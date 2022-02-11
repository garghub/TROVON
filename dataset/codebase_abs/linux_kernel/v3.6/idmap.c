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
V_29 = F_21 ( & V_41 ) ;
if ( V_29 < 0 )
goto V_42;
F_22 ( V_43 , & V_28 -> V_44 ) ;
V_26 -> V_45 = V_28 ;
V_26 -> V_46 = V_47 ;
V_48 = V_26 ;
return 0 ;
V_42:
F_23 ( & V_31 ) ;
V_40:
F_24 ( V_28 ) ;
V_39:
F_25 ( V_26 ) ;
return V_29 ;
}
static void F_26 ( void )
{
F_27 ( V_48 -> V_45 ) ;
F_23 ( & V_31 ) ;
F_23 ( & V_41 ) ;
F_25 ( V_48 ) ;
}
static T_3 F_28 ( const char * V_19 , T_2 V_20 ,
const char * type , T_2 V_49 , char * * V_50 )
{
char * V_51 ;
T_2 V_52 = V_49 + V_20 + 2 ;
* V_50 = F_29 ( V_52 , V_53 ) ;
if ( ! * V_50 )
return - V_32 ;
V_51 = * V_50 ;
memcpy ( V_51 , type , V_49 ) ;
V_51 += V_49 ;
* V_51 ++ = ':' ;
memcpy ( V_51 , V_19 , V_20 ) ;
V_51 += V_20 ;
* V_51 = '\0' ;
return V_52 ;
}
static T_3 F_30 ( struct V_54 * V_54 ,
const char * V_19 , T_2 V_20 ,
const char * type , void * V_8 ,
T_2 V_55 , struct V_56 * V_56 )
{
const struct V_26 * V_57 ;
struct V_27 * V_58 ;
char * V_50 ;
struct V_59 * V_60 ;
T_3 V_29 ;
V_29 = F_28 ( V_19 , V_20 , type , strlen ( type ) , & V_50 ) ;
if ( V_29 <= 0 )
goto V_61;
V_57 = F_31 ( V_48 ) ;
if ( V_56 )
V_58 = F_32 ( V_54 , V_50 , L_4 , 0 , V_56 ) ;
else
V_58 = F_33 ( & V_31 , V_50 , L_4 ) ;
F_34 ( V_57 ) ;
F_3 ( V_50 ) ;
if ( F_18 ( V_58 ) ) {
V_29 = F_19 ( V_58 ) ;
goto V_61;
}
F_35 () ;
V_58 -> V_62 |= V_36 ;
V_29 = F_36 ( V_58 ) ;
if ( V_29 < 0 )
goto V_63;
V_60 = F_37 ( V_58 -> V_60 . V_8 ) ;
if ( F_38 ( V_60 ) ) {
V_29 = F_19 ( V_60 ) ;
goto V_63;
}
V_29 = V_60 -> V_64 ;
if ( V_29 > 0 && V_29 <= V_55 )
memcpy ( V_8 , V_60 -> V_8 , V_29 ) ;
else
V_29 = - V_65 ;
V_63:
F_39 () ;
F_24 ( V_58 ) ;
V_61:
return V_29 ;
}
static T_3 F_40 ( const char * V_19 , T_2 V_20 ,
const char * type , void * V_8 ,
T_2 V_55 , struct V_56 * V_56 )
{
T_3 V_29 = F_30 ( & V_31 ,
V_19 , V_20 , type , V_8 ,
V_55 , NULL ) ;
if ( V_29 < 0 ) {
F_41 ( & V_56 -> V_66 ) ;
V_29 = F_30 ( & V_41 ,
V_19 , V_20 , type , V_8 ,
V_55 , V_56 ) ;
V_56 -> V_67 = NULL ;
F_42 ( & V_56 -> V_66 ) ;
}
return V_29 ;
}
static T_3 F_43 ( T_1 V_24 , const char * type , char * V_23 ,
T_2 V_25 , struct V_56 * V_56 )
{
char V_68 [ V_69 ] ;
int V_70 ;
T_3 V_29 ;
V_70 = snprintf ( V_68 , sizeof( V_68 ) , L_1 , V_24 ) ;
V_29 = F_40 ( V_68 , V_70 , type , V_23 , V_25 , V_56 ) ;
if ( V_29 < 0 )
return - V_65 ;
return V_29 ;
}
static int F_44 ( const char * V_19 , T_2 V_20 , const char * type ,
T_1 * V_24 , struct V_56 * V_56 )
{
char V_68 [ V_69 ] ;
long V_71 ;
T_3 V_55 ;
int V_29 = 0 ;
V_55 = F_40 ( V_19 , V_20 , type , V_68 , V_69 , V_56 ) ;
if ( V_55 <= 0 ) {
V_29 = - V_65 ;
} else {
V_29 = F_45 ( V_68 , 10 , & V_71 ) ;
* V_24 = ( T_1 ) V_71 ;
}
return V_29 ;
}
static void F_46 ( struct V_72 * V_73 )
{
if ( V_73 -> V_74 )
F_47 ( V_73 -> V_74 ) ;
}
static int F_48 ( struct V_74 * V_75 ,
struct V_56 * V_56 ,
struct V_72 * V_73 )
{
struct V_74 * V_74 ;
V_74 = F_49 ( V_75 , L_5 , V_56 , V_73 ) ;
if ( F_18 ( V_74 ) )
return F_19 ( V_74 ) ;
V_73 -> V_74 = V_74 ;
return 0 ;
}
static void F_50 ( struct V_76 * V_77 ,
struct V_72 * V_73 )
{
struct V_78 * V_78 = V_77 -> V_79 ;
struct V_80 * V_81 ;
V_81 = F_51 ( V_78 ) ;
if ( V_81 ) {
F_46 ( V_73 ) ;
F_52 ( V_78 ) ;
}
}
static int F_53 ( struct V_76 * V_77 ,
struct V_56 * V_56 ,
struct V_72 * V_73 )
{
struct V_78 * V_78 = V_77 -> V_79 ;
struct V_80 * V_81 ;
int V_82 = 0 ;
V_81 = F_51 ( V_78 ) ;
if ( V_81 ) {
if ( V_77 -> V_83 -> V_84 )
V_82 = F_48 ( V_77 -> V_83 -> V_84 ,
V_56 , V_73 ) ;
F_52 ( V_78 ) ;
}
return V_82 ;
}
int
F_54 ( struct V_76 * V_77 )
{
struct V_56 * V_56 ;
struct V_72 * V_73 ;
int error ;
F_55 ( V_77 -> V_85 != NULL ) ;
V_56 = F_56 ( sizeof( * V_56 ) , V_53 ) ;
if ( V_56 == NULL )
return - V_32 ;
V_73 = F_57 ( & V_86 , 0 ) ;
if ( F_18 ( V_73 ) ) {
error = F_19 ( V_73 ) ;
F_3 ( V_56 ) ;
return error ;
}
error = F_53 ( V_77 , V_56 , V_73 ) ;
if ( error ) {
F_58 ( V_73 ) ;
F_3 ( V_56 ) ;
return error ;
}
V_56 -> V_87 = V_73 ;
F_59 ( & V_56 -> V_66 ) ;
V_77 -> V_85 = V_56 ;
return 0 ;
}
void
F_60 ( struct V_76 * V_77 )
{
struct V_56 * V_56 = V_77 -> V_85 ;
if ( ! V_56 )
return;
F_50 ( V_77 , V_56 -> V_87 ) ;
F_58 ( V_56 -> V_87 ) ;
V_77 -> V_85 = NULL ;
F_3 ( V_56 ) ;
}
static int F_61 ( struct V_76 * V_77 , unsigned long V_88 ,
struct V_80 * V_89 )
{
int V_82 = 0 ;
switch ( V_88 ) {
case V_90 :
F_55 ( V_77 -> V_83 -> V_84 == NULL ) ;
V_82 = F_48 ( V_77 -> V_83 -> V_84 ,
V_77 -> V_85 ,
V_77 -> V_85 -> V_87 ) ;
break;
case V_91 :
if ( V_77 -> V_85 -> V_87 ) {
struct V_74 * V_92 ;
V_92 = V_77 -> V_85 -> V_87 -> V_74 -> V_93 ;
F_46 ( V_77 -> V_85 -> V_87 ) ;
if ( F_62 ( V_92 ) )
F_15 ( V_94 L_6
L_7 , V_95 ) ;
}
break;
default:
F_15 ( V_94 L_8 , V_95 ,
V_88 ) ;
return - V_96 ;
}
return V_82 ;
}
static struct V_76 * F_63 ( struct V_78 * V_78 , int V_88 )
{
struct V_97 * V_98 = F_64 ( V_78 , V_99 ) ;
struct V_74 * V_84 ;
struct V_76 * V_77 ;
int V_82 ;
V_100:
F_65 ( & V_98 -> V_101 ) ;
F_66 (clp, &nn->nfs_client_list, cl_share_link) {
if ( V_77 -> V_102 == V_103 ) {
F_67 ( & V_77 -> V_104 ) ;
F_68 ( & V_98 -> V_101 ) ;
V_82 = F_69 ( V_77 ) ;
F_70 ( V_77 ) ;
if ( V_82 )
return NULL ;
goto V_100;
}
if ( V_77 -> V_102 < 0 )
continue;
F_71 () ;
if ( V_77 -> V_105 != & V_106 )
continue;
V_84 = V_77 -> V_85 -> V_87 -> V_74 ;
if ( ( ( V_88 == V_90 ) && V_84 ) ||
( ( V_88 == V_91 ) && ! V_84 ) )
continue;
F_67 ( & V_77 -> V_104 ) ;
F_68 ( & V_98 -> V_101 ) ;
return V_77 ;
}
F_68 ( & V_98 -> V_101 ) ;
return NULL ;
}
static int F_72 ( struct V_107 * V_108 , unsigned long V_88 ,
void * V_109 )
{
struct V_80 * V_89 = V_109 ;
struct V_76 * V_77 ;
int error = 0 ;
if ( ! F_73 ( V_110 ) )
return 0 ;
while ( ( V_77 = F_63 ( V_89 -> V_111 , V_88 ) ) ) {
error = F_61 ( V_77 , V_88 , V_89 ) ;
F_70 ( V_77 ) ;
if ( error )
break;
}
F_74 ( V_110 ) ;
return error ;
}
int F_75 ( void )
{
int V_29 ;
V_29 = F_14 () ;
if ( V_29 != 0 )
goto V_61;
V_29 = F_76 ( & V_112 ) ;
if ( V_29 != 0 )
F_26 () ;
V_61:
return V_29 ;
}
void F_77 ( void )
{
F_78 ( & V_112 ) ;
F_26 () ;
}
static int F_79 ( char * V_50 , struct V_56 * V_56 ,
struct V_113 * V_114 ,
struct V_115 * V_116 )
{
T_4 V_117 ;
int V_118 , V_29 ;
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_114 -> V_119 = V_120 ;
V_118 = F_80 ( V_50 , V_121 , & V_117 ) ;
switch ( V_118 ) {
case V_122 :
V_114 -> V_119 = V_123 ;
case V_124 :
V_114 -> V_125 = V_126 ;
V_29 = F_81 ( V_114 -> V_127 , & V_117 , V_128 ) ;
break;
case V_129 :
V_114 -> V_119 = V_123 ;
case V_130 :
V_114 -> V_125 = V_131 ;
V_29 = F_82 ( & V_117 , & V_114 -> V_132 ) ;
break;
default:
V_29 = - V_65 ;
goto V_61;
}
V_116 -> V_8 = V_114 ;
V_116 -> V_14 = sizeof( struct V_113 ) ;
V_61:
return V_29 ;
}
static int F_83 ( struct V_133 * V_134 ,
const char * V_135 ,
void * V_136 )
{
struct V_137 * V_8 ;
struct V_115 * V_116 ;
struct V_113 * V_114 ;
struct V_56 * V_56 = (struct V_56 * ) V_136 ;
struct V_27 * V_27 = V_134 -> V_27 ;
int V_29 = - V_32 ;
V_8 = F_29 ( sizeof( * V_8 ) , V_53 ) ;
if ( ! V_8 )
goto V_138;
V_116 = & V_8 -> V_139 ;
V_114 = & V_8 -> V_113 ;
V_8 -> V_56 = V_56 ;
V_29 = F_79 ( V_27 -> V_140 , V_56 , V_114 , V_116 ) ;
if ( V_29 < 0 )
goto V_141;
F_55 ( V_56 -> V_67 != NULL ) ;
V_56 -> V_67 = V_134 ;
V_29 = F_84 ( V_56 -> V_87 , V_116 ) ;
if ( V_29 < 0 )
goto V_142;
return V_29 ;
V_142:
V_56 -> V_67 = NULL ;
V_141:
F_3 ( V_8 ) ;
V_138:
F_85 ( V_134 , V_29 ) ;
return V_29 ;
}
static int F_86 ( struct V_27 * V_27 , struct V_27 * V_143 , char * V_8 )
{
return F_20 ( V_27 , V_8 , strlen ( V_8 ) + 1 ,
V_48 -> V_45 ,
V_143 ) ;
}
static int F_87 ( struct V_113 * V_114 , struct V_27 * V_27 , struct V_27 * V_143 )
{
char V_68 [ V_69 ] ;
int V_29 = - V_65 ;
switch ( V_114 -> V_125 ) {
case V_126 :
sprintf ( V_68 , L_9 , V_114 -> V_132 ) ;
V_29 = F_86 ( V_27 , V_143 , V_68 ) ;
break;
case V_131 :
V_29 = F_86 ( V_27 , V_143 , V_114 -> V_127 ) ;
break;
}
return V_29 ;
}
static T_3
F_88 ( struct V_144 * V_145 , const char T_5 * V_146 , T_2 V_147 )
{
struct V_148 * V_149 = F_89 ( V_145 -> V_150 . V_74 -> V_151 ) ;
struct V_56 * V_56 = (struct V_56 * ) V_149 -> V_152 ;
struct V_133 * V_134 ;
struct V_113 V_114 ;
T_2 V_153 ;
int V_29 ;
V_134 = F_90 ( V_56 -> V_67 ) ;
V_56 -> V_67 = NULL ;
if ( V_147 != sizeof( V_114 ) ) {
V_29 = - V_154 ;
goto V_61;
}
if ( F_91 ( & V_114 , V_146 , V_147 ) != 0 ) {
V_29 = - V_155 ;
goto V_61;
}
if ( ! ( V_114 . V_156 & V_157 ) ) {
V_29 = - V_158 ;
goto V_61;
}
V_153 = F_92 ( V_114 . V_127 , V_128 ) ;
if ( V_153 == 0 || V_153 == V_128 ) {
V_29 = - V_65 ;
goto V_61;
}
V_29 = F_87 ( & V_114 , V_134 -> V_27 , V_134 -> V_143 ) ;
if ( V_29 >= 0 ) {
F_93 ( V_134 -> V_27 , V_159 ) ;
V_29 = V_147 ;
}
V_61:
F_85 ( V_134 , V_29 ) ;
return V_29 ;
}
static void
F_94 ( struct V_115 * V_116 )
{
struct V_137 * V_8 = F_95 ( V_116 ,
struct V_137 ,
V_139 ) ;
struct V_56 * V_56 = V_8 -> V_56 ;
struct V_133 * V_134 ;
if ( V_116 -> V_160 ) {
V_134 = F_90 ( V_56 -> V_67 ) ;
V_56 -> V_67 = NULL ;
F_85 ( V_134 , V_116 -> V_160 ) ;
}
F_3 ( V_8 ) ;
}
static void
F_96 ( struct V_161 * V_161 )
{
struct V_148 * V_149 = F_89 ( V_161 ) ;
struct V_56 * V_56 = (struct V_56 * ) V_149 -> V_152 ;
V_56 -> V_67 = NULL ;
}
int F_6 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_13 )
{
struct V_56 * V_56 = V_11 -> V_76 -> V_85 ;
if ( F_11 ( V_19 , V_20 , V_13 ) )
return 0 ;
return F_44 ( V_19 , V_20 , L_10 , V_13 , V_56 ) ;
}
int F_8 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_17 )
{
struct V_56 * V_56 = V_11 -> V_76 -> V_85 ;
if ( F_11 ( V_19 , V_20 , V_17 ) )
return 0 ;
return F_44 ( V_19 , V_20 , L_11 , V_17 , V_56 ) ;
}
int F_97 ( const struct V_10 * V_11 , T_1 V_13 , char * V_23 , T_2 V_25 )
{
struct V_56 * V_56 = V_11 -> V_76 -> V_85 ;
int V_29 = - V_65 ;
if ( ! ( V_11 -> V_162 & V_163 ) )
V_29 = F_43 ( V_13 , L_12 , V_23 , V_25 , V_56 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_13 , V_23 , V_25 ) ;
return V_29 ;
}
int F_98 ( const struct V_10 * V_11 , T_1 V_17 , char * V_23 , T_2 V_25 )
{
struct V_56 * V_56 = V_11 -> V_76 -> V_85 ;
int V_29 = - V_65 ;
if ( ! ( V_11 -> V_162 & V_163 ) )
V_29 = F_43 ( V_17 , L_13 , V_23 , V_25 , V_56 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_17 , V_23 , V_25 ) ;
return V_29 ;
}
