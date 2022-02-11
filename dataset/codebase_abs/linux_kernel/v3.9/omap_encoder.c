static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
F_4 ( V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_4 )
{
}
static bool F_6 ( struct V_1 * V_2 ,
const struct V_5 * V_4 ,
struct V_5 * V_6 )
{
return true ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_5 * V_4 ,
struct V_5 * V_6 )
{
}
static void F_8 ( struct V_1 * V_2 )
{
}
static void F_9 ( struct V_1 * V_2 )
{
}
int F_10 ( struct V_1 * V_2 , bool V_7 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_7 ) {
return V_11 -> V_13 ( V_9 ) ;
} else {
V_11 -> V_14 ( V_9 ) ;
return 0 ;
}
}
int F_11 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_21 ;
V_9 -> V_22 -> V_23 = V_16 ;
V_21 = V_11 -> V_24 ( V_9 , V_18 ) ;
if ( V_21 ) {
F_12 ( V_20 -> V_20 , L_1 , V_21 ) ;
return V_21 ;
}
V_11 -> V_25 ( V_9 , V_18 ) ;
return 0 ;
}
struct V_1 * F_13 ( struct V_19 * V_20 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
V_3 = F_14 ( sizeof( * V_3 ) , V_26 ) ;
if ( ! V_3 )
goto V_27;
V_3 -> V_9 = V_9 ;
V_2 = & V_3 -> V_28 ;
F_15 ( V_20 , V_2 , & V_29 ,
V_30 ) ;
F_16 ( V_2 , & V_31 ) ;
return V_2 ;
V_27:
if ( V_2 )
F_1 ( V_2 ) ;
return NULL ;
}
