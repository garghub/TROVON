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
V_76 = F_10 ( & V_8 -> V_58 , F_34 ( V_4 ) ,
F_35 ( V_4 ) -> V_92 , & V_90 ,
& V_91 ) ;
if ( V_76 ) {
F_36 ( L_5 , V_76 ) ;
return V_76 ;
}
V_76 = F_37 ( V_8 , F_34 ( V_4 ) , V_89 , V_4 ) ;
if ( ! V_76 )
V_76 = F_38 ( V_8 , V_89 , V_4 , & V_91 , & V_90 ) ;
if ( V_91 . V_28 )
F_39 ( V_91 . V_28 ) ;
return V_76 ;
}
static struct V_93 * F_40 ( struct V_82 * V_86 ,
struct V_87 * V_4 ,
struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_94 * V_95 ;
V_76 = F_41 ( V_8 , V_4 ) ;
if ( V_76 )
goto V_26;
V_95 = F_23 ( & V_8 -> V_96 ) ;
if ( ! V_95 ) {
V_76 = - V_73 ;
goto V_26;
}
F_42 ( V_84 ) ;
V_95 -> V_84 = V_84 ;
V_76 = F_33 ( V_8 , V_4 , & V_95 -> V_89 ) ;
if ( V_76 )
goto V_97;
return & V_95 -> V_98 ;
V_97:
F_27 ( V_84 ) ;
F_27 ( V_95 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static int F_43 ( struct V_93 * V_98 , struct V_87 * V_4 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_98 -> V_38 ) ;
struct V_94 * V_95 = F_44 ( V_98 ) ;
V_76 = F_41 ( V_8 , V_4 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_33 ( V_8 , V_4 , & V_95 -> V_89 ) ;
if ( V_76 )
return V_76 ;
return 0 ;
}
static int F_45 ( struct V_93 * V_98 , struct V_87 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_98 -> V_38 ) ;
struct V_94 * V_95 = F_44 ( V_98 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> type = V_98 -> type ;
F_46 ( V_8 , & V_95 -> V_89 , V_4 ) ;
return 0 ;
}
static int F_47 ( struct V_93 * V_98 )
{
struct V_94 * V_95 = F_44 ( V_98 ) ;
F_27 ( V_95 -> V_84 ) ;
F_27 ( V_95 ) ;
return 0 ;
}
static int F_48 ( struct V_99 * V_100 , struct V_101 * V_102 )
{
int V_76 ;
int V_103 ;
T_2 V_104 ;
struct V_105 * V_106 ;
int V_107 = V_102 -> V_107 ;
if ( F_5 ( F_49 ( V_100 -> V_108 ) ) ) {
V_76 = - V_73 ;
goto V_26;
}
if ( F_5 ( V_107 > V_100 -> V_109 ) ) {
V_76 = - V_11 ;
goto V_26;
}
V_104 = 0 ;
for ( V_103 = 0 ; V_103 < V_107 ; V_103 ++ )
V_104 += V_102 -> V_110 [ V_103 ] . V_104 ;
V_106 = F_50 ( V_100 -> V_108 ) ;
V_106 -> V_111 = V_102 -> V_111 ;
V_106 -> V_107 = V_107 ;
memcpy ( V_106 -> V_112 . V_113 , V_102 -> V_110 ,
V_107 * sizeof( struct V_114 ) ) ;
V_106 -> V_112 . V_104 = V_104 ;
V_106 -> V_112 . V_115 = V_104 ;
V_106 -> V_112 . V_107 = V_107 ;
V_106 -> V_112 . V_116 = 0 ;
V_106 -> V_112 . V_117 = 0 ;
F_51 () ;
F_52 ( V_100 -> V_108 ) ;
return 0 ;
V_26:
return V_76 ;
}
static struct V_118 * F_53 ( struct V_82 * V_86 ,
struct V_119 * V_120 ,
struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_121 * V_122 ;
struct V_67 * V_47 = V_68 ? V_86 -> V_123 -> V_47 : NULL ;
V_76 = F_54 ( V_8 , NULL , & V_120 -> V_4 , V_124 ) ;
if ( V_76 )
goto V_26;
V_122 = F_23 ( & V_8 -> V_125 ) ;
if ( ! V_122 ) {
V_76 = - V_73 ;
goto V_26;
}
F_55 ( V_122 ) ;
F_42 ( V_84 ) ;
V_122 -> V_84 = V_84 ;
V_76 = F_56 ( V_8 , V_122 , V_120 , V_47 , V_68 ) ;
if ( V_76 )
goto V_97;
return & V_122 -> V_126 ;
V_97:
F_27 ( V_84 ) ;
F_57 ( V_122 ) ;
F_27 ( V_122 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static int F_58 ( struct V_118 * V_126 , struct V_127 * V_4 ,
enum V_128 V_53 ,
struct V_5 * V_68 )
{
int V_76 ;
struct V_121 * V_122 = F_59 ( V_126 ) ;
struct V_7 * V_8 = F_2 ( V_126 -> V_38 ) ;
V_76 = F_54 ( V_8 , V_122 , V_4 , V_53 ) ;
if ( V_76 )
goto V_26;
V_76 = F_60 ( V_8 , V_122 , V_4 , V_53 , V_68 ) ;
if ( V_76 )
goto V_26;
return 0 ;
V_26:
return V_76 ;
}
static int F_61 ( struct V_118 * V_126 , struct V_127 * V_4 )
{
struct V_121 * V_122 = F_59 ( V_126 ) ;
if ( V_122 -> error )
return - V_11 ;
V_4 -> V_129 = V_122 -> V_100 . V_108 -> V_130 -> V_131 ;
V_4 -> V_109 = V_122 -> V_100 . V_109 ;
V_4 -> V_132 = V_122 -> V_133 ;
return 0 ;
}
static int F_62 ( struct V_118 * V_126 )
{
struct V_121 * V_122 = F_59 ( V_126 ) ;
if ( V_122 -> V_100 . V_108 )
F_63 ( V_122 -> V_100 . V_108 ) ;
F_27 ( V_122 -> V_84 ) ;
F_57 ( V_122 ) ;
F_27 ( V_122 ) ;
return 0 ;
}
static int F_64 ( struct V_118 * V_126 , struct V_101 * V_134 ,
struct V_101 * * V_135 )
{
int V_76 = 0 ;
unsigned long V_136 ;
struct V_121 * V_122 = F_59 ( V_126 ) ;
F_65 ( & V_122 -> V_100 . V_137 , V_136 ) ;
while ( V_134 ) {
V_76 = F_48 ( & V_122 -> V_100 , V_134 ) ;
if ( F_5 ( V_76 ) )
break;
V_134 = V_134 -> V_138 ;
}
F_66 ( & V_122 -> V_100 . V_137 , V_136 ) ;
if ( V_76 )
* V_135 = V_134 ;
return V_76 ;
}
static struct V_139 * F_67 ( struct V_82 * V_86 ,
struct V_140 * V_120 ,
struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_141 * V_142 ;
V_76 = F_68 ( V_8 , V_120 ) ;
if ( V_76 )
goto V_26;
V_142 = F_23 ( & V_8 -> V_143 ) ;
if ( ! V_142 ) {
V_76 = - V_73 ;
goto V_26;
}
if ( V_68 ) {
if ( V_68 -> V_9 ) {
V_76 = - V_11 ;
goto V_97;
}
V_142 -> V_144 = 1 ;
}
F_55 ( V_142 ) ;
V_76 = F_69 ( V_8 , V_142 , V_84 , V_120 , V_68 , V_86 ) ;
if ( V_76 )
goto V_145;
return & V_142 -> V_146 ;
V_145:
F_57 ( V_142 ) ;
V_97:
F_27 ( V_142 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static int F_70 ( struct V_139 * V_146 , struct V_147 * V_4 ,
int V_53 , struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_146 -> V_38 ) ;
struct V_141 * V_142 = F_71 ( V_146 ) ;
V_76 = F_72 ( V_8 , V_142 , V_4 , V_53 ) ;
if ( V_76 )
goto V_26;
V_76 = F_73 ( V_142 , V_4 , V_53 , V_68 ) ;
if ( V_76 )
goto V_26;
return 0 ;
V_26:
return V_76 ;
}
static int F_74 ( struct V_139 * V_146 , struct V_147 * V_4 ,
int V_53 , struct V_140 * V_120 )
{
struct V_141 * V_142 = F_71 ( V_146 ) ;
F_75 ( V_142 , V_120 ) ;
F_76 ( V_142 , V_4 , V_53 ) ;
return 0 ;
}
static int F_77 ( struct V_139 * V_146 )
{
struct V_141 * V_142 = F_71 ( V_146 ) ;
F_78 ( V_142 ) ;
F_57 ( V_142 ) ;
F_27 ( V_142 ) ;
return 0 ;
}
static int F_79 ( struct V_141 * V_142 , struct V_148 * V_102 ,
unsigned int V_53 , unsigned int V_104 )
{
int V_107 = V_102 -> V_107 ;
struct V_149 * V_150 = & V_142 -> V_150 ;
if ( F_5 ( V_107 > V_150 -> V_109 ) )
goto V_26;
if ( F_5 ( V_53 & V_151 ) ) {
if ( V_104 < 8 )
goto V_26;
if ( F_80 ( V_102 ) -> V_152 & 0x7 )
goto V_26;
}
if ( F_5 ( ( V_102 -> V_153 & V_154 ) &&
( V_104 > V_150 -> V_155 ) ) )
goto V_26;
return 0 ;
V_26:
return - V_11 ;
}
static void F_81 ( struct V_141 * V_142 , struct V_156 * V_134 ,
struct V_148 * V_102 )
{
V_134 -> V_111 = V_102 -> V_111 ;
V_134 -> V_107 = V_102 -> V_107 ;
V_134 -> V_157 = V_102 -> V_157 ;
V_134 -> V_153 = V_102 -> V_153 ;
if ( F_82 ( V_142 ) == V_158 ||
F_82 ( V_142 ) == V_159 ||
F_82 ( V_142 ) == V_160 ) {
V_134 -> V_134 . V_161 . V_162 = F_83 ( V_102 ) -> V_162 ;
V_134 -> V_134 . V_161 . V_163 = F_83 ( V_102 ) -> V_163 ;
if ( F_82 ( V_142 ) == V_160 )
V_134 -> V_134 . V_161 . V_164 = F_83 ( V_102 ) -> V_164 ;
if ( V_134 -> V_157 == V_165 )
V_134 -> V_166 . V_167 = V_102 -> V_166 . V_167 ;
} else {
switch ( V_134 -> V_157 ) {
case V_168 :
V_134 -> V_166 . V_167 = V_102 -> V_166 . V_167 ;
case V_169 :
case V_170 :
V_134 -> V_134 . V_171 . V_152 = F_84 ( V_102 ) -> V_152 ;
V_134 -> V_134 . V_171 . V_172 = F_84 ( V_102 ) -> V_172 ;
break;
case V_165 :
V_134 -> V_166 . V_167 = V_102 -> V_166 . V_167 ;
break;
case V_173 :
V_134 -> V_166 . V_174 = V_102 -> V_166 . V_174 ;
break;
case V_175 :
case V_176 :
V_134 -> V_134 . V_177 . V_152 =
F_80 ( V_102 ) -> V_152 ;
V_134 -> V_134 . V_177 . V_178 =
F_80 ( V_102 ) -> V_178 ;
V_134 -> V_134 . V_177 . V_179 = F_80 ( V_102 ) -> V_179 ;
V_134 -> V_134 . V_177 . V_172 = F_80 ( V_102 ) -> V_172 ;
break;
case V_180 :
V_134 -> V_166 . V_174 = V_102 -> V_166 . V_174 ;
break;
case V_181 :
V_134 -> V_134 . V_182 . V_183 = F_85 ( V_102 ) -> V_183 ;
V_134 -> V_134 . V_182 . V_184 = F_85 ( V_102 ) -> V_184 ;
V_134 -> V_134 . V_182 . V_185 = F_85 ( V_102 ) -> V_185 ;
break;
default:
break;
}
}
}
static int F_86 ( struct V_141 * V_142 , struct V_148 * V_102 ,
unsigned int V_53 , unsigned int V_104 ,
struct V_186 * V_187 )
{
int V_107 = V_102 -> V_107 ;
struct V_114 * V_113 ;
int V_103 ;
T_1 * V_188 ;
F_81 ( V_142 , & V_187 -> V_134 , V_102 ) ;
if ( F_82 ( V_142 ) == V_158 ||
F_82 ( V_142 ) == V_159 ||
F_82 ( V_142 ) == V_160 )
memcpy ( & V_187 -> V_89 , & F_44 ( F_83 ( V_102 ) -> V_95 ) -> V_89 , sizeof( V_187 -> V_89 ) ) ;
if ( F_5 ( V_102 -> V_153 & V_154 ) ) {
V_188 = V_187 -> V_112 . V_189 ;
V_113 = V_102 -> V_110 ;
for ( V_103 = 0 ; V_103 < V_107 ; V_103 ++ , V_113 ++ ) {
memcpy ( V_188 , ( void * ) ( V_190 ) V_113 -> V_191 ,
V_113 -> V_104 ) ;
V_188 += V_113 -> V_104 ;
}
} else if ( V_53 & V_192 ) {
V_187 -> V_53 = V_53 ;
V_187 -> V_193 = V_194 ;
return 0 ;
} else
memcpy ( V_187 -> V_112 . V_113 , V_102 -> V_110 ,
V_107 * sizeof( struct V_114 ) ) ;
V_187 -> V_195 = ( V_53 & V_151 ) ?
F_80 ( V_102 ) -> V_152 :
F_84 ( V_102 ) -> V_152 ;
V_187 -> V_53 = V_53 ;
V_187 -> V_112 . V_104 = V_104 ;
V_187 -> V_112 . V_115 = V_104 ;
V_187 -> V_112 . V_107 = V_107 ;
V_187 -> V_112 . V_116 = 0 ;
V_187 -> V_112 . V_117 = 0 ;
V_187 -> V_193 = V_194 ;
V_187 -> V_196 = F_87 ( 1 , & V_142 -> V_196 ) ;
return 0 ;
}
static int F_88 ( struct V_141 * V_142 , struct V_148 * V_102 ,
unsigned int V_53 , T_2 V_104 )
{
int V_76 ;
struct V_149 * V_150 = & V_142 -> V_150 ;
struct V_186 * V_197 ;
unsigned long V_136 ;
V_76 = F_79 ( V_142 , V_102 , V_53 , V_104 ) ;
if ( V_76 )
return V_76 ;
F_65 ( & V_142 -> V_150 . V_198 , V_136 ) ;
if ( F_5 ( F_49 ( V_150 -> V_108 ) ) ) {
V_76 = - V_73 ;
goto V_26;
}
V_197 = F_50 ( V_150 -> V_108 ) ;
V_76 = F_86 ( V_142 , V_102 , V_53 , V_104 , V_197 ) ;
if ( F_5 ( V_76 ) )
goto V_26;
F_51 () ;
F_52 ( V_150 -> V_108 ) ;
F_66 ( & V_142 -> V_150 . V_198 , V_136 ) ;
return 0 ;
V_26:
F_66 ( & V_142 -> V_150 . V_198 , V_136 ) ;
return V_76 ;
}
static int F_89 ( struct V_141 * V_142 , struct V_148 * V_134 ,
struct V_148 * * V_135 )
{
int V_76 = 0 ;
unsigned int V_53 ;
unsigned int V_104 = 0 ;
int V_103 ;
int V_199 ;
while ( V_134 ) {
V_53 = F_90 ( V_134 -> V_157 , V_142 ) ;
if ( F_5 ( ! V_53 ) ) {
V_76 = - V_11 ;
* V_135 = V_134 ;
break;
}
if ( F_5 ( ( V_134 -> V_153 & V_154 ) &&
! ( V_53 & V_200 ) ) ) {
V_76 = - V_11 ;
* V_135 = V_134 ;
break;
}
V_104 = 0 ;
for ( V_103 = 0 ; V_103 < V_134 -> V_107 ; V_103 ++ )
V_104 += V_134 -> V_110 [ V_103 ] . V_104 ;
V_76 = F_88 ( V_142 , V_134 , V_53 , V_104 ) ;
if ( V_76 ) {
* V_135 = V_134 ;
break;
}
V_134 = V_134 -> V_138 ;
}
V_199 = ( F_82 ( V_142 ) == V_160 ) ||
( F_91 ( V_142 -> V_150 . V_108 ) > 1 ) ;
F_92 ( & V_142 -> V_201 . V_202 , V_199 ) ;
return V_76 ;
}
static int F_93 ( struct V_139 * V_146 , struct V_148 * V_134 ,
struct V_148 * * V_135 )
{
struct V_141 * V_142 = F_71 ( V_146 ) ;
if ( F_5 ( ! V_142 -> V_203 ) ) {
* V_135 = V_134 ;
return - V_11 ;
}
if ( F_5 ( V_142 -> V_201 . V_193 < V_204 ) ) {
* V_135 = V_134 ;
return - V_11 ;
}
if ( V_142 -> V_144 ) {
F_92 ( & V_142 -> V_201 . V_202 , 0 ) ;
return 0 ;
} else
return F_89 ( V_142 , V_134 , V_135 ) ;
}
static int F_94 ( struct V_139 * V_146 , struct V_101 * V_134 ,
struct V_101 * * V_135 )
{
int V_76 = 0 ;
struct V_141 * V_142 = F_71 ( V_146 ) ;
struct V_99 * V_100 = & V_142 -> V_100 ;
unsigned long V_136 ;
if ( F_5 ( ( F_95 ( V_142 ) < V_205 ) || ! V_142 -> V_203 ) ) {
* V_135 = V_134 ;
V_76 = - V_11 ;
goto V_26;
}
if ( F_5 ( V_142 -> V_122 ) ) {
* V_135 = V_134 ;
V_76 = - V_11 ;
goto V_26;
}
F_65 ( & V_100 -> V_137 , V_136 ) ;
while ( V_134 ) {
V_76 = F_48 ( V_100 , V_134 ) ;
if ( F_5 ( V_76 ) ) {
* V_135 = V_134 ;
break;
}
V_134 = V_134 -> V_138 ;
}
F_66 ( & V_100 -> V_137 , V_136 ) ;
V_26:
return V_76 ;
}
static struct V_206 * F_96 ( struct V_1 * V_2 ,
const struct V_207 * V_4 ,
struct V_67 * V_47 ,
struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_208 * V_209 ;
if ( V_4 -> V_136 )
return F_24 ( - V_11 ) ;
V_76 = F_97 ( V_8 , NULL , V_4 -> V_210 , V_4 -> V_211 , V_68 ) ;
if ( V_76 )
goto V_26;
V_209 = F_23 ( & V_8 -> V_212 ) ;
if ( ! V_209 ) {
V_76 = - V_73 ;
goto V_26;
}
V_76 = F_98 ( V_8 , V_209 , V_4 -> V_210 , V_4 -> V_211 ,
V_47 , V_68 ) ;
if ( V_76 )
goto V_97;
return & V_209 -> V_213 ;
V_97:
F_27 ( V_209 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static int F_99 ( struct V_206 * V_213 )
{
struct V_208 * V_209 = F_100 ( V_213 ) ;
F_27 ( V_209 ) ;
return 0 ;
}
static int F_101 ( struct V_206 * V_213 , int V_210 , struct V_5 * V_68 )
{
int V_76 ;
struct V_208 * V_209 = F_100 ( V_213 ) ;
struct V_7 * V_8 = F_2 ( V_213 -> V_38 ) ;
V_76 = F_97 ( V_8 , V_209 , V_210 , 0 , V_68 ) ;
if ( V_76 )
goto V_26;
V_76 = F_102 ( V_209 , V_210 , V_68 ) ;
if ( V_76 )
goto V_26;
return 0 ;
V_26:
return V_76 ;
}
static int F_103 ( struct V_206 * V_213 , int V_214 , struct V_215 * V_216 )
{
int V_103 ;
struct V_208 * V_209 = F_100 ( V_213 ) ;
struct V_217 * V_210 ;
unsigned long V_136 ;
F_65 ( & V_209 -> V_218 , V_136 ) ;
for ( V_103 = 0 ; V_103 < V_214 ; V_103 ++ ) {
V_210 = F_104 ( V_209 -> V_108 ) ;
if ( ! V_210 )
break;
memcpy ( V_216 ++ , & V_210 -> V_219 , sizeof( * V_216 ) ) ;
F_105 ( V_209 -> V_108 ) ;
}
F_66 ( & V_209 -> V_218 , V_136 ) ;
return V_103 ;
}
static int F_106 ( struct V_206 * V_213 , int V_220 )
{
struct V_208 * V_209 = F_100 ( V_213 ) ;
int V_221 = F_91 ( V_209 -> V_108 ) ;
return ( V_221 > V_220 ) ? V_220 : V_221 ;
}
static int F_107 ( struct V_206 * V_213 , enum V_222 V_136 )
{
struct V_208 * V_209 = F_100 ( V_213 ) ;
unsigned long V_223 ;
int V_42 = 0 ;
F_65 ( & V_209 -> V_218 , V_223 ) ;
if ( V_209 -> V_224 != V_225 )
V_209 -> V_224 = V_136 & V_226 ;
if ( ( V_136 & V_227 ) && ! F_108 ( V_209 -> V_108 ) )
V_42 = 1 ;
F_66 ( & V_209 -> V_218 , V_223 ) ;
return V_42 ;
}
static struct V_228 * F_109 ( struct V_82 * V_86 , int V_185 )
{
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_229 * V_183 ;
int V_76 ;
V_183 = F_23 ( & V_8 -> V_230 ) ;
if ( ! V_183 ) {
V_76 = - V_73 ;
goto V_26;
}
F_55 ( V_183 ) ;
F_42 ( V_84 ) ;
V_76 = F_110 ( V_8 , V_84 , V_185 , V_183 ) ;
if ( V_76 )
goto V_97;
return & V_183 -> V_231 ;
V_97:
F_27 ( V_84 ) ;
F_57 ( V_183 ) ;
F_27 ( V_183 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static struct V_228 * F_111 ( struct V_82 * V_86 ,
T_4 V_232 ,
T_4 V_104 ,
T_4 V_195 ,
int V_185 , struct V_5 * V_68 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_229 * V_183 ;
V_183 = F_23 ( & V_8 -> V_230 ) ;
if ( ! V_183 ) {
V_76 = - V_73 ;
goto V_97;
}
F_55 ( V_183 ) ;
F_42 ( V_84 ) ;
V_76 = F_112 ( V_8 , V_84 , V_232 , V_104 , V_195 ,
V_185 , V_68 , V_183 ) ;
if ( V_76 )
goto V_145;
return & V_183 -> V_231 ;
V_145:
F_27 ( V_84 ) ;
F_57 ( V_183 ) ;
F_27 ( V_183 ) ;
V_97:
return F_24 ( V_76 ) ;
}
static int F_113 ( struct V_228 * V_231 )
{
struct V_229 * V_183 = F_114 ( V_231 ) ;
V_183 -> V_193 = V_233 ;
F_27 ( V_183 -> V_84 ) ;
F_57 ( V_183 ) ;
F_27 ( V_183 ) ;
return 0 ;
}
static struct V_228 * F_115 ( struct V_82 * V_86 ,
enum V_234 V_235 ,
T_2 V_236 )
{
struct V_7 * V_8 = F_2 ( V_86 -> V_38 ) ;
struct V_83 * V_84 = F_32 ( V_86 ) ;
struct V_229 * V_183 ;
int V_76 ;
if ( V_235 != V_237 )
return F_24 ( - V_11 ) ;
V_183 = F_23 ( & V_8 -> V_230 ) ;
if ( ! V_183 ) {
V_76 = - V_73 ;
goto V_26;
}
F_55 ( V_183 ) ;
F_42 ( V_84 ) ;
V_76 = F_116 ( V_8 , V_84 , V_236 , V_183 ) ;
if ( V_76 )
goto V_97;
return & V_183 -> V_231 ;
V_97:
F_27 ( V_84 ) ;
F_57 ( V_183 ) ;
F_27 ( V_183 ) ;
V_26:
return F_24 ( V_76 ) ;
}
static int F_117 ( struct V_228 * V_231 , T_4 V_191 )
{
struct V_229 * V_183 = F_114 ( V_231 ) ;
struct V_238 * V_239 ;
struct V_240 * V_130 ;
if ( F_5 ( V_183 -> V_241 == V_183 -> V_242 ) )
return - V_73 ;
V_239 = V_183 -> V_239 [ V_183 -> V_241 / V_243 ] ;
V_130 = & V_239 -> V_130 [ V_183 -> V_241 % V_243 ] ;
V_130 -> V_191 = V_191 ;
V_130 -> V_244 = V_231 -> V_245 ;
V_183 -> V_241 ++ ;
return 0 ;
}
static int F_118 ( struct V_228 * V_231 , struct V_246 * V_247 ,
int V_248 , unsigned int * V_249 )
{
struct V_229 * V_183 = F_114 ( V_231 ) ;
int V_250 ;
V_183 -> V_241 = 0 ;
V_250 = F_119 ( V_231 , V_247 , V_248 , V_249 , F_117 ) ;
V_183 -> V_251 = V_231 -> V_195 ;
V_183 -> V_195 = V_231 -> V_195 ;
V_183 -> V_104 = V_231 -> V_104 ;
V_183 -> V_252 = F_120 ( V_231 -> V_245 ) ;
V_183 -> V_253 = V_231 -> V_245 - 1 ;
V_183 -> V_254 = V_183 -> V_195 & V_183 -> V_253 ;
return V_250 ;
}
static int F_121 ( struct V_139 * V_146 , union V_40 * V_255 , T_3 V_256 )
{
int V_76 ;
struct V_7 * V_8 = F_2 ( V_146 -> V_38 ) ;
struct V_141 * V_142 = F_71 ( V_146 ) ;
struct V_257 * V_258 ;
V_76 = F_122 ( V_8 , V_255 , & V_258 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_123 ( V_8 , V_142 , V_258 ) ;
F_27 ( V_258 ) ;
return V_76 ;
}
static int F_124 ( struct V_139 * V_146 , union V_40 * V_255 , T_3 V_256 )
{
struct V_7 * V_8 = F_2 ( V_146 -> V_38 ) ;
struct V_141 * V_142 = F_71 ( V_146 ) ;
return F_125 ( V_8 , V_142 , V_255 ) ;
}
static T_5 F_126 ( struct V_38 * V_38 ,
struct V_259 * V_4 , char * V_130 )
{
struct V_7 * V_8 = F_127 ( V_38 , struct V_7 ,
V_58 . V_2 ) ;
return snprintf ( V_130 , 16 , L_6 , F_128 ( V_8 , 1 ) ) ;
}
int F_129 ( struct V_7 * V_8 )
{
int V_76 ;
int V_103 ;
struct V_1 * V_2 = & V_8 -> V_58 ;
F_130 ( V_2 -> V_37 , L_7 , V_260 ) ;
F_130 ( V_2 -> V_59 , L_8 , sizeof( V_2 -> V_59 ) ) ;
V_2 -> V_261 = V_262 ;
V_2 -> V_263 = V_264 ;
V_2 -> V_265 = 1 ;
V_2 -> V_266 = F_131 () ;
V_2 -> V_2 . V_50 = F_132 ( V_8 ) ;
V_2 -> V_267 = 0 ;
F_133 ( ( unsigned char * ) & V_2 -> V_268 ,
V_8 -> V_28 -> V_269 ) ;
V_2 -> V_2 . V_270 = & V_271 ;
V_2 -> V_272 = V_273 ;
V_2 -> V_274 = F_134 ( V_275 )
| F_134 ( V_276 )
| F_134 ( V_277 )
| F_134 ( V_278 )
| F_134 ( V_279 )
| F_134 ( V_280 )
| F_134 ( V_281 )
| F_134 ( V_282 )
| F_134 ( V_283 )
| F_134 ( V_284 )
| F_134 ( V_285 )
| F_134 ( V_286 )
| F_134 ( V_287 )
| F_134 ( V_288 )
| F_134 ( V_289 )
| F_134 ( V_290 )
| F_134 ( V_291 )
| F_134 ( V_292 )
| F_134 ( V_293 )
| F_134 ( V_294 )
| F_134 ( V_295 )
| F_134 ( V_296 )
| F_134 ( V_297 )
| F_134 ( V_298 )
| F_134 ( V_299 )
| F_134 ( V_300 )
| F_134 ( V_301 )
| F_134 ( V_302 )
| F_134 ( V_303 )
| F_134 ( V_304 )
| F_134 ( V_305 )
;
V_2 -> V_306 = F_1 ;
V_2 -> V_307 = F_17 ;
V_2 -> V_308 = F_4 ;
V_2 -> V_309 = F_19 ;
V_2 -> V_310 = F_20 ;
V_2 -> V_311 = F_9 ;
V_2 -> V_312 = F_13 ;
V_2 -> V_313 = F_11 ;
V_2 -> V_314 = F_12 ;
V_2 -> V_315 = F_15 ;
V_2 -> V_316 = F_22 ;
V_2 -> V_317 = F_25 ;
V_2 -> V_318 = V_319 ;
V_2 -> V_320 = F_28 ;
V_2 -> V_321 = F_30 ;
V_2 -> V_322 = F_31 ;
V_2 -> V_323 = F_40 ;
V_2 -> V_324 = F_43 ;
V_2 -> V_325 = F_45 ;
V_2 -> V_326 = F_47 ;
V_2 -> V_327 = F_53 ;
V_2 -> V_328 = F_58 ;
V_2 -> V_329 = F_61 ;
V_2 -> V_330 = F_62 ;
V_2 -> V_331 = F_64 ;
V_2 -> V_332 = F_67 ;
V_2 -> V_333 = F_70 ;
V_2 -> V_334 = F_74 ;
V_2 -> V_335 = F_77 ;
V_2 -> V_336 = F_93 ;
V_2 -> V_337 = F_94 ;
V_2 -> V_338 = F_96 ;
V_2 -> V_339 = F_99 ;
V_2 -> V_340 = F_101 ;
V_2 -> V_341 = F_103 ;
V_2 -> V_342 = F_106 ;
V_2 -> V_343 = F_107 ;
V_2 -> V_344 = F_109 ;
V_2 -> V_345 = F_111 ;
V_2 -> V_346 = F_113 ;
V_2 -> V_347 = F_115 ;
V_2 -> V_348 = F_118 ;
V_2 -> V_349 = F_121 ;
V_2 -> V_350 = F_124 ;
V_2 -> V_351 = V_352 ;
V_2 -> V_353 = V_354 ;
V_8 -> V_355 = F_135 ( L_9 , 0 , 0 ) ;
if ( F_136 ( V_8 -> V_355 ) ) {
F_36 ( L_10 ,
F_137 ( V_8 -> V_355 ) ) ;
return F_137 ( V_8 -> V_355 ) ;
}
V_76 = F_138 ( V_2 , NULL ) ;
if ( V_76 ) {
F_6 ( L_11 , V_76 ) ;
goto V_26;
}
for ( V_103 = 0 ; V_103 < F_139 ( V_356 ) ; ++ V_103 ) {
V_76 = F_140 ( & V_2 -> V_2 , V_356 [ V_103 ] ) ;
if ( V_76 ) {
F_6 ( L_12 ,
V_103 , V_76 ) ;
goto V_97;
}
}
return 0 ;
V_97:
F_141 ( V_2 ) ;
V_26:
F_142 ( V_8 -> V_355 ) ;
return V_76 ;
}
int F_143 ( struct V_7 * V_8 )
{
int V_103 ;
struct V_1 * V_2 = & V_8 -> V_58 ;
for ( V_103 = 0 ; V_103 < F_139 ( V_356 ) ; ++ V_103 )
F_144 ( & V_2 -> V_2 , V_356 [ V_103 ] ) ;
F_141 ( V_2 ) ;
return 0 ;
}
