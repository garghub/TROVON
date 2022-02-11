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
if ( V_2 -> V_20 )
F_3 ( V_2 , V_21 , V_22 ) ;
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
static T_1 F_11 ( struct V_1 * V_2 , T_1 * V_23 )
{
T_1 V_24 , V_25 ;
T_1 V_26 = 0 ;
V_24 = F_2 ( V_2 , V_27 ) ;
V_24 &= V_28 ;
if ( ! V_24 ) {
* V_23 = 0 ;
return 0 ;
}
V_25 = F_2 ( V_2 , V_29 ) ;
* V_23 = V_25 ;
if ( V_24 & V_30 )
V_26 |= V_31 ;
if ( V_24 & V_32 )
V_26 |= V_33 ;
if ( V_24 & V_34 )
V_26 |= V_35 ;
if ( V_24 & V_36 )
V_26 |= V_37 ;
if ( V_24 & V_38 )
V_26 |= V_39 ;
F_3 ( V_2 , V_24 , V_27 ) ;
return V_26 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
V_41 -> V_42 = F_2 ( V_2 , V_43 ) ;
V_41 -> V_44 = F_2 ( V_2 , V_45 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
F_3 ( V_2 , V_41 -> V_42 | V_46 , V_47 ) ;
F_3 ( V_2 , V_41 -> V_44 , V_48 ) ;
}
static T_1 F_14 ( struct V_40 * V_41 )
{
T_1 V_49 = V_41 -> V_42 & V_50 ;
T_1 V_51 = F_15 ( V_41 -> V_42 & V_49 ) ;
return V_41 -> V_42 & V_51 ;
}
static struct V_40 * F_16 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_40 * V_41 ;
if ( V_53 -> V_25 & ~ ( F_15 ( V_53 -> V_54 ) ) ) {
F_17 ( V_2 -> V_17 , L_3 , V_55 ,
V_53 -> V_25 ) ;
return F_18 ( - V_15 ) ;
}
V_41 = F_19 ( sizeof( * V_41 ) , V_56 ) ;
if ( ! V_41 )
return F_18 ( - V_57 ) ;
V_41 -> V_42 = ( V_53 -> V_25 & V_58 ) | V_53 -> V_59 | V_53 -> V_54 | V_53 -> V_60 ;
V_41 -> V_44 = V_53 -> V_12 | V_53 -> V_61 | V_53 -> V_62 | V_53 -> V_63 ;
return V_41 ;
}
static inline int F_20 ( struct V_40 * V_41 )
{
return V_41 -> V_42 & V_46 ;
}
static T_1 F_21 ( struct V_52 * V_53 )
{
T_1 V_64 ;
V_64 = V_53 -> V_63 << 5 ;
V_64 |= V_53 -> V_61 ;
V_64 |= V_53 -> V_62 >> 3 ;
V_64 <<= ( ( ( V_53 -> V_54 == V_65 ) ||
( V_53 -> V_54 == V_66 ) ) ? 0 : 6 ) ;
return V_64 ;
}
static T_2
F_22 ( struct V_1 * V_2 , struct V_40 * V_41 , char * V_67 )
{
char * V_68 = V_67 ;
V_68 += sprintf ( V_68 , L_4 , V_41 -> V_42 , V_41 -> V_44 ,
( V_41 -> V_42 & V_69 ) ? 1 : 0 ) ;
return V_68 - V_67 ;
}
static T_2
F_23 ( struct V_1 * V_2 , char * V_67 , T_2 V_70 )
{
char * V_68 = V_67 ;
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
F_24 ( V_84 ) ;
F_24 ( V_85 ) ;
F_24 ( V_86 ) ;
V_87:
return V_68 - V_67 ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_88 ;
T_1 * V_68 = V_2 -> V_89 ;
for ( V_88 = 0 ; V_88 < ( V_90 / sizeof( T_1 ) ) ; V_88 ++ ) {
V_68 [ V_88 ] = F_2 ( V_2 , V_88 * sizeof( T_1 ) ) ;
F_9 ( V_2 -> V_17 , L_5 , V_55 , V_88 , V_68 [ V_88 ] ) ;
}
F_26 ( V_68 [ 0 ] != V_91 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_88 ;
T_1 * V_68 = V_2 -> V_89 ;
for ( V_88 = 0 ; V_88 < ( V_90 / sizeof( T_1 ) ) ; V_88 ++ ) {
F_3 ( V_2 , V_68 [ V_88 ] , V_88 * sizeof( T_1 ) ) ;
F_9 ( V_2 -> V_17 , L_5 , V_55 , V_88 , V_68 [ V_88 ] ) ;
}
F_26 ( V_68 [ 0 ] != V_91 ) ;
}
static void F_28 ( struct V_40 * V_41 , struct V_52 * V_53 )
{
V_53 -> V_25 = V_41 -> V_42 & V_58 ;
V_53 -> V_12 = V_41 -> V_44 & V_92 ;
V_53 -> V_60 = V_41 -> V_42 & V_46 ;
V_53 -> V_54 = V_41 -> V_42 & V_50 ;
V_53 -> V_61 = V_41 -> V_44 & V_93 ;
V_53 -> V_62 = V_41 -> V_44 & V_94 ;
V_53 -> V_63 = V_41 -> V_44 & V_95 ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_96 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_96 ) ;
}
