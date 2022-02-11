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
static T_2 F_7 ( struct V_13 * V_18 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
return F_9 ( ( V_18 -> V_19 - V_7 -> V_16 ) & 31 ) ;
}
static int F_10 ( struct V_13 * V_18 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
return ( ( V_18 -> V_19 - V_7 -> V_16 ) / 32 ) * 4 ;
}
static void F_11 ( struct V_13 * V_18 )
{
}
static void F_12 ( struct V_13 * V_18 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 + F_10 ( V_18 ) ;
T_2 V_20 ;
V_20 = F_3 ( V_8 + V_21 ) ;
V_20 &= ~ F_7 ( V_18 ) ;
F_4 ( V_20 , V_8 + V_21 ) ;
}
static void F_13 ( struct V_13 * V_18 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 + F_10 ( V_18 ) ;
T_2 V_20 ;
V_20 = F_3 ( V_8 + V_21 ) ;
V_20 |= F_7 ( V_18 ) ;
F_4 ( V_20 , V_8 + V_21 ) ;
}
static int F_14 ( struct V_13 * V_18 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 + F_10 ( V_18 ) ;
T_2 V_22 , V_23 = F_7 ( V_18 ) ;
int V_5 ;
V_22 = F_3 ( V_8 + V_24 ) ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
F_4 ( V_22 ^ V_23 , V_8 + V_24 ) ;
F_4 ( V_22 , V_8 + V_24 ) ;
if ( F_3 ( V_8 + V_11 ) & V_23 )
break;
}
if ( V_5 == 8 )
F_15 ( L_1 ,
V_18 -> V_19 ) ;
return V_5 == 8 ? - 1 : 0 ;
}
static int F_16 ( struct V_13 * V_18 , unsigned int V_25 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 + F_10 ( V_18 ) ;
T_2 V_22 , V_23 = F_7 ( V_18 ) ;
if ( V_25 == V_26 )
return 0 ;
if ( ( ! ( V_25 & V_27 ) ^ ! ( V_25 & V_28 ) ) == 0 )
return - V_29 ;
V_22 = F_3 ( V_8 + V_24 ) ;
if ( V_25 & V_27 )
V_22 &= ~ V_23 ;
else
V_22 |= V_23 ;
F_4 ( V_22 , V_8 + V_24 ) ;
F_4 ( V_22 , V_8 + V_30 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_18 , unsigned int V_31 )
{
struct V_6 * V_7 = F_8 ( V_18 ) ;
void T_1 * V_8 = V_7 -> V_9 + V_10 + F_10 ( V_18 ) ;
T_2 V_32 , V_23 = F_7 ( V_18 ) ;
V_32 = F_3 ( V_8 + V_33 ) ;
if ( V_31 )
V_32 |= V_23 ;
else
V_32 &= ~ V_23 ;
F_4 ( V_32 , V_8 + V_33 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , unsigned V_16 )
{
void T_1 * V_34 = V_7 -> V_9 + V_10 ;
unsigned V_5 , V_19 ;
int V_35 ;
F_19 ( V_7 -> V_36 + V_10 , 512 , L_2 ) ;
V_35 = F_20 ( - 1 , V_16 , V_37 , - 1 ) ;
if ( V_35 <= 0 ) {
F_21 ( V_7 -> V_38 , L_3 ,
V_37 , V_35 ) ;
if ( V_35 == 0 )
V_35 = - V_29 ;
return V_35 ;
}
V_7 -> V_16 = V_35 ;
F_4 ( 0 , V_34 + V_21 ) ;
F_4 ( 0 , V_34 + V_39 ) ;
F_4 ( 0 , V_34 + V_33 ) ;
F_4 ( 0 , V_34 + V_40 ) ;
F_4 ( 0 , V_34 + V_24 ) ;
F_4 ( F_9 ( V_41 & 31 ) |
F_9 ( V_42 & 31 ) ,
V_34 + V_43 ) ;
F_4 ( ~ 0 , V_34 + V_11 ) ;
F_4 ( ~ 0 , V_34 + V_12 ) ;
for ( V_5 = V_44 ; V_5 <= V_45 ; V_5 ++ ) {
V_19 = V_7 -> V_16 + V_5 ;
F_22 ( V_19 , & V_46 , V_47 ) ;
F_23 ( V_19 , V_7 ) ;
F_24 ( V_19 , V_48 | V_49 ) ;
}
for ( V_5 = V_50 ; V_5 <= V_51 ; V_5 ++ ) {
V_19 = V_7 -> V_16 + V_5 ;
F_22 ( V_19 , & V_46 , V_47 ) ;
F_23 ( V_19 , V_7 ) ;
F_24 ( V_19 , V_48 | V_49 ) ;
}
F_25 ( V_7 -> V_19 , V_27 ) ;
F_26 ( V_7 -> V_19 , F_1 ,
V_7 ) ;
F_27 ( V_7 -> V_38 , L_4 ,
V_7 -> V_16 , V_7 -> V_16 + V_37 - 1 ) ;
return 0 ;
}
static void F_28 ( struct V_6 * V_7 )
{
void T_1 * V_34 = V_7 -> V_9 + V_10 ;
F_4 ( 0 , V_34 + V_21 ) ;
F_4 ( 0 , V_34 + V_39 ) ;
F_4 ( 0 , V_34 + V_33 ) ;
F_4 ( 0 , V_34 + V_40 ) ;
if ( V_7 -> V_19 != V_52 ) {
F_26 ( V_7 -> V_19 , NULL , NULL ) ;
F_29 ( V_7 -> V_16 , V_37 ) ;
F_30 ( V_7 -> V_36 + V_10 , 512 ) ;
}
}
static struct V_6 * F_31 ( struct V_53 * V_54 )
{
return F_32 ( V_54 , struct V_6 , V_54 ) ;
}
static void T_1 * F_33 ( struct V_6 * V_7 , unsigned V_55 )
{
void T_1 * V_56 = V_7 -> V_9 + V_57 ;
if ( V_55 < 4 )
return V_56 + V_58 ;
if ( V_55 < 10 )
return V_56 + V_59 ;
if ( V_55 < 18 )
return V_56 + V_60 ;
return NULL ;
}
static T_2 F_34 ( unsigned V_55 )
{
if ( V_55 < 4 )
return F_9 ( V_55 ) ;
if ( V_55 < 10 )
return F_9 ( V_55 - 4 ) ;
if ( V_55 < 18 )
return F_9 ( V_55 - 10 ) ;
return 0 ;
}
static void F_35 ( void T_1 * V_56 , T_2 V_23 , T_2 V_61 )
{
T_2 V_62 ;
V_62 = F_36 ( V_56 ) ;
V_62 &= ~ V_23 ;
V_62 |= V_23 & V_61 ;
F_37 ( V_62 , V_56 ) ;
}
static int F_38 ( struct V_53 * V_54 , unsigned V_55 )
{
struct V_6 * V_7 = F_31 ( V_54 ) ;
void T_1 * V_56 = F_33 ( V_7 , V_55 ) ;
T_2 V_23 = F_34 ( V_55 ) ;
return ! ! ( F_36 ( V_56 + V_63 ) & V_23 ) ;
}
static int F_39 ( struct V_53 * V_54 , unsigned V_55 )
{
struct V_6 * V_7 = F_31 ( V_54 ) ;
unsigned long V_25 ;
void T_1 * V_56 = F_33 ( V_7 , V_55 ) ;
T_2 V_23 = F_34 ( V_55 ) ;
F_40 ( & V_7 -> V_64 , V_25 ) ;
F_35 ( V_56 + V_63 , V_23 , V_23 ) ;
F_35 ( V_56 + V_65 , V_23 , V_23 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
return 0 ;
}
static int F_42 ( struct V_53 * V_54 , unsigned V_55 ,
int V_66 )
{
struct V_6 * V_7 = F_31 ( V_54 ) ;
unsigned long V_25 ;
void T_1 * V_56 = F_33 ( V_7 , V_55 ) ;
T_2 V_23 = F_34 ( V_55 ) ;
F_40 ( & V_7 -> V_64 , V_25 ) ;
F_35 ( V_56 + V_67 , V_23 , V_66 ? V_23 : 0 ) ;
F_35 ( V_56 + V_68 , V_23 , V_66 ? V_23 : 0 ) ;
F_35 ( V_56 + V_63 , V_23 , 0 ) ;
F_35 ( V_56 + V_65 , V_23 , 0 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
return 0 ;
}
static int F_43 ( struct V_53 * V_54 , unsigned V_55 )
{
struct V_6 * V_7 = F_31 ( V_54 ) ;
void T_1 * V_56 = F_33 ( V_7 , V_55 ) ;
T_2 V_23 = F_34 ( V_55 ) ;
return ! ! ( F_36 ( V_56 + V_69 ) & V_23 ) ;
}
static void F_44 ( struct V_53 * V_54 , unsigned V_55 , int V_66 )
{
struct V_6 * V_7 = F_31 ( V_54 ) ;
unsigned long V_25 ;
void T_1 * V_56 = F_33 ( V_7 , V_55 ) ;
T_2 V_23 = F_34 ( V_55 ) ;
F_40 ( & V_7 -> V_64 , V_25 ) ;
F_35 ( V_56 + V_67 , V_23 , V_66 ? V_23 : 0 ) ;
F_35 ( V_56 + V_68 , V_23 , V_66 ? V_23 : 0 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
}
static void F_45 ( struct V_53 * V_54 , unsigned long * V_23 ,
unsigned long * V_70 )
{
struct V_6 * V_7 = F_31 ( V_54 ) ;
unsigned long V_25 ;
void T_1 * V_56 = V_7 -> V_9 + V_57 ;
T_2 V_71 , V_62 ;
V_71 = * V_23 ;
V_62 = * V_70 ;
F_40 ( & V_7 -> V_64 , V_25 ) ;
F_35 ( V_56 + V_72 , V_71 & 15 , V_62 ) ;
F_35 ( V_56 + V_73 , V_71 & 15 , V_62 ) ;
F_35 ( V_56 + V_74 , ( V_71 >> 4 ) & 255 , V_62 >> 4 ) ;
F_35 ( V_56 + V_75 , ( V_71 >> 4 ) & 255 , V_62 >> 4 ) ;
F_35 ( V_56 + V_76 , ( V_71 >> 12 ) & 255 , V_62 >> 12 ) ;
F_35 ( V_56 + V_77 , ( V_71 >> 12 ) & 255 , V_62 >> 12 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
}
static int F_46 ( struct V_53 * V_54 , unsigned V_55 )
{
struct V_6 * V_7 = F_31 ( V_54 ) ;
return V_7 -> V_16 + V_55 ;
}
static int F_47 ( struct V_6 * V_7 )
{
V_7 -> V_54 . V_78 = L_5 ;
V_7 -> V_54 . V_79 = V_7 -> V_38 ;
V_7 -> V_54 . V_80 = V_81 ;
V_7 -> V_54 . V_82 = F_38 ;
V_7 -> V_54 . V_83 = F_39 ;
V_7 -> V_54 . V_84 = F_42 ;
V_7 -> V_54 . V_85 = F_43 ;
V_7 -> V_54 . V_61 = F_44 ;
V_7 -> V_54 . V_86 = F_45 ;
V_7 -> V_54 . V_87 = F_46 ;
V_7 -> V_54 . V_9 = - 1 ;
V_7 -> V_54 . V_88 = 18 ;
return F_48 ( V_7 -> V_38 , & V_7 -> V_54 , V_7 ) ;
}
static void F_49 ( struct V_6 * V_7 )
{
unsigned long V_25 , V_89 ;
F_40 ( & V_7 -> V_64 , V_25 ) ;
F_50 ( V_7 -> V_90 ) ;
V_89 = F_3 ( V_7 -> V_9 + V_91 ) ;
V_89 &= ~ V_92 ;
F_4 ( V_89 , V_7 -> V_9 + V_91 ) ;
V_89 |= V_93 | V_94 ;
F_4 ( V_89 , V_7 -> V_9 + V_91 ) ;
F_51 ( 100 ) ;
V_89 |= V_95 | V_96 ;
F_4 ( V_89 , V_7 -> V_9 + V_91 ) ;
F_51 ( 1 ) ;
F_4 ( 0 , V_7 -> V_9 + V_97 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
}
void
F_52 ( struct V_6 * V_7 , int V_98 , unsigned int V_99 ,
unsigned int V_100 )
{
unsigned int V_101 = V_102 | V_103 | F_53 ( V_99 , V_104 ) ;
if ( V_100 == 3 )
V_101 |= V_105 ;
F_4 ( V_101 , V_7 -> V_9 + V_106 ) ;
if ( V_7 -> V_38 -> V_107 )
* V_7 -> V_38 -> V_107 &= V_108 [ V_99 >> 2 ] ;
V_7 -> V_38 -> V_109 &= V_108 [ V_99 >> 2 ] ;
}
static void F_54 ( struct V_110 * V_111 )
{
struct V_112 * V_38 = F_55 ( V_111 ) ;
F_56 ( V_38 ) ;
}
static int
F_57 ( struct V_6 * V_7 , struct V_113 * V_79 ,
struct V_114 * V_115 )
{
struct V_112 * V_38 ;
unsigned V_5 ;
int V_35 ;
V_38 = F_58 ( sizeof( struct V_112 ) , V_116 ) ;
if ( ! V_38 ) {
V_35 = - V_117 ;
goto V_118;
}
F_59 ( & V_38 -> V_38 ) ;
F_60 ( & V_38 -> V_38 , L_6 , V_115 -> V_55 ) ;
V_38 -> V_119 = V_115 -> V_119 ;
V_38 -> V_38 . V_79 = V_7 -> V_38 ;
V_38 -> V_38 . V_120 = & V_121 ;
V_38 -> V_38 . V_122 = F_54 ;
V_38 -> V_123 . V_124 = V_7 -> V_36 + V_115 -> V_55 ;
V_38 -> V_123 . V_125 = V_38 -> V_123 . V_124 + 511 ;
V_38 -> V_123 . V_126 = F_61 ( & V_38 -> V_38 ) ;
V_38 -> V_123 . V_25 = V_127 ;
V_38 -> V_8 = V_7 -> V_9 + V_115 -> V_55 ;
V_38 -> V_128 = V_115 -> V_128 ;
for ( V_5 = 0 ; V_5 < F_62 ( V_115 -> V_19 ) ; V_5 ++ )
V_38 -> V_19 [ V_5 ] = V_7 -> V_16 + V_115 -> V_19 [ V_5 ] ;
if ( V_115 -> V_129 && V_7 -> V_38 -> V_107 ) {
V_38 -> V_107 = * V_7 -> V_38 -> V_107 ;
V_38 -> V_38 . V_107 = & V_38 -> V_107 ;
V_38 -> V_38 . V_109 = V_7 -> V_38 -> V_109 ;
}
V_35 = F_63 ( V_79 , & V_38 -> V_123 ) ;
if ( V_35 ) {
F_21 ( V_7 -> V_38 , L_7 ,
V_38 -> V_123 . V_126 ) ;
goto V_130;
}
V_35 = F_64 ( & V_38 -> V_38 ) ;
if ( V_35 )
goto V_131;
return 0 ;
V_131:
F_65 ( & V_38 -> V_123 ) ;
V_130:
F_66 ( & V_38 -> V_38 ) ;
V_118:
return V_35 ;
}
static int F_67 ( struct V_110 * V_132 , struct V_113 * V_133 , int V_19 )
{
struct V_134 * V_135 = V_132 -> V_136 ;
struct V_6 * V_7 ;
unsigned long V_137 ;
unsigned int V_138 ;
int V_5 , V_35 = - V_139 ;
if ( ! V_135 )
return - V_29 ;
V_7 = F_68 ( V_132 , sizeof( struct V_6 ) , V_116 ) ;
if ( ! V_7 )
return - V_117 ;
V_7 -> V_90 = F_69 ( V_132 , L_8 ) ;
if ( F_70 ( V_7 -> V_90 ) )
return F_71 ( V_7 -> V_90 ) ;
V_35 = F_72 ( V_7 -> V_90 ) ;
if ( V_35 )
return V_35 ;
F_73 ( & V_7 -> V_64 ) ;
V_7 -> V_38 = V_132 ;
F_74 ( V_7 -> V_38 , V_7 ) ;
V_7 -> V_140 = V_135 ;
V_7 -> V_36 = V_133 -> V_124 ;
V_7 -> V_19 = V_19 ;
V_7 -> V_9 = F_75 ( V_133 -> V_124 , V_141 * 2 ) ;
if ( ! V_7 -> V_9 ) {
V_35 = - V_117 ;
goto V_142;
}
V_137 = F_3 ( V_7 -> V_9 + V_143 ) ;
if ( ( V_137 & V_144 ) != V_145 ) {
F_76 ( V_146 L_9 , V_137 ) ;
V_35 = - V_139 ;
goto V_147;
}
F_77 ( L_10 ,
( V_137 & V_148 ) >> 4 , V_137 & V_149 ) ;
F_49 ( V_7 ) ;
if ( V_7 -> V_19 != V_52 ) {
V_35 = F_18 ( V_7 , V_135 -> V_16 ) ;
if ( V_35 )
goto V_150;
}
V_35 = F_47 ( V_7 ) ;
if ( V_35 )
goto V_151;
#ifdef F_78
{
unsigned int V_62 ;
F_52 ( V_7 , 1 ,
F_79 ( V_152 , V_153 ) ,
F_79 ( V_152 , V_154 ) ) ;
V_62 = F_3 ( V_7 -> V_9 + V_97 ) ;
F_4 ( V_62 | V_155 , V_7 -> V_9 + V_97 ) ;
F_80 () ;
}
#endif
V_156 = V_7 ;
V_138 = ~ 0 ;
if ( V_135 )
V_138 &= ~ V_135 -> V_157 ;
for ( V_5 = 0 ; V_5 < F_62 ( V_158 ) ; V_5 ++ )
if ( V_158 [ V_5 ] . V_119 & V_138 )
F_57 ( V_7 , V_133 , & V_158 [ V_5 ] ) ;
return 0 ;
V_151:
F_28 ( V_7 ) ;
V_150:
F_81 ( V_7 -> V_90 ) ;
V_147:
F_82 ( V_7 -> V_9 ) ;
V_142:
F_83 ( V_7 -> V_90 ) ;
return V_35 ;
}
static int F_84 ( struct V_110 * V_38 , void * V_159 )
{
struct V_112 * V_160 = F_55 ( V_38 ) ;
if ( V_38 -> V_120 != & V_121 )
return 0 ;
F_85 ( & V_160 -> V_38 ) ;
F_65 ( & V_160 -> V_123 ) ;
F_66 ( & V_160 -> V_38 ) ;
return 0 ;
}
static void F_86 ( struct V_6 * V_7 )
{
F_87 ( V_7 -> V_38 , NULL , F_84 ) ;
F_28 ( V_7 ) ;
F_81 ( V_7 -> V_90 ) ;
F_83 ( V_7 -> V_90 ) ;
F_82 ( V_7 -> V_9 ) ;
}
static int F_88 ( struct V_110 * V_38 )
{
struct V_6 * V_7 = F_89 ( V_38 ) ;
struct V_161 * V_162 ;
unsigned long V_25 ;
unsigned int V_62 ;
void T_1 * V_9 ;
V_162 = F_90 ( sizeof( struct V_161 ) , V_116 ) ;
if ( ! V_162 )
return - V_117 ;
V_7 -> V_163 = V_162 ;
F_40 ( & V_7 -> V_64 , V_25 ) ;
V_9 = V_7 -> V_9 ;
V_162 -> V_164 = F_3 ( V_9 + V_91 ) ;
V_162 -> V_165 = F_3 ( V_9 + V_97 ) ;
V_162 -> V_166 = F_3 ( V_9 + V_167 ) ;
V_162 -> V_168 = F_3 ( V_9 + V_169 ) ;
V_162 -> V_170 = F_3 ( V_9 + V_171 ) ;
V_162 -> V_172 = F_3 ( V_9 + V_173 ) ;
F_4 ( 0 , V_7 -> V_9 + V_171 ) ;
F_4 ( 0 , V_7 -> V_9 + V_173 ) ;
V_9 = V_7 -> V_9 + V_10 ;
V_162 -> V_174 = F_3 ( V_9 + V_24 ) ;
V_162 -> V_175 = F_3 ( V_9 + V_43 ) ;
V_162 -> V_176 = F_3 ( V_9 + V_21 ) ;
V_162 -> V_177 = F_3 ( V_9 + V_39 ) ;
V_162 -> V_178 = F_3 ( V_9 + V_30 ) ;
V_162 -> V_179 = F_3 ( V_9 + V_180 ) ;
V_162 -> V_181 = F_3 ( V_9 + V_33 ) ;
V_162 -> V_182 = F_3 ( V_9 + V_40 ) ;
V_62 = F_3 ( V_7 -> V_9 + V_91 ) ;
F_4 ( V_62 | V_183 , V_7 -> V_9 + V_91 ) ;
F_81 ( V_7 -> V_90 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
#ifdef F_78
F_91 () ;
#endif
return 0 ;
}
static int F_92 ( struct V_110 * V_38 )
{
struct V_6 * V_7 = F_89 ( V_38 ) ;
struct V_161 * V_162 ;
unsigned long V_25 , V_137 ;
void T_1 * V_9 ;
V_162 = V_7 -> V_163 ;
if ( ! V_162 )
return 0 ;
V_137 = F_3 ( V_7 -> V_9 + V_143 ) ;
if ( ( V_137 & V_144 ) != V_145 ) {
F_86 ( V_7 ) ;
F_74 ( V_38 , NULL ) ;
F_56 ( V_162 ) ;
return 0 ;
}
F_49 ( V_7 ) ;
#ifdef F_78
F_80 () ;
#endif
F_40 ( & V_7 -> V_64 , V_25 ) ;
F_4 ( 0 , V_7 -> V_9 + V_10 + V_21 ) ;
F_4 ( 0 , V_7 -> V_9 + V_10 + V_39 ) ;
V_9 = V_7 -> V_9 ;
F_4 ( V_162 -> V_164 , V_9 + V_91 ) ;
F_4 ( V_162 -> V_165 , V_9 + V_97 ) ;
F_4 ( V_162 -> V_166 , V_9 + V_167 ) ;
F_4 ( V_162 -> V_168 , V_9 + V_169 ) ;
F_4 ( V_162 -> V_170 , V_9 + V_171 ) ;
F_4 ( V_162 -> V_172 , V_9 + V_173 ) ;
V_9 = V_7 -> V_9 + V_10 ;
F_4 ( V_162 -> V_174 , V_9 + V_24 ) ;
F_4 ( V_162 -> V_175 , V_9 + V_43 ) ;
F_4 ( V_162 -> V_176 , V_9 + V_21 ) ;
F_4 ( V_162 -> V_177 , V_9 + V_39 ) ;
F_4 ( V_162 -> V_178 , V_9 + V_30 ) ;
F_4 ( V_162 -> V_179 , V_9 + V_180 ) ;
F_4 ( V_162 -> V_181 , V_9 + V_33 ) ;
F_4 ( V_162 -> V_182 , V_9 + V_40 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
V_7 -> V_163 = NULL ;
F_56 ( V_162 ) ;
return 0 ;
}
static int F_93 ( struct V_184 * V_185 )
{
struct V_113 * V_133 ;
int V_19 ;
V_133 = F_94 ( V_185 , V_127 , 0 ) ;
if ( ! V_133 )
return - V_29 ;
V_19 = F_95 ( V_185 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_67 ( & V_185 -> V_38 , V_133 , V_19 ) ;
}
static int F_96 ( struct V_184 * V_185 )
{
struct V_6 * V_7 = F_97 ( V_185 ) ;
if ( V_7 ) {
#ifdef F_98
F_56 ( V_7 -> V_163 ) ;
V_7 -> V_163 = NULL ;
#endif
F_86 ( V_7 ) ;
F_99 ( V_185 , NULL ) ;
}
return 0 ;
}
static inline struct V_6 * F_100 ( struct V_112 * V_160 )
{
return (struct V_6 * ) F_89 ( V_160 -> V_38 . V_79 ) ;
}
static unsigned int F_101 ( struct V_6 * V_7 )
{
unsigned int V_166 , V_186 , V_187 , V_188 ;
V_166 = F_3 ( V_7 -> V_9 + V_167 ) ;
V_186 = ( V_166 & 0x007f ) + 2 ;
V_187 = ( ( V_166 & 0x0f80 ) >> 7 ) + 2 ;
V_188 = V_189 [ ( V_166 & 0x3000 ) >> 12 ] ;
return 3686400 * V_186 / ( V_187 * V_188 ) ;
}
unsigned int F_102 ( struct V_112 * V_160 )
{
struct V_6 * V_7 = F_100 ( V_160 ) ;
return F_101 ( V_7 ) ;
}
void F_103 ( struct V_112 * V_160 , int V_190 )
{
struct V_6 * V_7 = F_100 ( V_160 ) ;
unsigned long V_25 ;
unsigned int V_62 ;
F_40 ( & V_7 -> V_64 , V_25 ) ;
V_62 = F_3 ( V_7 -> V_9 + V_91 ) ;
if ( V_190 == V_191 ) {
V_62 &= ~ V_192 ;
} else {
V_62 |= V_192 ;
}
F_4 ( V_62 , V_7 -> V_9 + V_91 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
}
int F_104 ( struct V_112 * V_160 , int V_193 )
{
struct V_6 * V_7 = F_100 ( V_160 ) ;
unsigned int div ;
if ( V_160 -> V_119 != V_194 )
return - V_29 ;
div = ( F_101 ( V_7 ) / 256 + V_193 / 2 ) / V_193 ;
if ( div == 0 )
div = 1 ;
if ( div > 128 )
div = 128 ;
F_4 ( div - 1 , V_7 -> V_9 + V_169 ) ;
return 0 ;
}
int F_105 ( struct V_112 * V_160 )
{
struct V_6 * V_7 = F_100 ( V_160 ) ;
unsigned long div ;
if ( V_160 -> V_119 != V_194 )
return - V_29 ;
div = F_3 ( V_7 -> V_9 + V_169 ) + 1 ;
return F_101 ( V_7 ) / ( 256 * div ) ;
}
void F_106 ( struct V_112 * V_160 ,
unsigned int V_70 , unsigned int V_195 ,
unsigned int V_196 )
{
struct V_6 * V_7 = F_100 ( V_160 ) ;
unsigned long V_25 ;
unsigned int V_62 ;
void T_1 * V_197 = V_7 -> V_9 + V_57 ;
#define F_107 ( T_3 , V_23 , V_195 ) \
if (mask) { \
val = sa1111_readl(port); \
val &= ~(mask); \
val |= (dir) & (mask); \
sa1111_writel(val, port); \
}
F_40 ( & V_7 -> V_64 , V_25 ) ;
F_107 ( V_197 + V_58 , V_70 & 15 , V_195 ) ;
F_107 ( V_197 + V_59 , ( V_70 >> 8 ) & 255 , V_195 >> 8 ) ;
F_107 ( V_197 + V_60 , ( V_70 >> 16 ) & 255 , V_195 >> 16 ) ;
F_107 ( V_197 + V_198 , V_70 & 15 , V_196 ) ;
F_107 ( V_197 + V_199 , ( V_70 >> 8 ) & 255 , V_196 >> 8 ) ;
F_107 ( V_197 + V_200 , ( V_70 >> 16 ) & 255 , V_196 >> 16 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
}
void F_108 ( struct V_112 * V_160 , unsigned int V_70 , unsigned int V_201 )
{
struct V_6 * V_7 = F_100 ( V_160 ) ;
unsigned long V_25 ;
unsigned int V_62 ;
void T_1 * V_197 = V_7 -> V_9 + V_57 ;
F_40 ( & V_7 -> V_64 , V_25 ) ;
F_107 ( V_197 + V_72 , V_70 & 15 , V_201 ) ;
F_107 ( V_197 + V_74 , ( V_70 >> 8 ) & 255 , V_201 >> 8 ) ;
F_107 ( V_197 + V_76 , ( V_70 >> 16 ) & 255 , V_201 >> 16 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
}
void F_109 ( struct V_112 * V_160 , unsigned int V_70 , unsigned int V_201 )
{
struct V_6 * V_7 = F_100 ( V_160 ) ;
unsigned long V_25 ;
unsigned int V_62 ;
void T_1 * V_197 = V_7 -> V_9 + V_57 ;
F_40 ( & V_7 -> V_64 , V_25 ) ;
F_107 ( V_197 + V_73 , V_70 & 15 , V_201 ) ;
F_107 ( V_197 + V_75 , ( V_70 >> 8 ) & 255 , V_201 >> 8 ) ;
F_107 ( V_197 + V_77 , ( V_70 >> 16 ) & 255 , V_201 >> 16 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
}
int F_110 ( struct V_112 * V_160 )
{
struct V_6 * V_7 = F_100 ( V_160 ) ;
unsigned long V_25 ;
unsigned int V_62 ;
int V_35 = 0 ;
if ( V_7 -> V_140 && V_7 -> V_140 -> V_202 )
V_35 = V_7 -> V_140 -> V_202 ( V_7 -> V_140 -> V_159 , V_160 -> V_119 ) ;
if ( V_35 == 0 ) {
F_40 ( & V_7 -> V_64 , V_25 ) ;
V_62 = F_3 ( V_7 -> V_9 + V_97 ) ;
F_4 ( V_62 | V_160 -> V_128 , V_7 -> V_9 + V_97 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
}
return V_35 ;
}
void F_111 ( struct V_112 * V_160 )
{
struct V_6 * V_7 = F_100 ( V_160 ) ;
unsigned long V_25 ;
unsigned int V_62 ;
F_40 ( & V_7 -> V_64 , V_25 ) ;
V_62 = F_3 ( V_7 -> V_9 + V_97 ) ;
F_4 ( V_62 & ~ V_160 -> V_128 , V_7 -> V_9 + V_97 ) ;
F_41 ( & V_7 -> V_64 , V_25 ) ;
if ( V_7 -> V_140 && V_7 -> V_140 -> V_203 )
V_7 -> V_140 -> V_203 ( V_7 -> V_140 -> V_159 , V_160 -> V_119 ) ;
}
int F_112 ( struct V_112 * V_160 , unsigned V_204 )
{
if ( V_204 >= F_62 ( V_160 -> V_19 ) )
return - V_29 ;
return V_160 -> V_19 [ V_204 ] ;
}
static int F_113 ( struct V_110 * V_111 , struct V_205 * V_206 )
{
struct V_112 * V_38 = F_55 ( V_111 ) ;
struct V_207 * V_208 = F_114 ( V_206 ) ;
return ! ! ( V_38 -> V_119 & V_208 -> V_119 ) ;
}
static int F_115 ( struct V_110 * V_38 , T_4 V_209 )
{
struct V_112 * V_160 = F_55 ( V_38 ) ;
struct V_207 * V_208 = F_114 ( V_38 -> V_210 ) ;
int V_35 = 0 ;
if ( V_208 && V_208 -> V_211 )
V_35 = V_208 -> V_211 ( V_160 , V_209 ) ;
return V_35 ;
}
static int F_116 ( struct V_110 * V_38 )
{
struct V_112 * V_160 = F_55 ( V_38 ) ;
struct V_207 * V_208 = F_114 ( V_38 -> V_210 ) ;
int V_35 = 0 ;
if ( V_208 && V_208 -> V_212 )
V_35 = V_208 -> V_212 ( V_160 ) ;
return V_35 ;
}
static void F_117 ( struct V_110 * V_38 )
{
struct V_207 * V_208 = F_114 ( V_38 -> V_210 ) ;
if ( V_208 && V_208 -> V_213 )
V_208 -> V_213 ( F_55 ( V_38 ) ) ;
}
static int F_118 ( struct V_110 * V_38 )
{
struct V_112 * V_160 = F_55 ( V_38 ) ;
struct V_207 * V_208 = F_114 ( V_38 -> V_210 ) ;
int V_35 = - V_139 ;
if ( V_208 -> V_214 )
V_35 = V_208 -> V_214 ( V_160 ) ;
return V_35 ;
}
static int F_119 ( struct V_110 * V_38 )
{
struct V_112 * V_160 = F_55 ( V_38 ) ;
struct V_207 * V_208 = F_114 ( V_38 -> V_210 ) ;
int V_35 = 0 ;
if ( V_208 -> remove )
V_35 = V_208 -> remove ( V_160 ) ;
return V_35 ;
}
int F_120 ( struct V_207 * V_210 )
{
V_210 -> V_208 . V_120 = & V_121 ;
return F_121 ( & V_210 -> V_208 ) ;
}
void F_122 ( struct V_207 * V_210 )
{
F_123 ( & V_210 -> V_208 ) ;
}
static int F_124 ( struct V_110 * V_38 , T_5 V_215 , T_6 V_216 )
{
return ( F_125 () || F_126 () ) &&
( V_215 >= 0xc8000000 || ( V_215 + V_216 ) >= 0xc8000000 ) ;
}
static int F_127 ( struct V_217 * V_218 , unsigned long V_219 ,
void * V_159 )
{
struct V_112 * V_38 = F_55 ( V_159 ) ;
switch ( V_219 ) {
case V_220 :
if ( V_38 -> V_38 . V_107 && V_38 -> V_107 < 0xffffffffUL ) {
int V_35 = F_128 ( & V_38 -> V_38 , 1024 , 4096 ,
F_124 ) ;
if ( V_35 )
F_21 ( & V_38 -> V_38 , L_11 , V_35 ) ;
}
break;
case V_221 :
if ( V_38 -> V_38 . V_107 && V_38 -> V_107 < 0xffffffffUL )
F_129 ( & V_38 -> V_38 ) ;
break;
}
return V_222 ;
}
static int T_7 F_130 ( void )
{
int V_35 = F_131 ( & V_121 ) ;
#ifdef F_132
if ( V_35 == 0 )
F_133 ( & V_121 , & V_223 ) ;
#endif
if ( V_35 == 0 )
F_134 ( & V_224 ) ;
return V_35 ;
}
static void T_8 F_135 ( void )
{
F_136 ( & V_224 ) ;
#ifdef F_132
F_137 ( & V_121 , & V_223 ) ;
#endif
F_138 ( & V_121 ) ;
}
