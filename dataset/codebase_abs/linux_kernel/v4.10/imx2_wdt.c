static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = V_8 ;
if ( V_6 -> V_9 )
V_7 |= V_10 ;
else
V_7 |= V_11 ;
F_3 ( V_6 -> V_12 , V_13 , V_7 ) ;
F_3 ( V_6 -> V_12 , V_13 , V_7 ) ;
F_3 ( V_6 -> V_12 , V_13 , V_7 ) ;
F_4 ( 500 ) ;
return 0 ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_14 ;
F_6 ( V_6 -> V_12 , V_13 , & V_14 ) ;
V_14 |= V_15 ;
V_14 &= ~ V_16 ;
if ( ! V_6 -> V_9 )
V_14 &= ~ V_17 ;
else
V_14 |= V_17 ;
V_14 &= ~ V_8 ;
V_14 |= F_7 ( V_2 -> V_18 ) ;
F_3 ( V_6 -> V_12 , V_13 , V_14 ) ;
V_14 |= V_8 ;
F_3 ( V_6 -> V_12 , V_13 , V_14 ) ;
}
static inline bool F_8 ( struct V_5 * V_6 )
{
T_1 V_14 ;
F_6 ( V_6 -> V_12 , V_13 , & V_14 ) ;
return V_14 & V_8 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 -> V_12 , V_19 , V_20 ) ;
F_3 ( V_6 -> V_12 , V_19 , V_21 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_2 -> V_18 = V_22 ;
F_11 ( V_6 -> V_12 , V_13 , V_16 ,
F_7 ( V_22 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_23 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_23 >= V_24 )
return - V_25 ;
V_2 -> V_26 = V_23 ;
F_11 ( V_6 -> V_12 , V_27 ,
V_28 | V_29 ,
V_28 | ( V_23 << 1 ) ) ;
return 0 ;
}
static T_2 F_13 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_14 ( V_6 -> V_12 , V_27 ,
V_32 , V_32 ) ;
F_15 ( V_2 ) ;
return V_33 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_8 ( V_6 ) )
F_10 ( V_2 , V_2 -> V_18 ) ;
else
F_5 ( V_2 ) ;
F_17 ( V_34 , & V_2 -> V_35 ) ;
return F_9 ( V_2 ) ;
}
static int T_3 F_18 ( struct V_36 * V_37 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_38 * V_39 ;
void T_4 * V_40 ;
int V_41 ;
T_1 V_14 ;
V_6 = F_19 ( & V_37 -> V_42 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 )
return - V_44 ;
V_39 = F_20 ( V_37 , V_45 , 0 ) ;
V_40 = F_21 ( & V_37 -> V_42 , V_39 ) ;
if ( F_22 ( V_40 ) )
return F_23 ( V_40 ) ;
V_6 -> V_12 = F_24 ( & V_37 -> V_42 , NULL , V_40 ,
& V_46 ) ;
if ( F_22 ( V_6 -> V_12 ) ) {
F_25 ( & V_37 -> V_42 , L_1 ) ;
return F_23 ( V_6 -> V_12 ) ;
}
V_6 -> V_47 = F_26 ( & V_37 -> V_42 , NULL ) ;
if ( F_22 ( V_6 -> V_47 ) ) {
F_25 ( & V_37 -> V_42 , L_2 ) ;
return F_23 ( V_6 -> V_47 ) ;
}
V_2 = & V_6 -> V_2 ;
V_2 -> V_48 = & V_49 ;
V_2 -> V_50 = & V_51 ;
V_2 -> V_52 = 1 ;
V_2 -> V_53 = V_24 * 1000 ;
V_2 -> V_54 = & V_37 -> V_42 ;
V_41 = F_27 ( V_37 , 0 ) ;
if ( V_41 > 0 )
if ( ! F_28 ( & V_37 -> V_42 , V_41 , F_13 , 0 ,
F_29 ( & V_37 -> V_42 ) , V_2 ) )
V_2 -> V_48 = & V_55 ;
V_41 = F_30 ( V_6 -> V_47 ) ;
if ( V_41 )
return V_41 ;
F_6 ( V_6 -> V_12 , V_56 , & V_14 ) ;
V_2 -> V_57 = V_14 & V_58 ? V_59 : 0 ;
V_6 -> V_9 = F_31 ( V_37 -> V_42 . V_60 ,
L_3 ) ;
V_2 -> V_18 = F_32 ( unsigned , V_18 , 1 , V_24 ) ;
if ( V_2 -> V_18 != V_18 )
F_33 ( & V_37 -> V_42 , L_4 ,
V_18 , V_2 -> V_18 ) ;
F_34 ( V_37 , V_2 ) ;
F_35 ( V_2 , V_6 ) ;
F_36 ( V_2 , V_61 ) ;
F_37 ( V_2 , 128 ) ;
F_38 ( V_2 , V_18 , & V_37 -> V_42 ) ;
if ( F_8 ( V_6 ) ) {
F_10 ( V_2 , V_2 -> V_18 ) ;
F_17 ( V_34 , & V_2 -> V_35 ) ;
}
F_3 ( V_6 -> V_12 , V_62 , 0 ) ;
V_41 = F_39 ( V_2 ) ;
if ( V_41 ) {
F_25 ( & V_37 -> V_42 , L_5 ) ;
goto V_63;
}
F_40 ( & V_37 -> V_42 , L_6 ,
V_2 -> V_18 , V_61 ) ;
return 0 ;
V_63:
F_41 ( V_6 -> V_47 ) ;
return V_41 ;
}
static int T_5 F_42 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_43 ( V_37 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( F_8 ( V_6 ) ) {
F_9 ( V_2 ) ;
F_45 ( & V_37 -> V_42 , L_7 ) ;
}
return 0 ;
}
static void F_46 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_43 ( V_37 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_8 ( V_6 ) ) {
F_10 ( V_2 , V_24 ) ;
F_9 ( V_2 ) ;
F_45 ( & V_37 -> V_42 , L_8 ) ;
}
}
static int F_47 ( struct V_64 * V_42 )
{
struct V_1 * V_2 = F_48 ( V_42 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_8 ( V_6 ) ) {
F_10 ( V_2 , V_24 ) ;
F_9 ( V_2 ) ;
}
F_41 ( V_6 -> V_47 ) ;
return 0 ;
}
static int F_49 ( struct V_64 * V_42 )
{
struct V_1 * V_2 = F_48 ( V_42 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_41 ;
V_41 = F_30 ( V_6 -> V_47 ) ;
if ( V_41 )
return V_41 ;
if ( F_50 ( V_2 ) && ! F_8 ( V_6 ) ) {
F_5 ( V_2 ) ;
}
if ( F_8 ( V_6 ) ) {
F_10 ( V_2 , V_2 -> V_18 ) ;
F_9 ( V_2 ) ;
}
return 0 ;
}
