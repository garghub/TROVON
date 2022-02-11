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
V_7 &= V_26 ;
} while ( V_7 == 0 );
}
static int F_7 ( struct V_27 * V_28 ,
struct V_1 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 ) ;
F_8 ( V_29 , V_28 , V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_27 * V_28 ,
struct V_30 * V_31 ,
struct V_1 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 ) ;
unsigned int V_32 , V_33 ;
unsigned long V_34 , V_7 ;
if ( V_28 -> V_35 == V_36 ) {
V_32 = V_17 ;
V_33 = V_37 ;
} else {
V_32 = V_19 ;
V_33 = V_38 ;
}
F_5 ( V_5 -> V_16 , F_10 ( V_31 ) ) ;
V_34 = F_3 ( V_5 -> V_16 + V_32 ) ;
V_34 &= ~ V_39 ;
V_7 = F_3 ( V_5 -> V_16 + V_33 ) ;
V_7 &= ~ V_40 ;
switch ( F_11 ( V_31 ) ) {
case V_41 :
V_34 |= V_42 ;
V_7 |= V_43 ;
break;
case V_44 :
V_34 |= V_45 ;
V_7 |= V_46 ;
break;
case V_47 :
V_34 |= V_48 ;
V_7 |= V_49 ;
break;
default:
return - V_15 ;
}
if ( V_28 -> V_35 == V_36 ) {
V_7 &= ~ V_50 ;
if ( F_12 ( V_31 ) == 1 )
V_7 |= V_51 ;
else
V_7 |= V_52 ;
}
F_4 ( V_34 , V_5 -> V_16 + V_32 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_33 ) ;
return 0 ;
}
static int F_13 ( struct V_27 * V_28 ,
int V_53 , struct V_1 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 ) ;
unsigned long V_7 ;
V_7 = F_3 ( V_5 -> V_16 + V_37 ) ;
switch ( V_53 ) {
case V_54 :
V_7 = F_3 ( V_5 -> V_16 + V_37 ) ;
V_7 |= V_55 ;
F_4 ( V_7 , V_5 -> V_16 + V_37 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_56 ) ;
V_7 |= V_57 ;
F_4 ( V_7 , V_5 -> V_16 + V_56 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_37 ) ;
V_7 &= ~ V_58 ;
V_7 &= ~ ( V_55 | V_59
| V_60 ) ;
if ( V_5 -> V_61 == 32 )
V_7 |= V_62 ;
else
V_7 |= V_63 ;
V_7 |= V_64 ;
F_4 ( V_7 , V_5 -> V_16 + V_37 ) ;
break;
case V_65 :
V_7 = F_3 ( V_5 -> V_16 + V_37 ) ;
V_7 |= V_55 | V_59 ;
F_4 ( V_7 , V_5 -> V_16 + V_37 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_56 ) ;
V_7 &= ~ V_57 ;
F_4 ( V_7 , V_5 -> V_16 + V_56 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_37 ) ;
V_7 &= ~ ( V_64 | V_60 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_37 ) ;
break;
case V_66 :
case V_67 :
V_7 = F_3 ( V_5 -> V_16 + V_37 ) ;
V_7 |= V_55 | V_59 ;
F_4 ( V_7 , V_5 -> V_16 + V_37 ) ;
break;
case V_68 :
case V_69 :
V_7 = F_3 ( V_5 -> V_16 + V_37 ) ;
V_7 &= ~ ( V_55 | V_59 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_37 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_14 ( struct V_27 * V_28 ,
int V_53 , struct V_1 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 ) ;
unsigned long V_7 ;
V_7 = F_3 ( V_5 -> V_16 + V_38 ) ;
switch ( V_53 ) {
case V_54 :
V_7 = F_3 ( V_5 -> V_16 + V_38 ) ;
V_7 |= V_70 ;
F_4 ( V_7 , V_5 -> V_16 + V_38 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_56 ) ;
V_7 |= V_71 ;
F_4 ( V_7 , V_5 -> V_16 + V_56 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_38 ) ;
V_7 &= ~ V_72 ;
V_7 &= ~ V_73 ;
V_7 &= ~ ( V_70 | V_74
| V_75 ) ;
if ( V_5 -> V_61 == 32 )
V_7 |= V_76 ;
else
V_7 |= V_77 ;
V_7 |= V_78 ;
F_4 ( V_7 , V_5 -> V_16 + V_38 ) ;
break;
case V_65 :
V_7 = F_3 ( V_5 -> V_16 + V_38 ) ;
V_7 |= V_70 | V_74 ;
F_4 ( V_7 , V_5 -> V_16 + V_38 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_56 ) ;
V_7 &= ~ V_71 ;
F_4 ( V_7 , V_5 -> V_16 + V_56 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_38 ) ;
V_7 &= ~ ( V_78 | V_75 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_38 ) ;
break;
case V_66 :
case V_67 :
V_7 = F_3 ( V_5 -> V_16 + V_38 ) ;
V_7 |= V_70 | V_74 ;
F_4 ( V_7 , V_5 -> V_16 + V_38 ) ;
break;
case V_68 :
case V_69 :
V_7 = F_3 ( V_5 -> V_16 + V_38 ) ;
V_7 &= ~ ( V_70 | V_74 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_38 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_15 ( struct V_27 * V_28 , int V_53 ,
struct V_1 * V_29 )
{
if ( V_28 -> V_35 == V_36 )
return F_13 ( V_28 , V_53 , V_29 ) ;
else
return F_14 ( V_28 , V_53 , V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 ) ;
unsigned long V_7 ;
unsigned int V_79 ;
F_4 ( 0xffffffff , V_5 -> V_16 + V_80 ) ;
F_4 ( 0 , V_5 -> V_16 + V_56 ) ;
V_79 = F_3 ( V_5 -> V_16 + 0x1200 ) ;
V_79 &= ( ~ ( 0x333FF8 ) ) ;
V_79 |= 0x111D18 ;
F_4 ( V_79 , V_5 -> V_16 + 0x1200 ) ;
F_17 ( 500 ) ;
V_79 = F_3 ( V_5 -> V_16 + 0x1200 ) ;
V_79 &= ( ~ ( 0x333FF8 ) ) ;
V_79 |= 0x111D18 ;
F_4 ( V_79 , V_5 -> V_16 + 0x1200 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_37 ) ;
V_7 &= ~ ( V_64 | V_60 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_37 ) ;
V_7 = F_3 ( V_5 -> V_16 + V_38 ) ;
V_7 &= ~ ( V_78 | V_75 ) ;
F_4 ( V_7 , V_5 -> V_16 + V_38 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_29 )
{
return 0 ;
}
static T_2 int F_19 ( struct V_81 * V_82 )
{
struct V_83 * V_84 ;
struct V_85 * V_86 =
V_82 -> V_87 . V_88 ;
struct V_4 * V_5 ;
int V_89 ;
V_5 = F_20 ( sizeof( struct V_4 ) , V_90 ) ;
if ( ! V_5 ) {
F_21 ( & V_82 -> V_87 , L_1 ) ;
V_89 = - V_91 ;
goto error;
}
F_22 ( & V_82 -> V_87 , V_5 ) ;
V_84 = F_23 ( V_82 , V_92 , 0 ) ;
if ( ! V_84 ) {
F_21 ( & V_82 -> V_87 , L_2 ) ;
V_89 = - V_93 ;
goto V_94;
}
V_5 -> V_84 = F_24 ( V_84 -> V_95 , V_96 , V_97 ) ;
if ( ! V_5 -> V_84 ) {
F_21 ( & V_82 -> V_87 , L_3 ) ;
V_89 = - V_98 ;
goto V_94;
}
V_5 -> V_16 = F_25 ( V_5 -> V_84 -> V_95 , V_96 ) ;
if ( ! V_5 -> V_16 ) {
F_21 ( & V_82 -> V_87 , L_4 ) ;
V_89 = - V_91 ;
goto V_99;
}
V_5 -> V_100 = F_26 ( V_82 , 0 ) ;
if ( V_5 -> V_100 <= 0 ) {
F_21 ( & V_82 -> V_87 , L_5 ) ;
V_89 = - V_93 ;
goto V_101;
}
if ( ! V_86 ) {
F_21 ( & V_82 -> V_87 , L_6 ) ;
V_89 = - V_15 ;
goto V_101;
}
V_5 -> V_61 = V_86 -> V_61 ;
V_5 -> V_102 = F_27 ( & V_82 -> V_87 , NULL ) ;
if ( F_28 ( V_5 -> V_102 ) ) {
F_21 ( & V_82 -> V_87 , L_7 ) ;
V_89 = F_29 ( V_5 -> V_102 ) ;
goto V_101;
}
F_30 ( V_5 -> V_102 ) ;
V_89 = F_31 ( & V_82 -> V_87 , & V_103 ) ;
if ( ! V_89 )
return 0 ;
F_21 ( & V_82 -> V_87 , L_8 ) ;
F_32 ( V_5 -> V_102 ) ;
F_33 ( V_5 -> V_102 ) ;
V_101:
F_34 ( V_5 -> V_16 ) ;
V_99:
F_35 ( V_5 -> V_84 -> V_95 , V_96 ) ;
V_94:
F_36 ( V_5 ) ;
error:
return V_89 ;
}
static T_3 int F_37 ( struct V_81 * V_82 )
{
struct V_4 * V_5 = F_38 ( & V_82 -> V_87 ) ;
F_39 ( & V_82 -> V_87 ) ;
F_32 ( V_5 -> V_102 ) ;
F_33 ( V_5 -> V_102 ) ;
F_34 ( V_5 -> V_16 ) ;
F_35 ( V_5 -> V_84 -> V_95 , V_96 ) ;
F_36 ( V_5 ) ;
return 0 ;
}
