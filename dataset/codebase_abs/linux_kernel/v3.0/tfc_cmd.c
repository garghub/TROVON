void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
if ( ! ( V_13 & V_14 ) )
return;
V_8 = & V_2 -> V_8 ;
F_2 ( V_15 L_1 ,
V_3 , V_2 , V_2 -> V_16 , V_2 -> V_17 , V_2 -> V_18 , V_8 ) ;
F_2 ( V_15 L_2 ,
V_3 , V_2 , V_2 -> V_19 ) ;
F_2 ( V_15 L_3 , V_3 , V_2 , V_2 -> V_20 ) ;
V_12 = F_3 ( V_8 ) ;
F_2 ( V_15 L_4 ,
V_3 , V_2 , V_12 , V_12 -> V_21 ,
V_12 -> V_22 , V_8 -> V_23 , V_8 -> V_24 ) ;
if ( V_12 -> V_25 )
F_4 (mem, task->t_mem_list, se_list)
F_2 ( V_15 L_5
L_6 ,
V_3 , V_2 , V_10 ,
V_10 -> V_26 , V_10 -> V_27 , V_10 -> V_28 ) ;
V_7 = V_2 -> V_18 ;
if ( V_7 ) {
V_5 = F_5 ( V_7 ) ;
F_2 ( V_15 L_7
L_8 ,
V_3 , V_2 , V_5 -> V_29 , V_5 -> V_30 , V_5 -> V_31 , V_5 -> V_32 ,
V_7 -> V_33 , V_5 -> V_34 ) ;
}
F_6 ( V_15 , L_9 , V_35 ,
16 , 4 , V_2 -> V_19 , V_36 , 0 ) ;
}
static void F_7 ( struct V_37 * V_17 , struct V_1 * V_2 )
{
struct V_38 * V_39 ;
unsigned long V_40 ;
V_39 = & V_17 -> V_41 -> V_42 -> V_39 ;
F_8 ( & V_39 -> V_43 , V_40 ) ;
F_9 ( & V_2 -> V_44 . V_45 , & V_39 -> V_46 ) ;
F_10 ( & V_39 -> V_43 , V_40 ) ;
F_11 ( & V_39 -> V_47 ) ;
F_12 ( & V_39 -> V_48 ) ;
}
static struct V_1 * F_13 ( struct V_38 * V_39 )
{
unsigned long V_40 ;
struct V_49 * V_50 ;
F_8 ( & V_39 -> V_43 , V_40 ) ;
if ( F_14 ( & V_39 -> V_46 ) ) {
F_10 ( & V_39 -> V_43 , V_40 ) ;
return NULL ;
}
V_50 = F_15 ( & V_39 -> V_46 , struct V_49 , V_45 ) ;
F_16 ( & V_50 -> V_45 ) ;
F_17 ( & V_39 -> V_47 ) ;
F_10 ( & V_39 -> V_43 , V_40 ) ;
return F_18 ( V_50 , struct V_1 , V_44 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
if ( ! V_2 )
return;
V_52 = V_2 -> V_55 ;
V_54 = F_20 ( V_52 ) ;
if ( F_21 ( V_52 ) )
V_54 -> V_56 . V_57 ( F_21 ( V_52 ) ) ;
F_22 ( V_52 ) ;
F_23 ( V_2 -> V_17 ) ;
F_24 ( V_2 ) ;
}
void F_25 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_18 ( V_8 , struct V_1 , V_8 ) ;
F_19 ( V_2 ) ;
}
void F_26 ( struct V_8 * V_8 )
{
F_27 ( V_8 , 0 , 1 , 0 ) ;
}
int F_28 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_18 ( V_8 , struct V_1 , V_8 ) ;
struct V_51 * V_52 ;
struct V_58 * V_59 ;
struct V_53 * V_54 ;
struct V_4 * V_5 ;
T_1 V_60 ;
F_1 ( V_2 , V_61 ) ;
V_5 = F_5 ( V_2 -> V_18 ) ;
V_54 = V_5 -> V_62 ;
V_60 = sizeof( * V_59 ) + V_8 -> V_63 ;
V_52 = F_29 ( V_54 , V_60 ) ;
if ( ! V_52 ) {
return 0 ;
}
V_59 = F_30 ( V_52 , V_60 ) ;
memset ( V_59 , 0 , V_60 ) ;
V_59 -> V_64 . V_65 = V_8 -> V_66 ;
V_60 = V_8 -> V_63 ;
if ( V_60 ) {
V_59 -> V_64 . V_67 |= V_68 ;
V_59 -> V_69 . V_70 = F_31 ( V_60 ) ;
memcpy ( ( V_59 + 1 ) , V_8 -> V_71 , V_60 ) ;
}
if ( V_8 -> V_24 & ( V_72 | V_73 ) ) {
if ( V_8 -> V_24 & V_72 )
V_59 -> V_64 . V_67 |= V_74 ;
else
V_59 -> V_64 . V_67 |= V_75 ;
V_59 -> V_69 . V_76 = F_32 ( V_8 -> V_77 ) ;
}
V_2 -> V_18 = V_54 -> V_56 . V_78 ( V_2 -> V_18 ) ;
F_33 ( V_52 , V_79 , V_5 -> V_30 , V_5 -> V_29 , V_80 ,
V_81 | V_82 | V_83 , 0 ) ;
V_54 -> V_56 . V_84 ( V_54 , V_2 -> V_18 , V_52 ) ;
V_54 -> V_56 . V_85 ( V_2 -> V_18 ) ;
return 0 ;
}
int F_34 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_18 ( V_8 , struct V_1 , V_8 ) ;
return V_2 -> V_86 != V_8 -> V_23 ;
}
int F_35 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_18 ( V_8 , struct V_1 , V_8 ) ;
struct V_51 * V_52 ;
struct V_87 * V_88 ;
struct V_53 * V_54 ;
struct V_4 * V_5 ;
struct V_89 * V_90 ;
T_2 V_91 ;
F_1 ( V_2 , V_61 ) ;
V_5 = F_5 ( V_2 -> V_18 ) ;
V_54 = V_5 -> V_62 ;
V_52 = F_29 ( V_54 , sizeof( * V_88 ) ) ;
if ( ! V_52 )
return V_92 ;
V_88 = F_30 ( V_52 , sizeof( * V_88 ) ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_93 = F_31 ( V_8 -> V_23 ) ;
V_2 -> V_18 = V_54 -> V_56 . V_78 ( V_2 -> V_18 ) ;
F_33 ( V_52 , V_94 , V_5 -> V_30 , V_5 -> V_29 , V_80 ,
V_81 | V_83 | V_95 , 0 ) ;
V_90 = F_36 ( V_52 ) ;
V_91 = F_37 ( V_90 -> V_96 ) ;
if ( V_91 & V_81 ) {
if ( ( V_5 -> V_97 <= V_54 -> V_98 ) &&
( V_90 -> V_99 == V_94 ) ) {
if ( V_8 -> V_24 & V_100 ) {
F_38 ( V_8 ) ;
V_2 -> V_101 = F_3 ( V_8 ) -> V_102 ;
V_2 -> V_103 =
F_3 ( V_8 ) -> V_104 ;
}
if ( V_2 -> V_101 && V_54 -> V_56 . V_105 ( V_54 , V_5 -> V_97 ,
V_2 -> V_101 , V_2 -> V_103 ) )
V_2 -> V_106 = 1 ;
}
}
V_54 -> V_56 . V_84 ( V_54 , V_2 -> V_18 , V_52 ) ;
return 0 ;
}
T_2 F_39 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_18 ( V_8 , struct V_1 , V_8 ) ;
return F_5 ( V_2 -> V_18 ) -> V_32 ;
}
int F_40 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_18 ( V_8 , struct V_1 , V_8 ) ;
return V_2 -> V_16 ;
}
int F_41 ( struct V_8 * V_8 )
{
return 0 ;
}
void F_42 ( struct V_8 * V_8 )
{
F_2 ( V_15 L_10 , V_61 , V_8 ) ;
}
static void F_43 ( struct V_6 * V_7 , struct V_51 * V_52 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
struct V_89 * V_90 ;
if ( F_44 ( V_52 ) ) {
V_2 -> V_8 . V_108 = V_109 ;
V_2 -> V_18 = NULL ;
F_27 ( & V_2 -> V_8 , 0 , 1 , 0 ) ;
return;
}
V_90 = F_36 ( V_52 ) ;
switch ( V_90 -> V_99 ) {
case V_110 :
F_45 ( V_2 , V_52 ) ;
break;
case V_111 :
case V_112 :
case V_94 :
default:
F_2 ( V_15 L_11 ,
V_61 , V_90 -> V_99 ) ;
F_22 ( V_52 ) ;
F_27 ( & V_2 -> V_8 , 0 , 1 , 0 ) ;
break;
}
}
static void F_46 ( struct V_53 * V_54 ,
const struct V_51 * V_113 ,
T_2 V_114 , enum V_115 V_116 )
{
struct V_51 * V_52 ;
struct V_6 * V_7 ;
const struct V_89 * V_90 ;
T_1 V_60 ;
struct V_58 * V_59 ;
struct V_117 * V_118 ;
V_90 = F_36 ( V_113 ) ;
F_47 ( L_12 ,
F_37 ( V_90 -> V_119 ) , F_48 ( V_90 -> V_120 ) , V_114 , V_116 ) ;
V_60 = sizeof( * V_59 ) ;
if ( V_114 == V_121 )
V_60 += sizeof( * V_118 ) ;
V_52 = F_29 ( V_54 , V_60 ) ;
if ( ! V_52 )
return;
V_59 = F_30 ( V_52 , V_60 ) ;
memset ( V_59 , 0 , V_60 ) ;
V_59 -> V_64 . V_65 = V_114 ;
if ( V_114 == V_121 ) {
V_59 -> V_69 . V_122 = F_31 ( sizeof( * V_118 ) ) ;
V_59 -> V_64 . V_67 |= V_123 ;
V_118 = (struct V_117 * ) ( V_59 + 1 ) ;
V_118 -> V_124 = V_116 ;
}
F_49 ( V_52 , V_113 , V_79 , 0 ) ;
V_7 = F_21 ( V_52 ) ;
if ( V_7 )
V_54 -> V_56 . V_84 ( V_54 , V_7 , V_52 ) ;
else
V_54 -> V_56 . V_125 ( V_54 , V_52 ) ;
}
static void F_50 ( struct V_1 * V_2 , enum V_115 V_116 )
{
F_46 ( V_2 -> V_17 -> V_41 -> V_54 ,
V_2 -> V_55 , V_121 , V_116 ) ;
F_19 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_126 * V_127 ;
struct V_128 * V_59 ;
struct V_37 * V_17 ;
T_3 V_129 ;
V_59 = F_30 ( V_2 -> V_55 , sizeof( * V_59 ) ) ;
switch ( V_59 -> V_130 ) {
case V_131 :
V_129 = V_132 ;
break;
case V_133 :
V_129 = V_134 ;
break;
case V_135 :
V_129 = V_136 ;
break;
case V_137 :
V_129 = V_138 ;
break;
case V_139 :
V_129 = V_140 ;
break;
default:
F_52 ( L_13 , V_59 -> V_130 ) ;
F_50 ( V_2 , V_141 ) ;
return;
}
F_52 ( L_14 , V_129 ) ;
V_127 = F_53 ( & V_2 -> V_8 , V_2 , V_129 ) ;
if ( ! V_127 ) {
F_52 ( L_15 ) ;
F_50 ( V_2 , V_142 ) ;
return;
}
V_2 -> V_8 . V_126 = V_127 ;
switch ( V_59 -> V_130 ) {
case V_131 :
V_2 -> V_20 = F_54 ( (struct V_143 * ) V_59 -> V_144 ) ;
if ( F_55 ( & V_2 -> V_8 , V_2 -> V_20 ) < 0 ) {
F_52 ( L_16
L_17 ,
V_129 , & V_2 -> V_8 , V_2 -> V_20 ) ;
F_1 ( V_2 , V_61 ) ;
V_17 = V_2 -> V_17 ;
F_56 ( & V_2 -> V_8 ,
V_2 -> V_8 . V_145 , 0 ) ;
F_27 ( & V_2 -> V_8 , 0 , 1 , 0 ) ;
F_23 ( V_17 ) ;
return;
}
break;
case V_133 :
case V_135 :
case V_137 :
case V_139 :
break;
default:
return;
}
F_57 ( & V_2 -> V_8 ) ;
}
int F_58 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_18 ( V_8 , struct V_1 , V_8 ) ;
struct V_126 * V_127 = V_8 -> V_126 ;
enum V_115 V_116 ;
switch ( V_127 -> V_146 ) {
case V_147 :
V_116 = V_148 ;
break;
case V_149 :
V_116 = V_150 ;
break;
case V_151 :
V_116 = V_152 ;
break;
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
default:
V_116 = V_142 ;
break;
}
F_52 ( L_18 ,
V_127 -> V_158 , V_127 -> V_146 , V_116 ) ;
F_50 ( V_2 , V_116 ) ;
return 0 ;
}
static void F_59 ( struct V_37 * V_17 , struct V_51 * V_52 )
{
struct V_1 * V_2 ;
struct V_53 * V_54 = V_17 -> V_41 -> V_54 ;
V_2 = F_60 ( sizeof( * V_2 ) , V_159 ) ;
if ( ! V_2 )
goto V_160;
V_2 -> V_17 = V_17 ;
V_2 -> V_18 = V_54 -> V_56 . V_161 ( V_54 , V_52 ) ;
if ( ! V_2 -> V_18 ) {
F_24 ( V_2 ) ;
goto V_160;
}
V_2 -> V_55 = V_52 ;
F_7 ( V_17 , V_2 ) ;
return;
V_160:
F_47 ( L_19 ) ;
F_46 ( V_54 , V_52 , V_162 , 0 ) ;
F_22 ( V_52 ) ;
F_23 ( V_17 ) ;
}
void F_61 ( struct V_37 * V_17 , struct V_51 * V_52 )
{
struct V_89 * V_90 = F_36 ( V_52 ) ;
switch ( V_90 -> V_99 ) {
case V_163 :
F_59 ( V_17 , V_52 ) ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_94 :
case V_164 :
default:
F_2 ( V_15 L_11 ,
V_61 , V_90 -> V_99 ) ;
F_22 ( V_52 ) ;
F_23 ( V_17 ) ;
break;
}
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_89 * V_90 = F_36 ( V_2 -> V_55 ) ;
struct V_8 * V_8 ;
struct V_128 * V_59 ;
int V_165 ;
T_2 V_166 ;
int V_167 ;
int V_168 ;
V_59 = F_30 ( V_2 -> V_55 , sizeof( * V_59 ) ) ;
if ( ! V_59 )
goto V_169;
if ( V_59 -> V_170 & V_171 )
goto V_169;
if ( V_59 -> V_130 ) {
V_167 = V_172 ;
V_165 = V_173 ;
V_166 = 0 ;
} else {
switch ( V_59 -> V_170 & ( V_174 | V_175 ) ) {
case 0 :
V_165 = V_173 ;
break;
case V_174 :
V_165 = V_176 ;
break;
case V_175 :
V_165 = V_177 ;
break;
case V_175 | V_174 :
goto V_169;
}
switch ( V_59 -> V_178 & V_179 ) {
case V_180 :
V_167 = V_181 ;
break;
case V_182 :
V_167 = V_183 ;
break;
case V_184 :
V_167 = V_185 ;
break;
case V_172 :
default:
V_167 = V_186 ;
}
V_167 = V_59 -> V_178 & V_179 ;
V_166 = F_63 ( V_59 -> V_187 ) ;
V_2 -> V_19 = V_59 -> V_188 ;
}
V_8 = & V_2 -> V_8 ;
F_64 ( V_8 , & V_189 -> V_190 , V_2 -> V_17 -> V_191 ,
V_166 , V_165 , V_167 ,
& V_2 -> V_192 [ 0 ] ) ;
if ( V_59 -> V_130 ) {
F_51 ( V_2 ) ;
return;
}
F_5 ( V_2 -> V_18 ) -> V_62 -> V_56 . V_193 ( V_2 -> V_18 , F_43 , V_2 ) ;
V_2 -> V_20 = F_54 ( (struct V_143 * ) V_59 -> V_144 ) ;
V_168 = F_65 ( & V_2 -> V_8 , NULL , V_2 -> V_20 ) ;
if ( V_168 < 0 ) {
F_1 ( V_2 , V_61 ) ;
F_56 ( & V_2 -> V_8 ,
V_2 -> V_8 . V_145 , 0 ) ;
return;
}
V_168 = F_66 ( V_8 , V_2 -> V_19 ) ;
F_47 ( L_20 , V_90 -> V_99 , V_168 ) ;
F_1 ( V_2 , V_61 ) ;
if ( V_168 == - 1 ) {
F_56 ( V_8 ,
V_194 , 0 ) ;
F_27 ( V_8 , 0 , 1 , 0 ) ;
return;
}
if ( V_168 == - 2 ) {
if ( V_8 -> V_24 & V_195 )
F_28 ( V_8 ) ;
else
F_56 ( V_8 ,
V_8 -> V_145 , 0 ) ;
F_27 ( V_8 , 0 , 1 , 0 ) ;
return;
}
F_67 ( V_8 ) ;
return;
V_169:
F_50 ( V_2 , V_141 ) ;
return;
}
static void F_68 ( struct V_1 * V_2 )
{
F_47 ( L_21 , V_2 -> V_16 ) ;
switch ( V_2 -> V_16 ) {
case V_196 :
F_62 ( V_2 ) ;
break;
default:
break;
}
}
int F_69 ( void * V_107 )
{
struct V_197 * V_42 = V_107 ;
struct V_38 * V_39 = & V_42 -> V_39 ;
struct V_1 * V_2 ;
int V_168 ;
F_70 ( V_198 , - 20 ) ;
while ( ! F_71 () ) {
V_168 = F_72 ( V_39 -> V_48 ,
F_73 ( & V_39 -> V_47 ) || F_71 () ) ;
if ( V_168 < 0 || F_71 () )
goto V_199;
V_2 = F_13 ( V_39 ) ;
if ( V_2 )
F_68 ( V_2 ) ;
}
V_199:
return 0 ;
}
