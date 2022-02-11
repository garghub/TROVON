static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
V_3 = F_2 ( V_4 ) ;
if ( V_3 < 0 )
return NULL ;
V_2 = malloc ( sizeof( * V_2 ) + V_3 * sizeof( int ) ) ;
if ( V_2 != NULL ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; ++ V_5 )
V_2 -> V_6 [ V_5 ] = V_5 ;
V_2 -> V_7 = V_3 ;
F_3 ( & V_2 -> V_8 , 1 ) ;
}
return V_2 ;
}
static struct V_1 * F_4 ( int V_3 , int * V_9 )
{
T_1 V_10 = V_3 * sizeof( int ) ;
struct V_1 * V_2 = malloc ( sizeof( * V_2 ) + V_10 ) ;
if ( V_2 != NULL ) {
V_2 -> V_7 = V_3 ;
memcpy ( V_2 -> V_6 , V_9 , V_10 ) ;
F_3 ( & V_2 -> V_8 , 1 ) ;
}
return V_2 ;
}
struct V_1 * F_5 ( T_2 * V_11 )
{
struct V_1 * V_2 = NULL ;
int V_3 = 0 ;
int * V_9 = NULL , * V_12 ;
int V_13 = 0 ;
int V_14 , V_15 , V_16 ;
char V_17 ;
V_17 = 0 ;
V_16 = - 1 ;
for (; ; ) {
V_14 = fscanf ( V_11 , L_1 , & V_15 , & V_17 ) ;
if ( V_14 <= 0 )
break;
if ( V_16 >= 0 ) {
int V_18 = V_3 + V_15 - V_16 - 1 ;
if ( V_18 >= V_13 ) {
V_13 = V_18 + V_19 / 2 ;
V_12 = realloc ( V_9 , V_13 * sizeof( int ) ) ;
if ( V_12 == NULL )
goto V_20;
V_9 = V_12 ;
}
while ( ++ V_16 < V_15 )
V_9 [ V_3 ++ ] = V_16 ;
}
if ( V_3 == V_13 ) {
V_13 += V_19 ;
V_12 = realloc ( V_9 , V_13 * sizeof( int ) ) ;
if ( V_12 == NULL )
goto V_20;
V_9 = V_12 ;
}
V_9 [ V_3 ++ ] = V_15 ;
if ( V_14 == 2 && V_17 == '-' )
V_16 = V_15 ;
else
V_16 = - 1 ;
if ( V_14 == 1 || V_17 == '\n' )
break;
}
if ( V_3 > 0 )
V_2 = F_4 ( V_3 , V_9 ) ;
else
V_2 = F_1 () ;
V_20:
free ( V_9 ) ;
return V_2 ;
}
static struct V_1 * F_6 ( void )
{
struct V_1 * V_2 = NULL ;
T_2 * V_21 ;
V_21 = fopen ( L_2 , L_3 ) ;
if ( ! V_21 )
return F_1 () ;
V_2 = F_5 ( V_21 ) ;
fclose ( V_21 ) ;
return V_2 ;
}
struct V_1 * F_7 ( const char * V_22 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_23 , V_24 = 0 ;
char * V_25 = NULL ;
int V_5 , V_3 = 0 ;
int * V_9 = NULL , * V_12 ;
int V_13 = 0 ;
if ( ! V_22 )
return F_6 () ;
if ( ! isdigit ( * V_22 ) )
goto V_26;
while ( isdigit ( * V_22 ) ) {
V_25 = NULL ;
V_23 = strtoul ( V_22 , & V_25 , 0 ) ;
if ( V_23 >= V_27
|| ( * V_25 != '\0' && * V_25 != ',' && * V_25 != '-' ) )
goto V_28;
if ( * V_25 == '-' ) {
V_22 = ++ V_25 ;
V_25 = NULL ;
V_24 = strtoul ( V_22 , & V_25 , 0 ) ;
if ( V_24 >= V_27 || ( * V_25 != '\0' && * V_25 != ',' ) )
goto V_28;
if ( V_24 < V_23 )
goto V_28;
} else {
V_24 = V_23 ;
}
for (; V_23 <= V_24 ; V_23 ++ ) {
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
if ( V_9 [ V_5 ] == ( int ) V_23 )
goto V_28;
if ( V_3 == V_13 ) {
V_13 += V_19 ;
V_12 = realloc ( V_9 , V_13 * sizeof( int ) ) ;
if ( V_12 == NULL )
goto V_28;
V_9 = V_12 ;
}
V_9 [ V_3 ++ ] = ( int ) V_23 ;
}
if ( * V_25 )
++ V_25 ;
V_22 = V_25 ;
}
if ( V_3 > 0 )
V_2 = F_4 ( V_3 , V_9 ) ;
else
V_2 = F_1 () ;
V_28:
free ( V_9 ) ;
V_26:
return V_2 ;
}
static struct V_1 * F_8 ( struct V_29 * V_2 )
{
struct V_1 * V_6 ;
V_6 = F_9 ( V_2 -> V_7 ) ;
if ( V_6 ) {
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_7 ; V_5 ++ ) {
if ( V_2 -> V_15 [ V_5 ] == ( V_30 ) - 1 )
V_6 -> V_6 [ V_5 ] = - 1 ;
else
V_6 -> V_6 [ V_5 ] = ( int ) V_2 -> V_15 [ V_5 ] ;
}
}
return V_6 ;
}
static struct V_1 * F_10 ( struct V_31 * V_32 )
{
struct V_1 * V_6 ;
int V_7 , V_33 = V_32 -> V_7 * V_32 -> V_34 * V_35 ;
V_7 = F_11 ( V_32 -> V_32 , V_33 ) ;
V_6 = F_9 ( V_7 ) ;
if ( V_6 ) {
int V_15 , V_5 = 0 ;
F_12 (cpu, mask->mask, nbits)
V_6 -> V_6 [ V_5 ++ ] = V_15 ;
}
return V_6 ;
}
struct V_1 * F_13 ( struct V_36 * V_37 )
{
if ( V_37 -> type == V_38 )
return F_8 ( (struct V_29 * ) V_37 -> V_37 ) ;
else
return F_10 ( (struct V_31 * ) V_37 -> V_37 ) ;
}
T_1 F_14 ( struct V_1 * V_6 , T_2 * V_39 )
{
int V_5 ;
T_1 V_40 = fprintf ( V_39 , L_4 ,
V_6 -> V_7 , V_6 -> V_7 > 1 ? L_5 : L_6 ) ;
for ( V_5 = 0 ; V_5 < V_6 -> V_7 ; ++ V_5 )
V_40 += fprintf ( V_39 , L_7 , V_5 ? L_8 : L_6 , V_6 -> V_6 [ V_5 ] ) ;
return V_40 + fprintf ( V_39 , L_9 ) ;
}
struct V_1 * F_15 ( void )
{
struct V_1 * V_2 = malloc ( sizeof( * V_2 ) + sizeof( int ) ) ;
if ( V_2 != NULL ) {
V_2 -> V_7 = 1 ;
V_2 -> V_6 [ 0 ] = - 1 ;
F_3 ( & V_2 -> V_8 , 1 ) ;
}
return V_2 ;
}
struct V_1 * F_9 ( int V_7 )
{
struct V_1 * V_2 = malloc ( sizeof( * V_2 ) + sizeof( int ) * V_7 ) ;
if ( V_2 != NULL ) {
int V_5 ;
V_2 -> V_7 = V_7 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
V_2 -> V_6 [ V_5 ] = - 1 ;
F_3 ( & V_2 -> V_8 , 1 ) ;
}
return V_2 ;
}
static void F_16 ( struct V_1 * V_6 )
{
if ( V_6 ) {
F_17 ( F_18 ( & V_6 -> V_8 ) != 0 ,
L_10 ) ;
free ( V_6 ) ;
}
}
struct V_1 * F_19 ( struct V_1 * V_6 )
{
if ( V_6 )
F_20 ( & V_6 -> V_8 ) ;
return V_6 ;
}
void F_21 ( struct V_1 * V_6 )
{
if ( V_6 && F_22 ( & V_6 -> V_8 ) )
F_16 ( V_6 ) ;
}
static int F_23 ( int V_15 , const char * V_41 , int * V_42 )
{
char V_43 [ V_44 ] ;
snprintf ( V_43 , V_44 ,
L_11 , V_15 , V_41 ) ;
return F_24 ( V_43 , V_42 ) ;
}
int F_25 ( int V_15 )
{
int V_42 , V_45 = F_23 ( V_15 , L_12 , & V_42 ) ;
return V_45 ? : V_42 ;
}
int F_26 ( struct V_1 * V_6 , int V_46 , void * V_37 V_47 )
{
int V_15 ;
if ( V_46 > V_6 -> V_7 )
return - 1 ;
V_15 = V_6 -> V_6 [ V_46 ] ;
return F_25 ( V_15 ) ;
}
static int F_27 ( const void * V_48 , const void * V_49 )
{
return * ( int * ) V_48 - * ( int * ) V_49 ;
}
int F_28 ( struct V_1 * V_2 , struct V_1 * * V_50 ,
int (* F_29)( struct V_1 * V_6 , int V_15 , void * V_37 ) ,
void * V_37 )
{
struct V_1 * V_51 ;
int V_7 = V_2 -> V_7 ;
int V_15 , V_52 , V_53 ;
V_51 = calloc ( 1 , sizeof( * V_51 ) + V_7 * sizeof( int ) ) ;
if ( ! V_51 )
return - 1 ;
for ( V_15 = 0 ; V_15 < V_7 ; V_15 ++ ) {
V_52 = F_29 ( V_2 , V_15 , V_37 ) ;
for ( V_53 = 0 ; V_53 < V_51 -> V_7 ; V_53 ++ ) {
if ( V_52 == V_51 -> V_6 [ V_53 ] )
break;
}
if ( V_53 == V_51 -> V_7 ) {
V_51 -> V_6 [ V_51 -> V_7 ] = V_52 ;
V_51 -> V_7 ++ ;
}
}
qsort ( V_51 -> V_6 , V_51 -> V_7 , sizeof( int ) , F_27 ) ;
F_3 ( & V_51 -> V_8 , 1 ) ;
* V_50 = V_51 ;
return 0 ;
}
int F_30 ( int V_15 )
{
int V_42 , V_45 = F_23 ( V_15 , L_13 , & V_42 ) ;
return V_45 ? : V_42 ;
}
int F_31 ( struct V_1 * V_6 , int V_46 , void * V_37 )
{
int V_15 , V_54 ;
if ( V_46 > V_6 -> V_7 )
return - 1 ;
V_15 = V_6 -> V_6 [ V_46 ] ;
V_15 = F_30 ( V_15 ) ;
V_54 = F_26 ( V_6 , V_46 , V_37 ) ;
if ( V_54 == - 1 )
return - 1 ;
return ( V_54 << 16 ) | ( V_15 & 0xffff ) ;
}
int F_32 ( struct V_1 * V_2 , struct V_1 * * V_55 )
{
return F_28 ( V_2 , V_55 , F_26 , NULL ) ;
}
int F_33 ( struct V_1 * V_2 , struct V_1 * * V_56 )
{
return F_28 ( V_2 , V_56 , F_31 , NULL ) ;
}
static int F_34 ( char * V_43 , int * V_57 )
{
T_1 V_58 ;
char * V_59 ;
int V_60 = 0 ;
if ( F_35 ( V_43 , & V_59 , & V_58 ) )
return - 1 ;
V_59 [ V_58 ] = '\0' ;
while ( -- V_58 ) {
if ( ( V_59 [ V_58 ] == ',' ) || ( V_59 [ V_58 ] == '-' ) ) {
V_58 ++ ;
break;
}
}
if ( sscanf ( & V_59 [ V_58 ] , L_14 , V_57 ) < 1 ) {
V_60 = - 1 ;
goto V_26;
}
( * V_57 ) ++ ;
V_26:
free ( V_59 ) ;
return V_60 ;
}
static void F_36 ( void )
{
const char * V_61 ;
char V_43 [ V_44 ] ;
int V_45 = - 1 ;
V_62 = 4096 ;
V_61 = F_37 () ;
if ( ! V_61 )
goto V_26;
V_45 = snprintf ( V_43 , V_44 , L_15 , V_61 ) ;
if ( V_45 == V_44 ) {
F_38 ( L_16 , V_44 ) ;
goto V_26;
}
V_45 = F_34 ( V_43 , & V_62 ) ;
V_26:
if ( V_45 )
F_38 ( L_17 , V_62 ) ;
}
static void F_39 ( void )
{
const char * V_61 ;
char V_43 [ V_44 ] ;
int V_45 = - 1 ;
V_63 = 8 ;
V_61 = F_37 () ;
if ( ! V_61 )
goto V_26;
V_45 = snprintf ( V_43 , V_44 , L_18 , V_61 ) ;
if ( V_45 == V_44 ) {
F_38 ( L_16 , V_44 ) ;
goto V_26;
}
V_45 = F_34 ( V_43 , & V_63 ) ;
V_26:
if ( V_45 )
F_38 ( L_19 , V_63 ) ;
}
int F_40 ( void )
{
if ( F_41 ( ! V_63 ) )
F_39 () ;
return V_63 ;
}
int F_42 ( void )
{
if ( F_41 ( ! V_62 ) )
F_36 () ;
return V_62 ;
}
int F_43 ( int V_15 )
{
if ( F_41 ( V_64 == NULL ) ) {
F_44 ( L_20 ) ;
return - 1 ;
}
return V_64 [ V_15 ] ;
}
static int F_45 ( void )
{
int V_5 ;
F_36 () ;
F_39 () ;
V_64 = calloc ( V_62 , sizeof( int ) ) ;
if ( ! V_64 ) {
F_38 ( L_21 , V_65 ) ;
return - 1 ;
}
for ( V_5 = 0 ; V_5 < V_62 ; V_5 ++ )
V_64 [ V_5 ] = - 1 ;
return 0 ;
}
int F_46 ( void )
{
struct V_66 * V_67 , * V_68 ;
T_3 * V_69 , * V_70 ;
unsigned int V_15 , V_71 ;
char V_59 [ V_44 ] ;
char V_43 [ V_44 ] ;
const char * V_61 ;
int V_14 ;
if ( F_45 () )
return - 1 ;
V_61 = F_37 () ;
if ( ! V_61 )
return 0 ;
V_14 = snprintf ( V_43 , V_44 , L_22 , V_61 ) ;
if ( V_14 == V_44 ) {
F_38 ( L_16 , V_44 ) ;
return - 1 ;
}
V_69 = F_47 ( V_43 ) ;
if ( ! V_69 )
return 0 ;
while ( ( V_67 = F_48 ( V_69 ) ) != NULL ) {
if ( V_67 -> V_72 != V_73 || sscanf ( V_67 -> V_74 , L_23 , & V_71 ) < 1 )
continue;
V_14 = snprintf ( V_59 , V_44 , L_24 , V_43 , V_67 -> V_74 ) ;
if ( V_14 == V_44 ) {
F_38 ( L_16 , V_44 ) ;
continue;
}
V_70 = F_47 ( V_59 ) ;
if ( ! V_70 )
continue;
while ( ( V_68 = F_48 ( V_70 ) ) != NULL ) {
if ( V_68 -> V_72 != V_75 || sscanf ( V_68 -> V_74 , L_25 , & V_15 ) < 1 )
continue;
V_64 [ V_15 ] = V_71 ;
}
F_49 ( V_70 ) ;
}
F_49 ( V_69 ) ;
return 0 ;
}
bool F_50 ( struct V_1 * V_2 , int V_15 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_7 ; ++ V_5 ) {
if ( V_2 -> V_6 [ V_5 ] == V_15 )
return true ;
}
return false ;
}
