static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ,
F_3 ( F_4 ( V_2 ) ,
F_5 ( V_2 ) ) ) ;
if ( V_4 == NULL )
return - V_6 ;
F_6 ( & V_4 -> V_7 ) ;
V_2 -> V_8 = V_4 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_8 ( V_4 != NULL ) ;
F_8 ( F_9 ( & V_4 -> V_7 ) ) ;
F_10 ( V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_11 * * V_13 , bool V_14 )
{
* V_13 = & ( (struct V_3 * ) V_2 -> V_8 ) -> V_15 ;
return 1 ;
}
static
struct V_9 * F_12 ( struct V_1 * V_2 ,
bool V_16 , bool V_17 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
struct V_9 * V_10 ;
V_10 = F_13 ( F_9 ( & V_4 -> V_7 ) ) ? NULL :
F_14 ( V_4 -> V_7 . V_18 , struct V_9 ,
V_19 . V_20 . V_21 ) ;
if ( F_15 ( ! V_16 && V_10 != NULL ) ) {
struct V_22 * V_23 = F_16 ( V_10 ,
struct V_22 ,
V_24 ) ;
F_17 ( & V_10 -> V_19 . V_20 . V_21 ) ;
F_18 ( V_25 , L_1 ,
V_2 -> V_26 -> V_27 , F_19 ( V_23 -> V_28 ) ,
V_10 -> V_19 . V_20 . V_29 ) ;
}
return V_10 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 ;
V_4 = F_16 ( F_21 ( V_10 ) , struct V_3 ,
V_15 ) ;
V_10 -> V_19 . V_20 . V_29 = V_4 -> V_30 ++ ;
F_22 ( & V_10 -> V_19 . V_20 . V_21 , & V_4 -> V_7 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
F_8 ( ! F_9 ( & V_10 -> V_19 . V_20 . V_21 ) ) ;
F_17 ( & V_10 -> V_19 . V_20 . V_21 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_22 * V_23 = F_16 ( V_10 , struct V_22 ,
V_24 ) ;
F_18 ( V_25 , L_2 ,
V_2 -> V_26 -> V_27 , F_19 ( V_23 -> V_28 ) ,
V_10 -> V_19 . V_20 . V_29 ) ;
}
