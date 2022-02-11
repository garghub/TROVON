static inline unsigned int F_1 ( void )
{
return V_1 [ 1 ] . V_2 - V_3 - 1 ;
}
static inline T_1 F_2 ( T_1 V_4 , int V_5 )
{
V_4 &= V_6 ;
#ifndef F_3
if ( ! V_5 ) {
V_4 &= ~ V_7 ;
V_4 |= ( V_4 & V_8 ) << 1 ;
}
V_4 |= V_8 ;
#endif
return V_4 ;
}
static inline T_1 F_4 ( T_1 V_9 , int V_5 )
{
#ifdef F_5
return ( V_9 & V_10 ) | V_11 ;
#else
return V_9 & V_10 ;
#endif
}
static inline void F_6 ( struct V_12 * V_13 ,
T_2 V_14 )
{
unsigned long V_15 ;
F_7 ( V_15 ) ;
F_8 ( V_16 , V_14 ) ;
F_8 ( V_17 , V_13 -> V_18 ) ;
F_8 ( V_19 , ( unsigned long ) V_13 -> V_9 ) ;
F_8 ( V_20 , ( T_1 ) V_13 -> V_21 ) ;
F_8 ( V_22 , ( T_1 ) ( V_13 -> V_21 >> 32 ) ) ;
#ifdef F_3
F_8 ( V_23 , V_13 -> V_24 ) ;
#endif
asm volatile("isync; tlbwe" : : : "memory");
#ifdef F_3
F_8 ( V_23 , 0 ) ;
F_9 () ;
#endif
F_10 ( V_15 ) ;
F_11 ( V_14 , V_13 -> V_24 , V_13 -> V_18 ,
V_13 -> V_9 , V_13 -> V_21 ) ;
}
static T_1 F_12 ( unsigned long V_25 )
{
unsigned long V_15 ;
T_1 V_14 ;
F_7 ( V_15 ) ;
F_8 ( V_26 , 0 ) ;
asm volatile("tlbsx 0, %0" : : "b" (eaddr & ~CONFIG_PAGE_OFFSET));
V_14 = F_13 ( V_16 ) ;
F_10 ( V_15 ) ;
return V_14 ;
}
static inline void F_14 ( struct V_27 * V_28 ,
int V_29 , int V_30 , struct V_12 * V_13 )
{
T_1 V_14 ;
if ( V_29 == 0 ) {
V_14 = F_12 ( V_13 -> V_9 ) ;
F_6 ( V_13 , V_14 ) ;
} else {
F_6 ( V_13 ,
F_15 ( 1 ) |
F_16 ( F_17 ( V_30 ) ) ) ;
}
}
static void F_18 ( struct V_27 * V_28 ,
struct V_12 * V_31 ,
struct V_12 * V_13 ,
int V_32 , int V_30 )
{
int V_33 ;
F_19 () ;
V_33 = F_20 ( & V_28 -> V_34 , V_31 ) ;
V_13 -> V_18 |= F_21 ( V_33 ) ;
F_14 ( V_28 , V_32 , V_30 , V_13 ) ;
F_22 () ;
}
void F_23 ( struct V_35 * V_34 )
{
struct V_27 * V_28 = F_24 ( V_34 ) ;
struct V_12 V_36 ;
T_3 V_37 = ( ( T_3 ) V_34 -> V_38 . V_39 ) & V_40 ;
unsigned int V_33 ;
T_4 V_41 ;
V_41 = ( T_4 ) F_25 ( ( void * ) V_37 ) >> V_42 ;
F_26 ( F_27 ( V_41 ) ) ;
F_19 () ;
V_33 = F_28 ( V_28 , 0 , 0 , 0 , 0 ) ;
V_36 . V_18 = V_43 | V_44 | F_21 ( V_33 ) |
F_29 ( V_45 ) ;
V_36 . V_9 = V_34 -> V_38 . V_46 | V_11 ;
V_36 . V_21 = ( ( V_47 ) V_41 << V_42 ) |
V_48 | V_49 | V_50 | V_51 ;
V_36 . V_24 = 0 ;
F_6 ( & V_36 , F_15 ( 1 ) | F_16 ( V_3 ) ) ;
F_22 () ;
}
void F_30 ( struct V_27 * V_28 , int V_29 ,
int V_52 )
{
struct V_12 * V_31 =
F_31 ( V_28 , V_29 , V_52 ) ;
struct V_53 * V_54 = & V_28 -> V_55 [ V_29 ] [ V_52 ] . V_54 ;
if ( ! ( V_54 -> V_15 & V_56 ) ) {
F_32 ( V_54 -> V_15 & ( V_57 | V_58 ) ,
L_1 , V_59 , V_54 -> V_15 ) ;
F_33 ( V_29 == 1 && V_28 -> V_60 [ V_52 ] ) ;
}
if ( V_29 == 1 && V_54 -> V_15 & V_57 ) {
V_47 V_61 = V_28 -> V_60 [ V_52 ] ;
int V_62 ;
unsigned long V_15 ;
F_7 ( V_15 ) ;
while ( V_61 ) {
V_62 = F_34 ( V_61 & - V_61 ) ;
F_8 ( V_16 ,
F_15 ( 1 ) |
F_16 ( F_17 ( V_62 ) ) ) ;
F_8 ( V_17 , 0 ) ;
asm volatile("tlbwe");
V_28 -> V_63 [ V_62 ] = 0 ;
V_61 &= V_61 - 1 ;
}
F_35 () ;
V_28 -> V_60 [ V_52 ] = 0 ;
V_54 -> V_15 &= ~ ( V_57 | V_56 ) ;
F_10 ( V_15 ) ;
}
if ( V_29 == 1 && V_54 -> V_15 & V_58 ) {
F_36 ( V_28 ) ;
V_54 -> V_15 &= ~ ( V_58 | V_56 ) ;
}
if ( ! ( V_54 -> V_15 & V_56 ) )
return;
F_37 ( V_28 , V_31 ) ;
V_54 -> V_15 &= ~ V_56 ;
}
static inline int F_38 ( struct V_12 * V_64 )
{
return V_64 -> V_21 & ( V_48 | V_50 ) ;
}
static inline void F_39 ( struct V_53 * V_54 ,
struct V_12 * V_31 ,
T_4 V_41 )
{
V_54 -> V_41 = V_41 ;
V_54 -> V_15 |= V_56 ;
if ( F_38 ( V_31 ) )
F_40 ( V_41 ) ;
}
static inline void F_41 ( struct V_53 * V_54 )
{
if ( V_54 -> V_15 & V_56 ) {
F_42 ( V_54 -> V_41 , V_54 -> V_15 ) ;
V_54 -> V_15 = 0 ;
}
}
static void F_43 ( struct V_27 * V_28 )
{
if ( V_28 -> V_60 )
memset ( V_28 -> V_60 , 0 ,
sizeof( V_47 ) * V_28 -> V_65 [ 1 ] . V_2 ) ;
if ( V_28 -> V_63 )
memset ( V_28 -> V_63 , 0 ,
sizeof( unsigned int ) * V_1 [ 1 ] . V_2 ) ;
}
static void F_44 ( struct V_27 * V_28 )
{
int V_29 ;
int V_66 ;
for ( V_29 = 0 ; V_29 <= 1 ; V_29 ++ ) {
for ( V_66 = 0 ; V_66 < V_28 -> V_65 [ V_29 ] . V_2 ; V_66 ++ ) {
struct V_53 * V_54 =
& V_28 -> V_55 [ V_29 ] [ V_66 ] . V_54 ;
F_41 ( V_54 ) ;
}
}
}
void F_45 ( struct V_35 * V_34 )
{
struct V_27 * V_28 = F_24 ( V_34 ) ;
F_36 ( V_28 ) ;
F_44 ( V_28 ) ;
F_43 ( V_28 ) ;
}
static void F_46 (
struct V_35 * V_34 ,
struct V_12 * V_31 ,
int V_67 , struct V_53 * V_54 , V_47 V_68 ,
struct V_12 * V_13 )
{
T_4 V_41 = V_54 -> V_41 ;
T_1 V_69 = V_34 -> V_38 . V_39 -> V_70 & V_71 ;
F_47 ( ! ( V_54 -> V_15 & V_56 ) ) ;
V_13 -> V_18 = F_29 ( V_67 ) | F_48 ( V_31 ) | V_43 ;
V_13 -> V_9 = ( V_68 & V_72 ) |
F_4 ( V_31 -> V_9 , V_69 ) ;
V_13 -> V_21 = ( ( V_47 ) V_41 << V_42 ) |
F_2 ( V_31 -> V_21 , V_69 ) ;
#ifdef F_3
V_13 -> V_24 = V_73 | V_34 -> V_74 -> V_38 . V_75 ;
#endif
}
static inline int F_49 ( struct V_27 * V_28 ,
V_47 V_68 , T_5 V_76 , struct V_12 * V_31 ,
int V_29 , struct V_12 * V_13 ,
struct V_53 * V_54 )
{
struct V_77 * V_78 ;
unsigned long V_41 = 0 ;
unsigned long V_79 ;
int V_80 = 0 ;
int V_67 = V_45 ;
V_78 = F_50 ( V_28 -> V_34 . V_74 , V_76 ) ;
V_79 = F_51 ( V_78 , V_76 ) ;
if ( V_29 == 1 ) {
struct V_81 * V_82 ;
F_52 ( & V_83 -> V_84 -> V_85 ) ;
V_82 = F_53 ( V_83 -> V_84 , V_79 ) ;
if ( V_82 && V_79 >= V_82 -> V_86 &&
( V_82 -> V_87 & V_88 ) ) {
unsigned long V_89 , V_90 ;
unsigned long V_91 , V_92 ;
V_80 = 1 ;
V_89 = V_82 -> V_93 ;
V_90 = V_89 +
( ( V_82 -> V_94 - V_82 -> V_86 ) >> V_42 ) ;
V_41 = V_89 + ( ( V_79 - V_82 -> V_86 ) >> V_42 ) ;
V_91 = V_41 - ( V_76 - V_78 -> V_95 ) ;
V_92 = V_91 + V_78 -> V_96 ;
if ( V_89 < V_91 )
V_89 = V_91 ;
if ( V_90 > V_92 )
V_90 = V_92 ;
V_67 = ( V_31 -> V_18 & V_97 ) >>
V_98 ;
V_67 = F_54 ( V_45 , V_67 & ~ 1 ) ;
for (; V_67 > V_45 ; V_67 -= 2 ) {
unsigned long V_99 , V_100 , V_101 ;
V_101 = 1 << ( V_67 - 2 ) ;
V_99 = V_76 & ~ ( V_101 - 1 ) ;
V_100 = V_99 + V_101 ;
if ( V_99 + V_41 - V_76 < V_89 )
continue;
if ( V_100 + V_41 - V_76 > V_90 )
continue;
if ( ( V_76 & ( V_101 - 1 ) ) !=
( V_41 & ( V_101 - 1 ) ) )
continue;
V_68 &= ~ ( ( V_101 << V_42 ) - 1 ) ;
V_41 &= ~ ( V_101 - 1 ) ;
break;
}
} else if ( V_82 && V_79 >= V_82 -> V_86 &&
( V_82 -> V_87 & V_102 ) ) {
unsigned long V_103 = F_55 ( V_82 ) ;
V_67 = ( V_31 -> V_18 & V_97 ) >>
V_98 ;
V_67 = F_56 ( F_57 ( V_103 ) - 10 , V_67 ) ;
V_67 = F_54 ( V_45 , V_67 & ~ 1 ) ;
}
F_58 ( & V_83 -> V_84 -> V_85 ) ;
}
if ( F_59 ( ! V_80 ) ) {
unsigned long V_101 = 1 << ( V_67 + 10 - V_42 ) ;
V_41 = F_60 ( V_78 , V_76 ) ;
if ( F_61 ( V_41 ) ) {
F_62 ( V_104 L_2 ,
( long ) V_76 ) ;
return - V_105 ;
}
V_41 &= ~ ( V_101 - 1 ) ;
V_68 &= ~ ( ( V_101 << V_42 ) - 1 ) ;
}
F_39 ( V_54 , V_31 , V_41 ) ;
F_46 ( & V_28 -> V_34 , V_31 , V_67 ,
V_54 , V_68 , V_13 ) ;
F_63 ( V_41 ) ;
F_64 ( V_41 ) ;
return 0 ;
}
static int F_65 ( struct V_27 * V_28 , int V_52 ,
struct V_12 * V_13 )
{
struct V_12 * V_31 ;
struct V_53 * V_54 ;
int V_32 = 0 ;
int V_30 = 0 ;
int V_106 ;
V_31 = F_31 ( V_28 , 0 , V_52 ) ;
V_54 = & V_28 -> V_55 [ 0 ] [ V_52 ] . V_54 ;
V_106 = F_49 ( V_28 , F_66 ( V_31 ) ,
F_67 ( V_31 ) >> V_42 ,
V_31 , 0 , V_13 , V_54 ) ;
if ( V_106 )
return V_106 ;
F_18 ( V_28 , V_31 , V_13 , V_32 , V_30 ) ;
return 0 ;
}
static int F_68 ( struct V_27 * V_28 ,
struct V_53 * V_54 ,
int V_52 )
{
unsigned int V_30 = V_28 -> V_107 ++ ;
if ( F_69 ( V_28 -> V_107 >= F_1 () ) )
V_28 -> V_107 = 0 ;
if ( V_28 -> V_63 [ V_30 ] ) {
unsigned int V_108 = V_28 -> V_63 [ V_30 ] - 1 ;
V_28 -> V_60 [ V_108 ] &= ~ ( 1ULL << V_30 ) ;
}
V_28 -> V_55 [ 1 ] [ V_52 ] . V_54 . V_15 |= V_57 ;
V_28 -> V_60 [ V_52 ] |= ( V_47 ) 1 << V_30 ;
V_28 -> V_63 [ V_30 ] = V_52 + 1 ;
F_33 ( ! ( V_54 -> V_15 & V_56 ) ) ;
return V_30 ;
}
static int F_70 ( struct V_27 * V_28 ,
V_47 V_68 , T_5 V_76 , struct V_12 * V_31 ,
struct V_12 * V_13 , int V_52 )
{
struct V_53 * V_54 = & V_28 -> V_55 [ 1 ] [ V_52 ] . V_54 ;
int V_30 ;
int V_106 ;
V_106 = F_49 ( V_28 , V_68 , V_76 , V_31 , 1 , V_13 ,
V_54 ) ;
if ( V_106 )
return V_106 ;
if ( F_71 ( V_13 ) == V_45 ) {
V_28 -> V_55 [ 1 ] [ V_52 ] . V_54 . V_15 |= V_58 ;
F_18 ( V_28 , V_31 , V_13 , 0 , 0 ) ;
return 0 ;
}
V_30 = F_68 ( V_28 , V_54 , V_52 ) ;
F_18 ( V_28 , V_31 , V_13 , 1 , V_30 ) ;
return 0 ;
}
void F_72 ( struct V_35 * V_34 , V_47 V_25 , T_6 V_109 ,
unsigned int V_110 )
{
struct V_27 * V_28 = F_24 ( V_34 ) ;
struct V_111 * V_112 ;
struct V_12 * V_31 , V_13 ;
int V_29 = F_73 ( V_110 ) ;
int V_52 = F_74 ( V_110 ) ;
V_31 = F_31 ( V_28 , V_29 , V_52 ) ;
switch ( V_29 ) {
case 0 :
V_112 = & V_28 -> V_55 [ V_29 ] [ V_52 ] ;
if ( ! ( V_112 -> V_54 . V_15 & V_56 ) ) {
F_65 ( V_28 , V_52 , & V_13 ) ;
} else {
F_46 ( V_34 , V_31 , V_45 ,
& V_112 -> V_54 , V_25 , & V_13 ) ;
F_18 ( V_28 , V_31 , & V_13 , 0 , 0 ) ;
}
break;
case 1 : {
T_5 V_76 = V_109 >> V_42 ;
F_70 ( V_28 , V_25 , V_76 , V_31 , & V_13 ,
V_52 ) ;
break;
}
default:
F_75 () ;
break;
}
}
int F_76 ( struct V_74 * V_74 , unsigned long V_79 )
{
F_77 ( V_79 ) ;
F_78 ( V_74 ) ;
return 0 ;
}
int F_79 ( struct V_74 * V_74 , unsigned long V_89 , unsigned long V_90 )
{
F_76 ( V_74 , V_89 ) ;
return 0 ;
}
int F_80 ( struct V_74 * V_74 , unsigned long V_79 )
{
return 0 ;
}
int F_81 ( struct V_74 * V_74 , unsigned long V_79 )
{
return 0 ;
}
void F_82 ( struct V_74 * V_74 , unsigned long V_79 , T_7 V_113 )
{
F_76 ( V_74 , V_79 ) ;
}
int F_83 ( struct V_27 * V_28 )
{
V_1 [ 0 ] . V_2 = F_13 ( V_114 ) & V_115 ;
V_1 [ 1 ] . V_2 = F_13 ( V_116 ) & V_115 ;
if ( V_1 [ 0 ] . V_2 == 0 ||
V_1 [ 1 ] . V_2 == 0 ) {
F_84 ( L_3 , V_59 ) ;
return - V_117 ;
}
V_1 [ 0 ] . V_118 = ( F_13 ( V_114 ) & V_119 ) >>
V_120 ;
V_1 [ 1 ] . V_118 = V_1 [ 1 ] . V_2 ;
if ( ! F_85 ( V_1 [ 0 ] . V_2 ) ||
! F_85 ( V_1 [ 0 ] . V_118 ) ||
V_1 [ 0 ] . V_2 < V_1 [ 0 ] . V_118 ||
V_1 [ 0 ] . V_118 == 0 ) {
F_84 ( L_4 ,
V_59 , V_1 [ 0 ] . V_2 ,
V_1 [ 0 ] . V_118 ) ;
return - V_117 ;
}
V_1 [ 0 ] . V_121 =
V_1 [ 0 ] . V_2 / V_1 [ 0 ] . V_118 ;
V_1 [ 1 ] . V_121 = 1 ;
V_28 -> V_63 = F_86 ( sizeof( unsigned int ) *
V_1 [ 1 ] . V_2 ,
V_122 ) ;
if ( ! V_28 -> V_63 )
return - V_105 ;
return 0 ;
}
void F_87 ( struct V_27 * V_28 )
{
F_88 ( V_28 -> V_63 ) ;
}
