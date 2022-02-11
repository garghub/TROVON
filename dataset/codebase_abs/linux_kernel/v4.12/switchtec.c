static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_4 * F_3 ( struct V_1 * V_5 )
{
struct V_4 * V_6 ;
V_6 = F_4 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return F_5 ( - V_8 ) ;
F_6 ( & V_5 -> V_3 ) ;
V_6 -> V_5 = V_5 ;
F_7 ( & V_6 -> V_9 ) ;
F_8 ( & V_6 -> V_10 ) ;
F_9 ( & V_6 -> V_11 ) ;
V_6 -> V_12 = F_10 ( & V_5 -> V_12 ) ;
F_11 ( & V_5 -> V_3 , L_1 , V_13 , V_6 ) ;
return V_6 ;
}
static void F_12 ( struct V_9 * V_9 )
{
struct V_4 * V_6 ;
V_6 = F_2 ( V_9 , struct V_4 , V_9 ) ;
F_11 ( & V_6 -> V_5 -> V_3 , L_1 , V_13 , V_6 ) ;
F_13 ( & V_6 -> V_5 -> V_3 ) ;
F_14 ( V_6 ) ;
}
static void F_15 ( struct V_4 * V_6 )
{
F_16 ( & V_6 -> V_9 , F_12 ) ;
}
static void F_17 ( struct V_4 * V_6 ,
enum V_14 V_15 )
{
const char * const V_16 [] = {
[ V_17 ] = L_2 ,
[ V_18 ] = L_3 ,
[ V_19 ] = L_4 ,
[ V_20 ] = L_5 ,
} ;
V_6 -> V_15 = V_15 ;
F_11 ( & V_6 -> V_5 -> V_3 , L_6 ,
V_6 , V_16 [ V_15 ] ) ;
}
static void F_18 ( struct V_1 * V_5 )
{
struct V_4 * V_6 ;
if ( V_5 -> V_21 )
return;
if ( F_19 ( & V_5 -> V_22 ) )
return;
V_6 = F_20 ( V_5 -> V_22 . V_23 , struct V_4 ,
V_10 ) ;
F_17 ( V_6 , V_19 ) ;
V_5 -> V_21 = 1 ;
F_21 ( & V_5 -> V_24 -> V_25 ,
V_6 -> V_26 , V_6 -> V_27 ) ;
F_22 ( V_6 -> V_28 , & V_5 -> V_24 -> V_28 ) ;
V_6 -> V_29 = F_23 ( & V_5 -> V_24 -> V_29 ) ;
if ( V_6 -> V_29 != V_30 )
F_24 ( V_5 ) ;
F_25 ( & V_5 -> V_31 ,
F_26 ( 500 ) ) ;
}
static int F_27 ( struct V_4 * V_6 )
{
struct V_1 * V_5 = V_6 -> V_5 ;
F_28 ( & V_6 -> V_9 ) ;
V_6 -> V_32 = sizeof( V_6 -> V_26 ) ;
F_17 ( V_6 , V_18 ) ;
F_9 ( & V_6 -> V_11 ) ;
F_29 ( & V_6 -> V_10 , & V_5 -> V_22 ) ;
F_18 ( V_5 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_5 )
{
struct V_4 * V_6 ;
if ( F_19 ( & V_5 -> V_22 ) )
return;
V_6 = F_20 ( V_5 -> V_22 . V_23 , struct V_4 ,
V_10 ) ;
V_6 -> V_29 = F_23 ( & V_5 -> V_24 -> V_29 ) ;
if ( V_6 -> V_29 == V_30 )
return;
F_17 ( V_6 , V_20 ) ;
V_6 -> V_33 = 0 ;
if ( V_6 -> V_29 != V_34 )
goto V_35;
V_6 -> V_33 = F_23 ( & V_5 -> V_24 -> V_36 ) ;
if ( V_6 -> V_33 != 0 )
goto V_35;
F_30 ( V_6 -> V_26 , & V_5 -> V_24 -> V_37 ,
V_6 -> V_32 ) ;
V_35:
F_31 ( & V_6 -> V_11 ) ;
F_32 ( & V_6 -> V_10 ) ;
F_15 ( V_6 ) ;
V_5 -> V_21 = 0 ;
F_18 ( V_5 ) ;
}
static void F_33 ( struct V_38 * V_39 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( V_39 , struct V_1 , V_40 ) ;
F_11 ( & V_5 -> V_3 , L_7 , V_13 ) ;
F_34 ( & V_5 -> V_41 ) ;
F_35 ( & V_5 -> V_31 ) ;
F_24 ( V_5 ) ;
F_36 ( & V_5 -> V_41 ) ;
}
static void F_37 ( struct V_38 * V_39 )
{
struct V_1 * V_5 ;
T_1 V_29 ;
V_5 = F_2 ( V_39 , struct V_1 , V_31 . V_39 ) ;
F_11 ( & V_5 -> V_3 , L_7 , V_13 ) ;
F_34 ( & V_5 -> V_41 ) ;
V_29 = F_23 ( & V_5 -> V_24 -> V_29 ) ;
if ( V_29 == V_30 ) {
F_25 ( & V_5 -> V_31 ,
F_26 ( 500 ) ) ;
goto V_35;
}
F_24 ( V_5 ) ;
V_35:
F_36 ( & V_5 -> V_41 ) ;
}
static T_2 F_38 ( struct V_2 * V_3 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_45 ;
V_45 = F_23 ( & V_5 -> V_46 -> V_47 ) ;
return sprintf ( V_44 , L_8 , V_45 ) ;
}
static T_2 F_39 ( struct V_2 * V_3 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_45 ;
V_45 = F_23 ( & V_5 -> V_46 -> V_48 ) ;
return sprintf ( V_44 , L_9 , V_45 ) ;
}
static T_2 F_40 ( char * V_44 , void T_3 * V_43 , T_4 V_49 )
{
int V_50 ;
F_30 ( V_44 , V_43 , V_49 ) ;
V_44 [ V_49 ] = '\n' ;
V_44 [ V_49 + 1 ] = 0 ;
for ( V_50 = V_49 - 1 ; V_50 > 0 ; V_50 -- ) {
if ( V_44 [ V_50 ] != ' ' )
break;
V_44 [ V_50 ] = '\n' ;
V_44 [ V_50 + 1 ] = 0 ;
}
return strlen ( V_44 ) ;
}
static T_2 F_41 ( struct V_2 * V_3 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_51 = F_42 ( & V_5 -> V_46 -> V_52 ) ;
return sprintf ( V_44 , L_10 , V_51 ) ;
}
static T_2 F_43 ( struct V_2 * V_3 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_53 = F_44 ( & V_5 -> V_46 -> V_54 ) ;
return sprintf ( V_44 , L_11 , V_53 ) ;
}
static T_2 F_45 ( struct V_2 * V_3 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return sprintf ( V_44 , L_11 , V_5 -> V_55 ) ;
}
static T_2 F_46 ( struct V_2 * V_3 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return sprintf ( V_44 , L_11 , V_5 -> V_56 ) ;
}
static int F_47 ( struct V_57 * V_57 , struct V_58 * V_59 )
{
struct V_1 * V_5 ;
struct V_4 * V_6 ;
V_5 = F_2 ( V_57 -> V_60 , struct V_1 , V_61 ) ;
V_6 = F_3 ( V_5 ) ;
if ( F_48 ( V_6 ) )
return F_49 ( V_6 ) ;
V_59 -> V_62 = V_6 ;
F_50 ( V_57 , V_59 ) ;
F_11 ( & V_5 -> V_3 , L_1 , V_13 , V_6 ) ;
return 0 ;
}
static int F_51 ( struct V_57 * V_57 , struct V_58 * V_59 )
{
struct V_4 * V_6 = V_59 -> V_62 ;
F_15 ( V_6 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_5 )
{
if ( F_53 ( & V_5 -> V_41 ) )
return - V_63 ;
if ( ! V_5 -> V_64 ) {
F_36 ( & V_5 -> V_41 ) ;
return - V_65 ;
}
return 0 ;
}
static T_2 F_54 ( struct V_58 * V_59 , const char T_5 * V_26 ,
T_4 V_66 , T_6 * V_67 )
{
struct V_4 * V_6 = V_59 -> V_62 ;
struct V_1 * V_5 = V_6 -> V_5 ;
int V_68 ;
if ( V_66 < sizeof( V_6 -> V_28 ) ||
V_66 > sizeof( V_6 -> V_28 ) + sizeof( V_6 -> V_26 ) )
return - V_69 ;
V_6 -> V_27 = V_66 - sizeof( V_6 -> V_28 ) ;
V_68 = F_52 ( V_5 ) ;
if ( V_68 )
return V_68 ;
if ( V_6 -> V_15 != V_17 ) {
V_68 = - V_70 ;
goto V_35;
}
V_68 = F_55 ( & V_6 -> V_28 , V_26 , sizeof( V_6 -> V_28 ) ) ;
if ( V_68 ) {
V_68 = - V_71 ;
goto V_35;
}
V_26 += sizeof( V_6 -> V_28 ) ;
V_68 = F_55 ( & V_6 -> V_26 , V_26 , V_66 - sizeof( V_6 -> V_28 ) ) ;
if ( V_68 ) {
V_68 = - V_71 ;
goto V_35;
}
V_68 = F_27 ( V_6 ) ;
V_35:
F_36 ( & V_5 -> V_41 ) ;
if ( V_68 )
return V_68 ;
return V_66 ;
}
static T_2 F_56 ( struct V_58 * V_59 , char T_5 * V_26 ,
T_4 V_66 , T_6 * V_67 )
{
struct V_4 * V_6 = V_59 -> V_62 ;
struct V_1 * V_5 = V_6 -> V_5 ;
int V_68 ;
if ( V_66 < sizeof( V_6 -> V_28 ) ||
V_66 > sizeof( V_6 -> V_28 ) + sizeof( V_6 -> V_26 ) )
return - V_69 ;
V_68 = F_52 ( V_5 ) ;
if ( V_68 )
return V_68 ;
if ( V_6 -> V_15 == V_17 ) {
F_36 ( & V_5 -> V_41 ) ;
return - V_70 ;
}
V_6 -> V_32 = V_66 - sizeof( V_6 -> V_33 ) ;
F_36 ( & V_5 -> V_41 ) ;
if ( V_59 -> V_72 & V_73 ) {
if ( ! F_57 ( & V_6 -> V_11 ) )
return - V_74 ;
} else {
V_68 = F_58 ( & V_6 -> V_11 ) ;
if ( V_68 < 0 )
return V_68 ;
}
V_68 = F_52 ( V_5 ) ;
if ( V_68 )
return V_68 ;
if ( V_6 -> V_15 != V_20 ) {
F_36 ( & V_5 -> V_41 ) ;
return - V_70 ;
}
V_68 = F_59 ( V_26 , & V_6 -> V_33 ,
sizeof( V_6 -> V_33 ) ) ;
if ( V_68 ) {
V_68 = - V_71 ;
goto V_35;
}
V_26 += sizeof( V_6 -> V_33 ) ;
V_68 = F_59 ( V_26 , & V_6 -> V_26 ,
V_66 - sizeof( V_6 -> V_33 ) ) ;
if ( V_68 ) {
V_68 = - V_71 ;
goto V_35;
}
F_17 ( V_6 , V_17 ) ;
V_35:
F_36 ( & V_5 -> V_41 ) ;
if ( V_6 -> V_29 == V_34 )
return V_66 ;
else if ( V_6 -> V_29 == V_75 )
return - V_76 ;
else
return - V_77 ;
}
static unsigned int F_60 ( struct V_58 * V_59 , T_7 * V_78 )
{
struct V_4 * V_6 = V_59 -> V_62 ;
struct V_1 * V_5 = V_6 -> V_5 ;
int V_79 = 0 ;
F_61 ( V_59 , & V_6 -> V_11 . V_78 , V_78 ) ;
F_61 ( V_59 , & V_5 -> V_80 , V_78 ) ;
if ( F_52 ( V_5 ) )
return V_81 | V_82 | V_83 | V_84 | V_85 ;
F_36 ( & V_5 -> V_41 ) ;
if ( F_57 ( & V_6 -> V_11 ) )
V_79 |= V_81 | V_86 ;
if ( V_6 -> V_12 != F_10 ( & V_5 -> V_12 ) )
V_79 |= V_87 | V_88 ;
return V_79 ;
}
static int F_62 ( struct V_1 * V_5 ,
struct V_89 T_5 * V_90 )
{
struct V_89 V_91 = { 0 } ;
struct V_92 T_3 * V_93 = V_5 -> V_94 ;
V_91 . V_95 = F_23 ( & V_93 -> V_95 ) ;
V_91 . V_96 = V_97 ;
if ( F_59 ( V_90 , & V_91 , sizeof( V_91 ) ) )
return - V_71 ;
return 0 ;
}
static void F_63 ( struct V_98 * V_91 ,
struct V_99 T_3 * V_100 )
{
V_91 -> V_101 = F_23 ( & V_100 -> V_101 ) ;
V_91 -> V_102 = F_23 ( & V_100 -> V_102 ) ;
}
static int F_64 ( struct V_1 * V_5 ,
struct V_98 T_5 * V_90 )
{
struct V_98 V_91 = { 0 } ;
struct V_92 T_3 * V_93 = V_5 -> V_94 ;
T_1 V_103 = - 1 ;
if ( F_55 ( & V_91 , V_90 , sizeof( V_91 ) ) )
return - V_71 ;
switch ( V_91 . V_104 ) {
case V_105 :
V_103 = F_23 ( & V_93 -> V_106 ) ;
F_63 ( & V_91 , & V_93 -> V_107 ) ;
break;
case V_108 :
V_103 = F_23 ( & V_93 -> V_106 ) ;
F_63 ( & V_91 , & V_93 -> V_109 ) ;
break;
case V_110 :
V_103 = F_23 ( & V_93 -> V_111 ) ;
F_63 ( & V_91 , & V_93 -> V_112 ) ;
break;
case V_113 :
V_103 = F_23 ( & V_93 -> V_111 ) ;
F_63 ( & V_91 , & V_93 -> V_114 ) ;
break;
case V_115 :
F_63 ( & V_91 , & V_93 -> V_116 ) ;
break;
case V_117 :
F_63 ( & V_91 , & V_93 -> V_118 [ 0 ] ) ;
break;
case V_119 :
F_63 ( & V_91 , & V_93 -> V_118 [ 1 ] ) ;
break;
case V_120 :
F_63 ( & V_91 , & V_93 -> V_118 [ 2 ] ) ;
break;
case V_121 :
F_63 ( & V_91 , & V_93 -> V_118 [ 3 ] ) ;
break;
case V_122 :
F_63 ( & V_91 , & V_93 -> V_118 [ 4 ] ) ;
break;
case V_123 :
F_63 ( & V_91 , & V_93 -> V_118 [ 5 ] ) ;
break;
case V_124 :
F_63 ( & V_91 , & V_93 -> V_118 [ 6 ] ) ;
break;
case V_125 :
F_63 ( & V_91 , & V_93 -> V_118 [ 7 ] ) ;
break;
default:
return - V_69 ;
}
if ( V_91 . V_101 == V_103 )
V_91 . V_126 = 1 ;
if ( F_59 ( V_90 , & V_91 , sizeof( V_91 ) ) )
return - V_71 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_5 ,
struct V_4 * V_6 ,
struct V_127 T_5 * V_128 )
{
struct V_127 V_129 = { 0 } ;
int V_50 ;
T_1 V_130 ;
V_129 . V_131 = F_23 ( & V_5 -> V_132 -> V_133 ) ;
V_129 . V_134 = F_23 ( & V_5 -> V_132 -> V_135 ) ;
V_129 . V_136 = F_23 ( & V_5 -> V_137 -> V_138 ) ;
for ( V_50 = 0 ; V_50 < V_5 -> V_56 ; V_50 ++ ) {
V_130 = F_23 ( & V_5 -> V_139 [ V_50 ] . V_138 ) ;
V_129 . V_140 [ V_50 ] = V_130 ;
}
for ( V_50 = 0 ; V_50 < V_141 ; V_50 ++ ) {
V_130 = F_42 ( & V_5 -> V_142 [ V_50 ] . V_143 ) ;
if ( V_130 != V_144 )
break;
V_130 = F_23 ( & V_5 -> V_142 [ V_50 ] . V_145 ) ;
V_129 . V_146 [ V_50 ] = V_130 ;
}
if ( F_59 ( V_128 , & V_129 , sizeof( V_129 ) ) )
return - V_71 ;
V_6 -> V_12 = F_10 ( & V_5 -> V_12 ) ;
return 0 ;
}
static T_1 T_3 * F_66 ( struct V_1 * V_5 ,
T_4 V_147 , int V_148 )
{
return ( void T_3 * ) V_5 -> V_132 + V_147 ;
}
static T_1 T_3 * F_67 ( struct V_1 * V_5 ,
T_4 V_147 , int V_148 )
{
return ( void T_3 * ) & V_5 -> V_139 [ V_148 ] + V_147 ;
}
static T_1 T_3 * F_68 ( struct V_1 * V_5 ,
T_4 V_147 , int V_148 )
{
return ( void T_3 * ) & V_5 -> V_142 [ V_148 ] + V_147 ;
}
static T_1 T_3 * F_69 ( struct V_1 * V_5 ,
int V_149 , int V_148 )
{
T_4 V_67 ;
if ( V_149 < 0 || V_149 >= V_150 )
return F_5 ( - V_69 ) ;
V_67 = V_151 [ V_149 ] . V_147 ;
if ( V_151 [ V_149 ] . V_152 == F_67 ) {
if ( V_148 == V_153 )
V_148 = V_5 -> V_55 ;
else if ( V_148 < 0 || V_148 >= V_5 -> V_56 )
return F_5 ( - V_69 ) ;
} else if ( V_151 [ V_149 ] . V_152 == F_68 ) {
if ( V_148 < 0 || V_148 >= V_5 -> V_154 )
return F_5 ( - V_69 ) ;
}
return V_151 [ V_149 ] . V_152 ( V_5 , V_67 , V_148 ) ;
}
static int F_70 ( struct V_1 * V_5 ,
struct V_155 * V_156 )
{
int V_50 ;
T_1 T_3 * V_130 ;
T_1 V_157 ;
V_130 = F_69 ( V_5 , V_156 -> V_149 , V_156 -> V_148 ) ;
if ( F_48 ( V_130 ) )
return F_49 ( V_130 ) ;
V_157 = F_23 ( V_130 ) ;
for ( V_50 = 0 ; V_50 < F_71 ( V_156 -> V_26 ) ; V_50 ++ )
V_156 -> V_26 [ V_50 ] = F_23 ( & V_130 [ V_50 + 1 ] ) ;
V_156 -> V_158 = V_157 & V_159 ;
V_156 -> V_160 = ( V_157 >> 5 ) & 0xFF ;
if ( ! ( V_156 -> V_161 & V_162 ) )
V_157 &= ~ V_163 ;
if ( V_156 -> V_161 & V_164 )
V_157 |= V_165 ;
if ( V_156 -> V_161 & V_166 )
V_157 &= ~ V_165 ;
if ( V_156 -> V_161 & V_167 )
V_157 |= V_168 ;
if ( V_156 -> V_161 & V_169 )
V_157 &= ~ V_168 ;
if ( V_156 -> V_161 & V_170 )
V_157 |= V_171 ;
if ( V_156 -> V_161 & V_172 )
V_157 &= ~ V_171 ;
if ( V_156 -> V_161 & V_173 )
V_157 |= V_174 ;
if ( V_156 -> V_161 & V_175 )
V_157 &= ~ V_174 ;
if ( V_156 -> V_161 )
F_22 ( V_157 , V_130 ) ;
V_156 -> V_161 = 0 ;
if ( V_157 & V_165 )
V_156 -> V_161 |= V_164 ;
if ( V_157 & V_168 )
V_156 -> V_161 |= V_167 ;
if ( V_157 & V_171 )
V_156 -> V_161 |= V_170 ;
if ( V_157 & V_174 )
V_156 -> V_161 |= V_173 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_5 ,
struct V_155 T_5 * V_176 )
{
int V_79 ;
int V_177 ;
struct V_155 V_156 ;
if ( F_55 ( & V_156 , V_176 , sizeof( V_156 ) ) )
return - V_71 ;
if ( V_156 . V_149 >= V_150 )
return - V_69 ;
if ( V_156 . V_161 & V_178 )
return - V_69 ;
if ( V_156 . V_148 == V_179 ) {
if ( V_151 [ V_156 . V_149 ] . V_152 == F_66 )
V_177 = 1 ;
else if ( V_151 [ V_156 . V_149 ] . V_152 == F_67 )
V_177 = V_5 -> V_56 ;
else if ( V_151 [ V_156 . V_149 ] . V_152 == F_68 )
V_177 = V_5 -> V_154 ;
else
return - V_69 ;
for ( V_156 . V_148 = 0 ; V_156 . V_148 < V_177 ; V_156 . V_148 ++ ) {
V_79 = F_70 ( V_5 , & V_156 ) ;
if ( V_79 < 0 )
return V_79 ;
}
} else {
V_79 = F_70 ( V_5 , & V_156 ) ;
if ( V_79 < 0 )
return V_79 ;
}
if ( F_59 ( V_176 , & V_156 , sizeof( V_156 ) ) )
return - V_71 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_5 ,
struct V_180 * V_181 )
{
int V_50 , V_140 ;
T_1 V_130 ;
struct V_182 * V_183 ;
struct V_180 V_184 ;
if ( F_55 ( & V_184 , V_181 , sizeof( V_184 ) ) )
return - V_71 ;
V_184 . V_185 = - 1 ;
for ( V_140 = 0 ; V_140 < V_5 -> V_56 ; V_140 ++ ) {
V_183 = & V_5 -> V_139 [ V_140 ] ;
V_184 . V_55 = V_140 ;
V_130 = F_23 ( & V_183 -> V_186 ) ;
if ( V_130 == V_184 . V_146 ) {
V_184 . V_185 = 0 ;
break;
}
V_130 = F_23 ( & V_183 -> V_187 ) ;
if ( V_130 == V_184 . V_146 ) {
V_184 . V_185 = V_188 ;
break;
}
for ( V_50 = 0 ; V_50 < F_71 ( V_183 -> V_189 ) ; V_50 ++ ) {
V_130 = F_23 ( & V_183 -> V_189 [ V_50 ] ) ;
if ( V_130 != V_184 . V_146 )
continue;
V_184 . V_185 = V_50 + 1 ;
break;
}
if ( V_184 . V_185 != - 1 )
break;
}
if ( F_59 ( V_181 , & V_184 , sizeof( V_184 ) ) )
return - V_71 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_5 ,
struct V_180 * V_181 )
{
struct V_180 V_184 ;
struct V_182 * V_183 ;
if ( F_55 ( & V_184 , V_181 , sizeof( V_184 ) ) )
return - V_71 ;
if ( V_184 . V_55 == V_153 )
V_183 = V_5 -> V_137 ;
else if ( V_184 . V_55 < V_5 -> V_56 )
V_183 = & V_5 -> V_139 [ V_184 . V_55 ] ;
else
return - V_69 ;
switch ( V_184 . V_185 ) {
case 0 :
V_184 . V_146 = F_23 ( & V_183 -> V_186 ) ;
break;
case V_188 :
V_184 . V_146 = F_23 ( & V_183 -> V_187 ) ;
break;
default:
if ( V_184 . V_185 > F_71 ( V_183 -> V_189 ) )
return - V_69 ;
V_184 . V_146 = F_23 ( & V_183 -> V_189 [ V_184 . V_185 - 1 ] ) ;
break;
}
if ( F_59 ( V_181 , & V_184 , sizeof( V_184 ) ) )
return - V_71 ;
return 0 ;
}
static long F_75 ( struct V_58 * V_59 , unsigned int V_28 ,
unsigned long V_190 )
{
struct V_4 * V_6 = V_59 -> V_62 ;
struct V_1 * V_5 = V_6 -> V_5 ;
int V_68 ;
void T_5 * V_191 = ( void T_5 * ) V_190 ;
V_68 = F_52 ( V_5 ) ;
if ( V_68 )
return V_68 ;
switch ( V_28 ) {
case V_192 :
V_68 = F_62 ( V_5 , V_191 ) ;
break;
case V_193 :
V_68 = F_64 ( V_5 , V_191 ) ;
break;
case V_194 :
V_68 = F_65 ( V_5 , V_6 , V_191 ) ;
break;
case V_195 :
V_68 = F_72 ( V_5 , V_191 ) ;
break;
case V_196 :
V_68 = F_73 ( V_5 , V_191 ) ;
break;
case V_197 :
V_68 = F_74 ( V_5 , V_191 ) ;
break;
default:
V_68 = - V_198 ;
break;
}
F_36 ( & V_5 -> V_41 ) ;
return V_68 ;
}
static void F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_14 ( V_5 ) ;
}
static void F_77 ( struct V_1 * V_5 )
{
struct V_4 * V_6 , * V_199 ;
F_78 ( V_5 -> V_200 ) ;
F_79 ( & V_5 -> V_31 ) ;
F_34 ( & V_5 -> V_41 ) ;
V_5 -> V_64 = false ;
F_80 (stuser, tmpuser, &stdev->mrpc_queue, list) {
F_31 ( & V_6 -> V_11 ) ;
F_32 ( & V_6 -> V_10 ) ;
F_15 ( V_6 ) ;
}
F_36 ( & V_5 -> V_41 ) ;
F_81 ( & V_5 -> V_80 ) ;
}
static struct V_1 * F_82 ( struct V_201 * V_200 )
{
struct V_1 * V_5 ;
int V_202 ;
struct V_2 * V_3 ;
struct V_61 * V_61 ;
int V_68 ;
V_5 = F_83 ( sizeof( * V_5 ) , V_7 ,
F_84 ( & V_200 -> V_3 ) ) ;
if ( ! V_5 )
return F_5 ( - V_8 ) ;
V_5 -> V_64 = true ;
V_5 -> V_200 = V_200 ;
F_8 ( & V_5 -> V_22 ) ;
F_85 ( & V_5 -> V_41 ) ;
V_5 -> V_21 = 0 ;
F_86 ( & V_5 -> V_40 , F_33 ) ;
F_87 ( & V_5 -> V_31 , F_37 ) ;
F_88 ( & V_5 -> V_80 ) ;
F_89 ( & V_5 -> V_12 , 0 ) ;
V_3 = & V_5 -> V_3 ;
F_90 ( V_3 ) ;
V_3 -> V_203 = V_204 ;
V_3 -> V_205 = & V_200 -> V_3 ;
V_3 -> V_206 = V_207 ;
V_3 -> V_208 = F_76 ;
V_202 = F_91 ( & V_209 , 0 , 0 ,
V_7 ) ;
if ( V_202 < 0 ) {
V_68 = V_202 ;
goto V_210;
}
V_3 -> V_211 = F_92 ( F_93 ( V_212 ) , V_202 ) ;
F_94 ( V_3 , L_12 , V_202 ) ;
V_61 = & V_5 -> V_61 ;
F_95 ( V_61 , & V_213 ) ;
V_61 -> V_214 = V_215 ;
return V_5 ;
V_210:
F_13 ( & V_5 -> V_3 ) ;
return F_5 ( V_68 ) ;
}
static int F_96 ( struct V_1 * V_5 , int V_216 , int V_217 )
{
T_4 V_67 = V_151 [ V_216 ] . V_147 ;
T_1 T_3 * V_218 ;
T_1 V_157 ;
V_218 = V_151 [ V_216 ] . V_152 ( V_5 , V_67 , V_217 ) ;
V_157 = F_23 ( V_218 ) ;
if ( ! ( V_157 & V_159 && V_157 & V_165 ) )
return 0 ;
F_11 ( & V_5 -> V_3 , L_13 , V_13 , V_216 , V_217 , V_157 ) ;
V_157 &= ~ ( V_165 | V_159 ) ;
F_22 ( V_157 , V_218 ) ;
return 1 ;
}
static int F_97 ( struct V_1 * V_5 , int V_216 )
{
int V_217 ;
int V_160 = 0 ;
if ( V_151 [ V_216 ] . V_152 == F_67 ) {
for ( V_217 = 0 ; V_217 < V_5 -> V_56 ; V_217 ++ )
V_160 += F_96 ( V_5 , V_216 , V_217 ) ;
} else if ( V_151 [ V_216 ] . V_152 == F_68 ) {
for ( V_217 = 0 ; V_217 < V_5 -> V_154 ; V_217 ++ ) {
if ( ! V_5 -> V_219 [ V_217 ] )
continue;
V_160 += F_96 ( V_5 , V_216 , V_217 ) ;
}
} else {
V_160 += F_96 ( V_5 , V_216 , 0 ) ;
}
return V_160 ;
}
static T_8 F_98 ( int V_220 , void * V_3 )
{
struct V_1 * V_5 = V_3 ;
T_1 V_130 ;
T_8 V_79 = V_221 ;
int V_216 , V_222 = 0 ;
V_130 = F_23 ( & V_5 -> V_137 -> V_223 ) ;
if ( V_130 & V_159 ) {
F_11 ( & V_5 -> V_3 , L_14 , V_13 ) ;
V_79 = V_224 ;
F_99 ( & V_5 -> V_40 ) ;
F_22 ( V_130 , & V_5 -> V_137 -> V_223 ) ;
}
for ( V_216 = 0 ; V_216 < V_150 ; V_216 ++ )
V_222 += F_97 ( V_5 , V_216 ) ;
if ( V_222 ) {
F_100 ( & V_5 -> V_12 ) ;
F_81 ( & V_5 -> V_80 ) ;
F_11 ( & V_5 -> V_3 , L_15 , V_13 ,
V_222 ) ;
return V_224 ;
}
return V_79 ;
}
static int F_101 ( struct V_1 * V_5 )
{
int V_225 ;
int V_226 ;
V_225 = F_102 ( V_5 -> V_200 , 1 , 4 ,
V_227 | V_228 ) ;
if ( V_225 < 0 )
return V_225 ;
V_226 = F_23 ( & V_5 -> V_137 -> V_229 ) ;
if ( V_226 < 0 || V_226 >= V_225 )
return - V_71 ;
V_226 = F_103 ( V_5 -> V_200 , V_226 ) ;
if ( V_226 < 0 )
return V_226 ;
return F_104 ( & V_5 -> V_200 -> V_3 , V_226 ,
F_98 , 0 ,
V_230 , V_5 ) ;
}
static void F_105 ( struct V_1 * V_5 )
{
int V_50 ;
T_1 V_130 ;
struct V_182 * V_183 = V_5 -> V_137 ;
for ( V_50 = 0 ; V_50 < V_141 ; V_50 ++ ) {
V_130 = F_42 ( & V_5 -> V_142 [ V_50 ] . V_143 ) ;
if ( V_130 != V_144 )
break;
}
V_5 -> V_154 = V_50 ;
V_130 = F_23 ( & V_183 -> V_186 ) ;
if ( V_130 < V_141 )
V_5 -> V_219 [ V_130 ] = 1 ;
V_130 = F_23 ( & V_183 -> V_187 ) ;
if ( V_130 < V_141 )
V_5 -> V_219 [ V_130 ] = 1 ;
for ( V_50 = 0 ; V_50 < F_71 ( V_183 -> V_189 ) ; V_50 ++ ) {
V_130 = F_23 ( & V_183 -> V_189 [ V_50 ] ) ;
if ( V_130 < V_141 )
V_5 -> V_219 [ V_130 ] = 1 ;
}
}
static int F_106 ( struct V_1 * V_5 ,
struct V_201 * V_200 )
{
int V_68 ;
V_68 = F_107 ( V_200 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_108 ( V_200 , 0x1 , V_230 ) ;
if ( V_68 )
return V_68 ;
F_109 ( V_200 ) ;
V_5 -> V_231 = F_110 ( V_200 ) [ 0 ] ;
V_5 -> V_24 = V_5 -> V_231 + V_232 ;
V_5 -> V_132 = V_5 -> V_231 + V_233 ;
V_5 -> V_46 = V_5 -> V_231 + V_234 ;
V_5 -> V_94 = V_5 -> V_231 + V_235 ;
V_5 -> V_236 = V_5 -> V_231 + V_237 ;
V_5 -> V_55 = F_44 ( & V_5 -> V_46 -> V_238 ) ;
V_5 -> V_56 = F_44 ( & V_5 -> V_236 -> V_56 ) ;
V_5 -> V_139 = V_5 -> V_231 + V_239 ;
V_5 -> V_137 = & V_5 -> V_139 [ V_5 -> V_55 ] ;
V_5 -> V_142 = V_5 -> V_231 + V_240 ;
if ( V_5 -> V_56 < 1 )
V_5 -> V_56 = 1 ;
F_105 ( V_5 ) ;
F_111 ( V_200 , V_5 ) ;
return 0 ;
}
static int F_112 ( struct V_201 * V_200 ,
const struct V_241 * V_51 )
{
struct V_1 * V_5 ;
int V_68 ;
V_5 = F_82 ( V_200 ) ;
if ( F_48 ( V_5 ) )
return F_49 ( V_5 ) ;
V_68 = F_106 ( V_5 , V_200 ) ;
if ( V_68 )
goto V_210;
V_68 = F_101 ( V_5 ) ;
if ( V_68 ) {
F_113 ( & V_5 -> V_3 , L_16 ) ;
goto V_210;
}
F_22 ( V_163 |
V_165 ,
& V_5 -> V_137 -> V_223 ) ;
V_68 = F_114 ( & V_5 -> V_61 , & V_5 -> V_3 ) ;
if ( V_68 )
goto V_242;
F_115 ( & V_5 -> V_3 , L_17 ) ;
return 0 ;
V_242:
F_77 ( V_5 ) ;
V_210:
F_116 ( & V_209 , F_117 ( V_5 -> V_3 . V_211 ) ) ;
F_13 ( & V_5 -> V_3 ) ;
return V_68 ;
}
static void F_118 ( struct V_201 * V_200 )
{
struct V_1 * V_5 = F_119 ( V_200 ) ;
F_111 ( V_200 , NULL ) ;
F_120 ( & V_5 -> V_61 , & V_5 -> V_3 ) ;
F_116 ( & V_209 , F_117 ( V_5 -> V_3 . V_211 ) ) ;
F_115 ( & V_5 -> V_3 , L_18 ) ;
F_77 ( V_5 ) ;
F_13 ( & V_5 -> V_3 ) ;
}
static int T_9 F_121 ( void )
{
int V_68 ;
V_68 = F_122 ( & V_212 , 0 , V_243 ,
L_19 ) ;
if ( V_68 )
return V_68 ;
V_204 = F_123 ( V_215 , L_19 ) ;
if ( F_48 ( V_204 ) ) {
V_68 = F_49 ( V_204 ) ;
goto V_244;
}
V_68 = F_124 ( & V_245 ) ;
if ( V_68 )
goto V_246;
F_125 ( V_230 L_20 ) ;
return 0 ;
V_246:
F_126 ( V_204 ) ;
V_244:
F_127 ( V_212 , V_243 ) ;
return V_68 ;
}
static void T_10 F_128 ( void )
{
F_129 ( & V_245 ) ;
F_126 ( V_204 ) ;
F_127 ( V_212 , V_243 ) ;
F_130 ( & V_209 ) ;
F_125 ( V_230 L_21 ) ;
}
