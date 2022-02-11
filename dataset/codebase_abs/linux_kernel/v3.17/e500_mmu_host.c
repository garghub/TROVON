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
T_1 V_24 ;
F_5 ( V_12 ) ;
F_6 ( V_25 , 0 ) ;
V_24 = F_11 ( V_26 ) ;
F_6 ( V_26 , V_24 & ~ V_27 ) ;
asm volatile("tlbsx 0, %0" : : "b" (eaddr & ~CONFIG_PAGE_OFFSET));
V_11 = F_11 ( V_13 ) ;
F_6 ( V_26 , V_24 ) ;
F_8 ( V_12 ) ;
return V_11 ;
}
static inline void F_12 ( struct V_28 * V_29 ,
int V_30 , int V_31 , struct V_9 * V_10 )
{
T_1 V_11 ;
if ( V_30 == 0 ) {
V_11 = F_10 ( V_10 -> V_17 ) ;
F_4 ( V_10 , V_11 ) ;
} else {
F_4 ( V_10 ,
F_13 ( 1 ) |
F_14 ( F_15 ( V_31 ) ) ) ;
}
}
static void F_16 ( struct V_28 * V_29 ,
struct V_9 * V_32 ,
struct V_9 * V_10 ,
int V_33 , int V_31 )
{
int V_34 ;
F_17 () ;
V_34 = F_18 ( & V_29 -> V_35 , V_32 ) ;
V_10 -> V_15 |= F_19 ( V_34 ) ;
F_12 ( V_29 , V_33 , V_31 , V_10 ) ;
F_20 () ;
}
void F_21 ( struct V_36 * V_35 )
{
struct V_28 * V_29 = F_22 ( V_35 ) ;
struct V_9 V_37 ;
T_3 V_38 = ( ( T_3 ) V_35 -> V_39 . V_40 ) & V_41 ;
unsigned int V_34 ;
T_4 V_42 ;
V_42 = ( T_4 ) F_23 ( ( void * ) V_38 ) >> V_43 ;
F_24 ( F_25 ( V_42 ) ) ;
F_17 () ;
V_34 = F_26 ( V_29 , 0 , 0 , 0 , 0 ) ;
V_37 . V_15 = V_44 | V_45 | F_19 ( V_34 ) |
F_27 ( V_46 ) ;
V_37 . V_17 = V_35 -> V_39 . V_47 | V_48 ;
V_37 . V_19 = ( ( V_49 ) V_42 << V_43 ) |
V_50 | V_51 | V_52 | V_53 ;
V_37 . V_22 = 0 ;
F_4 ( & V_37 , F_13 ( 1 ) | F_14 ( V_3 ) ) ;
F_20 () ;
}
void F_28 ( struct V_28 * V_29 , int V_30 ,
int V_54 )
{
struct V_9 * V_32 =
F_29 ( V_29 , V_30 , V_54 ) ;
struct V_55 * V_56 = & V_29 -> V_57 [ V_30 ] [ V_54 ] . V_56 ;
if ( ! ( V_56 -> V_12 & V_58 ) ) {
F_30 ( V_56 -> V_12 & ( V_59 | V_60 ) ,
L_1 , V_61 , V_56 -> V_12 ) ;
F_31 ( V_30 == 1 && V_29 -> V_62 [ V_54 ] ) ;
}
if ( V_30 == 1 && V_56 -> V_12 & V_59 ) {
V_49 V_63 = V_29 -> V_62 [ V_54 ] ;
int V_64 ;
unsigned long V_12 ;
F_5 ( V_12 ) ;
while ( V_63 ) {
V_64 = F_32 ( V_63 & - V_63 ) ;
F_6 ( V_13 ,
F_13 ( 1 ) |
F_14 ( F_15 ( V_64 ) ) ) ;
F_6 ( V_14 , 0 ) ;
asm volatile("tlbwe");
V_29 -> V_65 [ V_64 ] = 0 ;
V_63 &= V_63 - 1 ;
}
F_33 () ;
V_29 -> V_62 [ V_54 ] = 0 ;
V_56 -> V_12 &= ~ ( V_59 | V_58 ) ;
F_8 ( V_12 ) ;
}
if ( V_30 == 1 && V_56 -> V_12 & V_60 ) {
F_34 ( V_29 ) ;
V_56 -> V_12 &= ~ ( V_60 | V_58 ) ;
}
if ( V_56 -> V_12 & V_58 )
F_35 ( V_29 , V_32 ) ;
V_56 -> V_12 = 0 ;
}
static inline int F_36 ( struct V_9 * V_66 )
{
return V_66 -> V_19 & ( V_50 | V_52 ) ;
}
static inline void F_37 ( struct V_55 * V_56 ,
struct V_9 * V_32 ,
T_4 V_42 , unsigned int V_67 )
{
V_56 -> V_42 = V_42 ;
V_56 -> V_12 = V_58 ;
V_56 -> V_12 |= ( V_32 -> V_17 & V_68 ) | V_67 ;
F_38 ( V_42 ) ;
if ( F_36 ( V_32 ) )
F_39 ( V_42 ) ;
}
static inline void F_40 ( struct V_55 * V_56 )
{
if ( V_56 -> V_12 & V_58 ) {
F_41 ( V_56 -> V_42 , V_56 -> V_12 ) ;
V_56 -> V_12 = 0 ;
}
}
static void F_42 ( struct V_28 * V_29 )
{
if ( V_29 -> V_62 )
memset ( V_29 -> V_62 , 0 ,
sizeof( V_49 ) * V_29 -> V_69 [ 1 ] . V_2 ) ;
if ( V_29 -> V_65 )
memset ( V_29 -> V_65 , 0 ,
sizeof( unsigned int ) * V_1 [ 1 ] . V_2 ) ;
}
static void F_43 ( struct V_28 * V_29 )
{
int V_30 ;
int V_70 ;
for ( V_30 = 0 ; V_30 <= 1 ; V_30 ++ ) {
for ( V_70 = 0 ; V_70 < V_29 -> V_69 [ V_30 ] . V_2 ; V_70 ++ ) {
struct V_55 * V_56 =
& V_29 -> V_57 [ V_30 ] [ V_70 ] . V_56 ;
F_40 ( V_56 ) ;
}
}
}
void F_44 ( struct V_36 * V_35 )
{
struct V_28 * V_29 = F_22 ( V_35 ) ;
F_34 ( V_29 ) ;
F_43 ( V_29 ) ;
F_42 ( V_29 ) ;
}
static void F_45 (
struct V_36 * V_35 ,
struct V_9 * V_32 ,
int V_71 , struct V_55 * V_56 , V_49 V_72 ,
struct V_9 * V_10 )
{
T_4 V_42 = V_56 -> V_42 ;
T_1 V_73 = V_35 -> V_39 . V_40 -> V_74 & V_75 ;
F_46 ( ! ( V_56 -> V_12 & V_58 ) ) ;
V_10 -> V_15 = F_27 ( V_71 ) | F_47 ( V_32 ) | V_44 ;
V_10 -> V_17 = ( V_72 & V_76 ) | ( V_56 -> V_12 & V_77 ) ;
V_10 -> V_19 = ( ( V_49 ) V_42 << V_43 ) |
F_2 ( V_32 -> V_19 , V_73 ) ;
#ifdef F_3
V_10 -> V_22 = V_78 | V_35 -> V_79 -> V_39 . V_80 ;
#endif
}
static inline int F_48 ( struct V_28 * V_29 ,
V_49 V_72 , T_5 V_81 , struct V_9 * V_32 ,
int V_30 , struct V_9 * V_10 ,
struct V_55 * V_56 )
{
struct V_82 * V_83 ;
unsigned long V_42 = 0 ;
unsigned long V_84 ;
int V_85 = 0 ;
int V_71 = V_46 ;
int V_86 = 0 ;
unsigned long V_87 ;
struct V_79 * V_79 = V_29 -> V_35 . V_79 ;
unsigned long V_88 = 0 ;
T_6 * V_89 ;
unsigned int V_67 = 0 ;
T_7 * V_90 ;
V_87 = V_79 -> V_91 ;
F_49 () ;
V_83 = F_50 ( V_29 -> V_35 . V_79 , V_81 ) ;
V_84 = F_51 ( V_83 , V_81 ) ;
if ( V_30 == 1 ) {
struct V_92 * V_93 ;
F_52 ( & V_94 -> V_95 -> V_96 ) ;
V_93 = F_53 ( V_94 -> V_95 , V_84 ) ;
if ( V_93 && V_84 >= V_93 -> V_97 &&
( V_93 -> V_98 & V_99 ) ) {
unsigned long V_100 , V_101 ;
unsigned long V_102 , V_103 ;
V_85 = 1 ;
V_100 = V_93 -> V_104 ;
V_101 = V_100 +
( ( V_93 -> V_105 - V_93 -> V_97 ) >> V_43 ) ;
V_42 = V_100 + ( ( V_84 - V_93 -> V_97 ) >> V_43 ) ;
V_102 = V_42 - ( V_81 - V_83 -> V_106 ) ;
V_103 = V_102 + V_83 -> V_107 ;
if ( V_100 < V_102 )
V_100 = V_102 ;
if ( V_101 > V_103 )
V_101 = V_103 ;
V_71 = ( V_32 -> V_15 & V_108 ) >>
V_109 ;
V_71 = F_54 ( V_46 , V_71 & ~ 1 ) ;
for (; V_71 > V_46 ; V_71 -= 2 ) {
unsigned long V_110 , V_111 ;
V_88 = 1 << ( V_71 - 2 ) ;
V_110 = V_81 & ~ ( V_88 - 1 ) ;
V_111 = V_110 + V_88 ;
if ( V_110 + V_42 - V_81 < V_100 )
continue;
if ( V_111 + V_42 - V_81 > V_101 )
continue;
if ( ( V_81 & ( V_88 - 1 ) ) !=
( V_42 & ( V_88 - 1 ) ) )
continue;
V_72 &= ~ ( ( V_88 << V_43 ) - 1 ) ;
V_42 &= ~ ( V_88 - 1 ) ;
break;
}
} else if ( V_93 && V_84 >= V_93 -> V_97 &&
( V_93 -> V_98 & V_112 ) ) {
unsigned long V_113 = F_55 ( V_93 ) ;
V_71 = ( V_32 -> V_15 & V_108 ) >>
V_109 ;
V_71 = F_56 ( F_57 ( V_113 ) - 10 , V_71 ) ;
V_71 = F_54 ( V_46 , V_71 & ~ 1 ) ;
}
F_58 ( & V_94 -> V_95 -> V_96 ) ;
}
if ( F_59 ( ! V_85 ) ) {
V_88 = 1 << ( V_71 + 10 - V_43 ) ;
V_42 = F_60 ( V_83 , V_81 ) ;
if ( F_61 ( V_42 ) ) {
if ( F_62 () )
F_63 ( L_2 ,
V_61 , ( long ) V_81 ) ;
return - V_114 ;
}
V_42 &= ~ ( V_88 - 1 ) ;
V_72 &= ~ ( ( V_88 << V_43 ) - 1 ) ;
}
F_64 ( & V_79 -> V_115 ) ;
if ( F_65 ( V_79 , V_87 ) ) {
V_86 = - V_116 ;
goto V_117;
}
V_90 = V_29 -> V_35 . V_39 . V_90 ;
V_89 = F_66 ( V_90 , V_84 , & V_88 ) ;
if ( F_67 ( * V_89 ) )
V_67 = ( * V_89 >> V_118 ) & V_119 ;
else {
if ( F_62 () )
F_63 ( L_3 ,
V_61 , ( long ) V_81 , V_42 ) ;
V_86 = - V_114 ;
goto V_117;
}
F_37 ( V_56 , V_32 , V_42 , V_67 ) ;
F_45 ( & V_29 -> V_35 , V_32 , V_71 ,
V_56 , V_72 , V_10 ) ;
F_68 ( V_42 ) ;
V_117:
F_69 ( & V_79 -> V_115 ) ;
F_70 ( V_42 ) ;
return V_86 ;
}
static int F_71 ( struct V_28 * V_29 , int V_54 ,
struct V_9 * V_10 )
{
struct V_9 * V_32 ;
struct V_55 * V_56 ;
int V_33 = 0 ;
int V_31 = 0 ;
int V_120 ;
V_32 = F_29 ( V_29 , 0 , V_54 ) ;
V_56 = & V_29 -> V_57 [ 0 ] [ V_54 ] . V_56 ;
V_120 = F_48 ( V_29 , F_72 ( V_32 ) ,
F_73 ( V_32 ) >> V_43 ,
V_32 , 0 , V_10 , V_56 ) ;
if ( V_120 )
return V_120 ;
F_16 ( V_29 , V_32 , V_10 , V_33 , V_31 ) ;
return 0 ;
}
static int F_74 ( struct V_28 * V_29 ,
struct V_55 * V_56 ,
int V_54 )
{
unsigned int V_31 = V_29 -> V_121 ++ ;
if ( F_75 ( V_29 -> V_121 >= F_1 () ) )
V_29 -> V_121 = 0 ;
if ( V_29 -> V_65 [ V_31 ] ) {
unsigned int V_122 = V_29 -> V_65 [ V_31 ] - 1 ;
V_29 -> V_62 [ V_122 ] &= ~ ( 1ULL << V_31 ) ;
}
V_29 -> V_57 [ 1 ] [ V_54 ] . V_56 . V_12 |= V_59 ;
V_29 -> V_62 [ V_54 ] |= ( V_49 ) 1 << V_31 ;
V_29 -> V_65 [ V_31 ] = V_54 + 1 ;
F_31 ( ! ( V_56 -> V_12 & V_58 ) ) ;
return V_31 ;
}
static int F_76 ( struct V_28 * V_29 ,
V_49 V_72 , T_5 V_81 , struct V_9 * V_32 ,
struct V_9 * V_10 , int V_54 )
{
struct V_55 * V_56 = & V_29 -> V_57 [ 1 ] [ V_54 ] . V_56 ;
int V_31 ;
int V_120 ;
V_120 = F_48 ( V_29 , V_72 , V_81 , V_32 , 1 , V_10 ,
V_56 ) ;
if ( V_120 )
return V_120 ;
if ( F_77 ( V_10 ) == V_46 ) {
V_29 -> V_57 [ 1 ] [ V_54 ] . V_56 . V_12 |= V_60 ;
F_16 ( V_29 , V_32 , V_10 , 0 , 0 ) ;
return 0 ;
}
V_31 = F_74 ( V_29 , V_56 , V_54 ) ;
F_16 ( V_29 , V_32 , V_10 , 1 , V_31 ) ;
return 0 ;
}
void F_78 ( struct V_36 * V_35 , V_49 V_23 , T_8 V_123 ,
unsigned int V_124 )
{
struct V_28 * V_29 = F_22 ( V_35 ) ;
struct V_125 * V_126 ;
struct V_9 * V_32 , V_10 ;
int V_30 = F_79 ( V_124 ) ;
int V_54 = F_80 ( V_124 ) ;
V_32 = F_29 ( V_29 , V_30 , V_54 ) ;
switch ( V_30 ) {
case 0 :
V_126 = & V_29 -> V_57 [ V_30 ] [ V_54 ] ;
if ( ! ( V_126 -> V_56 . V_12 & V_58 ) ) {
F_71 ( V_29 , V_54 , & V_10 ) ;
} else {
F_45 ( V_35 , V_32 , V_46 ,
& V_126 -> V_56 , V_23 , & V_10 ) ;
F_16 ( V_29 , V_32 , & V_10 , 0 , 0 ) ;
}
break;
case 1 : {
T_5 V_81 = V_123 >> V_43 ;
F_76 ( V_29 , V_23 , V_81 , V_32 , & V_10 ,
V_54 ) ;
break;
}
default:
F_81 () ;
break;
}
}
int F_82 ( struct V_36 * V_35 , enum V_127 type ,
T_1 * V_128 )
{
T_9 V_129 ;
T_10 V_130 ;
T_11 V_42 ;
T_12 V_23 ;
T_1 V_15 , V_17 , V_4 ;
V_49 V_131 ;
struct V_132 * V_132 ;
unsigned int V_133 , V_134 ;
bool V_73 ;
unsigned long V_12 ;
V_129 = F_83 ( V_35 ) ;
V_133 = ( V_35 -> V_39 . V_40 -> V_74 & V_135 ) >> V_136 ;
F_5 ( V_12 ) ;
F_6 ( V_25 , ( V_35 -> V_39 . V_137 << V_138 ) | V_133 ) ;
F_6 ( V_139 , V_140 | V_35 -> V_79 -> V_39 . V_80 ) ;
asm volatile("tlbsx 0, %[geaddr]\n" : :
[geaddr] "r" (geaddr));
F_6 ( V_139 , 0 ) ;
F_6 ( V_21 , 0 ) ;
V_15 = F_11 ( V_14 ) ;
V_17 = F_11 ( V_16 ) ;
V_4 = F_11 ( V_18 ) ;
#ifdef F_84
V_131 = F_11 ( V_141 ) ;
#else
V_131 = ( ( V_49 ) F_11 ( V_20 ) << 32 ) | V_4 ;
#endif
F_8 ( V_12 ) ;
if ( ! ( V_15 & V_44 ) )
return V_142 ;
V_73 = V_35 -> V_39 . V_40 -> V_74 & V_75 ;
if ( F_75 ( ( V_73 && ! ( V_4 & V_143 ) ) ||
( ! V_73 && ! ( V_4 & V_144 ) ) ) ) {
F_85 (
L_4 ,
V_61 , V_129 ) ;
return V_142 ;
}
if ( F_86 ( V_35 , V_145 ) &&
F_75 ( ( V_17 & V_146 ) || ( V_17 & V_147 ) || ! ( V_17 & V_48 ) ) ) {
F_85 (
L_5 ,
V_61 , V_129 ) ;
return V_142 ;
}
V_134 = F_87 ( V_15 ) + 10 ;
V_130 = ( V_131 & ( ~ 0ULL << V_134 ) ) |
( V_129 & ( ( 1ULL << V_134 ) - 1ULL ) ) ;
V_42 = V_130 >> V_43 ;
if ( F_75 ( ! F_88 ( V_42 ) ) ) {
F_85 ( L_6 ,
V_61 , V_130 ) ;
return V_142 ;
}
V_132 = F_25 ( V_42 ) ;
V_23 = ( unsigned long ) F_89 ( V_132 ) ;
* V_128 = * ( T_1 * ) ( V_23 | ( unsigned long ) ( V_130 & ~ V_41 ) ) ;
F_90 ( ( T_1 * ) V_23 ) ;
return V_148 ;
}
int F_82 ( struct V_36 * V_35 , enum V_127 type ,
T_1 * V_128 )
{
return V_142 ;
}
int F_91 ( struct V_79 * V_79 , unsigned long V_84 )
{
F_92 ( V_84 ) ;
F_93 ( V_79 ) ;
return 0 ;
}
int F_94 ( struct V_79 * V_79 , unsigned long V_100 , unsigned long V_101 )
{
F_91 ( V_79 , V_100 ) ;
return 0 ;
}
int F_95 ( struct V_79 * V_79 , unsigned long V_84 )
{
return 0 ;
}
int F_96 ( struct V_79 * V_79 , unsigned long V_84 )
{
return 0 ;
}
void F_97 ( struct V_79 * V_79 , unsigned long V_84 , T_6 V_149 )
{
F_91 ( V_79 , V_84 ) ;
}
int F_98 ( struct V_28 * V_29 )
{
V_1 [ 0 ] . V_2 = F_11 ( V_150 ) & V_151 ;
V_1 [ 1 ] . V_2 = F_11 ( V_152 ) & V_151 ;
if ( V_1 [ 0 ] . V_2 == 0 ||
V_1 [ 1 ] . V_2 == 0 ) {
F_63 ( L_7 , V_61 ) ;
return - V_153 ;
}
V_1 [ 0 ] . V_154 = ( F_11 ( V_150 ) & V_155 ) >>
V_156 ;
V_1 [ 1 ] . V_154 = V_1 [ 1 ] . V_2 ;
if ( ! F_99 ( V_1 [ 0 ] . V_2 ) ||
! F_99 ( V_1 [ 0 ] . V_154 ) ||
V_1 [ 0 ] . V_2 < V_1 [ 0 ] . V_154 ||
V_1 [ 0 ] . V_154 == 0 ) {
F_63 ( L_8 ,
V_61 , V_1 [ 0 ] . V_2 ,
V_1 [ 0 ] . V_154 ) ;
return - V_153 ;
}
V_1 [ 0 ] . V_157 =
V_1 [ 0 ] . V_2 / V_1 [ 0 ] . V_154 ;
V_1 [ 1 ] . V_157 = 1 ;
V_29 -> V_65 = F_100 ( sizeof( unsigned int ) *
V_1 [ 1 ] . V_2 ,
V_158 ) ;
if ( ! V_29 -> V_65 )
return - V_114 ;
return 0 ;
}
void F_101 ( struct V_28 * V_29 )
{
F_102 ( V_29 -> V_65 ) ;
}
