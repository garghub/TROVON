static inline T_1 F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
return F_2 ( V_2 -> V_5 + V_4 + V_3 * V_6 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_1 V_7 )
{
F_4 ( V_7 , V_2 -> V_5 + V_4 + V_3 * V_6 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
int V_4 , T_1 V_7 )
{
F_4 ( V_7 , V_2 -> V_5 + V_4 ) ;
}
static void F_6 ( struct V_1 * V_8 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ )
F_5 ( V_8 , V_10 ,
V_11 << V_3 ) ;
F_5 ( V_8 , V_10 , V_12 ) ;
}
static int F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_8 ;
T_1 V_15 , V_16 ;
int V_3 ;
V_8 = F_8 ( V_14 -> V_17 ) ;
V_3 = V_14 -> V_18 ;
V_15 = F_9 ( V_8 -> V_19 , V_14 -> V_20 ) ;
if ( V_15 > V_21 )
V_15 = V_21 ;
else if ( V_15 < V_22 )
V_15 = V_22 ;
F_3 ( V_8 , V_3 , V_23 , V_15 ) ;
F_3 ( V_8 , V_3 , V_24 , V_25 ) ;
V_16 = F_1 ( V_8 , V_3 , V_26 ) ;
if ( V_14 -> V_27 & V_28 )
V_16 |= V_29 ;
else
V_16 &= ~ V_29 ;
if ( V_14 -> V_27 & V_30 )
V_16 |= V_31 ;
else
V_16 &= ~ V_31 ;
if ( ! ( V_14 -> V_27 & V_32 ) )
V_16 |= V_33 ;
else
V_16 &= ~ V_33 ;
if ( V_14 -> V_27 & V_34 )
V_16 |= V_35 ;
else
V_16 &= ~ V_35 ;
V_16 |= V_36 | V_37 ;
if ( V_15 == 4 )
V_16 |= V_38 ;
F_3 ( V_8 , V_3 , V_26 , V_16 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_8 )
{
T_1 V_39 , V_40 ;
int V_41 , V_42 , V_43 ;
V_40 = F_1 ( V_8 , V_8 -> V_3 , V_44 ) ;
V_40 &= V_45 ;
while ( V_40 ) {
V_39 = F_1 ( V_8 , V_8 -> V_3 , V_46 ) ;
V_42 = 0 ;
V_43 = F_11 ( V_8 -> V_47 , 4 ) ;
for ( V_41 = V_43 - 1 ; V_41 >= 0 ; V_41 -- , V_42 ++ )
V_8 -> V_48 [ V_41 ] = ( V_39 >> ( V_42 * 8 ) ) & 0xff ;
V_8 -> V_47 -= V_43 ;
V_8 -> V_48 += V_43 ;
V_40 -- ;
}
}
static void F_12 ( struct V_1 * V_8 )
{
T_1 V_49 , V_50 ;
int V_41 , V_42 , V_43 ;
V_50 = F_1 ( V_8 , V_8 -> V_3 , V_44 ) ;
V_50 &= V_51 ;
V_50 >>= V_52 ;
while ( V_8 -> V_53 && ( V_50 < V_54 ) ) {
V_42 = 0 ;
V_49 = 0 ;
V_43 = F_11 ( V_8 -> V_53 , 4 ) ;
for ( V_41 = V_43 - 1 ; V_41 >= 0 ; V_41 -- , V_42 ++ )
V_49 |= V_8 -> V_55 [ V_41 ] << ( V_42 * 8 ) ;
F_3 ( V_8 , V_8 -> V_3 , V_56 , V_49 ) ;
V_8 -> V_53 -= V_43 ;
V_8 -> V_55 += V_43 ;
V_50 ++ ;
}
}
static T_2 F_13 ( int V_57 , void * V_58 )
{
struct V_1 * V_8 = V_58 ;
T_1 V_59 ;
V_59 = F_1 ( V_8 , V_8 -> V_3 , V_60 ) &
V_61 ;
if ( ! V_59 )
return V_62 ;
if ( V_59 & V_63 ) {
if ( V_8 -> V_53 )
F_12 ( V_8 ) ;
if ( V_59 & V_64 )
V_8 -> V_65 ++ ;
}
if ( V_59 & V_66 ) {
if ( V_8 -> V_47 )
F_10 ( V_8 ) ;
if ( V_59 & V_67 )
V_8 -> V_68 ++ ;
}
F_3 ( V_8 , V_8 -> V_3 , V_60 , V_59 ) ;
if ( V_59 & V_69 )
F_14 ( & V_8 -> V_70 ) ;
return V_71 ;
}
static void F_15 ( struct V_1 * V_8 , int V_72 ,
int V_73 )
{
T_1 V_74 = 0 ;
if ( V_8 -> V_55 )
V_74 |= V_75 ;
if ( V_8 -> V_48 )
V_74 |= V_76 ;
if ( V_73 )
V_74 |= V_77 ;
V_74 |= ( ( V_72 * 8 - 1 ) << V_78 ) ;
F_3 ( V_8 , V_8 -> V_3 , V_79 , V_74 ) ;
}
static int F_16 ( struct V_1 * V_80 ,
const unsigned char * V_55 ,
unsigned char * V_48 , int V_72 , int V_73 )
{
int V_81 ;
T_1 V_82 = 0 ;
V_80 -> V_55 = V_55 ;
V_80 -> V_48 = V_48 ;
V_80 -> V_53 = ( V_80 -> V_55 == NULL ) ? 0 : V_72 ;
V_80 -> V_47 = ( V_80 -> V_48 == NULL ) ? 0 : V_72 ;
V_80 -> V_65 = V_80 -> V_68 = 0 ;
if ( V_80 -> V_53 )
F_12 ( V_80 ) ;
F_15 ( V_80 , V_72 , V_73 ) ;
if ( V_80 -> V_53 )
V_82 |= V_83 | V_84 |
V_85 | V_86 ;
else
V_82 |= V_85 | V_86 ;
V_82 |= V_87 ;
F_3 ( V_80 , V_80 -> V_3 , V_88 , V_82 ) ;
V_81 = F_17 ( & V_80 -> V_70 ,
F_18 ( 1000 ) ) ;
F_3 ( V_80 , V_80 -> V_3 , V_88 , 0x0 ) ;
if ( ! V_81 ) {
F_19 ( & V_80 -> V_89 , L_1 ) ;
goto V_90;
}
if ( V_80 -> V_65 || V_80 -> V_68 )
F_19 ( & V_80 -> V_89 , L_2 ,
V_80 -> V_68 , V_80 -> V_65 , V_72 ) ;
return V_72 ;
V_90:
return - V_91 ;
}
static int F_20 ( struct V_1 * V_80 , struct V_92 * V_93 )
{
int V_94 , V_95 ;
unsigned char * V_48 ;
const unsigned char * V_55 ;
V_55 = V_93 -> V_55 ;
V_48 = V_93 -> V_48 ;
V_94 = V_93 -> V_96 ;
while ( V_94 ) {
if ( V_94 > V_97 )
V_95 = F_16 ( V_80 , V_55 , V_48 ,
V_97 , 1 ) ;
else
V_95 = F_16 ( V_80 , V_55 , V_48 ,
V_94 , V_80 -> V_73 ) ;
if ( V_95 < 0 )
return V_95 ;
V_94 -= V_95 ;
if ( V_55 )
V_55 += V_95 ;
if ( V_48 )
V_48 += V_95 ;
}
return V_94 ;
}
static int F_21 ( struct V_98 * V_17 ,
struct V_13 * V_14 ,
struct V_92 * V_93 )
{
struct V_1 * V_8 = F_8 ( V_17 ) ;
int V_99 = 0 ;
V_8 -> V_3 = V_14 -> V_18 ;
V_8 -> V_89 = V_14 -> V_89 ;
if ( F_22 ( V_17 , V_93 ) )
V_8 -> V_73 = 0 ;
else
V_8 -> V_73 = 1 ;
if ( F_20 ( V_8 , V_93 ) )
V_99 = - V_100 ;
F_23 ( V_17 ) ;
return V_99 ;
}
static int F_24 ( struct V_101 * V_102 )
{
struct V_98 * V_17 ;
struct V_1 * V_8 ;
struct V_103 * V_104 ;
struct V_105 * V_105 ;
int V_57 , V_106 ;
V_8 = F_25 ( & V_102 -> V_89 , sizeof( * V_8 ) , V_107 ) ;
if ( ! V_8 )
return - V_108 ;
V_104 = F_26 ( V_102 , V_109 , 0 ) ;
V_8 -> V_5 = F_27 ( & V_102 -> V_89 , V_104 ) ;
if ( F_28 ( V_8 -> V_5 ) )
return F_29 ( V_8 -> V_5 ) ;
V_57 = F_30 ( V_102 , 0 ) ;
if ( V_57 < 0 ) {
F_19 ( & V_102 -> V_89 , L_3 , V_57 ) ;
return V_57 ;
}
V_106 = F_31 ( & V_102 -> V_89 , V_57 , F_13 , 0 ,
V_102 -> V_110 , V_8 ) ;
if ( V_106 ) {
F_19 ( & V_102 -> V_89 , L_4 , V_57 ) ;
return V_106 ;
}
V_105 = F_32 ( & V_102 -> V_89 , NULL ) ;
if ( F_28 ( V_105 ) ) {
F_19 ( & V_102 -> V_89 , L_5 ) ;
return F_29 ( V_105 ) ;
}
V_8 -> V_19 = F_33 ( V_105 ) ;
V_17 = F_34 ( & V_102 -> V_89 , 0 ) ;
if ( ! V_17 ) {
F_19 ( & V_102 -> V_89 , L_6 ) ;
return - V_108 ;
}
V_17 -> V_111 = 0 ;
V_17 -> V_112 = V_9 ;
V_17 -> V_113 = V_30 | V_28 | V_32 ;
V_17 -> V_114 = F_7 ;
V_17 -> V_115 = F_21 ;
V_17 -> V_89 . V_116 = V_102 -> V_89 . V_116 ;
F_35 ( & V_8 -> V_70 ) ;
F_36 ( V_17 , V_8 ) ;
F_6 ( V_8 ) ;
V_106 = F_37 ( & V_102 -> V_89 , V_17 ) ;
if ( V_106 ) {
F_19 ( & V_102 -> V_89 , L_7 ) ;
F_38 ( V_17 ) ;
return V_106 ;
}
return 0 ;
}
