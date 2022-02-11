void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
if ( ! V_4 -> V_7 )
return;
if ( V_2 -> V_8 ) {
unsigned V_9 = V_4 -> V_10 . V_9 << V_11 ;
V_2 -> V_8 -> V_12 -> V_13 ( V_2 -> V_8 , V_4 -> V_7 , V_6 , V_9 ) ;
}
F_2 ( & V_4 -> V_10 ) ;
V_4 -> V_7 = 0 ;
}
int
F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , int V_14 )
{
int V_15 ;
if ( F_4 ( F_5 ( & V_4 -> V_10 ) ) )
return 0 ;
V_15 = F_6 ( & V_2 -> V_16 , & V_4 -> V_10 , V_14 ,
0 , V_17 ) ;
if ( V_15 )
return V_15 ;
V_4 -> V_7 = V_4 -> V_10 . V_18 << V_11 ;
if ( V_2 -> V_8 ) {
unsigned V_9 = V_14 << V_11 ;
V_15 = V_2 -> V_8 -> V_12 -> V_19 ( V_2 -> V_8 , V_4 -> V_7 , V_6 ,
V_9 , V_20 | V_21 ) ;
}
return V_15 ;
}
void
F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_8 )
V_2 -> V_8 -> V_12 -> V_22 ( V_2 -> V_8 ) ;
F_9 ( V_2 ) ;
}
struct V_1 *
F_10 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return F_12 ( - V_29 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_8 = F_13 ( V_24 , V_26 ) ;
F_14 ( & V_2 -> V_16 , ( V_26 -> V_30 . V_31 >> V_11 ) ,
( V_26 -> V_30 . V_32 >> V_11 ) - 1 ) ;
return V_2 ;
}
