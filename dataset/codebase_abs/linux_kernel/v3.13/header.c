void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_3 , V_2 -> V_4 ) ;
}
void F_3 ( struct V_1 * V_2 , int V_3 )
{
F_4 ( V_3 , V_2 -> V_4 ) ;
}
bool F_5 ( const struct V_1 * V_2 , int V_3 )
{
return F_6 ( V_3 , V_2 -> V_4 ) ;
}
static int F_7 ( int V_5 , const void * V_6 , T_1 V_7 )
{
while ( V_7 ) {
int V_8 = F_8 ( V_5 , V_6 , V_7 ) ;
if ( V_8 < 0 )
return - V_9 ;
V_7 -= V_8 ;
V_6 += V_8 ;
}
return 0 ;
}
static int F_9 ( int V_5 , const void * V_10 , T_1 V_11 ,
T_1 V_12 )
{
static const char V_13 [ V_14 ] ;
int V_15 = F_7 ( V_5 , V_10 , V_11 ) ;
if ( ! V_15 )
V_15 = F_7 ( V_5 , V_13 , V_12 - V_11 ) ;
return V_15 ;
}
static int F_10 ( int V_5 , const char * V_16 )
{
T_2 V_17 , V_18 ;
int V_8 ;
V_18 = strlen ( V_16 ) + 1 ;
V_17 = F_11 ( V_18 , V_14 ) ;
V_8 = F_7 ( V_5 , & V_17 , sizeof( V_17 ) ) ;
if ( V_8 < 0 )
return V_8 ;
return F_9 ( V_5 , V_16 , V_18 , V_17 ) ;
}
static char * F_12 ( int V_5 , struct V_1 * V_19 )
{
T_3 V_20 , V_8 ;
T_2 V_17 ;
char * V_6 ;
V_20 = F_13 ( V_5 , & V_17 , sizeof( V_17 ) ) ;
if ( V_20 < ( T_3 ) sizeof( V_17 ) )
return NULL ;
if ( V_19 -> V_21 )
V_17 = F_14 ( V_17 ) ;
V_6 = malloc ( V_17 ) ;
if ( ! V_6 )
return NULL ;
V_8 = F_13 ( V_5 , V_6 , V_17 ) ;
if ( V_8 == ( T_3 ) V_17 ) {
return V_6 ;
}
free ( V_6 ) ;
return NULL ;
}
int
F_15 ( int V_22 , const char * * V_23 )
{
int V_24 ;
if ( V_25 )
return 0 ;
V_26 = ( T_2 ) V_22 ;
V_25 = calloc ( V_22 , sizeof( char * ) ) ;
if ( ! V_25 )
return - V_27 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ )
V_25 [ V_24 ] = V_23 [ V_24 ] ;
return 0 ;
}
static int F_16 ( char * V_28 , T_1 V_29 , T_4 * V_30 ,
T_5 V_31 , T_6 V_32 , int V_5 )
{
int V_15 ;
struct V_33 V_34 ;
T_1 V_17 ;
V_17 = V_29 + 1 ;
V_17 = F_11 ( V_17 , V_14 ) ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
memcpy ( & V_34 . V_30 , V_30 , V_35 ) ;
V_34 . V_31 = V_31 ;
V_34 . V_2 . V_32 = V_32 ;
V_34 . V_2 . V_7 = sizeof( V_34 ) + V_17 ;
V_15 = F_7 ( V_5 , & V_34 , sizeof( V_34 ) ) ;
if ( V_15 < 0 )
return V_15 ;
return F_9 ( V_5 , V_28 , V_29 + 1 , V_17 ) ;
}
static int F_17 ( struct V_36 * V_37 ,
struct V_38 * V_38 ,
T_5 V_31 , T_6 V_32 , int V_5 )
{
char V_39 [ V_40 ] ;
struct V_41 * V_42 ;
F_18 (pos, head) {
int V_15 ;
char * V_28 ;
T_1 V_29 ;
if ( ! V_42 -> V_43 )
continue;
if ( F_19 ( V_42 -> V_44 ) ) {
V_28 = ( char * ) V_45 ;
V_29 = sizeof( V_45 ) + 1 ;
} else if ( F_20 ( V_42 ) ) {
F_21 ( V_38 , V_39 , sizeof( V_39 ) ) ;
V_28 = V_39 ;
V_29 = strlen ( V_39 ) + 1 ;
} else {
V_28 = V_42 -> V_46 ;
V_29 = V_42 -> V_47 + 1 ;
}
V_15 = F_16 ( V_28 , V_29 , V_42 -> V_30 ,
V_31 , V_32 , V_5 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_22 ( struct V_38 * V_38 , int V_5 )
{
int V_15 ;
T_6 V_48 = V_49 ,
V_50 = V_51 ;
if ( ! F_23 ( V_38 ) ) {
V_48 = V_52 ;
V_50 = V_53 ;
}
V_15 = F_17 ( & V_38 -> V_54 , V_38 ,
V_38 -> V_31 , V_48 , V_5 ) ;
if ( V_15 == 0 )
V_15 = F_17 ( & V_38 -> V_55 , V_38 ,
V_38 -> V_31 , V_50 , V_5 ) ;
return V_15 ;
}
static int F_24 ( struct V_1 * V_2 , int V_5 )
{
struct V_56 * V_57 = F_25 ( V_2 ,
struct V_56 , V_2 ) ;
struct V_58 * V_59 ;
int V_15 = F_22 ( & V_57 -> V_60 . V_61 , V_5 ) ;
if ( V_15 )
return V_15 ;
for ( V_59 = F_26 ( & V_57 -> V_60 . V_62 ) ; V_59 ; V_59 = F_27 ( V_59 ) ) {
struct V_38 * V_42 = F_28 ( V_59 , struct V_38 , V_58 ) ;
V_15 = F_22 ( V_42 , V_5 ) ;
if ( V_15 )
break;
}
return V_15 ;
}
int F_29 ( const char * V_63 , const char * V_64 ,
const char * V_28 , bool V_65 , bool V_66 )
{
const T_1 V_7 = V_40 ;
char * V_67 , * V_68 = F_30 ( V_7 ) ,
* V_69 = F_30 ( V_7 ) , * V_70 ;
int V_17 , V_15 = - 1 ;
bool V_71 = V_65 || V_66 ;
if ( V_65 ) {
if ( V_72 . V_73 ) {
F_31 ( L_1 ) ;
V_15 = 0 ;
goto V_74;
}
V_67 = ( char * ) V_28 ;
} else
V_67 = F_32 ( V_28 , NULL ) ;
if ( V_67 == NULL || V_68 == NULL || V_69 == NULL )
goto V_74;
V_17 = F_33 ( V_68 , V_7 , L_2 ,
V_64 , V_71 ? L_3 : L_4 ,
V_66 ? V_45 : V_67 ) ;
if ( F_34 ( V_68 , 0755 ) )
goto V_74;
snprintf ( V_68 + V_17 , V_7 - V_17 , L_5 , V_63 ) ;
if ( F_35 ( V_68 , V_75 ) ) {
if ( V_65 ) {
if ( F_36 ( L_6 , V_68 ) )
goto V_74;
} else if ( F_37 ( V_67 , V_68 ) && F_36 ( V_28 , V_68 ) )
goto V_74;
}
V_17 = F_33 ( V_69 , V_7 , L_7 ,
V_64 , V_63 ) ;
if ( F_35 ( V_69 , V_76 ) && F_34 ( V_69 , 0755 ) )
goto V_74;
snprintf ( V_69 + V_17 , V_7 - V_17 , L_5 , V_63 + 2 ) ;
V_70 = V_68 + strlen ( V_64 ) - 5 ;
memcpy ( V_70 , L_8 , 5 ) ;
if ( F_38 ( V_70 , V_69 ) == 0 )
V_15 = 0 ;
V_74:
if ( ! V_65 )
free ( V_67 ) ;
free ( V_68 ) ;
free ( V_69 ) ;
return V_15 ;
}
static int F_39 ( const T_4 * V_30 , T_1 V_77 ,
const char * V_28 , const char * V_64 ,
bool V_65 , bool V_66 )
{
char V_63 [ V_35 * 2 + 1 ] ;
F_40 ( V_30 , V_77 , V_63 ) ;
return F_29 ( V_63 , V_64 , V_28 ,
V_65 , V_66 ) ;
}
int F_41 ( const char * V_63 , const char * V_64 )
{
const T_1 V_7 = V_40 ;
char * V_68 = F_30 ( V_7 ) ,
* V_69 = F_30 ( V_7 ) ;
int V_15 = - 1 ;
if ( V_68 == NULL || V_69 == NULL )
goto V_74;
snprintf ( V_69 , V_7 , L_9 ,
V_64 , V_63 , V_63 + 2 ) ;
if ( F_35 ( V_69 , V_75 ) )
goto V_74;
if ( F_42 ( V_69 , V_68 , V_7 - 1 ) < 0 )
goto V_74;
if ( F_43 ( V_69 ) )
goto V_74;
snprintf ( V_69 , V_7 , L_9 ,
V_64 , V_63 , V_68 ) ;
if ( F_43 ( V_69 ) )
goto V_74;
V_15 = 0 ;
V_74:
free ( V_68 ) ;
free ( V_69 ) ;
return V_15 ;
}
static int F_44 ( struct V_41 * V_41 , struct V_38 * V_38 ,
const char * V_64 )
{
bool V_65 = V_41 -> V_78 && V_41 -> V_46 [ 0 ] != '/' ;
bool V_66 = F_19 ( V_41 -> V_44 ) ;
char * V_28 = V_41 -> V_46 ;
char V_39 [ V_40 ] ;
if ( F_20 ( V_41 ) ) {
V_65 = true ;
F_21 ( V_38 , V_39 , sizeof( V_39 ) ) ;
V_28 = V_39 ;
}
return F_39 ( V_41 -> V_30 , sizeof( V_41 -> V_30 ) , V_28 ,
V_64 , V_65 , V_66 ) ;
}
static int F_45 ( struct V_36 * V_37 ,
struct V_38 * V_38 , const char * V_64 )
{
struct V_41 * V_42 ;
int V_15 = 0 ;
F_18 (pos, head)
if ( F_44 ( V_42 , V_38 , V_64 ) )
V_15 = - 1 ;
return V_15 ;
}
static int F_46 ( struct V_38 * V_38 , const char * V_64 )
{
int V_8 = F_45 ( & V_38 -> V_54 , V_38 ,
V_64 ) ;
V_8 |= F_45 ( & V_38 -> V_55 , V_38 , V_64 ) ;
return V_8 ;
}
static int F_47 ( struct V_56 * V_57 )
{
struct V_58 * V_59 ;
int V_8 ;
char V_64 [ V_40 ] ;
snprintf ( V_64 , sizeof( V_64 ) , L_10 , V_79 ) ;
if ( F_48 ( V_64 , 0755 ) != 0 && V_9 != V_80 )
return - 1 ;
V_8 = F_46 ( & V_57 -> V_60 . V_61 , V_64 ) ;
for ( V_59 = F_26 ( & V_57 -> V_60 . V_62 ) ; V_59 ; V_59 = F_27 ( V_59 ) ) {
struct V_38 * V_42 = F_28 ( V_59 , struct V_38 , V_58 ) ;
V_8 |= F_46 ( V_42 , V_64 ) ;
}
return V_8 ? - 1 : 0 ;
}
static bool F_49 ( struct V_38 * V_38 , bool V_81 )
{
bool V_8 = F_50 ( & V_38 -> V_54 , V_81 ) ;
V_8 |= F_50 ( & V_38 -> V_55 , V_81 ) ;
return V_8 ;
}
static bool F_51 ( struct V_56 * V_57 , bool V_81 )
{
struct V_58 * V_59 ;
bool V_8 = F_49 ( & V_57 -> V_60 . V_61 , V_81 ) ;
for ( V_59 = F_26 ( & V_57 -> V_60 . V_62 ) ; V_59 ; V_59 = F_27 ( V_59 ) ) {
struct V_38 * V_42 = F_28 ( V_59 , struct V_38 , V_58 ) ;
V_8 |= F_49 ( V_42 , V_81 ) ;
}
return V_8 ;
}
static int F_52 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 )
{
return F_53 ( V_5 , & V_84 -> V_85 ) ;
}
static int F_54 ( int V_5 , struct V_1 * T_7 ,
struct V_83 * V_84 V_82 )
{
struct V_56 * V_57 ;
int V_15 ;
V_57 = F_25 ( T_7 , struct V_56 , V_2 ) ;
if ( ! F_51 ( V_57 , true ) )
return - 1 ;
V_15 = F_24 ( T_7 , V_5 ) ;
if ( V_15 < 0 ) {
F_31 ( L_11 ) ;
return V_15 ;
}
if ( ! V_86 )
F_47 ( V_57 ) ;
return 0 ;
}
static int F_55 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_87 V_88 ;
int V_8 ;
V_8 = F_56 ( & V_88 ) ;
if ( V_8 < 0 )
return - 1 ;
return F_10 ( V_5 , V_88 . V_89 ) ;
}
static int F_57 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_87 V_88 ;
int V_8 ;
V_8 = F_56 ( & V_88 ) ;
if ( V_8 < 0 )
return - 1 ;
return F_10 ( V_5 , V_88 . V_90 ) ;
}
static int F_58 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_87 V_88 ;
int V_8 ;
V_8 = F_56 ( & V_88 ) ;
if ( V_8 < 0 )
return - 1 ;
return F_10 ( V_5 , V_88 . V_38 ) ;
}
static int F_59 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
return F_10 ( V_5 , V_91 ) ;
}
static int F_60 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
#ifndef F_61
#define F_61 NULL
#endif
T_8 * V_92 ;
char * V_6 = NULL ;
char * V_93 , * V_94 ;
const char * V_95 = F_61 ;
T_1 V_17 = 0 ;
int V_8 = - 1 ;
if ( ! V_95 )
return - 1 ;
V_92 = fopen ( L_12 , L_13 ) ;
if ( ! V_92 )
return - 1 ;
while ( F_62 ( & V_6 , & V_17 , V_92 ) > 0 ) {
V_8 = strncmp ( V_6 , V_95 , strlen ( V_95 ) ) ;
if ( ! V_8 )
break;
}
if ( V_8 )
goto V_96;
V_93 = V_6 ;
V_94 = strchr ( V_6 , ':' ) ;
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
V_8 = F_10 ( V_5 , V_93 ) ;
V_96:
free ( V_6 ) ;
fclose ( V_92 ) ;
return V_8 ;
}
static int F_63 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
long V_99 ;
T_2 V_100 , V_101 ;
int V_8 ;
V_99 = F_64 ( V_102 ) ;
if ( V_99 < 0 )
return - 1 ;
V_100 = ( T_2 ) ( V_99 & V_103 ) ;
V_99 = F_64 ( V_104 ) ;
if ( V_99 < 0 )
return - 1 ;
V_101 = ( T_2 ) ( V_99 & V_103 ) ;
V_8 = F_7 ( V_5 , & V_100 , sizeof( V_100 ) ) ;
if ( V_8 < 0 )
return V_8 ;
return F_7 ( V_5 , & V_101 , sizeof( V_101 ) ) ;
}
static int F_65 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 )
{
struct V_105 * V_106 ;
T_2 V_107 , V_108 , V_20 ;
int V_8 ;
V_107 = V_84 -> V_109 ;
V_8 = F_7 ( V_5 , & V_107 , sizeof( V_107 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_20 = ( T_2 ) sizeof( V_106 -> V_110 ) ;
V_8 = F_7 ( V_5 , & V_20 , sizeof( V_20 ) ) ;
if ( V_8 < 0 )
return V_8 ;
F_66 (evsel, &evlist->entries, node) {
V_8 = F_7 ( V_5 , & V_106 -> V_110 , V_20 ) ;
if ( V_8 < 0 )
return V_8 ;
V_108 = V_106 -> V_111 ;
V_8 = F_7 ( V_5 , & V_108 , sizeof( V_108 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_10 ( V_5 , F_67 ( V_106 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_7 ( V_5 , V_106 -> V_112 , V_106 -> V_111 * sizeof( V_113 ) ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int F_68 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
char V_6 [ V_114 ] ;
char V_115 [ 32 ] ;
T_2 V_24 , V_116 ;
int V_8 ;
sprintf ( V_115 , L_14 , F_69 () ) ;
V_8 = F_42 ( V_115 , V_6 , sizeof( V_6 ) ) ;
if ( V_8 <= 0 )
return - 1 ;
V_6 [ V_8 ] = '\0' ;
V_116 = V_26 + 1 ;
V_8 = F_7 ( V_5 , & V_116 , sizeof( V_116 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_10 ( V_5 , V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
V_8 = F_10 ( V_5 , V_25 [ V_24 ] ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int F_70 ( struct V_117 * V_118 , int V_119 )
{
T_8 * V_120 ;
char V_68 [ V_114 ] ;
char * V_6 = NULL , * V_94 ;
T_1 V_17 = 0 ;
T_3 V_121 ;
T_2 V_24 = 0 ;
int V_8 = - 1 ;
sprintf ( V_68 , V_122 , V_119 ) ;
V_120 = fopen ( V_68 , L_13 ) ;
if ( ! V_120 )
goto V_123;
V_121 = F_62 ( & V_6 , & V_17 , V_120 ) ;
fclose ( V_120 ) ;
if ( V_121 <= 0 )
goto V_123;
V_94 = strchr ( V_6 , '\n' ) ;
if ( V_94 )
* V_94 = '\0' ;
for ( V_24 = 0 ; V_24 < V_118 -> V_124 ; V_24 ++ ) {
if ( ! strcmp ( V_6 , V_118 -> V_125 [ V_24 ] ) )
break;
}
if ( V_24 == V_118 -> V_124 ) {
V_118 -> V_125 [ V_24 ] = V_6 ;
V_118 -> V_124 ++ ;
V_6 = NULL ;
V_17 = 0 ;
}
V_8 = 0 ;
V_123:
sprintf ( V_68 , V_126 , V_119 ) ;
V_120 = fopen ( V_68 , L_13 ) ;
if ( ! V_120 )
goto V_96;
if ( F_62 ( & V_6 , & V_17 , V_120 ) <= 0 )
goto V_96;
V_94 = strchr ( V_6 , '\n' ) ;
if ( V_94 )
* V_94 = '\0' ;
for ( V_24 = 0 ; V_24 < V_118 -> V_127 ; V_24 ++ ) {
if ( ! strcmp ( V_6 , V_118 -> V_128 [ V_24 ] ) )
break;
}
if ( V_24 == V_118 -> V_127 ) {
V_118 -> V_128 [ V_24 ] = V_6 ;
V_118 -> V_127 ++ ;
V_6 = NULL ;
}
V_8 = 0 ;
V_96:
if( V_120 )
fclose ( V_120 ) ;
free ( V_6 ) ;
return V_8 ;
}
static void F_71 ( struct V_117 * V_118 )
{
T_2 V_24 ;
if ( ! V_118 )
return;
for ( V_24 = 0 ; V_24 < V_118 -> V_124 ; V_24 ++ )
free ( V_118 -> V_125 [ V_24 ] ) ;
for ( V_24 = 0 ; V_24 < V_118 -> V_127 ; V_24 ++ )
free ( V_118 -> V_128 [ V_24 ] ) ;
free ( V_118 ) ;
}
static struct V_117 * F_72 ( void )
{
struct V_117 * V_118 ;
void * V_129 ;
T_2 V_99 , V_24 ;
T_1 V_20 ;
long V_130 ;
int V_8 = - 1 ;
V_130 = F_64 ( V_102 ) ;
if ( V_130 < 0 )
return NULL ;
V_99 = ( T_2 ) ( V_130 & V_103 ) ;
V_20 = V_99 * sizeof( char * ) ;
V_129 = calloc ( 1 , sizeof( * V_118 ) + 2 * V_20 ) ;
if ( ! V_129 )
return NULL ;
V_118 = V_129 ;
V_129 += sizeof( * V_118 ) ;
V_118 -> V_125 = V_129 ;
V_129 += V_20 ;
V_118 -> V_128 = V_129 ;
for ( V_24 = 0 ; V_24 < V_99 ; V_24 ++ ) {
V_8 = F_70 ( V_118 , V_24 ) ;
if ( V_8 < 0 )
break;
}
if ( V_8 ) {
F_71 ( V_118 ) ;
V_118 = NULL ;
}
return V_118 ;
}
static int F_73 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_117 * V_118 ;
T_2 V_24 ;
int V_8 ;
V_118 = F_72 () ;
if ( ! V_118 )
return - 1 ;
V_8 = F_7 ( V_5 , & V_118 -> V_124 , sizeof( V_118 -> V_124 ) ) ;
if ( V_8 < 0 )
goto V_96;
for ( V_24 = 0 ; V_24 < V_118 -> V_124 ; V_24 ++ ) {
V_8 = F_10 ( V_5 , V_118 -> V_125 [ V_24 ] ) ;
if ( V_8 < 0 )
goto V_96;
}
V_8 = F_7 ( V_5 , & V_118 -> V_127 , sizeof( V_118 -> V_127 ) ) ;
if ( V_8 < 0 )
goto V_96;
for ( V_24 = 0 ; V_24 < V_118 -> V_127 ; V_24 ++ ) {
V_8 = F_10 ( V_5 , V_118 -> V_128 [ V_24 ] ) ;
if ( V_8 < 0 )
break;
}
V_96:
F_71 ( V_118 ) ;
return V_8 ;
}
static int F_74 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
char * V_6 = NULL ;
T_8 * V_120 ;
T_1 V_17 = 0 ;
int V_8 = - 1 , V_116 ;
T_9 V_131 ;
V_120 = fopen ( L_15 , L_13 ) ;
if ( ! V_120 )
return - 1 ;
while ( F_62 ( & V_6 , & V_17 , V_120 ) > 0 ) {
V_8 = strncmp ( V_6 , L_16 , 9 ) ;
if ( ! V_8 )
break;
}
if ( ! V_8 ) {
V_116 = sscanf ( V_6 , L_17 V_132 , & V_131 ) ;
if ( V_116 == 1 )
V_8 = F_7 ( V_5 , & V_131 , sizeof( V_131 ) ) ;
}
free ( V_6 ) ;
fclose ( V_120 ) ;
return V_8 ;
}
static int F_75 ( int V_5 , int V_133 )
{
char V_16 [ V_114 ] ;
char V_134 [ 32 ] ;
char * V_6 = NULL , * V_94 ;
T_1 V_17 = 0 ;
T_8 * V_120 ;
V_113 V_135 , V_136 , V_131 ;
int V_8 = - 1 ;
sprintf ( V_16 , L_18 , V_133 ) ;
V_120 = fopen ( V_16 , L_13 ) ;
if ( ! V_120 )
return - 1 ;
while ( F_62 ( & V_6 , & V_17 , V_120 ) > 0 ) {
if ( ! strchr ( V_6 , ':' ) )
continue;
if ( sscanf ( V_6 , L_19 V_132 , V_134 , & V_131 ) != 2 )
goto V_96;
if ( ! strcmp ( V_134 , L_16 ) )
V_135 = V_131 ;
if ( ! strcmp ( V_134 , L_20 ) )
V_136 = V_131 ;
}
fclose ( V_120 ) ;
V_120 = NULL ;
V_8 = F_7 ( V_5 , & V_135 , sizeof( V_113 ) ) ;
if ( V_8 )
goto V_96;
V_8 = F_7 ( V_5 , & V_136 , sizeof( V_113 ) ) ;
if ( V_8 )
goto V_96;
V_8 = - 1 ;
sprintf ( V_16 , L_21 , V_133 ) ;
V_120 = fopen ( V_16 , L_13 ) ;
if ( ! V_120 )
goto V_96;
if ( F_62 ( & V_6 , & V_17 , V_120 ) <= 0 )
goto V_96;
V_94 = strchr ( V_6 , '\n' ) ;
if ( V_94 )
* V_94 = '\0' ;
V_8 = F_10 ( V_5 , V_6 ) ;
V_96:
free ( V_6 ) ;
if ( V_120 )
fclose ( V_120 ) ;
return V_8 ;
}
static int F_76 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
char * V_6 = NULL ;
T_1 V_17 = 0 ;
T_8 * V_120 ;
struct V_137 * V_138 = NULL ;
char * V_139 ;
T_2 V_99 , V_24 , V_140 ;
int V_8 = - 1 ;
V_120 = fopen ( L_22 , L_13 ) ;
if ( ! V_120 )
return - 1 ;
if ( F_62 ( & V_6 , & V_17 , V_120 ) <= 0 )
goto V_96;
V_139 = strchr ( V_6 , '\n' ) ;
if ( V_139 )
* V_139 = '\0' ;
V_138 = F_77 ( V_6 ) ;
if ( ! V_138 )
goto V_96;
V_99 = ( T_2 ) V_138 -> V_99 ;
V_8 = F_7 ( V_5 , & V_99 , sizeof( V_99 ) ) ;
if ( V_8 < 0 )
goto V_96;
for ( V_24 = 0 ; V_24 < V_99 ; V_24 ++ ) {
V_140 = ( T_2 ) V_138 -> V_141 [ V_24 ] ;
V_8 = F_7 ( V_5 , & V_140 , sizeof( V_140 ) ) ;
if ( V_8 < 0 )
break;
V_8 = F_75 ( V_5 , V_24 ) ;
if ( V_8 < 0 )
break;
}
V_96:
free ( V_6 ) ;
fclose ( V_120 ) ;
free ( V_138 ) ;
return V_8 ;
}
static int F_78 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_142 * V_143 = NULL ;
T_10 V_144 = F_79 ( V_5 , 0 , V_145 ) ;
T_11 V_146 = 0 ;
int V_8 ;
V_8 = F_7 ( V_5 , & V_146 , sizeof( V_146 ) ) ;
if ( V_8 < 0 )
return V_8 ;
while ( ( V_143 = F_80 ( V_143 ) ) ) {
if ( ! V_143 -> V_28 )
continue;
V_146 ++ ;
V_8 = F_7 ( V_5 , & V_143 -> type , sizeof( V_143 -> type ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_10 ( V_5 , V_143 -> V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( F_81 ( V_5 , & V_146 , sizeof( V_146 ) , V_144 ) != sizeof( V_146 ) ) {
F_79 ( V_5 , V_144 , V_147 ) ;
return - 1 ;
}
return 0 ;
}
static int F_82 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 )
{
T_2 V_148 = V_84 -> V_148 ;
struct V_105 * V_106 ;
int V_8 ;
V_8 = F_7 ( V_5 , & V_148 , sizeof( V_148 ) ) ;
if ( V_8 < 0 )
return V_8 ;
F_66 (evsel, &evlist->entries, node) {
if ( F_83 ( V_106 ) &&
V_106 -> V_149 > 1 ) {
const char * V_28 = V_106 -> V_150 ? : L_23 ;
T_2 V_151 = V_106 -> V_152 ;
T_2 V_149 = V_106 -> V_149 ;
V_8 = F_10 ( V_5 , V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_7 ( V_5 , & V_151 , sizeof( V_151 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_7 ( V_5 , & V_149 , sizeof( V_149 ) ) ;
if ( V_8 < 0 )
return V_8 ;
}
}
return 0 ;
}
static int F_84 ( int V_5 , struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
char V_153 [ 64 ] ;
int V_8 ;
V_8 = F_85 ( V_153 , sizeof( V_153 ) ) ;
if ( ! V_8 )
goto V_154;
return - 1 ;
V_154:
return F_10 ( V_5 , V_153 ) ;
}
static int F_86 ( int V_5 V_82 ,
struct V_1 * T_7 V_82 ,
struct V_83 * V_84 V_82 )
{
return 0 ;
}
static void F_87 ( struct V_1 * V_19 , int V_5 V_82 ,
T_8 * V_120 )
{
fprintf ( V_120 , L_24 , V_19 -> V_155 . V_156 ) ;
}
static void F_88 ( struct V_1 * V_19 , int V_5 V_82 ,
T_8 * V_120 )
{
fprintf ( V_120 , L_25 , V_19 -> V_155 . V_157 ) ;
}
static void F_89 ( struct V_1 * V_19 , int V_5 V_82 , T_8 * V_120 )
{
fprintf ( V_120 , L_26 , V_19 -> V_155 . V_158 ) ;
}
static void F_90 ( struct V_1 * V_19 , int V_5 V_82 ,
T_8 * V_120 )
{
fprintf ( V_120 , L_27 , V_19 -> V_155 . V_159 ) ;
}
static void F_91 ( struct V_1 * V_19 , int V_5 V_82 ,
T_8 * V_120 )
{
fprintf ( V_120 , L_28 , V_19 -> V_155 . V_160 ) ;
fprintf ( V_120 , L_29 , V_19 -> V_155 . V_161 ) ;
}
static void F_92 ( struct V_1 * V_19 , int V_5 V_82 ,
T_8 * V_120 )
{
fprintf ( V_120 , L_30 , V_19 -> V_155 . V_162 ) ;
}
static void F_93 ( struct V_1 * V_19 , int V_5 V_82 ,
T_8 * V_120 )
{
int V_99 , V_24 ;
char * V_16 ;
V_99 = V_19 -> V_155 . V_163 ;
V_16 = V_19 -> V_155 . V_164 ;
fprintf ( V_120 , L_31 ) ;
for ( V_24 = 0 ; V_24 < V_99 ; V_24 ++ ) {
fprintf ( V_120 , L_32 , V_16 ) ;
V_16 += strlen ( V_16 ) + 1 ;
}
fputc ( '\n' , V_120 ) ;
}
static void F_94 ( struct V_1 * V_19 , int V_5 V_82 ,
T_8 * V_120 )
{
int V_99 , V_24 ;
char * V_16 ;
V_99 = V_19 -> V_155 . V_165 ;
V_16 = V_19 -> V_155 . V_166 ;
for ( V_24 = 0 ; V_24 < V_99 ; V_24 ++ ) {
fprintf ( V_120 , L_33 , V_16 ) ;
V_16 += strlen ( V_16 ) + 1 ;
}
V_99 = V_19 -> V_155 . V_167 ;
V_16 = V_19 -> V_155 . V_168 ;
for ( V_24 = 0 ; V_24 < V_99 ; V_24 ++ ) {
fprintf ( V_120 , L_34 , V_16 ) ;
V_16 += strlen ( V_16 ) + 1 ;
}
}
static void F_95 ( struct V_105 * V_169 )
{
struct V_105 * V_106 ;
if ( ! V_169 )
return;
for ( V_106 = V_169 ; V_106 -> V_110 . V_7 ; V_106 ++ ) {
if ( V_106 -> V_28 )
free ( V_106 -> V_28 ) ;
if ( V_106 -> V_112 )
free ( V_106 -> V_112 ) ;
}
free ( V_169 ) ;
}
static struct V_105 *
F_96 ( struct V_1 * V_19 , int V_5 )
{
struct V_105 * V_106 , * V_169 = NULL ;
V_113 * V_112 ;
void * V_6 = NULL ;
T_2 V_107 , V_20 , V_99 , V_24 , V_140 ;
T_3 V_8 ;
T_1 V_170 ;
V_8 = F_13 ( V_5 , & V_107 , sizeof( V_107 ) ) ;
if ( V_8 != ( T_3 ) sizeof( V_107 ) )
goto error;
if ( V_19 -> V_21 )
V_107 = F_14 ( V_107 ) ;
V_8 = F_13 ( V_5 , & V_20 , sizeof( V_20 ) ) ;
if ( V_8 != ( T_3 ) sizeof( V_20 ) )
goto error;
if ( V_19 -> V_21 )
V_20 = F_14 ( V_20 ) ;
V_6 = malloc ( V_20 ) ;
if ( ! V_6 )
goto error;
V_169 = calloc ( V_107 + 1 , sizeof( * V_169 ) ) ;
if ( ! V_169 )
goto error;
V_170 = sizeof( V_106 -> V_110 ) ;
if ( V_20 < V_170 )
V_170 = V_20 ;
for ( V_24 = 0 , V_106 = V_169 ; V_24 < V_107 ; V_106 ++ , V_24 ++ ) {
V_106 -> V_152 = V_24 ;
V_8 = F_13 ( V_5 , V_6 , V_20 ) ;
if ( V_8 != ( T_3 ) V_20 )
goto error;
if ( V_19 -> V_21 )
F_97 ( V_6 ) ;
memcpy ( & V_106 -> V_110 , V_6 , V_170 ) ;
V_8 = F_13 ( V_5 , & V_99 , sizeof( V_99 ) ) ;
if ( V_8 != ( T_3 ) sizeof( V_99 ) )
goto error;
if ( V_19 -> V_21 ) {
V_99 = F_14 ( V_99 ) ;
V_106 -> V_21 = true ;
}
V_106 -> V_28 = F_12 ( V_5 , V_19 ) ;
if ( ! V_99 )
continue;
V_112 = calloc ( V_99 , sizeof( * V_112 ) ) ;
if ( ! V_112 )
goto error;
V_106 -> V_111 = V_99 ;
V_106 -> V_112 = V_112 ;
for ( V_140 = 0 ; V_140 < V_99 ; V_140 ++ ) {
V_8 = F_13 ( V_5 , V_112 , sizeof( * V_112 ) ) ;
if ( V_8 != ( T_3 ) sizeof( * V_112 ) )
goto error;
if ( V_19 -> V_21 )
* V_112 = F_98 ( * V_112 ) ;
V_112 ++ ;
}
}
V_171:
if ( V_6 )
free ( V_6 ) ;
return V_169 ;
error:
if ( V_169 )
F_95 ( V_169 ) ;
V_169 = NULL ;
goto V_171;
}
static void F_99 ( struct V_1 * V_19 , int V_5 , T_8 * V_120 )
{
struct V_105 * V_106 , * V_169 = F_96 ( V_19 , V_5 ) ;
T_2 V_140 ;
V_113 * V_112 ;
if ( ! V_169 ) {
fprintf ( V_120 , L_35 ) ;
return;
}
for ( V_106 = V_169 ; V_106 -> V_110 . V_7 ; V_106 ++ ) {
fprintf ( V_120 , L_36 , V_106 -> V_28 ) ;
fprintf ( V_120 , L_37 V_172
L_38 V_172 L_39 V_172 ,
V_106 -> V_110 . type ,
( V_113 ) V_106 -> V_110 . V_173 ,
( V_113 ) V_106 -> V_110 . V_174 ,
( V_113 ) V_106 -> V_110 . V_175 ) ;
fprintf ( V_120 , L_40 ,
V_106 -> V_110 . V_176 ,
V_106 -> V_110 . V_177 ) ;
fprintf ( V_120 , L_41 ,
V_106 -> V_110 . V_178 ,
V_106 -> V_110 . V_179 ) ;
fprintf ( V_120 , L_42 , V_106 -> V_110 . V_180 ) ;
fprintf ( V_120 , L_43 , V_106 -> V_110 . V_181 ) ;
fprintf ( V_120 , L_44 , V_106 -> V_110 . V_182 ) ;
fprintf ( V_120 , L_45 , V_106 -> V_110 . V_183 ) ;
if ( V_106 -> V_111 ) {
fprintf ( V_120 , L_46 ) ;
for ( V_140 = 0 , V_112 = V_106 -> V_112 ; V_140 < V_106 -> V_111 ; V_140 ++ , V_112 ++ ) {
if ( V_140 )
fputc ( ',' , V_120 ) ;
fprintf ( V_120 , L_47 V_132 , * V_112 ) ;
}
fprintf ( V_120 , L_48 ) ;
}
fputc ( '\n' , V_120 ) ;
}
F_95 ( V_169 ) ;
}
static void F_100 ( struct V_1 * V_19 , int V_5 V_82 ,
T_8 * V_120 )
{
fprintf ( V_120 , L_49 , V_19 -> V_155 . V_184 ) ;
}
static void F_101 ( struct V_1 * V_19 , int V_5 V_82 ,
T_8 * V_120 )
{
T_2 V_99 , V_139 , V_24 ;
char * V_16 , * V_185 ;
T_9 V_135 , V_136 ;
V_99 = V_19 -> V_155 . V_186 ;
V_16 = V_19 -> V_155 . V_187 ;
for ( V_24 = 0 ; V_24 < V_99 ; V_24 ++ ) {
V_139 = strtoul ( V_16 , & V_185 , 0 ) ;
if ( * V_185 != ':' )
goto error;
V_16 = V_185 + 1 ;
V_135 = F_102 ( V_16 , & V_185 , 0 ) ;
if ( * V_185 != ':' )
goto error;
V_16 = V_185 + 1 ;
V_136 = F_102 ( V_16 , & V_185 , 0 ) ;
if ( * V_185 != ':' )
goto error;
fprintf ( V_120 , L_50 V_132 L_51
L_52 V_132 L_53 ,
V_139 , V_135 , V_136 ) ;
V_16 = V_185 + 1 ;
fprintf ( V_120 , L_54 , V_139 , V_16 ) ;
V_16 += strlen ( V_16 ) + 1 ;
}
return;
error:
fprintf ( V_120 , L_55 ) ;
}
static void F_103 ( struct V_1 * V_19 , int V_5 V_82 , T_8 * V_120 )
{
fprintf ( V_120 , L_56 , V_19 -> V_155 . V_188 ) ;
}
static void F_104 ( struct V_1 * V_19 V_82 ,
int V_5 V_82 , T_8 * V_120 )
{
fprintf ( V_120 , L_57 ) ;
}
static void F_105 ( struct V_1 * V_19 , int V_5 V_82 ,
T_8 * V_120 )
{
const char * V_189 = L_58 ;
char * V_16 , * V_185 ;
T_2 V_146 ;
T_2 type ;
V_146 = V_19 -> V_155 . V_190 ;
if ( ! V_146 ) {
fprintf ( V_120 , L_59 ) ;
return;
}
V_16 = V_19 -> V_155 . V_191 ;
while ( V_146 ) {
type = strtoul ( V_16 , & V_185 , 0 ) ;
if ( * V_185 != ':' )
goto error;
V_16 = V_185 + 1 ;
fprintf ( V_120 , L_60 V_192 , V_189 , V_16 , type ) ;
V_189 = L_61 ;
V_16 += strlen ( V_16 ) + 1 ;
V_146 -- ;
}
fprintf ( V_120 , L_62 ) ;
if ( ! V_146 )
return;
error:
fprintf ( V_120 , L_63 ) ;
}
static void F_106 ( struct V_1 * V_19 , int V_5 V_82 ,
T_8 * V_120 )
{
struct V_56 * V_57 ;
struct V_105 * V_106 ;
T_2 V_99 = 0 ;
V_57 = F_25 ( V_19 , struct V_56 , V_2 ) ;
F_66 (evsel, &session->evlist->entries, node) {
if ( F_83 ( V_106 ) &&
V_106 -> V_149 > 1 ) {
fprintf ( V_120 , L_64 , V_106 -> V_150 ? : L_4 ,
F_67 ( V_106 ) ) ;
V_99 = V_106 -> V_149 - 1 ;
} else if ( V_99 ) {
fprintf ( V_120 , L_65 , F_67 ( V_106 ) ) ;
if ( -- V_99 == 0 )
fprintf ( V_120 , L_66 ) ;
}
}
}
static int F_107 ( struct V_33 * V_193 ,
char * V_68 ,
struct V_56 * V_57 )
{
int V_15 = - 1 ;
struct V_36 * V_37 ;
struct V_38 * V_38 ;
T_6 V_32 ;
struct V_41 * V_41 ;
enum V_194 V_195 ;
V_38 = F_108 ( V_57 , V_193 -> V_31 ) ;
if ( ! V_38 )
goto V_171;
V_32 = V_193 -> V_2 . V_32 & V_196 ;
switch ( V_32 ) {
case V_49 :
V_195 = V_197 ;
V_37 = & V_38 -> V_54 ;
break;
case V_52 :
V_195 = V_198 ;
V_37 = & V_38 -> V_54 ;
break;
case V_51 :
case V_53 :
V_195 = V_199 ;
V_37 = & V_38 -> V_55 ;
break;
default:
goto V_171;
}
V_41 = F_109 ( V_37 , V_68 ) ;
if ( V_41 != NULL ) {
char V_63 [ V_35 * 2 + 1 ] ;
F_110 ( V_41 , & V_193 -> V_30 ) ;
if ( V_68 [ 0 ] == '[' )
V_41 -> V_78 = V_195 ;
F_40 ( V_41 -> V_30 , sizeof( V_41 -> V_30 ) ,
V_63 ) ;
F_31 ( L_67 ,
V_41 -> V_46 , V_63 ) ;
}
V_15 = 0 ;
V_171:
return V_15 ;
}
static int F_111 ( struct V_1 * V_2 ,
int V_200 , V_113 V_144 , V_113 V_7 )
{
struct V_56 * V_57 = F_25 ( V_2 , struct V_56 , V_2 ) ;
struct {
struct V_201 V_2 ;
T_4 V_30 [ F_11 ( V_35 , sizeof( V_113 ) ) ] ;
char V_68 [ 0 ] ;
} V_202 ;
struct V_33 V_193 ;
char V_68 [ V_40 ] ;
V_113 V_203 = V_144 + V_7 ;
while ( V_144 < V_203 ) {
T_3 V_17 ;
if ( F_13 ( V_200 , & V_202 , sizeof( V_202 ) ) != sizeof( V_202 ) )
return - 1 ;
if ( V_2 -> V_21 )
F_112 ( & V_202 . V_2 ) ;
V_17 = V_202 . V_2 . V_7 - sizeof( V_202 ) ;
if ( F_13 ( V_200 , V_68 , V_17 ) != V_17 )
return - 1 ;
V_193 . V_2 = V_202 . V_2 ;
V_193 . V_31 = V_204 ;
if ( V_193 . V_2 . V_32 == V_53 ||
V_193 . V_2 . V_32 == V_52 )
V_193 . V_31 = V_205 ;
memcpy ( V_193 . V_30 , V_202 . V_30 , sizeof( V_193 . V_30 ) ) ;
F_107 ( & V_193 , V_68 , V_57 ) ;
V_144 += V_193 . V_2 . V_7 ;
}
return 0 ;
}
static int F_113 ( struct V_1 * V_2 ,
int V_200 , V_113 V_144 , V_113 V_7 )
{
struct V_56 * V_57 = F_25 ( V_2 , struct V_56 , V_2 ) ;
struct V_33 V_193 ;
char V_68 [ V_40 ] ;
V_113 V_203 = V_144 + V_7 , V_206 = V_144 ;
int V_15 = - 1 ;
while ( V_144 < V_203 ) {
T_3 V_17 ;
if ( F_13 ( V_200 , & V_193 , sizeof( V_193 ) ) != sizeof( V_193 ) )
goto V_171;
if ( V_2 -> V_21 )
F_112 ( & V_193 . V_2 ) ;
V_17 = V_193 . V_2 . V_7 - sizeof( V_193 ) ;
if ( F_13 ( V_200 , V_68 , V_17 ) != V_17 )
goto V_171;
if ( memcmp ( V_68 , L_68 , 13 ) == 0 ) {
if ( F_79 ( V_200 , V_206 , V_147 ) == ( T_10 ) - 1 )
return - 1 ;
return F_111 ( V_2 , V_200 , V_144 , V_7 ) ;
}
F_107 ( & V_193 , V_68 , V_57 ) ;
V_144 += V_193 . V_2 . V_7 ;
}
V_15 = 0 ;
V_171:
return V_15 ;
}
static int F_114 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 V_82 ,
int V_5 , void * V_208 )
{
T_3 V_8 = F_115 ( V_5 , V_208 , false ) ;
return V_8 < 0 ? - 1 : 0 ;
}
static int F_116 ( struct V_207 * T_12 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
if ( F_113 ( V_19 , V_5 , T_12 -> V_144 , T_12 -> V_7 ) )
F_31 ( L_69 ) ;
return 0 ;
}
static int F_117 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
V_19 -> V_155 . V_156 = F_12 ( V_5 , V_19 ) ;
return V_19 -> V_155 . V_156 ? 0 : - V_27 ;
}
static int F_118 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
V_19 -> V_155 . V_157 = F_12 ( V_5 , V_19 ) ;
return V_19 -> V_155 . V_157 ? 0 : - V_27 ;
}
static int F_119 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
V_19 -> V_155 . V_162 = F_12 ( V_5 , V_19 ) ;
return V_19 -> V_155 . V_162 ? 0 : - V_27 ;
}
static int F_120 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
V_19 -> V_155 . V_158 = F_12 ( V_5 , V_19 ) ;
return V_19 -> V_155 . V_158 ? 0 : - V_27 ;
}
static int F_121 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
T_1 V_8 ;
T_2 V_99 ;
V_8 = F_13 ( V_5 , & V_99 , sizeof( V_99 ) ) ;
if ( V_8 != sizeof( V_99 ) )
return - 1 ;
if ( V_19 -> V_21 )
V_99 = F_14 ( V_99 ) ;
V_19 -> V_155 . V_160 = V_99 ;
V_8 = F_13 ( V_5 , & V_99 , sizeof( V_99 ) ) ;
if ( V_8 != sizeof( V_99 ) )
return - 1 ;
if ( V_19 -> V_21 )
V_99 = F_14 ( V_99 ) ;
V_19 -> V_155 . V_161 = V_99 ;
return 0 ;
}
static int F_122 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
V_19 -> V_155 . V_159 = F_12 ( V_5 , V_19 ) ;
return V_19 -> V_155 . V_159 ? 0 : - V_27 ;
}
static int F_123 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
V_19 -> V_155 . V_188 = F_12 ( V_5 , V_19 ) ;
return V_19 -> V_155 . V_188 ? 0 : - V_27 ;
}
static int F_124 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
T_9 V_131 ;
T_1 V_8 ;
V_8 = F_13 ( V_5 , & V_131 , sizeof( V_131 ) ) ;
if ( V_8 != sizeof( V_131 ) )
return - 1 ;
if ( V_19 -> V_21 )
V_131 = F_98 ( V_131 ) ;
V_19 -> V_155 . V_184 = V_131 ;
return 0 ;
}
static struct V_105 *
F_125 ( struct V_83 * V_84 , int V_152 )
{
struct V_105 * V_106 ;
F_66 (evsel, &evlist->entries, node) {
if ( V_106 -> V_152 == V_152 )
return V_106 ;
}
return NULL ;
}
static void
F_126 ( struct V_83 * V_84 ,
struct V_105 * V_209 )
{
struct V_105 * V_106 ;
if ( ! V_209 -> V_28 )
return;
V_106 = F_125 ( V_84 , V_209 -> V_152 ) ;
if ( ! V_106 )
return;
if ( V_106 -> V_28 )
return;
V_106 -> V_28 = F_127 ( V_209 -> V_28 ) ;
}
static int
F_128 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_2 , int V_5 ,
void * V_208 V_82 )
{
struct V_56 * V_57 ;
struct V_105 * V_106 , * V_169 = F_96 ( V_2 , V_5 ) ;
if ( ! V_169 )
return 0 ;
V_57 = F_25 ( V_2 , struct V_56 , V_2 ) ;
for ( V_106 = V_169 ; V_106 -> V_110 . V_7 ; V_106 ++ )
F_126 ( V_57 -> V_84 , V_106 ) ;
F_95 ( V_169 ) ;
return 0 ;
}
static int F_129 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
T_1 V_8 ;
char * V_16 ;
T_2 V_99 , V_24 ;
struct V_210 V_211 ;
V_8 = F_13 ( V_5 , & V_99 , sizeof( V_99 ) ) ;
if ( V_8 != sizeof( V_99 ) )
return - 1 ;
if ( V_19 -> V_21 )
V_99 = F_14 ( V_99 ) ;
V_19 -> V_155 . V_163 = V_99 ;
F_130 ( & V_211 , 128 ) ;
for ( V_24 = 0 ; V_24 < V_99 ; V_24 ++ ) {
V_16 = F_12 ( V_5 , V_19 ) ;
if ( ! V_16 )
goto error;
F_131 ( & V_211 , V_16 , strlen ( V_16 ) + 1 ) ;
free ( V_16 ) ;
}
V_19 -> V_155 . V_164 = F_132 ( & V_211 , NULL ) ;
return 0 ;
error:
F_133 ( & V_211 ) ;
return - 1 ;
}
static int F_134 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
T_1 V_8 ;
T_2 V_99 , V_24 ;
char * V_16 ;
struct V_210 V_211 ;
V_8 = F_13 ( V_5 , & V_99 , sizeof( V_99 ) ) ;
if ( V_8 != sizeof( V_99 ) )
return - 1 ;
if ( V_19 -> V_21 )
V_99 = F_14 ( V_99 ) ;
V_19 -> V_155 . V_165 = V_99 ;
F_130 ( & V_211 , 128 ) ;
for ( V_24 = 0 ; V_24 < V_99 ; V_24 ++ ) {
V_16 = F_12 ( V_5 , V_19 ) ;
if ( ! V_16 )
goto error;
F_131 ( & V_211 , V_16 , strlen ( V_16 ) + 1 ) ;
free ( V_16 ) ;
}
V_19 -> V_155 . V_166 = F_132 ( & V_211 , NULL ) ;
V_8 = F_13 ( V_5 , & V_99 , sizeof( V_99 ) ) ;
if ( V_8 != sizeof( V_99 ) )
return - 1 ;
if ( V_19 -> V_21 )
V_99 = F_14 ( V_99 ) ;
V_19 -> V_155 . V_167 = V_99 ;
for ( V_24 = 0 ; V_24 < V_99 ; V_24 ++ ) {
V_16 = F_12 ( V_5 , V_19 ) ;
if ( ! V_16 )
goto error;
F_131 ( & V_211 , V_16 , strlen ( V_16 ) + 1 ) ;
free ( V_16 ) ;
}
V_19 -> V_155 . V_168 = F_132 ( & V_211 , NULL ) ;
return 0 ;
error:
F_133 ( & V_211 ) ;
return - 1 ;
}
static int F_135 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
T_1 V_8 ;
T_2 V_99 , V_133 , V_24 ;
char * V_16 ;
T_9 V_135 , V_136 ;
struct V_210 V_211 ;
V_8 = F_13 ( V_5 , & V_99 , sizeof( V_99 ) ) ;
if ( V_8 != sizeof( V_99 ) )
goto error;
if ( V_19 -> V_21 )
V_99 = F_14 ( V_99 ) ;
V_19 -> V_155 . V_186 = V_99 ;
F_130 ( & V_211 , 256 ) ;
for ( V_24 = 0 ; V_24 < V_99 ; V_24 ++ ) {
V_8 = F_13 ( V_5 , & V_133 , sizeof( V_133 ) ) ;
if ( V_8 != sizeof( V_133 ) )
goto error;
V_8 = F_13 ( V_5 , & V_135 , sizeof( V_113 ) ) ;
if ( V_8 != sizeof( V_113 ) )
goto error;
V_8 = F_13 ( V_5 , & V_136 , sizeof( V_113 ) ) ;
if ( V_8 != sizeof( V_113 ) )
goto error;
if ( V_19 -> V_21 ) {
V_133 = F_14 ( V_133 ) ;
V_135 = F_98 ( V_135 ) ;
V_136 = F_98 ( V_136 ) ;
}
F_136 ( & V_211 , L_70 V_132 L_71 V_132 L_72 ,
V_133 , V_135 , V_136 ) ;
V_16 = F_12 ( V_5 , V_19 ) ;
if ( ! V_16 )
goto error;
F_131 ( & V_211 , V_16 , strlen ( V_16 ) + 1 ) ;
free ( V_16 ) ;
}
V_19 -> V_155 . V_187 = F_132 ( & V_211 , NULL ) ;
return 0 ;
error:
F_133 ( & V_211 ) ;
return - 1 ;
}
static int F_137 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
T_1 V_8 ;
char * V_28 ;
T_2 V_146 ;
T_2 type ;
struct V_210 V_211 ;
V_8 = F_13 ( V_5 , & V_146 , sizeof( V_146 ) ) ;
if ( V_8 != sizeof( V_146 ) )
return - 1 ;
if ( V_19 -> V_21 )
V_146 = F_14 ( V_146 ) ;
if ( ! V_146 ) {
F_31 ( L_73 ) ;
return 0 ;
}
V_19 -> V_155 . V_190 = V_146 ;
F_130 ( & V_211 , 128 ) ;
while ( V_146 ) {
if ( F_13 ( V_5 , & type , sizeof( type ) ) != sizeof( type ) )
goto error;
if ( V_19 -> V_21 )
type = F_14 ( type ) ;
V_28 = F_12 ( V_5 , V_19 ) ;
if ( ! V_28 )
goto error;
F_136 ( & V_211 , L_74 , type , V_28 ) ;
F_131 ( & V_211 , L_4 , 1 ) ;
free ( V_28 ) ;
V_146 -- ;
}
V_19 -> V_155 . V_191 = F_132 ( & V_211 , NULL ) ;
return 0 ;
error:
F_133 ( & V_211 ) ;
return - 1 ;
}
static int F_138 ( struct V_207 * T_12 V_82 ,
struct V_1 * V_19 , int V_5 ,
void * V_208 V_82 )
{
T_1 V_8 = - 1 ;
T_2 V_24 , V_99 , V_148 ;
struct V_56 * V_57 ;
struct V_105 * V_106 , * V_212 = NULL ;
struct V_213 {
char * V_28 ;
T_2 V_151 ;
T_2 V_149 ;
} * V_214 ;
if ( F_13 ( V_5 , & V_148 , sizeof( V_148 ) ) != sizeof( V_148 ) )
return - 1 ;
if ( V_19 -> V_21 )
V_148 = F_14 ( V_148 ) ;
V_19 -> V_155 . V_148 = V_148 ;
if ( ! V_148 ) {
F_31 ( L_75 ) ;
return 0 ;
}
V_214 = calloc ( V_148 , sizeof( * V_214 ) ) ;
if ( ! V_214 )
return - 1 ;
for ( V_24 = 0 ; V_24 < V_148 ; V_24 ++ ) {
V_214 [ V_24 ] . V_28 = F_12 ( V_5 , V_19 ) ;
if ( ! V_214 [ V_24 ] . V_28 )
goto V_74;
if ( F_13 ( V_5 , & V_214 [ V_24 ] . V_151 , sizeof( T_2 ) ) != sizeof( T_2 ) )
goto V_74;
if ( F_13 ( V_5 , & V_214 [ V_24 ] . V_149 , sizeof( T_2 ) ) != sizeof( T_2 ) )
goto V_74;
if ( V_19 -> V_21 ) {
V_214 [ V_24 ] . V_151 = F_14 ( V_214 [ V_24 ] . V_151 ) ;
V_214 [ V_24 ] . V_149 = F_14 ( V_214 [ V_24 ] . V_149 ) ;
}
}
V_57 = F_25 ( V_19 , struct V_56 , V_2 ) ;
V_57 -> V_84 -> V_148 = V_148 ;
V_24 = V_99 = 0 ;
F_66 (evsel, &session->evlist->entries, node) {
if ( V_106 -> V_152 == ( int ) V_214 [ V_24 ] . V_151 ) {
V_106 -> V_212 = V_106 ;
if ( strcmp ( V_214 [ V_24 ] . V_28 , L_23 ) ) {
V_106 -> V_150 = V_214 [ V_24 ] . V_28 ;
V_214 [ V_24 ] . V_28 = NULL ;
}
V_106 -> V_149 = V_214 [ V_24 ] . V_149 ;
if ( V_24 >= V_148 || V_99 > 0 ) {
F_31 ( L_76 ) ;
goto V_74;
}
V_212 = V_106 ;
V_99 = V_106 -> V_149 - 1 ;
V_24 ++ ;
} else if ( V_99 ) {
V_106 -> V_212 = V_212 ;
V_99 -- ;
}
}
if ( V_24 != V_148 || V_99 != 0 ) {
F_31 ( L_76 ) ;
goto V_74;
}
V_8 = 0 ;
V_74:
for ( V_24 = 0 ; V_24 < V_148 ; V_24 ++ )
free ( V_214 [ V_24 ] . V_28 ) ;
free ( V_214 ) ;
return V_8 ;
}
static int F_139 ( struct V_207 * T_12 ,
struct V_1 * V_19 ,
int V_3 , int V_5 , void * V_208 )
{
struct V_215 * V_216 = V_208 ;
if ( F_79 ( V_5 , T_12 -> V_144 , V_147 ) == ( T_10 ) - 1 ) {
F_31 ( L_77 V_132 L_78
L_79 , T_12 -> V_144 , V_3 ) ;
return 0 ;
}
if ( V_3 >= V_217 ) {
F_140 ( L_80 , V_3 ) ;
return 0 ;
}
if ( ! V_218 [ V_3 ] . V_219 )
return 0 ;
if ( ! V_218 [ V_3 ] . V_220 || V_216 -> V_221 )
V_218 [ V_3 ] . V_219 ( V_19 , V_5 , V_216 -> V_120 ) ;
else
fprintf ( V_216 -> V_120 , L_81 ,
V_218 [ V_3 ] . V_28 ) ;
return 0 ;
}
int F_141 ( struct V_56 * V_57 , T_8 * V_120 , bool V_221 )
{
struct V_215 V_216 ;
struct V_1 * V_2 = & V_57 -> V_2 ;
int V_5 = F_142 ( V_57 -> V_92 ) ;
V_216 . V_120 = V_120 ;
V_216 . V_221 = V_221 ;
F_143 ( V_2 , V_5 , & V_216 ,
F_139 ) ;
return 0 ;
}
static int F_144 ( int V_5 , struct V_1 * T_7 , int type ,
struct V_207 * * V_94 ,
struct V_83 * V_84 )
{
int V_15 ;
int V_8 = 0 ;
if ( F_5 ( T_7 , type ) ) {
if ( ! V_218 [ type ] . F_8 )
return - 1 ;
( * V_94 ) -> V_144 = F_79 ( V_5 , 0 , V_145 ) ;
V_15 = V_218 [ type ] . F_8 ( V_5 , T_7 , V_84 ) ;
if ( V_15 < 0 ) {
F_31 ( L_82 , type ) ;
F_79 ( V_5 , ( * V_94 ) -> V_144 , V_147 ) ;
return - 1 ;
}
( * V_94 ) -> V_7 = F_79 ( V_5 , 0 , V_145 ) - ( * V_94 ) -> V_144 ;
( * V_94 ) ++ ;
}
return V_8 ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_83 * V_84 , int V_5 )
{
int V_222 ;
struct V_207 * V_223 , * V_94 ;
int V_224 ;
V_113 V_225 ;
int V_3 ;
int V_15 ;
V_222 = F_146 ( V_2 -> V_4 , V_226 ) ;
if ( ! V_222 )
return 0 ;
V_223 = V_94 = calloc ( V_222 , sizeof( * V_223 ) ) ;
if ( V_223 == NULL )
return - V_27 ;
V_224 = sizeof( * V_223 ) * V_222 ;
V_225 = V_2 -> V_227 ;
F_79 ( V_5 , V_225 + V_224 , V_147 ) ;
F_147 (feat, header->adds_features, HEADER_FEAT_BITS) {
if ( F_144 ( V_5 , V_2 , V_3 , & V_94 , V_84 ) )
F_3 ( V_2 , V_3 ) ;
}
F_79 ( V_5 , V_225 , V_147 ) ;
V_15 = F_7 ( V_5 , V_223 , V_224 ) ;
if ( V_15 < 0 )
F_31 ( L_83 ) ;
free ( V_223 ) ;
return V_15 ;
}
int F_148 ( int V_5 )
{
struct V_228 V_229 ;
int V_15 ;
V_229 = (struct V_228 ) {
. V_230 = V_231 ,
. V_7 = sizeof( V_229 ) ,
} ;
V_15 = F_7 ( V_5 , & V_229 , sizeof( V_229 ) ) ;
if ( V_15 < 0 ) {
F_31 ( L_84 ) ;
return V_15 ;
}
return 0 ;
}
int F_149 ( struct V_56 * V_57 ,
struct V_83 * V_84 ,
int V_5 , bool V_232 )
{
struct V_233 V_229 ;
struct V_234 V_235 ;
struct V_1 * V_2 = & V_57 -> V_2 ;
struct V_105 * V_106 ;
V_113 V_236 ;
int V_15 ;
F_79 ( V_5 , sizeof( V_229 ) , V_147 ) ;
F_66 (evsel, &evlist->entries, node) {
V_106 -> V_237 = F_79 ( V_5 , 0 , V_145 ) ;
V_15 = F_7 ( V_5 , V_106 -> V_112 , V_106 -> V_111 * sizeof( V_113 ) ) ;
if ( V_15 < 0 ) {
F_31 ( L_85 ) ;
return V_15 ;
}
}
V_236 = F_79 ( V_5 , 0 , V_145 ) ;
F_66 (evsel, &evlist->entries, node) {
V_235 = (struct V_234 ) {
. V_110 = V_106 -> V_110 ,
. V_111 = {
. V_144 = V_106 -> V_237 ,
. V_7 = V_106 -> V_111 * sizeof( V_113 ) ,
}
} ;
V_15 = F_7 ( V_5 , & V_235 , sizeof( V_235 ) ) ;
if ( V_15 < 0 ) {
F_31 ( L_86 ) ;
return V_15 ;
}
}
V_2 -> V_238 = F_79 ( V_5 , 0 , V_145 ) ;
V_2 -> V_227 = V_2 -> V_238 + V_2 -> V_239 ;
if ( V_232 ) {
V_15 = F_145 ( V_2 , V_84 , V_5 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_229 = (struct V_233 ) {
. V_230 = V_231 ,
. V_7 = sizeof( V_229 ) ,
. V_240 = sizeof( V_235 ) ,
. V_241 = {
. V_144 = V_236 ,
. V_7 = V_84 -> V_109 * sizeof( V_235 ) ,
} ,
. V_208 = {
. V_144 = V_2 -> V_238 ,
. V_7 = V_2 -> V_239 ,
} ,
} ;
memcpy ( & V_229 . V_4 , & V_2 -> V_4 , sizeof( V_2 -> V_4 ) ) ;
F_79 ( V_5 , 0 , V_147 ) ;
V_15 = F_7 ( V_5 , & V_229 , sizeof( V_229 ) ) ;
if ( V_15 < 0 ) {
F_31 ( L_85 ) ;
return V_15 ;
}
F_79 ( V_5 , V_2 -> V_238 + V_2 -> V_239 , V_147 ) ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 ,
int V_5 , void * V_6 , T_1 V_7 )
{
if ( F_13 ( V_5 , V_6 , V_7 ) <= 0 )
return - 1 ;
if ( V_2 -> V_21 )
F_151 ( V_6 , V_7 ) ;
return 0 ;
}
int F_143 ( struct V_1 * V_2 , int V_5 ,
void * V_208 ,
int (* F_152)( struct V_207 * T_12 ,
struct V_1 * V_19 ,
int V_3 , int V_5 , void * V_208 ) )
{
struct V_207 * V_223 , * V_242 ;
int V_222 ;
int V_224 ;
int V_3 ;
int V_15 ;
V_222 = F_146 ( V_2 -> V_4 , V_226 ) ;
if ( ! V_222 )
return 0 ;
V_223 = V_242 = calloc ( V_222 , sizeof( * V_223 ) ) ;
if ( ! V_223 )
return - 1 ;
V_224 = sizeof( * V_223 ) * V_222 ;
F_79 ( V_5 , V_2 -> V_227 , V_147 ) ;
V_15 = F_150 ( V_2 , V_5 , V_223 , V_224 ) ;
if ( V_15 < 0 )
goto V_74;
F_147 (feat, header->adds_features, HEADER_LAST_FEATURE) {
V_15 = F_152 ( V_242 ++ , V_2 , V_3 , V_5 , V_208 ) ;
if ( V_15 < 0 )
goto V_74;
}
V_15 = 0 ;
V_74:
free ( V_223 ) ;
return V_15 ;
}
static int F_153 ( T_9 V_243 , struct V_1 * V_19 )
{
T_9 V_244 , V_240 ;
int V_24 ;
for ( V_24 = 0 ; V_245 [ V_24 ] ; V_24 ++ ) {
V_244 = V_245 [ V_24 ]
+ sizeof( struct V_207 ) ;
if ( V_243 != V_244 ) {
V_240 = F_98 ( V_243 ) ;
if ( V_240 != V_244 )
continue;
V_19 -> V_21 = true ;
}
F_31 ( L_87 ,
V_24 ,
V_19 -> V_21 ) ;
return 0 ;
}
return - 1 ;
}
static int F_154 ( T_9 V_243 , struct V_1 * V_19 )
{
V_113 V_240 ;
int V_24 ;
for ( V_24 = 0 ; V_246 [ V_24 ] ; V_24 ++ ) {
if ( V_243 != V_246 [ V_24 ] ) {
V_240 = F_98 ( V_243 ) ;
if ( V_240 != V_243 )
continue;
V_19 -> V_21 = true ;
}
F_31 ( L_88 , V_24 ) ;
return 0 ;
}
return - 1 ;
}
bool F_155 ( V_113 V_230 )
{
if ( ! memcmp ( & V_230 , V_247 , sizeof( V_230 ) )
|| V_230 == V_248
|| V_230 == V_249 )
return true ;
return false ;
}
static int F_156 ( V_113 V_230 , T_9 V_243 ,
bool V_250 , struct V_1 * V_19 )
{
int V_8 ;
V_8 = memcmp ( & V_230 , V_247 , sizeof( V_230 ) ) ;
if ( V_8 == 0 ) {
V_19 -> V_162 = V_251 ;
F_31 ( L_89 ) ;
if ( V_250 )
return F_154 ( V_243 , V_19 ) ;
return F_153 ( V_243 , V_19 ) ;
}
if ( V_230 == V_248 )
return 0 ;
if ( V_230 != V_249 )
return - 1 ;
V_19 -> V_21 = true ;
V_19 -> V_162 = V_252 ;
return 0 ;
}
int F_157 ( struct V_233 * V_2 ,
struct V_1 * V_19 , int V_5 )
{
int V_8 ;
F_79 ( V_5 , 0 , V_147 ) ;
V_8 = F_13 ( V_5 , V_2 , sizeof( * V_2 ) ) ;
if ( V_8 <= 0 )
return - 1 ;
if ( F_156 ( V_2 -> V_230 ,
V_2 -> V_240 , false , V_19 ) < 0 ) {
F_31 ( L_90 ) ;
return - 1 ;
}
if ( V_19 -> V_21 ) {
F_151 ( V_2 , F_158 ( struct V_233 ,
V_4 ) ) ;
}
if ( V_2 -> V_7 != sizeof( * V_2 ) ) {
if ( V_2 -> V_7 == F_158 ( F_159 ( * V_2 ) , V_4 ) )
F_160 ( V_2 -> V_4 , V_226 ) ;
else
return - 1 ;
} else if ( V_19 -> V_21 ) {
F_151 ( & V_2 -> V_4 ,
F_161 ( V_226 ) ) ;
if ( ! F_6 ( V_253 , V_2 -> V_4 ) ) {
F_151 ( & V_2 -> V_4 ,
F_161 ( V_226 ) ) ;
F_162 ( & V_2 -> V_4 ,
F_163 ( V_226 ) ) ;
}
if ( ! F_6 ( V_253 , V_2 -> V_4 ) ) {
F_160 ( V_2 -> V_4 , V_226 ) ;
F_2 ( V_254 , V_2 -> V_4 ) ;
}
}
memcpy ( & V_19 -> V_4 , & V_2 -> V_4 ,
sizeof( V_19 -> V_4 ) ) ;
V_19 -> V_238 = V_2 -> V_208 . V_144 ;
V_19 -> V_239 = V_2 -> V_208 . V_7 ;
V_19 -> V_227 = V_2 -> V_208 . V_144 + V_2 -> V_208 . V_7 ;
return 0 ;
}
static int F_164 ( struct V_207 * T_12 ,
struct V_1 * V_19 ,
int V_3 , int V_5 , void * V_208 )
{
if ( F_79 ( V_5 , T_12 -> V_144 , V_147 ) == ( T_10 ) - 1 ) {
F_31 ( L_77 V_132 L_78
L_79 , T_12 -> V_144 , V_3 ) ;
return 0 ;
}
if ( V_3 >= V_217 ) {
F_31 ( L_91 , V_3 ) ;
return 0 ;
}
if ( ! V_218 [ V_3 ] . F_152 )
return 0 ;
return V_218 [ V_3 ] . F_152 ( T_12 , V_19 , V_5 , V_208 ) ;
}
static int F_165 ( struct V_228 * V_2 ,
struct V_1 * V_19 , int V_5 ,
bool V_255 )
{
int V_8 ;
V_8 = F_13 ( V_5 , V_2 , sizeof( * V_2 ) ) ;
if ( V_8 <= 0 )
return - 1 ;
if ( F_156 ( V_2 -> V_230 , V_2 -> V_7 , true , V_19 ) < 0 ) {
F_31 ( L_92 ) ;
return - 1 ;
}
if ( V_19 -> V_21 )
V_2 -> V_7 = F_98 ( V_2 -> V_7 ) ;
if ( V_255 && F_7 ( V_256 , V_2 , sizeof( * V_2 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int F_166 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = & V_57 -> V_2 ;
struct V_228 V_229 ;
if ( F_165 ( & V_229 , V_2 ,
F_142 ( V_57 -> V_92 ) ,
V_57 -> V_255 ) < 0 ) {
F_31 ( L_93 ) ;
return - V_257 ;
}
return 0 ;
}
static int F_167 ( int V_5 , struct V_1 * V_19 ,
struct V_234 * V_235 )
{
struct V_258 * V_110 = & V_235 -> V_110 ;
T_1 V_20 , V_259 ;
T_1 V_260 = sizeof( V_235 -> V_110 ) ;
int V_8 ;
memset ( V_235 , 0 , sizeof( * V_235 ) ) ;
V_8 = F_13 ( V_5 , V_110 , V_261 ) ;
if ( V_8 <= 0 ) {
F_31 ( L_94 ,
V_261 ) ;
return - 1 ;
}
V_20 = V_110 -> V_7 ;
if ( V_19 -> V_21 )
V_20 = F_14 ( V_20 ) ;
if ( V_20 == 0 ) {
V_20 = V_261 ;
} else if ( V_20 > V_260 ) {
F_31 ( L_95
L_96 , V_20 - V_260 ) ;
return - 1 ;
}
V_259 = V_20 - V_261 ;
if ( V_259 ) {
void * V_262 = V_110 ;
V_262 += V_261 ;
V_8 = F_13 ( V_5 , V_262 , V_259 ) ;
}
V_8 = F_13 ( V_5 , & V_235 -> V_111 , sizeof( V_235 -> V_111 ) ) ;
return V_8 <= 0 ? - 1 : 0 ;
}
static int F_168 ( struct V_105 * V_106 ,
struct V_263 * V_263 )
{
struct V_264 * V_209 ;
char V_10 [ 128 ] ;
if ( V_106 -> V_265 )
return 0 ;
if ( V_263 == NULL ) {
F_31 ( L_97 ) ;
return - 1 ;
}
V_209 = F_169 ( V_263 , V_106 -> V_110 . V_173 ) ;
if ( V_209 == NULL )
return - 1 ;
if ( ! V_106 -> V_28 ) {
snprintf ( V_10 , sizeof( V_10 ) , L_98 , V_209 -> system , V_209 -> V_28 ) ;
V_106 -> V_28 = F_127 ( V_10 ) ;
if ( V_106 -> V_28 == NULL )
return - 1 ;
}
V_106 -> V_265 = V_209 ;
return 0 ;
}
static int F_170 ( struct V_83 * V_84 ,
struct V_263 * V_263 )
{
struct V_105 * V_42 ;
F_66 (pos, &evlist->entries, node) {
if ( V_42 -> V_110 . type == V_266 &&
F_168 ( V_42 , V_263 ) )
return - 1 ;
}
return 0 ;
}
int F_171 ( struct V_56 * V_57 )
{
struct V_267 * V_92 = V_57 -> V_92 ;
struct V_1 * V_2 = & V_57 -> V_2 ;
struct V_233 V_229 ;
struct V_234 V_235 ;
V_113 V_268 ;
int V_269 , V_270 , V_24 , V_140 ;
int V_5 = F_142 ( V_92 ) ;
V_57 -> V_84 = F_172 () ;
if ( V_57 -> V_84 == NULL )
return - V_27 ;
if ( F_173 ( V_92 ) )
return F_166 ( V_57 ) ;
if ( F_157 ( & V_229 , V_2 , V_5 ) < 0 )
return - V_257 ;
if ( V_229 . V_208 . V_7 == 0 ) {
F_140 ( L_99
L_100 ,
V_92 -> V_271 ) ;
}
V_269 = V_229 . V_241 . V_7 / V_229 . V_240 ;
F_79 ( V_5 , V_229 . V_241 . V_144 , V_147 ) ;
for ( V_24 = 0 ; V_24 < V_269 ; V_24 ++ ) {
struct V_105 * V_106 ;
T_10 V_185 ;
if ( F_167 ( V_5 , V_2 , & V_235 ) < 0 )
goto V_272;
if ( V_2 -> V_21 )
F_97 ( & V_235 . V_110 ) ;
V_185 = F_79 ( V_5 , 0 , V_145 ) ;
V_106 = F_174 ( & V_235 . V_110 ) ;
if ( V_106 == NULL )
goto V_273;
V_106 -> V_21 = V_2 -> V_21 ;
F_175 ( V_57 -> V_84 , V_106 ) ;
V_270 = V_235 . V_111 . V_7 / sizeof( V_113 ) ;
if ( F_176 ( V_106 , 1 , V_270 ) )
goto V_273;
F_79 ( V_5 , V_235 . V_111 . V_144 , V_147 ) ;
for ( V_140 = 0 ; V_140 < V_270 ; V_140 ++ ) {
if ( F_150 ( V_2 , V_5 , & V_268 , sizeof( V_268 ) ) )
goto V_272;
F_177 ( V_57 -> V_84 , V_106 , 0 , V_140 , V_268 ) ;
}
F_79 ( V_5 , V_185 , V_147 ) ;
}
V_72 . V_274 = V_269 ;
F_143 ( V_2 , V_5 , & V_57 -> V_263 ,
F_164 ) ;
if ( F_170 ( V_57 -> V_84 ,
V_57 -> V_263 ) )
goto V_273;
return 0 ;
V_272:
return - V_9 ;
V_273:
F_178 ( V_57 -> V_84 ) ;
V_57 -> V_84 = NULL ;
return - V_27 ;
}
int F_179 ( struct V_275 * V_276 ,
struct V_258 * V_110 , T_2 V_111 , V_113 * V_112 ,
T_13 F_152 )
{
union V_277 * V_278 ;
T_1 V_7 ;
int V_15 ;
V_7 = sizeof( struct V_258 ) ;
V_7 = F_11 ( V_7 , sizeof( V_113 ) ) ;
V_7 += sizeof( struct V_201 ) ;
V_7 += V_111 * sizeof( V_113 ) ;
V_278 = malloc ( V_7 ) ;
if ( V_278 == NULL )
return - V_27 ;
V_278 -> V_110 . V_110 = * V_110 ;
memcpy ( V_278 -> V_110 . V_112 , V_112 , V_111 * sizeof( V_113 ) ) ;
V_278 -> V_110 . V_2 . type = V_279 ;
V_278 -> V_110 . V_2 . V_7 = ( T_6 ) V_7 ;
if ( V_278 -> V_110 . V_2 . V_7 == V_7 )
V_15 = F_152 ( V_276 , V_278 , NULL , NULL ) ;
else
V_15 = - V_280 ;
free ( V_278 ) ;
return V_15 ;
}
int F_180 ( struct V_275 * V_276 ,
struct V_56 * V_57 ,
T_13 F_152 )
{
struct V_105 * V_106 ;
int V_15 = 0 ;
F_66 (evsel, &session->evlist->entries, node) {
V_15 = F_179 ( V_276 , & V_106 -> V_110 , V_106 -> V_111 ,
V_106 -> V_112 , F_152 ) ;
if ( V_15 ) {
F_31 ( L_101 ) ;
return V_15 ;
}
}
return V_15 ;
}
int F_181 ( struct V_275 * V_276 V_82 ,
union V_277 * V_209 ,
struct V_83 * * V_281 )
{
T_2 V_24 , V_111 , V_282 ;
struct V_105 * V_106 ;
struct V_83 * V_84 = * V_281 ;
if ( V_84 == NULL ) {
* V_281 = V_84 = F_172 () ;
if ( V_84 == NULL )
return - V_27 ;
}
V_106 = F_174 ( & V_209 -> V_110 . V_110 ) ;
if ( V_106 == NULL )
return - V_27 ;
F_175 ( V_84 , V_106 ) ;
V_111 = V_209 -> V_2 . V_7 ;
V_111 -= ( void * ) & V_209 -> V_110 . V_112 - ( void * ) V_209 ;
V_282 = V_111 / sizeof( V_113 ) ;
if ( F_176 ( V_106 , 1 , V_282 ) )
return - V_27 ;
for ( V_24 = 0 ; V_24 < V_282 ; V_24 ++ ) {
F_177 ( V_84 , V_106 , 0 , V_24 , V_209 -> V_110 . V_112 [ V_24 ] ) ;
}
V_72 . V_274 = V_84 -> V_109 ;
return 0 ;
}
int F_182 ( struct V_275 * V_276 , int V_5 ,
struct V_83 * V_84 ,
T_13 F_152 )
{
union V_277 V_278 ;
struct V_283 * V_284 ;
T_3 V_7 = 0 , V_285 = 0 , V_286 ;
int V_15 V_82 = 0 ;
V_284 = F_183 ( & V_84 -> V_85 , V_5 , true ) ;
if ( ! V_284 )
return - 1 ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_278 . V_283 . V_2 . type = V_287 ;
V_7 = V_284 -> V_7 ;
V_285 = F_11 ( V_7 , sizeof( V_113 ) ) ;
V_286 = V_285 - V_7 ;
V_278 . V_283 . V_2 . V_7 = sizeof( V_278 . V_283 ) ;
V_278 . V_283 . V_7 = V_285 ;
F_152 ( V_276 , & V_278 , NULL , NULL ) ;
F_184 ( V_284 ) ;
F_9 ( V_5 , NULL , 0 , V_286 ) ;
return V_285 ;
}
int F_185 ( struct V_275 * V_276 V_82 ,
union V_277 * V_209 ,
struct V_56 * V_57 )
{
T_3 V_288 , V_286 , V_7 = V_209 -> V_283 . V_7 ;
int V_5 = F_142 ( V_57 -> V_92 ) ;
T_10 V_144 = F_79 ( V_5 , 0 , V_145 ) ;
char V_6 [ V_289 ] ;
F_79 ( V_5 , V_144 + sizeof( struct V_290 ) ,
V_147 ) ;
V_288 = F_115 ( V_5 , & V_57 -> V_263 ,
V_57 -> V_255 ) ;
V_286 = F_11 ( V_288 , sizeof( V_113 ) ) - V_288 ;
if ( F_13 ( V_5 , V_6 , V_286 ) < 0 ) {
F_186 ( L_102 , V_291 ) ;
return - 1 ;
}
if ( V_57 -> V_255 ) {
int V_292 = F_8 ( V_256 , V_6 , V_286 ) ;
if ( V_292 <= 0 || V_292 != V_286 ) {
F_186 ( L_103 , V_291 ) ;
return - 1 ;
}
}
if ( V_288 + V_286 != V_7 ) {
F_186 ( L_104 , V_291 ) ;
return - 1 ;
}
F_170 ( V_57 -> V_84 ,
V_57 -> V_263 ) ;
return V_288 + V_286 ;
}
int F_187 ( struct V_275 * V_276 ,
struct V_41 * V_42 , T_6 V_32 ,
T_13 F_152 ,
struct V_38 * V_38 )
{
union V_277 V_278 ;
T_1 V_17 ;
int V_15 = 0 ;
if ( ! V_42 -> V_43 )
return V_15 ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_17 = V_42 -> V_47 + 1 ;
V_17 = F_11 ( V_17 , V_14 ) ;
memcpy ( & V_278 . V_30 . V_30 , V_42 -> V_30 , sizeof( V_42 -> V_30 ) ) ;
V_278 . V_30 . V_2 . type = V_293 ;
V_278 . V_30 . V_2 . V_32 = V_32 ;
V_278 . V_30 . V_31 = V_38 -> V_31 ;
V_278 . V_30 . V_2 . V_7 = sizeof( V_278 . V_30 ) + V_17 ;
memcpy ( & V_278 . V_30 . V_68 , V_42 -> V_46 , V_42 -> V_47 ) ;
V_15 = F_152 ( V_276 , & V_278 , NULL , V_38 ) ;
return V_15 ;
}
int F_188 ( struct V_275 * V_276 V_82 ,
union V_277 * V_209 ,
struct V_56 * V_57 )
{
F_107 ( & V_209 -> V_30 ,
V_209 -> V_30 . V_68 ,
V_57 ) ;
return 0 ;
}
void F_189 ( void )
{
V_86 = true ;
}
