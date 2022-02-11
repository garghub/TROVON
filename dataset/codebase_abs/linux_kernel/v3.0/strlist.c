static struct V_1 * F_1 ( const char * V_2 , bool V_3 )
{
struct V_1 * V_4 = malloc ( sizeof( * V_4 ) ) ;
if ( V_4 != NULL ) {
if ( V_3 ) {
V_2 = F_2 ( V_2 ) ;
if ( V_2 == NULL )
goto V_5;
}
V_4 -> V_2 = V_2 ;
}
return V_4 ;
V_5:
free ( V_4 ) ;
return NULL ;
}
static void F_3 ( struct V_1 * V_4 , bool V_3 )
{
if ( V_3 )
free ( ( void * ) V_4 -> V_2 ) ;
free ( V_4 ) ;
}
int F_4 ( struct V_6 * V_4 , const char * V_7 )
{
struct V_8 * * V_9 = & V_4 -> V_10 . V_8 ;
struct V_8 * V_11 = NULL ;
struct V_1 * V_12 ;
while ( * V_9 != NULL ) {
int V_13 ;
V_11 = * V_9 ;
V_12 = F_5 ( V_11 , struct V_1 , V_8 ) ;
V_13 = strcmp ( V_12 -> V_2 , V_7 ) ;
if ( V_13 > 0 )
V_9 = & ( * V_9 ) -> V_14 ;
else if ( V_13 < 0 )
V_9 = & ( * V_9 ) -> V_15 ;
else
return - V_16 ;
}
V_12 = F_1 ( V_7 , V_4 -> V_3 ) ;
if ( V_12 == NULL )
return - V_17 ;
F_6 ( & V_12 -> V_8 , V_11 , V_9 ) ;
F_7 ( & V_12 -> V_8 , & V_4 -> V_10 ) ;
++ V_4 -> V_18 ;
return 0 ;
}
int F_8 ( struct V_6 * V_4 , const char * V_19 )
{
char V_20 [ 1024 ] ;
int V_21 ;
T_1 * V_22 = fopen ( V_19 , L_1 ) ;
if ( V_22 == NULL )
return V_23 ;
while ( fgets ( V_20 , sizeof( V_20 ) , V_22 ) != NULL ) {
const T_2 V_24 = strlen ( V_20 ) ;
if ( V_24 == 0 )
continue;
V_20 [ V_24 - 1 ] = '\0' ;
V_21 = F_4 ( V_4 , V_20 ) ;
if ( V_21 != 0 )
goto V_25;
}
V_21 = 0 ;
V_25:
fclose ( V_22 ) ;
return V_21 ;
}
void F_9 ( struct V_6 * V_4 , struct V_1 * V_12 )
{
F_10 ( & V_12 -> V_8 , & V_4 -> V_10 ) ;
F_3 ( V_12 , V_4 -> V_3 ) ;
}
struct V_1 * F_11 ( struct V_6 * V_4 , const char * V_20 )
{
struct V_8 * * V_9 = & V_4 -> V_10 . V_8 ;
struct V_8 * V_11 = NULL ;
while ( * V_9 != NULL ) {
struct V_1 * V_12 ;
int V_13 ;
V_11 = * V_9 ;
V_12 = F_5 ( V_11 , struct V_1 , V_8 ) ;
V_13 = strcmp ( V_12 -> V_2 , V_20 ) ;
if ( V_13 > 0 )
V_9 = & ( * V_9 ) -> V_14 ;
else if ( V_13 < 0 )
V_9 = & ( * V_9 ) -> V_15 ;
else
return V_12 ;
}
return NULL ;
}
static int F_12 ( struct V_6 * V_4 , const char * V_2 )
{
if ( strncmp ( V_2 , L_2 , 7 ) == 0 )
return F_8 ( V_4 , V_2 + 7 ) ;
return F_4 ( V_4 , V_2 ) ;
}
int F_13 ( struct V_6 * V_4 , const char * V_2 )
{
char * V_26 ;
int V_21 ;
while ( ( V_26 = strchr ( V_2 , ',' ) ) != NULL ) {
* V_26 = '\0' ;
V_21 = F_12 ( V_4 , V_2 ) ;
* V_26 = ',' ;
if ( V_21 != 0 )
return V_21 ;
V_2 = V_26 + 1 ;
}
return * V_2 ? F_12 ( V_4 , V_2 ) : 0 ;
}
struct V_6 * F_14 ( bool V_3 , const char * V_27 )
{
struct V_6 * V_4 = malloc ( sizeof( * V_4 ) ) ;
if ( V_4 != NULL ) {
V_4 -> V_10 = V_28 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_18 = 0 ;
if ( V_27 && F_13 ( V_4 , V_27 ) != 0 )
goto V_29;
}
return V_4 ;
V_29:
free ( V_4 ) ;
return NULL ;
}
void F_15 ( struct V_6 * V_4 )
{
if ( V_4 != NULL ) {
struct V_1 * V_30 ;
struct V_8 * V_31 = F_16 ( & V_4 -> V_10 ) ;
while ( V_31 ) {
V_30 = F_5 ( V_31 , struct V_1 , V_8 ) ;
V_31 = F_17 ( & V_30 -> V_8 ) ;
F_9 ( V_4 , V_30 ) ;
}
V_4 -> V_10 = V_28 ;
free ( V_4 ) ;
}
}
struct V_1 * F_18 ( const struct V_6 * V_4 , unsigned int V_32 )
{
struct V_8 * V_33 ;
for ( V_33 = F_16 ( & V_4 -> V_10 ) ; V_33 ; V_33 = F_17 ( V_33 ) ) {
struct V_1 * V_30 = F_5 ( V_33 , struct V_1 , V_8 ) ;
if ( ! V_32 -- )
return V_30 ;
}
return NULL ;
}
