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
if ( V_4 -> V_7 == V_20 )
V_2 -> V_12 |= V_17 ;
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
V_4 -> V_5 == V_33 ) {
V_2 -> V_12 |= V_31 ;
}
if ( V_4 -> V_7 == V_34 &&
V_4 -> V_5 == V_35 ) {
V_2 -> V_12 |= V_36 ;
V_2 -> V_12 |= V_17 ;
V_2 -> V_12 |= V_37 ;
}
if ( V_4 -> V_7 == V_38 &&
V_4 -> V_5 == 0x0015 )
V_2 -> V_12 |= V_36 ;
if ( V_4 -> V_7 == V_39 )
V_2 -> V_12 |= V_36 ;
if ( V_4 -> V_7 == V_39 &&
V_4 -> V_5 == 0x3432 )
V_2 -> V_12 |= V_37 ;
if ( V_4 -> V_7 == V_40 &&
V_4 -> V_5 == 0x1042 )
V_2 -> V_12 |= V_37 ;
if ( V_2 -> V_12 & V_36 )
F_6 ( V_2 , V_14 ,
L_9 ) ;
}
static int F_8 ( struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_42 -> V_43 . V_44 ) ;
int V_45 ;
V_45 = F_9 ( V_42 , F_4 ) ;
if ( V_45 )
return V_45 ;
V_2 = F_10 ( V_42 ) ;
if ( ! F_11 ( V_42 ) )
return 0 ;
F_12 ( V_4 , V_46 , & V_2 -> V_47 ) ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_47 ) ;
V_45 = F_1 ( V_2 , V_4 ) ;
if ( ! V_45 )
return V_45 ;
F_13 ( V_2 ) ;
return V_45 ;
}
static int F_14 ( struct V_3 * V_6 , const struct V_48 * V_49 )
{
int V_45 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
struct V_41 * V_42 ;
V_51 = (struct V_50 * ) V_49 -> V_52 ;
F_15 ( & V_6 -> V_6 ) ;
V_45 = F_16 ( V_6 , V_49 ) ;
if ( V_45 )
goto V_53;
V_42 = F_17 ( & V_6 -> V_6 ) ;
V_2 = F_10 ( V_42 ) ;
V_2 -> V_54 = F_18 ( V_51 , & V_6 -> V_6 ,
F_19 ( V_6 ) , V_42 ) ;
if ( ! V_2 -> V_54 ) {
V_45 = - V_55 ;
goto V_56;
}
* ( (struct V_1 * * ) V_2 -> V_54 -> V_57 ) = V_2 ;
V_45 = F_20 ( V_2 -> V_54 , V_6 -> V_58 ,
V_59 ) ;
if ( V_45 )
goto V_60;
if ( ! ( V_2 -> V_12 & V_37 ) &&
F_21 ( V_2 -> V_61 ) >= 4 )
V_2 -> V_54 -> V_62 = 1 ;
F_22 ( & V_6 -> V_6 ) ;
return 0 ;
V_60:
F_23 ( V_2 -> V_54 ) ;
V_56:
F_24 ( V_6 ) ;
V_53:
F_22 ( & V_6 -> V_6 ) ;
return V_45 ;
}
static void F_25 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_10 ( F_26 ( V_6 ) ) ;
if ( V_2 -> V_54 ) {
F_27 ( V_2 -> V_54 ) ;
F_23 ( V_2 -> V_54 ) ;
}
F_24 ( V_6 ) ;
if ( V_2 -> V_12 & V_63 )
F_28 ( V_6 , V_64 ) ;
F_13 ( V_2 ) ;
}
static int F_29 ( struct V_41 * V_42 , bool V_65 )
{
struct V_1 * V_2 = F_10 ( V_42 ) ;
struct V_3 * V_4 = F_5 ( V_42 -> V_43 . V_44 ) ;
if ( V_2 -> V_12 & V_66 )
V_4 -> V_67 = true ;
return F_30 ( V_2 , V_65 ) ;
}
static int F_31 ( struct V_41 * V_42 , bool V_68 )
{
struct V_1 * V_2 = F_10 ( V_42 ) ;
struct V_3 * V_4 = F_5 ( V_42 -> V_43 . V_44 ) ;
int V_45 = 0 ;
if ( V_4 -> V_7 == V_24 )
F_32 ( V_4 ) ;
V_45 = F_33 ( V_2 , V_68 ) ;
return V_45 ;
}
static int T_1 F_34 ( void )
{
F_35 ( & V_69 , F_8 ) ;
#ifdef F_36
V_69 . V_70 = F_29 ;
V_69 . V_71 = F_31 ;
#endif
return F_37 ( & V_72 ) ;
}
static void T_2 F_38 ( void )
{
F_39 ( & V_72 ) ;
}
