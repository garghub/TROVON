static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_5 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_3 ( V_2 , V_6 ) ;
F_2 ( V_2 , V_5 , 0 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_7 ;
V_7 = F_2 ( V_2 , V_5 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_2 ( V_2 , V_6 , V_4 ) ;
F_2 ( V_2 , V_5 , 0 ) ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 , V_8 , V_3 | V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_4 ( V_2 , V_10 ,
V_11 |
V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_4 ( V_2 , V_13 ,
V_14 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_4 ( V_2 , V_15 ,
V_16 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_4 ( V_2 , V_17 ,
V_18 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_4 ( V_2 , V_19 ,
V_20 ) ;
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_9 , V_21 ;
V_9 = F_5 ( V_2 ,
V_22 ,
V_23 |
V_24 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( F_8 ( V_2 ) == V_25 ||
F_8 ( V_2 ) == V_26 ) {
V_9 = F_4 ( V_2 , V_27 ,
V_28 ) ;
if ( V_9 < 0 )
goto error;
if ( V_2 -> V_29 -> V_30 == V_25 ) {
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
}
}
if ( F_8 ( V_2 ) == V_31 ) {
int V_4 ;
V_4 = F_1 ( V_2 , V_15 ) ;
if ( V_4 < 0 )
goto error;
V_4 |= V_32 ;
V_9 = F_4 ( V_2 , V_15 , V_4 ) ;
}
error:
V_21 = F_5 ( V_2 ,
V_22 ,
V_24 ) ;
return V_9 ? V_9 : V_21 ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_2 V_33 ;
int V_4 ;
bool V_34 = true ;
if ( F_8 ( V_2 ) != V_31 &&
F_8 ( V_2 ) != V_25 &&
F_8 ( V_2 ) != V_26 )
return;
V_4 = F_10 ( V_2 , V_35 ) ;
if ( V_4 < 0 )
return;
V_33 = V_4 ;
if ( ( F_8 ( V_2 ) == V_25 ||
F_8 ( V_2 ) == V_26 ) &&
F_11 ( V_2 ) >= 0x3 ) {
V_34 = false ;
} else {
if ( V_2 -> V_36 & V_37 ) {
V_4 &= ~ V_38 ;
V_34 = false ;
}
}
if ( ! V_34 || ( V_2 -> V_36 & V_39 ) )
V_4 &= ~ V_40 ;
else
V_4 |= V_40 ;
if ( V_2 -> V_36 & V_41 )
V_4 |= V_42 ;
if ( V_33 != V_4 )
F_12 ( V_2 , V_35 , V_4 ) ;
V_4 = F_10 ( V_2 , V_43 ) ;
if ( V_4 < 0 )
return;
V_33 = V_4 ;
if ( ! V_34 || ( V_2 -> V_36 & V_39 ) )
V_4 |= V_44 ;
else
V_4 &= ~ V_44 ;
if ( V_33 != V_4 )
F_12 ( V_2 , V_43 , V_4 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_45 , V_9 ;
V_45 = F_3 ( V_2 , V_46 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 |= V_47 ;
V_9 = F_2 ( V_2 , V_46 , V_45 ) ;
if ( V_9 < 0 )
return V_9 ;
V_45 = ~ ( V_48 |
V_49 |
V_50 ) ;
V_9 = F_2 ( V_2 , V_51 , V_45 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ( F_8 ( V_2 ) == V_25 ||
F_8 ( V_2 ) == V_26 ) &&
( V_2 -> V_36 & V_52 ) )
F_12 ( V_2 , V_53 , 0 ) ;
if ( ( V_2 -> V_36 & V_37 ) ||
( V_2 -> V_36 & V_41 ) ||
( V_2 -> V_36 & V_39 ) )
F_9 ( V_2 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_9 , V_45 ;
V_9 = F_13 ( V_2 ) ;
if ( V_2 -> V_36 & V_54 ) {
V_45 = F_10 ( V_2 , V_55 ) ;
F_12 ( V_2 , V_55 ,
V_45 |
V_56 |
V_57 ) ;
V_45 = V_58 | V_59 ;
V_9 = F_1 ( V_2 , V_45 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_4 ( V_2 , V_45 , V_9 |
V_60 |
V_61 ) ;
if ( V_9 < 0 )
return V_9 ;
V_45 = V_62 | V_59 ;
V_9 = F_1 ( V_2 , V_45 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_4 ( V_2 , V_45 ,
V_9 & ~ V_63 ) ;
if ( V_9 < 0 )
return V_9 ;
V_45 = F_10 ( V_2 , V_64 ) ;
F_12 ( V_2 , V_64 ,
V_45 | V_65 ) ;
F_12 ( V_2 , V_66 ,
F_15 ( V_67 ) |
F_16 ( V_68 ) ) ;
V_2 -> V_69 = V_70 ;
V_2 -> V_71 = V_72 ;
V_2 -> V_73 = V_74 ;
}
return V_9 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_18 ( V_2 ) ;
if ( V_2 -> V_36 & V_54 ) {
if ( V_2 -> V_75 ) {
V_2 -> V_71 = V_72 ;
V_2 -> V_73 = V_74 ;
}
}
return V_9 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_3 ( V_2 , V_76 ) ;
if ( V_45 < 0 )
return V_45 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_45 , V_9 ;
V_45 = F_3 ( V_2 , V_46 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_2 -> V_77 == V_78 )
V_45 &= ~ V_47 ;
else
V_45 |= V_47 ;
V_9 = F_2 ( V_2 , V_46 , V_45 ) ;
return V_9 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_22 ( V_2 ) ;
if ( V_2 -> V_79 == V_80 ) {
T_1 V_45 ;
V_45 = 0x7 | ( 0x7 << 12 ) ;
F_2 ( V_2 , 0x18 , V_45 ) ;
V_45 = F_3 ( V_2 , 0x18 ) ;
V_45 |= ( 1 << 8 ) ;
V_45 |= ( 1 << 15 ) ;
F_2 ( V_2 , 0x18 , V_45 ) ;
}
return V_7 ;
}
static int F_23 ( struct V_1 * V_2 , int V_45 , int V_81 )
{
int V_4 ;
V_4 = F_3 ( V_2 , V_45 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_2 ( V_2 , V_45 , V_4 | V_81 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_45 , V_9 , V_21 , V_82 ;
V_9 = F_2 ( V_2 , V_83 , V_84 ) ;
if ( V_9 < 0 )
return V_9 ;
V_45 = F_3 ( V_2 , V_85 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = V_86 |
V_87 |
V_88 |
V_89 |
V_90 ;
V_9 = F_2 ( V_2 , V_85 , V_45 ) ;
if ( V_9 < 0 )
return V_9 ;
V_82 = F_3 ( V_2 , V_91 ) ;
if ( V_82 < 0 )
return V_82 ;
V_45 = V_82 | V_92 ;
V_9 = F_2 ( V_2 , V_91 , V_45 ) ;
if ( V_9 < 0 )
return V_9 ;
V_45 = F_3 ( V_2 , V_93 ) ;
if ( V_45 < 0 ) {
V_9 = V_45 ;
goto V_94;
}
V_45 &= ~ V_95 ;
V_45 |= V_96 ;
V_9 = F_2 ( V_2 , V_93 , V_45 ) ;
if ( V_9 < 0 )
goto V_94;
V_9 = F_23 ( V_2 , V_97 ,
V_98 ) ;
if ( V_9 < 0 )
goto V_94;
if ( V_2 -> V_36 & V_39 ) {
V_9 = F_23 ( V_2 , V_99 ,
V_100 ) ;
}
V_94:
V_21 = F_2 ( V_2 , V_91 , V_82 ) ;
if ( ! V_9 )
V_9 = V_21 ;
return V_9 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_3 ( V_2 , V_85 ) ;
if ( V_45 < 0 )
return V_45 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_45 , V_9 ;
V_45 = F_3 ( V_2 , V_85 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_2 -> V_77 == V_78 )
V_45 &= ~ V_90 ;
else
V_45 |= V_90 ;
V_9 = F_2 ( V_2 , V_85 , V_45 ) ;
return V_9 ;
}
static int T_3 F_27 ( void )
{
return F_28 ( V_101 ,
F_29 ( V_101 ) ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( V_101 ,
F_29 ( V_101 ) ) ;
}
