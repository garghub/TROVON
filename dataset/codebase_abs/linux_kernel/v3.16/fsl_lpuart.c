static void F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 &= ~ ( V_6 | V_7 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 & ~ V_8 , V_2 -> V_4 + V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
}
static void F_6 ( struct V_9 * V_10 ,
struct V_11 * V_12 , int V_13 )
{
int V_14 ;
V_10 -> V_2 . V_15 . V_16 += V_13 ;
if ( ! V_12 ) {
F_7 ( V_10 -> V_2 . V_17 , L_1 ) ;
return;
}
F_8 ( V_10 -> V_2 . V_17 , V_10 -> V_18 ,
V_19 , V_20 ) ;
V_14 = F_9 ( V_12 ,
( ( unsigned char * ) ( V_10 -> V_21 ) ) , V_13 ) ;
if ( V_14 != V_13 ) {
F_10 ( 1 ) ;
F_7 ( V_10 -> V_2 . V_17 , L_2 ) ;
}
F_11 ( V_10 -> V_2 . V_17 , V_10 -> V_18 ,
V_19 , V_22 ) ;
}
static void F_12 ( struct V_9 * V_10 )
{
struct V_23 * V_24 = & V_10 -> V_2 . V_25 -> V_24 ;
unsigned long V_26 ;
F_13 ( & V_10 -> V_2 . V_27 , V_26 ) ;
while ( ! F_14 ( V_24 ) &&
F_2 ( V_10 -> V_2 . V_4 + V_28 ) < V_10 -> V_29 ) {
F_3 ( V_24 -> V_30 [ V_24 -> V_31 ] , V_10 -> V_2 . V_4 + V_32 ) ;
V_24 -> V_31 = ( V_24 -> V_31 + 1 ) & ( V_33 - 1 ) ;
V_10 -> V_2 . V_15 . V_34 ++ ;
}
if ( F_15 ( V_24 ) < V_35 )
F_16 ( & V_10 -> V_2 ) ;
if ( F_14 ( V_24 ) )
F_3 ( F_2 ( V_10 -> V_2 . V_4 + V_36 ) | V_37 ,
V_10 -> V_2 . V_4 + V_36 ) ;
F_17 ( & V_10 -> V_2 . V_27 , V_26 ) ;
}
static int F_18 ( struct V_9 * V_10 , unsigned long V_13 )
{
struct V_23 * V_24 = & V_10 -> V_2 . V_25 -> V_24 ;
T_1 V_38 ;
F_11 ( V_10 -> V_2 . V_17 , V_10 -> V_39 ,
V_33 , V_22 ) ;
V_10 -> V_40 = V_13 & ~ ( V_41 ) ;
V_38 = V_10 -> V_39 + V_24 -> V_31 ;
V_10 -> V_42 = F_19 ( V_10 -> V_43 ,
V_38 , V_10 -> V_40 ,
V_44 , V_45 ) ;
if ( ! V_10 -> V_42 ) {
F_7 ( V_10 -> V_2 . V_17 , L_3 ) ;
return - V_46 ;
}
V_10 -> V_42 -> V_47 = V_48 ;
V_10 -> V_42 -> V_49 = V_10 ;
V_10 -> V_50 = 1 ;
V_10 -> V_51 = F_20 ( V_10 -> V_42 ) ;
F_21 ( V_10 -> V_43 ) ;
return 0 ;
}
static void F_22 ( struct V_9 * V_10 )
{
struct V_23 * V_24 = & V_10 -> V_2 . V_25 -> V_24 ;
unsigned long V_13 = F_23 ( V_24 -> V_52 ,
V_24 -> V_31 , V_33 ) ;
if ( ! V_13 )
return;
if ( V_13 < V_53 )
F_3 ( F_2 ( V_10 -> V_2 . V_4 + V_36 ) & ~ V_37 ,
V_10 -> V_2 . V_4 + V_36 ) ;
else {
F_3 ( F_2 ( V_10 -> V_2 . V_4 + V_36 ) | V_37 ,
V_10 -> V_2 . V_4 + V_36 ) ;
F_18 ( V_10 , V_13 ) ;
}
}
static void V_48 ( void * V_54 )
{
struct V_9 * V_10 = V_54 ;
struct V_23 * V_24 = & V_10 -> V_2 . V_25 -> V_24 ;
unsigned long V_26 ;
F_24 ( V_10 -> V_42 ) ;
F_13 ( & V_10 -> V_2 . V_27 , V_26 ) ;
V_24 -> V_31 = ( V_24 -> V_31 + V_10 -> V_40 ) & ( V_33 - 1 ) ;
V_10 -> V_50 = 0 ;
if ( F_15 ( V_24 ) < V_35 )
F_16 ( & V_10 -> V_2 ) ;
F_22 ( V_10 ) ;
F_17 ( & V_10 -> V_2 . V_27 , V_26 ) ;
}
static int F_25 ( struct V_9 * V_10 )
{
F_11 ( V_10 -> V_2 . V_17 , V_10 -> V_18 ,
V_19 , V_22 ) ;
V_10 -> V_55 = F_19 ( V_10 -> V_56 ,
V_10 -> V_18 , V_19 ,
V_57 , V_45 ) ;
if ( ! V_10 -> V_55 ) {
F_7 ( V_10 -> V_2 . V_17 , L_4 ) ;
return - V_46 ;
}
V_10 -> V_55 -> V_47 = V_58 ;
V_10 -> V_55 -> V_49 = V_10 ;
V_10 -> V_59 = 1 ;
V_10 -> V_60 = F_20 ( V_10 -> V_55 ) ;
F_21 ( V_10 -> V_56 ) ;
return 0 ;
}
static void V_58 ( void * V_54 )
{
struct V_9 * V_10 = V_54 ;
struct V_11 * V_2 = & V_10 -> V_2 . V_25 -> V_2 ;
unsigned long V_26 ;
F_24 ( V_10 -> V_55 ) ;
F_13 ( & V_10 -> V_2 . V_27 , V_26 ) ;
V_10 -> V_59 = 0 ;
F_6 ( V_10 , V_2 , V_19 ) ;
F_26 ( V_2 ) ;
F_25 ( V_10 ) ;
F_17 ( & V_10 -> V_2 . V_27 , V_26 ) ;
}
static void F_27 ( unsigned long V_61 )
{
struct V_9 * V_10 = (struct V_9 * ) V_61 ;
struct V_11 * V_2 = & V_10 -> V_2 . V_25 -> V_2 ;
struct V_62 V_25 ;
unsigned long V_26 ;
unsigned char V_3 ;
int V_13 ;
F_28 ( & V_10 -> V_63 ) ;
F_29 ( V_10 -> V_56 ) ;
F_30 ( V_10 -> V_56 , V_10 -> V_60 , & V_25 ) ;
F_31 ( V_10 -> V_56 ) ;
V_13 = V_19 - V_25 . V_64 ;
F_24 ( V_10 -> V_55 ) ;
F_13 ( & V_10 -> V_2 . V_27 , V_26 ) ;
V_10 -> V_59 = 0 ;
F_6 ( V_10 , V_2 , V_13 ) ;
F_26 ( V_2 ) ;
V_3 = F_2 ( V_10 -> V_2 . V_4 + V_36 ) ;
F_3 ( V_3 & ~ V_65 , V_10 -> V_2 . V_4 + V_36 ) ;
F_17 ( & V_10 -> V_2 . V_27 , V_26 ) ;
}
static inline void F_32 ( struct V_9 * V_10 )
{
unsigned long V_26 ;
unsigned char V_3 ;
F_13 ( & V_10 -> V_2 . V_27 , V_26 ) ;
F_33 ( & V_10 -> V_63 ) ;
V_10 -> V_63 . V_66 = F_27 ;
V_10 -> V_63 . V_61 = ( unsigned long ) V_10 ;
V_10 -> V_63 . V_67 = V_68 + V_10 -> V_69 ;
F_34 ( & V_10 -> V_63 ) ;
F_25 ( V_10 ) ;
V_3 = F_2 ( V_10 -> V_2 . V_4 + V_36 ) ;
F_3 ( V_3 | V_65 , V_10 -> V_2 . V_4 + V_36 ) ;
F_17 ( & V_10 -> V_2 . V_27 , V_26 ) ;
}
static inline void F_35 ( struct V_9 * V_10 )
{
struct V_23 * V_24 = & V_10 -> V_2 . V_25 -> V_24 ;
while ( ! F_14 ( V_24 ) &&
( F_2 ( V_10 -> V_2 . V_4 + V_28 ) < V_10 -> V_29 ) ) {
F_3 ( V_24 -> V_30 [ V_24 -> V_31 ] , V_10 -> V_2 . V_4 + V_32 ) ;
V_24 -> V_31 = ( V_24 -> V_31 + 1 ) & ( V_33 - 1 ) ;
V_10 -> V_2 . V_15 . V_34 ++ ;
}
if ( F_15 ( V_24 ) < V_35 )
F_16 ( & V_10 -> V_2 ) ;
if ( F_14 ( V_24 ) )
F_1 ( & V_10 -> V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_37 ( V_2 ,
struct V_9 , V_2 ) ;
struct V_23 * V_24 = & V_10 -> V_2 . V_25 -> V_24 ;
unsigned char V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 | V_6 , V_2 -> V_4 + V_5 ) ;
if ( V_10 -> V_70 ) {
if ( ! F_14 ( V_24 ) && ! V_10 -> V_50 )
F_22 ( V_10 ) ;
} else {
if ( F_2 ( V_2 -> V_4 + V_71 ) & V_72 )
F_35 ( V_10 ) ;
}
}
static T_2 F_38 ( int V_73 , void * V_74 )
{
struct V_9 * V_10 = V_74 ;
struct V_23 * V_24 = & V_10 -> V_2 . V_25 -> V_24 ;
unsigned long V_26 ;
F_13 ( & V_10 -> V_2 . V_27 , V_26 ) ;
if ( V_10 -> V_2 . V_75 ) {
F_3 ( V_10 -> V_2 . V_75 , V_10 -> V_2 . V_4 + V_32 ) ;
goto V_76;
}
if ( F_14 ( V_24 ) || F_39 ( & V_10 -> V_2 ) ) {
F_1 ( & V_10 -> V_2 ) ;
goto V_76;
}
F_35 ( V_10 ) ;
if ( F_15 ( V_24 ) < V_35 )
F_16 ( & V_10 -> V_2 ) ;
V_76:
F_17 ( & V_10 -> V_2 . V_27 , V_26 ) ;
return V_77 ;
}
static T_2 F_40 ( int V_73 , void * V_74 )
{
struct V_9 * V_10 = V_74 ;
unsigned int V_78 , V_79 = 0 ;
struct V_11 * V_2 = & V_10 -> V_2 . V_25 -> V_2 ;
unsigned long V_26 ;
unsigned char V_16 , V_80 ;
F_13 ( & V_10 -> V_2 . V_27 , V_26 ) ;
while ( ! ( F_2 ( V_10 -> V_2 . V_4 + V_81 ) & V_82 ) ) {
V_78 = V_83 ;
V_10 -> V_2 . V_15 . V_16 ++ ;
V_80 = F_2 ( V_10 -> V_2 . V_4 + V_71 ) ;
V_16 = F_2 ( V_10 -> V_2 . V_4 + V_32 ) ;
if ( F_41 ( & V_10 -> V_2 , ( unsigned char ) V_16 ) )
continue;
if ( V_80 & ( V_84 | V_85 | V_86 ) ) {
if ( V_80 & V_84 )
V_10 -> V_2 . V_15 . V_87 ++ ;
else if ( V_80 & V_86 )
V_10 -> V_2 . V_15 . V_88 ++ ;
if ( V_80 & V_85 )
V_10 -> V_2 . V_15 . V_89 ++ ;
if ( V_80 & V_10 -> V_2 . V_90 ) {
if ( ++ V_79 > 100 )
goto V_76;
continue;
}
V_80 &= V_10 -> V_2 . V_91 ;
if ( V_80 & V_84 )
V_78 = V_92 ;
else if ( V_80 & V_86 )
V_78 = V_93 ;
if ( V_80 & V_85 )
V_78 = V_94 ;
#ifdef F_42
V_10 -> V_2 . V_95 = 0 ;
#endif
}
F_43 ( V_2 , V_16 , V_78 ) ;
}
V_76:
F_17 ( & V_10 -> V_2 . V_27 , V_26 ) ;
F_26 ( V_2 ) ;
return V_77 ;
}
static T_2 F_44 ( int V_73 , void * V_74 )
{
struct V_9 * V_10 = V_74 ;
unsigned char V_96 ;
V_96 = F_2 ( V_10 -> V_2 . V_4 + V_71 ) ;
if ( V_96 & V_97 ) {
if ( V_10 -> V_70 )
F_32 ( V_10 ) ;
else
F_40 ( V_73 , V_74 ) ;
}
if ( V_96 & V_72 &&
! ( F_2 ( V_10 -> V_2 . V_4 + V_36 ) & V_37 ) ) {
if ( V_10 -> V_70 )
F_12 ( V_10 ) ;
else
F_38 ( V_73 , V_74 ) ;
}
return V_77 ;
}
static unsigned int F_45 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_4 + V_71 ) & V_98 ) ?
V_99 : 0 ;
}
static unsigned int F_46 ( struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
unsigned char V_100 ;
V_100 = F_2 ( V_2 -> V_4 + V_101 ) ;
if ( V_100 & V_102 )
V_3 |= V_103 ;
if ( V_100 & V_104 )
V_3 |= V_105 ;
return V_3 ;
}
static void F_47 ( struct V_1 * V_2 , unsigned int V_106 )
{
unsigned char V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_101 ) &
~ ( V_104 | V_102 ) ;
if ( V_106 & V_105 )
V_3 |= V_104 ;
if ( V_106 & V_103 )
V_3 |= V_102 ;
F_3 ( V_3 , V_2 -> V_4 + V_101 ) ;
}
static void F_48 ( struct V_1 * V_2 , int V_107 )
{
unsigned char V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) & ~ V_108 ;
if ( V_107 != 0 )
V_3 |= V_108 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_49 ( struct V_9 * V_10 )
{
unsigned char V_109 , V_110 ;
unsigned char V_111 ;
V_110 = F_2 ( V_10 -> V_2 . V_4 + V_5 ) ;
V_111 = V_110 ;
V_110 &= ~ ( V_6 | V_7 | V_112 |
V_113 | V_8 ) ;
F_3 ( V_110 , V_10 -> V_2 . V_4 + V_5 ) ;
V_109 = F_2 ( V_10 -> V_2 . V_4 + V_114 ) ;
V_10 -> V_29 = 0x1 << ( ( ( V_109 >> V_115 ) &
V_116 ) + 1 ) ;
V_10 -> V_117 = 0x1 << ( ( ( V_109 >> V_118 ) &
V_116 ) + 1 ) ;
F_3 ( V_109 | V_119 | V_120 ,
V_10 -> V_2 . V_4 + V_114 ) ;
F_3 ( V_121 | V_122 ,
V_10 -> V_2 . V_4 + V_123 ) ;
F_3 ( 0 , V_10 -> V_2 . V_4 + V_124 ) ;
F_3 ( 1 , V_10 -> V_2 . V_4 + V_125 ) ;
F_3 ( V_111 , V_10 -> V_2 . V_4 + V_5 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_37 ( V_2 ,
struct V_9 , V_2 ) ;
struct V_126 * V_127 ;
struct V_128 V_129 ;
T_1 V_130 ;
unsigned char * V_131 ;
int V_132 ;
V_127 = F_51 ( V_10 -> V_2 . V_17 , L_5 ) ;
if ( ! V_127 ) {
F_7 ( V_10 -> V_2 . V_17 , L_6 ) ;
return - V_133 ;
}
V_130 = F_52 ( V_127 -> V_134 -> V_17 ,
V_10 -> V_2 . V_25 -> V_24 . V_30 ,
V_33 , V_22 ) ;
if ( F_53 ( V_127 -> V_134 -> V_17 , V_130 ) ) {
F_7 ( V_10 -> V_2 . V_17 , L_7 ) ;
F_54 ( V_127 ) ;
return - V_135 ;
}
V_131 = V_10 -> V_2 . V_25 -> V_24 . V_30 ;
V_129 . V_136 = V_10 -> V_2 . V_137 + V_32 ;
V_129 . V_138 = V_139 ;
V_129 . V_140 = V_53 ;
V_129 . V_141 = V_44 ;
V_132 = F_55 ( V_127 , & V_129 ) ;
if ( V_132 < 0 ) {
F_7 ( V_10 -> V_2 . V_17 ,
L_8 , V_132 ) ;
F_54 ( V_127 ) ;
return V_132 ;
}
V_10 -> V_43 = V_127 ;
V_10 -> V_142 = V_131 ;
V_10 -> V_39 = V_130 ;
V_10 -> V_50 = 0 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_37 ( V_2 ,
struct V_9 , V_2 ) ;
struct V_126 * V_143 ;
struct V_128 V_144 ;
T_1 V_130 ;
unsigned char * V_131 ;
int V_132 ;
V_143 = F_51 ( V_10 -> V_2 . V_17 , L_9 ) ;
if ( ! V_143 ) {
F_7 ( V_10 -> V_2 . V_17 , L_10 ) ;
return - V_133 ;
}
V_131 = F_57 ( V_10 -> V_2 . V_17 ,
V_19 , V_145 ) ;
if ( ! V_131 ) {
F_7 ( V_10 -> V_2 . V_17 , L_11 ) ;
F_54 ( V_143 ) ;
return - V_135 ;
}
V_130 = F_52 ( V_143 -> V_134 -> V_17 , V_131 ,
V_19 , V_20 ) ;
if ( F_53 ( V_143 -> V_134 -> V_17 , V_130 ) ) {
F_7 ( V_10 -> V_2 . V_17 , L_12 ) ;
F_54 ( V_143 ) ;
return - V_135 ;
}
V_144 . V_146 = V_10 -> V_2 . V_137 + V_32 ;
V_144 . V_147 = V_139 ;
V_144 . V_148 = 1 ;
V_144 . V_141 = V_57 ;
V_132 = F_55 ( V_143 , & V_144 ) ;
if ( V_132 < 0 ) {
F_7 ( V_10 -> V_2 . V_17 ,
L_8 , V_132 ) ;
F_54 ( V_143 ) ;
return V_132 ;
}
V_10 -> V_56 = V_143 ;
V_10 -> V_21 = V_131 ;
V_10 -> V_18 = V_130 ;
V_10 -> V_59 = 0 ;
V_10 -> V_69 = ( V_10 -> V_2 . V_149 - V_150 / 50 ) *
V_19 * 3 /
V_10 -> V_117 / 2 ;
if ( V_10 -> V_69 < F_58 ( 20 ) )
V_10 -> V_69 = F_58 ( 20 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_37 ( V_2 ,
struct V_9 , V_2 ) ;
struct V_126 * V_126 ;
F_60 ( V_10 -> V_2 . V_17 , V_10 -> V_39 ,
V_33 , V_22 ) ;
V_126 = V_10 -> V_43 ;
V_10 -> V_43 = NULL ;
V_10 -> V_39 = 0 ;
V_10 -> V_142 = NULL ;
F_54 ( V_126 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_37 ( V_2 ,
struct V_9 , V_2 ) ;
struct V_126 * V_126 ;
F_60 ( V_10 -> V_2 . V_17 , V_10 -> V_18 ,
V_19 , V_20 ) ;
V_126 = V_10 -> V_56 ;
V_10 -> V_56 = NULL ;
V_10 -> V_18 = 0 ;
V_10 -> V_21 = NULL ;
F_54 ( V_126 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_37 ( V_2 , struct V_9 , V_2 ) ;
int V_132 ;
unsigned long V_26 ;
unsigned char V_3 ;
if ( F_50 ( V_2 ) || F_56 ( V_2 ) ) {
V_10 -> V_70 = false ;
} else {
V_10 -> V_70 = true ;
V_3 = F_2 ( V_2 -> V_4 + V_36 ) ;
F_3 ( V_3 | V_37 , V_2 -> V_4 + V_36 ) ;
}
V_132 = F_63 ( V_2 -> V_17 , V_2 -> V_73 , F_44 , 0 ,
V_151 , V_10 ) ;
if ( V_132 )
return V_132 ;
F_13 ( & V_10 -> V_2 . V_27 , V_26 ) ;
F_49 ( V_10 ) ;
V_3 = F_2 ( V_10 -> V_2 . V_4 + V_5 ) ;
V_3 |= ( V_113 | V_6 | V_8 | V_112 ) ;
F_3 ( V_3 , V_10 -> V_2 . V_4 + V_5 ) ;
F_17 ( & V_10 -> V_2 . V_27 , V_26 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_37 ( V_2 , struct V_9 , V_2 ) ;
unsigned char V_3 ;
unsigned long V_26 ;
F_13 ( & V_2 -> V_27 , V_26 ) ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 &= ~ ( V_112 | V_8 |
V_6 | V_7 | V_113 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_17 ( & V_2 -> V_27 , V_26 ) ;
F_65 ( V_2 -> V_17 , V_2 -> V_73 , V_10 ) ;
if ( V_10 -> V_70 ) {
F_59 ( V_2 ) ;
F_61 ( V_2 ) ;
}
}
static void
F_66 ( struct V_1 * V_2 , struct V_152 * V_153 ,
struct V_152 * V_154 )
{
struct V_9 * V_10 = F_37 ( V_2 , struct V_9 , V_2 ) ;
unsigned long V_26 ;
unsigned char V_155 , V_156 , V_157 , V_158 , V_159 , V_160 ;
unsigned int V_161 ;
unsigned int V_162 = V_154 ? V_154 -> V_163 & V_164 : V_165 ;
unsigned int V_166 , V_167 ;
V_155 = V_156 = F_2 ( V_10 -> V_2 . V_4 + V_168 ) ;
V_157 = F_2 ( V_10 -> V_2 . V_4 + V_5 ) ;
V_158 = F_2 ( V_10 -> V_2 . V_4 + V_169 ) ;
V_159 = F_2 ( V_10 -> V_2 . V_4 + V_170 ) ;
V_160 = F_2 ( V_10 -> V_2 . V_4 + V_101 ) ;
while ( ( V_153 -> V_163 & V_164 ) != V_165 &&
( V_153 -> V_163 & V_164 ) != V_171 ) {
V_153 -> V_163 &= ~ V_164 ;
V_153 -> V_163 |= V_162 ;
V_162 = V_165 ;
}
if ( ( V_153 -> V_163 & V_164 ) == V_165 ||
( V_153 -> V_163 & V_164 ) == V_171 )
V_155 = V_156 & ~ V_172 ;
if ( V_153 -> V_163 & V_173 ) {
if ( ( V_153 -> V_163 & V_164 ) != V_165 ) {
V_153 -> V_163 &= ~ V_164 ;
V_153 -> V_163 |= V_165 ;
}
V_155 |= V_172 ;
}
if ( V_153 -> V_163 & V_174 ) {
V_160 |= ( V_104 | V_102 ) ;
} else {
V_153 -> V_163 &= ~ V_174 ;
V_160 &= ~ ( V_104 | V_102 ) ;
}
if ( V_153 -> V_163 & V_175 )
V_153 -> V_163 &= ~ V_175 ;
if ( ( V_153 -> V_163 & V_164 ) == V_171 )
V_153 -> V_163 |= V_176 ;
if ( ( V_153 -> V_163 & V_176 ) ) {
if ( V_153 -> V_163 & V_173 ) {
V_155 &= ~ V_177 ;
V_155 |= V_172 ;
} else {
V_155 |= V_177 ;
if ( ( V_153 -> V_163 & V_164 ) == V_165 )
V_155 |= V_172 ;
if ( V_153 -> V_163 & V_178 )
V_155 |= V_179 ;
else
V_155 &= ~ V_179 ;
}
}
V_161 = F_67 ( V_2 , V_153 , V_154 , 50 , V_2 -> V_180 / 16 ) ;
F_13 ( & V_10 -> V_2 . V_27 , V_26 ) ;
V_10 -> V_2 . V_91 = 0 ;
if ( V_153 -> V_181 & V_182 )
V_10 -> V_2 . V_91 |= ( V_86 | V_84 ) ;
if ( V_153 -> V_181 & ( V_183 | V_184 | V_185 ) )
V_10 -> V_2 . V_91 |= V_86 ;
V_10 -> V_2 . V_90 = 0 ;
if ( V_153 -> V_181 & V_186 )
V_10 -> V_2 . V_90 |= V_84 ;
if ( V_153 -> V_181 & V_183 ) {
V_10 -> V_2 . V_90 |= V_86 ;
if ( V_153 -> V_181 & V_186 )
V_10 -> V_2 . V_90 |= V_85 ;
}
F_68 ( V_2 , V_153 -> V_163 , V_161 ) ;
while ( ! ( F_2 ( V_10 -> V_2 . V_4 + V_71 ) & V_98 ) )
F_69 () ;
F_3 ( V_157 & ~ ( V_112 | V_8 ) ,
V_10 -> V_2 . V_4 + V_5 ) ;
V_166 = V_10 -> V_2 . V_180 / ( 16 * V_161 ) ;
V_167 = ( ( V_10 -> V_2 . V_180 - ( 16 * V_166 * V_161 ) ) * 2 ) / V_161 ;
V_159 &= ~ V_187 ;
V_159 |= ( V_166 >> 8 ) & 0x1F ;
V_158 &= ~ V_188 ;
V_167 &= V_188 ;
F_3 ( V_158 | V_167 , V_10 -> V_2 . V_4 + V_169 ) ;
F_3 ( V_159 , V_10 -> V_2 . V_4 + V_170 ) ;
F_3 ( V_166 & 0xFF , V_10 -> V_2 . V_4 + V_189 ) ;
F_3 ( V_155 , V_10 -> V_2 . V_4 + V_168 ) ;
F_3 ( V_160 , V_10 -> V_2 . V_4 + V_101 ) ;
F_3 ( V_157 , V_10 -> V_2 . V_4 + V_5 ) ;
F_17 ( & V_10 -> V_2 . V_27 , V_26 ) ;
}
static const char * F_70 ( struct V_1 * V_2 )
{
return L_13 ;
}
static void F_71 ( struct V_1 * V_2 )
{
}
static int F_72 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_73 ( struct V_1 * V_2 , int V_26 )
{
if ( V_26 & V_190 )
V_2 -> type = V_191 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_192 * V_193 )
{
int V_132 = 0 ;
if ( V_193 -> type != V_194 && V_193 -> type != V_191 )
V_132 = - V_195 ;
if ( V_2 -> V_73 != V_193 -> V_73 )
V_132 = - V_195 ;
if ( V_193 -> V_196 != V_197 )
V_132 = - V_195 ;
if ( V_2 -> V_180 / 16 != V_193 -> V_198 )
V_132 = - V_195 ;
if ( V_2 -> V_199 != V_193 -> V_2 )
V_132 = - V_195 ;
if ( V_193 -> V_200 != 0 )
V_132 = - V_195 ;
return V_132 ;
}
static void F_75 ( struct V_1 * V_2 , int V_201 )
{
while ( ! ( F_2 ( V_2 -> V_4 + V_71 ) & V_72 ) )
F_69 () ;
F_3 ( V_201 , V_2 -> V_4 + V_32 ) ;
}
static void
F_76 ( struct V_202 * V_203 , const char * V_204 , unsigned int V_13 )
{
struct V_9 * V_10 = V_205 [ V_203 -> V_206 ] ;
unsigned char V_157 , V_110 ;
V_110 = V_157 = F_2 ( V_10 -> V_2 . V_4 + V_5 ) ;
V_110 |= ( V_112 | V_8 ) ;
V_110 &= ~ ( V_6 | V_7 | V_113 ) ;
F_3 ( V_110 , V_10 -> V_2 . V_4 + V_5 ) ;
F_77 ( & V_10 -> V_2 , V_204 , V_13 , F_75 ) ;
while ( ! ( F_2 ( V_10 -> V_2 . V_4 + V_71 ) & V_98 ) )
F_69 () ;
F_3 ( V_157 , V_10 -> V_2 . V_4 + V_5 ) ;
}
static void T_3
F_78 ( struct V_9 * V_10 , int * V_161 ,
int * V_87 , int * V_207 )
{
unsigned char V_208 , V_159 , V_209 , V_167 ;
unsigned int V_166 , V_180 , V_210 ;
V_208 = F_2 ( V_10 -> V_2 . V_4 + V_5 ) ;
V_208 &= V_112 | V_8 ;
if ( ! V_208 )
return;
V_208 = F_2 ( V_10 -> V_2 . V_4 + V_168 ) ;
* V_87 = 'n' ;
if ( V_208 & V_177 ) {
if ( V_208 & V_179 )
* V_87 = 'o' ;
else
* V_87 = 'e' ;
}
if ( V_208 & V_172 )
* V_207 = 9 ;
else
* V_207 = 8 ;
V_159 = F_2 ( V_10 -> V_2 . V_4 + V_170 ) ;
V_159 &= V_187 ;
V_209 = F_2 ( V_10 -> V_2 . V_4 + V_189 ) ;
V_166 = V_159 ;
V_166 <<= 8 ;
V_166 |= V_209 ;
V_167 = F_2 ( V_10 -> V_2 . V_4 + V_169 ) ;
V_167 &= V_188 ;
V_180 = F_79 ( V_10 -> V_211 ) ;
V_210 = V_180 / ( 16 * ( V_166 + V_167 / 32 ) ) ;
if ( * V_161 != V_210 )
F_80 ( V_212 L_14
L_15 , V_210 , * V_161 ) ;
}
static int T_3 F_81 ( struct V_202 * V_203 , char * V_213 )
{
struct V_9 * V_10 ;
int V_161 = 115200 ;
int V_207 = 8 ;
int V_87 = 'n' ;
int V_214 = 'n' ;
if ( V_203 -> V_206 == - 1 || V_203 -> V_206 >= F_82 ( V_205 ) )
V_203 -> V_206 = 0 ;
V_10 = V_205 [ V_203 -> V_206 ] ;
if ( V_10 == NULL )
return - V_133 ;
if ( V_213 )
F_83 ( V_213 , & V_161 , & V_87 , & V_207 , & V_214 ) ;
else
F_78 ( V_10 , & V_161 , & V_87 , & V_207 ) ;
F_49 ( V_10 ) ;
return F_84 ( & V_10 -> V_2 , V_203 , V_161 , V_87 , V_207 , V_214 ) ;
}
static int F_85 ( struct V_215 * V_216 )
{
struct V_217 * V_218 = V_216 -> V_17 . V_219 ;
struct V_9 * V_10 ;
struct V_220 * V_221 ;
int V_132 ;
V_10 = F_57 ( & V_216 -> V_17 , sizeof( * V_10 ) , V_145 ) ;
if ( ! V_10 )
return - V_135 ;
V_216 -> V_17 . V_222 = 0 ;
V_132 = F_86 ( V_218 , L_16 ) ;
if ( V_132 < 0 ) {
F_7 ( & V_216 -> V_17 , L_17 , V_132 ) ;
return V_132 ;
}
V_10 -> V_2 . line = V_132 ;
V_221 = F_87 ( V_216 , V_223 , 0 ) ;
if ( ! V_221 )
return - V_133 ;
V_10 -> V_2 . V_137 = V_221 -> V_224 ;
V_10 -> V_2 . V_4 = F_88 ( & V_216 -> V_17 , V_221 ) ;
if ( F_89 ( V_10 -> V_2 . V_4 ) )
return F_90 ( V_10 -> V_2 . V_4 ) ;
V_10 -> V_2 . V_17 = & V_216 -> V_17 ;
V_10 -> V_2 . type = V_191 ;
V_10 -> V_2 . V_225 = V_197 ;
V_10 -> V_2 . V_73 = F_91 ( V_216 , 0 ) ;
V_10 -> V_2 . V_226 = & V_227 ;
V_10 -> V_2 . V_26 = V_228 ;
V_10 -> V_211 = F_92 ( & V_216 -> V_17 , L_18 ) ;
if ( F_89 ( V_10 -> V_211 ) ) {
V_132 = F_90 ( V_10 -> V_211 ) ;
F_7 ( & V_216 -> V_17 , L_19 , V_132 ) ;
return V_132 ;
}
V_132 = F_93 ( V_10 -> V_211 ) ;
if ( V_132 ) {
F_7 ( & V_216 -> V_17 , L_20 , V_132 ) ;
return V_132 ;
}
V_10 -> V_2 . V_180 = F_79 ( V_10 -> V_211 ) ;
V_205 [ V_10 -> V_2 . line ] = V_10 ;
F_94 ( V_216 , & V_10 -> V_2 ) ;
V_132 = F_95 ( & V_229 , & V_10 -> V_2 ) ;
if ( V_132 ) {
F_96 ( V_10 -> V_211 ) ;
return V_132 ;
}
return 0 ;
}
static int F_97 ( struct V_215 * V_216 )
{
struct V_9 * V_10 = F_98 ( V_216 ) ;
F_99 ( & V_229 , & V_10 -> V_2 ) ;
F_96 ( V_10 -> V_211 ) ;
return 0 ;
}
static int F_100 ( struct V_134 * V_17 )
{
struct V_9 * V_10 = F_101 ( V_17 ) ;
F_102 ( & V_229 , & V_10 -> V_2 ) ;
return 0 ;
}
static int F_103 ( struct V_134 * V_17 )
{
struct V_9 * V_10 = F_101 ( V_17 ) ;
F_104 ( & V_229 , & V_10 -> V_2 ) ;
return 0 ;
}
static int T_3 F_105 ( void )
{
int V_132 ;
F_106 ( L_21 ) ;
V_132 = F_107 ( & V_229 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_108 ( & V_230 ) ;
if ( V_132 )
F_109 ( & V_229 ) ;
return V_132 ;
}
static void T_4 F_110 ( void )
{
F_111 ( & V_230 ) ;
F_109 ( & V_229 ) ;
}
