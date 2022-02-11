int F_1 ( void )
{
V_1 = F_2 (
L_1 , sizeof( struct V_2 ) , 0 ,
V_3 , NULL ) ;
if ( ! V_1 )
return - V_4 ;
return 0 ;
}
void F_3 ( void )
{
F_4 () ;
F_5 ( V_1 ) ;
}
struct V_2 * F_6 ( struct V_5 * V_6 ,
void * V_7 )
{
struct V_2 * V_8 = NULL ;
unsigned V_9 ;
V_8 = F_7 ( V_1 , V_10 ) ;
if ( V_8 == NULL )
return NULL ;
V_8 -> V_7 = V_7 ;
V_8 -> V_11 = V_6 -> V_11 ;
F_8 ( & V_8 -> V_12 ) ;
V_9 = F_9 ( & V_6 -> V_13 ) ;
F_10 ( & V_8 -> V_14 , & V_15 ,
& V_8 -> V_12 , V_6 -> V_16 , V_9 ) ;
F_10 ( & V_8 -> V_17 , & V_18 ,
& V_8 -> V_12 , V_6 -> V_16 + 1 , V_9 ) ;
return V_8 ;
}
void F_11 ( struct V_2 * V_8 )
{
int V_19 = F_12 ( & V_8 -> V_14 ) ;
if ( ! V_19 )
F_13 ( & V_8 -> V_14 ,
L_2 ) ;
else
F_13 ( & V_8 -> V_14 ,
L_3 ) ;
}
void F_14 ( struct V_2 * V_8 )
{
int V_19 = F_12 ( & V_8 -> V_17 ) ;
if ( ! V_19 )
F_13 ( & V_8 -> V_17 ,
L_2 ) ;
else
F_13 ( & V_8 -> V_17 ,
L_3 ) ;
}
static const char * F_15 ( struct V_20 * V_8 )
{
return L_4 ;
}
static const char * F_16 ( struct V_20 * V_21 )
{
struct V_2 * V_8 = F_17 ( V_21 ) ;
return ( const char * ) V_8 -> V_11 -> V_22 ;
}
static bool F_18 ( struct V_20 * V_21 )
{
return true ;
}
static void F_19 ( struct V_23 * V_24 )
{
struct V_20 * V_21 = F_20 ( V_24 , struct V_20 , V_24 ) ;
struct V_2 * V_8 = F_17 ( V_21 ) ;
F_21 ( V_8 -> V_25 ) ;
F_22 ( V_1 , V_8 ) ;
}
static void F_23 ( struct V_20 * V_21 )
{
struct V_2 * V_8 = F_17 ( V_21 ) ;
F_24 ( & V_8 -> V_17 . V_24 , F_19 ) ;
}
static void F_25 ( struct V_20 * V_21 )
{
struct V_2 * V_8 = F_17 ( V_21 ) ;
F_21 ( & V_8 -> V_14 ) ;
}
