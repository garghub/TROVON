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
strncpy ( V_23 , V_1 -> V_30 , V_24 ) ;
V_29 = V_23 + V_1 -> V_31 ;
while ( V_29 != V_23 && * V_29 != '/' )
V_29 -- ;
if ( * V_29 == '/' )
V_29 ++ ;
V_27 = F_3 ( V_1 -> V_30 , V_29 ,
V_24 - ( V_29 - V_23 ) ) ;
}
break;
case V_7 :
if ( V_32 . V_33 [ 0 ] ||
( F_4 ( V_1 , V_23 , V_24 ) == NULL ) )
V_27 = - 1 ;
break;
case V_8 :
V_28 = F_5 ( V_23 , V_24 , L_1 ) ;
snprintf ( V_23 + V_28 , V_24 - V_28 , L_2 , V_1 -> V_30 ) ;
break;
case V_9 :
V_28 = F_5 ( V_23 , V_24 , L_1 ) ;
snprintf ( V_23 + V_28 , V_24 - V_28 , L_3 , V_1 -> V_30 ) ;
break;
case V_10 :
{
const char * V_34 ;
T_1 V_35 ;
V_34 = V_1 -> V_30 + V_1 -> V_31 ;
while ( V_34 != V_1 -> V_30 && * V_34 != '/' )
V_34 -- ;
V_28 = F_5 ( V_23 , V_24 , L_4 ) ;
V_35 = V_34 - V_1 -> V_30 + 2 ;
if ( V_35 > ( V_24 - V_28 ) ) {
V_27 = - 1 ;
break;
}
V_28 += F_6 ( V_23 + V_28 , V_35 , L_3 , V_1 -> V_30 ) ;
V_28 += F_6 ( V_23 + V_28 , V_24 - V_28 , L_5 ,
V_34 ) ;
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
V_28 = F_5 ( V_23 , V_24 , L_6 ) ;
snprintf ( V_23 + V_28 , V_24 - V_28 , L_7 ,
V_25 , V_25 + 2 ) ;
break;
case V_4 :
case V_18 :
case V_12 :
F_5 ( V_23 , V_24 , V_1 -> V_30 ) ;
break;
case V_16 :
case V_17 :
F_8 ( V_23 , V_24 , V_32 . V_33 ,
V_22 , V_1 -> V_30 ) ;
break;
case V_13 :
case V_14 :
F_5 ( V_23 , V_24 , V_1 -> V_30 ) ;
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
bool F_10 ( const char * V_40 )
{
if ( strncmp ( V_40 , L_8 , 2 ) )
return false ;
if ( V_40 [ 2 ] == '\0' || ( V_40 [ 2 ] == '.' && F_9 ( V_40 + 3 ) ) )
return true ;
return false ;
}
bool F_11 ( const char * V_44 , bool * V_45 )
{
const char * V_40 = strrchr ( V_44 , '.' ) ;
if ( V_40 == NULL )
return false ;
if ( F_9 ( V_40 + 1 ) ) {
if ( V_45 )
* V_45 = true ;
V_40 -= 3 ;
} else if ( V_45 )
* V_45 = false ;
return F_10 ( V_40 + 1 ) ;
}
bool F_12 ( const char * V_40 , const char * V_23 , int V_46 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_42 [ V_41 ] . V_43 ; V_41 ++ ) {
if ( ! strcmp ( V_40 , V_42 [ V_41 ] . V_43 ) )
return ! V_42 [ V_41 ] . F_13 ( V_23 ,
V_46 ) ;
}
return false ;
}
bool F_14 ( struct V_1 * V_1 )
{
return V_1 -> V_19 == V_14 ||
V_1 -> V_19 == V_17 ;
}
static void F_15 ( struct V_1 * V_1 )
{
F_16 ( & V_1 -> V_47 . V_48 , & V_49 ) ;
V_50 ++ ;
}
static void F_17 ( struct V_1 * V_1 )
{
F_18 ( & V_1 -> V_47 . V_48 ) ;
F_19 ( V_50 <= 0 ,
L_9 ) ;
V_50 -- ;
}
static int F_20 ( char * V_51 )
{
int V_52 ;
char V_53 [ V_54 ] ;
do {
V_52 = F_21 ( V_51 , V_55 ) ;
if ( V_52 >= 0 )
return V_52 ;
F_22 ( L_10 ,
F_23 ( V_56 , V_53 , sizeof( V_53 ) ) ) ;
if ( ! V_50 || V_56 != V_57 )
break;
F_24 () ;
} while ( 1 );
return - 1 ;
}
static int F_25 ( struct V_1 * V_1 , struct V_58 * V_58 )
{
int V_52 ;
char * V_22 = ( char * ) L_4 ;
char * V_51 = malloc ( V_59 ) ;
if ( ! V_51 )
return - V_60 ;
if ( V_58 )
V_22 = V_58 -> V_22 ;
if ( F_2 ( V_1 , V_1 -> V_61 ,
V_22 , V_51 , V_59 ) ) {
free ( V_51 ) ;
return - V_62 ;
}
V_52 = F_20 ( V_51 ) ;
free ( V_51 ) ;
return V_52 ;
}
static int F_26 ( struct V_1 * V_1 , struct V_58 * V_58 )
{
int V_52 = F_25 ( V_1 , V_58 ) ;
if ( V_52 >= 0 ) {
F_15 ( V_1 ) ;
F_27 () ;
}
return V_52 ;
}
static void F_28 ( struct V_1 * V_1 )
{
if ( V_1 -> V_47 . V_52 >= 0 ) {
F_29 ( V_1 -> V_47 . V_52 ) ;
V_1 -> V_47 . V_52 = - 1 ;
V_1 -> V_47 . V_63 = 0 ;
F_17 ( V_1 ) ;
}
}
static void F_30 ( struct V_1 * V_1 )
{
F_28 ( V_1 ) ;
}
static void F_24 ( void )
{
struct V_1 * V_1 ;
V_1 = F_31 ( & V_49 , struct V_1 , V_47 . V_48 ) ;
F_30 ( V_1 ) ;
}
static T_2 F_32 ( void )
{
struct V_64 V_65 ;
T_2 V_66 = 0 ;
if ( F_33 ( V_67 , & V_65 ) == 0 ) {
if ( V_65 . V_68 == V_69 )
V_66 = V_65 . V_68 ;
else
V_66 = V_65 . V_68 / 2 ;
} else {
F_34 ( L_11 ) ;
V_66 = 1 ;
}
return V_66 ;
}
static bool F_35 ( void )
{
static T_2 V_66 ;
if ( ! V_66 )
V_66 = F_32 () ;
if ( V_66 == V_69 )
return true ;
return V_66 > ( T_2 ) V_50 ;
}
static void F_27 ( void )
{
bool V_70 = F_35 () ;
if ( ! V_70 )
F_24 () ;
}
void F_36 ( struct V_1 * V_1 )
{
F_30 ( V_1 ) ;
}
int F_37 ( struct V_1 * V_1 , struct V_58 * V_58 )
{
enum V_21 V_71 [] = {
V_7 ,
V_12 ,
V_20 ,
} ;
int V_41 = 0 ;
if ( V_1 -> V_47 . V_72 == V_73 )
return - 1 ;
if ( V_1 -> V_47 . V_52 >= 0 )
goto V_74;
if ( V_1 -> V_61 != V_20 ) {
V_1 -> V_47 . V_52 = F_26 ( V_1 , V_58 ) ;
goto V_74;
}
do {
V_1 -> V_61 = V_71 [ V_41 ++ ] ;
V_1 -> V_47 . V_52 = F_26 ( V_1 , V_58 ) ;
if ( V_1 -> V_47 . V_52 >= 0 )
goto V_74;
} while ( V_1 -> V_61 != V_20 );
V_74:
if ( V_1 -> V_47 . V_52 >= 0 )
V_1 -> V_47 . V_72 = V_75 ;
else
V_1 -> V_47 . V_72 = V_73 ;
return V_1 -> V_47 . V_52 ;
}
bool F_38 ( struct V_1 * V_1 , enum V_76 V_77 )
{
T_3 V_78 = 1 << V_77 ;
if ( V_1 -> V_47 . V_79 & V_78 )
return true ;
V_1 -> V_47 . V_79 |= V_78 ;
return false ;
}
static void
F_39 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_40 ( V_81 ) ;
while ( V_83 ) {
struct V_84 * V_85 ;
V_85 = F_41 ( V_83 , struct V_84 , V_82 ) ;
V_83 = F_42 ( & V_85 -> V_82 ) ;
F_43 ( & V_85 -> V_82 , V_81 ) ;
free ( V_85 ) ;
}
}
static struct V_84 * F_44 ( const struct V_80 * V_81 , T_4 V_86 )
{
struct V_82 * const * V_87 = & V_81 -> V_82 ;
const struct V_82 * V_88 = NULL ;
struct V_84 * V_85 ;
while ( * V_87 != NULL ) {
T_4 V_89 ;
V_88 = * V_87 ;
V_85 = F_41 ( V_88 , struct V_84 , V_82 ) ;
V_89 = V_85 -> V_86 + V_90 ;
if ( V_86 < V_85 -> V_86 )
V_87 = & ( * V_87 ) -> V_91 ;
else if ( V_86 >= V_89 )
V_87 = & ( * V_87 ) -> V_92 ;
else
return V_85 ;
}
return NULL ;
}
static void
F_45 ( struct V_80 * V_81 , struct V_84 * V_93 )
{
struct V_82 * * V_87 = & V_81 -> V_82 ;
struct V_82 * V_88 = NULL ;
struct V_84 * V_85 ;
T_4 V_86 = V_93 -> V_86 ;
while ( * V_87 != NULL ) {
T_4 V_89 ;
V_88 = * V_87 ;
V_85 = F_41 ( V_88 , struct V_84 , V_82 ) ;
V_89 = V_85 -> V_86 + V_90 ;
if ( V_86 < V_85 -> V_86 )
V_87 = & ( * V_87 ) -> V_91 ;
else if ( V_86 >= V_89 )
V_87 = & ( * V_87 ) -> V_92 ;
}
F_46 ( & V_93 -> V_82 , V_88 , V_87 ) ;
F_47 ( & V_93 -> V_82 , V_81 ) ;
}
static T_5
F_48 ( struct V_84 * V_85 , T_4 V_86 ,
T_6 * V_47 , T_4 V_24 )
{
T_4 V_94 = V_86 - V_85 -> V_86 ;
T_4 V_95 = F_49 ( V_85 -> V_24 - V_94 , V_24 ) ;
memcpy ( V_47 , V_85 -> V_47 + V_94 , V_95 ) ;
return V_95 ;
}
static T_5
F_50 ( struct V_1 * V_1 , T_4 V_86 , T_6 * V_47 , T_5 V_24 )
{
struct V_84 * V_85 ;
T_5 V_27 ;
do {
T_4 V_94 ;
V_27 = - V_60 ;
V_85 = F_51 ( sizeof( * V_85 ) + V_90 ) ;
if ( ! V_85 )
break;
V_94 = V_86 & V_96 ;
V_27 = - V_62 ;
if ( - 1 == F_52 ( V_1 -> V_47 . V_52 , V_94 , V_97 ) )
break;
V_27 = F_53 ( V_1 -> V_47 . V_52 , V_85 -> V_47 , V_90 ) ;
if ( V_27 <= 0 )
break;
V_85 -> V_86 = V_94 ;
V_85 -> V_24 = V_27 ;
F_45 ( & V_1 -> V_47 . V_85 , V_85 ) ;
V_27 = F_48 ( V_85 , V_86 , V_47 , V_24 ) ;
} while ( 0 );
if ( V_27 <= 0 )
free ( V_85 ) ;
return V_27 ;
}
static T_5 F_54 ( struct V_1 * V_1 , T_4 V_86 ,
T_6 * V_47 , T_5 V_24 )
{
struct V_84 * V_85 ;
V_85 = F_44 ( & V_1 -> V_47 . V_85 , V_86 ) ;
if ( V_85 )
return F_48 ( V_85 , V_86 , V_47 , V_24 ) ;
else
return F_50 ( V_1 , V_86 , V_47 , V_24 ) ;
}
static T_5 F_55 ( struct V_1 * V_1 , T_4 V_86 , T_6 * V_47 , T_5 V_24 )
{
T_5 V_98 = 0 ;
T_6 * V_87 = V_47 ;
do {
T_5 V_27 ;
V_27 = F_54 ( V_1 , V_86 , V_87 , V_24 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! V_27 )
break;
F_56 ( V_27 > V_24 ) ;
V_98 += V_27 ;
V_87 += V_27 ;
V_86 += V_27 ;
V_24 -= V_27 ;
} while ( V_24 );
return V_98 ;
}
static int F_57 ( struct V_1 * V_1 )
{
struct V_99 V_100 ;
char V_53 [ V_54 ] ;
if ( ! V_1 -> V_47 . V_63 ) {
if ( F_58 ( V_1 -> V_47 . V_52 , & V_100 ) ) {
F_34 ( L_12 ,
F_23 ( V_56 , V_53 , sizeof( V_53 ) ) ) ;
return - 1 ;
}
V_1 -> V_47 . V_63 = V_100 . V_101 ;
}
return 0 ;
}
T_7 F_59 ( struct V_1 * V_1 , struct V_58 * V_58 )
{
int V_52 ;
V_52 = F_37 ( V_1 , V_58 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( F_57 ( V_1 ) )
return - 1 ;
return V_1 -> V_47 . V_63 ;
}
static T_5 F_60 ( struct V_1 * V_1 , T_4 V_86 ,
T_6 * V_47 , T_5 V_24 )
{
if ( F_57 ( V_1 ) )
return - 1 ;
if ( V_86 > V_1 -> V_47 . V_63 )
return - 1 ;
if ( V_86 + V_24 < V_86 )
return - 1 ;
return F_55 ( V_1 , V_86 , V_47 , V_24 ) ;
}
T_5 F_61 ( struct V_1 * V_1 , struct V_58 * V_58 ,
T_4 V_86 , T_6 * V_47 , T_5 V_24 )
{
if ( F_37 ( V_1 , V_58 ) < 0 )
return - 1 ;
return F_60 ( V_1 , V_86 , V_47 , V_24 ) ;
}
T_5 F_62 ( struct V_1 * V_1 , struct V_102 * V_102 ,
struct V_58 * V_58 , T_4 V_103 ,
T_6 * V_47 , T_5 V_24 )
{
T_4 V_86 = V_102 -> V_104 ( V_102 , V_103 ) ;
return F_61 ( V_1 , V_58 , V_86 , V_47 , V_24 ) ;
}
struct V_102 * F_63 ( const char * V_51 )
{
struct V_102 * V_102 = NULL ;
struct V_1 * V_1 = F_64 ( V_51 ) ;
if ( V_1 )
V_102 = F_65 ( 0 , V_1 , V_105 ) ;
return V_102 ;
}
struct V_1 * F_66 ( struct V_58 * V_58 , const char * V_51 ,
const char * V_106 , int V_107 )
{
struct V_1 * V_1 = F_67 ( & V_58 -> V_108 , V_51 ) ;
if ( V_1 != NULL ) {
F_68 ( V_1 , V_106 , false ) ;
V_1 -> V_109 = V_107 ;
}
return V_1 ;
}
static struct V_1 * F_69 ( struct V_80 * V_81 ,
struct V_1 * V_1 , const char * V_51 )
{
struct V_82 * * V_87 = & V_81 -> V_82 ;
struct V_82 * V_88 = NULL ;
if ( ! V_51 )
V_51 = V_1 -> V_30 ;
while ( * V_87 ) {
struct V_1 * V_110 = F_41 ( * V_87 , struct V_1 , V_82 ) ;
int V_111 = strcmp ( V_51 , V_110 -> V_30 ) ;
V_88 = * V_87 ;
if ( V_111 == 0 ) {
if ( ! V_1 || ( V_1 == V_110 ) )
return V_110 ;
V_111 = strcmp ( V_1 -> V_106 , V_110 -> V_106 ) ;
if ( V_111 == 0 ) {
F_34 ( L_13 , V_51 ) ;
return NULL ;
}
}
if ( V_111 < 0 )
V_87 = & V_88 -> V_91 ;
else
V_87 = & V_88 -> V_92 ;
}
if ( V_1 ) {
F_46 ( & V_1 -> V_82 , V_88 , V_87 ) ;
F_47 ( & V_1 -> V_82 , V_81 ) ;
}
return NULL ;
}
static inline struct V_1 *
F_70 ( const struct V_80 * V_81 , const char * V_51 )
{
return F_69 ( (struct V_80 * ) V_81 , NULL , V_51 ) ;
}
void F_71 ( struct V_1 * V_1 , const char * V_51 , bool V_112 )
{
if ( V_51 == NULL )
return;
if ( V_1 -> V_113 )
free ( ( char * ) V_1 -> V_30 ) ;
V_1 -> V_30 = V_51 ;
V_1 -> V_31 = strlen ( V_51 ) ;
V_1 -> V_113 = V_112 ;
}
void F_68 ( struct V_1 * V_1 , const char * V_51 , bool V_112 )
{
if ( V_51 == NULL )
return;
if ( V_1 -> V_114 )
free ( ( char * ) V_1 -> V_106 ) ;
V_1 -> V_106 = V_51 ;
V_1 -> V_115 = strlen ( V_51 ) ;
V_1 -> V_114 = V_112 ;
}
static void F_72 ( struct V_1 * V_1 )
{
char * V_116 , * V_117 = F_73 ( V_1 -> V_30 ) ;
if ( ! V_117 )
return;
V_116 = F_73 ( F_74 ( V_117 ) ) ;
free ( V_117 ) ;
if ( ! V_116 )
return;
F_68 ( V_1 , V_116 , true ) ;
}
int F_75 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_14 ) ;
if ( V_118 )
return V_1 -> V_31 ;
return V_1 -> V_115 ;
}
bool F_76 ( const struct V_1 * V_1 , enum V_119 type )
{
return V_1 -> V_120 & ( 1 << type ) ;
}
bool F_77 ( const struct V_1 * V_1 , enum V_119 type )
{
return V_1 -> V_121 & ( 1 << type ) ;
}
void F_78 ( struct V_1 * V_1 , enum V_119 type )
{
V_1 -> V_121 |= ( 1 << type ) ;
}
struct V_1 * F_64 ( const char * V_51 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_51 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_41 ;
strcpy ( V_1 -> V_51 , V_51 ) ;
F_71 ( V_1 , V_1 -> V_51 , false ) ;
F_68 ( V_1 , V_1 -> V_51 , false ) ;
for ( V_41 = 0 ; V_41 < V_122 ; ++ V_41 )
V_1 -> V_123 [ V_41 ] = V_1 -> V_124 [ V_41 ] = V_125 ;
V_1 -> V_47 . V_85 = V_125 ;
V_1 -> V_47 . V_52 = - 1 ;
V_1 -> V_47 . V_72 = V_126 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_61 = V_20 ;
V_1 -> V_127 = ( sizeof( void * ) == 8 ) ;
V_1 -> V_120 = 0 ;
V_1 -> V_128 = 0 ;
V_1 -> V_121 = 0 ;
V_1 -> V_36 = 0 ;
V_1 -> V_129 = 1 ;
V_1 -> V_130 = 1 ;
V_1 -> V_109 = V_131 ;
V_1 -> V_132 = V_133 ;
F_79 ( & V_1 -> V_82 ) ;
F_80 ( & V_1 -> V_134 ) ;
F_80 ( & V_1 -> V_47 . V_48 ) ;
}
return V_1 ;
}
void F_81 ( struct V_1 * V_1 )
{
int V_41 ;
if ( ! F_82 ( & V_1 -> V_82 ) )
F_34 ( L_15 ,
V_1 -> V_30 ) ;
for ( V_41 = 0 ; V_41 < V_122 ; ++ V_41 )
F_83 ( & V_1 -> V_123 [ V_41 ] ) ;
if ( V_1 -> V_114 ) {
F_84 ( ( char * * ) & V_1 -> V_106 ) ;
V_1 -> V_114 = false ;
}
if ( V_1 -> V_113 ) {
F_84 ( ( char * * ) & V_1 -> V_30 ) ;
V_1 -> V_113 = false ;
}
F_36 ( V_1 ) ;
F_39 ( & V_1 -> V_47 . V_85 ) ;
F_85 ( V_1 ) ;
F_84 ( & V_1 -> V_135 ) ;
free ( V_1 ) ;
}
void F_86 ( struct V_1 * V_1 , void * V_37 )
{
memcpy ( V_1 -> V_37 , V_37 , sizeof( V_1 -> V_37 ) ) ;
V_1 -> V_36 = 1 ;
}
bool F_87 ( const struct V_1 * V_1 , T_6 * V_37 )
{
return memcmp ( V_1 -> V_37 , V_37 , sizeof( V_1 -> V_37 ) ) == 0 ;
}
void F_88 ( struct V_1 * V_1 , struct V_58 * V_58 )
{
char V_136 [ V_59 ] ;
if ( F_89 ( V_58 ) )
return;
sprintf ( V_136 , L_16 , V_58 -> V_22 ) ;
if ( F_90 ( V_136 , V_1 -> V_37 ,
sizeof( V_1 -> V_37 ) ) == 0 )
V_1 -> V_36 = true ;
}
int F_91 ( struct V_1 * V_1 ,
const char * V_22 )
{
char V_23 [ V_59 ] ;
const char * V_51 = V_1 -> V_106 + 1 ;
snprintf ( V_23 , sizeof( V_23 ) ,
L_17 ,
V_22 , ( int ) strlen ( V_51 ) - 1 , V_51 ) ;
if ( F_90 ( V_23 , V_1 -> V_37 ,
sizeof( V_1 -> V_37 ) ) == 0 )
V_1 -> V_36 = true ;
return 0 ;
}
bool F_92 ( struct V_137 * V_138 , bool V_139 )
{
bool V_140 = false ;
struct V_1 * V_141 ;
F_93 (pos, head, node) {
if ( V_139 && ! V_141 -> V_142 )
continue;
if ( V_141 -> V_36 ) {
V_140 = true ;
continue;
}
if ( F_94 ( V_141 -> V_30 , V_141 -> V_37 ,
sizeof( V_141 -> V_37 ) ) > 0 ) {
V_140 = true ;
V_141 -> V_36 = true ;
}
}
return V_140 ;
}
void F_95 ( struct V_143 * V_143 , struct V_1 * V_1 )
{
F_16 ( & V_1 -> V_134 , & V_143 -> V_138 ) ;
F_69 ( & V_143 -> V_81 , V_1 , NULL ) ;
}
struct V_1 * F_96 ( const struct V_143 * V_143 , const char * V_51 ,
bool V_144 )
{
struct V_1 * V_141 ;
if ( V_144 ) {
F_93 (pos, &dsos->head, node)
if ( strcmp ( V_141 -> V_106 , V_51 ) == 0 )
return V_141 ;
return NULL ;
}
return F_70 ( & V_143 -> V_81 , V_51 ) ;
}
struct V_1 * F_67 ( struct V_143 * V_143 , const char * V_51 )
{
struct V_1 * V_1 = F_96 ( V_143 , V_51 , false ) ;
if ( ! V_1 ) {
V_1 = F_64 ( V_51 ) ;
if ( V_1 != NULL ) {
F_95 ( V_143 , V_1 ) ;
F_72 ( V_1 ) ;
}
}
return V_1 ;
}
T_1 F_97 ( struct V_137 * V_138 , T_8 * V_145 ,
bool (F_98)( struct V_1 * V_1 , int V_146 ) , int V_146 )
{
struct V_1 * V_141 ;
T_1 V_27 = 0 ;
F_93 (pos, head, node) {
if ( F_98 && F_98 ( V_141 , V_146 ) )
continue;
V_27 += F_99 ( V_141 , V_145 ) ;
V_27 += fprintf ( V_145 , L_18 , V_141 -> V_30 ) ;
}
return V_27 ;
}
T_1 F_100 ( struct V_137 * V_138 , T_8 * V_145 )
{
struct V_1 * V_141 ;
T_1 V_27 = 0 ;
F_93 (pos, head, node) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_122 ; ++ V_41 )
V_27 += F_101 ( V_141 , V_41 , V_145 ) ;
}
return V_27 ;
}
T_1 F_99 ( struct V_1 * V_1 , T_8 * V_145 )
{
char V_147 [ V_26 * 2 + 1 ] ;
F_7 ( V_1 -> V_37 , sizeof( V_1 -> V_37 ) , V_147 ) ;
return fprintf ( V_145 , L_3 , V_147 ) ;
}
T_1 F_101 ( struct V_1 * V_1 , enum V_119 type , T_8 * V_145 )
{
struct V_82 * V_148 ;
T_1 V_27 = fprintf ( V_145 , L_19 , V_1 -> V_106 ) ;
if ( V_1 -> V_106 != V_1 -> V_30 )
V_27 += fprintf ( V_145 , L_20 , V_1 -> V_30 ) ;
V_27 += fprintf ( V_145 , L_21 , V_149 [ type ] ,
F_76 ( V_1 , type ) ? L_4 : L_22 ) ;
V_27 += F_99 ( V_1 , V_145 ) ;
V_27 += fprintf ( V_145 , L_23 ) ;
for ( V_148 = F_40 ( & V_1 -> V_123 [ type ] ) ; V_148 ; V_148 = F_42 ( V_148 ) ) {
struct V_150 * V_141 = F_41 ( V_148 , struct V_150 , V_82 ) ;
V_27 += F_102 ( V_141 , V_145 ) ;
}
return V_27 ;
}
enum V_107 F_103 ( struct V_1 * V_1 , struct V_58 * V_58 )
{
int V_52 ;
V_52 = F_37 ( V_1 , V_58 ) ;
if ( V_52 < 0 )
return V_151 ;
return F_104 ( V_52 ) ;
}
