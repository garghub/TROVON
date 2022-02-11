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
struct V_27 * V_28 = V_26 -> V_28 ;
F_27 ( V_94 -> V_95 , V_96 , sizeof( V_94 -> V_95 ) ) ;
F_27 ( V_94 -> V_97 , V_28 -> V_98 , sizeof( V_94 -> V_97 ) ) ;
snprintf ( V_94 -> V_99 , sizeof( V_94 -> V_99 ) ,
L_1 , F_28 ( V_28 -> V_100 ) ) ;
V_94 -> V_101 = V_28 -> V_102 ;
if ( V_26 -> type == V_42 )
V_94 -> V_101 |= V_103 ;
return 0 ;
}
static int F_29 ( struct V_22 * V_22 , void * V_23 , struct V_104 * V_105 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_30 ( V_28 , V_105 -> V_106 , V_105 ) ;
}
static int F_31 ( struct V_22 * V_22 , void * V_23 , struct V_104 * V_105 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
V_105 -> V_106 = V_28 -> V_107 ;
return F_30 ( V_28 , V_105 -> V_106 , V_105 ) ;
}
static int F_32 ( struct V_22 * V_22 , void * V_23 , const struct V_104 * V_108 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_108 -> V_106 >= V_28 -> V_109 )
return - V_66 ;
V_28 -> V_107 = V_108 -> V_106 ;
F_33 ( V_28 ) ;
return 0 ;
}
static int F_34 ( struct V_22 * V_22 , void * V_23 , struct V_110 * V_105 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_35 ( V_28 , V_105 -> V_106 , V_105 ) ;
}
static int F_36 ( struct V_22 * V_22 , void * V_23 ,
struct V_111 * V_112 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_112 -> type != V_113 )
return - V_66 ;
V_112 -> V_114 . V_115 = V_112 -> V_114 . V_116 = 0 ;
V_112 -> V_114 . V_35 = 720 ;
V_112 -> V_114 . V_37 = V_28 -> V_70 ? 576 : 480 ;
V_112 -> V_117 . V_118 = V_28 -> V_70 ? 59 : 10 ;
V_112 -> V_117 . V_119 = V_28 -> V_70 ? 54 : 11 ;
V_112 -> V_120 = V_112 -> V_114 ;
return 0 ;
}
static int F_37 ( struct V_22 * V_22 , void * V_23 , const struct V_121 * V_122 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_122 -> type != V_113 )
return - V_66 ;
F_38 ( L_2 ) ;
return - V_66 ;
}
static int F_39 ( struct V_22 * V_22 , void * V_23 , struct V_121 * V_122 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_122 -> type != V_113 )
return - V_66 ;
F_38 ( L_3 ) ;
return - V_66 ;
}
static int F_40 ( struct V_22 * V_22 , void * V_23 ,
struct V_123 * V_17 )
{
static const struct V_123 V_124 [] = {
{ 0 , V_113 , 0 ,
L_4 , V_76 , { 0 , 0 , 0 , 0 }
} ,
{ 1 , V_113 , V_125 ,
L_5 , V_47 , { 0 , 0 , 0 , 0 }
} ,
{ 2 , V_113 , 0 ,
L_6 , V_126 , { 0 , 0 , 0 , 0 }
} ,
} ;
if ( V_17 -> V_106 > F_41 ( V_124 ) - 1 )
return - V_66 ;
* V_17 = V_124 [ V_17 -> V_106 ] ;
return 0 ;
}
static int F_42 ( struct V_22 * V_22 , void * V_23 , unsigned int * V_15 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_15 = V_28 -> V_127 ;
return 0 ;
}
int F_43 ( struct V_22 * V_22 , void * V_23 , unsigned int V_128 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_128 >= V_28 -> V_129 )
return - V_66 ;
if ( V_128 == V_28 -> V_127 ) {
F_44 ( L_7 ) ;
return 0 ;
}
F_44 ( L_8 ,
V_28 -> V_127 , V_128 ) ;
V_28 -> V_127 = V_128 ;
V_28 -> V_107 = V_28 -> V_97 -> V_130 [ V_128 ] . V_131 ;
F_45 ( V_28 ) ;
F_46 ( V_28 ) ;
F_33 ( V_28 ) ;
F_47 ( V_28 ) ;
return 0 ;
}
static int F_48 ( struct V_22 * V_22 , void * V_23 ,
struct V_132 * V_133 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_133 -> V_134 != 0 )
return - V_66 ;
F_49 ( V_28 , V_134 , V_135 , V_133 ) ;
return 0 ;
}
int F_50 ( struct V_22 * V_22 , void * V_23 , const struct V_132 * V_133 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_133 -> V_134 != 0 )
return - V_66 ;
F_45 ( V_28 ) ;
F_44 ( L_9 , V_133 -> V_136 ) ;
F_49 ( V_28 , V_134 , V_137 , V_133 ) ;
F_47 ( V_28 ) ;
return 0 ;
}
static int F_51 ( struct V_22 * V_22 , void * V_23 , T_2 * V_138 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_138 = V_28 -> V_138 ;
return 0 ;
}
int F_52 ( struct V_22 * V_22 , void * V_23 , T_2 V_138 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( ( V_138 & V_139 ) == 0 )
return - V_66 ;
if ( V_138 == V_28 -> V_138 )
return 0 ;
if ( F_53 ( V_140 , & V_28 -> V_141 ) ||
F_18 ( & V_28 -> V_74 ) > 0 ) {
return - V_75 ;
}
V_28 -> V_138 = V_138 ;
V_28 -> V_142 = ( V_138 & V_143 ) ? 1 : 0 ;
V_28 -> V_70 = ! V_28 -> V_142 ;
F_54 ( & V_28 -> V_36 , V_28 -> V_70 ) ;
V_28 -> V_36 . V_35 = 720 ;
V_28 -> V_36 . V_37 = V_28 -> V_70 ? 576 : 480 ;
V_28 -> V_50 . V_58 = V_28 -> V_70 ? 18 : 12 ;
V_28 -> V_50 . V_57 [ 0 ] = V_28 -> V_70 ? 6 : 10 ;
V_28 -> V_50 . V_57 [ 1 ] = V_28 -> V_70 ? 318 : 273 ;
F_44 ( L_10 ,
( unsigned long long ) V_28 -> V_138 ) ;
F_49 ( V_28 , V_144 , V_145 , V_28 -> V_138 ) ;
return 0 ;
}
static int F_55 ( struct V_22 * V_22 , void * V_23 , const struct V_146 * V_147 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_147 -> V_106 != 0 )
return - V_66 ;
F_49 ( V_28 , V_134 , V_148 , V_147 ) ;
return 0 ;
}
static int F_56 ( struct V_22 * V_22 , void * V_23 , struct V_146 * V_147 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_147 -> V_106 != 0 )
return - V_66 ;
F_49 ( V_28 , V_134 , V_149 , V_147 ) ;
if ( V_147 -> type == V_150 )
F_27 ( V_147 -> V_151 , L_11 , sizeof( V_147 -> V_151 ) ) ;
else
F_27 ( V_147 -> V_151 , L_12 , sizeof( V_147 -> V_151 ) ) ;
return 0 ;
}
static int F_57 ( struct V_22 * V_22 , void * V_23 ,
struct V_152 * V_153 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
int V_11 = V_28 -> V_70 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_153 -> type != V_86 )
return - V_66 ;
V_153 -> V_18 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_28 -> V_70 ) ) {
V_153 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
V_153 -> V_18 |= V_11 ;
} else
V_153 -> V_21 [ V_19 ] [ V_20 ] = 0 ;
}
}
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_153 -> V_60 [ V_19 ] = 0 ;
return 0 ;
}
static int F_58 ( struct V_154 * V_155 ,
struct V_156 * V_157 )
{
int V_158 , V_159 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
const int V_164 [ 8 ] = {
- 1 , V_165 , V_166 ,
- 1 , V_167 , - 1 , - 1 , - 1
} ;
V_159 = V_155 -> V_168 - V_155 -> V_169 ;
V_158 = 0 ;
V_161 = & V_157 -> V_170 [ V_157 -> V_171 ] ;
V_163 = (struct V_162 * ) & V_155 -> V_155 [ V_155 -> V_169 ] ;
while ( V_159 >= sizeof( struct V_162 ) &&
V_157 -> V_171 < V_172 ) {
V_161 -> V_52 = ( ( ( V_173 ) F_59 ( V_163 -> V_174 ) ) << 32 )
| F_59 ( V_163 -> V_175 ) ;
V_161 -> V_176 = ( ( ( V_173 ) ( F_59 ( V_163 -> V_177 ) & 1 ) ) << 32 )
| F_59 ( V_163 -> V_178 ) ;
V_161 -> V_179 = F_59 ( V_163 -> V_179 ) ;
V_161 -> V_59 = V_164 [ F_59 ( V_163 -> V_59 ) & 0x7 ] ;
V_161 -> V_60 [ 0 ] = 0 ;
V_161 -> V_60 [ 1 ] = 0 ;
V_157 -> V_171 ++ ;
V_161 = & V_157 -> V_170 [ V_157 -> V_171 ] ;
V_163 ++ ;
V_159 -= sizeof( struct V_162 ) ;
V_158 += sizeof( struct V_162 ) ;
}
if ( V_159 > 0 && V_159 < sizeof( struct V_162 ) )
V_158 += V_159 ;
V_155 -> V_169 += V_158 ;
return V_158 ;
}
static int F_60 ( struct V_29 * V_30 , struct V_180 * V_181 ,
struct V_156 * V_157 )
{
if ( V_30 -> type != V_182 )
return - V_66 ;
if ( V_181 -> V_183 == NULL )
V_181 -> V_183 = F_61 ( & V_181 -> V_184 ,
struct V_154 , V_185 ) ;
if ( F_62 ( V_181 -> V_183 , & V_181 -> V_184 , V_185 ) ) {
V_181 -> V_169 = V_181 -> V_168 ;
return 0 ;
}
F_63 (mdl->curr_buf, &mdl->buf_list, list) {
if ( V_181 -> V_183 -> V_169 >= V_181 -> V_183 -> V_168 )
continue;
V_181 -> V_169 += F_58 ( V_181 -> V_183 , V_157 ) ;
if ( V_157 -> V_171 >= V_172 ||
V_181 -> V_183 -> V_169 < V_181 -> V_183 -> V_168 ||
V_181 -> V_169 >= V_181 -> V_168 )
break;
}
return 0 ;
}
static int F_64 ( struct V_22 * V_22 , void * V_23 ,
struct V_156 * V_157 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_182 ] ;
T_3 V_186 ;
struct V_180 * V_181 ;
if ( ! F_65 ( V_30 ) )
return - V_66 ;
V_186 = V_30 -> V_187 -
V_30 -> V_188 * V_189 ;
if ( V_186 <= 0 )
V_186 = 1 ;
V_186 = V_186 * V_30 -> V_190 / sizeof( struct V_162 ) ;
V_157 -> V_171 = 0 ;
V_157 -> V_191 = V_186 ;
memset ( V_157 -> V_60 , 0 , sizeof( V_157 -> V_60 ) ) ;
do {
V_181 = F_66 ( V_30 , & V_30 -> V_192 ) ;
if ( V_181 == NULL )
break;
F_60 ( V_30 , V_181 , V_157 ) ;
if ( V_181 -> V_169 < V_181 -> V_168 ) {
F_67 ( V_30 , V_181 , & V_30 -> V_192 ) ;
break;
}
F_68 ( V_30 , V_181 , & V_30 -> V_193 ) ;
} while ( V_157 -> V_171 < V_172 );
F_69 ( V_30 ) ;
return 0 ;
}
static struct V_194 * F_70 ( struct V_25 * V_26 )
{
struct V_194 * V_195 = NULL ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
switch ( V_30 -> V_196 ) {
case V_113 :
V_195 = & V_30 -> V_197 ;
break;
case V_84 :
break;
default:
break;
}
return V_195 ;
}
static int F_71 ( struct V_22 * V_22 , void * V_41 ,
enum V_198 type )
{
struct V_25 * V_26 = V_22 -> V_199 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_113 ) &&
( V_30 -> V_196 != V_84 ) )
return - V_66 ;
if ( V_26 -> type != V_42 )
return - V_66 ;
F_72 ( & V_30 -> V_200 , F_73 ( 2000 ) + V_201 ) ;
return F_74 ( F_70 ( V_26 ) ) ;
}
static int F_75 ( struct V_22 * V_22 , void * V_41 ,
enum V_198 type )
{
struct V_25 * V_26 = V_22 -> V_199 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_113 ) &&
( V_30 -> V_196 != V_84 ) )
return - V_66 ;
if ( V_26 -> type != V_42 )
return - V_66 ;
return F_76 ( F_70 ( V_26 ) ) ;
}
static int F_77 ( struct V_22 * V_22 , void * V_41 ,
struct V_202 * V_203 )
{
struct V_25 * V_26 = V_22 -> V_199 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_113 ) &&
( V_30 -> V_196 != V_84 ) )
return - V_66 ;
return F_78 ( F_70 ( V_26 ) , V_203 ) ;
}
static int F_79 ( struct V_22 * V_22 , void * V_41 ,
struct V_204 * V_205 )
{
struct V_25 * V_26 = V_22 -> V_199 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_113 ) &&
( V_30 -> V_196 != V_84 ) )
return - V_66 ;
return F_80 ( F_70 ( V_26 ) , V_205 ) ;
}
static int F_81 ( struct V_22 * V_22 , void * V_41 , struct V_204 * V_205 )
{
struct V_25 * V_26 = V_22 -> V_199 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_113 ) &&
( V_30 -> V_196 != V_84 ) )
return - V_66 ;
return F_82 ( F_70 ( V_26 ) , V_205 ) ;
}
static int F_83 ( struct V_22 * V_22 , void * V_41 , struct V_204 * V_205 )
{
struct V_25 * V_26 = V_22 -> V_199 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_113 ) &&
( V_30 -> V_196 != V_84 ) )
return - V_66 ;
return F_84 ( F_70 ( V_26 ) , V_205 , V_22 -> V_206 & V_207 ) ;
}
static int F_85 ( struct V_22 * V_22 , void * V_23 ,
struct V_208 * V_209 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
T_4 V_68 ;
switch ( V_209 -> V_210 ) {
case V_211 :
F_86 ( L_13 ) ;
V_209 -> V_59 = 0 ;
return F_87 ( V_26 ) ;
case V_212 :
F_86 ( L_14 ) ;
V_209 -> V_59 &= V_213 ;
F_88 ( V_26 ,
V_209 -> V_59 & V_213 ) ;
break;
case V_214 :
F_86 ( L_15 ) ;
V_209 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_74 ) )
return - V_215 ;
if ( F_89 ( V_216 , & V_28 -> V_141 ) )
return 0 ;
V_68 = F_90 ( V_28 ) ;
if ( V_68 == V_217 ) {
F_91 ( L_16
L_15 ) ;
return - V_218 ;
}
F_45 ( V_28 ) ;
F_92 ( V_28 , V_219 , 1 , V_68 ) ;
break;
case V_220 :
F_86 ( L_17 ) ;
V_209 -> V_59 = 0 ;
if ( ! F_18 ( & V_28 -> V_74 ) )
return - V_215 ;
if ( ! F_93 ( V_216 , & V_28 -> V_141 ) )
return 0 ;
V_68 = F_90 ( V_28 ) ;
if ( V_68 == V_217 ) {
F_91 ( L_16
L_17 ) ;
return - V_218 ;
}
F_92 ( V_28 , V_221 , 1 , V_68 ) ;
F_47 ( V_28 ) ;
break;
default:
F_86 ( L_18 , V_209 -> V_210 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_94 ( struct V_22 * V_22 , void * V_23 ,
struct V_208 * V_209 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_209 -> V_210 ) {
case V_211 :
F_86 ( L_13 ) ;
V_209 -> V_59 = 0 ;
break;
case V_212 :
F_86 ( L_14 ) ;
V_209 -> V_59 &= V_213 ;
break;
case V_214 :
F_86 ( L_15 ) ;
V_209 -> V_59 = 0 ;
break;
case V_220 :
F_86 ( L_17 ) ;
V_209 -> V_59 = 0 ;
break;
default:
F_86 ( L_18 , V_209 -> V_210 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_95 ( struct V_22 * V_22 , void * V_23 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_110 V_222 ;
struct V_104 V_223 ;
int V_15 ;
F_96 ( L_19 , V_224 , V_28 -> V_98 ) ;
if ( V_28 -> V_225 & V_226 ) {
struct V_227 V_228 ;
F_97 ( V_28 , & V_228 ) ;
}
F_49 ( V_28 , V_144 , V_229 ) ;
F_35 ( V_28 , V_28 -> V_127 , & V_222 ) ;
F_30 ( V_28 , V_28 -> V_107 , & V_223 ) ;
F_96 ( L_20 , V_222 . V_151 ) ;
F_96 ( L_21 , V_223 . V_151 ) ;
F_98 ( & V_28 -> V_230 ) ;
F_96 ( L_22 ,
V_28 -> V_231 , V_28 -> V_232 ) ;
F_99 ( & V_28 -> V_230 ) ;
F_96 ( L_23 ,
F_53 ( V_140 , & V_28 -> V_141 ) ? L_24 : L_25 ) ;
F_100 ( & V_28 -> V_36 . V_233 , V_28 -> V_234 . V_151 ) ;
F_96 ( L_26 , V_28 -> V_141 ) ;
for ( V_15 = 0 ; V_15 < V_235 ; V_15 ++ ) {
struct V_29 * V_30 = & V_28 -> V_31 [ V_15 ] ;
if ( V_30 -> V_236 == NULL || V_30 -> V_187 == 0 )
continue;
F_96 ( L_27 ,
V_30 -> V_151 , V_30 -> V_237 ,
F_18 ( & V_30 -> V_192 . V_238 ) * V_30 -> V_188 * 100
/ V_30 -> V_187 ,
( V_30 -> V_187 * V_30 -> V_190 ) / 1024 , V_30 -> V_187 ) ;
}
F_96 ( L_28 ,
( long long ) V_28 -> V_239 ,
( long long ) V_28 -> V_240 ) ;
return 0 ;
}
static long F_101 ( struct V_22 * V_22 , void * V_23 , bool V_241 ,
unsigned int V_210 , void * V_242 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_210 ) {
case V_243 : {
T_4 V_92 = * ( T_4 * ) V_242 ;
if ( ( V_92 == 0 ) || ( V_92 & 0x01 ) )
F_102 ( V_28 , V_244 , V_144 , V_245 ,
( T_4 ) V_246 ) ;
break;
}
default:
return - V_247 ;
}
return 0 ;
}
void F_103 ( struct V_248 * V_249 )
{
V_249 -> V_250 = & V_251 ;
}
