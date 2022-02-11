static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 )
{
}
static void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
}
static T_1 * F_3 ( struct V_1 * V_2 , unsigned long V_8 )
{
return NULL ;
}
static struct V_9 * F_4 ( const struct V_1 * V_2 ,
struct V_5 * V_6 ,
const void * V_10 )
{
return NULL ;
}
static unsigned int F_5 ( const struct V_1 * V_2 )
{
return V_2 -> V_11 -> V_7 ;
}
void F_6 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_13 -> V_16 ;
F_7 ( & V_15 -> V_2 . V_17 , 1 ) ;
V_15 -> V_2 . V_11 = V_13 -> V_11 ;
V_15 -> V_2 . V_18 = & V_15 -> V_2 ;
F_8 ( & V_15 -> V_2 , V_19 , true ) ;
V_15 -> V_2 . V_20 = V_21 | V_22 ;
V_15 -> V_2 . V_23 = & V_24 ;
}
int T_2 F_9 ( void )
{
return F_10 ( & V_24 ) ;
}
void F_11 ( void )
{
F_12 ( & V_24 ) ;
}
