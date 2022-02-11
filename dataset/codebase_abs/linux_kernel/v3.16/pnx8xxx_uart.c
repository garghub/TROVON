static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
return ( F_2 ( V_2 -> V_4 . V_5 + V_3 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , int V_6 )
{
F_4 ( V_6 , V_2 -> V_4 . V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_7 , V_8 ;
V_7 = V_2 -> V_4 . V_9 -> V_10 ( & V_2 -> V_4 ) ;
V_8 = V_7 ^ V_2 -> V_11 ;
if ( V_8 == 0 )
return;
V_2 -> V_11 = V_7 ;
if ( V_8 & V_12 )
V_2 -> V_4 . V_13 . V_14 ++ ;
if ( V_8 & V_15 )
V_2 -> V_4 . V_13 . V_16 ++ ;
if ( V_8 & V_17 )
F_6 ( & V_2 -> V_4 , V_7 & V_17 ) ;
if ( V_8 & V_18 )
F_7 ( & V_2 -> V_4 , V_7 & V_18 ) ;
F_8 ( & V_2 -> V_4 . V_19 -> V_4 . V_20 ) ;
}
static void F_9 ( unsigned long V_21 )
{
struct V_1 * V_2 = (struct V_1 * ) V_21 ;
unsigned long V_22 ;
if ( V_2 -> V_4 . V_19 ) {
F_10 ( & V_2 -> V_4 . V_23 , V_22 ) ;
F_5 ( V_2 ) ;
F_11 ( & V_2 -> V_4 . V_23 , V_22 ) ;
F_12 ( & V_2 -> V_24 , V_25 + V_26 ) ;
}
}
static void F_13 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
T_1 V_28 ;
V_28 = F_1 ( V_2 , V_29 ) ;
F_3 ( V_2 , V_29 , V_28 & ~ V_30 ) ;
F_3 ( V_2 , V_31 , V_30 ) ;
}
static void F_14 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
T_1 V_28 ;
F_3 ( V_2 , V_31 , V_30 ) ;
V_28 = F_1 ( V_2 , V_29 ) ;
F_3 ( V_2 , V_29 , V_28 | V_30 ) ;
}
static void F_15 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
T_1 V_28 ;
V_28 = F_1 ( V_2 , V_29 ) ;
F_3 ( V_2 , V_29 , V_28 & ~ V_32 ) ;
F_3 ( V_2 , V_31 , V_32 ) ;
}
static void F_16 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_12 ( & V_2 -> V_24 , V_25 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
unsigned int V_7 , V_33 , V_34 ;
V_7 = F_18 ( F_1 ( V_2 , V_35 ) ) |
F_19 ( F_1 ( V_2 , V_36 ) ) ;
while ( V_7 & F_18 ( V_37 ) ) {
V_33 = F_1 ( V_2 , V_35 ) & 0xff ;
V_2 -> V_4 . V_13 . V_38 ++ ;
V_34 = V_39 ;
if ( V_7 & ( F_18 ( V_40 |
V_41 |
V_42 ) |
F_19 ( V_43 ) ) ) {
if ( V_7 & F_18 ( V_42 ) ) {
V_7 &= ~ ( F_18 ( V_40 ) |
F_18 ( V_41 ) ) ;
V_2 -> V_4 . V_13 . V_44 ++ ;
if ( F_20 ( & V_2 -> V_4 ) )
goto V_45;
} else if ( V_7 & F_18 ( V_41 ) )
V_2 -> V_4 . V_13 . V_46 ++ ;
else if ( V_7 & F_18 ( V_40 ) )
V_2 -> V_4 . V_13 . V_47 ++ ;
if ( V_7 & F_19 ( V_43 ) )
V_2 -> V_4 . V_13 . V_48 ++ ;
V_7 &= V_2 -> V_4 . V_49 ;
if ( V_7 & F_18 ( V_41 ) )
V_34 = V_50 ;
else if ( V_7 & F_18 ( V_40 ) )
V_34 = V_51 ;
#ifdef F_21
V_2 -> V_4 . V_52 = 0 ;
#endif
}
if ( F_22 ( & V_2 -> V_4 , V_33 ) )
goto V_45;
F_23 ( & V_2 -> V_4 , V_7 ,
F_19 ( V_43 ) , V_33 , V_34 ) ;
V_45:
F_3 ( V_2 , V_53 , F_1 ( V_2 , V_53 ) |
V_54 ) ;
V_7 = F_18 ( F_1 ( V_2 , V_35 ) ) |
F_19 ( F_1 ( V_2 , V_36 ) ) ;
}
F_24 ( & V_2 -> V_4 . V_23 ) ;
F_25 ( & V_2 -> V_4 . V_19 -> V_4 ) ;
F_26 ( & V_2 -> V_4 . V_23 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = & V_2 -> V_4 . V_19 -> V_56 ;
if ( V_2 -> V_4 . V_57 ) {
F_3 ( V_2 , V_35 , V_2 -> V_4 . V_57 ) ;
V_2 -> V_4 . V_13 . V_58 ++ ;
V_2 -> V_4 . V_57 = 0 ;
return;
}
F_5 ( V_2 ) ;
if ( F_28 ( V_56 ) || F_29 ( & V_2 -> V_4 ) ) {
F_13 ( & V_2 -> V_4 ) ;
return;
}
while ( ( ( F_1 ( V_2 , V_35 ) &
V_59 ) >> 16 ) < 16 ) {
F_3 ( V_2 , V_35 , V_56 -> V_60 [ V_56 -> V_61 ] ) ;
V_56 -> V_61 = ( V_56 -> V_61 + 1 ) & ( V_62 - 1 ) ;
V_2 -> V_4 . V_13 . V_58 ++ ;
if ( F_28 ( V_56 ) )
break;
}
if ( F_30 ( V_56 ) < V_63 )
F_31 ( & V_2 -> V_4 ) ;
if ( F_28 ( V_56 ) )
F_13 ( & V_2 -> V_4 ) ;
}
static T_2 F_32 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
unsigned int V_7 ;
F_26 ( & V_2 -> V_4 . V_23 ) ;
V_7 = F_1 ( V_2 , V_36 ) & F_1 ( V_2 , V_29 ) ;
if ( V_7 & ( V_66 | V_67 ) )
F_17 ( V_2 ) ;
if ( V_7 & V_68 )
F_27 ( V_2 ) ;
F_3 ( V_2 , V_31 , V_7 ) ;
F_24 ( & V_2 -> V_4 . V_23 ) ;
return V_69 ;
}
static unsigned int F_33 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
return F_1 ( V_2 , V_35 ) & V_70 ? 0 : V_71 ;
}
static unsigned int F_34 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned int V_72 = V_15 ;
unsigned int V_73 ;
V_73 = F_1 ( V_2 , V_74 ) ;
V_72 |= V_73 & V_75 ? V_18 : 0 ;
V_72 |= V_73 & V_76 ? V_17 : 0 ;
return V_72 ;
}
static void F_35 ( struct V_27 * V_4 , unsigned int V_72 )
{
#if 0
struct pnx8xxx_port *sport = (struct pnx8xxx_port *)port;
unsigned int msr;
#endif
}
static void F_36 ( struct V_27 * V_4 , int V_77 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_22 ;
unsigned int V_78 ;
F_10 ( & V_2 -> V_4 . V_23 , V_22 ) ;
V_78 = F_1 ( V_2 , V_53 ) ;
if ( V_77 == - 1 )
V_78 |= V_79 ;
else
V_78 &= ~ V_79 ;
F_3 ( V_2 , V_53 , V_78 ) ;
F_11 ( & V_2 -> V_4 . V_23 , V_22 ) ;
}
static int F_37 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
int V_80 ;
V_80 = F_38 ( V_2 -> V_4 . V_64 , F_32 , 0 ,
L_1 , V_2 ) ;
if ( V_80 )
return V_80 ;
F_3 ( V_2 , V_31 , V_32 |
V_30 ) ;
F_3 ( V_2 , V_29 , F_1 ( V_2 , V_29 ) |
V_32 |
V_30 ) ;
F_39 ( & V_2 -> V_4 . V_23 ) ;
F_16 ( & V_2 -> V_4 ) ;
F_40 ( & V_2 -> V_4 . V_23 ) ;
return 0 ;
}
static void F_41 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
int V_78 ;
F_42 ( & V_2 -> V_24 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
V_78 = F_1 ( V_2 , V_53 ) ;
V_78 &= ~ V_79 ;
V_78 |= V_81 | V_82 ;
F_3 ( V_2 , V_53 , V_78 ) ;
F_3 ( V_2 , V_31 , V_32 |
V_30 ) ;
F_43 ( V_2 -> V_4 . V_64 , V_2 ) ;
}
static void
F_44 ( struct V_27 * V_4 , struct V_83 * V_84 ,
struct V_83 * V_85 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_22 ;
unsigned int V_86 , V_87 , V_88 , V_89 ;
unsigned int V_90 = V_85 ? V_85 -> V_91 & V_92 : V_93 ;
while ( ( V_84 -> V_91 & V_92 ) != V_94 &&
( V_84 -> V_91 & V_92 ) != V_93 ) {
V_84 -> V_91 &= ~ V_92 ;
V_84 -> V_91 |= V_90 ;
V_90 = V_93 ;
}
if ( ( V_84 -> V_91 & V_92 ) == V_93 )
V_86 = V_95 ;
else
V_86 = 0 ;
if ( V_84 -> V_91 & V_96 )
V_86 |= V_97 ;
if ( V_84 -> V_91 & V_98 ) {
V_86 |= V_99 ;
if ( ! ( V_84 -> V_91 & V_100 ) )
V_86 |= V_101 ;
}
V_88 = F_45 ( V_4 , V_84 , V_85 , 0 , V_4 -> V_102 / 16 ) ;
V_89 = F_46 ( V_4 , V_88 ) ;
F_10 ( & V_2 -> V_4 . V_23 , V_22 ) ;
V_2 -> V_4 . V_49 = F_19 ( V_43 ) |
F_19 ( V_103 ) |
F_19 ( V_66 ) ;
if ( V_84 -> V_104 & V_105 )
V_2 -> V_4 . V_49 |=
F_18 ( V_40 ) |
F_18 ( V_41 ) ;
if ( V_84 -> V_104 & ( V_106 | V_107 | V_108 ) )
V_2 -> V_4 . V_49 |=
F_19 ( V_67 ) ;
V_2 -> V_4 . V_109 = 0 ;
if ( V_84 -> V_104 & V_110 )
V_2 -> V_4 . V_109 |=
F_18 ( V_40 ) |
F_18 ( V_41 ) ;
if ( V_84 -> V_104 & V_106 ) {
V_2 -> V_4 . V_109 |=
F_19 ( V_67 ) ;
if ( V_84 -> V_104 & V_110 )
V_2 -> V_4 . V_109 |=
F_19 ( V_43 ) ;
}
if ( ( V_84 -> V_91 & V_111 ) == 0 )
V_2 -> V_4 . V_109 |=
F_19 ( V_66 ) ;
F_42 ( & V_2 -> V_24 ) ;
F_47 ( V_4 , V_84 -> V_91 , V_88 ) ;
V_87 = F_1 ( V_2 , V_29 ) ;
F_3 ( V_2 , V_29 , V_87 & ~ ( V_30 |
V_32 ) ) ;
while ( F_1 ( V_2 , V_35 ) & V_70 )
F_48 () ;
F_3 ( V_2 , V_29 , 0 ) ;
V_86 |= V_81 ;
V_86 |= V_82 ;
F_3 ( V_2 , V_53 , V_86 ) ;
V_89 -= 1 ;
F_3 ( V_2 , V_112 , V_89 ) ;
F_3 ( V_2 , V_31 , - 1 ) ;
F_3 ( V_2 , V_29 , V_87 ) ;
if ( F_49 ( & V_2 -> V_4 , V_84 -> V_91 ) )
F_16 ( & V_2 -> V_4 ) ;
F_11 ( & V_2 -> V_4 . V_23 , V_22 ) ;
}
static const char * F_50 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
return V_2 -> V_4 . type == V_113 ? L_2 : NULL ;
}
static void F_51 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_52 ( V_2 -> V_4 . V_114 , V_115 ) ;
}
static int F_53 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
return F_54 ( V_2 -> V_4 . V_114 , V_115 ,
L_1 ) != NULL ? 0 : - V_116 ;
}
static void F_55 ( struct V_27 * V_4 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( V_22 & V_117 &&
F_53 ( & V_2 -> V_4 ) == 0 )
V_2 -> V_4 . type = V_113 ;
}
static int
F_56 ( struct V_27 * V_4 , struct V_118 * V_119 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
int V_120 = 0 ;
if ( V_119 -> type != V_121 && V_119 -> type != V_113 )
V_120 = - V_122 ;
if ( V_2 -> V_4 . V_64 != V_119 -> V_64 )
V_120 = - V_122 ;
if ( V_119 -> V_123 != V_124 )
V_120 = - V_122 ;
if ( V_2 -> V_4 . V_102 / 16 != V_119 -> V_125 )
V_120 = - V_122 ;
if ( ( void * ) V_2 -> V_4 . V_114 != V_119 -> V_126 )
V_120 = - V_122 ;
if ( V_2 -> V_4 . V_127 != V_119 -> V_4 )
V_120 = - V_122 ;
if ( V_119 -> V_128 != 0 )
V_120 = - V_122 ;
return V_120 ;
}
static void T_3 F_57 ( void )
{
static int V_129 = 1 ;
int V_130 ;
if ( ! V_129 )
return;
V_129 = 0 ;
for ( V_130 = 0 ; V_130 < V_131 ; V_130 ++ ) {
F_58 ( & V_132 [ V_130 ] . V_24 ) ;
V_132 [ V_130 ] . V_24 . V_133 = F_9 ;
V_132 [ V_130 ] . V_24 . V_21 = ( unsigned long ) & V_132 [ V_130 ] ;
V_132 [ V_130 ] . V_4 . V_9 = & V_134 ;
}
}
static void F_59 ( struct V_27 * V_4 , int V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
int V_7 ;
do {
V_7 = F_1 ( V_2 , V_35 ) ;
} while ( V_7 & V_59 );
F_3 ( V_2 , V_35 , V_33 ) ;
}
static void
F_60 ( struct V_135 * V_136 , const char * V_137 , unsigned int V_138 )
{
struct V_1 * V_2 = & V_132 [ V_136 -> V_139 ] ;
unsigned int V_87 , V_7 ;
V_87 = F_1 ( V_2 , V_29 ) ;
F_3 ( V_2 , V_29 , V_87 & ~ ( V_30 |
V_32 ) ) ;
F_61 ( & V_2 -> V_4 , V_137 , V_138 , F_59 ) ;
do {
V_7 = F_1 ( V_2 , V_35 ) ;
} while ( V_7 & V_59 );
F_3 ( V_2 , V_31 , V_68 |
V_103 ) ;
F_3 ( V_2 , V_29 , V_87 ) ;
}
static int T_3
F_62 ( struct V_135 * V_136 , char * V_140 )
{
struct V_1 * V_2 ;
int V_88 = 38400 ;
int V_141 = 8 ;
int V_46 = 'n' ;
int V_142 = 'n' ;
if ( V_136 -> V_139 == - 1 || V_136 -> V_139 >= V_131 )
V_136 -> V_139 = 0 ;
V_2 = & V_132 [ V_136 -> V_139 ] ;
if ( V_140 )
F_63 ( V_140 , & V_88 , & V_46 , & V_141 , & V_142 ) ;
return F_64 ( & V_2 -> V_4 , V_136 , V_88 , V_46 , V_141 , V_142 ) ;
}
static int T_3 F_65 ( void )
{
F_57 () ;
F_66 ( & V_143 ) ;
return 0 ;
}
static int F_67 ( struct V_144 * V_145 , T_4 V_19 )
{
struct V_1 * V_2 = F_68 ( V_145 ) ;
return F_69 ( & V_146 , & V_2 -> V_4 ) ;
}
static int F_70 ( struct V_144 * V_145 )
{
struct V_1 * V_2 = F_68 ( V_145 ) ;
return F_71 ( & V_146 , & V_2 -> V_4 ) ;
}
static int F_72 ( struct V_144 * V_145 )
{
struct V_147 * V_148 = V_145 -> V_147 ;
int V_130 ;
for ( V_130 = 0 ; V_130 < V_145 -> V_149 ; V_130 ++ , V_148 ++ ) {
if ( ! ( V_148 -> V_22 & V_150 ) )
continue;
for ( V_130 = 0 ; V_130 < V_131 ; V_130 ++ ) {
if ( V_132 [ V_130 ] . V_4 . V_114 != V_148 -> V_151 )
continue;
V_132 [ V_130 ] . V_4 . V_152 = & V_145 -> V_152 ;
F_73 ( & V_146 , & V_132 [ V_130 ] . V_4 ) ;
F_74 ( V_145 , & V_132 [ V_130 ] ) ;
break;
}
}
return 0 ;
}
static int F_75 ( struct V_144 * V_145 )
{
struct V_1 * V_2 = F_68 ( V_145 ) ;
if ( V_2 )
F_76 ( & V_146 , & V_2 -> V_4 ) ;
return 0 ;
}
static int T_3 F_77 ( void )
{
int V_120 ;
F_78 ( V_153 L_3 ) ;
F_57 () ;
V_120 = F_79 ( & V_146 ) ;
if ( V_120 == 0 ) {
V_120 = F_80 ( & V_154 ) ;
if ( V_120 )
F_81 ( & V_146 ) ;
}
return V_120 ;
}
static void T_5 F_82 ( void )
{
F_83 ( & V_154 ) ;
F_81 ( & V_146 ) ;
}
