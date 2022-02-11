static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 ,
unsigned long V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_12 = F_3 ( V_8 -> V_14 , V_5 , 0 , V_15 ) ;
if ( ! V_12 )
return - V_16 ;
V_10 = F_4 ( sizeof( * V_10 ) , V_15 ) ;
if ( ! V_10 )
goto V_17;
V_13 = F_5 ( V_10 , 1 , V_15 ) ;
if ( V_13 )
goto V_18;
F_6 ( V_10 -> V_19 , V_12 , V_5 , 0 ) ;
V_4 -> V_20 = V_12 ;
V_4 -> V_9 = V_10 ;
return 0 ;
V_18:
F_7 ( V_10 ) ;
V_17:
F_8 ( V_8 -> V_14 , V_12 , V_4 -> V_21 ) ;
return - V_16 ;
}
static void F_9 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_2 ) ;
struct V_11 * V_12 = V_4 -> V_20 ;
F_8 ( V_8 -> V_14 , V_12 , V_4 -> V_21 ) ;
F_10 ( V_4 -> V_9 ) ;
F_7 ( V_4 -> V_9 ) ;
}
static struct V_1 * F_11 ( struct V_14 * V_14 )
{
struct V_7 * V_8 ;
V_8 = F_12 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return F_13 ( - V_16 ) ;
V_8 -> V_2 . V_22 = & V_23 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_2 . type = V_24 ;
return & V_8 -> V_2 ;
}
static int F_14 ( struct V_14 * V_14 , void * V_25 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( V_14 ) ;
if ( F_15 ( V_2 ) )
return F_16 ( V_2 ) ;
V_2 -> V_26 = F_17 ( V_14 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_19 ( void )
{
F_20 ( F_14 , NULL ) ;
return 0 ;
}
