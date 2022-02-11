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
return V_61 ;
}
static inline void F_34 ( int V_67 , T_4 V_68 , struct V_10 * V_11 )
{
#if V_69 < 7
F_10 ( F_22 ( V_67 , V_25 , F_33 ( V_68 , V_11 ) ) , V_11 ) ;
#else
F_10 ( F_35 ( V_67 , V_68 & 0xffff ) , V_11 ) ;
if ( V_68 > 0xffff )
F_10 ( F_36 ( V_67 , V_68 >> 16 ) , V_11 ) ;
#endif
}
static inline void F_37 ( int V_67 , T_4 V_68 , struct V_10 * V_11 )
{
int V_70 = F_30 ( V_68 ) ;
if ( V_70 >= 0 )
F_10 ( F_24 ( V_67 , V_70 ) , V_11 ) ;
else
F_34 ( V_67 , V_68 , V_11 ) ;
}
static void F_38 ( T_2 V_8 , T_2 V_71 , T_2 V_72 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_39 ( V_73 , V_72 , 1 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_74 , V_72 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_75 , V_72 , 3 ) , V_11 ) ;
F_8 ( V_8 , F_40 ( V_73 , V_73 , 16 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_50 , V_72 , 2 ) , V_11 ) ;
F_8 ( V_8 , F_41 ( V_73 , V_73 , V_74 , V_76 , 24 ) , V_11 ) ;
F_8 ( V_8 , F_42 ( V_73 , V_73 , V_75 ) , V_11 ) ;
F_8 ( V_8 , F_41 ( V_71 , V_73 , V_50 , V_76 , 8 ) , V_11 ) ;
}
static void F_43 ( T_2 V_8 , T_2 V_71 , T_2 V_72 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_39 ( V_74 , V_72 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_39 ( V_75 , V_72 , 1 ) , V_11 ) ;
F_8 ( V_8 , F_41 ( V_71 , V_75 , V_74 , V_76 , 8 ) , V_11 ) ;
}
static inline void F_44 ( T_2 V_77 , T_2 V_78 , struct V_10 * V_11 )
{
F_10 ( F_40 ( V_74 , V_78 , 8 ) , V_11 ) ;
F_10 ( F_41 ( V_77 , V_74 , V_78 , V_79 , 8 ) , V_11 ) ;
F_10 ( F_45 ( V_77 , V_77 , 0x8ff ) , V_11 ) ;
}
static void F_38 ( T_2 V_8 , T_2 V_71 , T_2 V_72 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_22 ( V_71 , V_72 , 0 ) , V_11 ) ;
#ifdef F_46
F_8 ( V_8 , F_47 ( V_71 , V_71 ) , V_11 ) ;
#endif
}
static void F_43 ( T_2 V_8 , T_2 V_71 , T_2 V_72 , struct V_10 * V_11 )
{
F_8 ( V_8 , F_48 ( V_71 , V_72 , 0 ) , V_11 ) ;
#ifdef F_46
F_8 ( V_8 , F_49 ( V_71 , V_71 ) , V_11 ) ;
#endif
}
static inline void F_44 ( T_2 V_77 V_80 ,
T_2 V_78 V_80 ,
struct V_10 * V_11 V_80 )
{
#ifdef F_46
F_10 ( F_49 ( V_77 , V_78 ) , V_11 ) ;
#endif
}
static inline T_4 F_50 ( unsigned V_81 , struct V_10 * V_11 )
{
T_4 V_61 ;
if ( V_11 -> V_12 == NULL )
return 0 ;
V_61 = V_11 -> V_64 [ V_81 ] + V_11 -> V_65 - ( V_11 -> V_13 * 4 + 8 ) ;
return V_61 >> 2 ;
}
static inline void F_51 ( T_2 V_8 , struct V_10 * V_11 )
{
if ( V_11 -> V_82 >= 0 ) {
F_8 ( V_8 , F_52 ( F_50 ( V_11 -> V_82 , V_11 ) ) , V_11 ) ;
F_10 ( F_18 ( V_50 , V_50 ) , V_11 ) ;
} else {
F_8 ( V_8 , F_24 ( V_50 , 0 ) , V_11 ) ;
F_8 ( V_8 , F_52 ( F_50 ( V_11 -> V_15 -> V_16 , V_11 ) ) , V_11 ) ;
}
}
static inline void F_53 ( T_2 V_83 , struct V_10 * V_11 )
{
#if V_69 < 5
F_10 ( F_18 ( V_24 , V_25 ) , V_11 ) ;
if ( V_84 & V_85 )
F_10 ( F_29 ( V_83 ) , V_11 ) ;
else
F_10 ( F_18 ( V_25 , V_83 ) , V_11 ) ;
#else
F_10 ( F_54 ( V_83 ) , V_11 ) ;
#endif
}
static inline void F_55 ( T_2 V_67 , T_2 V_86 , T_2 V_87 , struct V_10 * V_11 )
{
#if V_69 == 7
if ( V_84 & V_88 ) {
F_10 ( F_56 ( V_67 , V_86 , V_87 ) , V_11 ) ;
return;
}
#endif
if ( V_86 != V_50 )
F_10 ( F_18 ( V_50 , V_86 ) , V_11 ) ;
if ( V_87 != V_74 )
F_10 ( F_18 ( V_74 , V_87 ) , V_11 ) ;
V_11 -> V_26 |= V_27 ;
F_37 ( V_73 , ( T_4 ) F_7 , V_11 ) ;
F_53 ( V_73 , V_11 ) ;
if ( V_67 != V_50 )
F_10 ( F_18 ( V_67 , V_50 ) , V_11 ) ;
}
static inline void F_57 ( struct V_10 * V_11 )
{
if ( ! ( V_11 -> V_26 & V_33 ) )
V_11 -> V_54 |= V_55 ;
V_11 -> V_26 |= V_33 ;
}
static int F_58 ( struct V_10 * V_11 )
{
void * V_89 [] = { F_1 , F_3 , F_5 } ;
const struct V_90 * V_91 = V_11 -> V_15 ;
const struct V_92 * V_9 ;
unsigned V_60 , V_93 , V_48 , V_94 ;
int V_70 ;
T_4 V_59 ;
for ( V_60 = 0 ; V_60 < V_91 -> V_16 ; V_60 ++ ) {
T_3 V_18 ;
V_9 = & ( V_91 -> V_17 [ V_60 ] ) ;
V_59 = V_9 -> V_59 ;
V_18 = F_59 ( V_9 ) ;
if ( V_11 -> V_12 == NULL )
V_11 -> V_64 [ V_60 ] = V_11 -> V_13 * 4 ;
switch ( V_18 ) {
case V_36 | V_95 :
F_37 ( V_21 , V_59 , V_11 ) ;
break;
case V_36 | V_37 | V_38 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 , V_16 ) != 4 ) ;
F_10 ( F_22 ( V_21 , V_30 ,
F_21 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_36 | V_96 :
V_11 -> V_26 |= F_62 ( V_59 ) ;
F_10 ( F_22 ( V_21 , V_49 , F_63 ( V_59 ) ) , V_11 ) ;
break;
case V_36 | V_37 | V_39 :
V_93 = 2 ;
goto V_97;
case V_36 | V_40 | V_39 :
V_93 = 1 ;
goto V_97;
case V_36 | V_41 | V_39 :
V_93 = 0 ;
V_97:
if ( ( int ) V_59 < 0 )
return - V_98 ;
F_37 ( V_99 , V_59 , V_11 ) ;
V_100:
V_11 -> V_26 |= V_28 | V_27 ;
if ( V_93 > 0 ) {
F_10 ( F_20 ( V_53 , V_32 ,
1 << V_93 ) , V_11 ) ;
F_10 ( F_64 ( V_53 , V_99 ) , V_11 ) ;
V_94 = V_101 ;
} else {
F_10 ( F_64 ( V_32 , V_99 ) , V_11 ) ;
V_94 = V_102 ;
}
F_8 ( V_94 , F_65 ( V_53 , V_99 , V_31 ) ,
V_11 ) ;
if ( V_93 == 0 )
F_8 ( V_94 , F_39 ( V_21 , V_53 , 0 ) ,
V_11 ) ;
else if ( V_93 == 1 )
F_43 ( V_94 , V_21 , V_53 , V_11 ) ;
else if ( V_93 == 2 )
F_38 ( V_94 , V_21 , V_53 , V_11 ) ;
F_8 ( V_94 , F_52 ( F_50 ( V_60 + 1 , V_11 ) ) , V_11 ) ;
F_37 ( V_73 , ( T_4 ) V_89 [ V_93 ] , V_11 ) ;
F_10 ( F_18 ( V_50 , V_30 ) , V_11 ) ;
F_53 ( V_73 , V_11 ) ;
F_10 ( F_66 ( V_74 , 0 ) , V_11 ) ;
F_51 ( V_103 , V_11 ) ;
F_10 ( F_18 ( V_21 , V_50 ) , V_11 ) ;
break;
case V_36 | V_37 | V_104 :
V_93 = 2 ;
goto V_105;
case V_36 | V_40 | V_104 :
V_93 = 1 ;
goto V_105;
case V_36 | V_41 | V_104 :
V_93 = 0 ;
V_105:
F_67 ( V_106 , V_99 , V_34 , V_59 , V_11 ) ;
goto V_100;
case V_107 | V_95 :
V_11 -> V_26 |= V_33 ;
F_37 ( V_34 , V_59 , V_11 ) ;
break;
case V_107 | V_37 | V_38 :
V_11 -> V_26 |= V_33 | V_29 ;
F_10 ( F_22 ( V_34 , V_30 ,
F_21 ( struct V_1 , V_16 ) ) , V_11 ) ;
break;
case V_107 | V_96 :
V_11 -> V_26 |= V_33 | F_62 ( V_59 ) ;
F_10 ( F_22 ( V_34 , V_49 , F_63 ( V_59 ) ) , V_11 ) ;
break;
case V_107 | V_41 | V_108 :
V_11 -> V_26 |= V_33 | V_28 | V_27 ;
if ( ( int ) V_59 < 0 )
return - 1 ;
F_37 ( V_99 , V_59 , V_11 ) ;
F_10 ( F_64 ( V_32 , V_99 ) , V_11 ) ;
F_8 ( V_102 , F_68 ( V_50 , V_31 ,
V_74 ) , V_11 ) ;
F_8 ( V_102 , F_52 ( F_50 ( V_60 + 1 , V_11 ) - 2 ) , V_11 ) ;
F_10 ( F_18 ( V_50 , V_30 ) , V_11 ) ;
F_37 ( V_73 , ( T_4 ) F_1 , V_11 ) ;
F_53 ( V_73 , V_11 ) ;
F_10 ( F_66 ( V_74 , 0 ) , V_11 ) ;
F_51 ( V_103 , V_11 ) ;
F_10 ( F_69 ( V_34 , V_50 , 0x00f ) , V_11 ) ;
F_10 ( F_40 ( V_34 , V_34 , 2 ) , V_11 ) ;
break;
case V_109 :
V_11 -> V_26 |= F_62 ( V_59 ) ;
F_10 ( F_70 ( V_21 , V_49 , F_63 ( V_59 ) ) , V_11 ) ;
break;
case V_110 :
F_57 ( V_11 ) ;
V_11 -> V_26 |= F_62 ( V_59 ) ;
F_10 ( F_70 ( V_34 , V_49 , F_63 ( V_59 ) ) , V_11 ) ;
break;
case V_111 | V_112 | V_56 :
F_67 ( V_106 , V_21 , V_21 , V_59 , V_11 ) ;
break;
case V_111 | V_112 | V_113 :
F_57 ( V_11 ) ;
F_10 ( F_65 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_111 | V_114 | V_56 :
F_67 ( V_115 , V_21 , V_21 , V_59 , V_11 ) ;
break;
case V_111 | V_114 | V_113 :
F_57 ( V_11 ) ;
F_10 ( F_23 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_111 | V_116 | V_56 :
F_37 ( V_53 , V_59 , V_11 ) ;
F_10 ( F_71 ( V_21 , V_21 , V_53 ) , V_11 ) ;
break;
case V_111 | V_116 | V_113 :
F_57 ( V_11 ) ;
F_10 ( F_71 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_111 | V_117 | V_56 :
if ( V_59 == 1 )
break;
F_37 ( V_53 , V_59 , V_11 ) ;
F_55 ( V_21 , V_21 , V_53 , V_11 ) ;
break;
case V_111 | V_117 | V_113 :
F_57 ( V_11 ) ;
F_10 ( F_66 ( V_34 , 0 ) , V_11 ) ;
F_51 ( V_118 , V_11 ) ;
F_55 ( V_21 , V_21 , V_34 , V_11 ) ;
break;
case V_111 | V_119 | V_56 :
F_67 ( V_120 , V_21 , V_21 , V_59 , V_11 ) ;
break;
case V_111 | V_119 | V_113 :
F_57 ( V_11 ) ;
F_10 ( F_42 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_111 | V_121 | V_56 :
F_67 ( V_122 , V_21 , V_21 , V_59 , V_11 ) ;
break;
case V_123 | V_124 :
case V_111 | V_121 | V_113 :
F_57 ( V_11 ) ;
F_10 ( F_72 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_111 | V_125 | V_56 :
F_67 ( V_126 , V_21 , V_21 , V_59 , V_11 ) ;
break;
case V_111 | V_125 | V_113 :
F_57 ( V_11 ) ;
F_10 ( F_73 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_111 | V_127 | V_56 :
if ( F_74 ( V_59 > 31 ) )
return - 1 ;
F_10 ( F_40 ( V_21 , V_21 , V_59 ) , V_11 ) ;
break;
case V_111 | V_127 | V_113 :
F_57 ( V_11 ) ;
F_10 ( F_75 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_111 | V_128 | V_56 :
if ( F_74 ( V_59 > 31 ) )
return - 1 ;
F_10 ( F_76 ( V_21 , V_21 , V_59 ) , V_11 ) ;
break;
case V_111 | V_128 | V_113 :
F_57 ( V_11 ) ;
F_10 ( F_77 ( V_21 , V_21 , V_34 ) , V_11 ) ;
break;
case V_111 | V_129 :
F_10 ( F_78 ( V_21 , V_21 , 0 ) , V_11 ) ;
break;
case V_130 | V_131 :
F_10 ( F_52 ( F_50 ( V_60 + V_59 + 1 , V_11 ) ) , V_11 ) ;
break;
case V_130 | V_132 | V_56 :
V_94 = V_118 ;
goto V_133;
case V_130 | V_134 | V_56 :
V_94 = V_102 ;
goto V_133;
case V_130 | V_135 | V_56 :
V_94 = V_101 ;
V_133:
V_70 = F_30 ( V_59 ) ;
if ( V_70 < 0 ) {
F_34 ( V_53 , V_59 , V_11 ) ;
F_10 ( F_64 ( V_21 , V_53 ) , V_11 ) ;
} else {
F_10 ( F_66 ( V_21 , V_70 ) , V_11 ) ;
}
V_136:
if ( V_9 -> V_137 )
F_8 ( V_94 , F_52 ( F_50 ( V_60 + V_9 -> V_137 + 1 ,
V_11 ) ) , V_11 ) ;
if ( V_9 -> V_138 )
F_8 ( V_94 ^ 1 , F_52 ( F_50 ( V_60 + V_9 -> V_138 + 1 ,
V_11 ) ) , V_11 ) ;
break;
case V_130 | V_132 | V_113 :
V_94 = V_118 ;
goto V_139;
case V_130 | V_134 | V_113 :
V_94 = V_102 ;
goto V_139;
case V_130 | V_135 | V_113 :
V_94 = V_140 ;
V_139:
F_57 ( V_11 ) ;
F_10 ( F_64 ( V_21 , V_34 ) , V_11 ) ;
goto V_136;
case V_130 | V_141 | V_56 :
V_94 = V_103 ;
V_70 = F_30 ( V_59 ) ;
if ( V_70 < 0 ) {
F_34 ( V_53 , V_59 , V_11 ) ;
F_10 ( F_79 ( V_21 , V_53 ) , V_11 ) ;
} else {
F_10 ( F_80 ( V_21 , V_70 ) , V_11 ) ;
}
goto V_136;
case V_130 | V_141 | V_113 :
F_57 ( V_11 ) ;
V_94 = V_103 ;
F_10 ( F_79 ( V_21 , V_34 ) , V_11 ) ;
goto V_136;
case V_19 | V_20 :
F_10 ( F_18 ( V_50 , V_21 ) , V_11 ) ;
goto V_142;
case V_19 | V_56 :
if ( ( V_59 == 0 ) && ( V_11 -> V_82 < 0 ) )
V_11 -> V_82 = V_60 ;
F_37 ( V_50 , V_59 , V_11 ) ;
V_142:
if ( V_60 != V_11 -> V_15 -> V_16 - 1 )
F_10 ( F_52 ( F_50 ( V_91 -> V_16 , V_11 ) ) , V_11 ) ;
break;
case V_143 | V_144 :
V_11 -> V_26 |= V_33 ;
F_10 ( F_18 ( V_34 , V_21 ) , V_11 ) ;
break;
case V_143 | V_145 :
F_57 ( V_11 ) ;
F_10 ( F_18 ( V_21 , V_34 ) , V_11 ) ;
break;
case V_123 | V_146 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 ,
V_147 ) != 2 ) ;
V_48 = F_21 ( struct V_1 , V_147 ) ;
F_10 ( F_48 ( V_53 , V_30 , V_48 ) , V_11 ) ;
F_44 ( V_21 , V_53 , V_11 ) ;
break;
case V_123 | V_148 :
F_67 ( V_149 , V_53 , V_49 , V_150 - 1 , V_11 ) ;
F_60 ( F_61 ( struct V_151 , V_152 ) != 4 ) ;
V_48 = F_21 ( struct V_151 , V_152 ) ;
F_10 ( F_22 ( V_21 , V_53 , V_48 ) , V_11 ) ;
break;
case V_123 | V_153 :
V_11 -> V_26 |= V_29 ;
V_48 = F_21 ( struct V_1 , V_154 ) ;
F_10 ( F_22 ( V_53 , V_30 , V_48 ) , V_11 ) ;
F_10 ( F_66 ( V_53 , 0 ) , V_11 ) ;
F_51 ( V_118 , V_11 ) ;
F_60 ( F_61 ( struct V_155 ,
V_156 ) != 4 ) ;
V_48 = F_21 ( struct V_155 , V_156 ) ;
F_10 ( F_22 ( V_21 , V_53 , V_48 ) , V_11 ) ;
break;
case V_123 | V_157 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 , V_158 ) != 4 ) ;
V_48 = F_21 ( struct V_1 , V_158 ) ;
F_10 ( F_22 ( V_21 , V_30 , V_48 ) , V_11 ) ;
break;
case V_123 | V_159 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 , V_160 ) != 4 ) ;
V_48 = F_21 ( struct V_1 , V_160 ) ;
F_10 ( F_22 ( V_21 , V_30 , V_48 ) , V_11 ) ;
break;
case V_123 | V_161 :
case V_123 | V_162 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 , V_163 ) != 2 ) ;
V_48 = F_21 ( struct V_1 , V_163 ) ;
F_10 ( F_48 ( V_21 , V_30 , V_48 ) , V_11 ) ;
if ( V_18 == ( V_123 | V_161 ) )
F_67 ( V_126 , V_21 , V_21 , V_164 , V_11 ) ;
else
F_67 ( V_126 , V_21 , V_21 , V_165 , V_11 ) ;
break;
case V_123 | V_166 :
V_11 -> V_26 |= V_29 ;
F_60 ( F_61 ( struct V_1 ,
V_167 ) != 2 ) ;
F_60 ( F_21 ( struct V_1 ,
V_167 ) > 0xff ) ;
V_48 = F_21 ( struct V_1 , V_167 ) ;
F_10 ( F_48 ( V_21 , V_30 , V_48 ) , V_11 ) ;
break;
default:
return - 1 ;
}
}
if ( V_11 -> V_12 == NULL )
V_11 -> V_64 [ V_60 ] = V_11 -> V_13 * 4 ;
return 0 ;
}
void F_81 ( struct V_90 * V_168 )
{
struct V_169 * V_170 ;
struct V_10 V_11 ;
unsigned V_171 ;
unsigned V_172 ;
T_2 * V_173 ;
if ( ! V_174 )
return;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_15 = V_168 ;
V_11 . V_82 = - 1 ;
V_11 . V_64 = F_82 ( 4 * ( V_11 . V_15 -> V_16 + 1 ) , V_175 ) ;
if ( V_11 . V_64 == NULL )
return;
if ( F_74 ( F_58 ( & V_11 ) ) )
goto V_176;
V_171 = V_11 . V_13 ;
F_17 ( & V_11 ) ;
V_11 . V_65 = ( V_11 . V_13 - V_171 ) * 4 ;
#if V_69 < 7
V_171 = V_11 . V_13 ;
F_25 ( & V_11 ) ;
V_11 . V_66 = ( V_11 . V_13 - V_171 ) * 4 ;
V_11 . V_13 += V_11 . V_62 ;
if ( V_11 . V_62 ) {
V_11 . V_63 = F_82 ( 4 * V_11 . V_62 , V_175 ) ;
if ( V_11 . V_63 == NULL )
goto V_176;
}
#else
F_25 ( & V_11 ) ;
#endif
V_172 = 4 * V_11 . V_13 ;
V_170 = F_83 ( V_172 , & V_173 ,
4 , F_16 ) ;
if ( V_170 == NULL )
goto V_176;
V_11 . V_12 = ( T_4 * ) V_173 ;
V_11 . V_13 = 0 ;
F_17 ( & V_11 ) ;
F_58 ( & V_11 ) ;
F_25 ( & V_11 ) ;
F_84 ( ( T_4 ) V_11 . V_12 , ( T_4 ) ( V_11 . V_12 + V_11 . V_13 ) ) ;
#if V_69 < 7
if ( V_11 . V_62 )
F_85 ( V_11 . V_63 ) ;
#endif
if ( V_174 > 1 )
F_86 ( V_168 -> V_16 , V_172 , 2 , V_11 . V_12 ) ;
F_87 ( ( unsigned long ) V_170 , V_170 -> V_177 ) ;
V_168 -> V_178 = ( void * ) V_11 . V_12 ;
V_168 -> V_179 = true ;
V_176:
F_85 ( V_11 . V_64 ) ;
return;
}
void F_88 ( struct V_90 * V_168 )
{
unsigned long V_180 = ( unsigned long ) V_168 -> V_178 & V_181 ;
struct V_169 * V_170 = ( void * ) V_180 ;
if ( ! V_168 -> V_179 )
goto V_182;
F_89 ( V_180 , V_170 -> V_177 ) ;
F_90 ( V_170 ) ;
V_182:
F_91 ( V_168 ) ;
}
