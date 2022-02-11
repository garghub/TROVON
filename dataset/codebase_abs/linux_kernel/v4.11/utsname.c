static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , F_3 () , V_4 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
F_5 ( V_1 , V_4 ) ;
}
static struct V_5 * F_6 ( void )
{
struct V_5 * V_6 ;
V_6 = F_7 ( sizeof( struct V_5 ) , V_7 ) ;
if ( V_6 )
F_8 ( & V_6 -> V_8 ) ;
return V_6 ;
}
static struct V_5 * F_9 ( struct V_2 * V_9 ,
struct V_5 * V_10 )
{
struct V_5 * V_3 ;
struct V_1 * V_1 ;
int V_11 ;
V_11 = - V_12 ;
V_1 = F_1 ( V_9 ) ;
if ( ! V_1 )
goto V_13;
V_11 = - V_14 ;
V_3 = F_6 () ;
if ( ! V_3 )
goto V_15;
V_11 = F_10 ( & V_3 -> V_3 ) ;
if ( V_11 )
goto V_16;
V_3 -> V_1 = V_1 ;
V_3 -> V_3 . V_17 = & V_18 ;
F_11 ( & V_19 ) ;
memcpy ( & V_3 -> V_20 , & V_10 -> V_20 , sizeof( V_3 -> V_20 ) ) ;
V_3 -> V_9 = F_12 ( V_9 ) ;
F_13 ( & V_19 ) ;
return V_3 ;
V_16:
F_14 ( V_3 ) ;
V_15:
F_4 ( V_1 ) ;
V_13:
return F_15 ( V_11 ) ;
}
struct V_5 * F_16 ( unsigned long V_21 ,
struct V_2 * V_9 , struct V_5 * V_10 )
{
struct V_5 * V_22 ;
F_17 ( ! V_10 ) ;
F_18 ( V_10 ) ;
if ( ! ( V_21 & V_23 ) )
return V_10 ;
V_22 = F_9 ( V_9 , V_10 ) ;
F_19 ( V_10 ) ;
return V_22 ;
}
void F_20 ( struct V_8 * V_8 )
{
struct V_5 * V_3 ;
V_3 = F_21 ( V_8 , struct V_5 , V_8 ) ;
F_4 ( V_3 -> V_1 ) ;
F_22 ( V_3 -> V_9 ) ;
F_23 ( & V_3 -> V_3 ) ;
F_14 ( V_3 ) ;
}
static inline struct V_5 * F_24 ( struct V_24 * V_3 )
{
return F_21 ( V_3 , struct V_5 , V_3 ) ;
}
static struct V_24 * F_25 ( struct V_25 * V_26 )
{
struct V_5 * V_3 = NULL ;
struct V_27 * V_27 ;
F_26 ( V_26 ) ;
V_27 = V_26 -> V_27 ;
if ( V_27 ) {
V_3 = V_27 -> V_6 ;
F_18 ( V_3 ) ;
}
F_27 ( V_26 ) ;
return V_3 ? & V_3 -> V_3 : NULL ;
}
static void F_28 ( struct V_24 * V_3 )
{
F_19 ( F_24 ( V_3 ) ) ;
}
static int F_29 ( struct V_27 * V_27 , struct V_24 * V_28 )
{
struct V_5 * V_3 = F_24 ( V_28 ) ;
if ( ! F_30 ( V_3 -> V_9 , V_29 ) ||
! F_30 ( F_31 () , V_29 ) )
return - V_30 ;
F_18 ( V_3 ) ;
F_19 ( V_27 -> V_6 ) ;
V_27 -> V_6 = V_3 ;
return 0 ;
}
static struct V_2 * F_32 ( struct V_24 * V_3 )
{
return F_24 ( V_3 ) -> V_9 ;
}
