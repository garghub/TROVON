static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 &= ~ V_6 ;
V_3 = F_3 ( V_2 , V_5 ,
V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 = F_4 ( V_2 , V_7 ) ;
V_4 &= ~ V_8 ;
V_4 |= V_9 ;
V_3 = F_5 ( V_2 , V_7 ,
V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 = F_6 ( V_2 , V_10 ) ;
V_4 &= ~ V_11 ;
V_3 = F_7 ( V_2 , V_10 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_3 ( V_2 , V_13 ,
V_14 |
V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_2 , V_16 ,
V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_2 , V_18 ,
V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_2 , V_20 ,
V_21 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_2 , V_22 ,
V_23 ) ;
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_12 , V_24 ;
V_12 = F_5 ( V_2 ,
V_25 ,
V_26 |
V_27 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_10 ( V_2 ) == V_28 ||
F_10 ( V_2 ) == V_29 ) {
V_12 = F_3 ( V_2 , V_30 ,
V_31 ) ;
if ( V_12 < 0 )
goto error;
if ( V_2 -> V_32 -> V_33 == V_28 ) {
V_12 = F_8 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
}
}
if ( F_10 ( V_2 ) == V_34 ) {
int V_4 ;
V_4 = F_2 ( V_2 , V_18 ) ;
if ( V_4 < 0 )
goto error;
V_4 |= V_35 ;
V_12 = F_3 ( V_2 , V_18 , V_4 ) ;
}
error:
V_24 = F_5 ( V_2 ,
V_25 ,
V_27 ) ;
return V_12 ? V_12 : V_24 ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_36 ;
int V_4 ;
bool V_37 = true ;
if ( F_10 ( V_2 ) != V_34 &&
F_10 ( V_2 ) != V_28 &&
F_10 ( V_2 ) != V_29 )
return;
V_4 = F_6 ( V_2 , V_38 ) ;
if ( V_4 < 0 )
return;
V_36 = V_4 ;
if ( ( F_10 ( V_2 ) == V_28 ||
F_10 ( V_2 ) == V_29 ) &&
F_12 ( V_2 ) >= 0x3 ) {
V_37 = false ;
} else {
if ( V_2 -> V_39 & V_40 ) {
V_4 &= ~ V_41 ;
V_37 = false ;
}
}
if ( ! V_37 || ( V_2 -> V_39 & V_42 ) )
V_4 &= ~ V_43 ;
else
V_4 |= V_43 ;
if ( V_2 -> V_39 & V_44 )
V_4 |= V_45 ;
if ( V_36 != V_4 )
F_7 ( V_2 , V_38 , V_4 ) ;
V_4 = F_6 ( V_2 , V_46 ) ;
if ( V_4 < 0 )
return;
V_36 = V_4 ;
if ( ! V_37 || ( V_2 -> V_39 & V_42 ) )
V_4 |= V_47 ;
else
V_4 &= ~ V_47 ;
if ( V_36 != V_4 )
F_7 ( V_2 , V_46 , V_4 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_48 , V_12 ;
V_48 = F_14 ( V_2 , V_49 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 |= V_50 ;
V_12 = F_15 ( V_2 , V_49 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
V_48 = ~ ( V_51 |
V_52 |
V_53 ) ;
V_12 = F_15 ( V_2 , V_54 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ( F_10 ( V_2 ) == V_28 ||
F_10 ( V_2 ) == V_29 ) &&
( V_2 -> V_39 & V_55 ) )
F_7 ( V_2 , V_56 , 0 ) ;
if ( ( V_2 -> V_39 & V_40 ) ||
( V_2 -> V_39 & V_44 ) ||
( V_2 -> V_39 & V_42 ) )
F_11 ( V_2 ) ;
if ( F_10 ( V_2 ) == V_57 ) {
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
F_9 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_12 , V_48 ;
V_12 = F_13 ( V_2 ) ;
if ( V_2 -> V_39 & V_58 ) {
V_48 = F_6 ( V_2 , V_59 ) ;
F_7 ( V_2 , V_59 ,
V_48 |
V_60 |
V_61 ) ;
V_48 = V_62 | V_63 ;
V_12 = F_2 ( V_2 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_2 , V_48 , V_12 |
V_64 |
V_65 ) ;
if ( V_12 < 0 )
return V_12 ;
V_48 = V_66 | V_63 ;
V_12 = F_2 ( V_2 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_2 , V_48 ,
V_12 & ~ V_67 ) ;
if ( V_12 < 0 )
return V_12 ;
V_48 = F_6 ( V_2 , V_68 ) ;
F_7 ( V_2 , V_68 ,
V_48 | V_69 ) ;
F_7 ( V_2 , V_70 ,
F_17 ( V_71 ) |
F_18 ( V_72 ) ) ;
V_2 -> V_73 = V_74 ;
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = V_78 ;
}
return V_12 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_20 ( V_2 ) ;
if ( V_2 -> V_39 & V_58 ) {
if ( V_2 -> V_79 ) {
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = V_78 ;
}
}
return V_12 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = V_2 -> V_82 . V_83 . V_84 ;
int V_85 ;
V_85 = F_22 ( V_2 ) ;
if ( V_2 -> V_86 == V_87 ) {
T_2 V_48 ;
V_48 = 0x7 | ( 0x7 << 12 ) ;
F_15 ( V_2 , 0x18 , V_48 ) ;
V_48 = F_14 ( V_2 , 0x18 ) ;
V_48 |= ( 1 << 8 ) ;
V_48 |= ( 1 << 15 ) ;
F_15 ( V_2 , 0x18 , V_48 ) ;
}
if ( F_23 ( V_81 , L_1 ) ) {
V_85 = F_3 ( V_2 , V_88 + 0x9 ,
0x11B ) ;
if ( V_85 < 0 )
return V_85 ;
}
return V_85 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_85 ;
V_85 = F_22 ( V_2 ) ;
if ( ( V_2 -> V_86 != V_89 ) &&
( V_2 -> V_86 != V_90 ) ) {
F_7 ( V_2 , 0x03 , 0 ) ;
}
if ( ( V_2 -> V_86 != V_89 ) &&
( V_2 -> V_86 != V_87 ) ) {
T_2 V_48 ;
F_5 ( V_2 , V_7 ,
V_91 ) ;
V_48 = F_14 ( V_2 , V_92 ) ;
V_48 &= ~ V_93 ;
V_48 &= ~ V_94 ;
F_5 ( V_2 , V_7 ,
V_9 | V_48 ) ;
}
return V_85 ;
}
static int F_25 ( struct V_1 * V_2 , int V_48 , int V_95 )
{
int V_4 ;
V_4 = F_14 ( V_2 , V_48 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_15 ( V_2 , V_48 , V_4 | V_95 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_48 , V_12 , V_24 , V_96 ;
V_12 = F_15 ( V_2 , V_97 , V_98 ) ;
if ( V_12 < 0 )
return V_12 ;
V_48 = F_14 ( V_2 , V_99 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = V_100 |
V_101 |
V_102 |
V_103 |
V_104 ;
V_12 = F_15 ( V_2 , V_99 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
V_96 = F_14 ( V_2 , V_105 ) ;
if ( V_96 < 0 )
return V_96 ;
V_48 = V_96 | V_106 ;
V_12 = F_15 ( V_2 , V_105 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
V_48 = F_14 ( V_2 , V_107 ) ;
if ( V_48 < 0 ) {
V_12 = V_48 ;
goto V_108;
}
V_48 &= ~ V_109 ;
V_48 |= V_110 ;
V_12 = F_15 ( V_2 , V_107 , V_48 ) ;
if ( V_12 < 0 )
goto V_108;
V_12 = F_25 ( V_2 , V_111 ,
V_112 ) ;
if ( V_12 < 0 )
goto V_108;
if ( V_2 -> V_39 & V_42 ) {
V_12 = F_25 ( V_2 , V_113 ,
V_114 ) ;
}
V_108:
V_24 = F_15 ( V_2 , V_105 , V_96 ) ;
if ( ! V_12 )
V_12 = V_24 ;
return V_12 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_48 ;
V_48 = F_14 ( V_2 , V_99 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_48 , V_12 ;
V_48 = F_14 ( V_2 , V_99 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_2 -> V_115 == V_116 )
V_48 &= ~ V_104 ;
else
V_48 |= V_104 ;
V_12 = F_15 ( V_2 , V_99 , V_48 ) ;
return V_12 ;
}
