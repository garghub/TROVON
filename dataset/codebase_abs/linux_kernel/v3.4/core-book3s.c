static inline unsigned long F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 * V_3 ) { }
static inline T_2 F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_4 ( struct V_1 * V_2 ) { }
static inline int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_4 = V_2 -> V_5 ;
if ( ( V_4 & V_6 ) && ! ( V_7 -> V_8 & V_9 ) ) {
unsigned long V_10 = ( V_4 & V_11 ) >> V_12 ;
if ( V_10 > 1 )
return 4 * ( V_10 - 1 ) ;
}
return 0 ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned long V_4 = V_2 -> V_5 ;
unsigned long V_13 = ( V_7 -> V_8 & V_9 ) ?
V_14 : V_15 ;
if ( ! ( V_4 & V_6 ) || ( V_4 & V_13 ) )
* V_3 = F_6 ( V_16 ) ;
}
static inline T_2 F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 & V_18 )
return V_19 ;
if ( ( V_2 -> V_17 & V_20 ) && V_21 != V_22 )
return V_23 ;
return V_24 ;
}
static inline T_2 F_3 ( struct V_1 * V_2 )
{
unsigned long V_4 = V_2 -> V_5 ;
unsigned long V_25 = V_26 ;
unsigned long V_27 = V_28 ;
if ( F_8 ( V_2 ) != 0xf00 )
return F_7 ( V_2 ) ;
if ( ( V_7 -> V_8 & V_29 ) &&
! ( V_4 & V_6 ) )
return F_7 ( V_2 ) ;
if ( V_7 -> V_8 & V_30 ) {
unsigned long V_31 = F_6 ( V_32 ) ;
if ( V_31 >= V_33 )
return V_24 ;
return V_19 ;
}
if ( V_7 -> V_8 & V_9 ) {
V_25 = V_34 ;
V_27 = V_35 ;
}
if ( V_4 & V_27 )
return V_19 ;
if ( ( V_4 & V_25 ) && ( V_21 != V_22 ) )
return V_23 ;
return V_24 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_5 = F_6 ( V_36 ) ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return ! V_2 -> V_37 ;
}
void F_9 ( void )
{
}
static unsigned long F_10 ( int V_38 )
{
unsigned long V_39 ;
switch ( V_38 ) {
case 1 :
V_39 = F_6 ( V_40 ) ;
break;
case 2 :
V_39 = F_6 ( V_41 ) ;
break;
case 3 :
V_39 = F_6 ( V_42 ) ;
break;
case 4 :
V_39 = F_6 ( V_43 ) ;
break;
case 5 :
V_39 = F_6 ( V_44 ) ;
break;
case 6 :
V_39 = F_6 ( V_45 ) ;
break;
#ifdef F_11
case 7 :
V_39 = F_6 ( V_46 ) ;
break;
case 8 :
V_39 = F_6 ( V_47 ) ;
break;
#endif
default:
F_12 ( V_48 L_1 , V_38 ) ;
V_39 = 0 ;
}
return V_39 ;
}
static void F_13 ( int V_38 , unsigned long V_39 )
{
switch ( V_38 ) {
case 1 :
F_14 ( V_40 , V_39 ) ;
break;
case 2 :
F_14 ( V_41 , V_39 ) ;
break;
case 3 :
F_14 ( V_42 , V_39 ) ;
break;
case 4 :
F_14 ( V_43 , V_39 ) ;
break;
case 5 :
F_14 ( V_44 , V_39 ) ;
break;
case 6 :
F_14 ( V_45 , V_39 ) ;
break;
#ifdef F_11
case 7 :
F_14 ( V_46 , V_39 ) ;
break;
case 8 :
F_14 ( V_47 , V_39 ) ;
break;
#endif
default:
F_12 ( V_48 L_2 , V_38 ) ;
}
}
static int F_15 ( struct V_49 * V_50 ,
T_1 V_51 [] , unsigned int V_52 [] ,
int V_53 )
{
unsigned long V_54 , V_55 , V_56 ;
unsigned long V_57 [ V_58 ] , V_59 [ V_58 ] ;
int V_60 [ V_58 ] , V_61 [ V_58 ] ;
int V_62 , V_63 ;
unsigned long V_64 = V_7 -> V_65 ;
unsigned long V_66 = V_7 -> V_67 ;
if ( V_53 > V_7 -> V_68 )
return - 1 ;
for ( V_62 = 0 ; V_62 < V_53 ; ++ V_62 ) {
if ( ( V_52 [ V_62 ] & V_69 )
&& ! V_7 -> V_70 ( V_51 [ V_62 ] ) ) {
V_7 -> V_71 ( V_51 [ V_62 ] , V_52 [ V_62 ] ,
V_50 -> V_72 [ V_62 ] ) ;
V_51 [ V_62 ] = V_50 -> V_72 [ V_62 ] [ 0 ] ;
}
if ( V_7 -> V_73 ( V_51 [ V_62 ] , & V_50 -> V_74 [ V_62 ] [ 0 ] ,
& V_50 -> V_75 [ V_62 ] [ 0 ] ) )
return - 1 ;
}
V_55 = V_54 = 0 ;
for ( V_62 = 0 ; V_62 < V_53 ; ++ V_62 ) {
V_56 = ( V_55 | V_50 -> V_75 [ V_62 ] [ 0 ] ) +
( V_55 & V_50 -> V_75 [ V_62 ] [ 0 ] & V_64 ) ;
if ( ( ( ( V_56 + V_66 ) ^ V_55 ) & V_54 ) != 0 ||
( ( ( V_56 + V_66 ) ^ V_50 -> V_75 [ V_62 ] [ 0 ] ) &
V_50 -> V_74 [ V_62 ] [ 0 ] ) != 0 )
break;
V_55 = V_56 ;
V_54 |= V_50 -> V_74 [ V_62 ] [ 0 ] ;
}
if ( V_62 == V_53 )
return 0 ;
if ( ! V_7 -> V_71 )
return - 1 ;
for ( V_62 = 0 ; V_62 < V_53 ; ++ V_62 ) {
V_61 [ V_62 ] = 0 ;
V_60 [ V_62 ] = V_7 -> V_71 ( V_51 [ V_62 ] , V_52 [ V_62 ] ,
V_50 -> V_72 [ V_62 ] ) ;
for ( V_63 = 1 ; V_63 < V_60 [ V_62 ] ; ++ V_63 )
V_7 -> V_73 ( V_50 -> V_72 [ V_62 ] [ V_63 ] ,
& V_50 -> V_74 [ V_62 ] [ V_63 ] ,
& V_50 -> V_75 [ V_62 ] [ V_63 ] ) ;
}
V_62 = 0 ;
V_63 = - 1 ;
V_55 = V_54 = V_56 = 0 ;
while ( V_62 < V_53 ) {
if ( V_63 >= 0 ) {
V_55 = V_59 [ V_62 ] ;
V_54 = V_57 [ V_62 ] ;
V_63 = V_61 [ V_62 ] ;
}
while ( ++ V_63 < V_60 [ V_62 ] ) {
V_56 = ( V_55 | V_50 -> V_75 [ V_62 ] [ V_63 ] ) +
( V_55 & V_50 -> V_75 [ V_62 ] [ V_63 ] & V_64 ) ;
if ( ( ( ( V_56 + V_66 ) ^ V_55 ) & V_54 ) == 0 &&
( ( ( V_56 + V_66 ) ^ V_50 -> V_75 [ V_62 ] [ V_63 ] )
& V_50 -> V_74 [ V_62 ] [ V_63 ] ) == 0 )
break;
}
if ( V_63 >= V_60 [ V_62 ] ) {
if ( -- V_62 < 0 )
return - 1 ;
} else {
V_61 [ V_62 ] = V_63 ;
V_59 [ V_62 ] = V_55 ;
V_57 [ V_62 ] = V_54 ;
V_55 = V_56 ;
V_54 |= V_50 -> V_74 [ V_62 ] [ V_63 ] ;
++ V_62 ;
V_63 = - 1 ;
}
}
for ( V_62 = 0 ; V_62 < V_53 ; ++ V_62 )
V_51 [ V_62 ] = V_50 -> V_72 [ V_62 ] [ V_61 [ V_62 ] ] ;
return 0 ;
}
static int F_16 ( struct V_76 * * V_77 , unsigned int V_52 [] ,
int V_78 , int V_79 )
{
int V_80 = 0 , V_81 = 0 , V_82 = 0 ;
int V_62 , V_83 , V_84 ;
struct V_76 * V_85 ;
V_83 = V_78 + V_79 ;
if ( V_83 <= 1 )
return 0 ;
V_84 = 1 ;
for ( V_62 = 0 ; V_62 < V_83 ; ++ V_62 ) {
if ( V_52 [ V_62 ] & V_86 ) {
V_52 [ V_62 ] &= ~ V_69 ;
continue;
}
V_85 = V_77 [ V_62 ] ;
if ( V_84 ) {
V_80 = V_85 -> V_87 . V_88 ;
V_81 = V_85 -> V_87 . V_89 ;
V_82 = V_85 -> V_87 . V_90 ;
V_84 = 0 ;
} else if ( V_85 -> V_87 . V_88 != V_80 ||
V_85 -> V_87 . V_89 != V_81 ||
V_85 -> V_87 . V_90 != V_82 ) {
return - V_91 ;
}
}
if ( V_80 || V_81 || V_82 )
for ( V_62 = 0 ; V_62 < V_83 ; ++ V_62 )
if ( V_52 [ V_62 ] & V_86 )
V_52 [ V_62 ] |= V_69 ;
return 0 ;
}
static T_1 F_17 ( T_1 V_92 , T_1 V_39 )
{
T_1 V_93 = ( V_39 - V_92 ) & 0xfffffffful ;
if ( V_92 > V_39 && ( V_92 - V_39 ) < 256 )
V_93 = 0 ;
return V_93 ;
}
static void F_18 ( struct V_76 * V_85 )
{
T_3 V_39 , V_93 , V_92 ;
if ( V_85 -> V_94 . V_95 & V_96 )
return;
if ( ! V_85 -> V_94 . V_38 )
return;
do {
V_92 = F_19 ( & V_85 -> V_94 . V_97 ) ;
F_20 () ;
V_39 = F_10 ( V_85 -> V_94 . V_38 ) ;
V_93 = F_17 ( V_92 , V_39 ) ;
if ( ! V_93 )
return;
} while ( F_21 ( & V_85 -> V_94 . V_97 , V_92 , V_39 ) != V_92 );
F_22 ( V_93 , & V_85 -> V_98 ) ;
F_23 ( V_93 , & V_85 -> V_94 . V_99 ) ;
}
static int F_24 ( int V_100 )
{
return ( V_7 -> V_8 & V_101 )
&& ( V_100 == 5 || V_100 == 6 ) ;
}
static void F_25 ( struct V_49 * V_50 ,
unsigned long V_102 , unsigned long V_103 )
{
struct V_76 * V_85 ;
T_1 V_39 , V_92 , V_93 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_50 -> V_104 ; ++ V_62 ) {
V_85 = V_50 -> V_105 [ V_62 ] ;
if ( ! V_85 -> V_94 . V_38 )
continue;
V_39 = ( V_85 -> V_94 . V_38 == 5 ) ? V_102 : V_103 ;
V_92 = F_19 ( & V_85 -> V_94 . V_97 ) ;
V_85 -> V_94 . V_38 = 0 ;
V_93 = F_17 ( V_92 , V_39 ) ;
if ( V_93 )
F_22 ( V_93 , & V_85 -> V_98 ) ;
}
}
static void F_26 ( struct V_49 * V_50 ,
unsigned long V_102 , unsigned long V_103 )
{
struct V_76 * V_85 ;
T_1 V_39 , V_92 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_50 -> V_104 ; ++ V_62 ) {
V_85 = V_50 -> V_105 [ V_62 ] ;
V_85 -> V_94 . V_38 = V_50 -> V_106 [ V_62 ] ;
V_39 = ( V_85 -> V_94 . V_38 == 5 ) ? V_102 : V_103 ;
V_92 = F_19 ( & V_85 -> V_94 . V_97 ) ;
if ( F_17 ( V_92 , V_39 ) )
F_27 ( & V_85 -> V_94 . V_97 , V_39 ) ;
F_28 ( V_85 ) ;
}
}
static void F_29 ( struct V_49 * V_50 , unsigned long V_107 )
{
unsigned long V_102 , V_103 ;
if ( ! V_50 -> V_104 ) {
F_14 ( V_108 , V_107 ) ;
return;
}
asm volatile("mtspr %3,%2; mfspr %0,%4; mfspr %1,%5"
: "=&r" (pmc5), "=&r" (pmc6)
: "r" (mmcr0 & ~(MMCR0_PMC1CE | MMCR0_PMCjCE)),
"i" (SPRN_MMCR0),
"i" (SPRN_PMC5), "i" (SPRN_PMC6));
if ( V_107 & V_109 )
F_25 ( V_50 , V_102 , V_103 ) ;
else
F_26 ( V_50 , V_102 , V_103 ) ;
if ( V_107 & ( V_110 | V_111 ) )
F_14 ( V_108 , V_107 ) ;
}
static void F_30 ( struct V_112 * V_112 )
{
struct V_49 * V_50 ;
unsigned long V_8 ;
if ( ! V_7 )
return;
F_31 ( V_8 ) ;
V_50 = & F_32 ( V_49 ) ;
if ( ! V_50 -> V_113 ) {
V_50 -> V_113 = 1 ;
V_50 -> V_114 = 0 ;
if ( ! V_50 -> V_115 ) {
F_33 () ;
V_50 -> V_115 = 1 ;
}
if ( V_50 -> V_116 [ 2 ] & V_6 ) {
F_14 ( V_36 ,
V_50 -> V_116 [ 2 ] & ~ V_6 ) ;
F_34 () ;
}
F_29 ( V_50 , F_6 ( V_108 ) | V_109 ) ;
F_34 () ;
}
F_35 ( V_8 ) ;
}
static void F_36 ( struct V_112 * V_112 )
{
struct V_76 * V_85 ;
struct V_49 * V_50 ;
unsigned long V_8 ;
long V_62 ;
unsigned long V_39 ;
T_3 V_117 ;
unsigned int V_118 [ V_58 ] ;
int V_119 ;
int V_38 ;
if ( ! V_7 )
return;
F_31 ( V_8 ) ;
V_50 = & F_32 ( V_49 ) ;
if ( ! V_50 -> V_113 ) {
F_35 ( V_8 ) ;
return;
}
V_50 -> V_113 = 0 ;
if ( ! V_50 -> V_114 ) {
F_14 ( V_36 , V_50 -> V_116 [ 2 ] & ~ V_6 ) ;
F_14 ( V_120 , V_50 -> V_116 [ 1 ] ) ;
if ( V_50 -> V_121 == 0 )
F_37 ( 0 ) ;
goto V_122;
}
if ( V_7 -> V_123 ( V_50 -> V_124 , V_50 -> V_121 , V_118 ,
V_50 -> V_116 ) ) {
F_12 ( V_48 L_3 ) ;
goto V_125;
}
V_85 = V_50 -> V_85 [ 0 ] ;
if ( V_85 -> V_87 . V_88 )
V_50 -> V_116 [ 0 ] |= V_126 ;
if ( V_85 -> V_87 . V_89 )
V_50 -> V_116 [ 0 ] |= V_21 ;
if ( V_85 -> V_87 . V_90 )
V_50 -> V_116 [ 0 ] |= V_22 ;
F_37 ( 1 ) ;
F_14 ( V_36 , V_50 -> V_116 [ 2 ] & ~ V_6 ) ;
F_14 ( V_120 , V_50 -> V_116 [ 1 ] ) ;
F_14 ( V_108 , ( V_50 -> V_116 [ 0 ] & ~ ( V_110 | V_111 ) )
| V_109 ) ;
for ( V_62 = 0 ; V_62 < V_50 -> V_121 ; ++ V_62 ) {
V_85 = V_50 -> V_85 [ V_62 ] ;
if ( V_85 -> V_94 . V_38 && V_85 -> V_94 . V_38 != V_118 [ V_62 ] + 1 ) {
F_18 ( V_85 ) ;
F_13 ( V_85 -> V_94 . V_38 , 0 ) ;
V_85 -> V_94 . V_38 = 0 ;
}
}
V_50 -> V_104 = V_119 = 0 ;
for ( V_62 = 0 ; V_62 < V_50 -> V_121 ; ++ V_62 ) {
V_85 = V_50 -> V_85 [ V_62 ] ;
if ( V_85 -> V_94 . V_38 )
continue;
V_38 = V_118 [ V_62 ] + 1 ;
if ( F_24 ( V_38 ) ) {
V_50 -> V_105 [ V_119 ] = V_85 ;
V_50 -> V_106 [ V_119 ] = V_38 ;
++ V_119 ;
continue;
}
V_39 = 0 ;
if ( V_85 -> V_94 . V_127 ) {
V_117 = F_19 ( & V_85 -> V_94 . V_99 ) ;
if ( V_117 < 0x80000000L )
V_39 = 0x80000000L - V_117 ;
}
F_27 ( & V_85 -> V_94 . V_97 , V_39 ) ;
V_85 -> V_94 . V_38 = V_38 ;
if ( V_85 -> V_94 . V_95 & V_96 )
V_39 = 0 ;
F_13 ( V_38 , V_39 ) ;
F_28 ( V_85 ) ;
}
V_50 -> V_104 = V_119 ;
V_50 -> V_116 [ 0 ] |= V_128 | V_129 ;
V_122:
F_34 () ;
F_29 ( V_50 , V_50 -> V_116 [ 0 ] ) ;
if ( V_50 -> V_116 [ 2 ] & V_6 ) {
F_34 () ;
F_14 ( V_36 , V_50 -> V_116 [ 2 ] ) ;
}
V_125:
F_35 ( V_8 ) ;
}
static int F_38 ( struct V_76 * V_130 , int V_131 ,
struct V_76 * V_77 [] , T_1 * V_124 ,
unsigned int * V_8 )
{
int V_83 = 0 ;
struct V_76 * V_85 ;
if ( ! F_39 ( V_130 ) ) {
if ( V_83 >= V_131 )
return - 1 ;
V_77 [ V_83 ] = V_130 ;
V_8 [ V_83 ] = V_130 -> V_94 . V_132 ;
V_124 [ V_83 ++ ] = V_130 -> V_94 . V_133 ;
}
F_40 (event, &group->sibling_list, group_entry) {
if ( ! F_39 ( V_85 ) &&
V_85 -> V_95 != V_134 ) {
if ( V_83 >= V_131 )
return - 1 ;
V_77 [ V_83 ] = V_85 ;
V_8 [ V_83 ] = V_85 -> V_94 . V_132 ;
V_124 [ V_83 ++ ] = V_85 -> V_94 . V_133 ;
}
}
return V_83 ;
}
static int F_41 ( struct V_76 * V_85 , int V_135 )
{
struct V_49 * V_50 ;
unsigned long V_8 ;
int V_136 ;
int V_137 = - V_91 ;
F_31 ( V_8 ) ;
F_42 ( V_85 -> V_112 ) ;
V_50 = & F_32 ( V_49 ) ;
V_136 = V_50 -> V_121 ;
if ( V_136 >= V_7 -> V_68 )
goto V_125;
V_50 -> V_85 [ V_136 ] = V_85 ;
V_50 -> V_124 [ V_136 ] = V_85 -> V_94 . V_133 ;
V_50 -> V_8 [ V_136 ] = V_85 -> V_94 . V_132 ;
if ( ! ( V_135 & V_138 ) )
V_85 -> V_94 . V_95 = V_96 | V_139 ;
if ( V_50 -> V_140 & V_141 )
goto V_142;
if ( F_16 ( V_50 -> V_85 , V_50 -> V_8 , V_136 , 1 ) )
goto V_125;
if ( F_15 ( V_50 , V_50 -> V_124 , V_50 -> V_8 , V_136 + 1 ) )
goto V_125;
V_85 -> V_94 . V_133 = V_50 -> V_124 [ V_136 ] ;
V_142:
++ V_50 -> V_121 ;
++ V_50 -> V_114 ;
V_137 = 0 ;
V_125:
F_43 ( V_85 -> V_112 ) ;
F_35 ( V_8 ) ;
return V_137 ;
}
static void F_44 ( struct V_76 * V_85 , int V_135 )
{
struct V_49 * V_50 ;
long V_62 ;
unsigned long V_8 ;
F_31 ( V_8 ) ;
F_42 ( V_85 -> V_112 ) ;
F_18 ( V_85 ) ;
V_50 = & F_32 ( V_49 ) ;
for ( V_62 = 0 ; V_62 < V_50 -> V_121 ; ++ V_62 ) {
if ( V_85 == V_50 -> V_85 [ V_62 ] ) {
while ( ++ V_62 < V_50 -> V_121 ) {
V_50 -> V_85 [ V_62 - 1 ] = V_50 -> V_85 [ V_62 ] ;
V_50 -> V_124 [ V_62 - 1 ] = V_50 -> V_124 [ V_62 ] ;
V_50 -> V_8 [ V_62 - 1 ] = V_50 -> V_8 [ V_62 ] ;
}
-- V_50 -> V_121 ;
V_7 -> V_143 ( V_85 -> V_94 . V_38 - 1 , V_50 -> V_116 ) ;
if ( V_85 -> V_94 . V_38 ) {
F_13 ( V_85 -> V_94 . V_38 , 0 ) ;
V_85 -> V_94 . V_38 = 0 ;
}
F_28 ( V_85 ) ;
break;
}
}
for ( V_62 = 0 ; V_62 < V_50 -> V_104 ; ++ V_62 )
if ( V_85 == V_50 -> V_105 [ V_62 ] )
break;
if ( V_62 < V_50 -> V_104 ) {
while ( ++ V_62 < V_50 -> V_104 ) {
V_50 -> V_105 [ V_62 - 1 ] = V_50 -> V_105 [ V_62 ] ;
V_50 -> V_106 [ V_62 - 1 ] = V_50 -> V_106 [ V_62 ] ;
}
-- V_50 -> V_104 ;
}
if ( V_50 -> V_121 == 0 ) {
V_50 -> V_116 [ 0 ] &= ~ ( V_128 | V_129 ) ;
}
F_43 ( V_85 -> V_112 ) ;
F_35 ( V_8 ) ;
}
static void F_45 ( struct V_76 * V_85 , int V_135 )
{
unsigned long V_8 ;
T_3 V_117 ;
unsigned long V_39 ;
if ( ! V_85 -> V_94 . V_38 || ! V_85 -> V_94 . V_127 )
return;
if ( ! ( V_85 -> V_94 . V_95 & V_96 ) )
return;
if ( V_135 & V_144 )
F_46 ( ! ( V_85 -> V_94 . V_95 & V_139 ) ) ;
F_31 ( V_8 ) ;
F_42 ( V_85 -> V_112 ) ;
V_85 -> V_94 . V_95 = 0 ;
V_117 = F_19 ( & V_85 -> V_94 . V_99 ) ;
V_39 = 0 ;
if ( V_117 < 0x80000000L )
V_39 = 0x80000000L - V_117 ;
F_13 ( V_85 -> V_94 . V_38 , V_39 ) ;
F_28 ( V_85 ) ;
F_43 ( V_85 -> V_112 ) ;
F_35 ( V_8 ) ;
}
static void F_47 ( struct V_76 * V_85 , int V_135 )
{
unsigned long V_8 ;
if ( ! V_85 -> V_94 . V_38 || ! V_85 -> V_94 . V_127 )
return;
if ( V_85 -> V_94 . V_95 & V_96 )
return;
F_31 ( V_8 ) ;
F_42 ( V_85 -> V_112 ) ;
F_18 ( V_85 ) ;
V_85 -> V_94 . V_95 |= V_96 | V_139 ;
F_13 ( V_85 -> V_94 . V_38 , 0 ) ;
F_28 ( V_85 ) ;
F_43 ( V_85 -> V_112 ) ;
F_35 ( V_8 ) ;
}
void F_48 ( struct V_112 * V_112 )
{
struct V_49 * V_50 = & F_32 ( V_49 ) ;
F_42 ( V_112 ) ;
V_50 -> V_140 |= V_141 ;
V_50 -> V_145 = V_50 -> V_121 ;
}
void F_49 ( struct V_112 * V_112 )
{
struct V_49 * V_50 = & F_32 ( V_49 ) ;
V_50 -> V_140 &= ~ V_141 ;
F_43 ( V_112 ) ;
}
int F_50 ( struct V_112 * V_112 )
{
struct V_49 * V_50 ;
long V_62 , V_83 ;
if ( ! V_7 )
return - V_91 ;
V_50 = & F_32 ( V_49 ) ;
V_83 = V_50 -> V_121 ;
if ( F_16 ( V_50 -> V_85 , V_50 -> V_8 , 0 , V_83 ) )
return - V_91 ;
V_62 = F_15 ( V_50 , V_50 -> V_124 , V_50 -> V_8 , V_83 ) ;
if ( V_62 < 0 )
return - V_91 ;
for ( V_62 = V_50 -> V_145 ; V_62 < V_83 ; ++ V_62 )
V_50 -> V_85 [ V_62 ] -> V_94 . V_133 = V_50 -> V_124 [ V_62 ] ;
V_50 -> V_140 &= ~ V_141 ;
F_43 ( V_112 ) ;
return 0 ;
}
static int F_51 ( struct V_76 * V_85 , T_1 V_146 ,
unsigned int V_8 )
{
int V_83 ;
T_1 V_147 [ V_148 ] ;
if ( V_85 -> V_87 . V_88
|| V_85 -> V_87 . V_89
|| V_85 -> V_87 . V_90
|| V_85 -> V_87 . V_127 )
return 0 ;
if ( V_7 -> V_70 ( V_146 ) )
return 1 ;
if ( ! V_7 -> V_71 )
return 0 ;
V_8 |= V_86 | V_69 ;
V_83 = V_7 -> V_71 ( V_146 , V_8 , V_147 ) ;
return V_83 > 0 ;
}
static T_1 F_52 ( T_1 V_146 , unsigned long V_8 )
{
T_1 V_147 [ V_148 ] ;
int V_83 ;
V_8 &= ~ ( V_86 | V_69 ) ;
V_83 = V_7 -> V_71 ( V_146 , V_8 , V_147 ) ;
if ( ! V_83 )
return 0 ;
return V_147 [ 0 ] ;
}
static void F_53 ( struct V_76 * V_85 )
{
if ( ! F_54 ( & V_149 , - 1 , 1 ) ) {
F_55 ( & V_150 ) ;
if ( F_56 ( & V_149 ) == 0 )
F_57 () ;
F_58 ( & V_150 ) ;
}
}
static int F_59 ( T_1 V_133 , T_1 * V_151 )
{
unsigned long type , V_152 , V_153 ;
int V_146 ;
if ( ! V_7 -> V_154 )
return - V_155 ;
type = V_133 & 0xff ;
V_152 = ( V_133 >> 8 ) & 0xff ;
V_153 = ( V_133 >> 16 ) & 0xff ;
if ( type >= V_156 ||
V_152 >= V_157 ||
V_153 >= V_158 )
return - V_155 ;
V_146 = ( * V_7 -> V_154 ) [ type ] [ V_152 ] [ V_153 ] ;
if ( V_146 == 0 )
return - V_159 ;
if ( V_146 == - 1 )
return - V_155 ;
* V_151 = V_146 ;
return 0 ;
}
static int F_60 ( struct V_76 * V_85 )
{
T_1 V_146 ;
unsigned long V_8 ;
struct V_76 * V_77 [ V_58 ] ;
T_1 V_124 [ V_58 ] ;
unsigned int V_52 [ V_58 ] ;
int V_83 ;
int V_160 ;
struct V_49 * V_50 ;
if ( ! V_7 )
return - V_161 ;
if ( F_61 ( V_85 ) )
return - V_159 ;
switch ( V_85 -> V_87 . type ) {
case V_162 :
V_146 = V_85 -> V_87 . V_133 ;
if ( V_146 >= V_7 -> V_163 || V_7 -> V_164 [ V_146 ] == 0 )
return - V_159 ;
V_146 = V_7 -> V_164 [ V_146 ] ;
break;
case V_165 :
V_160 = F_59 ( V_85 -> V_87 . V_133 , & V_146 ) ;
if ( V_160 )
return V_160 ;
break;
case V_166 :
V_146 = V_85 -> V_87 . V_133 ;
break;
default:
return - V_161 ;
}
V_85 -> V_94 . V_167 = V_146 ;
V_85 -> V_94 . V_38 = 0 ;
if ( ! F_62 ( V_168 ) )
V_85 -> V_87 . V_90 = 0 ;
V_8 = 0 ;
if ( V_85 -> V_169 & V_170 )
V_8 |= V_171 ;
if ( V_7 -> V_8 & V_101 ) {
if ( F_51 ( V_85 , V_146 , V_8 ) ) {
V_8 |= V_86 ;
} else if ( V_7 -> V_70 ( V_146 ) ) {
V_146 = F_52 ( V_146 , V_8 ) ;
if ( ! V_146 )
return - V_155 ;
}
}
V_83 = 0 ;
if ( V_85 -> V_172 != V_85 ) {
V_83 = F_38 ( V_85 -> V_172 , V_7 -> V_68 - 1 ,
V_77 , V_124 , V_52 ) ;
if ( V_83 < 0 )
return - V_155 ;
}
V_124 [ V_83 ] = V_146 ;
V_77 [ V_83 ] = V_85 ;
V_52 [ V_83 ] = V_8 ;
if ( F_16 ( V_77 , V_52 , V_83 , 1 ) )
return - V_155 ;
V_50 = & F_63 ( V_49 ) ;
V_160 = F_15 ( V_50 , V_124 , V_52 , V_83 + 1 ) ;
F_64 ( V_49 ) ;
if ( V_160 )
return - V_155 ;
V_85 -> V_94 . V_133 = V_124 [ V_83 ] ;
V_85 -> V_94 . V_132 = V_52 [ V_83 ] ;
V_85 -> V_94 . V_173 = V_85 -> V_94 . V_127 ;
F_27 ( & V_85 -> V_94 . V_99 , V_85 -> V_94 . V_173 ) ;
V_160 = 0 ;
if ( ! F_65 ( & V_149 ) ) {
F_55 ( & V_150 ) ;
if ( F_66 ( & V_149 ) == 0 &&
F_67 ( V_174 ) )
V_160 = - V_175 ;
else
F_68 ( & V_149 ) ;
F_58 ( & V_150 ) ;
}
V_85 -> V_176 = F_53 ;
return V_160 ;
}
static int F_69 ( struct V_76 * V_85 )
{
return V_85 -> V_94 . V_38 ;
}
static void F_70 ( struct V_76 * V_85 , unsigned long V_39 ,
struct V_1 * V_2 )
{
T_1 V_177 = V_85 -> V_94 . V_127 ;
T_3 V_92 , V_93 , V_117 ;
int V_178 = 0 ;
if ( V_85 -> V_94 . V_95 & V_96 ) {
F_13 ( V_85 -> V_94 . V_38 , 0 ) ;
return;
}
V_92 = F_19 ( & V_85 -> V_94 . V_97 ) ;
V_93 = F_17 ( V_92 , V_39 ) ;
F_22 ( V_93 , & V_85 -> V_98 ) ;
V_39 = 0 ;
V_117 = F_19 ( & V_85 -> V_94 . V_99 ) - V_93 ;
if ( V_177 ) {
if ( V_117 <= 0 ) {
V_117 += V_177 ;
if ( V_117 <= 0 )
V_117 = V_177 ;
V_178 = 1 ;
V_85 -> V_94 . V_173 = V_85 -> V_94 . V_127 ;
}
if ( V_117 < 0x80000000LL )
V_39 = 0x80000000LL - V_117 ;
}
F_13 ( V_85 -> V_94 . V_38 , V_39 ) ;
F_27 ( & V_85 -> V_94 . V_97 , V_39 ) ;
F_27 ( & V_85 -> V_94 . V_99 , V_117 ) ;
F_28 ( V_85 ) ;
if ( V_178 ) {
struct V_179 V_180 ;
F_71 ( & V_180 , ~ 0ULL ) ;
V_180 . V_177 = V_85 -> V_94 . V_173 ;
if ( V_85 -> V_87 . V_181 & V_182 )
F_2 ( V_2 , & V_180 . V_183 ) ;
if ( F_72 ( V_85 , & V_180 , V_2 ) )
F_47 ( V_85 , 0 ) ;
}
}
unsigned long F_73 ( struct V_1 * V_2 )
{
T_2 V_8 = F_3 ( V_2 ) ;
if ( V_8 )
return V_8 ;
return F_74 ( V_2 ) ? V_19 :
V_24 ;
}
unsigned long F_75 ( struct V_1 * V_2 )
{
unsigned long V_4 = V_2 -> V_5 ;
if ( F_8 ( V_2 ) != 0xf00 )
return V_2 -> V_184 ;
if ( ( V_7 -> V_8 & V_29 ) &&
! ( V_4 & V_6 ) )
return V_2 -> V_184 ;
return F_6 ( V_32 ) + F_1 ( V_2 ) ;
}
static bool F_76 ( unsigned long V_39 )
{
if ( ( int ) V_39 < 0 )
return true ;
if ( F_77 ( V_185 ) && ( ( 0x80000000 - V_39 ) <= 256 ) )
return true ;
return false ;
}
static void V_174 ( struct V_1 * V_2 )
{
int V_62 ;
struct V_49 * V_50 = & F_32 ( V_49 ) ;
struct V_76 * V_85 ;
unsigned long V_39 ;
int V_186 = 0 ;
int V_187 ;
if ( V_50 -> V_104 )
F_25 ( V_50 , F_6 ( V_44 ) ,
F_6 ( V_45 ) ) ;
F_4 ( V_2 ) ;
V_187 = F_5 ( V_2 ) ;
if ( V_187 )
F_78 () ;
else
F_79 () ;
for ( V_62 = 0 ; V_62 < V_50 -> V_121 ; ++ V_62 ) {
V_85 = V_50 -> V_85 [ V_62 ] ;
if ( ! V_85 -> V_94 . V_38 || F_24 ( V_85 -> V_94 . V_38 ) )
continue;
V_39 = F_10 ( V_85 -> V_94 . V_38 ) ;
if ( ( int ) V_39 < 0 ) {
V_186 = 1 ;
F_70 ( V_85 , V_39 , V_2 ) ;
}
}
if ( ! V_186 ) {
for ( V_62 = 0 ; V_62 < V_7 -> V_68 ; ++ V_62 ) {
if ( F_24 ( V_62 + 1 ) )
continue;
V_39 = F_10 ( V_62 + 1 ) ;
if ( F_76 ( V_39 ) )
F_13 ( V_62 + 1 , 0 ) ;
}
}
F_29 ( V_50 , V_50 -> V_116 [ 0 ] ) ;
if ( V_187 )
F_80 () ;
else
F_81 () ;
}
static void F_82 ( int V_188 )
{
struct V_49 * V_50 = & F_83 ( V_49 , V_188 ) ;
if ( ! V_7 )
return;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_116 [ 0 ] = V_109 ;
}
static int T_4
F_84 ( struct V_189 * V_190 , unsigned long V_191 , void * V_192 )
{
unsigned int V_188 = ( long ) V_192 ;
switch ( V_191 & ~ V_193 ) {
case V_194 :
F_82 ( V_188 ) ;
break;
default:
break;
}
return V_195 ;
}
int T_4 F_85 ( struct V_196 * V_112 )
{
if ( V_7 )
return - V_175 ;
V_7 = V_112 ;
F_86 ( L_4 ,
V_112 -> V_197 ) ;
#ifdef V_20
if ( F_87 () & V_20 )
V_21 = V_22 ;
#endif
F_88 ( & V_196 , L_5 , V_166 ) ;
F_89 ( F_84 ) ;
return 0 ;
}
