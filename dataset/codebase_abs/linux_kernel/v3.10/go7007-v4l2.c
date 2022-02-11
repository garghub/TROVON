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
int V_16 , V_17 , V_50 ;
if ( V_48 != NULL && ! F_1 ( V_48 -> V_48 . V_51 . V_1 ) )
return - V_52 ;
F_4 ( V_15 , & V_23 , & V_24 ) ;
if ( V_48 == NULL ) {
V_16 = V_23 ;
V_17 = V_24 ;
} else if ( V_15 -> V_22 -> V_53 & V_54 ) {
if ( V_48 -> V_48 . V_51 . V_16 > V_23 )
V_16 = V_23 ;
else if ( V_48 -> V_48 . V_51 . V_16 < 144 )
V_16 = 144 ;
else
V_16 = V_48 -> V_48 . V_51 . V_16 & ~ 0x0f ;
if ( V_48 -> V_48 . V_51 . V_17 > V_24 )
V_17 = V_24 ;
else if ( V_48 -> V_48 . V_51 . V_17 < 96 )
V_17 = 96 ;
else
V_17 = V_48 -> V_48 . V_51 . V_17 & ~ 0x0f ;
} else {
V_16 = V_48 -> V_48 . V_51 . V_16 ;
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
T_1 V_1 = V_48 -> V_48 . V_51 . V_1 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> type = V_55 ;
V_48 -> V_48 . V_51 . V_16 = V_16 ;
V_48 -> V_48 . V_51 . V_17 = V_17 ;
V_48 -> V_48 . V_51 . V_1 = V_1 ;
V_48 -> V_48 . V_51 . V_56 = V_57 ;
V_48 -> V_48 . V_51 . V_58 = 0 ;
V_48 -> V_48 . V_51 . V_59 = V_60 ;
V_48 -> V_48 . V_51 . V_61 = V_62 ;
}
if ( V_49 )
return 0 ;
if ( V_48 )
V_15 -> V_8 = V_48 -> V_48 . V_51 . V_1 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_63 = V_15 -> V_22 -> V_64 ;
V_15 -> V_65 = V_15 -> V_22 -> V_66 ;
for ( V_50 = 0 ; V_50 < 4 ; ++ V_50 )
V_15 -> V_67 [ V_50 ] . V_68 = 0 ;
for ( V_50 = 0 ; V_50 < 1624 ; ++ V_50 )
V_15 -> V_69 [ V_50 ] = 0 ;
if ( V_15 -> V_22 -> V_53 & V_54 ) {
struct V_70 V_71 ;
V_71 . V_72 = V_73 ;
V_71 . V_16 = V_48 ? V_48 -> V_48 . V_51 . V_16 : V_16 ;
V_71 . V_17 = V_17 ;
V_15 -> V_74 = 0 ;
V_15 -> V_75 = 0 ;
V_15 -> V_76 = 0 ;
F_8 ( & V_15 -> V_77 , V_78 , V_79 , & V_71 ) ;
} else {
if ( V_16 <= V_23 / 4 ) {
V_15 -> V_74 = 1 ;
V_15 -> V_75 = 1 ;
V_15 -> V_76 = 1 ;
} else if ( V_16 <= V_23 / 2 ) {
V_15 -> V_74 = 1 ;
V_15 -> V_75 = 1 ;
V_15 -> V_76 = 0 ;
} else {
V_15 -> V_74 = 0 ;
V_15 -> V_75 = 0 ;
V_15 -> V_76 = 0 ;
}
}
return 0 ;
}
static int F_9 ( struct V_80 * V_80 , void * V_81 ,
struct V_82 * V_83 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
F_11 ( V_83 -> V_84 , L_1 , sizeof( V_83 -> V_84 ) ) ;
F_11 ( V_83 -> V_85 , V_15 -> V_86 , sizeof( V_83 -> V_85 ) ) ;
F_11 ( V_83 -> V_87 , V_15 -> V_87 , sizeof( V_83 -> V_87 ) ) ;
V_83 -> V_88 = V_89 | V_90 |
V_91 ;
if ( V_15 -> V_22 -> V_92 )
V_83 -> V_88 |= V_93 ;
if ( V_15 -> V_22 -> V_94 & V_95 )
V_83 -> V_88 |= V_96 ;
V_83 -> V_97 = V_83 -> V_88 | V_98 ;
return 0 ;
}
static int F_12 ( struct V_80 * V_80 , void * V_81 ,
struct V_99 * V_48 )
{
char * V_100 = NULL ;
switch ( V_48 -> V_101 ) {
case 0 :
V_48 -> V_1 = V_2 ;
V_100 = L_2 ;
break;
case 1 :
V_48 -> V_1 = V_3 ;
V_100 = L_3 ;
break;
case 2 :
V_48 -> V_1 = V_4 ;
V_100 = L_4 ;
break;
case 3 :
V_48 -> V_1 = V_5 ;
V_100 = L_5 ;
break;
default:
return - V_52 ;
}
V_48 -> type = V_55 ;
V_48 -> V_94 = V_102 ;
strncpy ( V_48 -> V_103 , V_100 , sizeof( V_48 -> V_103 ) ) ;
return 0 ;
}
static int F_13 ( struct V_80 * V_80 , void * V_81 ,
struct V_47 * V_48 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
V_48 -> type = V_55 ;
V_48 -> V_48 . V_51 . V_16 = V_15 -> V_16 ;
V_48 -> V_48 . V_51 . V_17 = V_15 -> V_17 ;
V_48 -> V_48 . V_51 . V_1 = V_15 -> V_8 ;
V_48 -> V_48 . V_51 . V_56 = V_57 ;
V_48 -> V_48 . V_51 . V_58 = 0 ;
V_48 -> V_48 . V_51 . V_59 = V_60 ;
V_48 -> V_48 . V_51 . V_61 = V_62 ;
return 0 ;
}
static int F_14 ( struct V_80 * V_80 , void * V_81 ,
struct V_47 * V_48 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
return F_7 ( V_15 , V_48 , 1 ) ;
}
static int F_15 ( struct V_80 * V_80 , void * V_81 ,
struct V_47 * V_48 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
if ( F_16 ( & V_15 -> V_104 ) )
return - V_105 ;
return F_7 ( V_15 , V_48 , 0 ) ;
}
static int F_17 ( struct V_106 * V_107 , const struct V_47 * V_48 ,
unsigned int * V_108 , unsigned int * V_109 ,
unsigned int V_110 [] , void * V_111 [] )
{
V_110 [ 0 ] = V_60 ;
* V_109 = 1 ;
if ( * V_108 < 2 )
* V_108 = 2 ;
return 0 ;
}
static void F_18 ( struct V_112 * V_7 )
{
struct V_106 * V_113 = V_7 -> V_106 ;
struct V_14 * V_15 = F_19 ( V_113 ) ;
struct V_6 * V_114 =
F_20 ( V_7 , struct V_6 , V_7 ) ;
unsigned long V_94 ;
F_21 ( & V_15 -> V_115 , V_94 ) ;
F_22 ( & V_114 -> V_116 , & V_15 -> V_117 ) ;
F_23 ( & V_15 -> V_115 , V_94 ) ;
}
static int F_24 ( struct V_112 * V_7 )
{
struct V_6 * V_114 =
F_20 ( V_7 , struct V_6 , V_7 ) ;
V_114 -> V_118 = 0 ;
V_114 -> V_11 = 0 ;
V_7 -> V_119 [ 0 ] . V_120 = 0 ;
return 0 ;
}
static int F_25 ( struct V_112 * V_7 )
{
struct V_106 * V_113 = V_7 -> V_106 ;
struct V_14 * V_15 = F_19 ( V_113 ) ;
struct V_6 * V_114 =
F_20 ( V_7 , struct V_6 , V_7 ) ;
T_1 V_121 = F_2 ( V_114 , V_15 -> V_8 ) ;
struct V_122 * V_123 = & V_7 -> V_124 ;
V_123 -> V_94 &= ~ ( V_10 | V_13 |
V_12 ) ;
V_123 -> V_94 |= V_121 ;
V_123 -> V_56 = V_57 ;
return 0 ;
}
static int F_26 ( struct V_106 * V_107 , unsigned int V_125 )
{
struct V_14 * V_15 = F_19 ( V_107 ) ;
int V_126 ;
F_5 ( V_15 ) ;
F_27 ( & V_15 -> V_127 ) ;
V_15 -> V_128 = 0 ;
V_15 -> V_129 = NULL ;
V_107 -> V_130 = 1 ;
if ( F_28 ( V_15 ) < 0 )
V_126 = - V_131 ;
else
V_126 = 0 ;
F_29 ( & V_15 -> V_127 ) ;
if ( V_126 ) {
V_107 -> V_130 = 0 ;
return V_126 ;
}
F_8 ( & V_15 -> V_77 , V_78 , V_132 , 1 ) ;
F_30 ( V_15 -> V_35 , true ) ;
F_30 ( V_15 -> V_36 , true ) ;
F_30 ( V_15 -> V_39 , true ) ;
F_30 ( V_15 -> V_41 , true ) ;
if ( V_15 -> V_133 == V_134 )
F_31 ( V_15 , 0x3c82 , 0x0005 ) ;
return V_126 ;
}
static int F_32 ( struct V_106 * V_107 )
{
struct V_14 * V_15 = F_19 ( V_107 ) ;
unsigned long V_94 ;
V_107 -> V_130 = 0 ;
F_33 ( V_15 ) ;
F_27 ( & V_15 -> V_127 ) ;
F_34 ( V_15 ) ;
F_29 ( & V_15 -> V_127 ) ;
F_8 ( & V_15 -> V_77 , V_78 , V_132 , 0 ) ;
F_21 ( & V_15 -> V_115 , V_94 ) ;
F_35 ( & V_15 -> V_117 ) ;
F_23 ( & V_15 -> V_115 , V_94 ) ;
F_30 ( V_15 -> V_35 , false ) ;
F_30 ( V_15 -> V_36 , false ) ;
F_30 ( V_15 -> V_39 , false ) ;
F_30 ( V_15 -> V_41 , false ) ;
if ( V_15 -> V_133 == V_134 )
F_31 ( V_15 , 0x3c82 , 0x000d ) ;
return 0 ;
}
static int F_36 ( struct V_80 * V_135 , void * V_81 ,
struct V_136 * V_137 )
{
struct V_14 * V_15 = F_10 ( V_135 ) ;
struct V_138 V_139 = {
. V_140 = 1001 * V_15 -> V_141 ,
. V_142 = V_15 -> V_143 ,
} ;
if ( V_137 -> type != V_55 )
return - V_52 ;
V_137 -> V_137 . V_144 . V_145 = 2 ;
V_137 -> V_137 . V_144 . V_146 = V_147 ;
V_137 -> V_137 . V_144 . V_139 = V_139 ;
return 0 ;
}
static int F_37 ( struct V_80 * V_135 , void * V_81 ,
struct V_136 * V_137 )
{
struct V_14 * V_15 = F_10 ( V_135 ) ;
unsigned int V_148 , V_149 ;
if ( V_137 -> type != V_55 )
return - V_52 ;
V_148 = V_15 -> V_143 *
V_137 -> V_137 . V_144 . V_139 . V_140 ;
V_149 = 1001 * V_137 -> V_137 . V_144 . V_139 . V_142 ;
if ( V_148 != 0 && V_149 != 0 && V_148 > V_149 )
V_15 -> V_141 = ( V_148 + V_149 / 2 ) / V_149 ;
else
V_15 -> V_141 = 1 ;
return F_36 ( V_135 , V_81 , V_137 ) ;
}
static int F_38 ( struct V_80 * V_135 , void * V_81 ,
struct V_150 * V_151 )
{
struct V_14 * V_15 = F_10 ( V_135 ) ;
int V_16 , V_17 ;
if ( V_151 -> V_101 > 2 )
return - V_52 ;
if ( ! F_1 ( V_151 -> V_152 ) )
return - V_52 ;
F_4 ( V_15 , & V_16 , & V_17 ) ;
V_151 -> type = V_153 ;
V_151 -> V_154 . V_16 = ( V_16 >> V_151 -> V_101 ) & ~ 0xf ;
V_151 -> V_154 . V_17 = ( V_17 >> V_151 -> V_101 ) & ~ 0xf ;
return 0 ;
}
static int F_39 ( struct V_80 * V_135 , void * V_81 ,
struct V_155 * V_156 )
{
struct V_14 * V_15 = F_10 ( V_135 ) ;
int V_16 , V_17 ;
int V_50 ;
if ( V_156 -> V_101 > 4 )
return - V_52 ;
if ( ! F_1 ( V_156 -> V_152 ) )
return - V_52 ;
if ( ! ( V_15 -> V_22 -> V_53 & V_54 ) ) {
F_4 ( V_15 , & V_16 , & V_17 ) ;
for ( V_50 = 0 ; V_50 <= 2 ; V_50 ++ )
if ( V_156 -> V_16 == ( ( V_16 >> V_50 ) & ~ 0xf ) &&
V_156 -> V_17 == ( ( V_17 >> V_50 ) & ~ 0xf ) )
break;
if ( V_50 > 2 )
return - V_52 ;
}
V_156 -> type = V_157 ;
V_156 -> V_154 . V_140 = 1001 * ( V_156 -> V_101 + 1 ) ;
V_156 -> V_154 . V_142 = V_15 -> V_143 ;
return 0 ;
}
static int F_40 ( struct V_80 * V_80 , void * V_81 , T_3 * V_158 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
* V_158 = V_15 -> V_158 ;
return 0 ;
}
static int F_41 ( struct V_14 * V_15 )
{
if ( V_15 -> V_158 & V_159 ) {
V_15 -> V_18 = V_20 ;
V_15 -> V_143 = 25025 ;
} else {
V_15 -> V_18 = V_19 ;
V_15 -> V_143 = 30000 ;
}
F_8 ( & V_15 -> V_77 , V_160 , V_161 , V_15 -> V_158 ) ;
F_7 ( V_15 , NULL , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_80 * V_80 , void * V_81 , T_3 V_158 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
if ( F_16 ( & V_15 -> V_104 ) )
return - V_105 ;
V_15 -> V_158 = V_158 ;
return F_41 ( V_15 ) ;
}
static int F_43 ( struct V_80 * V_80 , void * V_81 , T_3 * V_158 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
return F_8 ( & V_15 -> V_77 , V_78 , V_162 , V_158 ) ;
}
static int F_44 ( struct V_80 * V_80 , void * V_81 ,
struct V_163 * V_164 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
if ( V_164 -> V_101 >= V_15 -> V_22 -> V_165 )
return - V_52 ;
strncpy ( V_164 -> V_86 , V_15 -> V_22 -> V_166 [ V_164 -> V_101 ] . V_86 ,
sizeof( V_164 -> V_86 ) ) ;
if ( ( V_15 -> V_22 -> V_94 & V_95 ) &&
V_164 -> V_101 == 0 )
V_164 -> type = V_167 ;
else
V_164 -> type = V_168 ;
if ( V_15 -> V_22 -> V_92 )
V_164 -> V_169 = ( 1 << V_15 -> V_22 -> V_92 ) - 1 ;
else
V_164 -> V_169 = 0 ;
V_164 -> V_170 = 0 ;
if ( V_15 -> V_22 -> V_53 & V_171 )
V_164 -> V_158 = F_45 ( V_80 ) -> V_172 ;
else
V_164 -> V_158 = 0 ;
return 0 ;
}
static int F_46 ( struct V_80 * V_80 , void * V_81 , unsigned int * V_173 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
* V_173 = V_15 -> V_173 ;
return 0 ;
}
static int F_47 ( struct V_80 * V_80 , void * V_174 , struct V_175 * V_176 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
if ( V_176 -> V_101 >= V_15 -> V_22 -> V_92 )
return - V_52 ;
F_11 ( V_176 -> V_86 , V_15 -> V_22 -> V_177 [ V_176 -> V_101 ] . V_86 , sizeof( V_176 -> V_86 ) ) ;
V_176 -> V_146 = V_178 ;
return 0 ;
}
static int F_48 ( struct V_80 * V_80 , void * V_174 , struct V_175 * V_176 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
V_176 -> V_101 = V_15 -> V_179 ;
F_11 ( V_176 -> V_86 , V_15 -> V_22 -> V_177 [ V_15 -> V_179 ] . V_86 , sizeof( V_176 -> V_86 ) ) ;
V_176 -> V_146 = V_178 ;
return 0 ;
}
static int F_49 ( struct V_80 * V_80 , void * V_174 , const struct V_175 * V_176 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
if ( V_176 -> V_101 >= V_15 -> V_22 -> V_92 )
return - V_52 ;
V_15 -> V_179 = V_176 -> V_101 ;
F_50 ( V_15 -> V_180 , V_181 , V_182 ,
V_15 -> V_22 -> V_177 [ V_15 -> V_179 ] . V_183 , 0 , 0 ) ;
return 0 ;
}
static void F_51 ( struct V_14 * V_15 )
{
unsigned int V_173 = V_15 -> V_173 ;
F_50 ( V_15 -> V_184 , V_78 , V_182 ,
V_15 -> V_22 -> V_166 [ V_173 ] . V_185 , 0 ,
V_15 -> V_22 -> V_186 ) ;
if ( V_15 -> V_22 -> V_92 ) {
int V_179 = V_15 -> V_22 -> V_166 [ V_173 ] . V_187 ;
F_50 ( V_15 -> V_180 , V_181 , V_182 ,
V_15 -> V_22 -> V_177 [ V_179 ] . V_183 , 0 , 0 ) ;
V_15 -> V_179 = V_179 ;
}
}
static int F_52 ( struct V_80 * V_80 , void * V_81 , unsigned int V_173 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
if ( V_173 >= V_15 -> V_22 -> V_165 )
return - V_52 ;
if ( F_16 ( & V_15 -> V_104 ) )
return - V_105 ;
V_15 -> V_173 = V_173 ;
F_51 ( V_15 ) ;
return 0 ;
}
static int F_53 ( struct V_80 * V_80 , void * V_81 ,
struct V_188 * V_189 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
if ( V_189 -> V_101 != 0 )
return - V_52 ;
F_11 ( V_189 -> V_86 , L_6 , sizeof( V_189 -> V_86 ) ) ;
return F_8 ( & V_15 -> V_77 , V_170 , V_190 , V_189 ) ;
}
static int F_54 ( struct V_80 * V_80 , void * V_81 ,
const struct V_188 * V_189 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
if ( V_189 -> V_101 != 0 )
return - V_52 ;
return F_8 ( & V_15 -> V_77 , V_170 , V_191 , V_189 ) ;
}
static int F_55 ( struct V_80 * V_80 , void * V_81 ,
struct V_192 * V_193 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
if ( V_193 -> V_170 )
return - V_52 ;
return F_8 ( & V_15 -> V_77 , V_170 , V_194 , V_193 ) ;
}
static int F_56 ( struct V_80 * V_80 , void * V_81 ,
const struct V_192 * V_193 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
if ( V_193 -> V_170 )
return - V_52 ;
return F_8 ( & V_15 -> V_77 , V_170 , V_195 , V_193 ) ;
}
static int F_57 ( struct V_80 * V_80 , void * V_81 )
{
struct V_14 * V_15 = F_10 ( V_80 ) ;
F_58 ( V_80 , V_81 ) ;
return F_8 ( & V_15 -> V_77 , V_160 , V_196 ) ;
}
int F_59 ( struct V_14 * V_15 )
{
struct V_197 * V_198 = & V_15 -> V_198 ;
struct V_199 * V_200 ;
F_60 ( V_198 , 13 ) ;
V_15 -> V_35 = F_61 ( V_198 , NULL ,
V_201 , 0 , 34 , 1 , 15 ) ;
V_15 -> V_36 = F_61 ( V_198 , NULL ,
V_202 , 0 , 1 , 1 , 1 ) ;
V_15 -> V_39 = F_61 ( V_198 , NULL ,
V_203 ,
64000 , 10000000 , 1 , 9800000 ) ;
V_15 -> V_37 = F_61 ( V_198 , NULL ,
V_204 , 0 , 2 , 2 , 0 ) ;
V_15 -> V_40 = F_61 ( V_198 , NULL ,
V_205 , 0 , 1 , 1 , 1 ) ;
V_15 -> V_41 = F_62 ( V_198 , NULL ,
V_206 ,
V_45 , 0 ,
V_42 ) ;
V_200 = F_61 ( V_198 , NULL ,
V_207 , 0 ,
V_208 | V_209 , 0 ,
V_208 | V_209 ) ;
if ( V_200 )
V_200 -> V_94 |= V_210 ;
if ( V_198 -> error ) {
int V_211 = V_198 -> error ;
F_63 ( & V_15 -> V_77 , L_7 ) ;
return V_211 ;
}
V_15 -> V_77 . V_212 = V_198 ;
return 0 ;
}
int F_64 ( struct V_14 * V_15 )
{
struct V_213 * V_214 = & V_15 -> V_214 ;
int V_211 ;
F_65 ( & V_15 -> V_215 ) ;
F_65 ( & V_15 -> V_216 ) ;
F_35 ( & V_15 -> V_117 ) ;
V_15 -> V_104 . type = V_55 ;
V_15 -> V_104 . V_217 = V_218 | V_219 | V_220 ;
V_15 -> V_104 . V_221 = & V_222 ;
V_15 -> V_104 . V_223 = & V_224 ;
V_15 -> V_104 . V_225 = V_15 ;
V_15 -> V_104 . V_226 = sizeof( struct V_6 ) ;
V_15 -> V_104 . V_227 = V_228 ;
V_15 -> V_104 . V_229 = & V_15 -> V_216 ;
V_211 = F_66 ( & V_15 -> V_104 ) ;
if ( V_211 )
return V_211 ;
* V_214 = V_230 ;
V_214 -> V_229 = & V_15 -> V_215 ;
V_214 -> V_231 = & V_15 -> V_104 ;
F_67 ( V_232 , & V_214 -> V_94 ) ;
F_68 ( V_214 , V_15 ) ;
V_214 -> V_77 = & V_15 -> V_77 ;
if ( ! F_69 ( & V_15 -> V_77 , V_78 , V_162 ) )
F_70 ( V_214 , V_233 ) ;
if ( ! ( V_15 -> V_22 -> V_94 & V_95 ) ) {
F_70 ( V_214 , V_234 ) ;
F_70 ( V_214 , V_235 ) ;
F_70 ( V_214 , V_236 ) ;
F_70 ( V_214 , V_237 ) ;
} else {
struct V_192 V_193 = {
. type = V_238 ,
. V_239 = 980 ,
} ;
F_8 ( & V_15 -> V_77 , V_170 , V_195 , & V_193 ) ;
}
if ( ! ( V_15 -> V_22 -> V_53 & V_171 ) ) {
F_70 ( V_214 , V_240 ) ;
F_70 ( V_214 , V_241 ) ;
V_214 -> V_172 = 0 ;
}
if ( V_15 -> V_22 -> V_53 & V_54 )
F_70 ( V_214 , V_242 ) ;
if ( V_15 -> V_22 -> V_92 == 0 ) {
F_70 ( V_214 , V_243 ) ;
F_70 ( V_214 , V_244 ) ;
F_70 ( V_214 , V_245 ) ;
}
if ( V_15 -> V_22 -> V_53 & V_246 )
F_50 ( V_15 -> V_184 , V_78 , V_247 ,
V_248 ,
V_249 | V_250 |
V_251 ) ;
F_51 ( V_15 ) ;
if ( V_15 -> V_22 -> V_53 & V_171 )
F_41 ( V_15 ) ;
V_211 = F_71 ( V_214 , V_252 , - 1 ) ;
if ( V_211 < 0 )
return V_211 ;
F_72 ( V_15 -> V_253 , L_8 ,
F_73 ( V_214 ) ) ;
return 0 ;
}
void F_74 ( struct V_14 * V_15 )
{
F_75 ( & V_15 -> V_198 ) ;
}
