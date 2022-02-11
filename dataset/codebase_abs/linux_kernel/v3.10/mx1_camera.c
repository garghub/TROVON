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
sizeof( struct V_11 ) , V_6 , & V_48 -> V_70 ) ;
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
static int F_48 ( struct V_5 * V_6 )
{
struct V_82 * V_83 = F_49 ( V_6 ) ;
struct V_47 * V_48 = F_19 ( V_6 -> V_10 ) ;
struct V_35 * V_36 = V_48 -> V_49 ;
struct V_84 V_85 = { . type = V_86 ,} ;
unsigned long V_87 ;
unsigned int V_74 ;
int V_22 ;
V_22 = F_50 ( V_83 , V_88 , V_89 , & V_85 ) ;
if ( ! V_22 ) {
V_87 = F_51 ( & V_85 , V_90 ) ;
if ( ! V_87 ) {
F_52 ( V_6 -> V_10 ,
L_14 ,
V_85 . V_64 , V_90 ) ;
return - V_31 ;
}
} else if ( V_22 != - V_91 ) {
return V_22 ;
} else {
V_87 = V_90 ;
}
if ( ( V_87 & V_92 ) &&
( V_87 & V_93 ) ) {
if ( ! V_36 -> V_94 ||
V_36 -> V_94 -> V_64 & V_95 )
V_87 &= ~ V_93 ;
else
V_87 &= ~ V_92 ;
}
if ( ( V_87 & V_96 ) &&
( V_87 & V_97 ) ) {
if ( ! V_36 -> V_94 ||
V_36 -> V_94 -> V_64 & V_98 )
V_87 &= ~ V_97 ;
else
V_87 &= ~ V_96 ;
}
if ( ( V_87 & V_99 ) &&
( V_87 & V_100 ) ) {
if ( ! V_36 -> V_94 ||
V_36 -> V_94 -> V_64 & V_101 )
V_87 &= ~ V_100 ;
else
V_87 &= ~ V_99 ;
}
V_85 . V_64 = V_87 ;
V_22 = F_50 ( V_83 , V_88 , V_102 , & V_85 ) ;
if ( V_22 < 0 && V_22 != - V_91 ) {
F_2 ( V_6 -> V_10 , L_15 ,
V_87 , V_22 ) ;
return V_22 ;
}
V_74 = F_21 ( V_36 -> V_53 + V_54 ) ;
if ( V_87 & V_96 )
V_74 |= V_103 ;
if ( V_87 & V_92 )
V_74 |= V_104 ;
if ( V_87 & V_100 )
V_74 |= V_105 ;
F_22 ( V_74 , V_36 -> V_53 + V_54 ) ;
return 0 ;
}
static int F_53 ( struct V_5 * V_6 ,
struct V_106 * V_107 )
{
struct V_82 * V_83 = F_49 ( V_6 ) ;
const struct V_108 * V_109 ;
struct V_110 * V_111 = & V_107 -> V_112 . V_111 ;
struct V_113 V_114 ;
int V_22 , V_115 ;
V_109 = F_54 ( V_6 , V_111 -> V_116 ) ;
if ( ! V_109 ) {
F_52 ( V_6 -> V_10 , L_16 ,
V_111 -> V_116 ) ;
return - V_31 ;
}
V_115 = V_109 -> V_117 -> V_118 ;
if ( V_115 > 8 ) {
F_52 ( V_6 -> V_10 ,
L_17 ,
V_115 , V_111 -> V_116 ) ;
return - V_31 ;
}
V_114 . V_27 = V_111 -> V_27 ;
V_114 . V_29 = V_111 -> V_29 ;
V_114 . V_21 = V_111 -> V_21 ;
V_114 . V_119 = V_111 -> V_119 ;
V_114 . V_26 = V_109 -> V_26 ;
V_22 = F_50 ( V_83 , V_88 , V_120 , & V_114 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_114 . V_26 != V_109 -> V_26 )
return - V_31 ;
V_111 -> V_27 = V_114 . V_27 ;
V_111 -> V_29 = V_114 . V_29 ;
V_111 -> V_21 = V_114 . V_21 ;
V_111 -> V_119 = V_114 . V_119 ;
V_6 -> V_24 = V_109 ;
return V_22 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_106 * V_107 )
{
struct V_82 * V_83 = F_49 ( V_6 ) ;
const struct V_108 * V_109 ;
struct V_110 * V_111 = & V_107 -> V_112 . V_111 ;
struct V_113 V_114 ;
int V_22 ;
V_109 = F_54 ( V_6 , V_111 -> V_116 ) ;
if ( ! V_109 ) {
F_52 ( V_6 -> V_10 , L_16 ,
V_111 -> V_116 ) ;
return - V_31 ;
}
V_114 . V_27 = V_111 -> V_27 ;
V_114 . V_29 = V_111 -> V_29 ;
V_114 . V_21 = V_111 -> V_21 ;
V_114 . V_119 = V_111 -> V_119 ;
V_114 . V_26 = V_109 -> V_26 ;
V_22 = F_50 ( V_83 , V_88 , V_121 , & V_114 ) ;
if ( V_22 < 0 )
return V_22 ;
V_111 -> V_27 = V_114 . V_27 ;
V_111 -> V_29 = V_114 . V_29 ;
V_111 -> V_21 = V_114 . V_21 ;
V_111 -> V_119 = V_114 . V_119 ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_122 * V_123 )
{
int V_124 ;
for ( V_124 = 0 ; V_124 < V_123 -> V_3 ; V_124 ++ ) {
struct V_11 * V_12 = F_9 ( V_6 -> V_125 . V_126 [ V_124 ] ,
struct V_11 , V_14 ) ;
V_12 -> V_25 = 0 ;
F_57 ( & V_12 -> V_14 . V_23 ) ;
}
return 0 ;
}
static unsigned int F_58 ( struct V_127 * V_127 , T_1 * V_128 )
{
struct V_5 * V_6 = V_127 -> V_129 ;
struct V_11 * V_12 ;
V_12 = F_29 ( V_6 -> V_125 . V_130 . V_61 , struct V_11 ,
V_14 . V_130 ) ;
F_59 ( V_127 , & V_12 -> V_14 . V_60 , V_128 ) ;
if ( V_12 -> V_14 . V_18 == V_57 ||
V_12 -> V_14 . V_18 == V_131 )
return V_132 | V_133 ;
return 0 ;
}
static int F_60 ( struct V_47 * V_48 ,
struct V_134 * V_135 )
{
F_61 ( V_135 -> V_136 , L_18 , sizeof( V_135 -> V_136 ) ) ;
V_135 -> V_137 = V_138 | V_139 ;
return 0 ;
}
static int T_2 F_62 ( struct V_140 * V_141 )
{
struct V_35 * V_36 ;
struct V_142 * V_43 ;
struct V_143 V_144 ;
struct V_73 * V_73 ;
void T_3 * V_53 ;
unsigned int V_145 ;
int V_146 = 0 ;
V_43 = F_63 ( V_141 , V_147 , 0 ) ;
V_145 = F_64 ( V_141 , 0 ) ;
if ( ! V_43 || ( int ) V_145 <= 0 ) {
V_146 = - V_148 ;
goto exit;
}
V_73 = F_65 ( & V_141 -> V_40 , L_19 ) ;
if ( F_66 ( V_73 ) ) {
V_146 = F_67 ( V_73 ) ;
goto exit;
}
V_36 = F_68 ( sizeof( * V_36 ) , V_149 ) ;
if ( ! V_36 ) {
F_15 ( & V_141 -> V_40 , L_20 ) ;
V_146 = - V_150 ;
goto V_151;
}
V_36 -> V_43 = V_43 ;
V_36 -> V_73 = V_73 ;
V_36 -> V_94 = V_141 -> V_40 . V_152 ;
if ( V_36 -> V_94 )
V_36 -> V_71 = V_36 -> V_94 -> V_153 * 10000 ;
if ( ! V_36 -> V_71 ) {
F_52 ( & V_141 -> V_40 ,
L_21
L_22 ) ;
V_36 -> V_71 = 20000000 ;
}
F_57 ( & V_36 -> V_50 ) ;
F_69 ( & V_36 -> V_65 ) ;
if ( ! F_70 ( V_43 -> V_44 , F_71 ( V_43 ) , V_154 ) ) {
V_146 = - V_79 ;
goto V_155;
}
V_53 = F_72 ( V_43 -> V_44 , F_71 ( V_43 ) ) ;
if ( ! V_53 ) {
V_146 = - V_150 ;
goto V_156;
}
V_36 -> V_145 = V_145 ;
V_36 -> V_53 = V_53 ;
V_36 -> V_42 = F_73 ( V_154 , V_157 ) ;
if ( V_36 -> V_42 < 0 ) {
F_15 ( & V_141 -> V_40 , L_23 ) ;
V_146 = - V_79 ;
goto V_158;
}
F_2 ( & V_141 -> V_40 , L_24 , V_36 -> V_42 ) ;
F_74 ( V_36 -> V_42 , F_31 , NULL ,
V_36 ) ;
F_75 ( V_36 -> V_42 , V_159 ,
V_160 , V_161 , 0 ) ;
F_76 ( V_36 -> V_42 , 0 ) ;
V_146 = F_77 ( & V_162 ) ;
if ( V_146 ) {
F_15 ( & V_141 -> V_40 , L_25 ) ;
goto V_163;
}
F_78 ( & V_164 , & V_165 -
& V_164 ) ;
V_144 . V_166 = ( long ) V_167 ;
V_144 . V_168 = ( long ) F_79 ( V_36 -> V_42 ) ;
V_144 . V_169 = ( long ) V_36 -> V_53 + V_54 ;
V_144 . V_170 = ( long ) V_36 -> V_53 + V_171 ;
V_144 . V_172 = 1 << V_36 -> V_42 ;
F_80 ( & V_144 ) ;
F_81 ( V_145 , 1 ) ;
F_82 ( V_145 ) ;
V_36 -> V_173 . V_174 = V_154 ;
V_36 -> V_173 . V_175 = & V_176 ;
V_36 -> V_173 . V_49 = V_36 ;
V_36 -> V_173 . V_177 . V_40 = & V_141 -> V_40 ;
V_36 -> V_173 . V_178 = V_141 -> V_179 ;
V_146 = F_83 ( & V_36 -> V_173 ) ;
if ( V_146 )
goto V_180;
F_46 ( & V_141 -> V_40 , L_26 ) ;
return 0 ;
V_180:
F_84 ( V_145 ) ;
F_81 ( V_145 , 0 ) ;
F_85 ( & V_162 ) ;
V_163:
F_86 ( V_36 -> V_42 ) ;
V_158:
F_87 ( V_53 ) ;
V_156:
F_88 ( V_43 -> V_44 , F_71 ( V_43 ) ) ;
V_155:
F_89 ( V_36 ) ;
V_151:
F_90 ( V_73 ) ;
exit:
return V_146 ;
}
static int T_4 F_91 ( struct V_140 * V_141 )
{
struct V_47 * V_173 = F_19 ( & V_141 -> V_40 ) ;
struct V_35 * V_36 = F_9 ( V_173 ,
struct V_35 , V_173 ) ;
struct V_142 * V_43 ;
F_86 ( V_36 -> V_42 ) ;
F_84 ( V_36 -> V_145 ) ;
F_81 ( V_36 -> V_145 , 0 ) ;
F_85 ( & V_162 ) ;
F_90 ( V_36 -> V_73 ) ;
F_92 ( V_173 ) ;
F_87 ( V_36 -> V_53 ) ;
V_43 = V_36 -> V_43 ;
F_88 ( V_43 -> V_44 , F_71 ( V_43 ) ) ;
F_89 ( V_36 ) ;
F_46 ( & V_141 -> V_40 , L_27 ) ;
return 0 ;
}
