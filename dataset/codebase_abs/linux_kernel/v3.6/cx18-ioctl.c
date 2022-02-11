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
V_33 -> V_41 = 0 ;
if ( V_26 -> type == V_42 ) {
V_33 -> V_43 = V_30 -> V_43 ;
V_33 -> V_44 = V_30 -> V_45 ;
V_33 -> V_46 = 720 ;
} else {
V_33 -> V_43 = V_47 ;
V_33 -> V_44 = 128 * 1024 ;
V_33 -> V_46 = 0 ;
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
V_49 -> V_60 [ 0 ] = 0 ;
V_49 -> V_60 [ 1 ] = 0 ;
V_49 -> V_62 = sizeof( struct V_63 ) * 36 ;
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
if ( V_26 -> type == V_42 ) {
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
struct V_71 V_72 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
int V_73 ;
int V_67 , V_68 ;
V_73 = F_12 ( V_22 , V_23 , V_17 ) ;
if ( V_73 )
return V_73 ;
V_67 = V_17 -> V_17 . V_34 . V_35 ;
V_68 = V_17 -> V_17 . V_34 . V_37 ;
if ( V_28 -> V_36 . V_35 == V_67 && V_28 -> V_36 . V_37 == V_68 &&
V_30 -> V_43 == V_17 -> V_17 . V_34 . V_43 )
return 0 ;
if ( F_18 ( & V_28 -> V_74 ) > 0 )
return - V_75 ;
V_30 -> V_43 = V_17 -> V_17 . V_34 . V_43 ;
if ( V_30 -> V_43 == V_76 )
V_30 -> V_45 = V_68 * 720 * 3 / 2 ;
else
V_30 -> V_45 = V_68 * 720 * 2 ;
V_72 . V_35 = V_28 -> V_36 . V_35 = V_67 ;
V_72 . V_37 = V_28 -> V_36 . V_37 = V_68 ;
V_72 . V_77 = V_78 ;
F_11 ( V_28 -> V_64 , V_79 , V_80 , & V_72 ) ;
return F_7 ( V_22 , V_23 , V_17 ) ;
}
static int F_19 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
int V_73 ;
if ( ! F_20 ( V_28 ) && F_18 ( & V_28 -> V_74 ) > 0 )
return - V_75 ;
V_73 = F_11 ( V_28 -> V_64 , V_50 , V_81 , & V_17 -> V_17 . V_50 ) ;
if ( V_73 )
return V_73 ;
V_28 -> V_50 . V_82 -> V_18 = 0 ;
V_28 -> V_50 . V_83 . type = V_84 ;
return F_9 ( V_22 , V_23 , V_17 ) ;
}
static int F_21 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
int V_73 ;
struct V_16 * V_49 = & V_17 -> V_17 . V_61 ;
F_16 ( V_22 , V_23 , V_17 ) ;
if ( F_20 ( V_28 ) && F_18 ( & V_28 -> V_74 ) > 0 )
return - V_75 ;
V_73 = F_11 ( V_28 -> V_64 , V_50 , V_85 , & V_17 -> V_17 . V_61 ) ;
if ( V_73 )
return V_73 ;
V_28 -> V_50 . V_83 . type = V_86 ;
memcpy ( V_28 -> V_50 . V_82 , V_49 , sizeof( * V_28 -> V_50 . V_82 ) ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_22 , void * V_23 ,
struct V_87 * V_88 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
int V_89 = 0 ;
V_88 -> V_90 = V_91 ;
V_88 -> V_92 = 0 ;
switch ( V_88 -> V_93 . type ) {
case V_94 :
switch ( V_88 -> V_93 . V_95 ) {
case 0 :
V_88 -> V_90 = V_96 ;
V_88 -> V_92 = F_23 ( V_28 , 0xC72028 ) ;
break;
case 1 :
F_24 ( V_28 , V_97 ,
V_98 , V_99 , V_88 ) ;
break;
default:
V_89 = - V_66 ;
break;
}
break;
case V_100 :
F_25 ( V_28 , V_98 , V_99 , V_88 ) ;
break;
case V_101 :
F_25 ( V_28 , V_98 , V_99 , V_88 ) ;
break;
default:
V_89 = - V_66 ;
break;
}
return V_89 ;
}
static int F_26 ( struct V_27 * V_28 , unsigned int V_102 , void * V_103 )
{
struct V_104 * V_105 = V_103 ;
if ( ! F_27 ( V_106 ) )
return - V_107 ;
if ( V_105 -> V_108 >= V_109 + V_110 )
return - V_66 ;
V_105 -> V_111 = 4 ;
if ( V_102 == V_112 )
F_28 ( V_28 , V_105 -> V_113 , V_105 -> V_108 ) ;
else
V_105 -> V_113 = F_29 ( V_28 , V_105 -> V_108 ) ;
return 0 ;
}
static int F_30 ( struct V_22 * V_22 , void * V_23 ,
struct V_104 * V_108 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( F_31 ( & V_108 -> V_93 ) )
return F_26 ( V_28 , V_114 , V_108 ) ;
F_25 ( V_28 , V_98 , V_115 , V_108 ) ;
return 0 ;
}
static int F_32 ( struct V_22 * V_22 , void * V_23 ,
struct V_104 * V_108 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( F_31 ( & V_108 -> V_93 ) )
return F_26 ( V_28 , V_112 , V_108 ) ;
F_25 ( V_28 , V_98 , V_116 , V_108 ) ;
return 0 ;
}
static int F_33 ( struct V_22 * V_22 , void * V_23 ,
struct V_117 * V_118 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
F_34 ( V_118 -> V_119 , V_120 , sizeof( V_118 -> V_119 ) ) ;
F_34 ( V_118 -> V_121 , V_28 -> V_122 , sizeof( V_118 -> V_121 ) ) ;
snprintf ( V_118 -> V_123 , sizeof( V_118 -> V_123 ) ,
L_1 , F_35 ( V_28 -> V_124 ) ) ;
V_118 -> V_125 = V_28 -> V_126 ;
if ( V_26 -> type == V_42 )
V_118 -> V_125 |= V_127 ;
return 0 ;
}
static int F_36 ( struct V_22 * V_22 , void * V_23 , struct V_128 * V_129 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_37 ( V_28 , V_129 -> V_130 , V_129 ) ;
}
static int F_38 ( struct V_22 * V_22 , void * V_23 , struct V_128 * V_129 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
V_129 -> V_130 = V_28 -> V_131 ;
return F_37 ( V_28 , V_129 -> V_130 , V_129 ) ;
}
static int F_39 ( struct V_22 * V_22 , void * V_23 , struct V_128 * V_132 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_132 -> V_130 >= V_28 -> V_133 )
return - V_66 ;
V_28 -> V_131 = V_132 -> V_130 ;
F_40 ( V_28 ) ;
return 0 ;
}
static int F_41 ( struct V_22 * V_22 , void * V_23 , struct V_134 * V_129 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_42 ( V_28 , V_129 -> V_130 , V_129 ) ;
}
static int F_43 ( struct V_22 * V_22 , void * V_23 ,
struct V_135 * V_136 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_136 -> type != V_137 )
return - V_66 ;
V_136 -> V_138 . V_139 = V_136 -> V_138 . V_140 = 0 ;
V_136 -> V_138 . V_35 = 720 ;
V_136 -> V_138 . V_37 = V_28 -> V_70 ? 576 : 480 ;
V_136 -> V_141 . V_142 = V_28 -> V_70 ? 59 : 10 ;
V_136 -> V_141 . V_143 = V_28 -> V_70 ? 54 : 11 ;
V_136 -> V_144 = V_136 -> V_138 ;
return 0 ;
}
static int F_44 ( struct V_22 * V_22 , void * V_23 , struct V_145 * V_146 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_146 -> type != V_137 )
return - V_66 ;
F_45 ( L_2 ) ;
return - V_66 ;
}
static int F_46 ( struct V_22 * V_22 , void * V_23 , struct V_145 * V_146 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_146 -> type != V_137 )
return - V_66 ;
F_45 ( L_3 ) ;
return - V_66 ;
}
static int F_47 ( struct V_22 * V_22 , void * V_23 ,
struct V_147 * V_17 )
{
static const struct V_147 V_148 [] = {
{ 0 , V_137 , 0 ,
L_4 , V_76 , { 0 , 0 , 0 , 0 }
} ,
{ 1 , V_137 , V_149 ,
L_5 , V_47 , { 0 , 0 , 0 , 0 }
} ,
{ 2 , V_137 , 0 ,
L_6 , V_150 , { 0 , 0 , 0 , 0 }
} ,
} ;
if ( V_17 -> V_130 > F_48 ( V_148 ) - 1 )
return - V_66 ;
* V_17 = V_148 [ V_17 -> V_130 ] ;
return 0 ;
}
static int F_49 ( struct V_22 * V_22 , void * V_23 , unsigned int * V_15 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_15 = V_28 -> V_151 ;
return 0 ;
}
int F_50 ( struct V_22 * V_22 , void * V_23 , unsigned int V_152 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_152 >= V_28 -> V_153 )
return - V_66 ;
if ( V_152 == V_28 -> V_151 ) {
F_51 ( L_7 ) ;
return 0 ;
}
F_51 ( L_8 ,
V_28 -> V_151 , V_152 ) ;
V_28 -> V_151 = V_152 ;
V_28 -> V_131 = V_28 -> V_121 -> V_154 [ V_152 ] . V_155 ;
F_52 ( V_28 ) ;
F_53 ( V_28 ) ;
F_40 ( V_28 ) ;
F_54 ( V_28 ) ;
return 0 ;
}
static int F_55 ( struct V_22 * V_22 , void * V_23 ,
struct V_156 * V_157 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_157 -> V_158 != 0 )
return - V_66 ;
F_25 ( V_28 , V_158 , V_159 , V_157 ) ;
return 0 ;
}
int F_56 ( struct V_22 * V_22 , void * V_23 , struct V_156 * V_157 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_157 -> V_158 != 0 )
return - V_66 ;
F_52 ( V_28 ) ;
F_51 ( L_9 , V_157 -> V_160 ) ;
F_25 ( V_28 , V_158 , V_161 , V_157 ) ;
F_54 ( V_28 ) ;
return 0 ;
}
static int F_57 ( struct V_22 * V_22 , void * V_23 , T_2 * V_162 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_162 = V_28 -> V_162 ;
return 0 ;
}
int F_58 ( struct V_22 * V_22 , void * V_23 , T_2 * V_162 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( ( * V_162 & V_163 ) == 0 )
return - V_66 ;
if ( * V_162 == V_28 -> V_162 )
return 0 ;
if ( F_59 ( V_164 , & V_28 -> V_165 ) ||
F_18 ( & V_28 -> V_74 ) > 0 ) {
return - V_75 ;
}
V_28 -> V_162 = * V_162 ;
V_28 -> V_166 = ( * V_162 & V_167 ) ? 1 : 0 ;
V_28 -> V_70 = ! V_28 -> V_166 ;
F_60 ( & V_28 -> V_36 , V_28 -> V_70 ) ;
V_28 -> V_36 . V_35 = 720 ;
V_28 -> V_36 . V_37 = V_28 -> V_70 ? 576 : 480 ;
V_28 -> V_50 . V_58 = V_28 -> V_70 ? 18 : 12 ;
V_28 -> V_50 . V_57 [ 0 ] = V_28 -> V_70 ? 6 : 10 ;
V_28 -> V_50 . V_57 [ 1 ] = V_28 -> V_70 ? 318 : 273 ;
F_51 ( L_10 ,
( unsigned long long ) V_28 -> V_162 ) ;
F_25 ( V_28 , V_98 , V_168 , V_28 -> V_162 ) ;
return 0 ;
}
static int F_61 ( struct V_22 * V_22 , void * V_23 , struct V_169 * V_170 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_170 -> V_130 != 0 )
return - V_66 ;
F_25 ( V_28 , V_158 , V_171 , V_170 ) ;
return 0 ;
}
static int F_62 ( struct V_22 * V_22 , void * V_23 , struct V_169 * V_170 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_170 -> V_130 != 0 )
return - V_66 ;
F_25 ( V_28 , V_158 , V_172 , V_170 ) ;
if ( V_170 -> type == V_173 )
F_34 ( V_170 -> V_174 , L_11 , sizeof( V_170 -> V_174 ) ) ;
else
F_34 ( V_170 -> V_174 , L_12 , sizeof( V_170 -> V_174 ) ) ;
return 0 ;
}
static int F_63 ( struct V_22 * V_22 , void * V_23 ,
struct V_175 * V_176 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
int V_11 = V_28 -> V_70 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_176 -> type != V_86 )
return - V_66 ;
V_176 -> V_18 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_28 -> V_70 ) ) {
V_176 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
V_176 -> V_18 |= V_11 ;
} else
V_176 -> V_21 [ V_19 ] [ V_20 ] = 0 ;
}
}
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_176 -> V_60 [ V_19 ] = 0 ;
return 0 ;
}
static int F_64 ( struct V_177 * V_178 ,
struct V_179 * V_180 )
{
int V_181 , V_182 ;
struct V_183 * V_184 ;
struct V_185 * V_186 ;
const int V_187 [ 8 ] = {
- 1 , V_188 , V_189 ,
- 1 , V_190 , - 1 , - 1 , - 1
} ;
V_182 = V_178 -> V_191 - V_178 -> V_192 ;
V_181 = 0 ;
V_184 = & V_180 -> V_193 [ V_180 -> V_194 ] ;
V_186 = (struct V_185 * ) & V_178 -> V_178 [ V_178 -> V_192 ] ;
while ( V_182 >= sizeof( struct V_185 ) &&
V_180 -> V_194 < V_195 ) {
V_184 -> V_52 = ( ( ( V_196 ) F_65 ( V_186 -> V_197 ) ) << 32 )
| F_65 ( V_186 -> V_198 ) ;
V_184 -> V_199 = ( ( ( V_196 ) ( F_65 ( V_186 -> V_200 ) & 1 ) ) << 32 )
| F_65 ( V_186 -> V_201 ) ;
V_184 -> V_202 = F_65 ( V_186 -> V_202 ) ;
V_184 -> V_59 = V_187 [ F_65 ( V_186 -> V_59 ) & 0x7 ] ;
V_184 -> V_60 [ 0 ] = 0 ;
V_184 -> V_60 [ 1 ] = 0 ;
V_180 -> V_194 ++ ;
V_184 = & V_180 -> V_193 [ V_180 -> V_194 ] ;
V_186 ++ ;
V_182 -= sizeof( struct V_185 ) ;
V_181 += sizeof( struct V_185 ) ;
}
if ( V_182 > 0 && V_182 < sizeof( struct V_185 ) )
V_181 += V_182 ;
V_178 -> V_192 += V_181 ;
return V_181 ;
}
static int F_66 ( struct V_29 * V_30 , struct V_203 * V_204 ,
struct V_179 * V_180 )
{
if ( V_30 -> type != V_205 )
return - V_66 ;
if ( V_204 -> V_206 == NULL )
V_204 -> V_206 = F_67 ( & V_204 -> V_207 ,
struct V_177 , V_208 ) ;
if ( F_68 ( V_204 -> V_206 , & V_204 -> V_207 , V_208 ) ) {
V_204 -> V_192 = V_204 -> V_191 ;
return 0 ;
}
F_69 (mdl->curr_buf, &mdl->buf_list, list) {
if ( V_204 -> V_206 -> V_192 >= V_204 -> V_206 -> V_191 )
continue;
V_204 -> V_192 += F_64 ( V_204 -> V_206 , V_180 ) ;
if ( V_180 -> V_194 >= V_195 ||
V_204 -> V_206 -> V_192 < V_204 -> V_206 -> V_191 ||
V_204 -> V_192 >= V_204 -> V_191 )
break;
}
return 0 ;
}
static int F_70 ( struct V_22 * V_22 , void * V_23 ,
struct V_179 * V_180 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_205 ] ;
T_3 V_209 ;
struct V_203 * V_204 ;
if ( ! F_71 ( V_30 ) )
return - V_66 ;
V_209 = V_30 -> V_210 -
V_30 -> V_211 * V_212 ;
if ( V_209 <= 0 )
V_209 = 1 ;
V_209 = V_209 * V_30 -> V_213 / sizeof( struct V_185 ) ;
V_180 -> V_194 = 0 ;
V_180 -> V_214 = V_209 ;
memset ( V_180 -> V_60 , 0 , sizeof( V_180 -> V_60 ) ) ;
do {
V_204 = F_72 ( V_30 , & V_30 -> V_215 ) ;
if ( V_204 == NULL )
break;
F_66 ( V_30 , V_204 , V_180 ) ;
if ( V_204 -> V_192 < V_204 -> V_191 ) {
F_73 ( V_30 , V_204 , & V_30 -> V_215 ) ;
break;
}
F_74 ( V_30 , V_204 , & V_30 -> V_216 ) ;
} while ( V_180 -> V_194 < V_195 );
F_75 ( V_30 ) ;
return 0 ;
}
static struct V_217 * F_76 ( struct V_25 * V_26 )
{
struct V_217 * V_218 = NULL ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
switch ( V_30 -> V_219 ) {
case V_137 :
V_218 = & V_30 -> V_220 ;
break;
case V_84 :
break;
default:
break;
}
return V_218 ;
}
static int F_77 ( struct V_22 * V_22 , void * V_41 ,
enum V_221 type )
{
struct V_25 * V_26 = V_22 -> V_222 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_219 != V_137 ) &&
( V_30 -> V_219 != V_84 ) )
return - V_66 ;
if ( V_26 -> type != V_42 )
return - V_66 ;
F_78 ( & V_30 -> V_223 , F_79 ( 2000 ) + V_224 ) ;
return F_80 ( F_76 ( V_26 ) ) ;
}
static int F_81 ( struct V_22 * V_22 , void * V_41 ,
enum V_221 type )
{
struct V_25 * V_26 = V_22 -> V_222 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_219 != V_137 ) &&
( V_30 -> V_219 != V_84 ) )
return - V_66 ;
if ( V_26 -> type != V_42 )
return - V_66 ;
return F_82 ( F_76 ( V_26 ) ) ;
}
static int F_83 ( struct V_22 * V_22 , void * V_41 ,
struct V_225 * V_226 )
{
struct V_25 * V_26 = V_22 -> V_222 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_219 != V_137 ) &&
( V_30 -> V_219 != V_84 ) )
return - V_66 ;
return F_84 ( F_76 ( V_26 ) , V_226 ) ;
}
static int F_85 ( struct V_22 * V_22 , void * V_41 ,
struct V_227 * V_228 )
{
struct V_25 * V_26 = V_22 -> V_222 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_219 != V_137 ) &&
( V_30 -> V_219 != V_84 ) )
return - V_66 ;
return F_86 ( F_76 ( V_26 ) , V_228 ) ;
}
static int F_87 ( struct V_22 * V_22 , void * V_41 , struct V_227 * V_228 )
{
struct V_25 * V_26 = V_22 -> V_222 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_219 != V_137 ) &&
( V_30 -> V_219 != V_84 ) )
return - V_66 ;
return F_88 ( F_76 ( V_26 ) , V_228 ) ;
}
static int F_89 ( struct V_22 * V_22 , void * V_41 , struct V_227 * V_228 )
{
struct V_25 * V_26 = V_22 -> V_222 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_219 != V_137 ) &&
( V_30 -> V_219 != V_84 ) )
return - V_66 ;
return F_90 ( F_76 ( V_26 ) , V_228 , V_22 -> V_229 & V_230 ) ;
}
static int F_91 ( struct V_22 * V_22 , void * V_23 ,
struct V_231 * V_232 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
T_4 V_68 ;
switch ( V_232 -> V_102 ) {
case V_233 :
F_92 ( L_13 ) ;
V_232 -> V_59 = 0 ;
return F_93 ( V_26 ) ;
case V_234 :
F_92 ( L_14 ) ;
V_232 -> V_59 &= V_235 ;
F_94 ( V_26 ,
V_232 -> V_59 & V_235 ) ;
break;
case V_236 :
F_92 ( L_15 ) ;
V_232 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_74 ) )
return - V_107 ;
if ( F_95 ( V_237 , & V_28 -> V_165 ) )
return 0 ;
V_68 = F_96 ( V_28 ) ;
if ( V_68 == V_238 ) {
F_97 ( L_16
L_15 ) ;
return - V_239 ;
}
F_52 ( V_28 ) ;
F_98 ( V_28 , V_240 , 1 , V_68 ) ;
break;
case V_241 :
F_92 ( L_17 ) ;
V_232 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_74 ) )
return - V_107 ;
if ( ! F_99 ( V_237 , & V_28 -> V_165 ) )
return 0 ;
V_68 = F_96 ( V_28 ) ;
if ( V_68 == V_238 ) {
F_97 ( L_16
L_17 ) ;
return - V_239 ;
}
F_98 ( V_28 , V_242 , 1 , V_68 ) ;
F_54 ( V_28 ) ;
break;
default:
F_92 ( L_18 , V_232 -> V_102 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_100 ( struct V_22 * V_22 , void * V_23 ,
struct V_231 * V_232 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_232 -> V_102 ) {
case V_233 :
F_92 ( L_13 ) ;
V_232 -> V_59 = 0 ;
break;
case V_234 :
F_92 ( L_14 ) ;
V_232 -> V_59 &= V_235 ;
break;
case V_236 :
F_92 ( L_15 ) ;
V_232 -> V_59 = 0 ;
break;
case V_241 :
F_92 ( L_17 ) ;
V_232 -> V_59 = 0 ;
break;
default:
F_92 ( L_18 , V_232 -> V_102 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_101 ( struct V_22 * V_22 , void * V_23 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_134 V_243 ;
struct V_128 V_244 ;
int V_15 ;
F_102 ( L_19 , V_245 , V_28 -> V_122 ) ;
if ( V_28 -> V_246 & V_247 ) {
struct V_248 V_249 ;
F_103 ( V_28 , & V_249 ) ;
}
F_25 ( V_28 , V_98 , V_250 ) ;
F_42 ( V_28 , V_28 -> V_151 , & V_243 ) ;
F_37 ( V_28 , V_28 -> V_131 , & V_244 ) ;
F_102 ( L_20 , V_243 . V_174 ) ;
F_102 ( L_21 , V_244 . V_174 ) ;
F_104 ( & V_28 -> V_251 ) ;
F_102 ( L_22 ,
V_28 -> V_252 , V_28 -> V_253 ) ;
F_105 ( & V_28 -> V_251 ) ;
F_102 ( L_23 ,
F_59 ( V_164 , & V_28 -> V_165 ) ? L_24 : L_25 ) ;
F_106 ( & V_28 -> V_36 . V_254 , V_28 -> V_255 . V_174 ) ;
F_102 ( L_26 , V_28 -> V_165 ) ;
for ( V_15 = 0 ; V_15 < V_256 ; V_15 ++ ) {
struct V_29 * V_30 = & V_28 -> V_31 [ V_15 ] ;
if ( V_30 -> V_257 == NULL || V_30 -> V_210 == 0 )
continue;
F_102 ( L_27 ,
V_30 -> V_174 , V_30 -> V_258 ,
F_18 ( & V_30 -> V_215 . V_259 ) * V_30 -> V_211 * 100
/ V_30 -> V_210 ,
( V_30 -> V_210 * V_30 -> V_213 ) / 1024 , V_30 -> V_210 ) ;
}
F_102 ( L_28 ,
( long long ) V_28 -> V_260 ,
( long long ) V_28 -> V_261 ) ;
return 0 ;
}
static long F_107 ( struct V_22 * V_22 , void * V_23 , bool V_262 ,
int V_102 , void * V_103 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_102 ) {
case V_263 : {
T_4 V_113 = * ( T_4 * ) V_103 ;
if ( ( V_113 == 0 ) || ( V_113 & 0x01 ) )
F_24 ( V_28 , V_264 , V_98 , V_265 ,
( T_4 ) V_266 ) ;
break;
}
default:
return - V_267 ;
}
return 0 ;
}
void F_108 ( struct V_268 * V_269 )
{
V_269 -> V_270 = & V_271 ;
}
