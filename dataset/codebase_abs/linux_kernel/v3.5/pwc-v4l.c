int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
int V_7 , V_8 ;
V_4 = & V_2 -> V_9 ;
V_7 = F_2 ( V_4 , 20 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_10 , V_11 , & V_8 ) ;
if ( V_7 || V_8 > 127 )
V_8 = 63 ;
V_2 -> V_12 = F_4 ( V_4 , & V_13 ,
V_14 , 0 , 127 , 1 , V_8 ) ;
V_7 = F_3 ( V_2 , V_10 , V_15 , & V_8 ) ;
if ( V_7 || V_8 > 63 )
V_8 = 31 ;
V_2 -> V_16 = F_4 ( V_4 , & V_13 ,
V_17 , 0 , 63 , 1 , V_8 ) ;
if ( V_2 -> type >= 675 ) {
if ( V_2 -> type < 730 )
V_2 -> V_18 = V_19 ;
else
V_2 -> V_18 = V_20 ;
V_7 = F_5 ( V_2 , V_21 , V_2 -> V_18 ,
& V_8 ) ;
if ( V_7 || V_8 < - 100 || V_8 > 100 )
V_8 = 0 ;
V_2 -> V_22 = F_4 ( V_4 , & V_13 ,
V_23 , - 100 , 100 , 1 , V_8 ) ;
}
V_7 = F_3 ( V_2 , V_10 , V_24 , & V_8 ) ;
if ( V_7 || V_8 > 31 )
V_8 = 15 ;
V_2 -> gamma = F_4 ( V_4 , & V_13 ,
V_25 , 0 , 31 , 1 , V_8 ) ;
V_7 = F_3 ( V_2 , V_21 , V_26 , & V_8 ) ;
if ( V_7 || V_8 > V_27 )
V_8 = V_27 ;
V_6 = V_28 ;
V_6 . V_29 = F_6 ( V_6 . V_30 ) ;
V_6 . V_8 = V_8 ;
V_2 -> V_31 = F_7 ( V_4 , & V_6 , NULL ) ;
if ( ! V_2 -> V_31 )
return V_4 -> error ;
V_7 = F_3 ( V_2 , V_21 ,
V_32 , & V_8 ) ;
if ( V_7 )
V_8 = 127 ;
V_2 -> V_33 = F_4 ( V_4 , & V_13 ,
V_34 , 0 , 255 , 1 , V_8 ) ;
V_7 = F_3 ( V_2 , V_21 ,
V_35 , & V_8 ) ;
if ( V_7 )
V_8 = 127 ;
V_2 -> V_36 = F_4 ( V_4 , & V_13 ,
V_37 , 0 , 255 , 1 , V_8 ) ;
F_8 ( 3 , & V_2 -> V_31 , V_38 , true ) ;
V_7 = F_3 ( V_2 , V_10 , V_39 , & V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0 ;
V_2 -> V_40 = F_4 ( V_4 , & V_13 ,
V_41 , 0 , 1 , 1 , V_8 == 0 ) ;
if ( ! V_2 -> V_40 )
return V_4 -> error ;
V_7 = F_3 ( V_2 , V_10 , V_42 , & V_8 ) ;
if ( V_7 || V_8 > 63 )
V_8 = 31 ;
V_2 -> V_43 = F_4 ( V_4 , & V_13 ,
V_44 , 0 , 63 , 1 , V_8 ) ;
if ( F_9 ( V_2 -> type ) ) {
V_7 = F_3 ( V_2 , V_10 , V_45 ,
& V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0 ;
V_2 -> V_46 = F_10 ( V_4 ,
& V_13 ,
V_47 ,
1 , 0 , V_8 != 0 ) ;
if ( ! V_2 -> V_46 )
return V_4 -> error ;
V_7 = F_11 ( V_2 , V_48 ,
V_49 , & V_8 ) ;
if ( V_7 || V_8 > 655 )
V_8 = 655 ;
V_2 -> V_50 = F_4 ( V_4 , & V_13 ,
V_51 , 0 , 655 , 1 , V_8 ) ;
F_8 ( 2 , & V_2 -> V_40 , 0 , true ) ;
F_8 ( 2 , & V_2 -> V_46 ,
V_52 , true ) ;
} else if ( F_12 ( V_2 -> type ) ) {
V_7 = F_11 ( V_2 , V_48 ,
V_49 , & V_8 ) ;
if ( V_7 || V_8 > 255 )
V_8 = 255 ;
V_2 -> V_50 = F_4 ( V_4 , & V_13 ,
V_51 , 0 , 255 , 1 , V_8 ) ;
V_2 -> V_53 [ 0 ] = V_2 -> V_40 ;
V_2 -> V_53 [ 1 ] = V_2 -> V_43 ;
V_2 -> V_53 [ 2 ] = V_2 -> V_50 ;
F_8 ( 3 , V_2 -> V_53 ,
0 , true ) ;
}
V_7 = F_3 ( V_2 , V_21 , V_54 ,
& V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0xff ;
V_2 -> V_55 = F_10 ( V_4 , & V_13 ,
V_56 , 1 , 0 , V_8 == 0 ) ;
V_7 = F_3 ( V_2 , V_10 , V_57 , & V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0 ;
V_6 = V_58 ;
V_6 . V_8 = V_8 == 0 ;
V_2 -> V_59 = F_7 ( V_4 , & V_6 , NULL ) ;
if ( ! V_2 -> V_59 )
return V_4 -> error ;
V_7 = F_3 ( V_2 , V_10 , V_60 , & V_8 ) ;
if ( V_7 || V_8 > 63 )
V_8 = 31 ;
V_6 = V_61 ;
V_6 . V_8 = V_8 ;
V_2 -> V_62 = F_7 ( V_4 , & V_6 , NULL ) ;
F_8 ( 2 , & V_2 -> V_59 , 0 , false ) ;
V_7 = F_3 ( V_2 , V_10 ,
V_63 , & V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0 ;
V_6 = V_64 ;
V_6 . V_29 = F_6 ( V_6 . V_30 ) ;
V_6 . V_8 = V_8 == 0 ;
V_2 -> V_65 = F_7 ( V_4 , & V_6 , NULL ) ;
V_7 = F_3 ( V_2 , V_10 ,
V_66 , & V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0 ;
V_6 = V_67 ;
V_6 . V_29 = F_6 ( V_6 . V_30 ) ;
V_6 . V_8 = V_8 == 0 ;
V_2 -> V_68 = F_7 ( V_4 , & V_6 , NULL ) ;
V_7 = F_3 ( V_2 , V_10 ,
V_69 , & V_8 ) ;
if ( V_7 || V_8 > 3 )
V_8 = 2 ;
V_6 = V_70 ;
V_6 . V_8 = V_8 ;
V_2 -> V_71 = F_7 ( V_4 , & V_6 , NULL ) ;
V_2 -> V_72 = F_7 ( V_4 , & V_73 , NULL ) ;
V_2 -> V_74 = F_7 ( V_4 , & V_75 ,
NULL ) ;
if ( V_2 -> V_74 )
V_2 -> V_74 -> V_76 |= V_77 ;
V_2 -> V_78 = F_7 ( V_4 ,
& V_79 ,
NULL ) ;
if ( V_2 -> V_78 )
V_2 -> V_78 -> V_76 |= V_77 ;
V_7 = F_3 ( V_2 , V_21 ,
V_80 , & V_8 ) ;
if ( V_7 || V_8 < 1 || V_8 > 32 )
V_8 = 1 ;
V_6 = V_81 ;
V_6 . V_8 = V_8 ;
V_2 -> V_82 = F_7 ( V_4 , & V_6 , NULL ) ;
V_7 = F_3 ( V_2 , V_21 ,
V_83 , & V_8 ) ;
if ( V_7 || V_8 > 63 )
V_8 = 0 ;
V_6 = V_84 ;
V_6 . V_8 = V_8 ;
V_2 -> V_85 = F_7 ( V_4 , & V_6 , NULL ) ;
if ( ! ( V_2 -> V_86 & V_87 ) )
return V_4 -> error ;
V_2 -> V_88 = F_4 ( V_4 , & V_13 ,
V_89 , - 4480 , 4480 , 64 , 0 ) ;
if ( ! V_2 -> V_88 )
return V_4 -> error ;
V_2 -> V_90 = F_4 ( V_4 , & V_13 ,
V_91 , - 1920 , 1920 , 64 , 0 ) ;
V_2 -> V_92 = F_4 ( V_4 , & V_13 ,
V_93 , 0 , 0 , 0 , 0 ) ;
V_2 -> V_94 = F_4 ( V_4 , & V_13 ,
V_95 , 0 , 0 , 0 , 0 ) ;
F_13 ( 4 , & V_2 -> V_88 ) ;
return V_4 -> error ;
}
static void F_14 ( struct V_96 * V_97 ,
int V_98 , int V_99 , T_1 V_100 )
{
memset ( & V_97 -> V_101 . V_102 , 0 , sizeof( struct V_103 ) ) ;
V_97 -> V_101 . V_102 . V_98 = V_98 ;
V_97 -> V_101 . V_102 . V_99 = V_99 ;
V_97 -> V_101 . V_102 . V_104 = V_105 ;
V_97 -> V_101 . V_102 . V_106 = V_100 ;
V_97 -> V_101 . V_102 . V_107 = V_97 -> V_101 . V_102 . V_98 ;
V_97 -> V_101 . V_102 . V_108 = V_97 -> V_101 . V_102 . V_99 * V_97 -> V_101 . V_102 . V_98 * 3 / 2 ;
F_15 ( L_1
L_2 ,
V_97 -> V_101 . V_102 . V_98 ,
V_97 -> V_101 . V_102 . V_99 ,
V_97 -> V_101 . V_102 . V_107 ,
V_97 -> V_101 . V_102 . V_108 ,
( V_97 -> V_101 . V_102 . V_106 ) & 255 ,
( V_97 -> V_101 . V_102 . V_106 >> 8 ) & 255 ,
( V_97 -> V_101 . V_102 . V_106 >> 16 ) & 255 ,
( V_97 -> V_101 . V_102 . V_106 >> 24 ) & 255 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
int V_109 ;
if ( V_97 -> type != V_110 ) {
F_15 ( L_3 ) ;
return - V_111 ;
}
switch ( V_97 -> V_101 . V_102 . V_106 ) {
case V_112 :
break;
case V_113 :
if ( F_17 ( V_2 -> type ) ) {
F_15 ( L_4 ) ;
return - V_111 ;
}
break;
case V_114 :
if ( F_18 ( V_2 -> type ) ) {
F_15 ( L_5 ) ;
return - V_111 ;
}
break;
default:
F_15 ( L_6 ) ;
return - V_111 ;
}
V_109 = F_19 ( V_2 , V_97 -> V_101 . V_102 . V_98 , V_97 -> V_101 . V_102 . V_99 ) ;
F_14 ( V_97 ,
V_115 [ V_109 ] [ 0 ] ,
V_115 [ V_109 ] [ 1 ] ,
V_97 -> V_101 . V_102 . V_106 ) ;
return 0 ;
}
static int F_20 ( struct V_116 * V_116 , void * V_117 , struct V_96 * V_97 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
int V_118 , V_106 , V_119 = 0 ;
V_118 = F_16 ( V_2 , V_97 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( F_22 ( & V_2 -> V_120 ) )
return - V_121 ;
V_118 = F_23 ( V_2 , V_116 ) ;
if ( V_118 )
goto V_122;
if ( V_2 -> V_123 . V_124 ) {
V_118 = - V_125 ;
goto V_122;
}
V_106 = V_97 -> V_101 . V_102 . V_106 ;
F_15 ( L_7
L_8 ,
V_97 -> V_101 . V_102 . V_98 , V_97 -> V_101 . V_102 . V_99 , V_2 -> V_126 ,
( V_106 ) & 255 ,
( V_106 >> 8 ) & 255 ,
( V_106 >> 16 ) & 255 ,
( V_106 >> 24 ) & 255 ) ;
V_118 = F_24 ( V_2 , V_97 -> V_101 . V_102 . V_98 , V_97 -> V_101 . V_102 . V_99 ,
V_106 , 30 , & V_119 , 0 ) ;
F_15 ( L_9 , V_118 ) ;
F_14 ( V_97 , V_2 -> V_98 , V_2 -> V_99 , V_2 -> V_100 ) ;
V_122:
F_25 ( & V_2 -> V_120 ) ;
return V_118 ;
}
static int F_26 ( struct V_116 * V_116 , void * V_117 , struct V_127 * V_128 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
strcpy ( V_128 -> V_129 , V_130 ) ;
F_27 ( V_128 -> V_131 , V_2 -> V_132 . V_29 , sizeof( V_128 -> V_131 ) ) ;
F_28 ( V_2 -> V_133 , V_128 -> V_134 , sizeof( V_128 -> V_134 ) ) ;
V_128 -> V_135 =
V_136 |
V_137 |
V_138 ;
return 0 ;
}
static int F_29 ( struct V_116 * V_116 , void * V_117 , struct V_139 * V_140 )
{
if ( V_140 -> V_141 )
return - V_111 ;
strcpy ( V_140 -> V_29 , L_10 ) ;
return 0 ;
}
static int F_30 ( struct V_116 * V_116 , void * V_117 , unsigned int * V_140 )
{
* V_140 = 0 ;
return 0 ;
}
static int F_31 ( struct V_116 * V_116 , void * V_117 , unsigned int V_140 )
{
return V_140 ? - V_111 : 0 ;
}
static int F_32 ( struct V_142 * V_143 )
{
struct V_1 * V_2 =
F_33 ( V_143 -> V_144 , struct V_1 , V_9 ) ;
int V_118 = 0 ;
switch ( V_143 -> V_30 ) {
case V_145 :
if ( V_2 -> V_146 &&
( V_2 -> V_31 -> V_147 != V_27 ||
F_34 ( V_148 ,
V_2 -> V_149 + V_150 / 4 ) ) ) {
V_2 -> V_33 -> V_147 = V_2 -> V_151 ;
V_2 -> V_36 -> V_147 = V_2 -> V_152 ;
break;
}
V_118 = F_3 ( V_2 , V_48 ,
V_153 ,
& V_2 -> V_33 -> V_147 ) ;
if ( V_118 )
break;
V_118 = F_3 ( V_2 , V_48 ,
V_154 ,
& V_2 -> V_36 -> V_147 ) ;
if ( V_118 )
break;
V_2 -> V_151 = V_2 -> V_33 -> V_147 ;
V_2 -> V_152 = V_2 -> V_36 -> V_147 ;
V_2 -> V_149 = V_148 ;
V_2 -> V_146 = true ;
break;
case V_41 :
if ( V_2 -> V_155 && F_34 ( V_148 ,
V_2 -> V_156 + V_150 / 4 ) ) {
V_2 -> V_43 -> V_147 = V_2 -> V_157 ;
break;
}
V_118 = F_3 ( V_2 , V_48 ,
V_158 , & V_2 -> V_43 -> V_147 ) ;
if ( V_118 )
break;
V_2 -> V_157 = V_2 -> V_43 -> V_147 ;
V_2 -> V_156 = V_148 ;
V_2 -> V_155 = true ;
if ( ! F_12 ( V_2 -> type ) )
break;
case V_47 :
if ( V_2 -> V_159 && F_34 ( V_148 ,
V_2 -> V_160 + V_150 / 4 ) ) {
V_2 -> V_50 -> V_147 = V_2 -> V_161 ;
break;
}
V_118 = F_11 ( V_2 , V_48 ,
V_49 ,
& V_2 -> V_50 -> V_147 ) ;
if ( V_118 )
break;
V_2 -> V_161 = V_2 -> V_50 -> V_147 ;
V_2 -> V_160 = V_148 ;
V_2 -> V_159 = true ;
break;
default:
V_118 = - V_111 ;
}
if ( V_118 )
F_35 ( L_11 , V_143 -> V_29 , V_118 ) ;
return V_118 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_118 ;
if ( V_2 -> V_31 -> V_162 ) {
V_118 = F_37 ( V_2 , V_163 ,
V_26 ,
V_2 -> V_31 -> V_147 ) ;
if ( V_118 )
return V_118 ;
if ( V_2 -> V_31 -> V_147 != V_38 )
V_2 -> V_146 = false ;
if ( V_2 -> V_31 -> V_147 == V_164 ||
V_2 -> V_31 -> V_147 == V_165 ||
V_2 -> V_31 -> V_147 == V_166 )
F_32 ( V_2 -> V_31 ) ;
}
if ( V_2 -> V_31 -> V_147 != V_38 )
return 0 ;
if ( V_2 -> V_33 -> V_162 ) {
V_118 = F_37 ( V_2 , V_163 ,
V_32 ,
V_2 -> V_33 -> V_147 ) ;
if ( V_118 )
return V_118 ;
}
if ( V_2 -> V_36 -> V_162 ) {
V_118 = F_37 ( V_2 , V_163 ,
V_35 ,
V_2 -> V_36 -> V_147 ) ;
if ( V_118 )
return V_118 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_118 ;
if ( V_2 -> V_40 -> V_162 ) {
V_118 = F_37 ( V_2 , V_167 ,
V_39 ,
V_2 -> V_40 -> V_147 ? 0 : 0xff ) ;
if ( V_118 )
return V_118 ;
if ( V_2 -> V_40 -> V_147 )
V_2 -> V_155 = false ;
}
if ( V_2 -> V_40 -> V_147 )
return 0 ;
if ( V_2 -> V_43 -> V_162 ) {
V_118 = F_37 ( V_2 , V_167 ,
V_42 ,
V_2 -> V_43 -> V_147 ) ;
if ( V_118 )
return V_118 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_118 ;
int V_168 = V_2 -> V_46 -> V_147 == V_169 ;
if ( V_2 -> V_46 -> V_162 ) {
V_118 = F_37 ( V_2 , V_167 ,
V_45 ,
V_168 ? 0 : 0xff ) ;
if ( V_118 )
return V_118 ;
if ( V_168 )
V_2 -> V_159 = false ;
}
if ( V_168 )
return 0 ;
if ( V_2 -> V_50 -> V_162 ) {
V_118 = F_40 ( V_2 , V_167 ,
V_170 ,
V_2 -> V_50 -> V_147 ) ;
if ( V_118 )
return V_118 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_118 ;
if ( V_2 -> V_40 -> V_162 ) {
V_118 = F_37 ( V_2 , V_167 ,
V_39 ,
V_2 -> V_40 -> V_147 ? 0 : 0xff ) ;
if ( V_118 )
return V_118 ;
if ( V_2 -> V_40 -> V_147 ) {
V_2 -> V_155 = false ;
V_2 -> V_159 = false ;
}
}
if ( V_2 -> V_40 -> V_147 )
return 0 ;
if ( V_2 -> V_43 -> V_162 ) {
V_118 = F_37 ( V_2 , V_167 ,
V_42 ,
V_2 -> V_43 -> V_147 ) ;
if ( V_118 )
return V_118 ;
}
if ( V_2 -> V_50 -> V_162 ) {
V_118 = F_40 ( V_2 , V_167 ,
V_170 ,
V_2 -> V_50 -> V_147 ) ;
if ( V_118 )
return V_118 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_118 ;
V_2 -> V_171 [ 0 ] = 0 ;
if ( V_2 -> V_92 -> V_162 )
V_2 -> V_171 [ 0 ] |= 0x01 ;
if ( V_2 -> V_94 -> V_162 )
V_2 -> V_171 [ 0 ] |= 0x02 ;
if ( V_2 -> V_92 -> V_162 || V_2 -> V_94 -> V_162 ) {
V_118 = F_43 ( V_2 , V_172 ,
V_173 ,
V_2 -> V_171 , 1 ) ;
if ( V_118 < 0 )
return V_118 ;
}
memset ( V_2 -> V_171 , 0 , 4 ) ;
if ( V_2 -> V_88 -> V_162 ) {
V_2 -> V_171 [ 0 ] = V_2 -> V_88 -> V_147 & 0xFF ;
V_2 -> V_171 [ 1 ] = ( V_2 -> V_88 -> V_147 >> 8 ) ;
}
if ( V_2 -> V_90 -> V_162 ) {
V_2 -> V_171 [ 2 ] = V_2 -> V_90 -> V_147 & 0xFF ;
V_2 -> V_171 [ 3 ] = ( V_2 -> V_90 -> V_147 >> 8 ) ;
}
if ( V_2 -> V_88 -> V_162 || V_2 -> V_90 -> V_162 ) {
V_118 = F_43 ( V_2 , V_172 ,
V_174 ,
V_2 -> V_171 , 4 ) ;
if ( V_118 < 0 )
return V_118 ;
}
return 0 ;
}
static int F_44 ( struct V_142 * V_143 )
{
struct V_1 * V_2 =
F_33 ( V_143 -> V_144 , struct V_1 , V_9 ) ;
int V_118 = 0 ;
switch ( V_143 -> V_30 ) {
case V_14 :
V_118 = F_37 ( V_2 , V_167 ,
V_11 , V_143 -> V_147 ) ;
break;
case V_17 :
V_118 = F_37 ( V_2 , V_167 ,
V_15 , V_143 -> V_147 ) ;
break;
case V_23 :
V_118 = F_45 ( V_2 , V_163 ,
V_2 -> V_18 , V_143 -> V_147 ) ;
break;
case V_25 :
V_118 = F_37 ( V_2 , V_167 ,
V_24 , V_143 -> V_147 ) ;
break;
case V_145 :
V_118 = F_36 ( V_2 ) ;
break;
case V_41 :
if ( F_9 ( V_2 -> type ) )
V_118 = F_38 ( V_2 ) ;
else if ( F_12 ( V_2 -> type ) )
V_118 = F_41 ( V_2 ) ;
else
V_118 = - V_111 ;
break;
case V_47 :
if ( F_9 ( V_2 -> type ) )
V_118 = F_39 ( V_2 ) ;
else
V_118 = - V_111 ;
break;
case V_56 :
V_118 = F_37 ( V_2 , V_163 ,
V_54 ,
V_143 -> V_147 ? 0 : 0xff ) ;
break;
case F_46 ( V_59 ) :
if ( V_2 -> V_59 -> V_162 ) {
V_118 = F_37 ( V_2 , V_167 ,
V_57 ,
V_2 -> V_59 -> V_147 ? 0 : 0xff ) ;
}
if ( V_118 == 0 && V_2 -> V_62 -> V_162 ) {
V_118 = F_37 ( V_2 , V_167 ,
V_60 ,
V_2 -> V_62 -> V_147 ) ;
}
break;
case V_175 :
V_118 = F_37 ( V_2 , V_167 ,
V_63 ,
V_143 -> V_147 ? 0 : 0xff ) ;
break;
case V_176 :
V_118 = F_37 ( V_2 , V_167 ,
V_66 ,
V_143 -> V_147 ? 0 : 0xff ) ;
break;
case F_46 ( V_71 ) :
V_118 = F_37 ( V_2 , V_167 ,
V_69 ,
V_143 -> V_147 ) ;
break;
case F_46 ( V_72 ) :
V_118 = F_47 ( V_2 , V_177 ) ;
break;
case F_46 ( V_74 ) :
V_118 = F_47 ( V_2 , V_178 ) ;
break;
case F_46 ( V_78 ) :
V_118 = F_47 ( V_2 ,
V_179 ) ;
break;
case F_46 ( V_82 ) :
V_118 = F_37 ( V_2 , V_163 ,
V_80 ,
V_143 -> V_147 ) ;
break;
case F_46 ( V_85 ) :
V_118 = F_37 ( V_2 , V_163 ,
V_83 ,
V_143 -> V_147 ) ;
break;
case V_89 :
V_118 = F_42 ( V_2 ) ;
break;
default:
V_118 = - V_111 ;
}
if ( V_118 )
F_35 ( L_12 , V_143 -> V_29 , V_118 ) ;
return V_118 ;
}
static int F_48 ( struct V_116 * V_116 , void * V_117 , struct V_180 * V_97 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
switch ( V_97 -> V_141 ) {
case 0 :
V_97 -> V_106 = V_2 -> type <= 646 ? V_113 : V_114 ;
V_97 -> V_76 = V_181 ;
F_27 ( V_97 -> V_182 , L_13 , sizeof( V_97 -> V_182 ) ) ;
break;
case 1 :
V_97 -> V_106 = V_112 ;
F_27 ( V_97 -> V_182 , L_14 , sizeof( V_97 -> V_182 ) ) ;
break;
default:
return - V_111 ;
}
return 0 ;
}
static int F_49 ( struct V_116 * V_116 , void * V_117 , struct V_96 * V_97 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
if ( V_97 -> type != V_110 )
return - V_111 ;
F_15 ( L_15 ,
V_2 -> V_98 , V_2 -> V_99 ) ;
F_14 ( V_97 , V_2 -> V_98 , V_2 -> V_99 , V_2 -> V_100 ) ;
return 0 ;
}
static int F_50 ( struct V_116 * V_116 , void * V_117 , struct V_96 * V_97 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
return F_16 ( V_2 , V_97 ) ;
}
static int F_51 ( struct V_116 * V_116 , void * V_117 ,
struct V_183 * V_184 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
int V_118 ;
if ( F_22 ( & V_2 -> V_120 ) )
return - V_121 ;
V_118 = F_23 ( V_2 , V_116 ) ;
if ( V_118 == 0 )
V_118 = F_52 ( & V_2 -> V_123 , V_184 ) ;
F_25 ( & V_2 -> V_120 ) ;
return V_118 ;
}
static int F_53 ( struct V_116 * V_116 , void * V_117 , struct V_185 * V_186 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
int V_118 ;
if ( F_22 ( & V_2 -> V_120 ) )
return - V_121 ;
V_118 = F_23 ( V_2 , V_116 ) ;
if ( V_118 == 0 )
V_118 = F_54 ( & V_2 -> V_123 , V_186 ) ;
F_25 ( & V_2 -> V_120 ) ;
return V_118 ;
}
static int F_55 ( struct V_116 * V_116 , void * V_117 , struct V_185 * V_186 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
int V_118 ;
if ( F_22 ( & V_2 -> V_120 ) )
return - V_121 ;
V_118 = F_23 ( V_2 , V_116 ) ;
if ( V_118 == 0 )
V_118 = F_56 ( & V_2 -> V_123 , V_186 ) ;
F_25 ( & V_2 -> V_120 ) ;
return V_118 ;
}
static int F_57 ( struct V_116 * V_116 , void * V_117 , struct V_185 * V_186 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
int V_118 ;
if ( F_22 ( & V_2 -> V_120 ) )
return - V_121 ;
V_118 = F_23 ( V_2 , V_116 ) ;
if ( V_118 == 0 )
V_118 = F_58 ( & V_2 -> V_123 , V_186 ,
V_116 -> V_187 & V_188 ) ;
F_25 ( & V_2 -> V_120 ) ;
return V_118 ;
}
static int F_59 ( struct V_116 * V_116 , void * V_117 , enum V_189 V_140 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
int V_118 ;
if ( F_22 ( & V_2 -> V_120 ) )
return - V_121 ;
V_118 = F_23 ( V_2 , V_116 ) ;
if ( V_118 == 0 )
V_118 = F_60 ( & V_2 -> V_123 , V_140 ) ;
F_25 ( & V_2 -> V_120 ) ;
return V_118 ;
}
static int F_61 ( struct V_116 * V_116 , void * V_117 , enum V_189 V_140 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
int V_118 ;
if ( F_22 ( & V_2 -> V_120 ) )
return - V_121 ;
V_118 = F_23 ( V_2 , V_116 ) ;
if ( V_118 == 0 )
V_118 = F_62 ( & V_2 -> V_123 , V_140 ) ;
F_25 ( & V_2 -> V_120 ) ;
return V_118 ;
}
static int F_63 ( struct V_116 * V_116 , void * V_117 ,
struct V_190 * V_191 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
unsigned int V_140 = 0 , V_141 = V_191 -> V_141 ;
if ( V_191 -> V_192 == V_112 ||
( V_191 -> V_192 == V_113 &&
F_18 ( V_2 -> type ) ) ||
( V_191 -> V_192 == V_114 &&
F_17 ( V_2 -> type ) ) ) {
for ( V_140 = 0 ; V_140 < V_193 ; V_140 ++ ) {
if ( ! ( V_2 -> V_194 & ( 1UL << V_140 ) ) )
continue;
if ( ! V_141 -- ) {
V_191 -> type = V_195 ;
V_191 -> V_196 . V_98 = V_115 [ V_140 ] [ 0 ] ;
V_191 -> V_196 . V_99 = V_115 [ V_140 ] [ 1 ] ;
return 0 ;
}
}
}
return - V_111 ;
}
static int F_64 ( struct V_116 * V_116 , void * V_117 ,
struct V_197 * V_198 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
int V_109 = - 1 ;
unsigned int V_140 ;
for ( V_140 = 0 ; V_140 < V_193 ; V_140 ++ ) {
if ( V_115 [ V_140 ] [ 0 ] == V_198 -> V_98 &&
V_115 [ V_140 ] [ 1 ] == V_198 -> V_99 ) {
V_109 = V_140 ;
break;
}
}
if ( V_109 < 0 || V_198 -> V_192 != V_112 )
return - V_111 ;
V_140 = F_65 ( V_2 , V_198 -> V_141 , V_109 ) ;
if ( ! V_140 )
return - V_111 ;
V_198 -> type = V_199 ;
V_198 -> V_196 . V_200 = 1 ;
V_198 -> V_196 . V_201 = V_140 ;
return 0 ;
}
static int F_66 ( struct V_116 * V_116 , void * V_117 ,
struct V_202 * V_203 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
if ( V_203 -> type != V_110 )
return - V_111 ;
memset ( V_203 , 0 , sizeof( * V_203 ) ) ;
V_203 -> type = V_110 ;
V_203 -> V_203 . V_204 . V_205 = V_206 ;
V_203 -> V_203 . V_204 . V_207 |= V_208 ;
V_203 -> V_203 . V_204 . V_209 . V_201 = V_2 -> V_126 ;
V_203 -> V_203 . V_204 . V_209 . V_200 = 1 ;
return 0 ;
}
static int F_67 ( struct V_116 * V_116 , void * V_117 ,
struct V_202 * V_203 )
{
struct V_1 * V_2 = F_21 ( V_116 ) ;
int V_119 = 0 ;
int V_118 , V_210 ;
if ( V_203 -> type != V_110 ||
V_203 -> V_203 . V_204 . V_209 . V_200 == 0 )
return - V_111 ;
V_210 = V_203 -> V_203 . V_204 . V_209 . V_201 /
V_203 -> V_203 . V_204 . V_209 . V_200 ;
if ( F_22 ( & V_2 -> V_120 ) )
return - V_121 ;
V_118 = F_23 ( V_2 , V_116 ) ;
if ( V_118 )
goto V_122;
if ( V_2 -> V_123 . V_124 ) {
V_118 = - V_125 ;
goto V_122;
}
V_118 = F_24 ( V_2 , V_2 -> V_98 , V_2 -> V_99 , V_2 -> V_100 ,
V_210 , & V_119 , 0 ) ;
F_66 ( V_116 , V_117 , V_203 ) ;
V_122:
F_25 ( & V_2 -> V_120 ) ;
return V_118 ;
}
