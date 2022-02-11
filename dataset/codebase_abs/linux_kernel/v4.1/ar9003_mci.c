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
if ( V_28 -> V_71 && F_23 ( V_28 ) ) {
F_11 ( V_2 , true ) ;
F_3 ( 5 ) ;
}
if ( V_28 -> V_71 && ! V_28 -> V_72 && F_23 ( V_28 ) ) {
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
( F_24 ( V_2 , V_10 ,
V_13 ) ) &&
( F_24 ( V_2 , V_10 ,
V_12 ) == 0 ) ) {
F_7 ( V_2 , V_10 ,
V_13 ) ;
F_7 ( V_2 , V_14 ,
V_15 ) ;
}
F_7 ( V_2 , V_61 , V_59 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( F_26 ( V_2 , V_74 ) &&
( V_28 -> V_31 != V_32 ) &&
! V_28 -> V_75 ) {
F_21 ( V_2 , true , true ) ;
}
V_28 -> V_76 = false ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_61 , 0 ) ;
F_7 ( V_2 , V_77 , 0 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_61 , V_78 ) ;
F_7 ( V_2 , V_77 ,
V_79 ) ;
}
static bool F_29 ( struct V_1 * V_2 , T_1 V_80 )
{
T_1 V_81 ;
V_81 = F_6 ( V_2 , V_10 ) ;
return ( ( V_81 & V_80 ) == V_80 ) ;
}
void F_30 ( struct V_1 * V_2 , T_1 * V_82 ,
T_1 * V_83 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
* V_82 = V_28 -> V_82 ;
* V_83 = V_28 -> V_83 ;
V_28 -> V_82 = 0 ;
V_28 -> V_83 = 0 ;
}
void F_31 ( struct V_1 * V_2 , enum V_84 * V_85 )
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
static void F_32 ( struct V_1 * V_2 , bool V_71 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( ! V_28 -> V_72 &&
( V_28 -> V_71 != V_71 ) )
V_28 -> V_72 = true ;
V_28 -> V_71 = V_71 ;
}
static bool F_33 ( struct V_1 * V_2 , T_1 V_90 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 * V_19 ;
T_1 V_91 , V_92 ;
if ( V_90 == V_93 )
return false ;
V_92 = V_90 << 4 ;
V_19 = ( T_1 * ) ( V_28 -> V_94 + V_92 ) ;
V_91 = F_34 ( V_19 ) ;
if ( V_91 == V_95 )
return false ;
return true ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( V_28 -> V_96 & V_97 ) {
F_36 ( V_2 , 3 , V_98 ) ;
F_36 ( V_2 , 2 , V_99 ) ;
F_36 ( V_2 , 1 , V_100 ) ;
F_36 ( V_2 , 0 , V_101 ) ;
} else if ( V_28 -> V_96 & V_102 ) {
F_36 ( V_2 , 3 , V_103 ) ;
F_36 ( V_2 , 2 , V_104 ) ;
F_36 ( V_2 , 1 , V_105 ) ;
F_36 ( V_2 , 0 , V_106 ) ;
F_36 ( V_2 , 5 , V_107 ) ;
} else if ( V_28 -> V_96 & V_108 ) {
F_36 ( V_2 , 3 , V_105 ) ;
F_36 ( V_2 , 2 , V_106 ) ;
F_36 ( V_2 , 1 , V_100 ) ;
F_36 ( V_2 , 0 , V_101 ) ;
} else
return;
F_37 ( V_2 , V_109 , V_110 ) ;
F_2 ( V_2 , V_111 , V_112 , 1 ) ;
F_2 ( V_2 , V_111 , V_113 , 0 ) ;
F_37 ( V_2 , V_114 , V_115 ) ;
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
static bool F_38 ( struct V_1 * V_2 , bool V_18 ,
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
static void F_39 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_134 ;
V_134 = F_26 ( V_2 , V_135 ) ;
if ( V_28 -> V_31 != V_134 )
V_28 -> V_31 = V_134 ;
if ( V_28 -> V_31 != V_32 ) {
F_16 ( V_2 , true ) ;
F_19 ( V_2 , true ) ;
if ( V_28 -> V_55 == true )
F_21 ( V_2 , false , true ) ;
}
}
void F_40 ( struct V_1 * V_2 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
if ( ! V_136 -> V_76 )
return;
F_39 ( V_2 ) ;
F_41 ( V_2 , true ) ;
if ( ( V_136 -> V_31 == V_63 ) &&
( V_136 -> V_52 == true ) ) {
V_136 -> V_51 = true ;
}
}
static void F_42 ( struct V_1 * V_2 , V_37 V_137 ,
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
static T_1 F_43 ( struct V_1 * V_2 , V_37 V_137 ,
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
F_44 ( V_139 ) ;
V_139 = NULL ;
}
if ( V_147 != V_152 )
V_7 = F_4 ( V_2 ,
V_10 ,
V_153 ,
V_7 ) ;
if ( ! V_7 )
break;
V_92 = F_45 ( V_2 , & V_147 ) ;
if ( V_92 == V_93 )
continue;
V_139 = ( T_1 * ) ( V_28 -> V_94 + V_92 ) ;
V_91 = F_34 ( V_139 ) ;
V_148 = F_46 ( V_139 ) ;
if ( F_47 ( V_91 ) ) {
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
F_48 ( V_19 ,
V_156 ) ;
F_10 ( V_2 , V_35 , 0 , V_19 , 16 ,
false , false ) ;
continue;
} else {
F_8 ( V_9 , V_17 , L_12 ,
* ( V_139 + 1 ) ) ;
V_146 ++ ;
F_42 ( V_2 , V_91 ,
V_148 , V_139 ) ;
}
}
if ( V_139 ) {
F_44 ( V_139 ) ;
V_139 = NULL ;
}
if ( V_7 <= 0 )
V_7 = 0 ;
while ( V_147 == V_152 ) {
V_92 = F_45 ( V_2 , & V_147 ) ;
if ( V_92 == V_93 )
break;
V_139 = ( T_1 * ) ( V_28 -> V_94 + V_92 ) ;
V_91 = F_34 ( V_139 ) ;
V_148 = F_46 ( V_139 ) ;
if ( ! F_47 ( V_91 ) )
F_42 ( V_2 , V_91 ,
V_148 , V_139 ) ;
F_44 ( V_139 ) ;
}
return V_7 ;
}
bool F_49 ( struct V_1 * V_2 , struct V_157 * V_158 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
T_1 V_19 [ 4 ] = { 0 , 0 , 0 , 0 } ;
F_32 ( V_2 , F_50 ( V_158 ) ) ;
if ( V_136 -> V_31 != V_159 )
return false ;
V_136 -> V_31 = V_160 ;
F_27 ( V_2 ) ;
F_48 ( V_19 , V_156 ) ;
F_10 ( V_2 , V_35 , 0 , V_19 ,
16 , true , false ) ;
if ( F_43 ( V_2 , V_150 ,
0 , 25000 ) )
F_8 ( V_9 , V_17 , L_13 ) ;
else
F_8 ( V_9 , V_17 ,
L_14 ) ;
V_136 -> V_31 = V_63 ;
F_28 ( V_2 ) ;
return true ;
}
int F_51 ( struct V_1 * V_2 , struct V_157 * V_158 ,
struct V_161 * V_162 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
if ( ! V_136 -> V_76 )
return 0 ;
if ( ! F_50 ( V_158 ) || ( V_136 -> V_31 != V_32 ) )
goto exit;
if ( ! F_29 ( V_2 , V_163 ) &&
! F_29 ( V_2 , V_11 ) )
goto exit;
F_7 ( V_2 , V_10 ,
( V_163 |
V_11 ) ) ;
F_9 ( V_2 , true ) ;
F_13 ( V_2 , true ) ;
F_3 ( 1 ) ;
if ( F_50 ( V_158 ) )
F_11 ( V_2 , true ) ;
V_136 -> V_31 = V_63 ;
F_52 ( V_2 , V_164 ,
1 << V_165 ) ;
if ( V_162 ) {
F_53 ( V_166 , & V_162 -> V_167 ) ;
F_53 ( V_168 , & V_162 -> V_167 ) ;
F_53 ( V_169 , & V_162 -> V_167 ) ;
}
if ( ! F_54 ( V_2 , V_158 ) )
return - V_170 ;
F_37 ( V_2 , V_164 ,
1 << V_165 ) ;
exit:
F_28 ( V_2 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
F_7 ( V_2 , V_171 , 0xffff0000 ) ;
F_7 ( V_2 , V_172 , 0xffffffff ) ;
F_7 ( V_2 , V_173 , 0xffffffff ) ;
F_7 ( V_2 , V_174 , 0xffffffff ) ;
F_7 ( V_2 , V_175 , 0xffffffff ) ;
F_37 ( V_2 , V_176 , V_177 ) ;
F_3 ( 10 ) ;
if ( F_23 ( V_28 ) ) {
F_14 ( V_2 , true ) ;
F_3 ( 5 ) ;
}
F_15 ( V_2 , true ) ;
}
static void F_56 ( struct V_1 * V_2 , bool V_178 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_179 ;
if ( ! V_178 ) {
F_52 ( V_2 , V_180 ,
V_181 ) ;
return;
}
F_2 ( V_2 , V_182 , V_183 , 1 ) ;
F_2 ( V_2 , V_182 ,
V_184 , 1 ) ;
if ( F_57 ( V_2 ) )
F_2 ( V_2 , V_185 , V_186 , 1 ) ;
if ( ! ( V_28 -> V_96 & V_187 ) ) {
V_179 = F_58 ( V_28 -> V_96 , V_188 ) ;
F_2 ( V_2 , V_180 ,
V_189 , V_179 ) ;
F_2 ( V_2 , V_180 ,
V_190 , 1 ) ;
} else
F_2 ( V_2 , V_180 ,
V_190 , 0 ) ;
F_2 ( V_2 , V_180 ,
V_181 , 1 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( ! F_57 ( V_2 ) )
return;
if ( V_28 -> V_96 & V_191 ) {
F_2 ( V_2 , V_192 ,
V_193 , 1 ) ;
F_2 ( V_2 , V_192 ,
V_194 ,
V_195 ) ;
} else {
F_2 ( V_2 , V_192 ,
V_193 , 0 ) ;
}
}
static void F_60 ( struct V_1 * V_2 )
{
T_1 V_196 ;
V_196 = F_61 ( 1 , V_197 ) |
F_61 ( 1 , V_198 ) |
F_61 ( 1 , V_199 ) |
F_61 ( 1 , V_200 ) |
F_61 ( 1 , V_201 ) |
F_61 ( 1 , V_202 ) |
F_61 ( 0 , V_203 ) |
F_61 ( 0 , V_204 ) |
F_61 ( 0 , V_181 ) ;
F_2 ( V_2 , V_116 ,
V_205 , 0x1 ) ;
F_7 ( V_2 , V_180 , V_196 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
T_1 V_196 ;
V_196 = F_61 ( 1 , V_197 ) |
F_61 ( 1 , V_198 ) |
F_61 ( 0 , V_199 ) |
F_61 ( 0 , V_200 ) |
F_61 ( 2 , V_201 ) |
F_61 ( 1 , V_202 ) |
F_61 ( 0 , V_203 ) |
F_61 ( 0 , V_204 ) |
F_61 ( 0 , V_181 ) ;
F_2 ( V_2 , V_116 ,
V_205 , 0x0 ) ;
F_7 ( V_2 , V_180 , V_196 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
T_1 V_196 ;
V_196 = F_61 ( 1 , V_197 ) |
F_61 ( 1 , V_198 ) |
F_61 ( 1 , V_199 ) |
F_61 ( 1 , V_200 ) |
F_61 ( 2 , V_201 ) |
F_61 ( 3 , V_202 ) |
F_61 ( 0 , V_203 ) |
F_61 ( 0 , V_204 ) |
F_61 ( 0 , V_181 ) ;
F_7 ( V_2 , V_180 , V_196 ) ;
}
int F_64 ( struct V_1 * V_2 , bool V_206 , bool V_71 ,
bool V_207 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_196 , V_208 ;
F_8 ( V_9 , V_17 , L_15 ,
V_207 , V_71 ) ;
if ( F_6 ( V_2 , V_180 ) == 0xdeadbeef ) {
F_65 ( V_9 , L_16 ) ;
return - V_209 ;
}
F_7 ( V_2 , V_210 , V_28 -> V_211 ) ;
F_7 ( V_2 , V_212 , V_28 -> V_213 ) ;
F_7 ( V_2 , V_214 , V_28 -> V_215 ) ;
if ( F_57 ( V_2 ) ) {
V_37 V_216 = F_58 ( V_28 -> V_96 , V_217 ) ;
if ( V_216 == V_218 )
F_60 ( V_2 ) ;
else
F_62 ( V_2 ) ;
} else {
F_63 ( V_2 ) ;
}
if ( V_71 && ! ( V_28 -> V_96 & V_219 ) )
F_56 ( V_2 , true ) ;
else
F_56 ( V_2 , false ) ;
F_37 ( V_2 , V_111 ,
V_220 ) ;
F_2 ( V_2 , V_221 ,
V_222 , 20 ) ;
F_2 ( V_2 , V_116 , V_223 , 0 ) ;
F_2 ( V_2 , V_224 , V_225 , 0 ) ;
F_2 ( V_2 , V_226 , V_227 , 0x3D090 ) ;
if ( V_28 -> V_96 & V_228 ) {
F_2 ( V_2 , V_116 ,
V_229 , 0 ) ;
F_2 ( V_2 , V_116 ,
V_230 , 0x7f ) ;
F_2 ( V_2 , V_180 ,
V_231 , 0 ) ;
for ( V_208 = 0 ; V_208 < 8 ; V_208 ++ )
F_7 ( V_2 , F_66 ( V_208 ) , 0x7f7f7f7f ) ;
}
V_196 = F_58 ( V_28 -> V_96 , V_232 ) ;
F_2 ( V_2 , V_176 , V_233 , V_196 ) ;
F_37 ( V_2 , V_180 , V_234 ) ;
V_196 = F_6 ( V_2 , V_3 ) ;
V_196 |= F_61 ( 1 , V_235 ) ;
F_7 ( V_2 , V_3 , V_196 ) ;
F_3 ( 1 ) ;
V_196 &= ~ F_61 ( 1 , V_235 ) ;
F_7 ( V_2 , V_3 , V_196 ) ;
if ( V_207 ) {
F_55 ( V_2 ) ;
F_3 ( 100 ) ;
}
F_67 ( V_2 ) ;
V_196 |= F_61 ( 1 , V_236 ) ;
F_7 ( V_2 , V_3 , V_196 ) ;
F_3 ( 1 ) ;
V_196 &= ~ F_61 ( 1 , V_236 ) ;
F_7 ( V_2 , V_3 , V_196 ) ;
F_26 ( V_2 , V_237 ) ;
F_7 ( V_2 , V_171 ,
( F_61 ( 0xe801 , V_238 ) |
F_61 ( 0x0000 , V_239 ) ) ) ;
if ( F_23 ( V_28 ) )
F_52 ( V_2 , V_176 ,
V_177 ) ;
else
F_37 ( V_2 , V_176 ,
V_177 ) ;
F_35 ( V_2 ) ;
V_28 -> V_76 = true ;
F_22 ( V_2 ) ;
F_59 ( V_2 ) ;
if ( V_206 )
F_28 ( V_2 ) ;
if ( F_68 ( V_2 ) )
F_69 ( V_2 ) ;
return 0 ;
}
void F_70 ( struct V_1 * V_2 , bool V_240 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
F_27 ( V_2 ) ;
if ( V_136 -> V_76 && ! V_240 ) {
F_55 ( V_2 ) ;
F_3 ( 20 ) ;
F_7 ( V_2 , V_180 , 0 ) ;
}
V_136 -> V_31 = V_32 ;
V_136 -> V_76 = false ;
}
static void F_71 ( struct V_1 * V_2 , bool V_18 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_241 , V_242 , V_243 ;
if ( ! V_28 -> V_72 || ( V_28 -> V_31 == V_32 ) )
return;
if ( V_28 -> V_71 ) {
V_241 = V_244 ;
V_243 = V_245 ;
V_242 = V_246 ;
} else {
V_241 = V_247 ;
V_243 = V_248 ;
V_242 = V_249 ;
}
if ( V_243 )
F_38 ( V_2 , V_18 ,
V_250 ,
V_243 ) ;
if ( V_242 )
F_38 ( V_2 , V_18 ,
V_251 ,
V_242 ) ;
}
static void F_72 ( struct V_1 * V_2 , V_37 V_252 ,
T_1 * V_19 , bool V_253 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_37 type , V_128 ;
if ( V_252 != V_35 )
return;
type = F_34 ( V_19 ) ;
V_128 = F_46 ( V_19 ) ;
if ( type != V_33 )
return;
switch ( V_128 ) {
case V_131 :
if ( * ( ( ( V_37 * ) V_19 ) + V_132 ) ==
V_254 )
break;
V_28 -> V_72 = V_253 ;
break;
case V_44 :
V_28 -> V_43 = V_253 ;
break;
case V_54 :
if ( * ( ( ( V_37 * ) V_19 ) + V_56 ) ==
V_58 ) {
V_28 -> V_55 = V_253 ;
if ( ! V_253 )
V_28 -> V_75 = false ;
}
if ( * ( ( ( V_37 * ) V_19 ) + V_56 ) ==
V_57 ) {
V_28 -> V_75 = ! V_253 ;
}
break;
default:
break;
}
}
void F_41 ( struct V_1 * V_2 , bool V_255 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
if ( ! V_28 -> V_72 && ! V_255 )
return;
if ( V_28 -> V_71 ) {
F_71 ( V_2 , true ) ;
F_11 ( V_2 , true ) ;
F_3 ( 5 ) ;
F_52 ( V_2 , V_176 ,
V_177 ) ;
F_52 ( V_2 , V_111 ,
V_256 ) ;
if ( ! ( V_28 -> V_96 & V_219 ) )
F_56 ( V_2 , true ) ;
if ( F_73 ( V_2 ) )
F_7 ( V_2 , V_257 , 0x02 ) ;
} else {
F_14 ( V_2 , true ) ;
F_3 ( 5 ) ;
F_37 ( V_2 , V_176 ,
V_177 ) ;
F_37 ( V_2 , V_111 ,
V_256 ) ;
F_56 ( V_2 , false ) ;
F_71 ( V_2 , true ) ;
}
}
bool F_10 ( struct V_1 * V_2 , V_37 V_252 , T_1 V_258 ,
T_1 * V_19 , V_37 V_259 , bool V_18 ,
bool V_260 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
bool V_261 = false ;
T_1 V_196 ;
T_1 V_59 ;
int V_208 ;
V_59 = F_6 ( V_2 , V_61 ) ;
V_196 = F_6 ( V_2 , V_180 ) ;
if ( ( V_196 == 0xdeadbeef ) || ! ( V_196 & V_234 ) ) {
F_8 ( V_9 , V_17 ,
L_17 ,
V_252 , ( V_2 -> V_262 == V_263 ) ? 1 : 0 ) ;
F_72 ( V_2 , V_252 , V_19 , true ) ;
return false ;
} else if ( V_260 && ( V_28 -> V_31 == V_32 ) ) {
F_8 ( V_9 , V_17 ,
L_18 ,
V_252 ) ;
F_72 ( V_2 , V_252 , V_19 , true ) ;
return false ;
}
if ( V_18 )
F_7 ( V_2 , V_61 , 0 ) ;
F_7 ( V_2 , V_14 ,
( V_264 |
V_265 ) ) ;
if ( V_19 ) {
for ( V_208 = 0 ; ( V_208 * 4 ) < V_259 ; V_208 ++ )
F_7 ( V_2 , ( V_266 + V_208 * 4 ) ,
* ( V_19 + V_208 ) ) ;
}
F_7 ( V_2 , V_267 ,
( F_61 ( ( V_258 & V_23 ) ,
V_268 ) |
F_61 ( V_259 , V_269 ) |
F_61 ( V_252 , V_270 ) ) ) ;
if ( V_18 &&
! ( F_4 ( V_2 , V_14 ,
V_264 , 500 ) ) )
F_72 ( V_2 , V_252 , V_19 , true ) ;
else {
F_72 ( V_2 , V_252 , V_19 , false ) ;
V_261 = true ;
}
if ( V_18 )
F_7 ( V_2 , V_61 , V_59 ) ;
return V_261 ;
}
void F_74 ( struct V_1 * V_2 , bool * V_271 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
T_1 V_130 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ( V_136 -> V_31 != V_63 ) ||
( V_136 -> V_96 & V_272 ) )
return;
F_48 ( V_130 , V_273 ) ;
V_130 [ V_274 ] = V_136 -> V_275 ++ ;
F_10 ( V_2 , V_35 , 0 , V_130 , 16 , true , false ) ;
if ( F_43 ( V_2 , V_154 , 0 , 50000 ) ) {
F_8 ( V_9 , V_17 , L_19 ) ;
} else {
* V_271 = false ;
F_8 ( V_9 , V_17 , L_20 ) ;
}
}
void F_75 ( struct V_1 * V_2 )
{
struct V_27 * V_136 = & V_2 -> V_29 . V_28 ;
T_1 V_130 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( ( V_136 -> V_31 != V_63 ) ||
( V_136 -> V_96 & V_272 ) )
return;
F_48 ( V_130 , V_276 ) ;
V_130 [ V_274 ] = V_136 -> V_277 ++ ;
F_10 ( V_2 , V_35 , 0 , V_130 , 16 , true , false ) ;
}
int F_76 ( struct V_1 * V_2 , T_1 V_211 , void * V_94 ,
T_2 V_259 , T_1 V_215 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_28 -> V_211 = V_211 ;
V_28 -> V_94 = V_94 ;
V_28 -> V_213 = V_259 ;
V_28 -> V_215 = V_215 ;
return F_64 ( V_2 , true , true , true ) ;
}
void F_77 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_180 , 0x00 ) ;
F_27 ( V_2 ) ;
}
T_1 F_26 ( struct V_1 * V_2 , T_1 V_278 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_279 = 0 , V_280 ;
V_37 V_45 ;
switch ( V_278 ) {
case V_74 :
if ( V_28 -> V_76 ) {
V_279 = F_6 ( V_2 , V_180 ) ;
if ( ( V_279 == 0xdeadbeef ) || ( V_279 == 0xffffffff ) )
V_279 = 0 ;
}
V_279 &= V_234 ;
break;
case V_237 :
V_279 = F_58 ( F_6 ( V_2 , V_212 ) , V_281 ) ;
if ( V_279 < V_28 -> V_213 )
V_28 -> V_282 = V_279 ;
else
V_28 -> V_282 = 0 ;
break;
case V_283 :
V_279 = F_58 ( F_6 ( V_2 , V_284 ) ,
V_285 ) ;
V_279 <<= 4 ;
break;
case V_135 :
V_279 = F_58 ( F_6 ( V_2 , V_284 ) ,
V_286 ) ?
V_32 : V_63 ;
break;
case V_287 :
V_28 -> V_31 = V_63 ;
F_16 ( V_2 , true ) ;
F_19 ( V_2 , true ) ;
if ( V_28 -> V_55 )
F_21 ( V_2 , false , true ) ;
F_41 ( V_2 , false ) ;
break;
case V_288 :
F_1 ( V_2 ) ;
V_28 -> V_72 = true ;
if ( V_28 -> V_96 & V_289 ) {
if ( ( F_6 ( V_2 , V_114 ) &
V_115 ) !=
V_115 ) {
F_35 ( V_2 ) ;
}
}
break;
case V_290 :
F_18 ( V_2 , true ) ;
break;
case V_291 :
F_16 ( V_2 , true ) ;
break;
case V_292 :
V_45 = V_48 ;
F_20 ( V_2 , true , V_45 ) ;
break;
case V_293 :
V_280 = F_78 ( V_2 ) ;
if ( ( V_280 - V_28 -> V_294 ) <= V_295 ) {
F_8 ( F_5 ( V_2 ) , V_17 ,
L_21 ) ;
break;
}
F_8 ( F_5 ( V_2 ) , V_17 , L_22 ) ;
V_28 -> V_294 = V_280 ;
F_22 ( V_2 ) ;
V_28 -> V_52 = true ;
V_28 -> V_51 = true ;
F_19 ( V_2 , true ) ;
F_41 ( V_2 , false ) ;
break;
case V_296 :
V_279 = ! ( V_28 -> V_96 & V_297 ) ;
break;
case V_298 :
V_279 = ( ! V_28 -> V_55 && V_28 -> V_51 ) ? 1 : 0 ;
V_28 -> V_51 = false ;
break;
case V_299 :
if ( F_68 ( V_2 ) )
V_279 = F_79 ( V_2 ) ;
break;
case V_300 :
if ( F_68 ( V_2 ) )
F_69 ( V_2 ) ;
break;
case V_301 :
if ( F_68 ( V_2 ) )
V_279 = F_80 ( V_2 ) ;
break;
case V_302 :
if ( F_68 ( V_2 ) )
V_279 = F_81 ( V_2 ) ;
break;
default:
break;
}
return V_279 ;
}
void F_82 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
F_8 ( V_9 , V_17 , L_23 ) ;
F_14 ( V_2 , true ) ;
F_3 ( 50 ) ;
F_37 ( V_2 , V_111 , V_256 ) ;
V_28 -> V_71 = false ;
V_28 -> V_72 = true ;
F_71 ( V_2 , true ) ;
V_28 -> V_72 = true ;
}
void F_83 ( struct V_1 * V_2 )
{
T_1 V_303 , V_304 ;
int V_208 ;
V_37 V_305 , V_306 ;
for ( V_208 = 0 ; V_208 < V_307 ; V_208 ++ ) {
V_303 = F_6 ( V_2 , V_116 ) ;
if ( V_303 != 0xdeadbeef )
break;
F_3 ( V_308 ) ;
}
F_7 ( V_2 , V_116 , ( V_303 | F_84 ( 23 ) ) ) ;
for ( V_208 = 0 ; V_208 < V_307 ; V_208 ++ ) {
V_304 = F_6 ( V_2 , V_120 ) ;
if ( V_304 != 0xdeadbeef )
break;
F_3 ( V_308 ) ;
}
F_7 ( V_2 , V_120 , ( V_304 | F_84 ( 27 ) | F_84 ( 19 ) | F_84 ( 18 ) ) ) ;
V_305 = F_6 ( V_2 , V_309 ) & 0x3 ;
V_306 = F_58 ( F_6 ( V_2 , V_284 ) , V_286 ) ;
F_7 ( V_2 , V_116 , V_303 ) ;
F_7 ( V_2 , V_120 , V_304 ) ;
if ( V_306 && ( V_305 == 2 ) ) {
F_37 ( V_2 , V_310 , 0x1 ) ;
F_52 ( V_2 , V_310 , 0x1 ) ;
F_3 ( 50 ) ;
}
}
void F_67 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_92 ;
V_92 = F_58 ( F_6 ( V_2 , V_212 ) , V_281 ) ;
if ( V_28 -> V_282 == V_92 )
return;
F_8 ( V_9 , V_17 , L_24 ,
V_28 -> V_282 , V_92 ) ;
V_28 -> V_52 = true ;
V_28 -> V_51 = true ;
V_28 -> V_282 = 0 ;
}
T_1 F_45 ( struct V_1 * V_2 , T_1 * V_311 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
T_1 V_92 , V_312 = 0 , V_313 ;
F_7 ( V_2 , V_10 ,
V_153 ) ;
V_313 = F_58 ( F_6 ( V_2 , V_212 ) , V_281 ) ;
V_92 = V_313 ;
if ( ! V_92 )
V_92 = V_28 -> V_213 - 1 ;
else if ( V_92 >= V_28 -> V_213 ) {
if ( V_92 != 0xFFFF )
V_92 = 0 ;
} else {
V_92 -- ;
}
if ( ( V_92 == 0xFFFF ) || ( V_313 == V_28 -> V_282 ) ) {
V_92 = V_93 ;
V_312 = V_151 ;
goto V_314;
}
for (; ; ) {
T_1 V_315 ;
if ( V_92 != V_28 -> V_282 )
V_312 = V_152 ;
else
V_312 = V_151 ;
V_315 = V_28 -> V_282 ;
if ( V_315 >= V_28 -> V_213 )
V_315 = 0 ;
V_28 -> V_282 ++ ;
if ( V_28 -> V_282 >= V_28 -> V_213 )
V_28 -> V_282 = 0 ;
if ( F_33 ( V_2 , V_315 ) ) {
V_92 = V_315 ;
break;
}
if ( V_312 == V_151 ) {
V_92 = V_93 ;
break;
}
}
if ( V_92 != V_93 )
V_92 <<= 4 ;
V_314:
if ( V_311 )
* V_311 = V_312 ;
return V_92 ;
}
void F_85 ( struct V_1 * V_2 , V_37 V_316 , V_37 V_317 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_28 -> V_141 = V_316 ;
V_28 -> V_142 = V_317 ;
V_28 -> V_30 = true ;
F_8 ( F_5 ( V_2 ) , V_17 , L_25 ,
V_28 -> V_141 , V_28 -> V_142 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_29 . V_28 ;
V_28 -> V_43 = true ;
F_19 ( V_2 , true ) ;
}
T_2 F_87 ( struct V_1 * V_2 , V_37 V_318 )
{
if ( ! V_2 -> V_29 . V_28 . V_319 )
goto V_314;
if ( V_318 == V_320 )
return V_321 ;
else if ( V_318 == V_322 )
return V_323 ;
V_314:
return - 1 ;
}
