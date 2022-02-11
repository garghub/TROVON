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
char V_25 [ V_26 ] ;
int V_27 = 0 ;
T_1 V_28 ;
switch ( type ) {
case V_6 :
{
const char * V_29 ;
char V_30 [ V_31 ] ;
char V_32 [ V_31 ] ;
unsigned int V_33 ;
V_28 = F_3 ( V_23 , V_24 , V_1 -> V_34 ) ;
V_29 = V_23 + V_28 ;
while ( V_29 != V_23 && * V_29 != '/' )
V_29 -- ;
strncpy ( V_30 , V_23 , V_29 - V_23 ) ;
V_30 [ V_29 - V_23 ] = '\0' ;
if ( ! F_4 ( V_23 ) ) {
V_27 = - 1 ;
break;
}
V_27 = F_5 ( V_23 , V_32 , V_31 ) ;
if ( V_27 )
break;
V_27 = - 1 ;
for ( V_33 = 0 ; V_33 < F_6 ( V_35 ) ; V_33 ++ ) {
snprintf ( V_23 , V_24 ,
V_35 [ V_33 ] , V_30 , V_32 ) ;
if ( F_4 ( V_23 ) ) {
V_27 = 0 ;
break;
}
}
break;
}
case V_7 :
if ( F_7 ( V_1 , V_23 , V_24 ) == NULL )
V_27 = - 1 ;
break;
case V_8 :
V_28 = F_3 ( V_23 , V_24 , L_1 ) ;
snprintf ( V_23 + V_28 , V_24 - V_28 , L_2 , V_1 -> V_34 ) ;
break;
case V_9 :
V_28 = F_3 ( V_23 , V_24 , L_1 ) ;
snprintf ( V_23 + V_28 , V_24 - V_28 , L_3 , V_1 -> V_34 ) ;
break;
case V_10 :
{
const char * V_29 ;
T_1 V_36 ;
V_29 = V_1 -> V_34 + V_1 -> V_37 ;
while ( V_29 != V_1 -> V_34 && * V_29 != '/' )
V_29 -- ;
V_28 = F_3 ( V_23 , V_24 , L_4 ) ;
V_36 = V_29 - V_1 -> V_34 + 2 ;
if ( V_36 > ( V_24 - V_28 ) ) {
V_27 = - 1 ;
break;
}
V_28 += F_8 ( V_23 + V_28 , V_36 , L_3 , V_1 -> V_34 ) ;
V_28 += F_8 ( V_23 + V_28 , V_24 - V_28 , L_5 ,
V_29 ) ;
break;
}
case V_11 :
if ( ! V_1 -> V_38 ) {
V_27 = - 1 ;
break;
}
F_9 ( V_1 -> V_39 ,
sizeof( V_1 -> V_39 ) ,
V_25 ) ;
V_28 = F_3 ( V_23 , V_24 , L_6 ) ;
snprintf ( V_23 + V_28 , V_24 - V_28 , L_7 ,
V_25 , V_25 + 2 ) ;
break;
case V_4 :
case V_18 :
case V_12 :
F_3 ( V_23 , V_24 , V_1 -> V_34 ) ;
break;
case V_16 :
case V_17 :
F_10 ( V_23 , V_24 , V_40 . V_41 ,
V_22 , V_1 -> V_34 ) ;
break;
case V_13 :
case V_14 :
F_3 ( V_23 , V_24 , V_1 -> V_34 ) ;
break;
case V_42 :
case V_43 :
snprintf ( V_23 , V_24 , L_3 , V_1 -> V_34 ) ;
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
bool F_11 ( const char * V_44 )
{
unsigned V_33 ;
for ( V_33 = 0 ; V_45 [ V_33 ] . V_46 ; V_33 ++ ) {
if ( ! strcmp ( V_44 , V_45 [ V_33 ] . V_46 ) )
return true ;
}
return false ;
}
bool F_12 ( const char * V_47 , int V_48 )
{
struct V_49 V_50 ;
int V_51 = V_48 & V_52 ;
F_13 ( V_51 != V_48 ,
L_8 ,
V_48 ) ;
switch ( V_51 ) {
case V_53 :
case V_54 :
case V_55 :
return false ;
default:
if ( F_14 ( & V_50 , V_47 ) ) {
F_15 ( L_9 ,
V_47 ) ;
return true ;
}
}
return V_50 . V_56 ;
}
bool F_16 ( const char * V_44 , const char * V_23 , int V_57 )
{
unsigned V_33 ;
for ( V_33 = 0 ; V_45 [ V_33 ] . V_46 ; V_33 ++ ) {
if ( ! strcmp ( V_44 , V_45 [ V_33 ] . V_46 ) )
return ! V_45 [ V_33 ] . F_17 ( V_23 ,
V_57 ) ;
}
return false ;
}
bool F_18 ( struct V_1 * V_1 )
{
return V_1 -> V_19 == V_14 ||
V_1 -> V_19 == V_17 ;
}
static int F_19 ( struct V_1 * V_1 , const char * V_58 , char * V_59 )
{
int V_60 = - 1 ;
struct V_49 V_50 ;
if ( ! F_18 ( V_1 ) )
return - 1 ;
if ( F_20 ( & V_50 , V_1 -> V_34 ) )
return - 1 ;
if ( ! V_50 . V_61 )
goto V_62;
V_60 = F_21 ( V_59 ) ;
if ( V_60 < 0 ) {
V_1 -> V_63 = V_64 ;
goto V_62;
}
if ( ! F_16 ( V_50 . V_44 , V_58 , V_60 ) ) {
V_1 -> V_63 = V_65 ;
F_22 ( V_60 ) ;
V_60 = - 1 ;
}
V_62:
free ( V_50 . V_44 ) ;
return V_60 ;
}
int F_23 ( struct V_1 * V_1 , const char * V_58 )
{
char V_59 [] = V_66 ;
int V_60 ;
V_60 = F_19 ( V_1 , V_58 , V_59 ) ;
F_24 ( V_59 ) ;
return V_60 ;
}
int F_25 ( struct V_1 * V_1 , const char * V_58 ,
char * V_47 , T_1 V_28 )
{
char V_59 [] = V_66 ;
int V_60 ;
V_60 = F_19 ( V_1 , V_58 , V_59 ) ;
if ( V_60 < 0 ) {
F_24 ( V_59 ) ;
return - 1 ;
}
strncpy ( V_47 , V_59 , V_28 ) ;
F_22 ( V_60 ) ;
return 0 ;
}
int F_26 ( struct V_49 * V_50 , const char * V_67 ,
bool V_68 , bool V_69 )
{
const char * V_58 = strrchr ( V_67 , '/' ) ;
const char * V_44 = strrchr ( V_67 , '.' ) ;
bool V_70 = false ;
memset ( V_50 , 0x0 , sizeof( * V_50 ) ) ;
V_58 = V_58 ? V_58 + 1 : V_67 ;
if ( V_58 [ 0 ] == '[' ) {
V_70 = true ;
if ( ( strncmp ( V_58 , L_10 , 17 ) == 0 ) ||
( strncmp ( V_58 , L_11 , 22 ) == 0 ) ||
( strncmp ( V_58 , L_12 , 6 ) == 0 ) ||
( strncmp ( V_58 , L_13 , 10 ) == 0 ) ) {
V_50 -> V_56 = false ;
} else
V_50 -> V_56 = true ;
}
if ( ( V_44 == NULL ) || V_70 ) {
if ( V_68 ) {
V_50 -> V_58 = F_27 ( V_58 ) ;
return V_50 -> V_58 ? 0 : - V_71 ;
}
return 0 ;
}
if ( F_11 ( V_44 + 1 ) ) {
V_50 -> V_61 = true ;
V_44 -= 3 ;
}
if ( V_44 > V_58 )
V_50 -> V_56 = ! strncmp ( V_44 , L_14 , 3 ) ;
if ( V_68 ) {
if ( V_50 -> V_56 ) {
if ( F_28 ( & V_50 -> V_58 , L_15 , ( int ) ( V_44 - V_58 ) , V_58 ) == - 1 )
return - V_71 ;
} else {
if ( F_28 ( & V_50 -> V_58 , L_3 , V_58 ) == - 1 )
return - V_71 ;
}
F_29 ( V_50 -> V_58 , '-' , '_' ) ;
}
if ( V_69 && V_50 -> V_61 ) {
V_50 -> V_44 = F_27 ( V_44 + 4 ) ;
if ( ! V_50 -> V_44 ) {
free ( ( void * ) V_50 -> V_58 ) ;
return - V_71 ;
}
}
return 0 ;
}
void F_30 ( struct V_1 * V_1 , struct V_49 * V_50 ,
struct V_72 * V_72 )
{
if ( F_31 ( V_72 ) )
V_1 -> V_19 = V_13 ;
else
V_1 -> V_19 = V_16 ;
if ( V_50 -> V_56 && V_50 -> V_61 )
V_1 -> V_19 ++ ;
F_32 ( V_1 , F_27 ( V_50 -> V_58 ) , true ) ;
}
static void F_33 ( struct V_1 * V_1 )
{
F_34 ( & V_1 -> V_73 . V_74 , & V_75 ) ;
V_76 ++ ;
}
static void F_35 ( struct V_1 * V_1 )
{
F_36 ( & V_1 -> V_73 . V_74 ) ;
F_13 ( V_76 <= 0 ,
L_16 ) ;
V_76 -- ;
}
static int F_37 ( char * V_58 )
{
int V_60 ;
char V_77 [ V_78 ] ;
do {
V_60 = F_38 ( V_58 , V_79 ) ;
if ( V_60 >= 0 )
return V_60 ;
F_39 ( L_17 ,
F_40 ( V_64 , V_77 , sizeof( V_77 ) ) ) ;
if ( ! V_76 || V_64 != V_80 )
break;
F_41 () ;
} while ( 1 );
return - 1 ;
}
static int F_42 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
int V_60 = - V_81 ;
char * V_22 = ( char * ) L_4 ;
char * V_58 = malloc ( V_31 ) ;
if ( ! V_58 )
return - V_71 ;
if ( V_72 )
V_22 = V_72 -> V_22 ;
if ( F_2 ( V_1 , V_1 -> V_82 ,
V_22 , V_58 , V_31 ) )
goto V_62;
if ( ! F_4 ( V_58 ) )
goto V_62;
if ( F_18 ( V_1 ) ) {
char V_83 [ V_84 ] ;
T_1 V_28 = sizeof( V_83 ) ;
if ( F_25 ( V_1 , V_58 , V_83 , V_28 ) < 0 ) {
V_60 = - V_1 -> V_63 ;
goto V_62;
}
strcpy ( V_58 , V_83 ) ;
}
V_60 = F_37 ( V_58 ) ;
if ( F_18 ( V_1 ) )
F_24 ( V_58 ) ;
V_62:
free ( V_58 ) ;
return V_60 ;
}
static int F_43 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
int V_60 = F_42 ( V_1 , V_72 ) ;
if ( V_60 >= 0 ) {
F_33 ( V_1 ) ;
F_44 () ;
}
return V_60 ;
}
static void F_45 ( struct V_1 * V_1 )
{
if ( V_1 -> V_73 . V_60 >= 0 ) {
F_22 ( V_1 -> V_73 . V_60 ) ;
V_1 -> V_73 . V_60 = - 1 ;
V_1 -> V_73 . V_85 = 0 ;
F_35 ( V_1 ) ;
}
}
static void F_46 ( struct V_1 * V_1 )
{
F_45 ( V_1 ) ;
}
static void F_41 ( void )
{
struct V_1 * V_1 ;
V_1 = F_47 ( & V_75 , struct V_1 , V_73 . V_74 ) ;
F_46 ( V_1 ) ;
}
static T_2 F_48 ( void )
{
struct V_86 V_87 ;
T_2 V_88 = 0 ;
if ( F_49 ( V_89 , & V_87 ) == 0 ) {
if ( V_87 . V_90 == V_91 )
V_88 = V_87 . V_90 ;
else
V_88 = V_87 . V_90 / 2 ;
} else {
F_15 ( L_18 ) ;
V_88 = 1 ;
}
return V_88 ;
}
void F_50 ( void )
{
V_92 = 0 ;
}
static bool F_51 ( void )
{
if ( ! V_92 )
V_92 = F_48 () ;
if ( V_92 == V_91 )
return true ;
return V_92 > ( T_2 ) V_76 ;
}
static void F_44 ( void )
{
bool V_93 = F_51 () ;
if ( ! V_93 )
F_41 () ;
}
void F_52 ( struct V_1 * V_1 )
{
F_53 ( & V_94 ) ;
F_46 ( V_1 ) ;
F_54 ( & V_94 ) ;
}
static void F_55 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
enum V_21 V_95 [] = {
V_7 ,
V_12 ,
V_20 ,
} ;
int V_33 = 0 ;
if ( V_1 -> V_73 . V_60 >= 0 )
return;
if ( V_1 -> V_82 != V_20 ) {
V_1 -> V_73 . V_60 = F_43 ( V_1 , V_72 ) ;
goto V_62;
}
do {
V_1 -> V_82 = V_95 [ V_33 ++ ] ;
V_1 -> V_73 . V_60 = F_43 ( V_1 , V_72 ) ;
if ( V_1 -> V_73 . V_60 >= 0 )
goto V_62;
} while ( V_1 -> V_82 != V_20 );
V_62:
if ( V_1 -> V_73 . V_60 >= 0 )
V_1 -> V_73 . V_96 = V_97 ;
else
V_1 -> V_73 . V_96 = V_98 ;
}
int F_56 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
if ( V_1 -> V_73 . V_96 == V_98 )
return - 1 ;
if ( F_53 ( & V_94 ) < 0 )
return - 1 ;
F_55 ( V_1 , V_72 ) ;
if ( V_1 -> V_73 . V_60 < 0 )
F_54 ( & V_94 ) ;
return V_1 -> V_73 . V_60 ;
}
void F_57 ( struct V_1 * V_1 V_99 )
{
F_54 ( & V_94 ) ;
}
bool F_58 ( struct V_1 * V_1 , enum V_100 V_101 )
{
T_3 V_102 = 1 << V_101 ;
if ( V_1 -> V_73 . V_103 & V_102 )
return true ;
V_1 -> V_73 . V_103 |= V_102 ;
return false ;
}
static void
F_59 ( struct V_1 * V_1 )
{
struct V_104 * V_105 = & V_1 -> V_73 . V_106 ;
struct V_107 * V_108 = F_60 ( V_105 ) ;
F_53 ( & V_1 -> V_109 ) ;
while ( V_108 ) {
struct V_110 * V_106 ;
V_106 = F_61 ( V_108 , struct V_110 , V_107 ) ;
V_108 = F_62 ( & V_106 -> V_107 ) ;
F_63 ( & V_106 -> V_107 , V_105 ) ;
free ( V_106 ) ;
}
F_54 ( & V_1 -> V_109 ) ;
}
static struct V_110 * F_64 ( struct V_1 * V_1 , T_4 V_111 )
{
const struct V_104 * V_105 = & V_1 -> V_73 . V_106 ;
struct V_107 * const * V_112 = & V_105 -> V_107 ;
const struct V_107 * V_113 = NULL ;
struct V_110 * V_106 ;
while ( * V_112 != NULL ) {
T_4 V_114 ;
V_113 = * V_112 ;
V_106 = F_61 ( V_113 , struct V_110 , V_107 ) ;
V_114 = V_106 -> V_111 + V_115 ;
if ( V_111 < V_106 -> V_111 )
V_112 = & ( * V_112 ) -> V_116 ;
else if ( V_111 >= V_114 )
V_112 = & ( * V_112 ) -> V_117 ;
else
return V_106 ;
}
return NULL ;
}
static struct V_110 *
F_65 ( struct V_1 * V_1 , struct V_110 * V_118 )
{
struct V_104 * V_105 = & V_1 -> V_73 . V_106 ;
struct V_107 * * V_112 = & V_105 -> V_107 ;
struct V_107 * V_113 = NULL ;
struct V_110 * V_106 ;
T_4 V_111 = V_118 -> V_111 ;
F_53 ( & V_1 -> V_109 ) ;
while ( * V_112 != NULL ) {
T_4 V_114 ;
V_113 = * V_112 ;
V_106 = F_61 ( V_113 , struct V_110 , V_107 ) ;
V_114 = V_106 -> V_111 + V_115 ;
if ( V_111 < V_106 -> V_111 )
V_112 = & ( * V_112 ) -> V_116 ;
else if ( V_111 >= V_114 )
V_112 = & ( * V_112 ) -> V_117 ;
else
goto V_62;
}
F_66 ( & V_118 -> V_107 , V_113 , V_112 ) ;
F_67 ( & V_118 -> V_107 , V_105 ) ;
V_106 = NULL ;
V_62:
F_54 ( & V_1 -> V_109 ) ;
return V_106 ;
}
static T_5
F_68 ( struct V_110 * V_106 , T_4 V_111 ,
T_6 * V_73 , T_4 V_24 )
{
T_4 V_119 = V_111 - V_106 -> V_111 ;
T_4 V_120 = F_69 ( V_106 -> V_24 - V_119 , V_24 ) ;
memcpy ( V_73 , V_106 -> V_73 + V_119 , V_120 ) ;
return V_120 ;
}
static T_5
F_70 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_111 , T_6 * V_73 , T_5 V_24 )
{
struct V_110 * V_106 ;
struct V_110 * V_121 ;
T_5 V_27 ;
do {
T_4 V_119 ;
V_106 = F_71 ( sizeof( * V_106 ) + V_115 ) ;
if ( ! V_106 )
return - V_71 ;
F_53 ( & V_94 ) ;
F_55 ( V_1 , V_72 ) ;
if ( V_1 -> V_73 . V_60 < 0 ) {
V_27 = - V_64 ;
V_1 -> V_73 . V_96 = V_98 ;
break;
}
V_119 = V_111 & V_122 ;
V_27 = F_72 ( V_1 -> V_73 . V_60 , V_106 -> V_73 , V_115 , V_119 ) ;
if ( V_27 <= 0 )
break;
V_106 -> V_111 = V_119 ;
V_106 -> V_24 = V_27 ;
} while ( 0 );
F_54 ( & V_94 ) ;
if ( V_27 > 0 ) {
V_121 = F_65 ( V_1 , V_106 ) ;
if ( V_121 ) {
free ( V_106 ) ;
V_106 = V_121 ;
}
V_27 = F_68 ( V_106 , V_111 , V_73 , V_24 ) ;
}
if ( V_27 <= 0 )
free ( V_106 ) ;
return V_27 ;
}
static T_5 F_73 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_111 , T_6 * V_73 , T_5 V_24 )
{
struct V_110 * V_106 ;
V_106 = F_64 ( V_1 , V_111 ) ;
if ( V_106 )
return F_68 ( V_106 , V_111 , V_73 , V_24 ) ;
else
return F_70 ( V_1 , V_72 , V_111 , V_73 , V_24 ) ;
}
static T_5 F_74 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_111 , T_6 * V_73 , T_5 V_24 )
{
T_5 V_123 = 0 ;
T_6 * V_112 = V_73 ;
do {
T_5 V_27 ;
V_27 = F_73 ( V_1 , V_72 , V_111 , V_112 , V_24 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! V_27 )
break;
F_75 ( V_27 > V_24 ) ;
V_123 += V_27 ;
V_112 += V_27 ;
V_111 += V_27 ;
V_24 -= V_27 ;
} while ( V_24 );
return V_123 ;
}
static int F_76 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
int V_27 = 0 ;
struct V_124 V_125 ;
char V_77 [ V_78 ] ;
if ( V_1 -> V_73 . V_85 )
return 0 ;
if ( V_1 -> V_73 . V_96 == V_98 )
return - 1 ;
F_53 ( & V_94 ) ;
F_55 ( V_1 , V_72 ) ;
if ( V_1 -> V_73 . V_60 < 0 ) {
V_27 = - V_64 ;
V_1 -> V_73 . V_96 = V_98 ;
goto V_62;
}
if ( F_77 ( V_1 -> V_73 . V_60 , & V_125 ) < 0 ) {
V_27 = - V_64 ;
F_15 ( L_19 ,
F_40 ( V_64 , V_77 , sizeof( V_77 ) ) ) ;
V_1 -> V_73 . V_96 = V_98 ;
goto V_62;
}
V_1 -> V_73 . V_85 = V_125 . V_126 ;
V_62:
F_54 ( & V_94 ) ;
return V_27 ;
}
T_7 F_78 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
if ( F_76 ( V_1 , V_72 ) )
return - 1 ;
return V_1 -> V_73 . V_85 ;
}
static T_5 F_79 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_111 , T_6 * V_73 , T_5 V_24 )
{
if ( F_76 ( V_1 , V_72 ) )
return - 1 ;
if ( V_111 > V_1 -> V_73 . V_85 )
return - 1 ;
if ( V_111 + V_24 < V_111 )
return - 1 ;
return F_74 ( V_1 , V_72 , V_111 , V_73 , V_24 ) ;
}
T_5 F_80 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_111 , T_6 * V_73 , T_5 V_24 )
{
if ( V_1 -> V_73 . V_96 == V_98 )
return - 1 ;
return F_79 ( V_1 , V_72 , V_111 , V_73 , V_24 ) ;
}
T_5 F_81 ( struct V_1 * V_1 , struct V_127 * V_127 ,
struct V_72 * V_72 , T_4 V_128 ,
T_6 * V_73 , T_5 V_24 )
{
T_4 V_111 = V_127 -> V_129 ( V_127 , V_128 ) ;
return F_80 ( V_1 , V_72 , V_111 , V_73 , V_24 ) ;
}
struct V_127 * F_82 ( const char * V_58 )
{
struct V_127 * V_127 = NULL ;
struct V_1 * V_1 = F_83 ( V_58 ) ;
if ( V_1 )
V_127 = F_84 ( 0 , V_1 , V_130 ) ;
return V_127 ;
}
struct V_1 * F_85 ( struct V_72 * V_72 , const char * V_58 ,
const char * V_131 , int V_132 )
{
struct V_1 * V_1 = F_86 ( V_72 , V_58 ) ;
if ( V_1 != NULL ) {
F_32 ( V_1 , V_131 , false ) ;
V_1 -> V_133 = V_132 ;
}
return V_1 ;
}
static struct V_1 * F_87 ( struct V_104 * V_105 ,
struct V_1 * V_1 , const char * V_58 )
{
struct V_107 * * V_112 = & V_105 -> V_107 ;
struct V_107 * V_113 = NULL ;
if ( ! V_58 )
V_58 = V_1 -> V_34 ;
while ( * V_112 ) {
struct V_1 * V_134 = F_61 ( * V_112 , struct V_1 , V_107 ) ;
int V_135 = strcmp ( V_58 , V_134 -> V_34 ) ;
V_113 = * V_112 ;
if ( V_135 == 0 ) {
if ( ! V_1 || ( V_1 == V_134 ) )
return V_134 ;
V_135 = strcmp ( V_1 -> V_131 , V_134 -> V_131 ) ;
if ( V_135 == 0 ) {
F_15 ( L_20 , V_58 ) ;
return NULL ;
}
}
if ( V_135 < 0 )
V_112 = & V_113 -> V_116 ;
else
V_112 = & V_113 -> V_117 ;
}
if ( V_1 ) {
F_66 ( & V_1 -> V_107 , V_113 , V_112 ) ;
F_67 ( & V_1 -> V_107 , V_105 ) ;
V_1 -> V_105 = V_105 ;
}
return NULL ;
}
static inline struct V_1 * F_88 ( struct V_104 * V_105 ,
const char * V_58 )
{
return F_87 ( V_105 , NULL , V_58 ) ;
}
void F_89 ( struct V_1 * V_1 , const char * V_58 , bool V_136 )
{
struct V_104 * V_105 = V_1 -> V_105 ;
if ( V_58 == NULL )
return;
if ( V_1 -> V_137 )
free ( ( char * ) V_1 -> V_34 ) ;
if ( V_105 ) {
F_63 ( & V_1 -> V_107 , V_105 ) ;
F_90 ( & V_1 -> V_107 ) ;
V_1 -> V_105 = NULL ;
}
V_1 -> V_34 = V_58 ;
V_1 -> V_37 = strlen ( V_58 ) ;
V_1 -> V_137 = V_136 ;
if ( V_105 )
F_87 ( V_105 , V_1 , NULL ) ;
}
void F_32 ( struct V_1 * V_1 , const char * V_58 , bool V_136 )
{
if ( V_58 == NULL )
return;
if ( V_1 -> V_138 )
free ( ( char * ) V_1 -> V_131 ) ;
V_1 -> V_131 = V_58 ;
V_1 -> V_139 = strlen ( V_58 ) ;
V_1 -> V_138 = V_136 ;
}
static void F_91 ( struct V_1 * V_1 )
{
char * V_140 , * V_141 = F_27 ( V_1 -> V_34 ) ;
if ( ! V_141 )
return;
V_140 = F_27 ( F_92 ( V_141 ) ) ;
free ( V_141 ) ;
if ( ! V_140 )
return;
F_32 ( V_1 , V_140 , true ) ;
}
int F_93 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_21 ) ;
if ( V_142 > 0 )
return V_1 -> V_37 ;
return V_1 -> V_139 ;
}
bool F_94 ( const struct V_1 * V_1 , enum V_143 type )
{
return V_1 -> V_144 & ( 1 << type ) ;
}
bool F_95 ( const struct V_1 * V_1 , enum V_143 type )
{
return V_1 -> V_145 & ( 1 << type ) ;
}
void F_96 ( struct V_1 * V_1 , enum V_143 type )
{
V_1 -> V_145 |= ( 1 << type ) ;
}
struct V_1 * F_83 ( const char * V_58 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_58 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_33 ;
strcpy ( V_1 -> V_58 , V_58 ) ;
F_89 ( V_1 , V_1 -> V_58 , false ) ;
F_32 ( V_1 , V_1 -> V_58 , false ) ;
for ( V_33 = 0 ; V_33 < V_146 ; ++ V_33 )
V_1 -> V_147 [ V_33 ] = V_1 -> V_148 [ V_33 ] = V_149 ;
V_1 -> V_73 . V_106 = V_149 ;
V_1 -> V_73 . V_60 = - 1 ;
V_1 -> V_73 . V_96 = V_150 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_82 = V_20 ;
V_1 -> V_151 = ( sizeof( void * ) == 8 ) ;
V_1 -> V_144 = 0 ;
V_1 -> V_152 = 0 ;
V_1 -> V_145 = 0 ;
V_1 -> V_38 = 0 ;
V_1 -> V_153 = 1 ;
V_1 -> V_154 = 1 ;
V_1 -> V_133 = V_155 ;
V_1 -> V_156 = V_157 ;
F_90 ( & V_1 -> V_107 ) ;
V_1 -> V_105 = NULL ;
F_97 ( & V_1 -> V_158 ) ;
F_97 ( & V_1 -> V_73 . V_74 ) ;
F_98 ( & V_1 -> V_109 , NULL ) ;
F_99 ( & V_1 -> V_159 , 1 ) ;
}
return V_1 ;
}
void F_100 ( struct V_1 * V_1 )
{
int V_33 ;
if ( ! F_101 ( & V_1 -> V_107 ) )
F_15 ( L_22 ,
V_1 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < V_146 ; ++ V_33 )
F_102 ( & V_1 -> V_147 [ V_33 ] ) ;
if ( V_1 -> V_138 ) {
F_103 ( ( char * * ) & V_1 -> V_131 ) ;
V_1 -> V_138 = false ;
}
if ( V_1 -> V_137 ) {
F_103 ( ( char * * ) & V_1 -> V_34 ) ;
V_1 -> V_137 = false ;
}
F_52 ( V_1 ) ;
F_104 ( V_1 -> V_160 ) ;
F_59 ( V_1 ) ;
F_105 ( V_1 ) ;
F_103 ( & V_1 -> V_161 ) ;
F_106 ( & V_1 -> V_109 ) ;
free ( V_1 ) ;
}
struct V_1 * F_107 ( struct V_1 * V_1 )
{
if ( V_1 )
F_108 ( & V_1 -> V_159 ) ;
return V_1 ;
}
void F_109 ( struct V_1 * V_1 )
{
if ( V_1 && F_110 ( & V_1 -> V_159 ) )
F_100 ( V_1 ) ;
}
void F_111 ( struct V_1 * V_1 , void * V_39 )
{
memcpy ( V_1 -> V_39 , V_39 , sizeof( V_1 -> V_39 ) ) ;
V_1 -> V_38 = 1 ;
}
bool F_112 ( const struct V_1 * V_1 , T_6 * V_39 )
{
return memcmp ( V_1 -> V_39 , V_39 , sizeof( V_1 -> V_39 ) ) == 0 ;
}
void F_113 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
char V_67 [ V_31 ] ;
if ( F_114 ( V_72 ) )
return;
sprintf ( V_67 , L_23 , V_72 -> V_22 ) ;
if ( F_115 ( V_67 , V_1 -> V_39 ,
sizeof( V_1 -> V_39 ) ) == 0 )
V_1 -> V_38 = true ;
}
int F_116 ( struct V_1 * V_1 ,
const char * V_22 )
{
char V_23 [ V_31 ] ;
const char * V_58 = V_1 -> V_131 + 1 ;
snprintf ( V_23 , sizeof( V_23 ) ,
L_24 ,
V_22 , ( int ) strlen ( V_58 ) - 1 , V_58 ) ;
if ( F_115 ( V_23 , V_1 -> V_39 ,
sizeof( V_1 -> V_39 ) ) == 0 )
V_1 -> V_38 = true ;
return 0 ;
}
bool F_117 ( struct V_162 * V_163 , bool V_164 )
{
bool V_165 = false ;
struct V_1 * V_166 ;
F_118 (pos, head, node) {
if ( V_164 && ! V_166 -> V_167 && ! F_119 ( V_166 ) )
continue;
if ( V_166 -> V_38 ) {
V_165 = true ;
continue;
}
if ( F_120 ( V_166 -> V_34 , V_166 -> V_39 ,
sizeof( V_166 -> V_39 ) ) > 0 ) {
V_165 = true ;
V_166 -> V_38 = true ;
}
}
return V_165 ;
}
void F_121 ( struct V_168 * V_168 , struct V_1 * V_1 )
{
F_34 ( & V_1 -> V_158 , & V_168 -> V_163 ) ;
F_87 ( & V_168 -> V_105 , V_1 , NULL ) ;
F_107 ( V_1 ) ;
}
void F_122 ( struct V_168 * V_168 , struct V_1 * V_1 )
{
F_123 ( & V_168 -> V_109 ) ;
F_121 ( V_168 , V_1 ) ;
F_124 ( & V_168 -> V_109 ) ;
}
struct V_1 * F_125 ( struct V_168 * V_168 , const char * V_58 , bool V_169 )
{
struct V_1 * V_166 ;
if ( V_169 ) {
F_118 (pos, &dsos->head, node)
if ( strcmp ( V_166 -> V_131 , V_58 ) == 0 )
return V_166 ;
return NULL ;
}
return F_88 ( & V_168 -> V_105 , V_58 ) ;
}
struct V_1 * F_126 ( struct V_168 * V_168 , const char * V_58 , bool V_169 )
{
struct V_1 * V_1 ;
F_127 ( & V_168 -> V_109 ) ;
V_1 = F_125 ( V_168 , V_58 , V_169 ) ;
F_124 ( & V_168 -> V_109 ) ;
return V_1 ;
}
struct V_1 * F_128 ( struct V_168 * V_168 , const char * V_58 )
{
struct V_1 * V_1 = F_83 ( V_58 ) ;
if ( V_1 != NULL ) {
F_121 ( V_168 , V_1 ) ;
F_91 ( V_1 ) ;
F_109 ( V_1 ) ;
}
return V_1 ;
}
struct V_1 * F_129 ( struct V_168 * V_168 , const char * V_58 )
{
struct V_1 * V_1 = F_125 ( V_168 , V_58 , false ) ;
return V_1 ? V_1 : F_128 ( V_168 , V_58 ) ;
}
struct V_1 * F_130 ( struct V_168 * V_168 , const char * V_58 )
{
struct V_1 * V_1 ;
F_123 ( & V_168 -> V_109 ) ;
V_1 = F_107 ( F_129 ( V_168 , V_58 ) ) ;
F_124 ( & V_168 -> V_109 ) ;
return V_1 ;
}
T_1 F_131 ( struct V_162 * V_163 , T_8 * V_170 ,
bool (F_132)( struct V_1 * V_1 , int V_171 ) , int V_171 )
{
struct V_1 * V_166 ;
T_1 V_27 = 0 ;
F_118 (pos, head, node) {
if ( F_132 && F_132 ( V_166 , V_171 ) )
continue;
V_27 += F_133 ( V_166 , V_170 ) ;
V_27 += fprintf ( V_170 , L_25 , V_166 -> V_34 ) ;
}
return V_27 ;
}
T_1 F_134 ( struct V_162 * V_163 , T_8 * V_170 )
{
struct V_1 * V_166 ;
T_1 V_27 = 0 ;
F_118 (pos, head, node) {
int V_33 ;
for ( V_33 = 0 ; V_33 < V_146 ; ++ V_33 )
V_27 += F_135 ( V_166 , V_33 , V_170 ) ;
}
return V_27 ;
}
T_1 F_133 ( struct V_1 * V_1 , T_8 * V_170 )
{
char V_172 [ V_26 ] ;
F_9 ( V_1 -> V_39 , sizeof( V_1 -> V_39 ) , V_172 ) ;
return fprintf ( V_170 , L_3 , V_172 ) ;
}
T_1 F_135 ( struct V_1 * V_1 , enum V_143 type , T_8 * V_170 )
{
struct V_107 * V_173 ;
T_1 V_27 = fprintf ( V_170 , L_26 , V_1 -> V_131 ) ;
if ( V_1 -> V_131 != V_1 -> V_34 )
V_27 += fprintf ( V_170 , L_27 , V_1 -> V_34 ) ;
V_27 += fprintf ( V_170 , L_28 , V_174 [ type ] ,
F_94 ( V_1 , type ) ? L_4 : L_29 ) ;
V_27 += F_133 ( V_1 , V_170 ) ;
V_27 += fprintf ( V_170 , L_30 ) ;
for ( V_173 = F_60 ( & V_1 -> V_147 [ type ] ) ; V_173 ; V_173 = F_62 ( V_173 ) ) {
struct V_175 * V_166 = F_61 ( V_173 , struct V_175 , V_107 ) ;
V_27 += F_136 ( V_166 , V_170 ) ;
}
return V_27 ;
}
enum V_132 F_137 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
int V_60 ;
enum V_132 type = V_176 ;
V_60 = F_56 ( V_1 , V_72 ) ;
if ( V_60 >= 0 ) {
type = F_138 ( V_60 ) ;
F_57 ( V_1 ) ;
}
return type ;
}
int F_139 ( struct V_1 * V_1 , char * V_177 , T_1 V_178 )
{
int V_179 , V_180 = V_1 -> V_63 ;
static const char * V_181 [] = {
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
} ;
F_75 ( V_178 == 0 ) ;
if ( V_180 >= 0 ) {
const char * V_182 = F_40 ( V_180 , V_177 , V_178 ) ;
if ( V_182 != V_177 )
F_8 ( V_177 , V_178 , L_3 , V_182 ) ;
return 0 ;
}
if ( V_180 < V_183 || V_180 >= V_184 )
return - 1 ;
V_179 = V_180 - V_183 ;
F_8 ( V_177 , V_178 , L_3 , V_181 [ V_179 ] ) ;
return 0 ;
}
