static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
V_3 &= ~ V_5 ;
V_3 |= V_6 ;
F_3 ( V_2 , V_4 , V_3 ) ;
V_3 = F_4 ( V_2 , V_7 ) ;
V_3 &= ~ V_8 ;
F_5 ( V_2 , V_7 , V_3 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_9 != V_10 ) &&
( V_2 -> V_9 != V_11 ) ) {
F_5 ( V_2 , 0x03 , 0 ) ;
}
if ( ( V_2 -> V_9 != V_10 ) &&
( V_2 -> V_9 != V_12 ) ) {
T_1 V_13 ;
V_13 = F_2 ( V_2 ,
V_4 ) ;
V_13 &= ~ V_5 ;
V_13 &= ~ V_14 ;
F_3 ( V_2 , V_4 ,
V_6 | V_13 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_15 , V_3 ;
V_3 = F_8 ( V_2 , V_16 ) ;
V_3 &= ~ V_17 ;
V_15 = F_9 ( V_2 , V_16 ,
V_3 ) ;
if ( V_15 < 0 )
return V_15 ;
V_3 = F_2 ( V_2 , V_4 ) ;
V_3 &= ~ V_5 ;
V_3 |= V_6 ;
V_15 = F_3 ( V_2 , V_4 ,
V_3 ) ;
if ( V_15 < 0 )
return V_15 ;
V_3 = F_4 ( V_2 , V_7 ) ;
V_3 &= ~ V_8 ;
V_15 = F_5 ( V_2 , V_7 , V_3 ) ;
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_9 ( V_2 , V_19 ,
V_20 |
V_21 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_9 ( V_2 , V_22 ,
V_23 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_9 ( V_2 , V_24 ,
V_25 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_9 ( V_2 , V_26 ,
V_27 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_9 ( V_2 , V_28 ,
V_29 ) ;
return V_18 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_18 , V_30 ;
V_18 = F_3 ( V_2 ,
V_31 ,
V_32 |
V_33 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( F_12 ( V_2 ) == V_34 ||
F_12 ( V_2 ) == V_35 ) {
V_18 = F_9 ( V_2 , V_36 ,
V_37 ) ;
if ( V_18 < 0 )
goto error;
if ( V_2 -> V_38 -> V_39 == V_34 ) {
V_18 = F_10 ( V_2 ) ;
if ( V_18 < 0 )
goto error;
}
}
if ( F_12 ( V_2 ) == V_40 ) {
int V_3 ;
V_3 = F_8 ( V_2 , V_24 ) ;
if ( V_3 < 0 )
goto error;
V_3 |= V_41 ;
V_18 = F_9 ( V_2 , V_24 , V_3 ) ;
}
error:
V_30 = F_3 ( V_2 ,
V_31 ,
V_33 ) ;
return V_18 ? V_18 : V_30 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_2 V_42 ;
int V_3 ;
bool V_43 = true ;
if ( F_12 ( V_2 ) != V_40 &&
F_12 ( V_2 ) != V_34 &&
F_12 ( V_2 ) != V_35 )
return;
V_3 = F_4 ( V_2 , V_44 ) ;
if ( V_3 < 0 )
return;
V_42 = V_3 ;
if ( ( F_12 ( V_2 ) == V_34 ||
F_12 ( V_2 ) == V_35 ) &&
F_14 ( V_2 ) >= 0x3 ) {
V_43 = false ;
} else {
if ( V_2 -> V_45 & V_46 ) {
V_3 &= ~ V_47 ;
V_43 = false ;
}
}
if ( ! V_43 || ( V_2 -> V_45 & V_48 ) )
V_3 &= ~ V_49 ;
else
V_3 |= V_49 ;
if ( V_2 -> V_45 & V_50 )
V_3 |= V_51 ;
if ( V_42 != V_3 )
F_5 ( V_2 , V_44 , V_3 ) ;
V_3 = F_4 ( V_2 , V_52 ) ;
if ( V_3 < 0 )
return;
V_42 = V_3 ;
if ( ! V_43 || ( V_2 -> V_45 & V_48 ) )
V_3 |= V_53 ;
else
V_3 &= ~ V_53 ;
if ( V_42 != V_3 )
F_5 ( V_2 , V_52 , V_3 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_13 , V_18 ;
V_13 = F_16 ( V_2 , V_54 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 |= V_55 ;
V_18 = F_17 ( V_2 , V_54 , V_13 ) ;
if ( V_18 < 0 )
return V_18 ;
V_13 = ~ ( V_56 |
V_57 |
V_58 ) ;
V_18 = F_17 ( V_2 , V_59 , V_13 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( ( F_12 ( V_2 ) == V_34 ||
F_12 ( V_2 ) == V_35 ) &&
( V_2 -> V_45 & V_60 ) )
F_5 ( V_2 , V_61 , 0 ) ;
if ( ( V_2 -> V_45 & V_46 ) ||
( V_2 -> V_45 & V_50 ) ||
( V_2 -> V_45 & V_48 ) )
F_13 ( V_2 ) ;
if ( F_12 ( V_2 ) == V_62 ) {
V_18 = F_1 ( V_2 ) ;
if ( V_18 )
return V_18 ;
} else if ( F_12 ( V_2 ) == V_63 ) {
V_18 = F_6 ( V_2 ) ;
if ( V_18 )
return V_18 ;
} else if ( F_12 ( V_2 ) == V_64 ) {
V_18 = F_7 ( V_2 ) ;
if ( V_18 )
return V_18 ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_18 , V_13 ;
V_18 = F_15 ( V_2 ) ;
if ( V_2 -> V_45 & V_65 ) {
V_13 = F_4 ( V_2 , V_66 ) ;
F_5 ( V_2 , V_66 ,
V_13 |
V_67 |
V_68 ) ;
V_13 = V_69 | V_70 ;
V_18 = F_8 ( V_2 , V_13 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_9 ( V_2 , V_13 , V_18 |
V_71 |
V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
V_13 = V_73 | V_70 ;
V_18 = F_8 ( V_2 , V_13 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_9 ( V_2 , V_13 ,
V_18 & ~ V_74 ) ;
if ( V_18 < 0 )
return V_18 ;
V_13 = F_4 ( V_2 , V_75 ) ;
F_5 ( V_2 , V_75 ,
V_13 | V_76 ) ;
F_5 ( V_2 , V_77 ,
F_19 ( V_78 ) |
F_20 ( V_79 ) ) ;
V_2 -> V_80 = V_81 ;
V_2 -> V_82 = V_83 ;
V_2 -> V_84 = V_85 ;
}
return V_18 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_22 ( V_2 ) ;
if ( V_2 -> V_45 & V_65 ) {
if ( V_2 -> V_86 ) {
V_2 -> V_82 = V_83 ;
V_2 -> V_84 = V_85 ;
}
}
return V_18 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_87 * V_88 = V_2 -> V_89 . V_90 . V_91 ;
int V_92 ;
V_92 = F_24 ( V_2 ) ;
if ( V_2 -> V_9 == V_12 ) {
T_1 V_13 ;
V_13 = 0x7 | ( 0x7 << 12 ) ;
F_17 ( V_2 , 0x18 , V_13 ) ;
V_13 = F_16 ( V_2 , 0x18 ) ;
V_13 |= ( 1 << 8 ) ;
V_13 |= ( 1 << 15 ) ;
F_17 ( V_2 , 0x18 , V_13 ) ;
}
if ( F_25 ( V_88 , L_1 ) ) {
V_92 = F_9 ( V_2 , V_93 + 0x9 ,
0x11B ) ;
if ( V_92 < 0 )
return V_92 ;
}
return V_92 ;
}
static int F_26 ( struct V_1 * V_2 , int V_13 , int V_94 )
{
int V_3 ;
V_3 = F_16 ( V_2 , V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_17 ( V_2 , V_13 , V_3 | V_94 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_13 , V_18 , V_30 , V_95 ;
V_18 = F_17 ( V_2 , V_96 , V_97 ) ;
if ( V_18 < 0 )
return V_18 ;
V_13 = F_16 ( V_2 , V_98 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = V_99 |
V_100 |
V_101 |
V_102 |
V_103 ;
V_18 = F_17 ( V_2 , V_98 , V_13 ) ;
if ( V_18 < 0 )
return V_18 ;
V_95 = F_16 ( V_2 , V_104 ) ;
if ( V_95 < 0 )
return V_95 ;
V_13 = V_95 | V_105 ;
V_18 = F_17 ( V_2 , V_104 , V_13 ) ;
if ( V_18 < 0 )
return V_18 ;
V_13 = F_16 ( V_2 , V_106 ) ;
if ( V_13 < 0 ) {
V_18 = V_13 ;
goto V_107;
}
V_13 &= ~ V_108 ;
V_13 |= V_109 ;
V_18 = F_17 ( V_2 , V_106 , V_13 ) ;
if ( V_18 < 0 )
goto V_107;
V_18 = F_26 ( V_2 , V_110 ,
V_111 ) ;
if ( V_18 < 0 )
goto V_107;
if ( V_2 -> V_45 & V_48 ) {
V_18 = F_26 ( V_2 , V_112 ,
V_113 ) ;
}
V_107:
V_30 = F_17 ( V_2 , V_104 , V_95 ) ;
if ( ! V_18 )
V_18 = V_30 ;
return V_18 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_16 ( V_2 , V_98 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_13 , V_18 ;
V_13 = F_16 ( V_2 , V_98 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_2 -> V_114 == V_115 )
V_13 &= ~ V_103 ;
else
V_13 |= V_103 ;
V_18 = F_17 ( V_2 , V_98 , V_13 ) ;
return V_18 ;
}
