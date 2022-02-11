static int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
T_1 V_7 = F_2 ( V_2 -> V_5 + V_8 ) ;
switch ( V_3 ) {
case V_9 :
V_4 |= V_10 ;
break;
case V_11 :
V_4 &= ~ ( V_10 & V_12 ) ;
break;
case V_13 :
V_4 &= ~ ( V_10 ) ;
V_4 |= V_12 ;
V_7 |= ( 0x7 << 17 ) ;
break;
default:
F_3 ( V_14
L_1 ,
V_3 ) ;
V_4 |= V_10 ;
}
F_4 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_4 ( V_7 , V_2 -> V_5 + V_8 ) ;
return 0 ;
}
static inline void F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
T_1 V_17 = F_2 ( V_2 -> V_5 + V_18 ) ;
T_1 V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( V_16 -> V_19 & V_20 )
V_17 &= ~ V_21 ;
if ( V_16 -> V_19 & V_22 )
V_17 &= ~ V_23 ;
if ( V_16 -> V_19 & V_24 )
V_17 &= ~ V_25 ;
if ( V_16 -> V_19 & V_26 )
V_17 |= V_27 ;
if ( V_16 -> V_19 & V_28 )
V_17 |= V_29 ;
if ( V_16 -> V_19 & V_30 )
V_4 |= V_31 ;
else
V_4 &= ~ V_31 ;
if ( V_16 -> V_19 & V_32 )
V_4 |= V_33 ;
else
V_4 &= ~ V_33 ;
if ( V_16 -> V_34 ) {
V_4 &= ~ F_6 ( 0xff ) ;
V_4 |= F_6 ( V_16 -> V_34 / 2 ) ;
}
F_4 ( V_17 , V_2 -> V_5 + V_18 ) ;
F_4 ( V_4 , V_2 -> V_5 + V_6 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
T_1 V_17 = F_2 ( V_2 -> V_5 + V_18 ) ;
F_4 ( V_17 | V_35 , V_2 -> V_5 + V_18 ) ;
F_8 ( 11 ) ;
F_4 ( V_17 & ~ V_35 , V_2 -> V_5 + V_18 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
int V_38 = 0 ;
struct V_15 * V_16 ;
T_1 V_17 ;
V_16 = V_37 -> V_39 ;
F_10 ( V_2 -> V_40 ) ;
F_7 ( V_2 ) ;
V_17 = F_2 ( V_2 -> V_5 + V_18 ) | V_41 ;
F_4 ( V_17 , V_2 -> V_5 + V_18 ) ;
while ( F_2 ( V_2 -> V_5 + V_18 ) & V_41 )
F_11 () ;
F_5 ( V_2 , V_16 ) ;
if ( V_16 -> V_42 )
V_38 = V_16 -> V_42 ( V_37 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( F_12 () )
F_13 ( & F_14 ( & V_2 -> V_2 ) -> V_43 ) ;
V_17 = F_2 ( V_2 -> V_5 + V_18 ) & ~ V_44 ;
F_4 ( V_17 , V_2 -> V_5 + V_18 ) ;
F_4 ( V_45 | V_46 , V_2 -> V_5 + V_47 ) ;
F_15 () ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_15 * V_16 ;
T_1 V_48 ;
V_16 = V_37 -> V_39 ;
if ( F_12 () )
F_17 ( & F_14 ( & V_2 -> V_2 ) -> V_43 ) ;
if ( V_16 -> exit )
V_16 -> exit ( V_37 ) ;
F_7 ( V_2 ) ;
V_48 = F_2 ( V_2 -> V_5 + V_49 ) | 0x01 ;
F_4 ( V_48 , V_2 -> V_5 + V_49 ) ;
F_8 ( 10 ) ;
F_18 ( V_2 -> V_40 ) ;
}
static int F_19 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_37 . V_54 ;
struct V_15 * V_55 ;
T_2 V_56 ;
if ( ! V_53 )
return 0 ;
if ( ! V_51 -> V_37 . V_57 )
V_51 -> V_37 . V_57 = & V_51 -> V_37 . V_58 ;
if ( ! V_51 -> V_37 . V_58 )
V_51 -> V_37 . V_58 = F_20 ( 32 ) ;
V_55 = F_21 ( & V_51 -> V_37 , sizeof( * V_55 ) , V_59 ) ;
if ( ! V_55 )
return - V_60 ;
if ( F_22 ( V_53 , L_2 , NULL ) )
V_55 -> V_19 |= V_20 ;
if ( F_22 ( V_53 , L_3 , NULL ) )
V_55 -> V_19 |= V_22 ;
if ( F_22 ( V_53 , L_4 , NULL ) )
V_55 -> V_19 |= V_24 ;
if ( F_22 ( V_53 , L_5 , NULL ) )
V_55 -> V_19 |= V_28 ;
if ( F_22 ( V_53 , L_6 , NULL ) )
V_55 -> V_19 |= V_26 ;
if ( F_22 ( V_53 , L_7 , NULL ) )
V_55 -> V_19 |= V_30 ;
if ( F_22 ( V_53 , L_8 , NULL ) )
V_55 -> V_19 |= V_32 ;
if ( ! F_23 ( V_53 , L_9 , & V_56 ) )
V_55 -> V_34 = V_56 ;
if ( ! F_23 ( V_53 , L_10 , & V_56 ) )
V_55 -> V_61 = V_56 ;
if ( ! F_23 ( V_53 , L_11 , & V_56 ) )
V_55 -> V_62 = V_56 ;
V_51 -> V_37 . V_39 = V_55 ;
return 0 ;
}
static int F_19 ( struct V_50 * V_51 )
{
return 0 ;
}
int F_24 ( const struct V_63 * V_64 , struct V_50 * V_51 )
{
int V_38 , V_65 ;
struct V_66 * V_67 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_68 * V_69 ;
struct V_40 * V_70 ;
V_38 = F_19 ( V_51 ) ;
if ( V_38 )
return V_38 ;
V_16 = V_51 -> V_37 . V_39 ;
if ( ! V_16 )
return - V_71 ;
V_65 = F_25 ( V_51 , 0 ) ;
if ( V_65 < 0 ) {
F_26 ( L_12 ) ;
return - V_72 ;
}
V_70 = F_27 ( & V_51 -> V_37 , NULL ) ;
if ( F_28 ( V_70 ) )
return F_29 ( V_70 ) ;
V_67 = F_30 ( V_64 , & V_51 -> V_37 , L_13 ) ;
if ( ! V_67 ) {
V_38 = - V_60 ;
goto V_73;
}
V_69 = F_31 ( V_51 , V_74 , 0 ) ;
if ( ! V_69 ) {
F_26 ( L_14 ) ;
V_38 = - V_72 ;
goto V_75;
}
V_67 -> V_76 = V_69 -> V_77 ;
V_67 -> V_78 = F_32 ( V_69 ) ;
if ( ! F_33 ( V_67 -> V_76 , V_67 -> V_78 , V_79 ) ) {
F_34 ( L_15 ) ;
V_38 = - V_80 ;
goto V_75;
}
V_67 -> V_81 = F_35 ( V_67 -> V_76 , V_67 -> V_78 ) ;
if ( ! V_67 -> V_81 ) {
F_34 ( L_16 ) ;
V_38 = - V_60 ;
goto V_82;
}
V_2 = (struct V_1 * ) F_36 ( V_67 ) ;
V_2 -> V_37 = & V_51 -> V_37 ;
V_2 -> V_40 = V_70 ;
V_2 -> V_5 = ( void V_83 * ) V_67 -> V_81 ;
if ( ( V_38 = F_9 ( V_2 , & V_51 -> V_37 ) ) < 0 ) {
F_34 ( L_17 ) ;
goto V_84;
}
F_1 ( V_2 , V_16 -> V_61 ) ;
if ( V_16 -> V_62 )
V_67 -> V_62 = V_16 -> V_62 ;
F_37 ( F_36 ( V_67 ) ) ;
V_38 = F_38 ( V_67 , V_65 , 0 ) ;
if ( V_38 == 0 )
return V_38 ;
F_16 ( V_2 , & V_51 -> V_37 ) ;
V_84:
F_39 ( V_67 -> V_81 ) ;
V_82:
F_40 ( V_67 -> V_76 , V_67 -> V_78 ) ;
V_75:
F_41 ( V_67 ) ;
V_73:
F_42 ( V_70 ) ;
return V_38 ;
}
void F_43 ( struct V_66 * V_67 , struct V_50 * V_51 )
{
struct V_1 * V_2 = F_44 ( V_67 ) ;
F_45 ( V_67 ) ;
F_16 ( V_2 , & V_51 -> V_37 ) ;
F_39 ( V_67 -> V_81 ) ;
F_40 ( V_67 -> V_76 , V_67 -> V_78 ) ;
F_41 ( V_67 ) ;
F_42 ( V_2 -> V_40 ) ;
}
static int
F_46 ( struct V_66 * V_67 )
{
struct V_85 * V_2 = F_36 ( V_67 ) ;
int V_86 ;
F_47 ( V_2 , L_18 , V_2 ) ;
V_2 -> V_87 = 3 ;
if ( ( V_86 = F_48 ( V_2 ) ) < 0 )
return V_86 ;
if ( ( V_86 = F_49 ( V_2 ) ) < 0 ) {
F_50 ( V_67 -> V_43 . V_88 , L_19 ,
V_67 -> V_43 . V_89 ) ;
F_51 ( V_67 ) ;
return V_86 ;
}
return 0 ;
}
static int F_52 ( struct V_50 * V_51 )
{
F_34 ( L_20 ) ;
if ( F_53 () )
return - V_71 ;
return F_24 ( & V_90 , V_51 ) ;
}
static int F_54 ( struct V_50 * V_51 )
{
struct V_66 * V_67 = F_55 ( V_51 ) ;
F_43 ( V_67 , V_51 ) ;
F_56 ( V_51 , NULL ) ;
return 0 ;
}
static int F_57 ( struct V_36 * V_37 )
{
struct V_66 * V_67 = F_58 ( V_37 ) ;
struct V_1 * V_2 = F_44 ( V_67 ) ;
if ( F_59 ( V_91 , V_2 -> V_2 . V_92 ) )
F_60 ( 5 ) ;
V_2 -> V_2 . V_92 = V_91 ;
F_16 ( V_2 , V_37 ) ;
return 0 ;
}
static int F_61 ( struct V_36 * V_37 )
{
struct V_66 * V_67 = F_58 ( V_37 ) ;
struct V_1 * V_2 = F_44 ( V_67 ) ;
struct V_15 * V_16 = V_37 -> V_39 ;
int V_93 ;
if ( F_59 ( V_91 , V_2 -> V_2 . V_92 ) )
F_60 ( 5 ) ;
V_2 -> V_2 . V_92 = V_91 ;
if ( ( V_93 = F_9 ( V_2 , V_37 ) ) < 0 )
return V_93 ;
F_1 ( V_2 , V_16 -> V_61 ) ;
F_62 ( V_67 , false ) ;
return 0 ;
}
