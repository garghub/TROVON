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
static int F_7 ( struct V_28 * V_29 ,
struct V_1 * V_30 )
{
struct V_4 * V_5 = F_2 ( V_30 ) ;
F_8 ( V_30 , V_29 , V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_28 * V_29 ,
struct V_31 * V_32 ,
struct V_1 * V_30 )
{
struct V_4 * V_5 = F_2 ( V_30 ) ;
unsigned int V_33 , V_34 ;
unsigned long V_35 , V_7 ;
if ( V_29 -> V_36 == V_37 ) {
V_33 = V_17 ;
V_34 = V_38 ;
} else {
V_33 = V_19 ;
V_34 = V_39 ;
}
F_5 ( V_5 -> V_16 , F_10 ( V_32 ) ) ;
V_35 = F_3 ( V_5 -> V_16 + V_33 ) ;
V_35 &= ~ V_40 ;
V_7 = F_3 ( V_5 -> V_16 + V_34 ) ;
V_7 &= ~ V_41 ;
switch ( F_11 ( V_32 ) ) {
case V_42 :
V_35 |= V_43 ;
V_7 |= V_44 ;
break;
case V_45 :
V_35 |= V_46 ;
V_7 |= V_47 ;
break;
case V_48 :
V_35 |= V_49 ;
V_7 |= V_50 ;
break;
default:
return - V_15 ;
}
if ( V_29 -> V_36 == V_37 ) {
V_7 &= ~ V_51 ;
if ( F_12 ( V_32 ) == 1 )
V_7 |= V_52 ;
else
V_7 |= V_53 ;
}
F_4 ( V_35 , V_5 -> V_16 + V_33 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_34 ) ;
return 0 ;
}
static int F_13 ( struct V_28 * V_29 ,
int V_54 , struct V_1 * V_30 )
{
struct V_4 * V_5 = F_2 ( V_30 ) ;
T_2 V_55 , V_7 ;
V_55 = F_3 ( V_5 -> V_16 + V_38 ) ;
if ( V_55 & V_56 ) {
unsigned V_57 = 5000 ;
do {
V_7 = V_55 ;
V_55 = F_3 ( V_5 -> V_16 + V_38 ) ;
if ( ! ( ( V_55 | V_7 ) & V_58 ) )
break;
F_14 ( 1 ) ;
} while ( V_57 -- );
if ( ( V_55 | V_7 ) & V_58 )
F_15 ( V_30 -> V_59 , L_1 ,
V_55 ) ;
}
switch ( V_54 ) {
case V_60 :
V_7 = F_3 ( V_5 -> V_16 + V_61 ) ;
V_7 |= V_62 ;
F_4 ( V_7 , V_5 -> V_16 + V_61 ) ;
V_55 &= ~ V_63 ;
V_55 &= ~ ( V_56 | V_64
| V_65 ) ;
if ( V_5 -> V_66 == 32 )
V_55 |= V_67 ;
else
V_55 |= V_68 ;
V_55 |= V_69 ;
F_4 ( V_55 , V_5 -> V_16 + V_38 ) ;
break;
case V_70 :
V_55 |= V_56 | V_64 ;
F_4 ( V_55 , V_5 -> V_16 + V_38 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_61 ) ;
V_7 &= ~ V_62 ;
F_4 ( V_7 , V_5 -> V_16 + V_61 ) ;
V_55 &= ~ ( V_69 | V_65 ) ;
F_4 ( V_55 , V_5 -> V_16 + V_38 ) ;
break;
case V_71 :
case V_72 :
V_55 |= V_56 | V_64 ;
F_4 ( V_55 , V_5 -> V_16 + V_38 ) ;
break;
case V_73 :
case V_74 :
V_55 &= ~ ( V_56 | V_64 ) ;
F_4 ( V_55 , V_5 -> V_16 + V_38 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_16 ( struct V_28 * V_29 ,
int V_54 , struct V_1 * V_30 )
{
struct V_4 * V_5 = F_2 ( V_30 ) ;
unsigned long V_7 ;
V_7 = F_3 ( V_5 -> V_16 + V_39 ) ;
switch ( V_54 ) {
case V_60 :
V_7 = F_3 ( V_5 -> V_16 + V_61 ) ;
V_7 |= V_75 ;
F_4 ( V_7 , V_5 -> V_16 + V_61 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_39 ) ;
V_7 &= ~ V_76 ;
V_7 &= ~ V_77 ;
V_7 &= ~ ( V_78 | V_79
| V_80 ) ;
if ( V_5 -> V_66 == 32 )
V_7 |= V_81 ;
else
V_7 |= V_82 ;
V_7 |= V_83 ;
F_4 ( V_7 , V_5 -> V_16 + V_39 ) ;
break;
case V_70 :
V_7 = F_3 ( V_5 -> V_16 + V_39 ) ;
V_7 |= V_78 | V_79 ;
F_4 ( V_7 , V_5 -> V_16 + V_39 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_61 ) ;
V_7 &= ~ V_75 ;
F_4 ( V_7 , V_5 -> V_16 + V_61 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_39 ) ;
V_7 &= ~ ( V_83 | V_80 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_39 ) ;
break;
case V_71 :
case V_72 :
V_7 = F_3 ( V_5 -> V_16 + V_39 ) ;
V_7 |= V_78 | V_79 ;
F_4 ( V_7 , V_5 -> V_16 + V_39 ) ;
break;
case V_73 :
case V_74 :
V_7 = F_3 ( V_5 -> V_16 + V_39 ) ;
V_7 &= ~ ( V_78 | V_79 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_39 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_17 ( struct V_28 * V_29 , int V_54 ,
struct V_1 * V_30 )
{
if ( V_29 -> V_36 == V_37 )
return F_13 ( V_29 , V_54 , V_30 ) ;
else
return F_16 ( V_29 , V_54 , V_30 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_30 )
{
struct V_4 * V_5 = F_2 ( V_30 ) ;
unsigned long V_7 ;
unsigned int V_84 ;
F_4 ( 0xffffffff , V_5 -> V_16 + V_85 ) ;
F_4 ( 0 , V_5 -> V_16 + V_61 ) ;
V_84 = F_3 ( V_5 -> V_16 + 0x1200 ) ;
V_84 &= ( ~ ( 0x333FF8 ) ) ;
V_84 |= 0x111D18 ;
F_4 ( V_84 , V_5 -> V_16 + 0x1200 ) ;
F_19 ( 500 ) ;
V_84 = F_3 ( V_5 -> V_16 + 0x1200 ) ;
V_84 &= ( ~ ( 0x333FF8 ) ) ;
V_84 |= 0x111D18 ;
F_4 ( V_84 , V_5 -> V_16 + 0x1200 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_38 ) ;
V_7 &= ~ ( V_69 | V_65 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_38 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_39 ) ;
V_7 &= ~ ( V_83 | V_80 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_39 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_30 )
{
return 0 ;
}
static T_3 int F_21 ( struct V_86 * V_87 )
{
struct V_88 * V_89 ;
struct V_90 * V_91 =
V_87 -> V_59 . V_92 ;
struct V_4 * V_5 ;
int V_93 ;
V_5 = F_22 ( sizeof( struct V_4 ) , V_94 ) ;
if ( ! V_5 ) {
F_23 ( & V_87 -> V_59 , L_2 ) ;
V_93 = - V_95 ;
goto error;
}
F_24 ( & V_87 -> V_59 , V_5 ) ;
V_89 = F_25 ( V_87 , V_96 , 0 ) ;
if ( ! V_89 ) {
F_23 ( & V_87 -> V_59 , L_3 ) ;
V_93 = - V_97 ;
goto V_98;
}
V_5 -> V_89 = F_26 ( V_89 -> V_99 , V_100 , V_101 ) ;
if ( ! V_5 -> V_89 ) {
F_23 ( & V_87 -> V_59 , L_4 ) ;
V_93 = - V_102 ;
goto V_98;
}
V_5 -> V_16 = F_27 ( V_5 -> V_89 -> V_99 , V_100 ) ;
if ( ! V_5 -> V_16 ) {
F_23 ( & V_87 -> V_59 , L_5 ) ;
V_93 = - V_95 ;
goto V_103;
}
V_5 -> V_104 = F_28 ( V_87 , 0 ) ;
if ( V_5 -> V_104 <= 0 ) {
F_23 ( & V_87 -> V_59 , L_6 ) ;
V_93 = - V_97 ;
goto V_105;
}
if ( ! V_91 ) {
F_23 ( & V_87 -> V_59 , L_7 ) ;
V_93 = - V_15 ;
goto V_105;
}
V_5 -> V_66 = V_91 -> V_66 ;
V_5 -> V_106 = F_29 ( & V_87 -> V_59 , NULL ) ;
if ( F_30 ( V_5 -> V_106 ) ) {
F_23 ( & V_87 -> V_59 , L_8 ) ;
V_93 = F_31 ( V_5 -> V_106 ) ;
goto V_105;
}
F_32 ( V_5 -> V_106 ) ;
V_93 = F_33 ( & V_87 -> V_59 , & V_107 ) ;
if ( ! V_93 )
return 0 ;
F_23 ( & V_87 -> V_59 , L_9 ) ;
F_34 ( V_5 -> V_106 ) ;
F_35 ( V_5 -> V_106 ) ;
V_105:
F_36 ( V_5 -> V_16 ) ;
V_103:
F_37 ( V_5 -> V_89 -> V_99 , V_100 ) ;
V_98:
F_38 ( V_5 ) ;
error:
return V_93 ;
}
static T_4 int F_39 ( struct V_86 * V_87 )
{
struct V_4 * V_5 = F_40 ( & V_87 -> V_59 ) ;
F_41 ( & V_87 -> V_59 ) ;
F_34 ( V_5 -> V_106 ) ;
F_35 ( V_5 -> V_106 ) ;
F_36 ( V_5 -> V_16 ) ;
F_37 ( V_5 -> V_89 -> V_99 , V_100 ) ;
F_38 ( V_5 ) ;
return 0 ;
}
