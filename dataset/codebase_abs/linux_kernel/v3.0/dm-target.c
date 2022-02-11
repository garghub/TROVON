static inline struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (tt, &_targets, list)
if ( ! strcmp ( V_2 , V_3 -> V_2 ) )
return V_3 ;
return NULL ;
}
static struct V_1 * F_3 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_4 ( & V_4 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 && ! F_5 ( V_3 -> V_5 ) )
V_3 = NULL ;
F_6 ( & V_4 ) ;
return V_3 ;
}
static void F_7 ( const char * V_2 )
{
F_8 ( L_1 , V_2 ) ;
}
struct V_1 * F_9 ( const char * V_2 )
{
struct V_1 * V_3 = F_3 ( V_2 ) ;
if ( ! V_3 ) {
F_7 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
}
return V_3 ;
}
void F_10 ( struct V_1 * V_3 )
{
F_4 ( & V_4 ) ;
F_11 ( V_3 -> V_5 ) ;
F_6 ( & V_4 ) ;
}
int F_12 ( void (* F_13)( struct V_1 * V_3 ,
void * V_6 ) , void * V_6 )
{
struct V_1 * V_3 ;
F_4 ( & V_4 ) ;
F_2 (tt, &_targets, list)
F_13 ( V_3 , V_6 ) ;
F_6 ( & V_4 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_3 )
{
int V_7 = 0 ;
F_15 ( & V_4 ) ;
if ( F_1 ( V_3 -> V_2 ) )
V_7 = - V_8 ;
else
F_16 ( & V_3 -> V_9 , & V_10 ) ;
F_17 ( & V_4 ) ;
return V_7 ;
}
void F_18 ( struct V_1 * V_3 )
{
F_15 ( & V_4 ) ;
if ( ! F_1 ( V_3 -> V_2 ) ) {
F_19 ( L_2 , V_3 -> V_2 ) ;
F_20 () ;
}
F_21 ( & V_3 -> V_9 ) ;
F_17 ( & V_4 ) ;
}
static int F_22 ( struct V_11 * V_3 , unsigned int V_12 , char * * args )
{
V_3 -> V_13 = 1 ;
return 0 ;
}
static void F_23 ( struct V_11 * V_3 )
{
}
static int F_24 ( struct V_11 * V_3 , struct V_14 * V_14 ,
union V_15 * V_16 )
{
return - V_17 ;
}
int T_1 F_25 ( void )
{
return F_14 ( & V_18 ) ;
}
void F_26 ( void )
{
F_18 ( & V_18 ) ;
}
