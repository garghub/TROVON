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
V_4 -> V_60 . V_54 = V_54 ;
V_4 -> V_66 = F_18 ( V_54 ) ;
V_4 -> V_67 = F_19 ( V_54 ) ;
V_4 -> V_68 = F_3 ( V_54 ) ;
V_4 -> V_69 = V_54 -> V_70 ;
V_4 -> V_71 = F_10 ;
return V_4 ;
}
int F_20 ( struct V_3 * V_4 )
{
struct V_48 * V_72 = V_4 -> V_33 -> V_34 -> V_35 ;
struct V_73 * V_74 = & V_72 -> V_74 ;
unsigned long V_49 ;
F_21 ( V_45 ) ;
F_11 ( & V_74 -> V_75 , V_49 ) ;
if ( V_72 -> V_76 < V_74 -> V_77 + 1 ) {
F_13 ( & V_74 -> V_75 , V_49 ) ;
return - V_23 ;
}
F_22 ( & V_4 -> V_45 , & V_74 -> V_78 ) ;
V_74 -> V_77 += 1 ;
F_13 ( & V_74 -> V_75 , V_49 ) ;
F_23 ( V_74 -> V_79 ) ;
return 0 ;
}
int F_24 ( struct V_80 * V_81 , struct V_1 * V_54 )
{
struct V_82 * V_83 = F_25 ( V_81 -> V_84 ) ;
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_48 * V_72 = V_33 -> V_34 -> V_35 ;
struct V_3 * V_4 ;
int V_85 = 0 ;
if ( F_12 ( V_86 , & V_33 -> V_52 ) ) {
V_54 -> V_44 = V_26 << 16 ;
goto V_87;
}
if ( F_27 ( V_33 ) ) {
F_28 ( V_33 -> V_88 . V_89 -> V_90 ) ;
V_85 = F_29 ( V_54 , V_33 -> V_88 . V_89 ) ;
F_30 ( V_33 -> V_88 . V_89 -> V_90 ) ;
return V_85 ;
}
V_4 = F_15 ( V_54 , V_33 , V_91 ) ;
if ( ! V_4 )
return V_92 ;
if ( V_72 -> V_93 < 2 )
V_85 = V_83 -> V_94 -> V_95 ( V_4 , 1 , V_91 ) ;
else
V_85 = F_20 ( V_4 ) ;
if ( V_85 )
goto V_96;
return 0 ;
V_96:
F_5 ( L_5 , V_85 ) ;
F_7 ( V_54 , NULL ) ;
F_9 ( V_4 ) ;
if ( V_85 == - V_23 )
V_54 -> V_44 = V_24 << 16 ;
else
V_54 -> V_44 = V_21 << 16 ;
V_87:
V_54 -> V_53 ( V_54 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_54 )
{
struct V_48 * V_72 = F_32 ( V_54 -> V_62 -> V_81 ) ;
struct V_3 * V_4 = F_33 ( V_54 ) ;
F_1 ( V_54 , V_4 ) ;
F_34 ( V_54 , & V_72 -> V_97 ) ;
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
F_36 ( & V_54 -> V_98 , & V_35 -> V_99 ) ;
}
static void F_37 ( struct V_100 * V_101 , struct V_1 * V_102 )
{
struct V_1 * V_54 , * V_103 ;
F_38 (cmd, n, error_q, eh_entry) {
if ( V_54 -> V_62 -> V_104 == V_102 -> V_62 -> V_104 &&
V_54 -> V_62 -> V_57 == V_102 -> V_62 -> V_57 )
F_35 ( V_54 ) ;
}
}
static void F_39 ( struct V_100 * V_101 ,
struct V_47 * V_33 )
{
struct V_1 * V_54 , * V_103 ;
F_38 (cmd, n, error_q, eh_entry) {
struct V_47 * V_105 = F_26 ( V_54 ) ;
if ( V_105 == V_33 )
F_31 ( V_54 ) ;
}
}
static void F_40 ( struct V_100 * V_101 ,
struct V_106 * V_34 )
{
struct V_1 * V_54 , * V_103 ;
F_38 (cmd, n, error_q, eh_entry) {
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_106 * V_105 = V_33 -> V_34 ;
if ( V_105 == V_34 )
F_31 ( V_54 ) ;
}
}
static enum V_107 F_41 ( struct V_3 * V_4 )
{
struct V_48 * V_35 = V_4 -> V_33 -> V_34 -> V_35 ;
unsigned long V_49 ;
int V_83 , V_85 ;
struct V_82 * V_108 =
F_25 ( V_4 -> V_33 -> V_34 -> V_35 -> V_74 . V_109 -> V_84 ) ;
if ( V_35 -> V_93 > 1 ) {
struct V_73 * V_74 = & V_35 -> V_74 ;
struct V_3 * V_110 , * V_103 ;
F_42 ( & V_74 -> V_111 ) ;
F_11 ( & V_74 -> V_75 , V_49 ) ;
F_38 (t, n, &core->task_queue, list)
if ( V_4 == V_110 ) {
F_8 ( & V_110 -> V_45 ) ;
break;
}
F_13 ( & V_74 -> V_75 , V_49 ) ;
F_43 ( & V_74 -> V_111 ) ;
if ( V_4 == V_110 )
return V_112 ;
}
for ( V_83 = 0 ; V_83 < 5 ; V_83 ++ ) {
F_5 ( L_6 , V_113 , V_4 ) ;
V_85 = V_108 -> V_94 -> V_114 ( V_4 ) ;
F_11 ( & V_4 -> V_115 , V_49 ) ;
if ( V_4 -> V_116 & V_117 ) {
F_13 ( & V_4 -> V_115 , V_49 ) ;
F_5 ( L_7 , V_113 ,
V_4 ) ;
return V_118 ;
}
F_13 ( & V_4 -> V_115 , V_49 ) ;
if ( V_85 == V_119 ) {
F_5 ( L_8 ,
V_113 , V_4 ) ;
return V_120 ;
} else if ( V_108 -> V_94 -> V_121 ) {
F_5 ( L_9 ,
V_113 , V_4 ) ;
V_85 = V_108 -> V_94 -> V_121 ( V_4 ) ;
switch ( V_85 ) {
case V_122 :
F_5 ( L_10 ,
V_113 , V_4 ) ;
return V_123 ;
case V_119 :
F_5 ( L_11 ,
V_113 , V_4 ) ;
return V_124 ;
case V_125 :
F_5 ( L_12 ,
V_113 , V_4 ) ;
return V_126 ;
}
}
}
return V_85 ;
}
static int F_44 ( struct V_47 * V_33 , struct V_1 * V_54 )
{
int V_85 = V_125 ;
struct V_56 V_57 ;
struct V_82 * V_83 =
F_25 ( V_33 -> V_34 -> V_35 -> V_74 . V_109 -> V_84 ) ;
F_17 ( V_54 -> V_62 -> V_57 , & V_57 ) ;
F_5 ( L_13 ,
F_45 ( V_33 -> V_127 ) ,
V_54 -> V_62 -> V_57 ) ;
if ( V_83 -> V_94 -> V_128 )
V_85 = V_83 -> V_94 -> V_128 ( V_33 , V_57 . V_56 ) ;
if ( V_85 == V_125 ) {
if ( V_83 -> V_94 -> V_129 )
V_85 = V_83 -> V_94 -> V_129 ( V_33 , V_57 . V_56 ) ;
}
if ( V_85 == V_125 ) {
if ( V_83 -> V_94 -> V_130 )
V_85 = V_83 -> V_94 -> V_130 ( V_33 , V_57 . V_56 ) ;
}
return V_85 ;
}
static int F_46 ( struct V_47 * V_33 )
{
int V_85 = V_125 ;
struct V_82 * V_83 =
F_25 ( V_33 -> V_34 -> V_35 -> V_74 . V_109 -> V_84 ) ;
F_5 ( L_14 ,
F_45 ( V_33 -> V_127 ) ) ;
if ( V_83 -> V_94 -> V_131 )
V_85 = V_83 -> V_94 -> V_131 ( V_33 ) ;
return V_85 ;
}
struct V_132 * F_47 ( struct V_47 * V_33 )
{
struct V_48 * V_35 = V_33 -> V_34 -> V_35 ;
struct V_132 * V_133 ;
unsigned long V_49 ;
F_48 ( ! V_33 -> V_133 ) ;
F_11 ( & V_35 -> V_134 , V_49 ) ;
V_133 = V_33 -> V_133 ;
F_49 ( & V_133 -> V_33 ) ;
F_13 ( & V_35 -> V_134 , V_49 ) ;
return V_133 ;
}
static void F_50 ( struct V_47 * V_33 )
{
struct V_48 * V_35 = V_33 -> V_34 -> V_35 ;
F_51 ( V_135 ) ;
if ( F_27 ( V_33 ) ) {
F_52 ( V_33 -> V_88 . V_89 ) ;
return;
}
V_136:
F_28 ( & V_35 -> V_90 ) ;
while ( F_12 ( V_137 , & V_33 -> V_52 ) ) {
F_53 ( & V_35 -> V_138 , & V_135 , V_139 ) ;
F_30 ( & V_35 -> V_90 ) ;
F_54 () ;
F_28 ( & V_35 -> V_90 ) ;
}
F_55 ( & V_35 -> V_138 , & V_135 ) ;
F_30 ( & V_35 -> V_90 ) ;
if ( F_56 ( V_35 -> V_74 . V_109 ) ) {
F_57 ( 10 ) ;
goto V_136;
}
}
static int F_58 ( struct V_47 * V_33 , int V_140 , int V_57 , int V_135 )
{
struct V_48 * V_35 = V_33 -> V_34 -> V_35 ;
int V_141 = 0 , V_142 = 100 ;
if ( F_27 ( V_33 ) ) {
F_59 ( V_33 ) ;
if ( V_135 )
F_60 ( V_33 ) ;
return V_143 ;
}
while ( ! V_141 && V_142 -- ) {
F_28 ( & V_35 -> V_90 ) ;
if ( ! F_12 ( V_137 , & V_33 -> V_52 ) &&
! F_12 ( V_140 , & V_33 -> V_52 ) ) {
V_141 = 1 ;
V_35 -> V_144 ++ ;
F_22 ( & V_33 -> V_145 . V_146 , & V_35 -> V_147 ) ;
F_61 ( V_137 , & V_33 -> V_52 ) ;
F_61 ( V_140 , & V_33 -> V_52 ) ;
F_17 ( V_57 , & V_33 -> V_145 . V_148 ) ;
F_62 ( V_35 -> V_74 . V_109 ) ;
}
F_30 ( & V_35 -> V_90 ) ;
if ( V_135 )
F_50 ( V_33 ) ;
if ( V_141 )
return V_143 ;
}
F_5 ( L_15 ,
V_140 == V_149 ? L_16 : L_17 ,
F_63 ( & V_33 -> V_150 -> V_33 ) ) ;
return V_151 ;
}
int F_64 ( struct V_1 * V_54 )
{
int V_85 ;
struct V_3 * V_4 = F_33 ( V_54 ) ;
struct V_80 * V_81 = V_54 -> V_62 -> V_81 ;
struct V_82 * V_83 = F_25 ( V_81 -> V_84 ) ;
if ( V_152 != V_81 -> V_153 )
return V_151 ;
if ( ! V_83 -> V_94 -> V_114 )
return V_151 ;
V_85 = V_83 -> V_94 -> V_114 ( V_4 ) ;
if ( V_85 == V_122 || V_85 == V_119 )
return V_143 ;
return V_151 ;
}
int F_65 ( struct V_1 * V_54 )
{
int V_85 ;
struct V_56 V_57 ;
struct V_80 * V_81 = V_54 -> V_62 -> V_81 ;
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_82 * V_83 = F_25 ( V_81 -> V_84 ) ;
if ( V_152 != V_81 -> V_153 )
return F_58 ( V_33 , V_149 , V_54 -> V_62 -> V_57 , 0 ) ;
F_17 ( V_54 -> V_62 -> V_57 , & V_57 ) ;
if ( ! V_83 -> V_94 -> V_130 )
return V_151 ;
V_85 = V_83 -> V_94 -> V_130 ( V_33 , V_57 . V_56 ) ;
if ( V_85 == V_122 || V_85 == V_119 )
return V_143 ;
return V_151 ;
}
int F_66 ( struct V_1 * V_54 )
{
int V_85 ;
struct V_80 * V_81 = V_54 -> V_62 -> V_81 ;
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_82 * V_83 = F_25 ( V_81 -> V_84 ) ;
if ( V_152 != V_81 -> V_153 )
return F_58 ( V_33 , V_154 , 0 , 0 ) ;
if ( ! V_83 -> V_94 -> V_131 )
return V_151 ;
V_85 = V_83 -> V_94 -> V_131 ( V_33 ) ;
if ( V_85 == V_122 || V_85 == V_119 ||
V_85 == - V_155 )
return V_143 ;
return V_151 ;
}
static int F_67 ( struct V_1 * V_54 )
{
int V_85 ;
struct V_80 * V_109 = V_54 -> V_62 -> V_81 ;
if ( ! V_109 -> V_156 -> V_157 )
goto V_158;
V_85 = V_109 -> V_156 -> V_157 ( V_54 ) ;
if ( V_85 == V_143 )
return V_85 ;
V_158:
if ( V_109 -> V_156 -> V_159 )
return V_109 -> V_156 -> V_159 ( V_54 ) ;
return V_151 ;
}
static void F_68 ( struct V_80 * V_109 , struct V_100 * V_160 )
{
struct V_1 * V_54 , * V_103 ;
enum V_107 V_85 = V_118 ;
int V_161 , V_162 ;
struct V_82 * V_83 = F_25 ( V_109 -> V_84 ) ;
unsigned long V_49 ;
struct V_48 * V_35 = F_32 ( V_109 ) ;
F_21 ( V_163 ) ;
F_38 (cmd, n, work_q, eh_entry) {
struct V_47 * V_33 = F_26 ( V_54 ) ;
struct V_3 * V_4 ;
F_11 ( & V_33 -> V_50 , V_49 ) ;
V_4 = F_33 ( V_54 ) ;
F_13 ( & V_33 -> V_50 , V_49 ) ;
if ( ! V_4 )
F_36 ( & V_54 -> V_98 , & V_163 ) ;
}
V_164:
F_38 (cmd, n, work_q, eh_entry) {
struct V_3 * V_4 = F_33 ( V_54 ) ;
F_8 ( & V_54 -> V_98 ) ;
F_11 ( & V_4 -> V_115 , V_49 ) ;
V_162 = V_4 -> V_116 & V_165 ;
F_13 ( & V_4 -> V_115 , V_49 ) ;
if ( V_162 ) {
F_5 ( L_18 ,
V_113 , V_4 ) ;
goto V_166;
}
F_5 ( L_19 , V_4 ) ;
V_85 = F_41 ( V_4 ) ;
V_54 -> V_167 = 0 ;
switch ( V_85 ) {
case V_112 :
F_5 ( L_20 ,
V_113 , V_4 ,
V_54 -> V_168 ? L_21 : L_22 ) ;
if ( V_54 -> V_168 )
V_54 -> V_168 -- ;
F_31 ( V_54 ) ;
continue;
case V_118 :
F_5 ( L_7 , V_113 ,
V_4 ) ;
F_35 ( V_54 ) ;
continue;
case V_120 :
F_5 ( L_8 ,
V_113 , V_4 ) ;
F_35 ( V_54 ) ;
continue;
case V_123 :
F_5 ( L_23 , V_4 ) ;
V_166:
V_161 = F_44 ( V_4 -> V_33 , V_54 ) ;
if ( V_161 == V_119 ) {
F_5 ( L_24
L_25 ,
F_45 ( V_4 -> V_33 ) ,
V_54 -> V_62 -> V_57 ) ;
F_35 ( V_54 ) ;
F_37 ( V_160 , V_54 ) ;
goto V_164;
}
case V_124 :
case V_126 :
F_5 ( L_26 ,
V_4 ) ;
V_161 = F_46 ( V_4 -> V_33 ) ;
if ( V_161 == V_119 ||
V_161 == - V_155 ) {
struct V_47 * V_33 = V_4 -> V_33 ;
F_5 ( L_27 ,
F_45 ( V_4 -> V_33 -> V_127 ) ) ;
F_31 ( V_54 ) ;
F_39 ( V_160 , V_33 ) ;
goto V_164;
}
F_67 ( V_54 ) ;
if ( V_83 -> V_94 -> V_169 ) {
struct V_106 * V_34 = V_4 -> V_33 -> V_34 ;
F_5 ( L_28 ,
V_34 -> V_170 ) ;
V_85 = V_83 -> V_94 -> V_169 ( V_34 ) ;
if ( V_85 == V_119 ) {
F_5 ( L_29
L_30 , V_34 -> V_170 ) ;
F_31 ( V_54 ) ;
F_40 ( V_160 ,
V_34 ) ;
goto V_164;
}
}
if ( V_83 -> V_94 -> V_171 ) {
F_5 ( L_31 ) ;
V_85 = V_83 -> V_94 -> V_171 ( V_35 ) ;
if ( V_85 == V_119 ) {
F_5 ( L_32
L_30 ) ;
F_31 ( V_54 ) ;
goto V_172;
}
}
F_5 ( L_33
L_34 ,
F_45 ( V_4 -> V_33 -> V_127 ) ,
V_54 -> V_62 -> V_57 ) ;
F_31 ( V_54 ) ;
goto V_172;
}
}
V_173:
F_69 ( & V_163 , V_160 ) ;
F_70 ( & V_35 -> V_99 , V_160 ) ;
return;
V_172:
F_5 ( L_35 , V_113 ) ;
F_38 (cmd, n, work_q, eh_entry)
F_31 ( V_54 ) ;
goto V_173;
}
static void F_71 ( struct V_80 * V_109 )
{
struct V_48 * V_35 = F_32 ( V_109 ) ;
struct V_82 * V_83 = F_25 ( V_109 -> V_84 ) ;
F_28 ( & V_35 -> V_90 ) ;
while ( ! F_72 ( & V_35 -> V_147 ) ) {
struct V_47 * V_33 ;
struct V_174 * V_175 ;
V_175 = F_73 ( V_35 -> V_147 . V_176 , F_74 ( * V_175 ) , V_146 ) ;
F_8 ( & V_175 -> V_146 ) ;
V_33 = F_75 ( V_175 , F_74 ( * V_33 ) , V_145 ) ;
F_76 ( & V_33 -> V_177 ) ;
F_77 ( F_27 ( V_33 ) , L_36 ) ;
F_30 ( & V_35 -> V_90 ) ;
if ( F_78 ( V_149 , & V_33 -> V_52 ) )
V_83 -> V_94 -> V_130 ( V_33 , V_175 -> V_148 . V_56 ) ;
if ( F_78 ( V_154 , & V_33 -> V_52 ) )
V_83 -> V_94 -> V_131 ( V_33 ) ;
F_79 ( V_33 ) ;
F_28 ( & V_35 -> V_90 ) ;
F_80 ( V_137 , & V_33 -> V_52 ) ;
V_35 -> V_144 -- ;
}
F_30 ( & V_35 -> V_90 ) ;
}
void F_81 ( struct V_80 * V_109 )
{
struct V_48 * V_35 = F_32 ( V_109 ) ;
F_21 ( V_178 ) ;
int V_142 = 0 ;
bool V_136 ;
V_136:
V_142 ++ ;
V_136 = true ;
F_28 ( V_109 -> V_179 ) ;
F_82 ( & V_109 -> V_180 , & V_178 ) ;
F_30 ( V_109 -> V_179 ) ;
F_5 ( L_37 ,
V_113 , V_109 -> V_181 , V_109 -> V_182 ) ;
F_61 ( V_51 , & V_35 -> V_52 ) ;
F_68 ( V_109 , & V_178 ) ;
F_80 ( V_51 , & V_35 -> V_52 ) ;
if ( F_72 ( & V_178 ) )
goto V_173;
F_83 ( V_109 , & V_178 , & V_35 -> V_97 ) ;
if ( ! F_84 ( & V_178 , & V_35 -> V_97 ) )
F_85 ( V_109 , & V_178 , & V_35 -> V_97 ) ;
V_173:
if ( V_35 -> V_93 > 1 )
F_23 ( V_35 -> V_74 . V_79 ) ;
F_71 ( V_109 ) ;
F_86 ( V_109 ) ;
F_87 ( & V_35 -> V_97 ) ;
F_28 ( & V_35 -> V_90 ) ;
if ( V_35 -> V_144 == 0 ) {
V_109 -> V_183 = 0 ;
V_136 = false ;
}
F_30 ( & V_35 -> V_90 ) ;
if ( V_136 )
goto V_136;
F_5 ( L_38 ,
V_113 , V_109 -> V_181 , V_109 -> V_182 , V_142 ) ;
}
enum V_184 F_88 ( struct V_1 * V_54 )
{
F_89 ( V_185 , V_54 , L_39 , V_54 ) ;
return V_186 ;
}
int F_90 ( struct V_187 * V_188 , int V_54 , void T_2 * V_189 )
{
struct V_47 * V_33 = F_91 ( V_188 ) ;
if ( F_27 ( V_33 ) )
return F_92 ( V_33 -> V_88 . V_89 , V_188 , V_54 , V_189 ) ;
return - V_190 ;
}
struct V_47 * F_93 ( struct V_191 * V_150 )
{
struct V_80 * V_109 = F_94 ( V_150 -> V_33 . V_192 ) ;
struct V_48 * V_35 = F_32 ( V_109 ) ;
struct V_47 * V_193 = NULL ;
int V_83 ;
unsigned long V_49 ;
F_11 ( & V_35 -> V_134 , V_49 ) ;
for ( V_83 = 0 ; V_83 < V_35 -> V_194 ; V_83 ++ ) {
struct V_106 * V_34 = V_35 -> V_195 [ V_83 ] ;
struct V_47 * V_33 ;
F_95 ( & V_34 -> V_196 ) ;
F_96 (dev, &port->dev_list, dev_list_node) {
if ( V_150 == V_33 -> V_150 ) {
V_193 = V_33 ;
F_97 ( & V_34 -> V_196 ) ;
goto V_197;
}
}
F_97 ( & V_34 -> V_196 ) ;
}
V_197:
F_13 ( & V_35 -> V_134 , V_49 ) ;
return V_193 ;
}
int F_98 ( struct V_198 * V_199 )
{
struct V_191 * V_150 = F_99 ( V_199 -> V_33 . V_192 ) ;
struct V_47 * V_193 = F_93 ( V_150 ) ;
if ( ! V_193 )
return - V_155 ;
F_76 ( & V_193 -> V_177 ) ;
V_199 -> V_200 = V_193 ;
return 0 ;
}
int F_100 ( struct V_187 * V_201 )
{
struct V_47 * V_33 = F_91 ( V_201 ) ;
struct V_48 * V_72 ;
F_48 ( V_33 -> V_150 -> V_202 . V_203 != V_204 ) ;
if ( F_27 ( V_33 ) ) {
F_101 ( V_201 , V_33 -> V_88 . V_89 ) ;
return 0 ;
}
V_72 = V_33 -> V_34 -> V_35 ;
F_102 ( V_201 ) ;
if ( V_201 -> V_205 ) {
F_103 ( V_201 , V_206 ) ;
F_104 ( V_201 , V_207 ) ;
} else {
F_5 ( L_40
L_41 , F_45 ( V_33 -> V_127 ) ,
V_201 -> V_57 ) ;
V_201 -> V_205 = 0 ;
F_103 ( V_201 , 0 ) ;
F_105 ( V_201 , 1 ) ;
}
V_201 -> V_208 = 1 ;
return 0 ;
}
int F_106 ( struct V_187 * V_188 , int V_209 , int V_210 )
{
struct V_47 * V_33 = F_91 ( V_188 ) ;
if ( F_27 ( V_33 ) )
return F_107 ( V_33 -> V_88 . V_89 , V_188 , V_209 ,
V_210 ) ;
switch ( V_210 ) {
case V_211 :
case V_212 :
if ( ! V_188 -> V_205 )
V_209 = 1 ;
F_108 ( V_188 , F_109 ( V_188 ) , V_209 ) ;
break;
case V_213 :
F_110 ( V_188 , V_209 ) ;
break;
default:
return - V_214 ;
}
return V_209 ;
}
int F_111 ( struct V_187 * V_201 , int V_215 )
{
struct V_47 * V_33 = F_91 ( V_201 ) ;
if ( F_27 ( V_33 ) )
return - V_190 ;
if ( ! V_201 -> V_205 )
return 0 ;
F_105 ( V_201 , 1 ) ;
F_103 ( V_201 , V_215 ) ;
F_104 ( V_201 , V_201 -> V_216 ) ;
return V_215 ;
}
int F_112 ( struct V_187 * V_201 ,
struct V_217 * V_218 ,
T_3 V_219 , int * V_220 )
{
V_220 [ 0 ] = 255 ;
V_220 [ 1 ] = 63 ;
F_113 ( V_219 , 255 * 63 ) ;
V_220 [ 2 ] = V_219 ;
return 0 ;
}
static void F_114 ( struct V_48 * V_72 )
{
struct V_73 * V_74 = & V_72 -> V_74 ;
unsigned long V_49 ;
F_21 ( V_221 ) ;
int V_222 ;
int V_85 ;
struct V_82 * V_83 = F_25 ( V_74 -> V_109 -> V_84 ) ;
F_42 ( & V_74 -> V_111 ) ;
F_11 ( & V_74 -> V_75 , V_49 ) ;
while ( ! F_115 () &&
! F_72 ( & V_74 -> V_78 ) &&
! F_12 ( V_51 , & V_72 -> V_52 ) ) {
V_222 = V_72 -> V_76 - V_74 -> V_77 ;
if ( V_222 >= 0 ) {
V_222 = V_74 -> V_77 ;
F_82 ( & V_74 -> V_78 , & V_221 ) ;
} else {
struct V_100 * V_223 , * V_103 ;
V_222 = V_72 -> V_76 ;
F_116 (a, n, &core->task_queue) {
F_36 ( V_223 , & V_221 ) ;
if ( -- V_222 == 0 )
break;
}
V_222 = V_72 -> V_76 ;
}
V_74 -> V_77 -= V_222 ;
F_13 ( & V_74 -> V_75 , V_49 ) ;
{
struct V_3 * V_4 = F_73 ( V_221 . V_176 ,
struct V_3 ,
V_45 ) ;
F_8 ( & V_221 ) ;
V_85 = V_83 -> V_94 -> V_95 ( V_4 , V_222 ,
V_224 ) ;
if ( F_14 ( V_85 ) )
F_117 ( & V_221 , V_4 -> V_45 . V_225 , & V_4 -> V_45 ) ;
}
F_11 ( & V_74 -> V_75 , V_49 ) ;
if ( V_85 ) {
F_82 ( & V_221 , & V_74 -> V_78 ) ;
V_74 -> V_77 += V_222 ;
}
}
F_13 ( & V_74 -> V_75 , V_49 ) ;
F_43 ( & V_74 -> V_111 ) ;
}
static int F_118 ( void * V_226 )
{
struct V_48 * V_72 = V_226 ;
while ( 1 ) {
F_119 ( V_227 ) ;
F_54 () ;
F_114 ( V_72 ) ;
if ( F_115 () )
break;
}
return 0 ;
}
int F_120 ( struct V_48 * V_72 )
{
struct V_73 * V_74 = & V_72 -> V_74 ;
F_121 ( & V_74 -> V_75 ) ;
F_122 ( & V_74 -> V_111 ) ;
V_74 -> V_77 = 0 ;
F_123 ( & V_74 -> V_78 ) ;
V_74 -> V_79 = F_124 ( F_118 , V_72 ,
L_42 , V_74 -> V_109 -> V_228 ) ;
if ( F_125 ( V_74 -> V_79 ) )
return F_126 ( V_74 -> V_79 ) ;
return 0 ;
}
void F_127 ( struct V_48 * V_72 )
{
unsigned long V_49 ;
struct V_73 * V_74 = & V_72 -> V_74 ;
struct V_3 * V_4 , * V_103 ;
F_128 ( V_74 -> V_79 ) ;
if ( ! F_72 ( & V_74 -> V_78 ) )
F_5 ( L_43 ,
F_45 ( V_72 -> V_127 ) ) ;
F_11 ( & V_74 -> V_75 , V_49 ) ;
F_38 (task, n, &core->task_queue, list) {
struct V_1 * V_54 = V_4 -> V_46 ;
F_8 ( & V_4 -> V_45 ) ;
F_7 ( V_54 , NULL ) ;
F_9 ( V_4 ) ;
V_54 -> V_44 = V_38 << 16 ;
V_54 -> V_53 ( V_54 ) ;
}
F_13 ( & V_74 -> V_75 , V_49 ) ;
}
void F_129 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_46 ;
if ( ! V_2 ) {
struct V_229 * V_230 = V_4 -> V_231 ;
if ( ! V_230 )
return;
if ( ! F_130 ( & V_230 -> V_232 ) )
return;
V_230 -> V_232 . V_233 ( V_230 -> V_232 . V_234 ) ;
return;
}
if ( F_27 ( V_4 -> V_33 ) ) {
F_131 ( V_4 ) ;
} else {
struct V_235 * V_221 = V_2 -> V_62 -> V_235 ;
unsigned long V_49 ;
F_11 ( V_221 -> V_236 , V_49 ) ;
F_132 ( V_2 -> V_237 ) ;
F_13 ( V_221 -> V_236 , V_49 ) ;
}
}
void F_133 ( struct V_198 * V_199 )
{
struct V_47 * V_193 = V_199 -> V_200 ;
if ( ! V_193 )
return;
V_199 -> V_200 = NULL ;
F_79 ( V_193 ) ;
}
static void F_134 ( T_4 * V_127 , const char * V_238 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < V_239 ; V_83 ++ ) {
T_4 V_240 , V_241 ;
if ( ! * V_238 )
break;
V_240 = isdigit ( * V_238 ) ? * V_238 - '0' : toupper ( * V_238 ) - 'A' + 10 ;
V_238 ++ ;
V_241 = isdigit ( * V_238 ) ? * V_238 - '0' : toupper ( * V_238 ) - 'A' + 10 ;
V_238 ++ ;
V_127 [ V_83 ] = ( V_240 << 4 ) | V_241 ;
}
}
int F_135 ( struct V_80 * V_109 , T_4 * V_242 )
{
int V_85 ;
const struct V_243 * V_244 ;
V_85 = F_136 ( & V_244 , L_44 , & V_109 -> V_245 ) ;
if ( V_85 )
return V_85 ;
if ( V_244 -> V_246 < V_247 ) {
V_85 = - V_155 ;
goto V_173;
}
F_134 ( V_242 , V_244 -> V_234 ) ;
V_173:
F_137 ( V_244 ) ;
return V_85 ;
}
