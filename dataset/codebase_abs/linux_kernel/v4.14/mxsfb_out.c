static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 =
F_1 ( V_3 ) ;
if ( V_4 -> V_5 )
return V_4 -> V_5 -> V_6 -> V_7 ( V_4 -> V_5 ) ;
return 0 ;
}
static enum V_8
F_4 ( struct V_2 * V_3 , bool V_9 )
{
struct V_1 * V_4 =
F_1 ( V_3 ) ;
if ( V_4 -> V_5 )
return V_10 ;
return V_11 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 =
F_1 ( V_3 ) ;
if ( V_4 -> V_5 )
F_6 ( V_4 -> V_5 ) ;
F_7 ( V_3 ) ;
F_8 ( V_3 ) ;
}
int F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_14 ;
struct V_15 * V_5 ;
int V_16 ;
V_16 = F_10 ( V_13 -> V_17 -> V_18 , 0 , 0 , & V_5 , NULL ) ;
if ( V_16 )
return V_16 ;
V_4 -> V_3 . V_19 = V_20 ;
V_4 -> V_3 . V_21 = 0 ;
F_11 ( & V_4 -> V_3 ,
& V_22 ) ;
V_16 = F_12 ( V_13 , & V_4 -> V_3 ,
& V_23 ,
V_24 ) ;
if ( ! V_16 )
V_4 -> V_5 = V_5 ;
return V_16 ;
}
