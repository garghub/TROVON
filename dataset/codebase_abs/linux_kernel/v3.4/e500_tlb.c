static struct V_1 * F_1 (
struct V_2 * V_3 , int V_4 , int V_5 )
{
int V_6 = V_3 -> V_7 [ V_4 ] ;
return & V_3 -> V_8 [ V_6 + V_5 ] ;
}
static inline int F_2 ( struct V_9 * V_5 )
{
unsigned long V_10 ;
int V_11 = - 1 ;
V_10 = ++ ( F_3 ( V_12 ) ) ;
if ( V_10 < V_13 ) {
F_3 ( V_14 ) . V_5 [ V_10 ] = V_5 ;
V_5 -> V_15 = V_10 ;
V_5 -> V_16 = & F_3 ( V_14 ) . V_5 [ V_10 ] ;
V_11 = V_10 ;
}
F_4 ( V_10 > V_13 ) ;
return V_11 ;
}
static inline int F_5 ( struct V_9 * V_5 )
{
if ( V_5 && V_5 -> V_15 != 0 &&
F_3 ( V_14 ) . V_5 [ V_5 -> V_15 ] == V_5 &&
V_5 -> V_16 == & F_3 ( V_14 ) . V_5 [ V_5 -> V_15 ] )
return V_5 -> V_15 ;
return - 1 ;
}
static inline void F_6 ( void )
{
F_3 ( V_12 ) = 0 ;
memset ( & F_3 ( V_14 ) , 0 , sizeof( F_3 ( V_14 ) ) ) ;
}
static void * F_7 ( struct V_2 * V_3 )
{
V_3 -> V_17 = F_8 ( sizeof( struct V_18 ) , V_19 ) ;
return V_3 -> V_17 ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_10 ( V_3 -> V_17 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
memset ( V_3 -> V_17 , 0 , sizeof( struct V_18 ) ) ;
F_12 ( V_3 ) ;
}
static inline void F_13 (
struct V_2 * V_3 ,
int V_20 , int V_21 , int V_22 )
{
struct V_18 * V_17 = V_3 -> V_17 ;
F_14 ( V_20 >= 2 ) ;
F_14 ( V_21 >= V_13 ) ;
F_14 ( V_22 >= 2 ) ;
V_17 -> V_9 [ V_20 ] [ V_21 ] [ V_22 ] . V_15 = 0 ;
V_17 -> V_9 [ V_20 ] [ V_21 ] [ V_22 ] . V_16 = NULL ;
F_12 ( V_3 ) ;
}
static unsigned int F_15 ( struct V_2 * V_3 ,
unsigned int V_20 , unsigned int V_23 ,
unsigned int V_22 , int V_24 )
{
struct V_18 * V_17 = V_3 -> V_17 ;
int V_10 ;
F_14 ( V_20 >= 2 ) ;
F_14 ( V_23 >= V_13 ) ;
F_14 ( V_22 >= 2 ) ;
V_10 = F_5 ( & V_17 -> V_9 [ V_20 ] [ V_23 ] [ V_22 ] ) ;
while ( V_10 <= 0 ) {
V_10 = F_2 ( & V_17 -> V_9 [ V_20 ] [ V_23 ] [ V_22 ] ) ;
if ( V_10 <= 0 ) {
F_16 () ;
F_6 () ;
}
if ( ! V_24 )
F_12 ( V_3 ) ;
}
return V_10 ;
}
void F_12 ( struct V_2 * V_3 )
{
F_17 () ;
V_3 -> V_25 . V_26 . V_27 = F_15 ( V_3 ,
F_18 ( & V_3 -> V_25 ) ,
F_19 ( & V_3 -> V_25 ) ,
F_20 ( & V_3 -> V_25 ) , 1 ) ;
V_3 -> V_25 . V_26 . V_28 = F_15 ( V_3 ,
F_18 ( & V_3 -> V_25 ) , 0 ,
F_20 ( & V_3 -> V_25 ) , 1 ) ;
F_21 () ;
}
static inline unsigned int F_22 (
struct V_2 * V_3 )
{
unsigned int V_29 ;
V_29 = V_3 -> V_30 [ 0 ] ++ ;
if ( F_23 ( V_3 -> V_30 [ 0 ] >= V_3 -> V_31 [ 0 ] . V_32 ) )
V_3 -> V_30 [ 0 ] = 0 ;
return V_29 ;
}
static inline unsigned int F_24 ( void )
{
return V_33 [ 1 ] . V_34 - V_35 - 1 ;
}
static inline int F_25 ( struct V_1 * V_36 )
{
return V_36 -> V_37 & ( V_38 | V_39 ) ;
}
static inline T_1 F_26 ( T_1 V_40 , int V_41 )
{
V_40 &= V_42 ;
if ( ! V_41 ) {
V_40 &= ~ V_43 ;
V_40 |= ( V_40 & V_44 ) << 1 ;
}
return V_40 | V_44 ;
}
static inline T_1 F_27 ( T_1 V_45 , int V_41 )
{
#ifdef F_28
return ( V_45 & V_46 ) | V_47 ;
#else
return V_45 & V_46 ;
#endif
}
static inline void F_29 ( struct V_1 * V_48 ,
T_2 V_49 )
{
unsigned long V_50 ;
F_30 ( V_50 ) ;
F_31 ( V_51 , V_49 ) ;
F_31 ( V_52 , V_48 -> V_53 ) ;
F_31 ( V_54 , ( unsigned long ) V_48 -> V_45 ) ;
F_31 ( V_55 , ( T_1 ) V_48 -> V_37 ) ;
F_31 ( V_56 , ( T_1 ) ( V_48 -> V_37 >> 32 ) ) ;
asm volatile("isync; tlbwe" : : : "memory");
F_32 ( V_50 ) ;
F_33 ( V_49 , V_48 -> V_57 , V_48 -> V_53 ,
V_48 -> V_45 , V_48 -> V_37 ) ;
}
static T_1 F_34 ( unsigned long V_58 )
{
unsigned long V_50 ;
T_1 V_49 ;
F_30 ( V_50 ) ;
F_31 ( V_59 , 0 ) ;
asm volatile("tlbsx 0, %0" : : "b" (eaddr & ~CONFIG_PAGE_OFFSET));
V_49 = F_35 ( V_51 ) ;
F_32 ( V_50 ) ;
return V_49 ;
}
static inline void F_36 ( struct V_2 * V_3 ,
int V_4 , int V_60 , struct V_1 * V_48 )
{
T_1 V_49 ;
if ( V_4 == 0 ) {
V_49 = F_34 ( V_48 -> V_45 ) ;
F_29 ( V_48 , V_49 ) ;
} else {
F_29 ( V_48 ,
F_37 ( 1 ) |
F_38 ( F_39 ( V_60 ) ) ) ;
}
}
void F_40 ( struct V_61 * V_25 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
struct V_1 V_62 ;
T_3 V_63 = ( ( T_3 ) V_25 -> V_26 . V_64 ) & V_65 ;
unsigned int V_66 ;
T_4 V_67 ;
V_67 = ( T_4 ) F_42 ( ( void * ) V_63 ) >> V_68 ;
F_43 ( F_44 ( V_67 ) ) ;
F_17 () ;
V_66 = F_15 ( V_3 , 0 , 0 , 0 , 0 ) ;
V_62 . V_53 = V_69 | V_70 | F_45 ( V_66 ) |
F_46 ( V_71 ) ;
V_62 . V_45 = V_25 -> V_26 . V_72 | V_47 ;
V_62 . V_37 = ( ( V_73 ) V_67 << V_68 ) |
V_38 | V_74 | V_39 | V_75 ;
V_62 . V_57 = 0 ;
F_29 ( & V_62 , F_37 ( 1 ) | F_38 ( V_35 ) ) ;
F_21 () ;
}
void F_47 ( struct V_61 * V_25 , int V_76 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
F_12 ( V_3 ) ;
}
void F_48 ( struct V_61 * V_25 )
{
}
static void F_49 ( struct V_2 * V_3 ,
int V_4 , int V_77 )
{
struct V_1 * V_78 =
F_1 ( V_3 , V_4 , V_77 ) ;
struct V_18 * V_17 = V_3 -> V_17 ;
unsigned int V_22 , V_79 , V_80 , V_21 ;
T_1 V_15 , V_58 ;
unsigned long V_50 ;
V_80 = F_50 ( V_78 ) ;
V_79 = F_51 ( V_78 ) ;
F_17 () ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
if ( V_4 == 1 ||
( V_21 = F_5 ( & V_17 -> V_9 [ V_80 ] [ V_79 ] [ V_22 ] ) ) <= 0 ) {
F_13 ( V_3 , V_80 , V_79 , V_22 ) ;
continue;
}
V_15 = ( V_21 << V_81 ) | V_82 ;
V_58 = F_52 ( V_78 ) ;
F_30 ( V_50 ) ;
F_31 ( V_59 , V_15 ) ;
asm volatile("tlbsx 0, %[eaddr]" : : [eaddr] "r" (eaddr));
V_15 = F_35 ( V_52 ) ;
if ( V_15 & V_69 ) {
F_31 ( V_52 , V_15 & ~ V_69 ) ;
asm volatile("tlbwe");
}
F_32 ( V_50 ) ;
}
F_21 () ;
}
static int F_53 ( T_5 V_83 , int V_84 , int V_32 )
{
int V_85 ;
V_85 = ( V_83 >> V_68 ) & ( V_84 - 1 ) ;
V_85 *= V_32 ;
return V_85 ;
}
static int F_54 ( struct V_2 * V_3 , T_5 V_83 )
{
return F_53 ( V_83 , V_3 -> V_31 [ 0 ] . V_84 ,
V_3 -> V_31 [ 0 ] . V_32 ) ;
}
static unsigned int F_55 ( struct V_61 * V_25 , int V_4 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
int V_77 = F_56 ( V_25 ) ;
if ( V_4 == 0 ) {
V_77 &= V_3 -> V_31 [ 0 ] . V_32 - 1 ;
V_77 += F_54 ( V_3 , V_25 -> V_26 . V_64 -> V_45 ) ;
} else {
V_77 &= V_3 -> V_31 [ V_4 ] . V_34 - 1 ;
}
return V_77 ;
}
static int F_57 ( struct V_2 * V_3 ,
T_5 V_58 , int V_4 , unsigned int V_21 , int V_20 )
{
int V_86 = V_3 -> V_31 [ V_4 ] . V_34 ;
unsigned int V_85 , V_6 ;
int V_87 ;
if ( V_4 == 0 ) {
V_85 = F_54 ( V_3 , V_58 ) ;
V_86 = V_3 -> V_31 [ 0 ] . V_32 ;
} else {
V_85 = 0 ;
}
V_6 = V_3 -> V_7 [ V_4 ] ;
for ( V_87 = 0 ; V_87 < V_86 ; V_87 ++ ) {
struct V_1 * V_36 =
& V_3 -> V_8 [ V_6 + V_85 + V_87 ] ;
unsigned int V_79 ;
if ( V_58 < F_52 ( V_36 ) )
continue;
if ( V_58 > F_58 ( V_36 ) )
continue;
V_79 = F_51 ( V_36 ) ;
if ( V_79 && ( V_79 != V_21 ) )
continue;
if ( ! F_59 ( V_36 ) )
continue;
if ( F_50 ( V_36 ) != V_20 && V_20 != - 1 )
continue;
return V_85 + V_87 ;
}
return - 1 ;
}
static inline void F_60 ( struct V_88 * V_89 ,
struct V_1 * V_78 ,
T_4 V_67 )
{
V_89 -> V_67 = V_67 ;
V_89 -> V_50 = V_90 ;
if ( F_25 ( V_78 ) )
V_89 -> V_50 |= V_91 ;
}
static inline void F_61 ( struct V_88 * V_89 )
{
if ( V_89 -> V_50 & V_90 ) {
if ( V_89 -> V_50 & V_91 )
F_62 ( V_89 -> V_67 ) ;
else
F_63 ( V_89 -> V_67 ) ;
V_89 -> V_50 = 0 ;
}
}
static void F_64 ( struct V_2 * V_3 )
{
int V_4 = 0 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_3 -> V_31 [ V_4 ] . V_34 ; V_87 ++ ) {
struct V_88 * V_89 =
& V_3 -> V_92 [ V_4 ] [ V_87 ] . V_89 ;
F_61 ( V_89 ) ;
}
}
static void F_65 ( struct V_2 * V_3 )
{
int V_93 = 1 ;
int V_87 ;
F_11 ( V_3 ) ;
for ( V_87 = 0 ; V_87 < V_33 [ V_93 ] . V_34 ; V_87 ++ ) {
struct V_88 * V_89 =
& V_3 -> V_94 [ V_93 ] [ V_87 ] ;
F_61 ( V_89 ) ;
}
F_64 ( V_3 ) ;
}
static inline void F_66 ( struct V_61 * V_25 ,
unsigned int V_58 , int V_20 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
unsigned int V_29 , V_95 , V_96 ;
int V_4 ;
V_4 = ( V_25 -> V_26 . V_64 -> V_97 >> 28 ) & 0x1 ;
V_29 = ( V_4 == 0 ) ? F_22 ( V_3 ) : 0 ;
V_95 = ( V_25 -> V_26 . V_64 -> V_97 >> 16 ) & 0xf ;
V_96 = ( V_25 -> V_26 . V_64 -> V_97 >> 7 ) & 0x1f ;
V_25 -> V_26 . V_64 -> V_49 = F_37 ( V_4 ) | F_38 ( V_29 )
| F_67 ( V_3 -> V_30 [ V_4 ] ) ;
V_25 -> V_26 . V_64 -> V_53 = V_69 | ( V_20 ? V_70 : 0 )
| F_45 ( V_3 -> V_21 [ V_95 ] )
| F_46 ( V_96 ) ;
V_25 -> V_26 . V_64 -> V_45 = ( V_58 & V_98 )
| ( V_25 -> V_26 . V_64 -> V_97 & V_46 ) ;
V_25 -> V_26 . V_64 -> V_37 &= V_99 | V_100 | V_101 | V_102 ;
V_25 -> V_26 . V_64 -> V_103 = ( V_25 -> V_26 . V_64 -> V_103 & V_104 )
| ( F_19 ( V_25 ) << 16 )
| ( V_20 ? V_82 : 0 ) ;
}
static inline void F_68 (
struct V_2 * V_3 ,
struct V_1 * V_78 ,
int V_105 , struct V_88 * V_89 , V_73 V_106 ,
struct V_1 * V_48 )
{
T_4 V_67 = V_89 -> V_67 ;
F_14 ( ! ( V_89 -> V_50 & V_90 ) ) ;
V_48 -> V_53 = F_46 ( V_105 ) | V_70 | V_69 ;
V_48 -> V_45 = ( V_106 & V_98 )
| F_27 ( V_78 -> V_45 ,
V_3 -> V_25 . V_26 . V_64 -> V_107 & V_108 ) ;
V_48 -> V_37 = ( ( V_73 ) V_67 << V_68 )
| F_26 ( V_78 -> V_37 ,
V_3 -> V_25 . V_26 . V_64 -> V_107 & V_108 ) ;
}
static inline void F_69 ( struct V_2 * V_3 ,
V_73 V_106 , T_6 V_109 , struct V_1 * V_78 ,
int V_4 , struct V_1 * V_48 ,
struct V_88 * V_89 )
{
struct V_110 * V_111 ;
unsigned long V_67 , V_112 ;
int V_113 = 0 ;
int V_105 = V_71 ;
V_111 = F_70 ( V_3 -> V_25 . V_114 , V_109 ) ;
V_112 = F_71 ( V_111 , V_109 ) ;
if ( V_4 == 1 ) {
struct V_115 * V_116 ;
F_72 ( & V_117 -> V_118 -> V_119 ) ;
V_116 = F_73 ( V_117 -> V_118 , V_112 ) ;
if ( V_116 && V_112 >= V_116 -> V_120 &&
( V_116 -> V_121 & V_122 ) ) {
unsigned long V_123 , V_124 ;
unsigned long V_125 , V_126 ;
V_113 = 1 ;
V_123 = V_116 -> V_127 ;
V_124 = V_123 +
( ( V_116 -> V_128 - V_116 -> V_120 ) >> V_68 ) ;
V_67 = V_123 + ( ( V_112 - V_116 -> V_120 ) >> V_68 ) ;
V_125 = V_67 - ( V_109 - V_111 -> V_129 ) ;
V_126 = V_125 + V_111 -> V_130 ;
if ( V_123 < V_125 )
V_123 = V_125 ;
if ( V_124 > V_126 )
V_124 = V_126 ;
V_105 = ( V_78 -> V_53 & V_131 ) >>
V_132 ;
V_105 = F_74 ( V_71 , V_105 & ~ 1 ) ;
for (; V_105 > V_71 ; V_105 -= 2 ) {
unsigned long V_133 , V_134 , V_135 ;
V_135 = 1 << ( V_105 - 2 ) ;
V_133 = V_109 & ~ ( V_135 - 1 ) ;
V_134 = V_133 + V_135 ;
if ( V_133 + V_67 - V_109 < V_123 )
continue;
if ( V_134 + V_67 - V_109 > V_124 )
continue;
if ( ( V_109 & ( V_135 - 1 ) ) !=
( V_67 & ( V_135 - 1 ) ) )
continue;
V_106 &= ~ ( ( V_135 << V_68 ) - 1 ) ;
V_67 &= ~ ( V_135 - 1 ) ;
break;
}
} else if ( V_116 && V_112 >= V_116 -> V_120 &&
( V_116 -> V_121 & V_136 ) ) {
unsigned long V_137 = F_75 ( V_116 ) ;
V_105 = ( V_78 -> V_53 & V_131 ) >>
V_132 ;
V_105 = F_76 ( F_77 ( V_137 ) - 10 , V_105 ) ;
V_105 = F_74 ( V_71 , V_105 & ~ 1 ) ;
}
F_78 ( & V_117 -> V_118 -> V_119 ) ;
}
if ( F_79 ( ! V_113 ) ) {
unsigned long V_135 = 1 << ( V_105 + 10 - V_68 ) ;
V_67 = F_80 ( V_3 -> V_25 . V_114 , V_111 , V_109 ) ;
if ( F_81 ( V_67 ) ) {
F_82 ( V_138 L_1 ,
( long ) V_109 ) ;
F_63 ( V_67 ) ;
return;
}
V_67 &= ~ ( V_135 - 1 ) ;
V_106 &= ~ ( ( V_135 << V_68 ) - 1 ) ;
}
F_61 ( V_89 ) ;
F_60 ( V_89 , V_78 , V_67 ) ;
F_68 ( V_3 , V_78 , V_105 , V_89 , V_106 , V_48 ) ;
}
static void F_83 ( struct V_2 * V_3 ,
int V_77 ,
struct V_1 * V_48 )
{
struct V_1 * V_78 ;
struct V_88 * V_89 ;
V_78 = F_1 ( V_3 , 0 , V_77 ) ;
V_89 = & V_3 -> V_92 [ 0 ] [ V_77 ] . V_89 ;
F_69 ( V_3 , F_52 ( V_78 ) ,
F_84 ( V_78 ) >> V_68 ,
V_78 , 0 , V_48 , V_89 ) ;
}
static int F_85 ( struct V_2 * V_3 ,
V_73 V_106 , T_6 V_109 , struct V_1 * V_78 ,
struct V_1 * V_48 )
{
struct V_88 * V_89 ;
unsigned int V_29 ;
V_29 = V_3 -> V_139 ++ ;
if ( F_23 ( V_3 -> V_139 >= F_24 () ) )
V_3 -> V_139 = 0 ;
V_89 = & V_3 -> V_94 [ 1 ] [ V_29 ] ;
F_69 ( V_3 , V_106 , V_109 , V_78 , 1 , V_48 , V_89 ) ;
return V_29 ;
}
void F_86 ( struct V_61 * V_25 , T_1 V_140 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
F_12 ( V_3 ) ;
}
static inline int F_87 (
struct V_2 * V_3 ,
int V_4 , int V_77 )
{
struct V_1 * V_78 =
F_1 ( V_3 , V_4 , V_77 ) ;
if ( F_23 ( F_88 ( V_78 ) ) )
return - 1 ;
V_78 -> V_53 = 0 ;
return 0 ;
}
int F_89 ( struct V_2 * V_3 , T_3 V_141 )
{
int V_77 ;
if ( V_141 & V_142 )
for ( V_77 = 0 ; V_77 < V_3 -> V_31 [ 0 ] . V_34 ; V_77 ++ )
F_87 ( V_3 , 0 , V_77 ) ;
if ( V_141 & V_143 )
for ( V_77 = 0 ; V_77 < V_3 -> V_31 [ 1 ] . V_34 ; V_77 ++ )
F_87 ( V_3 , 1 , V_77 ) ;
F_11 ( V_3 ) ;
return V_144 ;
}
int F_90 ( struct V_61 * V_25 , int V_145 , int V_146 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
unsigned int V_147 ;
int V_77 , V_4 ;
T_5 V_148 ;
V_148 = ( ( V_145 ) ? F_91 ( V_25 , V_145 ) : 0 ) + F_91 ( V_25 , V_146 ) ;
V_147 = ( V_148 >> 2 ) & 0x1 ;
V_4 = ( V_148 >> 3 ) & 0x1 ;
if ( V_147 ) {
for ( V_77 = 0 ; V_77 < V_3 -> V_31 [ V_4 ] . V_34 ;
V_77 ++ )
F_87 ( V_3 , V_4 , V_77 ) ;
} else {
V_148 &= 0xfffff000 ;
V_77 = F_57 ( V_3 , V_148 , V_4 ,
F_19 ( V_25 ) , - 1 ) ;
if ( V_77 >= 0 )
F_87 ( V_3 , V_4 , V_77 ) ;
}
F_11 ( V_3 ) ;
return V_144 ;
}
int F_92 ( struct V_61 * V_25 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
int V_4 , V_77 ;
struct V_1 * V_78 ;
V_4 = F_93 ( V_25 ) ;
V_77 = F_55 ( V_25 , V_4 ) ;
V_78 = F_1 ( V_3 , V_4 , V_77 ) ;
V_25 -> V_26 . V_64 -> V_49 &= ~ F_67 ( ~ 0 ) ;
V_25 -> V_26 . V_64 -> V_49 |= F_67 ( V_3 -> V_30 [ V_4 ] ) ;
V_25 -> V_26 . V_64 -> V_53 = V_78 -> V_53 ;
V_25 -> V_26 . V_64 -> V_45 = V_78 -> V_45 ;
V_25 -> V_26 . V_64 -> V_37 = V_78 -> V_37 ;
return V_144 ;
}
int F_94 ( struct V_61 * V_25 , int V_146 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
int V_20 = ! ! F_95 ( V_25 ) ;
unsigned int V_21 = F_96 ( V_25 ) ;
int V_77 , V_4 ;
struct V_1 * V_78 = NULL ;
T_5 V_148 ;
V_148 = F_91 ( V_25 , V_146 ) ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
V_77 = F_57 ( V_3 , V_148 , V_4 , V_21 , V_20 ) ;
if ( V_77 >= 0 ) {
V_78 = F_1 ( V_3 , V_4 , V_77 ) ;
break;
}
}
if ( V_78 ) {
V_77 &= V_3 -> V_31 [ V_4 ] . V_32 - 1 ;
V_25 -> V_26 . V_64 -> V_49 = F_37 ( V_4 ) | F_38 ( V_77 )
| F_67 ( V_3 -> V_30 [ V_4 ] ) ;
V_25 -> V_26 . V_64 -> V_53 = V_78 -> V_53 ;
V_25 -> V_26 . V_64 -> V_45 = V_78 -> V_45 ;
V_25 -> V_26 . V_64 -> V_37 = V_78 -> V_37 ;
} else {
int V_29 ;
V_4 = V_25 -> V_26 . V_64 -> V_97 >> 28 & 0x1 ;
V_29 = ( V_4 == 0 ) ? F_22 ( V_3 ) : 0 ;
V_25 -> V_26 . V_64 -> V_49 = F_37 ( V_4 )
| F_38 ( V_29 )
| F_67 ( V_3 -> V_30 [ V_4 ] ) ;
V_25 -> V_26 . V_64 -> V_53 =
( V_25 -> V_26 . V_64 -> V_103 & V_149 )
| ( V_25 -> V_26 . V_64 -> V_103 & ( V_82 ? V_70 : 0 ) )
| ( V_25 -> V_26 . V_64 -> V_97 & F_97 ( ~ 0 ) ) ;
V_25 -> V_26 . V_64 -> V_45 &= V_98 ;
V_25 -> V_26 . V_64 -> V_45 |= V_25 -> V_26 . V_64 -> V_97 &
V_46 ;
V_25 -> V_26 . V_64 -> V_37 &= V_99 | V_100 |
V_101 | V_102 ;
}
F_98 ( V_25 , V_150 ) ;
return V_144 ;
}
static void F_99 ( struct V_2 * V_3 ,
struct V_1 * V_78 ,
struct V_1 * V_48 ,
int V_93 , int V_60 )
{
int V_66 ;
F_17 () ;
V_66 = F_15 ( V_3 , F_50 ( V_78 ) ,
F_51 ( V_78 ) ,
F_20 ( & V_3 -> V_25 ) , 0 ) ;
V_48 -> V_53 |= F_45 ( V_66 ) ;
F_36 ( V_3 , V_93 , V_60 , V_48 ) ;
F_21 () ;
}
int F_100 ( struct V_61 * V_25 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
struct V_1 * V_78 ;
int V_4 , V_77 ;
V_4 = F_93 ( V_25 ) ;
V_77 = F_55 ( V_25 , V_4 ) ;
V_78 = F_1 ( V_3 , V_4 , V_77 ) ;
if ( F_59 ( V_78 ) )
F_49 ( V_3 , V_4 , V_77 ) ;
V_78 -> V_53 = V_25 -> V_26 . V_64 -> V_53 ;
V_78 -> V_45 = V_25 -> V_26 . V_64 -> V_45 ;
V_78 -> V_37 = V_25 -> V_26 . V_64 -> V_37 ;
F_101 ( V_25 -> V_26 . V_64 -> V_49 , V_78 -> V_53 ,
V_78 -> V_45 , V_78 -> V_37 ) ;
if ( F_102 ( V_25 , V_78 ) ) {
struct V_1 V_48 ;
int V_93 , V_60 ;
V_73 V_58 ;
V_73 V_151 ;
switch ( V_4 ) {
case 0 :
V_78 -> V_53 &= ~ F_46 ( ~ 0 ) ;
V_78 -> V_53 |= F_46 ( V_71 ) ;
V_93 = 0 ;
F_83 ( V_3 , V_77 , & V_48 ) ;
V_60 = 0 ;
break;
case 1 :
V_58 = F_52 ( V_78 ) ;
V_151 = F_84 ( V_78 ) ;
V_93 = 1 ;
V_60 = F_85 ( V_3 , V_58 ,
V_151 >> V_68 , V_78 , & V_48 ) ;
break;
default:
F_103 () ;
}
F_99 ( V_3 , V_78 , & V_48 , V_93 , V_60 ) ;
}
F_98 ( V_25 , V_152 ) ;
return V_144 ;
}
int F_104 ( struct V_61 * V_25 , T_5 V_58 )
{
unsigned int V_20 = ! ! ( V_25 -> V_26 . V_64 -> V_107 & V_153 ) ;
return F_105 ( V_25 , V_58 , F_19 ( V_25 ) , V_20 ) ;
}
int F_106 ( struct V_61 * V_25 , T_5 V_58 )
{
unsigned int V_20 = ! ! ( V_25 -> V_26 . V_64 -> V_107 & V_154 ) ;
return F_105 ( V_25 , V_58 , F_19 ( V_25 ) , V_20 ) ;
}
void F_107 ( struct V_61 * V_25 )
{
unsigned int V_20 = ! ! ( V_25 -> V_26 . V_64 -> V_107 & V_153 ) ;
F_66 ( V_25 , V_25 -> V_26 . V_155 , V_20 ) ;
}
void F_108 ( struct V_61 * V_25 )
{
unsigned int V_20 = ! ! ( V_25 -> V_26 . V_64 -> V_107 & V_154 ) ;
F_66 ( V_25 , V_25 -> V_26 . V_156 , V_20 ) ;
}
T_7 F_109 ( struct V_61 * V_25 , unsigned int V_157 ,
T_5 V_58 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
struct V_1 * V_78 ;
V_73 V_158 ;
V_78 = F_1 ( V_3 , F_110 ( V_157 ) , F_111 ( V_157 ) ) ;
V_158 = F_112 ( V_78 ) - 1 ;
return F_84 ( V_78 ) | ( V_58 & V_158 ) ;
}
void F_113 ( struct V_61 * V_25 )
{
}
void F_114 ( struct V_61 * V_25 , V_73 V_58 , T_7 V_159 ,
unsigned int V_157 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
struct V_160 * V_161 ;
struct V_1 * V_78 , V_48 ;
int V_4 = F_110 ( V_157 ) ;
int V_77 = F_111 ( V_157 ) ;
int V_93 , V_60 ;
V_78 = F_1 ( V_3 , V_4 , V_77 ) ;
switch ( V_4 ) {
case 0 :
V_93 = 0 ;
V_60 = 0 ;
V_161 = & V_3 -> V_92 [ V_4 ] [ V_77 ] ;
F_68 ( V_3 , V_78 , V_71 ,
& V_161 -> V_89 , V_58 , & V_48 ) ;
break;
case 1 : {
T_6 V_109 = V_159 >> V_68 ;
V_93 = 1 ;
V_60 = F_85 ( V_3 , V_58 , V_109 ,
V_78 , & V_48 ) ;
break;
}
default:
F_103 () ;
break;
}
F_99 ( V_3 , V_78 , & V_48 , V_93 , V_60 ) ;
}
int F_105 ( struct V_61 * V_25 ,
T_5 V_58 , unsigned int V_21 , int V_20 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
int V_77 , V_4 ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
V_77 = F_57 ( V_3 , V_58 , V_4 , V_21 , V_20 ) ;
if ( V_77 >= 0 )
return F_115 ( V_4 , V_77 ) ;
}
return - 1 ;
}
void F_116 ( struct V_61 * V_25 , T_1 V_21 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
if ( V_25 -> V_26 . V_21 != V_21 ) {
V_3 -> V_21 [ 0 ] = V_25 -> V_26 . V_21 = V_21 ;
F_12 ( V_3 ) ;
}
}
void F_117 ( struct V_2 * V_3 )
{
struct V_1 * V_36 ;
V_36 = F_1 ( V_3 , 1 , 0 ) ;
V_36 -> V_53 = V_69 | F_46 ( V_162 ) ;
V_36 -> V_45 = 0 ;
V_36 -> V_37 = V_44 ;
V_36 = F_1 ( V_3 , 1 , 1 ) ;
V_36 -> V_53 = V_69 | F_46 ( V_71 ) ;
V_36 -> V_45 = ( 0xe0004500 & 0xFFFFF000 ) | V_163 | V_164 ;
V_36 -> V_37 = ( 0xe0004500 & 0xFFFFF000 ) | V_44 ;
}
static void F_118 ( struct V_2 * V_3 )
{
int V_87 ;
F_65 ( V_3 ) ;
F_10 ( V_3 -> V_92 [ 0 ] ) ;
F_10 ( V_3 -> V_92 [ 1 ] ) ;
if ( V_3 -> V_165 ) {
F_119 ( ( void * ) ( F_120 ( ( V_166 ) V_3 -> V_8 ,
V_167 ) ) ) ;
for ( V_87 = 0 ; V_87 < V_3 -> V_168 ; V_87 ++ ) {
F_121 ( V_3 -> V_165 [ V_87 ] ) ;
F_122 ( V_3 -> V_165 [ V_87 ] ) ;
}
V_3 -> V_168 = 0 ;
V_3 -> V_165 = NULL ;
} else {
F_10 ( V_3 -> V_8 ) ;
}
V_3 -> V_8 = NULL ;
}
int F_123 ( struct V_61 * V_25 ,
struct V_169 * V_170 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
struct V_171 V_172 ;
char * V_173 ;
struct V_174 * * V_175 ;
struct V_160 * V_176 [ 2 ] = {} ;
T_8 V_177 ;
T_1 V_84 ;
int V_178 , V_11 , V_87 ;
if ( V_170 -> V_179 != V_180 )
return - V_181 ;
if ( F_124 ( & V_172 , ( void V_182 * ) ( V_166 ) V_170 -> V_172 ,
sizeof( V_172 ) ) )
return - V_183 ;
if ( V_172 . V_184 [ 1 ] > 64 )
return - V_181 ;
if ( V_172 . V_185 [ 1 ] != V_172 . V_184 [ 1 ] )
return - V_181 ;
if ( V_172 . V_184 [ 2 ] != 0 || V_172 . V_184 [ 3 ] != 0 )
return - V_181 ;
if ( V_172 . V_185 [ 2 ] != 0 || V_172 . V_185 [ 3 ] != 0 )
return - V_181 ;
if ( ! F_125 ( V_172 . V_185 [ 0 ] ) )
return - V_181 ;
V_84 = V_172 . V_184 [ 0 ] >> F_126 ( V_172 . V_185 [ 0 ] ) ;
if ( ! F_125 ( V_84 ) )
return - V_181 ;
V_177 = V_172 . V_184 [ 0 ] + V_172 . V_184 [ 1 ] ;
V_177 *= sizeof( struct V_1 ) ;
if ( V_170 -> V_177 < V_177 )
return - V_181 ;
V_178 = F_127 ( V_170 -> V_186 + V_177 - 1 , V_167 ) -
V_170 -> V_186 / V_167 ;
V_175 = F_128 ( sizeof( struct V_174 * ) * V_178 , V_19 ) ;
if ( ! V_175 )
return - V_187 ;
V_11 = F_129 ( V_170 -> V_186 , V_178 , 1 , V_175 ) ;
if ( V_11 < 0 )
goto V_188;
if ( V_11 != V_178 ) {
V_178 = V_11 ;
V_11 = - V_183 ;
goto V_189;
}
V_173 = F_130 ( V_175 , V_178 , V_190 , V_191 ) ;
if ( ! V_173 )
goto V_189;
V_176 [ 0 ] = F_8 ( sizeof( struct V_160 ) * V_172 . V_184 [ 0 ] ,
V_19 ) ;
V_176 [ 1 ] = F_8 ( sizeof( struct V_160 ) * V_172 . V_184 [ 1 ] ,
V_19 ) ;
if ( ! V_176 [ 0 ] || ! V_176 [ 1 ] )
goto V_189;
F_118 ( V_3 ) ;
V_3 -> V_92 [ 0 ] = V_176 [ 0 ] ;
V_3 -> V_92 [ 1 ] = V_176 [ 1 ] ;
V_3 -> V_8 = (struct V_1 * )
( V_173 + ( V_170 -> V_186 & ( V_167 - 1 ) ) ) ;
V_3 -> V_31 [ 0 ] . V_34 = V_172 . V_184 [ 0 ] ;
V_3 -> V_31 [ 1 ] . V_34 = V_172 . V_184 [ 1 ] ;
V_3 -> V_7 [ 0 ] = 0 ;
V_3 -> V_7 [ 1 ] = V_172 . V_184 [ 0 ] ;
V_3 -> V_192 &= ~ ( V_193 | V_194 ) ;
if ( V_172 . V_184 [ 0 ] <= 2048 )
V_3 -> V_192 |= V_172 . V_184 [ 0 ] ;
V_3 -> V_192 |= V_172 . V_185 [ 0 ] << V_195 ;
V_3 -> V_196 &= ~ ( V_193 | V_194 ) ;
V_3 -> V_196 |= V_172 . V_184 [ 1 ] ;
V_3 -> V_196 |= V_172 . V_185 [ 1 ] << V_195 ;
V_3 -> V_165 = V_175 ;
V_3 -> V_168 = V_178 ;
V_3 -> V_31 [ 0 ] . V_32 = V_172 . V_185 [ 0 ] ;
V_3 -> V_31 [ 0 ] . V_84 = V_84 ;
V_3 -> V_31 [ 1 ] . V_32 = V_172 . V_184 [ 1 ] ;
V_3 -> V_31 [ 1 ] . V_84 = 1 ;
return 0 ;
V_189:
F_10 ( V_176 [ 0 ] ) ;
F_10 ( V_176 [ 1 ] ) ;
for ( V_87 = 0 ; V_87 < V_178 ; V_87 ++ )
F_122 ( V_175 [ V_87 ] ) ;
V_188:
F_10 ( V_175 ) ;
return V_11 ;
}
int F_131 ( struct V_61 * V_25 ,
struct V_197 * V_198 )
{
struct V_2 * V_3 = F_41 ( V_25 ) ;
F_65 ( V_3 ) ;
return 0 ;
}
int F_132 ( struct V_2 * V_3 )
{
int V_199 = sizeof( struct V_1 ) ;
int V_34 = V_200 + V_201 ;
V_33 [ 0 ] . V_34 = F_35 ( V_202 ) & V_193 ;
V_33 [ 1 ] . V_34 = F_35 ( V_203 ) & V_193 ;
if ( V_33 [ 0 ] . V_34 == 0 ||
V_33 [ 1 ] . V_34 == 0 ) {
F_133 ( L_2 , V_204 ) ;
return - V_205 ;
}
V_33 [ 0 ] . V_32 = ( F_35 ( V_202 ) & V_194 ) >>
V_195 ;
V_33 [ 1 ] . V_32 = V_33 [ 1 ] . V_34 ;
if ( ! F_125 ( V_33 [ 0 ] . V_34 ) ||
! F_125 ( V_33 [ 0 ] . V_32 ) ||
V_33 [ 0 ] . V_34 < V_33 [ 0 ] . V_32 ||
V_33 [ 0 ] . V_32 == 0 ) {
F_133 ( L_3 ,
V_204 , V_33 [ 0 ] . V_34 ,
V_33 [ 0 ] . V_32 ) ;
return - V_205 ;
}
V_33 [ 0 ] . V_84 =
V_33 [ 0 ] . V_34 / V_33 [ 0 ] . V_32 ;
V_33 [ 1 ] . V_84 = 1 ;
V_3 -> V_31 [ 0 ] . V_34 = V_200 ;
V_3 -> V_31 [ 1 ] . V_34 = V_201 ;
V_3 -> V_31 [ 0 ] . V_32 = V_206 ;
V_3 -> V_31 [ 0 ] . V_84 =
V_200 / V_206 ;
V_3 -> V_31 [ 1 ] . V_32 = V_201 ;
V_3 -> V_31 [ 1 ] . V_84 = 1 ;
V_3 -> V_8 = F_128 ( V_34 * V_199 , V_19 ) ;
if ( ! V_3 -> V_8 )
return - V_187 ;
V_3 -> V_7 [ 0 ] = 0 ;
V_3 -> V_7 [ 1 ] = V_200 ;
V_3 -> V_94 [ 0 ] =
F_8 ( sizeof( struct V_88 ) * V_33 [ 0 ] . V_34 ,
V_19 ) ;
if ( ! V_3 -> V_94 [ 0 ] )
goto V_207;
V_3 -> V_94 [ 1 ] =
F_8 ( sizeof( struct V_88 ) * V_33 [ 1 ] . V_34 ,
V_19 ) ;
if ( ! V_3 -> V_94 [ 1 ] )
goto V_207;
V_3 -> V_92 [ 0 ] = F_8 ( sizeof( struct V_88 ) *
V_3 -> V_31 [ 0 ] . V_34 ,
V_19 ) ;
if ( ! V_3 -> V_92 [ 0 ] )
goto V_207;
V_3 -> V_92 [ 1 ] = F_8 ( sizeof( struct V_88 ) *
V_3 -> V_31 [ 1 ] . V_34 ,
V_19 ) ;
if ( ! V_3 -> V_92 [ 1 ] )
goto V_207;
if ( F_7 ( V_3 ) == NULL )
goto V_207;
V_3 -> V_192 = F_35 ( V_202 ) &
~ ( V_193 | V_194 ) ;
V_3 -> V_192 |= V_3 -> V_31 [ 0 ] . V_34 ;
V_3 -> V_192 |=
V_3 -> V_31 [ 0 ] . V_32 << V_195 ;
V_3 -> V_196 = F_35 ( V_203 ) &
~ ( V_193 | V_194 ) ;
V_3 -> V_192 |= V_3 -> V_31 [ 1 ] . V_34 ;
V_3 -> V_192 |=
V_3 -> V_31 [ 1 ] . V_32 << V_195 ;
return 0 ;
V_207:
F_118 ( V_3 ) ;
F_10 ( V_3 -> V_94 [ 0 ] ) ;
F_10 ( V_3 -> V_94 [ 1 ] ) ;
return - 1 ;
}
void F_134 ( struct V_2 * V_3 )
{
F_118 ( V_3 ) ;
F_9 ( V_3 ) ;
F_10 ( V_3 -> V_94 [ 0 ] ) ;
F_10 ( V_3 -> V_94 [ 1 ] ) ;
}
