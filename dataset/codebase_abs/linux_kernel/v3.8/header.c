int F_1 ( T_1 V_1 , const char * V_2 )
{
struct V_3 * V_4 ;
if ( strlen ( V_2 ) > V_5 )
F_2 ( L_1 , V_2 ) ;
V_4 = realloc ( V_6 , ( V_7 + 1 ) * sizeof( * V_6 ) ) ;
if ( V_4 == NULL )
return - V_8 ;
V_6 = V_4 ;
memset ( & V_6 [ V_7 ] , 0 , sizeof( struct V_3 ) ) ;
V_6 [ V_7 ] . V_9 = V_1 ;
strncpy ( V_6 [ V_7 ] . V_2 , V_2 , V_5 - 1 ) ;
V_7 ++ ;
return 0 ;
}
char * F_3 ( T_1 V_1 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
if ( V_6 [ V_10 ] . V_9 == V_1 )
return V_6 [ V_10 ] . V_2 ;
}
return NULL ;
}
void F_4 ( struct V_11 * V_12 , int V_13 )
{
F_5 ( V_13 , V_12 -> V_14 ) ;
}
void F_6 ( struct V_11 * V_12 , int V_13 )
{
F_7 ( V_13 , V_12 -> V_14 ) ;
}
bool F_8 ( const struct V_11 * V_12 , int V_13 )
{
return F_9 ( V_13 , V_12 -> V_14 ) ;
}
static int F_10 ( int V_15 , const void * V_16 , T_2 V_17 )
{
while ( V_17 ) {
int V_18 = F_11 ( V_15 , V_16 , V_17 ) ;
if ( V_18 < 0 )
return - V_19 ;
V_17 -= V_18 ;
V_16 += V_18 ;
}
return 0 ;
}
static int F_12 ( int V_15 , const void * V_20 , T_2 V_21 ,
T_2 V_22 )
{
static const char V_23 [ V_24 ] ;
int V_25 = F_10 ( V_15 , V_20 , V_21 ) ;
if ( ! V_25 )
V_25 = F_10 ( V_15 , V_23 , V_22 - V_21 ) ;
return V_25 ;
}
static int F_13 ( int V_15 , const char * V_26 )
{
T_3 V_27 , V_28 ;
int V_18 ;
V_28 = strlen ( V_26 ) + 1 ;
V_27 = F_14 ( V_28 , V_24 ) ;
V_18 = F_10 ( V_15 , & V_27 , sizeof( V_27 ) ) ;
if ( V_18 < 0 )
return V_18 ;
return F_12 ( V_15 , V_26 , V_28 , V_27 ) ;
}
static char * F_15 ( int V_15 , struct V_11 * V_29 )
{
T_4 V_30 , V_18 ;
T_3 V_27 ;
char * V_16 ;
V_30 = F_16 ( V_15 , & V_27 , sizeof( V_27 ) ) ;
if ( V_30 < ( T_4 ) sizeof( V_27 ) )
return NULL ;
if ( V_29 -> V_31 )
V_27 = F_17 ( V_27 ) ;
V_16 = malloc ( V_27 ) ;
if ( ! V_16 )
return NULL ;
V_18 = F_16 ( V_15 , V_16 , V_27 ) ;
if ( V_18 == ( T_4 ) V_27 ) {
return V_16 ;
}
free ( V_16 ) ;
return NULL ;
}
int
F_18 ( int V_32 , const char * * V_33 )
{
int V_10 ;
if ( V_34 )
return 0 ;
V_35 = ( T_3 ) V_32 ;
V_34 = calloc ( V_32 , sizeof( char * ) ) ;
if ( ! V_34 )
return - V_8 ;
for ( V_10 = 0 ; V_10 < V_32 ; V_10 ++ )
V_34 [ V_10 ] = V_33 [ V_10 ] ;
return 0 ;
}
static int F_19 ( char * V_2 , T_2 V_36 , T_5 * V_37 ,
T_6 V_38 , T_7 V_39 , int V_15 )
{
int V_25 ;
struct V_40 V_41 ;
T_2 V_27 ;
V_27 = V_36 + 1 ;
V_27 = F_14 ( V_27 , V_24 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
memcpy ( & V_41 . V_37 , V_37 , V_42 ) ;
V_41 . V_38 = V_38 ;
V_41 . V_12 . V_39 = V_39 ;
V_41 . V_12 . V_17 = sizeof( V_41 ) + V_27 ;
V_25 = F_10 ( V_15 , & V_41 , sizeof( V_41 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return F_12 ( V_15 , V_2 , V_36 + 1 , V_27 ) ;
}
static int F_20 ( struct V_43 * V_44 , T_6 V_38 ,
T_7 V_39 , int V_15 )
{
struct V_45 * V_46 ;
F_21 (pos, head) {
int V_25 ;
char * V_2 ;
T_2 V_36 ;
if ( ! V_46 -> V_47 )
continue;
if ( F_22 ( V_46 -> V_48 ) ) {
V_2 = ( char * ) V_49 ;
V_36 = sizeof( V_49 ) + 1 ;
} else {
V_2 = V_46 -> V_50 ;
V_36 = V_46 -> V_51 + 1 ;
}
V_25 = F_19 ( V_2 , V_36 , V_46 -> V_37 ,
V_38 , V_39 , V_15 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
static int F_23 ( struct V_52 * V_52 , int V_15 )
{
int V_25 ;
T_7 V_53 = V_54 ,
V_55 = V_56 ;
if ( ! F_24 ( V_52 ) ) {
V_53 = V_57 ;
V_55 = V_58 ;
}
V_25 = F_20 ( & V_52 -> V_59 , V_52 -> V_38 ,
V_53 , V_15 ) ;
if ( V_25 == 0 )
V_25 = F_20 ( & V_52 -> V_60 ,
V_52 -> V_38 , V_55 , V_15 ) ;
return V_25 ;
}
static int F_25 ( struct V_11 * V_12 , int V_15 )
{
struct V_61 * V_62 = F_26 ( V_12 ,
struct V_61 , V_12 ) ;
struct V_63 * V_64 ;
int V_25 = F_23 ( & V_62 -> V_65 , V_15 ) ;
if ( V_25 )
return V_25 ;
for ( V_64 = F_27 ( & V_62 -> V_66 ) ; V_64 ; V_64 = F_28 ( V_64 ) ) {
struct V_52 * V_46 = F_29 ( V_64 , struct V_52 , V_63 ) ;
V_25 = F_23 ( V_46 , V_15 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
int F_30 ( const char * V_67 , const char * V_68 ,
const char * V_2 , bool V_69 , bool V_70 )
{
const T_2 V_17 = V_71 ;
char * V_72 , * V_73 = F_31 ( V_17 ) ,
* V_74 = F_31 ( V_17 ) , * V_75 ;
int V_27 , V_25 = - 1 ;
bool V_76 = V_69 || V_70 ;
if ( V_69 ) {
if ( V_77 . V_78 ) {
F_32 ( L_2 ) ;
return 0 ;
}
V_72 = ( char * ) V_2 ;
} else
V_72 = F_33 ( V_2 , NULL ) ;
if ( V_72 == NULL || V_73 == NULL || V_74 == NULL )
goto V_79;
V_27 = F_34 ( V_73 , V_17 , L_3 ,
V_68 , V_76 ? L_4 : L_5 ,
V_70 ? V_49 : V_72 ) ;
if ( F_35 ( V_73 , 0755 ) )
goto V_79;
snprintf ( V_73 + V_27 , V_17 - V_27 , L_6 , V_67 ) ;
if ( F_36 ( V_73 , V_80 ) ) {
if ( V_69 ) {
if ( F_37 ( L_7 , V_73 ) )
goto V_79;
} else if ( F_38 ( V_72 , V_73 ) && F_37 ( V_2 , V_73 ) )
goto V_79;
}
V_27 = F_34 ( V_74 , V_17 , L_8 ,
V_68 , V_67 ) ;
if ( F_36 ( V_74 , V_81 ) && F_35 ( V_74 , 0755 ) )
goto V_79;
snprintf ( V_74 + V_27 , V_17 - V_27 , L_6 , V_67 + 2 ) ;
V_75 = V_73 + strlen ( V_68 ) - 5 ;
memcpy ( V_75 , L_9 , 5 ) ;
if ( F_39 ( V_75 , V_74 ) == 0 )
V_25 = 0 ;
V_79:
if ( ! V_69 )
free ( V_72 ) ;
free ( V_73 ) ;
free ( V_74 ) ;
return V_25 ;
}
static int F_40 ( const T_5 * V_37 , T_2 V_82 ,
const char * V_2 , const char * V_68 ,
bool V_69 , bool V_70 )
{
char V_67 [ V_42 * 2 + 1 ] ;
F_41 ( V_37 , V_82 , V_67 ) ;
return F_30 ( V_67 , V_68 , V_2 ,
V_69 , V_70 ) ;
}
int F_42 ( const char * V_67 , const char * V_68 )
{
const T_2 V_17 = V_71 ;
char * V_73 = F_31 ( V_17 ) ,
* V_74 = F_31 ( V_17 ) ;
int V_25 = - 1 ;
if ( V_73 == NULL || V_74 == NULL )
goto V_79;
snprintf ( V_74 , V_17 , L_10 ,
V_68 , V_67 , V_67 + 2 ) ;
if ( F_36 ( V_74 , V_80 ) )
goto V_79;
if ( F_43 ( V_74 , V_73 , V_17 - 1 ) < 0 )
goto V_79;
if ( F_44 ( V_74 ) )
goto V_79;
snprintf ( V_74 , V_17 , L_10 ,
V_68 , V_67 , V_73 ) ;
if ( F_44 ( V_74 ) )
goto V_79;
V_25 = 0 ;
V_79:
free ( V_73 ) ;
free ( V_74 ) ;
return V_25 ;
}
static int F_45 ( struct V_45 * V_45 , const char * V_68 )
{
bool V_69 = V_45 -> V_83 && V_45 -> V_50 [ 0 ] != '/' ;
bool V_70 = F_22 ( V_45 -> V_48 ) ;
return F_40 ( V_45 -> V_37 , sizeof( V_45 -> V_37 ) ,
V_45 -> V_50 , V_68 ,
V_69 , V_70 ) ;
}
static int F_46 ( struct V_43 * V_44 , const char * V_68 )
{
struct V_45 * V_46 ;
int V_25 = 0 ;
F_21 (pos, head)
if ( F_45 ( V_46 , V_68 ) )
V_25 = - 1 ;
return V_25 ;
}
static int F_47 ( struct V_52 * V_52 , const char * V_68 )
{
int V_18 = F_46 ( & V_52 -> V_59 , V_68 ) ;
V_18 |= F_46 ( & V_52 -> V_60 , V_68 ) ;
return V_18 ;
}
static int F_48 ( struct V_61 * V_62 )
{
struct V_63 * V_64 ;
int V_18 ;
char V_68 [ V_71 ] ;
snprintf ( V_68 , sizeof( V_68 ) , L_11 , V_84 ) ;
if ( F_49 ( V_68 , 0755 ) != 0 && V_19 != V_85 )
return - 1 ;
V_18 = F_47 ( & V_62 -> V_65 , V_68 ) ;
for ( V_64 = F_27 ( & V_62 -> V_66 ) ; V_64 ; V_64 = F_28 ( V_64 ) ) {
struct V_52 * V_46 = F_29 ( V_64 , struct V_52 , V_63 ) ;
V_18 |= F_47 ( V_46 , V_68 ) ;
}
return V_18 ? - 1 : 0 ;
}
static bool F_50 ( struct V_52 * V_52 , bool V_86 )
{
bool V_18 = F_51 ( & V_52 -> V_59 , V_86 ) ;
V_18 |= F_51 ( & V_52 -> V_60 , V_86 ) ;
return V_18 ;
}
static bool F_52 ( struct V_61 * V_62 , bool V_86 )
{
struct V_63 * V_64 ;
bool V_18 = F_50 ( & V_62 -> V_65 , V_86 ) ;
for ( V_64 = F_27 ( & V_62 -> V_66 ) ; V_64 ; V_64 = F_28 ( V_64 ) ) {
struct V_52 * V_46 = F_29 ( V_64 , struct V_52 , V_63 ) ;
V_18 |= F_50 ( V_46 , V_86 ) ;
}
return V_18 ;
}
static int F_53 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 )
{
return F_54 ( V_15 , & V_89 -> V_90 ) ;
}
static int F_55 ( int V_15 , struct V_11 * T_8 ,
struct V_88 * V_89 V_87 )
{
struct V_61 * V_62 ;
int V_25 ;
V_62 = F_26 ( T_8 , struct V_61 , V_12 ) ;
if ( ! F_52 ( V_62 , true ) )
return - 1 ;
V_25 = F_25 ( T_8 , V_15 ) ;
if ( V_25 < 0 ) {
F_32 ( L_12 ) ;
return V_25 ;
}
if ( ! V_91 )
F_48 ( V_62 ) ;
return 0 ;
}
static int F_56 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
struct V_92 V_93 ;
int V_18 ;
V_18 = F_57 ( & V_93 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_93 . V_94 ) ;
}
static int F_58 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
struct V_92 V_93 ;
int V_18 ;
V_18 = F_57 ( & V_93 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_93 . V_95 ) ;
}
static int F_59 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
struct V_92 V_93 ;
int V_18 ;
V_18 = F_57 ( & V_93 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_93 . V_52 ) ;
}
static int F_60 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
return F_13 ( V_15 , V_96 ) ;
}
static int F_61 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
#ifndef F_62
#define F_62 NULL
#endif
T_9 * V_97 ;
char * V_16 = NULL ;
char * V_98 , * V_99 ;
const char * V_100 = F_62 ;
T_2 V_27 = 0 ;
int V_18 = - 1 ;
if ( ! V_100 )
return - 1 ;
V_97 = fopen ( L_13 , L_14 ) ;
if ( ! V_97 )
return - 1 ;
while ( F_63 ( & V_16 , & V_27 , V_97 ) > 0 ) {
V_18 = strncmp ( V_16 , V_100 , strlen ( V_100 ) ) ;
if ( ! V_18 )
break;
}
if ( V_18 )
goto V_101;
V_98 = V_16 ;
V_99 = strchr ( V_16 , ':' ) ;
if ( V_99 && * ( V_99 + 1 ) == ' ' && * ( V_99 + 2 ) )
V_98 = V_99 + 2 ;
V_99 = strchr ( V_98 , '\n' ) ;
if ( V_99 )
* V_99 = '\0' ;
V_99 = V_98 ;
while ( * V_99 ) {
if ( isspace ( * V_99 ) ) {
char * V_102 = V_99 + 1 ;
char * V_103 = V_102 ;
* V_99 = ' ' ;
while ( * V_103 && isspace ( * V_103 ) )
V_103 ++ ;
if ( V_103 != ( V_99 + 1 ) )
while ( ( * V_102 ++ = * V_103 ++ ) ) ;
}
V_99 ++ ;
}
V_18 = F_13 ( V_15 , V_98 ) ;
V_101:
free ( V_16 ) ;
fclose ( V_97 ) ;
return V_18 ;
}
static int F_64 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
long V_104 ;
T_3 V_105 , V_106 ;
int V_18 ;
V_104 = F_65 ( V_107 ) ;
if ( V_104 < 0 )
return - 1 ;
V_105 = ( T_3 ) ( V_104 & V_108 ) ;
V_104 = F_65 ( V_109 ) ;
if ( V_104 < 0 )
return - 1 ;
V_106 = ( T_3 ) ( V_104 & V_108 ) ;
V_18 = F_10 ( V_15 , & V_105 , sizeof( V_105 ) ) ;
if ( V_18 < 0 )
return V_18 ;
return F_10 ( V_15 , & V_106 , sizeof( V_106 ) ) ;
}
static int F_66 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 )
{
struct V_110 * V_111 ;
T_3 V_112 , V_113 , V_30 ;
int V_18 ;
V_112 = V_89 -> V_114 ;
V_18 = F_10 ( V_15 , & V_112 , sizeof( V_112 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_30 = ( T_3 ) sizeof( V_111 -> V_115 ) ;
V_18 = F_10 ( V_15 , & V_30 , sizeof( V_30 ) ) ;
if ( V_18 < 0 )
return V_18 ;
F_67 (evsel, &evlist->entries, node) {
V_18 = F_10 ( V_15 , & V_111 -> V_115 , V_30 ) ;
if ( V_18 < 0 )
return V_18 ;
V_113 = V_111 -> V_116 ;
V_18 = F_10 ( V_15 , & V_113 , sizeof( V_113 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_15 , F_68 ( V_111 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_15 , V_111 -> V_1 , V_111 -> V_116 * sizeof( T_1 ) ) ;
if ( V_18 < 0 )
return V_18 ;
}
return 0 ;
}
static int F_69 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
char V_16 [ V_117 ] ;
char V_118 [ 32 ] ;
T_3 V_10 , V_119 ;
int V_18 ;
sprintf ( V_118 , L_15 , F_70 () ) ;
V_18 = F_43 ( V_118 , V_16 , sizeof( V_16 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
V_16 [ V_18 ] = '\0' ;
V_119 = V_35 + 1 ;
V_18 = F_10 ( V_15 , & V_119 , sizeof( V_119 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_15 , V_16 ) ;
if ( V_18 < 0 )
return V_18 ;
for ( V_10 = 0 ; V_10 < V_35 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_34 [ V_10 ] ) ;
if ( V_18 < 0 )
return V_18 ;
}
return 0 ;
}
static int F_71 ( struct V_120 * V_121 , int V_122 )
{
T_9 * V_123 ;
char V_73 [ V_117 ] ;
char * V_16 = NULL , * V_99 ;
T_2 V_27 = 0 ;
T_3 V_10 = 0 ;
int V_18 = - 1 ;
sprintf ( V_73 , V_124 , V_122 ) ;
V_123 = fopen ( V_73 , L_14 ) ;
if ( ! V_123 )
return - 1 ;
if ( F_63 ( & V_16 , & V_27 , V_123 ) <= 0 )
goto V_101;
fclose ( V_123 ) ;
V_99 = strchr ( V_16 , '\n' ) ;
if ( V_99 )
* V_99 = '\0' ;
for ( V_10 = 0 ; V_10 < V_121 -> V_125 ; V_10 ++ ) {
if ( ! strcmp ( V_16 , V_121 -> V_126 [ V_10 ] ) )
break;
}
if ( V_10 == V_121 -> V_125 ) {
V_121 -> V_126 [ V_10 ] = V_16 ;
V_121 -> V_125 ++ ;
V_16 = NULL ;
V_27 = 0 ;
}
sprintf ( V_73 , V_127 , V_122 ) ;
V_123 = fopen ( V_73 , L_14 ) ;
if ( ! V_123 )
goto V_101;
if ( F_63 ( & V_16 , & V_27 , V_123 ) <= 0 )
goto V_101;
V_99 = strchr ( V_16 , '\n' ) ;
if ( V_99 )
* V_99 = '\0' ;
for ( V_10 = 0 ; V_10 < V_121 -> V_128 ; V_10 ++ ) {
if ( ! strcmp ( V_16 , V_121 -> V_129 [ V_10 ] ) )
break;
}
if ( V_10 == V_121 -> V_128 ) {
V_121 -> V_129 [ V_10 ] = V_16 ;
V_121 -> V_128 ++ ;
V_16 = NULL ;
}
V_18 = 0 ;
V_101:
if( V_123 )
fclose ( V_123 ) ;
free ( V_16 ) ;
return V_18 ;
}
static void F_72 ( struct V_120 * V_121 )
{
T_3 V_10 ;
if ( ! V_121 )
return;
for ( V_10 = 0 ; V_10 < V_121 -> V_125 ; V_10 ++ )
free ( V_121 -> V_126 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < V_121 -> V_128 ; V_10 ++ )
free ( V_121 -> V_129 [ V_10 ] ) ;
free ( V_121 ) ;
}
static struct V_120 * F_73 ( void )
{
struct V_120 * V_121 ;
void * V_130 ;
T_3 V_104 , V_10 ;
T_2 V_30 ;
long V_131 ;
int V_18 = - 1 ;
V_131 = F_65 ( V_107 ) ;
if ( V_131 < 0 )
return NULL ;
V_104 = ( T_3 ) ( V_131 & V_108 ) ;
V_30 = V_104 * sizeof( char * ) ;
V_130 = calloc ( 1 , sizeof( * V_121 ) + 2 * V_30 ) ;
if ( ! V_130 )
return NULL ;
V_121 = V_130 ;
V_130 += sizeof( * V_121 ) ;
V_121 -> V_126 = V_130 ;
V_130 += V_30 ;
V_121 -> V_129 = V_130 ;
for ( V_10 = 0 ; V_10 < V_104 ; V_10 ++ ) {
V_18 = F_71 ( V_121 , V_10 ) ;
if ( V_18 < 0 )
break;
}
if ( V_18 ) {
F_72 ( V_121 ) ;
V_121 = NULL ;
}
return V_121 ;
}
static int F_74 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
struct V_120 * V_121 ;
T_3 V_10 ;
int V_18 ;
V_121 = F_73 () ;
if ( ! V_121 )
return - 1 ;
V_18 = F_10 ( V_15 , & V_121 -> V_125 , sizeof( V_121 -> V_125 ) ) ;
if ( V_18 < 0 )
goto V_101;
for ( V_10 = 0 ; V_10 < V_121 -> V_125 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_121 -> V_126 [ V_10 ] ) ;
if ( V_18 < 0 )
goto V_101;
}
V_18 = F_10 ( V_15 , & V_121 -> V_128 , sizeof( V_121 -> V_128 ) ) ;
if ( V_18 < 0 )
goto V_101;
for ( V_10 = 0 ; V_10 < V_121 -> V_128 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_121 -> V_129 [ V_10 ] ) ;
if ( V_18 < 0 )
break;
}
V_101:
F_72 ( V_121 ) ;
return V_18 ;
}
static int F_75 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
char * V_16 = NULL ;
T_9 * V_123 ;
T_2 V_27 = 0 ;
int V_18 = - 1 , V_119 ;
T_10 V_132 ;
V_123 = fopen ( L_16 , L_14 ) ;
if ( ! V_123 )
return - 1 ;
while ( F_63 ( & V_16 , & V_27 , V_123 ) > 0 ) {
V_18 = strncmp ( V_16 , L_17 , 9 ) ;
if ( ! V_18 )
break;
}
if ( ! V_18 ) {
V_119 = sscanf ( V_16 , L_18 V_133 , & V_132 ) ;
if ( V_119 == 1 )
V_18 = F_10 ( V_15 , & V_132 , sizeof( V_132 ) ) ;
}
free ( V_16 ) ;
fclose ( V_123 ) ;
return V_18 ;
}
static int F_76 ( int V_15 , int V_134 )
{
char V_26 [ V_117 ] ;
char V_135 [ 32 ] ;
char * V_16 = NULL , * V_99 ;
T_2 V_27 = 0 ;
T_9 * V_123 ;
T_1 V_136 , V_137 , V_132 ;
int V_18 = - 1 ;
sprintf ( V_26 , L_19 , V_134 ) ;
V_123 = fopen ( V_26 , L_14 ) ;
if ( ! V_123 )
return - 1 ;
while ( F_63 ( & V_16 , & V_27 , V_123 ) > 0 ) {
if ( ! strchr ( V_16 , ':' ) )
continue;
if ( sscanf ( V_16 , L_20 V_133 , V_135 , & V_132 ) != 2 )
goto V_101;
if ( ! strcmp ( V_135 , L_17 ) )
V_136 = V_132 ;
if ( ! strcmp ( V_135 , L_21 ) )
V_137 = V_132 ;
}
fclose ( V_123 ) ;
V_18 = F_10 ( V_15 , & V_136 , sizeof( T_1 ) ) ;
if ( V_18 )
goto V_101;
V_18 = F_10 ( V_15 , & V_137 , sizeof( T_1 ) ) ;
if ( V_18 )
goto V_101;
V_18 = - 1 ;
sprintf ( V_26 , L_22 , V_134 ) ;
V_123 = fopen ( V_26 , L_14 ) ;
if ( ! V_123 )
goto V_101;
if ( F_63 ( & V_16 , & V_27 , V_123 ) <= 0 )
goto V_101;
V_99 = strchr ( V_16 , '\n' ) ;
if ( V_99 )
* V_99 = '\0' ;
V_18 = F_13 ( V_15 , V_16 ) ;
V_101:
free ( V_16 ) ;
fclose ( V_123 ) ;
return V_18 ;
}
static int F_77 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
char * V_16 = NULL ;
T_2 V_27 = 0 ;
T_9 * V_123 ;
struct V_138 * V_139 = NULL ;
char * V_140 ;
T_3 V_104 , V_10 , V_141 ;
int V_18 = - 1 ;
V_123 = fopen ( L_23 , L_14 ) ;
if ( ! V_123 )
return - 1 ;
if ( F_63 ( & V_16 , & V_27 , V_123 ) <= 0 )
goto V_101;
V_140 = strchr ( V_16 , '\n' ) ;
if ( V_140 )
* V_140 = '\0' ;
V_139 = F_78 ( V_16 ) ;
if ( ! V_139 )
goto V_101;
V_104 = ( T_3 ) V_139 -> V_104 ;
V_18 = F_10 ( V_15 , & V_104 , sizeof( V_104 ) ) ;
if ( V_18 < 0 )
goto V_101;
for ( V_10 = 0 ; V_10 < V_104 ; V_10 ++ ) {
V_141 = ( T_3 ) V_139 -> V_142 [ V_10 ] ;
V_18 = F_10 ( V_15 , & V_141 , sizeof( V_141 ) ) ;
if ( V_18 < 0 )
break;
V_18 = F_76 ( V_15 , V_10 ) ;
if ( V_18 < 0 )
break;
}
V_101:
free ( V_16 ) ;
fclose ( V_123 ) ;
free ( V_139 ) ;
return V_18 ;
}
static int F_79 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
struct V_143 * V_144 = NULL ;
T_11 V_145 = F_80 ( V_15 , 0 , V_146 ) ;
T_12 V_147 = 0 ;
F_10 ( V_15 , & V_147 , sizeof( V_147 ) ) ;
while ( ( V_144 = F_81 ( V_144 ) ) ) {
if ( ! V_144 -> V_2 )
continue;
V_147 ++ ;
F_10 ( V_15 , & V_144 -> type , sizeof( V_144 -> type ) ) ;
F_13 ( V_15 , V_144 -> V_2 ) ;
}
if ( F_82 ( V_15 , & V_147 , sizeof( V_147 ) , V_145 ) != sizeof( V_147 ) ) {
F_80 ( V_15 , V_145 , V_148 ) ;
return - 1 ;
}
return 0 ;
}
static int F_83 ( int V_15 , struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
char V_149 [ 64 ] ;
int V_18 ;
V_18 = F_84 ( V_149 , sizeof( V_149 ) ) ;
if ( ! V_18 )
goto V_150;
return - 1 ;
V_150:
return F_13 ( V_15 , V_149 ) ;
}
static int F_85 ( int V_15 V_87 ,
struct V_11 * T_8 V_87 ,
struct V_88 * V_89 V_87 )
{
return 0 ;
}
static void F_86 ( struct V_11 * V_29 , int V_15 V_87 ,
T_9 * V_123 )
{
fprintf ( V_123 , L_24 , V_29 -> V_151 . V_152 ) ;
}
static void F_87 ( struct V_11 * V_29 , int V_15 V_87 ,
T_9 * V_123 )
{
fprintf ( V_123 , L_25 , V_29 -> V_151 . V_153 ) ;
}
static void F_88 ( struct V_11 * V_29 , int V_15 V_87 , T_9 * V_123 )
{
fprintf ( V_123 , L_26 , V_29 -> V_151 . V_154 ) ;
}
static void F_89 ( struct V_11 * V_29 , int V_15 V_87 ,
T_9 * V_123 )
{
fprintf ( V_123 , L_27 , V_29 -> V_151 . V_155 ) ;
}
static void F_90 ( struct V_11 * V_29 , int V_15 V_87 ,
T_9 * V_123 )
{
fprintf ( V_123 , L_28 , V_29 -> V_151 . V_156 ) ;
fprintf ( V_123 , L_29 , V_29 -> V_151 . V_157 ) ;
}
static void F_91 ( struct V_11 * V_29 , int V_15 V_87 ,
T_9 * V_123 )
{
fprintf ( V_123 , L_30 , V_29 -> V_151 . V_158 ) ;
}
static void F_92 ( struct V_11 * V_29 , int V_15 V_87 ,
T_9 * V_123 )
{
int V_104 , V_10 ;
char * V_26 ;
V_104 = V_29 -> V_151 . V_159 ;
V_26 = V_29 -> V_151 . V_160 ;
fprintf ( V_123 , L_31 ) ;
for ( V_10 = 0 ; V_10 < V_104 ; V_10 ++ ) {
fprintf ( V_123 , L_32 , V_26 ) ;
V_26 += strlen ( V_26 ) + 1 ;
}
fputc ( '\n' , V_123 ) ;
}
static void F_93 ( struct V_11 * V_29 , int V_15 V_87 ,
T_9 * V_123 )
{
int V_104 , V_10 ;
char * V_26 ;
V_104 = V_29 -> V_151 . V_161 ;
V_26 = V_29 -> V_151 . V_162 ;
for ( V_10 = 0 ; V_10 < V_104 ; V_10 ++ ) {
fprintf ( V_123 , L_33 , V_26 ) ;
V_26 += strlen ( V_26 ) + 1 ;
}
V_104 = V_29 -> V_151 . V_163 ;
V_26 = V_29 -> V_151 . V_164 ;
for ( V_10 = 0 ; V_10 < V_104 ; V_10 ++ ) {
fprintf ( V_123 , L_34 , V_26 ) ;
V_26 += strlen ( V_26 ) + 1 ;
}
}
static void F_94 ( struct V_110 * V_165 )
{
struct V_110 * V_111 ;
if ( ! V_165 )
return;
for ( V_111 = V_165 ; V_111 -> V_115 . V_17 ; V_111 ++ ) {
if ( V_111 -> V_2 )
free ( V_111 -> V_2 ) ;
if ( V_111 -> V_1 )
free ( V_111 -> V_1 ) ;
}
free ( V_165 ) ;
}
static struct V_110 *
F_95 ( struct V_11 * V_29 , int V_15 )
{
struct V_110 * V_111 , * V_165 = NULL ;
T_1 * V_1 ;
void * V_16 = NULL ;
T_3 V_112 , V_30 , V_104 , V_10 , V_141 ;
T_4 V_18 ;
T_2 V_166 ;
V_18 = F_16 ( V_15 , & V_112 , sizeof( V_112 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_112 ) )
goto error;
if ( V_29 -> V_31 )
V_112 = F_17 ( V_112 ) ;
V_18 = F_16 ( V_15 , & V_30 , sizeof( V_30 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_30 ) )
goto error;
if ( V_29 -> V_31 )
V_30 = F_17 ( V_30 ) ;
V_16 = malloc ( V_30 ) ;
if ( ! V_16 )
goto error;
V_165 = calloc ( V_112 + 1 , sizeof( * V_165 ) ) ;
if ( ! V_165 )
goto error;
V_166 = sizeof( V_111 -> V_115 ) ;
if ( V_30 < V_166 )
V_166 = V_30 ;
for ( V_10 = 0 , V_111 = V_165 ; V_10 < V_112 ; V_111 ++ , V_10 ++ ) {
V_111 -> V_167 = V_10 ;
V_18 = F_16 ( V_15 , V_16 , V_30 ) ;
if ( V_18 != ( T_4 ) V_30 )
goto error;
if ( V_29 -> V_31 )
F_96 ( V_16 ) ;
memcpy ( & V_111 -> V_115 , V_16 , V_166 ) ;
V_18 = F_16 ( V_15 , & V_104 , sizeof( V_104 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_104 ) )
goto error;
if ( V_29 -> V_31 ) {
V_104 = F_17 ( V_104 ) ;
V_111 -> V_31 = true ;
}
V_111 -> V_2 = F_15 ( V_15 , V_29 ) ;
if ( ! V_104 )
continue;
V_1 = calloc ( V_104 , sizeof( * V_1 ) ) ;
if ( ! V_1 )
goto error;
V_111 -> V_116 = V_104 ;
V_111 -> V_1 = V_1 ;
for ( V_141 = 0 ; V_141 < V_104 ; V_141 ++ ) {
V_18 = F_16 ( V_15 , V_1 , sizeof( * V_1 ) ) ;
if ( V_18 != ( T_4 ) sizeof( * V_1 ) )
goto error;
if ( V_29 -> V_31 )
* V_1 = F_97 ( * V_1 ) ;
V_1 ++ ;
}
}
V_168:
if ( V_16 )
free ( V_16 ) ;
return V_165 ;
error:
if ( V_165 )
F_94 ( V_165 ) ;
V_165 = NULL ;
goto V_168;
}
static void F_98 ( struct V_11 * V_29 , int V_15 , T_9 * V_123 )
{
struct V_110 * V_111 , * V_165 = F_95 ( V_29 , V_15 ) ;
T_3 V_141 ;
T_1 * V_1 ;
if ( ! V_165 ) {
fprintf ( V_123 , L_35 ) ;
return;
}
for ( V_111 = V_165 ; V_111 -> V_115 . V_17 ; V_111 ++ ) {
fprintf ( V_123 , L_36 , V_111 -> V_2 ) ;
fprintf ( V_123 , L_37 V_169
L_38 V_169 L_39 V_169 ,
V_111 -> V_115 . type ,
( T_1 ) V_111 -> V_115 . V_170 ,
( T_1 ) V_111 -> V_115 . V_171 ,
( T_1 ) V_111 -> V_115 . V_172 ) ;
fprintf ( V_123 , L_40 ,
V_111 -> V_115 . V_173 ,
V_111 -> V_115 . V_174 ) ;
fprintf ( V_123 , L_41 ,
V_111 -> V_115 . V_175 ,
V_111 -> V_115 . V_176 ) ;
fprintf ( V_123 , L_42 , V_111 -> V_115 . V_177 ) ;
if ( V_111 -> V_116 ) {
fprintf ( V_123 , L_43 ) ;
for ( V_141 = 0 , V_1 = V_111 -> V_1 ; V_141 < V_111 -> V_116 ; V_141 ++ , V_1 ++ ) {
if ( V_141 )
fputc ( ',' , V_123 ) ;
fprintf ( V_123 , L_44 V_133 , * V_1 ) ;
}
fprintf ( V_123 , L_45 ) ;
}
fputc ( '\n' , V_123 ) ;
}
F_94 ( V_165 ) ;
}
static void F_99 ( struct V_11 * V_29 , int V_15 V_87 ,
T_9 * V_123 )
{
fprintf ( V_123 , L_46 , V_29 -> V_151 . V_178 ) ;
}
static void F_100 ( struct V_11 * V_29 , int V_15 V_87 ,
T_9 * V_123 )
{
T_3 V_104 , V_140 , V_10 ;
char * V_26 , * V_179 ;
T_10 V_136 , V_137 ;
V_104 = V_29 -> V_151 . V_180 ;
V_26 = V_29 -> V_151 . V_181 ;
for ( V_10 = 0 ; V_10 < V_104 ; V_10 ++ ) {
V_140 = strtoul ( V_26 , & V_179 , 0 ) ;
if ( * V_179 != ':' )
goto error;
V_26 = V_179 + 1 ;
V_136 = F_101 ( V_26 , & V_179 , 0 ) ;
if ( * V_179 != ':' )
goto error;
V_26 = V_179 + 1 ;
V_137 = F_101 ( V_26 , & V_179 , 0 ) ;
if ( * V_179 != ':' )
goto error;
fprintf ( V_123 , L_47 V_133 L_48
L_49 V_133 L_50 ,
V_140 , V_136 , V_137 ) ;
V_26 = V_179 + 1 ;
fprintf ( V_123 , L_51 , V_140 , V_26 ) ;
V_26 += strlen ( V_26 ) + 1 ;
}
return;
error:
fprintf ( V_123 , L_52 ) ;
}
static void F_102 ( struct V_11 * V_29 , int V_15 V_87 , T_9 * V_123 )
{
fprintf ( V_123 , L_53 , V_29 -> V_151 . V_182 ) ;
}
static void F_103 ( struct V_11 * V_29 V_87 ,
int V_15 V_87 , T_9 * V_123 )
{
fprintf ( V_123 , L_54 ) ;
}
static void F_104 ( struct V_11 * V_29 , int V_15 V_87 ,
T_9 * V_123 )
{
const char * V_183 = L_55 ;
char * V_26 , * V_179 ;
T_3 V_147 ;
T_3 type ;
V_147 = V_29 -> V_151 . V_184 ;
if ( ! V_147 ) {
fprintf ( V_123 , L_56 ) ;
return;
}
V_26 = V_29 -> V_151 . V_185 ;
while ( V_147 ) {
type = strtoul ( V_26 , & V_179 , 0 ) ;
if ( * V_179 != ':' )
goto error;
V_26 = V_179 + 1 ;
fprintf ( V_123 , L_57 V_186 , V_183 , V_26 , type ) ;
V_183 = L_58 ;
V_26 += strlen ( V_26 ) + 1 ;
V_147 -- ;
}
fprintf ( V_123 , L_59 ) ;
if ( ! V_147 )
return;
error:
fprintf ( V_123 , L_60 ) ;
}
static int F_105 ( struct V_40 * V_187 ,
char * V_73 ,
struct V_61 * V_62 )
{
int V_25 = - 1 ;
struct V_43 * V_44 ;
struct V_52 * V_52 ;
T_7 V_39 ;
struct V_45 * V_45 ;
enum V_188 V_189 ;
V_52 = F_106 ( V_62 , V_187 -> V_38 ) ;
if ( ! V_52 )
goto V_168;
V_39 = V_187 -> V_12 . V_39 & V_190 ;
switch ( V_39 ) {
case V_54 :
V_189 = V_191 ;
V_44 = & V_52 -> V_59 ;
break;
case V_57 :
V_189 = V_192 ;
V_44 = & V_52 -> V_59 ;
break;
case V_56 :
case V_58 :
V_189 = V_193 ;
V_44 = & V_52 -> V_60 ;
break;
default:
goto V_168;
}
V_45 = F_107 ( V_44 , V_73 ) ;
if ( V_45 != NULL ) {
char V_67 [ V_42 * 2 + 1 ] ;
F_108 ( V_45 , & V_187 -> V_37 ) ;
if ( V_73 [ 0 ] == '[' )
V_45 -> V_83 = V_189 ;
F_41 ( V_45 -> V_37 , sizeof( V_45 -> V_37 ) ,
V_67 ) ;
F_32 ( L_61 ,
V_45 -> V_50 , V_67 ) ;
}
V_25 = 0 ;
V_168:
return V_25 ;
}
static int F_109 ( struct V_11 * V_12 ,
int V_194 , T_1 V_145 , T_1 V_17 )
{
struct V_61 * V_62 = F_26 ( V_12 , struct V_61 , V_12 ) ;
struct {
struct V_195 V_12 ;
T_5 V_37 [ F_14 ( V_42 , sizeof( T_1 ) ) ] ;
char V_73 [ 0 ] ;
} V_196 ;
struct V_40 V_187 ;
char V_73 [ V_71 ] ;
T_1 V_197 = V_145 + V_17 ;
while ( V_145 < V_197 ) {
T_4 V_27 ;
if ( F_16 ( V_194 , & V_196 , sizeof( V_196 ) ) != sizeof( V_196 ) )
return - 1 ;
if ( V_12 -> V_31 )
F_110 ( & V_196 . V_12 ) ;
V_27 = V_196 . V_12 . V_17 - sizeof( V_196 ) ;
if ( F_16 ( V_194 , V_73 , V_27 ) != V_27 )
return - 1 ;
V_187 . V_12 = V_196 . V_12 ;
V_187 . V_38 = V_198 ;
if ( V_187 . V_12 . V_39 == V_58 ||
V_187 . V_12 . V_39 == V_57 )
V_187 . V_38 = V_199 ;
memcpy ( V_187 . V_37 , V_196 . V_37 , sizeof( V_187 . V_37 ) ) ;
F_105 ( & V_187 , V_73 , V_62 ) ;
V_145 += V_187 . V_12 . V_17 ;
}
return 0 ;
}
static int F_111 ( struct V_11 * V_12 ,
int V_194 , T_1 V_145 , T_1 V_17 )
{
struct V_61 * V_62 = F_26 ( V_12 , struct V_61 , V_12 ) ;
struct V_40 V_187 ;
char V_73 [ V_71 ] ;
T_1 V_197 = V_145 + V_17 , V_200 = V_145 ;
int V_25 = - 1 ;
while ( V_145 < V_197 ) {
T_4 V_27 ;
if ( F_16 ( V_194 , & V_187 , sizeof( V_187 ) ) != sizeof( V_187 ) )
goto V_168;
if ( V_12 -> V_31 )
F_110 ( & V_187 . V_12 ) ;
V_27 = V_187 . V_12 . V_17 - sizeof( V_187 ) ;
if ( F_16 ( V_194 , V_73 , V_27 ) != V_27 )
goto V_168;
if ( memcmp ( V_73 , L_62 , 13 ) == 0 ) {
if ( F_80 ( V_194 , V_200 , V_148 ) == ( T_11 ) - 1 )
return - 1 ;
return F_109 ( V_12 , V_194 , V_145 , V_17 ) ;
}
F_105 ( & V_187 , V_73 , V_62 ) ;
V_145 += V_187 . V_12 . V_17 ;
}
V_25 = 0 ;
V_168:
return V_25 ;
}
static int F_112 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 V_87 ,
int V_15 , void * V_202 )
{
F_113 ( V_15 , V_202 , false ) ;
return 0 ;
}
static int F_114 ( struct V_201 * T_13 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
if ( F_111 ( V_29 , V_15 , T_13 -> V_145 , T_13 -> V_17 ) )
F_32 ( L_63 ) ;
return 0 ;
}
static int F_115 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
V_29 -> V_151 . V_152 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_151 . V_152 ? 0 : - V_8 ;
}
static int F_116 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
V_29 -> V_151 . V_153 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_151 . V_153 ? 0 : - V_8 ;
}
static int F_117 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
V_29 -> V_151 . V_158 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_151 . V_158 ? 0 : - V_8 ;
}
static int F_118 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
V_29 -> V_151 . V_154 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_151 . V_154 ? 0 : - V_8 ;
}
static int F_119 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
T_2 V_18 ;
T_3 V_104 ;
V_18 = F_16 ( V_15 , & V_104 , sizeof( V_104 ) ) ;
if ( V_18 != sizeof( V_104 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_104 = F_17 ( V_104 ) ;
V_29 -> V_151 . V_156 = V_104 ;
V_18 = F_16 ( V_15 , & V_104 , sizeof( V_104 ) ) ;
if ( V_18 != sizeof( V_104 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_104 = F_17 ( V_104 ) ;
V_29 -> V_151 . V_157 = V_104 ;
return 0 ;
}
static int F_120 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
V_29 -> V_151 . V_155 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_151 . V_155 ? 0 : - V_8 ;
}
static int F_121 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
V_29 -> V_151 . V_182 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_151 . V_182 ? 0 : - V_8 ;
}
static int F_122 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
T_10 V_132 ;
T_2 V_18 ;
V_18 = F_16 ( V_15 , & V_132 , sizeof( V_132 ) ) ;
if ( V_18 != sizeof( V_132 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_132 = F_97 ( V_132 ) ;
V_29 -> V_151 . V_178 = V_132 ;
return 0 ;
}
static struct V_110 *
F_123 ( struct V_88 * V_89 , int V_167 )
{
struct V_110 * V_111 ;
F_67 (evsel, &evlist->entries, node) {
if ( V_111 -> V_167 == V_167 )
return V_111 ;
}
return NULL ;
}
static void
F_124 ( struct V_88 * V_89 ,
struct V_110 * V_203 )
{
struct V_110 * V_111 ;
if ( ! V_203 -> V_2 )
return;
V_111 = F_123 ( V_89 , V_203 -> V_167 ) ;
if ( ! V_111 )
return;
if ( V_111 -> V_2 )
return;
V_111 -> V_2 = F_125 ( V_203 -> V_2 ) ;
}
static int
F_126 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_12 , int V_15 ,
void * V_202 V_87 )
{
struct V_61 * V_62 ;
struct V_110 * V_111 , * V_165 = F_95 ( V_12 , V_15 ) ;
if ( ! V_165 )
return 0 ;
V_62 = F_26 ( V_12 , struct V_61 , V_12 ) ;
for ( V_111 = V_165 ; V_111 -> V_115 . V_17 ; V_111 ++ )
F_124 ( V_62 -> V_89 , V_111 ) ;
F_94 ( V_165 ) ;
return 0 ;
}
static int F_127 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
T_2 V_18 ;
char * V_26 ;
T_3 V_104 , V_10 ;
struct V_204 V_205 ;
V_18 = F_16 ( V_15 , & V_104 , sizeof( V_104 ) ) ;
if ( V_18 != sizeof( V_104 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_104 = F_17 ( V_104 ) ;
V_29 -> V_151 . V_159 = V_104 ;
F_128 ( & V_205 , 128 ) ;
for ( V_10 = 0 ; V_10 < V_104 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
if ( ! V_26 )
goto error;
F_129 ( & V_205 , V_26 , strlen ( V_26 ) + 1 ) ;
free ( V_26 ) ;
}
V_29 -> V_151 . V_160 = F_130 ( & V_205 , NULL ) ;
return 0 ;
error:
F_131 ( & V_205 ) ;
return - 1 ;
}
static int F_132 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
T_2 V_18 ;
T_3 V_104 , V_10 ;
char * V_26 ;
struct V_204 V_205 ;
V_18 = F_16 ( V_15 , & V_104 , sizeof( V_104 ) ) ;
if ( V_18 != sizeof( V_104 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_104 = F_17 ( V_104 ) ;
V_29 -> V_151 . V_161 = V_104 ;
F_128 ( & V_205 , 128 ) ;
for ( V_10 = 0 ; V_10 < V_104 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
if ( ! V_26 )
goto error;
F_129 ( & V_205 , V_26 , strlen ( V_26 ) + 1 ) ;
free ( V_26 ) ;
}
V_29 -> V_151 . V_162 = F_130 ( & V_205 , NULL ) ;
V_18 = F_16 ( V_15 , & V_104 , sizeof( V_104 ) ) ;
if ( V_18 != sizeof( V_104 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_104 = F_17 ( V_104 ) ;
V_29 -> V_151 . V_163 = V_104 ;
for ( V_10 = 0 ; V_10 < V_104 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
if ( ! V_26 )
goto error;
F_129 ( & V_205 , V_26 , strlen ( V_26 ) + 1 ) ;
free ( V_26 ) ;
}
V_29 -> V_151 . V_164 = F_130 ( & V_205 , NULL ) ;
return 0 ;
error:
F_131 ( & V_205 ) ;
return - 1 ;
}
static int F_133 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
T_2 V_18 ;
T_3 V_104 , V_134 , V_10 ;
char * V_26 ;
T_10 V_136 , V_137 ;
struct V_204 V_205 ;
V_18 = F_16 ( V_15 , & V_104 , sizeof( V_104 ) ) ;
if ( V_18 != sizeof( V_104 ) )
goto error;
if ( V_29 -> V_31 )
V_104 = F_17 ( V_104 ) ;
V_29 -> V_151 . V_180 = V_104 ;
F_128 ( & V_205 , 256 ) ;
for ( V_10 = 0 ; V_10 < V_104 ; V_10 ++ ) {
V_18 = F_16 ( V_15 , & V_134 , sizeof( V_134 ) ) ;
if ( V_18 != sizeof( V_134 ) )
goto error;
V_18 = F_16 ( V_15 , & V_136 , sizeof( T_1 ) ) ;
if ( V_18 != sizeof( T_1 ) )
goto error;
V_18 = F_16 ( V_15 , & V_137 , sizeof( T_1 ) ) ;
if ( V_18 != sizeof( T_1 ) )
goto error;
if ( V_29 -> V_31 ) {
V_134 = F_17 ( V_134 ) ;
V_136 = F_97 ( V_136 ) ;
V_137 = F_97 ( V_137 ) ;
}
F_134 ( & V_205 , L_64 V_133 L_65 V_133 L_66 ,
V_134 , V_136 , V_137 ) ;
V_26 = F_15 ( V_15 , V_29 ) ;
if ( ! V_26 )
goto error;
F_129 ( & V_205 , V_26 , strlen ( V_26 ) + 1 ) ;
free ( V_26 ) ;
}
V_29 -> V_151 . V_181 = F_130 ( & V_205 , NULL ) ;
return 0 ;
error:
F_131 ( & V_205 ) ;
return - 1 ;
}
static int F_135 ( struct V_201 * T_13 V_87 ,
struct V_11 * V_29 , int V_15 ,
void * V_202 V_87 )
{
T_2 V_18 ;
char * V_2 ;
T_3 V_147 ;
T_3 type ;
struct V_204 V_205 ;
V_18 = F_16 ( V_15 , & V_147 , sizeof( V_147 ) ) ;
if ( V_18 != sizeof( V_147 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_147 = F_17 ( V_147 ) ;
if ( ! V_147 ) {
F_32 ( L_67 ) ;
return 0 ;
}
V_29 -> V_151 . V_184 = V_147 ;
F_128 ( & V_205 , 128 ) ;
while ( V_147 ) {
if ( F_16 ( V_15 , & type , sizeof( type ) ) != sizeof( type ) )
goto error;
if ( V_29 -> V_31 )
type = F_17 ( type ) ;
V_2 = F_15 ( V_15 , V_29 ) ;
if ( ! V_2 )
goto error;
F_134 ( & V_205 , L_68 , type , V_2 ) ;
F_129 ( & V_205 , L_5 , 1 ) ;
free ( V_2 ) ;
V_147 -- ;
}
V_29 -> V_151 . V_185 = F_130 ( & V_205 , NULL ) ;
return 0 ;
error:
F_131 ( & V_205 ) ;
return - 1 ;
}
static int F_136 ( struct V_201 * T_13 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_202 )
{
struct V_206 * V_207 = V_202 ;
if ( F_80 ( V_15 , T_13 -> V_145 , V_148 ) == ( T_11 ) - 1 ) {
F_32 ( L_69 V_133 L_70
L_71 , T_13 -> V_145 , V_13 ) ;
return 0 ;
}
if ( V_13 >= V_208 ) {
F_2 ( L_72 , V_13 ) ;
return 0 ;
}
if ( ! V_209 [ V_13 ] . V_210 )
return 0 ;
if ( ! V_209 [ V_13 ] . V_211 || V_207 -> V_212 )
V_209 [ V_13 ] . V_210 ( V_29 , V_15 , V_207 -> V_123 ) ;
else
fprintf ( V_207 -> V_123 , L_73 ,
V_209 [ V_13 ] . V_2 ) ;
return 0 ;
}
int F_137 ( struct V_61 * V_62 , T_9 * V_123 , bool V_212 )
{
struct V_206 V_207 ;
struct V_11 * V_12 = & V_62 -> V_12 ;
int V_15 = V_62 -> V_15 ;
V_207 . V_123 = V_123 ;
V_207 . V_212 = V_212 ;
F_138 ( V_12 , V_15 , & V_207 ,
F_136 ) ;
return 0 ;
}
static int F_139 ( int V_15 , struct V_11 * T_8 , int type ,
struct V_201 * * V_99 ,
struct V_88 * V_89 )
{
int V_25 ;
int V_18 = 0 ;
if ( F_8 ( T_8 , type ) ) {
if ( ! V_209 [ type ] . F_11 )
return - 1 ;
( * V_99 ) -> V_145 = F_80 ( V_15 , 0 , V_146 ) ;
V_25 = V_209 [ type ] . F_11 ( V_15 , T_8 , V_89 ) ;
if ( V_25 < 0 ) {
F_32 ( L_74 , type ) ;
F_80 ( V_15 , ( * V_99 ) -> V_145 , V_148 ) ;
return - 1 ;
}
( * V_99 ) -> V_17 = F_80 ( V_15 , 0 , V_146 ) - ( * V_99 ) -> V_145 ;
( * V_99 ) ++ ;
}
return V_18 ;
}
static int F_140 ( struct V_11 * V_12 ,
struct V_88 * V_89 , int V_15 )
{
int V_213 ;
struct V_201 * V_214 , * V_99 ;
int V_215 ;
T_1 V_216 ;
int V_13 ;
int V_25 ;
V_213 = F_141 ( V_12 -> V_14 , V_217 ) ;
if ( ! V_213 )
return 0 ;
V_214 = V_99 = calloc ( sizeof( * V_214 ) , V_213 ) ;
if ( V_214 == NULL )
return - V_8 ;
V_215 = sizeof( * V_214 ) * V_213 ;
V_216 = V_12 -> V_218 + V_12 -> V_219 ;
F_80 ( V_15 , V_216 + V_215 , V_148 ) ;
F_142 (feat, header->adds_features, HEADER_FEAT_BITS) {
if ( F_139 ( V_15 , V_12 , V_13 , & V_99 , V_89 ) )
F_6 ( V_12 , V_13 ) ;
}
F_80 ( V_15 , V_216 , V_148 ) ;
V_25 = F_10 ( V_15 , V_214 , V_215 ) ;
if ( V_25 < 0 )
F_32 ( L_75 ) ;
free ( V_214 ) ;
return V_25 ;
}
int F_143 ( int V_15 )
{
struct V_220 V_221 ;
int V_25 ;
V_221 = (struct V_220 ) {
. V_222 = V_223 ,
. V_17 = sizeof( V_221 ) ,
} ;
V_25 = F_10 ( V_15 , & V_221 , sizeof( V_221 ) ) ;
if ( V_25 < 0 ) {
F_32 ( L_76 ) ;
return V_25 ;
}
return 0 ;
}
int F_144 ( struct V_61 * V_62 ,
struct V_88 * V_89 ,
int V_15 , bool V_224 )
{
struct V_225 V_221 ;
struct V_226 V_227 ;
struct V_11 * V_12 = & V_62 -> V_12 ;
struct V_110 * V_111 , * V_228 = NULL ;
int V_25 ;
F_80 ( V_15 , sizeof( V_221 ) , V_148 ) ;
if ( V_62 -> V_89 != V_89 )
V_228 = F_145 ( V_62 -> V_89 ) ;
F_67 (evsel, &evlist->entries, node) {
V_111 -> V_229 = F_80 ( V_15 , 0 , V_146 ) ;
V_25 = F_10 ( V_15 , V_111 -> V_1 , V_111 -> V_116 * sizeof( T_1 ) ) ;
if ( V_25 < 0 ) {
V_230:
F_32 ( L_77 ) ;
return V_25 ;
}
if ( V_62 -> V_89 != V_89 ) {
V_25 = F_10 ( V_15 , V_228 -> V_1 , V_228 -> V_116 * sizeof( T_1 ) ) ;
if ( V_25 < 0 )
goto V_230;
V_111 -> V_116 += V_228 -> V_116 ;
V_228 = F_146 ( V_228 ) ;
}
}
V_12 -> V_231 = F_80 ( V_15 , 0 , V_146 ) ;
F_67 (evsel, &evlist->entries, node) {
V_227 = (struct V_226 ) {
. V_115 = V_111 -> V_115 ,
. V_116 = {
. V_145 = V_111 -> V_229 ,
. V_17 = V_111 -> V_116 * sizeof( T_1 ) ,
}
} ;
V_25 = F_10 ( V_15 , & V_227 , sizeof( V_227 ) ) ;
if ( V_25 < 0 ) {
F_32 ( L_78 ) ;
return V_25 ;
}
}
V_12 -> V_232 = F_80 ( V_15 , 0 , V_146 ) ;
V_12 -> V_233 = V_7 * sizeof( struct V_3 ) ;
if ( V_6 ) {
V_25 = F_10 ( V_15 , V_6 , V_12 -> V_233 ) ;
if ( V_25 < 0 ) {
F_32 ( L_79 ) ;
return V_25 ;
}
}
V_12 -> V_218 = F_80 ( V_15 , 0 , V_146 ) ;
if ( V_224 ) {
V_25 = F_140 ( V_12 , V_89 , V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_221 = (struct V_225 ) {
. V_222 = V_223 ,
. V_17 = sizeof( V_221 ) ,
. V_234 = sizeof( V_227 ) ,
. V_235 = {
. V_145 = V_12 -> V_231 ,
. V_17 = V_89 -> V_114 * sizeof( V_227 ) ,
} ,
. V_202 = {
. V_145 = V_12 -> V_218 ,
. V_17 = V_12 -> V_219 ,
} ,
. V_236 = {
. V_145 = V_12 -> V_232 ,
. V_17 = V_12 -> V_233 ,
} ,
} ;
memcpy ( & V_221 . V_14 , & V_12 -> V_14 , sizeof( V_12 -> V_14 ) ) ;
F_80 ( V_15 , 0 , V_148 ) ;
V_25 = F_10 ( V_15 , & V_221 , sizeof( V_221 ) ) ;
if ( V_25 < 0 ) {
F_32 ( L_77 ) ;
return V_25 ;
}
F_80 ( V_15 , V_12 -> V_218 + V_12 -> V_219 , V_148 ) ;
V_12 -> V_237 = 1 ;
return 0 ;
}
static int F_147 ( struct V_11 * V_12 ,
int V_15 , void * V_16 , T_2 V_17 )
{
if ( F_148 ( V_15 , V_16 , V_17 ) <= 0 )
return - 1 ;
if ( V_12 -> V_31 )
F_149 ( V_16 , V_17 ) ;
return 0 ;
}
int F_138 ( struct V_11 * V_12 , int V_15 ,
void * V_202 ,
int (* F_150)( struct V_201 * T_13 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_202 ) )
{
struct V_201 * V_214 , * V_238 ;
int V_213 ;
int V_215 ;
int V_13 ;
int V_25 ;
V_213 = F_141 ( V_12 -> V_14 , V_217 ) ;
if ( ! V_213 )
return 0 ;
V_214 = V_238 = calloc ( sizeof( * V_214 ) , V_213 ) ;
if ( ! V_214 )
return - 1 ;
V_215 = sizeof( * V_214 ) * V_213 ;
F_80 ( V_15 , V_12 -> V_218 + V_12 -> V_219 , V_148 ) ;
V_25 = F_147 ( V_12 , V_15 , V_214 , V_215 ) ;
if ( V_25 < 0 )
goto V_79;
F_142 (feat, header->adds_features, HEADER_LAST_FEATURE) {
V_25 = F_150 ( V_238 ++ , V_12 , V_13 , V_15 , V_202 ) ;
if ( V_25 < 0 )
goto V_79;
}
V_25 = 0 ;
V_79:
free ( V_214 ) ;
return V_25 ;
}
static int F_151 ( T_10 V_239 , struct V_11 * V_29 )
{
T_10 V_240 , V_234 ;
int V_10 ;
for ( V_10 = 0 ; V_241 [ V_10 ] ; V_10 ++ ) {
V_240 = V_241 [ V_10 ]
+ sizeof( struct V_201 ) ;
if ( V_239 != V_240 ) {
V_234 = F_97 ( V_239 ) ;
if ( V_234 != V_240 )
continue;
V_29 -> V_31 = true ;
}
F_32 ( L_80 ,
V_10 ,
V_29 -> V_31 ) ;
return 0 ;
}
return - 1 ;
}
static int F_152 ( T_10 V_239 , struct V_11 * V_29 )
{
T_1 V_234 ;
int V_10 ;
for ( V_10 = 0 ; V_242 [ V_10 ] ; V_10 ++ ) {
if ( V_239 != V_242 [ V_10 ] ) {
V_234 = F_97 ( V_239 ) ;
if ( V_234 != V_239 )
continue;
V_29 -> V_31 = true ;
}
F_32 ( L_81 , V_10 ) ;
return 0 ;
}
return - 1 ;
}
bool F_153 ( T_1 V_222 )
{
if ( ! memcmp ( & V_222 , V_243 , sizeof( V_222 ) )
|| V_222 == V_244
|| V_222 == V_245 )
return true ;
return false ;
}
static int F_154 ( T_1 V_222 , T_10 V_239 ,
bool V_246 , struct V_11 * V_29 )
{
int V_18 ;
V_18 = memcmp ( & V_222 , V_243 , sizeof( V_222 ) ) ;
if ( V_18 == 0 ) {
F_32 ( L_82 ) ;
if ( V_246 )
return F_152 ( V_239 , V_29 ) ;
return F_151 ( V_239 , V_29 ) ;
}
if ( V_222 == V_244 )
return 0 ;
if ( V_222 != V_245 )
return - 1 ;
V_29 -> V_31 = true ;
return 0 ;
}
int F_155 ( struct V_225 * V_12 ,
struct V_11 * V_29 , int V_15 )
{
int V_18 ;
F_80 ( V_15 , 0 , V_148 ) ;
V_18 = F_148 ( V_15 , V_12 , sizeof( * V_12 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
if ( F_154 ( V_12 -> V_222 ,
V_12 -> V_234 , false , V_29 ) < 0 ) {
F_32 ( L_83 ) ;
return - 1 ;
}
if ( V_29 -> V_31 ) {
F_149 ( V_12 , F_156 ( struct V_225 ,
V_14 ) ) ;
}
if ( V_12 -> V_17 != sizeof( * V_12 ) ) {
if ( V_12 -> V_17 == F_156 ( F_157 ( * V_12 ) , V_14 ) )
F_158 ( V_12 -> V_14 , V_217 ) ;
else
return - 1 ;
} else if ( V_29 -> V_31 ) {
F_149 ( & V_12 -> V_14 ,
F_159 ( V_217 ) ) ;
if ( ! F_9 ( V_247 , V_12 -> V_14 ) ) {
F_149 ( & V_12 -> V_14 ,
F_159 ( V_217 ) ) ;
F_160 ( & V_12 -> V_14 ,
F_161 ( V_217 ) ) ;
}
if ( ! F_9 ( V_247 , V_12 -> V_14 ) ) {
F_158 ( V_12 -> V_14 , V_217 ) ;
F_5 ( V_248 , V_12 -> V_14 ) ;
}
}
memcpy ( & V_29 -> V_14 , & V_12 -> V_14 ,
sizeof( V_29 -> V_14 ) ) ;
V_29 -> V_232 = V_12 -> V_236 . V_145 ;
V_29 -> V_233 = V_12 -> V_236 . V_17 ;
V_29 -> V_218 = V_12 -> V_202 . V_145 ;
V_29 -> V_219 = V_12 -> V_202 . V_17 ;
return 0 ;
}
static int F_162 ( struct V_201 * T_13 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_202 )
{
if ( F_80 ( V_15 , T_13 -> V_145 , V_148 ) == ( T_11 ) - 1 ) {
F_32 ( L_69 V_133 L_70
L_71 , T_13 -> V_145 , V_13 ) ;
return 0 ;
}
if ( V_13 >= V_208 ) {
F_32 ( L_84 , V_13 ) ;
return 0 ;
}
if ( ! V_209 [ V_13 ] . F_150 )
return 0 ;
return V_209 [ V_13 ] . F_150 ( T_13 , V_29 , V_15 , V_202 ) ;
}
static int F_163 ( struct V_220 * V_12 ,
struct V_11 * V_29 , int V_15 ,
bool V_249 )
{
int V_18 ;
V_18 = F_148 ( V_15 , V_12 , sizeof( * V_12 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
if ( F_154 ( V_12 -> V_222 , V_12 -> V_17 , true , V_29 ) < 0 ) {
F_32 ( L_85 ) ;
return - 1 ;
}
if ( V_29 -> V_31 )
V_12 -> V_17 = F_97 ( V_12 -> V_17 ) ;
if ( V_249 && F_10 ( V_250 , V_12 , sizeof( * V_12 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int F_164 ( struct V_61 * V_62 , int V_15 )
{
struct V_11 * V_12 = & V_62 -> V_12 ;
struct V_220 V_221 ;
if ( F_163 ( & V_221 , V_12 , V_15 ,
V_62 -> V_249 ) < 0 ) {
F_32 ( L_86 ) ;
return - V_251 ;
}
V_62 -> V_15 = V_15 ;
return 0 ;
}
static int F_165 ( int V_15 , struct V_11 * V_29 ,
struct V_226 * V_227 )
{
struct V_252 * V_115 = & V_227 -> V_115 ;
T_2 V_30 , V_253 ;
T_2 V_254 = sizeof( V_227 -> V_115 ) ;
int V_18 ;
memset ( V_227 , 0 , sizeof( * V_227 ) ) ;
V_18 = F_148 ( V_15 , V_115 , V_255 ) ;
if ( V_18 <= 0 ) {
F_32 ( L_87 ,
V_255 ) ;
return - 1 ;
}
V_30 = V_115 -> V_17 ;
if ( V_29 -> V_31 )
V_30 = F_17 ( V_30 ) ;
if ( V_30 == 0 ) {
V_30 = V_255 ;
} else if ( V_30 > V_254 ) {
F_32 ( L_88
L_89 , V_30 - V_254 ) ;
return - 1 ;
}
V_253 = V_30 - V_255 ;
if ( V_253 ) {
void * V_256 = V_115 ;
V_256 += V_255 ;
V_18 = F_148 ( V_15 , V_256 , V_253 ) ;
}
V_18 = F_148 ( V_15 , & V_227 -> V_116 , sizeof( V_227 -> V_116 ) ) ;
return V_18 <= 0 ? - 1 : 0 ;
}
static int F_166 ( struct V_110 * V_111 ,
struct V_257 * V_257 )
{
struct V_258 * V_203 ;
char V_20 [ 128 ] ;
if ( V_111 -> V_259 )
return 0 ;
V_203 = F_167 ( V_257 , V_111 -> V_115 . V_170 ) ;
if ( V_203 == NULL )
return - 1 ;
if ( ! V_111 -> V_2 ) {
snprintf ( V_20 , sizeof( V_20 ) , L_90 , V_203 -> system , V_203 -> V_2 ) ;
V_111 -> V_2 = F_125 ( V_20 ) ;
if ( V_111 -> V_2 == NULL )
return - 1 ;
}
V_111 -> V_259 = V_203 ;
return 0 ;
}
static int F_168 ( struct V_88 * V_89 ,
struct V_257 * V_257 )
{
struct V_110 * V_46 ;
F_67 (pos, &evlist->entries, node) {
if ( V_46 -> V_115 . type == V_260 &&
F_166 ( V_46 , V_257 ) )
return - 1 ;
}
return 0 ;
}
int F_169 ( struct V_61 * V_62 , int V_15 )
{
struct V_11 * V_12 = & V_62 -> V_12 ;
struct V_225 V_221 ;
struct V_226 V_227 ;
T_1 V_261 ;
int V_262 , V_263 , V_10 , V_141 ;
V_62 -> V_89 = F_170 ( NULL , NULL ) ;
if ( V_62 -> V_89 == NULL )
return - V_8 ;
if ( V_62 -> V_264 )
return F_164 ( V_62 , V_15 ) ;
if ( F_155 ( & V_221 , V_12 , V_15 ) < 0 )
return - V_251 ;
V_262 = V_221 . V_235 . V_17 / V_221 . V_234 ;
F_80 ( V_15 , V_221 . V_235 . V_145 , V_148 ) ;
for ( V_10 = 0 ; V_10 < V_262 ; V_10 ++ ) {
struct V_110 * V_111 ;
T_11 V_179 ;
if ( F_165 ( V_15 , V_12 , & V_227 ) < 0 )
goto V_265;
if ( V_12 -> V_31 )
F_96 ( & V_227 . V_115 ) ;
V_179 = F_80 ( V_15 , 0 , V_146 ) ;
V_111 = F_171 ( & V_227 . V_115 , V_10 ) ;
if ( V_111 == NULL )
goto V_266;
V_111 -> V_31 = V_12 -> V_31 ;
F_172 ( V_62 -> V_89 , V_111 ) ;
V_263 = V_227 . V_116 . V_17 / sizeof( T_1 ) ;
if ( F_173 ( V_111 , 1 , V_263 ) )
goto V_266;
F_80 ( V_15 , V_227 . V_116 . V_145 , V_148 ) ;
for ( V_141 = 0 ; V_141 < V_263 ; V_141 ++ ) {
if ( F_147 ( V_12 , V_15 , & V_261 , sizeof( V_261 ) ) )
goto V_265;
F_174 ( V_62 -> V_89 , V_111 , 0 , V_141 , V_261 ) ;
}
F_80 ( V_15 , V_179 , V_148 ) ;
}
V_77 . V_267 = V_262 ;
if ( V_221 . V_236 . V_17 ) {
F_80 ( V_15 , V_221 . V_236 . V_145 , V_148 ) ;
V_6 = malloc ( V_221 . V_236 . V_17 ) ;
if ( V_6 == NULL )
return - V_8 ;
if ( F_147 ( V_12 , V_15 , V_6 ,
V_221 . V_236 . V_17 ) )
goto V_265;
V_7 = V_221 . V_236 . V_17 / sizeof( struct V_3 ) ;
}
F_138 ( V_12 , V_15 , & V_62 -> V_257 ,
F_162 ) ;
F_80 ( V_15 , V_12 -> V_218 , V_148 ) ;
if ( F_168 ( V_62 -> V_89 ,
V_62 -> V_257 ) )
goto V_266;
V_12 -> V_237 = 1 ;
return 0 ;
V_265:
return - V_19 ;
V_266:
F_175 ( V_62 -> V_89 ) ;
V_62 -> V_89 = NULL ;
return - V_8 ;
}
int F_176 ( struct V_268 * V_269 ,
struct V_252 * V_115 , T_3 V_116 , T_1 * V_1 ,
T_14 F_150 )
{
union V_270 * V_271 ;
T_2 V_17 ;
int V_25 ;
V_17 = sizeof( struct V_252 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_17 += sizeof( struct V_195 ) ;
V_17 += V_116 * sizeof( T_1 ) ;
V_271 = malloc ( V_17 ) ;
if ( V_271 == NULL )
return - V_8 ;
V_271 -> V_115 . V_115 = * V_115 ;
memcpy ( V_271 -> V_115 . V_1 , V_1 , V_116 * sizeof( T_1 ) ) ;
V_271 -> V_115 . V_12 . type = V_272 ;
V_271 -> V_115 . V_12 . V_17 = ( T_7 ) V_17 ;
if ( V_271 -> V_115 . V_12 . V_17 == V_17 )
V_25 = F_150 ( V_269 , V_271 , NULL , NULL ) ;
else
V_25 = - V_273 ;
free ( V_271 ) ;
return V_25 ;
}
int F_177 ( struct V_268 * V_269 ,
struct V_61 * V_62 ,
T_14 F_150 )
{
struct V_110 * V_111 ;
int V_25 = 0 ;
F_67 (evsel, &session->evlist->entries, node) {
V_25 = F_176 ( V_269 , & V_111 -> V_115 , V_111 -> V_116 ,
V_111 -> V_1 , F_150 ) ;
if ( V_25 ) {
F_32 ( L_91 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_178 ( union V_270 * V_203 ,
struct V_88 * * V_274 )
{
T_3 V_10 , V_116 , V_275 ;
struct V_110 * V_111 ;
struct V_88 * V_89 = * V_274 ;
if ( V_89 == NULL ) {
* V_274 = V_89 = F_170 ( NULL , NULL ) ;
if ( V_89 == NULL )
return - V_8 ;
}
V_111 = F_171 ( & V_203 -> V_115 . V_115 , V_89 -> V_114 ) ;
if ( V_111 == NULL )
return - V_8 ;
F_172 ( V_89 , V_111 ) ;
V_116 = V_203 -> V_12 . V_17 ;
V_116 -= ( void * ) & V_203 -> V_115 . V_1 - ( void * ) V_203 ;
V_275 = V_116 / sizeof( T_1 ) ;
if ( F_173 ( V_111 , 1 , V_275 ) )
return - V_8 ;
for ( V_10 = 0 ; V_10 < V_275 ; V_10 ++ ) {
F_174 ( V_89 , V_111 , 0 , V_10 , V_203 -> V_115 . V_1 [ V_10 ] ) ;
}
return 0 ;
}
int F_179 ( struct V_268 * V_269 ,
T_1 V_9 , char * V_2 ,
T_14 F_150 ,
struct V_52 * V_52 )
{
union V_270 V_271 ;
T_2 V_17 = 0 ;
int V_25 = 0 ;
memset ( & V_271 , 0 , sizeof( V_271 ) ) ;
V_271 . V_276 . V_276 . V_9 = V_9 ;
memset ( V_271 . V_276 . V_276 . V_2 , 0 , V_5 ) ;
strncpy ( V_271 . V_276 . V_276 . V_2 , V_2 , V_5 - 1 ) ;
V_271 . V_276 . V_12 . type = V_277 ;
V_17 = strlen ( V_271 . V_276 . V_276 . V_2 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_271 . V_276 . V_12 . V_17 = sizeof( V_271 . V_276 ) -
( sizeof( V_271 . V_276 . V_276 . V_2 ) - V_17 ) ;
V_25 = F_150 ( V_269 , & V_271 , NULL , V_52 ) ;
return V_25 ;
}
int F_180 ( struct V_268 * V_269 ,
T_14 F_150 ,
struct V_52 * V_52 )
{
struct V_3 * type ;
int V_10 , V_25 = 0 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
type = & V_6 [ V_10 ] ;
V_25 = F_179 ( V_269 , type -> V_9 ,
type -> V_2 , F_150 ,
V_52 ) ;
if ( V_25 ) {
F_32 ( L_92 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_181 ( struct V_268 * V_269 V_87 ,
union V_270 * V_203 )
{
if ( F_1 ( V_203 -> V_276 . V_276 . V_9 ,
V_203 -> V_276 . V_276 . V_2 ) < 0 )
return - V_8 ;
return 0 ;
}
int F_182 ( struct V_268 * V_269 , int V_15 ,
struct V_88 * V_89 ,
T_14 F_150 )
{
union V_270 V_271 ;
struct V_278 * V_279 ;
T_4 V_17 = 0 , V_280 = 0 , V_281 ;
int V_25 V_87 = 0 ;
V_279 = F_183 ( & V_89 -> V_90 , V_15 , true ) ;
if ( ! V_279 )
return - 1 ;
memset ( & V_271 , 0 , sizeof( V_271 ) ) ;
V_271 . V_278 . V_12 . type = V_282 ;
V_17 = V_279 -> V_17 ;
V_280 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_281 = V_280 - V_17 ;
V_271 . V_278 . V_12 . V_17 = sizeof( V_271 . V_278 ) ;
V_271 . V_278 . V_17 = V_280 ;
F_150 ( V_269 , & V_271 , NULL , NULL ) ;
F_184 ( V_279 ) ;
F_12 ( V_15 , NULL , 0 , V_281 ) ;
return V_280 ;
}
int F_185 ( union V_270 * V_203 ,
struct V_61 * V_62 )
{
T_4 V_283 , V_281 , V_17 = V_203 -> V_278 . V_17 ;
T_11 V_145 = F_80 ( V_62 -> V_15 , 0 , V_146 ) ;
char V_16 [ V_284 ] ;
F_80 ( V_62 -> V_15 , V_145 + sizeof( struct V_285 ) ,
V_148 ) ;
V_283 = F_113 ( V_62 -> V_15 , & V_62 -> V_257 ,
V_62 -> V_249 ) ;
V_281 = F_14 ( V_283 , sizeof( T_1 ) ) - V_283 ;
if ( F_16 ( V_62 -> V_15 , V_16 , V_281 ) < 0 )
F_186 ( L_93 ) ;
if ( V_62 -> V_249 ) {
int V_286 = F_11 ( V_250 , V_16 , V_281 ) ;
if ( V_286 <= 0 || V_286 != V_281 )
F_186 ( L_94 ) ;
}
if ( V_283 + V_281 != V_17 )
F_186 ( L_95 ) ;
F_168 ( V_62 -> V_89 ,
V_62 -> V_257 ) ;
return V_283 + V_281 ;
}
int F_187 ( struct V_268 * V_269 ,
struct V_45 * V_46 , T_7 V_39 ,
T_14 F_150 ,
struct V_52 * V_52 )
{
union V_270 V_271 ;
T_2 V_27 ;
int V_25 = 0 ;
if ( ! V_46 -> V_47 )
return V_25 ;
memset ( & V_271 , 0 , sizeof( V_271 ) ) ;
V_27 = V_46 -> V_51 + 1 ;
V_27 = F_14 ( V_27 , V_24 ) ;
memcpy ( & V_271 . V_37 . V_37 , V_46 -> V_37 , sizeof( V_46 -> V_37 ) ) ;
V_271 . V_37 . V_12 . type = V_287 ;
V_271 . V_37 . V_12 . V_39 = V_39 ;
V_271 . V_37 . V_38 = V_52 -> V_38 ;
V_271 . V_37 . V_12 . V_17 = sizeof( V_271 . V_37 ) + V_27 ;
memcpy ( & V_271 . V_37 . V_73 , V_46 -> V_50 , V_46 -> V_51 ) ;
V_25 = F_150 ( V_269 , & V_271 , NULL , V_52 ) ;
return V_25 ;
}
int F_188 ( struct V_268 * V_269 V_87 ,
union V_270 * V_203 ,
struct V_61 * V_62 )
{
F_105 ( & V_203 -> V_37 ,
V_203 -> V_37 . V_73 ,
V_62 ) ;
return 0 ;
}
void F_189 ( void )
{
V_91 = true ;
}
