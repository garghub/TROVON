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
F_47 ( V_46 ) ;
}
static inline void F_48 ( struct V_77 * V_58 )
{
if ( V_58 -> V_25 & V_78 ) {
F_49 ( V_58 -> V_46 , V_58 -> V_25 ) ;
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
F_48 ( V_58 ) ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
int V_79 = 1 ;
int V_71 ;
F_53 ( V_2 ) ;
for ( V_71 = 0 ; V_71 < V_7 [ V_79 ] . V_8 ; V_71 ++ ) {
struct V_77 * V_58 =
& V_2 -> V_80 [ V_79 ] [ V_71 ] ;
F_48 ( V_58 ) ;
}
F_51 ( V_2 ) ;
}
void F_54 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
F_52 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static inline void F_55 ( struct V_38 * V_39 ,
unsigned int V_34 , int V_68 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
unsigned int V_3 , V_81 ;
int V_36 ;
V_36 = ( V_39 -> V_42 . V_43 -> V_82 >> 28 ) & 0x1 ;
V_3 = ( V_36 == 0 ) ? F_1 ( V_2 ) : 0 ;
V_81 = ( V_39 -> V_42 . V_43 -> V_82 >> 7 ) & 0x1f ;
V_39 -> V_42 . V_43 -> V_24 = F_18 ( V_36 ) | F_19 ( V_3 )
| F_56 ( V_2 -> V_4 [ V_36 ] ) ;
V_39 -> V_42 . V_43 -> V_28 = V_48 | ( V_68 ? V_49 : 0 )
| F_28 ( F_57 ( V_39 ) )
| F_29 ( V_81 ) ;
V_39 -> V_42 . V_43 -> V_20 = ( V_34 & V_83 )
| ( V_39 -> V_42 . V_43 -> V_82 & V_21 ) ;
V_39 -> V_42 . V_43 -> V_12 &= V_84 | V_85 | V_86 | V_87 ;
V_39 -> V_42 . V_43 -> V_88 = ( V_39 -> V_42 . V_43 -> V_88 & V_89 )
| ( F_58 ( V_39 ) << 16 )
| ( V_68 ? V_90 : 0 ) ;
}
static inline void F_59 (
struct V_38 * V_39 ,
struct V_10 * V_56 ,
int V_91 , struct V_77 * V_58 , V_52 V_92 ,
struct V_10 * V_23 )
{
T_4 V_46 = V_58 -> V_46 ;
T_1 V_93 = V_39 -> V_42 . V_43 -> V_94 & V_95 ;
F_60 ( ! ( V_58 -> V_25 & V_78 ) ) ;
V_23 -> V_28 = F_29 ( V_91 ) | F_61 ( V_56 ) | V_48 ;
V_23 -> V_20 = ( V_92 & V_83 ) |
F_7 ( V_56 -> V_20 , V_93 ) ;
V_23 -> V_12 = ( ( V_52 ) V_46 << V_47 ) |
F_5 ( V_56 -> V_12 , V_93 ) ;
#ifdef F_6
V_23 -> V_33 = V_96 | V_39 -> V_97 -> V_42 . V_98 ;
#endif
}
static inline void F_62 ( struct V_1 * V_2 ,
V_52 V_92 , T_6 V_99 , struct V_10 * V_56 ,
int V_36 , struct V_10 * V_23 ,
struct V_77 * V_58 )
{
struct V_100 * V_101 ;
unsigned long V_46 = 0 ;
unsigned long V_102 ;
int V_103 = 0 ;
int V_91 = V_50 ;
V_101 = F_63 ( V_2 -> V_39 . V_97 , V_99 ) ;
V_102 = F_64 ( V_101 , V_99 ) ;
if ( V_36 == 1 ) {
struct V_104 * V_105 ;
F_65 ( & V_106 -> V_107 -> V_108 ) ;
V_105 = F_66 ( V_106 -> V_107 , V_102 ) ;
if ( V_105 && V_102 >= V_105 -> V_109 &&
( V_105 -> V_110 & V_111 ) ) {
unsigned long V_112 , V_113 ;
unsigned long V_114 , V_115 ;
V_103 = 1 ;
V_112 = V_105 -> V_116 ;
V_113 = V_112 +
( ( V_105 -> V_117 - V_105 -> V_109 ) >> V_47 ) ;
V_46 = V_112 + ( ( V_102 - V_105 -> V_109 ) >> V_47 ) ;
V_114 = V_46 - ( V_99 - V_101 -> V_118 ) ;
V_115 = V_114 + V_101 -> V_119 ;
if ( V_112 < V_114 )
V_112 = V_114 ;
if ( V_113 > V_115 )
V_113 = V_115 ;
V_91 = ( V_56 -> V_28 & V_120 ) >>
V_121 ;
V_91 = F_67 ( V_50 , V_91 & ~ 1 ) ;
for (; V_91 > V_50 ; V_91 -= 2 ) {
unsigned long V_122 , V_123 , V_124 ;
V_124 = 1 << ( V_91 - 2 ) ;
V_122 = V_99 & ~ ( V_124 - 1 ) ;
V_123 = V_122 + V_124 ;
if ( V_122 + V_46 - V_99 < V_112 )
continue;
if ( V_123 + V_46 - V_99 > V_113 )
continue;
if ( ( V_99 & ( V_124 - 1 ) ) !=
( V_46 & ( V_124 - 1 ) ) )
continue;
V_92 &= ~ ( ( V_124 << V_47 ) - 1 ) ;
V_46 &= ~ ( V_124 - 1 ) ;
break;
}
} else if ( V_105 && V_102 >= V_105 -> V_109 &&
( V_105 -> V_110 & V_125 ) ) {
unsigned long V_126 = F_68 ( V_105 ) ;
V_91 = ( V_56 -> V_28 & V_120 ) >>
V_121 ;
V_91 = F_69 ( F_70 ( V_126 ) - 10 , V_91 ) ;
V_91 = F_67 ( V_50 , V_91 & ~ 1 ) ;
}
F_71 ( & V_106 -> V_107 -> V_108 ) ;
}
if ( F_72 ( ! V_103 ) ) {
unsigned long V_124 = 1 << ( V_91 + 10 - V_47 ) ;
V_46 = F_73 ( V_101 , V_99 ) ;
if ( F_74 ( V_46 ) ) {
F_75 ( V_127 L_1 ,
( long ) V_99 ) ;
return;
}
V_46 &= ~ ( V_124 - 1 ) ;
V_92 &= ~ ( ( V_124 << V_47 ) - 1 ) ;
}
F_48 ( V_58 ) ;
F_46 ( V_58 , V_56 , V_46 ) ;
F_59 ( & V_2 -> V_39 , V_56 , V_91 ,
V_58 , V_92 , V_23 ) ;
F_76 ( V_46 ) ;
F_77 ( V_46 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
int V_55 ,
struct V_10 * V_23 )
{
struct V_10 * V_56 ;
struct V_77 * V_58 ;
V_56 = F_32 ( V_2 , 0 , V_55 ) ;
V_58 = & V_2 -> V_57 [ 0 ] [ V_55 ] . V_58 ;
F_62 ( V_2 , F_41 ( V_56 ) ,
F_79 ( V_56 ) >> V_47 ,
V_56 , 0 , V_23 , V_58 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
V_52 V_92 , T_6 V_99 , struct V_10 * V_56 ,
struct V_10 * V_23 , int V_55 )
{
struct V_77 * V_58 ;
unsigned int V_3 ;
V_3 = V_2 -> V_128 ++ ;
if ( F_2 ( V_2 -> V_128 >= F_3 () ) )
V_2 -> V_128 = 0 ;
V_58 = & V_2 -> V_80 [ 1 ] [ V_3 ] ;
F_62 ( V_2 , V_92 , V_99 , V_56 , 1 , V_23 , V_58 ) ;
V_2 -> V_61 [ V_55 ] |= ( V_52 ) 1 << V_3 ;
V_2 -> V_57 [ 1 ] [ V_55 ] . V_58 . V_25 |= V_59 ;
if ( V_2 -> V_63 [ V_3 ] ) {
unsigned int V_129 = V_2 -> V_63 [ V_3 ] ;
V_2 -> V_61 [ V_129 ] &= ~ ( 1ULL << V_3 ) ;
}
V_2 -> V_63 [ V_3 ] = V_55 ;
return V_3 ;
}
static void F_81 ( struct V_1 * V_2 )
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
F_69 ( V_2 -> V_72 , V_34 ) ;
V_34 = F_42 ( V_11 ) ;
V_2 -> V_73 =
F_67 ( V_2 -> V_73 , V_34 ) ;
}
}
static int F_82 ( struct V_1 * V_2 ,
struct V_10 * V_56 )
{
unsigned long V_112 , V_113 , V_69 ;
V_69 = F_83 ( V_56 ) ;
V_112 = F_41 ( V_56 ) & ~ ( V_69 - 1 ) ;
V_113 = V_112 + V_69 - 1 ;
return V_2 -> V_72 == V_112 ||
V_2 -> V_73 == V_113 ;
}
static void F_84 ( struct V_38 * V_39 ,
struct V_10 * V_56 )
{
unsigned long V_112 , V_113 , V_69 ;
struct V_1 * V_2 = F_22 ( V_39 ) ;
if ( ! F_44 ( V_56 ) )
return;
V_69 = F_83 ( V_56 ) ;
V_112 = F_41 ( V_56 ) & ~ ( V_69 - 1 ) ;
V_113 = V_112 + V_69 - 1 ;
V_2 -> V_72 = F_69 ( V_2 -> V_72 , V_112 ) ;
V_2 -> V_73 = F_67 ( V_2 -> V_73 , V_113 ) ;
}
static inline int F_85 (
struct V_1 * V_2 ,
int V_36 , int V_55 )
{
struct V_10 * V_56 =
F_32 ( V_2 , V_36 , V_55 ) ;
if ( F_2 ( F_86 ( V_56 ) ) )
return - 1 ;
if ( V_36 == 1 && F_82 ( V_2 , V_56 ) )
F_81 ( V_2 ) ;
V_56 -> V_28 = 0 ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 , T_3 V_130 )
{
int V_55 ;
if ( V_130 & V_131 )
for ( V_55 = 0 ; V_55 < V_2 -> V_5 [ 0 ] . V_8 ; V_55 ++ )
F_85 ( V_2 , 0 , V_55 ) ;
if ( V_130 & V_132 )
for ( V_55 = 0 ; V_55 < V_2 -> V_5 [ 1 ] . V_8 ; V_55 ++ )
F_85 ( V_2 , 1 , V_55 ) ;
F_53 ( V_2 ) ;
return V_133 ;
}
int F_88 ( struct V_38 * V_39 , T_5 V_134 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
unsigned int V_135 ;
int V_55 , V_36 ;
V_135 = ( V_134 >> 2 ) & 0x1 ;
V_36 = ( V_134 >> 3 ) & 0x1 ;
if ( V_135 ) {
for ( V_55 = 0 ; V_55 < V_2 -> V_5 [ V_36 ] . V_8 ;
V_55 ++ )
F_85 ( V_2 , V_36 , V_55 ) ;
} else {
V_134 &= 0xfffff000 ;
V_55 = F_40 ( V_2 , V_134 , V_36 ,
F_58 ( V_39 ) , - 1 ) ;
if ( V_55 >= 0 )
F_85 ( V_2 , V_36 , V_55 ) ;
}
F_53 ( V_2 ) ;
return V_133 ;
}
static void F_89 ( struct V_1 * V_2 , int V_36 ,
int V_67 , int type )
{
struct V_10 * V_11 ;
int V_76 , V_55 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_5 [ V_36 ] . V_8 ; V_55 ++ ) {
V_11 = F_32 ( V_2 , V_36 , V_55 ) ;
V_76 = F_43 ( V_11 ) ;
if ( type == 0 || V_76 == V_67 ) {
F_31 ( V_2 , V_36 , V_55 ) ;
F_85 ( V_2 , V_36 , V_55 ) ;
}
}
}
static void F_90 ( struct V_1 * V_2 , int V_67 ,
T_5 V_134 )
{
int V_36 , V_55 ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_55 = F_40 ( V_2 , V_134 , V_36 , V_67 , - 1 ) ;
if ( V_55 >= 0 ) {
F_31 ( V_2 , V_36 , V_55 ) ;
F_85 ( V_2 , V_36 , V_55 ) ;
break;
}
}
}
int F_91 ( struct V_38 * V_39 , int type , T_5 V_134 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
int V_67 = F_92 ( V_39 ) ;
if ( type == 0 || type == 1 ) {
F_89 ( V_2 , 0 , V_67 , type ) ;
F_89 ( V_2 , 1 , V_67 , type ) ;
} else if ( type == 3 ) {
F_90 ( V_2 , V_67 , V_134 ) ;
}
return V_133 ;
}
int F_93 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
int V_36 , V_55 ;
struct V_10 * V_56 ;
V_36 = F_94 ( V_39 ) ;
V_55 = F_38 ( V_39 , V_36 ) ;
V_56 = F_32 ( V_2 , V_36 , V_55 ) ;
V_39 -> V_42 . V_43 -> V_24 &= ~ F_56 ( ~ 0 ) ;
V_39 -> V_42 . V_43 -> V_24 |= F_56 ( V_2 -> V_4 [ V_36 ] ) ;
V_39 -> V_42 . V_43 -> V_28 = V_56 -> V_28 ;
V_39 -> V_42 . V_43 -> V_20 = V_56 -> V_20 ;
V_39 -> V_42 . V_43 -> V_12 = V_56 -> V_12 ;
return V_133 ;
}
int F_95 ( struct V_38 * V_39 , T_5 V_134 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
int V_68 = ! ! F_96 ( V_39 ) ;
unsigned int V_67 = F_92 ( V_39 ) ;
int V_55 , V_36 ;
struct V_10 * V_56 = NULL ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_55 = F_40 ( V_2 , V_134 , V_36 , V_67 , V_68 ) ;
if ( V_55 >= 0 ) {
V_56 = F_32 ( V_2 , V_36 , V_55 ) ;
break;
}
}
if ( V_56 ) {
V_55 &= V_2 -> V_5 [ V_36 ] . V_6 - 1 ;
V_39 -> V_42 . V_43 -> V_24 = F_18 ( V_36 ) | F_19 ( V_55 )
| F_56 ( V_2 -> V_4 [ V_36 ] ) ;
V_39 -> V_42 . V_43 -> V_28 = V_56 -> V_28 ;
V_39 -> V_42 . V_43 -> V_20 = V_56 -> V_20 ;
V_39 -> V_42 . V_43 -> V_12 = V_56 -> V_12 ;
} else {
int V_3 ;
V_36 = V_39 -> V_42 . V_43 -> V_82 >> 28 & 0x1 ;
V_3 = ( V_36 == 0 ) ? F_1 ( V_2 ) : 0 ;
V_39 -> V_42 . V_43 -> V_24 = F_18 ( V_36 )
| F_19 ( V_3 )
| F_56 ( V_2 -> V_4 [ V_36 ] ) ;
V_39 -> V_42 . V_43 -> V_28 =
( V_39 -> V_42 . V_43 -> V_88 & V_136 )
| ( V_39 -> V_42 . V_43 -> V_88 & ( V_90 ? V_49 : 0 ) )
| ( V_39 -> V_42 . V_43 -> V_82 & F_97 ( ~ 0 ) ) ;
V_39 -> V_42 . V_43 -> V_20 &= V_83 ;
V_39 -> V_42 . V_43 -> V_20 |= V_39 -> V_42 . V_43 -> V_82 &
V_21 ;
V_39 -> V_42 . V_43 -> V_12 &= V_84 | V_85 |
V_86 | V_87 ;
}
F_98 ( V_39 , V_137 ) ;
return V_133 ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_10 * V_56 ,
struct V_10 * V_23 ,
int V_79 , int V_37 )
{
int V_45 ;
F_26 () ;
V_45 = F_100 ( & V_2 -> V_39 , V_56 ) ;
V_23 -> V_28 |= F_28 ( V_45 ) ;
F_17 ( V_2 , V_79 , V_37 , V_23 ) ;
F_30 () ;
}
int F_101 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
struct V_10 * V_56 , V_23 ;
int V_36 , V_55 , V_79 , V_37 ;
int V_138 = 0 ;
V_36 = F_94 ( V_39 ) ;
V_55 = F_38 ( V_39 , V_36 ) ;
V_56 = F_32 ( V_2 , V_36 , V_55 ) ;
if ( F_44 ( V_56 ) ) {
F_31 ( V_2 , V_36 , V_55 ) ;
if ( ( V_36 == 1 ) &&
F_82 ( V_2 , V_56 ) )
V_138 = 1 ;
}
V_56 -> V_28 = V_39 -> V_42 . V_43 -> V_28 ;
V_56 -> V_20 = V_39 -> V_42 . V_43 -> V_20 ;
if ( ! ( V_39 -> V_42 . V_43 -> V_94 & V_139 ) )
V_56 -> V_20 &= 0xffffffffUL ;
V_56 -> V_12 = V_39 -> V_42 . V_43 -> V_12 ;
F_102 ( V_39 -> V_42 . V_43 -> V_24 , V_56 -> V_28 ,
V_56 -> V_20 , V_56 -> V_12 ) ;
if ( V_36 == 1 ) {
if ( V_138 )
F_81 ( V_2 ) ;
else
F_84 ( V_39 , V_56 ) ;
}
if ( F_103 ( V_39 , V_56 ) ) {
V_52 V_34 ;
V_52 V_140 ;
switch ( V_36 ) {
case 0 :
V_56 -> V_28 &= ~ F_29 ( ~ 0 ) ;
V_56 -> V_28 |= F_29 ( V_50 ) ;
V_79 = 0 ;
F_78 ( V_2 , V_55 , & V_23 ) ;
V_37 = 0 ;
break;
case 1 :
V_34 = F_41 ( V_56 ) ;
V_140 = F_79 ( V_56 ) ;
V_79 = 1 ;
V_37 = F_80 ( V_2 , V_34 ,
V_140 >> V_47 , V_56 , & V_23 , V_55 ) ;
break;
default:
F_104 () ;
}
F_99 ( V_2 , V_56 , & V_23 , V_79 , V_37 ) ;
}
F_98 ( V_39 , V_141 ) ;
return V_133 ;
}
static int F_105 ( struct V_38 * V_39 ,
T_5 V_34 , unsigned int V_67 , int V_68 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
int V_55 , V_36 ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_55 = F_40 ( V_2 , V_34 , V_36 , V_67 , V_68 ) ;
if ( V_55 >= 0 )
return F_106 ( V_36 , V_55 ) ;
}
return - 1 ;
}
int F_107 ( struct V_38 * V_39 ,
struct V_142 * V_143 )
{
int V_144 ;
T_5 V_34 ;
T_7 V_67 ;
T_7 V_68 ;
V_34 = V_143 -> V_145 ;
V_67 = ( V_143 -> V_145 >> 32 ) & 0xff ;
V_68 = ( V_143 -> V_145 >> 40 ) & 0x1 ;
V_144 = F_105 ( V_39 , V_34 , V_67 , V_68 ) ;
if ( V_144 < 0 ) {
V_143 -> V_146 = 0 ;
return 0 ;
}
V_143 -> V_147 = F_108 ( V_39 , V_144 , V_34 ) ;
V_143 -> V_146 = 1 ;
return 0 ;
}
int F_109 ( struct V_38 * V_39 , T_5 V_34 )
{
unsigned int V_68 = ! ! ( V_39 -> V_42 . V_43 -> V_94 & V_148 ) ;
return F_105 ( V_39 , V_34 , F_58 ( V_39 ) , V_68 ) ;
}
int F_110 ( struct V_38 * V_39 , T_5 V_34 )
{
unsigned int V_68 = ! ! ( V_39 -> V_42 . V_43 -> V_94 & V_149 ) ;
return F_105 ( V_39 , V_34 , F_58 ( V_39 ) , V_68 ) ;
}
void F_111 ( struct V_38 * V_39 )
{
unsigned int V_68 = ! ! ( V_39 -> V_42 . V_43 -> V_94 & V_148 ) ;
F_55 ( V_39 , V_39 -> V_42 . V_150 , V_68 ) ;
}
void F_112 ( struct V_38 * V_39 )
{
unsigned int V_68 = ! ! ( V_39 -> V_42 . V_43 -> V_94 & V_149 ) ;
F_55 ( V_39 , V_39 -> V_42 . V_151 , V_68 ) ;
}
T_8 F_108 ( struct V_38 * V_39 , unsigned int V_144 ,
T_5 V_34 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
struct V_10 * V_56 ;
V_52 V_152 ;
V_56 = F_32 ( V_2 , F_113 ( V_144 ) , F_114 ( V_144 ) ) ;
V_152 = F_83 ( V_56 ) - 1 ;
return F_79 ( V_56 ) | ( V_34 & V_152 ) ;
}
void F_115 ( struct V_38 * V_39 )
{
}
void F_116 ( struct V_38 * V_39 , V_52 V_34 , T_8 V_153 ,
unsigned int V_144 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
struct V_154 * V_155 ;
struct V_10 * V_56 , V_23 ;
int V_36 = F_113 ( V_144 ) ;
int V_55 = F_114 ( V_144 ) ;
int V_79 , V_37 ;
V_56 = F_32 ( V_2 , V_36 , V_55 ) ;
switch ( V_36 ) {
case 0 :
V_79 = 0 ;
V_37 = 0 ;
V_155 = & V_2 -> V_57 [ V_36 ] [ V_55 ] ;
if ( F_2 ( ! ( V_155 -> V_58 . V_25 & V_78 ) ) )
F_78 ( V_2 , V_55 , & V_23 ) ;
else
F_59 ( V_39 , V_56 , V_50 ,
& V_155 -> V_58 , V_34 , & V_23 ) ;
break;
case 1 : {
T_6 V_99 = V_153 >> V_47 ;
V_79 = 1 ;
V_37 = F_80 ( V_2 , V_34 , V_99 ,
V_56 , & V_23 , V_55 ) ;
break;
}
default:
F_104 () ;
break;
}
F_99 ( V_2 , V_56 , & V_23 , V_79 , V_37 ) ;
}
int F_117 ( struct V_97 * V_97 , unsigned long V_102 )
{
F_118 ( V_102 ) ;
F_119 ( V_97 ) ;
return 0 ;
}
int F_120 ( struct V_97 * V_97 , unsigned long V_112 , unsigned long V_113 )
{
F_117 ( V_97 , V_112 ) ;
return 0 ;
}
int F_121 ( struct V_97 * V_97 , unsigned long V_102 )
{
return 0 ;
}
int F_122 ( struct V_97 * V_97 , unsigned long V_102 )
{
return 0 ;
}
void F_123 ( struct V_97 * V_97 , unsigned long V_102 , T_9 V_156 )
{
F_117 ( V_97 , V_102 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
int V_71 ;
F_50 ( V_2 ) ;
F_125 ( V_2 -> V_61 ) ;
F_52 ( V_2 ) ;
F_125 ( V_2 -> V_57 [ 0 ] ) ;
F_125 ( V_2 -> V_57 [ 1 ] ) ;
if ( V_2 -> V_157 ) {
F_126 ( ( void * ) ( F_127 ( ( V_158 ) V_2 -> V_75 ,
V_159 ) ) ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_160 ; V_71 ++ ) {
F_128 ( V_2 -> V_157 [ V_71 ] ) ;
F_129 ( V_2 -> V_157 [ V_71 ] ) ;
}
V_2 -> V_160 = 0 ;
F_125 ( V_2 -> V_157 ) ;
V_2 -> V_157 = NULL ;
} else {
F_125 ( V_2 -> V_75 ) ;
}
V_2 -> V_75 = NULL ;
}
void F_130 ( struct V_38 * V_39 , struct V_161 * V_162 )
{
V_162 -> V_163 . V_164 . V_24 = V_39 -> V_42 . V_43 -> V_24 ;
V_162 -> V_163 . V_164 . V_28 = V_39 -> V_42 . V_43 -> V_28 ;
V_162 -> V_163 . V_164 . V_20 = V_39 -> V_42 . V_43 -> V_20 ;
V_162 -> V_163 . V_164 . V_12 = V_39 -> V_42 . V_43 -> V_12 ;
V_162 -> V_163 . V_164 . V_82 = V_39 -> V_42 . V_43 -> V_82 ;
V_162 -> V_163 . V_164 . V_88 = V_39 -> V_42 . V_43 -> V_88 ;
V_162 -> V_163 . V_164 . V_165 = V_39 -> V_42 . V_165 ;
V_162 -> V_163 . V_164 . V_166 [ 0 ] = V_39 -> V_42 . V_166 [ 0 ] ;
V_162 -> V_163 . V_164 . V_166 [ 1 ] = V_39 -> V_42 . V_166 [ 1 ] ;
V_162 -> V_163 . V_164 . V_166 [ 2 ] = 0 ;
V_162 -> V_163 . V_164 . V_166 [ 3 ] = 0 ;
}
int F_131 ( struct V_38 * V_39 , struct V_161 * V_162 )
{
if ( V_162 -> V_163 . V_164 . V_167 & V_168 ) {
V_39 -> V_42 . V_43 -> V_24 = V_162 -> V_163 . V_164 . V_24 ;
V_39 -> V_42 . V_43 -> V_28 = V_162 -> V_163 . V_164 . V_28 ;
V_39 -> V_42 . V_43 -> V_20 = V_162 -> V_163 . V_164 . V_20 ;
V_39 -> V_42 . V_43 -> V_12 = V_162 -> V_163 . V_164 . V_12 ;
V_39 -> V_42 . V_43 -> V_82 = V_162 -> V_163 . V_164 . V_82 ;
V_39 -> V_42 . V_43 -> V_88 = V_162 -> V_163 . V_164 . V_88 ;
}
return 0 ;
}
int F_132 ( struct V_38 * V_39 ,
struct V_169 * V_170 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
struct V_171 V_172 ;
char * V_173 ;
struct V_174 * * V_175 ;
struct V_154 * V_176 [ 2 ] = {} ;
V_52 * V_177 = NULL ;
T_10 V_178 ;
T_1 V_65 ;
int V_179 , V_180 , V_71 ;
if ( V_170 -> V_181 != V_182 )
return - V_183 ;
if ( F_133 ( & V_172 , ( void V_184 * ) ( V_158 ) V_170 -> V_172 ,
sizeof( V_172 ) ) )
return - V_185 ;
if ( V_172 . V_186 [ 1 ] > 64 )
return - V_183 ;
if ( V_172 . V_187 [ 1 ] != V_172 . V_186 [ 1 ] )
return - V_183 ;
if ( V_172 . V_186 [ 2 ] != 0 || V_172 . V_186 [ 3 ] != 0 )
return - V_183 ;
if ( V_172 . V_187 [ 2 ] != 0 || V_172 . V_187 [ 3 ] != 0 )
return - V_183 ;
if ( ! F_134 ( V_172 . V_187 [ 0 ] ) )
return - V_183 ;
V_65 = V_172 . V_186 [ 0 ] >> F_135 ( V_172 . V_187 [ 0 ] ) ;
if ( ! F_134 ( V_65 ) )
return - V_183 ;
V_178 = V_172 . V_186 [ 0 ] + V_172 . V_186 [ 1 ] ;
V_178 *= sizeof( struct V_10 ) ;
if ( V_170 -> V_178 < V_178 )
return - V_183 ;
V_179 = F_136 ( V_170 -> V_188 + V_178 - 1 , V_159 ) -
V_170 -> V_188 / V_159 ;
V_175 = F_137 ( sizeof( struct V_174 * ) * V_179 , V_189 ) ;
if ( ! V_175 )
return - V_190 ;
V_180 = F_138 ( V_170 -> V_188 , V_179 , 1 , V_175 ) ;
if ( V_180 < 0 )
goto V_191;
if ( V_180 != V_179 ) {
V_179 = V_180 ;
V_180 = - V_185 ;
goto V_192;
}
V_173 = F_139 ( V_175 , V_179 , V_193 , V_194 ) ;
if ( ! V_173 ) {
V_180 = - V_190 ;
goto V_192;
}
V_176 [ 0 ] = F_140 ( sizeof( struct V_154 ) * V_172 . V_186 [ 0 ] ,
V_189 ) ;
V_176 [ 1 ] = F_140 ( sizeof( struct V_154 ) * V_172 . V_186 [ 1 ] ,
V_189 ) ;
if ( ! V_176 [ 0 ] || ! V_176 [ 1 ] ) {
V_180 = - V_190 ;
goto V_195;
}
V_177 = F_140 ( sizeof( V_52 ) * V_172 . V_186 [ 1 ] ,
V_189 ) ;
if ( ! V_177 ) {
V_180 = - V_190 ;
goto V_195;
}
F_124 ( V_2 ) ;
V_2 -> V_57 [ 0 ] = V_176 [ 0 ] ;
V_2 -> V_57 [ 1 ] = V_176 [ 1 ] ;
V_2 -> V_61 = V_177 ;
V_2 -> V_75 = (struct V_10 * )
( V_173 + ( V_170 -> V_188 & ( V_159 - 1 ) ) ) ;
V_2 -> V_5 [ 0 ] . V_8 = V_172 . V_186 [ 0 ] ;
V_2 -> V_5 [ 1 ] . V_8 = V_172 . V_186 [ 1 ] ;
V_2 -> V_74 [ 0 ] = 0 ;
V_2 -> V_74 [ 1 ] = V_172 . V_186 [ 0 ] ;
V_39 -> V_42 . V_165 = F_16 ( V_196 ) & ~ V_197 ;
V_39 -> V_42 . V_166 [ 0 ] &= ~ ( V_198 | V_199 ) ;
if ( V_172 . V_186 [ 0 ] <= 2048 )
V_39 -> V_42 . V_166 [ 0 ] |= V_172 . V_186 [ 0 ] ;
V_39 -> V_42 . V_166 [ 0 ] |= V_172 . V_187 [ 0 ] << V_200 ;
V_39 -> V_42 . V_166 [ 1 ] &= ~ ( V_198 | V_199 ) ;
V_39 -> V_42 . V_166 [ 1 ] |= V_172 . V_186 [ 1 ] ;
V_39 -> V_42 . V_166 [ 1 ] |= V_172 . V_187 [ 1 ] << V_200 ;
V_2 -> V_157 = V_175 ;
V_2 -> V_160 = V_179 ;
V_2 -> V_5 [ 0 ] . V_6 = V_172 . V_187 [ 0 ] ;
V_2 -> V_5 [ 0 ] . V_65 = V_65 ;
V_2 -> V_5 [ 1 ] . V_6 = V_172 . V_186 [ 1 ] ;
V_2 -> V_5 [ 1 ] . V_65 = 1 ;
F_81 ( V_2 ) ;
return 0 ;
V_195:
F_125 ( V_176 [ 0 ] ) ;
F_125 ( V_176 [ 1 ] ) ;
V_192:
for ( V_71 = 0 ; V_71 < V_179 ; V_71 ++ )
F_129 ( V_175 [ V_71 ] ) ;
V_191:
F_125 ( V_175 ) ;
return V_180 ;
}
int F_141 ( struct V_38 * V_39 ,
struct V_201 * V_202 )
{
struct V_1 * V_2 = F_22 ( V_39 ) ;
F_81 ( V_2 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
int F_142 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = & V_2 -> V_39 ;
int V_203 = sizeof( struct V_10 ) ;
int V_8 = V_204 + V_205 ;
V_7 [ 0 ] . V_8 = F_16 ( V_206 ) & V_198 ;
V_7 [ 1 ] . V_8 = F_16 ( V_207 ) & V_198 ;
if ( V_7 [ 0 ] . V_8 == 0 ||
V_7 [ 1 ] . V_8 == 0 ) {
F_143 ( L_2 , V_208 ) ;
return - V_209 ;
}
V_7 [ 0 ] . V_6 = ( F_16 ( V_206 ) & V_199 ) >>
V_200 ;
V_7 [ 1 ] . V_6 = V_7 [ 1 ] . V_8 ;
if ( ! F_134 ( V_7 [ 0 ] . V_8 ) ||
! F_134 ( V_7 [ 0 ] . V_6 ) ||
V_7 [ 0 ] . V_8 < V_7 [ 0 ] . V_6 ||
V_7 [ 0 ] . V_6 == 0 ) {
F_143 ( L_3 ,
V_208 , V_7 [ 0 ] . V_8 ,
V_7 [ 0 ] . V_6 ) ;
return - V_209 ;
}
V_7 [ 0 ] . V_65 =
V_7 [ 0 ] . V_8 / V_7 [ 0 ] . V_6 ;
V_7 [ 1 ] . V_65 = 1 ;
V_2 -> V_5 [ 0 ] . V_8 = V_204 ;
V_2 -> V_5 [ 1 ] . V_8 = V_205 ;
V_2 -> V_5 [ 0 ] . V_6 = V_210 ;
V_2 -> V_5 [ 0 ] . V_65 =
V_204 / V_210 ;
V_2 -> V_5 [ 1 ] . V_6 = V_205 ;
V_2 -> V_5 [ 1 ] . V_65 = 1 ;
V_2 -> V_75 = F_137 ( V_8 * V_203 , V_189 ) ;
if ( ! V_2 -> V_75 )
return - V_190 ;
V_2 -> V_74 [ 0 ] = 0 ;
V_2 -> V_74 [ 1 ] = V_204 ;
V_2 -> V_80 [ 0 ] =
F_140 ( sizeof( struct V_77 ) * V_7 [ 0 ] . V_8 ,
V_189 ) ;
if ( ! V_2 -> V_80 [ 0 ] )
goto V_211;
V_2 -> V_80 [ 1 ] =
F_140 ( sizeof( struct V_77 ) * V_7 [ 1 ] . V_8 ,
V_189 ) ;
if ( ! V_2 -> V_80 [ 1 ] )
goto V_211;
V_2 -> V_57 [ 0 ] = F_140 ( sizeof( struct V_77 ) *
V_2 -> V_5 [ 0 ] . V_8 ,
V_189 ) ;
if ( ! V_2 -> V_57 [ 0 ] )
goto V_211;
V_2 -> V_57 [ 1 ] = F_140 ( sizeof( struct V_77 ) *
V_2 -> V_5 [ 1 ] . V_8 ,
V_189 ) ;
if ( ! V_2 -> V_57 [ 1 ] )
goto V_211;
V_2 -> V_61 = F_140 ( sizeof( V_52 ) *
V_2 -> V_5 [ 1 ] . V_8 ,
V_189 ) ;
if ( ! V_2 -> V_61 )
goto V_211;
V_2 -> V_63 = F_140 ( sizeof( unsigned int ) *
V_7 [ 1 ] . V_8 ,
V_189 ) ;
if ( ! V_2 -> V_63 )
goto V_211;
V_39 -> V_42 . V_166 [ 0 ] = F_16 ( V_206 ) &
~ ( V_198 | V_199 ) ;
V_39 -> V_42 . V_166 [ 0 ] |= V_2 -> V_5 [ 0 ] . V_8 ;
V_39 -> V_42 . V_166 [ 0 ] |=
V_2 -> V_5 [ 0 ] . V_6 << V_200 ;
V_39 -> V_42 . V_166 [ 1 ] = F_16 ( V_207 ) &
~ ( V_198 | V_199 ) ;
V_39 -> V_42 . V_166 [ 1 ] |= V_2 -> V_5 [ 1 ] . V_8 ;
V_39 -> V_42 . V_166 [ 1 ] |=
V_2 -> V_5 [ 1 ] . V_6 << V_200 ;
F_81 ( V_2 ) ;
return 0 ;
V_211:
F_124 ( V_2 ) ;
F_125 ( V_2 -> V_80 [ 0 ] ) ;
F_125 ( V_2 -> V_80 [ 1 ] ) ;
return - 1 ;
}
void F_144 ( struct V_1 * V_2 )
{
F_124 ( V_2 ) ;
F_125 ( V_2 -> V_63 ) ;
F_125 ( V_2 -> V_80 [ 0 ] ) ;
F_125 ( V_2 -> V_80 [ 1 ] ) ;
}
