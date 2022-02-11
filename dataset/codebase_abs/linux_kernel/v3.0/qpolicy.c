static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 , V_4 ) ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) -> V_6 &&
V_2 -> V_5 . V_7 >= F_4 ( V_2 ) -> V_6 ;
}
static struct V_3 * F_5 ( struct V_1 * V_2 )
{
return F_6 ( & V_2 -> V_5 ) ;
}
static struct V_3 * F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_8 = NULL ;
F_8 (&sk->sk_write_queue, skb)
if ( V_8 == NULL || V_4 -> V_9 > V_8 -> V_9 )
V_8 = V_4 ;
return V_8 ;
}
static struct V_3 * F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_10 = NULL ;
F_8 (&sk->sk_write_queue, skb)
if ( V_10 == NULL || V_4 -> V_9 < V_10 -> V_9 )
V_10 = V_4 ;
return V_10 ;
}
static bool F_10 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) )
F_11 ( V_2 , F_9 ( V_2 ) ) ;
return false ;
}
void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_11 [ F_4 ( V_2 ) -> V_12 ] . F_13 ( V_2 , V_4 ) ;
}
bool F_14 ( struct V_1 * V_2 )
{
return V_11 [ F_4 ( V_2 ) -> V_12 ] . F_15 ( V_2 ) ;
}
void F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 != NULL ) {
F_16 ( V_4 , & V_2 -> V_5 ) ;
F_17 ( V_4 ) ;
}
}
struct V_3 * F_18 ( struct V_1 * V_2 )
{
return V_11 [ F_4 ( V_2 ) -> V_12 ] . F_19 ( V_2 ) ;
}
struct V_3 * F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_18 ( V_2 ) ;
if ( V_4 != NULL ) {
V_4 -> V_9 = 0 ;
F_16 ( V_4 , & V_2 -> V_5 ) ;
}
return V_4 ;
}
bool F_21 ( struct V_1 * V_2 , T_1 V_13 )
{
if ( ! V_13 || ( V_13 & ( V_13 - 1 ) ) )
return false ;
return ( V_11 [ F_4 ( V_2 ) -> V_12 ] . V_14 & V_13 ) == V_13 ;
}
