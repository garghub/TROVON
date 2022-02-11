void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
struct V_10 * V_11 ;
F_2 ( & V_6 -> V_12 ) ;
V_11 = F_3 ( V_2 , V_3 ) ;
if ( V_11 )
F_4 ( & V_11 -> V_13 ) ;
F_5 ( & V_6 -> V_12 ) ;
if ( ! V_11 ) {
F_6 ( V_8 , L_1 , V_3 ) ;
return;
}
V_11 -> V_14 ( V_11 , (enum V_15 ) V_4 ) ;
if ( F_7 ( & V_11 -> V_13 ) )
F_8 ( & V_11 -> free ) ;
}
static void F_9 ( struct V_10 * V_16 ,
enum V_15 type )
{
struct V_17 V_14 ;
struct V_18 * V_19 = & V_16 -> V_19 ;
if ( V_19 -> V_20 ) {
V_14 . V_7 = V_19 -> V_7 ;
V_14 . V_21 . V_11 = V_19 ;
switch ( type ) {
case V_22 :
V_14 . V_14 = V_23 ;
break;
case V_24 :
V_14 . V_14 = V_25 ;
break;
case V_26 :
V_14 . V_14 = V_27 ;
break;
case V_28 :
V_14 . V_14 = V_29 ;
break;
case V_30 :
V_14 . V_14 = V_31 ;
break;
case V_32 :
V_14 . V_14 = V_33 ;
break;
case V_34 :
V_14 . V_14 = V_35 ;
break;
case V_36 :
V_14 . V_14 = V_37 ;
break;
default:
F_10 ( V_19 -> V_7 -> V_8 . V_38 , L_2 ,
type , V_16 -> V_3 ) ;
return;
}
V_19 -> V_20 ( & V_14 , V_19 -> V_39 ) ;
}
}
static int F_11 ( struct V_1 * V_2 , int V_40 ,
int V_41 , unsigned long * V_42 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
return F_12 ( & V_6 -> V_43 , V_40 , V_41 , V_42 ) ;
}
enum V_44 F_13 ( enum V_45 V_46 )
{
switch ( V_46 ) {
case V_47 :
return V_48 ;
case V_49 :
return V_50 ;
case V_51 :
return V_52 ;
case V_53 :
return V_54 ;
case V_55 :
return V_56 ;
case V_57 :
return V_58 ;
default:
return V_59 ;
}
}
static int F_14 ( struct V_1 * V_2 , unsigned long V_3 ,
struct V_10 * V_16 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_60 ;
if ( ! V_3 )
return - V_61 ;
V_16 -> V_3 = V_3 ;
F_15 ( & V_6 -> V_12 ) ;
V_60 = F_16 ( & V_2 -> V_62 ,
V_16 -> V_3 & ( V_2 -> V_63 . V_64 - 1 ) , V_16 ) ;
F_17 ( & V_6 -> V_12 ) ;
if ( V_60 ) {
F_18 ( & V_2 -> V_9 -> V_8 , L_3 ) ;
goto V_65;
}
F_19 ( & V_16 -> V_13 , 1 ) ;
F_20 ( & V_16 -> free ) ;
return 0 ;
V_65:
return V_60 ;
}
static int F_21 ( struct V_1 * V_2 , unsigned long V_3 ,
struct V_10 * V_16 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
int V_60 ;
if ( ! V_3 )
return - V_61 ;
V_16 -> V_3 = V_3 ;
V_60 = F_22 ( V_2 , & V_6 -> V_6 , V_16 -> V_3 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_4 ) ;
goto V_66;
}
V_60 = F_22 ( V_2 , & V_6 -> V_67 , V_16 -> V_3 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_5 ) ;
goto V_68;
}
F_15 ( & V_6 -> V_12 ) ;
V_60 = F_16 ( & V_2 -> V_62 ,
V_16 -> V_3 & ( V_2 -> V_63 . V_64 - 1 ) , V_16 ) ;
F_17 ( & V_6 -> V_12 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_3 ) ;
goto V_65;
}
F_19 ( & V_16 -> V_13 , 1 ) ;
F_20 ( & V_16 -> free ) ;
return 0 ;
V_65:
F_23 ( V_2 , & V_6 -> V_67 , V_16 -> V_3 ) ;
V_68:
F_23 ( V_2 , & V_6 -> V_6 , V_16 -> V_3 ) ;
V_66:
return V_60 ;
}
void F_24 ( struct V_1 * V_2 , struct V_10 * V_16 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned long V_69 ;
F_25 ( & V_6 -> V_12 , V_69 ) ;
F_26 ( & V_2 -> V_62 ,
V_16 -> V_3 & ( V_2 -> V_63 . V_64 - 1 ) ) ;
F_27 ( & V_6 -> V_12 , V_69 ) ;
}
void F_28 ( struct V_1 * V_2 , struct V_10 * V_16 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_7 ( & V_16 -> V_13 ) )
F_8 ( & V_16 -> free ) ;
F_29 ( & V_16 -> free ) ;
if ( ( V_16 -> V_19 . V_70 ) != V_71 ) {
F_23 ( V_2 , & V_6 -> V_67 , V_16 -> V_3 ) ;
F_23 ( V_2 , & V_6 -> V_6 , V_16 -> V_3 ) ;
}
}
void F_30 ( struct V_1 * V_2 , int V_72 ,
int V_40 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( V_72 < V_73 )
return;
F_31 ( & V_6 -> V_43 , V_72 , V_40 , V_74 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_75 * V_76 , int V_77 , int V_78 ,
struct V_10 * V_16 )
{
T_1 V_79 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
if ( V_76 -> V_80 > V_2 -> V_63 . V_81 ||
V_76 -> V_82 > V_2 -> V_63 . V_83 ) {
F_18 ( V_8 , L_6 ,
V_76 -> V_80 , V_76 -> V_82 ) ;
return - V_61 ;
}
if ( V_78 ) {
if ( V_76 -> V_80 ) {
F_10 ( V_8 , L_7 ) ;
return - V_61 ;
}
V_16 -> V_84 . V_85 = V_16 -> V_84 . V_86 = 0 ;
} else {
if ( V_77 && ( ! V_76 -> V_80 || ! V_76 -> V_82 ) ) {
F_18 ( V_8 , L_8 ) ;
return - V_61 ;
}
V_79 = V_76 -> V_80 > V_87 ?
V_76 -> V_80 : V_87 ;
V_16 -> V_84 . V_85 = F_33 ( V_79 ) ;
if ( ( T_1 ) V_16 -> V_84 . V_85 > V_2 -> V_63 . V_81 ) {
F_18 ( V_8 , L_9 ) ;
return - V_61 ;
}
V_79 = F_34 ( 1U , V_76 -> V_82 ) ;
V_16 -> V_84 . V_86 = F_33 ( V_79 ) ;
V_16 -> V_84 . V_88 = F_35 ( V_2 -> V_63 . V_89 ) ;
}
V_76 -> V_80 = V_16 -> V_84 . V_90 = V_16 -> V_84 . V_85 ;
V_76 -> V_82 = V_16 -> V_84 . V_86 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_10 * V_16 ,
struct V_91 * V_92 )
{
T_1 V_93 = F_33 ( V_2 -> V_63 . V_94 ) ;
T_2 V_95 = F_35 ( V_93 ) ;
if ( ( T_1 ) ( 1 << V_92 -> V_96 ) > V_2 -> V_63 . V_81 ||
V_92 -> V_97 > V_95 ||
V_92 -> V_97 < V_98 ) {
F_18 ( & V_2 -> V_9 -> V_8 , L_10 ) ;
return - V_61 ;
}
V_16 -> V_99 . V_85 = 1 << V_92 -> V_96 ;
V_16 -> V_99 . V_88 = V_92 -> V_97 ;
V_16 -> V_100 = F_37 ( ( V_16 -> V_84 . V_85 <<
V_16 -> V_84 . V_88 ) , V_101 ) +
F_37 ( ( V_16 -> V_99 . V_85 <<
V_16 -> V_99 . V_88 ) , V_101 ) ;
V_16 -> V_99 . V_102 = 0 ;
V_16 -> V_84 . V_102 = F_37 ( ( V_16 -> V_99 . V_85 <<
V_16 -> V_99 . V_88 ) , V_101 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
struct V_10 * V_16 )
{
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
T_1 V_79 ;
if ( V_76 -> V_103 > V_2 -> V_63 . V_81 ||
V_76 -> V_104 > V_2 -> V_63 . V_105 ||
V_76 -> V_106 > V_2 -> V_63 . V_107 ) {
F_18 ( V_8 , L_11 ) ;
return - V_61 ;
}
V_16 -> V_99 . V_88 = F_35 ( V_2 -> V_63 . V_94 ) ;
V_16 -> V_108 = 1 ;
V_16 -> V_109 = 0 ;
V_79 = V_76 -> V_103 > V_87 ?
V_76 -> V_103 : V_87 ;
V_16 -> V_99 . V_85 = F_33 ( V_79 ) ;
if ( ( T_1 ) V_16 -> V_99 . V_85 > V_2 -> V_63 . V_81 ) {
F_18 ( V_8 , L_12 ) ;
return - V_61 ;
}
V_79 = F_34 ( 1U , V_76 -> V_104 ) ;
V_16 -> V_99 . V_86 = F_33 ( V_79 ) ;
V_16 -> V_100 = F_37 ( ( V_16 -> V_84 . V_85 <<
V_16 -> V_84 . V_88 ) , V_101 ) +
F_37 ( ( V_16 -> V_99 . V_85 <<
V_16 -> V_99 . V_88 ) , V_101 ) ;
V_16 -> V_99 . V_102 = 0 ;
V_16 -> V_84 . V_102 = F_37 ( ( V_16 -> V_99 . V_85 <<
V_16 -> V_99 . V_88 ) , V_101 ) ;
V_76 -> V_103 = V_16 -> V_99 . V_90 = V_16 -> V_99 . V_85 ;
V_76 -> V_104 = V_16 -> V_99 . V_86 ;
V_76 -> V_106 = 0 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_110 * V_110 ,
struct V_111 * V_112 ,
struct V_113 * V_114 , unsigned long V_115 ,
struct V_10 * V_16 )
{
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
struct V_91 V_92 ;
unsigned long V_3 = 0 ;
int V_60 = 0 ;
F_40 ( & V_16 -> V_116 ) ;
F_41 ( & V_16 -> V_99 . V_12 ) ;
F_41 ( & V_16 -> V_84 . V_12 ) ;
V_16 -> V_46 = V_47 ;
if ( V_112 -> V_117 == V_118 )
V_16 -> V_119 = V_118 ;
else
V_16 -> V_119 = V_120 ;
V_60 = F_32 ( V_2 , & V_112 -> V_76 , ! ! V_110 -> V_121 ,
! ! V_112 -> V_122 , V_16 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_13 ) ;
goto V_66;
}
if ( V_110 -> V_121 ) {
if ( F_42 ( & V_92 , V_114 , sizeof( V_92 ) ) ) {
F_18 ( V_8 , L_14 ) ;
V_60 = - V_123 ;
goto V_66;
}
V_60 = F_36 ( V_2 , V_16 , & V_92 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_15 ) ;
goto V_66;
}
V_16 -> V_124 = F_43 ( V_110 -> V_121 -> V_125 ,
V_92 . V_126 , V_16 -> V_100 , 0 ,
0 ) ;
if ( F_44 ( V_16 -> V_124 ) ) {
F_18 ( V_8 , L_16 ) ;
V_60 = F_45 ( V_16 -> V_124 ) ;
goto V_66;
}
V_60 = F_46 ( V_2 , F_47 ( V_16 -> V_124 ) ,
V_16 -> V_124 -> V_127 , & V_16 -> V_128 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_17 ) ;
goto V_129;
}
V_60 = F_48 ( V_2 , & V_16 -> V_128 ,
V_16 -> V_124 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_18 ) ;
goto V_130;
}
} else {
if ( V_112 -> V_131 &
V_132 ) {
F_18 ( V_8 , L_19 ) ;
V_60 = - V_61 ;
goto V_66;
}
if ( V_112 -> V_131 & V_133 ) {
F_18 ( V_8 , L_19 ) ;
V_60 = - V_61 ;
goto V_66;
}
V_60 = F_38 ( V_2 , & V_112 -> V_76 ,
V_16 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_20 ) ;
goto V_66;
}
V_16 -> V_99 . V_134 = V_2 -> V_135 + V_136 +
V_137 * V_2 -> V_138 . V_139 ;
V_16 -> V_84 . V_134 = V_2 -> V_135 +
V_140 +
V_137 * V_2 -> V_138 . V_139 ;
if ( F_49 ( V_2 , V_16 -> V_100 , V_101 * 2 ,
& V_16 -> V_141 ) ) {
F_18 ( V_8 , L_21 ) ;
V_60 = - V_142 ;
goto V_66;
}
V_60 = F_46 ( V_2 , V_16 -> V_141 . V_143 ,
V_16 -> V_141 . V_127 , & V_16 -> V_128 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_22 ) ;
goto V_129;
}
V_60 = F_50 ( V_2 , & V_16 -> V_128 ,
& V_16 -> V_141 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_23 ) ;
goto V_130;
}
V_16 -> V_99 . V_144 = F_51 ( V_16 -> V_99 . V_85 , sizeof( V_145 ) ,
V_146 ) ;
V_16 -> V_84 . V_144 = F_51 ( V_16 -> V_84 . V_85 , sizeof( V_145 ) ,
V_146 ) ;
if ( ! V_16 -> V_99 . V_144 || ! V_16 -> V_84 . V_144 ) {
V_60 = - V_142 ;
goto V_147;
}
}
if ( V_115 ) {
V_3 = V_115 ;
} else {
V_60 = F_11 ( V_2 , 1 , 1 , & V_3 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_24 ) ;
goto V_147;
}
}
if ( ( V_112 -> V_70 ) == V_71 ) {
V_60 = F_14 ( V_2 , V_3 , V_16 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_25 ) ;
goto V_148;
}
} else {
V_60 = F_21 ( V_2 , V_3 , V_16 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_25 ) ;
goto V_148;
}
}
if ( V_115 )
V_16 -> V_149 = 1 ;
else
V_16 -> V_149 = F_52 ( V_16 -> V_3 ) ;
V_16 -> V_14 = F_9 ;
return 0 ;
V_148:
if ( ! V_115 )
F_30 ( V_2 , V_3 , 1 ) ;
V_147:
F_53 ( V_16 -> V_99 . V_144 ) ;
F_53 ( V_16 -> V_84 . V_144 ) ;
V_130:
F_54 ( V_2 , & V_16 -> V_128 ) ;
V_129:
if ( V_110 -> V_121 )
F_55 ( V_16 -> V_124 ) ;
else
F_56 ( V_2 , V_16 -> V_100 , & V_16 -> V_141 ) ;
V_66:
return V_60 ;
}
struct V_18 * F_57 ( struct V_110 * V_150 ,
struct V_111 * V_112 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_58 ( V_150 -> V_7 ) ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
struct V_151 * V_152 ;
struct V_10 * V_16 ;
int V_60 ;
switch ( V_112 -> V_70 ) {
case V_153 : {
V_16 = F_59 ( sizeof( * V_16 ) , V_146 ) ;
if ( ! V_16 )
return F_60 ( - V_142 ) ;
V_60 = F_39 ( V_2 , V_150 , V_112 , V_114 , 0 ,
V_16 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_26 ) ;
F_53 ( V_16 ) ;
return F_60 ( V_60 ) ;
}
V_16 -> V_19 . V_154 = V_16 -> V_3 ;
break;
}
case V_71 : {
if ( V_150 -> V_121 ) {
F_18 ( V_8 , L_27 ) ;
return F_60 ( - V_61 ) ;
}
V_152 = F_59 ( sizeof( * V_152 ) , V_146 ) ;
if ( ! V_152 )
return F_60 ( - V_142 ) ;
V_16 = & V_152 -> V_16 ;
V_16 -> V_155 = V_112 -> V_156 - 1 ;
V_16 -> V_157 = V_2 -> V_158 . V_157 [ V_16 -> V_155 ] ;
V_16 -> V_19 . V_154 = V_159 +
V_2 -> V_158 . V_157 [ V_16 -> V_155 ] ;
V_60 = F_39 ( V_2 , V_150 , V_112 , V_114 ,
V_16 -> V_19 . V_154 , V_16 ) ;
if ( V_60 ) {
F_18 ( V_8 , L_28 ) ;
F_53 ( V_152 ) ;
return F_60 ( V_60 ) ;
}
break;
}
default: {
F_18 ( V_8 , L_29 , V_112 -> V_70 ) ;
return F_60 ( - V_61 ) ;
}
}
return & V_16 -> V_19 ;
}
int F_61 ( int V_70 )
{
int V_160 ;
if ( V_70 == V_153 )
V_160 = V_161 ;
else if ( V_70 == V_162 )
V_160 = V_163 ;
else if ( V_70 == V_164 )
V_160 = V_165 ;
else if ( V_70 == V_71 )
V_160 = V_165 ;
else
V_160 = - 1 ;
return V_160 ;
}
int F_62 ( struct V_18 * V_19 , struct V_166 * V_167 ,
int V_168 , struct V_113 * V_114 )
{
struct V_1 * V_2 = F_58 ( V_19 -> V_7 ) ;
struct V_10 * V_16 = F_63 ( V_19 ) ;
enum V_45 V_169 , V_170 ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
int V_60 = - V_61 ;
int V_171 ;
enum V_172 V_173 ;
F_64 ( & V_16 -> V_116 ) ;
V_169 = V_168 & V_174 ?
V_167 -> V_175 : (enum V_45 ) V_16 -> V_46 ;
V_170 = V_168 & V_176 ?
V_167 -> V_177 : V_169 ;
if ( ! F_65 ( V_169 , V_170 , V_19 -> V_70 , V_168 ,
V_178 ) ) {
F_18 ( V_8 , L_30 ) ;
goto V_179;
}
if ( ( V_168 & V_180 ) &&
( V_167 -> V_156 == 0 || V_167 -> V_156 > V_2 -> V_63 . V_181 ) ) {
F_18 ( V_8 , L_31 ,
V_167 -> V_156 ) ;
goto V_179;
}
if ( V_168 & V_182 ) {
V_171 = V_168 & V_180 ? ( V_167 -> V_156 - 1 ) : V_16 -> V_155 ;
if ( V_167 -> V_183 >= V_2 -> V_63 . V_184 [ V_171 ] ) {
F_18 ( V_8 , L_32 ,
V_167 -> V_183 ) ;
goto V_179;
}
}
if ( V_168 & V_185 ) {
V_171 = V_168 & V_180 ? ( V_167 -> V_156 - 1 ) : V_16 -> V_155 ;
V_173 = F_66 ( V_2 -> V_158 . V_186 [ V_171 ] -> V_187 ) ;
if ( V_167 -> V_188 > V_189 ||
V_167 -> V_188 < V_190 ||
V_167 -> V_188 > V_173 ) {
F_18 ( V_8 , L_33 ,
V_167 -> V_188 ) ;
goto V_179;
}
}
if ( V_168 & V_191 &&
V_167 -> V_192 > V_2 -> V_63 . V_193 ) {
F_18 ( V_8 , L_34 ,
V_167 -> V_192 ) ;
goto V_179;
}
if ( V_168 & V_194 &&
V_167 -> V_195 > V_2 -> V_63 . V_196 ) {
F_18 ( V_8 , L_35 ,
V_167 -> V_195 ) ;
goto V_179;
}
if ( V_169 == V_170 && V_169 == V_47 ) {
V_60 = - V_197 ;
F_18 ( V_8 , L_36 , V_169 ,
V_170 ) ;
goto V_179;
}
V_60 = V_2 -> V_198 -> V_199 ( V_19 , V_167 , V_168 , V_169 ,
V_170 ) ;
V_179:
F_67 ( & V_16 -> V_116 ) ;
return V_60 ;
}
void F_68 ( struct V_200 * V_201 , struct V_200 * V_202 )
__acquires( &send_cq->lock
void F_69 ( struct V_200 * V_201 ,
struct V_200 * V_202 ) __releases( &send_cq->lock
T_3 F_70 ( struct V_203 * V_204 )
{
switch ( V_204 -> V_205 ) {
case V_206 :
case V_207 :
return F_71 ( V_204 -> V_208 . V_209 ) ;
case V_210 :
return F_71 ( V_204 -> V_208 . V_211 ) ;
default:
return 0 ;
}
}
static void * F_72 ( struct V_10 * V_16 , int V_102 )
{
return F_73 ( & V_16 -> V_141 , V_102 ) ;
}
void * F_74 ( struct V_10 * V_16 , int V_212 )
{
return F_72 ( V_16 , V_16 -> V_84 . V_102 + ( V_212 << V_16 -> V_84 . V_88 ) ) ;
}
void * F_75 ( struct V_10 * V_16 , int V_212 )
{
return F_72 ( V_16 , V_16 -> V_99 . V_102 + ( V_212 << V_16 -> V_99 . V_88 ) ) ;
}
bool F_76 ( struct V_213 * V_214 , int V_215 ,
struct V_216 * V_216 )
{
struct V_200 * V_217 ;
T_1 V_218 ;
V_218 = V_214 -> V_219 - V_214 -> V_220 ;
if ( F_77 ( V_218 + V_215 < V_214 -> V_90 ) )
return 0 ;
V_217 = F_78 ( V_216 ) ;
F_2 ( & V_217 -> V_12 ) ;
V_218 = V_214 -> V_219 - V_214 -> V_220 ;
F_5 ( & V_217 -> V_12 ) ;
return V_218 + V_215 >= V_214 -> V_90 ;
}
int F_79 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_221 = 0 ;
int V_60 ;
F_41 ( & V_6 -> V_12 ) ;
F_80 ( & V_2 -> V_62 , V_222 ) ;
V_60 = F_81 ( & V_6 -> V_43 , V_2 -> V_63 . V_64 ,
V_2 -> V_63 . V_64 - 1 , V_73 ,
V_221 ) ;
if ( V_60 ) {
F_18 ( & V_2 -> V_9 -> V_8 , L_37 ,
V_60 ) ;
return V_60 ;
}
return 0 ;
}
void F_82 ( struct V_1 * V_2 )
{
F_83 ( & V_2 -> V_6 . V_43 ) ;
}
