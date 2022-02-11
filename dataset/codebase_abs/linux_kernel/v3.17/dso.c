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
[ V_14 ] = 'g' ,
[ V_15 ] = 'G' ,
[ V_16 ] = 'V' ,
} ;
if ( V_1 == NULL || V_1 -> V_17 == V_18 )
return '!' ;
return V_2 [ V_1 -> V_17 ] ;
}
int F_2 ( const struct V_1 * V_1 ,
enum V_19 type ,
char * V_20 , char * V_21 , T_1 V_22 )
{
char V_23 [ V_24 * 2 + 1 ] ;
int V_25 = 0 ;
switch ( type ) {
case V_6 : {
char * V_26 ;
strncpy ( V_21 , V_1 -> V_27 , V_22 ) ;
V_26 = V_21 + V_1 -> V_28 ;
while ( V_26 != V_21 && * V_26 != '/' )
V_26 -- ;
if ( * V_26 == '/' )
V_26 ++ ;
V_25 = F_3 ( V_1 -> V_27 , V_26 ,
V_22 - ( V_26 - V_21 ) ) ;
}
break;
case V_7 :
if ( V_29 . V_30 [ 0 ] ||
( F_4 ( V_1 , V_21 , V_22 ) == NULL ) )
V_25 = - 1 ;
break;
case V_8 :
snprintf ( V_21 , V_22 , L_1 ,
V_29 . V_30 , V_1 -> V_27 ) ;
break;
case V_9 :
snprintf ( V_21 , V_22 , L_2 ,
V_29 . V_30 , V_1 -> V_27 ) ;
break;
case V_10 :
{
const char * V_31 ;
T_1 V_32 ;
T_1 V_33 ;
V_31 = V_1 -> V_27 + V_1 -> V_28 ;
while ( V_31 != V_1 -> V_27 && * V_31 != '/' )
V_31 -- ;
V_32 = F_5 ( V_21 , V_22 , L_3 , V_29 . V_30 ) ;
V_33 = V_31 - V_1 -> V_27 + 2 ;
if ( V_33 > ( V_22 - V_32 ) ) {
V_25 = - 1 ;
break;
}
V_32 += F_5 ( V_21 + V_32 , V_33 , L_3 , V_1 -> V_27 ) ;
V_32 += F_5 ( V_21 + V_32 , V_22 - V_32 , L_4 ,
V_31 ) ;
break;
}
case V_11 :
if ( ! V_1 -> V_34 ) {
V_25 = - 1 ;
break;
}
F_6 ( V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ,
V_23 ) ;
snprintf ( V_21 , V_22 ,
L_5 ,
V_29 . V_30 , V_23 , V_23 + 2 ) ;
break;
case V_4 :
case V_16 :
case V_12 :
snprintf ( V_21 , V_22 , L_6 ,
V_29 . V_30 , V_1 -> V_27 ) ;
break;
case V_15 :
snprintf ( V_21 , V_22 , L_7 , V_29 . V_30 ,
V_20 , V_1 -> V_27 ) ;
break;
case V_13 :
snprintf ( V_21 , V_22 , L_6 , V_29 . V_30 ,
V_1 -> V_27 ) ;
break;
case V_36 :
case V_37 :
snprintf ( V_21 , V_22 , L_3 , V_1 -> V_27 ) ;
break;
default:
case V_3 :
case V_14 :
case V_5 :
case V_18 :
V_25 = - 1 ;
break;
}
return V_25 ;
}
static void F_7 ( struct V_1 * V_1 )
{
F_8 ( & V_1 -> V_38 . V_39 , & V_40 ) ;
V_41 ++ ;
}
static void F_9 ( struct V_1 * V_1 )
{
F_10 ( & V_1 -> V_38 . V_39 ) ;
F_11 ( V_41 <= 0 ,
L_8 ) ;
V_41 -- ;
}
static int F_12 ( char * V_42 )
{
int V_43 ;
do {
V_43 = F_13 ( V_42 , V_44 ) ;
if ( V_43 >= 0 )
return V_43 ;
F_14 ( L_9 , strerror ( V_45 ) ) ;
if ( ! V_41 || V_45 != V_46 )
break;
F_15 () ;
} while ( 1 );
return - 1 ;
}
static int F_16 ( struct V_1 * V_1 , struct V_47 * V_47 )
{
int V_43 ;
char * V_20 = ( char * ) L_10 ;
char * V_42 = malloc ( V_48 ) ;
if ( ! V_42 )
return - V_49 ;
if ( V_47 )
V_20 = V_47 -> V_20 ;
if ( F_2 ( V_1 , V_1 -> V_50 ,
V_20 , V_42 , V_48 ) ) {
free ( V_42 ) ;
return - V_51 ;
}
V_43 = F_12 ( V_42 ) ;
free ( V_42 ) ;
return V_43 ;
}
static int F_17 ( struct V_1 * V_1 , struct V_47 * V_47 )
{
int V_43 = F_16 ( V_1 , V_47 ) ;
if ( V_43 >= 0 ) {
F_7 ( V_1 ) ;
F_18 () ;
}
return V_43 ;
}
static void F_19 ( struct V_1 * V_1 )
{
if ( V_1 -> V_38 . V_43 >= 0 ) {
F_20 ( V_1 -> V_38 . V_43 ) ;
V_1 -> V_38 . V_43 = - 1 ;
V_1 -> V_38 . V_52 = 0 ;
F_9 ( V_1 ) ;
}
}
static void F_21 ( struct V_1 * V_1 )
{
F_19 ( V_1 ) ;
}
static void F_15 ( void )
{
struct V_1 * V_1 ;
V_1 = F_22 ( & V_40 , struct V_1 , V_38 . V_39 ) ;
F_21 ( V_1 ) ;
}
static T_2 F_23 ( void )
{
struct V_53 V_54 ;
T_2 V_55 = 0 ;
if ( F_24 ( V_56 , & V_54 ) == 0 ) {
if ( V_54 . V_57 == V_58 )
V_55 = V_54 . V_57 ;
else
V_55 = V_54 . V_57 / 2 ;
} else {
F_25 ( L_11 ) ;
V_55 = 1 ;
}
return V_55 ;
}
static bool F_26 ( void )
{
static T_2 V_55 ;
if ( ! V_55 )
V_55 = F_23 () ;
if ( V_55 == V_58 )
return true ;
return V_55 > ( T_2 ) V_41 ;
}
static void F_18 ( void )
{
bool V_59 = F_26 () ;
if ( ! V_59 )
F_15 () ;
}
void F_27 ( struct V_1 * V_1 )
{
F_21 ( V_1 ) ;
}
int F_28 ( struct V_1 * V_1 , struct V_47 * V_47 )
{
enum V_19 V_60 [] = {
V_7 ,
V_12 ,
V_18 ,
} ;
int V_61 = 0 ;
if ( V_1 -> V_38 . V_62 == V_63 )
return - 1 ;
if ( V_1 -> V_38 . V_43 >= 0 )
goto V_64;
if ( V_1 -> V_50 != V_18 ) {
V_1 -> V_38 . V_43 = F_17 ( V_1 , V_47 ) ;
goto V_64;
}
do {
V_1 -> V_50 = V_60 [ V_61 ++ ] ;
V_1 -> V_38 . V_43 = F_17 ( V_1 , V_47 ) ;
if ( V_1 -> V_38 . V_43 >= 0 )
goto V_64;
} while ( V_1 -> V_50 != V_18 );
V_64:
if ( V_1 -> V_38 . V_43 >= 0 )
V_1 -> V_38 . V_62 = V_65 ;
else
V_1 -> V_38 . V_62 = V_63 ;
return V_1 -> V_38 . V_43 ;
}
bool F_29 ( struct V_1 * V_1 , enum V_66 V_67 )
{
T_3 V_68 = 1 << V_67 ;
if ( V_1 -> V_38 . V_69 & V_68 )
return true ;
V_1 -> V_38 . V_69 |= V_68 ;
return false ;
}
static void
F_30 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = F_31 ( V_71 ) ;
while ( V_73 ) {
struct V_74 * V_75 ;
V_75 = F_32 ( V_73 , struct V_74 , V_72 ) ;
V_73 = F_33 ( & V_75 -> V_72 ) ;
F_34 ( & V_75 -> V_72 , V_71 ) ;
free ( V_75 ) ;
}
}
static struct V_74 * F_35 ( const struct V_70 * V_71 , T_4 V_76 )
{
struct V_72 * const * V_77 = & V_71 -> V_72 ;
const struct V_72 * V_78 = NULL ;
struct V_74 * V_75 ;
while ( * V_77 != NULL ) {
T_4 V_79 ;
V_78 = * V_77 ;
V_75 = F_32 ( V_78 , struct V_74 , V_72 ) ;
V_79 = V_75 -> V_76 + V_80 ;
if ( V_76 < V_75 -> V_76 )
V_77 = & ( * V_77 ) -> V_81 ;
else if ( V_76 >= V_79 )
V_77 = & ( * V_77 ) -> V_82 ;
else
return V_75 ;
}
return NULL ;
}
static void
F_36 ( struct V_70 * V_71 , struct V_74 * V_83 )
{
struct V_72 * * V_77 = & V_71 -> V_72 ;
struct V_72 * V_78 = NULL ;
struct V_74 * V_75 ;
T_4 V_76 = V_83 -> V_76 ;
while ( * V_77 != NULL ) {
T_4 V_79 ;
V_78 = * V_77 ;
V_75 = F_32 ( V_78 , struct V_74 , V_72 ) ;
V_79 = V_75 -> V_76 + V_80 ;
if ( V_76 < V_75 -> V_76 )
V_77 = & ( * V_77 ) -> V_81 ;
else if ( V_76 >= V_79 )
V_77 = & ( * V_77 ) -> V_82 ;
}
F_37 ( & V_83 -> V_72 , V_78 , V_77 ) ;
F_38 ( & V_83 -> V_72 , V_71 ) ;
}
static T_5
F_39 ( struct V_74 * V_75 , T_4 V_76 ,
T_6 * V_38 , T_4 V_22 )
{
T_4 V_84 = V_76 - V_75 -> V_76 ;
T_4 V_85 = F_40 ( V_75 -> V_22 - V_84 , V_22 ) ;
memcpy ( V_38 , V_75 -> V_38 + V_84 , V_85 ) ;
return V_85 ;
}
static T_5
F_41 ( struct V_1 * V_1 , T_4 V_76 , T_6 * V_38 , T_5 V_22 )
{
struct V_74 * V_75 ;
T_5 V_25 ;
do {
T_4 V_84 ;
V_25 = - V_49 ;
V_75 = F_42 ( sizeof( * V_75 ) + V_80 ) ;
if ( ! V_75 )
break;
V_84 = V_76 & V_86 ;
V_25 = - V_51 ;
if ( - 1 == F_43 ( V_1 -> V_38 . V_43 , V_84 , V_87 ) )
break;
V_25 = F_44 ( V_1 -> V_38 . V_43 , V_75 -> V_38 , V_80 ) ;
if ( V_25 <= 0 )
break;
V_75 -> V_76 = V_84 ;
V_75 -> V_22 = V_25 ;
F_36 ( & V_1 -> V_38 . V_75 , V_75 ) ;
V_25 = F_39 ( V_75 , V_76 , V_38 , V_22 ) ;
} while ( 0 );
if ( V_25 <= 0 )
free ( V_75 ) ;
return V_25 ;
}
static T_5 F_45 ( struct V_1 * V_1 , T_4 V_76 ,
T_6 * V_38 , T_5 V_22 )
{
struct V_74 * V_75 ;
V_75 = F_35 ( & V_1 -> V_38 . V_75 , V_76 ) ;
if ( V_75 )
return F_39 ( V_75 , V_76 , V_38 , V_22 ) ;
else
return F_41 ( V_1 , V_76 , V_38 , V_22 ) ;
}
static T_5 F_46 ( struct V_1 * V_1 , T_4 V_76 , T_6 * V_38 , T_5 V_22 )
{
T_5 V_88 = 0 ;
T_6 * V_77 = V_38 ;
do {
T_5 V_25 ;
V_25 = F_45 ( V_1 , V_76 , V_77 , V_22 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 )
break;
F_47 ( V_25 > V_22 ) ;
V_88 += V_25 ;
V_77 += V_25 ;
V_76 += V_25 ;
V_22 -= V_25 ;
} while ( V_22 );
return V_88 ;
}
static int F_48 ( struct V_1 * V_1 )
{
struct V_89 V_90 ;
if ( ! V_1 -> V_38 . V_52 ) {
if ( F_49 ( V_1 -> V_38 . V_43 , & V_90 ) ) {
F_25 ( L_12 , strerror ( V_45 ) ) ;
return - 1 ;
}
V_1 -> V_38 . V_52 = V_90 . V_91 ;
}
return 0 ;
}
T_7 F_50 ( struct V_1 * V_1 , struct V_47 * V_47 )
{
int V_43 ;
V_43 = F_28 ( V_1 , V_47 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( F_48 ( V_1 ) )
return - 1 ;
return V_1 -> V_38 . V_52 ;
}
static T_5 F_51 ( struct V_1 * V_1 , T_4 V_76 ,
T_6 * V_38 , T_5 V_22 )
{
if ( F_48 ( V_1 ) )
return - 1 ;
if ( V_76 > V_1 -> V_38 . V_52 )
return - 1 ;
if ( V_76 + V_22 < V_76 )
return - 1 ;
return F_46 ( V_1 , V_76 , V_38 , V_22 ) ;
}
T_5 F_52 ( struct V_1 * V_1 , struct V_47 * V_47 ,
T_4 V_76 , T_6 * V_38 , T_5 V_22 )
{
if ( F_28 ( V_1 , V_47 ) < 0 )
return - 1 ;
return F_51 ( V_1 , V_76 , V_38 , V_22 ) ;
}
T_5 F_53 ( struct V_1 * V_1 , struct V_92 * V_92 ,
struct V_47 * V_47 , T_4 V_93 ,
T_6 * V_38 , T_5 V_22 )
{
T_4 V_76 = V_92 -> V_94 ( V_92 , V_93 ) ;
return F_52 ( V_1 , V_47 , V_76 , V_38 , V_22 ) ;
}
struct V_92 * F_54 ( const char * V_42 )
{
struct V_92 * V_92 = NULL ;
struct V_1 * V_1 = F_55 ( V_42 ) ;
if ( V_1 )
V_92 = F_56 ( 0 , V_1 , V_95 ) ;
return V_92 ;
}
struct V_1 * F_57 ( struct V_47 * V_47 , const char * V_42 ,
const char * V_96 , int V_97 )
{
struct V_1 * V_1 = F_58 ( & V_47 -> V_98 , V_42 ) ;
if ( V_1 != NULL ) {
F_59 ( V_1 , V_96 , false ) ;
V_1 -> V_99 = V_97 ;
}
return V_1 ;
}
void F_60 ( struct V_1 * V_1 , const char * V_42 , bool V_100 )
{
if ( V_42 == NULL )
return;
if ( V_1 -> V_101 )
free ( ( char * ) V_1 -> V_27 ) ;
V_1 -> V_27 = V_42 ;
V_1 -> V_28 = strlen ( V_42 ) ;
V_1 -> V_101 = V_100 ;
}
void F_59 ( struct V_1 * V_1 , const char * V_42 , bool V_100 )
{
if ( V_42 == NULL )
return;
if ( V_1 -> V_102 )
free ( ( char * ) V_1 -> V_96 ) ;
V_1 -> V_96 = V_42 ;
V_1 -> V_103 = strlen ( V_42 ) ;
V_1 -> V_102 = V_100 ;
}
static void F_61 ( struct V_1 * V_1 )
{
char * V_104 , * V_105 = F_62 ( V_1 -> V_27 ) ;
if ( ! V_105 )
return;
V_104 = F_62 ( F_63 ( V_105 ) ) ;
free ( V_105 ) ;
if ( ! V_104 )
return;
F_59 ( V_1 , V_104 , true ) ;
}
int F_64 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_13 ) ;
if ( V_106 )
return V_1 -> V_28 ;
return V_1 -> V_103 ;
}
bool F_65 ( const struct V_1 * V_1 , enum V_107 type )
{
return V_1 -> V_108 & ( 1 << type ) ;
}
bool F_66 ( const struct V_1 * V_1 , enum V_107 type )
{
return V_1 -> V_109 & ( 1 << type ) ;
}
void F_67 ( struct V_1 * V_1 , enum V_107 type )
{
V_1 -> V_109 |= ( 1 << type ) ;
}
struct V_1 * F_55 ( const char * V_42 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_42 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_61 ;
strcpy ( V_1 -> V_42 , V_42 ) ;
F_60 ( V_1 , V_1 -> V_42 , false ) ;
F_59 ( V_1 , V_1 -> V_42 , false ) ;
for ( V_61 = 0 ; V_61 < V_110 ; ++ V_61 )
V_1 -> V_111 [ V_61 ] = V_1 -> V_112 [ V_61 ] = V_113 ;
V_1 -> V_38 . V_75 = V_113 ;
V_1 -> V_38 . V_43 = - 1 ;
V_1 -> V_38 . V_62 = V_114 ;
V_1 -> V_17 = V_18 ;
V_1 -> V_50 = V_18 ;
V_1 -> V_115 = ( sizeof( void * ) == 8 ) ;
V_1 -> V_108 = 0 ;
V_1 -> V_116 = 0 ;
V_1 -> V_109 = 0 ;
V_1 -> V_34 = 0 ;
V_1 -> V_117 = 1 ;
V_1 -> V_118 = 1 ;
V_1 -> V_99 = V_119 ;
V_1 -> V_120 = V_121 ;
F_68 ( & V_1 -> V_122 ) ;
F_68 ( & V_1 -> V_38 . V_39 ) ;
}
return V_1 ;
}
void F_69 ( struct V_1 * V_1 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_110 ; ++ V_61 )
F_70 ( & V_1 -> V_111 [ V_61 ] ) ;
if ( V_1 -> V_102 ) {
F_71 ( ( char * * ) & V_1 -> V_96 ) ;
V_1 -> V_102 = false ;
}
if ( V_1 -> V_101 ) {
F_71 ( ( char * * ) & V_1 -> V_27 ) ;
V_1 -> V_101 = false ;
}
F_27 ( V_1 ) ;
F_30 ( & V_1 -> V_38 . V_75 ) ;
F_72 ( V_1 ) ;
F_71 ( & V_1 -> V_123 ) ;
free ( V_1 ) ;
}
void F_73 ( struct V_1 * V_1 , void * V_35 )
{
memcpy ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) ;
V_1 -> V_34 = 1 ;
}
bool F_74 ( const struct V_1 * V_1 , T_6 * V_35 )
{
return memcmp ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) == 0 ;
}
void F_75 ( struct V_1 * V_1 , struct V_47 * V_47 )
{
char V_124 [ V_48 ] ;
if ( F_76 ( V_47 ) )
return;
sprintf ( V_124 , L_14 , V_47 -> V_20 ) ;
if ( F_77 ( V_124 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
}
int F_78 ( struct V_1 * V_1 ,
const char * V_20 )
{
char V_21 [ V_48 ] ;
const char * V_42 = V_1 -> V_96 + 1 ;
snprintf ( V_21 , sizeof( V_21 ) ,
L_15 ,
V_20 , ( int ) strlen ( V_42 ) - 1 , V_42 ) ;
if ( F_77 ( V_21 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
return 0 ;
}
bool F_79 ( struct V_125 * V_126 , bool V_127 )
{
bool V_128 = false ;
struct V_1 * V_129 ;
F_80 (pos, head, node) {
if ( V_127 && ! V_129 -> V_130 )
continue;
if ( V_129 -> V_34 ) {
V_128 = true ;
continue;
}
if ( F_81 ( V_129 -> V_27 , V_129 -> V_35 ,
sizeof( V_129 -> V_35 ) ) > 0 ) {
V_128 = true ;
V_129 -> V_34 = true ;
}
}
return V_128 ;
}
void F_82 ( struct V_125 * V_126 , struct V_1 * V_1 )
{
F_8 ( & V_1 -> V_122 , V_126 ) ;
}
struct V_1 * F_83 ( const struct V_125 * V_126 , const char * V_42 , bool V_131 )
{
struct V_1 * V_129 ;
if ( V_131 ) {
F_80 (pos, head, node)
if ( strcmp ( V_129 -> V_96 , V_42 ) == 0 )
return V_129 ;
return NULL ;
}
F_80 (pos, head, node)
if ( strcmp ( V_129 -> V_27 , V_42 ) == 0 )
return V_129 ;
return NULL ;
}
struct V_1 * F_58 ( struct V_125 * V_126 , const char * V_42 )
{
struct V_1 * V_1 = F_83 ( V_126 , V_42 , false ) ;
if ( ! V_1 ) {
V_1 = F_55 ( V_42 ) ;
if ( V_1 != NULL ) {
F_82 ( V_126 , V_1 ) ;
F_61 ( V_1 ) ;
}
}
return V_1 ;
}
T_1 F_84 ( struct V_125 * V_126 , T_8 * V_132 ,
bool (F_85)( struct V_1 * V_1 , int V_133 ) , int V_133 )
{
struct V_1 * V_129 ;
T_1 V_25 = 0 ;
F_80 (pos, head, node) {
if ( F_85 && F_85 ( V_129 , V_133 ) )
continue;
V_25 += F_86 ( V_129 , V_132 ) ;
V_25 += fprintf ( V_132 , L_16 , V_129 -> V_27 ) ;
}
return V_25 ;
}
T_1 F_87 ( struct V_125 * V_126 , T_8 * V_132 )
{
struct V_1 * V_129 ;
T_1 V_25 = 0 ;
F_80 (pos, head, node) {
int V_61 ;
for ( V_61 = 0 ; V_61 < V_110 ; ++ V_61 )
V_25 += F_88 ( V_129 , V_61 , V_132 ) ;
}
return V_25 ;
}
T_1 F_86 ( struct V_1 * V_1 , T_8 * V_132 )
{
char V_134 [ V_24 * 2 + 1 ] ;
F_6 ( V_1 -> V_35 , sizeof( V_1 -> V_35 ) , V_134 ) ;
return fprintf ( V_132 , L_3 , V_134 ) ;
}
T_1 F_88 ( struct V_1 * V_1 , enum V_107 type , T_8 * V_132 )
{
struct V_72 * V_135 ;
T_1 V_25 = fprintf ( V_132 , L_17 , V_1 -> V_96 ) ;
if ( V_1 -> V_96 != V_1 -> V_27 )
V_25 += fprintf ( V_132 , L_18 , V_1 -> V_27 ) ;
V_25 += fprintf ( V_132 , L_19 , V_136 [ type ] ,
F_65 ( V_1 , type ) ? L_10 : L_20 ) ;
V_25 += F_86 ( V_1 , V_132 ) ;
V_25 += fprintf ( V_132 , L_21 ) ;
for ( V_135 = F_31 ( & V_1 -> V_111 [ type ] ) ; V_135 ; V_135 = F_33 ( V_135 ) ) {
struct V_137 * V_129 = F_32 ( V_135 , struct V_137 , V_72 ) ;
V_25 += F_89 ( V_129 , V_132 ) ;
}
return V_25 ;
}
enum V_97 F_90 ( struct V_1 * V_1 , struct V_47 * V_47 )
{
int V_43 ;
V_43 = F_28 ( V_1 , V_47 ) ;
if ( V_43 < 0 )
return V_138 ;
return F_91 ( V_43 ) ;
}
