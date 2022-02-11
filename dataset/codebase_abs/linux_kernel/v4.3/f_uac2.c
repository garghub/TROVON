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
struct V_31 * V_32 ;
unsigned long V_22 ;
int V_55 = 0 ;
if ( V_30 -> V_41 == V_42 )
V_32 = & V_7 -> V_56 ;
else
V_32 = & V_7 -> V_57 ;
F_9 ( & V_32 -> V_40 , V_22 ) ;
V_32 -> V_23 = 0 ;
switch ( V_54 ) {
case V_58 :
case V_59 :
V_32 -> V_39 = V_30 ;
break;
case V_60 :
case V_61 :
V_32 -> V_39 = NULL ;
break;
default:
V_55 = - V_62 ;
}
F_10 ( & V_32 -> V_40 , V_22 ) ;
if ( V_30 -> V_41 == V_42 && ! V_32 -> V_39 )
memset ( V_32 -> V_63 , 0 , V_32 -> V_64 * V_65 ) ;
return V_55 ;
}
static T_2 F_17 ( struct V_29 * V_30 )
{
struct V_5 * V_7 = F_16 ( V_30 ) ;
struct V_31 * V_32 ;
if ( V_30 -> V_41 == V_42 )
V_32 = & V_7 -> V_56 ;
else
V_32 = & V_7 -> V_57 ;
return F_18 ( V_30 -> V_66 , V_32 -> V_23 ) ;
}
static int F_19 ( struct V_29 * V_30 ,
struct V_67 * V_68 )
{
struct V_5 * V_7 = F_16 ( V_30 ) ;
struct V_31 * V_32 ;
int V_55 ;
if ( V_30 -> V_41 == V_42 )
V_32 = & V_7 -> V_56 ;
else
V_32 = & V_7 -> V_57 ;
V_55 = F_20 ( V_30 ,
F_21 ( V_68 ) ) ;
if ( V_55 >= 0 ) {
V_32 -> V_49 = V_30 -> V_66 -> V_49 ;
V_32 -> V_51 = V_30 -> V_66 -> V_51 ;
V_32 -> V_48 = F_22 ( V_68 ) ;
}
return V_55 ;
}
static int F_23 ( struct V_29 * V_30 )
{
struct V_5 * V_7 = F_16 ( V_30 ) ;
struct V_31 * V_32 ;
if ( V_30 -> V_41 == V_42 )
V_32 = & V_7 -> V_56 ;
else
V_32 = & V_7 -> V_57 ;
V_32 -> V_51 = NULL ;
V_32 -> V_49 = 0 ;
V_32 -> V_48 = 0 ;
return F_24 ( V_30 ) ;
}
static int F_25 ( struct V_29 * V_30 )
{
struct V_5 * V_7 = F_16 ( V_30 ) ;
struct V_69 * V_66 = V_30 -> V_66 ;
struct V_1 * V_1 ;
struct V_11 * V_70 ;
int V_71 , V_72 ;
int V_73 , V_74 ;
int V_75 , V_76 ;
V_1 = F_3 ( V_7 ) ;
V_70 = F_2 ( V_1 -> V_4 . V_13 , struct V_11 , V_14 ) ;
V_71 = V_70 -> V_71 ;
V_72 = V_70 -> V_72 ;
V_73 = V_70 -> V_73 ;
V_74 = V_70 -> V_74 ;
V_75 = V_70 -> V_75 ;
V_76 = V_70 -> V_76 ;
V_7 -> V_44 = 0 ;
V_66 -> V_77 = V_78 ;
if ( V_30 -> V_41 == V_42 ) {
F_26 ( & V_7 -> V_56 . V_40 ) ;
V_66 -> V_77 . V_79 = V_73 ;
switch ( V_71 ) {
case 3 :
V_66 -> V_77 . V_80 = V_81 ;
break;
case 4 :
V_66 -> V_77 . V_80 = V_82 ;
break;
default:
V_66 -> V_77 . V_80 = V_83 ;
break;
}
V_66 -> V_77 . V_84 = F_6 ( V_75 ) ;
V_66 -> V_77 . V_85 = 2 * V_7 -> V_56 . V_64
/ V_66 -> V_77 . V_86 ;
} else {
F_26 ( & V_7 -> V_57 . V_40 ) ;
V_66 -> V_77 . V_79 = V_74 ;
switch ( V_72 ) {
case 3 :
V_66 -> V_77 . V_80 = V_81 ;
break;
case 4 :
V_66 -> V_77 . V_80 = V_82 ;
break;
default:
V_66 -> V_77 . V_80 = V_83 ;
break;
}
V_66 -> V_77 . V_84 = F_6 ( V_76 ) ;
V_66 -> V_77 . V_85 = 2 * V_7 -> V_57 . V_64
/ V_66 -> V_77 . V_86 ;
}
V_66 -> V_77 . V_87 = V_66 -> V_77 . V_79 ;
V_66 -> V_77 . V_88 = V_66 -> V_77 . V_84 ;
F_27 ( V_66 , V_89 ) ;
return 0 ;
}
static int F_28 ( struct V_29 * V_30 )
{
return 0 ;
}
static int F_29 ( struct V_8 * V_10 )
{
struct V_5 * V_7 = F_4 ( V_10 ) ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_1 * V_1 ;
struct V_11 * V_70 ;
int V_55 ;
int V_75 , V_76 ;
V_1 = F_3 ( V_7 ) ;
V_70 = F_2 ( V_1 -> V_4 . V_13 , struct V_11 , V_14 ) ;
V_75 = V_70 -> V_75 ;
V_76 = V_70 -> V_76 ;
V_55 = F_30 ( & V_10 -> V_53 , - 1 , NULL , V_94 , 0 , & V_91 ) ;
if ( V_55 < 0 )
return V_55 ;
V_7 -> V_91 = V_91 ;
V_55 = F_31 ( V_7 -> V_91 , L_3 , 0 ,
V_75 ? 1 : 0 , V_76 ? 1 : 0 , & V_93 ) ;
if ( V_55 < 0 )
goto V_95;
strcpy ( V_93 -> V_96 , L_3 ) ;
V_93 -> V_97 = V_7 ;
V_7 -> V_93 = V_93 ;
F_32 ( V_93 , V_42 , & V_98 ) ;
F_32 ( V_93 , V_99 , & V_98 ) ;
strcpy ( V_91 -> V_100 , L_4 ) ;
strcpy ( V_91 -> V_101 , L_4 ) ;
sprintf ( V_91 -> V_102 , L_5 , V_10 -> V_103 ) ;
F_33 ( V_93 , V_104 ,
F_34 ( V_105 ) , 0 , V_106 ) ;
V_55 = F_35 ( V_91 ) ;
if ( ! V_55 ) {
F_36 ( V_10 , V_91 ) ;
return 0 ;
}
V_95:
F_37 ( V_91 ) ;
V_7 -> V_93 = NULL ;
V_7 -> V_91 = NULL ;
return V_55 ;
}
static int F_38 ( struct V_8 * V_10 )
{
struct V_90 * V_91 = F_39 ( V_10 ) ;
if ( V_91 )
return F_37 ( V_91 ) ;
return 0 ;
}
static void F_40 ( struct V_107 * V_53 )
{
F_41 ( V_53 , L_6 , F_42 ( V_53 ) ) ;
}
static int F_43 ( struct V_1 * V_12 )
{
struct V_5 * V_7 = & V_12 -> V_7 ;
int V_55 ;
V_7 -> V_108 . V_109 = F_29 ;
V_7 -> V_108 . remove = F_38 ;
V_7 -> V_108 . V_100 . V_96 = V_110 ;
V_7 -> V_10 . V_103 = 0 ;
V_7 -> V_10 . V_96 = V_110 ;
V_7 -> V_10 . V_53 . V_111 = F_40 ;
V_55 = F_44 ( & V_7 -> V_108 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_45 ( & V_7 -> V_10 ) ;
if ( V_55 )
F_46 ( & V_7 -> V_108 ) ;
return V_55 ;
}
static void F_47 ( struct V_1 * V_12 )
{
struct V_5 * V_7 = & V_12 -> V_7 ;
F_46 ( & V_7 -> V_108 ) ;
F_48 ( & V_7 -> V_10 ) ;
}
static inline void
F_49 ( struct V_31 * V_32 , struct V_17 * V_18 )
{
struct V_5 * V_7 = V_32 -> V_7 ;
int V_112 ;
if ( ! V_32 -> V_34 )
return;
V_32 -> V_34 = false ;
for ( V_112 = 0 ; V_112 < V_65 ; V_112 ++ ) {
if ( V_32 -> V_113 [ V_112 ] . V_20 ) {
F_50 ( V_18 , V_32 -> V_113 [ V_112 ] . V_20 ) ;
F_51 ( V_18 , V_32 -> V_113 [ V_112 ] . V_20 ) ;
V_32 -> V_113 [ V_112 ] . V_20 = NULL ;
}
}
if ( F_52 ( V_18 ) )
F_13 ( & V_7 -> V_10 . V_53 ,
L_7 , V_36 , __LINE__ ) ;
}
static void F_53 ( const struct V_11 * V_114 ,
struct V_115 * V_116 ,
unsigned int V_117 , bool V_118 )
{
int V_119 , V_120 , V_121 ;
T_3 V_122 ;
if ( V_118 ) {
V_119 = V_114 -> V_75 ;
V_120 = V_114 -> V_73 ;
V_121 = V_114 -> V_71 ;
} else {
V_119 = V_114 -> V_76 ;
V_120 = V_114 -> V_74 ;
V_121 = V_114 -> V_72 ;
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
struct V_107 * V_53 = & V_7 -> V_10 . V_53 ;
struct V_31 * V_32 ;
struct V_11 * V_114 ;
struct V_132 * V_133 ;
int V_134 ;
V_114 = F_2 ( V_127 -> V_13 , struct V_11 , V_14 ) ;
V_133 = F_59 ( V_129 , V_135 , F_60 ( V_136 ) ) ;
if ( F_61 ( V_133 ) )
return F_62 ( V_133 ) ;
V_137 . V_138 = V_133 [ V_139 ] . V_103 ;
V_140 . V_141 = V_133 [ V_142 ] . V_103 ;
V_143 . V_144 = V_133 [ V_145 ] . V_103 ;
V_146 . V_144 = V_133 [ V_147 ] . V_103 ;
V_148 . V_149 = V_133 [ V_150 ] . V_103 ;
V_151 . V_149 = V_133 [ V_152 ] . V_103 ;
V_153 . V_149 = V_133 [ V_154 ] . V_103 ;
V_155 . V_149 = V_133 [ V_156 ] . V_103 ;
V_157 . V_141 = V_133 [ V_158 ] . V_103 ;
V_159 . V_141 = V_133 [ V_160 ] . V_103 ;
V_161 . V_141 = V_133 [ V_162 ] . V_103 ;
V_163 . V_141 = V_133 [ V_164 ] . V_103 ;
V_148 . V_165 = F_6 ( V_114 -> V_76 ) ;
V_148 . V_166 = F_63 ( V_114 -> V_76 ) ;
V_151 . V_165 = F_6 ( V_114 -> V_75 ) ;
V_151 . V_166 = F_63 ( V_114 -> V_75 ) ;
V_167 . V_165 = F_6 ( V_114 -> V_76 ) ;
V_167 . V_166 = F_63 ( V_114 -> V_76 ) ;
V_168 . V_165 = F_6 ( V_114 -> V_75 ) ;
V_168 . V_166 = F_63 ( V_114 -> V_75 ) ;
V_169 . V_170 = V_114 -> V_72 ;
V_169 . V_171 = V_114 -> V_72 * 8 ;
V_172 . V_170 = V_114 -> V_71 ;
V_172 . V_171 = V_114 -> V_71 * 8 ;
snprintf ( V_173 , sizeof( V_173 ) , L_8 , V_114 -> V_73 ) ;
snprintf ( V_174 , sizeof( V_174 ) , L_8 , V_114 -> V_74 ) ;
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
goto V_55;
}
V_12 -> V_182 -> V_184 = V_12 ;
V_12 -> V_185 = F_65 ( V_131 , & V_186 ) ;
if ( ! V_12 -> V_185 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
goto V_55;
}
V_12 -> V_185 -> V_184 = V_12 ;
V_7 -> V_56 . V_7 = V_7 ;
V_7 -> V_57 . V_7 = V_7 ;
F_53 ( V_114 , & V_186 , 1000 , true ) ;
F_53 ( V_114 , & V_183 , 1000 , false ) ;
F_53 ( V_114 , & V_187 , 8000 , true ) ;
F_53 ( V_114 , & V_188 , 8000 , false ) ;
V_188 . V_189 = V_183 . V_189 ;
V_187 . V_189 = V_186 . V_189 ;
V_134 = F_66 ( V_127 , V_190 , V_191 , NULL ) ;
if ( V_134 )
goto V_55;
V_32 = & V_12 -> V_7 . V_57 ;
V_32 -> V_64 = V_188 . V_124 ;
V_32 -> V_63 = F_67 ( V_32 -> V_64 * V_65 , V_105 ) ;
if ( ! V_32 -> V_63 ) {
V_32 -> V_64 = 0 ;
goto V_192;
}
V_32 = & V_12 -> V_7 . V_56 ;
V_32 -> V_64 = V_187 . V_124 ;
V_32 -> V_63 = F_67 ( V_32 -> V_64 * V_65 , V_105 ) ;
if ( ! V_32 -> V_63 ) {
V_32 -> V_64 = 0 ;
goto V_192;
}
V_134 = F_43 ( V_12 ) ;
if ( V_134 )
goto V_192;
return 0 ;
V_192:
F_68 ( V_127 ) ;
V_55:
F_69 ( V_12 -> V_7 . V_56 . V_63 ) ;
F_69 ( V_12 -> V_7 . V_57 . V_63 ) ;
if ( V_12 -> V_185 )
V_12 -> V_185 -> V_184 = NULL ;
if ( V_12 -> V_182 )
V_12 -> V_182 -> V_184 = NULL ;
return - V_62 ;
}
static int
F_70 ( struct V_2 * V_127 , unsigned V_193 , unsigned V_194 )
{
struct V_128 * V_129 = V_127 -> V_195 -> V_129 ;
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_130 * V_131 = V_129 -> V_131 ;
struct V_107 * V_53 = & V_7 -> V_10 . V_53 ;
struct V_19 * V_20 ;
struct V_17 * V_18 ;
struct V_31 * V_32 ;
int V_196 , V_112 ;
if ( V_194 > 1 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return - V_62 ;
}
if ( V_193 == V_12 -> V_176 ) {
if ( V_194 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return - V_62 ;
}
return 0 ;
}
if ( V_193 == V_12 -> V_178 ) {
V_18 = V_12 -> V_182 ;
V_32 = & V_7 -> V_57 ;
F_71 ( V_131 , V_127 , V_18 ) ;
V_12 -> V_179 = V_194 ;
V_196 = V_32 -> V_64 ;
} else if ( V_193 == V_12 -> V_180 ) {
struct V_11 * V_70 = F_5 ( V_12 ) ;
unsigned int V_117 , V_197 ;
struct V_115 * V_116 ;
V_18 = V_12 -> V_185 ;
V_32 = & V_7 -> V_56 ;
F_71 ( V_131 , V_127 , V_18 ) ;
V_12 -> V_181 = V_194 ;
if ( V_131 -> V_198 == V_199 ) {
V_116 = & V_186 ;
V_117 = 1000 ;
} else {
V_116 = & V_187 ;
V_117 = 8000 ;
}
V_7 -> V_47 = V_70 -> V_71 *
F_6 ( V_70 -> V_75 ) ;
V_197 = V_70 -> V_73 * V_7 -> V_47 ;
V_7 -> V_46 = V_117 / ( 1 << ( V_116 -> V_123 - 1 ) ) ;
V_7 -> V_43 = F_56 (unsigned int, rate / uac2->p_interval,
prm->max_psize) ;
if ( V_7 -> V_43 < V_32 -> V_64 )
V_7 -> V_45 = V_197 % V_7 -> V_46 ;
else
V_7 -> V_45 = 0 ;
V_196 = V_7 -> V_43 ;
V_7 -> V_44 = 0 ;
} else {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return - V_62 ;
}
if ( V_194 == 0 ) {
F_49 ( V_32 , V_18 ) ;
return 0 ;
}
V_32 -> V_34 = true ;
F_72 ( V_18 ) ;
for ( V_112 = 0 ; V_112 < V_65 ; V_112 ++ ) {
if ( ! V_32 -> V_113 [ V_112 ] . V_20 ) {
V_20 = F_73 ( V_18 , V_52 ) ;
if ( V_20 == NULL )
return - V_200 ;
V_32 -> V_113 [ V_112 ] . V_20 = V_20 ;
V_32 -> V_113 [ V_112 ] . V_33 = V_32 ;
V_20 -> V_201 = 0 ;
V_20 -> V_28 = & V_32 -> V_113 [ V_112 ] ;
V_20 -> V_38 = V_196 ;
V_20 -> V_202 = F_7 ;
V_20 -> V_50 = V_32 -> V_63 + V_112 * V_32 -> V_64 ;
}
if ( F_12 ( V_18 , V_32 -> V_113 [ V_112 ] . V_20 , V_52 ) )
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
}
return 0 ;
}
static int
F_74 ( struct V_2 * V_127 , unsigned V_193 )
{
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
if ( V_193 == V_12 -> V_176 )
return V_12 -> V_177 ;
else if ( V_193 == V_12 -> V_178 )
return V_12 -> V_179 ;
else if ( V_193 == V_12 -> V_180 )
return V_12 -> V_181 ;
else
F_13 ( & V_7 -> V_10 . V_53 ,
L_9 ,
V_36 , __LINE__ , V_193 ) ;
return - V_62 ;
}
static void
F_75 ( struct V_2 * V_127 )
{
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
F_49 ( & V_7 -> V_56 , V_12 -> V_185 ) ;
V_12 -> V_181 = 0 ;
F_49 ( & V_7 -> V_57 , V_12 -> V_182 ) ;
V_12 -> V_179 = 0 ;
}
static int
F_76 ( struct V_2 * V_127 , const struct V_203 * V_204 )
{
struct V_19 * V_20 = V_127 -> V_195 -> V_129 -> V_20 ;
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_11 * V_70 ;
T_3 V_205 = F_57 ( V_204 -> V_206 ) ;
T_3 V_207 = F_57 ( V_204 -> V_208 ) ;
T_3 V_209 = F_57 ( V_204 -> V_210 ) ;
T_4 V_211 = ( V_207 >> 8 ) & 0xff ;
T_4 V_212 = V_209 >> 8 ;
int V_213 = - V_214 ;
int V_73 , V_74 ;
V_70 = F_5 ( V_12 ) ;
V_73 = V_70 -> V_73 ;
V_74 = V_70 -> V_74 ;
if ( V_212 == V_215 ) {
struct V_216 V_217 ;
if ( V_211 == V_218 )
V_217 . V_219 = V_73 ;
else if ( V_211 == V_220 )
V_217 . V_219 = V_74 ;
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
struct V_19 * V_20 = V_127 -> V_195 -> V_129 -> V_20 ;
struct V_1 * V_12 = F_1 ( V_127 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_11 * V_70 ;
T_3 V_205 = F_57 ( V_204 -> V_206 ) ;
T_3 V_207 = F_57 ( V_204 -> V_208 ) ;
T_3 V_209 = F_57 ( V_204 -> V_210 ) ;
T_4 V_211 = ( V_207 >> 8 ) & 0xff ;
T_4 V_212 = V_209 >> 8 ;
struct V_222 V_223 ;
int V_213 = - V_214 ;
int V_73 , V_74 ;
V_70 = F_5 ( V_12 ) ;
V_73 = V_70 -> V_73 ;
V_74 = V_70 -> V_74 ;
if ( V_212 == V_215 ) {
if ( V_211 == V_218 )
V_223 . V_224 = V_73 ;
else if ( V_211 == V_220 )
V_223 . V_224 = V_74 ;
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
T_4 V_193 = V_207 & 0xff ;
if ( V_193 != V_12 -> V_176 ) {
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
struct V_128 * V_129 = V_127 -> V_195 -> V_129 ;
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
struct V_11 * V_70 = F_82 ( V_239 ) ;
F_85 ( & V_70 -> V_14 ) ;
}
static void F_86 ( struct V_241 * V_3 )
{
struct V_11 * V_70 ;
V_70 = F_2 ( V_3 , struct V_11 , V_14 ) ;
F_69 ( V_70 ) ;
}
static struct V_241 * F_87 ( void )
{
struct V_11 * V_70 ;
V_70 = F_67 ( sizeof( * V_70 ) , V_105 ) ;
if ( ! V_70 )
return F_88 ( - V_200 ) ;
F_89 ( & V_70 -> V_40 ) ;
V_70 -> V_14 . V_242 = F_86 ;
F_90 ( & V_70 -> V_14 . V_240 , L_11 ,
& V_243 ) ;
V_70 -> V_75 = V_244 ;
V_70 -> V_73 = V_245 ;
V_70 -> V_71 = V_246 ;
V_70 -> V_76 = V_247 ;
V_70 -> V_74 = V_248 ;
V_70 -> V_72 = V_249 ;
return & V_70 -> V_14 ;
}
static void F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_12 ;
struct V_11 * V_70 ;
V_12 = F_1 ( V_3 ) ;
V_70 = F_2 ( V_3 -> V_13 , struct V_11 , V_14 ) ;
F_69 ( V_12 ) ;
F_92 ( & V_70 -> V_40 ) ;
-- V_70 -> V_250 ;
F_93 ( & V_70 -> V_40 ) ;
}
static void F_94 ( struct V_125 * V_217 , struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_31 * V_32 ;
F_47 ( V_12 ) ;
V_32 = & V_12 -> V_7 . V_56 ;
F_69 ( V_32 -> V_63 ) ;
V_32 = & V_12 -> V_7 . V_57 ;
F_69 ( V_32 -> V_63 ) ;
F_68 ( V_3 ) ;
if ( V_12 -> V_185 )
V_12 -> V_185 -> V_184 = NULL ;
if ( V_12 -> V_182 )
V_12 -> V_182 -> V_184 = NULL ;
}
static struct V_2 * F_95 ( struct V_241 * V_13 )
{
struct V_1 * V_12 ;
struct V_11 * V_70 ;
V_12 = F_67 ( sizeof( * V_12 ) , V_105 ) ;
if ( V_12 == NULL )
return F_88 ( - V_200 ) ;
V_70 = F_2 ( V_13 , struct V_11 , V_14 ) ;
F_92 ( & V_70 -> V_40 ) ;
++ V_70 -> V_250 ;
F_93 ( & V_70 -> V_40 ) ;
V_12 -> V_4 . V_96 = L_12 ;
V_12 -> V_4 . V_251 = F_58 ;
V_12 -> V_4 . V_252 = F_94 ;
V_12 -> V_4 . V_253 = F_70 ;
V_12 -> V_4 . V_254 = F_74 ;
V_12 -> V_4 . V_255 = F_75 ;
V_12 -> V_4 . V_256 = F_81 ;
V_12 -> V_4 . V_257 = F_91 ;
return & V_12 -> V_4 ;
}
