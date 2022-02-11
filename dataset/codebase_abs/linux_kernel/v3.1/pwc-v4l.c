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
F_8 ( 3 , & V_2 -> V_31 , V_38 ,
V_2 -> V_31 -> V_39 . V_40 == V_27 ) ;
V_7 = F_3 ( V_2 , V_10 , V_41 , & V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0 ;
V_2 -> V_42 = F_4 ( V_4 , & V_13 ,
V_43 , 0 , 1 , 1 , V_8 == 0 ) ;
if ( ! V_2 -> V_42 )
return V_4 -> error ;
V_7 = F_3 ( V_2 , V_10 , V_44 , & V_8 ) ;
if ( V_7 || V_8 > 63 )
V_8 = 31 ;
V_2 -> V_45 = F_4 ( V_4 , & V_13 ,
V_46 , 0 , 63 , 1 , V_8 ) ;
if ( F_9 ( V_2 -> type ) ) {
V_7 = F_3 ( V_2 , V_10 , V_47 ,
& V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0 ;
V_2 -> V_48 = F_10 ( V_4 ,
& V_13 ,
V_49 ,
1 , 0 , V_8 != 0 ) ;
if ( ! V_2 -> V_48 )
return V_4 -> error ;
V_7 = F_11 ( V_2 , V_50 ,
V_51 , & V_8 ) ;
if ( V_7 || V_8 > 655 )
V_8 = 655 ;
V_2 -> V_52 = F_4 ( V_4 , & V_13 ,
V_53 , 0 , 655 , 1 , V_8 ) ;
F_8 ( 2 , & V_2 -> V_42 , 0 , true ) ;
F_8 ( 2 , & V_2 -> V_48 ,
V_54 , true ) ;
} else if ( F_12 ( V_2 -> type ) ) {
V_7 = F_11 ( V_2 , V_50 ,
V_51 , & V_8 ) ;
if ( V_7 || V_8 > 255 )
V_8 = 255 ;
V_2 -> V_52 = F_4 ( V_4 , & V_13 ,
V_53 , 0 , 255 , 1 , V_8 ) ;
V_2 -> V_55 [ 0 ] = V_2 -> V_42 ;
V_2 -> V_55 [ 1 ] = V_2 -> V_45 ;
V_2 -> V_55 [ 2 ] = V_2 -> V_52 ;
F_8 ( 3 , V_2 -> V_55 ,
0 , true ) ;
}
V_7 = F_3 ( V_2 , V_21 , V_56 ,
& V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0xff ;
V_2 -> V_57 = F_10 ( V_4 , & V_13 ,
V_58 , 1 , 0 , V_8 == 0 ) ;
V_7 = F_3 ( V_2 , V_10 , V_59 , & V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0 ;
V_6 = V_60 ;
V_6 . V_8 = V_8 == 0 ;
V_2 -> V_61 = F_7 ( V_4 , & V_6 , NULL ) ;
if ( ! V_2 -> V_61 )
return V_4 -> error ;
V_7 = F_3 ( V_2 , V_10 , V_62 , & V_8 ) ;
if ( V_7 || V_8 > 63 )
V_8 = 31 ;
V_6 = V_63 ;
V_6 . V_8 = V_8 ;
V_2 -> V_64 = F_7 ( V_4 , & V_6 , NULL ) ;
F_8 ( 2 , & V_2 -> V_61 , 0 , false ) ;
V_7 = F_3 ( V_2 , V_10 ,
V_65 , & V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0 ;
V_6 = V_66 ;
V_6 . V_29 = F_6 ( V_6 . V_30 ) ;
V_6 . V_8 = V_8 == 0 ;
V_2 -> V_67 = F_7 ( V_4 , & V_6 , NULL ) ;
V_7 = F_3 ( V_2 , V_10 ,
V_68 , & V_8 ) ;
if ( V_7 || ( V_8 != 0 && V_8 != 0xff ) )
V_8 = 0 ;
V_6 = V_69 ;
V_6 . V_29 = F_6 ( V_6 . V_30 ) ;
V_6 . V_8 = V_8 == 0 ;
V_2 -> V_70 = F_7 ( V_4 , & V_6 , NULL ) ;
V_7 = F_3 ( V_2 , V_10 ,
V_71 , & V_8 ) ;
if ( V_7 || V_8 > 3 )
V_8 = 2 ;
V_6 = V_72 ;
V_6 . V_8 = V_8 ;
V_2 -> V_73 = F_7 ( V_4 , & V_6 , NULL ) ;
V_2 -> V_74 = F_7 ( V_4 , & V_75 , NULL ) ;
V_2 -> V_76 = F_7 ( V_4 , & V_77 ,
NULL ) ;
if ( V_2 -> V_76 )
V_2 -> V_76 -> V_78 = V_79 ;
V_2 -> V_80 = F_7 ( V_4 ,
& V_81 ,
NULL ) ;
if ( V_2 -> V_80 )
V_2 -> V_80 -> V_78 = V_79 ;
if ( ! ( V_2 -> V_82 & V_83 ) )
return V_4 -> error ;
V_2 -> V_84 = F_4 ( V_4 , & V_13 ,
V_85 , - 4480 , 4480 , 64 , 0 ) ;
if ( ! V_2 -> V_84 )
return V_4 -> error ;
V_2 -> V_86 = F_4 ( V_4 , & V_13 ,
V_87 , - 1920 , 1920 , 64 , 0 ) ;
V_2 -> V_88 = F_4 ( V_4 , & V_13 ,
V_89 , 0 , 0 , 0 , 0 ) ;
V_2 -> V_90 = F_4 ( V_4 , & V_13 ,
V_91 , 0 , 0 , 0 , 0 ) ;
F_13 ( 4 , & V_2 -> V_84 ) ;
return V_4 -> error ;
}
static void F_14 ( const struct V_1 * V_2 , struct V_92 * V_93 )
{
memset ( & V_93 -> V_94 . V_95 , 0 , sizeof( struct V_96 ) ) ;
V_93 -> V_94 . V_95 . V_97 = V_2 -> V_98 . V_99 ;
V_93 -> V_94 . V_95 . V_100 = V_2 -> V_98 . V_101 ;
V_93 -> V_94 . V_95 . V_102 = V_103 ;
if ( V_2 -> V_104 == V_105 ) {
V_93 -> V_94 . V_95 . V_106 = V_105 ;
V_93 -> V_94 . V_95 . V_107 = ( V_93 -> V_94 . V_95 . V_97 * 3 ) / 2 ;
V_93 -> V_94 . V_95 . V_108 = V_93 -> V_94 . V_95 . V_100 * V_93 -> V_94 . V_95 . V_107 ;
} else {
V_93 -> V_94 . V_95 . V_107 = V_2 -> V_109 / 4 ;
V_93 -> V_94 . V_95 . V_108 = V_2 -> V_110 + sizeof( struct V_111 ) ;
if ( F_15 ( V_2 -> type ) )
V_93 -> V_94 . V_95 . V_106 = V_112 ;
else
V_93 -> V_94 . V_95 . V_106 = V_113 ;
}
F_16 ( L_1
L_2 ,
V_93 -> V_94 . V_95 . V_97 ,
V_93 -> V_94 . V_95 . V_100 ,
V_93 -> V_94 . V_95 . V_107 ,
V_93 -> V_94 . V_95 . V_108 ,
( V_93 -> V_94 . V_95 . V_106 ) & 255 ,
( V_93 -> V_94 . V_95 . V_106 >> 8 ) & 255 ,
( V_93 -> V_94 . V_95 . V_106 >> 16 ) & 255 ,
( V_93 -> V_94 . V_95 . V_106 >> 24 ) & 255 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
if ( V_93 -> type != V_114 ) {
F_16 ( L_3 ) ;
return - V_115 ;
}
switch ( V_93 -> V_94 . V_95 . V_106 ) {
case V_105 :
break;
case V_112 :
if ( F_18 ( V_2 -> type ) ) {
F_16 ( L_4 ) ;
return - V_115 ;
}
break;
case V_113 :
if ( F_15 ( V_2 -> type ) ) {
F_16 ( L_5 ) ;
return - V_115 ;
}
break;
default:
F_16 ( L_6 ) ;
return - V_115 ;
}
if ( V_93 -> V_94 . V_95 . V_97 > V_2 -> V_116 . V_99 )
V_93 -> V_94 . V_95 . V_97 = V_2 -> V_116 . V_99 ;
else if ( V_93 -> V_94 . V_95 . V_97 < V_2 -> V_117 . V_99 )
V_93 -> V_94 . V_95 . V_97 = V_2 -> V_117 . V_99 ;
if ( V_93 -> V_94 . V_95 . V_100 > V_2 -> V_116 . V_101 )
V_93 -> V_94 . V_95 . V_100 = V_2 -> V_116 . V_101 ;
else if ( V_93 -> V_94 . V_95 . V_100 < V_2 -> V_117 . V_101 )
V_93 -> V_94 . V_95 . V_100 = V_2 -> V_117 . V_101 ;
return 0 ;
}
static int F_19 ( struct V_118 * V_118 , void * V_119 , struct V_92 * V_93 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
int V_120 , V_121 , V_122 , V_123 , V_106 ;
if ( ! V_2 -> V_124 )
return - V_125 ;
if ( V_2 -> V_126 != NULL &&
V_2 -> V_126 != V_118 )
return - V_127 ;
V_2 -> V_126 = V_118 ;
V_120 = F_17 ( V_2 , V_93 ) ;
if ( V_120 < 0 )
return V_120 ;
V_106 = V_93 -> V_94 . V_95 . V_106 ;
V_123 = V_2 -> V_128 ;
V_122 = 0 ;
V_121 = V_2 -> V_129 ;
if ( V_93 -> V_94 . V_95 . V_130 ) {
V_123 = ( V_93 -> V_94 . V_95 . V_130 & V_131 ) >> V_132 ;
V_122 = ! ! ( V_93 -> V_94 . V_95 . V_130 & V_133 ) ;
V_121 = ( V_93 -> V_94 . V_95 . V_130 & V_134 ) >> V_135 ;
if ( V_121 == 0 )
V_121 = V_2 -> V_129 ;
}
if ( V_106 != V_105 &&
V_106 != V_112 &&
V_106 != V_113 )
return - V_115 ;
if ( F_21 ( & V_2 -> V_136 ) )
return - V_127 ;
F_16 ( L_7
L_8 ,
V_93 -> V_94 . V_95 . V_97 , V_93 -> V_94 . V_95 . V_100 , V_121 ,
V_123 , V_122 ,
( V_106 ) & 255 ,
( V_106 >> 8 ) & 255 ,
( V_106 >> 16 ) & 255 ,
( V_106 >> 24 ) & 255 ) ;
V_120 = F_22 ( V_2 ,
V_93 -> V_94 . V_95 . V_97 ,
V_93 -> V_94 . V_95 . V_100 ,
V_121 ,
V_123 ,
V_122 ) ;
F_16 ( L_9 , V_120 ) ;
if ( V_120 )
return V_120 ;
V_2 -> V_104 = V_106 ;
F_14 ( V_2 , V_93 ) ;
return 0 ;
}
static int F_23 ( struct V_118 * V_118 , void * V_119 , struct V_137 * V_138 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
if ( ! V_2 -> V_124 )
return - V_125 ;
strcpy ( V_138 -> V_139 , V_140 ) ;
F_24 ( V_138 -> V_141 , V_2 -> V_142 . V_29 , sizeof( V_138 -> V_141 ) ) ;
F_25 ( V_2 -> V_124 , V_138 -> V_143 , sizeof( V_138 -> V_143 ) ) ;
V_138 -> V_144 =
V_145 |
V_146 |
V_147 ;
return 0 ;
}
static int F_26 ( struct V_118 * V_118 , void * V_119 , struct V_148 * V_149 )
{
if ( V_149 -> V_150 )
return - V_115 ;
strcpy ( V_149 -> V_29 , L_10 ) ;
return 0 ;
}
static int F_27 ( struct V_118 * V_118 , void * V_119 , unsigned int * V_149 )
{
* V_149 = 0 ;
return 0 ;
}
static int F_28 ( struct V_118 * V_118 , void * V_119 , unsigned int V_149 )
{
return V_149 ? - V_115 : 0 ;
}
static int F_29 ( struct V_151 * V_152 )
{
struct V_1 * V_2 =
F_30 ( V_152 -> V_153 , struct V_1 , V_9 ) ;
int V_120 = 0 ;
F_31 ( & V_2 -> V_154 ) ;
F_32 ( & V_2 -> V_155 ) ;
if ( ! V_2 -> V_124 ) {
V_120 = - V_125 ;
goto V_156;
}
switch ( V_152 -> V_30 ) {
case V_157 :
if ( V_2 -> V_158 && F_33 ( V_159 ,
V_2 -> V_160 + V_161 / 4 ) ) {
V_2 -> V_33 -> V_40 = V_2 -> V_162 ;
V_2 -> V_36 -> V_40 = V_2 -> V_163 ;
break;
}
V_120 = F_3 ( V_2 , V_50 ,
V_164 ,
& V_2 -> V_33 -> V_40 ) ;
if ( V_120 )
break;
V_120 = F_3 ( V_2 , V_50 ,
V_165 ,
& V_2 -> V_36 -> V_40 ) ;
if ( V_120 )
break;
V_2 -> V_162 = V_2 -> V_33 -> V_40 ;
V_2 -> V_163 = V_2 -> V_36 -> V_40 ;
V_2 -> V_160 = V_159 ;
V_2 -> V_158 = true ;
break;
case V_43 :
if ( V_2 -> V_166 && F_33 ( V_159 ,
V_2 -> V_167 + V_161 / 4 ) ) {
V_2 -> V_45 -> V_40 = V_2 -> V_168 ;
break;
}
V_120 = F_3 ( V_2 , V_50 ,
V_169 , & V_2 -> V_45 -> V_40 ) ;
if ( V_120 )
break;
V_2 -> V_168 = V_2 -> V_45 -> V_40 ;
V_2 -> V_167 = V_159 ;
V_2 -> V_166 = true ;
if ( ! F_12 ( V_2 -> type ) )
break;
case V_49 :
if ( V_2 -> V_170 && F_33 ( V_159 ,
V_2 -> V_171 + V_161 / 4 ) ) {
V_2 -> V_52 -> V_40 = V_2 -> V_172 ;
break;
}
V_120 = F_11 ( V_2 , V_50 ,
V_51 ,
& V_2 -> V_52 -> V_40 ) ;
if ( V_120 )
break;
V_2 -> V_172 = V_2 -> V_52 -> V_40 ;
V_2 -> V_171 = V_159 ;
V_2 -> V_170 = true ;
break;
default:
V_120 = - V_115 ;
}
if ( V_120 )
F_34 ( L_11 , V_152 -> V_29 , V_120 ) ;
V_156:
F_31 ( & V_2 -> V_155 ) ;
F_32 ( & V_2 -> V_154 ) ;
return V_120 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_120 = 0 ;
if ( V_2 -> V_31 -> V_173 ) {
V_120 = F_36 ( V_2 , V_174 ,
V_26 ,
V_2 -> V_31 -> V_40 ) ;
if ( V_120 )
return V_120 ;
if ( V_2 -> V_33 -> V_175 ||
V_2 -> V_31 -> V_40 == V_176 ||
V_2 -> V_31 -> V_40 == V_177 ||
V_2 -> V_31 -> V_40 == V_178 ) {
if ( ! V_2 -> V_33 -> V_173 )
F_3 ( V_2 , V_50 ,
V_164 ,
& V_2 -> V_33 -> V_40 ) ;
if ( ! V_2 -> V_36 -> V_173 )
F_3 ( V_2 , V_50 ,
V_165 ,
& V_2 -> V_36 -> V_40 ) ;
}
if ( V_2 -> V_31 -> V_40 == V_27 ) {
V_2 -> V_33 -> V_175 = true ;
V_2 -> V_36 -> V_175 = true ;
V_2 -> V_158 = false ;
} else {
V_2 -> V_33 -> V_175 = false ;
V_2 -> V_36 -> V_175 = false ;
}
}
if ( V_120 == 0 && V_2 -> V_33 -> V_173 ) {
if ( V_2 -> V_31 -> V_40 != V_38 )
return - V_127 ;
V_120 = F_36 ( V_2 , V_174 ,
V_32 ,
V_2 -> V_33 -> V_40 ) ;
}
if ( V_120 == 0 && V_2 -> V_36 -> V_173 ) {
if ( V_2 -> V_31 -> V_40 != V_38 )
return - V_127 ;
V_120 = F_36 ( V_2 , V_174 ,
V_35 ,
V_2 -> V_36 -> V_40 ) ;
}
return V_120 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_120 = 0 ;
if ( V_2 -> V_42 -> V_173 ) {
V_120 = F_36 ( V_2 , V_179 ,
V_41 ,
V_2 -> V_42 -> V_40 ? 0 : 0xff ) ;
if ( V_120 )
return V_120 ;
if ( V_2 -> V_42 -> V_40 )
V_2 -> V_166 = false ;
else if ( ! V_2 -> V_45 -> V_173 )
F_3 ( V_2 , V_50 ,
V_169 ,
& V_2 -> V_45 -> V_40 ) ;
}
if ( V_120 == 0 && V_2 -> V_45 -> V_173 ) {
if ( V_2 -> V_42 -> V_40 )
return - V_127 ;
V_120 = F_36 ( V_2 , V_179 ,
V_44 ,
V_2 -> V_45 -> V_40 ) ;
}
return V_120 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_120 = 0 ;
int V_180 = V_2 -> V_48 -> V_40 == V_181 ;
if ( V_2 -> V_48 -> V_173 ) {
V_120 = F_36 ( V_2 , V_179 ,
V_47 ,
V_180 ? 0 : 0xff ) ;
if ( V_120 )
return V_120 ;
if ( V_180 )
V_2 -> V_170 = false ;
else if ( ! V_2 -> V_52 -> V_173 )
F_11 ( V_2 , V_50 ,
V_51 ,
& V_2 -> V_52 -> V_40 ) ;
}
if ( V_120 == 0 && V_2 -> V_52 -> V_173 ) {
if ( V_180 )
return - V_127 ;
V_120 = F_39 ( V_2 , V_179 ,
V_182 ,
V_2 -> V_52 -> V_40 ) ;
}
return V_120 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_120 = 0 ;
if ( V_2 -> V_42 -> V_173 ) {
V_120 = F_36 ( V_2 , V_179 ,
V_41 ,
V_2 -> V_42 -> V_40 ? 0 : 0xff ) ;
if ( V_120 )
return V_120 ;
if ( V_2 -> V_42 -> V_40 ) {
V_2 -> V_166 = false ;
V_2 -> V_170 = false ;
} else {
if ( ! V_2 -> V_45 -> V_173 )
F_3 ( V_2 , V_50 ,
V_169 ,
& V_2 -> V_45 -> V_40 ) ;
if ( ! V_2 -> V_52 -> V_173 )
F_11 ( V_2 , V_50 ,
V_51 ,
& V_2 -> V_52 -> V_40 ) ;
}
}
if ( V_120 == 0 && V_2 -> V_45 -> V_173 ) {
if ( V_2 -> V_42 -> V_40 )
return - V_127 ;
V_120 = F_36 ( V_2 , V_179 ,
V_44 ,
V_2 -> V_45 -> V_40 ) ;
}
if ( V_120 == 0 && V_2 -> V_52 -> V_173 ) {
if ( V_2 -> V_42 -> V_40 )
return - V_127 ;
V_120 = F_39 ( V_2 , V_179 ,
V_182 ,
V_2 -> V_52 -> V_40 ) ;
}
return V_120 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_120 ;
T_1 V_183 [ 4 ] ;
V_183 [ 0 ] = 0 ;
if ( V_2 -> V_88 -> V_173 )
V_183 [ 0 ] |= 0x01 ;
if ( V_2 -> V_90 -> V_173 )
V_183 [ 0 ] |= 0x02 ;
if ( V_2 -> V_88 -> V_173 || V_2 -> V_90 -> V_173 ) {
V_120 = F_42 ( V_2 , V_184 ,
V_185 , V_183 , 1 ) ;
if ( V_120 < 0 )
return V_120 ;
}
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
if ( V_2 -> V_84 -> V_173 ) {
V_183 [ 0 ] = V_2 -> V_84 -> V_40 & 0xFF ;
V_183 [ 1 ] = ( V_2 -> V_84 -> V_40 >> 8 ) ;
}
if ( V_2 -> V_86 -> V_173 ) {
V_183 [ 2 ] = V_2 -> V_86 -> V_40 & 0xFF ;
V_183 [ 3 ] = ( V_2 -> V_86 -> V_40 >> 8 ) ;
}
if ( V_2 -> V_84 -> V_173 || V_2 -> V_86 -> V_173 ) {
V_120 = F_42 ( V_2 , V_184 ,
V_186 ,
V_183 , sizeof( V_183 ) ) ;
if ( V_120 < 0 )
return V_120 ;
}
return 0 ;
}
static int F_43 ( struct V_151 * V_152 )
{
struct V_1 * V_2 =
F_30 ( V_152 -> V_153 , struct V_1 , V_9 ) ;
int V_120 = 0 ;
F_31 ( & V_2 -> V_154 ) ;
F_32 ( & V_2 -> V_155 ) ;
if ( ! V_2 -> V_124 ) {
V_120 = - V_125 ;
goto V_156;
}
switch ( V_152 -> V_30 ) {
case V_14 :
V_120 = F_36 ( V_2 , V_179 ,
V_11 , V_152 -> V_40 ) ;
break;
case V_17 :
V_120 = F_36 ( V_2 , V_179 ,
V_15 , V_152 -> V_40 ) ;
break;
case V_23 :
V_120 = F_44 ( V_2 , V_174 ,
V_2 -> V_18 , V_152 -> V_40 ) ;
break;
case V_25 :
V_120 = F_36 ( V_2 , V_179 ,
V_24 , V_152 -> V_40 ) ;
break;
case V_157 :
V_120 = F_35 ( V_2 ) ;
break;
case V_43 :
if ( F_9 ( V_2 -> type ) )
V_120 = F_37 ( V_2 ) ;
else if ( F_12 ( V_2 -> type ) )
V_120 = F_40 ( V_2 ) ;
else
V_120 = - V_115 ;
break;
case V_49 :
if ( F_9 ( V_2 -> type ) )
V_120 = F_38 ( V_2 ) ;
else
V_120 = - V_115 ;
break;
case V_58 :
V_120 = F_36 ( V_2 , V_174 ,
V_56 ,
V_152 -> V_40 ? 0 : 0xff ) ;
break;
case F_45 ( V_61 ) :
if ( V_2 -> V_61 -> V_173 ) {
V_120 = F_36 ( V_2 , V_179 ,
V_59 ,
V_2 -> V_61 -> V_40 ? 0 : 0xff ) ;
}
if ( V_120 == 0 && V_2 -> V_64 -> V_173 ) {
if ( V_2 -> V_61 -> V_40 ) {
V_120 = - V_127 ;
break;
}
V_120 = F_36 ( V_2 , V_179 ,
V_62 ,
V_2 -> V_64 -> V_40 ) ;
}
break;
case V_187 :
V_120 = F_36 ( V_2 , V_179 ,
V_65 ,
V_152 -> V_40 ? 0 : 0xff ) ;
break;
case V_188 :
V_120 = F_36 ( V_2 , V_179 ,
V_68 ,
V_152 -> V_40 ? 0 : 0xff ) ;
break;
case F_45 ( V_73 ) :
V_120 = F_36 ( V_2 , V_179 ,
V_71 ,
V_152 -> V_40 ) ;
break;
case F_45 ( V_74 ) :
V_120 = F_46 ( V_2 , V_189 ) ;
break;
case F_45 ( V_76 ) :
V_120 = F_46 ( V_2 , V_190 ) ;
break;
case F_45 ( V_80 ) :
V_120 = F_46 ( V_2 ,
V_191 ) ;
break;
case V_85 :
V_120 = F_41 ( V_2 ) ;
break;
default:
V_120 = - V_115 ;
}
if ( V_120 )
F_34 ( L_12 , V_152 -> V_29 , V_120 ) ;
V_156:
F_31 ( & V_2 -> V_155 ) ;
F_32 ( & V_2 -> V_154 ) ;
return V_120 ;
}
static int F_47 ( struct V_118 * V_118 , void * V_119 , struct V_192 * V_93 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
switch ( V_93 -> V_150 ) {
case 0 :
V_93 -> V_106 = V_2 -> type <= 646 ? V_112 : V_113 ;
V_93 -> V_78 = V_193 ;
F_24 ( V_93 -> V_194 , L_13 , sizeof( V_93 -> V_194 ) ) ;
break;
case 1 :
V_93 -> V_106 = V_105 ;
F_24 ( V_93 -> V_194 , L_14 , sizeof( V_93 -> V_194 ) ) ;
break;
default:
return - V_115 ;
}
return 0 ;
}
static int F_48 ( struct V_118 * V_118 , void * V_119 , struct V_92 * V_93 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
F_16 ( L_15 ,
V_2 -> V_195 . V_99 , V_2 -> V_195 . V_101 ) ;
F_14 ( V_2 , V_93 ) ;
return 0 ;
}
static int F_49 ( struct V_118 * V_118 , void * V_119 , struct V_92 * V_93 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
return F_17 ( V_2 , V_93 ) ;
}
static int F_50 ( struct V_118 * V_118 , void * V_119 ,
struct V_196 * V_197 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
if ( V_2 -> V_126 != NULL &&
V_2 -> V_126 != V_118 )
return - V_127 ;
V_2 -> V_126 = V_118 ;
return F_51 ( & V_2 -> V_136 , V_197 ) ;
}
static int F_52 ( struct V_118 * V_118 , void * V_119 , struct V_198 * V_183 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
return F_53 ( & V_2 -> V_136 , V_183 ) ;
}
static int F_54 ( struct V_118 * V_118 , void * V_119 , struct V_198 * V_183 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
if ( ! V_2 -> V_124 )
return - V_125 ;
if ( V_2 -> V_126 != V_118 )
return - V_127 ;
return F_55 ( & V_2 -> V_136 , V_183 ) ;
}
static int F_56 ( struct V_118 * V_118 , void * V_119 , struct V_198 * V_183 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
if ( ! V_2 -> V_124 )
return - V_125 ;
if ( V_2 -> V_126 != V_118 )
return - V_127 ;
return F_57 ( & V_2 -> V_136 , V_183 , V_118 -> V_199 & V_200 ) ;
}
static int F_58 ( struct V_118 * V_118 , void * V_119 , enum V_201 V_149 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
if ( ! V_2 -> V_124 )
return - V_125 ;
if ( V_2 -> V_126 != V_118 )
return - V_127 ;
return F_59 ( & V_2 -> V_136 , V_149 ) ;
}
static int F_60 ( struct V_118 * V_118 , void * V_119 , enum V_201 V_149 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
if ( ! V_2 -> V_124 )
return - V_125 ;
if ( V_2 -> V_126 != V_118 )
return - V_127 ;
return F_61 ( & V_2 -> V_136 , V_149 ) ;
}
static int F_62 ( struct V_118 * V_118 , void * V_119 ,
struct V_202 * V_203 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
unsigned int V_149 = 0 , V_150 = V_203 -> V_150 ;
if ( V_203 -> V_204 == V_105 ) {
for ( V_149 = 0 ; V_149 < V_205 ; V_149 ++ ) {
if ( V_2 -> V_206 & ( 1UL << V_149 ) ) {
if ( ! V_150 -- ) {
V_203 -> type = V_207 ;
V_203 -> V_208 . V_97 = V_209 [ V_149 ] . V_99 ;
V_203 -> V_208 . V_100 = V_209 [ V_149 ] . V_101 ;
return 0 ;
}
}
}
} else if ( V_203 -> V_150 == 0 &&
( ( V_203 -> V_204 == V_112 && F_15 ( V_2 -> type ) ) ||
( V_203 -> V_204 == V_113 && F_18 ( V_2 -> type ) ) ) ) {
V_203 -> type = V_207 ;
V_203 -> V_208 . V_97 = V_2 -> V_210 . V_99 ;
V_203 -> V_208 . V_100 = V_2 -> V_210 . V_101 ;
return 0 ;
}
return - V_115 ;
}
static int F_63 ( struct V_118 * V_118 , void * V_119 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
int V_213 = - 1 ;
unsigned int V_149 ;
for ( V_149 = 0 ; V_149 < V_205 ; V_149 ++ ) {
if ( V_209 [ V_149 ] . V_99 == V_212 -> V_97 &&
V_209 [ V_149 ] . V_101 == V_212 -> V_100 ) {
V_213 = V_149 ;
break;
}
}
if ( V_213 < 0 || V_212 -> V_204 != V_105 )
return - V_115 ;
V_149 = F_64 ( V_2 , V_212 -> V_150 , V_213 ) ;
if ( ! V_149 )
return - V_115 ;
V_212 -> type = V_214 ;
V_212 -> V_208 . V_215 = 1 ;
V_212 -> V_208 . V_216 = V_149 ;
return 0 ;
}
static long F_65 ( struct V_118 * V_118 , void * V_119 , bool V_217 ,
int V_218 , void * V_219 )
{
struct V_1 * V_2 = F_20 ( V_118 ) ;
return F_66 ( V_2 , V_218 , V_219 ) ;
}
