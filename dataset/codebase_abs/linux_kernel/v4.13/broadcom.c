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
V_3 = F_2 ( V_2 , V_4 ) ;
V_3 |= V_6 ;
if ( V_2 -> V_9 == V_16 ||
V_2 -> V_9 == V_11 ) {
V_3 &= ~ V_5 ;
}
if ( V_2 -> V_9 == V_10 ||
V_2 -> V_9 == V_12 ) {
V_3 |= V_5 ;
}
V_15 = F_3 ( V_2 , V_4 ,
V_3 ) ;
if ( V_15 < 0 )
return V_15 ;
V_3 = F_4 ( V_2 , V_7 ) ;
if ( V_2 -> V_9 == V_16 ||
V_2 -> V_9 == V_12 ) {
V_3 &= ~ V_8 ;
}
if ( V_2 -> V_9 == V_10 ||
V_2 -> V_9 == V_11 ) {
V_3 |= V_8 ;
}
V_15 = F_5 ( V_2 , V_7 , V_3 ) ;
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_9 ( V_2 , V_18 ,
V_19 |
V_20 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_9 ( V_2 , V_21 ,
V_22 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_9 ( V_2 , V_23 ,
V_24 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_9 ( V_2 , V_25 ,
V_26 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_9 ( V_2 , V_27 ,
V_28 ) ;
return V_17 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_17 , V_29 ;
V_17 = F_3 ( V_2 ,
V_30 ,
V_31 |
V_32 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( F_11 ( V_2 ) == V_33 ||
F_11 ( V_2 ) == V_34 ) {
V_17 = F_9 ( V_2 , V_35 ,
V_36 ) ;
if ( V_17 < 0 )
goto error;
if ( V_2 -> V_37 -> V_38 == V_33 ) {
V_17 = F_8 ( V_2 ) ;
if ( V_17 < 0 )
goto error;
}
}
if ( F_11 ( V_2 ) == V_39 ) {
int V_3 ;
V_3 = F_12 ( V_2 , V_23 ) ;
if ( V_3 < 0 )
goto error;
V_3 |= V_40 ;
V_17 = F_9 ( V_2 , V_23 , V_3 ) ;
}
error:
V_29 = F_3 ( V_2 ,
V_30 ,
V_32 ) ;
return V_17 ? V_17 : V_29 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_2 V_41 ;
int V_3 ;
bool V_42 = true ;
if ( F_11 ( V_2 ) != V_39 &&
F_11 ( V_2 ) != V_33 &&
F_11 ( V_2 ) != V_34 )
return;
V_3 = F_4 ( V_2 , V_43 ) ;
if ( V_3 < 0 )
return;
V_41 = V_3 ;
if ( ( F_11 ( V_2 ) == V_33 ||
F_11 ( V_2 ) == V_34 ) &&
F_14 ( V_2 ) >= 0x3 ) {
V_42 = false ;
} else {
if ( V_2 -> V_44 & V_45 ) {
V_3 &= ~ V_46 ;
V_42 = false ;
}
}
if ( ! V_42 || ( V_2 -> V_44 & V_47 ) )
V_3 &= ~ V_48 ;
else
V_3 |= V_48 ;
if ( V_2 -> V_44 & V_49 )
V_3 |= V_50 ;
if ( V_41 != V_3 )
F_5 ( V_2 , V_43 , V_3 ) ;
V_3 = F_4 ( V_2 , V_51 ) ;
if ( V_3 < 0 )
return;
V_41 = V_3 ;
if ( ! V_42 || ( V_2 -> V_44 & V_47 ) )
V_3 |= V_52 ;
else
V_3 &= ~ V_52 ;
if ( V_41 != V_3 )
F_5 ( V_2 , V_51 , V_3 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_13 , V_17 , V_3 ;
V_13 = F_16 ( V_2 , V_53 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 |= V_54 ;
V_17 = F_17 ( V_2 , V_53 , V_13 ) ;
if ( V_17 < 0 )
return V_17 ;
V_13 = ~ ( V_55 |
V_56 |
V_57 ) ;
V_17 = F_17 ( V_2 , V_58 , V_13 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( ( F_11 ( V_2 ) == V_33 ||
F_11 ( V_2 ) == V_34 ) &&
( V_2 -> V_44 & V_59 ) )
F_5 ( V_2 , V_60 , 0 ) ;
if ( ( V_2 -> V_44 & V_45 ) ||
( V_2 -> V_44 & V_49 ) ||
( V_2 -> V_44 & V_47 ) )
F_13 ( V_2 ) ;
if ( F_11 ( V_2 ) == V_61 ) {
V_17 = F_1 ( V_2 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_11 ( V_2 ) == V_62 ) {
V_17 = F_6 ( V_2 ) ;
if ( V_17 )
return V_17 ;
} else if ( F_11 ( V_2 ) == V_63 ) {
V_3 = F_12 ( V_2 ,
V_64 ) ;
V_3 &= ~ V_65 ;
V_17 = F_9 ( V_2 ,
V_64 ,
V_3 ) ;
if ( V_17 < 0 )
return V_17 ;
}
F_10 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_17 , V_13 ;
V_17 = F_15 ( V_2 ) ;
if ( V_2 -> V_44 & V_66 ) {
V_13 = F_4 ( V_2 , V_67 ) ;
F_5 ( V_2 , V_67 ,
V_13 |
V_68 |
V_69 ) ;
V_13 = V_70 | V_71 ;
V_17 = F_12 ( V_2 , V_13 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_9 ( V_2 , V_13 , V_17 |
V_72 |
V_73 ) ;
if ( V_17 < 0 )
return V_17 ;
V_13 = V_74 | V_71 ;
V_17 = F_12 ( V_2 , V_13 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_9 ( V_2 , V_13 ,
V_17 & ~ V_75 ) ;
if ( V_17 < 0 )
return V_17 ;
V_13 = F_4 ( V_2 , V_76 ) ;
F_5 ( V_2 , V_76 ,
V_13 | V_77 ) ;
F_5 ( V_2 , V_78 ,
F_19 ( V_79 ) |
F_20 ( V_80 ) ) ;
V_2 -> V_81 = V_82 ;
V_2 -> V_83 = V_84 ;
V_2 -> V_85 = V_86 ;
}
return V_17 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_22 ( V_2 ) ;
if ( V_2 -> V_44 & V_66 ) {
if ( V_2 -> V_87 ) {
V_2 -> V_83 = V_84 ;
V_2 -> V_85 = V_86 ;
}
}
return V_17 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = V_2 -> V_90 . V_91 . V_92 ;
int V_93 ;
V_93 = F_24 ( V_2 ) ;
F_7 ( V_2 ) ;
if ( F_25 ( V_89 , L_1 ) ) {
V_93 = F_9 ( V_2 , V_94 + 0x9 ,
0x11B ) ;
if ( V_93 < 0 )
return V_93 ;
}
return V_93 ;
}
static int F_26 ( struct V_1 * V_2 , int V_13 , int V_95 )
{
int V_3 ;
V_3 = F_16 ( V_2 , V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_17 ( V_2 , V_13 , V_3 | V_95 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_13 , V_17 , V_29 , V_96 ;
V_17 = F_17 ( V_2 , V_97 , V_98 ) ;
if ( V_17 < 0 )
return V_17 ;
V_13 = F_16 ( V_2 , V_99 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = V_100 |
V_101 |
V_102 |
V_103 |
V_104 ;
V_17 = F_17 ( V_2 , V_99 , V_13 ) ;
if ( V_17 < 0 )
return V_17 ;
V_96 = F_16 ( V_2 , V_105 ) ;
if ( V_96 < 0 )
return V_96 ;
V_13 = V_96 | V_106 ;
V_17 = F_17 ( V_2 , V_105 , V_13 ) ;
if ( V_17 < 0 )
return V_17 ;
V_13 = F_16 ( V_2 , V_107 ) ;
if ( V_13 < 0 ) {
V_17 = V_13 ;
goto V_108;
}
V_13 &= ~ V_109 ;
V_13 |= V_110 ;
V_17 = F_17 ( V_2 , V_107 , V_13 ) ;
if ( V_17 < 0 )
goto V_108;
V_17 = F_26 ( V_2 , V_111 ,
V_112 ) ;
if ( V_17 < 0 )
goto V_108;
if ( V_2 -> V_44 & V_47 ) {
V_17 = F_26 ( V_2 , V_113 ,
V_114 ) ;
}
V_108:
V_29 = F_17 ( V_2 , V_105 , V_96 ) ;
if ( ! V_17 )
V_17 = V_29 ;
return V_17 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_16 ( V_2 , V_99 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_13 , V_17 ;
V_13 = F_16 ( V_2 , V_99 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_2 -> V_115 == V_116 )
V_13 &= ~ V_104 ;
else
V_13 |= V_104 ;
V_17 = F_17 ( V_2 , V_99 , V_13 ) ;
return V_17 ;
}
