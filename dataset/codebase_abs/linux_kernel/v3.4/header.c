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
snprintf ( V_68 + V_27 , V_17 - V_27 , L_6 , V_63 ) ;
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
static int F_79 ( int V_15 V_82 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
return 0 ;
}
static void F_80 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_24 , V_26 ) ;
free ( V_26 ) ;
}
static void F_81 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_25 , V_26 ) ;
free ( V_26 ) ;
}
static void F_82 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_26 , V_26 ) ;
free ( V_26 ) ;
}
static void F_83 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_27 , V_26 ) ;
free ( V_26 ) ;
}
static void F_84 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
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
static void F_85 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_30 , V_26 ) ;
free ( V_26 ) ;
}
static void F_86 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
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
static void F_87 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
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
static void F_88 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
struct V_138 V_106 ;
T_10 V_1 ;
void * V_16 = NULL ;
char * V_26 ;
T_3 V_107 , V_30 , V_99 , V_10 , V_134 ;
T_4 V_18 ;
T_2 V_139 ;
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
F_89 ( V_16 ) ;
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
V_1 = F_90 ( V_1 ) ;
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
static void F_91 ( struct V_11 * T_8 V_82 , int V_15 , T_9 * V_116 )
{
T_10 V_125 ;
T_4 V_18 ;
V_18 = F_16 ( V_15 , & V_125 , sizeof( V_125 ) ) ;
if ( V_18 != sizeof( V_125 ) )
goto error;
if ( T_8 -> V_31 )
V_125 = F_90 ( V_125 ) ;
fprintf ( V_116 , L_44 V_126 L_45 , V_125 ) ;
return;
error:
fprintf ( V_116 , L_46 ) ;
}
static void F_92 ( struct V_11 * T_8 V_82 , int V_15 , T_9 * V_116 )
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
V_129 = F_90 ( V_129 ) ;
V_130 = F_90 ( V_130 ) ;
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
static void F_93 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_52 , V_26 ) ;
free ( V_26 ) ;
}
static void F_94 ( struct V_11 * V_29 V_82 , int V_15 V_82 ,
T_9 * V_116 )
{
fprintf ( V_116 , L_53 ) ;
}
static int F_95 ( struct V_42 * V_146 ,
char * V_68 ,
struct V_57 * V_58 )
{
int V_25 = - 1 ;
struct V_36 * V_37 ;
struct V_48 * V_48 ;
T_6 V_39 ;
struct V_40 * V_40 ;
enum V_147 V_148 ;
V_48 = F_96 ( V_58 , V_146 -> V_38 ) ;
if ( ! V_48 )
goto V_149;
V_39 = V_146 -> V_12 . V_39 & V_150 ;
switch ( V_39 ) {
case V_50 :
V_148 = V_151 ;
V_37 = & V_48 -> V_55 ;
break;
case V_53 :
V_148 = V_152 ;
V_37 = & V_48 -> V_55 ;
break;
case V_52 :
case V_54 :
V_148 = V_153 ;
V_37 = & V_48 -> V_56 ;
break;
default:
goto V_149;
}
V_40 = F_97 ( V_37 , V_68 ) ;
if ( V_40 != NULL ) {
char V_63 [ V_77 * 2 + 1 ] ;
F_98 ( V_40 , & V_146 -> V_46 ) ;
if ( V_68 [ 0 ] == '[' )
V_40 -> V_78 = V_148 ;
F_39 ( V_40 -> V_46 , sizeof( V_40 -> V_46 ) ,
V_63 ) ;
F_30 ( L_54 ,
V_40 -> V_47 , V_63 ) ;
}
V_25 = 0 ;
V_149:
return V_25 ;
}
static int F_99 ( struct V_11 * V_12 ,
int V_154 , T_1 V_155 , T_1 V_17 )
{
struct V_57 * V_58 = F_24 ( V_12 , struct V_57 , V_12 ) ;
struct {
struct V_156 V_12 ;
T_7 V_46 [ F_14 ( V_77 , sizeof( T_1 ) ) ] ;
char V_68 [ 0 ] ;
} V_157 ;
struct V_42 V_146 ;
char V_68 [ V_66 ] ;
T_1 V_158 = V_155 + V_17 ;
while ( V_155 < V_158 ) {
T_4 V_27 ;
if ( F_16 ( V_154 , & V_157 , sizeof( V_157 ) ) != sizeof( V_157 ) )
return - 1 ;
if ( V_12 -> V_31 )
F_100 ( & V_157 . V_12 ) ;
V_27 = V_157 . V_12 . V_17 - sizeof( V_157 ) ;
if ( F_16 ( V_154 , V_68 , V_27 ) != V_27 )
return - 1 ;
V_146 . V_12 = V_157 . V_12 ;
V_146 . V_38 = V_159 ;
if ( V_146 . V_12 . V_39 == V_54 ||
V_146 . V_12 . V_39 == V_53 )
V_146 . V_38 = V_160 ;
memcpy ( V_146 . V_46 , V_157 . V_46 , sizeof( V_146 . V_46 ) ) ;
F_95 ( & V_146 , V_68 , V_58 ) ;
V_155 += V_146 . V_12 . V_17 ;
}
return 0 ;
}
static int F_101 ( struct V_11 * V_12 ,
int V_154 , T_1 V_155 , T_1 V_17 )
{
struct V_57 * V_58 = F_24 ( V_12 , struct V_57 , V_12 ) ;
struct V_42 V_146 ;
char V_68 [ V_66 ] ;
T_1 V_158 = V_155 + V_17 , V_161 = V_155 ;
int V_25 = - 1 ;
while ( V_155 < V_158 ) {
T_4 V_27 ;
if ( F_16 ( V_154 , & V_146 , sizeof( V_146 ) ) != sizeof( V_146 ) )
goto V_149;
if ( V_12 -> V_31 )
F_100 ( & V_146 . V_12 ) ;
V_27 = V_146 . V_12 . V_17 - sizeof( V_146 ) ;
if ( F_16 ( V_154 , V_68 , V_27 ) != V_27 )
goto V_149;
if ( memcmp ( V_68 , L_55 , 13 ) == 0 ) {
if ( F_102 ( V_154 , V_161 , V_162 ) == ( V_163 ) - 1 )
return - 1 ;
return F_99 ( V_12 , V_154 , V_155 , V_17 ) ;
}
F_95 ( & V_146 , V_68 , V_58 ) ;
V_155 += V_146 . V_12 . V_17 ;
}
V_25 = 0 ;
V_149:
return V_25 ;
}
static int F_103 ( struct V_164 * T_11 V_165 ,
struct V_11 * V_29 V_165 ,
int V_13 V_165 , int V_15 )
{
F_104 ( V_15 , false ) ;
return 0 ;
}
static int F_105 ( struct V_164 * T_11 ,
struct V_11 * V_29 ,
int V_13 V_165 , int V_15 )
{
if ( F_101 ( V_29 , V_15 , T_11 -> V_155 , T_11 -> V_17 ) )
F_30 ( L_56 ) ;
return 0 ;
}
static int F_106 ( struct V_164 * T_11 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_166 )
{
struct V_167 * V_168 = V_166 ;
if ( F_102 ( V_15 , T_11 -> V_155 , V_162 ) == ( V_163 ) - 1 ) {
F_30 ( L_57 V_126 L_58
L_59 , T_11 -> V_155 , V_13 ) ;
return 0 ;
}
if ( V_13 >= V_169 ) {
F_2 ( L_60 , V_13 ) ;
return 0 ;
}
if ( ! V_170 [ V_13 ] . V_171 )
return 0 ;
if ( ! V_170 [ V_13 ] . V_172 || V_168 -> V_173 )
V_170 [ V_13 ] . V_171 ( V_29 , V_15 , V_168 -> V_116 ) ;
else
fprintf ( V_168 -> V_116 , L_61 ,
V_170 [ V_13 ] . V_2 ) ;
return 0 ;
}
int F_107 ( struct V_57 * V_58 , T_9 * V_116 , bool V_173 )
{
struct V_167 V_168 ;
struct V_11 * V_12 = & V_58 -> V_12 ;
int V_15 = V_58 -> V_15 ;
V_168 . V_116 = V_116 ;
V_168 . V_173 = V_173 ;
F_108 ( V_12 , V_15 , & V_168 ,
F_106 ) ;
return 0 ;
}
static int F_109 ( int V_15 , struct V_11 * T_8 , int type ,
struct V_164 * * V_94 ,
struct V_83 * V_84 )
{
int V_25 ;
int V_18 = 0 ;
if ( F_8 ( T_8 , type ) ) {
if ( ! V_170 [ type ] . F_11 )
return - 1 ;
( * V_94 ) -> V_155 = F_102 ( V_15 , 0 , V_174 ) ;
V_25 = V_170 [ type ] . F_11 ( V_15 , T_8 , V_84 ) ;
if ( V_25 < 0 ) {
F_30 ( L_62 , type ) ;
F_102 ( V_15 , ( * V_94 ) -> V_155 , V_162 ) ;
return - 1 ;
}
( * V_94 ) -> V_17 = F_102 ( V_15 , 0 , V_174 ) - ( * V_94 ) -> V_155 ;
( * V_94 ) ++ ;
}
return V_18 ;
}
static int F_110 ( struct V_11 * V_12 ,
struct V_83 * V_84 , int V_15 )
{
int V_175 ;
struct V_164 * V_176 , * V_94 ;
int V_177 ;
T_1 V_178 ;
int V_13 ;
int V_25 ;
V_175 = F_111 ( V_12 -> V_14 , V_179 ) ;
if ( ! V_175 )
return 0 ;
V_176 = V_94 = calloc ( sizeof( * V_176 ) , V_175 ) ;
if ( V_176 == NULL )
return - V_6 ;
V_177 = sizeof( * V_176 ) * V_175 ;
V_178 = V_12 -> V_180 + V_12 -> V_181 ;
F_102 ( V_15 , V_178 + V_177 , V_162 ) ;
F_112 (feat, header->adds_features, HEADER_FEAT_BITS) {
if ( F_109 ( V_15 , V_12 , V_13 , & V_94 , V_84 ) )
F_6 ( V_12 , V_13 ) ;
}
F_102 ( V_15 , V_178 , V_162 ) ;
V_25 = F_10 ( V_15 , V_176 , V_177 ) ;
if ( V_25 < 0 )
F_30 ( L_63 ) ;
free ( V_176 ) ;
return V_25 ;
}
int F_113 ( int V_15 )
{
struct V_182 V_183 ;
int V_25 ;
V_183 = (struct V_182 ) {
. V_184 = V_185 ,
. V_17 = sizeof( V_183 ) ,
} ;
V_25 = F_10 ( V_15 , & V_183 , sizeof( V_183 ) ) ;
if ( V_25 < 0 ) {
F_30 ( L_64 ) ;
return V_25 ;
}
return 0 ;
}
int F_114 ( struct V_57 * V_58 ,
struct V_83 * V_84 ,
int V_15 , bool V_186 )
{
struct V_187 V_183 ;
struct V_188 V_189 ;
struct V_11 * V_12 = & V_58 -> V_12 ;
struct V_105 * V_106 , * V_190 = NULL ;
int V_25 ;
F_102 ( V_15 , sizeof( V_183 ) , V_162 ) ;
if ( V_58 -> V_84 != V_84 )
V_190 = F_115 ( V_58 -> V_84 -> V_85 . V_191 , struct V_105 , V_127 ) ;
F_65 (attr, &evlist->entries, node) {
V_106 -> V_192 = F_102 ( V_15 , 0 , V_174 ) ;
V_25 = F_10 ( V_15 , V_106 -> V_1 , V_106 -> V_109 * sizeof( T_1 ) ) ;
if ( V_25 < 0 ) {
V_193:
F_30 ( L_65 ) ;
return V_25 ;
}
if ( V_58 -> V_84 != V_84 ) {
V_25 = F_10 ( V_15 , V_190 -> V_1 , V_190 -> V_109 * sizeof( T_1 ) ) ;
if ( V_25 < 0 )
goto V_193;
V_106 -> V_109 += V_190 -> V_109 ;
V_190 = F_115 ( V_190 -> V_127 . V_191 , struct V_105 , V_127 ) ;
}
}
V_12 -> V_194 = F_102 ( V_15 , 0 , V_174 ) ;
F_65 (attr, &evlist->entries, node) {
V_189 = (struct V_188 ) {
. V_106 = V_106 -> V_106 ,
. V_109 = {
. V_155 = V_106 -> V_192 ,
. V_17 = V_106 -> V_109 * sizeof( T_1 ) ,
}
} ;
V_25 = F_10 ( V_15 , & V_189 , sizeof( V_189 ) ) ;
if ( V_25 < 0 ) {
F_30 ( L_66 ) ;
return V_25 ;
}
}
V_12 -> V_195 = F_102 ( V_15 , 0 , V_174 ) ;
V_12 -> V_196 = V_8 * sizeof( struct V_5 ) ;
if ( V_4 ) {
V_25 = F_10 ( V_15 , V_4 , V_12 -> V_196 ) ;
if ( V_25 < 0 ) {
F_30 ( L_67 ) ;
return V_25 ;
}
}
V_12 -> V_180 = F_102 ( V_15 , 0 , V_174 ) ;
if ( V_186 ) {
V_25 = F_110 ( V_12 , V_84 , V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_183 = (struct V_187 ) {
. V_184 = V_185 ,
. V_17 = sizeof( V_183 ) ,
. V_197 = sizeof( V_189 ) ,
. V_198 = {
. V_155 = V_12 -> V_194 ,
. V_17 = V_84 -> V_199 * sizeof( V_189 ) ,
} ,
. V_166 = {
. V_155 = V_12 -> V_180 ,
. V_17 = V_12 -> V_181 ,
} ,
. V_200 = {
. V_155 = V_12 -> V_195 ,
. V_17 = V_12 -> V_196 ,
} ,
} ;
memcpy ( & V_183 . V_14 , & V_12 -> V_14 , sizeof( V_12 -> V_14 ) ) ;
F_102 ( V_15 , 0 , V_162 ) ;
V_25 = F_10 ( V_15 , & V_183 , sizeof( V_183 ) ) ;
if ( V_25 < 0 ) {
F_30 ( L_65 ) ;
return V_25 ;
}
F_102 ( V_15 , V_12 -> V_180 + V_12 -> V_181 , V_162 ) ;
V_12 -> V_201 = 1 ;
return 0 ;
}
static int F_116 ( struct V_11 * V_12 ,
int V_15 , void * V_16 , T_2 V_17 )
{
if ( F_117 ( V_15 , V_16 , V_17 ) <= 0 )
return - 1 ;
if ( V_12 -> V_31 )
F_118 ( V_16 , V_17 ) ;
return 0 ;
}
int F_108 ( struct V_11 * V_12 , int V_15 ,
void * V_166 ,
int (* F_119)( struct V_164 * T_11 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_166 ) )
{
struct V_164 * V_176 , * V_202 ;
int V_175 ;
int V_177 ;
int V_13 ;
int V_25 ;
V_175 = F_111 ( V_12 -> V_14 , V_179 ) ;
if ( ! V_175 )
return 0 ;
V_176 = V_202 = calloc ( sizeof( * V_176 ) , V_175 ) ;
if ( ! V_176 )
return - 1 ;
V_177 = sizeof( * V_176 ) * V_175 ;
F_102 ( V_15 , V_12 -> V_180 + V_12 -> V_181 , V_162 ) ;
V_25 = F_116 ( V_12 , V_15 , V_176 , V_177 ) ;
if ( V_25 < 0 )
goto V_73;
F_112 (feat, header->adds_features, HEADER_LAST_FEATURE) {
V_25 = F_119 ( V_202 ++ , V_12 , V_13 , V_15 , V_166 ) ;
if ( V_25 < 0 )
goto V_73;
}
V_25 = 0 ;
V_73:
free ( V_176 ) ;
return V_25 ;
}
static int F_120 ( T_10 V_203 , struct V_11 * V_29 )
{
T_10 V_204 , V_197 ;
int V_10 ;
for ( V_10 = 0 ; V_205 [ V_10 ] ; V_10 ++ ) {
V_204 = V_205 [ V_10 ]
+ sizeof( struct V_164 ) ;
if ( V_203 != V_204 ) {
V_197 = F_90 ( V_203 ) ;
if ( V_197 != V_204 )
continue;
V_29 -> V_31 = true ;
}
F_30 ( L_68 ,
V_10 ,
V_29 -> V_31 ) ;
return 0 ;
}
return - 1 ;
}
static int F_121 ( T_10 V_203 , struct V_11 * V_29 )
{
T_1 V_197 ;
int V_10 ;
for ( V_10 = 0 ; V_206 [ V_10 ] ; V_10 ++ ) {
if ( V_203 != V_206 [ V_10 ] ) {
V_197 = F_90 ( V_203 ) ;
if ( V_197 != V_203 )
continue;
V_29 -> V_31 = true ;
}
F_30 ( L_69 , V_10 ) ;
return 0 ;
}
return - 1 ;
}
static int F_122 ( T_1 V_184 , T_10 V_203 ,
bool V_207 , struct V_11 * V_29 )
{
int V_18 ;
V_18 = memcmp ( & V_184 , V_208 , sizeof( V_184 ) ) ;
if ( V_18 == 0 ) {
F_30 ( L_70 ) ;
if ( V_207 )
return F_121 ( V_203 , V_29 ) ;
return F_120 ( V_203 , V_29 ) ;
}
if ( V_184 == V_209 )
return 0 ;
if ( V_184 != V_210 )
return - 1 ;
V_29 -> V_31 = true ;
return 0 ;
}
int F_123 ( struct V_187 * V_12 ,
struct V_11 * V_29 , int V_15 )
{
int V_18 ;
F_102 ( V_15 , 0 , V_162 ) ;
V_18 = F_117 ( V_15 , V_12 , sizeof( * V_12 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
if ( F_122 ( V_12 -> V_184 ,
V_12 -> V_197 , false , V_29 ) < 0 ) {
F_30 ( L_71 ) ;
return - 1 ;
}
if ( V_29 -> V_31 ) {
F_118 ( V_12 , F_124 ( struct V_187 ,
V_14 ) ) ;
}
if ( V_12 -> V_17 != sizeof( * V_12 ) ) {
if ( V_12 -> V_17 == F_124 ( F_125 ( * V_12 ) , V_14 ) )
F_126 ( V_12 -> V_14 , V_179 ) ;
else
return - 1 ;
} else if ( V_29 -> V_31 ) {
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < F_127 ( V_179 ) ; ++ V_10 )
V_12 -> V_14 [ V_10 ] = F_90 ( V_12 -> V_14 [ V_10 ] ) ;
if ( ! F_9 ( V_211 , V_12 -> V_14 ) ) {
for ( V_10 = 0 ; V_10 < F_127 ( V_179 ) ; ++ V_10 ) {
V_12 -> V_14 [ V_10 ] = F_90 ( V_12 -> V_14 [ V_10 ] ) ;
V_12 -> V_14 [ V_10 ] = F_17 ( V_12 -> V_14 [ V_10 ] ) ;
}
}
if ( ! F_9 ( V_211 , V_12 -> V_14 ) ) {
F_126 ( V_12 -> V_14 , V_179 ) ;
F_5 ( V_212 , V_12 -> V_14 ) ;
}
}
memcpy ( & V_29 -> V_14 , & V_12 -> V_14 ,
sizeof( V_29 -> V_14 ) ) ;
V_29 -> V_195 = V_12 -> V_200 . V_155 ;
V_29 -> V_196 = V_12 -> V_200 . V_17 ;
V_29 -> V_180 = V_12 -> V_166 . V_155 ;
V_29 -> V_181 = V_12 -> V_166 . V_17 ;
return 0 ;
}
static int F_128 ( struct V_164 * T_11 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_166 V_82 )
{
if ( F_102 ( V_15 , T_11 -> V_155 , V_162 ) == ( V_163 ) - 1 ) {
F_30 ( L_57 V_126 L_58
L_59 , T_11 -> V_155 , V_13 ) ;
return 0 ;
}
if ( V_13 >= V_169 ) {
F_30 ( L_72 , V_13 ) ;
return 0 ;
}
if ( ! V_170 [ V_13 ] . F_119 )
return 0 ;
return V_170 [ V_13 ] . F_119 ( T_11 , V_29 , V_13 , V_15 ) ;
}
static int F_129 ( struct V_182 * V_12 ,
struct V_11 * V_29 , int V_15 ,
bool V_213 )
{
int V_18 ;
V_18 = F_117 ( V_15 , V_12 , sizeof( * V_12 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
if ( F_122 ( V_12 -> V_184 , V_12 -> V_17 , true , V_29 ) < 0 ) {
F_30 ( L_73 ) ;
return - 1 ;
}
if ( V_29 -> V_31 )
V_12 -> V_17 = F_90 ( V_12 -> V_17 ) ;
if ( V_213 && F_10 ( V_214 , V_12 , sizeof( * V_12 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int F_130 ( struct V_57 * V_58 , int V_15 )
{
struct V_11 * V_12 = & V_58 -> V_12 ;
struct V_182 V_183 ;
if ( F_129 ( & V_183 , V_12 , V_15 ,
V_58 -> V_213 ) < 0 ) {
F_30 ( L_74 ) ;
return - V_215 ;
}
V_58 -> V_15 = V_15 ;
return 0 ;
}
static int F_131 ( int V_15 , struct V_11 * V_29 ,
struct V_188 * V_189 )
{
struct V_138 * V_106 = & V_189 -> V_106 ;
T_2 V_30 , V_216 ;
T_2 V_217 = sizeof( V_189 -> V_106 ) ;
int V_18 ;
memset ( V_189 , 0 , sizeof( * V_189 ) ) ;
V_18 = F_117 ( V_15 , V_106 , V_218 ) ;
if ( V_18 <= 0 ) {
F_30 ( L_75 ,
V_218 ) ;
return - 1 ;
}
V_30 = V_106 -> V_17 ;
if ( V_29 -> V_31 )
V_30 = F_17 ( V_30 ) ;
if ( V_30 == 0 ) {
V_30 = V_218 ;
} else if ( V_30 > V_217 ) {
F_30 ( L_76
L_77 , V_30 - V_217 ) ;
return - 1 ;
}
V_216 = V_30 - V_218 ;
if ( V_216 ) {
void * V_219 = V_106 ;
V_219 += V_218 ;
V_18 = F_117 ( V_15 , V_219 , V_216 ) ;
}
V_18 = F_117 ( V_15 , & V_189 -> V_109 , sizeof( V_189 -> V_109 ) ) ;
return V_18 <= 0 ? - 1 : 0 ;
}
int F_132 ( struct V_57 * V_58 , int V_15 )
{
struct V_11 * V_12 = & V_58 -> V_12 ;
struct V_187 V_183 ;
struct V_188 V_189 ;
T_1 V_220 ;
int V_221 , V_222 , V_10 , V_134 ;
V_58 -> V_84 = F_133 ( NULL , NULL ) ;
if ( V_58 -> V_84 == NULL )
return - V_6 ;
if ( V_58 -> V_223 )
return F_130 ( V_58 , V_15 ) ;
if ( F_123 ( & V_183 , V_12 , V_15 ) < 0 )
return - V_215 ;
V_221 = V_183 . V_198 . V_17 / V_183 . V_197 ;
F_102 ( V_15 , V_183 . V_198 . V_155 , V_162 ) ;
for ( V_10 = 0 ; V_10 < V_221 ; V_10 ++ ) {
struct V_105 * V_224 ;
V_163 V_225 ;
if ( F_131 ( V_15 , V_12 , & V_189 ) < 0 )
goto V_226;
if ( V_12 -> V_31 )
F_89 ( & V_189 . V_106 ) ;
V_225 = F_102 ( V_15 , 0 , V_174 ) ;
V_224 = F_134 ( & V_189 . V_106 , V_10 ) ;
if ( V_224 == NULL )
goto V_227;
F_135 ( V_58 -> V_84 , V_224 ) ;
V_222 = V_189 . V_109 . V_17 / sizeof( T_1 ) ;
if ( F_136 ( V_224 , 1 , V_222 ) )
goto V_227;
F_102 ( V_15 , V_189 . V_109 . V_155 , V_162 ) ;
for ( V_134 = 0 ; V_134 < V_222 ; V_134 ++ ) {
if ( F_116 ( V_12 , V_15 , & V_220 , sizeof( V_220 ) ) )
goto V_226;
F_137 ( V_58 -> V_84 , V_224 , 0 , V_134 , V_220 ) ;
}
F_102 ( V_15 , V_225 , V_162 ) ;
}
V_71 . V_228 = V_221 ;
if ( V_183 . V_200 . V_17 ) {
F_102 ( V_15 , V_183 . V_200 . V_155 , V_162 ) ;
V_4 = malloc ( V_183 . V_200 . V_17 ) ;
if ( V_4 == NULL )
return - V_6 ;
if ( F_116 ( V_12 , V_15 , V_4 ,
V_183 . V_200 . V_17 ) )
goto V_226;
V_8 = V_183 . V_200 . V_17 / sizeof( struct V_5 ) ;
}
F_108 ( V_12 , V_15 , NULL ,
F_128 ) ;
F_102 ( V_15 , V_12 -> V_180 , V_162 ) ;
V_12 -> V_201 = 1 ;
return 0 ;
V_226:
return - V_19 ;
V_227:
F_138 ( V_58 -> V_84 ) ;
V_58 -> V_84 = NULL ;
return - V_6 ;
}
int F_139 ( struct V_229 * V_230 ,
struct V_138 * V_106 , T_6 V_109 , T_1 * V_1 ,
T_12 F_119 )
{
union V_231 * V_232 ;
T_2 V_17 ;
int V_25 ;
V_17 = sizeof( struct V_138 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_17 += sizeof( struct V_156 ) ;
V_17 += V_109 * sizeof( T_1 ) ;
V_232 = malloc ( V_17 ) ;
if ( V_232 == NULL )
return - V_6 ;
V_232 -> V_106 . V_106 = * V_106 ;
memcpy ( V_232 -> V_106 . V_1 , V_1 , V_109 * sizeof( T_1 ) ) ;
V_232 -> V_106 . V_12 . type = V_233 ;
V_232 -> V_106 . V_12 . V_17 = V_17 ;
V_25 = F_119 ( V_230 , V_232 , NULL , NULL ) ;
free ( V_232 ) ;
return V_25 ;
}
int F_140 ( struct V_229 * V_230 ,
struct V_57 * V_58 ,
T_12 F_119 )
{
struct V_105 * V_106 ;
int V_25 = 0 ;
F_65 (attr, &session->evlist->entries, node) {
V_25 = F_139 ( V_230 , & V_106 -> V_106 , V_106 -> V_109 ,
V_106 -> V_1 , F_119 ) ;
if ( V_25 ) {
F_30 ( L_78 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_141 ( union V_231 * V_234 ,
struct V_83 * * V_235 )
{
unsigned int V_10 , V_109 , V_236 ;
struct V_105 * V_224 ;
struct V_83 * V_84 = * V_235 ;
if ( V_84 == NULL ) {
* V_235 = V_84 = F_133 ( NULL , NULL ) ;
if ( V_84 == NULL )
return - V_6 ;
}
V_224 = F_134 ( & V_234 -> V_106 . V_106 , V_84 -> V_199 ) ;
if ( V_224 == NULL )
return - V_6 ;
F_135 ( V_84 , V_224 ) ;
V_109 = V_234 -> V_12 . V_17 ;
V_109 -= ( void * ) & V_234 -> V_106 . V_1 - ( void * ) V_234 ;
V_236 = V_109 / sizeof( T_1 ) ;
if ( F_136 ( V_224 , 1 , V_236 ) )
return - V_6 ;
for ( V_10 = 0 ; V_10 < V_236 ; V_10 ++ ) {
F_137 ( V_84 , V_224 , 0 , V_10 , V_234 -> V_106 . V_1 [ V_10 ] ) ;
}
return 0 ;
}
int F_142 ( struct V_229 * V_230 ,
T_1 V_9 , char * V_2 ,
T_12 F_119 ,
struct V_48 * V_48 )
{
union V_231 V_232 ;
T_2 V_17 = 0 ;
int V_25 = 0 ;
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
V_232 . V_237 . V_237 . V_9 = V_9 ;
memset ( V_232 . V_237 . V_237 . V_2 , 0 , V_3 ) ;
strncpy ( V_232 . V_237 . V_237 . V_2 , V_2 , V_3 - 1 ) ;
V_232 . V_237 . V_12 . type = V_238 ;
V_17 = strlen ( V_232 . V_237 . V_237 . V_2 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_232 . V_237 . V_12 . V_17 = sizeof( V_232 . V_237 ) -
( sizeof( V_232 . V_237 . V_237 . V_2 ) - V_17 ) ;
V_25 = F_119 ( V_230 , & V_232 , NULL , V_48 ) ;
return V_25 ;
}
int F_143 ( struct V_229 * V_230 ,
T_12 F_119 ,
struct V_48 * V_48 )
{
struct V_5 * type ;
int V_10 , V_25 = 0 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ ) {
type = & V_4 [ V_10 ] ;
V_25 = F_142 ( V_230 , type -> V_9 ,
type -> V_2 , F_119 ,
V_48 ) ;
if ( V_25 ) {
F_30 ( L_79 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_144 ( struct V_229 * V_230 V_165 ,
union V_231 * V_234 )
{
if ( F_1 ( V_234 -> V_237 . V_237 . V_9 ,
V_234 -> V_237 . V_237 . V_2 ) < 0 )
return - V_6 ;
return 0 ;
}
int F_145 ( struct V_229 * V_230 , int V_15 ,
struct V_83 * V_84 ,
T_12 F_119 )
{
union V_231 V_232 ;
struct V_239 * V_240 ;
T_4 V_17 = 0 , V_241 = 0 , V_242 ;
int V_25 V_82 = 0 ;
V_240 = F_146 ( & V_84 -> V_85 , V_15 , true ) ;
if ( ! V_240 )
return - 1 ;
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
V_232 . V_239 . V_12 . type = V_243 ;
V_17 = V_240 -> V_17 ;
V_241 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_242 = V_241 - V_17 ;
V_232 . V_239 . V_12 . V_17 = sizeof( V_232 . V_239 ) ;
V_232 . V_239 . V_17 = V_241 ;
F_119 ( V_230 , & V_232 , NULL , NULL ) ;
F_147 ( V_240 ) ;
F_12 ( V_15 , NULL , 0 , V_242 ) ;
return V_241 ;
}
int F_148 ( union V_231 * V_234 ,
struct V_57 * V_58 )
{
T_4 V_244 , V_242 , V_17 = V_234 -> V_239 . V_17 ;
V_163 V_155 = F_102 ( V_58 -> V_15 , 0 , V_174 ) ;
char V_16 [ V_245 ] ;
F_102 ( V_58 -> V_15 , V_155 + sizeof( struct V_246 ) ,
V_162 ) ;
V_244 = F_104 ( V_58 -> V_15 , V_58 -> V_213 ) ;
V_242 = F_14 ( V_244 , sizeof( T_1 ) ) - V_244 ;
if ( F_16 ( V_58 -> V_15 , V_16 , V_242 ) < 0 )
F_149 ( L_80 ) ;
if ( V_58 -> V_213 ) {
int V_247 = F_11 ( V_214 , V_16 , V_242 ) ;
if ( V_247 <= 0 || V_247 != V_242 )
F_149 ( L_81 ) ;
}
if ( V_244 + V_242 != V_17 )
F_149 ( L_82 ) ;
return V_244 + V_242 ;
}
int F_150 ( struct V_229 * V_230 ,
struct V_40 * V_41 , T_6 V_39 ,
T_12 F_119 ,
struct V_48 * V_48 )
{
union V_231 V_232 ;
T_2 V_27 ;
int V_25 = 0 ;
if ( ! V_41 -> V_44 )
return V_25 ;
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
V_27 = V_41 -> V_45 + 1 ;
V_27 = F_14 ( V_27 , V_24 ) ;
memcpy ( & V_232 . V_46 . V_46 , V_41 -> V_46 , sizeof( V_41 -> V_46 ) ) ;
V_232 . V_46 . V_12 . type = V_248 ;
V_232 . V_46 . V_12 . V_39 = V_39 ;
V_232 . V_46 . V_38 = V_48 -> V_38 ;
V_232 . V_46 . V_12 . V_17 = sizeof( V_232 . V_46 ) + V_27 ;
memcpy ( & V_232 . V_46 . V_68 , V_41 -> V_47 , V_41 -> V_45 ) ;
V_25 = F_119 ( V_230 , & V_232 , NULL , V_48 ) ;
return V_25 ;
}
int F_151 ( struct V_229 * V_230 V_82 ,
union V_231 * V_234 ,
struct V_57 * V_58 )
{
F_95 ( & V_234 -> V_46 ,
V_234 -> V_46 . V_68 ,
V_58 ) ;
return 0 ;
}
void F_152 ( void )
{
V_86 = true ;
}
