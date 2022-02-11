static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_4 , F_3 ( V_3 ) ) ;
return F_4 ( F_5 ( V_2 , V_4 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
return F_2 ( V_2 , V_4 ,
V_6 |
F_3 ( V_3 ) |
F_4 ( V_5 ) ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_8 , V_7 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_9 ) ;
F_2 ( V_2 , V_8 , 0 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_5 )
{
int V_10 ;
V_10 = F_2 ( V_2 , V_8 , V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_2 ( V_2 , V_9 , V_5 ) ;
F_2 ( V_2 , V_8 , 0 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_5 )
{
return F_2 ( V_2 , V_11 , V_7 | V_5 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_8 ( V_2 , V_13 ,
V_14 |
V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_8 ( V_2 , V_16 ,
V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_8 ( V_2 , V_18 ,
V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_8 ( V_2 , V_20 ,
V_21 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_8 ( V_2 , V_22 ,
V_23 ) ;
return V_12 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_12 , V_24 ;
V_12 = F_9 ( V_2 ,
V_25 ,
V_26 |
V_27 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_12 ( V_2 ) == V_28 ||
F_12 ( V_2 ) == V_29 ) {
V_12 = F_8 ( V_2 , V_30 ,
V_31 ) ;
if ( V_12 < 0 )
goto error;
if ( V_2 -> V_32 -> V_33 == V_28 ) {
V_12 = F_10 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
}
}
if ( F_12 ( V_2 ) == V_34 ) {
int V_5 ;
V_5 = F_7 ( V_2 , V_18 ) ;
if ( V_5 < 0 )
goto error;
V_5 |= V_35 ;
V_12 = F_8 ( V_2 , V_18 , V_5 ) ;
}
error:
V_24 = F_9 ( V_2 ,
V_25 ,
V_27 ) ;
return V_12 ? V_12 : V_24 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_2 V_36 ;
int V_5 ;
bool V_37 = true ;
if ( F_12 ( V_2 ) != V_34 &&
F_12 ( V_2 ) != V_28 &&
F_12 ( V_2 ) != V_29 )
return;
V_5 = F_1 ( V_2 , V_38 ) ;
if ( V_5 < 0 )
return;
V_36 = V_5 ;
if ( ( F_12 ( V_2 ) == V_28 ||
F_12 ( V_2 ) == V_29 ) &&
F_14 ( V_2 ) >= 0x3 ) {
V_37 = false ;
} else {
if ( V_2 -> V_39 & V_40 ) {
V_5 &= ~ V_41 ;
V_37 = false ;
}
}
if ( ! V_37 || ( V_2 -> V_39 & V_42 ) )
V_5 &= ~ V_43 ;
else
V_5 |= V_43 ;
if ( V_2 -> V_39 & V_44 )
V_5 |= V_45 ;
if ( V_36 != V_5 )
F_6 ( V_2 , V_38 , V_5 ) ;
V_5 = F_1 ( V_2 , V_46 ) ;
if ( V_5 < 0 )
return;
V_36 = V_5 ;
if ( ! V_37 || ( V_2 -> V_39 & V_42 ) )
V_5 |= V_47 ;
else
V_5 &= ~ V_47 ;
if ( V_36 != V_5 )
F_6 ( V_2 , V_46 , V_5 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_48 , V_12 ;
V_48 = F_5 ( V_2 , V_49 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 |= V_50 ;
V_12 = F_2 ( V_2 , V_49 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
V_48 = ~ ( V_51 |
V_52 |
V_53 ) ;
V_12 = F_2 ( V_2 , V_54 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ( F_12 ( V_2 ) == V_28 ||
F_12 ( V_2 ) == V_29 ) &&
( V_2 -> V_39 & V_55 ) )
F_6 ( V_2 , V_56 , 0 ) ;
if ( ( V_2 -> V_39 & V_40 ) ||
( V_2 -> V_39 & V_44 ) ||
( V_2 -> V_39 & V_42 ) )
F_13 ( V_2 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_12 , V_48 ;
V_12 = F_15 ( V_2 ) ;
if ( V_2 -> V_39 & V_57 ) {
V_48 = F_1 ( V_2 , V_58 ) ;
F_6 ( V_2 , V_58 ,
V_48 |
V_59 |
V_60 ) ;
V_48 = V_61 | V_62 ;
V_12 = F_7 ( V_2 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_8 ( V_2 , V_48 , V_12 |
V_63 |
V_64 ) ;
if ( V_12 < 0 )
return V_12 ;
V_48 = V_65 | V_62 ;
V_12 = F_7 ( V_2 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_8 ( V_2 , V_48 ,
V_12 & ~ V_66 ) ;
if ( V_12 < 0 )
return V_12 ;
V_48 = F_1 ( V_2 , V_67 ) ;
F_6 ( V_2 , V_67 ,
V_48 | V_68 ) ;
F_6 ( V_2 , V_69 ,
F_17 ( V_70 ) |
F_18 ( V_71 ) ) ;
V_2 -> V_72 = V_73 ;
V_2 -> V_74 = V_75 ;
V_2 -> V_76 = V_77 ;
}
return V_12 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_20 ( V_2 ) ;
if ( V_2 -> V_39 & V_57 ) {
if ( V_2 -> V_78 ) {
V_2 -> V_74 = V_75 ;
V_2 -> V_76 = V_77 ;
}
}
return V_12 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_48 ;
V_48 = F_5 ( V_2 , V_79 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_48 , V_12 ;
V_48 = F_5 ( V_2 , V_49 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_2 -> V_80 == V_81 )
V_48 &= ~ V_50 ;
else
V_48 |= V_50 ;
V_12 = F_2 ( V_2 , V_49 , V_48 ) ;
return V_12 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_24 ( V_2 ) ;
if ( V_2 -> V_82 == V_83 ) {
T_1 V_48 ;
V_48 = 0x7 | ( 0x7 << 12 ) ;
F_2 ( V_2 , 0x18 , V_48 ) ;
V_48 = F_5 ( V_2 , 0x18 ) ;
V_48 |= ( 1 << 8 ) ;
V_48 |= ( 1 << 15 ) ;
F_2 ( V_2 , 0x18 , V_48 ) ;
}
return V_10 ;
}
static int F_25 ( struct V_1 * V_2 , int V_48 , int V_84 )
{
int V_5 ;
V_5 = F_5 ( V_2 , V_48 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_2 ( V_2 , V_48 , V_5 | V_84 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_48 , V_12 , V_24 , V_85 ;
V_12 = F_2 ( V_2 , V_86 , V_87 ) ;
if ( V_12 < 0 )
return V_12 ;
V_48 = F_5 ( V_2 , V_88 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = V_89 |
V_90 |
V_91 |
V_92 |
V_93 ;
V_12 = F_2 ( V_2 , V_88 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
V_85 = F_5 ( V_2 , V_94 ) ;
if ( V_85 < 0 )
return V_85 ;
V_48 = V_85 | V_95 ;
V_12 = F_2 ( V_2 , V_94 , V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
V_48 = F_5 ( V_2 , V_96 ) ;
if ( V_48 < 0 ) {
V_12 = V_48 ;
goto V_97;
}
V_48 &= ~ V_98 ;
V_48 |= V_99 ;
V_12 = F_2 ( V_2 , V_96 , V_48 ) ;
if ( V_12 < 0 )
goto V_97;
V_12 = F_25 ( V_2 , V_100 ,
V_101 ) ;
if ( V_12 < 0 )
goto V_97;
if ( V_2 -> V_39 & V_42 ) {
V_12 = F_25 ( V_2 , V_102 ,
V_103 ) ;
}
V_97:
V_24 = F_2 ( V_2 , V_94 , V_85 ) ;
if ( ! V_12 )
V_12 = V_24 ;
return V_12 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_48 ;
V_48 = F_5 ( V_2 , V_88 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_48 , V_12 ;
V_48 = F_5 ( V_2 , V_88 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_2 -> V_80 == V_81 )
V_48 &= ~ V_93 ;
else
V_48 |= V_93 ;
V_12 = F_2 ( V_2 , V_88 , V_48 ) ;
return V_12 ;
}
static int T_3 F_29 ( void )
{
return F_30 ( V_104 ,
F_31 ( V_104 ) ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( V_104 ,
F_31 ( V_104 ) ) ;
}
