static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_3 ,
unsigned long V_4 )
{
return F_4 ( V_3 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_3 ,
unsigned long V_4 , unsigned long V_6 )
{
F_6 ( V_6 , V_3 -> V_5 + V_4 ) ;
}
static inline T_1 F_7 ( struct V_1 * V_3 ,
unsigned int V_7 , unsigned long V_4 )
{
unsigned long V_5 = V_8 + V_7 * V_9 ;
return F_4 ( V_3 -> V_5 + V_5 + V_4 ) ;
}
static inline void F_8 ( struct V_1 * V_3 ,
unsigned int V_7 , unsigned long V_4 ,
unsigned long V_6 )
{
unsigned long V_5 = V_8 + V_7 * V_9 ;
F_6 ( V_6 , V_3 -> V_5 + V_5 + V_4 ) ;
}
static int F_9 ( struct V_2 * V_3 , struct V_10 * V_11 ,
int V_12 , int V_13 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_15 , V_16 ;
unsigned long long div ;
unsigned int V_17 = 0 ;
T_1 V_6 ;
int V_18 ;
if ( F_10 ( V_11 ) && ( V_13 != F_11 ( V_11 ) ) ) {
F_12 ( V_3 -> V_19 , L_1 ) ;
return - V_20 ;
}
div = ( unsigned long long ) F_13 ( V_14 -> V_21 ) * V_13 ;
F_14 ( div , V_22 ) ;
while ( div > V_23 ) {
div >>= 1 ;
V_17 ++ ;
}
if ( V_17 > V_24 ) {
F_12 ( V_3 -> V_19 , L_2 ) ;
return - V_25 ;
}
V_15 = div ;
div *= V_12 ;
F_14 ( div , V_13 ) ;
V_16 = V_15 - div ;
V_18 = F_15 ( V_14 -> V_21 ) ;
if ( V_18 ) {
F_12 ( V_3 -> V_19 , L_3 ) ;
return V_18 ;
}
V_6 = F_7 ( V_14 , V_11 -> V_26 , V_27 ) ;
V_6 = ( V_6 & ~ V_28 ) | ( V_17 & V_28 ) ;
F_8 ( V_14 , V_11 -> V_26 , V_27 , V_6 ) ;
V_14 -> V_29 ( V_3 , V_11 , V_16 , V_15 ) ;
F_16 ( & V_14 -> V_30 ) ;
V_14 -> V_31 |= F_3 ( V_14 , V_32 ) ;
V_14 -> V_31 &= ~ ( 1 << V_11 -> V_26 ) ;
F_17 ( & V_14 -> V_30 ) ;
F_18 ( V_14 -> V_21 ) ;
return V_18 ;
}
static void F_19 ( struct V_2 * V_3 , struct V_10 * V_11 ,
unsigned long V_16 , unsigned long V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned int V_6 ;
F_8 ( V_14 , V_11 -> V_26 , V_33 , V_16 ) ;
V_6 = F_7 ( V_14 , V_11 -> V_26 , V_27 ) ;
V_6 &= ~ V_34 ;
F_8 ( V_14 , V_11 -> V_26 , V_27 , V_6 ) ;
if ( F_10 ( V_11 ) )
return;
F_8 ( V_14 , V_11 -> V_26 , V_35 , V_16 ) ;
F_8 ( V_14 , V_11 -> V_26 , V_36 , V_15 ) ;
}
static void F_20 ( struct V_2 * V_3 , struct V_10 * V_11 ,
unsigned long V_16 , unsigned long V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( F_10 ( V_11 ) ) {
F_8 ( V_14 , V_11 -> V_26 , V_37 , V_16 ) ;
} else {
F_8 ( V_14 , V_11 -> V_26 , V_38 , V_16 ) ;
F_8 ( V_14 , V_11 -> V_26 , V_39 , V_15 ) ;
}
}
static int F_21 ( struct V_2 * V_3 , struct V_10 * V_11 ,
enum V_40 V_41 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
T_1 V_6 ;
int V_18 ;
V_6 = F_7 ( V_14 , V_11 -> V_26 , V_27 ) ;
if ( V_41 == V_42 )
V_6 &= ~ V_43 ;
else
V_6 |= V_43 ;
V_18 = F_15 ( V_14 -> V_21 ) ;
if ( V_18 ) {
F_12 ( V_3 -> V_19 , L_3 ) ;
return V_18 ;
}
F_8 ( V_14 , V_11 -> V_26 , V_27 , V_6 ) ;
F_18 ( V_14 -> V_21 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_18 ;
V_18 = F_15 ( V_14 -> V_21 ) ;
if ( V_18 ) {
F_12 ( V_3 -> V_19 , L_3 ) ;
return V_18 ;
}
F_5 ( V_14 , V_44 , 1 << V_11 -> V_26 ) ;
return 0 ;
}
static void F_23 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_45 = V_46 + 2 * V_47 ;
F_16 ( & V_14 -> V_30 ) ;
V_14 -> V_31 |= F_3 ( V_14 , V_32 ) ;
while ( ! ( V_14 -> V_31 & ( 1 << V_11 -> V_26 ) ) &&
F_24 ( V_46 , V_45 ) ) {
F_25 ( 10 , 100 ) ;
V_14 -> V_31 |= F_3 ( V_14 , V_32 ) ;
}
F_17 ( & V_14 -> V_30 ) ;
F_5 ( V_14 , V_48 , 1 << V_11 -> V_26 ) ;
F_18 ( V_14 -> V_21 ) ;
}
static inline const struct V_49 *
F_26 ( struct V_50 * V_51 )
{
if ( V_51 -> V_19 . V_52 ) {
const struct V_53 * V_54 ;
V_54 = F_27 ( V_55 , & V_51 -> V_19 ) ;
if ( ! V_54 )
return NULL ;
return V_54 -> V_56 ;
} else {
const struct V_57 * V_58 ;
V_58 = F_28 ( V_51 ) ;
return (struct V_49 * ) V_58 -> V_59 ;
}
}
static int F_29 ( struct V_50 * V_51 )
{
const struct V_49 * V_56 ;
struct V_1 * V_14 ;
struct V_60 * V_61 ;
int V_18 ;
V_56 = F_26 ( V_51 ) ;
if ( ! V_56 )
return - V_62 ;
V_14 = F_30 ( & V_51 -> V_19 , sizeof( * V_14 ) , V_63 ) ;
if ( ! V_14 )
return - V_64 ;
V_61 = F_31 ( V_51 , V_65 , 0 ) ;
V_14 -> V_5 = F_32 ( & V_51 -> V_19 , V_61 ) ;
if ( F_33 ( V_14 -> V_5 ) )
return F_34 ( V_14 -> V_5 ) ;
V_14 -> V_21 = F_35 ( & V_51 -> V_19 , NULL ) ;
if ( F_33 ( V_14 -> V_21 ) )
return F_34 ( V_14 -> V_21 ) ;
V_18 = F_36 ( V_14 -> V_21 ) ;
if ( V_18 ) {
F_12 ( & V_51 -> V_19 , L_4 ) ;
return V_18 ;
}
V_14 -> V_3 . V_19 = & V_51 -> V_19 ;
V_14 -> V_3 . V_66 = & V_67 ;
if ( V_51 -> V_19 . V_52 ) {
V_14 -> V_3 . V_68 = V_69 ;
V_14 -> V_3 . V_70 = 3 ;
}
V_14 -> V_3 . V_5 = - 1 ;
V_14 -> V_3 . V_71 = 4 ;
V_14 -> V_3 . V_72 = true ;
V_14 -> V_29 = V_56 -> V_29 ;
V_14 -> V_31 = 0 ;
F_37 ( & V_14 -> V_30 ) ;
V_18 = F_38 ( & V_14 -> V_3 ) ;
if ( V_18 < 0 ) {
F_12 ( & V_51 -> V_19 , L_5 , V_18 ) ;
goto V_73;
}
F_39 ( V_51 , V_14 ) ;
return V_18 ;
V_73:
F_40 ( V_14 -> V_21 ) ;
return V_18 ;
}
static int F_41 ( struct V_50 * V_51 )
{
struct V_1 * V_14 = F_42 ( V_51 ) ;
F_40 ( V_14 -> V_21 ) ;
F_43 ( & V_14 -> V_30 ) ;
return F_44 ( & V_14 -> V_3 ) ;
}
