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
V_2 -> V_7 -> V_32 ( V_2 ) ;
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
static struct V_1 * F_26 ( struct V_33 * V_33 , struct V_16 * V_1 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
V_2 = F_27 ( V_33 , V_34 , V_35 , & V_36 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_28 ( V_1 , V_2 ) ;
V_2 -> V_19 = V_37 ;
V_2 -> V_38 = F_23 ;
V_2 -> V_39 = V_40 ;
V_5 = F_2 ( V_2 ) ;
F_29 ( & V_5 -> V_41 , V_42 ) ;
F_30 ( & V_5 -> V_43 ) ;
F_31 ( & V_5 -> V_44 ) ;
F_32 ( & V_5 -> V_28 , V_45 ) ;
V_2 -> V_7 -> V_46 ( V_2 ) ;
F_33 ( V_2 ) ;
return V_2 ;
}
static int F_34 ( struct V_16 * V_1 , struct V_47 * V_48 ,
int V_49 )
{
struct V_50 * V_51 = (struct V_50 * ) V_48 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 ;
V_5 = F_2 ( V_2 ) ;
V_17 = - V_52 ;
if ( V_49 < sizeof( struct V_50 ) )
goto V_18;
V_17 = - V_53 ;
if ( ( V_51 -> V_54 != V_55 ) &&
( ( V_51 -> V_54 != V_56 ) ||
( V_51 -> V_57 . V_58 != F_35 ( V_59 ) ) ) )
goto V_18;
F_14 ( V_2 ) ;
V_17 = - V_52 ;
if ( V_2 -> V_19 != V_37 )
goto V_60;
V_5 -> V_6 -> V_2 -> V_61 = V_2 -> V_61 ;
V_17 = F_36 ( V_5 -> V_6 , V_48 , V_49 ) ;
V_60:
F_21 ( V_2 ) ;
V_18:
return V_17 ;
}
static void F_37 ( struct V_1 * V_62 , struct V_1 * V_63 ,
unsigned long V_64 )
{
V_62 -> V_65 = V_63 -> V_65 ;
V_62 -> V_66 = V_63 -> V_66 ;
V_62 -> V_67 = V_63 -> V_67 ;
V_62 -> V_68 = V_63 -> V_68 ;
V_62 -> V_69 = V_63 -> V_69 ;
V_62 -> V_70 = V_63 -> V_70 ;
V_62 -> V_71 = V_63 -> V_71 ;
V_62 -> V_72 = V_63 -> V_72 ;
V_62 -> V_73 = V_63 -> V_73 ;
V_62 -> V_74 = V_63 -> V_74 ;
V_62 -> V_75 &= ~ V_64 ;
V_62 -> V_75 |= V_63 -> V_75 & V_64 ;
}
static void F_38 ( struct V_4 * V_5 )
{
F_37 ( V_5 -> V_6 -> V_2 , & V_5 -> V_2 , V_76 ) ;
}
static void F_39 ( struct V_4 * V_5 )
{
F_37 ( & V_5 -> V_2 , V_5 -> V_6 -> V_2 , V_77 ) ;
}
int F_40 ( struct V_16 * V_6 ,
T_1 * V_78 , T_2 * V_79 )
{
struct V_80 * V_81 = F_41 ( V_6 -> V_2 ) ;
struct V_50 V_51 ;
int V_17 = - V_82 ;
int V_83 ;
if ( ! V_81 ) {
V_17 = - V_84 ;
goto V_18;
}
if ( ! V_81 -> V_85 ) {
V_17 = - V_86 ;
goto V_60;
}
F_42 ( V_6 , (struct V_47 * ) & V_51 , & V_83 ) ;
F_43 (dst->dev->ip_ptr) {
if ( V_87 -> V_88 != V_51 . V_57 . V_58 )
continue;
* V_79 = F_44 ( V_87 -> V_89 ) ;
* V_78 = V_87 -> V_88 & V_87 -> V_89 ;
V_17 = 0 ;
break;
} F_45 ( V_81 -> V_85 -> V_90 ) ;
V_60:
F_46 ( V_81 ) ;
V_18:
return V_17 ;
}
static int F_47 ( struct V_4 * V_5 , union V_91 * V_92 )
{
struct V_93 * V_94 = V_5 -> V_30 . V_94 ;
struct V_95 * V_96 ;
int V_97 ;
int V_17 ;
V_96 = & V_94 -> V_98 [ V_99 ] ;
V_97 = F_48 (
& V_96 -> V_100 ,
V_101 ) ;
if ( V_97 <= 0 ) {
struct V_102 V_103 ;
V_17 = F_49 ( V_5 , & V_103 , sizeof( V_103 ) ,
V_104 ) ;
return V_17 ;
}
V_17 = F_50 ( V_96 ) ;
if ( V_17 )
return V_105 ;
F_51 ( V_96 ) ;
V_17 = F_52 ( V_96 ,
V_96 -> V_106 -> V_107 [ V_96 -> V_108 - 1 ] ,
V_92 , V_109 ) ;
if ( V_17 < 0 )
return V_110 ;
return V_17 ;
}
static void F_53 ( struct V_4 * V_5 ,
struct V_111 * V_112 )
{
V_5 -> V_30 . V_113 = V_112 -> V_114 ;
V_5 -> V_30 . V_115 . V_116 = F_54 ( V_112 -> V_117 ) ;
V_5 -> V_30 . V_118 = F_55 ( V_112 -> V_119 ) ;
F_56 ( & V_5 -> V_30 . V_120 , V_5 -> V_30 . V_118 ) ;
}
static void F_57 ( struct V_95 * V_96 ,
struct V_111 * V_112 )
{
V_96 -> V_121 = F_58 ( V_112 -> V_122 ) ;
memcpy ( V_96 -> V_123 , V_112 -> V_124 . V_92 , V_125 ) ;
memcpy ( V_96 -> V_126 , V_112 -> V_124 . V_107 , sizeof( V_96 -> V_126 ) ) ;
V_96 -> V_127 = F_58 ( V_112 -> V_128 ) ;
V_96 -> V_129 = V_112 -> V_130 ;
}
static int F_59 ( struct V_4 * V_5 )
{
struct V_50 * V_131 = (struct V_50 * ) V_5 -> V_51 ;
struct V_111 V_132 ;
int V_133 = V_134 ;
struct V_135 * V_106 ;
struct V_95 * V_96 ;
T_2 V_136 ;
int V_137 = 0 ;
int V_17 = 0 ;
T_2 V_108 ;
if ( F_60 ( V_5 ) ) {
V_137 = V_138 ;
goto V_139;
}
F_61 ( V_5 -> V_6 -> V_2 , & V_106 , & V_108 ) ;
if ( ! V_106 ) {
V_137 = V_140 ;
goto V_139;
}
V_137 = F_62 ( V_5 , V_106 , V_108 ) ;
if ( V_137 < 0 ) {
V_17 = V_137 ;
goto V_141;
}
if ( V_137 > 0 )
goto V_139;
V_137 = F_49 ( V_5 , & V_132 , sizeof( V_132 ) ,
V_142 ) ;
if ( V_137 < 0 ) {
V_17 = V_137 ;
goto V_141;
}
if ( V_137 > 0 )
goto V_139;
V_136 = V_132 . V_143 . V_144 ;
F_63 ( & V_145 ) ;
V_133 = F_64 ( V_5 , V_131 -> V_57 . V_58 , V_106 ,
V_108 , & V_132 . V_124 , V_136 ) ;
if ( V_133 < 0 ) {
V_17 = V_133 ;
if ( V_17 == - V_146 )
V_137 = V_147 ;
else if ( V_17 == - V_148 )
V_137 = V_149 ;
goto V_150;
}
V_96 = & V_5 -> V_30 . V_94 -> V_98 [ V_99 ] ;
F_53 ( V_5 , & V_132 ) ;
V_17 = F_65 ( V_5 ) ;
if ( V_17 ) {
V_137 = V_147 ;
goto V_150;
}
V_17 = F_66 ( V_5 ) ;
if ( V_17 ) {
V_137 = V_147 ;
goto V_150;
}
if ( V_133 == V_134 )
F_57 ( V_96 , & V_132 ) ;
V_17 = F_67 ( & V_5 -> V_30 , & V_132 ) ;
if ( V_17 ) {
V_137 = V_105 ;
goto V_150;
}
if ( V_133 == V_134 ) {
V_17 = F_68 ( V_96 ) ;
if ( V_17 ) {
V_137 = V_105 ;
goto V_150;
}
}
V_17 = F_69 ( V_5 ) ;
if ( V_17 )
goto V_151;
if ( V_133 == V_134 ) {
V_137 = F_47 (
V_5 , & V_106 -> V_92 [ V_108 - 1 ] ) ;
if ( V_137 < 0 ) {
V_17 = V_137 ;
goto V_151;
}
if ( V_137 > 0 )
goto V_150;
}
F_70 ( & V_145 ) ;
F_71 ( V_5 ) ;
F_72 ( V_5 ) ;
V_152:
F_38 ( V_5 ) ;
if ( V_5 -> V_2 . V_19 == V_37 )
V_5 -> V_2 . V_19 = V_153 ;
return V_17 ? V_17 : V_133 ;
V_150:
F_70 ( & V_145 ) ;
F_20 ( & V_5 -> V_30 ) ;
V_139:
V_5 -> V_22 = true ;
if ( V_137 && ( V_137 != V_154 ) ) {
V_17 = F_73 ( V_5 , V_137 , 0 ) ;
if ( V_17 < sizeof( struct V_102 ) )
goto V_141;
}
goto V_152;
V_151:
F_70 ( & V_145 ) ;
F_20 ( & V_5 -> V_30 ) ;
V_141:
return V_17 ;
}
static int F_74 ( struct V_16 * V_1 , struct V_47 * V_51 ,
int V_155 , int V_156 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_52 ;
V_5 = F_2 ( V_2 ) ;
if ( V_155 < sizeof( V_51 -> V_157 ) )
goto V_141;
if ( V_51 -> V_157 != V_55 )
goto V_141;
V_5 -> V_51 = V_51 ;
F_14 ( V_2 ) ;
switch ( V_2 -> V_19 ) {
default:
goto V_18;
case V_153 :
V_17 = - V_158 ;
goto V_18;
case V_37 :
V_17 = 0 ;
break;
}
F_38 ( V_5 ) ;
V_17 = F_75 ( V_5 -> V_6 , V_51 , V_155 , V_156 ) ;
if ( V_17 )
goto V_18;
V_17 = F_59 ( V_5 ) ;
if ( V_17 < 0 )
goto V_18;
else
V_17 = 0 ;
V_18:
F_21 ( V_2 ) ;
V_141:
return V_17 ;
}
static int F_76 ( struct V_4 * V_159 , struct V_4 * * V_160 )
{
struct V_1 * V_2 = & V_159 -> V_2 ;
struct V_16 * V_161 ;
struct V_1 * V_162 ;
int V_17 ;
F_21 ( & V_159 -> V_2 ) ;
V_162 = F_26 ( F_7 ( V_2 ) , NULL ) ;
if ( ! V_162 ) {
V_17 = - V_146 ;
V_159 -> V_2 . V_74 = V_146 ;
* V_160 = NULL ;
F_14 ( & V_159 -> V_2 ) ;
goto V_18;
}
* V_160 = F_2 ( V_162 ) ;
V_17 = F_77 ( V_159 -> V_6 , & V_161 , 0 ) ;
F_14 ( & V_159 -> V_2 ) ;
if ( V_17 < 0 ) {
V_159 -> V_2 . V_74 = - V_17 ;
V_162 -> V_19 = V_23 ;
F_16 ( V_162 , V_25 ) ;
V_2 -> V_7 -> V_32 ( V_162 ) ;
F_22 ( V_162 ) ;
* V_160 = NULL ;
goto V_18;
}
if ( V_159 -> V_2 . V_19 == V_23 ) {
if ( V_161 )
F_17 ( V_161 ) ;
V_162 -> V_19 = V_23 ;
F_16 ( V_162 , V_25 ) ;
V_2 -> V_7 -> V_32 ( V_162 ) ;
F_22 ( V_162 ) ;
* V_160 = NULL ;
goto V_18;
}
( * V_160 ) -> V_6 = V_161 ;
V_18:
return V_17 ;
}
static void F_78 ( struct V_1 * V_163 , struct V_1 * V_2 )
{
struct V_4 * V_164 = F_2 ( V_163 ) ;
F_12 ( V_2 ) ;
F_79 ( & V_164 -> V_44 ) ;
F_80 ( & F_2 ( V_2 ) -> V_43 , & V_164 -> V_43 ) ;
F_81 ( & V_164 -> V_44 ) ;
F_82 ( V_163 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_4 * V_164 = F_2 ( V_2 ) -> V_165 ;
F_79 ( & V_164 -> V_44 ) ;
F_84 ( & F_2 ( V_2 ) -> V_43 ) ;
F_81 ( & V_164 -> V_44 ) ;
F_85 ( & F_2 ( V_2 ) -> V_165 -> V_2 ) ;
F_22 ( V_2 ) ;
}
struct V_1 * F_86 ( struct V_1 * V_163 ,
struct V_16 * V_166 )
{
struct V_4 * V_167 , * V_168 ;
struct V_1 * V_162 ;
F_87 (isk, n, &smc_sk(parent)->accept_q, accept_q) {
V_162 = (struct V_1 * ) V_167 ;
F_83 ( V_162 ) ;
if ( V_162 -> V_19 == V_23 ) {
continue;
}
if ( V_166 )
F_88 ( V_162 , V_166 ) ;
return V_162 ;
}
return NULL ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ! V_2 -> V_169 )
V_2 -> V_169 = V_170 ;
if ( ! V_5 -> V_22 )
F_15 ( V_5 ) ;
if ( V_5 -> V_6 ) {
struct V_16 * V_171 ;
V_171 = V_5 -> V_6 ;
V_5 -> V_6 = NULL ;
F_17 ( V_171 ) ;
}
F_16 ( V_2 , V_25 ) ;
V_2 -> V_26 |= V_27 ;
if ( V_5 -> V_22 ) {
F_19 ( & V_5 -> V_28 , V_29 ) ;
} else {
F_20 ( & V_5 -> V_30 ) ;
F_19 ( & V_5 -> V_28 ,
V_31 ) ;
}
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
}
static int F_90 ( struct V_4 * V_5 )
{
struct V_93 * V_94 = V_5 -> V_30 . V_94 ;
struct V_95 * V_96 ;
int V_97 ;
int V_17 ;
V_96 = & V_94 -> V_98 [ V_99 ] ;
V_17 = F_52 ( V_96 ,
V_96 -> V_106 -> V_107 [ V_96 -> V_108 - 1 ] ,
& V_96 -> V_106 -> V_92 [ V_96 -> V_108 - 1 ] ,
V_172 ) ;
if ( V_17 < 0 )
return V_110 ;
V_97 = F_48 (
& V_96 -> V_173 ,
V_101 ) ;
if ( V_97 <= 0 ) {
struct V_102 V_103 ;
V_17 = F_49 ( V_5 , & V_103 , sizeof( V_103 ) ,
V_104 ) ;
}
return V_17 ;
}
static void F_91 ( struct V_174 * V_175 )
{
struct V_4 * V_160 = F_92 ( V_175 , struct V_4 ,
F_91 ) ;
struct V_16 * V_176 = V_160 -> V_6 ;
struct V_4 * V_159 = V_160 -> V_165 ;
struct V_111 V_177 ;
int V_133 = V_178 ;
struct V_1 * V_179 = & V_160 -> V_2 ;
struct V_180 V_181 ;
struct V_135 * V_106 ;
struct V_50 V_182 ;
struct V_95 * V_96 ;
int V_137 = 0 ;
int V_17 = 0 , V_83 ;
T_1 V_78 ;
T_2 V_79 ;
T_2 V_108 ;
V_137 = F_49 ( V_160 , & V_181 , sizeof( V_181 ) ,
V_183 ) ;
if ( V_137 < 0 )
goto V_141;
if ( V_137 > 0 )
goto V_139;
if ( F_60 ( V_160 ) ) {
V_137 = V_138 ;
goto V_139;
}
F_61 ( V_176 -> V_2 , & V_106 , & V_108 ) ;
if ( ! V_106 ) {
V_137 = V_140 ;
goto V_139;
}
V_17 = F_40 ( V_176 , & V_78 , & V_79 ) ;
if ( V_17 ) {
V_137 = V_140 ;
goto V_139;
}
if ( ( V_181 . V_184 != V_78 ) ||
( V_181 . V_79 != V_79 ) ) {
V_137 = V_140 ;
goto V_139;
}
F_93 ( V_176 , (struct V_47 * ) & V_182 , & V_83 ) ;
F_63 ( & V_145 ) ;
V_133 = F_64 ( V_160 , V_182 . V_57 . V_58 ,
V_106 , V_108 , & V_181 . V_124 , 0 ) ;
if ( V_133 == V_178 )
F_70 ( & V_145 ) ;
if ( V_133 < 0 ) {
V_17 = V_133 ;
if ( V_17 == - V_146 )
V_137 = V_147 ;
else if ( V_17 == - V_148 )
V_137 = V_149 ;
goto V_139;
}
V_96 = & V_160 -> V_30 . V_94 -> V_98 [ V_99 ] ;
V_17 = F_65 ( V_160 ) ;
if ( V_17 ) {
V_137 = V_147 ;
goto V_139;
}
V_17 = F_66 ( V_160 ) ;
if ( V_17 ) {
V_137 = V_147 ;
goto V_139;
}
V_17 = F_94 ( V_160 , V_133 ) ;
if ( V_17 )
goto V_141;
V_137 = F_49 ( V_160 , & V_177 , sizeof( V_177 ) ,
V_185 ) ;
if ( V_137 < 0 )
goto V_141;
if ( V_137 > 0 )
goto V_139;
F_53 ( V_160 , & V_177 ) ;
if ( V_133 == V_134 )
F_57 ( V_96 , & V_177 ) ;
V_17 = F_67 ( & V_160 -> V_30 , & V_177 ) ;
if ( V_17 ) {
V_137 = V_105 ;
goto V_139;
}
if ( V_133 == V_134 ) {
V_17 = F_68 ( V_96 ) ;
if ( V_17 ) {
V_137 = V_105 ;
goto V_139;
}
V_137 = F_90 ( V_160 ) ;
if ( V_137 < 0 ) {
V_17 = V_137 ;
goto V_141;
}
if ( V_137 > 0 )
goto V_139;
}
F_71 ( V_160 ) ;
F_72 ( V_160 ) ;
V_152:
F_33 ( V_179 ) ;
if ( V_179 -> V_19 == V_37 )
V_179 -> V_19 = V_153 ;
V_186:
if ( V_133 == V_134 )
F_70 ( & V_145 ) ;
F_13 ( & V_159 -> V_2 , V_21 ) ;
if ( V_159 -> V_2 . V_19 == V_20 ) {
F_78 ( & V_159 -> V_2 , V_179 ) ;
} else {
F_89 ( V_179 ) ;
}
F_21 ( & V_159 -> V_2 ) ;
V_159 -> V_2 . V_187 ( & V_159 -> V_2 ) ;
F_22 ( & V_159 -> V_2 ) ;
return;
V_139:
F_20 ( & V_160 -> V_30 ) ;
V_160 -> V_22 = true ;
if ( V_137 && ( V_137 != V_154 ) ) {
V_17 = F_73 ( V_160 , V_137 , 0 ) ;
if ( V_17 < sizeof( struct V_102 ) )
goto V_141;
}
goto V_152;
V_141:
V_179 -> V_19 = V_23 ;
F_20 ( & V_160 -> V_30 ) ;
goto V_186;
}
static void V_42 ( struct V_174 * V_175 )
{
struct V_4 * V_159 = F_92 ( V_175 , struct V_4 ,
V_41 ) ;
struct V_4 * V_160 ;
int V_17 = 0 ;
F_14 ( & V_159 -> V_2 ) ;
while ( V_159 -> V_2 . V_19 == V_20 ) {
V_17 = F_76 ( V_159 , & V_160 ) ;
if ( V_17 )
goto V_18;
if ( ! V_160 )
continue;
V_160 -> V_165 = V_159 ;
V_160 -> V_22 = false ;
F_12 ( & V_159 -> V_2 ) ;
F_29 ( & V_160 -> F_91 , F_91 ) ;
F_39 ( V_160 ) ;
F_95 ( & V_160 -> F_91 ) ;
}
V_18:
F_21 ( & V_159 -> V_2 ) ;
V_159 -> V_2 . V_187 ( & V_159 -> V_2 ) ;
}
static int F_96 ( struct V_16 * V_1 , int V_188 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
V_17 = - V_52 ;
if ( ( V_2 -> V_19 != V_37 ) && ( V_2 -> V_19 != V_20 ) )
goto V_18;
V_17 = 0 ;
if ( V_2 -> V_19 == V_20 ) {
V_2 -> V_189 = V_188 ;
goto V_18;
}
F_38 ( V_5 ) ;
V_17 = F_97 ( V_5 -> V_6 , V_188 ) ;
if ( V_17 )
goto V_18;
V_2 -> V_189 = V_188 ;
V_2 -> V_190 = 0 ;
V_2 -> V_19 = V_20 ;
F_29 ( & V_5 -> V_41 , V_42 ) ;
F_95 ( & V_5 -> V_41 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_98 ( struct V_16 * V_1 , struct V_16 * V_166 ,
int V_156 , bool V_191 )
{
struct V_1 * V_2 = V_1 -> V_2 , * V_62 ;
F_99 ( V_192 , V_193 ) ;
struct V_4 * V_159 ;
long V_194 ;
int V_17 = 0 ;
V_159 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_159 -> V_2 . V_19 != V_20 ) {
V_17 = - V_52 ;
goto V_18;
}
V_194 = F_100 ( V_2 , V_156 & V_195 ) ;
F_101 ( F_102 ( V_2 ) , & V_192 ) ;
while ( ! ( V_62 = F_86 ( V_2 , V_166 ) ) ) {
F_103 ( V_196 ) ;
if ( ! V_194 ) {
V_17 = - V_197 ;
break;
}
F_21 ( V_2 ) ;
V_194 = F_104 ( V_194 ) ;
F_105 () ;
F_14 ( V_2 ) ;
if ( F_106 ( V_193 ) ) {
V_17 = F_107 ( V_194 ) ;
break;
}
}
F_103 ( V_198 ) ;
F_108 ( F_102 ( V_2 ) , & V_192 ) ;
if ( ! V_17 )
V_17 = F_109 ( V_62 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_110 ( struct V_16 * V_1 , struct V_47 * V_51 ,
int * V_83 , int V_199 )
{
struct V_4 * V_5 ;
if ( V_199 && ( V_1 -> V_2 -> V_19 != V_153 ) &&
( V_1 -> V_2 -> V_19 != V_200 ) )
return - V_84 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
return V_5 -> V_6 -> V_201 -> V_202 ( V_5 -> V_6 , V_51 , V_83 , V_199 ) ;
}
static int F_111 ( struct V_16 * V_1 , struct V_203 * V_204 , T_3 V_83 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_205 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 != V_153 ) &&
( V_2 -> V_19 != V_200 ) &&
( V_2 -> V_19 != V_37 ) )
goto V_18;
if ( V_5 -> V_22 )
V_17 = V_5 -> V_6 -> V_201 -> V_206 ( V_5 -> V_6 , V_204 , V_83 ) ;
else
V_17 = F_112 ( V_5 , V_204 , V_83 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_113 ( struct V_16 * V_1 , struct V_203 * V_204 , T_3 V_83 ,
int V_156 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_84 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 == V_37 ) ||
( V_2 -> V_19 == V_20 ) ||
( V_2 -> V_19 == V_23 ) )
goto V_18;
if ( V_2 -> V_19 == V_207 ) {
V_17 = 0 ;
goto V_18;
}
if ( V_5 -> V_22 )
V_17 = V_5 -> V_6 -> V_201 -> V_208 ( V_5 -> V_6 , V_204 , V_83 , V_156 ) ;
else
V_17 = F_114 ( V_5 , V_204 , V_83 , V_156 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static unsigned int F_115 ( struct V_1 * V_163 )
{
struct V_4 * V_167 ;
struct V_1 * V_2 ;
F_14 ( V_163 ) ;
F_116 (isk, &smc_sk(parent)->accept_q, accept_q) {
V_2 = (struct V_1 * ) V_167 ;
if ( V_2 -> V_19 == V_153 ) {
F_21 ( V_163 ) ;
return V_209 | V_210 ;
}
}
F_21 ( V_163 ) ;
return 0 ;
}
static unsigned int F_117 ( struct V_211 * V_211 , struct V_16 * V_1 ,
T_4 * V_192 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_64 = 0 ;
struct V_4 * V_5 ;
int V_17 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
if ( ( V_2 -> V_19 == V_37 ) || V_5 -> V_22 ) {
V_64 = V_5 -> V_6 -> V_201 -> V_212 ( V_211 , V_5 -> V_6 , V_192 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 == V_37 ) && ( V_64 & V_213 ) ) {
V_2 -> V_74 = V_5 -> V_6 -> V_2 -> V_74 ;
if ( V_2 -> V_74 ) {
V_64 |= V_214 ;
} else {
V_17 = F_59 ( V_5 ) ;
if ( V_17 < 0 )
V_64 |= V_214 ;
else
V_64 |= V_213 | V_215 ;
}
}
F_21 ( V_2 ) ;
} else {
F_118 ( V_211 , F_102 ( V_2 ) , V_192 ) ;
if ( V_2 -> V_19 == V_20 )
V_64 |= F_115 ( V_2 ) ;
if ( V_2 -> V_74 )
V_64 |= V_214 ;
if ( F_119 ( & V_5 -> V_30 . V_216 ) ||
( V_2 -> V_26 & V_217 ) ) {
V_64 |= V_213 | V_215 ;
} else {
F_120 ( V_218 , V_2 ) ;
F_121 ( V_219 , & V_2 -> V_220 -> V_156 ) ;
}
if ( F_119 ( & V_5 -> V_30 . V_221 ) )
V_64 |= V_209 | V_210 ;
if ( ( V_2 -> V_26 == V_27 ) ||
( V_2 -> V_19 == V_23 ) )
V_64 |= V_222 ;
if ( V_2 -> V_26 & V_223 )
V_64 |= V_209 | V_210 | V_224 ;
if ( V_2 -> V_19 == V_200 )
V_64 |= V_209 ;
}
return V_64 ;
}
static int F_122 ( struct V_16 * V_1 , int V_225 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_52 ;
int V_226 = 0 ;
V_5 = F_2 ( V_2 ) ;
if ( ( V_225 < V_227 ) || ( V_225 > V_228 ) )
return V_17 ;
F_14 ( V_2 ) ;
V_17 = - V_84 ;
if ( ( V_2 -> V_19 != V_20 ) &&
( V_2 -> V_19 != V_153 ) &&
( V_2 -> V_19 != V_229 ) &&
( V_2 -> V_19 != V_230 ) &&
( V_2 -> V_19 != V_200 ) &&
( V_2 -> V_19 != V_231 ) &&
( V_2 -> V_19 != V_232 ) )
goto V_18;
if ( V_5 -> V_22 ) {
V_17 = F_123 ( V_5 -> V_6 , V_225 ) ;
V_2 -> V_26 = V_5 -> V_6 -> V_2 -> V_26 ;
if ( V_2 -> V_26 == V_27 )
V_2 -> V_19 = V_23 ;
goto V_18;
}
switch ( V_225 ) {
case V_228 :
V_17 = F_15 ( V_5 ) ;
break;
case V_233 :
V_17 = F_124 ( V_5 ) ;
break;
case V_227 :
if ( V_2 -> V_19 == V_20 )
V_17 = F_15 ( V_5 ) ;
else
V_17 = 0 ;
break;
}
V_226 = F_123 ( V_5 -> V_6 , V_225 ) ;
V_2 -> V_26 |= V_225 + 1 ;
V_18:
F_21 ( V_2 ) ;
return V_17 ? V_17 : V_226 ;
}
static int F_125 ( struct V_16 * V_1 , int V_234 , int V_235 ,
char T_5 * V_236 , unsigned int V_237 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 -> V_201 -> V_238 ( V_5 -> V_6 , V_234 , V_235 ,
V_236 , V_237 ) ;
}
static int F_126 ( struct V_16 * V_1 , int V_234 , int V_235 ,
char T_5 * V_236 , int T_5 * V_237 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
return V_5 -> V_6 -> V_201 -> V_239 ( V_5 -> V_6 , V_234 , V_235 ,
V_236 , V_237 ) ;
}
static int F_127 ( struct V_16 * V_1 , unsigned int V_240 ,
unsigned long V_241 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
if ( V_5 -> V_22 )
return V_5 -> V_6 -> V_201 -> V_242 ( V_5 -> V_6 , V_240 , V_241 ) ;
else
return F_128 ( V_1 , V_240 , V_241 ) ;
}
static T_6 F_129 ( struct V_16 * V_1 , struct V_243 * V_243 ,
int V_244 , T_3 V_245 , int V_156 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_205 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_19 != V_153 )
goto V_18;
if ( V_5 -> V_22 )
V_17 = F_130 ( V_5 -> V_6 , V_243 , V_244 ,
V_245 , V_156 ) ;
else
V_17 = F_131 ( V_1 , V_243 , V_244 , V_245 , V_156 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static T_6 F_132 ( struct V_16 * V_1 , T_7 * V_246 ,
struct V_247 * V_248 , T_3 V_83 ,
unsigned int V_156 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_84 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 != V_153 ) && ( V_2 -> V_19 != V_23 ) )
goto V_18;
if ( V_5 -> V_22 ) {
V_17 = V_5 -> V_6 -> V_201 -> V_249 ( V_5 -> V_6 , V_246 ,
V_248 , V_83 , V_156 ) ;
} else {
V_17 = - V_250 ;
}
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_133 ( struct V_33 * V_33 , struct V_16 * V_1 , int V_251 ,
int V_191 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int V_17 ;
V_17 = - V_252 ;
if ( V_1 -> type != V_253 )
goto V_18;
V_17 = - V_254 ;
if ( ( V_251 != V_255 ) && ( V_251 != V_256 ) )
goto V_18;
V_17 = - V_257 ;
V_1 -> V_201 = & V_258 ;
V_2 = F_26 ( V_33 , V_1 ) ;
if ( ! V_2 )
goto V_18;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_22 = false ;
V_17 = F_134 ( V_33 , V_259 , V_253 ,
V_256 , & V_5 -> V_6 ) ;
if ( V_17 )
F_135 ( V_2 ) ;
V_5 -> V_2 . V_66 = F_136 ( V_5 -> V_6 -> V_2 -> V_66 , V_260 ) ;
V_5 -> V_2 . V_67 = F_136 ( V_5 -> V_6 -> V_2 -> V_67 , V_260 ) ;
V_18:
return V_17 ;
}
static int T_8 F_137 ( void )
{
int V_17 ;
V_17 = F_138 () ;
if ( V_17 )
return V_17 ;
V_17 = F_139 () ;
if ( V_17 ) {
F_140 ( L_1 , V_261 , V_17 ) ;
goto V_262;
}
V_17 = F_141 () ;
if ( V_17 ) {
F_140 ( L_2 , V_261 , V_17 ) ;
goto V_262;
}
V_17 = F_142 ( & V_36 , 1 ) ;
if ( V_17 ) {
F_140 ( L_3 , V_261 , V_17 ) ;
goto V_262;
}
V_17 = F_143 ( & V_263 ) ;
if ( V_17 ) {
F_140 ( L_4 , V_261 , V_17 ) ;
goto V_264;
}
F_144 ( & V_265 . V_14 ) ;
V_17 = F_145 () ;
if ( V_17 ) {
F_140 ( L_5 , V_261 , V_17 ) ;
goto V_266;
}
return 0 ;
V_266:
F_146 ( V_34 ) ;
V_264:
F_147 ( & V_36 ) ;
V_262:
F_148 () ;
return V_17 ;
}
static void T_9 F_149 ( void )
{
struct V_93 * V_94 , * V_267 ;
F_150 ( V_268 ) ;
F_151 ( & V_269 . V_15 ) ;
if ( ! F_152 ( & V_269 . V_270 ) )
F_153 ( & V_269 . V_270 , & V_268 ) ;
F_154 ( & V_269 . V_15 ) ;
F_87 (lgr, lg, &lgr_freeing_list, list) {
F_84 ( & V_94 -> V_270 ) ;
F_155 ( V_94 ) ;
}
F_156 () ;
F_146 ( V_34 ) ;
F_147 ( & V_36 ) ;
F_148 () ;
}
