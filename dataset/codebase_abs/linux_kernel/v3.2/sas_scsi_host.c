static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 = 0 , V_10 = 0 ;
if ( F_2 ( V_2 -> V_11 & V_12 ) ) {
F_3 ( L_1 ) ;
return;
}
if ( F_2 ( ! V_7 ) ) {
F_3 ( L_2 ) ;
F_4 ( & V_2 -> V_13 ) ;
F_5 ( V_2 ) ;
return;
}
if ( V_4 -> V_14 == V_15 ) {
V_9 = V_16 ;
} else {
switch ( V_4 -> V_10 ) {
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
V_9 = V_16 ;
break;
case V_22 :
F_6 ( V_7 , V_4 -> V_23 ) ;
if ( F_7 ( V_7 ) - F_8 ( V_7 ) < V_7 -> V_24 )
V_9 = V_25 ;
break;
case V_26 :
V_9 = V_25 ;
break;
case V_27 :
V_9 = V_28 ;
break;
case V_29 :
V_9 = V_30 ;
break;
case V_31 :
V_9 = V_32 ;
break;
case V_33 :
if ( V_4 -> V_34 == V_35 )
V_9 = V_28 ;
else
V_9 = V_25 ;
break;
case V_36 :
F_3 ( L_3
L_4 ,
V_2 -> V_37 -> V_38 -> V_39 -> V_40 ) ;
break;
case V_41 :
V_9 = V_42 ;
break;
case V_43 :
memcpy ( V_7 -> V_44 , V_4 -> V_45 ,
F_9 ( V_46 , V_4 -> V_47 ) ) ;
V_10 = V_43 ;
break;
default:
V_10 = V_4 -> V_10 ;
break;
}
}
F_10 ( V_7 , NULL ) ;
V_7 -> V_48 = ( V_9 << 16 ) | V_10 ;
F_4 ( & V_2 -> V_13 ) ;
F_5 ( V_2 ) ;
V_7 -> V_49 ( V_7 ) ;
}
static struct V_1 * F_11 ( struct V_6 * V_50 ,
struct V_51 * V_37 ,
T_1 V_52 )
{
struct V_1 * V_2 = F_12 ( V_52 ) ;
struct V_53 V_54 ;
if ( ! V_2 )
return NULL ;
V_2 -> V_8 = V_50 ;
F_10 ( V_50 , V_2 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_55 = V_2 -> V_37 -> V_56 ;
V_2 -> V_57 . V_58 = 1 ;
F_13 ( V_50 -> V_59 -> V_54 , & V_54 ) ;
memcpy ( V_2 -> V_57 . V_60 , & V_54 . V_53 , 8 ) ;
V_2 -> V_57 . V_61 = V_62 ;
memcpy ( V_2 -> V_57 . V_63 , V_50 -> V_64 , 16 ) ;
V_2 -> V_65 = F_14 ( V_50 ) ;
V_2 -> V_66 = F_15 ( V_50 ) ;
V_2 -> V_67 = F_7 ( V_50 ) ;
V_2 -> V_68 = V_50 -> V_69 ;
V_2 -> V_70 = F_1 ;
return V_2 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = V_2 -> V_37 -> V_38 -> V_39 ;
struct V_73 * V_74 = & V_72 -> V_74 ;
unsigned long V_75 ;
F_17 ( V_13 ) ;
F_18 ( & V_74 -> V_76 , V_75 ) ;
if ( V_72 -> V_77 < V_74 -> V_78 + 1 ) {
F_19 ( & V_74 -> V_76 , V_75 ) ;
return - V_27 ;
}
F_20 ( & V_2 -> V_13 , & V_74 -> V_79 ) ;
V_74 -> V_78 += 1 ;
F_19 ( & V_74 -> V_76 , V_75 ) ;
F_21 ( V_74 -> V_80 ) ;
return 0 ;
}
int F_22 ( struct V_81 * V_82 , struct V_6 * V_50 )
{
struct V_83 * V_84 = F_23 ( V_82 -> V_85 ) ;
struct V_51 * V_37 = F_24 ( V_50 ) ;
struct V_71 * V_72 = V_37 -> V_38 -> V_39 ;
struct V_1 * V_2 ;
int V_86 = 0 ;
if ( V_37 -> V_87 ) {
V_50 -> V_48 = V_30 << 16 ;
goto V_88;
}
if ( F_25 ( V_37 ) ) {
unsigned long V_75 ;
F_18 ( V_37 -> V_89 . V_90 -> V_91 , V_75 ) ;
V_86 = F_26 ( V_50 , V_37 -> V_89 . V_90 ) ;
F_19 ( V_37 -> V_89 . V_90 -> V_91 , V_75 ) ;
return V_86 ;
}
V_2 = F_11 ( V_50 , V_37 , V_92 ) ;
if ( ! V_2 )
return V_93 ;
if ( V_72 -> V_94 < 2 )
V_86 = V_84 -> V_95 -> V_96 ( V_2 , 1 , V_92 ) ;
else
V_86 = F_16 ( V_2 ) ;
if ( V_86 )
goto V_97;
return 0 ;
V_97:
F_3 ( L_5 , V_86 ) ;
F_10 ( V_50 , NULL ) ;
F_5 ( V_2 ) ;
if ( V_86 == - V_27 )
V_50 -> V_48 = V_28 << 16 ;
else
V_50 -> V_48 = V_25 << 16 ;
V_88:
V_50 -> V_49 ( V_50 ) ;
return 0 ;
}
static void F_27 ( struct V_6 * V_50 )
{
struct V_1 * V_2 = F_28 ( V_50 ) ;
struct V_71 * V_72 = F_29 ( V_50 -> V_59 -> V_82 ) ;
V_2 -> V_11 &= ~ V_12 ;
V_2 -> V_70 ( V_2 ) ;
F_30 ( V_50 , & V_72 -> V_98 ) ;
}
static void F_31 ( struct V_99 * V_100 , struct V_6 * V_101 )
{
struct V_6 * V_50 , * V_102 ;
F_32 (cmd, n, error_q, eh_entry) {
if ( V_50 -> V_59 -> V_103 == V_101 -> V_59 -> V_103 &&
V_50 -> V_59 -> V_54 == V_101 -> V_59 -> V_54 )
F_27 ( V_50 ) ;
}
}
static void F_33 ( struct V_99 * V_100 ,
struct V_51 * V_37 )
{
struct V_6 * V_50 , * V_102 ;
F_32 (cmd, n, error_q, eh_entry) {
struct V_51 * V_104 = F_24 ( V_50 ) ;
if ( V_104 == V_37 )
F_27 ( V_50 ) ;
}
}
static void F_34 ( struct V_99 * V_100 ,
struct V_105 * V_38 )
{
struct V_6 * V_50 , * V_102 ;
F_32 (cmd, n, error_q, eh_entry) {
struct V_51 * V_37 = F_24 ( V_50 ) ;
struct V_105 * V_104 = V_37 -> V_38 ;
if ( V_104 == V_38 )
F_27 ( V_50 ) ;
}
}
static enum V_106 F_35 ( struct V_1 * V_2 )
{
struct V_71 * V_39 = V_2 -> V_37 -> V_38 -> V_39 ;
unsigned long V_75 ;
int V_84 , V_86 ;
struct V_83 * V_107 =
F_23 ( V_2 -> V_37 -> V_38 -> V_39 -> V_74 . V_108 -> V_85 ) ;
if ( V_39 -> V_94 > 1 ) {
struct V_73 * V_74 = & V_39 -> V_74 ;
struct V_1 * V_109 , * V_102 ;
F_18 ( & V_74 -> V_76 , V_75 ) ;
F_32 (t, n, &core->task_queue, list) {
if ( V_2 == V_109 ) {
F_4 ( & V_109 -> V_13 ) ;
F_19 ( & V_74 -> V_76 ,
V_75 ) ;
F_3 ( L_6
L_7 ,
V_110 , V_2 ) ;
return V_111 ;
}
}
F_19 ( & V_74 -> V_76 , V_75 ) ;
}
for ( V_84 = 0 ; V_84 < 5 ; V_84 ++ ) {
F_3 ( L_8 , V_110 , V_2 ) ;
V_86 = V_107 -> V_95 -> V_112 ( V_2 ) ;
F_18 ( & V_2 -> V_113 , V_75 ) ;
if ( V_2 -> V_11 & V_114 ) {
F_19 ( & V_2 -> V_113 , V_75 ) ;
F_3 ( L_9 , V_110 ,
V_2 ) ;
return V_115 ;
}
F_19 ( & V_2 -> V_113 , V_75 ) ;
if ( V_86 == V_116 ) {
F_3 ( L_10 ,
V_110 , V_2 ) ;
return V_111 ;
} else if ( V_107 -> V_95 -> V_117 ) {
F_3 ( L_11 ,
V_110 , V_2 ) ;
V_86 = V_107 -> V_95 -> V_117 ( V_2 ) ;
switch ( V_86 ) {
case V_118 :
F_3 ( L_12 ,
V_110 , V_2 ) ;
return V_119 ;
case V_116 :
F_3 ( L_13 ,
V_110 , V_2 ) ;
return V_120 ;
case V_121 :
F_3 ( L_14 ,
V_110 , V_2 ) ;
return V_122 ;
}
}
}
return V_86 ;
}
static int F_36 ( struct V_51 * V_37 , struct V_6 * V_50 )
{
int V_86 = V_121 ;
struct V_53 V_54 ;
struct V_83 * V_84 =
F_23 ( V_37 -> V_38 -> V_39 -> V_74 . V_108 -> V_85 ) ;
F_13 ( V_50 -> V_59 -> V_54 , & V_54 ) ;
F_3 ( L_15 ,
F_37 ( V_37 -> V_123 ) ,
V_50 -> V_59 -> V_54 ) ;
if ( V_84 -> V_95 -> V_124 )
V_86 = V_84 -> V_95 -> V_124 ( V_37 , V_54 . V_53 ) ;
if ( V_86 == V_121 ) {
if ( V_84 -> V_95 -> V_125 )
V_86 = V_84 -> V_95 -> V_125 ( V_37 , V_54 . V_53 ) ;
}
if ( V_86 == V_121 ) {
if ( V_84 -> V_95 -> V_126 )
V_86 = V_84 -> V_95 -> V_126 ( V_37 , V_54 . V_53 ) ;
}
return V_86 ;
}
static int F_38 ( struct V_51 * V_37 )
{
int V_86 = V_121 ;
struct V_83 * V_84 =
F_23 ( V_37 -> V_38 -> V_39 -> V_74 . V_108 -> V_85 ) ;
F_3 ( L_16 ,
F_37 ( V_37 -> V_123 ) ) ;
if ( V_84 -> V_95 -> V_127 )
V_86 = V_84 -> V_95 -> V_127 ( V_37 ) ;
return V_86 ;
}
struct V_128 * F_39 ( struct V_51 * V_37 )
{
struct V_51 * V_129 = V_37 -> V_130 ;
struct V_131 * V_132 = NULL ;
int V_84 ;
if ( ! V_129 )
return V_37 -> V_38 -> V_133 ;
for ( V_84 = 0 ; V_84 < V_129 -> V_134 . V_135 ; V_84 ++ )
if ( ! memcmp ( V_37 -> V_123 ,
V_129 -> V_134 . V_131 [ V_84 ] . V_136 ,
V_137 ) ) {
V_132 = & V_129 -> V_134 . V_131 [ V_84 ] ;
break;
}
F_40 ( ! V_132 ) ;
return V_132 -> V_133 ;
}
int F_41 ( struct V_6 * V_50 )
{
struct V_51 * V_37 = F_24 ( V_50 ) ;
struct V_83 * V_84 =
F_23 ( V_37 -> V_38 -> V_39 -> V_74 . V_108 -> V_85 ) ;
struct V_53 V_54 ;
int V_86 ;
F_13 ( V_50 -> V_59 -> V_54 , & V_54 ) ;
if ( ! V_84 -> V_95 -> V_126 )
return V_138 ;
V_86 = V_84 -> V_95 -> V_126 ( V_37 , V_54 . V_53 ) ;
if ( V_86 == V_118 || V_86 == V_116 )
return V_139 ;
return V_138 ;
}
int F_42 ( struct V_6 * V_50 )
{
struct V_51 * V_37 = F_24 ( V_50 ) ;
struct V_128 * V_133 = F_39 ( V_37 ) ;
int V_86 ;
V_86 = F_43 ( V_133 , 1 ) ;
if ( V_86 )
F_3 ( L_17 ,
F_44 ( & V_133 -> V_37 . V_140 ) ,
V_86 ) ;
if ( V_86 == V_118 || V_86 == V_116 )
return V_139 ;
return V_138 ;
}
static int F_45 ( struct V_6 * V_50 )
{
int V_86 ;
struct V_81 * V_108 = V_50 -> V_59 -> V_82 ;
if ( ! V_108 -> V_141 -> V_142 )
goto V_143;
V_86 = V_108 -> V_141 -> V_142 ( V_50 ) ;
if ( V_86 == V_139 )
return V_86 ;
V_143:
if ( V_108 -> V_141 -> V_144 )
return V_108 -> V_141 -> V_144 ( V_50 ) ;
return V_138 ;
}
static int F_46 ( struct V_81 * V_108 ,
struct V_99 * V_145 ,
struct V_99 * V_146 )
{
struct V_6 * V_50 , * V_102 ;
enum V_106 V_86 = V_115 ;
int V_147 , V_148 ;
struct V_83 * V_84 = F_23 ( V_108 -> V_85 ) ;
unsigned long V_75 ;
struct V_71 * V_39 = F_29 ( V_108 ) ;
V_149:
F_32 (cmd, n, work_q, eh_entry) {
struct V_1 * V_2 = F_28 ( V_50 ) ;
if ( ! V_2 )
continue;
F_4 ( & V_50 -> V_150 ) ;
F_18 ( & V_2 -> V_113 , V_75 ) ;
V_148 = V_2 -> V_11 & V_151 ;
F_19 ( & V_2 -> V_113 , V_75 ) ;
if ( V_148 ) {
F_3 ( L_18 ,
V_110 , V_2 ) ;
goto V_152;
}
F_3 ( L_19 , V_2 ) ;
V_86 = F_35 ( V_2 ) ;
V_50 -> V_153 = 0 ;
switch ( V_86 ) {
case V_115 :
F_3 ( L_9 , V_110 ,
V_2 ) ;
F_27 ( V_50 ) ;
continue;
case V_111 :
F_3 ( L_10 ,
V_110 , V_2 ) ;
F_27 ( V_50 ) ;
continue;
case V_119 :
F_3 ( L_20 , V_2 ) ;
V_152:
V_147 = F_36 ( V_2 -> V_37 , V_50 ) ;
if ( V_147 == V_116 ) {
F_3 ( L_21
L_22 ,
F_37 ( V_2 -> V_37 ) ,
V_50 -> V_59 -> V_54 ) ;
F_27 ( V_50 ) ;
F_31 ( V_145 , V_50 ) ;
goto V_149;
}
case V_120 :
case V_122 :
F_3 ( L_23 ,
V_2 ) ;
V_147 = F_38 ( V_2 -> V_37 ) ;
if ( V_147 == V_116 ) {
struct V_51 * V_37 = V_2 -> V_37 ;
F_3 ( L_24 ,
F_37 ( V_2 -> V_37 -> V_123 ) ) ;
F_27 ( V_50 ) ;
F_33 ( V_145 , V_37 ) ;
goto V_149;
}
F_45 ( V_50 ) ;
if ( V_84 -> V_95 -> V_154 ) {
struct V_105 * V_38 = V_2 -> V_37 -> V_38 ;
F_3 ( L_25 ,
V_38 -> V_155 ) ;
V_86 = V_84 -> V_95 -> V_154 ( V_38 ) ;
if ( V_86 == V_116 ) {
F_3 ( L_26
L_27 , V_38 -> V_155 ) ;
F_27 ( V_50 ) ;
F_34 ( V_145 ,
V_38 ) ;
goto V_149;
}
}
if ( V_84 -> V_95 -> V_156 ) {
F_3 ( L_28 ) ;
V_86 = V_84 -> V_95 -> V_156 ( V_39 ) ;
if ( V_86 == V_116 ) {
F_3 ( L_29
L_27 ) ;
F_27 ( V_50 ) ;
goto V_157;
}
}
F_3 ( L_30
L_31 ,
F_37 ( V_2 -> V_37 -> V_123 ) ,
V_50 -> V_59 -> V_54 ) ;
F_27 ( V_50 ) ;
goto V_157;
}
}
return F_47 ( V_145 ) ;
V_157:
F_3 ( L_32 , V_110 ) ;
F_32 (cmd, n, work_q, eh_entry)
F_27 ( V_50 ) ;
return F_47 ( V_145 ) ;
}
void F_48 ( struct V_81 * V_108 )
{
struct V_71 * V_39 = F_29 ( V_108 ) ;
unsigned long V_75 ;
F_17 ( V_158 ) ;
F_18 ( V_108 -> V_159 , V_75 ) ;
F_49 ( & V_108 -> V_160 , & V_158 ) ;
V_108 -> V_161 = 0 ;
F_19 ( V_108 -> V_159 , V_75 ) ;
F_3 ( L_33 , V_110 ) ;
if ( F_46 ( V_108 , & V_158 , & V_39 -> V_98 ) )
goto V_162;
if ( ! F_50 ( V_108 , & V_158 , & V_39 -> V_98 ) )
if ( ! F_51 ( & V_158 , & V_39 -> V_98 ) )
F_52 ( V_108 , & V_158 , & V_39 -> V_98 ) ;
V_162:
F_53 ( V_108 ) ;
F_54 ( & V_39 -> V_98 ) ;
F_3 ( L_34 , V_110 ) ;
return;
}
enum V_163 F_55 ( struct V_6 * V_50 )
{
struct V_1 * V_2 = F_28 ( V_50 ) ;
unsigned long V_75 ;
enum V_163 V_164 ;
if ( F_56 ( V_50 , V_2 , & V_164 ) )
return V_164 ;
if ( ! V_2 ) {
V_50 -> V_165 -> V_166 /= 2 ;
F_3 ( L_35 ,
V_50 , V_2 , ( V_50 -> V_165 -> V_166 ?
L_36 : L_37 ) ) ;
if ( ! V_50 -> V_165 -> V_166 )
return V_167 ;
return V_168 ;
}
F_18 ( & V_2 -> V_113 , V_75 ) ;
F_40 ( V_2 -> V_11 & V_12 ) ;
if ( V_2 -> V_11 & V_114 ) {
F_19 ( & V_2 -> V_113 , V_75 ) ;
F_3 ( L_38
L_39 , V_50 , V_2 ) ;
return V_169 ;
}
if ( ! ( V_2 -> V_11 & V_170 ) ) {
F_19 ( & V_2 -> V_113 , V_75 ) ;
F_3 ( L_40
L_41 ,
V_50 , V_2 ) ;
return V_168 ;
}
V_2 -> V_11 |= V_12 ;
F_19 ( & V_2 -> V_113 , V_75 ) ;
F_3 ( L_42 ,
V_50 , V_2 ) ;
return V_167 ;
}
int F_57 ( struct V_171 * V_172 , int V_50 , void T_2 * V_173 )
{
struct V_51 * V_37 = F_58 ( V_172 ) ;
if ( F_25 ( V_37 ) )
return F_59 ( V_37 -> V_89 . V_90 , V_172 , V_50 , V_173 ) ;
return - V_174 ;
}
struct V_51 * F_60 ( struct V_175 * V_176 )
{
struct V_81 * V_108 = F_61 ( V_176 -> V_37 . V_130 ) ;
struct V_71 * V_39 = F_29 ( V_108 ) ;
struct V_51 * V_177 = NULL ;
int V_84 ;
unsigned long V_75 ;
F_18 ( & V_39 -> V_178 , V_75 ) ;
for ( V_84 = 0 ; V_84 < V_39 -> V_135 ; V_84 ++ ) {
struct V_105 * V_38 = V_39 -> V_179 [ V_84 ] ;
struct V_51 * V_37 ;
F_62 ( & V_38 -> V_180 ) ;
F_63 (dev, &port->dev_list, dev_list_node) {
if ( V_176 == V_37 -> V_176 ) {
V_177 = V_37 ;
F_64 ( & V_38 -> V_180 ) ;
goto V_181;
}
}
F_64 ( & V_38 -> V_180 ) ;
}
V_181:
F_19 ( & V_39 -> V_178 , V_75 ) ;
return V_177 ;
}
static inline struct V_51 * F_65 ( struct V_182 * V_183 )
{
struct V_175 * V_176 = F_66 ( V_183 -> V_37 . V_130 ) ;
return F_60 ( V_176 ) ;
}
int F_67 ( struct V_182 * V_183 )
{
struct V_51 * V_177 = F_65 ( V_183 ) ;
int V_86 ;
if ( ! V_177 )
return - V_184 ;
if ( F_25 ( V_177 ) ) {
V_86 = F_68 ( V_177 , V_183 ) ;
if ( V_86 )
return V_86 ;
}
V_183 -> V_185 = V_177 ;
return 0 ;
}
int F_69 ( struct V_171 * V_186 )
{
struct V_51 * V_37 = F_58 ( V_186 ) ;
struct V_71 * V_72 ;
F_40 ( V_37 -> V_176 -> V_187 . V_188 != V_189 ) ;
if ( F_25 ( V_37 ) ) {
F_70 ( V_186 , V_37 -> V_89 . V_90 ) ;
return 0 ;
}
V_72 = V_37 -> V_38 -> V_39 ;
F_71 ( V_186 ) ;
if ( V_186 -> V_190 ) {
F_72 ( V_186 , V_191 ) ;
F_73 ( V_186 , V_192 ) ;
} else {
F_3 ( L_43
L_44 , F_37 ( V_37 -> V_123 ) ,
V_186 -> V_54 ) ;
V_186 -> V_190 = 0 ;
F_72 ( V_186 , 0 ) ;
F_74 ( V_186 , 1 ) ;
}
V_186 -> V_193 = 1 ;
return 0 ;
}
void F_75 ( struct V_171 * V_186 )
{
struct V_51 * V_37 = F_58 ( V_186 ) ;
if ( F_25 ( V_37 ) )
F_76 ( V_37 ) -> V_194 = V_195 ;
}
int F_77 ( struct V_171 * V_172 , int V_196 , int V_197 )
{
struct V_51 * V_37 = F_58 ( V_172 ) ;
if ( F_25 ( V_37 ) )
return F_78 ( V_37 -> V_89 . V_90 , V_172 , V_196 ,
V_197 ) ;
switch ( V_197 ) {
case V_198 :
case V_199 :
if ( ! V_172 -> V_190 )
V_196 = 1 ;
F_79 ( V_172 , F_80 ( V_172 ) , V_196 ) ;
break;
case V_200 :
F_81 ( V_172 , V_196 ) ;
break;
default:
return - V_201 ;
}
return V_196 ;
}
int F_82 ( struct V_171 * V_186 , int V_202 )
{
struct V_51 * V_37 = F_58 ( V_186 ) ;
if ( F_25 ( V_37 ) )
return - V_174 ;
if ( ! V_186 -> V_190 )
return 0 ;
F_74 ( V_186 , 1 ) ;
F_72 ( V_186 , V_202 ) ;
F_73 ( V_186 , V_186 -> V_203 ) ;
return V_202 ;
}
int F_83 ( struct V_171 * V_186 ,
struct V_204 * V_205 ,
T_3 V_206 , int * V_207 )
{
V_207 [ 0 ] = 255 ;
V_207 [ 1 ] = 63 ;
F_84 ( V_206 , 255 * 63 ) ;
V_207 [ 2 ] = V_206 ;
return 0 ;
}
static void F_85 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = & V_72 -> V_74 ;
unsigned long V_75 ;
F_17 ( V_208 ) ;
int V_209 ;
int V_86 ;
struct V_83 * V_84 = F_23 ( V_74 -> V_108 -> V_85 ) ;
F_18 ( & V_74 -> V_76 , V_75 ) ;
while ( ! F_86 () &&
! F_47 ( & V_74 -> V_79 ) ) {
V_209 = V_72 -> V_77 - V_74 -> V_78 ;
if ( V_209 >= 0 ) {
V_209 = V_74 -> V_78 ;
F_49 ( & V_74 -> V_79 , & V_208 ) ;
} else {
struct V_99 * V_210 , * V_102 ;
V_209 = V_72 -> V_77 ;
F_87 (a, n, &core->task_queue) {
F_88 ( V_210 , & V_208 ) ;
if ( -- V_209 == 0 )
break;
}
V_209 = V_72 -> V_77 ;
}
V_74 -> V_78 -= V_209 ;
F_19 ( & V_74 -> V_76 , V_75 ) ;
{
struct V_1 * V_2 = F_89 ( V_208 . V_211 ,
struct V_1 ,
V_13 ) ;
F_4 ( & V_208 ) ;
V_86 = V_84 -> V_95 -> V_96 ( V_2 , V_209 ,
V_212 ) ;
if ( F_2 ( V_86 ) )
F_90 ( & V_208 , V_2 -> V_13 . V_213 , & V_2 -> V_13 ) ;
}
F_18 ( & V_74 -> V_76 , V_75 ) ;
if ( V_86 ) {
F_49 ( & V_208 , & V_74 -> V_79 ) ;
V_74 -> V_78 += V_209 ;
}
}
F_19 ( & V_74 -> V_76 , V_75 ) ;
}
static int F_91 ( void * V_214 )
{
struct V_71 * V_72 = V_214 ;
while ( 1 ) {
F_92 ( V_215 ) ;
F_93 () ;
F_85 ( V_72 ) ;
if ( F_86 () )
break;
}
return 0 ;
}
int F_94 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = & V_72 -> V_74 ;
F_95 ( & V_74 -> V_76 ) ;
V_74 -> V_78 = 0 ;
F_96 ( & V_74 -> V_79 ) ;
V_74 -> V_80 = F_97 ( F_91 , V_72 ,
L_45 , V_74 -> V_108 -> V_216 ) ;
if ( F_98 ( V_74 -> V_80 ) )
return F_99 ( V_74 -> V_80 ) ;
return 0 ;
}
void F_100 ( struct V_71 * V_72 )
{
unsigned long V_75 ;
struct V_73 * V_74 = & V_72 -> V_74 ;
struct V_1 * V_2 , * V_102 ;
F_101 ( V_74 -> V_80 ) ;
if ( ! F_47 ( & V_74 -> V_79 ) )
F_3 ( L_46 ,
F_37 ( V_72 -> V_123 ) ) ;
F_18 ( & V_74 -> V_76 , V_75 ) ;
F_32 (task, n, &core->task_queue, list) {
struct V_6 * V_50 = V_2 -> V_8 ;
F_4 ( & V_2 -> V_13 ) ;
F_10 ( V_50 , NULL ) ;
F_5 ( V_2 ) ;
V_50 -> V_48 = V_42 << 16 ;
V_50 -> V_49 ( V_50 ) ;
}
F_19 ( & V_74 -> V_76 , V_75 ) ;
}
int F_102 ( struct V_1 * V_2 )
{
struct V_83 * V_107 =
F_23 ( V_2 -> V_37 -> V_38 -> V_39 -> V_74 . V_108 -> V_85 ) ;
unsigned long V_75 ;
int V_86 ;
F_18 ( & V_2 -> V_113 , V_75 ) ;
if ( V_2 -> V_11 & V_12 ||
V_2 -> V_11 & V_114 ) {
F_19 ( & V_2 -> V_113 , V_75 ) ;
F_3 ( L_47 , V_110 ,
V_2 ) ;
return 0 ;
}
V_2 -> V_11 |= V_12 ;
F_19 ( & V_2 -> V_113 , V_75 ) ;
if ( ! V_107 -> V_95 -> V_112 )
return - V_184 ;
V_86 = V_107 -> V_95 -> V_112 ( V_2 ) ;
F_18 ( & V_2 -> V_113 , V_75 ) ;
if ( ( V_2 -> V_11 & V_114 ) ||
( V_86 == V_116 ) )
{
F_19 ( & V_2 -> V_113 , V_75 ) ;
V_2 -> V_70 ( V_2 ) ;
return 0 ;
}
if ( ! ( V_2 -> V_11 & V_114 ) )
V_2 -> V_11 &= ~ V_12 ;
F_19 ( & V_2 -> V_113 , V_75 ) ;
return - V_217 ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_7 ) {
if ( ! F_104 ( & V_2 -> V_218 ) )
return;
V_2 -> V_218 . V_219 ( V_2 -> V_218 . V_220 ) ;
return;
}
if ( F_25 ( V_2 -> V_37 ) ) {
F_105 ( V_2 ) ;
} else {
struct V_221 * V_208 = V_7 -> V_59 -> V_221 ;
unsigned long V_75 ;
F_18 ( V_208 -> V_222 , V_75 ) ;
F_106 ( V_7 -> V_165 ) ;
F_19 ( V_208 -> V_222 , V_75 ) ;
F_107 ( V_7 -> V_59 -> V_82 ) ;
}
}
int F_108 ( struct V_171 * V_186 )
{
struct V_51 * V_37 = F_58 ( V_186 ) ;
if ( F_25 ( V_37 ) )
return F_109 ( V_37 -> V_89 . V_90 ) ;
return 0 ;
}
void F_110 ( struct V_182 * V_183 )
{
struct V_51 * V_177 = F_65 ( V_183 ) ;
if ( ! V_177 )
return;
if ( F_25 ( V_177 ) )
F_111 ( V_177 -> V_89 . V_90 ) ;
return;
}
static void F_112 ( T_4 * V_123 , const char * V_223 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < V_137 ; V_84 ++ ) {
T_4 V_224 , V_225 ;
if ( ! * V_223 )
break;
V_224 = isdigit ( * V_223 ) ? * V_223 - '0' : toupper ( * V_223 ) - 'A' + 10 ;
V_223 ++ ;
V_225 = isdigit ( * V_223 ) ? * V_223 - '0' : toupper ( * V_223 ) - 'A' + 10 ;
V_223 ++ ;
V_123 [ V_84 ] = ( V_224 << 4 ) | V_225 ;
}
}
int F_113 ( struct V_81 * V_108 , T_4 * V_226 )
{
int V_86 ;
const struct V_227 * V_228 ;
V_86 = F_114 ( & V_228 , L_48 , & V_108 -> V_229 ) ;
if ( V_86 )
return V_86 ;
if ( V_228 -> V_230 < V_231 ) {
V_86 = - V_184 ;
goto V_162;
}
F_112 ( V_226 , V_228 -> V_220 ) ;
V_162:
F_115 ( V_228 ) ;
return V_86 ;
}
