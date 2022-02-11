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
int F_19 ( const struct V_50 * V_51 , struct V_52 * V_53 )
{
int V_38 , V_54 ;
struct V_55 * V_56 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_57 * V_58 ;
struct V_40 * V_59 ;
V_16 = V_53 -> V_37 . V_39 ;
if ( ! V_16 )
return - V_60 ;
V_54 = F_20 ( V_53 , 0 ) ;
if ( V_54 < 0 ) {
F_21 ( L_2 ) ;
return - V_61 ;
}
V_59 = F_22 ( & V_53 -> V_37 , NULL ) ;
if ( F_23 ( V_59 ) )
return F_24 ( V_59 ) ;
V_56 = F_25 ( V_51 , & V_53 -> V_37 , L_3 ) ;
if ( ! V_56 ) {
V_38 = - V_62 ;
goto V_63;
}
V_58 = F_26 ( V_53 , V_64 , 0 ) ;
if ( ! V_58 ) {
F_21 ( L_4 ) ;
V_38 = - V_61 ;
goto V_65;
}
V_56 -> V_66 = V_58 -> V_67 ;
V_56 -> V_68 = F_27 ( V_58 ) ;
if ( ! F_28 ( V_56 -> V_66 , V_56 -> V_68 , V_69 ) ) {
F_29 ( L_5 ) ;
V_38 = - V_70 ;
goto V_65;
}
V_56 -> V_71 = F_30 ( V_56 -> V_66 , V_56 -> V_68 ) ;
if ( ! V_56 -> V_71 ) {
F_29 ( L_6 ) ;
V_38 = - V_62 ;
goto V_72;
}
V_2 = (struct V_1 * ) F_31 ( V_56 ) ;
V_2 -> V_37 = & V_53 -> V_37 ;
V_2 -> V_40 = V_59 ;
V_2 -> V_5 = ( void V_73 * ) V_56 -> V_71 ;
if ( ( V_38 = F_9 ( V_2 , & V_53 -> V_37 ) ) < 0 ) {
F_29 ( L_7 ) ;
goto V_74;
}
F_1 ( V_2 , V_16 -> V_75 ) ;
if ( V_16 -> V_76 )
V_56 -> V_76 = V_16 -> V_76 ;
F_32 ( F_31 ( V_56 ) ) ;
V_38 = F_33 ( V_56 , V_54 , 0 ) ;
if ( V_38 == 0 )
return V_38 ;
F_16 ( V_2 , & V_53 -> V_37 ) ;
V_74:
F_34 ( V_56 -> V_71 ) ;
V_72:
F_35 ( V_56 -> V_66 , V_56 -> V_68 ) ;
V_65:
F_36 ( V_56 ) ;
V_63:
F_37 ( V_59 ) ;
return V_38 ;
}
void F_38 ( struct V_55 * V_56 , struct V_52 * V_53 )
{
struct V_1 * V_2 = F_39 ( V_56 ) ;
F_40 ( V_56 ) ;
F_16 ( V_2 , & V_53 -> V_37 ) ;
F_34 ( V_56 -> V_71 ) ;
F_35 ( V_56 -> V_66 , V_56 -> V_68 ) ;
F_36 ( V_56 ) ;
F_37 ( V_2 -> V_40 ) ;
}
static int T_2
F_41 ( struct V_55 * V_56 )
{
struct V_77 * V_2 = F_31 ( V_56 ) ;
int V_78 ;
F_42 ( V_2 , L_8 , V_2 ) ;
V_2 -> V_79 = 3 ;
if ( ( V_78 = F_43 ( V_2 ) ) < 0 )
return V_78 ;
if ( ( V_78 = F_44 ( V_2 ) ) < 0 ) {
F_45 ( L_9 , V_56 -> V_43 . V_80 ) ;
F_46 ( V_56 ) ;
return V_78 ;
}
return 0 ;
}
static int F_47 ( struct V_52 * V_53 )
{
F_29 ( L_10 ) ;
if ( F_48 () )
return - V_60 ;
return F_19 ( & V_81 , V_53 ) ;
}
static int F_49 ( struct V_52 * V_53 )
{
struct V_55 * V_56 = F_50 ( V_53 ) ;
F_38 ( V_56 , V_53 ) ;
F_51 ( V_53 , NULL ) ;
return 0 ;
}
static int F_52 ( struct V_36 * V_37 )
{
struct V_55 * V_56 = F_53 ( V_37 ) ;
struct V_1 * V_2 = F_39 ( V_56 ) ;
if ( F_54 ( V_82 , V_2 -> V_2 . V_83 ) )
F_55 ( 5 ) ;
V_2 -> V_2 . V_83 = V_82 ;
F_16 ( V_2 , V_37 ) ;
V_56 -> V_84 = V_85 ;
return 0 ;
}
static int F_56 ( struct V_36 * V_37 )
{
struct V_55 * V_56 = F_53 ( V_37 ) ;
struct V_1 * V_2 = F_39 ( V_56 ) ;
struct V_15 * V_16 = V_37 -> V_39 ;
int V_86 ;
if ( F_54 ( V_82 , V_2 -> V_2 . V_83 ) )
F_55 ( 5 ) ;
V_2 -> V_2 . V_83 = V_82 ;
if ( ( V_86 = F_9 ( V_2 , V_37 ) ) < 0 )
return V_86 ;
F_1 ( V_2 , V_16 -> V_75 ) ;
F_57 ( V_56 ) ;
return 0 ;
}
