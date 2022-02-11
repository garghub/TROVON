static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 , V_4 -> V_8 ) ;
if ( V_7 < 0 )
F_3 ( V_2 -> V_2 , L_1 ) ;
V_7 = F_4 ( V_4 -> V_9 , V_10 , 0 ) ;
if ( V_7 )
F_3 ( V_2 -> V_2 , L_2 ) ;
V_7 = F_5 ( V_4 -> V_9 , V_11 , & V_6 ) ;
if ( V_7 )
F_3 ( V_2 -> V_2 , L_3 ) ;
V_6 &= V_12 ;
V_7 = F_4 ( V_4 -> V_9 , V_11 , V_6 ) ;
if ( V_7 )
F_3 ( V_2 -> V_2 , L_4 ) ;
V_7 = F_4 ( V_4 -> V_9 , V_13 ,
V_14 ) ;
if ( V_7 )
F_3 ( V_2 -> V_2 , L_5 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_15 , unsigned long V_16 )
{
struct V_17 * V_2 = V_15 -> V_2 ;
struct V_3 * V_4 = V_15 -> V_5 ;
int V_7 ;
V_7 = F_7 ( V_4 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_6 ) ;
return V_7 ;
}
V_7 = F_8 ( V_15 , V_15 -> V_18 . V_19 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_7 ) ;
goto V_20;
}
V_15 -> V_21 = true ;
V_7 = F_1 ( V_15 ) ;
if ( V_7 < 0 )
goto V_20;
V_15 -> V_22 = true ;
F_9 ( V_15 ) ;
return 0 ;
V_20:
if ( V_7 ) {
F_10 ( V_15 ) ;
F_11 ( V_15 ) ;
F_12 ( V_15 ) ;
V_15 -> V_5 = NULL ;
}
return V_7 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
}
static T_1 F_15 ( int V_8 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_26 ;
int V_7 ;
V_7 = F_5 ( V_4 -> V_9 , V_10 , & V_26 ) ;
if ( V_7 )
F_3 ( V_2 -> V_2 , L_2 ) ;
if ( V_26 & V_27 )
F_16 ( V_2 , 0 ) ;
V_7 = F_4 ( V_4 -> V_9 , V_10 , 0xffffffff ) ;
if ( V_7 )
F_3 ( V_2 -> V_2 , L_2 ) ;
V_7 = F_4 ( V_4 -> V_9 , V_13 ,
V_14 ) ;
if ( V_7 )
F_3 ( V_2 -> V_2 , L_5 ) ;
return V_28 ;
}
static int F_17 ( struct V_1 * V_2 , int V_29 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_6 ;
int V_7 ;
V_7 = F_5 ( V_4 -> V_9 , V_11 , & V_6 ) ;
if ( V_7 )
F_3 ( V_2 -> V_2 , L_3 ) ;
V_6 &= ~ V_12 ;
V_7 = F_4 ( V_4 -> V_9 , V_11 , V_6 ) ;
if ( V_7 )
F_3 ( V_2 -> V_2 , L_4 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , int V_29 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_6 ;
int V_7 ;
V_7 = F_5 ( V_4 -> V_9 , V_11 , & V_6 ) ;
if ( V_7 )
F_3 ( V_2 -> V_2 , L_3 ) ;
V_6 |= V_12 ;
V_7 = F_4 ( V_4 -> V_9 , V_11 , V_6 ) ;
if ( V_7 )
F_3 ( V_2 -> V_2 , L_4 ) ;
}
static int F_19 ( struct V_17 * V_2 )
{
struct V_3 * V_4 = F_20 ( V_2 ) ;
if ( ! V_4 )
return 0 ;
F_21 ( V_4 -> V_15 ) ;
F_22 ( V_4 -> V_9 , true ) ;
F_23 ( V_4 -> V_9 ) ;
F_24 ( V_4 -> V_30 ) ;
F_25 ( V_4 -> V_30 ) ;
return 0 ;
}
static int F_26 ( struct V_17 * V_2 )
{
struct V_3 * V_4 = F_20 ( V_2 ) ;
int V_7 ;
if ( ! V_4 )
return 0 ;
V_7 = F_27 ( V_4 -> V_30 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_8 ) ;
F_25 ( V_4 -> V_30 ) ;
return V_7 ;
}
V_7 = F_28 ( V_4 -> V_30 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_9 ) ;
return V_7 ;
}
F_29 ( V_4 -> V_15 ) ;
F_22 ( V_4 -> V_9 , false ) ;
F_30 ( V_4 -> V_9 ) ;
return 0 ;
}
static int F_31 ( struct V_31 * V_32 )
{
struct V_3 * V_4 ;
struct V_1 * V_15 ;
struct V_17 * V_2 = & V_32 -> V_2 ;
struct V_33 * V_34 ;
void T_2 * V_35 ;
struct V_36 * V_37 = & V_38 ;
const struct V_39 * V_40 ;
int V_7 ;
V_4 = F_32 ( V_2 , sizeof( * V_4 ) , V_41 ) ;
if ( ! V_4 )
return - V_42 ;
V_34 = F_33 ( V_32 , V_43 , 0 ) ;
if ( ! V_34 ) {
F_3 ( V_2 , L_10 ) ;
return - V_44 ;
}
V_35 = F_34 ( V_2 , V_34 ) ;
if ( F_35 ( V_35 ) ) {
V_7 = F_36 ( V_35 ) ;
return V_7 ;
}
V_4 -> V_8 = F_37 ( V_32 , 0 ) ;
if ( V_4 -> V_8 < 0 ) {
F_3 ( V_2 , L_11 ) ;
return - V_45 ;
}
V_4 -> V_30 = F_38 ( V_2 , L_12 ) ;
if ( F_35 ( V_4 -> V_30 ) ) {
V_7 = F_36 ( V_4 -> V_30 ) ;
F_3 ( V_2 , L_13 ) ;
return V_7 ;
}
V_7 = F_28 ( V_4 -> V_30 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_9 ) ;
return V_7 ;
}
V_7 = F_27 ( V_4 -> V_30 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_8 ) ;
F_25 ( V_4 -> V_30 ) ;
return V_7 ;
}
V_4 -> V_9 = F_39 ( V_2 , V_35 ,
& V_46 ) ;
if ( F_35 ( V_4 -> V_9 ) ) {
F_3 ( V_2 , L_14 ) ;
return F_36 ( V_4 -> V_9 ) ;
}
V_40 = F_40 ( V_47 , V_32 -> V_2 . V_48 ) ;
if ( ! V_40 )
return - V_44 ;
V_4 -> V_49 = V_40 -> V_50 ;
V_15 = F_41 ( V_37 , V_2 ) ;
if ( ! V_15 )
return - V_42 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_51 = V_2 -> V_48 ;
V_15 -> V_5 = V_4 ;
F_42 ( V_2 , V_4 ) ;
F_43 ( V_15 , F_44 ( V_2 ) ) ;
V_7 = F_45 ( V_15 , 0 ) ;
if ( V_7 < 0 )
goto V_52;
F_46 ( L_15 , V_37 -> V_53 ,
V_37 -> V_54 , V_37 -> V_55 , V_37 -> V_56 ,
V_37 -> V_57 , V_15 -> V_58 -> V_59 ) ;
return 0 ;
V_52:
F_47 ( V_15 ) ;
return V_7 ;
}
static int F_48 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_49 ( V_32 ) ;
F_50 ( V_4 -> V_15 ) ;
return 0 ;
}
