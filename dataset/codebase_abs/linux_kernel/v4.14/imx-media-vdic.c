static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
if ( V_2 -> V_4 )
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
if ( V_2 -> V_5 )
F_2 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
if ( ! F_3 ( V_2 -> V_6 ) )
F_4 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_7 , V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_6 ;
V_2 -> V_12 = V_2 -> V_13 -> V_12 [ V_2 -> V_14 ] ;
V_6 = F_6 ( V_2 -> V_12 ) ;
if ( F_7 ( V_6 ) ) {
F_8 ( & V_2 -> V_15 , L_1 ) ;
V_7 = F_9 ( V_6 ) ;
goto V_16;
}
V_2 -> V_6 = V_6 ;
if ( ! V_2 -> V_17 ) {
V_10 = F_10 ( V_2 -> V_12 , V_18 ) ;
if ( F_7 ( V_10 ) ) {
V_8 = V_18 ;
V_7 = F_9 ( V_10 ) ;
goto V_19;
}
V_2 -> V_3 = V_10 ;
V_10 = F_10 ( V_2 -> V_12 , V_20 ) ;
if ( F_7 ( V_10 ) ) {
V_8 = V_20 ;
V_7 = F_9 ( V_10 ) ;
goto V_19;
}
V_2 -> V_4 = V_10 ;
V_10 = F_10 ( V_2 -> V_12 , V_21 ) ;
if ( F_7 ( V_2 -> V_5 ) ) {
V_8 = V_21 ;
V_7 = F_9 ( V_10 ) ;
goto V_19;
}
V_2 -> V_5 = V_10 ;
}
return 0 ;
V_19:
F_8 ( & V_2 -> V_15 , L_2 , V_8 ) ;
V_16:
F_1 ( V_2 ) ;
return V_7 ;
}
static void T_1 F_11 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
T_2 V_24 , V_25 , V_26 ;
struct V_22 * V_27 ;
struct V_28 * V_29 , * V_30 ;
T_3 V_31 = V_2 -> V_32 ;
T_3 V_33 = V_2 -> V_34 ;
V_2 -> V_35 = V_2 -> V_36 ;
V_2 -> V_36 = V_23 ;
V_27 = V_2 -> V_35 ? V_2 -> V_35 : V_23 ;
V_30 = & V_27 -> V_37 . V_38 ;
V_29 = & V_23 -> V_37 . V_38 ;
switch ( V_2 -> V_39 ) {
case V_40 :
V_24 = F_12 ( V_30 , 0 ) ;
V_25 = F_12 ( V_29 , 0 ) + V_31 ;
V_26 = F_12 ( V_29 , 0 ) ;
break;
case V_41 :
V_24 = F_12 ( V_30 , 0 ) + V_31 ;
V_25 = F_12 ( V_29 , 0 ) ;
V_26 = F_12 ( V_29 , 0 ) + V_31 ;
break;
case V_42 :
V_24 = F_12 ( V_30 , 0 ) + V_33 ;
V_25 = F_12 ( V_29 , 0 ) ;
V_26 = F_12 ( V_29 , 0 ) + V_33 ;
break;
default:
V_24 = F_12 ( V_30 , 0 ) ;
V_25 = F_12 ( V_29 , 0 ) + V_33 ;
V_26 = F_12 ( V_29 , 0 ) ;
break;
}
F_13 ( V_2 -> V_3 , 0 , V_24 ) ;
F_13 ( V_2 -> V_4 , 0 , V_25 ) ;
F_13 ( V_2 -> V_5 , 0 , V_26 ) ;
F_14 ( V_2 -> V_3 , 0 ) ;
F_14 ( V_2 -> V_4 , 0 ) ;
F_14 ( V_2 -> V_5 , 0 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_9 * V_43 ,
T_2 V_44 , T_2 V_45 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
unsigned int V_48 ;
struct V_49 V_50 ;
int V_7 ;
F_16 ( V_43 ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_51 = V_47 -> V_52 . V_52 . V_51 ;
V_50 . V_51 . V_53 /= 2 ;
V_50 . V_54 . V_55 = V_50 . V_51 . V_55 ;
V_50 . V_54 . V_53 = V_50 . V_51 . V_53 ;
V_50 . V_44 = V_44 ;
V_50 . V_45 = V_45 ;
V_7 = F_17 ( V_43 , & V_50 ) ;
if ( V_7 )
return V_7 ;
V_48 = ( V_50 . V_51 . V_55 & 0xf ) ? 8 : 16 ;
F_18 ( V_43 , V_48 ) ;
F_19 ( V_43 , 1 ) ;
F_20 ( V_43 , false ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_12 , V_56 ,
V_57 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
}
static void F_24 ( struct V_1 * V_2 )
{
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_12 , V_56 ,
V_57 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_58 * V_59 ;
const struct V_60 * V_61 ;
int V_62 , V_7 ;
V_59 = & V_2 -> V_63 [ V_64 ] ;
V_61 = V_2 -> V_65 [ V_64 ] ;
V_62 = ( V_59 -> V_55 * V_61 -> V_66 * V_59 -> V_53 ) >> 3 ;
V_2 -> V_32 = V_62 / 2 ;
V_2 -> V_34 = V_61 -> V_67 ?
V_59 -> V_55 : ( V_59 -> V_55 * V_61 -> V_66 ) >> 3 ;
V_2 -> V_35 = NULL ;
V_2 -> V_36 = NULL ;
V_2 -> V_39 = V_59 -> V_68 ;
V_7 = F_15 ( V_2 , V_2 -> V_3 , 0 , 0 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_15 ( V_2 , V_2 -> V_4 , 0 , 0 ) ;
if ( V_7 )
return V_7 ;
return F_15 ( V_2 , V_2 -> V_5 , 0 , 0 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_3 ) ;
F_29 ( V_2 -> V_4 ) ;
F_29 ( V_2 -> V_5 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 -> V_3 ) ;
F_31 ( V_2 -> V_4 ) ;
F_31 ( V_2 -> V_5 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_58 * V_59 ;
int V_7 ;
V_59 = & V_2 -> V_63 [ V_2 -> V_69 ] ;
V_2 -> V_70 = V_2 -> V_17 ? & V_71 : & V_72 ;
V_7 = F_5 ( V_2 ) ;
if ( V_7 )
return V_7 ;
F_34 ( V_2 -> V_6 , V_73 ,
V_59 -> V_55 , V_59 -> V_53 ) ;
F_35 ( V_2 -> V_6 , V_74 , V_59 -> V_68 ) ;
F_36 ( V_2 -> V_6 , V_2 -> V_75 ) ;
V_7 = V_2 -> V_70 -> V_76 ( V_2 ) ;
if ( V_7 )
goto V_77;
F_37 ( V_2 -> V_6 ) ;
V_2 -> V_70 -> V_78 ( V_2 ) ;
return 0 ;
V_77:
F_1 ( V_2 ) ;
return V_7 ;
}
static void F_38 ( struct V_1 * V_2 )
{
V_2 -> V_70 -> V_79 ( V_2 ) ;
F_39 ( V_2 -> V_6 ) ;
V_2 -> V_70 -> V_80 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static int F_40 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_41 ( V_82 -> V_83 ,
struct V_1 , V_84 ) ;
enum V_85 V_75 ;
int V_7 = 0 ;
F_42 ( & V_2 -> V_86 ) ;
switch ( V_82 -> V_87 ) {
case V_88 :
V_75 = V_82 -> V_89 ;
if ( V_75 != V_2 -> V_75 ) {
if ( V_2 -> V_90 > 0 ) {
V_7 = - V_91 ;
goto V_16;
}
V_2 -> V_75 = V_75 ;
}
break;
default:
F_8 ( & V_2 -> V_15 , L_3 ) ;
V_7 = - V_92 ;
}
V_16:
F_43 ( & V_2 -> V_86 ) ;
return V_7 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = & V_2 -> V_84 ;
int V_7 ;
F_45 ( V_94 , 1 ) ;
F_46 ( V_94 , & V_95 ,
V_88 ,
V_96 , 0 , V_96 ,
V_97 ) ;
V_2 -> V_15 . V_98 = V_94 ;
if ( V_94 -> error ) {
V_7 = V_94 -> error ;
goto V_99;
}
F_47 ( V_94 ) ;
return 0 ;
V_99:
F_48 ( V_94 ) ;
return V_7 ;
}
static int F_49 ( struct V_100 * V_15 , int V_101 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_100 * V_102 = NULL ;
int V_7 = 0 ;
F_42 ( & V_2 -> V_86 ) ;
if ( ! V_2 -> V_103 || ! V_2 -> V_104 ) {
V_7 = - V_105 ;
goto V_16;
}
if ( V_2 -> V_17 )
V_102 = F_51 ( V_2 -> V_103 ) ;
if ( V_2 -> V_90 != ! V_101 )
goto V_106;
F_52 ( V_2 -> V_107 , L_4 , V_101 ? L_5 : L_6 ) ;
if ( V_101 )
V_7 = F_33 ( V_2 ) ;
else
F_38 ( V_2 ) ;
if ( V_7 )
goto V_16;
if ( V_102 ) {
V_7 = F_53 ( V_102 , V_108 , V_109 , V_101 ) ;
V_7 = ( V_7 && V_7 != - V_110 ) ? V_7 : 0 ;
if ( V_7 ) {
if ( V_101 )
F_38 ( V_2 ) ;
goto V_16;
}
}
V_106:
V_2 -> V_90 += V_101 ? 1 : - 1 ;
if ( V_2 -> V_90 < 0 )
V_2 -> V_90 = 0 ;
V_16:
F_43 ( & V_2 -> V_86 ) ;
return V_7 ;
}
static struct V_58 *
F_54 ( struct V_1 * V_2 , struct V_111 * V_112 ,
unsigned int V_113 , enum V_114 V_115 )
{
if ( V_115 == V_116 )
return F_55 ( & V_2 -> V_15 , V_112 , V_113 ) ;
else
return & V_2 -> V_63 [ V_113 ] ;
}
static int F_56 ( struct V_100 * V_15 ,
struct V_111 * V_112 ,
struct V_117 * V_118 )
{
if ( V_118 -> V_113 >= V_119 )
return - V_92 ;
return F_57 ( & V_118 -> V_118 , V_118 -> V_120 , V_121 ) ;
}
static int F_58 ( struct V_100 * V_15 ,
struct V_111 * V_112 ,
struct V_122 * V_123 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_58 * V_52 ;
int V_7 = 0 ;
if ( V_123 -> V_113 >= V_119 )
return - V_92 ;
F_42 ( & V_2 -> V_86 ) ;
V_52 = F_54 ( V_2 , V_112 , V_123 -> V_113 , V_123 -> V_115 ) ;
if ( ! V_52 ) {
V_7 = - V_92 ;
goto V_16;
}
V_123 -> V_124 = * V_52 ;
V_16:
F_43 ( & V_2 -> V_86 ) ;
return V_7 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_111 * V_112 ,
struct V_122 * V_123 ,
const struct V_60 * * V_65 )
{
struct V_58 * V_59 ;
* V_65 = F_60 ( V_123 -> V_124 . V_118 , V_121 ) ;
if ( ! * V_65 ) {
T_3 V_118 ;
F_57 ( & V_118 , 0 , V_121 ) ;
* V_65 = F_60 ( V_118 , V_121 ) ;
V_123 -> V_124 . V_118 = ( * V_65 ) -> V_125 [ 0 ] ;
}
V_59 = F_54 ( V_2 , V_112 , V_2 -> V_69 ,
V_123 -> V_115 ) ;
switch ( V_123 -> V_113 ) {
case V_126 :
V_123 -> V_124 = * V_59 ;
V_123 -> V_124 . V_68 = V_127 ;
break;
case V_128 :
case V_64 :
F_61 ( & V_123 -> V_124 . V_55 ,
V_129 , V_130 , V_131 ,
& V_123 -> V_124 . V_53 ,
V_132 , V_133 , V_134 , V_135 ) ;
F_62 ( & V_123 -> V_124 , V_59 ,
true ) ;
if ( ! F_63 ( V_123 -> V_124 . V_68 ) )
V_123 -> V_124 . V_68 = V_40 ;
break;
}
}
static int F_64 ( struct V_100 * V_15 ,
struct V_111 * V_112 ,
struct V_122 * V_123 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
const struct V_60 * V_65 ;
struct V_58 * V_52 ;
int V_7 = 0 ;
if ( V_123 -> V_113 >= V_119 )
return - V_92 ;
F_42 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_90 > 0 ) {
V_7 = - V_91 ;
goto V_16;
}
F_59 ( V_2 , V_112 , V_123 , & V_65 ) ;
V_52 = F_54 ( V_2 , V_112 , V_123 -> V_113 , V_123 -> V_115 ) ;
* V_52 = V_123 -> V_124 ;
if ( V_123 -> V_113 == V_128 ||
V_123 -> V_113 == V_64 ) {
const struct V_60 * V_136 ;
struct V_58 * V_137 ;
struct V_122 V_124 ;
V_124 . V_113 = V_126 ;
V_124 . V_115 = V_123 -> V_115 ;
V_124 . V_124 = V_123 -> V_124 ;
F_59 ( V_2 , V_112 , & V_124 , & V_136 ) ;
V_137 = F_54 ( V_2 , V_112 , V_126 ,
V_123 -> V_115 ) ;
* V_137 = V_124 . V_124 ;
if ( V_123 -> V_115 == V_138 )
V_2 -> V_65 [ V_126 ] = V_136 ;
}
if ( V_123 -> V_115 == V_138 )
V_2 -> V_65 [ V_123 -> V_113 ] = V_65 ;
V_16:
F_43 ( & V_2 -> V_86 ) ;
return V_7 ;
}
static int F_65 ( struct V_139 * V_140 ,
const struct V_141 * V_142 ,
const struct V_141 * V_143 , T_3 V_144 )
{
struct V_100 * V_15 = F_51 ( V_140 ) ;
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_100 * V_145 ;
int V_7 = 0 ;
F_52 ( V_2 -> V_107 , L_7 , V_143 -> V_140 -> V_146 ,
V_142 -> V_140 -> V_146 ) ;
F_42 ( & V_2 -> V_86 ) ;
if ( V_142 -> V_144 & V_147 ) {
if ( ! F_66 ( V_143 -> V_140 ) ) {
V_7 = - V_92 ;
goto V_16;
}
V_145 = F_51 ( V_143 -> V_140 ) ;
if ( V_144 & V_148 ) {
if ( V_2 -> V_104 ) {
V_7 = - V_91 ;
goto V_16;
}
V_2 -> V_104 = V_145 ;
} else {
V_2 -> V_104 = NULL ;
}
goto V_16;
}
if ( V_144 & V_148 ) {
if ( V_2 -> V_103 ) {
V_7 = - V_91 ;
goto V_16;
}
} else {
V_2 -> V_103 = NULL ;
goto V_16;
}
if ( V_142 -> V_120 == V_64 ) {
struct V_46 * V_47 = V_2 -> V_47 ;
if ( ! F_67 ( V_143 -> V_140 ) ) {
V_7 = - V_92 ;
goto V_16;
}
if ( ! V_47 ) {
V_7 = - V_149 ;
goto V_16;
}
V_2 -> V_17 = false ;
} else {
if ( ! F_66 ( V_143 -> V_140 ) ) {
V_7 = - V_92 ;
goto V_16;
}
V_145 = F_51 ( V_143 -> V_140 ) ;
if ( ! ( V_145 -> V_150 & V_151 ) ||
V_143 -> V_120 != V_152 ) {
V_7 = - V_92 ;
goto V_16;
}
V_2 -> V_17 = true ;
}
V_2 -> V_103 = V_143 -> V_140 ;
V_2 -> V_69 = V_142 -> V_120 ;
V_16:
F_43 ( & V_2 -> V_86 ) ;
return V_7 ;
}
static int F_68 ( struct V_100 * V_15 ,
struct V_153 * V_154 ,
struct V_122 * V_155 ,
struct V_122 * V_156 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
int V_7 ;
V_7 = F_69 ( V_15 , V_154 ,
V_155 , V_156 ) ;
if ( V_7 )
return V_7 ;
F_42 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_17 && V_2 -> V_75 != V_96 ) {
F_8 ( & V_2 -> V_15 ,
L_8 ) ;
V_7 = - V_92 ;
}
F_43 ( & V_2 -> V_86 ) ;
return V_7 ;
}
static int F_70 ( struct V_100 * V_15 ,
struct V_157 * V_158 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
if ( V_158 -> V_113 >= V_119 )
return - V_92 ;
F_42 ( & V_2 -> V_86 ) ;
V_158 -> V_159 = V_2 -> V_160 [ V_158 -> V_113 ] ;
F_43 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_71 ( struct V_100 * V_15 ,
struct V_157 * V_158 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_161 * V_162 , * V_163 ;
int V_7 = 0 ;
F_42 ( & V_2 -> V_86 ) ;
V_162 = & V_2 -> V_160 [ V_2 -> V_69 ] ;
V_163 = & V_2 -> V_160 [ V_126 ] ;
switch ( V_158 -> V_113 ) {
case V_128 :
case V_64 :
* V_163 = V_158 -> V_159 ;
if ( V_2 -> V_17 )
V_163 -> V_164 *= 2 ;
break;
case V_126 :
V_158 -> V_159 = * V_162 ;
if ( V_2 -> V_17 )
V_158 -> V_159 . V_164 *= 2 ;
break;
default:
V_7 = - V_92 ;
goto V_16;
}
V_2 -> V_160 [ V_158 -> V_113 ] = V_158 -> V_159 ;
V_16:
F_43 ( & V_2 -> V_86 ) ;
return V_7 ;
}
static int F_72 ( struct V_100 * V_15 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
int V_165 , V_7 ;
T_3 V_118 ;
V_2 -> V_13 = F_73 ( V_15 -> V_166 -> V_107 ) ;
for ( V_165 = 0 ; V_165 < V_119 ; V_165 ++ ) {
V_2 -> V_113 [ V_165 ] . V_144 = ( V_165 == V_126 ) ?
V_147 : V_167 ;
V_118 = 0 ;
if ( V_165 != V_64 )
F_57 ( & V_118 , 0 , V_121 ) ;
V_7 = F_74 ( & V_2 -> V_63 [ V_165 ] ,
640 , 480 , V_118 , V_127 ,
& V_2 -> V_65 [ V_165 ] ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_160 [ V_165 ] . V_168 = 1 ;
V_2 -> V_160 [ V_165 ] . V_164 = 30 ;
if ( V_165 == V_126 )
V_2 -> V_160 [ V_165 ] . V_164 *= 2 ;
}
V_2 -> V_69 = V_128 ;
V_7 = F_44 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_75 ( & V_15 -> V_140 , V_119 , V_2 -> V_113 ) ;
if ( V_7 )
F_48 ( & V_2 -> V_84 ) ;
return V_7 ;
}
static void F_76 ( struct V_100 * V_15 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
F_48 ( & V_2 -> V_84 ) ;
}
static int F_77 ( struct V_169 * V_170 )
{
struct V_171 * V_172 ;
struct V_1 * V_2 ;
int V_7 ;
V_2 = F_78 ( & V_170 -> V_107 , sizeof( * V_2 ) , V_173 ) ;
if ( ! V_2 )
return - V_174 ;
F_79 ( V_170 , & V_2 -> V_15 ) ;
V_2 -> V_107 = & V_170 -> V_107 ;
V_172 = V_2 -> V_107 -> V_175 ;
V_2 -> V_14 = V_172 -> V_14 ;
F_80 ( & V_2 -> V_15 , & V_176 ) ;
F_81 ( & V_2 -> V_15 , V_2 ) ;
V_2 -> V_15 . V_177 = & V_178 ;
V_2 -> V_15 . V_140 . V_70 = & V_179 ;
V_2 -> V_15 . V_140 . V_180 = V_181 ;
V_2 -> V_15 . V_107 = & V_170 -> V_107 ;
V_2 -> V_15 . V_182 = V_183 ;
V_2 -> V_15 . V_144 = V_184 ;
V_2 -> V_15 . V_150 = V_172 -> V_150 ;
strncpy ( V_2 -> V_15 . V_146 , V_172 -> V_185 , sizeof( V_2 -> V_15 . V_146 ) ) ;
F_82 ( & V_2 -> V_86 ) ;
V_7 = F_83 ( & V_2 -> V_15 ) ;
if ( V_7 )
goto free;
return 0 ;
free:
F_84 ( & V_2 -> V_86 ) ;
return V_7 ;
}
static int F_85 ( struct V_169 * V_170 )
{
struct V_100 * V_15 = F_86 ( V_170 ) ;
struct V_1 * V_2 = F_50 ( V_15 ) ;
F_87 ( V_15 , L_9 ) ;
F_88 ( V_15 ) ;
F_84 ( & V_2 -> V_86 ) ;
F_89 ( & V_15 -> V_140 ) ;
return 0 ;
}
