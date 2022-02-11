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
F_8 ( V_4 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_45 ;
struct V_46 * V_33 = V_4 -> V_33 ;
struct V_47 * V_35 = V_33 -> V_34 -> V_35 ;
unsigned long V_48 ;
F_10 ( & V_33 -> V_49 , V_48 ) ;
if ( F_11 ( V_50 , & V_35 -> V_51 ) )
V_4 = NULL ;
else
F_7 ( V_2 , NULL ) ;
F_12 ( & V_33 -> V_49 , V_48 ) ;
if ( F_13 ( ! V_4 ) ) {
F_5 ( L_3 ) ;
return;
}
if ( F_13 ( ! V_2 ) ) {
F_5 ( L_4 ) ;
F_8 ( V_4 ) ;
return;
}
F_1 ( V_2 , V_4 ) ;
V_2 -> V_52 ( V_2 ) ;
}
static struct V_3 * F_14 ( struct V_1 * V_53 ,
struct V_46 * V_33 ,
T_1 V_54 )
{
struct V_3 * V_4 = F_15 ( V_54 ) ;
struct V_55 V_56 ;
if ( ! V_4 )
return NULL ;
V_4 -> V_45 = V_53 ;
F_7 ( V_53 , V_4 ) ;
V_4 -> V_33 = V_33 ;
V_4 -> V_57 = V_4 -> V_33 -> V_58 ;
V_4 -> V_59 . V_60 = 1 ;
F_16 ( V_53 -> V_61 -> V_56 , & V_56 ) ;
memcpy ( V_4 -> V_59 . V_62 , & V_56 . V_55 , 8 ) ;
V_4 -> V_59 . V_63 = V_64 ;
V_4 -> V_59 . V_53 = V_53 ;
V_4 -> V_65 = F_17 ( V_53 ) ;
V_4 -> V_66 = F_18 ( V_53 ) ;
V_4 -> V_67 = F_3 ( V_53 ) ;
V_4 -> V_68 = V_53 -> V_69 ;
V_4 -> V_70 = F_9 ;
return V_4 ;
}
int F_19 ( struct V_71 * V_72 , struct V_1 * V_53 )
{
struct V_73 * V_74 = F_20 ( V_72 -> V_75 ) ;
struct V_46 * V_33 = F_21 ( V_53 ) ;
struct V_3 * V_4 ;
int V_76 = 0 ;
if ( F_11 ( V_77 , & V_33 -> V_51 ) ) {
V_53 -> V_44 = V_26 << 16 ;
goto V_78;
}
if ( F_22 ( V_33 ) ) {
F_23 ( V_33 -> V_79 . V_80 -> V_81 ) ;
V_76 = F_24 ( V_53 , V_33 -> V_79 . V_80 ) ;
F_25 ( V_33 -> V_79 . V_80 -> V_81 ) ;
return V_76 ;
}
V_4 = F_14 ( V_53 , V_33 , V_82 ) ;
if ( ! V_4 )
return V_83 ;
V_76 = V_74 -> V_84 -> V_85 ( V_4 , V_82 ) ;
if ( V_76 )
goto V_86;
return 0 ;
V_86:
F_5 ( L_5 , V_76 ) ;
F_7 ( V_53 , NULL ) ;
F_8 ( V_4 ) ;
if ( V_76 == - V_23 )
V_53 -> V_44 = V_24 << 16 ;
else
V_53 -> V_44 = V_21 << 16 ;
V_78:
V_53 -> V_52 ( V_53 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_53 )
{
struct V_47 * V_87 = F_27 ( V_53 -> V_61 -> V_72 ) ;
struct V_3 * V_4 = F_28 ( V_53 ) ;
F_1 ( V_53 , V_4 ) ;
F_29 ( V_53 , & V_87 -> V_88 ) ;
}
static void F_30 ( struct V_1 * V_53 )
{
struct V_46 * V_33 = F_21 ( V_53 ) ;
struct V_47 * V_35 = V_33 -> V_34 -> V_35 ;
struct V_3 * V_4 = F_28 ( V_53 ) ;
if ( ! F_22 ( V_33 ) ) {
F_26 ( V_53 ) ;
return;
}
F_1 ( V_53 , V_4 ) ;
F_31 ( & V_53 -> V_89 , & V_35 -> V_90 ) ;
}
static void F_32 ( struct V_91 * V_92 , struct V_1 * V_93 )
{
struct V_1 * V_53 , * V_94 ;
F_33 (cmd, n, error_q, eh_entry) {
if ( V_53 -> V_61 -> V_95 == V_93 -> V_61 -> V_95 &&
V_53 -> V_61 -> V_56 == V_93 -> V_61 -> V_56 )
F_30 ( V_53 ) ;
}
}
static void F_34 ( struct V_91 * V_92 ,
struct V_46 * V_33 )
{
struct V_1 * V_53 , * V_94 ;
F_33 (cmd, n, error_q, eh_entry) {
struct V_46 * V_96 = F_21 ( V_53 ) ;
if ( V_96 == V_33 )
F_26 ( V_53 ) ;
}
}
static void F_35 ( struct V_91 * V_92 ,
struct V_97 * V_34 )
{
struct V_1 * V_53 , * V_94 ;
F_33 (cmd, n, error_q, eh_entry) {
struct V_46 * V_33 = F_21 ( V_53 ) ;
struct V_97 * V_96 = V_33 -> V_34 ;
if ( V_96 == V_34 )
F_26 ( V_53 ) ;
}
}
static enum V_98 F_36 ( struct V_3 * V_4 )
{
unsigned long V_48 ;
int V_74 , V_76 ;
struct V_73 * V_99 =
F_20 ( V_4 -> V_33 -> V_34 -> V_35 -> V_100 . V_101 -> V_75 ) ;
for ( V_74 = 0 ; V_74 < 5 ; V_74 ++ ) {
F_5 ( L_6 , V_102 , V_4 ) ;
V_76 = V_99 -> V_84 -> V_103 ( V_4 ) ;
F_10 ( & V_4 -> V_104 , V_48 ) ;
if ( V_4 -> V_105 & V_106 ) {
F_12 ( & V_4 -> V_104 , V_48 ) ;
F_5 ( L_7 , V_102 ,
V_4 ) ;
return V_107 ;
}
F_12 ( & V_4 -> V_104 , V_48 ) ;
if ( V_76 == V_108 ) {
F_5 ( L_8 ,
V_102 , V_4 ) ;
return V_109 ;
} else if ( V_99 -> V_84 -> V_110 ) {
F_5 ( L_9 ,
V_102 , V_4 ) ;
V_76 = V_99 -> V_84 -> V_110 ( V_4 ) ;
switch ( V_76 ) {
case V_111 :
F_5 ( L_10 ,
V_102 , V_4 ) ;
return V_112 ;
case V_108 :
F_5 ( L_11 ,
V_102 , V_4 ) ;
return V_113 ;
case V_114 :
F_5 ( L_12 ,
V_102 , V_4 ) ;
return V_115 ;
}
}
}
return V_76 ;
}
static int F_37 ( struct V_46 * V_33 , struct V_1 * V_53 )
{
int V_76 = V_114 ;
struct V_55 V_56 ;
struct V_73 * V_74 =
F_20 ( V_33 -> V_34 -> V_35 -> V_100 . V_101 -> V_75 ) ;
F_16 ( V_53 -> V_61 -> V_56 , & V_56 ) ;
F_5 ( L_13 ,
F_38 ( V_33 -> V_116 ) ,
V_53 -> V_61 -> V_56 ) ;
if ( V_74 -> V_84 -> V_117 )
V_76 = V_74 -> V_84 -> V_117 ( V_33 , V_56 . V_55 ) ;
if ( V_76 == V_114 ) {
if ( V_74 -> V_84 -> V_118 )
V_76 = V_74 -> V_84 -> V_118 ( V_33 , V_56 . V_55 ) ;
}
if ( V_76 == V_114 ) {
if ( V_74 -> V_84 -> V_119 )
V_76 = V_74 -> V_84 -> V_119 ( V_33 , V_56 . V_55 ) ;
}
return V_76 ;
}
static int F_39 ( struct V_46 * V_33 )
{
int V_76 = V_114 ;
struct V_73 * V_74 =
F_20 ( V_33 -> V_34 -> V_35 -> V_100 . V_101 -> V_75 ) ;
F_5 ( L_14 ,
F_38 ( V_33 -> V_116 ) ) ;
if ( V_74 -> V_84 -> V_120 )
V_76 = V_74 -> V_84 -> V_120 ( V_33 ) ;
return V_76 ;
}
struct V_121 * F_40 ( struct V_46 * V_33 )
{
struct V_47 * V_35 = V_33 -> V_34 -> V_35 ;
struct V_121 * V_122 ;
unsigned long V_48 ;
F_41 ( ! V_33 -> V_122 ) ;
F_10 ( & V_35 -> V_123 , V_48 ) ;
V_122 = V_33 -> V_122 ;
F_42 ( & V_122 -> V_33 ) ;
F_12 ( & V_35 -> V_123 , V_48 ) ;
return V_122 ;
}
static void F_43 ( struct V_46 * V_33 )
{
struct V_47 * V_35 = V_33 -> V_34 -> V_35 ;
F_44 ( V_124 ) ;
if ( F_22 ( V_33 ) ) {
F_45 ( V_33 -> V_79 . V_80 ) ;
return;
}
V_125:
F_23 ( & V_35 -> V_81 ) ;
while ( F_11 ( V_126 , & V_33 -> V_51 ) ) {
F_46 ( & V_35 -> V_127 , & V_124 , V_128 ) ;
F_25 ( & V_35 -> V_81 ) ;
F_47 () ;
F_23 ( & V_35 -> V_81 ) ;
}
F_48 ( & V_35 -> V_127 , & V_124 ) ;
F_25 ( & V_35 -> V_81 ) ;
if ( F_49 ( V_35 -> V_100 . V_101 ) ) {
F_50 ( 10 ) ;
goto V_125;
}
}
static int F_51 ( struct V_46 * V_33 , int V_129 ,
T_2 V_56 , int V_124 )
{
struct V_47 * V_35 = V_33 -> V_34 -> V_35 ;
int V_130 = 0 , V_131 = 100 ;
if ( F_22 ( V_33 ) ) {
F_52 ( V_33 ) ;
if ( V_124 )
F_53 ( V_33 ) ;
return V_132 ;
}
while ( ! V_130 && V_131 -- ) {
F_23 ( & V_35 -> V_81 ) ;
if ( ! F_11 ( V_126 , & V_33 -> V_51 ) &&
! F_11 ( V_129 , & V_33 -> V_51 ) ) {
V_130 = 1 ;
V_35 -> V_133 ++ ;
F_54 ( & V_33 -> V_134 . V_135 , & V_35 -> V_136 ) ;
F_55 ( V_126 , & V_33 -> V_51 ) ;
F_55 ( V_129 , & V_33 -> V_51 ) ;
F_16 ( V_56 , & V_33 -> V_134 . V_137 ) ;
F_56 ( V_35 -> V_100 . V_101 ) ;
}
F_25 ( & V_35 -> V_81 ) ;
if ( V_124 )
F_43 ( V_33 ) ;
if ( V_130 )
return V_132 ;
}
F_5 ( L_15 ,
V_129 == V_138 ? L_16 : L_17 ,
F_57 ( & V_33 -> V_139 -> V_33 ) ) ;
return V_140 ;
}
int F_58 ( struct V_1 * V_53 )
{
int V_76 ;
struct V_3 * V_4 = F_28 ( V_53 ) ;
struct V_71 * V_72 = V_53 -> V_61 -> V_72 ;
struct V_73 * V_74 = F_20 ( V_72 -> V_75 ) ;
if ( V_141 != V_72 -> V_142 )
return V_140 ;
if ( ! V_74 -> V_84 -> V_103 )
return V_140 ;
V_76 = V_74 -> V_84 -> V_103 ( V_4 ) ;
if ( V_76 == V_111 || V_76 == V_108 )
return V_132 ;
return V_140 ;
}
int F_59 ( struct V_1 * V_53 )
{
int V_76 ;
struct V_55 V_56 ;
struct V_71 * V_72 = V_53 -> V_61 -> V_72 ;
struct V_46 * V_33 = F_21 ( V_53 ) ;
struct V_73 * V_74 = F_20 ( V_72 -> V_75 ) ;
if ( V_141 != V_72 -> V_142 )
return F_51 ( V_33 , V_138 , V_53 -> V_61 -> V_56 , 0 ) ;
F_16 ( V_53 -> V_61 -> V_56 , & V_56 ) ;
if ( ! V_74 -> V_84 -> V_119 )
return V_140 ;
V_76 = V_74 -> V_84 -> V_119 ( V_33 , V_56 . V_55 ) ;
if ( V_76 == V_111 || V_76 == V_108 )
return V_132 ;
return V_140 ;
}
int F_60 ( struct V_1 * V_53 )
{
int V_76 ;
struct V_71 * V_72 = V_53 -> V_61 -> V_72 ;
struct V_46 * V_33 = F_21 ( V_53 ) ;
struct V_73 * V_74 = F_20 ( V_72 -> V_75 ) ;
if ( V_141 != V_72 -> V_142 )
return F_51 ( V_33 , V_143 , 0 , 0 ) ;
if ( ! V_74 -> V_84 -> V_120 )
return V_140 ;
V_76 = V_74 -> V_84 -> V_120 ( V_33 ) ;
if ( V_76 == V_111 || V_76 == V_108 ||
V_76 == - V_144 )
return V_132 ;
return V_140 ;
}
static int F_61 ( struct V_1 * V_53 )
{
int V_76 ;
struct V_71 * V_101 = V_53 -> V_61 -> V_72 ;
if ( ! V_101 -> V_145 -> V_146 )
goto V_147;
V_76 = V_101 -> V_145 -> V_146 ( V_53 ) ;
if ( V_76 == V_132 )
return V_76 ;
V_147:
if ( V_101 -> V_145 -> V_148 )
return V_101 -> V_145 -> V_148 ( V_53 ) ;
return V_140 ;
}
static void F_62 ( struct V_71 * V_101 , struct V_91 * V_149 )
{
struct V_1 * V_53 , * V_94 ;
enum V_98 V_76 = V_107 ;
int V_150 , V_151 ;
struct V_73 * V_74 = F_20 ( V_101 -> V_75 ) ;
unsigned long V_48 ;
struct V_47 * V_35 = F_27 ( V_101 ) ;
F_63 ( V_152 ) ;
F_33 (cmd, n, work_q, eh_entry) {
struct V_46 * V_33 = F_21 ( V_53 ) ;
struct V_3 * V_4 ;
F_10 ( & V_33 -> V_49 , V_48 ) ;
V_4 = F_28 ( V_53 ) ;
F_12 ( & V_33 -> V_49 , V_48 ) ;
if ( ! V_4 )
F_31 ( & V_53 -> V_89 , & V_152 ) ;
}
V_153:
F_33 (cmd, n, work_q, eh_entry) {
struct V_3 * V_4 = F_28 ( V_53 ) ;
F_64 ( & V_53 -> V_89 ) ;
F_10 ( & V_4 -> V_104 , V_48 ) ;
V_151 = V_4 -> V_105 & V_154 ;
F_12 ( & V_4 -> V_104 , V_48 ) ;
if ( V_151 ) {
F_5 ( L_18 ,
V_102 , V_4 ) ;
goto V_155;
}
F_5 ( L_19 , V_4 ) ;
V_76 = F_36 ( V_4 ) ;
V_53 -> V_156 = 0 ;
switch ( V_76 ) {
case V_107 :
F_5 ( L_7 , V_102 ,
V_4 ) ;
F_30 ( V_53 ) ;
continue;
case V_109 :
F_5 ( L_8 ,
V_102 , V_4 ) ;
F_30 ( V_53 ) ;
continue;
case V_112 :
F_5 ( L_20 , V_4 ) ;
V_155:
V_150 = F_37 ( V_4 -> V_33 , V_53 ) ;
if ( V_150 == V_108 ) {
F_5 ( L_21
L_22 ,
F_38 ( V_4 -> V_33 ) ,
V_53 -> V_61 -> V_56 ) ;
F_30 ( V_53 ) ;
F_32 ( V_149 , V_53 ) ;
goto V_153;
}
case V_113 :
case V_115 :
F_5 ( L_23 ,
V_4 ) ;
V_150 = F_39 ( V_4 -> V_33 ) ;
if ( V_150 == V_108 ||
V_150 == - V_144 ) {
struct V_46 * V_33 = V_4 -> V_33 ;
F_5 ( L_24 ,
F_38 ( V_4 -> V_33 -> V_116 ) ) ;
F_26 ( V_53 ) ;
F_34 ( V_149 , V_33 ) ;
goto V_153;
}
F_61 ( V_53 ) ;
if ( V_74 -> V_84 -> V_157 ) {
struct V_97 * V_34 = V_4 -> V_33 -> V_34 ;
F_5 ( L_25 ,
V_34 -> V_158 ) ;
V_76 = V_74 -> V_84 -> V_157 ( V_34 ) ;
if ( V_76 == V_108 ) {
F_5 ( L_26
L_27 , V_34 -> V_158 ) ;
F_26 ( V_53 ) ;
F_35 ( V_149 ,
V_34 ) ;
goto V_153;
}
}
if ( V_74 -> V_84 -> V_159 ) {
F_5 ( L_28 ) ;
V_76 = V_74 -> V_84 -> V_159 ( V_35 ) ;
if ( V_76 == V_108 ) {
F_5 ( L_29
L_27 ) ;
F_26 ( V_53 ) ;
goto V_160;
}
}
F_5 ( L_30
L_31 ,
F_38 ( V_4 -> V_33 -> V_116 ) ,
V_53 -> V_61 -> V_56 ) ;
F_26 ( V_53 ) ;
goto V_160;
}
}
V_161:
F_65 ( & V_152 , V_149 ) ;
F_66 ( & V_35 -> V_90 , V_149 ) ;
return;
V_160:
F_5 ( L_32 , V_102 ) ;
F_33 (cmd, n, work_q, eh_entry)
F_26 ( V_53 ) ;
goto V_161;
}
static void F_67 ( struct V_71 * V_101 )
{
struct V_47 * V_35 = F_27 ( V_101 ) ;
struct V_73 * V_74 = F_20 ( V_101 -> V_75 ) ;
F_23 ( & V_35 -> V_81 ) ;
while ( ! F_68 ( & V_35 -> V_136 ) ) {
struct V_46 * V_33 ;
struct V_162 * V_163 ;
V_163 = F_69 ( V_35 -> V_136 . V_164 , F_70 ( * V_163 ) , V_135 ) ;
F_64 ( & V_163 -> V_135 ) ;
V_33 = F_71 ( V_163 , F_70 ( * V_33 ) , V_134 ) ;
F_72 ( & V_33 -> V_165 ) ;
F_73 ( F_22 ( V_33 ) , L_33 ) ;
F_25 ( & V_35 -> V_81 ) ;
if ( F_74 ( V_138 , & V_33 -> V_51 ) )
V_74 -> V_84 -> V_119 ( V_33 , V_163 -> V_137 . V_55 ) ;
if ( F_74 ( V_143 , & V_33 -> V_51 ) )
V_74 -> V_84 -> V_120 ( V_33 ) ;
F_75 ( V_33 ) ;
F_23 ( & V_35 -> V_81 ) ;
F_76 ( V_126 , & V_33 -> V_51 ) ;
V_35 -> V_133 -- ;
}
F_25 ( & V_35 -> V_81 ) ;
}
void F_77 ( struct V_71 * V_101 )
{
struct V_47 * V_35 = F_27 ( V_101 ) ;
F_63 ( V_166 ) ;
int V_131 = 0 ;
bool V_125 ;
V_125:
V_131 ++ ;
V_125 = true ;
F_23 ( V_101 -> V_167 ) ;
F_78 ( & V_101 -> V_168 , & V_166 ) ;
F_25 ( V_101 -> V_167 ) ;
F_5 ( L_34 ,
V_102 , F_79 ( & V_101 -> V_169 ) , V_101 -> V_170 ) ;
F_55 ( V_50 , & V_35 -> V_51 ) ;
F_62 ( V_101 , & V_166 ) ;
F_76 ( V_50 , & V_35 -> V_51 ) ;
if ( F_68 ( & V_166 ) )
goto V_161;
F_80 ( V_101 , & V_166 , & V_35 -> V_88 ) ;
if ( ! F_81 ( & V_166 , & V_35 -> V_88 ) )
F_82 ( V_101 , & V_166 , & V_35 -> V_88 ) ;
V_161:
F_67 ( V_101 ) ;
F_83 ( V_101 ) ;
F_84 ( & V_35 -> V_88 ) ;
F_23 ( & V_35 -> V_81 ) ;
if ( V_35 -> V_133 == 0 ) {
V_101 -> V_171 = 0 ;
V_125 = false ;
}
F_25 ( & V_35 -> V_81 ) ;
if ( V_125 )
goto V_125;
F_5 ( L_35 ,
V_102 , F_79 ( & V_101 -> V_169 ) ,
V_101 -> V_170 , V_131 ) ;
}
int F_85 ( struct V_172 * V_173 , int V_53 , void T_3 * V_174 )
{
struct V_46 * V_33 = F_86 ( V_173 ) ;
if ( F_22 ( V_33 ) )
return F_87 ( V_33 -> V_79 . V_80 , V_173 , V_53 , V_174 ) ;
return - V_175 ;
}
struct V_46 * F_88 ( struct V_176 * V_139 )
{
struct V_71 * V_101 = F_89 ( V_139 -> V_33 . V_177 ) ;
struct V_47 * V_35 = F_27 ( V_101 ) ;
struct V_46 * V_178 = NULL ;
int V_74 ;
unsigned long V_48 ;
F_10 ( & V_35 -> V_123 , V_48 ) ;
for ( V_74 = 0 ; V_74 < V_35 -> V_179 ; V_74 ++ ) {
struct V_97 * V_34 = V_35 -> V_180 [ V_74 ] ;
struct V_46 * V_33 ;
F_90 ( & V_34 -> V_181 ) ;
F_91 (dev, &port->dev_list, dev_list_node) {
if ( V_139 == V_33 -> V_139 ) {
V_178 = V_33 ;
F_92 ( & V_34 -> V_181 ) ;
goto V_182;
}
}
F_92 ( & V_34 -> V_181 ) ;
}
V_182:
F_12 ( & V_35 -> V_123 , V_48 ) ;
return V_178 ;
}
int F_93 ( struct V_183 * V_184 )
{
struct V_176 * V_139 = F_94 ( V_184 -> V_33 . V_177 ) ;
struct V_46 * V_178 = F_88 ( V_139 ) ;
if ( ! V_178 )
return - V_144 ;
F_72 ( & V_178 -> V_165 ) ;
V_184 -> V_185 = V_178 ;
return 0 ;
}
int F_95 ( struct V_172 * V_186 )
{
struct V_46 * V_33 = F_86 ( V_186 ) ;
struct V_47 * V_87 ;
F_41 ( V_33 -> V_139 -> V_187 . V_188 != V_189 ) ;
if ( F_22 ( V_33 ) ) {
F_96 ( V_186 , V_33 -> V_79 . V_80 ) ;
return 0 ;
}
V_87 = V_33 -> V_34 -> V_35 ;
F_97 ( V_186 ) ;
if ( V_186 -> V_190 ) {
F_98 ( V_186 , V_191 ) ;
} else {
F_5 ( L_36
L_37 , F_38 ( V_33 -> V_116 ) ,
V_186 -> V_56 ) ;
F_98 ( V_186 , 1 ) ;
}
V_186 -> V_192 = 1 ;
return 0 ;
}
int F_99 ( struct V_172 * V_173 , int V_193 )
{
struct V_46 * V_33 = F_86 ( V_173 ) ;
if ( F_22 ( V_33 ) )
return F_100 ( V_33 -> V_79 . V_80 , V_173 , V_193 ) ;
if ( ! V_173 -> V_190 )
V_193 = 1 ;
return F_98 ( V_173 , V_193 ) ;
}
int F_101 ( struct V_172 * V_186 ,
struct V_194 * V_195 ,
T_4 V_196 , int * V_197 )
{
V_197 [ 0 ] = 255 ;
V_197 [ 1 ] = 63 ;
F_102 ( V_196 , 255 * 63 ) ;
V_197 [ 2 ] = V_196 ;
return 0 ;
}
void F_103 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_45 ;
if ( ! V_2 ) {
struct V_198 * V_199 = V_4 -> V_200 ;
if ( ! V_199 )
return;
if ( ! F_104 ( & V_199 -> V_201 ) )
return;
V_199 -> V_201 . V_202 ( V_199 -> V_201 . V_203 ) ;
return;
}
if ( F_22 ( V_4 -> V_33 ) ) {
F_105 ( V_4 ) ;
} else {
struct V_204 * V_205 = V_2 -> V_61 -> V_204 ;
unsigned long V_48 ;
F_10 ( V_205 -> V_206 , V_48 ) ;
F_106 ( V_2 -> V_207 ) ;
F_12 ( V_205 -> V_206 , V_48 ) ;
}
}
void F_107 ( struct V_183 * V_184 )
{
struct V_46 * V_178 = V_184 -> V_185 ;
if ( ! V_178 )
return;
V_184 -> V_185 = NULL ;
F_75 ( V_178 ) ;
}
static void F_108 ( T_5 * V_116 , const char * V_208 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_209 ; V_74 ++ ) {
T_5 V_210 , V_211 ;
if ( ! * V_208 )
break;
V_210 = isdigit ( * V_208 ) ? * V_208 - '0' : toupper ( * V_208 ) - 'A' + 10 ;
V_208 ++ ;
V_211 = isdigit ( * V_208 ) ? * V_208 - '0' : toupper ( * V_208 ) - 'A' + 10 ;
V_208 ++ ;
V_116 [ V_74 ] = ( V_210 << 4 ) | V_211 ;
}
}
int F_109 ( struct V_71 * V_101 , T_5 * V_212 )
{
int V_76 ;
const struct V_213 * V_214 ;
V_76 = F_110 ( & V_214 , L_38 , & V_101 -> V_215 ) ;
if ( V_76 )
return V_76 ;
if ( V_214 -> V_216 < V_217 ) {
V_76 = - V_144 ;
goto V_161;
}
F_108 ( V_212 , V_214 -> V_203 ) ;
V_161:
F_111 ( V_214 ) ;
return V_76 ;
}
