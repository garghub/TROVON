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
V_2 -> V_11 |= V_30 ;
}
if ( V_4 -> V_7 == V_31 &&
V_4 -> V_5 == V_32 ) {
V_2 -> V_11 |= V_33 ;
F_3 ( V_2 , L_7 ) ;
V_2 -> V_11 |= V_14 ;
}
if ( V_4 -> V_7 == V_34 )
V_2 -> V_11 |= V_33 ;
}
static int F_7 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_36 -> V_37 . V_38 ) ;
int V_39 ;
V_39 = F_8 ( V_36 , F_4 ) ;
if ( V_39 )
return V_39 ;
V_2 = F_9 ( V_36 ) ;
if ( ! F_10 ( V_36 ) )
return 0 ;
F_11 ( V_4 , V_40 , & V_2 -> V_41 ) ;
F_3 ( V_2 , L_8 , ( unsigned int ) V_2 -> V_41 ) ;
V_39 = F_1 ( V_2 , V_4 ) ;
if ( ! V_39 )
return V_39 ;
F_12 ( V_2 ) ;
return V_39 ;
}
static int F_13 ( struct V_3 * V_6 , const struct V_42 * V_43 )
{
int V_39 ;
struct V_1 * V_2 ;
struct V_44 * V_45 ;
struct V_35 * V_36 ;
V_45 = (struct V_44 * ) V_43 -> V_46 ;
V_39 = F_14 ( V_6 , V_43 ) ;
if ( V_39 )
return V_39 ;
V_36 = F_15 ( & V_6 -> V_6 ) ;
V_2 = F_9 ( V_36 ) ;
V_2 -> V_47 = F_16 ( V_45 , & V_6 -> V_6 ,
F_17 ( V_6 ) , V_36 ) ;
if ( ! V_2 -> V_47 ) {
V_39 = - V_48 ;
goto V_49;
}
* ( (struct V_1 * * ) V_2 -> V_47 -> V_50 ) = V_2 ;
V_39 = F_18 ( V_2 -> V_47 , V_6 -> V_51 ,
V_52 ) ;
if ( V_39 )
goto V_53;
if ( V_2 -> V_11 & V_22 )
F_19 ( V_2 -> V_47 ) -> V_54 -> V_55 = 1 ;
return 0 ;
V_53:
F_20 ( V_2 -> V_47 ) ;
V_49:
F_21 ( V_6 ) ;
return V_39 ;
}
static void F_22 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( F_23 ( V_6 ) ) ;
if ( V_2 -> V_47 ) {
F_24 ( V_2 -> V_47 ) ;
F_20 ( V_2 -> V_47 ) ;
}
F_21 ( V_6 ) ;
F_12 ( V_2 ) ;
}
static int F_25 ( struct V_35 * V_36 , bool V_56 )
{
struct V_1 * V_2 = F_9 ( V_36 ) ;
int V_39 = 0 ;
if ( V_36 -> V_57 != V_58 ||
V_2 -> V_47 -> V_57 != V_58 )
return - V_59 ;
V_39 = F_26 ( V_2 ) ;
return V_39 ;
}
static int F_27 ( struct V_35 * V_36 , bool V_60 )
{
struct V_1 * V_2 = F_9 ( V_36 ) ;
struct V_3 * V_4 = F_5 ( V_36 -> V_37 . V_38 ) ;
int V_39 = 0 ;
if ( F_28 ( V_4 ) )
F_29 ( V_4 ) ;
V_39 = F_30 ( V_2 , V_60 ) ;
return V_39 ;
}
int T_1 F_31 ( void )
{
return F_32 ( & V_61 ) ;
}
void F_33 ( void )
{
F_34 ( & V_61 ) ;
}
