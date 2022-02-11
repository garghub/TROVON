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
V_33 -> V_45 = 720 ;
} else {
V_33 -> V_42 = V_46 ;
V_33 -> V_43 = 128 * 1024 ;
V_33 -> V_45 = 0 ;
}
return 0 ;
}
static int F_9 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_47 * V_48 = & V_17 -> V_17 . V_49 ;
V_48 -> V_50 = 27000000 ;
V_48 -> V_51 = 248 ;
V_48 -> V_52 = V_53 - 4 ;
V_48 -> V_54 = V_55 ;
V_48 -> V_56 [ 0 ] = V_28 -> V_49 . V_56 [ 0 ] ;
V_48 -> V_56 [ 1 ] = V_28 -> V_49 . V_56 [ 1 ] ;
V_48 -> V_57 [ 0 ] = V_48 -> V_57 [ 1 ] = V_28 -> V_49 . V_57 ;
V_48 -> V_58 = 0 ;
V_48 -> V_59 [ 0 ] = 0 ;
V_48 -> V_59 [ 1 ] = 0 ;
return 0 ;
}
static int F_10 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_16 * V_48 = & V_17 -> V_17 . V_60 ;
V_48 -> V_59 [ 0 ] = 0 ;
V_48 -> V_59 [ 1 ] = 0 ;
V_48 -> V_61 = sizeof( struct V_62 ) * 36 ;
memset ( V_48 -> V_21 , 0 , sizeof( V_48 -> V_21 ) ) ;
V_48 -> V_18 = 0 ;
if ( F_11 ( V_28 -> V_63 , V_49 , V_64 , & V_17 -> V_17 . V_60 ) )
return - V_65 ;
V_48 -> V_18 = F_6 ( V_48 ) ;
return 0 ;
}
static int F_12 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
int V_66 = V_17 -> V_17 . V_34 . V_35 ;
int V_67 = V_17 -> V_17 . V_34 . V_37 ;
int V_68 = 2 ;
V_66 = F_13 ( V_66 , 720 ) ;
V_66 = F_14 ( V_66 , 2 ) ;
if ( V_26 -> type == V_41 ) {
V_67 &= ~ 0x1f ;
V_68 = 32 ;
}
V_67 = F_13 ( V_67 , V_28 -> V_69 ? 576 : 480 ) ;
V_67 = F_14 ( V_67 , V_68 ) ;
V_17 -> V_17 . V_34 . V_35 = V_66 ;
V_17 -> V_17 . V_34 . V_37 = V_67 ;
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
struct V_16 * V_48 = & V_17 -> V_17 . V_60 ;
V_48 -> V_61 = sizeof( struct V_62 ) * 36 ;
V_48 -> V_59 [ 0 ] = 0 ;
V_48 -> V_59 [ 1 ] = 0 ;
if ( V_48 -> V_18 )
F_4 ( V_48 , V_28 -> V_69 ) ;
if ( F_5 ( V_48 , V_28 -> V_69 ) )
V_48 -> V_18 = F_6 ( V_48 ) ;
return 0 ;
}
static int F_17 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_70 V_71 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
int V_72 ;
int V_66 , V_67 ;
V_72 = F_12 ( V_22 , V_23 , V_17 ) ;
if ( V_72 )
return V_72 ;
V_66 = V_17 -> V_17 . V_34 . V_35 ;
V_67 = V_17 -> V_17 . V_34 . V_37 ;
if ( V_28 -> V_36 . V_35 == V_66 && V_28 -> V_36 . V_37 == V_67 &&
V_30 -> V_42 == V_17 -> V_17 . V_34 . V_42 )
return 0 ;
if ( F_18 ( & V_28 -> V_73 ) > 0 )
return - V_74 ;
V_30 -> V_42 = V_17 -> V_17 . V_34 . V_42 ;
if ( V_30 -> V_42 == V_75 )
V_30 -> V_44 = V_67 * 720 * 3 / 2 ;
else
V_30 -> V_44 = V_67 * 720 * 2 ;
V_71 . V_35 = V_28 -> V_36 . V_35 = V_66 ;
V_71 . V_37 = V_28 -> V_36 . V_37 = V_67 ;
V_71 . V_76 = V_77 ;
F_11 ( V_28 -> V_63 , V_78 , V_79 , & V_71 ) ;
return F_7 ( V_22 , V_23 , V_17 ) ;
}
static int F_19 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
int V_72 ;
if ( ! F_20 ( V_28 ) && F_18 ( & V_28 -> V_73 ) > 0 )
return - V_74 ;
V_72 = F_11 ( V_28 -> V_63 , V_49 , V_80 , & V_17 -> V_17 . V_49 ) ;
if ( V_72 )
return V_72 ;
V_28 -> V_49 . V_81 -> V_18 = 0 ;
V_28 -> V_49 . V_82 . type = V_83 ;
return F_9 ( V_22 , V_23 , V_17 ) ;
}
static int F_21 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_17 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
int V_72 ;
struct V_16 * V_48 = & V_17 -> V_17 . V_60 ;
F_16 ( V_22 , V_23 , V_17 ) ;
if ( F_20 ( V_28 ) && F_18 ( & V_28 -> V_73 ) > 0 )
return - V_74 ;
V_72 = F_11 ( V_28 -> V_63 , V_49 , V_84 , & V_17 -> V_17 . V_60 ) ;
if ( V_72 )
return V_72 ;
V_28 -> V_49 . V_82 . type = V_85 ;
memcpy ( V_28 -> V_49 . V_81 , V_48 , sizeof( * V_28 -> V_49 . V_81 ) ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_22 , void * V_23 ,
struct V_86 * V_87 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_87 -> V_87 & 0x3 )
return - V_65 ;
if ( V_87 -> V_87 >= V_88 + V_89 )
return - V_65 ;
V_87 -> V_90 = 4 ;
V_87 -> V_91 = F_23 ( V_28 , V_87 -> V_87 ) ;
return 0 ;
}
static int F_24 ( struct V_22 * V_22 , void * V_23 ,
const struct V_86 * V_87 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_87 -> V_87 & 0x3 )
return - V_65 ;
if ( V_87 -> V_87 >= V_88 + V_89 )
return - V_65 ;
F_25 ( V_28 , V_87 -> V_91 , V_87 -> V_87 ) ;
return 0 ;
}
static int F_26 ( struct V_22 * V_22 , void * V_23 ,
struct V_92 * V_93 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
F_27 ( V_93 -> V_94 , V_95 , sizeof( V_93 -> V_94 ) ) ;
F_27 ( V_93 -> V_96 , V_28 -> V_97 , sizeof( V_93 -> V_96 ) ) ;
snprintf ( V_93 -> V_98 , sizeof( V_93 -> V_98 ) ,
L_1 , F_28 ( V_28 -> V_99 ) ) ;
V_93 -> V_100 = V_28 -> V_101 ;
if ( V_26 -> type == V_41 )
V_93 -> V_100 |= V_102 ;
return 0 ;
}
static int F_29 ( struct V_22 * V_22 , void * V_23 , struct V_103 * V_104 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_30 ( V_28 , V_104 -> V_105 , V_104 ) ;
}
static int F_31 ( struct V_22 * V_22 , void * V_23 , struct V_103 * V_104 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
V_104 -> V_105 = V_28 -> V_106 ;
return F_30 ( V_28 , V_104 -> V_105 , V_104 ) ;
}
static int F_32 ( struct V_22 * V_22 , void * V_23 , const struct V_103 * V_107 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_107 -> V_105 >= V_28 -> V_108 )
return - V_65 ;
V_28 -> V_106 = V_107 -> V_105 ;
F_33 ( V_28 ) ;
return 0 ;
}
static int F_34 ( struct V_22 * V_22 , void * V_23 , struct V_109 * V_104 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_35 ( V_28 , V_104 -> V_105 , V_104 ) ;
}
static int F_36 ( struct V_22 * V_22 , void * V_23 ,
struct V_110 * V_111 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_111 -> type != V_112 )
return - V_65 ;
V_111 -> V_113 . V_114 = V_111 -> V_113 . V_115 = 0 ;
V_111 -> V_113 . V_35 = 720 ;
V_111 -> V_113 . V_37 = V_28 -> V_69 ? 576 : 480 ;
V_111 -> V_116 . V_117 = V_28 -> V_69 ? 59 : 10 ;
V_111 -> V_116 . V_118 = V_28 -> V_69 ? 54 : 11 ;
V_111 -> V_119 = V_111 -> V_113 ;
return 0 ;
}
static int F_37 ( struct V_22 * V_22 , void * V_23 , const struct V_120 * V_121 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_121 -> type != V_112 )
return - V_65 ;
F_38 ( L_2 ) ;
return - V_65 ;
}
static int F_39 ( struct V_22 * V_22 , void * V_23 , struct V_120 * V_121 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_121 -> type != V_112 )
return - V_65 ;
F_38 ( L_3 ) ;
return - V_65 ;
}
static int F_40 ( struct V_22 * V_22 , void * V_23 ,
struct V_122 * V_17 )
{
static const struct V_122 V_123 [] = {
{ 0 , V_112 , 0 ,
L_4 , V_75 , { 0 , 0 , 0 , 0 }
} ,
{ 1 , V_112 , V_124 ,
L_5 , V_46 , { 0 , 0 , 0 , 0 }
} ,
{ 2 , V_112 , 0 ,
L_6 , V_125 , { 0 , 0 , 0 , 0 }
} ,
} ;
if ( V_17 -> V_105 > F_41 ( V_123 ) - 1 )
return - V_65 ;
* V_17 = V_123 [ V_17 -> V_105 ] ;
return 0 ;
}
static int F_42 ( struct V_22 * V_22 , void * V_23 , unsigned int * V_15 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_15 = V_28 -> V_126 ;
return 0 ;
}
int F_43 ( struct V_22 * V_22 , void * V_23 , unsigned int V_127 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_127 >= V_28 -> V_128 )
return - V_65 ;
if ( V_127 == V_28 -> V_126 ) {
F_44 ( L_7 ) ;
return 0 ;
}
F_44 ( L_8 ,
V_28 -> V_126 , V_127 ) ;
V_28 -> V_126 = V_127 ;
V_28 -> V_106 = V_28 -> V_96 -> V_129 [ V_127 ] . V_130 ;
F_45 ( V_28 ) ;
F_46 ( V_28 ) ;
F_33 ( V_28 ) ;
F_47 ( V_28 ) ;
return 0 ;
}
static int F_48 ( struct V_22 * V_22 , void * V_23 ,
struct V_131 * V_132 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_132 -> V_133 != 0 )
return - V_65 ;
F_49 ( V_28 , V_133 , V_134 , V_132 ) ;
return 0 ;
}
int F_50 ( struct V_22 * V_22 , void * V_23 , const struct V_131 * V_132 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_132 -> V_133 != 0 )
return - V_65 ;
F_45 ( V_28 ) ;
F_44 ( L_9 , V_132 -> V_135 ) ;
F_49 ( V_28 , V_133 , V_136 , V_132 ) ;
F_47 ( V_28 ) ;
return 0 ;
}
static int F_51 ( struct V_22 * V_22 , void * V_23 , T_2 * V_137 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_137 = V_28 -> V_137 ;
return 0 ;
}
int F_52 ( struct V_22 * V_22 , void * V_23 , T_2 V_137 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( ( V_137 & V_138 ) == 0 )
return - V_65 ;
if ( V_137 == V_28 -> V_137 )
return 0 ;
if ( F_53 ( V_139 , & V_28 -> V_140 ) ||
F_18 ( & V_28 -> V_73 ) > 0 ) {
return - V_74 ;
}
V_28 -> V_137 = V_137 ;
V_28 -> V_141 = ( V_137 & V_142 ) ? 1 : 0 ;
V_28 -> V_69 = ! V_28 -> V_141 ;
F_54 ( & V_28 -> V_36 , V_28 -> V_69 ) ;
V_28 -> V_36 . V_35 = 720 ;
V_28 -> V_36 . V_37 = V_28 -> V_69 ? 576 : 480 ;
V_28 -> V_49 . V_57 = V_28 -> V_69 ? 18 : 12 ;
V_28 -> V_49 . V_56 [ 0 ] = V_28 -> V_69 ? 6 : 10 ;
V_28 -> V_49 . V_56 [ 1 ] = V_28 -> V_69 ? 318 : 273 ;
F_44 ( L_10 ,
( unsigned long long ) V_28 -> V_137 ) ;
F_49 ( V_28 , V_78 , V_143 , V_28 -> V_137 ) ;
return 0 ;
}
static int F_55 ( struct V_22 * V_22 , void * V_23 , const struct V_144 * V_145 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_145 -> V_105 != 0 )
return - V_65 ;
F_49 ( V_28 , V_133 , V_146 , V_145 ) ;
return 0 ;
}
static int F_56 ( struct V_22 * V_22 , void * V_23 , struct V_144 * V_145 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_145 -> V_105 != 0 )
return - V_65 ;
F_49 ( V_28 , V_133 , V_147 , V_145 ) ;
if ( V_145 -> type == V_148 )
F_27 ( V_145 -> V_149 , L_11 , sizeof( V_145 -> V_149 ) ) ;
else
F_27 ( V_145 -> V_149 , L_12 , sizeof( V_145 -> V_149 ) ) ;
return 0 ;
}
static int F_57 ( struct V_22 * V_22 , void * V_23 ,
struct V_150 * V_151 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
int V_11 = V_28 -> V_69 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_151 -> type != V_85 )
return - V_65 ;
V_151 -> V_18 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_28 -> V_69 ) ) {
V_151 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
V_151 -> V_18 |= V_11 ;
} else
V_151 -> V_21 [ V_19 ] [ V_20 ] = 0 ;
}
}
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_151 -> V_59 [ V_19 ] = 0 ;
return 0 ;
}
static int F_58 ( struct V_152 * V_153 ,
struct V_154 * V_155 )
{
int V_156 , V_157 ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
const int V_162 [ 8 ] = {
- 1 , V_163 , V_164 ,
- 1 , V_165 , - 1 , - 1 , - 1
} ;
V_157 = V_153 -> V_166 - V_153 -> V_167 ;
V_156 = 0 ;
V_159 = & V_155 -> V_168 [ V_155 -> V_169 ] ;
V_161 = (struct V_160 * ) & V_153 -> V_153 [ V_153 -> V_167 ] ;
while ( V_157 >= sizeof( struct V_160 ) &&
V_155 -> V_169 < V_170 ) {
V_159 -> V_51 = ( ( ( V_171 ) F_59 ( V_161 -> V_172 ) ) << 32 )
| F_59 ( V_161 -> V_173 ) ;
V_159 -> V_174 = ( ( ( V_171 ) ( F_59 ( V_161 -> V_175 ) & 1 ) ) << 32 )
| F_59 ( V_161 -> V_176 ) ;
V_159 -> V_177 = F_59 ( V_161 -> V_177 ) ;
V_159 -> V_58 = V_162 [ F_59 ( V_161 -> V_58 ) & 0x7 ] ;
V_159 -> V_59 [ 0 ] = 0 ;
V_159 -> V_59 [ 1 ] = 0 ;
V_155 -> V_169 ++ ;
V_159 = & V_155 -> V_168 [ V_155 -> V_169 ] ;
V_161 ++ ;
V_157 -= sizeof( struct V_160 ) ;
V_156 += sizeof( struct V_160 ) ;
}
if ( V_157 > 0 && V_157 < sizeof( struct V_160 ) )
V_156 += V_157 ;
V_153 -> V_167 += V_156 ;
return V_156 ;
}
static int F_60 ( struct V_29 * V_30 , struct V_178 * V_179 ,
struct V_154 * V_155 )
{
if ( V_30 -> type != V_180 )
return - V_65 ;
if ( V_179 -> V_181 == NULL )
V_179 -> V_181 = F_61 ( & V_179 -> V_182 ,
struct V_152 , V_183 ) ;
if ( F_62 ( V_179 -> V_181 , & V_179 -> V_182 , V_183 ) ) {
V_179 -> V_167 = V_179 -> V_166 ;
return 0 ;
}
F_63 (mdl->curr_buf, &mdl->buf_list, list) {
if ( V_179 -> V_181 -> V_167 >= V_179 -> V_181 -> V_166 )
continue;
V_179 -> V_167 += F_58 ( V_179 -> V_181 , V_155 ) ;
if ( V_155 -> V_169 >= V_170 ||
V_179 -> V_181 -> V_167 < V_179 -> V_181 -> V_166 ||
V_179 -> V_167 >= V_179 -> V_166 )
break;
}
return 0 ;
}
static int F_64 ( struct V_22 * V_22 , void * V_23 ,
struct V_154 * V_155 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_180 ] ;
T_3 V_184 ;
struct V_178 * V_179 ;
if ( ! F_65 ( V_30 ) )
return - V_65 ;
V_184 = V_30 -> V_185 -
V_30 -> V_186 * V_187 ;
if ( V_184 <= 0 )
V_184 = 1 ;
V_184 = V_184 * V_30 -> V_188 / sizeof( struct V_160 ) ;
V_155 -> V_169 = 0 ;
V_155 -> V_189 = V_184 ;
memset ( V_155 -> V_59 , 0 , sizeof( V_155 -> V_59 ) ) ;
do {
V_179 = F_66 ( V_30 , & V_30 -> V_190 ) ;
if ( V_179 == NULL )
break;
F_60 ( V_30 , V_179 , V_155 ) ;
if ( V_179 -> V_167 < V_179 -> V_166 ) {
F_67 ( V_30 , V_179 , & V_30 -> V_190 ) ;
break;
}
F_68 ( V_30 , V_179 , & V_30 -> V_191 ) ;
} while ( V_155 -> V_169 < V_170 );
F_69 ( V_30 ) ;
return 0 ;
}
static struct V_192 * F_70 ( struct V_25 * V_26 )
{
struct V_192 * V_193 = NULL ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
switch ( V_30 -> V_194 ) {
case V_112 :
V_193 = & V_30 -> V_195 ;
break;
case V_83 :
break;
default:
break;
}
return V_193 ;
}
static int F_71 ( struct V_22 * V_22 , void * V_196 ,
enum V_197 type )
{
struct V_25 * V_26 = V_22 -> V_198 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_194 != V_112 ) &&
( V_30 -> V_194 != V_83 ) )
return - V_65 ;
if ( V_26 -> type != V_41 )
return - V_65 ;
F_72 ( & V_30 -> V_199 , F_73 ( 2000 ) + V_200 ) ;
return F_74 ( F_70 ( V_26 ) ) ;
}
static int F_75 ( struct V_22 * V_22 , void * V_196 ,
enum V_197 type )
{
struct V_25 * V_26 = V_22 -> V_198 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_194 != V_112 ) &&
( V_30 -> V_194 != V_83 ) )
return - V_65 ;
if ( V_26 -> type != V_41 )
return - V_65 ;
return F_76 ( F_70 ( V_26 ) ) ;
}
static int F_77 ( struct V_22 * V_22 , void * V_196 ,
struct V_201 * V_202 )
{
struct V_25 * V_26 = V_22 -> V_198 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_194 != V_112 ) &&
( V_30 -> V_194 != V_83 ) )
return - V_65 ;
return F_78 ( F_70 ( V_26 ) , V_202 ) ;
}
static int F_79 ( struct V_22 * V_22 , void * V_196 ,
struct V_203 * V_204 )
{
struct V_25 * V_26 = V_22 -> V_198 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_194 != V_112 ) &&
( V_30 -> V_194 != V_83 ) )
return - V_65 ;
return F_80 ( F_70 ( V_26 ) , V_204 ) ;
}
static int F_81 ( struct V_22 * V_22 , void * V_196 , struct V_203 * V_204 )
{
struct V_25 * V_26 = V_22 -> V_198 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_194 != V_112 ) &&
( V_30 -> V_194 != V_83 ) )
return - V_65 ;
return F_82 ( F_70 ( V_26 ) , V_204 ) ;
}
static int F_83 ( struct V_22 * V_22 , void * V_196 , struct V_203 * V_204 )
{
struct V_25 * V_26 = V_22 -> V_198 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_194 != V_112 ) &&
( V_30 -> V_194 != V_83 ) )
return - V_65 ;
return F_84 ( F_70 ( V_26 ) , V_204 , V_22 -> V_205 & V_206 ) ;
}
static int F_85 ( struct V_22 * V_22 , void * V_23 ,
struct V_207 * V_208 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
T_4 V_67 ;
switch ( V_208 -> V_209 ) {
case V_210 :
F_86 ( L_13 ) ;
V_208 -> V_58 = 0 ;
return F_87 ( V_26 ) ;
case V_211 :
F_86 ( L_14 ) ;
V_208 -> V_58 &= V_212 ;
F_88 ( V_26 ,
V_208 -> V_58 & V_212 ) ;
break;
case V_213 :
F_86 ( L_15 ) ;
V_208 -> V_58 = 0 ;
if ( ! F_18 ( & V_28 -> V_73 ) )
return - V_214 ;
if ( F_89 ( V_215 , & V_28 -> V_140 ) )
return 0 ;
V_67 = F_90 ( V_28 ) ;
if ( V_67 == V_216 ) {
F_91 ( L_16
L_15 ) ;
return - V_217 ;
}
F_45 ( V_28 ) ;
F_92 ( V_28 , V_218 , 1 , V_67 ) ;
break;
case V_219 :
F_86 ( L_17 ) ;
V_208 -> V_58 = 0 ;
if ( ! F_18 ( & V_28 -> V_73 ) )
return - V_214 ;
if ( ! F_93 ( V_215 , & V_28 -> V_140 ) )
return 0 ;
V_67 = F_90 ( V_28 ) ;
if ( V_67 == V_216 ) {
F_91 ( L_16
L_17 ) ;
return - V_217 ;
}
F_92 ( V_28 , V_220 , 1 , V_67 ) ;
F_47 ( V_28 ) ;
break;
default:
F_86 ( L_18 , V_208 -> V_209 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_94 ( struct V_22 * V_22 , void * V_23 ,
struct V_207 * V_208 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_208 -> V_209 ) {
case V_210 :
F_86 ( L_13 ) ;
V_208 -> V_58 = 0 ;
break;
case V_211 :
F_86 ( L_14 ) ;
V_208 -> V_58 &= V_212 ;
break;
case V_213 :
F_86 ( L_15 ) ;
V_208 -> V_58 = 0 ;
break;
case V_219 :
F_86 ( L_17 ) ;
V_208 -> V_58 = 0 ;
break;
default:
F_86 ( L_18 , V_208 -> V_209 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_95 ( struct V_22 * V_22 , void * V_23 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_109 V_221 ;
struct V_103 V_222 ;
int V_15 ;
F_96 ( L_19 , V_223 , V_28 -> V_97 ) ;
if ( V_28 -> V_224 & V_225 ) {
struct V_226 V_227 ;
F_97 ( V_28 , & V_227 ) ;
}
F_49 ( V_28 , V_228 , V_229 ) ;
F_35 ( V_28 , V_28 -> V_126 , & V_221 ) ;
F_30 ( V_28 , V_28 -> V_106 , & V_222 ) ;
F_96 ( L_20 , V_221 . V_149 ) ;
F_96 ( L_21 , V_222 . V_149 ) ;
F_98 ( & V_28 -> V_230 ) ;
F_96 ( L_22 ,
V_28 -> V_231 , V_28 -> V_232 ) ;
F_99 ( & V_28 -> V_230 ) ;
F_96 ( L_23 ,
F_53 ( V_139 , & V_28 -> V_140 ) ? L_24 : L_25 ) ;
F_100 ( & V_28 -> V_36 . V_233 , V_28 -> V_234 . V_149 ) ;
F_96 ( L_26 , V_28 -> V_140 ) ;
for ( V_15 = 0 ; V_15 < V_235 ; V_15 ++ ) {
struct V_29 * V_30 = & V_28 -> V_31 [ V_15 ] ;
if ( V_30 -> V_236 == NULL || V_30 -> V_185 == 0 )
continue;
F_96 ( L_27 ,
V_30 -> V_149 , V_30 -> V_237 ,
F_18 ( & V_30 -> V_190 . V_238 ) * V_30 -> V_186 * 100
/ V_30 -> V_185 ,
( V_30 -> V_185 * V_30 -> V_188 ) / 1024 , V_30 -> V_185 ) ;
}
F_96 ( L_28 ,
( long long ) V_28 -> V_239 ,
( long long ) V_28 -> V_240 ) ;
return 0 ;
}
static long F_101 ( struct V_22 * V_22 , void * V_23 , bool V_241 ,
unsigned int V_209 , void * V_242 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_209 ) {
case V_243 : {
T_4 V_91 = * ( T_4 * ) V_242 ;
if ( ( V_91 == 0 ) || ( V_91 & 0x01 ) )
F_102 ( V_28 , V_244 , V_228 , V_245 ,
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
