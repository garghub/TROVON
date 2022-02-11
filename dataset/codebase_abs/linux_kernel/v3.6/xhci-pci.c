static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_2 ( V_4 ) )
F_3 ( V_2 , L_1 ) ;
F_3 ( V_2 , L_2 ) ;
return 0 ;
}
static void F_4 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_6 ) ;
if ( V_4 -> V_7 == V_8 &&
V_4 -> V_5 == V_9 ) {
if ( V_4 -> V_10 == 0x0 ) {
V_2 -> V_11 |= V_12 ;
F_3 ( V_2 , L_3
L_4 ) ;
}
V_2 -> V_11 |= V_13 ;
F_3 ( V_2 , L_5
L_6 ,
V_4 -> V_10 ) ;
V_2 -> V_11 |= V_14 ;
}
if ( V_4 -> V_7 == V_15 )
V_2 -> V_11 |= V_16 ;
if ( V_4 -> V_7 == V_17 && V_2 -> V_18 == 0x96 )
V_2 -> V_11 |= V_19 ;
if ( V_4 -> V_7 == V_17 && F_6 () )
V_2 -> V_11 |= V_20 ;
if ( V_4 -> V_7 == V_21 ) {
V_2 -> V_11 |= V_22 ;
V_2 -> V_11 |= V_23 ;
}
if ( V_4 -> V_7 == V_21 &&
V_4 -> V_5 == V_24 ) {
V_2 -> V_11 |= V_25 ;
V_2 -> V_11 |= V_26 ;
V_2 -> V_27 = 64 ;
V_2 -> V_11 |= V_28 ;
V_2 -> V_11 |= V_29 ;
}
if ( V_4 -> V_7 == V_30 &&
V_4 -> V_5 == V_31 ) {
V_2 -> V_11 |= V_32 ;
F_3 ( V_2 , L_7 ) ;
V_2 -> V_11 |= V_14 ;
}
if ( V_4 -> V_7 == V_33 )
V_2 -> V_11 |= V_32 ;
}
static int F_7 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_35 -> V_36 . V_37 ) ;
int V_38 ;
V_38 = F_8 ( V_35 , F_4 ) ;
if ( V_38 )
return V_38 ;
V_2 = F_9 ( V_35 ) ;
if ( ! F_10 ( V_35 ) )
return 0 ;
F_11 ( V_4 , V_39 , & V_2 -> V_40 ) ;
F_3 ( V_2 , L_8 , ( unsigned int ) V_2 -> V_40 ) ;
V_38 = F_1 ( V_2 , V_4 ) ;
if ( ! V_38 )
return V_38 ;
F_12 ( V_2 ) ;
return V_38 ;
}
static int F_13 ( struct V_3 * V_6 , const struct V_41 * V_42 )
{
int V_38 ;
struct V_1 * V_2 ;
struct V_43 * V_44 ;
struct V_34 * V_35 ;
V_44 = (struct V_43 * ) V_42 -> V_45 ;
V_38 = F_14 ( V_6 , V_42 ) ;
if ( V_38 )
return V_38 ;
V_35 = F_15 ( & V_6 -> V_6 ) ;
V_2 = F_9 ( V_35 ) ;
V_2 -> V_46 = F_16 ( V_44 , & V_6 -> V_6 ,
F_17 ( V_6 ) , V_35 ) ;
if ( ! V_2 -> V_46 ) {
V_38 = - V_47 ;
goto V_48;
}
* ( (struct V_1 * * ) V_2 -> V_46 -> V_49 ) = V_2 ;
V_38 = F_18 ( V_2 -> V_46 , V_6 -> V_50 ,
V_51 ) ;
if ( V_38 )
goto V_52;
if ( V_2 -> V_11 & V_22 )
F_19 ( V_2 -> V_46 ) -> V_53 -> V_54 = 1 ;
return 0 ;
V_52:
F_20 ( V_2 -> V_46 ) ;
V_48:
F_21 ( V_6 ) ;
return V_38 ;
}
static void F_22 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( F_23 ( V_6 ) ) ;
if ( V_2 -> V_46 ) {
F_24 ( V_2 -> V_46 ) ;
F_20 ( V_2 -> V_46 ) ;
}
F_21 ( V_6 ) ;
F_12 ( V_2 ) ;
}
static int F_25 ( struct V_34 * V_35 , bool V_55 )
{
struct V_1 * V_2 = F_9 ( V_35 ) ;
int V_38 = 0 ;
if ( V_35 -> V_56 != V_57 ||
V_2 -> V_46 -> V_56 != V_57 )
return - V_58 ;
V_38 = F_26 ( V_2 ) ;
return V_38 ;
}
static int F_27 ( struct V_34 * V_35 , bool V_59 )
{
struct V_1 * V_2 = F_9 ( V_35 ) ;
struct V_3 * V_4 = F_5 ( V_35 -> V_36 . V_37 ) ;
int V_38 = 0 ;
if ( F_28 ( V_4 ) )
F_29 ( V_4 ) ;
V_38 = F_30 ( V_2 , V_59 ) ;
return V_38 ;
}
int T_1 F_31 ( void )
{
return F_32 ( & V_60 ) ;
}
void F_33 ( void )
{
F_34 ( & V_60 ) ;
}
