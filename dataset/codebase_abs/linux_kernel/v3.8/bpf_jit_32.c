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
F_9 ( F_43 ( V_75 , V_79 , 8 ) , V_11 ) ;
F_9 ( F_39 ( V_78 , V_75 , V_79 , V_77 , 8 ) , V_11 ) ;
F_9 ( F_38 ( V_78 , V_78 , 8 ) , V_11 ) ;
F_9 ( F_43 ( V_78 , V_78 , 8 ) , V_11 ) ;
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
static inline void F_42 ( T_2 V_78 V_80 ,
T_2 V_79 V_80 ,
struct V_10 * V_11 V_80 )
{
#ifdef F_44
F_9 ( F_47 ( V_78 , V_79 ) , V_11 ) ;
#endif
}
static inline T_4 F_48 ( unsigned V_81 , struct V_10 * V_11 )
{
T_4 V_62 ;
if ( V_11 -> V_12 == NULL )
return 0 ;
V_62 = V_11 -> V_65 [ V_81 ] + V_11 -> V_66 - ( V_11 -> V_13 * 4 + 8 ) ;
return V_62 >> 2 ;
}
static inline void F_49 ( T_2 V_8 , struct V_10 * V_11 )
{
if ( V_11 -> V_82 >= 0 ) {
F_8 ( V_8 , F_50 ( F_48 ( V_11 -> V_82 , V_11 ) ) , V_11 ) ;
F_9 ( F_16 ( V_51 , V_51 ) , V_11 ) ;
} else {
F_8 ( V_8 , F_22 ( V_51 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_50 ( F_48 ( V_11 -> V_15 -> V_16 , V_11 ) ) , V_11 ) ;
}
}
static inline void F_51 ( T_2 V_83 , struct V_10 * V_11 )
{
#if V_70 < 5
F_9 ( F_16 ( V_23 , V_24 ) , V_11 ) ;
if ( V_84 & V_85 )
F_9 ( F_27 ( V_83 ) , V_11 ) ;
else
F_9 ( F_16 ( V_24 , V_83 ) , V_11 ) ;
#else
F_9 ( F_52 ( V_83 ) , V_11 ) ;
#endif
}
static inline void F_53 ( T_2 V_68 , T_2 V_86 , T_2 V_87 , struct V_10 * V_11 )
{
#if V_70 == 7
if ( V_84 & V_88 ) {
F_9 ( F_54 ( V_68 , V_86 , V_87 ) , V_11 ) ;
return;
}
#endif
if ( V_86 != V_51 )
F_9 ( F_16 ( V_51 , V_86 ) , V_11 ) ;
if ( V_87 != V_75 )
F_9 ( F_16 ( V_75 , V_87 ) , V_11 ) ;
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
void * V_89 [] = { F_1 , F_3 , F_5 } ;
const struct V_90 * V_91 = V_11 -> V_15 ;
const struct V_92 * V_9 ;
unsigned V_61 , V_93 , V_49 , V_94 ;
int V_71 ;
T_4 V_60 ;
for ( V_61 = 0 ; V_61 < V_91 -> V_16 ; V_61 ++ ) {
V_9 = & ( V_91 -> V_17 [ V_61 ] ) ;
V_60 = V_9 -> V_60 ;
if ( V_11 -> V_12 == NULL )
V_11 -> V_65 [ V_61 ] = V_11 -> V_13 * 4 ;
switch ( V_9 -> V_18 ) {
case V_95 :
F_35 ( V_20 , V_60 , V_11 ) ;
break;
case V_35 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 , V_16 ) != 4 ) ;
F_9 ( F_20 ( V_20 , V_29 ,
F_19 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_96 :
V_11 -> V_25 |= F_59 ( V_60 ) ;
F_9 ( F_20 ( V_20 , V_50 , F_60 ( V_60 ) ) , V_11 ) ;
break;
case V_36 :
V_93 = 2 ;
goto V_97;
case V_37 :
V_93 = 1 ;
goto V_97;
case V_38 :
V_93 = 0 ;
V_97:
if ( ( int ) V_60 < 0 )
return - V_98 ;
F_35 ( V_99 , V_60 , V_11 ) ;
V_100:
V_11 -> V_25 |= V_27 | V_26 ;
if ( V_93 > 0 ) {
F_9 ( F_18 ( V_54 , V_31 ,
1 << V_93 ) , V_11 ) ;
F_9 ( F_61 ( V_54 , V_99 ) , V_11 ) ;
V_94 = V_101 ;
} else {
F_9 ( F_61 ( V_31 , V_99 ) , V_11 ) ;
V_94 = V_102 ;
}
F_8 ( V_94 , F_62 ( V_54 , V_99 , V_30 ) ,
V_11 ) ;
if ( V_93 == 0 )
F_8 ( V_94 , F_37 ( V_20 , V_54 , 0 ) ,
V_11 ) ;
else if ( V_93 == 1 )
F_41 ( V_94 , V_20 , V_54 , V_11 ) ;
else if ( V_93 == 2 )
F_36 ( V_94 , V_20 , V_54 , V_11 ) ;
F_8 ( V_94 , F_50 ( F_48 ( V_61 + 1 , V_11 ) ) , V_11 ) ;
F_35 ( V_74 , ( T_4 ) V_89 [ V_93 ] , V_11 ) ;
F_9 ( F_16 ( V_51 , V_29 ) , V_11 ) ;
F_51 ( V_74 , V_11 ) ;
F_9 ( F_63 ( V_75 , 0 ) , V_11 ) ;
F_49 ( V_103 , V_11 ) ;
F_9 ( F_16 ( V_20 , V_51 ) , V_11 ) ;
break;
case V_104 :
V_93 = 2 ;
goto V_105;
case V_106 :
V_93 = 1 ;
goto V_105;
case V_107 :
V_93 = 0 ;
V_105:
F_64 ( V_108 , V_99 , V_33 , V_60 , V_11 ) ;
goto V_100;
case V_109 :
V_11 -> V_25 |= V_32 ;
F_35 ( V_33 , V_60 , V_11 ) ;
break;
case V_110 :
V_11 -> V_25 |= V_32 | V_28 ;
F_9 ( F_20 ( V_33 , V_29 ,
F_19 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_111 :
V_11 -> V_25 |= V_32 | F_59 ( V_60 ) ;
F_9 ( F_20 ( V_33 , V_50 , F_60 ( V_60 ) ) , V_11 ) ;
break;
case V_112 :
V_11 -> V_25 |= V_32 | V_27 | V_26 ;
if ( V_60 < 0 )
return - 1 ;
F_35 ( V_99 , V_60 , V_11 ) ;
F_9 ( F_61 ( V_31 , V_99 ) , V_11 ) ;
F_8 ( V_102 , F_65 ( V_51 , V_30 ,
V_75 ) , V_11 ) ;
F_8 ( V_102 , F_50 ( F_48 ( V_61 + 1 , V_11 ) - 2 ) , V_11 ) ;
F_9 ( F_16 ( V_51 , V_29 ) , V_11 ) ;
F_35 ( V_74 , ( T_4 ) F_1 , V_11 ) ;
F_51 ( V_74 , V_11 ) ;
F_9 ( F_63 ( V_75 , 0 ) , V_11 ) ;
F_49 ( V_103 , V_11 ) ;
F_9 ( F_66 ( V_33 , V_51 , 0x00f ) , V_11 ) ;
F_9 ( F_38 ( V_33 , V_33 , 2 ) , V_11 ) ;
break;
case V_113 :
V_11 -> V_25 |= F_59 ( V_60 ) ;
F_9 ( F_67 ( V_20 , V_50 , F_60 ( V_60 ) ) , V_11 ) ;
break;
case V_114 :
F_55 ( V_11 ) ;
V_11 -> V_25 |= F_59 ( V_60 ) ;
F_9 ( F_67 ( V_33 , V_50 , F_60 ( V_60 ) ) , V_11 ) ;
break;
case V_115 :
F_64 ( V_108 , V_20 , V_20 , V_60 , V_11 ) ;
break;
case V_116 :
F_55 ( V_11 ) ;
F_9 ( F_62 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_117 :
F_64 ( V_118 , V_20 , V_20 , V_60 , V_11 ) ;
break;
case V_119 :
F_55 ( V_11 ) ;
F_9 ( F_21 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_120 :
F_35 ( V_54 , V_60 , V_11 ) ;
F_9 ( F_68 ( V_20 , V_20 , V_54 ) , V_11 ) ;
break;
case V_121 :
F_55 ( V_11 ) ;
F_9 ( F_68 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_122 :
F_35 ( V_54 , V_60 , V_11 ) ;
F_9 ( F_69 ( V_54 , V_20 , V_20 , V_54 ) , V_11 ) ;
break;
case V_123 :
F_55 ( V_11 ) ;
F_9 ( F_63 ( V_33 , 0 ) , V_11 ) ;
F_49 ( V_124 , V_11 ) ;
F_53 ( V_20 , V_20 , V_33 , V_11 ) ;
break;
case V_125 :
F_64 ( V_126 , V_20 , V_20 , V_60 , V_11 ) ;
break;
case V_127 :
F_55 ( V_11 ) ;
F_9 ( F_40 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_128 :
F_64 ( V_129 , V_20 , V_20 , V_60 , V_11 ) ;
break;
case V_130 :
case V_131 :
F_55 ( V_11 ) ;
F_9 ( F_70 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_132 :
F_64 ( V_133 , V_20 , V_20 , V_60 , V_11 ) ;
break;
case V_134 :
F_55 ( V_11 ) ;
F_9 ( F_71 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_135 :
if ( F_72 ( V_60 > 31 ) )
return - 1 ;
F_9 ( F_38 ( V_20 , V_20 , V_60 ) , V_11 ) ;
break;
case V_136 :
F_55 ( V_11 ) ;
F_9 ( F_43 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_137 :
if ( F_72 ( V_60 > 31 ) )
return - 1 ;
F_9 ( F_73 ( V_20 , V_20 , V_60 ) , V_11 ) ;
break;
case V_138 :
F_55 ( V_11 ) ;
F_9 ( F_74 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_139 :
F_9 ( F_75 ( V_20 , V_20 , 0 ) , V_11 ) ;
break;
case V_140 :
F_9 ( F_50 ( F_48 ( V_61 + V_60 + 1 , V_11 ) ) , V_11 ) ;
break;
case V_141 :
V_94 = V_124 ;
goto V_142;
case V_143 :
V_94 = V_102 ;
goto V_142;
case V_144 :
V_94 = V_101 ;
V_142:
V_71 = F_28 ( V_60 ) ;
if ( V_71 < 0 ) {
F_32 ( V_54 , V_60 , V_11 ) ;
F_9 ( F_61 ( V_20 , V_54 ) , V_11 ) ;
} else {
F_9 ( F_63 ( V_20 , V_71 ) , V_11 ) ;
}
V_145:
if ( V_9 -> V_146 )
F_8 ( V_94 , F_50 ( F_48 ( V_61 + V_9 -> V_146 + 1 ,
V_11 ) ) , V_11 ) ;
if ( V_9 -> V_147 )
F_8 ( V_94 ^ 1 , F_50 ( F_48 ( V_61 + V_9 -> V_147 + 1 ,
V_11 ) ) , V_11 ) ;
break;
case V_148 :
V_94 = V_124 ;
goto V_149;
case V_150 :
V_94 = V_102 ;
goto V_149;
case V_151 :
V_94 = V_152 ;
V_149:
F_55 ( V_11 ) ;
F_9 ( F_61 ( V_20 , V_33 ) , V_11 ) ;
goto V_145;
case V_153 :
V_94 = V_103 ;
V_71 = F_28 ( V_60 ) ;
if ( V_71 < 0 ) {
F_32 ( V_54 , V_60 , V_11 ) ;
F_9 ( F_76 ( V_20 , V_54 ) , V_11 ) ;
} else {
F_9 ( F_77 ( V_20 , V_71 ) , V_11 ) ;
}
goto V_145;
case V_154 :
F_55 ( V_11 ) ;
V_94 = V_103 ;
F_9 ( F_76 ( V_20 , V_33 ) , V_11 ) ;
goto V_145;
case V_19 :
F_9 ( F_16 ( V_51 , V_20 ) , V_11 ) ;
goto V_155;
case V_57 :
if ( ( V_60 == 0 ) && ( V_11 -> V_82 < 0 ) )
V_11 -> V_82 = V_61 ;
F_35 ( V_51 , V_60 , V_11 ) ;
V_155:
if ( V_61 != V_11 -> V_15 -> V_16 - 1 )
F_9 ( F_50 ( F_48 ( V_91 -> V_16 , V_11 ) ) , V_11 ) ;
break;
case V_156 :
V_11 -> V_25 |= V_32 ;
F_9 ( F_16 ( V_33 , V_20 ) , V_11 ) ;
break;
case V_157 :
F_55 ( V_11 ) ;
F_9 ( F_16 ( V_20 , V_33 ) , V_11 ) ;
break;
case V_42 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 ,
V_158 ) != 2 ) ;
V_49 = F_19 ( struct V_1 , V_158 ) ;
F_9 ( F_46 ( V_54 , V_29 , V_49 ) , V_11 ) ;
F_42 ( V_20 , V_54 , V_11 ) ;
break;
case V_39 :
F_64 ( V_159 , V_54 , V_50 , V_160 - 1 , V_11 ) ;
F_57 ( F_58 ( struct V_161 , V_162 ) != 4 ) ;
V_49 = F_19 ( struct V_161 , V_162 ) ;
F_9 ( F_20 ( V_20 , V_54 , V_49 ) , V_11 ) ;
break;
case V_40 :
V_11 -> V_25 |= V_28 ;
V_49 = F_19 ( struct V_1 , V_163 ) ;
F_9 ( F_20 ( V_54 , V_29 , V_49 ) , V_11 ) ;
F_9 ( F_63 ( V_54 , 0 ) , V_11 ) ;
F_49 ( V_124 , V_11 ) ;
F_57 ( F_58 ( struct V_164 ,
V_165 ) != 4 ) ;
V_49 = F_19 ( struct V_164 , V_165 ) ;
F_9 ( F_20 ( V_20 , V_54 , V_49 ) , V_11 ) ;
break;
case V_41 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 , V_166 ) != 4 ) ;
V_49 = F_19 ( struct V_1 , V_166 ) ;
F_9 ( F_20 ( V_20 , V_29 , V_49 ) , V_11 ) ;
break;
case V_43 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 , V_167 ) != 4 ) ;
V_49 = F_19 ( struct V_1 , V_167 ) ;
F_9 ( F_20 ( V_20 , V_29 , V_49 ) , V_11 ) ;
break;
case V_44 :
case V_45 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 , V_168 ) != 2 ) ;
V_49 = F_19 ( struct V_1 , V_168 ) ;
F_9 ( F_46 ( V_20 , V_29 , V_49 ) , V_11 ) ;
if ( V_9 -> V_18 == V_44 )
F_64 ( V_133 , V_20 , V_20 , V_169 , V_11 ) ;
else
F_64 ( V_133 , V_20 , V_20 , V_170 , V_11 ) ;
break;
case V_46 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 ,
V_171 ) != 2 ) ;
F_57 ( F_19 ( struct V_1 ,
V_171 ) > 0xff ) ;
V_49 = F_19 ( struct V_1 , V_171 ) ;
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
void F_78 ( struct V_90 * V_172 )
{
struct V_10 V_11 ;
unsigned V_173 ;
unsigned V_174 ;
if ( ! V_175 )
return;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_15 = V_172 ;
V_11 . V_82 = - 1 ;
V_11 . V_65 = F_79 ( 4 * ( V_11 . V_15 -> V_16 + 1 ) , V_176 ) ;
if ( V_11 . V_65 == NULL )
return;
if ( F_72 ( F_56 ( & V_11 ) ) )
goto V_177;
V_173 = V_11 . V_13 ;
F_15 ( & V_11 ) ;
V_11 . V_66 = ( V_11 . V_13 - V_173 ) * 4 ;
#if V_70 < 7
V_173 = V_11 . V_13 ;
F_23 ( & V_11 ) ;
V_11 . V_67 = ( V_11 . V_13 - V_173 ) * 4 ;
V_11 . V_13 += V_11 . V_63 ;
if ( V_11 . V_63 ) {
V_11 . V_64 = F_79 ( 4 * V_11 . V_63 , V_176 ) ;
if ( V_11 . V_64 == NULL )
goto V_177;
}
#else
F_23 ( & V_11 ) ;
#endif
V_174 = 4 * V_11 . V_13 ;
V_11 . V_12 = F_80 ( F_81 ( sizeof( struct V_178 ) ,
V_174 ) ) ;
if ( F_72 ( V_11 . V_12 == NULL ) )
goto V_177;
V_11 . V_13 = 0 ;
F_15 ( & V_11 ) ;
F_56 ( & V_11 ) ;
F_23 ( & V_11 ) ;
F_82 ( ( T_4 ) V_11 . V_12 , ( T_4 ) ( V_11 . V_12 + V_11 . V_13 ) ) ;
#if V_70 < 7
if ( V_11 . V_63 )
F_83 ( V_11 . V_64 ) ;
#endif
if ( V_175 > 1 )
F_84 ( V_179 , L_1 ,
V_180 , 16 , 4 , V_11 . V_12 ,
V_174 , false ) ;
V_172 -> V_181 = ( void * ) V_11 . V_12 ;
V_177:
F_83 ( V_11 . V_65 ) ;
return;
}
static void F_85 ( struct V_178 * V_182 )
{
F_86 ( NULL , V_182 ) ;
}
void F_87 ( struct V_90 * V_172 )
{
struct V_178 * V_182 ;
if ( V_172 -> V_181 != V_183 ) {
V_182 = (struct V_178 * ) V_172 -> V_181 ;
F_88 ( V_182 , F_85 ) ;
F_89 ( V_182 ) ;
}
}
