void
F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
V_2 -> V_3 -> V_4 ( V_2 ) ;
}
void
F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_5 )
V_2 -> V_3 -> V_5 ( V_2 ) ;
}
void
F_3 ( struct V_1 * * V_6 )
{
struct V_1 * V_2 = * V_6 ;
if ( V_2 && ! F_4 ( ! V_2 -> V_3 ) ) {
if ( V_2 -> V_3 -> V_7 )
* V_6 = V_2 -> V_3 -> V_7 ( V_2 ) ;
F_5 ( * V_6 ) ;
* V_6 = NULL ;
}
}
void
F_6 ( const struct V_8 * V_3 , struct V_9 * V_10 ,
int V_11 , struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_14 * V_15 = V_10 -> V_16 . V_17 . V_18 -> V_15 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_19 = * V_13 ;
V_2 -> V_15 = F_7 ( V_15 , V_13 -> V_20 ) ;
V_2 -> V_21 = F_8 ( V_2 -> V_19 . V_21 ) - 1 ;
F_9 ( V_2 , L_1
L_2 ,
V_2 -> V_19 . type , V_2 -> V_19 . V_22 , V_2 -> V_19 . V_21 ,
V_2 -> V_19 . type >= 2 ? V_2 -> V_19 . V_23 . V_24 : 0 ,
V_2 -> V_19 . V_25 , V_2 -> V_19 . V_20 ,
V_2 -> V_19 . V_26 , V_2 -> V_19 . V_27 ) ;
}
int
F_10 ( const struct V_8 * V_3 ,
struct V_9 * V_10 , int V_11 , struct V_12 * V_13 ,
struct V_1 * * V_6 )
{
if ( ! ( * V_6 = F_11 ( sizeof( * * V_6 ) , V_28 ) ) )
return - V_29 ;
F_6 ( V_3 , V_10 , V_11 , V_13 , * V_6 ) ;
return 0 ;
}
