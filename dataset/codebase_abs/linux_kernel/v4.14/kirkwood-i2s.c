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
if ( F_8 ( V_5 -> V_30 ) ) {
F_9 ( V_28 -> V_31 , L_1 ,
V_32 , V_20 ) ;
F_5 ( V_5 -> V_16 , V_20 ) ;
V_29 = V_33 ;
} else {
F_9 ( V_28 -> V_31 , L_2 ,
V_32 , V_20 , 256 * V_20 ) ;
F_10 ( V_5 -> V_30 , 256 * V_20 ) ;
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
V_50 |
V_51 ;
V_41 = V_52 |
V_53 |
V_54 ;
break;
case V_55 :
V_43 |= V_56 ;
V_40 = V_57 |
V_50 |
V_51 ;
V_41 = V_58 |
V_53 |
V_54 ;
break;
case V_59 :
V_43 |= V_60 ;
V_40 = V_61 |
V_50 ;
V_41 = V_62 |
V_53 ;
break;
default:
return - V_15 ;
}
if ( V_37 -> V_44 == V_45 ) {
if ( F_16 ( V_39 ) == 1 )
V_40 |= V_63 ;
else
V_40 |= V_64 ;
V_5 -> V_40 &= ~ ( V_65 |
V_66 |
V_67 ) ;
V_5 -> V_40 |= V_40 ;
} else {
V_5 -> V_41 &= ~ ( V_68 |
V_69 ) ;
V_5 -> V_41 |= V_41 ;
}
F_4 ( V_43 , V_5 -> V_16 + V_42 ) ;
return 0 ;
}
static unsigned F_17 ( unsigned V_70 )
{
if ( ! ( V_70 & V_50 ) )
V_70 |= V_71 ;
if ( ! ( V_70 & V_51 ) )
V_70 |= V_72 ;
return V_70 ;
}
static int F_18 ( struct V_36 * V_37 ,
int V_73 , struct V_1 * V_28 )
{
struct V_74 * V_75 = V_37 -> V_75 ;
struct V_4 * V_5 = F_2 ( V_28 ) ;
T_2 V_70 , V_7 ;
V_70 = F_3 ( V_5 -> V_16 + V_76 ) ;
if ( ( V_70 & V_66 ) == 0 ) {
unsigned V_77 = 5000 ;
do {
V_7 = V_70 ;
V_70 = F_3 ( V_5 -> V_16 + V_76 ) ;
if ( ! ( ( V_70 | V_7 ) & V_78 ) )
break;
F_19 ( 1 ) ;
} while ( V_77 -- );
if ( ( V_70 | V_7 ) & V_78 )
F_20 ( V_28 -> V_31 , L_3 ,
V_70 ) ;
}
switch ( V_73 ) {
case V_79 :
V_70 = V_5 -> V_40 ;
if ( V_28 -> V_80 == 0 )
V_70 &= ~ V_51 ;
else
V_70 &= ~ V_50 ;
V_70 = F_17 ( V_70 ) ;
V_7 = V_70 & ~ V_66 ;
F_4 ( V_7 , V_5 -> V_16 + V_76 ) ;
if ( ! V_75 -> V_81 ) {
V_7 = F_3 ( V_5 -> V_16 + V_82 ) ;
V_7 |= V_83 ;
F_4 ( V_7 , V_5 -> V_16 + V_82 ) ;
}
F_4 ( V_70 , V_5 -> V_16 + V_76 ) ;
break;
case V_84 :
V_70 |= V_85 | V_71 |
V_72 ;
F_4 ( V_70 , V_5 -> V_16 + V_76 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_82 ) ;
V_7 &= ~ V_83 ;
F_4 ( V_7 , V_5 -> V_16 + V_82 ) ;
V_70 &= ~ V_66 ;
F_4 ( V_70 , V_5 -> V_16 + V_76 ) ;
break;
case V_86 :
case V_87 :
V_70 |= V_85 | V_71 |
V_72 ;
F_4 ( V_70 , V_5 -> V_16 + V_76 ) ;
break;
case V_88 :
case V_89 :
V_70 &= ~ ( V_85 | V_71 |
V_72 ) ;
V_70 = F_17 ( V_70 ) ;
F_4 ( V_70 , V_5 -> V_16 + V_76 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_21 ( struct V_36 * V_37 ,
int V_73 , struct V_1 * V_28 )
{
struct V_4 * V_5 = F_2 ( V_28 ) ;
T_2 V_70 , V_7 ;
V_7 = F_3 ( V_5 -> V_16 + V_90 ) ;
switch ( V_73 ) {
case V_79 :
V_70 = V_5 -> V_41 ;
if ( V_28 -> V_80 == 0 )
V_70 &= ~ V_54 ;
else
V_70 &= ~ V_53 ;
V_7 = V_70 & ~ V_68 ;
F_4 ( V_7 , V_5 -> V_16 + V_90 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_82 ) ;
V_7 |= V_91 ;
F_4 ( V_7 , V_5 -> V_16 + V_82 ) ;
F_4 ( V_70 , V_5 -> V_16 + V_90 ) ;
break;
case V_84 :
V_7 = F_3 ( V_5 -> V_16 + V_90 ) ;
V_7 |= V_92 | V_93 ;
F_4 ( V_7 , V_5 -> V_16 + V_90 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_82 ) ;
V_7 &= ~ V_91 ;
F_4 ( V_7 , V_5 -> V_16 + V_82 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_90 ) ;
V_7 &= ~ V_68 ;
F_4 ( V_7 , V_5 -> V_16 + V_90 ) ;
break;
case V_86 :
case V_87 :
V_7 = F_3 ( V_5 -> V_16 + V_90 ) ;
V_7 |= V_92 | V_93 ;
F_4 ( V_7 , V_5 -> V_16 + V_90 ) ;
break;
case V_88 :
case V_89 :
V_7 = F_3 ( V_5 -> V_16 + V_90 ) ;
V_7 &= ~ ( V_92 | V_93 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_90 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_22 ( struct V_36 * V_37 , int V_73 ,
struct V_1 * V_28 )
{
if ( V_37 -> V_44 == V_45 )
return F_18 ( V_37 , V_73 , V_28 ) ;
else
return F_21 ( V_37 , V_73 , V_28 ) ;
return 0 ;
}
static int F_23 ( struct V_4 * V_5 )
{
unsigned long V_7 ;
unsigned int V_94 ;
F_4 ( 0xffffffff , V_5 -> V_16 + V_95 ) ;
F_4 ( 0 , V_5 -> V_16 + V_82 ) ;
V_94 = F_3 ( V_5 -> V_16 + 0x1200 ) ;
V_94 &= ( ~ ( 0x333FF8 ) ) ;
V_94 |= 0x111D18 ;
F_4 ( V_94 , V_5 -> V_16 + 0x1200 ) ;
F_24 ( 500 ) ;
V_94 = F_3 ( V_5 -> V_16 + 0x1200 ) ;
V_94 &= ( ~ ( 0x333FF8 ) ) ;
V_94 |= 0x111D18 ;
F_4 ( V_94 , V_5 -> V_16 + 0x1200 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_76 ) ;
V_7 &= ~ V_66 ;
F_4 ( V_7 , V_5 -> V_16 + V_76 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_90 ) ;
V_7 &= ~ V_68 ;
F_4 ( V_7 , V_5 -> V_16 + V_90 ) ;
return 0 ;
}
static int F_25 ( struct V_96 * V_97 )
{
struct V_98 * V_99 = V_97 -> V_31 . V_100 ;
struct V_101 * V_102 = V_103 ;
struct V_4 * V_5 ;
struct V_104 * V_105 ;
struct V_106 * V_107 = V_97 -> V_31 . V_108 ;
int V_109 ;
V_5 = F_26 ( & V_97 -> V_31 , sizeof( * V_5 ) , V_110 ) ;
if ( ! V_5 )
return - V_111 ;
F_27 ( & V_97 -> V_31 , V_5 ) ;
V_105 = F_28 ( V_97 , V_112 , 0 ) ;
V_5 -> V_16 = F_29 ( & V_97 -> V_31 , V_105 ) ;
if ( F_8 ( V_5 -> V_16 ) )
return F_30 ( V_5 -> V_16 ) ;
V_5 -> V_113 = F_31 ( V_97 , 0 ) ;
if ( V_5 -> V_113 < 0 ) {
F_32 ( & V_97 -> V_31 , L_4 , V_5 -> V_113 ) ;
return V_5 -> V_113 ;
}
if ( V_107 ) {
V_5 -> V_114 = 128 ;
} else if ( V_99 ) {
V_5 -> V_114 = V_99 -> V_114 ;
} else {
F_32 ( & V_97 -> V_31 , L_5 ) ;
return - V_15 ;
}
V_5 -> V_115 = F_33 ( & V_97 -> V_31 , V_107 ? L_6 : NULL ) ;
if ( F_8 ( V_5 -> V_115 ) ) {
F_32 ( & V_97 -> V_31 , L_7 ) ;
return F_30 ( V_5 -> V_115 ) ;
}
V_109 = F_34 ( V_5 -> V_115 ) ;
if ( V_109 < 0 )
return V_109 ;
V_5 -> V_30 = F_33 ( & V_97 -> V_31 , L_8 ) ;
if ( F_8 ( V_5 -> V_30 ) ) {
if ( F_30 ( V_5 -> V_30 ) == - V_116 )
return - V_116 ;
} else {
if ( F_35 ( V_5 -> V_30 , V_5 -> V_115 ) ) {
F_36 ( & V_97 -> V_31 , V_5 -> V_30 ) ;
V_5 -> V_30 = F_37 ( - V_15 ) ;
} else {
F_38 ( & V_97 -> V_31 , L_9 ) ;
F_34 ( V_5 -> V_30 ) ;
V_102 = V_117 ;
}
}
V_5 -> V_40 = V_57 ;
V_5 -> V_41 = V_58 ;
if ( V_5 -> V_114 == 32 ) {
V_5 -> V_40 |= V_118 ;
V_5 -> V_41 |= V_119 ;
} else {
V_5 -> V_40 |= V_120 ;
V_5 -> V_41 |= V_121 ;
}
V_109 = F_39 ( & V_97 -> V_31 , & V_122 ,
V_102 , 2 ) ;
if ( V_109 ) {
F_32 ( & V_97 -> V_31 , L_10 ) ;
goto V_123;
}
V_109 = F_40 ( & V_97 -> V_31 , & V_124 ) ;
if ( V_109 ) {
F_32 ( & V_97 -> V_31 , L_11 ) ;
goto V_125;
}
F_23 ( V_5 ) ;
return 0 ;
V_125:
F_41 ( & V_97 -> V_31 ) ;
V_123:
if ( ! F_8 ( V_5 -> V_30 ) )
F_42 ( V_5 -> V_30 ) ;
F_42 ( V_5 -> V_115 ) ;
return V_109 ;
}
static int F_43 ( struct V_96 * V_97 )
{
struct V_4 * V_5 = F_44 ( & V_97 -> V_31 ) ;
F_45 ( & V_97 -> V_31 ) ;
F_41 ( & V_97 -> V_31 ) ;
if ( ! F_8 ( V_5 -> V_30 ) )
F_42 ( V_5 -> V_30 ) ;
F_42 ( V_5 -> V_115 ) ;
return 0 ;
}
