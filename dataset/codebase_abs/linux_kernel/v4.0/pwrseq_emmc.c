static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 1 ) ;
F_3 ( 1 ) ;
F_2 ( V_2 -> V_3 , 0 ) ;
F_3 ( 200 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 -> V_2 ,
struct V_1 , V_2 ) ;
F_1 ( V_2 ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 -> V_2 ,
struct V_1 , V_2 ) ;
F_7 ( & V_2 -> V_6 ) ;
F_8 ( V_2 -> V_3 ) ;
F_9 ( V_2 ) ;
V_5 -> V_2 = NULL ;
}
static int F_10 ( struct V_7 * V_8 ,
unsigned long V_9 , void * V_10 )
{
struct V_1 * V_2 = F_5 ( V_8 ,
struct V_1 , V_6 ) ;
F_1 ( V_2 ) ;
return V_11 ;
}
int F_11 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
struct V_1 * V_2 ;
int V_14 = 0 ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_15 ) ;
if ( ! V_2 )
return - V_16 ;
V_2 -> V_3 = F_13 ( V_13 , L_1 , 0 , V_17 ) ;
if ( F_14 ( V_2 -> V_3 ) ) {
V_14 = F_15 ( V_2 -> V_3 ) ;
goto free;
}
V_2 -> V_6 . V_18 = F_10 ;
V_2 -> V_6 . V_19 = 129 ;
F_16 ( & V_2 -> V_6 ) ;
V_2 -> V_2 . V_20 = & V_21 ;
V_5 -> V_2 = & V_2 -> V_2 ;
return 0 ;
free:
F_9 ( V_2 ) ;
return V_14 ;
}
