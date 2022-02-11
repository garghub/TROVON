static int F_1 ( struct V_1 * V_2 , unsigned int * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = F_2 ( V_6 -> V_9 ,
V_6 -> V_10 -> V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_4 = V_8 * V_6 -> V_12 ;
if ( ! * V_3 )
* V_3 = 32 ;
if ( * V_4 * * V_3 > V_13 * 1024 * 1024 )
* V_3 = ( V_13 * 1024 * 1024 ) / * V_4 ;
F_3 ( V_6 -> V_14 . V_15 , L_1 , * V_3 , * V_4 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_18 * V_19 = & V_17 -> V_19 ;
F_5 ( F_6 () ) ;
F_3 ( V_6 -> V_14 . V_15 , L_2 , V_20 ,
V_19 , V_19 -> V_21 , V_19 -> V_22 ) ;
F_7 ( V_2 , V_19 , 0 , 0 ) ;
F_8 ( V_2 , V_19 ) ;
V_19 -> V_23 = V_24 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_18 * V_19 , enum V_25 V_26 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_16 * V_17 = F_10 ( V_19 , struct V_16 , V_19 ) ;
int V_27 ;
int V_8 = F_2 ( V_6 -> V_9 ,
V_6 -> V_10 -> V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
F_3 ( V_6 -> V_14 . V_15 , L_2 , V_20 ,
V_19 , V_19 -> V_21 , V_19 -> V_22 ) ;
F_11 ( ! F_12 ( & V_19 -> V_28 ) ) ;
F_5 ( NULL == V_6 -> V_10 ) ;
V_17 -> V_29 = 1 ;
if ( V_17 -> V_30 != V_6 -> V_10 -> V_30 ||
V_19 -> V_31 != V_6 -> V_9 ||
V_19 -> V_32 != V_6 -> V_12 ||
V_19 -> V_26 != V_26 ) {
V_17 -> V_30 = V_6 -> V_10 -> V_30 ;
V_19 -> V_31 = V_6 -> V_9 ;
V_19 -> V_32 = V_6 -> V_12 ;
V_19 -> V_26 = V_26 ;
V_19 -> V_23 = V_24 ;
}
V_19 -> V_4 = V_8 * V_19 -> V_32 ;
if ( 0 != V_19 -> V_21 && V_19 -> V_22 < V_19 -> V_4 ) {
V_27 = - V_33 ;
goto V_34;
}
if ( V_19 -> V_23 == V_24 ) {
V_27 = F_13 ( V_2 , V_19 , NULL ) ;
if ( V_27 )
goto V_35;
V_19 -> V_23 = V_36 ;
}
V_17 -> V_29 = 0 ;
return 0 ;
V_35:
F_4 ( V_2 , V_17 ) ;
V_34:
V_17 -> V_29 = 0 ;
return V_27 ;
}
static int F_14 ( struct V_37 * V_38 )
{
struct V_18 * V_39 = & V_38 -> V_40 -> V_19 ;
struct V_41 * V_14 = V_38 -> V_6 -> V_14 . V_15 ;
int V_27 ;
if ( F_15 ( ! V_38 -> V_40 ) ) {
F_16 ( V_14 , L_3 ) ;
return - V_42 ;
}
V_27 = F_17 ( V_38 -> V_43 ,
F_18 ( V_39 ) ,
V_39 -> V_4 , V_38 -> V_44 -> V_45 +
V_46 , V_47 ) ;
if ( F_15 ( V_27 ) )
F_16 ( V_14 , L_4 ) ;
return V_27 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_48 * V_49 = F_20 ( V_6 -> V_14 . V_15 ) ;
struct V_37 * V_38 = V_49 -> V_50 ;
struct V_16 * V_17 = F_10 ( V_19 , struct V_16 , V_19 ) ;
F_3 ( V_6 -> V_14 . V_15 , L_2 , V_20 ,
V_19 , V_19 -> V_21 , V_19 -> V_22 ) ;
F_21 ( & V_19 -> V_28 , & V_38 -> V_51 ) ;
V_19 -> V_23 = V_52 ;
if ( ! V_38 -> V_40 ) {
V_38 -> V_40 = V_17 ;
if ( ! F_14 ( V_38 ) ) {
unsigned int V_53 ;
V_53 = F_22 ( V_38 -> V_54 + V_55 ) |
V_56 ;
F_23 ( V_53 , V_38 -> V_54 + V_55 ) ;
}
}
}
static void F_24 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_16 * V_17 = F_10 ( V_19 , struct V_16 , V_19 ) ;
#ifdef F_25
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_41 * V_14 = V_6 -> V_14 . V_15 ;
F_3 ( V_14 , L_2 , V_20 ,
V_19 , V_19 -> V_21 , V_19 -> V_22 ) ;
switch ( V_19 -> V_23 ) {
case V_52 :
F_3 ( V_14 , L_5 , V_20 ) ;
break;
case V_57 :
F_3 ( V_14 , L_6 , V_20 ) ;
break;
case V_36 :
F_3 ( V_14 , L_7 , V_20 ) ;
break;
default:
F_3 ( V_14 , L_8 , V_20 ) ;
break;
}
#endif
F_4 ( V_2 , V_17 ) ;
}
static void F_26 ( struct V_37 * V_38 ,
struct V_18 * V_19 ,
struct V_16 * V_17 )
{
F_27 ( & V_19 -> V_28 ) ;
V_19 -> V_23 = V_58 ;
F_28 ( & V_19 -> V_59 ) ;
V_19 -> V_60 ++ ;
F_29 ( & V_19 -> V_61 ) ;
if ( F_12 ( & V_38 -> V_51 ) ) {
V_38 -> V_40 = NULL ;
return;
}
V_38 -> V_40 = F_30 ( V_38 -> V_51 . V_62 ,
struct V_16 , V_19 . V_28 ) ;
if ( F_31 ( ! F_14 ( V_38 ) ) ) {
unsigned int V_53 ;
V_53 = F_22 ( V_38 -> V_54 + V_55 ) | V_56 ;
F_23 ( V_53 , V_38 -> V_54 + V_55 ) ;
}
}
static void F_32 ( int V_63 , void * V_64 )
{
struct V_37 * V_38 = V_64 ;
struct V_41 * V_14 = V_38 -> V_6 -> V_14 . V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
unsigned long V_65 ;
F_33 ( & V_38 -> V_66 , V_65 ) ;
F_34 ( V_63 ) ;
if ( F_15 ( ! V_38 -> V_40 ) ) {
F_16 ( V_14 , L_3 ) ;
goto V_34;
}
V_19 = & V_38 -> V_40 -> V_19 ;
V_17 = F_10 ( V_19 , struct V_16 , V_19 ) ;
F_11 ( V_17 -> V_29 || F_12 ( & V_19 -> V_28 ) ) ;
F_3 ( V_14 , L_2 , V_20 ,
V_19 , V_19 -> V_21 , V_19 -> V_22 ) ;
F_26 ( V_38 , V_19 , V_17 ) ;
V_34:
F_35 ( & V_38 -> V_66 , V_65 ) ;
}
static void F_36 ( struct V_1 * V_67 ,
struct V_5 * V_6 )
{
struct V_48 * V_49 = F_20 ( V_6 -> V_14 . V_15 ) ;
struct V_37 * V_38 = V_49 -> V_50 ;
F_37 ( V_67 , & V_68 , V_6 -> V_14 . V_15 ,
& V_38 -> V_66 , V_69 ,
V_70 ,
sizeof( struct V_16 ) , V_6 , & V_6 -> V_71 ) ;
}
static int F_38 ( struct V_37 * V_38 )
{
unsigned int V_72 = V_38 -> V_72 ;
unsigned long div ;
unsigned long V_73 ;
V_73 = F_39 ( V_38 -> V_74 ) ;
div = ( V_73 + 2 * V_72 - 1 ) / ( 2 * V_72 ) - 1 ;
F_3 ( V_38 -> V_6 -> V_14 . V_15 ,
L_9 ,
V_73 / 1000 , V_72 / 1000 , div ) ;
return div ;
}
static void F_40 ( struct V_37 * V_38 )
{
unsigned int V_75 = V_76 ;
F_3 ( V_38 -> V_6 -> V_14 . V_15 , L_10 ) ;
F_41 ( V_38 -> V_74 ) ;
F_23 ( V_75 , V_38 -> V_54 + V_55 ) ;
V_75 |= V_77 | V_78 | V_79 ;
V_75 |= F_42 ( F_38 ( V_38 ) ) ;
V_75 |= F_43 ( 2 ) ;
F_23 ( V_75 , V_38 -> V_54 + V_55 ) ;
}
static void F_44 ( struct V_37 * V_38 )
{
F_3 ( V_38 -> V_6 -> V_14 . V_15 , L_11 ) ;
F_23 ( 0x00 , V_38 -> V_54 + V_55 ) ;
F_45 ( V_38 -> V_74 ) ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_48 * V_49 = F_20 ( V_6 -> V_14 . V_15 ) ;
struct V_37 * V_38 = V_49 -> V_50 ;
if ( V_38 -> V_6 )
return - V_80 ;
F_47 ( V_6 -> V_14 . V_15 , L_12 ,
V_6 -> V_81 ) ;
F_40 ( V_38 ) ;
V_38 -> V_6 = V_6 ;
return 0 ;
}
static void F_48 ( struct V_5 * V_6 )
{
struct V_48 * V_49 = F_20 ( V_6 -> V_14 . V_15 ) ;
struct V_37 * V_38 = V_49 -> V_50 ;
unsigned int V_75 ;
F_5 ( V_6 != V_38 -> V_6 ) ;
V_75 = F_22 ( V_38 -> V_54 + V_55 ) & ~ V_82 ;
F_23 ( V_75 , V_38 -> V_54 + V_55 ) ;
F_34 ( V_38 -> V_43 ) ;
F_47 ( V_6 -> V_14 . V_15 , L_13 ,
V_6 -> V_81 ) ;
F_44 ( V_38 ) ;
V_38 -> V_6 = NULL ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_83 * V_84 )
{
struct V_85 * V_86 = F_50 ( V_6 ) ;
return F_51 ( V_86 , V_87 , V_88 , V_84 ) ;
}
static int F_52 ( struct V_5 * V_6 , T_1 V_89 )
{
struct V_48 * V_49 = F_20 ( V_6 -> V_14 . V_15 ) ;
struct V_37 * V_38 = V_49 -> V_50 ;
unsigned long V_90 , V_91 ;
unsigned int V_75 ;
int V_27 ;
V_90 = V_6 -> V_92 -> V_93 ( V_6 ) ;
V_91 = F_53 ( V_90 ,
V_94 ) ;
if ( ! V_91 )
return - V_33 ;
if ( ( V_91 & V_95 ) &&
( V_91 & V_96 ) ) {
if ( ! V_38 -> V_97 ||
V_38 -> V_97 -> V_65 & V_98 )
V_91 &= ~ V_96 ;
else
V_91 &= ~ V_95 ;
}
if ( ( V_91 & V_99 ) &&
( V_91 & V_100 ) ) {
if ( ! V_38 -> V_97 ||
V_38 -> V_97 -> V_65 & V_101 )
V_91 &= ~ V_100 ;
else
V_91 &= ~ V_99 ;
}
if ( ( V_91 & V_102 ) &&
( V_91 & V_103 ) ) {
if ( ! V_38 -> V_97 ||
V_38 -> V_97 -> V_65 & V_104 )
V_91 &= ~ V_103 ;
else
V_91 &= ~ V_102 ;
}
V_27 = V_6 -> V_92 -> V_105 ( V_6 , V_91 ) ;
if ( V_27 < 0 )
return V_27 ;
V_75 = F_22 ( V_38 -> V_54 + V_55 ) ;
if ( V_91 & V_99 )
V_75 |= V_106 ;
if ( V_91 & V_95 )
V_75 |= V_107 ;
if ( V_91 & V_103 )
V_75 |= V_108 ;
F_23 ( V_75 , V_38 -> V_54 + V_55 ) ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 ,
struct V_109 * V_110 )
{
struct V_85 * V_86 = F_50 ( V_6 ) ;
const struct V_111 * V_112 ;
struct V_113 * V_114 = & V_110 -> V_115 . V_114 ;
struct V_116 V_117 ;
int V_27 , V_118 ;
V_112 = F_55 ( V_6 , V_114 -> V_119 ) ;
if ( ! V_112 ) {
F_56 ( V_6 -> V_14 . V_15 , L_14 ,
V_114 -> V_119 ) ;
return - V_33 ;
}
V_118 = V_112 -> V_11 -> V_120 ;
if ( V_118 > 8 ) {
F_56 ( V_6 -> V_14 . V_15 ,
L_15 ,
V_118 , V_114 -> V_119 ) ;
return - V_33 ;
}
V_117 . V_31 = V_114 -> V_31 ;
V_117 . V_32 = V_114 -> V_32 ;
V_117 . V_26 = V_114 -> V_26 ;
V_117 . V_121 = V_114 -> V_121 ;
V_117 . V_30 = V_112 -> V_30 ;
V_27 = F_51 ( V_86 , V_87 , V_122 , & V_117 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_117 . V_30 != V_112 -> V_30 )
return - V_33 ;
V_114 -> V_31 = V_117 . V_31 ;
V_114 -> V_32 = V_117 . V_32 ;
V_114 -> V_26 = V_117 . V_26 ;
V_114 -> V_121 = V_117 . V_121 ;
V_6 -> V_10 = V_112 ;
return V_27 ;
}
static int F_57 ( struct V_5 * V_6 ,
struct V_109 * V_110 )
{
struct V_85 * V_86 = F_50 ( V_6 ) ;
const struct V_111 * V_112 ;
struct V_113 * V_114 = & V_110 -> V_115 . V_114 ;
struct V_116 V_117 ;
int V_27 ;
V_112 = F_55 ( V_6 , V_114 -> V_119 ) ;
if ( ! V_112 ) {
F_56 ( V_6 -> V_14 . V_15 , L_14 ,
V_114 -> V_119 ) ;
return - V_33 ;
}
V_117 . V_31 = V_114 -> V_31 ;
V_117 . V_32 = V_114 -> V_32 ;
V_117 . V_26 = V_114 -> V_26 ;
V_117 . V_121 = V_114 -> V_121 ;
V_117 . V_30 = V_112 -> V_30 ;
V_27 = F_51 ( V_86 , V_87 , V_123 , & V_117 ) ;
if ( V_27 < 0 )
return V_27 ;
V_114 -> V_31 = V_117 . V_31 ;
V_114 -> V_32 = V_117 . V_32 ;
V_114 -> V_26 = V_117 . V_26 ;
V_114 -> V_121 = V_117 . V_121 ;
return 0 ;
}
static int F_58 ( struct V_5 * V_6 ,
struct V_124 * V_125 )
{
int V_126 ;
for ( V_126 = 0 ; V_126 < V_125 -> V_3 ; V_126 ++ ) {
struct V_16 * V_17 = F_10 ( V_6 -> V_127 . V_128 [ V_126 ] ,
struct V_16 , V_19 ) ;
V_17 -> V_29 = 0 ;
F_59 ( & V_17 -> V_19 . V_28 ) ;
}
return 0 ;
}
static unsigned int F_60 ( struct V_129 * V_129 , T_2 * V_130 )
{
struct V_5 * V_6 = V_129 -> V_131 ;
struct V_16 * V_17 ;
V_17 = F_30 ( V_6 -> V_127 . V_132 . V_62 , struct V_16 ,
V_19 . V_132 ) ;
F_61 ( V_129 , & V_17 -> V_19 . V_61 , V_130 ) ;
if ( V_17 -> V_19 . V_23 == V_58 ||
V_17 -> V_19 . V_23 == V_133 )
return V_134 | V_135 ;
return 0 ;
}
static int F_62 ( struct V_48 * V_49 ,
struct V_136 * V_137 )
{
F_63 ( V_137 -> V_138 , L_16 , sizeof( V_137 -> V_138 ) ) ;
V_137 -> V_139 = V_140 ;
V_137 -> V_141 = V_142 | V_143 ;
return 0 ;
}
static int T_3 F_64 ( struct V_144 * V_145 )
{
struct V_37 * V_38 ;
struct V_146 * V_44 ;
struct V_147 V_148 ;
struct V_74 * V_74 ;
void T_4 * V_54 ;
unsigned int V_149 ;
int V_150 = 0 ;
V_44 = F_65 ( V_145 , V_151 , 0 ) ;
V_149 = F_66 ( V_145 , 0 ) ;
if ( ! V_44 || ( int ) V_149 <= 0 ) {
V_150 = - V_152 ;
goto exit;
}
V_74 = F_67 ( & V_145 -> V_14 , L_17 ) ;
if ( F_68 ( V_74 ) ) {
V_150 = F_69 ( V_74 ) ;
goto exit;
}
V_38 = F_70 ( sizeof( * V_38 ) , V_153 ) ;
if ( ! V_38 ) {
F_16 ( & V_145 -> V_14 , L_18 ) ;
V_150 = - V_154 ;
goto V_155;
}
V_38 -> V_44 = V_44 ;
V_38 -> V_74 = V_74 ;
V_38 -> V_97 = V_145 -> V_14 . V_156 ;
if ( V_38 -> V_97 )
V_38 -> V_72 = V_38 -> V_97 -> V_157 * 10000 ;
if ( ! V_38 -> V_72 ) {
F_56 ( & V_145 -> V_14 ,
L_19
L_20 ) ;
V_38 -> V_72 = 20000000 ;
}
F_59 ( & V_38 -> V_51 ) ;
F_71 ( & V_38 -> V_66 ) ;
if ( ! F_72 ( V_44 -> V_45 , F_73 ( V_44 ) , V_158 ) ) {
V_150 = - V_80 ;
goto V_159;
}
V_54 = F_74 ( V_44 -> V_45 , F_73 ( V_44 ) ) ;
if ( ! V_54 ) {
V_150 = - V_154 ;
goto V_160;
}
V_38 -> V_149 = V_149 ;
V_38 -> V_54 = V_54 ;
V_38 -> V_43 = F_75 ( V_158 , V_161 ) ;
if ( V_38 -> V_43 < 0 ) {
F_16 ( & V_145 -> V_14 , L_21 ) ;
V_150 = - V_80 ;
goto V_162;
}
F_3 ( & V_145 -> V_14 , L_22 , V_38 -> V_43 ) ;
F_76 ( V_38 -> V_43 , F_32 , NULL ,
V_38 ) ;
F_77 ( V_38 -> V_43 , V_163 ,
V_164 , V_165 , 0 ) ;
F_78 ( V_38 -> V_43 , 0 ) ;
V_150 = F_79 ( & V_166 ) ;
if ( V_150 ) {
F_16 ( & V_145 -> V_14 , L_23 ) ;
goto V_167;
}
F_80 ( & V_168 , & V_169 -
& V_168 ) ;
V_148 . V_170 = ( long ) V_171 ;
V_148 . V_172 = ( long ) F_81 ( V_38 -> V_43 ) ;
V_148 . V_173 = ( long ) V_38 -> V_54 + V_55 ;
V_148 . V_174 = ( long ) V_38 -> V_54 + V_175 ;
V_148 . V_176 = 1 << V_38 -> V_43 ;
F_82 ( & V_148 ) ;
F_83 ( V_149 , 1 ) ;
F_84 ( V_149 ) ;
V_38 -> V_177 . V_178 = V_158 ;
V_38 -> V_177 . V_92 = & V_179 ;
V_38 -> V_177 . V_50 = V_38 ;
V_38 -> V_177 . V_180 . V_14 = & V_145 -> V_14 ;
V_38 -> V_177 . V_181 = V_145 -> V_182 ;
V_150 = F_85 ( & V_38 -> V_177 ) ;
if ( V_150 )
goto V_183;
F_47 ( & V_145 -> V_14 , L_24 ) ;
return 0 ;
V_183:
F_86 ( V_149 ) ;
F_83 ( V_149 , 0 ) ;
F_87 ( & V_166 ) ;
V_167:
F_88 ( V_38 -> V_43 ) ;
V_162:
F_89 ( V_54 ) ;
V_160:
F_90 ( V_44 -> V_45 , F_73 ( V_44 ) ) ;
V_159:
F_91 ( V_38 ) ;
V_155:
F_92 ( V_74 ) ;
exit:
return V_150 ;
}
static int T_5 F_93 ( struct V_144 * V_145 )
{
struct V_48 * V_177 = F_20 ( & V_145 -> V_14 ) ;
struct V_37 * V_38 = F_10 ( V_177 ,
struct V_37 , V_177 ) ;
struct V_146 * V_44 ;
F_88 ( V_38 -> V_43 ) ;
F_86 ( V_38 -> V_149 ) ;
F_83 ( V_38 -> V_149 , 0 ) ;
F_87 ( & V_166 ) ;
F_92 ( V_38 -> V_74 ) ;
F_94 ( V_177 ) ;
F_89 ( V_38 -> V_54 ) ;
V_44 = V_38 -> V_44 ;
F_90 ( V_44 -> V_45 , F_73 ( V_44 ) ) ;
F_91 ( V_38 ) ;
F_47 ( & V_145 -> V_14 , L_25 ) ;
return 0 ;
}
static int T_3 F_95 ( void )
{
return F_96 ( & V_184 , F_64 ) ;
}
static void T_5 F_97 ( void )
{
return F_98 ( & V_184 ) ;
}
