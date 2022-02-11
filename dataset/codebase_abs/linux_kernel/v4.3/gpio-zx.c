static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 = V_3 -> V_7 + V_4 ;
if ( V_5 -> V_8 )
return F_4 ( V_6 ) ;
return 0 ;
}
static void F_5 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 = V_3 -> V_7 + V_4 ;
if ( V_5 -> V_8 )
F_6 ( V_6 ) ;
}
static int F_7 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_9 ;
T_1 V_10 ;
if ( V_4 >= V_3 -> V_11 )
return - V_12 ;
F_8 ( & V_5 -> V_13 , V_9 ) ;
V_10 = F_9 ( V_5 -> V_7 + V_14 ) ;
V_10 &= ~ F_10 ( V_4 ) ;
F_11 ( V_10 , V_5 -> V_7 + V_14 ) ;
F_12 ( & V_5 -> V_13 , V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , unsigned V_4 ,
int V_15 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_9 ;
T_1 V_10 ;
if ( V_4 >= V_3 -> V_11 )
return - V_12 ;
F_8 ( & V_5 -> V_13 , V_9 ) ;
V_10 = F_9 ( V_5 -> V_7 + V_14 ) ;
V_10 |= F_10 ( V_4 ) ;
F_11 ( V_10 , V_5 -> V_7 + V_14 ) ;
if ( V_15 )
F_11 ( F_10 ( V_4 ) , V_5 -> V_7 + V_16 ) ;
else
F_11 ( F_10 ( V_4 ) , V_5 -> V_7 + V_17 ) ;
F_12 ( & V_5 -> V_13 , V_9 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return ! ! ( F_9 ( V_5 -> V_7 + V_18 ) & F_10 ( V_4 ) ) ;
}
static void F_15 ( struct V_2 * V_3 , unsigned V_4 , int V_15 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_15 )
F_11 ( F_10 ( V_4 ) , V_5 -> V_7 + V_16 ) ;
else
F_11 ( F_10 ( V_4 ) , V_5 -> V_7 + V_17 ) ;
}
static int F_16 ( struct V_19 * V_20 , unsigned V_21 )
{
struct V_2 * V_3 = F_17 ( V_20 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_4 = F_18 ( V_20 ) ;
unsigned long V_9 ;
T_1 V_22 , V_23 , V_24 , V_25 ;
T_1 V_26 = F_10 ( V_4 ) ;
if ( V_4 < 0 || V_4 >= V_27 )
return - V_12 ;
F_8 ( & V_5 -> V_13 , V_9 ) ;
V_25 = F_9 ( V_5 -> V_7 + V_28 ) ;
V_22 = F_9 ( V_5 -> V_7 + V_29 ) ;
V_23 = F_9 ( V_5 -> V_7 + V_30 ) ;
V_24 = F_9 ( V_5 -> V_7 + V_31 ) ;
if ( V_21 & ( V_32 | V_33 ) ) {
V_22 |= V_26 ;
if ( V_21 & V_32 )
V_25 |= V_26 ;
else
V_25 &= ~ V_26 ;
} else
V_22 &= ~ V_26 ;
if ( ( V_21 & V_34 ) == V_34 ) {
V_23 |= V_26 ;
V_24 |= V_26 ;
} else {
if ( V_21 & V_35 ) {
V_23 |= V_26 ;
V_24 &= ~ V_26 ;
} else if ( V_21 & V_36 ) {
V_24 |= V_26 ;
V_23 &= ~ V_26 ;
}
}
F_11 ( V_22 , V_5 -> V_7 + V_29 ) ;
F_11 ( V_23 , V_5 -> V_7 + V_30 ) ;
F_11 ( V_24 , V_5 -> V_7 + V_31 ) ;
F_11 ( V_25 , V_5 -> V_7 + V_28 ) ;
F_12 ( & V_5 -> V_13 , V_9 ) ;
return 0 ;
}
static void F_19 ( struct V_37 * V_38 )
{
unsigned long V_39 ;
int V_4 ;
struct V_2 * V_3 = F_20 ( V_38 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_40 * V_41 = F_21 ( V_38 ) ;
F_22 ( V_41 , V_38 ) ;
V_39 = F_9 ( V_5 -> V_7 + V_42 ) ;
F_11 ( V_39 , V_5 -> V_7 + V_43 ) ;
if ( V_39 ) {
F_23 (offset, &pending, ZX_GPIO_NR)
F_24 ( F_25 ( V_3 -> V_44 ,
V_4 ) ) ;
}
F_26 ( V_41 , V_38 ) ;
}
static void F_27 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_17 ( V_20 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_45 = F_10 ( F_18 ( V_20 ) % V_27 ) ;
T_1 V_46 ;
F_28 ( & V_5 -> V_13 ) ;
V_46 = F_9 ( V_5 -> V_7 + V_47 ) | V_45 ;
F_11 ( V_46 , V_5 -> V_7 + V_47 ) ;
V_46 = F_9 ( V_5 -> V_7 + V_48 ) & ~ V_45 ;
F_11 ( V_46 , V_5 -> V_7 + V_48 ) ;
F_29 ( & V_5 -> V_13 ) ;
}
static void F_30 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_17 ( V_20 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_45 = F_10 ( F_18 ( V_20 ) % V_27 ) ;
T_1 V_46 ;
F_28 ( & V_5 -> V_13 ) ;
V_46 = F_9 ( V_5 -> V_7 + V_47 ) & ~ V_45 ;
F_11 ( V_46 , V_5 -> V_7 + V_47 ) ;
V_46 = F_9 ( V_5 -> V_7 + V_48 ) | V_45 ;
F_11 ( V_46 , V_5 -> V_7 + V_48 ) ;
F_29 ( & V_5 -> V_13 ) ;
}
static int F_31 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = & V_50 -> V_52 ;
struct V_1 * V_5 ;
struct V_53 * V_54 ;
int V_55 , V_56 , V_57 ;
V_5 = F_32 ( V_52 , sizeof( * V_5 ) , V_58 ) ;
if ( ! V_5 )
return - V_59 ;
V_54 = F_33 ( V_50 , V_60 , 0 ) ;
V_5 -> V_7 = F_34 ( V_52 , V_54 ) ;
if ( F_35 ( V_5 -> V_7 ) )
return F_36 ( V_5 -> V_7 ) ;
F_37 ( & V_5 -> V_13 ) ;
if ( F_38 ( V_52 -> V_61 , L_1 ) )
V_5 -> V_8 = true ;
V_56 = F_39 ( V_52 -> V_61 , L_2 ) ;
V_5 -> V_3 . V_62 = F_3 ;
V_5 -> V_3 . free = F_5 ;
V_5 -> V_3 . V_63 = F_7 ;
V_5 -> V_3 . V_64 = F_13 ;
V_5 -> V_3 . V_65 = F_14 ;
V_5 -> V_3 . V_66 = F_15 ;
V_5 -> V_3 . V_7 = V_27 * V_56 ;
V_5 -> V_3 . V_11 = V_27 ;
V_5 -> V_3 . V_67 = F_40 ( V_52 ) ;
V_5 -> V_3 . V_52 = V_52 ;
V_5 -> V_3 . V_68 = V_69 ;
V_57 = F_41 ( & V_5 -> V_3 ) ;
if ( V_57 )
return V_57 ;
F_11 ( 0xffff , V_5 -> V_7 + V_47 ) ;
F_11 ( 0 , V_5 -> V_7 + V_48 ) ;
V_55 = F_42 ( V_50 , 0 ) ;
if ( V_55 < 0 ) {
F_43 ( V_52 , L_3 ) ;
F_44 ( & V_5 -> V_3 ) ;
return - V_70 ;
}
V_57 = F_45 ( & V_5 -> V_3 , & V_71 ,
0 , V_72 ,
V_73 ) ;
if ( V_57 ) {
F_43 ( V_52 , L_4 ) ;
F_44 ( & V_5 -> V_3 ) ;
return V_57 ;
}
F_46 ( & V_5 -> V_3 , & V_71 ,
V_55 , F_19 ) ;
F_47 ( V_50 , V_5 ) ;
F_48 ( V_52 , L_5 ) ;
return 0 ;
}
