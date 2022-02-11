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
struct V_39 * V_40 = V_36 -> V_41 . V_6 -> V_10 ;
int V_22 ;
if ( F_14 ( ! V_36 -> V_38 ) ) {
F_15 ( V_40 , L_3 ) ;
return - V_42 ;
}
V_22 = F_16 ( V_36 -> V_43 ,
F_17 ( V_37 ) ,
V_37 -> V_4 , V_36 -> V_44 -> V_45 +
V_46 , V_47 ) ;
if ( F_14 ( V_22 ) )
F_15 ( V_40 , L_4 ) ;
return V_22 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_48 * V_49 = F_19 ( V_6 -> V_10 ) ;
struct V_35 * V_36 = V_49 -> V_50 ;
struct V_11 * V_12 = F_9 ( V_14 , struct V_11 , V_14 ) ;
F_2 ( V_6 -> V_10 , L_2 , V_15 ,
V_14 , V_14 -> V_16 , V_14 -> V_17 ) ;
F_20 ( & V_14 -> V_23 , & V_36 -> V_51 ) ;
V_14 -> V_18 = V_52 ;
if ( ! V_36 -> V_38 ) {
V_36 -> V_38 = V_12 ;
if ( ! F_13 ( V_36 ) ) {
unsigned int V_53 ;
V_53 = F_21 ( V_36 -> V_54 + V_55 ) |
V_56 ;
F_22 ( V_53 , V_36 -> V_54 + V_55 ) ;
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
case V_52 :
F_2 ( V_40 , L_5 , V_15 ) ;
break;
case V_57 :
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
V_14 -> V_18 = V_58 ;
F_27 ( & V_14 -> V_59 ) ;
V_14 -> V_60 ++ ;
F_28 ( & V_14 -> V_61 ) ;
if ( F_11 ( & V_36 -> V_51 ) ) {
V_36 -> V_38 = NULL ;
return;
}
V_36 -> V_38 = F_29 ( V_36 -> V_51 . V_62 ,
struct V_11 , V_14 . V_23 ) ;
if ( F_30 ( ! F_13 ( V_36 ) ) ) {
unsigned int V_53 ;
V_53 = F_21 ( V_36 -> V_54 + V_55 ) | V_56 ;
F_22 ( V_53 , V_36 -> V_54 + V_55 ) ;
}
}
static void F_31 ( int V_63 , void * V_64 )
{
struct V_35 * V_36 = V_64 ;
struct V_39 * V_40 = V_36 -> V_41 . V_6 -> V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned long V_65 ;
F_32 ( & V_36 -> V_66 , V_65 ) ;
F_33 ( V_63 ) ;
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
F_34 ( & V_36 -> V_66 , V_65 ) ;
}
static void F_35 ( struct V_1 * V_67 ,
struct V_5 * V_6 )
{
struct V_48 * V_49 = F_19 ( V_6 -> V_10 ) ;
struct V_35 * V_36 = V_49 -> V_50 ;
F_36 ( V_67 , & V_68 , V_6 -> V_10 ,
& V_36 -> V_66 , V_69 ,
V_70 ,
sizeof( struct V_11 ) , V_6 , & V_49 -> V_71 ) ;
}
static int F_37 ( struct V_35 * V_36 )
{
unsigned int V_72 = V_36 -> V_72 ;
unsigned long div ;
unsigned long V_73 ;
V_73 = F_38 ( V_36 -> V_74 ) ;
div = ( V_73 + 2 * V_72 - 1 ) / ( 2 * V_72 ) - 1 ;
F_2 ( V_36 -> V_41 . V_6 -> V_10 ,
L_9 ,
V_73 / 1000 , V_72 / 1000 , div ) ;
return div ;
}
static void F_39 ( struct V_35 * V_36 )
{
unsigned int V_75 = V_76 ;
F_2 ( V_36 -> V_41 . V_77 . V_40 , L_10 ) ;
F_40 ( V_36 -> V_74 ) ;
F_22 ( V_75 , V_36 -> V_54 + V_55 ) ;
V_75 |= V_78 | V_79 | V_80 ;
V_75 |= F_41 ( F_37 ( V_36 ) ) ;
V_75 |= F_42 ( 2 ) ;
F_22 ( V_75 , V_36 -> V_54 + V_55 ) ;
}
static void F_43 ( struct V_35 * V_36 )
{
F_2 ( V_36 -> V_41 . V_77 . V_40 , L_11 ) ;
F_22 ( 0x00 , V_36 -> V_54 + V_55 ) ;
F_44 ( V_36 -> V_74 ) ;
}
static int F_45 ( struct V_5 * V_6 )
{
F_46 ( V_6 -> V_10 , L_12 ,
V_6 -> V_81 ) ;
return 0 ;
}
static void F_47 ( struct V_5 * V_6 )
{
F_46 ( V_6 -> V_10 , L_13 ,
V_6 -> V_81 ) ;
}
static int F_48 ( struct V_48 * V_49 )
{
struct V_35 * V_36 = V_49 -> V_50 ;
F_39 ( V_36 ) ;
return 0 ;
}
static void F_49 ( struct V_48 * V_49 )
{
struct V_35 * V_36 = V_49 -> V_50 ;
unsigned int V_75 ;
V_75 = F_21 ( V_36 -> V_54 + V_55 ) & ~ V_82 ;
F_22 ( V_75 , V_36 -> V_54 + V_55 ) ;
F_33 ( V_36 -> V_43 ) ;
F_43 ( V_36 ) ;
}
static int F_50 ( struct V_5 * V_6 )
{
struct V_83 * V_84 = F_51 ( V_6 ) ;
struct V_48 * V_49 = F_19 ( V_6 -> V_10 ) ;
struct V_35 * V_36 = V_49 -> V_50 ;
struct V_85 V_86 = { . type = V_87 ,} ;
unsigned long V_88 ;
unsigned int V_75 ;
int V_22 ;
V_22 = F_52 ( V_84 , V_89 , V_90 , & V_86 ) ;
if ( ! V_22 ) {
V_88 = F_53 ( & V_86 , V_91 ) ;
if ( ! V_88 ) {
F_54 ( V_6 -> V_10 ,
L_14 ,
V_86 . V_65 , V_91 ) ;
return - V_31 ;
}
} else if ( V_22 != - V_92 ) {
return V_22 ;
} else {
V_88 = V_91 ;
}
if ( ( V_88 & V_93 ) &&
( V_88 & V_94 ) ) {
if ( ! V_36 -> V_95 ||
V_36 -> V_95 -> V_65 & V_96 )
V_88 &= ~ V_94 ;
else
V_88 &= ~ V_93 ;
}
if ( ( V_88 & V_97 ) &&
( V_88 & V_98 ) ) {
if ( ! V_36 -> V_95 ||
V_36 -> V_95 -> V_65 & V_99 )
V_88 &= ~ V_98 ;
else
V_88 &= ~ V_97 ;
}
if ( ( V_88 & V_100 ) &&
( V_88 & V_101 ) ) {
if ( ! V_36 -> V_95 ||
V_36 -> V_95 -> V_65 & V_102 )
V_88 &= ~ V_101 ;
else
V_88 &= ~ V_100 ;
}
V_86 . V_65 = V_88 ;
V_22 = F_52 ( V_84 , V_89 , V_103 , & V_86 ) ;
if ( V_22 < 0 && V_22 != - V_92 ) {
F_2 ( V_6 -> V_10 , L_15 ,
V_88 , V_22 ) ;
return V_22 ;
}
V_75 = F_21 ( V_36 -> V_54 + V_55 ) ;
if ( V_88 & V_97 )
V_75 |= V_104 ;
if ( V_88 & V_93 )
V_75 |= V_105 ;
if ( V_88 & V_101 )
V_75 |= V_106 ;
F_22 ( V_75 , V_36 -> V_54 + V_55 ) ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_107 * V_108 )
{
struct V_83 * V_84 = F_51 ( V_6 ) ;
const struct V_109 * V_110 ;
struct V_111 * V_112 = & V_108 -> V_113 . V_112 ;
struct V_114 V_115 ;
int V_22 , V_116 ;
V_110 = F_56 ( V_6 , V_112 -> V_117 ) ;
if ( ! V_110 ) {
F_54 ( V_6 -> V_10 , L_16 ,
V_112 -> V_117 ) ;
return - V_31 ;
}
V_116 = V_110 -> V_118 -> V_119 ;
if ( V_116 > 8 ) {
F_54 ( V_6 -> V_10 ,
L_17 ,
V_116 , V_112 -> V_117 ) ;
return - V_31 ;
}
V_115 . V_27 = V_112 -> V_27 ;
V_115 . V_29 = V_112 -> V_29 ;
V_115 . V_21 = V_112 -> V_21 ;
V_115 . V_120 = V_112 -> V_120 ;
V_115 . V_26 = V_110 -> V_26 ;
V_22 = F_52 ( V_84 , V_89 , V_121 , & V_115 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_115 . V_26 != V_110 -> V_26 )
return - V_31 ;
V_112 -> V_27 = V_115 . V_27 ;
V_112 -> V_29 = V_115 . V_29 ;
V_112 -> V_21 = V_115 . V_21 ;
V_112 -> V_120 = V_115 . V_120 ;
V_6 -> V_24 = V_110 ;
return V_22 ;
}
static int F_57 ( struct V_5 * V_6 ,
struct V_107 * V_108 )
{
struct V_83 * V_84 = F_51 ( V_6 ) ;
const struct V_109 * V_110 ;
struct V_111 * V_112 = & V_108 -> V_113 . V_112 ;
struct V_114 V_115 ;
int V_22 ;
V_110 = F_56 ( V_6 , V_112 -> V_117 ) ;
if ( ! V_110 ) {
F_54 ( V_6 -> V_10 , L_16 ,
V_112 -> V_117 ) ;
return - V_31 ;
}
V_115 . V_27 = V_112 -> V_27 ;
V_115 . V_29 = V_112 -> V_29 ;
V_115 . V_21 = V_112 -> V_21 ;
V_115 . V_120 = V_112 -> V_120 ;
V_115 . V_26 = V_110 -> V_26 ;
V_22 = F_52 ( V_84 , V_89 , V_122 , & V_115 ) ;
if ( V_22 < 0 )
return V_22 ;
V_112 -> V_27 = V_115 . V_27 ;
V_112 -> V_29 = V_115 . V_29 ;
V_112 -> V_21 = V_115 . V_21 ;
V_112 -> V_120 = V_115 . V_120 ;
return 0 ;
}
static int F_58 ( struct V_5 * V_6 ,
struct V_123 * V_124 )
{
int V_125 ;
for ( V_125 = 0 ; V_125 < V_124 -> V_3 ; V_125 ++ ) {
struct V_11 * V_12 = F_9 ( V_6 -> V_126 . V_127 [ V_125 ] ,
struct V_11 , V_14 ) ;
V_12 -> V_25 = 0 ;
F_59 ( & V_12 -> V_14 . V_23 ) ;
}
return 0 ;
}
static unsigned int F_60 ( struct V_128 * V_128 , T_1 * V_129 )
{
struct V_5 * V_6 = V_128 -> V_130 ;
struct V_11 * V_12 ;
V_12 = F_29 ( V_6 -> V_126 . V_131 . V_62 , struct V_11 ,
V_14 . V_131 ) ;
F_61 ( V_128 , & V_12 -> V_14 . V_61 , V_129 ) ;
if ( V_12 -> V_14 . V_18 == V_58 ||
V_12 -> V_14 . V_18 == V_132 )
return V_133 | V_134 ;
return 0 ;
}
static int F_62 ( struct V_48 * V_49 ,
struct V_135 * V_136 )
{
F_63 ( V_136 -> V_137 , L_18 , sizeof( V_136 -> V_137 ) ) ;
V_136 -> V_138 = V_139 | V_140 ;
return 0 ;
}
static int T_2 F_64 ( struct V_141 * V_142 )
{
struct V_35 * V_36 ;
struct V_143 * V_44 ;
struct V_144 V_145 ;
struct V_74 * V_74 ;
void T_3 * V_54 ;
unsigned int V_146 ;
int V_147 = 0 ;
V_44 = F_65 ( V_142 , V_148 , 0 ) ;
V_146 = F_66 ( V_142 , 0 ) ;
if ( ! V_44 || ( int ) V_146 <= 0 ) {
V_147 = - V_149 ;
goto exit;
}
V_74 = F_67 ( & V_142 -> V_40 , L_19 ) ;
if ( F_68 ( V_74 ) ) {
V_147 = F_69 ( V_74 ) ;
goto exit;
}
V_36 = F_70 ( sizeof( * V_36 ) , V_150 ) ;
if ( ! V_36 ) {
F_15 ( & V_142 -> V_40 , L_20 ) ;
V_147 = - V_151 ;
goto V_152;
}
V_36 -> V_44 = V_44 ;
V_36 -> V_74 = V_74 ;
V_36 -> V_95 = V_142 -> V_40 . V_153 ;
if ( V_36 -> V_95 )
V_36 -> V_72 = V_36 -> V_95 -> V_154 * 10000 ;
if ( ! V_36 -> V_72 ) {
F_54 ( & V_142 -> V_40 ,
L_21
L_22 ) ;
V_36 -> V_72 = 20000000 ;
}
F_59 ( & V_36 -> V_51 ) ;
F_71 ( & V_36 -> V_66 ) ;
if ( ! F_72 ( V_44 -> V_45 , F_73 ( V_44 ) , V_155 ) ) {
V_147 = - V_156 ;
goto V_157;
}
V_54 = F_74 ( V_44 -> V_45 , F_73 ( V_44 ) ) ;
if ( ! V_54 ) {
V_147 = - V_151 ;
goto V_158;
}
V_36 -> V_146 = V_146 ;
V_36 -> V_54 = V_54 ;
V_36 -> V_43 = F_75 ( V_155 , V_159 ) ;
if ( V_36 -> V_43 < 0 ) {
F_15 ( & V_142 -> V_40 , L_23 ) ;
V_147 = - V_156 ;
goto V_160;
}
F_2 ( & V_142 -> V_40 , L_24 , V_36 -> V_43 ) ;
F_76 ( V_36 -> V_43 , F_31 , NULL ,
V_36 ) ;
F_77 ( V_36 -> V_43 , V_161 ,
V_162 , V_163 , 0 ) ;
F_78 ( V_36 -> V_43 , 0 ) ;
V_147 = F_79 ( & V_164 ) ;
if ( V_147 ) {
F_15 ( & V_142 -> V_40 , L_25 ) ;
goto V_165;
}
F_80 ( & V_166 , & V_167 -
& V_166 ) ;
V_145 . V_168 = ( long ) V_169 ;
V_145 . V_170 = ( long ) F_81 ( V_36 -> V_43 ) ;
V_145 . V_171 = ( long ) V_36 -> V_54 + V_55 ;
V_145 . V_172 = ( long ) V_36 -> V_54 + V_173 ;
V_145 . V_174 = 1 << V_36 -> V_43 ;
F_82 ( & V_145 ) ;
F_83 ( V_146 , 1 ) ;
F_84 ( V_146 ) ;
V_36 -> V_41 . V_175 = V_155 ;
V_36 -> V_41 . V_176 = & V_177 ;
V_36 -> V_41 . V_50 = V_36 ;
V_36 -> V_41 . V_77 . V_40 = & V_142 -> V_40 ;
V_36 -> V_41 . V_178 = V_142 -> V_179 ;
V_147 = F_85 ( & V_36 -> V_41 ) ;
if ( V_147 )
goto V_180;
F_46 ( & V_142 -> V_40 , L_26 ) ;
return 0 ;
V_180:
F_86 ( V_146 ) ;
F_83 ( V_146 , 0 ) ;
F_87 ( & V_164 ) ;
V_165:
F_88 ( V_36 -> V_43 ) ;
V_160:
F_89 ( V_54 ) ;
V_158:
F_90 ( V_44 -> V_45 , F_73 ( V_44 ) ) ;
V_157:
F_91 ( V_36 ) ;
V_152:
F_92 ( V_74 ) ;
exit:
return V_147 ;
}
static int T_4 F_93 ( struct V_141 * V_142 )
{
struct V_48 * V_41 = F_19 ( & V_142 -> V_40 ) ;
struct V_35 * V_36 = F_9 ( V_41 ,
struct V_35 , V_41 ) ;
struct V_143 * V_44 ;
F_88 ( V_36 -> V_43 ) ;
F_86 ( V_36 -> V_146 ) ;
F_83 ( V_36 -> V_146 , 0 ) ;
F_87 ( & V_164 ) ;
F_92 ( V_36 -> V_74 ) ;
F_94 ( V_41 ) ;
F_89 ( V_36 -> V_54 ) ;
V_44 = V_36 -> V_44 ;
F_90 ( V_44 -> V_45 , F_73 ( V_44 ) ) ;
F_91 ( V_36 ) ;
F_46 ( & V_142 -> V_40 , L_27 ) ;
return 0 ;
}
