static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 * V_9 = V_3 ;
int V_10 ;
switch ( V_9 -> V_9 ) {
case V_11 :
case V_12 :
case V_13 :
return - V_14 ;
case V_15 :
V_10 = V_2 -> V_16 -> V_17 ;
break;
case V_18 :
V_10 = 1 ;
break;
case V_19 :
V_10 = V_7 -> V_20 - V_7 -> V_21 ;
break;
case V_22 :
V_10 = V_7 -> V_23 ? 1 : 0 ;
break;
case V_24 :
V_10 = 1 ;
break;
case V_25 :
V_10 = 1 ;
break;
case V_26 :
V_10 = F_2 ( & V_7 -> V_27 [ V_28 ] ) ;
break;
case V_29 :
V_10 = F_2 ( & V_7 -> V_27 [ V_30 ] ) ;
break;
case V_31 :
V_10 = F_2 ( & V_7 -> V_27 [ V_32 ] ) ;
break;
case V_33 :
V_10 = F_2 ( & V_7 -> V_27 [ V_34 ] ) ;
break;
case V_35 :
V_10 = 1 ;
break;
case V_36 :
V_10 = 1 ;
break;
case V_37 :
V_10 = F_3 ( V_2 ) -> V_38 >= 4 ;
break;
case V_39 :
V_10 = 1 ;
break;
case V_40 :
V_10 = 1 ;
break;
case V_41 :
V_10 = F_4 ( V_2 ) ;
break;
case V_42 :
V_10 = F_5 ( V_2 ) ;
break;
case V_43 :
V_10 = F_6 ( V_2 ) ;
break;
case V_44 :
V_10 = 1 ;
break;
case V_45 :
V_10 = F_7 ( V_2 ) ;
break;
case V_46 :
V_10 = 1 ;
break;
case V_47 :
V_10 = F_8 ( V_48 ) ;
break;
case V_49 :
V_10 = 1 ;
break;
case V_50 :
V_10 = 1 ;
break;
case V_51 :
V_10 = 1 ;
break;
case V_52 :
V_10 = F_9 () ;
break;
case V_53 :
V_10 = 1 ;
break;
case V_54 :
V_10 = 1 ;
break;
default:
F_10 ( L_1 , V_9 -> V_9 ) ;
return - V_55 ;
}
if ( F_11 ( V_9 -> V_10 , & V_10 , sizeof( int ) ) ) {
F_12 ( L_2 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_2 * V_9 = V_3 ;
switch ( V_9 -> V_9 ) {
case V_57 :
case V_58 :
case V_59 :
return - V_14 ;
case V_60 :
if ( V_9 -> V_10 > V_7 -> V_20 ||
V_9 -> V_10 < 0 )
return - V_55 ;
V_7 -> V_21 = V_9 -> V_10 ;
break;
default:
F_14 ( L_3 ,
V_9 -> V_9 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
V_7 -> V_61 = F_16 ( 0 , F_17 ( 0 , 0 ) ) ;
if ( ! V_7 -> V_61 ) {
F_12 ( L_4 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_62 = F_3 ( V_2 ) -> V_38 >= 4 ? V_63 : V_64 ;
T_3 V_65 , V_66 = 0 ;
T_4 V_67 ;
int V_68 ;
if ( F_3 ( V_2 ) -> V_38 >= 4 )
F_19 ( V_7 -> V_61 , V_62 + 4 , & V_66 ) ;
F_19 ( V_7 -> V_61 , V_62 , & V_65 ) ;
V_67 = ( ( T_4 ) V_66 << 32 ) | V_65 ;
#ifdef F_20
if ( V_67 &&
F_21 ( V_67 , V_67 + V_69 ) )
return 0 ;
#endif
V_7 -> V_70 . V_71 = L_5 ;
V_7 -> V_70 . V_72 = V_73 ;
V_68 = F_22 ( V_7 -> V_61 -> V_74 ,
& V_7 -> V_70 ,
V_69 , V_69 ,
V_75 ,
0 , V_76 ,
V_7 -> V_61 ) ;
if ( V_68 ) {
F_14 ( L_6 , V_68 ) ;
V_7 -> V_70 . V_77 = 0 ;
return V_68 ;
}
if ( F_3 ( V_2 ) -> V_38 >= 4 )
F_23 ( V_7 -> V_61 , V_62 + 4 ,
F_24 ( V_7 -> V_70 . V_77 ) ) ;
F_23 ( V_7 -> V_61 , V_62 ,
F_25 ( V_7 -> V_70 . V_77 ) ) ;
return 0 ;
}
static void
F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_78 = F_3 ( V_2 ) -> V_38 >= 4 ? V_63 : V_64 ;
T_3 V_79 ;
bool V_80 ;
if ( F_27 ( V_2 ) )
return;
V_7 -> V_81 = false ;
if ( F_28 ( V_2 ) || F_29 ( V_2 ) ) {
F_19 ( V_7 -> V_61 , V_82 , & V_79 ) ;
V_80 = ! ! ( V_79 & V_83 ) ;
} else {
F_19 ( V_7 -> V_61 , V_78 , & V_79 ) ;
V_80 = V_79 & 1 ;
}
if ( V_80 )
return;
if ( F_18 ( V_2 ) )
return;
V_7 -> V_81 = true ;
if ( F_28 ( V_2 ) || F_29 ( V_2 ) ) {
F_23 ( V_7 -> V_61 , V_82 ,
V_79 | V_83 ) ;
} else {
F_19 ( V_7 -> V_61 , V_78 , & V_79 ) ;
F_23 ( V_7 -> V_61 , V_78 , V_79 | 1 ) ;
}
}
static void
F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_78 = F_3 ( V_2 ) -> V_38 >= 4 ? V_63 : V_64 ;
T_3 V_79 ;
if ( V_7 -> V_81 ) {
if ( F_28 ( V_2 ) || F_29 ( V_2 ) ) {
F_19 ( V_7 -> V_61 , V_82 , & V_79 ) ;
V_79 &= ~ V_83 ;
F_23 ( V_7 -> V_61 , V_82 , V_79 ) ;
} else {
F_19 ( V_7 -> V_61 , V_78 , & V_79 ) ;
V_79 &= ~ 1 ;
F_23 ( V_7 -> V_61 , V_78 , V_79 ) ;
}
}
if ( V_7 -> V_70 . V_77 )
F_31 ( & V_7 -> V_70 ) ;
}
static unsigned int F_32 ( void * V_84 , bool V_85 )
{
struct V_1 * V_2 = V_84 ;
F_33 ( V_2 , V_85 ) ;
if ( V_85 )
return V_86 | V_87 |
V_88 | V_89 ;
else
return V_88 | V_89 ;
}
static void F_34 ( struct V_90 * V_16 , enum V_91 V_85 )
{
struct V_1 * V_2 = F_35 ( V_16 ) ;
T_5 V_92 = { . V_93 = V_94 } ;
if ( V_85 == V_95 ) {
F_36 ( L_7 ) ;
V_2 -> V_96 = V_97 ;
F_37 ( V_2 -> V_16 , V_98 ) ;
F_38 ( V_2 ) ;
V_2 -> V_96 = V_99 ;
} else {
F_39 ( L_8 ) ;
V_2 -> V_96 = V_97 ;
F_40 ( V_2 , V_92 ) ;
V_2 -> V_96 = V_100 ;
}
}
static bool F_41 ( struct V_90 * V_16 )
{
struct V_1 * V_2 = F_35 ( V_16 ) ;
return V_2 -> V_101 == 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_68 ;
V_68 = F_43 ( V_2 ) ;
if ( V_68 )
F_44 ( L_9 ) ;
V_68 = F_45 ( V_2 -> V_16 , V_2 , NULL , F_32 ) ;
if ( V_68 && V_68 != - V_14 )
goto V_102;
F_46 () ;
V_68 = F_47 ( V_2 -> V_16 , & V_103 , false ) ;
if ( V_68 )
goto V_104;
V_68 = F_48 ( V_2 ) ;
if ( V_68 )
goto V_105;
F_49 ( V_7 ) ;
V_68 = F_50 ( V_7 ) ;
if ( V_68 )
goto V_106;
F_51 ( V_2 ) ;
V_68 = F_52 ( V_2 ) ;
if ( V_68 )
goto V_107;
F_53 ( V_2 ) ;
V_2 -> V_108 = true ;
if ( F_3 ( V_2 ) -> V_109 == 0 )
return 0 ;
V_68 = F_54 ( V_2 ) ;
if ( V_68 )
goto V_110;
F_55 ( V_7 ) ;
F_56 ( V_111 , V_7 ) ;
F_57 ( V_2 ) ;
return 0 ;
V_110:
F_58 ( & V_2 -> V_112 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( & V_2 -> V_112 ) ;
V_107:
F_62 ( V_2 ) ;
V_106:
F_63 ( V_2 ) ;
V_105:
F_64 ( V_2 -> V_16 ) ;
V_104:
F_45 ( V_2 -> V_16 , NULL , NULL , NULL ) ;
V_102:
return V_68 ;
}
static int F_65 ( struct V_6 * V_7 )
{
struct V_113 * V_114 ;
struct V_90 * V_16 = V_7 -> V_2 -> V_16 ;
bool V_115 ;
int V_68 ;
V_114 = F_66 ( 1 ) ;
if ( ! V_114 )
return - V_116 ;
V_114 -> V_117 [ 0 ] . V_118 = V_7 -> V_119 . V_120 ;
V_114 -> V_117 [ 0 ] . V_121 = V_7 -> V_119 . V_122 ;
V_115 =
V_16 -> V_123 [ V_124 ] . V_72 & V_125 ;
V_68 = F_67 ( V_114 , L_10 , V_115 ) ;
F_68 ( V_114 ) ;
return V_68 ;
}
static int F_65 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_69 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_69 ( struct V_6 * V_7 )
{
return - V_14 ;
}
static int F_69 ( struct V_6 * V_7 )
{
int V_68 = 0 ;
F_44 ( L_11 ) ;
F_70 () ;
if ( F_71 ( & V_126 ) )
V_68 = F_72 ( & V_127 , 0 , V_128 - 1 , 1 ) ;
if ( V_68 == 0 ) {
V_68 = F_73 ( & V_126 ) ;
if ( V_68 == - V_14 )
V_68 = 0 ;
}
F_74 () ;
return V_68 ;
}
static void F_75 ( struct V_6 * V_7 )
{
const struct V_129 * V_130 = & V_7 -> V_130 ;
#define F_76 ( V_71 ) "%s"
#define F_77
#define F_78 ( V_71 ) info->name ? #name "," : ""
#define F_79 ,
F_14 ( L_12
F_80 ( F_76 , F_77 ) ,
V_130 -> V_38 ,
V_7 -> V_2 -> V_16 -> V_17 ,
V_7 -> V_2 -> V_16 -> V_131 ,
F_80 ( F_78 , F_79 ) ) ;
#undef F_76
#undef F_77
#undef F_78
#undef F_79
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_129 * V_130 ;
enum V_132 V_132 ;
V_130 = (struct V_129 * ) & V_7 -> V_130 ;
if ( F_27 ( V_2 ) || F_3 ( V_2 ) -> V_38 == 9 )
F_82 (dev_priv, pipe)
V_130 -> V_133 [ V_132 ] = 2 ;
else
F_82 (dev_priv, pipe)
V_130 -> V_133 [ V_132 ] = 1 ;
if ( V_134 . V_135 ) {
F_44 ( L_13 ) ;
V_130 -> V_109 = 0 ;
} else if ( V_130 -> V_109 > 0 &&
( F_3 ( V_2 ) -> V_38 == 7 || F_3 ( V_2 ) -> V_38 == 8 ) &&
! F_27 ( V_2 ) ) {
T_3 V_136 = F_83 ( V_137 ) ;
T_3 V_138 = F_83 ( V_139 ) ;
if ( V_136 & V_140 ||
V_138 & V_141 ||
( V_7 -> V_142 == V_143 &&
! ( V_138 & V_144 ) ) ) {
F_44 ( L_14 ) ;
V_130 -> V_109 = 0 ;
}
}
if ( F_84 ( V_2 ) ) {
T_3 V_145 , V_146 ;
V_145 = F_83 ( V_147 ) ;
V_146 = V_145 & ( V_148 |
V_149 |
V_150 |
V_151 ) ;
V_130 -> V_152 = 16 - F_85 ( V_146 ) ;
}
}
int F_86 ( struct V_1 * V_2 , unsigned long V_72 )
{
struct V_6 * V_7 ;
struct V_129 * V_130 , * V_153 ;
int V_68 = 0 , V_154 , V_155 ;
T_6 V_156 ;
V_130 = (struct V_129 * ) V_72 ;
if ( V_130 -> V_38 >= 6 && ! F_87 ( V_2 , V_157 ) ) {
F_44 ( L_15 ) ;
F_44 ( L_16 ) ;
return - V_14 ;
}
if ( ! F_87 ( V_2 , V_157 ) && ! V_2 -> V_158 )
return - V_55 ;
V_7 = F_88 ( sizeof( * V_7 ) , V_159 ) ;
if ( V_7 == NULL )
return - V_116 ;
V_2 -> V_8 = V_7 ;
V_7 -> V_2 = V_2 ;
V_153 = (struct V_129 * ) & V_7 -> V_130 ;
memcpy ( V_153 , V_130 , sizeof( V_7 -> V_130 ) ) ;
V_153 -> V_160 = V_2 -> V_16 -> V_17 ;
F_89 ( & V_7 -> V_161 ) ;
F_89 ( & V_7 -> V_162 . V_163 ) ;
F_90 ( & V_7 -> V_164 ) ;
F_89 ( & V_7 -> V_165 . V_163 ) ;
F_89 ( & V_7 -> V_166 . V_167 ) ;
F_89 ( & V_7 -> V_168 ) ;
F_90 ( & V_7 -> V_169 ) ;
F_90 ( & V_7 -> V_170 ) ;
F_91 ( V_2 ) ;
F_92 ( V_2 ) ;
F_75 ( V_7 ) ;
if ( F_93 ( V_2 ) )
F_44 ( L_17
L_18 ) ;
if ( F_15 ( V_2 ) ) {
V_68 = - V_171 ;
goto V_172;
}
V_154 = F_94 ( V_2 ) ? 1 : 0 ;
if ( V_130 -> V_38 < 5 )
V_155 = 512 * 1024 ;
else
V_155 = 2 * 1024 * 1024 ;
V_7 -> V_173 = F_95 ( V_2 -> V_16 , V_154 , V_155 ) ;
if ( ! V_7 -> V_173 ) {
F_12 ( L_19 ) ;
V_68 = - V_171 ;
goto V_174;
}
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
V_68 = F_98 ( V_2 ) ;
if ( V_68 )
goto V_175;
if ( F_87 ( V_2 , V_157 ) ) {
V_68 = F_65 ( V_7 ) ;
if ( V_68 ) {
F_12 ( L_20 ) ;
goto V_176;
}
V_68 = F_69 ( V_7 ) ;
if ( V_68 ) {
F_12 ( L_21 ) ;
goto V_176;
}
}
F_99 ( V_2 -> V_16 ) ;
if ( F_94 ( V_2 ) )
F_100 ( & V_2 -> V_16 -> V_2 , F_101 ( 30 ) ) ;
if ( F_102 ( V_2 ) || F_103 ( V_2 ) )
F_100 ( & V_2 -> V_16 -> V_2 , F_101 ( 32 ) ) ;
V_156 = V_7 -> V_119 . V_122 ;
V_7 -> V_119 . V_177 =
F_104 ( V_7 -> V_119 . V_120 ,
V_156 ) ;
if ( V_7 -> V_119 . V_177 == NULL ) {
V_68 = - V_171 ;
goto V_176;
}
V_7 -> V_119 . V_178 = F_105 ( V_7 -> V_119 . V_120 ,
V_156 ) ;
V_7 -> V_179 = F_106 ( L_22 , 0 ) ;
if ( V_7 -> V_179 == NULL ) {
F_12 ( L_23 ) ;
V_68 = - V_116 ;
goto V_180;
}
V_7 -> V_181 = F_106 ( L_24 , 0 ) ;
if ( V_7 -> V_181 == NULL ) {
F_12 ( L_25 ) ;
V_68 = - V_116 ;
goto V_182;
}
V_7 -> V_162 . V_183 =
F_106 ( L_26 , 0 ) ;
if ( V_7 -> V_162 . V_183 == NULL ) {
F_12 ( L_27 ) ;
V_68 = - V_116 ;
goto V_184;
}
F_107 ( V_7 ) ;
F_108 ( V_2 ) ;
F_26 ( V_2 ) ;
F_109 ( V_2 ) ;
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
if ( ! F_113 ( V_2 ) && ! F_114 ( V_2 ) )
F_115 ( V_2 -> V_16 ) ;
F_81 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_109 ) {
V_68 = F_116 ( V_2 , F_3 ( V_2 ) -> V_109 ) ;
if ( V_68 )
goto V_185;
}
F_117 ( V_7 ) ;
if ( F_87 ( V_2 , V_157 ) ) {
V_68 = F_42 ( V_2 ) ;
if ( V_68 < 0 ) {
F_12 ( L_28 ) ;
goto V_186;
}
}
F_118 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_109 ) {
F_119 ( V_2 ) ;
F_120 () ;
}
if ( F_121 ( V_2 ) )
F_122 ( V_7 ) ;
F_123 ( V_7 ) ;
F_124 ( V_7 ) ;
return 0 ;
V_186:
F_125 ( V_7 ) ;
F_126 ( V_2 ) ;
V_185:
F_127 ( F_128 ( & V_7 -> V_166 . V_187 ) ) ;
F_129 ( & V_7 -> V_166 . V_188 ) ;
if ( V_2 -> V_16 -> V_189 )
F_130 ( V_2 -> V_16 ) ;
F_131 ( V_2 ) ;
F_30 ( V_2 ) ;
F_132 ( & V_7 -> V_190 ) ;
F_133 ( V_7 -> V_162 . V_183 ) ;
V_184:
F_133 ( V_7 -> V_181 ) ;
V_182:
F_133 ( V_7 -> V_179 ) ;
V_180:
F_134 ( V_7 -> V_119 . V_178 ) ;
F_135 ( V_7 -> V_119 . V_177 ) ;
V_176:
F_136 ( V_2 ) ;
V_175:
F_137 ( V_2 ) ;
F_138 ( V_2 -> V_16 , V_7 -> V_173 ) ;
V_174:
F_139 ( V_7 -> V_61 ) ;
V_172:
if ( V_7 -> V_191 )
F_140 ( V_7 -> V_191 ) ;
F_68 ( V_7 ) ;
return V_68 ;
}
int F_141 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_68 ;
F_142 ( V_7 ) ;
V_68 = F_143 ( V_2 ) ;
if ( V_68 ) {
F_12 ( L_29 , V_68 ) ;
return V_68 ;
}
F_125 ( V_7 ) ;
F_144 () ;
F_145 ( V_2 ) ;
F_127 ( F_128 ( & V_7 -> V_166 . V_187 ) ) ;
F_129 ( & V_7 -> V_166 . V_188 ) ;
F_135 ( V_7 -> V_119 . V_177 ) ;
F_134 ( V_7 -> V_119 . V_178 ) ;
F_146 () ;
if ( F_87 ( V_2 , V_157 ) )
F_147 ( V_2 ) ;
F_126 ( V_2 ) ;
if ( F_87 ( V_2 , V_157 ) ) {
F_148 ( V_2 ) ;
if ( V_7 -> V_192 . V_193 && V_7 -> V_192 . V_194 ) {
F_68 ( V_7 -> V_192 . V_193 ) ;
V_7 -> V_192 . V_193 = NULL ;
V_7 -> V_192 . V_194 = 0 ;
}
F_64 ( V_2 -> V_16 ) ;
F_45 ( V_2 -> V_16 , NULL , NULL , NULL ) ;
}
F_149 ( & V_7 -> V_162 . V_195 ) ;
F_150 ( V_2 ) ;
if ( V_2 -> V_16 -> V_189 )
F_130 ( V_2 -> V_16 ) ;
F_151 ( V_2 ) ;
if ( F_87 ( V_2 , V_157 ) ) {
F_152 ( V_7 -> V_179 ) ;
F_58 ( & V_2 -> V_112 ) ;
F_59 ( V_2 ) ;
F_153 ( & V_7 -> V_166 . V_196 ) ;
F_60 ( V_2 ) ;
F_61 ( & V_2 -> V_112 ) ;
F_63 ( V_2 ) ;
}
F_131 ( V_2 ) ;
F_30 ( V_2 ) ;
F_133 ( V_7 -> V_181 ) ;
F_133 ( V_7 -> V_179 ) ;
F_133 ( V_7 -> V_162 . V_183 ) ;
F_132 ( & V_7 -> V_190 ) ;
F_136 ( V_2 ) ;
F_137 ( V_2 ) ;
if ( V_7 -> V_173 != NULL )
F_138 ( V_2 -> V_16 , V_7 -> V_173 ) ;
if ( V_7 -> V_191 )
F_140 ( V_7 -> V_191 ) ;
F_139 ( V_7 -> V_61 ) ;
F_68 ( V_7 ) ;
return 0 ;
}
int F_154 ( struct V_1 * V_2 , struct V_4 * V_197 )
{
int V_68 ;
V_68 = F_155 ( V_2 , V_197 ) ;
if ( V_68 )
return V_68 ;
return 0 ;
}
void F_156 ( struct V_1 * V_2 )
{
F_157 ( V_2 ) ;
F_158 () ;
}
void F_159 ( struct V_1 * V_2 , struct V_4 * V_197 )
{
F_58 ( & V_2 -> V_112 ) ;
F_160 ( V_2 , V_197 ) ;
F_161 ( V_2 , V_197 ) ;
F_61 ( & V_2 -> V_112 ) ;
if ( F_87 ( V_2 , V_157 ) )
F_162 ( V_2 , V_197 ) ;
}
void F_163 ( struct V_1 * V_2 , struct V_4 * V_197 )
{
struct V_198 * V_5 = V_197 -> V_199 ;
if ( V_5 && V_5 -> V_200 )
V_5 -> V_200 = NULL ;
F_68 ( V_5 ) ;
}
static int
F_164 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_197 )
{
return - V_14 ;
}
int F_165 ( struct V_1 * V_2 )
{
return 1 ;
}
