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
if ( F_10 ( V_19 , & V_11 -> V_20 ) && ( V_13 != V_11 -> V_21 ) ) {
F_11 ( V_3 -> V_22 , L_1 ) ;
return - V_23 ;
}
div = ( unsigned long long ) F_12 ( V_14 -> V_24 ) * V_13 ;
F_13 ( div , V_25 ) ;
while ( div > V_26 ) {
div >>= 1 ;
V_17 ++ ;
}
if ( V_17 > V_27 ) {
F_11 ( V_3 -> V_22 , L_2 ) ;
return - V_28 ;
}
V_15 = div ;
div *= V_12 ;
F_13 ( div , V_13 ) ;
V_16 = V_15 - div ;
V_18 = F_14 ( V_14 -> V_24 ) ;
if ( V_18 ) {
F_11 ( V_3 -> V_22 , L_3 ) ;
return V_18 ;
}
V_6 = F_7 ( V_14 , V_11 -> V_29 , V_30 ) ;
V_6 = ( V_6 & ~ V_31 ) | ( V_17 & V_31 ) ;
F_8 ( V_14 , V_11 -> V_29 , V_30 , V_6 ) ;
V_14 -> V_32 ( V_3 , V_11 , V_16 , V_15 ) ;
F_15 ( & V_14 -> V_33 ) ;
V_14 -> V_34 |= F_3 ( V_14 , V_35 ) ;
V_14 -> V_34 &= ~ ( 1 << V_11 -> V_29 ) ;
F_16 ( & V_14 -> V_33 ) ;
F_17 ( V_14 -> V_24 ) ;
return V_18 ;
}
static void F_18 ( struct V_2 * V_3 , struct V_10 * V_11 ,
unsigned long V_16 , unsigned long V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned int V_6 ;
F_8 ( V_14 , V_11 -> V_29 , V_36 , V_16 ) ;
V_6 = F_7 ( V_14 , V_11 -> V_29 , V_30 ) ;
V_6 &= ~ V_37 ;
F_8 ( V_14 , V_11 -> V_29 , V_30 , V_6 ) ;
if ( F_10 ( V_19 , & V_11 -> V_20 ) )
return;
F_8 ( V_14 , V_11 -> V_29 , V_38 , V_16 ) ;
F_8 ( V_14 , V_11 -> V_29 , V_39 , V_15 ) ;
}
static void F_19 ( struct V_2 * V_3 , struct V_10 * V_11 ,
unsigned long V_16 , unsigned long V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( F_10 ( V_19 , & V_11 -> V_20 ) ) {
F_8 ( V_14 , V_11 -> V_29 , V_40 , V_16 ) ;
} else {
F_8 ( V_14 , V_11 -> V_29 , V_41 , V_16 ) ;
F_8 ( V_14 , V_11 -> V_29 , V_42 , V_15 ) ;
}
}
static int F_20 ( struct V_2 * V_3 , struct V_10 * V_11 ,
enum V_43 V_44 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
T_1 V_6 ;
int V_18 ;
V_6 = F_7 ( V_14 , V_11 -> V_29 , V_30 ) ;
if ( V_44 == V_45 )
V_6 &= ~ V_46 ;
else
V_6 |= V_46 ;
V_18 = F_14 ( V_14 -> V_24 ) ;
if ( V_18 ) {
F_11 ( V_3 -> V_22 , L_3 ) ;
return V_18 ;
}
F_8 ( V_14 , V_11 -> V_29 , V_30 , V_6 ) ;
F_17 ( V_14 -> V_24 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_18 ;
V_18 = F_14 ( V_14 -> V_24 ) ;
if ( V_18 ) {
F_11 ( V_3 -> V_22 , L_3 ) ;
return V_18 ;
}
F_5 ( V_14 , V_47 , 1 << V_11 -> V_29 ) ;
return 0 ;
}
static void F_22 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_48 = V_49 + 2 * V_50 ;
F_15 ( & V_14 -> V_33 ) ;
V_14 -> V_34 |= F_3 ( V_14 , V_35 ) ;
while ( ! ( V_14 -> V_34 & ( 1 << V_11 -> V_29 ) ) &&
F_23 ( V_49 , V_48 ) ) {
F_24 ( 10 , 100 ) ;
V_14 -> V_34 |= F_3 ( V_14 , V_35 ) ;
}
F_16 ( & V_14 -> V_33 ) ;
F_5 ( V_14 , V_51 , 1 << V_11 -> V_29 ) ;
F_17 ( V_14 -> V_24 ) ;
}
static inline const struct V_52 *
F_25 ( struct V_53 * V_54 )
{
if ( V_54 -> V_22 . V_55 ) {
const struct V_56 * V_57 ;
V_57 = F_26 ( V_58 , & V_54 -> V_22 ) ;
if ( ! V_57 )
return NULL ;
return V_57 -> V_59 ;
} else {
const struct V_60 * V_61 ;
V_61 = F_27 ( V_54 ) ;
return (struct V_52 * ) V_61 -> V_62 ;
}
}
static int F_28 ( struct V_53 * V_54 )
{
const struct V_52 * V_59 ;
struct V_1 * V_14 ;
struct V_63 * V_64 ;
int V_18 ;
V_59 = F_25 ( V_54 ) ;
if ( ! V_59 )
return - V_65 ;
V_14 = F_29 ( & V_54 -> V_22 , sizeof( * V_14 ) , V_66 ) ;
if ( ! V_14 )
return - V_67 ;
V_64 = F_30 ( V_54 , V_68 , 0 ) ;
V_14 -> V_5 = F_31 ( & V_54 -> V_22 , V_64 ) ;
if ( F_32 ( V_14 -> V_5 ) )
return F_33 ( V_14 -> V_5 ) ;
V_14 -> V_24 = F_34 ( & V_54 -> V_22 , NULL ) ;
if ( F_32 ( V_14 -> V_24 ) )
return F_33 ( V_14 -> V_24 ) ;
V_18 = F_35 ( V_14 -> V_24 ) ;
if ( V_18 ) {
F_11 ( & V_54 -> V_22 , L_4 ) ;
return V_18 ;
}
V_14 -> V_3 . V_22 = & V_54 -> V_22 ;
V_14 -> V_3 . V_69 = & V_70 ;
if ( V_54 -> V_22 . V_55 ) {
V_14 -> V_3 . V_71 = V_72 ;
V_14 -> V_3 . V_73 = 3 ;
}
V_14 -> V_3 . V_5 = - 1 ;
V_14 -> V_3 . V_74 = 4 ;
V_14 -> V_3 . V_75 = true ;
V_14 -> V_32 = V_59 -> V_32 ;
V_14 -> V_34 = 0 ;
F_36 ( & V_14 -> V_33 ) ;
V_18 = F_37 ( & V_14 -> V_3 ) ;
if ( V_18 < 0 ) {
F_11 ( & V_54 -> V_22 , L_5 , V_18 ) ;
goto V_76;
}
F_38 ( V_54 , V_14 ) ;
return V_18 ;
V_76:
F_39 ( V_14 -> V_24 ) ;
return V_18 ;
}
static int F_40 ( struct V_53 * V_54 )
{
struct V_1 * V_14 = F_41 ( V_54 ) ;
F_39 ( V_14 -> V_24 ) ;
F_42 ( & V_14 -> V_33 ) ;
return F_43 ( & V_14 -> V_3 ) ;
}
