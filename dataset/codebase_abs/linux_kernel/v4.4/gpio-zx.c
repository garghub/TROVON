static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
if ( V_4 >= V_3 -> V_8 )
return - V_9 ;
F_4 ( & V_5 -> V_10 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_11 + V_12 ) ;
V_7 &= ~ F_6 ( V_4 ) ;
F_7 ( V_7 , V_5 -> V_11 + V_12 ) ;
F_8 ( & V_5 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_4 ,
int V_13 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
if ( V_4 >= V_3 -> V_8 )
return - V_9 ;
F_4 ( & V_5 -> V_10 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_11 + V_12 ) ;
V_7 |= F_6 ( V_4 ) ;
F_7 ( V_7 , V_5 -> V_11 + V_12 ) ;
if ( V_13 )
F_7 ( F_6 ( V_4 ) , V_5 -> V_11 + V_14 ) ;
else
F_7 ( F_6 ( V_4 ) , V_5 -> V_11 + V_15 ) ;
F_8 ( & V_5 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return ! ! ( F_5 ( V_5 -> V_11 + V_16 ) & F_6 ( V_4 ) ) ;
}
static void F_11 ( struct V_2 * V_3 , unsigned V_4 , int V_13 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_13 )
F_7 ( F_6 ( V_4 ) , V_5 -> V_11 + V_14 ) ;
else
F_7 ( F_6 ( V_4 ) , V_5 -> V_11 + V_15 ) ;
}
static int F_12 ( struct V_17 * V_18 , unsigned V_19 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_4 = F_14 ( V_18 ) ;
unsigned long V_6 ;
T_1 V_20 , V_21 , V_22 , V_23 ;
T_1 V_24 = F_6 ( V_4 ) ;
if ( V_4 < 0 || V_4 >= V_25 )
return - V_9 ;
F_4 ( & V_5 -> V_10 , V_6 ) ;
V_23 = F_5 ( V_5 -> V_11 + V_26 ) ;
V_20 = F_5 ( V_5 -> V_11 + V_27 ) ;
V_21 = F_5 ( V_5 -> V_11 + V_28 ) ;
V_22 = F_5 ( V_5 -> V_11 + V_29 ) ;
if ( V_19 & ( V_30 | V_31 ) ) {
V_20 |= V_24 ;
if ( V_19 & V_30 )
V_23 |= V_24 ;
else
V_23 &= ~ V_24 ;
} else
V_20 &= ~ V_24 ;
if ( ( V_19 & V_32 ) == V_32 ) {
V_21 |= V_24 ;
V_22 |= V_24 ;
} else {
if ( V_19 & V_33 ) {
V_21 |= V_24 ;
V_22 &= ~ V_24 ;
} else if ( V_19 & V_34 ) {
V_22 |= V_24 ;
V_21 &= ~ V_24 ;
}
}
F_7 ( V_20 , V_5 -> V_11 + V_27 ) ;
F_7 ( V_21 , V_5 -> V_11 + V_28 ) ;
F_7 ( V_22 , V_5 -> V_11 + V_29 ) ;
F_7 ( V_23 , V_5 -> V_11 + V_26 ) ;
F_8 ( & V_5 -> V_10 , V_6 ) ;
return 0 ;
}
static void F_15 ( struct V_35 * V_36 )
{
unsigned long V_37 ;
int V_4 ;
struct V_2 * V_3 = F_16 ( V_36 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_38 * V_39 = F_17 ( V_36 ) ;
F_18 ( V_39 , V_36 ) ;
V_37 = F_5 ( V_5 -> V_11 + V_40 ) ;
F_7 ( V_37 , V_5 -> V_11 + V_41 ) ;
if ( V_37 ) {
F_19 (offset, &pending, ZX_GPIO_NR)
F_20 ( F_21 ( V_3 -> V_42 ,
V_4 ) ) ;
}
F_22 ( V_39 , V_36 ) ;
}
static void F_23 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_43 = F_6 ( F_14 ( V_18 ) % V_25 ) ;
T_1 V_44 ;
F_24 ( & V_5 -> V_10 ) ;
V_44 = F_5 ( V_5 -> V_11 + V_45 ) | V_43 ;
F_7 ( V_44 , V_5 -> V_11 + V_45 ) ;
V_44 = F_5 ( V_5 -> V_11 + V_46 ) & ~ V_43 ;
F_7 ( V_44 , V_5 -> V_11 + V_46 ) ;
F_25 ( & V_5 -> V_10 ) ;
}
static void F_26 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_43 = F_6 ( F_14 ( V_18 ) % V_25 ) ;
T_1 V_44 ;
F_24 ( & V_5 -> V_10 ) ;
V_44 = F_5 ( V_5 -> V_11 + V_45 ) & ~ V_43 ;
F_7 ( V_44 , V_5 -> V_11 + V_45 ) ;
V_44 = F_5 ( V_5 -> V_11 + V_46 ) | V_43 ;
F_7 ( V_44 , V_5 -> V_11 + V_46 ) ;
F_25 ( & V_5 -> V_10 ) ;
}
static int F_27 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = & V_48 -> V_50 ;
struct V_1 * V_5 ;
struct V_51 * V_52 ;
int V_53 , V_54 , V_55 ;
V_5 = F_28 ( V_50 , sizeof( * V_5 ) , V_56 ) ;
if ( ! V_5 )
return - V_57 ;
V_52 = F_29 ( V_48 , V_58 , 0 ) ;
V_5 -> V_11 = F_30 ( V_50 , V_52 ) ;
if ( F_31 ( V_5 -> V_11 ) )
return F_32 ( V_5 -> V_11 ) ;
F_33 ( & V_5 -> V_10 ) ;
if ( F_34 ( V_50 -> V_59 , L_1 ) ) {
V_5 -> V_3 . V_60 = V_61 ;
V_5 -> V_3 . free = V_62 ;
}
V_54 = F_35 ( V_50 -> V_59 , L_2 ) ;
V_5 -> V_3 . V_63 = F_3 ;
V_5 -> V_3 . V_64 = F_9 ;
V_5 -> V_3 . V_65 = F_10 ;
V_5 -> V_3 . V_66 = F_11 ;
V_5 -> V_3 . V_11 = V_25 * V_54 ;
V_5 -> V_3 . V_8 = V_25 ;
V_5 -> V_3 . V_67 = F_36 ( V_50 ) ;
V_5 -> V_3 . V_50 = V_50 ;
V_5 -> V_3 . V_68 = V_69 ;
V_55 = F_37 ( & V_5 -> V_3 ) ;
if ( V_55 )
return V_55 ;
F_7 ( 0xffff , V_5 -> V_11 + V_45 ) ;
F_7 ( 0 , V_5 -> V_11 + V_46 ) ;
V_53 = F_38 ( V_48 , 0 ) ;
if ( V_53 < 0 ) {
F_39 ( V_50 , L_3 ) ;
F_40 ( & V_5 -> V_3 ) ;
return - V_70 ;
}
V_55 = F_41 ( & V_5 -> V_3 , & V_71 ,
0 , V_72 ,
V_73 ) ;
if ( V_55 ) {
F_39 ( V_50 , L_4 ) ;
F_40 ( & V_5 -> V_3 ) ;
return V_55 ;
}
F_42 ( & V_5 -> V_3 , & V_71 ,
V_53 , F_15 ) ;
F_43 ( V_48 , V_5 ) ;
F_44 ( V_50 , L_5 ) ;
return 0 ;
}
