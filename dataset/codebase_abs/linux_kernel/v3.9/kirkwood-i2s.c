static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
unsigned long V_7 ;
switch ( V_3 & V_8 ) {
case V_9 :
V_6 = V_10 ;
break;
case V_11 :
V_6 = V_12 ;
break;
case V_13 :
V_6 = V_14 ;
break;
default:
return - V_15 ;
}
V_7 = F_3 ( V_5 -> V_16 + V_17 ) ;
V_7 &= ~ V_18 ;
V_7 |= V_6 ;
F_4 ( V_7 , V_5 -> V_16 + V_17 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_19 ) ;
V_7 &= ~ V_18 ;
V_7 |= V_6 ;
F_4 ( V_7 , V_5 -> V_16 + V_19 ) ;
return 0 ;
}
static inline void F_5 ( void T_1 * V_16 , unsigned long V_20 )
{
unsigned long V_7 ;
V_7 = V_21 ;
switch ( V_20 ) {
default:
case 44100 :
V_7 |= V_22 ;
break;
case 48000 :
V_7 |= V_23 ;
break;
case 96000 :
V_7 |= V_24 ;
break;
}
F_4 ( V_7 , V_16 + V_25 ) ;
do {
F_6 () ;
V_7 = F_3 ( V_16 + V_26 ) ;
V_7 &= V_27 ;
} while ( V_7 == 0 );
}
static void F_7 ( struct V_1 * V_28 ,
struct V_4 * V_5 , unsigned long V_20 )
{
T_2 V_29 ;
if ( V_20 == 44100 || V_20 == 48000 || V_20 == 96000 ) {
F_8 ( V_28 -> V_30 , L_1 ,
V_31 , V_20 ) ;
F_5 ( V_5 -> V_16 , V_20 ) ;
V_29 = V_32 ;
} else if ( ! F_9 ( V_5 -> V_33 ) ) {
F_8 ( V_28 -> V_30 , L_2 ,
V_31 , V_20 , 256 * V_20 ) ;
F_10 ( V_5 -> V_33 , 256 * V_20 ) ;
V_29 = V_34 ;
}
F_4 ( V_29 , V_5 -> V_16 + V_35 ) ;
}
static int F_11 ( struct V_36 * V_37 ,
struct V_1 * V_28 )
{
struct V_4 * V_5 = F_2 ( V_28 ) ;
F_12 ( V_28 , V_37 , V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_1 * V_28 )
{
struct V_4 * V_5 = F_2 ( V_28 ) ;
T_2 V_40 , V_41 ;
unsigned int V_42 ;
unsigned long V_43 ;
if ( V_37 -> V_44 == V_45 ) {
V_42 = V_17 ;
} else {
V_42 = V_19 ;
}
F_7 ( V_28 , V_5 , F_14 ( V_39 ) ) ;
V_43 = F_3 ( V_5 -> V_16 + V_42 ) ;
V_43 &= ~ V_46 ;
switch ( F_15 ( V_39 ) ) {
case V_47 :
V_43 |= V_48 ;
V_40 = V_49 |
V_50 ;
V_41 = V_51 |
V_52 ;
break;
case V_53 :
V_43 |= V_54 ;
V_40 = V_55 |
V_50 ;
V_41 = V_56 |
V_52 ;
break;
case V_57 :
V_43 |= V_58 ;
V_40 = V_59 |
V_50 ;
V_41 = V_60 |
V_52 ;
break;
default:
return - V_15 ;
}
if ( V_37 -> V_44 == V_45 ) {
if ( F_16 ( V_39 ) == 1 )
V_40 |= V_61 ;
else
V_40 |= V_62 ;
V_5 -> V_40 &= ~ ( V_63 |
V_50 |
V_64 |
V_65 ) ;
V_5 -> V_40 |= V_40 ;
} else {
V_5 -> V_41 &= ~ V_66 ;
V_5 -> V_41 |= V_41 ;
}
F_4 ( V_43 , V_5 -> V_16 + V_42 ) ;
return 0 ;
}
static int F_17 ( struct V_36 * V_37 ,
int V_67 , struct V_1 * V_28 )
{
struct V_4 * V_5 = F_2 ( V_28 ) ;
T_2 V_68 , V_7 ;
V_68 = F_3 ( V_5 -> V_16 + V_69 ) ;
if ( V_68 & V_70 ) {
unsigned V_71 = 5000 ;
do {
V_7 = V_68 ;
V_68 = F_3 ( V_5 -> V_16 + V_69 ) ;
if ( ! ( ( V_68 | V_7 ) & V_72 ) )
break;
F_18 ( 1 ) ;
} while ( V_71 -- );
if ( ( V_68 | V_7 ) & V_72 )
F_19 ( V_28 -> V_30 , L_3 ,
V_68 ) ;
}
switch ( V_67 ) {
case V_73 :
V_68 = V_5 -> V_40 ;
V_7 = V_68 & ~ ( V_50 |
V_64 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_69 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_74 ) ;
V_7 |= V_75 ;
F_4 ( V_7 , V_5 -> V_16 + V_74 ) ;
F_4 ( V_68 , V_5 -> V_16 + V_69 ) ;
break;
case V_76 :
V_68 |= V_70 | V_77 ;
F_4 ( V_68 , V_5 -> V_16 + V_69 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_74 ) ;
V_7 &= ~ V_75 ;
F_4 ( V_7 , V_5 -> V_16 + V_74 ) ;
V_68 &= ~ ( V_50 | V_64 ) ;
F_4 ( V_68 , V_5 -> V_16 + V_69 ) ;
break;
case V_78 :
case V_79 :
V_68 |= V_70 | V_77 ;
F_4 ( V_68 , V_5 -> V_16 + V_69 ) ;
break;
case V_80 :
case V_81 :
V_68 &= ~ ( V_70 | V_77 ) ;
F_4 ( V_68 , V_5 -> V_16 + V_69 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_20 ( struct V_36 * V_37 ,
int V_67 , struct V_1 * V_28 )
{
struct V_4 * V_5 = F_2 ( V_28 ) ;
T_2 V_68 , V_7 ;
V_7 = F_3 ( V_5 -> V_16 + V_82 ) ;
switch ( V_67 ) {
case V_73 :
V_68 = V_5 -> V_41 ;
V_7 = V_68 & ~ V_52 ;
F_4 ( V_7 , V_5 -> V_16 + V_82 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_74 ) ;
V_7 |= V_83 ;
F_4 ( V_7 , V_5 -> V_16 + V_74 ) ;
F_4 ( V_68 , V_5 -> V_16 + V_82 ) ;
break;
case V_76 :
V_7 = F_3 ( V_5 -> V_16 + V_82 ) ;
V_7 |= V_84 | V_85 ;
F_4 ( V_7 , V_5 -> V_16 + V_82 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_74 ) ;
V_7 &= ~ V_83 ;
F_4 ( V_7 , V_5 -> V_16 + V_74 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_82 ) ;
V_7 &= ~ ( V_52 | V_86 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_82 ) ;
break;
case V_78 :
case V_79 :
V_7 = F_3 ( V_5 -> V_16 + V_82 ) ;
V_7 |= V_84 | V_85 ;
F_4 ( V_7 , V_5 -> V_16 + V_82 ) ;
break;
case V_80 :
case V_81 :
V_7 = F_3 ( V_5 -> V_16 + V_82 ) ;
V_7 &= ~ ( V_84 | V_85 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_82 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_21 ( struct V_36 * V_37 , int V_67 ,
struct V_1 * V_28 )
{
if ( V_37 -> V_44 == V_45 )
return F_17 ( V_37 , V_67 , V_28 ) ;
else
return F_20 ( V_37 , V_67 , V_28 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_28 )
{
struct V_4 * V_5 = F_2 ( V_28 ) ;
unsigned long V_7 ;
unsigned int V_87 ;
F_4 ( 0xffffffff , V_5 -> V_16 + V_88 ) ;
F_4 ( 0 , V_5 -> V_16 + V_74 ) ;
V_87 = F_3 ( V_5 -> V_16 + 0x1200 ) ;
V_87 &= ( ~ ( 0x333FF8 ) ) ;
V_87 |= 0x111D18 ;
F_4 ( V_87 , V_5 -> V_16 + 0x1200 ) ;
F_23 ( 500 ) ;
V_87 = F_3 ( V_5 -> V_16 + 0x1200 ) ;
V_87 &= ( ~ ( 0x333FF8 ) ) ;
V_87 |= 0x111D18 ;
F_4 ( V_87 , V_5 -> V_16 + 0x1200 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_69 ) ;
V_7 &= ~ ( V_50 | V_64 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_69 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_82 ) ;
V_7 &= ~ ( V_52 | V_86 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_82 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_28 )
{
return 0 ;
}
static int F_25 ( struct V_89 * V_90 )
{
struct V_91 * V_92 = V_90 -> V_30 . V_93 ;
struct V_94 * V_95 = & V_96 ;
struct V_4 * V_5 ;
struct V_97 * V_98 ;
int V_99 ;
V_5 = F_26 ( & V_90 -> V_30 , sizeof( * V_5 ) , V_100 ) ;
if ( ! V_5 ) {
F_27 ( & V_90 -> V_30 , L_4 ) ;
return - V_101 ;
}
F_28 ( & V_90 -> V_30 , V_5 ) ;
V_98 = F_29 ( V_90 , V_102 , 0 ) ;
if ( ! V_98 ) {
F_27 ( & V_90 -> V_30 , L_5 ) ;
return - V_103 ;
}
V_5 -> V_16 = F_30 ( & V_90 -> V_30 , V_98 ) ;
if ( F_9 ( V_5 -> V_16 ) )
return F_31 ( V_5 -> V_16 ) ;
V_5 -> V_104 = F_32 ( V_90 , 0 ) ;
if ( V_5 -> V_104 <= 0 ) {
F_27 ( & V_90 -> V_30 , L_6 ) ;
return - V_103 ;
}
if ( ! V_92 ) {
F_27 ( & V_90 -> V_30 , L_7 ) ;
return - V_15 ;
}
V_5 -> V_105 = V_92 -> V_105 ;
V_5 -> V_106 = F_33 ( & V_90 -> V_30 , NULL ) ;
if ( F_9 ( V_5 -> V_106 ) ) {
F_27 ( & V_90 -> V_30 , L_8 ) ;
return F_31 ( V_5 -> V_106 ) ;
}
V_99 = F_34 ( V_5 -> V_106 ) ;
if ( V_99 < 0 )
return V_99 ;
V_5 -> V_33 = F_35 ( & V_90 -> V_30 , L_9 ) ;
if ( ! F_9 ( V_5 -> V_33 ) ) {
if ( V_5 -> V_33 == V_5 -> V_106 ) {
F_36 ( V_5 -> V_33 ) ;
V_5 -> V_33 = F_37 ( - V_15 ) ;
} else {
F_38 ( & V_90 -> V_30 , L_10 ) ;
F_34 ( V_5 -> V_33 ) ;
V_95 = & V_107 ;
}
}
V_5 -> V_40 = V_55 ;
V_5 -> V_41 = V_56 ;
if ( V_92 -> V_105 == 32 ) {
V_5 -> V_40 |= V_108 ;
V_5 -> V_41 |= V_109 ;
} else {
V_5 -> V_40 |= V_110 ;
V_5 -> V_41 |= V_111 ;
}
V_99 = F_39 ( & V_90 -> V_30 , V_95 ) ;
if ( ! V_99 )
return 0 ;
F_27 ( & V_90 -> V_30 , L_11 ) ;
if ( ! F_9 ( V_5 -> V_33 ) ) {
F_40 ( V_5 -> V_33 ) ;
F_36 ( V_5 -> V_33 ) ;
}
F_40 ( V_5 -> V_106 ) ;
return V_99 ;
}
static int F_41 ( struct V_89 * V_90 )
{
struct V_4 * V_5 = F_42 ( & V_90 -> V_30 ) ;
F_43 ( & V_90 -> V_30 ) ;
if ( ! F_9 ( V_5 -> V_33 ) ) {
F_40 ( V_5 -> V_33 ) ;
F_36 ( V_5 -> V_33 ) ;
}
F_40 ( V_5 -> V_106 ) ;
return 0 ;
}
