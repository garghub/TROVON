static void
F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
unsigned int V_4 , V_5 , V_6 ;
struct V_7 * V_8 = F_2 ( V_1 ) ;
void T_1 * V_9 = V_8 -> V_10 + V_11 ;
V_4 = F_3 ( V_9 + V_12 ) ;
V_5 = F_3 ( V_9 + V_13 ) ;
F_4 ( V_4 , V_9 + V_12 ) ;
V_3 -> V_14 . V_15 -> V_16 ( & V_3 -> V_14 ) ;
F_4 ( V_5 , V_9 + V_13 ) ;
if ( V_4 == 0 && V_5 == 0 ) {
F_5 ( V_1 , V_3 ) ;
return;
}
for ( V_6 = 0 ; V_4 ; V_6 ++ , V_4 >>= 1 )
if ( V_4 & 1 )
F_6 ( V_6 + V_8 -> V_17 ) ;
for ( V_6 = 32 ; V_5 ; V_6 ++ , V_5 >>= 1 )
if ( V_5 & 1 )
F_6 ( V_6 + V_8 -> V_17 ) ;
V_3 -> V_14 . V_15 -> V_18 ( & V_3 -> V_14 ) ;
}
static void F_7 ( struct V_14 * V_19 )
{
}
static void F_8 ( struct V_14 * V_19 )
{
struct V_7 * V_8 = F_9 ( V_19 ) ;
void T_1 * V_9 = V_8 -> V_10 + V_11 ;
unsigned long V_20 ;
V_20 = F_3 ( V_9 + V_21 ) ;
V_20 &= ~ F_10 ( V_19 -> V_1 ) ;
F_11 ( V_20 , V_9 + V_21 ) ;
}
static void F_12 ( struct V_14 * V_19 )
{
struct V_7 * V_8 = F_9 ( V_19 ) ;
void T_1 * V_9 = V_8 -> V_10 + V_11 ;
unsigned long V_20 ;
V_20 = F_3 ( V_9 + V_21 ) ;
V_20 |= F_10 ( V_19 -> V_1 ) ;
F_4 ( V_20 , V_9 + V_21 ) ;
}
static int F_13 ( struct V_14 * V_19 )
{
struct V_7 * V_8 = F_9 ( V_19 ) ;
void T_1 * V_9 = V_8 -> V_10 + V_11 ;
unsigned int V_22 = F_10 ( V_19 -> V_1 ) ;
unsigned long V_23 ;
int V_6 ;
V_23 = F_3 ( V_9 + V_24 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
F_4 ( V_23 ^ V_22 , V_9 + V_24 ) ;
F_4 ( V_23 , V_9 + V_24 ) ;
if ( F_3 ( V_9 + V_12 ) & V_22 )
break;
}
if ( V_6 == 8 )
F_14 ( V_25 L_1
L_2 , V_19 -> V_1 ) ;
return V_6 == 8 ? - 1 : 0 ;
}
static int F_15 ( struct V_14 * V_19 , unsigned int V_26 )
{
struct V_7 * V_8 = F_9 ( V_19 ) ;
void T_1 * V_9 = V_8 -> V_10 + V_11 ;
unsigned int V_22 = F_10 ( V_19 -> V_1 ) ;
unsigned long V_23 ;
if ( V_26 == V_27 )
return 0 ;
if ( ( ! ( V_26 & V_28 ) ^ ! ( V_26 & V_29 ) ) == 0 )
return - V_30 ;
V_23 = F_3 ( V_9 + V_24 ) ;
if ( V_26 & V_28 )
V_23 &= ~ V_22 ;
else
V_23 |= V_22 ;
F_4 ( V_23 , V_9 + V_24 ) ;
F_4 ( V_23 , V_9 + V_31 ) ;
return 0 ;
}
static int F_16 ( struct V_14 * V_19 , unsigned int V_32 )
{
struct V_7 * V_8 = F_9 ( V_19 ) ;
void T_1 * V_9 = V_8 -> V_10 + V_11 ;
unsigned int V_22 = F_10 ( V_19 -> V_1 ) ;
unsigned long V_33 ;
V_33 = F_3 ( V_9 + V_34 ) ;
if ( V_32 )
V_33 |= V_22 ;
else
V_33 &= ~ V_22 ;
F_4 ( V_33 , V_9 + V_34 ) ;
return 0 ;
}
static void F_17 ( struct V_14 * V_19 )
{
struct V_7 * V_8 = F_9 ( V_19 ) ;
void T_1 * V_9 = V_8 -> V_10 + V_11 ;
unsigned long V_35 ;
V_35 = F_3 ( V_9 + V_36 ) ;
V_35 &= ~ F_18 ( V_19 -> V_1 ) ;
F_4 ( V_35 , V_9 + V_36 ) ;
}
static void F_19 ( struct V_14 * V_19 )
{
struct V_7 * V_8 = F_9 ( V_19 ) ;
void T_1 * V_9 = V_8 -> V_10 + V_11 ;
unsigned long V_35 ;
V_35 = F_3 ( V_9 + V_36 ) ;
V_35 |= F_18 ( V_19 -> V_1 ) ;
F_4 ( V_35 , V_9 + V_36 ) ;
}
static int F_20 ( struct V_14 * V_19 )
{
struct V_7 * V_8 = F_9 ( V_19 ) ;
void T_1 * V_9 = V_8 -> V_10 + V_11 ;
unsigned int V_22 = F_18 ( V_19 -> V_1 ) ;
unsigned long V_37 ;
int V_6 ;
V_37 = F_3 ( V_9 + V_38 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
F_4 ( V_37 ^ V_22 , V_9 + V_38 ) ;
F_4 ( V_37 , V_9 + V_38 ) ;
if ( F_3 ( V_9 + V_13 ) & V_22 )
break;
}
if ( V_6 == 8 )
F_14 ( V_25 L_1
L_2 , V_19 -> V_1 ) ;
return V_6 == 8 ? - 1 : 0 ;
}
static int F_21 ( struct V_14 * V_19 , unsigned int V_26 )
{
struct V_7 * V_8 = F_9 ( V_19 ) ;
void T_1 * V_9 = V_8 -> V_10 + V_11 ;
unsigned int V_22 = F_18 ( V_19 -> V_1 ) ;
unsigned long V_37 ;
if ( V_26 == V_27 )
return 0 ;
if ( ( ! ( V_26 & V_28 ) ^ ! ( V_26 & V_29 ) ) == 0 )
return - V_30 ;
V_37 = F_3 ( V_9 + V_38 ) ;
if ( V_26 & V_28 )
V_37 &= ~ V_22 ;
else
V_37 |= V_22 ;
F_4 ( V_37 , V_9 + V_38 ) ;
F_4 ( V_37 , V_9 + V_39 ) ;
return 0 ;
}
static int F_22 ( struct V_14 * V_19 , unsigned int V_32 )
{
struct V_7 * V_8 = F_9 ( V_19 ) ;
void T_1 * V_9 = V_8 -> V_10 + V_11 ;
unsigned int V_22 = F_18 ( V_19 -> V_1 ) ;
unsigned long V_40 ;
V_40 = F_3 ( V_9 + V_41 ) ;
if ( V_32 )
V_40 |= V_22 ;
else
V_40 &= ~ V_22 ;
F_4 ( V_40 , V_9 + V_41 ) ;
return 0 ;
}
static int F_23 ( struct V_7 * V_8 , unsigned V_17 )
{
void T_1 * V_42 = V_8 -> V_10 + V_11 ;
unsigned V_6 , V_1 ;
int V_43 ;
F_24 ( V_8 -> V_44 + V_11 , 512 , L_3 ) ;
V_43 = F_25 ( - 1 , V_17 , V_45 , - 1 ) ;
if ( V_43 <= 0 ) {
F_26 ( V_8 -> V_46 , L_4 ,
V_45 , V_43 ) ;
if ( V_43 == 0 )
V_43 = - V_30 ;
return V_43 ;
}
V_8 -> V_17 = V_43 ;
F_4 ( 0 , V_42 + V_21 ) ;
F_4 ( 0 , V_42 + V_36 ) ;
F_4 ( 0 , V_42 + V_34 ) ;
F_4 ( 0 , V_42 + V_41 ) ;
F_4 ( 0 , V_42 + V_24 ) ;
F_4 ( F_18 ( V_47 ) |
F_18 ( V_48 ) ,
V_42 + V_38 ) ;
F_4 ( ~ 0 , V_42 + V_12 ) ;
F_4 ( ~ 0 , V_42 + V_13 ) ;
for ( V_6 = V_49 ; V_6 <= V_50 ; V_6 ++ ) {
V_1 = V_8 -> V_17 + V_6 ;
F_27 ( V_1 , & V_51 ,
V_52 ) ;
F_28 ( V_1 , V_8 ) ;
F_29 ( V_1 , V_53 | V_54 ) ;
}
for ( V_6 = V_55 ; V_6 <= V_56 ; V_6 ++ ) {
V_1 = V_8 -> V_17 + V_6 ;
F_27 ( V_1 , & V_57 ,
V_52 ) ;
F_28 ( V_1 , V_8 ) ;
F_29 ( V_1 , V_53 | V_54 ) ;
}
F_30 ( V_8 -> V_1 , V_28 ) ;
F_31 ( V_8 -> V_1 , V_8 ) ;
F_32 ( V_8 -> V_1 , F_1 ) ;
F_33 ( V_8 -> V_46 , L_5 ,
V_8 -> V_17 , V_8 -> V_17 + V_45 - 1 ) ;
return 0 ;
}
static void F_34 ( struct V_7 * V_8 )
{
unsigned long V_26 , V_58 ;
F_35 ( & V_8 -> V_59 , V_26 ) ;
F_36 ( V_8 -> V_60 ) ;
V_58 = F_3 ( V_8 -> V_10 + V_61 ) ;
V_58 &= ~ V_62 ;
F_4 ( V_58 , V_8 -> V_10 + V_61 ) ;
V_58 |= V_63 | V_64 ;
F_4 ( V_58 , V_8 -> V_10 + V_61 ) ;
F_37 ( 100 ) ;
V_58 |= V_65 | V_66 ;
F_4 ( V_58 , V_8 -> V_10 + V_61 ) ;
F_37 ( 1 ) ;
F_4 ( 0 , V_8 -> V_10 + V_67 ) ;
F_38 ( & V_8 -> V_59 , V_26 ) ;
}
void
F_39 ( struct V_7 * V_8 , int V_68 , unsigned int V_69 ,
unsigned int V_70 )
{
unsigned int V_71 = V_72 | V_73 | F_40 ( V_69 , V_74 ) ;
if ( V_70 == 3 )
V_71 |= V_75 ;
F_4 ( V_71 , V_8 -> V_10 + V_76 ) ;
if ( V_8 -> V_46 -> V_77 )
* V_8 -> V_46 -> V_77 &= V_78 [ V_69 >> 2 ] ;
V_8 -> V_46 -> V_79 &= V_78 [ V_69 >> 2 ] ;
}
static void F_41 ( struct V_80 * V_81 )
{
struct V_82 * V_46 = F_42 ( V_81 ) ;
F_43 ( V_46 ) ;
}
static int
F_44 ( struct V_7 * V_8 , struct V_83 * V_84 ,
struct V_85 * V_86 )
{
struct V_82 * V_46 ;
unsigned V_6 ;
int V_43 ;
V_46 = F_45 ( sizeof( struct V_82 ) , V_87 ) ;
if ( ! V_46 ) {
V_43 = - V_88 ;
goto V_89;
}
F_46 ( & V_46 -> V_46 ) ;
F_47 ( & V_46 -> V_46 , L_6 , V_86 -> V_90 ) ;
V_46 -> V_91 = V_86 -> V_91 ;
V_46 -> V_46 . V_84 = V_8 -> V_46 ;
V_46 -> V_46 . V_92 = & V_93 ;
V_46 -> V_46 . V_94 = F_41 ;
V_46 -> V_95 . V_96 = V_8 -> V_44 + V_86 -> V_90 ;
V_46 -> V_95 . V_97 = V_46 -> V_95 . V_96 + 511 ;
V_46 -> V_95 . V_98 = F_48 ( & V_46 -> V_46 ) ;
V_46 -> V_95 . V_26 = V_99 ;
V_46 -> V_9 = V_8 -> V_10 + V_86 -> V_90 ;
V_46 -> V_100 = V_86 -> V_100 ;
for ( V_6 = 0 ; V_6 < F_49 ( V_86 -> V_1 ) ; V_6 ++ )
V_46 -> V_1 [ V_6 ] = V_8 -> V_17 + V_86 -> V_1 [ V_6 ] ;
if ( V_86 -> V_101 && V_8 -> V_46 -> V_77 ) {
V_46 -> V_77 = * V_8 -> V_46 -> V_77 ;
V_46 -> V_46 . V_77 = & V_46 -> V_77 ;
V_46 -> V_46 . V_79 = V_8 -> V_46 -> V_79 ;
}
V_43 = F_50 ( V_84 , & V_46 -> V_95 ) ;
if ( V_43 ) {
F_26 ( V_8 -> V_46 , L_7 ,
V_46 -> V_95 . V_98 ) ;
goto V_102;
}
V_43 = F_51 ( & V_46 -> V_46 ) ;
if ( V_43 )
goto V_103;
return 0 ;
V_103:
F_52 ( & V_46 -> V_95 ) ;
V_102:
F_53 ( & V_46 -> V_46 ) ;
V_89:
return V_43 ;
}
static int F_54 ( struct V_80 * V_104 , struct V_83 * V_105 , int V_1 )
{
struct V_106 * V_107 = V_104 -> V_108 ;
struct V_7 * V_8 ;
unsigned long V_109 ;
unsigned int V_110 ;
int V_6 , V_43 = - V_111 ;
if ( ! V_107 )
return - V_30 ;
V_8 = F_45 ( sizeof( struct V_7 ) , V_87 ) ;
if ( ! V_8 )
return - V_88 ;
V_8 -> V_60 = F_55 ( V_104 , L_8 ) ;
if ( F_56 ( V_8 -> V_60 ) ) {
V_43 = F_57 ( V_8 -> V_60 ) ;
goto V_112;
}
V_43 = F_58 ( V_8 -> V_60 ) ;
if ( V_43 )
goto V_113;
F_59 ( & V_8 -> V_59 ) ;
V_8 -> V_46 = V_104 ;
F_60 ( V_8 -> V_46 , V_8 ) ;
V_8 -> V_114 = V_107 ;
V_8 -> V_44 = V_105 -> V_96 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_10 = F_61 ( V_105 -> V_96 , V_115 * 2 ) ;
if ( ! V_8 -> V_10 ) {
V_43 = - V_88 ;
goto V_116;
}
V_109 = F_3 ( V_8 -> V_10 + V_117 ) ;
if ( ( V_109 & V_118 ) != V_119 ) {
F_14 ( V_120 L_9 , V_109 ) ;
V_43 = - V_111 ;
goto V_121;
}
F_14 ( V_122 L_10
L_11 ,
( V_109 & V_123 ) >> 4 , ( V_109 & V_124 ) ) ;
F_34 ( V_8 ) ;
if ( V_8 -> V_1 != V_125 ) {
V_43 = F_23 ( V_8 , V_107 -> V_17 ) ;
if ( V_43 )
goto V_121;
}
#ifdef F_62
{
unsigned int V_126 ;
F_39 ( V_8 , 1 ,
F_63 ( V_127 , V_128 ) ,
F_63 ( V_127 , V_129 ) ) ;
V_126 = F_3 ( V_8 -> V_10 + V_67 ) ;
F_4 ( V_126 | V_130 , V_8 -> V_10 + V_67 ) ;
F_64 () ;
}
#endif
V_131 = V_8 ;
V_110 = ~ 0 ;
if ( V_107 )
V_110 &= ~ V_107 -> V_132 ;
for ( V_6 = 0 ; V_6 < F_49 ( V_133 ) ; V_6 ++ )
if ( V_133 [ V_6 ] . V_91 & V_110 )
F_44 ( V_8 , V_105 , & V_133 [ V_6 ] ) ;
return 0 ;
V_121:
F_65 ( V_8 -> V_10 ) ;
V_116:
F_66 ( V_8 -> V_60 ) ;
V_113:
F_67 ( V_8 -> V_60 ) ;
V_112:
F_43 ( V_8 ) ;
return V_43 ;
}
static int F_68 ( struct V_80 * V_46 , void * V_134 )
{
struct V_82 * V_135 = F_42 ( V_46 ) ;
F_69 ( & V_135 -> V_46 ) ;
F_52 ( & V_135 -> V_95 ) ;
F_53 ( & V_135 -> V_46 ) ;
return 0 ;
}
static void F_70 ( struct V_7 * V_8 )
{
void T_1 * V_42 = V_8 -> V_10 + V_11 ;
F_71 ( V_8 -> V_46 , NULL , F_68 ) ;
F_4 ( 0 , V_42 + V_21 ) ;
F_4 ( 0 , V_42 + V_36 ) ;
F_4 ( 0 , V_42 + V_34 ) ;
F_4 ( 0 , V_42 + V_41 ) ;
F_72 ( V_8 -> V_60 ) ;
F_66 ( V_8 -> V_60 ) ;
if ( V_8 -> V_1 != V_125 ) {
F_32 ( V_8 -> V_1 , NULL ) ;
F_31 ( V_8 -> V_1 , NULL ) ;
F_73 ( V_8 -> V_17 , V_45 ) ;
F_74 ( V_8 -> V_44 + V_11 , 512 ) ;
}
F_65 ( V_8 -> V_10 ) ;
F_67 ( V_8 -> V_60 ) ;
F_43 ( V_8 ) ;
}
static int F_75 ( struct V_136 * V_46 , T_2 V_137 )
{
struct V_7 * V_8 = F_76 ( V_46 ) ;
struct V_138 * V_139 ;
unsigned long V_26 ;
unsigned int V_126 ;
void T_1 * V_10 ;
V_139 = F_77 ( sizeof( struct V_138 ) , V_87 ) ;
if ( ! V_139 )
return - V_88 ;
V_8 -> V_140 = V_139 ;
F_35 ( & V_8 -> V_59 , V_26 ) ;
V_10 = V_8 -> V_10 ;
V_139 -> V_141 = F_3 ( V_10 + V_61 ) ;
V_139 -> V_142 = F_3 ( V_10 + V_67 ) ;
V_139 -> V_143 = F_3 ( V_10 + V_144 ) ;
V_139 -> V_145 = F_3 ( V_10 + V_146 ) ;
V_139 -> V_147 = F_3 ( V_10 + V_148 ) ;
V_139 -> V_149 = F_3 ( V_10 + V_150 ) ;
F_4 ( 0 , V_8 -> V_10 + V_148 ) ;
F_4 ( 0 , V_8 -> V_10 + V_150 ) ;
V_10 = V_8 -> V_10 + V_11 ;
V_139 -> V_151 = F_3 ( V_10 + V_24 ) ;
V_139 -> V_152 = F_3 ( V_10 + V_38 ) ;
V_139 -> V_153 = F_3 ( V_10 + V_21 ) ;
V_139 -> V_154 = F_3 ( V_10 + V_36 ) ;
V_139 -> V_155 = F_3 ( V_10 + V_31 ) ;
V_139 -> V_156 = F_3 ( V_10 + V_39 ) ;
V_139 -> V_157 = F_3 ( V_10 + V_34 ) ;
V_139 -> V_158 = F_3 ( V_10 + V_41 ) ;
V_126 = F_3 ( V_8 -> V_10 + V_61 ) ;
F_4 ( V_126 | V_159 , V_8 -> V_10 + V_61 ) ;
F_72 ( V_8 -> V_60 ) ;
F_38 ( & V_8 -> V_59 , V_26 ) ;
#ifdef F_62
F_78 () ;
#endif
return 0 ;
}
static int F_79 ( struct V_136 * V_46 )
{
struct V_7 * V_8 = F_76 ( V_46 ) ;
struct V_138 * V_139 ;
unsigned long V_26 , V_109 ;
void T_1 * V_10 ;
V_139 = V_8 -> V_140 ;
if ( ! V_139 )
return 0 ;
V_109 = F_3 ( V_8 -> V_10 + V_117 ) ;
if ( ( V_109 & V_118 ) != V_119 ) {
F_70 ( V_8 ) ;
F_80 ( V_46 , NULL ) ;
F_43 ( V_139 ) ;
return 0 ;
}
F_34 ( V_8 ) ;
#ifdef F_62
F_64 () ;
#endif
F_35 ( & V_8 -> V_59 , V_26 ) ;
F_4 ( 0 , V_8 -> V_10 + V_11 + V_21 ) ;
F_4 ( 0 , V_8 -> V_10 + V_11 + V_36 ) ;
V_10 = V_8 -> V_10 ;
F_4 ( V_139 -> V_141 , V_10 + V_61 ) ;
F_4 ( V_139 -> V_142 , V_10 + V_67 ) ;
F_4 ( V_139 -> V_143 , V_10 + V_144 ) ;
F_4 ( V_139 -> V_145 , V_10 + V_146 ) ;
F_4 ( V_139 -> V_147 , V_10 + V_148 ) ;
F_4 ( V_139 -> V_149 , V_10 + V_150 ) ;
V_10 = V_8 -> V_10 + V_11 ;
F_4 ( V_139 -> V_151 , V_10 + V_24 ) ;
F_4 ( V_139 -> V_152 , V_10 + V_38 ) ;
F_4 ( V_139 -> V_153 , V_10 + V_21 ) ;
F_4 ( V_139 -> V_154 , V_10 + V_36 ) ;
F_4 ( V_139 -> V_155 , V_10 + V_31 ) ;
F_4 ( V_139 -> V_156 , V_10 + V_39 ) ;
F_4 ( V_139 -> V_157 , V_10 + V_34 ) ;
F_4 ( V_139 -> V_158 , V_10 + V_41 ) ;
F_38 ( & V_8 -> V_59 , V_26 ) ;
V_8 -> V_140 = NULL ;
F_43 ( V_139 ) ;
return 0 ;
}
static int F_81 ( struct V_136 * V_160 )
{
struct V_83 * V_105 ;
int V_1 ;
V_105 = F_82 ( V_160 , V_99 , 0 ) ;
if ( ! V_105 )
return - V_30 ;
V_1 = F_83 ( V_160 , 0 ) ;
if ( V_1 < 0 )
return - V_161 ;
return F_54 ( & V_160 -> V_46 , V_105 , V_1 ) ;
}
static int F_84 ( struct V_136 * V_160 )
{
struct V_7 * V_8 = F_76 ( V_160 ) ;
if ( V_8 ) {
#ifdef F_85
F_43 ( V_8 -> V_140 ) ;
V_8 -> V_140 = NULL ;
#endif
F_70 ( V_8 ) ;
F_80 ( V_160 , NULL ) ;
}
return 0 ;
}
static inline struct V_7 * F_86 ( struct V_82 * V_135 )
{
return (struct V_7 * ) F_87 ( V_135 -> V_46 . V_84 ) ;
}
static unsigned int F_88 ( struct V_7 * V_8 )
{
unsigned int V_143 , V_162 , V_163 , V_164 ;
V_143 = F_3 ( V_8 -> V_10 + V_144 ) ;
V_162 = ( V_143 & 0x007f ) + 2 ;
V_163 = ( ( V_143 & 0x0f80 ) >> 7 ) + 2 ;
V_164 = V_165 [ ( V_143 & 0x3000 ) >> 12 ] ;
return 3686400 * V_162 / ( V_163 * V_164 ) ;
}
unsigned int F_89 ( struct V_82 * V_135 )
{
struct V_7 * V_8 = F_86 ( V_135 ) ;
return F_88 ( V_8 ) ;
}
void F_90 ( struct V_82 * V_135 , int V_166 )
{
struct V_7 * V_8 = F_86 ( V_135 ) ;
unsigned long V_26 ;
unsigned int V_126 ;
F_35 ( & V_8 -> V_59 , V_26 ) ;
V_126 = F_3 ( V_8 -> V_10 + V_61 ) ;
if ( V_166 == V_167 ) {
V_126 &= ~ V_168 ;
} else {
V_126 |= V_168 ;
}
F_4 ( V_126 , V_8 -> V_10 + V_61 ) ;
F_38 ( & V_8 -> V_59 , V_26 ) ;
}
int F_91 ( struct V_82 * V_135 , int V_169 )
{
struct V_7 * V_8 = F_86 ( V_135 ) ;
unsigned int div ;
if ( V_135 -> V_91 != V_170 )
return - V_30 ;
div = ( F_88 ( V_8 ) / 256 + V_169 / 2 ) / V_169 ;
if ( div == 0 )
div = 1 ;
if ( div > 128 )
div = 128 ;
F_4 ( div - 1 , V_8 -> V_10 + V_146 ) ;
return 0 ;
}
int F_92 ( struct V_82 * V_135 )
{
struct V_7 * V_8 = F_86 ( V_135 ) ;
unsigned long div ;
if ( V_135 -> V_91 != V_170 )
return - V_30 ;
div = F_3 ( V_8 -> V_10 + V_146 ) + 1 ;
return F_88 ( V_8 ) / ( 256 * div ) ;
}
void F_93 ( struct V_82 * V_135 ,
unsigned int V_171 , unsigned int V_172 ,
unsigned int V_173 )
{
struct V_7 * V_8 = F_86 ( V_135 ) ;
unsigned long V_26 ;
unsigned int V_126 ;
void T_1 * V_174 = V_8 -> V_10 + V_175 ;
#define F_94 ( T_3 , V_22 , V_172 ) \
if (mask) { \
val = sa1111_readl(port); \
val &= ~(mask); \
val |= (dir) & (mask); \
sa1111_writel(val, port); \
}
F_35 ( & V_8 -> V_59 , V_26 ) ;
F_94 ( V_174 + V_176 , V_171 & 15 , V_172 ) ;
F_94 ( V_174 + V_177 , ( V_171 >> 8 ) & 255 , V_172 >> 8 ) ;
F_94 ( V_174 + V_178 , ( V_171 >> 16 ) & 255 , V_172 >> 16 ) ;
F_94 ( V_174 + V_179 , V_171 & 15 , V_173 ) ;
F_94 ( V_174 + V_180 , ( V_171 >> 8 ) & 255 , V_173 >> 8 ) ;
F_94 ( V_174 + V_181 , ( V_171 >> 16 ) & 255 , V_173 >> 16 ) ;
F_38 ( & V_8 -> V_59 , V_26 ) ;
}
void F_95 ( struct V_82 * V_135 , unsigned int V_171 , unsigned int V_182 )
{
struct V_7 * V_8 = F_86 ( V_135 ) ;
unsigned long V_26 ;
unsigned int V_126 ;
void T_1 * V_174 = V_8 -> V_10 + V_175 ;
F_35 ( & V_8 -> V_59 , V_26 ) ;
F_94 ( V_174 + V_183 , V_171 & 15 , V_182 ) ;
F_94 ( V_174 + V_184 , ( V_171 >> 8 ) & 255 , V_182 >> 8 ) ;
F_94 ( V_174 + V_185 , ( V_171 >> 16 ) & 255 , V_182 >> 16 ) ;
F_38 ( & V_8 -> V_59 , V_26 ) ;
}
void F_96 ( struct V_82 * V_135 , unsigned int V_171 , unsigned int V_182 )
{
struct V_7 * V_8 = F_86 ( V_135 ) ;
unsigned long V_26 ;
unsigned int V_126 ;
void T_1 * V_174 = V_8 -> V_10 + V_175 ;
F_35 ( & V_8 -> V_59 , V_26 ) ;
F_94 ( V_174 + V_186 , V_171 & 15 , V_182 ) ;
F_94 ( V_174 + V_187 , ( V_171 >> 8 ) & 255 , V_182 >> 8 ) ;
F_94 ( V_174 + V_188 , ( V_171 >> 16 ) & 255 , V_182 >> 16 ) ;
F_38 ( & V_8 -> V_59 , V_26 ) ;
}
int F_97 ( struct V_82 * V_135 )
{
struct V_7 * V_8 = F_86 ( V_135 ) ;
unsigned long V_26 ;
unsigned int V_126 ;
int V_43 = 0 ;
if ( V_8 -> V_114 && V_8 -> V_114 -> V_189 )
V_43 = V_8 -> V_114 -> V_189 ( V_8 -> V_114 -> V_134 , V_135 -> V_91 ) ;
if ( V_43 == 0 ) {
F_35 ( & V_8 -> V_59 , V_26 ) ;
V_126 = F_3 ( V_8 -> V_10 + V_67 ) ;
F_4 ( V_126 | V_135 -> V_100 , V_8 -> V_10 + V_67 ) ;
F_38 ( & V_8 -> V_59 , V_26 ) ;
}
return V_43 ;
}
void F_98 ( struct V_82 * V_135 )
{
struct V_7 * V_8 = F_86 ( V_135 ) ;
unsigned long V_26 ;
unsigned int V_126 ;
F_35 ( & V_8 -> V_59 , V_26 ) ;
V_126 = F_3 ( V_8 -> V_10 + V_67 ) ;
F_4 ( V_126 & ~ V_135 -> V_100 , V_8 -> V_10 + V_67 ) ;
F_38 ( & V_8 -> V_59 , V_26 ) ;
if ( V_8 -> V_114 && V_8 -> V_114 -> V_190 )
V_8 -> V_114 -> V_190 ( V_8 -> V_114 -> V_134 , V_135 -> V_91 ) ;
}
static int F_99 ( struct V_80 * V_81 , struct V_191 * V_192 )
{
struct V_82 * V_46 = F_42 ( V_81 ) ;
struct V_193 * V_194 = F_100 ( V_192 ) ;
return V_46 -> V_91 & V_194 -> V_91 ;
}
static int F_101 ( struct V_80 * V_46 , T_2 V_137 )
{
struct V_82 * V_135 = F_42 ( V_46 ) ;
struct V_193 * V_194 = F_100 ( V_46 -> V_195 ) ;
int V_43 = 0 ;
if ( V_194 && V_194 -> V_196 )
V_43 = V_194 -> V_196 ( V_135 , V_137 ) ;
return V_43 ;
}
static int F_102 ( struct V_80 * V_46 )
{
struct V_82 * V_135 = F_42 ( V_46 ) ;
struct V_193 * V_194 = F_100 ( V_46 -> V_195 ) ;
int V_43 = 0 ;
if ( V_194 && V_194 -> V_197 )
V_43 = V_194 -> V_197 ( V_135 ) ;
return V_43 ;
}
static void F_103 ( struct V_80 * V_46 )
{
struct V_193 * V_194 = F_100 ( V_46 -> V_195 ) ;
if ( V_194 && V_194 -> V_198 )
V_194 -> V_198 ( F_42 ( V_46 ) ) ;
}
static int F_104 ( struct V_80 * V_46 )
{
struct V_82 * V_135 = F_42 ( V_46 ) ;
struct V_193 * V_194 = F_100 ( V_46 -> V_195 ) ;
int V_43 = - V_111 ;
if ( V_194 -> V_199 )
V_43 = V_194 -> V_199 ( V_135 ) ;
return V_43 ;
}
static int F_105 ( struct V_80 * V_46 )
{
struct V_82 * V_135 = F_42 ( V_46 ) ;
struct V_193 * V_194 = F_100 ( V_46 -> V_195 ) ;
int V_43 = 0 ;
if ( V_194 -> remove )
V_43 = V_194 -> remove ( V_135 ) ;
return V_43 ;
}
int F_106 ( struct V_193 * V_195 )
{
V_195 -> V_194 . V_92 = & V_93 ;
return F_107 ( & V_195 -> V_194 ) ;
}
void F_108 ( struct V_193 * V_195 )
{
F_109 ( & V_195 -> V_194 ) ;
}
static int F_110 ( struct V_80 * V_46 , T_4 V_200 , T_5 V_201 )
{
return ( F_111 () || F_112 () ) &&
( V_200 >= 0xc8000000 || ( V_200 + V_201 ) >= 0xc8000000 ) ;
}
static int F_113 ( struct V_202 * V_203 , unsigned long V_204 ,
void * V_134 )
{
struct V_82 * V_46 = F_42 ( V_134 ) ;
switch ( V_204 ) {
case V_205 :
if ( V_46 -> V_46 . V_77 && V_46 -> V_77 < 0xffffffffUL ) {
int V_43 = F_114 ( & V_46 -> V_46 , 1024 , 4096 ,
F_110 ) ;
if ( V_43 )
F_26 ( & V_46 -> V_46 , L_12 , V_43 ) ;
}
break;
case V_206 :
if ( V_46 -> V_46 . V_77 && V_46 -> V_77 < 0xffffffffUL )
F_115 ( & V_46 -> V_46 ) ;
break;
}
return V_207 ;
}
static int T_6 F_116 ( void )
{
int V_43 = F_117 ( & V_93 ) ;
#ifdef F_118
if ( V_43 == 0 )
F_119 ( & V_93 , & V_208 ) ;
#endif
if ( V_43 == 0 )
F_120 ( & V_209 ) ;
return V_43 ;
}
static void T_7 F_121 ( void )
{
F_122 ( & V_209 ) ;
#ifdef F_118
F_123 ( & V_93 , & V_208 ) ;
#endif
F_124 ( & V_93 ) ;
}
