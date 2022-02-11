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
V_9 |= ( V_8 << 28 ) ;
V_9 = F_9 ( V_9 ) ;
if ( V_11 -> V_12 != NULL )
V_11 -> V_12 [ V_11 -> V_13 ] = V_9 ;
V_11 -> V_13 ++ ;
}
static inline void F_10 ( T_4 V_9 , struct V_10 * V_11 )
{
F_8 ( V_14 , V_9 , V_11 ) ;
}
static T_3 F_11 ( struct V_10 * V_11 )
{
T_3 V_4 = 0 ;
if ( ( V_11 -> V_15 -> V_16 > 1 ) ||
( V_11 -> V_15 -> V_17 [ 0 ] . V_18 == ( V_19 | V_20 ) ) )
V_4 |= 1 << V_21 ;
#ifdef F_12
V_4 |= ( 1 << V_22 ) | ( 1 << V_23 ) | ( 1 << V_24 ) | ( 1 << V_25 ) ;
#else
if ( V_11 -> V_26 & V_27 )
V_4 |= 1 << V_24 ;
#endif
if ( V_11 -> V_26 & ( V_28 | V_29 ) )
V_4 |= 1 << V_30 ;
if ( V_11 -> V_26 & V_28 )
V_4 |= ( 1 << V_31 ) | ( 1 << V_32 ) ;
if ( V_11 -> V_26 & V_33 )
V_4 |= 1 << V_34 ;
return V_4 ;
}
static inline int F_13 ( struct V_10 * V_11 )
{
return F_14 ( V_11 -> V_26 & V_35 ) ;
}
static inline bool F_15 ( T_3 V_9 )
{
switch ( V_9 ) {
case V_36 | V_37 | V_38 :
case V_36 | V_37 | V_39 :
case V_36 | V_40 | V_39 :
case V_36 | V_41 | V_39 :
return true ;
default:
return false ;
}
}
static void F_16 ( struct V_10 * V_11 )
{
T_3 V_42 = F_11 ( V_11 ) ;
T_3 V_43 = V_11 -> V_15 -> V_17 [ 0 ] . V_18 ;
T_3 V_44 ;
#ifdef F_12
F_10 ( F_17 ( V_23 , V_45 ) , V_11 ) ;
F_10 ( F_18 ( V_42 ) , V_11 ) ;
F_10 ( F_19 ( V_22 , V_23 , 4 ) , V_11 ) ;
#else
if ( V_42 )
F_10 ( F_18 ( V_42 ) , V_11 ) ;
#endif
if ( V_11 -> V_26 & ( V_28 | V_29 ) )
F_10 ( F_17 ( V_30 , V_46 ) , V_11 ) ;
if ( V_11 -> V_26 & V_28 ) {
V_44 = F_20 ( struct V_1 , V_47 ) ;
F_10 ( F_21 ( V_31 , V_30 , V_44 ) , V_11 ) ;
V_44 = F_20 ( struct V_1 , V_16 ) ;
F_10 ( F_21 ( V_32 , V_30 , V_44 ) , V_11 ) ;
V_44 = F_20 ( struct V_1 , V_48 ) ;
F_10 ( F_21 ( V_49 , V_30 , V_44 ) , V_11 ) ;
F_10 ( F_22 ( V_32 , V_32 , V_49 ) , V_11 ) ;
}
if ( V_11 -> V_50 & V_51 )
F_10 ( F_23 ( V_34 , 0 ) , V_11 ) ;
if ( ( V_43 != ( V_19 | V_52 ) ) && ! ( F_15 ( V_43 ) ) )
F_10 ( F_23 ( V_21 , 0 ) , V_11 ) ;
if ( V_11 -> V_26 & V_35 )
F_10 ( F_19 ( V_45 , V_45 , F_13 ( V_11 ) * 4 ) , V_11 ) ;
}
static void F_24 ( struct V_10 * V_11 )
{
T_3 V_42 = F_11 ( V_11 ) ;
if ( V_11 -> V_26 & V_35 )
F_10 ( F_25 ( V_45 , V_45 , F_13 ( V_11 ) * 4 ) , V_11 ) ;
V_42 &= ~ ( 1 << V_24 ) ;
#ifdef F_12
V_42 &= ~ ( 1 << V_23 ) ;
V_42 |= ( 1 << V_45 ) ;
F_10 ( F_26 ( V_45 , V_42 ) , V_11 ) ;
#else
if ( V_42 ) {
if ( V_11 -> V_26 & V_27 )
V_42 |= 1 << V_25 ;
F_10 ( F_27 ( V_42 ) , V_11 ) ;
}
if ( ! ( V_11 -> V_26 & V_27 ) )
F_10 ( F_28 ( V_24 ) , V_11 ) ;
#endif
}
static T_5 F_29 ( T_4 V_53 )
{
T_4 V_54 ;
for ( V_54 = 0 ; V_54 < 16 ; V_54 ++ )
if ( ( V_53 & ~ F_30 ( 0xff , 2 * V_54 ) ) == 0 )
return F_31 ( V_53 , 2 * V_54 ) | ( V_54 << 8 ) ;
return - 1 ;
}
static T_3 F_32 ( T_4 V_55 , struct V_10 * V_11 )
{
unsigned V_56 = 0 , V_3 ;
T_3 V_57 ;
if ( V_11 -> V_12 == NULL ) {
V_11 -> V_58 ++ ;
return 0 ;
}
while ( ( V_56 < V_11 -> V_58 ) && V_11 -> V_59 [ V_56 ] ) {
if ( V_11 -> V_59 [ V_56 ] == V_55 )
break;
V_56 ++ ;
}
if ( V_11 -> V_59 [ V_56 ] == 0 )
V_11 -> V_59 [ V_56 ] = V_55 ;
V_3 = V_11 -> V_60 [ V_11 -> V_15 -> V_16 ] ;
V_3 += V_11 -> V_61 ;
V_3 += V_11 -> V_62 ;
V_3 += V_56 * 4 ;
V_11 -> V_12 [ V_3 / 4 ] = V_55 ;
V_57 = V_3 - ( 8 + V_11 -> V_13 * 4 ) ;
return V_57 ;
}
static inline void F_33 ( int V_63 , T_4 V_64 , struct V_10 * V_11 )
{
#if V_65 < 7
F_10 ( F_21 ( V_63 , V_25 , F_32 ( V_64 , V_11 ) ) , V_11 ) ;
#else
F_10 ( F_34 ( V_63 , V_64 & 0xffff ) , V_11 ) ;
if ( V_64 > 0xffff )
F_10 ( F_35 ( V_63 , V_64 >> 16 ) , V_11 ) ;
#endif
}
static inline void F_36 ( int V_63 , T_4 V_64 , struct V_10 * V_11 )
{
int V_66 = F_29 ( V_64 ) ;
if ( V_66 >= 0 )
F_10 ( F_23 ( V_63 , V_66 ) , V_11 ) ;
else
F_33 ( V_63 , V_64 , V_11 ) ;
}
static void F_37 ( T_2 V_8 , T_2 V_67 , T_2 V_68 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_38 ( V_69 , V_68 , 1 ) , V_11 ) ;
F_8 ( V_8 , F_38 ( V_70 , V_68 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_38 ( V_71 , V_68 , 3 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_69 , V_69 , 16 ) , V_11 ) ;
F_8 ( V_8 , F_38 ( V_46 , V_68 , 2 ) , V_11 ) ;
F_8 ( V_8 , F_40 ( V_69 , V_69 , V_70 , V_72 , 24 ) , V_11 ) ;
F_8 ( V_8 , F_41 ( V_69 , V_69 , V_71 ) , V_11 ) ;
F_8 ( V_8 , F_40 ( V_67 , V_69 , V_46 , V_72 , 8 ) , V_11 ) ;
}
static void F_42 ( T_2 V_8 , T_2 V_67 , T_2 V_68 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_38 ( V_70 , V_68 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_38 ( V_71 , V_68 , 1 ) , V_11 ) ;
F_8 ( V_8 , F_40 ( V_67 , V_71 , V_70 , V_72 , 8 ) , V_11 ) ;
}
static inline void F_43 ( T_2 V_73 , T_2 V_74 , struct V_10 * V_11 )
{
F_10 ( F_39 ( V_70 , V_74 , 8 ) , V_11 ) ;
F_10 ( F_40 ( V_73 , V_70 , V_74 , V_75 , 8 ) , V_11 ) ;
F_10 ( F_44 ( V_73 , V_73 , 0x8ff ) , V_11 ) ;
}
static void F_37 ( T_2 V_8 , T_2 V_67 , T_2 V_68 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_21 ( V_67 , V_68 , 0 ) , V_11 ) ;
#ifdef F_45
F_8 ( V_8 , F_46 ( V_67 , V_67 ) , V_11 ) ;
#endif
}
static void F_42 ( T_2 V_8 , T_2 V_67 , T_2 V_68 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_47 ( V_67 , V_68 , 0 ) , V_11 ) ;
#ifdef F_45
F_8 ( V_8 , F_48 ( V_67 , V_67 ) , V_11 ) ;
#endif
}
static inline void F_43 ( T_2 V_73 V_76 ,
T_2 V_74 V_76 ,
struct V_10 * V_11 V_76 )
{
#ifdef F_45
F_10 ( F_48 ( V_73 , V_74 ) , V_11 ) ;
#endif
}
static inline T_4 F_49 ( unsigned V_77 , struct V_10 * V_11 )
{
T_4 V_57 ;
if ( V_11 -> V_12 == NULL )
return 0 ;
V_57 = V_11 -> V_60 [ V_77 ] + V_11 -> V_61 - ( V_11 -> V_13 * 4 + 8 ) ;
return V_57 >> 2 ;
}
static inline void F_50 ( T_2 V_8 , struct V_10 * V_11 )
{
if ( V_11 -> V_78 >= 0 ) {
F_8 ( V_8 , F_51 ( F_49 ( V_11 -> V_78 , V_11 ) ) , V_11 ) ;
F_10 ( F_17 ( V_46 , V_46 ) , V_11 ) ;
} else {
F_8 ( V_8 , F_23 ( V_46 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_51 ( F_49 ( V_11 -> V_15 -> V_16 , V_11 ) ) , V_11 ) ;
}
}
static inline void F_52 ( T_2 V_79 , struct V_10 * V_11 )
{
#if V_65 < 5
F_10 ( F_17 ( V_24 , V_25 ) , V_11 ) ;
if ( V_80 & V_81 )
F_10 ( F_28 ( V_79 ) , V_11 ) ;
else
F_10 ( F_17 ( V_25 , V_79 ) , V_11 ) ;
#else
F_10 ( F_53 ( V_79 ) , V_11 ) ;
#endif
}
static inline void F_54 ( T_2 V_63 , T_2 V_82 , T_2 V_83 , struct V_10 * V_11 )
{
#if V_65 == 7
if ( V_80 & V_84 ) {
F_10 ( F_55 ( V_63 , V_82 , V_83 ) , V_11 ) ;
return;
}
#endif
if ( V_82 != V_46 )
F_10 ( F_17 ( V_46 , V_82 ) , V_11 ) ;
if ( V_83 != V_70 )
F_10 ( F_17 ( V_70 , V_83 ) , V_11 ) ;
V_11 -> V_26 |= V_27 ;
F_36 ( V_69 , ( T_4 ) F_7 , V_11 ) ;
F_52 ( V_69 , V_11 ) ;
if ( V_63 != V_46 )
F_10 ( F_17 ( V_63 , V_46 ) , V_11 ) ;
}
static inline void F_56 ( struct V_10 * V_11 )
{
if ( ! ( V_11 -> V_26 & V_33 ) )
V_11 -> V_50 |= V_51 ;
V_11 -> V_26 |= V_33 ;
}
static int F_57 ( struct V_10 * V_11 )
{
void * V_85 [] = { F_1 , F_3 , F_5 } ;
const struct V_86 * V_87 = V_11 -> V_15 ;
const struct V_88 * V_9 ;
unsigned V_56 , V_89 , V_44 , V_90 ;
int V_66 ;
T_4 V_55 ;
for ( V_56 = 0 ; V_56 < V_87 -> V_16 ; V_56 ++ ) {
T_3 V_18 ;
V_9 = & ( V_87 -> V_17 [ V_56 ] ) ;
V_55 = V_9 -> V_55 ;
V_18 = F_58 ( V_9 ) ;
if ( V_11 -> V_12 == NULL )
V_11 -> V_60 [ V_56 ] = V_11 -> V_13 * 4 ;
switch ( V_18 ) {
case V_36 | V_91 :
F_36 ( V_21 , V_55 , V_11 ) ;
break;
case V_36 | V_37 | V_38 :
V_11 -> V_26 |= V_29 ;
F_59 ( F_60 ( struct V_1 , V_16 ) != 4 ) ;
F_10 ( F_21 ( V_21 , V_30 ,
F_20 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_36 | V_92 :
V_11 -> V_26 |= F_61 ( V_55 ) ;
F_10 ( F_21 ( V_21 , V_45 , F_62 ( V_55 ) ) , V_11 ) ;
break;
case V_36 | V_37 | V_39 :
V_89 = 2 ;
goto V_93;
case V_36 | V_40 | V_39 :
V_89 = 1 ;
goto V_93;
case V_36 | V_41 | V_39 :
V_89 = 0 ;
V_93:
if ( ( int ) V_55 < 0 )
return - V_94 ;
F_36 ( V_95 , V_55 , V_11 ) ;
V_96:
V_11 -> V_26 |= V_28 | V_27 ;
if ( V_89 > 0 ) {
F_10 ( F_19 ( V_49 , V_32 ,
1 << V_89 ) , V_11 ) ;
F_10 ( F_63 ( V_49 , V_95 ) , V_11 ) ;
V_90 = V_97 ;
} else {
F_10 ( F_63 ( V_32 , V_95 ) , V_11 ) ;
V_90 = V_98 ;
}
F_8 ( V_90 , F_64 ( V_49 , V_95 , V_31 ) ,
V_11 ) ;
if ( V_89 == 0 )
F_8 ( V_90 , F_38 ( V_21 , V_49 , 0 ) ,
V_11 ) ;
else if ( V_89 == 1 )
F_42 ( V_90 , V_21 , V_49 , V_11 ) ;
else if ( V_89 == 2 )
F_37 ( V_90 , V_21 , V_49 , V_11 ) ;
F_8 ( V_90 , F_51 ( F_49 ( V_56 + 1 , V_11 ) ) , V_11 ) ;
F_36 ( V_69 , ( T_4 ) V_85 [ V_89 ] , V_11 ) ;
F_10 ( F_17 ( V_46 , V_30 ) , V_11 ) ;
F_52 ( V_69 , V_11 ) ;
F_10 ( F_65 ( V_70 , 0 ) , V_11 ) ;
F_50 ( V_99 , V_11 ) ;
F_10 ( F_17 ( V_21 , V_46 ) , V_11 ) ;
break;
case V_36 | V_37 | V_100 :
V_89 = 2 ;
goto V_101;
case V_36 | V_40 | V_100 :
V_89 = 1 ;
goto V_101;
case V_36 | V_41 | V_100 :
V_89 = 0 ;
V_101:
F_66 ( V_102 , V_95 , V_34 , V_55 , V_11 ) ;
goto V_96;
case V_103 | V_91 :
V_11 -> V_26 |= V_33 ;
F_36 ( V_34 , V_55 , V_11 ) ;
break;
case V_103 | V_37 | V_38 :
V_11 -> V_26 |= V_33 | V_29 ;
F_10 ( F_21 ( V_34 , V_30 ,
F_20 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_103 | V_92 :
V_11 -> V_26 |= V_33 | F_61 ( V_55 ) ;
F_10 ( F_21 ( V_34 , V_45 , F_62 ( V_55 ) ) , V_11 ) ;
break;
case V_103 | V_41 | V_104 :
V_11 -> V_26 |= V_33 | V_28 | V_27 ;
if ( ( int ) V_55 < 0 )
return - 1 ;
F_36 ( V_95 , V_55 , V_11 ) ;
F_10 ( F_63 ( V_32 , V_95 ) , V_11 ) ;
F_8 ( V_98 , F_67 ( V_46 , V_31 ,
V_70 ) , V_11 ) ;
F_8 ( V_98 , F_51 ( F_49 ( V_56 + 1 , V_11 ) - 2 ) , V_11 ) ;
F_10 ( F_17 ( V_46 , V_30 ) , V_11 ) ;
F_36 ( V_69 , ( T_4 ) F_1 , V_11 ) ;
F_52 ( V_69 , V_11 ) ;
F_10 ( F_65 ( V_70 , 0 ) , V_11 ) ;
F_50 ( V_99 , V_11 ) ;
F_10 ( F_68 ( V_34 , V_46 , 0x00f ) , V_11 ) ;
F_10 ( F_39 ( V_34 , V_34 , 2 ) , V_11 ) ;
break;
case V_105 :
V_11 -> V_26 |= F_61 ( V_55 ) ;
F_10 ( F_69 ( V_21 , V_45 , F_62 ( V_55 ) ) , V_11 ) ;
break;
case V_106 :
F_56 ( V_11 ) ;
V_11 -> V_26 |= F_61 ( V_55 ) ;
F_10 ( F_69 ( V_34 , V_45 , F_62 ( V_55 ) ) , V_11 ) ;
break;
case V_107 | V_108 | V_52 :
F_66 ( V_102 , V_21 , V_21 , V_55 , V_11 ) ;
break;
case V_107 | V_108 | V_109 :
F_56 ( V_11 ) ;
F_10 ( F_64 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_107 | V_110 | V_52 :
F_66 ( V_111 , V_21 , V_21 , V_55 , V_11 ) ;
break;
case V_107 | V_110 | V_109 :
F_56 ( V_11 ) ;
F_10 ( F_22 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_107 | V_112 | V_52 :
F_36 ( V_49 , V_55 , V_11 ) ;
F_10 ( F_70 ( V_21 , V_21 , V_49 ) , V_11 ) ;
break;
case V_107 | V_112 | V_109 :
F_56 ( V_11 ) ;
F_10 ( F_70 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_107 | V_113 | V_52 :
if ( V_55 == 1 )
break;
F_36 ( V_49 , V_55 , V_11 ) ;
F_54 ( V_21 , V_21 , V_49 , V_11 ) ;
break;
case V_107 | V_113 | V_109 :
F_56 ( V_11 ) ;
F_10 ( F_65 ( V_34 , 0 ) , V_11 ) ;
F_50 ( V_114 , V_11 ) ;
F_54 ( V_21 , V_21 , V_34 , V_11 ) ;
break;
case V_107 | V_115 | V_52 :
F_66 ( V_116 , V_21 , V_21 , V_55 , V_11 ) ;
break;
case V_107 | V_115 | V_109 :
F_56 ( V_11 ) ;
F_10 ( F_41 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_107 | V_117 | V_52 :
F_66 ( V_118 , V_21 , V_21 , V_55 , V_11 ) ;
break;
case V_119 | V_120 :
case V_107 | V_117 | V_109 :
F_56 ( V_11 ) ;
F_10 ( F_71 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_107 | V_121 | V_52 :
F_66 ( V_122 , V_21 , V_21 , V_55 , V_11 ) ;
break;
case V_107 | V_121 | V_109 :
F_56 ( V_11 ) ;
F_10 ( F_72 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_107 | V_123 | V_52 :
if ( F_73 ( V_55 > 31 ) )
return - 1 ;
F_10 ( F_39 ( V_21 , V_21 , V_55 ) , V_11 ) ;
break;
case V_107 | V_123 | V_109 :
F_56 ( V_11 ) ;
F_10 ( F_74 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_107 | V_124 | V_52 :
if ( F_73 ( V_55 > 31 ) )
return - 1 ;
F_10 ( F_75 ( V_21 , V_21 , V_55 ) , V_11 ) ;
break;
case V_107 | V_124 | V_109 :
F_56 ( V_11 ) ;
F_10 ( F_76 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_107 | V_125 :
F_10 ( F_77 ( V_21 , V_21 , 0 ) , V_11 ) ;
break;
case V_126 | V_127 :
F_10 ( F_51 ( F_49 ( V_56 + V_55 + 1 , V_11 ) ) , V_11 ) ;
break;
case V_126 | V_128 | V_52 :
V_90 = V_114 ;
goto V_129;
case V_126 | V_130 | V_52 :
V_90 = V_98 ;
goto V_129;
case V_126 | V_131 | V_52 :
V_90 = V_97 ;
V_129:
V_66 = F_29 ( V_55 ) ;
if ( V_66 < 0 ) {
F_33 ( V_49 , V_55 , V_11 ) ;
F_10 ( F_63 ( V_21 , V_49 ) , V_11 ) ;
} else {
F_10 ( F_65 ( V_21 , V_66 ) , V_11 ) ;
}
V_132:
if ( V_9 -> V_133 )
F_8 ( V_90 , F_51 ( F_49 ( V_56 + V_9 -> V_133 + 1 ,
V_11 ) ) , V_11 ) ;
if ( V_9 -> V_134 )
F_8 ( V_90 ^ 1 , F_51 ( F_49 ( V_56 + V_9 -> V_134 + 1 ,
V_11 ) ) , V_11 ) ;
break;
case V_126 | V_128 | V_109 :
V_90 = V_114 ;
goto V_135;
case V_126 | V_130 | V_109 :
V_90 = V_98 ;
goto V_135;
case V_126 | V_131 | V_109 :
V_90 = V_136 ;
V_135:
F_56 ( V_11 ) ;
F_10 ( F_63 ( V_21 , V_34 ) , V_11 ) ;
goto V_132;
case V_126 | V_137 | V_52 :
V_90 = V_99 ;
V_66 = F_29 ( V_55 ) ;
if ( V_66 < 0 ) {
F_33 ( V_49 , V_55 , V_11 ) ;
F_10 ( F_78 ( V_21 , V_49 ) , V_11 ) ;
} else {
F_10 ( F_79 ( V_21 , V_66 ) , V_11 ) ;
}
goto V_132;
case V_126 | V_137 | V_109 :
F_56 ( V_11 ) ;
V_90 = V_99 ;
F_10 ( F_78 ( V_21 , V_34 ) , V_11 ) ;
goto V_132;
case V_19 | V_20 :
F_10 ( F_17 ( V_46 , V_21 ) , V_11 ) ;
goto V_138;
case V_19 | V_52 :
if ( ( V_55 == 0 ) && ( V_11 -> V_78 < 0 ) )
V_11 -> V_78 = V_56 ;
F_36 ( V_46 , V_55 , V_11 ) ;
V_138:
if ( V_56 != V_11 -> V_15 -> V_16 - 1 )
F_10 ( F_51 ( F_49 ( V_87 -> V_16 , V_11 ) ) , V_11 ) ;
break;
case V_139 | V_140 :
V_11 -> V_26 |= V_33 ;
F_10 ( F_17 ( V_34 , V_21 ) , V_11 ) ;
break;
case V_139 | V_141 :
F_56 ( V_11 ) ;
F_10 ( F_17 ( V_21 , V_34 ) , V_11 ) ;
break;
case V_119 | V_142 :
V_11 -> V_26 |= V_29 ;
F_59 ( F_60 ( struct V_1 ,
V_143 ) != 2 ) ;
V_44 = F_20 ( struct V_1 , V_143 ) ;
F_10 ( F_47 ( V_49 , V_30 , V_44 ) , V_11 ) ;
F_43 ( V_21 , V_49 , V_11 ) ;
break;
case V_119 | V_144 :
F_66 ( V_145 , V_49 , V_45 , V_146 - 1 , V_11 ) ;
F_59 ( F_60 ( struct V_147 , V_148 ) != 4 ) ;
V_44 = F_20 ( struct V_147 , V_148 ) ;
F_10 ( F_21 ( V_21 , V_49 , V_44 ) , V_11 ) ;
break;
case V_119 | V_149 :
V_11 -> V_26 |= V_29 ;
V_44 = F_20 ( struct V_1 , V_150 ) ;
F_10 ( F_21 ( V_49 , V_30 , V_44 ) , V_11 ) ;
F_10 ( F_65 ( V_49 , 0 ) , V_11 ) ;
F_50 ( V_114 , V_11 ) ;
F_59 ( F_60 ( struct V_151 ,
V_152 ) != 4 ) ;
V_44 = F_20 ( struct V_151 , V_152 ) ;
F_10 ( F_21 ( V_21 , V_49 , V_44 ) , V_11 ) ;
break;
case V_119 | V_153 :
V_11 -> V_26 |= V_29 ;
F_59 ( F_60 ( struct V_1 , V_154 ) != 4 ) ;
V_44 = F_20 ( struct V_1 , V_154 ) ;
F_10 ( F_21 ( V_21 , V_30 , V_44 ) , V_11 ) ;
break;
case V_119 | V_155 :
V_11 -> V_26 |= V_29 ;
F_59 ( F_60 ( struct V_1 , V_156 ) != 4 ) ;
V_44 = F_20 ( struct V_1 , V_156 ) ;
F_10 ( F_21 ( V_21 , V_30 , V_44 ) , V_11 ) ;
break;
case V_119 | V_157 :
case V_119 | V_158 :
V_11 -> V_26 |= V_29 ;
F_59 ( F_60 ( struct V_1 , V_159 ) != 2 ) ;
V_44 = F_20 ( struct V_1 , V_159 ) ;
F_10 ( F_47 ( V_21 , V_30 , V_44 ) , V_11 ) ;
if ( V_18 == ( V_119 | V_157 ) )
F_66 ( V_122 , V_21 , V_21 , V_160 , V_11 ) ;
else
F_66 ( V_122 , V_21 , V_21 , V_161 , V_11 ) ;
break;
case V_119 | V_162 :
V_11 -> V_26 |= V_29 ;
F_59 ( F_60 ( struct V_1 ,
V_163 ) != 2 ) ;
F_59 ( F_20 ( struct V_1 ,
V_163 ) > 0xff ) ;
V_44 = F_20 ( struct V_1 , V_163 ) ;
F_10 ( F_47 ( V_21 , V_30 , V_44 ) , V_11 ) ;
break;
default:
return - 1 ;
}
}
if ( V_11 -> V_12 == NULL )
V_11 -> V_60 [ V_56 ] = V_11 -> V_13 * 4 ;
return 0 ;
}
void F_80 ( struct V_86 * V_164 )
{
struct V_10 V_11 ;
unsigned V_165 ;
unsigned V_166 ;
if ( ! V_167 )
return;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_15 = V_164 ;
V_11 . V_78 = - 1 ;
V_11 . V_60 = F_81 ( 4 * ( V_11 . V_15 -> V_16 + 1 ) , V_168 ) ;
if ( V_11 . V_60 == NULL )
return;
if ( F_73 ( F_57 ( & V_11 ) ) )
goto V_169;
V_165 = V_11 . V_13 ;
F_16 ( & V_11 ) ;
V_11 . V_61 = ( V_11 . V_13 - V_165 ) * 4 ;
#if V_65 < 7
V_165 = V_11 . V_13 ;
F_24 ( & V_11 ) ;
V_11 . V_62 = ( V_11 . V_13 - V_165 ) * 4 ;
V_11 . V_13 += V_11 . V_58 ;
if ( V_11 . V_58 ) {
V_11 . V_59 = F_81 ( 4 * V_11 . V_58 , V_168 ) ;
if ( V_11 . V_59 == NULL )
goto V_169;
}
#else
F_24 ( & V_11 ) ;
#endif
V_166 = 4 * V_11 . V_13 ;
V_11 . V_12 = F_82 ( V_166 ) ;
if ( F_73 ( V_11 . V_12 == NULL ) )
goto V_169;
V_11 . V_13 = 0 ;
F_16 ( & V_11 ) ;
F_57 ( & V_11 ) ;
F_24 ( & V_11 ) ;
F_83 ( ( T_4 ) V_11 . V_12 , ( T_4 ) ( V_11 . V_12 + V_11 . V_13 ) ) ;
#if V_65 < 7
if ( V_11 . V_58 )
F_84 ( V_11 . V_59 ) ;
#endif
if ( V_167 > 1 )
F_85 ( V_164 -> V_16 , V_166 , 2 , V_11 . V_12 ) ;
V_164 -> V_170 = ( void * ) V_11 . V_12 ;
V_164 -> V_171 = 1 ;
V_169:
F_84 ( V_11 . V_60 ) ;
return;
}
void F_86 ( struct V_86 * V_164 )
{
if ( V_164 -> V_171 )
F_87 ( NULL , V_164 -> V_170 ) ;
F_84 ( V_164 ) ;
}
