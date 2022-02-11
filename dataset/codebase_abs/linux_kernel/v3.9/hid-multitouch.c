static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 != 0 || V_2 -> V_5 == 0 )
return V_2 -> V_3 . V_4 ;
else
return - 1 ;
}
static T_1 F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_3 ( V_7 , struct V_11 , V_7 ) ;
struct V_1 * V_2 = F_4 ( V_12 ) ;
return sprintf ( V_10 , L_1 , V_2 -> V_13 . V_14 ) ;
}
static T_1 F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_2 V_15 )
{
struct V_11 * V_12 = F_3 ( V_7 , struct V_11 , V_7 ) ;
struct V_1 * V_2 = F_4 ( V_12 ) ;
unsigned long V_16 ;
if ( F_6 ( V_10 , 0 , & V_16 ) )
return - V_17 ;
V_2 -> V_13 . V_14 = V_16 ;
if ( V_2 -> V_18 < 0 )
V_2 -> V_13 . V_14 &= ~ V_19 ;
return V_15 ;
}
static void F_7 ( struct V_11 * V_12 ,
struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
int V_24 ;
switch ( V_23 -> V_25 ) {
case V_26 :
V_2 -> V_27 = V_21 -> V_28 -> V_29 ;
V_2 -> V_30 = 0 ;
for ( V_24 = 0 ; V_24 < V_21 -> V_31 ; V_24 ++ ) {
if ( V_21 -> V_23 [ V_24 ] . V_25 == V_23 -> V_25 ) {
V_2 -> V_30 = V_24 ;
break;
}
}
break;
case V_32 :
V_2 -> V_33 = V_21 -> V_28 -> V_29 ;
V_2 -> V_34 = V_21 -> V_35 [ 0 ] ;
if ( ! V_2 -> V_34 &&
V_21 -> V_36 <= V_37 )
V_2 -> V_34 = V_21 -> V_36 ;
if ( V_2 -> V_13 . V_34 )
V_2 -> V_34 = V_2 -> V_13 . V_34 ;
break;
case 0xff0000c5 :
if ( V_21 -> V_38 == 256 && V_21 -> V_39 == 8 ) {
T_3 * V_14 = & V_2 -> V_13 . V_14 ;
* V_14 |= V_40 ;
* V_14 |= V_41 ;
* V_14 |= V_42 ;
* V_14 |= V_19 ;
* V_14 &= ~ V_43 ;
* V_14 &= ~ V_44 ;
* V_14 &= ~ V_45 ;
}
break;
}
}
static void F_8 ( struct V_46 * V_47 , unsigned int V_48 ,
struct V_20 * V_21 , int V_49 )
{
int V_50 = V_21 -> V_51 ;
int V_52 = V_21 -> V_36 ;
int V_53 = V_49 ? ( V_52 - V_50 ) / V_49 : 0 ;
F_9 ( V_47 , V_48 , V_50 , V_52 , V_53 , 0 ) ;
F_10 ( V_47 , V_48 , F_11 ( V_21 , V_48 ) ) ;
}
static void F_12 ( struct V_22 * V_23 , struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_56 * V_57 = V_2 -> V_58 ;
if ( V_57 -> V_59 >= V_60 )
return;
V_57 -> V_61 [ V_57 -> V_59 ++ ] = V_23 -> V_25 ;
}
static int F_13 ( struct V_11 * V_12 , struct V_54 * V_55 ,
struct V_20 * V_21 , struct V_22 * V_23 ,
unsigned long * * V_62 , int * V_63 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_64 * V_65 = & V_2 -> V_13 ;
int V_48 ;
struct V_22 * V_66 = NULL ;
if ( V_21 -> V_67 == V_68 )
V_2 -> V_69 |= V_70 ;
else if ( V_21 -> V_67 != V_71 )
return 0 ;
if ( V_21 -> V_67 == V_71 ||
( V_23 -> V_25 & V_72 ) == V_73 )
V_2 -> V_69 |= V_74 ;
if ( V_21 -> V_75 == V_76 )
return - 1 ;
if ( V_23 -> V_77 )
V_66 = & V_21 -> V_23 [ V_23 -> V_77 - 1 ] ;
switch ( V_23 -> V_25 & V_72 ) {
case V_78 :
switch ( V_23 -> V_25 ) {
case V_79 :
if ( V_66 && ( V_66 -> V_25 == V_23 -> V_25 ) ) {
F_14 ( V_55 , V_23 , V_62 , V_63 ,
V_80 , V_81 ) ;
F_8 ( V_55 -> V_47 , V_81 , V_21 ,
V_65 -> V_82 ) ;
} else {
F_14 ( V_55 , V_23 , V_62 , V_63 ,
V_80 , V_83 ) ;
F_8 ( V_55 -> V_47 , V_83 , V_21 ,
V_65 -> V_82 ) ;
}
F_12 ( V_23 , V_2 , V_55 ) ;
V_2 -> V_84 = V_21 -> V_85 ;
return 1 ;
case V_86 :
if ( V_66 && ( V_66 -> V_25 == V_23 -> V_25 ) ) {
F_14 ( V_55 , V_23 , V_62 , V_63 ,
V_80 , V_87 ) ;
F_8 ( V_55 -> V_47 , V_87 , V_21 ,
V_65 -> V_82 ) ;
} else {
F_14 ( V_55 , V_23 , V_62 , V_63 ,
V_80 , V_88 ) ;
F_8 ( V_55 -> V_47 , V_88 , V_21 ,
V_65 -> V_82 ) ;
}
F_12 ( V_23 , V_2 , V_55 ) ;
V_2 -> V_84 = V_21 -> V_85 ;
return 1 ;
}
return 0 ;
case V_89 :
switch ( V_23 -> V_25 ) {
case V_90 :
if ( V_65 -> V_14 & V_42 ) {
F_14 ( V_55 , V_23 , V_62 , V_63 ,
V_80 , V_91 ) ;
F_9 ( V_55 -> V_47 ,
V_91 , 0 , 1 , 0 , 0 ) ;
}
F_12 ( V_23 , V_2 , V_55 ) ;
V_2 -> V_84 = V_21 -> V_85 ;
return 1 ;
case V_92 :
F_12 ( V_23 , V_2 , V_55 ) ;
V_2 -> V_84 = V_21 -> V_85 ;
return 1 ;
case V_93 :
F_14 ( V_55 , V_23 , V_62 , V_63 , V_94 , V_95 ) ;
F_15 ( V_55 -> V_47 , V_94 , V_95 ) ;
F_12 ( V_23 , V_2 , V_55 ) ;
V_2 -> V_84 = V_21 -> V_85 ;
return 1 ;
case V_96 :
F_12 ( V_23 , V_2 , V_55 ) ;
V_2 -> V_84 = V_21 -> V_85 ;
V_2 -> V_97 ++ ;
V_2 -> V_98 = V_21 -> V_28 -> V_29 ;
return 1 ;
case V_99 :
F_14 ( V_55 , V_23 , V_62 , V_63 ,
V_80 , V_100 ) ;
if ( ! ( V_65 -> V_14 & V_101 ) )
F_8 ( V_55 -> V_47 , V_100 , V_21 ,
V_65 -> V_102 ) ;
F_12 ( V_23 , V_2 , V_55 ) ;
V_2 -> V_84 = V_21 -> V_85 ;
return 1 ;
case V_103 :
F_14 ( V_55 , V_23 , V_62 , V_63 ,
V_80 , V_104 ) ;
if ( ! ( V_65 -> V_14 & V_101 ) ) {
F_8 ( V_55 -> V_47 , V_104 , V_21 ,
V_65 -> V_105 ) ;
F_9 ( V_55 -> V_47 ,
V_106 , 0 , 1 , 0 , 0 ) ;
}
F_12 ( V_23 , V_2 , V_55 ) ;
V_2 -> V_84 = V_21 -> V_85 ;
return 1 ;
case V_107 :
F_14 ( V_55 , V_23 , V_62 , V_63 ,
V_80 , V_108 ) ;
F_8 ( V_55 -> V_47 , V_108 , V_21 ,
V_65 -> V_109 ) ;
F_12 ( V_23 , V_2 , V_55 ) ;
V_2 -> V_84 = V_21 -> V_85 ;
return 1 ;
case V_110 :
V_2 -> V_18 = V_21 -> V_85 ;
V_2 -> V_111 = V_23 -> V_77 ;
V_2 -> V_84 = V_21 -> V_85 ;
return 1 ;
case V_32 :
V_2 -> V_84 = V_21 -> V_85 ;
return - 1 ;
case V_112 :
return - 1 ;
}
return 0 ;
case V_73 :
V_48 = V_113 + ( ( V_23 -> V_25 - 1 ) & V_114 ) ;
F_14 ( V_55 , V_23 , V_62 , V_63 , V_94 , V_48 ) ;
F_15 ( V_55 -> V_47 , V_94 , V_48 ) ;
return 1 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_12 , struct V_54 * V_55 ,
struct V_20 * V_21 , struct V_22 * V_23 ,
unsigned long * * V_62 , int * V_63 )
{
if ( V_23 -> type == V_94 || V_23 -> type == V_80 )
F_17 ( V_23 -> type , V_55 -> V_47 -> V_115 ) ;
return - 1 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
T_3 V_14 = V_2 -> V_13 . V_14 ;
if ( V_14 & V_116 )
return V_2 -> V_3 . V_4 ;
if ( V_14 & V_117 )
return F_1 ( V_2 ) ;
if ( V_14 & V_118 )
return V_2 -> V_5 ;
if ( V_14 & V_119 )
return V_2 -> V_3 . V_4 - 1 ;
return F_19 ( V_47 , V_2 -> V_3 . V_4 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
if ( ( V_2 -> V_13 . V_14 & V_19 ) &&
V_2 -> V_5 >= V_2 -> V_120 )
return;
if ( V_2 -> V_121 || ( V_2 -> V_13 . V_14 & V_40 ) ) {
int V_122 = F_18 ( V_2 , V_47 ) ;
struct V_123 * V_124 = & V_2 -> V_3 ;
struct V_125 * V_126 = V_47 -> V_126 ;
if ( V_122 < 0 || V_122 >= V_2 -> V_34 )
return;
if ( ( V_2 -> V_13 . V_14 & V_41 ) && V_126 ) {
struct V_127 * V_128 = & V_126 -> V_129 [ V_122 ] ;
if ( F_21 ( V_128 ) &&
F_22 ( V_126 , V_128 ) )
return;
}
V_127 ( V_47 , V_122 ) ;
F_23 ( V_47 , V_130 ,
V_124 -> V_131 || V_124 -> V_132 ) ;
if ( V_124 -> V_131 || V_124 -> V_132 ) {
int V_133 = ( V_124 -> V_134 > V_124 -> V_135 ) ;
int V_136 = V_63 ( V_124 -> V_134 , V_124 -> V_135 ) >> 1 ;
int V_137 = F_24 ( V_124 -> V_134 , V_124 -> V_135 ) >> 1 ;
F_25 ( V_47 , V_80 , V_83 , V_124 -> V_138 ) ;
F_25 ( V_47 , V_80 , V_88 , V_124 -> V_139 ) ;
F_25 ( V_47 , V_80 , V_81 , V_124 -> V_140 ) ;
F_25 ( V_47 , V_80 , V_87 , V_124 -> V_141 ) ;
F_25 ( V_47 , V_80 , V_91 ,
! V_124 -> V_131 ) ;
F_25 ( V_47 , V_80 , V_106 , V_133 ) ;
F_25 ( V_47 , V_80 , V_108 , V_124 -> V_142 ) ;
F_25 ( V_47 , V_80 , V_100 , V_136 ) ;
F_25 ( V_47 , V_80 , V_104 , V_137 ) ;
}
}
V_2 -> V_5 ++ ;
}
static void F_26 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
F_27 ( V_47 ) ;
F_28 ( V_47 ) ;
V_2 -> V_5 = 0 ;
}
static int F_29 ( struct V_11 * V_25 , struct V_20 * V_21 ,
struct V_22 * V_23 , T_3 V_35 )
{
if ( V_25 -> V_143 & V_144 && V_25 -> V_145 )
V_25 -> V_145 ( V_25 , V_21 , V_23 , V_35 ) ;
return 1 ;
}
static void F_30 ( struct V_11 * V_25 , struct V_20 * V_21 ,
struct V_22 * V_23 , T_3 V_35 )
{
struct V_1 * V_2 = F_4 ( V_25 ) ;
T_3 V_14 = V_2 -> V_13 . V_14 ;
struct V_46 * V_47 = V_21 -> V_146 -> V_47 ;
if ( V_25 -> V_143 & V_147 ) {
switch ( V_23 -> V_25 ) {
case V_90 :
if ( V_14 & V_44 )
V_2 -> V_121 = V_35 ;
if ( V_14 & V_42 )
V_2 -> V_3 . V_132 = V_35 ;
break;
case V_93 :
if ( V_14 & V_43 )
V_2 -> V_121 = V_35 ;
V_2 -> V_3 . V_131 = V_35 ;
break;
case V_92 :
if ( V_14 & V_45 )
V_2 -> V_121 = V_35 ;
break;
case V_96 :
V_2 -> V_3 . V_4 = V_35 ;
break;
case V_107 :
V_2 -> V_3 . V_142 = V_35 ;
break;
case V_79 :
if ( V_23 -> V_48 == V_81 )
V_2 -> V_3 . V_140 = V_35 ;
else
V_2 -> V_3 . V_138 = V_35 ;
break;
case V_86 :
if ( V_23 -> V_48 == V_87 )
V_2 -> V_3 . V_141 = V_35 ;
else
V_2 -> V_3 . V_139 = V_35 ;
break;
case V_99 :
V_2 -> V_3 . V_134 = V_35 ;
break;
case V_103 :
V_2 -> V_3 . V_135 = V_35 ;
break;
case V_110 :
break;
case V_112 :
break;
default:
if ( V_23 -> type )
F_25 ( V_47 , V_23 -> type , V_23 -> V_48 ,
V_35 ) ;
return;
}
if ( V_23 -> V_77 + 1 == V_21 -> V_38 ) {
if ( V_23 -> V_25 == V_2 -> V_148 )
F_20 ( V_2 , V_47 ) ;
if ( V_21 -> V_85 == V_2 -> V_84
&& V_2 -> V_5 >= V_2 -> V_120 )
F_26 ( V_2 , V_21 -> V_146 -> V_47 ) ;
}
}
}
static void F_31 ( struct V_11 * V_25 , struct V_149 * V_28 )
{
struct V_1 * V_2 = F_4 ( V_25 ) ;
struct V_20 * V_21 ;
unsigned V_15 ;
int V_150 , V_151 ;
if ( V_28 -> V_29 != V_2 -> V_98 )
return;
if ( ! ( V_25 -> V_143 & V_147 ) )
return;
if ( V_2 -> V_18 >= 0 ) {
struct V_20 * V_21 = V_28 -> V_21 [ V_2 -> V_18 ] ;
int V_35 = V_21 -> V_35 [ V_2 -> V_111 ] ;
if ( V_35 )
V_2 -> V_120 = V_35 ;
}
for ( V_150 = 0 ; V_150 < V_28 -> V_152 ; V_150 ++ ) {
V_21 = V_28 -> V_21 [ V_150 ] ;
V_15 = V_21 -> V_38 ;
if ( ! ( V_153 & V_21 -> V_154 ) )
continue;
for ( V_151 = 0 ; V_151 < V_15 ; V_151 ++ )
F_30 ( V_25 , V_21 , & V_21 -> V_23 [ V_151 ] ,
V_21 -> V_35 [ V_151 ] ) ;
}
}
static void F_32 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_149 * V_150 ;
struct V_155 * V_156 ;
if ( V_2 -> V_27 < 0 )
return;
V_156 = & ( V_12 -> V_157 [ V_158 ] ) ;
V_150 = V_156 -> V_159 [ V_2 -> V_27 ] ;
if ( V_150 ) {
V_150 -> V_21 [ 0 ] -> V_35 [ V_2 -> V_30 ] = 0x02 ;
F_33 ( V_12 , V_150 , V_160 ) ;
}
}
static void F_34 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_149 * V_150 ;
struct V_155 * V_156 ;
int V_161 , V_63 ;
if ( V_2 -> V_33 < 0 )
return;
if ( ! V_2 -> V_13 . V_34 )
return;
V_156 = & V_12 -> V_157 [ V_158 ] ;
V_150 = V_156 -> V_159 [ V_2 -> V_33 ] ;
if ( V_150 ) {
V_63 = V_2 -> V_13 . V_34 ;
V_161 = V_150 -> V_21 [ 0 ] -> V_36 ;
V_63 = F_24 ( V_161 , V_63 ) ;
if ( V_150 -> V_21 [ 0 ] -> V_35 [ 0 ] != V_63 ) {
V_150 -> V_21 [ 0 ] -> V_35 [ 0 ] = V_63 ;
F_33 ( V_12 , V_150 , V_160 ) ;
}
}
}
static void F_35 ( struct V_1 * V_2 )
{
T_3 V_14 = V_2 -> V_13 . V_14 ;
if ( V_2 -> V_97 == 1 ) {
V_14 |= V_40 ;
V_14 &= ~ V_43 ;
V_14 &= ~ V_44 ;
V_14 &= ~ V_45 ;
V_14 &= ~ V_19 ;
}
V_2 -> V_13 . V_14 = V_14 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_58 ;
struct V_64 * V_65 = & V_2 -> V_13 ;
if ( V_2 -> V_97 > 0 ) {
int V_162 = V_57 -> V_59 / V_2 -> V_97 ;
V_2 -> V_148 = V_57 -> V_61 [ V_162 - 1 ] ;
}
if ( V_2 -> V_18 < 0 )
V_65 -> V_14 &= ~ V_19 ;
}
static void F_37 ( struct V_11 * V_12 , struct V_54 * V_55 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_64 * V_65 = & V_2 -> V_13 ;
struct V_46 * V_47 = V_55 -> V_47 ;
if ( ! F_38 ( V_83 , V_47 -> V_163 ) )
return;
if ( ! V_2 -> V_34 )
V_2 -> V_34 = V_164 ;
F_36 ( V_2 ) ;
if ( V_2 -> V_165 )
F_35 ( V_2 ) ;
if ( V_65 -> V_166 )
V_2 -> V_69 |= V_74 ;
if ( V_65 -> V_14 & V_43 )
V_2 -> V_69 |= V_167 ;
F_39 ( V_47 , V_2 -> V_34 , V_2 -> V_69 ) ;
V_2 -> V_69 = 0 ;
}
static int F_40 ( struct V_11 * V_12 , const struct V_168 * V_29 )
{
int V_169 , V_24 ;
struct V_1 * V_2 ;
struct V_64 * V_13 = V_170 ;
for ( V_24 = 0 ; V_170 [ V_24 ] . V_171 ; V_24 ++ ) {
if ( V_29 -> V_172 == V_170 [ V_24 ] . V_171 ) {
V_13 = & ( V_170 [ V_24 ] ) ;
break;
}
}
V_12 -> V_14 |= V_173 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_174 ) ;
if ( ! V_2 ) {
F_42 ( & V_12 -> V_7 , L_2 ) ;
return - V_175 ;
}
V_2 -> V_13 = * V_13 ;
V_2 -> V_27 = - 1 ;
V_2 -> V_33 = - 1 ;
V_2 -> V_18 = - 1 ;
F_43 ( V_12 , V_2 ) ;
V_2 -> V_58 = F_41 ( sizeof( struct V_56 ) , V_174 ) ;
if ( ! V_2 -> V_58 ) {
F_42 ( & V_12 -> V_7 , L_3 ) ;
V_169 = - V_175 ;
goto V_176;
}
if ( V_29 -> V_177 == V_178 && V_29 -> V_179 == V_178 )
V_2 -> V_165 = true ;
V_169 = F_44 ( V_12 ) ;
if ( V_169 != 0 )
goto V_176;
V_169 = F_45 ( V_12 , V_180 ) ;
if ( V_169 )
goto V_176;
V_169 = F_46 ( & V_12 -> V_7 . V_181 , & V_182 ) ;
F_34 ( V_12 ) ;
F_32 ( V_12 ) ;
F_47 ( V_2 -> V_58 ) ;
V_2 -> V_58 = NULL ;
return 0 ;
V_176:
F_47 ( V_2 -> V_58 ) ;
F_47 ( V_2 ) ;
return V_169 ;
}
static int F_48 ( struct V_11 * V_12 )
{
F_34 ( V_12 ) ;
F_32 ( V_12 ) ;
return 0 ;
}
static int F_49 ( struct V_11 * V_12 )
{
struct V_183 * V_184 ;
struct V_185 * V_186 ;
struct V_187 * V_7 ;
if ( V_12 -> V_188 != V_189 )
return 0 ;
V_184 = F_50 ( V_12 -> V_7 . V_190 ) ;
V_186 = V_184 -> V_191 ;
V_7 = F_51 ( V_12 ) ;
F_52 ( V_7 , F_53 ( V_7 , 0 ) ,
V_192 ,
V_193 | V_194 ,
0 , V_186 -> V_195 . V_196 ,
NULL , 0 , V_197 ) ;
return 0 ;
}
static void F_54 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
F_55 ( & V_12 -> V_7 . V_181 , & V_182 ) ;
F_56 ( V_12 ) ;
F_47 ( V_2 ) ;
F_43 ( V_12 , NULL ) ;
}
