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
struct V_29 * V_30 = F_27 ( V_22 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
F_28 ( V_93 -> V_94 , V_95 , sizeof( V_93 -> V_94 ) ) ;
F_28 ( V_93 -> V_96 , V_28 -> V_97 , sizeof( V_93 -> V_96 ) ) ;
snprintf ( V_93 -> V_98 , sizeof( V_93 -> V_98 ) ,
L_1 , F_29 ( V_28 -> V_99 ) ) ;
V_93 -> V_100 = V_28 -> V_101 ;
V_93 -> V_102 = V_30 -> V_103 ;
V_93 -> V_100 |= V_104 ;
return 0 ;
}
static int F_30 ( struct V_22 * V_22 , void * V_23 , struct V_105 * V_106 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_31 ( V_28 , V_106 -> V_107 , V_106 ) ;
}
static int F_32 ( struct V_22 * V_22 , void * V_23 , struct V_105 * V_106 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
V_106 -> V_107 = V_28 -> V_108 ;
return F_31 ( V_28 , V_106 -> V_107 , V_106 ) ;
}
static int F_33 ( struct V_22 * V_22 , void * V_23 , const struct V_105 * V_109 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_109 -> V_107 >= V_28 -> V_110 )
return - V_65 ;
V_28 -> V_108 = V_109 -> V_107 ;
F_34 ( V_28 ) ;
return 0 ;
}
static int F_35 ( struct V_22 * V_22 , void * V_23 , struct V_111 * V_106 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
return F_36 ( V_28 , V_106 -> V_107 , V_106 ) ;
}
static int F_37 ( struct V_22 * V_22 , void * V_23 ,
struct V_112 * V_113 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_113 -> type != V_114 )
return - V_65 ;
V_113 -> V_115 . V_116 = V_113 -> V_115 . V_117 = 0 ;
V_113 -> V_115 . V_35 = 720 ;
V_113 -> V_115 . V_37 = V_28 -> V_69 ? 576 : 480 ;
V_113 -> V_118 . V_119 = V_28 -> V_69 ? 59 : 10 ;
V_113 -> V_118 . V_120 = V_28 -> V_69 ? 54 : 11 ;
V_113 -> V_121 = V_113 -> V_115 ;
return 0 ;
}
static int F_38 ( struct V_22 * V_22 , void * V_23 , const struct V_122 * V_123 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_123 -> type != V_114 )
return - V_65 ;
F_39 ( L_2 ) ;
return - V_65 ;
}
static int F_40 ( struct V_22 * V_22 , void * V_23 , struct V_122 * V_123 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_123 -> type != V_114 )
return - V_65 ;
F_39 ( L_3 ) ;
return - V_65 ;
}
static int F_41 ( struct V_22 * V_22 , void * V_23 ,
struct V_124 * V_17 )
{
static const struct V_124 V_125 [] = {
{ 0 , V_114 , 0 ,
L_4 , V_75 , { 0 , 0 , 0 , 0 }
} ,
{ 1 , V_114 , V_126 ,
L_5 , V_46 , { 0 , 0 , 0 , 0 }
} ,
{ 2 , V_114 , 0 ,
L_6 , V_127 , { 0 , 0 , 0 , 0 }
} ,
} ;
if ( V_17 -> V_107 > F_42 ( V_125 ) - 1 )
return - V_65 ;
* V_17 = V_125 [ V_17 -> V_107 ] ;
return 0 ;
}
static int F_43 ( struct V_22 * V_22 , void * V_23 , unsigned int * V_15 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_15 = V_28 -> V_128 ;
return 0 ;
}
int F_44 ( struct V_22 * V_22 , void * V_23 , unsigned int V_129 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_129 >= V_28 -> V_130 )
return - V_65 ;
if ( V_129 == V_28 -> V_128 ) {
F_45 ( L_7 ) ;
return 0 ;
}
F_45 ( L_8 ,
V_28 -> V_128 , V_129 ) ;
V_28 -> V_128 = V_129 ;
V_28 -> V_108 = V_28 -> V_96 -> V_131 [ V_129 ] . V_132 ;
F_46 ( V_28 ) ;
F_47 ( V_28 ) ;
F_34 ( V_28 ) ;
F_48 ( V_28 ) ;
return 0 ;
}
static int F_49 ( struct V_22 * V_22 , void * V_23 ,
struct V_133 * V_134 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_134 -> V_135 != 0 )
return - V_65 ;
F_50 ( V_28 , V_135 , V_136 , V_134 ) ;
return 0 ;
}
int F_51 ( struct V_22 * V_22 , void * V_23 , const struct V_133 * V_134 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_134 -> V_135 != 0 )
return - V_65 ;
F_46 ( V_28 ) ;
F_45 ( L_9 , V_134 -> V_137 ) ;
F_50 ( V_28 , V_135 , V_138 , V_134 ) ;
F_48 ( V_28 ) ;
return 0 ;
}
static int F_52 ( struct V_22 * V_22 , void * V_23 , T_2 * V_139 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
* V_139 = V_28 -> V_139 ;
return 0 ;
}
int F_53 ( struct V_22 * V_22 , void * V_23 , T_2 V_139 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( ( V_139 & V_140 ) == 0 )
return - V_65 ;
if ( V_139 == V_28 -> V_139 )
return 0 ;
if ( F_54 ( V_141 , & V_28 -> V_142 ) ||
F_18 ( & V_28 -> V_73 ) > 0 ) {
return - V_74 ;
}
V_28 -> V_139 = V_139 ;
V_28 -> V_143 = ( V_139 & V_144 ) ? 1 : 0 ;
V_28 -> V_69 = ! V_28 -> V_143 ;
F_55 ( & V_28 -> V_36 , V_28 -> V_69 ) ;
V_28 -> V_36 . V_35 = 720 ;
V_28 -> V_36 . V_37 = V_28 -> V_69 ? 576 : 480 ;
V_28 -> V_49 . V_57 = V_28 -> V_69 ? 18 : 12 ;
V_28 -> V_49 . V_56 [ 0 ] = V_28 -> V_69 ? 6 : 10 ;
V_28 -> V_49 . V_56 [ 1 ] = V_28 -> V_69 ? 318 : 273 ;
F_45 ( L_10 ,
( unsigned long long ) V_28 -> V_139 ) ;
F_50 ( V_28 , V_78 , V_145 , V_28 -> V_139 ) ;
return 0 ;
}
static int F_56 ( struct V_22 * V_22 , void * V_23 , const struct V_146 * V_147 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( V_147 -> V_107 != 0 )
return - V_65 ;
F_50 ( V_28 , V_135 , V_148 , V_147 ) ;
return 0 ;
}
static int F_57 ( struct V_22 * V_22 , void * V_23 , struct V_146 * V_147 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
if ( V_147 -> V_107 != 0 )
return - V_65 ;
F_50 ( V_28 , V_135 , V_149 , V_147 ) ;
if ( V_147 -> type == V_150 )
F_28 ( V_147 -> V_151 , L_11 , sizeof( V_147 -> V_151 ) ) ;
else
F_28 ( V_147 -> V_151 , L_12 , sizeof( V_147 -> V_151 ) ) ;
return 0 ;
}
static int F_58 ( struct V_22 * V_22 , void * V_23 ,
struct V_152 * V_153 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
int V_11 = V_28 -> V_69 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_153 -> type != V_85 )
return - V_65 ;
V_153 -> V_18 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_28 -> V_69 ) ) {
V_153 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
V_153 -> V_18 |= V_11 ;
} else
V_153 -> V_21 [ V_19 ] [ V_20 ] = 0 ;
}
}
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
V_153 -> V_59 [ V_19 ] = 0 ;
return 0 ;
}
static int F_59 ( struct V_154 * V_155 ,
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
V_161 -> V_51 = ( ( ( V_173 ) F_60 ( V_163 -> V_174 ) ) << 32 )
| F_60 ( V_163 -> V_175 ) ;
V_161 -> V_176 = ( ( ( V_173 ) ( F_60 ( V_163 -> V_177 ) & 1 ) ) << 32 )
| F_60 ( V_163 -> V_178 ) ;
V_161 -> V_179 = F_60 ( V_163 -> V_179 ) ;
V_161 -> V_58 = V_164 [ F_60 ( V_163 -> V_58 ) & 0x7 ] ;
V_161 -> V_59 [ 0 ] = 0 ;
V_161 -> V_59 [ 1 ] = 0 ;
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
static int F_61 ( struct V_29 * V_30 , struct V_180 * V_181 ,
struct V_156 * V_157 )
{
if ( V_30 -> type != V_182 )
return - V_65 ;
if ( V_181 -> V_183 == NULL )
V_181 -> V_183 = F_62 ( & V_181 -> V_184 ,
struct V_154 , V_185 ) ;
if ( F_63 ( V_181 -> V_183 , & V_181 -> V_184 , V_185 ) ) {
V_181 -> V_169 = V_181 -> V_168 ;
return 0 ;
}
F_64 (mdl->curr_buf, &mdl->buf_list, list) {
if ( V_181 -> V_183 -> V_169 >= V_181 -> V_183 -> V_168 )
continue;
V_181 -> V_169 += F_59 ( V_181 -> V_183 , V_157 ) ;
if ( V_157 -> V_171 >= V_172 ||
V_181 -> V_183 -> V_169 < V_181 -> V_183 -> V_168 ||
V_181 -> V_169 >= V_181 -> V_168 )
break;
}
return 0 ;
}
static int F_65 ( struct V_22 * V_22 , void * V_23 ,
struct V_156 * V_157 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_182 ] ;
T_3 V_186 ;
struct V_180 * V_181 ;
if ( ! F_66 ( V_30 ) )
return - V_65 ;
V_186 = V_30 -> V_187 -
V_30 -> V_188 * V_189 ;
if ( V_186 <= 0 )
V_186 = 1 ;
V_186 = V_186 * V_30 -> V_190 / sizeof( struct V_162 ) ;
V_157 -> V_171 = 0 ;
V_157 -> V_191 = V_186 ;
memset ( V_157 -> V_59 , 0 , sizeof( V_157 -> V_59 ) ) ;
do {
V_181 = F_67 ( V_30 , & V_30 -> V_192 ) ;
if ( V_181 == NULL )
break;
F_61 ( V_30 , V_181 , V_157 ) ;
if ( V_181 -> V_169 < V_181 -> V_168 ) {
F_68 ( V_30 , V_181 , & V_30 -> V_192 ) ;
break;
}
F_69 ( V_30 , V_181 , & V_30 -> V_193 ) ;
} while ( V_157 -> V_171 < V_172 );
F_70 ( V_30 ) ;
return 0 ;
}
static struct V_194 * F_71 ( struct V_25 * V_26 )
{
struct V_194 * V_195 = NULL ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
switch ( V_30 -> V_196 ) {
case V_114 :
V_195 = & V_30 -> V_197 ;
break;
case V_83 :
break;
default:
break;
}
return V_195 ;
}
static int F_72 ( struct V_22 * V_22 , void * V_198 ,
enum V_199 type )
{
struct V_25 * V_26 = V_22 -> V_200 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_114 ) &&
( V_30 -> V_196 != V_83 ) )
return - V_65 ;
if ( V_26 -> type != V_41 )
return - V_65 ;
F_73 ( & V_30 -> V_201 , F_74 ( 2000 ) + V_202 ) ;
return F_75 ( F_71 ( V_26 ) ) ;
}
static int F_76 ( struct V_22 * V_22 , void * V_198 ,
enum V_199 type )
{
struct V_25 * V_26 = V_22 -> V_200 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_114 ) &&
( V_30 -> V_196 != V_83 ) )
return - V_65 ;
if ( V_26 -> type != V_41 )
return - V_65 ;
return F_77 ( F_71 ( V_26 ) ) ;
}
static int F_78 ( struct V_22 * V_22 , void * V_198 ,
struct V_203 * V_204 )
{
struct V_25 * V_26 = V_22 -> V_200 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_114 ) &&
( V_30 -> V_196 != V_83 ) )
return - V_65 ;
return F_79 ( F_71 ( V_26 ) , V_204 ) ;
}
static int F_80 ( struct V_22 * V_22 , void * V_198 ,
struct V_205 * V_206 )
{
struct V_25 * V_26 = V_22 -> V_200 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_114 ) &&
( V_30 -> V_196 != V_83 ) )
return - V_65 ;
return F_81 ( F_71 ( V_26 ) , V_206 ) ;
}
static int F_82 ( struct V_22 * V_22 , void * V_198 , struct V_205 * V_206 )
{
struct V_25 * V_26 = V_22 -> V_200 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_114 ) &&
( V_30 -> V_196 != V_83 ) )
return - V_65 ;
return F_83 ( F_71 ( V_26 ) , V_206 ) ;
}
static int F_84 ( struct V_22 * V_22 , void * V_198 , struct V_205 * V_206 )
{
struct V_25 * V_26 = V_22 -> V_200 ;
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_31 [ V_26 -> type ] ;
if ( ( V_30 -> V_196 != V_114 ) &&
( V_30 -> V_196 != V_83 ) )
return - V_65 ;
return F_85 ( F_71 ( V_26 ) , V_206 , V_22 -> V_207 & V_208 ) ;
}
static int F_86 ( struct V_22 * V_22 , void * V_23 ,
struct V_209 * V_210 )
{
struct V_25 * V_26 = F_8 ( V_23 ) ;
struct V_27 * V_28 = V_26 -> V_28 ;
T_4 V_67 ;
switch ( V_210 -> V_211 ) {
case V_212 :
F_87 ( L_13 ) ;
V_210 -> V_58 = 0 ;
return F_88 ( V_26 ) ;
case V_213 :
F_87 ( L_14 ) ;
V_210 -> V_58 &= V_214 ;
F_89 ( V_26 ,
V_210 -> V_58 & V_214 ) ;
break;
case V_215 :
F_87 ( L_15 ) ;
V_210 -> V_58 = 0 ;
if ( ! F_18 ( & V_28 -> V_73 ) )
return - V_216 ;
if ( F_90 ( V_217 , & V_28 -> V_142 ) )
return 0 ;
V_67 = F_91 ( V_28 ) ;
if ( V_67 == V_218 ) {
F_92 ( L_16
L_15 ) ;
return - V_219 ;
}
F_46 ( V_28 ) ;
F_93 ( V_28 , V_220 , 1 , V_67 ) ;
break;
case V_221 :
F_87 ( L_17 ) ;
V_210 -> V_58 = 0 ;
if ( ! F_18 ( & V_28 -> V_73 ) )
return - V_216 ;
if ( ! F_94 ( V_217 , & V_28 -> V_142 ) )
return 0 ;
V_67 = F_91 ( V_28 ) ;
if ( V_67 == V_218 ) {
F_92 ( L_16
L_17 ) ;
return - V_219 ;
}
F_93 ( V_28 , V_222 , 1 , V_67 ) ;
F_48 ( V_28 ) ;
break;
default:
F_87 ( L_18 , V_210 -> V_211 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_95 ( struct V_22 * V_22 , void * V_23 ,
struct V_209 * V_210 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_210 -> V_211 ) {
case V_212 :
F_87 ( L_13 ) ;
V_210 -> V_58 = 0 ;
break;
case V_213 :
F_87 ( L_14 ) ;
V_210 -> V_58 &= V_214 ;
break;
case V_215 :
F_87 ( L_15 ) ;
V_210 -> V_58 = 0 ;
break;
case V_221 :
F_87 ( L_17 ) ;
V_210 -> V_58 = 0 ;
break;
default:
F_87 ( L_18 , V_210 -> V_211 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_96 ( struct V_22 * V_22 , void * V_23 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
struct V_111 V_223 ;
struct V_105 V_224 ;
int V_15 ;
F_97 ( L_19 , V_225 , V_28 -> V_97 ) ;
if ( V_28 -> V_226 & V_227 ) {
struct V_228 V_229 ;
F_98 ( V_28 , & V_229 ) ;
}
F_50 ( V_28 , V_230 , V_231 ) ;
F_36 ( V_28 , V_28 -> V_128 , & V_223 ) ;
F_31 ( V_28 , V_28 -> V_108 , & V_224 ) ;
F_97 ( L_20 , V_223 . V_151 ) ;
F_97 ( L_21 , V_224 . V_151 ) ;
F_99 ( & V_28 -> V_232 ) ;
F_97 ( L_22 ,
V_28 -> V_233 , V_28 -> V_234 ) ;
F_100 ( & V_28 -> V_232 ) ;
F_97 ( L_23 ,
F_54 ( V_141 , & V_28 -> V_142 ) ? L_24 : L_25 ) ;
F_101 ( & V_28 -> V_36 . V_235 , V_28 -> V_236 . V_151 ) ;
F_97 ( L_26 , V_28 -> V_142 ) ;
for ( V_15 = 0 ; V_15 < V_237 ; V_15 ++ ) {
struct V_29 * V_30 = & V_28 -> V_31 [ V_15 ] ;
if ( V_30 -> V_238 == NULL || V_30 -> V_187 == 0 )
continue;
F_97 ( L_27 ,
V_30 -> V_151 , V_30 -> V_239 ,
F_18 ( & V_30 -> V_192 . V_240 ) * V_30 -> V_188 * 100
/ V_30 -> V_187 ,
( V_30 -> V_187 * V_30 -> V_190 ) / 1024 , V_30 -> V_187 ) ;
}
F_97 ( L_28 ,
( long long ) V_28 -> V_241 ,
( long long ) V_28 -> V_242 ) ;
return 0 ;
}
static long F_102 ( struct V_22 * V_22 , void * V_23 , bool V_243 ,
unsigned int V_211 , void * V_244 )
{
struct V_27 * V_28 = F_8 ( V_23 ) -> V_28 ;
switch ( V_211 ) {
case V_245 : {
T_4 V_91 = * ( T_4 * ) V_244 ;
if ( ( V_91 == 0 ) || ( V_91 & 0x01 ) )
F_103 ( V_28 , V_246 , V_230 , V_247 ,
( T_4 ) V_248 ) ;
break;
}
default:
return - V_249 ;
}
return 0 ;
}
void F_104 ( struct V_250 * V_251 )
{
V_251 -> V_252 = & V_253 ;
}
