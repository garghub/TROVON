static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_3 ( V_2 -> V_8 , L_1 , V_3 ) ;
F_4 ( & V_5 -> V_9 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_10 + V_11 ) ;
if ( V_7 & F_6 ( V_3 ) ) {
F_7 ( V_2 -> V_8 , L_2 ,
V_3 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
return - V_12 ;
}
F_9 ( V_7 | F_6 ( V_3 ) , V_5 -> V_10 + V_11 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_4 ( & V_5 -> V_9 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_10 + V_11 ) ;
V_7 &= ~ F_6 ( V_3 ) ;
F_9 ( V_7 , V_5 -> V_10 + V_11 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
F_3 ( V_2 -> V_8 , L_3 , V_3 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned V_3 , int V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_14 ;
F_3 ( V_2 -> V_8 , L_4 ,
V_3 , V_13 ) ;
F_4 ( & V_5 -> V_9 , V_6 ) ;
V_14 = F_5 ( V_5 -> V_10 + V_15 ) ;
V_14 &= ~ F_6 ( V_3 ) ;
if ( V_13 )
V_14 |= F_6 ( V_3 ) ;
F_9 ( V_14 , V_5 -> V_10 + V_15 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_14 ;
F_4 ( & V_5 -> V_9 , V_6 ) ;
V_14 = F_5 ( V_5 -> V_10 + V_16 ) ;
if ( V_14 & F_6 ( V_3 ) )
V_14 = F_5 ( V_5 -> V_10 + V_15 ) ;
else
V_14 = F_5 ( V_5 -> V_10 + V_17 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
V_14 >>= V_3 ;
V_14 &= 1 ;
F_3 ( V_2 -> V_8 , L_5 ,
V_3 , V_14 ) ;
return V_14 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_14 ;
F_3 ( V_2 -> V_8 , L_6 , V_3 ) ;
F_4 ( & V_5 -> V_9 , V_6 ) ;
V_14 = F_5 ( V_5 -> V_10 + V_16 ) ;
V_14 &= ~ F_6 ( V_3 ) ;
F_9 ( V_14 , V_5 -> V_10 + V_16 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_3 , int V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_14 ;
F_3 ( V_2 -> V_8 , L_7 ,
V_3 , V_13 ) ;
F_4 ( & V_5 -> V_9 , V_6 ) ;
V_14 = F_5 ( V_5 -> V_10 + V_15 ) ;
if ( V_13 )
V_14 |= F_6 ( V_3 ) ;
else
V_14 &= ~ F_6 ( V_3 ) ;
F_9 ( V_14 , V_5 -> V_10 + V_15 ) ;
V_14 = F_5 ( V_5 -> V_10 + V_16 ) ;
V_14 |= F_6 ( V_3 ) ;
F_9 ( V_14 , V_5 -> V_10 + V_16 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_21 ;
struct V_22 * V_23 ;
T_2 V_24 = F_16 ( V_21 ) ;
struct V_4 * V_5 ;
struct V_25 * V_26 ;
int V_27 = 0 ;
if ( F_17 ( V_24 , & V_23 ) ) {
F_18 ( V_21 , L_8 ) ;
return - V_28 ;
}
V_5 = F_19 ( V_21 , sizeof( struct V_4 ) , V_29 ) ;
if ( ! V_5 )
return - V_30 ;
V_26 = F_20 ( V_19 , V_31 , 0 ) ;
if ( ! V_26 ) {
F_18 ( & V_19 -> V_21 , L_9 ) ;
return - V_12 ;
}
V_5 -> V_10 = F_21 ( V_21 , V_26 ) ;
if ( F_22 ( V_5 -> V_10 ) ) {
F_18 ( & V_19 -> V_21 , L_10 ) ;
return F_23 ( V_5 -> V_10 ) ;
}
F_24 ( & V_5 -> V_9 ) ;
V_5 -> V_2 . V_32 = V_19 -> V_33 ;
V_5 -> V_2 . V_34 = V_35 ;
V_5 -> V_2 . V_8 = V_21 ;
V_5 -> V_2 . V_36 = F_1 ;
V_5 -> V_2 . free = F_10 ;
V_5 -> V_2 . V_37 = F_13 ;
V_5 -> V_2 . V_38 = F_14 ;
V_5 -> V_2 . V_39 = F_12 ;
V_5 -> V_2 . V_40 = F_11 ;
V_5 -> V_2 . V_41 = - 1 ;
V_5 -> V_2 . V_42 = V_43 ;
#if F_25 ( V_44 )
V_5 -> V_2 . V_45 = V_19 -> V_21 . V_45 ;
#endif
V_27 = F_26 ( & V_5 -> V_2 , V_5 ) ;
if ( V_27 ) {
F_18 ( & V_19 -> V_21 , L_11 ) ;
return V_27 ;
}
F_27 ( V_19 , V_5 ) ;
F_9 ( 0 , V_5 -> V_10 + V_11 ) ;
F_9 ( 0 , V_5 -> V_10 + V_46 ) ;
F_3 ( & V_19 -> V_21 , L_12 ) ;
return V_27 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = F_29 ( V_19 ) ;
F_30 ( & V_5 -> V_2 ) ;
return 0 ;
}
