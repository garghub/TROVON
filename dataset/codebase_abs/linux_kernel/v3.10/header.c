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
int V_25 = F_23 ( & V_62 -> V_65 . V_66 , V_15 ) ;
if ( V_25 )
return V_25 ;
for ( V_64 = F_27 ( & V_62 -> V_65 . V_67 ) ; V_64 ; V_64 = F_28 ( V_64 ) ) {
struct V_52 * V_46 = F_29 ( V_64 , struct V_52 , V_63 ) ;
V_25 = F_23 ( V_46 , V_15 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
int F_30 ( const char * V_68 , const char * V_69 ,
const char * V_2 , bool V_70 , bool V_71 )
{
const T_2 V_17 = V_72 ;
char * V_73 , * V_74 = F_31 ( V_17 ) ,
* V_75 = F_31 ( V_17 ) , * V_76 ;
int V_27 , V_25 = - 1 ;
bool V_77 = V_70 || V_71 ;
if ( V_70 ) {
if ( V_78 . V_79 ) {
F_32 ( L_2 ) ;
V_25 = 0 ;
goto V_80;
}
V_73 = ( char * ) V_2 ;
} else
V_73 = F_33 ( V_2 , NULL ) ;
if ( V_73 == NULL || V_74 == NULL || V_75 == NULL )
goto V_80;
V_27 = F_34 ( V_74 , V_17 , L_3 ,
V_69 , V_77 ? L_4 : L_5 ,
V_71 ? V_49 : V_73 ) ;
if ( F_35 ( V_74 , 0755 ) )
goto V_80;
snprintf ( V_74 + V_27 , V_17 - V_27 , L_6 , V_68 ) ;
if ( F_36 ( V_74 , V_81 ) ) {
if ( V_70 ) {
if ( F_37 ( L_7 , V_74 ) )
goto V_80;
} else if ( F_38 ( V_73 , V_74 ) && F_37 ( V_2 , V_74 ) )
goto V_80;
}
V_27 = F_34 ( V_75 , V_17 , L_8 ,
V_69 , V_68 ) ;
if ( F_36 ( V_75 , V_82 ) && F_35 ( V_75 , 0755 ) )
goto V_80;
snprintf ( V_75 + V_27 , V_17 - V_27 , L_6 , V_68 + 2 ) ;
V_76 = V_74 + strlen ( V_69 ) - 5 ;
memcpy ( V_76 , L_9 , 5 ) ;
if ( F_39 ( V_76 , V_75 ) == 0 )
V_25 = 0 ;
V_80:
if ( ! V_70 )
free ( V_73 ) ;
free ( V_74 ) ;
free ( V_75 ) ;
return V_25 ;
}
static int F_40 ( const T_5 * V_37 , T_2 V_83 ,
const char * V_2 , const char * V_69 ,
bool V_70 , bool V_71 )
{
char V_68 [ V_42 * 2 + 1 ] ;
F_41 ( V_37 , V_83 , V_68 ) ;
return F_30 ( V_68 , V_69 , V_2 ,
V_70 , V_71 ) ;
}
int F_42 ( const char * V_68 , const char * V_69 )
{
const T_2 V_17 = V_72 ;
char * V_74 = F_31 ( V_17 ) ,
* V_75 = F_31 ( V_17 ) ;
int V_25 = - 1 ;
if ( V_74 == NULL || V_75 == NULL )
goto V_80;
snprintf ( V_75 , V_17 , L_10 ,
V_69 , V_68 , V_68 + 2 ) ;
if ( F_36 ( V_75 , V_81 ) )
goto V_80;
if ( F_43 ( V_75 , V_74 , V_17 - 1 ) < 0 )
goto V_80;
if ( F_44 ( V_75 ) )
goto V_80;
snprintf ( V_75 , V_17 , L_10 ,
V_69 , V_68 , V_74 ) ;
if ( F_44 ( V_75 ) )
goto V_80;
V_25 = 0 ;
V_80:
free ( V_74 ) ;
free ( V_75 ) ;
return V_25 ;
}
static int F_45 ( struct V_45 * V_45 , const char * V_69 )
{
bool V_70 = V_45 -> V_84 && V_45 -> V_50 [ 0 ] != '/' ;
bool V_71 = F_22 ( V_45 -> V_48 ) ;
return F_40 ( V_45 -> V_37 , sizeof( V_45 -> V_37 ) ,
V_45 -> V_50 , V_69 ,
V_70 , V_71 ) ;
}
static int F_46 ( struct V_43 * V_44 , const char * V_69 )
{
struct V_45 * V_46 ;
int V_25 = 0 ;
F_21 (pos, head)
if ( F_45 ( V_46 , V_69 ) )
V_25 = - 1 ;
return V_25 ;
}
static int F_47 ( struct V_52 * V_52 , const char * V_69 )
{
int V_18 = F_46 ( & V_52 -> V_59 , V_69 ) ;
V_18 |= F_46 ( & V_52 -> V_60 , V_69 ) ;
return V_18 ;
}
static int F_48 ( struct V_61 * V_62 )
{
struct V_63 * V_64 ;
int V_18 ;
char V_69 [ V_72 ] ;
snprintf ( V_69 , sizeof( V_69 ) , L_11 , V_85 ) ;
if ( F_49 ( V_69 , 0755 ) != 0 && V_19 != V_86 )
return - 1 ;
V_18 = F_47 ( & V_62 -> V_65 . V_66 , V_69 ) ;
for ( V_64 = F_27 ( & V_62 -> V_65 . V_67 ) ; V_64 ; V_64 = F_28 ( V_64 ) ) {
struct V_52 * V_46 = F_29 ( V_64 , struct V_52 , V_63 ) ;
V_18 |= F_47 ( V_46 , V_69 ) ;
}
return V_18 ? - 1 : 0 ;
}
static bool F_50 ( struct V_52 * V_52 , bool V_87 )
{
bool V_18 = F_51 ( & V_52 -> V_59 , V_87 ) ;
V_18 |= F_51 ( & V_52 -> V_60 , V_87 ) ;
return V_18 ;
}
static bool F_52 ( struct V_61 * V_62 , bool V_87 )
{
struct V_63 * V_64 ;
bool V_18 = F_50 ( & V_62 -> V_65 . V_66 , V_87 ) ;
for ( V_64 = F_27 ( & V_62 -> V_65 . V_67 ) ; V_64 ; V_64 = F_28 ( V_64 ) ) {
struct V_52 * V_46 = F_29 ( V_64 , struct V_52 , V_63 ) ;
V_18 |= F_50 ( V_46 , V_87 ) ;
}
return V_18 ;
}
static int F_53 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 )
{
return F_54 ( V_15 , & V_90 -> V_91 ) ;
}
static int F_55 ( int V_15 , struct V_11 * T_8 ,
struct V_89 * V_90 V_88 )
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
if ( ! V_92 )
F_48 ( V_62 ) ;
return 0 ;
}
static int F_56 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
struct V_93 V_94 ;
int V_18 ;
V_18 = F_57 ( & V_94 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_94 . V_95 ) ;
}
static int F_58 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
struct V_93 V_94 ;
int V_18 ;
V_18 = F_57 ( & V_94 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_94 . V_96 ) ;
}
static int F_59 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
struct V_93 V_94 ;
int V_18 ;
V_18 = F_57 ( & V_94 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_94 . V_52 ) ;
}
static int F_60 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
return F_13 ( V_15 , V_97 ) ;
}
static int F_61 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
#ifndef F_62
#define F_62 NULL
#endif
T_9 * V_98 ;
char * V_16 = NULL ;
char * V_99 , * V_100 ;
const char * V_101 = F_62 ;
T_2 V_27 = 0 ;
int V_18 = - 1 ;
if ( ! V_101 )
return - 1 ;
V_98 = fopen ( L_13 , L_14 ) ;
if ( ! V_98 )
return - 1 ;
while ( F_63 ( & V_16 , & V_27 , V_98 ) > 0 ) {
V_18 = strncmp ( V_16 , V_101 , strlen ( V_101 ) ) ;
if ( ! V_18 )
break;
}
if ( V_18 )
goto V_102;
V_99 = V_16 ;
V_100 = strchr ( V_16 , ':' ) ;
if ( V_100 && * ( V_100 + 1 ) == ' ' && * ( V_100 + 2 ) )
V_99 = V_100 + 2 ;
V_100 = strchr ( V_99 , '\n' ) ;
if ( V_100 )
* V_100 = '\0' ;
V_100 = V_99 ;
while ( * V_100 ) {
if ( isspace ( * V_100 ) ) {
char * V_103 = V_100 + 1 ;
char * V_104 = V_103 ;
* V_100 = ' ' ;
while ( * V_104 && isspace ( * V_104 ) )
V_104 ++ ;
if ( V_104 != ( V_100 + 1 ) )
while ( ( * V_103 ++ = * V_104 ++ ) ) ;
}
V_100 ++ ;
}
V_18 = F_13 ( V_15 , V_99 ) ;
V_102:
free ( V_16 ) ;
fclose ( V_98 ) ;
return V_18 ;
}
static int F_64 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
long V_105 ;
T_3 V_106 , V_107 ;
int V_18 ;
V_105 = F_65 ( V_108 ) ;
if ( V_105 < 0 )
return - 1 ;
V_106 = ( T_3 ) ( V_105 & V_109 ) ;
V_105 = F_65 ( V_110 ) ;
if ( V_105 < 0 )
return - 1 ;
V_107 = ( T_3 ) ( V_105 & V_109 ) ;
V_18 = F_10 ( V_15 , & V_106 , sizeof( V_106 ) ) ;
if ( V_18 < 0 )
return V_18 ;
return F_10 ( V_15 , & V_107 , sizeof( V_107 ) ) ;
}
static int F_66 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 )
{
struct V_111 * V_112 ;
T_3 V_113 , V_114 , V_30 ;
int V_18 ;
V_113 = V_90 -> V_115 ;
V_18 = F_10 ( V_15 , & V_113 , sizeof( V_113 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_30 = ( T_3 ) sizeof( V_112 -> V_116 ) ;
V_18 = F_10 ( V_15 , & V_30 , sizeof( V_30 ) ) ;
if ( V_18 < 0 )
return V_18 ;
F_67 (evsel, &evlist->entries, node) {
V_18 = F_10 ( V_15 , & V_112 -> V_116 , V_30 ) ;
if ( V_18 < 0 )
return V_18 ;
V_114 = V_112 -> V_117 ;
V_18 = F_10 ( V_15 , & V_114 , sizeof( V_114 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_15 , F_68 ( V_112 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_15 , V_112 -> V_1 , V_112 -> V_117 * sizeof( T_1 ) ) ;
if ( V_18 < 0 )
return V_18 ;
}
return 0 ;
}
static int F_69 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
char V_16 [ V_118 ] ;
char V_119 [ 32 ] ;
T_3 V_10 , V_120 ;
int V_18 ;
sprintf ( V_119 , L_15 , F_70 () ) ;
V_18 = F_43 ( V_119 , V_16 , sizeof( V_16 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
V_16 [ V_18 ] = '\0' ;
V_120 = V_35 + 1 ;
V_18 = F_10 ( V_15 , & V_120 , sizeof( V_120 ) ) ;
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
static int F_71 ( struct V_121 * V_122 , int V_123 )
{
T_9 * V_124 ;
char V_74 [ V_118 ] ;
char * V_16 = NULL , * V_100 ;
T_2 V_27 = 0 ;
T_3 V_10 = 0 ;
int V_18 = - 1 ;
sprintf ( V_74 , V_125 , V_123 ) ;
V_124 = fopen ( V_74 , L_14 ) ;
if ( ! V_124 )
return - 1 ;
if ( F_63 ( & V_16 , & V_27 , V_124 ) <= 0 )
goto V_102;
fclose ( V_124 ) ;
V_100 = strchr ( V_16 , '\n' ) ;
if ( V_100 )
* V_100 = '\0' ;
for ( V_10 = 0 ; V_10 < V_122 -> V_126 ; V_10 ++ ) {
if ( ! strcmp ( V_16 , V_122 -> V_127 [ V_10 ] ) )
break;
}
if ( V_10 == V_122 -> V_126 ) {
V_122 -> V_127 [ V_10 ] = V_16 ;
V_122 -> V_126 ++ ;
V_16 = NULL ;
V_27 = 0 ;
}
sprintf ( V_74 , V_128 , V_123 ) ;
V_124 = fopen ( V_74 , L_14 ) ;
if ( ! V_124 )
goto V_102;
if ( F_63 ( & V_16 , & V_27 , V_124 ) <= 0 )
goto V_102;
V_100 = strchr ( V_16 , '\n' ) ;
if ( V_100 )
* V_100 = '\0' ;
for ( V_10 = 0 ; V_10 < V_122 -> V_129 ; V_10 ++ ) {
if ( ! strcmp ( V_16 , V_122 -> V_130 [ V_10 ] ) )
break;
}
if ( V_10 == V_122 -> V_129 ) {
V_122 -> V_130 [ V_10 ] = V_16 ;
V_122 -> V_129 ++ ;
V_16 = NULL ;
}
V_18 = 0 ;
V_102:
if( V_124 )
fclose ( V_124 ) ;
free ( V_16 ) ;
return V_18 ;
}
static void F_72 ( struct V_121 * V_122 )
{
T_3 V_10 ;
if ( ! V_122 )
return;
for ( V_10 = 0 ; V_10 < V_122 -> V_126 ; V_10 ++ )
free ( V_122 -> V_127 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < V_122 -> V_129 ; V_10 ++ )
free ( V_122 -> V_130 [ V_10 ] ) ;
free ( V_122 ) ;
}
static struct V_121 * F_73 ( void )
{
struct V_121 * V_122 ;
void * V_131 ;
T_3 V_105 , V_10 ;
T_2 V_30 ;
long V_132 ;
int V_18 = - 1 ;
V_132 = F_65 ( V_108 ) ;
if ( V_132 < 0 )
return NULL ;
V_105 = ( T_3 ) ( V_132 & V_109 ) ;
V_30 = V_105 * sizeof( char * ) ;
V_131 = calloc ( 1 , sizeof( * V_122 ) + 2 * V_30 ) ;
if ( ! V_131 )
return NULL ;
V_122 = V_131 ;
V_131 += sizeof( * V_122 ) ;
V_122 -> V_127 = V_131 ;
V_131 += V_30 ;
V_122 -> V_130 = V_131 ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
V_18 = F_71 ( V_122 , V_10 ) ;
if ( V_18 < 0 )
break;
}
if ( V_18 ) {
F_72 ( V_122 ) ;
V_122 = NULL ;
}
return V_122 ;
}
static int F_74 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
struct V_121 * V_122 ;
T_3 V_10 ;
int V_18 ;
V_122 = F_73 () ;
if ( ! V_122 )
return - 1 ;
V_18 = F_10 ( V_15 , & V_122 -> V_126 , sizeof( V_122 -> V_126 ) ) ;
if ( V_18 < 0 )
goto V_102;
for ( V_10 = 0 ; V_10 < V_122 -> V_126 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_122 -> V_127 [ V_10 ] ) ;
if ( V_18 < 0 )
goto V_102;
}
V_18 = F_10 ( V_15 , & V_122 -> V_129 , sizeof( V_122 -> V_129 ) ) ;
if ( V_18 < 0 )
goto V_102;
for ( V_10 = 0 ; V_10 < V_122 -> V_129 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_122 -> V_130 [ V_10 ] ) ;
if ( V_18 < 0 )
break;
}
V_102:
F_72 ( V_122 ) ;
return V_18 ;
}
static int F_75 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
char * V_16 = NULL ;
T_9 * V_124 ;
T_2 V_27 = 0 ;
int V_18 = - 1 , V_120 ;
T_10 V_133 ;
V_124 = fopen ( L_16 , L_14 ) ;
if ( ! V_124 )
return - 1 ;
while ( F_63 ( & V_16 , & V_27 , V_124 ) > 0 ) {
V_18 = strncmp ( V_16 , L_17 , 9 ) ;
if ( ! V_18 )
break;
}
if ( ! V_18 ) {
V_120 = sscanf ( V_16 , L_18 V_134 , & V_133 ) ;
if ( V_120 == 1 )
V_18 = F_10 ( V_15 , & V_133 , sizeof( V_133 ) ) ;
}
free ( V_16 ) ;
fclose ( V_124 ) ;
return V_18 ;
}
static int F_76 ( int V_15 , int V_135 )
{
char V_26 [ V_118 ] ;
char V_136 [ 32 ] ;
char * V_16 = NULL , * V_100 ;
T_2 V_27 = 0 ;
T_9 * V_124 ;
T_1 V_137 , V_138 , V_133 ;
int V_18 = - 1 ;
sprintf ( V_26 , L_19 , V_135 ) ;
V_124 = fopen ( V_26 , L_14 ) ;
if ( ! V_124 )
return - 1 ;
while ( F_63 ( & V_16 , & V_27 , V_124 ) > 0 ) {
if ( ! strchr ( V_16 , ':' ) )
continue;
if ( sscanf ( V_16 , L_20 V_134 , V_136 , & V_133 ) != 2 )
goto V_102;
if ( ! strcmp ( V_136 , L_17 ) )
V_137 = V_133 ;
if ( ! strcmp ( V_136 , L_21 ) )
V_138 = V_133 ;
}
fclose ( V_124 ) ;
V_124 = NULL ;
V_18 = F_10 ( V_15 , & V_137 , sizeof( T_1 ) ) ;
if ( V_18 )
goto V_102;
V_18 = F_10 ( V_15 , & V_138 , sizeof( T_1 ) ) ;
if ( V_18 )
goto V_102;
V_18 = - 1 ;
sprintf ( V_26 , L_22 , V_135 ) ;
V_124 = fopen ( V_26 , L_14 ) ;
if ( ! V_124 )
goto V_102;
if ( F_63 ( & V_16 , & V_27 , V_124 ) <= 0 )
goto V_102;
V_100 = strchr ( V_16 , '\n' ) ;
if ( V_100 )
* V_100 = '\0' ;
V_18 = F_13 ( V_15 , V_16 ) ;
V_102:
free ( V_16 ) ;
if ( V_124 )
fclose ( V_124 ) ;
return V_18 ;
}
static int F_77 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
char * V_16 = NULL ;
T_2 V_27 = 0 ;
T_9 * V_124 ;
struct V_139 * V_140 = NULL ;
char * V_141 ;
T_3 V_105 , V_10 , V_142 ;
int V_18 = - 1 ;
V_124 = fopen ( L_23 , L_14 ) ;
if ( ! V_124 )
return - 1 ;
if ( F_63 ( & V_16 , & V_27 , V_124 ) <= 0 )
goto V_102;
V_141 = strchr ( V_16 , '\n' ) ;
if ( V_141 )
* V_141 = '\0' ;
V_140 = F_78 ( V_16 ) ;
if ( ! V_140 )
goto V_102;
V_105 = ( T_3 ) V_140 -> V_105 ;
V_18 = F_10 ( V_15 , & V_105 , sizeof( V_105 ) ) ;
if ( V_18 < 0 )
goto V_102;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
V_142 = ( T_3 ) V_140 -> V_143 [ V_10 ] ;
V_18 = F_10 ( V_15 , & V_142 , sizeof( V_142 ) ) ;
if ( V_18 < 0 )
break;
V_18 = F_76 ( V_15 , V_10 ) ;
if ( V_18 < 0 )
break;
}
V_102:
free ( V_16 ) ;
fclose ( V_124 ) ;
free ( V_140 ) ;
return V_18 ;
}
static int F_79 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
struct V_144 * V_145 = NULL ;
T_11 V_146 = F_80 ( V_15 , 0 , V_147 ) ;
T_12 V_148 = 0 ;
int V_18 ;
V_18 = F_10 ( V_15 , & V_148 , sizeof( V_148 ) ) ;
if ( V_18 < 0 )
return V_18 ;
while ( ( V_145 = F_81 ( V_145 ) ) ) {
if ( ! V_145 -> V_2 )
continue;
V_148 ++ ;
V_18 = F_10 ( V_15 , & V_145 -> type , sizeof( V_145 -> type ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_15 , V_145 -> V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
}
if ( F_82 ( V_15 , & V_148 , sizeof( V_148 ) , V_146 ) != sizeof( V_148 ) ) {
F_80 ( V_15 , V_146 , V_149 ) ;
return - 1 ;
}
return 0 ;
}
static int F_83 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 )
{
T_3 V_150 = V_90 -> V_150 ;
struct V_111 * V_112 ;
int V_18 ;
V_18 = F_10 ( V_15 , & V_150 , sizeof( V_150 ) ) ;
if ( V_18 < 0 )
return V_18 ;
F_67 (evsel, &evlist->entries, node) {
if ( F_84 ( V_112 ) &&
V_112 -> V_151 > 1 ) {
const char * V_2 = V_112 -> V_152 ? : L_24 ;
T_3 V_153 = V_112 -> V_154 ;
T_3 V_151 = V_112 -> V_151 ;
V_18 = F_13 ( V_15 , V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_15 , & V_153 , sizeof( V_153 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_15 , & V_151 , sizeof( V_151 ) ) ;
if ( V_18 < 0 )
return V_18 ;
}
}
return 0 ;
}
static int F_85 ( int V_15 , struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
char V_155 [ 64 ] ;
int V_18 ;
V_18 = F_86 ( V_155 , sizeof( V_155 ) ) ;
if ( ! V_18 )
goto V_156;
return - 1 ;
V_156:
return F_13 ( V_15 , V_155 ) ;
}
static int F_87 ( int V_15 V_88 ,
struct V_11 * T_8 V_88 ,
struct V_89 * V_90 V_88 )
{
return 0 ;
}
static void F_88 ( struct V_11 * V_29 , int V_15 V_88 ,
T_9 * V_124 )
{
fprintf ( V_124 , L_25 , V_29 -> V_157 . V_158 ) ;
}
static void F_89 ( struct V_11 * V_29 , int V_15 V_88 ,
T_9 * V_124 )
{
fprintf ( V_124 , L_26 , V_29 -> V_157 . V_159 ) ;
}
static void F_90 ( struct V_11 * V_29 , int V_15 V_88 , T_9 * V_124 )
{
fprintf ( V_124 , L_27 , V_29 -> V_157 . V_160 ) ;
}
static void F_91 ( struct V_11 * V_29 , int V_15 V_88 ,
T_9 * V_124 )
{
fprintf ( V_124 , L_28 , V_29 -> V_157 . V_161 ) ;
}
static void F_92 ( struct V_11 * V_29 , int V_15 V_88 ,
T_9 * V_124 )
{
fprintf ( V_124 , L_29 , V_29 -> V_157 . V_162 ) ;
fprintf ( V_124 , L_30 , V_29 -> V_157 . V_163 ) ;
}
static void F_93 ( struct V_11 * V_29 , int V_15 V_88 ,
T_9 * V_124 )
{
fprintf ( V_124 , L_31 , V_29 -> V_157 . V_164 ) ;
}
static void F_94 ( struct V_11 * V_29 , int V_15 V_88 ,
T_9 * V_124 )
{
int V_105 , V_10 ;
char * V_26 ;
V_105 = V_29 -> V_157 . V_165 ;
V_26 = V_29 -> V_157 . V_166 ;
fprintf ( V_124 , L_32 ) ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
fprintf ( V_124 , L_33 , V_26 ) ;
V_26 += strlen ( V_26 ) + 1 ;
}
fputc ( '\n' , V_124 ) ;
}
static void F_95 ( struct V_11 * V_29 , int V_15 V_88 ,
T_9 * V_124 )
{
int V_105 , V_10 ;
char * V_26 ;
V_105 = V_29 -> V_157 . V_167 ;
V_26 = V_29 -> V_157 . V_168 ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
fprintf ( V_124 , L_34 , V_26 ) ;
V_26 += strlen ( V_26 ) + 1 ;
}
V_105 = V_29 -> V_157 . V_169 ;
V_26 = V_29 -> V_157 . V_170 ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
fprintf ( V_124 , L_35 , V_26 ) ;
V_26 += strlen ( V_26 ) + 1 ;
}
}
static void F_96 ( struct V_111 * V_171 )
{
struct V_111 * V_112 ;
if ( ! V_171 )
return;
for ( V_112 = V_171 ; V_112 -> V_116 . V_17 ; V_112 ++ ) {
if ( V_112 -> V_2 )
free ( V_112 -> V_2 ) ;
if ( V_112 -> V_1 )
free ( V_112 -> V_1 ) ;
}
free ( V_171 ) ;
}
static struct V_111 *
F_97 ( struct V_11 * V_29 , int V_15 )
{
struct V_111 * V_112 , * V_171 = NULL ;
T_1 * V_1 ;
void * V_16 = NULL ;
T_3 V_113 , V_30 , V_105 , V_10 , V_142 ;
T_4 V_18 ;
T_2 V_172 ;
V_18 = F_16 ( V_15 , & V_113 , sizeof( V_113 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_113 ) )
goto error;
if ( V_29 -> V_31 )
V_113 = F_17 ( V_113 ) ;
V_18 = F_16 ( V_15 , & V_30 , sizeof( V_30 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_30 ) )
goto error;
if ( V_29 -> V_31 )
V_30 = F_17 ( V_30 ) ;
V_16 = malloc ( V_30 ) ;
if ( ! V_16 )
goto error;
V_171 = calloc ( V_113 + 1 , sizeof( * V_171 ) ) ;
if ( ! V_171 )
goto error;
V_172 = sizeof( V_112 -> V_116 ) ;
if ( V_30 < V_172 )
V_172 = V_30 ;
for ( V_10 = 0 , V_112 = V_171 ; V_10 < V_113 ; V_112 ++ , V_10 ++ ) {
V_112 -> V_154 = V_10 ;
V_18 = F_16 ( V_15 , V_16 , V_30 ) ;
if ( V_18 != ( T_4 ) V_30 )
goto error;
if ( V_29 -> V_31 )
F_98 ( V_16 ) ;
memcpy ( & V_112 -> V_116 , V_16 , V_172 ) ;
V_18 = F_16 ( V_15 , & V_105 , sizeof( V_105 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_105 ) )
goto error;
if ( V_29 -> V_31 ) {
V_105 = F_17 ( V_105 ) ;
V_112 -> V_31 = true ;
}
V_112 -> V_2 = F_15 ( V_15 , V_29 ) ;
if ( ! V_105 )
continue;
V_1 = calloc ( V_105 , sizeof( * V_1 ) ) ;
if ( ! V_1 )
goto error;
V_112 -> V_117 = V_105 ;
V_112 -> V_1 = V_1 ;
for ( V_142 = 0 ; V_142 < V_105 ; V_142 ++ ) {
V_18 = F_16 ( V_15 , V_1 , sizeof( * V_1 ) ) ;
if ( V_18 != ( T_4 ) sizeof( * V_1 ) )
goto error;
if ( V_29 -> V_31 )
* V_1 = F_99 ( * V_1 ) ;
V_1 ++ ;
}
}
V_173:
if ( V_16 )
free ( V_16 ) ;
return V_171 ;
error:
if ( V_171 )
F_96 ( V_171 ) ;
V_171 = NULL ;
goto V_173;
}
static void F_100 ( struct V_11 * V_29 , int V_15 , T_9 * V_124 )
{
struct V_111 * V_112 , * V_171 = F_97 ( V_29 , V_15 ) ;
T_3 V_142 ;
T_1 * V_1 ;
if ( ! V_171 ) {
fprintf ( V_124 , L_36 ) ;
return;
}
for ( V_112 = V_171 ; V_112 -> V_116 . V_17 ; V_112 ++ ) {
fprintf ( V_124 , L_37 , V_112 -> V_2 ) ;
fprintf ( V_124 , L_38 V_174
L_39 V_174 L_40 V_174 ,
V_112 -> V_116 . type ,
( T_1 ) V_112 -> V_116 . V_175 ,
( T_1 ) V_112 -> V_116 . V_176 ,
( T_1 ) V_112 -> V_116 . V_177 ) ;
fprintf ( V_124 , L_41 ,
V_112 -> V_116 . V_178 ,
V_112 -> V_116 . V_179 ) ;
fprintf ( V_124 , L_42 ,
V_112 -> V_116 . V_180 ,
V_112 -> V_116 . V_181 ) ;
fprintf ( V_124 , L_43 , V_112 -> V_116 . V_182 ) ;
if ( V_112 -> V_117 ) {
fprintf ( V_124 , L_44 ) ;
for ( V_142 = 0 , V_1 = V_112 -> V_1 ; V_142 < V_112 -> V_117 ; V_142 ++ , V_1 ++ ) {
if ( V_142 )
fputc ( ',' , V_124 ) ;
fprintf ( V_124 , L_45 V_134 , * V_1 ) ;
}
fprintf ( V_124 , L_46 ) ;
}
fputc ( '\n' , V_124 ) ;
}
F_96 ( V_171 ) ;
}
static void F_101 ( struct V_11 * V_29 , int V_15 V_88 ,
T_9 * V_124 )
{
fprintf ( V_124 , L_47 , V_29 -> V_157 . V_183 ) ;
}
static void F_102 ( struct V_11 * V_29 , int V_15 V_88 ,
T_9 * V_124 )
{
T_3 V_105 , V_141 , V_10 ;
char * V_26 , * V_184 ;
T_10 V_137 , V_138 ;
V_105 = V_29 -> V_157 . V_185 ;
V_26 = V_29 -> V_157 . V_186 ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
V_141 = strtoul ( V_26 , & V_184 , 0 ) ;
if ( * V_184 != ':' )
goto error;
V_26 = V_184 + 1 ;
V_137 = F_103 ( V_26 , & V_184 , 0 ) ;
if ( * V_184 != ':' )
goto error;
V_26 = V_184 + 1 ;
V_138 = F_103 ( V_26 , & V_184 , 0 ) ;
if ( * V_184 != ':' )
goto error;
fprintf ( V_124 , L_48 V_134 L_49
L_50 V_134 L_51 ,
V_141 , V_137 , V_138 ) ;
V_26 = V_184 + 1 ;
fprintf ( V_124 , L_52 , V_141 , V_26 ) ;
V_26 += strlen ( V_26 ) + 1 ;
}
return;
error:
fprintf ( V_124 , L_53 ) ;
}
static void F_104 ( struct V_11 * V_29 , int V_15 V_88 , T_9 * V_124 )
{
fprintf ( V_124 , L_54 , V_29 -> V_157 . V_187 ) ;
}
static void F_105 ( struct V_11 * V_29 V_88 ,
int V_15 V_88 , T_9 * V_124 )
{
fprintf ( V_124 , L_55 ) ;
}
static void F_106 ( struct V_11 * V_29 , int V_15 V_88 ,
T_9 * V_124 )
{
const char * V_188 = L_56 ;
char * V_26 , * V_184 ;
T_3 V_148 ;
T_3 type ;
V_148 = V_29 -> V_157 . V_189 ;
if ( ! V_148 ) {
fprintf ( V_124 , L_57 ) ;
return;
}
V_26 = V_29 -> V_157 . V_190 ;
while ( V_148 ) {
type = strtoul ( V_26 , & V_184 , 0 ) ;
if ( * V_184 != ':' )
goto error;
V_26 = V_184 + 1 ;
fprintf ( V_124 , L_58 V_191 , V_188 , V_26 , type ) ;
V_188 = L_59 ;
V_26 += strlen ( V_26 ) + 1 ;
V_148 -- ;
}
fprintf ( V_124 , L_60 ) ;
if ( ! V_148 )
return;
error:
fprintf ( V_124 , L_61 ) ;
}
static void F_107 ( struct V_11 * V_29 , int V_15 V_88 ,
T_9 * V_124 )
{
struct V_61 * V_62 ;
struct V_111 * V_112 ;
T_3 V_105 = 0 ;
V_62 = F_26 ( V_29 , struct V_61 , V_12 ) ;
F_67 (evsel, &session->evlist->entries, node) {
if ( F_84 ( V_112 ) &&
V_112 -> V_151 > 1 ) {
fprintf ( V_124 , L_62 , V_112 -> V_152 ? : L_5 ,
F_68 ( V_112 ) ) ;
V_105 = V_112 -> V_151 - 1 ;
} else if ( V_105 ) {
fprintf ( V_124 , L_63 , F_68 ( V_112 ) ) ;
if ( -- V_105 == 0 )
fprintf ( V_124 , L_64 ) ;
}
}
}
static int F_108 ( struct V_40 * V_192 ,
char * V_74 ,
struct V_61 * V_62 )
{
int V_25 = - 1 ;
struct V_43 * V_44 ;
struct V_52 * V_52 ;
T_7 V_39 ;
struct V_45 * V_45 ;
enum V_193 V_194 ;
V_52 = F_109 ( V_62 , V_192 -> V_38 ) ;
if ( ! V_52 )
goto V_173;
V_39 = V_192 -> V_12 . V_39 & V_195 ;
switch ( V_39 ) {
case V_54 :
V_194 = V_196 ;
V_44 = & V_52 -> V_59 ;
break;
case V_57 :
V_194 = V_197 ;
V_44 = & V_52 -> V_59 ;
break;
case V_56 :
case V_58 :
V_194 = V_198 ;
V_44 = & V_52 -> V_60 ;
break;
default:
goto V_173;
}
V_45 = F_110 ( V_44 , V_74 ) ;
if ( V_45 != NULL ) {
char V_68 [ V_42 * 2 + 1 ] ;
F_111 ( V_45 , & V_192 -> V_37 ) ;
if ( V_74 [ 0 ] == '[' )
V_45 -> V_84 = V_194 ;
F_41 ( V_45 -> V_37 , sizeof( V_45 -> V_37 ) ,
V_68 ) ;
F_32 ( L_65 ,
V_45 -> V_50 , V_68 ) ;
}
V_25 = 0 ;
V_173:
return V_25 ;
}
static int F_112 ( struct V_11 * V_12 ,
int V_199 , T_1 V_146 , T_1 V_17 )
{
struct V_61 * V_62 = F_26 ( V_12 , struct V_61 , V_12 ) ;
struct {
struct V_200 V_12 ;
T_5 V_37 [ F_14 ( V_42 , sizeof( T_1 ) ) ] ;
char V_74 [ 0 ] ;
} V_201 ;
struct V_40 V_192 ;
char V_74 [ V_72 ] ;
T_1 V_202 = V_146 + V_17 ;
while ( V_146 < V_202 ) {
T_4 V_27 ;
if ( F_16 ( V_199 , & V_201 , sizeof( V_201 ) ) != sizeof( V_201 ) )
return - 1 ;
if ( V_12 -> V_31 )
F_113 ( & V_201 . V_12 ) ;
V_27 = V_201 . V_12 . V_17 - sizeof( V_201 ) ;
if ( F_16 ( V_199 , V_74 , V_27 ) != V_27 )
return - 1 ;
V_192 . V_12 = V_201 . V_12 ;
V_192 . V_38 = V_203 ;
if ( V_192 . V_12 . V_39 == V_58 ||
V_192 . V_12 . V_39 == V_57 )
V_192 . V_38 = V_204 ;
memcpy ( V_192 . V_37 , V_201 . V_37 , sizeof( V_192 . V_37 ) ) ;
F_108 ( & V_192 , V_74 , V_62 ) ;
V_146 += V_192 . V_12 . V_17 ;
}
return 0 ;
}
static int F_114 ( struct V_11 * V_12 ,
int V_199 , T_1 V_146 , T_1 V_17 )
{
struct V_61 * V_62 = F_26 ( V_12 , struct V_61 , V_12 ) ;
struct V_40 V_192 ;
char V_74 [ V_72 ] ;
T_1 V_202 = V_146 + V_17 , V_205 = V_146 ;
int V_25 = - 1 ;
while ( V_146 < V_202 ) {
T_4 V_27 ;
if ( F_16 ( V_199 , & V_192 , sizeof( V_192 ) ) != sizeof( V_192 ) )
goto V_173;
if ( V_12 -> V_31 )
F_113 ( & V_192 . V_12 ) ;
V_27 = V_192 . V_12 . V_17 - sizeof( V_192 ) ;
if ( F_16 ( V_199 , V_74 , V_27 ) != V_27 )
goto V_173;
if ( memcmp ( V_74 , L_66 , 13 ) == 0 ) {
if ( F_80 ( V_199 , V_205 , V_149 ) == ( T_11 ) - 1 )
return - 1 ;
return F_112 ( V_12 , V_199 , V_146 , V_17 ) ;
}
F_108 ( & V_192 , V_74 , V_62 ) ;
V_146 += V_192 . V_12 . V_17 ;
}
V_25 = 0 ;
V_173:
return V_25 ;
}
static int F_115 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 V_88 ,
int V_15 , void * V_207 )
{
T_4 V_18 = F_116 ( V_15 , V_207 , false ) ;
return V_18 < 0 ? - 1 : 0 ;
}
static int F_117 ( struct V_206 * T_13 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
if ( F_114 ( V_29 , V_15 , T_13 -> V_146 , T_13 -> V_17 ) )
F_32 ( L_67 ) ;
return 0 ;
}
static int F_118 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
V_29 -> V_157 . V_158 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_157 . V_158 ? 0 : - V_8 ;
}
static int F_119 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
V_29 -> V_157 . V_159 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_157 . V_159 ? 0 : - V_8 ;
}
static int F_120 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
V_29 -> V_157 . V_164 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_157 . V_164 ? 0 : - V_8 ;
}
static int F_121 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
V_29 -> V_157 . V_160 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_157 . V_160 ? 0 : - V_8 ;
}
static int F_122 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
T_2 V_18 ;
T_3 V_105 ;
V_18 = F_16 ( V_15 , & V_105 , sizeof( V_105 ) ) ;
if ( V_18 != sizeof( V_105 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_105 = F_17 ( V_105 ) ;
V_29 -> V_157 . V_162 = V_105 ;
V_18 = F_16 ( V_15 , & V_105 , sizeof( V_105 ) ) ;
if ( V_18 != sizeof( V_105 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_105 = F_17 ( V_105 ) ;
V_29 -> V_157 . V_163 = V_105 ;
return 0 ;
}
static int F_123 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
V_29 -> V_157 . V_161 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_157 . V_161 ? 0 : - V_8 ;
}
static int F_124 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
V_29 -> V_157 . V_187 = F_15 ( V_15 , V_29 ) ;
return V_29 -> V_157 . V_187 ? 0 : - V_8 ;
}
static int F_125 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
T_10 V_133 ;
T_2 V_18 ;
V_18 = F_16 ( V_15 , & V_133 , sizeof( V_133 ) ) ;
if ( V_18 != sizeof( V_133 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_133 = F_99 ( V_133 ) ;
V_29 -> V_157 . V_183 = V_133 ;
return 0 ;
}
static struct V_111 *
F_126 ( struct V_89 * V_90 , int V_154 )
{
struct V_111 * V_112 ;
F_67 (evsel, &evlist->entries, node) {
if ( V_112 -> V_154 == V_154 )
return V_112 ;
}
return NULL ;
}
static void
F_127 ( struct V_89 * V_90 ,
struct V_111 * V_208 )
{
struct V_111 * V_112 ;
if ( ! V_208 -> V_2 )
return;
V_112 = F_126 ( V_90 , V_208 -> V_154 ) ;
if ( ! V_112 )
return;
if ( V_112 -> V_2 )
return;
V_112 -> V_2 = F_128 ( V_208 -> V_2 ) ;
}
static int
F_129 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_12 , int V_15 ,
void * V_207 V_88 )
{
struct V_61 * V_62 ;
struct V_111 * V_112 , * V_171 = F_97 ( V_12 , V_15 ) ;
if ( ! V_171 )
return 0 ;
V_62 = F_26 ( V_12 , struct V_61 , V_12 ) ;
for ( V_112 = V_171 ; V_112 -> V_116 . V_17 ; V_112 ++ )
F_127 ( V_62 -> V_90 , V_112 ) ;
F_96 ( V_171 ) ;
return 0 ;
}
static int F_130 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
T_2 V_18 ;
char * V_26 ;
T_3 V_105 , V_10 ;
struct V_209 V_210 ;
V_18 = F_16 ( V_15 , & V_105 , sizeof( V_105 ) ) ;
if ( V_18 != sizeof( V_105 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_105 = F_17 ( V_105 ) ;
V_29 -> V_157 . V_165 = V_105 ;
F_131 ( & V_210 , 128 ) ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
if ( ! V_26 )
goto error;
F_132 ( & V_210 , V_26 , strlen ( V_26 ) + 1 ) ;
free ( V_26 ) ;
}
V_29 -> V_157 . V_166 = F_133 ( & V_210 , NULL ) ;
return 0 ;
error:
F_134 ( & V_210 ) ;
return - 1 ;
}
static int F_135 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
T_2 V_18 ;
T_3 V_105 , V_10 ;
char * V_26 ;
struct V_209 V_210 ;
V_18 = F_16 ( V_15 , & V_105 , sizeof( V_105 ) ) ;
if ( V_18 != sizeof( V_105 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_105 = F_17 ( V_105 ) ;
V_29 -> V_157 . V_167 = V_105 ;
F_131 ( & V_210 , 128 ) ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
if ( ! V_26 )
goto error;
F_132 ( & V_210 , V_26 , strlen ( V_26 ) + 1 ) ;
free ( V_26 ) ;
}
V_29 -> V_157 . V_168 = F_133 ( & V_210 , NULL ) ;
V_18 = F_16 ( V_15 , & V_105 , sizeof( V_105 ) ) ;
if ( V_18 != sizeof( V_105 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_105 = F_17 ( V_105 ) ;
V_29 -> V_157 . V_169 = V_105 ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
if ( ! V_26 )
goto error;
F_132 ( & V_210 , V_26 , strlen ( V_26 ) + 1 ) ;
free ( V_26 ) ;
}
V_29 -> V_157 . V_170 = F_133 ( & V_210 , NULL ) ;
return 0 ;
error:
F_134 ( & V_210 ) ;
return - 1 ;
}
static int F_136 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
T_2 V_18 ;
T_3 V_105 , V_135 , V_10 ;
char * V_26 ;
T_10 V_137 , V_138 ;
struct V_209 V_210 ;
V_18 = F_16 ( V_15 , & V_105 , sizeof( V_105 ) ) ;
if ( V_18 != sizeof( V_105 ) )
goto error;
if ( V_29 -> V_31 )
V_105 = F_17 ( V_105 ) ;
V_29 -> V_157 . V_185 = V_105 ;
F_131 ( & V_210 , 256 ) ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
V_18 = F_16 ( V_15 , & V_135 , sizeof( V_135 ) ) ;
if ( V_18 != sizeof( V_135 ) )
goto error;
V_18 = F_16 ( V_15 , & V_137 , sizeof( T_1 ) ) ;
if ( V_18 != sizeof( T_1 ) )
goto error;
V_18 = F_16 ( V_15 , & V_138 , sizeof( T_1 ) ) ;
if ( V_18 != sizeof( T_1 ) )
goto error;
if ( V_29 -> V_31 ) {
V_135 = F_17 ( V_135 ) ;
V_137 = F_99 ( V_137 ) ;
V_138 = F_99 ( V_138 ) ;
}
F_137 ( & V_210 , L_68 V_134 L_69 V_134 L_70 ,
V_135 , V_137 , V_138 ) ;
V_26 = F_15 ( V_15 , V_29 ) ;
if ( ! V_26 )
goto error;
F_132 ( & V_210 , V_26 , strlen ( V_26 ) + 1 ) ;
free ( V_26 ) ;
}
V_29 -> V_157 . V_186 = F_133 ( & V_210 , NULL ) ;
return 0 ;
error:
F_134 ( & V_210 ) ;
return - 1 ;
}
static int F_138 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
T_2 V_18 ;
char * V_2 ;
T_3 V_148 ;
T_3 type ;
struct V_209 V_210 ;
V_18 = F_16 ( V_15 , & V_148 , sizeof( V_148 ) ) ;
if ( V_18 != sizeof( V_148 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_148 = F_17 ( V_148 ) ;
if ( ! V_148 ) {
F_32 ( L_71 ) ;
return 0 ;
}
V_29 -> V_157 . V_189 = V_148 ;
F_131 ( & V_210 , 128 ) ;
while ( V_148 ) {
if ( F_16 ( V_15 , & type , sizeof( type ) ) != sizeof( type ) )
goto error;
if ( V_29 -> V_31 )
type = F_17 ( type ) ;
V_2 = F_15 ( V_15 , V_29 ) ;
if ( ! V_2 )
goto error;
F_137 ( & V_210 , L_72 , type , V_2 ) ;
F_132 ( & V_210 , L_5 , 1 ) ;
free ( V_2 ) ;
V_148 -- ;
}
V_29 -> V_157 . V_190 = F_133 ( & V_210 , NULL ) ;
return 0 ;
error:
F_134 ( & V_210 ) ;
return - 1 ;
}
static int F_139 ( struct V_206 * T_13 V_88 ,
struct V_11 * V_29 , int V_15 ,
void * V_207 V_88 )
{
T_2 V_18 = - 1 ;
T_3 V_10 , V_105 , V_150 ;
struct V_61 * V_62 ;
struct V_111 * V_112 , * V_211 = NULL ;
struct V_212 {
char * V_2 ;
T_3 V_153 ;
T_3 V_151 ;
} * V_213 ;
if ( F_16 ( V_15 , & V_150 , sizeof( V_150 ) ) != sizeof( V_150 ) )
return - 1 ;
if ( V_29 -> V_31 )
V_150 = F_17 ( V_150 ) ;
V_29 -> V_157 . V_150 = V_150 ;
if ( ! V_150 ) {
F_32 ( L_73 ) ;
return 0 ;
}
V_213 = calloc ( V_150 , sizeof( * V_213 ) ) ;
if ( ! V_213 )
return - 1 ;
for ( V_10 = 0 ; V_10 < V_150 ; V_10 ++ ) {
V_213 [ V_10 ] . V_2 = F_15 ( V_15 , V_29 ) ;
if ( ! V_213 [ V_10 ] . V_2 )
goto V_80;
if ( F_16 ( V_15 , & V_213 [ V_10 ] . V_153 , sizeof( T_3 ) ) != sizeof( T_3 ) )
goto V_80;
if ( F_16 ( V_15 , & V_213 [ V_10 ] . V_151 , sizeof( T_3 ) ) != sizeof( T_3 ) )
goto V_80;
if ( V_29 -> V_31 ) {
V_213 [ V_10 ] . V_153 = F_17 ( V_213 [ V_10 ] . V_153 ) ;
V_213 [ V_10 ] . V_151 = F_17 ( V_213 [ V_10 ] . V_151 ) ;
}
}
V_62 = F_26 ( V_29 , struct V_61 , V_12 ) ;
V_62 -> V_90 -> V_150 = V_150 ;
V_10 = V_105 = 0 ;
F_67 (evsel, &session->evlist->entries, node) {
if ( V_112 -> V_154 == ( int ) V_213 [ V_10 ] . V_153 ) {
V_112 -> V_211 = V_112 ;
if ( strcmp ( V_213 [ V_10 ] . V_2 , L_24 ) )
V_112 -> V_152 = V_213 [ V_10 ] . V_2 ;
V_112 -> V_151 = V_213 [ V_10 ] . V_151 ;
if ( V_10 >= V_150 || V_105 > 0 ) {
F_32 ( L_74 ) ;
goto V_80;
}
V_211 = V_112 ;
V_105 = V_112 -> V_151 - 1 ;
V_10 ++ ;
} else if ( V_105 ) {
V_112 -> V_211 = V_211 ;
V_105 -- ;
}
}
if ( V_10 != V_150 || V_105 != 0 ) {
F_32 ( L_74 ) ;
goto V_80;
}
V_18 = 0 ;
V_80:
while ( ( int ) -- V_10 >= 0 )
free ( V_213 [ V_10 ] . V_2 ) ;
free ( V_213 ) ;
return V_18 ;
}
static int F_140 ( struct V_206 * T_13 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_207 )
{
struct V_214 * V_215 = V_207 ;
if ( F_80 ( V_15 , T_13 -> V_146 , V_149 ) == ( T_11 ) - 1 ) {
F_32 ( L_75 V_134 L_76
L_77 , T_13 -> V_146 , V_13 ) ;
return 0 ;
}
if ( V_13 >= V_216 ) {
F_2 ( L_78 , V_13 ) ;
return 0 ;
}
if ( ! V_217 [ V_13 ] . V_218 )
return 0 ;
if ( ! V_217 [ V_13 ] . V_219 || V_215 -> V_220 )
V_217 [ V_13 ] . V_218 ( V_29 , V_15 , V_215 -> V_124 ) ;
else
fprintf ( V_215 -> V_124 , L_79 ,
V_217 [ V_13 ] . V_2 ) ;
return 0 ;
}
int F_141 ( struct V_61 * V_62 , T_9 * V_124 , bool V_220 )
{
struct V_214 V_215 ;
struct V_11 * V_12 = & V_62 -> V_12 ;
int V_15 = V_62 -> V_15 ;
V_215 . V_124 = V_124 ;
V_215 . V_220 = V_220 ;
F_142 ( V_12 , V_15 , & V_215 ,
F_140 ) ;
return 0 ;
}
static int F_143 ( int V_15 , struct V_11 * T_8 , int type ,
struct V_206 * * V_100 ,
struct V_89 * V_90 )
{
int V_25 ;
int V_18 = 0 ;
if ( F_8 ( T_8 , type ) ) {
if ( ! V_217 [ type ] . F_11 )
return - 1 ;
( * V_100 ) -> V_146 = F_80 ( V_15 , 0 , V_147 ) ;
V_25 = V_217 [ type ] . F_11 ( V_15 , T_8 , V_90 ) ;
if ( V_25 < 0 ) {
F_32 ( L_80 , type ) ;
F_80 ( V_15 , ( * V_100 ) -> V_146 , V_149 ) ;
return - 1 ;
}
( * V_100 ) -> V_17 = F_80 ( V_15 , 0 , V_147 ) - ( * V_100 ) -> V_146 ;
( * V_100 ) ++ ;
}
return V_18 ;
}
static int F_144 ( struct V_11 * V_12 ,
struct V_89 * V_90 , int V_15 )
{
int V_221 ;
struct V_206 * V_222 , * V_100 ;
int V_223 ;
T_1 V_224 ;
int V_13 ;
int V_25 ;
V_221 = F_145 ( V_12 -> V_14 , V_225 ) ;
if ( ! V_221 )
return 0 ;
V_222 = V_100 = calloc ( V_221 , sizeof( * V_222 ) ) ;
if ( V_222 == NULL )
return - V_8 ;
V_223 = sizeof( * V_222 ) * V_221 ;
V_224 = V_12 -> V_226 + V_12 -> V_227 ;
F_80 ( V_15 , V_224 + V_223 , V_149 ) ;
F_146 (feat, header->adds_features, HEADER_FEAT_BITS) {
if ( F_143 ( V_15 , V_12 , V_13 , & V_100 , V_90 ) )
F_6 ( V_12 , V_13 ) ;
}
F_80 ( V_15 , V_224 , V_149 ) ;
V_25 = F_10 ( V_15 , V_222 , V_223 ) ;
if ( V_25 < 0 )
F_32 ( L_81 ) ;
free ( V_222 ) ;
return V_25 ;
}
int F_147 ( int V_15 )
{
struct V_228 V_229 ;
int V_25 ;
V_229 = (struct V_228 ) {
. V_230 = V_231 ,
. V_17 = sizeof( V_229 ) ,
} ;
V_25 = F_10 ( V_15 , & V_229 , sizeof( V_229 ) ) ;
if ( V_25 < 0 ) {
F_32 ( L_82 ) ;
return V_25 ;
}
return 0 ;
}
int F_148 ( struct V_61 * V_62 ,
struct V_89 * V_90 ,
int V_15 , bool V_232 )
{
struct V_233 V_229 ;
struct V_234 V_235 ;
struct V_11 * V_12 = & V_62 -> V_12 ;
struct V_111 * V_112 , * V_236 = NULL ;
int V_25 ;
F_80 ( V_15 , sizeof( V_229 ) , V_149 ) ;
if ( V_62 -> V_90 != V_90 )
V_236 = F_149 ( V_62 -> V_90 ) ;
F_67 (evsel, &evlist->entries, node) {
V_112 -> V_237 = F_80 ( V_15 , 0 , V_147 ) ;
V_25 = F_10 ( V_15 , V_112 -> V_1 , V_112 -> V_117 * sizeof( T_1 ) ) ;
if ( V_25 < 0 ) {
V_238:
F_32 ( L_83 ) ;
return V_25 ;
}
if ( V_62 -> V_90 != V_90 ) {
V_25 = F_10 ( V_15 , V_236 -> V_1 , V_236 -> V_117 * sizeof( T_1 ) ) ;
if ( V_25 < 0 )
goto V_238;
V_112 -> V_117 += V_236 -> V_117 ;
V_236 = F_150 ( V_236 ) ;
}
}
V_12 -> V_239 = F_80 ( V_15 , 0 , V_147 ) ;
F_67 (evsel, &evlist->entries, node) {
V_235 = (struct V_234 ) {
. V_116 = V_112 -> V_116 ,
. V_117 = {
. V_146 = V_112 -> V_237 ,
. V_17 = V_112 -> V_117 * sizeof( T_1 ) ,
}
} ;
V_25 = F_10 ( V_15 , & V_235 , sizeof( V_235 ) ) ;
if ( V_25 < 0 ) {
F_32 ( L_84 ) ;
return V_25 ;
}
}
V_12 -> V_240 = F_80 ( V_15 , 0 , V_147 ) ;
V_12 -> V_241 = V_7 * sizeof( struct V_3 ) ;
if ( V_6 ) {
V_25 = F_10 ( V_15 , V_6 , V_12 -> V_241 ) ;
if ( V_25 < 0 ) {
F_32 ( L_85 ) ;
return V_25 ;
}
}
V_12 -> V_226 = F_80 ( V_15 , 0 , V_147 ) ;
if ( V_232 ) {
V_25 = F_144 ( V_12 , V_90 , V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_229 = (struct V_233 ) {
. V_230 = V_231 ,
. V_17 = sizeof( V_229 ) ,
. V_242 = sizeof( V_235 ) ,
. V_243 = {
. V_146 = V_12 -> V_239 ,
. V_17 = V_90 -> V_115 * sizeof( V_235 ) ,
} ,
. V_207 = {
. V_146 = V_12 -> V_226 ,
. V_17 = V_12 -> V_227 ,
} ,
. V_244 = {
. V_146 = V_12 -> V_240 ,
. V_17 = V_12 -> V_241 ,
} ,
} ;
memcpy ( & V_229 . V_14 , & V_12 -> V_14 , sizeof( V_12 -> V_14 ) ) ;
F_80 ( V_15 , 0 , V_149 ) ;
V_25 = F_10 ( V_15 , & V_229 , sizeof( V_229 ) ) ;
if ( V_25 < 0 ) {
F_32 ( L_83 ) ;
return V_25 ;
}
F_80 ( V_15 , V_12 -> V_226 + V_12 -> V_227 , V_149 ) ;
V_12 -> V_245 = 1 ;
return 0 ;
}
static int F_151 ( struct V_11 * V_12 ,
int V_15 , void * V_16 , T_2 V_17 )
{
if ( F_16 ( V_15 , V_16 , V_17 ) <= 0 )
return - 1 ;
if ( V_12 -> V_31 )
F_152 ( V_16 , V_17 ) ;
return 0 ;
}
int F_142 ( struct V_11 * V_12 , int V_15 ,
void * V_207 ,
int (* F_153)( struct V_206 * T_13 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_207 ) )
{
struct V_206 * V_222 , * V_246 ;
int V_221 ;
int V_223 ;
int V_13 ;
int V_25 ;
V_221 = F_145 ( V_12 -> V_14 , V_225 ) ;
if ( ! V_221 )
return 0 ;
V_222 = V_246 = calloc ( V_221 , sizeof( * V_222 ) ) ;
if ( ! V_222 )
return - 1 ;
V_223 = sizeof( * V_222 ) * V_221 ;
F_80 ( V_15 , V_12 -> V_226 + V_12 -> V_227 , V_149 ) ;
V_25 = F_151 ( V_12 , V_15 , V_222 , V_223 ) ;
if ( V_25 < 0 )
goto V_80;
F_146 (feat, header->adds_features, HEADER_LAST_FEATURE) {
V_25 = F_153 ( V_246 ++ , V_12 , V_13 , V_15 , V_207 ) ;
if ( V_25 < 0 )
goto V_80;
}
V_25 = 0 ;
V_80:
free ( V_222 ) ;
return V_25 ;
}
static int F_154 ( T_10 V_247 , struct V_11 * V_29 )
{
T_10 V_248 , V_242 ;
int V_10 ;
for ( V_10 = 0 ; V_249 [ V_10 ] ; V_10 ++ ) {
V_248 = V_249 [ V_10 ]
+ sizeof( struct V_206 ) ;
if ( V_247 != V_248 ) {
V_242 = F_99 ( V_247 ) ;
if ( V_242 != V_248 )
continue;
V_29 -> V_31 = true ;
}
F_32 ( L_86 ,
V_10 ,
V_29 -> V_31 ) ;
return 0 ;
}
return - 1 ;
}
static int F_155 ( T_10 V_247 , struct V_11 * V_29 )
{
T_1 V_242 ;
int V_10 ;
for ( V_10 = 0 ; V_250 [ V_10 ] ; V_10 ++ ) {
if ( V_247 != V_250 [ V_10 ] ) {
V_242 = F_99 ( V_247 ) ;
if ( V_242 != V_247 )
continue;
V_29 -> V_31 = true ;
}
F_32 ( L_87 , V_10 ) ;
return 0 ;
}
return - 1 ;
}
bool F_156 ( T_1 V_230 )
{
if ( ! memcmp ( & V_230 , V_251 , sizeof( V_230 ) )
|| V_230 == V_252
|| V_230 == V_253 )
return true ;
return false ;
}
static int F_157 ( T_1 V_230 , T_10 V_247 ,
bool V_254 , struct V_11 * V_29 )
{
int V_18 ;
V_18 = memcmp ( & V_230 , V_251 , sizeof( V_230 ) ) ;
if ( V_18 == 0 ) {
F_32 ( L_88 ) ;
if ( V_254 )
return F_155 ( V_247 , V_29 ) ;
return F_154 ( V_247 , V_29 ) ;
}
if ( V_230 == V_252 )
return 0 ;
if ( V_230 != V_253 )
return - 1 ;
V_29 -> V_31 = true ;
return 0 ;
}
int F_158 ( struct V_233 * V_12 ,
struct V_11 * V_29 , int V_15 )
{
int V_18 ;
F_80 ( V_15 , 0 , V_149 ) ;
V_18 = F_16 ( V_15 , V_12 , sizeof( * V_12 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
if ( F_157 ( V_12 -> V_230 ,
V_12 -> V_242 , false , V_29 ) < 0 ) {
F_32 ( L_89 ) ;
return - 1 ;
}
if ( V_29 -> V_31 ) {
F_152 ( V_12 , F_159 ( struct V_233 ,
V_14 ) ) ;
}
if ( V_12 -> V_17 != sizeof( * V_12 ) ) {
if ( V_12 -> V_17 == F_159 ( F_160 ( * V_12 ) , V_14 ) )
F_161 ( V_12 -> V_14 , V_225 ) ;
else
return - 1 ;
} else if ( V_29 -> V_31 ) {
F_152 ( & V_12 -> V_14 ,
F_162 ( V_225 ) ) ;
if ( ! F_9 ( V_255 , V_12 -> V_14 ) ) {
F_152 ( & V_12 -> V_14 ,
F_162 ( V_225 ) ) ;
F_163 ( & V_12 -> V_14 ,
F_164 ( V_225 ) ) ;
}
if ( ! F_9 ( V_255 , V_12 -> V_14 ) ) {
F_161 ( V_12 -> V_14 , V_225 ) ;
F_5 ( V_256 , V_12 -> V_14 ) ;
}
}
memcpy ( & V_29 -> V_14 , & V_12 -> V_14 ,
sizeof( V_29 -> V_14 ) ) ;
V_29 -> V_240 = V_12 -> V_244 . V_146 ;
V_29 -> V_241 = V_12 -> V_244 . V_17 ;
V_29 -> V_226 = V_12 -> V_207 . V_146 ;
V_29 -> V_227 = V_12 -> V_207 . V_17 ;
return 0 ;
}
static int F_165 ( struct V_206 * T_13 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_207 )
{
if ( F_80 ( V_15 , T_13 -> V_146 , V_149 ) == ( T_11 ) - 1 ) {
F_32 ( L_75 V_134 L_76
L_77 , T_13 -> V_146 , V_13 ) ;
return 0 ;
}
if ( V_13 >= V_216 ) {
F_32 ( L_90 , V_13 ) ;
return 0 ;
}
if ( ! V_217 [ V_13 ] . F_153 )
return 0 ;
return V_217 [ V_13 ] . F_153 ( T_13 , V_29 , V_15 , V_207 ) ;
}
static int F_166 ( struct V_228 * V_12 ,
struct V_11 * V_29 , int V_15 ,
bool V_257 )
{
int V_18 ;
V_18 = F_16 ( V_15 , V_12 , sizeof( * V_12 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
if ( F_157 ( V_12 -> V_230 , V_12 -> V_17 , true , V_29 ) < 0 ) {
F_32 ( L_91 ) ;
return - 1 ;
}
if ( V_29 -> V_31 )
V_12 -> V_17 = F_99 ( V_12 -> V_17 ) ;
if ( V_257 && F_10 ( V_258 , V_12 , sizeof( * V_12 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int F_167 ( struct V_61 * V_62 , int V_15 )
{
struct V_11 * V_12 = & V_62 -> V_12 ;
struct V_228 V_229 ;
if ( F_166 ( & V_229 , V_12 , V_15 ,
V_62 -> V_257 ) < 0 ) {
F_32 ( L_92 ) ;
return - V_259 ;
}
V_62 -> V_15 = V_15 ;
return 0 ;
}
static int F_168 ( int V_15 , struct V_11 * V_29 ,
struct V_234 * V_235 )
{
struct V_260 * V_116 = & V_235 -> V_116 ;
T_2 V_30 , V_261 ;
T_2 V_262 = sizeof( V_235 -> V_116 ) ;
int V_18 ;
memset ( V_235 , 0 , sizeof( * V_235 ) ) ;
V_18 = F_16 ( V_15 , V_116 , V_263 ) ;
if ( V_18 <= 0 ) {
F_32 ( L_93 ,
V_263 ) ;
return - 1 ;
}
V_30 = V_116 -> V_17 ;
if ( V_29 -> V_31 )
V_30 = F_17 ( V_30 ) ;
if ( V_30 == 0 ) {
V_30 = V_263 ;
} else if ( V_30 > V_262 ) {
F_32 ( L_94
L_95 , V_30 - V_262 ) ;
return - 1 ;
}
V_261 = V_30 - V_263 ;
if ( V_261 ) {
void * V_264 = V_116 ;
V_264 += V_263 ;
V_18 = F_16 ( V_15 , V_264 , V_261 ) ;
}
V_18 = F_16 ( V_15 , & V_235 -> V_117 , sizeof( V_235 -> V_117 ) ) ;
return V_18 <= 0 ? - 1 : 0 ;
}
static int F_169 ( struct V_111 * V_112 ,
struct V_265 * V_265 )
{
struct V_266 * V_208 ;
char V_20 [ 128 ] ;
if ( V_112 -> V_267 )
return 0 ;
if ( V_265 == NULL ) {
F_32 ( L_96 ) ;
return - 1 ;
}
V_208 = F_170 ( V_265 , V_112 -> V_116 . V_175 ) ;
if ( V_208 == NULL )
return - 1 ;
if ( ! V_112 -> V_2 ) {
snprintf ( V_20 , sizeof( V_20 ) , L_97 , V_208 -> system , V_208 -> V_2 ) ;
V_112 -> V_2 = F_128 ( V_20 ) ;
if ( V_112 -> V_2 == NULL )
return - 1 ;
}
V_112 -> V_267 = V_208 ;
return 0 ;
}
static int F_171 ( struct V_89 * V_90 ,
struct V_265 * V_265 )
{
struct V_111 * V_46 ;
F_67 (pos, &evlist->entries, node) {
if ( V_46 -> V_116 . type == V_268 &&
F_169 ( V_46 , V_265 ) )
return - 1 ;
}
return 0 ;
}
int F_172 ( struct V_61 * V_62 , int V_15 )
{
struct V_11 * V_12 = & V_62 -> V_12 ;
struct V_233 V_229 ;
struct V_234 V_235 ;
T_1 V_269 ;
int V_270 , V_271 , V_10 , V_142 ;
V_62 -> V_90 = F_173 () ;
if ( V_62 -> V_90 == NULL )
return - V_8 ;
if ( V_62 -> V_272 )
return F_167 ( V_62 , V_15 ) ;
if ( F_158 ( & V_229 , V_12 , V_15 ) < 0 )
return - V_259 ;
V_270 = V_229 . V_243 . V_17 / V_229 . V_242 ;
F_80 ( V_15 , V_229 . V_243 . V_146 , V_149 ) ;
for ( V_10 = 0 ; V_10 < V_270 ; V_10 ++ ) {
struct V_111 * V_112 ;
T_11 V_184 ;
if ( F_168 ( V_15 , V_12 , & V_235 ) < 0 )
goto V_273;
if ( V_12 -> V_31 )
F_98 ( & V_235 . V_116 ) ;
V_184 = F_80 ( V_15 , 0 , V_147 ) ;
V_112 = F_174 ( & V_235 . V_116 , V_10 ) ;
if ( V_112 == NULL )
goto V_274;
V_112 -> V_31 = V_12 -> V_31 ;
F_175 ( V_62 -> V_90 , V_112 ) ;
V_271 = V_235 . V_117 . V_17 / sizeof( T_1 ) ;
if ( F_176 ( V_112 , 1 , V_271 ) )
goto V_274;
F_80 ( V_15 , V_235 . V_117 . V_146 , V_149 ) ;
for ( V_142 = 0 ; V_142 < V_271 ; V_142 ++ ) {
if ( F_151 ( V_12 , V_15 , & V_269 , sizeof( V_269 ) ) )
goto V_273;
F_177 ( V_62 -> V_90 , V_112 , 0 , V_142 , V_269 ) ;
}
F_80 ( V_15 , V_184 , V_149 ) ;
}
V_78 . V_275 = V_270 ;
if ( V_229 . V_244 . V_17 ) {
F_80 ( V_15 , V_229 . V_244 . V_146 , V_149 ) ;
V_6 = malloc ( V_229 . V_244 . V_17 ) ;
if ( V_6 == NULL )
return - V_8 ;
if ( F_151 ( V_12 , V_15 , V_6 ,
V_229 . V_244 . V_17 ) )
goto V_273;
V_7 = V_229 . V_244 . V_17 / sizeof( struct V_3 ) ;
}
F_142 ( V_12 , V_15 , & V_62 -> V_265 ,
F_165 ) ;
F_80 ( V_15 , V_12 -> V_226 , V_149 ) ;
if ( F_171 ( V_62 -> V_90 ,
V_62 -> V_265 ) )
goto V_274;
V_12 -> V_245 = 1 ;
return 0 ;
V_273:
return - V_19 ;
V_274:
F_178 ( V_62 -> V_90 ) ;
V_62 -> V_90 = NULL ;
return - V_8 ;
}
int F_179 ( struct V_276 * V_277 ,
struct V_260 * V_116 , T_3 V_117 , T_1 * V_1 ,
T_14 F_153 )
{
union V_278 * V_279 ;
T_2 V_17 ;
int V_25 ;
V_17 = sizeof( struct V_260 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_17 += sizeof( struct V_200 ) ;
V_17 += V_117 * sizeof( T_1 ) ;
V_279 = malloc ( V_17 ) ;
if ( V_279 == NULL )
return - V_8 ;
V_279 -> V_116 . V_116 = * V_116 ;
memcpy ( V_279 -> V_116 . V_1 , V_1 , V_117 * sizeof( T_1 ) ) ;
V_279 -> V_116 . V_12 . type = V_280 ;
V_279 -> V_116 . V_12 . V_17 = ( T_7 ) V_17 ;
if ( V_279 -> V_116 . V_12 . V_17 == V_17 )
V_25 = F_153 ( V_277 , V_279 , NULL , NULL ) ;
else
V_25 = - V_281 ;
free ( V_279 ) ;
return V_25 ;
}
int F_180 ( struct V_276 * V_277 ,
struct V_61 * V_62 ,
T_14 F_153 )
{
struct V_111 * V_112 ;
int V_25 = 0 ;
F_67 (evsel, &session->evlist->entries, node) {
V_25 = F_179 ( V_277 , & V_112 -> V_116 , V_112 -> V_117 ,
V_112 -> V_1 , F_153 ) ;
if ( V_25 ) {
F_32 ( L_98 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_181 ( union V_278 * V_208 ,
struct V_89 * * V_282 )
{
T_3 V_10 , V_117 , V_283 ;
struct V_111 * V_112 ;
struct V_89 * V_90 = * V_282 ;
if ( V_90 == NULL ) {
* V_282 = V_90 = F_173 () ;
if ( V_90 == NULL )
return - V_8 ;
}
V_112 = F_174 ( & V_208 -> V_116 . V_116 , V_90 -> V_115 ) ;
if ( V_112 == NULL )
return - V_8 ;
F_175 ( V_90 , V_112 ) ;
V_117 = V_208 -> V_12 . V_17 ;
V_117 -= ( void * ) & V_208 -> V_116 . V_1 - ( void * ) V_208 ;
V_283 = V_117 / sizeof( T_1 ) ;
if ( F_176 ( V_112 , 1 , V_283 ) )
return - V_8 ;
for ( V_10 = 0 ; V_10 < V_283 ; V_10 ++ ) {
F_177 ( V_90 , V_112 , 0 , V_10 , V_208 -> V_116 . V_1 [ V_10 ] ) ;
}
return 0 ;
}
int F_182 ( struct V_276 * V_277 ,
T_1 V_9 , char * V_2 ,
T_14 F_153 ,
struct V_52 * V_52 )
{
union V_278 V_279 ;
T_2 V_17 = 0 ;
int V_25 = 0 ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
V_279 . V_284 . V_284 . V_9 = V_9 ;
memset ( V_279 . V_284 . V_284 . V_2 , 0 , V_5 ) ;
strncpy ( V_279 . V_284 . V_284 . V_2 , V_2 , V_5 - 1 ) ;
V_279 . V_284 . V_12 . type = V_285 ;
V_17 = strlen ( V_279 . V_284 . V_284 . V_2 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_279 . V_284 . V_12 . V_17 = sizeof( V_279 . V_284 ) -
( sizeof( V_279 . V_284 . V_284 . V_2 ) - V_17 ) ;
V_25 = F_153 ( V_277 , & V_279 , NULL , V_52 ) ;
return V_25 ;
}
int F_183 ( struct V_276 * V_277 ,
T_14 F_153 ,
struct V_52 * V_52 )
{
struct V_3 * type ;
int V_10 , V_25 = 0 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
type = & V_6 [ V_10 ] ;
V_25 = F_182 ( V_277 , type -> V_9 ,
type -> V_2 , F_153 ,
V_52 ) ;
if ( V_25 ) {
F_32 ( L_99 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_184 ( struct V_276 * V_277 V_88 ,
union V_278 * V_208 )
{
if ( F_1 ( V_208 -> V_284 . V_284 . V_9 ,
V_208 -> V_284 . V_284 . V_2 ) < 0 )
return - V_8 ;
return 0 ;
}
int F_185 ( struct V_276 * V_277 , int V_15 ,
struct V_89 * V_90 ,
T_14 F_153 )
{
union V_278 V_279 ;
struct V_286 * V_287 ;
T_4 V_17 = 0 , V_288 = 0 , V_289 ;
int V_25 V_88 = 0 ;
V_287 = F_186 ( & V_90 -> V_91 , V_15 , true ) ;
if ( ! V_287 )
return - 1 ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
V_279 . V_286 . V_12 . type = V_290 ;
V_17 = V_287 -> V_17 ;
V_288 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_289 = V_288 - V_17 ;
V_279 . V_286 . V_12 . V_17 = sizeof( V_279 . V_286 ) ;
V_279 . V_286 . V_17 = V_288 ;
F_153 ( V_277 , & V_279 , NULL , NULL ) ;
F_187 ( V_287 ) ;
F_12 ( V_15 , NULL , 0 , V_289 ) ;
return V_288 ;
}
int F_188 ( union V_278 * V_208 ,
struct V_61 * V_62 )
{
T_4 V_291 , V_289 , V_17 = V_208 -> V_286 . V_17 ;
T_11 V_146 = F_80 ( V_62 -> V_15 , 0 , V_147 ) ;
char V_16 [ V_292 ] ;
F_80 ( V_62 -> V_15 , V_146 + sizeof( struct V_293 ) ,
V_149 ) ;
V_291 = F_116 ( V_62 -> V_15 , & V_62 -> V_265 ,
V_62 -> V_257 ) ;
V_289 = F_14 ( V_291 , sizeof( T_1 ) ) - V_291 ;
if ( F_16 ( V_62 -> V_15 , V_16 , V_289 ) < 0 ) {
F_189 ( L_100 , V_294 ) ;
return - 1 ;
}
if ( V_62 -> V_257 ) {
int V_295 = F_11 ( V_258 , V_16 , V_289 ) ;
if ( V_295 <= 0 || V_295 != V_289 ) {
F_189 ( L_101 , V_294 ) ;
return - 1 ;
}
}
if ( V_291 + V_289 != V_17 ) {
F_189 ( L_102 , V_294 ) ;
return - 1 ;
}
F_171 ( V_62 -> V_90 ,
V_62 -> V_265 ) ;
return V_291 + V_289 ;
}
int F_190 ( struct V_276 * V_277 ,
struct V_45 * V_46 , T_7 V_39 ,
T_14 F_153 ,
struct V_52 * V_52 )
{
union V_278 V_279 ;
T_2 V_27 ;
int V_25 = 0 ;
if ( ! V_46 -> V_47 )
return V_25 ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
V_27 = V_46 -> V_51 + 1 ;
V_27 = F_14 ( V_27 , V_24 ) ;
memcpy ( & V_279 . V_37 . V_37 , V_46 -> V_37 , sizeof( V_46 -> V_37 ) ) ;
V_279 . V_37 . V_12 . type = V_296 ;
V_279 . V_37 . V_12 . V_39 = V_39 ;
V_279 . V_37 . V_38 = V_52 -> V_38 ;
V_279 . V_37 . V_12 . V_17 = sizeof( V_279 . V_37 ) + V_27 ;
memcpy ( & V_279 . V_37 . V_74 , V_46 -> V_50 , V_46 -> V_51 ) ;
V_25 = F_153 ( V_277 , & V_279 , NULL , V_52 ) ;
return V_25 ;
}
int F_191 ( struct V_276 * V_277 V_88 ,
union V_278 * V_208 ,
struct V_61 * V_62 )
{
F_108 ( & V_208 -> V_37 ,
V_208 -> V_37 . V_74 ,
V_62 ) ;
return 0 ;
}
void F_192 ( void )
{
V_92 = true ;
}
