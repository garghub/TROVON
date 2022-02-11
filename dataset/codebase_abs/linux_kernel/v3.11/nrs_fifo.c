static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( V_4 , F_3 ( V_2 ) , F_4 ( V_2 ) ) ;
if ( V_4 == NULL )
return - V_5 ;
F_5 ( & V_4 -> V_6 ) ;
V_2 -> V_7 = V_4 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_7 ;
F_7 ( V_4 != NULL ) ;
F_7 ( F_8 ( & V_4 -> V_6 ) ) ;
F_9 ( V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
const struct V_10 * V_11 ,
struct V_10 * * V_12 , bool V_13 )
{
* V_12 = & ( (struct V_3 * ) V_2 -> V_7 ) -> V_14 ;
return 1 ;
}
static
struct V_8 * F_11 ( struct V_1 * V_2 ,
bool V_15 , bool V_16 )
{
struct V_3 * V_4 = V_2 -> V_7 ;
struct V_8 * V_9 ;
V_9 = F_12 ( F_8 ( & V_4 -> V_6 ) ) ? NULL :
F_13 ( V_4 -> V_6 . V_17 , struct V_8 ,
V_18 . V_19 . V_20 ) ;
if ( F_14 ( ! V_15 && V_9 != NULL ) ) {
struct V_21 * V_22 = F_15 ( V_9 ,
struct V_21 ,
V_23 ) ;
F_16 ( & V_9 -> V_18 . V_19 . V_20 ) ;
F_17 ( V_24 , L_1 V_25
L_2 , V_2 -> V_26 -> V_27 ,
F_18 ( V_22 -> V_28 ) , V_9 -> V_18 . V_19 . V_29 ) ;
}
return V_9 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 ;
V_4 = F_15 ( F_20 ( V_9 ) , struct V_3 ,
V_14 ) ;
V_9 -> V_18 . V_19 . V_29 = V_4 -> V_30 ++ ;
F_21 ( & V_9 -> V_18 . V_19 . V_20 , & V_4 -> V_6 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_7 ( ! F_8 ( & V_9 -> V_18 . V_19 . V_20 ) ) ;
F_16 ( & V_9 -> V_18 . V_19 . V_20 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_21 * V_22 = F_15 ( V_9 , struct V_21 ,
V_23 ) ;
F_17 ( V_24 , L_3 V_25 L_2 ,
V_2 -> V_26 -> V_27 , F_18 ( V_22 -> V_28 ) ,
V_9 -> V_18 . V_19 . V_29 ) ;
}
