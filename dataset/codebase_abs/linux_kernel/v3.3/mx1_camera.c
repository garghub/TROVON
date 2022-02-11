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
F_3 ( V_6 -> V_14 , L_1 , * V_3 , * V_4 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 = & V_16 -> V_18 ;
F_5 ( F_6 () ) ;
F_3 ( V_6 -> V_14 , L_2 , V_19 ,
V_18 , V_18 -> V_20 , V_18 -> V_21 ) ;
F_7 ( V_2 , V_18 , 0 , 0 ) ;
F_8 ( V_2 , V_18 ) ;
V_18 -> V_22 = V_23 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_17 * V_18 , enum V_24 V_25 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_15 * V_16 = F_10 ( V_18 , struct V_15 , V_18 ) ;
int V_26 ;
int V_8 = F_2 ( V_6 -> V_9 ,
V_6 -> V_10 -> V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
F_3 ( V_6 -> V_14 , L_2 , V_19 ,
V_18 , V_18 -> V_20 , V_18 -> V_21 ) ;
F_11 ( ! F_12 ( & V_18 -> V_27 ) ) ;
F_5 ( NULL == V_6 -> V_10 ) ;
V_16 -> V_28 = 1 ;
if ( V_16 -> V_29 != V_6 -> V_10 -> V_29 ||
V_18 -> V_30 != V_6 -> V_9 ||
V_18 -> V_31 != V_6 -> V_12 ||
V_18 -> V_25 != V_25 ) {
V_16 -> V_29 = V_6 -> V_10 -> V_29 ;
V_18 -> V_30 = V_6 -> V_9 ;
V_18 -> V_31 = V_6 -> V_12 ;
V_18 -> V_25 = V_25 ;
V_18 -> V_22 = V_23 ;
}
V_18 -> V_4 = V_8 * V_18 -> V_31 ;
if ( 0 != V_18 -> V_20 && V_18 -> V_21 < V_18 -> V_4 ) {
V_26 = - V_32 ;
goto V_33;
}
if ( V_18 -> V_22 == V_23 ) {
V_26 = F_13 ( V_2 , V_18 , NULL ) ;
if ( V_26 )
goto V_34;
V_18 -> V_22 = V_35 ;
}
V_16 -> V_28 = 0 ;
return 0 ;
V_34:
F_4 ( V_2 , V_16 ) ;
V_33:
V_16 -> V_28 = 0 ;
return V_26 ;
}
static int F_14 ( struct V_36 * V_37 )
{
struct V_17 * V_38 = & V_37 -> V_39 -> V_18 ;
struct V_40 * V_41 = V_37 -> V_6 -> V_14 ;
int V_26 ;
if ( F_15 ( ! V_37 -> V_39 ) ) {
F_16 ( V_41 , L_3 ) ;
return - V_42 ;
}
V_26 = F_17 ( V_37 -> V_43 ,
F_18 ( V_38 ) ,
V_38 -> V_4 , V_37 -> V_44 -> V_45 +
V_46 , V_47 ) ;
if ( F_15 ( V_26 ) )
F_16 ( V_41 , L_4 ) ;
return V_26 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_48 * V_49 = F_20 ( V_6 -> V_14 ) ;
struct V_36 * V_37 = V_49 -> V_50 ;
struct V_15 * V_16 = F_10 ( V_18 , struct V_15 , V_18 ) ;
F_3 ( V_6 -> V_14 , L_2 , V_19 ,
V_18 , V_18 -> V_20 , V_18 -> V_21 ) ;
F_21 ( & V_18 -> V_27 , & V_37 -> V_51 ) ;
V_18 -> V_22 = V_52 ;
if ( ! V_37 -> V_39 ) {
V_37 -> V_39 = V_16 ;
if ( ! F_14 ( V_37 ) ) {
unsigned int V_53 ;
V_53 = F_22 ( V_37 -> V_54 + V_55 ) |
V_56 ;
F_23 ( V_53 , V_37 -> V_54 + V_55 ) ;
}
}
}
static void F_24 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_15 * V_16 = F_10 ( V_18 , struct V_15 , V_18 ) ;
#ifdef F_25
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_40 * V_41 = V_6 -> V_14 ;
F_3 ( V_41 , L_2 , V_19 ,
V_18 , V_18 -> V_20 , V_18 -> V_21 ) ;
switch ( V_18 -> V_22 ) {
case V_52 :
F_3 ( V_41 , L_5 , V_19 ) ;
break;
case V_57 :
F_3 ( V_41 , L_6 , V_19 ) ;
break;
case V_35 :
F_3 ( V_41 , L_7 , V_19 ) ;
break;
default:
F_3 ( V_41 , L_8 , V_19 ) ;
break;
}
#endif
F_4 ( V_2 , V_16 ) ;
}
static void F_26 ( struct V_36 * V_37 ,
struct V_17 * V_18 ,
struct V_15 * V_16 )
{
F_27 ( & V_18 -> V_27 ) ;
V_18 -> V_22 = V_58 ;
F_28 ( & V_18 -> V_59 ) ;
V_18 -> V_60 ++ ;
F_29 ( & V_18 -> V_61 ) ;
if ( F_12 ( & V_37 -> V_51 ) ) {
V_37 -> V_39 = NULL ;
return;
}
V_37 -> V_39 = F_30 ( V_37 -> V_51 . V_62 ,
struct V_15 , V_18 . V_27 ) ;
if ( F_31 ( ! F_14 ( V_37 ) ) ) {
unsigned int V_53 ;
V_53 = F_22 ( V_37 -> V_54 + V_55 ) | V_56 ;
F_23 ( V_53 , V_37 -> V_54 + V_55 ) ;
}
}
static void F_32 ( int V_63 , void * V_64 )
{
struct V_36 * V_37 = V_64 ;
struct V_40 * V_41 = V_37 -> V_6 -> V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
unsigned long V_65 ;
F_33 ( & V_37 -> V_66 , V_65 ) ;
F_34 ( V_63 ) ;
if ( F_15 ( ! V_37 -> V_39 ) ) {
F_16 ( V_41 , L_3 ) ;
goto V_33;
}
V_18 = & V_37 -> V_39 -> V_18 ;
V_16 = F_10 ( V_18 , struct V_15 , V_18 ) ;
F_11 ( V_16 -> V_28 || F_12 ( & V_18 -> V_27 ) ) ;
F_3 ( V_41 , L_2 , V_19 ,
V_18 , V_18 -> V_20 , V_18 -> V_21 ) ;
F_26 ( V_37 , V_18 , V_16 ) ;
V_33:
F_35 ( & V_37 -> V_66 , V_65 ) ;
}
static void F_36 ( struct V_1 * V_67 ,
struct V_5 * V_6 )
{
struct V_48 * V_49 = F_20 ( V_6 -> V_14 ) ;
struct V_36 * V_37 = V_49 -> V_50 ;
F_37 ( V_67 , & V_68 , V_6 -> V_14 ,
& V_37 -> V_66 , V_69 ,
V_70 ,
sizeof( struct V_15 ) , V_6 , & V_6 -> V_71 ) ;
}
static int F_38 ( struct V_36 * V_37 )
{
unsigned int V_72 = V_37 -> V_72 ;
unsigned long div ;
unsigned long V_73 ;
V_73 = F_39 ( V_37 -> V_74 ) ;
div = ( V_73 + 2 * V_72 - 1 ) / ( 2 * V_72 ) - 1 ;
F_3 ( V_37 -> V_6 -> V_14 ,
L_9 ,
V_73 / 1000 , V_72 / 1000 , div ) ;
return div ;
}
static void F_40 ( struct V_36 * V_37 )
{
unsigned int V_75 = V_76 ;
F_3 ( V_37 -> V_6 -> V_14 , L_10 ) ;
F_41 ( V_37 -> V_74 ) ;
F_23 ( V_75 , V_37 -> V_54 + V_55 ) ;
V_75 |= V_77 | V_78 | V_79 ;
V_75 |= F_42 ( F_38 ( V_37 ) ) ;
V_75 |= F_43 ( 2 ) ;
F_23 ( V_75 , V_37 -> V_54 + V_55 ) ;
}
static void F_44 ( struct V_36 * V_37 )
{
F_3 ( V_37 -> V_6 -> V_14 , L_11 ) ;
F_23 ( 0x00 , V_37 -> V_54 + V_55 ) ;
F_45 ( V_37 -> V_74 ) ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_48 * V_49 = F_20 ( V_6 -> V_14 ) ;
struct V_36 * V_37 = V_49 -> V_50 ;
if ( V_37 -> V_6 )
return - V_80 ;
F_47 ( V_6 -> V_14 , L_12 ,
V_6 -> V_81 ) ;
F_40 ( V_37 ) ;
V_37 -> V_6 = V_6 ;
return 0 ;
}
static void F_48 ( struct V_5 * V_6 )
{
struct V_48 * V_49 = F_20 ( V_6 -> V_14 ) ;
struct V_36 * V_37 = V_49 -> V_50 ;
unsigned int V_75 ;
F_5 ( V_6 != V_37 -> V_6 ) ;
V_75 = F_22 ( V_37 -> V_54 + V_55 ) & ~ V_82 ;
F_23 ( V_75 , V_37 -> V_54 + V_55 ) ;
F_34 ( V_37 -> V_43 ) ;
F_47 ( V_6 -> V_14 , L_13 ,
V_6 -> V_81 ) ;
F_44 ( V_37 ) ;
V_37 -> V_6 = NULL ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_83 * V_84 )
{
struct V_85 * V_86 = F_50 ( V_6 ) ;
return F_51 ( V_86 , V_87 , V_88 , V_84 ) ;
}
static int F_52 ( struct V_5 * V_6 )
{
struct V_85 * V_86 = F_50 ( V_6 ) ;
struct V_48 * V_49 = F_20 ( V_6 -> V_14 ) ;
struct V_36 * V_37 = V_49 -> V_50 ;
struct V_89 V_90 = { . type = V_91 ,} ;
unsigned long V_92 ;
unsigned int V_75 ;
int V_26 ;
V_26 = F_51 ( V_86 , V_87 , V_93 , & V_90 ) ;
if ( ! V_26 ) {
V_92 = F_53 ( & V_90 , V_94 ) ;
if ( ! V_92 ) {
F_54 ( V_6 -> V_14 ,
L_14 ,
V_90 . V_65 , V_94 ) ;
return - V_32 ;
}
} else if ( V_26 != - V_95 ) {
return V_26 ;
} else {
V_92 = V_94 ;
}
if ( ( V_92 & V_96 ) &&
( V_92 & V_97 ) ) {
if ( ! V_37 -> V_98 ||
V_37 -> V_98 -> V_65 & V_99 )
V_92 &= ~ V_97 ;
else
V_92 &= ~ V_96 ;
}
if ( ( V_92 & V_100 ) &&
( V_92 & V_101 ) ) {
if ( ! V_37 -> V_98 ||
V_37 -> V_98 -> V_65 & V_102 )
V_92 &= ~ V_101 ;
else
V_92 &= ~ V_100 ;
}
if ( ( V_92 & V_103 ) &&
( V_92 & V_104 ) ) {
if ( ! V_37 -> V_98 ||
V_37 -> V_98 -> V_65 & V_105 )
V_92 &= ~ V_104 ;
else
V_92 &= ~ V_103 ;
}
V_90 . V_65 = V_92 ;
V_26 = F_51 ( V_86 , V_87 , V_106 , & V_90 ) ;
if ( V_26 < 0 && V_26 != - V_95 ) {
F_3 ( V_6 -> V_14 , L_15 ,
V_92 , V_26 ) ;
return V_26 ;
}
V_75 = F_22 ( V_37 -> V_54 + V_55 ) ;
if ( V_92 & V_100 )
V_75 |= V_107 ;
if ( V_92 & V_96 )
V_75 |= V_108 ;
if ( V_92 & V_104 )
V_75 |= V_109 ;
F_23 ( V_75 , V_37 -> V_54 + V_55 ) ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_110 * V_111 )
{
struct V_85 * V_86 = F_50 ( V_6 ) ;
const struct V_112 * V_113 ;
struct V_114 * V_115 = & V_111 -> V_116 . V_115 ;
struct V_117 V_118 ;
int V_26 , V_119 ;
V_113 = F_56 ( V_6 , V_115 -> V_120 ) ;
if ( ! V_113 ) {
F_54 ( V_6 -> V_14 , L_16 ,
V_115 -> V_120 ) ;
return - V_32 ;
}
V_119 = V_113 -> V_11 -> V_121 ;
if ( V_119 > 8 ) {
F_54 ( V_6 -> V_14 ,
L_17 ,
V_119 , V_115 -> V_120 ) ;
return - V_32 ;
}
V_118 . V_30 = V_115 -> V_30 ;
V_118 . V_31 = V_115 -> V_31 ;
V_118 . V_25 = V_115 -> V_25 ;
V_118 . V_122 = V_115 -> V_122 ;
V_118 . V_29 = V_113 -> V_29 ;
V_26 = F_51 ( V_86 , V_87 , V_123 , & V_118 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_118 . V_29 != V_113 -> V_29 )
return - V_32 ;
V_115 -> V_30 = V_118 . V_30 ;
V_115 -> V_31 = V_118 . V_31 ;
V_115 -> V_25 = V_118 . V_25 ;
V_115 -> V_122 = V_118 . V_122 ;
V_6 -> V_10 = V_113 ;
return V_26 ;
}
static int F_57 ( struct V_5 * V_6 ,
struct V_110 * V_111 )
{
struct V_85 * V_86 = F_50 ( V_6 ) ;
const struct V_112 * V_113 ;
struct V_114 * V_115 = & V_111 -> V_116 . V_115 ;
struct V_117 V_118 ;
int V_26 ;
V_113 = F_56 ( V_6 , V_115 -> V_120 ) ;
if ( ! V_113 ) {
F_54 ( V_6 -> V_14 , L_16 ,
V_115 -> V_120 ) ;
return - V_32 ;
}
V_118 . V_30 = V_115 -> V_30 ;
V_118 . V_31 = V_115 -> V_31 ;
V_118 . V_25 = V_115 -> V_25 ;
V_118 . V_122 = V_115 -> V_122 ;
V_118 . V_29 = V_113 -> V_29 ;
V_26 = F_51 ( V_86 , V_87 , V_124 , & V_118 ) ;
if ( V_26 < 0 )
return V_26 ;
V_115 -> V_30 = V_118 . V_30 ;
V_115 -> V_31 = V_118 . V_31 ;
V_115 -> V_25 = V_118 . V_25 ;
V_115 -> V_122 = V_118 . V_122 ;
return 0 ;
}
static int F_58 ( struct V_5 * V_6 ,
struct V_125 * V_126 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_126 -> V_3 ; V_127 ++ ) {
struct V_15 * V_16 = F_10 ( V_6 -> V_128 . V_129 [ V_127 ] ,
struct V_15 , V_18 ) ;
V_16 -> V_28 = 0 ;
F_59 ( & V_16 -> V_18 . V_27 ) ;
}
return 0 ;
}
static unsigned int F_60 ( struct V_130 * V_130 , T_1 * V_131 )
{
struct V_5 * V_6 = V_130 -> V_132 ;
struct V_15 * V_16 ;
V_16 = F_30 ( V_6 -> V_128 . V_133 . V_62 , struct V_15 ,
V_18 . V_133 ) ;
F_61 ( V_130 , & V_16 -> V_18 . V_61 , V_131 ) ;
if ( V_16 -> V_18 . V_22 == V_58 ||
V_16 -> V_18 . V_22 == V_134 )
return V_135 | V_136 ;
return 0 ;
}
static int F_62 ( struct V_48 * V_49 ,
struct V_137 * V_138 )
{
F_63 ( V_138 -> V_139 , L_18 , sizeof( V_138 -> V_139 ) ) ;
V_138 -> V_140 = V_141 | V_142 ;
return 0 ;
}
static int T_2 F_64 ( struct V_143 * V_144 )
{
struct V_36 * V_37 ;
struct V_145 * V_44 ;
struct V_146 V_147 ;
struct V_74 * V_74 ;
void T_3 * V_54 ;
unsigned int V_148 ;
int V_149 = 0 ;
V_44 = F_65 ( V_144 , V_150 , 0 ) ;
V_148 = F_66 ( V_144 , 0 ) ;
if ( ! V_44 || ( int ) V_148 <= 0 ) {
V_149 = - V_151 ;
goto exit;
}
V_74 = F_67 ( & V_144 -> V_41 , L_19 ) ;
if ( F_68 ( V_74 ) ) {
V_149 = F_69 ( V_74 ) ;
goto exit;
}
V_37 = F_70 ( sizeof( * V_37 ) , V_152 ) ;
if ( ! V_37 ) {
F_16 ( & V_144 -> V_41 , L_20 ) ;
V_149 = - V_153 ;
goto V_154;
}
V_37 -> V_44 = V_44 ;
V_37 -> V_74 = V_74 ;
V_37 -> V_98 = V_144 -> V_41 . V_155 ;
if ( V_37 -> V_98 )
V_37 -> V_72 = V_37 -> V_98 -> V_156 * 10000 ;
if ( ! V_37 -> V_72 ) {
F_54 ( & V_144 -> V_41 ,
L_21
L_22 ) ;
V_37 -> V_72 = 20000000 ;
}
F_59 ( & V_37 -> V_51 ) ;
F_71 ( & V_37 -> V_66 ) ;
if ( ! F_72 ( V_44 -> V_45 , F_73 ( V_44 ) , V_157 ) ) {
V_149 = - V_80 ;
goto V_158;
}
V_54 = F_74 ( V_44 -> V_45 , F_73 ( V_44 ) ) ;
if ( ! V_54 ) {
V_149 = - V_153 ;
goto V_159;
}
V_37 -> V_148 = V_148 ;
V_37 -> V_54 = V_54 ;
V_37 -> V_43 = F_75 ( V_157 , V_160 ) ;
if ( V_37 -> V_43 < 0 ) {
F_16 ( & V_144 -> V_41 , L_23 ) ;
V_149 = - V_80 ;
goto V_161;
}
F_3 ( & V_144 -> V_41 , L_24 , V_37 -> V_43 ) ;
F_76 ( V_37 -> V_43 , F_32 , NULL ,
V_37 ) ;
F_77 ( V_37 -> V_43 , V_162 ,
V_163 , V_164 , 0 ) ;
F_78 ( V_37 -> V_43 , 0 ) ;
V_149 = F_79 ( & V_165 ) ;
if ( V_149 ) {
F_16 ( & V_144 -> V_41 , L_25 ) ;
goto V_166;
}
F_80 ( & V_167 , & V_168 -
& V_167 ) ;
V_147 . V_169 = ( long ) V_170 ;
V_147 . V_171 = ( long ) F_81 ( V_37 -> V_43 ) ;
V_147 . V_172 = ( long ) V_37 -> V_54 + V_55 ;
V_147 . V_173 = ( long ) V_37 -> V_54 + V_174 ;
V_147 . V_175 = 1 << V_37 -> V_43 ;
F_82 ( & V_147 ) ;
F_83 ( V_148 , 1 ) ;
F_84 ( V_148 ) ;
V_37 -> V_176 . V_177 = V_157 ;
V_37 -> V_176 . V_178 = & V_179 ;
V_37 -> V_176 . V_50 = V_37 ;
V_37 -> V_176 . V_180 . V_41 = & V_144 -> V_41 ;
V_37 -> V_176 . V_181 = V_144 -> V_182 ;
V_149 = F_85 ( & V_37 -> V_176 ) ;
if ( V_149 )
goto V_183;
F_47 ( & V_144 -> V_41 , L_26 ) ;
return 0 ;
V_183:
F_86 ( V_148 ) ;
F_83 ( V_148 , 0 ) ;
F_87 ( & V_165 ) ;
V_166:
F_88 ( V_37 -> V_43 ) ;
V_161:
F_89 ( V_54 ) ;
V_159:
F_90 ( V_44 -> V_45 , F_73 ( V_44 ) ) ;
V_158:
F_91 ( V_37 ) ;
V_154:
F_92 ( V_74 ) ;
exit:
return V_149 ;
}
static int T_4 F_93 ( struct V_143 * V_144 )
{
struct V_48 * V_176 = F_20 ( & V_144 -> V_41 ) ;
struct V_36 * V_37 = F_10 ( V_176 ,
struct V_36 , V_176 ) ;
struct V_145 * V_44 ;
F_88 ( V_37 -> V_43 ) ;
F_86 ( V_37 -> V_148 ) ;
F_83 ( V_37 -> V_148 , 0 ) ;
F_87 ( & V_165 ) ;
F_92 ( V_37 -> V_74 ) ;
F_94 ( V_176 ) ;
F_89 ( V_37 -> V_54 ) ;
V_44 = V_37 -> V_44 ;
F_90 ( V_44 -> V_45 , F_73 ( V_44 ) ) ;
F_91 ( V_37 ) ;
F_47 ( & V_144 -> V_41 , L_27 ) ;
return 0 ;
}
static int T_2 F_95 ( void )
{
return F_96 ( & V_184 , F_64 ) ;
}
static void T_4 F_97 ( void )
{
return F_98 ( & V_184 ) ;
}
