static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ,
V_4 , 1 ) ;
F_3 ( 1 ) ;
F_2 ( V_2 , V_3 ,
V_4 , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_6 , int V_7 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
while ( V_7 ) {
if ( F_6 ( V_2 , V_5 ) & V_6 ) {
F_7 ( V_2 , V_5 , V_6 ) ;
if ( V_5 == V_10 ) {
if ( V_6 &
V_11 )
F_1 ( V_2 ) ;
if ( V_6 &
( V_12 |
V_13 ) )
F_7 ( V_2 , V_14 ,
V_15 ) ;
F_7 ( V_2 , V_14 ,
V_16 ) ;
}
break;
}
F_3 ( 10 ) ;
V_7 -= 10 ;
if ( V_7 < 0 )
break;
}
if ( V_7 <= 0 ) {
F_8 ( V_9 , V_17 ,
L_1 ,
V_5 , V_6 ) ;
F_8 ( V_9 , V_17 ,
L_2 ,
F_6 ( V_2 , V_14 ) ,
F_6 ( V_2 , V_10 ) ) ;
V_7 = 0 ;
}
return V_7 ;
}
static void F_9 ( struct V_1 * V_2 , bool V_18 )
{
T_1 V_19 [ 4 ] = { 0xffffffff , 0xffffffff , 0xffffffff , 0xffffff00 } ;
F_10 ( V_2 , V_20 , 0 , V_19 , 16 ,
V_18 , false ) ;
F_3 ( 5 ) ;
}
static void F_11 ( struct V_1 * V_2 , bool V_18 )
{
T_1 V_19 = 0x00000000 ;
F_10 ( V_2 , V_21 , 0 , & V_19 , 1 ,
V_18 , false ) ;
}
static void F_12 ( struct V_1 * V_2 , bool V_18 )
{
F_10 ( V_2 , V_22 , V_23 ,
NULL , 0 , V_18 , false ) ;
F_3 ( 5 ) ;
}
static void F_13 ( struct V_1 * V_2 , bool V_18 )
{
F_10 ( V_2 , V_24 , V_23 ,
NULL , 0 , V_18 , false ) ;
}
static void F_14 ( struct V_1 * V_2 , bool V_18 )
{
T_1 V_19 = 0x70000000 ;
F_10 ( V_2 , V_25 , 0 , & V_19 , 1 ,
V_18 , false ) ;
}
static void F_15 ( struct V_1 * V_2 , bool V_18 )
{
F_10 ( V_2 , V_26 ,
V_23 ,
NULL , 0 , V_18 , false ) ;
}
static void F_16 ( struct V_1 * V_2 ,
bool V_18 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ! V_28 -> V_30 &&
( V_28 -> V_31 != V_32 ) ) {
F_17 ( V_19 ,
V_33 ,
V_34 ) ;
F_10 ( V_2 , V_35 , 0 , V_19 , 16 ,
V_18 , true ) ;
}
}
static void F_18 ( struct V_1 * V_2 ,
bool V_18 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_17 ( V_19 , V_33 ,
V_36 ) ;
* ( ( ( V_37 * ) V_19 ) + V_38 ) =
V_28 -> V_39 ;
* ( ( ( V_37 * ) V_19 ) + V_40 ) =
V_28 -> V_41 ;
F_10 ( V_2 , V_35 , 0 , V_19 , 16 , V_18 , true ) ;
}
static void F_19 ( struct V_1 * V_2 ,
bool V_18 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 * V_19 = & V_28 -> V_42 [ 0 ] ;
if ( ( V_28 -> V_43 == true ) &&
( V_28 -> V_31 != V_32 ) ) {
F_17 ( V_19 ,
V_33 ,
V_44 ) ;
F_10 ( V_2 , V_35 , 0 , V_19 , 16 ,
V_18 , true ) ;
F_17 ( V_19 , 0xff , 0xff ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
bool V_18 , V_37 V_45 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
bool V_46 = ! ! ( V_45 & ( V_47 |
V_48 ) ) ;
if ( V_28 -> V_31 != V_32 ) {
F_17 ( V_19 , V_33 ,
V_49 ) ;
* ( ( ( V_37 * ) V_19 ) + V_50 ) = V_45 ;
if ( ! F_10 ( V_2 , V_35 , 0 , V_19 , 16 ,
V_18 , true ) ) {
if ( V_46 )
V_28 -> V_51 = true ;
}
if ( V_46 )
V_28 -> V_52 = false ;
}
}
static void F_21 ( struct V_1 * V_2 , bool V_53 ,
bool V_18 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_17 ( V_19 , V_33 ,
V_54 ) ;
if ( V_53 ) {
V_28 -> V_52 = true ;
V_28 -> V_55 = true ;
V_28 -> V_51 = true ;
* ( ( ( V_37 * ) V_19 ) + V_56 ) =
V_57 ;
} else
* ( ( ( V_37 * ) V_19 ) + V_56 ) =
V_58 ;
F_10 ( V_2 , V_35 , 0 , V_19 , 16 , V_18 , true ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_59 ;
T_1 V_60 = 150 ;
V_28 -> V_31 = V_32 ;
V_59 = F_6 ( V_2 , V_61 ) ;
F_7 ( V_2 , V_61 , 0 ) ;
F_7 ( V_2 , V_10 ,
F_6 ( V_2 , V_10 ) ) ;
F_7 ( V_2 , V_14 ,
F_6 ( V_2 , V_14 ) ) ;
F_9 ( V_2 , true ) ;
F_12 ( V_2 , true ) ;
if ( F_4 ( V_2 , V_10 ,
V_13 , 500 ) ) {
V_28 -> V_31 = V_62 ;
F_13 ( V_2 , true ) ;
F_3 ( 10 ) ;
F_7 ( V_2 , V_63 , 0xFFFFFFFF ) ;
F_7 ( V_2 , V_64 , 0xFFFFFFFF ) ;
F_7 ( V_2 , V_65 , 0xFFFFFFFF ) ;
F_7 ( V_2 , V_66 , 0xFFFFFFFF ) ;
F_7 ( V_2 , V_67 , 0X000000FF ) ;
F_7 ( V_2 , V_10 ,
V_68 ) ;
F_7 ( V_2 , V_14 ,
V_69 ) ;
if ( V_28 -> V_70 ) {
F_11 ( V_2 , true ) ;
F_3 ( 5 ) ;
}
if ( ( V_28 -> V_70 && ! V_28 -> V_71 ) ) {
if ( F_4 ( V_2 ,
V_10 ,
V_72 ,
V_60 ) )
F_8 ( V_9 , V_17 ,
L_3 ) ;
else
F_8 ( V_9 , V_17 ,
L_4 ) ;
}
}
if ( ( V_28 -> V_31 == V_62 ) &&
( F_23 ( V_2 , V_10 ,
V_13 ) ) &&
( F_23 ( V_2 , V_10 ,
V_12 ) == 0 ) ) {
F_7 ( V_2 , V_10 ,
V_13 ) ;
F_7 ( V_2 , V_14 ,
V_15 ) ;
}
F_7 ( V_2 , V_61 , V_59 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( F_25 ( V_2 , V_73 , NULL ) &&
( V_28 -> V_31 != V_32 ) &&
! V_28 -> V_74 ) {
F_21 ( V_2 , true , true ) ;
}
V_28 -> V_75 = false ;
F_7 ( V_2 , V_76 , 0x2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_61 , 0 ) ;
F_7 ( V_2 , V_77 , 0 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_61 , V_78 ) ;
F_7 ( V_2 , V_77 ,
V_79 ) ;
}
static bool F_28 ( struct V_1 * V_2 , T_1 V_80 )
{
T_1 V_81 ;
V_81 = F_6 ( V_2 , V_10 ) ;
return ( ( V_81 & V_80 ) == V_80 ) ;
}
void F_29 ( struct V_1 * V_2 , T_1 * V_82 ,
T_1 * V_83 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
* V_82 = V_28 -> V_82 ;
* V_83 = V_28 -> V_83 ;
V_28 -> V_82 = 0 ;
V_28 -> V_83 = 0 ;
}
void F_30 ( struct V_1 * V_2 , enum V_84 * V_85 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_82 , V_83 ;
V_83 = F_6 ( V_2 , V_10 ) ;
V_82 = F_6 ( V_2 , V_14 ) ;
if ( ( V_82 == 0xdeadbeef ) || ( V_83 == 0xdeadbeef ) ) {
F_8 ( V_9 , V_17 ,
L_5 ) ;
} else {
V_28 -> V_83 |= V_83 ;
V_28 -> V_82 |= V_82 ;
* V_85 |= V_86 ;
if ( V_83 & V_87 )
V_28 -> V_88 = F_6 ( V_2 , V_89 ) ;
F_7 ( V_2 , V_10 , V_83 ) ;
F_7 ( V_2 , V_14 , V_82 ) ;
}
}
static void F_31 ( struct V_1 * V_2 , bool V_70 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( ! V_28 -> V_71 &&
( V_28 -> V_70 != V_70 ) )
V_28 -> V_71 = true ;
V_28 -> V_70 = V_70 ;
}
static bool F_32 ( struct V_1 * V_2 , T_1 V_90 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 * V_19 ;
T_1 V_91 , V_92 ;
if ( V_90 == V_93 )
return false ;
V_92 = V_90 << 4 ;
V_19 = ( T_1 * ) ( V_28 -> V_94 + V_92 ) ;
V_91 = F_33 ( V_19 ) ;
if ( V_91 == V_95 )
return false ;
return true ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( V_28 -> V_96 & V_97 ) {
F_35 ( V_2 , 3 , V_98 ) ;
F_35 ( V_2 , 2 , V_99 ) ;
F_35 ( V_2 , 1 , V_100 ) ;
F_35 ( V_2 , 0 , V_101 ) ;
} else if ( V_28 -> V_96 & V_102 ) {
F_35 ( V_2 , 3 , V_103 ) ;
F_35 ( V_2 , 2 , V_104 ) ;
F_35 ( V_2 , 1 , V_105 ) ;
F_35 ( V_2 , 0 , V_106 ) ;
F_35 ( V_2 , 5 , V_107 ) ;
} else if ( V_28 -> V_96 & V_108 ) {
F_35 ( V_2 , 3 , V_105 ) ;
F_35 ( V_2 , 2 , V_106 ) ;
F_35 ( V_2 , 1 , V_100 ) ;
F_35 ( V_2 , 0 , V_101 ) ;
} else
return;
F_36 ( V_2 , V_109 , V_110 ) ;
F_2 ( V_2 , V_111 , V_112 , 1 ) ;
F_2 ( V_2 , V_111 , V_113 , 0 ) ;
F_36 ( V_2 , V_114 , V_115 ) ;
F_2 ( V_2 , V_116 , V_117 , 0 ) ;
F_2 ( V_2 , V_116 , V_118 , 1 ) ;
F_7 ( V_2 , V_119 , 0x4b ) ;
F_2 ( V_2 , V_120 , V_121 , 0x03 ) ;
F_2 ( V_2 , V_120 , V_122 , 0x01 ) ;
F_2 ( V_2 , V_123 , V_124 , 0x02 ) ;
F_2 ( V_2 , V_123 , V_125 , 0x03 ) ;
F_2 ( V_2 , V_126 ,
V_127 , 0x07 ) ;
}
static bool F_37 ( struct V_1 * V_2 , bool V_18 ,
V_37 V_128 , T_1 V_129 )
{
T_1 V_130 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_17 ( V_130 , V_33 ,
V_131 ) ;
* ( ( ( V_37 * ) V_130 ) + V_132 ) = V_128 ;
* ( ( ( V_37 * ) V_130 ) + V_133 + 0 ) = V_129 & 0xFF ;
* ( ( ( V_37 * ) V_130 ) + V_133 + 1 ) = ( V_129 >> 8 ) & 0xFF ;
* ( ( ( V_37 * ) V_130 ) + V_133 + 2 ) = ( V_129 >> 16 ) & 0xFF ;
* ( ( ( V_37 * ) V_130 ) + V_133 + 3 ) = ( V_129 >> 24 ) & 0xFF ;
return F_10 ( V_2 , V_35 , 0 , V_130 , 16 ,
V_18 , true ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_134 ;
V_134 = F_25 ( V_2 , V_135 , NULL ) ;
if ( V_28 -> V_31 != V_134 )
V_28 -> V_31 = V_134 ;
if ( V_28 -> V_31 != V_32 ) {
F_16 ( V_2 , true ) ;
F_19 ( V_2 , true ) ;
if ( V_28 -> V_55 == true )
F_21 ( V_2 , false , true ) ;
}
}
void F_39 ( struct V_1 * V_2 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
if ( ! V_136 -> V_75 )
return;
F_38 ( V_2 ) ;
F_40 ( V_2 , true ) ;
if ( ( V_136 -> V_31 == V_62 ) &&
( V_136 -> V_52 == true ) ) {
V_136 -> V_51 = true ;
}
}
static void F_41 ( struct V_1 * V_2 , V_37 V_137 ,
V_37 V_138 , T_1 * V_139 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_37 * V_140 = ( V_37 * ) V_139 ;
if ( V_137 != V_33 )
return;
switch ( V_138 ) {
case V_34 :
F_8 ( V_9 , V_17 , L_6 ) ;
F_18 ( V_2 , true ) ;
break;
case V_36 :
F_8 ( V_9 , V_17 , L_7 ) ;
V_28 -> V_141 =
* ( V_140 + V_38 ) ;
V_28 -> V_142 =
* ( V_140 + V_40 ) ;
V_28 -> V_30 = true ;
F_8 ( V_9 , V_17 , L_8 ,
V_28 -> V_141 , V_28 -> V_142 ) ;
break;
case V_49 :
F_8 ( V_9 , V_17 ,
L_9 ,
* ( V_140 + V_143 ) ) ;
V_28 -> V_43 = true ;
F_19 ( V_2 , true ) ;
break;
case V_144 :
V_28 -> V_52 = true ;
F_8 ( V_9 , V_17 , L_10 ) ;
break;
case V_145 :
V_28 -> V_52 = true ;
F_8 ( V_9 , V_17 ,
L_11 ,
* ( V_139 + 3 ) ) ;
break;
default:
break;
}
}
static T_1 F_42 ( struct V_1 * V_2 , V_37 V_137 ,
V_37 V_138 , int V_7 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 * V_139 = NULL , V_146 = 0 , V_147 ;
T_1 V_92 ;
V_37 V_91 = 0 , V_148 = 0 ;
bool V_149 = ( V_137 == V_150 ) ;
V_147 = V_7 ? V_151 : V_152 ;
while ( V_7 > 0 ) {
if ( V_139 ) {
F_43 ( V_139 ) ;
V_139 = NULL ;
}
if ( V_147 != V_152 )
V_7 = F_4 ( V_2 ,
V_10 ,
V_153 ,
V_7 ) ;
if ( ! V_7 )
break;
V_92 = F_25 ( V_2 , V_154 ,
& V_147 ) ;
if ( V_92 == V_93 )
continue;
V_139 = ( T_1 * ) ( V_28 -> V_94 + V_92 ) ;
V_91 = F_33 ( V_139 ) ;
V_148 = F_44 ( V_139 ) ;
if ( F_45 ( V_91 ) ) {
if ( V_91 == V_137 ) {
if ( ( V_137 == V_150 ) &&
! V_149 ) {
V_137 = V_155 ;
continue;
}
break;
}
} else if ( ( V_91 == V_137 ) && ( V_148 == V_138 ) ) {
break;
}
if ( ( V_137 == V_155 ) &&
( V_91 == V_156 ) ) {
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_137 = V_150 ;
F_46 ( V_19 ,
V_157 ) ;
F_10 ( V_2 , V_35 , 0 , V_19 , 16 ,
false , false ) ;
continue;
} else {
F_8 ( V_9 , V_17 , L_12 ,
* ( V_139 + 1 ) ) ;
V_146 ++ ;
F_41 ( V_2 , V_91 ,
V_148 , V_139 ) ;
}
}
if ( V_139 ) {
F_43 ( V_139 ) ;
V_139 = NULL ;
}
if ( V_7 <= 0 )
V_7 = 0 ;
while ( V_147 == V_152 ) {
V_92 = F_25 ( V_2 , V_154 ,
& V_147 ) ;
if ( V_92 == V_93 )
break;
V_139 = ( T_1 * ) ( V_28 -> V_94 + V_92 ) ;
V_91 = F_33 ( V_139 ) ;
V_148 = F_44 ( V_139 ) ;
if ( ! F_45 ( V_91 ) )
F_41 ( V_2 , V_91 ,
V_148 , V_139 ) ;
F_43 ( V_139 ) ;
}
return V_7 ;
}
bool F_47 ( struct V_1 * V_2 , struct V_158 * V_159 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_31 ( V_2 , F_48 ( V_159 ) ) ;
if ( V_136 -> V_31 != V_160 )
return false ;
V_136 -> V_31 = V_161 ;
F_26 ( V_2 ) ;
F_46 ( V_19 , V_157 ) ;
F_10 ( V_2 , V_35 , 0 , V_19 ,
16 , true , false ) ;
if ( F_42 ( V_2 , V_150 ,
0 , 25000 ) )
F_8 ( V_9 , V_17 , L_13 ) ;
else
F_8 ( V_9 , V_17 ,
L_14 ) ;
V_136 -> V_31 = V_62 ;
F_27 ( V_2 ) ;
return true ;
}
int F_49 ( struct V_1 * V_2 , struct V_158 * V_159 ,
struct V_162 * V_163 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
if ( ! V_136 -> V_75 )
return 0 ;
if ( ! F_48 ( V_159 ) || ( V_136 -> V_31 != V_32 ) )
goto exit;
if ( F_28 ( V_2 , V_164 ) ||
F_28 ( V_2 , V_11 ) ) {
F_7 ( V_2 , V_10 ,
V_164 |
V_11 ) ;
F_9 ( V_2 , true ) ;
F_13 ( V_2 , true ) ;
F_3 ( 1 ) ;
if ( F_48 ( V_159 ) )
F_11 ( V_2 , true ) ;
V_136 -> V_31 = V_62 ;
if ( V_163 ) {
V_163 -> V_165 = false ;
V_163 -> V_166 = false ;
V_163 -> V_167 . V_168 = 0 ;
}
if ( ! F_50 ( V_2 , V_159 ) )
return - V_169 ;
}
exit:
F_27 ( V_2 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_170 , 0xffff0000 ) ;
F_7 ( V_2 , V_171 , 0xffffffff ) ;
F_7 ( V_2 , V_172 , 0xffffffff ) ;
F_7 ( V_2 , V_173 , 0xffffffff ) ;
F_7 ( V_2 , V_174 , 0xffffffff ) ;
F_36 ( V_2 , V_175 , V_176 ) ;
F_3 ( 10 ) ;
F_14 ( V_2 , true ) ;
F_3 ( 5 ) ;
F_15 ( V_2 , true ) ;
}
static void F_52 ( struct V_1 * V_2 , bool V_177 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_178 ;
if ( V_177 ) {
F_2 ( V_2 , V_179 ,
V_180 , 1 ) ;
F_2 ( V_2 , V_179 ,
V_181 , 1 ) ;
if ( ! ( V_28 -> V_96 & V_182 ) ) {
V_178 = F_53 ( V_28 -> V_96 , V_183 ) ;
F_2 ( V_2 , V_184 ,
V_185 , V_178 ) ;
F_2 ( V_2 , V_184 ,
V_186 , 1 ) ;
} else {
F_2 ( V_2 , V_184 ,
V_186 , 0 ) ;
}
F_2 ( V_2 , V_184 ,
V_187 , 1 ) ;
} else {
F_54 ( V_2 , V_184 ,
V_187 ) ;
}
}
void F_55 ( struct V_1 * V_2 , bool V_188 , bool V_70 ,
bool V_189 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_190 ;
F_8 ( V_9 , V_17 , L_15 ,
V_189 , V_70 ) ;
if ( ! V_28 -> V_191 && ! V_28 -> V_192 ) {
F_8 ( V_9 , V_17 ,
L_16 ) ;
return;
}
if ( F_6 ( V_2 , V_184 ) == 0xdeadbeef ) {
F_8 ( V_9 , V_17 , L_17 ) ;
return;
}
F_7 ( V_2 , V_193 , V_28 -> V_191 ) ;
F_7 ( V_2 , V_194 , V_28 -> V_195 ) ;
F_7 ( V_2 , V_196 , V_28 -> V_192 ) ;
V_190 = F_56 ( 1 , V_197 ) |
F_56 ( 1 , V_198 ) |
F_56 ( 1 , V_199 ) |
F_56 ( 1 , V_200 ) |
F_56 ( 2 , V_201 ) |
F_56 ( 3 , V_202 ) |
F_56 ( 0 , V_203 ) |
F_56 ( 0 , V_204 ) |
F_56 ( 0 , V_187 ) ;
F_7 ( V_2 , V_184 , V_190 ) ;
if ( V_70 && ! ( V_28 -> V_96 & V_205 ) )
F_52 ( V_2 , true ) ;
else
F_52 ( V_2 , false ) ;
F_36 ( V_2 , V_111 ,
V_206 ) ;
F_2 ( V_2 , V_207 ,
V_208 , 20 ) ;
F_2 ( V_2 , V_116 , V_209 , 1 ) ;
F_2 ( V_2 , V_210 , V_211 , 0 ) ;
V_190 = F_53 ( V_28 -> V_96 , V_212 ) ;
F_2 ( V_2 , V_175 , V_213 , V_190 ) ;
F_36 ( V_2 , V_184 , V_214 ) ;
V_190 = F_6 ( V_2 , V_3 ) ;
V_190 |= F_56 ( 1 , V_215 ) ;
F_7 ( V_2 , V_3 , V_190 ) ;
F_3 ( 1 ) ;
V_190 &= ~ F_56 ( 1 , V_215 ) ;
F_7 ( V_2 , V_3 , V_190 ) ;
if ( V_189 ) {
F_51 ( V_2 ) ;
F_3 ( 100 ) ;
}
V_190 |= F_56 ( 1 , V_216 ) ;
F_7 ( V_2 , V_3 , V_190 ) ;
F_3 ( 1 ) ;
V_190 &= ~ F_56 ( 1 , V_216 ) ;
F_7 ( V_2 , V_3 , V_190 ) ;
F_25 ( V_2 , V_217 , NULL ) ;
F_7 ( V_2 , V_170 ,
( F_56 ( 0xe801 , V_218 ) |
F_56 ( 0x0000 , V_219 ) ) ) ;
F_54 ( V_2 , V_175 ,
V_176 ) ;
F_34 ( V_2 ) ;
V_28 -> V_75 = true ;
F_22 ( V_2 ) ;
if ( V_188 )
F_27 ( V_2 ) ;
}
void F_57 ( struct V_1 * V_2 , bool V_220 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
F_26 ( V_2 ) ;
if ( V_136 -> V_75 && ! V_220 ) {
F_51 ( V_2 ) ;
F_3 ( 20 ) ;
F_7 ( V_2 , V_184 , 0 ) ;
}
V_136 -> V_31 = V_32 ;
V_136 -> V_75 = false ;
}
static void F_58 ( struct V_1 * V_2 , bool V_18 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_221 , V_222 , V_223 ;
if ( V_28 -> V_71 && ( V_28 -> V_31 != V_32 ) ) {
if ( V_28 -> V_70 ) {
V_221 = V_224 ;
V_223 = V_225 ;
V_222 = V_226 ;
} else {
V_221 = V_227 ;
V_223 = V_228 ;
V_222 = V_229 ;
}
if ( V_223 )
F_37 ( V_2 , V_18 ,
V_230 ,
V_223 ) ;
if ( V_222 )
F_37 ( V_2 , V_18 ,
V_231 ,
V_222 ) ;
}
}
static void F_59 ( struct V_1 * V_2 , V_37 V_232 ,
T_1 * V_19 , bool V_233 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_37 type , V_128 ;
if ( V_232 != V_35 )
return;
type = F_33 ( V_19 ) ;
V_128 = F_44 ( V_19 ) ;
if ( type != V_33 )
return;
switch ( V_128 ) {
case V_131 :
if ( * ( ( ( V_37 * ) V_19 ) + V_132 ) ==
V_234 )
break;
V_28 -> V_71 = V_233 ;
break;
case V_44 :
V_28 -> V_43 = V_233 ;
break;
case V_54 :
if ( * ( ( ( V_37 * ) V_19 ) + V_56 ) ==
V_58 ) {
V_28 -> V_55 = V_233 ;
if ( ! V_233 )
V_28 -> V_74 = false ;
}
if ( * ( ( ( V_37 * ) V_19 ) + V_56 ) ==
V_57 ) {
V_28 -> V_74 = ! V_233 ;
}
break;
default:
break;
}
}
void F_40 ( struct V_1 * V_2 , bool V_18 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( V_28 -> V_71 ) {
if ( V_28 -> V_70 ) {
F_58 ( V_2 , true ) ;
F_11 ( V_2 , true ) ;
F_3 ( 5 ) ;
F_54 ( V_2 , V_175 ,
V_176 ) ;
F_54 ( V_2 , V_111 ,
V_235 ) ;
if ( ! ( V_28 -> V_96 & V_205 ) ) {
F_36 ( V_2 , V_184 ,
V_187 ) ;
}
} else {
F_14 ( V_2 , true ) ;
F_3 ( 5 ) ;
F_36 ( V_2 , V_175 ,
V_176 ) ;
F_36 ( V_2 , V_111 ,
V_235 ) ;
F_54 ( V_2 , V_184 ,
V_187 ) ;
F_58 ( V_2 , true ) ;
}
}
}
bool F_10 ( struct V_1 * V_2 , V_37 V_232 , T_1 V_236 ,
T_1 * V_19 , V_37 V_237 , bool V_18 ,
bool V_238 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
bool V_239 = false ;
T_1 V_190 ;
T_1 V_59 ;
int V_240 ;
V_59 = F_6 ( V_2 , V_61 ) ;
V_190 = F_6 ( V_2 , V_184 ) ;
if ( ( V_190 == 0xdeadbeef ) || ! ( V_190 & V_214 ) ) {
F_8 ( V_9 , V_17 ,
L_18 ,
V_232 , ( V_2 -> V_241 == V_242 ) ? 1 : 0 ) ;
F_59 ( V_2 , V_232 , V_19 , true ) ;
return false ;
} else if ( V_238 && ( V_28 -> V_31 == V_32 ) ) {
F_8 ( V_9 , V_17 ,
L_19 ,
V_232 ) ;
F_59 ( V_2 , V_232 , V_19 , true ) ;
return false ;
}
if ( V_18 )
F_7 ( V_2 , V_61 , 0 ) ;
F_7 ( V_2 , V_14 ,
( V_243 |
V_244 ) ) ;
if ( V_19 ) {
for ( V_240 = 0 ; ( V_240 * 4 ) < V_237 ; V_240 ++ )
F_7 ( V_2 , ( V_245 + V_240 * 4 ) ,
* ( V_19 + V_240 ) ) ;
}
F_7 ( V_2 , V_246 ,
( F_56 ( ( V_236 & V_23 ) ,
V_247 ) |
F_56 ( V_237 , V_248 ) |
F_56 ( V_232 , V_249 ) ) ) ;
if ( V_18 &&
! ( F_4 ( V_2 , V_14 ,
V_243 , 500 ) ) )
F_59 ( V_2 , V_232 , V_19 , true ) ;
else {
F_59 ( V_2 , V_232 , V_19 , false ) ;
V_239 = true ;
}
if ( V_18 )
F_7 ( V_2 , V_61 , V_59 ) ;
return V_239 ;
}
void F_60 ( struct V_1 * V_2 , bool * V_250 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
T_1 V_130 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ( V_136 -> V_31 != V_62 ) ||
( V_136 -> V_96 & V_251 ) )
return;
F_46 ( V_130 , V_252 ) ;
V_130 [ V_253 ] = V_136 -> V_254 ++ ;
F_10 ( V_2 , V_35 , 0 , V_130 , 16 , true , false ) ;
if ( F_42 ( V_2 , V_155 , 0 , 50000 ) ) {
F_8 ( V_9 , V_17 , L_20 ) ;
} else {
V_250 = false ;
F_8 ( V_9 , V_17 , L_21 ) ;
}
}
void F_61 ( struct V_1 * V_2 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
T_1 V_130 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ( V_136 -> V_31 != V_62 ) ||
( V_136 -> V_96 & V_251 ) )
return;
F_46 ( V_130 , V_255 ) ;
V_130 [ V_253 ] = V_136 -> V_256 ++ ;
F_10 ( V_2 , V_35 , 0 , V_130 , 16 , true , false ) ;
}
void F_62 ( struct V_1 * V_2 , T_1 V_191 , void * V_94 ,
T_2 V_237 , T_1 V_192 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_28 -> V_191 = V_191 ;
V_28 -> V_94 = V_94 ;
V_28 -> V_195 = V_237 ;
V_28 -> V_192 = V_192 ;
F_55 ( V_2 , true , true , true ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_184 , 0x00 ) ;
F_26 ( V_2 ) ;
}
T_1 F_25 ( struct V_1 * V_2 , T_1 V_257 , T_1 * V_140 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_258 = 0 , V_259 = 0 , V_260 ;
V_37 V_45 ;
switch ( V_257 ) {
case V_73 :
if ( V_28 -> V_75 ) {
V_258 = F_6 ( V_2 , V_184 ) ;
if ( ( V_258 == 0xdeadbeef ) || ( V_258 == 0xffffffff ) )
V_258 = 0 ;
}
V_258 &= V_214 ;
break;
case V_217 :
V_258 = F_53 ( F_6 ( V_2 , V_194 ) , V_261 ) ;
V_28 -> V_262 = V_258 ;
break;
case V_154 :
case V_263 :
F_7 ( V_2 , V_10 ,
V_153 ) ;
V_260 = F_53 ( F_6 ( V_2 , V_194 ) , V_261 ) ;
V_258 = V_260 ;
if ( V_258 == 0 )
V_258 = V_28 -> V_195 - 1 ;
else if ( V_258 >= V_28 -> V_195 ) {
if ( V_258 != 0xFFFF )
V_258 = 0 ;
} else {
V_258 -- ;
}
if ( V_258 == 0xFFFF ) {
V_258 = V_93 ;
V_259 = V_151 ;
} else if ( V_257 == V_154 ) {
if ( V_260 == V_28 -> V_262 ) {
V_258 = V_93 ;
V_259 = V_151 ;
} else {
for (; ; ) {
T_1 V_264 ;
if ( V_258 != V_28 -> V_262 )
V_259 = V_152 ;
else
V_259 = V_151 ;
V_264 = V_28 -> V_262 ;
V_28 -> V_262 ++ ;
if ( V_28 -> V_262 >=
V_28 -> V_195 )
V_28 -> V_262 = 0 ;
if ( F_32 ( V_2 ,
V_264 ) ) {
V_258 = V_264 ;
break;
}
if ( V_259 == V_151 ) {
V_258 = V_93 ;
break;
}
}
}
if ( V_140 )
* V_140 = V_259 ;
}
if ( V_258 != V_93 )
V_258 <<= 4 ;
break;
case V_265 :
V_258 = F_53 ( F_6 ( V_2 , V_266 ) ,
V_267 ) ;
V_258 <<= 4 ;
break;
case V_135 :
V_258 = F_53 ( F_6 ( V_2 , V_266 ) ,
V_268 ) ?
V_32 : V_62 ;
break;
case V_269 :
V_258 = F_53 ( V_28 -> V_88 , V_270 ) ;
break;
case V_271 :
V_258 = F_53 ( V_28 -> V_88 , V_272 ) ;
break;
case V_273 :
V_258 = F_53 ( V_28 -> V_88 , V_274 ) ;
break;
case V_275 :
V_258 = V_28 -> V_31 ;
break;
case V_276 :
V_28 -> V_31 = V_32 ;
break;
case V_277 :
V_28 -> V_31 = V_62 ;
F_16 ( V_2 , true ) ;
F_19 ( V_2 , true ) ;
if ( V_28 -> V_55 )
F_21 ( V_2 , false , true ) ;
F_40 ( V_2 , true ) ;
break;
case V_278 :
V_28 -> V_31 = V_160 ;
break;
case V_279 :
V_28 -> V_31 = V_161 ;
break;
case V_280 :
F_1 ( V_2 ) ;
V_28 -> V_71 = true ;
if ( V_28 -> V_96 & V_281 ) {
if ( ( F_6 ( V_2 , V_114 ) &
V_115 ) !=
V_115 ) {
F_34 ( V_2 ) ;
}
}
break;
case V_282 :
F_18 ( V_2 , true ) ;
break;
case V_283 :
if ( ! V_140 )
F_8 ( V_9 , V_17 ,
L_22 ) ;
else {
V_28 -> V_141 = ( * V_140 >> 8 ) & 0xff ;
V_28 -> V_142 = ( * V_140 ) & 0xff ;
V_28 -> V_30 = true ;
F_8 ( V_9 , V_17 , L_23 ,
V_28 -> V_141 , V_28 -> V_142 ) ;
}
break;
case V_284 :
if ( V_140 ) {
if ( ( ( V_28 -> V_42 [ 1 ] & 0xffff0000 ) ==
( * ( V_140 + 1 ) & 0xffff0000 ) ) &&
( V_28 -> V_42 [ 2 ] == * ( V_140 + 2 ) ) &&
( V_28 -> V_42 [ 3 ] == * ( V_140 + 3 ) ) )
break;
V_28 -> V_42 [ 0 ] = * V_140 ++ ;
V_28 -> V_42 [ 1 ] = * V_140 ++ ;
V_28 -> V_42 [ 2 ] = * V_140 ++ ;
V_28 -> V_42 [ 3 ] = * V_140 ++ ;
}
V_28 -> V_43 = true ;
F_19 ( V_2 , true ) ;
break;
case V_285 :
F_16 ( V_2 , true ) ;
break;
case V_286 :
V_45 = V_48 ;
F_20 ( V_2 , true , V_45 ) ;
break;
case V_287 :
V_258 = ( ! V_28 -> V_55 &&
V_28 -> V_51 ) ? 1 : 0 ;
if ( V_140 )
V_28 -> V_51 =
( * V_140 != 0 ) ? true : false ;
break;
case V_288 :
F_22 ( V_2 ) ;
V_28 -> V_52 = true ;
V_28 -> V_51 = true ;
F_19 ( V_2 , true ) ;
F_40 ( V_2 , true ) ;
break;
case V_289 :
V_258 = ! ( V_28 -> V_96 & V_290 ) ;
break;
case V_291 :
V_258 = ! ( V_28 -> V_96 & V_292 ) ;
break;
default:
break;
}
return V_258 ;
}
