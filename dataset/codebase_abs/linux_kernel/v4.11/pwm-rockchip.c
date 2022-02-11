static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_4 ,
struct V_5 * V_6 , bool V_7 ,
enum V_8 V_9 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_1 V_11 = V_12 | V_13 ;
T_1 V_14 ;
V_14 = F_4 ( V_10 -> V_15 + V_10 -> V_16 -> V_17 . V_18 ) ;
if ( V_7 )
V_14 |= V_11 ;
else
V_14 &= ~ V_11 ;
F_5 ( V_14 , V_10 -> V_15 + V_10 -> V_16 -> V_17 . V_18 ) ;
}
static void F_6 ( struct V_2 * V_4 ,
struct V_5 * V_6 ,
struct V_19 * V_20 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_1 V_11 = V_12 | V_13 ;
T_1 V_14 ;
V_14 = F_4 ( V_10 -> V_15 + V_10 -> V_16 -> V_17 . V_18 ) ;
if ( ( V_14 & V_11 ) == V_11 )
V_20 -> V_21 = true ;
}
static void F_7 ( struct V_2 * V_4 ,
struct V_5 * V_6 , bool V_7 ,
enum V_8 V_9 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_1 V_11 = V_22 | V_23 | V_24 |
V_25 ;
T_1 V_14 ;
if ( V_9 == V_26 )
V_11 |= V_27 | V_28 ;
else
V_11 |= V_29 | V_30 ;
V_14 = F_4 ( V_10 -> V_15 + V_10 -> V_16 -> V_17 . V_18 ) ;
if ( V_7 )
V_14 |= V_11 ;
else
V_14 &= ~ V_11 ;
F_5 ( V_14 , V_10 -> V_15 + V_10 -> V_16 -> V_17 . V_18 ) ;
}
static void F_8 ( struct V_2 * V_4 ,
struct V_5 * V_6 ,
struct V_19 * V_20 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_1 V_11 = V_22 | V_23 | V_24 |
V_25 ;
T_1 V_14 ;
V_14 = F_4 ( V_10 -> V_15 + V_10 -> V_16 -> V_17 . V_18 ) ;
if ( ( V_14 & V_11 ) != V_11 )
return;
V_20 -> V_21 = true ;
if ( ! ( V_14 & V_29 ) )
V_20 -> V_9 = V_26 ;
}
static void F_9 ( struct V_2 * V_4 ,
struct V_5 * V_6 ,
struct V_19 * V_20 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_31 ;
T_2 V_32 ;
int V_33 ;
V_33 = F_10 ( V_10 -> V_34 ) ;
if ( V_33 )
return;
V_31 = F_11 ( V_10 -> V_34 ) ;
V_32 = F_4 ( V_10 -> V_15 + V_10 -> V_16 -> V_17 . V_35 ) ;
V_32 *= V_10 -> V_16 -> V_36 * V_37 ;
V_20 -> V_35 = F_12 ( V_32 , V_31 ) ;
V_32 = F_4 ( V_10 -> V_15 + V_10 -> V_16 -> V_17 . V_38 ) ;
V_32 *= V_10 -> V_16 -> V_36 * V_37 ;
V_20 -> V_39 = F_12 ( V_32 , V_31 ) ;
V_10 -> V_16 -> V_40 ( V_4 , V_6 , V_20 ) ;
F_13 ( V_10 -> V_34 ) ;
}
static int F_14 ( struct V_2 * V_4 , struct V_5 * V_6 ,
int V_41 , int V_42 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_35 , V_38 ;
T_2 V_31 , div ;
V_31 = F_11 ( V_10 -> V_34 ) ;
div = V_31 * V_42 ;
V_35 = F_12 ( div ,
V_10 -> V_16 -> V_36 * V_37 ) ;
div = V_31 * V_41 ;
V_38 = F_12 ( div , V_10 -> V_16 -> V_36 * V_37 ) ;
F_15 ( V_35 , V_10 -> V_15 + V_10 -> V_16 -> V_17 . V_35 ) ;
F_15 ( V_38 , V_10 -> V_15 + V_10 -> V_16 -> V_17 . V_38 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_4 ,
struct V_5 * V_6 ,
bool V_7 ,
enum V_8 V_9 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_33 ;
if ( V_7 ) {
V_33 = F_10 ( V_10 -> V_34 ) ;
if ( V_33 )
return V_33 ;
}
V_10 -> V_16 -> V_43 ( V_4 , V_6 , V_7 , V_9 ) ;
if ( ! V_7 )
F_13 ( V_10 -> V_34 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_4 , struct V_5 * V_6 ,
struct V_19 * V_20 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_19 V_44 ;
bool V_21 ;
int V_33 ;
F_18 ( V_6 , & V_44 ) ;
V_21 = V_44 . V_21 ;
V_33 = F_10 ( V_10 -> V_34 ) ;
if ( V_33 )
return V_33 ;
if ( V_20 -> V_9 != V_44 . V_9 && V_21 ) {
V_33 = F_16 ( V_4 , V_6 , false , V_20 -> V_9 ) ;
if ( V_33 )
goto V_45;
V_21 = false ;
}
V_33 = F_14 ( V_4 , V_6 , V_20 -> V_39 , V_20 -> V_35 ) ;
if ( V_33 ) {
if ( V_21 != V_44 . V_21 )
F_16 ( V_4 , V_6 , ! V_21 ,
V_20 -> V_9 ) ;
goto V_45;
}
if ( V_20 -> V_21 != V_21 ) {
V_33 = F_16 ( V_4 , V_6 , V_20 -> V_21 ,
V_20 -> V_9 ) ;
if ( V_33 )
goto V_45;
}
F_9 ( V_4 , V_6 , V_20 ) ;
V_45:
F_13 ( V_10 -> V_34 ) ;
return V_33 ;
}
static int F_19 ( struct V_46 * V_47 )
{
const struct V_48 * V_49 ;
struct V_1 * V_10 ;
struct V_50 * V_51 ;
int V_33 ;
V_49 = F_20 ( V_52 , & V_47 -> V_53 ) ;
if ( ! V_49 )
return - V_54 ;
V_10 = F_21 ( & V_47 -> V_53 , sizeof( * V_10 ) , V_55 ) ;
if ( ! V_10 )
return - V_56 ;
V_51 = F_22 ( V_47 , V_57 , 0 ) ;
V_10 -> V_15 = F_23 ( & V_47 -> V_53 , V_51 ) ;
if ( F_24 ( V_10 -> V_15 ) )
return F_25 ( V_10 -> V_15 ) ;
V_10 -> V_34 = F_26 ( & V_47 -> V_53 , NULL ) ;
if ( F_24 ( V_10 -> V_34 ) )
return F_25 ( V_10 -> V_34 ) ;
V_33 = F_27 ( V_10 -> V_34 ) ;
if ( V_33 )
return V_33 ;
F_28 ( V_47 , V_10 ) ;
V_10 -> V_16 = V_49 -> V_16 ;
V_10 -> V_4 . V_53 = & V_47 -> V_53 ;
V_10 -> V_4 . V_58 = V_10 -> V_16 -> V_58 ;
V_10 -> V_4 . V_15 = - 1 ;
V_10 -> V_4 . V_59 = 1 ;
if ( V_10 -> V_16 -> V_60 ) {
V_10 -> V_4 . V_61 = V_62 ;
V_10 -> V_4 . V_63 = 3 ;
}
V_33 = F_29 ( & V_10 -> V_4 ) ;
if ( V_33 < 0 ) {
F_30 ( V_10 -> V_34 ) ;
F_31 ( & V_47 -> V_53 , L_1 , V_33 ) ;
}
if ( ! F_32 ( V_10 -> V_4 . V_64 ) )
F_13 ( V_10 -> V_34 ) ;
return V_33 ;
}
static int F_33 ( struct V_46 * V_47 )
{
struct V_1 * V_10 = F_34 ( V_47 ) ;
if ( F_32 ( V_10 -> V_4 . V_64 ) )
F_13 ( V_10 -> V_34 ) ;
F_30 ( V_10 -> V_34 ) ;
return F_35 ( & V_10 -> V_4 ) ;
}
