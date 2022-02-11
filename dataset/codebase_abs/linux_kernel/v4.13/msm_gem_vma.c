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
if ( ! V_3 || ! V_9 -> V_12 )
return;
if ( V_3 -> V_5 ) {
unsigned V_13 = V_9 -> V_14 . V_13 << V_15 ;
V_3 -> V_5 -> V_6 -> V_16 ( V_3 -> V_5 , V_9 -> V_12 , V_11 , V_13 ) ;
}
F_8 ( & V_3 -> V_17 ) ;
F_9 ( & V_9 -> V_14 ) ;
F_10 ( & V_3 -> V_17 ) ;
V_9 -> V_12 = 0 ;
F_5 ( V_3 ) ;
}
int
F_11 ( struct V_2 * V_3 ,
struct V_8 * V_9 , struct V_10 * V_11 , int V_18 )
{
int V_19 ;
F_8 ( & V_3 -> V_17 ) ;
if ( F_12 ( F_13 ( & V_9 -> V_14 ) ) ) {
F_10 ( & V_3 -> V_17 ) ;
return 0 ;
}
V_19 = F_14 ( & V_3 -> V_4 , & V_9 -> V_14 , V_18 ) ;
F_10 ( & V_3 -> V_17 ) ;
if ( V_19 )
return V_19 ;
V_9 -> V_12 = V_9 -> V_14 . V_20 << V_15 ;
if ( V_3 -> V_5 ) {
unsigned V_13 = V_18 << V_15 ;
V_19 = V_3 -> V_5 -> V_6 -> V_21 ( V_3 -> V_5 , V_9 -> V_12 , V_11 ,
V_13 , V_22 | V_23 ) ;
}
F_15 ( & V_3 -> V_1 ) ;
return V_19 ;
}
struct V_2 *
F_16 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 )
{
struct V_2 * V_3 ;
V_3 = F_17 ( sizeof( * V_3 ) , V_29 ) ;
if ( ! V_3 )
return F_18 ( - V_30 ) ;
F_19 ( & V_3 -> V_17 ) ;
V_3 -> V_28 = V_28 ;
V_3 -> V_5 = F_20 ( V_25 , V_27 ) ;
F_21 ( & V_3 -> V_4 , ( V_27 -> V_31 . V_32 >> V_15 ) ,
( V_27 -> V_31 . V_33 >> V_15 ) - 1 ) ;
F_22 ( & V_3 -> V_1 ) ;
return V_3 ;
}
