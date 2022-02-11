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
static int F_22 ( struct V_6 * V_50 ,
void (* V_49)( struct V_6 * ) )
__releases( V_81 -> V_82 )
__acquires( V_37 -> V_83 . V_84 -> V_85 )
__releases( V_37 -> V_83 . V_84 -> V_85 )
__acquires( V_81 -> V_82 )
{
int V_86 = 0 ;
struct V_51 * V_37 = F_23 ( V_50 ) ;
struct V_87 * V_81 = V_50 -> V_59 -> V_81 ;
struct V_88 * V_89 = F_24 ( V_81 -> V_90 ) ;
F_25 ( V_81 -> V_82 ) ;
{
struct V_71 * V_72 = V_37 -> V_38 -> V_39 ;
struct V_1 * V_2 ;
if ( V_37 -> V_91 ) {
V_50 -> V_48 = V_30 << 16 ;
V_49 ( V_50 ) ;
goto V_92;
}
if ( F_26 ( V_37 ) ) {
unsigned long V_75 ;
F_18 ( V_37 -> V_83 . V_84 -> V_85 , V_75 ) ;
V_86 = F_27 ( V_50 , V_37 -> V_83 . V_84 ) ;
F_19 ( V_37 -> V_83 . V_84 -> V_85 , V_75 ) ;
goto V_92;
}
V_86 = - V_93 ;
V_2 = F_11 ( V_50 , V_37 , V_94 ) ;
if ( ! V_2 )
goto V_92;
V_50 -> V_49 = V_49 ;
if ( V_72 -> V_95 < 2 )
V_86 = V_89 -> V_96 -> V_97 ( V_2 , 1 , V_94 ) ;
else
V_86 = F_16 ( V_2 ) ;
if ( V_86 ) {
F_3 ( L_5 , V_86 ) ;
F_10 ( V_50 , NULL ) ;
F_5 ( V_2 ) ;
if ( V_86 == - V_27 ) {
V_50 -> V_48 = V_28 << 16 ;
V_86 = 0 ;
V_49 ( V_50 ) ;
}
goto V_92;
}
}
V_92:
F_28 ( V_81 -> V_82 ) ;
return V_86 ;
}
static void F_29 ( struct V_6 * V_50 )
{
struct V_1 * V_2 = F_30 ( V_50 ) ;
struct V_71 * V_72 = F_31 ( V_50 -> V_59 -> V_81 ) ;
V_2 -> V_11 &= ~ V_12 ;
V_2 -> V_70 ( V_2 ) ;
F_32 ( V_50 , & V_72 -> V_98 ) ;
}
static void F_33 ( struct V_99 * V_100 , struct V_6 * V_101 )
{
struct V_6 * V_50 , * V_102 ;
F_34 (cmd, n, error_q, eh_entry) {
if ( V_50 -> V_59 -> V_103 == V_101 -> V_59 -> V_103 &&
V_50 -> V_59 -> V_54 == V_101 -> V_59 -> V_54 )
F_29 ( V_50 ) ;
}
}
static void F_35 ( struct V_99 * V_100 ,
struct V_51 * V_37 )
{
struct V_6 * V_50 , * V_102 ;
F_34 (cmd, n, error_q, eh_entry) {
struct V_51 * V_104 = F_23 ( V_50 ) ;
if ( V_104 == V_37 )
F_29 ( V_50 ) ;
}
}
static void F_36 ( struct V_99 * V_100 ,
struct V_105 * V_38 )
{
struct V_6 * V_50 , * V_102 ;
F_34 (cmd, n, error_q, eh_entry) {
struct V_51 * V_37 = F_23 ( V_50 ) ;
struct V_105 * V_104 = V_37 -> V_38 ;
if ( V_104 == V_38 )
F_29 ( V_50 ) ;
}
}
static enum V_106 F_37 ( struct V_1 * V_2 )
{
struct V_71 * V_39 = V_2 -> V_37 -> V_38 -> V_39 ;
unsigned long V_75 ;
int V_89 , V_86 ;
struct V_88 * V_107 =
F_24 ( V_2 -> V_37 -> V_38 -> V_39 -> V_74 . V_108 -> V_90 ) ;
if ( V_39 -> V_95 > 1 ) {
struct V_73 * V_74 = & V_39 -> V_74 ;
struct V_1 * V_109 , * V_102 ;
F_18 ( & V_74 -> V_76 , V_75 ) ;
F_34 (t, n, &core->task_queue, list) {
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
for ( V_89 = 0 ; V_89 < 5 ; V_89 ++ ) {
F_3 ( L_8 , V_110 , V_2 ) ;
V_86 = V_107 -> V_96 -> V_112 ( V_2 ) ;
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
} else if ( V_107 -> V_96 -> V_117 ) {
F_3 ( L_11 ,
V_110 , V_2 ) ;
V_86 = V_107 -> V_96 -> V_117 ( V_2 ) ;
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
static int F_38 ( struct V_51 * V_37 , struct V_6 * V_50 )
{
int V_86 = V_121 ;
struct V_53 V_54 ;
struct V_88 * V_89 =
F_24 ( V_37 -> V_38 -> V_39 -> V_74 . V_108 -> V_90 ) ;
F_13 ( V_50 -> V_59 -> V_54 , & V_54 ) ;
F_3 ( L_15 ,
F_39 ( V_37 -> V_123 ) ,
V_50 -> V_59 -> V_54 ) ;
if ( V_89 -> V_96 -> V_124 )
V_86 = V_89 -> V_96 -> V_124 ( V_37 , V_54 . V_53 ) ;
if ( V_86 == V_121 ) {
if ( V_89 -> V_96 -> V_125 )
V_86 = V_89 -> V_96 -> V_125 ( V_37 , V_54 . V_53 ) ;
}
if ( V_86 == V_121 ) {
if ( V_89 -> V_96 -> V_126 )
V_86 = V_89 -> V_96 -> V_126 ( V_37 , V_54 . V_53 ) ;
}
return V_86 ;
}
static int F_40 ( struct V_51 * V_37 )
{
int V_86 = V_121 ;
struct V_88 * V_89 =
F_24 ( V_37 -> V_38 -> V_39 -> V_74 . V_108 -> V_90 ) ;
F_3 ( L_16 ,
F_39 ( V_37 -> V_123 ) ) ;
if ( V_89 -> V_96 -> V_127 )
V_86 = V_89 -> V_96 -> V_127 ( V_37 ) ;
return V_86 ;
}
struct V_128 * F_41 ( struct V_51 * V_37 )
{
struct V_51 * V_129 = V_37 -> V_130 ;
struct V_131 * V_132 = NULL ;
int V_89 ;
if ( ! V_129 )
return V_37 -> V_38 -> V_133 ;
for ( V_89 = 0 ; V_89 < V_129 -> V_134 . V_135 ; V_89 ++ )
if ( ! memcmp ( V_37 -> V_123 ,
V_129 -> V_134 . V_131 [ V_89 ] . V_136 ,
V_137 ) ) {
V_132 = & V_129 -> V_134 . V_131 [ V_89 ] ;
break;
}
F_42 ( ! V_132 ) ;
return V_132 -> V_133 ;
}
int F_43 ( struct V_6 * V_50 )
{
struct V_51 * V_37 = F_23 ( V_50 ) ;
struct V_88 * V_89 =
F_24 ( V_37 -> V_38 -> V_39 -> V_74 . V_108 -> V_90 ) ;
struct V_53 V_54 ;
int V_86 ;
F_13 ( V_50 -> V_59 -> V_54 , & V_54 ) ;
if ( ! V_89 -> V_96 -> V_126 )
return V_138 ;
V_86 = V_89 -> V_96 -> V_126 ( V_37 , V_54 . V_53 ) ;
if ( V_86 == V_118 || V_86 == V_116 )
return V_139 ;
return V_138 ;
}
int F_44 ( struct V_6 * V_50 )
{
struct V_51 * V_37 = F_23 ( V_50 ) ;
struct V_128 * V_133 = F_41 ( V_37 ) ;
int V_86 ;
V_86 = F_45 ( V_133 , 1 ) ;
if ( V_86 )
F_3 ( L_17 ,
F_46 ( & V_133 -> V_37 . V_140 ) ,
V_86 ) ;
if ( V_86 == V_118 || V_86 == V_116 )
return V_139 ;
return V_138 ;
}
static int F_47 ( struct V_6 * V_50 )
{
int V_86 ;
struct V_87 * V_108 = V_50 -> V_59 -> V_81 ;
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
static int F_48 ( struct V_87 * V_108 ,
struct V_99 * V_145 ,
struct V_99 * V_146 )
{
struct V_6 * V_50 , * V_102 ;
enum V_106 V_86 = V_115 ;
int V_147 , V_148 ;
struct V_88 * V_89 = F_24 ( V_108 -> V_90 ) ;
unsigned long V_75 ;
struct V_71 * V_39 = F_31 ( V_108 ) ;
V_149:
F_34 (cmd, n, work_q, eh_entry) {
struct V_1 * V_2 = F_30 ( V_50 ) ;
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
V_86 = F_37 ( V_2 ) ;
V_50 -> V_153 = 0 ;
switch ( V_86 ) {
case V_115 :
F_3 ( L_9 , V_110 ,
V_2 ) ;
F_29 ( V_50 ) ;
continue;
case V_111 :
F_3 ( L_10 ,
V_110 , V_2 ) ;
F_29 ( V_50 ) ;
continue;
case V_119 :
F_3 ( L_20 , V_2 ) ;
V_152:
V_147 = F_38 ( V_2 -> V_37 , V_50 ) ;
if ( V_147 == V_116 ) {
F_3 ( L_21
L_22 ,
F_39 ( V_2 -> V_37 ) ,
V_50 -> V_59 -> V_54 ) ;
F_29 ( V_50 ) ;
F_33 ( V_145 , V_50 ) ;
goto V_149;
}
case V_120 :
case V_122 :
F_3 ( L_23 ,
V_2 ) ;
V_147 = F_40 ( V_2 -> V_37 ) ;
if ( V_147 == V_116 ) {
struct V_51 * V_37 = V_2 -> V_37 ;
F_3 ( L_24 ,
F_39 ( V_2 -> V_37 -> V_123 ) ) ;
F_29 ( V_50 ) ;
F_35 ( V_145 , V_37 ) ;
goto V_149;
}
F_47 ( V_50 ) ;
if ( V_89 -> V_96 -> V_154 ) {
struct V_105 * V_38 = V_2 -> V_37 -> V_38 ;
F_3 ( L_25 ,
V_38 -> V_155 ) ;
V_86 = V_89 -> V_96 -> V_154 ( V_38 ) ;
if ( V_86 == V_116 ) {
F_3 ( L_26
L_27 , V_38 -> V_155 ) ;
F_29 ( V_50 ) ;
F_36 ( V_145 ,
V_38 ) ;
goto V_149;
}
}
if ( V_89 -> V_96 -> V_156 ) {
F_3 ( L_28 ) ;
V_86 = V_89 -> V_96 -> V_156 ( V_39 ) ;
if ( V_86 == V_116 ) {
F_3 ( L_29
L_27 ) ;
F_29 ( V_50 ) ;
goto V_157;
}
}
F_3 ( L_30
L_31 ,
F_39 ( V_2 -> V_37 -> V_123 ) ,
V_50 -> V_59 -> V_54 ) ;
F_29 ( V_50 ) ;
goto V_157;
}
}
return F_49 ( V_145 ) ;
V_157:
F_3 ( L_32 , V_110 ) ;
F_34 (cmd, n, work_q, eh_entry)
F_29 ( V_50 ) ;
return F_49 ( V_145 ) ;
}
void F_50 ( struct V_87 * V_108 )
{
struct V_71 * V_39 = F_31 ( V_108 ) ;
unsigned long V_75 ;
F_17 ( V_158 ) ;
F_18 ( V_108 -> V_82 , V_75 ) ;
F_51 ( & V_108 -> V_159 , & V_158 ) ;
V_108 -> V_160 = 0 ;
F_19 ( V_108 -> V_82 , V_75 ) ;
F_3 ( L_33 , V_110 ) ;
if ( F_48 ( V_108 , & V_158 , & V_39 -> V_98 ) )
goto V_92;
if ( ! F_52 ( V_108 , & V_158 , & V_39 -> V_98 ) )
if ( ! F_53 ( & V_158 , & V_39 -> V_98 ) )
F_54 ( V_108 , & V_158 , & V_39 -> V_98 ) ;
V_92:
F_55 ( V_108 ) ;
F_56 ( & V_39 -> V_98 ) ;
F_3 ( L_34 , V_110 ) ;
return;
}
enum V_161 F_57 ( struct V_6 * V_50 )
{
struct V_1 * V_2 = F_30 ( V_50 ) ;
unsigned long V_75 ;
enum V_161 V_162 ;
if ( F_58 ( V_50 , V_2 , & V_162 ) )
return V_162 ;
if ( ! V_2 ) {
V_50 -> V_163 -> V_164 /= 2 ;
F_3 ( L_35 ,
V_50 , V_2 , ( V_50 -> V_163 -> V_164 ?
L_36 : L_37 ) ) ;
if ( ! V_50 -> V_163 -> V_164 )
return V_165 ;
return V_166 ;
}
F_18 ( & V_2 -> V_113 , V_75 ) ;
F_42 ( V_2 -> V_11 & V_12 ) ;
if ( V_2 -> V_11 & V_114 ) {
F_19 ( & V_2 -> V_113 , V_75 ) ;
F_3 ( L_38
L_39 , V_50 , V_2 ) ;
return V_167 ;
}
if ( ! ( V_2 -> V_11 & V_168 ) ) {
F_19 ( & V_2 -> V_113 , V_75 ) ;
F_3 ( L_40
L_41 ,
V_50 , V_2 ) ;
return V_166 ;
}
V_2 -> V_11 |= V_12 ;
F_19 ( & V_2 -> V_113 , V_75 ) ;
F_3 ( L_42 ,
V_50 , V_2 ) ;
return V_165 ;
}
int F_59 ( struct V_169 * V_170 , int V_50 , void T_2 * V_171 )
{
struct V_51 * V_37 = F_60 ( V_170 ) ;
if ( F_26 ( V_37 ) )
return F_61 ( V_37 -> V_83 . V_84 , V_170 , V_50 , V_171 ) ;
return - V_172 ;
}
struct V_51 * F_62 ( struct V_173 * V_174 )
{
struct V_87 * V_108 = F_63 ( V_174 -> V_37 . V_130 ) ;
struct V_71 * V_39 = F_31 ( V_108 ) ;
struct V_51 * V_175 = NULL ;
int V_89 ;
unsigned long V_75 ;
F_18 ( & V_39 -> V_176 , V_75 ) ;
for ( V_89 = 0 ; V_89 < V_39 -> V_135 ; V_89 ++ ) {
struct V_105 * V_38 = V_39 -> V_177 [ V_89 ] ;
struct V_51 * V_37 ;
F_64 ( & V_38 -> V_178 ) ;
F_65 (dev, &port->dev_list, dev_list_node) {
if ( V_174 == V_37 -> V_174 ) {
V_175 = V_37 ;
F_66 ( & V_38 -> V_178 ) ;
goto V_179;
}
}
F_66 ( & V_38 -> V_178 ) ;
}
V_179:
F_19 ( & V_39 -> V_176 , V_75 ) ;
return V_175 ;
}
static inline struct V_51 * F_67 ( struct V_180 * V_181 )
{
struct V_173 * V_174 = F_68 ( V_181 -> V_37 . V_130 ) ;
return F_62 ( V_174 ) ;
}
int F_69 ( struct V_180 * V_181 )
{
struct V_51 * V_175 = F_67 ( V_181 ) ;
int V_86 ;
if ( ! V_175 )
return - V_182 ;
if ( F_26 ( V_175 ) ) {
V_86 = F_70 ( V_175 , V_181 ) ;
if ( V_86 )
return V_86 ;
}
V_181 -> V_183 = V_175 ;
return 0 ;
}
int F_71 ( struct V_169 * V_184 )
{
struct V_51 * V_37 = F_60 ( V_184 ) ;
struct V_71 * V_72 ;
F_42 ( V_37 -> V_174 -> V_185 . V_186 != V_187 ) ;
if ( F_26 ( V_37 ) ) {
F_72 ( V_184 , V_37 -> V_83 . V_84 ) ;
return 0 ;
}
V_72 = V_37 -> V_38 -> V_39 ;
F_73 ( V_184 ) ;
if ( V_184 -> V_188 ) {
F_74 ( V_184 , V_189 ) ;
F_75 ( V_184 , V_190 ) ;
} else {
F_3 ( L_43
L_44 , F_39 ( V_37 -> V_123 ) ,
V_184 -> V_54 ) ;
V_184 -> V_188 = 0 ;
F_74 ( V_184 , 0 ) ;
F_76 ( V_184 , 1 ) ;
}
V_184 -> V_191 = 1 ;
return 0 ;
}
void F_77 ( struct V_169 * V_184 )
{
struct V_51 * V_37 = F_60 ( V_184 ) ;
if ( F_26 ( V_37 ) )
V_37 -> V_83 . V_84 -> V_192 . V_59 [ 0 ] . V_193 = V_194 ;
}
int F_78 ( struct V_169 * V_184 , int V_195 ,
int V_196 )
{
int V_86 = F_9 ( V_195 , V_197 ) ;
if ( V_196 != V_198 )
return - V_199 ;
if ( V_184 -> V_188 )
F_79 ( V_184 , F_80 ( V_184 ) ,
V_86 ) ;
else {
struct V_51 * V_37 = F_60 ( V_184 ) ;
F_81 ( L_45 ,
F_39 ( V_37 -> V_123 ) ,
V_184 -> V_54 ) ;
F_79 ( V_184 , 0 , 1 ) ;
V_86 = 1 ;
}
return V_86 ;
}
int F_82 ( struct V_169 * V_184 , int V_200 )
{
if ( ! V_184 -> V_188 )
return 0 ;
F_76 ( V_184 , 1 ) ;
F_74 ( V_184 , V_200 ) ;
F_75 ( V_184 , V_184 -> V_201 ) ;
return V_200 ;
}
int F_83 ( struct V_169 * V_184 ,
struct V_202 * V_203 ,
T_3 V_204 , int * V_205 )
{
V_205 [ 0 ] = 255 ;
V_205 [ 1 ] = 63 ;
F_84 ( V_204 , 255 * 63 ) ;
V_205 [ 2 ] = V_204 ;
return 0 ;
}
static void F_85 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = & V_72 -> V_74 ;
unsigned long V_75 ;
F_17 ( V_206 ) ;
int V_207 ;
int V_86 ;
struct V_88 * V_89 = F_24 ( V_74 -> V_108 -> V_90 ) ;
F_18 ( & V_74 -> V_76 , V_75 ) ;
while ( ! F_86 () &&
! F_49 ( & V_74 -> V_79 ) ) {
V_207 = V_72 -> V_77 - V_74 -> V_78 ;
if ( V_207 >= 0 ) {
V_207 = V_74 -> V_78 ;
F_51 ( & V_74 -> V_79 , & V_206 ) ;
} else {
struct V_99 * V_208 , * V_102 ;
V_207 = V_72 -> V_77 ;
F_87 (a, n, &core->task_queue) {
F_88 ( V_208 , & V_206 ) ;
if ( -- V_207 == 0 )
break;
}
V_207 = V_72 -> V_77 ;
}
V_74 -> V_78 -= V_207 ;
F_19 ( & V_74 -> V_76 , V_75 ) ;
{
struct V_1 * V_2 = F_89 ( V_206 . V_209 ,
struct V_1 ,
V_13 ) ;
F_4 ( & V_206 ) ;
V_86 = V_89 -> V_96 -> V_97 ( V_2 , V_207 ,
V_210 ) ;
if ( F_2 ( V_86 ) )
F_90 ( & V_206 , V_2 -> V_13 . V_211 , & V_2 -> V_13 ) ;
}
F_18 ( & V_74 -> V_76 , V_75 ) ;
if ( V_86 ) {
F_51 ( & V_206 , & V_74 -> V_79 ) ;
V_74 -> V_78 += V_207 ;
}
}
F_19 ( & V_74 -> V_76 , V_75 ) ;
}
static int F_91 ( void * V_212 )
{
struct V_71 * V_72 = V_212 ;
while ( 1 ) {
F_92 ( V_213 ) ;
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
L_46 , V_74 -> V_108 -> V_214 ) ;
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
if ( ! F_49 ( & V_74 -> V_79 ) )
F_3 ( L_47 ,
F_39 ( V_72 -> V_123 ) ) ;
F_18 ( & V_74 -> V_76 , V_75 ) ;
F_34 (task, n, &core->task_queue, list) {
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
struct V_88 * V_107 =
F_24 ( V_2 -> V_37 -> V_38 -> V_39 -> V_74 . V_108 -> V_90 ) ;
unsigned long V_75 ;
int V_86 ;
F_18 ( & V_2 -> V_113 , V_75 ) ;
if ( V_2 -> V_11 & V_12 ||
V_2 -> V_11 & V_114 ) {
F_19 ( & V_2 -> V_113 , V_75 ) ;
F_3 ( L_48 , V_110 ,
V_2 ) ;
return 0 ;
}
V_2 -> V_11 |= V_12 ;
F_19 ( & V_2 -> V_113 , V_75 ) ;
if ( ! V_107 -> V_96 -> V_112 )
return - V_182 ;
V_86 = V_107 -> V_96 -> V_112 ( V_2 ) ;
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
return - V_215 ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_7 ) {
if ( ! F_104 ( & V_2 -> V_216 ) )
return;
V_2 -> V_216 . V_217 ( V_2 -> V_216 . V_218 ) ;
return;
}
if ( F_26 ( V_2 -> V_37 ) ) {
F_105 ( V_2 ) ;
} else {
struct V_219 * V_206 = V_7 -> V_59 -> V_219 ;
unsigned long V_75 ;
F_18 ( V_206 -> V_220 , V_75 ) ;
F_106 ( V_7 -> V_163 ) ;
F_19 ( V_206 -> V_220 , V_75 ) ;
F_107 ( V_7 -> V_59 -> V_81 ) ;
}
}
int F_108 ( struct V_169 * V_184 )
{
struct V_51 * V_37 = F_60 ( V_184 ) ;
if ( F_26 ( V_37 ) )
return F_109 ( V_37 -> V_83 . V_84 ) ;
return 0 ;
}
void F_110 ( struct V_180 * V_181 )
{
struct V_51 * V_175 = F_67 ( V_181 ) ;
if ( ! V_175 )
return;
if ( F_26 ( V_175 ) )
F_111 ( V_175 -> V_83 . V_84 ) ;
return;
}
static void F_112 ( T_4 * V_123 , const char * V_221 )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < V_137 ; V_89 ++ ) {
T_4 V_222 , V_223 ;
if ( ! * V_221 )
break;
V_222 = isdigit ( * V_221 ) ? * V_221 - '0' : toupper ( * V_221 ) - 'A' + 10 ;
V_221 ++ ;
V_223 = isdigit ( * V_221 ) ? * V_221 - '0' : toupper ( * V_221 ) - 'A' + 10 ;
V_221 ++ ;
V_123 [ V_89 ] = ( V_222 << 4 ) | V_223 ;
}
}
int F_113 ( struct V_87 * V_108 , T_4 * V_224 )
{
int V_86 ;
const struct V_225 * V_226 ;
V_86 = F_114 ( & V_226 , L_49 , & V_108 -> V_227 ) ;
if ( V_86 )
return V_86 ;
if ( V_226 -> V_228 < V_229 ) {
V_86 = - V_182 ;
goto V_92;
}
F_112 ( V_224 , V_226 -> V_218 ) ;
V_92:
F_115 ( V_226 ) ;
return V_86 ;
}
