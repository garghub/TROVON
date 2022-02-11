static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_6 , V_5 -> V_7 , F_4 ( V_5 -> V_8 ) ,
V_3 ? F_4 ( V_5 -> V_8 ) : 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , 1 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 , 0 ) < 0 )
F_7 ( L_1 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_9 ;
if ( F_9 ( V_5 -> V_6 , V_5 -> V_7 , & V_9 ) < 0 )
F_7 ( L_2 ) ;
return ! ! ( V_9 & F_4 ( V_5 -> V_8 ) ) ;
}
struct V_1 * F_10 ( struct V_10 * V_11 ,
struct V_6 * V_6 ,
const char * V_12 ,
const struct V_13 * V_14 )
{
struct V_4 * V_5 ;
struct V_15 V_16 ;
int V_17 ;
V_5 = F_11 ( V_11 , sizeof( * V_5 ) , V_18 ) ;
if ( ! V_5 )
return F_12 ( - V_19 ) ;
V_16 . V_12 = V_12 ;
V_16 . V_20 = & V_21 ;
V_16 . V_22 = V_14 -> V_23 ? V_24 : 0 ;
V_16 . V_25 = V_14 -> V_23 ? & V_14 -> V_23 : NULL ;
V_16 . V_26 = V_14 -> V_23 ? 1 : 0 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_7 = V_14 -> V_7 ;
V_5 -> V_8 = V_14 -> V_8 ;
V_5 -> V_2 . V_16 = & V_16 ;
V_17 = F_13 ( V_11 , & V_5 -> V_2 ) ;
if ( V_17 )
return F_12 ( V_17 ) ;
return & V_5 -> V_2 ;
}
