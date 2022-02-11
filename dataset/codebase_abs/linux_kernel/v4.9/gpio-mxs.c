static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static int F_3 ( struct V_6 * V_7 , unsigned int type )
{
T_1 V_8 ;
T_1 V_9 = 1 << V_7 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_13 ;
void T_2 * V_14 ;
int V_15 ;
V_2 -> V_16 &= ~ V_9 ;
switch ( type ) {
case V_17 :
V_8 = F_5 ( V_2 -> V_12 . V_18 + V_7 -> V_10 ) ;
if ( V_8 )
V_15 = V_19 ;
else
V_15 = V_20 ;
V_2 -> V_16 |= V_9 ;
break;
case V_21 :
V_15 = V_20 ;
break;
case V_22 :
V_15 = V_19 ;
break;
case V_23 :
V_15 = V_24 ;
break;
case V_25 :
V_15 = V_26 ;
break;
default:
return - V_27 ;
}
V_14 = V_2 -> V_18 + F_6 ( V_2 ) ;
if ( V_15 & V_28 )
F_7 ( V_9 , V_14 + V_29 ) ;
else
F_7 ( V_9 , V_14 + V_30 ) ;
V_14 = V_2 -> V_18 + F_8 ( V_2 ) ;
if ( V_15 & V_31 )
F_7 ( V_9 , V_14 + V_29 ) ;
else
F_7 ( V_9 , V_14 + V_30 ) ;
F_7 ( V_9 ,
V_2 -> V_18 + F_9 ( V_2 ) + V_30 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_32 )
{
T_1 V_33 , V_8 , V_15 ;
void T_2 * V_14 ;
V_33 = 1 << V_32 ;
V_14 = V_2 -> V_18 + F_8 ( V_2 ) ;
V_8 = F_11 ( V_14 ) ;
V_15 = V_8 & V_33 ;
if ( V_15 )
F_7 ( V_33 , V_14 + V_30 ) ;
else
F_7 ( V_33 , V_14 + V_29 ) ;
}
static void F_12 ( struct V_34 * V_35 )
{
T_1 V_36 ;
struct V_1 * V_2 = F_13 ( V_35 ) ;
V_35 -> V_6 . V_37 -> V_38 ( & V_35 -> V_6 ) ;
V_36 = F_11 ( V_2 -> V_18 + F_9 ( V_2 ) ) &
F_11 ( V_2 -> V_18 + F_14 ( V_2 ) ) ;
while ( V_36 != 0 ) {
int V_39 = F_15 ( V_36 ) - 1 ;
if ( V_2 -> V_16 & ( 1 << V_39 ) )
F_10 ( V_2 , V_39 ) ;
F_16 ( F_17 ( V_2 -> V_40 , V_39 ) ) ;
V_36 &= ~ ( 1 << V_39 ) ;
}
}
static int F_18 ( struct V_6 * V_7 , unsigned int V_41 )
{
struct V_11 * V_12 = F_4 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_13 ;
if ( V_41 )
F_19 ( V_2 -> V_42 ) ;
else
F_20 ( V_2 -> V_42 ) ;
return 0 ;
}
static int T_3 F_21 ( struct V_1 * V_2 , int V_43 )
{
struct V_11 * V_12 ;
struct V_44 * V_45 ;
V_12 = F_22 ( L_1 , 1 , V_43 ,
V_2 -> V_18 , V_46 ) ;
if ( ! V_12 )
return - V_47 ;
V_12 -> V_13 = V_2 ;
V_45 = V_12 -> V_48 ;
V_45 -> V_37 . V_38 = V_49 ;
V_45 -> V_37 . V_50 = V_51 ;
V_45 -> V_37 . V_52 = V_53 ;
V_45 -> V_37 . V_54 = F_3 ;
V_45 -> V_37 . V_55 = F_18 ;
V_45 -> V_56 . V_57 = F_9 ( V_2 ) + V_30 ;
V_45 -> V_56 . V_58 = F_14 ( V_2 ) ;
F_23 ( V_12 , F_24 ( 32 ) , V_59 ,
V_60 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_61 * V_12 , unsigned V_62 )
{
struct V_1 * V_2 = F_26 ( V_12 ) ;
return F_17 ( V_2 -> V_40 , V_62 ) ;
}
static int F_27 ( struct V_61 * V_12 , unsigned V_62 )
{
struct V_1 * V_2 = F_26 ( V_12 ) ;
T_1 V_58 = 1 << V_62 ;
T_1 V_63 ;
V_63 = F_11 ( V_2 -> V_18 + F_28 ( V_2 ) ) ;
return ! ( V_63 & V_58 ) ;
}
static int F_29 ( struct V_64 * V_65 )
{
const struct V_66 * V_67 =
F_30 ( V_68 , & V_65 -> V_69 ) ;
struct V_70 * V_71 = V_65 -> V_69 . V_72 ;
struct V_70 * V_73 ;
static void T_2 * V_18 ;
struct V_1 * V_2 ;
int V_43 ;
int V_74 ;
V_2 = F_31 ( & V_65 -> V_69 , sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_76 = F_32 ( V_71 , L_2 ) ;
if ( V_2 -> V_76 < 0 )
return V_2 -> V_76 ;
V_2 -> V_3 = (enum V_77 ) V_67 -> V_78 ;
V_2 -> V_42 = F_33 ( V_65 , 0 ) ;
if ( V_2 -> V_42 < 0 )
return V_2 -> V_42 ;
if ( ! V_18 ) {
V_73 = F_34 ( V_71 ) ;
V_18 = F_35 ( V_73 , 0 ) ;
F_36 ( V_73 ) ;
if ( ! V_18 )
return - V_79 ;
}
V_2 -> V_18 = V_18 ;
F_7 ( ~ 0U , V_2 -> V_18 + F_37 ( V_2 ) ) ;
F_7 ( 0 , V_2 -> V_18 + F_14 ( V_2 ) ) ;
F_7 ( ~ 0U , V_2 -> V_18 + F_9 ( V_2 ) + V_30 ) ;
V_43 = F_38 ( - 1 , 0 , 32 , F_39 () ) ;
if ( V_43 < 0 ) {
V_74 = V_43 ;
goto V_80;
}
V_2 -> V_40 = F_40 ( V_71 , 32 , V_43 , 0 ,
& V_81 , NULL ) ;
if ( ! V_2 -> V_40 ) {
V_74 = - V_82 ;
goto V_83;
}
V_74 = F_21 ( V_2 , V_43 ) ;
if ( V_74 < 0 )
goto V_84;
F_41 ( V_2 -> V_42 , F_12 ,
V_2 ) ;
V_74 = F_42 ( & V_2 -> V_12 , & V_65 -> V_69 , 4 ,
V_2 -> V_18 + F_43 ( V_2 ) ,
V_2 -> V_18 + F_44 ( V_2 ) + V_29 ,
V_2 -> V_18 + F_44 ( V_2 ) + V_30 ,
V_2 -> V_18 + F_28 ( V_2 ) , NULL , 0 ) ;
if ( V_74 )
goto V_84;
V_2 -> V_12 . V_85 = F_25 ;
V_2 -> V_12 . V_86 = F_27 ;
V_2 -> V_12 . V_18 = V_2 -> V_76 * 32 ;
V_74 = F_45 ( & V_2 -> V_12 , V_2 ) ;
if ( V_74 )
goto V_84;
return 0 ;
V_84:
F_46 ( V_2 -> V_40 ) ;
V_83:
F_47 ( V_43 , 32 ) ;
V_80:
F_48 ( V_2 -> V_18 ) ;
return V_74 ;
}
static int T_3 F_49 ( void )
{
return F_50 ( & V_87 ) ;
}
