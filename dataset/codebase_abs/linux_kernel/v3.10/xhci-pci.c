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
( V_4 -> V_5 == V_9 ||
V_4 -> V_5 == V_10 ) ) {
if ( V_4 -> V_5 == V_9 &&
V_4 -> V_11 == 0x0 ) {
V_2 -> V_12 |= V_13 ;
F_3 ( V_2 , L_3
L_4 ) ;
}
V_2 -> V_12 |= V_14 ;
F_3 ( V_2 , L_5
L_6 ,
V_4 -> V_11 ) ;
V_2 -> V_12 |= V_15 ;
}
if ( V_4 -> V_7 == V_16 )
V_2 -> V_12 |= V_17 ;
if ( V_4 -> V_7 == V_18 && V_2 -> V_19 == 0x96 )
V_2 -> V_12 |= V_20 ;
if ( V_4 -> V_7 == V_18 && F_6 () )
V_2 -> V_12 |= V_21 ;
if ( V_4 -> V_7 == V_22 ) {
V_2 -> V_12 |= V_23 ;
V_2 -> V_12 |= V_24 ;
}
if ( V_4 -> V_7 == V_22 &&
V_4 -> V_5 == V_25 ) {
V_2 -> V_12 |= V_26 ;
V_2 -> V_12 |= V_27 ;
V_2 -> V_28 = 64 ;
V_2 -> V_12 |= V_29 ;
V_2 -> V_12 |= V_30 ;
V_2 -> V_12 |= V_31 ;
}
if ( V_4 -> V_7 == V_32 &&
V_4 -> V_5 == V_33 ) {
V_2 -> V_12 |= V_34 ;
F_3 ( V_2 , L_7 ) ;
V_2 -> V_12 |= V_15 ;
}
if ( V_4 -> V_7 == V_35 )
V_2 -> V_12 |= V_34 ;
}
static int F_7 ( struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_37 -> V_38 . V_39 ) ;
int V_40 ;
V_40 = F_8 ( V_37 , F_4 ) ;
if ( V_40 )
return V_40 ;
V_2 = F_9 ( V_37 ) ;
if ( ! F_10 ( V_37 ) )
return 0 ;
F_11 ( V_4 , V_41 , & V_2 -> V_42 ) ;
F_3 ( V_2 , L_8 , ( unsigned int ) V_2 -> V_42 ) ;
V_40 = F_1 ( V_2 , V_4 ) ;
if ( ! V_40 )
return V_40 ;
F_12 ( V_2 ) ;
return V_40 ;
}
static int F_13 ( struct V_3 * V_6 , const struct V_43 * V_44 )
{
int V_40 ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
struct V_36 * V_37 ;
V_46 = (struct V_45 * ) V_44 -> V_47 ;
V_40 = F_14 ( V_6 , V_44 ) ;
if ( V_40 )
return V_40 ;
V_37 = F_15 ( & V_6 -> V_6 ) ;
V_2 = F_9 ( V_37 ) ;
V_2 -> V_48 = F_16 ( V_46 , & V_6 -> V_6 ,
F_17 ( V_6 ) , V_37 ) ;
if ( ! V_2 -> V_48 ) {
V_40 = - V_49 ;
goto V_50;
}
* ( (struct V_1 * * ) V_2 -> V_48 -> V_51 ) = V_2 ;
V_40 = F_18 ( V_2 -> V_48 , V_6 -> V_52 ,
V_53 ) ;
if ( V_40 )
goto V_54;
if ( V_2 -> V_12 & V_23 )
F_19 ( V_2 -> V_48 ) -> V_55 -> V_56 = 1 ;
return 0 ;
V_54:
F_20 ( V_2 -> V_48 ) ;
V_50:
F_21 ( V_6 ) ;
return V_40 ;
}
static void F_22 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( F_23 ( V_6 ) ) ;
if ( V_2 -> V_48 ) {
F_24 ( V_2 -> V_48 ) ;
F_20 ( V_2 -> V_48 ) ;
}
F_21 ( V_6 ) ;
F_12 ( V_2 ) ;
}
static int F_25 ( struct V_36 * V_37 , bool V_57 )
{
struct V_1 * V_2 = F_9 ( V_37 ) ;
struct V_3 * V_4 = F_5 ( V_37 -> V_38 . V_39 ) ;
if ( F_26 () )
V_4 -> V_58 = true ;
return F_27 ( V_2 ) ;
}
static int F_28 ( struct V_36 * V_37 , bool V_59 )
{
struct V_1 * V_2 = F_9 ( V_37 ) ;
struct V_3 * V_4 = F_5 ( V_37 -> V_38 . V_39 ) ;
int V_40 = 0 ;
if ( F_29 ( V_4 ) )
F_30 ( V_4 ) ;
V_40 = F_31 ( V_2 , V_59 ) ;
return V_40 ;
}
int T_1 F_32 ( void )
{
return F_33 ( & V_60 ) ;
}
void F_34 ( void )
{
F_35 ( & V_60 ) ;
}
