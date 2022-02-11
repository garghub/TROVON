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
F_15 ( V_14 -> V_24 ) ;
return V_18 ;
}
static void F_16 ( struct V_2 * V_3 , struct V_10 * V_11 ,
unsigned long V_16 , unsigned long V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned int V_6 ;
if ( F_10 ( V_19 , & V_11 -> V_20 ) ) {
F_8 ( V_14 , V_11 -> V_29 , V_33 , V_16 ) ;
V_6 = F_7 ( V_14 , V_11 -> V_29 , V_30 ) ;
V_6 &= ~ V_34 ;
F_8 ( V_14 , V_11 -> V_29 , V_30 , V_6 ) ;
} else {
F_8 ( V_14 , V_11 -> V_29 , V_35 , V_16 ) ;
F_8 ( V_14 , V_11 -> V_29 , V_36 , V_15 ) ;
}
}
static void F_17 ( struct V_2 * V_3 , struct V_10 * V_11 ,
unsigned long V_16 , unsigned long V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( F_10 ( V_19 , & V_11 -> V_20 ) ) {
F_8 ( V_14 , V_11 -> V_29 , V_37 , V_16 ) ;
} else {
F_8 ( V_14 , V_11 -> V_29 , V_38 , V_16 ) ;
F_8 ( V_14 , V_11 -> V_29 , V_39 , V_15 ) ;
}
}
static int F_18 ( struct V_2 * V_3 , struct V_10 * V_11 ,
enum V_40 V_41 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
T_1 V_6 ;
int V_18 ;
V_6 = F_7 ( V_14 , V_11 -> V_29 , V_30 ) ;
if ( V_41 == V_42 )
V_6 &= ~ V_43 ;
else
V_6 |= V_43 ;
V_18 = F_14 ( V_14 -> V_24 ) ;
if ( V_18 ) {
F_11 ( V_3 -> V_22 , L_3 ) ;
return V_18 ;
}
F_8 ( V_14 , V_11 -> V_29 , V_30 , V_6 ) ;
F_15 ( V_14 -> V_24 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_18 ;
V_18 = F_14 ( V_14 -> V_24 ) ;
if ( V_18 ) {
F_11 ( V_3 -> V_22 , L_3 ) ;
return V_18 ;
}
F_5 ( V_14 , V_44 , 1 << V_11 -> V_29 ) ;
return 0 ;
}
static void F_20 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_5 ( V_14 , V_45 , 1 << V_11 -> V_29 ) ;
F_15 ( V_14 -> V_24 ) ;
}
static inline const struct V_46 *
F_21 ( struct V_47 * V_48 )
{
if ( V_48 -> V_22 . V_49 ) {
const struct V_50 * V_51 ;
V_51 = F_22 ( V_52 , & V_48 -> V_22 ) ;
if ( ! V_51 )
return NULL ;
return V_51 -> V_53 ;
} else {
const struct V_54 * V_55 ;
V_55 = F_23 ( V_48 ) ;
return (struct V_46 * ) V_55 -> V_56 ;
}
}
static int F_24 ( struct V_47 * V_48 )
{
const struct V_46 * V_53 ;
struct V_1 * V_14 ;
struct V_57 * V_58 ;
int V_18 ;
V_53 = F_21 ( V_48 ) ;
if ( ! V_53 )
return - V_59 ;
V_14 = F_25 ( & V_48 -> V_22 , sizeof( * V_14 ) , V_60 ) ;
if ( ! V_14 )
return - V_61 ;
V_58 = F_26 ( V_48 , V_62 , 0 ) ;
V_14 -> V_5 = F_27 ( & V_48 -> V_22 , V_58 ) ;
if ( F_28 ( V_14 -> V_5 ) )
return F_29 ( V_14 -> V_5 ) ;
V_14 -> V_24 = F_30 ( & V_48 -> V_22 , NULL ) ;
if ( F_28 ( V_14 -> V_24 ) )
return F_29 ( V_14 -> V_24 ) ;
V_18 = F_31 ( V_14 -> V_24 ) ;
if ( V_18 ) {
F_11 ( & V_48 -> V_22 , L_4 ) ;
return V_18 ;
}
V_14 -> V_3 . V_22 = & V_48 -> V_22 ;
V_14 -> V_3 . V_63 = & V_64 ;
if ( V_48 -> V_22 . V_49 ) {
V_14 -> V_3 . V_65 = V_66 ;
V_14 -> V_3 . V_67 = 3 ;
}
V_14 -> V_3 . V_5 = - 1 ;
V_14 -> V_3 . V_68 = 4 ;
V_14 -> V_3 . V_69 = true ;
V_14 -> V_32 = V_53 -> V_32 ;
V_18 = F_32 ( & V_14 -> V_3 ) ;
if ( V_18 < 0 ) {
F_11 ( & V_48 -> V_22 , L_5 , V_18 ) ;
goto V_70;
}
F_33 ( V_48 , V_14 ) ;
return V_18 ;
V_70:
F_34 ( V_14 -> V_24 ) ;
return V_18 ;
}
static int F_35 ( struct V_47 * V_48 )
{
struct V_1 * V_14 = F_36 ( V_48 ) ;
F_34 ( V_14 -> V_24 ) ;
return F_37 ( & V_14 -> V_3 ) ;
}
