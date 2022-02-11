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
static inline int F_20 ( struct V_2 * V_3 , unsigned V_16 )
{
struct V_17 * V_17 = F_21 ( V_16 ) ;
return V_17 -> V_18 ;
}
static void F_22 ( unsigned V_19 )
{
int V_20 = 100 ;
unsigned V_8 , V_21 , V_22 ;
do {
V_8 = F_5 ( F_8 ( V_19 ) ) & F_9 ( V_7 ) ;
if ( V_8 )
F_6 ( F_9 ( V_23 ) , F_23 ( V_19 ) ) ;
else
F_3 ( F_9 ( V_23 ) , F_23 ( V_19 ) ) ;
V_21 = F_5 ( F_8 ( V_19 ) ) & F_9 ( V_7 ) ;
V_22 = F_5 ( F_24 ( V_19 ) ) & F_9 ( V_24 ) ;
if ( V_22 || V_8 == V_21 )
return;
} while ( V_20 -- > 0 );
F_25 ( L_1
L_2 ,
V_25 , V_8 , V_21 ) ;
}
static void F_26 ( struct V_17 * V_26 )
{
int V_19 = F_20 ( & V_27 . V_2 , V_26 -> V_16 ) ;
F_4 ( F_9 ( V_24 ) , F_24 ( V_19 ) ) ;
if ( F_27 ( V_19 , V_27 . V_28 ) )
F_22 ( V_19 ) ;
}
static void F_28 ( struct V_17 * V_26 )
{
int V_19 = F_20 ( & V_27 . V_2 , V_26 -> V_16 ) ;
unsigned long V_10 ;
F_12 ( & V_11 , V_10 ) ;
F_4 ( V_29 , F_29 ( V_19 ) ) ;
F_6 ( F_9 ( V_30 ) | F_9 ( V_31 ) , F_23 ( V_19 ) ) ;
F_30 ( V_19 , V_27 . V_32 ) ;
F_14 ( & V_11 , V_10 ) ;
}
static void F_31 ( struct V_17 * V_26 )
{
int V_19 = F_20 ( & V_27 . V_2 , V_26 -> V_16 ) ;
unsigned long V_10 ;
F_12 ( & V_11 , V_10 ) ;
F_32 ( V_19 , V_27 . V_32 ) ;
F_3 ( F_9 ( V_30 ) | F_9 ( V_31 ) , F_23 ( V_19 ) ) ;
F_4 ( V_33 , F_29 ( V_19 ) ) ;
F_14 ( & V_11 , V_10 ) ;
}
static int F_33 ( struct V_17 * V_26 , unsigned int V_34 )
{
int V_19 = F_20 ( & V_27 . V_2 , V_26 -> V_16 ) ;
unsigned long V_10 ;
T_2 V_35 ;
F_12 ( & V_11 , V_10 ) ;
V_35 = F_5 ( F_23 ( V_19 ) ) ;
if ( V_34 & V_36 ) {
V_35 |= F_9 ( V_37 ) ;
F_34 ( V_26 -> V_16 , V_38 ) ;
if ( ( V_34 & V_36 ) == V_36 )
F_32 ( V_19 , V_27 . V_28 ) ;
else
F_30 ( V_19 , V_27 . V_28 ) ;
} else {
V_35 &= ~ F_9 ( V_37 ) ;
F_34 ( V_26 -> V_16 , V_39 ) ;
F_30 ( V_19 , V_27 . V_28 ) ;
}
if ( V_34 & ( V_40 | V_41 ) )
V_35 |= F_9 ( V_23 ) ;
else
V_35 &= ~ F_9 ( V_23 ) ;
F_4 ( V_35 , F_23 ( V_19 ) ) ;
if ( ( V_34 & V_36 ) == V_36 )
F_22 ( V_19 ) ;
F_14 ( & V_11 , V_10 ) ;
return 0 ;
}
static void F_35 ( unsigned int V_16 , struct V_42 * V_43 )
{
unsigned long V_44 ;
struct V_45 * V_3 = F_36 ( V_43 ) ;
F_37 ( V_3 , V_43 ) ;
F_38 (i, msm_gpio.enabled_irqs, MAX_NR_GPIO) {
if ( F_5 ( F_24 ( V_44 ) ) & F_9 ( V_24 ) )
F_39 ( F_40 ( V_27 . V_15 ,
V_44 ) ) ;
}
F_41 ( V_3 , V_43 ) ;
}
static int F_42 ( struct V_17 * V_26 , unsigned int V_46 )
{
int V_19 = F_20 ( & V_27 . V_2 , V_26 -> V_16 ) ;
if ( V_46 ) {
if ( F_43 ( V_27 . V_47 , V_48 ) )
F_44 ( V_27 . V_49 , 1 ) ;
F_45 ( V_19 , V_27 . V_47 ) ;
} else {
F_46 ( V_19 , V_27 . V_47 ) ;
if ( F_43 ( V_27 . V_47 , V_48 ) )
F_44 ( V_27 . V_49 , 0 ) ;
}
return 0 ;
}
static int F_47 ( struct V_14 * V_26 , unsigned int V_16 ,
T_3 V_18 )
{
F_48 ( V_16 , & V_50 ) ;
F_49 ( V_16 , & V_51 ,
V_39 ) ;
F_50 ( V_16 , V_52 ) ;
return 0 ;
}
static int F_51 ( struct V_53 * V_54 )
{
int V_55 , V_56 ;
struct V_57 * V_58 ;
if ( F_52 ( V_54 -> V_59 . V_60 , L_3 , & V_56 ) ) {
F_53 ( & V_54 -> V_59 , L_4 , V_25 ) ;
return - V_61 ;
}
if ( V_56 > V_48 )
F_54 ( 1 , L_5 ) ;
F_55 ( V_27 . V_32 , V_48 ) ;
F_55 ( V_27 . V_47 , V_48 ) ;
F_55 ( V_27 . V_28 , V_48 ) ;
V_58 = F_56 ( V_54 , V_62 , 0 ) ;
V_27 . V_63 = F_57 ( & V_54 -> V_59 , V_58 ) ;
if ( F_58 ( V_27 . V_63 ) )
return F_59 ( V_27 . V_63 ) ;
V_27 . V_2 . V_56 = V_56 ;
V_27 . V_2 . V_64 = V_54 -> V_65 ;
V_27 . V_2 . V_59 = & V_54 -> V_59 ;
V_27 . V_2 . V_66 = 0 ;
V_27 . V_2 . V_67 = F_11 ;
V_27 . V_2 . V_68 = F_15 ;
V_27 . V_2 . V_69 = F_7 ;
V_27 . V_2 . V_70 = F_10 ;
V_27 . V_2 . V_71 = F_18 ;
V_27 . V_2 . V_72 = F_16 ;
V_27 . V_2 . free = F_17 ;
V_55 = F_60 ( & V_27 . V_2 ) ;
if ( V_55 < 0 ) {
F_53 ( & V_54 -> V_59 , L_6 , V_55 ) ;
return V_55 ;
}
V_27 . V_49 = F_61 ( V_54 , 0 ) ;
if ( V_27 . V_49 < 0 ) {
F_53 ( & V_54 -> V_59 , L_7 ) ;
return V_27 . V_49 ;
}
V_27 . V_15 = F_62 ( V_54 -> V_59 . V_60 , V_56 ,
& V_73 ,
& V_27 ) ;
if ( ! V_27 . V_15 )
return - V_74 ;
F_63 ( V_27 . V_49 , F_35 ) ;
return 0 ;
}
static int F_64 ( struct V_53 * V_59 )
{
F_65 ( & V_27 . V_2 ) ;
F_66 ( V_27 . V_49 , NULL ) ;
return 0 ;
}
