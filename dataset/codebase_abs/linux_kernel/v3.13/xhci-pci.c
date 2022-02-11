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
if ( V_4 -> V_35 == V_36 )
V_2 -> V_12 |= V_37 ;
}
if ( V_4 -> V_7 == V_38 &&
V_4 -> V_5 == V_39 ) {
V_2 -> V_12 |= V_40 ;
F_6 ( V_2 , V_14 ,
L_9 ) ;
V_2 -> V_12 |= V_17 ;
}
if ( V_4 -> V_7 == V_41 )
V_2 -> V_12 |= V_40 ;
}
static int F_8 ( struct V_42 * V_43 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_43 -> V_44 . V_45 ) ;
int V_46 ;
V_46 = F_9 ( V_43 , F_4 ) ;
if ( V_46 )
return V_46 ;
V_2 = F_10 ( V_43 ) ;
if ( ! F_11 ( V_43 ) )
return 0 ;
F_12 ( V_4 , V_47 , & V_2 -> V_48 ) ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_48 ) ;
V_46 = F_1 ( V_2 , V_4 ) ;
if ( ! V_46 )
return V_46 ;
F_13 ( V_2 ) ;
return V_46 ;
}
static int F_14 ( struct V_3 * V_6 , const struct V_49 * V_50 )
{
int V_46 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
struct V_42 * V_43 ;
V_52 = (struct V_51 * ) V_50 -> V_53 ;
V_46 = F_15 ( V_6 , V_50 ) ;
if ( V_46 )
return V_46 ;
V_43 = F_16 ( & V_6 -> V_6 ) ;
V_2 = F_10 ( V_43 ) ;
V_2 -> V_54 = F_17 ( V_52 , & V_6 -> V_6 ,
F_18 ( V_6 ) , V_43 ) ;
if ( ! V_2 -> V_54 ) {
V_46 = - V_55 ;
goto V_56;
}
* ( (struct V_1 * * ) V_2 -> V_54 -> V_57 ) = V_2 ;
V_46 = F_19 ( V_2 -> V_54 , V_6 -> V_58 ,
V_59 ) ;
if ( V_46 )
goto V_60;
if ( V_2 -> V_12 & V_25 )
F_20 ( V_2 -> V_54 ) -> V_61 -> V_62 = 1 ;
return 0 ;
V_60:
F_21 ( V_2 -> V_54 ) ;
V_56:
F_22 ( V_6 ) ;
return V_46 ;
}
static void F_23 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_10 ( F_24 ( V_6 ) ) ;
if ( V_2 -> V_54 ) {
F_25 ( V_2 -> V_54 ) ;
F_21 ( V_2 -> V_54 ) ;
}
F_22 ( V_6 ) ;
if ( V_2 -> V_12 & V_37 )
F_26 ( V_6 , V_63 ) ;
F_13 ( V_2 ) ;
}
static int F_27 ( struct V_42 * V_43 , bool V_64 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
struct V_3 * V_4 = F_5 ( V_43 -> V_44 . V_45 ) ;
if ( F_28 () )
V_4 -> V_65 = true ;
return F_29 ( V_2 ) ;
}
static int F_30 ( struct V_42 * V_43 , bool V_66 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
struct V_3 * V_4 = F_5 ( V_43 -> V_44 . V_45 ) ;
int V_46 = 0 ;
if ( V_4 -> V_7 == V_24 )
F_31 ( V_4 ) ;
V_46 = F_32 ( V_2 , V_66 ) ;
return V_46 ;
}
int T_1 F_33 ( void )
{
return F_34 ( & V_67 ) ;
}
void F_35 ( void )
{
F_36 ( & V_67 ) ;
}
