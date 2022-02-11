static inline int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_4 = - 1 ;
V_3 = ++ ( F_2 ( V_5 ) ) ;
if ( V_3 < V_6 ) {
F_2 ( V_7 ) . V_2 [ V_3 ] = V_2 ;
V_2 -> V_8 = V_3 ;
V_2 -> V_9 = & F_2 ( V_7 ) . V_2 [ V_3 ] ;
V_4 = V_3 ;
}
F_3 ( V_3 > V_6 ) ;
return V_4 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_8 != 0 &&
F_2 ( V_7 ) . V_2 [ V_2 -> V_8 ] == V_2 &&
V_2 -> V_9 == & F_2 ( V_7 ) . V_2 [ V_2 -> V_8 ] )
return V_2 -> V_8 ;
return - 1 ;
}
static inline void F_5 ( void )
{
F_6 () ;
F_2 ( V_5 ) = 0 ;
memset ( & F_2 ( V_7 ) , 0 , sizeof( F_2 ( V_7 ) ) ) ;
F_7 () ;
}
static void * F_8 ( struct V_10 * V_11 )
{
V_11 -> V_12 = F_9 ( sizeof( struct V_13 ) , V_14 ) ;
return V_11 -> V_12 ;
}
static void F_10 ( struct V_10 * V_11 )
{
F_11 ( V_11 -> V_12 ) ;
}
static void F_12 ( struct V_10 * V_11 )
{
memset ( V_11 -> V_12 , 0 , sizeof( struct V_13 ) ) ;
F_13 ( V_11 ) ;
}
static inline void F_14 (
struct V_10 * V_11 ,
int V_15 , int V_16 , int V_17 )
{
struct V_13 * V_12 = V_11 -> V_12 ;
F_15 ( V_15 >= 2 ) ;
F_15 ( V_16 >= V_6 ) ;
F_15 ( V_17 >= 2 ) ;
V_12 -> V_1 [ V_15 ] [ V_16 ] [ V_17 ] . V_8 = 0 ;
V_12 -> V_1 [ V_15 ] [ V_16 ] [ V_17 ] . V_9 = NULL ;
F_13 ( V_11 ) ;
}
static unsigned int F_16 ( struct V_10 * V_11 ,
unsigned int V_15 , unsigned int V_18 ,
unsigned int V_17 , int V_19 )
{
struct V_13 * V_12 = V_11 -> V_12 ;
int V_3 ;
F_15 ( V_15 >= 2 ) ;
F_15 ( V_18 >= V_6 ) ;
F_15 ( V_17 >= 2 ) ;
V_3 = F_4 ( & V_12 -> V_1 [ V_15 ] [ V_18 ] [ V_17 ] ) ;
while ( V_3 <= 0 ) {
V_3 = F_1 ( & V_12 -> V_1 [ V_15 ] [ V_18 ] [ V_17 ] ) ;
if ( V_3 <= 0 ) {
F_17 () ;
F_5 () ;
}
if ( ! V_19 )
F_13 ( V_11 ) ;
}
return V_3 ;
}
void F_13 ( struct V_10 * V_11 )
{
F_6 () ;
V_11 -> V_20 . V_21 . V_22 = F_16 ( V_11 ,
F_18 ( & V_11 -> V_20 ) ,
F_19 ( & V_11 -> V_20 ) ,
F_20 ( & V_11 -> V_20 ) , 1 ) ;
V_11 -> V_20 . V_21 . V_23 = F_16 ( V_11 ,
F_18 ( & V_11 -> V_20 ) , 0 ,
F_20 ( & V_11 -> V_20 ) , 1 ) ;
F_7 () ;
}
void F_21 ( struct V_24 * V_20 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
struct V_25 * V_25 ;
int V_26 , V_27 ;
F_23 ( L_1 ,
L_2 , L_3 , L_4 , L_5 , L_6 ) ;
for ( V_27 = 0 ; V_27 < 2 ; V_27 ++ ) {
F_23 ( L_7 , V_27 ) ;
for ( V_26 = 0 ; V_26 < V_11 -> V_28 [ V_27 ] ; V_26 ++ ) {
V_25 = & V_11 -> V_29 [ V_27 ] [ V_26 ] ;
if ( V_25 -> V_30 & V_31 )
F_23 ( L_8 ,
V_27 , V_26 , V_25 -> V_30 , V_25 -> V_32 ,
V_25 -> V_33 , V_25 -> V_34 ) ;
}
}
}
static inline unsigned int F_24 (
struct V_10 * V_11 )
{
unsigned int V_35 ;
V_35 = V_11 -> V_36 [ 0 ] ++ ;
if ( F_25 ( V_11 -> V_36 [ 0 ] >= V_37 ) )
V_11 -> V_36 [ 0 ] = 0 ;
return V_35 ;
}
static inline unsigned int F_26 ( void )
{
return V_38 - V_39 - 1 ;
}
static inline int F_27 ( struct V_25 * V_25 )
{
return V_25 -> V_33 & ( V_40 | V_41 ) ;
}
static inline T_1 F_28 ( T_1 V_33 , int V_42 )
{
V_33 &= V_43 ;
if ( ! V_42 ) {
V_33 &= ~ V_44 ;
V_33 |= ( V_33 & V_45 ) << 1 ;
}
return V_33 | V_45 ;
}
static inline T_1 F_29 ( T_1 V_32 , int V_42 )
{
#ifdef F_30
return ( V_32 & V_46 ) | V_47 ;
#else
return V_32 & V_46 ;
#endif
}
static inline void F_31 ( struct V_25 * V_48 , T_2 V_49 )
{
unsigned long V_50 ;
F_32 ( V_50 ) ;
F_33 ( V_51 , V_49 ) ;
F_33 ( V_52 , V_48 -> V_30 ) ;
F_33 ( V_53 , V_48 -> V_32 ) ;
F_33 ( V_54 , V_48 -> V_33 ) ;
F_33 ( V_55 , V_48 -> V_34 ) ;
asm volatile("isync; tlbwe" : : : "memory");
F_34 ( V_50 ) ;
}
static inline void F_35 ( struct V_10 * V_11 ,
int V_27 , int V_56 , struct V_25 * V_48 )
{
if ( V_27 == 0 ) {
F_31 ( V_48 ,
F_36 ( 0 ) |
F_37 ( V_56 & ( V_37 - 1 ) ) ) ;
} else {
F_31 ( V_48 ,
F_36 ( 1 ) |
F_37 ( F_38 ( V_56 ) ) ) ;
}
F_39 ( F_40 ( V_27 , V_56 ) , V_48 -> V_30 , V_48 -> V_32 ,
V_48 -> V_33 , V_48 -> V_34 ) ;
}
void F_41 ( struct V_24 * V_20 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
struct V_25 V_57 ;
T_3 V_58 = ( ( T_3 ) V_20 -> V_21 . V_59 ) & V_60 ;
unsigned int V_61 ;
T_4 V_62 ;
V_62 = ( T_4 ) F_42 ( ( void * ) V_58 ) >> V_63 ;
F_43 ( F_44 ( V_62 ) ) ;
F_6 () ;
V_61 = F_16 ( V_11 , 0 , 0 , 0 , 0 ) ;
V_57 . V_30 = V_31 | V_64 | F_45 ( V_61 ) |
F_46 ( V_65 ) ;
V_57 . V_32 = V_20 -> V_21 . V_66 | V_47 ;
V_57 . V_33 = ( V_62 << V_63 ) |
V_40 | V_67 | V_41 | V_68 ;
V_57 . V_34 = V_62 >> ( 32 - V_63 ) ;
F_31 ( & V_57 , F_36 ( 1 ) | F_37 ( V_39 ) ) ;
F_7 () ;
}
void F_47 ( struct V_24 * V_20 , int V_69 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
F_13 ( V_11 ) ;
}
void F_48 ( struct V_24 * V_20 )
{
}
static void F_49 ( struct V_10 * V_11 ,
int V_27 , int V_56 )
{
struct V_25 * V_70 = & V_11 -> V_29 [ V_27 ] [ V_56 ] ;
struct V_13 * V_12 = V_11 -> V_12 ;
unsigned int V_17 , V_71 , V_72 , V_16 ;
T_1 V_8 , V_73 ;
unsigned long V_50 ;
V_72 = F_50 ( V_70 ) ;
V_71 = F_51 ( V_70 ) ;
F_6 () ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
if ( V_27 == 1 ||
( V_16 = F_4 ( & V_12 -> V_1 [ V_72 ] [ V_71 ] [ V_17 ] ) ) <= 0 ) {
F_14 ( V_11 , V_72 , V_71 , V_17 ) ;
continue;
}
V_8 = ( V_16 << V_74 ) | V_75 ;
V_73 = F_52 ( V_70 ) ;
F_32 ( V_50 ) ;
F_33 ( V_76 , V_8 ) ;
asm volatile("tlbsx 0, %[eaddr]" : : [eaddr] "r" (eaddr));
V_8 = F_53 ( V_52 ) ;
if ( V_8 & V_31 ) {
F_33 ( V_52 , V_8 & ~ V_31 ) ;
asm volatile("tlbwe");
}
F_34 ( V_50 ) ;
}
F_7 () ;
}
static int F_54 ( struct V_10 * V_11 ,
T_5 V_73 , int V_27 , unsigned int V_16 , int V_15 )
{
int V_77 = V_11 -> V_28 [ V_27 ] ;
int V_78 ;
int V_26 ;
if ( V_27 == 0 ) {
int V_79 = V_77 / V_37 - 1 ;
V_78 = ( V_73 >> V_63 ) & V_79 ;
V_78 *= V_37 ;
V_77 = V_37 ;
} else {
V_78 = 0 ;
}
for ( V_26 = 0 ; V_26 < V_77 ; V_26 ++ ) {
struct V_25 * V_25 = & V_11 -> V_29 [ V_27 ] [ V_78 + V_26 ] ;
unsigned int V_71 ;
if ( V_73 < F_52 ( V_25 ) )
continue;
if ( V_73 > F_55 ( V_25 ) )
continue;
V_71 = F_51 ( V_25 ) ;
if ( V_71 && ( V_71 != V_16 ) )
continue;
if ( ! F_56 ( V_25 ) )
continue;
if ( F_50 ( V_25 ) != V_15 && V_15 != - 1 )
continue;
return V_78 + V_26 ;
}
return - 1 ;
}
static inline void F_57 ( struct V_80 * V_81 ,
struct V_25 * V_70 ,
T_4 V_62 )
{
V_81 -> V_62 = V_62 ;
V_81 -> V_50 = V_82 ;
if ( F_27 ( V_70 ) )
V_81 -> V_50 |= V_83 ;
}
static inline void F_58 ( struct V_80 * V_81 )
{
if ( V_81 -> V_50 & V_82 ) {
if ( V_81 -> V_50 & V_83 )
F_59 ( V_81 -> V_62 ) ;
else
F_60 ( V_81 -> V_62 ) ;
V_81 -> V_50 = 0 ;
}
}
static inline void F_61 ( struct V_24 * V_20 ,
unsigned int V_73 , int V_15 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
unsigned int V_35 , V_84 , V_85 ;
int V_27 ;
V_27 = ( V_11 -> V_86 >> 28 ) & 0x1 ;
V_35 = ( V_27 == 0 ) ? F_24 ( V_11 ) : 0 ;
V_84 = ( V_11 -> V_86 >> 16 ) & 0xf ;
V_85 = ( V_11 -> V_86 >> 7 ) & 0x1f ;
V_11 -> V_49 = F_36 ( V_27 ) | F_37 ( V_35 )
| F_62 ( V_11 -> V_36 [ V_27 ] ) ;
V_11 -> V_30 = V_31 | ( V_15 ? V_64 : 0 )
| F_45 ( V_11 -> V_16 [ V_84 ] )
| F_46 ( V_85 ) ;
V_11 -> V_32 = ( V_73 & V_87 )
| ( V_11 -> V_86 & V_46 ) ;
V_11 -> V_33 &= V_88 | V_89 | V_90 | V_91 ;
V_11 -> V_92 = ( V_11 -> V_92 & V_93 )
| ( F_19 ( V_20 ) << 16 )
| ( V_15 ? V_75 : 0 ) ;
V_11 -> V_34 = 0 ;
}
static inline void F_63 ( struct V_10 * V_11 ,
struct V_25 * V_70 , int V_94 ,
struct V_80 * V_81 ,
T_6 V_95 , struct V_25 * V_48 )
{
T_4 V_62 = V_81 -> V_62 ;
unsigned int V_61 ;
V_61 = F_16 ( V_11 , F_50 ( V_70 ) ,
F_51 ( V_70 ) ,
F_20 ( & V_11 -> V_20 ) , 0 ) ;
V_48 -> V_30 = F_46 ( V_94 )
| F_45 ( V_61 ) | V_64 | V_31 ;
V_48 -> V_32 = ( V_95 & V_87 )
| F_29 ( V_70 -> V_32 ,
V_11 -> V_20 . V_21 . V_59 -> V_96 & V_97 ) ;
V_48 -> V_33 = ( ( V_62 << V_63 ) & V_98 )
| F_28 ( V_70 -> V_33 ,
V_11 -> V_20 . V_21 . V_59 -> V_96 & V_97 ) ;
V_48 -> V_34 = ( V_62 >> ( 32 - V_63 ) ) & V_99 ;
}
static inline void F_64 ( struct V_10 * V_11 ,
T_6 V_95 , T_7 V_100 , struct V_25 * V_70 , int V_27 , int V_56 ,
struct V_25 * V_48 )
{
struct V_101 * V_102 ;
unsigned long V_62 , V_103 ;
int V_104 = 0 ;
int V_94 = V_65 ;
struct V_80 * V_81 ;
V_102 = F_65 ( V_11 -> V_20 . V_105 , V_100 ) ;
V_103 = F_66 ( V_102 , V_100 ) ;
if ( V_27 == 1 ) {
struct V_106 * V_107 ;
F_67 ( & V_108 -> V_109 -> V_110 ) ;
V_107 = F_68 ( V_108 -> V_109 , V_103 ) ;
if ( V_107 && V_103 >= V_107 -> V_111 &&
( V_107 -> V_112 & V_113 ) ) {
unsigned long V_114 , V_115 ;
unsigned long V_116 , V_117 ;
V_104 = 1 ;
V_114 = V_107 -> V_118 ;
V_115 = V_114 +
( ( V_107 -> V_119 - V_107 -> V_111 ) >> V_63 ) ;
V_62 = V_114 + ( ( V_103 - V_107 -> V_111 ) >> V_63 ) ;
V_116 = V_62 - ( V_100 - V_102 -> V_120 ) ;
V_117 = V_116 + V_102 -> V_121 ;
if ( V_114 < V_116 )
V_114 = V_116 ;
if ( V_115 > V_117 )
V_115 = V_117 ;
V_94 = ( V_70 -> V_30 & V_122 ) >>
V_123 ;
V_94 = F_69 ( V_65 , V_94 & ~ 1 ) ;
for (; V_94 > V_65 ; V_94 -= 2 ) {
unsigned long V_124 , V_125 , V_126 ;
V_126 = 1 << ( V_94 - 2 ) ;
V_124 = V_100 & ~ ( V_126 - 1 ) ;
V_125 = V_124 + V_126 ;
if ( V_124 + V_62 - V_100 < V_114 )
continue;
if ( V_125 + V_62 - V_100 > V_115 )
continue;
if ( ( V_100 & ( V_126 - 1 ) ) !=
( V_62 & ( V_126 - 1 ) ) )
continue;
V_95 &= ~ ( ( V_126 << V_63 ) - 1 ) ;
V_62 &= ~ ( V_126 - 1 ) ;
break;
}
}
F_70 ( & V_108 -> V_109 -> V_110 ) ;
}
if ( F_71 ( ! V_104 ) ) {
V_62 = F_72 ( V_11 -> V_20 . V_105 , V_102 , V_100 ) ;
if ( F_73 ( V_62 ) ) {
F_23 ( V_127 L_9 ,
( long ) V_100 ) ;
F_60 ( V_62 ) ;
return;
}
}
V_81 = & V_11 -> V_128 [ V_27 ] [ V_56 ] ;
F_58 ( V_81 ) ;
F_57 ( V_81 , V_70 , V_62 ) ;
F_63 ( V_11 , V_70 , V_94 , V_81 , V_95 , V_48 ) ;
}
static int F_74 ( struct V_10 * V_11 ,
int V_56 , struct V_25 * V_48 )
{
struct V_25 * V_70 ;
V_70 = & V_11 -> V_29 [ 0 ] [ V_56 ] ;
F_64 ( V_11 , F_52 ( V_70 ) ,
F_75 ( V_70 ) >> V_63 ,
V_70 , 0 , V_56 , V_48 ) ;
return V_56 ;
}
static int F_76 ( struct V_10 * V_11 ,
T_6 V_95 , T_7 V_100 , struct V_25 * V_70 , struct V_25 * V_48 )
{
unsigned int V_35 ;
V_35 = V_11 -> V_36 [ 1 ] ++ ;
if ( F_25 ( V_11 -> V_36 [ 1 ] >= F_26 () ) )
V_11 -> V_36 [ 1 ] = 0 ;
F_64 ( V_11 , V_95 , V_100 , V_70 , 1 , V_35 , V_48 ) ;
return V_35 ;
}
void F_77 ( struct V_24 * V_20 , T_1 V_129 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
F_13 ( V_11 ) ;
}
static inline int F_78 (
struct V_10 * V_11 ,
int V_27 , int V_56 )
{
struct V_25 * V_70 = & V_11 -> V_29 [ V_27 ] [ V_56 ] ;
if ( F_25 ( F_79 ( V_70 ) ) )
return - 1 ;
V_70 -> V_30 = 0 ;
return 0 ;
}
int F_80 ( struct V_10 * V_11 , T_3 V_130 )
{
int V_56 ;
if ( V_130 & V_131 )
for ( V_56 = 0 ; V_56 < V_11 -> V_28 [ 0 ] ; V_56 ++ )
F_78 ( V_11 , 0 , V_56 ) ;
if ( V_130 & V_132 )
for ( V_56 = 0 ; V_56 < V_11 -> V_28 [ 1 ] ; V_56 ++ )
F_78 ( V_11 , 1 , V_56 ) ;
F_12 ( V_11 ) ;
return V_133 ;
}
int F_81 ( struct V_24 * V_20 , int V_134 , int V_135 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
unsigned int V_136 ;
int V_56 , V_27 ;
T_5 V_137 ;
V_137 = ( ( V_134 ) ? F_82 ( V_20 , V_134 ) : 0 ) + F_82 ( V_20 , V_135 ) ;
V_136 = ( V_137 >> 2 ) & 0x1 ;
V_27 = ( V_137 >> 3 ) & 0x1 ;
if ( V_136 ) {
for ( V_56 = 0 ; V_56 < V_11 -> V_28 [ V_27 ] ; V_56 ++ )
F_78 ( V_11 , V_27 , V_56 ) ;
} else {
V_137 &= 0xfffff000 ;
V_56 = F_54 ( V_11 , V_137 , V_27 ,
F_19 ( V_20 ) , - 1 ) ;
if ( V_56 >= 0 )
F_78 ( V_11 , V_27 , V_56 ) ;
}
F_12 ( V_11 ) ;
return V_133 ;
}
int F_83 ( struct V_24 * V_20 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
int V_27 , V_56 ;
struct V_25 * V_70 ;
V_27 = F_84 ( V_11 ) ;
V_56 = F_85 ( V_11 , V_27 ) ;
V_70 = & V_11 -> V_29 [ V_27 ] [ V_56 ] ;
V_11 -> V_49 &= ~ F_62 ( ~ 0 ) ;
V_11 -> V_49 |= F_62 ( V_11 -> V_36 [ V_27 ] ) ;
V_11 -> V_30 = V_70 -> V_30 ;
V_11 -> V_32 = V_70 -> V_32 ;
V_11 -> V_33 = V_70 -> V_33 ;
V_11 -> V_34 = V_70 -> V_34 ;
return V_133 ;
}
int F_86 ( struct V_24 * V_20 , int V_135 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
int V_15 = ! ! F_87 ( V_11 ) ;
unsigned int V_16 = F_88 ( V_11 ) ;
int V_56 , V_27 ;
struct V_25 * V_70 = NULL ;
T_5 V_137 ;
V_137 = F_82 ( V_20 , V_135 ) ;
for ( V_27 = 0 ; V_27 < 2 ; V_27 ++ ) {
V_56 = F_54 ( V_11 , V_137 , V_27 , V_16 , V_15 ) ;
if ( V_56 >= 0 ) {
V_70 = & V_11 -> V_29 [ V_27 ] [ V_56 ] ;
break;
}
}
if ( V_70 ) {
V_11 -> V_49 = F_36 ( V_27 ) | F_37 ( V_56 )
| F_62 ( V_11 -> V_36 [ V_27 ] ) ;
V_11 -> V_30 = V_70 -> V_30 ;
V_11 -> V_32 = V_70 -> V_32 ;
V_11 -> V_33 = V_70 -> V_33 ;
V_11 -> V_34 = V_70 -> V_34 ;
} else {
int V_35 ;
V_27 = V_11 -> V_86 >> 28 & 0x1 ;
V_35 = ( V_27 == 0 ) ? F_24 ( V_11 ) : 0 ;
V_11 -> V_49 = F_36 ( V_27 ) | F_37 ( V_35 )
| F_62 ( V_11 -> V_36 [ V_27 ] ) ;
V_11 -> V_30 = ( V_11 -> V_92 & V_138 )
| ( V_11 -> V_92 & ( V_75 ? V_64 : 0 ) )
| ( V_11 -> V_86 & F_89 ( ~ 0 ) ) ;
V_11 -> V_32 &= V_87 ;
V_11 -> V_32 |= V_11 -> V_86 & V_46 ;
V_11 -> V_33 &= V_88 | V_89 | V_90 | V_91 ;
V_11 -> V_34 = 0 ;
}
F_90 ( V_20 , V_139 ) ;
return V_133 ;
}
int F_91 ( struct V_24 * V_20 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
struct V_25 * V_70 ;
int V_27 , V_56 ;
V_27 = F_84 ( V_11 ) ;
V_56 = F_85 ( V_11 , V_27 ) ;
V_70 = & V_11 -> V_29 [ V_27 ] [ V_56 ] ;
if ( F_56 ( V_70 ) )
F_49 ( V_11 , V_27 , V_56 ) ;
V_70 -> V_30 = V_11 -> V_30 ;
V_70 -> V_32 = V_11 -> V_32 ;
V_70 -> V_33 = V_11 -> V_33 ;
V_70 -> V_34 = V_11 -> V_34 ;
F_92 ( V_11 -> V_49 , V_70 -> V_30 , V_70 -> V_32 ,
V_70 -> V_33 , V_70 -> V_34 ) ;
if ( F_93 ( V_20 , V_70 ) ) {
struct V_25 V_48 ;
int V_140 , V_141 ;
T_6 V_73 ;
T_6 V_142 ;
F_6 () ;
switch ( V_27 ) {
case 0 :
V_70 -> V_30 &= ~ F_46 ( ~ 0 ) ;
V_70 -> V_30 |= F_46 ( V_65 ) ;
V_140 = 0 ;
V_141 = F_74 ( V_11 , V_56 , & V_48 ) ;
break;
case 1 :
V_73 = F_52 ( V_70 ) ;
V_142 = F_75 ( V_70 ) ;
V_140 = 1 ;
V_141 = F_76 ( V_11 , V_73 ,
V_142 >> V_63 , V_70 , & V_48 ) ;
break;
default:
F_94 () ;
}
F_35 ( V_11 , V_140 , V_141 , & V_48 ) ;
F_7 () ;
}
F_90 ( V_20 , V_143 ) ;
return V_133 ;
}
int F_95 ( struct V_24 * V_20 , T_5 V_73 )
{
unsigned int V_15 = ! ! ( V_20 -> V_21 . V_59 -> V_96 & V_144 ) ;
return F_96 ( V_20 , V_73 , F_19 ( V_20 ) , V_15 ) ;
}
int F_97 ( struct V_24 * V_20 , T_5 V_73 )
{
unsigned int V_15 = ! ! ( V_20 -> V_21 . V_59 -> V_96 & V_145 ) ;
return F_96 ( V_20 , V_73 , F_19 ( V_20 ) , V_15 ) ;
}
void F_98 ( struct V_24 * V_20 )
{
unsigned int V_15 = ! ! ( V_20 -> V_21 . V_59 -> V_96 & V_144 ) ;
F_61 ( V_20 , V_20 -> V_21 . V_146 , V_15 ) ;
}
void F_99 ( struct V_24 * V_20 )
{
unsigned int V_15 = ! ! ( V_20 -> V_21 . V_59 -> V_96 & V_145 ) ;
F_61 ( V_20 , V_20 -> V_21 . V_147 , V_15 ) ;
}
T_8 F_100 ( struct V_24 * V_20 , unsigned int V_148 ,
T_5 V_73 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
struct V_25 * V_70 =
& V_11 -> V_29 [ F_101 ( V_148 ) ] [ F_102 ( V_148 ) ] ;
T_6 V_149 = F_103 ( V_70 ) - 1 ;
return F_75 ( V_70 ) | ( V_73 & V_149 ) ;
}
void F_104 ( struct V_24 * V_20 )
{
}
void F_105 ( struct V_24 * V_20 , T_6 V_73 , T_8 V_150 ,
unsigned int V_148 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
struct V_80 * V_81 ;
struct V_25 * V_70 , V_48 ;
int V_27 = F_101 ( V_148 ) ;
int V_56 = F_102 ( V_148 ) ;
int V_140 , V_141 ;
V_70 = & V_11 -> V_29 [ V_27 ] [ V_56 ] ;
F_6 () ;
switch ( V_27 ) {
case 0 :
V_140 = 0 ;
V_141 = V_56 ;
V_81 = & V_11 -> V_128 [ V_140 ] [ V_141 ] ;
F_63 ( V_11 , V_70 , V_65 ,
V_81 , V_73 , & V_48 ) ;
break;
case 1 : {
T_7 V_100 = V_150 >> V_63 ;
V_140 = 1 ;
V_141 = F_76 ( V_11 , V_73 , V_100 ,
V_70 , & V_48 ) ;
break;
}
default:
F_94 () ;
break;
}
F_35 ( V_11 , V_140 , V_141 , & V_48 ) ;
F_7 () ;
}
int F_96 ( struct V_24 * V_20 ,
T_5 V_73 , unsigned int V_16 , int V_15 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
int V_56 , V_27 ;
for ( V_27 = 0 ; V_27 < 2 ; V_27 ++ ) {
V_56 = F_54 ( V_11 , V_73 , V_27 , V_16 , V_15 ) ;
if ( V_56 >= 0 )
return F_40 ( V_27 , V_56 ) ;
}
return - 1 ;
}
void F_106 ( struct V_24 * V_20 , T_1 V_16 )
{
struct V_10 * V_11 = F_22 ( V_20 ) ;
if ( V_20 -> V_21 . V_16 != V_16 ) {
V_11 -> V_16 [ 0 ] = V_20 -> V_21 . V_16 = V_16 ;
F_13 ( V_11 ) ;
}
}
void F_107 ( struct V_10 * V_11 )
{
struct V_25 * V_25 ;
V_25 = & V_11 -> V_29 [ 1 ] [ 0 ] ;
V_25 -> V_30 = V_31 | F_46 ( V_151 ) ;
V_25 -> V_32 = 0 ;
V_25 -> V_33 = V_45 ;
V_25 -> V_34 = 0 ;
V_25 = & V_11 -> V_29 [ 1 ] [ 1 ] ;
V_25 -> V_30 = V_31 | F_46 ( V_65 ) ;
V_25 -> V_32 = ( 0xe0004500 & 0xFFFFF000 ) | V_152 | V_153 ;
V_25 -> V_33 = ( 0xe0004500 & 0xFFFFF000 ) | V_45 ;
V_25 -> V_34 = 0 ;
}
int F_108 ( struct V_10 * V_11 )
{
V_38 = F_53 ( V_154 ) & 0xFFF ;
V_11 -> V_28 [ 0 ] = V_155 ;
V_11 -> V_29 [ 0 ] =
F_9 ( sizeof( struct V_25 ) * V_155 , V_14 ) ;
if ( V_11 -> V_29 [ 0 ] == NULL )
goto V_156;
V_11 -> V_28 [ 1 ] = V_157 ;
V_11 -> V_29 [ 1 ] =
F_9 ( sizeof( struct V_25 ) * V_157 , V_14 ) ;
if ( V_11 -> V_29 [ 1 ] == NULL )
goto V_158;
V_11 -> V_128 [ 0 ] = (struct V_80 * )
F_9 ( sizeof( struct V_80 ) * V_155 , V_14 ) ;
if ( V_11 -> V_128 [ 0 ] == NULL )
goto V_159;
V_11 -> V_128 [ 1 ] = (struct V_80 * )
F_9 ( sizeof( struct V_80 ) * V_157 , V_14 ) ;
if ( V_11 -> V_128 [ 1 ] == NULL )
goto V_160;
if ( F_8 ( V_11 ) == NULL )
goto V_161;
V_11 -> V_162 = F_53 ( V_163 ) & ~ 0xfffUL ;
V_11 -> V_162 |= V_11 -> V_28 [ 0 ] ;
V_11 -> V_164 = F_53 ( V_154 ) & ~ 0xfffUL ;
V_11 -> V_164 |= V_11 -> V_28 [ 1 ] ;
return 0 ;
V_161:
F_11 ( V_11 -> V_128 [ 1 ] ) ;
V_160:
F_11 ( V_11 -> V_128 [ 0 ] ) ;
V_159:
F_11 ( V_11 -> V_29 [ 1 ] ) ;
V_158:
F_11 ( V_11 -> V_29 [ 0 ] ) ;
V_156:
return - 1 ;
}
void F_109 ( struct V_10 * V_11 )
{
int V_140 , V_26 ;
for ( V_140 = 0 ; V_140 < 2 ; V_140 ++ )
for ( V_26 = 0 ; V_26 < V_11 -> V_28 [ V_140 ] ; V_26 ++ ) {
struct V_80 * V_81 =
& V_11 -> V_128 [ V_140 ] [ V_26 ] ;
F_58 ( V_81 ) ;
}
F_10 ( V_11 ) ;
F_11 ( V_11 -> V_29 [ 1 ] ) ;
F_11 ( V_11 -> V_29 [ 0 ] ) ;
}
