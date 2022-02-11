char F_1 ( const struct V_1 * V_1 )
{
static const char V_2 [] = {
[ V_3 ] = 'k' ,
[ V_4 ] = 'v' ,
[ V_5 ] = 'j' ,
[ V_6 ] = 'l' ,
[ V_7 ] = 'B' ,
[ V_8 ] = 'f' ,
[ V_9 ] = 'u' ,
[ V_10 ] = 'o' ,
[ V_11 ] = 'b' ,
[ V_12 ] = 'd' ,
[ V_13 ] = 'K' ,
[ V_14 ] = 'm' ,
[ V_15 ] = 'g' ,
[ V_16 ] = 'G' ,
[ V_17 ] = 'M' ,
[ V_18 ] = 'V' ,
} ;
if ( V_1 == NULL || V_1 -> V_19 == V_20 )
return '!' ;
return V_2 [ V_1 -> V_19 ] ;
}
int F_2 ( const struct V_1 * V_1 ,
enum V_21 type ,
char * V_22 , char * V_23 , T_1 V_24 )
{
char V_25 [ V_26 * 2 + 1 ] ;
int V_27 = 0 ;
T_1 V_28 ;
switch ( type ) {
case V_6 : {
char * V_29 ;
V_28 = F_3 ( V_23 , V_24 , V_1 -> V_30 ) ;
V_29 = V_23 + V_28 ;
while ( V_29 != V_23 && * V_29 != '/' )
V_29 -- ;
if ( * V_29 == '/' )
V_29 ++ ;
V_27 = F_4 ( V_23 , V_29 ,
V_24 - ( V_29 - V_23 ) ) ;
}
break;
case V_7 :
if ( V_31 . V_32 [ 0 ] ||
( F_5 ( V_1 , V_23 , V_24 ) == NULL ) )
V_27 = - 1 ;
break;
case V_8 :
V_28 = F_3 ( V_23 , V_24 , L_1 ) ;
snprintf ( V_23 + V_28 , V_24 - V_28 , L_2 , V_1 -> V_30 ) ;
break;
case V_9 :
V_28 = F_3 ( V_23 , V_24 , L_1 ) ;
snprintf ( V_23 + V_28 , V_24 - V_28 , L_3 , V_1 -> V_30 ) ;
break;
case V_10 :
{
const char * V_33 ;
T_1 V_34 ;
V_33 = V_1 -> V_30 + V_1 -> V_35 ;
while ( V_33 != V_1 -> V_30 && * V_33 != '/' )
V_33 -- ;
V_28 = F_3 ( V_23 , V_24 , L_4 ) ;
V_34 = V_33 - V_1 -> V_30 + 2 ;
if ( V_34 > ( V_24 - V_28 ) ) {
V_27 = - 1 ;
break;
}
V_28 += F_6 ( V_23 + V_28 , V_34 , L_3 , V_1 -> V_30 ) ;
V_28 += F_6 ( V_23 + V_28 , V_24 - V_28 , L_5 ,
V_33 ) ;
break;
}
case V_11 :
if ( ! V_1 -> V_36 ) {
V_27 = - 1 ;
break;
}
F_7 ( V_1 -> V_37 ,
sizeof( V_1 -> V_37 ) ,
V_25 ) ;
V_28 = F_3 ( V_23 , V_24 , L_6 ) ;
snprintf ( V_23 + V_28 , V_24 - V_28 , L_7 ,
V_25 , V_25 + 2 ) ;
break;
case V_4 :
case V_18 :
case V_12 :
F_3 ( V_23 , V_24 , V_1 -> V_30 ) ;
break;
case V_16 :
case V_17 :
F_8 ( V_23 , V_24 , V_31 . V_32 ,
V_22 , V_1 -> V_30 ) ;
break;
case V_13 :
case V_14 :
F_3 ( V_23 , V_24 , V_1 -> V_30 ) ;
break;
case V_38 :
case V_39 :
snprintf ( V_23 , V_24 , L_3 , V_1 -> V_30 ) ;
break;
default:
case V_3 :
case V_15 :
case V_5 :
case V_20 :
V_27 = - 1 ;
break;
}
return V_27 ;
}
bool F_9 ( const char * V_40 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_42 [ V_41 ] . V_43 ; V_41 ++ ) {
if ( ! strcmp ( V_40 , V_42 [ V_41 ] . V_43 ) )
return true ;
}
return false ;
}
bool F_10 ( const char * V_44 )
{
struct V_45 V_46 ;
if ( F_11 ( & V_46 , V_44 ) )
return NULL ;
return V_46 . V_47 ;
}
bool F_12 ( const char * V_40 , const char * V_23 , int V_48 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_42 [ V_41 ] . V_43 ; V_41 ++ ) {
if ( ! strcmp ( V_40 , V_42 [ V_41 ] . V_43 ) )
return ! V_42 [ V_41 ] . F_13 ( V_23 ,
V_48 ) ;
}
return false ;
}
bool F_14 ( struct V_1 * V_1 )
{
return V_1 -> V_19 == V_14 ||
V_1 -> V_19 == V_17 ;
}
int F_15 ( struct V_45 * V_46 , const char * V_49 ,
bool V_50 , bool V_51 )
{
const char * V_52 = strrchr ( V_49 , '/' ) ;
const char * V_40 = strrchr ( V_49 , '.' ) ;
memset ( V_46 , 0x0 , sizeof( * V_46 ) ) ;
V_52 = V_52 ? V_52 + 1 : V_49 ;
if ( V_40 == NULL ) {
if ( V_50 ) {
V_46 -> V_52 = F_16 ( V_52 ) ;
return V_46 -> V_52 ? 0 : - V_53 ;
}
return 0 ;
}
if ( F_9 ( V_40 + 1 ) ) {
V_46 -> V_54 = true ;
V_40 -= 3 ;
}
if ( V_40 > V_52 )
V_46 -> V_47 = ! strncmp ( V_40 , L_8 , 3 ) ;
if ( V_50 ) {
if ( V_46 -> V_47 ) {
if ( F_17 ( & V_46 -> V_52 , L_9 , ( int ) ( V_40 - V_52 ) , V_52 ) == - 1 )
return - V_53 ;
} else {
if ( F_17 ( & V_46 -> V_52 , L_3 , V_52 ) == - 1 )
return - V_53 ;
}
F_18 ( V_46 -> V_52 , '-' , '_' ) ;
}
if ( V_51 && V_46 -> V_54 ) {
V_46 -> V_40 = F_16 ( V_40 + 4 ) ;
if ( ! V_46 -> V_40 ) {
free ( ( void * ) V_46 -> V_52 ) ;
return - V_53 ;
}
}
return 0 ;
}
static void F_19 ( struct V_1 * V_1 )
{
F_20 ( & V_1 -> V_55 . V_56 , & V_57 ) ;
V_58 ++ ;
}
static void F_21 ( struct V_1 * V_1 )
{
F_22 ( & V_1 -> V_55 . V_56 ) ;
F_23 ( V_58 <= 0 ,
L_10 ) ;
V_58 -- ;
}
static int F_24 ( char * V_52 )
{
int V_59 ;
char V_60 [ V_61 ] ;
do {
V_59 = F_25 ( V_52 , V_62 ) ;
if ( V_59 >= 0 )
return V_59 ;
F_26 ( L_11 ,
F_27 ( V_63 , V_60 , sizeof( V_60 ) ) ) ;
if ( ! V_58 || V_63 != V_64 )
break;
F_28 () ;
} while ( 1 );
return - 1 ;
}
static int F_29 ( struct V_1 * V_1 , struct V_65 * V_65 )
{
int V_59 ;
char * V_22 = ( char * ) L_4 ;
char * V_52 = malloc ( V_66 ) ;
if ( ! V_52 )
return - V_53 ;
if ( V_65 )
V_22 = V_65 -> V_22 ;
if ( F_2 ( V_1 , V_1 -> V_67 ,
V_22 , V_52 , V_66 ) ) {
free ( V_52 ) ;
return - V_68 ;
}
V_59 = F_24 ( V_52 ) ;
free ( V_52 ) ;
return V_59 ;
}
static int F_30 ( struct V_1 * V_1 , struct V_65 * V_65 )
{
int V_59 = F_29 ( V_1 , V_65 ) ;
if ( V_59 >= 0 ) {
F_19 ( V_1 ) ;
F_31 () ;
}
return V_59 ;
}
static void F_32 ( struct V_1 * V_1 )
{
if ( V_1 -> V_55 . V_59 >= 0 ) {
F_33 ( V_1 -> V_55 . V_59 ) ;
V_1 -> V_55 . V_59 = - 1 ;
V_1 -> V_55 . V_69 = 0 ;
F_21 ( V_1 ) ;
}
}
static void F_34 ( struct V_1 * V_1 )
{
F_32 ( V_1 ) ;
}
static void F_28 ( void )
{
struct V_1 * V_1 ;
V_1 = F_35 ( & V_57 , struct V_1 , V_55 . V_56 ) ;
F_34 ( V_1 ) ;
}
static T_2 F_36 ( void )
{
struct V_70 V_71 ;
T_2 V_72 = 0 ;
if ( F_37 ( V_73 , & V_71 ) == 0 ) {
if ( V_71 . V_74 == V_75 )
V_72 = V_71 . V_74 ;
else
V_72 = V_71 . V_74 / 2 ;
} else {
F_38 ( L_12 ) ;
V_72 = 1 ;
}
return V_72 ;
}
static bool F_39 ( void )
{
static T_2 V_72 ;
if ( ! V_72 )
V_72 = F_36 () ;
if ( V_72 == V_75 )
return true ;
return V_72 > ( T_2 ) V_58 ;
}
static void F_31 ( void )
{
bool V_76 = F_39 () ;
if ( ! V_76 )
F_28 () ;
}
void F_40 ( struct V_1 * V_1 )
{
F_34 ( V_1 ) ;
}
int F_41 ( struct V_1 * V_1 , struct V_65 * V_65 )
{
enum V_21 V_77 [] = {
V_7 ,
V_12 ,
V_20 ,
} ;
int V_41 = 0 ;
if ( V_1 -> V_55 . V_78 == V_79 )
return - 1 ;
if ( V_1 -> V_55 . V_59 >= 0 )
goto V_80;
if ( V_1 -> V_67 != V_20 ) {
V_1 -> V_55 . V_59 = F_30 ( V_1 , V_65 ) ;
goto V_80;
}
do {
V_1 -> V_67 = V_77 [ V_41 ++ ] ;
V_1 -> V_55 . V_59 = F_30 ( V_1 , V_65 ) ;
if ( V_1 -> V_55 . V_59 >= 0 )
goto V_80;
} while ( V_1 -> V_67 != V_20 );
V_80:
if ( V_1 -> V_55 . V_59 >= 0 )
V_1 -> V_55 . V_78 = V_81 ;
else
V_1 -> V_55 . V_78 = V_79 ;
return V_1 -> V_55 . V_59 ;
}
bool F_42 ( struct V_1 * V_1 , enum V_82 V_83 )
{
T_3 V_84 = 1 << V_83 ;
if ( V_1 -> V_55 . V_85 & V_84 )
return true ;
V_1 -> V_55 . V_85 |= V_84 ;
return false ;
}
static void
F_43 ( struct V_86 * V_87 )
{
struct V_88 * V_89 = F_44 ( V_87 ) ;
while ( V_89 ) {
struct V_90 * V_91 ;
V_91 = F_45 ( V_89 , struct V_90 , V_88 ) ;
V_89 = F_46 ( & V_91 -> V_88 ) ;
F_47 ( & V_91 -> V_88 , V_87 ) ;
free ( V_91 ) ;
}
}
static struct V_90 * F_48 ( const struct V_86 * V_87 , T_4 V_92 )
{
struct V_88 * const * V_93 = & V_87 -> V_88 ;
const struct V_88 * V_94 = NULL ;
struct V_90 * V_91 ;
while ( * V_93 != NULL ) {
T_4 V_95 ;
V_94 = * V_93 ;
V_91 = F_45 ( V_94 , struct V_90 , V_88 ) ;
V_95 = V_91 -> V_92 + V_96 ;
if ( V_92 < V_91 -> V_92 )
V_93 = & ( * V_93 ) -> V_97 ;
else if ( V_92 >= V_95 )
V_93 = & ( * V_93 ) -> V_98 ;
else
return V_91 ;
}
return NULL ;
}
static void
F_49 ( struct V_86 * V_87 , struct V_90 * V_99 )
{
struct V_88 * * V_93 = & V_87 -> V_88 ;
struct V_88 * V_94 = NULL ;
struct V_90 * V_91 ;
T_4 V_92 = V_99 -> V_92 ;
while ( * V_93 != NULL ) {
T_4 V_95 ;
V_94 = * V_93 ;
V_91 = F_45 ( V_94 , struct V_90 , V_88 ) ;
V_95 = V_91 -> V_92 + V_96 ;
if ( V_92 < V_91 -> V_92 )
V_93 = & ( * V_93 ) -> V_97 ;
else if ( V_92 >= V_95 )
V_93 = & ( * V_93 ) -> V_98 ;
}
F_50 ( & V_99 -> V_88 , V_94 , V_93 ) ;
F_51 ( & V_99 -> V_88 , V_87 ) ;
}
static T_5
F_52 ( struct V_90 * V_91 , T_4 V_92 ,
T_6 * V_55 , T_4 V_24 )
{
T_4 V_100 = V_92 - V_91 -> V_92 ;
T_4 V_101 = F_53 ( V_91 -> V_24 - V_100 , V_24 ) ;
memcpy ( V_55 , V_91 -> V_55 + V_100 , V_101 ) ;
return V_101 ;
}
static T_5
F_54 ( struct V_1 * V_1 , T_4 V_92 , T_6 * V_55 , T_5 V_24 )
{
struct V_90 * V_91 ;
T_5 V_27 ;
do {
T_4 V_100 ;
V_27 = - V_53 ;
V_91 = F_55 ( sizeof( * V_91 ) + V_96 ) ;
if ( ! V_91 )
break;
V_100 = V_92 & V_102 ;
V_27 = F_56 ( V_1 -> V_55 . V_59 , V_91 -> V_55 , V_96 , V_100 ) ;
if ( V_27 <= 0 )
break;
V_91 -> V_92 = V_100 ;
V_91 -> V_24 = V_27 ;
F_49 ( & V_1 -> V_55 . V_91 , V_91 ) ;
V_27 = F_52 ( V_91 , V_92 , V_55 , V_24 ) ;
} while ( 0 );
if ( V_27 <= 0 )
free ( V_91 ) ;
return V_27 ;
}
static T_5 F_57 ( struct V_1 * V_1 , T_4 V_92 ,
T_6 * V_55 , T_5 V_24 )
{
struct V_90 * V_91 ;
V_91 = F_48 ( & V_1 -> V_55 . V_91 , V_92 ) ;
if ( V_91 )
return F_52 ( V_91 , V_92 , V_55 , V_24 ) ;
else
return F_54 ( V_1 , V_92 , V_55 , V_24 ) ;
}
static T_5 F_58 ( struct V_1 * V_1 , T_4 V_92 , T_6 * V_55 , T_5 V_24 )
{
T_5 V_103 = 0 ;
T_6 * V_93 = V_55 ;
do {
T_5 V_27 ;
V_27 = F_57 ( V_1 , V_92 , V_93 , V_24 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! V_27 )
break;
F_59 ( V_27 > V_24 ) ;
V_103 += V_27 ;
V_93 += V_27 ;
V_92 += V_27 ;
V_24 -= V_27 ;
} while ( V_24 );
return V_103 ;
}
static int F_60 ( struct V_1 * V_1 )
{
struct V_104 V_105 ;
char V_60 [ V_61 ] ;
if ( ! V_1 -> V_55 . V_69 ) {
if ( F_61 ( V_1 -> V_55 . V_59 , & V_105 ) ) {
F_38 ( L_13 ,
F_27 ( V_63 , V_60 , sizeof( V_60 ) ) ) ;
return - 1 ;
}
V_1 -> V_55 . V_69 = V_105 . V_106 ;
}
return 0 ;
}
T_7 F_62 ( struct V_1 * V_1 , struct V_65 * V_65 )
{
int V_59 ;
V_59 = F_41 ( V_1 , V_65 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( F_60 ( V_1 ) )
return - 1 ;
return V_1 -> V_55 . V_69 ;
}
static T_5 F_63 ( struct V_1 * V_1 , T_4 V_92 ,
T_6 * V_55 , T_5 V_24 )
{
if ( F_60 ( V_1 ) )
return - 1 ;
if ( V_92 > V_1 -> V_55 . V_69 )
return - 1 ;
if ( V_92 + V_24 < V_92 )
return - 1 ;
return F_58 ( V_1 , V_92 , V_55 , V_24 ) ;
}
T_5 F_64 ( struct V_1 * V_1 , struct V_65 * V_65 ,
T_4 V_92 , T_6 * V_55 , T_5 V_24 )
{
if ( F_41 ( V_1 , V_65 ) < 0 )
return - 1 ;
return F_63 ( V_1 , V_92 , V_55 , V_24 ) ;
}
T_5 F_65 ( struct V_1 * V_1 , struct V_107 * V_107 ,
struct V_65 * V_65 , T_4 V_108 ,
T_6 * V_55 , T_5 V_24 )
{
T_4 V_92 = V_107 -> V_109 ( V_107 , V_108 ) ;
return F_64 ( V_1 , V_65 , V_92 , V_55 , V_24 ) ;
}
struct V_107 * F_66 ( const char * V_52 )
{
struct V_107 * V_107 = NULL ;
struct V_1 * V_1 = F_67 ( V_52 ) ;
if ( V_1 )
V_107 = F_68 ( 0 , V_1 , V_110 ) ;
return V_107 ;
}
struct V_1 * F_69 ( struct V_65 * V_65 , const char * V_52 ,
const char * V_111 , int V_112 )
{
struct V_1 * V_1 = F_70 ( & V_65 -> V_113 , V_52 ) ;
if ( V_1 != NULL ) {
F_71 ( V_1 , V_111 , false ) ;
V_1 -> V_114 = V_112 ;
}
return V_1 ;
}
static struct V_1 * F_72 ( struct V_86 * V_87 ,
struct V_1 * V_1 , const char * V_52 )
{
struct V_88 * * V_93 = & V_87 -> V_88 ;
struct V_88 * V_94 = NULL ;
if ( ! V_52 )
V_52 = V_1 -> V_30 ;
while ( * V_93 ) {
struct V_1 * V_115 = F_45 ( * V_93 , struct V_1 , V_88 ) ;
int V_116 = strcmp ( V_52 , V_115 -> V_30 ) ;
V_94 = * V_93 ;
if ( V_116 == 0 ) {
if ( ! V_1 || ( V_1 == V_115 ) )
return V_115 ;
V_116 = strcmp ( V_1 -> V_111 , V_115 -> V_111 ) ;
if ( V_116 == 0 ) {
F_38 ( L_14 , V_52 ) ;
return NULL ;
}
}
if ( V_116 < 0 )
V_93 = & V_94 -> V_97 ;
else
V_93 = & V_94 -> V_98 ;
}
if ( V_1 ) {
F_50 ( & V_1 -> V_88 , V_94 , V_93 ) ;
F_51 ( & V_1 -> V_88 , V_87 ) ;
}
return NULL ;
}
static inline struct V_1 *
F_73 ( const struct V_86 * V_87 , const char * V_52 )
{
return F_72 ( (struct V_86 * ) V_87 , NULL , V_52 ) ;
}
void F_74 ( struct V_1 * V_1 , const char * V_52 , bool V_117 )
{
if ( V_52 == NULL )
return;
if ( V_1 -> V_118 )
free ( ( char * ) V_1 -> V_30 ) ;
V_1 -> V_30 = V_52 ;
V_1 -> V_35 = strlen ( V_52 ) ;
V_1 -> V_118 = V_117 ;
}
void F_71 ( struct V_1 * V_1 , const char * V_52 , bool V_117 )
{
if ( V_52 == NULL )
return;
if ( V_1 -> V_119 )
free ( ( char * ) V_1 -> V_111 ) ;
V_1 -> V_111 = V_52 ;
V_1 -> V_120 = strlen ( V_52 ) ;
V_1 -> V_119 = V_117 ;
}
static void F_75 ( struct V_1 * V_1 )
{
char * V_121 , * V_122 = F_16 ( V_1 -> V_30 ) ;
if ( ! V_122 )
return;
V_121 = F_16 ( F_76 ( V_122 ) ) ;
free ( V_122 ) ;
if ( ! V_121 )
return;
F_71 ( V_1 , V_121 , true ) ;
}
int F_77 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_15 ) ;
if ( V_123 )
return V_1 -> V_35 ;
return V_1 -> V_120 ;
}
bool F_78 ( const struct V_1 * V_1 , enum V_124 type )
{
return V_1 -> V_125 & ( 1 << type ) ;
}
bool F_79 ( const struct V_1 * V_1 , enum V_124 type )
{
return V_1 -> V_126 & ( 1 << type ) ;
}
void F_80 ( struct V_1 * V_1 , enum V_124 type )
{
V_1 -> V_126 |= ( 1 << type ) ;
}
struct V_1 * F_67 ( const char * V_52 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_52 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_41 ;
strcpy ( V_1 -> V_52 , V_52 ) ;
F_74 ( V_1 , V_1 -> V_52 , false ) ;
F_71 ( V_1 , V_1 -> V_52 , false ) ;
for ( V_41 = 0 ; V_41 < V_127 ; ++ V_41 )
V_1 -> V_128 [ V_41 ] = V_1 -> V_129 [ V_41 ] = V_130 ;
V_1 -> V_55 . V_91 = V_130 ;
V_1 -> V_55 . V_59 = - 1 ;
V_1 -> V_55 . V_78 = V_131 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_67 = V_20 ;
V_1 -> V_132 = ( sizeof( void * ) == 8 ) ;
V_1 -> V_125 = 0 ;
V_1 -> V_133 = 0 ;
V_1 -> V_126 = 0 ;
V_1 -> V_36 = 0 ;
V_1 -> V_134 = 1 ;
V_1 -> V_135 = 1 ;
V_1 -> V_114 = V_136 ;
V_1 -> V_137 = V_138 ;
F_81 ( & V_1 -> V_88 ) ;
F_82 ( & V_1 -> V_139 ) ;
F_82 ( & V_1 -> V_55 . V_56 ) ;
}
return V_1 ;
}
void F_83 ( struct V_1 * V_1 )
{
int V_41 ;
if ( ! F_84 ( & V_1 -> V_88 ) )
F_38 ( L_16 ,
V_1 -> V_30 ) ;
for ( V_41 = 0 ; V_41 < V_127 ; ++ V_41 )
F_85 ( & V_1 -> V_128 [ V_41 ] ) ;
if ( V_1 -> V_119 ) {
F_86 ( ( char * * ) & V_1 -> V_111 ) ;
V_1 -> V_119 = false ;
}
if ( V_1 -> V_118 ) {
F_86 ( ( char * * ) & V_1 -> V_30 ) ;
V_1 -> V_118 = false ;
}
F_40 ( V_1 ) ;
F_43 ( & V_1 -> V_55 . V_91 ) ;
F_87 ( V_1 ) ;
F_86 ( & V_1 -> V_140 ) ;
free ( V_1 ) ;
}
void F_88 ( struct V_1 * V_1 , void * V_37 )
{
memcpy ( V_1 -> V_37 , V_37 , sizeof( V_1 -> V_37 ) ) ;
V_1 -> V_36 = 1 ;
}
bool F_89 ( const struct V_1 * V_1 , T_6 * V_37 )
{
return memcmp ( V_1 -> V_37 , V_37 , sizeof( V_1 -> V_37 ) ) == 0 ;
}
void F_90 ( struct V_1 * V_1 , struct V_65 * V_65 )
{
char V_49 [ V_66 ] ;
if ( F_91 ( V_65 ) )
return;
sprintf ( V_49 , L_17 , V_65 -> V_22 ) ;
if ( F_92 ( V_49 , V_1 -> V_37 ,
sizeof( V_1 -> V_37 ) ) == 0 )
V_1 -> V_36 = true ;
}
int F_93 ( struct V_1 * V_1 ,
const char * V_22 )
{
char V_23 [ V_66 ] ;
const char * V_52 = V_1 -> V_111 + 1 ;
snprintf ( V_23 , sizeof( V_23 ) ,
L_18 ,
V_22 , ( int ) strlen ( V_52 ) - 1 , V_52 ) ;
if ( F_92 ( V_23 , V_1 -> V_37 ,
sizeof( V_1 -> V_37 ) ) == 0 )
V_1 -> V_36 = true ;
return 0 ;
}
bool F_94 ( struct V_141 * V_142 , bool V_143 )
{
bool V_144 = false ;
struct V_1 * V_145 ;
F_95 (pos, head, node) {
if ( V_143 && ! V_145 -> V_146 )
continue;
if ( V_145 -> V_36 ) {
V_144 = true ;
continue;
}
if ( F_96 ( V_145 -> V_30 , V_145 -> V_37 ,
sizeof( V_145 -> V_37 ) ) > 0 ) {
V_144 = true ;
V_145 -> V_36 = true ;
}
}
return V_144 ;
}
void F_97 ( struct V_147 * V_147 , struct V_1 * V_1 )
{
F_20 ( & V_1 -> V_139 , & V_147 -> V_142 ) ;
F_72 ( & V_147 -> V_87 , V_1 , NULL ) ;
}
struct V_1 * F_98 ( const struct V_147 * V_147 , const char * V_52 ,
bool V_148 )
{
struct V_1 * V_145 ;
if ( V_148 ) {
F_95 (pos, &dsos->head, node)
if ( strcmp ( V_145 -> V_111 , V_52 ) == 0 )
return V_145 ;
return NULL ;
}
return F_73 ( & V_147 -> V_87 , V_52 ) ;
}
struct V_1 * F_99 ( struct V_147 * V_147 , const char * V_52 )
{
struct V_1 * V_1 = F_67 ( V_52 ) ;
if ( V_1 != NULL ) {
F_97 ( V_147 , V_1 ) ;
F_75 ( V_1 ) ;
}
return V_1 ;
}
struct V_1 * F_70 ( struct V_147 * V_147 , const char * V_52 )
{
struct V_1 * V_1 = F_98 ( V_147 , V_52 , false ) ;
return V_1 ? V_1 : F_99 ( V_147 , V_52 ) ;
}
T_1 F_100 ( struct V_141 * V_142 , T_8 * V_149 ,
bool (F_101)( struct V_1 * V_1 , int V_150 ) , int V_150 )
{
struct V_1 * V_145 ;
T_1 V_27 = 0 ;
F_95 (pos, head, node) {
if ( F_101 && F_101 ( V_145 , V_150 ) )
continue;
V_27 += F_102 ( V_145 , V_149 ) ;
V_27 += fprintf ( V_149 , L_19 , V_145 -> V_30 ) ;
}
return V_27 ;
}
T_1 F_103 ( struct V_141 * V_142 , T_8 * V_149 )
{
struct V_1 * V_145 ;
T_1 V_27 = 0 ;
F_95 (pos, head, node) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_127 ; ++ V_41 )
V_27 += F_104 ( V_145 , V_41 , V_149 ) ;
}
return V_27 ;
}
T_1 F_102 ( struct V_1 * V_1 , T_8 * V_149 )
{
char V_151 [ V_26 * 2 + 1 ] ;
F_7 ( V_1 -> V_37 , sizeof( V_1 -> V_37 ) , V_151 ) ;
return fprintf ( V_149 , L_3 , V_151 ) ;
}
T_1 F_104 ( struct V_1 * V_1 , enum V_124 type , T_8 * V_149 )
{
struct V_88 * V_152 ;
T_1 V_27 = fprintf ( V_149 , L_20 , V_1 -> V_111 ) ;
if ( V_1 -> V_111 != V_1 -> V_30 )
V_27 += fprintf ( V_149 , L_21 , V_1 -> V_30 ) ;
V_27 += fprintf ( V_149 , L_22 , V_153 [ type ] ,
F_78 ( V_1 , type ) ? L_4 : L_23 ) ;
V_27 += F_102 ( V_1 , V_149 ) ;
V_27 += fprintf ( V_149 , L_24 ) ;
for ( V_152 = F_44 ( & V_1 -> V_128 [ type ] ) ; V_152 ; V_152 = F_46 ( V_152 ) ) {
struct V_154 * V_145 = F_45 ( V_152 , struct V_154 , V_88 ) ;
V_27 += F_105 ( V_145 , V_149 ) ;
}
return V_27 ;
}
enum V_112 F_106 ( struct V_1 * V_1 , struct V_65 * V_65 )
{
int V_59 ;
V_59 = F_41 ( V_1 , V_65 ) ;
if ( V_59 < 0 )
return V_155 ;
return F_107 ( V_59 ) ;
}
int F_108 ( struct V_1 * V_1 , char * V_156 , T_1 V_157 )
{
int V_158 , V_159 = V_1 -> V_160 ;
static const char * V_161 [] = {
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
} ;
F_59 ( V_157 == 0 ) ;
if ( V_159 >= 0 ) {
const char * V_162 = F_27 ( V_159 , V_156 , V_157 ) ;
if ( V_162 != V_156 )
F_6 ( V_156 , V_157 , L_3 , V_162 ) ;
return 0 ;
}
if ( V_159 < V_163 || V_159 >= V_164 )
return - 1 ;
V_158 = V_159 - V_163 ;
F_6 ( V_156 , V_157 , L_3 , V_161 [ V_158 ] ) ;
return 0 ;
}
