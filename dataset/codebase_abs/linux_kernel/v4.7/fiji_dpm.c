static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 ) ;
return 0 ;
}
static int F_3 ( struct V_2 * V_3 )
{
char V_4 [ 30 ] = L_1 ;
int V_5 ;
V_5 = F_4 ( & V_3 -> V_6 . V_7 , V_4 , V_3 -> V_8 ) ;
if ( V_5 )
goto V_9;
V_5 = F_5 ( V_3 -> V_6 . V_7 ) ;
V_9:
if ( V_5 ) {
F_6 ( L_2 , V_4 ) ;
F_7 ( V_3 -> V_6 . V_7 ) ;
V_3 -> V_6 . V_7 = NULL ;
}
return V_5 ;
}
static int F_8 ( void * V_1 )
{
int V_10 ;
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_10 = F_3 ( V_3 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_9 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_7 ( V_3 -> V_6 . V_7 ) ;
V_3 -> V_6 . V_7 = NULL ;
return 0 ;
}
static int F_10 ( void * V_1 )
{
int V_10 ;
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_11 ( & V_3 -> V_6 . V_11 ) ;
V_10 = F_12 ( V_3 ) ;
if ( V_10 ) {
F_6 ( L_3 ) ;
goto V_12;
}
V_10 = F_13 ( V_3 ) ;
if ( V_10 ) {
F_6 ( L_4 ) ;
goto V_12;
}
F_14 ( & V_3 -> V_6 . V_11 ) ;
return 0 ;
V_12:
V_3 -> V_13 . V_14 = false ;
F_14 ( & V_3 -> V_6 . V_11 ) ;
return - V_15 ;
}
static int F_15 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_11 ( & V_3 -> V_6 . V_11 ) ;
F_16 ( V_3 ) ;
F_14 ( & V_3 -> V_6 . V_11 ) ;
return 0 ;
}
static int F_17 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_15 ( V_3 ) ;
return 0 ;
}
static int F_18 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_10 ( V_3 ) ;
return 0 ;
}
static int F_19 ( void * V_1 ,
enum V_16 V_17 )
{
return 0 ;
}
static int F_20 ( void * V_1 ,
enum V_18 V_17 )
{
return 0 ;
}
static void F_2 ( struct V_2 * V_3 )
{
if ( NULL == V_3 -> V_6 . V_19 )
V_3 -> V_6 . V_19 = & V_20 ;
}
