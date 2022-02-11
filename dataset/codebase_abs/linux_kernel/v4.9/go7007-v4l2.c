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
unsigned int V_108 [] , struct V_109 * V_110 [] )
{
V_108 [ 0 ] = V_60 ;
* V_107 = 1 ;
if ( * V_106 < 2 )
* V_106 = 2 ;
return 0 ;
}
static void F_18 ( struct V_111 * V_7 )
{
struct V_104 * V_112 = V_7 -> V_104 ;
struct V_15 * V_16 = F_19 ( V_112 ) ;
struct V_113 * V_114 = F_20 ( V_7 ) ;
struct V_6 * V_115 =
F_21 ( V_114 , struct V_6 , V_7 ) ;
unsigned long V_92 ;
F_22 ( & V_16 -> V_116 , V_92 ) ;
F_23 ( & V_115 -> V_117 , & V_16 -> V_118 ) ;
F_24 ( & V_16 -> V_116 , V_92 ) ;
}
static int F_25 ( struct V_111 * V_7 )
{
struct V_113 * V_114 = F_20 ( V_7 ) ;
struct V_6 * V_115 =
F_21 ( V_114 , struct V_6 , V_7 ) ;
V_115 -> V_119 = 0 ;
V_115 -> V_12 = 0 ;
V_7 -> V_120 [ 0 ] . V_121 = 0 ;
return 0 ;
}
static void F_26 ( struct V_111 * V_7 )
{
struct V_104 * V_112 = V_7 -> V_104 ;
struct V_15 * V_16 = F_19 ( V_112 ) ;
struct V_113 * V_114 = F_20 ( V_7 ) ;
struct V_6 * V_115 =
F_21 ( V_114 , struct V_6 , V_7 ) ;
T_1 V_122 = F_2 ( V_115 , V_16 -> V_8 ) ;
V_114 -> V_92 &= ~ ( V_11 | V_14 |
V_13 ) ;
V_114 -> V_92 |= V_122 ;
V_114 -> V_56 = V_57 ;
}
static int F_27 ( struct V_104 * V_105 , unsigned int V_123 )
{
struct V_15 * V_16 = F_19 ( V_105 ) ;
int V_124 ;
F_5 ( V_16 ) ;
F_28 ( & V_16 -> V_125 ) ;
V_16 -> V_126 = 0 ;
V_16 -> V_127 = NULL ;
V_16 -> V_128 = 0 ;
V_105 -> V_129 = 1 ;
if ( F_29 ( V_16 ) < 0 )
V_124 = - V_130 ;
else
V_124 = 0 ;
F_30 ( & V_16 -> V_125 ) ;
if ( V_124 ) {
V_105 -> V_129 = 0 ;
return V_124 ;
}
F_8 ( & V_16 -> V_75 , V_131 , V_132 , 1 ) ;
F_31 ( V_16 -> V_36 , true ) ;
F_31 ( V_16 -> V_37 , true ) ;
F_31 ( V_16 -> V_40 , true ) ;
F_31 ( V_16 -> V_42 , true ) ;
if ( V_16 -> V_133 == V_134 )
F_32 ( V_16 , 0x3c82 , 0x0005 ) ;
return V_124 ;
}
static void F_33 ( struct V_104 * V_105 )
{
struct V_15 * V_16 = F_19 ( V_105 ) ;
unsigned long V_92 ;
V_105 -> V_129 = 0 ;
F_34 ( V_16 ) ;
F_28 ( & V_16 -> V_125 ) ;
F_35 ( V_16 ) ;
F_30 ( & V_16 -> V_125 ) ;
F_8 ( & V_16 -> V_75 , V_131 , V_132 , 0 ) ;
F_22 ( & V_16 -> V_116 , V_92 ) ;
F_36 ( & V_16 -> V_118 ) ;
F_24 ( & V_16 -> V_116 , V_92 ) ;
F_31 ( V_16 -> V_36 , false ) ;
F_31 ( V_16 -> V_37 , false ) ;
F_31 ( V_16 -> V_40 , false ) ;
F_31 ( V_16 -> V_42 , false ) ;
if ( V_16 -> V_133 == V_134 )
F_32 ( V_16 , 0x3c82 , 0x000d ) ;
}
static int F_37 ( struct V_78 * V_135 , void * V_79 ,
struct V_136 * V_137 )
{
struct V_15 * V_16 = F_10 ( V_135 ) ;
struct V_138 V_139 = {
. V_140 = 1001 * V_16 -> V_141 ,
. V_142 = V_16 -> V_143 ,
} ;
if ( V_137 -> type != V_55 )
return - V_52 ;
V_137 -> V_137 . V_144 . V_145 = 2 ;
V_137 -> V_137 . V_144 . V_146 = V_147 ;
V_137 -> V_137 . V_144 . V_139 = V_139 ;
return 0 ;
}
static int F_38 ( struct V_78 * V_135 , void * V_79 ,
struct V_136 * V_137 )
{
struct V_15 * V_16 = F_10 ( V_135 ) ;
unsigned int V_148 , V_149 ;
if ( V_137 -> type != V_55 )
return - V_52 ;
V_148 = V_16 -> V_143 *
V_137 -> V_137 . V_144 . V_139 . V_140 ;
V_149 = 1001 * V_137 -> V_137 . V_144 . V_139 . V_142 ;
if ( V_148 != 0 && V_149 != 0 && V_148 > V_149 )
V_16 -> V_141 = ( V_148 + V_149 / 2 ) / V_149 ;
else
V_16 -> V_141 = 1 ;
return F_37 ( V_135 , V_79 , V_137 ) ;
}
static int F_39 ( struct V_78 * V_135 , void * V_79 ,
struct V_150 * V_151 )
{
struct V_15 * V_16 = F_10 ( V_135 ) ;
int V_17 , V_18 ;
if ( V_151 -> V_99 > 2 )
return - V_52 ;
if ( ! F_1 ( V_151 -> V_152 ) )
return - V_52 ;
F_4 ( V_16 , & V_17 , & V_18 ) ;
V_151 -> type = V_153 ;
V_151 -> V_154 . V_17 = ( V_17 >> V_151 -> V_99 ) & ~ 0xf ;
V_151 -> V_154 . V_18 = ( V_18 >> V_151 -> V_99 ) & ~ 0xf ;
return 0 ;
}
static int F_40 ( struct V_78 * V_135 , void * V_79 ,
struct V_155 * V_156 )
{
struct V_15 * V_16 = F_10 ( V_135 ) ;
int V_17 , V_18 ;
int V_157 ;
if ( V_156 -> V_99 > 4 )
return - V_52 ;
if ( ! F_1 ( V_156 -> V_152 ) )
return - V_52 ;
if ( ! ( V_16 -> V_23 -> V_53 & V_54 ) ) {
F_4 ( V_16 , & V_17 , & V_18 ) ;
for ( V_157 = 0 ; V_157 <= 2 ; V_157 ++ )
if ( V_156 -> V_17 == ( ( V_17 >> V_157 ) & ~ 0xf ) &&
V_156 -> V_18 == ( ( V_18 >> V_157 ) & ~ 0xf ) )
break;
if ( V_157 > 2 )
return - V_52 ;
}
V_156 -> type = V_158 ;
V_156 -> V_154 . V_140 = 1001 * ( V_156 -> V_99 + 1 ) ;
V_156 -> V_154 . V_142 = V_16 -> V_143 ;
return 0 ;
}
static int F_41 ( struct V_78 * V_78 , void * V_79 , T_3 * V_159 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
* V_159 = V_16 -> V_159 ;
return 0 ;
}
static int F_42 ( struct V_15 * V_16 )
{
if ( V_16 -> V_159 & V_160 ) {
V_16 -> V_19 = V_21 ;
V_16 -> V_143 = 25025 ;
} else {
V_16 -> V_19 = V_20 ;
V_16 -> V_143 = 30000 ;
}
F_8 ( & V_16 -> V_75 , V_131 , V_161 , V_16 -> V_159 ) ;
F_7 ( V_16 , NULL , 0 ) ;
return 0 ;
}
static int F_43 ( struct V_78 * V_78 , void * V_79 , T_3 V_159 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( F_16 ( & V_16 -> V_102 ) )
return - V_103 ;
V_16 -> V_159 = V_159 ;
return F_42 ( V_16 ) ;
}
static int F_44 ( struct V_78 * V_78 , void * V_79 , T_3 * V_159 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
return F_8 ( & V_16 -> V_75 , V_131 , V_162 , V_159 ) ;
}
static int F_45 ( struct V_78 * V_78 , void * V_79 ,
struct V_163 * V_164 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_164 -> V_99 >= V_16 -> V_23 -> V_165 )
return - V_52 ;
strncpy ( V_164 -> V_84 , V_16 -> V_23 -> V_166 [ V_164 -> V_99 ] . V_84 ,
sizeof( V_164 -> V_84 ) ) ;
if ( ( V_16 -> V_23 -> V_92 & V_93 ) &&
V_164 -> V_99 == 0 )
V_164 -> type = V_167 ;
else
V_164 -> type = V_168 ;
if ( V_16 -> V_23 -> V_90 )
V_164 -> V_169 = ( 1 << V_16 -> V_23 -> V_90 ) - 1 ;
else
V_164 -> V_169 = 0 ;
V_164 -> V_170 = 0 ;
if ( V_16 -> V_23 -> V_53 & V_171 )
V_164 -> V_159 = F_46 ( V_78 ) -> V_172 ;
else
V_164 -> V_159 = 0 ;
return 0 ;
}
static int F_47 ( struct V_78 * V_78 , void * V_79 , unsigned int * V_173 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
* V_173 = V_16 -> V_173 ;
return 0 ;
}
static int F_48 ( struct V_78 * V_78 , void * V_174 , struct V_175 * V_176 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_176 -> V_99 >= V_16 -> V_23 -> V_90 )
return - V_52 ;
F_11 ( V_176 -> V_84 , V_16 -> V_23 -> V_177 [ V_176 -> V_99 ] . V_84 ,
sizeof( V_176 -> V_84 ) ) ;
V_176 -> V_146 = V_178 ;
return 0 ;
}
static int F_49 ( struct V_78 * V_78 , void * V_174 , struct V_175 * V_176 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
V_176 -> V_99 = V_16 -> V_179 ;
F_11 ( V_176 -> V_84 , V_16 -> V_23 -> V_177 [ V_16 -> V_179 ] . V_84 ,
sizeof( V_176 -> V_84 ) ) ;
V_176 -> V_146 = V_178 ;
return 0 ;
}
static int F_50 ( struct V_78 * V_78 , void * V_174 ,
const struct V_175 * V_176 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_176 -> V_99 >= V_16 -> V_23 -> V_90 )
return - V_52 ;
V_16 -> V_179 = V_176 -> V_99 ;
F_51 ( V_16 -> V_180 , V_181 , V_182 ,
V_16 -> V_23 -> V_177 [ V_16 -> V_179 ] . V_183 , 0 , 0 ) ;
return 0 ;
}
static void F_52 ( struct V_15 * V_16 )
{
unsigned int V_173 = V_16 -> V_173 ;
F_51 ( V_16 -> V_184 , V_131 , V_182 ,
V_16 -> V_23 -> V_166 [ V_173 ] . V_185 , 0 ,
V_16 -> V_23 -> V_186 ) ;
if ( V_16 -> V_23 -> V_90 ) {
int V_179 = V_16 -> V_23 -> V_166 [ V_173 ] . V_187 ;
F_51 ( V_16 -> V_180 , V_181 , V_182 ,
V_16 -> V_23 -> V_177 [ V_179 ] . V_183 , 0 , 0 ) ;
V_16 -> V_179 = V_179 ;
}
}
static int F_53 ( struct V_78 * V_78 , void * V_79 , unsigned int V_173 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_173 >= V_16 -> V_23 -> V_165 )
return - V_52 ;
if ( F_16 ( & V_16 -> V_102 ) )
return - V_103 ;
V_16 -> V_173 = V_173 ;
F_52 ( V_16 ) ;
return 0 ;
}
static int F_54 ( struct V_78 * V_78 , void * V_79 ,
struct V_188 * V_189 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_189 -> V_99 != 0 )
return - V_52 ;
F_11 ( V_189 -> V_84 , L_6 , sizeof( V_189 -> V_84 ) ) ;
return F_8 ( & V_16 -> V_75 , V_170 , V_190 , V_189 ) ;
}
static int F_55 ( struct V_78 * V_78 , void * V_79 ,
const struct V_188 * V_189 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_189 -> V_99 != 0 )
return - V_52 ;
return F_8 ( & V_16 -> V_75 , V_170 , V_191 , V_189 ) ;
}
static int F_56 ( struct V_78 * V_78 , void * V_79 ,
struct V_192 * V_193 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_193 -> V_170 )
return - V_52 ;
return F_8 ( & V_16 -> V_75 , V_170 , V_194 , V_193 ) ;
}
static int F_57 ( struct V_78 * V_78 , void * V_79 ,
const struct V_192 * V_193 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
if ( V_193 -> V_170 )
return - V_52 ;
return F_8 ( & V_16 -> V_75 , V_170 , V_195 , V_193 ) ;
}
static int F_58 ( struct V_78 * V_78 , void * V_79 )
{
struct V_15 * V_16 = F_10 ( V_78 ) ;
F_59 ( V_78 , V_79 ) ;
return F_8 ( & V_16 -> V_75 , V_196 , V_197 ) ;
}
static int F_60 ( struct V_198 * V_174 ,
const struct V_199 * V_200 )
{
switch ( V_200 -> type ) {
case V_201 :
return F_61 ( V_174 , V_200 ) ;
case V_202 :
return F_62 ( V_174 , V_200 , 30 , NULL ) ;
}
return - V_52 ;
}
static int F_63 ( struct V_203 * V_204 )
{
struct V_15 * V_16 =
F_21 ( V_204 -> V_205 , struct V_15 , V_206 ) ;
unsigned V_207 ;
T_2 * V_208 ;
switch ( V_204 -> V_209 ) {
case V_210 :
V_16 -> V_211 [ 0 ] . V_212 = V_204 -> V_213 ;
break;
case V_214 :
V_16 -> V_211 [ 0 ] . V_215 = V_204 -> V_213 ;
break;
case V_216 :
V_16 -> V_211 [ 0 ] . V_217 = V_204 -> V_213 ;
break;
case V_218 :
V_16 -> V_211 [ 1 ] . V_212 = V_204 -> V_213 ;
break;
case V_219 :
V_16 -> V_211 [ 1 ] . V_215 = V_204 -> V_213 ;
break;
case V_220 :
V_16 -> V_211 [ 1 ] . V_217 = V_204 -> V_213 ;
break;
case V_221 :
V_16 -> V_211 [ 2 ] . V_212 = V_204 -> V_213 ;
break;
case V_222 :
V_16 -> V_211 [ 2 ] . V_215 = V_204 -> V_213 ;
break;
case V_223 :
V_16 -> V_211 [ 2 ] . V_217 = V_204 -> V_213 ;
break;
case V_224 :
V_16 -> V_211 [ 3 ] . V_212 = V_204 -> V_213 ;
break;
case V_225 :
V_16 -> V_211 [ 3 ] . V_215 = V_204 -> V_213 ;
break;
case V_226 :
V_16 -> V_211 [ 3 ] . V_217 = V_204 -> V_213 ;
break;
case V_227 :
V_208 = V_16 -> V_228 ;
for ( V_207 = 0 ; V_207 < V_16 -> V_18 / 16 ; V_207 ++ , V_208 += V_16 -> V_17 / 16 )
memcpy ( V_208 , V_204 -> V_229 . V_230 + V_207 * ( 720 / 16 ) , V_16 -> V_17 / 16 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
int F_64 ( struct V_15 * V_16 )
{
struct V_231 * V_206 = & V_16 -> V_206 ;
struct V_203 * V_204 ;
F_65 ( V_206 , 22 ) ;
V_16 -> V_36 = F_66 ( V_206 , NULL ,
V_232 , 0 , 34 , 1 , 15 ) ;
V_16 -> V_37 = F_66 ( V_206 , NULL ,
V_233 , 0 , 1 , 1 , 1 ) ;
V_16 -> V_40 = F_66 ( V_206 , NULL ,
V_234 ,
64000 , 10000000 , 1 , 9800000 ) ;
V_16 -> V_38 = F_66 ( V_206 , NULL ,
V_235 , 0 , 2 , 2 , 0 ) ;
V_16 -> V_41 = F_66 ( V_206 , NULL ,
V_236 , 0 , 1 , 1 , 1 ) ;
V_16 -> V_42 = F_67 ( V_206 , NULL ,
V_237 ,
V_46 , 0 ,
V_43 ) ;
V_204 = F_66 ( V_206 , NULL ,
V_238 , 0 ,
V_239 |
V_240 , 0 ,
V_239 |
V_240 ) ;
if ( V_204 )
V_204 -> V_92 |= V_241 ;
F_68 ( V_206 , & V_242 , NULL ) ;
F_68 ( V_206 , & V_243 , NULL ) ;
F_68 ( V_206 , & V_244 , NULL ) ;
F_68 ( V_206 , & V_245 , NULL ) ;
F_68 ( V_206 , & V_246 , NULL ) ;
F_68 ( V_206 , & V_247 , NULL ) ;
F_68 ( V_206 , & V_248 , NULL ) ;
F_68 ( V_206 , & V_249 , NULL ) ;
F_68 ( V_206 , & V_250 , NULL ) ;
F_68 ( V_206 , & V_251 , NULL ) ;
F_68 ( V_206 , & V_252 , NULL ) ;
F_68 ( V_206 , & V_253 , NULL ) ;
F_68 ( V_206 , & V_254 , NULL ) ;
V_16 -> V_255 = F_67 ( V_206 , NULL ,
V_256 ,
V_257 ,
1 << V_258 ,
V_259 ) ;
if ( V_206 -> error ) {
int V_260 = V_206 -> error ;
F_69 ( & V_16 -> V_75 , L_7 ) ;
return V_260 ;
}
V_16 -> V_75 . V_261 = V_206 ;
return 0 ;
}
int F_70 ( struct V_15 * V_16 )
{
struct V_262 * V_263 = & V_16 -> V_263 ;
int V_260 ;
F_71 ( & V_16 -> V_264 ) ;
F_71 ( & V_16 -> V_265 ) ;
F_36 ( & V_16 -> V_118 ) ;
V_16 -> V_102 . type = V_55 ;
V_16 -> V_102 . V_266 = V_267 | V_268 | V_269 ;
V_16 -> V_102 . V_270 = & V_271 ;
V_16 -> V_102 . V_272 = & V_273 ;
V_16 -> V_102 . V_274 = V_16 ;
V_16 -> V_102 . V_275 = sizeof( struct V_6 ) ;
V_16 -> V_102 . V_276 = V_277 ;
V_16 -> V_102 . V_278 = & V_16 -> V_265 ;
V_260 = F_72 ( & V_16 -> V_102 ) ;
if ( V_260 )
return V_260 ;
* V_263 = V_279 ;
V_263 -> V_278 = & V_16 -> V_264 ;
V_263 -> V_280 = & V_16 -> V_102 ;
F_73 ( V_263 , V_16 ) ;
V_263 -> V_75 = & V_16 -> V_75 ;
if ( ! F_74 ( & V_16 -> V_75 , 0 , V_131 , V_162 ) )
F_75 ( V_263 , V_281 ) ;
if ( ! ( V_16 -> V_23 -> V_92 & V_93 ) ) {
F_75 ( V_263 , V_282 ) ;
F_75 ( V_263 , V_283 ) ;
F_75 ( V_263 , V_284 ) ;
F_75 ( V_263 , V_285 ) ;
} else {
struct V_192 V_193 = {
. type = V_286 ,
. V_287 = 980 ,
} ;
F_8 ( & V_16 -> V_75 , V_170 , V_195 , & V_193 ) ;
}
if ( ! ( V_16 -> V_23 -> V_53 & V_171 ) ) {
F_75 ( V_263 , V_288 ) ;
F_75 ( V_263 , V_289 ) ;
V_263 -> V_172 = 0 ;
}
if ( V_16 -> V_23 -> V_53 & V_54 )
F_75 ( V_263 , V_290 ) ;
if ( V_16 -> V_23 -> V_90 == 0 ) {
F_75 ( V_263 , V_291 ) ;
F_75 ( V_263 , V_292 ) ;
F_75 ( V_263 , V_293 ) ;
}
if ( V_16 -> V_23 -> V_53 & V_294 )
F_51 ( V_16 -> V_184 , V_131 , V_295 ,
V_296 ,
V_297 | V_298 |
V_299 ) ;
F_52 ( V_16 ) ;
if ( V_16 -> V_23 -> V_53 & V_171 )
F_42 ( V_16 ) ;
V_260 = F_76 ( V_263 , V_300 , - 1 ) ;
if ( V_260 < 0 )
return V_260 ;
F_77 ( V_16 -> V_301 , L_8 ,
F_78 ( V_263 ) ) ;
return 0 ;
}
void F_79 ( struct V_15 * V_16 )
{
F_80 ( & V_16 -> V_206 ) ;
}
