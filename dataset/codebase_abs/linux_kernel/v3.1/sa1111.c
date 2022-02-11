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
static void F_23 ( struct V_7 * V_8 )
{
void T_1 * V_42 = V_8 -> V_10 + V_11 ;
unsigned int V_1 ;
F_24 ( V_8 -> V_43 + V_11 , 512 , L_3 ) ;
F_4 ( 0 , V_42 + V_21 ) ;
F_4 ( 0 , V_42 + V_36 ) ;
F_4 ( 0 , V_42 + V_34 ) ;
F_4 ( 0 , V_42 + V_41 ) ;
F_4 ( 0 , V_42 + V_24 ) ;
F_4 ( F_18 ( V_44 ) |
F_18 ( V_45 ) ,
V_42 + V_38 ) ;
F_4 ( ~ 0 , V_42 + V_12 ) ;
F_4 ( ~ 0 , V_42 + V_13 ) ;
for ( V_1 = V_46 ; V_1 <= V_47 ; V_1 ++ ) {
F_25 ( V_1 , & V_48 ,
V_49 ) ;
F_26 ( V_1 , V_8 ) ;
F_27 ( V_1 , V_50 | V_51 ) ;
}
for ( V_1 = V_52 ; V_1 <= V_53 ; V_1 ++ ) {
F_25 ( V_1 , & V_54 ,
V_49 ) ;
F_26 ( V_1 , V_8 ) ;
F_27 ( V_1 , V_50 | V_51 ) ;
}
F_28 ( V_8 -> V_1 , V_28 ) ;
F_29 ( V_8 -> V_1 , V_8 ) ;
F_30 ( V_8 -> V_1 , F_1 ) ;
}
static void F_31 ( struct V_7 * V_8 )
{
unsigned long V_26 , V_55 ;
F_32 ( & V_8 -> V_56 , V_26 ) ;
F_33 ( V_8 -> V_57 ) ;
V_55 = F_3 ( V_8 -> V_10 + V_58 ) ;
V_55 &= ~ V_59 ;
F_4 ( V_55 , V_8 -> V_10 + V_58 ) ;
V_55 |= V_60 | V_61 ;
F_4 ( V_55 , V_8 -> V_10 + V_58 ) ;
F_34 ( 100 ) ;
V_55 |= V_62 | V_63 ;
F_4 ( V_55 , V_8 -> V_10 + V_58 ) ;
F_34 ( 1 ) ;
F_4 ( 0 , V_8 -> V_10 + V_64 ) ;
F_35 ( & V_8 -> V_56 , V_26 ) ;
}
void
F_36 ( struct V_7 * V_8 , int V_65 , unsigned int V_66 ,
unsigned int V_67 )
{
unsigned int V_68 = V_69 | V_70 | F_37 ( V_66 , V_71 ) ;
if ( V_67 == 3 )
V_68 |= V_72 ;
F_4 ( V_68 , V_8 -> V_10 + V_73 ) ;
if ( V_8 -> V_74 -> V_75 )
* V_8 -> V_74 -> V_75 &= V_76 [ V_66 >> 2 ] ;
V_8 -> V_74 -> V_77 &= V_76 [ V_66 >> 2 ] ;
}
static int F_38 ( struct V_78 * V_74 , T_2 V_79 , T_3 V_80 )
{
return ( F_39 () || F_40 () ) &&
( V_79 >= 0xc8000000 || ( V_79 + V_80 ) >= 0xc8000000 ) ;
}
static void F_41 ( struct V_78 * V_81 )
{
struct V_82 * V_74 = F_42 ( V_81 ) ;
F_43 ( & V_74 -> V_83 ) ;
F_44 ( V_74 ) ;
}
static int
F_45 ( struct V_7 * V_8 , struct V_84 * V_85 ,
struct V_86 * V_87 )
{
struct V_82 * V_74 ;
int V_88 ;
V_74 = F_46 ( sizeof( struct V_82 ) , V_89 ) ;
if ( ! V_74 ) {
V_88 = - V_90 ;
goto V_91;
}
F_47 ( & V_74 -> V_74 , L_4 , V_87 -> V_92 ) ;
V_74 -> V_93 = V_87 -> V_93 ;
V_74 -> V_74 . V_85 = V_8 -> V_74 ;
V_74 -> V_74 . V_94 = & V_95 ;
V_74 -> V_74 . V_96 = F_41 ;
V_74 -> V_74 . V_77 = V_8 -> V_74 -> V_77 ;
V_74 -> V_83 . V_97 = V_8 -> V_43 + V_87 -> V_92 ;
V_74 -> V_83 . V_98 = V_74 -> V_83 . V_97 + 511 ;
V_74 -> V_83 . V_99 = F_48 ( & V_74 -> V_74 ) ;
V_74 -> V_83 . V_26 = V_100 ;
V_74 -> V_9 = V_8 -> V_10 + V_87 -> V_92 ;
V_74 -> V_101 = V_87 -> V_101 ;
memmove ( V_74 -> V_1 , V_87 -> V_1 , sizeof( V_74 -> V_1 ) ) ;
V_88 = F_49 ( V_85 , & V_74 -> V_83 ) ;
if ( V_88 ) {
F_14 ( L_5 ,
V_74 -> V_83 . V_99 ) ;
F_47 ( & V_74 -> V_74 , NULL ) ;
F_44 ( V_74 ) ;
goto V_91;
}
V_88 = F_50 ( & V_74 -> V_74 ) ;
if ( V_88 ) {
F_43 ( & V_74 -> V_83 ) ;
F_44 ( V_74 ) ;
goto V_91;
}
#ifdef F_51
if ( V_8 -> V_74 -> V_75 ) {
V_74 -> V_75 = * V_8 -> V_74 -> V_75 ;
V_74 -> V_74 . V_75 = & V_74 -> V_75 ;
if ( V_74 -> V_75 != 0xffffffffUL ) {
V_88 = F_52 ( & V_74 -> V_74 , 1024 , 4096 ,
F_38 ) ;
if ( V_88 ) {
F_53 ( & V_74 -> V_74 , L_6
L_7 ) ;
F_54 ( & V_74 -> V_74 ) ;
}
}
}
#endif
V_91:
return V_88 ;
}
static int T_4
F_55 ( struct V_78 * V_102 , struct V_84 * V_103 , int V_1 )
{
struct V_7 * V_8 ;
unsigned long V_104 ;
unsigned int V_105 ;
int V_6 , V_88 = - V_106 ;
V_8 = F_46 ( sizeof( struct V_7 ) , V_89 ) ;
if ( ! V_8 )
return - V_90 ;
V_8 -> V_57 = F_56 ( V_102 , L_8 ) ;
if ( F_57 ( V_8 -> V_57 ) ) {
V_88 = F_58 ( V_8 -> V_57 ) ;
goto V_107;
}
F_59 ( & V_8 -> V_56 ) ;
V_8 -> V_74 = V_102 ;
F_60 ( V_8 -> V_74 , V_8 ) ;
V_8 -> V_43 = V_103 -> V_97 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_10 = F_61 ( V_103 -> V_97 , V_108 * 2 ) ;
if ( ! V_8 -> V_10 ) {
V_88 = - V_90 ;
goto V_109;
}
V_104 = F_3 ( V_8 -> V_10 + V_110 ) ;
if ( ( V_104 & V_111 ) != V_112 ) {
F_14 ( V_113 L_9 , V_104 ) ;
V_88 = - V_106 ;
goto V_114;
}
F_14 ( V_115 L_10
L_11 ,
( V_104 & V_116 ) >> 4 , ( V_104 & V_117 ) ) ;
F_31 ( V_8 ) ;
#ifdef F_62
{
unsigned int V_118 ;
F_36 ( V_8 , 1 ,
F_63 ( V_119 , V_120 ) ,
F_63 ( V_119 , V_121 ) ) ;
V_118 = F_3 ( V_8 -> V_10 + V_64 ) ;
F_4 ( V_118 | V_122 , V_8 -> V_10 + V_64 ) ;
F_64 () ;
}
#endif
if ( V_8 -> V_1 != V_123 )
F_23 ( V_8 ) ;
V_124 = V_8 ;
V_105 = ~ 0 ;
if ( F_39 () || F_65 () ||
F_66 () )
V_105 &= ~ ( 1 << 4 ) ;
else
V_105 &= ~ ( 1 << 1 ) ;
for ( V_6 = 0 ; V_6 < F_67 ( V_125 ) ; V_6 ++ )
if ( V_105 & ( 1 << V_6 ) )
F_45 ( V_8 , V_103 , & V_125 [ V_6 ] ) ;
return 0 ;
V_114:
F_68 ( V_8 -> V_10 ) ;
V_109:
F_69 ( V_8 -> V_57 ) ;
V_107:
F_44 ( V_8 ) ;
return V_88 ;
}
static int F_70 ( struct V_78 * V_74 , void * V_126 )
{
F_54 ( V_74 ) ;
return 0 ;
}
static void F_71 ( struct V_7 * V_8 )
{
void T_1 * V_42 = V_8 -> V_10 + V_11 ;
F_72 ( V_8 -> V_74 , NULL , F_70 ) ;
F_4 ( 0 , V_42 + V_21 ) ;
F_4 ( 0 , V_42 + V_36 ) ;
F_4 ( 0 , V_42 + V_34 ) ;
F_4 ( 0 , V_42 + V_41 ) ;
F_73 ( V_8 -> V_57 ) ;
if ( V_8 -> V_1 != V_123 ) {
F_30 ( V_8 -> V_1 , NULL ) ;
F_29 ( V_8 -> V_1 , NULL ) ;
F_74 ( V_8 -> V_43 + V_11 , 512 ) ;
}
F_68 ( V_8 -> V_10 ) ;
F_69 ( V_8 -> V_57 ) ;
F_44 ( V_8 ) ;
}
static int F_75 ( struct V_127 * V_74 , T_5 V_128 )
{
struct V_7 * V_8 = F_76 ( V_74 ) ;
struct V_129 * V_130 ;
unsigned long V_26 ;
unsigned int V_118 ;
void T_1 * V_10 ;
V_130 = F_77 ( sizeof( struct V_129 ) , V_89 ) ;
if ( ! V_130 )
return - V_90 ;
V_8 -> V_131 = V_130 ;
F_32 ( & V_8 -> V_56 , V_26 ) ;
V_10 = V_8 -> V_10 ;
V_130 -> V_132 = F_3 ( V_10 + V_58 ) ;
V_130 -> V_133 = F_3 ( V_10 + V_64 ) ;
V_130 -> V_134 = F_3 ( V_10 + V_135 ) ;
V_130 -> V_136 = F_3 ( V_10 + V_137 ) ;
V_130 -> V_138 = F_3 ( V_10 + V_139 ) ;
V_130 -> V_140 = F_3 ( V_10 + V_141 ) ;
V_10 = V_8 -> V_10 + V_11 ;
V_130 -> V_142 = F_3 ( V_10 + V_24 ) ;
V_130 -> V_143 = F_3 ( V_10 + V_38 ) ;
V_130 -> V_144 = F_3 ( V_10 + V_21 ) ;
V_130 -> V_145 = F_3 ( V_10 + V_36 ) ;
V_130 -> V_146 = F_3 ( V_10 + V_31 ) ;
V_130 -> V_147 = F_3 ( V_10 + V_39 ) ;
V_130 -> V_148 = F_3 ( V_10 + V_34 ) ;
V_130 -> V_149 = F_3 ( V_10 + V_41 ) ;
V_118 = F_3 ( V_8 -> V_10 + V_58 ) ;
F_4 ( V_118 | V_150 , V_8 -> V_10 + V_58 ) ;
F_4 ( 0 , V_8 -> V_10 + V_139 ) ;
F_4 ( 0 , V_8 -> V_10 + V_141 ) ;
F_73 ( V_8 -> V_57 ) ;
F_35 ( & V_8 -> V_56 , V_26 ) ;
return 0 ;
}
static int F_78 ( struct V_127 * V_74 )
{
struct V_7 * V_8 = F_76 ( V_74 ) ;
struct V_129 * V_130 ;
unsigned long V_26 , V_104 ;
void T_1 * V_10 ;
V_130 = V_8 -> V_131 ;
if ( ! V_130 )
return 0 ;
V_104 = F_3 ( V_8 -> V_10 + V_110 ) ;
if ( ( V_104 & V_111 ) != V_112 ) {
F_71 ( V_8 ) ;
F_79 ( V_74 , NULL ) ;
F_44 ( V_130 ) ;
return 0 ;
}
F_31 ( V_8 ) ;
F_32 ( & V_8 -> V_56 , V_26 ) ;
F_4 ( 0 , V_8 -> V_10 + V_11 + V_21 ) ;
F_4 ( 0 , V_8 -> V_10 + V_11 + V_36 ) ;
V_10 = V_8 -> V_10 ;
F_4 ( V_130 -> V_132 , V_10 + V_58 ) ;
F_4 ( V_130 -> V_133 , V_10 + V_64 ) ;
F_4 ( V_130 -> V_134 , V_10 + V_135 ) ;
F_4 ( V_130 -> V_136 , V_10 + V_137 ) ;
F_4 ( V_130 -> V_138 , V_10 + V_139 ) ;
F_4 ( V_130 -> V_140 , V_10 + V_141 ) ;
V_10 = V_8 -> V_10 + V_11 ;
F_4 ( V_130 -> V_142 , V_10 + V_24 ) ;
F_4 ( V_130 -> V_143 , V_10 + V_38 ) ;
F_4 ( V_130 -> V_144 , V_10 + V_21 ) ;
F_4 ( V_130 -> V_145 , V_10 + V_36 ) ;
F_4 ( V_130 -> V_146 , V_10 + V_31 ) ;
F_4 ( V_130 -> V_147 , V_10 + V_39 ) ;
F_4 ( V_130 -> V_148 , V_10 + V_34 ) ;
F_4 ( V_130 -> V_149 , V_10 + V_41 ) ;
F_35 ( & V_8 -> V_56 , V_26 ) ;
V_8 -> V_131 = NULL ;
F_44 ( V_130 ) ;
return 0 ;
}
static int T_4 F_80 ( struct V_127 * V_151 )
{
struct V_84 * V_103 ;
int V_1 ;
V_103 = F_81 ( V_151 , V_100 , 0 ) ;
if ( ! V_103 )
return - V_30 ;
V_1 = F_82 ( V_151 , 0 ) ;
if ( V_1 < 0 )
return - V_152 ;
return F_55 ( & V_151 -> V_74 , V_103 , V_1 ) ;
}
static int F_83 ( struct V_127 * V_151 )
{
struct V_7 * V_8 = F_76 ( V_151 ) ;
if ( V_8 ) {
#ifdef F_84
F_44 ( V_8 -> V_131 ) ;
V_8 -> V_131 = NULL ;
#endif
F_71 ( V_8 ) ;
F_79 ( V_151 , NULL ) ;
}
return 0 ;
}
static inline struct V_7 * F_85 ( struct V_82 * V_153 )
{
return (struct V_7 * ) F_86 ( V_153 -> V_74 . V_85 ) ;
}
static unsigned int F_87 ( struct V_7 * V_8 )
{
unsigned int V_134 , V_154 , V_155 , V_156 ;
V_134 = F_3 ( V_8 -> V_10 + V_135 ) ;
V_154 = ( V_134 & 0x007f ) + 2 ;
V_155 = ( ( V_134 & 0x0f80 ) >> 7 ) + 2 ;
V_156 = V_157 [ ( V_134 & 0x3000 ) >> 12 ] ;
return 3686400 * V_154 / ( V_155 * V_156 ) ;
}
unsigned int F_88 ( struct V_82 * V_153 )
{
struct V_7 * V_8 = F_85 ( V_153 ) ;
return F_87 ( V_8 ) ;
}
void F_89 ( struct V_82 * V_153 , int V_158 )
{
struct V_7 * V_8 = F_85 ( V_153 ) ;
unsigned long V_26 ;
unsigned int V_118 ;
F_32 ( & V_8 -> V_56 , V_26 ) ;
V_118 = F_3 ( V_8 -> V_10 + V_58 ) ;
if ( V_158 == V_159 ) {
V_118 &= ~ V_160 ;
} else {
V_118 |= V_160 ;
}
F_4 ( V_118 , V_8 -> V_10 + V_58 ) ;
F_35 ( & V_8 -> V_56 , V_26 ) ;
}
int F_90 ( struct V_82 * V_153 , int V_161 )
{
struct V_7 * V_8 = F_85 ( V_153 ) ;
unsigned int div ;
if ( V_153 -> V_93 != V_162 )
return - V_30 ;
div = ( F_87 ( V_8 ) / 256 + V_161 / 2 ) / V_161 ;
if ( div == 0 )
div = 1 ;
if ( div > 128 )
div = 128 ;
F_4 ( div - 1 , V_8 -> V_10 + V_137 ) ;
return 0 ;
}
int F_91 ( struct V_82 * V_153 )
{
struct V_7 * V_8 = F_85 ( V_153 ) ;
unsigned long div ;
if ( V_153 -> V_93 != V_162 )
return - V_30 ;
div = F_3 ( V_8 -> V_10 + V_137 ) + 1 ;
return F_87 ( V_8 ) / ( 256 * div ) ;
}
void F_92 ( struct V_82 * V_153 ,
unsigned int V_163 , unsigned int V_164 ,
unsigned int V_165 )
{
struct V_7 * V_8 = F_85 ( V_153 ) ;
unsigned long V_26 ;
unsigned int V_118 ;
void T_1 * V_166 = V_8 -> V_10 + V_167 ;
#define F_93 ( T_6 , V_22 , V_164 ) \
if (mask) { \
val = sa1111_readl(port); \
val &= ~(mask); \
val |= (dir) & (mask); \
sa1111_writel(val, port); \
}
F_32 ( & V_8 -> V_56 , V_26 ) ;
F_93 ( V_166 + V_168 , V_163 & 15 , V_164 ) ;
F_93 ( V_166 + V_169 , ( V_163 >> 8 ) & 255 , V_164 >> 8 ) ;
F_93 ( V_166 + V_170 , ( V_163 >> 16 ) & 255 , V_164 >> 16 ) ;
F_93 ( V_166 + V_171 , V_163 & 15 , V_165 ) ;
F_93 ( V_166 + V_172 , ( V_163 >> 8 ) & 255 , V_165 >> 8 ) ;
F_93 ( V_166 + V_173 , ( V_163 >> 16 ) & 255 , V_165 >> 16 ) ;
F_35 ( & V_8 -> V_56 , V_26 ) ;
}
void F_94 ( struct V_82 * V_153 , unsigned int V_163 , unsigned int V_174 )
{
struct V_7 * V_8 = F_85 ( V_153 ) ;
unsigned long V_26 ;
unsigned int V_118 ;
void T_1 * V_166 = V_8 -> V_10 + V_167 ;
F_32 ( & V_8 -> V_56 , V_26 ) ;
F_93 ( V_166 + V_175 , V_163 & 15 , V_174 ) ;
F_93 ( V_166 + V_176 , ( V_163 >> 8 ) & 255 , V_174 >> 8 ) ;
F_93 ( V_166 + V_177 , ( V_163 >> 16 ) & 255 , V_174 >> 16 ) ;
F_35 ( & V_8 -> V_56 , V_26 ) ;
}
void F_95 ( struct V_82 * V_153 , unsigned int V_163 , unsigned int V_174 )
{
struct V_7 * V_8 = F_85 ( V_153 ) ;
unsigned long V_26 ;
unsigned int V_118 ;
void T_1 * V_166 = V_8 -> V_10 + V_167 ;
F_32 ( & V_8 -> V_56 , V_26 ) ;
F_93 ( V_166 + V_178 , V_163 & 15 , V_174 ) ;
F_93 ( V_166 + V_179 , ( V_163 >> 8 ) & 255 , V_174 >> 8 ) ;
F_93 ( V_166 + V_180 , ( V_163 >> 16 ) & 255 , V_174 >> 16 ) ;
F_35 ( & V_8 -> V_56 , V_26 ) ;
}
void F_96 ( struct V_82 * V_153 )
{
struct V_7 * V_8 = F_85 ( V_153 ) ;
unsigned long V_26 ;
unsigned int V_118 ;
F_32 ( & V_8 -> V_56 , V_26 ) ;
V_118 = F_3 ( V_8 -> V_10 + V_64 ) ;
F_4 ( V_118 | V_153 -> V_101 , V_8 -> V_10 + V_64 ) ;
F_35 ( & V_8 -> V_56 , V_26 ) ;
}
void F_97 ( struct V_82 * V_153 )
{
struct V_7 * V_8 = F_85 ( V_153 ) ;
unsigned long V_26 ;
unsigned int V_118 ;
F_32 ( & V_8 -> V_56 , V_26 ) ;
V_118 = F_3 ( V_8 -> V_10 + V_64 ) ;
F_4 ( V_118 & ~ V_153 -> V_101 , V_8 -> V_10 + V_64 ) ;
F_35 ( & V_8 -> V_56 , V_26 ) ;
}
static int F_98 ( struct V_78 * V_81 , struct V_181 * V_182 )
{
struct V_82 * V_74 = F_42 ( V_81 ) ;
struct V_183 * V_184 = F_99 ( V_182 ) ;
return V_74 -> V_93 == V_184 -> V_93 ;
}
static int F_100 ( struct V_78 * V_74 , T_5 V_128 )
{
struct V_82 * V_153 = F_42 ( V_74 ) ;
struct V_183 * V_184 = F_99 ( V_74 -> V_185 ) ;
int V_88 = 0 ;
if ( V_184 && V_184 -> V_186 )
V_88 = V_184 -> V_186 ( V_153 , V_128 ) ;
return V_88 ;
}
static int F_101 ( struct V_78 * V_74 )
{
struct V_82 * V_153 = F_42 ( V_74 ) ;
struct V_183 * V_184 = F_99 ( V_74 -> V_185 ) ;
int V_88 = 0 ;
if ( V_184 && V_184 -> V_187 )
V_88 = V_184 -> V_187 ( V_153 ) ;
return V_88 ;
}
static int F_102 ( struct V_78 * V_74 )
{
struct V_82 * V_153 = F_42 ( V_74 ) ;
struct V_183 * V_184 = F_99 ( V_74 -> V_185 ) ;
int V_88 = - V_106 ;
if ( V_184 -> V_188 )
V_88 = V_184 -> V_188 ( V_153 ) ;
return V_88 ;
}
static int F_103 ( struct V_78 * V_74 )
{
struct V_82 * V_153 = F_42 ( V_74 ) ;
struct V_183 * V_184 = F_99 ( V_74 -> V_185 ) ;
int V_88 = 0 ;
if ( V_184 -> remove )
V_88 = V_184 -> remove ( V_153 ) ;
return V_88 ;
}
int F_104 ( struct V_183 * V_185 )
{
V_185 -> V_184 . V_94 = & V_95 ;
return F_105 ( & V_185 -> V_184 ) ;
}
void F_106 ( struct V_183 * V_185 )
{
F_107 ( & V_185 -> V_184 ) ;
}
static int T_7 F_108 ( void )
{
int V_88 = F_109 ( & V_95 ) ;
if ( V_88 == 0 )
F_110 ( & V_189 ) ;
return V_88 ;
}
static void T_8 F_111 ( void )
{
F_112 ( & V_189 ) ;
F_113 ( & V_95 ) ;
}
