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
if ( V_4 -> V_7 == V_41 &&
V_4 -> V_5 == 0x0015 &&
V_4 -> V_35 == V_42 &&
V_4 -> V_43 == 0xc0cd )
V_2 -> V_12 |= V_40 ;
if ( V_4 -> V_7 == V_44 )
V_2 -> V_12 |= V_40 ;
}
static int F_8 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_46 -> V_47 . V_48 ) ;
int V_49 ;
V_49 = F_9 ( V_46 , F_4 ) ;
if ( V_49 )
return V_49 ;
V_2 = F_10 ( V_46 ) ;
if ( ! F_11 ( V_46 ) )
return 0 ;
F_12 ( V_4 , V_50 , & V_2 -> V_51 ) ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_51 ) ;
V_49 = F_1 ( V_2 , V_4 ) ;
if ( ! V_49 )
return V_49 ;
F_13 ( V_2 ) ;
return V_49 ;
}
static int F_14 ( struct V_3 * V_6 , const struct V_52 * V_53 )
{
int V_49 ;
struct V_1 * V_2 ;
struct V_54 * V_55 ;
struct V_45 * V_46 ;
V_55 = (struct V_54 * ) V_53 -> V_56 ;
V_49 = F_15 ( V_6 , V_53 ) ;
if ( V_49 )
return V_49 ;
V_46 = F_16 ( & V_6 -> V_6 ) ;
V_2 = F_10 ( V_46 ) ;
V_2 -> V_57 = F_17 ( V_55 , & V_6 -> V_6 ,
F_18 ( V_6 ) , V_46 ) ;
if ( ! V_2 -> V_57 ) {
V_49 = - V_58 ;
goto V_59;
}
* ( (struct V_1 * * ) V_2 -> V_57 -> V_60 ) = V_2 ;
V_49 = F_19 ( V_2 -> V_57 , V_6 -> V_61 ,
V_62 ) ;
if ( V_49 )
goto V_63;
if ( V_2 -> V_12 & V_25 )
F_20 ( V_2 -> V_57 ) -> V_64 -> V_65 = 1 ;
return 0 ;
V_63:
F_21 ( V_2 -> V_57 ) ;
V_59:
F_22 ( V_6 ) ;
return V_49 ;
}
static void F_23 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_10 ( F_24 ( V_6 ) ) ;
if ( V_2 -> V_57 ) {
F_25 ( V_2 -> V_57 ) ;
F_21 ( V_2 -> V_57 ) ;
}
F_22 ( V_6 ) ;
if ( V_2 -> V_12 & V_37 )
F_26 ( V_6 , V_66 ) ;
F_13 ( V_2 ) ;
}
static int F_27 ( struct V_45 * V_46 , bool V_67 )
{
struct V_1 * V_2 = F_10 ( V_46 ) ;
struct V_3 * V_4 = F_5 ( V_46 -> V_47 . V_48 ) ;
if ( F_28 () )
V_4 -> V_68 = true ;
return F_29 ( V_2 ) ;
}
static int F_30 ( struct V_45 * V_46 , bool V_69 )
{
struct V_1 * V_2 = F_10 ( V_46 ) ;
struct V_3 * V_4 = F_5 ( V_46 -> V_47 . V_48 ) ;
int V_49 = 0 ;
if ( V_4 -> V_7 == V_24 )
F_31 ( V_4 ) ;
V_49 = F_32 ( V_2 , V_69 ) ;
return V_49 ;
}
int T_1 F_33 ( void )
{
return F_34 ( & V_70 ) ;
}
void F_35 ( void )
{
F_36 ( & V_70 ) ;
}
