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
F_16 ( V_38 -> V_50 , L_3 ,
V_22 ) ;
goto V_26;
}
V_25 = & V_8 -> V_25 ;
if ( F_5 ( V_39 >= V_25 -> V_4 . V_51 ) ) {
F_16 ( V_38 -> V_50 , L_4 ,
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
return V_8 -> V_67 -> V_68 ( V_8 , V_22 ) ;
}
static struct V_69 * F_21 ( struct V_1 * V_2 ,
struct V_5 * V_70 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_71 * V_72 ;
V_72 = F_22 ( & V_8 -> V_73 ) ;
return V_72 ? & V_72 -> V_74 : F_23 ( - V_75 ) ;
}
static int F_24 ( struct V_69 * V_74 )
{
struct V_71 * V_72 = F_25 ( V_74 ) ;
F_26 ( V_72 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_22 ,
struct V_76 * V_77 )
{
int V_78 ;
struct V_23 V_4 ;
V_78 = F_4 ( V_2 , V_22 , & V_4 ) ;
if ( V_78 )
return V_78 ;
V_77 -> V_51 = V_4 . V_51 ;
V_77 -> V_79 = V_4 . V_79 ;
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = V_83 ;
return 0 ;
}
static struct V_84 * F_28 ( struct V_1 * V_2 ,
struct V_69 * V_47 ,
struct V_5 * V_70 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_85 * V_86 ;
V_86 = F_22 ( & V_8 -> V_87 ) ;
return V_86 ? & V_86 -> V_88 : F_23 ( - V_75 ) ;
}
static int F_29 ( struct V_84 * V_88 )
{
struct V_85 * V_86 = F_30 ( V_88 ) ;
F_26 ( V_86 ) ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 , struct V_89 * V_4 ,
struct V_90 * V_91 )
{
int V_78 ;
union V_40 V_92 ;
struct V_46 V_93 ;
V_78 = F_10 ( & V_8 -> V_58 , V_4 -> V_22 ,
V_4 -> V_94 . V_95 , & V_92 ,
& V_93 ) ;
if ( V_78 ) {
F_32 ( L_5 , V_78 ) ;
return V_78 ;
}
V_78 = F_33 ( V_8 , V_4 -> V_22 , V_91 , V_4 ) ;
if ( ! V_78 )
V_78 = F_34 ( V_8 , V_91 , V_4 , & V_93 , & V_92 ) ;
if ( V_93 . V_28 )
F_35 ( V_93 . V_28 ) ;
return V_78 ;
}
static struct V_96 * F_36 ( struct V_84 * V_88 , struct V_89 * V_4 ,
struct V_5 * V_70 )
{
int V_78 ;
struct V_7 * V_8 = F_2 ( V_88 -> V_38 ) ;
struct V_85 * V_86 = F_30 ( V_88 ) ;
struct V_97 * V_98 ;
V_78 = F_37 ( V_8 , V_4 ) ;
if ( V_78 )
goto V_26;
V_98 = F_22 ( & V_8 -> V_99 ) ;
if ( ! V_98 ) {
V_78 = - V_75 ;
goto V_26;
}
F_38 ( V_86 ) ;
V_98 -> V_86 = V_86 ;
V_78 = F_31 ( V_8 , V_4 , & V_98 -> V_91 ) ;
if ( V_78 )
goto V_100;
return & V_98 -> V_101 ;
V_100:
F_26 ( V_86 ) ;
F_26 ( V_98 ) ;
V_26:
return F_23 ( V_78 ) ;
}
static int F_39 ( struct V_96 * V_101 , struct V_89 * V_4 )
{
int V_78 ;
struct V_7 * V_8 = F_2 ( V_101 -> V_38 ) ;
struct V_97 * V_98 = F_40 ( V_101 ) ;
V_78 = F_37 ( V_8 , V_4 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_31 ( V_8 , V_4 , & V_98 -> V_91 ) ;
if ( V_78 )
return V_78 ;
return 0 ;
}
static int F_41 ( struct V_96 * V_101 , struct V_89 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_101 -> V_38 ) ;
struct V_97 * V_98 = F_40 ( V_101 ) ;
F_42 ( V_8 , & V_98 -> V_91 , V_4 ) ;
return 0 ;
}
static int F_43 ( struct V_96 * V_101 )
{
struct V_97 * V_98 = F_40 ( V_101 ) ;
F_26 ( V_98 -> V_86 ) ;
F_26 ( V_98 ) ;
return 0 ;
}
static int F_44 ( struct V_102 * V_103 , struct V_104 * V_105 )
{
int V_78 ;
int V_106 ;
T_2 V_107 ;
struct V_108 * V_109 ;
int V_110 = V_105 -> V_110 ;
if ( F_5 ( F_45 ( V_103 -> V_111 ) ) ) {
V_78 = - V_75 ;
goto V_26;
}
if ( F_5 ( V_110 > V_103 -> V_112 ) ) {
V_78 = - V_11 ;
goto V_26;
}
V_107 = 0 ;
for ( V_106 = 0 ; V_106 < V_110 ; V_106 ++ )
V_107 += V_105 -> V_113 [ V_106 ] . V_107 ;
V_109 = F_46 ( V_103 -> V_111 ) ;
V_109 -> V_114 = V_105 -> V_114 ;
V_109 -> V_110 = V_110 ;
memcpy ( V_109 -> V_115 . V_116 , V_105 -> V_113 ,
V_110 * sizeof( struct V_117 ) ) ;
V_109 -> V_115 . V_107 = V_107 ;
V_109 -> V_115 . V_118 = V_107 ;
V_109 -> V_115 . V_110 = V_110 ;
V_109 -> V_115 . V_119 = 0 ;
V_109 -> V_115 . V_120 = 0 ;
F_47 () ;
F_48 ( V_103 -> V_111 ) ;
return 0 ;
V_26:
return V_78 ;
}
static struct V_121 * F_49 ( struct V_84 * V_88 ,
struct V_122 * V_123 ,
struct V_5 * V_70 )
{
int V_78 ;
struct V_7 * V_8 = F_2 ( V_88 -> V_38 ) ;
struct V_85 * V_86 = F_30 ( V_88 ) ;
struct V_124 * V_125 ;
struct V_69 * V_47 = V_70 ? V_88 -> V_126 -> V_47 : NULL ;
V_78 = F_50 ( V_8 , NULL , & V_123 -> V_4 , V_127 ) ;
if ( V_78 )
goto V_26;
V_125 = F_22 ( & V_8 -> V_128 ) ;
if ( ! V_125 ) {
V_78 = - V_75 ;
goto V_26;
}
F_51 ( V_125 ) ;
F_38 ( V_86 ) ;
V_125 -> V_86 = V_86 ;
V_78 = F_52 ( V_8 , V_125 , V_123 , V_47 , V_70 ) ;
if ( V_78 )
goto V_100;
return & V_125 -> V_129 ;
V_100:
F_26 ( V_86 ) ;
F_53 ( V_125 ) ;
F_26 ( V_125 ) ;
V_26:
return F_23 ( V_78 ) ;
}
static int F_54 ( struct V_121 * V_129 , struct V_130 * V_4 ,
enum V_131 V_53 ,
struct V_5 * V_70 )
{
int V_78 ;
struct V_124 * V_125 = F_55 ( V_129 ) ;
struct V_7 * V_8 = F_2 ( V_129 -> V_38 ) ;
V_78 = F_50 ( V_8 , V_125 , V_4 , V_53 ) ;
if ( V_78 )
goto V_26;
V_78 = F_56 ( V_8 , V_125 , V_4 , V_53 , V_70 ) ;
if ( V_78 )
goto V_26;
return 0 ;
V_26:
return V_78 ;
}
static int F_57 ( struct V_121 * V_129 , struct V_130 * V_4 )
{
struct V_124 * V_125 = F_55 ( V_129 ) ;
if ( V_125 -> error )
return - V_11 ;
V_4 -> V_132 = V_125 -> V_103 . V_111 -> V_133 -> V_134 ;
V_4 -> V_112 = V_125 -> V_103 . V_112 ;
V_4 -> V_135 = V_125 -> V_136 ;
return 0 ;
}
static int F_58 ( struct V_121 * V_129 )
{
struct V_124 * V_125 = F_55 ( V_129 ) ;
if ( V_125 -> V_103 . V_111 )
F_59 ( V_125 -> V_103 . V_111 ) ;
F_26 ( V_125 -> V_86 ) ;
F_53 ( V_125 ) ;
F_26 ( V_125 ) ;
return 0 ;
}
static int F_60 ( struct V_121 * V_129 , struct V_104 * V_137 ,
struct V_104 * * V_138 )
{
int V_78 = 0 ;
unsigned long V_139 ;
struct V_124 * V_125 = F_55 ( V_129 ) ;
F_61 ( & V_125 -> V_103 . V_140 , V_139 ) ;
while ( V_137 ) {
V_78 = F_44 ( & V_125 -> V_103 , V_137 ) ;
if ( F_5 ( V_78 ) )
break;
V_137 = V_137 -> V_141 ;
}
F_62 ( & V_125 -> V_103 . V_140 , V_139 ) ;
if ( V_78 )
* V_138 = V_137 ;
return V_78 ;
}
static struct V_142 * F_63 ( struct V_84 * V_88 ,
struct V_143 * V_123 ,
struct V_5 * V_70 )
{
int V_78 ;
struct V_7 * V_8 = F_2 ( V_88 -> V_38 ) ;
struct V_85 * V_86 = F_30 ( V_88 ) ;
struct V_144 * V_145 ;
V_78 = F_64 ( V_8 , V_123 ) ;
if ( V_78 )
goto V_26;
V_145 = F_22 ( & V_8 -> V_146 ) ;
if ( ! V_145 ) {
V_78 = - V_75 ;
goto V_26;
}
if ( V_70 ) {
if ( V_70 -> V_9 ) {
V_78 = - V_11 ;
goto V_100;
}
V_145 -> V_147 = 1 ;
}
F_51 ( V_145 ) ;
V_78 = F_65 ( V_8 , V_145 , V_86 , V_123 , V_70 , V_88 ) ;
if ( V_78 )
goto V_148;
return & V_145 -> V_149 ;
V_148:
F_53 ( V_145 ) ;
V_100:
F_26 ( V_145 ) ;
V_26:
return F_23 ( V_78 ) ;
}
static int F_66 ( struct V_142 * V_149 , struct V_150 * V_4 ,
int V_53 , struct V_5 * V_70 )
{
int V_78 ;
struct V_7 * V_8 = F_2 ( V_149 -> V_38 ) ;
struct V_144 * V_145 = F_67 ( V_149 ) ;
V_78 = F_68 ( V_8 , V_145 , V_4 , V_53 ) ;
if ( V_78 )
goto V_26;
V_78 = F_69 ( V_145 , V_4 , V_53 , V_70 ) ;
if ( V_78 )
goto V_26;
return 0 ;
V_26:
return V_78 ;
}
static int F_70 ( struct V_142 * V_149 , struct V_150 * V_4 ,
int V_53 , struct V_143 * V_123 )
{
struct V_144 * V_145 = F_67 ( V_149 ) ;
F_71 ( V_145 , V_123 ) ;
F_72 ( V_145 , V_4 , V_53 ) ;
return 0 ;
}
static int F_73 ( struct V_142 * V_149 )
{
struct V_144 * V_145 = F_67 ( V_149 ) ;
F_74 ( V_145 ) ;
F_53 ( V_145 ) ;
F_26 ( V_145 ) ;
return 0 ;
}
static int F_75 ( struct V_144 * V_145 , struct V_151 * V_105 ,
unsigned int V_53 , unsigned int V_107 )
{
int V_110 = V_105 -> V_110 ;
struct V_152 * V_153 = & V_145 -> V_153 ;
if ( F_5 ( V_110 > V_153 -> V_112 ) )
goto V_26;
if ( F_5 ( V_53 & V_154 ) ) {
if ( V_107 < 8 )
goto V_26;
if ( F_76 ( V_105 ) -> V_155 & 0x7 )
goto V_26;
}
if ( F_5 ( ( V_105 -> V_156 & V_157 ) &&
( V_107 > V_153 -> V_158 ) ) )
goto V_26;
return 0 ;
V_26:
return - V_11 ;
}
static void F_77 ( struct V_144 * V_145 , struct V_159 * V_137 ,
struct V_151 * V_105 )
{
V_137 -> V_114 = V_105 -> V_114 ;
V_137 -> V_110 = V_105 -> V_110 ;
V_137 -> V_160 = V_105 -> V_160 ;
V_137 -> V_156 = V_105 -> V_156 ;
if ( F_78 ( V_145 ) == V_161 ||
F_78 ( V_145 ) == V_162 ||
F_78 ( V_145 ) == V_163 ) {
V_137 -> V_137 . V_164 . V_165 = F_79 ( V_105 ) -> V_165 ;
V_137 -> V_137 . V_164 . V_166 = F_79 ( V_105 ) -> V_166 ;
if ( F_78 ( V_145 ) == V_163 )
V_137 -> V_137 . V_164 . V_167 = F_79 ( V_105 ) -> V_167 ;
if ( V_137 -> V_160 == V_168 )
V_137 -> V_169 . V_170 = V_105 -> V_169 . V_170 ;
} else {
switch ( V_137 -> V_160 ) {
case V_171 :
V_137 -> V_169 . V_170 = V_105 -> V_169 . V_170 ;
case V_172 :
case V_173 :
V_137 -> V_137 . V_174 . V_155 = F_80 ( V_105 ) -> V_155 ;
V_137 -> V_137 . V_174 . V_175 = F_80 ( V_105 ) -> V_175 ;
break;
case V_168 :
V_137 -> V_169 . V_170 = V_105 -> V_169 . V_170 ;
break;
case V_176 :
V_137 -> V_169 . V_177 = V_105 -> V_169 . V_177 ;
break;
case V_178 :
case V_179 :
V_137 -> V_137 . V_180 . V_155 =
F_76 ( V_105 ) -> V_155 ;
V_137 -> V_137 . V_180 . V_181 =
F_76 ( V_105 ) -> V_181 ;
V_137 -> V_137 . V_180 . V_182 = F_76 ( V_105 ) -> V_182 ;
V_137 -> V_137 . V_180 . V_175 = F_76 ( V_105 ) -> V_175 ;
break;
case V_183 :
V_137 -> V_169 . V_177 = V_105 -> V_169 . V_177 ;
break;
case V_184 :
V_137 -> V_137 . V_185 . V_186 = F_81 ( V_105 ) -> V_186 ;
V_137 -> V_137 . V_185 . V_187 = F_81 ( V_105 ) -> V_187 ;
V_137 -> V_137 . V_185 . V_188 = F_81 ( V_105 ) -> V_188 ;
break;
default:
break;
}
}
}
static int F_82 ( struct V_144 * V_145 , struct V_151 * V_105 ,
unsigned int V_53 , unsigned int V_107 ,
struct V_189 * V_190 )
{
int V_110 = V_105 -> V_110 ;
struct V_117 * V_116 ;
int V_106 ;
T_1 * V_191 ;
F_77 ( V_145 , & V_190 -> V_137 , V_105 ) ;
if ( F_78 ( V_145 ) == V_161 ||
F_78 ( V_145 ) == V_162 ||
F_78 ( V_145 ) == V_163 )
memcpy ( & V_190 -> V_91 , & F_40 ( F_79 ( V_105 ) -> V_98 ) -> V_91 , sizeof( V_190 -> V_91 ) ) ;
if ( F_5 ( V_105 -> V_156 & V_157 ) ) {
V_191 = V_190 -> V_115 . V_192 ;
V_116 = V_105 -> V_113 ;
for ( V_106 = 0 ; V_106 < V_110 ; V_106 ++ , V_116 ++ ) {
if ( V_145 -> V_147 && F_83 ( V_191 , ( V_193 void * )
( V_194 ) V_116 -> V_195 , V_116 -> V_107 ) )
return - V_196 ;
else if ( ! V_145 -> V_147 )
memcpy ( V_191 , ( void * ) ( V_194 ) V_116 -> V_195 ,
V_116 -> V_107 ) ;
V_191 += V_116 -> V_107 ;
}
} else if ( V_53 & V_197 ) {
V_190 -> V_53 = V_53 ;
V_190 -> V_198 = V_199 ;
return 0 ;
} else
memcpy ( V_190 -> V_115 . V_116 , V_105 -> V_113 ,
V_110 * sizeof( struct V_117 ) ) ;
V_190 -> V_200 = ( V_53 & V_154 ) ?
F_76 ( V_105 ) -> V_155 :
F_80 ( V_105 ) -> V_155 ;
V_190 -> V_53 = V_53 ;
V_190 -> V_115 . V_107 = V_107 ;
V_190 -> V_115 . V_118 = V_107 ;
V_190 -> V_115 . V_110 = V_110 ;
V_190 -> V_115 . V_119 = 0 ;
V_190 -> V_115 . V_120 = 0 ;
V_190 -> V_198 = V_199 ;
V_190 -> V_201 = F_84 ( 1 , & V_145 -> V_201 ) ;
return 0 ;
}
static int F_85 ( struct V_144 * V_145 , struct V_151 * V_105 ,
unsigned int V_53 , T_2 V_107 )
{
int V_78 ;
struct V_152 * V_153 = & V_145 -> V_153 ;
struct V_189 * V_202 ;
unsigned long V_139 ;
V_78 = F_75 ( V_145 , V_105 , V_53 , V_107 ) ;
if ( V_78 )
return V_78 ;
F_61 ( & V_145 -> V_153 . V_203 , V_139 ) ;
if ( F_5 ( F_45 ( V_153 -> V_111 ) ) ) {
V_78 = - V_75 ;
goto V_26;
}
V_202 = F_46 ( V_153 -> V_111 ) ;
V_78 = F_82 ( V_145 , V_105 , V_53 , V_107 , V_202 ) ;
if ( F_5 ( V_78 ) )
goto V_26;
F_47 () ;
F_48 ( V_153 -> V_111 ) ;
F_62 ( & V_145 -> V_153 . V_203 , V_139 ) ;
return 0 ;
V_26:
F_62 ( & V_145 -> V_153 . V_203 , V_139 ) ;
return V_78 ;
}
static int F_86 ( struct V_144 * V_145 , struct V_151 * V_137 ,
struct V_151 * * V_138 )
{
int V_78 = 0 ;
unsigned int V_53 ;
unsigned int V_107 = 0 ;
int V_106 ;
int V_204 ;
while ( V_137 ) {
V_53 = F_87 ( V_137 -> V_160 , V_145 ) ;
if ( F_5 ( ! V_53 ) ) {
V_78 = - V_11 ;
* V_138 = V_137 ;
break;
}
if ( F_5 ( ( V_137 -> V_156 & V_157 ) &&
! ( V_53 & V_205 ) ) ) {
V_78 = - V_11 ;
* V_138 = V_137 ;
break;
}
V_107 = 0 ;
for ( V_106 = 0 ; V_106 < V_137 -> V_110 ; V_106 ++ )
V_107 += V_137 -> V_113 [ V_106 ] . V_107 ;
V_78 = F_85 ( V_145 , V_137 , V_53 , V_107 ) ;
if ( V_78 ) {
* V_138 = V_137 ;
break;
}
V_137 = V_137 -> V_141 ;
}
V_204 = ( F_78 ( V_145 ) == V_163 ) ||
( F_88 ( V_145 -> V_153 . V_111 ) > 1 ) ;
F_89 ( & V_145 -> V_206 . V_207 , V_204 ) ;
return V_78 ;
}
static int F_90 ( struct V_142 * V_149 , struct V_151 * V_137 ,
struct V_151 * * V_138 )
{
struct V_144 * V_145 = F_67 ( V_149 ) ;
if ( F_5 ( ! V_145 -> V_208 ) ) {
* V_138 = V_137 ;
return - V_11 ;
}
if ( F_5 ( V_145 -> V_206 . V_198 < V_209 ) ) {
* V_138 = V_137 ;
return - V_11 ;
}
if ( V_145 -> V_147 ) {
F_89 ( & V_145 -> V_206 . V_207 , 0 ) ;
return 0 ;
} else
return F_86 ( V_145 , V_137 , V_138 ) ;
}
static int F_91 ( struct V_142 * V_149 , struct V_104 * V_137 ,
struct V_104 * * V_138 )
{
int V_78 = 0 ;
struct V_144 * V_145 = F_67 ( V_149 ) ;
struct V_102 * V_103 = & V_145 -> V_103 ;
unsigned long V_139 ;
if ( F_5 ( ( F_92 ( V_145 ) < V_210 ) || ! V_145 -> V_208 ) ) {
* V_138 = V_137 ;
V_78 = - V_11 ;
goto V_26;
}
if ( F_5 ( V_145 -> V_125 ) ) {
* V_138 = V_137 ;
V_78 = - V_11 ;
goto V_26;
}
F_61 ( & V_103 -> V_140 , V_139 ) ;
while ( V_137 ) {
V_78 = F_44 ( V_103 , V_137 ) ;
if ( F_5 ( V_78 ) ) {
* V_138 = V_137 ;
break;
}
V_137 = V_137 -> V_141 ;
}
F_62 ( & V_103 -> V_140 , V_139 ) ;
V_26:
return V_78 ;
}
static struct V_211 * F_93 ( struct V_1 * V_2 ,
const struct V_212 * V_4 ,
struct V_69 * V_47 ,
struct V_5 * V_70 )
{
int V_78 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_213 * V_214 ;
if ( V_4 -> V_139 )
return F_23 ( - V_11 ) ;
V_78 = F_94 ( V_8 , NULL , V_4 -> V_215 , V_4 -> V_216 , V_70 ) ;
if ( V_78 )
goto V_26;
V_214 = F_22 ( & V_8 -> V_217 ) ;
if ( ! V_214 ) {
V_78 = - V_75 ;
goto V_26;
}
V_78 = F_95 ( V_8 , V_214 , V_4 -> V_215 , V_4 -> V_216 ,
V_47 , V_70 ) ;
if ( V_78 )
goto V_100;
return & V_214 -> V_218 ;
V_100:
F_26 ( V_214 ) ;
V_26:
return F_23 ( V_78 ) ;
}
static int F_96 ( struct V_211 * V_218 )
{
struct V_213 * V_214 = F_97 ( V_218 ) ;
F_26 ( V_214 ) ;
return 0 ;
}
static int F_98 ( struct V_211 * V_218 , int V_215 , struct V_5 * V_70 )
{
int V_78 ;
struct V_213 * V_214 = F_97 ( V_218 ) ;
struct V_7 * V_8 = F_2 ( V_218 -> V_38 ) ;
V_78 = F_94 ( V_8 , V_214 , V_215 , 0 , V_70 ) ;
if ( V_78 )
goto V_26;
V_78 = F_99 ( V_214 , V_215 , V_70 ) ;
if ( V_78 )
goto V_26;
return 0 ;
V_26:
return V_78 ;
}
static int F_100 ( struct V_211 * V_218 , int V_219 , struct V_220 * V_221 )
{
int V_106 ;
struct V_213 * V_214 = F_97 ( V_218 ) ;
struct V_222 * V_215 ;
unsigned long V_139 ;
F_61 ( & V_214 -> V_223 , V_139 ) ;
for ( V_106 = 0 ; V_106 < V_219 ; V_106 ++ ) {
V_215 = F_101 ( V_214 -> V_111 ) ;
if ( ! V_215 )
break;
memcpy ( V_221 ++ , & V_215 -> V_224 , sizeof( * V_221 ) ) ;
F_102 ( V_214 -> V_111 ) ;
}
F_62 ( & V_214 -> V_223 , V_139 ) ;
return V_106 ;
}
static int F_103 ( struct V_211 * V_218 , int V_225 )
{
struct V_213 * V_214 = F_97 ( V_218 ) ;
int V_226 = F_88 ( V_214 -> V_111 ) ;
return ( V_226 > V_225 ) ? V_225 : V_226 ;
}
static int F_104 ( struct V_211 * V_218 , enum V_227 V_139 )
{
struct V_213 * V_214 = F_97 ( V_218 ) ;
unsigned long V_228 ;
int V_42 = 0 ;
F_61 ( & V_214 -> V_223 , V_228 ) ;
if ( V_214 -> V_229 != V_230 )
V_214 -> V_229 = V_139 & V_231 ;
if ( ( V_139 & V_232 ) && ! F_105 ( V_214 -> V_111 ) )
V_42 = 1 ;
F_62 ( & V_214 -> V_223 , V_228 ) ;
return V_42 ;
}
static struct V_233 * F_106 ( struct V_84 * V_88 , int V_188 )
{
struct V_7 * V_8 = F_2 ( V_88 -> V_38 ) ;
struct V_85 * V_86 = F_30 ( V_88 ) ;
struct V_234 * V_186 ;
int V_78 ;
V_186 = F_22 ( & V_8 -> V_235 ) ;
if ( ! V_186 ) {
V_78 = - V_75 ;
goto V_26;
}
F_51 ( V_186 ) ;
F_38 ( V_86 ) ;
V_78 = F_107 ( V_8 , V_86 , V_188 , V_186 ) ;
if ( V_78 )
goto V_100;
return & V_186 -> V_236 ;
V_100:
F_26 ( V_86 ) ;
F_53 ( V_186 ) ;
F_26 ( V_186 ) ;
V_26:
return F_23 ( V_78 ) ;
}
static struct V_233 * F_108 ( struct V_84 * V_88 ,
T_4 V_237 ,
T_4 V_107 ,
T_4 V_200 ,
int V_188 , struct V_5 * V_70 )
{
int V_78 ;
struct V_7 * V_8 = F_2 ( V_88 -> V_38 ) ;
struct V_85 * V_86 = F_30 ( V_88 ) ;
struct V_234 * V_186 ;
V_186 = F_22 ( & V_8 -> V_235 ) ;
if ( ! V_186 ) {
V_78 = - V_75 ;
goto V_100;
}
F_51 ( V_186 ) ;
F_38 ( V_86 ) ;
V_78 = F_109 ( V_8 , V_86 , V_237 , V_107 , V_200 ,
V_188 , V_70 , V_186 ) ;
if ( V_78 )
goto V_148;
return & V_186 -> V_236 ;
V_148:
F_26 ( V_86 ) ;
F_53 ( V_186 ) ;
F_26 ( V_186 ) ;
V_100:
return F_23 ( V_78 ) ;
}
static int F_110 ( struct V_233 * V_236 )
{
struct V_234 * V_186 = F_111 ( V_236 ) ;
V_186 -> V_198 = V_238 ;
F_26 ( V_186 -> V_86 ) ;
F_53 ( V_186 ) ;
F_26 ( V_186 ) ;
return 0 ;
}
static struct V_233 * F_112 ( struct V_84 * V_88 ,
enum V_239 V_240 ,
T_2 V_241 )
{
struct V_7 * V_8 = F_2 ( V_88 -> V_38 ) ;
struct V_85 * V_86 = F_30 ( V_88 ) ;
struct V_234 * V_186 ;
int V_78 ;
if ( V_240 != V_242 )
return F_23 ( - V_11 ) ;
V_186 = F_22 ( & V_8 -> V_235 ) ;
if ( ! V_186 ) {
V_78 = - V_75 ;
goto V_26;
}
F_51 ( V_186 ) ;
F_38 ( V_86 ) ;
V_78 = F_113 ( V_8 , V_86 , V_241 , V_186 ) ;
if ( V_78 )
goto V_100;
return & V_186 -> V_236 ;
V_100:
F_26 ( V_86 ) ;
F_53 ( V_186 ) ;
F_26 ( V_186 ) ;
V_26:
return F_23 ( V_78 ) ;
}
static int F_114 ( struct V_233 * V_236 , T_4 V_195 )
{
struct V_234 * V_186 = F_111 ( V_236 ) ;
struct V_243 * V_244 ;
struct V_245 * V_133 ;
if ( F_5 ( V_186 -> V_246 == V_186 -> V_247 ) )
return - V_75 ;
V_244 = V_186 -> V_244 [ V_186 -> V_246 / V_248 ] ;
V_133 = & V_244 -> V_133 [ V_186 -> V_246 % V_248 ] ;
V_133 -> V_195 = V_195 ;
V_133 -> V_249 = V_236 -> V_250 ;
V_186 -> V_246 ++ ;
return 0 ;
}
static int F_115 ( struct V_233 * V_236 , struct V_251 * V_252 ,
int V_253 , unsigned int * V_254 )
{
struct V_234 * V_186 = F_111 ( V_236 ) ;
int V_255 ;
V_186 -> V_246 = 0 ;
V_255 = F_116 ( V_236 , V_252 , V_253 , V_254 , F_114 ) ;
V_186 -> V_256 = V_236 -> V_200 ;
V_186 -> V_200 = V_236 -> V_200 ;
V_186 -> V_107 = V_236 -> V_107 ;
V_186 -> V_257 = F_117 ( V_236 -> V_250 ) ;
V_186 -> V_258 = V_236 -> V_250 - 1 ;
V_186 -> V_259 = V_186 -> V_200 & V_186 -> V_258 ;
return V_255 ;
}
static int F_118 ( struct V_142 * V_149 , union V_40 * V_260 , T_3 V_261 )
{
int V_78 ;
struct V_7 * V_8 = F_2 ( V_149 -> V_38 ) ;
struct V_144 * V_145 = F_67 ( V_149 ) ;
struct V_262 * V_263 ;
V_78 = F_119 ( V_8 , V_260 , & V_263 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_120 ( V_8 , V_145 , V_263 ) ;
F_26 ( V_263 ) ;
return V_78 ;
}
static int F_121 ( struct V_142 * V_149 , union V_40 * V_260 , T_3 V_261 )
{
struct V_7 * V_8 = F_2 ( V_149 -> V_38 ) ;
struct V_144 * V_145 = F_67 ( V_149 ) ;
return F_122 ( V_8 , V_145 , V_260 ) ;
}
static T_5 F_123 ( struct V_38 * V_38 ,
struct V_264 * V_4 , char * V_133 )
{
struct V_7 * V_8 = F_124 ( V_38 , struct V_7 ,
V_58 . V_2 ) ;
char * V_37 ;
V_37 = V_8 -> V_67 -> V_265 ( V_8 , 1 ) ;
return snprintf ( V_133 , 16 , L_6 , V_37 ) ;
}
int F_125 ( struct V_7 * V_8 )
{
int V_78 ;
int V_106 ;
struct V_1 * V_2 = & V_8 -> V_58 ;
F_126 ( V_2 -> V_37 , L_7 , V_266 ) ;
F_126 ( V_2 -> V_59 , L_8 , sizeof( V_2 -> V_59 ) ) ;
V_2 -> V_267 = V_268 ;
V_2 -> V_269 = V_270 ;
V_2 -> V_271 = 1 ;
V_2 -> V_272 = V_273 ;
V_2 -> V_50 = V_8 -> V_67 -> V_50 ( V_8 ) ;
V_2 -> V_274 = 0 ;
V_2 -> V_275 = V_8 -> V_67 -> V_275 ( V_8 ) ;
V_2 -> V_276 = & V_277 ;
V_2 -> V_278 = V_279 ;
V_2 -> V_280 = F_127 ( V_281 )
| F_127 ( V_282 )
| F_127 ( V_283 )
| F_127 ( V_284 )
| F_127 ( V_285 )
| F_127 ( V_286 )
| F_127 ( V_287 )
| F_127 ( V_288 )
| F_127 ( V_289 )
| F_127 ( V_290 )
| F_127 ( V_291 )
| F_127 ( V_292 )
| F_127 ( V_293 )
| F_127 ( V_294 )
| F_127 ( V_295 )
| F_127 ( V_296 )
| F_127 ( V_297 )
| F_127 ( V_298 )
| F_127 ( V_299 )
| F_127 ( V_300 )
| F_127 ( V_301 )
| F_127 ( V_302 )
| F_127 ( V_303 )
| F_127 ( V_304 )
| F_127 ( V_305 )
| F_127 ( V_306 )
| F_127 ( V_307 )
| F_127 ( V_308 )
| F_127 ( V_309 )
| F_127 ( V_310 )
| F_127 ( V_311 )
;
V_2 -> V_312 = F_1 ;
V_2 -> V_313 = F_17 ;
V_2 -> V_314 = F_4 ;
V_2 -> V_315 = F_19 ;
V_2 -> V_316 = F_20 ;
V_2 -> V_317 = F_9 ;
V_2 -> V_318 = F_13 ;
V_2 -> V_319 = F_11 ;
V_2 -> V_320 = F_12 ;
V_2 -> V_321 = F_15 ;
V_2 -> V_322 = F_21 ;
V_2 -> V_323 = F_24 ;
V_2 -> V_324 = V_325 ;
V_2 -> V_326 = F_27 ;
V_2 -> V_327 = F_28 ;
V_2 -> V_328 = F_29 ;
V_2 -> V_329 = F_36 ;
V_2 -> V_330 = F_39 ;
V_2 -> V_331 = F_41 ;
V_2 -> V_332 = F_43 ;
V_2 -> V_333 = F_49 ;
V_2 -> V_334 = F_54 ;
V_2 -> V_335 = F_57 ;
V_2 -> V_336 = F_58 ;
V_2 -> V_337 = F_60 ;
V_2 -> V_338 = F_63 ;
V_2 -> V_339 = F_66 ;
V_2 -> V_340 = F_70 ;
V_2 -> V_341 = F_73 ;
V_2 -> V_342 = F_90 ;
V_2 -> V_343 = F_91 ;
V_2 -> V_344 = F_93 ;
V_2 -> V_345 = F_96 ;
V_2 -> V_346 = F_98 ;
V_2 -> V_347 = F_100 ;
V_2 -> V_348 = F_103 ;
V_2 -> V_349 = F_104 ;
V_2 -> V_350 = F_106 ;
V_2 -> V_351 = F_108 ;
V_2 -> V_352 = F_110 ;
V_2 -> V_353 = F_112 ;
V_2 -> V_354 = F_115 ;
V_2 -> V_355 = F_118 ;
V_2 -> V_356 = F_121 ;
V_78 = F_128 ( V_2 , NULL ) ;
if ( V_78 ) {
F_6 ( L_9 , V_78 ) ;
goto V_26;
}
for ( V_106 = 0 ; V_106 < F_129 ( V_357 ) ; ++ V_106 ) {
V_78 = F_130 ( & V_2 -> V_2 , V_357 [ V_106 ] ) ;
if ( V_78 ) {
F_6 ( L_10 ,
V_106 , V_78 ) ;
goto V_100;
}
}
return 0 ;
V_100:
F_131 ( V_2 ) ;
V_26:
return V_78 ;
}
int F_132 ( struct V_7 * V_8 )
{
int V_106 ;
struct V_1 * V_2 = & V_8 -> V_58 ;
for ( V_106 = 0 ; V_106 < F_129 ( V_357 ) ; ++ V_106 )
F_133 ( & V_2 -> V_2 , V_357 [ V_106 ] ) ;
F_131 ( V_2 ) ;
return 0 ;
}
