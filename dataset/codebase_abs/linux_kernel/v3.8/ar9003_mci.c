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
if ( ! ( F_6 ( V_2 , V_5 ) & V_6 ) ) {
F_3 ( 10 ) ;
V_7 -= 10 ;
if ( V_7 < 0 )
break;
else
continue;
}
F_7 ( V_2 , V_5 , V_6 ) ;
if ( V_5 != V_10 )
break;
if ( V_6 & V_11 )
F_1 ( V_2 ) ;
if ( V_6 & ( V_12 |
V_13 ) )
F_7 ( V_2 , V_14 ,
V_15 ) ;
F_7 ( V_2 , V_14 , V_16 ) ;
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
if ( V_28 -> V_30 ||
( V_28 -> V_31 == V_32 ) )
return;
F_17 ( V_19 , V_33 ,
V_34 ) ;
F_10 ( V_2 , V_35 , 0 , V_19 , 16 , V_18 , true ) ;
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
if ( ! V_28 -> V_43 ||
( V_28 -> V_31 == V_32 ) )
return;
F_17 ( V_19 , V_33 ,
V_44 ) ;
F_10 ( V_2 , V_35 , 0 , V_19 , 16 , V_18 , true ) ;
F_17 ( V_19 , 0xff , 0xff ) ;
}
static void F_20 ( struct V_1 * V_2 ,
bool V_18 , V_37 V_45 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
bool V_46 ;
if ( V_28 -> V_31 == V_32 )
return;
V_46 = ! ! ( V_45 & ( V_47 |
V_48 ) ) ;
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
if ( ! F_4 ( V_2 , V_10 ,
V_13 , 500 ) )
goto V_62;
V_28 -> V_31 = V_63 ;
F_13 ( V_2 , true ) ;
F_3 ( 10 ) ;
F_7 ( V_2 , V_64 , 0xFFFFFFFF ) ;
F_7 ( V_2 , V_65 , 0xFFFFFFFF ) ;
F_7 ( V_2 , V_66 , 0xFFFFFFFF ) ;
F_7 ( V_2 , V_67 , 0xFFFFFFFF ) ;
F_7 ( V_2 , V_68 , 0X000000FF ) ;
F_7 ( V_2 , V_10 ,
V_69 ) ;
F_7 ( V_2 , V_14 , V_70 ) ;
if ( V_28 -> V_71 ) {
F_11 ( V_2 , true ) ;
F_3 ( 5 ) ;
}
if ( ( V_28 -> V_71 && ! V_28 -> V_72 ) ) {
if ( F_4 ( V_2 ,
V_10 ,
V_73 ,
V_60 ) )
F_8 ( V_9 , V_17 ,
L_3 ) ;
else
F_8 ( V_9 , V_17 ,
L_4 ) ;
}
V_62:
if ( ( V_28 -> V_31 == V_63 ) &&
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
if ( F_25 ( V_2 , V_74 ) &&
( V_28 -> V_31 != V_32 ) &&
! V_28 -> V_75 ) {
F_21 ( V_2 , true , true ) ;
}
V_28 -> V_76 = false ;
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
static void F_31 ( struct V_1 * V_2 , bool V_71 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( ! V_28 -> V_72 &&
( V_28 -> V_71 != V_71 ) )
V_28 -> V_72 = true ;
V_28 -> V_71 = V_71 ;
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
V_134 = F_25 ( V_2 , V_135 ) ;
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
if ( ! V_136 -> V_76 )
return;
F_38 ( V_2 ) ;
F_40 ( V_2 , true ) ;
if ( ( V_136 -> V_31 == V_63 ) &&
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
V_92 = F_44 ( V_2 , false , & V_147 ) ;
if ( V_92 == V_93 )
continue;
V_139 = ( T_1 * ) ( V_28 -> V_94 + V_92 ) ;
V_91 = F_33 ( V_139 ) ;
V_148 = F_45 ( V_139 ) ;
if ( F_46 ( V_91 ) ) {
if ( V_91 == V_137 ) {
if ( ( V_137 == V_150 ) &&
! V_149 ) {
V_137 = V_154 ;
continue;
}
break;
}
} else if ( ( V_91 == V_137 ) &&
( V_148 == V_138 ) )
break;
if ( ( V_137 == V_154 ) &&
( V_91 == V_155 ) ) {
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_137 = V_150 ;
F_47 ( V_19 ,
V_156 ) ;
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
V_92 = F_44 ( V_2 , false , & V_147 ) ;
if ( V_92 == V_93 )
break;
V_139 = ( T_1 * ) ( V_28 -> V_94 + V_92 ) ;
V_91 = F_33 ( V_139 ) ;
V_148 = F_45 ( V_139 ) ;
if ( ! F_46 ( V_91 ) )
F_41 ( V_2 , V_91 ,
V_148 , V_139 ) ;
F_43 ( V_139 ) ;
}
return V_7 ;
}
bool F_48 ( struct V_1 * V_2 , struct V_157 * V_158 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_31 ( V_2 , F_49 ( V_158 ) ) ;
if ( V_136 -> V_31 != V_159 )
return false ;
V_136 -> V_31 = V_160 ;
F_26 ( V_2 ) ;
F_47 ( V_19 , V_156 ) ;
F_10 ( V_2 , V_35 , 0 , V_19 ,
16 , true , false ) ;
if ( F_42 ( V_2 , V_150 ,
0 , 25000 ) )
F_8 ( V_9 , V_17 , L_13 ) ;
else
F_8 ( V_9 , V_17 ,
L_14 ) ;
V_136 -> V_31 = V_63 ;
F_27 ( V_2 ) ;
return true ;
}
int F_50 ( struct V_1 * V_2 , struct V_157 * V_158 ,
struct V_161 * V_162 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
if ( ! V_136 -> V_76 )
return 0 ;
if ( ! F_49 ( V_158 ) || ( V_136 -> V_31 != V_32 ) )
goto exit;
if ( ! F_28 ( V_2 , V_163 ) &&
! F_28 ( V_2 , V_11 ) )
goto exit;
F_7 ( V_2 , V_10 ,
( V_163 |
V_11 ) ) ;
F_9 ( V_2 , true ) ;
F_13 ( V_2 , true ) ;
F_3 ( 1 ) ;
if ( F_49 ( V_158 ) )
F_11 ( V_2 , true ) ;
V_136 -> V_31 = V_63 ;
F_51 ( V_2 , V_164 ,
1 << V_165 ) ;
if ( V_162 ) {
V_162 -> V_166 = false ;
V_162 -> V_167 = false ;
V_162 -> V_168 = false ;
}
if ( ! F_52 ( V_2 , V_158 ) )
return - V_169 ;
F_36 ( V_2 , V_164 ,
1 << V_165 ) ;
exit:
F_27 ( V_2 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_170 , 0xffff0000 ) ;
F_36 ( V_2 , V_171 , V_172 ) ;
F_3 ( 10 ) ;
F_14 ( V_2 , true ) ;
F_3 ( 5 ) ;
F_15 ( V_2 , true ) ;
}
static void F_54 ( struct V_1 * V_2 , bool V_173 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_174 ;
if ( ! V_173 ) {
F_51 ( V_2 , V_175 ,
V_176 ) ;
return;
}
F_2 ( V_2 , V_177 , V_178 , 1 ) ;
F_2 ( V_2 , V_177 ,
V_179 , 1 ) ;
if ( F_55 ( V_2 ) )
F_2 ( V_2 , V_180 , V_181 , 1 ) ;
if ( ! ( V_28 -> V_96 & V_182 ) ) {
V_174 = F_56 ( V_28 -> V_96 , V_183 ) ;
F_2 ( V_2 , V_175 ,
V_184 , V_174 ) ;
F_2 ( V_2 , V_175 ,
V_185 , 1 ) ;
} else
F_2 ( V_2 , V_175 ,
V_185 , 0 ) ;
F_2 ( V_2 , V_175 ,
V_176 , 1 ) ;
}
int F_57 ( struct V_1 * V_2 , bool V_186 , bool V_71 ,
bool V_187 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_188 , V_189 ;
F_8 ( V_9 , V_17 , L_15 ,
V_187 , V_71 ) ;
if ( ! V_28 -> V_190 && ! V_28 -> V_191 ) {
F_58 ( V_9 , L_16 ) ;
return - V_192 ;
}
if ( F_6 ( V_2 , V_175 ) == 0xdeadbeef ) {
F_58 ( V_9 , L_17 ) ;
return - V_193 ;
}
F_7 ( V_2 , V_194 , V_28 -> V_190 ) ;
F_7 ( V_2 , V_195 , V_28 -> V_196 ) ;
F_7 ( V_2 , V_197 , V_28 -> V_191 ) ;
V_188 = F_59 ( 1 , V_198 ) |
F_59 ( 1 , V_199 ) |
F_59 ( 1 , V_200 ) |
F_59 ( 1 , V_201 ) |
F_59 ( 0 , V_202 ) |
F_59 ( 0 , V_203 ) |
F_59 ( 0 , V_176 ) ;
if ( F_55 ( V_2 ) ) {
V_188 |= F_59 ( 1 , V_204 ) |
F_59 ( 1 , V_205 ) ;
F_2 ( V_2 , V_116 ,
V_206 , 0x1 ) ;
} else {
V_188 |= F_59 ( 2 , V_204 ) |
F_59 ( 3 , V_205 ) ;
}
F_7 ( V_2 , V_175 , V_188 ) ;
if ( V_71 && ! ( V_28 -> V_96 & V_207 ) )
F_54 ( V_2 , true ) ;
else
F_54 ( V_2 , false ) ;
F_36 ( V_2 , V_111 ,
V_208 ) ;
F_2 ( V_2 , V_209 ,
V_210 , 20 ) ;
F_2 ( V_2 , V_116 , V_211 , 0 ) ;
F_2 ( V_2 , V_212 , V_213 , 0 ) ;
F_2 ( V_2 , V_214 , V_215 , 0x3D090 ) ;
if ( V_28 -> V_96 & V_216 ) {
F_2 ( V_2 , V_116 ,
V_217 , 0 ) ;
F_2 ( V_2 , V_116 ,
V_218 , 0x7f ) ;
F_2 ( V_2 , V_175 ,
V_219 , 0 ) ;
for ( V_189 = 0 ; V_189 < 8 ; V_189 ++ )
F_7 ( V_2 , F_60 ( V_189 ) , 0x7f7f7f7f ) ;
}
V_188 = F_56 ( V_28 -> V_96 , V_220 ) ;
F_2 ( V_2 , V_171 , V_221 , V_188 ) ;
F_36 ( V_2 , V_175 , V_222 ) ;
V_188 = F_6 ( V_2 , V_3 ) ;
V_188 |= F_59 ( 1 , V_223 ) ;
F_7 ( V_2 , V_3 , V_188 ) ;
F_3 ( 1 ) ;
V_188 &= ~ F_59 ( 1 , V_223 ) ;
F_7 ( V_2 , V_3 , V_188 ) ;
if ( V_187 ) {
F_53 ( V_2 ) ;
F_3 ( 100 ) ;
}
F_61 ( V_2 ) ;
V_188 |= F_59 ( 1 , V_224 ) ;
F_7 ( V_2 , V_3 , V_188 ) ;
F_3 ( 1 ) ;
V_188 &= ~ F_59 ( 1 , V_224 ) ;
F_7 ( V_2 , V_3 , V_188 ) ;
F_44 ( V_2 , true , NULL ) ;
F_7 ( V_2 , V_170 ,
( F_59 ( 0xe801 , V_225 ) |
F_59 ( 0x0000 , V_226 ) ) ) ;
F_51 ( V_2 , V_171 ,
V_172 ) ;
F_34 ( V_2 ) ;
V_28 -> V_76 = true ;
F_22 ( V_2 ) ;
if ( F_55 ( V_2 ) )
F_2 ( V_2 , V_227 ,
V_228 , 0 ) ;
if ( V_186 )
F_27 ( V_2 ) ;
return 0 ;
}
void F_62 ( struct V_1 * V_2 , bool V_229 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
F_26 ( V_2 ) ;
if ( V_136 -> V_76 && ! V_229 ) {
F_53 ( V_2 ) ;
F_3 ( 20 ) ;
F_7 ( V_2 , V_175 , 0 ) ;
}
V_136 -> V_31 = V_32 ;
V_136 -> V_76 = false ;
}
static void F_63 ( struct V_1 * V_2 , bool V_18 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_230 , V_231 , V_232 ;
if ( ! V_28 -> V_72 || ( V_28 -> V_31 == V_32 ) )
return;
if ( V_28 -> V_71 ) {
V_230 = V_233 ;
V_232 = V_234 ;
V_231 = V_235 ;
} else {
V_230 = V_236 ;
V_232 = V_237 ;
V_231 = V_238 ;
}
if ( V_232 )
F_37 ( V_2 , V_18 ,
V_239 ,
V_232 ) ;
if ( V_231 )
F_37 ( V_2 , V_18 ,
V_240 ,
V_231 ) ;
}
static void F_64 ( struct V_1 * V_2 , V_37 V_241 ,
T_1 * V_19 , bool V_242 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_37 type , V_128 ;
if ( V_241 != V_35 )
return;
type = F_33 ( V_19 ) ;
V_128 = F_45 ( V_19 ) ;
if ( type != V_33 )
return;
switch ( V_128 ) {
case V_131 :
if ( * ( ( ( V_37 * ) V_19 ) + V_132 ) ==
V_243 )
break;
V_28 -> V_72 = V_242 ;
break;
case V_44 :
V_28 -> V_43 = V_242 ;
break;
case V_54 :
if ( * ( ( ( V_37 * ) V_19 ) + V_56 ) ==
V_58 ) {
V_28 -> V_55 = V_242 ;
if ( ! V_242 )
V_28 -> V_75 = false ;
}
if ( * ( ( ( V_37 * ) V_19 ) + V_56 ) ==
V_57 ) {
V_28 -> V_75 = ! V_242 ;
}
break;
default:
break;
}
}
void F_40 ( struct V_1 * V_2 , bool V_244 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( ! V_28 -> V_72 && ! V_244 )
return;
if ( V_28 -> V_71 ) {
F_63 ( V_2 , true ) ;
F_11 ( V_2 , true ) ;
F_3 ( 5 ) ;
F_51 ( V_2 , V_171 ,
V_172 ) ;
F_51 ( V_2 , V_111 ,
V_245 ) ;
if ( ! ( V_28 -> V_96 & V_207 ) )
F_54 ( V_2 , true ) ;
if ( F_65 ( V_2 ) )
F_7 ( V_2 , V_246 , 0x02 ) ;
} else {
F_14 ( V_2 , true ) ;
F_3 ( 5 ) ;
F_36 ( V_2 , V_171 ,
V_172 ) ;
F_36 ( V_2 , V_111 ,
V_245 ) ;
F_54 ( V_2 , false ) ;
F_63 ( V_2 , true ) ;
}
}
bool F_10 ( struct V_1 * V_2 , V_37 V_241 , T_1 V_247 ,
T_1 * V_19 , V_37 V_248 , bool V_18 ,
bool V_249 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
bool V_250 = false ;
T_1 V_188 ;
T_1 V_59 ;
int V_189 ;
V_59 = F_6 ( V_2 , V_61 ) ;
V_188 = F_6 ( V_2 , V_175 ) ;
if ( ( V_188 == 0xdeadbeef ) || ! ( V_188 & V_222 ) ) {
F_8 ( V_9 , V_17 ,
L_18 ,
V_241 , ( V_2 -> V_251 == V_252 ) ? 1 : 0 ) ;
F_64 ( V_2 , V_241 , V_19 , true ) ;
return false ;
} else if ( V_249 && ( V_28 -> V_31 == V_32 ) ) {
F_8 ( V_9 , V_17 ,
L_19 ,
V_241 ) ;
F_64 ( V_2 , V_241 , V_19 , true ) ;
return false ;
}
if ( V_18 )
F_7 ( V_2 , V_61 , 0 ) ;
F_7 ( V_2 , V_14 ,
( V_253 |
V_254 ) ) ;
if ( V_19 ) {
for ( V_189 = 0 ; ( V_189 * 4 ) < V_248 ; V_189 ++ )
F_7 ( V_2 , ( V_255 + V_189 * 4 ) ,
* ( V_19 + V_189 ) ) ;
}
F_7 ( V_2 , V_256 ,
( F_59 ( ( V_247 & V_23 ) ,
V_257 ) |
F_59 ( V_248 , V_258 ) |
F_59 ( V_241 , V_259 ) ) ) ;
if ( V_18 &&
! ( F_4 ( V_2 , V_14 ,
V_253 , 500 ) ) )
F_64 ( V_2 , V_241 , V_19 , true ) ;
else {
F_64 ( V_2 , V_241 , V_19 , false ) ;
V_250 = true ;
}
if ( V_18 )
F_7 ( V_2 , V_61 , V_59 ) ;
return V_250 ;
}
void F_66 ( struct V_1 * V_2 , bool * V_260 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
T_1 V_130 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ( V_136 -> V_31 != V_63 ) ||
( V_136 -> V_96 & V_261 ) )
return;
F_47 ( V_130 , V_262 ) ;
V_130 [ V_263 ] = V_136 -> V_264 ++ ;
F_10 ( V_2 , V_35 , 0 , V_130 , 16 , true , false ) ;
if ( F_42 ( V_2 , V_154 , 0 , 50000 ) ) {
F_8 ( V_9 , V_17 , L_20 ) ;
} else {
* V_260 = false ;
F_8 ( V_9 , V_17 , L_21 ) ;
}
}
void F_67 ( struct V_1 * V_2 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
T_1 V_130 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ( V_136 -> V_31 != V_63 ) ||
( V_136 -> V_96 & V_261 ) )
return;
F_47 ( V_130 , V_265 ) ;
V_130 [ V_263 ] = V_136 -> V_266 ++ ;
F_10 ( V_2 , V_35 , 0 , V_130 , 16 , true , false ) ;
}
int F_68 ( struct V_1 * V_2 , T_1 V_190 , void * V_94 ,
T_2 V_248 , T_1 V_191 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_28 -> V_190 = V_190 ;
V_28 -> V_94 = V_94 ;
V_28 -> V_196 = V_248 ;
V_28 -> V_191 = V_191 ;
return F_57 ( V_2 , true , true , true ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_175 , 0x00 ) ;
F_26 ( V_2 ) ;
}
T_1 F_25 ( struct V_1 * V_2 , T_1 V_267 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_268 = 0 , V_269 ;
V_37 V_45 ;
switch ( V_267 ) {
case V_74 :
if ( V_28 -> V_76 ) {
V_268 = F_6 ( V_2 , V_175 ) ;
if ( ( V_268 == 0xdeadbeef ) || ( V_268 == 0xffffffff ) )
V_268 = 0 ;
}
V_268 &= V_222 ;
break;
case V_270 :
V_268 = F_56 ( F_6 ( V_2 , V_271 ) ,
V_272 ) ;
V_268 <<= 4 ;
break;
case V_135 :
V_268 = F_56 ( F_6 ( V_2 , V_271 ) ,
V_273 ) ?
V_32 : V_63 ;
break;
case V_274 :
V_28 -> V_31 = V_63 ;
F_16 ( V_2 , true ) ;
F_19 ( V_2 , true ) ;
if ( V_28 -> V_55 )
F_21 ( V_2 , false , true ) ;
F_40 ( V_2 , false ) ;
break;
case V_275 :
F_1 ( V_2 ) ;
V_28 -> V_72 = true ;
if ( V_28 -> V_96 & V_276 ) {
if ( ( F_6 ( V_2 , V_114 ) &
V_115 ) !=
V_115 ) {
F_34 ( V_2 ) ;
}
}
break;
case V_277 :
F_18 ( V_2 , true ) ;
break;
case V_278 :
F_16 ( V_2 , true ) ;
break;
case V_279 :
V_45 = V_48 ;
F_20 ( V_2 , true , V_45 ) ;
break;
case V_280 :
V_269 = F_70 ( V_2 ) ;
if ( ( V_269 - V_28 -> V_281 ) <= V_282 ) {
F_8 ( F_5 ( V_2 ) , V_17 ,
L_22 ) ;
break;
}
F_8 ( F_5 ( V_2 ) , V_17 , L_23 ) ;
V_28 -> V_281 = V_269 ;
F_22 ( V_2 ) ;
V_28 -> V_52 = true ;
V_28 -> V_51 = true ;
F_19 ( V_2 , true ) ;
F_40 ( V_2 , false ) ;
break;
case V_283 :
V_268 = ! ( V_28 -> V_96 & V_284 ) ;
break;
case V_285 :
V_268 = ( ! V_28 -> V_55 && V_28 -> V_51 ) ? 1 : 0 ;
V_28 -> V_51 = false ;
break;
default:
break;
}
return V_268 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
F_8 ( V_9 , V_17 , L_24 ) ;
F_14 ( V_2 , true ) ;
F_3 ( 50 ) ;
F_36 ( V_2 , V_111 , V_245 ) ;
V_28 -> V_71 = false ;
V_28 -> V_72 = true ;
F_63 ( V_2 , true ) ;
V_28 -> V_72 = true ;
}
void F_72 ( struct V_1 * V_2 )
{
T_1 V_286 , V_287 ;
int V_189 ;
V_37 V_288 , V_289 ;
for ( V_189 = 0 ; V_189 < V_290 ; V_189 ++ ) {
V_286 = F_6 ( V_2 , V_116 ) ;
if ( V_286 != 0xdeadbeef )
break;
F_3 ( V_291 ) ;
}
F_7 ( V_2 , V_116 , ( V_286 | F_73 ( 23 ) ) ) ;
for ( V_189 = 0 ; V_189 < V_290 ; V_189 ++ ) {
V_287 = F_6 ( V_2 , V_120 ) ;
if ( V_287 != 0xdeadbeef )
break;
F_3 ( V_291 ) ;
}
F_7 ( V_2 , V_120 , ( V_287 | F_73 ( 27 ) | F_73 ( 19 ) | F_73 ( 18 ) ) ) ;
V_288 = F_6 ( V_2 , V_292 ) & 0x3 ;
V_289 = F_56 ( F_6 ( V_2 , V_271 ) , V_273 ) ;
F_7 ( V_2 , V_116 , V_286 ) ;
F_7 ( V_2 , V_120 , V_287 ) ;
if ( V_289 && ( V_288 == 2 ) ) {
F_36 ( V_2 , V_293 , 0x1 ) ;
F_51 ( V_2 , V_293 , 0x1 ) ;
F_3 ( 50 ) ;
}
}
void F_61 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_92 ;
V_92 = F_56 ( F_6 ( V_2 , V_195 ) , V_294 ) ;
if ( V_28 -> V_295 == V_92 )
return;
F_8 ( V_9 , V_17 , L_25 ,
V_28 -> V_295 , V_92 ) ;
V_28 -> V_52 = true ;
V_28 -> V_51 = true ;
V_28 -> V_295 = 0 ;
}
T_1 F_44 ( struct V_1 * V_2 , bool V_296 , T_1 * V_297 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_92 , V_298 = 0 , V_299 ;
if ( V_296 ) {
V_299 = F_56 ( F_6 ( V_2 , V_195 ) , V_294 ) ;
if ( V_299 >= V_28 -> V_196 )
V_299 = 0 ;
V_28 -> V_295 = V_299 ;
return V_299 ;
}
F_7 ( V_2 , V_10 ,
V_153 ) ;
V_299 = F_56 ( F_6 ( V_2 , V_195 ) , V_294 ) ;
V_92 = V_299 ;
if ( ! V_92 )
V_92 = V_28 -> V_196 - 1 ;
else if ( V_92 >= V_28 -> V_196 ) {
if ( V_92 != 0xFFFF )
V_92 = 0 ;
} else {
V_92 -- ;
}
if ( ( V_92 == 0xFFFF ) || ( V_299 == V_28 -> V_295 ) ) {
V_92 = V_93 ;
V_298 = V_151 ;
goto V_300;
}
for (; ; ) {
T_1 V_301 ;
if ( V_92 != V_28 -> V_295 )
V_298 = V_152 ;
else
V_298 = V_151 ;
V_301 = V_28 -> V_295 ;
if ( V_301 >= V_28 -> V_196 )
V_301 = 0 ;
V_28 -> V_295 ++ ;
if ( V_28 -> V_295 >= V_28 -> V_196 )
V_28 -> V_295 = 0 ;
if ( F_32 ( V_2 , V_301 ) ) {
V_92 = V_301 ;
break;
}
if ( V_298 == V_151 ) {
V_92 = V_93 ;
break;
}
}
if ( V_92 != V_93 )
V_92 <<= 4 ;
V_300:
if ( V_297 )
* V_297 = V_298 ;
return V_92 ;
}
void F_74 ( struct V_1 * V_2 , V_37 V_302 , V_37 V_303 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_28 -> V_141 = V_302 ;
V_28 -> V_142 = V_303 ;
V_28 -> V_30 = true ;
F_8 ( F_5 ( V_2 ) , V_17 , L_26 ,
V_28 -> V_141 , V_28 -> V_142 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_28 -> V_43 = true ;
F_19 ( V_2 , true ) ;
}
T_2 F_76 ( struct V_1 * V_2 , V_37 V_304 )
{
if ( ! V_2 -> V_29 . V_28 . V_305 )
goto V_300;
if ( V_304 == V_306 )
return V_307 ;
else if ( V_304 == V_308 )
return V_309 ;
V_300:
return - 1 ;
}
