static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 ) {
F_3 ( L_1 ) ;
return NULL ;
}
V_3 -> V_4 = V_4 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_6 = 1 ;
V_4 -> V_7 = F_2 ( V_8 , V_5 ) ;
if ( ! V_4 -> V_7 ) {
F_3 ( L_2 ) ;
goto V_9;
}
V_4 -> V_10 = F_2 ( V_8 , V_5 ) ;
if ( ! V_4 -> V_10 ) {
F_3 ( L_3 ) ;
goto V_11;
}
V_3 -> V_12 = F_2 ( sizeof( struct V_13 ) , V_5 ) ;
if ( ! V_3 -> V_12 ) {
F_3 ( L_4
L_5 ) ;
goto V_14;
}
F_4 ( & V_3 -> V_15 ) ;
F_5 ( & V_3 -> V_16 ) ;
F_5 ( & V_3 -> V_17 ) ;
F_5 ( & V_3 -> V_18 ) ;
F_5 ( & V_3 -> V_19 ) ;
F_6 ( & V_3 -> V_20 ) ;
F_6 ( & V_3 -> V_21 ) ;
F_6 ( & V_3 -> V_22 ) ;
F_6 ( & V_3 -> V_23 ) ;
F_6 ( & V_3 -> V_24 ) ;
F_6 ( & V_3 -> V_25 ) ;
F_6 ( & V_3 -> V_26 ) ;
F_7 ( & V_3 -> V_27 ) ;
F_7 ( & V_3 -> V_28 ) ;
F_7 ( & V_3 -> V_29 ) ;
F_7 ( & V_3 -> V_30 ) ;
F_7 ( & V_3 -> V_31 ) ;
F_7 ( & V_3 -> V_32 ) ;
if ( ! F_8 ( & V_3 -> V_33 , V_5 ) ) {
F_3 ( L_6 ) ;
goto V_34;
}
V_3 -> V_35 = V_4 ;
return V_4 ;
V_34:
F_9 ( V_3 -> V_12 ) ;
V_14:
F_9 ( V_4 -> V_10 ) ;
V_11:
F_9 ( V_4 -> V_7 ) ;
V_9:
F_9 ( V_4 ) ;
return NULL ;
}
int F_10 ( struct V_2 * V_3 )
{
V_3 -> V_36 . V_37 = 0 ;
V_3 -> V_36 . V_38 = F_11 ( L_7 , 0 ,
V_39 ) ;
if ( F_12 ( V_3 -> V_36 . V_38 ) ) {
F_3 ( L_8 ) ;
return - V_40 ;
}
V_3 -> V_41 . V_37 = 0 ;
V_3 -> V_41 . V_38 = F_11 ( L_7 , 0 ,
V_39 ) ;
if ( F_12 ( V_3 -> V_41 . V_38 ) ) {
F_3 ( L_9 ) ;
F_13 ( V_3 -> V_36 . V_38 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_14 (
struct V_2 * V_3 ,
T_1 V_42 ,
T_1 V_43 )
{
if ( ( V_42 != 0x00 ) || ( V_43 != 0x00 ) ) {
F_3 ( L_10
L_11 ,
V_43 , V_42 ) ;
F_15 ( V_3 , V_44 ,
V_45 ) ;
return - 1 ;
}
return 0 ;
}
int F_16 ( struct V_2 * V_3 )
{
int V_46 ;
struct V_47 * V_48 = NULL , * V_49 = NULL ;
struct V_50 * V_51 = V_3 -> V_51 ;
struct V_52 * V_53 = NULL , * V_54 = NULL ;
struct V_55 * V_56 = & V_51 -> V_57 ;
struct V_58 * V_59 , * V_60 ;
V_48 = F_17 (
V_61 , V_3 -> V_62 ) ;
V_49 = F_17 (
V_63 , V_3 -> V_62 ) ;
if ( ! V_48 || ! V_49 ) {
F_15 ( V_3 , V_44 ,
V_64 ) ;
return - 1 ;
}
V_46 = ( strncmp ( V_49 -> V_65 , V_66 , 6 ) ) ? 1 : 0 ;
F_18 ( & V_56 -> V_67 ) ;
F_19 (se_sess, se_sess_tmp, &se_tpg->tpg_sess_list,
sess_list) {
V_54 = V_59 -> V_68 ;
F_20 ( & V_54 -> V_69 ) ;
if ( F_21 ( & V_54 -> V_70 ) ||
F_21 ( & V_54 -> V_71 ) ||
( V_54 -> V_72 & V_73 ) ) {
F_22 ( & V_54 -> V_69 ) ;
continue;
}
if ( ! memcmp ( V_54 -> V_74 , V_3 -> V_53 -> V_74 , 6 ) &&
( ! strcmp ( V_54 -> V_75 -> V_76 ,
V_48 -> V_65 ) &&
( V_54 -> V_75 -> V_77 == V_46 ) ) ) {
F_23 ( & V_54 -> V_78 , 1 ) ;
F_22 ( & V_54 -> V_69 ) ;
F_24 ( V_54 ) ;
F_25 ( V_54 ) ;
V_53 = V_54 ;
break;
}
F_22 ( & V_54 -> V_69 ) ;
}
F_26 ( & V_56 -> V_67 ) ;
if ( ! V_53 )
return 0 ;
F_27 ( L_12
L_13 , ( V_46 ) ?
L_14 : L_15 , V_53 -> V_79 ,
V_53 -> V_75 -> V_76 ) ;
F_18 ( & V_53 -> V_69 ) ;
if ( V_53 -> V_80 == V_81 ) {
F_26 ( & V_53 -> V_69 ) ;
F_28 ( V_53 ) ;
F_29 ( V_53 -> V_59 ) ;
return 0 ;
}
F_26 ( & V_53 -> V_69 ) ;
F_30 ( V_53 , 1 , 1 ) ;
F_28 ( V_53 ) ;
F_29 ( V_53 -> V_59 ) ;
return 0 ;
}
static void F_31 (
struct V_52 * V_53 ,
struct V_2 * V_3 ,
T_2 V_82 )
{
V_3 -> V_53 = V_53 ;
V_3 -> V_82 = F_32 ( V_82 ) ;
F_33 ( & V_3 -> V_83 , sizeof( V_84 ) ) ;
F_34 ( & V_85 ) ;
V_3 -> V_86 = V_87 -> V_86 ++ ;
F_35 ( & V_85 ) ;
}
int F_36 (
struct V_2 * V_3 ,
unsigned char * V_88 )
{
struct V_52 * V_53 = NULL ;
struct V_89 * V_90 = (struct V_89 * ) V_88 ;
int V_91 ;
V_53 = F_2 ( sizeof( struct V_52 ) , V_5 ) ;
if ( ! V_53 ) {
F_15 ( V_3 , V_92 ,
V_93 ) ;
F_3 ( L_16 ) ;
return - V_40 ;
}
F_31 ( V_53 , V_3 , V_90 -> V_82 ) ;
V_53 -> V_94 = V_90 -> V_95 ;
memcpy ( & V_53 -> V_74 , V_90 -> V_74 , 6 ) ;
V_53 -> V_96 = F_37 ( V_90 -> V_97 ) ;
F_5 ( & V_53 -> V_98 ) ;
F_5 ( & V_53 -> V_99 ) ;
F_5 ( & V_53 -> V_100 ) ;
F_5 ( & V_53 -> V_101 ) ;
F_6 ( & V_53 -> V_102 ) ;
F_6 ( & V_53 -> V_103 ) ;
F_6 ( & V_53 -> V_104 ) ;
F_6 ( & V_53 -> V_105 ) ;
F_38 ( & V_53 -> V_106 ) ;
F_7 ( & V_53 -> V_69 ) ;
F_7 ( & V_53 -> V_107 ) ;
F_7 ( & V_53 -> V_108 ) ;
F_7 ( & V_53 -> V_109 ) ;
F_7 ( & V_53 -> V_110 ) ;
F_39 ( V_5 ) ;
F_18 ( & V_111 ) ;
V_91 = F_40 ( & V_112 , NULL , 0 , 0 , V_113 ) ;
if ( V_91 >= 0 )
V_53 -> V_114 = V_91 ;
F_26 ( & V_111 ) ;
F_41 () ;
if ( V_91 < 0 ) {
F_3 ( L_17 ) ;
F_15 ( V_3 , V_92 ,
V_93 ) ;
F_9 ( V_53 ) ;
return - V_40 ;
}
V_53 -> V_115 = F_42 () ;
V_53 -> V_116 = F_37 ( V_90 -> V_97 ) ;
V_53 -> V_75 = F_2 ( sizeof( struct V_117 ) , V_5 ) ;
if ( ! V_53 -> V_75 ) {
F_15 ( V_3 , V_92 ,
V_93 ) ;
F_3 ( L_4
L_18 ) ;
F_9 ( V_53 ) ;
return - V_40 ;
}
V_53 -> V_59 = F_43 ( V_118 ) ;
if ( F_12 ( V_53 -> V_59 ) ) {
F_15 ( V_3 , V_92 ,
V_93 ) ;
F_9 ( V_53 -> V_75 ) ;
F_9 ( V_53 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_44 (
struct V_2 * V_3 )
{
struct V_119 * V_120 ;
struct V_52 * V_53 = V_3 -> V_53 ;
bool V_121 = false ;
V_53 -> V_51 = V_3 -> V_51 ;
V_53 -> V_122 = ++ V_53 -> V_51 -> V_123 ;
if ( ! V_53 -> V_122 )
V_53 -> V_122 = ++ V_53 -> V_51 -> V_123 ;
if ( F_45 ( & V_3 -> V_62 ,
V_3 -> V_51 -> V_62 , 1 ) < 0 ) {
F_15 ( V_3 , V_92 ,
V_93 ) ;
return - 1 ;
}
if ( V_3 -> V_124 -> V_125 == V_126 )
V_121 = true ;
F_46 ( V_3 -> V_62 , V_121 ) ;
if ( V_53 -> V_75 -> V_77 )
return F_47 (
V_3 -> V_62 ) ;
V_120 = F_48 ( V_53 ) ;
if ( F_49 ( V_3 , L_19 , V_53 -> V_51 -> V_127 ) )
return - 1 ;
if ( F_49 ( V_3 , L_20 , V_120 -> V_128 ) )
return - 1 ;
if ( F_50 ( V_3 -> V_62 , V_3 ) < 0 )
return - 1 ;
if ( V_121 ) {
struct V_47 * V_129 ;
unsigned long V_130 , V_131 ;
int V_132 ;
if ( F_49 ( V_3 , L_21 ) )
return - 1 ;
V_129 = F_17 ( L_22 ,
V_3 -> V_62 ) ;
if ( ! V_129 ) {
F_15 ( V_3 , V_92 ,
V_93 ) ;
return - 1 ;
}
V_132 = F_51 ( V_129 -> V_65 , 0 , & V_130 ) ;
if ( V_132 < 0 ) {
F_15 ( V_3 , V_92 ,
V_93 ) ;
return - 1 ;
}
V_131 = V_130 % V_133 ;
if ( ! V_131 )
goto V_134;
if ( V_130 < V_133 )
V_130 = V_133 ;
else
V_130 -= V_131 ;
F_52 ( L_23
L_24 , V_130 ) ;
if ( F_49 ( V_3 , L_25 , V_130 ) )
return - 1 ;
V_134:
if ( V_53 -> V_59 -> V_135 &
( V_136 | V_137 |
V_138 ) ) {
if ( F_49 ( V_3 , L_26 ) )
return - 1 ;
if ( F_49 ( V_3 , L_27 ) )
return - 1 ;
F_27 ( L_28
L_29 ) ;
}
}
return 0 ;
}
int F_50 (
struct V_139 * V_62 ,
struct V_2 * V_3 )
{
struct V_47 * V_129 ;
V_129 = F_17 ( L_30 , V_62 ) ;
if ( ! V_129 ) {
F_3 ( L_31
L_32 ) ;
F_15 ( V_3 , V_92 ,
V_93 ) ;
return - 1 ;
}
V_129 -> V_140 &= ~ V_141 ;
V_129 = F_17 ( L_33 , V_62 ) ;
if ( ! V_129 ) {
F_3 ( L_31
L_34 ) ;
F_15 ( V_3 , V_92 ,
V_93 ) ;
return - 1 ;
}
V_129 -> V_140 &= ~ V_141 ;
V_129 = F_17 ( L_35 , V_62 ) ;
if ( ! V_129 ) {
F_3 ( L_31
L_34 ) ;
F_15 ( V_3 , V_92 ,
V_93 ) ;
return - 1 ;
}
V_129 -> V_140 &= ~ V_141 ;
V_129 = F_17 ( L_36 , V_62 ) ;
if ( ! V_129 ) {
F_3 ( L_31
L_34 ) ;
F_15 ( V_3 , V_92 ,
V_93 ) ;
return - 1 ;
}
V_129 -> V_140 &= ~ V_141 ;
return 0 ;
}
static int F_53 (
struct V_2 * V_3 ,
unsigned char * V_88 )
{
struct V_89 * V_90 = (struct V_89 * ) V_88 ;
F_31 ( NULL , V_3 , V_90 -> V_82 ) ;
return 0 ;
}
static int F_54 (
struct V_2 * V_3 ,
unsigned char * V_88 )
{
struct V_50 * V_51 = V_3 -> V_51 ;
struct V_52 * V_53 = NULL , * V_54 = NULL ;
struct V_55 * V_56 = & V_51 -> V_57 ;
struct V_58 * V_59 , * V_60 ;
struct V_89 * V_90 = (struct V_89 * ) V_88 ;
bool V_121 = false ;
F_18 ( & V_56 -> V_67 ) ;
F_19 (se_sess, se_sess_tmp, &se_tpg->tpg_sess_list,
sess_list) {
V_54 = (struct V_52 * ) V_59 -> V_68 ;
if ( F_21 ( & V_54 -> V_70 ) ||
F_21 ( & V_54 -> V_71 ) ||
( V_54 -> V_72 & V_73 ) )
continue;
if ( ! memcmp ( V_54 -> V_74 , V_90 -> V_74 , 6 ) &&
( V_54 -> V_122 == F_32 ( V_90 -> V_122 ) ) ) {
F_24 ( V_54 ) ;
F_25 ( V_54 ) ;
V_53 = V_54 ;
break;
}
}
F_26 ( & V_56 -> V_67 ) ;
if ( ! V_53 ) {
F_3 ( L_37
L_38 ) ;
F_15 ( V_3 , V_44 ,
V_142 ) ;
return - 1 ;
}
F_18 ( & V_53 -> V_69 ) ;
if ( V_53 -> V_80 == V_81 )
F_23 ( & V_53 -> V_143 , 1 ) ;
F_26 ( & V_53 -> V_69 ) ;
F_31 ( V_53 , V_3 , V_90 -> V_82 ) ;
if ( F_45 ( & V_3 -> V_62 ,
V_3 -> V_51 -> V_62 , 0 ) < 0 ) {
F_15 ( V_3 , V_92 ,
V_93 ) ;
return - 1 ;
}
if ( V_3 -> V_124 -> V_125 == V_126 )
V_121 = true ;
F_46 ( V_3 -> V_62 , V_121 ) ;
if ( F_49 ( V_3 , L_19 , V_53 -> V_51 -> V_127 ) )
return - 1 ;
return F_50 ( V_3 -> V_62 , V_3 ) ;
}
int F_55 (
struct V_2 * V_3 ,
T_3 V_82 ,
V_84 V_144 )
{
struct V_2 * V_145 = NULL ;
struct V_146 * V_147 = NULL ;
struct V_52 * V_53 = V_3 -> V_53 ;
V_145 = F_56 ( V_53 , V_82 ) ;
if ( V_145 ) {
F_3 ( L_39
L_40 ,
V_145 -> V_82 , V_53 -> V_75 -> V_76 ) ;
F_57 ( V_145 ) ;
F_58 ( V_145 ) ;
}
if ( V_53 -> V_75 -> V_148 == 2 ) {
V_147 = F_59 (
V_53 , V_82 ) ;
if ( V_147 ) {
F_27 ( L_41
L_42 ,
V_3 -> V_82 ) ;
F_60 ( V_147 , V_144 ) ;
}
}
F_27 ( L_43 ,
V_82 , V_53 -> V_75 -> V_76 ) ;
if ( ( F_21 ( & V_53 -> V_149 ) + 1 ) > V_53 -> V_75 -> V_150 ) {
F_3 ( L_44
L_45 ,
V_53 -> V_75 -> V_150 ) ;
F_15 ( V_3 , V_44 ,
V_151 ) ;
return - 1 ;
}
return 0 ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_52 * V_53 = V_3 -> V_53 ;
if ( V_3 -> V_124 -> V_125 == V_126 )
return;
if ( ! V_53 -> V_75 -> V_77 )
F_62 ( V_3 ) ;
}
static int F_63 ( struct V_2 * V_3 )
{
int V_91 = 0 ;
F_20 ( & V_87 -> V_152 ) ;
V_3 -> V_153 = F_64 ( V_87 -> V_154 ,
V_155 , F_65 ( 1 ) ) ;
F_22 ( & V_87 -> V_152 ) ;
if ( V_3 -> V_153 < 0 ) {
F_3 ( L_46
L_47 ) ;
return - V_40 ;
}
V_3 -> V_156 = F_66 ( V_157 , V_3 ,
L_48 , V_158 ) ;
if ( F_12 ( V_3 -> V_156 ) ) {
F_3 ( L_49 ) ;
V_91 = F_67 ( V_3 -> V_156 ) ;
goto V_159;
}
V_3 -> V_160 = true ;
V_3 -> V_161 = F_66 ( V_162 , V_3 ,
L_48 , V_163 ) ;
if ( F_12 ( V_3 -> V_161 ) ) {
F_3 ( L_50 ) ;
V_91 = F_67 ( V_3 -> V_161 ) ;
goto V_164;
}
V_3 -> V_165 = true ;
return 0 ;
V_164:
F_68 ( V_3 -> V_156 ) ;
V_3 -> V_160 = false ;
V_159:
F_20 ( & V_87 -> V_152 ) ;
F_69 ( V_87 -> V_154 , V_3 -> V_153 ,
F_65 ( 1 ) ) ;
F_22 ( & V_87 -> V_152 ) ;
return V_91 ;
}
int F_70 (
struct V_166 * V_167 ,
struct V_2 * V_3 ,
T_1 V_168 )
{
int V_169 = 0 ;
struct V_52 * V_53 = V_3 -> V_53 ;
struct V_58 * V_59 = V_53 -> V_59 ;
struct V_50 * V_51 = V_53 -> V_51 ;
struct V_55 * V_56 = & V_51 -> V_57 ;
int V_132 ;
F_71 ( V_3 ) ;
F_72 ( V_3 , V_170 ,
V_171 ) ;
F_27 ( L_51 ) ;
V_3 -> V_172 = V_173 ;
F_73 ( V_3 -> V_12 , V_3 -> V_62 ) ;
F_74 ( V_3 ) ;
if ( ! V_168 ) {
F_75 ( V_53 -> V_75 ,
V_3 -> V_62 , 0 ) ;
F_76 ( V_3 -> V_62 ) ;
V_3 -> V_62 = NULL ;
F_18 ( & V_53 -> V_69 ) ;
F_23 ( & V_53 -> V_143 , 0 ) ;
if ( V_53 -> V_80 == V_81 ) {
F_27 ( L_52
L_53 ) ;
V_53 -> V_80 = V_174 ;
V_169 = 1 ;
}
F_27 ( L_54
L_55 , V_3 -> V_82 , V_3 -> V_175 ,
V_3 -> V_176 , V_3 -> V_177 , V_51 -> V_127 ) ;
F_77 ( & V_3 -> V_16 , & V_53 -> V_98 ) ;
F_78 ( & V_53 -> V_149 ) ;
F_27 ( L_56
L_57 , F_21 ( & V_53 -> V_149 ) ,
V_53 -> V_75 -> V_76 ) ;
F_26 ( & V_53 -> V_69 ) ;
V_132 = F_63 ( V_3 ) ;
if ( V_132 )
return V_132 ;
F_61 ( V_3 ) ;
F_79 ( V_3 ) ;
V_3 -> V_178 = 1 ;
V_3 -> V_179 = 1 ;
F_58 ( V_3 ) ;
if ( V_169 ) {
F_18 ( & V_56 -> V_67 ) ;
F_25 ( V_53 ) ;
F_26 ( & V_56 -> V_67 ) ;
}
F_28 ( V_53 ) ;
return 0 ;
}
F_75 ( V_53 -> V_75 , V_3 -> V_62 , 1 ) ;
F_76 ( V_3 -> V_62 ) ;
V_3 -> V_62 = NULL ;
F_80 ( V_53 ) ;
F_18 ( & V_56 -> V_67 ) ;
F_81 ( & V_53 -> V_51 -> V_57 ,
V_59 -> V_180 , V_59 , V_53 ) ;
F_27 ( L_58 ) ;
V_53 -> V_80 = V_174 ;
F_27 ( L_59 ,
V_3 -> V_82 , V_3 -> V_175 , V_3 -> V_176 , V_3 -> V_177 ,
V_51 -> V_127 ) ;
F_18 ( & V_53 -> V_69 ) ;
F_77 ( & V_3 -> V_16 , & V_53 -> V_98 ) ;
F_78 ( & V_53 -> V_149 ) ;
F_27 ( L_60
L_61 , F_21 ( & V_53 -> V_149 ) ,
V_53 -> V_75 -> V_76 ) ;
F_26 ( & V_53 -> V_69 ) ;
V_53 -> V_79 = V_51 -> V_79 ++ ;
if ( ! V_53 -> V_79 )
V_53 -> V_79 = V_51 -> V_79 ++ ;
F_27 ( L_62 ,
V_53 -> V_75 -> V_76 ) ;
V_51 -> V_181 ++ ;
if ( V_51 -> V_182 )
V_51 -> V_182 -> V_183 ++ ;
F_27 ( L_63
L_64 , V_51 -> V_181 , V_51 -> V_127 ) ;
F_26 ( & V_56 -> V_67 ) ;
V_132 = F_63 ( V_3 ) ;
if ( V_132 )
return V_132 ;
F_61 ( V_3 ) ;
F_79 ( V_3 ) ;
V_3 -> V_178 = 1 ;
V_3 -> V_179 = 1 ;
F_58 ( V_3 ) ;
return 0 ;
}
static void F_82 ( unsigned long V_184 )
{
struct V_166 * V_167 = (struct V_166 * ) V_184 ;
F_18 ( & V_167 -> V_185 ) ;
F_3 ( L_65 ,
V_167 -> V_186 , V_167 -> V_187 ) ;
if ( V_167 -> V_188 & V_189 ) {
F_26 ( & V_167 -> V_185 ) ;
return;
}
if ( V_167 -> V_190 )
F_83 ( V_191 , V_167 -> V_190 , 1 ) ;
V_167 -> V_188 &= ~ V_192 ;
F_26 ( & V_167 -> V_185 ) ;
}
static void F_84 ( struct V_166 * V_167 )
{
F_18 ( & V_167 -> V_185 ) ;
F_85 ( & V_167 -> V_193 ) ;
V_167 -> V_193 . V_194 = ( F_42 () + V_195 * V_196 ) ;
V_167 -> V_193 . V_184 = ( unsigned long ) V_167 ;
V_167 -> V_193 . V_197 = F_82 ;
V_167 -> V_188 &= ~ V_189 ;
V_167 -> V_188 |= V_192 ;
F_86 ( & V_167 -> V_193 ) ;
F_27 ( L_66
L_67 , V_195 ) ;
F_26 ( & V_167 -> V_185 ) ;
}
static void F_87 ( struct V_166 * V_167 )
{
F_18 ( & V_167 -> V_185 ) ;
if ( ! ( V_167 -> V_188 & V_192 ) ) {
F_26 ( & V_167 -> V_185 ) ;
return;
}
V_167 -> V_188 |= V_189 ;
F_26 ( & V_167 -> V_185 ) ;
F_88 ( & V_167 -> V_193 ) ;
F_18 ( & V_167 -> V_185 ) ;
V_167 -> V_188 &= ~ V_192 ;
F_26 ( & V_167 -> V_185 ) ;
}
int F_89 (
struct V_166 * V_167 ,
struct V_198 * V_199 )
{
struct V_200 * V_201 = NULL ;
int V_202 = V_203 , V_91 , V_204 = 0 , V_205 ;
switch ( V_167 -> V_206 ) {
case V_207 :
V_167 -> V_208 = V_209 ;
V_167 -> V_210 = V_211 ;
break;
case V_212 :
V_167 -> V_208 = V_213 ;
V_167 -> V_210 = V_211 ;
break;
case V_214 :
V_167 -> V_208 = V_213 ;
V_167 -> V_210 = V_215 ;
break;
default:
F_3 ( L_68 ,
V_167 -> V_206 ) ;
return - V_216 ;
}
V_167 -> V_208 = V_209 ;
V_167 -> V_210 = V_211 ;
V_91 = F_90 ( V_199 -> V_217 , V_167 -> V_210 ,
V_167 -> V_208 , & V_201 ) ;
if ( V_91 < 0 ) {
F_3 ( L_69 ) ;
return V_91 ;
}
V_167 -> V_218 = V_201 ;
memcpy ( & V_167 -> V_219 , V_199 ,
sizeof( struct V_198 ) ) ;
if ( V_199 -> V_217 == V_220 )
V_205 = sizeof( struct V_221 ) ;
else
V_205 = sizeof( struct V_222 ) ;
V_204 = 1 ;
if ( V_167 -> V_206 == V_207 ) {
V_91 = F_91 ( V_201 , V_209 , V_223 ,
( char * ) & V_204 , sizeof( V_204 ) ) ;
if ( V_91 < 0 ) {
F_3 ( L_70
L_71 , V_91 ) ;
goto V_224;
}
}
V_91 = F_91 ( V_201 , V_225 , V_226 ,
( char * ) & V_204 , sizeof( V_204 ) ) ;
if ( V_91 < 0 ) {
F_3 ( L_72
L_73 ) ;
goto V_224;
}
V_91 = F_91 ( V_201 , V_227 , V_228 ,
( char * ) & V_204 , sizeof( V_204 ) ) ;
if ( V_91 < 0 ) {
F_3 ( L_74
L_73 ) ;
goto V_224;
}
V_91 = F_92 ( V_201 , (struct V_199 * ) & V_167 -> V_219 , V_205 ) ;
if ( V_91 < 0 ) {
F_3 ( L_75 , V_91 ) ;
goto V_224;
}
V_91 = F_93 ( V_201 , V_202 ) ;
if ( V_91 != 0 ) {
F_3 ( L_76 , V_91 ) ;
goto V_224;
}
return 0 ;
V_224:
V_167 -> V_218 = NULL ;
F_94 ( V_201 ) ;
return V_91 ;
}
int F_95 (
struct V_166 * V_167 ,
struct V_198 * V_199 )
{
struct V_229 * V_230 ;
int V_132 ;
V_230 = F_96 ( V_167 -> V_206 ) ;
if ( ! V_230 )
return - V_216 ;
V_132 = V_230 -> F_89 ( V_167 , V_199 ) ;
if ( V_132 < 0 ) {
F_97 ( V_230 ) ;
return V_132 ;
}
V_167 -> V_231 = V_230 ;
V_167 -> V_232 = true ;
return 0 ;
}
int F_98 ( struct V_166 * V_167 , struct V_2 * V_3 )
{
struct V_200 * V_233 , * V_201 = V_167 -> V_218 ;
struct V_222 V_234 ;
struct V_221 V_235 ;
int V_132 , V_236 ;
V_132 = F_99 ( V_201 , & V_233 , 0 ) ;
if ( V_132 < 0 )
return V_132 ;
V_3 -> V_201 = V_233 ;
V_3 -> V_237 = V_167 -> V_219 . V_217 ;
if ( V_167 -> V_219 . V_217 == V_220 ) {
memset ( & V_235 , 0 , sizeof( struct V_221 ) ) ;
V_132 = V_3 -> V_201 -> V_238 -> V_239 ( V_3 -> V_201 ,
(struct V_199 * ) & V_235 , & V_236 , 1 ) ;
if ( ! V_132 ) {
if ( ! F_100 ( & V_235 . V_240 ) )
snprintf ( V_3 -> V_175 , sizeof( V_3 -> V_175 ) , L_77 ,
& V_235 . V_240 . V_241 ) ;
else
snprintf ( V_3 -> V_175 , sizeof( V_3 -> V_175 ) , L_78 ,
& V_235 . V_240 . V_242 [ 3 ] ) ;
V_3 -> V_243 = F_101 ( V_235 . V_244 ) ;
}
V_132 = V_3 -> V_201 -> V_238 -> V_239 ( V_3 -> V_201 ,
(struct V_199 * ) & V_235 , & V_236 , 0 ) ;
if ( ! V_132 ) {
if ( ! F_100 ( & V_235 . V_240 ) )
snprintf ( V_3 -> V_176 , sizeof( V_3 -> V_176 ) , L_77 ,
& V_235 . V_240 . V_241 ) ;
else
snprintf ( V_3 -> V_176 , sizeof( V_3 -> V_176 ) , L_78 ,
& V_235 . V_240 . V_242 [ 3 ] ) ;
V_3 -> V_177 = F_101 ( V_235 . V_244 ) ;
}
} else {
memset ( & V_234 , 0 , sizeof( struct V_222 ) ) ;
V_132 = V_3 -> V_201 -> V_238 -> V_239 ( V_3 -> V_201 ,
(struct V_199 * ) & V_234 , & V_236 , 1 ) ;
if ( ! V_132 ) {
sprintf ( V_3 -> V_175 , L_78 ,
& V_234 . V_245 . V_246 ) ;
V_3 -> V_243 = F_101 ( V_234 . V_247 ) ;
}
V_132 = V_3 -> V_201 -> V_238 -> V_239 ( V_3 -> V_201 ,
(struct V_199 * ) & V_234 , & V_236 , 0 ) ;
if ( ! V_132 ) {
sprintf ( V_3 -> V_176 , L_78 ,
& V_234 . V_245 . V_246 ) ;
V_3 -> V_177 = F_101 ( V_234 . V_247 ) ;
}
}
return 0 ;
}
int F_102 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_89 * V_248 ;
V_84 V_249 = 0 , V_250 ;
if ( F_103 ( V_3 , V_4 -> V_251 , V_252 ) < 0 )
return - 1 ;
V_248 = (struct V_89 * ) V_4 -> V_251 ;
V_250 = F_104 ( V_248 -> V_253 ) ;
V_249 = ( ( - V_250 ) & 3 ) ;
F_27 ( L_79
L_80 ,
V_248 -> V_37 , V_248 -> V_95 , V_248 -> V_97 ,
V_248 -> V_144 , V_248 -> V_82 , V_250 ) ;
if ( V_4 -> V_6 ) {
V_248 = (struct V_89 * ) V_4 -> V_251 ;
V_4 -> V_254 = ( ! V_248 -> V_122 ) ? 1 : 0 ;
V_4 -> V_255 = F_105 ( V_248 -> V_37 ) ;
V_4 -> V_43 = V_248 -> V_256 ;
V_4 -> V_42 = V_248 -> V_257 ;
memcpy ( V_4 -> V_74 , V_248 -> V_74 , 6 ) ;
V_4 -> V_258 = F_37 ( V_248 -> V_97 ) ;
V_4 -> V_94 = V_248 -> V_95 ;
V_4 -> V_259 = F_37 ( V_248 -> V_144 ) ;
V_4 -> V_82 = F_32 ( V_248 -> V_82 ) ;
V_4 -> V_122 = F_32 ( V_248 -> V_122 ) ;
}
if ( F_106 ( V_3 , V_4 ) < 0 )
return - 1 ;
memset ( V_4 -> V_7 , 0 , V_8 ) ;
if ( F_103 ( V_3 , V_4 -> V_7 ,
V_250 + V_249 ) < 0 )
return - 1 ;
return 0 ;
}
int F_107 ( struct V_2 * V_3 , struct V_1 * V_4 ,
V_84 V_260 )
{
if ( F_108 ( V_3 , V_4 -> V_261 , V_4 -> V_10 , V_260 ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_109 ( struct V_2 * V_3 , struct V_229 * V_230 )
{
int V_132 ;
if ( ! V_230 -> V_262 ) {
V_3 -> V_124 = V_230 ;
return 0 ;
}
V_132 = F_110 ( V_230 -> V_262 ) ;
if ( ! V_132 ) {
F_3 ( L_81 , V_230 -> V_263 ) ;
return - V_216 ;
}
V_3 -> V_124 = V_230 ;
return 0 ;
}
void F_111 ( struct V_2 * V_3 ,
struct V_166 * V_167 , bool V_168 , bool V_264 )
{
if ( ! V_264 )
goto V_265;
F_3 ( L_82 ) ;
F_72 ( V_3 , V_44 ,
V_266 ) ;
if ( ! V_168 || ! V_3 -> V_53 )
goto V_265;
if ( V_3 -> V_53 -> V_59 )
F_112 ( V_3 -> V_53 -> V_59 ) ;
if ( V_3 -> V_53 -> V_114 != 0 ) {
F_18 ( & V_111 ) ;
F_113 ( & V_112 , V_3 -> V_53 -> V_114 ) ;
F_26 ( & V_111 ) ;
}
F_9 ( V_3 -> V_53 -> V_75 ) ;
F_9 ( V_3 -> V_53 ) ;
V_3 -> V_53 = NULL ;
V_265:
F_87 ( V_167 ) ;
if ( ! V_168 && V_3 -> V_53 ) {
F_18 ( & V_3 -> V_53 -> V_69 ) ;
if ( V_3 -> V_53 -> V_80 == V_81 ) {
struct V_55 * V_56 =
& V_3 -> V_51 -> V_57 ;
F_23 ( & V_3 -> V_53 -> V_143 , 0 ) ;
F_26 ( & V_3 -> V_53 -> V_69 ) ;
F_18 ( & V_56 -> V_67 ) ;
F_114 ( V_3 -> V_53 ) ;
F_26 ( & V_56 -> V_67 ) ;
} else
F_26 ( & V_3 -> V_53 -> V_69 ) ;
F_28 ( V_3 -> V_53 ) ;
}
if ( ! F_12 ( V_3 -> V_36 . V_38 ) )
F_13 ( V_3 -> V_36 . V_38 ) ;
if ( ! F_12 ( V_3 -> V_41 . V_38 ) )
F_13 ( V_3 -> V_41 . V_38 ) ;
F_115 ( V_3 -> V_33 ) ;
F_9 ( V_3 -> V_12 ) ;
if ( V_3 -> V_62 ) {
F_76 ( V_3 -> V_62 ) ;
V_3 -> V_62 = NULL ;
}
F_116 ( V_3 ) ;
if ( V_3 -> V_201 ) {
F_94 ( V_3 -> V_201 ) ;
V_3 -> V_201 = NULL ;
}
if ( V_3 -> V_124 -> V_267 )
V_3 -> V_124 -> V_267 ( V_3 ) ;
if ( V_3 -> V_124 -> V_268 )
V_3 -> V_124 -> V_268 ( V_3 ) ;
F_97 ( V_3 -> V_124 ) ;
F_9 ( V_3 ) ;
}
static int F_117 ( struct V_166 * V_167 )
{
T_1 * V_269 , V_168 = 0 ;
int V_91 = 0 , V_132 ;
struct V_2 * V_3 = NULL ;
struct V_1 * V_4 ;
struct V_50 * V_51 = NULL ;
struct V_89 * V_90 ;
struct V_270 * V_271 ;
bool V_264 = false ;
F_118 ( V_272 ) ;
F_18 ( & V_167 -> V_185 ) ;
if ( V_167 -> V_273 == V_274 ) {
V_167 -> V_273 = V_275 ;
F_119 ( & V_167 -> V_276 ) ;
} else if ( V_167 -> V_273 == V_277 ) {
F_26 ( & V_167 -> V_185 ) ;
goto exit;
} else {
V_167 -> V_273 = V_275 ;
}
F_26 ( & V_167 -> V_185 ) ;
V_3 = F_2 ( sizeof( struct V_2 ) , V_5 ) ;
if ( ! V_3 ) {
F_3 ( L_83
L_84 ) ;
return 1 ;
}
F_27 ( L_85 ) ;
V_3 -> V_172 = V_278 ;
if ( F_109 ( V_3 , V_167 -> V_231 ) < 0 ) {
F_9 ( V_3 ) ;
return 1 ;
}
V_132 = V_167 -> V_231 -> F_98 ( V_167 , V_3 ) ;
if ( V_132 == - V_279 ) {
F_119 ( & V_167 -> V_276 ) ;
F_97 ( V_3 -> V_124 ) ;
F_9 ( V_3 ) ;
V_3 = NULL ;
goto exit;
} else if ( V_132 < 0 ) {
F_18 ( & V_167 -> V_185 ) ;
if ( V_167 -> V_273 == V_274 ) {
F_26 ( & V_167 -> V_185 ) ;
F_119 ( & V_167 -> V_276 ) ;
F_97 ( V_3 -> V_124 ) ;
F_9 ( V_3 ) ;
V_3 = NULL ;
return 1 ;
}
F_26 ( & V_167 -> V_185 ) ;
F_97 ( V_3 -> V_124 ) ;
F_9 ( V_3 ) ;
V_3 = NULL ;
goto V_280;
}
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
goto V_281;
}
F_84 ( V_167 ) ;
F_27 ( L_86 ) ;
V_3 -> V_172 = V_282 ;
V_132 = V_167 -> V_231 -> F_102 ( V_3 , V_4 ) ;
if ( V_132 == 1 )
return 1 ;
else if ( V_132 < 0 )
goto V_281;
V_269 = & V_4 -> V_251 [ 0 ] ;
V_90 = (struct V_89 * ) V_269 ;
V_3 -> V_283 = V_90 -> V_95 ;
F_18 ( & V_167 -> V_185 ) ;
if ( V_167 -> V_273 != V_275 ) {
F_26 ( & V_167 -> V_185 ) ;
F_3 ( L_87
L_88 , V_167 -> V_186 , V_167 -> V_187 ) ;
F_15 ( V_3 , V_92 ,
V_284 ) ;
goto V_281;
}
F_26 ( & V_167 -> V_185 ) ;
V_3 -> V_285 = V_167 -> V_206 ;
F_27 ( L_89
L_90 , V_3 -> V_175 , V_167 -> V_231 -> V_263 ,
V_3 -> V_176 , V_3 -> V_177 ) ;
F_27 ( L_91 ) ;
V_3 -> V_172 = V_286 ;
if ( F_14 ( V_3 , V_90 -> V_257 ,
V_90 -> V_256 ) < 0 )
goto V_281;
V_168 = ( V_90 -> V_122 == 0x0000 ) ;
if ( V_168 ) {
if ( F_36 ( V_3 , V_269 ) < 0 )
goto V_281;
} else {
if ( F_53 ( V_3 , V_269 ) < 0 )
goto V_281;
}
V_132 = F_120 ( V_167 , V_3 , V_4 ) ;
if ( V_132 < 0 ) {
V_51 = V_3 -> V_51 ;
goto V_281;
}
V_4 -> V_168 = V_168 ;
V_3 -> V_53 -> V_59 -> V_135 =
V_3 -> V_124 -> V_287 ( V_3 ) ;
V_51 = V_3 -> V_51 ;
if ( ! V_51 ) {
F_3 ( L_92 ) ;
goto V_281;
}
if ( V_168 ) {
if ( F_44 ( V_3 ) < 0 )
goto V_281;
} else {
if ( F_54 ( V_3 , V_269 ) < 0 )
goto V_265;
}
V_91 = F_121 ( V_4 , V_3 ) ;
if ( V_91 < 0 )
goto V_281;
if ( ! V_3 -> V_53 ) {
F_3 ( L_93 ) ;
goto V_281;
}
F_87 ( V_167 ) ;
if ( F_122 ( V_272 ) )
goto V_281;
if ( V_91 == 1 ) {
V_271 = V_3 -> V_271 ;
V_91 = F_70 ( V_167 , V_3 , V_168 ) ;
if ( V_91 < 0 )
goto V_281;
F_123 ( V_167 , V_51 , V_271 ) ;
}
V_51 = NULL ;
V_271 = NULL ;
return 1 ;
V_281:
V_264 = true ;
V_265:
V_271 = V_3 -> V_271 ;
F_111 ( V_3 , V_167 , V_168 , V_264 ) ;
V_264 = false ;
if ( V_51 ) {
F_123 ( V_167 , V_51 , V_271 ) ;
V_51 = NULL ;
V_271 = NULL ;
}
V_280:
return 1 ;
exit:
F_87 ( V_167 ) ;
F_18 ( & V_167 -> V_185 ) ;
V_167 -> V_273 = V_288 ;
F_26 ( & V_167 -> V_185 ) ;
return 0 ;
}
int F_124 ( void * V_289 )
{
struct V_166 * V_167 = V_289 ;
int V_91 ;
F_125 ( V_191 ) ;
while ( 1 ) {
V_91 = F_117 ( V_167 ) ;
if ( V_91 != 1 )
break;
}
return 0 ;
}
