static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 = F_2 ( V_2 , V_5 ) ;
if ( V_3 )
F_3 ( V_2 , V_6 , V_7 ) ;
else
F_3 ( V_2 , V_8 , V_7 ) ;
V_4 &= ~ V_9 ;
if ( V_3 )
V_4 |= ( V_10 | V_11 ) ;
else
V_4 |= ( V_10 ) ;
F_3 ( V_2 , V_4 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_4 , V_12 ;
if ( ! V_2 -> V_13 || ! F_5 ( ( T_1 ) V_2 -> V_13 , V_14 ) )
return - V_15 ;
V_12 = F_6 ( V_2 -> V_13 ) ;
if ( ! F_5 ( V_12 , V_14 ) )
return - V_15 ;
V_4 = F_2 ( V_2 , V_16 ) ;
F_7 ( V_2 -> V_17 , L_1 , V_2 -> V_18 ,
( V_4 >> 4 ) & 0xf , V_4 & 0xf ) ;
F_3 ( V_2 , V_12 , V_19 ) ;
F_1 ( V_2 , true ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_4 = F_2 ( V_2 , V_5 ) ;
V_4 &= ~ V_9 ;
F_3 ( V_2 , V_4 , V_5 ) ;
F_9 ( V_2 -> V_17 , L_2 , V_2 -> V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 , bool V_3 )
{
F_1 ( V_2 , false ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 * V_20 )
{
T_1 V_21 , V_22 ;
T_1 V_23 = 0 ;
V_21 = F_2 ( V_2 , V_24 ) ;
V_21 &= V_25 ;
if ( ! V_21 ) {
* V_20 = 0 ;
return 0 ;
}
V_22 = F_2 ( V_2 , V_26 ) ;
* V_20 = V_22 ;
if ( V_21 & V_27 )
V_23 |= V_28 ;
if ( V_21 & V_29 )
V_23 |= V_30 ;
if ( V_21 & V_31 )
V_23 |= V_32 ;
if ( V_21 & V_33 )
V_23 |= V_34 ;
if ( V_21 & V_35 )
V_23 |= V_36 ;
F_3 ( V_2 , V_21 , V_24 ) ;
return V_23 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
V_38 -> V_39 = F_2 ( V_2 , V_40 ) ;
V_38 -> V_41 = F_2 ( V_2 , V_42 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
F_3 ( V_2 , V_38 -> V_39 | V_43 , V_44 ) ;
F_3 ( V_2 , V_38 -> V_41 , V_45 ) ;
}
static T_1 F_14 ( struct V_37 * V_38 )
{
T_1 V_46 = V_38 -> V_39 & V_47 ;
T_1 V_48 = F_15 ( V_38 -> V_39 & V_46 ) ;
return V_38 -> V_39 & V_48 ;
}
static struct V_37 * F_16 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_37 * V_38 ;
if ( V_50 -> V_22 & ~ ( F_15 ( V_50 -> V_51 ) ) ) {
F_17 ( V_2 -> V_17 , L_3 , V_52 ,
V_50 -> V_22 ) ;
return F_18 ( - V_15 ) ;
}
V_38 = F_19 ( sizeof( * V_38 ) , V_53 ) ;
if ( ! V_38 )
return F_18 ( - V_54 ) ;
V_38 -> V_39 = ( V_50 -> V_22 & V_55 ) | V_50 -> V_56 | V_50 -> V_51 | V_50 -> V_57 ;
V_38 -> V_41 = V_50 -> V_12 | V_50 -> V_58 | V_50 -> V_59 | V_50 -> V_60 ;
return V_38 ;
}
static inline int F_20 ( struct V_37 * V_38 )
{
return V_38 -> V_39 & V_43 ;
}
static T_1 F_21 ( struct V_49 * V_50 )
{
T_1 V_61 ;
V_61 = V_50 -> V_60 << 5 ;
V_61 |= V_50 -> V_58 ;
V_61 |= V_50 -> V_59 >> 3 ;
V_61 <<= ( ( ( V_50 -> V_51 == V_62 ) ||
( V_50 -> V_51 == V_63 ) ) ? 0 : 6 ) ;
return V_61 ;
}
static T_2
F_22 ( struct V_1 * V_2 , struct V_37 * V_38 , char * V_64 )
{
char * V_65 = V_64 ;
V_65 += sprintf ( V_65 , L_4 , V_38 -> V_39 , V_38 -> V_41 ,
( V_38 -> V_39 & V_66 ) ? 1 : 0 ) ;
return V_65 - V_64 ;
}
static T_2
F_23 ( struct V_1 * V_2 , char * V_64 , T_2 V_67 )
{
char * V_65 = V_64 ;
F_24 ( V_68 ) ;
F_24 ( V_69 ) ;
F_24 ( V_70 ) ;
F_24 ( V_71 ) ;
F_24 ( V_72 ) ;
F_24 ( V_73 ) ;
F_24 ( V_74 ) ;
F_24 ( V_75 ) ;
F_24 ( V_76 ) ;
F_24 ( V_77 ) ;
F_24 ( V_78 ) ;
F_24 ( V_79 ) ;
F_24 ( V_80 ) ;
F_24 ( V_81 ) ;
F_24 ( V_82 ) ;
F_24 ( V_83 ) ;
V_84:
return V_65 - V_64 ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_85 ;
T_1 * V_65 = V_2 -> V_86 ;
for ( V_85 = 0 ; V_85 < ( V_87 / sizeof( T_1 ) ) ; V_85 ++ ) {
V_65 [ V_85 ] = F_2 ( V_2 , V_85 * sizeof( T_1 ) ) ;
F_9 ( V_2 -> V_17 , L_5 , V_52 , V_85 , V_65 [ V_85 ] ) ;
}
F_26 ( V_65 [ 0 ] != V_88 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_85 ;
T_1 * V_65 = V_2 -> V_86 ;
for ( V_85 = 0 ; V_85 < ( V_87 / sizeof( T_1 ) ) ; V_85 ++ ) {
F_3 ( V_2 , V_65 [ V_85 ] , V_85 * sizeof( T_1 ) ) ;
F_9 ( V_2 -> V_17 , L_5 , V_52 , V_85 , V_65 [ V_85 ] ) ;
}
F_26 ( V_65 [ 0 ] != V_88 ) ;
}
static void F_28 ( struct V_37 * V_38 , struct V_49 * V_50 )
{
V_50 -> V_22 = V_38 -> V_39 & V_55 ;
V_50 -> V_12 = V_38 -> V_41 & V_89 ;
V_50 -> V_57 = V_38 -> V_39 & V_43 ;
V_50 -> V_51 = V_38 -> V_39 & V_47 ;
V_50 -> V_58 = V_38 -> V_41 & V_90 ;
V_50 -> V_59 = V_38 -> V_41 & V_91 ;
V_50 -> V_60 = V_38 -> V_41 & V_92 ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_93 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_93 ) ;
}
