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
int V_9 ;
V_8 = F_1 () ;
if ( ! V_8 )
return F_5 ( - V_10 ) ;
V_9 = F_6 ( & V_8 -> V_8 ) ;
if ( V_9 ) {
F_7 ( V_8 ) ;
return F_5 ( V_9 ) ;
}
V_8 -> V_8 . V_11 = & V_12 ;
F_8 ( & V_13 ) ;
memcpy ( & V_8 -> V_14 , & V_7 -> V_14 , sizeof( V_8 -> V_14 ) ) ;
V_8 -> V_6 = F_9 ( V_6 ) ;
F_10 ( & V_13 ) ;
return V_8 ;
}
struct V_1 * F_11 ( unsigned long V_15 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_1 * V_16 ;
F_12 ( ! V_7 ) ;
F_13 ( V_7 ) ;
if ( ! ( V_15 & V_17 ) )
return V_7 ;
V_16 = F_4 ( V_6 , V_7 ) ;
F_14 ( V_7 ) ;
return V_16 ;
}
void F_15 ( struct V_4 * V_4 )
{
struct V_1 * V_8 ;
V_8 = F_16 ( V_4 , struct V_1 , V_4 ) ;
F_17 ( V_8 -> V_6 ) ;
F_18 ( & V_8 -> V_8 ) ;
F_7 ( V_8 ) ;
}
static inline struct V_1 * F_19 ( struct V_18 * V_8 )
{
return F_16 ( V_8 , struct V_1 , V_8 ) ;
}
static struct V_18 * F_20 ( struct V_19 * V_20 )
{
struct V_1 * V_8 = NULL ;
struct V_21 * V_21 ;
F_21 ( V_20 ) ;
V_21 = V_20 -> V_21 ;
if ( V_21 ) {
V_8 = V_21 -> V_2 ;
F_13 ( V_8 ) ;
}
F_22 ( V_20 ) ;
return V_8 ? & V_8 -> V_8 : NULL ;
}
static void F_23 ( struct V_18 * V_8 )
{
F_14 ( F_19 ( V_8 ) ) ;
}
static int F_24 ( struct V_21 * V_21 , struct V_18 * V_22 )
{
struct V_1 * V_8 = F_19 ( V_22 ) ;
if ( ! F_25 ( V_8 -> V_6 , V_23 ) ||
! F_25 ( F_26 () , V_23 ) )
return - V_24 ;
F_13 ( V_8 ) ;
F_14 ( V_21 -> V_2 ) ;
V_21 -> V_2 = V_8 ;
return 0 ;
}
