static inline int F_1 ( struct V_1 * V_2 , int V_3 , void * V_4 ,
unsigned int V_5 )
{
void * V_6 = F_2 ( V_2 , V_3 , V_5 ) ;
if ( ! V_6 )
return - V_7 ;
memcpy ( V_4 , V_6 , V_5 ) ;
return 0 ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_4 ;
int V_8 ;
if ( V_3 < 0 )
V_8 = F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
else
V_8 = F_4 ( V_2 , V_3 , & V_4 , 1 ) ;
return ( T_1 ) V_8 << 32 | V_4 ;
}
static T_1 F_5 ( struct V_1 * V_2 , int V_3 )
{
T_3 V_4 ;
int V_8 ;
if ( V_3 < 0 )
V_8 = F_1 ( V_2 , V_3 , & V_4 , 2 ) ;
else
V_8 = F_4 ( V_2 , V_3 , & V_4 , 2 ) ;
return ( T_1 ) V_8 << 32 | F_6 ( V_4 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , int V_3 )
{
T_4 V_4 ;
int V_8 ;
if ( V_3 < 0 )
V_8 = F_1 ( V_2 , V_3 , & V_4 , 4 ) ;
else
V_8 = F_4 ( V_2 , V_3 , & V_4 , 4 ) ;
return ( T_1 ) V_8 << 32 | F_8 ( V_4 ) ;
}
static T_4 F_9 ( T_4 V_9 , T_4 V_10 )
{
return V_9 / V_10 ;
}
static inline void F_10 ( int V_11 , T_4 V_12 , struct V_13 * V_14 )
{
V_12 |= ( V_11 << 28 ) ;
V_12 = F_11 ( V_12 ) ;
if ( V_14 -> V_15 != NULL )
V_14 -> V_15 [ V_14 -> V_16 ] = V_12 ;
V_14 -> V_16 ++ ;
}
static inline void F_12 ( T_4 V_12 , struct V_13 * V_14 )
{
F_10 ( V_17 , V_12 , V_14 ) ;
}
static T_3 F_13 ( struct V_13 * V_14 )
{
T_3 V_4 = 0 ;
if ( ( V_14 -> V_18 -> V_19 > 1 ) ||
( V_14 -> V_18 -> V_20 [ 0 ] . V_21 == ( V_22 | V_23 ) ) )
V_4 |= 1 << V_24 ;
#ifdef F_14
V_4 |= ( 1 << V_25 ) | ( 1 << V_26 ) | ( 1 << V_27 ) | ( 1 << V_28 ) ;
#else
if ( V_14 -> V_29 & V_30 )
V_4 |= 1 << V_27 ;
#endif
if ( V_14 -> V_29 & ( V_31 | V_32 ) )
V_4 |= 1 << V_33 ;
if ( V_14 -> V_29 & V_31 )
V_4 |= ( 1 << V_34 ) | ( 1 << V_35 ) ;
if ( V_14 -> V_29 & V_36 )
V_4 |= 1 << V_37 ;
return V_4 ;
}
static inline int F_15 ( struct V_13 * V_14 )
{
return F_16 ( V_14 -> V_29 & V_38 ) ;
}
static inline bool F_17 ( T_3 V_12 )
{
switch ( V_12 ) {
case V_39 | V_40 | V_41 :
case V_39 | V_40 | V_42 :
case V_39 | V_43 | V_42 :
case V_39 | V_44 | V_42 :
return true ;
default:
return false ;
}
}
static void F_18 ( void * V_45 , unsigned int V_5 )
{
T_4 * V_6 ;
for ( V_6 = V_45 ; V_5 >= sizeof( T_4 ) ; V_5 -= sizeof( T_4 ) )
* V_6 ++ = F_11 ( V_46 ) ;
}
static void F_19 ( struct V_13 * V_14 )
{
T_3 V_47 = F_13 ( V_14 ) ;
T_3 V_48 = V_14 -> V_18 -> V_20 [ 0 ] . V_21 ;
T_3 V_49 ;
#ifdef F_14
F_12 ( F_20 ( V_26 , V_50 ) , V_14 ) ;
F_12 ( F_21 ( V_47 ) , V_14 ) ;
F_12 ( F_22 ( V_25 , V_26 , 4 ) , V_14 ) ;
#else
if ( V_47 )
F_12 ( F_21 ( V_47 ) , V_14 ) ;
#endif
if ( V_14 -> V_29 & ( V_31 | V_32 ) )
F_12 ( F_20 ( V_33 , V_51 ) , V_14 ) ;
if ( V_14 -> V_29 & V_31 ) {
V_49 = F_23 ( struct V_1 , V_52 ) ;
F_12 ( F_24 ( V_34 , V_33 , V_49 ) , V_14 ) ;
V_49 = F_23 ( struct V_1 , V_19 ) ;
F_12 ( F_24 ( V_35 , V_33 , V_49 ) , V_14 ) ;
V_49 = F_23 ( struct V_1 , V_53 ) ;
F_12 ( F_24 ( V_54 , V_33 , V_49 ) , V_14 ) ;
F_12 ( F_25 ( V_35 , V_35 , V_54 ) , V_14 ) ;
}
if ( V_14 -> V_55 & V_56 )
F_12 ( F_26 ( V_37 , 0 ) , V_14 ) ;
if ( ( V_48 != ( V_22 | V_57 ) ) && ! ( F_17 ( V_48 ) ) )
F_12 ( F_26 ( V_24 , 0 ) , V_14 ) ;
if ( V_14 -> V_29 & V_38 )
F_12 ( F_22 ( V_50 , V_50 , F_15 ( V_14 ) * 4 ) , V_14 ) ;
}
static void F_27 ( struct V_13 * V_14 )
{
T_3 V_47 = F_13 ( V_14 ) ;
if ( V_14 -> V_29 & V_38 )
F_12 ( F_28 ( V_50 , V_50 , F_15 ( V_14 ) * 4 ) , V_14 ) ;
V_47 &= ~ ( 1 << V_27 ) ;
#ifdef F_14
V_47 &= ~ ( 1 << V_26 ) ;
V_47 |= ( 1 << V_50 ) ;
F_12 ( F_29 ( V_50 , V_47 ) , V_14 ) ;
#else
if ( V_47 ) {
if ( V_14 -> V_29 & V_30 )
V_47 |= 1 << V_28 ;
F_12 ( F_30 ( V_47 ) , V_14 ) ;
}
if ( ! ( V_14 -> V_29 & V_30 ) )
F_12 ( F_31 ( V_27 ) , V_14 ) ;
#endif
}
static T_5 F_32 ( T_4 V_58 )
{
T_4 V_59 ;
for ( V_59 = 0 ; V_59 < 16 ; V_59 ++ )
if ( ( V_58 & ~ F_33 ( 0xff , 2 * V_59 ) ) == 0 )
return F_34 ( V_58 , 2 * V_59 ) | ( V_59 << 8 ) ;
return - 1 ;
}
static T_3 F_35 ( T_4 V_60 , struct V_13 * V_14 )
{
unsigned V_61 = 0 , V_3 ;
T_3 V_62 ;
if ( V_14 -> V_15 == NULL ) {
V_14 -> V_63 ++ ;
return 0 ;
}
while ( ( V_61 < V_14 -> V_63 ) && V_14 -> V_64 [ V_61 ] ) {
if ( V_14 -> V_64 [ V_61 ] == V_60 )
break;
V_61 ++ ;
}
if ( V_14 -> V_64 [ V_61 ] == 0 )
V_14 -> V_64 [ V_61 ] = V_60 ;
V_3 = V_14 -> V_65 [ V_14 -> V_18 -> V_19 ] ;
V_3 += V_14 -> V_66 ;
V_3 += V_14 -> V_67 ;
V_3 += V_61 * 4 ;
V_14 -> V_15 [ V_3 / 4 ] = V_60 ;
V_62 = V_3 - ( 8 + V_14 -> V_16 * 4 ) ;
if ( V_62 & ~ 0xfff ) {
V_14 -> V_55 |= V_68 ;
return 0 ;
}
return V_62 ;
}
static inline void F_36 ( int V_69 , T_4 V_70 , struct V_13 * V_14 )
{
#if V_71 < 7
F_12 ( F_24 ( V_69 , V_28 , F_35 ( V_70 , V_14 ) ) , V_14 ) ;
#else
F_12 ( F_37 ( V_69 , V_70 & 0xffff ) , V_14 ) ;
if ( V_70 > 0xffff )
F_12 ( F_38 ( V_69 , V_70 >> 16 ) , V_14 ) ;
#endif
}
static inline void F_39 ( int V_69 , T_4 V_70 , struct V_13 * V_14 )
{
int V_72 = F_32 ( V_70 ) ;
if ( V_72 >= 0 )
F_12 ( F_26 ( V_69 , V_72 ) , V_14 ) ;
else
F_36 ( V_69 , V_70 , V_14 ) ;
}
static void F_40 ( T_2 V_11 , T_2 V_73 , T_2 V_74 , struct V_13 * V_14 )
{
F_10 ( V_11 , F_41 ( V_75 , V_74 , 1 ) , V_14 ) ;
F_10 ( V_11 , F_41 ( V_76 , V_74 , 0 ) , V_14 ) ;
F_10 ( V_11 , F_41 ( V_77 , V_74 , 3 ) , V_14 ) ;
F_10 ( V_11 , F_42 ( V_75 , V_75 , 16 ) , V_14 ) ;
F_10 ( V_11 , F_41 ( V_51 , V_74 , 2 ) , V_14 ) ;
F_10 ( V_11 , F_43 ( V_75 , V_75 , V_76 , V_78 , 24 ) , V_14 ) ;
F_10 ( V_11 , F_44 ( V_75 , V_75 , V_77 ) , V_14 ) ;
F_10 ( V_11 , F_43 ( V_73 , V_75 , V_51 , V_78 , 8 ) , V_14 ) ;
}
static void F_45 ( T_2 V_11 , T_2 V_73 , T_2 V_74 , struct V_13 * V_14 )
{
F_10 ( V_11 , F_41 ( V_76 , V_74 , 0 ) , V_14 ) ;
F_10 ( V_11 , F_41 ( V_77 , V_74 , 1 ) , V_14 ) ;
F_10 ( V_11 , F_43 ( V_73 , V_77 , V_76 , V_78 , 8 ) , V_14 ) ;
}
static inline void F_46 ( T_2 V_79 , T_2 V_80 , struct V_13 * V_14 )
{
F_12 ( F_42 ( V_76 , V_80 , 8 ) , V_14 ) ;
F_12 ( F_43 ( V_79 , V_76 , V_80 , V_81 , 8 ) , V_14 ) ;
F_12 ( F_47 ( V_79 , V_79 , 0x8ff ) , V_14 ) ;
}
static void F_40 ( T_2 V_11 , T_2 V_73 , T_2 V_74 , struct V_13 * V_14 )
{
F_10 ( V_11 , F_24 ( V_73 , V_74 , 0 ) , V_14 ) ;
#ifdef F_48
F_10 ( V_11 , F_49 ( V_73 , V_73 ) , V_14 ) ;
#endif
}
static void F_45 ( T_2 V_11 , T_2 V_73 , T_2 V_74 , struct V_13 * V_14 )
{
F_10 ( V_11 , F_50 ( V_73 , V_74 , 0 ) , V_14 ) ;
#ifdef F_48
F_10 ( V_11 , F_51 ( V_73 , V_73 ) , V_14 ) ;
#endif
}
static inline void F_46 ( T_2 V_79 V_82 ,
T_2 V_80 V_82 ,
struct V_13 * V_14 V_82 )
{
#ifdef F_48
F_12 ( F_51 ( V_79 , V_80 ) , V_14 ) ;
#endif
}
static inline T_4 F_52 ( unsigned V_83 , struct V_13 * V_14 )
{
T_4 V_62 ;
if ( V_14 -> V_15 == NULL )
return 0 ;
V_62 = V_14 -> V_65 [ V_83 ] + V_14 -> V_66 - ( V_14 -> V_16 * 4 + 8 ) ;
return V_62 >> 2 ;
}
static inline void F_53 ( T_2 V_11 , struct V_13 * V_14 )
{
if ( V_14 -> V_84 >= 0 ) {
F_10 ( V_11 , F_54 ( F_52 ( V_14 -> V_84 , V_14 ) ) , V_14 ) ;
F_12 ( F_20 ( V_51 , V_51 ) , V_14 ) ;
} else {
F_10 ( V_11 , F_26 ( V_51 , 0 ) , V_14 ) ;
F_10 ( V_11 , F_54 ( F_52 ( V_14 -> V_18 -> V_19 , V_14 ) ) , V_14 ) ;
}
}
static inline void F_55 ( T_2 V_85 , struct V_13 * V_14 )
{
#if V_71 < 5
F_12 ( F_20 ( V_27 , V_28 ) , V_14 ) ;
if ( V_86 & V_87 )
F_12 ( F_31 ( V_85 ) , V_14 ) ;
else
F_12 ( F_20 ( V_28 , V_85 ) , V_14 ) ;
#else
F_12 ( F_56 ( V_85 ) , V_14 ) ;
#endif
}
static inline void F_57 ( T_2 V_69 , T_2 V_88 , T_2 V_89 , struct V_13 * V_14 )
{
#if V_71 == 7
if ( V_86 & V_90 ) {
F_12 ( F_58 ( V_69 , V_88 , V_89 ) , V_14 ) ;
return;
}
#endif
if ( V_89 != V_76 )
F_12 ( F_20 ( V_76 , V_89 ) , V_14 ) ;
if ( V_88 != V_51 )
F_12 ( F_20 ( V_51 , V_88 ) , V_14 ) ;
V_14 -> V_29 |= V_30 ;
F_39 ( V_75 , ( T_4 ) F_9 , V_14 ) ;
F_55 ( V_75 , V_14 ) ;
if ( V_69 != V_51 )
F_12 ( F_20 ( V_69 , V_51 ) , V_14 ) ;
}
static inline void F_59 ( struct V_13 * V_14 )
{
if ( ! ( V_14 -> V_29 & V_36 ) )
V_14 -> V_55 |= V_56 ;
V_14 -> V_29 |= V_36 ;
}
static int F_60 ( struct V_13 * V_14 )
{
void * V_91 [] = { F_3 , F_5 , F_7 } ;
const struct V_92 * V_93 = V_14 -> V_18 ;
const struct V_94 * V_12 ;
unsigned V_61 , V_95 , V_49 , V_96 ;
int V_72 ;
T_4 V_60 ;
for ( V_61 = 0 ; V_61 < V_93 -> V_19 ; V_61 ++ ) {
T_3 V_21 ;
V_12 = & ( V_93 -> V_20 [ V_61 ] ) ;
V_60 = V_12 -> V_60 ;
V_21 = F_61 ( V_12 ) ;
if ( V_14 -> V_15 == NULL )
V_14 -> V_65 [ V_61 ] = V_14 -> V_16 * 4 ;
switch ( V_21 ) {
case V_39 | V_97 :
F_39 ( V_24 , V_60 , V_14 ) ;
break;
case V_39 | V_40 | V_41 :
V_14 -> V_29 |= V_32 ;
F_62 ( F_63 ( struct V_1 , V_19 ) != 4 ) ;
F_12 ( F_24 ( V_24 , V_33 ,
F_23 ( struct V_1 , V_19 ) ) , V_14 ) ;
break;
case V_39 | V_98 :
V_14 -> V_29 |= F_64 ( V_60 ) ;
F_12 ( F_24 ( V_24 , V_50 , F_65 ( V_60 ) ) , V_14 ) ;
break;
case V_39 | V_40 | V_42 :
V_95 = 2 ;
goto V_99;
case V_39 | V_43 | V_42 :
V_95 = 1 ;
goto V_99;
case V_39 | V_44 | V_42 :
V_95 = 0 ;
V_99:
F_39 ( V_100 , V_60 , V_14 ) ;
V_101:
V_14 -> V_29 |= V_31 | V_30 ;
if ( V_95 > 0 ) {
F_12 ( F_22 ( V_54 , V_35 ,
1 << V_95 ) , V_14 ) ;
F_12 ( F_66 ( V_54 , V_100 ) , V_14 ) ;
V_96 = V_102 ;
} else {
F_12 ( F_66 ( V_35 , V_100 ) , V_14 ) ;
V_96 = V_103 ;
}
F_10 ( V_96 , F_67 ( V_100 , 0 ) , V_14 ) ;
F_10 ( V_96 , F_68 ( V_54 , V_100 , V_34 ) ,
V_14 ) ;
if ( V_95 == 0 )
F_10 ( V_96 , F_41 ( V_24 , V_54 , 0 ) ,
V_14 ) ;
else if ( V_95 == 1 )
F_45 ( V_96 , V_24 , V_54 , V_14 ) ;
else if ( V_95 == 2 )
F_40 ( V_96 , V_24 , V_54 , V_14 ) ;
F_10 ( V_96 , F_54 ( F_52 ( V_61 + 1 , V_14 ) ) , V_14 ) ;
F_39 ( V_75 , ( T_4 ) V_91 [ V_95 ] , V_14 ) ;
F_12 ( F_20 ( V_51 , V_33 ) , V_14 ) ;
F_55 ( V_75 , V_14 ) ;
F_12 ( F_67 ( V_76 , 0 ) , V_14 ) ;
F_53 ( V_104 , V_14 ) ;
F_12 ( F_20 ( V_24 , V_51 ) , V_14 ) ;
break;
case V_39 | V_40 | V_105 :
V_95 = 2 ;
goto V_106;
case V_39 | V_43 | V_105 :
V_95 = 1 ;
goto V_106;
case V_39 | V_44 | V_105 :
V_95 = 0 ;
V_106:
F_59 ( V_14 ) ;
F_69 ( V_107 , V_100 , V_37 , V_60 , V_14 ) ;
goto V_101;
case V_108 | V_97 :
V_14 -> V_29 |= V_36 ;
F_39 ( V_37 , V_60 , V_14 ) ;
break;
case V_108 | V_40 | V_41 :
V_14 -> V_29 |= V_36 | V_32 ;
F_12 ( F_24 ( V_37 , V_33 ,
F_23 ( struct V_1 , V_19 ) ) , V_14 ) ;
break;
case V_108 | V_98 :
V_14 -> V_29 |= V_36 | F_64 ( V_60 ) ;
F_12 ( F_24 ( V_37 , V_50 , F_65 ( V_60 ) ) , V_14 ) ;
break;
case V_108 | V_44 | V_109 :
V_14 -> V_29 |= V_36 | V_31 | V_30 ;
if ( ( int ) V_60 < 0 )
return - 1 ;
F_39 ( V_100 , V_60 , V_14 ) ;
F_12 ( F_66 ( V_35 , V_100 ) , V_14 ) ;
F_10 ( V_103 , F_70 ( V_51 , V_34 ,
V_76 ) , V_14 ) ;
F_10 ( V_103 , F_54 ( F_52 ( V_61 + 1 , V_14 ) - 2 ) , V_14 ) ;
F_12 ( F_20 ( V_51 , V_33 ) , V_14 ) ;
F_39 ( V_75 , ( T_4 ) F_3 , V_14 ) ;
F_55 ( V_75 , V_14 ) ;
F_12 ( F_67 ( V_76 , 0 ) , V_14 ) ;
F_53 ( V_104 , V_14 ) ;
F_12 ( F_71 ( V_37 , V_51 , 0x00f ) , V_14 ) ;
F_12 ( F_42 ( V_37 , V_37 , 2 ) , V_14 ) ;
break;
case V_110 :
V_14 -> V_29 |= F_64 ( V_60 ) ;
F_12 ( F_72 ( V_24 , V_50 , F_65 ( V_60 ) ) , V_14 ) ;
break;
case V_111 :
F_59 ( V_14 ) ;
V_14 -> V_29 |= F_64 ( V_60 ) ;
F_12 ( F_72 ( V_37 , V_50 , F_65 ( V_60 ) ) , V_14 ) ;
break;
case V_112 | V_113 | V_57 :
F_69 ( V_107 , V_24 , V_24 , V_60 , V_14 ) ;
break;
case V_112 | V_113 | V_114 :
F_59 ( V_14 ) ;
F_12 ( F_68 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_115 | V_57 :
F_69 ( V_116 , V_24 , V_24 , V_60 , V_14 ) ;
break;
case V_112 | V_115 | V_114 :
F_59 ( V_14 ) ;
F_12 ( F_25 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_117 | V_57 :
F_39 ( V_54 , V_60 , V_14 ) ;
F_12 ( F_73 ( V_24 , V_24 , V_54 ) , V_14 ) ;
break;
case V_112 | V_117 | V_114 :
F_59 ( V_14 ) ;
F_12 ( F_73 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_118 | V_57 :
if ( V_60 == 1 )
break;
F_39 ( V_54 , V_60 , V_14 ) ;
F_57 ( V_24 , V_24 , V_54 , V_14 ) ;
break;
case V_112 | V_118 | V_114 :
F_59 ( V_14 ) ;
F_12 ( F_67 ( V_37 , 0 ) , V_14 ) ;
F_53 ( V_119 , V_14 ) ;
F_57 ( V_24 , V_24 , V_37 , V_14 ) ;
break;
case V_112 | V_120 | V_57 :
F_69 ( V_121 , V_24 , V_24 , V_60 , V_14 ) ;
break;
case V_112 | V_120 | V_114 :
F_59 ( V_14 ) ;
F_12 ( F_44 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_122 | V_57 :
F_69 ( V_123 , V_24 , V_24 , V_60 , V_14 ) ;
break;
case V_124 | V_125 :
case V_112 | V_122 | V_114 :
F_59 ( V_14 ) ;
F_12 ( F_74 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_126 | V_57 :
F_69 ( V_127 , V_24 , V_24 , V_60 , V_14 ) ;
break;
case V_112 | V_126 | V_114 :
F_59 ( V_14 ) ;
F_12 ( F_75 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_128 | V_57 :
if ( F_76 ( V_60 > 31 ) )
return - 1 ;
F_12 ( F_42 ( V_24 , V_24 , V_60 ) , V_14 ) ;
break;
case V_112 | V_128 | V_114 :
F_59 ( V_14 ) ;
F_12 ( F_77 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_129 | V_57 :
if ( F_76 ( V_60 > 31 ) )
return - 1 ;
F_12 ( F_78 ( V_24 , V_24 , V_60 ) , V_14 ) ;
break;
case V_112 | V_129 | V_114 :
F_59 ( V_14 ) ;
F_12 ( F_79 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_130 :
F_12 ( F_80 ( V_24 , V_24 , 0 ) , V_14 ) ;
break;
case V_131 | V_132 :
F_12 ( F_54 ( F_52 ( V_61 + V_60 + 1 , V_14 ) ) , V_14 ) ;
break;
case V_131 | V_133 | V_57 :
V_96 = V_119 ;
goto V_134;
case V_131 | V_135 | V_57 :
V_96 = V_103 ;
goto V_134;
case V_131 | V_136 | V_57 :
V_96 = V_137 ;
V_134:
V_72 = F_32 ( V_60 ) ;
if ( V_72 < 0 ) {
F_36 ( V_54 , V_60 , V_14 ) ;
F_12 ( F_66 ( V_24 , V_54 ) , V_14 ) ;
} else {
F_12 ( F_67 ( V_24 , V_72 ) , V_14 ) ;
}
V_138:
if ( V_12 -> V_139 )
F_10 ( V_96 , F_54 ( F_52 ( V_61 + V_12 -> V_139 + 1 ,
V_14 ) ) , V_14 ) ;
if ( V_12 -> V_140 )
F_10 ( V_96 ^ 1 , F_54 ( F_52 ( V_61 + V_12 -> V_140 + 1 ,
V_14 ) ) , V_14 ) ;
break;
case V_131 | V_133 | V_114 :
V_96 = V_119 ;
goto V_141;
case V_131 | V_135 | V_114 :
V_96 = V_103 ;
goto V_141;
case V_131 | V_136 | V_114 :
V_96 = V_142 ;
V_141:
F_59 ( V_14 ) ;
F_12 ( F_66 ( V_24 , V_37 ) , V_14 ) ;
goto V_138;
case V_131 | V_143 | V_57 :
V_96 = V_104 ;
V_72 = F_32 ( V_60 ) ;
if ( V_72 < 0 ) {
F_36 ( V_54 , V_60 , V_14 ) ;
F_12 ( F_81 ( V_24 , V_54 ) , V_14 ) ;
} else {
F_12 ( F_82 ( V_24 , V_72 ) , V_14 ) ;
}
goto V_138;
case V_131 | V_143 | V_114 :
F_59 ( V_14 ) ;
V_96 = V_104 ;
F_12 ( F_81 ( V_24 , V_37 ) , V_14 ) ;
goto V_138;
case V_22 | V_23 :
F_12 ( F_20 ( V_51 , V_24 ) , V_14 ) ;
goto V_144;
case V_22 | V_57 :
if ( ( V_60 == 0 ) && ( V_14 -> V_84 < 0 ) )
V_14 -> V_84 = V_61 ;
F_39 ( V_51 , V_60 , V_14 ) ;
V_144:
if ( V_61 != V_14 -> V_18 -> V_19 - 1 )
F_12 ( F_54 ( F_52 ( V_93 -> V_19 , V_14 ) ) , V_14 ) ;
break;
case V_145 | V_146 :
V_14 -> V_29 |= V_36 ;
F_12 ( F_20 ( V_37 , V_24 ) , V_14 ) ;
break;
case V_145 | V_147 :
F_59 ( V_14 ) ;
F_12 ( F_20 ( V_24 , V_37 ) , V_14 ) ;
break;
case V_124 | V_148 :
V_14 -> V_29 |= V_32 ;
F_62 ( F_63 ( struct V_1 ,
V_149 ) != 2 ) ;
V_49 = F_23 ( struct V_1 , V_149 ) ;
F_12 ( F_50 ( V_54 , V_33 , V_49 ) , V_14 ) ;
F_46 ( V_24 , V_54 , V_14 ) ;
break;
case V_124 | V_150 :
F_69 ( V_151 , V_54 , V_50 , V_152 - 1 , V_14 ) ;
F_62 ( F_63 ( struct V_153 , V_154 ) != 4 ) ;
V_49 = F_23 ( struct V_153 , V_154 ) ;
F_12 ( F_24 ( V_24 , V_54 , V_49 ) , V_14 ) ;
break;
case V_124 | V_155 :
case V_124 | V_156 :
V_14 -> V_29 |= V_32 ;
V_49 = F_23 ( struct V_1 , V_157 ) ;
F_12 ( F_24 ( V_54 , V_33 , V_49 ) , V_14 ) ;
F_12 ( F_67 ( V_54 , 0 ) , V_14 ) ;
F_53 ( V_119 , V_14 ) ;
F_62 ( F_63 ( struct V_158 ,
V_159 ) != 4 ) ;
F_62 ( F_63 ( struct V_158 ,
type ) != 2 ) ;
if ( V_21 == ( V_124 | V_155 ) ) {
V_49 = F_23 ( struct V_158 , V_159 ) ;
F_12 ( F_24 ( V_24 , V_54 , V_49 ) , V_14 ) ;
} else {
V_49 = F_23 ( struct V_158 , type ) ;
F_39 ( V_75 , V_49 , V_14 ) ;
F_12 ( F_83 ( V_24 , V_54 , V_75 ) , V_14 ) ;
}
break;
case V_124 | V_160 :
V_14 -> V_29 |= V_32 ;
F_62 ( F_63 ( struct V_1 , V_161 ) != 4 ) ;
V_49 = F_23 ( struct V_1 , V_161 ) ;
F_12 ( F_24 ( V_24 , V_33 , V_49 ) , V_14 ) ;
break;
case V_124 | V_162 :
V_14 -> V_29 |= V_32 ;
F_62 ( F_63 ( struct V_1 , V_163 ) != 4 ) ;
V_49 = F_23 ( struct V_1 , V_163 ) ;
F_12 ( F_24 ( V_24 , V_33 , V_49 ) , V_14 ) ;
break;
case V_124 | V_164 :
case V_124 | V_165 :
V_14 -> V_29 |= V_32 ;
F_62 ( F_63 ( struct V_1 , V_166 ) != 2 ) ;
V_49 = F_23 ( struct V_1 , V_166 ) ;
F_12 ( F_50 ( V_24 , V_33 , V_49 ) , V_14 ) ;
if ( V_21 == ( V_124 | V_164 ) )
F_69 ( V_127 , V_24 , V_24 , ~ V_167 , V_14 ) ;
else {
F_69 ( V_168 , V_24 , V_24 , 12 , V_14 ) ;
F_69 ( V_127 , V_24 , V_24 , 0x1 , V_14 ) ;
}
break;
case V_124 | V_169 :
V_14 -> V_29 |= V_32 ;
F_62 ( F_63 ( struct V_1 ,
V_170 [ 0 ] ) != 1 ) ;
V_49 = F_84 () ;
F_12 ( F_41 ( V_24 , V_33 , V_49 ) , V_14 ) ;
F_12 ( F_71 ( V_24 , V_24 , V_171 ) , V_14 ) ;
#ifdef F_85
F_12 ( F_78 ( V_24 , V_24 , 5 ) , V_14 ) ;
#endif
break;
case V_124 | V_172 :
V_14 -> V_29 |= V_32 ;
F_62 ( F_63 ( struct V_1 ,
V_173 ) != 2 ) ;
F_62 ( F_23 ( struct V_1 ,
V_173 ) > 0xff ) ;
V_49 = F_23 ( struct V_1 , V_173 ) ;
F_12 ( F_50 ( V_24 , V_33 , V_49 ) , V_14 ) ;
break;
case V_124 | V_174 :
V_14 -> V_29 |= V_32 | V_30 ;
F_12 ( F_20 ( V_51 , V_33 ) , V_14 ) ;
F_39 ( V_75 , ( unsigned int ) V_175 , V_14 ) ;
F_55 ( V_75 , V_14 ) ;
F_12 ( F_20 ( V_24 , V_51 ) , V_14 ) ;
break;
case V_108 | V_40 | V_42 :
V_14 -> V_29 |= V_32 ;
F_12 ( F_24 ( V_24 , V_33 , V_60 ) , V_14 ) ;
break;
default:
return - 1 ;
}
if ( V_14 -> V_55 & V_68 )
return - 1 ;
}
if ( V_14 -> V_15 == NULL )
V_14 -> V_65 [ V_61 ] = V_14 -> V_16 * 4 ;
return 0 ;
}
void F_86 ( struct V_92 * V_176 )
{
struct V_177 * V_178 ;
struct V_13 V_14 ;
unsigned V_179 ;
unsigned V_180 ;
T_2 * V_181 ;
if ( ! V_182 )
return;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_18 = V_176 ;
V_14 . V_84 = - 1 ;
V_14 . V_65 = F_87 ( 4 * ( V_14 . V_18 -> V_19 + 1 ) , V_183 ) ;
if ( V_14 . V_65 == NULL )
return;
if ( F_76 ( F_60 ( & V_14 ) ) )
goto V_184;
V_179 = V_14 . V_16 ;
F_19 ( & V_14 ) ;
V_14 . V_66 = ( V_14 . V_16 - V_179 ) * 4 ;
#if V_71 < 7
V_179 = V_14 . V_16 ;
F_27 ( & V_14 ) ;
V_14 . V_67 = ( V_14 . V_16 - V_179 ) * 4 ;
V_14 . V_16 += V_14 . V_63 ;
if ( V_14 . V_63 ) {
V_14 . V_64 = F_87 ( 4 * V_14 . V_63 , V_183 ) ;
if ( V_14 . V_64 == NULL )
goto V_184;
}
#else
F_27 ( & V_14 ) ;
#endif
V_180 = 4 * V_14 . V_16 ;
V_178 = F_88 ( V_180 , & V_181 ,
4 , F_18 ) ;
if ( V_178 == NULL )
goto V_184;
V_14 . V_15 = ( T_4 * ) V_181 ;
V_14 . V_16 = 0 ;
F_19 ( & V_14 ) ;
if ( F_60 ( & V_14 ) < 0 ) {
#if V_71 < 7
if ( V_14 . V_63 )
F_89 ( V_14 . V_64 ) ;
#endif
F_90 ( V_178 ) ;
goto V_184;
}
F_27 ( & V_14 ) ;
F_91 ( ( T_4 ) V_14 . V_15 , ( T_4 ) ( V_14 . V_15 + V_14 . V_16 ) ) ;
#if V_71 < 7
if ( V_14 . V_63 )
F_89 ( V_14 . V_64 ) ;
#endif
if ( V_182 > 1 )
F_92 ( V_176 -> V_19 , V_180 , 2 , V_14 . V_15 ) ;
F_93 ( ( unsigned long ) V_178 , V_178 -> V_185 ) ;
V_176 -> V_186 = ( void * ) V_14 . V_15 ;
V_176 -> V_187 = true ;
V_184:
F_89 ( V_14 . V_65 ) ;
return;
}
void F_94 ( struct V_92 * V_176 )
{
unsigned long V_188 = ( unsigned long ) V_176 -> V_186 & V_189 ;
struct V_177 * V_178 = ( void * ) V_188 ;
if ( ! V_176 -> V_187 )
goto V_190;
F_95 ( V_188 , V_178 -> V_185 ) ;
F_90 ( V_178 ) ;
V_190:
F_96 ( V_176 ) ;
}
