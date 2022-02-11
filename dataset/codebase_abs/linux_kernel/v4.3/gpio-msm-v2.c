static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static inline void F_3 ( unsigned V_4 , void T_1 * V_5 )
{
F_4 ( F_5 ( V_5 ) | V_4 , V_5 ) ;
}
static inline void F_6 ( unsigned V_4 , void T_1 * V_5 )
{
F_4 ( F_5 ( V_5 ) & ~ V_4 , V_5 ) ;
}
static int F_7 ( struct V_2 * V_3 , unsigned V_6 )
{
return F_5 ( F_8 ( V_6 ) ) & F_9 ( V_7 ) ;
}
static void F_10 ( struct V_2 * V_3 , unsigned V_6 , int V_8 )
{
F_4 ( V_8 ? F_9 ( V_9 ) : 0 , F_8 ( V_6 ) ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_6 )
{
unsigned long V_10 ;
F_12 ( & V_11 , V_10 ) ;
F_6 ( F_9 ( V_12 ) , F_13 ( V_6 ) ) ;
F_14 ( & V_11 , V_10 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
unsigned V_6 ,
int V_8 )
{
unsigned long V_10 ;
F_12 ( & V_11 , V_10 ) ;
F_10 ( V_3 , V_6 , V_8 ) ;
F_3 ( F_9 ( V_12 ) , F_13 ( V_6 ) ) ;
F_14 ( & V_11 , V_10 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , unsigned V_6 )
{
return 0 ;
}
static void F_17 ( struct V_2 * V_3 , unsigned V_6 )
{
return;
}
static int F_18 ( struct V_2 * V_3 , unsigned V_6 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
return F_19 ( V_15 , V_6 ) ;
}
static void F_20 ( unsigned V_16 )
{
int V_17 = 100 ;
unsigned V_8 , V_18 , V_19 ;
do {
V_8 = F_5 ( F_8 ( V_16 ) ) & F_9 ( V_7 ) ;
if ( V_8 )
F_6 ( F_9 ( V_20 ) , F_21 ( V_16 ) ) ;
else
F_3 ( F_9 ( V_20 ) , F_21 ( V_16 ) ) ;
V_18 = F_5 ( F_8 ( V_16 ) ) & F_9 ( V_7 ) ;
V_19 = F_5 ( F_22 ( V_16 ) ) & F_9 ( V_21 ) ;
if ( V_19 || V_8 == V_18 )
return;
} while ( V_17 -- > 0 );
F_23 ( L_1
L_2 ,
V_22 , V_8 , V_18 ) ;
}
static void F_24 ( struct V_23 * V_24 )
{
int V_16 = V_24 -> V_25 ;
F_4 ( F_9 ( V_21 ) , F_22 ( V_16 ) ) ;
if ( F_25 ( V_16 , V_26 . V_27 ) )
F_20 ( V_16 ) ;
}
static void F_26 ( struct V_23 * V_24 )
{
unsigned long V_10 ;
int V_16 = V_24 -> V_25 ;
F_12 ( & V_11 , V_10 ) ;
F_4 ( V_28 , F_27 ( V_16 ) ) ;
F_6 ( F_9 ( V_29 ) | F_9 ( V_30 ) , F_21 ( V_16 ) ) ;
F_28 ( V_16 , V_26 . V_31 ) ;
F_14 ( & V_11 , V_10 ) ;
}
static void F_29 ( struct V_23 * V_24 )
{
unsigned long V_10 ;
int V_16 = V_24 -> V_25 ;
F_12 ( & V_11 , V_10 ) ;
F_30 ( V_16 , V_26 . V_31 ) ;
F_3 ( F_9 ( V_29 ) | F_9 ( V_30 ) , F_21 ( V_16 ) ) ;
F_4 ( V_32 , F_27 ( V_16 ) ) ;
F_14 ( & V_11 , V_10 ) ;
}
static int F_31 ( struct V_23 * V_24 , unsigned int V_33 )
{
unsigned long V_10 ;
int V_16 = V_24 -> V_25 ;
T_2 V_34 ;
F_12 ( & V_11 , V_10 ) ;
V_34 = F_5 ( F_21 ( V_16 ) ) ;
if ( V_33 & V_35 ) {
V_34 |= F_9 ( V_36 ) ;
F_32 ( V_24 , V_37 ) ;
if ( ( V_33 & V_35 ) == V_35 )
F_30 ( V_16 , V_26 . V_27 ) ;
else
F_28 ( V_16 , V_26 . V_27 ) ;
} else {
V_34 &= ~ F_9 ( V_36 ) ;
F_32 ( V_24 , V_38 ) ;
F_28 ( V_16 , V_26 . V_27 ) ;
}
if ( V_33 & ( V_39 | V_40 ) )
V_34 |= F_9 ( V_20 ) ;
else
V_34 &= ~ F_9 ( V_20 ) ;
F_4 ( V_34 , F_21 ( V_16 ) ) ;
if ( ( V_33 & V_35 ) == V_35 )
F_20 ( V_16 ) ;
F_14 ( & V_11 , V_10 ) ;
return 0 ;
}
static void F_33 ( struct V_41 * V_42 )
{
unsigned long V_43 ;
struct V_44 * V_3 = F_34 ( V_42 ) ;
F_35 ( V_3 , V_42 ) ;
F_36 (i, msm_gpio.enabled_irqs, MAX_NR_GPIO) {
if ( F_5 ( F_22 ( V_43 ) ) & F_9 ( V_21 ) )
F_37 ( F_38 ( V_26 . V_15 ,
V_43 ) ) ;
}
F_39 ( V_3 , V_42 ) ;
}
static int F_40 ( struct V_23 * V_24 , unsigned int V_45 )
{
int V_16 = V_24 -> V_25 ;
if ( V_45 ) {
if ( F_41 ( V_26 . V_46 , V_47 ) )
F_42 ( V_26 . V_48 , 1 ) ;
F_43 ( V_16 , V_26 . V_46 ) ;
} else {
F_44 ( V_16 , V_26 . V_46 ) ;
if ( F_41 ( V_26 . V_46 , V_47 ) )
F_42 ( V_26 . V_48 , 0 ) ;
}
return 0 ;
}
static int F_45 ( struct V_14 * V_24 , unsigned int V_49 ,
T_3 V_25 )
{
F_46 ( V_49 , & V_50 ) ;
F_47 ( V_49 , & V_51 ,
V_38 ) ;
return 0 ;
}
static int F_48 ( struct V_52 * V_53 )
{
int V_54 , V_55 ;
struct V_56 * V_57 ;
if ( F_49 ( V_53 -> V_58 . V_59 , L_3 , & V_55 ) ) {
F_50 ( & V_53 -> V_58 , L_4 , V_22 ) ;
return - V_60 ;
}
if ( V_55 > V_47 )
F_51 ( 1 , L_5 ) ;
F_52 ( V_26 . V_31 , V_47 ) ;
F_52 ( V_26 . V_46 , V_47 ) ;
F_52 ( V_26 . V_27 , V_47 ) ;
V_57 = F_53 ( V_53 , V_61 , 0 ) ;
V_26 . V_62 = F_54 ( & V_53 -> V_58 , V_57 ) ;
if ( F_55 ( V_26 . V_62 ) )
return F_56 ( V_26 . V_62 ) ;
V_26 . V_2 . V_55 = V_55 ;
V_26 . V_2 . V_63 = V_53 -> V_64 ;
V_26 . V_2 . V_58 = & V_53 -> V_58 ;
V_26 . V_2 . V_65 = 0 ;
V_26 . V_2 . V_66 = F_11 ;
V_26 . V_2 . V_67 = F_15 ;
V_26 . V_2 . V_68 = F_7 ;
V_26 . V_2 . V_69 = F_10 ;
V_26 . V_2 . V_70 = F_18 ;
V_26 . V_2 . V_71 = F_16 ;
V_26 . V_2 . free = F_17 ;
V_54 = F_57 ( & V_26 . V_2 ) ;
if ( V_54 < 0 ) {
F_50 ( & V_53 -> V_58 , L_6 , V_54 ) ;
return V_54 ;
}
V_26 . V_48 = F_58 ( V_53 , 0 ) ;
if ( V_26 . V_48 < 0 ) {
F_50 ( & V_53 -> V_58 , L_7 ) ;
return V_26 . V_48 ;
}
V_26 . V_15 = F_59 ( V_53 -> V_58 . V_59 , V_55 ,
& V_72 ,
& V_26 ) ;
if ( ! V_26 . V_15 )
return - V_73 ;
F_60 ( V_26 . V_48 , F_33 ) ;
return 0 ;
}
static int F_61 ( struct V_52 * V_58 )
{
F_62 ( & V_26 . V_2 ) ;
F_63 ( V_26 . V_48 , NULL ) ;
return 0 ;
}
