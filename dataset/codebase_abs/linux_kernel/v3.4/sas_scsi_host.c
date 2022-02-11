static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
int V_8 = 0 , V_9 = 0 ;
if ( V_6 -> V_10 == V_11 ) {
V_8 = V_12 ;
} else {
switch ( V_6 -> V_9 ) {
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
V_8 = V_12 ;
break;
case V_18 :
F_2 ( V_2 , V_6 -> V_19 ) ;
if ( F_3 ( V_2 ) - F_4 ( V_2 ) < V_2 -> V_20 )
V_8 = V_21 ;
break;
case V_22 :
V_8 = V_21 ;
break;
case V_23 :
V_8 = V_24 ;
break;
case V_25 :
V_8 = V_26 ;
break;
case V_27 :
V_8 = V_28 ;
break;
case V_29 :
if ( V_6 -> V_30 == V_31 )
V_8 = V_24 ;
else
V_8 = V_21 ;
break;
case V_32 :
F_5 ( L_1
L_2 ,
V_4 -> V_33 -> V_34 -> V_35 -> V_36 ) ;
break;
case V_37 :
V_8 = V_38 ;
break;
case V_39 :
memcpy ( V_2 -> V_40 , V_6 -> V_41 ,
F_6 ( V_42 , V_6 -> V_43 ) ) ;
V_9 = V_39 ;
break;
default:
V_9 = V_6 -> V_9 ;
break;
}
}
V_2 -> V_44 = ( V_8 << 16 ) | V_9 ;
F_7 ( V_2 , NULL ) ;
F_8 ( & V_4 -> V_45 ) ;
F_9 ( V_4 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_46 ;
struct V_47 * V_33 = V_4 -> V_33 ;
struct V_48 * V_35 = V_33 -> V_34 -> V_35 ;
unsigned long V_49 ;
F_11 ( & V_33 -> V_50 , V_49 ) ;
if ( F_12 ( V_51 , & V_35 -> V_52 ) )
V_4 = NULL ;
else
F_7 ( V_2 , NULL ) ;
F_13 ( & V_33 -> V_50 , V_49 ) ;
if ( F_14 ( ! V_4 ) ) {
F_5 ( L_3 ) ;
return;
}
if ( F_14 ( ! V_2 ) ) {
F_5 ( L_4 ) ;
F_8 ( & V_4 -> V_45 ) ;
F_9 ( V_4 ) ;
return;
}
F_1 ( V_2 , V_4 ) ;
V_2 -> V_53 ( V_2 ) ;
}
static struct V_3 * F_15 ( struct V_1 * V_54 ,
struct V_47 * V_33 ,
T_1 V_55 )
{
struct V_3 * V_4 = F_16 ( V_55 ) ;
struct V_56 V_57 ;
if ( ! V_4 )
return NULL ;
V_4 -> V_46 = V_54 ;
F_7 ( V_54 , V_4 ) ;
V_4 -> V_33 = V_33 ;
V_4 -> V_58 = V_4 -> V_33 -> V_59 ;
V_4 -> V_60 . V_61 = 1 ;
F_17 ( V_54 -> V_62 -> V_57 , & V_57 ) ;
memcpy ( V_4 -> V_60 . V_63 , & V_57 . V_56 , 8 ) ;
V_4 -> V_60 . V_64 = V_65 ;
memcpy ( V_4 -> V_60 . V_66 , V_54 -> V_67 , 16 ) ;
V_4 -> V_68 = F_18 ( V_54 ) ;
V_4 -> V_69 = F_19 ( V_54 ) ;
V_4 -> V_70 = F_3 ( V_54 ) ;
V_4 -> V_71 = V_54 -> V_72 ;
V_4 -> V_73 = F_10 ;
return V_4 ;
}
int F_20 ( struct V_3 * V_4 )
{
struct V_48 * V_74 = V_4 -> V_33 -> V_34 -> V_35 ;
struct V_75 * V_76 = & V_74 -> V_76 ;
unsigned long V_49 ;
F_21 ( V_45 ) ;
F_11 ( & V_76 -> V_77 , V_49 ) ;
if ( V_74 -> V_78 < V_76 -> V_79 + 1 ) {
F_13 ( & V_76 -> V_77 , V_49 ) ;
return - V_23 ;
}
F_22 ( & V_4 -> V_45 , & V_76 -> V_80 ) ;
V_76 -> V_79 += 1 ;
F_13 ( & V_76 -> V_77 , V_49 ) ;
F_23 ( V_76 -> V_81 ) ;
return 0 ;
}
int F_24 ( struct V_82 * V_83 , struct V_1 * V_54 )
{
struct V_84 * V_85 = F_25 ( V_83 -> V_86 ) ;
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_48 * V_74 = V_33 -> V_34 -> V_35 ;
struct V_3 * V_4 ;
int V_87 = 0 ;
if ( F_12 ( V_88 , & V_33 -> V_52 ) ) {
V_54 -> V_44 = V_26 << 16 ;
goto V_89;
}
if ( F_27 ( V_33 ) ) {
F_28 ( V_33 -> V_90 . V_91 -> V_92 ) ;
V_87 = F_29 ( V_54 , V_33 -> V_90 . V_91 ) ;
F_30 ( V_33 -> V_90 . V_91 -> V_92 ) ;
return V_87 ;
}
V_4 = F_15 ( V_54 , V_33 , V_93 ) ;
if ( ! V_4 )
return V_94 ;
if ( V_74 -> V_95 < 2 )
V_87 = V_85 -> V_96 -> V_97 ( V_4 , 1 , V_93 ) ;
else
V_87 = F_20 ( V_4 ) ;
if ( V_87 )
goto V_98;
return 0 ;
V_98:
F_5 ( L_5 , V_87 ) ;
F_7 ( V_54 , NULL ) ;
F_9 ( V_4 ) ;
if ( V_87 == - V_23 )
V_54 -> V_44 = V_24 << 16 ;
else
V_54 -> V_44 = V_21 << 16 ;
V_89:
V_54 -> V_53 ( V_54 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_54 )
{
struct V_48 * V_74 = F_32 ( V_54 -> V_62 -> V_83 ) ;
struct V_3 * V_4 = F_33 ( V_54 ) ;
F_1 ( V_54 , V_4 ) ;
F_34 ( V_54 , & V_74 -> V_99 ) ;
}
static void F_35 ( struct V_1 * V_54 )
{
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_48 * V_35 = V_33 -> V_34 -> V_35 ;
struct V_3 * V_4 = F_33 ( V_54 ) ;
if ( ! F_27 ( V_33 ) ) {
F_31 ( V_54 ) ;
return;
}
F_1 ( V_54 , V_4 ) ;
F_36 ( & V_54 -> V_100 , & V_35 -> V_101 ) ;
}
static void F_37 ( struct V_102 * V_103 , struct V_1 * V_104 )
{
struct V_1 * V_54 , * V_105 ;
F_38 (cmd, n, error_q, eh_entry) {
if ( V_54 -> V_62 -> V_106 == V_104 -> V_62 -> V_106 &&
V_54 -> V_62 -> V_57 == V_104 -> V_62 -> V_57 )
F_35 ( V_54 ) ;
}
}
static void F_39 ( struct V_102 * V_103 ,
struct V_47 * V_33 )
{
struct V_1 * V_54 , * V_105 ;
F_38 (cmd, n, error_q, eh_entry) {
struct V_47 * V_107 = F_26 ( V_54 ) ;
if ( V_107 == V_33 )
F_31 ( V_54 ) ;
}
}
static void F_40 ( struct V_102 * V_103 ,
struct V_108 * V_34 )
{
struct V_1 * V_54 , * V_105 ;
F_38 (cmd, n, error_q, eh_entry) {
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_108 * V_107 = V_33 -> V_34 ;
if ( V_107 == V_34 )
F_31 ( V_54 ) ;
}
}
static enum V_109 F_41 ( struct V_3 * V_4 )
{
struct V_48 * V_35 = V_4 -> V_33 -> V_34 -> V_35 ;
unsigned long V_49 ;
int V_85 , V_87 ;
struct V_84 * V_110 =
F_25 ( V_4 -> V_33 -> V_34 -> V_35 -> V_76 . V_111 -> V_86 ) ;
if ( V_35 -> V_95 > 1 ) {
struct V_75 * V_76 = & V_35 -> V_76 ;
struct V_3 * V_112 , * V_105 ;
F_42 ( & V_76 -> V_113 ) ;
F_11 ( & V_76 -> V_77 , V_49 ) ;
F_38 (t, n, &core->task_queue, list)
if ( V_4 == V_112 ) {
F_8 ( & V_112 -> V_45 ) ;
break;
}
F_13 ( & V_76 -> V_77 , V_49 ) ;
F_43 ( & V_76 -> V_113 ) ;
if ( V_4 == V_112 )
return V_114 ;
}
for ( V_85 = 0 ; V_85 < 5 ; V_85 ++ ) {
F_5 ( L_6 , V_115 , V_4 ) ;
V_87 = V_110 -> V_96 -> V_116 ( V_4 ) ;
F_11 ( & V_4 -> V_117 , V_49 ) ;
if ( V_4 -> V_118 & V_119 ) {
F_13 ( & V_4 -> V_117 , V_49 ) ;
F_5 ( L_7 , V_115 ,
V_4 ) ;
return V_120 ;
}
F_13 ( & V_4 -> V_117 , V_49 ) ;
if ( V_87 == V_121 ) {
F_5 ( L_8 ,
V_115 , V_4 ) ;
return V_122 ;
} else if ( V_110 -> V_96 -> V_123 ) {
F_5 ( L_9 ,
V_115 , V_4 ) ;
V_87 = V_110 -> V_96 -> V_123 ( V_4 ) ;
switch ( V_87 ) {
case V_124 :
F_5 ( L_10 ,
V_115 , V_4 ) ;
return V_125 ;
case V_121 :
F_5 ( L_11 ,
V_115 , V_4 ) ;
return V_126 ;
case V_127 :
F_5 ( L_12 ,
V_115 , V_4 ) ;
return V_128 ;
}
}
}
return V_87 ;
}
static int F_44 ( struct V_47 * V_33 , struct V_1 * V_54 )
{
int V_87 = V_127 ;
struct V_56 V_57 ;
struct V_84 * V_85 =
F_25 ( V_33 -> V_34 -> V_35 -> V_76 . V_111 -> V_86 ) ;
F_17 ( V_54 -> V_62 -> V_57 , & V_57 ) ;
F_5 ( L_13 ,
F_45 ( V_33 -> V_129 ) ,
V_54 -> V_62 -> V_57 ) ;
if ( V_85 -> V_96 -> V_130 )
V_87 = V_85 -> V_96 -> V_130 ( V_33 , V_57 . V_56 ) ;
if ( V_87 == V_127 ) {
if ( V_85 -> V_96 -> V_131 )
V_87 = V_85 -> V_96 -> V_131 ( V_33 , V_57 . V_56 ) ;
}
if ( V_87 == V_127 ) {
if ( V_85 -> V_96 -> V_132 )
V_87 = V_85 -> V_96 -> V_132 ( V_33 , V_57 . V_56 ) ;
}
return V_87 ;
}
static int F_46 ( struct V_47 * V_33 )
{
int V_87 = V_127 ;
struct V_84 * V_85 =
F_25 ( V_33 -> V_34 -> V_35 -> V_76 . V_111 -> V_86 ) ;
F_5 ( L_14 ,
F_45 ( V_33 -> V_129 ) ) ;
if ( V_85 -> V_96 -> V_133 )
V_87 = V_85 -> V_96 -> V_133 ( V_33 ) ;
return V_87 ;
}
struct V_134 * F_47 ( struct V_47 * V_33 )
{
struct V_48 * V_35 = V_33 -> V_34 -> V_35 ;
struct V_134 * V_135 ;
unsigned long V_49 ;
F_48 ( ! V_33 -> V_135 ) ;
F_11 ( & V_35 -> V_136 , V_49 ) ;
V_135 = V_33 -> V_135 ;
F_49 ( & V_135 -> V_33 ) ;
F_13 ( & V_35 -> V_136 , V_49 ) ;
return V_135 ;
}
int F_50 ( struct V_1 * V_54 )
{
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_84 * V_85 =
F_25 ( V_33 -> V_34 -> V_35 -> V_76 . V_111 -> V_86 ) ;
struct V_56 V_57 ;
int V_87 ;
F_17 ( V_54 -> V_62 -> V_57 , & V_57 ) ;
if ( ! V_85 -> V_96 -> V_132 )
return V_137 ;
V_87 = V_85 -> V_96 -> V_132 ( V_33 , V_57 . V_56 ) ;
if ( V_87 == V_124 || V_87 == V_121 )
return V_138 ;
return V_137 ;
}
int F_51 ( struct V_1 * V_54 )
{
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_134 * V_135 = F_47 ( V_33 ) ;
int V_87 ;
V_87 = F_52 ( V_135 , 1 ) ;
if ( V_87 )
F_5 ( L_15 ,
F_53 ( & V_135 -> V_33 . V_139 ) ,
V_87 ) ;
F_54 ( V_135 ) ;
if ( V_87 == V_124 || V_87 == V_121 )
return V_138 ;
return V_137 ;
}
static int F_55 ( struct V_1 * V_54 )
{
int V_87 ;
struct V_82 * V_111 = V_54 -> V_62 -> V_83 ;
if ( ! V_111 -> V_140 -> V_141 )
goto V_142;
V_87 = V_111 -> V_140 -> V_141 ( V_54 ) ;
if ( V_87 == V_138 )
return V_87 ;
V_142:
if ( V_111 -> V_140 -> V_143 )
return V_111 -> V_140 -> V_143 ( V_54 ) ;
return V_137 ;
}
static void F_56 ( struct V_82 * V_111 , struct V_102 * V_144 )
{
struct V_1 * V_54 , * V_105 ;
enum V_109 V_87 = V_120 ;
int V_145 , V_146 ;
struct V_84 * V_85 = F_25 ( V_111 -> V_86 ) ;
unsigned long V_49 ;
struct V_48 * V_35 = F_32 ( V_111 ) ;
F_21 ( V_147 ) ;
F_38 (cmd, n, work_q, eh_entry) {
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_3 * V_4 ;
F_11 ( & V_33 -> V_50 , V_49 ) ;
V_4 = F_33 ( V_54 ) ;
F_13 ( & V_33 -> V_50 , V_49 ) ;
if ( ! V_4 )
F_36 ( & V_54 -> V_100 , & V_147 ) ;
}
V_148:
F_38 (cmd, n, work_q, eh_entry) {
struct V_3 * V_4 = F_33 ( V_54 ) ;
F_8 ( & V_54 -> V_100 ) ;
F_11 ( & V_4 -> V_117 , V_49 ) ;
V_146 = V_4 -> V_118 & V_149 ;
F_13 ( & V_4 -> V_117 , V_49 ) ;
if ( V_146 ) {
F_5 ( L_16 ,
V_115 , V_4 ) ;
goto V_150;
}
F_5 ( L_17 , V_4 ) ;
V_87 = F_41 ( V_4 ) ;
V_54 -> V_151 = 0 ;
switch ( V_87 ) {
case V_114 :
F_5 ( L_18 ,
V_115 , V_4 ,
V_54 -> V_152 ? L_19 : L_20 ) ;
if ( V_54 -> V_152 )
V_54 -> V_152 -- ;
F_31 ( V_54 ) ;
continue;
case V_120 :
F_5 ( L_7 , V_115 ,
V_4 ) ;
F_35 ( V_54 ) ;
continue;
case V_122 :
F_5 ( L_8 ,
V_115 , V_4 ) ;
F_35 ( V_54 ) ;
continue;
case V_125 :
F_5 ( L_21 , V_4 ) ;
V_150:
V_145 = F_44 ( V_4 -> V_33 , V_54 ) ;
if ( V_145 == V_121 ) {
F_5 ( L_22
L_23 ,
F_45 ( V_4 -> V_33 ) ,
V_54 -> V_62 -> V_57 ) ;
F_35 ( V_54 ) ;
F_37 ( V_144 , V_54 ) ;
goto V_148;
}
case V_126 :
case V_128 :
F_5 ( L_24 ,
V_4 ) ;
V_145 = F_46 ( V_4 -> V_33 ) ;
if ( V_145 == V_121 ||
V_145 == - V_153 ) {
struct V_47 * V_33 = V_4 -> V_33 ;
F_5 ( L_25 ,
F_45 ( V_4 -> V_33 -> V_129 ) ) ;
F_31 ( V_54 ) ;
F_39 ( V_144 , V_33 ) ;
goto V_148;
}
F_55 ( V_54 ) ;
if ( V_85 -> V_96 -> V_154 ) {
struct V_108 * V_34 = V_4 -> V_33 -> V_34 ;
F_5 ( L_26 ,
V_34 -> V_155 ) ;
V_87 = V_85 -> V_96 -> V_154 ( V_34 ) ;
if ( V_87 == V_121 ) {
F_5 ( L_27
L_28 , V_34 -> V_155 ) ;
F_31 ( V_54 ) ;
F_40 ( V_144 ,
V_34 ) ;
goto V_148;
}
}
if ( V_85 -> V_96 -> V_156 ) {
F_5 ( L_29 ) ;
V_87 = V_85 -> V_96 -> V_156 ( V_35 ) ;
if ( V_87 == V_121 ) {
F_5 ( L_30
L_28 ) ;
F_31 ( V_54 ) ;
goto V_157;
}
}
F_5 ( L_31
L_32 ,
F_45 ( V_4 -> V_33 -> V_129 ) ,
V_54 -> V_62 -> V_57 ) ;
F_31 ( V_54 ) ;
goto V_157;
}
}
V_158:
F_57 ( & V_147 , V_144 ) ;
F_58 ( & V_35 -> V_101 , V_144 ) ;
return;
V_157:
F_5 ( L_33 , V_115 ) ;
F_38 (cmd, n, work_q, eh_entry)
F_31 ( V_54 ) ;
goto V_158;
}
void F_59 ( struct V_82 * V_111 )
{
struct V_48 * V_35 = F_32 ( V_111 ) ;
unsigned long V_49 ;
F_21 ( V_159 ) ;
F_11 ( V_111 -> V_160 , V_49 ) ;
F_60 ( & V_111 -> V_161 , & V_159 ) ;
V_111 -> V_162 = 0 ;
F_13 ( V_111 -> V_160 , V_49 ) ;
F_5 ( L_34 ,
V_115 , V_111 -> V_163 , V_111 -> V_164 ) ;
F_61 ( V_51 , & V_35 -> V_52 ) ;
F_56 ( V_111 , & V_159 ) ;
F_62 ( V_51 , & V_35 -> V_52 ) ;
if ( F_63 ( & V_159 ) )
goto V_158;
F_64 ( V_111 , & V_159 , & V_35 -> V_99 ) ;
if ( ! F_65 ( & V_159 , & V_35 -> V_99 ) )
F_66 ( V_111 , & V_159 , & V_35 -> V_99 ) ;
V_158:
if ( V_35 -> V_95 > 1 )
F_23 ( V_35 -> V_76 . V_81 ) ;
F_67 ( V_111 ) ;
F_68 ( & V_35 -> V_99 ) ;
F_5 ( L_35 ,
V_115 , V_111 -> V_163 , V_111 -> V_164 ) ;
}
enum V_165 F_69 ( struct V_1 * V_54 )
{
F_70 ( V_166 , V_54 , L_36 , V_54 ) ;
return V_167 ;
}
int F_71 ( struct V_168 * V_169 , int V_54 , void T_2 * V_170 )
{
struct V_47 * V_33 = F_72 ( V_169 ) ;
if ( F_27 ( V_33 ) )
return F_73 ( V_33 -> V_90 . V_91 , V_169 , V_54 , V_170 ) ;
return - V_171 ;
}
struct V_47 * F_74 ( struct V_172 * V_173 )
{
struct V_82 * V_111 = F_75 ( V_173 -> V_33 . V_174 ) ;
struct V_48 * V_35 = F_32 ( V_111 ) ;
struct V_47 * V_175 = NULL ;
int V_85 ;
unsigned long V_49 ;
F_11 ( & V_35 -> V_136 , V_49 ) ;
for ( V_85 = 0 ; V_85 < V_35 -> V_176 ; V_85 ++ ) {
struct V_108 * V_34 = V_35 -> V_177 [ V_85 ] ;
struct V_47 * V_33 ;
F_76 ( & V_34 -> V_178 ) ;
F_77 (dev, &port->dev_list, dev_list_node) {
if ( V_173 == V_33 -> V_173 ) {
V_175 = V_33 ;
F_78 ( & V_34 -> V_178 ) ;
goto V_179;
}
}
F_78 ( & V_34 -> V_178 ) ;
}
V_179:
F_13 ( & V_35 -> V_136 , V_49 ) ;
return V_175 ;
}
int F_79 ( struct V_180 * V_181 )
{
struct V_172 * V_173 = F_80 ( V_181 -> V_33 . V_174 ) ;
struct V_47 * V_175 = F_74 ( V_173 ) ;
if ( ! V_175 )
return - V_153 ;
F_81 ( & V_175 -> V_182 ) ;
V_181 -> V_183 = V_175 ;
return 0 ;
}
int F_82 ( struct V_168 * V_184 )
{
struct V_47 * V_33 = F_72 ( V_184 ) ;
struct V_48 * V_74 ;
F_48 ( V_33 -> V_173 -> V_185 . V_186 != V_187 ) ;
if ( F_27 ( V_33 ) ) {
F_83 ( V_184 , V_33 -> V_90 . V_91 ) ;
return 0 ;
}
V_74 = V_33 -> V_34 -> V_35 ;
F_84 ( V_184 ) ;
if ( V_184 -> V_188 ) {
F_85 ( V_184 , V_189 ) ;
F_86 ( V_184 , V_190 ) ;
} else {
F_5 ( L_37
L_38 , F_45 ( V_33 -> V_129 ) ,
V_184 -> V_57 ) ;
V_184 -> V_188 = 0 ;
F_85 ( V_184 , 0 ) ;
F_87 ( V_184 , 1 ) ;
}
V_184 -> V_191 = 1 ;
return 0 ;
}
int F_88 ( struct V_168 * V_169 , int V_192 , int V_193 )
{
struct V_47 * V_33 = F_72 ( V_169 ) ;
if ( F_27 ( V_33 ) )
return F_89 ( V_33 -> V_90 . V_91 , V_169 , V_192 ,
V_193 ) ;
switch ( V_193 ) {
case V_194 :
case V_195 :
if ( ! V_169 -> V_188 )
V_192 = 1 ;
F_90 ( V_169 , F_91 ( V_169 ) , V_192 ) ;
break;
case V_196 :
F_92 ( V_169 , V_192 ) ;
break;
default:
return - V_197 ;
}
return V_192 ;
}
int F_93 ( struct V_168 * V_184 , int V_198 )
{
struct V_47 * V_33 = F_72 ( V_184 ) ;
if ( F_27 ( V_33 ) )
return - V_171 ;
if ( ! V_184 -> V_188 )
return 0 ;
F_87 ( V_184 , 1 ) ;
F_85 ( V_184 , V_198 ) ;
F_86 ( V_184 , V_184 -> V_199 ) ;
return V_198 ;
}
int F_94 ( struct V_168 * V_184 ,
struct V_200 * V_201 ,
T_3 V_202 , int * V_203 )
{
V_203 [ 0 ] = 255 ;
V_203 [ 1 ] = 63 ;
F_95 ( V_202 , 255 * 63 ) ;
V_203 [ 2 ] = V_202 ;
return 0 ;
}
static void F_96 ( struct V_48 * V_74 )
{
struct V_75 * V_76 = & V_74 -> V_76 ;
unsigned long V_49 ;
F_21 ( V_204 ) ;
int V_205 ;
int V_87 ;
struct V_84 * V_85 = F_25 ( V_76 -> V_111 -> V_86 ) ;
F_42 ( & V_76 -> V_113 ) ;
F_11 ( & V_76 -> V_77 , V_49 ) ;
while ( ! F_97 () &&
! F_63 ( & V_76 -> V_80 ) &&
! F_12 ( V_51 , & V_74 -> V_52 ) ) {
V_205 = V_74 -> V_78 - V_76 -> V_79 ;
if ( V_205 >= 0 ) {
V_205 = V_76 -> V_79 ;
F_60 ( & V_76 -> V_80 , & V_204 ) ;
} else {
struct V_102 * V_206 , * V_105 ;
V_205 = V_74 -> V_78 ;
F_98 (a, n, &core->task_queue) {
F_36 ( V_206 , & V_204 ) ;
if ( -- V_205 == 0 )
break;
}
V_205 = V_74 -> V_78 ;
}
V_76 -> V_79 -= V_205 ;
F_13 ( & V_76 -> V_77 , V_49 ) ;
{
struct V_3 * V_4 = F_99 ( V_204 . V_207 ,
struct V_3 ,
V_45 ) ;
F_8 ( & V_204 ) ;
V_87 = V_85 -> V_96 -> V_97 ( V_4 , V_205 ,
V_208 ) ;
if ( F_14 ( V_87 ) )
F_100 ( & V_204 , V_4 -> V_45 . V_209 , & V_4 -> V_45 ) ;
}
F_11 ( & V_76 -> V_77 , V_49 ) ;
if ( V_87 ) {
F_60 ( & V_204 , & V_76 -> V_80 ) ;
V_76 -> V_79 += V_205 ;
}
}
F_13 ( & V_76 -> V_77 , V_49 ) ;
F_43 ( & V_76 -> V_113 ) ;
}
static int F_101 ( void * V_210 )
{
struct V_48 * V_74 = V_210 ;
while ( 1 ) {
F_102 ( V_211 ) ;
F_103 () ;
F_96 ( V_74 ) ;
if ( F_97 () )
break;
}
return 0 ;
}
int F_104 ( struct V_48 * V_74 )
{
struct V_75 * V_76 = & V_74 -> V_76 ;
F_105 ( & V_76 -> V_77 ) ;
F_106 ( & V_76 -> V_113 ) ;
V_76 -> V_79 = 0 ;
F_107 ( & V_76 -> V_80 ) ;
V_76 -> V_81 = F_108 ( F_101 , V_74 ,
L_39 , V_76 -> V_111 -> V_212 ) ;
if ( F_109 ( V_76 -> V_81 ) )
return F_110 ( V_76 -> V_81 ) ;
return 0 ;
}
void F_111 ( struct V_48 * V_74 )
{
unsigned long V_49 ;
struct V_75 * V_76 = & V_74 -> V_76 ;
struct V_3 * V_4 , * V_105 ;
F_112 ( V_76 -> V_81 ) ;
if ( ! F_63 ( & V_76 -> V_80 ) )
F_5 ( L_40 ,
F_45 ( V_74 -> V_129 ) ) ;
F_11 ( & V_76 -> V_77 , V_49 ) ;
F_38 (task, n, &core->task_queue, list) {
struct V_1 * V_54 = V_4 -> V_46 ;
F_8 ( & V_4 -> V_45 ) ;
F_7 ( V_54 , NULL ) ;
F_9 ( V_4 ) ;
V_54 -> V_44 = V_38 << 16 ;
V_54 -> V_53 ( V_54 ) ;
}
F_13 ( & V_76 -> V_77 , V_49 ) ;
}
void F_113 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_46 ;
if ( ! V_2 ) {
if ( ! F_114 ( & V_4 -> V_213 ) )
return;
V_4 -> V_213 . V_214 ( V_4 -> V_213 . V_215 ) ;
return;
}
if ( F_27 ( V_4 -> V_33 ) ) {
F_115 ( V_4 ) ;
} else {
struct V_216 * V_204 = V_2 -> V_62 -> V_216 ;
unsigned long V_49 ;
F_11 ( V_204 -> V_217 , V_49 ) ;
F_116 ( V_2 -> V_218 ) ;
F_13 ( V_204 -> V_217 , V_49 ) ;
F_117 ( V_2 -> V_62 -> V_83 ) ;
}
}
void F_118 ( struct V_180 * V_181 )
{
struct V_47 * V_175 = V_181 -> V_183 ;
if ( ! V_175 )
return;
V_181 -> V_183 = NULL ;
F_119 ( V_175 ) ;
}
static void F_120 ( T_4 * V_129 , const char * V_219 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_220 ; V_85 ++ ) {
T_4 V_221 , V_222 ;
if ( ! * V_219 )
break;
V_221 = isdigit ( * V_219 ) ? * V_219 - '0' : toupper ( * V_219 ) - 'A' + 10 ;
V_219 ++ ;
V_222 = isdigit ( * V_219 ) ? * V_219 - '0' : toupper ( * V_219 ) - 'A' + 10 ;
V_219 ++ ;
V_129 [ V_85 ] = ( V_221 << 4 ) | V_222 ;
}
}
int F_121 ( struct V_82 * V_111 , T_4 * V_223 )
{
int V_87 ;
const struct V_224 * V_225 ;
V_87 = F_122 ( & V_225 , L_41 , & V_111 -> V_226 ) ;
if ( V_87 )
return V_87 ;
if ( V_225 -> V_227 < V_228 ) {
V_87 = - V_153 ;
goto V_158;
}
F_120 ( V_223 , V_225 -> V_215 ) ;
V_158:
F_123 ( V_225 ) ;
return V_87 ;
}
