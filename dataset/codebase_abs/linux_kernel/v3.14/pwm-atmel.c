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
unsigned long V_15 , V_16 , V_17 ;
unsigned long long div ;
unsigned int V_18 = 0 ;
int V_19 ;
if ( F_10 ( V_20 , & V_11 -> V_21 ) && ( V_13 != V_11 -> V_22 ) ) {
F_11 ( V_3 -> V_23 , L_1 ) ;
return - V_24 ;
}
V_15 = F_12 ( V_14 -> V_25 ) ;
div = V_15 ;
while ( div > V_26 ) {
div = V_15 / ( 1 << V_18 ) ;
div = div * V_13 ;
F_13 ( div , 1000000000 ) ;
if ( V_18 ++ > V_27 ) {
F_11 ( V_3 -> V_23 , L_2 ) ;
return - V_28 ;
}
}
V_16 = div ;
div *= V_12 ;
F_13 ( div , V_13 ) ;
V_17 = div ;
V_19 = F_14 ( V_14 -> V_25 ) ;
if ( V_19 ) {
F_11 ( V_3 -> V_23 , L_3 ) ;
return V_19 ;
}
F_8 ( V_14 , V_11 -> V_29 , V_30 , V_18 ) ;
V_14 -> V_31 ( V_3 , V_11 , V_17 , V_16 ) ;
F_15 ( V_14 -> V_25 ) ;
return V_19 ;
}
static void F_16 ( struct V_2 * V_3 , struct V_10 * V_11 ,
unsigned long V_17 , unsigned long V_16 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned int V_6 ;
if ( F_10 ( V_20 , & V_11 -> V_21 ) ) {
F_8 ( V_14 , V_11 -> V_29 , V_32 , V_17 ) ;
V_6 = F_7 ( V_14 , V_11 -> V_29 , V_30 ) ;
V_6 &= ~ V_33 ;
F_8 ( V_14 , V_11 -> V_29 , V_30 , V_6 ) ;
} else {
F_8 ( V_14 , V_11 -> V_29 , V_34 , V_17 ) ;
F_8 ( V_14 , V_11 -> V_29 , V_35 , V_16 ) ;
}
}
static void F_17 ( struct V_2 * V_3 , struct V_10 * V_11 ,
unsigned long V_17 , unsigned long V_16 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( F_10 ( V_20 , & V_11 -> V_21 ) ) {
F_8 ( V_14 , V_11 -> V_29 , V_36 , V_17 ) ;
} else {
F_8 ( V_14 , V_11 -> V_29 , V_37 , V_17 ) ;
F_8 ( V_14 , V_11 -> V_29 , V_38 , V_16 ) ;
}
}
static int F_18 ( struct V_2 * V_3 , struct V_10 * V_11 ,
enum V_39 V_40 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
T_1 V_6 ;
int V_19 ;
V_6 = F_7 ( V_14 , V_11 -> V_29 , V_30 ) ;
if ( V_40 == V_41 )
V_6 &= ~ V_42 ;
else
V_6 |= V_42 ;
V_19 = F_14 ( V_14 -> V_25 ) ;
if ( V_19 ) {
F_11 ( V_3 -> V_23 , L_3 ) ;
return V_19 ;
}
F_8 ( V_14 , V_11 -> V_29 , V_30 , V_6 ) ;
F_15 ( V_14 -> V_25 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_19 ;
V_19 = F_14 ( V_14 -> V_25 ) ;
if ( V_19 ) {
F_11 ( V_3 -> V_23 , L_3 ) ;
return V_19 ;
}
F_5 ( V_14 , V_43 , 1 << V_11 -> V_29 ) ;
return 0 ;
}
static void F_20 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_5 ( V_14 , V_44 , 1 << V_11 -> V_29 ) ;
F_15 ( V_14 -> V_25 ) ;
}
static inline const struct V_45 *
F_21 ( struct V_46 * V_47 )
{
if ( V_47 -> V_23 . V_48 ) {
const struct V_49 * V_50 ;
V_50 = F_22 ( V_51 , & V_47 -> V_23 ) ;
if ( ! V_50 )
return NULL ;
return V_50 -> V_52 ;
} else {
const struct V_53 * V_54 ;
V_54 = F_23 ( V_47 ) ;
return (struct V_45 * ) V_54 -> V_55 ;
}
}
static int F_24 ( struct V_46 * V_47 )
{
const struct V_45 * V_52 ;
struct V_1 * V_14 ;
struct V_56 * V_57 ;
int V_19 ;
V_52 = F_21 ( V_47 ) ;
if ( ! V_52 )
return - V_58 ;
V_14 = F_25 ( & V_47 -> V_23 , sizeof( * V_14 ) , V_59 ) ;
if ( ! V_14 )
return - V_60 ;
V_57 = F_26 ( V_47 , V_61 , 0 ) ;
V_14 -> V_5 = F_27 ( & V_47 -> V_23 , V_57 ) ;
if ( F_28 ( V_14 -> V_5 ) )
return F_29 ( V_14 -> V_5 ) ;
V_14 -> V_25 = F_30 ( & V_47 -> V_23 , NULL ) ;
if ( F_28 ( V_14 -> V_25 ) )
return F_29 ( V_14 -> V_25 ) ;
V_19 = F_31 ( V_14 -> V_25 ) ;
if ( V_19 ) {
F_11 ( & V_47 -> V_23 , L_4 ) ;
return V_19 ;
}
V_14 -> V_3 . V_23 = & V_47 -> V_23 ;
V_14 -> V_3 . V_62 = & V_63 ;
if ( V_47 -> V_23 . V_48 ) {
V_14 -> V_3 . V_64 = V_65 ;
V_14 -> V_3 . V_66 = 3 ;
}
V_14 -> V_3 . V_5 = - 1 ;
V_14 -> V_3 . V_67 = 4 ;
V_14 -> V_31 = V_52 -> V_31 ;
V_19 = F_32 ( & V_14 -> V_3 ) ;
if ( V_19 < 0 ) {
F_11 ( & V_47 -> V_23 , L_5 , V_19 ) ;
goto V_68;
}
F_33 ( V_47 , V_14 ) ;
return V_19 ;
V_68:
F_34 ( V_14 -> V_25 ) ;
return V_19 ;
}
static int F_35 ( struct V_46 * V_47 )
{
struct V_1 * V_14 = F_36 ( V_47 ) ;
F_34 ( V_14 -> V_25 ) ;
return F_37 ( & V_14 -> V_3 ) ;
}
