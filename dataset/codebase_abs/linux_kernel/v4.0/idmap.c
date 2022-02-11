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
T_2 V_17 ;
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
int F_11 ( const char * V_19 , T_3 V_20 , T_4 * V_21 )
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
static int F_13 ( T_4 V_24 , char * V_23 , T_3 V_25 )
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
V_28 = F_17 ( L_3 ,
V_33 , V_34 , V_26 ,
( V_35 & ~ V_36 ) |
V_37 | V_38 ,
V_39 , NULL ) ;
if ( F_18 ( V_28 ) ) {
V_29 = F_19 ( V_28 ) ;
goto V_40;
}
V_29 = F_20 ( & V_31 ) ;
if ( V_29 < 0 )
goto V_41;
V_29 = F_20 ( & V_42 ) ;
if ( V_29 < 0 )
goto V_43;
F_21 ( V_44 , & V_28 -> V_45 ) ;
V_26 -> V_46 = V_28 ;
V_26 -> V_47 = V_48 ;
V_49 = V_26 ;
return 0 ;
V_43:
F_22 ( & V_31 ) ;
V_41:
F_23 ( V_28 ) ;
V_40:
F_24 ( V_26 ) ;
return V_29 ;
}
static void F_25 ( void )
{
F_26 ( V_49 -> V_46 ) ;
F_22 ( & V_31 ) ;
F_22 ( & V_42 ) ;
F_24 ( V_49 ) ;
}
static T_5 F_27 ( const char * V_19 , T_3 V_20 ,
const char * type , T_3 V_50 , char * * V_51 )
{
char * V_52 ;
T_3 V_53 = V_50 + V_20 + 2 ;
* V_51 = F_28 ( V_53 , V_54 ) ;
if ( ! * V_51 )
return - V_32 ;
V_52 = * V_51 ;
memcpy ( V_52 , type , V_50 ) ;
V_52 += V_50 ;
* V_52 ++ = ':' ;
memcpy ( V_52 , V_19 , V_20 ) ;
V_52 += V_20 ;
* V_52 = '\0' ;
return V_53 ;
}
static struct V_27 * F_29 ( const char * V_19 , T_3 V_20 ,
const char * type , struct V_55 * V_55 )
{
char * V_51 ;
struct V_27 * V_56 ;
T_5 V_29 ;
V_29 = F_27 ( V_19 , V_20 , type , strlen ( type ) , & V_51 ) ;
if ( V_29 <= 0 )
return F_30 ( V_29 ) ;
V_56 = F_31 ( & V_31 , V_51 , L_4 ) ;
if ( F_18 ( V_56 ) ) {
F_32 ( & V_55 -> V_57 ) ;
V_56 = F_33 ( & V_42 ,
V_51 , L_4 , 0 , V_55 ) ;
F_34 ( & V_55 -> V_57 ) ;
}
if ( ! F_18 ( V_56 ) )
F_21 ( V_58 , & V_56 -> V_45 ) ;
F_3 ( V_51 ) ;
return V_56 ;
}
static T_5 F_35 ( const char * V_19 , T_3 V_20 ,
const char * type , void * V_8 ,
T_3 V_59 , struct V_55 * V_55 )
{
const struct V_26 * V_60 ;
struct V_27 * V_56 ;
struct V_61 * V_62 ;
T_5 V_29 ;
V_60 = F_36 ( V_49 ) ;
V_56 = F_29 ( V_19 , V_20 , type , V_55 ) ;
F_37 ( V_60 ) ;
if ( F_18 ( V_56 ) ) {
V_29 = F_19 ( V_56 ) ;
goto V_63;
}
F_38 () ;
V_56 -> V_64 |= V_37 ;
V_29 = F_39 ( V_56 ) ;
if ( V_29 < 0 )
goto V_65;
V_62 = F_40 ( V_56 -> V_62 . V_66 ) ;
if ( F_41 ( V_62 ) ) {
V_29 = F_19 ( V_62 ) ;
goto V_65;
}
V_29 = V_62 -> V_67 ;
if ( V_29 > 0 && V_29 <= V_59 )
memcpy ( V_8 , V_62 -> V_8 , V_29 ) ;
else
V_29 = - V_68 ;
V_65:
F_42 () ;
F_23 ( V_56 ) ;
V_63:
return V_29 ;
}
static T_5 F_43 ( T_4 V_24 , const char * type , char * V_23 ,
T_3 V_25 , struct V_55 * V_55 )
{
char V_69 [ V_70 ] ;
int V_71 ;
T_5 V_29 ;
V_71 = snprintf ( V_69 , sizeof( V_69 ) , L_1 , V_24 ) ;
V_29 = F_35 ( V_69 , V_71 , type , V_23 , V_25 , V_55 ) ;
if ( V_29 < 0 )
return - V_68 ;
return V_29 ;
}
static int F_44 ( const char * V_19 , T_3 V_20 , const char * type ,
T_4 * V_24 , struct V_55 * V_55 )
{
char V_69 [ V_70 ] ;
long V_72 ;
T_5 V_59 ;
int V_29 = 0 ;
V_59 = F_35 ( V_19 , V_20 , type , V_69 , V_70 , V_55 ) ;
if ( V_59 <= 0 ) {
V_29 = - V_68 ;
} else {
V_29 = F_45 ( V_69 , 10 , & V_72 ) ;
* V_24 = ( T_4 ) V_72 ;
}
return V_29 ;
}
static void F_46 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_55 * V_55 = V_76 -> V_77 ;
struct V_78 * V_79 = V_55 -> V_80 ;
if ( V_79 -> V_73 ) {
F_47 ( V_79 -> V_73 ) ;
V_79 -> V_73 = NULL ;
}
}
static int F_48 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_55 * V_55 = V_76 -> V_77 ;
struct V_78 * V_79 = V_55 -> V_80 ;
struct V_73 * V_73 ;
V_73 = F_49 ( V_74 , L_5 , V_55 , V_79 ) ;
if ( F_18 ( V_73 ) )
return F_19 ( V_73 ) ;
V_79 -> V_73 = V_73 ;
return 0 ;
}
int
F_50 ( struct V_81 * V_82 )
{
struct V_55 * V_55 ;
struct V_78 * V_79 ;
int error ;
V_55 = F_51 ( sizeof( * V_55 ) , V_54 ) ;
if ( V_55 == NULL )
return - V_32 ;
F_52 ( & V_55 -> V_83 ,
& V_84 ,
V_55 ) ;
V_79 = F_53 ( & V_85 , 0 ) ;
if ( F_18 ( V_79 ) ) {
error = F_19 ( V_79 ) ;
goto V_86;
}
V_55 -> V_80 = V_79 ;
F_54 ( & V_55 -> V_57 ) ;
error = F_55 ( V_82 -> V_87 ,
& V_82 -> V_88 -> V_89 ,
& V_55 -> V_83 ) ;
if ( error )
goto V_90;
V_82 -> V_91 = V_55 ;
return 0 ;
V_90:
F_56 ( V_55 -> V_80 ) ;
V_86:
F_3 ( V_55 ) ;
return error ;
}
void
F_57 ( struct V_81 * V_82 )
{
struct V_55 * V_55 = V_82 -> V_91 ;
if ( ! V_55 )
return;
V_82 -> V_91 = NULL ;
F_58 ( V_82 -> V_87 ,
& V_82 -> V_88 -> V_89 ,
& V_55 -> V_83 ) ;
F_56 ( V_55 -> V_80 ) ;
F_3 ( V_55 ) ;
}
int F_59 ( void )
{
int V_29 ;
V_29 = F_14 () ;
if ( V_29 != 0 )
goto V_63;
V_63:
return V_29 ;
}
void F_60 ( void )
{
F_25 () ;
}
static int F_61 ( char * V_51 , struct V_55 * V_55 ,
struct V_92 * V_93 ,
struct V_94 * V_95 )
{
T_6 V_96 ;
int V_97 , V_29 ;
V_93 -> V_98 = V_99 ;
V_97 = F_62 ( V_51 , V_100 , & V_96 ) ;
switch ( V_97 ) {
case V_101 :
V_93 -> V_98 = V_102 ;
case V_103 :
V_93 -> V_104 = V_105 ;
V_29 = F_63 ( V_93 -> V_106 , & V_96 , V_107 ) ;
break;
case V_108 :
V_93 -> V_98 = V_102 ;
case V_109 :
V_93 -> V_104 = V_110 ;
V_29 = F_64 ( & V_96 , & V_93 -> V_111 ) ;
break;
default:
V_29 = - V_68 ;
goto V_63;
}
V_95 -> V_8 = V_93 ;
V_95 -> V_14 = sizeof( struct V_92 ) ;
V_63:
return V_29 ;
}
static bool
F_65 ( struct V_55 * V_55 ,
struct V_112 * V_8 )
{
if ( V_55 -> V_113 != NULL ) {
F_66 ( 1 ) ;
return false ;
}
V_55 -> V_113 = V_8 ;
return true ;
}
static void
F_67 ( struct V_55 * V_55 , int V_29 )
{
struct V_114 * V_115 = V_55 -> V_113 -> V_116 ;
F_3 ( V_55 -> V_113 ) ;
V_55 -> V_113 = NULL ;
F_68 ( V_115 , V_29 ) ;
}
static void
F_69 ( struct V_55 * V_55 , int V_29 )
{
if ( V_55 -> V_113 != NULL )
F_67 ( V_55 , V_29 ) ;
}
static int F_70 ( struct V_114 * V_115 ,
const char * V_117 ,
void * V_118 )
{
struct V_112 * V_8 ;
struct V_94 * V_95 ;
struct V_92 * V_93 ;
struct V_55 * V_55 = (struct V_55 * ) V_118 ;
struct V_27 * V_27 = V_115 -> V_27 ;
int V_29 = - V_32 ;
V_8 = F_51 ( sizeof( * V_8 ) , V_54 ) ;
if ( ! V_8 )
goto V_119;
V_95 = & V_8 -> V_120 ;
V_93 = & V_8 -> V_92 ;
V_8 -> V_55 = V_55 ;
V_8 -> V_116 = V_115 ;
V_29 = F_61 ( V_27 -> V_121 , V_55 , V_93 , V_95 ) ;
if ( V_29 < 0 )
goto V_122;
V_29 = - V_123 ;
if ( ! F_65 ( V_55 , V_8 ) )
goto V_122;
V_29 = F_71 ( V_55 -> V_80 , V_95 ) ;
if ( V_29 < 0 )
F_69 ( V_55 , V_29 ) ;
return V_29 ;
V_122:
F_3 ( V_8 ) ;
V_119:
F_68 ( V_115 , V_29 ) ;
return V_29 ;
}
static int F_72 ( struct V_27 * V_27 , struct V_27 * V_124 , char * V_8 , T_3 V_67 )
{
return F_73 ( V_27 , V_8 , V_67 ,
V_49 -> V_46 ,
V_124 ) ;
}
static int F_74 ( struct V_92 * V_93 ,
struct V_92 * V_125 ,
struct V_27 * V_27 , struct V_27 * V_124 )
{
char V_69 [ V_70 ] ;
T_3 V_14 ;
int V_29 = - V_126 ;
if ( V_125 -> V_98 != V_93 -> V_98 || V_125 -> V_104 != V_93 -> V_104 )
goto V_63;
switch ( V_93 -> V_104 ) {
case V_105 :
if ( strcmp ( V_125 -> V_106 , V_93 -> V_106 ) != 0 )
break;
V_14 = sprintf ( V_69 , L_6 , V_93 -> V_111 ) + 1 ;
V_29 = F_72 ( V_27 , V_124 , V_69 , V_14 ) ;
break;
case V_110 :
if ( V_125 -> V_111 != V_93 -> V_111 )
break;
V_14 = strlen ( V_93 -> V_106 ) ;
V_29 = F_72 ( V_27 , V_124 , V_93 -> V_106 , V_14 ) ;
break;
default:
V_29 = - V_68 ;
}
V_63:
return V_29 ;
}
static T_5
F_75 ( struct V_127 * V_128 , const char T_7 * V_129 , T_3 V_130 )
{
struct V_131 * V_132 = F_76 ( F_77 ( V_128 ) ) ;
struct V_55 * V_55 = (struct V_55 * ) V_132 -> V_133 ;
struct V_114 * V_115 ;
struct V_92 V_93 ;
T_3 V_134 ;
int V_29 = - V_126 ;
if ( V_55 -> V_113 == NULL )
goto V_135;
V_115 = V_55 -> V_113 -> V_116 ;
if ( V_130 != sizeof( V_93 ) ) {
V_29 = - V_136 ;
goto V_63;
}
if ( F_78 ( & V_93 , V_129 , V_130 ) != 0 ) {
V_29 = - V_137 ;
goto V_63;
}
if ( ! ( V_93 . V_138 & V_139 ) ) {
V_29 = - V_126 ;
goto V_63;
}
V_134 = F_79 ( V_93 . V_106 , V_107 ) ;
if ( V_134 == 0 || V_134 == V_107 ) {
V_29 = - V_68 ;
goto V_63;
}
V_29 = F_74 ( & V_93 ,
& V_55 -> V_113 -> V_92 ,
V_115 -> V_27 , V_115 -> V_124 ) ;
if ( V_29 >= 0 ) {
F_80 ( V_115 -> V_27 , V_140 ) ;
V_29 = V_130 ;
}
V_63:
F_67 ( V_55 , V_29 ) ;
V_135:
return V_29 ;
}
static void
F_81 ( struct V_94 * V_95 )
{
struct V_112 * V_8 = F_82 ( V_95 ,
struct V_112 ,
V_120 ) ;
struct V_55 * V_55 = V_8 -> V_55 ;
if ( V_95 -> V_141 )
F_69 ( V_55 , V_95 -> V_141 ) ;
}
static void
F_83 ( struct V_142 * V_142 )
{
struct V_131 * V_132 = F_76 ( V_142 ) ;
struct V_55 * V_55 = (struct V_55 * ) V_132 -> V_133 ;
F_69 ( V_55 , - V_143 ) ;
}
int F_6 ( const struct V_10 * V_11 , const char * V_19 , T_3 V_20 , T_1 * V_13 )
{
struct V_55 * V_55 = V_11 -> V_81 -> V_91 ;
T_4 V_24 = - 1 ;
int V_29 = 0 ;
if ( ! F_11 ( V_19 , V_20 , & V_24 ) )
V_29 = F_44 ( V_19 , V_20 , L_7 , & V_24 , V_55 ) ;
if ( V_29 == 0 ) {
* V_13 = F_84 ( & V_144 , V_24 ) ;
if ( ! F_85 ( * V_13 ) )
V_29 = - V_145 ;
}
F_86 ( V_19 , V_20 , V_24 , V_29 ) ;
return V_29 ;
}
int F_8 ( const struct V_10 * V_11 , const char * V_19 , T_3 V_20 , T_2 * V_17 )
{
struct V_55 * V_55 = V_11 -> V_81 -> V_91 ;
T_4 V_24 = - 1 ;
int V_29 = 0 ;
if ( ! F_11 ( V_19 , V_20 , & V_24 ) )
V_29 = F_44 ( V_19 , V_20 , L_8 , & V_24 , V_55 ) ;
if ( V_29 == 0 ) {
* V_17 = F_87 ( & V_144 , V_24 ) ;
if ( ! F_88 ( * V_17 ) )
V_29 = - V_145 ;
}
F_89 ( V_19 , V_20 , V_24 , V_29 ) ;
return V_29 ;
}
int F_90 ( const struct V_10 * V_11 , T_1 V_13 , char * V_23 , T_3 V_25 )
{
struct V_55 * V_55 = V_11 -> V_81 -> V_91 ;
int V_29 = - V_68 ;
T_4 V_24 ;
V_24 = F_91 ( & V_144 , V_13 ) ;
if ( ! ( V_11 -> V_146 & V_147 ) )
V_29 = F_43 ( V_24 , L_9 , V_23 , V_25 , V_55 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_24 , V_23 , V_25 ) ;
F_92 ( V_23 , V_29 , V_24 , V_29 ) ;
return V_29 ;
}
int F_93 ( const struct V_10 * V_11 , T_2 V_17 , char * V_23 , T_3 V_25 )
{
struct V_55 * V_55 = V_11 -> V_81 -> V_91 ;
int V_29 = - V_68 ;
T_4 V_24 ;
V_24 = F_94 ( & V_144 , V_17 ) ;
if ( ! ( V_11 -> V_146 & V_147 ) )
V_29 = F_43 ( V_24 , L_10 , V_23 , V_25 , V_55 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_24 , V_23 , V_25 ) ;
F_95 ( V_23 , V_29 , V_24 , V_29 ) ;
return V_29 ;
}
