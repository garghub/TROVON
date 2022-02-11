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
bool F_10 ( const char * V_44 , int V_45 )
{
struct V_46 V_47 ;
int V_48 = V_45 & V_49 ;
F_11 ( V_48 != V_45 ,
L_8 ,
V_45 ) ;
switch ( V_48 ) {
case V_50 :
case V_51 :
case V_52 :
return false ;
default:
if ( F_12 ( & V_47 , V_44 ) ) {
F_13 ( L_9 ,
V_44 ) ;
return true ;
}
}
return V_47 . V_53 ;
}
bool F_14 ( const char * V_40 , const char * V_23 , int V_54 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_42 [ V_41 ] . V_43 ; V_41 ++ ) {
if ( ! strcmp ( V_40 , V_42 [ V_41 ] . V_43 ) )
return ! V_42 [ V_41 ] . F_15 ( V_23 ,
V_54 ) ;
}
return false ;
}
bool F_16 ( struct V_1 * V_1 )
{
return V_1 -> V_19 == V_14 ||
V_1 -> V_19 == V_17 ;
}
int F_17 ( struct V_46 * V_47 , const char * V_55 ,
bool V_56 , bool V_57 )
{
const char * V_58 = strrchr ( V_55 , '/' ) ;
const char * V_40 = strrchr ( V_55 , '.' ) ;
bool V_59 = false ;
memset ( V_47 , 0x0 , sizeof( * V_47 ) ) ;
V_58 = V_58 ? V_58 + 1 : V_55 ;
if ( V_58 [ 0 ] == '[' ) {
V_59 = true ;
if ( ( strncmp ( V_58 , L_10 , 17 ) == 0 ) ||
( strncmp ( V_58 , L_11 , 22 ) == 0 ) ||
( strncmp ( V_58 , L_12 , 6 ) == 0 ) ||
( strncmp ( V_58 , L_13 , 10 ) == 0 ) ) {
V_47 -> V_53 = false ;
} else
V_47 -> V_53 = true ;
}
if ( ( V_40 == NULL ) || V_59 ) {
if ( V_56 ) {
V_47 -> V_58 = F_18 ( V_58 ) ;
return V_47 -> V_58 ? 0 : - V_60 ;
}
return 0 ;
}
if ( F_9 ( V_40 + 1 ) ) {
V_47 -> V_61 = true ;
V_40 -= 3 ;
}
if ( V_40 > V_58 )
V_47 -> V_53 = ! strncmp ( V_40 , L_14 , 3 ) ;
if ( V_56 ) {
if ( V_47 -> V_53 ) {
if ( F_19 ( & V_47 -> V_58 , L_15 , ( int ) ( V_40 - V_58 ) , V_58 ) == - 1 )
return - V_60 ;
} else {
if ( F_19 ( & V_47 -> V_58 , L_3 , V_58 ) == - 1 )
return - V_60 ;
}
F_20 ( V_47 -> V_58 , '-' , '_' ) ;
}
if ( V_57 && V_47 -> V_61 ) {
V_47 -> V_40 = F_18 ( V_40 + 4 ) ;
if ( ! V_47 -> V_40 ) {
free ( ( void * ) V_47 -> V_58 ) ;
return - V_60 ;
}
}
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
F_22 ( & V_1 -> V_62 . V_63 , & V_64 ) ;
V_65 ++ ;
}
static void F_23 ( struct V_1 * V_1 )
{
F_24 ( & V_1 -> V_62 . V_63 ) ;
F_11 ( V_65 <= 0 ,
L_16 ) ;
V_65 -- ;
}
static int F_25 ( char * V_58 )
{
int V_66 ;
char V_67 [ V_68 ] ;
do {
V_66 = F_26 ( V_58 , V_69 ) ;
if ( V_66 >= 0 )
return V_66 ;
F_27 ( L_17 ,
F_28 ( V_70 , V_67 , sizeof( V_67 ) ) ) ;
if ( ! V_65 || V_70 != V_71 )
break;
F_29 () ;
} while ( 1 );
return - 1 ;
}
static int F_30 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
int V_66 ;
char * V_22 = ( char * ) L_4 ;
char * V_58 = malloc ( V_73 ) ;
if ( ! V_58 )
return - V_60 ;
if ( V_72 )
V_22 = V_72 -> V_22 ;
if ( F_2 ( V_1 , V_1 -> V_74 ,
V_22 , V_58 , V_73 ) ) {
free ( V_58 ) ;
return - V_75 ;
}
V_66 = F_25 ( V_58 ) ;
free ( V_58 ) ;
return V_66 ;
}
static int F_31 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
int V_66 = F_30 ( V_1 , V_72 ) ;
if ( V_66 >= 0 ) {
F_21 ( V_1 ) ;
F_32 () ;
}
return V_66 ;
}
static void F_33 ( struct V_1 * V_1 )
{
if ( V_1 -> V_62 . V_66 >= 0 ) {
F_34 ( V_1 -> V_62 . V_66 ) ;
V_1 -> V_62 . V_66 = - 1 ;
V_1 -> V_62 . V_76 = 0 ;
F_23 ( V_1 ) ;
}
}
static void F_35 ( struct V_1 * V_1 )
{
F_33 ( V_1 ) ;
}
static void F_29 ( void )
{
struct V_1 * V_1 ;
V_1 = F_36 ( & V_64 , struct V_1 , V_62 . V_63 ) ;
F_35 ( V_1 ) ;
}
static T_2 F_37 ( void )
{
struct V_77 V_78 ;
T_2 V_79 = 0 ;
if ( F_38 ( V_80 , & V_78 ) == 0 ) {
if ( V_78 . V_81 == V_82 )
V_79 = V_78 . V_81 ;
else
V_79 = V_78 . V_81 / 2 ;
} else {
F_13 ( L_18 ) ;
V_79 = 1 ;
}
return V_79 ;
}
static bool F_39 ( void )
{
static T_2 V_79 ;
if ( ! V_79 )
V_79 = F_37 () ;
if ( V_79 == V_82 )
return true ;
return V_79 > ( T_2 ) V_65 ;
}
static void F_32 ( void )
{
bool V_83 = F_39 () ;
if ( ! V_83 )
F_29 () ;
}
void F_40 ( struct V_1 * V_1 )
{
F_41 ( & V_84 ) ;
F_35 ( V_1 ) ;
F_42 ( & V_84 ) ;
}
static void F_43 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
enum V_21 V_85 [] = {
V_7 ,
V_12 ,
V_20 ,
} ;
int V_41 = 0 ;
if ( V_1 -> V_62 . V_66 >= 0 )
return;
if ( V_1 -> V_74 != V_20 ) {
V_1 -> V_62 . V_66 = F_31 ( V_1 , V_72 ) ;
goto V_86;
}
do {
V_1 -> V_74 = V_85 [ V_41 ++ ] ;
V_1 -> V_62 . V_66 = F_31 ( V_1 , V_72 ) ;
if ( V_1 -> V_62 . V_66 >= 0 )
goto V_86;
} while ( V_1 -> V_74 != V_20 );
V_86:
if ( V_1 -> V_62 . V_66 >= 0 )
V_1 -> V_62 . V_87 = V_88 ;
else
V_1 -> V_62 . V_87 = V_89 ;
}
int F_44 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
if ( V_1 -> V_62 . V_87 == V_89 )
return - 1 ;
if ( F_41 ( & V_84 ) < 0 )
return - 1 ;
F_43 ( V_1 , V_72 ) ;
if ( V_1 -> V_62 . V_66 < 0 )
F_42 ( & V_84 ) ;
return V_1 -> V_62 . V_66 ;
}
void F_45 ( struct V_1 * V_1 V_90 )
{
F_42 ( & V_84 ) ;
}
bool F_46 ( struct V_1 * V_1 , enum V_91 V_92 )
{
T_3 V_93 = 1 << V_92 ;
if ( V_1 -> V_62 . V_94 & V_93 )
return true ;
V_1 -> V_62 . V_94 |= V_93 ;
return false ;
}
static void
F_47 ( struct V_1 * V_1 )
{
struct V_95 * V_96 = & V_1 -> V_62 . V_97 ;
struct V_98 * V_99 = F_48 ( V_96 ) ;
F_41 ( & V_1 -> V_100 ) ;
while ( V_99 ) {
struct V_101 * V_97 ;
V_97 = F_49 ( V_99 , struct V_101 , V_98 ) ;
V_99 = F_50 ( & V_97 -> V_98 ) ;
F_51 ( & V_97 -> V_98 , V_96 ) ;
free ( V_97 ) ;
}
F_42 ( & V_1 -> V_100 ) ;
}
static struct V_101 * F_52 ( struct V_1 * V_1 , T_4 V_102 )
{
const struct V_95 * V_96 = & V_1 -> V_62 . V_97 ;
struct V_98 * const * V_103 = & V_96 -> V_98 ;
const struct V_98 * V_104 = NULL ;
struct V_101 * V_97 ;
while ( * V_103 != NULL ) {
T_4 V_105 ;
V_104 = * V_103 ;
V_97 = F_49 ( V_104 , struct V_101 , V_98 ) ;
V_105 = V_97 -> V_102 + V_106 ;
if ( V_102 < V_97 -> V_102 )
V_103 = & ( * V_103 ) -> V_107 ;
else if ( V_102 >= V_105 )
V_103 = & ( * V_103 ) -> V_108 ;
else
return V_97 ;
}
return NULL ;
}
static struct V_101 *
F_53 ( struct V_1 * V_1 , struct V_101 * V_109 )
{
struct V_95 * V_96 = & V_1 -> V_62 . V_97 ;
struct V_98 * * V_103 = & V_96 -> V_98 ;
struct V_98 * V_104 = NULL ;
struct V_101 * V_97 ;
T_4 V_102 = V_109 -> V_102 ;
F_41 ( & V_1 -> V_100 ) ;
while ( * V_103 != NULL ) {
T_4 V_105 ;
V_104 = * V_103 ;
V_97 = F_49 ( V_104 , struct V_101 , V_98 ) ;
V_105 = V_97 -> V_102 + V_106 ;
if ( V_102 < V_97 -> V_102 )
V_103 = & ( * V_103 ) -> V_107 ;
else if ( V_102 >= V_105 )
V_103 = & ( * V_103 ) -> V_108 ;
else
goto V_86;
}
F_54 ( & V_109 -> V_98 , V_104 , V_103 ) ;
F_55 ( & V_109 -> V_98 , V_96 ) ;
V_97 = NULL ;
V_86:
F_42 ( & V_1 -> V_100 ) ;
return V_97 ;
}
static T_5
F_56 ( struct V_101 * V_97 , T_4 V_102 ,
T_6 * V_62 , T_4 V_24 )
{
T_4 V_110 = V_102 - V_97 -> V_102 ;
T_4 V_111 = F_57 ( V_97 -> V_24 - V_110 , V_24 ) ;
memcpy ( V_62 , V_97 -> V_62 + V_110 , V_111 ) ;
return V_111 ;
}
static T_5
F_58 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_102 , T_6 * V_62 , T_5 V_24 )
{
struct V_101 * V_97 ;
struct V_101 * V_112 ;
T_5 V_27 ;
do {
T_4 V_110 ;
V_97 = F_59 ( sizeof( * V_97 ) + V_106 ) ;
if ( ! V_97 )
return - V_60 ;
F_41 ( & V_84 ) ;
F_43 ( V_1 , V_72 ) ;
if ( V_1 -> V_62 . V_66 < 0 ) {
V_27 = - V_70 ;
V_1 -> V_62 . V_87 = V_89 ;
break;
}
V_110 = V_102 & V_113 ;
V_27 = F_60 ( V_1 -> V_62 . V_66 , V_97 -> V_62 , V_106 , V_110 ) ;
if ( V_27 <= 0 )
break;
V_97 -> V_102 = V_110 ;
V_97 -> V_24 = V_27 ;
} while ( 0 );
F_42 ( & V_84 ) ;
if ( V_27 > 0 ) {
V_112 = F_53 ( V_1 , V_97 ) ;
if ( V_112 ) {
free ( V_97 ) ;
V_97 = V_112 ;
}
V_27 = F_56 ( V_97 , V_102 , V_62 , V_24 ) ;
}
if ( V_27 <= 0 )
free ( V_97 ) ;
return V_27 ;
}
static T_5 F_61 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_102 , T_6 * V_62 , T_5 V_24 )
{
struct V_101 * V_97 ;
V_97 = F_52 ( V_1 , V_102 ) ;
if ( V_97 )
return F_56 ( V_97 , V_102 , V_62 , V_24 ) ;
else
return F_58 ( V_1 , V_72 , V_102 , V_62 , V_24 ) ;
}
static T_5 F_62 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_102 , T_6 * V_62 , T_5 V_24 )
{
T_5 V_114 = 0 ;
T_6 * V_103 = V_62 ;
do {
T_5 V_27 ;
V_27 = F_61 ( V_1 , V_72 , V_102 , V_103 , V_24 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! V_27 )
break;
F_63 ( V_27 > V_24 ) ;
V_114 += V_27 ;
V_103 += V_27 ;
V_102 += V_27 ;
V_24 -= V_27 ;
} while ( V_24 );
return V_114 ;
}
static int F_64 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
int V_27 = 0 ;
struct V_115 V_116 ;
char V_67 [ V_68 ] ;
if ( V_1 -> V_62 . V_76 )
return 0 ;
if ( V_1 -> V_62 . V_87 == V_89 )
return - 1 ;
F_41 ( & V_84 ) ;
F_43 ( V_1 , V_72 ) ;
if ( V_1 -> V_62 . V_66 < 0 ) {
V_27 = - V_70 ;
V_1 -> V_62 . V_87 = V_89 ;
goto V_86;
}
if ( F_65 ( V_1 -> V_62 . V_66 , & V_116 ) < 0 ) {
V_27 = - V_70 ;
F_13 ( L_19 ,
F_28 ( V_70 , V_67 , sizeof( V_67 ) ) ) ;
V_1 -> V_62 . V_87 = V_89 ;
goto V_86;
}
V_1 -> V_62 . V_76 = V_116 . V_117 ;
V_86:
F_42 ( & V_84 ) ;
return V_27 ;
}
T_7 F_66 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
if ( F_64 ( V_1 , V_72 ) )
return - 1 ;
return V_1 -> V_62 . V_76 ;
}
static T_5 F_67 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_102 , T_6 * V_62 , T_5 V_24 )
{
if ( F_64 ( V_1 , V_72 ) )
return - 1 ;
if ( V_102 > V_1 -> V_62 . V_76 )
return - 1 ;
if ( V_102 + V_24 < V_102 )
return - 1 ;
return F_62 ( V_1 , V_72 , V_102 , V_62 , V_24 ) ;
}
T_5 F_68 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_102 , T_6 * V_62 , T_5 V_24 )
{
if ( V_1 -> V_62 . V_87 == V_89 )
return - 1 ;
return F_67 ( V_1 , V_72 , V_102 , V_62 , V_24 ) ;
}
T_5 F_69 ( struct V_1 * V_1 , struct V_118 * V_118 ,
struct V_72 * V_72 , T_4 V_119 ,
T_6 * V_62 , T_5 V_24 )
{
T_4 V_102 = V_118 -> V_120 ( V_118 , V_119 ) ;
return F_68 ( V_1 , V_72 , V_102 , V_62 , V_24 ) ;
}
struct V_118 * F_70 ( const char * V_58 )
{
struct V_118 * V_118 = NULL ;
struct V_1 * V_1 = F_71 ( V_58 ) ;
if ( V_1 )
V_118 = F_72 ( 0 , V_1 , V_121 ) ;
return V_118 ;
}
struct V_1 * F_73 ( struct V_72 * V_72 , const char * V_58 ,
const char * V_122 , int V_123 )
{
struct V_1 * V_1 = F_74 ( V_72 , V_58 ) ;
if ( V_1 != NULL ) {
F_75 ( V_1 , V_122 , false ) ;
V_1 -> V_124 = V_123 ;
}
return V_1 ;
}
static struct V_1 * F_76 ( struct V_95 * V_96 ,
struct V_1 * V_1 , const char * V_58 )
{
struct V_98 * * V_103 = & V_96 -> V_98 ;
struct V_98 * V_104 = NULL ;
if ( ! V_58 )
V_58 = V_1 -> V_30 ;
while ( * V_103 ) {
struct V_1 * V_125 = F_49 ( * V_103 , struct V_1 , V_98 ) ;
int V_126 = strcmp ( V_58 , V_125 -> V_30 ) ;
V_104 = * V_103 ;
if ( V_126 == 0 ) {
if ( ! V_1 || ( V_1 == V_125 ) )
return V_125 ;
V_126 = strcmp ( V_1 -> V_122 , V_125 -> V_122 ) ;
if ( V_126 == 0 ) {
F_13 ( L_20 , V_58 ) ;
return NULL ;
}
}
if ( V_126 < 0 )
V_103 = & V_104 -> V_107 ;
else
V_103 = & V_104 -> V_108 ;
}
if ( V_1 ) {
F_54 ( & V_1 -> V_98 , V_104 , V_103 ) ;
F_55 ( & V_1 -> V_98 , V_96 ) ;
V_1 -> V_96 = V_96 ;
}
return NULL ;
}
static inline struct V_1 * F_77 ( struct V_95 * V_96 ,
const char * V_58 )
{
return F_76 ( V_96 , NULL , V_58 ) ;
}
void F_78 ( struct V_1 * V_1 , const char * V_58 , bool V_127 )
{
struct V_95 * V_96 = V_1 -> V_96 ;
if ( V_58 == NULL )
return;
if ( V_1 -> V_128 )
free ( ( char * ) V_1 -> V_30 ) ;
if ( V_96 ) {
F_51 ( & V_1 -> V_98 , V_96 ) ;
F_79 ( & V_1 -> V_98 ) ;
V_1 -> V_96 = NULL ;
}
V_1 -> V_30 = V_58 ;
V_1 -> V_35 = strlen ( V_58 ) ;
V_1 -> V_128 = V_127 ;
if ( V_96 )
F_76 ( V_96 , V_1 , NULL ) ;
}
void F_75 ( struct V_1 * V_1 , const char * V_58 , bool V_127 )
{
if ( V_58 == NULL )
return;
if ( V_1 -> V_129 )
free ( ( char * ) V_1 -> V_122 ) ;
V_1 -> V_122 = V_58 ;
V_1 -> V_130 = strlen ( V_58 ) ;
V_1 -> V_129 = V_127 ;
}
static void F_80 ( struct V_1 * V_1 )
{
char * V_131 , * V_132 = F_18 ( V_1 -> V_30 ) ;
if ( ! V_132 )
return;
V_131 = F_18 ( F_81 ( V_132 ) ) ;
free ( V_132 ) ;
if ( ! V_131 )
return;
F_75 ( V_1 , V_131 , true ) ;
}
int F_82 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_21 ) ;
if ( V_133 )
return V_1 -> V_35 ;
return V_1 -> V_130 ;
}
bool F_83 ( const struct V_1 * V_1 , enum V_134 type )
{
return V_1 -> V_135 & ( 1 << type ) ;
}
bool F_84 ( const struct V_1 * V_1 , enum V_134 type )
{
return V_1 -> V_136 & ( 1 << type ) ;
}
void F_85 ( struct V_1 * V_1 , enum V_134 type )
{
V_1 -> V_136 |= ( 1 << type ) ;
}
struct V_1 * F_71 ( const char * V_58 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_58 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_41 ;
strcpy ( V_1 -> V_58 , V_58 ) ;
F_78 ( V_1 , V_1 -> V_58 , false ) ;
F_75 ( V_1 , V_1 -> V_58 , false ) ;
for ( V_41 = 0 ; V_41 < V_137 ; ++ V_41 )
V_1 -> V_138 [ V_41 ] = V_1 -> V_139 [ V_41 ] = V_140 ;
V_1 -> V_62 . V_97 = V_140 ;
V_1 -> V_62 . V_66 = - 1 ;
V_1 -> V_62 . V_87 = V_141 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_74 = V_20 ;
V_1 -> V_142 = ( sizeof( void * ) == 8 ) ;
V_1 -> V_135 = 0 ;
V_1 -> V_143 = 0 ;
V_1 -> V_136 = 0 ;
V_1 -> V_36 = 0 ;
V_1 -> V_144 = 1 ;
V_1 -> V_145 = 1 ;
V_1 -> V_124 = V_146 ;
V_1 -> V_147 = V_148 ;
F_79 ( & V_1 -> V_98 ) ;
V_1 -> V_96 = NULL ;
F_86 ( & V_1 -> V_149 ) ;
F_86 ( & V_1 -> V_62 . V_63 ) ;
F_87 ( & V_1 -> V_100 , NULL ) ;
F_88 ( & V_1 -> V_150 , 1 ) ;
}
return V_1 ;
}
void F_89 ( struct V_1 * V_1 )
{
int V_41 ;
if ( ! F_90 ( & V_1 -> V_98 ) )
F_13 ( L_22 ,
V_1 -> V_30 ) ;
for ( V_41 = 0 ; V_41 < V_137 ; ++ V_41 )
F_91 ( & V_1 -> V_138 [ V_41 ] ) ;
if ( V_1 -> V_129 ) {
F_92 ( ( char * * ) & V_1 -> V_122 ) ;
V_1 -> V_129 = false ;
}
if ( V_1 -> V_128 ) {
F_92 ( ( char * * ) & V_1 -> V_30 ) ;
V_1 -> V_128 = false ;
}
F_40 ( V_1 ) ;
F_93 ( V_1 -> V_151 ) ;
F_47 ( V_1 ) ;
F_94 ( V_1 ) ;
F_92 ( & V_1 -> V_152 ) ;
F_95 ( & V_1 -> V_100 ) ;
free ( V_1 ) ;
}
struct V_1 * F_96 ( struct V_1 * V_1 )
{
if ( V_1 )
F_97 ( & V_1 -> V_150 ) ;
return V_1 ;
}
void F_98 ( struct V_1 * V_1 )
{
if ( V_1 && F_99 ( & V_1 -> V_150 ) )
F_89 ( V_1 ) ;
}
void F_100 ( struct V_1 * V_1 , void * V_37 )
{
memcpy ( V_1 -> V_37 , V_37 , sizeof( V_1 -> V_37 ) ) ;
V_1 -> V_36 = 1 ;
}
bool F_101 ( const struct V_1 * V_1 , T_6 * V_37 )
{
return memcmp ( V_1 -> V_37 , V_37 , sizeof( V_1 -> V_37 ) ) == 0 ;
}
void F_102 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
char V_55 [ V_73 ] ;
if ( F_103 ( V_72 ) )
return;
sprintf ( V_55 , L_23 , V_72 -> V_22 ) ;
if ( F_104 ( V_55 , V_1 -> V_37 ,
sizeof( V_1 -> V_37 ) ) == 0 )
V_1 -> V_36 = true ;
}
int F_105 ( struct V_1 * V_1 ,
const char * V_22 )
{
char V_23 [ V_73 ] ;
const char * V_58 = V_1 -> V_122 + 1 ;
snprintf ( V_23 , sizeof( V_23 ) ,
L_24 ,
V_22 , ( int ) strlen ( V_58 ) - 1 , V_58 ) ;
if ( F_104 ( V_23 , V_1 -> V_37 ,
sizeof( V_1 -> V_37 ) ) == 0 )
V_1 -> V_36 = true ;
return 0 ;
}
bool F_106 ( struct V_153 * V_154 , bool V_155 )
{
bool V_156 = false ;
struct V_1 * V_157 ;
F_107 (pos, head, node) {
if ( V_155 && ! V_157 -> V_158 )
continue;
if ( V_157 -> V_36 ) {
V_156 = true ;
continue;
}
if ( F_108 ( V_157 -> V_30 , V_157 -> V_37 ,
sizeof( V_157 -> V_37 ) ) > 0 ) {
V_156 = true ;
V_157 -> V_36 = true ;
}
}
return V_156 ;
}
void F_109 ( struct V_159 * V_159 , struct V_1 * V_1 )
{
F_22 ( & V_1 -> V_149 , & V_159 -> V_154 ) ;
F_76 ( & V_159 -> V_96 , V_1 , NULL ) ;
F_96 ( V_1 ) ;
}
void F_110 ( struct V_159 * V_159 , struct V_1 * V_1 )
{
F_111 ( & V_159 -> V_100 ) ;
F_109 ( V_159 , V_1 ) ;
F_112 ( & V_159 -> V_100 ) ;
}
struct V_1 * F_113 ( struct V_159 * V_159 , const char * V_58 , bool V_160 )
{
struct V_1 * V_157 ;
if ( V_160 ) {
F_107 (pos, &dsos->head, node)
if ( strcmp ( V_157 -> V_122 , V_58 ) == 0 )
return V_157 ;
return NULL ;
}
return F_77 ( & V_159 -> V_96 , V_58 ) ;
}
struct V_1 * F_114 ( struct V_159 * V_159 , const char * V_58 , bool V_160 )
{
struct V_1 * V_1 ;
F_115 ( & V_159 -> V_100 ) ;
V_1 = F_113 ( V_159 , V_58 , V_160 ) ;
F_112 ( & V_159 -> V_100 ) ;
return V_1 ;
}
struct V_1 * F_116 ( struct V_159 * V_159 , const char * V_58 )
{
struct V_1 * V_1 = F_71 ( V_58 ) ;
if ( V_1 != NULL ) {
F_109 ( V_159 , V_1 ) ;
F_80 ( V_1 ) ;
}
return V_1 ;
}
struct V_1 * F_117 ( struct V_159 * V_159 , const char * V_58 )
{
struct V_1 * V_1 = F_113 ( V_159 , V_58 , false ) ;
return V_1 ? V_1 : F_116 ( V_159 , V_58 ) ;
}
struct V_1 * F_118 ( struct V_159 * V_159 , const char * V_58 )
{
struct V_1 * V_1 ;
F_111 ( & V_159 -> V_100 ) ;
V_1 = F_96 ( F_117 ( V_159 , V_58 ) ) ;
F_112 ( & V_159 -> V_100 ) ;
return V_1 ;
}
T_1 F_119 ( struct V_153 * V_154 , T_8 * V_161 ,
bool (F_120)( struct V_1 * V_1 , int V_162 ) , int V_162 )
{
struct V_1 * V_157 ;
T_1 V_27 = 0 ;
F_107 (pos, head, node) {
if ( F_120 && F_120 ( V_157 , V_162 ) )
continue;
V_27 += F_121 ( V_157 , V_161 ) ;
V_27 += fprintf ( V_161 , L_25 , V_157 -> V_30 ) ;
}
return V_27 ;
}
T_1 F_122 ( struct V_153 * V_154 , T_8 * V_161 )
{
struct V_1 * V_157 ;
T_1 V_27 = 0 ;
F_107 (pos, head, node) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_137 ; ++ V_41 )
V_27 += F_123 ( V_157 , V_41 , V_161 ) ;
}
return V_27 ;
}
T_1 F_121 ( struct V_1 * V_1 , T_8 * V_161 )
{
char V_163 [ V_26 * 2 + 1 ] ;
F_7 ( V_1 -> V_37 , sizeof( V_1 -> V_37 ) , V_163 ) ;
return fprintf ( V_161 , L_3 , V_163 ) ;
}
T_1 F_123 ( struct V_1 * V_1 , enum V_134 type , T_8 * V_161 )
{
struct V_98 * V_164 ;
T_1 V_27 = fprintf ( V_161 , L_26 , V_1 -> V_122 ) ;
if ( V_1 -> V_122 != V_1 -> V_30 )
V_27 += fprintf ( V_161 , L_27 , V_1 -> V_30 ) ;
V_27 += fprintf ( V_161 , L_28 , V_165 [ type ] ,
F_83 ( V_1 , type ) ? L_4 : L_29 ) ;
V_27 += F_121 ( V_1 , V_161 ) ;
V_27 += fprintf ( V_161 , L_30 ) ;
for ( V_164 = F_48 ( & V_1 -> V_138 [ type ] ) ; V_164 ; V_164 = F_50 ( V_164 ) ) {
struct V_166 * V_157 = F_49 ( V_164 , struct V_166 , V_98 ) ;
V_27 += F_124 ( V_157 , V_161 ) ;
}
return V_27 ;
}
enum V_123 F_125 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
int V_66 ;
enum V_123 type = V_167 ;
V_66 = F_44 ( V_1 , V_72 ) ;
if ( V_66 >= 0 ) {
type = F_126 ( V_66 ) ;
F_45 ( V_1 ) ;
}
return type ;
}
int F_127 ( struct V_1 * V_1 , char * V_168 , T_1 V_169 )
{
int V_170 , V_171 = V_1 -> V_172 ;
static const char * V_173 [] = {
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
} ;
F_63 ( V_169 == 0 ) ;
if ( V_171 >= 0 ) {
const char * V_174 = F_28 ( V_171 , V_168 , V_169 ) ;
if ( V_174 != V_168 )
F_6 ( V_168 , V_169 , L_3 , V_174 ) ;
return 0 ;
}
if ( V_171 < V_175 || V_171 >= V_176 )
return - 1 ;
V_170 = V_171 - V_175 ;
F_6 ( V_168 , V_169 , L_3 , V_173 [ V_170 ] ) ;
return 0 ;
}
