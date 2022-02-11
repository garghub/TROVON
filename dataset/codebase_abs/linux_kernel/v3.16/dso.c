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
if ( V_43 > 0 ) {
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
if ( V_1 -> V_38 . V_43 >= 0 )
return V_1 -> V_38 . V_43 ;
if ( V_1 -> V_50 != V_18 ) {
V_1 -> V_38 . V_43 = F_17 ( V_1 , V_47 ) ;
return V_1 -> V_38 . V_43 ;
}
do {
int V_43 ;
V_1 -> V_50 = V_60 [ V_61 ++ ] ;
V_43 = F_17 ( V_1 , V_47 ) ;
if ( V_43 >= 0 )
return V_1 -> V_38 . V_43 = V_43 ;
} while ( V_1 -> V_50 != V_18 );
return - V_51 ;
}
static void
F_29 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = F_30 ( V_63 ) ;
while ( V_65 ) {
struct V_66 * V_67 ;
V_67 = F_31 ( V_65 , struct V_66 , V_64 ) ;
V_65 = F_32 ( & V_67 -> V_64 ) ;
F_33 ( & V_67 -> V_64 , V_63 ) ;
free ( V_67 ) ;
}
}
static struct V_66 * F_34 ( const struct V_62 * V_63 , T_3 V_68 )
{
struct V_64 * const * V_69 = & V_63 -> V_64 ;
const struct V_64 * V_70 = NULL ;
struct V_66 * V_67 ;
while ( * V_69 != NULL ) {
T_3 V_71 ;
V_70 = * V_69 ;
V_67 = F_31 ( V_70 , struct V_66 , V_64 ) ;
V_71 = V_67 -> V_68 + V_72 ;
if ( V_68 < V_67 -> V_68 )
V_69 = & ( * V_69 ) -> V_73 ;
else if ( V_68 >= V_71 )
V_69 = & ( * V_69 ) -> V_74 ;
else
return V_67 ;
}
return NULL ;
}
static void
F_35 ( struct V_62 * V_63 , struct V_66 * V_75 )
{
struct V_64 * * V_69 = & V_63 -> V_64 ;
struct V_64 * V_70 = NULL ;
struct V_66 * V_67 ;
T_3 V_68 = V_75 -> V_68 ;
while ( * V_69 != NULL ) {
T_3 V_71 ;
V_70 = * V_69 ;
V_67 = F_31 ( V_70 , struct V_66 , V_64 ) ;
V_71 = V_67 -> V_68 + V_72 ;
if ( V_68 < V_67 -> V_68 )
V_69 = & ( * V_69 ) -> V_73 ;
else if ( V_68 >= V_71 )
V_69 = & ( * V_69 ) -> V_74 ;
}
F_36 ( & V_75 -> V_64 , V_70 , V_69 ) ;
F_37 ( & V_75 -> V_64 , V_63 ) ;
}
static T_4
F_38 ( struct V_66 * V_67 , T_3 V_68 ,
T_5 * V_38 , T_3 V_22 )
{
T_3 V_76 = V_68 - V_67 -> V_68 ;
T_3 V_77 = F_39 ( V_67 -> V_22 - V_76 , V_22 ) ;
memcpy ( V_38 , V_67 -> V_38 + V_76 , V_77 ) ;
return V_77 ;
}
static T_4
F_40 ( struct V_1 * V_1 , T_3 V_68 , T_5 * V_38 , T_4 V_22 )
{
struct V_66 * V_67 ;
T_4 V_25 ;
do {
T_3 V_76 ;
V_25 = - V_49 ;
V_67 = F_41 ( sizeof( * V_67 ) + V_72 ) ;
if ( ! V_67 )
break;
V_76 = V_68 & V_78 ;
V_25 = - V_51 ;
if ( - 1 == F_42 ( V_1 -> V_38 . V_43 , V_76 , V_79 ) )
break;
V_25 = F_43 ( V_1 -> V_38 . V_43 , V_67 -> V_38 , V_72 ) ;
if ( V_25 <= 0 )
break;
V_67 -> V_68 = V_76 ;
V_67 -> V_22 = V_25 ;
F_35 ( & V_1 -> V_38 . V_67 , V_67 ) ;
V_25 = F_38 ( V_67 , V_68 , V_38 , V_22 ) ;
} while ( 0 );
if ( V_25 <= 0 )
free ( V_67 ) ;
return V_25 ;
}
static T_4 F_44 ( struct V_1 * V_1 , T_3 V_68 ,
T_5 * V_38 , T_4 V_22 )
{
struct V_66 * V_67 ;
V_67 = F_34 ( & V_1 -> V_38 . V_67 , V_68 ) ;
if ( V_67 )
return F_38 ( V_67 , V_68 , V_38 , V_22 ) ;
else
return F_40 ( V_1 , V_68 , V_38 , V_22 ) ;
}
static T_4 F_45 ( struct V_1 * V_1 , T_3 V_68 , T_5 * V_38 , T_4 V_22 )
{
T_4 V_80 = 0 ;
T_5 * V_69 = V_38 ;
do {
T_4 V_25 ;
V_25 = F_44 ( V_1 , V_68 , V_69 , V_22 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 )
break;
F_46 ( V_25 > V_22 ) ;
V_80 += V_25 ;
V_69 += V_25 ;
V_68 += V_25 ;
V_22 -= V_25 ;
} while ( V_22 );
return V_80 ;
}
static int F_47 ( struct V_1 * V_1 )
{
struct V_81 V_82 ;
if ( ! V_1 -> V_38 . V_52 ) {
if ( F_48 ( V_1 -> V_38 . V_43 , & V_82 ) ) {
F_25 ( L_12 , strerror ( V_45 ) ) ;
return - 1 ;
}
V_1 -> V_38 . V_52 = V_82 . V_83 ;
}
return 0 ;
}
static T_4 F_49 ( struct V_1 * V_1 , T_3 V_68 ,
T_5 * V_38 , T_4 V_22 )
{
if ( F_47 ( V_1 ) )
return - 1 ;
if ( V_68 > V_1 -> V_38 . V_52 )
return - 1 ;
if ( V_68 + V_22 < V_68 )
return - 1 ;
return F_45 ( V_1 , V_68 , V_38 , V_22 ) ;
}
T_4 F_50 ( struct V_1 * V_1 , struct V_47 * V_47 ,
T_3 V_68 , T_5 * V_38 , T_4 V_22 )
{
if ( F_28 ( V_1 , V_47 ) < 0 )
return - 1 ;
return F_49 ( V_1 , V_68 , V_38 , V_22 ) ;
}
T_4 F_51 ( struct V_1 * V_1 , struct V_84 * V_84 ,
struct V_47 * V_47 , T_3 V_85 ,
T_5 * V_38 , T_4 V_22 )
{
T_3 V_68 = V_84 -> V_86 ( V_84 , V_85 ) ;
return F_50 ( V_1 , V_47 , V_68 , V_38 , V_22 ) ;
}
struct V_84 * F_52 ( const char * V_42 )
{
struct V_84 * V_84 = NULL ;
struct V_1 * V_1 = F_53 ( V_42 ) ;
if ( V_1 )
V_84 = F_54 ( 0 , V_1 , V_87 ) ;
return V_84 ;
}
struct V_1 * F_55 ( struct V_47 * V_47 , const char * V_42 ,
const char * V_88 , int V_89 )
{
struct V_1 * V_1 = F_56 ( & V_47 -> V_90 , V_42 ) ;
if ( V_1 != NULL ) {
F_57 ( V_1 , V_88 , false ) ;
V_1 -> V_91 = V_89 ;
}
return V_1 ;
}
void F_58 ( struct V_1 * V_1 , const char * V_42 , bool V_92 )
{
if ( V_42 == NULL )
return;
if ( V_1 -> V_93 )
free ( ( char * ) V_1 -> V_27 ) ;
V_1 -> V_27 = V_42 ;
V_1 -> V_28 = strlen ( V_42 ) ;
V_1 -> V_93 = V_92 ;
}
void F_57 ( struct V_1 * V_1 , const char * V_42 , bool V_92 )
{
if ( V_42 == NULL )
return;
if ( V_1 -> V_94 )
free ( ( char * ) V_1 -> V_88 ) ;
V_1 -> V_88 = V_42 ;
V_1 -> V_95 = strlen ( V_42 ) ;
V_1 -> V_94 = V_92 ;
}
static void F_59 ( struct V_1 * V_1 )
{
char * V_96 , * V_97 = F_60 ( V_1 -> V_27 ) ;
if ( ! V_97 )
return;
V_96 = F_60 ( F_61 ( V_97 ) ) ;
free ( V_97 ) ;
if ( ! V_96 )
return;
F_57 ( V_1 , V_96 , true ) ;
}
int F_62 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_13 ) ;
if ( V_98 )
return V_1 -> V_28 ;
return V_1 -> V_95 ;
}
bool F_63 ( const struct V_1 * V_1 , enum V_99 type )
{
return V_1 -> V_100 & ( 1 << type ) ;
}
bool F_64 ( const struct V_1 * V_1 , enum V_99 type )
{
return V_1 -> V_101 & ( 1 << type ) ;
}
void F_65 ( struct V_1 * V_1 , enum V_99 type )
{
V_1 -> V_101 |= ( 1 << type ) ;
}
struct V_1 * F_53 ( const char * V_42 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_42 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_61 ;
strcpy ( V_1 -> V_42 , V_42 ) ;
F_58 ( V_1 , V_1 -> V_42 , false ) ;
F_57 ( V_1 , V_1 -> V_42 , false ) ;
for ( V_61 = 0 ; V_61 < V_102 ; ++ V_61 )
V_1 -> V_103 [ V_61 ] = V_1 -> V_104 [ V_61 ] = V_105 ;
V_1 -> V_38 . V_67 = V_105 ;
V_1 -> V_38 . V_43 = - 1 ;
V_1 -> V_17 = V_18 ;
V_1 -> V_50 = V_18 ;
V_1 -> V_100 = 0 ;
V_1 -> V_106 = 0 ;
V_1 -> V_101 = 0 ;
V_1 -> V_34 = 0 ;
V_1 -> V_107 = 1 ;
V_1 -> V_108 = 1 ;
V_1 -> V_91 = V_109 ;
V_1 -> V_110 = V_111 ;
F_66 ( & V_1 -> V_112 ) ;
F_66 ( & V_1 -> V_38 . V_39 ) ;
}
return V_1 ;
}
void F_67 ( struct V_1 * V_1 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_102 ; ++ V_61 )
F_68 ( & V_1 -> V_103 [ V_61 ] ) ;
if ( V_1 -> V_94 ) {
F_69 ( ( char * * ) & V_1 -> V_88 ) ;
V_1 -> V_94 = false ;
}
if ( V_1 -> V_93 ) {
F_69 ( ( char * * ) & V_1 -> V_27 ) ;
V_1 -> V_93 = false ;
}
F_27 ( V_1 ) ;
F_29 ( & V_1 -> V_38 . V_67 ) ;
F_70 ( V_1 ) ;
F_69 ( & V_1 -> V_113 ) ;
free ( V_1 ) ;
}
void F_71 ( struct V_1 * V_1 , void * V_35 )
{
memcpy ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) ;
V_1 -> V_34 = 1 ;
}
bool F_72 ( const struct V_1 * V_1 , T_5 * V_35 )
{
return memcmp ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) == 0 ;
}
void F_73 ( struct V_1 * V_1 , struct V_47 * V_47 )
{
char V_114 [ V_48 ] ;
if ( F_74 ( V_47 ) )
return;
sprintf ( V_114 , L_14 , V_47 -> V_20 ) ;
if ( F_75 ( V_114 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
}
int F_76 ( struct V_1 * V_1 ,
const char * V_20 )
{
char V_21 [ V_48 ] ;
const char * V_42 = V_1 -> V_88 + 1 ;
snprintf ( V_21 , sizeof( V_21 ) ,
L_15 ,
V_20 , ( int ) strlen ( V_42 ) - 1 , V_42 ) ;
if ( F_75 ( V_21 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
return 0 ;
}
bool F_77 ( struct V_115 * V_116 , bool V_117 )
{
bool V_118 = false ;
struct V_1 * V_119 ;
F_78 (pos, head, node) {
if ( V_117 && ! V_119 -> V_120 )
continue;
if ( V_119 -> V_34 ) {
V_118 = true ;
continue;
}
if ( F_79 ( V_119 -> V_27 , V_119 -> V_35 ,
sizeof( V_119 -> V_35 ) ) > 0 ) {
V_118 = true ;
V_119 -> V_34 = true ;
}
}
return V_118 ;
}
void F_80 ( struct V_115 * V_116 , struct V_1 * V_1 )
{
F_8 ( & V_1 -> V_112 , V_116 ) ;
}
struct V_1 * F_81 ( const struct V_115 * V_116 , const char * V_42 , bool V_121 )
{
struct V_1 * V_119 ;
if ( V_121 ) {
F_78 (pos, head, node)
if ( strcmp ( V_119 -> V_88 , V_42 ) == 0 )
return V_119 ;
return NULL ;
}
F_78 (pos, head, node)
if ( strcmp ( V_119 -> V_27 , V_42 ) == 0 )
return V_119 ;
return NULL ;
}
struct V_1 * F_56 ( struct V_115 * V_116 , const char * V_42 )
{
struct V_1 * V_1 = F_81 ( V_116 , V_42 , false ) ;
if ( ! V_1 ) {
V_1 = F_53 ( V_42 ) ;
if ( V_1 != NULL ) {
F_80 ( V_116 , V_1 ) ;
F_59 ( V_1 ) ;
}
}
return V_1 ;
}
T_1 F_82 ( struct V_115 * V_116 , T_6 * V_122 ,
bool (F_83)( struct V_1 * V_1 , int V_123 ) , int V_123 )
{
struct V_1 * V_119 ;
T_1 V_25 = 0 ;
F_78 (pos, head, node) {
if ( F_83 && F_83 ( V_119 , V_123 ) )
continue;
V_25 += F_84 ( V_119 , V_122 ) ;
V_25 += fprintf ( V_122 , L_16 , V_119 -> V_27 ) ;
}
return V_25 ;
}
T_1 F_85 ( struct V_115 * V_116 , T_6 * V_122 )
{
struct V_1 * V_119 ;
T_1 V_25 = 0 ;
F_78 (pos, head, node) {
int V_61 ;
for ( V_61 = 0 ; V_61 < V_102 ; ++ V_61 )
V_25 += F_86 ( V_119 , V_61 , V_122 ) ;
}
return V_25 ;
}
T_1 F_84 ( struct V_1 * V_1 , T_6 * V_122 )
{
char V_124 [ V_24 * 2 + 1 ] ;
F_6 ( V_1 -> V_35 , sizeof( V_1 -> V_35 ) , V_124 ) ;
return fprintf ( V_122 , L_3 , V_124 ) ;
}
T_1 F_86 ( struct V_1 * V_1 , enum V_99 type , T_6 * V_122 )
{
struct V_64 * V_125 ;
T_1 V_25 = fprintf ( V_122 , L_17 , V_1 -> V_88 ) ;
if ( V_1 -> V_88 != V_1 -> V_27 )
V_25 += fprintf ( V_122 , L_18 , V_1 -> V_27 ) ;
V_25 += fprintf ( V_122 , L_19 , V_126 [ type ] ,
F_63 ( V_1 , type ) ? L_10 : L_20 ) ;
V_25 += F_84 ( V_1 , V_122 ) ;
V_25 += fprintf ( V_122 , L_21 ) ;
for ( V_125 = F_30 ( & V_1 -> V_103 [ type ] ) ; V_125 ; V_125 = F_32 ( V_125 ) ) {
struct V_127 * V_119 = F_31 ( V_125 , struct V_127 , V_64 ) ;
V_25 += F_87 ( V_119 , V_122 ) ;
}
return V_25 ;
}
