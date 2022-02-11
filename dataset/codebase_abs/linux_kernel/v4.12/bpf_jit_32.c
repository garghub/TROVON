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
static T_4 F_10 ( T_4 V_9 , T_4 V_10 )
{
return V_9 % V_10 ;
}
static inline void F_11 ( int V_11 , T_4 V_12 , struct V_13 * V_14 )
{
V_12 |= ( V_11 << 28 ) ;
V_12 = F_12 ( V_12 ) ;
if ( V_14 -> V_15 != NULL )
V_14 -> V_15 [ V_14 -> V_16 ] = V_12 ;
V_14 -> V_16 ++ ;
}
static inline void F_13 ( T_4 V_12 , struct V_13 * V_14 )
{
F_11 ( V_17 , V_12 , V_14 ) ;
}
static T_3 F_14 ( struct V_13 * V_14 )
{
T_3 V_4 = 0 ;
if ( ( V_14 -> V_18 -> V_19 > 1 ) ||
( V_14 -> V_18 -> V_20 [ 0 ] . V_21 == ( V_22 | V_23 ) ) )
V_4 |= 1 << V_24 ;
#ifdef F_15
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
static inline int F_16 ( struct V_13 * V_14 )
{
return F_17 ( V_14 -> V_29 & V_38 ) ;
}
static void F_18 ( void * V_39 , unsigned int V_5 )
{
T_4 * V_6 ;
for ( V_6 = V_39 ; V_5 >= sizeof( T_4 ) ; V_5 -= sizeof( T_4 ) )
* V_6 ++ = F_12 ( V_40 ) ;
}
static void F_19 ( struct V_13 * V_14 )
{
T_3 V_41 = F_14 ( V_14 ) ;
T_3 V_42 ;
#ifdef F_15
F_13 ( F_20 ( V_26 , V_43 ) , V_14 ) ;
F_13 ( F_21 ( V_41 ) , V_14 ) ;
F_13 ( F_22 ( V_25 , V_26 , 4 ) , V_14 ) ;
#else
if ( V_41 )
F_13 ( F_21 ( V_41 ) , V_14 ) ;
#endif
if ( V_14 -> V_29 & ( V_31 | V_32 ) )
F_13 ( F_20 ( V_33 , V_44 ) , V_14 ) ;
if ( V_14 -> V_29 & V_31 ) {
V_42 = F_23 ( struct V_1 , V_45 ) ;
F_13 ( F_24 ( V_34 , V_33 , V_42 ) , V_14 ) ;
V_42 = F_23 ( struct V_1 , V_19 ) ;
F_13 ( F_24 ( V_35 , V_33 , V_42 ) , V_14 ) ;
V_42 = F_23 ( struct V_1 , V_46 ) ;
F_13 ( F_24 ( V_47 , V_33 , V_42 ) , V_14 ) ;
F_13 ( F_25 ( V_35 , V_35 , V_47 ) , V_14 ) ;
}
if ( V_14 -> V_48 & V_49 )
F_13 ( F_26 ( V_37 , 0 ) , V_14 ) ;
if ( F_27 ( & V_14 -> V_18 -> V_20 [ 0 ] ) )
F_13 ( F_26 ( V_24 , 0 ) , V_14 ) ;
if ( V_14 -> V_29 & V_38 )
F_13 ( F_22 ( V_43 , V_43 , F_16 ( V_14 ) * 4 ) , V_14 ) ;
}
static void F_28 ( struct V_13 * V_14 )
{
T_3 V_41 = F_14 ( V_14 ) ;
if ( V_14 -> V_29 & V_38 )
F_13 ( F_29 ( V_43 , V_43 , F_16 ( V_14 ) * 4 ) , V_14 ) ;
V_41 &= ~ ( 1 << V_27 ) ;
#ifdef F_15
V_41 &= ~ ( 1 << V_26 ) ;
V_41 |= ( 1 << V_43 ) ;
F_13 ( F_30 ( V_43 , V_41 ) , V_14 ) ;
#else
if ( V_41 ) {
if ( V_14 -> V_29 & V_30 )
V_41 |= 1 << V_28 ;
F_13 ( F_31 ( V_41 ) , V_14 ) ;
}
if ( ! ( V_14 -> V_29 & V_30 ) )
F_13 ( F_32 ( V_27 ) , V_14 ) ;
#endif
}
static T_5 F_33 ( T_4 V_50 )
{
T_4 V_51 ;
for ( V_51 = 0 ; V_51 < 16 ; V_51 ++ )
if ( ( V_50 & ~ F_34 ( 0xff , 2 * V_51 ) ) == 0 )
return F_35 ( V_50 , 2 * V_51 ) | ( V_51 << 8 ) ;
return - 1 ;
}
static T_3 F_36 ( T_4 V_52 , struct V_13 * V_14 )
{
unsigned V_53 = 0 , V_3 ;
T_3 V_54 ;
if ( V_14 -> V_15 == NULL ) {
V_14 -> V_55 ++ ;
return 0 ;
}
while ( ( V_53 < V_14 -> V_55 ) && V_14 -> V_56 [ V_53 ] ) {
if ( V_14 -> V_56 [ V_53 ] == V_52 )
break;
V_53 ++ ;
}
if ( V_14 -> V_56 [ V_53 ] == 0 )
V_14 -> V_56 [ V_53 ] = V_52 ;
V_3 = V_14 -> V_57 [ V_14 -> V_18 -> V_19 ] ;
V_3 += V_14 -> V_58 ;
V_3 += V_14 -> V_59 ;
V_3 += V_53 * 4 ;
V_14 -> V_15 [ V_3 / 4 ] = V_52 ;
V_54 = V_3 - ( 8 + V_14 -> V_16 * 4 ) ;
if ( V_54 & ~ 0xfff ) {
V_14 -> V_48 |= V_60 ;
return 0 ;
}
return V_54 ;
}
static inline void F_37 ( int V_61 , T_4 V_62 , struct V_13 * V_14 )
{
#if V_63 < 7
F_13 ( F_24 ( V_61 , V_28 , F_36 ( V_62 , V_14 ) ) , V_14 ) ;
#else
F_13 ( F_38 ( V_61 , V_62 & 0xffff ) , V_14 ) ;
if ( V_62 > 0xffff )
F_13 ( F_39 ( V_61 , V_62 >> 16 ) , V_14 ) ;
#endif
}
static inline void F_40 ( int V_61 , T_4 V_62 , struct V_13 * V_14 )
{
int V_64 = F_33 ( V_62 ) ;
if ( V_64 >= 0 )
F_13 ( F_26 ( V_61 , V_64 ) , V_14 ) ;
else
F_37 ( V_61 , V_62 , V_14 ) ;
}
static void F_41 ( T_2 V_11 , T_2 V_65 , T_2 V_66 , struct V_13 * V_14 )
{
F_11 ( V_11 , F_42 ( V_67 , V_66 , 1 ) , V_14 ) ;
F_11 ( V_11 , F_42 ( V_68 , V_66 , 0 ) , V_14 ) ;
F_11 ( V_11 , F_42 ( V_69 , V_66 , 3 ) , V_14 ) ;
F_11 ( V_11 , F_43 ( V_67 , V_67 , 16 ) , V_14 ) ;
F_11 ( V_11 , F_42 ( V_44 , V_66 , 2 ) , V_14 ) ;
F_11 ( V_11 , F_44 ( V_67 , V_67 , V_68 , V_70 , 24 ) , V_14 ) ;
F_11 ( V_11 , F_45 ( V_67 , V_67 , V_69 ) , V_14 ) ;
F_11 ( V_11 , F_44 ( V_65 , V_67 , V_44 , V_70 , 8 ) , V_14 ) ;
}
static void F_46 ( T_2 V_11 , T_2 V_65 , T_2 V_66 , struct V_13 * V_14 )
{
F_11 ( V_11 , F_42 ( V_68 , V_66 , 0 ) , V_14 ) ;
F_11 ( V_11 , F_42 ( V_69 , V_66 , 1 ) , V_14 ) ;
F_11 ( V_11 , F_44 ( V_65 , V_69 , V_68 , V_70 , 8 ) , V_14 ) ;
}
static inline void F_47 ( T_2 V_71 , T_2 V_72 , struct V_13 * V_14 )
{
F_13 ( F_43 ( V_68 , V_72 , 8 ) , V_14 ) ;
F_13 ( F_44 ( V_71 , V_68 , V_72 , V_73 , 8 ) , V_14 ) ;
F_13 ( F_48 ( V_71 , V_71 , 0x8ff ) , V_14 ) ;
}
static void F_41 ( T_2 V_11 , T_2 V_65 , T_2 V_66 , struct V_13 * V_14 )
{
F_11 ( V_11 , F_24 ( V_65 , V_66 , 0 ) , V_14 ) ;
#ifdef F_49
F_11 ( V_11 , F_50 ( V_65 , V_65 ) , V_14 ) ;
#endif
}
static void F_46 ( T_2 V_11 , T_2 V_65 , T_2 V_66 , struct V_13 * V_14 )
{
F_11 ( V_11 , F_51 ( V_65 , V_66 , 0 ) , V_14 ) ;
#ifdef F_49
F_11 ( V_11 , F_52 ( V_65 , V_65 ) , V_14 ) ;
#endif
}
static inline void F_47 ( T_2 V_71 V_74 ,
T_2 V_72 V_74 ,
struct V_13 * V_14 V_74 )
{
#ifdef F_49
F_13 ( F_52 ( V_71 , V_72 ) , V_14 ) ;
#endif
}
static inline T_4 F_53 ( unsigned V_75 , struct V_13 * V_14 )
{
T_4 V_54 ;
if ( V_14 -> V_15 == NULL )
return 0 ;
V_54 = V_14 -> V_57 [ V_75 ] + V_14 -> V_58 - ( V_14 -> V_16 * 4 + 8 ) ;
return V_54 >> 2 ;
}
static inline void F_54 ( T_2 V_11 , struct V_13 * V_14 )
{
if ( V_14 -> V_76 >= 0 ) {
F_11 ( V_11 , F_55 ( F_53 ( V_14 -> V_76 , V_14 ) ) , V_14 ) ;
F_13 ( F_20 ( V_44 , V_44 ) , V_14 ) ;
} else {
F_11 ( V_11 , F_26 ( V_44 , 0 ) , V_14 ) ;
F_11 ( V_11 , F_55 ( F_53 ( V_14 -> V_18 -> V_19 , V_14 ) ) , V_14 ) ;
}
}
static inline void F_56 ( T_2 V_77 , struct V_13 * V_14 )
{
#if V_63 < 5
F_13 ( F_20 ( V_27 , V_28 ) , V_14 ) ;
if ( V_78 & V_79 )
F_13 ( F_32 ( V_77 ) , V_14 ) ;
else
F_13 ( F_20 ( V_28 , V_77 ) , V_14 ) ;
#else
F_13 ( F_57 ( V_77 ) , V_14 ) ;
#endif
}
static inline void F_58 ( T_2 V_61 , T_2 V_80 , T_2 V_81 , struct V_13 * V_14 ,
int V_82 )
{
#if V_63 == 7
if ( V_78 & V_83 ) {
if ( V_82 == V_84 )
F_13 ( F_59 ( V_61 , V_80 , V_81 ) , V_14 ) ;
else {
F_13 ( F_59 ( V_67 , V_80 , V_81 ) , V_14 ) ;
F_13 ( F_60 ( V_61 , V_81 , V_67 , V_80 ) , V_14 ) ;
}
return;
}
#endif
if ( V_81 != V_68 )
F_13 ( F_20 ( V_68 , V_81 ) , V_14 ) ;
if ( V_80 != V_44 )
F_13 ( F_20 ( V_44 , V_80 ) , V_14 ) ;
V_14 -> V_29 |= V_30 ;
F_40 ( V_67 , V_82 == V_84 ? ( T_4 ) F_9 : ( T_4 ) F_10 ,
V_14 ) ;
F_56 ( V_67 , V_14 ) ;
if ( V_61 != V_44 )
F_13 ( F_20 ( V_61 , V_44 ) , V_14 ) ;
}
static inline void F_61 ( struct V_13 * V_14 )
{
if ( ! ( V_14 -> V_29 & V_36 ) )
V_14 -> V_48 |= V_49 ;
V_14 -> V_29 |= V_36 ;
}
static int F_62 ( struct V_13 * V_14 )
{
void * V_85 [] = { F_3 , F_5 , F_7 } ;
const struct V_86 * V_87 = V_14 -> V_18 ;
const struct V_88 * V_12 ;
unsigned V_53 , V_89 , V_42 , V_90 ;
int V_64 ;
T_4 V_52 ;
for ( V_53 = 0 ; V_53 < V_87 -> V_19 ; V_53 ++ ) {
T_3 V_21 ;
V_12 = & ( V_87 -> V_20 [ V_53 ] ) ;
V_52 = V_12 -> V_52 ;
V_21 = F_63 ( V_12 ) ;
if ( V_14 -> V_15 == NULL )
V_14 -> V_57 [ V_53 ] = V_14 -> V_16 * 4 ;
switch ( V_21 ) {
case V_91 | V_92 :
F_40 ( V_24 , V_52 , V_14 ) ;
break;
case V_91 | V_93 | V_94 :
V_14 -> V_29 |= V_32 ;
F_64 ( F_65 ( struct V_1 , V_19 ) != 4 ) ;
F_13 ( F_24 ( V_24 , V_33 ,
F_23 ( struct V_1 , V_19 ) ) , V_14 ) ;
break;
case V_91 | V_95 :
V_14 -> V_29 |= F_66 ( V_52 ) ;
F_13 ( F_24 ( V_24 , V_43 , F_67 ( V_52 ) ) , V_14 ) ;
break;
case V_91 | V_93 | V_96 :
V_89 = 2 ;
goto V_97;
case V_91 | V_98 | V_96 :
V_89 = 1 ;
goto V_97;
case V_91 | V_99 | V_96 :
V_89 = 0 ;
V_97:
F_40 ( V_100 , V_52 , V_14 ) ;
V_101:
V_14 -> V_29 |= V_31 | V_30 ;
if ( V_89 > 0 ) {
F_13 ( F_22 ( V_47 , V_35 ,
1 << V_89 ) , V_14 ) ;
F_13 ( F_68 ( V_47 , V_100 ) , V_14 ) ;
V_90 = V_102 ;
} else {
F_13 ( F_68 ( V_35 , V_100 ) , V_14 ) ;
V_90 = V_103 ;
}
F_11 ( V_90 , F_69 ( V_100 , 0 ) , V_14 ) ;
F_11 ( V_90 , F_70 ( V_47 , V_100 , V_34 ) ,
V_14 ) ;
if ( V_89 == 0 )
F_11 ( V_90 , F_42 ( V_24 , V_47 , 0 ) ,
V_14 ) ;
else if ( V_89 == 1 )
F_46 ( V_90 , V_24 , V_47 , V_14 ) ;
else if ( V_89 == 2 )
F_41 ( V_90 , V_24 , V_47 , V_14 ) ;
F_11 ( V_90 , F_55 ( F_53 ( V_53 + 1 , V_14 ) ) , V_14 ) ;
F_40 ( V_67 , ( T_4 ) V_85 [ V_89 ] , V_14 ) ;
F_13 ( F_20 ( V_44 , V_33 ) , V_14 ) ;
F_56 ( V_67 , V_14 ) ;
F_13 ( F_69 ( V_68 , 0 ) , V_14 ) ;
F_54 ( V_104 , V_14 ) ;
F_13 ( F_20 ( V_24 , V_44 ) , V_14 ) ;
break;
case V_91 | V_93 | V_105 :
V_89 = 2 ;
goto V_106;
case V_91 | V_98 | V_105 :
V_89 = 1 ;
goto V_106;
case V_91 | V_99 | V_105 :
V_89 = 0 ;
V_106:
F_61 ( V_14 ) ;
F_71 ( V_107 , V_100 , V_37 , V_52 , V_14 ) ;
goto V_101;
case V_108 | V_92 :
V_14 -> V_29 |= V_36 ;
F_40 ( V_37 , V_52 , V_14 ) ;
break;
case V_108 | V_93 | V_94 :
V_14 -> V_29 |= V_36 | V_32 ;
F_13 ( F_24 ( V_37 , V_33 ,
F_23 ( struct V_1 , V_19 ) ) , V_14 ) ;
break;
case V_108 | V_95 :
V_14 -> V_29 |= V_36 | F_66 ( V_52 ) ;
F_13 ( F_24 ( V_37 , V_43 , F_67 ( V_52 ) ) , V_14 ) ;
break;
case V_108 | V_99 | V_109 :
V_14 -> V_29 |= V_36 | V_31 | V_30 ;
if ( ( int ) V_52 < 0 )
return - 1 ;
F_40 ( V_100 , V_52 , V_14 ) ;
F_13 ( F_68 ( V_35 , V_100 ) , V_14 ) ;
F_11 ( V_103 , F_72 ( V_44 , V_34 ,
V_68 ) , V_14 ) ;
F_11 ( V_103 , F_55 ( F_53 ( V_53 + 1 , V_14 ) - 2 ) , V_14 ) ;
F_13 ( F_20 ( V_44 , V_33 ) , V_14 ) ;
F_40 ( V_67 , ( T_4 ) F_3 , V_14 ) ;
F_56 ( V_67 , V_14 ) ;
F_13 ( F_69 ( V_68 , 0 ) , V_14 ) ;
F_54 ( V_104 , V_14 ) ;
F_13 ( F_73 ( V_37 , V_44 , 0x00f ) , V_14 ) ;
F_13 ( F_43 ( V_37 , V_37 , 2 ) , V_14 ) ;
break;
case V_110 :
V_14 -> V_29 |= F_66 ( V_52 ) ;
F_13 ( F_74 ( V_24 , V_43 , F_67 ( V_52 ) ) , V_14 ) ;
break;
case V_111 :
F_61 ( V_14 ) ;
V_14 -> V_29 |= F_66 ( V_52 ) ;
F_13 ( F_74 ( V_37 , V_43 , F_67 ( V_52 ) ) , V_14 ) ;
break;
case V_112 | V_113 | V_114 :
F_71 ( V_107 , V_24 , V_24 , V_52 , V_14 ) ;
break;
case V_112 | V_113 | V_115 :
F_61 ( V_14 ) ;
F_13 ( F_70 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_116 | V_114 :
F_71 ( V_117 , V_24 , V_24 , V_52 , V_14 ) ;
break;
case V_112 | V_116 | V_115 :
F_61 ( V_14 ) ;
F_13 ( F_25 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_118 | V_114 :
F_40 ( V_47 , V_52 , V_14 ) ;
F_13 ( F_75 ( V_24 , V_24 , V_47 ) , V_14 ) ;
break;
case V_112 | V_118 | V_115 :
F_61 ( V_14 ) ;
F_13 ( F_75 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_84 | V_114 :
if ( V_52 == 1 )
break;
F_40 ( V_47 , V_52 , V_14 ) ;
F_58 ( V_24 , V_24 , V_47 , V_14 , V_84 ) ;
break;
case V_112 | V_84 | V_115 :
F_61 ( V_14 ) ;
F_13 ( F_69 ( V_37 , 0 ) , V_14 ) ;
F_54 ( V_119 , V_14 ) ;
F_58 ( V_24 , V_24 , V_37 , V_14 , V_84 ) ;
break;
case V_112 | V_120 | V_114 :
if ( V_52 == 1 ) {
F_40 ( V_24 , 0 , V_14 ) ;
break;
}
F_40 ( V_47 , V_52 , V_14 ) ;
F_58 ( V_24 , V_24 , V_47 , V_14 , V_120 ) ;
break;
case V_112 | V_120 | V_115 :
F_61 ( V_14 ) ;
F_13 ( F_69 ( V_37 , 0 ) , V_14 ) ;
F_54 ( V_119 , V_14 ) ;
F_58 ( V_24 , V_24 , V_37 , V_14 , V_120 ) ;
break;
case V_112 | V_121 | V_114 :
F_71 ( V_122 , V_24 , V_24 , V_52 , V_14 ) ;
break;
case V_112 | V_121 | V_115 :
F_61 ( V_14 ) ;
F_13 ( F_45 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_123 | V_114 :
F_71 ( V_124 , V_24 , V_24 , V_52 , V_14 ) ;
break;
case V_125 | V_126 :
case V_112 | V_123 | V_115 :
F_61 ( V_14 ) ;
F_13 ( F_76 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_127 | V_114 :
F_71 ( V_128 , V_24 , V_24 , V_52 , V_14 ) ;
break;
case V_112 | V_127 | V_115 :
F_61 ( V_14 ) ;
F_13 ( F_77 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_129 | V_114 :
if ( F_78 ( V_52 > 31 ) )
return - 1 ;
F_13 ( F_43 ( V_24 , V_24 , V_52 ) , V_14 ) ;
break;
case V_112 | V_129 | V_115 :
F_61 ( V_14 ) ;
F_13 ( F_79 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_130 | V_114 :
if ( F_78 ( V_52 > 31 ) )
return - 1 ;
if ( V_52 )
F_13 ( F_80 ( V_24 , V_24 , V_52 ) , V_14 ) ;
break;
case V_112 | V_130 | V_115 :
F_61 ( V_14 ) ;
F_13 ( F_81 ( V_24 , V_24 , V_37 ) , V_14 ) ;
break;
case V_112 | V_131 :
F_13 ( F_82 ( V_24 , V_24 , 0 ) , V_14 ) ;
break;
case V_132 | V_133 :
F_13 ( F_55 ( F_53 ( V_53 + V_52 + 1 , V_14 ) ) , V_14 ) ;
break;
case V_132 | V_134 | V_114 :
V_90 = V_119 ;
goto V_135;
case V_132 | V_136 | V_114 :
V_90 = V_103 ;
goto V_135;
case V_132 | V_137 | V_114 :
V_90 = V_138 ;
V_135:
V_64 = F_33 ( V_52 ) ;
if ( V_64 < 0 ) {
F_37 ( V_47 , V_52 , V_14 ) ;
F_13 ( F_68 ( V_24 , V_47 ) , V_14 ) ;
} else {
F_13 ( F_69 ( V_24 , V_64 ) , V_14 ) ;
}
V_139:
if ( V_12 -> V_140 )
F_11 ( V_90 , F_55 ( F_53 ( V_53 + V_12 -> V_140 + 1 ,
V_14 ) ) , V_14 ) ;
if ( V_12 -> V_141 )
F_11 ( V_90 ^ 1 , F_55 ( F_53 ( V_53 + V_12 -> V_141 + 1 ,
V_14 ) ) , V_14 ) ;
break;
case V_132 | V_134 | V_115 :
V_90 = V_119 ;
goto V_142;
case V_132 | V_136 | V_115 :
V_90 = V_103 ;
goto V_142;
case V_132 | V_137 | V_115 :
V_90 = V_143 ;
V_142:
F_61 ( V_14 ) ;
F_13 ( F_68 ( V_24 , V_37 ) , V_14 ) ;
goto V_139;
case V_132 | V_144 | V_114 :
V_90 = V_104 ;
V_64 = F_33 ( V_52 ) ;
if ( V_64 < 0 ) {
F_37 ( V_47 , V_52 , V_14 ) ;
F_13 ( F_83 ( V_24 , V_47 ) , V_14 ) ;
} else {
F_13 ( F_84 ( V_24 , V_64 ) , V_14 ) ;
}
goto V_139;
case V_132 | V_144 | V_115 :
F_61 ( V_14 ) ;
V_90 = V_104 ;
F_13 ( F_83 ( V_24 , V_37 ) , V_14 ) ;
goto V_139;
case V_22 | V_23 :
F_13 ( F_20 ( V_44 , V_24 ) , V_14 ) ;
goto V_145;
case V_22 | V_114 :
if ( ( V_52 == 0 ) && ( V_14 -> V_76 < 0 ) )
V_14 -> V_76 = V_53 ;
F_40 ( V_44 , V_52 , V_14 ) ;
V_145:
if ( V_53 != V_14 -> V_18 -> V_19 - 1 )
F_13 ( F_55 ( F_53 ( V_87 -> V_19 , V_14 ) ) , V_14 ) ;
break;
case V_146 | V_147 :
V_14 -> V_29 |= V_36 ;
F_13 ( F_20 ( V_37 , V_24 ) , V_14 ) ;
break;
case V_146 | V_148 :
F_61 ( V_14 ) ;
F_13 ( F_20 ( V_24 , V_37 ) , V_14 ) ;
break;
case V_125 | V_149 :
V_14 -> V_29 |= V_32 ;
F_64 ( F_65 ( struct V_1 ,
V_150 ) != 2 ) ;
V_42 = F_23 ( struct V_1 , V_150 ) ;
F_13 ( F_51 ( V_47 , V_33 , V_42 ) , V_14 ) ;
F_47 ( V_24 , V_47 , V_14 ) ;
break;
case V_125 | V_151 :
F_71 ( V_152 , V_47 , V_43 , V_153 - 1 , V_14 ) ;
F_64 ( F_65 ( struct V_154 , V_155 ) != 4 ) ;
V_42 = F_23 ( struct V_154 , V_155 ) ;
F_13 ( F_24 ( V_24 , V_47 , V_42 ) , V_14 ) ;
break;
case V_125 | V_156 :
case V_125 | V_157 :
V_14 -> V_29 |= V_32 ;
V_42 = F_23 ( struct V_1 , V_158 ) ;
F_13 ( F_24 ( V_47 , V_33 , V_42 ) , V_14 ) ;
F_13 ( F_69 ( V_47 , 0 ) , V_14 ) ;
F_54 ( V_119 , V_14 ) ;
F_64 ( F_65 ( struct V_159 ,
V_160 ) != 4 ) ;
F_64 ( F_65 ( struct V_159 ,
type ) != 2 ) ;
if ( V_21 == ( V_125 | V_156 ) ) {
V_42 = F_23 ( struct V_159 , V_160 ) ;
F_13 ( F_24 ( V_24 , V_47 , V_42 ) , V_14 ) ;
} else {
V_42 = F_23 ( struct V_159 , type ) ;
F_40 ( V_67 , V_42 , V_14 ) ;
F_13 ( F_85 ( V_24 , V_47 , V_67 ) , V_14 ) ;
}
break;
case V_125 | V_161 :
V_14 -> V_29 |= V_32 ;
F_64 ( F_65 ( struct V_1 , V_162 ) != 4 ) ;
V_42 = F_23 ( struct V_1 , V_162 ) ;
F_13 ( F_24 ( V_24 , V_33 , V_42 ) , V_14 ) ;
break;
case V_125 | V_163 :
V_14 -> V_29 |= V_32 ;
F_64 ( F_65 ( struct V_1 , V_164 ) != 4 ) ;
V_42 = F_23 ( struct V_1 , V_164 ) ;
F_13 ( F_24 ( V_24 , V_33 , V_42 ) , V_14 ) ;
break;
case V_125 | V_165 :
case V_125 | V_166 :
V_14 -> V_29 |= V_32 ;
F_64 ( F_65 ( struct V_1 , V_167 ) != 2 ) ;
V_42 = F_23 ( struct V_1 , V_167 ) ;
F_13 ( F_51 ( V_24 , V_33 , V_42 ) , V_14 ) ;
if ( V_21 == ( V_125 | V_165 ) )
F_71 ( V_128 , V_24 , V_24 , ~ V_168 , V_14 ) ;
else {
F_71 ( V_169 , V_24 , V_24 , 12 , V_14 ) ;
F_71 ( V_128 , V_24 , V_24 , 0x1 , V_14 ) ;
}
break;
case V_125 | V_170 :
V_14 -> V_29 |= V_32 ;
F_64 ( F_65 ( struct V_1 ,
V_171 [ 0 ] ) != 1 ) ;
V_42 = F_86 () ;
F_13 ( F_42 ( V_24 , V_33 , V_42 ) , V_14 ) ;
F_13 ( F_73 ( V_24 , V_24 , V_172 ) , V_14 ) ;
#ifdef F_87
F_13 ( F_80 ( V_24 , V_24 , 5 ) , V_14 ) ;
#endif
break;
case V_125 | V_173 :
V_14 -> V_29 |= V_32 ;
F_64 ( F_65 ( struct V_1 ,
V_174 ) != 2 ) ;
F_64 ( F_23 ( struct V_1 ,
V_174 ) > 0xff ) ;
V_42 = F_23 ( struct V_1 , V_174 ) ;
F_13 ( F_51 ( V_24 , V_33 , V_42 ) , V_14 ) ;
break;
case V_125 | V_175 :
V_14 -> V_29 |= V_32 | V_30 ;
F_13 ( F_20 ( V_44 , V_33 ) , V_14 ) ;
F_40 ( V_67 , ( unsigned int ) V_176 , V_14 ) ;
F_56 ( V_67 , V_14 ) ;
F_13 ( F_20 ( V_24 , V_44 ) , V_14 ) ;
break;
case V_108 | V_93 | V_96 :
V_14 -> V_29 |= V_32 ;
F_13 ( F_24 ( V_24 , V_33 , V_52 ) , V_14 ) ;
break;
default:
return - 1 ;
}
if ( V_14 -> V_48 & V_60 )
return - 1 ;
}
if ( V_14 -> V_15 == NULL )
V_14 -> V_57 [ V_53 ] = V_14 -> V_16 * 4 ;
return 0 ;
}
void F_88 ( struct V_86 * V_177 )
{
struct V_178 * V_179 ;
struct V_13 V_14 ;
unsigned V_180 ;
unsigned V_181 ;
T_2 * V_182 ;
if ( ! V_183 )
return;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_18 = V_177 ;
V_14 . V_76 = - 1 ;
V_14 . V_57 = F_89 ( 4 * ( V_14 . V_18 -> V_19 + 1 ) , V_184 ) ;
if ( V_14 . V_57 == NULL )
return;
if ( F_78 ( F_62 ( & V_14 ) ) )
goto V_185;
V_180 = V_14 . V_16 ;
F_19 ( & V_14 ) ;
V_14 . V_58 = ( V_14 . V_16 - V_180 ) * 4 ;
#if V_63 < 7
V_180 = V_14 . V_16 ;
F_28 ( & V_14 ) ;
V_14 . V_59 = ( V_14 . V_16 - V_180 ) * 4 ;
V_14 . V_16 += V_14 . V_55 ;
if ( V_14 . V_55 ) {
V_14 . V_56 = F_89 ( 4 * V_14 . V_55 , V_184 ) ;
if ( V_14 . V_56 == NULL )
goto V_185;
}
#else
F_28 ( & V_14 ) ;
#endif
V_181 = 4 * V_14 . V_16 ;
V_179 = F_90 ( V_181 , & V_182 ,
4 , F_18 ) ;
if ( V_179 == NULL )
goto V_185;
V_14 . V_15 = ( T_4 * ) V_182 ;
V_14 . V_16 = 0 ;
F_19 ( & V_14 ) ;
if ( F_62 ( & V_14 ) < 0 ) {
#if V_63 < 7
if ( V_14 . V_55 )
F_91 ( V_14 . V_56 ) ;
#endif
F_92 ( V_179 ) ;
goto V_185;
}
F_28 ( & V_14 ) ;
F_93 ( ( T_4 ) V_179 , ( T_4 ) ( V_14 . V_15 + V_14 . V_16 ) ) ;
#if V_63 < 7
if ( V_14 . V_55 )
F_91 ( V_14 . V_56 ) ;
#endif
if ( V_183 > 1 )
F_94 ( V_177 -> V_19 , V_181 , 2 , V_14 . V_15 ) ;
F_95 ( ( unsigned long ) V_179 , V_179 -> V_186 ) ;
V_177 -> V_187 = ( void * ) V_14 . V_15 ;
V_177 -> V_188 = 1 ;
V_185:
F_91 ( V_14 . V_57 ) ;
return;
}
void F_96 ( struct V_86 * V_177 )
{
unsigned long V_189 = ( unsigned long ) V_177 -> V_187 & V_190 ;
struct V_178 * V_179 = ( void * ) V_189 ;
if ( ! V_177 -> V_188 )
goto V_191;
F_97 ( V_189 , V_179 -> V_186 ) ;
F_92 ( V_179 ) ;
V_191:
F_98 ( V_177 ) ;
}
