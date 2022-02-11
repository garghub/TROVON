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
struct V_33 * V_34 = V_2 -> V_4 . V_19 -> V_4 . V_34 ;
unsigned int V_7 , V_35 , V_36 ;
V_7 = F_18 ( F_1 ( V_2 , V_37 ) ) |
F_19 ( F_1 ( V_2 , V_38 ) ) ;
while ( V_7 & F_18 ( V_39 ) ) {
V_35 = F_1 ( V_2 , V_37 ) & 0xff ;
V_2 -> V_4 . V_13 . V_40 ++ ;
V_36 = V_41 ;
if ( V_7 & ( F_18 ( V_42 |
V_43 |
V_44 ) |
F_19 ( V_45 ) ) ) {
if ( V_7 & F_18 ( V_44 ) ) {
V_7 &= ~ ( F_18 ( V_42 ) |
F_18 ( V_43 ) ) ;
V_2 -> V_4 . V_13 . V_46 ++ ;
if ( F_20 ( & V_2 -> V_4 ) )
goto V_47;
} else if ( V_7 & F_18 ( V_43 ) )
V_2 -> V_4 . V_13 . V_48 ++ ;
else if ( V_7 & F_18 ( V_42 ) )
V_2 -> V_4 . V_13 . V_49 ++ ;
if ( V_7 & F_19 ( V_45 ) )
V_2 -> V_4 . V_13 . V_50 ++ ;
V_7 &= V_2 -> V_4 . V_51 ;
if ( V_7 & F_18 ( V_43 ) )
V_36 = V_52 ;
else if ( V_7 & F_18 ( V_42 ) )
V_36 = V_53 ;
#ifdef F_21
V_2 -> V_4 . V_54 = 0 ;
#endif
}
if ( F_22 ( & V_2 -> V_4 , V_35 ) )
goto V_47;
F_23 ( & V_2 -> V_4 , V_7 ,
F_19 ( V_45 ) , V_35 , V_36 ) ;
V_47:
F_3 ( V_2 , V_55 , F_1 ( V_2 , V_55 ) |
V_56 ) ;
V_7 = F_18 ( F_1 ( V_2 , V_37 ) ) |
F_19 ( F_1 ( V_2 , V_38 ) ) ;
}
F_24 ( V_34 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = & V_2 -> V_4 . V_19 -> V_58 ;
if ( V_2 -> V_4 . V_59 ) {
F_3 ( V_2 , V_37 , V_2 -> V_4 . V_59 ) ;
V_2 -> V_4 . V_13 . V_60 ++ ;
V_2 -> V_4 . V_59 = 0 ;
return;
}
F_5 ( V_2 ) ;
if ( F_26 ( V_58 ) || F_27 ( & V_2 -> V_4 ) ) {
F_13 ( & V_2 -> V_4 ) ;
return;
}
while ( ( ( F_1 ( V_2 , V_37 ) &
V_61 ) >> 16 ) < 16 ) {
F_3 ( V_2 , V_37 , V_58 -> V_62 [ V_58 -> V_63 ] ) ;
V_58 -> V_63 = ( V_58 -> V_63 + 1 ) & ( V_64 - 1 ) ;
V_2 -> V_4 . V_13 . V_60 ++ ;
if ( F_26 ( V_58 ) )
break;
}
if ( F_28 ( V_58 ) < V_65 )
F_29 ( & V_2 -> V_4 ) ;
if ( F_26 ( V_58 ) )
F_13 ( & V_2 -> V_4 ) ;
}
static T_2 F_30 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
unsigned int V_7 ;
F_31 ( & V_2 -> V_4 . V_23 ) ;
V_7 = F_1 ( V_2 , V_38 ) & F_1 ( V_2 , V_29 ) ;
if ( V_7 & ( V_68 | V_69 ) )
F_17 ( V_2 ) ;
if ( V_7 & V_70 )
F_25 ( V_2 ) ;
F_3 ( V_2 , V_31 , V_7 ) ;
F_32 ( & V_2 -> V_4 . V_23 ) ;
return V_71 ;
}
static unsigned int F_33 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
return F_1 ( V_2 , V_37 ) & V_72 ? 0 : V_73 ;
}
static unsigned int F_34 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned int V_74 = V_15 ;
unsigned int V_75 ;
V_75 = F_1 ( V_2 , V_76 ) ;
V_74 |= V_75 & V_77 ? V_18 : 0 ;
V_74 |= V_75 & V_78 ? V_17 : 0 ;
return V_74 ;
}
static void F_35 ( struct V_27 * V_4 , unsigned int V_74 )
{
#if 0
struct pnx8xxx_port *sport = (struct pnx8xxx_port *)port;
unsigned int msr;
#endif
}
static void F_36 ( struct V_27 * V_4 , int V_79 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_22 ;
unsigned int V_80 ;
F_10 ( & V_2 -> V_4 . V_23 , V_22 ) ;
V_80 = F_1 ( V_2 , V_55 ) ;
if ( V_79 == - 1 )
V_80 |= V_81 ;
else
V_80 &= ~ V_81 ;
F_3 ( V_2 , V_55 , V_80 ) ;
F_11 ( & V_2 -> V_4 . V_23 , V_22 ) ;
}
static int F_37 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
int V_82 ;
V_82 = F_38 ( V_2 -> V_4 . V_66 , F_30 , 0 ,
L_1 , V_2 ) ;
if ( V_82 )
return V_82 ;
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
int V_80 ;
F_42 ( & V_2 -> V_24 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
V_80 = F_1 ( V_2 , V_55 ) ;
V_80 &= ~ V_81 ;
V_80 |= V_83 | V_84 ;
F_3 ( V_2 , V_55 , V_80 ) ;
F_3 ( V_2 , V_31 , V_32 |
V_30 ) ;
F_43 ( V_2 -> V_4 . V_66 , V_2 ) ;
}
static void
F_44 ( struct V_27 * V_4 , struct V_85 * V_86 ,
struct V_85 * V_87 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_22 ;
unsigned int V_88 , V_89 , V_90 , V_91 ;
unsigned int V_92 = V_87 ? V_87 -> V_93 & V_94 : V_95 ;
while ( ( V_86 -> V_93 & V_94 ) != V_96 &&
( V_86 -> V_93 & V_94 ) != V_95 ) {
V_86 -> V_93 &= ~ V_94 ;
V_86 -> V_93 |= V_92 ;
V_92 = V_95 ;
}
if ( ( V_86 -> V_93 & V_94 ) == V_95 )
V_88 = V_97 ;
else
V_88 = 0 ;
if ( V_86 -> V_93 & V_98 )
V_88 |= V_99 ;
if ( V_86 -> V_93 & V_100 ) {
V_88 |= V_101 ;
if ( ! ( V_86 -> V_93 & V_102 ) )
V_88 |= V_103 ;
}
V_90 = F_45 ( V_4 , V_86 , V_87 , 0 , V_4 -> V_104 / 16 ) ;
V_91 = F_46 ( V_4 , V_90 ) ;
F_10 ( & V_2 -> V_4 . V_23 , V_22 ) ;
V_2 -> V_4 . V_51 = F_19 ( V_45 ) |
F_19 ( V_105 ) |
F_19 ( V_68 ) ;
if ( V_86 -> V_106 & V_107 )
V_2 -> V_4 . V_51 |=
F_18 ( V_42 ) |
F_18 ( V_43 ) ;
if ( V_86 -> V_106 & ( V_108 | V_109 ) )
V_2 -> V_4 . V_51 |=
F_19 ( V_69 ) ;
V_2 -> V_4 . V_110 = 0 ;
if ( V_86 -> V_106 & V_111 )
V_2 -> V_4 . V_110 |=
F_18 ( V_42 ) |
F_18 ( V_43 ) ;
if ( V_86 -> V_106 & V_112 ) {
V_2 -> V_4 . V_110 |=
F_19 ( V_69 ) ;
if ( V_86 -> V_106 & V_111 )
V_2 -> V_4 . V_110 |=
F_19 ( V_45 ) ;
}
if ( ( V_86 -> V_93 & V_113 ) == 0 )
V_2 -> V_4 . V_110 |=
F_19 ( V_68 ) ;
F_42 ( & V_2 -> V_24 ) ;
F_47 ( V_4 , V_86 -> V_93 , V_90 ) ;
V_89 = F_1 ( V_2 , V_29 ) ;
F_3 ( V_2 , V_29 , V_89 & ~ ( V_30 |
V_32 ) ) ;
while ( F_1 ( V_2 , V_37 ) & V_72 )
F_48 () ;
F_3 ( V_2 , V_29 , 0 ) ;
V_88 |= V_83 ;
V_88 |= V_84 ;
F_3 ( V_2 , V_55 , V_88 ) ;
V_91 -= 1 ;
F_3 ( V_2 , V_114 , V_91 ) ;
F_3 ( V_2 , V_31 , - 1 ) ;
F_3 ( V_2 , V_29 , V_89 ) ;
if ( F_49 ( & V_2 -> V_4 , V_86 -> V_93 ) )
F_16 ( & V_2 -> V_4 ) ;
F_11 ( & V_2 -> V_4 . V_23 , V_22 ) ;
}
static const char * F_50 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
return V_2 -> V_4 . type == V_115 ? L_2 : NULL ;
}
static void F_51 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_52 ( V_2 -> V_4 . V_116 , V_117 ) ;
}
static int F_53 ( struct V_27 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
return F_54 ( V_2 -> V_4 . V_116 , V_117 ,
L_1 ) != NULL ? 0 : - V_118 ;
}
static void F_55 ( struct V_27 * V_4 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( V_22 & V_119 &&
F_53 ( & V_2 -> V_4 ) == 0 )
V_2 -> V_4 . type = V_115 ;
}
static int
F_56 ( struct V_27 * V_4 , struct V_120 * V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
int V_122 = 0 ;
if ( V_121 -> type != V_123 && V_121 -> type != V_115 )
V_122 = - V_124 ;
if ( V_2 -> V_4 . V_66 != V_121 -> V_66 )
V_122 = - V_124 ;
if ( V_121 -> V_125 != V_126 )
V_122 = - V_124 ;
if ( V_2 -> V_4 . V_104 / 16 != V_121 -> V_127 )
V_122 = - V_124 ;
if ( ( void * ) V_2 -> V_4 . V_116 != V_121 -> V_128 )
V_122 = - V_124 ;
if ( V_2 -> V_4 . V_129 != V_121 -> V_4 )
V_122 = - V_124 ;
if ( V_121 -> V_130 != 0 )
V_122 = - V_124 ;
return V_122 ;
}
static void T_3 F_57 ( void )
{
static int V_131 = 1 ;
int V_132 ;
if ( ! V_131 )
return;
V_131 = 0 ;
for ( V_132 = 0 ; V_132 < V_133 ; V_132 ++ ) {
F_58 ( & V_134 [ V_132 ] . V_24 ) ;
V_134 [ V_132 ] . V_24 . V_135 = F_9 ;
V_134 [ V_132 ] . V_24 . V_21 = ( unsigned long ) & V_134 [ V_132 ] ;
V_134 [ V_132 ] . V_4 . V_9 = & V_136 ;
}
}
static void F_59 ( struct V_27 * V_4 , int V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
int V_7 ;
do {
V_7 = F_1 ( V_2 , V_37 ) ;
} while ( V_7 & V_61 );
F_3 ( V_2 , V_37 , V_35 ) ;
}
static void
F_60 ( struct V_137 * V_138 , const char * V_139 , unsigned int V_140 )
{
struct V_1 * V_2 = & V_134 [ V_138 -> V_141 ] ;
unsigned int V_89 , V_7 ;
V_89 = F_1 ( V_2 , V_29 ) ;
F_3 ( V_2 , V_29 , V_89 & ~ ( V_30 |
V_32 ) ) ;
F_61 ( & V_2 -> V_4 , V_139 , V_140 , F_59 ) ;
do {
V_7 = F_1 ( V_2 , V_37 ) ;
} while ( V_7 & V_61 );
F_3 ( V_2 , V_31 , V_70 |
V_105 ) ;
F_3 ( V_2 , V_29 , V_89 ) ;
}
static int T_3
F_62 ( struct V_137 * V_138 , char * V_142 )
{
struct V_1 * V_2 ;
int V_90 = 38400 ;
int V_143 = 8 ;
int V_48 = 'n' ;
int V_144 = 'n' ;
if ( V_138 -> V_141 == - 1 || V_138 -> V_141 >= V_133 )
V_138 -> V_141 = 0 ;
V_2 = & V_134 [ V_138 -> V_141 ] ;
if ( V_142 )
F_63 ( V_142 , & V_90 , & V_48 , & V_143 , & V_144 ) ;
return F_64 ( & V_2 -> V_4 , V_138 , V_90 , V_48 , V_143 , V_144 ) ;
}
static int T_3 F_65 ( void )
{
F_57 () ;
F_66 ( & V_145 ) ;
return 0 ;
}
static int F_67 ( struct V_146 * V_147 , T_4 V_19 )
{
struct V_1 * V_2 = F_68 ( V_147 ) ;
return F_69 ( & V_148 , & V_2 -> V_4 ) ;
}
static int F_70 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = F_68 ( V_147 ) ;
return F_71 ( & V_148 , & V_2 -> V_4 ) ;
}
static int F_72 ( struct V_146 * V_147 )
{
struct V_149 * V_150 = V_147 -> V_149 ;
int V_132 ;
for ( V_132 = 0 ; V_132 < V_147 -> V_151 ; V_132 ++ , V_150 ++ ) {
if ( ! ( V_150 -> V_22 & V_152 ) )
continue;
for ( V_132 = 0 ; V_132 < V_133 ; V_132 ++ ) {
if ( V_134 [ V_132 ] . V_4 . V_116 != V_150 -> V_153 )
continue;
V_134 [ V_132 ] . V_4 . V_154 = & V_147 -> V_154 ;
F_73 ( & V_148 , & V_134 [ V_132 ] . V_4 ) ;
F_74 ( V_147 , & V_134 [ V_132 ] ) ;
break;
}
}
return 0 ;
}
static int F_75 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = F_68 ( V_147 ) ;
F_74 ( V_147 , NULL ) ;
if ( V_2 )
F_76 ( & V_148 , & V_2 -> V_4 ) ;
return 0 ;
}
static int T_3 F_77 ( void )
{
int V_122 ;
F_78 ( V_155 L_3 ) ;
F_57 () ;
V_122 = F_79 ( & V_148 ) ;
if ( V_122 == 0 ) {
V_122 = F_80 ( & V_156 ) ;
if ( V_122 )
F_81 ( & V_148 ) ;
}
return V_122 ;
}
static void T_5 F_82 ( void )
{
F_83 ( & V_156 ) ;
F_81 ( & V_148 ) ;
}
