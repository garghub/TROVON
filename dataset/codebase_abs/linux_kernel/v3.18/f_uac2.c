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
static int
F_53 ( struct V_114 * V_115 , struct V_2 * V_116 )
{
struct V_1 * V_12 = F_1 ( V_116 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_117 * V_118 = V_115 -> V_118 ;
struct V_119 * V_120 = V_118 -> V_120 ;
struct V_107 * V_53 = & V_7 -> V_10 . V_53 ;
struct V_31 * V_32 ;
struct V_11 * V_121 ;
struct V_122 * V_123 ;
int V_124 ;
V_121 = F_2 ( V_116 -> V_13 , struct V_11 , V_14 ) ;
V_123 = F_54 ( V_118 , V_125 , F_55 ( V_126 ) ) ;
if ( F_56 ( V_123 ) )
return F_57 ( V_123 ) ;
V_127 . V_128 = V_123 [ V_129 ] . V_103 ;
V_130 . V_131 = V_123 [ V_132 ] . V_103 ;
V_133 . V_134 = V_123 [ V_135 ] . V_103 ;
V_136 . V_134 = V_123 [ V_137 ] . V_103 ;
V_138 . V_139 = V_123 [ V_140 ] . V_103 ;
V_141 . V_139 = V_123 [ V_142 ] . V_103 ;
V_143 . V_139 = V_123 [ V_144 ] . V_103 ;
V_145 . V_139 = V_123 [ V_146 ] . V_103 ;
V_147 . V_131 = V_123 [ V_148 ] . V_103 ;
V_149 . V_131 = V_123 [ V_150 ] . V_103 ;
V_151 . V_131 = V_123 [ V_152 ] . V_103 ;
V_153 . V_131 = V_123 [ V_154 ] . V_103 ;
V_138 . V_155 = F_6 ( V_121 -> V_76 ) ;
V_138 . V_156 = F_58 ( V_121 -> V_76 ) ;
V_141 . V_155 = F_6 ( V_121 -> V_75 ) ;
V_141 . V_156 = F_58 ( V_121 -> V_75 ) ;
V_157 . V_155 = F_6 ( V_121 -> V_76 ) ;
V_157 . V_156 = F_58 ( V_121 -> V_76 ) ;
V_158 . V_155 = F_6 ( V_121 -> V_75 ) ;
V_158 . V_156 = F_58 ( V_121 -> V_75 ) ;
V_159 . V_160 = V_121 -> V_72 ;
V_159 . V_161 = V_121 -> V_72 * 8 ;
V_162 . V_160 = V_121 -> V_71 ;
V_162 . V_161 = V_121 -> V_71 * 8 ;
snprintf ( V_163 , sizeof( V_163 ) , L_8 , V_121 -> V_73 ) ;
snprintf ( V_164 , sizeof( V_164 ) , L_8 , V_121 -> V_74 ) ;
V_124 = F_59 ( V_115 , V_116 ) ;
if ( V_124 < 0 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return V_124 ;
}
V_130 . V_165 = V_124 ;
V_12 -> V_166 = V_124 ;
V_12 -> V_167 = 0 ;
V_124 = F_59 ( V_115 , V_116 ) ;
if ( V_124 < 0 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return V_124 ;
}
V_147 . V_165 = V_124 ;
V_149 . V_165 = V_124 ;
V_12 -> V_168 = V_124 ;
V_12 -> V_169 = 0 ;
V_124 = F_59 ( V_115 , V_116 ) ;
if ( V_124 < 0 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return V_124 ;
}
V_151 . V_165 = V_124 ;
V_153 . V_165 = V_124 ;
V_12 -> V_170 = V_124 ;
V_12 -> V_171 = 0 ;
V_12 -> V_172 = F_60 ( V_120 , & V_173 ) ;
if ( ! V_12 -> V_172 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
goto V_55;
}
V_12 -> V_172 -> V_174 = V_12 ;
V_12 -> V_175 = F_60 ( V_120 , & V_176 ) ;
if ( ! V_12 -> V_175 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
goto V_55;
}
V_12 -> V_175 -> V_174 = V_12 ;
V_7 -> V_56 . V_7 = V_7 ;
V_7 -> V_57 . V_7 = V_7 ;
V_177 . V_178 = V_173 . V_178 ;
V_177 . V_179 = V_173 . V_179 ;
V_180 . V_178 = V_176 . V_178 ;
V_180 . V_179 = V_176 . V_179 ;
V_124 = F_61 ( V_116 , V_181 , V_182 , NULL ) ;
if ( V_124 )
goto V_55;
V_32 = & V_12 -> V_7 . V_57 ;
V_32 -> V_64 = V_177 . V_179 ;
V_32 -> V_63 = F_62 ( V_32 -> V_64 * V_65 , V_105 ) ;
if ( ! V_32 -> V_63 ) {
V_32 -> V_64 = 0 ;
goto V_183;
}
V_32 = & V_12 -> V_7 . V_56 ;
V_32 -> V_64 = V_180 . V_179 ;
V_32 -> V_63 = F_62 ( V_32 -> V_64 * V_65 , V_105 ) ;
if ( ! V_32 -> V_63 ) {
V_32 -> V_64 = 0 ;
goto V_183;
}
V_124 = F_43 ( V_12 ) ;
if ( V_124 )
goto V_183;
return 0 ;
V_183:
F_63 ( V_116 ) ;
V_55:
F_64 ( V_12 -> V_7 . V_56 . V_63 ) ;
F_64 ( V_12 -> V_7 . V_57 . V_63 ) ;
if ( V_12 -> V_175 )
V_12 -> V_175 -> V_174 = NULL ;
if ( V_12 -> V_172 )
V_12 -> V_172 -> V_174 = NULL ;
return - V_62 ;
}
static int
F_65 ( struct V_2 * V_116 , unsigned V_184 , unsigned V_185 )
{
struct V_117 * V_118 = V_116 -> V_186 -> V_118 ;
struct V_1 * V_12 = F_1 ( V_116 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_119 * V_120 = V_118 -> V_120 ;
struct V_107 * V_53 = & V_7 -> V_10 . V_53 ;
struct V_19 * V_20 ;
struct V_17 * V_18 ;
struct V_31 * V_32 ;
int V_187 , V_112 ;
if ( V_185 > 1 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return - V_62 ;
}
if ( V_184 == V_12 -> V_166 ) {
if ( V_185 ) {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return - V_62 ;
}
return 0 ;
}
if ( V_184 == V_12 -> V_168 ) {
V_18 = V_12 -> V_172 ;
V_32 = & V_7 -> V_57 ;
F_66 ( V_120 , V_116 , V_18 ) ;
V_12 -> V_169 = V_185 ;
V_187 = V_32 -> V_64 ;
} else if ( V_184 == V_12 -> V_170 ) {
struct V_11 * V_70 = F_5 ( V_12 ) ;
unsigned int V_188 , V_189 ;
struct V_190 * V_191 ;
V_18 = V_12 -> V_175 ;
V_32 = & V_7 -> V_56 ;
F_66 ( V_120 , V_116 , V_18 ) ;
V_12 -> V_171 = V_185 ;
if ( V_120 -> V_192 == V_193 ) {
V_191 = & V_176 ;
V_188 = 1000 ;
} else {
V_191 = & V_180 ;
V_188 = 125 ;
}
V_7 -> V_47 = V_70 -> V_71 *
F_6 ( V_70 -> V_75 ) ;
V_189 = V_70 -> V_73 * V_7 -> V_47 ;
V_7 -> V_46 = ( 1 << ( V_191 -> V_194 - 1 ) ) * V_188 ;
V_7 -> V_43 = F_67 (unsigned int, rate / uac2->p_interval,
prm->max_psize) ;
if ( V_7 -> V_43 < V_32 -> V_64 )
V_7 -> V_45 = V_189 % V_7 -> V_46 ;
else
V_7 -> V_45 = 0 ;
V_187 = V_7 -> V_43 ;
V_7 -> V_44 = 0 ;
} else {
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
return - V_62 ;
}
if ( V_185 == 0 ) {
F_49 ( V_32 , V_18 ) ;
return 0 ;
}
V_32 -> V_34 = true ;
F_68 ( V_18 ) ;
for ( V_112 = 0 ; V_112 < V_65 ; V_112 ++ ) {
if ( ! V_32 -> V_113 [ V_112 ] . V_20 ) {
V_20 = F_69 ( V_18 , V_52 ) ;
if ( V_20 == NULL )
return - V_195 ;
V_32 -> V_113 [ V_112 ] . V_20 = V_20 ;
V_32 -> V_113 [ V_112 ] . V_33 = V_32 ;
V_20 -> V_196 = 0 ;
V_20 -> V_28 = & V_32 -> V_113 [ V_112 ] ;
V_20 -> V_38 = V_187 ;
V_20 -> V_197 = F_7 ;
V_20 -> V_50 = V_32 -> V_63 + V_112 * V_32 -> V_64 ;
}
if ( F_12 ( V_18 , V_32 -> V_113 [ V_112 ] . V_20 , V_52 ) )
F_13 ( V_53 , L_7 , V_36 , __LINE__ ) ;
}
return 0 ;
}
static int
F_70 ( struct V_2 * V_116 , unsigned V_184 )
{
struct V_1 * V_12 = F_1 ( V_116 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
if ( V_184 == V_12 -> V_166 )
return V_12 -> V_167 ;
else if ( V_184 == V_12 -> V_168 )
return V_12 -> V_169 ;
else if ( V_184 == V_12 -> V_170 )
return V_12 -> V_171 ;
else
F_13 ( & V_7 -> V_10 . V_53 ,
L_9 ,
V_36 , __LINE__ , V_184 ) ;
return - V_62 ;
}
static void
F_71 ( struct V_2 * V_116 )
{
struct V_1 * V_12 = F_1 ( V_116 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
F_49 ( & V_7 -> V_56 , V_12 -> V_175 ) ;
V_12 -> V_171 = 0 ;
F_49 ( & V_7 -> V_57 , V_12 -> V_172 ) ;
V_12 -> V_169 = 0 ;
}
static int
F_72 ( struct V_2 * V_116 , const struct V_198 * V_199 )
{
struct V_19 * V_20 = V_116 -> V_186 -> V_118 -> V_20 ;
struct V_1 * V_12 = F_1 ( V_116 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_11 * V_70 ;
T_3 V_200 = F_73 ( V_199 -> V_201 ) ;
T_3 V_202 = F_73 ( V_199 -> V_203 ) ;
T_3 V_204 = F_73 ( V_199 -> V_205 ) ;
T_4 V_206 = ( V_202 >> 8 ) & 0xff ;
T_4 V_207 = V_204 >> 8 ;
int V_208 = - V_209 ;
int V_73 , V_74 ;
V_70 = F_5 ( V_12 ) ;
V_73 = V_70 -> V_73 ;
V_74 = V_70 -> V_74 ;
if ( V_207 == V_210 ) {
struct V_211 V_212 ;
if ( V_206 == V_213 )
V_212 . V_214 = V_73 ;
else if ( V_206 == V_215 )
V_212 . V_214 = V_74 ;
V_208 = F_67 ( unsigned , V_200 , sizeof V_212 ) ;
memcpy ( V_20 -> V_50 , & V_212 , V_208 ) ;
} else if ( V_207 == V_216 ) {
* ( T_4 * ) V_20 -> V_50 = 1 ;
V_208 = F_67 ( unsigned , V_200 , 1 ) ;
} else {
F_13 ( & V_7 -> V_10 . V_53 ,
L_10 ,
V_36 , __LINE__ , V_207 ) ;
}
return V_208 ;
}
static int
F_74 ( struct V_2 * V_116 , const struct V_198 * V_199 )
{
struct V_19 * V_20 = V_116 -> V_186 -> V_118 -> V_20 ;
struct V_1 * V_12 = F_1 ( V_116 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_11 * V_70 ;
T_3 V_200 = F_73 ( V_199 -> V_201 ) ;
T_3 V_202 = F_73 ( V_199 -> V_203 ) ;
T_3 V_204 = F_73 ( V_199 -> V_205 ) ;
T_4 V_206 = ( V_202 >> 8 ) & 0xff ;
T_4 V_207 = V_204 >> 8 ;
struct V_217 V_218 ;
int V_208 = - V_209 ;
int V_73 , V_74 ;
V_70 = F_5 ( V_12 ) ;
V_73 = V_70 -> V_73 ;
V_74 = V_70 -> V_74 ;
if ( V_207 == V_210 ) {
if ( V_206 == V_213 )
V_218 . V_219 = V_73 ;
else if ( V_206 == V_215 )
V_218 . V_219 = V_74 ;
else
return - V_209 ;
V_218 . V_220 = V_218 . V_219 ;
V_218 . V_221 = 0 ;
V_218 . V_222 = 1 ;
V_208 = F_67 ( unsigned , V_200 , sizeof V_218 ) ;
memcpy ( V_20 -> V_50 , & V_218 , V_208 ) ;
} else {
F_13 ( & V_7 -> V_10 . V_53 ,
L_10 ,
V_36 , __LINE__ , V_207 ) ;
}
return V_208 ;
}
static int
F_75 ( struct V_2 * V_116 , const struct V_198 * V_199 )
{
if ( V_199 -> V_223 == V_224 )
return F_72 ( V_116 , V_199 ) ;
else if ( V_199 -> V_223 == V_225 )
return F_74 ( V_116 , V_199 ) ;
else
return - V_209 ;
}
static int
F_76 ( struct V_2 * V_116 , const struct V_198 * V_199 )
{
T_3 V_200 = F_73 ( V_199 -> V_201 ) ;
T_3 V_204 = F_73 ( V_199 -> V_205 ) ;
T_4 V_207 = V_204 >> 8 ;
if ( V_207 == V_210 )
return V_200 ;
return - V_209 ;
}
static int
F_77 ( struct V_2 * V_116 , const struct V_198 * V_199 )
{
struct V_1 * V_12 = F_1 ( V_116 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
T_3 V_202 = F_73 ( V_199 -> V_203 ) ;
T_4 V_184 = V_202 & 0xff ;
if ( V_184 != V_12 -> V_166 ) {
F_13 ( & V_7 -> V_10 . V_53 ,
L_7 , V_36 , __LINE__ ) ;
return - V_209 ;
}
if ( V_199 -> V_226 & V_227 )
return F_75 ( V_116 , V_199 ) ;
else if ( V_199 -> V_223 == V_224 )
return F_76 ( V_116 , V_199 ) ;
return - V_209 ;
}
static int
F_78 ( struct V_2 * V_116 , const struct V_198 * V_199 )
{
struct V_117 * V_118 = V_116 -> V_186 -> V_118 ;
struct V_1 * V_12 = F_1 ( V_116 ) ;
struct V_5 * V_7 = & V_12 -> V_7 ;
struct V_19 * V_20 = V_118 -> V_20 ;
T_3 V_200 = F_73 ( V_199 -> V_201 ) ;
int V_208 = - V_209 ;
if ( ( V_199 -> V_226 & V_228 ) != V_229 )
return - V_209 ;
if ( ( V_199 -> V_226 & V_230 ) == V_231 )
V_208 = F_77 ( V_116 , V_199 ) ;
else
F_13 ( & V_7 -> V_10 . V_53 , L_7 , V_36 , __LINE__ ) ;
if ( V_208 >= 0 ) {
V_20 -> V_38 = V_208 ;
V_20 -> V_196 = V_208 < V_200 ;
V_208 = F_12 ( V_118 -> V_120 -> V_232 , V_20 , V_52 ) ;
if ( V_208 < 0 ) {
F_13 ( & V_7 -> V_10 . V_53 ,
L_7 , V_36 , __LINE__ ) ;
V_20 -> V_25 = 0 ;
}
}
return V_208 ;
}
static inline struct V_11 * F_79 ( struct V_233 * V_234 )
{
return F_2 ( F_80 ( V_234 ) , struct V_11 ,
V_14 . V_235 ) ;
}
static void F_81 ( struct V_233 * V_234 )
{
struct V_11 * V_70 = F_79 ( V_234 ) ;
F_82 ( & V_70 -> V_14 ) ;
}
static void F_83 ( struct V_236 * V_3 )
{
struct V_11 * V_70 ;
V_70 = F_2 ( V_3 , struct V_11 , V_14 ) ;
F_64 ( V_70 ) ;
}
static struct V_236 * F_84 ( void )
{
struct V_11 * V_70 ;
V_70 = F_62 ( sizeof( * V_70 ) , V_105 ) ;
if ( ! V_70 )
return F_85 ( - V_195 ) ;
F_86 ( & V_70 -> V_40 ) ;
V_70 -> V_14 . V_237 = F_83 ;
F_87 ( & V_70 -> V_14 . V_235 , L_11 ,
& V_238 ) ;
V_70 -> V_75 = V_239 ;
V_70 -> V_73 = V_240 ;
V_70 -> V_71 = V_241 ;
V_70 -> V_76 = V_242 ;
V_70 -> V_74 = V_243 ;
V_70 -> V_72 = V_244 ;
return & V_70 -> V_14 ;
}
static void F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_12 ;
struct V_11 * V_70 ;
V_12 = F_1 ( V_3 ) ;
V_70 = F_2 ( V_3 -> V_13 , struct V_11 , V_14 ) ;
F_64 ( V_12 ) ;
F_89 ( & V_70 -> V_40 ) ;
-- V_70 -> V_245 ;
F_90 ( & V_70 -> V_40 ) ;
}
static void F_91 ( struct V_114 * V_212 , struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_31 * V_32 ;
F_47 ( V_12 ) ;
V_32 = & V_12 -> V_7 . V_56 ;
F_64 ( V_32 -> V_63 ) ;
V_32 = & V_12 -> V_7 . V_57 ;
F_64 ( V_32 -> V_63 ) ;
F_63 ( V_3 ) ;
if ( V_12 -> V_175 )
V_12 -> V_175 -> V_174 = NULL ;
if ( V_12 -> V_172 )
V_12 -> V_172 -> V_174 = NULL ;
}
struct V_2 * F_92 ( struct V_236 * V_13 )
{
struct V_1 * V_12 ;
struct V_11 * V_70 ;
V_12 = F_62 ( sizeof( * V_12 ) , V_105 ) ;
if ( V_12 == NULL )
return F_85 ( - V_195 ) ;
V_70 = F_2 ( V_13 , struct V_11 , V_14 ) ;
F_89 ( & V_70 -> V_40 ) ;
++ V_70 -> V_245 ;
F_90 ( & V_70 -> V_40 ) ;
V_12 -> V_4 . V_96 = L_12 ;
V_12 -> V_4 . V_246 = F_53 ;
V_12 -> V_4 . V_247 = F_91 ;
V_12 -> V_4 . V_248 = F_65 ;
V_12 -> V_4 . V_249 = F_70 ;
V_12 -> V_4 . V_250 = F_71 ;
V_12 -> V_4 . V_251 = F_78 ;
V_12 -> V_4 . V_252 = F_88 ;
return & V_12 -> V_4 ;
}
