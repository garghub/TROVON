static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
unsigned int V_5 = V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 ,
V_9 ) ;
F_3 ( V_8 -> V_10 , V_11 , V_5 ) ;
F_3 ( V_8 -> V_10 , V_11 , V_5 ) ;
F_3 ( V_8 -> V_10 , V_11 , V_5 ) ;
F_4 ( 500 ) ;
return V_12 ;
}
static inline void F_5 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_6 ( V_14 ) ;
T_1 V_15 ;
F_7 ( V_8 -> V_10 , V_11 , & V_15 ) ;
V_15 |= V_16 ;
V_15 &= ~ V_17 ;
V_15 &= ~ V_18 ;
V_15 &= ~ V_6 ;
V_15 |= F_8 ( V_14 -> V_19 ) ;
F_3 ( V_8 -> V_10 , V_11 , V_15 ) ;
V_15 |= V_6 ;
F_3 ( V_8 -> V_10 , V_11 , V_15 ) ;
}
static inline bool F_9 ( struct V_7 * V_8 )
{
T_1 V_15 ;
F_7 ( V_8 -> V_10 , V_11 , & V_15 ) ;
return V_15 & V_6 ;
}
static int F_10 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_6 ( V_14 ) ;
F_3 ( V_8 -> V_10 , V_20 , V_21 ) ;
F_3 ( V_8 -> V_10 , V_20 , V_22 ) ;
return 0 ;
}
static void F_11 ( unsigned long V_23 )
{
struct V_13 * V_14 = (struct V_13 * ) V_23 ;
struct V_7 * V_8 = F_6 ( V_14 ) ;
F_10 ( V_14 ) ;
F_12 ( & V_8 -> V_24 , V_25 + V_14 -> V_19 * V_26 / 2 ) ;
}
static int F_13 ( struct V_13 * V_14 ,
unsigned int V_27 )
{
struct V_7 * V_8 = F_6 ( V_14 ) ;
V_14 -> V_19 = V_27 ;
F_14 ( V_8 -> V_10 , V_11 , V_17 ,
F_8 ( V_27 ) ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_6 ( V_14 ) ;
if ( F_9 ( V_8 ) ) {
F_16 ( & V_8 -> V_24 ) ;
F_13 ( V_14 , V_14 -> V_19 ) ;
} else
F_5 ( V_14 ) ;
return F_10 ( V_14 ) ;
}
static int F_17 ( struct V_13 * V_14 )
{
F_11 ( ( unsigned long ) V_14 ) ;
return 0 ;
}
static inline void F_18 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_6 ( V_14 ) ;
if ( F_9 ( V_8 ) ) {
F_13 ( V_14 , V_14 -> V_19 ) ;
F_11 ( ( unsigned long ) V_14 ) ;
}
}
static int T_2 F_19 ( struct V_28 * V_29 )
{
struct V_7 * V_8 ;
struct V_13 * V_14 ;
struct V_30 * V_31 ;
void T_3 * V_32 ;
int V_33 ;
T_1 V_15 ;
V_8 = F_20 ( & V_29 -> V_34 , sizeof( * V_8 ) , V_35 ) ;
if ( ! V_8 )
return - V_36 ;
V_31 = F_21 ( V_29 , V_37 , 0 ) ;
V_32 = F_22 ( & V_29 -> V_34 , V_31 ) ;
if ( F_23 ( V_32 ) )
return F_24 ( V_32 ) ;
V_8 -> V_10 = F_25 ( & V_29 -> V_34 , NULL , V_32 ,
& V_38 ) ;
if ( F_23 ( V_8 -> V_10 ) ) {
F_26 ( & V_29 -> V_34 , L_1 ) ;
return F_24 ( V_8 -> V_10 ) ;
}
V_8 -> V_39 = F_27 ( & V_29 -> V_34 , NULL ) ;
if ( F_23 ( V_8 -> V_39 ) ) {
F_26 ( & V_29 -> V_34 , L_2 ) ;
return F_24 ( V_8 -> V_39 ) ;
}
V_14 = & V_8 -> V_14 ;
V_14 -> V_40 = & V_41 ;
V_14 -> V_42 = & V_43 ;
V_14 -> V_44 = 1 ;
V_14 -> V_45 = V_46 ;
V_14 -> V_47 = & V_29 -> V_34 ;
V_33 = F_28 ( V_8 -> V_39 ) ;
if ( V_33 )
return V_33 ;
F_7 ( V_8 -> V_10 , V_48 , & V_15 ) ;
V_14 -> V_49 = V_15 & V_50 ? V_51 : 0 ;
V_14 -> V_19 = F_29 ( unsigned , V_19 , 1 , V_46 ) ;
if ( V_14 -> V_19 != V_19 )
F_30 ( & V_29 -> V_34 , L_3 ,
V_19 , V_14 -> V_19 ) ;
F_31 ( V_29 , V_14 ) ;
F_32 ( V_14 , V_8 ) ;
F_33 ( V_14 , V_52 ) ;
F_34 ( V_14 , V_19 , & V_29 -> V_34 ) ;
F_35 ( & V_8 -> V_24 , F_11 , ( unsigned long ) V_14 ) ;
F_18 ( V_14 ) ;
F_3 ( V_8 -> V_10 , V_53 , 0 ) ;
V_33 = F_36 ( V_14 ) ;
if ( V_33 ) {
F_26 ( & V_29 -> V_34 , L_4 ) ;
goto V_54;
}
V_8 -> V_9 . V_55 = F_1 ;
V_8 -> V_9 . V_56 = 128 ;
V_33 = F_37 ( & V_8 -> V_9 ) ;
if ( V_33 )
F_26 ( & V_29 -> V_34 , L_5 ) ;
F_38 ( & V_29 -> V_34 , L_6 ,
V_14 -> V_19 , V_52 ) ;
return 0 ;
V_54:
F_39 ( V_8 -> V_39 ) ;
return V_33 ;
}
static int T_4 F_40 ( struct V_28 * V_29 )
{
struct V_13 * V_14 = F_41 ( V_29 ) ;
struct V_7 * V_8 = F_6 ( V_14 ) ;
F_42 ( & V_8 -> V_9 ) ;
F_43 ( V_14 ) ;
if ( F_9 ( V_8 ) ) {
F_16 ( & V_8 -> V_24 ) ;
F_10 ( V_14 ) ;
F_44 ( & V_29 -> V_34 , L_7 ) ;
}
return 0 ;
}
static void F_45 ( struct V_28 * V_29 )
{
struct V_13 * V_14 = F_41 ( V_29 ) ;
struct V_7 * V_8 = F_6 ( V_14 ) ;
if ( F_9 ( V_8 ) ) {
F_16 ( & V_8 -> V_24 ) ;
F_13 ( V_14 , V_46 ) ;
F_10 ( V_14 ) ;
F_44 ( & V_29 -> V_34 , L_8 ) ;
}
}
static int F_46 ( struct V_57 * V_34 )
{
struct V_13 * V_14 = F_47 ( V_34 ) ;
struct V_7 * V_8 = F_6 ( V_14 ) ;
if ( F_9 ( V_8 ) ) {
F_13 ( V_14 , V_46 ) ;
F_10 ( V_14 ) ;
if ( ! F_48 ( V_14 ) )
F_16 ( & V_8 -> V_24 ) ;
}
F_39 ( V_8 -> V_39 ) ;
return 0 ;
}
static int F_49 ( struct V_57 * V_34 )
{
struct V_13 * V_14 = F_47 ( V_34 ) ;
struct V_7 * V_8 = F_6 ( V_14 ) ;
int V_33 ;
V_33 = F_28 ( V_8 -> V_39 ) ;
if ( V_33 )
return V_33 ;
if ( F_48 ( V_14 ) && ! F_9 ( V_8 ) ) {
F_5 ( V_14 ) ;
F_13 ( V_14 , V_14 -> V_19 ) ;
F_10 ( V_14 ) ;
} else if ( F_9 ( V_8 ) ) {
F_13 ( V_14 , V_14 -> V_19 ) ;
F_10 ( V_14 ) ;
if ( ! F_48 ( V_14 ) )
F_12 ( & V_8 -> V_24 ,
V_25 + V_14 -> V_19 * V_26 / 2 ) ;
}
return 0 ;
}
