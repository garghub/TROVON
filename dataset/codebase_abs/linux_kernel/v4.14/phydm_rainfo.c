void F_1 ( void * V_1 , T_1 * const V_2 , T_1 * V_3 ,
char * V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
T_2 V_8 [ V_9 ] = { 0 } ;
T_2 V_10 = ( T_2 ) V_2 [ 0 ] ;
T_2 V_11 ;
T_1 V_12 = * V_3 ;
T_1 V_13 = * V_5 ;
F_2 ( V_4 + V_12 , V_13 - V_12 ,
L_1 , V_10 ) ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
V_8 [ V_11 ] = ( T_2 ) V_2 [ V_11 + 1 ] ;
F_2 ( V_4 + V_12 , V_13 - V_12 ,
L_2 , V_11 ,
V_8 [ V_11 ] ) ;
}
F_3 ( V_7 , V_10 , V_9 , V_8 ) ;
}
void F_4 ( void * V_1 , T_1 * const V_2 , T_1 * V_3 ,
char * V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
struct V_14 * V_15 = & V_7 -> V_16 ;
T_1 V_12 = * V_3 ;
T_1 V_13 = * V_5 ;
if ( V_2 [ 0 ] == 100 ) {
F_2 (
V_4 + V_12 , V_13 - V_12 ,
L_3 ,
( ( V_15 -> V_17 == 0 ) ?
L_4 :
( ( V_15 -> V_18 ) ? L_5 : L_6 ) ) ,
V_15 -> V_17 ) ;
} else if ( V_2 [ 0 ] == 0 ) {
V_15 -> V_18 = 0 ;
V_15 -> V_17 = ( T_2 ) V_2 [ 1 ] ;
F_2 ( V_4 + V_12 , V_13 - V_12 ,
L_7 ,
V_15 -> V_17 ) ;
} else if ( V_2 [ 0 ] == 1 ) {
V_15 -> V_18 = 1 ;
V_15 -> V_17 = ( T_2 ) V_2 [ 1 ] ;
F_2 ( V_4 + V_12 , V_13 - V_12 ,
L_8 ,
V_15 -> V_17 ) ;
} else {
F_2 ( V_4 + V_12 , V_13 - V_12 , L_9 ) ;
}
}
void F_5 ( void * V_1 , T_2 * V_19 , T_2 V_20 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
T_2 V_21 = V_19 [ 0 ] ;
T_2 V_11 ;
F_6 ( V_7 , V_22 ,
L_10 ,
V_19 [ 0 ] ) ;
if ( V_21 == V_23 ) {
F_6 ( V_7 , V_24 ,
L_11 ) ;
if ( V_7 -> V_25 & V_26 ) {
F_6 ( V_7 , V_24 , L_12 ,
L_13 , V_19 [ 1 ] ) ;
F_6 ( V_7 , V_24 , L_14 ,
L_15 , V_19 [ 2 ] & 0x7f ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_16 , ( V_19 [ 2 ] & 0x80 ) >> 7 ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_17 , V_19 [ 3 ] ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_18 , V_19 [ 4 ] ) ;
F_6 ( V_7 , V_24 , L_14 ,
L_19 , V_19 [ 5 ] ) ;
F_6 ( V_7 , V_24 , L_14 ,
L_20 , V_19 [ 6 ] ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_21 , V_19 [ 7 ] ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_22 , V_19 [ 8 ] ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_23 , V_19 [ 9 ] ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_24 , V_19 [ 10 ] ) ;
F_6 ( V_7 , V_24 , L_14 ,
L_25 , V_19 [ 11 ] ) ;
} else {
F_6 ( V_7 , V_24 , L_12 ,
L_13 , V_19 [ 1 ] ) ;
F_6 ( V_7 , V_24 , L_26 ,
L_17 , V_19 [ 2 ] ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_21 , V_19 [ 3 ] ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_22 , V_19 [ 4 ] ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_27 , V_19 [ 5 ] ) ;
F_6 ( V_7 , V_24 , L_14 ,
L_28 , V_19 [ 6 ] ) ;
F_6 ( V_7 , V_24 , L_14 ,
L_23 , V_19 [ 7 ] ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_29 , V_19 [ 8 ] ) ;
;
}
F_6 ( V_7 , V_24 ,
L_11 ) ;
} else if ( V_21 == V_27 ) {
F_6 ( V_7 , V_24 ,
L_11 ) ;
if ( V_7 -> V_25 & V_26 ) {
F_6 ( V_7 , V_24 , L_12 ,
L_30 , V_19 [ 1 ] ) ;
F_6 ( V_7 , V_24 , L_14 ,
L_31 , V_19 [ 2 ] ) ;
F_6 ( V_7 , V_24 , L_14 ,
L_32 , V_19 [ 3 ] ) ;
for ( V_11 = 4 ; V_11 <= 11 ; V_11 ++ )
F_6 ( V_7 , V_24 ,
L_33 , V_19 [ V_11 ] ) ;
} else {
F_6 ( V_7 , V_24 ,
L_34 ,
L_35 , V_19 [ 8 ] , V_19 [ 7 ] ,
V_19 [ 6 ] , V_19 [ 5 ] , V_19 [ 4 ] ,
V_19 [ 3 ] , V_19 [ 2 ] , V_19 [ 1 ] ) ;
}
F_6 ( V_7 , V_24 ,
L_11 ) ;
} else if ( V_21 == V_28 ) {
for ( V_11 = 0 ; V_11 < ( V_20 - 1 ) ; V_11 ++ )
F_6 ( V_7 , V_24 ,
L_36 , V_11 , V_19 [ 1 + V_11 ] ) ;
} else if ( V_21 == V_29 ) {
F_6 ( V_7 , V_24 , L_37 ,
L_38 , V_19 [ 1 ] , V_19 [ 2 ] ) ;
} else if ( V_21 == V_30 ) {
F_6 ( V_7 , V_24 , L_14 ,
L_39 , V_19 [ 1 ] ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_40 , V_19 [ 2 ] ) ;
F_6 ( V_7 , V_24 , L_12 ,
L_41 , V_19 [ 3 ] ) ;
F_6 ( V_7 , V_24 , L_14 ,
L_42 , V_19 [ 4 ] ) ;
F_6 ( V_7 , V_24 , L_43 ,
L_44 , V_19 [ 5 ] , V_19 [ 6 ] ) ;
F_6 ( V_7 , V_24 , L_45 ,
L_46 , V_19 [ 11 ] , V_19 [ 10 ] , V_19 [ 9 ] ,
V_19 [ 8 ] , V_19 [ 7 ] ) ;
}
}
void F_7 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
if ( ! ( V_7 -> V_31 & V_32 ) )
return;
if ( V_7 -> V_33 != V_7 -> V_34 ) {
if ( V_7 -> V_34 ) {
F_6 ( V_7 , V_35 ,
L_47 ) ;
F_8 ( V_7 , 0x430 , V_36 , 0x0 ) ;
F_8 ( V_7 , 0x434 , V_36 , 0x04030201 ) ;
} else {
F_6 ( V_7 , V_35 ,
L_48 ) ;
F_8 ( V_7 , 0x430 , V_36 , 0x01000000 ) ;
F_8 ( V_7 , 0x434 , V_36 , 0x06050402 ) ;
}
V_7 -> V_33 = V_7 -> V_34 ;
}
}
void F_9 ( void * V_1 ) {}
void F_10 ( void * V_1 , T_2 V_37 , T_1 V_38 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
T_2 V_39 [ 12 ] = { 1 , 2 , 5 , 11 , 6 , 9 , 12 , 18 , 24 , 36 , 48 , 54 } ;
T_2 V_40 = V_37 & 0x7f ;
T_2 V_41 = ( V_40 >= V_42 ) ? 1 : 0 ;
T_2 V_43 = ( V_37 & 0x80 ) >> 7 ;
F_6 ( V_7 , V_38 , L_49 ,
( ( V_40 >= V_42 ) &&
( V_40 <= V_44 ) ) ?
L_50 :
L_51 ,
( ( V_40 >= V_45 ) &&
( V_40 <= V_46 ) ) ?
L_52 :
L_51 ,
( ( V_40 >= V_47 ) &&
( V_40 <= V_48 ) ) ?
L_53 :
L_51 ,
( V_40 >= V_49 ) ? L_54 : L_51 ,
( V_41 ) ? ( ( V_40 - V_42 ) % 10 ) :
( ( V_40 >= V_49 ) ?
( V_40 - V_49 ) :
( ( V_40 <= V_50 ) ?
V_39 [ V_40 ] :
0 ) ) ,
( V_43 ) ? L_55 : L_56 ,
( V_40 >= V_49 ) ? L_51 : L_57 ) ;
}
void F_11 ( void * V_1 , T_2 * V_19 , T_2 V_20 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
struct V_14 * V_15 = & V_7 -> V_16 ;
T_2 V_51 = V_19 [ 1 ] ;
T_2 V_37 = V_19 [ 0 ] ;
T_2 V_40 = V_37 & 0x7f ;
T_2 V_52 ;
if ( V_20 >= 4 ) {
if ( V_19 [ 3 ] == 0 ) {
F_6 ( V_7 , V_35 ,
L_58 , V_51 ) ;
} else if ( V_19 [ 3 ] == 0xff ) {
F_6 ( V_7 , V_35 ,
L_59 , V_51 ) ;
} else if ( V_19 [ 3 ] == 1 ) {
F_6 ( V_7 , V_35 ,
L_60 , V_51 ) ;
} else if ( V_19 [ 3 ] == 2 ) {
F_6 ( V_7 , V_35 ,
L_61 , V_51 ) ;
} else if ( V_19 [ 3 ] == 3 ) {
F_6 ( V_7 , V_35 ,
L_62 , V_51 ) ;
} else if ( V_19 [ 3 ] == 4 ) {
F_6 ( V_7 , V_35 ,
L_63 , V_51 ) ;
} else if ( V_19 [ 3 ] == 5 ) {
F_6 ( V_7 , V_35 ,
L_64 , V_51 ) ;
}
} else {
F_6 ( V_7 , V_35 , L_65 ,
V_51 ) ;
}
F_10 ( V_7 , V_37 , V_35 ) ;
V_15 -> V_53 [ V_51 ] = V_37 ;
V_52 = F_12 ( V_7 , V_40 ) ;
if ( ( V_7 -> V_54 ) ||
( ( V_52 > V_15 -> V_55 ) &&
( V_15 -> V_56 == 1 ) ) ) {
F_13 ( V_7 , V_40 ) ;
V_15 -> V_56 = 0 ;
}
}
void F_14 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
struct V_14 * V_15 = & V_7 -> V_16 ;
V_15 -> V_57 = false ;
}
void F_15 ( void * V_1 ) {}
void F_16 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
if ( V_7 -> V_25 == V_58 ) {
T_1 V_59 ;
V_59 = F_17 ( V_7 , 0x4c8 , V_60 ) ;
F_18 ( V_7 , 0x4cc , V_61 , ( V_59 - 1 ) ) ;
}
}
void F_19 ( void * V_1 , T_2 V_18 ,
T_2 V_17
)
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
struct V_14 * V_15 = & V_7 -> V_16 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_17 = V_17 ;
F_6 ( V_7 , V_62 ,
L_66 ,
( ( V_17 == 0 ) ?
L_4 :
( ( V_18 ) ? L_5 : L_6 ) ) ,
V_17 ) ;
}
static void F_20 ( void * V_1 ) {}
static void F_21 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
struct V_14 * V_15 = & V_7 -> V_16 ;
struct V_63 * V_64 = (struct V_63 * ) V_7 -> V_65 ;
struct V_66 * V_67 = V_66 ( V_64 ) ;
struct V_68 * V_69 ;
int V_11 ;
int V_70 = 0xff ;
unsigned long V_71 = 0 , V_72 = 0 ;
T_2 V_73 = 0 , V_74 = 0 , V_75 = 0 ;
T_2 V_8 [ V_76 ] = { 0 } ;
T_2 V_77 = V_76 ;
T_2 V_51 = 0 ;
if ( ! V_7 -> V_78 )
return;
for ( V_11 = 0 ; V_11 < V_79 ; V_11 ++ ) {
V_69 = (struct V_68 * ) V_7 -> V_80 [ V_11 ] ;
if ( ! F_22 ( V_69 ) )
continue;
if ( F_23 ( V_69 -> V_81 ) ||
F_24 ( V_69 -> V_81 ) )
continue;
if ( V_69 -> V_82 . V_83 == ( - 1 ) )
continue;
if ( V_69 -> V_82 . V_83 <
V_70 )
V_70 =
V_69 -> V_82 . V_83 ;
V_71 = V_64 -> V_84 . V_85 ;
V_72 = V_64 -> V_84 . V_86 ;
if ( V_72 > ( V_71 * 6 ) )
V_73 = 1 ;
else
V_73 = 0 ;
if ( V_67 -> V_87 == V_88 ||
V_67 -> V_87 == V_89 ) {
struct V_90 * V_91 = F_25 (
( void * ) V_69 , struct V_90 , V_92 ) ;
V_51 = V_91 -> V_93 + 1 ;
}
V_8 [ 0 ] = V_51 ;
V_8 [ 2 ] =
V_69 -> V_82 . V_83 & 0x7F ;
if ( V_73 )
V_8 [ 3 ] |= V_94 ;
if ( V_75 )
V_8 [ 3 ] |= V_95 ;
if ( V_74 )
V_8 [ 3 ] |= V_96 ;
if ( V_7 -> V_34 )
V_8 [ 3 ] |= V_97 ;
if ( V_69 -> V_82 . V_98 == V_99 ) {
V_8 [ 3 ] |= V_100 ;
V_69 -> V_82 . V_98 = V_101 ;
}
V_8 [ 4 ] = ( V_15 -> V_17 & 0x7f ) |
( V_15 -> V_18 << 7 ) ;
F_3 ( V_7 , V_102 , V_77 ,
V_8 ) ;
}
if ( V_70 != 0xff )
V_7 -> V_103 = V_70 ;
}
static void F_26 ( void * V_1 ) {}
void F_27 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
if ( ! ( V_7 -> V_31 & V_104 ) )
return;
switch ( V_7 -> V_105 ) {
case V_106 :
F_20 ( V_7 ) ;
break;
case V_107 :
F_21 ( V_7 ) ;
break;
case V_108 :
F_26 ( V_7 ) ;
break;
default:
break;
}
}
void F_28 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
struct V_109 * V_110 = & V_7 -> V_111 ;
V_110 -> type = V_112 ;
if ( V_110 -> type == V_112 )
V_7 -> V_113 = true ;
else
V_7 -> V_113 = false ;
V_110 -> V_114 = V_115 ;
V_110 -> V_116 = 35 ;
V_110 -> V_117 = false ;
V_110 -> V_118 = 50 ;
V_110 -> V_119 = 20 ;
}
void F_29 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
struct V_14 * V_15 = & V_7 -> V_16 ;
if ( ! V_7 -> V_78 )
return;
if ( ! ( V_7 -> V_31 & V_120 ) ) {
F_6 ( V_7 , V_62 ,
L_67 , V_121 ) ;
return;
}
V_15 -> V_122 ++ ;
switch ( V_7 -> V_105 ) {
case V_106 :
F_30 ( V_7 ) ;
break;
case V_107 :
F_31 ( V_7 ) ;
break;
case V_108 :
F_32 ( V_7 ) ;
break;
}
}
static T_2 F_33 ( void * V_1 , T_2 V_123 )
{
if ( V_123 == V_124 )
V_123 = V_125 ;
else if ( V_123 == V_126 )
V_123 = V_127 ;
else if ( V_123 == V_128 )
V_123 = V_129 ;
return V_123 ;
}
static T_2 F_34 ( void * V_1 , T_2 V_130 )
{
if ( V_130 == V_131 )
V_130 = V_132 ;
else if ( V_130 == V_133 )
V_130 = V_134 ;
else if ( V_130 == V_135 )
V_130 = V_136 ;
else if ( V_130 == V_137 )
V_130 = V_138 ;
else if ( V_130 == V_139 )
V_130 = V_140 ;
else if ( V_130 == V_141 )
V_130 = V_142 ;
else if ( V_130 == V_143 )
V_130 = V_144 ;
else if ( V_130 == V_145 )
V_130 = V_132 ;
else if ( V_130 == V_146 )
V_130 = V_147 ;
return V_130 ;
}
static T_1 F_35 ( void * V_1 , T_1 V_148 )
{
return V_148 ;
}
T_2 F_36 ( void * V_1 , T_1 V_148 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
T_2 V_149 = 0 ;
if ( ( V_148 == V_150 ) ||
( V_148 == V_151 ) ||
( V_148 == V_152 ) ) {
V_149 = 1 ;
}
F_6 ( V_7 , V_62 ,
L_68 ,
V_148 , V_149 ) ;
return V_149 ;
}
T_2 F_37 ( void * V_1 , T_1 V_148 , T_2 V_130 , T_2 V_153 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
T_2 V_154 = 0 ;
T_2 V_155 ;
T_2 V_156 ;
V_155 = F_33 ( V_7 , V_153 ) ;
V_156 = F_34 ( V_7 , V_130 ) ;
V_148 = F_35 ( V_7 , V_148 ) ;
F_6 (
V_7 , V_62 ,
L_69 ,
V_148 , V_156 , V_155 ) ;
switch ( V_148 ) {
case V_157 : {
if ( V_155 == V_127 ) {
if ( V_156 == V_138 )
V_154 = V_158 ;
else if ( V_156 == V_136 )
V_154 = V_159 ;
else
V_154 = V_160 ;
} else {
if ( V_156 == V_138 )
V_154 = V_161 ;
else if ( V_156 == V_136 )
V_154 = V_162 ;
else
V_154 = V_160 ;
}
} break;
case V_163 : {
if ( V_156 == V_138 )
V_154 = V_164 ;
else if ( V_156 == V_136 )
V_154 = V_165 ;
else
V_154 = V_160 ;
}
break;
case V_166 :
V_154 = V_167 ;
break;
case V_168 :
V_154 = V_169 ;
break;
case V_170 :
V_154 = V_171 ;
break;
case V_150 :
case V_152 : {
if ( V_156 == V_138 )
V_154 = V_172 ;
else if ( V_156 == V_136 )
V_154 = V_173 ;
else
V_154 = V_174 ;
} break;
case V_151 : {
if ( V_155 >= V_129 ) {
if ( V_156 == V_138 )
V_154 = V_172 ;
else if ( V_156 == V_136 )
V_154 = V_173 ;
else
V_154 = V_174 ;
} else {
if ( V_156 == V_138 )
V_154 = V_175 ;
else if ( V_156 == V_136 )
V_154 = V_176 ;
else
V_154 = V_174 ;
}
} break;
default:
V_154 = 0 ;
break;
}
F_6 ( V_7 , V_62 , L_70 ,
V_154 ) ;
return V_154 ;
}
void F_38 ( void * V_1 , T_1 V_148 , T_2 V_130 ,
T_2 V_123 , T_2 V_177 , T_2 V_178 ,
T_1 * V_179 , T_1 * V_180 ,
T_2 V_181 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
T_2 V_156 ;
T_2 V_155 ;
T_1 V_182 = * V_180 ,
V_183 = * V_179 ;
V_148 = F_35 ( V_7 , V_148 ) ;
V_156 = F_34 ( V_7 , V_130 ) ;
V_155 = F_33 ( V_7 , V_123 ) ;
F_6 ( V_7 , V_62 ,
L_71 ,
V_183 , V_182 ) ;
switch ( V_148 ) {
case V_170 : {
V_182 &= 0x0000000f ;
} break;
case V_166 : {
V_182 &= 0x00000ff5 ;
} break;
case V_168 : {
V_182 &= 0x00000ff0 ;
} break;
case V_157 :
case V_163 : {
if ( V_177 )
V_156 = V_138 ;
if ( V_156 == V_138 ) {
if ( V_155 == V_127 )
V_182 &= 0x000ff015 ;
else
V_182 &= 0x000ff005 ;
} else if ( V_156 == V_136 ||
V_156 == V_134 ||
V_156 == V_184 ) {
if ( V_155 == V_127 )
V_182 &= 0x0ffff015 ;
else
V_182 &= 0x0ffff005 ;
} else {
V_182 &= 0xfffff015 ;
V_183 &= 0xf ;
}
} break;
case V_151 : {
if ( V_156 == V_138 ) {
V_182 &= 0x003ff015 ;
} else if ( V_156 == V_136 ||
V_156 == V_134 ||
V_156 == V_184 ) {
V_182 &= 0xfffff015 ;
} else {
V_182 &= 0xfffff010 ;
V_183 &= 0x3ff ;
}
if ( V_155 ==
V_125 ) {
V_182 &= 0x7fdfffff ;
V_183 &= 0x1ff ;
}
} break;
case V_150 : {
if ( V_156 == V_138 ) {
V_182 &= 0x003ff010 ;
} else if ( V_156 == V_136 ||
V_156 == V_134 ||
V_156 == V_184 ) {
V_182 &= 0xfffff010 ;
} else {
V_182 &= 0xfffff010 ;
V_183 &= 0x3ff ;
}
if ( V_155 ==
V_125 ) {
V_182 &= 0x7fdfffff ;
V_183 &= 0x1ff ;
}
} break;
default:
break;
}
if ( V_148 != V_170 ) {
if ( V_181 == 0 )
V_182 &= 0xffffffff ;
else if ( V_181 == 1 )
V_182 &= 0xfffffff0 ;
else if ( V_181 == 2 )
V_182 &= 0xffffefe0 ;
else if ( V_181 == 3 )
V_182 &= 0xffffcfc0 ;
else if ( V_181 == 4 )
V_182 &= 0xffff8f80 ;
else if ( V_181 >= 5 )
V_182 &= 0xffff0f00 ;
}
if ( V_178 )
V_182 &= 0xfffffff0 ;
F_6 (
V_7 , V_62 ,
L_72 ,
V_148 , V_156 , V_155 , V_177 ,
V_181 ) ;
* V_180 = V_182 ;
* V_179 = V_183 ;
F_6 ( V_7 , V_62 ,
L_73 ,
* V_179 , * V_180 ) ;
}
T_2 F_39 ( void * V_1 , T_1 V_185 , T_2 V_114 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
T_2 V_186 [ V_187 ] = {
20 , 34 , 38 , 42 ,
46 , 50 , 100 } ;
T_2 V_188 = 0 ;
T_2 V_11 ;
F_6 (
V_7 , V_62 ,
L_74 ,
V_114 , V_186 [ 0 ] , V_186 [ 1 ] ,
V_186 [ 2 ] , V_186 [ 3 ] ,
V_186 [ 4 ] , V_186 [ 5 ] ) ;
for ( V_11 = 0 ; V_11 < V_187 ; V_11 ++ ) {
if ( V_11 >= ( V_114 ) )
V_186 [ V_11 ] += V_189 ;
}
F_6 (
V_7 , V_62 ,
L_75 ,
V_185 , V_186 [ 0 ] , V_186 [ 1 ] ,
V_186 [ 2 ] , V_186 [ 3 ] ,
V_186 [ 4 ] , V_186 [ 5 ] ) ;
for ( V_11 = 0 ; V_11 < V_187 ; V_11 ++ ) {
if ( V_185 < V_186 [ V_11 ] ) {
V_188 = V_11 ;
break;
}
}
return V_188 ;
}
void F_30 ( void * V_1 ) {}
void F_31 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
struct V_14 * V_15 = & V_7 -> V_16 ;
void * V_65 = V_7 -> V_65 ;
T_1 V_11 ;
struct V_68 * V_69 ;
T_2 V_190 ;
if ( ! V_7 -> V_113 ) {
F_6 (
V_7 , V_62 ,
L_76 ,
V_121 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_79 ; V_11 ++ ) {
V_69 = V_7 -> V_80 [ V_11 ] ;
if ( ! F_22 ( V_69 ) )
continue;
if ( F_23 ( V_69 -> V_81 ) )
continue;
else if ( F_24 ( V_69 -> V_81 ) )
continue;
V_190 = F_39 (
V_7 , V_69 -> V_82 . V_83 ,
V_69 -> V_191 ) ;
if ( ( V_69 -> V_191 != V_190 ) ||
( V_15 -> V_122 >=
V_192 ) ) {
V_15 -> V_122 = 0 ;
F_6 (
V_7 , V_62 ,
L_77 ,
V_69 -> V_191 , V_190 ,
V_69 -> V_82 . V_83 ) ;
V_69 -> V_191 = V_190 ;
F_40 ( V_65 , V_69 ,
V_69 -> V_191 ) ;
} else {
F_6 ( V_7 , V_62 ,
L_78 ,
V_190 ) ;
}
}
}
void F_32 ( void * V_1 ) {}
void F_41 ( void * V_1 ) {}
T_2 F_12 ( void * V_1 , T_2 V_40 )
{
T_2 V_52 = 0 ;
if ( V_40 >= V_193 ) {
V_40 -= V_193 ;
} else if ( V_40 >= V_47 ) {
V_40 -= V_47 ;
} else if ( V_40 >= V_45 ) {
V_40 -= V_45 ;
} else if ( V_40 >= V_42 ) {
V_40 -= V_42 ;
} else if ( V_40 >= V_194 ) {
V_40 -= V_194 ;
} else if ( V_40 >= V_195 ) {
V_40 -= V_195 ;
} else if ( V_40 >= V_196 ) {
V_40 -= V_196 ;
}
V_52 = V_40 ;
return V_52 ;
}
static void F_42 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
struct V_14 * V_15 = & V_7 -> V_16 ;
T_3 V_51 ;
T_2 V_197 ;
T_2 V_198 = 0 ;
V_15 -> V_55 = 0 ;
V_15 -> V_56 = 1 ;
if ( V_7 -> V_199 != 0 ) {
for ( V_51 = 0 ; V_51 < V_79 ; V_51 ++ ) {
V_197 = F_12 (
V_7 , ( ( V_15 -> V_53 [ V_51 ] ) & 0x7f ) ) ;
if ( V_197 >=
( V_15 -> V_55 ) ) {
V_15 -> V_55 =
V_197 ;
V_15 -> V_200 = V_51 ;
}
V_198 ++ ;
if ( V_198 == V_7 -> V_199 )
break;
}
F_6 (
V_7 , V_35 ,
L_79 ,
( V_15 -> V_200 ) ,
( V_15 -> V_55 ) ) ;
}
}
void F_43 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
F_42 ( V_7 ) ;
F_9 ( V_7 ) ;
F_7 ( V_7 ) ;
F_29 ( V_7 ) ;
F_41 ( V_7 ) ;
}
void F_44 ( void * V_1 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
struct V_14 * V_15 = & V_7 -> V_16 ;
V_15 -> V_200 = 0 ;
V_15 -> V_55 = 0 ;
V_15 -> V_17 = 0 ;
V_15 -> V_18 = 0 ;
}
T_2 F_45 ( void * V_1 , T_2 V_201 , bool V_202 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
T_2 V_203 = V_204 ;
if ( V_202 ) {
V_203 = V_205 ;
} else {
switch ( V_201 ) {
case V_48 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_46 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_44 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_50 :
case V_234 :
case V_235 :
case V_236 :
V_203 = V_236 ;
break;
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
V_203 = V_248 ;
break;
case V_47 :
case V_45 :
case V_42 :
case V_196 :
case V_49 :
case V_249 :
case V_204 :
V_203 = V_204 ;
break;
case V_250 :
case V_251 :
case V_252 :
case V_205 :
V_203 = V_205 ;
break;
default:
V_203 = V_204 ;
break;
}
}
if ( * V_7 -> V_253 == 1 ) {
if ( V_203 < V_204 )
V_203 = V_204 ;
}
return V_203 ;
}
static void F_46 ( struct V_6 * V_7 ) {}
void F_47 ( void * V_1 , bool V_254 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
if ( V_7 -> V_25 == V_255 ||
V_7 -> V_25 == V_256 ||
V_7 -> V_25 == V_257 ||
V_7 -> V_25 == V_258 ||
V_7 -> V_25 == V_259 ||
V_7 -> V_25 == V_260 ||
V_7 -> V_25 == V_261 )
V_7 -> V_262 = V_254 ;
F_46 ( V_7 ) ;
}
void F_13 ( void * V_1 , T_2 V_37 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
F_6 ( V_7 , V_263 , L_80 ,
V_37 ) ;
V_7 -> V_201 = V_37 ;
}
bool F_48 ( void * V_1 , T_4 V_185 , bool V_264 ,
T_2 * V_265 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
struct V_109 * V_266 = & V_7 -> V_111 ;
const T_2 V_267 = 5 ;
T_2 V_268 = V_266 -> V_118 ;
T_2 V_269 = V_266 -> V_119 ;
T_2 V_114 ;
F_6 ( V_7 , V_62 ,
L_81 , V_185 ,
* V_265 ) ;
F_6 ( V_7 , V_62 ,
L_82 ,
V_268 , V_269 ) ;
switch ( * V_265 ) {
case V_115 :
case V_270 :
break;
case V_271 :
V_268 += V_267 ;
break;
case V_272 :
V_268 += V_267 ;
V_269 += V_267 ;
break;
default:
F_49 ( true , L_83 , * V_265 ) ;
break;
}
if ( V_185 > V_268 )
V_114 = V_270 ;
else if ( V_185 > V_269 )
V_114 = V_271 ;
else
V_114 = V_272 ;
F_6 ( V_7 , V_62 ,
L_84 ,
V_268 , V_269 ) ;
if ( * V_265 != V_114 || V_264 ) {
F_6 ( V_7 , V_62 ,
L_85 , * V_265 ,
V_114 ) ;
* V_265 = V_114 ;
return true ;
}
return false ;
}
