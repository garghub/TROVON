struct V_1 * F_1 ( struct V_2 * V_3 , void * V_4 )
{
struct V_1 * V_5 = NULL ;
unsigned V_6 ;
V_5 = F_2 ( V_7 , V_8 ) ;
if ( V_5 == NULL )
return NULL ;
F_3 ( & V_5 -> V_9 ) ;
V_5 -> V_4 = V_4 ;
V_5 -> V_10 = V_3 -> V_10 ;
F_4 ( & V_5 -> V_11 ) ;
V_6 = F_5 ( & V_3 -> V_12 ) ;
F_6 ( & V_5 -> V_13 , & V_14 , & V_5 -> V_11 ,
V_3 -> V_15 , V_6 ) ;
return V_5 ;
}
void F_7 ( struct V_1 * V_5 )
{
int V_16 = F_8 ( & V_5 -> V_13 ) ;
if ( ! V_16 )
F_9 ( & V_5 -> V_13 , L_1 ) ;
else
F_9 ( & V_5 -> V_13 , L_2 ) ;
}
void F_10 ( struct V_1 * V_17 )
{
struct V_18 * V_19 , * V_20 ;
F_11 ( V_21 , & V_17 -> V_13 . V_22 ) ;
F_12 (cur, tmp, &s_fence->scheduled_cb, node) {
F_13 ( & V_19 -> V_23 ) ;
V_19 -> V_24 ( & V_17 -> V_13 , V_19 ) ;
}
}
static const char * F_14 ( struct V_5 * V_5 )
{
return L_3 ;
}
static const char * F_15 ( struct V_5 * V_25 )
{
struct V_1 * V_5 = F_16 ( V_25 ) ;
return ( const char * ) V_5 -> V_10 -> V_26 ;
}
static bool F_17 ( struct V_5 * V_25 )
{
return true ;
}
static void F_18 ( struct V_27 * V_28 )
{
struct V_5 * V_25 = F_19 ( V_28 , struct V_5 , V_28 ) ;
struct V_1 * V_5 = F_16 ( V_25 ) ;
F_20 ( V_7 , V_5 ) ;
}
static void F_21 ( struct V_5 * V_25 )
{
F_22 ( & V_25 -> V_28 , F_18 ) ;
}
