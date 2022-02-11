static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , int V_6 , void * V_7 )
{
struct V_8 * V_9 = V_7 ;
if ( V_9 -> V_10 . V_11 )
return V_9 -> V_10 . V_11 ( V_9 -> V_10 . V_7 , V_5 , V_6 ) ;
F_2 ( L_1 , V_5 , V_6 ) ;
return 0 ;
}
static int F_3 ( struct V_12 * V_13 , const char * const * V_14 ,
int V_15 )
{
struct V_8 * V_9 = F_4 ( V_13 ) ;
int V_16 ;
F_5 ( V_13 -> V_4 ) ;
V_16 = F_6 ( V_9 -> V_2 , V_13 -> V_4 ) ;
F_7 ( V_13 -> V_4 ) ;
return V_16 ;
}
static void F_8 ( struct V_12 * V_13 , const char * const * V_14 ,
int V_15 )
{
struct V_8 * V_9 = F_4 ( V_13 ) ;
F_5 ( V_13 -> V_4 ) ;
F_9 ( V_9 -> V_2 , V_13 -> V_4 ) ;
F_7 ( V_13 -> V_4 ) ;
}
static int F_10 ( struct V_12 * V_13 , T_1 V_5 ,
struct V_17 * V_18 , unsigned V_19 , int V_20 )
{
struct V_8 * V_9 = F_4 ( V_13 ) ;
T_2 V_16 ;
V_16 = F_11 ( V_9 -> V_2 , V_5 , V_18 -> V_21 , V_18 -> V_22 , V_20 ) ;
F_12 ( V_16 < 0 ) ;
return ( V_16 == V_19 ) ? 0 : - V_23 ;
}
static int F_13 ( struct V_12 * V_13 , T_1 V_5 ,
struct V_17 * V_18 , unsigned V_19 )
{
struct V_8 * V_9 = F_4 ( V_13 ) ;
F_5 ( V_13 -> V_4 ) ;
F_14 ( V_9 -> V_2 , V_5 , V_19 ) ;
F_7 ( V_13 -> V_4 ) ;
return 0 ;
}
static void F_15 ( struct V_12 * V_13 )
{
struct V_8 * V_9 = F_4 ( V_13 ) ;
F_16 ( V_9 -> V_2 ) ;
F_17 ( V_9 ) ;
}
struct V_12 * F_18 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = F_19 ( sizeof( * V_9 ) , V_24 ) ;
if ( ! V_9 )
return F_20 ( - V_25 ) ;
V_9 -> V_2 = V_2 ;
F_21 ( & V_9 -> V_10 , V_4 , & V_26 ) ;
F_22 ( V_2 , F_1 , V_9 ) ;
return & V_9 -> V_10 ;
}
