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
static inline void F_4 ( struct V_9 * V_10 ,
T_2 V_11 )
{
unsigned long V_12 ;
F_5 ( V_12 ) ;
F_6 ( V_13 , V_11 ) ;
F_6 ( V_14 , V_10 -> V_15 ) ;
F_6 ( V_16 , ( unsigned long ) V_10 -> V_17 ) ;
F_6 ( V_18 , ( T_1 ) V_10 -> V_19 ) ;
F_6 ( V_20 , ( T_1 ) ( V_10 -> V_19 >> 32 ) ) ;
#ifdef F_3
F_6 ( V_21 , V_10 -> V_22 ) ;
#endif
asm volatile("isync; tlbwe" : : : "memory");
#ifdef F_3
F_6 ( V_21 , 0 ) ;
F_7 () ;
#endif
F_8 ( V_12 ) ;
F_9 ( V_11 , V_10 -> V_22 , V_10 -> V_15 ,
V_10 -> V_17 , V_10 -> V_19 ) ;
}
static T_1 F_10 ( unsigned long V_23 )
{
unsigned long V_12 ;
T_1 V_11 ;
F_5 ( V_12 ) ;
F_6 ( V_24 , 0 ) ;
asm volatile("tlbsx 0, %0" : : "b" (eaddr & ~CONFIG_PAGE_OFFSET));
V_11 = F_11 ( V_13 ) ;
F_8 ( V_12 ) ;
return V_11 ;
}
static inline void F_12 ( struct V_25 * V_26 ,
int V_27 , int V_28 , struct V_9 * V_10 )
{
T_1 V_11 ;
if ( V_27 == 0 ) {
V_11 = F_10 ( V_10 -> V_17 ) ;
F_4 ( V_10 , V_11 ) ;
} else {
F_4 ( V_10 ,
F_13 ( 1 ) |
F_14 ( F_15 ( V_28 ) ) ) ;
}
}
static void F_16 ( struct V_25 * V_26 ,
struct V_9 * V_29 ,
struct V_9 * V_10 ,
int V_30 , int V_28 )
{
int V_31 ;
F_17 () ;
V_31 = F_18 ( & V_26 -> V_32 , V_29 ) ;
V_10 -> V_15 |= F_19 ( V_31 ) ;
F_12 ( V_26 , V_30 , V_28 , V_10 ) ;
F_20 () ;
}
void F_21 ( struct V_33 * V_32 )
{
struct V_25 * V_26 = F_22 ( V_32 ) ;
struct V_9 V_34 ;
T_3 V_35 = ( ( T_3 ) V_32 -> V_36 . V_37 ) & V_38 ;
unsigned int V_31 ;
T_4 V_39 ;
V_39 = ( T_4 ) F_23 ( ( void * ) V_35 ) >> V_40 ;
F_24 ( F_25 ( V_39 ) ) ;
F_17 () ;
V_31 = F_26 ( V_26 , 0 , 0 , 0 , 0 ) ;
V_34 . V_15 = V_41 | V_42 | F_19 ( V_31 ) |
F_27 ( V_43 ) ;
V_34 . V_17 = V_32 -> V_36 . V_44 | V_45 ;
V_34 . V_19 = ( ( V_46 ) V_39 << V_40 ) |
V_47 | V_48 | V_49 | V_50 ;
V_34 . V_22 = 0 ;
F_4 ( & V_34 , F_13 ( 1 ) | F_14 ( V_3 ) ) ;
F_20 () ;
}
void F_28 ( struct V_25 * V_26 , int V_27 ,
int V_51 )
{
struct V_9 * V_29 =
F_29 ( V_26 , V_27 , V_51 ) ;
struct V_52 * V_53 = & V_26 -> V_54 [ V_27 ] [ V_51 ] . V_53 ;
if ( ! ( V_53 -> V_12 & V_55 ) ) {
F_30 ( V_53 -> V_12 & ( V_56 | V_57 ) ,
L_1 , V_58 , V_53 -> V_12 ) ;
F_31 ( V_27 == 1 && V_26 -> V_59 [ V_51 ] ) ;
}
if ( V_27 == 1 && V_53 -> V_12 & V_56 ) {
V_46 V_60 = V_26 -> V_59 [ V_51 ] ;
int V_61 ;
unsigned long V_12 ;
F_5 ( V_12 ) ;
while ( V_60 ) {
V_61 = F_32 ( V_60 & - V_60 ) ;
F_6 ( V_13 ,
F_13 ( 1 ) |
F_14 ( F_15 ( V_61 ) ) ) ;
F_6 ( V_14 , 0 ) ;
asm volatile("tlbwe");
V_26 -> V_62 [ V_61 ] = 0 ;
V_60 &= V_60 - 1 ;
}
F_33 () ;
V_26 -> V_59 [ V_51 ] = 0 ;
V_53 -> V_12 &= ~ ( V_56 | V_55 ) ;
F_8 ( V_12 ) ;
}
if ( V_27 == 1 && V_53 -> V_12 & V_57 ) {
F_34 ( V_26 ) ;
V_53 -> V_12 &= ~ ( V_57 | V_55 ) ;
}
if ( V_53 -> V_12 & V_55 )
F_35 ( V_26 , V_29 ) ;
V_53 -> V_12 = 0 ;
}
static inline int F_36 ( struct V_9 * V_63 )
{
return V_63 -> V_19 & ( V_47 | V_49 ) ;
}
static inline void F_37 ( struct V_52 * V_53 ,
struct V_9 * V_29 ,
T_4 V_39 , unsigned int V_64 )
{
V_53 -> V_39 = V_39 ;
V_53 -> V_12 = V_55 ;
V_53 -> V_12 |= ( V_29 -> V_17 & V_65 ) | V_64 ;
F_38 ( V_39 ) ;
if ( F_36 ( V_29 ) )
F_39 ( V_39 ) ;
}
static inline void F_40 ( struct V_52 * V_53 )
{
if ( V_53 -> V_12 & V_55 ) {
F_41 ( V_53 -> V_39 , V_53 -> V_12 ) ;
V_53 -> V_12 = 0 ;
}
}
static void F_42 ( struct V_25 * V_26 )
{
if ( V_26 -> V_59 )
memset ( V_26 -> V_59 , 0 ,
sizeof( V_46 ) * V_26 -> V_66 [ 1 ] . V_2 ) ;
if ( V_26 -> V_62 )
memset ( V_26 -> V_62 , 0 ,
sizeof( unsigned int ) * V_1 [ 1 ] . V_2 ) ;
}
static void F_43 ( struct V_25 * V_26 )
{
int V_27 ;
int V_67 ;
for ( V_27 = 0 ; V_27 <= 1 ; V_27 ++ ) {
for ( V_67 = 0 ; V_67 < V_26 -> V_66 [ V_27 ] . V_2 ; V_67 ++ ) {
struct V_52 * V_53 =
& V_26 -> V_54 [ V_27 ] [ V_67 ] . V_53 ;
F_40 ( V_53 ) ;
}
}
}
void F_44 ( struct V_33 * V_32 )
{
struct V_25 * V_26 = F_22 ( V_32 ) ;
F_34 ( V_26 ) ;
F_43 ( V_26 ) ;
F_42 ( V_26 ) ;
}
static void F_45 (
struct V_33 * V_32 ,
struct V_9 * V_29 ,
int V_68 , struct V_52 * V_53 , V_46 V_69 ,
struct V_9 * V_10 )
{
T_4 V_39 = V_53 -> V_39 ;
T_1 V_70 = V_32 -> V_36 . V_37 -> V_71 & V_72 ;
F_46 ( ! ( V_53 -> V_12 & V_55 ) ) ;
V_10 -> V_15 = F_27 ( V_68 ) | F_47 ( V_29 ) | V_41 ;
V_10 -> V_17 = ( V_69 & V_73 ) | ( V_53 -> V_12 & V_74 ) ;
V_10 -> V_19 = ( ( V_46 ) V_39 << V_40 ) |
F_2 ( V_29 -> V_19 , V_70 ) ;
#ifdef F_3
V_10 -> V_22 = V_75 | V_32 -> V_76 -> V_36 . V_77 ;
#endif
}
static inline int F_48 ( struct V_25 * V_26 ,
V_46 V_69 , T_5 V_78 , struct V_9 * V_29 ,
int V_27 , struct V_9 * V_10 ,
struct V_52 * V_53 )
{
struct V_79 * V_80 ;
unsigned long V_39 = 0 ;
unsigned long V_81 ;
int V_82 = 0 ;
int V_68 = V_43 ;
int V_83 = 0 ;
unsigned long V_84 ;
struct V_76 * V_76 = V_26 -> V_32 . V_76 ;
unsigned long V_85 = 0 ;
T_6 * V_86 ;
unsigned int V_64 = 0 ;
T_7 * V_87 ;
V_84 = V_76 -> V_88 ;
F_49 () ;
V_80 = F_50 ( V_26 -> V_32 . V_76 , V_78 ) ;
V_81 = F_51 ( V_80 , V_78 ) ;
if ( V_27 == 1 ) {
struct V_89 * V_90 ;
F_52 ( & V_91 -> V_92 -> V_93 ) ;
V_90 = F_53 ( V_91 -> V_92 , V_81 ) ;
if ( V_90 && V_81 >= V_90 -> V_94 &&
( V_90 -> V_95 & V_96 ) ) {
unsigned long V_97 , V_98 ;
unsigned long V_99 , V_100 ;
V_82 = 1 ;
V_97 = V_90 -> V_101 ;
V_98 = V_97 +
( ( V_90 -> V_102 - V_90 -> V_94 ) >> V_40 ) ;
V_39 = V_97 + ( ( V_81 - V_90 -> V_94 ) >> V_40 ) ;
V_99 = V_39 - ( V_78 - V_80 -> V_103 ) ;
V_100 = V_99 + V_80 -> V_104 ;
if ( V_97 < V_99 )
V_97 = V_99 ;
if ( V_98 > V_100 )
V_98 = V_100 ;
V_68 = ( V_29 -> V_15 & V_105 ) >>
V_106 ;
V_68 = F_54 ( V_43 , V_68 & ~ 1 ) ;
for (; V_68 > V_43 ; V_68 -= 2 ) {
unsigned long V_107 , V_108 ;
V_85 = 1 << ( V_68 - 2 ) ;
V_107 = V_78 & ~ ( V_85 - 1 ) ;
V_108 = V_107 + V_85 ;
if ( V_107 + V_39 - V_78 < V_97 )
continue;
if ( V_108 + V_39 - V_78 > V_98 )
continue;
if ( ( V_78 & ( V_85 - 1 ) ) !=
( V_39 & ( V_85 - 1 ) ) )
continue;
V_69 &= ~ ( ( V_85 << V_40 ) - 1 ) ;
V_39 &= ~ ( V_85 - 1 ) ;
break;
}
} else if ( V_90 && V_81 >= V_90 -> V_94 &&
( V_90 -> V_95 & V_109 ) ) {
unsigned long V_110 = F_55 ( V_90 ) ;
V_68 = ( V_29 -> V_15 & V_105 ) >>
V_106 ;
V_68 = F_56 ( F_57 ( V_110 ) - 10 , V_68 ) ;
V_68 = F_54 ( V_43 , V_68 & ~ 1 ) ;
}
F_58 ( & V_91 -> V_92 -> V_93 ) ;
}
if ( F_59 ( ! V_82 ) ) {
V_85 = 1 << ( V_68 + 10 - V_40 ) ;
V_39 = F_60 ( V_80 , V_78 ) ;
if ( F_61 ( V_39 ) ) {
if ( F_62 () )
F_63 ( L_2 ,
V_58 , ( long ) V_78 ) ;
return - V_111 ;
}
V_39 &= ~ ( V_85 - 1 ) ;
V_69 &= ~ ( ( V_85 << V_40 ) - 1 ) ;
}
F_64 ( & V_76 -> V_112 ) ;
if ( F_65 ( V_76 , V_84 ) ) {
V_83 = - V_113 ;
goto V_114;
}
V_87 = V_26 -> V_32 . V_36 . V_87 ;
V_86 = F_66 ( V_87 , V_81 , & V_85 ) ;
if ( F_67 ( * V_86 ) )
V_64 = ( * V_86 >> V_115 ) & V_116 ;
else {
if ( F_62 () )
F_63 ( L_3 ,
V_58 , ( long ) V_78 , V_39 ) ;
return - V_111 ;
}
F_37 ( V_53 , V_29 , V_39 , V_64 ) ;
F_45 ( & V_26 -> V_32 , V_29 , V_68 ,
V_53 , V_69 , V_10 ) ;
F_68 ( V_39 ) ;
V_114:
F_69 ( & V_76 -> V_112 ) ;
F_70 ( V_39 ) ;
return V_83 ;
}
static int F_71 ( struct V_25 * V_26 , int V_51 ,
struct V_9 * V_10 )
{
struct V_9 * V_29 ;
struct V_52 * V_53 ;
int V_30 = 0 ;
int V_28 = 0 ;
int V_117 ;
V_29 = F_29 ( V_26 , 0 , V_51 ) ;
V_53 = & V_26 -> V_54 [ 0 ] [ V_51 ] . V_53 ;
V_117 = F_48 ( V_26 , F_72 ( V_29 ) ,
F_73 ( V_29 ) >> V_40 ,
V_29 , 0 , V_10 , V_53 ) ;
if ( V_117 )
return V_117 ;
F_16 ( V_26 , V_29 , V_10 , V_30 , V_28 ) ;
return 0 ;
}
static int F_74 ( struct V_25 * V_26 ,
struct V_52 * V_53 ,
int V_51 )
{
unsigned int V_28 = V_26 -> V_118 ++ ;
if ( F_75 ( V_26 -> V_118 >= F_1 () ) )
V_26 -> V_118 = 0 ;
if ( V_26 -> V_62 [ V_28 ] ) {
unsigned int V_119 = V_26 -> V_62 [ V_28 ] - 1 ;
V_26 -> V_59 [ V_119 ] &= ~ ( 1ULL << V_28 ) ;
}
V_26 -> V_54 [ 1 ] [ V_51 ] . V_53 . V_12 |= V_56 ;
V_26 -> V_59 [ V_51 ] |= ( V_46 ) 1 << V_28 ;
V_26 -> V_62 [ V_28 ] = V_51 + 1 ;
F_31 ( ! ( V_53 -> V_12 & V_55 ) ) ;
return V_28 ;
}
static int F_76 ( struct V_25 * V_26 ,
V_46 V_69 , T_5 V_78 , struct V_9 * V_29 ,
struct V_9 * V_10 , int V_51 )
{
struct V_52 * V_53 = & V_26 -> V_54 [ 1 ] [ V_51 ] . V_53 ;
int V_28 ;
int V_117 ;
V_117 = F_48 ( V_26 , V_69 , V_78 , V_29 , 1 , V_10 ,
V_53 ) ;
if ( V_117 )
return V_117 ;
if ( F_77 ( V_10 ) == V_43 ) {
V_26 -> V_54 [ 1 ] [ V_51 ] . V_53 . V_12 |= V_57 ;
F_16 ( V_26 , V_29 , V_10 , 0 , 0 ) ;
return 0 ;
}
V_28 = F_74 ( V_26 , V_53 , V_51 ) ;
F_16 ( V_26 , V_29 , V_10 , 1 , V_28 ) ;
return 0 ;
}
void F_78 ( struct V_33 * V_32 , V_46 V_23 , T_8 V_120 ,
unsigned int V_121 )
{
struct V_25 * V_26 = F_22 ( V_32 ) ;
struct V_122 * V_123 ;
struct V_9 * V_29 , V_10 ;
int V_27 = F_79 ( V_121 ) ;
int V_51 = F_80 ( V_121 ) ;
V_29 = F_29 ( V_26 , V_27 , V_51 ) ;
switch ( V_27 ) {
case 0 :
V_123 = & V_26 -> V_54 [ V_27 ] [ V_51 ] ;
if ( ! ( V_123 -> V_53 . V_12 & V_55 ) ) {
F_71 ( V_26 , V_51 , & V_10 ) ;
} else {
F_45 ( V_32 , V_29 , V_43 ,
& V_123 -> V_53 , V_23 , & V_10 ) ;
F_16 ( V_26 , V_29 , & V_10 , 0 , 0 ) ;
}
break;
case 1 : {
T_5 V_78 = V_120 >> V_40 ;
F_76 ( V_26 , V_23 , V_78 , V_29 , & V_10 ,
V_51 ) ;
break;
}
default:
F_81 () ;
break;
}
}
int F_82 ( struct V_76 * V_76 , unsigned long V_81 )
{
F_83 ( V_81 ) ;
F_84 ( V_76 ) ;
return 0 ;
}
int F_85 ( struct V_76 * V_76 , unsigned long V_97 , unsigned long V_98 )
{
F_82 ( V_76 , V_97 ) ;
return 0 ;
}
int F_86 ( struct V_76 * V_76 , unsigned long V_81 )
{
return 0 ;
}
int F_87 ( struct V_76 * V_76 , unsigned long V_81 )
{
return 0 ;
}
void F_88 ( struct V_76 * V_76 , unsigned long V_81 , T_6 V_124 )
{
F_82 ( V_76 , V_81 ) ;
}
int F_89 ( struct V_25 * V_26 )
{
V_1 [ 0 ] . V_2 = F_11 ( V_125 ) & V_126 ;
V_1 [ 1 ] . V_2 = F_11 ( V_127 ) & V_126 ;
if ( V_1 [ 0 ] . V_2 == 0 ||
V_1 [ 1 ] . V_2 == 0 ) {
F_63 ( L_4 , V_58 ) ;
return - V_128 ;
}
V_1 [ 0 ] . V_129 = ( F_11 ( V_125 ) & V_130 ) >>
V_131 ;
V_1 [ 1 ] . V_129 = V_1 [ 1 ] . V_2 ;
if ( ! F_90 ( V_1 [ 0 ] . V_2 ) ||
! F_90 ( V_1 [ 0 ] . V_129 ) ||
V_1 [ 0 ] . V_2 < V_1 [ 0 ] . V_129 ||
V_1 [ 0 ] . V_129 == 0 ) {
F_63 ( L_5 ,
V_58 , V_1 [ 0 ] . V_2 ,
V_1 [ 0 ] . V_129 ) ;
return - V_128 ;
}
V_1 [ 0 ] . V_132 =
V_1 [ 0 ] . V_2 / V_1 [ 0 ] . V_129 ;
V_1 [ 1 ] . V_132 = 1 ;
V_26 -> V_62 = F_91 ( sizeof( unsigned int ) *
V_1 [ 1 ] . V_2 ,
V_133 ) ;
if ( ! V_26 -> V_62 )
return - V_111 ;
return 0 ;
}
void F_92 ( struct V_25 * V_26 )
{
F_93 ( V_26 -> V_62 ) ;
}
