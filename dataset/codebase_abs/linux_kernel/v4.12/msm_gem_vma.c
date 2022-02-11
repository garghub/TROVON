static void
F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ,
struct V_2 , V_1 ) ;
F_3 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_5 )
V_3 -> V_5 -> V_6 -> V_7 ( V_3 -> V_5 ) ;
F_4 ( V_3 ) ;
}
void F_5 ( struct V_2 * V_3 )
{
if ( V_3 )
F_6 ( & V_3 -> V_1 , F_1 ) ;
}
void
F_7 ( struct V_2 * V_3 ,
struct V_8 * V_9 , struct V_10 * V_11 )
{
if ( ! V_9 -> V_12 )
return;
if ( V_3 -> V_5 ) {
unsigned V_13 = V_9 -> V_14 . V_13 << V_15 ;
V_3 -> V_5 -> V_6 -> V_16 ( V_3 -> V_5 , V_9 -> V_12 , V_11 , V_13 ) ;
}
F_8 ( & V_9 -> V_14 ) ;
V_9 -> V_12 = 0 ;
F_5 ( V_3 ) ;
}
int
F_9 ( struct V_2 * V_3 ,
struct V_8 * V_9 , struct V_10 * V_11 , int V_17 )
{
int V_18 ;
if ( F_10 ( F_11 ( & V_9 -> V_14 ) ) )
return 0 ;
V_18 = F_12 ( & V_3 -> V_4 , & V_9 -> V_14 , V_17 ) ;
if ( V_18 )
return V_18 ;
V_9 -> V_12 = V_9 -> V_14 . V_19 << V_15 ;
if ( V_3 -> V_5 ) {
unsigned V_13 = V_17 << V_15 ;
V_18 = V_3 -> V_5 -> V_6 -> V_20 ( V_3 -> V_5 , V_9 -> V_12 , V_11 ,
V_13 , V_21 | V_22 ) ;
}
F_13 ( & V_3 -> V_1 ) ;
return V_18 ;
}
struct V_2 *
F_14 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 )
{
struct V_2 * V_3 ;
V_3 = F_15 ( sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 )
return F_16 ( - V_29 ) ;
V_3 -> V_27 = V_27 ;
V_3 -> V_5 = F_17 ( V_24 , V_26 ) ;
F_18 ( & V_3 -> V_4 , ( V_26 -> V_30 . V_31 >> V_15 ) ,
( V_26 -> V_30 . V_32 >> V_15 ) - 1 ) ;
F_19 ( & V_3 -> V_1 ) ;
return V_3 ;
}
