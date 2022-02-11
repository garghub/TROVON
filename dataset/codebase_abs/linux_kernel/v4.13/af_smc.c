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
struct V_49 V_50 ;
int V_17 = - V_81 ;
int V_82 ;
if ( ! V_80 ) {
V_17 = - V_83 ;
goto V_18;
}
if ( ! V_80 -> V_84 ) {
V_17 = - V_85 ;
goto V_59;
}
F_42 ( V_6 , (struct V_46 * ) & V_50 , & V_82 ) ;
F_43 (dst->dev->ip_ptr) {
if ( V_86 -> V_87 != V_50 . V_56 . V_57 )
continue;
* V_78 = F_44 ( V_86 -> V_88 ) ;
* V_77 = V_86 -> V_87 & V_86 -> V_88 ;
V_17 = 0 ;
break;
} F_45 ( V_80 -> V_84 -> V_89 ) ;
V_59:
F_46 ( V_80 ) ;
V_18:
return V_17 ;
}
static int F_47 ( struct V_4 * V_5 , union V_90 * V_91 )
{
struct V_92 * V_93 = V_5 -> V_30 . V_93 ;
struct V_94 * V_95 ;
int V_96 ;
int V_17 ;
V_95 = & V_93 -> V_97 [ V_98 ] ;
V_96 = F_48 (
& V_95 -> V_99 ,
V_100 ) ;
if ( V_96 <= 0 ) {
struct V_101 V_102 ;
V_17 = F_49 ( V_5 , & V_102 , sizeof( V_102 ) ,
V_103 ) ;
return V_17 ;
}
V_17 = F_50 ( V_95 ) ;
if ( V_17 )
return V_104 ;
F_51 ( V_95 ) ;
V_17 = F_52 ( V_95 ,
V_95 -> V_105 -> V_106 [ V_95 -> V_107 - 1 ] ,
V_91 , V_108 ) ;
if ( V_17 < 0 )
return V_109 ;
return V_17 ;
}
static void F_53 ( struct V_4 * V_5 ,
struct V_110 * V_111 )
{
V_5 -> V_30 . V_112 = V_111 -> V_113 ;
V_5 -> V_30 . V_114 . V_115 = F_54 ( V_111 -> V_116 ) ;
V_5 -> V_30 . V_117 = F_55 ( V_111 -> V_118 ) ;
F_56 ( & V_5 -> V_30 . V_119 , V_5 -> V_30 . V_117 ) ;
}
static void F_57 ( struct V_94 * V_95 ,
struct V_110 * V_111 )
{
V_95 -> V_120 = F_58 ( V_111 -> V_121 ) ;
memcpy ( V_95 -> V_122 , V_111 -> V_123 . V_91 , V_124 ) ;
memcpy ( V_95 -> V_125 , V_111 -> V_123 . V_106 , sizeof( V_95 -> V_125 ) ) ;
V_95 -> V_126 = F_58 ( V_111 -> V_127 ) ;
V_95 -> V_128 = V_111 -> V_129 ;
}
static int F_59 ( struct V_4 * V_5 )
{
struct V_49 * V_130 = (struct V_49 * ) V_5 -> V_50 ;
struct V_110 V_131 ;
int V_132 = V_133 ;
struct V_134 * V_105 ;
struct V_94 * V_95 ;
T_2 V_135 ;
int V_136 = 0 ;
int V_17 = 0 ;
T_2 V_107 ;
if ( F_60 ( V_5 ) ) {
V_136 = V_137 ;
goto V_138;
}
F_61 ( V_5 -> V_6 -> V_2 , & V_105 , & V_107 ) ;
if ( ! V_105 ) {
V_136 = V_139 ;
goto V_138;
}
V_136 = F_62 ( V_5 , V_105 , V_107 ) ;
if ( V_136 < 0 ) {
V_17 = V_136 ;
goto V_140;
}
if ( V_136 > 0 )
goto V_138;
V_136 = F_49 ( V_5 , & V_131 , sizeof( V_131 ) ,
V_141 ) ;
if ( V_136 < 0 ) {
V_17 = V_136 ;
goto V_140;
}
if ( V_136 > 0 )
goto V_138;
V_135 = V_131 . V_142 . V_143 ;
F_63 ( & V_144 ) ;
V_132 = F_64 ( V_5 , V_130 -> V_56 . V_57 , V_105 ,
V_107 , & V_131 . V_123 , V_135 ) ;
if ( V_132 < 0 ) {
V_17 = V_132 ;
if ( V_17 == - V_145 )
V_136 = V_146 ;
else if ( V_17 == - V_147 )
V_136 = V_148 ;
goto V_149;
}
V_95 = & V_5 -> V_30 . V_93 -> V_97 [ V_98 ] ;
F_53 ( V_5 , & V_131 ) ;
V_17 = F_65 ( V_5 ) ;
if ( V_17 ) {
V_136 = V_146 ;
goto V_149;
}
V_17 = F_66 ( V_5 ) ;
if ( V_17 ) {
V_136 = V_146 ;
goto V_149;
}
if ( V_132 == V_133 )
F_57 ( V_95 , & V_131 ) ;
V_17 = F_67 ( & V_5 -> V_30 , & V_131 ) ;
if ( V_17 ) {
V_136 = V_104 ;
goto V_149;
}
F_68 ( V_5 ) ;
F_69 ( V_5 ) ;
if ( V_132 == V_133 ) {
V_17 = F_70 ( V_95 ) ;
if ( V_17 ) {
V_136 = V_104 ;
goto V_149;
}
}
V_17 = F_71 ( V_5 ) ;
if ( V_17 )
goto V_150;
if ( V_132 == V_133 ) {
V_136 = F_47 (
V_5 , & V_105 -> V_91 [ V_107 - 1 ] ) ;
if ( V_136 < 0 ) {
V_17 = V_136 ;
goto V_150;
}
if ( V_136 > 0 )
goto V_149;
}
F_72 ( & V_144 ) ;
F_73 ( V_5 ) ;
V_151:
F_38 ( V_5 ) ;
if ( V_5 -> V_2 . V_19 == V_36 )
V_5 -> V_2 . V_19 = V_152 ;
return V_17 ? V_17 : V_132 ;
V_149:
F_72 ( & V_144 ) ;
F_20 ( & V_5 -> V_30 ) ;
V_138:
V_5 -> V_22 = true ;
if ( V_136 && ( V_136 != V_153 ) ) {
V_17 = F_74 ( V_5 , V_136 , 0 ) ;
if ( V_17 < sizeof( struct V_101 ) )
goto V_140;
}
goto V_151;
V_150:
F_72 ( & V_144 ) ;
F_20 ( & V_5 -> V_30 ) ;
V_140:
return V_17 ;
}
static int F_75 ( struct V_16 * V_1 , struct V_46 * V_50 ,
int V_154 , int V_155 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_51 ;
V_5 = F_2 ( V_2 ) ;
if ( V_154 < sizeof( V_50 -> V_156 ) )
goto V_140;
if ( V_50 -> V_156 != V_54 )
goto V_140;
V_5 -> V_50 = V_50 ;
F_14 ( V_2 ) ;
switch ( V_2 -> V_19 ) {
default:
goto V_18;
case V_152 :
V_17 = - V_157 ;
goto V_18;
case V_36 :
V_17 = 0 ;
break;
}
F_38 ( V_5 ) ;
V_17 = F_76 ( V_5 -> V_6 , V_50 , V_154 , V_155 ) ;
if ( V_17 )
goto V_18;
V_17 = F_59 ( V_5 ) ;
if ( V_17 < 0 )
goto V_18;
else
V_17 = 0 ;
V_18:
F_21 ( V_2 ) ;
V_140:
return V_17 ;
}
static int F_77 ( struct V_4 * V_158 , struct V_4 * * V_159 )
{
struct V_1 * V_2 = & V_158 -> V_2 ;
struct V_16 * V_160 ;
struct V_1 * V_161 ;
int V_17 ;
F_21 ( & V_158 -> V_2 ) ;
V_161 = F_26 ( F_7 ( V_2 ) , NULL ) ;
if ( ! V_161 ) {
V_17 = - V_145 ;
V_158 -> V_2 . V_73 = V_145 ;
* V_159 = NULL ;
F_14 ( & V_158 -> V_2 ) ;
goto V_18;
}
* V_159 = F_2 ( V_161 ) ;
V_17 = F_78 ( V_158 -> V_6 , & V_160 , 0 ) ;
F_14 ( & V_158 -> V_2 ) ;
if ( V_17 < 0 ) {
V_158 -> V_2 . V_73 = - V_17 ;
V_161 -> V_19 = V_23 ;
F_16 ( V_161 , V_25 ) ;
V_2 -> V_7 -> V_162 ( V_161 ) ;
F_22 ( V_161 ) ;
* V_159 = NULL ;
goto V_18;
}
if ( V_158 -> V_2 . V_19 == V_23 ) {
if ( V_160 )
F_17 ( V_160 ) ;
V_161 -> V_19 = V_23 ;
F_16 ( V_161 , V_25 ) ;
V_2 -> V_7 -> V_162 ( V_161 ) ;
F_22 ( V_161 ) ;
* V_159 = NULL ;
goto V_18;
}
( * V_159 ) -> V_6 = V_160 ;
V_18:
return V_17 ;
}
static void F_79 ( struct V_1 * V_163 , struct V_1 * V_2 )
{
struct V_4 * V_164 = F_2 ( V_163 ) ;
F_12 ( V_2 ) ;
F_80 ( & V_164 -> V_43 ) ;
F_81 ( & F_2 ( V_2 ) -> V_42 , & V_164 -> V_42 ) ;
F_82 ( & V_164 -> V_43 ) ;
F_83 ( V_163 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_164 = F_2 ( V_2 ) -> V_165 ;
F_80 ( & V_164 -> V_43 ) ;
F_85 ( & F_2 ( V_2 ) -> V_42 ) ;
F_82 ( & V_164 -> V_43 ) ;
F_86 ( & F_2 ( V_2 ) -> V_165 -> V_2 ) ;
F_22 ( V_2 ) ;
}
struct V_1 * F_87 ( struct V_1 * V_163 ,
struct V_16 * V_166 )
{
struct V_4 * V_167 , * V_168 ;
struct V_1 * V_161 ;
F_88 (isk, n, &smc_sk(parent)->accept_q, accept_q) {
V_161 = (struct V_1 * ) V_167 ;
F_84 ( V_161 ) ;
if ( V_161 -> V_19 == V_23 ) {
V_161 -> V_7 -> V_162 ( V_161 ) ;
F_22 ( V_161 ) ;
continue;
}
if ( V_166 )
F_89 ( V_161 , V_166 ) ;
return V_161 ;
}
return NULL ;
}
void F_90 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ! V_2 -> V_169 )
V_2 -> V_169 = V_170 ;
if ( V_5 -> V_22 ) {
V_2 -> V_19 = V_23 ;
} else {
F_15 ( V_5 ) ;
F_16 ( V_2 , V_25 ) ;
V_2 -> V_26 |= V_27 ;
}
if ( V_5 -> V_6 ) {
struct V_16 * V_171 ;
V_171 = V_5 -> V_6 ;
V_5 -> V_6 = NULL ;
F_17 ( V_171 ) ;
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
static int F_91 ( struct V_4 * V_5 )
{
struct V_92 * V_93 = V_5 -> V_30 . V_93 ;
struct V_94 * V_95 ;
int V_96 ;
int V_17 ;
V_95 = & V_93 -> V_97 [ V_98 ] ;
V_17 = F_52 ( V_95 ,
V_95 -> V_105 -> V_106 [ V_95 -> V_107 - 1 ] ,
& V_95 -> V_105 -> V_91 [ V_95 -> V_107 - 1 ] ,
V_172 ) ;
if ( V_17 < 0 )
return V_109 ;
V_96 = F_48 (
& V_95 -> V_173 ,
V_100 ) ;
if ( V_96 <= 0 ) {
struct V_101 V_102 ;
V_17 = F_49 ( V_5 , & V_102 , sizeof( V_102 ) ,
V_103 ) ;
}
return V_17 ;
}
static void F_92 ( struct V_174 * V_175 )
{
struct V_4 * V_159 = F_93 ( V_175 , struct V_4 ,
F_92 ) ;
struct V_16 * V_176 = V_159 -> V_6 ;
struct V_4 * V_158 = V_159 -> V_165 ;
struct V_110 V_177 ;
int V_132 = V_178 ;
struct V_1 * V_179 = & V_159 -> V_2 ;
struct V_180 V_181 ;
struct V_134 * V_105 ;
struct V_49 V_182 ;
struct V_94 * V_95 ;
int V_136 = 0 ;
int V_17 = 0 , V_82 ;
T_1 V_77 ;
T_2 V_78 ;
T_2 V_107 ;
V_136 = F_49 ( V_159 , & V_181 , sizeof( V_181 ) ,
V_183 ) ;
if ( V_136 < 0 )
goto V_140;
if ( V_136 > 0 )
goto V_138;
if ( F_60 ( V_159 ) ) {
V_136 = V_137 ;
goto V_138;
}
F_61 ( V_176 -> V_2 , & V_105 , & V_107 ) ;
if ( ! V_105 ) {
V_136 = V_139 ;
goto V_138;
}
V_17 = F_40 ( V_176 , & V_77 , & V_78 ) ;
if ( V_17 ) {
V_136 = V_139 ;
goto V_138;
}
if ( ( V_181 . V_184 != V_77 ) ||
( V_181 . V_78 != V_78 ) ) {
V_136 = V_139 ;
goto V_138;
}
F_94 ( V_176 , (struct V_46 * ) & V_182 , & V_82 ) ;
F_63 ( & V_144 ) ;
V_132 = F_64 ( V_159 , V_182 . V_56 . V_57 ,
V_105 , V_107 , & V_181 . V_123 , 0 ) ;
if ( V_132 == V_178 )
F_72 ( & V_144 ) ;
if ( V_132 < 0 ) {
V_17 = V_132 ;
if ( V_17 == - V_145 )
V_136 = V_146 ;
else if ( V_17 == - V_147 )
V_136 = V_148 ;
goto V_138;
}
V_95 = & V_159 -> V_30 . V_93 -> V_97 [ V_98 ] ;
V_17 = F_65 ( V_159 ) ;
if ( V_17 ) {
V_136 = V_146 ;
goto V_138;
}
V_17 = F_66 ( V_159 ) ;
if ( V_17 ) {
V_136 = V_146 ;
goto V_138;
}
F_68 ( V_159 ) ;
F_69 ( V_159 ) ;
V_17 = F_95 ( V_159 , V_132 ) ;
if ( V_17 )
goto V_140;
V_136 = F_49 ( V_159 , & V_177 , sizeof( V_177 ) ,
V_185 ) ;
if ( V_136 < 0 )
goto V_140;
if ( V_136 > 0 )
goto V_138;
F_53 ( V_159 , & V_177 ) ;
if ( V_132 == V_133 )
F_57 ( V_95 , & V_177 ) ;
V_17 = F_67 ( & V_159 -> V_30 , & V_177 ) ;
if ( V_17 ) {
V_136 = V_104 ;
goto V_138;
}
if ( V_132 == V_133 ) {
V_17 = F_70 ( V_95 ) ;
if ( V_17 ) {
V_136 = V_104 ;
goto V_138;
}
V_136 = F_91 ( V_159 ) ;
if ( V_136 < 0 ) {
V_17 = V_136 ;
goto V_140;
}
if ( V_136 > 0 )
goto V_138;
}
F_73 ( V_159 ) ;
V_151:
F_33 ( V_179 ) ;
if ( V_179 -> V_19 == V_36 )
V_179 -> V_19 = V_152 ;
V_186:
if ( V_132 == V_133 )
F_72 ( & V_144 ) ;
F_13 ( & V_158 -> V_2 , V_21 ) ;
if ( V_158 -> V_2 . V_19 == V_20 ) {
F_79 ( & V_158 -> V_2 , V_179 ) ;
} else {
F_90 ( V_179 ) ;
}
F_21 ( & V_158 -> V_2 ) ;
V_158 -> V_2 . V_187 ( & V_158 -> V_2 ) ;
F_22 ( & V_158 -> V_2 ) ;
return;
V_138:
F_20 ( & V_159 -> V_30 ) ;
V_159 -> V_22 = true ;
if ( V_136 && ( V_136 != V_153 ) ) {
V_17 = F_74 ( V_159 , V_136 , 0 ) ;
if ( V_17 < sizeof( struct V_101 ) )
goto V_140;
}
goto V_151;
V_140:
V_179 -> V_19 = V_23 ;
F_20 ( & V_159 -> V_30 ) ;
goto V_186;
}
static void V_41 ( struct V_174 * V_175 )
{
struct V_4 * V_158 = F_93 ( V_175 , struct V_4 ,
V_40 ) ;
struct V_4 * V_159 ;
int V_17 = 0 ;
F_14 ( & V_158 -> V_2 ) ;
while ( V_158 -> V_2 . V_19 == V_20 ) {
V_17 = F_77 ( V_158 , & V_159 ) ;
if ( V_17 )
goto V_18;
if ( ! V_159 )
continue;
V_159 -> V_165 = V_158 ;
V_159 -> V_22 = false ;
F_12 ( & V_158 -> V_2 ) ;
F_29 ( & V_159 -> F_92 , F_92 ) ;
F_39 ( V_159 ) ;
F_96 ( & V_159 -> F_92 ) ;
}
V_18:
F_21 ( & V_158 -> V_2 ) ;
V_158 -> V_2 . V_187 ( & V_158 -> V_2 ) ;
}
static int F_97 ( struct V_16 * V_1 , int V_188 )
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
V_2 -> V_189 = V_188 ;
goto V_18;
}
F_38 ( V_5 ) ;
V_17 = F_98 ( V_5 -> V_6 , V_188 ) ;
if ( V_17 )
goto V_18;
V_2 -> V_189 = V_188 ;
V_2 -> V_190 = 0 ;
V_2 -> V_19 = V_20 ;
F_29 ( & V_5 -> V_40 , V_41 ) ;
F_96 ( & V_5 -> V_40 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_99 ( struct V_16 * V_1 , struct V_16 * V_166 ,
int V_155 , bool V_191 )
{
struct V_1 * V_2 = V_1 -> V_2 , * V_61 ;
F_100 ( V_192 , V_193 ) ;
struct V_4 * V_158 ;
long V_194 ;
int V_17 = 0 ;
V_158 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_158 -> V_2 . V_19 != V_20 ) {
V_17 = - V_51 ;
goto V_18;
}
V_194 = F_101 ( V_2 , V_155 & V_195 ) ;
F_102 ( F_103 ( V_2 ) , & V_192 ) ;
while ( ! ( V_61 = F_87 ( V_2 , V_166 ) ) ) {
F_104 ( V_196 ) ;
if ( ! V_194 ) {
V_17 = - V_197 ;
break;
}
F_21 ( V_2 ) ;
V_194 = F_105 ( V_194 ) ;
F_106 () ;
F_14 ( V_2 ) ;
if ( F_107 ( V_193 ) ) {
V_17 = F_108 ( V_194 ) ;
break;
}
}
F_104 ( V_198 ) ;
F_109 ( F_103 ( V_2 ) , & V_192 ) ;
if ( ! V_17 )
V_17 = F_110 ( V_61 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_111 ( struct V_16 * V_1 , struct V_46 * V_50 ,
int * V_82 , int V_199 )
{
struct V_4 * V_5 ;
if ( V_199 && ( V_1 -> V_2 -> V_19 != V_152 ) &&
( V_1 -> V_2 -> V_19 != V_200 ) )
return - V_83 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
return V_5 -> V_6 -> V_201 -> V_202 ( V_5 -> V_6 , V_50 , V_82 , V_199 ) ;
}
static int F_112 ( struct V_16 * V_1 , struct V_203 * V_204 , T_3 V_82 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_205 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 != V_152 ) &&
( V_2 -> V_19 != V_200 ) &&
( V_2 -> V_19 != V_36 ) )
goto V_18;
if ( V_5 -> V_22 )
V_17 = V_5 -> V_6 -> V_201 -> V_206 ( V_5 -> V_6 , V_204 , V_82 ) ;
else
V_17 = F_113 ( V_5 , V_204 , V_82 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_114 ( struct V_16 * V_1 , struct V_203 * V_204 , T_3 V_82 ,
int V_155 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_83 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 == V_36 ) ||
( V_2 -> V_19 == V_20 ) ||
( V_2 -> V_19 == V_23 ) )
goto V_18;
if ( V_2 -> V_19 == V_207 ) {
V_17 = 0 ;
goto V_18;
}
if ( V_5 -> V_22 )
V_17 = V_5 -> V_6 -> V_201 -> V_208 ( V_5 -> V_6 , V_204 , V_82 , V_155 ) ;
else
V_17 = F_115 ( V_5 , V_204 , V_82 , V_155 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static unsigned int F_116 ( struct V_1 * V_163 )
{
struct V_4 * V_167 ;
struct V_1 * V_2 ;
F_14 ( V_163 ) ;
F_117 (isk, &smc_sk(parent)->accept_q, accept_q) {
V_2 = (struct V_1 * ) V_167 ;
if ( V_2 -> V_19 == V_152 ) {
F_21 ( V_163 ) ;
return V_209 | V_210 ;
}
}
F_21 ( V_163 ) ;
return 0 ;
}
static unsigned int F_118 ( struct V_211 * V_211 , struct V_16 * V_1 ,
T_4 * V_192 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_63 = 0 ;
struct V_4 * V_5 ;
int V_17 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
if ( ( V_2 -> V_19 == V_36 ) || V_5 -> V_22 ) {
V_63 = V_5 -> V_6 -> V_201 -> V_212 ( V_211 , V_5 -> V_6 , V_192 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 == V_36 ) && ( V_63 & V_213 ) ) {
V_2 -> V_73 = V_5 -> V_6 -> V_2 -> V_73 ;
if ( V_2 -> V_73 ) {
V_63 |= V_214 ;
} else {
V_17 = F_59 ( V_5 ) ;
if ( V_17 < 0 )
V_63 |= V_214 ;
else
V_63 |= V_213 | V_215 ;
}
}
F_21 ( V_2 ) ;
} else {
F_119 ( V_211 , F_103 ( V_2 ) , V_192 ) ;
if ( V_2 -> V_19 == V_20 )
V_63 |= F_116 ( V_2 ) ;
if ( V_2 -> V_73 )
V_63 |= V_214 ;
if ( F_120 ( & V_5 -> V_30 . V_216 ) ||
( V_2 -> V_26 & V_217 ) ) {
V_63 |= V_213 | V_215 ;
} else {
F_121 ( V_218 , V_2 ) ;
F_122 ( V_219 , & V_2 -> V_220 -> V_155 ) ;
}
if ( F_120 ( & V_5 -> V_30 . V_221 ) )
V_63 |= V_209 | V_210 ;
if ( ( V_2 -> V_26 == V_27 ) ||
( V_2 -> V_19 == V_23 ) )
V_63 |= V_222 ;
if ( V_2 -> V_26 & V_223 )
V_63 |= V_209 | V_210 | V_224 ;
if ( V_2 -> V_19 == V_200 )
V_63 |= V_209 ;
}
return V_63 ;
}
static int F_123 ( struct V_16 * V_1 , int V_225 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_51 ;
int V_226 = 0 ;
V_5 = F_2 ( V_2 ) ;
if ( ( V_225 < V_227 ) || ( V_225 > V_228 ) )
return V_17 ;
F_14 ( V_2 ) ;
V_17 = - V_83 ;
if ( ( V_2 -> V_19 != V_20 ) &&
( V_2 -> V_19 != V_152 ) &&
( V_2 -> V_19 != V_229 ) &&
( V_2 -> V_19 != V_230 ) &&
( V_2 -> V_19 != V_200 ) &&
( V_2 -> V_19 != V_231 ) &&
( V_2 -> V_19 != V_232 ) )
goto V_18;
if ( V_5 -> V_22 ) {
V_17 = F_124 ( V_5 -> V_6 , V_225 ) ;
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
V_17 = F_125 ( V_5 ) ;
break;
case V_227 :
if ( V_2 -> V_19 == V_20 )
V_17 = F_15 ( V_5 ) ;
else
V_17 = 0 ;
break;
}
V_226 = F_124 ( V_5 -> V_6 , V_225 ) ;
V_2 -> V_26 |= V_225 + 1 ;
V_18:
F_21 ( V_2 ) ;
return V_17 ? V_17 : V_226 ;
}
static int F_126 ( struct V_16 * V_1 , int V_234 , int V_235 ,
char T_5 * V_236 , unsigned int V_237 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 -> V_201 -> V_238 ( V_5 -> V_6 , V_234 , V_235 ,
V_236 , V_237 ) ;
}
static int F_127 ( struct V_16 * V_1 , int V_234 , int V_235 ,
char T_5 * V_236 , int T_5 * V_237 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
return V_5 -> V_6 -> V_201 -> V_239 ( V_5 -> V_6 , V_234 , V_235 ,
V_236 , V_237 ) ;
}
static int F_128 ( struct V_16 * V_1 , unsigned int V_240 ,
unsigned long V_241 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_1 -> V_2 ) ;
if ( V_5 -> V_22 )
return V_5 -> V_6 -> V_201 -> V_242 ( V_5 -> V_6 , V_240 , V_241 ) ;
else
return F_129 ( V_1 , V_240 , V_241 ) ;
}
static T_6 F_130 ( struct V_16 * V_1 , struct V_243 * V_243 ,
int V_244 , T_3 V_245 , int V_155 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_205 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_19 != V_152 )
goto V_18;
if ( V_5 -> V_22 )
V_17 = F_131 ( V_5 -> V_6 , V_243 , V_244 ,
V_245 , V_155 ) ;
else
V_17 = F_132 ( V_1 , V_243 , V_244 , V_245 , V_155 ) ;
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static T_6 F_133 ( struct V_16 * V_1 , T_7 * V_246 ,
struct V_247 * V_248 , T_3 V_82 ,
unsigned int V_155 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_4 * V_5 ;
int V_17 = - V_83 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ( V_2 -> V_19 != V_152 ) && ( V_2 -> V_19 != V_23 ) )
goto V_18;
if ( V_5 -> V_22 ) {
V_17 = V_5 -> V_6 -> V_201 -> V_249 ( V_5 -> V_6 , V_246 ,
V_248 , V_82 , V_155 ) ;
} else {
V_17 = - V_250 ;
}
V_18:
F_21 ( V_2 ) ;
return V_17 ;
}
static int F_134 ( struct V_32 * V_32 , struct V_16 * V_1 , int V_251 ,
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
V_2 = F_26 ( V_32 , V_1 ) ;
if ( ! V_2 )
goto V_18;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_22 = false ;
V_17 = F_135 ( V_32 , V_259 , V_253 ,
V_256 , & V_5 -> V_6 ) ;
if ( V_17 )
F_136 ( V_2 ) ;
V_5 -> V_2 . V_65 = F_137 ( V_5 -> V_6 -> V_2 -> V_65 , V_260 ) ;
V_5 -> V_2 . V_66 = F_137 ( V_5 -> V_6 -> V_2 -> V_66 , V_260 ) ;
V_18:
return V_17 ;
}
static int T_8 F_138 ( void )
{
int V_17 ;
V_17 = F_139 () ;
if ( V_17 )
return V_17 ;
V_17 = F_140 () ;
if ( V_17 ) {
F_141 ( L_1 , V_261 , V_17 ) ;
goto V_262;
}
V_17 = F_142 () ;
if ( V_17 ) {
F_141 ( L_2 , V_261 , V_17 ) ;
goto V_262;
}
V_17 = F_143 ( & V_35 , 1 ) ;
if ( V_17 ) {
F_141 ( L_3 , V_261 , V_17 ) ;
goto V_262;
}
V_17 = F_144 ( & V_263 ) ;
if ( V_17 ) {
F_141 ( L_4 , V_261 , V_17 ) ;
goto V_264;
}
F_145 ( & V_265 . V_14 ) ;
V_17 = F_146 () ;
if ( V_17 ) {
F_141 ( L_5 , V_261 , V_17 ) ;
goto V_266;
}
return 0 ;
V_266:
F_147 ( V_33 ) ;
V_264:
F_148 ( & V_35 ) ;
V_262:
F_149 () ;
return V_17 ;
}
static void T_9 F_150 ( void )
{
struct V_92 * V_93 , * V_267 ;
F_151 ( V_268 ) ;
F_152 ( & V_269 . V_15 ) ;
if ( ! F_153 ( & V_269 . V_270 ) )
F_154 ( & V_269 . V_270 , & V_268 ) ;
F_155 ( & V_269 . V_15 ) ;
F_88 (lgr, lg, &lgr_freeing_list, list) {
F_85 ( & V_93 -> V_270 ) ;
F_156 ( V_93 ) ;
}
F_157 () ;
F_147 ( V_33 ) ;
F_148 ( & V_35 ) ;
F_149 () ;
}
