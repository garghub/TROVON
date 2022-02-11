static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) ) ;
}
static inline struct V_3 * F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_5 ( V_5 ) ;
return V_7 -> V_8 ;
}
static int F_6 ( struct V_4 * V_5 , unsigned V_9 )
{
if ( V_9 >= V_10 )
return - V_11 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 ,
unsigned V_9 )
{
struct V_3 * V_8 = F_4 ( V_5 ) ;
F_8 ( V_8 -> V_2 , L_1 , V_9 ) ;
return F_9 ( V_8 , V_12 ,
1 << V_9 , 1 << V_9 ) ;
}
static int F_10 ( struct V_4 * V_5 , unsigned V_9 )
{
struct V_3 * V_8 = F_4 ( V_5 ) ;
int V_13 ;
V_13 = F_11 ( V_8 , V_14 ) ;
F_8 ( V_8 -> V_2 , L_2 , V_9 ,
V_13 < 0 ? V_13 : V_13 & ( 1 << V_9 ) ) ;
return V_13 < 0 ? V_13 : ! ! ( V_13 & ( 1 << V_9 ) ) ;
}
static void F_12 ( struct V_4 * V_5 , unsigned V_9 ,
int V_15 )
{
struct V_6 * V_7 = F_5 ( V_5 ) ;
struct V_3 * V_8 = F_4 ( V_5 ) ;
V_7 -> V_16 &= ~ ( 1 << V_9 ) ;
V_7 -> V_16 |= ( ! ! V_15 ) << V_9 ;
F_13 ( V_8 , V_14 , V_7 -> V_16 ) ;
F_8 ( V_8 -> V_2 , L_3 , V_9 , ! ! V_15 ) ;
}
static int F_14 ( struct V_4 * V_5 ,
unsigned V_9 , int V_15 )
{
struct V_3 * V_8 = F_4 ( V_5 ) ;
F_8 ( V_8 -> V_2 , L_1 , V_9 ) ;
F_12 ( V_5 , V_9 , V_15 ) ;
return F_9 ( V_8 , V_12 , 1 << V_9 , 0 ) ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_3 * V_8 )
{
struct V_6 * V_7 ;
int V_13 ;
V_7 = F_16 ( V_8 -> V_2 , sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
return - V_20 ;
V_18 -> V_7 = V_7 ;
V_7 -> V_8 = V_8 ;
V_7 -> V_4 = V_21 ;
V_7 -> V_4 . V_22 = V_10 ;
V_7 -> V_4 . V_23 = V_8 -> V_2 ;
V_7 -> V_4 . V_24 = - 1 ;
V_13 = F_17 ( & V_7 -> V_4 , V_7 ) ;
if ( V_13 != 0 )
F_18 ( V_8 -> V_2 , L_4 , V_13 ) ;
return V_13 ;
}
static void F_19 ( struct V_17 * V_18 )
{
F_20 ( & V_18 -> V_7 -> V_4 ) ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_3 * V_8 )
{
return 0 ;
}
static void F_19 ( struct V_17 * V_18 )
{
}
struct V_17 * F_21 ( struct V_3 * V_8 )
{
struct V_17 * V_18 ;
V_18 = F_22 ( sizeof( struct V_17 ) , V_19 ) ;
if ( V_18 == NULL )
return F_23 ( - V_20 ) ;
V_18 -> V_25 = & V_26 ;
V_18 -> V_27 = 0 ;
V_18 -> V_2 . V_25 = & V_28 ;
V_18 -> V_2 . V_23 = V_8 -> V_29 . V_30 -> V_2 ;
V_18 -> V_2 . V_31 = F_1 ;
F_24 ( & V_18 -> V_2 , L_5 ,
V_8 -> V_29 . V_30 -> V_32 -> V_33 , 0 ,
V_8 -> V_29 . V_34 ) ;
F_25 ( & V_18 -> V_2 ) ;
return V_18 ;
}
struct V_17 * F_26 ( struct V_3 * V_8 ,
unsigned int V_35 , unsigned int V_36 )
{
struct V_17 * V_18 ;
int V_13 ;
V_18 = F_21 ( V_8 ) ;
if ( F_27 ( V_18 ) )
return V_18 ;
if ( V_35 ) {
V_13 = F_28 ( V_18 , false , V_35 , V_36 ) ;
if ( V_13 < 0 ) {
F_18 ( V_8 -> V_2 , L_6 ,
V_13 ) ;
goto V_37;
}
}
V_13 = F_29 ( & V_18 -> V_2 ) ;
if ( V_13 )
goto V_37;
V_13 = F_15 ( V_18 , V_8 ) ;
if ( V_13 )
goto V_37;
return V_18 ;
V_37:
F_30 ( & V_18 -> V_2 ) ;
return F_23 ( V_13 ) ;
}
void F_31 ( struct V_17 * V_18 )
{
F_19 ( V_18 ) ;
F_32 ( & V_18 -> V_2 ) ;
V_18 -> V_25 = NULL ;
F_30 ( & V_18 -> V_2 ) ;
}
static void F_33 ( struct V_17 * V_18 )
{
struct V_38 * V_39 = V_40 . V_39 ;
F_34 ( V_39 , V_40 . V_41 ) ;
F_35 ( V_40 . V_42 , 1 ) ;
F_36 ( 10 ) ;
F_35 ( V_40 . V_42 , 0 ) ;
F_34 ( V_39 , V_40 . V_43 ) ;
F_37 ( 2 ) ;
}
static void F_38 ( struct V_17 * V_18 )
{
struct V_38 * V_39 = V_40 . V_39 ;
F_34 ( V_39 , V_40 . V_44 ) ;
F_35 ( V_40 . V_42 , 0 ) ;
F_35 ( V_40 . V_45 , 0 ) ;
F_35 ( V_40 . V_46 , 0 ) ;
F_36 ( 10 ) ;
F_35 ( V_40 . V_46 , 1 ) ;
F_34 ( V_39 , V_40 . V_43 ) ;
F_37 ( 2 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_38 * V_49 ;
struct V_50 * V_51 ;
int V_52 ;
int V_13 ;
V_49 = F_40 ( V_2 ) ;
if ( F_27 ( V_49 ) ) {
F_18 ( V_2 , L_7 ) ;
return F_41 ( V_49 ) ;
}
V_48 -> V_39 = V_49 ;
V_51 = F_42 ( V_49 , L_8 ) ;
if ( F_27 ( V_51 ) ) {
F_18 ( V_2 , L_9 ) ;
return F_41 ( V_51 ) ;
}
V_48 -> V_44 = V_51 ;
V_51 = F_42 ( V_49 , L_10 ) ;
if ( F_27 ( V_51 ) ) {
F_18 ( V_2 , L_11 ) ;
return F_41 ( V_51 ) ;
}
V_48 -> V_41 = V_51 ;
V_51 = F_42 ( V_49 , L_12 ) ;
if ( F_27 ( V_51 ) ) {
F_18 ( V_2 , L_13 ) ;
return F_41 ( V_51 ) ;
}
V_48 -> V_43 = V_51 ;
V_52 = F_43 ( V_2 -> V_53 , L_14 , 0 ) ;
if ( V_52 < 0 ) {
F_18 ( V_2 , L_15 ) ;
return V_52 ;
}
V_13 = F_44 ( V_2 , V_52 , L_16 ) ;
if ( V_13 ) {
F_18 ( V_2 , L_17 ) ;
return V_13 ;
}
V_48 -> V_42 = V_52 ;
V_52 = F_43 ( V_2 -> V_53 , L_14 , 1 ) ;
if ( V_52 < 0 ) {
F_18 ( V_2 , L_18 , V_52 ) ;
return V_52 ;
}
V_13 = F_44 ( V_2 , V_52 , L_19 ) ;
if ( V_13 ) {
F_18 ( V_2 , L_20 ) ;
return V_13 ;
}
V_48 -> V_45 = V_52 ;
V_52 = F_43 ( V_2 -> V_53 , L_14 , 2 ) ;
if ( V_52 < 0 ) {
F_18 ( V_2 , L_21 ) ;
return V_52 ;
}
V_13 = F_44 ( V_2 , V_52 , L_22 ) ;
if ( V_13 ) {
F_18 ( V_2 , L_23 ) ;
return V_13 ;
}
V_48 -> V_46 = V_52 ;
return 0 ;
}
int F_45 ( struct V_54 * V_55 )
{
if ( V_55 == V_56 )
return 0 ;
if ( V_56 && V_55 )
return - V_57 ;
V_56 = V_55 ;
V_26 . V_55 = V_55 ;
return 0 ;
}
int F_46 ( struct V_54 * V_55 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = & V_59 -> V_2 ;
struct V_47 V_48 ;
int V_13 ;
V_13 = F_39 ( V_2 , & V_48 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_45 ( V_55 ) ;
if ( V_13 )
return V_13 ;
V_55 -> V_60 = F_33 ;
V_55 -> V_61 = F_38 ;
V_40 = V_48 ;
return 0 ;
}
