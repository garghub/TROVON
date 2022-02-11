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
static int F_26 ( struct V_22 * V_22 , void * V_23 ,
struct V_102 * V_103 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( F_27 ( & V_103 -> V_93 ) ) {
if ( V_103 -> V_103 >= V_104 + V_105 )
return - V_66 ;
V_103 -> V_106 = 4 ;
V_103 -> V_107 = F_28 ( V_28 , V_103 -> V_103 ) ;
return 0 ;
}
F_25 ( V_28 , V_98 , V_108 , V_103 ) ;
return 0 ;
}
static int F_29 ( struct V_22 * V_22 , void * V_23 ,
const struct V_102 * V_103 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( F_27 ( & V_103 -> V_93 ) ) {
if ( V_103 -> V_103 >= V_104 + V_105 )
return - V_66 ;
F_30 ( V_28 , V_103 -> V_107 , V_103 -> V_103 ) ;
return 0 ;
}
F_25 ( V_28 , V_98 , V_109 , V_103 ) ;
return 0 ;
}
static int F_31 ( struct V_22 * V_22 , void * V_23 ,
struct V_110 * V_111 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
F_32 ( V_111 -> V_112 , V_113 , sizeof( V_111 -> V_112 ) ) ;
F_32 ( V_111 -> V_114 , V_28 -> V_115 , sizeof( V_111 -> V_114 ) ) ;
snprintf ( V_111 -> V_116 , sizeof( V_111 -> V_116 ) ,
L_1 , F_33 ( V_28 -> V_117 ) ) ;
V_111 -> V_118 = V_28 -> V_119 ;
if ( V_26 -> type == V_42 )
V_111 -> V_118 |= V_120 ;
return 0 ;
}
static int F_34 ( struct V_22 * V_22 , void * V_23 , struct V_121 * V_122 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_35 ( V_28 , V_122 -> V_123 , V_122 ) ;
}
static int F_36 ( struct V_22 * V_22 , void * V_23 , struct V_121 * V_122 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
V_122 -> V_123 = V_28 -> V_124 ;
return F_35 ( V_28 , V_122 -> V_123 , V_122 ) ;
}
static int F_37 ( struct V_22 * V_22 , void * V_23 , const struct V_121 * V_125 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_125 -> V_123 >= V_28 -> V_126 )
return - V_66 ;
V_28 -> V_124 = V_125 -> V_123 ;
F_38 ( V_28 ) ;
return 0 ;
}
static int F_39 ( struct V_22 * V_22 , void * V_23 , struct V_127 * V_122 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_40 ( V_28 , V_122 -> V_123 , V_122 ) ;
}
static int F_41 ( struct V_22 * V_22 , void * V_23 ,
struct V_128 * V_129 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_129 -> type != V_130 )
return - V_66 ;
V_129 -> V_131 . V_132 = V_129 -> V_131 . V_133 = 0 ;
V_129 -> V_131 . V_35 = 720 ;
V_129 -> V_131 . V_37 = V_28 -> V_70 ? 576 : 480 ;
V_129 -> V_134 . V_135 = V_28 -> V_70 ? 59 : 10 ;
V_129 -> V_134 . V_136 = V_28 -> V_70 ? 54 : 11 ;
V_129 -> V_137 = V_129 -> V_131 ;
return 0 ;
}
static int F_42 ( struct V_22 * V_22 , void * V_23 , const struct V_138 * V_139 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_139 -> type != V_130 )
return - V_66 ;
F_43 ( L_2 ) ;
return - V_66 ;
}
static int F_44 ( struct V_22 * V_22 , void * V_23 , struct V_138 * V_139 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_139 -> type != V_130 )
return - V_66 ;
F_43 ( L_3 ) ;
return - V_66 ;
}
static int F_45 ( struct V_22 * V_22 , void * V_23 ,
struct V_140 * V_17 )
{
static const struct V_140 V_141 [] = {
{ 0 , V_130 , 0 ,
L_4 , V_76 , { 0 , 0 , 0 , 0 }
} ,
{ 1 , V_130 , V_142 ,
L_5 , V_47 , { 0 , 0 , 0 , 0 }
} ,
{ 2 , V_130 , 0 ,
L_6 , V_143 , { 0 , 0 , 0 , 0 }
} ,
} ;
if ( V_17 -> V_123 > F_46 ( V_141 ) - 1 )
return - V_66 ;
* V_17 = V_141 [ V_17 -> V_123 ] ;
return 0 ;
}
static int F_47 ( struct V_22 * V_22 , void * V_23 , unsigned int * V_15 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_15 = V_28 -> V_144 ;
return 0 ;
}
int F_48 ( struct V_22 * V_22 , void * V_23 , unsigned int V_145 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_145 >= V_28 -> V_146 )
return - V_66 ;
if ( V_145 == V_28 -> V_144 ) {
F_49 ( L_7 ) ;
return 0 ;
}
F_49 ( L_8 ,
V_28 -> V_144 , V_145 ) ;
V_28 -> V_144 = V_145 ;
V_28 -> V_124 = V_28 -> V_114 -> V_147 [ V_145 ] . V_148 ;
F_50 ( V_28 ) ;
F_51 ( V_28 ) ;
F_38 ( V_28 ) ;
F_52 ( V_28 ) ;
return 0 ;
}
static int F_53 ( struct V_22 * V_22 , void * V_23 ,
struct V_149 * V_150 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_150 -> V_151 != 0 )
return - V_66 ;
F_25 ( V_28 , V_151 , V_152 , V_150 ) ;
return 0 ;
}
int F_54 ( struct V_22 * V_22 , void * V_23 , const struct V_149 * V_150 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_150 -> V_151 != 0 )
return - V_66 ;
F_50 ( V_28 ) ;
F_49 ( L_9 , V_150 -> V_153 ) ;
F_25 ( V_28 , V_151 , V_154 , V_150 ) ;
F_52 ( V_28 ) ;
return 0 ;
}
static int F_55 ( struct V_22 * V_22 , void * V_23 , T_2 * V_155 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_155 = V_28 -> V_155 ;
return 0 ;
}
int F_56 ( struct V_22 * V_22 , void * V_23 , T_2 V_155 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( ( V_155 & V_156 ) == 0 )
return - V_66 ;
if ( V_155 == V_28 -> V_155 )
return 0 ;
if ( F_57 ( V_157 , & V_28 -> V_158 ) ||
F_18 ( & V_28 -> V_74 ) > 0 ) {
return - V_75 ;
}
V_28 -> V_155 = V_155 ;
V_28 -> V_159 = ( V_155 & V_160 ) ? 1 : 0 ;
V_28 -> V_70 = ! V_28 -> V_159 ;
F_58 ( & V_28 -> V_36 , V_28 -> V_70 ) ;
V_28 -> V_36 . V_35 = 720 ;
V_28 -> V_36 . V_37 = V_28 -> V_70 ? 576 : 480 ;
V_28 -> V_50 . V_58 = V_28 -> V_70 ? 18 : 12 ;
V_28 -> V_50 . V_57 [ 0 ] = V_28 -> V_70 ? 6 : 10 ;
V_28 -> V_50 . V_57 [ 1 ] = V_28 -> V_70 ? 318 : 273 ;
F_49 ( L_10 ,
( unsigned long long ) V_28 -> V_155 ) ;
F_25 ( V_28 , V_98 , V_161 , V_28 -> V_155 ) ;
return 0 ;
}
static int F_59 ( struct V_22 * V_22 , void * V_23 , const struct V_162 * V_163 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_163 -> V_123 != 0 )
return - V_66 ;
F_25 ( V_28 , V_151 , V_164 , V_163 ) ;
return 0 ;
}
static int F_60 ( struct V_22 * V_22 , void * V_23 , struct V_162 * V_163 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_163 -> V_123 != 0 )
return - V_66 ;
F_25 ( V_28 , V_151 , V_165 , V_163 ) ;
if ( V_163 -> type == V_166 )
F_32 ( V_163 -> V_167 , L_11 , sizeof( V_163 -> V_167 ) ) ;
else
F_32 ( V_163 -> V_167 , L_12 , sizeof( V_163 -> V_167 ) ) ;
return 0 ;
}
static int F_61 ( struct V_22 * V_22 , void * V_23 ,
struct V_168 * V_169 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
int V_11 = V_28 -> V_70 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_169 -> type != V_86 )
return - V_66 ;
V_169 -> V_18 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_28 -> V_70 ) ) {
V_169 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
V_169 -> V_18 |= V_11 ;
} else
V_169 -> V_21 [ V_19 ] [ V_20 ] = 0 ;
}
}
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_169 -> V_60 [ V_19 ] = 0 ;
return 0 ;
}
static int F_62 ( struct V_170 * V_171 ,
struct V_172 * V_173 )
{
int V_174 , V_175 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
const int V_180 [ 8 ] = {
- 1 , V_181 , V_182 ,
- 1 , V_183 , - 1 , - 1 , - 1
} ;
V_175 = V_171 -> V_184 - V_171 -> V_185 ;
V_174 = 0 ;
V_177 = & V_173 -> V_186 [ V_173 -> V_187 ] ;
V_179 = (struct V_178 * ) & V_171 -> V_171 [ V_171 -> V_185 ] ;
while ( V_175 >= sizeof( struct V_178 ) &&
V_173 -> V_187 < V_188 ) {
V_177 -> V_52 = ( ( ( V_189 ) F_63 ( V_179 -> V_190 ) ) << 32 )
| F_63 ( V_179 -> V_191 ) ;
V_177 -> V_192 = ( ( ( V_189 ) ( F_63 ( V_179 -> V_193 ) & 1 ) ) << 32 )
| F_63 ( V_179 -> V_194 ) ;
V_177 -> V_195 = F_63 ( V_179 -> V_195 ) ;
V_177 -> V_59 = V_180 [ F_63 ( V_179 -> V_59 ) & 0x7 ] ;
V_177 -> V_60 [ 0 ] = 0 ;
V_177 -> V_60 [ 1 ] = 0 ;
V_173 -> V_187 ++ ;
V_177 = & V_173 -> V_186 [ V_173 -> V_187 ] ;
V_179 ++ ;
V_175 -= sizeof( struct V_178 ) ;
V_174 += sizeof( struct V_178 ) ;
}
if ( V_175 > 0 && V_175 < sizeof( struct V_178 ) )
V_174 += V_175 ;
V_171 -> V_185 += V_174 ;
return V_174 ;
}
static int F_64 ( struct V_29 * V_30 , struct V_196 * V_197 ,
struct V_172 * V_173 )
{
if ( V_30 -> type != V_198 )
return - V_66 ;
if ( V_197 -> V_199 == NULL )
V_197 -> V_199 = F_65 ( & V_197 -> V_200 ,
struct V_170 , V_201 ) ;
if ( F_66 ( V_197 -> V_199 , & V_197 -> V_200 , V_201 ) ) {
V_197 -> V_185 = V_197 -> V_184 ;
return 0 ;
}
F_67 (mdl->curr_buf, &mdl->buf_list, list) {
if ( V_197 -> V_199 -> V_185 >= V_197 -> V_199 -> V_184 )
continue;
V_197 -> V_185 += F_62 ( V_197 -> V_199 , V_173 ) ;
if ( V_173 -> V_187 >= V_188 ||
V_197 -> V_199 -> V_185 < V_197 -> V_199 -> V_184 ||
V_197 -> V_185 >= V_197 -> V_184 )
break;
}
return 0 ;
}
static int F_68 ( struct V_22 * V_22 , void * V_23 ,
struct V_172 * V_173 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_198 ] ;
T_3 V_202 ;
struct V_196 * V_197 ;
if ( ! F_69 ( V_30 ) )
return - V_66 ;
V_202 = V_30 -> V_203 -
V_30 -> V_204 * V_205 ;
if ( V_202 <= 0 )
V_202 = 1 ;
V_202 = V_202 * V_30 -> V_206 / sizeof( struct V_178 ) ;
V_173 -> V_187 = 0 ;
V_173 -> V_207 = V_202 ;
memset ( V_173 -> V_60 , 0 , sizeof( V_173 -> V_60 ) ) ;
do {
V_197 = F_70 ( V_30 , & V_30 -> V_208 ) ;
if ( V_197 == NULL )
break;
F_64 ( V_30 , V_197 , V_173 ) ;
if ( V_197 -> V_185 < V_197 -> V_184 ) {
F_71 ( V_30 , V_197 , & V_30 -> V_208 ) ;
break;
}
F_72 ( V_30 , V_197 , & V_30 -> V_209 ) ;
} while ( V_173 -> V_187 < V_188 );
F_73 ( V_30 ) ;
return 0 ;
}
static struct V_210 * F_74 ( struct V_25 * V_26 )
{
struct V_210 * V_211 = NULL ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
switch ( V_30 -> V_212 ) {
case V_130 :
V_211 = & V_30 -> V_213 ;
break;
case V_84 :
break;
default:
break;
}
return V_211 ;
}
static int F_75 ( struct V_22 * V_22 , void * V_41 ,
enum V_214 type )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_212 != V_130 ) &&
( V_30 -> V_212 != V_84 ) )
return - V_66 ;
if ( V_26 -> type != V_42 )
return - V_66 ;
F_76 ( & V_30 -> V_216 , F_77 ( 2000 ) + V_217 ) ;
return F_78 ( F_74 ( V_26 ) ) ;
}
static int F_79 ( struct V_22 * V_22 , void * V_41 ,
enum V_214 type )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_212 != V_130 ) &&
( V_30 -> V_212 != V_84 ) )
return - V_66 ;
if ( V_26 -> type != V_42 )
return - V_66 ;
return F_80 ( F_74 ( V_26 ) ) ;
}
static int F_81 ( struct V_22 * V_22 , void * V_41 ,
struct V_218 * V_219 )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_212 != V_130 ) &&
( V_30 -> V_212 != V_84 ) )
return - V_66 ;
return F_82 ( F_74 ( V_26 ) , V_219 ) ;
}
static int F_83 ( struct V_22 * V_22 , void * V_41 ,
struct V_220 * V_221 )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_212 != V_130 ) &&
( V_30 -> V_212 != V_84 ) )
return - V_66 ;
return F_84 ( F_74 ( V_26 ) , V_221 ) ;
}
static int F_85 ( struct V_22 * V_22 , void * V_41 , struct V_220 * V_221 )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_212 != V_130 ) &&
( V_30 -> V_212 != V_84 ) )
return - V_66 ;
return F_86 ( F_74 ( V_26 ) , V_221 ) ;
}
static int F_87 ( struct V_22 * V_22 , void * V_41 , struct V_220 * V_221 )
{
struct V_25 * V_26 = V_22 -> V_215 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_212 != V_130 ) &&
( V_30 -> V_212 != V_84 ) )
return - V_66 ;
return F_88 ( F_74 ( V_26 ) , V_221 , V_22 -> V_222 & V_223 ) ;
}
static int F_89 ( struct V_22 * V_22 , void * V_23 ,
struct V_224 * V_225 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
T_4 V_68 ;
switch ( V_225 -> V_226 ) {
case V_227 :
F_90 ( L_13 ) ;
V_225 -> V_59 = 0 ;
return F_91 ( V_26 ) ;
case V_228 :
F_90 ( L_14 ) ;
V_225 -> V_59 &= V_229 ;
F_92 ( V_26 ,
V_225 -> V_59 & V_229 ) ;
break;
case V_230 :
F_90 ( L_15 ) ;
V_225 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_74 ) )
return - V_231 ;
if ( F_93 ( V_232 , & V_28 -> V_158 ) )
return 0 ;
V_68 = F_94 ( V_28 ) ;
if ( V_68 == V_233 ) {
F_95 ( L_16
L_15 ) ;
return - V_234 ;
}
F_50 ( V_28 ) ;
F_96 ( V_28 , V_235 , 1 , V_68 ) ;
break;
case V_236 :
F_90 ( L_17 ) ;
V_225 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_74 ) )
return - V_231 ;
if ( ! F_97 ( V_232 , & V_28 -> V_158 ) )
return 0 ;
V_68 = F_94 ( V_28 ) ;
if ( V_68 == V_233 ) {
F_95 ( L_16
L_17 ) ;
return - V_234 ;
}
F_96 ( V_28 , V_237 , 1 , V_68 ) ;
F_52 ( V_28 ) ;
break;
default:
F_90 ( L_18 , V_225 -> V_226 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_98 ( struct V_22 * V_22 , void * V_23 ,
struct V_224 * V_225 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_225 -> V_226 ) {
case V_227 :
F_90 ( L_13 ) ;
V_225 -> V_59 = 0 ;
break;
case V_228 :
F_90 ( L_14 ) ;
V_225 -> V_59 &= V_229 ;
break;
case V_230 :
F_90 ( L_15 ) ;
V_225 -> V_59 = 0 ;
break;
case V_236 :
F_90 ( L_17 ) ;
V_225 -> V_59 = 0 ;
break;
default:
F_90 ( L_18 , V_225 -> V_226 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_99 ( struct V_22 * V_22 , void * V_23 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_127 V_238 ;
struct V_121 V_239 ;
int V_15 ;
F_100 ( L_19 , V_240 , V_28 -> V_115 ) ;
if ( V_28 -> V_241 & V_242 ) {
struct V_243 V_244 ;
F_101 ( V_28 , & V_244 ) ;
}
F_25 ( V_28 , V_98 , V_245 ) ;
F_40 ( V_28 , V_28 -> V_144 , & V_238 ) ;
F_35 ( V_28 , V_28 -> V_124 , & V_239 ) ;
F_100 ( L_20 , V_238 . V_167 ) ;
F_100 ( L_21 , V_239 . V_167 ) ;
F_102 ( & V_28 -> V_246 ) ;
F_100 ( L_22 ,
V_28 -> V_247 , V_28 -> V_248 ) ;
F_103 ( & V_28 -> V_246 ) ;
F_100 ( L_23 ,
F_57 ( V_157 , & V_28 -> V_158 ) ? L_24 : L_25 ) ;
F_104 ( & V_28 -> V_36 . V_249 , V_28 -> V_250 . V_167 ) ;
F_100 ( L_26 , V_28 -> V_158 ) ;
for ( V_15 = 0 ; V_15 < V_251 ; V_15 ++ ) {
struct V_29 * V_30 = & V_28 -> V_31 [ V_15 ] ;
if ( V_30 -> V_252 == NULL || V_30 -> V_203 == 0 )
continue;
F_100 ( L_27 ,
V_30 -> V_167 , V_30 -> V_253 ,
F_18 ( & V_30 -> V_208 . V_254 ) * V_30 -> V_204 * 100
/ V_30 -> V_203 ,
( V_30 -> V_203 * V_30 -> V_206 ) / 1024 , V_30 -> V_203 ) ;
}
F_100 ( L_28 ,
( long long ) V_28 -> V_255 ,
( long long ) V_28 -> V_256 ) ;
return 0 ;
}
static long F_105 ( struct V_22 * V_22 , void * V_23 , bool V_257 ,
unsigned int V_226 , void * V_258 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_226 ) {
case V_259 : {
T_4 V_107 = * ( T_4 * ) V_258 ;
if ( ( V_107 == 0 ) || ( V_107 & 0x01 ) )
F_24 ( V_28 , V_260 , V_98 , V_261 ,
( T_4 ) V_262 ) ;
break;
}
default:
return - V_263 ;
}
return 0 ;
}
void F_106 ( struct V_264 * V_265 )
{
V_265 -> V_266 = & V_267 ;
}
