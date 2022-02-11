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
if ( ! ( V_2 -> V_80 & V_81 ) )
return V_4 -> error ;
V_2 -> V_82 = F_4 ( V_4 , & V_13 ,
V_83 , - 4480 , 4480 , 64 , 0 ) ;
if ( ! V_2 -> V_82 )
return V_4 -> error ;
V_2 -> V_84 = F_4 ( V_4 , & V_13 ,
V_85 , - 1920 , 1920 , 64 , 0 ) ;
V_2 -> V_86 = F_4 ( V_4 , & V_13 ,
V_87 , 0 , 0 , 0 , 0 ) ;
V_2 -> V_88 = F_4 ( V_4 , & V_13 ,
V_89 , 0 , 0 , 0 , 0 ) ;
F_13 ( 4 , & V_2 -> V_82 ) ;
return V_4 -> error ;
}
static void F_14 ( const struct V_1 * V_2 , struct V_90 * V_91 )
{
memset ( & V_91 -> V_92 . V_93 , 0 , sizeof( struct V_94 ) ) ;
V_91 -> V_92 . V_93 . V_95 = V_2 -> V_96 . V_97 ;
V_91 -> V_92 . V_93 . V_98 = V_2 -> V_96 . V_99 ;
V_91 -> V_92 . V_93 . V_100 = V_101 ;
if ( V_2 -> V_102 == V_103 ) {
V_91 -> V_92 . V_93 . V_104 = V_103 ;
V_91 -> V_92 . V_93 . V_105 = ( V_91 -> V_92 . V_93 . V_95 * 3 ) / 2 ;
V_91 -> V_92 . V_93 . V_106 = V_91 -> V_92 . V_93 . V_98 * V_91 -> V_92 . V_93 . V_105 ;
} else {
V_91 -> V_92 . V_93 . V_105 = V_2 -> V_107 / 4 ;
V_91 -> V_92 . V_93 . V_106 = V_2 -> V_108 + sizeof( struct V_109 ) ;
if ( F_15 ( V_2 -> type ) )
V_91 -> V_92 . V_93 . V_104 = V_110 ;
else
V_91 -> V_92 . V_93 . V_104 = V_111 ;
}
F_16 ( L_1
L_2 ,
V_91 -> V_92 . V_93 . V_95 ,
V_91 -> V_92 . V_93 . V_98 ,
V_91 -> V_92 . V_93 . V_105 ,
V_91 -> V_92 . V_93 . V_106 ,
( V_91 -> V_92 . V_93 . V_104 ) & 255 ,
( V_91 -> V_92 . V_93 . V_104 >> 8 ) & 255 ,
( V_91 -> V_92 . V_93 . V_104 >> 16 ) & 255 ,
( V_91 -> V_92 . V_93 . V_104 >> 24 ) & 255 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
if ( V_91 -> type != V_112 ) {
F_16 ( L_3 ) ;
return - V_113 ;
}
switch ( V_91 -> V_92 . V_93 . V_104 ) {
case V_103 :
break;
case V_110 :
if ( F_18 ( V_2 -> type ) ) {
F_16 ( L_4 ) ;
return - V_113 ;
}
break;
case V_111 :
if ( F_15 ( V_2 -> type ) ) {
F_16 ( L_5 ) ;
return - V_113 ;
}
break;
default:
F_16 ( L_6 ) ;
return - V_113 ;
}
if ( V_91 -> V_92 . V_93 . V_95 > V_2 -> V_114 . V_97 )
V_91 -> V_92 . V_93 . V_95 = V_2 -> V_114 . V_97 ;
else if ( V_91 -> V_92 . V_93 . V_95 < V_2 -> V_115 . V_97 )
V_91 -> V_92 . V_93 . V_95 = V_2 -> V_115 . V_97 ;
if ( V_91 -> V_92 . V_93 . V_98 > V_2 -> V_114 . V_99 )
V_91 -> V_92 . V_93 . V_98 = V_2 -> V_114 . V_99 ;
else if ( V_91 -> V_92 . V_93 . V_98 < V_2 -> V_115 . V_99 )
V_91 -> V_92 . V_93 . V_98 = V_2 -> V_115 . V_99 ;
return 0 ;
}
static int F_19 ( struct V_116 * V_116 , void * V_117 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
int V_118 , V_119 , V_120 , V_121 , V_104 ;
if ( ! V_2 -> V_122 )
return - V_123 ;
if ( V_2 -> V_124 != NULL &&
V_2 -> V_124 != V_116 )
return - V_125 ;
V_2 -> V_124 = V_116 ;
V_118 = F_17 ( V_2 , V_91 ) ;
if ( V_118 < 0 )
return V_118 ;
V_104 = V_91 -> V_92 . V_93 . V_104 ;
V_121 = V_2 -> V_126 ;
V_120 = 0 ;
V_119 = V_2 -> V_127 ;
if ( V_91 -> V_92 . V_93 . V_128 ) {
V_121 = ( V_91 -> V_92 . V_93 . V_128 & V_129 ) >> V_130 ;
V_120 = ! ! ( V_91 -> V_92 . V_93 . V_128 & V_131 ) ;
V_119 = ( V_91 -> V_92 . V_93 . V_128 & V_132 ) >> V_133 ;
if ( V_119 == 0 )
V_119 = V_2 -> V_127 ;
}
if ( V_104 != V_103 &&
V_104 != V_110 &&
V_104 != V_111 )
return - V_113 ;
if ( F_21 ( & V_2 -> V_134 ) )
return - V_125 ;
F_16 ( L_7
L_8 ,
V_91 -> V_92 . V_93 . V_95 , V_91 -> V_92 . V_93 . V_98 , V_119 ,
V_121 , V_120 ,
( V_104 ) & 255 ,
( V_104 >> 8 ) & 255 ,
( V_104 >> 16 ) & 255 ,
( V_104 >> 24 ) & 255 ) ;
V_118 = F_22 ( V_2 ,
V_91 -> V_92 . V_93 . V_95 ,
V_91 -> V_92 . V_93 . V_98 ,
V_119 ,
V_121 ,
V_120 ) ;
F_16 ( L_9 , V_118 ) ;
if ( V_118 )
return V_118 ;
V_2 -> V_102 = V_104 ;
F_14 ( V_2 , V_91 ) ;
return 0 ;
}
static int F_23 ( struct V_116 * V_116 , void * V_117 , struct V_135 * V_136 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
if ( ! V_2 -> V_122 )
return - V_123 ;
strcpy ( V_136 -> V_137 , V_138 ) ;
F_24 ( V_136 -> V_139 , V_2 -> V_140 . V_29 , sizeof( V_136 -> V_139 ) ) ;
F_25 ( V_2 -> V_122 , V_136 -> V_141 , sizeof( V_136 -> V_141 ) ) ;
V_136 -> V_142 =
V_143 |
V_144 |
V_145 ;
return 0 ;
}
static int F_26 ( struct V_116 * V_116 , void * V_117 , struct V_146 * V_147 )
{
if ( V_147 -> V_148 )
return - V_113 ;
strcpy ( V_147 -> V_29 , L_10 ) ;
return 0 ;
}
static int F_27 ( struct V_116 * V_116 , void * V_117 , unsigned int * V_147 )
{
* V_147 = 0 ;
return 0 ;
}
static int F_28 ( struct V_116 * V_116 , void * V_117 , unsigned int V_147 )
{
return V_147 ? - V_113 : 0 ;
}
static int F_29 ( struct V_149 * V_150 )
{
struct V_1 * V_2 =
F_30 ( V_150 -> V_151 , struct V_1 , V_9 ) ;
int V_118 = 0 ;
F_31 ( & V_2 -> V_152 ) ;
F_32 ( & V_2 -> V_153 ) ;
if ( ! V_2 -> V_122 ) {
V_118 = - V_123 ;
goto V_154;
}
switch ( V_150 -> V_30 ) {
case V_155 :
if ( V_2 -> V_156 &&
( V_2 -> V_31 -> V_157 != V_27 ||
F_33 ( V_158 ,
V_2 -> V_159 + V_160 / 4 ) ) ) {
V_2 -> V_33 -> V_157 = V_2 -> V_161 ;
V_2 -> V_36 -> V_157 = V_2 -> V_162 ;
break;
}
V_118 = F_3 ( V_2 , V_48 ,
V_163 ,
& V_2 -> V_33 -> V_157 ) ;
if ( V_118 )
break;
V_118 = F_3 ( V_2 , V_48 ,
V_164 ,
& V_2 -> V_36 -> V_157 ) ;
if ( V_118 )
break;
V_2 -> V_161 = V_2 -> V_33 -> V_157 ;
V_2 -> V_162 = V_2 -> V_36 -> V_157 ;
V_2 -> V_159 = V_158 ;
V_2 -> V_156 = true ;
break;
case V_41 :
if ( V_2 -> V_165 && F_33 ( V_158 ,
V_2 -> V_166 + V_160 / 4 ) ) {
V_2 -> V_43 -> V_157 = V_2 -> V_167 ;
break;
}
V_118 = F_3 ( V_2 , V_48 ,
V_168 , & V_2 -> V_43 -> V_157 ) ;
if ( V_118 )
break;
V_2 -> V_167 = V_2 -> V_43 -> V_157 ;
V_2 -> V_166 = V_158 ;
V_2 -> V_165 = true ;
if ( ! F_12 ( V_2 -> type ) )
break;
case V_47 :
if ( V_2 -> V_169 && F_33 ( V_158 ,
V_2 -> V_170 + V_160 / 4 ) ) {
V_2 -> V_50 -> V_157 = V_2 -> V_171 ;
break;
}
V_118 = F_11 ( V_2 , V_48 ,
V_49 ,
& V_2 -> V_50 -> V_157 ) ;
if ( V_118 )
break;
V_2 -> V_171 = V_2 -> V_50 -> V_157 ;
V_2 -> V_170 = V_158 ;
V_2 -> V_169 = true ;
break;
default:
V_118 = - V_113 ;
}
if ( V_118 )
F_34 ( L_11 , V_150 -> V_29 , V_118 ) ;
V_154:
F_31 ( & V_2 -> V_153 ) ;
F_32 ( & V_2 -> V_152 ) ;
return V_118 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_118 ;
if ( V_2 -> V_31 -> V_172 ) {
V_118 = F_36 ( V_2 , V_173 ,
V_26 ,
V_2 -> V_31 -> V_157 ) ;
if ( V_118 )
return V_118 ;
if ( V_2 -> V_31 -> V_157 != V_38 )
V_2 -> V_156 = false ;
}
if ( V_2 -> V_31 -> V_157 != V_38 )
return 0 ;
if ( V_2 -> V_33 -> V_172 ) {
V_118 = F_36 ( V_2 , V_173 ,
V_32 ,
V_2 -> V_33 -> V_157 ) ;
if ( V_118 )
return V_118 ;
}
if ( V_2 -> V_36 -> V_172 ) {
V_118 = F_36 ( V_2 , V_173 ,
V_35 ,
V_2 -> V_36 -> V_157 ) ;
if ( V_118 )
return V_118 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_118 ;
if ( V_2 -> V_40 -> V_172 ) {
V_118 = F_36 ( V_2 , V_174 ,
V_39 ,
V_2 -> V_40 -> V_157 ? 0 : 0xff ) ;
if ( V_118 )
return V_118 ;
if ( V_2 -> V_40 -> V_157 )
V_2 -> V_165 = false ;
}
if ( V_2 -> V_40 -> V_157 )
return 0 ;
if ( V_2 -> V_43 -> V_172 ) {
V_118 = F_36 ( V_2 , V_174 ,
V_42 ,
V_2 -> V_43 -> V_157 ) ;
if ( V_118 )
return V_118 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_118 ;
int V_175 = V_2 -> V_46 -> V_157 == V_176 ;
if ( V_2 -> V_46 -> V_172 ) {
V_118 = F_36 ( V_2 , V_174 ,
V_45 ,
V_175 ? 0 : 0xff ) ;
if ( V_118 )
return V_118 ;
if ( V_175 )
V_2 -> V_169 = false ;
}
if ( V_175 )
return 0 ;
if ( V_2 -> V_50 -> V_172 ) {
V_118 = F_39 ( V_2 , V_174 ,
V_177 ,
V_2 -> V_50 -> V_157 ) ;
if ( V_118 )
return V_118 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_118 ;
if ( V_2 -> V_40 -> V_172 ) {
V_118 = F_36 ( V_2 , V_174 ,
V_39 ,
V_2 -> V_40 -> V_157 ? 0 : 0xff ) ;
if ( V_118 )
return V_118 ;
if ( V_2 -> V_40 -> V_157 ) {
V_2 -> V_165 = false ;
V_2 -> V_169 = false ;
}
}
if ( V_2 -> V_40 -> V_157 )
return 0 ;
if ( V_2 -> V_43 -> V_172 ) {
V_118 = F_36 ( V_2 , V_174 ,
V_42 ,
V_2 -> V_43 -> V_157 ) ;
if ( V_118 )
return V_118 ;
}
if ( V_2 -> V_50 -> V_172 ) {
V_118 = F_39 ( V_2 , V_174 ,
V_177 ,
V_2 -> V_50 -> V_157 ) ;
if ( V_118 )
return V_118 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_118 ;
T_1 V_178 [ 4 ] ;
V_178 [ 0 ] = 0 ;
if ( V_2 -> V_86 -> V_172 )
V_178 [ 0 ] |= 0x01 ;
if ( V_2 -> V_88 -> V_172 )
V_178 [ 0 ] |= 0x02 ;
if ( V_2 -> V_86 -> V_172 || V_2 -> V_88 -> V_172 ) {
V_118 = F_42 ( V_2 , V_179 ,
V_180 , V_178 , 1 ) ;
if ( V_118 < 0 )
return V_118 ;
}
memset ( V_178 , 0 , sizeof( V_178 ) ) ;
if ( V_2 -> V_82 -> V_172 ) {
V_178 [ 0 ] = V_2 -> V_82 -> V_157 & 0xFF ;
V_178 [ 1 ] = ( V_2 -> V_82 -> V_157 >> 8 ) ;
}
if ( V_2 -> V_84 -> V_172 ) {
V_178 [ 2 ] = V_2 -> V_84 -> V_157 & 0xFF ;
V_178 [ 3 ] = ( V_2 -> V_84 -> V_157 >> 8 ) ;
}
if ( V_2 -> V_82 -> V_172 || V_2 -> V_84 -> V_172 ) {
V_118 = F_42 ( V_2 , V_179 ,
V_181 ,
V_178 , sizeof( V_178 ) ) ;
if ( V_118 < 0 )
return V_118 ;
}
return 0 ;
}
static int F_43 ( struct V_149 * V_150 )
{
struct V_1 * V_2 =
F_30 ( V_150 -> V_151 , struct V_1 , V_9 ) ;
int V_118 = 0 ;
F_31 ( & V_2 -> V_152 ) ;
F_32 ( & V_2 -> V_153 ) ;
if ( ! V_2 -> V_122 ) {
V_118 = - V_123 ;
goto V_154;
}
switch ( V_150 -> V_30 ) {
case V_14 :
V_118 = F_36 ( V_2 , V_174 ,
V_11 , V_150 -> V_157 ) ;
break;
case V_17 :
V_118 = F_36 ( V_2 , V_174 ,
V_15 , V_150 -> V_157 ) ;
break;
case V_23 :
V_118 = F_44 ( V_2 , V_173 ,
V_2 -> V_18 , V_150 -> V_157 ) ;
break;
case V_25 :
V_118 = F_36 ( V_2 , V_174 ,
V_24 , V_150 -> V_157 ) ;
break;
case V_155 :
V_118 = F_35 ( V_2 ) ;
break;
case V_41 :
if ( F_9 ( V_2 -> type ) )
V_118 = F_37 ( V_2 ) ;
else if ( F_12 ( V_2 -> type ) )
V_118 = F_40 ( V_2 ) ;
else
V_118 = - V_113 ;
break;
case V_47 :
if ( F_9 ( V_2 -> type ) )
V_118 = F_38 ( V_2 ) ;
else
V_118 = - V_113 ;
break;
case V_56 :
V_118 = F_36 ( V_2 , V_173 ,
V_54 ,
V_150 -> V_157 ? 0 : 0xff ) ;
break;
case F_45 ( V_59 ) :
if ( V_2 -> V_59 -> V_172 ) {
V_118 = F_36 ( V_2 , V_174 ,
V_57 ,
V_2 -> V_59 -> V_157 ? 0 : 0xff ) ;
}
if ( V_118 == 0 && V_2 -> V_62 -> V_172 ) {
V_118 = F_36 ( V_2 , V_174 ,
V_60 ,
V_2 -> V_62 -> V_157 ) ;
}
break;
case V_182 :
V_118 = F_36 ( V_2 , V_174 ,
V_63 ,
V_150 -> V_157 ? 0 : 0xff ) ;
break;
case V_183 :
V_118 = F_36 ( V_2 , V_174 ,
V_66 ,
V_150 -> V_157 ? 0 : 0xff ) ;
break;
case F_45 ( V_71 ) :
V_118 = F_36 ( V_2 , V_174 ,
V_69 ,
V_150 -> V_157 ) ;
break;
case F_45 ( V_72 ) :
V_118 = F_46 ( V_2 , V_184 ) ;
break;
case F_45 ( V_74 ) :
V_118 = F_46 ( V_2 , V_185 ) ;
break;
case F_45 ( V_78 ) :
V_118 = F_46 ( V_2 ,
V_186 ) ;
break;
case V_83 :
V_118 = F_41 ( V_2 ) ;
break;
default:
V_118 = - V_113 ;
}
if ( V_118 )
F_34 ( L_12 , V_150 -> V_29 , V_118 ) ;
V_154:
F_31 ( & V_2 -> V_153 ) ;
F_32 ( & V_2 -> V_152 ) ;
return V_118 ;
}
static int F_47 ( struct V_116 * V_116 , void * V_117 , struct V_187 * V_91 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
switch ( V_91 -> V_148 ) {
case 0 :
V_91 -> V_104 = V_2 -> type <= 646 ? V_110 : V_111 ;
V_91 -> V_76 = V_188 ;
F_24 ( V_91 -> V_189 , L_13 , sizeof( V_91 -> V_189 ) ) ;
break;
case 1 :
V_91 -> V_104 = V_103 ;
F_24 ( V_91 -> V_189 , L_14 , sizeof( V_91 -> V_189 ) ) ;
break;
default:
return - V_113 ;
}
return 0 ;
}
static int F_48 ( struct V_116 * V_116 , void * V_117 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
F_16 ( L_15 ,
V_2 -> V_190 . V_97 , V_2 -> V_190 . V_99 ) ;
F_14 ( V_2 , V_91 ) ;
return 0 ;
}
static int F_49 ( struct V_116 * V_116 , void * V_117 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
return F_17 ( V_2 , V_91 ) ;
}
static int F_50 ( struct V_116 * V_116 , void * V_117 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
if ( V_2 -> V_124 != NULL &&
V_2 -> V_124 != V_116 )
return - V_125 ;
V_2 -> V_124 = V_116 ;
return F_51 ( & V_2 -> V_134 , V_192 ) ;
}
static int F_52 ( struct V_116 * V_116 , void * V_117 , struct V_193 * V_178 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
return F_53 ( & V_2 -> V_134 , V_178 ) ;
}
static int F_54 ( struct V_116 * V_116 , void * V_117 , struct V_193 * V_178 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
if ( ! V_2 -> V_122 )
return - V_123 ;
if ( V_2 -> V_124 != V_116 )
return - V_125 ;
return F_55 ( & V_2 -> V_134 , V_178 ) ;
}
static int F_56 ( struct V_116 * V_116 , void * V_117 , struct V_193 * V_178 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
if ( ! V_2 -> V_122 )
return - V_123 ;
if ( V_2 -> V_124 != V_116 )
return - V_125 ;
return F_57 ( & V_2 -> V_134 , V_178 , V_116 -> V_194 & V_195 ) ;
}
static int F_58 ( struct V_116 * V_116 , void * V_117 , enum V_196 V_147 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
if ( ! V_2 -> V_122 )
return - V_123 ;
if ( V_2 -> V_124 != V_116 )
return - V_125 ;
return F_59 ( & V_2 -> V_134 , V_147 ) ;
}
static int F_60 ( struct V_116 * V_116 , void * V_117 , enum V_196 V_147 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
if ( ! V_2 -> V_122 )
return - V_123 ;
if ( V_2 -> V_124 != V_116 )
return - V_125 ;
return F_61 ( & V_2 -> V_134 , V_147 ) ;
}
static int F_62 ( struct V_116 * V_116 , void * V_117 ,
struct V_197 * V_198 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
unsigned int V_147 = 0 , V_148 = V_198 -> V_148 ;
if ( V_198 -> V_199 == V_103 ) {
for ( V_147 = 0 ; V_147 < V_200 ; V_147 ++ ) {
if ( V_2 -> V_201 & ( 1UL << V_147 ) ) {
if ( ! V_148 -- ) {
V_198 -> type = V_202 ;
V_198 -> V_203 . V_95 = V_204 [ V_147 ] . V_97 ;
V_198 -> V_203 . V_98 = V_204 [ V_147 ] . V_99 ;
return 0 ;
}
}
}
} else if ( V_198 -> V_148 == 0 &&
( ( V_198 -> V_199 == V_110 && F_15 ( V_2 -> type ) ) ||
( V_198 -> V_199 == V_111 && F_18 ( V_2 -> type ) ) ) ) {
V_198 -> type = V_202 ;
V_198 -> V_203 . V_95 = V_2 -> V_205 . V_97 ;
V_198 -> V_203 . V_98 = V_2 -> V_205 . V_99 ;
return 0 ;
}
return - V_113 ;
}
static int F_63 ( struct V_116 * V_116 , void * V_117 ,
struct V_206 * V_207 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
int V_208 = - 1 ;
unsigned int V_147 ;
for ( V_147 = 0 ; V_147 < V_200 ; V_147 ++ ) {
if ( V_204 [ V_147 ] . V_97 == V_207 -> V_95 &&
V_204 [ V_147 ] . V_99 == V_207 -> V_98 ) {
V_208 = V_147 ;
break;
}
}
if ( V_208 < 0 || V_207 -> V_199 != V_103 )
return - V_113 ;
V_147 = F_64 ( V_2 , V_207 -> V_148 , V_208 ) ;
if ( ! V_147 )
return - V_113 ;
V_207 -> type = V_209 ;
V_207 -> V_203 . V_210 = 1 ;
V_207 -> V_203 . V_211 = V_147 ;
return 0 ;
}
static int F_65 ( struct V_116 * V_116 , void * V_128 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
F_66 ( & V_2 -> V_9 , V_138 ) ;
return 0 ;
}
static long F_67 ( struct V_116 * V_116 , void * V_117 , bool V_212 ,
int V_213 , void * V_214 )
{
struct V_1 * V_2 = F_20 ( V_116 ) ;
return F_68 ( V_2 , V_213 , V_214 ) ;
}
