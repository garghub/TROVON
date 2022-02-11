static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 , V_5 , V_3 | V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_4 ( V_2 , V_7 ,
V_8 |
V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_10 ,
V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_12 ,
V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_14 ,
V_15 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_16 ,
V_17 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_6 , V_18 ;
V_6 = F_1 ( V_2 ,
V_19 ,
V_20 |
V_21 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_6 ( V_2 ) == V_22 ||
F_6 ( V_2 ) == V_23 ) {
V_6 = F_4 ( V_2 , V_24 ,
V_25 ) ;
if ( V_6 < 0 )
goto error;
if ( V_2 -> V_26 -> V_27 == V_22 ) {
V_6 = F_3 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
}
}
if ( F_6 ( V_2 ) == V_28 ) {
int V_4 ;
V_4 = F_7 ( V_2 , V_12 ) ;
if ( V_4 < 0 )
goto error;
V_4 |= V_29 ;
V_6 = F_4 ( V_2 , V_12 , V_4 ) ;
}
error:
V_18 = F_1 ( V_2 ,
V_19 ,
V_21 ) ;
return V_6 ? V_6 : V_18 ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_30 ;
int V_4 ;
bool V_31 = true ;
if ( F_6 ( V_2 ) != V_28 &&
F_6 ( V_2 ) != V_22 &&
F_6 ( V_2 ) != V_23 )
return;
V_4 = F_9 ( V_2 , V_32 ) ;
if ( V_4 < 0 )
return;
V_30 = V_4 ;
if ( ( F_6 ( V_2 ) == V_22 ||
F_6 ( V_2 ) == V_23 ) &&
F_10 ( V_2 ) >= 0x3 ) {
V_31 = false ;
} else {
if ( V_2 -> V_33 & V_34 ) {
V_4 &= ~ V_35 ;
V_31 = false ;
}
}
if ( ! V_31 || ( V_2 -> V_33 & V_36 ) )
V_4 &= ~ V_37 ;
else
V_4 |= V_37 ;
if ( V_2 -> V_33 & V_38 )
V_4 |= V_39 ;
if ( V_30 != V_4 )
F_11 ( V_2 , V_32 , V_4 ) ;
V_4 = F_9 ( V_2 , V_40 ) ;
if ( V_4 < 0 )
return;
V_30 = V_4 ;
if ( ! V_31 || ( V_2 -> V_33 & V_36 ) )
V_4 |= V_41 ;
else
V_4 &= ~ V_41 ;
if ( V_30 != V_4 )
F_11 ( V_2 , V_40 , V_4 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_42 , V_6 ;
V_42 = F_13 ( V_2 , V_43 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 |= V_44 ;
V_6 = F_2 ( V_2 , V_43 , V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
V_42 = ~ ( V_45 |
V_46 |
V_47 ) ;
V_6 = F_2 ( V_2 , V_48 , V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ( F_6 ( V_2 ) == V_22 ||
F_6 ( V_2 ) == V_23 ) &&
( V_2 -> V_33 & V_49 ) )
F_11 ( V_2 , V_50 , 0 ) ;
if ( ( V_2 -> V_33 & V_34 ) ||
( V_2 -> V_33 & V_38 ) ||
( V_2 -> V_33 & V_36 ) )
F_8 ( V_2 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_6 , V_42 ;
V_6 = F_12 ( V_2 ) ;
if ( V_2 -> V_33 & V_51 ) {
V_42 = F_9 ( V_2 , V_52 ) ;
F_11 ( V_2 , V_52 ,
V_42 |
V_53 |
V_54 ) ;
V_42 = V_55 | V_56 ;
V_6 = F_7 ( V_2 , V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_42 , V_6 |
V_57 |
V_58 ) ;
if ( V_6 < 0 )
return V_6 ;
V_42 = V_59 | V_56 ;
V_6 = F_7 ( V_2 , V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_42 ,
V_6 & ~ V_60 ) ;
if ( V_6 < 0 )
return V_6 ;
V_42 = F_9 ( V_2 , V_61 ) ;
F_11 ( V_2 , V_61 ,
V_42 | V_62 ) ;
F_11 ( V_2 , V_63 ,
F_15 ( V_64 ) |
F_16 ( V_65 ) ) ;
V_2 -> V_66 = V_67 ;
V_2 -> V_68 = V_69 ;
V_2 -> V_70 = V_71 ;
}
return V_6 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_18 ( V_2 ) ;
if ( V_2 -> V_33 & V_51 ) {
if ( V_2 -> V_72 ) {
V_2 -> V_68 = V_69 ;
V_2 -> V_70 = V_71 ;
}
}
return V_6 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_73 ;
V_73 = F_20 ( V_2 ) ;
if ( V_2 -> V_74 == V_75 ) {
T_1 V_42 ;
V_42 = 0x7 | ( 0x7 << 12 ) ;
F_2 ( V_2 , 0x18 , V_42 ) ;
V_42 = F_13 ( V_2 , 0x18 ) ;
V_42 |= ( 1 << 8 ) ;
V_42 |= ( 1 << 15 ) ;
F_2 ( V_2 , 0x18 , V_42 ) ;
}
return V_73 ;
}
static int F_21 ( struct V_1 * V_2 , int V_42 , int V_76 )
{
int V_4 ;
V_4 = F_13 ( V_2 , V_42 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_2 ( V_2 , V_42 , V_4 | V_76 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_42 , V_6 , V_18 , V_77 ;
V_6 = F_2 ( V_2 , V_78 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
V_42 = F_13 ( V_2 , V_80 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = V_81 |
V_82 |
V_83 |
V_84 |
V_85 ;
V_6 = F_2 ( V_2 , V_80 , V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
V_77 = F_13 ( V_2 , V_86 ) ;
if ( V_77 < 0 )
return V_77 ;
V_42 = V_77 | V_87 ;
V_6 = F_2 ( V_2 , V_86 , V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
V_42 = F_13 ( V_2 , V_88 ) ;
if ( V_42 < 0 ) {
V_6 = V_42 ;
goto V_89;
}
V_42 &= ~ V_90 ;
V_42 |= V_91 ;
V_6 = F_2 ( V_2 , V_88 , V_42 ) ;
if ( V_6 < 0 )
goto V_89;
V_6 = F_21 ( V_2 , V_92 ,
V_93 ) ;
if ( V_6 < 0 )
goto V_89;
if ( V_2 -> V_33 & V_36 ) {
V_6 = F_21 ( V_2 , V_94 ,
V_95 ) ;
}
V_89:
V_18 = F_2 ( V_2 , V_86 , V_77 ) ;
if ( ! V_6 )
V_6 = V_18 ;
return V_6 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_13 ( V_2 , V_80 ) ;
if ( V_42 < 0 )
return V_42 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_42 , V_6 ;
V_42 = F_13 ( V_2 , V_80 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_2 -> V_96 == V_97 )
V_42 &= ~ V_85 ;
else
V_42 |= V_85 ;
V_6 = F_2 ( V_2 , V_80 , V_42 ) ;
return V_6 ;
}
