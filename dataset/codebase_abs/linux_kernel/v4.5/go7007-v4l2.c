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
T_2 * V_9 = F_3 ( & V_7 -> V_7 . V_10 , 0 ) ;
switch ( V_8 ) {
case V_2 :
return V_11 ;
case V_5 :
switch ( ( V_9 [ V_7 -> V_12 + 4 ] >> 6 ) & 0x3 ) {
case 0 :
return V_11 ;
case 1 :
return V_13 ;
case 2 :
return V_14 ;
default:
return 0 ;
}
case V_3 :
case V_4 :
switch ( ( V_9 [ V_7 -> V_12 + 5 ] >> 3 ) & 0x7 ) {
case 1 :
return V_11 ;
case 2 :
return V_13 ;
case 3 :
return V_14 ;
default:
return 0 ;
}
}
return 0 ;
}
static void F_4 ( struct V_15 * V_16 , int * V_17 , int * V_18 )
{
switch ( V_16 -> V_19 ) {
case V_20 :
* V_17 = 720 ;
* V_18 = 480 ;
break;
case V_21 :
* V_17 = 720 ;
* V_18 = 576 ;
break;
case V_22 :
default:
* V_17 = V_16 -> V_23 -> V_24 ;
* V_18 = V_16 -> V_23 -> V_25 ;
break;
}
}
static void F_5 ( struct V_15 * V_16 )
{
if ( V_16 -> V_8 == V_2 ) {
V_16 -> V_26 = 0 ;
V_16 -> V_27 = V_28 ;
V_16 -> V_29 = 0 ;
V_16 -> V_30 = 0 ;
V_16 -> V_31 = 0 ;
V_16 -> V_32 = 0 ;
V_16 -> V_33 = 0 ;
V_16 -> V_34 = 0 ;
V_16 -> V_35 = 0 ;
return;
}
switch ( V_16 -> V_8 ) {
case V_3 :
V_16 -> V_26 = 0 ;
break;
default:
case V_4 :
V_16 -> V_26 = 0x48 ;
break;
case V_5 :
V_16 -> V_26 = 0xf5 ;
break;
}
V_16 -> V_29 = F_6 ( V_16 -> V_36 ) ;
V_16 -> V_31 = F_6 ( V_16 -> V_37 ) ;
V_16 -> V_30 = F_6 ( V_16 -> V_38 ) != 0 ;
V_16 -> V_39 = F_6 ( V_16 -> V_40 ) ;
V_16 -> V_32 = F_6 ( V_16 -> V_41 ) ;
V_16 -> V_34 = 1 ;
V_16 -> V_35 = 0 ;
if ( V_16 -> V_8 == V_4 )
V_16 -> V_35 =
V_16 -> V_39 == 9800000 &&
V_16 -> V_29 == 15 &&
V_16 -> V_30 == 0 &&
V_16 -> V_32 == 1 &&
V_16 -> V_31 ;
switch ( F_6 ( V_16 -> V_42 ) ) {
default:
case V_43 :
V_16 -> V_27 = V_28 ;
break;
case V_44 :
V_16 -> V_27 = V_45 ;
break;
case V_46 :
V_16 -> V_27 = V_47 ;
break;
}
}
static int F_7 ( struct V_15 * V_16 , struct V_48 * V_49 , int V_50 )
{
int V_25 = 0 , V_24 = 0 ;
int V_17 , V_18 ;
if ( V_49 != NULL && ! F_1 ( V_49 -> V_49 . V_51 . V_1 ) )
return - V_52 ;
F_4 ( V_16 , & V_24 , & V_25 ) ;
if ( V_49 == NULL ) {
V_17 = V_24 ;
V_18 = V_25 ;
} else if ( V_16 -> V_23 -> V_53 & V_54 ) {
if ( V_49 -> V_49 . V_51 . V_17 > V_24 )
V_17 = V_24 ;
else if ( V_49 -> V_49 . V_51 . V_17 < 144 )
V_17 = 144 ;
else
V_17 = V_49 -> V_49 . V_51 . V_17 & ~ 0x0f ;
if ( V_49 -> V_49 . V_51 . V_18 > V_25 )
V_18 = V_25 ;
else if ( V_49 -> V_49 . V_51 . V_18 < 96 )
V_18 = 96 ;
else
V_18 = V_49 -> V_49 . V_51 . V_18 & ~ 0x0f ;
} else {
V_17 = V_49 -> V_49 . V_51 . V_17 ;
if ( V_17 <= V_24 / 4 ) {
V_17 = V_24 / 4 ;
V_18 = V_25 / 4 ;
} else if ( V_17 <= V_24 / 2 ) {
V_17 = V_24 / 2 ;
V_18 = V_25 / 2 ;
} else {
V_17 = V_24 ;
V_18 = V_25 ;
}
V_17 &= ~ 0xf ;
V_18 &= ~ 0xf ;
}
if ( V_49 != NULL ) {
T_1 V_1 = V_49 -> V_49 . V_51 . V_1 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> type = V_55 ;
V_49 -> V_49 . V_51 . V_17 = V_17 ;
V_49 -> V_49 . V_51 . V_18 = V_18 ;
V_49 -> V_49 . V_51 . V_1 = V_1 ;
V_49 -> V_49 . V_51 . V_56 = V_57 ;
V_49 -> V_49 . V_51 . V_58 = 0 ;
V_49 -> V_49 . V_51 . V_59 = V_60 ;
V_49 -> V_49 . V_51 . V_61 = V_62 ;
}
if ( V_50 )
return 0 ;
if ( V_49 )
V_16 -> V_8 = V_49 -> V_49 . V_51 . V_1 ;
V_16 -> V_17 = V_17 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_63 = V_16 -> V_23 -> V_64 ;
V_16 -> V_65 = V_16 -> V_23 -> V_66 ;
if ( V_16 -> V_23 -> V_53 & V_54 ) {
struct V_67 V_8 = {
. V_68 = V_69 ,
} ;
V_8 . V_8 . V_70 = V_71 ;
V_8 . V_8 . V_17 = V_49 ? V_49 -> V_49 . V_51 . V_17 : V_17 ;
V_8 . V_8 . V_18 = V_18 ;
V_16 -> V_72 = 0 ;
V_16 -> V_73 = 0 ;
V_16 -> V_74 = 0 ;
F_8 ( & V_16 -> V_75 , V_76 , V_77 , NULL , & V_8 ) ;
} else {
if ( V_17 <= V_24 / 4 ) {
V_16 -> V_72 = 1 ;
V_16 -> V_73 = 1 ;
V_16 -> V_74 = 1 ;
} else if ( V_17 <= V_24 / 2 ) {
V_16 -> V_72 = 1 ;
V_16 -> V_73 = 1 ;
V_16 -> V_74 = 0 ;
} else {
V_16 -> V_72 = 0 ;
V_16 -> V_73 = 0 ;
V_16 -> V_74 = 0 ;
}
}
return 0 ;
}
static int F_9 ( struct V_78 * V_78 , void * V_79 ,
struct V_80 * V_81 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
F_11 ( V_81 -> V_82 , L_1 , sizeof( V_81 -> V_82 ) ) ;
F_11 ( V_81 -> V_83 , V_16 -> V_84 , sizeof( V_81 -> V_83 ) ) ;
F_11 ( V_81 -> V_85 , V_16 -> V_85 , sizeof( V_81 -> V_85 ) ) ;
V_81 -> V_86 = V_87 | V_88 |
V_89 ;
if ( V_16 -> V_23 -> V_90 )
V_81 -> V_86 |= V_91 ;
if ( V_16 -> V_23 -> V_92 & V_93 )
V_81 -> V_86 |= V_94 ;
V_81 -> V_95 = V_81 -> V_86 | V_96 ;
return 0 ;
}
static int F_12 ( struct V_78 * V_78 , void * V_79 ,
struct V_97 * V_49 )
{
char * V_98 = NULL ;
switch ( V_49 -> V_99 ) {
case 0 :
V_49 -> V_1 = V_2 ;
V_98 = L_2 ;
break;
case 1 :
V_49 -> V_1 = V_3 ;
V_98 = L_3 ;
break;
case 2 :
V_49 -> V_1 = V_4 ;
V_98 = L_4 ;
break;
case 3 :
V_49 -> V_1 = V_5 ;
V_98 = L_5 ;
break;
default:
return - V_52 ;
}
V_49 -> type = V_55 ;
V_49 -> V_92 = V_100 ;
strncpy ( V_49 -> V_101 , V_98 , sizeof( V_49 -> V_101 ) ) ;
return 0 ;
}
static int F_13 ( struct V_78 * V_78 , void * V_79 ,
struct V_48 * V_49 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
V_49 -> type = V_55 ;
V_49 -> V_49 . V_51 . V_17 = V_16 -> V_17 ;
V_49 -> V_49 . V_51 . V_18 = V_16 -> V_18 ;
V_49 -> V_49 . V_51 . V_1 = V_16 -> V_8 ;
V_49 -> V_49 . V_51 . V_56 = V_57 ;
V_49 -> V_49 . V_51 . V_58 = 0 ;
V_49 -> V_49 . V_51 . V_59 = V_60 ;
V_49 -> V_49 . V_51 . V_61 = V_62 ;
return 0 ;
}
static int F_14 ( struct V_78 * V_78 , void * V_79 ,
struct V_48 * V_49 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
return F_7 ( V_16 , V_49 , 1 ) ;
}
static int F_15 ( struct V_78 * V_78 , void * V_79 ,
struct V_48 * V_49 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( F_16 ( & V_16 -> V_102 ) )
return - V_103 ;
return F_7 ( V_16 , V_49 , 0 ) ;
}
static int F_17 ( struct V_104 * V_105 ,
unsigned int * V_106 , unsigned int * V_107 ,
unsigned int V_108 [] , void * V_109 [] )
{
V_108 [ 0 ] = V_60 ;
* V_107 = 1 ;
if ( * V_106 < 2 )
* V_106 = 2 ;
return 0 ;
}
static void F_18 ( struct V_110 * V_7 )
{
struct V_104 * V_111 = V_7 -> V_104 ;
struct V_15 * V_16 = F_19 ( V_111 ) ;
struct V_112 * V_113 = F_20 ( V_7 ) ;
struct V_6 * V_114 =
F_21 ( V_113 , struct V_6 , V_7 ) ;
unsigned long V_92 ;
F_22 ( & V_16 -> V_115 , V_92 ) ;
F_23 ( & V_114 -> V_116 , & V_16 -> V_117 ) ;
F_24 ( & V_16 -> V_115 , V_92 ) ;
}
static int F_25 ( struct V_110 * V_7 )
{
struct V_112 * V_113 = F_20 ( V_7 ) ;
struct V_6 * V_114 =
F_21 ( V_113 , struct V_6 , V_7 ) ;
V_114 -> V_118 = 0 ;
V_114 -> V_12 = 0 ;
V_7 -> V_119 [ 0 ] . V_120 = 0 ;
return 0 ;
}
static void F_26 ( struct V_110 * V_7 )
{
struct V_104 * V_111 = V_7 -> V_104 ;
struct V_15 * V_16 = F_19 ( V_111 ) ;
struct V_112 * V_113 = F_20 ( V_7 ) ;
struct V_6 * V_114 =
F_21 ( V_113 , struct V_6 , V_7 ) ;
T_1 V_121 = F_2 ( V_114 , V_16 -> V_8 ) ;
V_113 -> V_92 &= ~ ( V_11 | V_14 |
V_13 ) ;
V_113 -> V_92 |= V_121 ;
V_113 -> V_56 = V_57 ;
}
static int F_27 ( struct V_104 * V_105 , unsigned int V_122 )
{
struct V_15 * V_16 = F_19 ( V_105 ) ;
int V_123 ;
F_5 ( V_16 ) ;
F_28 ( & V_16 -> V_124 ) ;
V_16 -> V_125 = 0 ;
V_16 -> V_126 = NULL ;
V_16 -> V_127 = 0 ;
V_105 -> V_128 = 1 ;
if ( F_29 ( V_16 ) < 0 )
V_123 = - V_129 ;
else
V_123 = 0 ;
F_30 ( & V_16 -> V_124 ) ;
if ( V_123 ) {
V_105 -> V_128 = 0 ;
return V_123 ;
}
F_8 ( & V_16 -> V_75 , V_130 , V_131 , 1 ) ;
F_31 ( V_16 -> V_36 , true ) ;
F_31 ( V_16 -> V_37 , true ) ;
F_31 ( V_16 -> V_40 , true ) ;
F_31 ( V_16 -> V_42 , true ) ;
if ( V_16 -> V_132 == V_133 )
F_32 ( V_16 , 0x3c82 , 0x0005 ) ;
return V_123 ;
}
static void F_33 ( struct V_104 * V_105 )
{
struct V_15 * V_16 = F_19 ( V_105 ) ;
unsigned long V_92 ;
V_105 -> V_128 = 0 ;
F_34 ( V_16 ) ;
F_28 ( & V_16 -> V_124 ) ;
F_35 ( V_16 ) ;
F_30 ( & V_16 -> V_124 ) ;
F_8 ( & V_16 -> V_75 , V_130 , V_131 , 0 ) ;
F_22 ( & V_16 -> V_115 , V_92 ) ;
F_36 ( & V_16 -> V_117 ) ;
F_24 ( & V_16 -> V_115 , V_92 ) ;
F_31 ( V_16 -> V_36 , false ) ;
F_31 ( V_16 -> V_37 , false ) ;
F_31 ( V_16 -> V_40 , false ) ;
F_31 ( V_16 -> V_42 , false ) ;
if ( V_16 -> V_132 == V_133 )
F_32 ( V_16 , 0x3c82 , 0x000d ) ;
}
static int F_37 ( struct V_78 * V_134 , void * V_79 ,
struct V_135 * V_136 )
{
struct V_15 * V_16 = F_10 ( V_134 ) ;
struct V_137 V_138 = {
. V_139 = 1001 * V_16 -> V_140 ,
. V_141 = V_16 -> V_142 ,
} ;
if ( V_136 -> type != V_55 )
return - V_52 ;
V_136 -> V_136 . V_143 . V_144 = 2 ;
V_136 -> V_136 . V_143 . V_145 = V_146 ;
V_136 -> V_136 . V_143 . V_138 = V_138 ;
return 0 ;
}
static int F_38 ( struct V_78 * V_134 , void * V_79 ,
struct V_135 * V_136 )
{
struct V_15 * V_16 = F_10 ( V_134 ) ;
unsigned int V_147 , V_148 ;
if ( V_136 -> type != V_55 )
return - V_52 ;
V_147 = V_16 -> V_142 *
V_136 -> V_136 . V_143 . V_138 . V_139 ;
V_148 = 1001 * V_136 -> V_136 . V_143 . V_138 . V_141 ;
if ( V_147 != 0 && V_148 != 0 && V_147 > V_148 )
V_16 -> V_140 = ( V_147 + V_148 / 2 ) / V_148 ;
else
V_16 -> V_140 = 1 ;
return F_37 ( V_134 , V_79 , V_136 ) ;
}
static int F_39 ( struct V_78 * V_134 , void * V_79 ,
struct V_149 * V_150 )
{
struct V_15 * V_16 = F_10 ( V_134 ) ;
int V_17 , V_18 ;
if ( V_150 -> V_99 > 2 )
return - V_52 ;
if ( ! F_1 ( V_150 -> V_151 ) )
return - V_52 ;
F_4 ( V_16 , & V_17 , & V_18 ) ;
V_150 -> type = V_152 ;
V_150 -> V_153 . V_17 = ( V_17 >> V_150 -> V_99 ) & ~ 0xf ;
V_150 -> V_153 . V_18 = ( V_18 >> V_150 -> V_99 ) & ~ 0xf ;
return 0 ;
}
static int F_40 ( struct V_78 * V_134 , void * V_79 ,
struct V_154 * V_155 )
{
struct V_15 * V_16 = F_10 ( V_134 ) ;
int V_17 , V_18 ;
int V_156 ;
if ( V_155 -> V_99 > 4 )
return - V_52 ;
if ( ! F_1 ( V_155 -> V_151 ) )
return - V_52 ;
if ( ! ( V_16 -> V_23 -> V_53 & V_54 ) ) {
F_4 ( V_16 , & V_17 , & V_18 ) ;
for ( V_156 = 0 ; V_156 <= 2 ; V_156 ++ )
if ( V_155 -> V_17 == ( ( V_17 >> V_156 ) & ~ 0xf ) &&
V_155 -> V_18 == ( ( V_18 >> V_156 ) & ~ 0xf ) )
break;
if ( V_156 > 2 )
return - V_52 ;
}
V_155 -> type = V_157 ;
V_155 -> V_153 . V_139 = 1001 * ( V_155 -> V_99 + 1 ) ;
V_155 -> V_153 . V_141 = V_16 -> V_142 ;
return 0 ;
}
static int F_41 ( struct V_78 * V_78 , void * V_79 , T_3 * V_158 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
* V_158 = V_16 -> V_158 ;
return 0 ;
}
static int F_42 ( struct V_15 * V_16 )
{
if ( V_16 -> V_158 & V_159 ) {
V_16 -> V_19 = V_21 ;
V_16 -> V_142 = 25025 ;
} else {
V_16 -> V_19 = V_20 ;
V_16 -> V_142 = 30000 ;
}
F_8 ( & V_16 -> V_75 , V_130 , V_160 , V_16 -> V_158 ) ;
F_7 ( V_16 , NULL , 0 ) ;
return 0 ;
}
static int F_43 ( struct V_78 * V_78 , void * V_79 , T_3 V_158 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( F_16 ( & V_16 -> V_102 ) )
return - V_103 ;
V_16 -> V_158 = V_158 ;
return F_42 ( V_16 ) ;
}
static int F_44 ( struct V_78 * V_78 , void * V_79 , T_3 * V_158 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
return F_8 ( & V_16 -> V_75 , V_130 , V_161 , V_158 ) ;
}
static int F_45 ( struct V_78 * V_78 , void * V_79 ,
struct V_162 * V_163 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_163 -> V_99 >= V_16 -> V_23 -> V_164 )
return - V_52 ;
strncpy ( V_163 -> V_84 , V_16 -> V_23 -> V_165 [ V_163 -> V_99 ] . V_84 ,
sizeof( V_163 -> V_84 ) ) ;
if ( ( V_16 -> V_23 -> V_92 & V_93 ) &&
V_163 -> V_99 == 0 )
V_163 -> type = V_166 ;
else
V_163 -> type = V_167 ;
if ( V_16 -> V_23 -> V_90 )
V_163 -> V_168 = ( 1 << V_16 -> V_23 -> V_90 ) - 1 ;
else
V_163 -> V_168 = 0 ;
V_163 -> V_169 = 0 ;
if ( V_16 -> V_23 -> V_53 & V_170 )
V_163 -> V_158 = F_46 ( V_78 ) -> V_171 ;
else
V_163 -> V_158 = 0 ;
return 0 ;
}
static int F_47 ( struct V_78 * V_78 , void * V_79 , unsigned int * V_172 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
* V_172 = V_16 -> V_172 ;
return 0 ;
}
static int F_48 ( struct V_78 * V_78 , void * V_173 , struct V_174 * V_175 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_175 -> V_99 >= V_16 -> V_23 -> V_90 )
return - V_52 ;
F_11 ( V_175 -> V_84 , V_16 -> V_23 -> V_176 [ V_175 -> V_99 ] . V_84 ,
sizeof( V_175 -> V_84 ) ) ;
V_175 -> V_145 = V_177 ;
return 0 ;
}
static int F_49 ( struct V_78 * V_78 , void * V_173 , struct V_174 * V_175 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
V_175 -> V_99 = V_16 -> V_178 ;
F_11 ( V_175 -> V_84 , V_16 -> V_23 -> V_176 [ V_16 -> V_178 ] . V_84 ,
sizeof( V_175 -> V_84 ) ) ;
V_175 -> V_145 = V_177 ;
return 0 ;
}
static int F_50 ( struct V_78 * V_78 , void * V_173 ,
const struct V_174 * V_175 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_175 -> V_99 >= V_16 -> V_23 -> V_90 )
return - V_52 ;
V_16 -> V_178 = V_175 -> V_99 ;
F_51 ( V_16 -> V_179 , V_180 , V_181 ,
V_16 -> V_23 -> V_176 [ V_16 -> V_178 ] . V_182 , 0 , 0 ) ;
return 0 ;
}
static void F_52 ( struct V_15 * V_16 )
{
unsigned int V_172 = V_16 -> V_172 ;
F_51 ( V_16 -> V_183 , V_130 , V_181 ,
V_16 -> V_23 -> V_165 [ V_172 ] . V_184 , 0 ,
V_16 -> V_23 -> V_185 ) ;
if ( V_16 -> V_23 -> V_90 ) {
int V_178 = V_16 -> V_23 -> V_165 [ V_172 ] . V_186 ;
F_51 ( V_16 -> V_179 , V_180 , V_181 ,
V_16 -> V_23 -> V_176 [ V_178 ] . V_182 , 0 , 0 ) ;
V_16 -> V_178 = V_178 ;
}
}
static int F_53 ( struct V_78 * V_78 , void * V_79 , unsigned int V_172 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_172 >= V_16 -> V_23 -> V_164 )
return - V_52 ;
if ( F_16 ( & V_16 -> V_102 ) )
return - V_103 ;
V_16 -> V_172 = V_172 ;
F_52 ( V_16 ) ;
return 0 ;
}
static int F_54 ( struct V_78 * V_78 , void * V_79 ,
struct V_187 * V_188 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_188 -> V_99 != 0 )
return - V_52 ;
F_11 ( V_188 -> V_84 , L_6 , sizeof( V_188 -> V_84 ) ) ;
return F_8 ( & V_16 -> V_75 , V_169 , V_189 , V_188 ) ;
}
static int F_55 ( struct V_78 * V_78 , void * V_79 ,
const struct V_187 * V_188 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_188 -> V_99 != 0 )
return - V_52 ;
return F_8 ( & V_16 -> V_75 , V_169 , V_190 , V_188 ) ;
}
static int F_56 ( struct V_78 * V_78 , void * V_79 ,
struct V_191 * V_192 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_192 -> V_169 )
return - V_52 ;
return F_8 ( & V_16 -> V_75 , V_169 , V_193 , V_192 ) ;
}
static int F_57 ( struct V_78 * V_78 , void * V_79 ,
const struct V_191 * V_192 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_192 -> V_169 )
return - V_52 ;
return F_8 ( & V_16 -> V_75 , V_169 , V_194 , V_192 ) ;
}
static int F_58 ( struct V_78 * V_78 , void * V_79 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
F_59 ( V_78 , V_79 ) ;
return F_8 ( & V_16 -> V_75 , V_195 , V_196 ) ;
}
static int F_60 ( struct V_197 * V_173 ,
const struct V_198 * V_199 )
{
switch ( V_199 -> type ) {
case V_200 :
return F_61 ( V_173 , V_199 ) ;
case V_201 :
return F_62 ( V_173 , V_199 , 30 , NULL ) ;
}
return - V_52 ;
}
static int F_63 ( struct V_202 * V_203 )
{
struct V_15 * V_16 =
F_21 ( V_203 -> V_204 , struct V_15 , V_205 ) ;
unsigned V_206 ;
T_2 * V_207 ;
switch ( V_203 -> V_208 ) {
case V_209 :
V_16 -> V_210 [ 0 ] . V_211 = V_203 -> V_212 ;
break;
case V_213 :
V_16 -> V_210 [ 0 ] . V_214 = V_203 -> V_212 ;
break;
case V_215 :
V_16 -> V_210 [ 0 ] . V_216 = V_203 -> V_212 ;
break;
case V_217 :
V_16 -> V_210 [ 1 ] . V_211 = V_203 -> V_212 ;
break;
case V_218 :
V_16 -> V_210 [ 1 ] . V_214 = V_203 -> V_212 ;
break;
case V_219 :
V_16 -> V_210 [ 1 ] . V_216 = V_203 -> V_212 ;
break;
case V_220 :
V_16 -> V_210 [ 2 ] . V_211 = V_203 -> V_212 ;
break;
case V_221 :
V_16 -> V_210 [ 2 ] . V_214 = V_203 -> V_212 ;
break;
case V_222 :
V_16 -> V_210 [ 2 ] . V_216 = V_203 -> V_212 ;
break;
case V_223 :
V_16 -> V_210 [ 3 ] . V_211 = V_203 -> V_212 ;
break;
case V_224 :
V_16 -> V_210 [ 3 ] . V_214 = V_203 -> V_212 ;
break;
case V_225 :
V_16 -> V_210 [ 3 ] . V_216 = V_203 -> V_212 ;
break;
case V_226 :
V_207 = V_16 -> V_227 ;
for ( V_206 = 0 ; V_206 < V_16 -> V_18 / 16 ; V_206 ++ , V_207 += V_16 -> V_17 / 16 )
memcpy ( V_207 , V_203 -> V_228 . V_229 + V_206 * ( 720 / 16 ) , V_16 -> V_17 / 16 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
int F_64 ( struct V_15 * V_16 )
{
struct V_230 * V_205 = & V_16 -> V_205 ;
struct V_202 * V_203 ;
F_65 ( V_205 , 22 ) ;
V_16 -> V_36 = F_66 ( V_205 , NULL ,
V_231 , 0 , 34 , 1 , 15 ) ;
V_16 -> V_37 = F_66 ( V_205 , NULL ,
V_232 , 0 , 1 , 1 , 1 ) ;
V_16 -> V_40 = F_66 ( V_205 , NULL ,
V_233 ,
64000 , 10000000 , 1 , 9800000 ) ;
V_16 -> V_38 = F_66 ( V_205 , NULL ,
V_234 , 0 , 2 , 2 , 0 ) ;
V_16 -> V_41 = F_66 ( V_205 , NULL ,
V_235 , 0 , 1 , 1 , 1 ) ;
V_16 -> V_42 = F_67 ( V_205 , NULL ,
V_236 ,
V_46 , 0 ,
V_43 ) ;
V_203 = F_66 ( V_205 , NULL ,
V_237 , 0 ,
V_238 |
V_239 , 0 ,
V_238 |
V_239 ) ;
if ( V_203 )
V_203 -> V_92 |= V_240 ;
F_68 ( V_205 , & V_241 , NULL ) ;
F_68 ( V_205 , & V_242 , NULL ) ;
F_68 ( V_205 , & V_243 , NULL ) ;
F_68 ( V_205 , & V_244 , NULL ) ;
F_68 ( V_205 , & V_245 , NULL ) ;
F_68 ( V_205 , & V_246 , NULL ) ;
F_68 ( V_205 , & V_247 , NULL ) ;
F_68 ( V_205 , & V_248 , NULL ) ;
F_68 ( V_205 , & V_249 , NULL ) ;
F_68 ( V_205 , & V_250 , NULL ) ;
F_68 ( V_205 , & V_251 , NULL ) ;
F_68 ( V_205 , & V_252 , NULL ) ;
F_68 ( V_205 , & V_253 , NULL ) ;
V_16 -> V_254 = F_67 ( V_205 , NULL ,
V_255 ,
V_256 ,
1 << V_257 ,
V_258 ) ;
if ( V_205 -> error ) {
int V_259 = V_205 -> error ;
F_69 ( & V_16 -> V_75 , L_7 ) ;
return V_259 ;
}
V_16 -> V_75 . V_260 = V_205 ;
return 0 ;
}
int F_70 ( struct V_15 * V_16 )
{
struct V_261 * V_262 = & V_16 -> V_262 ;
int V_259 ;
F_71 ( & V_16 -> V_263 ) ;
F_71 ( & V_16 -> V_264 ) ;
F_36 ( & V_16 -> V_117 ) ;
V_16 -> V_102 . type = V_55 ;
V_16 -> V_102 . V_265 = V_266 | V_267 | V_268 ;
V_16 -> V_102 . V_269 = & V_270 ;
V_16 -> V_102 . V_271 = & V_272 ;
V_16 -> V_102 . V_273 = V_16 ;
V_16 -> V_102 . V_274 = sizeof( struct V_6 ) ;
V_16 -> V_102 . V_275 = V_276 ;
V_16 -> V_102 . V_277 = & V_16 -> V_264 ;
V_259 = F_72 ( & V_16 -> V_102 ) ;
if ( V_259 )
return V_259 ;
* V_262 = V_278 ;
V_262 -> V_277 = & V_16 -> V_263 ;
V_262 -> V_279 = & V_16 -> V_102 ;
F_73 ( V_262 , V_16 ) ;
V_262 -> V_75 = & V_16 -> V_75 ;
if ( ! F_74 ( & V_16 -> V_75 , V_130 , V_161 ) )
F_75 ( V_262 , V_280 ) ;
if ( ! ( V_16 -> V_23 -> V_92 & V_93 ) ) {
F_75 ( V_262 , V_281 ) ;
F_75 ( V_262 , V_282 ) ;
F_75 ( V_262 , V_283 ) ;
F_75 ( V_262 , V_284 ) ;
} else {
struct V_191 V_192 = {
. type = V_285 ,
. V_286 = 980 ,
} ;
F_8 ( & V_16 -> V_75 , V_169 , V_194 , & V_192 ) ;
}
if ( ! ( V_16 -> V_23 -> V_53 & V_170 ) ) {
F_75 ( V_262 , V_287 ) ;
F_75 ( V_262 , V_288 ) ;
V_262 -> V_171 = 0 ;
}
if ( V_16 -> V_23 -> V_53 & V_54 )
F_75 ( V_262 , V_289 ) ;
if ( V_16 -> V_23 -> V_90 == 0 ) {
F_75 ( V_262 , V_290 ) ;
F_75 ( V_262 , V_291 ) ;
F_75 ( V_262 , V_292 ) ;
}
if ( V_16 -> V_23 -> V_53 & V_293 )
F_51 ( V_16 -> V_183 , V_130 , V_294 ,
V_295 ,
V_296 | V_297 |
V_298 ) ;
F_52 ( V_16 ) ;
if ( V_16 -> V_23 -> V_53 & V_170 )
F_42 ( V_16 ) ;
V_259 = F_76 ( V_262 , V_299 , - 1 ) ;
if ( V_259 < 0 )
return V_259 ;
F_77 ( V_16 -> V_300 , L_8 ,
F_78 ( V_262 ) ) ;
return 0 ;
}
void F_79 ( struct V_15 * V_16 )
{
F_80 ( & V_16 -> V_205 ) ;
}
