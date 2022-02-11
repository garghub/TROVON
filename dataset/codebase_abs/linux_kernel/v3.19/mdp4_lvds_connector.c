static enum V_1 F_1 (
struct V_2 * V_3 , bool V_4 )
{
struct V_5 * V_5 =
F_2 ( V_3 ) ;
return V_5 -> V_6 ?
V_7 :
V_8 ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_5 * V_5 =
F_2 ( V_3 ) ;
struct V_9 * V_6 = V_5 -> V_6 ;
if ( V_6 )
F_4 ( V_6 ) ;
F_5 ( V_3 ) ;
F_6 ( V_3 ) ;
F_7 ( V_5 ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_5 * V_5 =
F_2 ( V_3 ) ;
struct V_9 * V_6 = V_5 -> V_6 ;
int V_10 = 0 ;
if ( V_6 )
V_10 = V_6 -> V_11 -> V_12 ( V_6 ) ;
return V_10 ;
}
static int F_9 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
struct V_5 * V_5 =
F_2 ( V_3 ) ;
struct V_15 * V_16 = V_5 -> V_16 ;
long V_17 , V_18 ;
V_18 = 1000 * V_14 -> clock ;
V_17 = F_10 ( V_16 , V_18 ) ;
F_11 ( L_1 , V_18 , V_17 ) ;
if ( V_17 != V_18 )
return V_19 ;
return V_20 ;
}
static struct V_15 *
F_12 ( struct V_2 * V_3 )
{
struct V_5 * V_5 =
F_2 ( V_3 ) ;
return V_5 -> V_16 ;
}
struct V_2 * F_13 ( struct V_21 * V_22 ,
struct V_9 * V_6 , struct V_15 * V_16 )
{
struct V_2 * V_3 = NULL ;
struct V_5 * V_5 ;
int V_10 ;
V_5 = F_14 ( sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 ) {
V_10 = - V_24 ;
goto V_25;
}
V_5 -> V_16 = V_16 ;
V_5 -> V_6 = V_6 ;
V_3 = & V_5 -> V_26 ;
F_15 ( V_22 , V_3 , & V_27 ,
V_28 ) ;
F_16 ( V_3 , & V_29 ) ;
V_3 -> V_30 = 0 ;
V_3 -> V_31 = 0 ;
V_3 -> V_32 = 0 ;
F_17 ( V_3 ) ;
F_18 ( V_3 , V_16 ) ;
if ( V_6 )
F_19 ( V_6 , V_3 ) ;
return V_3 ;
V_25:
if ( V_3 )
F_3 ( V_3 ) ;
return F_20 ( V_10 ) ;
}
