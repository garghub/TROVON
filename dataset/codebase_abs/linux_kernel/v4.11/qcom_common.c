struct V_1 * F_1 ( struct V_2 * V_2 ,
const struct V_3 * V_4 ,
int * V_5 )
{
static struct V_1 V_6 = { . V_7 = 1 , } ;
* V_5 = sizeof( V_6 ) ;
return & V_6 ;
}
static int F_2 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
V_11 -> V_12 = F_4 ( V_11 -> V_13 , V_11 -> V_14 ) ;
return F_5 ( V_11 -> V_12 ) ? F_6 ( V_11 -> V_12 ) : 0 ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
F_8 ( V_11 -> V_12 ) ;
V_11 -> V_12 = NULL ;
}
void F_9 ( struct V_2 * V_2 , struct V_10 * V_11 )
{
struct V_15 * V_13 = & V_2 -> V_13 ;
V_11 -> V_14 = F_10 ( V_13 -> V_16 -> V_17 , L_1 ) ;
if ( ! V_11 -> V_14 )
return;
V_11 -> V_13 = V_13 ;
F_11 ( V_2 , & V_11 -> V_9 , F_2 , F_7 ) ;
}
void F_12 ( struct V_2 * V_2 , struct V_10 * V_11 )
{
F_13 ( V_2 , & V_11 -> V_9 ) ;
F_14 ( V_11 -> V_14 ) ;
}
