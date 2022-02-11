static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 -> V_2 -> V_7 -> V_8 ( V_5 -> V_6 -> V_2 , V_3 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_7 -> V_10 . V_11 ;
struct V_12 * V_13 ;
V_13 = & V_10 -> V_14 ;
F_4 ( & V_10 -> V_15 ) ;
F_5 ( V_2 , V_13 ) ;
F_6 ( F_7 ( V_2 ) , V_2 -> V_7 , 1 ) ;
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_7 -> V_10 . V_11 ;
F_4 ( & V_10 -> V_15 ) ;
if ( F_10 ( V_2 ) )
F_6 ( F_7 ( V_2 ) , V_2 -> V_7 , - 1 ) ;
F_8 ( & V_10 -> V_15 ) ;
}
static int F_11 ( struct V_16 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = 0 ;
if ( ! V_2 )
goto V_18;
V_5 = F_2 ( V_2 ) ;
F_12 ( V_2 ) ;
if ( V_2 -> V_19 == V_20 )
F_13 ( V_2 , V_21 ) ;
else
F_14 ( V_2 ) ;
if ( V_5 -> V_22 ) {
V_2 -> V_19 = V_23 ;
V_2 -> V_24 ( V_2 ) ;
} else {
V_17 = F_15 ( V_5 ) ;
F_16 ( V_2 , V_25 ) ;
V_2 -> V_26 |= V_27 ;
}
if ( V_5 -> V_6 ) {
F_17 ( V_5 -> V_6 ) ;
V_5 -> V_6 = NULL ;
}
F_18 ( V_2 ) ;
V_1 -> V_2 = NULL ;
if ( V_5 -> V_22 ) {
F_19 ( & V_5 -> V_28 , V_29 ) ;
} else if ( V_2 -> V_19 == V_23 ) {
F_20 ( & V_5 -> V_30 ) ;
F_19 ( & V_5 -> V_28 ,
V_31 ) ;
}
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
V_18:
return V_17 ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 != V_23 )
return;
if ( ! F_24 ( V_2 , V_25 ) )
return;
F_25 ( V_2 ) ;
}
static struct V_1 * F_26 ( struct V_32 * V_32 , struct V_16 * V_1 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
V_2 = F_27 ( V_32 , V_33 , V_34 , & V_35 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_28 ( V_1 , V_2 ) ;
V_2 -> V_19 = V_36 ;
V_2 -> V_37 = F_23 ;
V_2 -> V_38 = V_39 ;
V_5 = F_2 ( V_2 ) ;
F_29 ( & V_5 -> V_40 , V_41 ) ;
F_30 ( & V_5 -> V_42 ) ;
F_31 ( & V_5 -> V_43 ) ;
F_32 ( & V_5 -> V_28 , V_44 ) ;
V_2 -> V_7 -> V_45 ( V_2 ) ;
F_33 ( V_2 ) ;
return V_2 ;
}
static int F_34 ( struct V_16 * V_1 , struct V_46 * V_47 ,
int V_48 )
{
struct V_49 * V_50 = (struct V_49 * ) V_47 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 ;
V_5 = F_2 ( V_2 ) ;
V_17 = - V_51 ;
if ( V_48 < sizeof( struct V_49 ) )
goto V_18;
V_17 = - V_52 ;
if ( ( V_50 -> V_53 != V_54 ) &&
( ( V_50 -> V_53 != V_55 ) ||
( V_50 -> V_56 . V_57 != F_35 ( V_58 ) ) ) )
goto V_18;
F_14 ( V_2 ) ;
V_17 = - V_51 ;
if ( V_2 -> V_19 != V_36 )
goto V_59;
V_5 -> V_6 -> V_2 -> V_60 = V_2 -> V_60 ;
V_17 = F_36 ( V_5 -> V_6 , V_47 , V_48 ) ;
V_59:
F_21 ( V_2 ) ;
V_18:
return V_17 ;
}
static void F_37 ( struct V_1 * V_61 , struct V_1 * V_62 ,
unsigned long V_63 )
{
V_61 -> V_64 = V_62 -> V_64 ;
V_61 -> V_65 = V_62 -> V_65 ;
V_61 -> V_66 = V_62 -> V_66 ;
V_61 -> V_67 = V_62 -> V_67 ;
V_61 -> V_68 = V_62 -> V_68 ;
V_61 -> V_69 = V_62 -> V_69 ;
V_61 -> V_70 = V_62 -> V_70 ;
V_61 -> V_71 = V_62 -> V_71 ;
V_61 -> V_72 = V_62 -> V_72 ;
V_61 -> V_73 = V_62 -> V_73 ;
V_61 -> V_74 &= ~ V_63 ;
V_61 -> V_74 |= V_62 -> V_74 & V_63 ;
}
static void F_38 ( struct V_4 * V_5 )
{
F_37 ( V_5 -> V_6 -> V_2 , & V_5 -> V_2 , V_75 ) ;
}
static void F_39 ( struct V_4 * V_5 )
{
F_37 ( & V_5 -> V_2 , V_5 -> V_6 -> V_2 , V_76 ) ;
}
int F_40 ( struct V_16 * V_6 ,
T_1 * V_77 , T_2 * V_78 )
{
struct V_79 * V_80 = F_41 ( V_6 -> V_2 ) ;
struct V_81 * V_82 ;
struct V_49 V_50 ;
int V_17 = - V_83 ;
int V_84 ;
if ( ! V_80 ) {
V_17 = - V_85 ;
goto V_18;
}
if ( ! V_80 -> V_86 ) {
V_17 = - V_87 ;
goto V_59;
}
F_42 ( V_6 , (struct V_46 * ) & V_50 , & V_84 ) ;
F_43 () ;
V_82 = F_44 ( V_80 -> V_86 ) ;
F_45 (in_dev) {
if ( ! F_46 ( V_50 . V_56 . V_57 , V_88 ) )
continue;
* V_78 = F_47 ( V_88 -> V_89 ) ;
* V_77 = V_88 -> V_90 & V_88 -> V_89 ;
V_17 = 0 ;
break;
} F_48 ( V_82 ) ;
F_49 () ;
V_59:
F_50 ( V_80 ) ;
V_18:
return V_17 ;
}
static int F_51 ( struct V_4 * V_5 , union V_91 * V_92 )
{
struct V_93 * V_94 = V_5 -> V_30 . V_94 ;
struct V_95 * V_96 ;
int V_97 ;
int V_17 ;
V_96 = & V_94 -> V_98 [ V_99 ] ;
V_97 = F_52 (
& V_96 -> V_100 ,
V_101 ) ;
if ( V_97 <= 0 ) {
struct V_102 V_103 ;
V_17 = F_53 ( V_5 , & V_103 , sizeof( V_103 ) ,
V_104 ) ;
return V_17 ;
}
V_17 = F_54 ( V_96 ) ;
if ( V_17 )
return V_105 ;
F_55 ( V_96 ) ;
V_17 = F_56 ( V_96 ,
V_5 -> V_30 . V_106 -> V_107 [ V_99 ] ) ;
if ( V_17 )
return V_105 ;
V_17 = F_57 ( V_96 ,
V_96 -> V_108 -> V_109 [ V_96 -> V_110 - 1 ] ,
V_92 , V_111 ) ;
if ( V_17 < 0 )
return V_112 ;
return V_17 ;
}
static void F_58 ( struct V_4 * V_5 ,
struct V_113 * V_114 )
{
V_5 -> V_30 . V_115 = V_114 -> V_116 ;
V_5 -> V_30 . V_117 . V_118 = F_59 ( V_114 -> V_119 ) ;
V_5 -> V_30 . V_120 = F_60 ( V_114 -> V_121 ) ;
F_61 ( & V_5 -> V_30 . V_122 , V_5 -> V_30 . V_120 ) ;
}
static void F_62 ( struct V_95 * V_96 ,
struct V_113 * V_114 )
{
V_96 -> V_123 = F_63 ( V_114 -> V_124 ) ;
memcpy ( V_96 -> V_125 , V_114 -> V_126 . V_92 , V_127 ) ;
memcpy ( V_96 -> V_128 , V_114 -> V_126 . V_109 , sizeof( V_96 -> V_128 ) ) ;
V_96 -> V_129 = F_63 ( V_114 -> V_130 ) ;
V_96 -> V_131 = V_114 -> V_132 ;
}
static int F_64 ( struct V_4 * V_5 )
{
struct V_49 * V_133 = (struct V_49 * ) V_5 -> V_50 ;
struct V_113 V_134 ;
int V_135 = V_136 ;
struct V_137 * V_108 ;
struct V_95 * V_96 ;
T_2 V_138 ;
int V_139 = 0 ;
int V_17 = 0 ;
T_2 V_110 ;
if ( F_65 ( V_5 ) ) {
V_139 = V_140 ;
goto V_141;
}
F_66 ( V_5 -> V_6 -> V_2 , & V_108 , & V_110 ) ;
if ( ! V_108 ) {
V_139 = V_142 ;
goto V_141;
}
V_139 = F_67 ( V_5 , V_108 , V_110 ) ;
if ( V_139 < 0 ) {
V_17 = V_139 ;
goto V_143;
}
if ( V_139 > 0 )
goto V_141;
V_139 = F_53 ( V_5 , & V_134 , sizeof( V_134 ) ,
V_144 ) ;
if ( V_139 < 0 ) {
V_17 = V_139 ;
goto V_143;
}
if ( V_139 > 0 )
goto V_141;
V_138 = V_134 . V_145 . V_146 ;
F_68 ( & V_147 ) ;
V_135 = F_69 ( V_5 , V_133 -> V_56 . V_57 , V_108 ,
V_110 , & V_134 . V_126 , V_138 ) ;
if ( V_135 < 0 ) {
V_17 = V_135 ;
if ( V_17 == - V_148 )
V_139 = V_149 ;
else if ( V_17 == - V_150 )
V_139 = V_151 ;
goto V_152;
}
V_96 = & V_5 -> V_30 . V_94 -> V_98 [ V_99 ] ;
F_58 ( V_5 , & V_134 ) ;
V_17 = F_70 ( V_5 ) ;
if ( V_17 ) {
V_139 = V_149 ;
goto V_152;
}
if ( V_135 == V_136 )
F_62 ( V_96 , & V_134 ) ;
V_17 = F_71 ( & V_5 -> V_30 , & V_134 ) ;
if ( V_17 ) {
V_139 = V_105 ;
goto V_152;
}
F_72 ( V_5 ) ;
F_73 ( V_5 ) ;
if ( V_135 == V_136 ) {
V_17 = F_74 ( V_96 ) ;
if ( V_17 ) {
V_139 = V_105 ;
goto V_152;
}
} else {
struct V_153 * V_154 = V_5 -> V_30 . V_106 ;
if ( ! V_154 -> V_155 ) {
V_17 = F_56 ( V_96 ,
V_154 -> V_107 [ V_99 ] ) ;
if ( V_17 ) {
V_139 = V_105 ;
goto V_152;
}
}
}
F_75 ( & V_5 -> V_30 ) ;
V_17 = F_76 ( V_5 ) ;
if ( V_17 )
goto V_156;
if ( V_135 == V_136 ) {
V_139 = F_51 (
V_5 , & V_108 -> V_92 [ V_110 - 1 ] ) ;
if ( V_139 < 0 ) {
V_17 = V_139 ;
goto V_156;
}
if ( V_139 > 0 )
goto V_152;
}
F_77 ( & V_147 ) ;
F_78 ( V_5 ) ;
V_157:
F_38 ( V_5 ) ;
if ( V_5 -> V_2 . V_19 == V_36 )
V_5 -> V_2 . V_19 = V_158 ;
return V_17 ? V_17 : V_135 ;
V_152:
F_77 ( & V_147 ) ;
F_20 ( & V_5 -> V_30 ) ;
V_141:
V_5 -> V_22 = true ;
if ( V_139 && ( V_139 != V_159 ) ) {
V_17 = F_79 ( V_5 , V_139 ) ;
if ( V_17 < sizeof( struct V_102 ) )
goto V_143;
}
goto V_157;
V_156:
F_77 ( & V_147 ) ;
F_20 ( & V_5 -> V_30 ) ;
V_143:
return V_17 ;
}
static int F_80 ( struct V_16 * V_1 , struct V_46 * V_50 ,
int V_160 , int V_161 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_51 ;
V_5 = F_2 ( V_2 ) ;
if ( V_160 < sizeof( V_50 -> V_162 ) )
goto V_143;
if ( V_50 -> V_162 != V_54 )
goto V_143;
V_5 -> V_50 = V_50 ;
F_14 ( V_2 ) ;
switch ( V_2 -> V_19 ) {
default:
goto V_18;
case V_158 :
V_17 = - V_163 ;
goto V_18;
case V_36 :
V_17 = 0 ;
break;
}
F_38 ( V_5 ) ;
V_17 = F_81 ( V_5 -> V_6 , V_50 , V_160 , V_161 ) ;
if ( V_17 )
goto V_18;
V_17 = F_64 ( V_5 ) ;
if ( V_17 < 0 )
goto V_18;
else
V_17 = 0 ;
V_18:
F_21 ( V_2 ) ;
V_143:
return V_17 ;
}
static int F_82 ( struct V_4 * V_164 , struct V_4 * * V_165 )
{
struct V_1 * V_2 = & V_164 -> V_2 ;
struct V_16 * V_166 ;
struct V_1 * V_167 ;
int V_17 ;
F_21 ( & V_164 -> V_2 ) ;
V_167 = F_26 ( F_7 ( V_2 ) , NULL ) ;
if ( ! V_167 ) {
V_17 = - V_148 ;
V_164 -> V_2 . V_73 = V_148 ;
* V_165 = NULL ;
F_14 ( & V_164 -> V_2 ) ;
goto V_18;
}
* V_165 = F_2 ( V_167 ) ;
V_17 = F_83 ( V_164 -> V_6 , & V_166 , 0 ) ;
F_14 ( & V_164 -> V_2 ) ;
if ( V_17 < 0 ) {
V_164 -> V_2 . V_73 = - V_17 ;
V_167 -> V_19 = V_23 ;
F_16 ( V_167 , V_25 ) ;
V_2 -> V_7 -> V_168 ( V_167 ) ;
F_22 ( V_167 ) ;
* V_165 = NULL ;
goto V_18;
}
if ( V_164 -> V_2 . V_19 == V_23 ) {
if ( V_166 )
F_17 ( V_166 ) ;
V_167 -> V_19 = V_23 ;
F_16 ( V_167 , V_25 ) ;
V_2 -> V_7 -> V_168 ( V_167 ) ;
F_22 ( V_167 ) ;
* V_165 = NULL ;
goto V_18;
}
( * V_165 ) -> V_6 = V_166 ;
V_18:
return V_17 ;
}
static void F_84 ( struct V_1 * V_169 , struct V_1 * V_2 )
{
struct V_4 * V_170 = F_2 ( V_169 ) ;
F_12 ( V_2 ) ;
F_85 ( & V_170 -> V_43 ) ;
F_86 ( & F_2 ( V_2 ) -> V_42 , & V_170 -> V_42 ) ;
F_87 ( & V_170 -> V_43 ) ;
F_88 ( V_169 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_170 = F_2 ( V_2 ) -> V_171 ;
F_85 ( & V_170 -> V_43 ) ;
F_90 ( & F_2 ( V_2 ) -> V_42 ) ;
F_87 ( & V_170 -> V_43 ) ;
F_91 ( & F_2 ( V_2 ) -> V_171 -> V_2 ) ;
F_22 ( V_2 ) ;
}
struct V_1 * F_92 ( struct V_1 * V_169 ,
struct V_16 * V_172 )
{
struct V_4 * V_173 , * V_174 ;
struct V_1 * V_167 ;
F_93 (isk, n, &smc_sk(parent)->accept_q, accept_q) {
V_167 = (struct V_1 * ) V_173 ;
F_89 ( V_167 ) ;
if ( V_167 -> V_19 == V_23 ) {
V_167 -> V_7 -> V_168 ( V_167 ) ;
F_22 ( V_167 ) ;
continue;
}
if ( V_172 )
F_94 ( V_167 , V_172 ) ;
return V_167 ;
}
return NULL ;
}
void F_95 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ! V_2 -> V_175 )
V_2 -> V_175 = V_176 ;
if ( V_5 -> V_22 ) {
V_2 -> V_19 = V_23 ;
} else {
F_15 ( V_5 ) ;
F_16 ( V_2 , V_25 ) ;
V_2 -> V_26 |= V_27 ;
}
if ( V_5 -> V_6 ) {
struct V_16 * V_177 ;
V_177 = V_5 -> V_6 ;
V_5 -> V_6 = NULL ;
F_17 ( V_177 ) ;
}
if ( V_5 -> V_22 ) {
F_19 ( & V_5 -> V_28 , V_29 ) ;
} else if ( V_2 -> V_19 == V_23 ) {
F_20 ( & V_5 -> V_30 ) ;
F_19 ( & V_5 -> V_28 ,
V_31 ) ;
}
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
}
static int F_96 ( struct V_4 * V_5 )
{
struct V_93 * V_94 = V_5 -> V_30 . V_94 ;
struct V_95 * V_96 ;
int V_97 ;
int V_17 ;
V_96 = & V_94 -> V_98 [ V_99 ] ;
V_17 = F_56 ( V_96 ,
V_5 -> V_30 . V_106 -> V_107 [ V_99 ] ) ;
if ( V_17 )
return V_105 ;
V_17 = F_57 ( V_96 ,
V_96 -> V_108 -> V_109 [ V_96 -> V_110 - 1 ] ,
& V_96 -> V_108 -> V_92 [ V_96 -> V_110 - 1 ] ,
V_178 ) ;
if ( V_17 < 0 )
return V_112 ;
V_97 = F_52 (
& V_96 -> V_179 ,
V_101 ) ;
if ( V_97 <= 0 ) {
struct V_102 V_103 ;
V_17 = F_53 ( V_5 , & V_103 , sizeof( V_103 ) ,
V_104 ) ;
}
return V_17 ;
}
static void F_97 ( struct V_180 * V_181 )
{
struct V_4 * V_165 = F_98 ( V_181 , struct V_4 ,
F_97 ) ;
struct V_16 * V_182 = V_165 -> V_6 ;
struct V_4 * V_164 = V_165 -> V_171 ;
struct V_113 V_183 ;
int V_135 = V_184 ;
struct V_1 * V_185 = & V_165 -> V_2 ;
struct V_186 V_187 ;
struct V_137 * V_108 ;
struct V_49 V_188 ;
struct V_95 * V_96 ;
int V_139 = 0 ;
int V_17 = 0 , V_84 ;
T_1 V_77 ;
T_2 V_78 ;
T_2 V_110 ;
V_139 = F_53 ( V_165 , & V_187 , sizeof( V_187 ) ,
V_189 ) ;
if ( V_139 < 0 )
goto V_143;
if ( V_139 > 0 )
goto V_141;
if ( F_65 ( V_165 ) ) {
V_139 = V_140 ;
goto V_141;
}
F_66 ( V_182 -> V_2 , & V_108 , & V_110 ) ;
if ( ! V_108 ) {
V_139 = V_142 ;
goto V_141;
}
V_17 = F_40 ( V_182 , & V_77 , & V_78 ) ;
if ( V_17 ) {
V_139 = V_142 ;
goto V_141;
}
if ( ( V_187 . V_190 != V_77 ) ||
( V_187 . V_78 != V_78 ) ) {
V_139 = V_142 ;
goto V_141;
}
F_99 ( V_182 , (struct V_46 * ) & V_188 , & V_84 ) ;
F_68 ( & V_147 ) ;
V_135 = F_69 ( V_165 , V_188 . V_56 . V_57 ,
V_108 , V_110 , & V_187 . V_126 , 0 ) ;
if ( V_135 < 0 ) {
V_17 = V_135 ;
if ( V_17 == - V_148 )
V_139 = V_149 ;
goto V_141;
}
V_96 = & V_165 -> V_30 . V_94 -> V_98 [ V_99 ] ;
V_17 = F_70 ( V_165 ) ;
if ( V_17 ) {
V_139 = V_149 ;
goto V_141;
}
F_72 ( V_165 ) ;
F_73 ( V_165 ) ;
if ( V_135 != V_136 ) {
struct V_153 * V_154 = V_165 -> V_30 . V_106 ;
if ( ! V_154 -> V_155 ) {
V_17 = F_56 ( V_96 ,
V_154 -> V_107 [ V_99 ] ) ;
if ( V_17 ) {
V_139 = V_105 ;
goto V_141;
}
}
}
F_75 ( & V_165 -> V_30 ) ;
V_17 = F_100 ( V_165 , V_135 ) ;
if ( V_17 )
goto V_143;
V_139 = F_53 ( V_165 , & V_183 , sizeof( V_183 ) ,
V_191 ) ;
if ( V_139 < 0 )
goto V_143;
if ( V_139 > 0 )
goto V_141;
F_58 ( V_165 , & V_183 ) ;
if ( V_135 == V_136 )
F_62 ( V_96 , & V_183 ) ;
V_17 = F_71 ( & V_165 -> V_30 , & V_183 ) ;
if ( V_17 ) {
V_139 = V_105 ;
goto V_141;
}
if ( V_135 == V_136 ) {
V_17 = F_74 ( V_96 ) ;
if ( V_17 ) {
V_139 = V_105 ;
goto V_141;
}
V_139 = F_96 ( V_165 ) ;
if ( V_139 < 0 ) {
V_17 = V_139 ;
goto V_143;
}
if ( V_139 > 0 )
goto V_141;
}
F_78 ( V_165 ) ;
V_157:
F_33 ( V_185 ) ;
if ( V_185 -> V_19 == V_36 )
V_185 -> V_19 = V_158 ;
V_192:
F_77 ( & V_147 ) ;
F_13 ( & V_164 -> V_2 , V_21 ) ;
if ( V_164 -> V_2 . V_19 == V_20 ) {
F_84 ( & V_164 -> V_2 , V_185 ) ;
} else {
F_95 ( V_185 ) ;
}
F_21 ( & V_164 -> V_2 ) ;
V_164 -> V_2 . V_193 ( & V_164 -> V_2 ) ;
F_22 ( & V_164 -> V_2 ) ;
return;
V_141:
F_20 ( & V_165 -> V_30 ) ;
V_165 -> V_22 = true ;
if ( V_139 && ( V_139 != V_159 ) ) {
V_17 = F_79 ( V_165 , V_139 ) ;
if ( V_17 < sizeof( struct V_102 ) )
goto V_143;
}
goto V_157;
V_143:
V_185 -> V_19 = V_23 ;
F_20 ( & V_165 -> V_30 ) ;
goto V_192;
}
static void V_41 ( struct V_180 * V_181 )
{
struct V_4 * V_164 = F_98 ( V_181 , struct V_4 ,
V_40 ) ;
struct V_4 * V_165 ;
int V_17 = 0 ;
F_14 ( & V_164 -> V_2 ) ;
while ( V_164 -> V_2 . V_19 == V_20 ) {
V_17 = F_82 ( V_164 , & V_165 ) ;
if ( V_17 )
goto V_18;
if ( ! V_165 )
continue;
V_165 -> V_171 = V_164 ;
V_165 -> V_22 = false ;
F_12 ( & V_164 -> V_2 ) ;
F_29 ( & V_165 -> F_97 , F_97 ) ;
F_39 ( V_165 ) ;
F_101 ( & V_165 -> F_97 ) ;
}
V_18:
F_21 ( & V_164 -> V_2 ) ;
V_164 -> V_2 . V_193 ( & V_164 -> V_2 ) ;
}
static int F_102 ( struct V_16 * V_1 , int V_194 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
V_17 = - V_51 ;
if ( ( V_2 -> V_19 != V_36 ) && ( V_2 -> V_19 != V_20 ) )
goto V_18;
V_17 = 0 ;
if ( V_2 -> V_19 == V_20 ) {
V_2 -> V_195 = V_194 ;
goto V_18;
}
F_38 ( V_5 ) ;
V_17 = F_103 ( V_5 -> V_6 , V_194 ) ;
if ( V_17 )
goto V_18;
V_2 -> V_195 = V_194 ;
V_2 -> V_196 = 0 ;
V_2 -> V_19 = V_20 ;
F_29 ( & V_5 -> V_40 , V_41 ) ;
F_101 ( & V_5 -> V_40 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_104 ( struct V_16 * V_1 , struct V_16 * V_172 ,
int V_161 , bool V_197 )
{
struct V_1 * V_2 = V_1 -> V_2 , * V_61 ;
F_105 ( V_198 , V_199 ) ;
struct V_4 * V_164 ;
long V_200 ;
int V_17 = 0 ;
V_164 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_164 -> V_2 . V_19 != V_20 ) {
V_17 = - V_51 ;
goto V_18;
}
V_200 = F_106 ( V_2 , V_161 & V_201 ) ;
F_107 ( F_108 ( V_2 ) , & V_198 ) ;
while ( ! ( V_61 = F_92 ( V_2 , V_172 ) ) ) {
F_109 ( V_202 ) ;
if ( ! V_200 ) {
V_17 = - V_203 ;
break;
}
F_21 ( V_2 ) ;
V_200 = F_110 ( V_200 ) ;
F_111 () ;
F_14 ( V_2 ) ;
if ( F_112 ( V_199 ) ) {
V_17 = F_113 ( V_200 ) ;
break;
}
}
F_109 ( V_204 ) ;
F_114 ( F_108 ( V_2 ) , & V_198 ) ;
if ( ! V_17 )
V_17 = F_115 ( V_61 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_116 ( struct V_16 * V_1 , struct V_46 * V_50 ,
int * V_84 , int V_205 )
{
struct V_4 * V_5 ;
if ( V_205 && ( V_1 -> V_2 -> V_19 != V_158 ) &&
( V_1 -> V_2 -> V_19 != V_206 ) )
return - V_85 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
return V_5 -> V_6 -> V_207 -> V_208 ( V_5 -> V_6 , V_50 , V_84 , V_205 ) ;
}
static int F_117 ( struct V_16 * V_1 , struct V_209 * V_210 , T_3 V_84 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_211 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 != V_158 ) &&
( V_2 -> V_19 != V_206 ) &&
( V_2 -> V_19 != V_36 ) )
goto V_18;
if ( V_5 -> V_22 )
V_17 = V_5 -> V_6 -> V_207 -> V_212 ( V_5 -> V_6 , V_210 , V_84 ) ;
else
V_17 = F_118 ( V_5 , V_210 , V_84 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_119 ( struct V_16 * V_1 , struct V_209 * V_210 , T_3 V_84 ,
int V_161 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_85 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 == V_36 ) ||
( V_2 -> V_19 == V_20 ) ||
( V_2 -> V_19 == V_23 ) )
goto V_18;
if ( V_2 -> V_19 == V_213 ) {
V_17 = 0 ;
goto V_18;
}
if ( V_5 -> V_22 )
V_17 = V_5 -> V_6 -> V_207 -> V_214 ( V_5 -> V_6 , V_210 , V_84 , V_161 ) ;
else
V_17 = F_120 ( V_5 , V_210 , V_84 , V_161 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static unsigned int F_121 ( struct V_1 * V_169 )
{
struct V_4 * V_173 ;
struct V_1 * V_2 ;
F_14 ( V_169 ) ;
F_122 (isk, &smc_sk(parent)->accept_q, accept_q) {
V_2 = (struct V_1 * ) V_173 ;
if ( V_2 -> V_19 == V_158 ) {
F_21 ( V_169 ) ;
return V_215 | V_216 ;
}
}
F_21 ( V_169 ) ;
return 0 ;
}
static unsigned int F_123 ( struct V_217 * V_217 , struct V_16 * V_1 ,
T_4 * V_198 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_63 = 0 ;
struct V_4 * V_5 ;
int V_17 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
if ( ( V_2 -> V_19 == V_36 ) || V_5 -> V_22 ) {
V_63 = V_5 -> V_6 -> V_207 -> V_218 ( V_217 , V_5 -> V_6 , V_198 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 == V_36 ) && ( V_63 & V_219 ) ) {
V_2 -> V_73 = V_5 -> V_6 -> V_2 -> V_73 ;
if ( V_2 -> V_73 ) {
V_63 |= V_220 ;
} else {
V_17 = F_64 ( V_5 ) ;
if ( V_17 < 0 )
V_63 |= V_220 ;
else
V_63 |= V_219 | V_221 ;
}
}
F_21 ( V_2 ) ;
} else {
F_124 ( V_217 , F_108 ( V_2 ) , V_198 ) ;
if ( V_2 -> V_19 == V_20 )
V_63 |= F_121 ( V_2 ) ;
if ( V_2 -> V_73 )
V_63 |= V_220 ;
if ( F_125 ( & V_5 -> V_30 . V_222 ) ||
( V_2 -> V_26 & V_223 ) ) {
V_63 |= V_219 | V_221 ;
} else {
F_126 ( V_224 , V_2 ) ;
F_127 ( V_225 , & V_2 -> V_226 -> V_161 ) ;
}
if ( F_125 ( & V_5 -> V_30 . V_227 ) )
V_63 |= V_215 | V_216 ;
if ( ( V_2 -> V_26 == V_27 ) ||
( V_2 -> V_19 == V_23 ) )
V_63 |= V_228 ;
if ( V_2 -> V_26 & V_229 )
V_63 |= V_215 | V_216 | V_230 ;
if ( V_2 -> V_19 == V_206 )
V_63 |= V_215 ;
}
return V_63 ;
}
static int F_128 ( struct V_16 * V_1 , int V_231 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_51 ;
int V_232 = 0 ;
V_5 = F_2 ( V_2 ) ;
if ( ( V_231 < V_233 ) || ( V_231 > V_234 ) )
return V_17 ;
F_14 ( V_2 ) ;
V_17 = - V_85 ;
if ( ( V_2 -> V_19 != V_20 ) &&
( V_2 -> V_19 != V_158 ) &&
( V_2 -> V_19 != V_235 ) &&
( V_2 -> V_19 != V_236 ) &&
( V_2 -> V_19 != V_206 ) &&
( V_2 -> V_19 != V_237 ) &&
( V_2 -> V_19 != V_238 ) )
goto V_18;
if ( V_5 -> V_22 ) {
V_17 = F_129 ( V_5 -> V_6 , V_231 ) ;
V_2 -> V_26 = V_5 -> V_6 -> V_2 -> V_26 ;
if ( V_2 -> V_26 == V_27 )
V_2 -> V_19 = V_23 ;
goto V_18;
}
switch ( V_231 ) {
case V_234 :
V_17 = F_15 ( V_5 ) ;
break;
case V_239 :
V_17 = F_130 ( V_5 ) ;
break;
case V_233 :
if ( V_2 -> V_19 == V_20 )
V_17 = F_15 ( V_5 ) ;
else
V_17 = 0 ;
break;
}
V_232 = F_129 ( V_5 -> V_6 , V_231 ) ;
V_2 -> V_26 |= V_231 + 1 ;
V_18:
F_21 ( V_2 ) ;
return V_17 ? V_17 : V_232 ;
}
static int F_131 ( struct V_16 * V_1 , int V_240 , int V_241 ,
char T_5 * V_242 , unsigned int V_243 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 -> V_207 -> V_244 ( V_5 -> V_6 , V_240 , V_241 ,
V_242 , V_243 ) ;
}
static int F_132 ( struct V_16 * V_1 , int V_240 , int V_241 ,
char T_5 * V_242 , int T_5 * V_243 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
return V_5 -> V_6 -> V_207 -> V_245 ( V_5 -> V_6 , V_240 , V_241 ,
V_242 , V_243 ) ;
}
static int F_133 ( struct V_16 * V_1 , unsigned int V_246 ,
unsigned long V_247 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
if ( V_5 -> V_22 )
return V_5 -> V_6 -> V_207 -> V_248 ( V_5 -> V_6 , V_246 , V_247 ) ;
else
return F_134 ( V_1 , V_246 , V_247 ) ;
}
static T_6 F_135 ( struct V_16 * V_1 , struct V_249 * V_249 ,
int V_250 , T_3 V_251 , int V_161 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_211 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_19 != V_158 )
goto V_18;
if ( V_5 -> V_22 )
V_17 = F_136 ( V_5 -> V_6 , V_249 , V_250 ,
V_251 , V_161 ) ;
else
V_17 = F_137 ( V_1 , V_249 , V_250 , V_251 , V_161 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static T_6 F_138 ( struct V_16 * V_1 , T_7 * V_252 ,
struct V_253 * V_254 , T_3 V_84 ,
unsigned int V_161 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_85 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 != V_158 ) && ( V_2 -> V_19 != V_23 ) )
goto V_18;
if ( V_5 -> V_22 ) {
V_17 = V_5 -> V_6 -> V_207 -> V_255 ( V_5 -> V_6 , V_252 ,
V_254 , V_84 , V_161 ) ;
} else {
V_17 = - V_256 ;
}
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_139 ( struct V_32 * V_32 , struct V_16 * V_1 , int V_257 ,
int V_197 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int V_17 ;
V_17 = - V_258 ;
if ( V_1 -> type != V_259 )
goto V_18;
V_17 = - V_260 ;
if ( ( V_257 != V_261 ) && ( V_257 != V_262 ) )
goto V_18;
V_17 = - V_263 ;
V_1 -> V_207 = & V_264 ;
V_2 = F_26 ( V_32 , V_1 ) ;
if ( ! V_2 )
goto V_18;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_22 = false ;
V_17 = F_140 ( V_32 , V_265 , V_259 ,
V_262 , & V_5 -> V_6 ) ;
if ( V_17 )
F_141 ( V_2 ) ;
V_5 -> V_2 . V_65 = F_142 ( V_5 -> V_6 -> V_2 -> V_65 , V_266 ) ;
V_5 -> V_2 . V_66 = F_142 ( V_5 -> V_6 -> V_2 -> V_66 , V_266 ) ;
V_18:
return V_17 ;
}
static int T_8 F_143 ( void )
{
int V_17 ;
V_17 = F_144 () ;
if ( V_17 )
return V_17 ;
V_17 = F_145 () ;
if ( V_17 ) {
F_146 ( L_1 , V_267 , V_17 ) ;
goto V_268;
}
V_17 = F_147 () ;
if ( V_17 ) {
F_146 ( L_2 , V_267 , V_17 ) ;
goto V_268;
}
V_17 = F_148 ( & V_35 , 1 ) ;
if ( V_17 ) {
F_146 ( L_3 , V_267 , V_17 ) ;
goto V_268;
}
V_17 = F_149 ( & V_269 ) ;
if ( V_17 ) {
F_146 ( L_4 , V_267 , V_17 ) ;
goto V_270;
}
F_150 ( & V_271 . V_14 ) ;
V_17 = F_151 () ;
if ( V_17 ) {
F_146 ( L_5 , V_267 , V_17 ) ;
goto V_272;
}
return 0 ;
V_272:
F_152 ( V_33 ) ;
V_270:
F_153 ( & V_35 ) ;
V_268:
F_154 () ;
return V_17 ;
}
static void T_9 F_155 ( void )
{
struct V_93 * V_94 , * V_273 ;
F_156 ( V_274 ) ;
F_157 ( & V_275 . V_15 ) ;
if ( ! F_158 ( & V_275 . V_276 ) )
F_159 ( & V_275 . V_276 , & V_274 ) ;
F_160 ( & V_275 . V_15 ) ;
F_93 (lgr, lg, &lgr_freeing_list, list) {
F_90 ( & V_94 -> V_276 ) ;
F_161 ( V_94 ) ;
}
F_162 () ;
F_152 ( V_33 ) ;
F_153 ( & V_35 ) ;
F_154 () ;
}
