static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_6 , int V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long long V_9 ;
unsigned long V_10 , V_11 ;
unsigned int V_12 ;
if ( V_7 > V_13 )
return - V_14 ;
V_9 = V_8 -> V_15 ;
V_9 = V_9 * V_7 ;
F_4 ( V_9 , V_13 ) ;
V_10 = ( unsigned long ) V_9 ;
if ( V_10 < 1 ) {
V_10 = 1 ;
V_11 = 1 ;
} else {
V_9 = V_8 -> V_15 ;
V_9 = V_9 * V_6 ;
F_4 ( V_9 , V_13 ) ;
V_11 = ( unsigned long ) V_9 ;
}
F_5 ( V_8 -> V_3 . V_16 ) ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 |= V_19 | V_20 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
if ( ! F_8 ( V_5 ) ) {
F_9 ( V_11 , V_8 -> V_17 + V_21 ) ;
F_9 ( V_10 , V_8 -> V_17 + V_22 ) ;
} else {
F_9 ( V_11 , V_8 -> V_17 + V_23 ) ;
F_9 ( V_10 , V_8 -> V_17 + V_24 ) ;
}
if ( ! F_8 ( V_5 ) ) {
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 &= ~ V_19 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
}
F_10 ( V_8 -> V_3 . V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_25 V_26 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned short V_12 ;
F_5 ( V_8 -> V_3 . V_16 ) ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
if ( V_26 == V_27 )
V_12 |= V_28 ;
else
V_12 &= ~ V_28 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
F_10 ( V_8 -> V_3 . V_16 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned int V_12 ;
F_5 ( V_8 -> V_3 . V_16 ) ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 |= V_29 | V_19 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned int V_12 ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 &= ~ ( V_29 | V_19 ) ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
F_10 ( V_8 -> V_3 . V_16 ) ;
}
static void F_14 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( F_8 ( V_5 ) ) {
F_15 ( V_3 -> V_16 , L_1 ) ;
F_10 ( V_3 -> V_16 ) ;
}
}
static int F_16 ( struct V_30 * V_31 )
{
int V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_35 ;
struct V_1 * V_8 ;
T_1 V_36 ;
V_8 = F_17 ( & V_31 -> V_16 , sizeof( * V_8 ) , V_37 ) ;
if ( ! V_8 )
return - V_38 ;
V_35 = F_18 ( & V_31 -> V_16 , L_2 ) ;
if ( F_19 ( V_35 ) ) {
F_20 ( & V_31 -> V_16 , L_3 ) ;
return F_21 ( V_35 ) ;
}
V_8 -> V_15 = F_22 ( V_35 ) ;
if ( ! V_8 -> V_15 ) {
F_20 ( & V_31 -> V_16 , L_4 ) ;
return - V_39 ;
}
V_8 -> V_3 . V_16 = & V_31 -> V_16 ;
V_8 -> V_3 . V_40 = & V_41 ;
V_8 -> V_3 . V_42 = V_43 ;
V_8 -> V_3 . V_44 = 3 ;
V_8 -> V_3 . V_45 = - 1 ;
V_8 -> V_3 . V_46 = 1 ;
V_34 = F_23 ( V_31 , V_47 , 0 ) ;
V_8 -> V_17 = F_24 ( & V_31 -> V_16 , V_34 ) ;
if ( F_19 ( V_8 -> V_17 ) )
return F_21 ( V_8 -> V_17 ) ;
V_32 = F_25 ( & V_8 -> V_3 ) ;
if ( V_32 < 0 ) {
F_20 ( & V_31 -> V_16 , L_5 , V_32 ) ;
return V_32 ;
}
F_26 ( & V_31 -> V_16 ) ;
F_5 ( & V_31 -> V_16 ) ;
V_36 = F_27 ( V_31 -> V_16 . V_48 ,
V_49 ) ;
if ( ! ( V_36 & V_50 ) ) {
F_20 ( & V_31 -> V_16 , L_6 ) ;
V_32 = - V_39 ;
goto V_51;
}
F_10 ( & V_31 -> V_16 ) ;
F_28 ( V_31 , V_8 ) ;
return 0 ;
V_51:
F_10 ( & V_31 -> V_16 ) ;
F_29 ( & V_31 -> V_16 ) ;
F_30 ( & V_8 -> V_3 ) ;
return V_32 ;
}
static int F_31 ( struct V_30 * V_31 )
{
struct V_1 * V_8 = F_32 ( V_31 ) ;
F_5 ( & V_31 -> V_16 ) ;
F_27 ( V_31 -> V_16 . V_48 , V_52 ) ;
F_10 ( & V_31 -> V_16 ) ;
F_29 ( & V_31 -> V_16 ) ;
return F_30 ( & V_8 -> V_3 ) ;
}
static void F_33 ( struct V_1 * V_8 )
{
F_5 ( V_8 -> V_3 . V_16 ) ;
V_8 -> V_53 . V_54 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_8 -> V_53 . V_55 = F_34 ( V_8 -> V_17 + V_23 ) ;
V_8 -> V_53 . V_56 = F_34 ( V_8 -> V_17 + V_24 ) ;
F_10 ( V_8 -> V_3 . V_16 ) ;
}
static void F_35 ( struct V_1 * V_8 )
{
F_9 ( V_8 -> V_53 . V_56 , V_8 -> V_17 + V_24 ) ;
F_9 ( V_8 -> V_53 . V_55 , V_8 -> V_17 + V_23 ) ;
F_7 ( V_8 -> V_53 . V_54 , V_8 -> V_17 + V_18 ) ;
}
static int F_36 ( struct V_57 * V_16 )
{
struct V_1 * V_8 = F_37 ( V_16 ) ;
struct V_4 * V_5 = V_8 -> V_3 . V_58 ;
F_33 ( V_8 ) ;
if ( F_8 ( V_5 ) )
F_10 ( V_16 ) ;
return 0 ;
}
static int F_38 ( struct V_57 * V_16 )
{
struct V_1 * V_8 = F_37 ( V_16 ) ;
struct V_4 * V_5 = V_8 -> V_3 . V_58 ;
if ( F_8 ( V_5 ) )
F_5 ( V_16 ) ;
F_35 ( V_8 ) ;
return 0 ;
}
