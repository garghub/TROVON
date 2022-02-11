int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 -> V_5 . V_6 ;
T_1 V_7 = V_3 - 1 ;
struct V_8 * V_9 = & V_2 -> V_10 . V_9 ;
if ( ! F_2 ( V_3 ) )
return - V_11 ;
V_9 -> V_12 = 0 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = V_3 ;
V_9 -> V_7 = V_7 ;
F_3 ( & V_9 -> V_15 ) ;
V_9 -> V_16 = F_4 ( F_5 ( V_3 ) , sizeof( long ) , V_17 ) ;
if ( ! V_9 -> V_16 )
return - V_18 ;
F_6 ( 0 , V_9 -> V_16 ) ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_10 . V_9 ;
F_8 ( V_9 -> V_16 ) ;
}
int F_9 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_8 * V_9 ;
unsigned long V_21 ;
T_1 V_22 ;
V_9 = & V_2 -> V_10 . V_9 ;
F_10 ( & V_9 -> V_15 , V_21 ) ;
V_22 = F_11 ( V_9 -> V_16 , V_9 -> V_14 , V_9 -> V_12 ) ;
if ( V_22 >= V_9 -> V_14 ) {
V_9 -> V_13 = ( V_9 -> V_13 + V_9 -> V_14 ) & V_9 -> V_7 ;
V_22 = F_12 ( V_9 -> V_16 , V_9 -> V_14 ) ;
}
if ( V_22 >= V_9 -> V_14 ) {
F_13 ( & V_9 -> V_15 , V_21 ) ;
return - V_18 ;
}
F_6 ( V_22 , V_9 -> V_16 ) ;
V_22 |= V_9 -> V_13 ;
F_13 ( & V_9 -> V_15 , V_21 ) ;
V_20 -> V_23 = V_22 ;
V_20 -> V_24 = ( F_14 ( V_2 -> V_25 , V_26 ) >>
V_27 ) + V_20 -> V_23 ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_8 * V_9 = & V_2 -> V_10 . V_9 ;
unsigned long V_21 ;
T_1 V_22 ;
V_22 = V_20 -> V_23 & ( V_9 -> V_14 - 1 ) ;
F_10 ( & V_9 -> V_15 , V_21 ) ;
F_16 ( V_22 , V_9 -> V_16 ) ;
V_9 -> V_12 = F_17 ( V_9 -> V_12 , V_22 ) ;
V_9 -> V_13 = ( V_9 -> V_13 + V_9 -> V_14 ) & V_9 -> V_7 ;
F_13 ( & V_9 -> V_15 , V_21 ) ;
}
