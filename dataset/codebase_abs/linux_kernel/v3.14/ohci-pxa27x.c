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
struct V_39 * V_40 = F_10 ( V_37 ) ;
V_16 = F_11 ( V_37 ) ;
F_12 ( V_2 -> V_41 ) ;
F_7 ( V_2 ) ;
V_17 = F_2 ( V_2 -> V_5 + V_18 ) | V_42 ;
F_4 ( V_17 , V_2 -> V_5 + V_18 ) ;
while ( F_2 ( V_2 -> V_5 + V_18 ) & V_42 )
F_13 () ;
F_5 ( V_2 , V_16 ) ;
if ( V_16 -> V_43 )
V_38 = V_16 -> V_43 ( V_37 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( F_14 () )
F_15 ( & V_40 -> V_44 ) ;
V_17 = F_2 ( V_2 -> V_5 + V_18 ) & ~ V_45 ;
F_4 ( V_17 , V_2 -> V_5 + V_18 ) ;
F_4 ( V_46 | V_47 , V_2 -> V_5 + V_48 ) ;
F_16 () ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_15 * V_16 ;
struct V_39 * V_40 = F_10 ( V_37 ) ;
T_1 V_49 ;
V_16 = F_11 ( V_37 ) ;
if ( F_14 () )
F_18 ( & V_40 -> V_44 ) ;
if ( V_16 -> exit )
V_16 -> exit ( V_37 ) ;
F_7 ( V_2 ) ;
V_49 = F_2 ( V_2 -> V_5 + V_50 ) | 0x01 ;
F_4 ( V_49 , V_2 -> V_5 + V_50 ) ;
F_8 ( 10 ) ;
F_19 ( V_2 -> V_41 ) ;
}
static int F_20 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_37 . V_55 ;
struct V_15 * V_56 ;
T_2 V_57 ;
int V_58 ;
if ( ! V_54 )
return 0 ;
V_58 = F_21 ( & V_52 -> V_37 , F_22 ( 32 ) ) ;
if ( V_58 )
return V_58 ;
V_56 = F_23 ( & V_52 -> V_37 , sizeof( * V_56 ) , V_59 ) ;
if ( ! V_56 )
return - V_60 ;
if ( F_24 ( V_54 , L_2 , NULL ) )
V_56 -> V_19 |= V_20 ;
if ( F_24 ( V_54 , L_3 , NULL ) )
V_56 -> V_19 |= V_22 ;
if ( F_24 ( V_54 , L_4 , NULL ) )
V_56 -> V_19 |= V_24 ;
if ( F_24 ( V_54 , L_5 , NULL ) )
V_56 -> V_19 |= V_28 ;
if ( F_24 ( V_54 , L_6 , NULL ) )
V_56 -> V_19 |= V_26 ;
if ( F_24 ( V_54 , L_7 , NULL ) )
V_56 -> V_19 |= V_30 ;
if ( F_24 ( V_54 , L_8 , NULL ) )
V_56 -> V_19 |= V_32 ;
if ( ! F_25 ( V_54 , L_9 , & V_57 ) )
V_56 -> V_34 = V_57 ;
if ( ! F_25 ( V_54 , L_10 , & V_57 ) )
V_56 -> V_61 = V_57 ;
if ( ! F_25 ( V_54 , L_11 , & V_57 ) )
V_56 -> V_62 = V_57 ;
V_52 -> V_37 . V_63 = V_56 ;
return 0 ;
}
static int F_20 ( struct V_51 * V_52 )
{
return 0 ;
}
int F_26 ( const struct V_64 * V_65 , struct V_51 * V_52 )
{
int V_38 , V_66 ;
struct V_39 * V_40 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
struct V_41 * V_71 ;
V_38 = F_20 ( V_52 ) ;
if ( V_38 )
return V_38 ;
V_16 = F_11 ( & V_52 -> V_37 ) ;
if ( ! V_16 )
return - V_72 ;
V_66 = F_27 ( V_52 , 0 ) ;
if ( V_66 < 0 ) {
F_28 ( L_12 ) ;
return - V_73 ;
}
V_71 = F_29 ( & V_52 -> V_37 , NULL ) ;
if ( F_30 ( V_71 ) )
return F_31 ( V_71 ) ;
V_40 = F_32 ( V_65 , & V_52 -> V_37 , L_13 ) ;
if ( ! V_40 )
return - V_60 ;
V_70 = F_33 ( V_52 , V_74 , 0 ) ;
if ( ! V_70 ) {
F_28 ( L_14 ) ;
V_38 = - V_73 ;
goto V_75;
}
V_40 -> V_76 = V_70 -> V_77 ;
V_40 -> V_78 = F_34 ( V_70 ) ;
V_40 -> V_79 = F_35 ( & V_52 -> V_37 , V_70 ) ;
if ( F_30 ( V_40 -> V_79 ) ) {
V_38 = F_31 ( V_40 -> V_79 ) ;
goto V_75;
}
V_2 = F_36 ( V_40 ) ;
V_2 -> V_41 = V_71 ;
V_2 -> V_5 = ( void V_80 * ) V_40 -> V_79 ;
V_38 = F_9 ( V_2 , & V_52 -> V_37 ) ;
if ( V_38 < 0 ) {
F_37 ( L_15 ) ;
goto V_75;
}
F_1 ( V_2 , V_16 -> V_61 ) ;
if ( V_16 -> V_62 )
V_40 -> V_62 = V_16 -> V_62 ;
V_68 = F_38 ( V_40 ) ;
V_68 -> V_81 = 3 ;
V_38 = F_39 ( V_40 , V_66 , 0 ) ;
if ( V_38 == 0 ) {
F_40 ( V_40 -> V_44 . V_82 ) ;
return V_38 ;
}
F_17 ( V_2 , & V_52 -> V_37 ) ;
V_75:
F_41 ( V_40 ) ;
return V_38 ;
}
void F_42 ( struct V_39 * V_40 , struct V_51 * V_52 )
{
struct V_1 * V_2 = F_36 ( V_40 ) ;
F_43 ( V_40 ) ;
F_17 ( V_2 , & V_52 -> V_37 ) ;
F_41 ( V_40 ) ;
}
static int F_44 ( struct V_51 * V_52 )
{
F_37 ( L_16 ) ;
if ( F_45 () )
return - V_72 ;
return F_26 ( & V_83 , V_52 ) ;
}
static int F_46 ( struct V_51 * V_52 )
{
struct V_39 * V_40 = F_47 ( V_52 ) ;
F_42 ( V_40 , V_52 ) ;
return 0 ;
}
static int F_48 ( struct V_36 * V_37 )
{
struct V_39 * V_40 = F_10 ( V_37 ) ;
struct V_1 * V_2 = F_36 ( V_40 ) ;
struct V_67 * V_68 = F_38 ( V_40 ) ;
bool V_84 = F_49 ( V_37 ) ;
int V_58 ;
if ( F_50 ( V_85 , V_68 -> V_86 ) )
F_51 ( 5 ) ;
V_68 -> V_86 = V_85 ;
V_58 = F_52 ( V_40 , V_84 ) ;
if ( V_58 )
return V_58 ;
F_17 ( V_2 , V_37 ) ;
return V_58 ;
}
static int F_53 ( struct V_36 * V_37 )
{
struct V_39 * V_40 = F_10 ( V_37 ) ;
struct V_1 * V_2 = F_36 ( V_40 ) ;
struct V_15 * V_16 = F_11 ( V_37 ) ;
struct V_67 * V_68 = F_38 ( V_40 ) ;
int V_87 ;
if ( F_50 ( V_85 , V_68 -> V_86 ) )
F_51 ( 5 ) ;
V_68 -> V_86 = V_85 ;
V_87 = F_9 ( V_2 , V_37 ) ;
if ( V_87 < 0 )
return V_87 ;
F_1 ( V_2 , V_16 -> V_61 ) ;
F_54 ( V_40 , false ) ;
return 0 ;
}
static int T_3 F_55 ( void )
{
if ( F_45 () )
return - V_72 ;
F_56 ( L_17 V_88 L_18 , V_89 ) ;
F_57 ( & V_83 , & V_90 ) ;
return F_58 ( & V_91 ) ;
}
static void T_4 F_59 ( void )
{
F_60 ( & V_91 ) ;
}
