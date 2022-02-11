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
F_6 ( V_2 , V_14 ,
L_3
L_4 ) ;
}
if ( V_4 -> V_5 == V_9 &&
V_4 -> V_11 == 0x4 ) {
V_2 -> V_12 |= V_15 ;
F_6 ( V_2 , V_14 ,
L_5
L_6 ,
V_4 -> V_11 ) ;
}
V_2 -> V_12 |= V_16 ;
F_6 ( V_2 , V_14 ,
L_7
L_8 ,
V_4 -> V_11 ) ;
V_2 -> V_12 |= V_17 ;
}
if ( V_4 -> V_7 == V_18 )
V_2 -> V_12 |= V_19 ;
if ( V_4 -> V_7 == V_20 && V_2 -> V_21 == 0x96 )
V_2 -> V_12 |= V_22 ;
if ( V_4 -> V_7 == V_20 && F_7 () )
V_2 -> V_12 |= V_23 ;
if ( V_4 -> V_7 == V_24 ) {
V_2 -> V_12 |= V_25 ;
V_2 -> V_12 |= V_26 ;
}
if ( V_4 -> V_7 == V_24 &&
V_4 -> V_5 == V_27 ) {
V_2 -> V_12 |= V_28 ;
V_2 -> V_29 = 64 ;
V_2 -> V_12 |= V_30 ;
V_2 -> V_12 |= V_31 ;
V_2 -> V_12 |= V_32 ;
}
if ( V_4 -> V_7 == V_24 &&
( V_4 -> V_5 == V_33 ||
V_4 -> V_5 == V_34 ) ) {
V_2 -> V_12 |= V_35 ;
}
if ( V_4 -> V_7 == V_36 &&
V_4 -> V_5 == V_37 ) {
V_2 -> V_12 |= V_38 ;
F_6 ( V_2 , V_14 ,
L_9 ) ;
V_2 -> V_12 |= V_17 ;
}
if ( V_4 -> V_7 == V_39 )
V_2 -> V_12 |= V_38 ;
}
static int F_8 ( struct V_40 * V_41 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_41 -> V_42 . V_43 ) ;
int V_44 ;
V_44 = F_9 ( V_41 , F_4 ) ;
if ( V_44 )
return V_44 ;
V_2 = F_10 ( V_41 ) ;
if ( ! F_11 ( V_41 ) )
return 0 ;
F_12 ( V_4 , V_45 , & V_2 -> V_46 ) ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_46 ) ;
V_44 = F_1 ( V_2 , V_4 ) ;
if ( ! V_44 )
return V_44 ;
F_13 ( V_2 ) ;
return V_44 ;
}
static int F_14 ( struct V_3 * V_6 , const struct V_47 * V_48 )
{
int V_44 ;
struct V_1 * V_2 ;
struct V_49 * V_50 ;
struct V_40 * V_41 ;
V_50 = (struct V_49 * ) V_48 -> V_51 ;
V_44 = F_15 ( V_6 , V_48 ) ;
if ( V_44 )
return V_44 ;
V_41 = F_16 ( & V_6 -> V_6 ) ;
V_2 = F_10 ( V_41 ) ;
V_2 -> V_52 = F_17 ( V_50 , & V_6 -> V_6 ,
F_18 ( V_6 ) , V_41 ) ;
if ( ! V_2 -> V_52 ) {
V_44 = - V_53 ;
goto V_54;
}
* ( (struct V_1 * * ) V_2 -> V_52 -> V_55 ) = V_2 ;
V_44 = F_19 ( V_2 -> V_52 , V_6 -> V_56 ,
V_57 ) ;
if ( V_44 )
goto V_58;
if ( V_2 -> V_12 & V_25 )
F_20 ( V_2 -> V_52 ) -> V_59 -> V_60 = 1 ;
return 0 ;
V_58:
F_21 ( V_2 -> V_52 ) ;
V_54:
F_22 ( V_6 ) ;
return V_44 ;
}
static void F_23 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_10 ( F_24 ( V_6 ) ) ;
if ( V_2 -> V_52 ) {
F_25 ( V_2 -> V_52 ) ;
F_21 ( V_2 -> V_52 ) ;
}
F_22 ( V_6 ) ;
if ( V_2 -> V_12 & V_35 )
F_26 ( V_6 , V_61 ) ;
F_13 ( V_2 ) ;
}
static int F_27 ( struct V_40 * V_41 , bool V_62 )
{
struct V_1 * V_2 = F_10 ( V_41 ) ;
struct V_3 * V_4 = F_5 ( V_41 -> V_42 . V_43 ) ;
if ( F_28 () )
V_4 -> V_63 = true ;
return F_29 ( V_2 ) ;
}
static int F_30 ( struct V_40 * V_41 , bool V_64 )
{
struct V_1 * V_2 = F_10 ( V_41 ) ;
struct V_3 * V_4 = F_5 ( V_41 -> V_42 . V_43 ) ;
int V_44 = 0 ;
if ( V_4 -> V_7 == V_24 )
F_31 ( V_4 ) ;
V_44 = F_32 ( V_2 , V_64 ) ;
return V_44 ;
}
int T_1 F_33 ( void )
{
return F_34 ( & V_65 ) ;
}
void F_35 ( void )
{
F_36 ( & V_65 ) ;
}
