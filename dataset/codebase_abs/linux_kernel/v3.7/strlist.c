static
struct V_1 * F_1 ( struct V_2 * V_2 , const void * V_3 )
{
const char * V_4 = V_3 ;
struct V_1 * V_5 = NULL ;
struct V_6 * V_6 = F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_7 * V_8 = malloc ( sizeof( * V_8 ) ) ;
if ( V_8 != NULL ) {
if ( V_6 -> V_9 ) {
V_4 = F_3 ( V_4 ) ;
if ( V_4 == NULL )
goto V_10;
}
V_8 -> V_4 = V_4 ;
V_5 = & V_8 -> V_1 ;
}
return V_5 ;
V_10:
free ( V_8 ) ;
return NULL ;
}
static void F_4 ( struct V_7 * V_11 , bool V_9 )
{
if ( V_9 )
free ( ( void * ) V_11 -> V_4 ) ;
free ( V_11 ) ;
}
static
void F_5 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
struct V_6 * V_12 = F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_7 * V_8 = F_2 ( V_1 , struct V_7 , V_1 ) ;
F_4 ( V_8 , V_12 -> V_9 ) ;
}
static int F_6 ( struct V_1 * V_1 , const void * V_3 )
{
const char * V_13 = V_3 ;
struct V_7 * V_8 = F_2 ( V_1 , struct V_7 , V_1 ) ;
return strcmp ( V_8 -> V_4 , V_13 ) ;
}
int F_7 ( struct V_6 * V_11 , const char * V_14 )
{
return F_8 ( & V_11 -> V_2 , V_14 ) ;
}
int F_9 ( struct V_6 * V_11 , const char * V_15 )
{
char V_3 [ 1024 ] ;
int V_16 ;
T_1 * V_17 = fopen ( V_15 , L_1 ) ;
if ( V_17 == NULL )
return V_18 ;
while ( fgets ( V_3 , sizeof( V_3 ) , V_17 ) != NULL ) {
const T_2 V_19 = strlen ( V_3 ) ;
if ( V_19 == 0 )
continue;
V_3 [ V_19 - 1 ] = '\0' ;
V_16 = F_7 ( V_11 , V_3 ) ;
if ( V_16 != 0 )
goto V_20;
}
V_16 = 0 ;
V_20:
fclose ( V_17 ) ;
return V_16 ;
}
void F_10 ( struct V_6 * V_12 , struct V_7 * V_8 )
{
F_11 ( & V_12 -> V_2 , & V_8 -> V_1 ) ;
}
struct V_7 * F_12 ( struct V_6 * V_12 , const char * V_3 )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_1 = F_13 ( & V_12 -> V_2 , V_3 ) ;
if ( V_1 )
V_8 = F_2 ( V_1 , struct V_7 , V_1 ) ;
return V_8 ;
}
static int F_14 ( struct V_6 * V_11 , const char * V_4 )
{
if ( strncmp ( V_4 , L_2 , 7 ) == 0 )
return F_9 ( V_11 , V_4 + 7 ) ;
return F_7 ( V_11 , V_4 ) ;
}
int F_15 ( struct V_6 * V_11 , const char * V_4 )
{
char * V_21 ;
int V_16 ;
while ( ( V_21 = strchr ( V_4 , ',' ) ) != NULL ) {
* V_21 = '\0' ;
V_16 = F_14 ( V_11 , V_4 ) ;
* V_21 = ',' ;
if ( V_16 != 0 )
return V_16 ;
V_4 = V_21 + 1 ;
}
return * V_4 ? F_14 ( V_11 , V_4 ) : 0 ;
}
struct V_6 * F_16 ( bool V_9 , const char * V_12 )
{
struct V_6 * V_11 = malloc ( sizeof( * V_11 ) ) ;
if ( V_11 != NULL ) {
F_17 ( & V_11 -> V_2 ) ;
V_11 -> V_2 . V_22 = F_6 ;
V_11 -> V_2 . V_23 = F_1 ;
V_11 -> V_2 . V_24 = F_5 ;
V_11 -> V_9 = V_9 ;
if ( V_12 && F_15 ( V_11 , V_12 ) != 0 )
goto V_25;
}
return V_11 ;
V_25:
free ( V_11 ) ;
return NULL ;
}
void F_18 ( struct V_6 * V_11 )
{
if ( V_11 != NULL )
F_19 ( & V_11 -> V_2 ) ;
}
struct V_7 * F_20 ( const struct V_6 * V_12 , unsigned int V_26 )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_1 ;
V_1 = F_21 ( & V_12 -> V_2 , V_26 ) ;
if ( V_1 )
V_8 = F_2 ( V_1 , struct V_7 , V_1 ) ;
return V_8 ;
}
