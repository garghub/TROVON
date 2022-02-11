static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 , V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
V_3 = F_3 ( V_8 + V_11 ) ;
V_4 = F_3 ( V_8 + V_12 ) ;
F_4 ( V_3 , V_8 + V_11 ) ;
V_2 -> V_13 . V_14 -> V_15 ( & V_2 -> V_13 ) ;
F_4 ( V_4 , V_8 + V_12 ) ;
if ( V_3 == 0 && V_4 == 0 ) {
F_5 ( V_2 ) ;
return;
}
for ( V_5 = 0 ; V_3 ; V_5 ++ , V_3 >>= 1 )
if ( V_3 & 1 )
F_6 ( V_5 + V_7 -> V_16 ) ;
for ( V_5 = 32 ; V_4 ; V_5 ++ , V_4 >>= 1 )
if ( V_4 & 1 )
F_6 ( V_5 + V_7 -> V_16 ) ;
V_2 -> V_13 . V_14 -> V_17 ( & V_2 -> V_13 ) ;
}
static void F_7 ( struct V_13 * V_18 )
{
}
static void F_8 ( struct V_13 * V_18 )
{
struct V_6 * V_7 = F_9 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
unsigned long V_19 ;
V_19 = F_3 ( V_8 + V_20 ) ;
V_19 &= ~ F_10 ( V_18 -> V_21 ) ;
F_11 ( V_19 , V_8 + V_20 ) ;
}
static void F_12 ( struct V_13 * V_18 )
{
struct V_6 * V_7 = F_9 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
unsigned long V_19 ;
V_19 = F_3 ( V_8 + V_20 ) ;
V_19 |= F_10 ( V_18 -> V_21 ) ;
F_4 ( V_19 , V_8 + V_20 ) ;
}
static int F_13 ( struct V_13 * V_18 )
{
struct V_6 * V_7 = F_9 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
unsigned int V_22 = F_10 ( V_18 -> V_21 ) ;
unsigned long V_23 ;
int V_5 ;
V_23 = F_3 ( V_8 + V_24 ) ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
F_4 ( V_23 ^ V_22 , V_8 + V_24 ) ;
F_4 ( V_23 , V_8 + V_24 ) ;
if ( F_3 ( V_8 + V_11 ) & V_22 )
break;
}
if ( V_5 == 8 )
F_14 ( L_1 ,
V_18 -> V_21 ) ;
return V_5 == 8 ? - 1 : 0 ;
}
static int F_15 ( struct V_13 * V_18 , unsigned int V_25 )
{
struct V_6 * V_7 = F_9 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
unsigned int V_22 = F_10 ( V_18 -> V_21 ) ;
unsigned long V_23 ;
if ( V_25 == V_26 )
return 0 ;
if ( ( ! ( V_25 & V_27 ) ^ ! ( V_25 & V_28 ) ) == 0 )
return - V_29 ;
V_23 = F_3 ( V_8 + V_24 ) ;
if ( V_25 & V_27 )
V_23 &= ~ V_22 ;
else
V_23 |= V_22 ;
F_4 ( V_23 , V_8 + V_24 ) ;
F_4 ( V_23 , V_8 + V_30 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_18 , unsigned int V_31 )
{
struct V_6 * V_7 = F_9 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
unsigned int V_22 = F_10 ( V_18 -> V_21 ) ;
unsigned long V_32 ;
V_32 = F_3 ( V_8 + V_33 ) ;
if ( V_31 )
V_32 |= V_22 ;
else
V_32 &= ~ V_22 ;
F_4 ( V_32 , V_8 + V_33 ) ;
return 0 ;
}
static void F_17 ( struct V_13 * V_18 )
{
struct V_6 * V_7 = F_9 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
unsigned long V_34 ;
V_34 = F_3 ( V_8 + V_35 ) ;
V_34 &= ~ F_18 ( V_18 -> V_21 ) ;
F_4 ( V_34 , V_8 + V_35 ) ;
}
static void F_19 ( struct V_13 * V_18 )
{
struct V_6 * V_7 = F_9 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
unsigned long V_34 ;
V_34 = F_3 ( V_8 + V_35 ) ;
V_34 |= F_18 ( V_18 -> V_21 ) ;
F_4 ( V_34 , V_8 + V_35 ) ;
}
static int F_20 ( struct V_13 * V_18 )
{
struct V_6 * V_7 = F_9 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
unsigned int V_22 = F_18 ( V_18 -> V_21 ) ;
unsigned long V_36 ;
int V_5 ;
V_36 = F_3 ( V_8 + V_37 ) ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
F_4 ( V_36 ^ V_22 , V_8 + V_37 ) ;
F_4 ( V_36 , V_8 + V_37 ) ;
if ( F_3 ( V_8 + V_12 ) & V_22 )
break;
}
if ( V_5 == 8 )
F_14 ( L_1 ,
V_18 -> V_21 ) ;
return V_5 == 8 ? - 1 : 0 ;
}
static int F_21 ( struct V_13 * V_18 , unsigned int V_25 )
{
struct V_6 * V_7 = F_9 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
unsigned int V_22 = F_18 ( V_18 -> V_21 ) ;
unsigned long V_36 ;
if ( V_25 == V_26 )
return 0 ;
if ( ( ! ( V_25 & V_27 ) ^ ! ( V_25 & V_28 ) ) == 0 )
return - V_29 ;
V_36 = F_3 ( V_8 + V_37 ) ;
if ( V_25 & V_27 )
V_36 &= ~ V_22 ;
else
V_36 |= V_22 ;
F_4 ( V_36 , V_8 + V_37 ) ;
F_4 ( V_36 , V_8 + V_38 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_18 , unsigned int V_31 )
{
struct V_6 * V_7 = F_9 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 ;
unsigned int V_22 = F_18 ( V_18 -> V_21 ) ;
unsigned long V_39 ;
V_39 = F_3 ( V_8 + V_40 ) ;
if ( V_31 )
V_39 |= V_22 ;
else
V_39 &= ~ V_22 ;
F_4 ( V_39 , V_8 + V_40 ) ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 , unsigned V_16 )
{
void T_1 * V_41 = V_7 -> V_9 + V_10 ;
unsigned V_5 , V_21 ;
int V_42 ;
F_24 ( V_7 -> V_43 + V_10 , 512 , L_2 ) ;
V_42 = F_25 ( - 1 , V_16 , V_44 , - 1 ) ;
if ( V_42 <= 0 ) {
F_26 ( V_7 -> V_45 , L_3 ,
V_44 , V_42 ) ;
if ( V_42 == 0 )
V_42 = - V_29 ;
return V_42 ;
}
V_7 -> V_16 = V_42 ;
F_4 ( 0 , V_41 + V_20 ) ;
F_4 ( 0 , V_41 + V_35 ) ;
F_4 ( 0 , V_41 + V_33 ) ;
F_4 ( 0 , V_41 + V_40 ) ;
F_4 ( 0 , V_41 + V_24 ) ;
F_4 ( F_18 ( V_46 ) |
F_18 ( V_47 ) ,
V_41 + V_37 ) ;
F_4 ( ~ 0 , V_41 + V_11 ) ;
F_4 ( ~ 0 , V_41 + V_12 ) ;
for ( V_5 = V_48 ; V_5 <= V_49 ; V_5 ++ ) {
V_21 = V_7 -> V_16 + V_5 ;
F_27 ( V_21 , & V_50 ,
V_51 ) ;
F_28 ( V_21 , V_7 ) ;
F_29 ( V_21 , V_52 | V_53 ) ;
}
for ( V_5 = V_54 ; V_5 <= V_55 ; V_5 ++ ) {
V_21 = V_7 -> V_16 + V_5 ;
F_27 ( V_21 , & V_56 ,
V_51 ) ;
F_28 ( V_21 , V_7 ) ;
F_29 ( V_21 , V_52 | V_53 ) ;
}
F_30 ( V_7 -> V_21 , V_27 ) ;
F_31 ( V_7 -> V_21 , F_1 ,
V_7 ) ;
F_32 ( V_7 -> V_45 , L_4 ,
V_7 -> V_16 , V_7 -> V_16 + V_44 - 1 ) ;
return 0 ;
}
static void F_33 ( struct V_6 * V_7 )
{
unsigned long V_25 , V_57 ;
F_34 ( & V_7 -> V_58 , V_25 ) ;
F_35 ( V_7 -> V_59 ) ;
V_57 = F_3 ( V_7 -> V_9 + V_60 ) ;
V_57 &= ~ V_61 ;
F_4 ( V_57 , V_7 -> V_9 + V_60 ) ;
V_57 |= V_62 | V_63 ;
F_4 ( V_57 , V_7 -> V_9 + V_60 ) ;
F_36 ( 100 ) ;
V_57 |= V_64 | V_65 ;
F_4 ( V_57 , V_7 -> V_9 + V_60 ) ;
F_36 ( 1 ) ;
F_4 ( 0 , V_7 -> V_9 + V_66 ) ;
F_37 ( & V_7 -> V_58 , V_25 ) ;
}
void
F_38 ( struct V_6 * V_7 , int V_67 , unsigned int V_68 ,
unsigned int V_69 )
{
unsigned int V_70 = V_71 | V_72 | F_39 ( V_68 , V_73 ) ;
if ( V_69 == 3 )
V_70 |= V_74 ;
F_4 ( V_70 , V_7 -> V_9 + V_75 ) ;
if ( V_7 -> V_45 -> V_76 )
* V_7 -> V_45 -> V_76 &= V_77 [ V_68 >> 2 ] ;
V_7 -> V_45 -> V_78 &= V_77 [ V_68 >> 2 ] ;
}
static void F_40 ( struct V_79 * V_80 )
{
struct V_81 * V_45 = F_41 ( V_80 ) ;
F_42 ( V_45 ) ;
}
static int
F_43 ( struct V_6 * V_7 , struct V_82 * V_83 ,
struct V_84 * V_85 )
{
struct V_81 * V_45 ;
unsigned V_5 ;
int V_42 ;
V_45 = F_44 ( sizeof( struct V_81 ) , V_86 ) ;
if ( ! V_45 ) {
V_42 = - V_87 ;
goto V_88;
}
F_45 ( & V_45 -> V_45 ) ;
F_46 ( & V_45 -> V_45 , L_5 , V_85 -> V_89 ) ;
V_45 -> V_90 = V_85 -> V_90 ;
V_45 -> V_45 . V_83 = V_7 -> V_45 ;
V_45 -> V_45 . V_91 = & V_92 ;
V_45 -> V_45 . V_93 = F_40 ;
V_45 -> V_94 . V_95 = V_7 -> V_43 + V_85 -> V_89 ;
V_45 -> V_94 . V_96 = V_45 -> V_94 . V_95 + 511 ;
V_45 -> V_94 . V_97 = F_47 ( & V_45 -> V_45 ) ;
V_45 -> V_94 . V_25 = V_98 ;
V_45 -> V_8 = V_7 -> V_9 + V_85 -> V_89 ;
V_45 -> V_99 = V_85 -> V_99 ;
for ( V_5 = 0 ; V_5 < F_48 ( V_85 -> V_21 ) ; V_5 ++ )
V_45 -> V_21 [ V_5 ] = V_7 -> V_16 + V_85 -> V_21 [ V_5 ] ;
if ( V_85 -> V_100 && V_7 -> V_45 -> V_76 ) {
V_45 -> V_76 = * V_7 -> V_45 -> V_76 ;
V_45 -> V_45 . V_76 = & V_45 -> V_76 ;
V_45 -> V_45 . V_78 = V_7 -> V_45 -> V_78 ;
}
V_42 = F_49 ( V_83 , & V_45 -> V_94 ) ;
if ( V_42 ) {
F_26 ( V_7 -> V_45 , L_6 ,
V_45 -> V_94 . V_97 ) ;
goto V_101;
}
V_42 = F_50 ( & V_45 -> V_45 ) ;
if ( V_42 )
goto V_102;
return 0 ;
V_102:
F_51 ( & V_45 -> V_94 ) ;
V_101:
F_52 ( & V_45 -> V_45 ) ;
V_88:
return V_42 ;
}
static int F_53 ( struct V_79 * V_103 , struct V_82 * V_104 , int V_21 )
{
struct V_105 * V_106 = V_103 -> V_107 ;
struct V_6 * V_7 ;
unsigned long V_108 ;
unsigned int V_109 ;
int V_5 , V_42 = - V_110 ;
if ( ! V_106 )
return - V_29 ;
V_7 = F_44 ( sizeof( struct V_6 ) , V_86 ) ;
if ( ! V_7 )
return - V_87 ;
V_7 -> V_59 = F_54 ( V_103 , L_7 ) ;
if ( F_55 ( V_7 -> V_59 ) ) {
V_42 = F_56 ( V_7 -> V_59 ) ;
goto V_111;
}
V_42 = F_57 ( V_7 -> V_59 ) ;
if ( V_42 )
goto V_112;
F_58 ( & V_7 -> V_58 ) ;
V_7 -> V_45 = V_103 ;
F_59 ( V_7 -> V_45 , V_7 ) ;
V_7 -> V_113 = V_106 ;
V_7 -> V_43 = V_104 -> V_95 ;
V_7 -> V_21 = V_21 ;
V_7 -> V_9 = F_60 ( V_104 -> V_95 , V_114 * 2 ) ;
if ( ! V_7 -> V_9 ) {
V_42 = - V_87 ;
goto V_115;
}
V_108 = F_3 ( V_7 -> V_9 + V_116 ) ;
if ( ( V_108 & V_117 ) != V_118 ) {
F_61 ( V_119 L_8 , V_108 ) ;
V_42 = - V_110 ;
goto V_120;
}
F_62 ( L_9 ,
( V_108 & V_121 ) >> 4 , V_108 & V_122 ) ;
F_33 ( V_7 ) ;
if ( V_7 -> V_21 != V_123 ) {
V_42 = F_23 ( V_7 , V_106 -> V_16 ) ;
if ( V_42 )
goto V_120;
}
#ifdef F_63
{
unsigned int V_124 ;
F_38 ( V_7 , 1 ,
F_64 ( V_125 , V_126 ) ,
F_64 ( V_125 , V_127 ) ) ;
V_124 = F_3 ( V_7 -> V_9 + V_66 ) ;
F_4 ( V_124 | V_128 , V_7 -> V_9 + V_66 ) ;
F_65 () ;
}
#endif
V_129 = V_7 ;
V_109 = ~ 0 ;
if ( V_106 )
V_109 &= ~ V_106 -> V_130 ;
for ( V_5 = 0 ; V_5 < F_48 ( V_131 ) ; V_5 ++ )
if ( V_131 [ V_5 ] . V_90 & V_109 )
F_43 ( V_7 , V_104 , & V_131 [ V_5 ] ) ;
return 0 ;
V_120:
F_66 ( V_7 -> V_9 ) ;
V_115:
F_67 ( V_7 -> V_59 ) ;
V_112:
F_68 ( V_7 -> V_59 ) ;
V_111:
F_42 ( V_7 ) ;
return V_42 ;
}
static int F_69 ( struct V_79 * V_45 , void * V_132 )
{
struct V_81 * V_133 = F_41 ( V_45 ) ;
F_70 ( & V_133 -> V_45 ) ;
F_51 ( & V_133 -> V_94 ) ;
F_52 ( & V_133 -> V_45 ) ;
return 0 ;
}
static void F_71 ( struct V_6 * V_7 )
{
void T_1 * V_41 = V_7 -> V_9 + V_10 ;
F_72 ( V_7 -> V_45 , NULL , F_69 ) ;
F_4 ( 0 , V_41 + V_20 ) ;
F_4 ( 0 , V_41 + V_35 ) ;
F_4 ( 0 , V_41 + V_33 ) ;
F_4 ( 0 , V_41 + V_40 ) ;
F_73 ( V_7 -> V_59 ) ;
F_67 ( V_7 -> V_59 ) ;
if ( V_7 -> V_21 != V_123 ) {
F_31 ( V_7 -> V_21 , NULL , NULL ) ;
F_74 ( V_7 -> V_16 , V_44 ) ;
F_75 ( V_7 -> V_43 + V_10 , 512 ) ;
}
F_66 ( V_7 -> V_9 ) ;
F_68 ( V_7 -> V_59 ) ;
F_42 ( V_7 ) ;
}
static int F_76 ( struct V_134 * V_45 , T_2 V_135 )
{
struct V_6 * V_7 = F_77 ( V_45 ) ;
struct V_136 * V_137 ;
unsigned long V_25 ;
unsigned int V_124 ;
void T_1 * V_9 ;
V_137 = F_78 ( sizeof( struct V_136 ) , V_86 ) ;
if ( ! V_137 )
return - V_87 ;
V_7 -> V_138 = V_137 ;
F_34 ( & V_7 -> V_58 , V_25 ) ;
V_9 = V_7 -> V_9 ;
V_137 -> V_139 = F_3 ( V_9 + V_60 ) ;
V_137 -> V_140 = F_3 ( V_9 + V_66 ) ;
V_137 -> V_141 = F_3 ( V_9 + V_142 ) ;
V_137 -> V_143 = F_3 ( V_9 + V_144 ) ;
V_137 -> V_145 = F_3 ( V_9 + V_146 ) ;
V_137 -> V_147 = F_3 ( V_9 + V_148 ) ;
F_4 ( 0 , V_7 -> V_9 + V_146 ) ;
F_4 ( 0 , V_7 -> V_9 + V_148 ) ;
V_9 = V_7 -> V_9 + V_10 ;
V_137 -> V_149 = F_3 ( V_9 + V_24 ) ;
V_137 -> V_150 = F_3 ( V_9 + V_37 ) ;
V_137 -> V_151 = F_3 ( V_9 + V_20 ) ;
V_137 -> V_152 = F_3 ( V_9 + V_35 ) ;
V_137 -> V_153 = F_3 ( V_9 + V_30 ) ;
V_137 -> V_154 = F_3 ( V_9 + V_38 ) ;
V_137 -> V_155 = F_3 ( V_9 + V_33 ) ;
V_137 -> V_156 = F_3 ( V_9 + V_40 ) ;
V_124 = F_3 ( V_7 -> V_9 + V_60 ) ;
F_4 ( V_124 | V_157 , V_7 -> V_9 + V_60 ) ;
F_73 ( V_7 -> V_59 ) ;
F_37 ( & V_7 -> V_58 , V_25 ) ;
#ifdef F_63
F_79 () ;
#endif
return 0 ;
}
static int F_80 ( struct V_134 * V_45 )
{
struct V_6 * V_7 = F_77 ( V_45 ) ;
struct V_136 * V_137 ;
unsigned long V_25 , V_108 ;
void T_1 * V_9 ;
V_137 = V_7 -> V_138 ;
if ( ! V_137 )
return 0 ;
V_108 = F_3 ( V_7 -> V_9 + V_116 ) ;
if ( ( V_108 & V_117 ) != V_118 ) {
F_71 ( V_7 ) ;
F_81 ( V_45 , NULL ) ;
F_42 ( V_137 ) ;
return 0 ;
}
F_33 ( V_7 ) ;
#ifdef F_63
F_65 () ;
#endif
F_34 ( & V_7 -> V_58 , V_25 ) ;
F_4 ( 0 , V_7 -> V_9 + V_10 + V_20 ) ;
F_4 ( 0 , V_7 -> V_9 + V_10 + V_35 ) ;
V_9 = V_7 -> V_9 ;
F_4 ( V_137 -> V_139 , V_9 + V_60 ) ;
F_4 ( V_137 -> V_140 , V_9 + V_66 ) ;
F_4 ( V_137 -> V_141 , V_9 + V_142 ) ;
F_4 ( V_137 -> V_143 , V_9 + V_144 ) ;
F_4 ( V_137 -> V_145 , V_9 + V_146 ) ;
F_4 ( V_137 -> V_147 , V_9 + V_148 ) ;
V_9 = V_7 -> V_9 + V_10 ;
F_4 ( V_137 -> V_149 , V_9 + V_24 ) ;
F_4 ( V_137 -> V_150 , V_9 + V_37 ) ;
F_4 ( V_137 -> V_151 , V_9 + V_20 ) ;
F_4 ( V_137 -> V_152 , V_9 + V_35 ) ;
F_4 ( V_137 -> V_153 , V_9 + V_30 ) ;
F_4 ( V_137 -> V_154 , V_9 + V_38 ) ;
F_4 ( V_137 -> V_155 , V_9 + V_33 ) ;
F_4 ( V_137 -> V_156 , V_9 + V_40 ) ;
F_37 ( & V_7 -> V_58 , V_25 ) ;
V_7 -> V_138 = NULL ;
F_42 ( V_137 ) ;
return 0 ;
}
static int F_82 ( struct V_134 * V_158 )
{
struct V_82 * V_104 ;
int V_21 ;
V_104 = F_83 ( V_158 , V_98 , 0 ) ;
if ( ! V_104 )
return - V_29 ;
V_21 = F_84 ( V_158 , 0 ) ;
if ( V_21 < 0 )
return - V_159 ;
return F_53 ( & V_158 -> V_45 , V_104 , V_21 ) ;
}
static int F_85 ( struct V_134 * V_158 )
{
struct V_6 * V_7 = F_77 ( V_158 ) ;
if ( V_7 ) {
#ifdef F_86
F_42 ( V_7 -> V_138 ) ;
V_7 -> V_138 = NULL ;
#endif
F_71 ( V_7 ) ;
F_81 ( V_158 , NULL ) ;
}
return 0 ;
}
static inline struct V_6 * F_87 ( struct V_81 * V_133 )
{
return (struct V_6 * ) F_88 ( V_133 -> V_45 . V_83 ) ;
}
static unsigned int F_89 ( struct V_6 * V_7 )
{
unsigned int V_141 , V_160 , V_161 , V_162 ;
V_141 = F_3 ( V_7 -> V_9 + V_142 ) ;
V_160 = ( V_141 & 0x007f ) + 2 ;
V_161 = ( ( V_141 & 0x0f80 ) >> 7 ) + 2 ;
V_162 = V_163 [ ( V_141 & 0x3000 ) >> 12 ] ;
return 3686400 * V_160 / ( V_161 * V_162 ) ;
}
unsigned int F_90 ( struct V_81 * V_133 )
{
struct V_6 * V_7 = F_87 ( V_133 ) ;
return F_89 ( V_7 ) ;
}
void F_91 ( struct V_81 * V_133 , int V_164 )
{
struct V_6 * V_7 = F_87 ( V_133 ) ;
unsigned long V_25 ;
unsigned int V_124 ;
F_34 ( & V_7 -> V_58 , V_25 ) ;
V_124 = F_3 ( V_7 -> V_9 + V_60 ) ;
if ( V_164 == V_165 ) {
V_124 &= ~ V_166 ;
} else {
V_124 |= V_166 ;
}
F_4 ( V_124 , V_7 -> V_9 + V_60 ) ;
F_37 ( & V_7 -> V_58 , V_25 ) ;
}
int F_92 ( struct V_81 * V_133 , int V_167 )
{
struct V_6 * V_7 = F_87 ( V_133 ) ;
unsigned int div ;
if ( V_133 -> V_90 != V_168 )
return - V_29 ;
div = ( F_89 ( V_7 ) / 256 + V_167 / 2 ) / V_167 ;
if ( div == 0 )
div = 1 ;
if ( div > 128 )
div = 128 ;
F_4 ( div - 1 , V_7 -> V_9 + V_144 ) ;
return 0 ;
}
int F_93 ( struct V_81 * V_133 )
{
struct V_6 * V_7 = F_87 ( V_133 ) ;
unsigned long div ;
if ( V_133 -> V_90 != V_168 )
return - V_29 ;
div = F_3 ( V_7 -> V_9 + V_144 ) + 1 ;
return F_89 ( V_7 ) / ( 256 * div ) ;
}
void F_94 ( struct V_81 * V_133 ,
unsigned int V_169 , unsigned int V_170 ,
unsigned int V_171 )
{
struct V_6 * V_7 = F_87 ( V_133 ) ;
unsigned long V_25 ;
unsigned int V_124 ;
void T_1 * V_172 = V_7 -> V_9 + V_173 ;
#define F_95 ( T_3 , V_22 , V_170 ) \
if (mask) { \
val = sa1111_readl(port); \
val &= ~(mask); \
val |= (dir) & (mask); \
sa1111_writel(val, port); \
}
F_34 ( & V_7 -> V_58 , V_25 ) ;
F_95 ( V_172 + V_174 , V_169 & 15 , V_170 ) ;
F_95 ( V_172 + V_175 , ( V_169 >> 8 ) & 255 , V_170 >> 8 ) ;
F_95 ( V_172 + V_176 , ( V_169 >> 16 ) & 255 , V_170 >> 16 ) ;
F_95 ( V_172 + V_177 , V_169 & 15 , V_171 ) ;
F_95 ( V_172 + V_178 , ( V_169 >> 8 ) & 255 , V_171 >> 8 ) ;
F_95 ( V_172 + V_179 , ( V_169 >> 16 ) & 255 , V_171 >> 16 ) ;
F_37 ( & V_7 -> V_58 , V_25 ) ;
}
void F_96 ( struct V_81 * V_133 , unsigned int V_169 , unsigned int V_180 )
{
struct V_6 * V_7 = F_87 ( V_133 ) ;
unsigned long V_25 ;
unsigned int V_124 ;
void T_1 * V_172 = V_7 -> V_9 + V_173 ;
F_34 ( & V_7 -> V_58 , V_25 ) ;
F_95 ( V_172 + V_181 , V_169 & 15 , V_180 ) ;
F_95 ( V_172 + V_182 , ( V_169 >> 8 ) & 255 , V_180 >> 8 ) ;
F_95 ( V_172 + V_183 , ( V_169 >> 16 ) & 255 , V_180 >> 16 ) ;
F_37 ( & V_7 -> V_58 , V_25 ) ;
}
void F_97 ( struct V_81 * V_133 , unsigned int V_169 , unsigned int V_180 )
{
struct V_6 * V_7 = F_87 ( V_133 ) ;
unsigned long V_25 ;
unsigned int V_124 ;
void T_1 * V_172 = V_7 -> V_9 + V_173 ;
F_34 ( & V_7 -> V_58 , V_25 ) ;
F_95 ( V_172 + V_184 , V_169 & 15 , V_180 ) ;
F_95 ( V_172 + V_185 , ( V_169 >> 8 ) & 255 , V_180 >> 8 ) ;
F_95 ( V_172 + V_186 , ( V_169 >> 16 ) & 255 , V_180 >> 16 ) ;
F_37 ( & V_7 -> V_58 , V_25 ) ;
}
int F_98 ( struct V_81 * V_133 )
{
struct V_6 * V_7 = F_87 ( V_133 ) ;
unsigned long V_25 ;
unsigned int V_124 ;
int V_42 = 0 ;
if ( V_7 -> V_113 && V_7 -> V_113 -> V_187 )
V_42 = V_7 -> V_113 -> V_187 ( V_7 -> V_113 -> V_132 , V_133 -> V_90 ) ;
if ( V_42 == 0 ) {
F_34 ( & V_7 -> V_58 , V_25 ) ;
V_124 = F_3 ( V_7 -> V_9 + V_66 ) ;
F_4 ( V_124 | V_133 -> V_99 , V_7 -> V_9 + V_66 ) ;
F_37 ( & V_7 -> V_58 , V_25 ) ;
}
return V_42 ;
}
void F_99 ( struct V_81 * V_133 )
{
struct V_6 * V_7 = F_87 ( V_133 ) ;
unsigned long V_25 ;
unsigned int V_124 ;
F_34 ( & V_7 -> V_58 , V_25 ) ;
V_124 = F_3 ( V_7 -> V_9 + V_66 ) ;
F_4 ( V_124 & ~ V_133 -> V_99 , V_7 -> V_9 + V_66 ) ;
F_37 ( & V_7 -> V_58 , V_25 ) ;
if ( V_7 -> V_113 && V_7 -> V_113 -> V_188 )
V_7 -> V_113 -> V_188 ( V_7 -> V_113 -> V_132 , V_133 -> V_90 ) ;
}
static int F_100 ( struct V_79 * V_80 , struct V_189 * V_190 )
{
struct V_81 * V_45 = F_41 ( V_80 ) ;
struct V_191 * V_192 = F_101 ( V_190 ) ;
return ! ! ( V_45 -> V_90 & V_192 -> V_90 ) ;
}
static int F_102 ( struct V_79 * V_45 , T_2 V_135 )
{
struct V_81 * V_133 = F_41 ( V_45 ) ;
struct V_191 * V_192 = F_101 ( V_45 -> V_193 ) ;
int V_42 = 0 ;
if ( V_192 && V_192 -> V_194 )
V_42 = V_192 -> V_194 ( V_133 , V_135 ) ;
return V_42 ;
}
static int F_103 ( struct V_79 * V_45 )
{
struct V_81 * V_133 = F_41 ( V_45 ) ;
struct V_191 * V_192 = F_101 ( V_45 -> V_193 ) ;
int V_42 = 0 ;
if ( V_192 && V_192 -> V_195 )
V_42 = V_192 -> V_195 ( V_133 ) ;
return V_42 ;
}
static void F_104 ( struct V_79 * V_45 )
{
struct V_191 * V_192 = F_101 ( V_45 -> V_193 ) ;
if ( V_192 && V_192 -> V_196 )
V_192 -> V_196 ( F_41 ( V_45 ) ) ;
}
static int F_105 ( struct V_79 * V_45 )
{
struct V_81 * V_133 = F_41 ( V_45 ) ;
struct V_191 * V_192 = F_101 ( V_45 -> V_193 ) ;
int V_42 = - V_110 ;
if ( V_192 -> V_197 )
V_42 = V_192 -> V_197 ( V_133 ) ;
return V_42 ;
}
static int F_106 ( struct V_79 * V_45 )
{
struct V_81 * V_133 = F_41 ( V_45 ) ;
struct V_191 * V_192 = F_101 ( V_45 -> V_193 ) ;
int V_42 = 0 ;
if ( V_192 -> remove )
V_42 = V_192 -> remove ( V_133 ) ;
return V_42 ;
}
int F_107 ( struct V_191 * V_193 )
{
V_193 -> V_192 . V_91 = & V_92 ;
return F_108 ( & V_193 -> V_192 ) ;
}
void F_109 ( struct V_191 * V_193 )
{
F_110 ( & V_193 -> V_192 ) ;
}
static int F_111 ( struct V_79 * V_45 , T_4 V_198 , T_5 V_199 )
{
return ( F_112 () || F_113 () ) &&
( V_198 >= 0xc8000000 || ( V_198 + V_199 ) >= 0xc8000000 ) ;
}
static int F_114 ( struct V_200 * V_201 , unsigned long V_202 ,
void * V_132 )
{
struct V_81 * V_45 = F_41 ( V_132 ) ;
switch ( V_202 ) {
case V_203 :
if ( V_45 -> V_45 . V_76 && V_45 -> V_76 < 0xffffffffUL ) {
int V_42 = F_115 ( & V_45 -> V_45 , 1024 , 4096 ,
F_111 ) ;
if ( V_42 )
F_26 ( & V_45 -> V_45 , L_10 , V_42 ) ;
}
break;
case V_204 :
if ( V_45 -> V_45 . V_76 && V_45 -> V_76 < 0xffffffffUL )
F_116 ( & V_45 -> V_45 ) ;
break;
}
return V_205 ;
}
static int T_6 F_117 ( void )
{
int V_42 = F_118 ( & V_92 ) ;
#ifdef F_119
if ( V_42 == 0 )
F_120 ( & V_92 , & V_206 ) ;
#endif
if ( V_42 == 0 )
F_121 ( & V_207 ) ;
return V_42 ;
}
static void T_7 F_122 ( void )
{
F_123 ( & V_207 ) ;
#ifdef F_119
F_124 ( & V_92 , & V_206 ) ;
#endif
F_125 ( & V_92 ) ;
}
