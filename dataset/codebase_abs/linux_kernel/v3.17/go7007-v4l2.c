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
struct V_66 V_67 ;
V_67 . V_68 = V_69 ;
V_67 . V_16 = V_48 ? V_48 -> V_48 . V_50 . V_16 : V_16 ;
V_67 . V_17 = V_17 ;
V_15 -> V_70 = 0 ;
V_15 -> V_71 = 0 ;
V_15 -> V_72 = 0 ;
F_8 ( & V_15 -> V_73 , V_74 , V_75 , & V_67 ) ;
} else {
if ( V_16 <= V_23 / 4 ) {
V_15 -> V_70 = 1 ;
V_15 -> V_71 = 1 ;
V_15 -> V_72 = 1 ;
} else if ( V_16 <= V_23 / 2 ) {
V_15 -> V_70 = 1 ;
V_15 -> V_71 = 1 ;
V_15 -> V_72 = 0 ;
} else {
V_15 -> V_70 = 0 ;
V_15 -> V_71 = 0 ;
V_15 -> V_72 = 0 ;
}
}
return 0 ;
}
static int F_9 ( struct V_76 * V_76 , void * V_77 ,
struct V_78 * V_79 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
F_11 ( V_79 -> V_80 , L_1 , sizeof( V_79 -> V_80 ) ) ;
F_11 ( V_79 -> V_81 , V_15 -> V_82 , sizeof( V_79 -> V_81 ) ) ;
F_11 ( V_79 -> V_83 , V_15 -> V_83 , sizeof( V_79 -> V_83 ) ) ;
V_79 -> V_84 = V_85 | V_86 |
V_87 ;
if ( V_15 -> V_22 -> V_88 )
V_79 -> V_84 |= V_89 ;
if ( V_15 -> V_22 -> V_90 & V_91 )
V_79 -> V_84 |= V_92 ;
V_79 -> V_93 = V_79 -> V_84 | V_94 ;
return 0 ;
}
static int F_12 ( struct V_76 * V_76 , void * V_77 ,
struct V_95 * V_48 )
{
char * V_96 = NULL ;
switch ( V_48 -> V_97 ) {
case 0 :
V_48 -> V_1 = V_2 ;
V_96 = L_2 ;
break;
case 1 :
V_48 -> V_1 = V_3 ;
V_96 = L_3 ;
break;
case 2 :
V_48 -> V_1 = V_4 ;
V_96 = L_4 ;
break;
case 3 :
V_48 -> V_1 = V_5 ;
V_96 = L_5 ;
break;
default:
return - V_51 ;
}
V_48 -> type = V_54 ;
V_48 -> V_90 = V_98 ;
strncpy ( V_48 -> V_99 , V_96 , sizeof( V_48 -> V_99 ) ) ;
return 0 ;
}
static int F_13 ( struct V_76 * V_76 , void * V_77 ,
struct V_47 * V_48 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
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
static int F_14 ( struct V_76 * V_76 , void * V_77 ,
struct V_47 * V_48 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
return F_7 ( V_15 , V_48 , 1 ) ;
}
static int F_15 ( struct V_76 * V_76 , void * V_77 ,
struct V_47 * V_48 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
if ( F_16 ( & V_15 -> V_100 ) )
return - V_101 ;
return F_7 ( V_15 , V_48 , 0 ) ;
}
static int F_17 ( struct V_102 * V_103 ,
const struct V_47 * V_48 ,
unsigned int * V_104 , unsigned int * V_105 ,
unsigned int V_106 [] , void * V_107 [] )
{
V_106 [ 0 ] = V_59 ;
* V_105 = 1 ;
if ( * V_104 < 2 )
* V_104 = 2 ;
return 0 ;
}
static void F_18 ( struct V_108 * V_7 )
{
struct V_102 * V_109 = V_7 -> V_102 ;
struct V_14 * V_15 = F_19 ( V_109 ) ;
struct V_6 * V_110 =
F_20 ( V_7 , struct V_6 , V_7 ) ;
unsigned long V_90 ;
F_21 ( & V_15 -> V_111 , V_90 ) ;
F_22 ( & V_110 -> V_112 , & V_15 -> V_113 ) ;
F_23 ( & V_15 -> V_111 , V_90 ) ;
}
static int F_24 ( struct V_108 * V_7 )
{
struct V_6 * V_110 =
F_20 ( V_7 , struct V_6 , V_7 ) ;
V_110 -> V_114 = 0 ;
V_110 -> V_11 = 0 ;
V_7 -> V_115 [ 0 ] . V_116 = 0 ;
return 0 ;
}
static void F_25 ( struct V_108 * V_7 )
{
struct V_102 * V_109 = V_7 -> V_102 ;
struct V_14 * V_15 = F_19 ( V_109 ) ;
struct V_6 * V_110 =
F_20 ( V_7 , struct V_6 , V_7 ) ;
T_1 V_117 = F_2 ( V_110 , V_15 -> V_8 ) ;
struct V_118 * V_119 = & V_7 -> V_120 ;
V_119 -> V_90 &= ~ ( V_10 | V_13 |
V_12 ) ;
V_119 -> V_90 |= V_117 ;
V_119 -> V_55 = V_56 ;
}
static int F_26 ( struct V_102 * V_103 , unsigned int V_121 )
{
struct V_14 * V_15 = F_19 ( V_103 ) ;
int V_122 ;
F_5 ( V_15 ) ;
F_27 ( & V_15 -> V_123 ) ;
V_15 -> V_124 = 0 ;
V_15 -> V_125 = NULL ;
V_15 -> V_126 = 0 ;
V_103 -> V_127 = 1 ;
if ( F_28 ( V_15 ) < 0 )
V_122 = - V_128 ;
else
V_122 = 0 ;
F_29 ( & V_15 -> V_123 ) ;
if ( V_122 ) {
V_103 -> V_127 = 0 ;
return V_122 ;
}
F_8 ( & V_15 -> V_73 , V_74 , V_129 , 1 ) ;
F_30 ( V_15 -> V_35 , true ) ;
F_30 ( V_15 -> V_36 , true ) ;
F_30 ( V_15 -> V_39 , true ) ;
F_30 ( V_15 -> V_41 , true ) ;
if ( V_15 -> V_130 == V_131 )
F_31 ( V_15 , 0x3c82 , 0x0005 ) ;
return V_122 ;
}
static void F_32 ( struct V_102 * V_103 )
{
struct V_14 * V_15 = F_19 ( V_103 ) ;
unsigned long V_90 ;
V_103 -> V_127 = 0 ;
F_33 ( V_15 ) ;
F_27 ( & V_15 -> V_123 ) ;
F_34 ( V_15 ) ;
F_29 ( & V_15 -> V_123 ) ;
F_8 ( & V_15 -> V_73 , V_74 , V_129 , 0 ) ;
F_21 ( & V_15 -> V_111 , V_90 ) ;
F_35 ( & V_15 -> V_113 ) ;
F_23 ( & V_15 -> V_111 , V_90 ) ;
F_30 ( V_15 -> V_35 , false ) ;
F_30 ( V_15 -> V_36 , false ) ;
F_30 ( V_15 -> V_39 , false ) ;
F_30 ( V_15 -> V_41 , false ) ;
if ( V_15 -> V_130 == V_131 )
F_31 ( V_15 , 0x3c82 , 0x000d ) ;
}
static int F_36 ( struct V_76 * V_132 , void * V_77 ,
struct V_133 * V_134 )
{
struct V_14 * V_15 = F_10 ( V_132 ) ;
struct V_135 V_136 = {
. V_137 = 1001 * V_15 -> V_138 ,
. V_139 = V_15 -> V_140 ,
} ;
if ( V_134 -> type != V_54 )
return - V_51 ;
V_134 -> V_134 . V_141 . V_142 = 2 ;
V_134 -> V_134 . V_141 . V_143 = V_144 ;
V_134 -> V_134 . V_141 . V_136 = V_136 ;
return 0 ;
}
static int F_37 ( struct V_76 * V_132 , void * V_77 ,
struct V_133 * V_134 )
{
struct V_14 * V_15 = F_10 ( V_132 ) ;
unsigned int V_145 , V_146 ;
if ( V_134 -> type != V_54 )
return - V_51 ;
V_145 = V_15 -> V_140 *
V_134 -> V_134 . V_141 . V_136 . V_137 ;
V_146 = 1001 * V_134 -> V_134 . V_141 . V_136 . V_139 ;
if ( V_145 != 0 && V_146 != 0 && V_145 > V_146 )
V_15 -> V_138 = ( V_145 + V_146 / 2 ) / V_146 ;
else
V_15 -> V_138 = 1 ;
return F_36 ( V_132 , V_77 , V_134 ) ;
}
static int F_38 ( struct V_76 * V_132 , void * V_77 ,
struct V_147 * V_148 )
{
struct V_14 * V_15 = F_10 ( V_132 ) ;
int V_16 , V_17 ;
if ( V_148 -> V_97 > 2 )
return - V_51 ;
if ( ! F_1 ( V_148 -> V_149 ) )
return - V_51 ;
F_4 ( V_15 , & V_16 , & V_17 ) ;
V_148 -> type = V_150 ;
V_148 -> V_151 . V_16 = ( V_16 >> V_148 -> V_97 ) & ~ 0xf ;
V_148 -> V_151 . V_17 = ( V_17 >> V_148 -> V_97 ) & ~ 0xf ;
return 0 ;
}
static int F_39 ( struct V_76 * V_132 , void * V_77 ,
struct V_152 * V_153 )
{
struct V_14 * V_15 = F_10 ( V_132 ) ;
int V_16 , V_17 ;
int V_154 ;
if ( V_153 -> V_97 > 4 )
return - V_51 ;
if ( ! F_1 ( V_153 -> V_149 ) )
return - V_51 ;
if ( ! ( V_15 -> V_22 -> V_52 & V_53 ) ) {
F_4 ( V_15 , & V_16 , & V_17 ) ;
for ( V_154 = 0 ; V_154 <= 2 ; V_154 ++ )
if ( V_153 -> V_16 == ( ( V_16 >> V_154 ) & ~ 0xf ) &&
V_153 -> V_17 == ( ( V_17 >> V_154 ) & ~ 0xf ) )
break;
if ( V_154 > 2 )
return - V_51 ;
}
V_153 -> type = V_155 ;
V_153 -> V_151 . V_137 = 1001 * ( V_153 -> V_97 + 1 ) ;
V_153 -> V_151 . V_139 = V_15 -> V_140 ;
return 0 ;
}
static int F_40 ( struct V_76 * V_76 , void * V_77 , T_3 * V_156 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
* V_156 = V_15 -> V_156 ;
return 0 ;
}
static int F_41 ( struct V_14 * V_15 )
{
if ( V_15 -> V_156 & V_157 ) {
V_15 -> V_18 = V_20 ;
V_15 -> V_140 = 25025 ;
} else {
V_15 -> V_18 = V_19 ;
V_15 -> V_140 = 30000 ;
}
F_8 ( & V_15 -> V_73 , V_74 , V_158 , V_15 -> V_156 ) ;
F_7 ( V_15 , NULL , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_76 * V_76 , void * V_77 , T_3 V_156 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
if ( F_16 ( & V_15 -> V_100 ) )
return - V_101 ;
V_15 -> V_156 = V_156 ;
return F_41 ( V_15 ) ;
}
static int F_43 ( struct V_76 * V_76 , void * V_77 , T_3 * V_156 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
return F_8 ( & V_15 -> V_73 , V_74 , V_159 , V_156 ) ;
}
static int F_44 ( struct V_76 * V_76 , void * V_77 ,
struct V_160 * V_161 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
if ( V_161 -> V_97 >= V_15 -> V_22 -> V_162 )
return - V_51 ;
strncpy ( V_161 -> V_82 , V_15 -> V_22 -> V_163 [ V_161 -> V_97 ] . V_82 ,
sizeof( V_161 -> V_82 ) ) ;
if ( ( V_15 -> V_22 -> V_90 & V_91 ) &&
V_161 -> V_97 == 0 )
V_161 -> type = V_164 ;
else
V_161 -> type = V_165 ;
if ( V_15 -> V_22 -> V_88 )
V_161 -> V_166 = ( 1 << V_15 -> V_22 -> V_88 ) - 1 ;
else
V_161 -> V_166 = 0 ;
V_161 -> V_167 = 0 ;
if ( V_15 -> V_22 -> V_52 & V_168 )
V_161 -> V_156 = F_45 ( V_76 ) -> V_169 ;
else
V_161 -> V_156 = 0 ;
return 0 ;
}
static int F_46 ( struct V_76 * V_76 , void * V_77 , unsigned int * V_170 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
* V_170 = V_15 -> V_170 ;
return 0 ;
}
static int F_47 ( struct V_76 * V_76 , void * V_171 , struct V_172 * V_173 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
if ( V_173 -> V_97 >= V_15 -> V_22 -> V_88 )
return - V_51 ;
F_11 ( V_173 -> V_82 , V_15 -> V_22 -> V_174 [ V_173 -> V_97 ] . V_82 ,
sizeof( V_173 -> V_82 ) ) ;
V_173 -> V_143 = V_175 ;
return 0 ;
}
static int F_48 ( struct V_76 * V_76 , void * V_171 , struct V_172 * V_173 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
V_173 -> V_97 = V_15 -> V_176 ;
F_11 ( V_173 -> V_82 , V_15 -> V_22 -> V_174 [ V_15 -> V_176 ] . V_82 ,
sizeof( V_173 -> V_82 ) ) ;
V_173 -> V_143 = V_175 ;
return 0 ;
}
static int F_49 ( struct V_76 * V_76 , void * V_171 ,
const struct V_172 * V_173 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
if ( V_173 -> V_97 >= V_15 -> V_22 -> V_88 )
return - V_51 ;
V_15 -> V_176 = V_173 -> V_97 ;
F_50 ( V_15 -> V_177 , V_178 , V_179 ,
V_15 -> V_22 -> V_174 [ V_15 -> V_176 ] . V_180 , 0 , 0 ) ;
return 0 ;
}
static void F_51 ( struct V_14 * V_15 )
{
unsigned int V_170 = V_15 -> V_170 ;
F_50 ( V_15 -> V_181 , V_74 , V_179 ,
V_15 -> V_22 -> V_163 [ V_170 ] . V_182 , 0 ,
V_15 -> V_22 -> V_183 ) ;
if ( V_15 -> V_22 -> V_88 ) {
int V_176 = V_15 -> V_22 -> V_163 [ V_170 ] . V_184 ;
F_50 ( V_15 -> V_177 , V_178 , V_179 ,
V_15 -> V_22 -> V_174 [ V_176 ] . V_180 , 0 , 0 ) ;
V_15 -> V_176 = V_176 ;
}
}
static int F_52 ( struct V_76 * V_76 , void * V_77 , unsigned int V_170 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
if ( V_170 >= V_15 -> V_22 -> V_162 )
return - V_51 ;
if ( F_16 ( & V_15 -> V_100 ) )
return - V_101 ;
V_15 -> V_170 = V_170 ;
F_51 ( V_15 ) ;
return 0 ;
}
static int F_53 ( struct V_76 * V_76 , void * V_77 ,
struct V_185 * V_186 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
if ( V_186 -> V_97 != 0 )
return - V_51 ;
F_11 ( V_186 -> V_82 , L_6 , sizeof( V_186 -> V_82 ) ) ;
return F_8 ( & V_15 -> V_73 , V_167 , V_187 , V_186 ) ;
}
static int F_54 ( struct V_76 * V_76 , void * V_77 ,
const struct V_185 * V_186 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
if ( V_186 -> V_97 != 0 )
return - V_51 ;
return F_8 ( & V_15 -> V_73 , V_167 , V_188 , V_186 ) ;
}
static int F_55 ( struct V_76 * V_76 , void * V_77 ,
struct V_189 * V_190 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
if ( V_190 -> V_167 )
return - V_51 ;
return F_8 ( & V_15 -> V_73 , V_167 , V_191 , V_190 ) ;
}
static int F_56 ( struct V_76 * V_76 , void * V_77 ,
const struct V_189 * V_190 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
if ( V_190 -> V_167 )
return - V_51 ;
return F_8 ( & V_15 -> V_73 , V_167 , V_192 , V_190 ) ;
}
static int F_57 ( struct V_76 * V_76 , void * V_77 )
{
struct V_14 * V_15 = F_10 ( V_76 ) ;
F_58 ( V_76 , V_77 ) ;
return F_8 ( & V_15 -> V_73 , V_193 , V_194 ) ;
}
static int F_59 ( struct V_195 * V_171 ,
const struct V_196 * V_197 )
{
switch ( V_197 -> type ) {
case V_198 :
return F_60 ( V_171 , V_197 ) ;
case V_199 :
return F_61 ( V_171 , V_197 , 30 , NULL ) ;
}
return - V_51 ;
}
static int F_62 ( struct V_200 * V_201 )
{
struct V_14 * V_15 =
F_20 ( V_201 -> V_202 , struct V_14 , V_203 ) ;
unsigned V_204 ;
T_2 * V_205 ;
switch ( V_201 -> V_206 ) {
case V_207 :
V_15 -> V_208 [ 0 ] . V_209 = V_201 -> V_210 ;
break;
case V_211 :
V_15 -> V_208 [ 0 ] . V_212 = V_201 -> V_210 ;
break;
case V_213 :
V_15 -> V_208 [ 0 ] . V_214 = V_201 -> V_210 ;
break;
case V_215 :
V_15 -> V_208 [ 1 ] . V_209 = V_201 -> V_210 ;
break;
case V_216 :
V_15 -> V_208 [ 1 ] . V_212 = V_201 -> V_210 ;
break;
case V_217 :
V_15 -> V_208 [ 1 ] . V_214 = V_201 -> V_210 ;
break;
case V_218 :
V_15 -> V_208 [ 2 ] . V_209 = V_201 -> V_210 ;
break;
case V_219 :
V_15 -> V_208 [ 2 ] . V_212 = V_201 -> V_210 ;
break;
case V_220 :
V_15 -> V_208 [ 2 ] . V_214 = V_201 -> V_210 ;
break;
case V_221 :
V_15 -> V_208 [ 3 ] . V_209 = V_201 -> V_210 ;
break;
case V_222 :
V_15 -> V_208 [ 3 ] . V_212 = V_201 -> V_210 ;
break;
case V_223 :
V_15 -> V_208 [ 3 ] . V_214 = V_201 -> V_210 ;
break;
case V_224 :
V_205 = V_15 -> V_225 ;
for ( V_204 = 0 ; V_204 < V_15 -> V_17 / 16 ; V_204 ++ , V_205 += V_15 -> V_16 / 16 )
memcpy ( V_205 , V_201 -> V_226 . V_227 + V_204 * ( 720 / 16 ) , V_15 -> V_16 / 16 ) ;
break;
default:
return - V_51 ;
}
return 0 ;
}
int F_63 ( struct V_14 * V_15 )
{
struct V_228 * V_203 = & V_15 -> V_203 ;
struct V_200 * V_201 ;
F_64 ( V_203 , 22 ) ;
V_15 -> V_35 = F_65 ( V_203 , NULL ,
V_229 , 0 , 34 , 1 , 15 ) ;
V_15 -> V_36 = F_65 ( V_203 , NULL ,
V_230 , 0 , 1 , 1 , 1 ) ;
V_15 -> V_39 = F_65 ( V_203 , NULL ,
V_231 ,
64000 , 10000000 , 1 , 9800000 ) ;
V_15 -> V_37 = F_65 ( V_203 , NULL ,
V_232 , 0 , 2 , 2 , 0 ) ;
V_15 -> V_40 = F_65 ( V_203 , NULL ,
V_233 , 0 , 1 , 1 , 1 ) ;
V_15 -> V_41 = F_66 ( V_203 , NULL ,
V_234 ,
V_45 , 0 ,
V_42 ) ;
V_201 = F_65 ( V_203 , NULL ,
V_235 , 0 ,
V_236 |
V_237 , 0 ,
V_236 |
V_237 ) ;
if ( V_201 )
V_201 -> V_90 |= V_238 ;
F_67 ( V_203 , & V_239 , NULL ) ;
F_67 ( V_203 , & V_240 , NULL ) ;
F_67 ( V_203 , & V_241 , NULL ) ;
F_67 ( V_203 , & V_242 , NULL ) ;
F_67 ( V_203 , & V_243 , NULL ) ;
F_67 ( V_203 , & V_244 , NULL ) ;
F_67 ( V_203 , & V_245 , NULL ) ;
F_67 ( V_203 , & V_246 , NULL ) ;
F_67 ( V_203 , & V_247 , NULL ) ;
F_67 ( V_203 , & V_248 , NULL ) ;
F_67 ( V_203 , & V_249 , NULL ) ;
F_67 ( V_203 , & V_250 , NULL ) ;
F_67 ( V_203 , & V_251 , NULL ) ;
V_15 -> V_252 = F_66 ( V_203 , NULL ,
V_253 ,
V_254 ,
1 << V_255 ,
V_256 ) ;
if ( V_203 -> error ) {
int V_257 = V_203 -> error ;
F_68 ( & V_15 -> V_73 , L_7 ) ;
return V_257 ;
}
V_15 -> V_73 . V_258 = V_203 ;
return 0 ;
}
int F_69 ( struct V_14 * V_15 )
{
struct V_259 * V_260 = & V_15 -> V_260 ;
int V_257 ;
F_70 ( & V_15 -> V_261 ) ;
F_70 ( & V_15 -> V_262 ) ;
F_35 ( & V_15 -> V_113 ) ;
V_15 -> V_100 . type = V_54 ;
V_15 -> V_100 . V_263 = V_264 | V_265 | V_266 ;
V_15 -> V_100 . V_267 = & V_268 ;
V_15 -> V_100 . V_269 = & V_270 ;
V_15 -> V_100 . V_271 = V_15 ;
V_15 -> V_100 . V_272 = sizeof( struct V_6 ) ;
V_15 -> V_100 . V_273 = V_274 ;
V_15 -> V_100 . V_275 = & V_15 -> V_262 ;
V_257 = F_71 ( & V_15 -> V_100 ) ;
if ( V_257 )
return V_257 ;
* V_260 = V_276 ;
V_260 -> V_275 = & V_15 -> V_261 ;
V_260 -> V_277 = & V_15 -> V_100 ;
F_72 ( V_260 , V_15 ) ;
V_260 -> V_73 = & V_15 -> V_73 ;
if ( ! F_73 ( & V_15 -> V_73 , V_74 , V_159 ) )
F_74 ( V_260 , V_278 ) ;
if ( ! ( V_15 -> V_22 -> V_90 & V_91 ) ) {
F_74 ( V_260 , V_279 ) ;
F_74 ( V_260 , V_280 ) ;
F_74 ( V_260 , V_281 ) ;
F_74 ( V_260 , V_282 ) ;
} else {
struct V_189 V_190 = {
. type = V_283 ,
. V_284 = 980 ,
} ;
F_8 ( & V_15 -> V_73 , V_167 , V_192 , & V_190 ) ;
}
if ( ! ( V_15 -> V_22 -> V_52 & V_168 ) ) {
F_74 ( V_260 , V_285 ) ;
F_74 ( V_260 , V_286 ) ;
V_260 -> V_169 = 0 ;
}
if ( V_15 -> V_22 -> V_52 & V_53 )
F_74 ( V_260 , V_287 ) ;
if ( V_15 -> V_22 -> V_88 == 0 ) {
F_74 ( V_260 , V_288 ) ;
F_74 ( V_260 , V_289 ) ;
F_74 ( V_260 , V_290 ) ;
}
if ( V_15 -> V_22 -> V_52 & V_291 )
F_50 ( V_15 -> V_181 , V_74 , V_292 ,
V_293 ,
V_294 | V_295 |
V_296 ) ;
F_51 ( V_15 ) ;
if ( V_15 -> V_22 -> V_52 & V_168 )
F_41 ( V_15 ) ;
V_257 = F_75 ( V_260 , V_297 , - 1 ) ;
if ( V_257 < 0 )
return V_257 ;
F_76 ( V_15 -> V_298 , L_8 ,
F_77 ( V_260 ) ) ;
return 0 ;
}
void F_78 ( struct V_14 * V_15 )
{
F_79 ( & V_15 -> V_203 ) ;
}
