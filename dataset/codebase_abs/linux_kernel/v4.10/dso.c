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
case V_6 : {
char * V_29 ;
V_28 = F_3 ( V_23 , V_24 , V_1 -> V_30 ) ;
V_29 = V_23 + V_28 ;
while ( V_29 != V_23 && * V_29 != '/' )
V_29 -- ;
if ( * V_29 == '/' )
V_29 ++ ;
V_27 = - 1 ;
if ( ! F_4 ( V_23 ) )
break;
V_27 = F_5 ( V_23 , V_29 ,
V_24 - ( V_29 - V_23 ) ) ;
}
break;
case V_7 :
if ( F_6 ( V_1 , V_23 , V_24 ) == NULL )
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
const char * V_31 ;
T_1 V_32 ;
V_31 = V_1 -> V_30 + V_1 -> V_33 ;
while ( V_31 != V_1 -> V_30 && * V_31 != '/' )
V_31 -- ;
V_28 = F_3 ( V_23 , V_24 , L_4 ) ;
V_32 = V_31 - V_1 -> V_30 + 2 ;
if ( V_32 > ( V_24 - V_28 ) ) {
V_27 = - 1 ;
break;
}
V_28 += F_7 ( V_23 + V_28 , V_32 , L_3 , V_1 -> V_30 ) ;
V_28 += F_7 ( V_23 + V_28 , V_24 - V_28 , L_5 ,
V_31 ) ;
break;
}
case V_11 :
if ( ! V_1 -> V_34 ) {
V_27 = - 1 ;
break;
}
F_8 ( V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ,
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
F_9 ( V_23 , V_24 , V_36 . V_37 ,
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
bool F_10 ( const char * V_40 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_42 [ V_41 ] . V_43 ; V_41 ++ ) {
if ( ! strcmp ( V_40 , V_42 [ V_41 ] . V_43 ) )
return true ;
}
return false ;
}
bool F_11 ( const char * V_44 , int V_45 )
{
struct V_46 V_47 ;
int V_48 = V_45 & V_49 ;
F_12 ( V_48 != V_45 ,
L_8 ,
V_45 ) ;
switch ( V_48 ) {
case V_50 :
case V_51 :
case V_52 :
return false ;
default:
if ( F_13 ( & V_47 , V_44 ) ) {
F_14 ( L_9 ,
V_44 ) ;
return true ;
}
}
return V_47 . V_53 ;
}
bool F_15 ( const char * V_40 , const char * V_23 , int V_54 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_42 [ V_41 ] . V_43 ; V_41 ++ ) {
if ( ! strcmp ( V_40 , V_42 [ V_41 ] . V_43 ) )
return ! V_42 [ V_41 ] . F_16 ( V_23 ,
V_54 ) ;
}
return false ;
}
bool F_17 ( struct V_1 * V_1 )
{
return V_1 -> V_19 == V_14 ||
V_1 -> V_19 == V_17 ;
}
int F_18 ( struct V_46 * V_47 , const char * V_55 ,
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
V_47 -> V_58 = F_19 ( V_58 ) ;
return V_47 -> V_58 ? 0 : - V_60 ;
}
return 0 ;
}
if ( F_10 ( V_40 + 1 ) ) {
V_47 -> V_61 = true ;
V_40 -= 3 ;
}
if ( V_40 > V_58 )
V_47 -> V_53 = ! strncmp ( V_40 , L_14 , 3 ) ;
if ( V_56 ) {
if ( V_47 -> V_53 ) {
if ( F_20 ( & V_47 -> V_58 , L_15 , ( int ) ( V_40 - V_58 ) , V_58 ) == - 1 )
return - V_60 ;
} else {
if ( F_20 ( & V_47 -> V_58 , L_3 , V_58 ) == - 1 )
return - V_60 ;
}
F_21 ( V_47 -> V_58 , '-' , '_' ) ;
}
if ( V_57 && V_47 -> V_61 ) {
V_47 -> V_40 = F_19 ( V_40 + 4 ) ;
if ( ! V_47 -> V_40 ) {
free ( ( void * ) V_47 -> V_58 ) ;
return - V_60 ;
}
}
return 0 ;
}
static void F_22 ( struct V_1 * V_1 )
{
F_23 ( & V_1 -> V_62 . V_63 , & V_64 ) ;
V_65 ++ ;
}
static void F_24 ( struct V_1 * V_1 )
{
F_25 ( & V_1 -> V_62 . V_63 ) ;
F_12 ( V_65 <= 0 ,
L_16 ) ;
V_65 -- ;
}
static int F_26 ( char * V_58 )
{
int V_66 ;
char V_67 [ V_68 ] ;
do {
V_66 = F_27 ( V_58 , V_69 ) ;
if ( V_66 >= 0 )
return V_66 ;
F_28 ( L_17 ,
F_29 ( V_70 , V_67 , sizeof( V_67 ) ) ) ;
if ( ! V_65 || V_70 != V_71 )
break;
F_30 () ;
} while ( 1 );
return - 1 ;
}
static int F_31 ( struct V_1 * V_1 , struct V_72 * V_72 )
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
if ( ! F_4 ( V_58 ) )
return - V_75 ;
V_66 = F_26 ( V_58 ) ;
free ( V_58 ) ;
return V_66 ;
}
static int F_32 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
int V_66 = F_31 ( V_1 , V_72 ) ;
if ( V_66 >= 0 ) {
F_22 ( V_1 ) ;
F_33 () ;
}
return V_66 ;
}
static void F_34 ( struct V_1 * V_1 )
{
if ( V_1 -> V_62 . V_66 >= 0 ) {
F_35 ( V_1 -> V_62 . V_66 ) ;
V_1 -> V_62 . V_66 = - 1 ;
V_1 -> V_62 . V_76 = 0 ;
F_24 ( V_1 ) ;
}
}
static void F_36 ( struct V_1 * V_1 )
{
F_34 ( V_1 ) ;
}
static void F_30 ( void )
{
struct V_1 * V_1 ;
V_1 = F_37 ( & V_64 , struct V_1 , V_62 . V_63 ) ;
F_36 ( V_1 ) ;
}
static T_2 F_38 ( void )
{
struct V_77 V_78 ;
T_2 V_79 = 0 ;
if ( F_39 ( V_80 , & V_78 ) == 0 ) {
if ( V_78 . V_81 == V_82 )
V_79 = V_78 . V_81 ;
else
V_79 = V_78 . V_81 / 2 ;
} else {
F_14 ( L_18 ) ;
V_79 = 1 ;
}
return V_79 ;
}
void F_40 ( void )
{
V_83 = 0 ;
}
static bool F_41 ( void )
{
if ( ! V_83 )
V_83 = F_38 () ;
if ( V_83 == V_82 )
return true ;
return V_83 > ( T_2 ) V_65 ;
}
static void F_33 ( void )
{
bool V_84 = F_41 () ;
if ( ! V_84 )
F_30 () ;
}
void F_42 ( struct V_1 * V_1 )
{
F_43 ( & V_85 ) ;
F_36 ( V_1 ) ;
F_44 ( & V_85 ) ;
}
static void F_45 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
enum V_21 V_86 [] = {
V_7 ,
V_12 ,
V_20 ,
} ;
int V_41 = 0 ;
if ( V_1 -> V_62 . V_66 >= 0 )
return;
if ( V_1 -> V_74 != V_20 ) {
V_1 -> V_62 . V_66 = F_32 ( V_1 , V_72 ) ;
goto V_87;
}
do {
V_1 -> V_74 = V_86 [ V_41 ++ ] ;
V_1 -> V_62 . V_66 = F_32 ( V_1 , V_72 ) ;
if ( V_1 -> V_62 . V_66 >= 0 )
goto V_87;
} while ( V_1 -> V_74 != V_20 );
V_87:
if ( V_1 -> V_62 . V_66 >= 0 )
V_1 -> V_62 . V_88 = V_89 ;
else
V_1 -> V_62 . V_88 = V_90 ;
}
int F_46 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
if ( V_1 -> V_62 . V_88 == V_90 )
return - 1 ;
if ( F_43 ( & V_85 ) < 0 )
return - 1 ;
F_45 ( V_1 , V_72 ) ;
if ( V_1 -> V_62 . V_66 < 0 )
F_44 ( & V_85 ) ;
return V_1 -> V_62 . V_66 ;
}
void F_47 ( struct V_1 * V_1 V_91 )
{
F_44 ( & V_85 ) ;
}
bool F_48 ( struct V_1 * V_1 , enum V_92 V_93 )
{
T_3 V_94 = 1 << V_93 ;
if ( V_1 -> V_62 . V_95 & V_94 )
return true ;
V_1 -> V_62 . V_95 |= V_94 ;
return false ;
}
static void
F_49 ( struct V_1 * V_1 )
{
struct V_96 * V_97 = & V_1 -> V_62 . V_98 ;
struct V_99 * V_100 = F_50 ( V_97 ) ;
F_43 ( & V_1 -> V_101 ) ;
while ( V_100 ) {
struct V_102 * V_98 ;
V_98 = F_51 ( V_100 , struct V_102 , V_99 ) ;
V_100 = F_52 ( & V_98 -> V_99 ) ;
F_53 ( & V_98 -> V_99 , V_97 ) ;
free ( V_98 ) ;
}
F_44 ( & V_1 -> V_101 ) ;
}
static struct V_102 * F_54 ( struct V_1 * V_1 , T_4 V_103 )
{
const struct V_96 * V_97 = & V_1 -> V_62 . V_98 ;
struct V_99 * const * V_104 = & V_97 -> V_99 ;
const struct V_99 * V_105 = NULL ;
struct V_102 * V_98 ;
while ( * V_104 != NULL ) {
T_4 V_106 ;
V_105 = * V_104 ;
V_98 = F_51 ( V_105 , struct V_102 , V_99 ) ;
V_106 = V_98 -> V_103 + V_107 ;
if ( V_103 < V_98 -> V_103 )
V_104 = & ( * V_104 ) -> V_108 ;
else if ( V_103 >= V_106 )
V_104 = & ( * V_104 ) -> V_109 ;
else
return V_98 ;
}
return NULL ;
}
static struct V_102 *
F_55 ( struct V_1 * V_1 , struct V_102 * V_110 )
{
struct V_96 * V_97 = & V_1 -> V_62 . V_98 ;
struct V_99 * * V_104 = & V_97 -> V_99 ;
struct V_99 * V_105 = NULL ;
struct V_102 * V_98 ;
T_4 V_103 = V_110 -> V_103 ;
F_43 ( & V_1 -> V_101 ) ;
while ( * V_104 != NULL ) {
T_4 V_106 ;
V_105 = * V_104 ;
V_98 = F_51 ( V_105 , struct V_102 , V_99 ) ;
V_106 = V_98 -> V_103 + V_107 ;
if ( V_103 < V_98 -> V_103 )
V_104 = & ( * V_104 ) -> V_108 ;
else if ( V_103 >= V_106 )
V_104 = & ( * V_104 ) -> V_109 ;
else
goto V_87;
}
F_56 ( & V_110 -> V_99 , V_105 , V_104 ) ;
F_57 ( & V_110 -> V_99 , V_97 ) ;
V_98 = NULL ;
V_87:
F_44 ( & V_1 -> V_101 ) ;
return V_98 ;
}
static T_5
F_58 ( struct V_102 * V_98 , T_4 V_103 ,
T_6 * V_62 , T_4 V_24 )
{
T_4 V_111 = V_103 - V_98 -> V_103 ;
T_4 V_112 = F_59 ( V_98 -> V_24 - V_111 , V_24 ) ;
memcpy ( V_62 , V_98 -> V_62 + V_111 , V_112 ) ;
return V_112 ;
}
static T_5
F_60 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_103 , T_6 * V_62 , T_5 V_24 )
{
struct V_102 * V_98 ;
struct V_102 * V_113 ;
T_5 V_27 ;
do {
T_4 V_111 ;
V_98 = F_61 ( sizeof( * V_98 ) + V_107 ) ;
if ( ! V_98 )
return - V_60 ;
F_43 ( & V_85 ) ;
F_45 ( V_1 , V_72 ) ;
if ( V_1 -> V_62 . V_66 < 0 ) {
V_27 = - V_70 ;
V_1 -> V_62 . V_88 = V_90 ;
break;
}
V_111 = V_103 & V_114 ;
V_27 = F_62 ( V_1 -> V_62 . V_66 , V_98 -> V_62 , V_107 , V_111 ) ;
if ( V_27 <= 0 )
break;
V_98 -> V_103 = V_111 ;
V_98 -> V_24 = V_27 ;
} while ( 0 );
F_44 ( & V_85 ) ;
if ( V_27 > 0 ) {
V_113 = F_55 ( V_1 , V_98 ) ;
if ( V_113 ) {
free ( V_98 ) ;
V_98 = V_113 ;
}
V_27 = F_58 ( V_98 , V_103 , V_62 , V_24 ) ;
}
if ( V_27 <= 0 )
free ( V_98 ) ;
return V_27 ;
}
static T_5 F_63 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_103 , T_6 * V_62 , T_5 V_24 )
{
struct V_102 * V_98 ;
V_98 = F_54 ( V_1 , V_103 ) ;
if ( V_98 )
return F_58 ( V_98 , V_103 , V_62 , V_24 ) ;
else
return F_60 ( V_1 , V_72 , V_103 , V_62 , V_24 ) ;
}
static T_5 F_64 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_103 , T_6 * V_62 , T_5 V_24 )
{
T_5 V_115 = 0 ;
T_6 * V_104 = V_62 ;
do {
T_5 V_27 ;
V_27 = F_63 ( V_1 , V_72 , V_103 , V_104 , V_24 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! V_27 )
break;
F_65 ( V_27 > V_24 ) ;
V_115 += V_27 ;
V_104 += V_27 ;
V_103 += V_27 ;
V_24 -= V_27 ;
} while ( V_24 );
return V_115 ;
}
static int F_66 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
int V_27 = 0 ;
struct V_116 V_117 ;
char V_67 [ V_68 ] ;
if ( V_1 -> V_62 . V_76 )
return 0 ;
if ( V_1 -> V_62 . V_88 == V_90 )
return - 1 ;
F_43 ( & V_85 ) ;
F_45 ( V_1 , V_72 ) ;
if ( V_1 -> V_62 . V_66 < 0 ) {
V_27 = - V_70 ;
V_1 -> V_62 . V_88 = V_90 ;
goto V_87;
}
if ( F_67 ( V_1 -> V_62 . V_66 , & V_117 ) < 0 ) {
V_27 = - V_70 ;
F_14 ( L_19 ,
F_29 ( V_70 , V_67 , sizeof( V_67 ) ) ) ;
V_1 -> V_62 . V_88 = V_90 ;
goto V_87;
}
V_1 -> V_62 . V_76 = V_117 . V_118 ;
V_87:
F_44 ( & V_85 ) ;
return V_27 ;
}
T_7 F_68 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
if ( F_66 ( V_1 , V_72 ) )
return - 1 ;
return V_1 -> V_62 . V_76 ;
}
static T_5 F_69 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_103 , T_6 * V_62 , T_5 V_24 )
{
if ( F_66 ( V_1 , V_72 ) )
return - 1 ;
if ( V_103 > V_1 -> V_62 . V_76 )
return - 1 ;
if ( V_103 + V_24 < V_103 )
return - 1 ;
return F_64 ( V_1 , V_72 , V_103 , V_62 , V_24 ) ;
}
T_5 F_70 ( struct V_1 * V_1 , struct V_72 * V_72 ,
T_4 V_103 , T_6 * V_62 , T_5 V_24 )
{
if ( V_1 -> V_62 . V_88 == V_90 )
return - 1 ;
return F_69 ( V_1 , V_72 , V_103 , V_62 , V_24 ) ;
}
T_5 F_71 ( struct V_1 * V_1 , struct V_119 * V_119 ,
struct V_72 * V_72 , T_4 V_120 ,
T_6 * V_62 , T_5 V_24 )
{
T_4 V_103 = V_119 -> V_121 ( V_119 , V_120 ) ;
return F_70 ( V_1 , V_72 , V_103 , V_62 , V_24 ) ;
}
struct V_119 * F_72 ( const char * V_58 )
{
struct V_119 * V_119 = NULL ;
struct V_1 * V_1 = F_73 ( V_58 ) ;
if ( V_1 )
V_119 = F_74 ( 0 , V_1 , V_122 ) ;
return V_119 ;
}
struct V_1 * F_75 ( struct V_72 * V_72 , const char * V_58 ,
const char * V_123 , int V_124 )
{
struct V_1 * V_1 = F_76 ( V_72 , V_58 ) ;
if ( V_1 != NULL ) {
F_77 ( V_1 , V_123 , false ) ;
V_1 -> V_125 = V_124 ;
}
return V_1 ;
}
static struct V_1 * F_78 ( struct V_96 * V_97 ,
struct V_1 * V_1 , const char * V_58 )
{
struct V_99 * * V_104 = & V_97 -> V_99 ;
struct V_99 * V_105 = NULL ;
if ( ! V_58 )
V_58 = V_1 -> V_30 ;
while ( * V_104 ) {
struct V_1 * V_126 = F_51 ( * V_104 , struct V_1 , V_99 ) ;
int V_127 = strcmp ( V_58 , V_126 -> V_30 ) ;
V_105 = * V_104 ;
if ( V_127 == 0 ) {
if ( ! V_1 || ( V_1 == V_126 ) )
return V_126 ;
V_127 = strcmp ( V_1 -> V_123 , V_126 -> V_123 ) ;
if ( V_127 == 0 ) {
F_14 ( L_20 , V_58 ) ;
return NULL ;
}
}
if ( V_127 < 0 )
V_104 = & V_105 -> V_108 ;
else
V_104 = & V_105 -> V_109 ;
}
if ( V_1 ) {
F_56 ( & V_1 -> V_99 , V_105 , V_104 ) ;
F_57 ( & V_1 -> V_99 , V_97 ) ;
V_1 -> V_97 = V_97 ;
}
return NULL ;
}
static inline struct V_1 * F_79 ( struct V_96 * V_97 ,
const char * V_58 )
{
return F_78 ( V_97 , NULL , V_58 ) ;
}
void F_80 ( struct V_1 * V_1 , const char * V_58 , bool V_128 )
{
struct V_96 * V_97 = V_1 -> V_97 ;
if ( V_58 == NULL )
return;
if ( V_1 -> V_129 )
free ( ( char * ) V_1 -> V_30 ) ;
if ( V_97 ) {
F_53 ( & V_1 -> V_99 , V_97 ) ;
F_81 ( & V_1 -> V_99 ) ;
V_1 -> V_97 = NULL ;
}
V_1 -> V_30 = V_58 ;
V_1 -> V_33 = strlen ( V_58 ) ;
V_1 -> V_129 = V_128 ;
if ( V_97 )
F_78 ( V_97 , V_1 , NULL ) ;
}
void F_77 ( struct V_1 * V_1 , const char * V_58 , bool V_128 )
{
if ( V_58 == NULL )
return;
if ( V_1 -> V_130 )
free ( ( char * ) V_1 -> V_123 ) ;
V_1 -> V_123 = V_58 ;
V_1 -> V_131 = strlen ( V_58 ) ;
V_1 -> V_130 = V_128 ;
}
static void F_82 ( struct V_1 * V_1 )
{
char * V_132 , * V_133 = F_19 ( V_1 -> V_30 ) ;
if ( ! V_133 )
return;
V_132 = F_19 ( F_83 ( V_133 ) ) ;
free ( V_133 ) ;
if ( ! V_132 )
return;
F_77 ( V_1 , V_132 , true ) ;
}
int F_84 ( const struct V_1 * V_1 )
{
if ( ! V_1 )
return strlen ( L_21 ) ;
if ( V_134 )
return V_1 -> V_33 ;
return V_1 -> V_131 ;
}
bool F_85 ( const struct V_1 * V_1 , enum V_135 type )
{
return V_1 -> V_136 & ( 1 << type ) ;
}
bool F_86 ( const struct V_1 * V_1 , enum V_135 type )
{
return V_1 -> V_137 & ( 1 << type ) ;
}
void F_87 ( struct V_1 * V_1 , enum V_135 type )
{
V_1 -> V_137 |= ( 1 << type ) ;
}
struct V_1 * F_73 ( const char * V_58 )
{
struct V_1 * V_1 = calloc ( 1 , sizeof( * V_1 ) + strlen ( V_58 ) + 1 ) ;
if ( V_1 != NULL ) {
int V_41 ;
strcpy ( V_1 -> V_58 , V_58 ) ;
F_80 ( V_1 , V_1 -> V_58 , false ) ;
F_77 ( V_1 , V_1 -> V_58 , false ) ;
for ( V_41 = 0 ; V_41 < V_138 ; ++ V_41 )
V_1 -> V_139 [ V_41 ] = V_1 -> V_140 [ V_41 ] = V_141 ;
V_1 -> V_62 . V_98 = V_141 ;
V_1 -> V_62 . V_66 = - 1 ;
V_1 -> V_62 . V_88 = V_142 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_74 = V_20 ;
V_1 -> V_143 = ( sizeof( void * ) == 8 ) ;
V_1 -> V_136 = 0 ;
V_1 -> V_144 = 0 ;
V_1 -> V_137 = 0 ;
V_1 -> V_34 = 0 ;
V_1 -> V_145 = 1 ;
V_1 -> V_146 = 1 ;
V_1 -> V_125 = V_147 ;
V_1 -> V_148 = V_149 ;
F_81 ( & V_1 -> V_99 ) ;
V_1 -> V_97 = NULL ;
F_88 ( & V_1 -> V_150 ) ;
F_88 ( & V_1 -> V_62 . V_63 ) ;
F_89 ( & V_1 -> V_101 , NULL ) ;
F_90 ( & V_1 -> V_151 , 1 ) ;
}
return V_1 ;
}
void F_91 ( struct V_1 * V_1 )
{
int V_41 ;
if ( ! F_92 ( & V_1 -> V_99 ) )
F_14 ( L_22 ,
V_1 -> V_30 ) ;
for ( V_41 = 0 ; V_41 < V_138 ; ++ V_41 )
F_93 ( & V_1 -> V_139 [ V_41 ] ) ;
if ( V_1 -> V_130 ) {
F_94 ( ( char * * ) & V_1 -> V_123 ) ;
V_1 -> V_130 = false ;
}
if ( V_1 -> V_129 ) {
F_94 ( ( char * * ) & V_1 -> V_30 ) ;
V_1 -> V_129 = false ;
}
F_42 ( V_1 ) ;
F_95 ( V_1 -> V_152 ) ;
F_49 ( V_1 ) ;
F_96 ( V_1 ) ;
F_94 ( & V_1 -> V_153 ) ;
F_97 ( & V_1 -> V_101 ) ;
free ( V_1 ) ;
}
struct V_1 * F_98 ( struct V_1 * V_1 )
{
if ( V_1 )
F_99 ( & V_1 -> V_151 ) ;
return V_1 ;
}
void F_100 ( struct V_1 * V_1 )
{
if ( V_1 && F_101 ( & V_1 -> V_151 ) )
F_91 ( V_1 ) ;
}
void F_102 ( struct V_1 * V_1 , void * V_35 )
{
memcpy ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) ;
V_1 -> V_34 = 1 ;
}
bool F_103 ( const struct V_1 * V_1 , T_6 * V_35 )
{
return memcmp ( V_1 -> V_35 , V_35 , sizeof( V_1 -> V_35 ) ) == 0 ;
}
void F_104 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
char V_55 [ V_73 ] ;
if ( F_105 ( V_72 ) )
return;
sprintf ( V_55 , L_23 , V_72 -> V_22 ) ;
if ( F_106 ( V_55 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
}
int F_107 ( struct V_1 * V_1 ,
const char * V_22 )
{
char V_23 [ V_73 ] ;
const char * V_58 = V_1 -> V_123 + 1 ;
snprintf ( V_23 , sizeof( V_23 ) ,
L_24 ,
V_22 , ( int ) strlen ( V_58 ) - 1 , V_58 ) ;
if ( F_106 ( V_23 , V_1 -> V_35 ,
sizeof( V_1 -> V_35 ) ) == 0 )
V_1 -> V_34 = true ;
return 0 ;
}
bool F_108 ( struct V_154 * V_155 , bool V_156 )
{
bool V_157 = false ;
struct V_1 * V_158 ;
F_109 (pos, head, node) {
if ( V_156 && ! V_158 -> V_159 && ! F_110 ( V_158 ) )
continue;
if ( V_158 -> V_34 ) {
V_157 = true ;
continue;
}
if ( F_111 ( V_158 -> V_30 , V_158 -> V_35 ,
sizeof( V_158 -> V_35 ) ) > 0 ) {
V_157 = true ;
V_158 -> V_34 = true ;
}
}
return V_157 ;
}
void F_112 ( struct V_160 * V_160 , struct V_1 * V_1 )
{
F_23 ( & V_1 -> V_150 , & V_160 -> V_155 ) ;
F_78 ( & V_160 -> V_97 , V_1 , NULL ) ;
F_98 ( V_1 ) ;
}
void F_113 ( struct V_160 * V_160 , struct V_1 * V_1 )
{
F_114 ( & V_160 -> V_101 ) ;
F_112 ( V_160 , V_1 ) ;
F_115 ( & V_160 -> V_101 ) ;
}
struct V_1 * F_116 ( struct V_160 * V_160 , const char * V_58 , bool V_161 )
{
struct V_1 * V_158 ;
if ( V_161 ) {
F_109 (pos, &dsos->head, node)
if ( strcmp ( V_158 -> V_123 , V_58 ) == 0 )
return V_158 ;
return NULL ;
}
return F_79 ( & V_160 -> V_97 , V_58 ) ;
}
struct V_1 * F_117 ( struct V_160 * V_160 , const char * V_58 , bool V_161 )
{
struct V_1 * V_1 ;
F_118 ( & V_160 -> V_101 ) ;
V_1 = F_116 ( V_160 , V_58 , V_161 ) ;
F_115 ( & V_160 -> V_101 ) ;
return V_1 ;
}
struct V_1 * F_119 ( struct V_160 * V_160 , const char * V_58 )
{
struct V_1 * V_1 = F_73 ( V_58 ) ;
if ( V_1 != NULL ) {
F_112 ( V_160 , V_1 ) ;
F_82 ( V_1 ) ;
F_100 ( V_1 ) ;
}
return V_1 ;
}
struct V_1 * F_120 ( struct V_160 * V_160 , const char * V_58 )
{
struct V_1 * V_1 = F_116 ( V_160 , V_58 , false ) ;
return V_1 ? V_1 : F_119 ( V_160 , V_58 ) ;
}
struct V_1 * F_121 ( struct V_160 * V_160 , const char * V_58 )
{
struct V_1 * V_1 ;
F_114 ( & V_160 -> V_101 ) ;
V_1 = F_98 ( F_120 ( V_160 , V_58 ) ) ;
F_115 ( & V_160 -> V_101 ) ;
return V_1 ;
}
T_1 F_122 ( struct V_154 * V_155 , T_8 * V_162 ,
bool (F_123)( struct V_1 * V_1 , int V_163 ) , int V_163 )
{
struct V_1 * V_158 ;
T_1 V_27 = 0 ;
F_109 (pos, head, node) {
if ( F_123 && F_123 ( V_158 , V_163 ) )
continue;
V_27 += F_124 ( V_158 , V_162 ) ;
V_27 += fprintf ( V_162 , L_25 , V_158 -> V_30 ) ;
}
return V_27 ;
}
T_1 F_125 ( struct V_154 * V_155 , T_8 * V_162 )
{
struct V_1 * V_158 ;
T_1 V_27 = 0 ;
F_109 (pos, head, node) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_138 ; ++ V_41 )
V_27 += F_126 ( V_158 , V_41 , V_162 ) ;
}
return V_27 ;
}
T_1 F_124 ( struct V_1 * V_1 , T_8 * V_162 )
{
char V_164 [ V_26 ] ;
F_8 ( V_1 -> V_35 , sizeof( V_1 -> V_35 ) , V_164 ) ;
return fprintf ( V_162 , L_3 , V_164 ) ;
}
T_1 F_126 ( struct V_1 * V_1 , enum V_135 type , T_8 * V_162 )
{
struct V_99 * V_165 ;
T_1 V_27 = fprintf ( V_162 , L_26 , V_1 -> V_123 ) ;
if ( V_1 -> V_123 != V_1 -> V_30 )
V_27 += fprintf ( V_162 , L_27 , V_1 -> V_30 ) ;
V_27 += fprintf ( V_162 , L_28 , V_166 [ type ] ,
F_85 ( V_1 , type ) ? L_4 : L_29 ) ;
V_27 += F_124 ( V_1 , V_162 ) ;
V_27 += fprintf ( V_162 , L_30 ) ;
for ( V_165 = F_50 ( & V_1 -> V_139 [ type ] ) ; V_165 ; V_165 = F_52 ( V_165 ) ) {
struct V_167 * V_158 = F_51 ( V_165 , struct V_167 , V_99 ) ;
V_27 += F_127 ( V_158 , V_162 ) ;
}
return V_27 ;
}
enum V_124 F_128 ( struct V_1 * V_1 , struct V_72 * V_72 )
{
int V_66 ;
enum V_124 type = V_168 ;
V_66 = F_46 ( V_1 , V_72 ) ;
if ( V_66 >= 0 ) {
type = F_129 ( V_66 ) ;
F_47 ( V_1 ) ;
}
return type ;
}
int F_130 ( struct V_1 * V_1 , char * V_169 , T_1 V_170 )
{
int V_171 , V_172 = V_1 -> V_173 ;
static const char * V_174 [] = {
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
} ;
F_65 ( V_170 == 0 ) ;
if ( V_172 >= 0 ) {
const char * V_175 = F_29 ( V_172 , V_169 , V_170 ) ;
if ( V_175 != V_169 )
F_7 ( V_169 , V_170 , L_3 , V_175 ) ;
return 0 ;
}
if ( V_172 < V_176 || V_172 >= V_177 )
return - 1 ;
V_171 = V_172 - V_176 ;
F_7 ( V_169 , V_170 , L_3 , V_174 [ V_171 ] ) ;
return 0 ;
}
