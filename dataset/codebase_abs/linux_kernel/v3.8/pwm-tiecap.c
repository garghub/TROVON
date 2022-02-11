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
if ( ! F_8 ( V_21 , & V_5 -> V_22 ) ) {
F_9 ( V_11 , V_8 -> V_17 + V_23 ) ;
F_9 ( V_10 , V_8 -> V_17 + V_24 ) ;
} else {
F_9 ( V_11 , V_8 -> V_17 + V_25 ) ;
F_9 ( V_10 , V_8 -> V_17 + V_26 ) ;
}
if ( ! F_8 ( V_21 , & V_5 -> V_22 ) ) {
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 &= ~ V_19 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
}
F_10 ( V_8 -> V_3 . V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_27 V_28 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned short V_12 ;
F_5 ( V_8 -> V_3 . V_16 ) ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
if ( V_28 == V_29 )
V_12 |= V_30 ;
else
V_12 &= ~ V_30 ;
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
V_12 |= V_31 | V_19 ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned int V_12 ;
V_12 = F_6 ( V_8 -> V_17 + V_18 ) ;
V_12 &= ~ ( V_31 | V_19 ) ;
F_7 ( V_12 , V_8 -> V_17 + V_18 ) ;
F_10 ( V_8 -> V_3 . V_16 ) ;
}
static void F_14 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( F_8 ( V_21 , & V_5 -> V_22 ) ) {
F_15 ( V_3 -> V_16 , L_1 ) ;
F_10 ( V_3 -> V_16 ) ;
}
}
static int F_16 ( struct V_32 * V_33 )
{
int V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_37 ;
struct V_1 * V_8 ;
T_1 V_38 ;
struct V_39 * V_39 ;
V_39 = F_17 ( & V_33 -> V_16 ) ;
if ( F_18 ( V_39 ) )
F_15 ( & V_33 -> V_16 , L_2 ) ;
V_8 = F_19 ( & V_33 -> V_16 , sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
F_20 ( & V_33 -> V_16 , L_3 ) ;
return - V_41 ;
}
V_37 = F_21 ( & V_33 -> V_16 , L_4 ) ;
if ( F_18 ( V_37 ) ) {
F_20 ( & V_33 -> V_16 , L_5 ) ;
return F_22 ( V_37 ) ;
}
V_8 -> V_15 = F_23 ( V_37 ) ;
if ( ! V_8 -> V_15 ) {
F_20 ( & V_33 -> V_16 , L_6 ) ;
return - V_42 ;
}
V_8 -> V_3 . V_16 = & V_33 -> V_16 ;
V_8 -> V_3 . V_43 = & V_44 ;
V_8 -> V_3 . V_45 = V_46 ;
V_8 -> V_3 . V_47 = 3 ;
V_8 -> V_3 . V_48 = - 1 ;
V_8 -> V_3 . V_49 = 1 ;
V_36 = F_24 ( V_33 , V_50 , 0 ) ;
if ( ! V_36 ) {
F_20 ( & V_33 -> V_16 , L_7 ) ;
return - V_51 ;
}
V_8 -> V_17 = F_25 ( & V_33 -> V_16 , V_36 ) ;
if ( ! V_8 -> V_17 )
return - V_52 ;
V_34 = F_26 ( & V_8 -> V_3 ) ;
if ( V_34 < 0 ) {
F_20 ( & V_33 -> V_16 , L_8 , V_34 ) ;
return V_34 ;
}
F_27 ( & V_33 -> V_16 ) ;
F_5 ( & V_33 -> V_16 ) ;
V_38 = F_28 ( V_33 -> V_16 . V_53 ,
V_54 ) ;
if ( ! ( V_38 & V_55 ) ) {
F_20 ( & V_33 -> V_16 , L_9 ) ;
V_34 = - V_42 ;
goto V_56;
}
F_10 ( & V_33 -> V_16 ) ;
F_29 ( V_33 , V_8 ) ;
return 0 ;
V_56:
F_10 ( & V_33 -> V_16 ) ;
F_30 ( & V_33 -> V_16 ) ;
F_31 ( & V_8 -> V_3 ) ;
return V_34 ;
}
static int F_32 ( struct V_32 * V_33 )
{
struct V_1 * V_8 = F_33 ( V_33 ) ;
F_5 ( & V_33 -> V_16 ) ;
F_28 ( V_33 -> V_16 . V_53 , V_57 ) ;
F_10 ( & V_33 -> V_16 ) ;
F_10 ( & V_33 -> V_16 ) ;
F_30 ( & V_33 -> V_16 ) ;
return F_31 ( & V_8 -> V_3 ) ;
}
