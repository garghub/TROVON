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
F_42 ( & V_56 -> V_66 ) ;
}
return V_29 ;
}
static T_3 F_43 ( T_1 V_24 , const char * type , char * V_23 ,
T_2 V_25 , struct V_56 * V_56 )
{
char V_67 [ V_68 ] ;
int V_69 ;
T_3 V_29 ;
V_69 = snprintf ( V_67 , sizeof( V_67 ) , L_1 , V_24 ) ;
V_29 = F_40 ( V_67 , V_69 , type , V_23 , V_25 , V_56 ) ;
if ( V_29 < 0 )
return - V_65 ;
return V_29 ;
}
static int F_44 ( const char * V_19 , T_2 V_20 , const char * type ,
T_1 * V_24 , struct V_56 * V_56 )
{
char V_67 [ V_68 ] ;
long V_70 ;
T_3 V_55 ;
int V_29 = 0 ;
V_55 = F_40 ( V_19 , V_20 , type , V_67 , V_68 , V_56 ) ;
if ( V_55 <= 0 ) {
V_29 = - V_65 ;
} else {
V_29 = F_45 ( V_67 , 10 , & V_70 ) ;
* V_24 = ( T_1 ) V_70 ;
}
return V_29 ;
}
static void F_46 ( struct V_71 * V_72 )
{
if ( V_72 -> V_73 )
F_47 ( V_72 -> V_73 ) ;
}
static int F_48 ( struct V_73 * V_74 ,
struct V_56 * V_56 ,
struct V_71 * V_72 )
{
struct V_73 * V_73 ;
V_73 = F_49 ( V_74 , L_5 , V_56 , V_72 ) ;
if ( F_18 ( V_73 ) )
return F_19 ( V_73 ) ;
V_72 -> V_73 = V_73 ;
return 0 ;
}
static void F_50 ( struct V_75 * V_76 ,
struct V_71 * V_72 )
{
struct V_77 * V_77 = V_76 -> V_78 ;
struct V_79 * V_80 ;
V_80 = F_51 ( V_77 ) ;
if ( V_80 ) {
F_46 ( V_72 ) ;
F_52 ( V_77 ) ;
}
}
static int F_53 ( struct V_75 * V_76 ,
struct V_56 * V_56 ,
struct V_71 * V_72 )
{
struct V_77 * V_77 = V_76 -> V_78 ;
struct V_79 * V_80 ;
int V_81 = 0 ;
V_80 = F_51 ( V_77 ) ;
if ( V_80 ) {
if ( V_76 -> V_82 -> V_83 )
V_81 = F_48 ( V_76 -> V_82 -> V_83 ,
V_56 , V_72 ) ;
F_52 ( V_77 ) ;
}
return V_81 ;
}
int
F_54 ( struct V_75 * V_76 )
{
struct V_56 * V_56 ;
struct V_71 * V_72 ;
int error ;
V_56 = F_55 ( sizeof( * V_56 ) , V_53 ) ;
if ( V_56 == NULL )
return - V_32 ;
V_72 = F_56 ( & V_84 , 0 ) ;
if ( F_18 ( V_72 ) ) {
error = F_19 ( V_72 ) ;
F_3 ( V_56 ) ;
return error ;
}
error = F_53 ( V_76 , V_56 , V_72 ) ;
if ( error ) {
F_57 ( V_72 ) ;
F_3 ( V_56 ) ;
return error ;
}
V_56 -> V_85 = V_72 ;
F_58 ( & V_56 -> V_66 ) ;
V_76 -> V_86 = V_56 ;
return 0 ;
}
void
F_59 ( struct V_75 * V_76 )
{
struct V_56 * V_56 = V_76 -> V_86 ;
if ( ! V_56 )
return;
F_50 ( V_76 , V_56 -> V_85 ) ;
F_57 ( V_56 -> V_85 ) ;
V_76 -> V_86 = NULL ;
F_3 ( V_56 ) ;
}
static int F_60 ( struct V_75 * V_76 , unsigned long V_87 ,
struct V_79 * V_88 )
{
int V_81 = 0 ;
switch ( V_87 ) {
case V_89 :
V_81 = F_48 ( V_76 -> V_82 -> V_83 ,
V_76 -> V_86 ,
V_76 -> V_86 -> V_85 ) ;
break;
case V_90 :
if ( V_76 -> V_86 -> V_85 ) {
struct V_73 * V_91 ;
V_91 = V_76 -> V_86 -> V_85 -> V_73 -> V_92 ;
F_46 ( V_76 -> V_86 -> V_85 ) ;
if ( F_61 ( V_91 ) )
F_15 ( V_93 L_6
L_7 , V_94 ) ;
}
break;
default:
F_15 ( V_93 L_8 , V_94 ,
V_87 ) ;
return - V_95 ;
}
return V_81 ;
}
static struct V_75 * F_62 ( struct V_77 * V_77 , int V_87 )
{
struct V_96 * V_97 = F_63 ( V_77 , V_98 ) ;
struct V_73 * V_83 ;
struct V_75 * V_76 ;
int V_81 ;
V_99:
F_64 ( & V_97 -> V_100 ) ;
F_65 (clp, &nn->nfs_client_list, cl_share_link) {
if ( V_76 -> V_101 == V_102 ) {
F_66 ( & V_76 -> V_103 ) ;
F_67 ( & V_97 -> V_100 ) ;
V_81 = F_68 ( V_76 ) ;
F_69 ( V_76 ) ;
if ( V_81 )
return NULL ;
goto V_99;
}
if ( V_76 -> V_101 < 0 )
continue;
F_70 () ;
if ( V_76 -> V_104 != & V_105 )
continue;
V_83 = V_76 -> V_86 -> V_85 -> V_73 ;
if ( ( ( V_87 == V_89 ) && V_83 ) ||
( ( V_87 == V_90 ) && ! V_83 ) )
continue;
F_66 ( & V_76 -> V_103 ) ;
F_67 ( & V_97 -> V_100 ) ;
return V_76 ;
}
F_67 ( & V_97 -> V_100 ) ;
return NULL ;
}
static int F_71 ( struct V_106 * V_107 , unsigned long V_87 ,
void * V_108 )
{
struct V_79 * V_88 = V_108 ;
struct V_75 * V_76 ;
int error = 0 ;
if ( ! F_72 ( V_109 ) )
return 0 ;
while ( ( V_76 = F_62 ( V_88 -> V_110 , V_87 ) ) ) {
error = F_60 ( V_76 , V_87 , V_88 ) ;
F_69 ( V_76 ) ;
if ( error )
break;
}
F_73 ( V_109 ) ;
return error ;
}
int F_74 ( void )
{
int V_29 ;
V_29 = F_14 () ;
if ( V_29 != 0 )
goto V_61;
V_29 = F_75 ( & V_111 ) ;
if ( V_29 != 0 )
F_26 () ;
V_61:
return V_29 ;
}
void F_76 ( void )
{
F_77 ( & V_111 ) ;
F_26 () ;
}
static int F_78 ( char * V_50 , struct V_56 * V_56 ,
struct V_112 * V_113 ,
struct V_114 * V_115 )
{
T_4 V_116 ;
int V_117 , V_29 ;
V_113 -> V_118 = V_119 ;
V_117 = F_79 ( V_50 , V_120 , & V_116 ) ;
switch ( V_117 ) {
case V_121 :
V_113 -> V_118 = V_122 ;
case V_123 :
V_113 -> V_124 = V_125 ;
V_29 = F_80 ( V_113 -> V_126 , & V_116 , V_127 ) ;
break;
case V_128 :
V_113 -> V_118 = V_122 ;
case V_129 :
V_113 -> V_124 = V_130 ;
V_29 = F_81 ( & V_116 , & V_113 -> V_131 ) ;
break;
default:
V_29 = - V_65 ;
goto V_61;
}
V_115 -> V_8 = V_113 ;
V_115 -> V_14 = sizeof( struct V_112 ) ;
V_61:
return V_29 ;
}
static bool
F_82 ( struct V_56 * V_56 ,
struct V_132 * V_8 )
{
if ( V_56 -> V_133 != NULL ) {
F_83 ( 1 ) ;
return false ;
}
V_56 -> V_133 = V_8 ;
return true ;
}
static void
F_84 ( struct V_56 * V_56 , int V_29 )
{
struct V_134 * V_135 = V_56 -> V_133 -> V_136 ;
F_3 ( V_56 -> V_133 ) ;
V_56 -> V_133 = NULL ;
F_85 ( V_135 , V_29 ) ;
}
static void
F_86 ( struct V_56 * V_56 , int V_29 )
{
if ( V_56 -> V_133 != NULL )
F_84 ( V_56 , V_29 ) ;
}
static int F_87 ( struct V_134 * V_135 ,
const char * V_137 ,
void * V_138 )
{
struct V_132 * V_8 ;
struct V_114 * V_115 ;
struct V_112 * V_113 ;
struct V_56 * V_56 = (struct V_56 * ) V_138 ;
struct V_27 * V_27 = V_135 -> V_27 ;
int V_29 = - V_32 ;
V_8 = F_55 ( sizeof( * V_8 ) , V_53 ) ;
if ( ! V_8 )
goto V_139;
V_115 = & V_8 -> V_140 ;
V_113 = & V_8 -> V_112 ;
V_8 -> V_56 = V_56 ;
V_8 -> V_136 = V_135 ;
V_29 = F_78 ( V_27 -> V_141 , V_56 , V_113 , V_115 ) ;
if ( V_29 < 0 )
goto V_142;
V_29 = - V_143 ;
if ( ! F_82 ( V_56 , V_8 ) )
goto V_142;
V_29 = F_88 ( V_56 -> V_85 , V_115 ) ;
if ( V_29 < 0 )
F_86 ( V_56 , V_29 ) ;
return V_29 ;
V_142:
F_3 ( V_8 ) ;
V_139:
F_85 ( V_135 , V_29 ) ;
return V_29 ;
}
static int F_89 ( struct V_27 * V_27 , struct V_27 * V_144 , char * V_8 )
{
return F_20 ( V_27 , V_8 , strlen ( V_8 ) + 1 ,
V_48 -> V_45 ,
V_144 ) ;
}
static int F_90 ( struct V_112 * V_113 ,
struct V_112 * V_145 ,
struct V_27 * V_27 , struct V_27 * V_144 )
{
char V_67 [ V_68 ] ;
int V_29 = - V_146 ;
if ( V_145 -> V_118 != V_113 -> V_118 || V_145 -> V_124 != V_113 -> V_124 )
goto V_61;
switch ( V_113 -> V_124 ) {
case V_125 :
if ( strcmp ( V_145 -> V_126 , V_113 -> V_126 ) != 0 )
break;
sprintf ( V_67 , L_9 , V_113 -> V_131 ) ;
V_29 = F_89 ( V_27 , V_144 , V_67 ) ;
break;
case V_130 :
if ( V_145 -> V_131 != V_113 -> V_131 )
break;
V_29 = F_89 ( V_27 , V_144 , V_113 -> V_126 ) ;
break;
default:
V_29 = - V_65 ;
}
V_61:
return V_29 ;
}
static T_3
F_91 ( struct V_147 * V_148 , const char T_5 * V_149 , T_2 V_150 )
{
struct V_151 * V_152 = F_92 ( V_148 -> V_153 . V_73 -> V_154 ) ;
struct V_56 * V_56 = (struct V_56 * ) V_152 -> V_155 ;
struct V_134 * V_135 ;
struct V_112 V_113 ;
T_2 V_156 ;
int V_29 = - V_146 ;
if ( V_56 -> V_133 == NULL )
goto V_157;
V_135 = V_56 -> V_133 -> V_136 ;
if ( V_150 != sizeof( V_113 ) ) {
V_29 = - V_158 ;
goto V_61;
}
if ( F_93 ( & V_113 , V_149 , V_150 ) != 0 ) {
V_29 = - V_159 ;
goto V_61;
}
if ( ! ( V_113 . V_160 & V_161 ) ) {
V_29 = - V_146 ;
goto V_61;
}
V_156 = F_94 ( V_113 . V_126 , V_127 ) ;
if ( V_156 == 0 || V_156 == V_127 ) {
V_29 = - V_65 ;
goto V_61;
}
V_29 = F_90 ( & V_113 ,
& V_56 -> V_133 -> V_112 ,
V_135 -> V_27 , V_135 -> V_144 ) ;
if ( V_29 >= 0 ) {
F_95 ( V_135 -> V_27 , V_162 ) ;
V_29 = V_150 ;
}
V_61:
F_84 ( V_56 , V_29 ) ;
V_157:
return V_29 ;
}
static void
F_96 ( struct V_114 * V_115 )
{
struct V_132 * V_8 = F_97 ( V_115 ,
struct V_132 ,
V_140 ) ;
struct V_56 * V_56 = V_8 -> V_56 ;
if ( V_115 -> V_163 )
F_86 ( V_56 , V_115 -> V_163 ) ;
}
static void
F_98 ( struct V_164 * V_164 )
{
struct V_151 * V_152 = F_92 ( V_164 ) ;
struct V_56 * V_56 = (struct V_56 * ) V_152 -> V_155 ;
F_86 ( V_56 , - V_165 ) ;
}
int F_6 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_13 )
{
struct V_56 * V_56 = V_11 -> V_75 -> V_86 ;
if ( F_11 ( V_19 , V_20 , V_13 ) )
return 0 ;
return F_44 ( V_19 , V_20 , L_10 , V_13 , V_56 ) ;
}
int F_8 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_17 )
{
struct V_56 * V_56 = V_11 -> V_75 -> V_86 ;
if ( F_11 ( V_19 , V_20 , V_17 ) )
return 0 ;
return F_44 ( V_19 , V_20 , L_11 , V_17 , V_56 ) ;
}
int F_99 ( const struct V_10 * V_11 , T_1 V_13 , char * V_23 , T_2 V_25 )
{
struct V_56 * V_56 = V_11 -> V_75 -> V_86 ;
int V_29 = - V_65 ;
if ( ! ( V_11 -> V_166 & V_167 ) )
V_29 = F_43 ( V_13 , L_12 , V_23 , V_25 , V_56 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_13 , V_23 , V_25 ) ;
return V_29 ;
}
int F_100 ( const struct V_10 * V_11 , T_1 V_17 , char * V_23 , T_2 V_25 )
{
struct V_56 * V_56 = V_11 -> V_75 -> V_86 ;
int V_29 = - V_65 ;
if ( ! ( V_11 -> V_166 & V_167 ) )
V_29 = F_43 ( V_17 , L_13 , V_23 , V_25 , V_56 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_17 , V_23 , V_25 ) ;
return V_29 ;
}
