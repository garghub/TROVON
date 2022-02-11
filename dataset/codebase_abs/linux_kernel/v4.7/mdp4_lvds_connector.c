static enum V_1 F_1 (
struct V_2 * V_3 , bool V_4 )
{
struct V_5 * V_5 =
F_2 ( V_3 ) ;
if ( ! V_5 -> V_6 )
V_5 -> V_6 =
F_3 ( V_5 -> V_7 ) ;
return V_5 -> V_6 ?
V_8 :
V_9 ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_5 * V_5 =
F_2 ( V_3 ) ;
F_5 ( V_3 ) ;
F_6 ( V_5 ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_5 * V_5 =
F_2 ( V_3 ) ;
struct V_10 * V_6 = V_5 -> V_6 ;
int V_11 = 0 ;
if ( V_6 ) {
F_8 ( V_6 , V_3 ) ;
V_11 = V_6 -> V_12 -> V_13 ( V_6 ) ;
F_9 ( V_6 ) ;
}
return V_11 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_5 * V_5 =
F_2 ( V_3 ) ;
struct V_16 * V_17 = V_5 -> V_17 ;
long V_18 , V_19 ;
V_19 = 1000 * V_15 -> clock ;
V_18 = F_11 ( V_17 , V_19 ) ;
F_12 ( L_1 , V_19 , V_18 ) ;
if ( V_18 != V_19 )
return V_20 ;
return V_21 ;
}
static struct V_16 *
F_13 ( struct V_2 * V_3 )
{
struct V_5 * V_5 =
F_2 ( V_3 ) ;
return V_5 -> V_17 ;
}
struct V_2 * F_14 ( struct V_22 * V_23 ,
struct V_24 * V_7 , struct V_16 * V_17 )
{
struct V_2 * V_3 = NULL ;
struct V_5 * V_5 ;
V_5 = F_15 ( sizeof( * V_5 ) , V_25 ) ;
if ( ! V_5 )
return F_16 ( - V_26 ) ;
V_5 -> V_17 = V_17 ;
V_5 -> V_7 = V_7 ;
V_3 = & V_5 -> V_27 ;
F_17 ( V_23 , V_3 , & V_28 ,
V_29 ) ;
F_18 ( V_3 , & V_30 ) ;
V_3 -> V_31 = 0 ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = 0 ;
F_19 ( V_3 , V_17 ) ;
return V_3 ;
}
