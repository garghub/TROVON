static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline
struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static inline
struct V_5 * F_4 ( struct V_8 * V_9 )
{
return F_2 ( V_9 , struct V_5 , V_10 ) ;
}
static inline
struct V_11 * F_5 ( struct V_1 * V_12 )
{
return F_2 ( V_12 -> V_4 . V_13 , struct V_11 , V_14 ) ;
}
static inline
T_1 F_6 ( T_1 V_15 )
{
T_1 V_16 = 0 ;
while ( V_15 ) {
V_16 += ( V_15 & 1 ) ;
V_15 >>= 1 ;
}
return V_16 ;
}
static void
F_7 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
unsigned V_21 ;
unsigned long V_22 ;
unsigned int V_23 ;
bool V_24 = false ;
int V_25 = V_20 -> V_25 ;
struct V_26 * V_27 = V_20 -> V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 = V_27 -> V_33 ;
struct V_5 * V_7 = V_32 -> V_7 ;
if ( ! V_32 -> V_34 || V_20 -> V_25 == - V_35 )
return;
if ( V_25 )
F_8 ( L_1 ,
V_36 , V_25 , V_20 -> V_37 , V_20 -> V_38 ) ;
V_30 = V_32 -> V_39 ;
if ( ! V_30 )
goto exit;
F_9 ( & V_32 -> V_40 , V_22 ) ;
if ( V_30 -> V_41 == V_42 ) {
V_20 -> V_38 = V_7 -> V_43 ;
V_7 -> V_44 += V_7 -> V_45 ;
if ( V_7 -> V_44 / V_7 -> V_46 >= V_7 -> V_47 ) {
V_20 -> V_38 += V_7 -> V_47 ;
V_7 -> V_44 -= V_7 -> V_47 *
V_7 -> V_46 ;
}
V_20 -> V_37 = V_20 -> V_38 ;
}
V_21 = V_32 -> V_23 % V_32 -> V_48 ;
V_21 += V_20 -> V_37 ;
if ( V_21 >= V_32 -> V_48 )
V_24 = true ;
V_23 = V_32 -> V_23 ;
V_32 -> V_23 = ( V_32 -> V_23 + V_20 -> V_37 ) % V_32 -> V_49 ;
F_10 ( & V_32 -> V_40 , V_22 ) ;
V_21 = V_32 -> V_49 - V_23 ;
if ( V_30 -> V_41 == V_42 ) {
if ( F_11 ( V_21 < V_20 -> V_37 ) ) {
memcpy ( V_20 -> V_50 , V_32 -> V_51 + V_23 , V_21 ) ;
memcpy ( V_20 -> V_50 + V_21 , V_32 -> V_51 ,
V_20 -> V_37 - V_21 ) ;
} else {
memcpy ( V_20 -> V_50 , V_32 -> V_51 + V_23 , V_20 -> V_37 ) ;
}
} else {
if ( F_11 ( V_21 < V_20 -> V_37 ) ) {
memcpy ( V_32 -> V_51 + V_23 , V_20 -> V_50 , V_21 ) ;
memcpy ( V_32 -> V_51 , V_20 -> V_50 + V_21 ,
V_20 -> V_37 - V_21 ) ;
} else {
memcpy ( V_32 -> V_51 + V_23 , V_20 -> V_50 , V_20 -> V_37 ) ;
}
}
exit:
if ( F_12 ( V_18 , V_20 , V_52 ) )
F_13 ( & V_7 -> V_10 . V_53 , L_2 , __LINE__ ) ;
if ( V_24 )
F_14 ( V_30 ) ;
return;
}
static int
F_15 ( struct V_29 * V_30 , int V_54 )
{
struct V_5 * V_7 = F_16 ( V_30 ) ;
struct V_1 * V_12 = F_3 ( V_7 ) ;
struct V_11 * V_55 = F_5 ( V_12 ) ;
struct V_31 * V_32 ;
unsigned long V_22 ;
int V_56 = 0 ;
if ( V_30 -> V_41 == V_42 )
V_32 = & V_7 -> V_57 ;
else
V_32 = & V_7 -> V_58 ;
F_9 ( & V_32 -> V_40 , V_22 ) ;
V_32 -> V_23 = 0 ;
switch ( V_54 ) {
case V_59 :
case V_60 :
V_32 -> V_39 = V_30 ;
break;
case V_61 :
case V_62 :
V_32 -> V_39 = NULL ;
break;
default:
V_56 = - V_63 ;
}
F_10 ( & V_32 -> V_40 , V_22 ) ;
if ( V_30 -> V_41 == V_42 && ! V_32 -> V_39 )
memset ( V_32 -> V_64 , 0 , V_32 -> V_65 * V_55 -> V_66 ) ;
return V_56 ;
}
static T_2 F_17 ( struct V_29 * V_30 )
{
struct V_5 * V_7 = F_16 ( V_30 ) ;
struct V_31 * V_32 ;
if ( V_30 -> V_41 == V_42 )
V_32 = & V_7 -> V_57 ;
else
V_32 = & V_7 -> V_58 ;
return F_18 ( V_30 -> V_67 , V_32 -> V_23 ) ;
}
static int F_19 ( struct V_29 * V_30 ,
struct V_68 * V_69 )
{
struct V_5 * V_7 = F_16 ( V_30 ) ;
struct V_31 * V_32 ;
int V_56 ;
if ( V_30 -> V_41 == V_42 )
V_32 = & V_7 -> V_57 ;
else
V_32 = & V_7 -> V_58 ;
V_56 = F_20 ( V_30 ,
F_21 ( V_69 ) ) ;
if ( V_56 >= 0 ) {
V_32 -> V_49 = V_30 -> V_67 -> V_49 ;
V_32 -> V_51 = V_30 -> V_67 -> V_51 ;
V_32 -> V_48 = F_22 ( V_69 ) ;
}
return V_56 ;
}
static int F_23 ( struct V_29 * V_30 )
{
struct V_5 * V_7 = F_16 ( V_30 ) ;
struct V_31 * V_32 ;
if ( V_30 -> V_41 == V_42 )
V_32 = & V_7 -> V_57 ;
else
V_32 = & V_7 -> V_58 ;
V_32 -> V_51 = NULL ;
V_32 -> V_49 = 0 ;
V_32 -> V_48 = 0 ;
return F_24 ( V_30 ) ;
}
static int F_25 ( struct V_29 * V_30 )
{
struct V_5 * V_7 = F_16 ( V_30 ) ;
struct V_70 * V_67 = V_30 -> V_67 ;
struct V_1 * V_1 ;
struct V_11 * V_71 ;
int V_72 , V_73 ;
int V_74 , V_75 ;
int V_76 , V_77 ;
V_1 = F_3 ( V_7 ) ;
V_71 = F_2 ( V_1 -> V_4 . V_13 , struct V_11 , V_14 ) ;
V_72 = V_71 -> V_72 ;
V_73 = V_71 -> V_73 ;
V_74 = V_71 -> V_74 ;
V_75 = V_71 -> V_75 ;
V_76 = V_71 -> V_76 ;
V_77 = V_71 -> V_77 ;
V_7 -> V_44 = 0 ;
V_67 -> V_78 = V_79 ;
if ( V_30 -> V_41 == V_42 ) {
F_26 ( & V_7 -> V_57 . V_40 ) ;
V_67 -> V_78 . V_80 = V_74 ;
switch ( V_72 ) {
case 3 :
V_67 -> V_78 . V_81 = V_82 ;
break;
case 4 :
V_67 -> V_78 . V_81 = V_83 ;
break;
default:
V_67 -> V_78 . V_81 = V_84 ;
break;
}
V_67 -> V_78 . V_85 = F_6 ( V_76 ) ;
V_67 -> V_78 . V_86 = 2 * V_7 -> V_57 . V_65
/ V_67 -> V_78 . V_87 ;
} else {
F_26 ( & V_7 -> V_58 . V_40 ) ;
V_67 -> V_78 . V_80 = V_75 ;
switch ( V_73 ) {
case 3 :
V_67 -> V_78 . V_81 = V_82 ;
break;
case 4 :
V_67 -> V_78 . V_81 = V_83 ;
break;
default:
V_67 -> V_78 . V_81 = V_84 ;
break;
}
V_67 -> V_78 . V_85 = F_6 ( V_77 ) ;
V_67 -> V_78 . V_86 = 2 * V_7 -> V_58 . V_65
/ V_67 -> V_78 . V_87 ;
}
V_67 -> V_78 . V_88 = V_67 -> V_78 . V_80 ;
V_67 -> V_78 . V_89 = V_67 -> V_78 . V_85 ;
F_27 ( V_67 , V_90 ) ;
return 0 ;
}
static int F_28 ( struct V_29 * V_30 )
{
return 0 ;
}
static int F_29 ( struct V_8 * V_10 )
{
struct V_5 * V_7 = F_4 ( V_10 ) ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_1 * V_1 ;
struct V_11 * V_71 ;
int V_56 ;
int V_76 , V_77 ;
V_1 = F_3 ( V_7 ) ;
V_71 = F_2 ( V_1 -> V_4 . V_13 , struct V_11 , V_14 ) ;
V_76 = V_71 -> V_76 ;
V_77 = V_71 -> V_77 ;
V_56 = F_30 ( & V_10 -> V_53 , - 1 , NULL , V_95 , 0 , & V_92 ) ;
if ( V_56 < 0 )
return V_56 ;
V_7 -> V_92 = V_92 ;
V_56 = F_31 ( V_7 -> V_92 , L_3 , 0 ,
V_76 ? 1 : 0 , V_77 ? 1 : 0 , & V_94 ) ;
if ( V_56 < 0 )
goto V_96;
strcpy ( V_94 -> V_97 , L_3 ) ;
V_94 -> V_98 = V_7 ;
V_7 -> V_94 = V_94 ;
F_32 ( V_94 , V_42 , & V_99 ) ;
F_32 ( V_94 , V_100 , & V_99 ) ;
strcpy ( V_92 -> V_101 , L_4 ) ;
strcpy ( V_92 -> V_102 , L_4 ) ;
sprintf ( V_92 -> V_103 , L_5 , V_10 -> V_104 ) ;
F_33 ( V_94 , V_105 ,
F_34 ( V_106 ) , 0 , V_107 ) ;
V_56 = F_35 ( V_92 ) ;
if ( ! V_56 ) {
F_36 ( V_10 , V_92 ) ;
return 0 ;
}
V_96:
F_37 ( V_92 ) ;
V_7 -> V_94 = NULL ;
V_7 -> V_92 = NULL ;
return V_56 ;
}
static int F_38 ( struct V_8 * V_10 )
{
struct V_91 * V_92 = F_39 ( V_10 ) ;
if ( V_92 )
return F_37 ( V_92 ) ;
return 0 ;
}
static void F_40 ( struct V_108 * V_53 )
{
F_41 ( V_53 , L_6 , F_42 ( V_53 ) ) ;
}
static int F_43 ( struct V_1 * V_12 )
{
struct V_5 * V_7 = & V_12 -> V_7 ;
int V_56 ;
V_7 -> V_109 . V_110 = F_29 ;
V_7 -> V_109 . remove = F_38 ;
V_7 -> V_109 . V_101 . V_97 = V_111 ;
V_7 -> V_10 . V_104 = 0 ;
V_7 -> V_10 . V_97 = V_111 ;
V_7 -> V_10 . V_53 . V_112 = F_40 ;
V_56 = F_44 ( & V_7 -> V_109 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_45 ( & V_7 -> V_10 ) ;
if ( V_56 )
F_46 ( & V_7 -> V_109 ) ;
return V_56 ;
}
static void F_47 ( struct V_1 * V_12 )
{
struct V_5 * V_7 = & V_12 -> V_7 ;
F_46 ( & V_7 -> V_109 ) ;
F_48 ( & V_7 -> V_10 ) ;
}
static inline void
F_49 ( struct V_31 * V_32 , struct V_17 * V_18 )
{
struct V_5 * V_7 = V_32 -> V_7 ;
struct V_1 * V_12 = F_3 ( V_7 ) ;
struct V_11 * V_55 = F_5 ( V_12 ) ;
int V_113 ;
if ( ! V_32 -> V_34 )
return;
V_32 -> V_34 = false ;
for ( V_113 = 0 ; V_113 < V_55 -> V_66 ; V_113 ++ ) {
if ( V_32 -> V_114 [ V_113 ] . V_20 ) {
F_50 ( V_18 , V_32 -> V_114 [ V_113 ] . V_20 ) ;
F_51 ( V_18 , V_32 -> V_114 [ V_113 ] . V_20 ) ;
V_32 -> V_114 [ V_113 ] . V_20 = NULL ;
}
}
if ( F_52 ( V_18 ) )
F_13 ( & V_7 -> V_10 . V_53 ,
L_7 , V_36 , __LINE__ ) ;
}
static void F_53 ( const struct V_11 * V_55 ,
struct V_115 * V_116 ,
unsigned int V_117 , bool V_118 )
{
int V_119 , V_120 , V_121 ;
T_3 V_122 ;
if ( V_118 ) {
V_119 = V_55 -> V_76 ;
V_120 = V_55 -> V_74 ;
V_121 = V_55 -> V_72 ;
} else {
V_119 = V_55 -> V_77 ;
V_120 = V_55 -> V_75 ;
V_121 = V_55 -> V_73 ;
}
V_122 = F_6 ( V_119 ) * V_121 *
F_54 ( V_120 , V_117 / ( 1 << ( V_116 -> V_123 - 1 ) ) ) ;
V_116 -> V_124 = F_55 ( F_56 ( T_3 , V_122 ,
F_57 ( V_116 -> V_124 ) ) ) ;
}
static int
F_58 ( struct V_125 * V_126 , struct V_2 * V_127 )
{
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_128 * V_129 = V_126 -> V_129 ;
struct V_130 * V_131 = V_129 -> V_131 ;
struct V_108 * V_53 = & V_7 -> V_10 . V_53 ;
struct V_31 * V_32 ;
struct V_11 * V_55 ;
struct V_132 * V_133 ;
int V_134 ;
V_55 = F_2 ( V_127 -> V_13 , struct V_11 , V_14 ) ;
V_133 = F_59 ( V_129 , V_135 , F_60 ( V_136 ) ) ;
if ( F_61 ( V_133 ) )
return F_62 ( V_133 ) ;
V_137 . V_138 = V_133 [ V_139 ] . V_104 ;
V_140 . V_141 = V_133 [ V_142 ] . V_104 ;
V_143 . V_144 = V_133 [ V_145 ] . V_104 ;
V_146 . V_144 = V_133 [ V_147 ] . V_104 ;
V_148 . V_149 = V_133 [ V_150 ] . V_104 ;
V_151 . V_149 = V_133 [ V_152 ] . V_104 ;
V_153 . V_149 = V_133 [ V_154 ] . V_104 ;
V_155 . V_149 = V_133 [ V_156 ] . V_104 ;
V_157 . V_141 = V_133 [ V_158 ] . V_104 ;
V_159 . V_141 = V_133 [ V_160 ] . V_104 ;
V_161 . V_141 = V_133 [ V_162 ] . V_104 ;
V_163 . V_141 = V_133 [ V_164 ] . V_104 ;
V_148 . V_165 = F_6 ( V_55 -> V_77 ) ;
V_148 . V_166 = F_63 ( V_55 -> V_77 ) ;
V_151 . V_165 = F_6 ( V_55 -> V_76 ) ;
V_151 . V_166 = F_63 ( V_55 -> V_76 ) ;
V_167 . V_165 = F_6 ( V_55 -> V_77 ) ;
V_167 . V_166 = F_63 ( V_55 -> V_77 ) ;
V_168 . V_165 = F_6 ( V_55 -> V_76 ) ;
V_168 . V_166 = F_63 ( V_55 -> V_76 ) ;
V_169 . V_170 = V_55 -> V_73 ;
V_169 . V_171 = V_55 -> V_73 * 8 ;
V_172 . V_170 = V_55 -> V_72 ;
V_172 . V_171 = V_55 -> V_72 * 8 ;
snprintf ( V_173 , sizeof( V_173 ) , L_8 , V_55 -> V_74 ) ;
snprintf ( V_174 , sizeof( V_174 ) , L_8 , V_55 -> V_75 ) ;
V_134 = F_64 ( V_126 , V_127 ) ;
if ( V_134 < 0 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return V_134 ;
}
V_140 . V_175 = V_134 ;
V_12 -> V_176 = V_134 ;
V_12 -> V_177 = 0 ;
V_134 = F_64 ( V_126 , V_127 ) ;
if ( V_134 < 0 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return V_134 ;
}
V_157 . V_175 = V_134 ;
V_159 . V_175 = V_134 ;
V_12 -> V_178 = V_134 ;
V_12 -> V_179 = 0 ;
V_134 = F_64 ( V_126 , V_127 ) ;
if ( V_134 < 0 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return V_134 ;
}
V_161 . V_175 = V_134 ;
V_163 . V_175 = V_134 ;
V_12 -> V_180 = V_134 ;
V_12 -> V_181 = 0 ;
V_12 -> V_182 = F_65 ( V_131 , & V_183 ) ;
if ( ! V_12 -> V_182 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return V_134 ;
}
V_12 -> V_184 = F_65 ( V_131 , & V_185 ) ;
if ( ! V_12 -> V_184 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return V_134 ;
}
V_7 -> V_57 . V_7 = V_7 ;
V_7 -> V_58 . V_7 = V_7 ;
F_53 ( V_55 , & V_185 , 1000 , true ) ;
F_53 ( V_55 , & V_183 , 1000 , false ) ;
F_53 ( V_55 , & V_186 , 8000 , true ) ;
F_53 ( V_55 , & V_187 , 8000 , false ) ;
V_187 . V_188 = V_183 . V_188 ;
V_186 . V_188 = V_185 . V_188 ;
V_134 = F_66 ( V_127 , V_189 , V_190 , NULL ,
NULL ) ;
if ( V_134 )
return V_134 ;
V_32 = & V_12 -> V_7 . V_58 ;
V_32 -> V_65 = V_187 . V_124 ;
V_32 -> V_114 = F_67 ( V_55 -> V_66 , sizeof( struct V_26 ) ,
V_106 ) ;
if ( ! V_32 -> V_114 ) {
V_134 = - V_191 ;
goto V_192;
}
V_32 -> V_64 = F_67 ( V_55 -> V_66 , V_32 -> V_65 , V_106 ) ;
if ( ! V_32 -> V_64 ) {
V_32 -> V_65 = 0 ;
V_134 = - V_191 ;
goto V_192;
}
V_32 = & V_12 -> V_7 . V_57 ;
V_32 -> V_65 = V_186 . V_124 ;
V_32 -> V_114 = F_67 ( V_55 -> V_66 , sizeof( struct V_26 ) ,
V_106 ) ;
if ( ! V_32 -> V_114 ) {
V_134 = - V_191 ;
goto V_192;
}
V_32 -> V_64 = F_67 ( V_55 -> V_66 , V_32 -> V_65 , V_106 ) ;
if ( ! V_32 -> V_64 ) {
V_32 -> V_65 = 0 ;
V_134 = - V_191 ;
goto V_193;
}
V_134 = F_43 ( V_12 ) ;
if ( V_134 )
goto V_193;
return 0 ;
V_193:
F_68 ( V_12 -> V_7 . V_57 . V_114 ) ;
F_68 ( V_12 -> V_7 . V_58 . V_114 ) ;
F_68 ( V_12 -> V_7 . V_57 . V_64 ) ;
F_68 ( V_12 -> V_7 . V_58 . V_64 ) ;
V_192:
F_69 ( V_127 ) ;
return V_134 ;
}
static int
F_70 ( struct V_2 * V_127 , unsigned V_194 , unsigned V_195 )
{
struct V_128 * V_129 = V_127 -> V_196 -> V_129 ;
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_11 * V_71 = F_5 ( V_12 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_130 * V_131 = V_129 -> V_131 ;
struct V_108 * V_53 = & V_7 -> V_10 . V_53 ;
struct V_19 * V_20 ;
struct V_17 * V_18 ;
struct V_31 * V_32 ;
int V_197 , V_113 ;
if ( V_195 > 1 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return - V_63 ;
}
if ( V_194 == V_12 -> V_176 ) {
if ( V_195 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return - V_63 ;
}
return 0 ;
}
if ( V_194 == V_12 -> V_178 ) {
V_18 = V_12 -> V_182 ;
V_32 = & V_7 -> V_58 ;
F_71 ( V_131 , V_127 , V_18 ) ;
V_12 -> V_179 = V_195 ;
V_197 = V_32 -> V_65 ;
} else if ( V_194 == V_12 -> V_180 ) {
unsigned int V_117 , V_198 ;
struct V_115 * V_116 ;
V_18 = V_12 -> V_184 ;
V_32 = & V_7 -> V_57 ;
F_71 ( V_131 , V_127 , V_18 ) ;
V_12 -> V_181 = V_195 ;
if ( V_131 -> V_199 == V_200 ) {
V_116 = & V_185 ;
V_117 = 1000 ;
} else {
V_116 = & V_186 ;
V_117 = 8000 ;
}
V_7 -> V_47 = V_71 -> V_72 *
F_6 ( V_71 -> V_76 ) ;
V_198 = V_71 -> V_74 * V_7 -> V_47 ;
V_7 -> V_46 = V_117 / ( 1 << ( V_116 -> V_123 - 1 ) ) ;
V_7 -> V_43 = F_56 (unsigned int, rate / uac2->p_interval,
prm->max_psize) ;
if ( V_7 -> V_43 < V_32 -> V_65 )
V_7 -> V_45 = V_198 % V_7 -> V_46 ;
else
V_7 -> V_45 = 0 ;
V_197 = V_7 -> V_43 ;
V_7 -> V_44 = 0 ;
} else {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return - V_63 ;
}
if ( V_195 == 0 ) {
F_49 ( V_32 , V_18 ) ;
return 0 ;
}
V_32 -> V_34 = true ;
F_72 ( V_18 ) ;
for ( V_113 = 0 ; V_113 < V_71 -> V_66 ; V_113 ++ ) {
if ( ! V_32 -> V_114 [ V_113 ] . V_20 ) {
V_20 = F_73 ( V_18 , V_52 ) ;
if ( V_20 == NULL )
return - V_191 ;
V_32 -> V_114 [ V_113 ] . V_20 = V_20 ;
V_32 -> V_114 [ V_113 ] . V_33 = V_32 ;
V_20 -> V_201 = 0 ;
V_20 -> V_28 = & V_32 -> V_114 [ V_113 ] ;
V_20 -> V_38 = V_197 ;
V_20 -> V_202 = F_7 ;
V_20 -> V_50 = V_32 -> V_64 + V_113 * V_32 -> V_65 ;
}
if ( F_12 ( V_18 , V_32 -> V_114 [ V_113 ] . V_20 , V_52 ) )
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
}
return 0 ;
}
static int
F_74 ( struct V_2 * V_127 , unsigned V_194 )
{
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
if ( V_194 == V_12 -> V_176 )
return V_12 -> V_177 ;
else if ( V_194 == V_12 -> V_178 )
return V_12 -> V_179 ;
else if ( V_194 == V_12 -> V_180 )
return V_12 -> V_181 ;
else
F_13 ( & V_7 -> V_10 . V_53 ,
L_9 ,
V_36 , __LINE__ , V_194 ) ;
return - V_63 ;
}
static void
F_75 ( struct V_2 * V_127 )
{
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
F_49 ( & V_7 -> V_57 , V_12 -> V_184 ) ;
V_12 -> V_181 = 0 ;
F_49 ( & V_7 -> V_58 , V_12 -> V_182 ) ;
V_12 -> V_179 = 0 ;
}
static int
F_76 ( struct V_2 * V_127 , const struct V_203 * V_204 )
{
struct V_19 * V_20 = V_127 -> V_196 -> V_129 -> V_20 ;
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_11 * V_71 ;
T_3 V_205 = F_57 ( V_204 -> V_206 ) ;
T_3 V_207 = F_57 ( V_204 -> V_208 ) ;
T_3 V_209 = F_57 ( V_204 -> V_210 ) ;
T_4 V_211 = ( V_207 >> 8 ) & 0xff ;
T_4 V_212 = V_209 >> 8 ;
int V_213 = - V_214 ;
int V_74 , V_75 ;
V_71 = F_5 ( V_12 ) ;
V_74 = V_71 -> V_74 ;
V_75 = V_71 -> V_75 ;
if ( V_212 == V_215 ) {
struct V_216 V_217 ;
memset ( & V_217 , 0 , sizeof( struct V_216 ) ) ;
if ( V_211 == V_218 )
V_217 . V_219 = V_74 ;
else if ( V_211 == V_220 )
V_217 . V_219 = V_75 ;
V_213 = F_56 ( unsigned , V_205 , sizeof V_217 ) ;
memcpy ( V_20 -> V_50 , & V_217 , V_213 ) ;
} else if ( V_212 == V_221 ) {
* ( T_4 * ) V_20 -> V_50 = 1 ;
V_213 = F_56 ( unsigned , V_205 , 1 ) ;
} else {
F_13 ( & V_7 -> V_10 . V_53 ,
L_10 ,
V_36 , __LINE__ , V_212 ) ;
}
return V_213 ;
}
static int
F_77 ( struct V_2 * V_127 , const struct V_203 * V_204 )
{
struct V_19 * V_20 = V_127 -> V_196 -> V_129 -> V_20 ;
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_11 * V_71 ;
T_3 V_205 = F_57 ( V_204 -> V_206 ) ;
T_3 V_207 = F_57 ( V_204 -> V_208 ) ;
T_3 V_209 = F_57 ( V_204 -> V_210 ) ;
T_4 V_211 = ( V_207 >> 8 ) & 0xff ;
T_4 V_212 = V_209 >> 8 ;
struct V_222 V_223 ;
int V_213 = - V_214 ;
int V_74 , V_75 ;
V_71 = F_5 ( V_12 ) ;
V_74 = V_71 -> V_74 ;
V_75 = V_71 -> V_75 ;
if ( V_212 == V_215 ) {
if ( V_211 == V_218 )
V_223 . V_224 = V_74 ;
else if ( V_211 == V_220 )
V_223 . V_224 = V_75 ;
else
return - V_214 ;
V_223 . V_225 = V_223 . V_224 ;
V_223 . V_226 = 0 ;
V_223 . V_227 = 1 ;
V_213 = F_56 ( unsigned , V_205 , sizeof V_223 ) ;
memcpy ( V_20 -> V_50 , & V_223 , V_213 ) ;
} else {
F_13 ( & V_7 -> V_10 . V_53 ,
L_10 ,
V_36 , __LINE__ , V_212 ) ;
}
return V_213 ;
}
static int
F_78 ( struct V_2 * V_127 , const struct V_203 * V_204 )
{
if ( V_204 -> V_228 == V_229 )
return F_76 ( V_127 , V_204 ) ;
else if ( V_204 -> V_228 == V_230 )
return F_77 ( V_127 , V_204 ) ;
else
return - V_214 ;
}
static int
F_79 ( struct V_2 * V_127 , const struct V_203 * V_204 )
{
T_3 V_205 = F_57 ( V_204 -> V_206 ) ;
T_3 V_209 = F_57 ( V_204 -> V_210 ) ;
T_4 V_212 = V_209 >> 8 ;
if ( V_212 == V_215 )
return V_205 ;
return - V_214 ;
}
static int
F_80 ( struct V_2 * V_127 , const struct V_203 * V_204 )
{
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
T_3 V_207 = F_57 ( V_204 -> V_208 ) ;
T_4 V_194 = V_207 & 0xff ;
if ( V_194 != V_12 -> V_176 ) {
F_13 ( & V_7 -> V_10 . V_53 ,
L_7 , V_36 , __LINE__ ) ;
return - V_214 ;
}
if ( V_204 -> V_231 & V_232 )
return F_78 ( V_127 , V_204 ) ;
else if ( V_204 -> V_228 == V_229 )
return F_79 ( V_127 , V_204 ) ;
return - V_214 ;
}
static int
F_81 ( struct V_2 * V_127 , const struct V_203 * V_204 )
{
struct V_128 * V_129 = V_127 -> V_196 -> V_129 ;
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_19 * V_20 = V_129 -> V_20 ;
T_3 V_205 = F_57 ( V_204 -> V_206 ) ;
int V_213 = - V_214 ;
if ( ( V_204 -> V_231 & V_233 ) != V_234 )
return - V_214 ;
if ( ( V_204 -> V_231 & V_235 ) == V_236 )
V_213 = F_80 ( V_127 , V_204 ) ;
else
F_13 ( & V_7 -> V_10 . V_53 , L_7 , V_36 , __LINE__ ) ;
if ( V_213 >= 0 ) {
V_20 -> V_38 = V_213 ;
V_20 -> V_201 = V_213 < V_205 ;
V_213 = F_12 ( V_129 -> V_131 -> V_237 , V_20 , V_52 ) ;
if ( V_213 < 0 ) {
F_13 ( & V_7 -> V_10 . V_53 ,
L_7 , V_36 , __LINE__ ) ;
V_20 -> V_25 = 0 ;
}
}
return V_213 ;
}
static inline struct V_11 * F_82 ( struct V_238 * V_239 )
{
return F_2 ( F_83 ( V_239 ) , struct V_11 ,
V_14 . V_240 ) ;
}
static void F_84 ( struct V_238 * V_239 )
{
struct V_11 * V_71 = F_82 ( V_239 ) ;
F_85 ( & V_71 -> V_14 ) ;
}
static void F_86 ( struct V_241 * V_3 )
{
struct V_11 * V_71 ;
V_71 = F_2 ( V_3 , struct V_11 , V_14 ) ;
F_68 ( V_71 ) ;
}
static struct V_241 * F_87 ( void )
{
struct V_11 * V_71 ;
V_71 = F_88 ( sizeof( * V_71 ) , V_106 ) ;
if ( ! V_71 )
return F_89 ( - V_191 ) ;
F_90 ( & V_71 -> V_40 ) ;
V_71 -> V_14 . V_242 = F_86 ;
F_91 ( & V_71 -> V_14 . V_240 , L_11 ,
& V_243 ) ;
V_71 -> V_76 = V_244 ;
V_71 -> V_74 = V_245 ;
V_71 -> V_72 = V_246 ;
V_71 -> V_77 = V_247 ;
V_71 -> V_75 = V_248 ;
V_71 -> V_73 = V_249 ;
V_71 -> V_66 = V_250 ;
return & V_71 -> V_14 ;
}
static void F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_12 ;
struct V_11 * V_71 ;
V_12 = F_1 ( V_3 ) ;
V_71 = F_2 ( V_3 -> V_13 , struct V_11 , V_14 ) ;
F_68 ( V_12 ) ;
F_93 ( & V_71 -> V_40 ) ;
-- V_71 -> V_251 ;
F_94 ( & V_71 -> V_40 ) ;
}
static void F_95 ( struct V_125 * V_217 , struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_31 * V_32 ;
F_47 ( V_12 ) ;
V_32 = & V_12 -> V_7 . V_57 ;
F_68 ( V_32 -> V_64 ) ;
V_32 = & V_12 -> V_7 . V_58 ;
F_68 ( V_32 -> V_64 ) ;
F_68 ( V_32 -> V_114 ) ;
F_69 ( V_3 ) ;
}
static struct V_2 * F_96 ( struct V_241 * V_13 )
{
struct V_1 * V_12 ;
struct V_11 * V_71 ;
V_12 = F_88 ( sizeof( * V_12 ) , V_106 ) ;
if ( V_12 == NULL )
return F_89 ( - V_191 ) ;
V_71 = F_2 ( V_13 , struct V_11 , V_14 ) ;
F_93 ( & V_71 -> V_40 ) ;
++ V_71 -> V_251 ;
F_94 ( & V_71 -> V_40 ) ;
V_12 -> V_4 . V_97 = L_12 ;
V_12 -> V_4 . V_252 = F_58 ;
V_12 -> V_4 . V_253 = F_95 ;
V_12 -> V_4 . V_254 = F_70 ;
V_12 -> V_4 . V_255 = F_74 ;
V_12 -> V_4 . V_256 = F_75 ;
V_12 -> V_4 . V_257 = F_81 ;
V_12 -> V_4 . V_258 = F_92 ;
return & V_12 -> V_4 ;
}
