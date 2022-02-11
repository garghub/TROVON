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
static void F_16 ( void * V_42 , unsigned int V_43 )
{
T_4 * V_44 ;
for ( V_44 = V_42 ; V_43 >= sizeof( T_4 ) ; V_43 -= sizeof( T_4 ) )
* V_44 ++ = F_9 ( V_45 ) ;
}
static void F_17 ( struct V_10 * V_11 )
{
T_3 V_46 = F_11 ( V_11 ) ;
T_3 V_47 = V_11 -> V_15 -> V_17 [ 0 ] . V_18 ;
T_3 V_48 ;
#ifdef F_12
F_10 ( F_18 ( V_23 , V_49 ) , V_11 ) ;
F_10 ( F_19 ( V_46 ) , V_11 ) ;
F_10 ( F_20 ( V_22 , V_23 , 4 ) , V_11 ) ;
#else
if ( V_46 )
F_10 ( F_19 ( V_46 ) , V_11 ) ;
#endif
if ( V_11 -> V_26 & ( V_28 | V_29 ) )
F_10 ( F_18 ( V_30 , V_50 ) , V_11 ) ;
if ( V_11 -> V_26 & V_28 ) {
V_48 = F_21 ( struct V_1 , V_51 ) ;
F_10 ( F_22 ( V_31 , V_30 , V_48 ) , V_11 ) ;
V_48 = F_21 ( struct V_1 , V_16 ) ;
F_10 ( F_22 ( V_32 , V_30 , V_48 ) , V_11 ) ;
V_48 = F_21 ( struct V_1 , V_52 ) ;
F_10 ( F_22 ( V_53 , V_30 , V_48 ) , V_11 ) ;
F_10 ( F_23 ( V_32 , V_32 , V_53 ) , V_11 ) ;
}
if ( V_11 -> V_54 & V_55 )
F_10 ( F_24 ( V_34 , 0 ) , V_11 ) ;
if ( ( V_47 != ( V_19 | V_56 ) ) && ! ( F_15 ( V_47 ) ) )
F_10 ( F_24 ( V_21 , 0 ) , V_11 ) ;
if ( V_11 -> V_26 & V_35 )
F_10 ( F_20 ( V_49 , V_49 , F_13 ( V_11 ) * 4 ) , V_11 ) ;
}
static void F_25 ( struct V_10 * V_11 )
{
T_3 V_46 = F_11 ( V_11 ) ;
if ( V_11 -> V_26 & V_35 )
F_10 ( F_26 ( V_49 , V_49 , F_13 ( V_11 ) * 4 ) , V_11 ) ;
V_46 &= ~ ( 1 << V_24 ) ;
#ifdef F_12
V_46 &= ~ ( 1 << V_23 ) ;
V_46 |= ( 1 << V_49 ) ;
F_10 ( F_27 ( V_49 , V_46 ) , V_11 ) ;
#else
if ( V_46 ) {
if ( V_11 -> V_26 & V_27 )
V_46 |= 1 << V_25 ;
F_10 ( F_28 ( V_46 ) , V_11 ) ;
}
if ( ! ( V_11 -> V_26 & V_27 ) )
F_10 ( F_29 ( V_24 ) , V_11 ) ;
#endif
}
static T_5 F_30 ( T_4 V_57 )
{
T_4 V_58 ;
for ( V_58 = 0 ; V_58 < 16 ; V_58 ++ )
if ( ( V_57 & ~ F_31 ( 0xff , 2 * V_58 ) ) == 0 )
return F_32 ( V_57 , 2 * V_58 ) | ( V_58 << 8 ) ;
return - 1 ;
}
static T_3 F_33 ( T_4 V_59 , struct V_10 * V_11 )
{
unsigned V_60 = 0 , V_3 ;
T_3 V_61 ;
if ( V_11 -> V_12 == NULL ) {
V_11 -> V_62 ++ ;
return 0 ;
}
while ( ( V_60 < V_11 -> V_62 ) && V_11 -> V_63 [ V_60 ] ) {
if ( V_11 -> V_63 [ V_60 ] == V_59 )
break;
V_60 ++ ;
}
if ( V_11 -> V_63 [ V_60 ] == 0 )
V_11 -> V_63 [ V_60 ] = V_59 ;
V_3 = V_11 -> V_64 [ V_11 -> V_15 -> V_16 ] ;
V_3 += V_11 -> V_65 ;
V_3 += V_11 -> V_66 ;
V_3 += V_60 * 4 ;
V_11 -> V_12 [ V_3 / 4 ] = V_59 ;
V_61 = V_3 - ( 8 + V_11 -> V_13 * 4 ) ;
if ( V_61 & ~ 0xfff ) {
V_11 -> V_54 |= V_67 ;
return 0 ;
}
return V_61 ;
}
static inline void F_34 ( int V_68 , T_4 V_69 , struct V_10 * V_11 )
{
#if V_70 < 7
F_10 ( F_22 ( V_68 , V_25 , F_33 ( V_69 , V_11 ) ) , V_11 ) ;
#else
F_10 ( F_35 ( V_68 , V_69 & 0xffff ) , V_11 ) ;
if ( V_69 > 0xffff )
F_10 ( F_36 ( V_68 , V_69 >> 16 ) , V_11 ) ;
#endif
}
static inline void F_37 ( int V_68 , T_4 V_69 , struct V_10 * V_11 )
{
int V_71 = F_30 ( V_69 ) ;
if ( V_71 >= 0 )
F_10 ( F_24 ( V_68 , V_71 ) , V_11 ) ;
else
F_34 ( V_68 , V_69 , V_11 ) ;
}
static void F_38 ( T_2 V_8 , T_2 V_72 , T_2 V_73 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_39 ( V_74 , V_73 , 1 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_75 , V_73 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_76 , V_73 , 3 ) , V_11 ) ;
F_8 ( V_8 , F_40 ( V_74 , V_74 , 16 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_50 , V_73 , 2 ) , V_11 ) ;
F_8 ( V_8 , F_41 ( V_74 , V_74 , V_75 , V_77 , 24 ) , V_11 ) ;
F_8 ( V_8 , F_42 ( V_74 , V_74 , V_76 ) , V_11 ) ;
F_8 ( V_8 , F_41 ( V_72 , V_74 , V_50 , V_77 , 8 ) , V_11 ) ;
}
static void F_43 ( T_2 V_8 , T_2 V_72 , T_2 V_73 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_39 ( V_75 , V_73 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_76 , V_73 , 1 ) , V_11 ) ;
F_8 ( V_8 , F_41 ( V_72 , V_76 , V_75 , V_77 , 8 ) , V_11 ) ;
}
static inline void F_44 ( T_2 V_78 , T_2 V_79 , struct V_10 * V_11 )
{
F_10 ( F_40 ( V_75 , V_79 , 8 ) , V_11 ) ;
F_10 ( F_41 ( V_78 , V_75 , V_79 , V_80 , 8 ) , V_11 ) ;
F_10 ( F_45 ( V_78 , V_78 , 0x8ff ) , V_11 ) ;
}
static void F_38 ( T_2 V_8 , T_2 V_72 , T_2 V_73 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_22 ( V_72 , V_73 , 0 ) , V_11 ) ;
#ifdef F_46
F_8 ( V_8 , F_47 ( V_72 , V_72 ) , V_11 ) ;
#endif
}
static void F_43 ( T_2 V_8 , T_2 V_72 , T_2 V_73 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_48 ( V_72 , V_73 , 0 ) , V_11 ) ;
#ifdef F_46
F_8 ( V_8 , F_49 ( V_72 , V_72 ) , V_11 ) ;
#endif
}
static inline void F_44 ( T_2 V_78 V_81 ,
T_2 V_79 V_81 ,
struct V_10 * V_11 V_81 )
{
#ifdef F_46
F_10 ( F_49 ( V_78 , V_79 ) , V_11 ) ;
#endif
}
static inline T_4 F_50 ( unsigned V_82 , struct V_10 * V_11 )
{
T_4 V_61 ;
if ( V_11 -> V_12 == NULL )
return 0 ;
V_61 = V_11 -> V_64 [ V_82 ] + V_11 -> V_65 - ( V_11 -> V_13 * 4 + 8 ) ;
return V_61 >> 2 ;
}
static inline void F_51 ( T_2 V_8 , struct V_10 * V_11 )
{
if ( V_11 -> V_83 >= 0 ) {
F_8 ( V_8 , F_52 ( F_50 ( V_11 -> V_83 , V_11 ) ) , V_11 ) ;
F_10 ( F_18 ( V_50 , V_50 ) , V_11 ) ;
} else {
F_8 ( V_8 , F_24 ( V_50 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_52 ( F_50 ( V_11 -> V_15 -> V_16 , V_11 ) ) , V_11 ) ;
}
}
static inline void F_53 ( T_2 V_84 , struct V_10 * V_11 )
{
#if V_70 < 5
F_10 ( F_18 ( V_24 , V_25 ) , V_11 ) ;
if ( V_85 & V_86 )
F_10 ( F_29 ( V_84 ) , V_11 ) ;
else
F_10 ( F_18 ( V_25 , V_84 ) , V_11 ) ;
#else
F_10 ( F_54 ( V_84 ) , V_11 ) ;
#endif
}
static inline void F_55 ( T_2 V_68 , T_2 V_87 , T_2 V_88 , struct V_10 * V_11 )
{
#if V_70 == 7
if ( V_85 & V_89 ) {
F_10 ( F_56 ( V_68 , V_87 , V_88 ) , V_11 ) ;
return;
}
#endif
if ( V_88 != V_75 )
F_10 ( F_18 ( V_75 , V_88 ) , V_11 ) ;
if ( V_87 != V_50 )
F_10 ( F_18 ( V_50 , V_87 ) , V_11 ) ;
V_11 -> V_26 |= V_27 ;
F_37 ( V_74 , ( T_4 ) F_7 , V_11 ) ;
F_53 ( V_74 , V_11 ) ;
if ( V_68 != V_50 )
F_10 ( F_18 ( V_68 , V_50 ) , V_11 ) ;
}
static inline void F_57 ( struct V_10 * V_11 )
{
if ( ! ( V_11 -> V_26 & V_33 ) )
V_11 -> V_54 |= V_55 ;
V_11 -> V_26 |= V_33 ;
}
static int F_58 ( struct V_10 * V_11 )
{
void * V_90 [] = { F_1 , F_3 , F_5 } ;
const struct V_91 * V_92 = V_11 -> V_15 ;
const struct V_93 * V_9 ;
unsigned V_60 , V_94 , V_48 , V_95 ;
int V_71 ;
T_4 V_59 ;
for ( V_60 = 0 ; V_60 < V_92 -> V_16 ; V_60 ++ ) {
T_3 V_18 ;
V_9 = & ( V_92 -> V_17 [ V_60 ] ) ;
V_59 = V_9 -> V_59 ;
V_18 = F_59 ( V_9 ) ;
if ( V_11 -> V_12 == NULL )
V_11 -> V_64 [ V_60 ] = V_11 -> V_13 * 4 ;
switch ( V_18 ) {
case V_36 | V_96 :
F_37 ( V_21 , V_59 , V_11 ) ;
break;
case V_36 | V_37 | V_38 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 , V_16 ) != 4 ) ;
F_10 ( F_22 ( V_21 , V_30 ,
F_21 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_36 | V_97 :
V_11 -> V_26 |= F_62 ( V_59 ) ;
F_10 ( F_22 ( V_21 , V_49 , F_63 ( V_59 ) ) , V_11 ) ;
break;
case V_36 | V_37 | V_39 :
V_94 = 2 ;
goto V_98;
case V_36 | V_40 | V_39 :
V_94 = 1 ;
goto V_98;
case V_36 | V_41 | V_39 :
V_94 = 0 ;
V_98:
if ( ( int ) V_59 < 0 )
return - V_99 ;
F_37 ( V_100 , V_59 , V_11 ) ;
V_101:
V_11 -> V_26 |= V_28 | V_27 ;
if ( V_94 > 0 ) {
F_10 ( F_20 ( V_53 , V_32 ,
1 << V_94 ) , V_11 ) ;
F_10 ( F_64 ( V_53 , V_100 ) , V_11 ) ;
V_95 = V_102 ;
} else {
F_10 ( F_64 ( V_32 , V_100 ) , V_11 ) ;
V_95 = V_103 ;
}
F_8 ( V_95 , F_65 ( V_53 , V_100 , V_31 ) ,
V_11 ) ;
if ( V_94 == 0 )
F_8 ( V_95 , F_39 ( V_21 , V_53 , 0 ) ,
V_11 ) ;
else if ( V_94 == 1 )
F_43 ( V_95 , V_21 , V_53 , V_11 ) ;
else if ( V_94 == 2 )
F_38 ( V_95 , V_21 , V_53 , V_11 ) ;
F_8 ( V_95 , F_52 ( F_50 ( V_60 + 1 , V_11 ) ) , V_11 ) ;
F_37 ( V_74 , ( T_4 ) V_90 [ V_94 ] , V_11 ) ;
F_10 ( F_18 ( V_50 , V_30 ) , V_11 ) ;
F_53 ( V_74 , V_11 ) ;
F_10 ( F_66 ( V_75 , 0 ) , V_11 ) ;
F_51 ( V_104 , V_11 ) ;
F_10 ( F_18 ( V_21 , V_50 ) , V_11 ) ;
break;
case V_36 | V_37 | V_105 :
V_94 = 2 ;
goto V_106;
case V_36 | V_40 | V_105 :
V_94 = 1 ;
goto V_106;
case V_36 | V_41 | V_105 :
V_94 = 0 ;
V_106:
F_67 ( V_107 , V_100 , V_34 , V_59 , V_11 ) ;
goto V_101;
case V_108 | V_96 :
V_11 -> V_26 |= V_33 ;
F_37 ( V_34 , V_59 , V_11 ) ;
break;
case V_108 | V_37 | V_38 :
V_11 -> V_26 |= V_33 | V_29 ;
F_10 ( F_22 ( V_34 , V_30 ,
F_21 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_108 | V_97 :
V_11 -> V_26 |= V_33 | F_62 ( V_59 ) ;
F_10 ( F_22 ( V_34 , V_49 , F_63 ( V_59 ) ) , V_11 ) ;
break;
case V_108 | V_41 | V_109 :
V_11 -> V_26 |= V_33 | V_28 | V_27 ;
if ( ( int ) V_59 < 0 )
return - 1 ;
F_37 ( V_100 , V_59 , V_11 ) ;
F_10 ( F_64 ( V_32 , V_100 ) , V_11 ) ;
F_8 ( V_103 , F_68 ( V_50 , V_31 ,
V_75 ) , V_11 ) ;
F_8 ( V_103 , F_52 ( F_50 ( V_60 + 1 , V_11 ) - 2 ) , V_11 ) ;
F_10 ( F_18 ( V_50 , V_30 ) , V_11 ) ;
F_37 ( V_74 , ( T_4 ) F_1 , V_11 ) ;
F_53 ( V_74 , V_11 ) ;
F_10 ( F_66 ( V_75 , 0 ) , V_11 ) ;
F_51 ( V_104 , V_11 ) ;
F_10 ( F_69 ( V_34 , V_50 , 0x00f ) , V_11 ) ;
F_10 ( F_40 ( V_34 , V_34 , 2 ) , V_11 ) ;
break;
case V_110 :
V_11 -> V_26 |= F_62 ( V_59 ) ;
F_10 ( F_70 ( V_21 , V_49 , F_63 ( V_59 ) ) , V_11 ) ;
break;
case V_111 :
F_57 ( V_11 ) ;
V_11 -> V_26 |= F_62 ( V_59 ) ;
F_10 ( F_70 ( V_34 , V_49 , F_63 ( V_59 ) ) , V_11 ) ;
break;
case V_112 | V_113 | V_56 :
F_67 ( V_107 , V_21 , V_21 , V_59 , V_11 ) ;
break;
case V_112 | V_113 | V_114 :
F_57 ( V_11 ) ;
F_10 ( F_65 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_112 | V_115 | V_56 :
F_67 ( V_116 , V_21 , V_21 , V_59 , V_11 ) ;
break;
case V_112 | V_115 | V_114 :
F_57 ( V_11 ) ;
F_10 ( F_23 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_112 | V_117 | V_56 :
F_37 ( V_53 , V_59 , V_11 ) ;
F_10 ( F_71 ( V_21 , V_21 , V_53 ) , V_11 ) ;
break;
case V_112 | V_117 | V_114 :
F_57 ( V_11 ) ;
F_10 ( F_71 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_112 | V_118 | V_56 :
if ( V_59 == 1 )
break;
F_37 ( V_53 , V_59 , V_11 ) ;
F_55 ( V_21 , V_21 , V_53 , V_11 ) ;
break;
case V_112 | V_118 | V_114 :
F_57 ( V_11 ) ;
F_10 ( F_66 ( V_34 , 0 ) , V_11 ) ;
F_51 ( V_119 , V_11 ) ;
F_55 ( V_21 , V_21 , V_34 , V_11 ) ;
break;
case V_112 | V_120 | V_56 :
F_67 ( V_121 , V_21 , V_21 , V_59 , V_11 ) ;
break;
case V_112 | V_120 | V_114 :
F_57 ( V_11 ) ;
F_10 ( F_42 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_112 | V_122 | V_56 :
F_67 ( V_123 , V_21 , V_21 , V_59 , V_11 ) ;
break;
case V_124 | V_125 :
case V_112 | V_122 | V_114 :
F_57 ( V_11 ) ;
F_10 ( F_72 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_112 | V_126 | V_56 :
F_67 ( V_127 , V_21 , V_21 , V_59 , V_11 ) ;
break;
case V_112 | V_126 | V_114 :
F_57 ( V_11 ) ;
F_10 ( F_73 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_112 | V_128 | V_56 :
if ( F_74 ( V_59 > 31 ) )
return - 1 ;
F_10 ( F_40 ( V_21 , V_21 , V_59 ) , V_11 ) ;
break;
case V_112 | V_128 | V_114 :
F_57 ( V_11 ) ;
F_10 ( F_75 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_112 | V_129 | V_56 :
if ( F_74 ( V_59 > 31 ) )
return - 1 ;
F_10 ( F_76 ( V_21 , V_21 , V_59 ) , V_11 ) ;
break;
case V_112 | V_129 | V_114 :
F_57 ( V_11 ) ;
F_10 ( F_77 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_112 | V_130 :
F_10 ( F_78 ( V_21 , V_21 , 0 ) , V_11 ) ;
break;
case V_131 | V_132 :
F_10 ( F_52 ( F_50 ( V_60 + V_59 + 1 , V_11 ) ) , V_11 ) ;
break;
case V_131 | V_133 | V_56 :
V_95 = V_119 ;
goto V_134;
case V_131 | V_135 | V_56 :
V_95 = V_103 ;
goto V_134;
case V_131 | V_136 | V_56 :
V_95 = V_102 ;
V_134:
V_71 = F_30 ( V_59 ) ;
if ( V_71 < 0 ) {
F_34 ( V_53 , V_59 , V_11 ) ;
F_10 ( F_64 ( V_21 , V_53 ) , V_11 ) ;
} else {
F_10 ( F_66 ( V_21 , V_71 ) , V_11 ) ;
}
V_137:
if ( V_9 -> V_138 )
F_8 ( V_95 , F_52 ( F_50 ( V_60 + V_9 -> V_138 + 1 ,
V_11 ) ) , V_11 ) ;
if ( V_9 -> V_139 )
F_8 ( V_95 ^ 1 , F_52 ( F_50 ( V_60 + V_9 -> V_139 + 1 ,
V_11 ) ) , V_11 ) ;
break;
case V_131 | V_133 | V_114 :
V_95 = V_119 ;
goto V_140;
case V_131 | V_135 | V_114 :
V_95 = V_103 ;
goto V_140;
case V_131 | V_136 | V_114 :
V_95 = V_141 ;
V_140:
F_57 ( V_11 ) ;
F_10 ( F_64 ( V_21 , V_34 ) , V_11 ) ;
goto V_137;
case V_131 | V_142 | V_56 :
V_95 = V_104 ;
V_71 = F_30 ( V_59 ) ;
if ( V_71 < 0 ) {
F_34 ( V_53 , V_59 , V_11 ) ;
F_10 ( F_79 ( V_21 , V_53 ) , V_11 ) ;
} else {
F_10 ( F_80 ( V_21 , V_71 ) , V_11 ) ;
}
goto V_137;
case V_131 | V_142 | V_114 :
F_57 ( V_11 ) ;
V_95 = V_104 ;
F_10 ( F_79 ( V_21 , V_34 ) , V_11 ) ;
goto V_137;
case V_19 | V_20 :
F_10 ( F_18 ( V_50 , V_21 ) , V_11 ) ;
goto V_143;
case V_19 | V_56 :
if ( ( V_59 == 0 ) && ( V_11 -> V_83 < 0 ) )
V_11 -> V_83 = V_60 ;
F_37 ( V_50 , V_59 , V_11 ) ;
V_143:
if ( V_60 != V_11 -> V_15 -> V_16 - 1 )
F_10 ( F_52 ( F_50 ( V_92 -> V_16 , V_11 ) ) , V_11 ) ;
break;
case V_144 | V_145 :
V_11 -> V_26 |= V_33 ;
F_10 ( F_18 ( V_34 , V_21 ) , V_11 ) ;
break;
case V_144 | V_146 :
F_57 ( V_11 ) ;
F_10 ( F_18 ( V_21 , V_34 ) , V_11 ) ;
break;
case V_124 | V_147 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 ,
V_148 ) != 2 ) ;
V_48 = F_21 ( struct V_1 , V_148 ) ;
F_10 ( F_48 ( V_53 , V_30 , V_48 ) , V_11 ) ;
F_44 ( V_21 , V_53 , V_11 ) ;
break;
case V_124 | V_149 :
F_67 ( V_150 , V_53 , V_49 , V_151 - 1 , V_11 ) ;
F_60 ( F_61 ( struct V_152 , V_153 ) != 4 ) ;
V_48 = F_21 ( struct V_152 , V_153 ) ;
F_10 ( F_22 ( V_21 , V_53 , V_48 ) , V_11 ) ;
break;
case V_124 | V_154 :
V_11 -> V_26 |= V_29 ;
V_48 = F_21 ( struct V_1 , V_155 ) ;
F_10 ( F_22 ( V_53 , V_30 , V_48 ) , V_11 ) ;
F_10 ( F_66 ( V_53 , 0 ) , V_11 ) ;
F_51 ( V_119 , V_11 ) ;
F_60 ( F_61 ( struct V_156 ,
V_157 ) != 4 ) ;
V_48 = F_21 ( struct V_156 , V_157 ) ;
F_10 ( F_22 ( V_21 , V_53 , V_48 ) , V_11 ) ;
break;
case V_124 | V_158 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 , V_159 ) != 4 ) ;
V_48 = F_21 ( struct V_1 , V_159 ) ;
F_10 ( F_22 ( V_21 , V_30 , V_48 ) , V_11 ) ;
break;
case V_124 | V_160 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 , V_161 ) != 4 ) ;
V_48 = F_21 ( struct V_1 , V_161 ) ;
F_10 ( F_22 ( V_21 , V_30 , V_48 ) , V_11 ) ;
break;
case V_124 | V_162 :
case V_124 | V_163 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 , V_164 ) != 2 ) ;
V_48 = F_21 ( struct V_1 , V_164 ) ;
F_10 ( F_48 ( V_21 , V_30 , V_48 ) , V_11 ) ;
if ( V_18 == ( V_124 | V_162 ) )
F_67 ( V_127 , V_21 , V_21 , V_165 , V_11 ) ;
else
F_67 ( V_127 , V_21 , V_21 , V_166 , V_11 ) ;
break;
case V_124 | V_167 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 ,
V_168 ) != 2 ) ;
F_60 ( F_21 ( struct V_1 ,
V_168 ) > 0xff ) ;
V_48 = F_21 ( struct V_1 , V_168 ) ;
F_10 ( F_48 ( V_21 , V_30 , V_48 ) , V_11 ) ;
break;
default:
return - 1 ;
}
if ( V_11 -> V_54 & V_67 )
return - 1 ;
}
if ( V_11 -> V_12 == NULL )
V_11 -> V_64 [ V_60 ] = V_11 -> V_13 * 4 ;
return 0 ;
}
void F_81 ( struct V_91 * V_169 )
{
struct V_170 * V_171 ;
struct V_10 V_11 ;
unsigned V_172 ;
unsigned V_173 ;
T_2 * V_174 ;
if ( ! V_175 )
return;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_15 = V_169 ;
V_11 . V_83 = - 1 ;
V_11 . V_64 = F_82 ( 4 * ( V_11 . V_15 -> V_16 + 1 ) , V_176 ) ;
if ( V_11 . V_64 == NULL )
return;
if ( F_74 ( F_58 ( & V_11 ) ) )
goto V_177;
V_172 = V_11 . V_13 ;
F_17 ( & V_11 ) ;
V_11 . V_65 = ( V_11 . V_13 - V_172 ) * 4 ;
#if V_70 < 7
V_172 = V_11 . V_13 ;
F_25 ( & V_11 ) ;
V_11 . V_66 = ( V_11 . V_13 - V_172 ) * 4 ;
V_11 . V_13 += V_11 . V_62 ;
if ( V_11 . V_62 ) {
V_11 . V_63 = F_82 ( 4 * V_11 . V_62 , V_176 ) ;
if ( V_11 . V_63 == NULL )
goto V_177;
}
#else
F_25 ( & V_11 ) ;
#endif
V_173 = 4 * V_11 . V_13 ;
V_171 = F_83 ( V_173 , & V_174 ,
4 , F_16 ) ;
if ( V_171 == NULL )
goto V_177;
V_11 . V_12 = ( T_4 * ) V_174 ;
V_11 . V_13 = 0 ;
F_17 ( & V_11 ) ;
if ( F_58 ( & V_11 ) < 0 ) {
#if V_70 < 7
if ( V_11 . V_62 )
F_84 ( V_11 . V_63 ) ;
#endif
F_85 ( V_171 ) ;
goto V_177;
}
F_25 ( & V_11 ) ;
F_86 ( ( T_4 ) V_11 . V_12 , ( T_4 ) ( V_11 . V_12 + V_11 . V_13 ) ) ;
#if V_70 < 7
if ( V_11 . V_62 )
F_84 ( V_11 . V_63 ) ;
#endif
if ( V_175 > 1 )
F_87 ( V_169 -> V_16 , V_173 , 2 , V_11 . V_12 ) ;
F_88 ( ( unsigned long ) V_171 , V_171 -> V_178 ) ;
V_169 -> V_179 = ( void * ) V_11 . V_12 ;
V_169 -> V_180 = true ;
V_177:
F_84 ( V_11 . V_64 ) ;
return;
}
void F_89 ( struct V_91 * V_169 )
{
unsigned long V_181 = ( unsigned long ) V_169 -> V_179 & V_182 ;
struct V_170 * V_171 = ( void * ) V_181 ;
if ( ! V_169 -> V_180 )
goto V_183;
F_90 ( V_181 , V_171 -> V_178 ) ;
F_85 ( V_171 ) ;
V_183:
F_91 ( V_169 ) ;
}
