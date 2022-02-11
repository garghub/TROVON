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
return true ;
default:
return false ;
}
}
static void F_15 ( struct V_10 * V_11 )
{
T_3 V_45 = F_10 ( V_11 ) ;
T_3 V_46 = V_11 -> V_15 -> V_17 [ 0 ] . V_18 ;
T_3 V_47 ;
#ifdef F_11
F_9 ( F_16 ( V_22 , V_48 ) , V_11 ) ;
F_9 ( F_17 ( V_45 ) , V_11 ) ;
F_9 ( F_18 ( V_21 , V_22 , 4 ) , V_11 ) ;
#else
if ( V_45 )
F_9 ( F_17 ( V_45 ) , V_11 ) ;
#endif
if ( V_11 -> V_25 & ( V_27 | V_28 ) )
F_9 ( F_16 ( V_29 , V_49 ) , V_11 ) ;
if ( V_11 -> V_25 & V_27 ) {
V_47 = F_19 ( struct V_1 , V_50 ) ;
F_9 ( F_20 ( V_30 , V_29 , V_47 ) , V_11 ) ;
V_47 = F_19 ( struct V_1 , V_16 ) ;
F_9 ( F_20 ( V_31 , V_29 , V_47 ) , V_11 ) ;
V_47 = F_19 ( struct V_1 , V_51 ) ;
F_9 ( F_20 ( V_52 , V_29 , V_47 ) , V_11 ) ;
F_9 ( F_21 ( V_31 , V_31 , V_52 ) , V_11 ) ;
}
if ( V_11 -> V_53 & V_54 )
F_9 ( F_22 ( V_33 , 0 ) , V_11 ) ;
if ( ( V_46 != V_55 ) && ! ( F_14 ( V_46 ) ) )
F_9 ( F_22 ( V_20 , 0 ) , V_11 ) ;
if ( V_11 -> V_25 & V_34 )
F_9 ( F_18 ( V_48 , V_48 , F_12 ( V_11 ) * 4 ) , V_11 ) ;
}
static void F_23 ( struct V_10 * V_11 )
{
T_3 V_45 = F_10 ( V_11 ) ;
if ( V_11 -> V_25 & V_34 )
F_9 ( F_24 ( V_48 , V_48 , F_12 ( V_11 ) * 4 ) , V_11 ) ;
V_45 &= ~ ( 1 << V_23 ) ;
#ifdef F_11
V_45 &= ~ ( 1 << V_22 ) ;
V_45 |= ( 1 << V_48 ) ;
F_9 ( F_25 ( V_48 , V_45 ) , V_11 ) ;
#else
if ( V_45 ) {
if ( V_11 -> V_25 & V_26 )
V_45 |= 1 << V_24 ;
F_9 ( F_26 ( V_45 ) , V_11 ) ;
}
if ( ! ( V_11 -> V_25 & V_26 ) )
F_9 ( F_27 ( V_23 ) , V_11 ) ;
#endif
}
static T_5 F_28 ( T_4 V_56 )
{
T_4 V_57 ;
for ( V_57 = 0 ; V_57 < 16 ; V_57 ++ )
if ( ( V_56 & ~ F_29 ( 0xff , 2 * V_57 ) ) == 0 )
return F_30 ( V_56 , 2 * V_57 ) | ( V_57 << 8 ) ;
return - 1 ;
}
static T_3 F_31 ( T_4 V_58 , struct V_10 * V_11 )
{
unsigned V_59 = 0 , V_3 ;
T_3 V_60 ;
if ( V_11 -> V_12 == NULL ) {
V_11 -> V_61 ++ ;
return 0 ;
}
while ( ( V_59 < V_11 -> V_61 ) && V_11 -> V_62 [ V_59 ] ) {
if ( V_11 -> V_62 [ V_59 ] == V_58 )
break;
V_59 ++ ;
}
if ( V_11 -> V_62 [ V_59 ] == 0 )
V_11 -> V_62 [ V_59 ] = V_58 ;
V_3 = V_11 -> V_63 [ V_11 -> V_15 -> V_16 ] ;
V_3 += V_11 -> V_64 ;
V_3 += V_11 -> V_65 ;
V_3 += V_59 * 4 ;
V_11 -> V_12 [ V_3 / 4 ] = V_58 ;
V_60 = V_3 - ( 8 + V_11 -> V_13 * 4 ) ;
return V_60 ;
}
static inline void F_32 ( int V_66 , T_4 V_67 , struct V_10 * V_11 )
{
#if V_68 < 7
F_9 ( F_20 ( V_66 , V_24 , F_31 ( V_67 , V_11 ) ) , V_11 ) ;
#else
F_9 ( F_33 ( V_66 , V_67 & 0xffff ) , V_11 ) ;
if ( V_67 > 0xffff )
F_9 ( F_34 ( V_66 , V_67 >> 16 ) , V_11 ) ;
#endif
}
static inline void F_35 ( int V_66 , T_4 V_67 , struct V_10 * V_11 )
{
int V_69 = F_28 ( V_67 ) ;
if ( V_69 >= 0 )
F_9 ( F_22 ( V_66 , V_69 ) , V_11 ) ;
else
F_32 ( V_66 , V_67 , V_11 ) ;
}
static void F_36 ( T_2 V_8 , T_2 V_70 , T_2 V_71 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_37 ( V_72 , V_71 , 1 ) , V_11 ) ;
F_8 ( V_8 , F_37 ( V_73 , V_71 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_37 ( V_74 , V_71 , 3 ) , V_11 ) ;
F_8 ( V_8 , F_38 ( V_72 , V_72 , 16 ) , V_11 ) ;
F_8 ( V_8 , F_37 ( V_49 , V_71 , 2 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_72 , V_72 , V_73 , V_75 , 24 ) , V_11 ) ;
F_8 ( V_8 , F_40 ( V_72 , V_72 , V_74 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_70 , V_72 , V_49 , V_75 , 8 ) , V_11 ) ;
}
static void F_41 ( T_2 V_8 , T_2 V_70 , T_2 V_71 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_37 ( V_73 , V_71 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_37 ( V_74 , V_71 , 1 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_70 , V_74 , V_73 , V_75 , 8 ) , V_11 ) ;
}
static inline void F_42 ( T_2 V_76 , T_2 V_77 , struct V_10 * V_11 )
{
F_9 ( F_43 ( V_73 , V_77 , 8 ) , V_11 ) ;
F_9 ( F_39 ( V_76 , V_73 , V_77 , V_75 , 8 ) , V_11 ) ;
F_9 ( F_38 ( V_76 , V_76 , 8 ) , V_11 ) ;
F_9 ( F_43 ( V_76 , V_76 , 8 ) , V_11 ) ;
}
static void F_36 ( T_2 V_8 , T_2 V_70 , T_2 V_71 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_20 ( V_70 , V_71 , 0 ) , V_11 ) ;
#ifdef F_44
F_8 ( V_8 , F_45 ( V_70 , V_70 ) , V_11 ) ;
#endif
}
static void F_41 ( T_2 V_8 , T_2 V_70 , T_2 V_71 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_46 ( V_70 , V_71 , 0 ) , V_11 ) ;
#ifdef F_44
F_8 ( V_8 , F_47 ( V_70 , V_70 ) , V_11 ) ;
#endif
}
static inline void F_42 ( T_2 V_76 V_78 ,
T_2 V_77 V_78 ,
struct V_10 * V_11 V_78 )
{
#ifdef F_44
F_9 ( F_47 ( V_76 , V_77 ) , V_11 ) ;
#endif
}
static inline T_4 F_48 ( unsigned V_79 , struct V_10 * V_11 )
{
T_4 V_60 ;
if ( V_11 -> V_12 == NULL )
return 0 ;
V_60 = V_11 -> V_63 [ V_79 ] + V_11 -> V_64 - ( V_11 -> V_13 * 4 + 8 ) ;
return V_60 >> 2 ;
}
static inline void F_49 ( T_2 V_8 , struct V_10 * V_11 )
{
if ( V_11 -> V_80 >= 0 ) {
F_8 ( V_8 , F_50 ( F_48 ( V_11 -> V_80 , V_11 ) ) , V_11 ) ;
F_9 ( F_16 ( V_49 , V_49 ) , V_11 ) ;
} else {
F_8 ( V_8 , F_22 ( V_49 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_50 ( F_48 ( V_11 -> V_15 -> V_16 , V_11 ) ) , V_11 ) ;
}
}
static inline void F_51 ( T_2 V_81 , struct V_10 * V_11 )
{
#if V_68 < 5
F_9 ( F_16 ( V_23 , V_24 ) , V_11 ) ;
if ( V_82 & V_83 )
F_9 ( F_27 ( V_81 ) , V_11 ) ;
else
F_9 ( F_16 ( V_24 , V_81 ) , V_11 ) ;
#else
F_9 ( F_52 ( V_81 ) , V_11 ) ;
#endif
}
static inline void F_53 ( T_2 V_66 , T_2 V_84 , T_2 V_85 , struct V_10 * V_11 )
{
#if V_68 == 7
if ( V_82 & V_86 ) {
F_9 ( F_54 ( V_66 , V_84 , V_85 ) , V_11 ) ;
return;
}
#endif
if ( V_84 != V_49 )
F_9 ( F_16 ( V_49 , V_84 ) , V_11 ) ;
if ( V_85 != V_73 )
F_9 ( F_16 ( V_73 , V_85 ) , V_11 ) ;
V_11 -> V_25 |= V_26 ;
F_35 ( V_72 , ( T_4 ) F_7 , V_11 ) ;
F_51 ( V_72 , V_11 ) ;
if ( V_66 != V_49 )
F_9 ( F_16 ( V_66 , V_49 ) , V_11 ) ;
}
static inline void F_55 ( struct V_10 * V_11 )
{
if ( ! ( V_11 -> V_25 & V_32 ) )
V_11 -> V_53 |= V_54 ;
V_11 -> V_25 |= V_32 ;
}
static int F_56 ( struct V_10 * V_11 )
{
void * V_87 [] = { F_1 , F_3 , F_5 } ;
const struct V_88 * V_89 = V_11 -> V_15 ;
const struct V_90 * V_9 ;
unsigned V_59 , V_91 , V_47 , V_92 ;
int V_69 ;
T_4 V_58 ;
for ( V_59 = 0 ; V_59 < V_89 -> V_16 ; V_59 ++ ) {
V_9 = & ( V_89 -> V_17 [ V_59 ] ) ;
V_58 = V_9 -> V_58 ;
if ( V_11 -> V_12 == NULL )
V_11 -> V_63 [ V_59 ] = V_11 -> V_13 * 4 ;
switch ( V_9 -> V_18 ) {
case V_93 :
F_35 ( V_20 , V_58 , V_11 ) ;
break;
case V_35 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 , V_16 ) != 4 ) ;
F_9 ( F_20 ( V_20 , V_29 ,
F_19 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_94 :
V_11 -> V_25 |= F_59 ( V_58 ) ;
F_9 ( F_20 ( V_20 , V_48 , F_60 ( V_58 ) ) , V_11 ) ;
break;
case V_36 :
V_91 = 2 ;
goto V_95;
case V_37 :
V_91 = 1 ;
goto V_95;
case V_38 :
V_91 = 0 ;
V_95:
if ( ( int ) V_58 < 0 )
return - V_96 ;
F_35 ( V_97 , V_58 , V_11 ) ;
V_98:
V_11 -> V_25 |= V_27 | V_26 ;
if ( V_91 > 0 ) {
F_9 ( F_18 ( V_52 , V_31 ,
1 << V_91 ) , V_11 ) ;
F_9 ( F_61 ( V_52 , V_97 ) , V_11 ) ;
V_92 = V_99 ;
} else {
F_9 ( F_61 ( V_31 , V_97 ) , V_11 ) ;
V_92 = V_100 ;
}
F_8 ( V_92 , F_62 ( V_52 , V_97 , V_30 ) ,
V_11 ) ;
if ( V_91 == 0 )
F_8 ( V_92 , F_37 ( V_20 , V_52 , 0 ) ,
V_11 ) ;
else if ( V_91 == 1 )
F_41 ( V_92 , V_20 , V_52 , V_11 ) ;
else if ( V_91 == 2 )
F_36 ( V_92 , V_20 , V_52 , V_11 ) ;
F_8 ( V_92 , F_50 ( F_48 ( V_59 + 1 , V_11 ) ) , V_11 ) ;
F_35 ( V_72 , ( T_4 ) V_87 [ V_91 ] , V_11 ) ;
F_9 ( F_16 ( V_49 , V_29 ) , V_11 ) ;
F_51 ( V_72 , V_11 ) ;
F_9 ( F_63 ( V_73 , 0 ) , V_11 ) ;
F_49 ( V_101 , V_11 ) ;
F_9 ( F_16 ( V_20 , V_49 ) , V_11 ) ;
break;
case V_102 :
V_91 = 2 ;
goto V_103;
case V_104 :
V_91 = 1 ;
goto V_103;
case V_105 :
V_91 = 0 ;
V_103:
F_64 ( V_106 , V_97 , V_33 , V_58 , V_11 ) ;
goto V_98;
case V_107 :
V_11 -> V_25 |= V_32 ;
F_35 ( V_33 , V_58 , V_11 ) ;
break;
case V_108 :
V_11 -> V_25 |= V_32 | V_28 ;
F_9 ( F_20 ( V_33 , V_29 ,
F_19 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_109 :
V_11 -> V_25 |= V_32 | F_59 ( V_58 ) ;
F_9 ( F_20 ( V_33 , V_48 , F_60 ( V_58 ) ) , V_11 ) ;
break;
case V_110 :
V_11 -> V_25 |= V_32 | V_27 | V_26 ;
if ( V_58 < 0 )
return - 1 ;
F_35 ( V_97 , V_58 , V_11 ) ;
F_9 ( F_61 ( V_31 , V_97 ) , V_11 ) ;
F_8 ( V_100 , F_65 ( V_49 , V_30 ,
V_73 ) , V_11 ) ;
F_8 ( V_100 , F_50 ( F_48 ( V_59 + 1 , V_11 ) - 2 ) , V_11 ) ;
F_9 ( F_16 ( V_49 , V_29 ) , V_11 ) ;
F_35 ( V_72 , ( T_4 ) F_1 , V_11 ) ;
F_51 ( V_72 , V_11 ) ;
F_9 ( F_63 ( V_73 , 0 ) , V_11 ) ;
F_49 ( V_101 , V_11 ) ;
F_9 ( F_66 ( V_33 , V_49 , 0x00f ) , V_11 ) ;
F_9 ( F_38 ( V_33 , V_33 , 2 ) , V_11 ) ;
break;
case V_111 :
V_11 -> V_25 |= F_59 ( V_58 ) ;
F_9 ( F_67 ( V_20 , V_48 , F_60 ( V_58 ) ) , V_11 ) ;
break;
case V_112 :
F_55 ( V_11 ) ;
V_11 -> V_25 |= F_59 ( V_58 ) ;
F_9 ( F_67 ( V_33 , V_48 , F_60 ( V_58 ) ) , V_11 ) ;
break;
case V_113 :
F_64 ( V_106 , V_20 , V_20 , V_58 , V_11 ) ;
break;
case V_114 :
F_55 ( V_11 ) ;
F_9 ( F_62 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_115 :
F_64 ( V_116 , V_20 , V_20 , V_58 , V_11 ) ;
break;
case V_117 :
F_55 ( V_11 ) ;
F_9 ( F_21 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_118 :
F_35 ( V_52 , V_58 , V_11 ) ;
F_9 ( F_68 ( V_20 , V_20 , V_52 ) , V_11 ) ;
break;
case V_119 :
F_55 ( V_11 ) ;
F_9 ( F_68 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_120 :
F_35 ( V_52 , V_58 , V_11 ) ;
F_9 ( F_69 ( V_52 , V_20 , V_20 , V_52 ) , V_11 ) ;
break;
case V_121 :
F_55 ( V_11 ) ;
F_9 ( F_63 ( V_33 , 0 ) , V_11 ) ;
F_49 ( V_122 , V_11 ) ;
F_53 ( V_20 , V_20 , V_33 , V_11 ) ;
break;
case V_123 :
F_64 ( V_124 , V_20 , V_20 , V_58 , V_11 ) ;
break;
case V_125 :
F_55 ( V_11 ) ;
F_9 ( F_40 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_126 :
F_64 ( V_127 , V_20 , V_20 , V_58 , V_11 ) ;
break;
case V_128 :
F_55 ( V_11 ) ;
F_9 ( F_70 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_129 :
if ( F_71 ( V_58 > 31 ) )
return - 1 ;
F_9 ( F_38 ( V_20 , V_20 , V_58 ) , V_11 ) ;
break;
case V_130 :
F_55 ( V_11 ) ;
F_9 ( F_43 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_131 :
if ( F_71 ( V_58 > 31 ) )
return - 1 ;
F_9 ( F_72 ( V_20 , V_20 , V_58 ) , V_11 ) ;
break;
case V_132 :
F_55 ( V_11 ) ;
F_9 ( F_73 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_133 :
F_9 ( F_74 ( V_20 , V_20 , 0 ) , V_11 ) ;
break;
case V_134 :
F_9 ( F_50 ( F_48 ( V_59 + V_58 + 1 , V_11 ) ) , V_11 ) ;
break;
case V_135 :
V_92 = V_122 ;
goto V_136;
case V_137 :
V_92 = V_100 ;
goto V_136;
case V_138 :
V_92 = V_99 ;
V_136:
V_69 = F_28 ( V_58 ) ;
if ( V_69 < 0 ) {
F_32 ( V_52 , V_58 , V_11 ) ;
F_9 ( F_61 ( V_20 , V_52 ) , V_11 ) ;
} else {
F_9 ( F_63 ( V_20 , V_69 ) , V_11 ) ;
}
V_139:
if ( V_9 -> V_140 )
F_8 ( V_92 , F_50 ( F_48 ( V_59 + V_9 -> V_140 + 1 ,
V_11 ) ) , V_11 ) ;
if ( V_9 -> V_141 )
F_8 ( V_92 ^ 1 , F_50 ( F_48 ( V_59 + V_9 -> V_141 + 1 ,
V_11 ) ) , V_11 ) ;
break;
case V_142 :
V_92 = V_122 ;
goto V_143;
case V_144 :
V_92 = V_100 ;
goto V_143;
case V_145 :
V_92 = V_146 ;
V_143:
F_55 ( V_11 ) ;
F_9 ( F_61 ( V_20 , V_33 ) , V_11 ) ;
goto V_139;
case V_147 :
V_92 = V_101 ;
V_69 = F_28 ( V_58 ) ;
if ( V_69 < 0 ) {
F_32 ( V_52 , V_58 , V_11 ) ;
F_9 ( F_75 ( V_20 , V_52 ) , V_11 ) ;
} else {
F_9 ( F_76 ( V_20 , V_69 ) , V_11 ) ;
}
goto V_139;
case V_148 :
F_55 ( V_11 ) ;
V_92 = V_101 ;
F_9 ( F_75 ( V_20 , V_33 ) , V_11 ) ;
goto V_139;
case V_19 :
F_9 ( F_16 ( V_49 , V_20 ) , V_11 ) ;
goto V_149;
case V_55 :
if ( ( V_58 == 0 ) && ( V_11 -> V_80 < 0 ) )
V_11 -> V_80 = V_59 ;
F_35 ( V_49 , V_58 , V_11 ) ;
V_149:
if ( V_59 != V_11 -> V_15 -> V_16 - 1 )
F_9 ( F_50 ( F_48 ( V_89 -> V_16 , V_11 ) ) , V_11 ) ;
break;
case V_150 :
V_11 -> V_25 |= V_32 ;
F_9 ( F_16 ( V_33 , V_20 ) , V_11 ) ;
break;
case V_151 :
F_55 ( V_11 ) ;
F_9 ( F_16 ( V_20 , V_33 ) , V_11 ) ;
break;
case V_152 :
F_55 ( V_11 ) ;
F_9 ( F_77 ( V_20 , V_20 , V_33 ) , V_11 ) ;
break;
case V_42 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 ,
V_153 ) != 2 ) ;
V_47 = F_19 ( struct V_1 , V_153 ) ;
F_9 ( F_46 ( V_52 , V_29 , V_47 ) , V_11 ) ;
F_42 ( V_20 , V_52 , V_11 ) ;
break;
case V_39 :
F_64 ( V_154 , V_52 , V_48 , V_155 - 1 , V_11 ) ;
F_57 ( F_58 ( struct V_156 , V_157 ) != 4 ) ;
V_47 = F_19 ( struct V_156 , V_157 ) ;
F_9 ( F_20 ( V_20 , V_52 , V_47 ) , V_11 ) ;
break;
case V_40 :
V_11 -> V_25 |= V_28 ;
V_47 = F_19 ( struct V_1 , V_158 ) ;
F_9 ( F_20 ( V_52 , V_29 , V_47 ) , V_11 ) ;
F_9 ( F_63 ( V_52 , 0 ) , V_11 ) ;
F_49 ( V_122 , V_11 ) ;
F_57 ( F_58 ( struct V_159 ,
V_160 ) != 4 ) ;
V_47 = F_19 ( struct V_159 , V_160 ) ;
F_9 ( F_20 ( V_20 , V_52 , V_47 ) , V_11 ) ;
break;
case V_41 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 , V_161 ) != 4 ) ;
V_47 = F_19 ( struct V_1 , V_161 ) ;
F_9 ( F_20 ( V_20 , V_29 , V_47 ) , V_11 ) ;
break;
case V_43 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 , V_162 ) != 4 ) ;
V_47 = F_19 ( struct V_1 , V_162 ) ;
F_9 ( F_20 ( V_20 , V_29 , V_47 ) , V_11 ) ;
break;
case V_44 :
V_11 -> V_25 |= V_28 ;
F_57 ( F_58 ( struct V_1 ,
V_163 ) != 2 ) ;
F_57 ( F_19 ( struct V_1 ,
V_163 ) > 0xff ) ;
V_47 = F_19 ( struct V_1 , V_163 ) ;
F_9 ( F_46 ( V_20 , V_29 , V_47 ) , V_11 ) ;
break;
default:
return - 1 ;
}
}
if ( V_11 -> V_12 == NULL )
V_11 -> V_63 [ V_59 ] = V_11 -> V_13 * 4 ;
return 0 ;
}
void F_78 ( struct V_88 * V_164 )
{
struct V_10 V_11 ;
unsigned V_165 ;
unsigned V_166 ;
if ( ! V_167 )
return;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_15 = V_164 ;
V_11 . V_80 = - 1 ;
V_11 . V_63 = F_79 ( V_168 , 4 * ( V_11 . V_15 -> V_16 + 1 ) ) ;
if ( V_11 . V_63 == NULL )
return;
if ( F_71 ( F_56 ( & V_11 ) ) )
goto V_169;
V_165 = V_11 . V_13 ;
F_15 ( & V_11 ) ;
V_11 . V_64 = ( V_11 . V_13 - V_165 ) * 4 ;
#if V_68 < 7
V_165 = V_11 . V_13 ;
F_23 ( & V_11 ) ;
V_11 . V_65 = ( V_11 . V_13 - V_165 ) * 4 ;
V_11 . V_13 += V_11 . V_61 ;
if ( V_11 . V_61 ) {
V_11 . V_62 = F_79 ( V_168 , 4 * V_11 . V_61 ) ;
if ( V_11 . V_62 == NULL )
goto V_169;
}
#else
F_23 ( & V_11 ) ;
#endif
V_166 = 4 * V_11 . V_13 ;
V_11 . V_12 = F_80 ( F_81 ( sizeof( struct V_170 ) ,
V_166 ) ) ;
if ( F_71 ( V_11 . V_12 == NULL ) )
goto V_169;
V_11 . V_13 = 0 ;
F_15 ( & V_11 ) ;
F_56 ( & V_11 ) ;
F_23 ( & V_11 ) ;
F_82 ( ( T_4 ) V_11 . V_12 , ( T_4 ) ( V_11 . V_12 + V_11 . V_13 ) ) ;
#if V_68 < 7
if ( V_11 . V_61 )
F_83 ( V_11 . V_62 ) ;
#endif
if ( V_167 > 1 )
F_84 ( V_171 , L_1 ,
V_172 , 16 , 4 , V_11 . V_12 ,
V_166 , false ) ;
V_164 -> V_173 = ( void * ) V_11 . V_12 ;
V_169:
F_83 ( V_11 . V_63 ) ;
return;
}
static void F_85 ( struct V_170 * V_174 )
{
F_86 ( NULL , V_174 ) ;
}
void F_87 ( struct V_88 * V_164 )
{
struct V_170 * V_174 ;
if ( V_164 -> V_173 != V_175 ) {
V_174 = (struct V_170 * ) V_164 -> V_173 ;
F_88 ( V_174 , F_85 ) ;
F_89 ( V_174 ) ;
}
}
