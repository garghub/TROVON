char F_1 ( const struct V_1 * V_1 )
{
static const char V_2 [] = {
[ V_3 ] = 'k' ,
[ V_4 ] = 'v' ,
[ V_5 ] = 'j' ,
[ V_6 ] = 'l' ,
[ V_7 ] = 'B' ,
[ V_8 ] = 'D' ,
[ V_9 ] = 'f' ,
[ V_10 ] = 'u' ,
[ V_11 ] = 'o' ,
[ V_12 ] = 'b' ,
[ V_13 ] = 'd' ,
[ V_14 ] = 'K' ,
[ V_15 ] = 'm' ,
[ V_16 ] = 'g' ,
[ V_17 ] = 'G' ,
[ V_18 ] = 'M' ,
[ V_19 ] = 'V' ,
} ;
if ( V_1 == NULL || V_1 -> V_20 == V_21 )
return '!' ;
return V_2 [ V_1 -> V_20 ] ;
}
int F_2 ( const struct V_1 * V_1 ,
enum V_22 type ,
char * V_23 , char * V_24 , T_1 V_25 )
{
char V_26 [ V_27 ] ;
int V_28 = 0 ;
T_1 V_29 ;
switch ( type ) {
case V_6 :
{
const char * V_30 ;
char V_31 [ V_32 ] ;
char V_33 [ V_32 ] ;
unsigned int V_34 ;
V_29 = F_3 ( V_24 , V_25 , V_1 -> V_35 ) ;
V_30 = V_24 + V_29 ;
while ( V_30 != V_24 && * V_30 != '/' )
V_30 -- ;
strncpy ( V_31 , V_24 , V_30 - V_24 ) ;
V_31 [ V_30 - V_24 ] = '\0' ;
if ( ! F_4 ( V_24 ) ) {
V_28 = - 1 ;
break;
}
V_28 = F_5 ( V_24 , V_33 , V_32 ) ;
if ( V_28 )
break;
V_28 = - 1 ;
for ( V_34 = 0 ; V_34 < F_6 ( V_36 ) ; V_34 ++ ) {
snprintf ( V_24 , V_25 ,
V_36 [ V_34 ] , V_31 , V_33 ) ;
if ( F_4 ( V_24 ) ) {
V_28 = 0 ;
break;
}
}
break;
}
case V_7 :
if ( F_7 ( V_1 , V_24 , V_25 , false ) == NULL )
V_28 = - 1 ;
break;
case V_8 :
if ( F_7 ( V_1 , V_24 , V_25 , true ) == NULL )
V_28 = - 1 ;
break;
case V_9 :
V_29 = F_3 ( V_24 , V_25 , L_1 ) ;
snprintf ( V_24 + V_29 , V_25 - V_29 , L_2 , V_1 -> V_35 ) ;
break;
case V_10 :
V_29 = F_3 ( V_24 , V_25 , L_1 ) ;
snprintf ( V_24 + V_29 , V_25 - V_29 , L_3 , V_1 -> V_35 ) ;
break;
case V_11 :
{
const char * V_30 ;
T_1 V_37 ;
V_30 = V_1 -> V_35 + V_1 -> V_38 ;
while ( V_30 != V_1 -> V_35 && * V_30 != '/' )
V_30 -- ;
V_29 = F_3 ( V_24 , V_25 , L_4 ) ;
V_37 = V_30 - V_1 -> V_35 + 2 ;
if ( V_37 > ( V_25 - V_29 ) ) {
V_28 = - 1 ;
break;
}
V_29 += F_8 ( V_24 + V_29 , V_37 , L_3 , V_1 -> V_35 ) ;
V_29 += F_8 ( V_24 + V_29 , V_25 - V_29 , L_5 ,
V_30 ) ;
break;
}
case V_12 :
if ( ! V_1 -> V_39 ) {
V_28 = - 1 ;
break;
}
F_9 ( V_1 -> V_40 ,
sizeof( V_1 -> V_40 ) ,
V_26 ) ;
V_29 = F_3 ( V_24 , V_25 , L_6 ) ;
snprintf ( V_24 + V_29 , V_25 - V_29 , L_7 ,
V_26 , V_26 + 2 ) ;
break;
case V_4 :
case V_19 :
case V_13 :
F_3 ( V_24 , V_25 , V_1 -> V_35 ) ;
break;
case V_17 :
case V_18 :
F_10 ( V_24 , V_25 , V_41 . V_42 ,
V_23 , V_1 -> V_35 ) ;
break;
case V_14 :
case V_15 :
F_3 ( V_24 , V_25 , V_1 -> V_35 ) ;
break;
case V_43 :
case V_44 :
snprintf ( V_24 , V_25 , L_3 , V_1 -> V_35 ) ;
break;
default:
case V_3 :
case V_16 :
case V_5 :
case V_21 :
V_28 = - 1 ;
break;
}
return V_28 ;
}
bool F_11 ( const char * V_45 )
{
unsigned V_34 ;
for ( V_34 = 0 ; V_46 [ V_34 ] . V_47 ; V_34 ++ ) {
if ( ! strcmp ( V_45 , V_46 [ V_34 ] . V_47 ) )
return true ;
}
return false ;
}
bool F_12 ( const char * V_48 , int V_49 )
{
struct V_50 V_51 ;
int V_52 = V_49 & V_53 ;
F_13 ( V_52 != V_49 ,
L_8 ,
V_49 ) ;
switch ( V_52 ) {
case V_54 :
case V_55 :
case V_56 :
return false ;
default:
if ( F_14 ( & V_51 , V_48 ) ) {
F_15 ( L_9 ,
V_48 ) ;
return true ;
}
}
return V_51 . V_57 ;
}
bool F_16 ( const char * V_45 , const char * V_24 , int V_58 )
{
unsigned V_34 ;
for ( V_34 = 0 ; V_46 [ V_34 ] . V_47 ; V_34 ++ ) {
if ( ! strcmp ( V_45 , V_46 [ V_34 ] . V_47 ) )
return ! V_46 [ V_34 ] . F_17 ( V_24 ,
V_58 ) ;
}
return false ;
}
bool F_18 ( struct V_1 * V_1 )
{
return V_1 -> V_20 == V_15 ||
V_1 -> V_20 == V_18 ;
}
static int F_19 ( struct V_1 * V_1 , const char * V_59 , char * V_60 )
{
int V_61 = - 1 ;
struct V_50 V_51 ;
if ( ! F_18 ( V_1 ) )
return - 1 ;
if ( F_20 ( & V_51 , V_1 -> V_35 ) )
return - 1 ;
if ( ! V_51 . V_62 )
goto V_63;
V_61 = F_21 ( V_60 ) ;
if ( V_61 < 0 ) {
V_1 -> V_64 = V_65 ;
goto V_63;
}
if ( ! F_16 ( V_51 . V_45 , V_59 , V_61 ) ) {
V_1 -> V_64 = V_66 ;
F_22 ( V_61 ) ;
V_61 = - 1 ;
}
V_63:
free ( V_51 . V_45 ) ;
return V_61 ;
}
int F_23 ( struct V_1 * V_1 , const char * V_59 )
{
char V_60 [] = V_67 ;
int V_61 ;
V_61 = F_19 ( V_1 , V_59 , V_60 ) ;
F_24 ( V_60 ) ;
return V_61 ;
}
int F_25 ( struct V_1 * V_1 , const char * V_59 ,
char * V_48 , T_1 V_29 )
{
char V_60 [] = V_67 ;
int V_61 ;
V_61 = F_19 ( V_1 , V_59 , V_60 ) ;
if ( V_61 < 0 ) {
F_24 ( V_60 ) ;
return - 1 ;
}
strncpy ( V_48 , V_60 , V_29 ) ;
F_22 ( V_61 ) ;
return 0 ;
}
int F_26 ( struct V_50 * V_51 , const char * V_68 ,
bool V_69 , bool V_70 )
{
const char * V_59 = strrchr ( V_68 , '/' ) ;
const char * V_45 = strrchr ( V_68 , '.' ) ;
bool V_71 = false ;
memset ( V_51 , 0x0 , sizeof( * V_51 ) ) ;
V_59 = V_59 ? V_59 + 1 : V_68 ;
if ( V_59 [ 0 ] == '[' ) {
V_71 = true ;
if ( ( strncmp ( V_59 , L_10 , 17 ) == 0 ) ||
( strncmp ( V_59 , L_11 , 22 ) == 0 ) ||
( strncmp ( V_59 , L_12 , 6 ) == 0 ) ||
( strncmp ( V_59 , L_13 , 10 ) == 0 ) ) {
V_51 -> V_57 = false ;
} else
V_51 -> V_57 = true ;
}
if ( ( V_45 == NULL ) || V_71 ) {
if ( V_69 ) {
V_51 -> V_59 = F_27 ( V_59 ) ;
return V_51 -> V_59 ? 0 : - V_72 ;
}
return 0 ;
}
if ( F_11 ( V_45 + 1 ) ) {
V_51 -> V_62 = true ;
V_45 -= 3 ;
}
if ( V_45 > V_59 )
V_51 -> V_57 = ! strncmp ( V_45 , L_14 , 3 ) ;
if ( V_69 ) {
if ( V_51 -> V_57 ) {
if ( F_28 ( & V_51 -> V_59 , L_15 , ( int ) ( V_45 - V_59 ) , V_59 ) == - 1 )
return - V_72 ;
} else {
if ( F_28 ( & V_51 -> V_59 , L_3 , V_59 ) == - 1 )
return - V_72 ;
}
F_29 ( V_51 -> V_59 , '-' , '_' ) ;
}
if ( V_70 && V_51 -> V_62 ) {
V_51 -> V_45 = F_27 ( V_45 + 4 ) ;
if ( ! V_51 -> V_45 ) {
free ( ( void * ) V_51 -> V_59 ) ;
return - V_72 ;
}
}
return 0 ;
}
void F_30 ( struct V_1 * V_1 , struct V_50 * V_51 ,
struct V_73 * V_73 )
{
if ( F_31 ( V_73 ) )
V_1 -> V_20 = V_14 ;
else
V_1 -> V_20 = V_17 ;
if ( V_51 -> V_57 && V_51 -> V_62 )
V_1 -> V_20 ++ ;
F_32 ( V_1 , F_27 ( V_51 -> V_59 ) , true ) ;
}
static void F_33 ( struct V_1 * V_1 )
{
F_34 ( & V_1 -> V_74 . V_75 , & V_76 ) ;
V_77 ++ ;
}
static void F_35 ( struct V_1 * V_1 )
{
F_36 ( & V_1 -> V_74 . V_75 ) ;
F_13 ( V_77 <= 0 ,
L_16 ) ;
V_77 -- ;
}
static int F_37 ( char * V_59 )
{
int V_61 ;
char V_78 [ V_79 ] ;
do {
V_61 = F_38 ( V_59 , V_80 ) ;
if ( V_61 >= 0 )
return V_61 ;
F_39 ( L_17 ,
F_40 ( V_65 , V_78 , sizeof( V_78 ) ) ) ;
if ( ! V_77 || V_65 != V_81 )
break;
F_41 () ;
} while ( 1 );
return - 1 ;
}
static int F_42 ( struct V_1 * V_1 , struct V_73 * V_73 )
{
int V_61 = - V_82 ;
char * V_23 = ( char * ) L_4 ;
char * V_59 = malloc ( V_32 ) ;
if ( ! V_59 )
return - V_72 ;
if ( V_73 )
V_23 = V_73 -> V_23 ;
if ( F_2 ( V_1 , V_1 -> V_83 ,
V_23 , V_59 , V_32 ) )
goto V_63;
if ( ! F_4 ( V_59 ) )
goto V_63;
if ( F_18 ( V_1 ) ) {
char V_84 [ V_85 ] ;
T_1 V_29 = sizeof( V_84 ) ;
if ( F_25 ( V_1 , V_59 , V_84 , V_29 ) < 0 ) {
V_61 = - V_1 -> V_64 ;
goto V_63;
}
strcpy ( V_59 , V_84 ) ;
}
V_61 = F_37 ( V_59 ) ;
if ( F_18 ( V_1 ) )
F_24 ( V_59 ) ;
V_63:
free ( V_59 ) ;
return V_61 ;
}
static int F_43 ( struct V_1 * V_1 , struct V_73 * V_73 )
{
int V_61 ;
struct V_86 V_87 ;
if ( V_1 -> V_83 != V_7 )
F_44 ( V_1 -> V_88 , & V_87 ) ;
V_61 = F_42 ( V_1 , V_73 ) ;
if ( V_1 -> V_83 != V_7 )
F_45 ( & V_87 ) ;
if ( V_61 >= 0 ) {
F_33 ( V_1 ) ;
F_46 () ;
}
return V_61 ;
}
static void F_47 ( struct V_1 * V_1 )
{
if ( V_1 -> V_74 . V_61 >= 0 ) {
F_22 ( V_1 -> V_74 . V_61 ) ;
V_1 -> V_74 . V_61 = - 1 ;
V_1 -> V_74 . V_89 = 0 ;
F_35 ( V_1 ) ;
}
}
static void F_48 ( struct V_1 * V_1 )
{
F_47 ( V_1 ) ;
}
static void F_41 ( void )
{
struct V_1 * V_1 ;
V_1 = F_49 ( & V_76 , struct V_1 , V_74 . V_75 ) ;
F_48 ( V_1 ) ;
}
static T_2 F_50 ( void )
{
struct V_90 V_91 ;
T_2 V_92 = 0 ;
if ( F_51 ( V_93 , & V_91 ) == 0 ) {
if ( V_91 . V_94 == V_95 )
V_92 = V_91 . V_94 ;
else
V_92 = V_91 . V_94 / 2 ;
} else {
F_15 ( L_18 ) ;
V_92 = 1 ;
}
return V_92 ;
}
void F_52 ( void )
{
V_96 = 0 ;
}
static bool F_53 ( void )
{
if ( ! V_96 )
V_96 = F_50 () ;
if ( V_96 == V_95 )
return true ;
return V_96 > ( T_2 ) V_77 ;
}
static void F_46 ( void )
{
bool V_97 = F_53 () ;
if ( ! V_97 )
F_41 () ;
}
void F_54 ( struct V_1 * V_1 )
{
F_55 ( & V_98 ) ;
F_48 ( V_1 ) ;
F_56 ( & V_98 ) ;
}
static void F_57 ( struct V_1 * V_1 , struct V_73 * V_73 )
{
enum V_22 V_99 [] = {
V_7 ,
V_13 ,
V_21 ,
} ;
int V_34 = 0 ;
if ( V_1 -> V_74 . V_61 >= 0 )
return;
if ( V_1 -> V_83 != V_21 ) {
V_1 -> V_74 . V_61 = F_43 ( V_1 , V_73 ) ;
goto V_63;
}
do {
V_1 -> V_83 = V_99 [ V_34 ++ ] ;
V_1 -> V_74 . V_61 = F_43 ( V_1 , V_73 ) ;
if ( V_1 -> V_74 . V_61 >= 0 )
goto V_63;
} while ( V_1 -> V_83 != V_21 );
V_63:
if ( V_1 -> V_74 . V_61 >= 0 )
V_1 -> V_74 . V_100 = V_101 ;
else
V_1 -> V_74 . V_100 = V_102 ;
}
int F_58 ( struct V_1 * V_1 , struct V_73 * V_73 )
{
if ( V_1 -> V_74 . V_100 == V_102 )
return - 1 ;
if ( F_55 ( & V_98 ) < 0 )
return - 1 ;
F_57 ( V_1 , V_73 ) ;
if ( V_1 -> V_74 . V_61 < 0 )
F_56 ( & V_98 ) ;
return V_1 -> V_74 . V_61 ;
}
void F_59 ( struct V_1 * V_1 V_103 )
{
F_56 ( & V_98 ) ;
}
bool F_60 ( struct V_1 * V_1 , enum V_104 V_105 )
{
T_3 V_106 = 1 << V_105 ;
if ( V_1 -> V_74 . V_107 & V_106 )
return true ;
V_1 -> V_74 . V_107 |= V_106 ;
return false ;
}
static void
F_61 ( struct V_1 * V_1 )
{
struct V_108 * V_109 = & V_1 -> V_74 . V_110 ;
struct V_111 * V_112 = F_62 ( V_109 ) ;
F_55 ( & V_1 -> V_113 ) ;
while ( V_112 ) {
struct V_114 * V_110 ;
V_110 = F_63 ( V_112 , struct V_114 , V_111 ) ;
V_112 = F_64 ( & V_110 -> V_111 ) ;
F_65 ( & V_110 -> V_111 , V_109 ) ;
free ( V_110 ) ;
}
F_56 ( & V_1 -> V_113 ) ;
}
static struct V_114 * F_66 ( struct V_1 * V_1 , T_4 V_115 )
{
const struct V_108 * V_109 = & V_1 -> V_74 . V_110 ;
struct V_111 * const * V_116 = & V_109 -> V_111 ;
const struct V_111 * V_117 = NULL ;
struct V_114 * V_110 ;
while ( * V_116 != NULL ) {
T_4 V_118 ;
V_117 = * V_116 ;
V_110 = F_63 ( V_117 , struct V_114 , V_111 ) ;
V_118 = V_110 -> V_115 + V_119 ;
if ( V_115 < V_110 -> V_115 )
V_116 = & ( * V_116 ) -> V_120 ;
else if ( V_115 >= V_118 )
V_116 = & ( * V_116 ) -> V_121 ;
else
return V_110 ;
}
return NULL ;
}
static struct V_114 *
F_67 ( struct V_1 * V_1 , struct V_114 * V_122 )
{
struct V_108 * V_109 = & V_1 -> V_74 . V_110 ;
struct V_111 * * V_116 = & V_109 -> V_111 ;
struct V_111 * V_117 = NULL ;
struct V_114 * V_110 ;
T_4 V_115 = V_122 -> V_115 ;
F_55 ( & V_1 -> V_113 ) ;
while ( * V_116 != NULL ) {
T_4 V_118 ;
V_117 = * V_116 ;
V_110 = F_63 ( V_117 , struct V_114 , V_111 ) ;
V_118 = V_110 -> V_115 + V_119 ;
if ( V_115 < V_110 -> V_115 )
V_116 = & ( * V_116 ) -> V_120 ;
else if ( V_115 >= V_118 )
V_116 = & ( * V_116 ) -> V_121 ;
else
goto V_63;
}
F_68 ( & V_122 -> V_111 , V_117 , V_116 ) ;
F_69 ( & V_122 -> V_111 , V_109 ) ;
V_110 = NULL ;
V_63:
F_56 ( & V_1 -> V_113 ) ;
return V_110 ;
}
static T_5
F_70 ( struct V_114 * V_110 , T_4 V_115 ,
T_6 * V_74 , T_4 V_25 )
{
T_4 V_123 = V_115 - V_110 -> V_115 ;
T_4 V_124 = F_71 ( V_110 -> V_25 - V_123 , V_25 ) ;
memcpy ( V_74 , V_110 -> V_74 + V_123 , V_124 ) ;
return V_124 ;
}
static T_5
F_72 ( struct V_1 * V_1 , struct V_73 * V_73 ,
T_4 V_115 , T_6 * V_74 , T_5 V_25 )
{
struct V_114 * V_110 ;
struct V_114 * V_125 ;
T_5 V_28 ;
do {
T_4 V_123 ;
V_110 = F_73 ( sizeof( * V_110 ) + V_119 ) ;
if ( ! V_110 )
return - V_72 ;
F_55 ( & V_98 ) ;
F_57 ( V_1 , V_73 ) ;
if ( V_1 -> V_74 . V_61 < 0 ) {
V_28 = - V_65 ;
V_1 -> V_74 . V_100 = V_102 ;
break;
}
V_123 = V_115 & V_126 ;
V_28 = F_74 ( V_1 -> V_74 . V_61 , V_110 -> V_74 , V_119 , V_123 ) ;
if ( V_28 <= 0 )
break;
V_110 -> V_115 = V_123 ;
V_110 -> V_25 = V_28 ;
} while ( 0 );
F_56 ( & V_98 ) ;
if ( V_28 > 0 ) {
V_125 = F_67 ( V_1 , V_110 ) ;
if ( V_125 ) {
free ( V_110 ) ;
V_110 = V_125 ;
}
V_28 = F_70 ( V_110 , V_115 , V_74 , V_25 ) ;
}
if ( V_28 <= 0 )
free ( V_110 ) ;
return V_28 ;
}
static T_5 F_75 ( struct V_1 * V_1 , struct V_73 * V_73 ,
T_4 V_115 , T_6 * V_74 , T_5 V_25 )
{
struct V_114 * V_110 ;
V_110 = F_66 ( V_1 , V_115 ) ;
if ( V_110 )
return F_70 ( V_110 , V_115 , V_74 , V_25 ) ;
else
return F_72 ( V_1 , V_73 , V_115 , V_74 , V_25 ) ;
}
static T_5 F_76 ( struct V_1 * V_1 , struct V_73 * V_73 ,
T_4 V_115 , T_6 * V_74 , T_5 V_25 )
{
T_5 V_127 = 0 ;
T_6 * V_116 = V_74 ;
do {
T_5 V_28 ;
V_28 = F_75 ( V_1 , V_73 , V_115 , V_116 , V_25 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ! V_28 )
break;
F_77 ( V_28 > V_25 ) ;
V_127 += V_28 ;
V_116 += V_28 ;
V_115 += V_28 ;
V_25 -= V_28 ;
} while ( V_25 );
return V_127 ;
}
static int F_78 ( struct V_1 * V_1 , struct V_73 * V_73 )
{
int V_28 = 0 ;
struct V_128 V_129 ;
char V_78 [ V_79 ] ;
if ( V_1 -> V_74 . V_89 )
return 0 ;
if ( V_1 -> V_74 . V_100 == V_102 )
return - 1 ;
F_55 ( & V_98 ) ;
F_57 ( V_1 , V_73 ) ;
if ( V_1 -> V_74 . V_61 < 0 ) {
V_28 = - V_65 ;
V_1 -> V_74 . V_100 = V_102 ;
goto V_63;
}
if ( F_79 ( V_1 -> V_74 . V_61 , & V_129 ) < 0 ) {
V_28 = - V_65 ;
F_15 ( L_19 ,
F_40 ( V_65 , V_78 , sizeof( V_78 ) ) ) ;
V_1 -> V_74 . V_100 = V_102 ;
goto V_63;
}
V_1 -> V_74 . V_89 = V_129 . V_130 ;
V_63:
F_56 ( & V_98 ) ;
return V_28 ;
}
T_7 F_80 ( struct V_1 * V_1 , struct V_73 * V_73 )
{
if ( F_78 ( V_1 , V_73 ) )
return - 1 ;
return V_1 -> V_74 . V_89 ;
}
static T_5 F_81 ( struct V_1 * V_1 , struct V_73 * V_73 ,
T_4 V_115 , T_6 * V_74 , T_5 V_25 )
{
if ( F_78 ( V_1 , V_73 ) )
return - 1 ;
if ( V_115 > V_1 -> V_74 . V_89 )
return - 1 ;
if ( V_115 + V_25 < V_115 )
return - 1 ;
return F_76 ( V_1 , V_73 , V_115 , V_74 , V_25 ) ;
}
T_5 F_82 ( struct V_1 * V_1 , struct V_73 * V_73 ,
T_4 V_115 , T_6 * V_74 , T_5 V_25 )
{
if ( V_1 -> V_74 . V_100 == V_102 )
return - 1 ;
return F_81 ( V_1 , V_73 , V_115 , V_74 , V_25 ) ;
}
T_5 F_83 ( struct V_1 * V_1 , struct V_131 * V_131 ,
struct V_73 * V_73 , T_4 V_132 ,
T_6 * V_74 , T_5 V_25 )
{
T_4 V_115 = V_131 -> V_133 ( V_131 , V_132 ) ;
return F_82 ( V_1 , V_73 , V_115 , V_74 , V_25 ) ;
}
struct V_131 * F_84 ( const char * V_59 )
{
struct V_131 * V_131 = NULL ;
struct V_1 * V_1 = F_85 ( V_59 ) ;
if ( V_1 )
V_131 = F_86 ( 0 , V_1 , V_134 ) ;
return V_131 ;
}
struct V_1 * F_87 ( struct V_73 * V_73 , const char * V_59 ,
const char * V_135 , int V_136 )
{
struct V_1 * V_1 = F_88 ( V_73 , V_59 ) ;
if ( V_1 != NULL ) {
F_32 ( V_1 , V_135 , false ) ;
V_1 -> V_137 = V_136 ;
}
return V_1 ;
}
static struct V_1 * F_89 ( struct V_108 * V_109 ,
struct V_1 * V_1 , const char * V_59 )
{
struct V_111 * * V_116 = & V_109 -> V_111 ;
struct V_111 * V_117 = NULL ;
if ( ! V_59 )
V_59 = V_1 -> V_35 ;
while ( * V_116 ) {
struct V_1 * V_138 = F_63 ( * V_116 , struct V_1 , V_111 ) ;
int V_139 = strcmp ( V_59 , V_138 -> V_35 ) ;
V_117 = * V_116 ;
if ( V_139 == 0 ) {
if ( ! V_1 || ( V_1 == V_138 ) )
return V_138 ;
V_139 = strcmp ( V_1 -> V_135 , V_138 -> V_135 ) ;
if ( V_139 == 0 ) {
F_15 ( L_20 , V_59 ) ;
return NULL ;
}
}
if ( V_139 < 0 )
V_116 = & V_117 -> V_120 ;
else
V_116 = & V_117 -> V_121 ;
}
if ( V_1 ) {
F_68 ( & V_1 -> V_111 , V_117 , V_116 ) ;
F_69 ( & V_1 -> V_111 , V_109 ) ;
V_1 -> V_109 = V_109 ;
}
return NULL ;
}
static inline struct V_1 * F_90 ( struct V_108 * V_109 ,
const char * V_59 )
{
return F_89 ( V_109 , NULL , V_59 ) ;
}
void F_91 ( struct V_1 * V_1 , const char * V_59 , bool V_140 )
{
struct V_108 * V_109 = V_1 -> V_109 ;
if ( V_59 == NULL )
return;
if ( V_1 -> V_141 )
free ( ( char * ) V_1 -> V_35 ) ;
if ( V_109 ) {
F_65 ( & V_1 -> V_111 , V_109 ) ;
F_92 ( & V_1 -> V_111 ) ;
V_1 -> V_109 = NULL ;
}
V_1 -> V_35 = V_59 ;
V_1 -> V_38 = strlen ( V_59 ) ;
V_1 -> V_141 = V_140 ;
if ( V_109 )
F_89 ( V_109 , V_1 , NULL ) ;
}
void F_32 ( struct V_1 * V_1 , const char * V_59 , bool V_140 )
{
if ( V_59 == NULL )
return;
if ( V_1 -> V_142 )
free ( ( char * ) V_1 -> V_135 ) ;
V_1 -> V_135 = V_59 ;
V_1 -> V_143 = strlen ( V_59 ) ;
V_1 -> V_142 = V_140 ;
}
static void F_93 ( struct V_1 * V_1 )
{
char * V_144 , * V_145 = F_27 ( V_1 -> V_35 ) ;
if ( ! V_145 )
return;
V_144 = F_27 ( F_94 ( V_145 ) ) ;
free ( V_145 ) ;
if ( ! V_144 )
return;
F_32 ( V_1 , V_144 , true ) ;
}
int F_95 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_21 ) ;
if ( V_146 > 0 )
return V_1 -> V_38 ;
return V_1 -> V_143 ;
}
bool F_96 ( const struct V_1 * V_1 , enum V_147 type )
{
return V_1 -> V_148 & ( 1 << type ) ;
}
bool F_97 ( const struct V_1 * V_1 , enum V_147 type )
{
return V_1 -> V_149 & ( 1 << type ) ;
}
void F_98 ( struct V_1 * V_1 , enum V_147 type )
{
V_1 -> V_149 |= ( 1 << type ) ;
}
struct V_1 * F_85 ( const char * V_59 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_59 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_34 ;
strcpy ( V_1 -> V_59 , V_59 ) ;
F_91 ( V_1 , V_1 -> V_59 , false ) ;
F_32 ( V_1 , V_1 -> V_59 , false ) ;
for ( V_34 = 0 ; V_34 < V_150 ; ++ V_34 )
V_1 -> V_151 [ V_34 ] = V_1 -> V_152 [ V_34 ] = V_153 ;
V_1 -> V_74 . V_110 = V_153 ;
V_1 -> V_74 . V_61 = - 1 ;
V_1 -> V_74 . V_100 = V_154 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_83 = V_21 ;
V_1 -> V_155 = ( sizeof( void * ) == 8 ) ;
V_1 -> V_148 = 0 ;
V_1 -> V_156 = 0 ;
V_1 -> V_149 = 0 ;
V_1 -> V_39 = 0 ;
V_1 -> V_157 = 1 ;
V_1 -> V_158 = 1 ;
V_1 -> V_137 = V_159 ;
V_1 -> V_160 = V_161 ;
F_92 ( & V_1 -> V_111 ) ;
V_1 -> V_109 = NULL ;
F_99 ( & V_1 -> V_162 ) ;
F_99 ( & V_1 -> V_74 . V_75 ) ;
F_100 ( & V_1 -> V_113 , NULL ) ;
F_101 ( & V_1 -> V_163 , 1 ) ;
}
return V_1 ;
}
void F_102 ( struct V_1 * V_1 )
{
int V_34 ;
if ( ! F_103 ( & V_1 -> V_111 ) )
F_15 ( L_22 ,
V_1 -> V_35 ) ;
for ( V_34 = 0 ; V_34 < V_150 ; ++ V_34 )
F_104 ( & V_1 -> V_151 [ V_34 ] ) ;
if ( V_1 -> V_142 ) {
F_105 ( ( char * * ) & V_1 -> V_135 ) ;
V_1 -> V_142 = false ;
}
if ( V_1 -> V_141 ) {
F_105 ( ( char * * ) & V_1 -> V_35 ) ;
V_1 -> V_141 = false ;
}
F_54 ( V_1 ) ;
F_106 ( V_1 -> V_164 ) ;
F_61 ( V_1 ) ;
F_107 ( V_1 ) ;
F_105 ( & V_1 -> V_165 ) ;
F_108 ( V_1 -> V_88 ) ;
F_109 ( & V_1 -> V_113 ) ;
free ( V_1 ) ;
}
struct V_1 * F_110 ( struct V_1 * V_1 )
{
if ( V_1 )
F_111 ( & V_1 -> V_163 ) ;
return V_1 ;
}
void F_112 ( struct V_1 * V_1 )
{
if ( V_1 && F_113 ( & V_1 -> V_163 ) )
F_102 ( V_1 ) ;
}
void F_114 ( struct V_1 * V_1 , void * V_40 )
{
memcpy ( V_1 -> V_40 , V_40 , sizeof( V_1 -> V_40 ) ) ;
V_1 -> V_39 = 1 ;
}
bool F_115 ( const struct V_1 * V_1 , T_6 * V_40 )
{
return memcmp ( V_1 -> V_40 , V_40 , sizeof( V_1 -> V_40 ) ) == 0 ;
}
void F_116 ( struct V_1 * V_1 , struct V_73 * V_73 )
{
char V_68 [ V_32 ] ;
if ( F_117 ( V_73 ) )
return;
sprintf ( V_68 , L_23 , V_73 -> V_23 ) ;
if ( F_118 ( V_68 , V_1 -> V_40 ,
sizeof( V_1 -> V_40 ) ) == 0 )
V_1 -> V_39 = true ;
}
int F_119 ( struct V_1 * V_1 ,
const char * V_23 )
{
char V_24 [ V_32 ] ;
const char * V_59 = V_1 -> V_135 + 1 ;
snprintf ( V_24 , sizeof( V_24 ) ,
L_24 ,
V_23 , ( int ) strlen ( V_59 ) - 1 , V_59 ) ;
if ( F_118 ( V_24 , V_1 -> V_40 ,
sizeof( V_1 -> V_40 ) ) == 0 )
V_1 -> V_39 = true ;
return 0 ;
}
bool F_120 ( struct V_166 * V_167 , bool V_168 )
{
bool V_169 = false ;
struct V_1 * V_170 ;
struct V_86 V_87 ;
F_121 (pos, head, node) {
if ( V_168 && ! V_170 -> V_171 && ! F_122 ( V_170 ) )
continue;
if ( V_170 -> V_39 ) {
V_169 = true ;
continue;
}
F_44 ( V_170 -> V_88 , & V_87 ) ;
if ( F_123 ( V_170 -> V_35 , V_170 -> V_40 ,
sizeof( V_170 -> V_40 ) ) > 0 ) {
V_169 = true ;
V_170 -> V_39 = true ;
}
F_45 ( & V_87 ) ;
}
return V_169 ;
}
void F_124 ( struct V_172 * V_172 , struct V_1 * V_1 )
{
F_34 ( & V_1 -> V_162 , & V_172 -> V_167 ) ;
F_89 ( & V_172 -> V_109 , V_1 , NULL ) ;
F_110 ( V_1 ) ;
}
void F_125 ( struct V_172 * V_172 , struct V_1 * V_1 )
{
F_126 ( & V_172 -> V_113 ) ;
F_124 ( V_172 , V_1 ) ;
F_127 ( & V_172 -> V_113 ) ;
}
struct V_1 * F_128 ( struct V_172 * V_172 , const char * V_59 , bool V_173 )
{
struct V_1 * V_170 ;
if ( V_173 ) {
F_121 (pos, &dsos->head, node)
if ( strcmp ( V_170 -> V_135 , V_59 ) == 0 )
return V_170 ;
return NULL ;
}
return F_90 ( & V_172 -> V_109 , V_59 ) ;
}
struct V_1 * F_129 ( struct V_172 * V_172 , const char * V_59 , bool V_173 )
{
struct V_1 * V_1 ;
F_130 ( & V_172 -> V_113 ) ;
V_1 = F_128 ( V_172 , V_59 , V_173 ) ;
F_127 ( & V_172 -> V_113 ) ;
return V_1 ;
}
struct V_1 * F_131 ( struct V_172 * V_172 , const char * V_59 )
{
struct V_1 * V_1 = F_85 ( V_59 ) ;
if ( V_1 != NULL ) {
F_124 ( V_172 , V_1 ) ;
F_93 ( V_1 ) ;
F_112 ( V_1 ) ;
}
return V_1 ;
}
struct V_1 * F_132 ( struct V_172 * V_172 , const char * V_59 )
{
struct V_1 * V_1 = F_128 ( V_172 , V_59 , false ) ;
return V_1 ? V_1 : F_131 ( V_172 , V_59 ) ;
}
struct V_1 * F_133 ( struct V_172 * V_172 , const char * V_59 )
{
struct V_1 * V_1 ;
F_126 ( & V_172 -> V_113 ) ;
V_1 = F_110 ( F_132 ( V_172 , V_59 ) ) ;
F_127 ( & V_172 -> V_113 ) ;
return V_1 ;
}
T_1 F_134 ( struct V_166 * V_167 , T_8 * V_174 ,
bool (F_135)( struct V_1 * V_1 , int V_175 ) , int V_175 )
{
struct V_1 * V_170 ;
T_1 V_28 = 0 ;
F_121 (pos, head, node) {
if ( F_135 && F_135 ( V_170 , V_175 ) )
continue;
V_28 += F_136 ( V_170 , V_174 ) ;
V_28 += fprintf ( V_174 , L_25 , V_170 -> V_35 ) ;
}
return V_28 ;
}
T_1 F_137 ( struct V_166 * V_167 , T_8 * V_174 )
{
struct V_1 * V_170 ;
T_1 V_28 = 0 ;
F_121 (pos, head, node) {
int V_34 ;
for ( V_34 = 0 ; V_34 < V_150 ; ++ V_34 )
V_28 += F_138 ( V_170 , V_34 , V_174 ) ;
}
return V_28 ;
}
T_1 F_136 ( struct V_1 * V_1 , T_8 * V_174 )
{
char V_176 [ V_27 ] ;
F_9 ( V_1 -> V_40 , sizeof( V_1 -> V_40 ) , V_176 ) ;
return fprintf ( V_174 , L_3 , V_176 ) ;
}
T_1 F_138 ( struct V_1 * V_1 , enum V_147 type , T_8 * V_174 )
{
struct V_111 * V_177 ;
T_1 V_28 = fprintf ( V_174 , L_26 , V_1 -> V_135 ) ;
if ( V_1 -> V_135 != V_1 -> V_35 )
V_28 += fprintf ( V_174 , L_27 , V_1 -> V_35 ) ;
V_28 += fprintf ( V_174 , L_28 , V_178 [ type ] ,
F_96 ( V_1 , type ) ? L_4 : L_29 ) ;
V_28 += F_136 ( V_1 , V_174 ) ;
V_28 += fprintf ( V_174 , L_30 ) ;
for ( V_177 = F_62 ( & V_1 -> V_151 [ type ] ) ; V_177 ; V_177 = F_64 ( V_177 ) ) {
struct V_179 * V_170 = F_63 ( V_177 , struct V_179 , V_111 ) ;
V_28 += F_139 ( V_170 , V_174 ) ;
}
return V_28 ;
}
enum V_136 F_140 ( struct V_1 * V_1 , struct V_73 * V_73 )
{
int V_61 ;
enum V_136 type = V_180 ;
V_61 = F_58 ( V_1 , V_73 ) ;
if ( V_61 >= 0 ) {
type = F_141 ( V_61 ) ;
F_59 ( V_1 ) ;
}
return type ;
}
int F_142 ( struct V_1 * V_1 , char * V_181 , T_1 V_182 )
{
int V_183 , V_184 = V_1 -> V_64 ;
static const char * V_185 [] = {
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
} ;
F_77 ( V_182 == 0 ) ;
if ( V_184 >= 0 ) {
const char * V_186 = F_40 ( V_184 , V_181 , V_182 ) ;
if ( V_186 != V_181 )
F_8 ( V_181 , V_182 , L_3 , V_186 ) ;
return 0 ;
}
if ( V_184 < V_187 || V_184 >= V_188 )
return - 1 ;
V_183 = V_184 - V_187 ;
F_8 ( V_181 , V_182 , L_3 , V_185 [ V_183 ] ) ;
return 0 ;
}
