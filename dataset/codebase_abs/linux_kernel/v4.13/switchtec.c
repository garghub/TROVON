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
struct V_103 T_3 * V_104 = V_5 -> V_46 ;
T_1 V_105 = - 1 ;
if ( F_55 ( & V_91 , V_90 , sizeof( V_91 ) ) )
return - V_71 ;
switch ( V_91 . V_106 ) {
case V_107 :
V_105 = F_23 ( & V_93 -> V_108 ) ;
F_63 ( & V_91 , & V_93 -> V_109 ) ;
if ( F_42 ( & V_104 -> V_110 ) == V_111 )
V_91 . V_112 |= V_113 ;
break;
case V_114 :
V_105 = F_23 ( & V_93 -> V_108 ) ;
F_63 ( & V_91 , & V_93 -> V_115 ) ;
if ( F_42 ( & V_104 -> V_110 ) == V_116 )
V_91 . V_112 |= V_113 ;
break;
case V_117 :
V_105 = F_23 ( & V_93 -> V_118 ) ;
F_63 ( & V_91 , & V_93 -> V_119 ) ;
if ( F_42 ( & V_104 -> V_120 ) == V_121 )
V_91 . V_112 |= V_113 ;
break;
case V_122 :
V_105 = F_23 ( & V_93 -> V_118 ) ;
F_63 ( & V_91 , & V_93 -> V_123 ) ;
if ( F_42 ( & V_104 -> V_120 ) == V_124 )
V_91 . V_112 |= V_113 ;
break;
case V_125 :
F_63 ( & V_91 , & V_93 -> V_126 ) ;
break;
case V_127 :
F_63 ( & V_91 , & V_93 -> V_128 [ 0 ] ) ;
break;
case V_129 :
F_63 ( & V_91 , & V_93 -> V_128 [ 1 ] ) ;
break;
case V_130 :
F_63 ( & V_91 , & V_93 -> V_128 [ 2 ] ) ;
break;
case V_131 :
F_63 ( & V_91 , & V_93 -> V_128 [ 3 ] ) ;
break;
case V_132 :
F_63 ( & V_91 , & V_93 -> V_128 [ 4 ] ) ;
break;
case V_133 :
F_63 ( & V_91 , & V_93 -> V_128 [ 5 ] ) ;
break;
case V_134 :
F_63 ( & V_91 , & V_93 -> V_128 [ 6 ] ) ;
break;
case V_135 :
F_63 ( & V_91 , & V_93 -> V_128 [ 7 ] ) ;
break;
default:
return - V_69 ;
}
if ( V_91 . V_101 == V_105 )
V_91 . V_112 |= V_136 ;
if ( F_59 ( V_90 , & V_91 , sizeof( V_91 ) ) )
return - V_71 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_5 ,
struct V_4 * V_6 ,
struct V_137 T_5 * V_138 )
{
struct V_137 V_139 = { 0 } ;
int V_50 ;
T_1 V_140 ;
V_139 . V_141 = F_23 ( & V_5 -> V_142 -> V_143 ) ;
V_139 . V_144 = F_23 ( & V_5 -> V_142 -> V_145 ) ;
V_139 . V_146 = F_23 ( & V_5 -> V_147 -> V_148 ) ;
for ( V_50 = 0 ; V_50 < V_5 -> V_56 ; V_50 ++ ) {
V_140 = F_23 ( & V_5 -> V_149 [ V_50 ] . V_148 ) ;
V_139 . V_150 [ V_50 ] = V_140 ;
}
for ( V_50 = 0 ; V_50 < V_151 ; V_50 ++ ) {
V_140 = F_42 ( & V_5 -> V_152 [ V_50 ] . V_153 ) ;
if ( V_140 != V_154 )
break;
V_140 = F_23 ( & V_5 -> V_152 [ V_50 ] . V_155 ) ;
V_139 . V_156 [ V_50 ] = V_140 ;
}
if ( F_59 ( V_138 , & V_139 , sizeof( V_139 ) ) )
return - V_71 ;
V_6 -> V_12 = F_10 ( & V_5 -> V_12 ) ;
return 0 ;
}
static T_1 T_3 * F_66 ( struct V_1 * V_5 ,
T_4 V_157 , int V_158 )
{
return ( void T_3 * ) V_5 -> V_142 + V_157 ;
}
static T_1 T_3 * F_67 ( struct V_1 * V_5 ,
T_4 V_157 , int V_158 )
{
return ( void T_3 * ) & V_5 -> V_149 [ V_158 ] + V_157 ;
}
static T_1 T_3 * F_68 ( struct V_1 * V_5 ,
T_4 V_157 , int V_158 )
{
return ( void T_3 * ) & V_5 -> V_152 [ V_158 ] + V_157 ;
}
static T_1 T_3 * F_69 ( struct V_1 * V_5 ,
int V_159 , int V_158 )
{
T_4 V_67 ;
if ( V_159 < 0 || V_159 >= V_160 )
return F_5 ( - V_69 ) ;
V_67 = V_161 [ V_159 ] . V_157 ;
if ( V_161 [ V_159 ] . V_162 == F_67 ) {
if ( V_158 == V_163 )
V_158 = V_5 -> V_55 ;
else if ( V_158 < 0 || V_158 >= V_5 -> V_56 )
return F_5 ( - V_69 ) ;
} else if ( V_161 [ V_159 ] . V_162 == F_68 ) {
if ( V_158 < 0 || V_158 >= V_5 -> V_164 )
return F_5 ( - V_69 ) ;
}
return V_161 [ V_159 ] . V_162 ( V_5 , V_67 , V_158 ) ;
}
static int F_70 ( struct V_1 * V_5 ,
struct V_165 * V_166 )
{
int V_50 ;
T_1 T_3 * V_140 ;
T_1 V_167 ;
V_140 = F_69 ( V_5 , V_166 -> V_159 , V_166 -> V_158 ) ;
if ( F_48 ( V_140 ) )
return F_49 ( V_140 ) ;
V_167 = F_23 ( V_140 ) ;
for ( V_50 = 0 ; V_50 < F_71 ( V_166 -> V_26 ) ; V_50 ++ )
V_166 -> V_26 [ V_50 ] = F_23 ( & V_140 [ V_50 + 1 ] ) ;
V_166 -> V_168 = V_167 & V_169 ;
V_166 -> V_170 = ( V_167 >> 5 ) & 0xFF ;
if ( ! ( V_166 -> V_171 & V_172 ) )
V_167 &= ~ V_173 ;
if ( V_166 -> V_171 & V_174 )
V_167 |= V_175 ;
if ( V_166 -> V_171 & V_176 )
V_167 &= ~ V_175 ;
if ( V_166 -> V_171 & V_177 )
V_167 |= V_178 ;
if ( V_166 -> V_171 & V_179 )
V_167 &= ~ V_178 ;
if ( V_166 -> V_171 & V_180 )
V_167 |= V_181 ;
if ( V_166 -> V_171 & V_182 )
V_167 &= ~ V_181 ;
if ( V_166 -> V_171 & V_183 )
V_167 |= V_184 ;
if ( V_166 -> V_171 & V_185 )
V_167 &= ~ V_184 ;
if ( V_166 -> V_171 )
F_22 ( V_167 , V_140 ) ;
V_166 -> V_171 = 0 ;
if ( V_167 & V_175 )
V_166 -> V_171 |= V_174 ;
if ( V_167 & V_178 )
V_166 -> V_171 |= V_177 ;
if ( V_167 & V_181 )
V_166 -> V_171 |= V_180 ;
if ( V_167 & V_184 )
V_166 -> V_171 |= V_183 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_5 ,
struct V_165 T_5 * V_186 )
{
int V_79 ;
int V_187 ;
struct V_165 V_166 ;
if ( F_55 ( & V_166 , V_186 , sizeof( V_166 ) ) )
return - V_71 ;
if ( V_166 . V_159 >= V_160 )
return - V_69 ;
if ( V_166 . V_171 & V_188 )
return - V_69 ;
if ( V_166 . V_158 == V_189 ) {
if ( V_161 [ V_166 . V_159 ] . V_162 == F_66 )
V_187 = 1 ;
else if ( V_161 [ V_166 . V_159 ] . V_162 == F_67 )
V_187 = V_5 -> V_56 ;
else if ( V_161 [ V_166 . V_159 ] . V_162 == F_68 )
V_187 = V_5 -> V_164 ;
else
return - V_69 ;
for ( V_166 . V_158 = 0 ; V_166 . V_158 < V_187 ; V_166 . V_158 ++ ) {
V_79 = F_70 ( V_5 , & V_166 ) ;
if ( V_79 < 0 )
return V_79 ;
}
} else {
V_79 = F_70 ( V_5 , & V_166 ) ;
if ( V_79 < 0 )
return V_79 ;
}
if ( F_59 ( V_186 , & V_166 , sizeof( V_166 ) ) )
return - V_71 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_5 ,
struct V_190 * V_191 )
{
int V_50 , V_150 ;
T_1 V_140 ;
struct V_192 * V_193 ;
struct V_190 V_194 ;
if ( F_55 ( & V_194 , V_191 , sizeof( V_194 ) ) )
return - V_71 ;
V_194 . V_195 = - 1 ;
for ( V_150 = 0 ; V_150 < V_5 -> V_56 ; V_150 ++ ) {
V_193 = & V_5 -> V_149 [ V_150 ] ;
V_194 . V_55 = V_150 ;
V_140 = F_23 ( & V_193 -> V_196 ) ;
if ( V_140 == V_194 . V_156 ) {
V_194 . V_195 = 0 ;
break;
}
V_140 = F_23 ( & V_193 -> V_197 ) ;
if ( V_140 == V_194 . V_156 ) {
V_194 . V_195 = V_198 ;
break;
}
for ( V_50 = 0 ; V_50 < F_71 ( V_193 -> V_199 ) ; V_50 ++ ) {
V_140 = F_23 ( & V_193 -> V_199 [ V_50 ] ) ;
if ( V_140 != V_194 . V_156 )
continue;
V_194 . V_195 = V_50 + 1 ;
break;
}
if ( V_194 . V_195 != - 1 )
break;
}
if ( F_59 ( V_191 , & V_194 , sizeof( V_194 ) ) )
return - V_71 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_5 ,
struct V_190 * V_191 )
{
struct V_190 V_194 ;
struct V_192 * V_193 ;
if ( F_55 ( & V_194 , V_191 , sizeof( V_194 ) ) )
return - V_71 ;
if ( V_194 . V_55 == V_163 )
V_193 = V_5 -> V_147 ;
else if ( V_194 . V_55 < V_5 -> V_56 )
V_193 = & V_5 -> V_149 [ V_194 . V_55 ] ;
else
return - V_69 ;
switch ( V_194 . V_195 ) {
case 0 :
V_194 . V_156 = F_23 ( & V_193 -> V_196 ) ;
break;
case V_198 :
V_194 . V_156 = F_23 ( & V_193 -> V_197 ) ;
break;
default:
if ( V_194 . V_195 > F_71 ( V_193 -> V_199 ) )
return - V_69 ;
V_194 . V_156 = F_23 ( & V_193 -> V_199 [ V_194 . V_195 - 1 ] ) ;
break;
}
if ( F_59 ( V_191 , & V_194 , sizeof( V_194 ) ) )
return - V_71 ;
return 0 ;
}
static long F_75 ( struct V_58 * V_59 , unsigned int V_28 ,
unsigned long V_200 )
{
struct V_4 * V_6 = V_59 -> V_62 ;
struct V_1 * V_5 = V_6 -> V_5 ;
int V_68 ;
void T_5 * V_201 = ( void T_5 * ) V_200 ;
V_68 = F_52 ( V_5 ) ;
if ( V_68 )
return V_68 ;
switch ( V_28 ) {
case V_202 :
V_68 = F_62 ( V_5 , V_201 ) ;
break;
case V_203 :
V_68 = F_64 ( V_5 , V_201 ) ;
break;
case V_204 :
V_68 = F_65 ( V_5 , V_6 , V_201 ) ;
break;
case V_205 :
V_68 = F_72 ( V_5 , V_201 ) ;
break;
case V_206 :
V_68 = F_73 ( V_5 , V_201 ) ;
break;
case V_207 :
V_68 = F_74 ( V_5 , V_201 ) ;
break;
default:
V_68 = - V_208 ;
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
struct V_4 * V_6 , * V_209 ;
F_78 ( V_5 -> V_210 ) ;
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
static struct V_1 * F_82 ( struct V_211 * V_210 )
{
struct V_1 * V_5 ;
int V_212 ;
struct V_2 * V_3 ;
struct V_61 * V_61 ;
int V_68 ;
V_5 = F_83 ( sizeof( * V_5 ) , V_7 ,
F_84 ( & V_210 -> V_3 ) ) ;
if ( ! V_5 )
return F_5 ( - V_8 ) ;
V_5 -> V_64 = true ;
V_5 -> V_210 = V_210 ;
F_8 ( & V_5 -> V_22 ) ;
F_85 ( & V_5 -> V_41 ) ;
V_5 -> V_21 = 0 ;
F_86 ( & V_5 -> V_40 , F_33 ) ;
F_87 ( & V_5 -> V_31 , F_37 ) ;
F_88 ( & V_5 -> V_80 ) ;
F_89 ( & V_5 -> V_12 , 0 ) ;
V_3 = & V_5 -> V_3 ;
F_90 ( V_3 ) ;
V_3 -> V_213 = V_214 ;
V_3 -> V_215 = & V_210 -> V_3 ;
V_3 -> V_216 = V_217 ;
V_3 -> V_218 = F_76 ;
V_212 = F_91 ( & V_219 , 0 , 0 ,
V_7 ) ;
if ( V_212 < 0 ) {
V_68 = V_212 ;
goto V_220;
}
V_3 -> V_221 = F_92 ( F_93 ( V_222 ) , V_212 ) ;
F_94 ( V_3 , L_12 , V_212 ) ;
V_61 = & V_5 -> V_61 ;
F_95 ( V_61 , & V_223 ) ;
V_61 -> V_224 = V_225 ;
return V_5 ;
V_220:
F_13 ( & V_5 -> V_3 ) ;
return F_5 ( V_68 ) ;
}
static int F_96 ( struct V_1 * V_5 , int V_226 , int V_227 )
{
T_4 V_67 = V_161 [ V_226 ] . V_157 ;
T_1 T_3 * V_228 ;
T_1 V_167 ;
V_228 = V_161 [ V_226 ] . V_162 ( V_5 , V_67 , V_227 ) ;
V_167 = F_23 ( V_228 ) ;
if ( ! ( V_167 & V_169 && V_167 & V_175 ) )
return 0 ;
F_11 ( & V_5 -> V_3 , L_13 , V_13 , V_226 , V_227 , V_167 ) ;
V_167 &= ~ ( V_175 | V_169 ) ;
F_22 ( V_167 , V_228 ) ;
return 1 ;
}
static int F_97 ( struct V_1 * V_5 , int V_226 )
{
int V_227 ;
int V_170 = 0 ;
if ( V_161 [ V_226 ] . V_162 == F_67 ) {
for ( V_227 = 0 ; V_227 < V_5 -> V_56 ; V_227 ++ )
V_170 += F_96 ( V_5 , V_226 , V_227 ) ;
} else if ( V_161 [ V_226 ] . V_162 == F_68 ) {
for ( V_227 = 0 ; V_227 < V_5 -> V_164 ; V_227 ++ ) {
if ( ! V_5 -> V_229 [ V_227 ] )
continue;
V_170 += F_96 ( V_5 , V_226 , V_227 ) ;
}
} else {
V_170 += F_96 ( V_5 , V_226 , 0 ) ;
}
return V_170 ;
}
static T_8 F_98 ( int V_230 , void * V_3 )
{
struct V_1 * V_5 = V_3 ;
T_1 V_140 ;
T_8 V_79 = V_231 ;
int V_226 , V_232 = 0 ;
V_140 = F_23 ( & V_5 -> V_147 -> V_233 ) ;
if ( V_140 & V_169 ) {
F_11 ( & V_5 -> V_3 , L_14 , V_13 ) ;
V_79 = V_234 ;
F_99 ( & V_5 -> V_40 ) ;
F_22 ( V_140 , & V_5 -> V_147 -> V_233 ) ;
}
for ( V_226 = 0 ; V_226 < V_160 ; V_226 ++ )
V_232 += F_97 ( V_5 , V_226 ) ;
if ( V_232 ) {
F_100 ( & V_5 -> V_12 ) ;
F_81 ( & V_5 -> V_80 ) ;
F_11 ( & V_5 -> V_3 , L_15 , V_13 ,
V_232 ) ;
return V_234 ;
}
return V_79 ;
}
static int F_101 ( struct V_1 * V_5 )
{
int V_235 ;
int V_236 ;
V_235 = F_102 ( V_5 -> V_210 , 1 , 4 ,
V_237 | V_238 ) ;
if ( V_235 < 0 )
return V_235 ;
V_236 = F_23 ( & V_5 -> V_147 -> V_239 ) ;
if ( V_236 < 0 || V_236 >= V_235 )
return - V_71 ;
V_236 = F_103 ( V_5 -> V_210 , V_236 ) ;
if ( V_236 < 0 )
return V_236 ;
return F_104 ( & V_5 -> V_210 -> V_3 , V_236 ,
F_98 , 0 ,
V_240 , V_5 ) ;
}
static void F_105 ( struct V_1 * V_5 )
{
int V_50 ;
T_1 V_140 ;
struct V_192 * V_193 = V_5 -> V_147 ;
for ( V_50 = 0 ; V_50 < V_151 ; V_50 ++ ) {
V_140 = F_42 ( & V_5 -> V_152 [ V_50 ] . V_153 ) ;
if ( V_140 != V_154 )
break;
}
V_5 -> V_164 = V_50 ;
V_140 = F_23 ( & V_193 -> V_196 ) ;
if ( V_140 < V_151 )
V_5 -> V_229 [ V_140 ] = 1 ;
V_140 = F_23 ( & V_193 -> V_197 ) ;
if ( V_140 < V_151 )
V_5 -> V_229 [ V_140 ] = 1 ;
for ( V_50 = 0 ; V_50 < F_71 ( V_193 -> V_199 ) ; V_50 ++ ) {
V_140 = F_23 ( & V_193 -> V_199 [ V_50 ] ) ;
if ( V_140 < V_151 )
V_5 -> V_229 [ V_140 ] = 1 ;
}
}
static int F_106 ( struct V_1 * V_5 ,
struct V_211 * V_210 )
{
int V_68 ;
V_68 = F_107 ( V_210 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_108 ( V_210 , 0x1 , V_240 ) ;
if ( V_68 )
return V_68 ;
F_109 ( V_210 ) ;
V_5 -> V_241 = F_110 ( V_210 ) [ 0 ] ;
V_5 -> V_24 = V_5 -> V_241 + V_242 ;
V_5 -> V_142 = V_5 -> V_241 + V_243 ;
V_5 -> V_46 = V_5 -> V_241 + V_244 ;
V_5 -> V_94 = V_5 -> V_241 + V_245 ;
V_5 -> V_246 = V_5 -> V_241 + V_247 ;
V_5 -> V_55 = F_44 ( & V_5 -> V_46 -> V_248 ) ;
V_5 -> V_56 = F_44 ( & V_5 -> V_246 -> V_56 ) ;
V_5 -> V_149 = V_5 -> V_241 + V_249 ;
V_5 -> V_147 = & V_5 -> V_149 [ V_5 -> V_55 ] ;
V_5 -> V_152 = V_5 -> V_241 + V_250 ;
if ( V_5 -> V_56 < 1 )
V_5 -> V_56 = 1 ;
F_105 ( V_5 ) ;
F_111 ( V_210 , V_5 ) ;
return 0 ;
}
static int F_112 ( struct V_211 * V_210 ,
const struct V_251 * V_51 )
{
struct V_1 * V_5 ;
int V_68 ;
V_5 = F_82 ( V_210 ) ;
if ( F_48 ( V_5 ) )
return F_49 ( V_5 ) ;
V_68 = F_106 ( V_5 , V_210 ) ;
if ( V_68 )
goto V_220;
V_68 = F_101 ( V_5 ) ;
if ( V_68 ) {
F_113 ( & V_5 -> V_3 , L_16 ) ;
goto V_220;
}
F_22 ( V_173 |
V_175 ,
& V_5 -> V_147 -> V_233 ) ;
V_68 = F_114 ( & V_5 -> V_61 , & V_5 -> V_3 ) ;
if ( V_68 )
goto V_252;
F_115 ( & V_5 -> V_3 , L_17 ) ;
return 0 ;
V_252:
F_77 ( V_5 ) ;
V_220:
F_116 ( & V_219 , F_117 ( V_5 -> V_3 . V_221 ) ) ;
F_13 ( & V_5 -> V_3 ) ;
return V_68 ;
}
static void F_118 ( struct V_211 * V_210 )
{
struct V_1 * V_5 = F_119 ( V_210 ) ;
F_111 ( V_210 , NULL ) ;
F_120 ( & V_5 -> V_61 , & V_5 -> V_3 ) ;
F_116 ( & V_219 , F_117 ( V_5 -> V_3 . V_221 ) ) ;
F_115 ( & V_5 -> V_3 , L_18 ) ;
F_77 ( V_5 ) ;
F_13 ( & V_5 -> V_3 ) ;
}
static int T_9 F_121 ( void )
{
int V_68 ;
V_68 = F_122 ( & V_222 , 0 , V_253 ,
L_19 ) ;
if ( V_68 )
return V_68 ;
V_214 = F_123 ( V_225 , L_19 ) ;
if ( F_48 ( V_214 ) ) {
V_68 = F_49 ( V_214 ) ;
goto V_254;
}
V_68 = F_124 ( & V_255 ) ;
if ( V_68 )
goto V_256;
F_125 ( V_240 L_20 ) ;
return 0 ;
V_256:
F_126 ( V_214 ) ;
V_254:
F_127 ( V_222 , V_253 ) ;
return V_68 ;
}
static void T_10 F_128 ( void )
{
F_129 ( & V_255 ) ;
F_126 ( V_214 ) ;
F_127 ( V_222 , V_253 ) ;
F_130 ( & V_219 ) ;
F_125 ( V_240 L_21 ) ;
}
