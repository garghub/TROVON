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
}
return V_2 ;
}
static struct V_1 * F_3 ( int V_3 , int * V_8 )
{
T_1 V_9 = V_3 * sizeof( int ) ;
struct V_1 * V_2 = malloc ( sizeof( * V_2 ) + V_9 ) ;
if ( V_2 != NULL ) {
V_2 -> V_7 = V_3 ;
memcpy ( V_2 -> V_6 , V_8 , V_9 ) ;
}
return V_2 ;
}
struct V_1 * F_4 ( T_2 * V_10 )
{
struct V_1 * V_2 = NULL ;
int V_3 = 0 ;
int * V_8 = NULL , * V_11 ;
int V_12 = 0 ;
int V_13 , V_14 , V_15 ;
char V_16 ;
V_16 = 0 ;
V_15 = - 1 ;
for (; ; ) {
V_13 = fscanf ( V_10 , L_1 , & V_14 , & V_16 ) ;
if ( V_13 <= 0 )
break;
if ( V_15 >= 0 ) {
int V_17 = V_3 + V_14 - V_15 - 1 ;
if ( V_17 >= V_12 ) {
V_12 = V_17 + V_18 / 2 ;
V_11 = realloc ( V_8 , V_12 * sizeof( int ) ) ;
if ( V_11 == NULL )
goto V_19;
V_8 = V_11 ;
}
while ( ++ V_15 < V_14 )
V_8 [ V_3 ++ ] = V_15 ;
}
if ( V_3 == V_12 ) {
V_12 += V_18 ;
V_11 = realloc ( V_8 , V_12 * sizeof( int ) ) ;
if ( V_11 == NULL )
goto V_19;
V_8 = V_11 ;
}
V_8 [ V_3 ++ ] = V_14 ;
if ( V_13 == 2 && V_16 == '-' )
V_15 = V_14 ;
else
V_15 = - 1 ;
if ( V_13 == 1 || V_16 == '\n' )
break;
}
if ( V_3 > 0 )
V_2 = F_3 ( V_3 , V_8 ) ;
else
V_2 = F_1 () ;
V_19:
free ( V_8 ) ;
return V_2 ;
}
static struct V_1 * F_5 ( void )
{
struct V_1 * V_2 = NULL ;
T_2 * V_20 ;
V_20 = fopen ( L_2 , L_3 ) ;
if ( ! V_20 )
return F_1 () ;
V_2 = F_4 ( V_20 ) ;
fclose ( V_20 ) ;
return V_2 ;
}
struct V_1 * F_6 ( const char * V_21 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_22 , V_23 = 0 ;
char * V_24 = NULL ;
int V_5 , V_3 = 0 ;
int * V_8 = NULL , * V_11 ;
int V_12 = 0 ;
if ( ! V_21 )
return F_5 () ;
if ( ! isdigit ( * V_21 ) )
goto V_25;
while ( isdigit ( * V_21 ) ) {
V_24 = NULL ;
V_22 = strtoul ( V_21 , & V_24 , 0 ) ;
if ( V_22 >= V_26
|| ( * V_24 != '\0' && * V_24 != ',' && * V_24 != '-' ) )
goto V_27;
if ( * V_24 == '-' ) {
V_21 = ++ V_24 ;
V_24 = NULL ;
V_23 = strtoul ( V_21 , & V_24 , 0 ) ;
if ( V_23 >= V_26 || ( * V_24 != '\0' && * V_24 != ',' ) )
goto V_27;
if ( V_23 < V_22 )
goto V_27;
} else {
V_23 = V_22 ;
}
for (; V_22 <= V_23 ; V_22 ++ ) {
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
if ( V_8 [ V_5 ] == ( int ) V_22 )
goto V_27;
if ( V_3 == V_12 ) {
V_12 += V_18 ;
V_11 = realloc ( V_8 , V_12 * sizeof( int ) ) ;
if ( V_11 == NULL )
goto V_27;
V_8 = V_11 ;
}
V_8 [ V_3 ++ ] = ( int ) V_22 ;
}
if ( * V_24 )
++ V_24 ;
V_21 = V_24 ;
}
if ( V_3 > 0 )
V_2 = F_3 ( V_3 , V_8 ) ;
else
V_2 = F_1 () ;
V_27:
free ( V_8 ) ;
V_25:
return V_2 ;
}
T_1 F_7 ( struct V_1 * V_6 , T_2 * V_28 )
{
int V_5 ;
T_1 V_29 = fprintf ( V_28 , L_4 ,
V_6 -> V_7 , V_6 -> V_7 > 1 ? L_5 : L_6 ) ;
for ( V_5 = 0 ; V_5 < V_6 -> V_7 ; ++ V_5 )
V_29 += fprintf ( V_28 , L_7 , V_5 ? L_8 : L_6 , V_6 -> V_6 [ V_5 ] ) ;
return V_29 + fprintf ( V_28 , L_9 ) ;
}
struct V_1 * F_8 ( void )
{
struct V_1 * V_2 = malloc ( sizeof( * V_2 ) + sizeof( int ) ) ;
if ( V_2 != NULL ) {
V_2 -> V_7 = 1 ;
V_2 -> V_6 [ 0 ] = - 1 ;
}
return V_2 ;
}
void F_9 ( struct V_1 * V_6 )
{
free ( V_6 ) ;
}
