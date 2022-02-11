static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( struct V_1 ) , V_3 ) ;
if ( V_2 )
F_3 ( & V_2 -> V_4 ) ;
return V_2 ;
}
static struct V_1 * F_4 ( struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_1 () ;
if ( ! V_8 )
return F_5 ( - V_9 ) ;
F_6 ( & V_10 ) ;
memcpy ( & V_8 -> V_11 , & V_7 -> V_11 , sizeof( V_8 -> V_11 ) ) ;
V_8 -> V_12 = F_7 ( F_8 ( V_6 , V_12 ) ) ;
F_9 ( & V_10 ) ;
return V_8 ;
}
struct V_1 * F_10 ( unsigned long V_13 ,
struct V_5 * V_6 )
{
struct V_1 * V_7 = V_6 -> V_14 -> V_2 ;
struct V_1 * V_15 ;
F_11 ( ! V_7 ) ;
F_12 ( V_7 ) ;
if ( ! ( V_13 & V_16 ) )
return V_7 ;
V_15 = F_4 ( V_6 , V_7 ) ;
F_13 ( V_7 ) ;
return V_15 ;
}
void F_14 ( struct V_4 * V_4 )
{
struct V_1 * V_8 ;
V_8 = F_15 ( V_4 , struct V_1 , V_4 ) ;
F_16 ( V_8 -> V_12 ) ;
F_17 ( V_8 ) ;
}
static void * F_18 ( struct V_5 * V_17 )
{
struct V_1 * V_8 = NULL ;
struct V_14 * V_14 ;
F_19 () ;
V_14 = F_20 ( V_17 ) ;
if ( V_14 ) {
V_8 = V_14 -> V_2 ;
F_12 ( V_8 ) ;
}
F_21 () ;
return V_8 ;
}
static void F_22 ( void * V_8 )
{
F_13 ( V_8 ) ;
}
static int F_23 ( struct V_14 * V_14 , void * V_8 )
{
F_12 ( V_8 ) ;
F_13 ( V_14 -> V_2 ) ;
V_14 -> V_2 = V_8 ;
return 0 ;
}
