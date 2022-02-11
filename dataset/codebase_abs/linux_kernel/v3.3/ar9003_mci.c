static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
return;
F_3 ( V_2 , V_3 ,
V_4 , 1 ) ;
F_4 ( 1 ) ;
F_3 ( V_2 , V_3 ,
V_4 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_6 , int V_7 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
while ( V_7 ) {
if ( F_7 ( V_2 , V_5 ) & V_6 ) {
F_8 ( V_2 , V_5 , V_6 ) ;
if ( V_5 == V_10 ) {
if ( V_6 &
V_11 )
F_1 ( V_2 ) ;
if ( V_6 &
( V_12 |
V_13 ) )
F_8 ( V_2 , V_14 ,
V_15 ) ;
F_8 ( V_2 , V_14 ,
V_16 ) ;
}
break;
}
F_4 ( 10 ) ;
V_7 -= 10 ;
if ( V_7 < 0 )
break;
}
if ( V_7 <= 0 ) {
F_9 ( V_9 , V_17 ,
L_1 ,
V_5 , V_6 ) ;
F_9 ( V_9 , V_17 ,
L_2 ,
F_7 ( V_2 , V_14 ) ,
F_7 ( V_2 , V_10 ) ) ;
V_7 = 0 ;
}
return V_7 ;
}
void F_10 ( struct V_1 * V_2 , bool V_18 )
{
T_1 V_19 [ 4 ] = { 0xffffffff , 0xffffffff , 0xffffffff , 0xffffff00 } ;
if ( ! V_20 )
return;
F_11 ( V_2 , V_21 , 0 , V_19 , 16 ,
V_18 , false ) ;
F_4 ( 5 ) ;
}
void F_12 ( struct V_1 * V_2 , bool V_18 )
{
T_1 V_19 = 0x00000000 ;
if ( ! V_20 )
return;
F_11 ( V_2 , V_22 , 0 , & V_19 , 1 ,
V_18 , false ) ;
}
static void F_13 ( struct V_1 * V_2 , bool V_18 )
{
F_11 ( V_2 , V_23 , V_24 ,
NULL , 0 , V_18 , false ) ;
F_4 ( 5 ) ;
}
void F_14 ( struct V_1 * V_2 , bool V_18 )
{
if ( ! V_20 )
return;
F_11 ( V_2 , V_25 , V_24 ,
NULL , 0 , V_18 , false ) ;
}
static void F_15 ( struct V_1 * V_2 , bool V_18 )
{
T_1 V_19 = 0x70000000 ;
F_11 ( V_2 , V_26 , 0 , & V_19 , 1 ,
V_18 , false ) ;
}
static void F_16 ( struct V_1 * V_2 , bool V_18 )
{
F_11 ( V_2 , V_27 ,
V_24 ,
NULL , 0 , V_18 , false ) ;
}
static void F_17 ( struct V_1 * V_2 ,
bool V_18 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ! V_29 -> V_31 &&
( V_29 -> V_32 != V_33 ) ) {
F_9 ( V_9 , V_17 , L_3 ) ;
F_18 ( V_19 ,
V_34 , V_35 ) ;
F_11 ( V_2 , V_36 , 0 , V_19 , 16 ,
V_18 , true ) ;
}
}
static void F_19 ( struct V_1 * V_2 ,
bool V_18 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_9 ( V_9 , V_17 , L_4 ) ;
F_18 ( V_19 , V_34 ,
V_37 ) ;
* ( ( ( V_38 * ) V_19 ) + V_39 ) =
V_29 -> V_40 ;
* ( ( ( V_38 * ) V_19 ) + V_41 ) =
V_29 -> V_42 ;
F_11 ( V_2 , V_36 , 0 , V_19 , 16 , V_18 , true ) ;
}
static void F_20 ( struct V_1 * V_2 ,
bool V_18 )
{
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 * V_19 = & V_29 -> V_43 [ 0 ] ;
if ( ( V_29 -> V_44 == true ) &&
( V_29 -> V_32 != V_33 ) ) {
F_18 ( V_19 ,
V_34 , V_45 ) ;
F_11 ( V_2 , V_36 , 0 , V_19 , 16 ,
V_18 , true ) ;
F_18 ( V_19 , 0xff , 0xff ) ;
}
}
static void F_21 ( struct V_1 * V_2 ,
bool V_18 , V_38 V_46 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
bool V_47 = ! ! ( V_46 & ( V_48 |
V_49 ) ) ;
if ( V_29 -> V_32 != V_33 ) {
F_9 ( V_9 , V_17 , L_5 ,
V_46 ) ;
F_18 ( V_19 ,
V_34 , V_50 ) ;
* ( ( ( V_38 * ) V_19 ) + V_51 ) = V_46 ;
if ( ! F_11 ( V_2 , V_36 , 0 , V_19 , 16 ,
V_18 , true ) ) {
if ( V_47 ) {
V_29 -> V_52 = true ;
F_9 ( V_9 , V_17 ,
L_6 ) ;
}
}
if ( V_47 )
V_29 -> V_53 = false ;
}
}
void F_22 ( struct V_1 * V_2 , bool V_54 ,
bool V_18 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ! V_20 )
return;
F_9 ( V_9 , V_17 , L_7 ,
( V_54 ) ? L_8 : L_9 ) ;
F_18 ( V_19 ,
V_34 , V_55 ) ;
if ( V_54 ) {
V_29 -> V_53 = true ;
V_29 -> V_56 = true ;
V_29 -> V_52 = true ;
* ( ( ( V_38 * ) V_19 ) + V_57 ) =
V_58 ;
} else
* ( ( ( V_38 * ) V_19 ) + V_57 ) =
V_59 ;
F_11 ( V_2 , V_36 , 0 , V_19 , 16 , V_18 , true ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 V_60 ;
T_1 V_61 = 150 ;
V_29 -> V_32 = V_33 ;
V_60 = F_7 ( V_2 , V_62 ) ;
F_8 ( V_2 , V_62 , 0 ) ;
F_8 ( V_2 , V_10 ,
F_7 ( V_2 , V_10 ) ) ;
F_8 ( V_2 , V_14 ,
F_7 ( V_2 , V_14 ) ) ;
F_9 ( V_9 , V_17 , L_10 ) ;
F_9 ( V_9 , V_17 , L_11 ) ;
F_10 ( V_2 , true ) ;
if ( F_24 ( V_2 ) )
F_4 ( 252 ) ;
F_9 ( V_9 , V_17 , L_12 ) ;
F_13 ( V_2 , true ) ;
if ( F_5 ( V_2 , V_10 ,
V_13 , 500 ) ) {
F_9 ( V_9 , V_17 , L_13 ) ;
V_29 -> V_32 = V_63 ;
if ( F_24 ( V_2 ) )
F_4 ( 10 ) ;
F_9 ( V_9 , V_17 , L_14 ) ;
F_14 ( V_2 , true ) ;
F_4 ( 10 ) ;
F_8 ( V_2 , V_64 , 0xFFFFFFFF ) ;
F_8 ( V_2 , V_65 , 0xFFFFFFFF ) ;
F_8 ( V_2 , V_66 , 0xFFFFFFFF ) ;
F_8 ( V_2 , V_67 , 0xFFFFFFFF ) ;
F_8 ( V_2 , V_68 , 0X000000FF ) ;
F_8 ( V_2 , V_10 ,
V_69 ) ;
F_8 ( V_2 , V_14 ,
V_70 ) ;
if ( F_24 ( V_2 ) || V_29 -> V_71 ) {
F_9 ( V_9 , V_17 , L_15 ) ;
F_12 ( V_2 , true ) ;
F_4 ( 5 ) ;
}
if ( F_24 ( V_2 ) || ( V_29 -> V_71 &&
! V_29 -> V_72 ) ) {
if ( F_5 ( V_2 ,
V_10 ,
V_73 ,
V_61 ) )
F_9 ( V_9 , V_17 ,
L_16 ) ;
else
F_9 ( V_9 , V_17 ,
L_17 ) ;
}
if ( F_24 ( V_2 ) ) {
F_9 ( V_9 , V_17 ,
L_18 ) ;
F_10 ( V_2 , true ) ;
F_4 ( 252 ) ;
}
}
if ( ( V_29 -> V_32 == V_63 ) &&
( F_25 ( V_2 , V_10 ,
V_13 ) ) &&
( F_25 ( V_2 , V_10 ,
V_12 ) == 0 ) ) {
F_8 ( V_2 , V_10 ,
V_13 ) ;
F_8 ( V_2 , V_14 ,
V_15 ) ;
}
F_8 ( V_2 , V_62 , V_60 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( ! V_20 )
return;
F_8 ( V_2 , V_62 , 0 ) ;
F_8 ( V_2 , V_74 , 0 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( ! V_20 )
return;
F_8 ( V_2 , V_62 , V_75 ) ;
F_8 ( V_2 , V_74 ,
V_76 ) ;
}
bool F_28 ( struct V_1 * V_2 , T_1 V_77 )
{
T_1 V_78 ;
if ( ! V_20 )
return false ;
V_78 = F_7 ( V_2 , V_10 ) ;
return ( ( V_78 & V_77 ) == V_77 ) ;
}
void F_29 ( struct V_1 * V_2 , T_1 * V_79 ,
T_1 * V_80 )
{
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
if ( ! V_20 )
return;
* V_79 = V_29 -> V_79 ;
* V_80 = V_29 -> V_80 ;
V_29 -> V_79 = 0 ;
V_29 -> V_80 = 0 ;
}
void F_30 ( struct V_1 * V_2 , bool V_71 )
{
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
if ( ! V_20 )
return;
if ( ! V_29 -> V_72 &&
( V_29 -> V_71 != V_71 ) )
V_29 -> V_72 = true ;
V_29 -> V_71 = V_71 ;
}
static bool F_31 ( struct V_1 * V_2 , T_1 V_81 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 * V_19 ;
T_1 V_82 , V_83 ;
if ( V_81 == V_84 )
return false ;
V_83 = V_81 << 4 ;
V_19 = ( T_1 * ) ( V_29 -> V_85 + V_83 ) ;
V_82 = F_32 ( V_19 ) ;
if ( V_82 == V_86 ) {
F_9 ( V_9 , V_17 , L_19 ) ;
return false ;
}
return true ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
if ( V_29 -> V_87 & V_88 ) {
F_34 ( V_2 , 3 ,
V_89 ) ;
F_34 ( V_2 , 2 , V_90 ) ;
F_34 ( V_2 , 1 , V_91 ) ;
F_34 ( V_2 , 0 , V_92 ) ;
} else if ( V_29 -> V_87 & V_93 ) {
F_34 ( V_2 , 3 , V_94 ) ;
F_34 ( V_2 , 2 , V_95 ) ;
F_34 ( V_2 , 1 , V_96 ) ;
F_34 ( V_2 , 0 , V_97 ) ;
F_34 ( V_2 , 5 , V_98 ) ;
} else if ( V_29 -> V_87 & V_99 ) {
F_34 ( V_2 , 3 , V_96 ) ;
F_34 ( V_2 , 2 , V_97 ) ;
F_34 ( V_2 , 1 , V_91 ) ;
F_34 ( V_2 , 0 , V_92 ) ;
} else
return;
F_35 ( V_2 , V_100 , V_101 ) ;
if ( F_36 ( V_2 ) ) {
F_3 ( V_2 , V_102 ,
V_103 , 1 ) ;
F_3 ( V_2 , V_102 ,
V_104 , 0 ) ;
F_35 ( V_2 , V_105 ,
V_106 ) ;
}
F_3 ( V_2 , V_107 , V_108 , 0 ) ;
F_3 ( V_2 , V_107 , V_109 , 1 ) ;
F_8 ( V_2 , V_110 , 0x4b ) ;
F_3 ( V_2 , V_111 , V_112 , 0x03 ) ;
F_3 ( V_2 , V_111 , V_113 , 0x01 ) ;
F_3 ( V_2 , V_114 , V_115 , 0x02 ) ;
F_3 ( V_2 , V_114 , V_116 , 0x03 ) ;
F_3 ( V_2 , V_117 ,
V_118 , 0x07 ) ;
}
static bool F_37 ( struct V_1 * V_2 , bool V_18 ,
V_38 V_119 , T_1 V_120 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
T_1 V_121 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_18 ( V_121 ,
V_34 , V_122 ) ;
* ( ( ( V_38 * ) V_121 ) + V_123 ) = V_119 ;
* ( ( ( V_38 * ) V_121 ) + V_124 + 0 ) = V_120 & 0xFF ;
* ( ( ( V_38 * ) V_121 ) + V_124 + 1 ) = ( V_120 >> 8 ) & 0xFF ;
* ( ( ( V_38 * ) V_121 ) + V_124 + 2 ) = ( V_120 >> 16 ) & 0xFF ;
* ( ( ( V_38 * ) V_121 ) + V_124 + 3 ) = ( V_120 >> 24 ) & 0xFF ;
F_9 ( V_9 , V_17 ,
L_20 ,
V_119 == V_125 ? L_21 :
V_119 == V_126 ? L_22 : L_23 ,
V_120 ) ;
return F_11 ( V_2 , V_36 , 0 , V_121 , 16 ,
V_18 , true ) ;
}
void F_38 ( struct V_1 * V_2 , bool V_127 , bool V_71 ,
bool V_128 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 V_129 , V_130 ;
if ( ! V_20 )
return;
F_9 ( V_9 , V_17 , L_24 ,
V_128 , V_71 ) ;
if ( ! V_29 -> V_131 && ! V_29 -> V_132 ) {
F_9 ( V_9 , V_17 ,
L_25 ) ;
return;
}
if ( F_7 ( V_2 , V_133 ) == 0xdeadbeef ) {
F_9 ( V_9 , V_17 , L_26 ) ;
return;
}
F_8 ( V_2 , V_134 , V_29 -> V_131 ) ;
F_8 ( V_2 , V_135 , V_29 -> V_136 ) ;
F_8 ( V_2 , V_137 , V_29 -> V_132 ) ;
V_129 = F_39 ( 1 , V_138 ) |
F_39 ( 1 , V_139 ) |
F_39 ( 1 , V_140 ) |
F_39 ( 1 , V_141 ) |
F_39 ( 2 , V_142 ) |
F_39 ( 3 , V_143 ) |
F_39 ( 0 , V_144 ) |
F_39 ( 0 , V_145 ) |
F_39 ( 0 , V_146 ) ;
if ( V_71 && ( F_2 ( V_2 ) ) &&
! ( V_29 -> V_87 & V_147 ) ) {
V_129 |= F_39 ( 1 , V_146 ) ;
F_9 ( V_9 , V_17 , L_27 ) ;
if ( ! ( V_29 -> V_87 &
V_148 ) ) {
V_130 = F_40 ( V_29 -> V_87 ,
V_149 ) ;
V_130 &= 7 ;
V_129 |= F_39 ( 1 ,
V_150 ) ;
V_129 |= F_39 ( V_130 , V_151 ) ;
F_3 ( V_2 , V_152 ,
V_153 , 1 ) ;
F_3 ( V_2 , V_152 ,
V_154 , 1 ) ;
} else
F_9 ( V_9 , V_17 , L_28 ) ;
} else
F_9 ( V_9 , V_17 , L_29 ) ;
if ( F_24 ( V_2 ) )
V_129 |= F_39 ( 1 , V_155 ) ;
F_8 ( V_2 , V_133 , V_129 ) ;
if ( F_2 ( V_2 ) ) {
F_35 ( V_2 , V_102 ,
V_156 ) ;
F_3 ( V_2 , V_157 ,
V_158 , 20 ) ;
}
F_3 ( V_2 , V_107 , V_159 , 1 ) ;
F_3 ( V_2 , V_160 , V_161 , 0 ) ;
V_130 = F_40 ( V_29 -> V_87 , V_162 ) ;
F_3 ( V_2 , V_163 , V_164 , V_130 ) ;
F_35 ( V_2 , V_133 , V_165 ) ;
V_129 = F_7 ( V_2 , V_3 ) ;
V_129 |= F_39 ( 1 , V_166 ) ;
F_8 ( V_2 , V_3 , V_129 ) ;
F_4 ( 1 ) ;
V_129 &= ~ F_39 ( 1 , V_166 ) ;
F_8 ( V_2 , V_3 , V_129 ) ;
if ( V_128 ) {
F_41 ( V_2 ) ;
F_4 ( 100 ) ;
}
V_129 |= F_39 ( 1 , V_167 ) ;
F_8 ( V_2 , V_3 , V_129 ) ;
F_4 ( 1 ) ;
V_129 &= ~ F_39 ( 1 , V_167 ) ;
F_8 ( V_2 , V_3 , V_129 ) ;
F_42 ( V_2 , V_168 , NULL ) ;
F_8 ( V_2 , V_169 ,
( F_39 ( 0xe801 , V_170 ) |
F_39 ( 0x0000 , V_171 ) ) ) ;
F_43 ( V_2 , V_163 ,
V_172 ) ;
if ( F_36 ( V_2 ) )
F_33 ( V_2 ) ;
V_29 -> V_173 = true ;
F_23 ( V_2 ) ;
if ( V_127 )
F_27 ( V_2 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
if ( ! V_20 )
return;
F_8 ( V_2 , V_169 , 0xffff0000 ) ;
F_8 ( V_2 , V_174 , 0xffffffff ) ;
F_8 ( V_2 , V_175 , 0xffffffff ) ;
F_8 ( V_2 , V_176 , 0xffffffff ) ;
F_8 ( V_2 , V_177 , 0xffffffff ) ;
F_35 ( V_2 , V_163 , V_172 ) ;
F_4 ( 10 ) ;
F_9 ( V_9 , V_17 , L_30 ) ;
F_15 ( V_2 , true ) ;
F_4 ( 5 ) ;
F_9 ( V_9 , V_17 , L_31 ) ;
F_16 ( V_2 , true ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 V_178 ;
if ( ! V_20 )
return;
V_178 = F_42 ( V_2 , V_179 , NULL ) ;
if ( V_29 -> V_32 != V_178 ) {
F_9 ( V_9 , V_17 ,
L_32 ,
V_29 -> V_32 , V_178 ) ;
V_29 -> V_32 = V_178 ;
}
if ( V_29 -> V_32 != V_33 ) {
F_17 ( V_2 , true ) ;
F_20 ( V_2 , true ) ;
if ( V_29 -> V_56 == true ) {
F_9 ( V_9 , V_17 , L_33 ) ;
F_22 ( V_2 , false , true ) ;
}
}
}
static void F_45 ( struct V_1 * V_2 , bool V_18 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 V_180 , V_181 , V_182 ;
if ( F_2 ( V_2 ) &&
V_29 -> V_72 &&
( V_29 -> V_32 != V_33 ) ) {
if ( V_29 -> V_71 ) {
V_180 = V_183 ;
V_182 = V_184 ;
V_181 = V_185 ;
} else {
V_180 = V_186 ;
V_182 = V_187 ;
V_181 = V_188 ;
}
F_9 ( V_9 , V_17 ,
L_34 ,
V_29 -> V_71 ? L_35 : L_36 , V_180 , V_182 , V_181 ) ;
if ( V_182 )
F_37 ( V_2 , V_18 ,
V_189 , V_182 ) ;
if ( V_181 )
F_37 ( V_2 , V_18 ,
V_126 , V_181 ) ;
}
if ( F_24 ( V_2 ) && ( V_29 -> V_32 != V_33 ) )
V_29 -> V_72 = false ;
}
static void F_46 ( struct V_1 * V_2 , V_38 V_190 ,
T_1 * V_19 , bool V_191 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
V_38 type , V_119 ;
if ( V_191 ) {
if ( V_19 )
F_9 ( V_9 , V_17 ,
L_37 ,
V_190 ,
* ( ( ( V_38 * ) V_19 ) + 4 ) ,
* ( ( ( V_38 * ) V_19 ) + 5 ) ,
* ( ( ( V_38 * ) V_19 ) + 6 ) ) ;
else
F_9 ( V_9 , V_17 , L_38 ,
V_190 ) ;
}
if ( V_190 != V_36 )
return;
type = F_32 ( V_19 ) ;
V_119 = F_47 ( V_19 ) ;
if ( type != V_34 )
return;
switch ( V_119 ) {
case V_122 :
if ( F_24 ( V_2 ) )
break;
if ( * ( ( ( V_38 * ) V_19 ) + V_123 ) ==
V_125 )
break;
V_29 -> V_72 = V_191 ;
if ( V_191 )
F_9 ( V_9 , V_17 ,
L_39 ,
V_29 -> V_71 ? L_35 : L_36 ) ;
else
F_9 ( V_9 , V_17 ,
L_40 ,
V_29 -> V_71 ? L_35 : L_36 ) ;
break;
case V_45 :
V_29 -> V_44 = V_191 ;
if ( V_191 )
F_9 ( V_9 , V_17 , L_41 ) ;
else
F_9 ( V_9 , V_17 , L_42 ) ;
break;
case V_55 :
if ( * ( ( ( V_38 * ) V_19 ) + V_57 ) ==
V_59 ) {
V_29 -> V_56 = V_191 ;
if ( V_191 )
F_9 ( V_9 , V_17 ,
L_43 ) ;
else {
V_29 -> V_192 = false ;
F_9 ( V_9 , V_17 ,
L_44 ) ;
}
}
if ( * ( ( ( V_38 * ) V_19 ) + V_57 ) ==
V_58 ) {
V_29 -> V_192 = ! V_191 ;
if ( V_191 )
F_9 ( V_9 , V_17 ,
L_45 ) ;
else
F_9 ( V_9 , V_17 ,
L_44 ) ;
}
break;
default:
break;
}
}
void F_48 ( struct V_1 * V_2 , bool V_18 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
if ( ! V_20 )
return;
if ( V_29 -> V_72 ) {
if ( V_29 -> V_71 ) {
F_45 ( V_2 , true ) ;
F_9 ( V_9 , V_17 , L_46 ) ;
F_12 ( V_2 , true ) ;
F_4 ( 5 ) ;
F_43 ( V_2 , V_163 ,
V_172 ) ;
if ( F_2 ( V_2 ) ) {
F_43 ( V_2 , V_102 ,
V_193 ) ;
if ( ! ( V_29 -> V_87 &
V_147 ) ) {
F_35 ( V_2 , V_133 ,
V_146 ) ;
}
}
} else {
F_9 ( V_9 , V_17 , L_30 ) ;
F_15 ( V_2 , true ) ;
F_4 ( 5 ) ;
F_35 ( V_2 , V_163 ,
V_172 ) ;
if ( F_2 ( V_2 ) ) {
F_35 ( V_2 , V_102 ,
V_193 ) ;
F_43 ( V_2 , V_133 ,
V_146 ) ;
}
F_45 ( V_2 , true ) ;
}
}
}
bool F_11 ( struct V_1 * V_2 , V_38 V_190 , T_1 V_194 ,
T_1 * V_19 , V_38 V_195 , bool V_18 ,
bool V_196 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
bool V_197 = false ;
T_1 V_129 ;
T_1 V_60 ;
int V_198 ;
if ( ! V_20 )
return false ;
V_60 = F_7 ( V_2 , V_62 ) ;
V_129 = F_7 ( V_2 , V_133 ) ;
if ( ( V_129 == 0xdeadbeef ) || ! ( V_129 & V_165 ) ) {
F_9 ( V_9 , V_17 ,
L_47 ,
V_190 ,
( V_2 -> V_199 == V_200 ) ? 1 : 0 ) ;
F_46 ( V_2 , V_190 , V_19 , true ) ;
return false ;
} else if ( V_196 && ( V_29 -> V_32 == V_33 ) ) {
F_9 ( V_9 , V_17 ,
L_48 ,
V_190 ) ;
F_46 ( V_2 , V_190 , V_19 , true ) ;
return false ;
}
if ( V_18 )
F_8 ( V_2 , V_62 , 0 ) ;
F_8 ( V_2 , V_14 ,
( V_201 |
V_202 ) ) ;
if ( V_19 ) {
for ( V_198 = 0 ; ( V_198 * 4 ) < V_195 ; V_198 ++ )
F_8 ( V_2 , ( V_203 + V_198 * 4 ) ,
* ( V_19 + V_198 ) ) ;
}
F_8 ( V_2 , V_204 ,
( F_39 ( ( V_194 & V_24 ) ,
V_205 ) |
F_39 ( V_195 , V_206 ) |
F_39 ( V_190 , V_207 ) ) ) ;
if ( V_18 &&
! ( F_5 ( V_2 , V_14 ,
V_201 , 500 ) ) )
F_46 ( V_2 , V_190 , V_19 , true ) ;
else {
F_46 ( V_2 , V_190 , V_19 , false ) ;
V_197 = true ;
}
if ( V_18 )
F_8 ( V_2 , V_62 , V_60 ) ;
return V_197 ;
}
void F_49 ( struct V_1 * V_2 , T_1 V_131 , void * V_85 ,
T_2 V_195 , T_1 V_132 )
{
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
void * V_208 = ( void * ) ( ( char * ) V_85 + ( V_132 - V_131 ) ) ;
if ( ! V_20 )
return;
V_29 -> V_131 = V_131 ;
V_29 -> V_85 = V_85 ;
V_29 -> V_136 = V_195 ;
V_29 -> V_132 = V_132 ;
V_29 -> V_208 = V_208 ;
F_38 ( V_2 , true , true , true ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
if ( ! V_20 )
return;
F_8 ( V_2 , V_133 , 0x00 ) ;
F_9 ( V_9 , V_17 , L_49 ) ;
F_26 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 , V_38 V_209 ,
V_38 V_210 , T_1 * V_211 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
V_38 * V_212 = ( V_38 * ) V_211 ;
if ( V_209 != V_34 )
return;
switch ( V_210 ) {
case V_35 :
F_9 ( V_9 , V_17 , L_50 ) ;
F_19 ( V_2 , true ) ;
break;
case V_37 :
F_9 ( V_9 , V_17 , L_51 ) ;
V_29 -> V_213 =
* ( V_212 + V_39 ) ;
V_29 -> V_214 =
* ( V_212 + V_41 ) ;
V_29 -> V_31 = true ;
F_9 ( V_9 , V_17 , L_52 ,
V_29 -> V_213 , V_29 -> V_214 ) ;
break;
case V_50 :
F_9 ( V_9 , V_17 ,
L_53 ,
* ( V_212 + V_215 ) ) ;
V_29 -> V_44 = true ;
F_20 ( V_2 , true ) ;
break;
case V_216 :
V_29 -> V_53 = true ;
F_9 ( V_9 , V_17 , L_54 ) ;
break;
case V_217 :
V_29 -> V_53 = true ;
F_9 ( V_9 , V_17 ,
L_55 ,
* ( V_211 + 3 ) ) ;
break;
default:
break;
}
}
T_1 F_52 ( struct V_1 * V_2 , V_38 V_209 ,
V_38 V_210 , int V_7 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 * V_211 = NULL , V_218 = 0 , V_219 ;
T_1 V_83 ;
V_38 V_82 = 0 , V_220 = 0 ;
bool V_221 = ( V_209 == V_222 ) ;
if ( ! V_20 )
return 0 ;
V_219 = V_7 ? V_223 : V_224 ;
while ( V_7 > 0 ) {
if ( V_211 ) {
F_53 ( V_211 ) ;
V_211 = NULL ;
}
if ( V_219 != V_224 )
V_7 = F_5 ( V_2 ,
V_10 ,
V_225 ,
V_7 ) ;
if ( ! V_7 )
break;
V_83 = F_42 ( V_2 ,
V_226 , & V_219 ) ;
if ( V_83 == V_84 )
continue;
V_211 = ( T_1 * ) ( V_29 -> V_85 + V_83 ) ;
V_82 = F_32 ( V_211 ) ;
V_220 = F_47 ( V_211 ) ;
if ( F_54 ( V_82 ) ) {
if ( V_82 == V_209 ) {
if ( ( V_209 == V_222 ) &&
! V_221 ) {
V_209 = V_227 ;
F_9 ( V_9 , V_17 ,
L_56 ) ;
continue;
}
break;
}
} else if ( ( V_82 == V_209 ) &&
( V_220 == V_210 ) )
break;
if ( ( V_209 == V_227 ) &&
( V_82 == V_228 ) ) {
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_209 = V_222 ;
F_9 ( V_9 , V_17 ,
L_57 ) ;
F_55 ( V_19 ,
V_229 ) ;
F_11 ( V_2 , V_36 , 0 , V_19 , 16 ,
false , false ) ;
F_9 ( V_9 , V_17 , L_58 ) ;
continue;
} else {
F_9 ( V_9 , V_17 , L_59 ,
* ( V_211 + 1 ) ) ;
V_218 ++ ;
F_51 ( V_2 , V_82 ,
V_220 , V_211 ) ;
}
}
if ( V_211 ) {
F_53 ( V_211 ) ;
V_211 = NULL ;
}
if ( V_7 <= 0 ) {
V_7 = 0 ;
F_9 ( V_9 , V_17 ,
L_60 , V_218 ) ;
} else
F_9 ( V_9 , V_17 , L_61 ,
V_209 , V_210 ) ;
while ( V_219 == V_224 ) {
F_9 ( V_9 , V_17 , L_62 ) ;
V_83 = F_42 ( V_2 , V_226 ,
& V_219 ) ;
if ( V_83 == V_84 )
break;
V_211 = ( T_1 * ) ( V_29 -> V_85 + V_83 ) ;
V_82 = F_32 ( V_211 ) ;
V_220 = F_47 ( V_211 ) ;
if ( ! F_54 ( V_82 ) )
F_51 ( V_2 , V_82 ,
V_220 , V_211 ) ;
F_53 ( V_211 ) ;
}
return V_7 ;
}
T_1 F_42 ( struct V_1 * V_2 , T_1 V_230 , T_1 * V_212 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_29 = & V_2 -> V_30 . V_29 ;
T_1 V_231 = 0 , V_232 = 0 , V_233 ;
V_38 V_46 ;
if ( ! V_20 )
return 0 ;
switch ( V_230 ) {
case V_234 :
if ( V_29 -> V_173 ) {
V_231 = F_7 ( V_2 , V_133 ) ;
if ( ( V_231 == 0xdeadbeef ) || ( V_231 == 0xffffffff ) )
V_231 = 0 ;
}
V_231 &= V_165 ;
break;
case V_168 :
V_231 = F_40 ( F_7 ( V_2 , V_135 ) , V_235 ) ;
F_9 ( V_9 , V_17 , L_63 , V_231 ) ;
V_29 -> V_236 = V_231 ;
break;
case V_226 :
case V_237 :
F_8 ( V_2 , V_10 ,
V_225 ) ;
V_233 = F_40 ( F_7 ( V_2 , V_135 ) , V_235 ) ;
V_231 = V_233 ;
if ( V_231 == 0 )
V_231 = V_29 -> V_136 - 1 ;
else if ( V_231 >= V_29 -> V_136 ) {
if ( V_231 != 0xFFFF ) {
V_231 = 0 ;
F_9 ( V_9 , V_17 ,
L_64 ) ;
}
} else
V_231 -- ;
if ( V_231 == 0xFFFF ) {
V_231 = V_84 ;
V_232 = V_223 ;
F_9 ( V_9 , V_17 ,
L_65 ,
V_233 , V_231 ) ;
} else if ( V_230 == V_226 ) {
if ( V_233 == V_29 -> V_236 ) {
V_231 = V_84 ;
V_232 = V_223 ;
F_9 ( V_9 , V_17 ,
L_66 ,
V_233 , V_231 ) ;
} else {
for (; ; ) {
T_1 V_238 ;
if ( V_231 != V_29 -> V_236 )
V_232 = V_224 ;
else
V_232 = V_223 ;
V_238 = V_29 -> V_236 ;
V_29 -> V_236 ++ ;
if ( V_29 -> V_236 >=
V_29 -> V_136 )
V_29 -> V_236 = 0 ;
F_9 ( V_9 , V_17 ,
L_67 ,
V_233 , V_238 ,
( V_232 == V_224 ) ) ;
if ( F_31 ( V_2 ,
V_238 ) ) {
V_231 = V_238 ;
break;
}
if ( V_232 == V_223 ) {
V_231 = V_84 ;
break;
}
}
}
if ( V_212 )
* V_212 = V_232 ;
}
if ( V_231 != V_84 )
V_231 <<= 4 ;
break;
case V_239 :
V_231 = F_40 ( F_7 ( V_2 , V_240 ) ,
V_241 ) ;
V_231 <<= 4 ;
break;
case V_179 :
V_231 = F_40 ( F_7 ( V_2 , V_240 ) ,
V_242 ) ?
V_33 : V_63 ;
break;
case V_243 :
V_231 = F_40 ( V_29 -> V_244 , V_245 ) ;
break;
case V_246 :
V_231 = F_40 ( V_29 -> V_244 , V_247 ) ;
break;
case V_248 :
V_231 = F_40 ( V_29 -> V_244 , V_249 ) ;
break;
case V_250 :
V_231 = V_29 -> V_32 ;
break;
case V_251 :
V_29 -> V_32 = V_33 ;
break;
case V_252 :
V_29 -> V_32 = V_63 ;
F_17 ( V_2 , true ) ;
F_20 ( V_2 , true ) ;
if ( V_29 -> V_56 ) {
F_9 ( V_9 , V_17 , L_33 ) ;
F_22 ( V_2 , false , true ) ;
}
F_48 ( V_2 , true ) ;
break;
case V_253 :
V_29 -> V_32 = V_254 ;
break;
case V_255 :
V_29 -> V_32 = V_256 ;
break;
case V_257 :
F_1 ( V_2 ) ;
V_29 -> V_72 = true ;
if ( ( F_36 ( V_2 ) ) &&
( V_29 -> V_87 & V_258 ) ) {
if ( ( F_7 ( V_2 , V_105 ) &
V_106 ) !=
V_106 ) {
F_9 ( V_9 , V_17 ,
L_68 ) ;
F_33 ( V_2 ) ;
}
}
break;
case V_259 :
F_19 ( V_2 , true ) ;
break;
case V_260 :
if ( ! V_212 )
F_9 ( V_9 , V_17 ,
L_69 ) ;
else {
V_29 -> V_213 = ( * V_212 >> 8 ) & 0xff ;
V_29 -> V_214 = ( * V_212 ) & 0xff ;
V_29 -> V_31 = true ;
F_9 ( V_9 , V_17 , L_70 ,
V_29 -> V_213 , V_29 -> V_214 ) ;
}
break;
case V_261 :
if ( V_212 ) {
if ( ( ( V_29 -> V_43 [ 1 ] & 0xffff0000 ) ==
( * ( V_212 + 1 ) & 0xffff0000 ) ) &&
( V_29 -> V_43 [ 2 ] == * ( V_212 + 2 ) ) &&
( V_29 -> V_43 [ 3 ] == * ( V_212 + 3 ) ) )
break;
V_29 -> V_43 [ 0 ] = * V_212 ++ ;
V_29 -> V_43 [ 1 ] = * V_212 ++ ;
V_29 -> V_43 [ 2 ] = * V_212 ++ ;
V_29 -> V_43 [ 3 ] = * V_212 ++ ;
}
V_29 -> V_44 = true ;
F_20 ( V_2 , true ) ;
break;
case V_262 :
F_17 ( V_2 , true ) ;
break;
case V_263 :
V_46 = ( F_24 ( V_2 ) ) ?
V_48 :
V_49 ;
F_21 ( V_2 , true , V_46 ) ;
break;
case V_264 :
V_231 = ( ! V_29 -> V_56 &&
V_29 -> V_52 ) ? 1 : 0 ;
if ( V_212 )
V_29 -> V_52 =
( * V_212 != 0 ) ? true : false ;
break;
case V_265 :
F_9 ( V_9 , V_17 , L_71 ) ;
F_23 ( V_2 ) ;
V_29 -> V_53 = true ;
V_29 -> V_52 = true ;
F_20 ( V_2 , true ) ;
F_48 ( V_2 , true ) ;
break;
case V_266 :
V_231 = ! ( V_29 -> V_87 & V_267 ) ;
break;
case V_268 :
V_231 = ! ( V_29 -> V_87 & V_269 ) ;
break;
default:
break;
}
return V_231 ;
}
