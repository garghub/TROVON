static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_6 -> V_9 || V_6 -> V_10 )
return - V_11 ;
* V_4 = V_8 -> V_4 ;
return 0 ;
}
static void F_3 ( int V_12 , T_1 * V_13 ,
T_1 * V_14 )
{
if ( V_12 <= 1000 ) {
* V_14 = V_15 ;
* V_13 = V_16 ;
} else if ( V_12 <= 10000 ) {
* V_14 = V_15 ;
* V_13 = V_17 ;
} else if ( V_12 <= 20000 ) {
* V_14 = V_18 ;
* V_13 = V_19 ;
} else if ( V_12 <= 30000 ) {
* V_14 = V_18 ;
* V_13 = V_20 ;
} else if ( V_12 <= 40000 ) {
* V_14 = V_18 ;
* V_13 = V_17 ;
} else {
* V_14 = V_18 ;
* V_13 = V_21 ;
}
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_22 , struct V_23 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_24 * V_25 ;
T_2 V_12 ;
if ( F_5 ( V_22 != 1 ) ) {
F_6 ( L_1 , V_22 ) ;
goto V_26;
}
V_25 = & V_8 -> V_25 ;
* V_4 = V_25 -> V_4 ;
F_7 ( & V_8 -> V_27 ) ;
if ( V_8 -> V_28 -> V_29 -> V_30 ) {
struct V_31 V_32 ;
V_8 -> V_28 -> V_29 -> V_30 ( V_8 -> V_28 , & V_32 ) ;
V_12 = V_32 . V_33 . V_12 ;
} else if ( V_8 -> V_28 -> V_29 -> V_34 ) {
struct V_35 V_36 ;
V_8 -> V_28 -> V_29 -> V_34 ( V_8 -> V_28 , & V_36 ) ;
V_12 = V_36 . V_12 ;
} else {
F_6 ( L_2 ,
V_8 -> V_28 -> V_37 ) ;
V_12 = 1000 ;
}
F_3 ( V_12 , & V_4 -> V_13 ,
& V_4 -> V_14 ) ;
F_8 ( & V_8 -> V_27 ) ;
return 0 ;
V_26:
return - V_11 ;
}
static int F_9 ( struct V_1 * V_38 ,
T_1 V_22 , int V_39 , union V_40 * V_41 )
{
int V_42 ;
if ( V_39 > V_43 )
return - V_11 ;
V_42 = F_10 ( V_38 , V_22 , V_39 , V_41 , NULL ) ;
if ( V_42 == - V_44 ) {
memcpy ( V_41 , & V_45 , sizeof( * V_41 ) ) ;
return 0 ;
}
return V_42 ;
}
static int F_11 ( struct V_1 * V_38 , T_1 V_22 , unsigned int
V_39 , const union V_40 * V_41 ,
const struct V_46 * V_4 , void * * V_47 )
{
if ( V_39 >= V_43 )
return - V_11 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_38 , T_1 V_22 , unsigned int
V_39 , void * * V_47 )
{
if ( V_39 >= V_43 )
return - V_11 ;
return 0 ;
}
static struct V_48 * F_13 ( struct V_1 * V_38 ,
T_1 V_22 )
{
struct V_7 * V_8 = F_2 ( V_38 ) ;
if ( V_8 -> V_28 ) {
F_14 ( V_8 -> V_28 ) ;
return V_8 -> V_28 ;
}
return NULL ;
}
static int F_15 ( struct V_1 * V_38 ,
T_1 V_22 , T_3 V_39 , T_3 * V_49 )
{
struct V_7 * V_8 = F_2 ( V_38 ) ;
struct V_24 * V_25 ;
if ( F_5 ( V_22 != 1 ) ) {
F_16 ( V_38 -> V_2 . V_50 , L_3 ,
V_22 ) ;
goto V_26;
}
V_25 = & V_8 -> V_25 ;
if ( F_5 ( V_39 >= V_25 -> V_4 . V_51 ) ) {
F_16 ( V_38 -> V_2 . V_50 , L_4 ,
V_39 ) ;
goto V_26;
}
* V_49 = V_25 -> V_52 [ V_39 ] ;
return 0 ;
V_26:
return - V_11 ;
}
static int F_17 ( struct V_1 * V_2 ,
int V_53 , struct V_54 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_53 & V_55 )
V_8 -> V_4 . V_56 = F_18 ( V_4 -> V_56 ) ;
if ( V_53 & V_57 ) {
memcpy ( V_8 -> V_58 . V_59 ,
V_4 -> V_59 , sizeof( V_8 -> V_58 . V_59 ) ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_1 V_22 , int V_53 , struct V_60 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_24 * V_25 ;
if ( F_5 ( V_22 != 1 ) ) {
F_6 ( L_3 , V_22 ) ;
goto V_26;
}
V_25 = & V_8 -> V_25 ;
V_25 -> V_4 . V_61 |= V_4 -> V_62 ;
V_25 -> V_4 . V_61 &= ~ V_4 -> V_63 ;
if ( V_53 & V_64 )
V_25 -> V_4 . V_65 = 0 ;
return 0 ;
V_26:
return - V_11 ;
}
static enum V_66 F_20 ( struct V_1 * V_2 ,
T_1 V_22 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_21 ( V_8 , V_22 ) ;
}
static struct V_67 * F_22 ( struct V_1 * V_2 ,
struct V_5 * V_68 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_69 * V_70 ;
V_70 = F_23 ( & V_8 -> V_71 ) ;
return V_70 ? & V_70 -> V_72 : F_24 ( - V_73 ) ;
}
static int F_25 ( struct V_67 * V_72 )
{
struct V_69 * V_70 = F_26 ( V_72 ) ;
F_27 ( V_70 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_22 ,
struct V_74 * V_75 )
{
int V_76 ;
struct V_23 V_4 ;
V_75 -> V_77 = V_78 ;
V_76 = F_29 ( V_2 , V_22 , & V_4 ) ;
if ( V_76 )
return V_76 ;
V_75 -> V_51 = V_4 . V_51 ;
V_75 -> V_79 = V_4 . V_79 ;
V_75 -> V_80 = V_81 ;
return 0 ;
}
static struct V_82 * F_30 ( struct V_1 * V_2 ,
struct V_67 * V_47 ,
struct V_5 * V_68 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_83 * V_84 ;
V_84 = F_23 ( & V_8 -> V_85 ) ;
return V_84 ? & V_84 -> V_86 : F_24 ( - V_73 ) ;
}
static int F_31 ( struct V_82 * V_86 )
{
struct V_83 * V_84 = F_32 ( V_86 ) ;
F_27 ( V_84 ) ;
return 0 ;
}
static int F_33 ( struct V_7 * V_8 , struct V_87 * V_4 ,
struct V_88 * V_89 )
{
int V_76 ;
union V_40 V_90 ;
struct V_46 V_91 ;
V_76 = F_10 ( & V_8 -> V_58 , V_4 -> V_22 ,
V_4 -> V_92 . V_93 , & V_90 ,
& V_91 ) ;
if ( V_76 ) {
F_34 ( L_5 , V_76 ) ;
return V_76 ;
}
V_76 = F_35 ( V_8 , V_4 -> V_22 , V_89 , V_4 ) ;
if ( ! V_76 )
V_76 = F_36 ( V_8 , V_89 , V_4 , & V_91 , & V_90 ) ;
if ( V_91 . V_28 )
F_37 ( V_91 . V_28 ) ;
return V_76 ;
}
static struct V_94 * F_38 ( struct V_82 * V_86 , struct V_87 * V_4 ,
struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_95 * V_96 ;
V_76 = F_39 ( V_8 , V_4 ) ;
if ( V_76 )
goto V_26;
V_96 = F_23 ( & V_8 -> V_97 ) ;
if ( ! V_96 ) {
V_76 = - V_73 ;
goto V_26;
}
F_40 ( V_84 ) ;
V_96 -> V_84 = V_84 ;
V_76 = F_33 ( V_8 , V_4 , & V_96 -> V_89 ) ;
if ( V_76 )
goto V_98;
return & V_96 -> V_99 ;
V_98:
F_27 ( V_84 ) ;
F_27 ( V_96 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static int F_41 ( struct V_94 * V_99 , struct V_87 * V_4 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_99 -> V_38 ) ;
struct V_95 * V_96 = F_42 ( V_99 ) ;
V_76 = F_39 ( V_8 , V_4 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_33 ( V_8 , V_4 , & V_96 -> V_89 ) ;
if ( V_76 )
return V_76 ;
return 0 ;
}
static int F_43 ( struct V_94 * V_99 , struct V_87 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_99 -> V_38 ) ;
struct V_95 * V_96 = F_42 ( V_99 ) ;
F_44 ( V_8 , & V_96 -> V_89 , V_4 ) ;
return 0 ;
}
static int F_45 ( struct V_94 * V_99 )
{
struct V_95 * V_96 = F_42 ( V_99 ) ;
F_27 ( V_96 -> V_84 ) ;
F_27 ( V_96 ) ;
return 0 ;
}
static int F_46 ( struct V_100 * V_101 , struct V_102 * V_103 )
{
int V_76 ;
int V_104 ;
T_2 V_105 ;
struct V_106 * V_107 ;
int V_108 = V_103 -> V_108 ;
if ( F_5 ( F_47 ( V_101 -> V_109 ) ) ) {
V_76 = - V_73 ;
goto V_26;
}
if ( F_5 ( V_108 > V_101 -> V_110 ) ) {
V_76 = - V_11 ;
goto V_26;
}
V_105 = 0 ;
for ( V_104 = 0 ; V_104 < V_108 ; V_104 ++ )
V_105 += V_103 -> V_111 [ V_104 ] . V_105 ;
V_107 = F_48 ( V_101 -> V_109 ) ;
V_107 -> V_112 = V_103 -> V_112 ;
V_107 -> V_108 = V_108 ;
memcpy ( V_107 -> V_113 . V_114 , V_103 -> V_111 ,
V_108 * sizeof( struct V_115 ) ) ;
V_107 -> V_113 . V_105 = V_105 ;
V_107 -> V_113 . V_116 = V_105 ;
V_107 -> V_113 . V_108 = V_108 ;
V_107 -> V_113 . V_117 = 0 ;
V_107 -> V_113 . V_118 = 0 ;
F_49 () ;
F_50 ( V_101 -> V_109 ) ;
return 0 ;
V_26:
return V_76 ;
}
static struct V_119 * F_51 ( struct V_82 * V_86 ,
struct V_120 * V_121 ,
struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_122 * V_123 ;
struct V_67 * V_47 = V_68 ? V_86 -> V_124 -> V_47 : NULL ;
V_76 = F_52 ( V_8 , NULL , & V_121 -> V_4 , V_125 ) ;
if ( V_76 )
goto V_26;
V_123 = F_23 ( & V_8 -> V_126 ) ;
if ( ! V_123 ) {
V_76 = - V_73 ;
goto V_26;
}
F_53 ( V_123 ) ;
F_40 ( V_84 ) ;
V_123 -> V_84 = V_84 ;
V_76 = F_54 ( V_8 , V_123 , V_121 , V_47 , V_68 ) ;
if ( V_76 )
goto V_98;
return & V_123 -> V_127 ;
V_98:
F_27 ( V_84 ) ;
F_55 ( V_123 ) ;
F_27 ( V_123 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static int F_56 ( struct V_119 * V_127 , struct V_128 * V_4 ,
enum V_129 V_53 ,
struct V_5 * V_68 )
{
int V_76 ;
struct V_122 * V_123 = F_57 ( V_127 ) ;
struct V_7 * V_8 = F_2 ( V_127 -> V_38 ) ;
V_76 = F_52 ( V_8 , V_123 , V_4 , V_53 ) ;
if ( V_76 )
goto V_26;
V_76 = F_58 ( V_8 , V_123 , V_4 , V_53 , V_68 ) ;
if ( V_76 )
goto V_26;
return 0 ;
V_26:
return V_76 ;
}
static int F_59 ( struct V_119 * V_127 , struct V_128 * V_4 )
{
struct V_122 * V_123 = F_57 ( V_127 ) ;
if ( V_123 -> error )
return - V_11 ;
V_4 -> V_130 = V_123 -> V_101 . V_109 -> V_131 -> V_132 ;
V_4 -> V_110 = V_123 -> V_101 . V_110 ;
V_4 -> V_133 = V_123 -> V_134 ;
return 0 ;
}
static int F_60 ( struct V_119 * V_127 )
{
struct V_122 * V_123 = F_57 ( V_127 ) ;
if ( V_123 -> V_101 . V_109 )
F_61 ( V_123 -> V_101 . V_109 ) ;
F_27 ( V_123 -> V_84 ) ;
F_55 ( V_123 ) ;
F_27 ( V_123 ) ;
return 0 ;
}
static int F_62 ( struct V_119 * V_127 , struct V_102 * V_135 ,
struct V_102 * * V_136 )
{
int V_76 = 0 ;
unsigned long V_137 ;
struct V_122 * V_123 = F_57 ( V_127 ) ;
F_63 ( & V_123 -> V_101 . V_138 , V_137 ) ;
while ( V_135 ) {
V_76 = F_46 ( & V_123 -> V_101 , V_135 ) ;
if ( F_5 ( V_76 ) )
break;
V_135 = V_135 -> V_139 ;
}
F_64 ( & V_123 -> V_101 . V_138 , V_137 ) ;
if ( V_76 )
* V_136 = V_135 ;
return V_76 ;
}
static struct V_140 * F_65 ( struct V_82 * V_86 ,
struct V_141 * V_121 ,
struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_142 * V_143 ;
V_76 = F_66 ( V_8 , V_121 ) ;
if ( V_76 )
goto V_26;
V_143 = F_23 ( & V_8 -> V_144 ) ;
if ( ! V_143 ) {
V_76 = - V_73 ;
goto V_26;
}
if ( V_68 ) {
if ( V_68 -> V_9 ) {
V_76 = - V_11 ;
goto V_98;
}
V_143 -> V_145 = 1 ;
}
F_53 ( V_143 ) ;
V_76 = F_67 ( V_8 , V_143 , V_84 , V_121 , V_68 , V_86 ) ;
if ( V_76 )
goto V_146;
return & V_143 -> V_147 ;
V_146:
F_55 ( V_143 ) ;
V_98:
F_27 ( V_143 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static int F_68 ( struct V_140 * V_147 , struct V_148 * V_4 ,
int V_53 , struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_147 -> V_38 ) ;
struct V_142 * V_143 = F_69 ( V_147 ) ;
V_76 = F_70 ( V_8 , V_143 , V_4 , V_53 ) ;
if ( V_76 )
goto V_26;
V_76 = F_71 ( V_143 , V_4 , V_53 , V_68 ) ;
if ( V_76 )
goto V_26;
return 0 ;
V_26:
return V_76 ;
}
static int F_72 ( struct V_140 * V_147 , struct V_148 * V_4 ,
int V_53 , struct V_141 * V_121 )
{
struct V_142 * V_143 = F_69 ( V_147 ) ;
F_73 ( V_143 , V_121 ) ;
F_74 ( V_143 , V_4 , V_53 ) ;
return 0 ;
}
static int F_75 ( struct V_140 * V_147 )
{
struct V_142 * V_143 = F_69 ( V_147 ) ;
F_76 ( V_143 ) ;
F_55 ( V_143 ) ;
F_27 ( V_143 ) ;
return 0 ;
}
static int F_77 ( struct V_142 * V_143 , struct V_149 * V_103 ,
unsigned int V_53 , unsigned int V_105 )
{
int V_108 = V_103 -> V_108 ;
struct V_150 * V_151 = & V_143 -> V_151 ;
if ( F_5 ( V_108 > V_151 -> V_110 ) )
goto V_26;
if ( F_5 ( V_53 & V_152 ) ) {
if ( V_105 < 8 )
goto V_26;
if ( F_78 ( V_103 ) -> V_153 & 0x7 )
goto V_26;
}
if ( F_5 ( ( V_103 -> V_154 & V_155 ) &&
( V_105 > V_151 -> V_156 ) ) )
goto V_26;
return 0 ;
V_26:
return - V_11 ;
}
static void F_79 ( struct V_142 * V_143 , struct V_157 * V_135 ,
struct V_149 * V_103 )
{
V_135 -> V_112 = V_103 -> V_112 ;
V_135 -> V_108 = V_103 -> V_108 ;
V_135 -> V_158 = V_103 -> V_158 ;
V_135 -> V_154 = V_103 -> V_154 ;
if ( F_80 ( V_143 ) == V_159 ||
F_80 ( V_143 ) == V_160 ||
F_80 ( V_143 ) == V_161 ) {
V_135 -> V_135 . V_162 . V_163 = F_81 ( V_103 ) -> V_163 ;
V_135 -> V_135 . V_162 . V_164 = F_81 ( V_103 ) -> V_164 ;
if ( F_80 ( V_143 ) == V_161 )
V_135 -> V_135 . V_162 . V_165 = F_81 ( V_103 ) -> V_165 ;
if ( V_135 -> V_158 == V_166 )
V_135 -> V_167 . V_168 = V_103 -> V_167 . V_168 ;
} else {
switch ( V_135 -> V_158 ) {
case V_169 :
V_135 -> V_167 . V_168 = V_103 -> V_167 . V_168 ;
case V_170 :
case V_171 :
V_135 -> V_135 . V_172 . V_153 = F_82 ( V_103 ) -> V_153 ;
V_135 -> V_135 . V_172 . V_173 = F_82 ( V_103 ) -> V_173 ;
break;
case V_166 :
V_135 -> V_167 . V_168 = V_103 -> V_167 . V_168 ;
break;
case V_174 :
V_135 -> V_167 . V_175 = V_103 -> V_167 . V_175 ;
break;
case V_176 :
case V_177 :
V_135 -> V_135 . V_178 . V_153 =
F_78 ( V_103 ) -> V_153 ;
V_135 -> V_135 . V_178 . V_179 =
F_78 ( V_103 ) -> V_179 ;
V_135 -> V_135 . V_178 . V_180 = F_78 ( V_103 ) -> V_180 ;
V_135 -> V_135 . V_178 . V_173 = F_78 ( V_103 ) -> V_173 ;
break;
case V_181 :
V_135 -> V_167 . V_175 = V_103 -> V_167 . V_175 ;
break;
case V_182 :
V_135 -> V_135 . V_183 . V_184 = F_83 ( V_103 ) -> V_184 ;
V_135 -> V_135 . V_183 . V_185 = F_83 ( V_103 ) -> V_185 ;
V_135 -> V_135 . V_183 . V_186 = F_83 ( V_103 ) -> V_186 ;
break;
default:
break;
}
}
}
static int F_84 ( struct V_142 * V_143 , struct V_149 * V_103 ,
unsigned int V_53 , unsigned int V_105 ,
struct V_187 * V_188 )
{
int V_108 = V_103 -> V_108 ;
struct V_115 * V_114 ;
int V_104 ;
T_1 * V_189 ;
F_79 ( V_143 , & V_188 -> V_135 , V_103 ) ;
if ( F_80 ( V_143 ) == V_159 ||
F_80 ( V_143 ) == V_160 ||
F_80 ( V_143 ) == V_161 )
memcpy ( & V_188 -> V_89 , & F_42 ( F_81 ( V_103 ) -> V_96 ) -> V_89 , sizeof( V_188 -> V_89 ) ) ;
if ( F_5 ( V_103 -> V_154 & V_155 ) ) {
V_189 = V_188 -> V_113 . V_190 ;
V_114 = V_103 -> V_111 ;
for ( V_104 = 0 ; V_104 < V_108 ; V_104 ++ , V_114 ++ ) {
if ( V_143 -> V_145 && F_85 ( V_189 , ( V_191 void * )
( V_192 ) V_114 -> V_193 , V_114 -> V_105 ) )
return - V_194 ;
else if ( ! V_143 -> V_145 )
memcpy ( V_189 , ( void * ) ( V_192 ) V_114 -> V_193 ,
V_114 -> V_105 ) ;
V_189 += V_114 -> V_105 ;
}
} else if ( V_53 & V_195 ) {
V_188 -> V_53 = V_53 ;
V_188 -> V_196 = V_197 ;
return 0 ;
} else
memcpy ( V_188 -> V_113 . V_114 , V_103 -> V_111 ,
V_108 * sizeof( struct V_115 ) ) ;
V_188 -> V_198 = ( V_53 & V_152 ) ?
F_78 ( V_103 ) -> V_153 :
F_82 ( V_103 ) -> V_153 ;
V_188 -> V_53 = V_53 ;
V_188 -> V_113 . V_105 = V_105 ;
V_188 -> V_113 . V_116 = V_105 ;
V_188 -> V_113 . V_108 = V_108 ;
V_188 -> V_113 . V_117 = 0 ;
V_188 -> V_113 . V_118 = 0 ;
V_188 -> V_196 = V_197 ;
V_188 -> V_199 = F_86 ( 1 , & V_143 -> V_199 ) ;
return 0 ;
}
static int F_87 ( struct V_142 * V_143 , struct V_149 * V_103 ,
unsigned int V_53 , T_2 V_105 )
{
int V_76 ;
struct V_150 * V_151 = & V_143 -> V_151 ;
struct V_187 * V_200 ;
unsigned long V_137 ;
V_76 = F_77 ( V_143 , V_103 , V_53 , V_105 ) ;
if ( V_76 )
return V_76 ;
F_63 ( & V_143 -> V_151 . V_201 , V_137 ) ;
if ( F_5 ( F_47 ( V_151 -> V_109 ) ) ) {
V_76 = - V_73 ;
goto V_26;
}
V_200 = F_48 ( V_151 -> V_109 ) ;
V_76 = F_84 ( V_143 , V_103 , V_53 , V_105 , V_200 ) ;
if ( F_5 ( V_76 ) )
goto V_26;
F_49 () ;
F_50 ( V_151 -> V_109 ) ;
F_64 ( & V_143 -> V_151 . V_201 , V_137 ) ;
return 0 ;
V_26:
F_64 ( & V_143 -> V_151 . V_201 , V_137 ) ;
return V_76 ;
}
static int F_88 ( struct V_142 * V_143 , struct V_149 * V_135 ,
struct V_149 * * V_136 )
{
int V_76 = 0 ;
unsigned int V_53 ;
unsigned int V_105 = 0 ;
int V_104 ;
int V_202 ;
while ( V_135 ) {
V_53 = F_89 ( V_135 -> V_158 , V_143 ) ;
if ( F_5 ( ! V_53 ) ) {
V_76 = - V_11 ;
* V_136 = V_135 ;
break;
}
if ( F_5 ( ( V_135 -> V_154 & V_155 ) &&
! ( V_53 & V_203 ) ) ) {
V_76 = - V_11 ;
* V_136 = V_135 ;
break;
}
V_105 = 0 ;
for ( V_104 = 0 ; V_104 < V_135 -> V_108 ; V_104 ++ )
V_105 += V_135 -> V_111 [ V_104 ] . V_105 ;
V_76 = F_87 ( V_143 , V_135 , V_53 , V_105 ) ;
if ( V_76 ) {
* V_136 = V_135 ;
break;
}
V_135 = V_135 -> V_139 ;
}
V_202 = ( F_80 ( V_143 ) == V_161 ) ||
( F_90 ( V_143 -> V_151 . V_109 ) > 1 ) ;
F_91 ( & V_143 -> V_204 . V_205 , V_202 ) ;
return V_76 ;
}
static int F_92 ( struct V_140 * V_147 , struct V_149 * V_135 ,
struct V_149 * * V_136 )
{
struct V_142 * V_143 = F_69 ( V_147 ) ;
if ( F_5 ( ! V_143 -> V_206 ) ) {
* V_136 = V_135 ;
return - V_11 ;
}
if ( F_5 ( V_143 -> V_204 . V_196 < V_207 ) ) {
* V_136 = V_135 ;
return - V_11 ;
}
if ( V_143 -> V_145 ) {
F_91 ( & V_143 -> V_204 . V_205 , 0 ) ;
return 0 ;
} else
return F_88 ( V_143 , V_135 , V_136 ) ;
}
static int F_93 ( struct V_140 * V_147 , struct V_102 * V_135 ,
struct V_102 * * V_136 )
{
int V_76 = 0 ;
struct V_142 * V_143 = F_69 ( V_147 ) ;
struct V_100 * V_101 = & V_143 -> V_101 ;
unsigned long V_137 ;
if ( F_5 ( ( F_94 ( V_143 ) < V_208 ) || ! V_143 -> V_206 ) ) {
* V_136 = V_135 ;
V_76 = - V_11 ;
goto V_26;
}
if ( F_5 ( V_143 -> V_123 ) ) {
* V_136 = V_135 ;
V_76 = - V_11 ;
goto V_26;
}
F_63 ( & V_101 -> V_138 , V_137 ) ;
while ( V_135 ) {
V_76 = F_46 ( V_101 , V_135 ) ;
if ( F_5 ( V_76 ) ) {
* V_136 = V_135 ;
break;
}
V_135 = V_135 -> V_139 ;
}
F_64 ( & V_101 -> V_138 , V_137 ) ;
V_26:
return V_76 ;
}
static struct V_209 * F_95 ( struct V_1 * V_2 ,
const struct V_210 * V_4 ,
struct V_67 * V_47 ,
struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_211 * V_212 ;
if ( V_4 -> V_137 )
return F_24 ( - V_11 ) ;
V_76 = F_96 ( V_8 , NULL , V_4 -> V_213 , V_4 -> V_214 , V_68 ) ;
if ( V_76 )
goto V_26;
V_212 = F_23 ( & V_8 -> V_215 ) ;
if ( ! V_212 ) {
V_76 = - V_73 ;
goto V_26;
}
V_76 = F_97 ( V_8 , V_212 , V_4 -> V_213 , V_4 -> V_214 ,
V_47 , V_68 ) ;
if ( V_76 )
goto V_98;
return & V_212 -> V_216 ;
V_98:
F_27 ( V_212 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static int F_98 ( struct V_209 * V_216 )
{
struct V_211 * V_212 = F_99 ( V_216 ) ;
F_27 ( V_212 ) ;
return 0 ;
}
static int F_100 ( struct V_209 * V_216 , int V_213 , struct V_5 * V_68 )
{
int V_76 ;
struct V_211 * V_212 = F_99 ( V_216 ) ;
struct V_7 * V_8 = F_2 ( V_216 -> V_38 ) ;
V_76 = F_96 ( V_8 , V_212 , V_213 , 0 , V_68 ) ;
if ( V_76 )
goto V_26;
V_76 = F_101 ( V_212 , V_213 , V_68 ) ;
if ( V_76 )
goto V_26;
return 0 ;
V_26:
return V_76 ;
}
static int F_102 ( struct V_209 * V_216 , int V_217 , struct V_218 * V_219 )
{
int V_104 ;
struct V_211 * V_212 = F_99 ( V_216 ) ;
struct V_220 * V_213 ;
unsigned long V_137 ;
F_63 ( & V_212 -> V_221 , V_137 ) ;
for ( V_104 = 0 ; V_104 < V_217 ; V_104 ++ ) {
V_213 = F_103 ( V_212 -> V_109 ) ;
if ( ! V_213 )
break;
memcpy ( V_219 ++ , & V_213 -> V_222 , sizeof( * V_219 ) ) ;
F_104 ( V_212 -> V_109 ) ;
}
F_64 ( & V_212 -> V_221 , V_137 ) ;
return V_104 ;
}
static int F_105 ( struct V_209 * V_216 , int V_223 )
{
struct V_211 * V_212 = F_99 ( V_216 ) ;
int V_224 = F_90 ( V_212 -> V_109 ) ;
return ( V_224 > V_223 ) ? V_223 : V_224 ;
}
static int F_106 ( struct V_209 * V_216 , enum V_225 V_137 )
{
struct V_211 * V_212 = F_99 ( V_216 ) ;
unsigned long V_226 ;
int V_42 = 0 ;
F_63 ( & V_212 -> V_221 , V_226 ) ;
if ( V_212 -> V_227 != V_228 )
V_212 -> V_227 = V_137 & V_229 ;
if ( ( V_137 & V_230 ) && ! F_107 ( V_212 -> V_109 ) )
V_42 = 1 ;
F_64 ( & V_212 -> V_221 , V_226 ) ;
return V_42 ;
}
static struct V_231 * F_108 ( struct V_82 * V_86 , int V_186 )
{
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_232 * V_184 ;
int V_76 ;
V_184 = F_23 ( & V_8 -> V_233 ) ;
if ( ! V_184 ) {
V_76 = - V_73 ;
goto V_26;
}
F_53 ( V_184 ) ;
F_40 ( V_84 ) ;
V_76 = F_109 ( V_8 , V_84 , V_186 , V_184 ) ;
if ( V_76 )
goto V_98;
return & V_184 -> V_234 ;
V_98:
F_27 ( V_84 ) ;
F_55 ( V_184 ) ;
F_27 ( V_184 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static struct V_231 * F_110 ( struct V_82 * V_86 ,
T_4 V_235 ,
T_4 V_105 ,
T_4 V_198 ,
int V_186 , struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_232 * V_184 ;
V_184 = F_23 ( & V_8 -> V_233 ) ;
if ( ! V_184 ) {
V_76 = - V_73 ;
goto V_98;
}
F_53 ( V_184 ) ;
F_40 ( V_84 ) ;
V_76 = F_111 ( V_8 , V_84 , V_235 , V_105 , V_198 ,
V_186 , V_68 , V_184 ) ;
if ( V_76 )
goto V_146;
return & V_184 -> V_234 ;
V_146:
F_27 ( V_84 ) ;
F_55 ( V_184 ) ;
F_27 ( V_184 ) ;
V_98:
return F_24 ( V_76 ) ;
}
static int F_112 ( struct V_231 * V_234 )
{
struct V_232 * V_184 = F_113 ( V_234 ) ;
V_184 -> V_196 = V_236 ;
F_27 ( V_184 -> V_84 ) ;
F_55 ( V_184 ) ;
F_27 ( V_184 ) ;
return 0 ;
}
static struct V_231 * F_114 ( struct V_82 * V_86 ,
enum V_237 V_238 ,
T_2 V_239 )
{
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_232 * V_184 ;
int V_76 ;
if ( V_238 != V_240 )
return F_24 ( - V_11 ) ;
V_184 = F_23 ( & V_8 -> V_233 ) ;
if ( ! V_184 ) {
V_76 = - V_73 ;
goto V_26;
}
F_53 ( V_184 ) ;
F_40 ( V_84 ) ;
V_76 = F_115 ( V_8 , V_84 , V_239 , V_184 ) ;
if ( V_76 )
goto V_98;
return & V_184 -> V_234 ;
V_98:
F_27 ( V_84 ) ;
F_55 ( V_184 ) ;
F_27 ( V_184 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static int F_116 ( struct V_231 * V_234 , T_4 V_193 )
{
struct V_232 * V_184 = F_113 ( V_234 ) ;
struct V_241 * V_242 ;
struct V_243 * V_131 ;
if ( F_5 ( V_184 -> V_244 == V_184 -> V_245 ) )
return - V_73 ;
V_242 = V_184 -> V_242 [ V_184 -> V_244 / V_246 ] ;
V_131 = & V_242 -> V_131 [ V_184 -> V_244 % V_246 ] ;
V_131 -> V_193 = V_193 ;
V_131 -> V_247 = V_234 -> V_248 ;
V_184 -> V_244 ++ ;
return 0 ;
}
static int F_117 ( struct V_231 * V_234 , struct V_249 * V_250 ,
int V_251 , unsigned int * V_252 )
{
struct V_232 * V_184 = F_113 ( V_234 ) ;
int V_253 ;
V_184 -> V_244 = 0 ;
V_253 = F_118 ( V_234 , V_250 , V_251 , V_252 , F_116 ) ;
V_184 -> V_254 = V_234 -> V_198 ;
V_184 -> V_198 = V_234 -> V_198 ;
V_184 -> V_105 = V_234 -> V_105 ;
V_184 -> V_255 = F_119 ( V_234 -> V_248 ) ;
V_184 -> V_256 = V_234 -> V_248 - 1 ;
V_184 -> V_257 = V_184 -> V_198 & V_184 -> V_256 ;
return V_253 ;
}
static int F_120 ( struct V_140 * V_147 , union V_40 * V_258 , T_3 V_259 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_147 -> V_38 ) ;
struct V_142 * V_143 = F_69 ( V_147 ) ;
struct V_260 * V_261 ;
V_76 = F_121 ( V_8 , V_258 , & V_261 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_122 ( V_8 , V_143 , V_261 ) ;
F_27 ( V_261 ) ;
return V_76 ;
}
static int F_123 ( struct V_140 * V_147 , union V_40 * V_258 , T_3 V_259 )
{
struct V_7 * V_8 = F_2 ( V_147 -> V_38 ) ;
struct V_142 * V_143 = F_69 ( V_147 ) ;
return F_124 ( V_8 , V_143 , V_258 ) ;
}
static T_5 F_125 ( struct V_38 * V_38 ,
struct V_262 * V_4 , char * V_131 )
{
struct V_7 * V_8 = F_126 ( V_38 , struct V_7 ,
V_58 . V_2 ) ;
return snprintf ( V_131 , 16 , L_6 , F_127 ( V_8 , 1 ) ) ;
}
int F_128 ( struct V_7 * V_8 )
{
int V_76 ;
int V_104 ;
struct V_1 * V_2 = & V_8 -> V_58 ;
F_129 ( V_2 -> V_37 , L_7 , V_263 ) ;
F_129 ( V_2 -> V_59 , L_8 , sizeof( V_2 -> V_59 ) ) ;
V_2 -> V_264 = V_265 ;
V_2 -> V_266 = V_267 ;
V_2 -> V_268 = 1 ;
V_2 -> V_269 = V_270 ;
V_2 -> V_2 . V_50 = F_130 ( V_8 ) ;
V_2 -> V_271 = 0 ;
V_2 -> V_272 = F_131 ( V_8 ) ;
V_2 -> V_2 . V_273 = & V_274 ;
V_2 -> V_275 = V_276 ;
V_2 -> V_277 = F_132 ( V_278 )
| F_132 ( V_279 )
| F_132 ( V_280 )
| F_132 ( V_281 )
| F_132 ( V_282 )
| F_132 ( V_283 )
| F_132 ( V_284 )
| F_132 ( V_285 )
| F_132 ( V_286 )
| F_132 ( V_287 )
| F_132 ( V_288 )
| F_132 ( V_289 )
| F_132 ( V_290 )
| F_132 ( V_291 )
| F_132 ( V_292 )
| F_132 ( V_293 )
| F_132 ( V_294 )
| F_132 ( V_295 )
| F_132 ( V_296 )
| F_132 ( V_297 )
| F_132 ( V_298 )
| F_132 ( V_299 )
| F_132 ( V_300 )
| F_132 ( V_301 )
| F_132 ( V_302 )
| F_132 ( V_303 )
| F_132 ( V_304 )
| F_132 ( V_305 )
| F_132 ( V_306 )
| F_132 ( V_307 )
| F_132 ( V_308 )
;
V_2 -> V_309 = F_1 ;
V_2 -> V_310 = F_17 ;
V_2 -> V_311 = F_4 ;
V_2 -> V_312 = F_19 ;
V_2 -> V_313 = F_20 ;
V_2 -> V_314 = F_9 ;
V_2 -> V_315 = F_13 ;
V_2 -> V_316 = F_11 ;
V_2 -> V_317 = F_12 ;
V_2 -> V_318 = F_15 ;
V_2 -> V_319 = F_22 ;
V_2 -> V_320 = F_25 ;
V_2 -> V_321 = V_322 ;
V_2 -> V_323 = F_28 ;
V_2 -> V_324 = F_30 ;
V_2 -> V_325 = F_31 ;
V_2 -> V_326 = F_38 ;
V_2 -> V_327 = F_41 ;
V_2 -> V_328 = F_43 ;
V_2 -> V_329 = F_45 ;
V_2 -> V_330 = F_51 ;
V_2 -> V_331 = F_56 ;
V_2 -> V_332 = F_59 ;
V_2 -> V_333 = F_60 ;
V_2 -> V_334 = F_62 ;
V_2 -> V_335 = F_65 ;
V_2 -> V_336 = F_68 ;
V_2 -> V_337 = F_72 ;
V_2 -> V_338 = F_75 ;
V_2 -> V_339 = F_92 ;
V_2 -> V_340 = F_93 ;
V_2 -> V_341 = F_95 ;
V_2 -> V_342 = F_98 ;
V_2 -> V_343 = F_100 ;
V_2 -> V_344 = F_102 ;
V_2 -> V_345 = F_105 ;
V_2 -> V_346 = F_106 ;
V_2 -> V_347 = F_108 ;
V_2 -> V_348 = F_110 ;
V_2 -> V_349 = F_112 ;
V_2 -> V_350 = F_114 ;
V_2 -> V_351 = F_117 ;
V_2 -> V_352 = F_120 ;
V_2 -> V_353 = F_123 ;
V_76 = F_133 ( V_2 , NULL ) ;
if ( V_76 ) {
F_6 ( L_9 , V_76 ) ;
goto V_26;
}
for ( V_104 = 0 ; V_104 < F_134 ( V_354 ) ; ++ V_104 ) {
V_76 = F_135 ( & V_2 -> V_2 , V_354 [ V_104 ] ) ;
if ( V_76 ) {
F_6 ( L_10 ,
V_104 , V_76 ) ;
goto V_98;
}
}
return 0 ;
V_98:
F_136 ( V_2 ) ;
V_26:
return V_76 ;
}
int F_137 ( struct V_7 * V_8 )
{
int V_104 ;
struct V_1 * V_2 = & V_8 -> V_58 ;
for ( V_104 = 0 ; V_104 < F_134 ( V_354 ) ; ++ V_104 )
F_138 ( & V_2 -> V_2 , V_354 [ V_104 ] ) ;
F_136 ( V_2 ) ;
return 0 ;
}
