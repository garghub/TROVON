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
static void F_50 ( struct V_47 * V_33 )
{
struct V_48 * V_35 = V_33 -> V_34 -> V_35 ;
F_51 ( V_137 ) ;
if ( F_27 ( V_33 ) ) {
F_52 ( V_33 -> V_90 . V_91 ) ;
return;
}
V_138:
F_28 ( & V_35 -> V_92 ) ;
while ( F_12 ( V_139 , & V_33 -> V_52 ) ) {
F_53 ( & V_35 -> V_140 , & V_137 , V_141 ) ;
F_30 ( & V_35 -> V_92 ) ;
F_54 () ;
F_28 ( & V_35 -> V_92 ) ;
}
F_55 ( & V_35 -> V_140 , & V_137 ) ;
F_30 ( & V_35 -> V_92 ) ;
if ( F_56 ( V_35 -> V_76 . V_111 ) ) {
F_57 ( 10 ) ;
goto V_138;
}
}
static int F_58 ( struct V_47 * V_33 , int V_142 , int V_57 , int V_137 )
{
struct V_48 * V_35 = V_33 -> V_34 -> V_35 ;
int V_143 = 0 , V_144 = 100 ;
if ( F_27 ( V_33 ) ) {
F_59 ( V_33 ) ;
if ( V_137 )
F_60 ( V_33 ) ;
return V_145 ;
}
while ( ! V_143 && V_144 -- ) {
F_28 ( & V_35 -> V_92 ) ;
if ( ! F_12 ( V_139 , & V_33 -> V_52 ) &&
! F_12 ( V_142 , & V_33 -> V_52 ) ) {
V_143 = 1 ;
V_35 -> V_146 ++ ;
F_22 ( & V_33 -> V_147 . V_148 , & V_35 -> V_149 ) ;
F_61 ( V_139 , & V_33 -> V_52 ) ;
F_61 ( V_142 , & V_33 -> V_52 ) ;
F_17 ( V_57 , & V_33 -> V_147 . V_150 ) ;
F_62 ( V_35 -> V_76 . V_111 ) ;
}
F_30 ( & V_35 -> V_92 ) ;
if ( V_137 )
F_50 ( V_33 ) ;
if ( V_143 )
return V_145 ;
}
F_5 ( L_15 ,
V_142 == V_151 ? L_16 : L_17 ,
F_63 ( & V_33 -> V_152 -> V_33 ) ) ;
return V_153 ;
}
int F_64 ( struct V_1 * V_54 )
{
int V_87 ;
struct V_3 * V_4 = F_33 ( V_54 ) ;
struct V_82 * V_83 = V_54 -> V_62 -> V_83 ;
struct V_84 * V_85 = F_25 ( V_83 -> V_86 ) ;
if ( V_154 != V_83 -> V_155 )
return V_153 ;
if ( ! V_85 -> V_96 -> V_116 )
return V_153 ;
V_87 = V_85 -> V_96 -> V_116 ( V_4 ) ;
if ( V_87 == V_124 || V_87 == V_121 )
return V_145 ;
return V_153 ;
}
int F_65 ( struct V_1 * V_54 )
{
int V_87 ;
struct V_56 V_57 ;
struct V_82 * V_83 = V_54 -> V_62 -> V_83 ;
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_84 * V_85 = F_25 ( V_83 -> V_86 ) ;
if ( V_154 != V_83 -> V_155 )
return F_58 ( V_33 , V_151 , V_54 -> V_62 -> V_57 , 0 ) ;
F_17 ( V_54 -> V_62 -> V_57 , & V_57 ) ;
if ( ! V_85 -> V_96 -> V_132 )
return V_153 ;
V_87 = V_85 -> V_96 -> V_132 ( V_33 , V_57 . V_56 ) ;
if ( V_87 == V_124 || V_87 == V_121 )
return V_145 ;
return V_153 ;
}
int F_66 ( struct V_1 * V_54 )
{
int V_87 ;
struct V_82 * V_83 = V_54 -> V_62 -> V_83 ;
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_84 * V_85 = F_25 ( V_83 -> V_86 ) ;
if ( V_154 != V_83 -> V_155 )
return F_58 ( V_33 , V_156 , 0 , 0 ) ;
if ( ! V_85 -> V_96 -> V_133 )
return V_153 ;
V_87 = V_85 -> V_96 -> V_133 ( V_33 ) ;
if ( V_87 == V_124 || V_87 == V_121 ||
V_87 == - V_157 )
return V_145 ;
return V_153 ;
}
static int F_67 ( struct V_1 * V_54 )
{
int V_87 ;
struct V_82 * V_111 = V_54 -> V_62 -> V_83 ;
if ( ! V_111 -> V_158 -> V_159 )
goto V_160;
V_87 = V_111 -> V_158 -> V_159 ( V_54 ) ;
if ( V_87 == V_145 )
return V_87 ;
V_160:
if ( V_111 -> V_158 -> V_161 )
return V_111 -> V_158 -> V_161 ( V_54 ) ;
return V_153 ;
}
static void F_68 ( struct V_82 * V_111 , struct V_102 * V_162 )
{
struct V_1 * V_54 , * V_105 ;
enum V_109 V_87 = V_120 ;
int V_163 , V_164 ;
struct V_84 * V_85 = F_25 ( V_111 -> V_86 ) ;
unsigned long V_49 ;
struct V_48 * V_35 = F_32 ( V_111 ) ;
F_21 ( V_165 ) ;
F_38 (cmd, n, work_q, eh_entry) {
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_3 * V_4 ;
F_11 ( & V_33 -> V_50 , V_49 ) ;
V_4 = F_33 ( V_54 ) ;
F_13 ( & V_33 -> V_50 , V_49 ) ;
if ( ! V_4 )
F_36 ( & V_54 -> V_100 , & V_165 ) ;
}
V_166:
F_38 (cmd, n, work_q, eh_entry) {
struct V_3 * V_4 = F_33 ( V_54 ) ;
F_8 ( & V_54 -> V_100 ) ;
F_11 ( & V_4 -> V_117 , V_49 ) ;
V_164 = V_4 -> V_118 & V_167 ;
F_13 ( & V_4 -> V_117 , V_49 ) ;
if ( V_164 ) {
F_5 ( L_18 ,
V_115 , V_4 ) ;
goto V_168;
}
F_5 ( L_19 , V_4 ) ;
V_87 = F_41 ( V_4 ) ;
V_54 -> V_169 = 0 ;
switch ( V_87 ) {
case V_114 :
F_5 ( L_20 ,
V_115 , V_4 ,
V_54 -> V_170 ? L_21 : L_22 ) ;
if ( V_54 -> V_170 )
V_54 -> V_170 -- ;
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
F_5 ( L_23 , V_4 ) ;
V_168:
V_163 = F_44 ( V_4 -> V_33 , V_54 ) ;
if ( V_163 == V_121 ) {
F_5 ( L_24
L_25 ,
F_45 ( V_4 -> V_33 ) ,
V_54 -> V_62 -> V_57 ) ;
F_35 ( V_54 ) ;
F_37 ( V_162 , V_54 ) ;
goto V_166;
}
case V_126 :
case V_128 :
F_5 ( L_26 ,
V_4 ) ;
V_163 = F_46 ( V_4 -> V_33 ) ;
if ( V_163 == V_121 ||
V_163 == - V_157 ) {
struct V_47 * V_33 = V_4 -> V_33 ;
F_5 ( L_27 ,
F_45 ( V_4 -> V_33 -> V_129 ) ) ;
F_31 ( V_54 ) ;
F_39 ( V_162 , V_33 ) ;
goto V_166;
}
F_67 ( V_54 ) ;
if ( V_85 -> V_96 -> V_171 ) {
struct V_108 * V_34 = V_4 -> V_33 -> V_34 ;
F_5 ( L_28 ,
V_34 -> V_172 ) ;
V_87 = V_85 -> V_96 -> V_171 ( V_34 ) ;
if ( V_87 == V_121 ) {
F_5 ( L_29
L_30 , V_34 -> V_172 ) ;
F_31 ( V_54 ) ;
F_40 ( V_162 ,
V_34 ) ;
goto V_166;
}
}
if ( V_85 -> V_96 -> V_173 ) {
F_5 ( L_31 ) ;
V_87 = V_85 -> V_96 -> V_173 ( V_35 ) ;
if ( V_87 == V_121 ) {
F_5 ( L_32
L_30 ) ;
F_31 ( V_54 ) ;
goto V_174;
}
}
F_5 ( L_33
L_34 ,
F_45 ( V_4 -> V_33 -> V_129 ) ,
V_54 -> V_62 -> V_57 ) ;
F_31 ( V_54 ) ;
goto V_174;
}
}
V_175:
F_69 ( & V_165 , V_162 ) ;
F_70 ( & V_35 -> V_101 , V_162 ) ;
return;
V_174:
F_5 ( L_35 , V_115 ) ;
F_38 (cmd, n, work_q, eh_entry)
F_31 ( V_54 ) ;
goto V_175;
}
static void F_71 ( struct V_82 * V_111 )
{
struct V_48 * V_35 = F_32 ( V_111 ) ;
struct V_84 * V_85 = F_25 ( V_111 -> V_86 ) ;
F_28 ( & V_35 -> V_92 ) ;
while ( ! F_72 ( & V_35 -> V_149 ) ) {
struct V_47 * V_33 ;
struct V_176 * V_177 ;
V_177 = F_73 ( V_35 -> V_149 . V_178 , F_74 ( * V_177 ) , V_148 ) ;
F_8 ( & V_177 -> V_148 ) ;
V_33 = F_75 ( V_177 , F_74 ( * V_33 ) , V_147 ) ;
F_76 ( & V_33 -> V_179 ) ;
F_77 ( F_27 ( V_33 ) , L_36 ) ;
F_30 ( & V_35 -> V_92 ) ;
if ( F_78 ( V_151 , & V_33 -> V_52 ) )
V_85 -> V_96 -> V_132 ( V_33 , V_177 -> V_150 . V_56 ) ;
if ( F_78 ( V_156 , & V_33 -> V_52 ) )
V_85 -> V_96 -> V_133 ( V_33 ) ;
F_79 ( V_33 ) ;
F_28 ( & V_35 -> V_92 ) ;
F_80 ( V_139 , & V_33 -> V_52 ) ;
V_35 -> V_146 -- ;
}
F_30 ( & V_35 -> V_92 ) ;
}
void F_81 ( struct V_82 * V_111 )
{
struct V_48 * V_35 = F_32 ( V_111 ) ;
F_21 ( V_180 ) ;
int V_144 = 0 ;
bool V_138 ;
V_138:
V_144 ++ ;
V_138 = true ;
F_28 ( V_111 -> V_181 ) ;
F_82 ( & V_111 -> V_182 , & V_180 ) ;
F_30 ( V_111 -> V_181 ) ;
F_5 ( L_37 ,
V_115 , V_111 -> V_183 , V_111 -> V_184 ) ;
F_61 ( V_51 , & V_35 -> V_52 ) ;
F_68 ( V_111 , & V_180 ) ;
F_80 ( V_51 , & V_35 -> V_52 ) ;
if ( F_72 ( & V_180 ) )
goto V_175;
F_83 ( V_111 , & V_180 , & V_35 -> V_99 ) ;
if ( ! F_84 ( & V_180 , & V_35 -> V_99 ) )
F_85 ( V_111 , & V_180 , & V_35 -> V_99 ) ;
V_175:
if ( V_35 -> V_95 > 1 )
F_23 ( V_35 -> V_76 . V_81 ) ;
F_71 ( V_111 ) ;
F_86 ( V_111 ) ;
F_87 ( & V_35 -> V_99 ) ;
F_28 ( & V_35 -> V_92 ) ;
if ( V_35 -> V_146 == 0 ) {
V_111 -> V_185 = 0 ;
V_138 = false ;
}
F_30 ( & V_35 -> V_92 ) ;
if ( V_138 )
goto V_138;
F_5 ( L_38 ,
V_115 , V_111 -> V_183 , V_111 -> V_184 , V_144 ) ;
}
enum V_186 F_88 ( struct V_1 * V_54 )
{
F_89 ( V_187 , V_54 , L_39 , V_54 ) ;
return V_188 ;
}
int F_90 ( struct V_189 * V_190 , int V_54 , void T_2 * V_191 )
{
struct V_47 * V_33 = F_91 ( V_190 ) ;
if ( F_27 ( V_33 ) )
return F_92 ( V_33 -> V_90 . V_91 , V_190 , V_54 , V_191 ) ;
return - V_192 ;
}
struct V_47 * F_93 ( struct V_193 * V_152 )
{
struct V_82 * V_111 = F_94 ( V_152 -> V_33 . V_194 ) ;
struct V_48 * V_35 = F_32 ( V_111 ) ;
struct V_47 * V_195 = NULL ;
int V_85 ;
unsigned long V_49 ;
F_11 ( & V_35 -> V_136 , V_49 ) ;
for ( V_85 = 0 ; V_85 < V_35 -> V_196 ; V_85 ++ ) {
struct V_108 * V_34 = V_35 -> V_197 [ V_85 ] ;
struct V_47 * V_33 ;
F_95 ( & V_34 -> V_198 ) ;
F_96 (dev, &port->dev_list, dev_list_node) {
if ( V_152 == V_33 -> V_152 ) {
V_195 = V_33 ;
F_97 ( & V_34 -> V_198 ) ;
goto V_199;
}
}
F_97 ( & V_34 -> V_198 ) ;
}
V_199:
F_13 ( & V_35 -> V_136 , V_49 ) ;
return V_195 ;
}
int F_98 ( struct V_200 * V_201 )
{
struct V_193 * V_152 = F_99 ( V_201 -> V_33 . V_194 ) ;
struct V_47 * V_195 = F_93 ( V_152 ) ;
if ( ! V_195 )
return - V_157 ;
F_76 ( & V_195 -> V_179 ) ;
V_201 -> V_202 = V_195 ;
return 0 ;
}
int F_100 ( struct V_189 * V_203 )
{
struct V_47 * V_33 = F_91 ( V_203 ) ;
struct V_48 * V_74 ;
F_48 ( V_33 -> V_152 -> V_204 . V_205 != V_206 ) ;
if ( F_27 ( V_33 ) ) {
F_101 ( V_203 , V_33 -> V_90 . V_91 ) ;
return 0 ;
}
V_74 = V_33 -> V_34 -> V_35 ;
F_102 ( V_203 ) ;
if ( V_203 -> V_207 ) {
F_103 ( V_203 , V_208 ) ;
F_104 ( V_203 , V_209 ) ;
} else {
F_5 ( L_40
L_41 , F_45 ( V_33 -> V_129 ) ,
V_203 -> V_57 ) ;
V_203 -> V_207 = 0 ;
F_103 ( V_203 , 0 ) ;
F_105 ( V_203 , 1 ) ;
}
V_203 -> V_210 = 1 ;
return 0 ;
}
int F_106 ( struct V_189 * V_190 , int V_211 , int V_212 )
{
struct V_47 * V_33 = F_91 ( V_190 ) ;
if ( F_27 ( V_33 ) )
return F_107 ( V_33 -> V_90 . V_91 , V_190 , V_211 ,
V_212 ) ;
switch ( V_212 ) {
case V_213 :
case V_214 :
if ( ! V_190 -> V_207 )
V_211 = 1 ;
F_108 ( V_190 , F_109 ( V_190 ) , V_211 ) ;
break;
case V_215 :
F_110 ( V_190 , V_211 ) ;
break;
default:
return - V_216 ;
}
return V_211 ;
}
int F_111 ( struct V_189 * V_203 , int V_217 )
{
struct V_47 * V_33 = F_91 ( V_203 ) ;
if ( F_27 ( V_33 ) )
return - V_192 ;
if ( ! V_203 -> V_207 )
return 0 ;
F_105 ( V_203 , 1 ) ;
F_103 ( V_203 , V_217 ) ;
F_104 ( V_203 , V_203 -> V_218 ) ;
return V_217 ;
}
int F_112 ( struct V_189 * V_203 ,
struct V_219 * V_220 ,
T_3 V_221 , int * V_222 )
{
V_222 [ 0 ] = 255 ;
V_222 [ 1 ] = 63 ;
F_113 ( V_221 , 255 * 63 ) ;
V_222 [ 2 ] = V_221 ;
return 0 ;
}
static void F_114 ( struct V_48 * V_74 )
{
struct V_75 * V_76 = & V_74 -> V_76 ;
unsigned long V_49 ;
F_21 ( V_223 ) ;
int V_224 ;
int V_87 ;
struct V_84 * V_85 = F_25 ( V_76 -> V_111 -> V_86 ) ;
F_42 ( & V_76 -> V_113 ) ;
F_11 ( & V_76 -> V_77 , V_49 ) ;
while ( ! F_115 () &&
! F_72 ( & V_76 -> V_80 ) &&
! F_12 ( V_51 , & V_74 -> V_52 ) ) {
V_224 = V_74 -> V_78 - V_76 -> V_79 ;
if ( V_224 >= 0 ) {
V_224 = V_76 -> V_79 ;
F_82 ( & V_76 -> V_80 , & V_223 ) ;
} else {
struct V_102 * V_225 , * V_105 ;
V_224 = V_74 -> V_78 ;
F_116 (a, n, &core->task_queue) {
F_36 ( V_225 , & V_223 ) ;
if ( -- V_224 == 0 )
break;
}
V_224 = V_74 -> V_78 ;
}
V_76 -> V_79 -= V_224 ;
F_13 ( & V_76 -> V_77 , V_49 ) ;
{
struct V_3 * V_4 = F_73 ( V_223 . V_178 ,
struct V_3 ,
V_45 ) ;
F_8 ( & V_223 ) ;
V_87 = V_85 -> V_96 -> V_97 ( V_4 , V_224 ,
V_226 ) ;
if ( F_14 ( V_87 ) )
F_117 ( & V_223 , V_4 -> V_45 . V_227 , & V_4 -> V_45 ) ;
}
F_11 ( & V_76 -> V_77 , V_49 ) ;
if ( V_87 ) {
F_82 ( & V_223 , & V_76 -> V_80 ) ;
V_76 -> V_79 += V_224 ;
}
}
F_13 ( & V_76 -> V_77 , V_49 ) ;
F_43 ( & V_76 -> V_113 ) ;
}
static int F_118 ( void * V_228 )
{
struct V_48 * V_74 = V_228 ;
while ( 1 ) {
F_119 ( V_229 ) ;
F_54 () ;
F_114 ( V_74 ) ;
if ( F_115 () )
break;
}
return 0 ;
}
int F_120 ( struct V_48 * V_74 )
{
struct V_75 * V_76 = & V_74 -> V_76 ;
F_121 ( & V_76 -> V_77 ) ;
F_122 ( & V_76 -> V_113 ) ;
V_76 -> V_79 = 0 ;
F_123 ( & V_76 -> V_80 ) ;
V_76 -> V_81 = F_124 ( F_118 , V_74 ,
L_42 , V_76 -> V_111 -> V_230 ) ;
if ( F_125 ( V_76 -> V_81 ) )
return F_126 ( V_76 -> V_81 ) ;
return 0 ;
}
void F_127 ( struct V_48 * V_74 )
{
unsigned long V_49 ;
struct V_75 * V_76 = & V_74 -> V_76 ;
struct V_3 * V_4 , * V_105 ;
F_128 ( V_76 -> V_81 ) ;
if ( ! F_72 ( & V_76 -> V_80 ) )
F_5 ( L_43 ,
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
void F_129 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_46 ;
if ( ! V_2 ) {
struct V_231 * V_232 = V_4 -> V_233 ;
if ( ! V_232 )
return;
if ( ! F_130 ( & V_232 -> V_234 ) )
return;
V_232 -> V_234 . V_235 ( V_232 -> V_234 . V_236 ) ;
return;
}
if ( F_27 ( V_4 -> V_33 ) ) {
F_131 ( V_4 ) ;
} else {
struct V_237 * V_223 = V_2 -> V_62 -> V_237 ;
unsigned long V_49 ;
F_11 ( V_223 -> V_238 , V_49 ) ;
F_132 ( V_2 -> V_239 ) ;
F_13 ( V_223 -> V_238 , V_49 ) ;
}
}
void F_133 ( struct V_200 * V_201 )
{
struct V_47 * V_195 = V_201 -> V_202 ;
if ( ! V_195 )
return;
V_201 -> V_202 = NULL ;
F_79 ( V_195 ) ;
}
static void F_134 ( T_4 * V_129 , const char * V_240 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_241 ; V_85 ++ ) {
T_4 V_242 , V_243 ;
if ( ! * V_240 )
break;
V_242 = isdigit ( * V_240 ) ? * V_240 - '0' : toupper ( * V_240 ) - 'A' + 10 ;
V_240 ++ ;
V_243 = isdigit ( * V_240 ) ? * V_240 - '0' : toupper ( * V_240 ) - 'A' + 10 ;
V_240 ++ ;
V_129 [ V_85 ] = ( V_242 << 4 ) | V_243 ;
}
}
int F_135 ( struct V_82 * V_111 , T_4 * V_244 )
{
int V_87 ;
const struct V_245 * V_246 ;
V_87 = F_136 ( & V_246 , L_44 , & V_111 -> V_247 ) ;
if ( V_87 )
return V_87 ;
if ( V_246 -> V_248 < V_249 ) {
V_87 = - V_157 ;
goto V_175;
}
F_134 ( V_244 , V_246 -> V_236 ) ;
V_175:
F_137 ( V_246 ) ;
return V_87 ;
}
