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
return F_17 ( V_3 -> V_13 + V_6 ) ;
}
static void F_18 ( struct V_2 * V_3 , unsigned V_6 )
{
F_19 ( V_3 -> V_13 + V_6 ) ;
}
static int F_20 ( struct V_2 * V_3 , unsigned V_6 )
{
return F_21 ( V_3 -> V_13 + V_6 ) ;
}
static inline int F_22 ( struct V_2 * V_3 , unsigned V_14 )
{
return V_14 - F_21 ( V_3 -> V_13 ) ;
}
static void F_23 ( unsigned V_15 )
{
int V_16 = 100 ;
unsigned V_8 , V_17 , V_18 ;
do {
V_8 = F_5 ( F_8 ( V_15 ) ) & F_9 ( V_7 ) ;
if ( V_8 )
F_6 ( F_9 ( V_19 ) , F_24 ( V_15 ) ) ;
else
F_3 ( F_9 ( V_19 ) , F_24 ( V_15 ) ) ;
V_17 = F_5 ( F_8 ( V_15 ) ) & F_9 ( V_7 ) ;
V_18 = F_5 ( F_25 ( V_15 ) ) & F_9 ( V_20 ) ;
if ( V_18 || V_8 == V_17 )
return;
} while ( V_16 -- > 0 );
F_26 ( L_1
L_2 ,
V_8 , V_17 ) ;
}
static void F_27 ( struct V_21 * V_22 )
{
int V_15 = F_22 ( & V_23 . V_2 , V_22 -> V_14 ) ;
F_4 ( F_9 ( V_20 ) , F_25 ( V_15 ) ) ;
if ( F_28 ( V_15 , V_23 . V_24 ) )
F_23 ( V_15 ) ;
}
static void F_29 ( struct V_21 * V_22 )
{
int V_15 = F_22 ( & V_23 . V_2 , V_22 -> V_14 ) ;
unsigned long V_10 ;
F_12 ( & V_11 , V_10 ) ;
F_4 ( V_25 , F_30 ( V_15 ) ) ;
F_6 ( V_26 | V_27 , F_24 ( V_15 ) ) ;
F_31 ( V_15 , V_23 . V_28 ) ;
F_14 ( & V_11 , V_10 ) ;
}
static void F_32 ( struct V_21 * V_22 )
{
int V_15 = F_22 ( & V_23 . V_2 , V_22 -> V_14 ) ;
unsigned long V_10 ;
F_12 ( & V_11 , V_10 ) ;
F_33 ( V_15 , V_23 . V_28 ) ;
F_3 ( V_26 | V_27 , F_24 ( V_15 ) ) ;
F_4 ( V_29 , F_30 ( V_15 ) ) ;
F_14 ( & V_11 , V_10 ) ;
}
static int F_34 ( struct V_21 * V_22 , unsigned int V_30 )
{
int V_15 = F_22 ( & V_23 . V_2 , V_22 -> V_14 ) ;
unsigned long V_10 ;
T_2 V_31 ;
F_12 ( & V_11 , V_10 ) ;
V_31 = F_5 ( F_24 ( V_15 ) ) ;
if ( V_30 & V_32 ) {
V_31 |= F_9 ( V_33 ) ;
F_35 ( V_22 -> V_14 , V_34 ) ;
if ( ( V_30 & V_32 ) == V_32 )
F_33 ( V_15 , V_23 . V_24 ) ;
else
F_31 ( V_15 , V_23 . V_24 ) ;
} else {
V_31 &= ~ F_9 ( V_33 ) ;
F_35 ( V_22 -> V_14 , V_35 ) ;
F_31 ( V_15 , V_23 . V_24 ) ;
}
if ( V_30 & ( V_36 | V_37 ) )
V_31 |= F_9 ( V_19 ) ;
else
V_31 &= ~ F_9 ( V_19 ) ;
F_4 ( V_31 , F_24 ( V_15 ) ) ;
if ( ( V_30 & V_32 ) == V_32 )
F_23 ( V_15 ) ;
F_14 ( & V_11 , V_10 ) ;
return 0 ;
}
static void F_36 ( unsigned int V_14 , struct V_38 * V_39 )
{
unsigned long V_40 ;
struct V_41 * V_3 = F_37 ( V_39 ) ;
F_38 ( V_3 , V_39 ) ;
F_39 (i, msm_gpio.enabled_irqs, NR_GPIO_IRQS) {
if ( F_5 ( F_25 ( V_40 ) ) & F_9 ( V_20 ) )
F_40 ( F_20 ( & V_23 . V_2 ,
V_40 ) ) ;
}
F_41 ( V_3 , V_39 ) ;
}
static int F_42 ( struct V_21 * V_22 , unsigned int V_42 )
{
int V_15 = F_22 ( & V_23 . V_2 , V_22 -> V_14 ) ;
if ( V_42 ) {
if ( F_43 ( V_23 . V_43 , V_44 ) )
F_44 ( V_45 , 1 ) ;
F_45 ( V_15 , V_23 . V_43 ) ;
} else {
F_46 ( V_15 , V_23 . V_43 ) ;
if ( F_43 ( V_23 . V_43 , V_44 ) )
F_44 ( V_45 , 0 ) ;
}
return 0 ;
}
static int T_3 F_47 ( struct V_46 * V_47 )
{
int V_40 , V_14 , V_48 ;
F_48 ( V_23 . V_28 , V_44 ) ;
F_48 ( V_23 . V_43 , V_44 ) ;
F_48 ( V_23 . V_24 , V_44 ) ;
V_23 . V_2 . V_49 = V_47 -> V_50 ;
V_48 = F_49 ( & V_23 . V_2 ) ;
if ( V_48 < 0 )
return V_48 ;
for ( V_40 = 0 ; V_40 < V_23 . V_2 . V_51 ; ++ V_40 ) {
V_14 = F_20 ( & V_23 . V_2 , V_40 ) ;
F_50 ( V_14 , & V_52 ,
V_35 ) ;
F_51 ( V_14 , V_53 ) ;
}
F_52 ( V_45 ,
F_36 ) ;
return 0 ;
}
static int T_4 F_53 ( struct V_46 * V_47 )
{
int V_48 = F_54 ( & V_23 . V_2 ) ;
if ( V_48 < 0 )
return V_48 ;
F_55 ( V_45 , NULL ) ;
return 0 ;
}
static int T_5 F_56 ( void )
{
int V_54 ;
V_54 = F_57 ( & V_55 ) ;
if ( ! V_54 ) {
V_54 = F_58 ( & V_56 ) ;
if ( V_54 )
F_59 ( & V_55 ) ;
}
return V_54 ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_56 ) ;
F_59 ( & V_55 ) ;
}
