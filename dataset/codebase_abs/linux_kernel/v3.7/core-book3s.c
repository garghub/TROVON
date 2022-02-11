static inline unsigned long F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 * V_3 ) { }
static inline T_2 F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_4 = 0 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
return 1 ;
}
static inline unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_5 = V_2 -> V_6 ;
if ( ( V_5 & V_7 ) && ! ( V_8 -> V_9 & V_10 ) ) {
unsigned long V_11 = ( V_5 & V_12 ) >> V_13 ;
if ( V_11 > 1 )
return 4 * ( V_11 - 1 ) ;
}
return 0 ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned long V_5 = V_2 -> V_6 ;
unsigned long V_14 ;
if ( V_8 -> V_9 & V_15 )
V_14 = V_16 ;
else if ( V_8 -> V_9 & V_10 )
V_14 = V_17 ;
else
V_14 = V_18 ;
if ( ! ( V_5 & V_7 ) || ( V_5 & V_14 ) )
* V_3 = F_7 ( V_19 ) ;
}
static bool F_8 ( unsigned long V_5 )
{
unsigned long V_20 = V_21 ;
if ( V_8 -> V_9 & V_10 )
V_20 = V_22 ;
return ! ! ( V_5 & V_20 ) ;
}
static bool F_9 ( unsigned long V_5 )
{
unsigned long V_23 = V_24 ;
if ( V_8 -> V_9 & V_10 )
V_23 = V_25 ;
return ! ! ( V_5 & V_23 ) ;
}
static inline T_2 F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 & V_27 )
return V_28 ;
if ( ( V_2 -> V_26 & V_29 ) && V_30 != V_31 )
return V_32 ;
return V_33 ;
}
static inline T_2 F_3 ( struct V_1 * V_2 )
{
unsigned long V_5 = V_2 -> V_6 ;
unsigned long V_34 = V_2 -> V_4 ;
if ( ! V_34 )
return F_10 ( V_2 ) ;
if ( V_8 -> V_9 & V_35 ) {
unsigned long V_36 = F_7 ( V_37 ) ;
if ( V_36 >= V_38 )
return V_33 ;
return V_28 ;
}
if ( F_9 ( V_5 ) )
return V_28 ;
if ( F_8 ( V_5 ) && ( V_30 != V_31 ) )
return V_32 ;
return V_33 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned long V_5 = F_7 ( V_39 ) ;
int V_40 = V_5 & V_7 ;
int V_34 ;
if ( F_11 ( V_2 ) != 0xf00 )
V_34 = 0 ;
else if ( V_40 )
V_34 = 1 ;
else if ( ( V_8 -> V_9 & V_41 ) )
V_34 = 0 ;
else if ( ! ( V_8 -> V_9 & V_35 ) && F_9 ( V_5 ) )
V_34 = 0 ;
else
V_34 = 1 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_4 = V_34 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return ! V_2 -> V_42 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
unsigned long V_5 = V_2 -> V_6 ;
int V_40 = V_5 & V_7 ;
if ( ( V_8 -> V_9 & V_15 ) && V_40 )
return V_5 & V_43 ;
return 1 ;
}
void F_12 ( void )
{
}
static unsigned long F_13 ( int V_44 )
{
unsigned long V_45 ;
switch ( V_44 ) {
case 1 :
V_45 = F_7 ( V_46 ) ;
break;
case 2 :
V_45 = F_7 ( V_47 ) ;
break;
case 3 :
V_45 = F_7 ( V_48 ) ;
break;
case 4 :
V_45 = F_7 ( V_49 ) ;
break;
case 5 :
V_45 = F_7 ( V_50 ) ;
break;
case 6 :
V_45 = F_7 ( V_51 ) ;
break;
#ifdef F_14
case 7 :
V_45 = F_7 ( V_52 ) ;
break;
case 8 :
V_45 = F_7 ( V_53 ) ;
break;
#endif
default:
F_15 ( V_54 L_1 , V_44 ) ;
V_45 = 0 ;
}
return V_45 ;
}
static void F_16 ( int V_44 , unsigned long V_45 )
{
switch ( V_44 ) {
case 1 :
F_17 ( V_46 , V_45 ) ;
break;
case 2 :
F_17 ( V_47 , V_45 ) ;
break;
case 3 :
F_17 ( V_48 , V_45 ) ;
break;
case 4 :
F_17 ( V_49 , V_45 ) ;
break;
case 5 :
F_17 ( V_50 , V_45 ) ;
break;
case 6 :
F_17 ( V_51 , V_45 ) ;
break;
#ifdef F_14
case 7 :
F_17 ( V_52 , V_45 ) ;
break;
case 8 :
F_17 ( V_53 , V_45 ) ;
break;
#endif
default:
F_15 ( V_54 L_2 , V_44 ) ;
}
}
static int F_18 ( struct V_55 * V_56 ,
T_1 V_57 [] , unsigned int V_58 [] ,
int V_59 )
{
unsigned long V_60 , V_61 , V_62 ;
unsigned long V_63 [ V_64 ] , V_65 [ V_64 ] ;
int V_66 [ V_64 ] , V_67 [ V_64 ] ;
int V_68 , V_69 ;
unsigned long V_70 = V_8 -> V_71 ;
unsigned long V_72 = V_8 -> V_73 ;
if ( V_59 > V_8 -> V_74 )
return - 1 ;
for ( V_68 = 0 ; V_68 < V_59 ; ++ V_68 ) {
if ( ( V_58 [ V_68 ] & V_75 )
&& ! V_8 -> V_76 ( V_57 [ V_68 ] ) ) {
V_8 -> V_77 ( V_57 [ V_68 ] , V_58 [ V_68 ] ,
V_56 -> V_78 [ V_68 ] ) ;
V_57 [ V_68 ] = V_56 -> V_78 [ V_68 ] [ 0 ] ;
}
if ( V_8 -> V_79 ( V_57 [ V_68 ] , & V_56 -> V_80 [ V_68 ] [ 0 ] ,
& V_56 -> V_81 [ V_68 ] [ 0 ] ) )
return - 1 ;
}
V_61 = V_60 = 0 ;
for ( V_68 = 0 ; V_68 < V_59 ; ++ V_68 ) {
V_62 = ( V_61 | V_56 -> V_81 [ V_68 ] [ 0 ] ) +
( V_61 & V_56 -> V_81 [ V_68 ] [ 0 ] & V_70 ) ;
if ( ( ( ( V_62 + V_72 ) ^ V_61 ) & V_60 ) != 0 ||
( ( ( V_62 + V_72 ) ^ V_56 -> V_81 [ V_68 ] [ 0 ] ) &
V_56 -> V_80 [ V_68 ] [ 0 ] ) != 0 )
break;
V_61 = V_62 ;
V_60 |= V_56 -> V_80 [ V_68 ] [ 0 ] ;
}
if ( V_68 == V_59 )
return 0 ;
if ( ! V_8 -> V_77 )
return - 1 ;
for ( V_68 = 0 ; V_68 < V_59 ; ++ V_68 ) {
V_67 [ V_68 ] = 0 ;
V_66 [ V_68 ] = V_8 -> V_77 ( V_57 [ V_68 ] , V_58 [ V_68 ] ,
V_56 -> V_78 [ V_68 ] ) ;
for ( V_69 = 1 ; V_69 < V_66 [ V_68 ] ; ++ V_69 )
V_8 -> V_79 ( V_56 -> V_78 [ V_68 ] [ V_69 ] ,
& V_56 -> V_80 [ V_68 ] [ V_69 ] ,
& V_56 -> V_81 [ V_68 ] [ V_69 ] ) ;
}
V_68 = 0 ;
V_69 = - 1 ;
V_61 = V_60 = V_62 = 0 ;
while ( V_68 < V_59 ) {
if ( V_69 >= 0 ) {
V_61 = V_65 [ V_68 ] ;
V_60 = V_63 [ V_68 ] ;
V_69 = V_67 [ V_68 ] ;
}
while ( ++ V_69 < V_66 [ V_68 ] ) {
V_62 = ( V_61 | V_56 -> V_81 [ V_68 ] [ V_69 ] ) +
( V_61 & V_56 -> V_81 [ V_68 ] [ V_69 ] & V_70 ) ;
if ( ( ( ( V_62 + V_72 ) ^ V_61 ) & V_60 ) == 0 &&
( ( ( V_62 + V_72 ) ^ V_56 -> V_81 [ V_68 ] [ V_69 ] )
& V_56 -> V_80 [ V_68 ] [ V_69 ] ) == 0 )
break;
}
if ( V_69 >= V_66 [ V_68 ] ) {
if ( -- V_68 < 0 )
return - 1 ;
} else {
V_67 [ V_68 ] = V_69 ;
V_65 [ V_68 ] = V_61 ;
V_63 [ V_68 ] = V_60 ;
V_61 = V_62 ;
V_60 |= V_56 -> V_80 [ V_68 ] [ V_69 ] ;
++ V_68 ;
V_69 = - 1 ;
}
}
for ( V_68 = 0 ; V_68 < V_59 ; ++ V_68 )
V_57 [ V_68 ] = V_56 -> V_78 [ V_68 ] [ V_67 [ V_68 ] ] ;
return 0 ;
}
static int F_19 ( struct V_82 * * V_83 , unsigned int V_58 [] ,
int V_84 , int V_85 )
{
int V_86 = 0 , V_87 = 0 , V_88 = 0 ;
int V_68 , V_89 , V_90 ;
struct V_82 * V_91 ;
V_89 = V_84 + V_85 ;
if ( V_89 <= 1 )
return 0 ;
V_90 = 1 ;
for ( V_68 = 0 ; V_68 < V_89 ; ++ V_68 ) {
if ( V_58 [ V_68 ] & V_92 ) {
V_58 [ V_68 ] &= ~ V_75 ;
continue;
}
V_91 = V_83 [ V_68 ] ;
if ( V_90 ) {
V_86 = V_91 -> V_93 . V_94 ;
V_87 = V_91 -> V_93 . V_95 ;
V_88 = V_91 -> V_93 . V_96 ;
V_90 = 0 ;
} else if ( V_91 -> V_93 . V_94 != V_86 ||
V_91 -> V_93 . V_95 != V_87 ||
V_91 -> V_93 . V_96 != V_88 ) {
return - V_97 ;
}
}
if ( V_86 || V_87 || V_88 )
for ( V_68 = 0 ; V_68 < V_89 ; ++ V_68 )
if ( V_58 [ V_68 ] & V_92 )
V_58 [ V_68 ] |= V_75 ;
return 0 ;
}
static T_1 F_20 ( T_1 V_98 , T_1 V_45 )
{
T_1 V_99 = ( V_45 - V_98 ) & 0xfffffffful ;
if ( V_98 > V_45 && ( V_98 - V_45 ) < 256 )
V_99 = 0 ;
return V_99 ;
}
static void F_21 ( struct V_82 * V_91 )
{
T_3 V_45 , V_99 , V_98 ;
if ( V_91 -> V_100 . V_101 & V_102 )
return;
if ( ! V_91 -> V_100 . V_44 )
return;
do {
V_98 = F_22 ( & V_91 -> V_100 . V_103 ) ;
F_23 () ;
V_45 = F_13 ( V_91 -> V_100 . V_44 ) ;
V_99 = F_20 ( V_98 , V_45 ) ;
if ( ! V_99 )
return;
} while ( F_24 ( & V_91 -> V_100 . V_103 , V_98 , V_45 ) != V_98 );
F_25 ( V_99 , & V_91 -> V_104 ) ;
F_26 ( V_99 , & V_91 -> V_100 . V_105 ) ;
}
static int F_27 ( int V_106 )
{
return ( V_8 -> V_9 & V_107 )
&& ( V_106 == 5 || V_106 == 6 ) ;
}
static void F_28 ( struct V_55 * V_56 ,
unsigned long V_108 , unsigned long V_109 )
{
struct V_82 * V_91 ;
T_1 V_45 , V_98 , V_99 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_56 -> V_110 ; ++ V_68 ) {
V_91 = V_56 -> V_111 [ V_68 ] ;
if ( ! V_91 -> V_100 . V_44 )
continue;
V_45 = ( V_91 -> V_100 . V_44 == 5 ) ? V_108 : V_109 ;
V_98 = F_22 ( & V_91 -> V_100 . V_103 ) ;
V_91 -> V_100 . V_44 = 0 ;
V_99 = F_20 ( V_98 , V_45 ) ;
if ( V_99 )
F_25 ( V_99 , & V_91 -> V_104 ) ;
}
}
static void F_29 ( struct V_55 * V_56 ,
unsigned long V_108 , unsigned long V_109 )
{
struct V_82 * V_91 ;
T_1 V_45 , V_98 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_56 -> V_110 ; ++ V_68 ) {
V_91 = V_56 -> V_111 [ V_68 ] ;
V_91 -> V_100 . V_44 = V_56 -> V_112 [ V_68 ] ;
V_45 = ( V_91 -> V_100 . V_44 == 5 ) ? V_108 : V_109 ;
V_98 = F_22 ( & V_91 -> V_100 . V_103 ) ;
if ( F_20 ( V_98 , V_45 ) )
F_30 ( & V_91 -> V_100 . V_103 , V_45 ) ;
F_31 ( V_91 ) ;
}
}
static void F_32 ( struct V_55 * V_56 , unsigned long V_113 )
{
unsigned long V_108 , V_109 ;
if ( ! V_56 -> V_110 ) {
F_17 ( V_114 , V_113 ) ;
return;
}
asm volatile("mtspr %3,%2; mfspr %0,%4; mfspr %1,%5"
: "=&r" (pmc5), "=&r" (pmc6)
: "r" (mmcr0 & ~(MMCR0_PMC1CE | MMCR0_PMCjCE)),
"i" (SPRN_MMCR0),
"i" (SPRN_PMC5), "i" (SPRN_PMC6));
if ( V_113 & V_115 )
F_28 ( V_56 , V_108 , V_109 ) ;
else
F_29 ( V_56 , V_108 , V_109 ) ;
if ( V_113 & ( V_116 | V_117 ) )
F_17 ( V_114 , V_113 ) ;
}
static void F_33 ( struct V_118 * V_118 )
{
struct V_55 * V_56 ;
unsigned long V_9 ;
if ( ! V_8 )
return;
F_34 ( V_9 ) ;
V_56 = & F_35 ( V_55 ) ;
if ( ! V_56 -> V_119 ) {
V_56 -> V_119 = 1 ;
V_56 -> V_120 = 0 ;
if ( ! V_56 -> V_121 ) {
F_36 () ;
V_56 -> V_121 = 1 ;
}
if ( V_56 -> V_122 [ 2 ] & V_7 ) {
F_17 ( V_39 ,
V_56 -> V_122 [ 2 ] & ~ V_7 ) ;
F_37 () ;
}
F_32 ( V_56 , F_7 ( V_114 ) | V_115 ) ;
F_37 () ;
}
F_38 ( V_9 ) ;
}
static void F_39 ( struct V_118 * V_118 )
{
struct V_82 * V_91 ;
struct V_55 * V_56 ;
unsigned long V_9 ;
long V_68 ;
unsigned long V_45 ;
T_3 V_123 ;
unsigned int V_124 [ V_64 ] ;
int V_125 ;
int V_44 ;
if ( ! V_8 )
return;
F_34 ( V_9 ) ;
V_56 = & F_35 ( V_55 ) ;
if ( ! V_56 -> V_119 ) {
F_38 ( V_9 ) ;
return;
}
V_56 -> V_119 = 0 ;
if ( ! V_56 -> V_120 ) {
F_17 ( V_39 , V_56 -> V_122 [ 2 ] & ~ V_7 ) ;
F_17 ( V_126 , V_56 -> V_122 [ 1 ] ) ;
if ( V_56 -> V_127 == 0 )
F_40 ( 0 ) ;
goto V_128;
}
if ( V_8 -> V_129 ( V_56 -> V_130 , V_56 -> V_127 , V_124 ,
V_56 -> V_122 ) ) {
F_15 ( V_54 L_3 ) ;
goto V_131;
}
V_91 = V_56 -> V_91 [ 0 ] ;
if ( V_91 -> V_93 . V_94 )
V_56 -> V_122 [ 0 ] |= V_132 ;
if ( V_91 -> V_93 . V_95 )
V_56 -> V_122 [ 0 ] |= V_30 ;
if ( V_91 -> V_93 . V_96 )
V_56 -> V_122 [ 0 ] |= V_31 ;
F_40 ( 1 ) ;
F_17 ( V_39 , V_56 -> V_122 [ 2 ] & ~ V_7 ) ;
F_17 ( V_126 , V_56 -> V_122 [ 1 ] ) ;
F_17 ( V_114 , ( V_56 -> V_122 [ 0 ] & ~ ( V_116 | V_117 ) )
| V_115 ) ;
for ( V_68 = 0 ; V_68 < V_56 -> V_127 ; ++ V_68 ) {
V_91 = V_56 -> V_91 [ V_68 ] ;
if ( V_91 -> V_100 . V_44 && V_91 -> V_100 . V_44 != V_124 [ V_68 ] + 1 ) {
F_21 ( V_91 ) ;
F_16 ( V_91 -> V_100 . V_44 , 0 ) ;
V_91 -> V_100 . V_44 = 0 ;
}
}
V_56 -> V_110 = V_125 = 0 ;
for ( V_68 = 0 ; V_68 < V_56 -> V_127 ; ++ V_68 ) {
V_91 = V_56 -> V_91 [ V_68 ] ;
if ( V_91 -> V_100 . V_44 )
continue;
V_44 = V_124 [ V_68 ] + 1 ;
if ( F_27 ( V_44 ) ) {
V_56 -> V_111 [ V_125 ] = V_91 ;
V_56 -> V_112 [ V_125 ] = V_44 ;
++ V_125 ;
continue;
}
V_45 = 0 ;
if ( V_91 -> V_100 . V_133 ) {
V_123 = F_22 ( & V_91 -> V_100 . V_105 ) ;
if ( V_123 < 0x80000000L )
V_45 = 0x80000000L - V_123 ;
}
F_30 ( & V_91 -> V_100 . V_103 , V_45 ) ;
V_91 -> V_100 . V_44 = V_44 ;
if ( V_91 -> V_100 . V_101 & V_102 )
V_45 = 0 ;
F_16 ( V_44 , V_45 ) ;
F_31 ( V_91 ) ;
}
V_56 -> V_110 = V_125 ;
V_56 -> V_122 [ 0 ] |= V_134 | V_135 ;
V_128:
F_37 () ;
F_32 ( V_56 , V_56 -> V_122 [ 0 ] ) ;
if ( V_56 -> V_122 [ 2 ] & V_7 ) {
F_37 () ;
F_17 ( V_39 , V_56 -> V_122 [ 2 ] ) ;
}
V_131:
F_38 ( V_9 ) ;
}
static int F_41 ( struct V_82 * V_136 , int V_137 ,
struct V_82 * V_83 [] , T_1 * V_130 ,
unsigned int * V_9 )
{
int V_89 = 0 ;
struct V_82 * V_91 ;
if ( ! F_42 ( V_136 ) ) {
if ( V_89 >= V_137 )
return - 1 ;
V_83 [ V_89 ] = V_136 ;
V_9 [ V_89 ] = V_136 -> V_100 . V_138 ;
V_130 [ V_89 ++ ] = V_136 -> V_100 . V_139 ;
}
F_43 (event, &group->sibling_list, group_entry) {
if ( ! F_42 ( V_91 ) &&
V_91 -> V_101 != V_140 ) {
if ( V_89 >= V_137 )
return - 1 ;
V_83 [ V_89 ] = V_91 ;
V_9 [ V_89 ] = V_91 -> V_100 . V_138 ;
V_130 [ V_89 ++ ] = V_91 -> V_100 . V_139 ;
}
}
return V_89 ;
}
static int F_44 ( struct V_82 * V_91 , int V_141 )
{
struct V_55 * V_56 ;
unsigned long V_9 ;
int V_142 ;
int V_143 = - V_97 ;
F_34 ( V_9 ) ;
F_45 ( V_91 -> V_118 ) ;
V_56 = & F_35 ( V_55 ) ;
V_142 = V_56 -> V_127 ;
if ( V_142 >= V_8 -> V_74 )
goto V_131;
V_56 -> V_91 [ V_142 ] = V_91 ;
V_56 -> V_130 [ V_142 ] = V_91 -> V_100 . V_139 ;
V_56 -> V_9 [ V_142 ] = V_91 -> V_100 . V_138 ;
if ( ! ( V_141 & V_144 ) )
V_91 -> V_100 . V_101 = V_102 | V_145 ;
if ( V_56 -> V_146 & V_147 )
goto V_148;
if ( F_19 ( V_56 -> V_91 , V_56 -> V_9 , V_142 , 1 ) )
goto V_131;
if ( F_18 ( V_56 , V_56 -> V_130 , V_56 -> V_9 , V_142 + 1 ) )
goto V_131;
V_91 -> V_100 . V_139 = V_56 -> V_130 [ V_142 ] ;
V_148:
++ V_56 -> V_127 ;
++ V_56 -> V_120 ;
V_143 = 0 ;
V_131:
F_46 ( V_91 -> V_118 ) ;
F_38 ( V_9 ) ;
return V_143 ;
}
static void F_47 ( struct V_82 * V_91 , int V_141 )
{
struct V_55 * V_56 ;
long V_68 ;
unsigned long V_9 ;
F_34 ( V_9 ) ;
F_45 ( V_91 -> V_118 ) ;
F_21 ( V_91 ) ;
V_56 = & F_35 ( V_55 ) ;
for ( V_68 = 0 ; V_68 < V_56 -> V_127 ; ++ V_68 ) {
if ( V_91 == V_56 -> V_91 [ V_68 ] ) {
while ( ++ V_68 < V_56 -> V_127 ) {
V_56 -> V_91 [ V_68 - 1 ] = V_56 -> V_91 [ V_68 ] ;
V_56 -> V_130 [ V_68 - 1 ] = V_56 -> V_130 [ V_68 ] ;
V_56 -> V_9 [ V_68 - 1 ] = V_56 -> V_9 [ V_68 ] ;
}
-- V_56 -> V_127 ;
V_8 -> V_149 ( V_91 -> V_100 . V_44 - 1 , V_56 -> V_122 ) ;
if ( V_91 -> V_100 . V_44 ) {
F_16 ( V_91 -> V_100 . V_44 , 0 ) ;
V_91 -> V_100 . V_44 = 0 ;
}
F_31 ( V_91 ) ;
break;
}
}
for ( V_68 = 0 ; V_68 < V_56 -> V_110 ; ++ V_68 )
if ( V_91 == V_56 -> V_111 [ V_68 ] )
break;
if ( V_68 < V_56 -> V_110 ) {
while ( ++ V_68 < V_56 -> V_110 ) {
V_56 -> V_111 [ V_68 - 1 ] = V_56 -> V_111 [ V_68 ] ;
V_56 -> V_112 [ V_68 - 1 ] = V_56 -> V_112 [ V_68 ] ;
}
-- V_56 -> V_110 ;
}
if ( V_56 -> V_127 == 0 ) {
V_56 -> V_122 [ 0 ] &= ~ ( V_134 | V_135 ) ;
}
F_46 ( V_91 -> V_118 ) ;
F_38 ( V_9 ) ;
}
static void F_48 ( struct V_82 * V_91 , int V_141 )
{
unsigned long V_9 ;
T_3 V_123 ;
unsigned long V_45 ;
if ( ! V_91 -> V_100 . V_44 || ! V_91 -> V_100 . V_133 )
return;
if ( ! ( V_91 -> V_100 . V_101 & V_102 ) )
return;
if ( V_141 & V_150 )
F_49 ( ! ( V_91 -> V_100 . V_101 & V_145 ) ) ;
F_34 ( V_9 ) ;
F_45 ( V_91 -> V_118 ) ;
V_91 -> V_100 . V_101 = 0 ;
V_123 = F_22 ( & V_91 -> V_100 . V_105 ) ;
V_45 = 0 ;
if ( V_123 < 0x80000000L )
V_45 = 0x80000000L - V_123 ;
F_16 ( V_91 -> V_100 . V_44 , V_45 ) ;
F_31 ( V_91 ) ;
F_46 ( V_91 -> V_118 ) ;
F_38 ( V_9 ) ;
}
static void F_50 ( struct V_82 * V_91 , int V_141 )
{
unsigned long V_9 ;
if ( ! V_91 -> V_100 . V_44 || ! V_91 -> V_100 . V_133 )
return;
if ( V_91 -> V_100 . V_101 & V_102 )
return;
F_34 ( V_9 ) ;
F_45 ( V_91 -> V_118 ) ;
F_21 ( V_91 ) ;
V_91 -> V_100 . V_101 |= V_102 | V_145 ;
F_16 ( V_91 -> V_100 . V_44 , 0 ) ;
F_31 ( V_91 ) ;
F_46 ( V_91 -> V_118 ) ;
F_38 ( V_9 ) ;
}
void F_51 ( struct V_118 * V_118 )
{
struct V_55 * V_56 = & F_35 ( V_55 ) ;
F_45 ( V_118 ) ;
V_56 -> V_146 |= V_147 ;
V_56 -> V_151 = V_56 -> V_127 ;
}
void F_52 ( struct V_118 * V_118 )
{
struct V_55 * V_56 = & F_35 ( V_55 ) ;
V_56 -> V_146 &= ~ V_147 ;
F_46 ( V_118 ) ;
}
int F_53 ( struct V_118 * V_118 )
{
struct V_55 * V_56 ;
long V_68 , V_89 ;
if ( ! V_8 )
return - V_97 ;
V_56 = & F_35 ( V_55 ) ;
V_89 = V_56 -> V_127 ;
if ( F_19 ( V_56 -> V_91 , V_56 -> V_9 , 0 , V_89 ) )
return - V_97 ;
V_68 = F_18 ( V_56 , V_56 -> V_130 , V_56 -> V_9 , V_89 ) ;
if ( V_68 < 0 )
return - V_97 ;
for ( V_68 = V_56 -> V_151 ; V_68 < V_89 ; ++ V_68 )
V_56 -> V_91 [ V_68 ] -> V_100 . V_139 = V_56 -> V_130 [ V_68 ] ;
V_56 -> V_146 &= ~ V_147 ;
F_46 ( V_118 ) ;
return 0 ;
}
static int F_54 ( struct V_82 * V_91 , T_1 V_152 ,
unsigned int V_9 )
{
int V_89 ;
T_1 V_153 [ V_154 ] ;
if ( V_91 -> V_93 . V_94
|| V_91 -> V_93 . V_95
|| V_91 -> V_93 . V_96
|| V_91 -> V_93 . V_133 )
return 0 ;
if ( V_8 -> V_76 ( V_152 ) )
return 1 ;
if ( ! V_8 -> V_77 )
return 0 ;
V_9 |= V_92 | V_75 ;
V_89 = V_8 -> V_77 ( V_152 , V_9 , V_153 ) ;
return V_89 > 0 ;
}
static T_1 F_55 ( T_1 V_152 , unsigned long V_9 )
{
T_1 V_153 [ V_154 ] ;
int V_89 ;
V_9 &= ~ ( V_92 | V_75 ) ;
V_89 = V_8 -> V_77 ( V_152 , V_9 , V_153 ) ;
if ( ! V_89 )
return 0 ;
return V_153 [ 0 ] ;
}
static void F_56 ( struct V_82 * V_91 )
{
if ( ! F_57 ( & V_155 , - 1 , 1 ) ) {
F_58 ( & V_156 ) ;
if ( F_59 ( & V_155 ) == 0 )
F_60 () ;
F_61 ( & V_156 ) ;
}
}
static int F_62 ( T_1 V_139 , T_1 * V_157 )
{
unsigned long type , V_158 , V_4 ;
int V_152 ;
if ( ! V_8 -> V_159 )
return - V_160 ;
type = V_139 & 0xff ;
V_158 = ( V_139 >> 8 ) & 0xff ;
V_4 = ( V_139 >> 16 ) & 0xff ;
if ( type >= V_161 ||
V_158 >= V_162 ||
V_4 >= V_163 )
return - V_160 ;
V_152 = ( * V_8 -> V_159 ) [ type ] [ V_158 ] [ V_4 ] ;
if ( V_152 == 0 )
return - V_164 ;
if ( V_152 == - 1 )
return - V_160 ;
* V_157 = V_152 ;
return 0 ;
}
static int F_63 ( struct V_82 * V_91 )
{
T_1 V_152 ;
unsigned long V_9 ;
struct V_82 * V_83 [ V_64 ] ;
T_1 V_130 [ V_64 ] ;
unsigned int V_58 [ V_64 ] ;
int V_89 ;
int V_165 ;
struct V_55 * V_56 ;
if ( ! V_8 )
return - V_166 ;
if ( F_64 ( V_91 ) )
return - V_164 ;
switch ( V_91 -> V_93 . type ) {
case V_167 :
V_152 = V_91 -> V_93 . V_139 ;
if ( V_152 >= V_8 -> V_168 || V_8 -> V_169 [ V_152 ] == 0 )
return - V_164 ;
V_152 = V_8 -> V_169 [ V_152 ] ;
break;
case V_170 :
V_165 = F_62 ( V_91 -> V_93 . V_139 , & V_152 ) ;
if ( V_165 )
return V_165 ;
break;
case V_171 :
V_152 = V_91 -> V_93 . V_139 ;
break;
default:
return - V_166 ;
}
V_91 -> V_100 . V_172 = V_152 ;
V_91 -> V_100 . V_44 = 0 ;
if ( ! F_65 ( V_173 ) )
V_91 -> V_93 . V_96 = 0 ;
V_9 = 0 ;
if ( V_91 -> V_174 & V_175 )
V_9 |= V_176 ;
if ( V_8 -> V_9 & V_107 ) {
if ( F_54 ( V_91 , V_152 , V_9 ) ) {
V_9 |= V_92 ;
} else if ( V_8 -> V_76 ( V_152 ) ) {
V_152 = F_55 ( V_152 , V_9 ) ;
if ( ! V_152 )
return - V_160 ;
}
}
V_89 = 0 ;
if ( V_91 -> V_177 != V_91 ) {
V_89 = F_41 ( V_91 -> V_177 , V_8 -> V_74 - 1 ,
V_83 , V_130 , V_58 ) ;
if ( V_89 < 0 )
return - V_160 ;
}
V_130 [ V_89 ] = V_152 ;
V_83 [ V_89 ] = V_91 ;
V_58 [ V_89 ] = V_9 ;
if ( F_19 ( V_83 , V_58 , V_89 , 1 ) )
return - V_160 ;
V_56 = & F_66 ( V_55 ) ;
V_165 = F_18 ( V_56 , V_130 , V_58 , V_89 + 1 ) ;
F_67 ( V_55 ) ;
if ( V_165 )
return - V_160 ;
V_91 -> V_100 . V_139 = V_130 [ V_89 ] ;
V_91 -> V_100 . V_138 = V_58 [ V_89 ] ;
V_91 -> V_100 . V_178 = V_91 -> V_100 . V_133 ;
F_30 ( & V_91 -> V_100 . V_105 , V_91 -> V_100 . V_178 ) ;
V_165 = 0 ;
if ( ! F_68 ( & V_155 ) ) {
F_58 ( & V_156 ) ;
if ( F_69 ( & V_155 ) == 0 &&
F_70 ( V_179 ) )
V_165 = - V_180 ;
else
F_71 ( & V_155 ) ;
F_61 ( & V_156 ) ;
}
V_91 -> V_181 = F_56 ;
return V_165 ;
}
static int F_72 ( struct V_82 * V_91 )
{
return V_91 -> V_100 . V_44 ;
}
static void F_73 ( struct V_82 * V_91 , unsigned long V_45 ,
struct V_1 * V_2 )
{
T_1 V_182 = V_91 -> V_100 . V_133 ;
T_3 V_98 , V_99 , V_123 ;
int V_183 = 0 ;
if ( V_91 -> V_100 . V_101 & V_102 ) {
F_16 ( V_91 -> V_100 . V_44 , 0 ) ;
return;
}
V_98 = F_22 ( & V_91 -> V_100 . V_103 ) ;
V_99 = F_20 ( V_98 , V_45 ) ;
F_25 ( V_99 , & V_91 -> V_104 ) ;
V_45 = 0 ;
V_123 = F_22 ( & V_91 -> V_100 . V_105 ) - V_99 ;
if ( V_182 ) {
if ( V_123 <= 0 ) {
V_123 += V_182 ;
if ( V_123 <= 0 )
V_123 = V_182 ;
V_183 = F_6 ( V_2 ) ;
V_91 -> V_100 . V_178 = V_91 -> V_100 . V_133 ;
}
if ( V_123 < 0x80000000LL )
V_45 = 0x80000000LL - V_123 ;
}
F_16 ( V_91 -> V_100 . V_44 , V_45 ) ;
F_30 ( & V_91 -> V_100 . V_103 , V_45 ) ;
F_30 ( & V_91 -> V_100 . V_105 , V_123 ) ;
F_31 ( V_91 ) ;
if ( V_183 ) {
struct V_184 V_185 ;
F_74 ( & V_185 , ~ 0ULL , V_91 -> V_100 . V_178 ) ;
if ( V_91 -> V_93 . V_186 & V_187 )
F_2 ( V_2 , & V_185 . V_188 ) ;
if ( F_75 ( V_91 , & V_185 , V_2 ) )
F_50 ( V_91 , 0 ) ;
}
}
unsigned long F_76 ( struct V_1 * V_2 )
{
T_2 V_9 = F_3 ( V_2 ) ;
if ( V_9 )
return V_9 ;
return F_77 ( V_2 ) ? V_28 :
V_33 ;
}
unsigned long F_78 ( struct V_1 * V_2 )
{
unsigned long V_34 = V_2 -> V_4 ;
if ( V_34 && F_6 ( V_2 ) )
return F_7 ( V_37 ) + F_1 ( V_2 ) ;
else if ( V_34 )
return 0 ;
else
return V_2 -> V_189 ;
}
static bool F_79 ( unsigned long V_45 )
{
if ( ( int ) V_45 < 0 )
return true ;
if ( F_80 ( V_190 ) && ( ( 0x80000000 - V_45 ) <= 256 ) )
return true ;
return false ;
}
static void V_179 ( struct V_1 * V_2 )
{
int V_68 ;
struct V_55 * V_56 = & F_35 ( V_55 ) ;
struct V_82 * V_91 ;
unsigned long V_45 ;
int V_191 = 0 ;
int V_192 ;
if ( V_56 -> V_110 )
F_28 ( V_56 , F_7 ( V_50 ) ,
F_7 ( V_51 ) ) ;
F_4 ( V_2 ) ;
V_192 = F_5 ( V_2 ) ;
if ( V_192 )
F_81 () ;
else
F_82 () ;
for ( V_68 = 0 ; V_68 < V_56 -> V_127 ; ++ V_68 ) {
V_91 = V_56 -> V_91 [ V_68 ] ;
if ( ! V_91 -> V_100 . V_44 || F_27 ( V_91 -> V_100 . V_44 ) )
continue;
V_45 = F_13 ( V_91 -> V_100 . V_44 ) ;
if ( ( int ) V_45 < 0 ) {
V_191 = 1 ;
F_73 ( V_91 , V_45 , V_2 ) ;
}
}
if ( ! V_191 ) {
for ( V_68 = 0 ; V_68 < V_8 -> V_74 ; ++ V_68 ) {
if ( F_27 ( V_68 + 1 ) )
continue;
V_45 = F_13 ( V_68 + 1 ) ;
if ( F_79 ( V_45 ) )
F_16 ( V_68 + 1 , 0 ) ;
}
}
F_32 ( V_56 , V_56 -> V_122 [ 0 ] ) ;
if ( V_192 )
F_83 () ;
else
F_84 () ;
}
static void F_85 ( int V_193 )
{
struct V_55 * V_56 = & F_86 ( V_55 , V_193 ) ;
if ( ! V_8 )
return;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_56 -> V_122 [ 0 ] = V_115 ;
}
static int T_4
F_87 ( struct V_194 * V_195 , unsigned long V_196 , void * V_197 )
{
unsigned int V_193 = ( long ) V_197 ;
switch ( V_196 & ~ V_198 ) {
case V_199 :
F_85 ( V_193 ) ;
break;
default:
break;
}
return V_200 ;
}
int T_4 F_88 ( struct V_201 * V_118 )
{
if ( V_8 )
return - V_180 ;
V_8 = V_118 ;
F_89 ( L_4 ,
V_118 -> V_202 ) ;
#ifdef V_29
if ( F_90 () & V_29 )
V_30 = V_31 ;
#endif
F_91 ( & V_201 , L_5 , V_171 ) ;
F_92 ( F_87 ) ;
return 0 ;
}
