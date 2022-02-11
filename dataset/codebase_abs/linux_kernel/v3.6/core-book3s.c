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
unsigned long V_14 = ( V_8 -> V_9 & V_10 ) ?
V_15 : V_16 ;
if ( ! ( V_5 & V_7 ) || ( V_5 & V_14 ) )
* V_3 = F_6 ( V_17 ) ;
}
static bool F_7 ( unsigned long V_5 )
{
unsigned long V_18 = V_19 ;
if ( V_8 -> V_9 & V_10 )
V_18 = V_20 ;
return ! ! ( V_5 & V_18 ) ;
}
static bool F_8 ( unsigned long V_5 )
{
unsigned long V_21 = V_22 ;
if ( V_8 -> V_9 & V_10 )
V_21 = V_23 ;
return ! ! ( V_5 & V_21 ) ;
}
static inline T_2 F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 & V_25 )
return V_26 ;
if ( ( V_2 -> V_24 & V_27 ) && V_28 != V_29 )
return V_30 ;
return V_31 ;
}
static inline T_2 F_3 ( struct V_1 * V_2 )
{
unsigned long V_5 = V_2 -> V_6 ;
unsigned long V_32 = V_2 -> V_4 ;
if ( ! V_32 )
return F_9 ( V_2 ) ;
if ( V_8 -> V_9 & V_33 ) {
unsigned long V_34 = F_6 ( V_35 ) ;
if ( V_34 >= V_36 )
return V_31 ;
return V_26 ;
}
if ( F_8 ( V_5 ) )
return V_26 ;
if ( F_7 ( V_5 ) && ( V_28 != V_29 ) )
return V_30 ;
return V_31 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned long V_5 = F_6 ( V_37 ) ;
int V_38 = V_5 & V_7 ;
int V_32 ;
if ( F_10 ( V_2 ) != 0xf00 )
V_32 = 0 ;
else if ( V_38 )
V_32 = 1 ;
else if ( ( V_8 -> V_9 & V_39 ) )
V_32 = 0 ;
else if ( ! ( V_8 -> V_9 & V_33 ) && F_8 ( V_5 ) )
V_32 = 0 ;
else
V_32 = 1 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_4 = V_32 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return ! V_2 -> V_40 ;
}
void F_11 ( void )
{
}
static unsigned long F_12 ( int V_41 )
{
unsigned long V_42 ;
switch ( V_41 ) {
case 1 :
V_42 = F_6 ( V_43 ) ;
break;
case 2 :
V_42 = F_6 ( V_44 ) ;
break;
case 3 :
V_42 = F_6 ( V_45 ) ;
break;
case 4 :
V_42 = F_6 ( V_46 ) ;
break;
case 5 :
V_42 = F_6 ( V_47 ) ;
break;
case 6 :
V_42 = F_6 ( V_48 ) ;
break;
#ifdef F_13
case 7 :
V_42 = F_6 ( V_49 ) ;
break;
case 8 :
V_42 = F_6 ( V_50 ) ;
break;
#endif
default:
F_14 ( V_51 L_1 , V_41 ) ;
V_42 = 0 ;
}
return V_42 ;
}
static void F_15 ( int V_41 , unsigned long V_42 )
{
switch ( V_41 ) {
case 1 :
F_16 ( V_43 , V_42 ) ;
break;
case 2 :
F_16 ( V_44 , V_42 ) ;
break;
case 3 :
F_16 ( V_45 , V_42 ) ;
break;
case 4 :
F_16 ( V_46 , V_42 ) ;
break;
case 5 :
F_16 ( V_47 , V_42 ) ;
break;
case 6 :
F_16 ( V_48 , V_42 ) ;
break;
#ifdef F_13
case 7 :
F_16 ( V_49 , V_42 ) ;
break;
case 8 :
F_16 ( V_50 , V_42 ) ;
break;
#endif
default:
F_14 ( V_51 L_2 , V_41 ) ;
}
}
static int F_17 ( struct V_52 * V_53 ,
T_1 V_54 [] , unsigned int V_55 [] ,
int V_56 )
{
unsigned long V_57 , V_58 , V_59 ;
unsigned long V_60 [ V_61 ] , V_62 [ V_61 ] ;
int V_63 [ V_61 ] , V_64 [ V_61 ] ;
int V_65 , V_66 ;
unsigned long V_67 = V_8 -> V_68 ;
unsigned long V_69 = V_8 -> V_70 ;
if ( V_56 > V_8 -> V_71 )
return - 1 ;
for ( V_65 = 0 ; V_65 < V_56 ; ++ V_65 ) {
if ( ( V_55 [ V_65 ] & V_72 )
&& ! V_8 -> V_73 ( V_54 [ V_65 ] ) ) {
V_8 -> V_74 ( V_54 [ V_65 ] , V_55 [ V_65 ] ,
V_53 -> V_75 [ V_65 ] ) ;
V_54 [ V_65 ] = V_53 -> V_75 [ V_65 ] [ 0 ] ;
}
if ( V_8 -> V_76 ( V_54 [ V_65 ] , & V_53 -> V_77 [ V_65 ] [ 0 ] ,
& V_53 -> V_78 [ V_65 ] [ 0 ] ) )
return - 1 ;
}
V_58 = V_57 = 0 ;
for ( V_65 = 0 ; V_65 < V_56 ; ++ V_65 ) {
V_59 = ( V_58 | V_53 -> V_78 [ V_65 ] [ 0 ] ) +
( V_58 & V_53 -> V_78 [ V_65 ] [ 0 ] & V_67 ) ;
if ( ( ( ( V_59 + V_69 ) ^ V_58 ) & V_57 ) != 0 ||
( ( ( V_59 + V_69 ) ^ V_53 -> V_78 [ V_65 ] [ 0 ] ) &
V_53 -> V_77 [ V_65 ] [ 0 ] ) != 0 )
break;
V_58 = V_59 ;
V_57 |= V_53 -> V_77 [ V_65 ] [ 0 ] ;
}
if ( V_65 == V_56 )
return 0 ;
if ( ! V_8 -> V_74 )
return - 1 ;
for ( V_65 = 0 ; V_65 < V_56 ; ++ V_65 ) {
V_64 [ V_65 ] = 0 ;
V_63 [ V_65 ] = V_8 -> V_74 ( V_54 [ V_65 ] , V_55 [ V_65 ] ,
V_53 -> V_75 [ V_65 ] ) ;
for ( V_66 = 1 ; V_66 < V_63 [ V_65 ] ; ++ V_66 )
V_8 -> V_76 ( V_53 -> V_75 [ V_65 ] [ V_66 ] ,
& V_53 -> V_77 [ V_65 ] [ V_66 ] ,
& V_53 -> V_78 [ V_65 ] [ V_66 ] ) ;
}
V_65 = 0 ;
V_66 = - 1 ;
V_58 = V_57 = V_59 = 0 ;
while ( V_65 < V_56 ) {
if ( V_66 >= 0 ) {
V_58 = V_62 [ V_65 ] ;
V_57 = V_60 [ V_65 ] ;
V_66 = V_64 [ V_65 ] ;
}
while ( ++ V_66 < V_63 [ V_65 ] ) {
V_59 = ( V_58 | V_53 -> V_78 [ V_65 ] [ V_66 ] ) +
( V_58 & V_53 -> V_78 [ V_65 ] [ V_66 ] & V_67 ) ;
if ( ( ( ( V_59 + V_69 ) ^ V_58 ) & V_57 ) == 0 &&
( ( ( V_59 + V_69 ) ^ V_53 -> V_78 [ V_65 ] [ V_66 ] )
& V_53 -> V_77 [ V_65 ] [ V_66 ] ) == 0 )
break;
}
if ( V_66 >= V_63 [ V_65 ] ) {
if ( -- V_65 < 0 )
return - 1 ;
} else {
V_64 [ V_65 ] = V_66 ;
V_62 [ V_65 ] = V_58 ;
V_60 [ V_65 ] = V_57 ;
V_58 = V_59 ;
V_57 |= V_53 -> V_77 [ V_65 ] [ V_66 ] ;
++ V_65 ;
V_66 = - 1 ;
}
}
for ( V_65 = 0 ; V_65 < V_56 ; ++ V_65 )
V_54 [ V_65 ] = V_53 -> V_75 [ V_65 ] [ V_64 [ V_65 ] ] ;
return 0 ;
}
static int F_18 ( struct V_79 * * V_80 , unsigned int V_55 [] ,
int V_81 , int V_82 )
{
int V_83 = 0 , V_84 = 0 , V_85 = 0 ;
int V_65 , V_86 , V_87 ;
struct V_79 * V_88 ;
V_86 = V_81 + V_82 ;
if ( V_86 <= 1 )
return 0 ;
V_87 = 1 ;
for ( V_65 = 0 ; V_65 < V_86 ; ++ V_65 ) {
if ( V_55 [ V_65 ] & V_89 ) {
V_55 [ V_65 ] &= ~ V_72 ;
continue;
}
V_88 = V_80 [ V_65 ] ;
if ( V_87 ) {
V_83 = V_88 -> V_90 . V_91 ;
V_84 = V_88 -> V_90 . V_92 ;
V_85 = V_88 -> V_90 . V_93 ;
V_87 = 0 ;
} else if ( V_88 -> V_90 . V_91 != V_83 ||
V_88 -> V_90 . V_92 != V_84 ||
V_88 -> V_90 . V_93 != V_85 ) {
return - V_94 ;
}
}
if ( V_83 || V_84 || V_85 )
for ( V_65 = 0 ; V_65 < V_86 ; ++ V_65 )
if ( V_55 [ V_65 ] & V_89 )
V_55 [ V_65 ] |= V_72 ;
return 0 ;
}
static T_1 F_19 ( T_1 V_95 , T_1 V_42 )
{
T_1 V_96 = ( V_42 - V_95 ) & 0xfffffffful ;
if ( V_95 > V_42 && ( V_95 - V_42 ) < 256 )
V_96 = 0 ;
return V_96 ;
}
static void F_20 ( struct V_79 * V_88 )
{
T_3 V_42 , V_96 , V_95 ;
if ( V_88 -> V_97 . V_98 & V_99 )
return;
if ( ! V_88 -> V_97 . V_41 )
return;
do {
V_95 = F_21 ( & V_88 -> V_97 . V_100 ) ;
F_22 () ;
V_42 = F_12 ( V_88 -> V_97 . V_41 ) ;
V_96 = F_19 ( V_95 , V_42 ) ;
if ( ! V_96 )
return;
} while ( F_23 ( & V_88 -> V_97 . V_100 , V_95 , V_42 ) != V_95 );
F_24 ( V_96 , & V_88 -> V_101 ) ;
F_25 ( V_96 , & V_88 -> V_97 . V_102 ) ;
}
static int F_26 ( int V_103 )
{
return ( V_8 -> V_9 & V_104 )
&& ( V_103 == 5 || V_103 == 6 ) ;
}
static void F_27 ( struct V_52 * V_53 ,
unsigned long V_105 , unsigned long V_106 )
{
struct V_79 * V_88 ;
T_1 V_42 , V_95 , V_96 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_53 -> V_107 ; ++ V_65 ) {
V_88 = V_53 -> V_108 [ V_65 ] ;
if ( ! V_88 -> V_97 . V_41 )
continue;
V_42 = ( V_88 -> V_97 . V_41 == 5 ) ? V_105 : V_106 ;
V_95 = F_21 ( & V_88 -> V_97 . V_100 ) ;
V_88 -> V_97 . V_41 = 0 ;
V_96 = F_19 ( V_95 , V_42 ) ;
if ( V_96 )
F_24 ( V_96 , & V_88 -> V_101 ) ;
}
}
static void F_28 ( struct V_52 * V_53 ,
unsigned long V_105 , unsigned long V_106 )
{
struct V_79 * V_88 ;
T_1 V_42 , V_95 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_53 -> V_107 ; ++ V_65 ) {
V_88 = V_53 -> V_108 [ V_65 ] ;
V_88 -> V_97 . V_41 = V_53 -> V_109 [ V_65 ] ;
V_42 = ( V_88 -> V_97 . V_41 == 5 ) ? V_105 : V_106 ;
V_95 = F_21 ( & V_88 -> V_97 . V_100 ) ;
if ( F_19 ( V_95 , V_42 ) )
F_29 ( & V_88 -> V_97 . V_100 , V_42 ) ;
F_30 ( V_88 ) ;
}
}
static void F_31 ( struct V_52 * V_53 , unsigned long V_110 )
{
unsigned long V_105 , V_106 ;
if ( ! V_53 -> V_107 ) {
F_16 ( V_111 , V_110 ) ;
return;
}
asm volatile("mtspr %3,%2; mfspr %0,%4; mfspr %1,%5"
: "=&r" (pmc5), "=&r" (pmc6)
: "r" (mmcr0 & ~(MMCR0_PMC1CE | MMCR0_PMCjCE)),
"i" (SPRN_MMCR0),
"i" (SPRN_PMC5), "i" (SPRN_PMC6));
if ( V_110 & V_112 )
F_27 ( V_53 , V_105 , V_106 ) ;
else
F_28 ( V_53 , V_105 , V_106 ) ;
if ( V_110 & ( V_113 | V_114 ) )
F_16 ( V_111 , V_110 ) ;
}
static void F_32 ( struct V_115 * V_115 )
{
struct V_52 * V_53 ;
unsigned long V_9 ;
if ( ! V_8 )
return;
F_33 ( V_9 ) ;
V_53 = & F_34 ( V_52 ) ;
if ( ! V_53 -> V_116 ) {
V_53 -> V_116 = 1 ;
V_53 -> V_117 = 0 ;
if ( ! V_53 -> V_118 ) {
F_35 () ;
V_53 -> V_118 = 1 ;
}
if ( V_53 -> V_119 [ 2 ] & V_7 ) {
F_16 ( V_37 ,
V_53 -> V_119 [ 2 ] & ~ V_7 ) ;
F_36 () ;
}
F_31 ( V_53 , F_6 ( V_111 ) | V_112 ) ;
F_36 () ;
}
F_37 ( V_9 ) ;
}
static void F_38 ( struct V_115 * V_115 )
{
struct V_79 * V_88 ;
struct V_52 * V_53 ;
unsigned long V_9 ;
long V_65 ;
unsigned long V_42 ;
T_3 V_120 ;
unsigned int V_121 [ V_61 ] ;
int V_122 ;
int V_41 ;
if ( ! V_8 )
return;
F_33 ( V_9 ) ;
V_53 = & F_34 ( V_52 ) ;
if ( ! V_53 -> V_116 ) {
F_37 ( V_9 ) ;
return;
}
V_53 -> V_116 = 0 ;
if ( ! V_53 -> V_117 ) {
F_16 ( V_37 , V_53 -> V_119 [ 2 ] & ~ V_7 ) ;
F_16 ( V_123 , V_53 -> V_119 [ 1 ] ) ;
if ( V_53 -> V_124 == 0 )
F_39 ( 0 ) ;
goto V_125;
}
if ( V_8 -> V_126 ( V_53 -> V_127 , V_53 -> V_124 , V_121 ,
V_53 -> V_119 ) ) {
F_14 ( V_51 L_3 ) ;
goto V_128;
}
V_88 = V_53 -> V_88 [ 0 ] ;
if ( V_88 -> V_90 . V_91 )
V_53 -> V_119 [ 0 ] |= V_129 ;
if ( V_88 -> V_90 . V_92 )
V_53 -> V_119 [ 0 ] |= V_28 ;
if ( V_88 -> V_90 . V_93 )
V_53 -> V_119 [ 0 ] |= V_29 ;
F_39 ( 1 ) ;
F_16 ( V_37 , V_53 -> V_119 [ 2 ] & ~ V_7 ) ;
F_16 ( V_123 , V_53 -> V_119 [ 1 ] ) ;
F_16 ( V_111 , ( V_53 -> V_119 [ 0 ] & ~ ( V_113 | V_114 ) )
| V_112 ) ;
for ( V_65 = 0 ; V_65 < V_53 -> V_124 ; ++ V_65 ) {
V_88 = V_53 -> V_88 [ V_65 ] ;
if ( V_88 -> V_97 . V_41 && V_88 -> V_97 . V_41 != V_121 [ V_65 ] + 1 ) {
F_20 ( V_88 ) ;
F_15 ( V_88 -> V_97 . V_41 , 0 ) ;
V_88 -> V_97 . V_41 = 0 ;
}
}
V_53 -> V_107 = V_122 = 0 ;
for ( V_65 = 0 ; V_65 < V_53 -> V_124 ; ++ V_65 ) {
V_88 = V_53 -> V_88 [ V_65 ] ;
if ( V_88 -> V_97 . V_41 )
continue;
V_41 = V_121 [ V_65 ] + 1 ;
if ( F_26 ( V_41 ) ) {
V_53 -> V_108 [ V_122 ] = V_88 ;
V_53 -> V_109 [ V_122 ] = V_41 ;
++ V_122 ;
continue;
}
V_42 = 0 ;
if ( V_88 -> V_97 . V_130 ) {
V_120 = F_21 ( & V_88 -> V_97 . V_102 ) ;
if ( V_120 < 0x80000000L )
V_42 = 0x80000000L - V_120 ;
}
F_29 ( & V_88 -> V_97 . V_100 , V_42 ) ;
V_88 -> V_97 . V_41 = V_41 ;
if ( V_88 -> V_97 . V_98 & V_99 )
V_42 = 0 ;
F_15 ( V_41 , V_42 ) ;
F_30 ( V_88 ) ;
}
V_53 -> V_107 = V_122 ;
V_53 -> V_119 [ 0 ] |= V_131 | V_132 ;
V_125:
F_36 () ;
F_31 ( V_53 , V_53 -> V_119 [ 0 ] ) ;
if ( V_53 -> V_119 [ 2 ] & V_7 ) {
F_36 () ;
F_16 ( V_37 , V_53 -> V_119 [ 2 ] ) ;
}
V_128:
F_37 ( V_9 ) ;
}
static int F_40 ( struct V_79 * V_133 , int V_134 ,
struct V_79 * V_80 [] , T_1 * V_127 ,
unsigned int * V_9 )
{
int V_86 = 0 ;
struct V_79 * V_88 ;
if ( ! F_41 ( V_133 ) ) {
if ( V_86 >= V_134 )
return - 1 ;
V_80 [ V_86 ] = V_133 ;
V_9 [ V_86 ] = V_133 -> V_97 . V_135 ;
V_127 [ V_86 ++ ] = V_133 -> V_97 . V_136 ;
}
F_42 (event, &group->sibling_list, group_entry) {
if ( ! F_41 ( V_88 ) &&
V_88 -> V_98 != V_137 ) {
if ( V_86 >= V_134 )
return - 1 ;
V_80 [ V_86 ] = V_88 ;
V_9 [ V_86 ] = V_88 -> V_97 . V_135 ;
V_127 [ V_86 ++ ] = V_88 -> V_97 . V_136 ;
}
}
return V_86 ;
}
static int F_43 ( struct V_79 * V_88 , int V_138 )
{
struct V_52 * V_53 ;
unsigned long V_9 ;
int V_139 ;
int V_140 = - V_94 ;
F_33 ( V_9 ) ;
F_44 ( V_88 -> V_115 ) ;
V_53 = & F_34 ( V_52 ) ;
V_139 = V_53 -> V_124 ;
if ( V_139 >= V_8 -> V_71 )
goto V_128;
V_53 -> V_88 [ V_139 ] = V_88 ;
V_53 -> V_127 [ V_139 ] = V_88 -> V_97 . V_136 ;
V_53 -> V_9 [ V_139 ] = V_88 -> V_97 . V_135 ;
if ( ! ( V_138 & V_141 ) )
V_88 -> V_97 . V_98 = V_99 | V_142 ;
if ( V_53 -> V_143 & V_144 )
goto V_145;
if ( F_18 ( V_53 -> V_88 , V_53 -> V_9 , V_139 , 1 ) )
goto V_128;
if ( F_17 ( V_53 , V_53 -> V_127 , V_53 -> V_9 , V_139 + 1 ) )
goto V_128;
V_88 -> V_97 . V_136 = V_53 -> V_127 [ V_139 ] ;
V_145:
++ V_53 -> V_124 ;
++ V_53 -> V_117 ;
V_140 = 0 ;
V_128:
F_45 ( V_88 -> V_115 ) ;
F_37 ( V_9 ) ;
return V_140 ;
}
static void F_46 ( struct V_79 * V_88 , int V_138 )
{
struct V_52 * V_53 ;
long V_65 ;
unsigned long V_9 ;
F_33 ( V_9 ) ;
F_44 ( V_88 -> V_115 ) ;
F_20 ( V_88 ) ;
V_53 = & F_34 ( V_52 ) ;
for ( V_65 = 0 ; V_65 < V_53 -> V_124 ; ++ V_65 ) {
if ( V_88 == V_53 -> V_88 [ V_65 ] ) {
while ( ++ V_65 < V_53 -> V_124 ) {
V_53 -> V_88 [ V_65 - 1 ] = V_53 -> V_88 [ V_65 ] ;
V_53 -> V_127 [ V_65 - 1 ] = V_53 -> V_127 [ V_65 ] ;
V_53 -> V_9 [ V_65 - 1 ] = V_53 -> V_9 [ V_65 ] ;
}
-- V_53 -> V_124 ;
V_8 -> V_146 ( V_88 -> V_97 . V_41 - 1 , V_53 -> V_119 ) ;
if ( V_88 -> V_97 . V_41 ) {
F_15 ( V_88 -> V_97 . V_41 , 0 ) ;
V_88 -> V_97 . V_41 = 0 ;
}
F_30 ( V_88 ) ;
break;
}
}
for ( V_65 = 0 ; V_65 < V_53 -> V_107 ; ++ V_65 )
if ( V_88 == V_53 -> V_108 [ V_65 ] )
break;
if ( V_65 < V_53 -> V_107 ) {
while ( ++ V_65 < V_53 -> V_107 ) {
V_53 -> V_108 [ V_65 - 1 ] = V_53 -> V_108 [ V_65 ] ;
V_53 -> V_109 [ V_65 - 1 ] = V_53 -> V_109 [ V_65 ] ;
}
-- V_53 -> V_107 ;
}
if ( V_53 -> V_124 == 0 ) {
V_53 -> V_119 [ 0 ] &= ~ ( V_131 | V_132 ) ;
}
F_45 ( V_88 -> V_115 ) ;
F_37 ( V_9 ) ;
}
static void F_47 ( struct V_79 * V_88 , int V_138 )
{
unsigned long V_9 ;
T_3 V_120 ;
unsigned long V_42 ;
if ( ! V_88 -> V_97 . V_41 || ! V_88 -> V_97 . V_130 )
return;
if ( ! ( V_88 -> V_97 . V_98 & V_99 ) )
return;
if ( V_138 & V_147 )
F_48 ( ! ( V_88 -> V_97 . V_98 & V_142 ) ) ;
F_33 ( V_9 ) ;
F_44 ( V_88 -> V_115 ) ;
V_88 -> V_97 . V_98 = 0 ;
V_120 = F_21 ( & V_88 -> V_97 . V_102 ) ;
V_42 = 0 ;
if ( V_120 < 0x80000000L )
V_42 = 0x80000000L - V_120 ;
F_15 ( V_88 -> V_97 . V_41 , V_42 ) ;
F_30 ( V_88 ) ;
F_45 ( V_88 -> V_115 ) ;
F_37 ( V_9 ) ;
}
static void F_49 ( struct V_79 * V_88 , int V_138 )
{
unsigned long V_9 ;
if ( ! V_88 -> V_97 . V_41 || ! V_88 -> V_97 . V_130 )
return;
if ( V_88 -> V_97 . V_98 & V_99 )
return;
F_33 ( V_9 ) ;
F_44 ( V_88 -> V_115 ) ;
F_20 ( V_88 ) ;
V_88 -> V_97 . V_98 |= V_99 | V_142 ;
F_15 ( V_88 -> V_97 . V_41 , 0 ) ;
F_30 ( V_88 ) ;
F_45 ( V_88 -> V_115 ) ;
F_37 ( V_9 ) ;
}
void F_50 ( struct V_115 * V_115 )
{
struct V_52 * V_53 = & F_34 ( V_52 ) ;
F_44 ( V_115 ) ;
V_53 -> V_143 |= V_144 ;
V_53 -> V_148 = V_53 -> V_124 ;
}
void F_51 ( struct V_115 * V_115 )
{
struct V_52 * V_53 = & F_34 ( V_52 ) ;
V_53 -> V_143 &= ~ V_144 ;
F_45 ( V_115 ) ;
}
int F_52 ( struct V_115 * V_115 )
{
struct V_52 * V_53 ;
long V_65 , V_86 ;
if ( ! V_8 )
return - V_94 ;
V_53 = & F_34 ( V_52 ) ;
V_86 = V_53 -> V_124 ;
if ( F_18 ( V_53 -> V_88 , V_53 -> V_9 , 0 , V_86 ) )
return - V_94 ;
V_65 = F_17 ( V_53 , V_53 -> V_127 , V_53 -> V_9 , V_86 ) ;
if ( V_65 < 0 )
return - V_94 ;
for ( V_65 = V_53 -> V_148 ; V_65 < V_86 ; ++ V_65 )
V_53 -> V_88 [ V_65 ] -> V_97 . V_136 = V_53 -> V_127 [ V_65 ] ;
V_53 -> V_143 &= ~ V_144 ;
F_45 ( V_115 ) ;
return 0 ;
}
static int F_53 ( struct V_79 * V_88 , T_1 V_149 ,
unsigned int V_9 )
{
int V_86 ;
T_1 V_150 [ V_151 ] ;
if ( V_88 -> V_90 . V_91
|| V_88 -> V_90 . V_92
|| V_88 -> V_90 . V_93
|| V_88 -> V_90 . V_130 )
return 0 ;
if ( V_8 -> V_73 ( V_149 ) )
return 1 ;
if ( ! V_8 -> V_74 )
return 0 ;
V_9 |= V_89 | V_72 ;
V_86 = V_8 -> V_74 ( V_149 , V_9 , V_150 ) ;
return V_86 > 0 ;
}
static T_1 F_54 ( T_1 V_149 , unsigned long V_9 )
{
T_1 V_150 [ V_151 ] ;
int V_86 ;
V_9 &= ~ ( V_89 | V_72 ) ;
V_86 = V_8 -> V_74 ( V_149 , V_9 , V_150 ) ;
if ( ! V_86 )
return 0 ;
return V_150 [ 0 ] ;
}
static void F_55 ( struct V_79 * V_88 )
{
if ( ! F_56 ( & V_152 , - 1 , 1 ) ) {
F_57 ( & V_153 ) ;
if ( F_58 ( & V_152 ) == 0 )
F_59 () ;
F_60 ( & V_153 ) ;
}
}
static int F_61 ( T_1 V_136 , T_1 * V_154 )
{
unsigned long type , V_155 , V_4 ;
int V_149 ;
if ( ! V_8 -> V_156 )
return - V_157 ;
type = V_136 & 0xff ;
V_155 = ( V_136 >> 8 ) & 0xff ;
V_4 = ( V_136 >> 16 ) & 0xff ;
if ( type >= V_158 ||
V_155 >= V_159 ||
V_4 >= V_160 )
return - V_157 ;
V_149 = ( * V_8 -> V_156 ) [ type ] [ V_155 ] [ V_4 ] ;
if ( V_149 == 0 )
return - V_161 ;
if ( V_149 == - 1 )
return - V_157 ;
* V_154 = V_149 ;
return 0 ;
}
static int F_62 ( struct V_79 * V_88 )
{
T_1 V_149 ;
unsigned long V_9 ;
struct V_79 * V_80 [ V_61 ] ;
T_1 V_127 [ V_61 ] ;
unsigned int V_55 [ V_61 ] ;
int V_86 ;
int V_162 ;
struct V_52 * V_53 ;
if ( ! V_8 )
return - V_163 ;
if ( F_63 ( V_88 ) )
return - V_161 ;
switch ( V_88 -> V_90 . type ) {
case V_164 :
V_149 = V_88 -> V_90 . V_136 ;
if ( V_149 >= V_8 -> V_165 || V_8 -> V_166 [ V_149 ] == 0 )
return - V_161 ;
V_149 = V_8 -> V_166 [ V_149 ] ;
break;
case V_167 :
V_162 = F_61 ( V_88 -> V_90 . V_136 , & V_149 ) ;
if ( V_162 )
return V_162 ;
break;
case V_168 :
V_149 = V_88 -> V_90 . V_136 ;
break;
default:
return - V_163 ;
}
V_88 -> V_97 . V_169 = V_149 ;
V_88 -> V_97 . V_41 = 0 ;
if ( ! F_64 ( V_170 ) )
V_88 -> V_90 . V_93 = 0 ;
V_9 = 0 ;
if ( V_88 -> V_171 & V_172 )
V_9 |= V_173 ;
if ( V_8 -> V_9 & V_104 ) {
if ( F_53 ( V_88 , V_149 , V_9 ) ) {
V_9 |= V_89 ;
} else if ( V_8 -> V_73 ( V_149 ) ) {
V_149 = F_54 ( V_149 , V_9 ) ;
if ( ! V_149 )
return - V_157 ;
}
}
V_86 = 0 ;
if ( V_88 -> V_174 != V_88 ) {
V_86 = F_40 ( V_88 -> V_174 , V_8 -> V_71 - 1 ,
V_80 , V_127 , V_55 ) ;
if ( V_86 < 0 )
return - V_157 ;
}
V_127 [ V_86 ] = V_149 ;
V_80 [ V_86 ] = V_88 ;
V_55 [ V_86 ] = V_9 ;
if ( F_18 ( V_80 , V_55 , V_86 , 1 ) )
return - V_157 ;
V_53 = & F_65 ( V_52 ) ;
V_162 = F_17 ( V_53 , V_127 , V_55 , V_86 + 1 ) ;
F_66 ( V_52 ) ;
if ( V_162 )
return - V_157 ;
V_88 -> V_97 . V_136 = V_127 [ V_86 ] ;
V_88 -> V_97 . V_135 = V_55 [ V_86 ] ;
V_88 -> V_97 . V_175 = V_88 -> V_97 . V_130 ;
F_29 ( & V_88 -> V_97 . V_102 , V_88 -> V_97 . V_175 ) ;
V_162 = 0 ;
if ( ! F_67 ( & V_152 ) ) {
F_57 ( & V_153 ) ;
if ( F_68 ( & V_152 ) == 0 &&
F_69 ( V_176 ) )
V_162 = - V_177 ;
else
F_70 ( & V_152 ) ;
F_60 ( & V_153 ) ;
}
V_88 -> V_178 = F_55 ;
return V_162 ;
}
static int F_71 ( struct V_79 * V_88 )
{
return V_88 -> V_97 . V_41 ;
}
static void F_72 ( struct V_79 * V_88 , unsigned long V_42 ,
struct V_1 * V_2 )
{
T_1 V_179 = V_88 -> V_97 . V_130 ;
T_3 V_95 , V_96 , V_120 ;
int V_180 = 0 ;
if ( V_88 -> V_97 . V_98 & V_99 ) {
F_15 ( V_88 -> V_97 . V_41 , 0 ) ;
return;
}
V_95 = F_21 ( & V_88 -> V_97 . V_100 ) ;
V_96 = F_19 ( V_95 , V_42 ) ;
F_24 ( V_96 , & V_88 -> V_101 ) ;
V_42 = 0 ;
V_120 = F_21 ( & V_88 -> V_97 . V_102 ) - V_96 ;
if ( V_179 ) {
if ( V_120 <= 0 ) {
V_120 += V_179 ;
if ( V_120 <= 0 )
V_120 = V_179 ;
V_180 = 1 ;
V_88 -> V_97 . V_175 = V_88 -> V_97 . V_130 ;
}
if ( V_120 < 0x80000000LL )
V_42 = 0x80000000LL - V_120 ;
}
F_15 ( V_88 -> V_97 . V_41 , V_42 ) ;
F_29 ( & V_88 -> V_97 . V_100 , V_42 ) ;
F_29 ( & V_88 -> V_97 . V_102 , V_120 ) ;
F_30 ( V_88 ) ;
if ( V_180 ) {
struct V_181 V_182 ;
F_73 ( & V_182 , ~ 0ULL , V_88 -> V_97 . V_175 ) ;
if ( V_88 -> V_90 . V_183 & V_184 )
F_2 ( V_2 , & V_182 . V_185 ) ;
if ( F_74 ( V_88 , & V_182 , V_2 ) )
F_49 ( V_88 , 0 ) ;
}
}
unsigned long F_75 ( struct V_1 * V_2 )
{
T_2 V_9 = F_3 ( V_2 ) ;
if ( V_9 )
return V_9 ;
return F_76 ( V_2 ) ? V_26 :
V_31 ;
}
unsigned long F_77 ( struct V_1 * V_2 )
{
unsigned long V_32 = V_2 -> V_4 ;
if ( V_32 )
return F_6 ( V_35 ) + F_1 ( V_2 ) ;
else
return V_2 -> V_186 ;
}
static bool F_78 ( unsigned long V_42 )
{
if ( ( int ) V_42 < 0 )
return true ;
if ( F_79 ( V_187 ) && ( ( 0x80000000 - V_42 ) <= 256 ) )
return true ;
return false ;
}
static void V_176 ( struct V_1 * V_2 )
{
int V_65 ;
struct V_52 * V_53 = & F_34 ( V_52 ) ;
struct V_79 * V_88 ;
unsigned long V_42 ;
int V_188 = 0 ;
int V_189 ;
if ( V_53 -> V_107 )
F_27 ( V_53 , F_6 ( V_47 ) ,
F_6 ( V_48 ) ) ;
F_4 ( V_2 ) ;
V_189 = F_5 ( V_2 ) ;
if ( V_189 )
F_80 () ;
else
F_81 () ;
for ( V_65 = 0 ; V_65 < V_53 -> V_124 ; ++ V_65 ) {
V_88 = V_53 -> V_88 [ V_65 ] ;
if ( ! V_88 -> V_97 . V_41 || F_26 ( V_88 -> V_97 . V_41 ) )
continue;
V_42 = F_12 ( V_88 -> V_97 . V_41 ) ;
if ( F_78 ( V_42 ) ) {
V_188 = 1 ;
F_72 ( V_88 , V_42 , V_2 ) ;
}
}
if ( ! V_188 ) {
for ( V_65 = 0 ; V_65 < V_8 -> V_71 ; ++ V_65 ) {
if ( F_26 ( V_65 + 1 ) )
continue;
V_42 = F_12 ( V_65 + 1 ) ;
if ( F_78 ( V_42 ) )
F_15 ( V_65 + 1 , 0 ) ;
}
}
F_31 ( V_53 , V_53 -> V_119 [ 0 ] ) ;
if ( V_189 )
F_82 () ;
else
F_83 () ;
}
static void F_84 ( int V_190 )
{
struct V_52 * V_53 = & F_85 ( V_52 , V_190 ) ;
if ( ! V_8 )
return;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_119 [ 0 ] = V_112 ;
}
static int T_4
F_86 ( struct V_191 * V_192 , unsigned long V_193 , void * V_194 )
{
unsigned int V_190 = ( long ) V_194 ;
switch ( V_193 & ~ V_195 ) {
case V_196 :
F_84 ( V_190 ) ;
break;
default:
break;
}
return V_197 ;
}
int T_4 F_87 ( struct V_198 * V_115 )
{
if ( V_8 )
return - V_177 ;
V_8 = V_115 ;
F_88 ( L_4 ,
V_115 -> V_199 ) ;
#ifdef V_27
if ( F_89 () & V_27 )
V_28 = V_29 ;
#endif
F_90 ( & V_198 , L_5 , V_168 ) ;
F_91 ( F_86 ) ;
return 0 ;
}
