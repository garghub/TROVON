static T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 , V_3 , & V_4 , 1 ) ;
return ( T_1 ) V_5 << 32 | V_4 ;
}
static T_1 F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
T_3 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 , V_3 , & V_4 , 2 ) ;
return ( T_1 ) V_5 << 32 | F_4 ( V_4 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
T_4 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 , V_3 , & V_4 , 4 ) ;
return ( T_1 ) V_5 << 32 | F_6 ( V_4 ) ;
}
static T_4 F_7 ( T_4 V_6 , T_4 V_7 )
{
return V_6 / V_7 ;
}
static inline void F_8 ( int V_8 , T_4 V_9 , struct V_10 * V_11 )
{
if ( V_11 -> V_12 != NULL )
V_11 -> V_12 [ V_11 -> V_13 ] = V_9 | ( V_8 << 28 ) ;
V_11 -> V_13 ++ ;
}
static inline void F_9 ( T_4 V_9 , struct V_10 * V_11 )
{
F_8 ( V_14 , V_9 , V_11 ) ;
}
static T_3 F_10 ( struct V_10 * V_11 )
{
T_3 V_4 = 0 ;
if ( ( V_11 -> V_15 -> V_16 > 1 ) ||
( V_11 -> V_15 -> V_17 [ 0 ] . V_18 == V_19 ) )
V_4 |= 1 << V_20 ;
#ifdef F_11
V_4 |= ( 1 << V_21 ) | ( 1 << V_22 ) | ( 1 << V_23 ) | ( 1 << V_24 ) ;
#else
if ( V_11 -> V_25 & V_26 )
V_4 |= 1 << V_23 ;
#endif
if ( V_11 -> V_25 & ( V_27 | V_28 ) )
V_4 |= 1 << V_29 ;
if ( V_11 -> V_25 & V_27 )
V_4 |= ( 1 << V_30 ) | ( 1 << V_31 ) ;
if ( V_11 -> V_25 & V_32 )
V_4 |= 1 << V_33 ;
return V_4 ;
}
static inline int F_12 ( struct V_10 * V_11 )
{
return F_13 ( V_11 -> V_25 & V_34 ) ;
}
static inline bool F_14 ( T_3 V_9 )
{
switch ( V_9 ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
return true ;
default:
return false ;
}
}
static void F_15 ( struct V_10 * V_11 )
{
T_3 V_47 = F_10 ( V_11 ) ;
T_3 V_48 = V_11 -> V_15 -> V_17 [ 0 ] . V_18 ;
T_3 V_49 ;
#ifdef F_11
F_9 ( F_16 ( V_22 , V_50 ) , V_11 ) ;
F_9 ( F_17 ( V_47 ) , V_11 ) ;
F_9 ( F_18 ( V_21 , V_22 , 4 ) , V_11 ) ;
#else
if ( V_47 )
F_9 ( F_17 ( V_47 ) , V_11 ) ;
#endif
if ( V_11 -> V_25 & ( V_27 | V_28 ) )
F_9 ( F_16 ( V_29 , V_51 ) , V_11 ) ;
if ( V_11 -> V_25 & V_27 ) {
V_49 = F_19 ( struct V_1 , V_52 ) ;
F_9 ( F_20 ( V_30 , V_29 , V_49 ) , V_11 ) ;
V_49 = F_19 ( struct V_1 , V_16 ) ;
F_9 ( F_20 ( V_31 , V_29 , V_49 ) , V_11 ) ;
V_49 = F_19 ( struct V_1 , V_53 ) ;
F_9 ( F_20 ( V_54 , V_29 , V_49 ) , V_11 ) ;
F_9 ( F_21 ( V_31 , V_31 , V_54 ) , V_11 ) ;
}
if ( V_11 -> V_55 & V_56 )
F_9 ( F_22 ( V_33 , 0 ) , V_11 ) ;
if ( ( V_48 != V_57 ) && ! ( F_14 ( V_48 ) ) )
F_9 ( F_22 ( V_20 , 0 ) , V_11 ) ;
if ( V_11 -> V_25 & V_34 )
F_9 ( F_18 ( V_50 , V_50 , F_12 ( V_11 ) * 4 ) , V_11 ) ;
}
static void F_23 ( struct V_10 * V_11 )
{
T_3 V_47 = F_10 ( V_11 ) ;
if ( V_11 -> V_25 & V_34 )
F_9 ( F_24 ( V_50 , V_50 , F_12 ( V_11 ) * 4 ) , V_11 ) ;
V_47 &= ~ ( 1 << V_23 ) ;
#ifdef F_11
V_47 &= ~ ( 1 << V_22 ) ;
V_47 |= ( 1 << V_50 ) ;
F_9 ( F_25 ( V_50 , V_47 ) , V_11 ) ;
#else
if ( V_47 ) {
if ( V_11 -> V_25 & V_26 )
V_47 |= 1 << V_24 ;
F_9 ( F_26 ( V_47 ) , V_11 ) ;
}
if ( ! ( V_11 -> V_25 & V_26 ) )
F_9 ( F_27 ( V_23 ) , V_11 ) ;
#endif
}
static T_5 F_28 ( T_4 V_58 )
{
T_4 V_59 ;
for ( V_59 = 0 ; V_59 < 16 ; V_59 ++ )
if ( ( V_58 & ~ F_29 ( 0xff , 2 * V_59 ) ) == 0 )
return F_30 ( V_58 , 2 * V_59 ) | ( V_59 << 8 ) ;
return - 1 ;
}
static T_3 F_31 ( T_4 V_60 , struct V_10 * V_11 )
{
unsigned V_61 = 0 , V_3 ;
T_3 V_62 ;
if ( V_11 -> V_12 == NULL ) {
V_11 -> V_63 ++ ;
return 0 ;
}
while ( ( V_61 < V_11 -> V_63 ) && V_11 -> V_64 [ V_61 ] ) {
if ( V_11 -> V_64 [ V_61 ] == V_60 )
break;
V_61 ++ ;
}
if ( V_11 -> V_64 [ V_61 ] == 0 )
V_11 -> V_64 [ V_61 ] = V_60 ;
V_3 = V_11 -> V_65 [ V_11 -> V_15 -> V_16 ] ;
V_3 += V_11 -> V_66 ;
V_3 += V_11 -> V_67 ;
V_3 += V_61 * 4 ;
V_11 -> V_12 [ V_3 / 4 ] = V_60 ;
V_62 = V_3 - ( 8 + V_11 -> V_13 * 4 ) ;
return V_62 ;
}
static inline void F_32 ( int V_68 , T_4 V_69 , struct V_10 * V_11 )
{
#if V_70 < 7
F_9 ( F_20 ( V_68 , V_24 , F_31 ( V_69 , V_11 ) ) , V_11 ) ;
#else
F_9 ( F_33 ( V_68 , V_69 & 0xffff ) , V_11 ) ;
if ( V_69 > 0xffff )
F_9 ( F_34 ( V_68 , V_69 >> 16 ) , V_11 ) ;
#endif
}
static inline void F_35 ( int V_68 , T_4 V_69 , struct V_10 * V_11 )
{
int V_71 = F_28 ( V_69 ) ;
if ( V_71 >= 0 )
F_9 ( F_22 ( V_68 , V_71 ) , V_11 ) ;
else
F_32 ( V_68 , V_69 , V_11 ) ;
}
static void F_36 ( T_2 V_8 , T_2 V_72 , T_2 V_73 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_37 ( V_74 , V_73 , 1 ) , V_11 ) ;
F_8 ( V_8 , F_37 ( V_75 , V_73 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_37 ( V_76 , V_73 , 3 ) , V_11 ) ;
F_8 ( V_8 , F_38 ( V_74 , V_74 , 16 ) , V_11 ) ;
F_8 ( V_8 , F_37 ( V_51 , V_73 , 2 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_74 , V_74 , V_75 , V_77 , 24 ) , V_11 ) ;
F_8 ( V_8 , F_40 ( V_74 , V_74 , V_76 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_72 , V_74 , V_51 , V_77 , 8 ) , V_11 ) ;
}
static void F_41 ( T_2 V_8 , T_2 V_72 , T_2 V_73 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_37 ( V_75 , V_73 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_37 ( V_76 , V_73 , 1 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_72 , V_76 , V_75 , V_77 , 8 ) , V_11 ) ;
}
static inline void F_42 ( T_2 V_78 , T_2 V_79 , struct V_10 * V_11 )
{
F_9 ( F_38 ( V_75 , V_79 , 8 ) , V_11 ) ;
F_9 ( F_39 ( V_78 , V_75 , V_79 , V_80 , 8 ) , V_11 ) ;
F_9 ( F_43 ( V_78 , V_78 , 0x8ff ) , V_11 ) ;
}
static void F_36 ( T_2 V_8 , T_2 V_72 , T_2 V_73 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_20 ( V_72 , V_73 , 0 ) , V_11 ) ;
#ifdef F_44
F_8 ( V_8 , F_45 ( V_72 , V_72 ) , V_11 ) ;
#endif
}
static void F_41 ( T_2 V_8 , T_2 V_72 , T_2 V_73 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_46 ( V_72 , V_73 , 0 ) , V_11 ) ;
#ifdef F_44
F_8 ( V_8 , F_47 ( V_72 , V_72 ) , V_11 ) ;
#endif
}
static inline void F_42 ( T_2 V_78 V_81 ,
T_2 V_79 V_81 ,
struct V_10 * V_11 V_81 )
{
#ifdef F_44
F_9 ( F_47 ( V_78 , V_79 ) , V_11 ) ;
#endif
}
static inline T_4 F_48 ( unsigned V_82 , struct V_10 * V_11 )
{
T_4 V_62 ;
if ( V_11 -> V_12 == NULL )
return 0 ;
V_62 = V_11 -> V_65 [ V_82 ] + V_11 -> V_66 - ( V_11 -> V_13 * 4 + 8 ) ;
return V_62 >> 2 ;
}
static inline void F_49 ( T_2 V_8 , struct V_10 * V_11 )
{
if ( V_11 -> V_83 >= 0 ) {
F_8 ( V_8 , F_50 ( F_48 ( V_11 -> V_83 , V_11 ) ) , V_11 ) ;
F_9 ( F_16 ( V_51 , V_51 ) , V_11 ) ;
} else {
F_8 ( V_8 , F_22 ( V_51 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_50 ( F_48 ( V_11 -> V_15 -> V_16 , V_11 ) ) , V_11 ) ;
}
}
static inline void F_51 ( T_2 V_84 , struct V_10 * V_11 )
{
#if V_70 < 5
F_9 ( F_16 ( V_23 , V_24 ) , V_11 ) ;
if ( V_85 & V_86 )
F_9 ( F_27 ( V_84 ) , V_11 ) ;
else
F_9 ( F_16 ( V_24 , V_84 ) , V_11 ) ;
#else
F_9 ( F_52 ( V_84 ) , V_11 ) ;
#endif
}
static inline void F_53 ( T_2 V_68 , T_2 V_87 , T_2 V_88 , struct V_10 * V_11 )
{
#if V_70 == 7
if ( V_85 & V_89 ) {
F_9 ( F_54 ( V_68 , V_87 , V_88 ) , V_11 ) ;
return;
}
#endif
if ( V_87 != V_51 )
F_9 ( F_16 ( V_51 , V_87 ) , V_11 ) ;
if ( V_88 != V_75 )
F_9 ( F_16 ( V_75 , V_88 ) , V_11 ) ;
V_11 -> V_25 |= V_26 ;
F_35 ( V_74 , ( T_4 ) F_7 , V_11 ) ;
F_51 ( V_74 , V_11 ) ;
if ( V_68 != V_51 )
F_9 ( F_16 ( V_68 , V_51 ) , V_11 ) ;
}
static inline void F_55 ( struct V_10 * V_11 )
{
if ( ! ( V_11 -> V_25 & V_32 ) )
V_11 -> V_55 |= V_56 ;
V_11 -> V_25 |= V_32 ;
}
static int F_56 ( struct V_10 * V_11 )
{
void * V_90 [] = { F_1 , F_3 , F_5 } ;
const struct V_91 * V_92 = V_11 -> V_15 ;
const struct V_93 * V_9 ;
unsigned V_61 , V_94 , V_49 , V_95 ;
int V_71 ;
T_4 V_60 ;
for ( V_61 = 0 ; V_61 < V_92 -> V_16 ; V_61 ++ ) {
V_9 = & ( V_92 -> V_17 [ V_61 ] ) ;
V_60 = V_9 -> V_60 ;
if ( V_11 -> V_12 == NULL )
V_11 -> V_65 [ V_61 ] = V_11 -> V_13 * 4 ;
switch ( V_9 -> V_18 ) {
case V_96 :
F_35 ( V_20 , V_60 , V_11 ) ;
break;
case V_35 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 , V_16 ) != 4 ) ;
F_9 ( F_20 ( V_20 , V_29 ,
F_19 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_97 :
V_11 -> V_25 |= F_59 ( V_60 ) ;
F_9 ( F_20 ( V_20 , V_50 , F_60 ( V_60 ) ) , V_11 ) ;
break;
case V_36 :
V_94 = 2 ;
goto V_98;
case V_37 :
V_94 = 1 ;
goto V_98;
case V_38 :
V_94 = 0 ;
V_98:
if ( ( int ) V_60 < 0 )
return - V_99 ;
F_35 ( V_100 , V_60 , V_11 ) ;
V_101:
V_11 -> V_25 |= V_27 | V_26 ;
if ( V_94 > 0 ) {
F_9 ( F_18 ( V_54 , V_31 ,
1 << V_94 ) , V_11 ) ;
F_9 ( F_61 ( V_54 , V_100 ) , V_11 ) ;
V_95 = V_102 ;
} else {
F_9 ( F_61 ( V_31 , V_100 ) , V_11 ) ;
V_95 = V_103 ;
}
F_8 ( V_95 , F_62 ( V_54 , V_100 , V_30 ) ,
V_11 ) ;
if ( V_94 == 0 )
F_8 ( V_95 , F_37 ( V_20 , V_54 , 0 ) ,
V_11 ) ;
else if ( V_94 == 1 )
F_41 ( V_95 , V_20 , V_54 , V_11 ) ;
else if ( V_94 == 2 )
F_36 ( V_95 , V_20 , V_54 , V_11 ) ;
F_8 ( V_95 , F_50 ( F_48 ( V_61 + 1 , V_11 ) ) , V_11 ) ;
F_35 ( V_74 , ( T_4 ) V_90 [ V_94 ] , V_11 ) ;
F_9 ( F_16 ( V_51 , V_29 ) , V_11 ) ;
F_51 ( V_74 , V_11 ) ;
F_9 ( F_63 ( V_75 , 0 ) , V_11 ) ;
F_49 ( V_104 , V_11 ) ;
F_9 ( F_16 ( V_20 , V_51 ) , V_11 ) ;
break;
case V_105 :
V_94 = 2 ;
goto V_106;
case V_107 :
V_94 = 1 ;
goto V_106;
case V_108 :
V_94 = 0 ;
V_106:
F_64 ( V_109 , V_100 , V_33 , V_60 , V_11 ) ;
goto V_101;
case V_110 :
V_11 -> V_25 |= V_32 ;
F_35 ( V_33 , V_60 , V_11 ) ;
break;
case V_111 :
V_11 -> V_25 |= V_32 | V_28 ;
F_9 ( F_20 ( V_33 , V_29 ,
F_19 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_112 :
V_11 -> V_25 |= V_32 | F_59 ( V_60 ) ;
F_9 ( F_20 ( V_33 , V_50 , F_60 ( V_60 ) ) , V_11 ) ;
break;
case V_113 :
V_11 -> V_25 |= V_32 | V_27 | V_26 ;
if ( ( int ) V_60 < 0 )
return - 1 ;
F_35 ( V_100 , V_60 , V_11 ) ;
F_9 ( F_61 ( V_31 , V_100 ) , V_11 ) ;
F_8 ( V_103 , F_65 ( V_51 , V_30 ,
V_75 ) , V_11 ) ;
F_8 ( V_103 , F_50 ( F_48 ( V_61 + 1 , V_11 ) - 2 ) , V_11 ) ;
F_9 ( F_16 ( V_51 , V_29 ) , V_11 ) ;
F_35 ( V_74 , ( T_4 ) F_1 , V_11 ) ;
F_51 ( V_74 , V_11 ) ;
F_9 ( F_63 ( V_75 , 0 ) , V_11 ) ;
F_49 ( V_104 , V_11 ) ;
F_9 ( F_66 ( V_33 , V_51 , 0x00f ) , V_11 ) ;
F_9 ( F_38 ( V_33 , V_33 , 2 ) , V_11 ) ;
break;
case V_114 :
V_11 -> V_25 |= F_59 ( V_60 ) ;
F_9 ( F_67 ( V_20 , V_50 , F_60 ( V_60 ) ) , V_11 ) ;
break;
case V_115 :
F_55 ( V_11 ) ;
V_11 -> V_25 |= F_59 ( V_60 ) ;
F_9 ( F_67 ( V_33 , V_50 , F_60 ( V_60 ) ) , V_11 ) ;
break;
case V_116 :
F_64 ( V_109 , V_20 , V_20 , V_60 , V_11 ) ;
break;
case V_117 :
F_55 ( V_11 ) ;
F_9 ( F_62 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_118 :
F_64 ( V_119 , V_20 , V_20 , V_60 , V_11 ) ;
break;
case V_120 :
F_55 ( V_11 ) ;
F_9 ( F_21 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_121 :
F_35 ( V_54 , V_60 , V_11 ) ;
F_9 ( F_68 ( V_20 , V_20 , V_54 ) , V_11 ) ;
break;
case V_122 :
F_55 ( V_11 ) ;
F_9 ( F_68 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_123 :
F_35 ( V_54 , V_60 , V_11 ) ;
F_9 ( F_69 ( V_54 , V_20 , V_20 , V_54 ) , V_11 ) ;
break;
case V_124 :
F_55 ( V_11 ) ;
F_9 ( F_63 ( V_33 , 0 ) , V_11 ) ;
F_49 ( V_125 , V_11 ) ;
F_53 ( V_20 , V_20 , V_33 , V_11 ) ;
break;
case V_126 :
F_64 ( V_127 , V_20 , V_20 , V_60 , V_11 ) ;
break;
case V_128 :
F_55 ( V_11 ) ;
F_9 ( F_40 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_129 :
F_64 ( V_130 , V_20 , V_20 , V_60 , V_11 ) ;
break;
case V_131 :
case V_132 :
F_55 ( V_11 ) ;
F_9 ( F_70 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_133 :
F_64 ( V_134 , V_20 , V_20 , V_60 , V_11 ) ;
break;
case V_135 :
F_55 ( V_11 ) ;
F_9 ( F_71 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_136 :
if ( F_72 ( V_60 > 31 ) )
return - 1 ;
F_9 ( F_38 ( V_20 , V_20 , V_60 ) , V_11 ) ;
break;
case V_137 :
F_55 ( V_11 ) ;
F_9 ( F_73 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_138 :
if ( F_72 ( V_60 > 31 ) )
return - 1 ;
F_9 ( F_74 ( V_20 , V_20 , V_60 ) , V_11 ) ;
break;
case V_139 :
F_55 ( V_11 ) ;
F_9 ( F_75 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_140 :
F_9 ( F_76 ( V_20 , V_20 , 0 ) , V_11 ) ;
break;
case V_141 :
F_9 ( F_50 ( F_48 ( V_61 + V_60 + 1 , V_11 ) ) , V_11 ) ;
break;
case V_142 :
V_95 = V_125 ;
goto V_143;
case V_144 :
V_95 = V_103 ;
goto V_143;
case V_145 :
V_95 = V_102 ;
V_143:
V_71 = F_28 ( V_60 ) ;
if ( V_71 < 0 ) {
F_32 ( V_54 , V_60 , V_11 ) ;
F_9 ( F_61 ( V_20 , V_54 ) , V_11 ) ;
} else {
F_9 ( F_63 ( V_20 , V_71 ) , V_11 ) ;
}
V_146:
if ( V_9 -> V_147 )
F_8 ( V_95 , F_50 ( F_48 ( V_61 + V_9 -> V_147 + 1 ,
V_11 ) ) , V_11 ) ;
if ( V_9 -> V_148 )
F_8 ( V_95 ^ 1 , F_50 ( F_48 ( V_61 + V_9 -> V_148 + 1 ,
V_11 ) ) , V_11 ) ;
break;
case V_149 :
V_95 = V_125 ;
goto V_150;
case V_151 :
V_95 = V_103 ;
goto V_150;
case V_152 :
V_95 = V_153 ;
V_150:
F_55 ( V_11 ) ;
F_9 ( F_61 ( V_20 , V_33 ) , V_11 ) ;
goto V_146;
case V_154 :
V_95 = V_104 ;
V_71 = F_28 ( V_60 ) ;
if ( V_71 < 0 ) {
F_32 ( V_54 , V_60 , V_11 ) ;
F_9 ( F_77 ( V_20 , V_54 ) , V_11 ) ;
} else {
F_9 ( F_78 ( V_20 , V_71 ) , V_11 ) ;
}
goto V_146;
case V_155 :
F_55 ( V_11 ) ;
V_95 = V_104 ;
F_9 ( F_77 ( V_20 , V_33 ) , V_11 ) ;
goto V_146;
case V_19 :
F_9 ( F_16 ( V_51 , V_20 ) , V_11 ) ;
goto V_156;
case V_57 :
if ( ( V_60 == 0 ) && ( V_11 -> V_83 < 0 ) )
V_11 -> V_83 = V_61 ;
F_35 ( V_51 , V_60 , V_11 ) ;
V_156:
if ( V_61 != V_11 -> V_15 -> V_16 - 1 )
F_9 ( F_50 ( F_48 ( V_92 -> V_16 , V_11 ) ) , V_11 ) ;
break;
case V_157 :
V_11 -> V_25 |= V_32 ;
F_9 ( F_16 ( V_33 , V_20 ) , V_11 ) ;
break;
case V_158 :
F_55 ( V_11 ) ;
F_9 ( F_16 ( V_20 , V_33 ) , V_11 ) ;
break;
case V_42 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 ,
V_159 ) != 2 ) ;
V_49 = F_19 ( struct V_1 , V_159 ) ;
F_9 ( F_46 ( V_54 , V_29 , V_49 ) , V_11 ) ;
F_42 ( V_20 , V_54 , V_11 ) ;
break;
case V_39 :
F_64 ( V_160 , V_54 , V_50 , V_161 - 1 , V_11 ) ;
F_57 ( F_58 ( struct V_162 , V_163 ) != 4 ) ;
V_49 = F_19 ( struct V_162 , V_163 ) ;
F_9 ( F_20 ( V_20 , V_54 , V_49 ) , V_11 ) ;
break;
case V_40 :
V_11 -> V_25 |= V_28 ;
V_49 = F_19 ( struct V_1 , V_164 ) ;
F_9 ( F_20 ( V_54 , V_29 , V_49 ) , V_11 ) ;
F_9 ( F_63 ( V_54 , 0 ) , V_11 ) ;
F_49 ( V_125 , V_11 ) ;
F_57 ( F_58 ( struct V_165 ,
V_166 ) != 4 ) ;
V_49 = F_19 ( struct V_165 , V_166 ) ;
F_9 ( F_20 ( V_20 , V_54 , V_49 ) , V_11 ) ;
break;
case V_41 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 , V_167 ) != 4 ) ;
V_49 = F_19 ( struct V_1 , V_167 ) ;
F_9 ( F_20 ( V_20 , V_29 , V_49 ) , V_11 ) ;
break;
case V_43 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 , V_168 ) != 4 ) ;
V_49 = F_19 ( struct V_1 , V_168 ) ;
F_9 ( F_20 ( V_20 , V_29 , V_49 ) , V_11 ) ;
break;
case V_44 :
case V_45 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 , V_169 ) != 2 ) ;
V_49 = F_19 ( struct V_1 , V_169 ) ;
F_9 ( F_46 ( V_20 , V_29 , V_49 ) , V_11 ) ;
if ( V_9 -> V_18 == V_44 )
F_64 ( V_134 , V_20 , V_20 , V_170 , V_11 ) ;
else
F_64 ( V_134 , V_20 , V_20 , V_171 , V_11 ) ;
break;
case V_46 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 ,
V_172 ) != 2 ) ;
F_57 ( F_19 ( struct V_1 ,
V_172 ) > 0xff ) ;
V_49 = F_19 ( struct V_1 , V_172 ) ;
F_9 ( F_46 ( V_20 , V_29 , V_49 ) , V_11 ) ;
break;
default:
return - 1 ;
}
}
if ( V_11 -> V_12 == NULL )
V_11 -> V_65 [ V_61 ] = V_11 -> V_13 * 4 ;
return 0 ;
}
void F_79 ( struct V_91 * V_173 )
{
struct V_10 V_11 ;
unsigned V_174 ;
unsigned V_175 ;
if ( ! V_176 )
return;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_15 = V_173 ;
V_11 . V_83 = - 1 ;
V_11 . V_65 = F_80 ( 4 * ( V_11 . V_15 -> V_16 + 1 ) , V_177 ) ;
if ( V_11 . V_65 == NULL )
return;
if ( F_72 ( F_56 ( & V_11 ) ) )
goto V_178;
V_174 = V_11 . V_13 ;
F_15 ( & V_11 ) ;
V_11 . V_66 = ( V_11 . V_13 - V_174 ) * 4 ;
#if V_70 < 7
V_174 = V_11 . V_13 ;
F_23 ( & V_11 ) ;
V_11 . V_67 = ( V_11 . V_13 - V_174 ) * 4 ;
V_11 . V_13 += V_11 . V_63 ;
if ( V_11 . V_63 ) {
V_11 . V_64 = F_80 ( 4 * V_11 . V_63 , V_177 ) ;
if ( V_11 . V_64 == NULL )
goto V_178;
}
#else
F_23 ( & V_11 ) ;
#endif
V_175 = 4 * V_11 . V_13 ;
V_11 . V_12 = F_81 ( F_82 ( sizeof( struct V_179 ) ,
V_175 ) ) ;
if ( F_72 ( V_11 . V_12 == NULL ) )
goto V_178;
V_11 . V_13 = 0 ;
F_15 ( & V_11 ) ;
F_56 ( & V_11 ) ;
F_23 ( & V_11 ) ;
F_83 ( ( T_4 ) V_11 . V_12 , ( T_4 ) ( V_11 . V_12 + V_11 . V_13 ) ) ;
#if V_70 < 7
if ( V_11 . V_63 )
F_84 ( V_11 . V_64 ) ;
#endif
if ( V_176 > 1 )
F_85 ( V_180 , L_1 ,
V_181 , 16 , 4 , V_11 . V_12 ,
V_175 , false ) ;
V_173 -> V_182 = ( void * ) V_11 . V_12 ;
V_178:
F_84 ( V_11 . V_65 ) ;
return;
}
static void F_86 ( struct V_179 * V_183 )
{
F_87 ( NULL , V_183 ) ;
}
void F_88 ( struct V_91 * V_173 )
{
struct V_179 * V_183 ;
if ( V_173 -> V_182 != V_184 ) {
V_183 = (struct V_179 * ) V_173 -> V_182 ;
F_89 ( V_183 , F_86 ) ;
F_90 ( V_183 ) ;
}
}
