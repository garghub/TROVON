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
unsigned long V_13 ;
if ( ! V_2 -> V_14 || ! F_5 ( ( T_1 ) V_2 -> V_14 , V_15 ) )
return - V_16 ;
V_12 = F_6 ( V_2 -> V_14 ) ;
if ( ! F_5 ( V_12 , V_15 ) )
return - V_16 ;
F_3 ( V_2 , V_17 , V_18 ) ;
V_13 = V_19 + F_7 ( 20 ) ;
do {
V_4 = F_2 ( V_2 , V_20 ) ;
if ( V_4 & V_21 )
break;
} while ( ! F_8 ( V_19 , V_13 ) );
if ( ! ( V_4 & V_21 ) ) {
F_9 ( V_2 -> V_22 , L_1 ) ;
return - V_23 ;
}
V_4 = F_2 ( V_2 , V_24 ) ;
F_10 ( V_2 -> V_22 , L_2 , V_2 -> V_25 ,
( V_4 >> 4 ) & 0xf , V_4 & 0xf ) ;
V_4 = F_2 ( V_2 , V_18 ) ;
V_4 &= ~ V_26 ;
V_4 |= ( V_27 | V_28 ) ;
F_3 ( V_2 , V_4 , V_18 ) ;
F_3 ( V_2 , V_12 , V_29 ) ;
F_1 ( V_2 , true ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_4 = F_2 ( V_2 , V_5 ) ;
V_4 &= ~ V_9 ;
F_3 ( V_2 , V_4 , V_5 ) ;
F_3 ( V_2 , V_30 , V_18 ) ;
F_12 ( V_2 -> V_22 , L_3 , V_2 -> V_25 ) ;
}
static void F_13 ( struct V_1 * V_2 , bool V_3 )
{
F_1 ( V_2 , false ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_1 * V_31 )
{
T_1 V_32 , V_33 ;
T_1 V_34 = 0 ;
V_32 = F_2 ( V_2 , V_35 ) ;
V_32 &= V_36 ;
if ( ! V_32 ) {
* V_31 = 0 ;
return 0 ;
}
V_33 = F_2 ( V_2 , V_37 ) ;
* V_31 = V_33 ;
if ( V_32 & V_38 )
V_34 |= V_39 ;
if ( V_32 & V_40 )
V_34 |= V_41 ;
if ( V_32 & V_42 )
V_34 |= V_43 ;
if ( V_32 & V_44 )
V_34 |= V_45 ;
if ( V_32 & V_46 )
V_34 |= V_47 ;
F_3 ( V_2 , V_32 , V_35 ) ;
return V_34 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
V_49 -> V_50 = F_2 ( V_2 , V_51 ) ;
V_49 -> V_52 = F_2 ( V_2 , V_53 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
F_3 ( V_2 , V_49 -> V_50 | V_54 , V_55 ) ;
F_3 ( V_2 , V_49 -> V_52 , V_56 ) ;
}
static T_1 F_17 ( struct V_48 * V_49 )
{
T_1 V_57 = V_49 -> V_50 & V_58 ;
T_1 V_59 = F_18 ( V_49 -> V_50 & V_57 ) ;
return V_49 -> V_50 & V_59 ;
}
static struct V_48 * F_19 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_48 * V_49 ;
if ( V_61 -> V_33 & ~ ( F_18 ( V_61 -> V_62 ) ) ) {
F_9 ( V_2 -> V_22 , L_4 , V_63 ,
V_61 -> V_33 ) ;
return F_20 ( - V_16 ) ;
}
V_49 = F_21 ( sizeof( * V_49 ) , V_64 ) ;
if ( ! V_49 )
return F_20 ( - V_65 ) ;
V_49 -> V_50 = ( V_61 -> V_33 & V_66 ) | V_61 -> V_67 | V_61 -> V_62 | V_61 -> V_68 ;
V_49 -> V_52 = V_61 -> V_12 | V_61 -> V_69 | V_61 -> V_70 | V_61 -> V_71 ;
return V_49 ;
}
static inline int F_22 ( struct V_48 * V_49 )
{
return V_49 -> V_50 & V_54 ;
}
static T_1 F_23 ( struct V_60 * V_61 )
{
T_1 V_72 ;
V_72 = V_61 -> V_71 << 5 ;
V_72 |= V_61 -> V_69 ;
V_72 |= V_61 -> V_70 >> 3 ;
V_72 <<= ( ( V_61 -> V_62 & V_73 ) ? 0 : 6 ) ;
return V_72 ;
}
static T_2 F_24 ( struct V_1 * V_2 , struct V_48 * V_49 , char * V_74 )
{
char * V_75 = V_74 ;
V_75 += sprintf ( V_75 , L_5 , V_49 -> V_50 , V_49 -> V_52 ,
( V_49 -> V_50 & V_76 ) ? 1 : 0 ) ;
return V_75 - V_74 ;
}
static T_2 F_25 ( struct V_1 * V_2 , char * V_74 , T_2 V_77 )
{
char * V_75 = V_74 ;
F_26 ( V_78 ) ;
F_26 ( V_79 ) ;
F_26 ( V_80 ) ;
F_26 ( V_81 ) ;
F_26 ( V_82 ) ;
F_26 ( V_83 ) ;
F_26 ( V_84 ) ;
F_26 ( V_85 ) ;
F_26 ( V_86 ) ;
F_26 ( V_87 ) ;
F_26 ( V_88 ) ;
F_26 ( V_89 ) ;
F_26 ( V_90 ) ;
F_26 ( V_91 ) ;
F_26 ( V_92 ) ;
F_26 ( V_93 ) ;
F_26 ( V_94 ) ;
F_26 ( V_95 ) ;
V_96:
return V_75 - V_74 ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_97 ;
T_1 * V_75 = V_2 -> V_98 ;
for ( V_97 = 0 ; V_97 < ( V_99 / sizeof( T_1 ) ) ; V_97 ++ ) {
V_75 [ V_97 ] = F_2 ( V_2 , V_97 * sizeof( T_1 ) ) ;
F_12 ( V_2 -> V_22 , L_6 , V_63 , V_97 , V_75 [ V_97 ] ) ;
}
F_28 ( V_75 [ 0 ] != V_100 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_97 ;
T_1 * V_75 = V_2 -> V_98 ;
for ( V_97 = 0 ; V_97 < ( V_99 / sizeof( T_1 ) ) ; V_97 ++ ) {
F_3 ( V_2 , V_75 [ V_97 ] , V_97 * sizeof( T_1 ) ) ;
F_12 ( V_2 -> V_22 , L_6 , V_63 , V_97 , V_75 [ V_97 ] ) ;
}
F_28 ( V_75 [ 0 ] != V_100 ) ;
}
static void F_30 ( struct V_48 * V_49 , struct V_60 * V_61 )
{
V_61 -> V_33 = V_49 -> V_50 & V_66 ;
V_61 -> V_12 = V_49 -> V_52 & V_101 ;
V_61 -> V_68 = V_49 -> V_50 & V_54 ;
V_61 -> V_62 = V_49 -> V_50 & V_58 ;
V_61 -> V_69 = V_49 -> V_52 & V_102 ;
V_61 -> V_70 = V_49 -> V_52 & V_103 ;
V_61 -> V_71 = V_49 -> V_52 & V_104 ;
}
static int T_3 F_31 ( void )
{
return F_32 ( & V_105 ) ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_105 ) ;
}
