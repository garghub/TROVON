static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , int V_5 )
{
void T_1 * V_6 = V_4 -> V_6 ;
T_2 V_7 ;
F_4 ( V_4 -> V_8 , L_1 , V_9 ) ;
V_7 = F_5 ( V_6 + V_10 ) & V_11 ;
if ( V_5 )
F_6 ( V_7 | V_12 , V_6 + V_10 ) ;
else
F_6 ( V_7 & ~ V_12 , V_6 + V_10 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
int V_13 , unsigned int V_14 , int V_15 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_7 ;
F_4 ( V_4 -> V_8 , L_1 , V_9 ) ;
V_7 = F_5 ( V_4 -> V_6 + V_10 ) ;
if ( V_13 == V_16 )
V_7 &= ~ V_17 ;
else
V_7 |= V_17 ;
F_6 ( V_7 , V_4 -> V_6 + V_10 ) ;
V_4 -> V_18 = V_14 ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 , int V_21 ,
struct V_2 * V_22 )
{
struct V_23 * V_24 = V_20 -> V_25 ;
struct V_1 * V_4 = F_1 ( V_24 -> V_3 ) ;
unsigned long V_26 ;
F_4 ( V_4 -> V_8 , L_1 , V_9 ) ;
switch ( V_21 ) {
case V_27 :
case V_28 :
case V_29 :
F_9 ( & V_4 -> V_30 , V_26 ) ;
F_3 ( V_4 , 1 ) ;
F_10 ( & V_4 -> V_30 , V_26 ) ;
break;
case V_31 :
case V_32 :
case V_33 :
F_9 ( & V_4 -> V_30 , V_26 ) ;
F_3 ( V_4 , 0 ) ;
F_10 ( & V_4 -> V_30 , V_26 ) ;
break;
default:
return - V_34 ;
}
return 0 ;
}
static int F_11 ( struct V_19 * V_20 ,
struct V_35 * V_36 ,
struct V_2 * V_37 )
{
struct V_23 * V_24 = V_20 -> V_25 ;
struct V_1 * V_4 = F_1 ( V_24 -> V_3 ) ;
void T_1 * V_6 = V_4 -> V_6 ;
struct V_38 * V_39 ;
T_2 V_40 , V_7 , V_41 ;
unsigned long V_26 ;
int V_42 , V_43 ;
F_4 ( V_4 -> V_8 , L_1 , V_9 ) ;
if ( V_20 -> V_44 == V_45 )
V_39 = V_4 -> V_46 ;
else {
F_12 ( V_4 -> V_8 , L_2 ) ;
return - V_34 ;
}
F_13 ( V_24 -> V_3 , V_20 , V_39 ) ;
F_9 ( & V_4 -> V_30 , V_26 ) ;
V_40 = F_5 ( V_6 + V_47 ) & V_48 ;
V_41 = F_5 ( V_6 + V_49 ) & V_50 ;
V_7 = F_5 ( V_6 + V_10 ) & V_11 ;
V_40 &= ~ V_51 ;
V_40 |= ( 0x7 << V_52 ) ;
V_40 |= V_53 ;
V_40 |= V_54 ;
V_40 &= ~ V_55 ;
switch ( F_14 ( V_36 ) ) {
case 16 :
V_40 |= V_56 ;
break;
default:
F_12 ( V_4 -> V_8 , L_3 ) ;
goto V_57;
}
V_43 = V_4 -> V_18 / F_15 ( V_36 ) ;
for ( V_42 = 0 ; V_42 < F_16 ( V_58 ) ; V_42 ++ )
if ( V_43 == V_58 [ V_42 ] )
break;
if ( V_42 == F_16 ( V_58 ) ) {
F_12 ( V_4 -> V_8 , L_4 ,
V_4 -> V_18 , F_15 ( V_36 ) ) ;
goto V_57;
}
V_40 &= ~ V_59 ;
switch ( V_43 ) {
case 256 :
V_40 |= V_60 ;
break;
case 384 :
V_40 |= V_61 ;
break;
case 512 :
V_40 |= V_62 ;
break;
}
V_41 &= ~ V_63 ;
switch ( F_15 ( V_36 ) ) {
case 44100 :
V_41 |= V_64 ;
break;
case 48000 :
V_41 |= V_65 ;
break;
case 32000 :
V_41 |= V_66 ;
break;
case 96000 :
V_41 |= V_67 ;
break;
default:
F_12 ( V_4 -> V_8 , L_5 ,
F_15 ( V_36 ) ) ;
goto V_57;
}
V_41 &= ~ V_68 ;
V_41 |= V_69 ;
V_41 |= V_70 ;
F_6 ( V_40 , V_6 + V_47 ) ;
F_6 ( V_41 , V_6 + V_49 ) ;
F_6 ( V_7 , V_6 + V_10 ) ;
F_10 ( & V_4 -> V_30 , V_26 ) ;
return 0 ;
V_57:
F_10 ( & V_4 -> V_30 , V_26 ) ;
return - V_34 ;
}
static void F_17 ( struct V_19 * V_20 ,
struct V_2 * V_22 )
{
struct V_23 * V_24 = V_20 -> V_25 ;
struct V_1 * V_4 = F_1 ( V_24 -> V_3 ) ;
void T_1 * V_6 = V_4 -> V_6 ;
T_2 V_40 , V_7 ;
F_4 ( V_4 -> V_8 , L_1 , V_9 ) ;
V_40 = F_5 ( V_6 + V_47 ) & V_48 ;
V_7 = F_5 ( V_6 + V_10 ) & V_11 ;
F_6 ( V_40 | V_71 , V_6 + V_47 ) ;
F_18 () ;
F_6 ( V_7 & ~ V_12 , V_6 + V_10 ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_40 = V_4 -> V_72 ;
F_4 ( V_4 -> V_8 , L_1 , V_9 ) ;
V_4 -> V_73 = F_5 ( V_4 -> V_6 + V_10 ) & V_11 ;
V_4 -> V_72 = F_5 ( V_4 -> V_6 + V_47 ) & V_48 ;
V_4 -> V_74 = F_5 ( V_4 -> V_6 + V_49 ) & V_50 ;
F_6 ( V_40 | V_71 , V_4 -> V_6 + V_47 ) ;
F_18 () ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_4 -> V_8 , L_1 , V_9 ) ;
F_6 ( V_4 -> V_73 , V_4 -> V_6 + V_10 ) ;
F_6 ( V_4 -> V_72 , V_4 -> V_6 + V_47 ) ;
F_6 ( V_4 -> V_74 , V_4 -> V_6 + V_49 ) ;
return 0 ;
}
static int F_21 ( struct V_75 * V_76 )
{
struct V_77 * V_78 ;
struct V_79 * V_80 , * V_81 ;
struct V_1 * V_4 ;
int V_82 ;
V_78 = V_76 -> V_8 . V_83 ;
F_4 ( & V_76 -> V_8 , L_1 , V_9 ) ;
V_81 = F_22 ( V_76 , V_84 , 0 ) ;
if ( ! V_81 ) {
F_12 ( & V_76 -> V_8 , L_6 ) ;
return - V_85 ;
}
V_80 = F_22 ( V_76 , V_86 , 0 ) ;
if ( ! V_80 ) {
F_12 ( & V_76 -> V_8 , L_7 ) ;
return - V_85 ;
}
if ( V_78 && V_78 -> V_87
&& V_78 -> V_87 ( V_76 ) ) {
F_12 ( & V_76 -> V_8 , L_8 ) ;
return - V_34 ;
}
V_4 = & V_88 ;
V_4 -> V_8 = & V_76 -> V_8 ;
F_23 ( & V_4 -> V_30 ) ;
V_4 -> V_89 = F_24 ( & V_76 -> V_8 , L_9 ) ;
if ( F_25 ( V_4 -> V_89 ) ) {
F_12 ( & V_76 -> V_8 , L_10 ) ;
V_82 = - V_90 ;
goto V_91;
}
F_26 ( V_4 -> V_89 ) ;
V_4 -> V_92 = F_24 ( & V_76 -> V_8 , L_11 ) ;
if ( F_25 ( V_4 -> V_92 ) ) {
F_12 ( & V_76 -> V_8 , L_12 ) ;
V_82 = - V_90 ;
goto V_93;
}
F_26 ( V_4 -> V_92 ) ;
if ( ! F_27 ( V_80 -> V_94 ,
F_28 ( V_80 ) , L_13 ) ) {
F_12 ( & V_76 -> V_8 , L_14 ) ;
V_82 = - V_95 ;
goto V_96;
}
V_4 -> V_6 = F_29 ( V_80 -> V_94 , 0x100 ) ;
if ( V_4 -> V_6 == NULL ) {
F_12 ( & V_76 -> V_8 , L_15 ) ;
V_82 = - V_85 ;
goto V_97;
}
F_30 ( & V_76 -> V_8 , V_4 ) ;
V_82 = F_31 ( & V_76 -> V_8 ,
& V_98 , & V_99 , 1 ) ;
if ( V_82 != 0 ) {
F_12 ( & V_76 -> V_8 , L_16 ) ;
goto V_100;
}
V_101 . V_102 = 2 ;
V_101 . V_103 = V_80 -> V_94 + V_104 ;
V_101 . V_105 = V_81 -> V_94 ;
V_4 -> V_46 = & V_101 ;
V_82 = F_32 ( & V_76 -> V_8 ) ;
if ( V_82 ) {
F_12 ( & V_76 -> V_8 , L_17 , V_82 ) ;
goto V_100;
}
return 0 ;
V_100:
F_33 ( V_4 -> V_6 ) ;
V_97:
F_34 ( V_80 -> V_94 , F_28 ( V_80 ) ) ;
V_96:
F_35 ( V_4 -> V_92 ) ;
V_93:
F_35 ( V_4 -> V_89 ) ;
V_91:
return V_82 ;
}
static int F_36 ( struct V_75 * V_76 )
{
struct V_1 * V_4 = & V_88 ;
struct V_79 * V_80 ;
F_33 ( V_4 -> V_6 ) ;
V_80 = F_22 ( V_76 , V_86 , 0 ) ;
if ( V_80 )
F_34 ( V_80 -> V_94 , F_28 ( V_80 ) ) ;
F_35 ( V_4 -> V_92 ) ;
F_35 ( V_4 -> V_89 ) ;
return 0 ;
}
