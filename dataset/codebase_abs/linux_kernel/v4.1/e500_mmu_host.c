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
T_2 V_11 ,
T_2 V_12 )
{
unsigned long V_13 ;
F_5 ( V_13 ) ;
F_6 ( V_14 , V_11 ) ;
F_6 ( V_15 , V_10 -> V_16 ) ;
F_6 ( V_17 , ( unsigned long ) V_10 -> V_18 ) ;
F_6 ( V_19 , ( T_1 ) V_10 -> V_20 ) ;
F_6 ( V_21 , ( T_1 ) ( V_10 -> V_20 >> 32 ) ) ;
#ifdef F_3
F_6 ( V_22 , V_23 | F_7 ( V_12 ) ) ;
#endif
asm volatile("isync; tlbwe" : : : "memory");
#ifdef F_3
F_6 ( V_22 , 0 ) ;
F_8 () ;
#endif
F_9 ( V_13 ) ;
F_10 ( V_11 , V_10 -> V_24 , V_10 -> V_16 ,
V_10 -> V_18 , V_10 -> V_20 ) ;
}
static T_1 F_11 ( unsigned long V_25 )
{
unsigned long V_13 ;
T_1 V_11 ;
T_1 V_26 ;
F_5 ( V_13 ) ;
F_6 ( V_27 , 0 ) ;
V_26 = F_12 ( V_28 ) ;
F_6 ( V_28 , V_26 & ~ V_29 ) ;
asm volatile("tlbsx 0, %0" : : "b" (eaddr & ~CONFIG_PAGE_OFFSET));
V_11 = F_12 ( V_14 ) ;
F_6 ( V_28 , V_26 ) ;
F_9 ( V_13 ) ;
return V_11 ;
}
static inline void F_13 ( struct V_30 * V_31 ,
int V_32 , int V_33 , struct V_9 * V_10 )
{
T_1 V_11 ;
if ( V_32 == 0 ) {
V_11 = F_11 ( V_10 -> V_18 ) ;
F_4 ( V_10 , V_11 , V_31 -> V_34 . V_35 -> V_36 . V_12 ) ;
} else {
F_4 ( V_10 ,
F_14 ( 1 ) |
F_15 ( F_16 ( V_33 ) ) ,
V_31 -> V_34 . V_35 -> V_36 . V_12 ) ;
}
}
static void F_17 ( struct V_30 * V_31 ,
struct V_9 * V_37 ,
struct V_9 * V_10 ,
int V_38 , int V_33 )
{
int V_39 ;
F_18 () ;
V_39 = F_19 ( & V_31 -> V_34 , V_37 ) ;
V_10 -> V_16 |= F_20 ( V_39 ) ;
F_13 ( V_31 , V_38 , V_33 , V_10 ) ;
F_21 () ;
}
void F_22 ( struct V_40 * V_34 )
{
struct V_30 * V_31 = F_23 ( V_34 ) ;
struct V_9 V_41 ;
T_3 V_42 = ( ( T_3 ) V_34 -> V_36 . V_43 ) & V_44 ;
unsigned int V_39 ;
T_4 V_45 ;
V_45 = ( T_4 ) F_24 ( ( void * ) V_42 ) >> V_46 ;
F_25 ( F_26 ( V_45 ) ) ;
F_18 () ;
V_39 = F_27 ( V_31 , 0 , 0 , 0 , 0 ) ;
V_41 . V_16 = V_47 | V_48 | F_20 ( V_39 ) |
F_28 ( V_49 ) ;
V_41 . V_18 = V_34 -> V_36 . V_50 | V_51 ;
V_41 . V_20 = ( ( V_52 ) V_45 << V_46 ) |
V_53 | V_54 | V_55 | V_56 ;
V_41 . V_24 = 0 ;
F_4 ( & V_41 , F_14 ( 1 ) | F_15 ( V_3 ) , 0 ) ;
F_21 () ;
}
void F_29 ( struct V_30 * V_31 , int V_32 ,
int V_57 )
{
struct V_9 * V_37 =
F_30 ( V_31 , V_32 , V_57 ) ;
struct V_58 * V_59 = & V_31 -> V_60 [ V_32 ] [ V_57 ] . V_59 ;
if ( ! ( V_59 -> V_13 & V_61 ) ) {
F_31 ( V_59 -> V_13 & ( V_62 | V_63 ) ,
L_1 , V_64 , V_59 -> V_13 ) ;
F_32 ( V_32 == 1 && V_31 -> V_65 [ V_57 ] ) ;
}
if ( V_32 == 1 && V_59 -> V_13 & V_62 ) {
V_52 V_66 = V_31 -> V_65 [ V_57 ] ;
int V_67 ;
unsigned long V_13 ;
F_5 ( V_13 ) ;
while ( V_66 ) {
V_67 = F_33 ( V_66 & - V_66 ) ;
F_6 ( V_14 ,
F_14 ( 1 ) |
F_15 ( F_16 ( V_67 ) ) ) ;
F_6 ( V_15 , 0 ) ;
asm volatile("tlbwe");
V_31 -> V_68 [ V_67 ] = 0 ;
V_66 &= V_66 - 1 ;
}
F_34 () ;
V_31 -> V_65 [ V_57 ] = 0 ;
V_59 -> V_13 &= ~ ( V_62 | V_61 ) ;
F_9 ( V_13 ) ;
}
if ( V_32 == 1 && V_59 -> V_13 & V_63 ) {
F_35 ( V_31 ) ;
V_59 -> V_13 &= ~ ( V_63 | V_61 ) ;
}
if ( V_59 -> V_13 & V_61 )
F_36 ( V_31 , V_37 ) ;
V_59 -> V_13 = 0 ;
}
static inline int F_37 ( struct V_9 * V_69 )
{
return V_69 -> V_20 & ( V_53 | V_55 ) ;
}
static inline void F_38 ( struct V_58 * V_59 ,
struct V_9 * V_37 ,
T_4 V_45 , unsigned int V_70 )
{
V_59 -> V_45 = V_45 ;
V_59 -> V_13 = V_61 ;
V_59 -> V_13 |= ( V_37 -> V_18 & V_71 ) | V_70 ;
F_39 ( V_45 ) ;
if ( F_37 ( V_37 ) )
F_40 ( V_45 ) ;
}
static inline void F_41 ( struct V_58 * V_59 )
{
if ( V_59 -> V_13 & V_61 ) {
F_42 ( V_59 -> V_45 , V_59 -> V_13 ) ;
V_59 -> V_13 = 0 ;
}
}
static void F_43 ( struct V_30 * V_31 )
{
if ( V_31 -> V_65 )
memset ( V_31 -> V_65 , 0 ,
sizeof( V_52 ) * V_31 -> V_72 [ 1 ] . V_2 ) ;
if ( V_31 -> V_68 )
memset ( V_31 -> V_68 , 0 ,
sizeof( unsigned int ) * V_1 [ 1 ] . V_2 ) ;
}
static void F_44 ( struct V_30 * V_31 )
{
int V_32 ;
int V_73 ;
for ( V_32 = 0 ; V_32 <= 1 ; V_32 ++ ) {
for ( V_73 = 0 ; V_73 < V_31 -> V_72 [ V_32 ] . V_2 ; V_73 ++ ) {
struct V_58 * V_59 =
& V_31 -> V_60 [ V_32 ] [ V_73 ] . V_59 ;
F_41 ( V_59 ) ;
}
}
}
void F_45 ( struct V_40 * V_34 )
{
struct V_30 * V_31 = F_23 ( V_34 ) ;
F_35 ( V_31 ) ;
F_44 ( V_31 ) ;
F_43 ( V_31 ) ;
}
static void F_46 (
struct V_40 * V_34 ,
struct V_9 * V_37 ,
int V_74 , struct V_58 * V_59 , V_52 V_75 ,
struct V_9 * V_10 )
{
T_4 V_45 = V_59 -> V_45 ;
T_1 V_76 = V_34 -> V_36 . V_43 -> V_77 & V_78 ;
F_47 ( ! ( V_59 -> V_13 & V_61 ) ) ;
V_10 -> V_16 = F_28 ( V_74 ) | F_48 ( V_37 ) | V_47 ;
V_10 -> V_18 = ( V_75 & V_79 ) | ( V_59 -> V_13 & V_80 ) ;
V_10 -> V_20 = ( ( V_52 ) V_45 << V_46 ) |
F_2 ( V_37 -> V_20 , V_76 ) ;
}
static inline int F_49 ( struct V_30 * V_31 ,
V_52 V_75 , T_5 V_81 , struct V_9 * V_37 ,
int V_32 , struct V_9 * V_10 ,
struct V_58 * V_59 )
{
struct V_82 * V_83 ;
unsigned long V_45 = 0 ;
unsigned long V_84 ;
int V_85 = 0 ;
int V_74 = V_49 ;
int V_86 = 0 ;
unsigned long V_87 ;
struct V_35 * V_35 = V_31 -> V_34 . V_35 ;
unsigned long V_88 = 0 ;
T_6 * V_89 ;
unsigned int V_70 = 0 ;
T_7 * V_90 ;
unsigned long V_13 ;
V_87 = V_35 -> V_91 ;
F_50 () ;
V_83 = F_51 ( V_31 -> V_34 . V_35 , V_81 ) ;
V_84 = F_52 ( V_83 , V_81 ) ;
if ( V_32 == 1 ) {
struct V_92 * V_93 ;
F_53 ( & V_94 -> V_95 -> V_96 ) ;
V_93 = F_54 ( V_94 -> V_95 , V_84 ) ;
if ( V_93 && V_84 >= V_93 -> V_97 &&
( V_93 -> V_98 & V_99 ) ) {
unsigned long V_100 , V_101 ;
unsigned long V_102 , V_103 ;
V_85 = 1 ;
V_100 = V_93 -> V_104 ;
V_101 = V_100 +
( ( V_93 -> V_105 - V_93 -> V_97 ) >> V_46 ) ;
V_45 = V_100 + ( ( V_84 - V_93 -> V_97 ) >> V_46 ) ;
V_102 = V_45 - ( V_81 - V_83 -> V_106 ) ;
V_103 = V_102 + V_83 -> V_107 ;
if ( V_100 < V_102 )
V_100 = V_102 ;
if ( V_101 > V_103 )
V_101 = V_103 ;
V_74 = ( V_37 -> V_16 & V_108 ) >>
V_109 ;
V_74 = F_55 ( V_49 , V_74 & ~ 1 ) ;
for (; V_74 > V_49 ; V_74 -= 2 ) {
unsigned long V_110 , V_111 ;
V_88 = 1 << ( V_74 - 2 ) ;
V_110 = V_81 & ~ ( V_88 - 1 ) ;
V_111 = V_110 + V_88 ;
if ( V_110 + V_45 - V_81 < V_100 )
continue;
if ( V_111 + V_45 - V_81 > V_101 )
continue;
if ( ( V_81 & ( V_88 - 1 ) ) !=
( V_45 & ( V_88 - 1 ) ) )
continue;
V_75 &= ~ ( ( V_88 << V_46 ) - 1 ) ;
V_45 &= ~ ( V_88 - 1 ) ;
break;
}
} else if ( V_93 && V_84 >= V_93 -> V_97 &&
( V_93 -> V_98 & V_112 ) ) {
unsigned long V_113 = F_56 ( V_93 ) ;
V_74 = ( V_37 -> V_16 & V_108 ) >>
V_109 ;
V_74 = F_57 ( F_58 ( V_113 ) - 10 , V_74 ) ;
V_74 = F_55 ( V_49 , V_74 & ~ 1 ) ;
}
F_59 ( & V_94 -> V_95 -> V_96 ) ;
}
if ( F_60 ( ! V_85 ) ) {
V_88 = 1 << ( V_74 + 10 - V_46 ) ;
V_45 = F_61 ( V_83 , V_81 ) ;
if ( F_62 ( V_45 ) ) {
if ( F_63 () )
F_64 ( L_2 ,
V_64 , ( long ) V_81 ) ;
return - V_114 ;
}
V_45 &= ~ ( V_88 - 1 ) ;
V_75 &= ~ ( ( V_88 << V_46 ) - 1 ) ;
}
F_65 ( & V_35 -> V_115 ) ;
if ( F_66 ( V_35 , V_87 ) ) {
V_86 = - V_116 ;
goto V_117;
}
V_90 = V_31 -> V_34 . V_36 . V_90 ;
F_5 ( V_13 ) ;
V_89 = F_67 ( V_90 , V_84 , NULL ) ;
if ( V_89 ) {
T_6 V_118 = F_68 ( * V_89 ) ;
if ( F_69 ( V_118 ) ) {
V_70 = ( F_70 ( V_118 ) >> V_119 ) &
V_120 ;
F_9 ( V_13 ) ;
} else {
F_9 ( V_13 ) ;
F_71 ( L_3 ,
V_64 , ( long ) V_81 , V_45 ) ;
V_86 = - V_114 ;
goto V_117;
}
}
F_38 ( V_59 , V_37 , V_45 , V_70 ) ;
F_46 ( & V_31 -> V_34 , V_37 , V_74 ,
V_59 , V_75 , V_10 ) ;
F_72 ( V_45 ) ;
V_117:
F_73 ( & V_35 -> V_115 ) ;
F_74 ( V_45 ) ;
return V_86 ;
}
static int F_75 ( struct V_30 * V_31 , int V_57 ,
struct V_9 * V_10 )
{
struct V_9 * V_37 ;
struct V_58 * V_59 ;
int V_38 = 0 ;
int V_33 = 0 ;
int V_121 ;
V_37 = F_30 ( V_31 , 0 , V_57 ) ;
V_59 = & V_31 -> V_60 [ 0 ] [ V_57 ] . V_59 ;
V_121 = F_49 ( V_31 , F_76 ( V_37 ) ,
F_77 ( V_37 ) >> V_46 ,
V_37 , 0 , V_10 , V_59 ) ;
if ( V_121 )
return V_121 ;
F_17 ( V_31 , V_37 , V_10 , V_38 , V_33 ) ;
return 0 ;
}
static int F_78 ( struct V_30 * V_31 ,
struct V_58 * V_59 ,
int V_57 )
{
unsigned int V_33 = V_31 -> V_122 ++ ;
if ( F_79 ( V_31 -> V_122 >= F_1 () ) )
V_31 -> V_122 = 0 ;
if ( V_31 -> V_68 [ V_33 ] ) {
unsigned int V_123 = V_31 -> V_68 [ V_33 ] - 1 ;
V_31 -> V_65 [ V_123 ] &= ~ ( 1ULL << V_33 ) ;
}
V_31 -> V_60 [ 1 ] [ V_57 ] . V_59 . V_13 |= V_62 ;
V_31 -> V_65 [ V_57 ] |= ( V_52 ) 1 << V_33 ;
V_31 -> V_68 [ V_33 ] = V_57 + 1 ;
F_32 ( ! ( V_59 -> V_13 & V_61 ) ) ;
return V_33 ;
}
static int F_80 ( struct V_30 * V_31 ,
V_52 V_75 , T_5 V_81 , struct V_9 * V_37 ,
struct V_9 * V_10 , int V_57 )
{
struct V_58 * V_59 = & V_31 -> V_60 [ 1 ] [ V_57 ] . V_59 ;
int V_33 ;
int V_121 ;
V_121 = F_49 ( V_31 , V_75 , V_81 , V_37 , 1 , V_10 ,
V_59 ) ;
if ( V_121 )
return V_121 ;
if ( F_81 ( V_10 ) == V_49 ) {
V_31 -> V_60 [ 1 ] [ V_57 ] . V_59 . V_13 |= V_63 ;
F_17 ( V_31 , V_37 , V_10 , 0 , 0 ) ;
return 0 ;
}
V_33 = F_78 ( V_31 , V_59 , V_57 ) ;
F_17 ( V_31 , V_37 , V_10 , 1 , V_33 ) ;
return 0 ;
}
void F_82 ( struct V_40 * V_34 , V_52 V_25 , T_8 V_124 ,
unsigned int V_125 )
{
struct V_30 * V_31 = F_23 ( V_34 ) ;
struct V_126 * V_127 ;
struct V_9 * V_37 , V_10 ;
int V_32 = F_83 ( V_125 ) ;
int V_57 = F_84 ( V_125 ) ;
V_37 = F_30 ( V_31 , V_32 , V_57 ) ;
switch ( V_32 ) {
case 0 :
V_127 = & V_31 -> V_60 [ V_32 ] [ V_57 ] ;
if ( ! ( V_127 -> V_59 . V_13 & V_61 ) ) {
F_75 ( V_31 , V_57 , & V_10 ) ;
} else {
F_46 ( V_34 , V_37 , V_49 ,
& V_127 -> V_59 , V_25 , & V_10 ) ;
F_17 ( V_31 , V_37 , & V_10 , 0 , 0 ) ;
}
break;
case 1 : {
T_5 V_81 = V_124 >> V_46 ;
F_80 ( V_31 , V_25 , V_81 , V_37 , & V_10 ,
V_57 ) ;
break;
}
default:
F_85 () ;
break;
}
}
int F_86 ( struct V_40 * V_34 , enum V_128 type ,
T_1 * V_129 )
{
T_9 V_130 ;
T_10 V_131 ;
T_11 V_45 ;
T_12 V_25 ;
T_1 V_16 , V_18 , V_4 ;
V_52 V_132 ;
struct V_133 * V_133 ;
unsigned int V_134 , V_135 ;
bool V_76 ;
unsigned long V_13 ;
V_130 = F_87 ( V_34 ) ;
V_134 = ( V_34 -> V_36 . V_43 -> V_77 & V_136 ) >> V_137 ;
F_5 ( V_13 ) ;
F_6 ( V_27 , ( V_34 -> V_36 . V_138 << V_139 ) | V_134 ) ;
F_6 ( V_140 , V_141 | F_88 ( V_34 ) ) ;
asm volatile("tlbsx 0, %[geaddr]\n" : :
[geaddr] "r" (geaddr));
F_6 ( V_140 , 0 ) ;
F_6 ( V_22 , 0 ) ;
V_16 = F_12 ( V_15 ) ;
V_18 = F_12 ( V_17 ) ;
V_4 = F_12 ( V_19 ) ;
#ifdef F_89
V_132 = F_12 ( V_142 ) ;
#else
V_132 = ( ( V_52 ) F_12 ( V_21 ) << 32 ) | V_4 ;
#endif
F_9 ( V_13 ) ;
if ( ! ( V_16 & V_47 ) )
return V_143 ;
V_76 = V_34 -> V_36 . V_43 -> V_77 & V_78 ;
if ( F_79 ( ( V_76 && ! ( V_4 & V_144 ) ) ||
( ! V_76 && ! ( V_4 & V_145 ) ) ) ) {
F_71 (
L_4 ,
V_64 , V_130 ) ;
return V_143 ;
}
if ( F_90 ( V_34 , V_146 ) &&
F_79 ( ( V_18 & V_147 ) || ( V_18 & V_148 ) || ! ( V_18 & V_51 ) ) ) {
F_71 (
L_5 ,
V_64 , V_130 ) ;
return V_143 ;
}
V_135 = F_91 ( V_16 ) + 10 ;
V_131 = ( V_132 & ( ~ 0ULL << V_135 ) ) |
( V_130 & ( ( 1ULL << V_135 ) - 1ULL ) ) ;
V_45 = V_131 >> V_46 ;
if ( F_79 ( ! F_92 ( V_45 ) ) ) {
F_71 ( L_6 ,
V_64 , V_131 ) ;
return V_143 ;
}
V_133 = F_26 ( V_45 ) ;
V_25 = ( unsigned long ) F_93 ( V_133 ) ;
* V_129 = * ( T_1 * ) ( V_25 | ( unsigned long ) ( V_131 & ~ V_44 ) ) ;
F_94 ( ( T_1 * ) V_25 ) ;
return V_149 ;
}
int F_86 ( struct V_40 * V_34 , enum V_128 type ,
T_1 * V_129 )
{
return V_143 ;
}
int F_95 ( struct V_35 * V_35 , unsigned long V_84 )
{
F_96 ( V_84 ) ;
F_97 ( V_35 ) ;
return 0 ;
}
int F_98 ( struct V_35 * V_35 , unsigned long V_100 , unsigned long V_101 )
{
F_95 ( V_35 , V_100 ) ;
return 0 ;
}
int F_99 ( struct V_35 * V_35 , unsigned long V_100 , unsigned long V_101 )
{
return 0 ;
}
int F_100 ( struct V_35 * V_35 , unsigned long V_84 )
{
return 0 ;
}
void F_101 ( struct V_35 * V_35 , unsigned long V_84 , T_6 V_118 )
{
F_95 ( V_35 , V_84 ) ;
}
int F_102 ( struct V_30 * V_31 )
{
V_1 [ 0 ] . V_2 = F_12 ( V_150 ) & V_151 ;
V_1 [ 1 ] . V_2 = F_12 ( V_152 ) & V_151 ;
if ( V_1 [ 0 ] . V_2 == 0 ||
V_1 [ 1 ] . V_2 == 0 ) {
F_64 ( L_7 , V_64 ) ;
return - V_153 ;
}
V_1 [ 0 ] . V_154 = ( F_12 ( V_150 ) & V_155 ) >>
V_156 ;
V_1 [ 1 ] . V_154 = V_1 [ 1 ] . V_2 ;
if ( ! F_103 ( V_1 [ 0 ] . V_2 ) ||
! F_103 ( V_1 [ 0 ] . V_154 ) ||
V_1 [ 0 ] . V_2 < V_1 [ 0 ] . V_154 ||
V_1 [ 0 ] . V_154 == 0 ) {
F_64 ( L_8 ,
V_64 , V_1 [ 0 ] . V_2 ,
V_1 [ 0 ] . V_154 ) ;
return - V_153 ;
}
V_1 [ 0 ] . V_157 =
V_1 [ 0 ] . V_2 / V_1 [ 0 ] . V_154 ;
V_1 [ 1 ] . V_157 = 1 ;
V_31 -> V_68 = F_104 ( sizeof( unsigned int ) *
V_1 [ 1 ] . V_2 ,
V_158 ) ;
if ( ! V_31 -> V_68 )
return - V_114 ;
return 0 ;
}
void F_105 ( struct V_30 * V_31 )
{
F_106 ( V_31 -> V_68 ) ;
}
