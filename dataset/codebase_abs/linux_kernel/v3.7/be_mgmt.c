unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
unsigned int V_11 = 0 ;
F_2 ( V_2 , V_12 ,
V_13 | V_14 ,
L_1 ) ;
F_3 ( & V_6 -> V_15 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 ) {
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
V_8 = F_6 ( V_2 ) ;
V_10 = F_7 ( V_8 ) ;
V_8 -> V_16 |= V_11 ;
F_8 ( V_8 , sizeof( * V_10 ) , true , 0 ) ;
F_9 ( & V_10 -> V_17 , V_18 ,
V_19 ,
sizeof( struct V_20 ) ) ;
V_10 -> V_3 = V_3 ;
V_10 -> V_21 = V_4 ;
F_10 ( V_2 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
unsigned int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_22 * V_10 ;
unsigned int V_11 = 0 ;
F_2 ( V_2 , V_12 ,
V_13 | V_14 ,
L_1 ) ;
F_3 ( & V_6 -> V_15 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 ) {
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
V_8 = F_6 ( V_2 ) ;
V_10 = F_7 ( V_8 ) ;
V_8 -> V_16 |= V_11 ;
F_8 ( V_8 , sizeof( * V_10 ) , true , 0 ) ;
F_9 ( & V_10 -> V_17 , V_18 ,
V_23 ,
sizeof( struct V_24 ) ) ;
F_10 ( V_2 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
unsigned int F_12 ( struct V_1 * V_2 ,
T_1 V_25 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
unsigned int V_11 = 0 ;
struct V_28 * V_10 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
F_2 ( V_2 , V_12 ,
V_13 | V_14 ,
L_2 ) ;
F_3 ( & V_6 -> V_15 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 ) {
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
V_27 -> V_33 = sizeof( * V_30 ) ;
V_10 = V_27 -> V_34 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_8 = F_6 ( V_2 ) ;
V_32 = F_13 ( V_8 ) ;
V_8 -> V_16 |= V_11 ;
V_8 -> V_16 |= V_11 ;
F_8 ( V_8 , sizeof( * V_10 ) , false , 1 ) ;
F_9 ( & V_10 -> V_17 , V_18 ,
V_35 ,
sizeof( * V_30 ) ) ;
V_10 -> V_21 = V_25 ;
V_32 -> V_36 = F_14 ( F_15 ( V_27 -> V_37 ) ) ;
V_32 -> V_38 = F_14 ( V_27 -> V_37 & 0xFFFFFFFF ) ;
V_32 -> V_39 = F_14 ( V_27 -> V_33 ) ;
F_10 ( V_2 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
int F_16 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_17 ( & V_6 -> V_40 ) ;
struct V_41 * V_10 = F_7 ( V_8 ) ;
int V_42 = 0 ;
F_3 ( & V_6 -> V_15 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_8 ( V_8 , sizeof( * V_10 ) , true , 0 ) ;
F_9 ( & V_10 -> V_17 , V_43 ,
V_44 , sizeof( * V_10 ) ) ;
V_42 = F_18 ( V_6 ) ;
if ( ! V_42 ) {
struct V_41 * V_45 ;
V_45 = V_10 ;
V_2 -> V_46 . V_47 = V_45 -> V_47 ;
V_2 -> V_46 . V_48 =
V_45 -> V_49 [ 0 ] . V_50 ;
V_2 -> V_46 . V_51 =
V_45 -> V_49 [ 0 ] . V_52 ;
V_2 -> V_46 . V_53 =
V_45 -> V_49 [ 0 ] . V_54 ;
V_2 -> V_46 . V_55 =
V_45 -> V_49 [ 0 ] . V_56 ;
if ( V_2 -> V_46 . V_55 > ( V_57 / 2 ) ) {
F_2 ( V_2 , V_12 , V_58 ,
L_3
L_4 ,
V_2 -> V_46 . V_55 ,
V_57 ) ;
V_2 -> V_46 . V_55 = V_57 / 2 ;
}
} else {
F_2 ( V_2 , V_59 , V_58 ,
L_5 ) ;
}
F_5 ( & V_6 -> V_15 ) ;
return V_42 ;
}
int F_19 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_26 V_27 ;
struct V_7 * V_8 = F_17 ( & V_6 -> V_40 ) ;
struct V_60 * V_10 ;
struct V_31 * V_32 = F_13 ( V_8 ) ;
int V_42 = 0 ;
V_27 . V_34 = F_20 ( V_6 -> V_61 ,
sizeof( struct V_60 ) ,
& V_27 . V_37 ) ;
if ( V_27 . V_34 == NULL ) {
F_2 ( V_2 , V_62 , V_58 ,
L_6
L_7 ) ;
return - V_63 ;
}
V_27 . V_33 = sizeof( struct V_60 ) ;
V_10 = V_27 . V_34 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
F_3 ( & V_6 -> V_15 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_8 ( V_8 , sizeof( * V_10 ) , false , 1 ) ;
F_9 ( & V_10 -> V_17 , V_43 ,
V_64 , sizeof( * V_10 ) ) ;
V_32 -> V_36 = F_14 ( F_15 ( V_27 . V_37 ) ) ;
V_32 -> V_38 = F_14 ( V_27 . V_37 & 0xFFFFFFFF ) ;
V_32 -> V_39 = F_14 ( V_27 . V_33 ) ;
V_42 = F_18 ( V_6 ) ;
if ( ! V_42 ) {
struct V_65 * V_30 = V_27 . V_34 ;
F_2 ( V_2 , V_12 , V_58 ,
L_8
L_9
L_10 ,
V_30 -> V_66 . V_67
. V_68 ,
V_30 -> V_66 . V_67 .
V_69 ) ;
V_2 -> V_46 . V_70 =
V_30 -> V_66 . V_67 . V_70 ;
F_2 ( V_2 , V_12 , V_58 ,
L_11 ,
V_2 -> V_46 . V_70 ) ;
} else
F_2 ( V_2 , V_62 , V_58 ,
L_12 ) ;
F_5 ( & V_6 -> V_15 ) ;
if ( V_27 . V_34 )
F_21 ( V_6 -> V_61 , V_27 . V_33 ,
V_27 . V_34 , V_27 . V_37 ) ;
return V_42 ;
}
unsigned int F_22 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
struct V_71 * V_72 ,
struct V_26 * V_27 )
{
struct V_73 * V_30 ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_31 * V_74 = F_13 ( V_8 ) ;
unsigned int V_11 = 0 ;
struct V_75 * V_76 = V_72 -> V_77 ;
struct V_78 * V_10 = V_27 -> V_34 ;
unsigned short V_79 , V_80 , V_81 , V_82 ;
V_27 -> V_33 = V_72 -> V_83 . V_84 ;
memset ( V_27 -> V_34 , 0 , V_27 -> V_33 ) ;
V_30 = V_27 -> V_34 ;
V_79 = V_76 -> V_85 . V_86 . V_87 [ 1 ] ;
V_80 = V_76 -> V_85 . V_86 . V_87 [ 2 ] ;
V_81 = V_76 -> V_85 . V_86 . V_87 [ 3 ] ;
V_82 = V_76 -> V_85 . V_86 . V_87 [ 4 ] ;
V_10 -> V_79 = V_79 ;
V_10 -> V_81 = V_81 ;
V_10 -> V_82 = V_82 ;
F_3 ( & V_6 -> V_15 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
switch ( V_76 -> V_85 . V_86 . V_87 [ 0 ] ) {
case V_88 :
V_82 = V_81 * V_80 + V_82 ;
F_9 ( & V_10 -> V_17 , V_89 ,
V_90 , sizeof( * V_10 ) ) ;
F_23 ( V_72 -> V_83 . V_91 ,
V_72 -> V_83 . V_92 ,
V_27 -> V_34 + V_82 , V_72 -> V_93 ) ;
break;
case V_94 :
F_9 ( & V_10 -> V_17 , V_89 ,
V_95 , sizeof( * V_10 ) ) ;
break;
default:
F_2 ( V_2 , V_59 , V_13 ,
L_13 ,
V_76 -> V_85 . V_86 . V_87 [ 0 ] ) ;
F_5 ( & V_6 -> V_15 ) ;
return - V_96 ;
}
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 ) {
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
F_8 ( V_8 , V_27 -> V_33 , false ,
V_72 -> V_83 . V_92 ) ;
V_74 -> V_36 = F_14 ( F_15 ( V_27 -> V_37 ) ) ;
V_74 -> V_38 = F_14 ( V_27 -> V_37 & 0xFFFFFFFF ) ;
V_74 -> V_39 = F_14 ( V_27 -> V_33 ) ;
V_8 -> V_16 |= V_11 ;
F_10 ( V_2 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
int F_24 ( struct V_1 * V_2 , unsigned short V_97 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_98 * V_10 = F_7 ( V_8 ) ;
int V_42 = 0 ;
F_3 ( & V_6 -> V_15 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_8 ( V_8 , sizeof( * V_10 ) , true , 0 ) ;
F_9 ( & V_10 -> V_17 , V_89 ,
V_99 , sizeof( * V_10 ) ) ;
V_10 -> V_97 = V_97 ;
V_10 -> V_100 = F_25 ( F_26 ( V_2 ) ) ;
V_10 -> V_101 = F_25 ( F_27 ( V_2 ) ) ;
V_42 = F_28 ( V_2 ) ;
if ( V_42 )
F_2 ( V_2 , V_59 , V_58 ,
L_14 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_42 ;
}
unsigned int F_29 ( struct V_1 * V_2 ,
struct V_102 * V_103 ,
unsigned int V_104 , unsigned int V_105 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_31 * V_32 ;
struct V_106 * V_10 ;
unsigned int V_107 , V_11 = 0 ;
F_3 ( & V_6 -> V_15 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 ) {
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
V_10 = V_27 -> V_34 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_8 = F_6 ( V_2 ) ;
V_32 = F_13 ( V_8 ) ;
V_8 -> V_16 |= V_11 ;
F_8 ( V_8 , sizeof( * V_10 ) , false , 1 ) ;
F_9 ( & V_10 -> V_17 , V_89 ,
V_108 ,
sizeof( * V_10 ) ) ;
V_10 -> V_109 = 0 ;
V_10 -> V_110 = V_111 ;
for ( V_107 = 0 ; V_107 < V_104 ; V_107 ++ ) {
V_10 -> V_112 [ V_107 ] . V_113 = V_103 -> V_113 ;
V_10 -> V_112 [ V_107 ] . V_105 = V_103 -> V_105 ;
V_10 -> V_52 ++ ;
V_103 ++ ;
}
V_32 -> V_36 = F_14 ( F_15 ( V_27 -> V_37 ) ) ;
V_32 -> V_38 = F_14 ( V_27 -> V_37 & 0xFFFFFFFF ) ;
V_32 -> V_39 = F_14 ( V_27 -> V_33 ) ;
F_10 ( V_2 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
unsigned int F_30 ( struct V_1 * V_2 ,
struct V_114 * V_115 ,
unsigned short V_105 ,
unsigned short V_116 ,
unsigned short V_117 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_118 * V_10 ;
unsigned int V_11 = 0 ;
F_3 ( & V_6 -> V_15 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 ) {
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
V_8 = F_6 ( V_2 ) ;
V_8 -> V_16 |= V_11 ;
V_10 = F_7 ( V_8 ) ;
F_8 ( V_8 , sizeof( * V_10 ) , true , 0 ) ;
F_9 ( & V_10 -> V_17 , V_18 ,
V_119 ,
sizeof( * V_10 ) ) ;
V_10 -> V_21 = V_115 -> V_120 ;
V_10 -> V_105 = V_105 ;
if ( V_116 )
V_10 -> V_110 = V_121 ;
else
V_10 -> V_110 = V_122 ;
V_10 -> V_123 = V_117 ;
F_10 ( V_2 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
unsigned int F_31 ( struct V_1 * V_2 ,
unsigned short V_105 , unsigned int V_124 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_125 * V_10 ;
unsigned int V_11 = 0 ;
F_3 ( & V_6 -> V_15 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 ) {
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
V_8 = F_6 ( V_2 ) ;
V_10 = F_7 ( V_8 ) ;
V_8 -> V_16 |= V_11 ;
F_8 ( V_8 , sizeof( * V_10 ) , true , 0 ) ;
F_9 ( & V_10 -> V_17 , V_126 ,
V_127 , sizeof( * V_10 ) ) ;
V_10 -> V_128 = ( unsigned short ) V_105 ;
V_10 -> V_129 = ( unsigned char ) V_124 ;
F_10 ( V_2 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_130 * V_131 ,
struct V_114 * V_115 ,
struct V_26 * V_27 )
{
struct V_132 * V_133 ;
struct V_134 * V_135 ;
struct V_136 * V_137 = (struct V_136 * ) V_131 ;
struct V_138 * V_139 = (struct V_138 * ) V_131 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_140 * V_10 ;
unsigned short V_141 ;
unsigned short V_142 ;
struct V_143 V_144 = { 0 , 0 } ;
struct V_143 * V_145 ;
unsigned int V_11 = 0 ;
unsigned int V_107 ;
unsigned short V_105 = V_115 -> V_146 ;
struct V_31 * V_32 ;
V_133 = V_2 -> V_133 ;
V_135 = V_133 -> V_147 ;
V_141 = ( unsigned short ) F_26 ( V_2 ) ;
V_142 = ( unsigned short ) F_27 ( V_2 ) ;
V_145 = & V_144 ;
F_33 ( V_2 , V_145 ) ;
F_3 ( & V_6 -> V_15 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 ) {
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
V_8 = F_6 ( V_2 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_32 = F_13 ( V_8 ) ;
V_10 = V_27 -> V_34 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_8 -> V_16 |= V_11 ;
F_8 ( V_8 , sizeof( * V_10 ) , false , 1 ) ;
F_9 ( & V_10 -> V_17 , V_89 ,
V_148 ,
sizeof( * V_10 ) ) ;
if ( V_131 -> V_149 == V_150 ) {
T_2 V_151 = V_137 -> V_152 . V_151 ;
V_10 -> V_153 . V_154 = V_155 ;
V_10 -> V_153 . V_156 [ 0 ] = V_151 & 0x000000ff ;
V_10 -> V_153 . V_156 [ 1 ] = ( V_151 & 0x0000ff00 ) >> 8 ;
V_10 -> V_153 . V_156 [ 2 ] = ( V_151 & 0x00ff0000 ) >> 16 ;
V_10 -> V_153 . V_156 [ 3 ] = ( V_151 & 0xff000000 ) >> 24 ;
V_10 -> V_157 = F_34 ( V_137 -> V_158 ) ;
V_115 -> V_131 = V_137 -> V_152 . V_151 ;
V_115 -> V_159 = F_34 ( V_137 -> V_158 ) ;
V_115 -> V_154 = V_155 ;
} else if ( V_131 -> V_149 == V_160 ) {
V_10 -> V_153 . V_154 = V_161 ;
memcpy ( & V_10 -> V_153 . V_156 ,
& V_139 -> V_162 . V_163 . V_164 , 16 ) ;
V_10 -> V_157 = F_34 ( V_139 -> V_165 ) ;
V_115 -> V_159 = F_34 ( V_139 -> V_165 ) ;
memcpy ( & V_115 -> V_166 ,
& V_139 -> V_162 . V_163 . V_164 , 16 ) ;
V_115 -> V_154 = V_161 ;
} else{
F_2 ( V_2 , V_62 , V_13 ,
L_15 ,
V_131 -> V_149 ) ;
F_5 ( & V_6 -> V_15 ) ;
F_35 ( & V_2 -> V_6 , V_11 ) ;
return - V_167 ;
}
V_10 -> V_105 = V_105 ;
V_107 = V_2 -> V_168 ++ ;
if ( V_2 -> V_168 == V_2 -> V_169 )
V_2 -> V_168 = 0 ;
V_10 -> V_170 = V_135 -> V_171 [ V_107 ] . V_128 ;
F_2 ( V_2 , V_12 , V_13 ,
L_16 , V_107 , V_10 -> V_170 ) ;
V_10 -> V_172 = V_141 ;
V_10 -> V_100 = V_141 ;
V_10 -> V_101 = V_142 ;
V_10 -> V_173 = 1 ;
V_10 -> V_174 . V_175 = V_145 -> V_175 ;
V_10 -> V_174 . V_176 = V_145 -> V_176 ;
V_32 -> V_36 = F_14 ( F_15 ( V_27 -> V_37 ) ) ;
V_32 -> V_38 = F_14 ( V_27 -> V_37 & 0xFFFFFFFF ) ;
V_32 -> V_39 = F_14 ( V_27 -> V_33 ) ;
F_10 ( V_2 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
unsigned int F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = F_17 ( & V_6 -> V_40 ) ;
struct V_177 * V_10 = F_7 ( V_8 ) ;
struct V_177 * V_178 = V_10 ;
int V_42 = 0 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_3 ( & V_6 -> V_15 ) ;
F_8 ( V_8 , sizeof( * V_10 ) , true , 0 ) ;
F_9 ( & V_10 -> V_17 , V_89 ,
V_179 ,
sizeof( * V_10 ) ) ;
V_42 = F_18 ( V_6 ) ;
if ( ! V_42 )
V_2 -> V_180 = V_178 -> V_181 [ 0 ] ;
else {
F_2 ( V_2 , V_59 , V_13 ,
L_17 ) ;
}
F_5 ( & V_6 -> V_15 ) ;
return V_42 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_26 * V_27 , void * V_182 ,
int V_183 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = F_6 ( V_2 ) ;
unsigned short V_42 , V_184 ;
struct V_31 * V_32 ;
unsigned int V_11 ;
int V_185 = 0 ;
F_3 ( & V_6 -> V_15 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 ) {
F_5 ( & V_6 -> V_15 ) ;
V_185 = - V_63 ;
goto V_186;
}
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_16 |= V_11 ;
V_32 = F_13 ( V_8 ) ;
F_8 ( V_8 , V_27 -> V_33 , false , 1 ) ;
V_32 -> V_36 = F_14 ( F_15 ( V_27 -> V_37 ) ) ;
V_32 -> V_38 = F_14 ( V_27 -> V_37 & 0xFFFFFFFF ) ;
V_32 -> V_39 = F_14 ( V_27 -> V_33 ) ;
F_10 ( V_2 ) ;
F_5 ( & V_6 -> V_15 ) ;
F_38 ( V_2 -> V_6 . V_187 [ V_11 ] ,
V_2 -> V_6 . V_188 [ V_11 ] ) ;
V_184 = ( V_2 -> V_6 . V_188 [ V_11 ] & 0x0000FF00 ) >> 8 ;
V_42 = V_2 -> V_6 . V_188 [ V_11 ] & 0x000000FF ;
if ( V_42 || V_184 ) {
F_2 ( V_2 , V_62 ,
V_13 | V_14 ,
L_18
L_19 , V_42 , V_184 ) ;
V_185 = - V_189 ;
goto V_190;
}
if ( V_182 )
memcpy ( V_182 , V_27 -> V_34 , V_183 ) ;
V_190:
F_35 ( & V_2 -> V_6 , V_11 ) ;
V_186:
F_21 ( V_6 -> V_61 , V_27 -> V_33 ,
V_27 -> V_34 , V_27 -> V_37 ) ;
return V_185 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_26 * V_191 ,
int V_192 , int V_33 )
{
V_191 -> V_34 = F_20 ( V_2 -> V_6 . V_61 , V_33 , & V_191 -> V_37 ) ;
if ( ! V_191 -> V_34 ) {
F_2 ( V_2 , V_62 , V_13 ,
L_20 ) ;
return - V_63 ;
}
memset ( V_191 -> V_34 , 0 , V_33 ) ;
V_191 -> V_33 = V_33 ;
F_9 ( V_191 -> V_34 , V_89 , V_192 , V_33 ) ;
return 0 ;
}
static int
F_40 ( struct V_1 * V_2 ,
struct V_193 * V_194 ,
struct V_195 * V_196 ,
struct V_195 * V_197 ,
T_3 V_198 )
{
struct V_199 * V_10 ;
struct V_26 V_27 ;
T_3 V_154 ;
int V_185 ;
V_185 = F_39 ( V_2 , & V_27 ,
V_200 ,
sizeof( * V_10 ) ) ;
if ( V_185 )
return V_185 ;
V_154 = ( V_196 -> V_201 == V_202 ) ?
V_161 : V_155 ;
V_10 = V_27 . V_34 ;
V_10 -> V_203 . V_204 = 1 ;
V_10 -> V_203 . V_205 . V_206 = V_198 ;
V_10 -> V_203 . V_205 . V_207 =
V_2 -> V_180 ;
V_10 -> V_203 . V_205 . V_208 . V_209 =
sizeof( struct V_210 ) ;
V_10 -> V_203 . V_205 . V_208 . V_154 = V_154 ;
if ( V_198 == V_211 ) {
memcpy ( V_10 -> V_203 . V_205 . V_208 . V_156 , V_196 -> V_212 ,
V_196 -> V_39 ) ;
if ( V_197 )
memcpy ( V_10 -> V_203 . V_205 . V_208 . V_213 ,
V_197 -> V_212 , V_197 -> V_39 ) ;
} else {
memcpy ( V_10 -> V_203 . V_205 . V_208 . V_156 ,
V_194 -> V_208 . V_156 , V_196 -> V_39 ) ;
memcpy ( V_10 -> V_203 . V_205 . V_208 . V_213 ,
V_194 -> V_208 . V_213 , V_196 -> V_39 ) ;
}
V_185 = F_37 ( V_2 , & V_27 , NULL , 0 ) ;
if ( V_185 < 0 )
F_2 ( V_2 , V_59 , V_13 ,
L_21 ) ;
return V_185 ;
}
static int F_41 ( struct V_1 * V_2 , T_4 * V_214 ,
T_3 V_215 , T_3 V_216 )
{
struct V_217 * V_10 ;
struct V_26 V_27 ;
int V_218 ;
V_218 = F_39 ( V_2 , & V_27 ,
V_219 ,
sizeof( * V_10 ) ) ;
if ( V_218 )
return V_218 ;
V_10 = V_27 . V_34 ;
V_10 -> V_206 = V_215 ;
V_10 -> V_208 . V_154 = V_155 ;
memcpy ( V_10 -> V_208 . V_156 , V_214 , V_216 ) ;
return F_37 ( V_2 , & V_27 , NULL , 0 ) ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_195 * V_196 ,
struct V_195 * V_197 ,
T_3 V_220 )
{
struct V_221 V_222 ;
struct V_193 V_194 ;
struct V_223 * V_224 ;
struct V_225 * V_226 ;
struct V_26 V_27 ;
T_4 * V_227 ;
T_3 V_154 ;
int V_185 ;
if ( F_36 ( V_2 ) )
return - V_189 ;
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
V_154 = ( V_196 -> V_201 == V_202 ) ?
V_161 : V_155 ;
V_185 = F_43 ( V_2 , V_154 , & V_194 ) ;
if ( V_185 )
return V_185 ;
if ( V_220 == V_228 ) {
if ( V_194 . V_229 ) {
F_2 ( V_2 , V_59 , V_13 ,
L_22 ) ;
return 0 ;
}
V_196 -> V_39 = ( V_196 -> V_201 == V_202 ) ?
V_230 : V_231 ;
} else {
if ( V_194 . V_229 ) {
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
V_185 = F_39 ( V_2 , & V_27 ,
V_232 ,
sizeof( * V_226 ) ) ;
if ( V_185 )
return V_185 ;
V_226 = V_27 . V_34 ;
V_226 -> V_207 = V_2 -> V_180 ;
V_226 -> V_154 = V_154 ;
V_185 = F_37 ( V_2 , & V_27 , NULL , 0 ) ;
if ( V_185 < 0 ) {
F_2 ( V_2 , V_59 ,
V_13 ,
L_23 ) ;
return V_185 ;
}
}
}
if ( V_194 . V_208 . V_156 [ 0 ] ) {
V_185 = F_40 ( V_2 , & V_194 , V_196 , NULL ,
V_233 ) ;
if ( V_185 )
return V_185 ;
}
if ( V_220 == V_228 ) {
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
V_185 = F_44 ( V_2 , V_155 , & V_222 ) ;
if ( V_185 ) {
F_2 ( V_2 , V_59 , V_13 ,
L_24 ) ;
return V_185 ;
}
if ( V_222 . V_208 . V_156 [ 0 ] ) {
V_227 = ( T_4 * ) & V_222 . V_208 . V_156 ;
V_185 = F_41 ( V_2 , V_227 ,
V_233 , V_231 ) ;
if ( V_185 ) {
F_2 ( V_2 , V_59 ,
V_13 ,
L_25 ) ;
return V_185 ;
}
}
}
if ( V_220 == V_228 ) {
V_185 = F_39 ( V_2 , & V_27 ,
V_234 ,
sizeof( * V_224 ) ) ;
if ( V_185 )
return V_185 ;
V_224 = V_27 . V_34 ;
V_224 -> V_235 = V_236 ;
V_224 -> V_237 = 1 ;
V_224 -> V_207 = V_2 -> V_180 ;
V_224 -> V_154 = V_238 ;
return F_37 ( V_2 , & V_27 , NULL , 0 ) ;
} else {
return F_40 ( V_2 , & V_194 , V_196 ,
V_197 , V_211 ) ;
}
return V_185 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_195 * V_239 )
{
struct V_221 V_222 ;
T_4 * V_227 ;
int V_218 ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
V_218 = F_44 ( V_2 , V_155 , & V_222 ) ;
if ( V_218 ) {
F_2 ( V_2 , V_59 , V_13 ,
L_24 ) ;
return V_218 ;
}
if ( V_222 . V_208 . V_156 [ 0 ] ) {
V_227 = ( T_4 * ) & V_222 . V_208 . V_156 ;
V_218 = F_41 ( V_2 , V_227 , V_233 ,
V_239 -> V_39 ) ;
if ( V_218 ) {
F_2 ( V_2 , V_59 , V_13 ,
L_25 ) ;
return V_218 ;
}
}
V_227 = ( T_4 * ) & V_239 -> V_212 ;
V_218 = F_41 ( V_2 , V_227 , V_211 ,
V_239 -> V_39 ) ;
if ( V_218 )
F_2 ( V_2 , V_59 , V_13 ,
L_26 ) ;
return V_218 ;
}
int F_44 ( struct V_1 * V_2 , int V_154 ,
struct V_221 * V_240 )
{
struct V_241 * V_10 ;
struct V_26 V_27 ;
int V_185 ;
V_185 = F_39 ( V_2 , & V_27 ,
V_242 ,
sizeof( * V_240 ) ) ;
if ( V_185 )
return V_185 ;
V_10 = V_27 . V_34 ;
V_10 -> V_154 = V_154 ;
return F_37 ( V_2 , & V_27 , V_240 ,
sizeof( * V_240 ) ) ;
}
int F_43 ( struct V_1 * V_2 , int V_154 ,
struct V_193 * V_194 )
{
struct V_243 * V_10 ;
struct V_26 V_27 ;
int V_185 ;
if ( F_36 ( V_2 ) )
return - V_189 ;
V_185 = F_39 ( V_2 , & V_27 ,
V_244 ,
sizeof( * V_194 ) ) ;
if ( V_185 )
return V_185 ;
V_10 = V_27 . V_34 ;
V_10 -> V_207 = V_2 -> V_180 ;
V_10 -> V_154 = V_154 ;
return F_37 ( V_2 , & V_27 , V_194 ,
sizeof( * V_194 ) ) ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_245 * V_246 )
{
struct V_26 V_27 ;
int V_185 ;
V_185 = F_39 ( V_2 , & V_27 ,
V_247 ,
sizeof( * V_246 ) ) ;
if ( V_185 )
return V_185 ;
return F_37 ( V_2 , & V_27 , V_246 , sizeof( * V_246 ) ) ;
}
unsigned int F_47 ( struct V_1 * V_2 )
{
unsigned int V_11 = 0 ;
struct V_7 * V_8 ;
struct V_248 * V_10 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_3 ( & V_6 -> V_15 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 ) {
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
V_8 = F_6 ( V_2 ) ;
V_10 = F_7 ( V_8 ) ;
V_8 -> V_16 |= V_11 ;
F_8 ( V_8 , sizeof( * V_10 ) , true , 0 ) ;
F_9 ( & V_10 -> V_17 , V_18 ,
V_249 ,
sizeof( * V_10 ) ) ;
F_10 ( V_2 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
unsigned int F_48 ( struct V_1 * V_2 )
{
unsigned int V_11 = 0 ;
struct V_7 * V_8 ;
struct V_250 * V_10 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_3 ( & V_6 -> V_15 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 ) {
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
V_8 = F_6 ( V_2 ) ;
V_10 = F_7 ( V_8 ) ;
V_8 -> V_16 |= V_11 ;
F_8 ( V_8 , sizeof( * V_10 ) , true , 0 ) ;
F_9 ( & V_10 -> V_17 , V_43 ,
V_251 ,
sizeof( * V_10 ) ) ;
F_10 ( V_2 ) ;
F_5 ( & V_6 -> V_15 ) ;
return V_11 ;
}
int F_49 ( struct V_1 * V_2 ,
unsigned int * V_252 )
{
struct V_24 * V_253 ;
struct V_7 * V_8 ;
unsigned int V_11 , V_254 ;
T_4 V_255 = 3 ;
unsigned short V_42 , V_184 ;
struct V_256 * V_257 = & V_2 -> V_6 . V_258 . V_259 ;
do {
V_11 = F_11 ( V_2 ) ;
if ( ! V_11 ) {
F_2 ( V_2 , V_62 ,
V_13 | V_58 ,
L_27 ) ;
return - V_260 ;
} else
F_38 ( V_2 -> V_6 . V_187 [ V_11 ] ,
V_2 -> V_6 . V_188 [ V_11 ] ) ;
V_254 = ( V_2 -> V_6 . V_188 [ V_11 ] & 0x00FF0000 ) >> 16 ;
V_184 = ( V_2 -> V_6 . V_188 [ V_11 ] & 0x0000FF00 ) >> 8 ;
V_42 = V_2 -> V_6 . V_188 [ V_11 ] & 0x000000FF ;
if ( V_42 || V_184 ) {
F_2 ( V_2 , V_62 ,
V_58 | V_13 ,
L_28
L_29 ,
V_42 , V_184 ) ;
F_35 ( & V_2 -> V_6 , V_11 ) ;
return - V_261 ;
}
V_8 = F_50 ( V_257 , V_254 ) ;
F_35 ( & V_2 -> V_6 , V_11 ) ;
V_253 = F_7 ( V_8 ) ;
if ( ! V_253 -> V_262 ) {
F_2 ( V_2 , V_12 ,
V_58 | V_13 ,
L_30 ) ;
return - V_263 ;
}
if ( V_253 -> V_25 != V_264 ) {
* V_252 = V_253 -> V_25 ;
return 0 ;
}
V_11 = F_1 ( V_2 , V_265 ,
V_264 ) ;
if ( ! V_11 ) {
F_2 ( V_2 , V_62 ,
V_58 | V_13 ,
L_31 ) ;
return - V_260 ;
} else
F_38 ( V_2 -> V_6 . V_187 [ V_11 ] ,
V_2 -> V_6 . V_188 [ V_11 ] ) ;
V_254 = ( V_2 -> V_6 . V_188 [ V_11 ] & 0x00FF0000 ) >> 16 ;
V_184 = ( V_2 -> V_6 . V_188 [ V_11 ] & 0x0000FF00 ) >> 8 ;
V_42 = V_2 -> V_6 . V_188 [ V_11 ] & 0x000000FF ;
if ( V_42 || V_184 ) {
F_2 ( V_2 , V_62 ,
V_58 | V_13 ,
L_32
L_29 ,
V_42 , V_184 ) ;
F_35 ( & V_2 -> V_6 , V_11 ) ;
return - V_261 ;
}
F_35 ( & V_2 -> V_6 , V_11 ) ;
} while ( -- V_255 );
F_2 ( V_2 , V_62 ,
V_58 | V_13 ,
L_33 ) ;
return - V_263 ;
}
int F_51 ( struct V_1 * V_2 ,
T_5 V_266 )
{
unsigned int V_11 , V_254 ;
unsigned short V_42 , V_184 ;
V_11 = F_52 ( V_2 , V_266 ) ;
if ( ! V_11 ) {
F_2 ( V_2 , V_62 ,
( V_13 | V_14 ) ,
L_34 ) ;
return - V_261 ;
} else
F_38 ( V_2 -> V_6 . V_187 [ V_11 ] ,
V_2 -> V_6 . V_188 [ V_11 ] ) ;
V_254 = ( V_2 -> V_6 . V_188 [ V_11 ] & 0x00FF0000 ) >> 16 ;
V_184 = ( V_2 -> V_6 . V_188 [ V_11 ] & 0x0000FF00 ) >> 8 ;
V_42 = V_2 -> V_6 . V_188 [ V_11 ] & 0x000000FF ;
if ( V_42 || V_184 ) {
F_2 ( V_2 , V_62 ,
( V_13 | V_14 ) ,
L_35 ,
V_42 , V_184 ) ;
F_35 ( & V_2 -> V_6 , V_11 ) ;
return - V_260 ;
}
F_35 ( & V_2 -> V_6 , V_11 ) ;
return 0 ;
}
