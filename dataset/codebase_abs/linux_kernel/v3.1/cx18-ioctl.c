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
if ( V_30 -> V_43 == V_44 )
V_33 -> V_45 = V_33 -> V_37 * 720 * 3 / 2 ;
else
V_33 -> V_45 = V_33 -> V_37 * 720 * 2 ;
V_33 -> V_46 = 720 ;
} else {
V_33 -> V_43 = V_47 ;
V_33 -> V_45 = 128 * 1024 ;
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
V_72 . V_35 = V_28 -> V_36 . V_35 = V_67 ;
V_72 . V_37 = V_28 -> V_36 . V_37 = V_68 ;
V_72 . V_76 = V_77 ;
F_11 ( V_28 -> V_64 , V_78 , V_79 , & V_72 ) ;
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
V_73 = F_11 ( V_28 -> V_64 , V_50 , V_80 , & V_17 -> V_17 . V_50 ) ;
if ( V_73 )
return V_73 ;
V_28 -> V_50 . V_81 -> V_18 = 0 ;
V_28 -> V_50 . V_82 . type = V_83 ;
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
V_73 = F_11 ( V_28 -> V_64 , V_50 , V_84 , & V_17 -> V_17 . V_61 ) ;
if ( V_73 )
return V_73 ;
V_28 -> V_50 . V_82 . type = V_85 ;
memcpy ( V_28 -> V_50 . V_81 , V_49 , sizeof( * V_28 -> V_50 . V_81 ) ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_22 , void * V_23 ,
struct V_86 * V_87 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
int V_88 = 0 ;
V_87 -> V_89 = V_90 ;
V_87 -> V_91 = 0 ;
switch ( V_87 -> V_92 . type ) {
case V_93 :
switch ( V_87 -> V_92 . V_94 ) {
case 0 :
V_87 -> V_89 = V_95 ;
V_87 -> V_91 = F_23 ( V_28 , 0xC72028 ) ;
break;
case 1 :
F_24 ( V_28 , V_96 ,
V_97 , V_98 , V_87 ) ;
break;
default:
V_88 = - V_66 ;
break;
}
break;
case V_99 :
F_25 ( V_28 , V_97 , V_98 , V_87 ) ;
break;
case V_100 :
F_25 ( V_28 , V_97 , V_98 , V_87 ) ;
break;
default:
V_88 = - V_66 ;
break;
}
return V_88 ;
}
static int F_26 ( struct V_27 * V_28 , unsigned int V_101 , void * V_102 )
{
struct V_103 * V_104 = V_102 ;
if ( ! F_27 ( V_105 ) )
return - V_106 ;
if ( V_104 -> V_107 >= V_108 + V_109 )
return - V_66 ;
V_104 -> V_110 = 4 ;
if ( V_101 == V_111 )
F_28 ( V_28 , V_104 -> V_112 , V_104 -> V_107 ) ;
else
V_104 -> V_112 = F_29 ( V_28 , V_104 -> V_107 ) ;
return 0 ;
}
static int F_30 ( struct V_22 * V_22 , void * V_23 ,
struct V_103 * V_107 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( F_31 ( & V_107 -> V_92 ) )
return F_26 ( V_28 , V_113 , V_107 ) ;
F_25 ( V_28 , V_97 , V_114 , V_107 ) ;
return 0 ;
}
static int F_32 ( struct V_22 * V_22 , void * V_23 ,
struct V_103 * V_107 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( F_31 ( & V_107 -> V_92 ) )
return F_26 ( V_28 , V_111 , V_107 ) ;
F_25 ( V_28 , V_97 , V_115 , V_107 ) ;
return 0 ;
}
static int F_33 ( struct V_22 * V_22 , void * V_23 ,
struct V_116 * V_117 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
F_34 ( V_117 -> V_118 , V_119 , sizeof( V_117 -> V_118 ) ) ;
F_34 ( V_117 -> V_120 , V_28 -> V_121 , sizeof( V_117 -> V_120 ) ) ;
snprintf ( V_117 -> V_122 , sizeof( V_117 -> V_122 ) ,
L_1 , F_35 ( V_28 -> V_123 ) ) ;
V_117 -> V_124 = V_28 -> V_125 ;
return 0 ;
}
static int F_36 ( struct V_22 * V_22 , void * V_23 , struct V_126 * V_127 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_37 ( V_28 , V_127 -> V_128 , V_127 ) ;
}
static int F_38 ( struct V_22 * V_22 , void * V_23 , struct V_126 * V_127 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
V_127 -> V_128 = V_28 -> V_129 ;
return F_37 ( V_28 , V_127 -> V_128 , V_127 ) ;
}
static int F_39 ( struct V_22 * V_22 , void * V_23 , struct V_126 * V_130 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_130 -> V_128 >= V_28 -> V_131 )
return - V_66 ;
V_28 -> V_129 = V_130 -> V_128 ;
F_40 ( V_28 ) ;
return 0 ;
}
static int F_41 ( struct V_22 * V_22 , void * V_23 , struct V_132 * V_127 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_42 ( V_28 , V_127 -> V_128 , V_127 ) ;
}
static int F_43 ( struct V_22 * V_22 , void * V_23 ,
struct V_133 * V_134 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_134 -> type != V_135 )
return - V_66 ;
V_134 -> V_136 . V_137 = V_134 -> V_136 . V_138 = 0 ;
V_134 -> V_136 . V_35 = 720 ;
V_134 -> V_136 . V_37 = V_28 -> V_70 ? 576 : 480 ;
V_134 -> V_139 . V_140 = V_28 -> V_70 ? 59 : 10 ;
V_134 -> V_139 . V_141 = V_28 -> V_70 ? 54 : 11 ;
V_134 -> V_142 = V_134 -> V_136 ;
return 0 ;
}
static int F_44 ( struct V_22 * V_22 , void * V_23 , struct V_143 * V_144 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_144 -> type != V_135 )
return - V_66 ;
F_45 ( L_2 ) ;
return - V_66 ;
}
static int F_46 ( struct V_22 * V_22 , void * V_23 , struct V_143 * V_144 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_144 -> type != V_135 )
return - V_66 ;
F_45 ( L_3 ) ;
return - V_66 ;
}
static int F_47 ( struct V_22 * V_22 , void * V_23 ,
struct V_145 * V_17 )
{
static const struct V_145 V_146 [] = {
{ 0 , V_135 , 0 ,
L_4 , V_44 , { 0 , 0 , 0 , 0 }
} ,
{ 1 , V_135 , V_147 ,
L_5 , V_47 , { 0 , 0 , 0 , 0 }
} ,
{ 2 , V_135 , 0 ,
L_6 , V_148 , { 0 , 0 , 0 , 0 }
} ,
} ;
if ( V_17 -> V_128 > F_48 ( V_146 ) - 1 )
return - V_66 ;
* V_17 = V_146 [ V_17 -> V_128 ] ;
return 0 ;
}
static int F_49 ( struct V_22 * V_22 , void * V_23 , unsigned int * V_15 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_15 = V_28 -> V_149 ;
return 0 ;
}
int F_50 ( struct V_22 * V_22 , void * V_23 , unsigned int V_150 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_150 >= V_28 -> V_151 )
return - V_66 ;
if ( V_150 == V_28 -> V_149 ) {
F_51 ( L_7 ) ;
return 0 ;
}
F_51 ( L_8 ,
V_28 -> V_149 , V_150 ) ;
V_28 -> V_149 = V_150 ;
V_28 -> V_129 = V_28 -> V_120 -> V_152 [ V_150 ] . V_153 ;
F_52 ( V_28 ) ;
F_53 ( V_28 ) ;
F_40 ( V_28 ) ;
F_54 ( V_28 ) ;
return 0 ;
}
static int F_55 ( struct V_22 * V_22 , void * V_23 ,
struct V_154 * V_155 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_155 -> V_156 != 0 )
return - V_66 ;
F_25 ( V_28 , V_156 , V_157 , V_155 ) ;
return 0 ;
}
int F_56 ( struct V_22 * V_22 , void * V_23 , struct V_154 * V_155 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_155 -> V_156 != 0 )
return - V_66 ;
F_52 ( V_28 ) ;
F_51 ( L_9 , V_155 -> V_158 ) ;
F_25 ( V_28 , V_156 , V_159 , V_155 ) ;
F_54 ( V_28 ) ;
return 0 ;
}
static int F_57 ( struct V_22 * V_22 , void * V_23 , T_2 * V_160 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_160 = V_28 -> V_160 ;
return 0 ;
}
int F_58 ( struct V_22 * V_22 , void * V_23 , T_2 * V_160 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( ( * V_160 & V_161 ) == 0 )
return - V_66 ;
if ( * V_160 == V_28 -> V_160 )
return 0 ;
if ( F_59 ( V_162 , & V_28 -> V_163 ) ||
F_18 ( & V_28 -> V_74 ) > 0 ) {
return - V_75 ;
}
V_28 -> V_160 = * V_160 ;
V_28 -> V_164 = ( * V_160 & V_165 ) ? 1 : 0 ;
V_28 -> V_70 = ! V_28 -> V_164 ;
F_60 ( & V_28 -> V_36 , V_28 -> V_70 ) ;
V_28 -> V_36 . V_35 = 720 ;
V_28 -> V_36 . V_37 = V_28 -> V_70 ? 576 : 480 ;
V_28 -> V_50 . V_58 = V_28 -> V_70 ? 18 : 12 ;
V_28 -> V_50 . V_57 [ 0 ] = V_28 -> V_70 ? 6 : 10 ;
V_28 -> V_50 . V_57 [ 1 ] = V_28 -> V_70 ? 318 : 273 ;
F_51 ( L_10 ,
( unsigned long long ) V_28 -> V_160 ) ;
F_25 ( V_28 , V_97 , V_166 , V_28 -> V_160 ) ;
return 0 ;
}
static int F_61 ( struct V_22 * V_22 , void * V_23 , struct V_167 * V_168 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_168 -> V_128 != 0 )
return - V_66 ;
F_25 ( V_28 , V_156 , V_169 , V_168 ) ;
return 0 ;
}
static int F_62 ( struct V_22 * V_22 , void * V_23 , struct V_167 * V_168 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_168 -> V_128 != 0 )
return - V_66 ;
F_25 ( V_28 , V_156 , V_170 , V_168 ) ;
if ( V_168 -> type == V_171 )
F_34 ( V_168 -> V_172 , L_11 , sizeof( V_168 -> V_172 ) ) ;
else
F_34 ( V_168 -> V_172 , L_12 , sizeof( V_168 -> V_172 ) ) ;
return 0 ;
}
static int F_63 ( struct V_22 * V_22 , void * V_23 ,
struct V_173 * V_174 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
int V_11 = V_28 -> V_70 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_174 -> type != V_85 )
return - V_66 ;
V_174 -> V_18 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_28 -> V_70 ) ) {
V_174 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
V_174 -> V_18 |= V_11 ;
} else
V_174 -> V_21 [ V_19 ] [ V_20 ] = 0 ;
}
}
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_174 -> V_60 [ V_19 ] = 0 ;
return 0 ;
}
static int F_64 ( struct V_175 * V_176 ,
struct V_177 * V_178 )
{
int V_179 , V_180 ;
struct V_181 * V_182 ;
struct V_183 * V_184 ;
const int V_185 [ 8 ] = {
- 1 , V_186 , V_187 ,
- 1 , V_188 , - 1 , - 1 , - 1
} ;
V_180 = V_176 -> V_189 - V_176 -> V_190 ;
V_179 = 0 ;
V_182 = & V_178 -> V_191 [ V_178 -> V_192 ] ;
V_184 = (struct V_183 * ) & V_176 -> V_176 [ V_176 -> V_190 ] ;
while ( V_180 >= sizeof( struct V_183 ) &&
V_178 -> V_192 < V_193 ) {
V_182 -> V_52 = ( ( ( V_194 ) F_65 ( V_184 -> V_195 ) ) << 32 )
| F_65 ( V_184 -> V_196 ) ;
V_182 -> V_197 = ( ( ( V_194 ) ( F_65 ( V_184 -> V_198 ) & 1 ) ) << 32 )
| F_65 ( V_184 -> V_199 ) ;
V_182 -> V_200 = F_65 ( V_184 -> V_200 ) ;
V_182 -> V_59 = V_185 [ F_65 ( V_184 -> V_59 ) & 0x7 ] ;
V_182 -> V_60 [ 0 ] = 0 ;
V_182 -> V_60 [ 1 ] = 0 ;
V_178 -> V_192 ++ ;
V_182 = & V_178 -> V_191 [ V_178 -> V_192 ] ;
V_184 ++ ;
V_180 -= sizeof( struct V_183 ) ;
V_179 += sizeof( struct V_183 ) ;
}
if ( V_180 > 0 && V_180 < sizeof( struct V_183 ) )
V_179 += V_180 ;
V_176 -> V_190 += V_179 ;
return V_179 ;
}
static int F_66 ( struct V_29 * V_30 , struct V_201 * V_202 ,
struct V_177 * V_178 )
{
if ( V_30 -> type != V_203 )
return - V_66 ;
if ( V_202 -> V_204 == NULL )
V_202 -> V_204 = F_67 ( & V_202 -> V_205 ,
struct V_175 , V_206 ) ;
if ( F_68 ( V_202 -> V_204 , & V_202 -> V_205 , V_206 ) ) {
V_202 -> V_190 = V_202 -> V_189 ;
return 0 ;
}
F_69 (mdl->curr_buf, &mdl->buf_list, list) {
if ( V_202 -> V_204 -> V_190 >= V_202 -> V_204 -> V_189 )
continue;
V_202 -> V_190 += F_64 ( V_202 -> V_204 , V_178 ) ;
if ( V_178 -> V_192 >= V_193 ||
V_202 -> V_204 -> V_190 < V_202 -> V_204 -> V_189 ||
V_202 -> V_190 >= V_202 -> V_189 )
break;
}
return 0 ;
}
static int F_70 ( struct V_22 * V_22 , void * V_23 ,
struct V_177 * V_178 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_203 ] ;
T_3 V_207 ;
struct V_201 * V_202 ;
if ( ! F_71 ( V_30 ) )
return - V_66 ;
V_207 = V_30 -> V_208 -
V_30 -> V_209 * V_210 ;
if ( V_207 <= 0 )
V_207 = 1 ;
V_207 = V_207 * V_30 -> V_211 / sizeof( struct V_183 ) ;
V_178 -> V_192 = 0 ;
V_178 -> V_212 = V_207 ;
memset ( V_178 -> V_60 , 0 , sizeof( V_178 -> V_60 ) ) ;
do {
V_202 = F_72 ( V_30 , & V_30 -> V_213 ) ;
if ( V_202 == NULL )
break;
F_66 ( V_30 , V_202 , V_178 ) ;
if ( V_202 -> V_190 < V_202 -> V_189 ) {
F_73 ( V_30 , V_202 , & V_30 -> V_213 ) ;
break;
}
F_74 ( V_30 , V_202 , & V_30 -> V_214 ) ;
} while ( V_178 -> V_192 < V_193 );
F_75 ( V_30 ) ;
return 0 ;
}
static struct V_215 * F_76 ( struct V_25 * V_26 )
{
struct V_215 * V_216 = NULL ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
switch ( V_30 -> V_217 ) {
case V_135 :
V_216 = & V_30 -> V_218 ;
break;
case V_83 :
break;
default:
break;
}
return V_216 ;
}
static int F_77 ( struct V_22 * V_22 , void * V_41 ,
enum V_219 type )
{
struct V_25 * V_26 = V_22 -> V_220 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_217 != V_135 ) &&
( V_30 -> V_217 != V_83 ) )
return - V_66 ;
if ( V_26 -> type != V_42 )
return - V_66 ;
F_78 ( & V_30 -> V_221 , F_79 ( 2000 ) + V_222 ) ;
return F_80 ( F_76 ( V_26 ) ) ;
}
static int F_81 ( struct V_22 * V_22 , void * V_41 ,
enum V_219 type )
{
struct V_25 * V_26 = V_22 -> V_220 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_217 != V_135 ) &&
( V_30 -> V_217 != V_83 ) )
return - V_66 ;
if ( V_26 -> type != V_42 )
return - V_66 ;
return F_82 ( F_76 ( V_26 ) ) ;
}
static int F_83 ( struct V_22 * V_22 , void * V_41 ,
struct V_223 * V_224 )
{
struct V_25 * V_26 = V_22 -> V_220 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_217 != V_135 ) &&
( V_30 -> V_217 != V_83 ) )
return - V_66 ;
return F_84 ( F_76 ( V_26 ) , V_224 ) ;
}
static int F_85 ( struct V_22 * V_22 , void * V_41 ,
struct V_225 * V_226 )
{
struct V_25 * V_26 = V_22 -> V_220 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_217 != V_135 ) &&
( V_30 -> V_217 != V_83 ) )
return - V_66 ;
return F_86 ( F_76 ( V_26 ) , V_226 ) ;
}
static int F_87 ( struct V_22 * V_22 , void * V_41 , struct V_225 * V_226 )
{
struct V_25 * V_26 = V_22 -> V_220 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_217 != V_135 ) &&
( V_30 -> V_217 != V_83 ) )
return - V_66 ;
return F_88 ( F_76 ( V_26 ) , V_226 ) ;
}
static int F_89 ( struct V_22 * V_22 , void * V_41 , struct V_225 * V_226 )
{
struct V_25 * V_26 = V_22 -> V_220 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_217 != V_135 ) &&
( V_30 -> V_217 != V_83 ) )
return - V_66 ;
return F_90 ( F_76 ( V_26 ) , V_226 , V_22 -> V_227 & V_228 ) ;
}
static int F_91 ( struct V_22 * V_22 , void * V_23 ,
struct V_229 * V_230 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
T_4 V_68 ;
switch ( V_230 -> V_101 ) {
case V_231 :
F_92 ( L_13 ) ;
V_230 -> V_59 = 0 ;
return F_93 ( V_26 ) ;
case V_232 :
F_92 ( L_14 ) ;
V_230 -> V_59 &= V_233 ;
F_94 ( V_26 ,
V_230 -> V_59 & V_233 ) ;
break;
case V_234 :
F_92 ( L_15 ) ;
V_230 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_74 ) )
return - V_106 ;
if ( F_95 ( V_235 , & V_28 -> V_163 ) )
return 0 ;
V_68 = F_96 ( V_28 ) ;
if ( V_68 == V_236 ) {
F_97 ( L_16
L_15 ) ;
return - V_237 ;
}
F_52 ( V_28 ) ;
F_98 ( V_28 , V_238 , 1 , V_68 ) ;
break;
case V_239 :
F_92 ( L_17 ) ;
V_230 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_74 ) )
return - V_106 ;
if ( ! F_99 ( V_235 , & V_28 -> V_163 ) )
return 0 ;
V_68 = F_96 ( V_28 ) ;
if ( V_68 == V_236 ) {
F_97 ( L_16
L_17 ) ;
return - V_237 ;
}
F_98 ( V_28 , V_240 , 1 , V_68 ) ;
F_54 ( V_28 ) ;
break;
default:
F_92 ( L_18 , V_230 -> V_101 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_100 ( struct V_22 * V_22 , void * V_23 ,
struct V_229 * V_230 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_230 -> V_101 ) {
case V_231 :
F_92 ( L_13 ) ;
V_230 -> V_59 = 0 ;
break;
case V_232 :
F_92 ( L_14 ) ;
V_230 -> V_59 &= V_233 ;
break;
case V_234 :
F_92 ( L_15 ) ;
V_230 -> V_59 = 0 ;
break;
case V_239 :
F_92 ( L_17 ) ;
V_230 -> V_59 = 0 ;
break;
default:
F_92 ( L_18 , V_230 -> V_101 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_101 ( struct V_22 * V_22 , void * V_23 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_132 V_241 ;
struct V_126 V_242 ;
int V_15 ;
F_102 ( L_19
L_20 , V_28 -> V_243 ) ;
F_102 ( L_21 , V_244 , V_28 -> V_121 ) ;
if ( V_28 -> V_245 & V_246 ) {
struct V_247 V_248 ;
F_103 ( V_28 , & V_248 ) ;
}
F_25 ( V_28 , V_97 , V_249 ) ;
F_42 ( V_28 , V_28 -> V_149 , & V_241 ) ;
F_37 ( V_28 , V_28 -> V_129 , & V_242 ) ;
F_102 ( L_22 , V_241 . V_172 ) ;
F_102 ( L_23 , V_242 . V_172 ) ;
F_104 ( & V_28 -> V_250 ) ;
F_102 ( L_24 ,
V_28 -> V_251 , V_28 -> V_252 ) ;
F_105 ( & V_28 -> V_250 ) ;
F_102 ( L_25 ,
F_59 ( V_162 , & V_28 -> V_163 ) ? L_26 : L_27 ) ;
F_106 ( & V_28 -> V_36 . V_253 , V_28 -> V_254 . V_172 ) ;
F_102 ( L_28 , V_28 -> V_163 ) ;
for ( V_15 = 0 ; V_15 < V_255 ; V_15 ++ ) {
struct V_29 * V_30 = & V_28 -> V_31 [ V_15 ] ;
if ( V_30 -> V_256 == NULL || V_30 -> V_208 == 0 )
continue;
F_102 ( L_29 ,
V_30 -> V_172 , V_30 -> V_257 ,
F_18 ( & V_30 -> V_213 . V_258 ) * V_30 -> V_209 * 100
/ V_30 -> V_208 ,
( V_30 -> V_208 * V_30 -> V_211 ) / 1024 , V_30 -> V_208 ) ;
}
F_102 ( L_30 ,
( long long ) V_28 -> V_259 ,
( long long ) V_28 -> V_260 ) ;
F_102 ( L_31
L_32 , V_28 -> V_243 ) ;
return 0 ;
}
static long F_107 ( struct V_22 * V_22 , void * V_23 , bool V_261 ,
int V_101 , void * V_102 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_101 ) {
case V_262 : {
T_4 V_112 = * ( T_4 * ) V_102 ;
if ( ( V_112 == 0 ) || ( V_112 & 0x01 ) )
F_24 ( V_28 , V_263 , V_97 , V_264 ,
( T_4 ) V_265 ) ;
break;
}
default:
return - V_66 ;
}
return 0 ;
}
long F_108 ( struct V_22 * V_266 , unsigned int V_101 ,
unsigned long V_102 )
{
struct V_267 * V_268 = F_109 ( V_266 ) ;
struct V_25 * V_26 = F_110 ( V_266 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
long V_269 ;
F_104 ( & V_28 -> V_270 ) ;
if ( V_271 & V_272 )
V_268 -> V_273 = V_274 | V_275 ;
V_269 = F_111 ( V_266 , V_101 , V_102 ) ;
V_268 -> V_273 = 0 ;
F_105 ( & V_28 -> V_270 ) ;
return V_269 ;
}
void F_112 ( struct V_267 * V_276 )
{
V_276 -> V_277 = & V_278 ;
}
