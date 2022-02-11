static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + F_2 ( V_5 ) ;
const struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_10 ;
T_1 V_11 ;
if ( ! F_5 ( V_9 ) )
return 0 ;
V_11 = V_12 ;
if ( V_9 -> V_13 != V_14 )
V_11 |= V_15 ;
do {
V_10 = F_6 ( V_2 , 0 , V_16 ) ;
if ( V_10 == - V_17 || V_10 == - V_18 ) {
F_7 ( 50 , 100 ) ;
continue;
}
if ( V_10 < 0 )
return V_10 ;
if ( ( V_10 & V_11 ) == V_11 )
return 0 ;
F_7 ( 50 , 100 ) ;
} while ( F_8 ( V_4 , V_3 ) );
return - V_19 ;
}
static int F_9 ( struct V_1 * V_2 , int V_20 , int V_21 )
{
int V_22 ;
V_22 = F_1 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
return F_10 ( V_2 , V_20 , V_21 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_20 , int V_21 )
{
int V_22 ;
V_22 = F_1 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
return F_6 ( V_2 , V_20 , V_21 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_20 , T_1 V_23 )
{
int V_22 ;
V_22 = F_1 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
return F_13 ( V_2 , V_20 , V_23 ) ;
}
static inline int F_14 ( int V_9 )
{
T_2 V_24 = ( ( T_2 ) V_9 ) >> 11 ;
T_3 V_25 = ( ( ( T_2 ) ( V_9 << 5 ) ) >> 5 ) ;
V_24 += 6 ;
return ( V_24 < 0 ? V_25 > > - V_24 : V_25 << V_24 ) ;
}
static int F_15 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_20 , int V_21 , T_4 * V_26 )
{
int V_22 ;
V_22 = F_9 ( V_2 , V_20 , V_21 ) ;
if ( V_22 >= 0 ) {
if ( F_14 ( V_22 ) > F_14 ( * V_26 ) )
* V_26 = V_22 ;
V_22 = * V_26 ;
}
return V_22 ;
}
static int F_16 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_20 , int V_21 , T_4 * V_27 )
{
int V_22 ;
V_22 = F_9 ( V_2 , V_20 , V_21 ) ;
if ( V_22 >= 0 ) {
if ( F_14 ( V_22 ) < F_14 ( * V_27 ) )
* V_27 = V_22 ;
V_22 = * V_27 ;
}
return V_22 ;
}
static int F_17 ( struct V_1 * V_2 , int V_20 ,
int V_21 )
{
const struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_22 ;
switch ( V_21 ) {
case V_28 :
V_22 = F_15 ( V_9 , V_2 , V_20 , V_29 ,
& V_9 -> V_30 ) ;
break;
case V_31 :
V_22 = F_9 ( V_2 , V_20 , V_32 ) ;
if ( V_22 >= 0 ) {
if ( V_22 > V_9 -> V_33 [ V_20 ] )
V_9 -> V_33 [ V_20 ] = V_22 ;
V_22 = V_9 -> V_33 [ V_20 ] ;
}
break;
case V_34 :
V_22 = F_15 ( V_9 , V_2 , V_20 ,
V_35 ,
& V_9 -> V_36 [ V_20 ] ) ;
break;
case V_37 :
case V_38 :
case V_39 :
V_22 = 0 ;
break;
default:
V_22 = F_1 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = - V_40 ;
break;
}
return V_22 ;
}
static int F_18 ( struct V_1 * V_2 , int V_20 , int V_21 )
{
const struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_22 ;
switch ( V_21 ) {
case V_41 :
V_22 = F_16 ( V_9 , V_2 , V_20 , V_42 ,
& V_9 -> V_43 ) ;
break;
case V_44 :
V_22 = F_9 ( V_2 , V_20 , V_45 ) ;
if ( V_22 >= 0 ) {
if ( V_9 -> V_33 [ V_20 ] && V_22 > V_9 -> V_33 [ V_20 ] )
V_22 = V_9 -> V_33 [ V_20 ] ;
if ( V_22 < V_9 -> V_46 [ V_20 ] )
V_9 -> V_46 [ V_20 ] = V_22 ;
V_22 = V_9 -> V_46 [ V_20 ] ;
}
break;
case V_47 :
V_22 = F_16 ( V_9 , V_2 , V_20 ,
V_48 ,
& V_9 -> V_49 [ V_20 ] ) ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
V_22 = - V_18 ;
break;
default:
V_22 = F_17 ( V_2 , V_20 , V_21 ) ;
break;
}
return V_22 ;
}
static int F_19 ( struct V_1 * V_2 , int V_20 , int V_21 )
{
const struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_22 ;
switch ( V_21 ) {
case V_50 :
V_22 = F_15 ( V_9 , V_2 , V_20 , V_54 ,
& V_9 -> V_55 [ V_20 ] ) ;
break;
case V_56 :
V_22 = F_16 ( V_9 , V_2 , V_20 , V_57 ,
& V_9 -> V_58 [ V_20 ] ) ;
break;
case V_51 :
V_22 = 0 ;
break;
default:
V_22 = F_18 ( V_2 , V_20 , V_21 ) ;
break;
}
return V_22 ;
}
static int F_20 ( struct V_1 * V_2 , int V_20 , int V_21 )
{
const struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_22 ;
switch ( V_21 ) {
case V_59 :
V_22 = F_15 ( V_9 , V_2 , V_20 , V_60 ,
& V_9 -> V_61 ) ;
break;
case V_62 :
V_22 = F_16 ( V_9 , V_2 , V_20 , V_63 ,
& V_9 -> V_64 ) ;
break;
case V_65 :
V_22 = F_15 ( V_9 , V_2 , V_20 , V_66 ,
& V_9 -> V_67 ) ;
break;
case V_68 :
V_22 = F_16 ( V_9 , V_2 , V_20 , V_69 ,
& V_9 -> V_70 ) ;
break;
case V_71 :
case V_72 :
V_22 = 0 ;
break;
default:
V_22 = F_18 ( V_2 , V_20 , V_21 ) ;
break;
}
return V_22 ;
}
static int F_21 ( struct V_1 * V_2 , int V_20 , int V_21 )
{
const struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_22 ;
switch ( V_21 ) {
case V_50 :
V_22 = F_15 ( V_9 , V_2 , V_20 , V_73 ,
& V_9 -> V_55 [ V_20 ] ) ;
break;
case V_52 :
V_22 = F_15 ( V_9 , V_2 , V_20 ,
V_74 ,
& V_9 -> V_75 ) ;
break;
case V_41 :
case V_44 :
case V_47 :
V_22 = - V_18 ;
break;
case V_51 :
case V_53 :
V_22 = 0 ;
break;
default:
V_22 = F_17 ( V_2 , V_20 , V_21 ) ;
break;
}
return V_22 ;
}
static int F_22 ( struct V_1 * V_2 , int V_20 , int V_21 )
{
const struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_22 ;
switch ( V_21 ) {
case V_59 :
V_22 = F_15 ( V_9 , V_2 , V_20 , V_76 ,
& V_9 -> V_61 ) ;
break;
case V_71 :
V_22 = 0 ;
break;
default:
V_22 = F_21 ( V_2 , V_20 , V_21 ) ;
break;
}
return V_22 ;
}
static int F_23 ( struct V_8 * V_9 ,
struct V_1 * V_2 , int V_20 )
{
int V_22 ;
if ( F_24 ( V_9 ) )
V_22 = F_12 ( V_2 , 0 , V_77 ) ;
else
V_22 = F_12 ( V_2 , V_20 , V_78 ) ;
return V_22 ;
}
static int F_25 ( struct V_1 * V_2 , int V_20 ,
int V_21 , T_4 V_79 )
{
const struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_22 ;
switch ( V_21 ) {
case V_71 :
V_9 -> V_61 = 0x7c00 ;
V_9 -> V_64 = 0x7bff ;
V_22 = F_23 ( V_9 , V_2 , 0 ) ;
break;
case V_72 :
V_9 -> V_67 = 0x7c00 ;
V_9 -> V_70 = 0x7bff ;
V_22 = F_23 ( V_9 , V_2 , 0 ) ;
break;
case V_51 :
V_9 -> V_55 [ V_20 ] = 0x7c00 ;
V_9 -> V_58 [ V_20 ] = 0xfbff ;
V_22 = F_23 ( V_9 , V_2 , V_20 ) ;
break;
case V_53 :
V_9 -> V_75 = 0x7c00 ;
V_22 = F_23 ( V_9 , V_2 , V_20 ) ;
break;
case V_37 :
V_9 -> V_46 [ V_20 ] = 0xffff ;
V_9 -> V_33 [ V_20 ] = 0 ;
V_22 = F_23 ( V_9 , V_2 , V_20 ) ;
break;
case V_38 :
V_9 -> V_43 = 0x7bff ;
V_9 -> V_30 = 0x7c00 ;
V_22 = F_23 ( V_9 , V_2 , V_20 ) ;
break;
case V_39 :
V_9 -> V_49 [ V_20 ] = 0x7bff ;
V_9 -> V_36 [ V_20 ] = 0x7c00 ;
V_22 = F_23 ( V_9 , V_2 , V_20 ) ;
break;
default:
V_22 = F_1 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = - V_40 ;
break;
}
return V_22 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_80 ;
V_80 = F_27 ( V_2 , V_81 ) ;
if ( V_80 < 0 ) {
const struct V_82 * V_13 ;
T_1 V_83 [ V_84 ] ;
int V_22 ;
if ( ! F_28 ( V_2 -> V_85 ,
V_86 ) )
return - V_87 ;
V_22 = F_29 ( V_2 , V_88 , V_83 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_22 < 3 || strncmp ( V_83 , L_1 , 3 ) )
return - V_87 ;
V_22 = F_29 ( V_2 , V_89 , V_83 ) ;
if ( V_22 < 0 )
return V_22 ;
for ( V_13 = & V_90 [ 0 ] ; strlen ( V_13 -> V_91 ) ; V_13 ++ ) {
if ( ! strncasecmp ( V_13 -> V_91 , V_83 , strlen ( V_13 -> V_91 ) ) )
return ( int ) V_13 -> V_92 ;
}
return - V_87 ;
}
V_80 &= V_93 ;
if ( V_80 == V_94 )
return V_95 ;
else if ( V_80 == V_96 )
return V_97 ;
else if ( V_80 == V_98 )
return V_99 ;
else if ( V_80 == V_100 || V_80 == V_101 )
return V_102 ;
else if ( V_80 == V_103 || V_80 == V_104 )
return V_105 ;
else if ( V_80 == V_106 )
return V_107 ;
else if ( V_80 == V_108 || V_80 == V_109 )
return V_110 ;
else if ( V_80 == V_111 )
return V_14 ;
else if ( V_80 == V_112 )
return V_113 ;
else if ( V_80 == V_114 )
return V_115 ;
else if ( V_80 == V_116 || V_80 == V_117 )
return V_118 ;
else if ( V_80 == V_119 )
return V_120 ;
else if ( V_80 == V_121 || V_80 == V_122 ||
V_80 == V_123 )
return V_124 ;
F_30 ( & V_2 -> V_125 , L_2 , V_80 ) ;
return - V_87 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_82 * V_13 )
{
int V_126 , V_80 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
if ( ! F_28 ( V_2 -> V_85 ,
V_127 ) )
return - V_87 ;
V_9 = F_32 ( & V_2 -> V_125 , sizeof( struct V_8 ) ,
V_128 ) ;
if ( ! V_9 )
return - V_129 ;
V_80 = F_26 ( V_2 ) ;
if ( V_80 < 0 )
return V_80 ;
V_9 -> V_13 = V_80 ;
if ( V_9 -> V_13 != V_13 -> V_92 )
F_33 ( & V_2 -> V_125 ,
L_3 ,
V_13 -> V_91 ,
V_90 [ V_9 -> V_13 ] . V_91 ) ;
V_7 = & V_9 -> V_7 ;
V_7 -> V_130 = F_25 ;
V_7 -> V_131 = F_12 ;
V_7 -> V_132 = F_9 ;
V_7 -> V_133 = F_11 ;
V_9 -> V_43 = 0x7bff ;
V_9 -> V_30 = 0x7c00 ;
for ( V_126 = 0 ; V_126 < F_34 ( V_9 -> V_46 ) ; V_126 ++ )
V_9 -> V_46 [ V_126 ] = 0xffff ;
for ( V_126 = 0 ; V_126 < F_34 ( V_9 -> V_58 ) ; V_126 ++ )
V_9 -> V_58 [ V_126 ] = 0xfbff ;
for ( V_126 = 0 ; V_126 < F_34 ( V_9 -> V_55 ) ; V_126 ++ )
V_9 -> V_55 [ V_126 ] = 0x7c00 ;
for ( V_126 = 0 ; V_126 < F_34 ( V_9 -> V_49 ) ; V_126 ++ )
V_9 -> V_49 [ V_126 ] = 0x7bff ;
for ( V_126 = 0 ; V_126 < F_34 ( V_9 -> V_36 ) ; V_126 ++ )
V_9 -> V_36 [ V_126 ] = 0x7c00 ;
V_9 -> V_75 = 0x7c00 ;
switch ( V_9 -> V_13 ) {
case V_95 :
V_7 -> V_132 = F_19 ;
V_7 -> V_134 = V_135 ;
V_7 -> V_136 [ 0 ] = V_137 | V_138
| V_139 ;
for ( V_126 = 0 ; V_126 < V_7 -> V_134 ; V_126 ++ ) {
V_7 -> V_136 [ V_126 ] |= V_140
| V_141 | V_142
| V_143 | V_144
| V_145 | V_146 ;
}
break;
case V_97 :
V_7 -> V_132 = F_20 ;
V_7 -> V_134 = V_135 ;
V_7 -> V_136 [ 0 ] = V_147 | V_148
| V_137 | V_138
| V_139 ;
for ( V_126 = 0 ; V_126 < V_7 -> V_134 ; V_126 ++ ) {
V_7 -> V_136 [ V_126 ] |= V_140
| V_141 | V_142
| V_143 | V_144
| V_145 | V_146 ;
}
break;
case V_99 :
case V_102 :
case V_105 :
case V_118 :
V_7 -> V_132 = F_18 ;
V_7 -> V_134 = V_149 ;
V_7 -> V_136 [ 0 ] = V_137 | V_138
| V_140 | V_141
| V_143 | V_144 ;
for ( V_126 = 1 ; V_126 < V_149 ; V_126 ++ ) {
V_7 -> V_136 [ V_126 ] = V_140
| V_141 ;
}
break;
case V_107 :
case V_115 :
case V_120 :
case V_124 :
V_9 -> V_150 |= V_151 | V_152 ;
V_7 -> V_132 = F_21 ;
V_7 -> V_134 = V_153 ;
V_7 -> V_136 [ 0 ] = V_137 | V_147
| V_138
| V_140 | V_141
| V_145 | V_146
| V_142 | V_143
| V_139 | V_144 ;
V_7 -> V_136 [ 1 ] = V_140 | V_141
| V_145 | V_146
| V_142
| V_143 | V_144 ;
break;
case V_110 :
V_9 -> V_150 |= V_151 | V_152 ;
V_7 -> V_132 = F_21 ;
V_7 -> V_134 = V_153 ;
V_7 -> V_136 [ 0 ] = V_137
| V_138
| V_140 | V_141
| V_145 | V_146
| V_142 | V_143
| V_139 | V_144 ;
V_7 -> V_136 [ 1 ] = V_140 | V_141
| V_145 | V_146
| V_142
| V_143 | V_144 ;
break;
case V_14 :
V_9 -> V_150 |= V_151 | V_152 ;
V_7 -> V_132 = F_22 ;
V_7 -> V_134 = V_154 ;
V_7 -> V_136 [ 0 ] = V_137 | V_147
| V_138
| V_140 | V_141
| V_145 | V_146
| V_148 | V_142 | V_143
| V_139 | V_144 ;
break;
case V_113 :
V_9 -> V_150 |= V_151 | V_152 ;
V_7 -> V_132 = F_22 ;
V_7 -> V_134 = V_153 ;
V_7 -> V_136 [ 0 ] = V_137 | V_147
| V_138
| V_140 | V_141
| V_145 | V_146
| V_148 | V_142 | V_143
| V_139 | V_144 ;
V_7 -> V_136 [ 1 ] = V_140 | V_141
| V_145 | V_146
| V_142
| V_143 | V_144 ;
break;
default:
return - V_87 ;
}
#if F_35 ( V_155 )
V_7 -> V_156 = V_7 -> V_134 ;
V_7 -> V_157 = V_158 ;
if ( V_7 -> V_156 > F_34 ( V_158 ) ) {
F_30 ( & V_2 -> V_125 , L_4 ) ;
V_7 -> V_156 = F_34 ( V_158 ) ;
}
#endif
return F_36 ( V_2 , V_13 , V_7 ) ;
}
