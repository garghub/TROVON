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
static void F_4 ( struct V_7 * V_8 , bool V_9 )
{
if ( V_9 )
F_5 ( ( char * * ) & V_8 -> V_4 ) ;
free ( V_8 ) ;
}
static
void F_6 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
struct V_6 * V_11 = F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_7 * V_8 = F_2 ( V_1 , struct V_7 , V_1 ) ;
F_4 ( V_8 , V_11 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_1 , const void * V_3 )
{
const char * V_12 = V_3 ;
struct V_7 * V_8 = F_2 ( V_1 , struct V_7 , V_1 ) ;
return strcmp ( V_8 -> V_4 , V_12 ) ;
}
int F_8 ( struct V_6 * V_11 , const char * V_13 )
{
return F_9 ( & V_11 -> V_2 , V_13 ) ;
}
int F_10 ( struct V_6 * V_11 , const char * V_14 )
{
char V_3 [ 1024 ] ;
int V_15 ;
T_1 * V_16 = fopen ( V_14 , L_1 ) ;
if ( V_16 == NULL )
return - V_17 ;
while ( fgets ( V_3 , sizeof( V_3 ) , V_16 ) != NULL ) {
const T_2 V_18 = strlen ( V_3 ) ;
if ( V_18 == 0 )
continue;
V_3 [ V_18 - 1 ] = '\0' ;
V_15 = F_8 ( V_11 , V_3 ) ;
if ( V_15 != 0 )
goto V_19;
}
V_15 = 0 ;
V_19:
fclose ( V_16 ) ;
return V_15 ;
}
void F_11 ( struct V_6 * V_11 , struct V_7 * V_8 )
{
F_12 ( & V_11 -> V_2 , & V_8 -> V_1 ) ;
}
struct V_7 * F_13 ( struct V_6 * V_11 , const char * V_3 )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_1 = F_14 ( & V_11 -> V_2 , V_3 ) ;
if ( V_1 )
V_8 = F_2 ( V_1 , struct V_7 , V_1 ) ;
return V_8 ;
}
static int F_15 ( struct V_6 * V_11 , const char * V_4 ,
const char * V_20 )
{
int V_15 ;
char * V_21 = NULL ;
if ( strncmp ( V_4 , L_2 , 7 ) == 0 )
return F_10 ( V_11 , V_4 + 7 ) ;
if ( V_20 ) {
V_15 = - V_22 ;
if ( F_16 ( & V_21 , L_3 , V_20 , V_4 ) < 0 )
goto V_19;
if ( F_17 ( V_21 , V_23 ) == 0 ) {
V_15 = F_10 ( V_11 , V_21 ) ;
goto V_19;
}
}
V_15 = F_8 ( V_11 , V_4 ) ;
V_19:
free ( V_21 ) ;
return V_15 ;
}
static int F_18 ( struct V_6 * V_11 , const char * V_4 , const char * V_20 )
{
char * V_24 ;
int V_15 ;
while ( ( V_24 = strchr ( V_4 , ',' ) ) != NULL ) {
* V_24 = '\0' ;
V_15 = F_15 ( V_11 , V_4 , V_20 ) ;
* V_24 = ',' ;
if ( V_15 != 0 )
return V_15 ;
V_4 = V_24 + 1 ;
}
return * V_4 ? F_15 ( V_11 , V_4 , V_20 ) : 0 ;
}
struct V_6 * F_19 ( const char * V_25 , const struct V_26 * V_27 )
{
struct V_6 * V_11 = malloc ( sizeof( * V_11 ) ) ;
if ( V_11 != NULL ) {
bool V_9 = true ;
const char * V_28 = NULL ;
if ( V_27 ) {
V_9 = ! V_27 -> V_29 ;
V_28 = V_27 -> V_28 ;
}
F_20 ( & V_11 -> V_2 ) ;
V_11 -> V_2 . V_30 = F_7 ;
V_11 -> V_2 . V_31 = F_1 ;
V_11 -> V_2 . V_32 = F_6 ;
V_11 -> V_9 = V_9 ;
if ( V_25 && F_18 ( V_11 , V_25 , V_28 ) != 0 )
goto V_33;
}
return V_11 ;
V_33:
free ( V_11 ) ;
return NULL ;
}
void F_21 ( struct V_6 * V_11 )
{
if ( V_11 != NULL )
F_22 ( & V_11 -> V_2 ) ;
}
struct V_7 * F_23 ( const struct V_6 * V_11 , unsigned int V_34 )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_1 ;
V_1 = F_24 ( & V_11 -> V_2 , V_34 ) ;
if ( V_1 )
V_8 = F_2 ( V_1 , struct V_7 , V_1 ) ;
return V_8 ;
}
