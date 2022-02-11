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
return V_15 ;
}
static void F_7 ( struct V_11 * V_12 ,
struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
int V_22 ;
switch ( V_21 -> V_23 ) {
case V_24 :
V_2 -> V_25 = V_19 -> V_26 -> V_27 ;
V_2 -> V_28 = 0 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_29 ; V_22 ++ ) {
if ( V_19 -> V_21 [ V_22 ] . V_23 == V_21 -> V_23 ) {
V_2 -> V_28 = V_22 ;
break;
}
}
break;
case V_30 :
V_2 -> V_31 = V_19 -> V_26 -> V_27 ;
V_2 -> V_32 = V_19 -> V_33 [ 0 ] ;
if ( ! V_2 -> V_32 &&
V_19 -> V_34 <= V_35 )
V_2 -> V_32 = V_19 -> V_34 ;
if ( V_2 -> V_13 . V_32 )
V_2 -> V_32 = V_2 -> V_13 . V_32 ;
break;
case 0xff0000c5 :
if ( V_19 -> V_36 == 256 && V_19 -> V_37 == 8 ) {
T_3 * V_14 = & V_2 -> V_13 . V_14 ;
* V_14 |= V_38 ;
* V_14 |= V_39 ;
* V_14 |= V_40 ;
* V_14 &= ~ V_41 ;
* V_14 &= ~ V_42 ;
* V_14 &= ~ V_43 ;
}
break;
}
}
static void F_8 ( struct V_44 * V_45 , unsigned int V_46 ,
struct V_18 * V_19 , int V_47 )
{
int V_48 = V_19 -> V_49 ;
int V_50 = V_19 -> V_34 ;
int V_51 = V_47 ? ( V_50 - V_48 ) / V_47 : 0 ;
F_9 ( V_45 , V_46 , V_48 , V_50 , V_51 , 0 ) ;
F_10 ( V_45 , V_46 , F_11 ( V_19 , V_46 ) ) ;
}
static void F_12 ( struct V_20 * V_21 , struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = V_2 -> V_56 ;
if ( V_55 -> V_57 >= V_58 )
return;
V_55 -> V_59 [ V_55 -> V_57 ++ ] = V_21 -> V_23 ;
}
static int F_13 ( struct V_11 * V_12 , struct V_52 * V_53 ,
struct V_18 * V_19 , struct V_20 * V_21 ,
unsigned long * * V_60 , int * V_61 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_62 * V_63 = & V_2 -> V_13 ;
int V_46 ;
struct V_20 * V_64 = NULL ;
if ( V_19 -> V_65 == V_66 )
V_2 -> V_67 |= V_68 ;
else if ( V_19 -> V_65 != V_69 )
return 0 ;
if ( V_19 -> V_65 == V_69 ||
( V_21 -> V_23 & V_70 ) == V_71 )
V_2 -> V_67 |= V_72 ;
if ( V_19 -> V_73 == V_74 )
return - 1 ;
if ( V_21 -> V_75 )
V_64 = & V_19 -> V_21 [ V_21 -> V_75 - 1 ] ;
switch ( V_21 -> V_23 & V_70 ) {
case V_76 :
switch ( V_21 -> V_23 ) {
case V_77 :
if ( V_64 && ( V_64 -> V_23 == V_21 -> V_23 ) ) {
F_14 ( V_53 , V_21 , V_60 , V_61 ,
V_78 , V_79 ) ;
F_8 ( V_53 -> V_45 , V_79 , V_19 ,
V_63 -> V_80 ) ;
} else {
F_14 ( V_53 , V_21 , V_60 , V_61 ,
V_78 , V_81 ) ;
F_8 ( V_53 -> V_45 , V_81 , V_19 ,
V_63 -> V_80 ) ;
}
F_12 ( V_21 , V_2 , V_53 ) ;
V_2 -> V_82 = V_19 -> V_83 ;
return 1 ;
case V_84 :
if ( V_64 && ( V_64 -> V_23 == V_21 -> V_23 ) ) {
F_14 ( V_53 , V_21 , V_60 , V_61 ,
V_78 , V_85 ) ;
F_8 ( V_53 -> V_45 , V_85 , V_19 ,
V_63 -> V_80 ) ;
} else {
F_14 ( V_53 , V_21 , V_60 , V_61 ,
V_78 , V_86 ) ;
F_8 ( V_53 -> V_45 , V_86 , V_19 ,
V_63 -> V_80 ) ;
}
F_12 ( V_21 , V_2 , V_53 ) ;
V_2 -> V_82 = V_19 -> V_83 ;
return 1 ;
}
return 0 ;
case V_87 :
switch ( V_21 -> V_23 ) {
case V_88 :
if ( V_63 -> V_14 & V_40 ) {
F_14 ( V_53 , V_21 , V_60 , V_61 ,
V_78 , V_89 ) ;
F_9 ( V_53 -> V_45 ,
V_89 , 0 , 1 , 0 , 0 ) ;
}
F_12 ( V_21 , V_2 , V_53 ) ;
V_2 -> V_82 = V_19 -> V_83 ;
return 1 ;
case V_90 :
F_12 ( V_21 , V_2 , V_53 ) ;
V_2 -> V_82 = V_19 -> V_83 ;
return 1 ;
case V_91 :
F_14 ( V_53 , V_21 , V_60 , V_61 , V_92 , V_93 ) ;
F_15 ( V_53 -> V_45 , V_92 , V_93 ) ;
F_12 ( V_21 , V_2 , V_53 ) ;
V_2 -> V_82 = V_19 -> V_83 ;
return 1 ;
case V_94 :
F_12 ( V_21 , V_2 , V_53 ) ;
V_2 -> V_82 = V_19 -> V_83 ;
V_2 -> V_95 ++ ;
return 1 ;
case V_96 :
F_14 ( V_53 , V_21 , V_60 , V_61 ,
V_78 , V_97 ) ;
if ( ! ( V_63 -> V_14 & V_98 ) )
F_8 ( V_53 -> V_45 , V_97 , V_19 ,
V_63 -> V_99 ) ;
F_12 ( V_21 , V_2 , V_53 ) ;
V_2 -> V_82 = V_19 -> V_83 ;
return 1 ;
case V_100 :
F_14 ( V_53 , V_21 , V_60 , V_61 ,
V_78 , V_101 ) ;
if ( ! ( V_63 -> V_14 & V_98 ) ) {
F_8 ( V_53 -> V_45 , V_101 , V_19 ,
V_63 -> V_102 ) ;
F_9 ( V_53 -> V_45 ,
V_103 , 0 , 1 , 0 , 0 ) ;
}
F_12 ( V_21 , V_2 , V_53 ) ;
V_2 -> V_82 = V_19 -> V_83 ;
return 1 ;
case V_104 :
F_14 ( V_53 , V_21 , V_60 , V_61 ,
V_78 , V_105 ) ;
F_8 ( V_53 -> V_45 , V_105 , V_19 ,
V_63 -> V_106 ) ;
F_12 ( V_21 , V_2 , V_53 ) ;
V_2 -> V_82 = V_19 -> V_83 ;
return 1 ;
case V_107 :
V_2 -> V_82 = V_19 -> V_83 ;
return 1 ;
case V_30 :
V_2 -> V_82 = V_19 -> V_83 ;
return - 1 ;
case V_108 :
return - 1 ;
}
return 0 ;
case V_71 :
V_46 = V_109 + ( ( V_21 -> V_23 - 1 ) & V_110 ) ;
F_14 ( V_53 , V_21 , V_60 , V_61 , V_92 , V_46 ) ;
F_15 ( V_53 -> V_45 , V_92 , V_46 ) ;
return 1 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_12 , struct V_52 * V_53 ,
struct V_18 * V_19 , struct V_20 * V_21 ,
unsigned long * * V_60 , int * V_61 )
{
if ( V_21 -> type == V_92 || V_21 -> type == V_78 )
F_17 ( V_21 -> type , V_53 -> V_45 -> V_111 ) ;
return - 1 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
T_3 V_14 = V_2 -> V_13 . V_14 ;
if ( V_14 & V_112 )
return V_2 -> V_3 . V_4 ;
if ( V_14 & V_113 )
return F_1 ( V_2 ) ;
if ( V_14 & V_114 )
return V_2 -> V_5 ;
if ( V_14 & V_115 )
return V_2 -> V_3 . V_4 - 1 ;
return F_19 ( V_45 , V_2 -> V_3 . V_4 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
if ( V_2 -> V_116 || ( V_2 -> V_13 . V_14 & V_38 ) ) {
int V_117 = F_18 ( V_2 , V_45 ) ;
struct V_118 * V_119 = & V_2 -> V_3 ;
struct V_120 * V_121 = V_45 -> V_121 ;
if ( V_117 < 0 || V_117 >= V_2 -> V_32 )
return;
if ( ( V_2 -> V_13 . V_14 & V_39 ) && V_121 ) {
struct V_122 * V_123 = & V_121 -> V_124 [ V_117 ] ;
if ( F_21 ( V_123 ) &&
F_22 ( V_121 , V_123 ) )
return;
}
V_122 ( V_45 , V_117 ) ;
F_23 ( V_45 , V_125 ,
V_119 -> V_126 || V_119 -> V_127 ) ;
if ( V_119 -> V_126 || V_119 -> V_127 ) {
int V_128 = ( V_119 -> V_129 > V_119 -> V_130 ) ;
int V_131 = V_61 ( V_119 -> V_129 , V_119 -> V_130 ) >> 1 ;
int V_132 = F_24 ( V_119 -> V_129 , V_119 -> V_130 ) >> 1 ;
F_25 ( V_45 , V_78 , V_81 , V_119 -> V_133 ) ;
F_25 ( V_45 , V_78 , V_86 , V_119 -> V_134 ) ;
F_25 ( V_45 , V_78 , V_79 , V_119 -> V_135 ) ;
F_25 ( V_45 , V_78 , V_85 , V_119 -> V_136 ) ;
F_25 ( V_45 , V_78 , V_89 ,
! V_119 -> V_126 ) ;
F_25 ( V_45 , V_78 , V_103 , V_128 ) ;
F_25 ( V_45 , V_78 , V_105 , V_119 -> V_137 ) ;
F_25 ( V_45 , V_78 , V_97 , V_131 ) ;
F_25 ( V_45 , V_78 , V_101 , V_132 ) ;
}
}
V_2 -> V_5 ++ ;
}
static void F_26 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
F_27 ( V_45 ) ;
F_28 ( V_45 ) ;
V_2 -> V_5 = 0 ;
}
static int F_29 ( struct V_11 * V_23 , struct V_18 * V_19 ,
struct V_20 * V_21 , T_3 V_33 )
{
struct V_1 * V_2 = F_4 ( V_23 ) ;
T_3 V_14 = V_2 -> V_13 . V_14 ;
if ( V_23 -> V_138 & V_139 ) {
switch ( V_21 -> V_23 ) {
case V_88 :
if ( V_14 & V_42 )
V_2 -> V_116 = V_33 ;
if ( V_14 & V_40 )
V_2 -> V_3 . V_127 = V_33 ;
break;
case V_91 :
if ( V_14 & V_41 )
V_2 -> V_116 = V_33 ;
V_2 -> V_3 . V_126 = V_33 ;
break;
case V_90 :
if ( V_14 & V_43 )
V_2 -> V_116 = V_33 ;
break;
case V_94 :
V_2 -> V_3 . V_4 = V_33 ;
break;
case V_104 :
V_2 -> V_3 . V_137 = V_33 ;
break;
case V_77 :
if ( V_21 -> V_46 == V_79 )
V_2 -> V_3 . V_135 = V_33 ;
else
V_2 -> V_3 . V_133 = V_33 ;
break;
case V_84 :
if ( V_21 -> V_46 == V_85 )
V_2 -> V_3 . V_136 = V_33 ;
else
V_2 -> V_3 . V_134 = V_33 ;
break;
case V_96 :
V_2 -> V_3 . V_129 = V_33 ;
break;
case V_100 :
V_2 -> V_3 . V_130 = V_33 ;
break;
case V_107 :
if ( V_33 )
V_2 -> V_140 = V_33 ;
break;
case V_108 :
break;
default:
return 0 ;
}
if ( V_21 -> V_75 + 1 == V_19 -> V_36 ) {
if ( V_21 -> V_23 == V_2 -> V_141 )
F_20 ( V_2 , V_19 -> V_142 -> V_45 ) ;
if ( V_19 -> V_83 == V_2 -> V_82
&& V_2 -> V_5 >= V_2 -> V_140 )
F_26 ( V_2 , V_19 -> V_142 -> V_45 ) ;
}
}
if ( V_23 -> V_138 & V_143 && V_23 -> V_144 )
V_23 -> V_144 ( V_23 , V_19 , V_21 , V_33 ) ;
return 1 ;
}
static void F_30 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
if ( V_2 -> V_25 < 0 )
return;
V_148 = & ( V_12 -> V_149 [ V_150 ] ) ;
V_146 = V_148 -> V_151 [ V_2 -> V_25 ] ;
if ( V_146 ) {
V_146 -> V_19 [ 0 ] -> V_33 [ V_2 -> V_28 ] = 0x02 ;
F_31 ( V_12 , V_146 , V_152 ) ;
}
}
static void F_32 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
int V_153 , V_61 ;
if ( V_2 -> V_31 < 0 )
return;
if ( ! V_2 -> V_13 . V_32 )
return;
V_148 = & V_12 -> V_149 [ V_150 ] ;
V_146 = V_148 -> V_151 [ V_2 -> V_31 ] ;
if ( V_146 ) {
V_61 = V_2 -> V_13 . V_32 ;
V_153 = V_146 -> V_19 [ 0 ] -> V_34 ;
V_61 = F_24 ( V_153 , V_61 ) ;
if ( V_146 -> V_19 [ 0 ] -> V_33 [ 0 ] != V_61 ) {
V_146 -> V_19 [ 0 ] -> V_33 [ 0 ] = V_61 ;
F_31 ( V_12 , V_146 , V_152 ) ;
}
}
}
static void F_33 ( struct V_1 * V_2 )
{
T_3 V_14 = V_2 -> V_13 . V_14 ;
if ( V_2 -> V_95 == 1 ) {
V_14 |= V_38 ;
V_14 &= ~ V_41 ;
V_14 &= ~ V_42 ;
V_14 &= ~ V_43 ;
}
V_2 -> V_13 . V_14 = V_14 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_56 ;
if ( V_2 -> V_95 > 0 ) {
int V_154 = V_55 -> V_57 / V_2 -> V_95 ;
V_2 -> V_141 = V_55 -> V_59 [ V_154 - 1 ] ;
}
}
static void F_35 ( struct V_11 * V_12 , struct V_52 * V_53 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_62 * V_63 = & V_2 -> V_13 ;
struct V_44 * V_45 = V_53 -> V_45 ;
if ( ! F_36 ( V_81 , V_45 -> V_155 ) )
return;
if ( ! V_2 -> V_32 )
V_2 -> V_32 = V_156 ;
F_34 ( V_2 ) ;
if ( V_2 -> V_157 )
F_33 ( V_2 ) ;
if ( V_63 -> V_158 )
V_2 -> V_67 |= V_72 ;
if ( V_63 -> V_14 & V_41 )
V_2 -> V_67 |= V_159 ;
F_37 ( V_45 , V_2 -> V_32 , V_2 -> V_67 ) ;
V_2 -> V_67 = 0 ;
}
static int F_38 ( struct V_11 * V_12 , const struct V_160 * V_27 )
{
int V_161 , V_22 ;
struct V_1 * V_2 ;
struct V_62 * V_13 = V_162 ;
for ( V_22 = 0 ; V_162 [ V_22 ] . V_163 ; V_22 ++ ) {
if ( V_27 -> V_164 == V_162 [ V_22 ] . V_163 ) {
V_13 = & ( V_162 [ V_22 ] ) ;
break;
}
}
V_12 -> V_14 |= V_165 ;
V_2 = F_39 ( sizeof( struct V_1 ) , V_166 ) ;
if ( ! V_2 ) {
F_40 ( & V_12 -> V_7 , L_2 ) ;
return - V_167 ;
}
V_2 -> V_13 = * V_13 ;
V_2 -> V_25 = - 1 ;
V_2 -> V_31 = - 1 ;
F_41 ( V_12 , V_2 ) ;
V_2 -> V_56 = F_39 ( sizeof( struct V_54 ) , V_166 ) ;
if ( ! V_2 -> V_56 ) {
F_40 ( & V_12 -> V_7 , L_3 ) ;
V_161 = - V_167 ;
goto V_168;
}
if ( V_27 -> V_169 == V_170 && V_27 -> V_171 == V_170 )
V_2 -> V_157 = true ;
V_161 = F_42 ( V_12 ) ;
if ( V_161 != 0 )
goto V_168;
V_161 = F_43 ( V_12 , V_172 ) ;
if ( V_161 )
goto V_168;
V_161 = F_44 ( & V_12 -> V_7 . V_173 , & V_174 ) ;
F_32 ( V_12 ) ;
F_30 ( V_12 ) ;
F_45 ( V_2 -> V_56 ) ;
V_2 -> V_56 = NULL ;
return 0 ;
V_168:
F_45 ( V_2 -> V_56 ) ;
F_45 ( V_2 ) ;
return V_161 ;
}
static int F_46 ( struct V_11 * V_12 )
{
F_32 ( V_12 ) ;
F_30 ( V_12 ) ;
return 0 ;
}
static int F_47 ( struct V_11 * V_12 )
{
struct V_175 * V_176 ;
struct V_177 * V_178 ;
struct V_179 * V_7 ;
if ( V_12 -> V_180 != V_181 )
return 0 ;
V_176 = F_48 ( V_12 -> V_7 . V_182 ) ;
V_178 = V_176 -> V_183 ;
V_7 = F_49 ( V_12 ) ;
F_50 ( V_7 , F_51 ( V_7 , 0 ) ,
V_184 ,
V_185 | V_186 ,
0 , V_178 -> V_187 . V_188 ,
NULL , 0 , V_189 ) ;
return 0 ;
}
static void F_52 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
F_53 ( & V_12 -> V_7 . V_173 , & V_174 ) ;
F_54 ( V_12 ) ;
F_45 ( V_2 ) ;
F_41 ( V_12 , NULL ) ;
}
static int T_4 F_55 ( void )
{
return F_56 ( & V_190 ) ;
}
static void T_5 F_57 ( void )
{
F_58 ( & V_190 ) ;
}
