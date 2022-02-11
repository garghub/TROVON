void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned long V_4 , V_5 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
V_5 = F_3 ( V_6 ) ;
if ( V_5 == V_8 [ V_9 ] . V_5 )
V_4 = F_4 ( V_9 ) ;
else if ( V_5 == V_8 [ V_10 ] . V_5 )
V_4 = F_4 ( V_10 ) ;
else {
F_5 ( 1 , L_1 ) ;
return ;
}
F_6 ( V_2 -> V_11 , V_3 , V_4 , 0 ) ;
}
void F_7 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned long V_4 , V_5 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
V_5 = F_3 ( V_6 ) ;
if ( V_5 == V_8 [ V_9 ] . V_5 )
V_4 = F_4 ( V_9 ) ;
else if ( V_5 == V_8 [ V_10 ] . V_5 )
V_4 = F_4 ( V_10 ) ;
else {
F_5 ( 1 , L_1 ) ;
return ;
}
F_8 ( V_2 -> V_11 , V_3 , V_4 , 0 ) ;
}
unsigned long
F_9 ( struct V_12 * V_12 , unsigned long V_13 ,
unsigned long V_14 , unsigned long V_15 ,
unsigned long V_16 )
{
struct V_17 * V_18 = V_19 -> V_18 ;
struct V_1 * V_2 ;
struct V_6 * V_20 = F_2 ( V_12 ) ;
struct V_21 V_22 ;
if ( V_14 & ~ F_10 ( V_20 ) )
return - V_23 ;
if ( V_14 > V_24 )
return - V_25 ;
if ( V_16 & V_26 ) {
if ( F_11 ( V_12 , V_13 , V_14 ) )
return - V_23 ;
return V_13 ;
}
if ( V_13 ) {
V_13 = F_12 ( V_13 , F_13 ( V_20 ) ) ;
V_2 = F_14 ( V_18 , V_13 ) ;
if ( V_24 - V_14 >= V_13 &&
( ! V_2 || V_13 + V_14 <= V_2 -> V_27 ) )
return V_13 ;
}
V_22 . V_16 = V_28 ;
V_22 . V_29 = V_14 ;
V_22 . V_30 = V_31 ;
V_22 . V_32 = V_19 -> V_18 -> V_33 ;
V_22 . V_34 = V_35 & ~ F_10 ( V_20 ) ;
V_22 . V_36 = 0 ;
return F_15 ( & V_22 ) ;
}
