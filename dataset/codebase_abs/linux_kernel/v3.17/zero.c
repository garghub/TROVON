static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = ( void * ) V_1 ;
struct V_4 * V_5 = V_3 -> V_6 ;
if ( ! V_3 -> V_7 )
return;
if ( V_5 -> V_8 != V_9 ) {
int V_10 = F_2 ( V_5 ) ;
F_3 ( V_3 , L_1 , V_11 , V_10 ) ;
}
}
static void F_4 ( struct V_2 * V_3 )
{
if ( V_3 -> V_6 -> V_8 == V_9 )
return;
if ( V_12 ) {
if ( V_13 &&
( V_14 > V_13 * 1000 ) )
V_14 = V_12 * 1000 ;
F_5 ( & V_15 , V_16 +
F_6 ( V_14 ) ) ;
F_7 ( V_3 , L_2 ,
V_14 ) ;
V_14 += V_17 ;
} else
F_7 ( V_3 , L_3 , V_11 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
F_7 ( V_3 , L_3 , V_11 ) ;
F_9 ( & V_15 ) ;
}
static int F_10 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
switch ( V_21 -> V_22 ) {
case 0x5b :
case 0x5c :
return V_23 -> V_24 ( V_23 , V_21 ) ;
default:
return - V_25 ;
}
}
static int T_1 F_11 ( struct V_2 * V_3 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_10 ;
V_10 = F_12 ( V_3 , V_30 ) ;
if ( V_10 < 0 )
return V_10 ;
V_31 . V_32 = V_30 [ V_33 ] . V_34 ;
V_31 . V_35 = V_30 [ V_36 ] . V_34 ;
V_31 . V_37 = V_30 [ V_38 ] . V_34 ;
F_13 ( & V_15 , F_1 , ( unsigned long ) V_3 ) ;
V_39 = F_14 ( L_4 ) ;
if ( F_15 ( V_39 ) )
return F_16 ( V_39 ) ;
V_27 = F_17 ( V_39 , struct V_26 , V_40 ) ;
V_27 -> V_41 = V_42 . V_41 ;
V_27 -> V_43 = V_42 . V_43 ;
V_27 -> V_44 = V_42 . V_44 ;
V_27 -> V_45 = V_42 . V_45 ;
V_27 -> V_46 = V_42 . V_46 ;
V_27 -> V_47 = V_42 . V_47 ;
V_23 = F_18 ( V_39 ) ;
if ( F_15 ( V_23 ) ) {
V_10 = F_16 ( V_23 ) ;
goto V_48;
}
V_49 = F_14 ( L_5 ) ;
if ( F_15 ( V_49 ) ) {
V_10 = F_16 ( V_49 ) ;
goto V_50;
}
V_29 = F_17 ( V_49 , struct V_28 , V_40 ) ;
V_29 -> V_47 = V_42 . V_47 ;
V_29 -> V_51 = V_42 . V_51 ;
V_52 = F_18 ( V_49 ) ;
if ( F_15 ( V_52 ) ) {
V_10 = F_16 ( V_52 ) ;
goto V_53;
}
V_54 . V_55 = V_30 [ V_56 ] . V_34 ;
V_57 . V_55 = V_30 [ V_58 ] . V_34 ;
V_54 . V_59 &= ~ V_60 ;
V_57 . V_59 &= ~ V_60 ;
V_54 . V_61 = NULL ;
V_57 . V_61 = NULL ;
if ( V_12 ) {
V_54 . V_59 |= V_60 ;
V_57 . V_59 |= V_60 ;
V_14 = V_12 * 1000 ;
}
if ( F_19 ( V_3 -> V_6 ) ) {
V_54 . V_61 = V_62 ;
V_54 . V_59 |= V_60 ;
V_57 . V_61 = V_62 ;
V_57 . V_59 |= V_60 ;
}
if ( V_63 ) {
F_20 ( V_3 , & V_57 ) ;
F_20 ( V_3 , & V_54 ) ;
} else {
F_20 ( V_3 , & V_54 ) ;
F_20 ( V_3 , & V_57 ) ;
}
V_10 = F_21 ( & V_54 , V_23 ) ;
if ( V_10 )
goto V_64;
F_22 ( V_3 -> V_6 ) ;
V_10 = F_21 ( & V_57 , V_52 ) ;
if ( V_10 )
goto V_64;
F_22 ( V_3 -> V_6 ) ;
F_23 ( V_3 , & V_65 ) ;
F_3 ( V_3 , L_6 V_66 L_7 , V_67 ) ;
return 0 ;
V_64:
F_24 ( V_52 ) ;
V_52 = NULL ;
V_53:
F_25 ( V_49 ) ;
V_49 = NULL ;
V_50:
F_24 ( V_23 ) ;
V_23 = NULL ;
V_48:
F_25 ( V_39 ) ;
V_39 = NULL ;
return V_10 ;
}
static int F_26 ( struct V_2 * V_3 )
{
F_27 ( & V_15 ) ;
if ( ! F_28 ( V_23 ) )
F_24 ( V_23 ) ;
F_25 ( V_39 ) ;
if ( ! F_28 ( V_52 ) )
F_24 ( V_52 ) ;
F_25 ( V_49 ) ;
return 0 ;
}
