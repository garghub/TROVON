static bool F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
return true ;
default:
return false ;
}
}
static T_1 F_2 ( struct V_6 * V_7 , int V_8 )
{
T_2 * V_9 = F_3 ( & V_7 -> V_7 , 0 ) ;
switch ( V_8 ) {
case V_2 :
return V_10 ;
case V_5 :
switch ( ( V_9 [ V_7 -> V_11 + 4 ] >> 6 ) & 0x3 ) {
case 0 :
return V_10 ;
case 1 :
return V_12 ;
case 2 :
return V_13 ;
default:
return 0 ;
}
case V_3 :
case V_4 :
switch ( ( V_9 [ V_7 -> V_11 + 5 ] >> 3 ) & 0x7 ) {
case 1 :
return V_10 ;
case 2 :
return V_12 ;
case 3 :
return V_13 ;
default:
return 0 ;
}
}
return 0 ;
}
static void F_4 ( struct V_14 * V_15 , int * V_16 , int * V_17 )
{
switch ( V_15 -> V_18 ) {
case V_19 :
* V_16 = 720 ;
* V_17 = 480 ;
break;
case V_20 :
* V_16 = 720 ;
* V_17 = 576 ;
break;
case V_21 :
default:
* V_16 = V_15 -> V_22 -> V_23 ;
* V_17 = V_15 -> V_22 -> V_24 ;
break;
}
}
static void F_5 ( struct V_14 * V_15 )
{
if ( V_15 -> V_8 == V_2 ) {
V_15 -> V_25 = 0 ;
V_15 -> V_26 = V_27 ;
V_15 -> V_28 = 0 ;
V_15 -> V_29 = 0 ;
V_15 -> V_30 = 0 ;
V_15 -> V_31 = 0 ;
V_15 -> V_32 = 0 ;
V_15 -> V_33 = 0 ;
V_15 -> V_34 = 0 ;
return;
}
switch ( V_15 -> V_8 ) {
case V_3 :
V_15 -> V_25 = 0 ;
break;
default:
case V_4 :
V_15 -> V_25 = 0x48 ;
break;
case V_5 :
V_15 -> V_25 = 0xf5 ;
break;
}
V_15 -> V_28 = F_6 ( V_15 -> V_35 ) ;
V_15 -> V_30 = F_6 ( V_15 -> V_36 ) ;
V_15 -> V_29 = F_6 ( V_15 -> V_37 ) != 0 ;
V_15 -> V_38 = F_6 ( V_15 -> V_39 ) ;
V_15 -> V_31 = F_6 ( V_15 -> V_40 ) ;
V_15 -> V_33 = 1 ;
V_15 -> V_34 = 0 ;
if ( V_15 -> V_8 == V_4 )
V_15 -> V_34 =
V_15 -> V_38 == 9800000 &&
V_15 -> V_28 == 15 &&
V_15 -> V_29 == 0 &&
V_15 -> V_31 == 1 &&
V_15 -> V_30 ;
switch ( F_6 ( V_15 -> V_41 ) ) {
default:
case V_42 :
V_15 -> V_26 = V_27 ;
break;
case V_43 :
V_15 -> V_26 = V_44 ;
break;
case V_45 :
V_15 -> V_26 = V_46 ;
break;
}
}
static int F_7 ( struct V_14 * V_15 , struct V_47 * V_48 , int V_49 )
{
int V_24 = 0 , V_23 = 0 ;
int V_16 , V_17 ;
if ( V_48 != NULL && ! F_1 ( V_48 -> V_48 . V_50 . V_1 ) )
return - V_51 ;
F_4 ( V_15 , & V_23 , & V_24 ) ;
if ( V_48 == NULL ) {
V_16 = V_23 ;
V_17 = V_24 ;
} else if ( V_15 -> V_22 -> V_52 & V_53 ) {
if ( V_48 -> V_48 . V_50 . V_16 > V_23 )
V_16 = V_23 ;
else if ( V_48 -> V_48 . V_50 . V_16 < 144 )
V_16 = 144 ;
else
V_16 = V_48 -> V_48 . V_50 . V_16 & ~ 0x0f ;
if ( V_48 -> V_48 . V_50 . V_17 > V_24 )
V_17 = V_24 ;
else if ( V_48 -> V_48 . V_50 . V_17 < 96 )
V_17 = 96 ;
else
V_17 = V_48 -> V_48 . V_50 . V_17 & ~ 0x0f ;
} else {
V_16 = V_48 -> V_48 . V_50 . V_16 ;
if ( V_16 <= V_23 / 4 ) {
V_16 = V_23 / 4 ;
V_17 = V_24 / 4 ;
} else if ( V_16 <= V_23 / 2 ) {
V_16 = V_23 / 2 ;
V_17 = V_24 / 2 ;
} else {
V_16 = V_23 ;
V_17 = V_24 ;
}
V_16 &= ~ 0xf ;
V_17 &= ~ 0xf ;
}
if ( V_48 != NULL ) {
T_1 V_1 = V_48 -> V_48 . V_50 . V_1 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> type = V_54 ;
V_48 -> V_48 . V_50 . V_16 = V_16 ;
V_48 -> V_48 . V_50 . V_17 = V_17 ;
V_48 -> V_48 . V_50 . V_1 = V_1 ;
V_48 -> V_48 . V_50 . V_55 = V_56 ;
V_48 -> V_48 . V_50 . V_57 = 0 ;
V_48 -> V_48 . V_50 . V_58 = V_59 ;
V_48 -> V_48 . V_50 . V_60 = V_61 ;
}
if ( V_49 )
return 0 ;
if ( V_48 )
V_15 -> V_8 = V_48 -> V_48 . V_50 . V_1 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_62 = V_15 -> V_22 -> V_63 ;
V_15 -> V_64 = V_15 -> V_22 -> V_65 ;
if ( V_15 -> V_22 -> V_52 & V_53 ) {
struct V_66 V_8 = {
. V_67 = V_68 ,
} ;
V_8 . V_8 . V_69 = V_70 ;
V_8 . V_8 . V_16 = V_48 ? V_48 -> V_48 . V_50 . V_16 : V_16 ;
V_8 . V_8 . V_17 = V_17 ;
V_15 -> V_71 = 0 ;
V_15 -> V_72 = 0 ;
V_15 -> V_73 = 0 ;
F_8 ( & V_15 -> V_74 , V_75 , V_76 , NULL , & V_8 ) ;
} else {
if ( V_16 <= V_23 / 4 ) {
V_15 -> V_71 = 1 ;
V_15 -> V_72 = 1 ;
V_15 -> V_73 = 1 ;
} else if ( V_16 <= V_23 / 2 ) {
V_15 -> V_71 = 1 ;
V_15 -> V_72 = 1 ;
V_15 -> V_73 = 0 ;
} else {
V_15 -> V_71 = 0 ;
V_15 -> V_72 = 0 ;
V_15 -> V_73 = 0 ;
}
}
return 0 ;
}
static int F_9 ( struct V_77 * V_77 , void * V_78 ,
struct V_79 * V_80 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
F_11 ( V_80 -> V_81 , L_1 , sizeof( V_80 -> V_81 ) ) ;
F_11 ( V_80 -> V_82 , V_15 -> V_83 , sizeof( V_80 -> V_82 ) ) ;
F_11 ( V_80 -> V_84 , V_15 -> V_84 , sizeof( V_80 -> V_84 ) ) ;
V_80 -> V_85 = V_86 | V_87 |
V_88 ;
if ( V_15 -> V_22 -> V_89 )
V_80 -> V_85 |= V_90 ;
if ( V_15 -> V_22 -> V_91 & V_92 )
V_80 -> V_85 |= V_93 ;
V_80 -> V_94 = V_80 -> V_85 | V_95 ;
return 0 ;
}
static int F_12 ( struct V_77 * V_77 , void * V_78 ,
struct V_96 * V_48 )
{
char * V_97 = NULL ;
switch ( V_48 -> V_98 ) {
case 0 :
V_48 -> V_1 = V_2 ;
V_97 = L_2 ;
break;
case 1 :
V_48 -> V_1 = V_3 ;
V_97 = L_3 ;
break;
case 2 :
V_48 -> V_1 = V_4 ;
V_97 = L_4 ;
break;
case 3 :
V_48 -> V_1 = V_5 ;
V_97 = L_5 ;
break;
default:
return - V_51 ;
}
V_48 -> type = V_54 ;
V_48 -> V_91 = V_99 ;
strncpy ( V_48 -> V_100 , V_97 , sizeof( V_48 -> V_100 ) ) ;
return 0 ;
}
static int F_13 ( struct V_77 * V_77 , void * V_78 ,
struct V_47 * V_48 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
V_48 -> type = V_54 ;
V_48 -> V_48 . V_50 . V_16 = V_15 -> V_16 ;
V_48 -> V_48 . V_50 . V_17 = V_15 -> V_17 ;
V_48 -> V_48 . V_50 . V_1 = V_15 -> V_8 ;
V_48 -> V_48 . V_50 . V_55 = V_56 ;
V_48 -> V_48 . V_50 . V_57 = 0 ;
V_48 -> V_48 . V_50 . V_58 = V_59 ;
V_48 -> V_48 . V_50 . V_60 = V_61 ;
return 0 ;
}
static int F_14 ( struct V_77 * V_77 , void * V_78 ,
struct V_47 * V_48 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
return F_7 ( V_15 , V_48 , 1 ) ;
}
static int F_15 ( struct V_77 * V_77 , void * V_78 ,
struct V_47 * V_48 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
if ( F_16 ( & V_15 -> V_101 ) )
return - V_102 ;
return F_7 ( V_15 , V_48 , 0 ) ;
}
static int F_17 ( struct V_103 * V_104 ,
const struct V_47 * V_48 ,
unsigned int * V_105 , unsigned int * V_106 ,
unsigned int V_107 [] , void * V_108 [] )
{
V_107 [ 0 ] = V_59 ;
* V_106 = 1 ;
if ( * V_105 < 2 )
* V_105 = 2 ;
return 0 ;
}
static void F_18 ( struct V_109 * V_7 )
{
struct V_103 * V_110 = V_7 -> V_103 ;
struct V_14 * V_15 = F_19 ( V_110 ) ;
struct V_6 * V_111 =
F_20 ( V_7 , struct V_6 , V_7 ) ;
unsigned long V_91 ;
F_21 ( & V_15 -> V_112 , V_91 ) ;
F_22 ( & V_111 -> V_113 , & V_15 -> V_114 ) ;
F_23 ( & V_15 -> V_112 , V_91 ) ;
}
static int F_24 ( struct V_109 * V_7 )
{
struct V_6 * V_111 =
F_20 ( V_7 , struct V_6 , V_7 ) ;
V_111 -> V_115 = 0 ;
V_111 -> V_11 = 0 ;
V_7 -> V_116 [ 0 ] . V_117 = 0 ;
return 0 ;
}
static void F_25 ( struct V_109 * V_7 )
{
struct V_103 * V_110 = V_7 -> V_103 ;
struct V_14 * V_15 = F_19 ( V_110 ) ;
struct V_6 * V_111 =
F_20 ( V_7 , struct V_6 , V_7 ) ;
T_1 V_118 = F_2 ( V_111 , V_15 -> V_8 ) ;
struct V_119 * V_120 = & V_7 -> V_121 ;
V_120 -> V_91 &= ~ ( V_10 | V_13 |
V_12 ) ;
V_120 -> V_91 |= V_118 ;
V_120 -> V_55 = V_56 ;
}
static int F_26 ( struct V_103 * V_104 , unsigned int V_122 )
{
struct V_14 * V_15 = F_19 ( V_104 ) ;
int V_123 ;
F_5 ( V_15 ) ;
F_27 ( & V_15 -> V_124 ) ;
V_15 -> V_125 = 0 ;
V_15 -> V_126 = NULL ;
V_15 -> V_127 = 0 ;
V_104 -> V_128 = 1 ;
if ( F_28 ( V_15 ) < 0 )
V_123 = - V_129 ;
else
V_123 = 0 ;
F_29 ( & V_15 -> V_124 ) ;
if ( V_123 ) {
V_104 -> V_128 = 0 ;
return V_123 ;
}
F_8 ( & V_15 -> V_74 , V_130 , V_131 , 1 ) ;
F_30 ( V_15 -> V_35 , true ) ;
F_30 ( V_15 -> V_36 , true ) ;
F_30 ( V_15 -> V_39 , true ) ;
F_30 ( V_15 -> V_41 , true ) ;
if ( V_15 -> V_132 == V_133 )
F_31 ( V_15 , 0x3c82 , 0x0005 ) ;
return V_123 ;
}
static void F_32 ( struct V_103 * V_104 )
{
struct V_14 * V_15 = F_19 ( V_104 ) ;
unsigned long V_91 ;
V_104 -> V_128 = 0 ;
F_33 ( V_15 ) ;
F_27 ( & V_15 -> V_124 ) ;
F_34 ( V_15 ) ;
F_29 ( & V_15 -> V_124 ) ;
F_8 ( & V_15 -> V_74 , V_130 , V_131 , 0 ) ;
F_21 ( & V_15 -> V_112 , V_91 ) ;
F_35 ( & V_15 -> V_114 ) ;
F_23 ( & V_15 -> V_112 , V_91 ) ;
F_30 ( V_15 -> V_35 , false ) ;
F_30 ( V_15 -> V_36 , false ) ;
F_30 ( V_15 -> V_39 , false ) ;
F_30 ( V_15 -> V_41 , false ) ;
if ( V_15 -> V_132 == V_133 )
F_31 ( V_15 , 0x3c82 , 0x000d ) ;
}
static int F_36 ( struct V_77 * V_134 , void * V_78 ,
struct V_135 * V_136 )
{
struct V_14 * V_15 = F_10 ( V_134 ) ;
struct V_137 V_138 = {
. V_139 = 1001 * V_15 -> V_140 ,
. V_141 = V_15 -> V_142 ,
} ;
if ( V_136 -> type != V_54 )
return - V_51 ;
V_136 -> V_136 . V_143 . V_144 = 2 ;
V_136 -> V_136 . V_143 . V_145 = V_146 ;
V_136 -> V_136 . V_143 . V_138 = V_138 ;
return 0 ;
}
static int F_37 ( struct V_77 * V_134 , void * V_78 ,
struct V_135 * V_136 )
{
struct V_14 * V_15 = F_10 ( V_134 ) ;
unsigned int V_147 , V_148 ;
if ( V_136 -> type != V_54 )
return - V_51 ;
V_147 = V_15 -> V_142 *
V_136 -> V_136 . V_143 . V_138 . V_139 ;
V_148 = 1001 * V_136 -> V_136 . V_143 . V_138 . V_141 ;
if ( V_147 != 0 && V_148 != 0 && V_147 > V_148 )
V_15 -> V_140 = ( V_147 + V_148 / 2 ) / V_148 ;
else
V_15 -> V_140 = 1 ;
return F_36 ( V_134 , V_78 , V_136 ) ;
}
static int F_38 ( struct V_77 * V_134 , void * V_78 ,
struct V_149 * V_150 )
{
struct V_14 * V_15 = F_10 ( V_134 ) ;
int V_16 , V_17 ;
if ( V_150 -> V_98 > 2 )
return - V_51 ;
if ( ! F_1 ( V_150 -> V_151 ) )
return - V_51 ;
F_4 ( V_15 , & V_16 , & V_17 ) ;
V_150 -> type = V_152 ;
V_150 -> V_153 . V_16 = ( V_16 >> V_150 -> V_98 ) & ~ 0xf ;
V_150 -> V_153 . V_17 = ( V_17 >> V_150 -> V_98 ) & ~ 0xf ;
return 0 ;
}
static int F_39 ( struct V_77 * V_134 , void * V_78 ,
struct V_154 * V_155 )
{
struct V_14 * V_15 = F_10 ( V_134 ) ;
int V_16 , V_17 ;
int V_156 ;
if ( V_155 -> V_98 > 4 )
return - V_51 ;
if ( ! F_1 ( V_155 -> V_151 ) )
return - V_51 ;
if ( ! ( V_15 -> V_22 -> V_52 & V_53 ) ) {
F_4 ( V_15 , & V_16 , & V_17 ) ;
for ( V_156 = 0 ; V_156 <= 2 ; V_156 ++ )
if ( V_155 -> V_16 == ( ( V_16 >> V_156 ) & ~ 0xf ) &&
V_155 -> V_17 == ( ( V_17 >> V_156 ) & ~ 0xf ) )
break;
if ( V_156 > 2 )
return - V_51 ;
}
V_155 -> type = V_157 ;
V_155 -> V_153 . V_139 = 1001 * ( V_155 -> V_98 + 1 ) ;
V_155 -> V_153 . V_141 = V_15 -> V_142 ;
return 0 ;
}
static int F_40 ( struct V_77 * V_77 , void * V_78 , T_3 * V_158 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
* V_158 = V_15 -> V_158 ;
return 0 ;
}
static int F_41 ( struct V_14 * V_15 )
{
if ( V_15 -> V_158 & V_159 ) {
V_15 -> V_18 = V_20 ;
V_15 -> V_142 = 25025 ;
} else {
V_15 -> V_18 = V_19 ;
V_15 -> V_142 = 30000 ;
}
F_8 ( & V_15 -> V_74 , V_130 , V_160 , V_15 -> V_158 ) ;
F_7 ( V_15 , NULL , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_77 * V_77 , void * V_78 , T_3 V_158 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
if ( F_16 ( & V_15 -> V_101 ) )
return - V_102 ;
V_15 -> V_158 = V_158 ;
return F_41 ( V_15 ) ;
}
static int F_43 ( struct V_77 * V_77 , void * V_78 , T_3 * V_158 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
return F_8 ( & V_15 -> V_74 , V_130 , V_161 , V_158 ) ;
}
static int F_44 ( struct V_77 * V_77 , void * V_78 ,
struct V_162 * V_163 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
if ( V_163 -> V_98 >= V_15 -> V_22 -> V_164 )
return - V_51 ;
strncpy ( V_163 -> V_83 , V_15 -> V_22 -> V_165 [ V_163 -> V_98 ] . V_83 ,
sizeof( V_163 -> V_83 ) ) ;
if ( ( V_15 -> V_22 -> V_91 & V_92 ) &&
V_163 -> V_98 == 0 )
V_163 -> type = V_166 ;
else
V_163 -> type = V_167 ;
if ( V_15 -> V_22 -> V_89 )
V_163 -> V_168 = ( 1 << V_15 -> V_22 -> V_89 ) - 1 ;
else
V_163 -> V_168 = 0 ;
V_163 -> V_169 = 0 ;
if ( V_15 -> V_22 -> V_52 & V_170 )
V_163 -> V_158 = F_45 ( V_77 ) -> V_171 ;
else
V_163 -> V_158 = 0 ;
return 0 ;
}
static int F_46 ( struct V_77 * V_77 , void * V_78 , unsigned int * V_172 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
* V_172 = V_15 -> V_172 ;
return 0 ;
}
static int F_47 ( struct V_77 * V_77 , void * V_173 , struct V_174 * V_175 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
if ( V_175 -> V_98 >= V_15 -> V_22 -> V_89 )
return - V_51 ;
F_11 ( V_175 -> V_83 , V_15 -> V_22 -> V_176 [ V_175 -> V_98 ] . V_83 ,
sizeof( V_175 -> V_83 ) ) ;
V_175 -> V_145 = V_177 ;
return 0 ;
}
static int F_48 ( struct V_77 * V_77 , void * V_173 , struct V_174 * V_175 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
V_175 -> V_98 = V_15 -> V_178 ;
F_11 ( V_175 -> V_83 , V_15 -> V_22 -> V_176 [ V_15 -> V_178 ] . V_83 ,
sizeof( V_175 -> V_83 ) ) ;
V_175 -> V_145 = V_177 ;
return 0 ;
}
static int F_49 ( struct V_77 * V_77 , void * V_173 ,
const struct V_174 * V_175 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
if ( V_175 -> V_98 >= V_15 -> V_22 -> V_89 )
return - V_51 ;
V_15 -> V_178 = V_175 -> V_98 ;
F_50 ( V_15 -> V_179 , V_180 , V_181 ,
V_15 -> V_22 -> V_176 [ V_15 -> V_178 ] . V_182 , 0 , 0 ) ;
return 0 ;
}
static void F_51 ( struct V_14 * V_15 )
{
unsigned int V_172 = V_15 -> V_172 ;
F_50 ( V_15 -> V_183 , V_130 , V_181 ,
V_15 -> V_22 -> V_165 [ V_172 ] . V_184 , 0 ,
V_15 -> V_22 -> V_185 ) ;
if ( V_15 -> V_22 -> V_89 ) {
int V_178 = V_15 -> V_22 -> V_165 [ V_172 ] . V_186 ;
F_50 ( V_15 -> V_179 , V_180 , V_181 ,
V_15 -> V_22 -> V_176 [ V_178 ] . V_182 , 0 , 0 ) ;
V_15 -> V_178 = V_178 ;
}
}
static int F_52 ( struct V_77 * V_77 , void * V_78 , unsigned int V_172 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
if ( V_172 >= V_15 -> V_22 -> V_164 )
return - V_51 ;
if ( F_16 ( & V_15 -> V_101 ) )
return - V_102 ;
V_15 -> V_172 = V_172 ;
F_51 ( V_15 ) ;
return 0 ;
}
static int F_53 ( struct V_77 * V_77 , void * V_78 ,
struct V_187 * V_188 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
if ( V_188 -> V_98 != 0 )
return - V_51 ;
F_11 ( V_188 -> V_83 , L_6 , sizeof( V_188 -> V_83 ) ) ;
return F_8 ( & V_15 -> V_74 , V_169 , V_189 , V_188 ) ;
}
static int F_54 ( struct V_77 * V_77 , void * V_78 ,
const struct V_187 * V_188 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
if ( V_188 -> V_98 != 0 )
return - V_51 ;
return F_8 ( & V_15 -> V_74 , V_169 , V_190 , V_188 ) ;
}
static int F_55 ( struct V_77 * V_77 , void * V_78 ,
struct V_191 * V_192 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
if ( V_192 -> V_169 )
return - V_51 ;
return F_8 ( & V_15 -> V_74 , V_169 , V_193 , V_192 ) ;
}
static int F_56 ( struct V_77 * V_77 , void * V_78 ,
const struct V_191 * V_192 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
if ( V_192 -> V_169 )
return - V_51 ;
return F_8 ( & V_15 -> V_74 , V_169 , V_194 , V_192 ) ;
}
static int F_57 ( struct V_77 * V_77 , void * V_78 )
{
struct V_14 * V_15 = F_10 ( V_77 ) ;
F_58 ( V_77 , V_78 ) ;
return F_8 ( & V_15 -> V_74 , V_195 , V_196 ) ;
}
static int F_59 ( struct V_197 * V_173 ,
const struct V_198 * V_199 )
{
switch ( V_199 -> type ) {
case V_200 :
return F_60 ( V_173 , V_199 ) ;
case V_201 :
return F_61 ( V_173 , V_199 , 30 , NULL ) ;
}
return - V_51 ;
}
static int F_62 ( struct V_202 * V_203 )
{
struct V_14 * V_15 =
F_20 ( V_203 -> V_204 , struct V_14 , V_205 ) ;
unsigned V_206 ;
T_2 * V_207 ;
switch ( V_203 -> V_208 ) {
case V_209 :
V_15 -> V_210 [ 0 ] . V_211 = V_203 -> V_212 ;
break;
case V_213 :
V_15 -> V_210 [ 0 ] . V_214 = V_203 -> V_212 ;
break;
case V_215 :
V_15 -> V_210 [ 0 ] . V_216 = V_203 -> V_212 ;
break;
case V_217 :
V_15 -> V_210 [ 1 ] . V_211 = V_203 -> V_212 ;
break;
case V_218 :
V_15 -> V_210 [ 1 ] . V_214 = V_203 -> V_212 ;
break;
case V_219 :
V_15 -> V_210 [ 1 ] . V_216 = V_203 -> V_212 ;
break;
case V_220 :
V_15 -> V_210 [ 2 ] . V_211 = V_203 -> V_212 ;
break;
case V_221 :
V_15 -> V_210 [ 2 ] . V_214 = V_203 -> V_212 ;
break;
case V_222 :
V_15 -> V_210 [ 2 ] . V_216 = V_203 -> V_212 ;
break;
case V_223 :
V_15 -> V_210 [ 3 ] . V_211 = V_203 -> V_212 ;
break;
case V_224 :
V_15 -> V_210 [ 3 ] . V_214 = V_203 -> V_212 ;
break;
case V_225 :
V_15 -> V_210 [ 3 ] . V_216 = V_203 -> V_212 ;
break;
case V_226 :
V_207 = V_15 -> V_227 ;
for ( V_206 = 0 ; V_206 < V_15 -> V_17 / 16 ; V_206 ++ , V_207 += V_15 -> V_16 / 16 )
memcpy ( V_207 , V_203 -> V_228 . V_229 + V_206 * ( 720 / 16 ) , V_15 -> V_16 / 16 ) ;
break;
default:
return - V_51 ;
}
return 0 ;
}
int F_63 ( struct V_14 * V_15 )
{
struct V_230 * V_205 = & V_15 -> V_205 ;
struct V_202 * V_203 ;
F_64 ( V_205 , 22 ) ;
V_15 -> V_35 = F_65 ( V_205 , NULL ,
V_231 , 0 , 34 , 1 , 15 ) ;
V_15 -> V_36 = F_65 ( V_205 , NULL ,
V_232 , 0 , 1 , 1 , 1 ) ;
V_15 -> V_39 = F_65 ( V_205 , NULL ,
V_233 ,
64000 , 10000000 , 1 , 9800000 ) ;
V_15 -> V_37 = F_65 ( V_205 , NULL ,
V_234 , 0 , 2 , 2 , 0 ) ;
V_15 -> V_40 = F_65 ( V_205 , NULL ,
V_235 , 0 , 1 , 1 , 1 ) ;
V_15 -> V_41 = F_66 ( V_205 , NULL ,
V_236 ,
V_45 , 0 ,
V_42 ) ;
V_203 = F_65 ( V_205 , NULL ,
V_237 , 0 ,
V_238 |
V_239 , 0 ,
V_238 |
V_239 ) ;
if ( V_203 )
V_203 -> V_91 |= V_240 ;
F_67 ( V_205 , & V_241 , NULL ) ;
F_67 ( V_205 , & V_242 , NULL ) ;
F_67 ( V_205 , & V_243 , NULL ) ;
F_67 ( V_205 , & V_244 , NULL ) ;
F_67 ( V_205 , & V_245 , NULL ) ;
F_67 ( V_205 , & V_246 , NULL ) ;
F_67 ( V_205 , & V_247 , NULL ) ;
F_67 ( V_205 , & V_248 , NULL ) ;
F_67 ( V_205 , & V_249 , NULL ) ;
F_67 ( V_205 , & V_250 , NULL ) ;
F_67 ( V_205 , & V_251 , NULL ) ;
F_67 ( V_205 , & V_252 , NULL ) ;
F_67 ( V_205 , & V_253 , NULL ) ;
V_15 -> V_254 = F_66 ( V_205 , NULL ,
V_255 ,
V_256 ,
1 << V_257 ,
V_258 ) ;
if ( V_205 -> error ) {
int V_259 = V_205 -> error ;
F_68 ( & V_15 -> V_74 , L_7 ) ;
return V_259 ;
}
V_15 -> V_74 . V_260 = V_205 ;
return 0 ;
}
int F_69 ( struct V_14 * V_15 )
{
struct V_261 * V_262 = & V_15 -> V_262 ;
int V_259 ;
F_70 ( & V_15 -> V_263 ) ;
F_70 ( & V_15 -> V_264 ) ;
F_35 ( & V_15 -> V_114 ) ;
V_15 -> V_101 . type = V_54 ;
V_15 -> V_101 . V_265 = V_266 | V_267 | V_268 ;
V_15 -> V_101 . V_269 = & V_270 ;
V_15 -> V_101 . V_271 = & V_272 ;
V_15 -> V_101 . V_273 = V_15 ;
V_15 -> V_101 . V_274 = sizeof( struct V_6 ) ;
V_15 -> V_101 . V_275 = V_276 ;
V_15 -> V_101 . V_277 = & V_15 -> V_264 ;
V_259 = F_71 ( & V_15 -> V_101 ) ;
if ( V_259 )
return V_259 ;
* V_262 = V_278 ;
V_262 -> V_277 = & V_15 -> V_263 ;
V_262 -> V_279 = & V_15 -> V_101 ;
F_72 ( V_262 , V_15 ) ;
V_262 -> V_74 = & V_15 -> V_74 ;
if ( ! F_73 ( & V_15 -> V_74 , V_130 , V_161 ) )
F_74 ( V_262 , V_280 ) ;
if ( ! ( V_15 -> V_22 -> V_91 & V_92 ) ) {
F_74 ( V_262 , V_281 ) ;
F_74 ( V_262 , V_282 ) ;
F_74 ( V_262 , V_283 ) ;
F_74 ( V_262 , V_284 ) ;
} else {
struct V_191 V_192 = {
. type = V_285 ,
. V_286 = 980 ,
} ;
F_8 ( & V_15 -> V_74 , V_169 , V_194 , & V_192 ) ;
}
if ( ! ( V_15 -> V_22 -> V_52 & V_170 ) ) {
F_74 ( V_262 , V_287 ) ;
F_74 ( V_262 , V_288 ) ;
V_262 -> V_171 = 0 ;
}
if ( V_15 -> V_22 -> V_52 & V_53 )
F_74 ( V_262 , V_289 ) ;
if ( V_15 -> V_22 -> V_89 == 0 ) {
F_74 ( V_262 , V_290 ) ;
F_74 ( V_262 , V_291 ) ;
F_74 ( V_262 , V_292 ) ;
}
if ( V_15 -> V_22 -> V_52 & V_293 )
F_50 ( V_15 -> V_183 , V_130 , V_294 ,
V_295 ,
V_296 | V_297 |
V_298 ) ;
F_51 ( V_15 ) ;
if ( V_15 -> V_22 -> V_52 & V_170 )
F_41 ( V_15 ) ;
V_259 = F_75 ( V_262 , V_299 , - 1 ) ;
if ( V_259 < 0 )
return V_259 ;
F_76 ( V_15 -> V_300 , L_8 ,
F_77 ( V_262 ) ) ;
return 0 ;
}
void F_78 ( struct V_14 * V_15 )
{
F_79 ( & V_15 -> V_205 ) ;
}
