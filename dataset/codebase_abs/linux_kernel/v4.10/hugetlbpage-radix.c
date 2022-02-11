void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_4 ;
struct V_5 * V_5 = F_2 ( V_2 -> V_6 ) ;
V_4 = F_3 ( V_5 ) ;
F_4 ( V_2 -> V_7 , V_3 , V_4 ) ;
}
void F_5 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_4 ;
struct V_5 * V_5 = F_2 ( V_2 -> V_6 ) ;
V_4 = F_3 ( V_5 ) ;
F_6 ( V_2 -> V_7 , V_3 , V_4 ) ;
}
void F_7 ( struct V_1 * V_2 , unsigned long V_8 ,
unsigned long V_9 )
{
int V_4 ;
struct V_5 * V_5 = F_2 ( V_2 -> V_6 ) ;
V_4 = F_3 ( V_5 ) ;
F_8 ( V_2 -> V_7 , V_8 , V_9 , V_4 ) ;
}
unsigned long
F_9 ( struct V_10 * V_10 , unsigned long V_11 ,
unsigned long V_12 , unsigned long V_13 ,
unsigned long V_14 )
{
struct V_15 * V_16 = V_17 -> V_16 ;
struct V_1 * V_2 ;
struct V_5 * V_18 = F_2 ( V_10 ) ;
struct V_19 V_20 ;
if ( V_12 & ~ F_10 ( V_18 ) )
return - V_21 ;
if ( V_12 > V_22 )
return - V_23 ;
if ( V_14 & V_24 ) {
if ( F_11 ( V_10 , V_11 , V_12 ) )
return - V_21 ;
return V_11 ;
}
if ( V_11 ) {
V_11 = F_12 ( V_11 , F_13 ( V_18 ) ) ;
V_2 = F_14 ( V_16 , V_11 ) ;
if ( V_22 - V_12 >= V_11 &&
( ! V_2 || V_11 + V_12 <= V_2 -> V_25 ) )
return V_11 ;
}
V_20 . V_14 = V_26 ;
V_20 . V_27 = V_12 ;
V_20 . V_28 = V_29 ;
V_20 . V_30 = V_17 -> V_16 -> V_31 ;
V_20 . V_32 = V_33 & ~ F_10 ( V_18 ) ;
V_20 . V_34 = 0 ;
return F_15 ( & V_20 ) ;
}
