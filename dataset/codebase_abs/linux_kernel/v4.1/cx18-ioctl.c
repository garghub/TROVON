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
V_30 -> V_42 == V_17 -> V_17 . V_34 . V_42 )
return 0 ;
if ( F_18 ( & V_28 -> V_74 ) > 0 )
return - V_75 ;
V_30 -> V_42 = V_17 -> V_17 . V_34 . V_42 ;
if ( V_30 -> V_42 == V_76 ) {
V_30 -> V_44 = V_68 * 720 * 3 / 2 ;
V_30 -> V_46 = 720 ;
} else {
V_30 -> V_44 = V_68 * 720 * 2 ;
V_30 -> V_46 = 1440 ;
}
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
if ( V_88 -> V_88 & 0x3 )
return - V_66 ;
if ( V_88 -> V_88 >= V_89 + V_90 )
return - V_66 ;
V_88 -> V_91 = 4 ;
V_88 -> V_92 = F_23 ( V_28 , V_88 -> V_88 ) ;
return 0 ;
}
static int F_24 ( struct V_22 * V_22 , void * V_23 ,
const struct V_87 * V_88 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_88 -> V_88 & 0x3 )
return - V_66 ;
if ( V_88 -> V_88 >= V_89 + V_90 )
return - V_66 ;
F_25 ( V_28 , V_88 -> V_92 , V_88 -> V_88 ) ;
return 0 ;
}
static int F_26 ( struct V_22 * V_22 , void * V_23 ,
struct V_93 * V_94 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_29 * V_30 = F_27 ( V_22 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
F_28 ( V_94 -> V_95 , V_96 , sizeof( V_94 -> V_95 ) ) ;
F_28 ( V_94 -> V_97 , V_28 -> V_98 , sizeof( V_94 -> V_97 ) ) ;
snprintf ( V_94 -> V_99 , sizeof( V_94 -> V_99 ) ,
L_1 , F_29 ( V_28 -> V_100 ) ) ;
V_94 -> V_101 = V_28 -> V_102 ;
V_94 -> V_103 = V_30 -> V_104 ;
V_94 -> V_101 |= V_105 ;
return 0 ;
}
static int F_30 ( struct V_22 * V_22 , void * V_23 , struct V_106 * V_107 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_31 ( V_28 , V_107 -> V_108 , V_107 ) ;
}
static int F_32 ( struct V_22 * V_22 , void * V_23 , struct V_106 * V_107 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
V_107 -> V_108 = V_28 -> V_109 ;
return F_31 ( V_28 , V_107 -> V_108 , V_107 ) ;
}
static int F_33 ( struct V_22 * V_22 , void * V_23 , const struct V_106 * V_110 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_110 -> V_108 >= V_28 -> V_111 )
return - V_66 ;
V_28 -> V_109 = V_110 -> V_108 ;
F_34 ( V_28 ) ;
return 0 ;
}
static int F_35 ( struct V_22 * V_22 , void * V_23 , struct V_112 * V_107 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_36 ( V_28 , V_107 -> V_108 , V_107 ) ;
}
static int F_37 ( struct V_22 * V_22 , void * V_23 ,
struct V_113 * V_114 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_114 -> type != V_115 )
return - V_66 ;
V_114 -> V_116 . V_117 = V_28 -> V_70 ? 59 : 10 ;
V_114 -> V_116 . V_118 = V_28 -> V_70 ? 54 : 11 ;
return 0 ;
}
static int F_38 ( struct V_22 * V_22 , void * V_23 ,
struct V_119 * V_120 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_120 -> type != V_115 )
return - V_66 ;
switch ( V_120 -> V_121 ) {
case V_122 :
case V_123 :
V_120 -> V_124 . V_125 = V_120 -> V_124 . V_126 = 0 ;
V_120 -> V_124 . V_35 = 720 ;
V_120 -> V_124 . V_37 = V_28 -> V_70 ? 576 : 480 ;
break;
default:
return - V_66 ;
}
return 0 ;
}
static int F_39 ( struct V_22 * V_22 , void * V_23 ,
struct V_127 * V_17 )
{
static const struct V_127 V_128 [] = {
{ 0 , V_115 , 0 ,
L_2 , V_76 , { 0 , 0 , 0 , 0 }
} ,
{ 1 , V_115 , V_129 ,
L_3 , V_47 , { 0 , 0 , 0 , 0 }
} ,
{ 2 , V_115 , 0 ,
L_4 , V_130 , { 0 , 0 , 0 , 0 }
} ,
} ;
if ( V_17 -> V_108 > F_40 ( V_128 ) - 1 )
return - V_66 ;
* V_17 = V_128 [ V_17 -> V_108 ] ;
return 0 ;
}
static int F_41 ( struct V_22 * V_22 , void * V_23 , unsigned int * V_15 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_15 = V_28 -> V_131 ;
return 0 ;
}
int F_42 ( struct V_22 * V_22 , void * V_23 , unsigned int V_132 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
T_2 V_133 = V_134 ;
const struct V_135 * V_136 =
V_28 -> V_97 -> V_137 + V_132 ;
if ( V_132 >= V_28 -> V_138 )
return - V_66 ;
if ( V_132 == V_28 -> V_131 ) {
F_43 ( L_5 ) ;
return 0 ;
}
F_43 ( L_6 ,
V_28 -> V_131 , V_132 ) ;
V_28 -> V_131 = V_132 ;
V_28 -> V_109 = V_28 -> V_97 -> V_137 [ V_132 ] . V_139 ;
if ( V_136 -> V_140 == V_141 )
V_133 = V_28 -> V_142 ;
V_28 -> V_31 [ V_143 ] . V_144 . V_145 = V_133 ;
V_28 -> V_31 [ V_41 ] . V_144 . V_145 = V_133 ;
V_28 -> V_31 [ V_146 ] . V_144 . V_145 = V_133 ;
F_44 ( V_28 ) ;
F_45 ( V_28 ) ;
F_34 ( V_28 ) ;
F_46 ( V_28 ) ;
return 0 ;
}
static int F_47 ( struct V_22 * V_22 , void * V_23 ,
struct V_147 * V_148 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_148 -> V_149 != 0 )
return - V_66 ;
F_48 ( V_28 , V_149 , V_150 , V_148 ) ;
return 0 ;
}
int F_49 ( struct V_22 * V_22 , void * V_23 , const struct V_147 * V_148 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_148 -> V_149 != 0 )
return - V_66 ;
F_44 ( V_28 ) ;
F_43 ( L_7 , V_148 -> V_151 ) ;
F_48 ( V_28 , V_149 , V_152 , V_148 ) ;
F_46 ( V_28 ) ;
return 0 ;
}
static int F_50 ( struct V_22 * V_22 , void * V_23 , T_2 * V_133 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_133 = V_28 -> V_133 ;
return 0 ;
}
int F_51 ( struct V_22 * V_22 , void * V_23 , T_2 V_133 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( ( V_133 & V_134 ) == 0 )
return - V_66 ;
if ( V_133 == V_28 -> V_133 )
return 0 ;
if ( F_52 ( V_153 , & V_28 -> V_154 ) ||
F_18 ( & V_28 -> V_74 ) > 0 ) {
return - V_75 ;
}
V_28 -> V_133 = V_133 ;
V_28 -> V_155 = ( V_133 & V_156 ) ? 1 : 0 ;
V_28 -> V_70 = ! V_28 -> V_155 ;
F_53 ( & V_28 -> V_36 , V_28 -> V_70 ) ;
V_28 -> V_36 . V_35 = 720 ;
V_28 -> V_36 . V_37 = V_28 -> V_70 ? 576 : 480 ;
V_28 -> V_50 . V_58 = V_28 -> V_70 ? 18 : 12 ;
V_28 -> V_50 . V_57 [ 0 ] = V_28 -> V_70 ? 6 : 10 ;
V_28 -> V_50 . V_57 [ 1 ] = V_28 -> V_70 ? 318 : 273 ;
F_43 ( L_8 ,
( unsigned long long ) V_28 -> V_133 ) ;
F_48 ( V_28 , V_79 , V_157 , V_28 -> V_133 ) ;
return 0 ;
}
static int F_54 ( struct V_22 * V_22 , void * V_23 , const struct V_158 * V_159 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_159 -> V_108 != 0 )
return - V_66 ;
F_48 ( V_28 , V_149 , V_160 , V_159 ) ;
return 0 ;
}
static int F_55 ( struct V_22 * V_22 , void * V_23 , struct V_158 * V_159 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_159 -> V_108 != 0 )
return - V_66 ;
F_48 ( V_28 , V_149 , V_161 , V_159 ) ;
if ( V_159 -> type == V_162 )
F_28 ( V_159 -> V_163 , L_9 , sizeof( V_159 -> V_163 ) ) ;
else
F_28 ( V_159 -> V_163 , L_10 , sizeof( V_159 -> V_163 ) ) ;
return 0 ;
}
static int F_56 ( struct V_22 * V_22 , void * V_23 ,
struct V_164 * V_165 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
int V_11 = V_28 -> V_70 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_165 -> type != V_86 )
return - V_66 ;
V_165 -> V_18 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_28 -> V_70 ) ) {
V_165 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
V_165 -> V_18 |= V_11 ;
} else
V_165 -> V_21 [ V_19 ] [ V_20 ] = 0 ;
}
}
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_165 -> V_60 [ V_19 ] = 0 ;
return 0 ;
}
static int F_57 ( struct V_166 * V_167 ,
struct V_168 * V_169 )
{
int V_170 , V_171 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
const int V_176 [ 8 ] = {
- 1 , V_177 , V_178 ,
- 1 , V_179 , - 1 , - 1 , - 1
} ;
V_171 = V_167 -> V_180 - V_167 -> V_181 ;
V_170 = 0 ;
V_173 = & V_169 -> V_182 [ V_169 -> V_183 ] ;
V_175 = (struct V_174 * ) & V_167 -> V_167 [ V_167 -> V_181 ] ;
while ( V_171 >= sizeof( struct V_174 ) &&
V_169 -> V_183 < V_184 ) {
V_173 -> V_52 = ( ( ( V_185 ) F_58 ( V_175 -> V_186 ) ) << 32 )
| F_58 ( V_175 -> V_187 ) ;
V_173 -> V_188 = ( ( ( V_185 ) ( F_58 ( V_175 -> V_189 ) & 1 ) ) << 32 )
| F_58 ( V_175 -> V_190 ) ;
V_173 -> V_191 = F_58 ( V_175 -> V_191 ) ;
V_173 -> V_59 = V_176 [ F_58 ( V_175 -> V_59 ) & 0x7 ] ;
V_173 -> V_60 [ 0 ] = 0 ;
V_173 -> V_60 [ 1 ] = 0 ;
V_169 -> V_183 ++ ;
V_173 = & V_169 -> V_182 [ V_169 -> V_183 ] ;
V_175 ++ ;
V_171 -= sizeof( struct V_174 ) ;
V_170 += sizeof( struct V_174 ) ;
}
if ( V_171 > 0 && V_171 < sizeof( struct V_174 ) )
V_170 += V_171 ;
V_167 -> V_181 += V_170 ;
return V_170 ;
}
static int F_59 ( struct V_29 * V_30 , struct V_192 * V_193 ,
struct V_168 * V_169 )
{
if ( V_30 -> type != V_194 )
return - V_66 ;
if ( V_193 -> V_195 == NULL )
V_193 -> V_195 = F_60 ( & V_193 -> V_196 ,
struct V_166 , V_197 ) ;
if ( F_61 ( V_193 -> V_195 , & V_193 -> V_196 , V_197 ) ) {
V_193 -> V_181 = V_193 -> V_180 ;
return 0 ;
}
F_62 (mdl->curr_buf, &mdl->buf_list, list) {
if ( V_193 -> V_195 -> V_181 >= V_193 -> V_195 -> V_180 )
continue;
V_193 -> V_181 += F_57 ( V_193 -> V_195 , V_169 ) ;
if ( V_169 -> V_183 >= V_184 ||
V_193 -> V_195 -> V_181 < V_193 -> V_195 -> V_180 ||
V_193 -> V_181 >= V_193 -> V_180 )
break;
}
return 0 ;
}
static int F_63 ( struct V_22 * V_22 , void * V_23 ,
struct V_168 * V_169 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_194 ] ;
T_3 V_198 ;
struct V_192 * V_193 ;
if ( ! F_64 ( V_30 ) )
return - V_66 ;
V_198 = V_30 -> V_199 -
V_30 -> V_200 * V_201 ;
if ( V_198 <= 0 )
V_198 = 1 ;
V_198 = V_198 * V_30 -> V_202 / sizeof( struct V_174 ) ;
V_169 -> V_183 = 0 ;
V_169 -> V_203 = V_198 ;
memset ( V_169 -> V_60 , 0 , sizeof( V_169 -> V_60 ) ) ;
do {
V_193 = F_65 ( V_30 , & V_30 -> V_204 ) ;
if ( V_193 == NULL )
break;
F_59 ( V_30 , V_193 , V_169 ) ;
if ( V_193 -> V_181 < V_193 -> V_180 ) {
F_66 ( V_30 , V_193 , & V_30 -> V_204 ) ;
break;
}
F_67 ( V_30 , V_193 , & V_30 -> V_205 ) ;
} while ( V_169 -> V_183 < V_184 );
F_68 ( V_30 ) ;
return 0 ;
}
static struct V_206 * F_69 ( struct V_25 * V_26 )
{
struct V_206 * V_207 = NULL ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
switch ( V_30 -> V_208 ) {
case V_115 :
V_207 = & V_30 -> V_209 ;
break;
case V_84 :
break;
default:
break;
}
return V_207 ;
}
static int F_70 ( struct V_22 * V_22 , void * V_210 ,
enum V_211 type )
{
struct V_25 * V_26 = V_22 -> V_212 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_208 != V_115 ) &&
( V_30 -> V_208 != V_84 ) )
return - V_66 ;
if ( V_26 -> type != V_41 )
return - V_66 ;
F_71 ( & V_30 -> V_213 , F_72 ( 2000 ) + V_214 ) ;
return F_73 ( F_69 ( V_26 ) ) ;
}
static int F_74 ( struct V_22 * V_22 , void * V_210 ,
enum V_211 type )
{
struct V_25 * V_26 = V_22 -> V_212 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_208 != V_115 ) &&
( V_30 -> V_208 != V_84 ) )
return - V_66 ;
if ( V_26 -> type != V_41 )
return - V_66 ;
return F_75 ( F_69 ( V_26 ) ) ;
}
static int F_76 ( struct V_22 * V_22 , void * V_210 ,
struct V_215 * V_216 )
{
struct V_25 * V_26 = V_22 -> V_212 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_208 != V_115 ) &&
( V_30 -> V_208 != V_84 ) )
return - V_66 ;
return F_77 ( F_69 ( V_26 ) , V_216 ) ;
}
static int F_78 ( struct V_22 * V_22 , void * V_210 ,
struct V_217 * V_218 )
{
struct V_25 * V_26 = V_22 -> V_212 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_208 != V_115 ) &&
( V_30 -> V_208 != V_84 ) )
return - V_66 ;
return F_79 ( F_69 ( V_26 ) , V_218 ) ;
}
static int F_80 ( struct V_22 * V_22 , void * V_210 , struct V_217 * V_218 )
{
struct V_25 * V_26 = V_22 -> V_212 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_208 != V_115 ) &&
( V_30 -> V_208 != V_84 ) )
return - V_66 ;
return F_81 ( F_69 ( V_26 ) , V_218 ) ;
}
static int F_82 ( struct V_22 * V_22 , void * V_210 , struct V_217 * V_218 )
{
struct V_25 * V_26 = V_22 -> V_212 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_208 != V_115 ) &&
( V_30 -> V_208 != V_84 ) )
return - V_66 ;
return F_83 ( F_69 ( V_26 ) , V_218 , V_22 -> V_219 & V_220 ) ;
}
static int F_84 ( struct V_22 * V_22 , void * V_23 ,
struct V_221 * V_222 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
T_4 V_68 ;
switch ( V_222 -> V_223 ) {
case V_224 :
F_85 ( L_11 ) ;
V_222 -> V_59 = 0 ;
return F_86 ( V_26 ) ;
case V_225 :
F_85 ( L_12 ) ;
V_222 -> V_59 &= V_226 ;
F_87 ( V_26 ,
V_222 -> V_59 & V_226 ) ;
break;
case V_227 :
F_85 ( L_13 ) ;
V_222 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_74 ) )
return - V_228 ;
if ( F_88 ( V_229 , & V_28 -> V_154 ) )
return 0 ;
V_68 = F_89 ( V_28 ) ;
if ( V_68 == V_230 ) {
F_90 ( L_14
L_13 ) ;
return - V_231 ;
}
F_44 ( V_28 ) ;
F_91 ( V_28 , V_232 , 1 , V_68 ) ;
break;
case V_233 :
F_85 ( L_15 ) ;
V_222 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_74 ) )
return - V_228 ;
if ( ! F_92 ( V_229 , & V_28 -> V_154 ) )
return 0 ;
V_68 = F_89 ( V_28 ) ;
if ( V_68 == V_230 ) {
F_90 ( L_14
L_15 ) ;
return - V_231 ;
}
F_91 ( V_28 , V_234 , 1 , V_68 ) ;
F_46 ( V_28 ) ;
break;
default:
F_85 ( L_16 , V_222 -> V_223 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_93 ( struct V_22 * V_22 , void * V_23 ,
struct V_221 * V_222 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_222 -> V_223 ) {
case V_224 :
F_85 ( L_11 ) ;
V_222 -> V_59 = 0 ;
break;
case V_225 :
F_85 ( L_12 ) ;
V_222 -> V_59 &= V_226 ;
break;
case V_227 :
F_85 ( L_13 ) ;
V_222 -> V_59 = 0 ;
break;
case V_233 :
F_85 ( L_15 ) ;
V_222 -> V_59 = 0 ;
break;
default:
F_85 ( L_16 , V_222 -> V_223 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_94 ( struct V_22 * V_22 , void * V_23 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_112 V_235 ;
struct V_106 V_236 ;
int V_15 ;
F_95 ( L_17 , V_237 , V_28 -> V_98 ) ;
if ( V_28 -> V_238 & V_239 ) {
struct V_240 V_241 ;
F_96 ( V_28 , & V_241 ) ;
}
F_48 ( V_28 , V_242 , V_243 ) ;
F_36 ( V_28 , V_28 -> V_131 , & V_235 ) ;
F_31 ( V_28 , V_28 -> V_109 , & V_236 ) ;
F_95 ( L_18 , V_235 . V_163 ) ;
F_95 ( L_19 , V_236 . V_163 ) ;
F_97 ( & V_28 -> V_244 ) ;
F_95 ( L_20 ,
V_28 -> V_245 , V_28 -> V_246 ) ;
F_98 ( & V_28 -> V_244 ) ;
F_95 ( L_21 ,
F_52 ( V_153 , & V_28 -> V_154 ) ? L_22 : L_23 ) ;
F_99 ( & V_28 -> V_36 . V_247 , V_28 -> V_248 . V_163 ) ;
F_95 ( L_24 , V_28 -> V_154 ) ;
for ( V_15 = 0 ; V_15 < V_249 ; V_15 ++ ) {
struct V_29 * V_30 = & V_28 -> V_31 [ V_15 ] ;
if ( V_30 -> V_144 . V_248 == NULL || V_30 -> V_199 == 0 )
continue;
F_95 ( L_25 ,
V_30 -> V_163 , V_30 -> V_250 ,
F_18 ( & V_30 -> V_204 . V_251 ) * V_30 -> V_200 * 100
/ V_30 -> V_199 ,
( V_30 -> V_199 * V_30 -> V_202 ) / 1024 , V_30 -> V_199 ) ;
}
F_95 ( L_26 ,
( long long ) V_28 -> V_252 ,
( long long ) V_28 -> V_253 ) ;
return 0 ;
}
static long F_100 ( struct V_22 * V_22 , void * V_23 , bool V_254 ,
unsigned int V_223 , void * V_255 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_223 ) {
case V_256 : {
T_4 V_92 = * ( T_4 * ) V_255 ;
if ( ( V_92 == 0 ) || ( V_92 & 0x01 ) )
F_101 ( V_28 , V_257 , V_242 , V_258 ,
( T_4 ) V_259 ) ;
break;
}
default:
return - V_260 ;
}
return 0 ;
}
void F_102 ( struct V_261 * V_262 )
{
V_262 -> V_263 = & V_264 ;
}
