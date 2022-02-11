static int F_1 ( void T_1 * V_1 )
{
T_2 V_2 ;
int V_3 ;
V_2 = F_2 ( V_1 + V_4 ) ;
V_2 &= ~ V_5 ;
F_3 ( V_2 , V_1 + V_4 ) ;
V_2 = F_4 ( V_1 + V_6 ) ;
V_2 |= V_7 ;
F_5 ( V_2 , V_1 + V_6 ) ;
for ( V_3 = 0 ; V_3 < 20 ; V_3 ++ ) {
V_2 = F_2 ( V_1 + V_8 ) ;
if ( ( V_2 & V_9 ) == V_9 ) {
V_2 = F_2 ( V_1 + V_4 ) ;
V_2 |= V_10 ;
F_3 ( V_2 , V_1 + V_4 ) ;
return 0 ;
}
F_6 ( 1 ) ;
}
return - V_11 ;
}
static int F_7 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_4 ) ;
V_2 &= ~ V_10 ;
F_3 ( V_2 , V_1 + V_4 ) ;
V_2 = F_4 ( V_1 + V_6 ) ;
V_2 &= ~ V_7 ;
F_5 ( V_2 , V_1 + V_6 ) ;
V_2 = F_2 ( V_1 + V_4 ) ;
V_2 |= V_5 ;
F_3 ( V_2 , V_1 + V_4 ) ;
return 0 ;
}
static void F_8 ( struct V_12 * V_13 )
{
T_2 V_2 ;
F_9 ( V_13 -> V_14 ) ;
V_2 = F_2 ( V_13 -> V_1 + V_15 ) ;
V_2 &= ~ ( V_16 | V_17 ) ;
V_2 |= V_13 -> V_18 ;
F_3 ( V_2 , V_13 -> V_1 + V_15 ) ;
}
static void F_10 ( struct V_12 * V_13 )
{
F_7 ( V_13 -> V_1 ) ;
F_11 ( V_13 -> V_14 ) ;
}
static int F_12 ( struct V_19 * V_20 , int V_21 )
{
struct V_12 * V_13 = F_13 ( V_20 ) ;
unsigned long V_22 ;
int V_23 ;
F_14 ( & V_13 -> V_24 , V_22 ) ;
V_23 = V_21 ? F_7 ( V_13 -> V_1 ) :
F_1 ( V_13 -> V_1 ) ;
F_15 ( & V_13 -> V_24 , V_22 ) ;
return V_23 ;
}
static int F_16 ( struct V_19 * V_20 )
{
struct V_12 * V_13 = F_13 ( V_20 ) ;
unsigned long V_22 ;
F_14 ( & V_13 -> V_24 , V_22 ) ;
if ( ! V_13 -> V_25 ++ )
F_8 ( V_13 ) ;
F_15 ( & V_13 -> V_24 , V_22 ) ;
return 0 ;
}
static void F_17 ( struct V_19 * V_20 )
{
struct V_12 * V_13 = F_13 ( V_20 ) ;
unsigned long V_22 ;
F_14 ( & V_13 -> V_24 , V_22 ) ;
if ( ! V_13 -> V_25 ) {
F_18 ( V_20 -> V_26 , L_1 ) ;
goto V_27;
}
if ( ! -- V_13 -> V_25 )
F_10 ( V_13 ) ;
V_27:
F_15 ( & V_13 -> V_24 , V_22 ) ;
}
static int F_19 ( struct V_28 * V_29 )
{
struct V_30 * V_26 = & V_29 -> V_26 ;
struct V_31 * V_32 ;
struct V_12 * V_13 ;
struct V_33 * V_34 ;
void T_1 * V_1 ;
struct V_14 * V_14 ;
int V_23 ;
V_32 = F_20 ( & V_29 -> V_26 ) ;
if ( ! V_32 ) {
F_21 ( V_26 , L_2 ) ;
return - V_35 ;
}
V_14 = F_22 ( & V_29 -> V_26 , L_3 ) ;
if ( F_23 ( V_14 ) ) {
F_21 ( & V_29 -> V_26 , L_4 ) ;
return F_24 ( V_14 ) ;
}
V_34 = F_25 ( V_29 , V_36 , 0 ) ;
V_1 = F_26 ( V_26 , V_34 ) ;
if ( F_23 ( V_1 ) )
return F_24 ( V_1 ) ;
V_13 = F_27 ( V_26 , sizeof( * V_13 ) , V_37 ) ;
if ( ! V_13 ) {
F_21 ( V_26 , L_5 ) ;
return - V_38 ;
}
F_28 ( & V_13 -> V_24 ) ;
V_13 -> V_14 = V_14 ;
V_13 -> V_1 = V_1 ;
V_13 -> V_18 = V_32 -> V_39 ?
V_40 : V_16 ;
V_13 -> V_18 |= V_32 -> V_41 ?
V_42 : V_17 ;
V_13 -> V_20 . V_26 = V_26 ;
V_13 -> V_20 . V_43 = F_29 ( V_26 ) ;
V_13 -> V_20 . V_44 = F_16 ;
V_13 -> V_20 . V_45 = F_17 ;
V_13 -> V_20 . V_46 = F_12 ;
V_23 = F_30 ( & V_13 -> V_20 ) ;
if ( V_23 < 0 ) {
F_21 ( V_26 , L_6 ) ;
return V_23 ;
}
F_31 ( V_29 , V_13 ) ;
return V_23 ;
}
static int F_32 ( struct V_28 * V_29 )
{
struct V_12 * V_13 = F_33 ( V_29 ) ;
F_34 ( & V_13 -> V_20 ) ;
return 0 ;
}
