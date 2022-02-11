static struct V_1 * F_1 ( struct V_2 * V_2 V_3 ,
const void * V_4 )
{
int V_5 = ( int ) ( ( long ) V_4 ) ;
struct V_1 * V_6 = NULL ;
struct V_7 * V_8 = malloc ( sizeof( * V_8 ) ) ;
if ( V_8 != NULL ) {
V_8 -> V_5 = V_5 ;
V_8 -> V_9 = NULL ;
V_6 = & V_8 -> V_1 ;
}
return V_6 ;
}
static void F_2 ( struct V_7 * V_10 )
{
free ( V_10 ) ;
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
int F_6 ( struct V_11 * V_10 , int V_5 )
{
return F_7 ( & V_10 -> V_2 , ( void * ) ( ( long ) V_5 ) ) ;
}
void F_8 ( struct V_11 * V_10 , struct V_7 * V_8 )
{
F_9 ( & V_10 -> V_2 , & V_8 -> V_1 ) ;
}
static struct V_7 * F_10 ( struct V_11 * V_10 ,
int V_5 , bool V_12 )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_1 ;
if ( V_10 == NULL )
return NULL ;
if ( V_12 )
V_1 = F_11 ( & V_10 -> V_2 , ( void * ) ( ( long ) V_5 ) ) ;
else
V_1 = F_12 ( & V_10 -> V_2 , ( void * ) ( ( long ) V_5 ) ) ;
if ( V_1 )
V_8 = F_4 ( V_1 , struct V_7 , V_1 ) ;
return V_8 ;
}
struct V_7 * F_13 ( struct V_11 * V_10 , int V_5 )
{
return F_10 ( V_10 , V_5 , false ) ;
}
struct V_7 * F_14 ( struct V_11 * V_10 , int V_5 )
{
return F_10 ( V_10 , V_5 , true ) ;
}
static int F_15 ( struct V_11 * V_10 , const char * V_13 )
{
char * V_14 ;
int V_15 ;
do {
long V_16 = strtol ( V_13 , & V_14 , 10 ) ;
V_15 = - V_17 ;
if ( * V_14 != ',' && * V_14 != '\0' )
break;
V_15 = F_6 ( V_10 , V_16 ) ;
if ( V_15 )
break;
V_13 = V_14 + 1 ;
} while ( * V_14 != '\0' );
return V_15 ;
}
struct V_11 * F_16 ( const char * V_18 )
{
struct V_11 * V_10 = malloc ( sizeof( * V_10 ) ) ;
if ( V_10 != NULL ) {
F_17 ( & V_10 -> V_2 ) ;
V_10 -> V_2 . V_19 = F_5 ;
V_10 -> V_2 . V_20 = F_1 ;
V_10 -> V_2 . V_21 = F_3 ;
if ( V_18 && F_15 ( V_10 , V_18 ) )
goto V_22;
}
return V_10 ;
V_22:
F_18 ( V_10 ) ;
return NULL ;
}
void F_18 ( struct V_11 * V_10 )
{
if ( V_10 != NULL )
F_19 ( & V_10 -> V_2 ) ;
}
struct V_7 * F_20 ( const struct V_11 * V_10 , unsigned int V_23 )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_1 ;
V_1 = F_21 ( & V_10 -> V_2 , V_23 ) ;
if ( V_1 )
V_8 = F_4 ( V_1 , struct V_7 , V_1 ) ;
return V_8 ;
}
