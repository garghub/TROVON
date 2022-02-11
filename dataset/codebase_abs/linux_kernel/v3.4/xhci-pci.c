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
}
if ( V_4 -> V_7 == V_14 )
V_2 -> V_11 |= V_15 ;
if ( V_4 -> V_7 == V_16 && V_2 -> V_17 == 0x96 )
V_2 -> V_11 |= V_18 ;
if ( V_4 -> V_7 == V_16 && F_6 () )
V_2 -> V_11 |= V_19 ;
if ( V_4 -> V_7 == V_20 &&
V_4 -> V_5 == V_21 ) {
V_2 -> V_11 |= V_22 ;
V_2 -> V_11 |= V_23 ;
V_2 -> V_24 = 64 ;
V_2 -> V_11 |= V_25 ;
}
if ( V_4 -> V_7 == V_26 &&
V_4 -> V_5 == V_27 ) {
V_2 -> V_11 |= V_28 ;
F_3 ( V_2 , L_7 ) ;
}
if ( V_4 -> V_7 == V_29 )
V_2 -> V_11 |= V_28 ;
}
static int F_7 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_31 -> V_32 . V_33 ) ;
int V_34 ;
V_34 = F_8 ( V_31 , F_4 ) ;
if ( V_34 )
return V_34 ;
V_2 = F_9 ( V_31 ) ;
if ( ! F_10 ( V_31 ) )
return 0 ;
F_11 ( V_4 , V_35 , & V_2 -> V_36 ) ;
F_3 ( V_2 , L_8 , ( unsigned int ) V_2 -> V_36 ) ;
V_34 = F_1 ( V_2 , V_4 ) ;
if ( ! V_34 )
return V_34 ;
F_12 ( V_2 ) ;
return V_34 ;
}
static int F_13 ( struct V_3 * V_6 , const struct V_37 * V_38 )
{
int V_34 ;
struct V_1 * V_2 ;
struct V_39 * V_40 ;
struct V_30 * V_31 ;
V_40 = (struct V_39 * ) V_38 -> V_41 ;
V_34 = F_14 ( V_6 , V_38 ) ;
if ( V_34 )
return V_34 ;
V_31 = F_15 ( & V_6 -> V_6 ) ;
V_2 = F_9 ( V_31 ) ;
V_2 -> V_42 = F_16 ( V_40 , & V_6 -> V_6 ,
F_17 ( V_6 ) , V_31 ) ;
if ( ! V_2 -> V_42 ) {
V_34 = - V_43 ;
goto V_44;
}
* ( (struct V_1 * * ) V_2 -> V_42 -> V_45 ) = V_2 ;
V_34 = F_18 ( V_2 -> V_42 , V_6 -> V_46 ,
V_47 ) ;
if ( V_34 )
goto V_48;
return 0 ;
V_48:
F_19 ( V_2 -> V_42 ) ;
V_44:
F_20 ( V_6 ) ;
return V_34 ;
}
static void F_21 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( F_22 ( V_6 ) ) ;
if ( V_2 -> V_42 ) {
F_23 ( V_2 -> V_42 ) ;
F_19 ( V_2 -> V_42 ) ;
}
F_20 ( V_6 ) ;
F_12 ( V_2 ) ;
}
static int F_24 ( struct V_30 * V_31 , bool V_49 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
int V_34 = 0 ;
if ( V_31 -> V_50 != V_51 ||
V_2 -> V_42 -> V_50 != V_51 )
return - V_52 ;
V_34 = F_25 ( V_2 ) ;
return V_34 ;
}
static int F_26 ( struct V_30 * V_31 , bool V_53 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
struct V_3 * V_4 = F_5 ( V_31 -> V_32 . V_33 ) ;
int V_34 = 0 ;
if ( F_27 ( V_4 ) )
F_28 ( V_4 ) ;
V_34 = F_29 ( V_2 , V_53 ) ;
return V_34 ;
}
int T_1 F_30 ( void )
{
return F_31 ( & V_54 ) ;
}
void F_32 ( void )
{
F_33 ( & V_54 ) ;
}
