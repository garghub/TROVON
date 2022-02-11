static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 -> V_3 ) )
F_3 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
if ( ! F_2 ( V_2 -> V_4 ) )
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
if ( ! F_2 ( V_2 -> V_5 ) )
F_3 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
if ( ! F_2 ( V_2 -> V_6 ) )
F_4 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_7 , V_8 ;
V_2 -> V_9 = V_2 -> V_10 -> V_9 [ V_2 -> V_11 ] ;
V_2 -> V_6 = F_6 ( V_2 -> V_9 ) ;
if ( F_7 ( V_2 -> V_6 ) ) {
F_8 ( & V_2 -> V_12 , L_1 ) ;
V_7 = F_9 ( V_2 -> V_6 ) ;
goto V_13;
}
if ( ! V_2 -> V_14 ) {
V_2 -> V_3 = F_10 ( V_2 -> V_9 ,
V_15 ) ;
if ( F_7 ( V_2 -> V_3 ) ) {
V_8 = V_15 ;
V_7 = F_9 ( V_2 -> V_3 ) ;
goto V_16;
}
V_2 -> V_4 = F_10 ( V_2 -> V_9 ,
V_17 ) ;
if ( F_7 ( V_2 -> V_4 ) ) {
V_8 = V_17 ;
V_7 = F_9 ( V_2 -> V_4 ) ;
goto V_16;
}
V_2 -> V_5 = F_10 ( V_2 -> V_9 ,
V_18 ) ;
if ( F_7 ( V_2 -> V_5 ) ) {
V_8 = V_18 ;
V_7 = F_9 ( V_2 -> V_5 ) ;
goto V_16;
}
}
return 0 ;
V_16:
F_8 ( & V_2 -> V_12 , L_2 , V_8 ) ;
V_13:
F_1 ( V_2 ) ;
return V_7 ;
}
static void T_1 F_11 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
T_2 V_21 , V_22 , V_23 ;
struct V_19 * V_24 ;
struct V_25 * V_26 , * V_27 ;
T_3 V_28 = V_2 -> V_29 ;
T_3 V_30 = V_2 -> V_31 ;
V_2 -> V_32 = V_2 -> V_33 ;
V_2 -> V_33 = V_20 ;
V_24 = V_2 -> V_32 ? V_2 -> V_32 : V_20 ;
V_27 = & V_24 -> V_34 . V_35 ;
V_26 = & V_20 -> V_34 . V_35 ;
switch ( V_2 -> V_36 ) {
case V_37 :
V_21 = F_12 ( V_27 , 0 ) ;
V_22 = F_12 ( V_26 , 0 ) + V_28 ;
V_23 = F_12 ( V_26 , 0 ) ;
break;
case V_38 :
V_21 = F_12 ( V_27 , 0 ) + V_28 ;
V_22 = F_12 ( V_26 , 0 ) ;
V_23 = F_12 ( V_26 , 0 ) + V_28 ;
break;
case V_39 :
V_21 = F_12 ( V_27 , 0 ) + V_30 ;
V_22 = F_12 ( V_26 , 0 ) ;
V_23 = F_12 ( V_26 , 0 ) + V_30 ;
break;
default:
V_21 = F_12 ( V_27 , 0 ) ;
V_22 = F_12 ( V_26 , 0 ) + V_30 ;
V_23 = F_12 ( V_26 , 0 ) ;
break;
}
F_13 ( V_2 -> V_3 , 0 , V_21 ) ;
F_13 ( V_2 -> V_4 , 0 , V_22 ) ;
F_13 ( V_2 -> V_5 , 0 , V_23 ) ;
F_14 ( V_2 -> V_3 , 0 ) ;
F_14 ( V_2 -> V_4 , 0 ) ;
F_14 ( V_2 -> V_5 , 0 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
T_2 V_42 , T_2 V_43 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
unsigned int V_46 ;
struct V_47 V_48 ;
int V_7 ;
F_16 ( V_41 ) ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_49 = V_45 -> V_50 . V_50 . V_49 ;
V_48 . V_49 . V_51 /= 2 ;
V_48 . V_52 . V_53 = V_48 . V_49 . V_53 ;
V_48 . V_52 . V_51 = V_48 . V_49 . V_51 ;
V_48 . V_42 = V_42 ;
V_48 . V_43 = V_43 ;
V_7 = F_17 ( V_41 , & V_48 ) ;
if ( V_7 )
return V_7 ;
V_46 = ( V_48 . V_49 . V_53 & 0xf ) ? 8 : 16 ;
F_18 ( V_41 , V_46 ) ;
F_19 ( V_41 , 1 ) ;
F_20 ( V_41 , false ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_9 , V_54 ,
V_55 ) ;
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
F_26 ( V_2 -> V_9 , V_54 ,
V_55 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
const struct V_58 * V_59 ;
int V_60 , V_7 ;
V_57 = & V_2 -> V_61 [ V_62 ] ;
V_59 = V_2 -> V_63 [ V_62 ] ;
V_60 = ( V_57 -> V_53 * V_59 -> V_64 * V_57 -> V_51 ) >> 3 ;
V_2 -> V_29 = V_60 / 2 ;
V_2 -> V_31 = V_59 -> V_65 ?
V_57 -> V_53 : ( V_57 -> V_53 * V_59 -> V_64 ) >> 3 ;
V_2 -> V_32 = NULL ;
V_2 -> V_33 = NULL ;
V_2 -> V_36 = V_57 -> V_66 ;
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
struct V_56 * V_57 ;
int V_7 ;
V_57 = & V_2 -> V_61 [ V_2 -> V_67 ] ;
V_2 -> V_68 = V_2 -> V_14 ? & V_69 : & V_70 ;
V_7 = F_5 ( V_2 ) ;
if ( V_7 )
return V_7 ;
F_34 ( V_2 -> V_6 , V_71 ,
V_57 -> V_53 , V_57 -> V_51 ) ;
F_35 ( V_2 -> V_6 , V_72 , V_57 -> V_66 ) ;
F_36 ( V_2 -> V_6 , V_2 -> V_73 ) ;
V_7 = V_2 -> V_68 -> V_74 ( V_2 ) ;
if ( V_7 )
goto V_75;
F_37 ( V_2 -> V_6 ) ;
V_2 -> V_68 -> V_76 ( V_2 ) ;
return 0 ;
V_75:
F_1 ( V_2 ) ;
return V_7 ;
}
static void F_38 ( struct V_1 * V_2 )
{
V_2 -> V_68 -> V_77 ( V_2 ) ;
F_39 ( V_2 -> V_6 ) ;
V_2 -> V_68 -> V_78 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static int F_40 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_41 ( V_80 -> V_81 ,
struct V_1 , V_82 ) ;
enum V_83 V_73 ;
int V_7 = 0 ;
F_42 ( & V_2 -> V_84 ) ;
switch ( V_80 -> V_85 ) {
case V_86 :
V_73 = V_80 -> V_87 ;
if ( V_73 != V_2 -> V_73 ) {
if ( V_2 -> V_88 > 0 ) {
V_7 = - V_89 ;
goto V_13;
}
V_2 -> V_73 = V_73 ;
}
break;
default:
F_8 ( & V_2 -> V_12 , L_3 ) ;
V_7 = - V_90 ;
}
V_13:
F_43 ( & V_2 -> V_84 ) ;
return V_7 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_91 * V_92 = & V_2 -> V_82 ;
int V_7 ;
F_45 ( V_92 , 1 ) ;
F_46 ( V_92 , & V_93 ,
V_86 ,
V_94 , 0 , V_94 ,
V_95 ) ;
V_2 -> V_12 . V_96 = V_92 ;
if ( V_92 -> error ) {
V_7 = V_92 -> error ;
goto V_97;
}
F_47 ( V_92 ) ;
return 0 ;
V_97:
F_48 ( V_92 ) ;
return V_7 ;
}
static int F_49 ( struct V_98 * V_12 , int V_99 )
{
struct V_1 * V_2 = F_50 ( V_12 ) ;
struct V_98 * V_100 = NULL ;
int V_7 = 0 ;
F_42 ( & V_2 -> V_84 ) ;
if ( ! V_2 -> V_101 || ! V_2 -> V_102 ) {
V_7 = - V_103 ;
goto V_13;
}
if ( V_2 -> V_14 )
V_100 = F_51 ( V_2 -> V_101 ) ;
if ( V_2 -> V_88 != ! V_99 )
goto V_104;
F_52 ( V_2 -> V_105 , L_4 , V_99 ? L_5 : L_6 ) ;
if ( V_99 )
V_7 = F_33 ( V_2 ) ;
else
F_38 ( V_2 ) ;
if ( V_7 )
goto V_13;
if ( V_100 ) {
V_7 = F_53 ( V_100 , V_106 , V_107 , V_99 ) ;
V_7 = ( V_7 && V_7 != - V_108 ) ? V_7 : 0 ;
if ( V_7 ) {
if ( V_99 )
F_38 ( V_2 ) ;
goto V_13;
}
}
V_104:
V_2 -> V_88 += V_99 ? 1 : - 1 ;
if ( V_2 -> V_88 < 0 )
V_2 -> V_88 = 0 ;
V_13:
F_43 ( & V_2 -> V_84 ) ;
return V_7 ;
}
static struct V_56 *
F_54 ( struct V_1 * V_2 , struct V_109 * V_110 ,
unsigned int V_111 , enum V_112 V_113 )
{
if ( V_113 == V_114 )
return F_55 ( & V_2 -> V_12 , V_110 , V_111 ) ;
else
return & V_2 -> V_61 [ V_111 ] ;
}
static int F_56 ( struct V_98 * V_12 ,
struct V_109 * V_110 ,
struct V_115 * V_116 )
{
if ( V_116 -> V_111 >= V_117 )
return - V_90 ;
return F_57 ( & V_116 -> V_116 , V_116 -> V_118 , V_119 ) ;
}
static int F_58 ( struct V_98 * V_12 ,
struct V_109 * V_110 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_50 ( V_12 ) ;
struct V_56 * V_50 ;
int V_7 = 0 ;
if ( V_121 -> V_111 >= V_117 )
return - V_90 ;
F_42 ( & V_2 -> V_84 ) ;
V_50 = F_54 ( V_2 , V_110 , V_121 -> V_111 , V_121 -> V_113 ) ;
if ( ! V_50 ) {
V_7 = - V_90 ;
goto V_13;
}
V_121 -> V_122 = * V_50 ;
V_13:
F_43 ( & V_2 -> V_84 ) ;
return V_7 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_109 * V_110 ,
struct V_120 * V_121 ,
const struct V_58 * * V_63 )
{
struct V_56 * V_57 ;
* V_63 = F_60 ( V_121 -> V_122 . V_116 , V_119 ) ;
if ( ! * V_63 ) {
T_3 V_116 ;
F_57 ( & V_116 , 0 , V_119 ) ;
* V_63 = F_60 ( V_116 , V_119 ) ;
V_121 -> V_122 . V_116 = ( * V_63 ) -> V_123 [ 0 ] ;
}
V_57 = F_54 ( V_2 , V_110 , V_2 -> V_67 ,
V_121 -> V_113 ) ;
switch ( V_121 -> V_111 ) {
case V_124 :
V_121 -> V_122 = * V_57 ;
V_121 -> V_122 . V_66 = V_125 ;
break;
case V_126 :
case V_62 :
F_61 ( & V_121 -> V_122 . V_53 ,
V_127 , V_128 , V_129 ,
& V_121 -> V_122 . V_51 ,
V_130 , V_131 , V_132 , V_133 ) ;
F_62 ( & V_121 -> V_122 , V_57 ,
true ) ;
if ( ! F_63 ( V_121 -> V_122 . V_66 ) )
V_121 -> V_122 . V_66 = V_37 ;
break;
}
}
static int F_64 ( struct V_98 * V_12 ,
struct V_109 * V_110 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_50 ( V_12 ) ;
const struct V_58 * V_63 ;
struct V_56 * V_50 ;
int V_7 = 0 ;
if ( V_121 -> V_111 >= V_117 )
return - V_90 ;
F_42 ( & V_2 -> V_84 ) ;
if ( V_2 -> V_88 > 0 ) {
V_7 = - V_89 ;
goto V_13;
}
F_59 ( V_2 , V_110 , V_121 , & V_63 ) ;
V_50 = F_54 ( V_2 , V_110 , V_121 -> V_111 , V_121 -> V_113 ) ;
* V_50 = V_121 -> V_122 ;
if ( V_121 -> V_111 == V_126 ||
V_121 -> V_111 == V_62 ) {
const struct V_58 * V_134 ;
struct V_56 * V_135 ;
struct V_120 V_122 ;
V_122 . V_111 = V_124 ;
V_122 . V_113 = V_121 -> V_113 ;
V_122 . V_122 = V_121 -> V_122 ;
F_59 ( V_2 , V_110 , & V_122 , & V_134 ) ;
V_135 = F_54 ( V_2 , V_110 , V_124 ,
V_121 -> V_113 ) ;
* V_135 = V_122 . V_122 ;
if ( V_121 -> V_113 == V_136 )
V_2 -> V_63 [ V_124 ] = V_134 ;
}
if ( V_121 -> V_113 == V_136 )
V_2 -> V_63 [ V_121 -> V_111 ] = V_63 ;
V_13:
F_43 ( & V_2 -> V_84 ) ;
return V_7 ;
}
static int F_65 ( struct V_137 * V_138 ,
const struct V_139 * V_140 ,
const struct V_139 * V_141 , T_3 V_142 )
{
struct V_98 * V_12 = F_51 ( V_138 ) ;
struct V_1 * V_2 = F_50 ( V_12 ) ;
struct V_98 * V_143 ;
int V_7 = 0 ;
F_52 ( V_2 -> V_105 , L_7 , V_141 -> V_138 -> V_144 ,
V_140 -> V_138 -> V_144 ) ;
F_42 ( & V_2 -> V_84 ) ;
if ( V_140 -> V_142 & V_145 ) {
if ( ! F_66 ( V_141 -> V_138 ) ) {
V_7 = - V_90 ;
goto V_13;
}
V_143 = F_51 ( V_141 -> V_138 ) ;
if ( V_142 & V_146 ) {
if ( V_2 -> V_102 ) {
V_7 = - V_89 ;
goto V_13;
}
V_2 -> V_102 = V_143 ;
} else {
V_2 -> V_102 = NULL ;
}
goto V_13;
}
if ( V_142 & V_146 ) {
if ( V_2 -> V_101 ) {
V_7 = - V_89 ;
goto V_13;
}
} else {
V_2 -> V_101 = NULL ;
goto V_13;
}
if ( V_140 -> V_118 == V_62 ) {
struct V_44 * V_45 = V_2 -> V_45 ;
if ( ! F_67 ( V_141 -> V_138 ) ) {
V_7 = - V_90 ;
goto V_13;
}
if ( ! V_45 ) {
V_7 = - V_147 ;
goto V_13;
}
V_2 -> V_14 = false ;
} else {
if ( ! F_66 ( V_141 -> V_138 ) ) {
V_7 = - V_90 ;
goto V_13;
}
V_143 = F_51 ( V_141 -> V_138 ) ;
if ( ! ( V_143 -> V_148 & V_149 ) ||
V_141 -> V_118 != V_150 ) {
V_7 = - V_90 ;
goto V_13;
}
V_2 -> V_14 = true ;
}
V_2 -> V_101 = V_141 -> V_138 ;
V_2 -> V_67 = V_140 -> V_118 ;
V_13:
F_43 ( & V_2 -> V_84 ) ;
return V_7 ;
}
static int F_68 ( struct V_98 * V_12 ,
struct V_151 * V_152 ,
struct V_120 * V_153 ,
struct V_120 * V_154 )
{
struct V_1 * V_2 = F_50 ( V_12 ) ;
int V_7 ;
V_7 = F_69 ( V_12 , V_152 ,
V_153 , V_154 ) ;
if ( V_7 )
return V_7 ;
F_42 ( & V_2 -> V_84 ) ;
if ( V_2 -> V_14 && V_2 -> V_73 != V_94 ) {
F_8 ( & V_2 -> V_12 ,
L_8 ) ;
V_7 = - V_90 ;
}
F_43 ( & V_2 -> V_84 ) ;
return V_7 ;
}
static int F_70 ( struct V_98 * V_12 ,
struct V_155 * V_156 )
{
struct V_1 * V_2 = F_50 ( V_12 ) ;
if ( V_156 -> V_111 >= V_117 )
return - V_90 ;
F_42 ( & V_2 -> V_84 ) ;
V_156 -> V_157 = V_2 -> V_158 [ V_156 -> V_111 ] ;
F_43 ( & V_2 -> V_84 ) ;
return 0 ;
}
static int F_71 ( struct V_98 * V_12 ,
struct V_155 * V_156 )
{
struct V_1 * V_2 = F_50 ( V_12 ) ;
struct V_159 * V_160 , * V_161 ;
int V_7 = 0 ;
F_42 ( & V_2 -> V_84 ) ;
V_160 = & V_2 -> V_158 [ V_2 -> V_67 ] ;
V_161 = & V_2 -> V_158 [ V_124 ] ;
switch ( V_156 -> V_111 ) {
case V_126 :
case V_62 :
* V_161 = V_156 -> V_157 ;
if ( V_2 -> V_14 )
V_161 -> V_162 *= 2 ;
break;
case V_124 :
V_156 -> V_157 = * V_160 ;
if ( V_2 -> V_14 )
V_156 -> V_157 . V_162 *= 2 ;
break;
default:
V_7 = - V_90 ;
goto V_13;
}
V_2 -> V_158 [ V_156 -> V_111 ] = V_156 -> V_157 ;
V_13:
F_43 ( & V_2 -> V_84 ) ;
return V_7 ;
}
static int F_72 ( struct V_98 * V_12 )
{
struct V_1 * V_2 = F_50 ( V_12 ) ;
int V_163 , V_7 ;
T_3 V_116 ;
V_2 -> V_10 = F_73 ( V_12 -> V_164 -> V_105 ) ;
for ( V_163 = 0 ; V_163 < V_117 ; V_163 ++ ) {
V_2 -> V_111 [ V_163 ] . V_142 = ( V_163 == V_124 ) ?
V_145 : V_165 ;
V_116 = 0 ;
if ( V_163 != V_62 )
F_57 ( & V_116 , 0 , V_119 ) ;
V_7 = F_74 ( & V_2 -> V_61 [ V_163 ] ,
640 , 480 , V_116 , V_125 ,
& V_2 -> V_63 [ V_163 ] ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_158 [ V_163 ] . V_166 = 1 ;
V_2 -> V_158 [ V_163 ] . V_162 = 30 ;
if ( V_163 == V_124 )
V_2 -> V_158 [ V_163 ] . V_162 *= 2 ;
}
V_2 -> V_67 = V_126 ;
V_7 = F_44 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_75 ( & V_12 -> V_138 , V_117 , V_2 -> V_111 ) ;
if ( V_7 )
F_48 ( & V_2 -> V_82 ) ;
return V_7 ;
}
static void F_76 ( struct V_98 * V_12 )
{
struct V_1 * V_2 = F_50 ( V_12 ) ;
F_48 ( & V_2 -> V_82 ) ;
}
static int F_77 ( struct V_167 * V_168 )
{
struct V_169 * V_170 ;
struct V_1 * V_2 ;
int V_7 ;
V_2 = F_78 ( & V_168 -> V_105 , sizeof( * V_2 ) , V_171 ) ;
if ( ! V_2 )
return - V_172 ;
F_79 ( V_168 , & V_2 -> V_12 ) ;
V_2 -> V_105 = & V_168 -> V_105 ;
V_170 = V_2 -> V_105 -> V_173 ;
V_2 -> V_11 = V_170 -> V_11 ;
F_80 ( & V_2 -> V_12 , & V_174 ) ;
F_81 ( & V_2 -> V_12 , V_2 ) ;
V_2 -> V_12 . V_175 = & V_176 ;
V_2 -> V_12 . V_138 . V_68 = & V_177 ;
V_2 -> V_12 . V_138 . V_178 = V_179 ;
V_2 -> V_12 . V_105 = & V_168 -> V_105 ;
V_2 -> V_12 . V_180 = V_181 ;
V_2 -> V_12 . V_142 = V_182 ;
V_2 -> V_12 . V_148 = V_170 -> V_148 ;
strncpy ( V_2 -> V_12 . V_144 , V_170 -> V_183 , sizeof( V_2 -> V_12 . V_144 ) ) ;
F_82 ( & V_2 -> V_84 ) ;
V_7 = F_83 ( & V_2 -> V_12 ) ;
if ( V_7 )
goto free;
return 0 ;
free:
F_84 ( & V_2 -> V_84 ) ;
return V_7 ;
}
static int F_85 ( struct V_167 * V_168 )
{
struct V_98 * V_12 = F_86 ( V_168 ) ;
struct V_1 * V_2 = F_50 ( V_12 ) ;
F_87 ( V_12 , L_9 ) ;
F_88 ( V_12 ) ;
F_84 ( & V_2 -> V_84 ) ;
F_89 ( & V_12 -> V_138 ) ;
return 0 ;
}
