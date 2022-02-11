static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
}
static enum V_6 F_6 ( struct V_1
* V_2 , bool V_7 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
return ( V_4 -> V_5 ?
V_8 :
V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
if ( ! V_4 -> V_5 )
return 0 ;
return F_8 ( V_4 -> V_5 ) ;
}
static struct V_10 * F_9 ( struct V_11 * V_12 )
{
struct V_13 * V_14 , * V_15 ;
struct V_13 * V_16 = V_12 -> V_17 ;
struct V_10 * V_5 ;
V_14 = F_10 ( V_16 , NULL ) ;
if ( ! V_14 ) {
F_11 ( V_12 , L_1 ) ;
return NULL ;
}
V_15 = F_12 ( V_14 ) ;
F_13 ( V_14 ) ;
if ( ! V_15 ) {
F_11 ( V_12 , L_2 ) ;
return NULL ;
}
V_5 = F_14 ( V_15 ) ;
F_13 ( V_15 ) ;
return V_5 ;
}
int F_15 ( struct V_18 * V_12 )
{
struct V_19 * V_20 = V_12 -> V_21 ;
struct V_3 * V_4 = & V_20 -> V_2 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
F_16 ( V_12 , V_2 , & V_22 ,
V_23 ) ;
F_17 ( V_2 , & V_24 ) ;
V_4 -> V_5 = F_9 ( V_12 -> V_12 ) ;
if ( V_4 -> V_5 )
F_18 ( V_4 -> V_5 , V_2 ) ;
return 0 ;
}
