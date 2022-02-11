static struct V_1 * F_1 ( struct V_2 * V_2 V_3 ,
const void * V_4 )
{
int V_5 = ( int ) ( ( long ) V_4 ) ;
struct V_1 * V_6 = NULL ;
struct V_7 * V_8 = malloc ( sizeof( * V_8 ) ) ;
if ( V_8 != NULL ) {
V_8 -> V_5 = V_5 ;
V_6 = & V_8 -> V_1 ;
}
return V_6 ;
}
static void F_2 ( struct V_7 * V_9 )
{
free ( V_9 ) ;
}
static void F_3 ( struct V_2 * V_2 V_3 ,
struct V_1 * V_1 )
{
struct V_7 * V_8 = F_4 ( V_1 , struct V_7 , V_1 ) ;
F_2 ( V_8 ) ;
}
static int F_5 ( struct V_1 * V_1 , const void * V_4 )
{
int V_5 = ( int ) ( ( long ) V_4 ) ;
struct V_7 * V_8 = F_4 ( V_1 , struct V_7 , V_1 ) ;
return V_8 -> V_5 - V_5 ;
}
int F_6 ( struct V_10 * V_9 , int V_5 )
{
return F_7 ( & V_9 -> V_2 , ( void * ) ( ( long ) V_5 ) ) ;
}
void F_8 ( struct V_10 * V_9 , struct V_7 * V_8 )
{
F_9 ( & V_9 -> V_2 , & V_8 -> V_1 ) ;
}
struct V_7 * F_10 ( struct V_10 * V_9 , int V_5 )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_1 = F_11 ( & V_9 -> V_2 , ( void * ) ( ( long ) V_5 ) ) ;
if ( V_1 )
V_8 = F_4 ( V_1 , struct V_7 , V_1 ) ;
return V_8 ;
}
struct V_10 * F_12 ( void )
{
struct V_10 * V_9 = malloc ( sizeof( * V_9 ) ) ;
if ( V_9 != NULL ) {
F_13 ( & V_9 -> V_2 ) ;
V_9 -> V_2 . V_11 = F_5 ;
V_9 -> V_2 . V_12 = F_1 ;
V_9 -> V_2 . V_13 = F_3 ;
}
return V_9 ;
}
void F_14 ( struct V_10 * V_9 )
{
if ( V_9 != NULL )
F_15 ( & V_9 -> V_2 ) ;
}
struct V_7 * F_16 ( const struct V_10 * V_9 , unsigned int V_14 )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_1 ;
V_1 = F_17 ( & V_9 -> V_2 , V_14 ) ;
if ( V_1 )
V_8 = F_4 ( V_1 , struct V_7 , V_1 ) ;
return V_8 ;
}
