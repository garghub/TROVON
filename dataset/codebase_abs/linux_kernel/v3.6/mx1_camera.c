static int F_1 ( struct V_1 * V_2 , unsigned int * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_4 = V_6 -> V_8 ;
if ( ! * V_3 )
* V_3 = 32 ;
if ( * V_4 * * V_3 > V_9 * 1024 * 1024 )
* V_3 = ( V_9 * 1024 * 1024 ) / * V_4 ;
F_2 ( V_6 -> V_10 , L_1 , * V_3 , * V_4 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_13 * V_14 = & V_12 -> V_14 ;
F_4 ( F_5 () ) ;
F_2 ( V_6 -> V_10 , L_2 , V_15 ,
V_14 , V_14 -> V_16 , V_14 -> V_17 ) ;
F_6 ( V_2 , V_14 , 0 , 0 ) ;
F_7 ( V_2 , V_14 ) ;
V_14 -> V_18 = V_19 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_13 * V_14 , enum V_20 V_21 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_11 * V_12 = F_9 ( V_14 , struct V_11 , V_14 ) ;
int V_22 ;
F_2 ( V_6 -> V_10 , L_2 , V_15 ,
V_14 , V_14 -> V_16 , V_14 -> V_17 ) ;
F_10 ( ! F_11 ( & V_14 -> V_23 ) ) ;
F_4 ( NULL == V_6 -> V_24 ) ;
V_12 -> V_25 = 1 ;
if ( V_12 -> V_26 != V_6 -> V_24 -> V_26 ||
V_14 -> V_27 != V_6 -> V_28 ||
V_14 -> V_29 != V_6 -> V_30 ||
V_14 -> V_21 != V_21 ) {
V_12 -> V_26 = V_6 -> V_24 -> V_26 ;
V_14 -> V_27 = V_6 -> V_28 ;
V_14 -> V_29 = V_6 -> V_30 ;
V_14 -> V_21 = V_21 ;
V_14 -> V_18 = V_19 ;
}
V_14 -> V_4 = V_6 -> V_8 ;
if ( 0 != V_14 -> V_16 && V_14 -> V_17 < V_14 -> V_4 ) {
V_22 = - V_31 ;
goto V_32;
}
if ( V_14 -> V_18 == V_19 ) {
V_22 = F_12 ( V_2 , V_14 , NULL ) ;
if ( V_22 )
goto V_33;
V_14 -> V_18 = V_34 ;
}
V_12 -> V_25 = 0 ;
return 0 ;
V_33:
F_3 ( V_2 , V_12 ) ;
V_32:
V_12 -> V_25 = 0 ;
return V_22 ;
}
static int F_13 ( struct V_35 * V_36 )
{
struct V_13 * V_37 = & V_36 -> V_38 -> V_14 ;
struct V_39 * V_40 = V_36 -> V_6 -> V_10 ;
int V_22 ;
if ( F_14 ( ! V_36 -> V_38 ) ) {
F_15 ( V_40 , L_3 ) ;
return - V_41 ;
}
V_22 = F_16 ( V_36 -> V_42 ,
F_17 ( V_37 ) ,
V_37 -> V_4 , V_36 -> V_43 -> V_44 +
V_45 , V_46 ) ;
if ( F_14 ( V_22 ) )
F_15 ( V_40 , L_4 ) ;
return V_22 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_47 * V_48 = F_19 ( V_6 -> V_10 ) ;
struct V_35 * V_36 = V_48 -> V_49 ;
struct V_11 * V_12 = F_9 ( V_14 , struct V_11 , V_14 ) ;
F_2 ( V_6 -> V_10 , L_2 , V_15 ,
V_14 , V_14 -> V_16 , V_14 -> V_17 ) ;
F_20 ( & V_14 -> V_23 , & V_36 -> V_50 ) ;
V_14 -> V_18 = V_51 ;
if ( ! V_36 -> V_38 ) {
V_36 -> V_38 = V_12 ;
if ( ! F_13 ( V_36 ) ) {
unsigned int V_52 ;
V_52 = F_21 ( V_36 -> V_53 + V_54 ) |
V_55 ;
F_22 ( V_52 , V_36 -> V_53 + V_54 ) ;
}
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_11 * V_12 = F_9 ( V_14 , struct V_11 , V_14 ) ;
#ifdef F_24
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_39 * V_40 = V_6 -> V_10 ;
F_2 ( V_40 , L_2 , V_15 ,
V_14 , V_14 -> V_16 , V_14 -> V_17 ) ;
switch ( V_14 -> V_18 ) {
case V_51 :
F_2 ( V_40 , L_5 , V_15 ) ;
break;
case V_56 :
F_2 ( V_40 , L_6 , V_15 ) ;
break;
case V_34 :
F_2 ( V_40 , L_7 , V_15 ) ;
break;
default:
F_2 ( V_40 , L_8 , V_15 ) ;
break;
}
#endif
F_3 ( V_2 , V_12 ) ;
}
static void F_25 ( struct V_35 * V_36 ,
struct V_13 * V_14 ,
struct V_11 * V_12 )
{
F_26 ( & V_14 -> V_23 ) ;
V_14 -> V_18 = V_57 ;
F_27 ( & V_14 -> V_58 ) ;
V_14 -> V_59 ++ ;
F_28 ( & V_14 -> V_60 ) ;
if ( F_11 ( & V_36 -> V_50 ) ) {
V_36 -> V_38 = NULL ;
return;
}
V_36 -> V_38 = F_29 ( V_36 -> V_50 . V_61 ,
struct V_11 , V_14 . V_23 ) ;
if ( F_30 ( ! F_13 ( V_36 ) ) ) {
unsigned int V_52 ;
V_52 = F_21 ( V_36 -> V_53 + V_54 ) | V_55 ;
F_22 ( V_52 , V_36 -> V_53 + V_54 ) ;
}
}
static void F_31 ( int V_62 , void * V_63 )
{
struct V_35 * V_36 = V_63 ;
struct V_39 * V_40 = V_36 -> V_6 -> V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned long V_64 ;
F_32 ( & V_36 -> V_65 , V_64 ) ;
F_33 ( V_62 ) ;
if ( F_14 ( ! V_36 -> V_38 ) ) {
F_15 ( V_40 , L_3 ) ;
goto V_32;
}
V_14 = & V_36 -> V_38 -> V_14 ;
V_12 = F_9 ( V_14 , struct V_11 , V_14 ) ;
F_10 ( V_12 -> V_25 || F_11 ( & V_14 -> V_23 ) ) ;
F_2 ( V_40 , L_2 , V_15 ,
V_14 , V_14 -> V_16 , V_14 -> V_17 ) ;
F_25 ( V_36 , V_14 , V_12 ) ;
V_32:
F_34 ( & V_36 -> V_65 , V_64 ) ;
}
static void F_35 ( struct V_1 * V_66 ,
struct V_5 * V_6 )
{
struct V_47 * V_48 = F_19 ( V_6 -> V_10 ) ;
struct V_35 * V_36 = V_48 -> V_49 ;
F_36 ( V_66 , & V_67 , V_6 -> V_10 ,
& V_36 -> V_65 , V_68 ,
V_69 ,
sizeof( struct V_11 ) , V_6 , & V_6 -> V_70 ) ;
}
static int F_37 ( struct V_35 * V_36 )
{
unsigned int V_71 = V_36 -> V_71 ;
unsigned long div ;
unsigned long V_72 ;
V_72 = F_38 ( V_36 -> V_73 ) ;
div = ( V_72 + 2 * V_71 - 1 ) / ( 2 * V_71 ) - 1 ;
F_2 ( V_36 -> V_6 -> V_10 ,
L_9 ,
V_72 / 1000 , V_71 / 1000 , div ) ;
return div ;
}
static void F_39 ( struct V_35 * V_36 )
{
unsigned int V_74 = V_75 ;
F_2 ( V_36 -> V_6 -> V_10 , L_10 ) ;
F_40 ( V_36 -> V_73 ) ;
F_22 ( V_74 , V_36 -> V_53 + V_54 ) ;
V_74 |= V_76 | V_77 | V_78 ;
V_74 |= F_41 ( F_37 ( V_36 ) ) ;
V_74 |= F_42 ( 2 ) ;
F_22 ( V_74 , V_36 -> V_53 + V_54 ) ;
}
static void F_43 ( struct V_35 * V_36 )
{
F_2 ( V_36 -> V_6 -> V_10 , L_11 ) ;
F_22 ( 0x00 , V_36 -> V_53 + V_54 ) ;
F_44 ( V_36 -> V_73 ) ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_47 * V_48 = F_19 ( V_6 -> V_10 ) ;
struct V_35 * V_36 = V_48 -> V_49 ;
if ( V_36 -> V_6 )
return - V_79 ;
F_46 ( V_6 -> V_10 , L_12 ,
V_6 -> V_80 ) ;
F_39 ( V_36 ) ;
V_36 -> V_6 = V_6 ;
return 0 ;
}
static void F_47 ( struct V_5 * V_6 )
{
struct V_47 * V_48 = F_19 ( V_6 -> V_10 ) ;
struct V_35 * V_36 = V_48 -> V_49 ;
unsigned int V_74 ;
F_4 ( V_6 != V_36 -> V_6 ) ;
V_74 = F_21 ( V_36 -> V_53 + V_54 ) & ~ V_81 ;
F_22 ( V_74 , V_36 -> V_53 + V_54 ) ;
F_33 ( V_36 -> V_42 ) ;
F_46 ( V_6 -> V_10 , L_13 ,
V_6 -> V_80 ) ;
F_43 ( V_36 ) ;
V_36 -> V_6 = NULL ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_82 * V_83 )
{
struct V_84 * V_85 = F_49 ( V_6 ) ;
return F_50 ( V_85 , V_86 , V_87 , V_83 ) ;
}
static int F_51 ( struct V_5 * V_6 )
{
struct V_84 * V_85 = F_49 ( V_6 ) ;
struct V_47 * V_48 = F_19 ( V_6 -> V_10 ) ;
struct V_35 * V_36 = V_48 -> V_49 ;
struct V_88 V_89 = { . type = V_90 ,} ;
unsigned long V_91 ;
unsigned int V_74 ;
int V_22 ;
V_22 = F_50 ( V_85 , V_86 , V_92 , & V_89 ) ;
if ( ! V_22 ) {
V_91 = F_52 ( & V_89 , V_93 ) ;
if ( ! V_91 ) {
F_53 ( V_6 -> V_10 ,
L_14 ,
V_89 . V_64 , V_93 ) ;
return - V_31 ;
}
} else if ( V_22 != - V_94 ) {
return V_22 ;
} else {
V_91 = V_93 ;
}
if ( ( V_91 & V_95 ) &&
( V_91 & V_96 ) ) {
if ( ! V_36 -> V_97 ||
V_36 -> V_97 -> V_64 & V_98 )
V_91 &= ~ V_96 ;
else
V_91 &= ~ V_95 ;
}
if ( ( V_91 & V_99 ) &&
( V_91 & V_100 ) ) {
if ( ! V_36 -> V_97 ||
V_36 -> V_97 -> V_64 & V_101 )
V_91 &= ~ V_100 ;
else
V_91 &= ~ V_99 ;
}
if ( ( V_91 & V_102 ) &&
( V_91 & V_103 ) ) {
if ( ! V_36 -> V_97 ||
V_36 -> V_97 -> V_64 & V_104 )
V_91 &= ~ V_103 ;
else
V_91 &= ~ V_102 ;
}
V_89 . V_64 = V_91 ;
V_22 = F_50 ( V_85 , V_86 , V_105 , & V_89 ) ;
if ( V_22 < 0 && V_22 != - V_94 ) {
F_2 ( V_6 -> V_10 , L_15 ,
V_91 , V_22 ) ;
return V_22 ;
}
V_74 = F_21 ( V_36 -> V_53 + V_54 ) ;
if ( V_91 & V_99 )
V_74 |= V_106 ;
if ( V_91 & V_95 )
V_74 |= V_107 ;
if ( V_91 & V_103 )
V_74 |= V_108 ;
F_22 ( V_74 , V_36 -> V_53 + V_54 ) ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 ,
struct V_109 * V_110 )
{
struct V_84 * V_85 = F_49 ( V_6 ) ;
const struct V_111 * V_112 ;
struct V_113 * V_114 = & V_110 -> V_115 . V_114 ;
struct V_116 V_117 ;
int V_22 , V_118 ;
V_112 = F_55 ( V_6 , V_114 -> V_119 ) ;
if ( ! V_112 ) {
F_53 ( V_6 -> V_10 , L_16 ,
V_114 -> V_119 ) ;
return - V_31 ;
}
V_118 = V_112 -> V_120 -> V_121 ;
if ( V_118 > 8 ) {
F_53 ( V_6 -> V_10 ,
L_17 ,
V_118 , V_114 -> V_119 ) ;
return - V_31 ;
}
V_117 . V_27 = V_114 -> V_27 ;
V_117 . V_29 = V_114 -> V_29 ;
V_117 . V_21 = V_114 -> V_21 ;
V_117 . V_122 = V_114 -> V_122 ;
V_117 . V_26 = V_112 -> V_26 ;
V_22 = F_50 ( V_85 , V_86 , V_123 , & V_117 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_117 . V_26 != V_112 -> V_26 )
return - V_31 ;
V_114 -> V_27 = V_117 . V_27 ;
V_114 -> V_29 = V_117 . V_29 ;
V_114 -> V_21 = V_117 . V_21 ;
V_114 -> V_122 = V_117 . V_122 ;
V_6 -> V_24 = V_112 ;
return V_22 ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_109 * V_110 )
{
struct V_84 * V_85 = F_49 ( V_6 ) ;
const struct V_111 * V_112 ;
struct V_113 * V_114 = & V_110 -> V_115 . V_114 ;
struct V_116 V_117 ;
int V_22 ;
V_112 = F_55 ( V_6 , V_114 -> V_119 ) ;
if ( ! V_112 ) {
F_53 ( V_6 -> V_10 , L_16 ,
V_114 -> V_119 ) ;
return - V_31 ;
}
V_117 . V_27 = V_114 -> V_27 ;
V_117 . V_29 = V_114 -> V_29 ;
V_117 . V_21 = V_114 -> V_21 ;
V_117 . V_122 = V_114 -> V_122 ;
V_117 . V_26 = V_112 -> V_26 ;
V_22 = F_50 ( V_85 , V_86 , V_124 , & V_117 ) ;
if ( V_22 < 0 )
return V_22 ;
V_114 -> V_27 = V_117 . V_27 ;
V_114 -> V_29 = V_117 . V_29 ;
V_114 -> V_21 = V_117 . V_21 ;
V_114 -> V_122 = V_117 . V_122 ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 ,
struct V_125 * V_126 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_126 -> V_3 ; V_127 ++ ) {
struct V_11 * V_12 = F_9 ( V_6 -> V_128 . V_129 [ V_127 ] ,
struct V_11 , V_14 ) ;
V_12 -> V_25 = 0 ;
F_58 ( & V_12 -> V_14 . V_23 ) ;
}
return 0 ;
}
static unsigned int F_59 ( struct V_130 * V_130 , T_1 * V_131 )
{
struct V_5 * V_6 = V_130 -> V_132 ;
struct V_11 * V_12 ;
V_12 = F_29 ( V_6 -> V_128 . V_133 . V_61 , struct V_11 ,
V_14 . V_133 ) ;
F_60 ( V_130 , & V_12 -> V_14 . V_60 , V_131 ) ;
if ( V_12 -> V_14 . V_18 == V_57 ||
V_12 -> V_14 . V_18 == V_134 )
return V_135 | V_136 ;
return 0 ;
}
static int F_61 ( struct V_47 * V_48 ,
struct V_137 * V_138 )
{
F_62 ( V_138 -> V_139 , L_18 , sizeof( V_138 -> V_139 ) ) ;
V_138 -> V_140 = V_141 | V_142 ;
return 0 ;
}
static int T_2 F_63 ( struct V_143 * V_144 )
{
struct V_35 * V_36 ;
struct V_145 * V_43 ;
struct V_146 V_147 ;
struct V_73 * V_73 ;
void T_3 * V_53 ;
unsigned int V_148 ;
int V_149 = 0 ;
V_43 = F_64 ( V_144 , V_150 , 0 ) ;
V_148 = F_65 ( V_144 , 0 ) ;
if ( ! V_43 || ( int ) V_148 <= 0 ) {
V_149 = - V_151 ;
goto exit;
}
V_73 = F_66 ( & V_144 -> V_40 , L_19 ) ;
if ( F_67 ( V_73 ) ) {
V_149 = F_68 ( V_73 ) ;
goto exit;
}
V_36 = F_69 ( sizeof( * V_36 ) , V_152 ) ;
if ( ! V_36 ) {
F_15 ( & V_144 -> V_40 , L_20 ) ;
V_149 = - V_153 ;
goto V_154;
}
V_36 -> V_43 = V_43 ;
V_36 -> V_73 = V_73 ;
V_36 -> V_97 = V_144 -> V_40 . V_155 ;
if ( V_36 -> V_97 )
V_36 -> V_71 = V_36 -> V_97 -> V_156 * 10000 ;
if ( ! V_36 -> V_71 ) {
F_53 ( & V_144 -> V_40 ,
L_21
L_22 ) ;
V_36 -> V_71 = 20000000 ;
}
F_58 ( & V_36 -> V_50 ) ;
F_70 ( & V_36 -> V_65 ) ;
if ( ! F_71 ( V_43 -> V_44 , F_72 ( V_43 ) , V_157 ) ) {
V_149 = - V_79 ;
goto V_158;
}
V_53 = F_73 ( V_43 -> V_44 , F_72 ( V_43 ) ) ;
if ( ! V_53 ) {
V_149 = - V_153 ;
goto V_159;
}
V_36 -> V_148 = V_148 ;
V_36 -> V_53 = V_53 ;
V_36 -> V_42 = F_74 ( V_157 , V_160 ) ;
if ( V_36 -> V_42 < 0 ) {
F_15 ( & V_144 -> V_40 , L_23 ) ;
V_149 = - V_79 ;
goto V_161;
}
F_2 ( & V_144 -> V_40 , L_24 , V_36 -> V_42 ) ;
F_75 ( V_36 -> V_42 , F_31 , NULL ,
V_36 ) ;
F_76 ( V_36 -> V_42 , V_162 ,
V_163 , V_164 , 0 ) ;
F_77 ( V_36 -> V_42 , 0 ) ;
V_149 = F_78 ( & V_165 ) ;
if ( V_149 ) {
F_15 ( & V_144 -> V_40 , L_25 ) ;
goto V_166;
}
F_79 ( & V_167 , & V_168 -
& V_167 ) ;
V_147 . V_169 = ( long ) V_170 ;
V_147 . V_171 = ( long ) F_80 ( V_36 -> V_42 ) ;
V_147 . V_172 = ( long ) V_36 -> V_53 + V_54 ;
V_147 . V_173 = ( long ) V_36 -> V_53 + V_174 ;
V_147 . V_175 = 1 << V_36 -> V_42 ;
F_81 ( & V_147 ) ;
F_82 ( V_148 , 1 ) ;
F_83 ( V_148 ) ;
V_36 -> V_176 . V_177 = V_157 ;
V_36 -> V_176 . V_178 = & V_179 ;
V_36 -> V_176 . V_49 = V_36 ;
V_36 -> V_176 . V_180 . V_40 = & V_144 -> V_40 ;
V_36 -> V_176 . V_181 = V_144 -> V_182 ;
V_149 = F_84 ( & V_36 -> V_176 ) ;
if ( V_149 )
goto V_183;
F_46 ( & V_144 -> V_40 , L_26 ) ;
return 0 ;
V_183:
F_85 ( V_148 ) ;
F_82 ( V_148 , 0 ) ;
F_86 ( & V_165 ) ;
V_166:
F_87 ( V_36 -> V_42 ) ;
V_161:
F_88 ( V_53 ) ;
V_159:
F_89 ( V_43 -> V_44 , F_72 ( V_43 ) ) ;
V_158:
F_90 ( V_36 ) ;
V_154:
F_91 ( V_73 ) ;
exit:
return V_149 ;
}
static int T_4 F_92 ( struct V_143 * V_144 )
{
struct V_47 * V_176 = F_19 ( & V_144 -> V_40 ) ;
struct V_35 * V_36 = F_9 ( V_176 ,
struct V_35 , V_176 ) ;
struct V_145 * V_43 ;
F_87 ( V_36 -> V_42 ) ;
F_85 ( V_36 -> V_148 ) ;
F_82 ( V_36 -> V_148 , 0 ) ;
F_86 ( & V_165 ) ;
F_91 ( V_36 -> V_73 ) ;
F_93 ( V_176 ) ;
F_88 ( V_36 -> V_53 ) ;
V_43 = V_36 -> V_43 ;
F_89 ( V_43 -> V_44 , F_72 ( V_43 ) ) ;
F_90 ( V_36 ) ;
F_46 ( & V_144 -> V_40 , L_27 ) ;
return 0 ;
}
static int T_2 F_94 ( void )
{
return F_95 ( & V_184 , F_63 ) ;
}
static void T_4 F_96 ( void )
{
return F_97 ( & V_184 ) ;
}
