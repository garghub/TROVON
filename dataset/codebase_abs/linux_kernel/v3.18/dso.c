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
T_1 V_26 ;
switch ( type ) {
case V_6 : {
char * V_27 ;
strncpy ( V_21 , V_1 -> V_28 , V_22 ) ;
V_27 = V_21 + V_1 -> V_29 ;
while ( V_27 != V_21 && * V_27 != '/' )
V_27 -- ;
if ( * V_27 == '/' )
V_27 ++ ;
V_25 = F_3 ( V_1 -> V_28 , V_27 ,
V_22 - ( V_27 - V_21 ) ) ;
}
break;
case V_7 :
if ( V_30 . V_31 [ 0 ] ||
( F_4 ( V_1 , V_21 , V_22 ) == NULL ) )
V_25 = - 1 ;
break;
case V_8 :
V_26 = F_5 ( V_21 , V_22 , L_1 ) ;
snprintf ( V_21 + V_26 , V_22 - V_26 , L_2 , V_1 -> V_28 ) ;
break;
case V_9 :
V_26 = F_5 ( V_21 , V_22 , L_1 ) ;
snprintf ( V_21 + V_26 , V_22 - V_26 , L_3 , V_1 -> V_28 ) ;
break;
case V_10 :
{
const char * V_32 ;
T_1 V_33 ;
V_32 = V_1 -> V_28 + V_1 -> V_29 ;
while ( V_32 != V_1 -> V_28 && * V_32 != '/' )
V_32 -- ;
V_26 = F_5 ( V_21 , V_22 , L_4 ) ;
V_33 = V_32 - V_1 -> V_28 + 2 ;
if ( V_33 > ( V_22 - V_26 ) ) {
V_25 = - 1 ;
break;
}
V_26 += F_6 ( V_21 + V_26 , V_33 , L_3 , V_1 -> V_28 ) ;
V_26 += F_6 ( V_21 + V_26 , V_22 - V_26 , L_5 ,
V_32 ) ;
break;
}
case V_11 :
if ( ! V_1 -> V_34 ) {
V_25 = - 1 ;
break;
}
F_7 ( V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ,
V_23 ) ;
V_26 = F_5 ( V_21 , V_22 , L_6 ) ;
snprintf ( V_21 + V_26 , V_22 - V_26 , L_7 ,
V_23 , V_23 + 2 ) ;
break;
case V_4 :
case V_16 :
case V_12 :
F_5 ( V_21 , V_22 , V_1 -> V_28 ) ;
break;
case V_15 :
F_8 ( V_21 , V_22 , V_30 . V_31 ,
V_20 , V_1 -> V_28 ) ;
break;
case V_13 :
F_5 ( V_21 , V_22 , V_1 -> V_28 ) ;
break;
case V_36 :
case V_37 :
snprintf ( V_21 , V_22 , L_3 , V_1 -> V_28 ) ;
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
static void F_9 ( struct V_1 * V_1 )
{
F_10 ( & V_1 -> V_38 . V_39 , & V_40 ) ;
V_41 ++ ;
}
static void F_11 ( struct V_1 * V_1 )
{
F_12 ( & V_1 -> V_38 . V_39 ) ;
F_13 ( V_41 <= 0 ,
L_8 ) ;
V_41 -- ;
}
static int F_14 ( char * V_42 )
{
int V_43 ;
char V_44 [ V_45 ] ;
do {
V_43 = F_15 ( V_42 , V_46 ) ;
if ( V_43 >= 0 )
return V_43 ;
F_16 ( L_9 ,
F_17 ( V_47 , V_44 , sizeof( V_44 ) ) ) ;
if ( ! V_41 || V_47 != V_48 )
break;
F_18 () ;
} while ( 1 );
return - 1 ;
}
static int F_19 ( struct V_1 * V_1 , struct V_49 * V_49 )
{
int V_43 ;
char * V_20 = ( char * ) L_4 ;
char * V_42 = malloc ( V_50 ) ;
if ( ! V_42 )
return - V_51 ;
if ( V_49 )
V_20 = V_49 -> V_20 ;
if ( F_2 ( V_1 , V_1 -> V_52 ,
V_20 , V_42 , V_50 ) ) {
free ( V_42 ) ;
return - V_53 ;
}
V_43 = F_14 ( V_42 ) ;
free ( V_42 ) ;
return V_43 ;
}
static int F_20 ( struct V_1 * V_1 , struct V_49 * V_49 )
{
int V_43 = F_19 ( V_1 , V_49 ) ;
if ( V_43 >= 0 ) {
F_9 ( V_1 ) ;
F_21 () ;
}
return V_43 ;
}
static void F_22 ( struct V_1 * V_1 )
{
if ( V_1 -> V_38 . V_43 >= 0 ) {
F_23 ( V_1 -> V_38 . V_43 ) ;
V_1 -> V_38 . V_43 = - 1 ;
V_1 -> V_38 . V_54 = 0 ;
F_11 ( V_1 ) ;
}
}
static void F_24 ( struct V_1 * V_1 )
{
F_22 ( V_1 ) ;
}
static void F_18 ( void )
{
struct V_1 * V_1 ;
V_1 = F_25 ( & V_40 , struct V_1 , V_38 . V_39 ) ;
F_24 ( V_1 ) ;
}
static T_2 F_26 ( void )
{
struct V_55 V_56 ;
T_2 V_57 = 0 ;
if ( F_27 ( V_58 , & V_56 ) == 0 ) {
if ( V_56 . V_59 == V_60 )
V_57 = V_56 . V_59 ;
else
V_57 = V_56 . V_59 / 2 ;
} else {
F_28 ( L_10 ) ;
V_57 = 1 ;
}
return V_57 ;
}
static bool F_29 ( void )
{
static T_2 V_57 ;
if ( ! V_57 )
V_57 = F_26 () ;
if ( V_57 == V_60 )
return true ;
return V_57 > ( T_2 ) V_41 ;
}
static void F_21 ( void )
{
bool V_61 = F_29 () ;
if ( ! V_61 )
F_18 () ;
}
void F_30 ( struct V_1 * V_1 )
{
F_24 ( V_1 ) ;
}
int F_31 ( struct V_1 * V_1 , struct V_49 * V_49 )
{
enum V_19 V_62 [] = {
V_7 ,
V_12 ,
V_18 ,
} ;
int V_63 = 0 ;
if ( V_1 -> V_38 . V_64 == V_65 )
return - 1 ;
if ( V_1 -> V_38 . V_43 >= 0 )
goto V_66;
if ( V_1 -> V_52 != V_18 ) {
V_1 -> V_38 . V_43 = F_20 ( V_1 , V_49 ) ;
goto V_66;
}
do {
V_1 -> V_52 = V_62 [ V_63 ++ ] ;
V_1 -> V_38 . V_43 = F_20 ( V_1 , V_49 ) ;
if ( V_1 -> V_38 . V_43 >= 0 )
goto V_66;
} while ( V_1 -> V_52 != V_18 );
V_66:
if ( V_1 -> V_38 . V_43 >= 0 )
V_1 -> V_38 . V_64 = V_67 ;
else
V_1 -> V_38 . V_64 = V_65 ;
return V_1 -> V_38 . V_43 ;
}
bool F_32 ( struct V_1 * V_1 , enum V_68 V_69 )
{
T_3 V_70 = 1 << V_69 ;
if ( V_1 -> V_38 . V_71 & V_70 )
return true ;
V_1 -> V_38 . V_71 |= V_70 ;
return false ;
}
static void
F_33 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = F_34 ( V_73 ) ;
while ( V_75 ) {
struct V_76 * V_77 ;
V_77 = F_35 ( V_75 , struct V_76 , V_74 ) ;
V_75 = F_36 ( & V_77 -> V_74 ) ;
F_37 ( & V_77 -> V_74 , V_73 ) ;
free ( V_77 ) ;
}
}
static struct V_76 * F_38 ( const struct V_72 * V_73 , T_4 V_78 )
{
struct V_74 * const * V_79 = & V_73 -> V_74 ;
const struct V_74 * V_80 = NULL ;
struct V_76 * V_77 ;
while ( * V_79 != NULL ) {
T_4 V_81 ;
V_80 = * V_79 ;
V_77 = F_35 ( V_80 , struct V_76 , V_74 ) ;
V_81 = V_77 -> V_78 + V_82 ;
if ( V_78 < V_77 -> V_78 )
V_79 = & ( * V_79 ) -> V_83 ;
else if ( V_78 >= V_81 )
V_79 = & ( * V_79 ) -> V_84 ;
else
return V_77 ;
}
return NULL ;
}
static void
F_39 ( struct V_72 * V_73 , struct V_76 * V_85 )
{
struct V_74 * * V_79 = & V_73 -> V_74 ;
struct V_74 * V_80 = NULL ;
struct V_76 * V_77 ;
T_4 V_78 = V_85 -> V_78 ;
while ( * V_79 != NULL ) {
T_4 V_81 ;
V_80 = * V_79 ;
V_77 = F_35 ( V_80 , struct V_76 , V_74 ) ;
V_81 = V_77 -> V_78 + V_82 ;
if ( V_78 < V_77 -> V_78 )
V_79 = & ( * V_79 ) -> V_83 ;
else if ( V_78 >= V_81 )
V_79 = & ( * V_79 ) -> V_84 ;
}
F_40 ( & V_85 -> V_74 , V_80 , V_79 ) ;
F_41 ( & V_85 -> V_74 , V_73 ) ;
}
static T_5
F_42 ( struct V_76 * V_77 , T_4 V_78 ,
T_6 * V_38 , T_4 V_22 )
{
T_4 V_86 = V_78 - V_77 -> V_78 ;
T_4 V_87 = F_43 ( V_77 -> V_22 - V_86 , V_22 ) ;
memcpy ( V_38 , V_77 -> V_38 + V_86 , V_87 ) ;
return V_87 ;
}
static T_5
F_44 ( struct V_1 * V_1 , T_4 V_78 , T_6 * V_38 , T_5 V_22 )
{
struct V_76 * V_77 ;
T_5 V_25 ;
do {
T_4 V_86 ;
V_25 = - V_51 ;
V_77 = F_45 ( sizeof( * V_77 ) + V_82 ) ;
if ( ! V_77 )
break;
V_86 = V_78 & V_88 ;
V_25 = - V_53 ;
if ( - 1 == F_46 ( V_1 -> V_38 . V_43 , V_86 , V_89 ) )
break;
V_25 = F_47 ( V_1 -> V_38 . V_43 , V_77 -> V_38 , V_82 ) ;
if ( V_25 <= 0 )
break;
V_77 -> V_78 = V_86 ;
V_77 -> V_22 = V_25 ;
F_39 ( & V_1 -> V_38 . V_77 , V_77 ) ;
V_25 = F_42 ( V_77 , V_78 , V_38 , V_22 ) ;
} while ( 0 );
if ( V_25 <= 0 )
free ( V_77 ) ;
return V_25 ;
}
static T_5 F_48 ( struct V_1 * V_1 , T_4 V_78 ,
T_6 * V_38 , T_5 V_22 )
{
struct V_76 * V_77 ;
V_77 = F_38 ( & V_1 -> V_38 . V_77 , V_78 ) ;
if ( V_77 )
return F_42 ( V_77 , V_78 , V_38 , V_22 ) ;
else
return F_44 ( V_1 , V_78 , V_38 , V_22 ) ;
}
static T_5 F_49 ( struct V_1 * V_1 , T_4 V_78 , T_6 * V_38 , T_5 V_22 )
{
T_5 V_90 = 0 ;
T_6 * V_79 = V_38 ;
do {
T_5 V_25 ;
V_25 = F_48 ( V_1 , V_78 , V_79 , V_22 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 )
break;
F_50 ( V_25 > V_22 ) ;
V_90 += V_25 ;
V_79 += V_25 ;
V_78 += V_25 ;
V_22 -= V_25 ;
} while ( V_22 );
return V_90 ;
}
static int F_51 ( struct V_1 * V_1 )
{
struct V_91 V_92 ;
char V_44 [ V_45 ] ;
if ( ! V_1 -> V_38 . V_54 ) {
if ( F_52 ( V_1 -> V_38 . V_43 , & V_92 ) ) {
F_28 ( L_11 ,
F_17 ( V_47 , V_44 , sizeof( V_44 ) ) ) ;
return - 1 ;
}
V_1 -> V_38 . V_54 = V_92 . V_93 ;
}
return 0 ;
}
T_7 F_53 ( struct V_1 * V_1 , struct V_49 * V_49 )
{
int V_43 ;
V_43 = F_31 ( V_1 , V_49 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( F_51 ( V_1 ) )
return - 1 ;
return V_1 -> V_38 . V_54 ;
}
static T_5 F_54 ( struct V_1 * V_1 , T_4 V_78 ,
T_6 * V_38 , T_5 V_22 )
{
if ( F_51 ( V_1 ) )
return - 1 ;
if ( V_78 > V_1 -> V_38 . V_54 )
return - 1 ;
if ( V_78 + V_22 < V_78 )
return - 1 ;
return F_49 ( V_1 , V_78 , V_38 , V_22 ) ;
}
T_5 F_55 ( struct V_1 * V_1 , struct V_49 * V_49 ,
T_4 V_78 , T_6 * V_38 , T_5 V_22 )
{
if ( F_31 ( V_1 , V_49 ) < 0 )
return - 1 ;
return F_54 ( V_1 , V_78 , V_38 , V_22 ) ;
}
T_5 F_56 ( struct V_1 * V_1 , struct V_94 * V_94 ,
struct V_49 * V_49 , T_4 V_95 ,
T_6 * V_38 , T_5 V_22 )
{
T_4 V_78 = V_94 -> V_96 ( V_94 , V_95 ) ;
return F_55 ( V_1 , V_49 , V_78 , V_38 , V_22 ) ;
}
struct V_94 * F_57 ( const char * V_42 )
{
struct V_94 * V_94 = NULL ;
struct V_1 * V_1 = F_58 ( V_42 ) ;
if ( V_1 )
V_94 = F_59 ( 0 , V_1 , V_97 ) ;
return V_94 ;
}
struct V_1 * F_60 ( struct V_49 * V_49 , const char * V_42 ,
const char * V_98 , int V_99 )
{
struct V_1 * V_1 = F_61 ( & V_49 -> V_100 , V_42 ) ;
if ( V_1 != NULL ) {
F_62 ( V_1 , V_98 , false ) ;
V_1 -> V_101 = V_99 ;
}
return V_1 ;
}
static struct V_1 * F_63 ( struct V_72 * V_73 ,
struct V_1 * V_1 , const char * V_42 )
{
struct V_74 * * V_79 = & V_73 -> V_74 ;
struct V_74 * V_80 = NULL ;
if ( ! V_42 )
V_42 = V_1 -> V_28 ;
while ( * V_79 ) {
struct V_1 * V_102 = F_35 ( * V_79 , struct V_1 , V_74 ) ;
int V_103 = strcmp ( V_42 , V_102 -> V_28 ) ;
V_80 = * V_79 ;
if ( V_103 == 0 ) {
if ( ! V_1 || ( V_1 == V_102 ) )
return V_102 ;
V_103 = strcmp ( V_1 -> V_98 , V_102 -> V_98 ) ;
if ( V_103 == 0 ) {
F_28 ( L_12 , V_42 ) ;
return NULL ;
}
}
if ( V_103 < 0 )
V_79 = & V_80 -> V_83 ;
else
V_79 = & V_80 -> V_84 ;
}
if ( V_1 ) {
F_40 ( & V_1 -> V_74 , V_80 , V_79 ) ;
F_41 ( & V_1 -> V_74 , V_73 ) ;
}
return NULL ;
}
static inline struct V_1 *
F_64 ( const struct V_72 * V_73 , const char * V_42 )
{
return F_63 ( (struct V_72 * ) V_73 , NULL , V_42 ) ;
}
void F_65 ( struct V_1 * V_1 , const char * V_42 , bool V_104 )
{
if ( V_42 == NULL )
return;
if ( V_1 -> V_105 )
free ( ( char * ) V_1 -> V_28 ) ;
V_1 -> V_28 = V_42 ;
V_1 -> V_29 = strlen ( V_42 ) ;
V_1 -> V_105 = V_104 ;
}
void F_62 ( struct V_1 * V_1 , const char * V_42 , bool V_104 )
{
if ( V_42 == NULL )
return;
if ( V_1 -> V_106 )
free ( ( char * ) V_1 -> V_98 ) ;
V_1 -> V_98 = V_42 ;
V_1 -> V_107 = strlen ( V_42 ) ;
V_1 -> V_106 = V_104 ;
}
static void F_66 ( struct V_1 * V_1 )
{
char * V_108 , * V_109 = F_67 ( V_1 -> V_28 ) ;
if ( ! V_109 )
return;
V_108 = F_67 ( F_68 ( V_109 ) ) ;
free ( V_109 ) ;
if ( ! V_108 )
return;
F_62 ( V_1 , V_108 , true ) ;
}
int F_69 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_13 ) ;
if ( V_110 )
return V_1 -> V_29 ;
return V_1 -> V_107 ;
}
bool F_70 ( const struct V_1 * V_1 , enum V_111 type )
{
return V_1 -> V_112 & ( 1 << type ) ;
}
bool F_71 ( const struct V_1 * V_1 , enum V_111 type )
{
return V_1 -> V_113 & ( 1 << type ) ;
}
void F_72 ( struct V_1 * V_1 , enum V_111 type )
{
V_1 -> V_113 |= ( 1 << type ) ;
}
struct V_1 * F_58 ( const char * V_42 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_42 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_63 ;
strcpy ( V_1 -> V_42 , V_42 ) ;
F_65 ( V_1 , V_1 -> V_42 , false ) ;
F_62 ( V_1 , V_1 -> V_42 , false ) ;
for ( V_63 = 0 ; V_63 < V_114 ; ++ V_63 )
V_1 -> V_115 [ V_63 ] = V_1 -> V_116 [ V_63 ] = V_117 ;
V_1 -> V_38 . V_77 = V_117 ;
V_1 -> V_38 . V_43 = - 1 ;
V_1 -> V_38 . V_64 = V_118 ;
V_1 -> V_17 = V_18 ;
V_1 -> V_52 = V_18 ;
V_1 -> V_119 = ( sizeof( void * ) == 8 ) ;
V_1 -> V_112 = 0 ;
V_1 -> V_120 = 0 ;
V_1 -> V_113 = 0 ;
V_1 -> V_34 = 0 ;
V_1 -> V_121 = 1 ;
V_1 -> V_122 = 1 ;
V_1 -> V_101 = V_123 ;
V_1 -> V_124 = V_125 ;
F_73 ( & V_1 -> V_74 ) ;
F_74 ( & V_1 -> V_126 ) ;
F_74 ( & V_1 -> V_38 . V_39 ) ;
}
return V_1 ;
}
void F_75 ( struct V_1 * V_1 )
{
int V_63 ;
if ( ! F_76 ( & V_1 -> V_74 ) )
F_28 ( L_14 ,
V_1 -> V_28 ) ;
for ( V_63 = 0 ; V_63 < V_114 ; ++ V_63 )
F_77 ( & V_1 -> V_115 [ V_63 ] ) ;
if ( V_1 -> V_106 ) {
F_78 ( ( char * * ) & V_1 -> V_98 ) ;
V_1 -> V_106 = false ;
}
if ( V_1 -> V_105 ) {
F_78 ( ( char * * ) & V_1 -> V_28 ) ;
V_1 -> V_105 = false ;
}
F_30 ( V_1 ) ;
F_33 ( & V_1 -> V_38 . V_77 ) ;
F_79 ( V_1 ) ;
F_78 ( & V_1 -> V_127 ) ;
free ( V_1 ) ;
}
void F_80 ( struct V_1 * V_1 , void * V_35 )
{
memcpy ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) ;
V_1 -> V_34 = 1 ;
}
bool F_81 ( const struct V_1 * V_1 , T_6 * V_35 )
{
return memcmp ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) == 0 ;
}
void F_82 ( struct V_1 * V_1 , struct V_49 * V_49 )
{
char V_128 [ V_50 ] ;
if ( F_83 ( V_49 ) )
return;
sprintf ( V_128 , L_15 , V_49 -> V_20 ) ;
if ( F_84 ( V_128 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
}
int F_85 ( struct V_1 * V_1 ,
const char * V_20 )
{
char V_21 [ V_50 ] ;
const char * V_42 = V_1 -> V_98 + 1 ;
snprintf ( V_21 , sizeof( V_21 ) ,
L_16 ,
V_20 , ( int ) strlen ( V_42 ) - 1 , V_42 ) ;
if ( F_84 ( V_21 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
return 0 ;
}
bool F_86 ( struct V_129 * V_130 , bool V_131 )
{
bool V_132 = false ;
struct V_1 * V_133 ;
F_87 (pos, head, node) {
if ( V_131 && ! V_133 -> V_134 )
continue;
if ( V_133 -> V_34 ) {
V_132 = true ;
continue;
}
if ( F_88 ( V_133 -> V_28 , V_133 -> V_35 ,
sizeof( V_133 -> V_35 ) ) > 0 ) {
V_132 = true ;
V_133 -> V_34 = true ;
}
}
return V_132 ;
}
void F_89 ( struct V_135 * V_135 , struct V_1 * V_1 )
{
F_10 ( & V_1 -> V_126 , & V_135 -> V_130 ) ;
F_63 ( & V_135 -> V_73 , V_1 , NULL ) ;
}
struct V_1 * F_90 ( const struct V_135 * V_135 , const char * V_42 ,
bool V_136 )
{
struct V_1 * V_133 ;
if ( V_136 ) {
F_87 (pos, &dsos->head, node)
if ( strcmp ( V_133 -> V_98 , V_42 ) == 0 )
return V_133 ;
return NULL ;
}
return F_64 ( & V_135 -> V_73 , V_42 ) ;
}
struct V_1 * F_61 ( struct V_135 * V_135 , const char * V_42 )
{
struct V_1 * V_1 = F_90 ( V_135 , V_42 , false ) ;
if ( ! V_1 ) {
V_1 = F_58 ( V_42 ) ;
if ( V_1 != NULL ) {
F_89 ( V_135 , V_1 ) ;
F_66 ( V_1 ) ;
}
}
return V_1 ;
}
T_1 F_91 ( struct V_129 * V_130 , T_8 * V_137 ,
bool (F_92)( struct V_1 * V_1 , int V_138 ) , int V_138 )
{
struct V_1 * V_133 ;
T_1 V_25 = 0 ;
F_87 (pos, head, node) {
if ( F_92 && F_92 ( V_133 , V_138 ) )
continue;
V_25 += F_93 ( V_133 , V_137 ) ;
V_25 += fprintf ( V_137 , L_17 , V_133 -> V_28 ) ;
}
return V_25 ;
}
T_1 F_94 ( struct V_129 * V_130 , T_8 * V_137 )
{
struct V_1 * V_133 ;
T_1 V_25 = 0 ;
F_87 (pos, head, node) {
int V_63 ;
for ( V_63 = 0 ; V_63 < V_114 ; ++ V_63 )
V_25 += F_95 ( V_133 , V_63 , V_137 ) ;
}
return V_25 ;
}
T_1 F_93 ( struct V_1 * V_1 , T_8 * V_137 )
{
char V_139 [ V_24 * 2 + 1 ] ;
F_7 ( V_1 -> V_35 , sizeof( V_1 -> V_35 ) , V_139 ) ;
return fprintf ( V_137 , L_3 , V_139 ) ;
}
T_1 F_95 ( struct V_1 * V_1 , enum V_111 type , T_8 * V_137 )
{
struct V_74 * V_140 ;
T_1 V_25 = fprintf ( V_137 , L_18 , V_1 -> V_98 ) ;
if ( V_1 -> V_98 != V_1 -> V_28 )
V_25 += fprintf ( V_137 , L_19 , V_1 -> V_28 ) ;
V_25 += fprintf ( V_137 , L_20 , V_141 [ type ] ,
F_70 ( V_1 , type ) ? L_4 : L_21 ) ;
V_25 += F_93 ( V_1 , V_137 ) ;
V_25 += fprintf ( V_137 , L_22 ) ;
for ( V_140 = F_34 ( & V_1 -> V_115 [ type ] ) ; V_140 ; V_140 = F_36 ( V_140 ) ) {
struct V_142 * V_133 = F_35 ( V_140 , struct V_142 , V_74 ) ;
V_25 += F_96 ( V_133 , V_137 ) ;
}
return V_25 ;
}
enum V_99 F_97 ( struct V_1 * V_1 , struct V_49 * V_49 )
{
int V_43 ;
V_43 = F_31 ( V_1 , V_49 ) ;
if ( V_43 < 0 )
return V_143 ;
return F_98 ( V_43 ) ;
}
