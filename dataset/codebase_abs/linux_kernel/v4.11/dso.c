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
int F_19 ( struct V_49 * V_50 , const char * V_58 ,
bool V_59 , bool V_60 )
{
const char * V_61 = strrchr ( V_58 , '/' ) ;
const char * V_44 = strrchr ( V_58 , '.' ) ;
bool V_62 = false ;
memset ( V_50 , 0x0 , sizeof( * V_50 ) ) ;
V_61 = V_61 ? V_61 + 1 : V_58 ;
if ( V_61 [ 0 ] == '[' ) {
V_62 = true ;
if ( ( strncmp ( V_61 , L_10 , 17 ) == 0 ) ||
( strncmp ( V_61 , L_11 , 22 ) == 0 ) ||
( strncmp ( V_61 , L_12 , 6 ) == 0 ) ||
( strncmp ( V_61 , L_13 , 10 ) == 0 ) ) {
V_50 -> V_56 = false ;
} else
V_50 -> V_56 = true ;
}
if ( ( V_44 == NULL ) || V_62 ) {
if ( V_59 ) {
V_50 -> V_61 = F_20 ( V_61 ) ;
return V_50 -> V_61 ? 0 : - V_63 ;
}
return 0 ;
}
if ( F_11 ( V_44 + 1 ) ) {
V_50 -> V_64 = true ;
V_44 -= 3 ;
}
if ( V_44 > V_61 )
V_50 -> V_56 = ! strncmp ( V_44 , L_14 , 3 ) ;
if ( V_59 ) {
if ( V_50 -> V_56 ) {
if ( F_21 ( & V_50 -> V_61 , L_15 , ( int ) ( V_44 - V_61 ) , V_61 ) == - 1 )
return - V_63 ;
} else {
if ( F_21 ( & V_50 -> V_61 , L_3 , V_61 ) == - 1 )
return - V_63 ;
}
F_22 ( V_50 -> V_61 , '-' , '_' ) ;
}
if ( V_60 && V_50 -> V_64 ) {
V_50 -> V_44 = F_20 ( V_44 + 4 ) ;
if ( ! V_50 -> V_44 ) {
free ( ( void * ) V_50 -> V_61 ) ;
return - V_63 ;
}
}
return 0 ;
}
static void F_23 ( struct V_1 * V_1 )
{
F_24 ( & V_1 -> V_65 . V_66 , & V_67 ) ;
V_68 ++ ;
}
static void F_25 ( struct V_1 * V_1 )
{
F_26 ( & V_1 -> V_65 . V_66 ) ;
F_13 ( V_68 <= 0 ,
L_16 ) ;
V_68 -- ;
}
static int F_27 ( char * V_61 )
{
int V_69 ;
char V_70 [ V_71 ] ;
do {
V_69 = F_28 ( V_61 , V_72 ) ;
if ( V_69 >= 0 )
return V_69 ;
F_29 ( L_17 ,
F_30 ( V_73 , V_70 , sizeof( V_70 ) ) ) ;
if ( ! V_68 || V_73 != V_74 )
break;
F_31 () ;
} while ( 1 );
return - 1 ;
}
static int F_32 ( struct V_1 * V_1 , struct V_75 * V_75 )
{
int V_69 ;
char * V_22 = ( char * ) L_4 ;
char * V_61 = malloc ( V_31 ) ;
if ( ! V_61 )
return - V_63 ;
if ( V_75 )
V_22 = V_75 -> V_22 ;
if ( F_2 ( V_1 , V_1 -> V_76 ,
V_22 , V_61 , V_31 ) ) {
free ( V_61 ) ;
return - V_77 ;
}
if ( ! F_4 ( V_61 ) )
return - V_77 ;
V_69 = F_27 ( V_61 ) ;
free ( V_61 ) ;
return V_69 ;
}
static int F_33 ( struct V_1 * V_1 , struct V_75 * V_75 )
{
int V_69 = F_32 ( V_1 , V_75 ) ;
if ( V_69 >= 0 ) {
F_23 ( V_1 ) ;
F_34 () ;
}
return V_69 ;
}
static void F_35 ( struct V_1 * V_1 )
{
if ( V_1 -> V_65 . V_69 >= 0 ) {
F_36 ( V_1 -> V_65 . V_69 ) ;
V_1 -> V_65 . V_69 = - 1 ;
V_1 -> V_65 . V_78 = 0 ;
F_25 ( V_1 ) ;
}
}
static void F_37 ( struct V_1 * V_1 )
{
F_35 ( V_1 ) ;
}
static void F_31 ( void )
{
struct V_1 * V_1 ;
V_1 = F_38 ( & V_67 , struct V_1 , V_65 . V_66 ) ;
F_37 ( V_1 ) ;
}
static T_2 F_39 ( void )
{
struct V_79 V_80 ;
T_2 V_81 = 0 ;
if ( F_40 ( V_82 , & V_80 ) == 0 ) {
if ( V_80 . V_83 == V_84 )
V_81 = V_80 . V_83 ;
else
V_81 = V_80 . V_83 / 2 ;
} else {
F_15 ( L_18 ) ;
V_81 = 1 ;
}
return V_81 ;
}
void F_41 ( void )
{
V_85 = 0 ;
}
static bool F_42 ( void )
{
if ( ! V_85 )
V_85 = F_39 () ;
if ( V_85 == V_84 )
return true ;
return V_85 > ( T_2 ) V_68 ;
}
static void F_34 ( void )
{
bool V_86 = F_42 () ;
if ( ! V_86 )
F_31 () ;
}
void F_43 ( struct V_1 * V_1 )
{
F_44 ( & V_87 ) ;
F_37 ( V_1 ) ;
F_45 ( & V_87 ) ;
}
static void F_46 ( struct V_1 * V_1 , struct V_75 * V_75 )
{
enum V_21 V_88 [] = {
V_7 ,
V_12 ,
V_20 ,
} ;
int V_33 = 0 ;
if ( V_1 -> V_65 . V_69 >= 0 )
return;
if ( V_1 -> V_76 != V_20 ) {
V_1 -> V_65 . V_69 = F_33 ( V_1 , V_75 ) ;
goto V_89;
}
do {
V_1 -> V_76 = V_88 [ V_33 ++ ] ;
V_1 -> V_65 . V_69 = F_33 ( V_1 , V_75 ) ;
if ( V_1 -> V_65 . V_69 >= 0 )
goto V_89;
} while ( V_1 -> V_76 != V_20 );
V_89:
if ( V_1 -> V_65 . V_69 >= 0 )
V_1 -> V_65 . V_90 = V_91 ;
else
V_1 -> V_65 . V_90 = V_92 ;
}
int F_47 ( struct V_1 * V_1 , struct V_75 * V_75 )
{
if ( V_1 -> V_65 . V_90 == V_92 )
return - 1 ;
if ( F_44 ( & V_87 ) < 0 )
return - 1 ;
F_46 ( V_1 , V_75 ) ;
if ( V_1 -> V_65 . V_69 < 0 )
F_45 ( & V_87 ) ;
return V_1 -> V_65 . V_69 ;
}
void F_48 ( struct V_1 * V_1 V_93 )
{
F_45 ( & V_87 ) ;
}
bool F_49 ( struct V_1 * V_1 , enum V_94 V_95 )
{
T_3 V_96 = 1 << V_95 ;
if ( V_1 -> V_65 . V_97 & V_96 )
return true ;
V_1 -> V_65 . V_97 |= V_96 ;
return false ;
}
static void
F_50 ( struct V_1 * V_1 )
{
struct V_98 * V_99 = & V_1 -> V_65 . V_100 ;
struct V_101 * V_102 = F_51 ( V_99 ) ;
F_44 ( & V_1 -> V_103 ) ;
while ( V_102 ) {
struct V_104 * V_100 ;
V_100 = F_52 ( V_102 , struct V_104 , V_101 ) ;
V_102 = F_53 ( & V_100 -> V_101 ) ;
F_54 ( & V_100 -> V_101 , V_99 ) ;
free ( V_100 ) ;
}
F_45 ( & V_1 -> V_103 ) ;
}
static struct V_104 * F_55 ( struct V_1 * V_1 , T_4 V_105 )
{
const struct V_98 * V_99 = & V_1 -> V_65 . V_100 ;
struct V_101 * const * V_106 = & V_99 -> V_101 ;
const struct V_101 * V_107 = NULL ;
struct V_104 * V_100 ;
while ( * V_106 != NULL ) {
T_4 V_108 ;
V_107 = * V_106 ;
V_100 = F_52 ( V_107 , struct V_104 , V_101 ) ;
V_108 = V_100 -> V_105 + V_109 ;
if ( V_105 < V_100 -> V_105 )
V_106 = & ( * V_106 ) -> V_110 ;
else if ( V_105 >= V_108 )
V_106 = & ( * V_106 ) -> V_111 ;
else
return V_100 ;
}
return NULL ;
}
static struct V_104 *
F_56 ( struct V_1 * V_1 , struct V_104 * V_112 )
{
struct V_98 * V_99 = & V_1 -> V_65 . V_100 ;
struct V_101 * * V_106 = & V_99 -> V_101 ;
struct V_101 * V_107 = NULL ;
struct V_104 * V_100 ;
T_4 V_105 = V_112 -> V_105 ;
F_44 ( & V_1 -> V_103 ) ;
while ( * V_106 != NULL ) {
T_4 V_108 ;
V_107 = * V_106 ;
V_100 = F_52 ( V_107 , struct V_104 , V_101 ) ;
V_108 = V_100 -> V_105 + V_109 ;
if ( V_105 < V_100 -> V_105 )
V_106 = & ( * V_106 ) -> V_110 ;
else if ( V_105 >= V_108 )
V_106 = & ( * V_106 ) -> V_111 ;
else
goto V_89;
}
F_57 ( & V_112 -> V_101 , V_107 , V_106 ) ;
F_58 ( & V_112 -> V_101 , V_99 ) ;
V_100 = NULL ;
V_89:
F_45 ( & V_1 -> V_103 ) ;
return V_100 ;
}
static T_5
F_59 ( struct V_104 * V_100 , T_4 V_105 ,
T_6 * V_65 , T_4 V_24 )
{
T_4 V_113 = V_105 - V_100 -> V_105 ;
T_4 V_114 = F_60 ( V_100 -> V_24 - V_113 , V_24 ) ;
memcpy ( V_65 , V_100 -> V_65 + V_113 , V_114 ) ;
return V_114 ;
}
static T_5
F_61 ( struct V_1 * V_1 , struct V_75 * V_75 ,
T_4 V_105 , T_6 * V_65 , T_5 V_24 )
{
struct V_104 * V_100 ;
struct V_104 * V_115 ;
T_5 V_27 ;
do {
T_4 V_113 ;
V_100 = F_62 ( sizeof( * V_100 ) + V_109 ) ;
if ( ! V_100 )
return - V_63 ;
F_44 ( & V_87 ) ;
F_46 ( V_1 , V_75 ) ;
if ( V_1 -> V_65 . V_69 < 0 ) {
V_27 = - V_73 ;
V_1 -> V_65 . V_90 = V_92 ;
break;
}
V_113 = V_105 & V_116 ;
V_27 = F_63 ( V_1 -> V_65 . V_69 , V_100 -> V_65 , V_109 , V_113 ) ;
if ( V_27 <= 0 )
break;
V_100 -> V_105 = V_113 ;
V_100 -> V_24 = V_27 ;
} while ( 0 );
F_45 ( & V_87 ) ;
if ( V_27 > 0 ) {
V_115 = F_56 ( V_1 , V_100 ) ;
if ( V_115 ) {
free ( V_100 ) ;
V_100 = V_115 ;
}
V_27 = F_59 ( V_100 , V_105 , V_65 , V_24 ) ;
}
if ( V_27 <= 0 )
free ( V_100 ) ;
return V_27 ;
}
static T_5 F_64 ( struct V_1 * V_1 , struct V_75 * V_75 ,
T_4 V_105 , T_6 * V_65 , T_5 V_24 )
{
struct V_104 * V_100 ;
V_100 = F_55 ( V_1 , V_105 ) ;
if ( V_100 )
return F_59 ( V_100 , V_105 , V_65 , V_24 ) ;
else
return F_61 ( V_1 , V_75 , V_105 , V_65 , V_24 ) ;
}
static T_5 F_65 ( struct V_1 * V_1 , struct V_75 * V_75 ,
T_4 V_105 , T_6 * V_65 , T_5 V_24 )
{
T_5 V_117 = 0 ;
T_6 * V_106 = V_65 ;
do {
T_5 V_27 ;
V_27 = F_64 ( V_1 , V_75 , V_105 , V_106 , V_24 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! V_27 )
break;
F_66 ( V_27 > V_24 ) ;
V_117 += V_27 ;
V_106 += V_27 ;
V_105 += V_27 ;
V_24 -= V_27 ;
} while ( V_24 );
return V_117 ;
}
static int F_67 ( struct V_1 * V_1 , struct V_75 * V_75 )
{
int V_27 = 0 ;
struct V_118 V_119 ;
char V_70 [ V_71 ] ;
if ( V_1 -> V_65 . V_78 )
return 0 ;
if ( V_1 -> V_65 . V_90 == V_92 )
return - 1 ;
F_44 ( & V_87 ) ;
F_46 ( V_1 , V_75 ) ;
if ( V_1 -> V_65 . V_69 < 0 ) {
V_27 = - V_73 ;
V_1 -> V_65 . V_90 = V_92 ;
goto V_89;
}
if ( F_68 ( V_1 -> V_65 . V_69 , & V_119 ) < 0 ) {
V_27 = - V_73 ;
F_15 ( L_19 ,
F_30 ( V_73 , V_70 , sizeof( V_70 ) ) ) ;
V_1 -> V_65 . V_90 = V_92 ;
goto V_89;
}
V_1 -> V_65 . V_78 = V_119 . V_120 ;
V_89:
F_45 ( & V_87 ) ;
return V_27 ;
}
T_7 F_69 ( struct V_1 * V_1 , struct V_75 * V_75 )
{
if ( F_67 ( V_1 , V_75 ) )
return - 1 ;
return V_1 -> V_65 . V_78 ;
}
static T_5 F_70 ( struct V_1 * V_1 , struct V_75 * V_75 ,
T_4 V_105 , T_6 * V_65 , T_5 V_24 )
{
if ( F_67 ( V_1 , V_75 ) )
return - 1 ;
if ( V_105 > V_1 -> V_65 . V_78 )
return - 1 ;
if ( V_105 + V_24 < V_105 )
return - 1 ;
return F_65 ( V_1 , V_75 , V_105 , V_65 , V_24 ) ;
}
T_5 F_71 ( struct V_1 * V_1 , struct V_75 * V_75 ,
T_4 V_105 , T_6 * V_65 , T_5 V_24 )
{
if ( V_1 -> V_65 . V_90 == V_92 )
return - 1 ;
return F_70 ( V_1 , V_75 , V_105 , V_65 , V_24 ) ;
}
T_5 F_72 ( struct V_1 * V_1 , struct V_121 * V_121 ,
struct V_75 * V_75 , T_4 V_122 ,
T_6 * V_65 , T_5 V_24 )
{
T_4 V_105 = V_121 -> V_123 ( V_121 , V_122 ) ;
return F_71 ( V_1 , V_75 , V_105 , V_65 , V_24 ) ;
}
struct V_121 * F_73 ( const char * V_61 )
{
struct V_121 * V_121 = NULL ;
struct V_1 * V_1 = F_74 ( V_61 ) ;
if ( V_1 )
V_121 = F_75 ( 0 , V_1 , V_124 ) ;
return V_121 ;
}
struct V_1 * F_76 ( struct V_75 * V_75 , const char * V_61 ,
const char * V_125 , int V_126 )
{
struct V_1 * V_1 = F_77 ( V_75 , V_61 ) ;
if ( V_1 != NULL ) {
F_78 ( V_1 , V_125 , false ) ;
V_1 -> V_127 = V_126 ;
}
return V_1 ;
}
static struct V_1 * F_79 ( struct V_98 * V_99 ,
struct V_1 * V_1 , const char * V_61 )
{
struct V_101 * * V_106 = & V_99 -> V_101 ;
struct V_101 * V_107 = NULL ;
if ( ! V_61 )
V_61 = V_1 -> V_34 ;
while ( * V_106 ) {
struct V_1 * V_128 = F_52 ( * V_106 , struct V_1 , V_101 ) ;
int V_129 = strcmp ( V_61 , V_128 -> V_34 ) ;
V_107 = * V_106 ;
if ( V_129 == 0 ) {
if ( ! V_1 || ( V_1 == V_128 ) )
return V_128 ;
V_129 = strcmp ( V_1 -> V_125 , V_128 -> V_125 ) ;
if ( V_129 == 0 ) {
F_15 ( L_20 , V_61 ) ;
return NULL ;
}
}
if ( V_129 < 0 )
V_106 = & V_107 -> V_110 ;
else
V_106 = & V_107 -> V_111 ;
}
if ( V_1 ) {
F_57 ( & V_1 -> V_101 , V_107 , V_106 ) ;
F_58 ( & V_1 -> V_101 , V_99 ) ;
V_1 -> V_99 = V_99 ;
}
return NULL ;
}
static inline struct V_1 * F_80 ( struct V_98 * V_99 ,
const char * V_61 )
{
return F_79 ( V_99 , NULL , V_61 ) ;
}
void F_81 ( struct V_1 * V_1 , const char * V_61 , bool V_130 )
{
struct V_98 * V_99 = V_1 -> V_99 ;
if ( V_61 == NULL )
return;
if ( V_1 -> V_131 )
free ( ( char * ) V_1 -> V_34 ) ;
if ( V_99 ) {
F_54 ( & V_1 -> V_101 , V_99 ) ;
F_82 ( & V_1 -> V_101 ) ;
V_1 -> V_99 = NULL ;
}
V_1 -> V_34 = V_61 ;
V_1 -> V_37 = strlen ( V_61 ) ;
V_1 -> V_131 = V_130 ;
if ( V_99 )
F_79 ( V_99 , V_1 , NULL ) ;
}
void F_78 ( struct V_1 * V_1 , const char * V_61 , bool V_130 )
{
if ( V_61 == NULL )
return;
if ( V_1 -> V_132 )
free ( ( char * ) V_1 -> V_125 ) ;
V_1 -> V_125 = V_61 ;
V_1 -> V_133 = strlen ( V_61 ) ;
V_1 -> V_132 = V_130 ;
}
static void F_83 ( struct V_1 * V_1 )
{
char * V_134 , * V_135 = F_20 ( V_1 -> V_34 ) ;
if ( ! V_135 )
return;
V_134 = F_20 ( F_84 ( V_135 ) ) ;
free ( V_135 ) ;
if ( ! V_134 )
return;
F_78 ( V_1 , V_134 , true ) ;
}
int F_85 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_21 ) ;
if ( V_136 > 0 )
return V_1 -> V_37 ;
return V_1 -> V_133 ;
}
bool F_86 ( const struct V_1 * V_1 , enum V_137 type )
{
return V_1 -> V_138 & ( 1 << type ) ;
}
bool F_87 ( const struct V_1 * V_1 , enum V_137 type )
{
return V_1 -> V_139 & ( 1 << type ) ;
}
void F_88 ( struct V_1 * V_1 , enum V_137 type )
{
V_1 -> V_139 |= ( 1 << type ) ;
}
struct V_1 * F_74 ( const char * V_61 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_61 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_33 ;
strcpy ( V_1 -> V_61 , V_61 ) ;
F_81 ( V_1 , V_1 -> V_61 , false ) ;
F_78 ( V_1 , V_1 -> V_61 , false ) ;
for ( V_33 = 0 ; V_33 < V_140 ; ++ V_33 )
V_1 -> V_141 [ V_33 ] = V_1 -> V_142 [ V_33 ] = V_143 ;
V_1 -> V_65 . V_100 = V_143 ;
V_1 -> V_65 . V_69 = - 1 ;
V_1 -> V_65 . V_90 = V_144 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_76 = V_20 ;
V_1 -> V_145 = ( sizeof( void * ) == 8 ) ;
V_1 -> V_138 = 0 ;
V_1 -> V_146 = 0 ;
V_1 -> V_139 = 0 ;
V_1 -> V_38 = 0 ;
V_1 -> V_147 = 1 ;
V_1 -> V_148 = 1 ;
V_1 -> V_127 = V_149 ;
V_1 -> V_150 = V_151 ;
F_82 ( & V_1 -> V_101 ) ;
V_1 -> V_99 = NULL ;
F_89 ( & V_1 -> V_152 ) ;
F_89 ( & V_1 -> V_65 . V_66 ) ;
F_90 ( & V_1 -> V_103 , NULL ) ;
F_91 ( & V_1 -> V_153 , 1 ) ;
}
return V_1 ;
}
void F_92 ( struct V_1 * V_1 )
{
int V_33 ;
if ( ! F_93 ( & V_1 -> V_101 ) )
F_15 ( L_22 ,
V_1 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < V_140 ; ++ V_33 )
F_94 ( & V_1 -> V_141 [ V_33 ] ) ;
if ( V_1 -> V_132 ) {
F_95 ( ( char * * ) & V_1 -> V_125 ) ;
V_1 -> V_132 = false ;
}
if ( V_1 -> V_131 ) {
F_95 ( ( char * * ) & V_1 -> V_34 ) ;
V_1 -> V_131 = false ;
}
F_43 ( V_1 ) ;
F_96 ( V_1 -> V_154 ) ;
F_50 ( V_1 ) ;
F_97 ( V_1 ) ;
F_95 ( & V_1 -> V_155 ) ;
F_98 ( & V_1 -> V_103 ) ;
free ( V_1 ) ;
}
struct V_1 * F_99 ( struct V_1 * V_1 )
{
if ( V_1 )
F_100 ( & V_1 -> V_153 ) ;
return V_1 ;
}
void F_101 ( struct V_1 * V_1 )
{
if ( V_1 && F_102 ( & V_1 -> V_153 ) )
F_92 ( V_1 ) ;
}
void F_103 ( struct V_1 * V_1 , void * V_39 )
{
memcpy ( V_1 -> V_39 , V_39 , sizeof( V_1 -> V_39 ) ) ;
V_1 -> V_38 = 1 ;
}
bool F_104 ( const struct V_1 * V_1 , T_6 * V_39 )
{
return memcmp ( V_1 -> V_39 , V_39 , sizeof( V_1 -> V_39 ) ) == 0 ;
}
void F_105 ( struct V_1 * V_1 , struct V_75 * V_75 )
{
char V_58 [ V_31 ] ;
if ( F_106 ( V_75 ) )
return;
sprintf ( V_58 , L_23 , V_75 -> V_22 ) ;
if ( F_107 ( V_58 , V_1 -> V_39 ,
sizeof( V_1 -> V_39 ) ) == 0 )
V_1 -> V_38 = true ;
}
int F_108 ( struct V_1 * V_1 ,
const char * V_22 )
{
char V_23 [ V_31 ] ;
const char * V_61 = V_1 -> V_125 + 1 ;
snprintf ( V_23 , sizeof( V_23 ) ,
L_24 ,
V_22 , ( int ) strlen ( V_61 ) - 1 , V_61 ) ;
if ( F_107 ( V_23 , V_1 -> V_39 ,
sizeof( V_1 -> V_39 ) ) == 0 )
V_1 -> V_38 = true ;
return 0 ;
}
bool F_109 ( struct V_156 * V_157 , bool V_158 )
{
bool V_159 = false ;
struct V_1 * V_160 ;
F_110 (pos, head, node) {
if ( V_158 && ! V_160 -> V_161 && ! F_111 ( V_160 ) )
continue;
if ( V_160 -> V_38 ) {
V_159 = true ;
continue;
}
if ( F_112 ( V_160 -> V_34 , V_160 -> V_39 ,
sizeof( V_160 -> V_39 ) ) > 0 ) {
V_159 = true ;
V_160 -> V_38 = true ;
}
}
return V_159 ;
}
void F_113 ( struct V_162 * V_162 , struct V_1 * V_1 )
{
F_24 ( & V_1 -> V_152 , & V_162 -> V_157 ) ;
F_79 ( & V_162 -> V_99 , V_1 , NULL ) ;
F_99 ( V_1 ) ;
}
void F_114 ( struct V_162 * V_162 , struct V_1 * V_1 )
{
F_115 ( & V_162 -> V_103 ) ;
F_113 ( V_162 , V_1 ) ;
F_116 ( & V_162 -> V_103 ) ;
}
struct V_1 * F_117 ( struct V_162 * V_162 , const char * V_61 , bool V_163 )
{
struct V_1 * V_160 ;
if ( V_163 ) {
F_110 (pos, &dsos->head, node)
if ( strcmp ( V_160 -> V_125 , V_61 ) == 0 )
return V_160 ;
return NULL ;
}
return F_80 ( & V_162 -> V_99 , V_61 ) ;
}
struct V_1 * F_118 ( struct V_162 * V_162 , const char * V_61 , bool V_163 )
{
struct V_1 * V_1 ;
F_119 ( & V_162 -> V_103 ) ;
V_1 = F_117 ( V_162 , V_61 , V_163 ) ;
F_116 ( & V_162 -> V_103 ) ;
return V_1 ;
}
struct V_1 * F_120 ( struct V_162 * V_162 , const char * V_61 )
{
struct V_1 * V_1 = F_74 ( V_61 ) ;
if ( V_1 != NULL ) {
F_113 ( V_162 , V_1 ) ;
F_83 ( V_1 ) ;
F_101 ( V_1 ) ;
}
return V_1 ;
}
struct V_1 * F_121 ( struct V_162 * V_162 , const char * V_61 )
{
struct V_1 * V_1 = F_117 ( V_162 , V_61 , false ) ;
return V_1 ? V_1 : F_120 ( V_162 , V_61 ) ;
}
struct V_1 * F_122 ( struct V_162 * V_162 , const char * V_61 )
{
struct V_1 * V_1 ;
F_115 ( & V_162 -> V_103 ) ;
V_1 = F_99 ( F_121 ( V_162 , V_61 ) ) ;
F_116 ( & V_162 -> V_103 ) ;
return V_1 ;
}
T_1 F_123 ( struct V_156 * V_157 , T_8 * V_164 ,
bool (F_124)( struct V_1 * V_1 , int V_165 ) , int V_165 )
{
struct V_1 * V_160 ;
T_1 V_27 = 0 ;
F_110 (pos, head, node) {
if ( F_124 && F_124 ( V_160 , V_165 ) )
continue;
V_27 += F_125 ( V_160 , V_164 ) ;
V_27 += fprintf ( V_164 , L_25 , V_160 -> V_34 ) ;
}
return V_27 ;
}
T_1 F_126 ( struct V_156 * V_157 , T_8 * V_164 )
{
struct V_1 * V_160 ;
T_1 V_27 = 0 ;
F_110 (pos, head, node) {
int V_33 ;
for ( V_33 = 0 ; V_33 < V_140 ; ++ V_33 )
V_27 += F_127 ( V_160 , V_33 , V_164 ) ;
}
return V_27 ;
}
T_1 F_125 ( struct V_1 * V_1 , T_8 * V_164 )
{
char V_166 [ V_26 ] ;
F_9 ( V_1 -> V_39 , sizeof( V_1 -> V_39 ) , V_166 ) ;
return fprintf ( V_164 , L_3 , V_166 ) ;
}
T_1 F_127 ( struct V_1 * V_1 , enum V_137 type , T_8 * V_164 )
{
struct V_101 * V_167 ;
T_1 V_27 = fprintf ( V_164 , L_26 , V_1 -> V_125 ) ;
if ( V_1 -> V_125 != V_1 -> V_34 )
V_27 += fprintf ( V_164 , L_27 , V_1 -> V_34 ) ;
V_27 += fprintf ( V_164 , L_28 , V_168 [ type ] ,
F_86 ( V_1 , type ) ? L_4 : L_29 ) ;
V_27 += F_125 ( V_1 , V_164 ) ;
V_27 += fprintf ( V_164 , L_30 ) ;
for ( V_167 = F_51 ( & V_1 -> V_141 [ type ] ) ; V_167 ; V_167 = F_53 ( V_167 ) ) {
struct V_169 * V_160 = F_52 ( V_167 , struct V_169 , V_101 ) ;
V_27 += F_128 ( V_160 , V_164 ) ;
}
return V_27 ;
}
enum V_126 F_129 ( struct V_1 * V_1 , struct V_75 * V_75 )
{
int V_69 ;
enum V_126 type = V_170 ;
V_69 = F_47 ( V_1 , V_75 ) ;
if ( V_69 >= 0 ) {
type = F_130 ( V_69 ) ;
F_48 ( V_1 ) ;
}
return type ;
}
int F_131 ( struct V_1 * V_1 , char * V_171 , T_1 V_172 )
{
int V_173 , V_174 = V_1 -> V_175 ;
static const char * V_176 [] = {
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
} ;
F_66 ( V_172 == 0 ) ;
if ( V_174 >= 0 ) {
const char * V_177 = F_30 ( V_174 , V_171 , V_172 ) ;
if ( V_177 != V_171 )
F_8 ( V_171 , V_172 , L_3 , V_177 ) ;
return 0 ;
}
if ( V_174 < V_178 || V_174 >= V_179 )
return - 1 ;
V_173 = V_174 - V_178 ;
F_8 ( V_171 , V_172 , L_3 , V_176 [ V_173 ] ) ;
return 0 ;
}
