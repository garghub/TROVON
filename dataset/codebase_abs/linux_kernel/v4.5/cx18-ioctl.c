T_1 F_1 ( int type )
{
switch ( type ) {
case V_1 :
return V_2 ;
case V_3 :
return V_4 ;
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
default:
return 0 ;
}
}
static int F_2 ( int V_9 , int line , int V_10 )
{
return ( V_10 && line >= 6 &&
( ( V_9 == 0 && line <= 23 ) || ( V_9 == 1 && line <= 22 ) ) ) ||
( ! V_10 && line >= 10 && line < 22 ) ;
}
static T_1 F_3 ( int V_9 , int line , T_1 V_11 , int V_10 )
{
T_1 V_12 = ( V_10 ? V_13 : V_14 ) ;
int V_15 ;
V_11 = V_11 & V_12 ;
if ( V_11 == 0 || ! F_2 ( V_9 , line , V_10 ) )
return 0 ;
if ( ! V_10 ) {
if ( line == 21 && ( V_11 & V_3 ) )
return V_3 ;
} else {
if ( line == 16 && V_9 == 0 && ( V_11 & V_7 ) )
return V_7 ;
if ( line == 23 && V_9 == 0 && ( V_11 & V_5 ) )
return V_5 ;
if ( line == 23 )
return 0 ;
}
for ( V_15 = 0 ; V_15 < 32 ; V_15 ++ ) {
if ( ( 1 << V_15 ) & V_11 )
return 1 << V_15 ;
}
return 0 ;
}
void F_4 ( struct V_16 * V_17 , int V_10 )
{
T_1 V_11 = V_17 -> V_18 ;
int V_19 , V_20 ;
V_17 -> V_18 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ )
V_17 -> V_21 [ V_19 ] [ V_20 ] = F_3 ( V_19 , V_20 , V_11 , V_10 ) ;
}
}
static int F_5 ( struct V_16 * V_17 , int V_10 )
{
int V_19 , V_20 ;
T_1 V_11 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
V_17 -> V_21 [ V_19 ] [ V_20 ] = F_3 ( V_19 , V_20 , V_17 -> V_21 [ V_19 ] [ V_20 ] , V_10 ) ;
V_11 |= V_17 -> V_21 [ V_19 ] [ V_20 ] ;
}
}
return V_11 != 0 ;
}
T_1 F_6 ( struct V_16 * V_17 )
{
int V_19 , V_20 ;
T_1 V_11 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ )
V_11 |= V_17 -> V_21 [ V_19 ] [ V_20 ] ;
}
return V_11 ;
}
static int F_7 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
struct V_32 * V_33 = & V_17 -> V_17 . V_34 ;
V_33 -> V_35 = V_28 -> V_36 . V_35 ;
V_33 -> V_37 = V_28 -> V_36 . V_37 ;
V_33 -> V_38 = V_39 ;
V_33 -> V_9 = V_40 ;
if ( V_26 -> type == V_41 ) {
V_33 -> V_42 = V_30 -> V_42 ;
V_33 -> V_43 = V_30 -> V_44 ;
V_33 -> V_45 = V_30 -> V_46 ;
} else {
V_33 -> V_42 = V_47 ;
V_33 -> V_43 = 128 * 1024 ;
V_33 -> V_45 = 0 ;
}
return 0 ;
}
static int F_9 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_48 * V_49 = & V_17 -> V_17 . V_50 ;
V_49 -> V_51 = 27000000 ;
V_49 -> V_52 = 248 ;
V_49 -> V_53 = V_54 - 4 ;
V_49 -> V_55 = V_56 ;
V_49 -> V_57 [ 0 ] = V_28 -> V_50 . V_57 [ 0 ] ;
V_49 -> V_57 [ 1 ] = V_28 -> V_50 . V_57 [ 1 ] ;
V_49 -> V_58 [ 0 ] = V_49 -> V_58 [ 1 ] = V_28 -> V_50 . V_58 ;
V_49 -> V_59 = 0 ;
V_49 -> V_60 [ 0 ] = 0 ;
V_49 -> V_60 [ 1 ] = 0 ;
return 0 ;
}
static int F_10 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_16 * V_49 = & V_17 -> V_17 . V_61 ;
V_49 -> V_60 [ 0 ] = 0 ;
V_49 -> V_60 [ 1 ] = 0 ;
V_49 -> V_62 = sizeof( struct V_63 ) * 36 ;
memset ( V_49 -> V_21 , 0 , sizeof( V_49 -> V_21 ) ) ;
V_49 -> V_18 = 0 ;
if ( F_11 ( V_28 -> V_64 , V_50 , V_65 , & V_17 -> V_17 . V_61 ) )
return - V_66 ;
V_49 -> V_18 = F_6 ( V_49 ) ;
return 0 ;
}
static int F_12 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
int V_67 = V_17 -> V_17 . V_34 . V_35 ;
int V_68 = V_17 -> V_17 . V_34 . V_37 ;
int V_69 = 2 ;
V_67 = F_13 ( V_67 , 720 ) ;
V_67 = F_14 ( V_67 , 2 ) ;
if ( V_26 -> type == V_41 ) {
V_68 &= ~ 0x1f ;
V_69 = 32 ;
}
V_68 = F_13 ( V_68 , V_28 -> V_70 ? 576 : 480 ) ;
V_68 = F_14 ( V_68 , V_69 ) ;
V_17 -> V_17 . V_34 . V_35 = V_67 ;
V_17 -> V_17 . V_34 . V_37 = V_68 ;
return 0 ;
}
static int F_15 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
return F_9 ( V_22 , V_23 , V_17 ) ;
}
static int F_16 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_16 * V_49 = & V_17 -> V_17 . V_61 ;
V_49 -> V_62 = sizeof( struct V_63 ) * 36 ;
V_49 -> V_60 [ 0 ] = 0 ;
V_49 -> V_60 [ 1 ] = 0 ;
if ( V_49 -> V_18 )
F_4 ( V_49 , V_28 -> V_70 ) ;
if ( F_5 ( V_49 , V_28 -> V_70 ) )
V_49 -> V_18 = F_6 ( V_49 ) ;
return 0 ;
}
static int F_17 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_71 V_72 = {
. V_73 = V_74 ,
} ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
int V_75 ;
int V_67 , V_68 ;
V_75 = F_12 ( V_22 , V_23 , V_17 ) ;
if ( V_75 )
return V_75 ;
V_67 = V_17 -> V_17 . V_34 . V_35 ;
V_68 = V_17 -> V_17 . V_34 . V_37 ;
if ( V_28 -> V_36 . V_35 == V_67 && V_28 -> V_36 . V_37 == V_68 &&
V_30 -> V_42 == V_17 -> V_17 . V_34 . V_42 )
return 0 ;
if ( F_18 ( & V_28 -> V_76 ) > 0 )
return - V_77 ;
V_30 -> V_42 = V_17 -> V_17 . V_34 . V_42 ;
if ( V_30 -> V_42 == V_78 ) {
V_30 -> V_44 = V_68 * 720 * 3 / 2 ;
V_30 -> V_46 = 720 ;
} else {
V_30 -> V_44 = V_68 * 720 * 2 ;
V_30 -> V_46 = 1440 ;
}
V_72 . V_72 . V_35 = V_28 -> V_36 . V_35 = V_67 ;
V_72 . V_72 . V_37 = V_28 -> V_36 . V_37 = V_68 ;
V_72 . V_72 . V_79 = V_80 ;
F_11 ( V_28 -> V_64 , V_81 , V_82 , NULL , & V_72 ) ;
return F_7 ( V_22 , V_23 , V_17 ) ;
}
static int F_19 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
int V_75 ;
if ( ! F_20 ( V_28 ) && F_18 ( & V_28 -> V_76 ) > 0 )
return - V_77 ;
V_75 = F_11 ( V_28 -> V_64 , V_50 , V_83 , & V_17 -> V_17 . V_50 ) ;
if ( V_75 )
return V_75 ;
V_28 -> V_50 . V_84 -> V_18 = 0 ;
V_28 -> V_50 . V_85 . type = V_86 ;
return F_9 ( V_22 , V_23 , V_17 ) ;
}
static int F_21 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
int V_75 ;
struct V_16 * V_49 = & V_17 -> V_17 . V_61 ;
F_16 ( V_22 , V_23 , V_17 ) ;
if ( F_20 ( V_28 ) && F_18 ( & V_28 -> V_76 ) > 0 )
return - V_77 ;
V_75 = F_11 ( V_28 -> V_64 , V_50 , V_87 , & V_17 -> V_17 . V_61 ) ;
if ( V_75 )
return V_75 ;
V_28 -> V_50 . V_85 . type = V_88 ;
memcpy ( V_28 -> V_50 . V_84 , V_49 , sizeof( * V_28 -> V_50 . V_84 ) ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_22 , void * V_23 ,
struct V_89 * V_90 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_90 -> V_90 & 0x3 )
return - V_66 ;
if ( V_90 -> V_90 >= V_91 + V_92 )
return - V_66 ;
V_90 -> V_93 = 4 ;
V_90 -> V_94 = F_23 ( V_28 , V_90 -> V_90 ) ;
return 0 ;
}
static int F_24 ( struct V_22 * V_22 , void * V_23 ,
const struct V_89 * V_90 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_90 -> V_90 & 0x3 )
return - V_66 ;
if ( V_90 -> V_90 >= V_91 + V_92 )
return - V_66 ;
F_25 ( V_28 , V_90 -> V_94 , V_90 -> V_90 ) ;
return 0 ;
}
static int F_26 ( struct V_22 * V_22 , void * V_23 ,
struct V_95 * V_96 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_29 * V_30 = F_27 ( V_22 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
F_28 ( V_96 -> V_97 , V_98 , sizeof( V_96 -> V_97 ) ) ;
F_28 ( V_96 -> V_99 , V_28 -> V_100 , sizeof( V_96 -> V_99 ) ) ;
snprintf ( V_96 -> V_101 , sizeof( V_96 -> V_101 ) ,
L_1 , F_29 ( V_28 -> V_102 ) ) ;
V_96 -> V_103 = V_28 -> V_104 ;
V_96 -> V_105 = V_30 -> V_106 ;
V_96 -> V_103 |= V_107 ;
return 0 ;
}
static int F_30 ( struct V_22 * V_22 , void * V_23 , struct V_108 * V_109 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_31 ( V_28 , V_109 -> V_110 , V_109 ) ;
}
static int F_32 ( struct V_22 * V_22 , void * V_23 , struct V_108 * V_109 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
V_109 -> V_110 = V_28 -> V_111 ;
return F_31 ( V_28 , V_109 -> V_110 , V_109 ) ;
}
static int F_33 ( struct V_22 * V_22 , void * V_23 , const struct V_108 * V_112 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_112 -> V_110 >= V_28 -> V_113 )
return - V_66 ;
V_28 -> V_111 = V_112 -> V_110 ;
F_34 ( V_28 ) ;
return 0 ;
}
static int F_35 ( struct V_22 * V_22 , void * V_23 , struct V_114 * V_109 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_36 ( V_28 , V_109 -> V_110 , V_109 ) ;
}
static int F_37 ( struct V_22 * V_22 , void * V_23 ,
struct V_115 * V_116 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_116 -> type != V_117 )
return - V_66 ;
V_116 -> V_118 . V_119 = V_28 -> V_70 ? 54 : 11 ;
V_116 -> V_118 . V_120 = V_28 -> V_70 ? 59 : 10 ;
return 0 ;
}
static int F_38 ( struct V_22 * V_22 , void * V_23 ,
struct V_121 * V_122 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_122 -> type != V_117 )
return - V_66 ;
switch ( V_122 -> V_123 ) {
case V_124 :
case V_125 :
V_122 -> V_126 . V_127 = V_122 -> V_126 . V_128 = 0 ;
V_122 -> V_126 . V_35 = 720 ;
V_122 -> V_126 . V_37 = V_28 -> V_70 ? 576 : 480 ;
break;
default:
return - V_66 ;
}
return 0 ;
}
static int F_39 ( struct V_22 * V_22 , void * V_23 ,
struct V_129 * V_17 )
{
static const struct V_129 V_130 [] = {
{ 0 , V_117 , 0 ,
L_2 , V_78 , { 0 , 0 , 0 , 0 }
} ,
{ 1 , V_117 , V_131 ,
L_3 , V_47 , { 0 , 0 , 0 , 0 }
} ,
{ 2 , V_117 , 0 ,
L_4 , V_132 , { 0 , 0 , 0 , 0 }
} ,
} ;
if ( V_17 -> V_110 > F_40 ( V_130 ) - 1 )
return - V_66 ;
* V_17 = V_130 [ V_17 -> V_110 ] ;
return 0 ;
}
static int F_41 ( struct V_22 * V_22 , void * V_23 , unsigned int * V_15 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_15 = V_28 -> V_133 ;
return 0 ;
}
int F_42 ( struct V_22 * V_22 , void * V_23 , unsigned int V_134 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
T_2 V_135 = V_136 ;
const struct V_137 * V_138 =
V_28 -> V_99 -> V_139 + V_134 ;
if ( V_134 >= V_28 -> V_140 )
return - V_66 ;
if ( V_134 == V_28 -> V_133 ) {
F_43 ( L_5 ) ;
return 0 ;
}
F_43 ( L_6 ,
V_28 -> V_133 , V_134 ) ;
V_28 -> V_133 = V_134 ;
V_28 -> V_111 = V_28 -> V_99 -> V_139 [ V_134 ] . V_141 ;
if ( V_138 -> V_142 == V_143 )
V_135 = V_28 -> V_144 ;
V_28 -> V_31 [ V_145 ] . V_146 . V_147 = V_135 ;
V_28 -> V_31 [ V_41 ] . V_146 . V_147 = V_135 ;
V_28 -> V_31 [ V_148 ] . V_146 . V_147 = V_135 ;
F_44 ( V_28 ) ;
F_45 ( V_28 ) ;
F_34 ( V_28 ) ;
F_46 ( V_28 ) ;
return 0 ;
}
static int F_47 ( struct V_22 * V_22 , void * V_23 ,
struct V_149 * V_150 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_150 -> V_151 != 0 )
return - V_66 ;
F_48 ( V_28 , V_151 , V_152 , V_150 ) ;
return 0 ;
}
int F_49 ( struct V_22 * V_22 , void * V_23 , const struct V_149 * V_150 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_150 -> V_151 != 0 )
return - V_66 ;
F_44 ( V_28 ) ;
F_43 ( L_7 , V_150 -> V_153 ) ;
F_48 ( V_28 , V_151 , V_154 , V_150 ) ;
F_46 ( V_28 ) ;
return 0 ;
}
static int F_50 ( struct V_22 * V_22 , void * V_23 , T_2 * V_135 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_135 = V_28 -> V_135 ;
return 0 ;
}
int F_51 ( struct V_22 * V_22 , void * V_23 , T_2 V_135 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( ( V_135 & V_136 ) == 0 )
return - V_66 ;
if ( V_135 == V_28 -> V_135 )
return 0 ;
if ( F_52 ( V_155 , & V_28 -> V_156 ) ||
F_18 ( & V_28 -> V_76 ) > 0 ) {
return - V_77 ;
}
V_28 -> V_135 = V_135 ;
V_28 -> V_157 = ( V_135 & V_158 ) ? 1 : 0 ;
V_28 -> V_70 = ! V_28 -> V_157 ;
F_53 ( & V_28 -> V_36 , V_28 -> V_70 ) ;
V_28 -> V_36 . V_35 = 720 ;
V_28 -> V_36 . V_37 = V_28 -> V_70 ? 576 : 480 ;
V_28 -> V_50 . V_58 = V_28 -> V_70 ? 18 : 12 ;
V_28 -> V_50 . V_57 [ 0 ] = V_28 -> V_70 ? 6 : 10 ;
V_28 -> V_50 . V_57 [ 1 ] = V_28 -> V_70 ? 318 : 273 ;
F_43 ( L_8 ,
( unsigned long long ) V_28 -> V_135 ) ;
F_48 ( V_28 , V_159 , V_160 , V_28 -> V_135 ) ;
return 0 ;
}
static int F_54 ( struct V_22 * V_22 , void * V_23 , const struct V_161 * V_162 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_162 -> V_110 != 0 )
return - V_66 ;
F_48 ( V_28 , V_151 , V_163 , V_162 ) ;
return 0 ;
}
static int F_55 ( struct V_22 * V_22 , void * V_23 , struct V_161 * V_162 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_162 -> V_110 != 0 )
return - V_66 ;
F_48 ( V_28 , V_151 , V_164 , V_162 ) ;
if ( V_162 -> type == V_165 )
F_28 ( V_162 -> V_166 , L_9 , sizeof( V_162 -> V_166 ) ) ;
else
F_28 ( V_162 -> V_166 , L_10 , sizeof( V_162 -> V_166 ) ) ;
return 0 ;
}
static int F_56 ( struct V_22 * V_22 , void * V_23 ,
struct V_167 * V_168 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
int V_11 = V_28 -> V_70 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_168 -> type != V_88 )
return - V_66 ;
V_168 -> V_18 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_28 -> V_70 ) ) {
V_168 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
V_168 -> V_18 |= V_11 ;
} else
V_168 -> V_21 [ V_19 ] [ V_20 ] = 0 ;
}
}
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_168 -> V_60 [ V_19 ] = 0 ;
return 0 ;
}
static int F_57 ( struct V_169 * V_170 ,
struct V_171 * V_172 )
{
int V_173 , V_174 ;
struct V_175 * V_176 ;
struct V_177 * V_178 ;
const int V_179 [ 8 ] = {
- 1 , V_180 , V_181 ,
- 1 , V_182 , - 1 , - 1 , - 1
} ;
V_174 = V_170 -> V_183 - V_170 -> V_184 ;
V_173 = 0 ;
V_176 = & V_172 -> V_185 [ V_172 -> V_186 ] ;
V_178 = (struct V_177 * ) & V_170 -> V_170 [ V_170 -> V_184 ] ;
while ( V_174 >= sizeof( struct V_177 ) &&
V_172 -> V_186 < V_187 ) {
V_176 -> V_52 = ( ( ( V_188 ) F_58 ( V_178 -> V_189 ) ) << 32 )
| F_58 ( V_178 -> V_190 ) ;
V_176 -> V_191 = ( ( ( V_188 ) ( F_58 ( V_178 -> V_192 ) & 1 ) ) << 32 )
| F_58 ( V_178 -> V_193 ) ;
V_176 -> V_194 = F_58 ( V_178 -> V_194 ) ;
V_176 -> V_59 = V_179 [ F_58 ( V_178 -> V_59 ) & 0x7 ] ;
V_176 -> V_60 [ 0 ] = 0 ;
V_176 -> V_60 [ 1 ] = 0 ;
V_172 -> V_186 ++ ;
V_176 = & V_172 -> V_185 [ V_172 -> V_186 ] ;
V_178 ++ ;
V_174 -= sizeof( struct V_177 ) ;
V_173 += sizeof( struct V_177 ) ;
}
if ( V_174 > 0 && V_174 < sizeof( struct V_177 ) )
V_173 += V_174 ;
V_170 -> V_184 += V_173 ;
return V_173 ;
}
static int F_59 ( struct V_29 * V_30 , struct V_195 * V_196 ,
struct V_171 * V_172 )
{
if ( V_30 -> type != V_197 )
return - V_66 ;
if ( V_196 -> V_198 == NULL )
V_196 -> V_198 = F_60 ( & V_196 -> V_199 ,
struct V_169 , V_200 ) ;
if ( F_61 ( V_196 -> V_198 , & V_196 -> V_199 , V_200 ) ) {
V_196 -> V_184 = V_196 -> V_183 ;
return 0 ;
}
F_62 (mdl->curr_buf, &mdl->buf_list, list) {
if ( V_196 -> V_198 -> V_184 >= V_196 -> V_198 -> V_183 )
continue;
V_196 -> V_184 += F_57 ( V_196 -> V_198 , V_172 ) ;
if ( V_172 -> V_186 >= V_187 ||
V_196 -> V_198 -> V_184 < V_196 -> V_198 -> V_183 ||
V_196 -> V_184 >= V_196 -> V_183 )
break;
}
return 0 ;
}
static int F_63 ( struct V_22 * V_22 , void * V_23 ,
struct V_171 * V_172 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_197 ] ;
T_3 V_201 ;
struct V_195 * V_196 ;
if ( ! F_64 ( V_30 ) )
return - V_66 ;
V_201 = V_30 -> V_202 -
V_30 -> V_203 * V_204 ;
if ( V_201 <= 0 )
V_201 = 1 ;
V_201 = V_201 * V_30 -> V_205 / sizeof( struct V_177 ) ;
V_172 -> V_186 = 0 ;
V_172 -> V_206 = V_201 ;
memset ( V_172 -> V_60 , 0 , sizeof( V_172 -> V_60 ) ) ;
do {
V_196 = F_65 ( V_30 , & V_30 -> V_207 ) ;
if ( V_196 == NULL )
break;
F_59 ( V_30 , V_196 , V_172 ) ;
if ( V_196 -> V_184 < V_196 -> V_183 ) {
F_66 ( V_30 , V_196 , & V_30 -> V_207 ) ;
break;
}
F_67 ( V_30 , V_196 , & V_30 -> V_208 ) ;
} while ( V_172 -> V_186 < V_187 );
F_68 ( V_30 ) ;
return 0 ;
}
static struct V_209 * F_69 ( struct V_25 * V_26 )
{
struct V_209 * V_210 = NULL ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
switch ( V_30 -> V_211 ) {
case V_117 :
V_210 = & V_30 -> V_212 ;
break;
case V_86 :
break;
default:
break;
}
return V_210 ;
}
static int F_70 ( struct V_22 * V_22 , void * V_213 ,
enum V_214 type )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_211 != V_117 ) &&
( V_30 -> V_211 != V_86 ) )
return - V_66 ;
if ( V_26 -> type != V_41 )
return - V_66 ;
F_71 ( & V_30 -> V_216 , F_72 ( 2000 ) + V_217 ) ;
return F_73 ( F_69 ( V_26 ) ) ;
}
static int F_74 ( struct V_22 * V_22 , void * V_213 ,
enum V_214 type )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_211 != V_117 ) &&
( V_30 -> V_211 != V_86 ) )
return - V_66 ;
if ( V_26 -> type != V_41 )
return - V_66 ;
return F_75 ( F_69 ( V_26 ) ) ;
}
static int F_76 ( struct V_22 * V_22 , void * V_213 ,
struct V_218 * V_219 )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_211 != V_117 ) &&
( V_30 -> V_211 != V_86 ) )
return - V_66 ;
return F_77 ( F_69 ( V_26 ) , V_219 ) ;
}
static int F_78 ( struct V_22 * V_22 , void * V_213 ,
struct V_220 * V_221 )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_211 != V_117 ) &&
( V_30 -> V_211 != V_86 ) )
return - V_66 ;
return F_79 ( F_69 ( V_26 ) , V_221 ) ;
}
static int F_80 ( struct V_22 * V_22 , void * V_213 , struct V_220 * V_221 )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_211 != V_117 ) &&
( V_30 -> V_211 != V_86 ) )
return - V_66 ;
return F_81 ( F_69 ( V_26 ) , V_221 ) ;
}
static int F_82 ( struct V_22 * V_22 , void * V_213 , struct V_220 * V_221 )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_211 != V_117 ) &&
( V_30 -> V_211 != V_86 ) )
return - V_66 ;
return F_83 ( F_69 ( V_26 ) , V_221 , V_22 -> V_222 & V_223 ) ;
}
static int F_84 ( struct V_22 * V_22 , void * V_23 ,
struct V_224 * V_225 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
T_4 V_68 ;
switch ( V_225 -> V_226 ) {
case V_227 :
F_85 ( L_11 ) ;
V_225 -> V_59 = 0 ;
return F_86 ( V_26 ) ;
case V_228 :
F_85 ( L_12 ) ;
V_225 -> V_59 &= V_229 ;
F_87 ( V_26 ,
V_225 -> V_59 & V_229 ) ;
break;
case V_230 :
F_85 ( L_13 ) ;
V_225 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_76 ) )
return - V_231 ;
if ( F_88 ( V_232 , & V_28 -> V_156 ) )
return 0 ;
V_68 = F_89 ( V_28 ) ;
if ( V_68 == V_233 ) {
F_90 ( L_14
L_13 ) ;
return - V_234 ;
}
F_44 ( V_28 ) ;
F_91 ( V_28 , V_235 , 1 , V_68 ) ;
break;
case V_236 :
F_85 ( L_15 ) ;
V_225 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_76 ) )
return - V_231 ;
if ( ! F_92 ( V_232 , & V_28 -> V_156 ) )
return 0 ;
V_68 = F_89 ( V_28 ) ;
if ( V_68 == V_233 ) {
F_90 ( L_14
L_15 ) ;
return - V_234 ;
}
F_91 ( V_28 , V_237 , 1 , V_68 ) ;
F_46 ( V_28 ) ;
break;
default:
F_85 ( L_16 , V_225 -> V_226 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_93 ( struct V_22 * V_22 , void * V_23 ,
struct V_224 * V_225 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_225 -> V_226 ) {
case V_227 :
F_85 ( L_11 ) ;
V_225 -> V_59 = 0 ;
break;
case V_228 :
F_85 ( L_12 ) ;
V_225 -> V_59 &= V_229 ;
break;
case V_230 :
F_85 ( L_13 ) ;
V_225 -> V_59 = 0 ;
break;
case V_236 :
F_85 ( L_15 ) ;
V_225 -> V_59 = 0 ;
break;
default:
F_85 ( L_16 , V_225 -> V_226 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_94 ( struct V_22 * V_22 , void * V_23 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_114 V_238 ;
struct V_108 V_239 ;
int V_15 ;
F_95 ( L_17 , V_240 , V_28 -> V_100 ) ;
if ( V_28 -> V_241 & V_242 ) {
struct V_243 V_244 ;
F_96 ( V_28 , & V_244 ) ;
}
F_48 ( V_28 , V_245 , V_246 ) ;
F_36 ( V_28 , V_28 -> V_133 , & V_238 ) ;
F_31 ( V_28 , V_28 -> V_111 , & V_239 ) ;
F_95 ( L_18 , V_238 . V_166 ) ;
F_95 ( L_19 , V_239 . V_166 ) ;
F_97 ( & V_28 -> V_247 ) ;
F_95 ( L_20 ,
V_28 -> V_248 , V_28 -> V_249 ) ;
F_98 ( & V_28 -> V_247 ) ;
F_95 ( L_21 ,
F_52 ( V_155 , & V_28 -> V_156 ) ? L_22 : L_23 ) ;
F_99 ( & V_28 -> V_36 . V_250 , V_28 -> V_251 . V_166 ) ;
F_95 ( L_24 , V_28 -> V_156 ) ;
for ( V_15 = 0 ; V_15 < V_252 ; V_15 ++ ) {
struct V_29 * V_30 = & V_28 -> V_31 [ V_15 ] ;
if ( V_30 -> V_146 . V_251 == NULL || V_30 -> V_202 == 0 )
continue;
F_95 ( L_25 ,
V_30 -> V_166 , V_30 -> V_253 ,
F_18 ( & V_30 -> V_207 . V_254 ) * V_30 -> V_203 * 100
/ V_30 -> V_202 ,
( V_30 -> V_202 * V_30 -> V_205 ) / 1024 , V_30 -> V_202 ) ;
}
F_95 ( L_26 ,
( long long ) V_28 -> V_255 ,
( long long ) V_28 -> V_256 ) ;
return 0 ;
}
static long F_100 ( struct V_22 * V_22 , void * V_23 , bool V_257 ,
unsigned int V_226 , void * V_258 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_226 ) {
case V_259 : {
T_4 V_94 = * ( T_4 * ) V_258 ;
if ( ( V_94 == 0 ) || ( V_94 & 0x01 ) )
F_101 ( V_28 , V_260 , V_245 , V_261 ,
( T_4 ) V_262 ) ;
break;
}
default:
return - V_263 ;
}
return 0 ;
}
void F_102 ( struct V_264 * V_265 )
{
V_265 -> V_266 = & V_267 ;
}
