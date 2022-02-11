static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
F_3 ( V_4 -> V_6 , V_7 , & V_5 ) ;
V_5 |= V_8 ;
V_5 &= ~ V_9 ;
V_5 &= ~ V_10 ;
V_5 &= ~ V_11 ;
V_5 |= F_4 ( V_2 -> V_12 ) ;
F_5 ( V_4 -> V_6 , V_7 , V_5 ) ;
V_5 |= V_11 ;
F_5 ( V_4 -> V_6 , V_7 , V_5 ) ;
}
static inline bool F_6 ( struct V_3 * V_4 )
{
T_1 V_5 ;
F_3 ( V_4 -> V_6 , V_7 , & V_5 ) ;
return V_5 & V_11 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_6 , V_13 , V_14 ) ;
F_5 ( V_4 -> V_6 , V_13 , V_15 ) ;
return 0 ;
}
static void F_8 ( unsigned long V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_7 ( V_2 ) ;
F_9 ( & V_4 -> V_17 , V_18 + V_2 -> V_12 * V_19 / 2 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_11 ( V_4 -> V_6 , V_7 , V_9 ,
F_4 ( V_20 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_6 ( V_4 ) ) {
F_13 ( & V_4 -> V_17 ) ;
F_10 ( V_2 , V_2 -> V_12 ) ;
} else
F_1 ( V_2 ) ;
return F_7 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_8 ( ( unsigned long ) V_2 ) ;
return 0 ;
}
static inline void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_6 ( V_4 ) ) {
F_10 ( V_2 , V_2 -> V_12 ) ;
F_8 ( ( unsigned long ) V_2 ) ;
}
}
static int T_2 F_16 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_25 . V_26 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
void T_3 * V_29 ;
bool V_30 ;
int V_31 ;
T_1 V_5 ;
V_4 = F_17 ( & V_22 -> V_25 , sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return - V_33 ;
V_30 = F_18 ( V_24 , L_1 ) ;
if ( V_30 )
V_34 . V_35 = V_36 ;
V_28 = F_19 ( V_22 , V_37 , 0 ) ;
V_29 = F_20 ( & V_22 -> V_25 , V_28 ) ;
if ( F_21 ( V_29 ) )
return F_22 ( V_29 ) ;
V_4 -> V_6 = F_23 ( & V_22 -> V_25 , NULL , V_29 ,
& V_34 ) ;
if ( F_21 ( V_4 -> V_6 ) ) {
F_24 ( & V_22 -> V_25 , L_2 ) ;
return F_22 ( V_4 -> V_6 ) ;
}
V_4 -> V_38 = F_25 ( & V_22 -> V_25 , NULL ) ;
if ( F_21 ( V_4 -> V_38 ) ) {
F_24 ( & V_22 -> V_25 , L_3 ) ;
return F_22 ( V_4 -> V_38 ) ;
}
V_2 = & V_4 -> V_2 ;
V_2 -> V_39 = & V_40 ;
V_2 -> V_41 = & V_42 ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 = V_45 ;
F_26 ( V_4 -> V_38 ) ;
F_3 ( V_4 -> V_6 , V_46 , & V_5 ) ;
V_2 -> V_47 = V_5 & V_48 ? V_49 : 0 ;
V_2 -> V_12 = F_27 ( unsigned , V_12 , 1 , V_45 ) ;
if ( V_2 -> V_12 != V_12 )
F_28 ( & V_22 -> V_25 , L_4 ,
V_12 , V_2 -> V_12 ) ;
F_29 ( V_22 , V_2 ) ;
F_30 ( V_2 , V_4 ) ;
F_31 ( V_2 , V_50 ) ;
F_32 ( V_2 , V_12 , & V_22 -> V_25 ) ;
F_33 ( & V_4 -> V_17 , F_8 , ( unsigned long ) V_2 ) ;
F_15 ( V_2 ) ;
V_31 = F_34 ( V_2 ) ;
if ( V_31 ) {
F_24 ( & V_22 -> V_25 , L_5 ) ;
return V_31 ;
}
F_35 ( & V_22 -> V_25 , L_6 ,
V_2 -> V_12 , V_50 ) ;
return 0 ;
}
static int T_4 F_36 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_37 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( V_2 ) ;
if ( F_6 ( V_4 ) ) {
F_13 ( & V_4 -> V_17 ) ;
F_7 ( V_2 ) ;
F_39 ( & V_22 -> V_25 , L_7 ) ;
}
return 0 ;
}
static void F_40 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_37 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_6 ( V_4 ) ) {
F_13 ( & V_4 -> V_17 ) ;
F_10 ( V_2 , V_45 ) ;
F_7 ( V_2 ) ;
F_39 ( & V_22 -> V_25 , L_8 ) ;
}
}
