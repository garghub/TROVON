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
V_10 = 1 ;
break;
case V_34 :
V_10 = 1 ;
break;
case V_35 :
V_10 = F_3 ( V_2 ) -> V_36 >= 4 ;
break;
case V_37 :
V_10 = 1 ;
break;
case V_38 :
V_10 = 1 ;
break;
case V_39 :
V_10 = F_4 ( V_2 ) ;
break;
case V_40 :
V_10 = F_5 ( V_2 ) ;
break;
case V_41 :
V_10 = F_6 ( V_2 ) ;
break;
case V_42 :
V_10 = 1 ;
break;
case V_43 :
V_10 = F_7 ( V_2 ) ;
break;
case V_44 :
V_10 = 1 ;
break;
case V_45 :
V_10 = F_8 ( V_46 ) ;
break;
case V_47 :
V_10 = 1 ;
break;
case V_48 :
V_10 = 1 ;
break;
case V_49 :
V_10 = 1 ;
break;
case V_50 :
V_10 = F_9 () ;
break;
case V_51 :
V_10 = 1 ;
break;
default:
F_10 ( L_1 , V_9 -> V_9 ) ;
return - V_52 ;
}
if ( F_11 ( V_9 -> V_10 , & V_10 , sizeof( int ) ) ) {
F_12 ( L_2 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_2 * V_9 = V_3 ;
switch ( V_9 -> V_9 ) {
case V_54 :
case V_55 :
case V_56 :
return - V_14 ;
case V_57 :
if ( V_9 -> V_10 > V_7 -> V_20 ||
V_9 -> V_10 < 0 )
return - V_52 ;
V_7 -> V_21 = V_9 -> V_10 ;
break;
default:
F_14 ( L_3 ,
V_9 -> V_9 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
V_7 -> V_58 = F_16 ( 0 , F_17 ( 0 , 0 ) ) ;
if ( ! V_7 -> V_58 ) {
F_12 ( L_4 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_59 = F_3 ( V_2 ) -> V_36 >= 4 ? V_60 : V_61 ;
T_3 V_62 , V_63 = 0 ;
T_4 V_64 ;
int V_65 ;
if ( F_3 ( V_2 ) -> V_36 >= 4 )
F_19 ( V_7 -> V_58 , V_59 + 4 , & V_63 ) ;
F_19 ( V_7 -> V_58 , V_59 , & V_62 ) ;
V_64 = ( ( T_4 ) V_63 << 32 ) | V_62 ;
#ifdef F_20
if ( V_64 &&
F_21 ( V_64 , V_64 + V_66 ) )
return 0 ;
#endif
V_7 -> V_67 . V_68 = L_5 ;
V_7 -> V_67 . V_69 = V_70 ;
V_65 = F_22 ( V_7 -> V_58 -> V_71 ,
& V_7 -> V_67 ,
V_66 , V_66 ,
V_72 ,
0 , V_73 ,
V_7 -> V_58 ) ;
if ( V_65 ) {
F_14 ( L_6 , V_65 ) ;
V_7 -> V_67 . V_74 = 0 ;
return V_65 ;
}
if ( F_3 ( V_2 ) -> V_36 >= 4 )
F_23 ( V_7 -> V_58 , V_59 + 4 ,
F_24 ( V_7 -> V_67 . V_74 ) ) ;
F_23 ( V_7 -> V_58 , V_59 ,
F_25 ( V_7 -> V_67 . V_74 ) ) ;
return 0 ;
}
static void
F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_75 = F_3 ( V_2 ) -> V_36 >= 4 ? V_60 : V_61 ;
T_3 V_76 ;
bool V_77 ;
if ( F_27 ( V_2 ) )
return;
V_7 -> V_78 = false ;
if ( F_28 ( V_2 ) || F_29 ( V_2 ) ) {
F_19 ( V_7 -> V_58 , V_79 , & V_76 ) ;
V_77 = ! ! ( V_76 & V_80 ) ;
} else {
F_19 ( V_7 -> V_58 , V_75 , & V_76 ) ;
V_77 = V_76 & 1 ;
}
if ( V_77 )
return;
if ( F_18 ( V_2 ) )
return;
V_7 -> V_78 = true ;
if ( F_28 ( V_2 ) || F_29 ( V_2 ) ) {
F_23 ( V_7 -> V_58 , V_79 ,
V_76 | V_80 ) ;
} else {
F_19 ( V_7 -> V_58 , V_75 , & V_76 ) ;
F_23 ( V_7 -> V_58 , V_75 , V_76 | 1 ) ;
}
}
static void
F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_75 = F_3 ( V_2 ) -> V_36 >= 4 ? V_60 : V_61 ;
T_3 V_76 ;
if ( V_7 -> V_78 ) {
if ( F_28 ( V_2 ) || F_29 ( V_2 ) ) {
F_19 ( V_7 -> V_58 , V_79 , & V_76 ) ;
V_76 &= ~ V_80 ;
F_23 ( V_7 -> V_58 , V_79 , V_76 ) ;
} else {
F_19 ( V_7 -> V_58 , V_75 , & V_76 ) ;
V_76 &= ~ 1 ;
F_23 ( V_7 -> V_58 , V_75 , V_76 ) ;
}
}
if ( V_7 -> V_67 . V_74 )
F_31 ( & V_7 -> V_67 ) ;
}
static unsigned int F_32 ( void * V_81 , bool V_82 )
{
struct V_1 * V_2 = V_81 ;
F_33 ( V_2 , V_82 ) ;
if ( V_82 )
return V_83 | V_84 |
V_85 | V_86 ;
else
return V_85 | V_86 ;
}
static void F_34 ( struct V_87 * V_16 , enum V_88 V_82 )
{
struct V_1 * V_2 = F_35 ( V_16 ) ;
T_5 V_89 = { . V_90 = V_91 } ;
if ( V_82 == V_92 ) {
F_36 ( L_7 ) ;
V_2 -> V_93 = V_94 ;
F_37 ( V_2 -> V_16 , V_95 ) ;
F_38 ( V_2 ) ;
V_2 -> V_93 = V_96 ;
} else {
F_39 ( L_8 ) ;
V_2 -> V_93 = V_94 ;
F_40 ( V_2 , V_89 ) ;
V_2 -> V_93 = V_97 ;
}
}
static bool F_41 ( struct V_87 * V_16 )
{
struct V_1 * V_2 = F_35 ( V_16 ) ;
return V_2 -> V_98 == 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_65 ;
V_65 = F_43 ( V_2 ) ;
if ( V_65 )
F_44 ( L_9 ) ;
V_65 = F_45 ( V_2 -> V_16 , V_2 , NULL , F_32 ) ;
if ( V_65 && V_65 != - V_14 )
goto V_99;
F_46 () ;
V_65 = F_47 ( V_2 -> V_16 , & V_100 , false ) ;
if ( V_65 )
goto V_101;
V_65 = F_48 ( V_2 ) ;
if ( V_65 )
goto V_102;
F_49 ( V_7 ) ;
V_65 = F_50 ( V_7 ) ;
if ( V_65 )
goto V_103;
F_51 ( V_2 ) ;
V_65 = F_52 ( V_2 ) ;
if ( V_65 )
goto V_104;
F_53 ( V_2 ) ;
V_2 -> V_105 = true ;
if ( F_3 ( V_2 ) -> V_106 == 0 )
return 0 ;
V_65 = F_54 ( V_2 ) ;
if ( V_65 )
goto V_107;
F_55 ( V_7 ) ;
F_56 ( V_108 , V_7 ) ;
F_57 ( V_2 ) ;
return 0 ;
V_107:
F_58 ( & V_2 -> V_109 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( & V_2 -> V_109 ) ;
V_104:
F_62 ( V_2 ) ;
V_103:
F_63 ( V_2 ) ;
V_102:
F_64 ( V_2 -> V_16 ) ;
V_101:
F_45 ( V_2 -> V_16 , NULL , NULL , NULL ) ;
V_99:
return V_65 ;
}
static int F_65 ( struct V_6 * V_7 )
{
struct V_110 * V_111 ;
struct V_87 * V_16 = V_7 -> V_2 -> V_16 ;
bool V_112 ;
int V_65 ;
V_111 = F_66 ( 1 ) ;
if ( ! V_111 )
return - V_113 ;
V_111 -> V_114 [ 0 ] . V_115 = V_7 -> V_116 . V_117 ;
V_111 -> V_114 [ 0 ] . V_118 = V_7 -> V_116 . V_119 ;
V_112 =
V_16 -> V_120 [ V_121 ] . V_69 & V_122 ;
V_65 = F_67 ( V_111 , L_10 , V_112 ) ;
F_68 ( V_111 ) ;
return V_65 ;
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
int V_65 = 0 ;
F_44 ( L_11 ) ;
F_70 () ;
if ( F_71 ( & V_123 ) )
V_65 = F_72 ( & V_124 , 0 , V_125 - 1 , 1 ) ;
if ( V_65 == 0 ) {
V_65 = F_73 ( & V_123 ) ;
if ( V_65 == - V_14 )
V_65 = 0 ;
}
F_74 () ;
return V_65 ;
}
static void F_75 ( struct V_6 * V_7 )
{
const struct V_126 * V_127 = & V_7 -> V_127 ;
#define F_76 ( V_68 ) "%s"
#define F_77
#define F_78 ( V_68 ) info->name ? #name "," : ""
#define F_79 ,
F_14 ( L_12
F_80 ( F_76 , F_77 ) ,
V_127 -> V_36 ,
V_7 -> V_2 -> V_16 -> V_17 ,
V_7 -> V_2 -> V_16 -> V_128 ,
F_80 ( F_78 , F_79 ) ) ;
#undef F_76
#undef F_77
#undef F_78
#undef F_79
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_126 * V_127 ;
enum V_129 V_129 ;
V_127 = (struct V_126 * ) & V_7 -> V_127 ;
if ( F_27 ( V_2 ) || F_3 ( V_2 ) -> V_36 == 9 )
F_82 (dev_priv, pipe)
V_127 -> V_130 [ V_129 ] = 2 ;
else
F_82 (dev_priv, pipe)
V_127 -> V_130 [ V_129 ] = 1 ;
if ( V_131 . V_132 ) {
F_44 ( L_13 ) ;
V_127 -> V_106 = 0 ;
} else if ( V_127 -> V_106 > 0 &&
( F_3 ( V_2 ) -> V_36 == 7 || F_3 ( V_2 ) -> V_36 == 8 ) &&
! F_27 ( V_2 ) ) {
T_3 V_133 = F_83 ( V_134 ) ;
T_3 V_135 = F_83 ( V_136 ) ;
if ( V_133 & V_137 ||
V_135 & V_138 ||
( V_7 -> V_139 == V_140 &&
! ( V_135 & V_141 ) ) ) {
F_44 ( L_14 ) ;
V_127 -> V_106 = 0 ;
}
}
}
int F_84 ( struct V_1 * V_2 , unsigned long V_69 )
{
struct V_6 * V_7 ;
struct V_126 * V_127 , * V_142 ;
int V_65 = 0 , V_143 , V_144 ;
T_6 V_145 ;
V_127 = (struct V_126 * ) V_69 ;
if ( V_127 -> V_36 >= 6 && ! F_85 ( V_2 , V_146 ) ) {
F_44 ( L_15 ) ;
F_44 ( L_16 ) ;
return - V_14 ;
}
if ( ! F_85 ( V_2 , V_146 ) && ! V_2 -> V_147 )
return - V_52 ;
V_7 = F_86 ( sizeof( * V_7 ) , V_148 ) ;
if ( V_7 == NULL )
return - V_113 ;
V_2 -> V_8 = V_7 ;
V_7 -> V_2 = V_2 ;
V_142 = (struct V_126 * ) & V_7 -> V_127 ;
memcpy ( V_142 , V_127 , sizeof( V_7 -> V_127 ) ) ;
V_142 -> V_149 = V_2 -> V_16 -> V_17 ;
F_87 ( & V_7 -> V_150 ) ;
F_87 ( & V_7 -> V_151 . V_152 ) ;
F_88 ( & V_7 -> V_153 ) ;
F_87 ( & V_7 -> V_154 . V_152 ) ;
F_87 ( & V_7 -> V_155 . V_156 ) ;
F_87 ( & V_7 -> V_157 ) ;
F_88 ( & V_7 -> V_158 ) ;
F_88 ( & V_7 -> V_159 ) ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
F_75 ( V_7 ) ;
if ( F_91 ( V_2 ) )
F_44 ( L_17
L_18 ) ;
if ( F_15 ( V_2 ) ) {
V_65 = - V_160 ;
goto V_161;
}
V_143 = F_92 ( V_2 ) ? 1 : 0 ;
if ( V_127 -> V_36 < 5 )
V_144 = 512 * 1024 ;
else
V_144 = 2 * 1024 * 1024 ;
V_7 -> V_162 = F_93 ( V_2 -> V_16 , V_143 , V_144 ) ;
if ( ! V_7 -> V_162 ) {
F_12 ( L_19 ) ;
V_65 = - V_160 ;
goto V_163;
}
F_94 ( V_2 ) ;
F_95 ( V_2 ) ;
V_65 = F_96 ( V_2 ) ;
if ( V_65 )
goto V_164;
if ( F_85 ( V_2 , V_146 ) ) {
V_65 = F_65 ( V_7 ) ;
if ( V_65 ) {
F_12 ( L_20 ) ;
goto V_165;
}
V_65 = F_69 ( V_7 ) ;
if ( V_65 ) {
F_12 ( L_21 ) ;
goto V_165;
}
}
F_97 ( V_2 -> V_16 ) ;
if ( F_92 ( V_2 ) )
F_98 ( & V_2 -> V_16 -> V_2 , F_99 ( 30 ) ) ;
if ( F_100 ( V_2 ) || F_101 ( V_2 ) )
F_98 ( & V_2 -> V_16 -> V_2 , F_99 ( 32 ) ) ;
V_145 = V_7 -> V_116 . V_119 ;
V_7 -> V_116 . V_166 =
F_102 ( V_7 -> V_116 . V_117 ,
V_145 ) ;
if ( V_7 -> V_116 . V_166 == NULL ) {
V_65 = - V_160 ;
goto V_165;
}
V_7 -> V_116 . V_167 = F_103 ( V_7 -> V_116 . V_117 ,
V_145 ) ;
V_7 -> V_168 = F_104 ( L_22 , 0 ) ;
if ( V_7 -> V_168 == NULL ) {
F_12 ( L_23 ) ;
V_65 = - V_113 ;
goto V_169;
}
V_7 -> V_170 = F_104 ( L_24 , 0 ) ;
if ( V_7 -> V_170 == NULL ) {
F_12 ( L_25 ) ;
V_65 = - V_113 ;
goto V_171;
}
F_105 ( V_7 ) ;
F_106 ( V_2 ) ;
F_26 ( V_2 ) ;
F_107 ( V_2 ) ;
F_108 ( V_2 ) ;
F_109 ( V_2 ) ;
F_110 ( V_2 ) ;
if ( ! F_111 ( V_2 ) && ! F_112 ( V_2 ) )
F_113 ( V_2 -> V_16 ) ;
F_81 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_106 ) {
V_65 = F_114 ( V_2 , F_3 ( V_2 ) -> V_106 ) ;
if ( V_65 )
goto V_172;
}
F_115 ( V_7 ) ;
if ( F_85 ( V_2 , V_146 ) ) {
V_65 = F_42 ( V_2 ) ;
if ( V_65 < 0 ) {
F_12 ( L_26 ) ;
goto V_173;
}
}
F_116 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_106 ) {
F_117 ( V_2 ) ;
F_118 () ;
}
if ( F_119 ( V_2 ) )
F_120 ( V_7 ) ;
F_121 ( V_7 ) ;
return 0 ;
V_173:
F_122 ( V_7 ) ;
F_123 ( V_2 ) ;
V_172:
F_124 ( F_125 ( & V_7 -> V_155 . V_174 ) ) ;
F_126 ( & V_7 -> V_155 . V_175 ) ;
if ( V_2 -> V_16 -> V_176 )
F_127 ( V_2 -> V_16 ) ;
F_128 ( V_2 ) ;
F_30 ( V_2 ) ;
F_129 ( & V_7 -> V_177 ) ;
F_130 ( V_7 -> V_170 ) ;
V_171:
F_130 ( V_7 -> V_168 ) ;
V_169:
F_131 ( V_7 -> V_116 . V_167 ) ;
F_132 ( V_7 -> V_116 . V_166 ) ;
V_165:
F_133 ( V_2 ) ;
V_164:
F_134 ( V_2 ) ;
F_135 ( V_2 -> V_16 , V_7 -> V_162 ) ;
V_163:
F_136 ( V_7 -> V_58 ) ;
V_161:
if ( V_7 -> V_178 )
F_137 ( V_7 -> V_178 ) ;
F_68 ( V_7 ) ;
return V_65 ;
}
int F_138 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_65 ;
V_65 = F_139 ( V_2 ) ;
if ( V_65 ) {
F_12 ( L_27 , V_65 ) ;
return V_65 ;
}
F_122 ( V_7 ) ;
F_140 () ;
F_141 ( V_2 ) ;
F_124 ( F_125 ( & V_7 -> V_155 . V_174 ) ) ;
F_126 ( & V_7 -> V_155 . V_175 ) ;
F_132 ( V_7 -> V_116 . V_166 ) ;
F_131 ( V_7 -> V_116 . V_167 ) ;
F_142 () ;
if ( F_85 ( V_2 , V_146 ) )
F_143 ( V_2 ) ;
F_123 ( V_2 ) ;
if ( F_85 ( V_2 , V_146 ) ) {
F_144 ( V_2 ) ;
if ( V_7 -> V_179 . V_180 && V_7 -> V_179 . V_181 ) {
F_68 ( V_7 -> V_179 . V_180 ) ;
V_7 -> V_179 . V_180 = NULL ;
V_7 -> V_179 . V_181 = 0 ;
}
F_64 ( V_2 -> V_16 ) ;
F_45 ( V_2 -> V_16 , NULL , NULL , NULL ) ;
}
F_145 ( & V_7 -> V_151 . V_182 ) ;
F_146 ( & V_7 -> V_151 . V_183 ) ;
F_147 ( V_2 ) ;
if ( V_2 -> V_16 -> V_176 )
F_127 ( V_2 -> V_16 ) ;
F_148 ( V_2 ) ;
if ( F_85 ( V_2 , V_146 ) ) {
F_149 ( V_7 -> V_168 ) ;
F_58 ( & V_2 -> V_109 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( & V_2 -> V_109 ) ;
F_63 ( V_2 ) ;
}
F_128 ( V_2 ) ;
F_30 ( V_2 ) ;
F_130 ( V_7 -> V_170 ) ;
F_130 ( V_7 -> V_168 ) ;
F_129 ( & V_7 -> V_177 ) ;
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
if ( V_7 -> V_162 != NULL )
F_135 ( V_2 -> V_16 , V_7 -> V_162 ) ;
if ( V_7 -> V_178 )
F_137 ( V_7 -> V_178 ) ;
F_136 ( V_7 -> V_58 ) ;
F_68 ( V_7 ) ;
return 0 ;
}
int F_150 ( struct V_1 * V_2 , struct V_4 * V_184 )
{
int V_65 ;
V_65 = F_151 ( V_2 , V_184 ) ;
if ( V_65 )
return V_65 ;
return 0 ;
}
void F_152 ( struct V_1 * V_2 )
{
F_153 ( V_2 ) ;
F_154 () ;
}
void F_155 ( struct V_1 * V_2 , struct V_4 * V_184 )
{
F_58 ( & V_2 -> V_109 ) ;
F_156 ( V_2 , V_184 ) ;
F_157 ( V_2 , V_184 ) ;
F_61 ( & V_2 -> V_109 ) ;
if ( F_85 ( V_2 , V_146 ) )
F_158 ( V_2 , V_184 ) ;
}
void F_159 ( struct V_1 * V_2 , struct V_4 * V_184 )
{
struct V_185 * V_5 = V_184 -> V_186 ;
if ( V_5 && V_5 -> V_187 )
V_5 -> V_187 = NULL ;
F_68 ( V_5 ) ;
}
int F_160 ( struct V_1 * V_2 )
{
return 1 ;
}
