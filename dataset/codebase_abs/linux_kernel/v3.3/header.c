int F_1 ( T_1 V_1 , const char * V_2 )
{
if ( strlen ( V_2 ) > V_3 )
F_2 ( L_1 , V_2 ) ;
if ( ! V_4 ) {
V_4 = malloc ( sizeof( struct V_5 ) ) ;
if ( V_4 == NULL )
return - V_6 ;
} else {
struct V_5 * V_7 ;
V_7 = realloc ( V_4 , ( V_8 + 1 ) * sizeof( * V_4 ) ) ;
if ( V_7 == NULL )
return - V_6 ;
V_4 = V_7 ;
}
memset ( & V_4 [ V_8 ] , 0 , sizeof( struct V_5 ) ) ;
V_4 [ V_8 ] . V_9 = V_1 ;
strncpy ( V_4 [ V_8 ] . V_2 , V_2 , V_3 - 1 ) ;
V_8 ++ ;
return 0 ;
}
char * F_3 ( T_1 V_1 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ ) {
if ( V_4 [ V_10 ] . V_9 == V_1 )
return V_4 [ V_10 ] . V_2 ;
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
V_34 = ( T_3 ) V_32 ;
V_35 = calloc ( V_32 , sizeof( char * ) ) ;
if ( ! V_35 )
return - V_6 ;
for ( V_10 = 0 ; V_10 < V_32 ; V_10 ++ )
V_35 [ V_10 ] = V_33 [ V_10 ] ;
return 0 ;
}
static int F_19 ( struct V_36 * V_37 , T_5 V_38 ,
T_6 V_39 , int V_15 )
{
struct V_40 * V_41 ;
F_20 (pos, head) {
int V_25 ;
struct V_42 V_43 ;
T_2 V_27 ;
if ( ! V_41 -> V_44 )
continue;
V_27 = V_41 -> V_45 + 1 ;
V_27 = F_14 ( V_27 , V_24 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
memcpy ( & V_43 . V_46 , V_41 -> V_46 , sizeof( V_41 -> V_46 ) ) ;
V_43 . V_38 = V_38 ;
V_43 . V_12 . V_39 = V_39 ;
V_43 . V_12 . V_17 = sizeof( V_43 ) + V_27 ;
V_25 = F_10 ( V_15 , & V_43 , sizeof( V_43 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_12 ( V_15 , V_41 -> V_47 ,
V_41 -> V_45 + 1 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_21 ( struct V_48 * V_48 , int V_15 )
{
int V_25 ;
T_6 V_49 = V_50 ,
V_51 = V_52 ;
if ( ! F_22 ( V_48 ) ) {
V_49 = V_53 ;
V_51 = V_54 ;
}
V_25 = F_19 ( & V_48 -> V_55 , V_48 -> V_38 ,
V_49 , V_15 ) ;
if ( V_25 == 0 )
V_25 = F_19 ( & V_48 -> V_56 ,
V_48 -> V_38 , V_51 , V_15 ) ;
return V_25 ;
}
static int F_23 ( struct V_11 * V_12 , int V_15 )
{
struct V_57 * V_58 = F_24 ( V_12 ,
struct V_57 , V_12 ) ;
struct V_59 * V_60 ;
int V_25 = F_21 ( & V_58 -> V_61 , V_15 ) ;
if ( V_25 )
return V_25 ;
for ( V_60 = F_25 ( & V_58 -> V_62 ) ; V_60 ; V_60 = F_26 ( V_60 ) ) {
struct V_48 * V_41 = F_27 ( V_60 , struct V_48 , V_59 ) ;
V_25 = F_21 ( V_41 , V_15 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
int F_28 ( const char * V_63 , const char * V_64 ,
const char * V_2 , bool V_65 )
{
const T_2 V_17 = V_66 ;
char * V_67 , * V_68 = F_29 ( V_17 ) ,
* V_69 = F_29 ( V_17 ) , * V_70 ;
int V_27 , V_25 = - 1 ;
if ( V_65 ) {
if ( V_71 . V_72 ) {
F_30 ( L_2 ) ;
return 0 ;
}
V_67 = ( char * ) V_2 ;
} else
V_67 = F_31 ( V_2 , NULL ) ;
if ( V_67 == NULL || V_68 == NULL || V_69 == NULL )
goto V_73;
V_27 = F_32 ( V_68 , V_17 , L_3 ,
V_64 , V_65 ? L_4 : L_5 , V_67 ) ;
if ( F_33 ( V_68 , 0755 ) )
goto V_73;
snprintf ( V_68 + V_27 , sizeof( V_68 ) - V_27 , L_6 , V_63 ) ;
if ( F_34 ( V_68 , V_74 ) ) {
if ( V_65 ) {
if ( F_35 ( L_7 , V_68 ) )
goto V_73;
} else if ( F_36 ( V_67 , V_68 ) && F_35 ( V_2 , V_68 ) )
goto V_73;
}
V_27 = F_32 ( V_69 , V_17 , L_8 ,
V_64 , V_63 ) ;
if ( F_34 ( V_69 , V_75 ) && F_33 ( V_69 , 0755 ) )
goto V_73;
snprintf ( V_69 + V_27 , V_17 - V_27 , L_6 , V_63 + 2 ) ;
V_70 = V_68 + strlen ( V_64 ) - 5 ;
memcpy ( V_70 , L_9 , 5 ) ;
if ( F_37 ( V_70 , V_69 ) == 0 )
V_25 = 0 ;
V_73:
if ( ! V_65 )
free ( V_67 ) ;
free ( V_68 ) ;
free ( V_69 ) ;
return V_25 ;
}
static int F_38 ( const T_7 * V_46 , T_2 V_76 ,
const char * V_2 , const char * V_64 ,
bool V_65 )
{
char V_63 [ V_77 * 2 + 1 ] ;
F_39 ( V_46 , V_76 , V_63 ) ;
return F_28 ( V_63 , V_64 , V_2 , V_65 ) ;
}
int F_40 ( const char * V_63 , const char * V_64 )
{
const T_2 V_17 = V_66 ;
char * V_68 = F_29 ( V_17 ) ,
* V_69 = F_29 ( V_17 ) ;
int V_25 = - 1 ;
if ( V_68 == NULL || V_69 == NULL )
goto V_73;
snprintf ( V_69 , V_17 , L_10 ,
V_64 , V_63 , V_63 + 2 ) ;
if ( F_34 ( V_69 , V_74 ) )
goto V_73;
if ( F_41 ( V_69 , V_68 , V_17 - 1 ) < 0 )
goto V_73;
if ( F_42 ( V_69 ) )
goto V_73;
snprintf ( V_69 , V_17 , L_10 ,
V_64 , V_63 , V_68 ) ;
if ( F_42 ( V_69 ) )
goto V_73;
V_25 = 0 ;
V_73:
free ( V_68 ) ;
free ( V_69 ) ;
return V_25 ;
}
static int F_43 ( struct V_40 * V_40 , const char * V_64 )
{
bool V_65 = V_40 -> V_78 && V_40 -> V_47 [ 0 ] != '/' ;
return F_38 ( V_40 -> V_46 , sizeof( V_40 -> V_46 ) ,
V_40 -> V_47 , V_64 , V_65 ) ;
}
static int F_44 ( struct V_36 * V_37 , const char * V_64 )
{
struct V_40 * V_41 ;
int V_25 = 0 ;
F_20 (pos, head)
if ( F_43 ( V_41 , V_64 ) )
V_25 = - 1 ;
return V_25 ;
}
static int F_45 ( struct V_48 * V_48 , const char * V_64 )
{
int V_18 = F_44 ( & V_48 -> V_55 , V_64 ) ;
V_18 |= F_44 ( & V_48 -> V_56 , V_64 ) ;
return V_18 ;
}
static int F_46 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
int V_18 ;
char V_64 [ V_66 ] ;
snprintf ( V_64 , sizeof( V_64 ) , L_11 , V_79 ) ;
if ( F_47 ( V_64 , 0755 ) != 0 && V_19 != V_80 )
return - 1 ;
V_18 = F_45 ( & V_58 -> V_61 , V_64 ) ;
for ( V_60 = F_25 ( & V_58 -> V_62 ) ; V_60 ; V_60 = F_26 ( V_60 ) ) {
struct V_48 * V_41 = F_27 ( V_60 , struct V_48 , V_59 ) ;
V_18 |= F_45 ( V_41 , V_64 ) ;
}
return V_18 ? - 1 : 0 ;
}
static bool F_48 ( struct V_48 * V_48 , bool V_81 )
{
bool V_18 = F_49 ( & V_48 -> V_55 , V_81 ) ;
V_18 |= F_49 ( & V_48 -> V_56 , V_81 ) ;
return V_18 ;
}
static bool F_50 ( struct V_57 * V_58 , bool V_81 )
{
struct V_59 * V_60 ;
bool V_18 = F_48 ( & V_58 -> V_61 , V_81 ) ;
for ( V_60 = F_25 ( & V_58 -> V_62 ) ; V_60 ; V_60 = F_26 ( V_60 ) ) {
struct V_48 * V_41 = F_27 ( V_60 , struct V_48 , V_59 ) ;
V_18 |= F_48 ( V_41 , V_81 ) ;
}
return V_18 ;
}
static int F_51 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 )
{
return F_52 ( V_15 , & V_84 -> V_85 ) ;
}
static int F_53 ( int V_15 , struct V_11 * T_8 ,
struct V_83 * V_84 V_82 )
{
struct V_57 * V_58 ;
int V_25 ;
V_58 = F_24 ( T_8 , struct V_57 , V_12 ) ;
if ( ! F_50 ( V_58 , true ) )
return - 1 ;
V_25 = F_23 ( T_8 , V_15 ) ;
if ( V_25 < 0 ) {
F_30 ( L_12 ) ;
return V_25 ;
}
if ( ! V_86 )
F_46 ( V_58 ) ;
return 0 ;
}
static int F_54 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_87 V_88 ;
int V_18 ;
V_18 = F_55 ( & V_88 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_88 . V_89 ) ;
}
static int F_56 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_87 V_88 ;
int V_18 ;
V_18 = F_55 ( & V_88 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_88 . V_90 ) ;
}
static int F_57 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_87 V_88 ;
int V_18 ;
V_18 = F_55 ( & V_88 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_88 . V_48 ) ;
}
static int F_58 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
return F_13 ( V_15 , V_91 ) ;
}
static int F_59 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
#ifndef F_60
#define F_60 NULL
#endif
T_9 * V_92 ;
char * V_16 = NULL ;
char * V_93 , * V_94 ;
const char * V_95 = F_60 ;
T_2 V_27 = 0 ;
int V_18 = - 1 ;
if ( ! V_95 )
return - 1 ;
V_92 = fopen ( L_13 , L_14 ) ;
if ( ! V_92 )
return - 1 ;
while ( F_61 ( & V_16 , & V_27 , V_92 ) > 0 ) {
V_18 = strncmp ( V_16 , V_95 , strlen ( V_95 ) ) ;
if ( ! V_18 )
break;
}
if ( V_18 )
goto V_96;
V_93 = V_16 ;
V_94 = strchr ( V_16 , ':' ) ;
if ( V_94 && * ( V_94 + 1 ) == ' ' && * ( V_94 + 2 ) )
V_93 = V_94 + 2 ;
V_94 = strchr ( V_93 , '\n' ) ;
if ( V_94 )
* V_94 = '\0' ;
V_94 = V_93 ;
while ( * V_94 ) {
if ( isspace ( * V_94 ) ) {
char * V_97 = V_94 + 1 ;
char * V_98 = V_97 ;
* V_94 = ' ' ;
while ( * V_98 && isspace ( * V_98 ) )
V_98 ++ ;
if ( V_98 != ( V_94 + 1 ) )
while ( ( * V_97 ++ = * V_98 ++ ) ) ;
}
V_94 ++ ;
}
V_18 = F_13 ( V_15 , V_93 ) ;
V_96:
free ( V_16 ) ;
fclose ( V_92 ) ;
return V_18 ;
}
static int F_62 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
long V_99 ;
T_3 V_100 , V_101 ;
int V_18 ;
V_99 = F_63 ( V_102 ) ;
if ( V_99 < 0 )
return - 1 ;
V_100 = ( T_3 ) ( V_99 & V_103 ) ;
V_99 = F_63 ( V_104 ) ;
if ( V_99 < 0 )
return - 1 ;
V_101 = ( T_3 ) ( V_99 & V_103 ) ;
V_18 = F_10 ( V_15 , & V_100 , sizeof( V_100 ) ) ;
if ( V_18 < 0 )
return V_18 ;
return F_10 ( V_15 , & V_101 , sizeof( V_101 ) ) ;
}
static int F_64 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 )
{
struct V_105 * V_106 ;
T_3 V_107 = 0 , V_108 , V_30 ;
int V_18 ;
F_65 (attr, &evlist->entries, node)
V_107 ++ ;
V_18 = F_10 ( V_15 , & V_107 , sizeof( V_107 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_30 = ( T_3 ) sizeof( V_106 -> V_106 ) ;
V_18 = F_10 ( V_15 , & V_30 , sizeof( V_30 ) ) ;
if ( V_18 < 0 )
return V_18 ;
F_65 (attr, &evlist->entries, node) {
V_18 = F_10 ( V_15 , & V_106 -> V_106 , V_30 ) ;
if ( V_18 < 0 )
return V_18 ;
V_108 = V_106 -> V_109 ;
V_18 = F_10 ( V_15 , & V_108 , sizeof( V_108 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_15 , F_66 ( V_106 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_15 , V_106 -> V_1 , V_106 -> V_109 * sizeof( T_1 ) ) ;
if ( V_18 < 0 )
return V_18 ;
}
return 0 ;
}
static int F_67 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
char V_16 [ V_110 ] ;
char V_111 [ 32 ] ;
T_3 V_10 , V_112 ;
int V_18 ;
sprintf ( V_111 , L_15 , F_68 () ) ;
V_18 = F_41 ( V_111 , V_16 , sizeof( V_16 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
V_16 [ V_18 ] = '\0' ;
V_112 = V_34 + 1 ;
V_18 = F_10 ( V_15 , & V_112 , sizeof( V_112 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_15 , V_16 ) ;
if ( V_18 < 0 )
return V_18 ;
for ( V_10 = 0 ; V_10 < V_34 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_35 [ V_10 ] ) ;
if ( V_18 < 0 )
return V_18 ;
}
return 0 ;
}
static int F_69 ( struct V_113 * V_114 , int V_115 )
{
T_9 * V_116 ;
char V_68 [ V_110 ] ;
char * V_16 = NULL , * V_94 ;
T_2 V_27 = 0 ;
T_3 V_10 = 0 ;
int V_18 = - 1 ;
sprintf ( V_68 , V_117 , V_115 ) ;
V_116 = fopen ( V_68 , L_14 ) ;
if ( ! V_116 )
return - 1 ;
if ( F_61 ( & V_16 , & V_27 , V_116 ) <= 0 )
goto V_96;
fclose ( V_116 ) ;
V_94 = strchr ( V_16 , '\n' ) ;
if ( V_94 )
* V_94 = '\0' ;
for ( V_10 = 0 ; V_10 < V_114 -> V_118 ; V_10 ++ ) {
if ( ! strcmp ( V_16 , V_114 -> V_119 [ V_10 ] ) )
break;
}
if ( V_10 == V_114 -> V_118 ) {
V_114 -> V_119 [ V_10 ] = V_16 ;
V_114 -> V_118 ++ ;
V_16 = NULL ;
V_27 = 0 ;
}
sprintf ( V_68 , V_120 , V_115 ) ;
V_116 = fopen ( V_68 , L_14 ) ;
if ( ! V_116 )
goto V_96;
if ( F_61 ( & V_16 , & V_27 , V_116 ) <= 0 )
goto V_96;
V_94 = strchr ( V_16 , '\n' ) ;
if ( V_94 )
* V_94 = '\0' ;
for ( V_10 = 0 ; V_10 < V_114 -> V_121 ; V_10 ++ ) {
if ( ! strcmp ( V_16 , V_114 -> V_122 [ V_10 ] ) )
break;
}
if ( V_10 == V_114 -> V_121 ) {
V_114 -> V_122 [ V_10 ] = V_16 ;
V_114 -> V_121 ++ ;
V_16 = NULL ;
}
V_18 = 0 ;
V_96:
if( V_116 )
fclose ( V_116 ) ;
free ( V_16 ) ;
return V_18 ;
}
static void F_70 ( struct V_113 * V_114 )
{
T_3 V_10 ;
if ( ! V_114 )
return;
for ( V_10 = 0 ; V_10 < V_114 -> V_118 ; V_10 ++ )
free ( V_114 -> V_119 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < V_114 -> V_121 ; V_10 ++ )
free ( V_114 -> V_122 [ V_10 ] ) ;
free ( V_114 ) ;
}
static struct V_113 * F_71 ( void )
{
struct V_113 * V_114 ;
void * V_123 ;
T_3 V_99 , V_10 ;
T_2 V_30 ;
long V_124 ;
int V_18 = - 1 ;
V_124 = F_63 ( V_102 ) ;
if ( V_124 < 0 )
return NULL ;
V_99 = ( T_3 ) ( V_124 & V_103 ) ;
V_30 = V_99 * sizeof( char * ) ;
V_123 = calloc ( 1 , sizeof( * V_114 ) + 2 * V_30 ) ;
if ( ! V_123 )
return NULL ;
V_114 = V_123 ;
V_123 += sizeof( * V_114 ) ;
V_114 -> V_119 = V_123 ;
V_123 += V_30 ;
V_114 -> V_122 = V_123 ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_18 = F_69 ( V_114 , V_10 ) ;
if ( V_18 < 0 )
break;
}
if ( V_18 ) {
F_70 ( V_114 ) ;
V_114 = NULL ;
}
return V_114 ;
}
static int F_72 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_113 * V_114 ;
T_3 V_10 ;
int V_18 ;
V_114 = F_71 () ;
if ( ! V_114 )
return - 1 ;
V_18 = F_10 ( V_15 , & V_114 -> V_118 , sizeof( V_114 -> V_118 ) ) ;
if ( V_18 < 0 )
goto V_96;
for ( V_10 = 0 ; V_10 < V_114 -> V_118 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_114 -> V_119 [ V_10 ] ) ;
if ( V_18 < 0 )
goto V_96;
}
V_18 = F_10 ( V_15 , & V_114 -> V_121 , sizeof( V_114 -> V_121 ) ) ;
if ( V_18 < 0 )
goto V_96;
for ( V_10 = 0 ; V_10 < V_114 -> V_121 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_114 -> V_122 [ V_10 ] ) ;
if ( V_18 < 0 )
break;
}
V_96:
F_70 ( V_114 ) ;
return V_18 ;
}
static int F_73 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
char * V_16 = NULL ;
T_9 * V_116 ;
T_2 V_27 = 0 ;
int V_18 = - 1 , V_112 ;
T_10 V_125 ;
V_116 = fopen ( L_16 , L_14 ) ;
if ( ! V_116 )
return - 1 ;
while ( F_61 ( & V_16 , & V_27 , V_116 ) > 0 ) {
V_18 = strncmp ( V_16 , L_17 , 9 ) ;
if ( ! V_18 )
break;
}
if ( ! V_18 ) {
V_112 = sscanf ( V_16 , L_18 V_126 , & V_125 ) ;
if ( V_112 == 1 )
V_18 = F_10 ( V_15 , & V_125 , sizeof( V_125 ) ) ;
}
free ( V_16 ) ;
fclose ( V_116 ) ;
return V_18 ;
}
static int F_74 ( int V_15 , int V_127 )
{
char V_26 [ V_110 ] ;
char V_128 [ 32 ] ;
char * V_16 = NULL , * V_94 ;
T_2 V_27 = 0 ;
T_9 * V_116 ;
T_1 V_129 , V_130 , V_125 ;
int V_18 = - 1 ;
sprintf ( V_26 , L_19 , V_127 ) ;
V_116 = fopen ( V_26 , L_14 ) ;
if ( ! V_116 )
return - 1 ;
while ( F_61 ( & V_16 , & V_27 , V_116 ) > 0 ) {
if ( ! strchr ( V_16 , ':' ) )
continue;
if ( sscanf ( V_16 , L_20 V_126 , V_128 , & V_125 ) != 2 )
goto V_96;
if ( ! strcmp ( V_128 , L_17 ) )
V_129 = V_125 ;
if ( ! strcmp ( V_128 , L_21 ) )
V_130 = V_125 ;
}
fclose ( V_116 ) ;
V_18 = F_10 ( V_15 , & V_129 , sizeof( T_1 ) ) ;
if ( V_18 )
goto V_96;
V_18 = F_10 ( V_15 , & V_130 , sizeof( T_1 ) ) ;
if ( V_18 )
goto V_96;
V_18 = - 1 ;
sprintf ( V_26 , L_22 , V_127 ) ;
V_116 = fopen ( V_26 , L_14 ) ;
if ( ! V_116 )
goto V_96;
if ( F_61 ( & V_16 , & V_27 , V_116 ) <= 0 )
goto V_96;
V_94 = strchr ( V_16 , '\n' ) ;
if ( V_94 )
* V_94 = '\0' ;
V_18 = F_13 ( V_15 , V_16 ) ;
V_96:
free ( V_16 ) ;
fclose ( V_116 ) ;
return V_18 ;
}
static int F_75 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
char * V_16 = NULL ;
T_2 V_27 = 0 ;
T_9 * V_116 ;
struct V_131 * V_132 = NULL ;
char * V_133 ;
T_3 V_99 , V_10 , V_134 ;
int V_18 = - 1 ;
V_116 = fopen ( L_23 , L_14 ) ;
if ( ! V_116 )
return - 1 ;
if ( F_61 ( & V_16 , & V_27 , V_116 ) <= 0 )
goto V_96;
V_133 = strchr ( V_16 , '\n' ) ;
if ( V_133 )
* V_133 = '\0' ;
V_132 = F_76 ( V_16 ) ;
if ( ! V_132 )
goto V_96;
V_99 = ( T_3 ) V_132 -> V_99 ;
V_18 = F_10 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 < 0 )
goto V_96;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_134 = ( T_3 ) V_132 -> V_135 [ V_10 ] ;
V_18 = F_10 ( V_15 , & V_134 , sizeof( V_134 ) ) ;
if ( V_18 < 0 )
break;
V_18 = F_74 ( V_15 , V_10 ) ;
if ( V_18 < 0 )
break;
}
V_96:
free ( V_16 ) ;
fclose ( V_116 ) ;
free ( V_132 ) ;
return V_18 ;
}
static int F_77 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
char V_136 [ 64 ] ;
int V_18 ;
V_18 = F_78 ( V_136 , sizeof( V_136 ) ) ;
if ( ! V_18 )
goto V_137;
return - 1 ;
V_137:
return F_13 ( V_15 , V_136 ) ;
}
static void F_79 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_24 , V_26 ) ;
free ( V_26 ) ;
}
static void F_80 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_25 , V_26 ) ;
free ( V_26 ) ;
}
static void F_81 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_26 , V_26 ) ;
free ( V_26 ) ;
}
static void F_82 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_27 , V_26 ) ;
free ( V_26 ) ;
}
static void F_83 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
T_4 V_18 ;
T_3 V_99 ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
V_99 = - 1 ;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
fprintf ( V_116 , L_28 , V_99 ) ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
V_99 = - 1 ;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
fprintf ( V_116 , L_29 , V_99 ) ;
}
static void F_84 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_30 , V_26 ) ;
free ( V_26 ) ;
}
static void F_85 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
T_4 V_18 ;
char * V_26 ;
T_3 V_99 , V_10 ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
return;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
fprintf ( V_116 , L_31 ) ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_32 , V_26 ) ;
free ( V_26 ) ;
}
fputc ( '\n' , V_116 ) ;
}
static void F_86 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
T_4 V_18 ;
T_3 V_99 , V_10 ;
char * V_26 ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
return;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_33 , V_26 ) ;
free ( V_26 ) ;
}
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
return;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_34 , V_26 ) ;
free ( V_26 ) ;
}
}
static void F_87 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
struct V_138 V_106 ;
T_10 V_1 ;
void * V_16 = NULL ;
char * V_26 ;
T_3 V_107 , V_30 , V_99 , V_10 , V_134 , V_139 ;
int V_18 ;
V_18 = F_16 ( V_15 , & V_107 , sizeof( V_107 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_107 ) )
goto error;
if ( V_29 -> V_31 )
V_107 = F_17 ( V_107 ) ;
V_18 = F_16 ( V_15 , & V_30 , sizeof( V_30 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_30 ) )
goto error;
if ( V_29 -> V_31 )
V_30 = F_17 ( V_30 ) ;
if ( V_30 < ( T_3 ) sizeof( V_106 ) )
goto error;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_16 = malloc ( V_30 ) ;
if ( ! V_16 )
goto error;
V_139 = sizeof( V_106 ) ;
if ( V_30 < V_139 )
V_139 = V_30 ;
for ( V_10 = 0 ; V_10 < V_107 ; V_10 ++ ) {
V_18 = F_16 ( V_15 , V_16 , V_30 ) ;
if ( V_18 != ( T_4 ) V_30 )
goto error;
if ( V_29 -> V_31 )
F_88 ( V_16 ) ;
memcpy ( & V_106 , V_16 , V_139 ) ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
goto error;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_35 , V_26 ) ;
free ( V_26 ) ;
fprintf ( V_116 , L_36 V_140
L_37 V_140 L_38 V_140 ,
V_106 . type ,
( T_1 ) V_106 . V_141 ,
( T_1 ) V_106 . V_142 ,
( T_1 ) V_106 . V_143 ) ;
fprintf ( V_116 , L_39 ,
V_106 . V_144 ,
V_106 . V_145 ) ;
if ( V_99 )
fprintf ( V_116 , L_40 ) ;
for ( V_134 = 0 ; V_134 < V_99 ; V_134 ++ ) {
V_18 = F_16 ( V_15 , & V_1 , sizeof( V_1 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_1 ) )
goto error;
if ( V_29 -> V_31 )
V_1 = F_89 ( V_1 ) ;
if ( V_134 )
fputc ( ',' , V_116 ) ;
fprintf ( V_116 , L_41 V_126 , V_1 ) ;
}
if ( V_99 && V_134 == V_99 )
fprintf ( V_116 , L_42 ) ;
fputc ( '\n' , V_116 ) ;
}
free ( V_16 ) ;
return;
error:
fprintf ( V_116 , L_43 ) ;
}
static void F_90 ( struct V_11 * T_8 V_82 , int V_15 , T_9 * V_116 )
{
T_10 V_125 ;
T_4 V_18 ;
V_18 = F_16 ( V_15 , & V_125 , sizeof( V_125 ) ) ;
if ( V_18 != sizeof( V_125 ) )
goto error;
if ( T_8 -> V_31 )
V_125 = F_89 ( V_125 ) ;
fprintf ( V_116 , L_44 V_126 L_45 , V_125 ) ;
return;
error:
fprintf ( V_116 , L_46 ) ;
}
static void F_91 ( struct V_11 * T_8 V_82 , int V_15 , T_9 * V_116 )
{
T_4 V_18 ;
T_3 V_99 , V_133 , V_10 ;
char * V_26 ;
T_10 V_129 , V_130 ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
goto error;
if ( T_8 -> V_31 )
V_99 = F_17 ( V_99 ) ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_18 = F_16 ( V_15 , & V_133 , sizeof( V_133 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_133 ) )
goto error;
if ( T_8 -> V_31 )
V_133 = F_17 ( V_133 ) ;
V_18 = F_16 ( V_15 , & V_129 , sizeof( T_1 ) ) ;
if ( V_18 != sizeof( T_1 ) )
goto error;
V_18 = F_16 ( V_15 , & V_130 , sizeof( T_1 ) ) ;
if ( V_18 != sizeof( T_1 ) )
goto error;
if ( T_8 -> V_31 ) {
V_129 = F_89 ( V_129 ) ;
V_130 = F_89 ( V_130 ) ;
}
fprintf ( V_116 , L_47 V_126 L_48
L_49 V_126 L_45 ,
V_133 ,
V_129 ,
V_130 ) ;
V_26 = F_15 ( V_15 , T_8 ) ;
fprintf ( V_116 , L_50 , V_133 , V_26 ) ;
free ( V_26 ) ;
}
return;
error:
fprintf ( V_116 , L_51 ) ;
}
static void F_92 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_52 , V_26 ) ;
free ( V_26 ) ;
}
static int F_93 ( struct V_146 * V_147 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_148 )
{
struct V_149 * V_150 = V_148 ;
if ( F_94 ( V_15 , V_147 -> V_151 , V_152 ) == ( V_153 ) - 1 ) {
F_30 ( L_53 V_126 L_54
L_55 , V_147 -> V_151 , V_13 ) ;
return 0 ;
}
if ( V_13 >= V_154 ) {
F_2 ( L_56 , V_13 ) ;
return 0 ;
}
if ( ! V_155 [ V_13 ] . V_156 )
return 0 ;
if ( ! V_155 [ V_13 ] . V_157 || V_150 -> V_158 )
V_155 [ V_13 ] . V_156 ( V_29 , V_15 , V_150 -> V_116 ) ;
else
fprintf ( V_150 -> V_116 , L_57 ,
V_155 [ V_13 ] . V_2 ) ;
return 0 ;
}
int F_95 ( struct V_57 * V_58 , T_9 * V_116 , bool V_158 )
{
struct V_149 V_150 ;
struct V_11 * V_12 = & V_58 -> V_12 ;
int V_15 = V_58 -> V_15 ;
V_150 . V_116 = V_116 ;
V_150 . V_158 = V_158 ;
F_96 ( V_12 , V_15 , & V_150 ,
F_93 ) ;
return 0 ;
}
static int F_97 ( int V_15 , struct V_11 * T_8 , int type ,
struct V_146 * * V_94 ,
struct V_83 * V_84 )
{
int V_25 ;
int V_18 = 0 ;
if ( F_8 ( T_8 , type ) ) {
if ( ! V_155 [ type ] . F_11 )
return - 1 ;
( * V_94 ) -> V_151 = F_94 ( V_15 , 0 , V_159 ) ;
V_25 = V_155 [ type ] . F_11 ( V_15 , T_8 , V_84 ) ;
if ( V_25 < 0 ) {
F_30 ( L_58 , type ) ;
F_94 ( V_15 , ( * V_94 ) -> V_151 , V_152 ) ;
return - 1 ;
}
( * V_94 ) -> V_17 = F_94 ( V_15 , 0 , V_159 ) - ( * V_94 ) -> V_151 ;
( * V_94 ) ++ ;
}
return V_18 ;
}
static int F_98 ( struct V_11 * V_12 ,
struct V_83 * V_84 , int V_15 )
{
int V_160 ;
struct V_146 * V_161 , * V_94 ;
int V_162 ;
T_1 V_163 ;
int V_13 ;
int V_25 ;
V_160 = F_99 ( V_12 -> V_14 , V_164 ) ;
if ( ! V_160 )
return 0 ;
V_161 = V_94 = calloc ( sizeof( * V_161 ) , V_160 ) ;
if ( V_161 == NULL )
return - V_6 ;
V_162 = sizeof( * V_161 ) * V_160 ;
V_163 = V_12 -> V_165 + V_12 -> V_166 ;
F_94 ( V_15 , V_163 + V_162 , V_152 ) ;
F_100 (feat, header->adds_features, HEADER_FEAT_BITS) {
if ( F_97 ( V_15 , V_12 , V_13 , & V_94 , V_84 ) )
F_6 ( V_12 , V_13 ) ;
}
F_94 ( V_15 , V_163 , V_152 ) ;
V_25 = F_10 ( V_15 , V_161 , V_162 ) ;
if ( V_25 < 0 )
F_30 ( L_59 ) ;
free ( V_161 ) ;
return V_25 ;
}
int F_101 ( int V_15 )
{
struct V_167 V_168 ;
int V_25 ;
V_168 = (struct V_167 ) {
. V_169 = V_170 ,
. V_17 = sizeof( V_168 ) ,
} ;
V_25 = F_10 ( V_15 , & V_168 , sizeof( V_168 ) ) ;
if ( V_25 < 0 ) {
F_30 ( L_60 ) ;
return V_25 ;
}
return 0 ;
}
int F_102 ( struct V_57 * V_58 ,
struct V_83 * V_84 ,
int V_15 , bool V_171 )
{
struct V_172 V_168 ;
struct V_173 V_174 ;
struct V_11 * V_12 = & V_58 -> V_12 ;
struct V_105 * V_106 , * V_175 = NULL ;
int V_25 ;
F_94 ( V_15 , sizeof( V_168 ) , V_152 ) ;
if ( V_58 -> V_84 != V_84 )
V_175 = F_103 ( V_58 -> V_84 -> V_85 . V_176 , struct V_105 , V_127 ) ;
F_65 (attr, &evlist->entries, node) {
V_106 -> V_177 = F_94 ( V_15 , 0 , V_159 ) ;
V_25 = F_10 ( V_15 , V_106 -> V_1 , V_106 -> V_109 * sizeof( T_1 ) ) ;
if ( V_25 < 0 ) {
V_178:
F_30 ( L_61 ) ;
return V_25 ;
}
if ( V_58 -> V_84 != V_84 ) {
V_25 = F_10 ( V_15 , V_175 -> V_1 , V_175 -> V_109 * sizeof( T_1 ) ) ;
if ( V_25 < 0 )
goto V_178;
V_106 -> V_109 += V_175 -> V_109 ;
V_175 = F_103 ( V_175 -> V_127 . V_176 , struct V_105 , V_127 ) ;
}
}
V_12 -> V_179 = F_94 ( V_15 , 0 , V_159 ) ;
F_65 (attr, &evlist->entries, node) {
V_174 = (struct V_173 ) {
. V_106 = V_106 -> V_106 ,
. V_109 = {
. V_151 = V_106 -> V_177 ,
. V_17 = V_106 -> V_109 * sizeof( T_1 ) ,
}
} ;
V_25 = F_10 ( V_15 , & V_174 , sizeof( V_174 ) ) ;
if ( V_25 < 0 ) {
F_30 ( L_62 ) ;
return V_25 ;
}
}
V_12 -> V_180 = F_94 ( V_15 , 0 , V_159 ) ;
V_12 -> V_181 = V_8 * sizeof( struct V_5 ) ;
if ( V_4 ) {
V_25 = F_10 ( V_15 , V_4 , V_12 -> V_181 ) ;
if ( V_25 < 0 ) {
F_30 ( L_63 ) ;
return V_25 ;
}
}
V_12 -> V_165 = F_94 ( V_15 , 0 , V_159 ) ;
if ( V_171 ) {
V_25 = F_98 ( V_12 , V_84 , V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_168 = (struct V_172 ) {
. V_169 = V_170 ,
. V_17 = sizeof( V_168 ) ,
. V_182 = sizeof( V_174 ) ,
. V_183 = {
. V_151 = V_12 -> V_179 ,
. V_17 = V_84 -> V_184 * sizeof( V_174 ) ,
} ,
. V_148 = {
. V_151 = V_12 -> V_165 ,
. V_17 = V_12 -> V_166 ,
} ,
. V_185 = {
. V_151 = V_12 -> V_180 ,
. V_17 = V_12 -> V_181 ,
} ,
} ;
memcpy ( & V_168 . V_14 , & V_12 -> V_14 , sizeof( V_12 -> V_14 ) ) ;
F_94 ( V_15 , 0 , V_152 ) ;
V_25 = F_10 ( V_15 , & V_168 , sizeof( V_168 ) ) ;
if ( V_25 < 0 ) {
F_30 ( L_61 ) ;
return V_25 ;
}
F_94 ( V_15 , V_12 -> V_165 + V_12 -> V_166 , V_152 ) ;
V_12 -> V_186 = 1 ;
return 0 ;
}
static int F_104 ( struct V_11 * V_12 ,
int V_15 , void * V_16 , T_2 V_17 )
{
if ( F_105 ( V_15 , V_16 , V_17 ) <= 0 )
return - 1 ;
if ( V_12 -> V_31 )
F_106 ( V_16 , V_17 ) ;
return 0 ;
}
int F_96 ( struct V_11 * V_12 , int V_15 ,
void * V_148 ,
int (* F_107)( struct V_146 * V_147 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_148 ) )
{
struct V_146 * V_161 , * V_187 ;
int V_160 ;
int V_162 ;
int V_13 ;
int V_25 ;
V_160 = F_99 ( V_12 -> V_14 , V_164 ) ;
if ( ! V_160 )
return 0 ;
V_161 = V_187 = calloc ( sizeof( * V_161 ) , V_160 ) ;
if ( ! V_161 )
return - 1 ;
V_162 = sizeof( * V_161 ) * V_160 ;
F_94 ( V_15 , V_12 -> V_165 + V_12 -> V_166 , V_152 ) ;
V_25 = F_104 ( V_12 , V_15 , V_161 , V_162 ) ;
if ( V_25 < 0 )
goto V_73;
F_100 (feat, header->adds_features, HEADER_LAST_FEATURE) {
V_25 = F_107 ( V_187 ++ , V_12 , V_13 , V_15 , V_148 ) ;
if ( V_25 < 0 )
goto V_73;
}
V_25 = 0 ;
V_73:
free ( V_161 ) ;
return V_25 ;
}
int F_108 ( struct V_172 * V_12 ,
struct V_11 * V_29 , int V_15 )
{
F_94 ( V_15 , 0 , V_152 ) ;
if ( F_105 ( V_15 , V_12 , sizeof( * V_12 ) ) <= 0 ||
memcmp ( & V_12 -> V_169 , V_188 , sizeof( V_12 -> V_169 ) ) )
return - 1 ;
if ( V_12 -> V_182 != sizeof( struct V_173 ) ) {
T_1 V_182 = F_89 ( V_12 -> V_182 ) ;
if ( V_182 != sizeof( struct V_173 ) )
return - 1 ;
F_106 ( V_12 , F_109 ( struct V_172 ,
V_14 ) ) ;
V_29 -> V_31 = true ;
}
if ( V_12 -> V_17 != sizeof( * V_12 ) ) {
if ( V_12 -> V_17 == F_109 ( F_110 ( * V_12 ) , V_14 ) )
F_111 ( V_12 -> V_14 , V_164 ) ;
else
return - 1 ;
} else if ( V_29 -> V_31 ) {
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < F_112 ( V_164 ) ; ++ V_10 )
V_12 -> V_14 [ V_10 ] = F_89 ( V_12 -> V_14 [ V_10 ] ) ;
if ( ! F_9 ( V_189 , V_12 -> V_14 ) ) {
for ( V_10 = 0 ; V_10 < F_112 ( V_164 ) ; ++ V_10 ) {
V_12 -> V_14 [ V_10 ] = F_89 ( V_12 -> V_14 [ V_10 ] ) ;
V_12 -> V_14 [ V_10 ] = F_17 ( V_12 -> V_14 [ V_10 ] ) ;
}
}
if ( ! F_9 ( V_189 , V_12 -> V_14 ) ) {
F_111 ( V_12 -> V_14 , V_164 ) ;
F_5 ( V_190 , V_12 -> V_14 ) ;
}
}
memcpy ( & V_29 -> V_14 , & V_12 -> V_14 ,
sizeof( V_29 -> V_14 ) ) ;
V_29 -> V_180 = V_12 -> V_185 . V_151 ;
V_29 -> V_181 = V_12 -> V_185 . V_17 ;
V_29 -> V_165 = V_12 -> V_148 . V_151 ;
V_29 -> V_166 = V_12 -> V_148 . V_17 ;
return 0 ;
}
static int F_113 ( struct V_42 * V_191 ,
char * V_68 ,
struct V_57 * V_58 )
{
int V_25 = - 1 ;
struct V_36 * V_37 ;
struct V_48 * V_48 ;
T_6 V_39 ;
struct V_40 * V_40 ;
enum V_192 V_193 ;
V_48 = F_114 ( V_58 , V_191 -> V_38 ) ;
if ( ! V_48 )
goto V_194;
V_39 = V_191 -> V_12 . V_39 & V_195 ;
switch ( V_39 ) {
case V_50 :
V_193 = V_196 ;
V_37 = & V_48 -> V_55 ;
break;
case V_53 :
V_193 = V_197 ;
V_37 = & V_48 -> V_55 ;
break;
case V_52 :
case V_54 :
V_193 = V_198 ;
V_37 = & V_48 -> V_56 ;
break;
default:
goto V_194;
}
V_40 = F_115 ( V_37 , V_68 ) ;
if ( V_40 != NULL ) {
char V_63 [ V_77 * 2 + 1 ] ;
F_116 ( V_40 , & V_191 -> V_46 ) ;
if ( V_68 [ 0 ] == '[' )
V_40 -> V_78 = V_193 ;
F_39 ( V_40 -> V_46 , sizeof( V_40 -> V_46 ) ,
V_63 ) ;
F_30 ( L_64 ,
V_40 -> V_47 , V_63 ) ;
}
V_25 = 0 ;
V_194:
return V_25 ;
}
static int F_117 ( struct V_11 * V_12 ,
int V_199 , T_1 V_151 , T_1 V_17 )
{
struct V_57 * V_58 = F_24 ( V_12 , struct V_57 , V_12 ) ;
struct {
struct V_200 V_12 ;
T_7 V_46 [ F_14 ( V_77 , sizeof( T_1 ) ) ] ;
char V_68 [ 0 ] ;
} V_201 ;
struct V_42 V_191 ;
char V_68 [ V_66 ] ;
T_1 V_202 = V_151 + V_17 ;
while ( V_151 < V_202 ) {
T_4 V_27 ;
if ( F_16 ( V_199 , & V_201 , sizeof( V_201 ) ) != sizeof( V_201 ) )
return - 1 ;
if ( V_12 -> V_31 )
F_118 ( & V_201 . V_12 ) ;
V_27 = V_201 . V_12 . V_17 - sizeof( V_201 ) ;
if ( F_16 ( V_199 , V_68 , V_27 ) != V_27 )
return - 1 ;
V_191 . V_12 = V_201 . V_12 ;
V_191 . V_38 = V_203 ;
if ( V_191 . V_12 . V_39 == V_54 ||
V_191 . V_12 . V_39 == V_53 )
V_191 . V_38 = V_204 ;
memcpy ( V_191 . V_46 , V_201 . V_46 , sizeof( V_191 . V_46 ) ) ;
F_113 ( & V_191 , V_68 , V_58 ) ;
V_151 += V_191 . V_12 . V_17 ;
}
return 0 ;
}
static int F_119 ( struct V_11 * V_12 ,
int V_199 , T_1 V_151 , T_1 V_17 )
{
struct V_57 * V_58 = F_24 ( V_12 , struct V_57 , V_12 ) ;
struct V_42 V_191 ;
char V_68 [ V_66 ] ;
T_1 V_202 = V_151 + V_17 , V_205 = V_151 ;
int V_25 = - 1 ;
while ( V_151 < V_202 ) {
T_4 V_27 ;
if ( F_16 ( V_199 , & V_191 , sizeof( V_191 ) ) != sizeof( V_191 ) )
goto V_194;
if ( V_12 -> V_31 )
F_118 ( & V_191 . V_12 ) ;
V_27 = V_191 . V_12 . V_17 - sizeof( V_191 ) ;
if ( F_16 ( V_199 , V_68 , V_27 ) != V_27 )
goto V_194;
if ( memcmp ( V_68 , L_65 , 13 ) == 0 ) {
if ( F_94 ( V_199 , V_205 , V_152 ) == ( V_153 ) - 1 )
return - 1 ;
return F_117 ( V_12 , V_199 , V_151 , V_17 ) ;
}
F_113 ( & V_191 , V_68 , V_58 ) ;
V_151 += V_191 . V_12 . V_17 ;
}
V_25 = 0 ;
V_194:
return V_25 ;
}
static int F_120 ( struct V_146 * V_147 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_148 V_82 )
{
if ( F_94 ( V_15 , V_147 -> V_151 , V_152 ) == ( V_153 ) - 1 ) {
F_30 ( L_53 V_126 L_54
L_55 , V_147 -> V_151 , V_13 ) ;
return 0 ;
}
if ( V_13 >= V_154 ) {
F_30 ( L_66 , V_13 ) ;
return 0 ;
}
switch ( V_13 ) {
case V_206 :
F_121 ( V_15 , false ) ;
break;
case V_190 :
if ( F_119 ( V_29 , V_15 , V_147 -> V_151 , V_147 -> V_17 ) )
F_30 ( L_67 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_122 ( struct V_167 * V_12 ,
struct V_11 * V_29 , int V_15 ,
bool V_207 )
{
if ( F_105 ( V_15 , V_12 , sizeof( * V_12 ) ) <= 0 ||
memcmp ( & V_12 -> V_169 , V_188 , sizeof( V_12 -> V_169 ) ) )
return - 1 ;
if ( V_207 && F_10 ( V_208 , V_12 , sizeof( * V_12 ) ) < 0 )
return - 1 ;
if ( V_12 -> V_17 != sizeof( * V_12 ) ) {
T_1 V_17 = F_89 ( V_12 -> V_17 ) ;
if ( V_17 != sizeof( * V_12 ) )
return - 1 ;
V_29 -> V_31 = true ;
}
return 0 ;
}
static int F_123 ( struct V_57 * V_58 , int V_15 )
{
struct V_11 * V_12 = & V_58 -> V_12 ;
struct V_167 V_168 ;
if ( F_122 ( & V_168 , V_12 , V_15 ,
V_58 -> V_207 ) < 0 ) {
F_30 ( L_68 ) ;
return - V_209 ;
}
V_58 -> V_15 = V_15 ;
return 0 ;
}
int F_124 ( struct V_57 * V_58 , int V_15 )
{
struct V_11 * V_12 = & V_58 -> V_12 ;
struct V_172 V_168 ;
struct V_173 V_174 ;
T_1 V_210 ;
int V_211 , V_212 , V_10 , V_134 ;
V_58 -> V_84 = F_125 ( NULL , NULL ) ;
if ( V_58 -> V_84 == NULL )
return - V_6 ;
if ( V_58 -> V_213 )
return F_123 ( V_58 , V_15 ) ;
if ( F_108 ( & V_168 , V_12 , V_15 ) < 0 ) {
F_30 ( L_68 ) ;
return - V_209 ;
}
V_211 = V_168 . V_183 . V_17 / sizeof( V_174 ) ;
F_94 ( V_15 , V_168 . V_183 . V_151 , V_152 ) ;
for ( V_10 = 0 ; V_10 < V_211 ; V_10 ++ ) {
struct V_105 * V_214 ;
V_153 V_215 ;
if ( F_105 ( V_15 , & V_174 , sizeof( V_174 ) ) <= 0 )
goto V_216;
if ( V_12 -> V_31 )
F_88 ( & V_174 . V_106 ) ;
V_215 = F_94 ( V_15 , 0 , V_159 ) ;
V_214 = F_126 ( & V_174 . V_106 , V_10 ) ;
if ( V_214 == NULL )
goto V_217;
F_127 ( V_58 -> V_84 , V_214 ) ;
V_212 = V_174 . V_109 . V_17 / sizeof( T_1 ) ;
if ( F_128 ( V_214 , 1 , V_212 ) )
goto V_217;
F_94 ( V_15 , V_174 . V_109 . V_151 , V_152 ) ;
for ( V_134 = 0 ; V_134 < V_212 ; V_134 ++ ) {
if ( F_104 ( V_12 , V_15 , & V_210 , sizeof( V_210 ) ) )
goto V_216;
F_129 ( V_58 -> V_84 , V_214 , 0 , V_134 , V_210 ) ;
}
F_94 ( V_15 , V_215 , V_152 ) ;
}
V_71 . V_218 = V_211 ;
if ( V_168 . V_185 . V_17 ) {
F_94 ( V_15 , V_168 . V_185 . V_151 , V_152 ) ;
V_4 = malloc ( V_168 . V_185 . V_17 ) ;
if ( V_4 == NULL )
return - V_6 ;
if ( F_104 ( V_12 , V_15 , V_4 ,
V_168 . V_185 . V_17 ) )
goto V_216;
V_8 = V_168 . V_185 . V_17 / sizeof( struct V_5 ) ;
}
F_96 ( V_12 , V_15 , NULL ,
F_120 ) ;
F_94 ( V_15 , V_12 -> V_165 , V_152 ) ;
V_12 -> V_186 = 1 ;
return 0 ;
V_216:
return - V_19 ;
V_217:
F_130 ( V_58 -> V_84 ) ;
V_58 -> V_84 = NULL ;
return - V_6 ;
}
int F_131 ( struct V_219 * V_220 ,
struct V_138 * V_106 , T_6 V_109 , T_1 * V_1 ,
T_11 F_107 )
{
union V_221 * V_222 ;
T_2 V_17 ;
int V_25 ;
V_17 = sizeof( struct V_138 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_17 += sizeof( struct V_200 ) ;
V_17 += V_109 * sizeof( T_1 ) ;
V_222 = malloc ( V_17 ) ;
if ( V_222 == NULL )
return - V_6 ;
V_222 -> V_106 . V_106 = * V_106 ;
memcpy ( V_222 -> V_106 . V_1 , V_1 , V_109 * sizeof( T_1 ) ) ;
V_222 -> V_106 . V_12 . type = V_223 ;
V_222 -> V_106 . V_12 . V_17 = V_17 ;
V_25 = F_107 ( V_220 , V_222 , NULL , NULL ) ;
free ( V_222 ) ;
return V_25 ;
}
int F_132 ( struct V_219 * V_220 ,
struct V_57 * V_58 ,
T_11 F_107 )
{
struct V_105 * V_106 ;
int V_25 = 0 ;
F_65 (attr, &session->evlist->entries, node) {
V_25 = F_131 ( V_220 , & V_106 -> V_106 , V_106 -> V_109 ,
V_106 -> V_1 , F_107 ) ;
if ( V_25 ) {
F_30 ( L_69 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_133 ( union V_221 * V_224 ,
struct V_83 * * V_225 )
{
unsigned int V_10 , V_109 , V_226 ;
struct V_105 * V_214 ;
struct V_83 * V_84 = * V_225 ;
if ( V_84 == NULL ) {
* V_225 = V_84 = F_125 ( NULL , NULL ) ;
if ( V_84 == NULL )
return - V_6 ;
}
V_214 = F_126 ( & V_224 -> V_106 . V_106 , V_84 -> V_184 ) ;
if ( V_214 == NULL )
return - V_6 ;
F_127 ( V_84 , V_214 ) ;
V_109 = V_224 -> V_12 . V_17 ;
V_109 -= ( void * ) & V_224 -> V_106 . V_1 - ( void * ) V_224 ;
V_226 = V_109 / sizeof( T_1 ) ;
if ( F_128 ( V_214 , 1 , V_226 ) )
return - V_6 ;
for ( V_10 = 0 ; V_10 < V_226 ; V_10 ++ ) {
F_129 ( V_84 , V_214 , 0 , V_10 , V_224 -> V_106 . V_1 [ V_10 ] ) ;
}
return 0 ;
}
int F_134 ( struct V_219 * V_220 ,
T_1 V_9 , char * V_2 ,
T_11 F_107 ,
struct V_48 * V_48 )
{
union V_221 V_222 ;
T_2 V_17 = 0 ;
int V_25 = 0 ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
V_222 . V_227 . V_227 . V_9 = V_9 ;
memset ( V_222 . V_227 . V_227 . V_2 , 0 , V_3 ) ;
strncpy ( V_222 . V_227 . V_227 . V_2 , V_2 , V_3 - 1 ) ;
V_222 . V_227 . V_12 . type = V_228 ;
V_17 = strlen ( V_222 . V_227 . V_227 . V_2 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_222 . V_227 . V_12 . V_17 = sizeof( V_222 . V_227 ) -
( sizeof( V_222 . V_227 . V_227 . V_2 ) - V_17 ) ;
V_25 = F_107 ( V_220 , & V_222 , NULL , V_48 ) ;
return V_25 ;
}
int F_135 ( struct V_219 * V_220 ,
T_11 F_107 ,
struct V_48 * V_48 )
{
struct V_5 * type ;
int V_10 , V_25 = 0 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ ) {
type = & V_4 [ V_10 ] ;
V_25 = F_134 ( V_220 , type -> V_9 ,
type -> V_2 , F_107 ,
V_48 ) ;
if ( V_25 ) {
F_30 ( L_70 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_136 ( struct V_219 * V_220 V_229 ,
union V_221 * V_224 )
{
if ( F_1 ( V_224 -> V_227 . V_227 . V_9 ,
V_224 -> V_227 . V_227 . V_2 ) < 0 )
return - V_6 ;
return 0 ;
}
int F_137 ( struct V_219 * V_220 , int V_15 ,
struct V_83 * V_84 ,
T_11 F_107 )
{
union V_221 V_222 ;
struct V_230 * V_231 ;
T_4 V_17 = 0 , V_232 = 0 , V_233 ;
int V_25 V_82 = 0 ;
V_231 = F_138 ( & V_84 -> V_85 , V_15 , true ) ;
if ( ! V_231 )
return - 1 ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
V_222 . V_230 . V_12 . type = V_234 ;
V_17 = V_231 -> V_17 ;
V_232 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_233 = V_232 - V_17 ;
V_222 . V_230 . V_12 . V_17 = sizeof( V_222 . V_230 ) ;
V_222 . V_230 . V_17 = V_232 ;
F_107 ( V_220 , & V_222 , NULL , NULL ) ;
F_139 ( V_231 ) ;
F_12 ( V_15 , NULL , 0 , V_233 ) ;
return V_232 ;
}
int F_140 ( union V_221 * V_224 ,
struct V_57 * V_58 )
{
T_4 V_235 , V_233 , V_17 = V_224 -> V_230 . V_17 ;
V_153 V_151 = F_94 ( V_58 -> V_15 , 0 , V_159 ) ;
char V_16 [ V_236 ] ;
F_94 ( V_58 -> V_15 , V_151 + sizeof( struct V_237 ) ,
V_152 ) ;
V_235 = F_121 ( V_58 -> V_15 , V_58 -> V_207 ) ;
V_233 = F_14 ( V_235 , sizeof( T_1 ) ) - V_235 ;
if ( F_16 ( V_58 -> V_15 , V_16 , V_233 ) < 0 )
F_141 ( L_71 ) ;
if ( V_58 -> V_207 ) {
int V_238 = F_11 ( V_208 , V_16 , V_233 ) ;
if ( V_238 <= 0 || V_238 != V_233 )
F_141 ( L_72 ) ;
}
if ( V_235 + V_233 != V_17 )
F_141 ( L_73 ) ;
return V_235 + V_233 ;
}
int F_142 ( struct V_219 * V_220 ,
struct V_40 * V_41 , T_6 V_39 ,
T_11 F_107 ,
struct V_48 * V_48 )
{
union V_221 V_222 ;
T_2 V_27 ;
int V_25 = 0 ;
if ( ! V_41 -> V_44 )
return V_25 ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
V_27 = V_41 -> V_45 + 1 ;
V_27 = F_14 ( V_27 , V_24 ) ;
memcpy ( & V_222 . V_46 . V_46 , V_41 -> V_46 , sizeof( V_41 -> V_46 ) ) ;
V_222 . V_46 . V_12 . type = V_239 ;
V_222 . V_46 . V_12 . V_39 = V_39 ;
V_222 . V_46 . V_38 = V_48 -> V_38 ;
V_222 . V_46 . V_12 . V_17 = sizeof( V_222 . V_46 ) + V_27 ;
memcpy ( & V_222 . V_46 . V_68 , V_41 -> V_47 , V_41 -> V_45 ) ;
V_25 = F_107 ( V_220 , & V_222 , NULL , V_48 ) ;
return V_25 ;
}
int F_143 ( struct V_219 * V_220 V_82 ,
union V_221 * V_224 ,
struct V_57 * V_58 )
{
F_113 ( & V_224 -> V_46 ,
V_224 -> V_46 . V_68 ,
V_58 ) ;
return 0 ;
}
void F_144 ( void )
{
V_86 = true ;
}
