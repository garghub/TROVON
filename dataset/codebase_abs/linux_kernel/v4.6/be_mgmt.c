void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 , V_4 = 0 ;
T_1 V_5 = 0 , V_6 = 0 ;
T_2 V_7 = 0 ;
if ( V_2 -> V_8 )
return;
F_2 ( V_2 -> V_9 ,
V_10 , & V_4 ) ;
F_2 ( V_2 -> V_9 ,
V_11 ,
& V_6 ) ;
F_2 ( V_2 -> V_9 ,
V_12 ,
& V_3 ) ;
F_2 ( V_2 -> V_9 ,
V_13 ,
& V_5 ) ;
V_4 = ( V_4 & ~ V_6 ) ;
V_3 = ( V_3 & ~ V_5 ) ;
if ( V_4 || V_3 ) {
V_2 -> V_8 = true ;
F_3 ( V_2 , V_14 ,
V_15 | V_16 ,
L_1 ) ;
}
if ( V_4 ) {
for ( V_7 = 0 ; V_4 ; V_4 >>= 1 , V_7 ++ ) {
if ( V_4 & 1 )
F_3 ( V_2 , V_14 ,
V_15 ,
L_2 ,
V_17 [ V_7 ] ) ;
}
}
if ( V_3 ) {
for ( V_7 = 0 ; V_3 ; V_3 >>= 1 , V_7 ++ ) {
if ( V_3 & 1 )
F_3 ( V_2 , V_14 ,
V_15 ,
L_3 ,
V_18 [ V_7 ] ) ;
}
}
}
int F_4 ( struct V_1 * V_2 ,
struct V_19 * V_20 , int V_21 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
int V_7 ;
F_5 ( & V_23 -> V_29 ) ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return 0 ;
}
V_27 = F_8 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_27 ) , true , 0 ) ;
F_10 ( & V_27 -> V_30 , V_31 ,
V_32 , sizeof( * V_27 ) ) ;
V_27 -> V_33 = F_11 ( V_21 ) ;
for ( V_7 = 0 ; V_7 < V_21 ; V_7 ++ ) {
V_27 -> V_34 [ V_7 ] . V_35 = F_11 ( V_20 [ V_7 ] . V_35 ) ;
V_27 -> V_34 [ V_7 ] . V_36 = 0 ;
V_27 -> V_34 [ V_7 ] . V_37 =
F_11 ( V_20 [ V_7 ] . V_37 ) ;
}
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
return V_28 ;
}
unsigned int F_13 ( struct V_1 * V_2 ,
unsigned int V_38 ,
unsigned int V_39 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
struct V_40 * V_27 ;
unsigned int V_28 ;
F_3 ( V_2 , V_41 ,
V_15 | V_16 ,
L_4 ) ;
F_5 ( & V_23 -> V_29 ) ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return 0 ;
}
V_27 = F_8 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_27 ) , true , 0 ) ;
F_10 ( & V_27 -> V_30 , V_42 ,
V_43 ,
sizeof( struct V_44 ) ) ;
V_27 -> V_38 = V_38 ;
V_27 -> V_45 = V_39 ;
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
return V_28 ;
}
unsigned int F_14 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
struct V_46 * V_27 ;
unsigned int V_28 ;
F_3 ( V_2 , V_41 ,
V_15 | V_16 ,
L_4 ) ;
F_5 ( & V_23 -> V_29 ) ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return 0 ;
}
V_27 = F_8 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_27 ) , true , 0 ) ;
F_10 ( & V_27 -> V_30 , V_42 ,
V_47 ,
sizeof( struct V_48 ) ) ;
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
return V_28 ;
}
unsigned int F_15 ( struct V_1 * V_2 ,
T_3 V_49 ,
struct V_50 * V_51 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
unsigned int V_28 ;
struct V_52 * V_27 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
F_3 ( V_2 , V_41 ,
V_15 | V_16 ,
L_5 ) ;
F_5 ( & V_23 -> V_29 ) ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return 0 ;
}
V_51 -> V_57 = sizeof( * V_54 ) ;
V_27 = V_51 -> V_58 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_56 = F_16 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_27 ) , false , 1 ) ;
F_10 ( & V_27 -> V_30 , V_42 ,
V_59 ,
sizeof( * V_54 ) ) ;
V_27 -> V_45 = V_49 ;
V_56 -> V_60 = F_11 ( F_17 ( V_51 -> V_61 ) ) ;
V_56 -> V_62 = F_11 ( V_51 -> V_61 & 0xFFFFFFFF ) ;
V_56 -> V_63 = F_11 ( V_51 -> V_57 ) ;
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
return V_28 ;
}
int F_18 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
int V_64 = 0 ;
struct V_24 * V_25 ;
struct V_65 * V_66 ;
F_5 ( & V_23 -> V_29 ) ;
V_25 = F_19 ( & V_23 -> V_67 ) ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_66 = F_8 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_66 ) , true , 0 ) ;
F_10 ( & V_66 -> V_68 . V_69 , V_31 ,
V_70 ,
V_71 ) ;
V_64 = F_20 ( V_23 ) ;
V_2 -> V_72 = 0 ;
if ( ! V_64 ) {
V_2 -> V_72 = V_66 -> V_73 . V_54 . V_74 >>
( V_2 -> V_75 . V_76 * 8 ) & 0xff ;
} else {
F_3 ( V_2 , V_41 , V_77 ,
L_6 ,
V_64 , V_66 -> V_68 . V_78 . V_79 ) ;
}
if ( V_2 -> V_72 == 0 )
V_2 -> V_72 = '?' ;
F_7 ( & V_23 -> V_29 ) ;
return V_64 ;
}
int F_21 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 = F_19 ( & V_23 -> V_67 ) ;
struct V_80 * V_81 = F_8 ( V_25 ) ;
T_1 V_82 , V_83 ;
int V_79 = - V_84 ;
T_2 V_85 = 0 ;
F_5 ( & V_23 -> V_29 ) ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
F_9 ( V_25 , sizeof( * V_81 ) , true , 0 ) ;
F_10 ( & V_81 -> V_30 , V_31 ,
V_86 ,
V_71 ) ;
if ( F_20 ( V_23 ) ) {
F_3 ( V_2 , V_14 , V_77 ,
L_7 ) ;
goto V_87;
}
V_2 -> V_75 . V_76 = V_81 -> V_76 ;
if ( V_2 -> V_75 . V_76 >= V_88 ) {
F_3 ( V_2 , V_14 , V_77 ,
L_8 ,
V_2 -> V_75 . V_76 ) ;
goto V_87;
}
if ( ! F_22 ( V_2 ) ) {
V_2 -> V_75 . V_89 = V_81 -> V_89 ;
V_2 -> V_75 . V_90 = V_81 -> V_90 ;
if ( V_2 -> V_75 . V_89 == 0 ||
V_2 -> V_75 . V_89 > 2048 ) {
F_3 ( V_2 , V_14 , V_77 ,
L_9 ,
V_2 -> V_75 . V_89 ) ;
goto V_87;
}
if ( V_2 -> V_75 . V_90 == 0 ||
V_2 -> V_75 . V_90 > 4096 ) {
F_3 ( V_2 , V_14 , V_77 ,
L_10 ,
V_2 -> V_75 . V_90 ) ;
goto V_87;
}
F_3 ( V_2 , V_41 , V_77 ,
L_11 ,
V_2 -> V_75 . V_89 ,
V_2 -> V_75 . V_90 ) ;
}
for ( V_85 = 0 ; V_85 < V_91 ; V_85 ++ ) {
if ( V_81 -> V_92 [ V_85 ] . V_93 &
V_94 ) {
F_23 ( V_85 , & V_2 -> V_75 . V_95 ) ;
V_2 -> V_75 . V_96 [ V_85 ] =
V_81 -> V_92 [ V_85 ] . V_97 ;
V_2 -> V_75 . V_98 [ V_85 ] =
V_81 -> V_92 [ V_85 ] . V_99 ;
V_2 -> V_75 . V_100 [ V_85 ] =
V_81 -> V_92 [ V_85 ] . V_101 ;
V_2 -> V_75 . V_102 [ V_85 ] =
V_81 -> V_92 [ V_85 ] . V_83 ;
V_2 -> V_75 . V_103 [ V_85 ] =
V_81 -> V_104 [ V_85 ] . V_105 ;
V_2 -> V_75 . V_106 [ V_85 ] =
V_81 -> V_104 [ V_85 ] . V_107 ;
F_3 ( V_2 , V_41 , V_77 ,
L_12
L_13
L_14
L_15
L_16 ,
V_85 ,
V_2 -> V_75 .
V_98 [ V_85 ] ,
V_2 -> V_75 .
V_96 [ V_85 ] ,
V_2 -> V_75 .
V_102 [ V_85 ] ,
V_2 -> V_75 .
V_100 [ V_85 ] ) ;
}
}
if ( V_2 -> V_75 . V_95 == 0 ) {
F_3 ( V_2 , V_14 , V_77 ,
L_17 ,
V_81 -> V_92 [ V_108 ] . V_93 ,
V_81 -> V_92 [ V_109 ] . V_93 ) ;
goto V_87;
}
for ( V_85 = 0 ; V_85 < V_91 ; V_85 ++ )
if ( F_24 ( V_85 , & V_2 -> V_75 . V_95 ) )
break;
V_83 = V_2 -> V_75 . V_102 [ V_85 ] ;
if ( V_83 == 0 || V_83 > 65536 ) {
F_3 ( V_2 , V_14 , V_77 ,
L_18 , V_83 ) ;
goto V_87;
}
V_82 = F_25 ( V_2 , V_108 ) +
F_25 ( V_2 , V_109 ) ;
if ( V_82 == 0 || V_82 > 4096 ) {
F_3 ( V_2 , V_14 , V_77 ,
L_19 , V_82 ) ;
goto V_87;
}
V_2 -> V_75 . V_110 = ( V_81 -> V_111 &
V_112 ) ;
F_3 ( V_2 , V_41 , V_77 ,
L_20 ,
V_2 -> V_75 . V_110 ) ;
V_79 = 0 ;
V_87:
F_7 ( & V_23 -> V_29 ) ;
return V_79 ;
}
int F_26 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_50 V_51 ;
struct V_24 * V_25 = F_19 ( & V_23 -> V_67 ) ;
struct V_113 * V_27 ;
struct V_55 * V_56 = F_16 ( V_25 ) ;
int V_79 = 0 ;
V_51 . V_58 = F_27 ( V_23 -> V_114 ,
sizeof( struct V_113 ) ,
& V_51 . V_61 ) ;
if ( V_51 . V_58 == NULL ) {
F_3 ( V_2 , V_14 , V_77 ,
L_21
L_22 ) ;
return - V_115 ;
}
V_51 . V_57 = sizeof( struct V_113 ) ;
V_27 = V_51 . V_58 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
F_5 ( & V_23 -> V_29 ) ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
F_9 ( V_25 , sizeof( * V_27 ) , false , 1 ) ;
F_10 ( & V_27 -> V_30 , V_31 ,
V_116 , sizeof( * V_27 ) ) ;
V_56 -> V_60 = F_11 ( F_17 ( V_51 . V_61 ) ) ;
V_56 -> V_62 = F_11 ( V_51 . V_61 & 0xFFFFFFFF ) ;
V_56 -> V_63 = F_11 ( V_51 . V_57 ) ;
V_79 = F_20 ( V_23 ) ;
if ( ! V_79 ) {
struct V_117 * V_54 = V_51 . V_58 ;
F_3 ( V_2 , V_41 , V_77 ,
L_23
L_24
L_25 ,
V_54 -> V_118 . V_119
. V_120 ,
V_54 -> V_118 . V_119 .
V_121 ) ;
V_2 -> V_75 . V_122 =
V_54 -> V_118 . V_119 . V_122 ;
F_3 ( V_2 , V_41 , V_77 ,
L_26 ,
V_2 -> V_75 . V_122 ) ;
memcpy ( V_2 -> V_123 , V_54 -> V_118 . V_119 .
V_121 , V_124 ) ;
} else
F_3 ( V_2 , V_14 , V_77 ,
L_27 ) ;
F_7 ( & V_23 -> V_29 ) ;
if ( V_51 . V_58 )
F_28 ( V_23 -> V_114 , V_51 . V_57 ,
V_51 . V_58 , V_51 . V_61 ) ;
return V_79 ;
}
unsigned int F_29 ( struct V_22 * V_23 ,
struct V_1 * V_2 ,
struct V_125 * V_126 ,
struct V_50 * V_51 )
{
struct V_127 * V_54 ;
struct V_24 * V_25 ;
struct V_55 * V_128 ;
unsigned int V_28 = 0 ;
struct V_129 * V_130 = V_126 -> V_131 ;
struct V_132 * V_27 = V_51 -> V_58 ;
unsigned short V_133 , V_134 , V_135 , V_136 ;
V_51 -> V_57 = V_126 -> V_137 . V_138 ;
memset ( V_51 -> V_58 , 0 , V_51 -> V_57 ) ;
V_54 = V_51 -> V_58 ;
V_133 = V_130 -> V_139 . V_140 . V_141 [ 1 ] ;
V_134 = V_130 -> V_139 . V_140 . V_141 [ 2 ] ;
V_135 = V_130 -> V_139 . V_140 . V_141 [ 3 ] ;
V_136 = V_130 -> V_139 . V_140 . V_141 [ 4 ] ;
V_27 -> V_133 = V_133 ;
V_27 -> V_135 = V_135 ;
V_27 -> V_136 = V_136 ;
if ( F_30 ( & V_23 -> V_29 ) )
return 0 ;
switch ( V_130 -> V_139 . V_140 . V_141 [ 0 ] ) {
case V_142 :
V_136 = V_135 * V_134 + V_136 ;
F_10 ( & V_27 -> V_30 , V_143 ,
V_144 , sizeof( * V_27 ) ) ;
F_31 ( V_126 -> V_137 . V_145 ,
V_126 -> V_137 . V_146 ,
V_51 -> V_58 + V_136 , V_126 -> V_147 ) ;
break;
case V_148 :
F_10 ( & V_27 -> V_30 , V_143 ,
V_149 , sizeof( * V_27 ) ) ;
break;
default:
F_3 ( V_2 , V_150 , V_15 ,
L_28 ,
V_130 -> V_139 . V_140 . V_141 [ 0 ] ) ;
F_7 ( & V_23 -> V_29 ) ;
return - V_151 ;
}
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return 0 ;
}
V_128 = F_16 ( V_25 ) ;
F_9 ( V_25 , V_51 -> V_57 , false ,
V_126 -> V_137 . V_146 ) ;
V_128 -> V_60 = F_11 ( F_17 ( V_51 -> V_61 ) ) ;
V_128 -> V_62 = F_11 ( V_51 -> V_61 & 0xFFFFFFFF ) ;
V_128 -> V_63 = F_11 ( V_51 -> V_57 ) ;
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
return V_28 ;
}
int F_32 ( struct V_1 * V_2 , unsigned short V_85 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
struct V_152 * V_27 ;
unsigned int V_28 ;
int V_79 ;
F_5 ( & V_23 -> V_29 ) ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return - V_153 ;
}
V_27 = F_8 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_27 ) , true , 0 ) ;
F_10 ( & V_27 -> V_30 , V_143 ,
V_154 , sizeof( * V_27 ) ) ;
V_27 -> V_155 = ( 1 << V_85 ) ;
V_27 -> V_156 = F_33 ( F_34 ( V_2 , V_85 ) ) ;
V_27 -> V_157 = F_33 ( F_35 ( V_2 , V_85 ) ) ;
F_12 ( V_2 , V_28 ) ;
V_79 = F_36 ( V_2 , V_28 ) ;
if ( V_79 )
F_3 ( V_2 , V_150 , V_77 ,
L_29 ) ;
F_7 ( & V_23 -> V_29 ) ;
return V_79 ;
}
unsigned int F_37 ( struct V_1 * V_2 ,
struct V_158 * V_159 ,
unsigned int V_160 , unsigned int V_161 ,
struct V_50 * V_51 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
struct V_55 * V_56 ;
struct V_162 * V_27 ;
unsigned int V_7 , V_28 ;
F_5 ( & V_23 -> V_29 ) ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return 0 ;
}
V_27 = V_51 -> V_58 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_56 = F_16 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_27 ) , false , 1 ) ;
F_10 ( & V_27 -> V_30 , V_143 ,
V_163 ,
sizeof( * V_27 ) ) ;
V_27 -> V_164 = 0 ;
V_27 -> V_165 = V_166 ;
for ( V_7 = 0 ; V_7 < V_160 ; V_7 ++ ) {
V_27 -> V_167 [ V_7 ] . V_168 = V_159 -> V_168 ;
V_27 -> V_167 [ V_7 ] . V_161 = V_159 -> V_161 ;
V_27 -> V_83 ++ ;
V_159 ++ ;
}
V_56 -> V_60 = F_11 ( F_17 ( V_51 -> V_61 ) ) ;
V_56 -> V_62 = F_11 ( V_51 -> V_61 & 0xFFFFFFFF ) ;
V_56 -> V_63 = F_11 ( V_51 -> V_57 ) ;
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
return V_28 ;
}
unsigned int F_38 ( struct V_1 * V_2 ,
struct V_169 * V_170 ,
unsigned short V_161 ,
unsigned short V_171 ,
unsigned short V_172 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
struct V_173 * V_27 ;
unsigned int V_28 = 0 ;
F_5 ( & V_23 -> V_29 ) ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return 0 ;
}
V_27 = F_8 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_27 ) , true , 0 ) ;
F_10 ( & V_27 -> V_30 , V_42 ,
V_174 ,
sizeof( * V_27 ) ) ;
V_27 -> V_45 = V_170 -> V_175 ;
V_27 -> V_161 = V_161 ;
if ( V_171 )
V_27 -> V_165 = V_176 ;
else
V_27 -> V_165 = V_177 ;
V_27 -> V_178 = V_172 ;
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
return V_28 ;
}
unsigned int F_39 ( struct V_1 * V_2 ,
unsigned short V_161 , unsigned int V_179 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
struct V_180 * V_27 ;
unsigned int V_28 ;
F_5 ( & V_23 -> V_29 ) ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return 0 ;
}
V_27 = F_8 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_27 ) , true , 0 ) ;
F_10 ( & V_27 -> V_30 , V_181 ,
V_182 , sizeof( * V_27 ) ) ;
V_27 -> V_183 = ( unsigned short ) V_161 ;
V_27 -> V_184 = ( unsigned char ) V_179 ;
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
return V_28 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_185 * V_186 ,
struct V_169 * V_170 ,
struct V_50 * V_51 )
{
struct V_187 * V_188 ;
struct V_189 * V_190 ;
struct V_191 * V_192 = (struct V_191 * ) V_186 ;
struct V_193 * V_194 = (struct V_193 * ) V_186 ;
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
struct V_195 * V_27 ;
unsigned short V_196 ;
unsigned short V_197 ;
struct V_198 V_199 = { 0 , 0 } ;
struct V_198 * V_200 ;
unsigned int V_28 = 0 ;
unsigned int V_7 , V_85 ;
unsigned short V_161 = V_170 -> V_201 ;
struct V_55 * V_56 ;
if ( V_186 -> V_202 != V_203 && V_186 -> V_202 != V_204 ) {
F_3 ( V_2 , V_14 , V_15 ,
L_30 ,
V_186 -> V_202 ) ;
return - V_84 ;
}
V_188 = V_2 -> V_188 ;
V_190 = V_188 -> V_205 ;
V_85 = V_188 -> V_206 [ F_41 ( V_161 ) ] . V_85 ;
V_196 = ( unsigned short ) F_34 ( V_2 , V_85 ) ;
V_197 = ( unsigned short ) F_35 ( V_2 , V_85 ) ;
V_200 = & V_199 ;
F_42 ( V_2 , V_200 ) ;
if ( F_30 ( & V_23 -> V_29 ) )
return 0 ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return 0 ;
}
V_56 = F_16 ( V_25 ) ;
V_27 = V_51 -> V_58 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
F_9 ( V_25 , V_51 -> V_57 , false , 1 ) ;
F_10 ( & V_27 -> V_30 , V_143 ,
V_207 ,
V_51 -> V_57 ) ;
if ( V_186 -> V_202 == V_203 ) {
T_4 V_208 = V_192 -> V_209 . V_208 ;
V_27 -> V_210 . V_211 = V_212 ;
V_27 -> V_210 . V_213 [ 0 ] = V_208 & 0x000000ff ;
V_27 -> V_210 . V_213 [ 1 ] = ( V_208 & 0x0000ff00 ) >> 8 ;
V_27 -> V_210 . V_213 [ 2 ] = ( V_208 & 0x00ff0000 ) >> 16 ;
V_27 -> V_210 . V_213 [ 3 ] = ( V_208 & 0xff000000 ) >> 24 ;
V_27 -> V_214 = F_43 ( V_192 -> V_215 ) ;
V_170 -> V_186 = V_192 -> V_209 . V_208 ;
V_170 -> V_216 = F_43 ( V_192 -> V_215 ) ;
V_170 -> V_211 = V_212 ;
} else {
V_27 -> V_210 . V_211 = V_217 ;
memcpy ( & V_27 -> V_210 . V_213 ,
& V_194 -> V_218 . V_219 . V_220 , 16 ) ;
V_27 -> V_214 = F_43 ( V_194 -> V_221 ) ;
V_170 -> V_216 = F_43 ( V_194 -> V_221 ) ;
memcpy ( & V_170 -> V_222 ,
& V_194 -> V_218 . V_219 . V_220 , 16 ) ;
V_170 -> V_211 = V_217 ;
}
V_27 -> V_161 = V_161 ;
V_7 = V_2 -> V_223 ++ ;
if ( V_2 -> V_223 == V_2 -> V_224 )
V_2 -> V_223 = 0 ;
V_27 -> V_225 = V_190 -> V_226 [ V_7 ] . V_183 ;
F_3 ( V_2 , V_41 , V_15 ,
L_31 , V_7 , V_27 -> V_225 ) ;
V_27 -> V_227 = V_196 ;
V_27 -> V_156 = V_196 ;
V_27 -> V_157 = V_197 ;
V_27 -> V_228 = 1 ;
V_27 -> V_229 . V_230 = V_200 -> V_230 ;
V_27 -> V_229 . V_231 = V_200 -> V_231 ;
V_56 -> V_60 = F_11 ( F_17 ( V_51 -> V_61 ) ) ;
V_56 -> V_62 = F_11 ( V_51 -> V_61 & 0xFFFFFFFF ) ;
V_56 -> V_63 = F_11 ( V_51 -> V_57 ) ;
if ( ! F_22 ( V_2 ) ) {
V_27 -> V_30 . V_232 = V_233 ;
V_27 -> V_234 = 0 ;
V_27 -> V_235 = 2 ;
}
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
return V_28 ;
}
unsigned int F_44 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
struct V_236 * V_27 ;
struct V_236 * V_237 ;
unsigned int V_28 ;
int V_79 = 0 ;
if ( F_30 ( & V_23 -> V_29 ) )
return - V_238 ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return - V_115 ;
}
V_27 = F_8 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_27 ) , true , 0 ) ;
F_10 ( & V_27 -> V_30 , V_143 ,
V_239 ,
sizeof( * V_27 ) ) ;
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
V_79 = F_45 ( V_2 , V_28 , & V_25 , NULL ) ;
if ( V_79 ) {
F_3 ( V_2 , V_150 , V_15 ,
L_32 ) ;
return - V_153 ;
}
V_237 = F_8 ( V_25 ) ;
V_2 -> V_240 = V_237 -> V_241 [ 0 ] ;
return V_79 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_50 * V_51 , void * V_242 ,
int V_243 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
struct V_55 * V_56 ;
unsigned int V_28 ;
int V_244 = 0 ;
F_5 ( & V_23 -> V_29 ) ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
V_244 = - V_115 ;
goto V_245;
}
V_56 = F_16 ( V_25 ) ;
F_9 ( V_25 , V_51 -> V_57 , false , 1 ) ;
V_56 -> V_60 = F_11 ( F_17 ( V_51 -> V_61 ) ) ;
V_56 -> V_62 = F_11 ( F_47 ( V_51 -> V_61 ) ) ;
V_56 -> V_63 = F_11 ( V_51 -> V_57 ) ;
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
V_244 = F_45 ( V_2 , V_28 , NULL , V_51 ) ;
if ( V_242 )
memcpy ( V_242 , V_51 -> V_58 , V_243 ) ;
if ( V_244 ) {
if ( V_244 == - V_246 )
return V_244 ;
F_3 ( V_2 , V_150 ,
V_15 | V_16 ,
L_33 ) ;
if ( V_244 != - V_153 )
goto V_245;
else
return V_244 ;
}
V_245:
F_28 ( V_23 -> V_114 , V_51 -> V_57 ,
V_51 -> V_58 , V_51 -> V_61 ) ;
return V_244 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_50 * V_247 ,
int V_248 , int V_57 )
{
V_247 -> V_58 = F_49 ( V_2 -> V_23 . V_114 , V_57 , & V_247 -> V_61 ) ;
if ( ! V_247 -> V_58 ) {
F_3 ( V_2 , V_14 , V_15 ,
L_34 ) ;
return - V_115 ;
}
V_247 -> V_57 = V_57 ;
F_10 ( V_247 -> V_58 , V_143 , V_248 , V_57 ) ;
return 0 ;
}
static int
F_50 ( struct V_1 * V_2 ,
struct V_249 * V_250 ,
struct V_251 * V_252 ,
struct V_251 * V_253 ,
T_1 V_254 )
{
struct V_255 * V_27 ;
struct V_50 V_51 ;
T_1 V_211 ;
int V_244 ;
V_244 = F_48 ( V_2 , & V_51 ,
V_256 ,
sizeof( * V_27 ) ) ;
if ( V_244 )
return V_244 ;
V_211 = ( V_252 -> V_257 == V_258 ) ?
V_217 : V_212 ;
V_27 = V_51 . V_58 ;
V_27 -> V_259 . V_260 = 1 ;
V_27 -> V_259 . V_261 . V_262 = V_254 ;
V_27 -> V_259 . V_261 . V_263 =
V_2 -> V_240 ;
V_27 -> V_259 . V_261 . V_264 . V_265 =
sizeof( struct V_266 ) ;
V_27 -> V_259 . V_261 . V_264 . V_211 = V_211 ;
if ( V_254 == V_267 ) {
memcpy ( V_27 -> V_259 . V_261 . V_264 . V_213 , V_252 -> V_268 ,
sizeof( V_27 -> V_259 . V_261 . V_264 . V_213 ) ) ;
if ( V_253 )
memcpy ( V_27 -> V_259 . V_261 . V_264 . V_269 ,
V_253 -> V_268 ,
sizeof( V_27 -> V_259 . V_261 . V_264 . V_269 ) ) ;
} else {
memcpy ( V_27 -> V_259 . V_261 . V_264 . V_213 ,
V_250 -> V_264 . V_213 ,
sizeof( V_27 -> V_259 . V_261 . V_264 . V_213 ) ) ;
memcpy ( V_27 -> V_259 . V_261 . V_264 . V_269 ,
V_250 -> V_264 . V_269 ,
sizeof( V_27 -> V_259 . V_261 . V_264 . V_269 ) ) ;
}
V_244 = F_46 ( V_2 , & V_51 , NULL , 0 ) ;
if ( V_244 < 0 )
F_3 ( V_2 , V_150 , V_15 ,
L_35 ) ;
return V_244 ;
}
static int F_51 ( struct V_1 * V_2 , T_2 * V_270 ,
T_1 V_271 , T_1 V_272 )
{
struct V_273 * V_27 ;
struct V_50 V_51 ;
int V_274 ;
V_274 = F_48 ( V_2 , & V_51 ,
V_275 ,
sizeof( * V_27 ) ) ;
if ( V_274 )
return V_274 ;
V_27 = V_51 . V_58 ;
V_27 -> V_262 = V_271 ;
V_27 -> V_264 . V_211 = V_212 ;
memcpy ( V_27 -> V_264 . V_213 , V_270 , sizeof( V_27 -> V_264 . V_213 ) ) ;
return F_46 ( V_2 , & V_51 , NULL , 0 ) ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_251 * V_252 ,
struct V_251 * V_253 ,
T_1 V_276 )
{
struct V_277 V_278 ;
struct V_249 * V_250 ;
struct V_279 * V_280 ;
struct V_281 * V_282 ;
struct V_50 V_51 ;
T_2 * V_283 ;
T_1 V_211 ;
int V_244 ;
V_244 = F_44 ( V_2 ) ;
if ( V_244 )
return V_244 ;
V_211 = ( V_252 -> V_257 == V_258 ) ?
V_217 : V_212 ;
V_244 = F_53 ( V_2 , V_211 , & V_250 ) ;
if ( V_244 )
return V_244 ;
if ( V_276 == V_284 ) {
if ( V_250 -> V_285 ) {
F_3 ( V_2 , V_150 , V_15 ,
L_36 ) ;
goto exit;
}
V_252 -> V_63 = ( V_252 -> V_257 == V_258 ) ?
V_286 : V_287 ;
} else {
if ( V_250 -> V_285 ) {
memset ( V_250 , 0 , sizeof( * V_250 ) ) ;
V_244 = F_48 ( V_2 , & V_51 ,
V_288 ,
sizeof( * V_282 ) ) ;
if ( V_244 )
goto exit;
V_282 = V_51 . V_58 ;
V_282 -> V_263 = V_2 -> V_240 ;
V_282 -> V_211 = V_211 ;
V_244 = F_46 ( V_2 , & V_51 , NULL , 0 ) ;
if ( V_244 < 0 ) {
F_3 ( V_2 , V_150 ,
V_15 ,
L_37 ) ;
goto exit;
}
}
}
if ( V_250 -> V_264 . V_213 [ 0 ] ) {
V_244 = F_50 ( V_2 , V_250 , V_252 , NULL ,
V_289 ) ;
if ( V_244 )
goto exit;
}
if ( V_276 == V_284 ) {
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_244 = F_54 ( V_2 , V_212 , & V_278 ) ;
if ( V_244 ) {
F_3 ( V_2 , V_150 , V_15 ,
L_38 ) ;
goto exit;
}
if ( V_278 . V_264 . V_213 [ 0 ] ) {
V_283 = ( T_2 * ) & V_278 . V_264 . V_213 ;
V_244 = F_51 ( V_2 , V_283 ,
V_289 , V_287 ) ;
if ( V_244 ) {
F_3 ( V_2 , V_150 ,
V_15 ,
L_39 ) ;
goto exit;
}
}
}
if ( V_276 == V_284 ) {
V_244 = F_48 ( V_2 , & V_51 ,
V_290 ,
sizeof( * V_280 ) ) ;
if ( V_244 )
goto exit;
V_280 = V_51 . V_58 ;
V_280 -> V_291 = V_292 ;
V_280 -> V_293 = 1 ;
V_280 -> V_263 = V_2 -> V_240 ;
V_280 -> V_211 = V_294 ;
V_244 = F_46 ( V_2 , & V_51 , NULL , 0 ) ;
} else {
V_244 = F_50 ( V_2 , V_250 , V_252 ,
V_253 , V_267 ) ;
}
exit:
F_55 ( V_250 ) ;
return V_244 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_251 * V_295 )
{
struct V_277 V_278 ;
T_2 * V_283 ;
int V_274 ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_274 = F_54 ( V_2 , V_212 , & V_278 ) ;
if ( V_274 ) {
F_3 ( V_2 , V_150 , V_15 ,
L_38 ) ;
return V_274 ;
}
if ( V_278 . V_264 . V_213 [ 0 ] ) {
V_283 = ( T_2 * ) & V_278 . V_264 . V_213 ;
V_274 = F_51 ( V_2 , V_283 , V_289 ,
V_295 -> V_63 ) ;
if ( V_274 ) {
F_3 ( V_2 , V_150 , V_15 ,
L_39 ) ;
return V_274 ;
}
}
V_283 = ( T_2 * ) & V_295 -> V_268 ;
V_274 = F_51 ( V_2 , V_283 , V_267 ,
V_295 -> V_63 ) ;
if ( V_274 )
F_3 ( V_2 , V_150 , V_15 ,
L_40 ) ;
return V_274 ;
}
int F_54 ( struct V_1 * V_2 , int V_211 ,
struct V_277 * V_296 )
{
struct V_297 * V_27 ;
struct V_50 V_51 ;
int V_244 ;
V_244 = F_48 ( V_2 , & V_51 ,
V_298 ,
sizeof( * V_296 ) ) ;
if ( V_244 )
return V_244 ;
V_27 = V_51 . V_58 ;
V_27 -> V_211 = V_211 ;
return F_46 ( V_2 , & V_51 , V_296 ,
sizeof( * V_296 ) ) ;
}
int F_53 ( struct V_1 * V_2 , int V_211 ,
struct V_249 * * V_250 )
{
struct V_299 * V_27 ;
struct V_50 V_51 ;
T_1 V_300 = sizeof( struct V_249 ) ;
int V_244 ;
V_244 = F_44 ( V_2 ) ;
if ( V_244 )
return V_244 ;
do {
V_244 = F_48 ( V_2 , & V_51 ,
V_301 ,
V_300 ) ;
if ( V_244 )
return V_244 ;
V_27 = V_51 . V_58 ;
V_27 -> V_263 = V_2 -> V_240 ;
V_27 -> V_211 = V_211 ;
* V_250 = F_57 ( V_300 , V_302 ) ;
if ( ! * V_250 ) {
F_3 ( V_2 , V_14 ,
V_77 | V_15 ,
L_41 ) ;
F_28 ( V_2 -> V_23 . V_114 ,
V_51 . V_57 ,
V_51 . V_58 ,
V_51 . V_61 ) ;
return - V_115 ;
}
V_244 = F_46 ( V_2 , & V_51 , * V_250 ,
V_300 ) ;
if ( V_244 == - V_246 ) {
V_300 = ( (struct V_127 * )
V_51 . V_58 ) -> V_303 ;
V_300 += sizeof( struct V_304 ) ;
F_28 ( V_2 -> V_23 . V_114 , V_51 . V_57 ,
V_51 . V_58 ,
V_51 . V_61 ) ;
F_55 ( * V_250 ) ;
} else
break;
} while ( true );
return V_244 ;
}
int F_58 ( struct V_1 * V_2 ,
struct V_305 * V_306 )
{
struct V_50 V_51 ;
int V_244 ;
V_244 = F_48 ( V_2 , & V_51 ,
V_307 ,
sizeof( * V_306 ) ) ;
if ( V_244 )
return V_244 ;
return F_46 ( V_2 , & V_51 , V_306 , sizeof( * V_306 ) ) ;
}
unsigned int F_59 ( struct V_1 * V_2 )
{
unsigned int V_28 ;
struct V_24 * V_25 ;
struct V_308 * V_27 ;
struct V_22 * V_23 = & V_2 -> V_23 ;
if ( F_30 ( & V_23 -> V_29 ) )
return 0 ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
return 0 ;
}
V_27 = F_8 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_27 ) , true , 0 ) ;
F_10 ( & V_27 -> V_30 , V_42 ,
V_309 ,
sizeof( * V_27 ) ) ;
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
return V_28 ;
}
int F_60 ( struct V_1 * V_2 ,
unsigned int * V_310 )
{
struct V_48 * V_311 ;
struct V_24 * V_25 ;
unsigned int V_28 ;
T_2 V_312 = 3 ;
int V_244 ;
do {
V_28 = F_14 ( V_2 ) ;
if ( ! V_28 ) {
F_3 ( V_2 , V_14 ,
V_15 | V_77 ,
L_42 ) ;
return - V_246 ;
}
V_244 = F_45 ( V_2 , V_28 , & V_25 , NULL ) ;
if ( V_244 ) {
F_3 ( V_2 , V_14 ,
V_77 | V_15 ,
L_43 ) ;
return - V_153 ;
}
V_311 = F_8 ( V_25 ) ;
if ( ! V_311 -> V_313 ) {
F_3 ( V_2 , V_41 ,
V_77 | V_15 ,
L_44 ) ;
return - V_314 ;
}
if ( V_311 -> V_49 != V_315 ) {
* V_310 = V_311 -> V_49 ;
return 0 ;
}
V_28 = F_13 ( V_2 , V_316 ,
V_315 ) ;
if ( ! V_28 ) {
F_3 ( V_2 , V_14 ,
V_77 | V_15 ,
L_45 ) ;
return - V_246 ;
}
V_244 = F_45 ( V_2 , V_28 , NULL , NULL ) ;
if ( V_244 ) {
F_3 ( V_2 , V_14 ,
V_77 | V_15 ,
L_46 ) ;
return V_244 ;
}
} while ( -- V_312 );
F_3 ( V_2 , V_14 ,
V_77 | V_15 ,
L_47 ) ;
return - V_314 ;
}
int F_61 ( struct V_1 * V_2 ,
T_5 V_317 )
{
int V_244 ;
unsigned int V_28 ;
V_28 = F_62 ( V_2 , V_317 ) ;
if ( ! V_28 ) {
F_3 ( V_2 , V_14 ,
( V_15 | V_16 ) ,
L_48 ) ;
return - V_153 ;
}
V_244 = F_45 ( V_2 , V_28 , NULL , NULL ) ;
if ( V_244 ) {
F_3 ( V_2 , V_14 ,
( V_15 | V_16 ) ,
L_49 ) ;
return V_244 ;
}
return V_244 ;
}
T_6
F_63 ( struct V_318 * V_319 , struct V_320 * V_321 ,
char * V_322 )
{
return snprintf ( V_322 , V_323 , V_324 L_50 ) ;
}
T_6
F_64 ( struct V_318 * V_319 , struct V_320 * V_321 ,
char * V_322 )
{
struct V_325 * V_326 = F_65 ( V_319 ) ;
struct V_1 * V_2 = F_66 ( V_326 ) ;
return snprintf ( V_322 , V_323 , L_51 , V_2 -> V_123 ) ;
}
T_6
F_67 ( struct V_318 * V_319 , struct V_320 * V_321 ,
char * V_322 )
{
struct V_325 * V_326 = F_65 ( V_319 ) ;
struct V_1 * V_2 = F_66 ( V_326 ) ;
T_5 V_327 = 0 , V_85 , V_63 = 0 , V_328 = 0 ;
for ( V_85 = 0 ; V_85 < V_91 ; V_85 ++ ) {
if ( F_24 ( V_85 , ( void * ) & V_2 -> V_75 . V_95 ) ) {
V_327 = F_68 ( V_2 , V_85 ) ;
V_328 = F_25 ( V_2 , V_85 ) ;
V_63 += snprintf ( V_322 + V_63 , V_323 - V_63 ,
L_52 , V_85 ,
( V_328 - V_327 ) ) ;
} else
V_63 += snprintf ( V_322 + V_63 , V_323 - V_63 ,
L_52 , V_85 , 0 ) ;
}
return V_63 ;
}
T_6
F_69 ( struct V_318 * V_319 , struct V_320 * V_321 ,
char * V_322 )
{
struct V_325 * V_326 = F_65 ( V_319 ) ;
struct V_1 * V_2 = F_66 ( V_326 ) ;
T_5 V_85 , V_63 = 0 ;
for ( V_85 = 0 ; V_85 < V_91 ; V_85 ++ ) {
if ( F_24 ( V_85 , ( void * ) & V_2 -> V_75 . V_95 ) )
V_63 += snprintf ( V_322 + V_63 , V_323 - V_63 ,
L_52 , V_85 ,
F_68 ( V_2 , V_85 ) ) ;
else
V_63 += snprintf ( V_322 + V_63 , V_323 - V_63 ,
L_52 , V_85 , 0 ) ;
}
return V_63 ;
}
T_6
F_70 ( struct V_318 * V_319 , struct V_320 * V_321 ,
char * V_322 )
{
T_5 V_329 = 0 ;
struct V_325 * V_326 = F_65 ( V_319 ) ;
struct V_1 * V_2 = F_66 ( V_326 ) ;
V_329 = V_2 -> V_9 -> V_318 ;
switch ( V_329 ) {
case V_330 :
case V_331 :
case V_332 :
return snprintf ( V_322 , V_323 , L_53 ) ;
break;
case V_333 :
case V_334 :
return snprintf ( V_322 , V_323 , L_54 ) ;
break;
case V_335 :
return snprintf ( V_322 , V_323 , L_55 ) ;
break;
default:
return snprintf ( V_322 , V_323 ,
L_56 , V_329 ) ;
break;
}
}
T_6
F_71 ( struct V_318 * V_319 , struct V_320 * V_321 ,
char * V_322 )
{
struct V_325 * V_326 = F_65 ( V_319 ) ;
struct V_1 * V_2 = F_66 ( V_326 ) ;
return snprintf ( V_322 , V_323 , L_57 ,
V_2 -> V_75 . V_76 ) ;
}
void F_72 ( struct V_336 * V_118 ,
struct V_337 * V_338 ,
struct V_339 * V_340 ,
struct V_341 * V_342 )
{
struct V_343 * V_344 = V_338 -> V_344 ;
memset ( V_344 , 0 , sizeof( * V_344 ) ) ;
F_73 ( struct V_345 ,
V_346 , V_344 ,
V_118 -> V_347 [ F_74 ( struct V_348 ,
V_346 ) / 32 ] ) ;
F_73 ( struct V_345 , type , V_344 ,
V_349 ) ;
F_73 ( struct V_345 ,
V_350 ,
V_344 ,
V_118 -> V_347 [ F_74 ( struct V_348 ,
V_350 ) / 32 ] ) ;
F_73 ( struct V_345 , V_351 , V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_351 ) / 32 ] & V_352 ) ) ;
F_73 ( struct V_345 , V_353 , V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_353 ) / 32 ] & V_354 ) >> 2 ) ;
F_73 ( struct V_345 , V_355 , V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_355 ) / 32 ] & V_356 ) >> 3 ) ;
F_73 ( struct V_345 , V_357 , V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_357 ) / 32 ] & V_358 ) >> 4 ) ;
F_73 ( struct V_345 , V_359 , V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_359 ) / 32 ] & V_360 ) >> 5 ) ;
F_73 ( struct V_345 , V_361 ,
V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_362 ) / 32 ] + 1 ) ) ;
F_73 ( struct V_345 , V_363 ,
V_344 , V_338 -> V_364 ) ;
F_73 ( struct V_345 ,
V_365 , V_344 , V_118 -> V_347 [ F_74
( struct V_348 ,
V_365 ) / 32 ] ) ;
F_73 ( struct V_345 , V_366 ,
V_344 , V_338 -> V_364 ) ;
if ( V_342 -> V_367 )
F_73 ( struct V_345 ,
V_366 ,
V_342 -> V_367 ,
V_338 -> V_364 ) ;
V_342 -> V_367 = V_344 ;
F_73 ( struct V_345 ,
V_368 , V_344 , 0 ) ;
F_73 ( struct V_345 , V_369 ,
V_344 , 1 ) ;
F_73 ( struct V_345 , V_370 ,
V_344 , 0 ) ;
F_73 ( struct V_345 , V_371 , V_344 ,
0 ) ;
V_340 += V_372 ;
F_73 ( struct V_345 ,
V_373 , V_344 ,
V_340 -> V_374 [ 0 ] . V_375 . V_376 . V_377 . V_378 ) ;
F_73 ( struct V_345 ,
V_379 , V_344 ,
V_340 -> V_374 [ 0 ] . V_375 . V_376 . V_377 . V_380 ) ;
}
void F_75 ( struct V_336 * V_118 ,
struct V_337 * V_338 ,
struct V_341 * V_342 )
{
struct V_343 * V_344 = V_338 -> V_344 ;
memset ( V_344 , 0 , sizeof( * V_344 ) ) ;
F_73 ( struct V_381 ,
V_365 , V_344 , V_118 -> V_347 [ F_74
( struct V_348 ,
V_365 ) / 32 ] ) ;
F_73 ( struct V_381 ,
type , V_344 ,
V_349 ) ;
F_73 ( struct V_381 ,
V_366 ,
V_344 , V_338 -> V_364 ) ;
if ( V_342 -> V_367 )
F_73 ( struct V_381 ,
V_366 ,
V_342 -> V_367 ,
V_338 -> V_364 ) ;
V_342 -> V_367 = V_344 ;
F_73 ( struct V_381 , V_363 ,
V_344 , V_338 -> V_364 ) ;
F_73 ( struct V_381 ,
V_346 , V_344 ,
V_118 -> V_347 [ F_74 ( struct V_348 ,
V_346 ) / 32 ] ) ;
F_73 ( struct V_381 ,
V_350 , V_344 ,
V_118 -> V_347 [ F_74 ( struct V_348 ,
V_350 ) / 32 ] ) ;
F_73 ( struct V_381 ,
V_382 , V_344 ,
V_118 -> V_347 [ F_74 ( struct V_348 ,
V_383 ) / 32 ] ) ;
F_73 ( struct V_381 ,
V_384 , V_344 , V_385 ) ;
F_73 ( struct V_381 , V_351 , V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_351 ) / 32 ] & V_352 ) ) ;
F_73 ( struct V_381 , V_353 , V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_353 ) / 32 ] & V_354 ) >> 2 ) ;
F_73 ( struct V_381 , V_355 , V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_355 ) / 32 ] & V_356 ) >> 3 ) ;
F_73 ( struct V_381 ,
V_357 , V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_357 ) / 32 ] & V_358 ) >> 4 ) ;
F_73 ( struct V_381 , V_359 , V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_359 ) / 32 ] & V_360 ) >> 5 ) ;
F_73 ( struct V_381 ,
V_386 ,
V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_386 ) / 32 ] &
V_387 ) >> 6 ) ;
F_73 ( struct V_381 ,
V_388 ,
V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_388 ) / 32 ] &
V_389 ) >> 7 ) ;
F_73 ( struct V_381 , V_390 ,
V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_390 ) / 32 ] &
V_391 ) >> 8 ) ;
F_73 ( struct V_381 , V_361 ,
V_344 ,
( V_118 -> V_347 [ F_74 ( struct V_348 ,
V_362 ) / 32 ] + 1 ) ) ;
}
int F_76 ( struct V_1 * V_2 ,
T_1 V_392 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_24 * V_25 ;
struct V_393 * V_27 ;
struct V_394 * V_54 ;
unsigned int V_28 ;
int V_244 ;
F_3 ( V_2 , V_41 ,
V_15 | V_16 ,
L_58 ) ;
F_5 ( & V_23 -> V_29 ) ;
V_25 = F_6 ( V_2 , & V_28 ) ;
if ( ! V_25 ) {
F_7 ( & V_23 -> V_29 ) ;
F_3 ( V_2 , V_41 ,
V_15 | V_16 ,
L_59 ) ;
return - V_84 ;
}
V_27 = F_8 ( V_25 ) ;
F_9 ( V_25 , sizeof( * V_27 ) , true , 0 ) ;
F_10 ( & V_27 -> V_30 , V_42 ,
V_395 ,
sizeof( struct V_393 ) ) ;
V_27 -> V_45 = V_392 ;
F_12 ( V_2 , V_28 ) ;
F_7 ( & V_23 -> V_29 ) ;
V_244 = F_45 ( V_2 , V_28 , & V_25 , NULL ) ;
if ( V_244 ) {
F_3 ( V_2 , V_14 ,
V_77 | V_15 ,
L_60 ) ;
return - V_153 ;
}
V_54 = F_8 ( V_25 ) ;
if ( V_54 -> V_396 !=
V_397 ) {
F_3 ( V_2 , V_14 ,
V_77 | V_15 ,
L_61 ,
V_54 -> V_396 ) ;
V_244 = - V_84 ;
}
return V_244 ;
}
