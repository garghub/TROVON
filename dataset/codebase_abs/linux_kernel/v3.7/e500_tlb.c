static inline unsigned int F_1 (
struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = V_2 -> V_4 [ 0 ] ++ ;
if ( F_2 ( V_2 -> V_4 [ 0 ] >= V_2 -> V_5 [ 0 ] . V_6 ) )
V_2 -> V_4 [ 0 ] = 0 ;
return V_3 ;
}
static inline unsigned int F_3 ( void )
{
return V_7 [ 1 ] . V_8 - V_9 - 1 ;
}
static inline int F_4 ( struct V_10 * V_11 )
{
return V_11 -> V_12 & ( V_13 | V_14 ) ;
}
static inline T_1 F_5 ( T_1 V_15 , int V_16 )
{
V_15 &= V_17 ;
#ifndef F_6
if ( ! V_16 ) {
V_15 &= ~ V_18 ;
V_15 |= ( V_15 & V_19 ) << 1 ;
}
V_15 |= V_19 ;
#endif
return V_15 ;
}
static inline T_1 F_7 ( T_1 V_20 , int V_16 )
{
#ifdef F_8
return ( V_20 & V_21 ) | V_22 ;
#else
return V_20 & V_21 ;
#endif
}
static inline void F_9 ( struct V_10 * V_23 ,
T_2 V_24 )
{
unsigned long V_25 ;
F_10 ( V_25 ) ;
F_11 ( V_26 , V_24 ) ;
F_11 ( V_27 , V_23 -> V_28 ) ;
F_11 ( V_29 , ( unsigned long ) V_23 -> V_20 ) ;
F_11 ( V_30 , ( T_1 ) V_23 -> V_12 ) ;
F_11 ( V_31 , ( T_1 ) ( V_23 -> V_12 >> 32 ) ) ;
#ifdef F_6
F_11 ( V_32 , V_23 -> V_33 ) ;
#endif
asm volatile("isync; tlbwe" : : : "memory");
#ifdef F_6
F_11 ( V_32 , 0 ) ;
F_12 () ;
#endif
F_13 ( V_25 ) ;
F_14 ( V_24 , V_23 -> V_33 , V_23 -> V_28 ,
V_23 -> V_20 , V_23 -> V_12 ) ;
}
static T_1 F_15 ( unsigned long V_34 )
{
unsigned long V_25 ;
T_1 V_24 ;
F_10 ( V_25 ) ;
F_11 ( V_35 , 0 ) ;
asm volatile("tlbsx 0, %0" : : "b" (eaddr & ~CONFIG_PAGE_OFFSET));
V_24 = F_16 ( V_26 ) ;
F_13 ( V_25 ) ;
return V_24 ;
}
static inline void F_17 ( struct V_1 * V_2 ,
int V_36 , int V_37 , struct V_10 * V_23 )
{
T_1 V_24 ;
if ( V_36 == 0 ) {
V_24 = F_15 ( V_23 -> V_20 ) ;
F_9 ( V_23 , V_24 ) ;
} else {
F_9 ( V_23 ,
F_18 ( 1 ) |
F_19 ( F_20 ( V_37 ) ) ) ;
}
}
void F_21 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
struct V_10 V_40 ;
T_3 V_41 = ( ( T_3 ) V_39 -> V_42 . V_43 ) & V_44 ;
unsigned int V_45 ;
T_4 V_46 ;
V_46 = ( T_4 ) F_23 ( ( void * ) V_41 ) >> V_47 ;
F_24 ( F_25 ( V_46 ) ) ;
F_26 () ;
V_45 = F_27 ( V_2 , 0 , 0 , 0 , 0 ) ;
V_40 . V_28 = V_48 | V_49 | F_28 ( V_45 ) |
F_29 ( V_50 ) ;
V_40 . V_20 = V_39 -> V_42 . V_51 | V_22 ;
V_40 . V_12 = ( ( V_52 ) V_46 << V_47 ) |
V_13 | V_53 | V_14 | V_54 ;
V_40 . V_33 = 0 ;
F_9 ( & V_40 , F_18 ( 1 ) | F_19 ( V_9 ) ) ;
F_30 () ;
}
static void F_31 ( struct V_1 * V_2 ,
int V_36 , int V_55 )
{
struct V_10 * V_56 =
F_32 ( V_2 , V_36 , V_55 ) ;
if ( V_36 == 1 &&
V_2 -> V_57 [ 1 ] [ V_55 ] . V_58 . V_25 & V_59 ) {
V_52 V_60 = V_2 -> V_61 [ V_55 ] ;
int V_62 ;
unsigned long V_25 ;
F_10 ( V_25 ) ;
while ( V_60 ) {
V_62 = F_33 ( V_60 & - V_60 ) ;
F_11 ( V_26 ,
F_18 ( 1 ) |
F_19 ( F_20 ( V_62 ) ) ) ;
F_11 ( V_27 , 0 ) ;
asm volatile("tlbwe");
V_2 -> V_63 [ V_62 ] = 0 ;
V_60 &= V_60 - 1 ;
}
F_34 () ;
V_2 -> V_61 [ V_55 ] = 0 ;
V_2 -> V_57 [ 1 ] [ V_55 ] . V_58 . V_25 &= ~ V_59 ;
F_13 ( V_25 ) ;
return;
}
F_35 ( V_2 , V_56 ) ;
}
static int F_36 ( T_5 V_64 , int V_65 , int V_6 )
{
int V_66 ;
V_66 = ( V_64 >> V_47 ) & ( V_65 - 1 ) ;
V_66 *= V_6 ;
return V_66 ;
}
static int F_37 ( struct V_1 * V_2 , T_5 V_64 )
{
return F_36 ( V_64 , V_2 -> V_5 [ 0 ] . V_65 ,
V_2 -> V_5 [ 0 ] . V_6 ) ;
}
static unsigned int F_38 ( struct V_38 * V_39 , int V_36 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
int V_55 = F_39 ( V_39 ) ;
if ( V_36 == 0 ) {
V_55 &= V_2 -> V_5 [ 0 ] . V_6 - 1 ;
V_55 += F_37 ( V_2 , V_39 -> V_42 . V_43 -> V_20 ) ;
} else {
V_55 &= V_2 -> V_5 [ V_36 ] . V_8 - 1 ;
}
return V_55 ;
}
static int F_40 ( struct V_1 * V_2 ,
T_5 V_34 , int V_36 , unsigned int V_67 , int V_68 )
{
int V_69 = V_2 -> V_5 [ V_36 ] . V_8 ;
unsigned int V_66 , V_70 ;
int V_71 ;
if ( V_36 == 0 ) {
V_66 = F_37 ( V_2 , V_34 ) ;
V_69 = V_2 -> V_5 [ 0 ] . V_6 ;
} else {
if ( V_34 < V_2 -> V_72 ||
V_34 > V_2 -> V_73 )
return - 1 ;
V_66 = 0 ;
}
V_70 = V_2 -> V_74 [ V_36 ] ;
for ( V_71 = 0 ; V_71 < V_69 ; V_71 ++ ) {
struct V_10 * V_11 =
& V_2 -> V_75 [ V_70 + V_66 + V_71 ] ;
unsigned int V_76 ;
if ( V_34 < F_41 ( V_11 ) )
continue;
if ( V_34 > F_42 ( V_11 ) )
continue;
V_76 = F_43 ( V_11 ) ;
if ( V_76 && ( V_76 != V_67 ) )
continue;
if ( ! F_44 ( V_11 ) )
continue;
if ( F_45 ( V_11 ) != V_68 && V_68 != - 1 )
continue;
return V_66 + V_71 ;
}
return - 1 ;
}
static inline void F_46 ( struct V_77 * V_58 ,
struct V_10 * V_56 ,
T_4 V_46 )
{
V_58 -> V_46 = V_46 ;
V_58 -> V_25 = V_78 ;
if ( F_4 ( V_56 ) )
V_58 -> V_25 |= V_79 ;
}
static inline void F_47 ( struct V_77 * V_58 )
{
if ( V_58 -> V_25 & V_78 ) {
if ( V_58 -> V_25 & V_79 )
F_48 ( V_58 -> V_46 ) ;
else
F_49 ( V_58 -> V_46 ) ;
V_58 -> V_25 = 0 ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_61 )
memset ( V_2 -> V_61 , 0 ,
sizeof( V_52 ) * V_2 -> V_5 [ 1 ] . V_8 ) ;
if ( V_2 -> V_63 )
memset ( V_2 -> V_63 , 0 ,
sizeof( unsigned int ) * V_7 [ 1 ] . V_8 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
int V_36 = 0 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_5 [ V_36 ] . V_8 ; V_71 ++ ) {
struct V_77 * V_58 =
& V_2 -> V_57 [ V_36 ] [ V_71 ] . V_58 ;
F_47 ( V_58 ) ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
int V_80 = 1 ;
int V_71 ;
F_53 ( V_2 ) ;
for ( V_71 = 0 ; V_71 < V_7 [ V_80 ] . V_8 ; V_71 ++ ) {
struct V_77 * V_58 =
& V_2 -> V_81 [ V_80 ] [ V_71 ] ;
F_47 ( V_58 ) ;
}
F_51 ( V_2 ) ;
}
static inline void F_54 ( struct V_38 * V_39 ,
unsigned int V_34 , int V_68 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
unsigned int V_3 , V_82 ;
int V_36 ;
V_36 = ( V_39 -> V_42 . V_43 -> V_83 >> 28 ) & 0x1 ;
V_3 = ( V_36 == 0 ) ? F_1 ( V_2 ) : 0 ;
V_82 = ( V_39 -> V_42 . V_43 -> V_83 >> 7 ) & 0x1f ;
V_39 -> V_42 . V_43 -> V_24 = F_18 ( V_36 ) | F_19 ( V_3 )
| F_55 ( V_2 -> V_4 [ V_36 ] ) ;
V_39 -> V_42 . V_43 -> V_28 = V_48 | ( V_68 ? V_49 : 0 )
| F_28 ( F_56 ( V_39 ) )
| F_29 ( V_82 ) ;
V_39 -> V_42 . V_43 -> V_20 = ( V_34 & V_84 )
| ( V_39 -> V_42 . V_43 -> V_83 & V_21 ) ;
V_39 -> V_42 . V_43 -> V_12 &= V_85 | V_86 | V_87 | V_88 ;
V_39 -> V_42 . V_43 -> V_89 = ( V_39 -> V_42 . V_43 -> V_89 & V_90 )
| ( F_57 ( V_39 ) << 16 )
| ( V_68 ? V_91 : 0 ) ;
}
static inline void F_58 (
struct V_38 * V_39 ,
struct V_10 * V_56 ,
int V_92 , struct V_77 * V_58 , V_52 V_93 ,
struct V_10 * V_23 )
{
T_4 V_46 = V_58 -> V_46 ;
T_1 V_94 = V_39 -> V_42 . V_43 -> V_95 & V_96 ;
F_59 ( ! ( V_58 -> V_25 & V_78 ) ) ;
V_23 -> V_28 = F_29 ( V_92 ) | F_60 ( V_56 ) | V_48 ;
V_23 -> V_20 = ( V_93 & V_84 ) |
F_7 ( V_56 -> V_20 , V_94 ) ;
V_23 -> V_12 = ( ( V_52 ) V_46 << V_47 ) |
F_5 ( V_56 -> V_12 , V_94 ) ;
#ifdef F_6
V_23 -> V_33 = V_97 | V_39 -> V_98 -> V_42 . V_99 ;
#endif
}
static inline void F_61 ( struct V_1 * V_2 ,
V_52 V_93 , T_6 V_100 , struct V_10 * V_56 ,
int V_36 , struct V_10 * V_23 ,
struct V_77 * V_58 )
{
struct V_101 * V_102 ;
unsigned long V_46 , V_103 ;
int V_104 = 0 ;
int V_92 = V_50 ;
V_102 = F_62 ( V_2 -> V_39 . V_98 , V_100 ) ;
V_103 = F_63 ( V_102 , V_100 ) ;
if ( V_36 == 1 ) {
struct V_105 * V_106 ;
F_64 ( & V_107 -> V_108 -> V_109 ) ;
V_106 = F_65 ( V_107 -> V_108 , V_103 ) ;
if ( V_106 && V_103 >= V_106 -> V_110 &&
( V_106 -> V_111 & V_112 ) ) {
unsigned long V_113 , V_114 ;
unsigned long V_115 , V_116 ;
V_104 = 1 ;
V_113 = V_106 -> V_117 ;
V_114 = V_113 +
( ( V_106 -> V_118 - V_106 -> V_110 ) >> V_47 ) ;
V_46 = V_113 + ( ( V_103 - V_106 -> V_110 ) >> V_47 ) ;
V_115 = V_46 - ( V_100 - V_102 -> V_119 ) ;
V_116 = V_115 + V_102 -> V_120 ;
if ( V_113 < V_115 )
V_113 = V_115 ;
if ( V_114 > V_116 )
V_114 = V_116 ;
V_92 = ( V_56 -> V_28 & V_121 ) >>
V_122 ;
V_92 = F_66 ( V_50 , V_92 & ~ 1 ) ;
for (; V_92 > V_50 ; V_92 -= 2 ) {
unsigned long V_123 , V_124 , V_125 ;
V_125 = 1 << ( V_92 - 2 ) ;
V_123 = V_100 & ~ ( V_125 - 1 ) ;
V_124 = V_123 + V_125 ;
if ( V_123 + V_46 - V_100 < V_113 )
continue;
if ( V_124 + V_46 - V_100 > V_114 )
continue;
if ( ( V_100 & ( V_125 - 1 ) ) !=
( V_46 & ( V_125 - 1 ) ) )
continue;
V_93 &= ~ ( ( V_125 << V_47 ) - 1 ) ;
V_46 &= ~ ( V_125 - 1 ) ;
break;
}
} else if ( V_106 && V_103 >= V_106 -> V_110 &&
( V_106 -> V_111 & V_126 ) ) {
unsigned long V_127 = F_67 ( V_106 ) ;
V_92 = ( V_56 -> V_28 & V_121 ) >>
V_122 ;
V_92 = F_68 ( F_69 ( V_127 ) - 10 , V_92 ) ;
V_92 = F_66 ( V_50 , V_92 & ~ 1 ) ;
}
F_70 ( & V_107 -> V_108 -> V_109 ) ;
}
if ( F_71 ( ! V_104 ) ) {
unsigned long V_125 = 1 << ( V_92 + 10 - V_47 ) ;
V_46 = F_72 ( V_102 , V_100 ) ;
if ( F_73 ( V_46 ) ) {
F_74 ( V_128 L_1 ,
( long ) V_100 ) ;
return;
}
V_46 &= ~ ( V_125 - 1 ) ;
V_93 &= ~ ( ( V_125 << V_47 ) - 1 ) ;
}
F_47 ( V_58 ) ;
F_46 ( V_58 , V_56 , V_46 ) ;
F_58 ( & V_2 -> V_39 , V_56 , V_92 ,
V_58 , V_93 , V_23 ) ;
F_75 ( V_46 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
int V_55 ,
struct V_10 * V_23 )
{
struct V_10 * V_56 ;
struct V_77 * V_58 ;
V_56 = F_32 ( V_2 , 0 , V_55 ) ;
V_58 = & V_2 -> V_57 [ 0 ] [ V_55 ] . V_58 ;
F_61 ( V_2 , F_41 ( V_56 ) ,
F_77 ( V_56 ) >> V_47 ,
V_56 , 0 , V_23 , V_58 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
V_52 V_93 , T_6 V_100 , struct V_10 * V_56 ,
struct V_10 * V_23 , int V_55 )
{
struct V_77 * V_58 ;
unsigned int V_3 ;
V_3 = V_2 -> V_129 ++ ;
if ( F_2 ( V_2 -> V_129 >= F_3 () ) )
V_2 -> V_129 = 0 ;
V_58 = & V_2 -> V_81 [ 1 ] [ V_3 ] ;
F_61 ( V_2 , V_93 , V_100 , V_56 , 1 , V_23 , V_58 ) ;
V_2 -> V_61 [ V_55 ] |= ( V_52 ) 1 << V_3 ;
V_2 -> V_57 [ 1 ] [ V_55 ] . V_58 . V_25 |= V_59 ;
if ( V_2 -> V_63 [ V_3 ] ) {
unsigned int V_130 = V_2 -> V_63 [ V_3 ] ;
V_2 -> V_61 [ V_130 ] &= ~ ( 1ULL << V_3 ) ;
}
V_2 -> V_63 [ V_3 ] = V_55 ;
return V_3 ;
}
static void F_79 ( struct V_1 * V_2 )
{
int V_69 = V_2 -> V_5 [ 1 ] . V_8 ;
unsigned int V_70 ;
T_5 V_34 ;
int V_71 ;
V_2 -> V_72 = ~ 0UL ;
V_2 -> V_73 = 0 ;
V_70 = V_2 -> V_74 [ 1 ] ;
for ( V_71 = 0 ; V_71 < V_69 ; V_71 ++ ) {
struct V_10 * V_11 =
& V_2 -> V_75 [ V_70 + V_71 ] ;
if ( ! F_44 ( V_11 ) )
continue;
V_34 = F_41 ( V_11 ) ;
V_2 -> V_72 =
F_68 ( V_2 -> V_72 , V_34 ) ;
V_34 = F_42 ( V_11 ) ;
V_2 -> V_73 =
F_66 ( V_2 -> V_73 , V_34 ) ;
}
}
static int F_80 ( struct V_1 * V_2 ,
struct V_10 * V_56 )
{
unsigned long V_113 , V_114 , V_69 ;
V_69 = F_81 ( V_56 ) ;
V_113 = F_41 ( V_56 ) & ~ ( V_69 - 1 ) ;
V_114 = V_113 + V_69 - 1 ;
return V_2 -> V_72 == V_113 ||
V_2 -> V_73 == V_114 ;
}
static void F_82 ( struct V_38 * V_39 ,
struct V_10 * V_56 )
{
unsigned long V_113 , V_114 , V_69 ;
struct V_1 * V_2 = F_22 ( V_39 ) ;
if ( ! F_44 ( V_56 ) )
return;
V_69 = F_81 ( V_56 ) ;
V_113 = F_41 ( V_56 ) & ~ ( V_69 - 1 ) ;
V_114 = V_113 + V_69 - 1 ;
V_2 -> V_72 = F_68 ( V_2 -> V_72 , V_113 ) ;
V_2 -> V_73 = F_66 ( V_2 -> V_73 , V_114 ) ;
}
static inline int F_83 (
struct V_1 * V_2 ,
int V_36 , int V_55 )
{
struct V_10 * V_56 =
F_32 ( V_2 , V_36 , V_55 ) ;
if ( F_2 ( F_84 ( V_56 ) ) )
return - 1 ;
if ( V_36 == 1 && F_80 ( V_2 , V_56 ) )
F_79 ( V_2 ) ;
V_56 -> V_28 = 0 ;
return 0 ;
}
int F_85 ( struct V_1 * V_2 , T_3 V_131 )
{
int V_55 ;
if ( V_131 & V_132 )
for ( V_55 = 0 ; V_55 < V_2 -> V_5 [ 0 ] . V_8 ; V_55 ++ )
F_83 ( V_2 , 0 , V_55 ) ;
if ( V_131 & V_133 )
for ( V_55 = 0 ; V_55 < V_2 -> V_5 [ 1 ] . V_8 ; V_55 ++ )
F_83 ( V_2 , 1 , V_55 ) ;
F_53 ( V_2 ) ;
return V_134 ;
}
int F_86 ( struct V_38 * V_39 , int V_135 , int V_136 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
unsigned int V_137 ;
int V_55 , V_36 ;
T_5 V_138 ;
V_138 = ( ( V_135 ) ? F_87 ( V_39 , V_135 ) : 0 ) + F_87 ( V_39 , V_136 ) ;
V_137 = ( V_138 >> 2 ) & 0x1 ;
V_36 = ( V_138 >> 3 ) & 0x1 ;
if ( V_137 ) {
for ( V_55 = 0 ; V_55 < V_2 -> V_5 [ V_36 ] . V_8 ;
V_55 ++ )
F_83 ( V_2 , V_36 , V_55 ) ;
} else {
V_138 &= 0xfffff000 ;
V_55 = F_40 ( V_2 , V_138 , V_36 ,
F_57 ( V_39 ) , - 1 ) ;
if ( V_55 >= 0 )
F_83 ( V_2 , V_36 , V_55 ) ;
}
F_53 ( V_2 ) ;
return V_134 ;
}
static void F_88 ( struct V_1 * V_2 , int V_36 ,
int V_67 , int V_139 )
{
struct V_10 * V_11 ;
int V_76 , V_55 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_5 [ V_36 ] . V_8 ; V_55 ++ ) {
V_11 = F_32 ( V_2 , V_36 , V_55 ) ;
V_76 = F_43 ( V_11 ) ;
if ( V_139 == 0 || V_76 == V_67 ) {
F_31 ( V_2 , V_36 , V_55 ) ;
F_83 ( V_2 , V_36 , V_55 ) ;
}
}
}
static void F_89 ( struct V_1 * V_2 , int V_67 ,
int V_135 , int V_136 )
{
int V_36 , V_55 ;
T_5 V_138 ;
V_138 = F_87 ( & V_2 -> V_39 , V_136 ) ;
if ( V_135 )
V_138 += F_87 ( & V_2 -> V_39 , V_135 ) ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_55 = F_40 ( V_2 , V_138 , V_36 , V_67 , - 1 ) ;
if ( V_55 >= 0 ) {
F_31 ( V_2 , V_36 , V_55 ) ;
F_83 ( V_2 , V_36 , V_55 ) ;
break;
}
}
}
int F_90 ( struct V_38 * V_39 , int V_139 , int V_135 , int V_136 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
int V_67 = F_91 ( V_39 ) ;
if ( V_139 == 0 || V_139 == 1 ) {
F_88 ( V_2 , 0 , V_67 , V_139 ) ;
F_88 ( V_2 , 1 , V_67 , V_139 ) ;
} else if ( V_139 == 3 ) {
F_89 ( V_2 , V_67 , V_135 , V_136 ) ;
}
return V_134 ;
}
int F_92 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
int V_36 , V_55 ;
struct V_10 * V_56 ;
V_36 = F_93 ( V_39 ) ;
V_55 = F_38 ( V_39 , V_36 ) ;
V_56 = F_32 ( V_2 , V_36 , V_55 ) ;
V_39 -> V_42 . V_43 -> V_24 &= ~ F_55 ( ~ 0 ) ;
V_39 -> V_42 . V_43 -> V_24 |= F_55 ( V_2 -> V_4 [ V_36 ] ) ;
V_39 -> V_42 . V_43 -> V_28 = V_56 -> V_28 ;
V_39 -> V_42 . V_43 -> V_20 = V_56 -> V_20 ;
V_39 -> V_42 . V_43 -> V_12 = V_56 -> V_12 ;
return V_134 ;
}
int F_94 ( struct V_38 * V_39 , int V_136 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
int V_68 = ! ! F_95 ( V_39 ) ;
unsigned int V_67 = F_91 ( V_39 ) ;
int V_55 , V_36 ;
struct V_10 * V_56 = NULL ;
T_5 V_138 ;
V_138 = F_87 ( V_39 , V_136 ) ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_55 = F_40 ( V_2 , V_138 , V_36 , V_67 , V_68 ) ;
if ( V_55 >= 0 ) {
V_56 = F_32 ( V_2 , V_36 , V_55 ) ;
break;
}
}
if ( V_56 ) {
V_55 &= V_2 -> V_5 [ V_36 ] . V_6 - 1 ;
V_39 -> V_42 . V_43 -> V_24 = F_18 ( V_36 ) | F_19 ( V_55 )
| F_55 ( V_2 -> V_4 [ V_36 ] ) ;
V_39 -> V_42 . V_43 -> V_28 = V_56 -> V_28 ;
V_39 -> V_42 . V_43 -> V_20 = V_56 -> V_20 ;
V_39 -> V_42 . V_43 -> V_12 = V_56 -> V_12 ;
} else {
int V_3 ;
V_36 = V_39 -> V_42 . V_43 -> V_83 >> 28 & 0x1 ;
V_3 = ( V_36 == 0 ) ? F_1 ( V_2 ) : 0 ;
V_39 -> V_42 . V_43 -> V_24 = F_18 ( V_36 )
| F_19 ( V_3 )
| F_55 ( V_2 -> V_4 [ V_36 ] ) ;
V_39 -> V_42 . V_43 -> V_28 =
( V_39 -> V_42 . V_43 -> V_89 & V_140 )
| ( V_39 -> V_42 . V_43 -> V_89 & ( V_91 ? V_49 : 0 ) )
| ( V_39 -> V_42 . V_43 -> V_83 & F_96 ( ~ 0 ) ) ;
V_39 -> V_42 . V_43 -> V_20 &= V_84 ;
V_39 -> V_42 . V_43 -> V_20 |= V_39 -> V_42 . V_43 -> V_83 &
V_21 ;
V_39 -> V_42 . V_43 -> V_12 &= V_85 | V_86 |
V_87 | V_88 ;
}
F_97 ( V_39 , V_141 ) ;
return V_134 ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_10 * V_56 ,
struct V_10 * V_23 ,
int V_80 , int V_37 )
{
int V_45 ;
F_26 () ;
V_45 = F_99 ( & V_2 -> V_39 , V_56 ) ;
V_23 -> V_28 |= F_28 ( V_45 ) ;
F_17 ( V_2 , V_80 , V_37 , V_23 ) ;
F_30 () ;
}
int F_100 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
struct V_10 * V_56 , V_23 ;
int V_36 , V_55 , V_80 , V_37 ;
int V_142 = 0 ;
V_36 = F_93 ( V_39 ) ;
V_55 = F_38 ( V_39 , V_36 ) ;
V_56 = F_32 ( V_2 , V_36 , V_55 ) ;
if ( F_44 ( V_56 ) ) {
F_31 ( V_2 , V_36 , V_55 ) ;
if ( ( V_36 == 1 ) &&
F_80 ( V_2 , V_56 ) )
V_142 = 1 ;
}
V_56 -> V_28 = V_39 -> V_42 . V_43 -> V_28 ;
V_56 -> V_20 = V_39 -> V_42 . V_43 -> V_20 ;
V_56 -> V_12 = V_39 -> V_42 . V_43 -> V_12 ;
F_101 ( V_39 -> V_42 . V_43 -> V_24 , V_56 -> V_28 ,
V_56 -> V_20 , V_56 -> V_12 ) ;
if ( V_36 == 1 ) {
if ( V_142 )
F_79 ( V_2 ) ;
else
F_82 ( V_39 , V_56 ) ;
}
if ( F_102 ( V_39 , V_56 ) ) {
V_52 V_34 ;
V_52 V_143 ;
switch ( V_36 ) {
case 0 :
V_56 -> V_28 &= ~ F_29 ( ~ 0 ) ;
V_56 -> V_28 |= F_29 ( V_50 ) ;
V_80 = 0 ;
F_76 ( V_2 , V_55 , & V_23 ) ;
V_37 = 0 ;
break;
case 1 :
V_34 = F_41 ( V_56 ) ;
V_143 = F_77 ( V_56 ) ;
V_80 = 1 ;
V_37 = F_78 ( V_2 , V_34 ,
V_143 >> V_47 , V_56 , & V_23 , V_55 ) ;
break;
default:
F_103 () ;
}
F_98 ( V_2 , V_56 , & V_23 , V_80 , V_37 ) ;
}
F_97 ( V_39 , V_144 ) ;
return V_134 ;
}
static int F_104 ( struct V_38 * V_39 ,
T_5 V_34 , unsigned int V_67 , int V_68 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
int V_55 , V_36 ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_55 = F_40 ( V_2 , V_34 , V_36 , V_67 , V_68 ) ;
if ( V_55 >= 0 )
return F_105 ( V_36 , V_55 ) ;
}
return - 1 ;
}
int F_106 ( struct V_38 * V_39 ,
struct V_145 * V_146 )
{
int V_147 ;
T_5 V_34 ;
T_7 V_67 ;
T_7 V_68 ;
V_34 = V_146 -> V_148 ;
V_67 = ( V_146 -> V_148 >> 32 ) & 0xff ;
V_68 = ( V_146 -> V_148 >> 40 ) & 0x1 ;
V_147 = F_104 ( V_39 , V_34 , V_67 , V_68 ) ;
if ( V_147 < 0 ) {
V_146 -> V_149 = 0 ;
return 0 ;
}
V_146 -> V_150 = F_107 ( V_39 , V_147 , V_34 ) ;
V_146 -> V_149 = 1 ;
return 0 ;
}
int F_108 ( struct V_38 * V_39 , T_5 V_34 )
{
unsigned int V_68 = ! ! ( V_39 -> V_42 . V_43 -> V_95 & V_151 ) ;
return F_104 ( V_39 , V_34 , F_57 ( V_39 ) , V_68 ) ;
}
int F_109 ( struct V_38 * V_39 , T_5 V_34 )
{
unsigned int V_68 = ! ! ( V_39 -> V_42 . V_43 -> V_95 & V_152 ) ;
return F_104 ( V_39 , V_34 , F_57 ( V_39 ) , V_68 ) ;
}
void F_110 ( struct V_38 * V_39 )
{
unsigned int V_68 = ! ! ( V_39 -> V_42 . V_43 -> V_95 & V_151 ) ;
F_54 ( V_39 , V_39 -> V_42 . V_153 , V_68 ) ;
}
void F_111 ( struct V_38 * V_39 )
{
unsigned int V_68 = ! ! ( V_39 -> V_42 . V_43 -> V_95 & V_152 ) ;
F_54 ( V_39 , V_39 -> V_42 . V_154 , V_68 ) ;
}
T_8 F_107 ( struct V_38 * V_39 , unsigned int V_147 ,
T_5 V_34 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
struct V_10 * V_56 ;
V_52 V_155 ;
V_56 = F_32 ( V_2 , F_112 ( V_147 ) , F_113 ( V_147 ) ) ;
V_155 = F_81 ( V_56 ) - 1 ;
return F_77 ( V_56 ) | ( V_34 & V_155 ) ;
}
void F_114 ( struct V_38 * V_39 )
{
}
void F_115 ( struct V_38 * V_39 , V_52 V_34 , T_8 V_156 ,
unsigned int V_147 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
struct V_157 * V_158 ;
struct V_10 * V_56 , V_23 ;
int V_36 = F_112 ( V_147 ) ;
int V_55 = F_113 ( V_147 ) ;
int V_80 , V_37 ;
V_56 = F_32 ( V_2 , V_36 , V_55 ) ;
switch ( V_36 ) {
case 0 :
V_80 = 0 ;
V_37 = 0 ;
V_158 = & V_2 -> V_57 [ V_36 ] [ V_55 ] ;
F_58 ( V_39 , V_56 , V_50 ,
& V_158 -> V_58 , V_34 , & V_23 ) ;
break;
case 1 : {
T_6 V_100 = V_156 >> V_47 ;
V_80 = 1 ;
V_37 = F_78 ( V_2 , V_34 , V_100 ,
V_56 , & V_23 , V_55 ) ;
break;
}
default:
F_103 () ;
break;
}
F_98 ( V_2 , V_56 , & V_23 , V_80 , V_37 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
int V_71 ;
F_50 ( V_2 ) ;
F_117 ( V_2 -> V_61 ) ;
F_52 ( V_2 ) ;
F_117 ( V_2 -> V_57 [ 0 ] ) ;
F_117 ( V_2 -> V_57 [ 1 ] ) ;
if ( V_2 -> V_159 ) {
F_118 ( ( void * ) ( F_119 ( ( V_160 ) V_2 -> V_75 ,
V_161 ) ) ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_162 ; V_71 ++ ) {
F_120 ( V_2 -> V_159 [ V_71 ] ) ;
F_121 ( V_2 -> V_159 [ V_71 ] ) ;
}
V_2 -> V_162 = 0 ;
V_2 -> V_159 = NULL ;
} else {
F_117 ( V_2 -> V_75 ) ;
}
V_2 -> V_75 = NULL ;
}
void F_122 ( struct V_38 * V_39 , struct V_163 * V_164 )
{
V_164 -> V_165 . V_166 . V_24 = V_39 -> V_42 . V_43 -> V_24 ;
V_164 -> V_165 . V_166 . V_28 = V_39 -> V_42 . V_43 -> V_28 ;
V_164 -> V_165 . V_166 . V_20 = V_39 -> V_42 . V_43 -> V_20 ;
V_164 -> V_165 . V_166 . V_12 = V_39 -> V_42 . V_43 -> V_12 ;
V_164 -> V_165 . V_166 . V_83 = V_39 -> V_42 . V_43 -> V_83 ;
V_164 -> V_165 . V_166 . V_89 = V_39 -> V_42 . V_43 -> V_89 ;
V_164 -> V_165 . V_166 . V_167 = V_39 -> V_42 . V_167 ;
V_164 -> V_165 . V_166 . V_168 [ 0 ] = V_39 -> V_42 . V_168 [ 0 ] ;
V_164 -> V_165 . V_166 . V_168 [ 1 ] = V_39 -> V_42 . V_168 [ 1 ] ;
V_164 -> V_165 . V_166 . V_168 [ 2 ] = 0 ;
V_164 -> V_165 . V_166 . V_168 [ 3 ] = 0 ;
}
int F_123 ( struct V_38 * V_39 , struct V_163 * V_164 )
{
if ( V_164 -> V_165 . V_166 . V_169 & V_170 ) {
V_39 -> V_42 . V_43 -> V_24 = V_164 -> V_165 . V_166 . V_24 ;
V_39 -> V_42 . V_43 -> V_28 = V_164 -> V_165 . V_166 . V_28 ;
V_39 -> V_42 . V_43 -> V_20 = V_164 -> V_165 . V_166 . V_20 ;
V_39 -> V_42 . V_43 -> V_12 = V_164 -> V_165 . V_166 . V_12 ;
V_39 -> V_42 . V_43 -> V_83 = V_164 -> V_165 . V_166 . V_83 ;
V_39 -> V_42 . V_43 -> V_89 = V_164 -> V_165 . V_166 . V_89 ;
}
return 0 ;
}
int F_124 ( struct V_38 * V_39 ,
struct V_171 * V_172 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
struct V_173 V_174 ;
char * V_175 ;
struct V_176 * * V_177 ;
struct V_157 * V_178 [ 2 ] = {} ;
V_52 * V_179 = NULL ;
T_9 V_180 ;
T_1 V_65 ;
int V_181 , V_182 , V_71 ;
if ( V_172 -> V_183 != V_184 )
return - V_185 ;
if ( F_125 ( & V_174 , ( void V_186 * ) ( V_160 ) V_172 -> V_174 ,
sizeof( V_174 ) ) )
return - V_187 ;
if ( V_174 . V_188 [ 1 ] > 64 )
return - V_185 ;
if ( V_174 . V_189 [ 1 ] != V_174 . V_188 [ 1 ] )
return - V_185 ;
if ( V_174 . V_188 [ 2 ] != 0 || V_174 . V_188 [ 3 ] != 0 )
return - V_185 ;
if ( V_174 . V_189 [ 2 ] != 0 || V_174 . V_189 [ 3 ] != 0 )
return - V_185 ;
if ( ! F_126 ( V_174 . V_189 [ 0 ] ) )
return - V_185 ;
V_65 = V_174 . V_188 [ 0 ] >> F_127 ( V_174 . V_189 [ 0 ] ) ;
if ( ! F_126 ( V_65 ) )
return - V_185 ;
V_180 = V_174 . V_188 [ 0 ] + V_174 . V_188 [ 1 ] ;
V_180 *= sizeof( struct V_10 ) ;
if ( V_172 -> V_180 < V_180 )
return - V_185 ;
V_181 = F_128 ( V_172 -> V_190 + V_180 - 1 , V_161 ) -
V_172 -> V_190 / V_161 ;
V_177 = F_129 ( sizeof( struct V_176 * ) * V_181 , V_191 ) ;
if ( ! V_177 )
return - V_192 ;
V_182 = F_130 ( V_172 -> V_190 , V_181 , 1 , V_177 ) ;
if ( V_182 < 0 )
goto V_193;
if ( V_182 != V_181 ) {
V_181 = V_182 ;
V_182 = - V_187 ;
goto V_194;
}
V_175 = F_131 ( V_177 , V_181 , V_195 , V_196 ) ;
if ( ! V_175 )
goto V_194;
V_178 [ 0 ] = F_132 ( sizeof( struct V_157 ) * V_174 . V_188 [ 0 ] ,
V_191 ) ;
V_178 [ 1 ] = F_132 ( sizeof( struct V_157 ) * V_174 . V_188 [ 1 ] ,
V_191 ) ;
if ( ! V_178 [ 0 ] || ! V_178 [ 1 ] )
goto V_194;
V_179 = F_132 ( sizeof( V_52 ) * V_174 . V_188 [ 1 ] ,
V_191 ) ;
if ( ! V_179 )
goto V_194;
F_116 ( V_2 ) ;
V_2 -> V_57 [ 0 ] = V_178 [ 0 ] ;
V_2 -> V_57 [ 1 ] = V_178 [ 1 ] ;
V_2 -> V_61 = V_179 ;
V_2 -> V_75 = (struct V_10 * )
( V_175 + ( V_172 -> V_190 & ( V_161 - 1 ) ) ) ;
V_2 -> V_5 [ 0 ] . V_8 = V_174 . V_188 [ 0 ] ;
V_2 -> V_5 [ 1 ] . V_8 = V_174 . V_188 [ 1 ] ;
V_2 -> V_74 [ 0 ] = 0 ;
V_2 -> V_74 [ 1 ] = V_174 . V_188 [ 0 ] ;
V_39 -> V_42 . V_167 = F_16 ( V_197 ) & ~ V_198 ;
V_39 -> V_42 . V_168 [ 0 ] &= ~ ( V_199 | V_200 ) ;
if ( V_174 . V_188 [ 0 ] <= 2048 )
V_39 -> V_42 . V_168 [ 0 ] |= V_174 . V_188 [ 0 ] ;
V_39 -> V_42 . V_168 [ 0 ] |= V_174 . V_189 [ 0 ] << V_201 ;
V_39 -> V_42 . V_168 [ 1 ] &= ~ ( V_199 | V_200 ) ;
V_39 -> V_42 . V_168 [ 1 ] |= V_174 . V_188 [ 1 ] ;
V_39 -> V_42 . V_168 [ 1 ] |= V_174 . V_189 [ 1 ] << V_201 ;
V_2 -> V_159 = V_177 ;
V_2 -> V_162 = V_181 ;
V_2 -> V_5 [ 0 ] . V_6 = V_174 . V_189 [ 0 ] ;
V_2 -> V_5 [ 0 ] . V_65 = V_65 ;
V_2 -> V_5 [ 1 ] . V_6 = V_174 . V_188 [ 1 ] ;
V_2 -> V_5 [ 1 ] . V_65 = 1 ;
F_79 ( V_2 ) ;
return 0 ;
V_194:
F_117 ( V_178 [ 0 ] ) ;
F_117 ( V_178 [ 1 ] ) ;
for ( V_71 = 0 ; V_71 < V_181 ; V_71 ++ )
F_121 ( V_177 [ V_71 ] ) ;
V_193:
F_117 ( V_177 ) ;
return V_182 ;
}
int F_133 ( struct V_38 * V_39 ,
struct V_202 * V_203 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
F_79 ( V_2 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
int F_134 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = & V_2 -> V_39 ;
int V_204 = sizeof( struct V_10 ) ;
int V_8 = V_205 + V_206 ;
V_7 [ 0 ] . V_8 = F_16 ( V_207 ) & V_199 ;
V_7 [ 1 ] . V_8 = F_16 ( V_208 ) & V_199 ;
if ( V_7 [ 0 ] . V_8 == 0 ||
V_7 [ 1 ] . V_8 == 0 ) {
F_135 ( L_2 , V_209 ) ;
return - V_210 ;
}
V_7 [ 0 ] . V_6 = ( F_16 ( V_207 ) & V_200 ) >>
V_201 ;
V_7 [ 1 ] . V_6 = V_7 [ 1 ] . V_8 ;
if ( ! F_126 ( V_7 [ 0 ] . V_8 ) ||
! F_126 ( V_7 [ 0 ] . V_6 ) ||
V_7 [ 0 ] . V_8 < V_7 [ 0 ] . V_6 ||
V_7 [ 0 ] . V_6 == 0 ) {
F_135 ( L_3 ,
V_209 , V_7 [ 0 ] . V_8 ,
V_7 [ 0 ] . V_6 ) ;
return - V_210 ;
}
V_7 [ 0 ] . V_65 =
V_7 [ 0 ] . V_8 / V_7 [ 0 ] . V_6 ;
V_7 [ 1 ] . V_65 = 1 ;
V_2 -> V_5 [ 0 ] . V_8 = V_205 ;
V_2 -> V_5 [ 1 ] . V_8 = V_206 ;
V_2 -> V_5 [ 0 ] . V_6 = V_211 ;
V_2 -> V_5 [ 0 ] . V_65 =
V_205 / V_211 ;
V_2 -> V_5 [ 1 ] . V_6 = V_206 ;
V_2 -> V_5 [ 1 ] . V_65 = 1 ;
V_2 -> V_75 = F_129 ( V_8 * V_204 , V_191 ) ;
if ( ! V_2 -> V_75 )
return - V_192 ;
V_2 -> V_74 [ 0 ] = 0 ;
V_2 -> V_74 [ 1 ] = V_205 ;
V_2 -> V_81 [ 0 ] =
F_132 ( sizeof( struct V_77 ) * V_7 [ 0 ] . V_8 ,
V_191 ) ;
if ( ! V_2 -> V_81 [ 0 ] )
goto V_212;
V_2 -> V_81 [ 1 ] =
F_132 ( sizeof( struct V_77 ) * V_7 [ 1 ] . V_8 ,
V_191 ) ;
if ( ! V_2 -> V_81 [ 1 ] )
goto V_212;
V_2 -> V_57 [ 0 ] = F_132 ( sizeof( struct V_77 ) *
V_2 -> V_5 [ 0 ] . V_8 ,
V_191 ) ;
if ( ! V_2 -> V_57 [ 0 ] )
goto V_212;
V_2 -> V_57 [ 1 ] = F_132 ( sizeof( struct V_77 ) *
V_2 -> V_5 [ 1 ] . V_8 ,
V_191 ) ;
if ( ! V_2 -> V_57 [ 1 ] )
goto V_212;
V_2 -> V_61 = F_132 ( sizeof( unsigned int ) *
V_2 -> V_5 [ 1 ] . V_8 ,
V_191 ) ;
if ( ! V_2 -> V_61 )
goto V_212;
V_2 -> V_63 = F_132 ( sizeof( unsigned int ) *
V_7 [ 1 ] . V_8 ,
V_191 ) ;
if ( ! V_2 -> V_63 )
goto V_212;
V_39 -> V_42 . V_168 [ 0 ] = F_16 ( V_207 ) &
~ ( V_199 | V_200 ) ;
V_39 -> V_42 . V_168 [ 0 ] |= V_2 -> V_5 [ 0 ] . V_8 ;
V_39 -> V_42 . V_168 [ 0 ] |=
V_2 -> V_5 [ 0 ] . V_6 << V_201 ;
V_39 -> V_42 . V_168 [ 1 ] = F_16 ( V_208 ) &
~ ( V_199 | V_200 ) ;
V_39 -> V_42 . V_168 [ 1 ] |= V_2 -> V_5 [ 1 ] . V_8 ;
V_39 -> V_42 . V_168 [ 1 ] |=
V_2 -> V_5 [ 1 ] . V_6 << V_201 ;
F_79 ( V_2 ) ;
return 0 ;
V_212:
F_116 ( V_2 ) ;
F_117 ( V_2 -> V_81 [ 0 ] ) ;
F_117 ( V_2 -> V_81 [ 1 ] ) ;
return - 1 ;
}
void F_136 ( struct V_1 * V_2 )
{
F_116 ( V_2 ) ;
F_117 ( V_2 -> V_63 ) ;
F_117 ( V_2 -> V_81 [ 0 ] ) ;
F_117 ( V_2 -> V_81 [ 1 ] ) ;
}
