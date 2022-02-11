static int F_1 ( const void * V_1 , const void * V_2 )
{
const char * V_3 = V_1 ;
const struct V_4 * V_5 = V_2 ;
return strcmp ( V_3 , V_5 -> V_6 ) ;
}
static int F_2 ( const void * V_7 , const void * V_8 )
{
const struct V_4 * V_9 = V_7 , * V_10 = V_8 ;
return strcmp ( V_9 -> V_6 , V_10 -> V_6 ) ;
}
static int F_3 ( struct V_11 * V_12 )
{
int V_13 = 0 , V_14 , V_15 ;
struct V_4 * V_16 ;
for ( V_14 = 0 ; V_14 <= V_17 ; ++ V_14 )
if ( V_18 [ V_14 ] )
++ V_13 ;
V_16 = V_12 -> V_19 . V_16 = malloc ( sizeof( struct V_4 ) * V_13 ) ;
if ( V_12 -> V_19 . V_16 == NULL )
return - 1 ;
for ( V_14 = 0 , V_15 = 0 ; V_14 <= V_17 ; ++ V_14 ) {
if ( V_18 [ V_14 ] ) {
V_16 [ V_15 ] . V_6 = V_18 [ V_14 ] ;
V_16 [ V_15 ] . V_20 = V_14 ;
++ V_15 ;
}
}
qsort ( V_12 -> V_19 . V_16 , V_13 , sizeof( struct V_4 ) , F_2 ) ;
V_12 -> V_19 . V_13 = V_13 ;
return 0 ;
}
struct V_11 * F_4 ( void )
{
struct V_11 * V_12 = malloc ( sizeof( * V_12 ) ) ;
if ( V_12 ) {
if ( F_3 ( V_12 ) ) {
free ( V_12 ) ;
return NULL ;
}
}
return V_12 ;
}
void F_5 ( struct V_11 * V_12 )
{
F_6 ( & V_12 -> V_19 . V_16 ) ;
free ( V_12 ) ;
}
const char * F_7 ( const struct V_11 * V_12 V_21 , int V_20 )
{
return V_20 <= V_17 ? V_18 [ V_20 ] : NULL ;
}
int F_8 ( struct V_11 * V_12 , const char * V_6 )
{
struct V_4 * V_22 = bsearch ( V_6 , V_12 -> V_19 . V_16 ,
V_12 -> V_19 . V_13 , sizeof( * V_22 ) ,
F_1 ) ;
return V_22 ? V_22 -> V_20 : - 1 ;
}
struct V_11 * F_4 ( void )
{
struct V_11 * V_12 = malloc ( sizeof( * V_12 ) ) ;
if ( V_12 )
V_12 -> V_23 = F_9 () ;
return V_12 ;
}
void F_5 ( struct V_11 * V_12 )
{
free ( V_12 ) ;
}
const char * F_7 ( const struct V_11 * V_12 , int V_20 )
{
return F_10 ( V_20 , V_12 -> V_23 ) ;
}
int F_8 ( struct V_11 * V_12 , const char * V_6 )
{
return F_11 ( V_6 , V_12 -> V_23 ) ;
}
