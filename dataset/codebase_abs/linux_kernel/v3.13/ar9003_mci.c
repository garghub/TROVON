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
F_52 ( V_166 , & V_162 -> V_167 ) ;
F_52 ( V_168 , & V_162 -> V_167 ) ;
F_52 ( V_169 , & V_162 -> V_167 ) ;
}
if ( ! F_53 ( V_2 , V_158 ) )
return - V_170 ;
F_36 ( V_2 , V_164 ,
1 << V_165 ) ;
exit:
F_27 ( V_2 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_171 , 0xffff0000 ) ;
F_36 ( V_2 , V_172 , V_173 ) ;
F_3 ( 10 ) ;
F_14 ( V_2 , true ) ;
F_3 ( 5 ) ;
F_15 ( V_2 , true ) ;
}
static void F_55 ( struct V_1 * V_2 , bool V_174 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_175 ;
if ( ! V_174 ) {
F_51 ( V_2 , V_176 ,
V_177 ) ;
return;
}
F_2 ( V_2 , V_178 , V_179 , 1 ) ;
F_2 ( V_2 , V_178 ,
V_180 , 1 ) ;
if ( F_56 ( V_2 ) )
F_2 ( V_2 , V_181 , V_182 , 1 ) ;
if ( ! ( V_28 -> V_96 & V_183 ) ) {
V_175 = F_57 ( V_28 -> V_96 , V_184 ) ;
F_2 ( V_2 , V_176 ,
V_185 , V_175 ) ;
F_2 ( V_2 , V_176 ,
V_186 , 1 ) ;
} else
F_2 ( V_2 , V_176 ,
V_186 , 0 ) ;
F_2 ( V_2 , V_176 ,
V_177 , 1 ) ;
}
int F_58 ( struct V_1 * V_2 , bool V_187 , bool V_71 ,
bool V_188 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_189 , V_190 ;
F_8 ( V_9 , V_17 , L_15 ,
V_188 , V_71 ) ;
if ( ! V_28 -> V_191 && ! V_28 -> V_192 ) {
F_59 ( V_9 , L_16 ) ;
return - V_193 ;
}
if ( F_6 ( V_2 , V_176 ) == 0xdeadbeef ) {
F_59 ( V_9 , L_17 ) ;
return - V_194 ;
}
F_7 ( V_2 , V_195 , V_28 -> V_191 ) ;
F_7 ( V_2 , V_196 , V_28 -> V_197 ) ;
F_7 ( V_2 , V_198 , V_28 -> V_192 ) ;
V_189 = F_60 ( 1 , V_199 ) |
F_60 ( 1 , V_200 ) |
F_60 ( 1 , V_201 ) |
F_60 ( 1 , V_202 ) |
F_60 ( 0 , V_203 ) |
F_60 ( 0 , V_204 ) |
F_60 ( 0 , V_177 ) ;
if ( F_56 ( V_2 ) ) {
V_189 |= F_60 ( 1 , V_205 ) |
F_60 ( 1 , V_206 ) ;
F_2 ( V_2 , V_116 ,
V_207 , 0x1 ) ;
} else {
V_189 |= F_60 ( 2 , V_205 ) |
F_60 ( 3 , V_206 ) ;
}
F_7 ( V_2 , V_176 , V_189 ) ;
if ( V_71 && ! ( V_28 -> V_96 & V_208 ) )
F_55 ( V_2 , true ) ;
else
F_55 ( V_2 , false ) ;
F_36 ( V_2 , V_111 ,
V_209 ) ;
F_2 ( V_2 , V_210 ,
V_211 , 20 ) ;
F_2 ( V_2 , V_116 , V_212 , 0 ) ;
F_2 ( V_2 , V_213 , V_214 , 0 ) ;
F_2 ( V_2 , V_215 , V_216 , 0x3D090 ) ;
if ( V_28 -> V_96 & V_217 ) {
F_2 ( V_2 , V_116 ,
V_218 , 0 ) ;
F_2 ( V_2 , V_116 ,
V_219 , 0x7f ) ;
F_2 ( V_2 , V_176 ,
V_220 , 0 ) ;
for ( V_190 = 0 ; V_190 < 8 ; V_190 ++ )
F_7 ( V_2 , F_61 ( V_190 ) , 0x7f7f7f7f ) ;
}
V_189 = F_57 ( V_28 -> V_96 , V_221 ) ;
F_2 ( V_2 , V_172 , V_222 , V_189 ) ;
F_36 ( V_2 , V_176 , V_223 ) ;
V_189 = F_6 ( V_2 , V_3 ) ;
V_189 |= F_60 ( 1 , V_224 ) ;
F_7 ( V_2 , V_3 , V_189 ) ;
F_3 ( 1 ) ;
V_189 &= ~ F_60 ( 1 , V_224 ) ;
F_7 ( V_2 , V_3 , V_189 ) ;
if ( V_188 ) {
F_54 ( V_2 ) ;
F_3 ( 100 ) ;
}
F_62 ( V_2 ) ;
V_189 |= F_60 ( 1 , V_225 ) ;
F_7 ( V_2 , V_3 , V_189 ) ;
F_3 ( 1 ) ;
V_189 &= ~ F_60 ( 1 , V_225 ) ;
F_7 ( V_2 , V_3 , V_189 ) ;
F_44 ( V_2 , true , NULL ) ;
F_7 ( V_2 , V_171 ,
( F_60 ( 0xe801 , V_226 ) |
F_60 ( 0x0000 , V_227 ) ) ) ;
F_51 ( V_2 , V_172 ,
V_173 ) ;
F_34 ( V_2 ) ;
V_28 -> V_76 = true ;
F_22 ( V_2 ) ;
if ( F_56 ( V_2 ) )
F_2 ( V_2 , V_228 ,
V_229 , 0 ) ;
if ( V_187 )
F_27 ( V_2 ) ;
return 0 ;
}
void F_63 ( struct V_1 * V_2 , bool V_230 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
F_26 ( V_2 ) ;
if ( V_136 -> V_76 && ! V_230 ) {
F_54 ( V_2 ) ;
F_3 ( 20 ) ;
F_7 ( V_2 , V_176 , 0 ) ;
}
V_136 -> V_31 = V_32 ;
V_136 -> V_76 = false ;
}
static void F_64 ( struct V_1 * V_2 , bool V_18 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_231 , V_232 , V_233 ;
if ( ! V_28 -> V_72 || ( V_28 -> V_31 == V_32 ) )
return;
if ( V_28 -> V_71 ) {
V_231 = V_234 ;
V_233 = V_235 ;
V_232 = V_236 ;
} else {
V_231 = V_237 ;
V_233 = V_238 ;
V_232 = V_239 ;
}
if ( V_233 )
F_37 ( V_2 , V_18 ,
V_240 ,
V_233 ) ;
if ( V_232 )
F_37 ( V_2 , V_18 ,
V_241 ,
V_232 ) ;
}
static void F_65 ( struct V_1 * V_2 , V_37 V_242 ,
T_1 * V_19 , bool V_243 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_37 type , V_128 ;
if ( V_242 != V_35 )
return;
type = F_33 ( V_19 ) ;
V_128 = F_45 ( V_19 ) ;
if ( type != V_33 )
return;
switch ( V_128 ) {
case V_131 :
if ( * ( ( ( V_37 * ) V_19 ) + V_132 ) ==
V_244 )
break;
V_28 -> V_72 = V_243 ;
break;
case V_44 :
V_28 -> V_43 = V_243 ;
break;
case V_54 :
if ( * ( ( ( V_37 * ) V_19 ) + V_56 ) ==
V_58 ) {
V_28 -> V_55 = V_243 ;
if ( ! V_243 )
V_28 -> V_75 = false ;
}
if ( * ( ( ( V_37 * ) V_19 ) + V_56 ) ==
V_57 ) {
V_28 -> V_75 = ! V_243 ;
}
break;
default:
break;
}
}
void F_40 ( struct V_1 * V_2 , bool V_245 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( ! V_28 -> V_72 && ! V_245 )
return;
if ( V_28 -> V_71 ) {
F_64 ( V_2 , true ) ;
F_11 ( V_2 , true ) ;
F_3 ( 5 ) ;
F_51 ( V_2 , V_172 ,
V_173 ) ;
F_51 ( V_2 , V_111 ,
V_246 ) ;
if ( ! ( V_28 -> V_96 & V_208 ) )
F_55 ( V_2 , true ) ;
if ( F_66 ( V_2 ) )
F_7 ( V_2 , V_247 , 0x02 ) ;
} else {
F_14 ( V_2 , true ) ;
F_3 ( 5 ) ;
F_36 ( V_2 , V_172 ,
V_173 ) ;
F_36 ( V_2 , V_111 ,
V_246 ) ;
F_55 ( V_2 , false ) ;
F_64 ( V_2 , true ) ;
}
}
bool F_10 ( struct V_1 * V_2 , V_37 V_242 , T_1 V_248 ,
T_1 * V_19 , V_37 V_249 , bool V_18 ,
bool V_250 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
bool V_251 = false ;
T_1 V_189 ;
T_1 V_59 ;
int V_190 ;
V_59 = F_6 ( V_2 , V_61 ) ;
V_189 = F_6 ( V_2 , V_176 ) ;
if ( ( V_189 == 0xdeadbeef ) || ! ( V_189 & V_223 ) ) {
F_8 ( V_9 , V_17 ,
L_18 ,
V_242 , ( V_2 -> V_252 == V_253 ) ? 1 : 0 ) ;
F_65 ( V_2 , V_242 , V_19 , true ) ;
return false ;
} else if ( V_250 && ( V_28 -> V_31 == V_32 ) ) {
F_8 ( V_9 , V_17 ,
L_19 ,
V_242 ) ;
F_65 ( V_2 , V_242 , V_19 , true ) ;
return false ;
}
if ( V_18 )
F_7 ( V_2 , V_61 , 0 ) ;
F_7 ( V_2 , V_14 ,
( V_254 |
V_255 ) ) ;
if ( V_19 ) {
for ( V_190 = 0 ; ( V_190 * 4 ) < V_249 ; V_190 ++ )
F_7 ( V_2 , ( V_256 + V_190 * 4 ) ,
* ( V_19 + V_190 ) ) ;
}
F_7 ( V_2 , V_257 ,
( F_60 ( ( V_248 & V_23 ) ,
V_258 ) |
F_60 ( V_249 , V_259 ) |
F_60 ( V_242 , V_260 ) ) ) ;
if ( V_18 &&
! ( F_4 ( V_2 , V_14 ,
V_254 , 500 ) ) )
F_65 ( V_2 , V_242 , V_19 , true ) ;
else {
F_65 ( V_2 , V_242 , V_19 , false ) ;
V_251 = true ;
}
if ( V_18 )
F_7 ( V_2 , V_61 , V_59 ) ;
return V_251 ;
}
void F_67 ( struct V_1 * V_2 , bool * V_261 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
T_1 V_130 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ( V_136 -> V_31 != V_63 ) ||
( V_136 -> V_96 & V_262 ) )
return;
F_47 ( V_130 , V_263 ) ;
V_130 [ V_264 ] = V_136 -> V_265 ++ ;
F_10 ( V_2 , V_35 , 0 , V_130 , 16 , true , false ) ;
if ( F_42 ( V_2 , V_154 , 0 , 50000 ) ) {
F_8 ( V_9 , V_17 , L_20 ) ;
} else {
* V_261 = false ;
F_8 ( V_9 , V_17 , L_21 ) ;
}
}
void F_68 ( struct V_1 * V_2 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
T_1 V_130 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ( V_136 -> V_31 != V_63 ) ||
( V_136 -> V_96 & V_262 ) )
return;
F_47 ( V_130 , V_266 ) ;
V_130 [ V_264 ] = V_136 -> V_267 ++ ;
F_10 ( V_2 , V_35 , 0 , V_130 , 16 , true , false ) ;
}
int F_69 ( struct V_1 * V_2 , T_1 V_191 , void * V_94 ,
T_2 V_249 , T_1 V_192 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_28 -> V_191 = V_191 ;
V_28 -> V_94 = V_94 ;
V_28 -> V_197 = V_249 ;
V_28 -> V_192 = V_192 ;
return F_58 ( V_2 , true , true , true ) ;
}
void F_70 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_176 , 0x00 ) ;
F_26 ( V_2 ) ;
}
T_1 F_25 ( struct V_1 * V_2 , T_1 V_268 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_269 = 0 , V_270 ;
V_37 V_45 ;
switch ( V_268 ) {
case V_74 :
if ( V_28 -> V_76 ) {
V_269 = F_6 ( V_2 , V_176 ) ;
if ( ( V_269 == 0xdeadbeef ) || ( V_269 == 0xffffffff ) )
V_269 = 0 ;
}
V_269 &= V_223 ;
break;
case V_271 :
V_269 = F_57 ( F_6 ( V_2 , V_272 ) ,
V_273 ) ;
V_269 <<= 4 ;
break;
case V_135 :
V_269 = F_57 ( F_6 ( V_2 , V_272 ) ,
V_274 ) ?
V_32 : V_63 ;
break;
case V_275 :
V_28 -> V_31 = V_63 ;
F_16 ( V_2 , true ) ;
F_19 ( V_2 , true ) ;
if ( V_28 -> V_55 )
F_21 ( V_2 , false , true ) ;
F_40 ( V_2 , false ) ;
break;
case V_276 :
F_1 ( V_2 ) ;
V_28 -> V_72 = true ;
if ( V_28 -> V_96 & V_277 ) {
if ( ( F_6 ( V_2 , V_114 ) &
V_115 ) !=
V_115 ) {
F_34 ( V_2 ) ;
}
}
break;
case V_278 :
F_18 ( V_2 , true ) ;
break;
case V_279 :
F_16 ( V_2 , true ) ;
break;
case V_280 :
V_45 = V_48 ;
F_20 ( V_2 , true , V_45 ) ;
break;
case V_281 :
V_270 = F_71 ( V_2 ) ;
if ( ( V_270 - V_28 -> V_282 ) <= V_283 ) {
F_8 ( F_5 ( V_2 ) , V_17 ,
L_22 ) ;
break;
}
F_8 ( F_5 ( V_2 ) , V_17 , L_23 ) ;
V_28 -> V_282 = V_270 ;
F_22 ( V_2 ) ;
V_28 -> V_52 = true ;
V_28 -> V_51 = true ;
F_19 ( V_2 , true ) ;
F_40 ( V_2 , false ) ;
break;
case V_284 :
V_269 = ! ( V_28 -> V_96 & V_285 ) ;
break;
case V_286 :
V_269 = ( ! V_28 -> V_55 && V_28 -> V_51 ) ? 1 : 0 ;
V_28 -> V_51 = false ;
break;
default:
break;
}
return V_269 ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
F_8 ( V_9 , V_17 , L_24 ) ;
F_14 ( V_2 , true ) ;
F_3 ( 50 ) ;
F_36 ( V_2 , V_111 , V_246 ) ;
V_28 -> V_71 = false ;
V_28 -> V_72 = true ;
F_64 ( V_2 , true ) ;
V_28 -> V_72 = true ;
}
void F_73 ( struct V_1 * V_2 )
{
T_1 V_287 , V_288 ;
int V_190 ;
V_37 V_289 , V_290 ;
for ( V_190 = 0 ; V_190 < V_291 ; V_190 ++ ) {
V_287 = F_6 ( V_2 , V_116 ) ;
if ( V_287 != 0xdeadbeef )
break;
F_3 ( V_292 ) ;
}
F_7 ( V_2 , V_116 , ( V_287 | F_74 ( 23 ) ) ) ;
for ( V_190 = 0 ; V_190 < V_291 ; V_190 ++ ) {
V_288 = F_6 ( V_2 , V_120 ) ;
if ( V_288 != 0xdeadbeef )
break;
F_3 ( V_292 ) ;
}
F_7 ( V_2 , V_120 , ( V_288 | F_74 ( 27 ) | F_74 ( 19 ) | F_74 ( 18 ) ) ) ;
V_289 = F_6 ( V_2 , V_293 ) & 0x3 ;
V_290 = F_57 ( F_6 ( V_2 , V_272 ) , V_274 ) ;
F_7 ( V_2 , V_116 , V_287 ) ;
F_7 ( V_2 , V_120 , V_288 ) ;
if ( V_290 && ( V_289 == 2 ) ) {
F_36 ( V_2 , V_294 , 0x1 ) ;
F_51 ( V_2 , V_294 , 0x1 ) ;
F_3 ( 50 ) ;
}
}
void F_62 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_92 ;
V_92 = F_57 ( F_6 ( V_2 , V_196 ) , V_295 ) ;
if ( V_28 -> V_296 == V_92 )
return;
F_8 ( V_9 , V_17 , L_25 ,
V_28 -> V_296 , V_92 ) ;
V_28 -> V_52 = true ;
V_28 -> V_51 = true ;
V_28 -> V_296 = 0 ;
}
T_1 F_44 ( struct V_1 * V_2 , bool V_297 , T_1 * V_298 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_92 , V_299 = 0 , V_300 ;
if ( V_297 ) {
V_300 = F_57 ( F_6 ( V_2 , V_196 ) , V_295 ) ;
if ( V_300 >= V_28 -> V_197 )
V_300 = 0 ;
V_28 -> V_296 = V_300 ;
return V_300 ;
}
F_7 ( V_2 , V_10 ,
V_153 ) ;
V_300 = F_57 ( F_6 ( V_2 , V_196 ) , V_295 ) ;
V_92 = V_300 ;
if ( ! V_92 )
V_92 = V_28 -> V_197 - 1 ;
else if ( V_92 >= V_28 -> V_197 ) {
if ( V_92 != 0xFFFF )
V_92 = 0 ;
} else {
V_92 -- ;
}
if ( ( V_92 == 0xFFFF ) || ( V_300 == V_28 -> V_296 ) ) {
V_92 = V_93 ;
V_299 = V_151 ;
goto V_301;
}
for (; ; ) {
T_1 V_302 ;
if ( V_92 != V_28 -> V_296 )
V_299 = V_152 ;
else
V_299 = V_151 ;
V_302 = V_28 -> V_296 ;
if ( V_302 >= V_28 -> V_197 )
V_302 = 0 ;
V_28 -> V_296 ++ ;
if ( V_28 -> V_296 >= V_28 -> V_197 )
V_28 -> V_296 = 0 ;
if ( F_32 ( V_2 , V_302 ) ) {
V_92 = V_302 ;
break;
}
if ( V_299 == V_151 ) {
V_92 = V_93 ;
break;
}
}
if ( V_92 != V_93 )
V_92 <<= 4 ;
V_301:
if ( V_298 )
* V_298 = V_299 ;
return V_92 ;
}
void F_75 ( struct V_1 * V_2 , V_37 V_303 , V_37 V_304 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_28 -> V_141 = V_303 ;
V_28 -> V_142 = V_304 ;
V_28 -> V_30 = true ;
F_8 ( F_5 ( V_2 ) , V_17 , L_26 ,
V_28 -> V_141 , V_28 -> V_142 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_28 -> V_43 = true ;
F_19 ( V_2 , true ) ;
}
T_2 F_77 ( struct V_1 * V_2 , V_37 V_305 )
{
if ( ! V_2 -> V_29 . V_28 . V_306 )
goto V_301;
if ( V_305 == V_307 )
return V_308 ;
else if ( V_305 == V_309 )
return V_310 ;
V_301:
return - 1 ;
}
