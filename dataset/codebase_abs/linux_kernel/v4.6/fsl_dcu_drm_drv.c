static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 == V_4 || V_3 == V_5 )
return true ;
return false ;
}
static int F_2 ( struct V_6 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
V_10 = F_3 ( V_2 , V_8 -> V_11 ) ;
if ( V_10 < 0 )
F_4 ( V_2 -> V_2 , L_1 ) ;
F_5 ( V_8 -> V_12 , V_4 , 0 ) ;
F_5 ( V_8 -> V_12 , V_13 , ~ 0 ) ;
F_5 ( V_8 -> V_12 , V_5 ,
V_14 ) ;
return V_10 ;
}
static int F_6 ( struct V_6 * V_15 , unsigned long V_16 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_7 * V_8 = V_15 -> V_9 ;
int V_10 ;
V_10 = F_7 ( V_8 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_2 ) ;
return V_10 ;
}
V_10 = F_8 ( V_15 , V_15 -> V_17 . V_18 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_3 ) ;
goto V_19;
}
V_15 -> V_20 = true ;
V_10 = F_2 ( V_15 ) ;
if ( V_10 < 0 )
goto V_19;
V_15 -> V_21 = true ;
F_9 ( V_15 ) ;
return 0 ;
V_19:
if ( V_10 ) {
F_10 ( V_15 ) ;
F_11 ( V_15 ) ;
F_12 ( V_15 ) ;
V_15 -> V_9 = NULL ;
}
return V_10 ;
}
static int F_13 ( struct V_6 * V_2 )
{
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
}
static T_1 F_14 ( int V_11 , void * V_22 )
{
struct V_6 * V_2 = V_22 ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_23 ;
int V_10 ;
V_10 = F_15 ( V_8 -> V_12 , V_4 , & V_23 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_2 , L_4 ) ;
return V_24 ;
}
if ( V_23 & V_25 )
F_16 ( V_2 , 0 ) ;
F_5 ( V_8 -> V_12 , V_4 , V_23 ) ;
F_5 ( V_8 -> V_12 , V_5 ,
V_14 ) ;
return V_26 ;
}
static int F_17 ( struct V_6 * V_2 , unsigned int V_27 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_28 ;
F_15 ( V_8 -> V_12 , V_13 , & V_28 ) ;
V_28 &= ~ V_29 ;
F_5 ( V_8 -> V_12 , V_13 , V_28 ) ;
return 0 ;
}
static void F_18 ( struct V_6 * V_2 ,
unsigned int V_27 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_28 ;
F_15 ( V_8 -> V_12 , V_13 , & V_28 ) ;
V_28 |= V_29 ;
F_5 ( V_8 -> V_12 , V_13 , V_28 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_20 ( V_2 ) ;
if ( ! V_8 )
return 0 ;
F_21 ( V_8 -> V_15 ) ;
F_22 ( V_8 -> V_12 , true ) ;
F_23 ( V_8 -> V_12 ) ;
F_24 ( V_8 -> V_30 ) ;
F_25 ( V_8 -> V_30 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_20 ( V_2 ) ;
int V_10 ;
if ( ! V_8 )
return 0 ;
V_10 = F_27 ( V_8 -> V_30 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_5 ) ;
F_25 ( V_8 -> V_30 ) ;
return V_10 ;
}
V_10 = F_28 ( V_8 -> V_30 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_6 ) ;
return V_10 ;
}
F_29 ( V_8 -> V_15 ) ;
F_22 ( V_8 -> V_12 , false ) ;
F_30 ( V_8 -> V_12 ) ;
return 0 ;
}
static int F_31 ( struct V_31 * V_32 )
{
struct V_7 * V_8 ;
struct V_6 * V_15 ;
struct V_1 * V_2 = & V_32 -> V_2 ;
struct V_33 * V_34 ;
void T_2 * V_35 ;
struct V_36 * V_37 = & V_38 ;
const struct V_39 * V_40 ;
int V_10 ;
V_8 = F_32 ( V_2 , sizeof( * V_8 ) , V_41 ) ;
if ( ! V_8 )
return - V_42 ;
V_34 = F_33 ( V_32 , V_43 , 0 ) ;
if ( ! V_34 ) {
F_4 ( V_2 , L_7 ) ;
return - V_44 ;
}
V_35 = F_34 ( V_2 , V_34 ) ;
if ( F_35 ( V_35 ) ) {
V_10 = F_36 ( V_35 ) ;
return V_10 ;
}
V_8 -> V_11 = F_37 ( V_32 , 0 ) ;
if ( V_8 -> V_11 < 0 ) {
F_4 ( V_2 , L_8 ) ;
return - V_45 ;
}
V_8 -> V_30 = F_38 ( V_2 , L_9 ) ;
if ( F_35 ( V_8 -> V_30 ) ) {
V_10 = F_36 ( V_8 -> V_30 ) ;
F_4 ( V_2 , L_10 ) ;
return V_10 ;
}
V_10 = F_28 ( V_8 -> V_30 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_6 ) ;
return V_10 ;
}
V_10 = F_27 ( V_8 -> V_30 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 , L_5 ) ;
F_25 ( V_8 -> V_30 ) ;
return V_10 ;
}
V_8 -> V_12 = F_39 ( V_2 , V_35 ,
& V_46 ) ;
if ( F_35 ( V_8 -> V_12 ) ) {
F_4 ( V_2 , L_11 ) ;
return F_36 ( V_8 -> V_12 ) ;
}
V_40 = F_40 ( V_47 , V_32 -> V_2 . V_48 ) ;
if ( ! V_40 )
return - V_44 ;
V_8 -> V_49 = V_40 -> V_50 ;
V_15 = F_41 ( V_37 , V_2 ) ;
if ( ! V_15 )
return - V_42 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_51 = V_2 -> V_48 ;
V_15 -> V_9 = V_8 ;
F_42 ( V_2 , V_8 ) ;
V_10 = F_43 ( V_15 , 0 ) ;
if ( V_10 < 0 )
goto V_52;
F_44 ( L_12 , V_37 -> V_53 ,
V_37 -> V_54 , V_37 -> V_55 , V_37 -> V_56 ,
V_37 -> V_57 , V_15 -> V_58 -> V_59 ) ;
return 0 ;
V_52:
F_45 ( V_15 ) ;
return V_10 ;
}
static int F_46 ( struct V_31 * V_32 )
{
struct V_7 * V_8 = F_47 ( V_32 ) ;
F_48 ( V_8 -> V_15 ) ;
return 0 ;
}
