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
V_27 = F_52 ( V_1 -> V_47 . V_52 , V_85 -> V_47 , V_90 , V_94 ) ;
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
static T_5 F_53 ( struct V_1 * V_1 , T_4 V_86 ,
T_6 * V_47 , T_5 V_24 )
{
struct V_84 * V_85 ;
V_85 = F_44 ( & V_1 -> V_47 . V_85 , V_86 ) ;
if ( V_85 )
return F_48 ( V_85 , V_86 , V_47 , V_24 ) ;
else
return F_50 ( V_1 , V_86 , V_47 , V_24 ) ;
}
static T_5 F_54 ( struct V_1 * V_1 , T_4 V_86 , T_6 * V_47 , T_5 V_24 )
{
T_5 V_97 = 0 ;
T_6 * V_87 = V_47 ;
do {
T_5 V_27 ;
V_27 = F_53 ( V_1 , V_86 , V_87 , V_24 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! V_27 )
break;
F_55 ( V_27 > V_24 ) ;
V_97 += V_27 ;
V_87 += V_27 ;
V_86 += V_27 ;
V_24 -= V_27 ;
} while ( V_24 );
return V_97 ;
}
static int F_56 ( struct V_1 * V_1 )
{
struct V_98 V_99 ;
char V_53 [ V_54 ] ;
if ( ! V_1 -> V_47 . V_63 ) {
if ( F_57 ( V_1 -> V_47 . V_52 , & V_99 ) ) {
F_34 ( L_12 ,
F_23 ( V_56 , V_53 , sizeof( V_53 ) ) ) ;
return - 1 ;
}
V_1 -> V_47 . V_63 = V_99 . V_100 ;
}
return 0 ;
}
T_7 F_58 ( struct V_1 * V_1 , struct V_58 * V_58 )
{
int V_52 ;
V_52 = F_37 ( V_1 , V_58 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( F_56 ( V_1 ) )
return - 1 ;
return V_1 -> V_47 . V_63 ;
}
static T_5 F_59 ( struct V_1 * V_1 , T_4 V_86 ,
T_6 * V_47 , T_5 V_24 )
{
if ( F_56 ( V_1 ) )
return - 1 ;
if ( V_86 > V_1 -> V_47 . V_63 )
return - 1 ;
if ( V_86 + V_24 < V_86 )
return - 1 ;
return F_54 ( V_1 , V_86 , V_47 , V_24 ) ;
}
T_5 F_60 ( struct V_1 * V_1 , struct V_58 * V_58 ,
T_4 V_86 , T_6 * V_47 , T_5 V_24 )
{
if ( F_37 ( V_1 , V_58 ) < 0 )
return - 1 ;
return F_59 ( V_1 , V_86 , V_47 , V_24 ) ;
}
T_5 F_61 ( struct V_1 * V_1 , struct V_101 * V_101 ,
struct V_58 * V_58 , T_4 V_102 ,
T_6 * V_47 , T_5 V_24 )
{
T_4 V_86 = V_101 -> V_103 ( V_101 , V_102 ) ;
return F_60 ( V_1 , V_58 , V_86 , V_47 , V_24 ) ;
}
struct V_101 * F_62 ( const char * V_51 )
{
struct V_101 * V_101 = NULL ;
struct V_1 * V_1 = F_63 ( V_51 ) ;
if ( V_1 )
V_101 = F_64 ( 0 , V_1 , V_104 ) ;
return V_101 ;
}
struct V_1 * F_65 ( struct V_58 * V_58 , const char * V_51 ,
const char * V_105 , int V_106 )
{
struct V_1 * V_1 = F_66 ( & V_58 -> V_107 , V_51 ) ;
if ( V_1 != NULL ) {
F_67 ( V_1 , V_105 , false ) ;
V_1 -> V_108 = V_106 ;
}
return V_1 ;
}
static struct V_1 * F_68 ( struct V_80 * V_81 ,
struct V_1 * V_1 , const char * V_51 )
{
struct V_82 * * V_87 = & V_81 -> V_82 ;
struct V_82 * V_88 = NULL ;
if ( ! V_51 )
V_51 = V_1 -> V_30 ;
while ( * V_87 ) {
struct V_1 * V_109 = F_41 ( * V_87 , struct V_1 , V_82 ) ;
int V_110 = strcmp ( V_51 , V_109 -> V_30 ) ;
V_88 = * V_87 ;
if ( V_110 == 0 ) {
if ( ! V_1 || ( V_1 == V_109 ) )
return V_109 ;
V_110 = strcmp ( V_1 -> V_105 , V_109 -> V_105 ) ;
if ( V_110 == 0 ) {
F_34 ( L_13 , V_51 ) ;
return NULL ;
}
}
if ( V_110 < 0 )
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
F_69 ( const struct V_80 * V_81 , const char * V_51 )
{
return F_68 ( (struct V_80 * ) V_81 , NULL , V_51 ) ;
}
void F_70 ( struct V_1 * V_1 , const char * V_51 , bool V_111 )
{
if ( V_51 == NULL )
return;
if ( V_1 -> V_112 )
free ( ( char * ) V_1 -> V_30 ) ;
V_1 -> V_30 = V_51 ;
V_1 -> V_31 = strlen ( V_51 ) ;
V_1 -> V_112 = V_111 ;
}
void F_67 ( struct V_1 * V_1 , const char * V_51 , bool V_111 )
{
if ( V_51 == NULL )
return;
if ( V_1 -> V_113 )
free ( ( char * ) V_1 -> V_105 ) ;
V_1 -> V_105 = V_51 ;
V_1 -> V_114 = strlen ( V_51 ) ;
V_1 -> V_113 = V_111 ;
}
static void F_71 ( struct V_1 * V_1 )
{
char * V_115 , * V_116 = F_72 ( V_1 -> V_30 ) ;
if ( ! V_116 )
return;
V_115 = F_72 ( F_73 ( V_116 ) ) ;
free ( V_116 ) ;
if ( ! V_115 )
return;
F_67 ( V_1 , V_115 , true ) ;
}
int F_74 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_14 ) ;
if ( V_117 )
return V_1 -> V_31 ;
return V_1 -> V_114 ;
}
bool F_75 ( const struct V_1 * V_1 , enum V_118 type )
{
return V_1 -> V_119 & ( 1 << type ) ;
}
bool F_76 ( const struct V_1 * V_1 , enum V_118 type )
{
return V_1 -> V_120 & ( 1 << type ) ;
}
void F_77 ( struct V_1 * V_1 , enum V_118 type )
{
V_1 -> V_120 |= ( 1 << type ) ;
}
struct V_1 * F_63 ( const char * V_51 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_51 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_41 ;
strcpy ( V_1 -> V_51 , V_51 ) ;
F_70 ( V_1 , V_1 -> V_51 , false ) ;
F_67 ( V_1 , V_1 -> V_51 , false ) ;
for ( V_41 = 0 ; V_41 < V_121 ; ++ V_41 )
V_1 -> V_122 [ V_41 ] = V_1 -> V_123 [ V_41 ] = V_124 ;
V_1 -> V_47 . V_85 = V_124 ;
V_1 -> V_47 . V_52 = - 1 ;
V_1 -> V_47 . V_72 = V_125 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_61 = V_20 ;
V_1 -> V_126 = ( sizeof( void * ) == 8 ) ;
V_1 -> V_119 = 0 ;
V_1 -> V_127 = 0 ;
V_1 -> V_120 = 0 ;
V_1 -> V_36 = 0 ;
V_1 -> V_128 = 1 ;
V_1 -> V_129 = 1 ;
V_1 -> V_108 = V_130 ;
V_1 -> V_131 = V_132 ;
F_78 ( & V_1 -> V_82 ) ;
F_79 ( & V_1 -> V_133 ) ;
F_79 ( & V_1 -> V_47 . V_48 ) ;
}
return V_1 ;
}
void F_80 ( struct V_1 * V_1 )
{
int V_41 ;
if ( ! F_81 ( & V_1 -> V_82 ) )
F_34 ( L_15 ,
V_1 -> V_30 ) ;
for ( V_41 = 0 ; V_41 < V_121 ; ++ V_41 )
F_82 ( & V_1 -> V_122 [ V_41 ] ) ;
if ( V_1 -> V_113 ) {
F_83 ( ( char * * ) & V_1 -> V_105 ) ;
V_1 -> V_113 = false ;
}
if ( V_1 -> V_112 ) {
F_83 ( ( char * * ) & V_1 -> V_30 ) ;
V_1 -> V_112 = false ;
}
F_36 ( V_1 ) ;
F_39 ( & V_1 -> V_47 . V_85 ) ;
F_84 ( V_1 ) ;
F_83 ( & V_1 -> V_134 ) ;
free ( V_1 ) ;
}
void F_85 ( struct V_1 * V_1 , void * V_37 )
{
memcpy ( V_1 -> V_37 , V_37 , sizeof( V_1 -> V_37 ) ) ;
V_1 -> V_36 = 1 ;
}
bool F_86 ( const struct V_1 * V_1 , T_6 * V_37 )
{
return memcmp ( V_1 -> V_37 , V_37 , sizeof( V_1 -> V_37 ) ) == 0 ;
}
void F_87 ( struct V_1 * V_1 , struct V_58 * V_58 )
{
char V_135 [ V_59 ] ;
if ( F_88 ( V_58 ) )
return;
sprintf ( V_135 , L_16 , V_58 -> V_22 ) ;
if ( F_89 ( V_135 , V_1 -> V_37 ,
sizeof( V_1 -> V_37 ) ) == 0 )
V_1 -> V_36 = true ;
}
int F_90 ( struct V_1 * V_1 ,
const char * V_22 )
{
char V_23 [ V_59 ] ;
const char * V_51 = V_1 -> V_105 + 1 ;
snprintf ( V_23 , sizeof( V_23 ) ,
L_17 ,
V_22 , ( int ) strlen ( V_51 ) - 1 , V_51 ) ;
if ( F_89 ( V_23 , V_1 -> V_37 ,
sizeof( V_1 -> V_37 ) ) == 0 )
V_1 -> V_36 = true ;
return 0 ;
}
bool F_91 ( struct V_136 * V_137 , bool V_138 )
{
bool V_139 = false ;
struct V_1 * V_140 ;
F_92 (pos, head, node) {
if ( V_138 && ! V_140 -> V_141 )
continue;
if ( V_140 -> V_36 ) {
V_139 = true ;
continue;
}
if ( F_93 ( V_140 -> V_30 , V_140 -> V_37 ,
sizeof( V_140 -> V_37 ) ) > 0 ) {
V_139 = true ;
V_140 -> V_36 = true ;
}
}
return V_139 ;
}
void F_94 ( struct V_142 * V_142 , struct V_1 * V_1 )
{
F_16 ( & V_1 -> V_133 , & V_142 -> V_137 ) ;
F_68 ( & V_142 -> V_81 , V_1 , NULL ) ;
}
struct V_1 * F_95 ( const struct V_142 * V_142 , const char * V_51 ,
bool V_143 )
{
struct V_1 * V_140 ;
if ( V_143 ) {
F_92 (pos, &dsos->head, node)
if ( strcmp ( V_140 -> V_105 , V_51 ) == 0 )
return V_140 ;
return NULL ;
}
return F_69 ( & V_142 -> V_81 , V_51 ) ;
}
struct V_1 * F_66 ( struct V_142 * V_142 , const char * V_51 )
{
struct V_1 * V_1 = F_95 ( V_142 , V_51 , false ) ;
if ( ! V_1 ) {
V_1 = F_63 ( V_51 ) ;
if ( V_1 != NULL ) {
F_94 ( V_142 , V_1 ) ;
F_71 ( V_1 ) ;
}
}
return V_1 ;
}
T_1 F_96 ( struct V_136 * V_137 , T_8 * V_144 ,
bool (F_97)( struct V_1 * V_1 , int V_145 ) , int V_145 )
{
struct V_1 * V_140 ;
T_1 V_27 = 0 ;
F_92 (pos, head, node) {
if ( F_97 && F_97 ( V_140 , V_145 ) )
continue;
V_27 += F_98 ( V_140 , V_144 ) ;
V_27 += fprintf ( V_144 , L_18 , V_140 -> V_30 ) ;
}
return V_27 ;
}
T_1 F_99 ( struct V_136 * V_137 , T_8 * V_144 )
{
struct V_1 * V_140 ;
T_1 V_27 = 0 ;
F_92 (pos, head, node) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_121 ; ++ V_41 )
V_27 += F_100 ( V_140 , V_41 , V_144 ) ;
}
return V_27 ;
}
T_1 F_98 ( struct V_1 * V_1 , T_8 * V_144 )
{
char V_146 [ V_26 * 2 + 1 ] ;
F_7 ( V_1 -> V_37 , sizeof( V_1 -> V_37 ) , V_146 ) ;
return fprintf ( V_144 , L_3 , V_146 ) ;
}
T_1 F_100 ( struct V_1 * V_1 , enum V_118 type , T_8 * V_144 )
{
struct V_82 * V_147 ;
T_1 V_27 = fprintf ( V_144 , L_19 , V_1 -> V_105 ) ;
if ( V_1 -> V_105 != V_1 -> V_30 )
V_27 += fprintf ( V_144 , L_20 , V_1 -> V_30 ) ;
V_27 += fprintf ( V_144 , L_21 , V_148 [ type ] ,
F_75 ( V_1 , type ) ? L_4 : L_22 ) ;
V_27 += F_98 ( V_1 , V_144 ) ;
V_27 += fprintf ( V_144 , L_23 ) ;
for ( V_147 = F_40 ( & V_1 -> V_122 [ type ] ) ; V_147 ; V_147 = F_42 ( V_147 ) ) {
struct V_149 * V_140 = F_41 ( V_147 , struct V_149 , V_82 ) ;
V_27 += F_101 ( V_140 , V_144 ) ;
}
return V_27 ;
}
enum V_106 F_102 ( struct V_1 * V_1 , struct V_58 * V_58 )
{
int V_52 ;
V_52 = F_37 ( V_1 , V_58 ) ;
if ( V_52 < 0 )
return V_150 ;
return F_103 ( V_52 ) ;
}
