int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
unsigned int V_12 ;
int V_13 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_16 ,
V_17 , sizeof( * V_11 ) ) ;
V_11 -> V_18 = F_8 ( V_5 ) ;
for ( V_13 = 0 ; V_13 < V_5 ; V_13 ++ ) {
V_11 -> V_19 [ V_13 ] . V_20 = F_8 ( V_4 [ V_13 ] . V_20 ) ;
V_11 -> V_19 [ V_13 ] . V_21 = 0 ;
V_11 -> V_19 [ V_13 ] . V_22 =
F_8 ( V_4 [ V_13 ] . V_22 ) ;
}
F_9 ( V_23 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_11 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_8 * V_9 ;
struct V_30 * V_31 ;
unsigned int V_12 = 0 ;
struct V_32 * V_33 = V_27 -> V_34 ;
struct V_35 * V_11 = V_29 -> V_36 ;
unsigned short V_37 , V_38 , V_39 , V_40 ;
V_29 -> V_41 = V_27 -> V_42 . V_43 ;
memset ( V_29 -> V_36 , 0 , V_29 -> V_41 ) ;
V_37 = V_33 -> V_44 . V_45 . V_46 [ 1 ] ;
V_38 = V_33 -> V_44 . V_45 . V_46 [ 2 ] ;
V_39 = V_33 -> V_44 . V_45 . V_46 [ 3 ] ;
V_40 = V_33 -> V_44 . V_45 . V_46 [ 4 ] ;
V_11 -> V_37 = V_37 ;
V_11 -> V_39 = V_39 ;
V_11 -> V_40 = V_40 ;
if ( F_12 ( & V_7 -> V_14 ) )
return 0 ;
switch ( V_33 -> V_44 . V_45 . V_46 [ 0 ] ) {
case V_47 :
V_40 = V_39 * V_38 + V_40 ;
F_7 ( & V_11 -> V_15 , V_48 ,
V_49 , sizeof( * V_11 ) ) ;
F_13 ( V_27 -> V_42 . V_50 ,
V_27 -> V_42 . V_51 ,
V_29 -> V_36 + V_40 , V_27 -> V_52 ) ;
break;
case V_53 :
F_7 ( & V_11 -> V_15 , V_48 ,
V_54 , sizeof( * V_11 ) ) ;
break;
default:
F_14 ( V_2 , V_55 , V_56 ,
L_1 ,
V_33 -> V_44 . V_45 . V_46 [ 0 ] ) ;
F_4 ( & V_7 -> V_14 ) ;
return - V_57 ;
}
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_31 = F_15 ( V_9 ) ;
F_6 ( V_9 , V_29 -> V_41 , false ,
V_27 -> V_42 . V_51 ) ;
V_31 -> V_58 = F_8 ( F_16 ( V_29 -> V_59 ) ) ;
V_31 -> V_60 = F_8 ( V_29 -> V_59 & 0xFFFFFFFF ) ;
V_31 -> V_61 = F_8 ( V_29 -> V_41 ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
struct V_64 * V_65 ,
struct V_28 * V_29 )
{
struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 = (struct V_70 * ) V_63 ;
struct V_72 * V_73 = (struct V_72 * ) V_63 ;
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_74 * V_11 ;
unsigned short V_75 ;
unsigned short V_76 ;
struct V_77 V_78 = { 0 , 0 } ;
struct V_77 * V_79 ;
unsigned int V_12 = 0 ;
unsigned int V_13 , V_80 ;
unsigned short V_81 = V_65 -> V_82 ;
struct V_30 * V_83 ;
if ( V_63 -> V_84 != V_85 && V_63 -> V_84 != V_86 ) {
F_14 ( V_2 , V_87 , V_56 ,
L_2 ,
V_63 -> V_84 ) ;
return - V_88 ;
}
V_67 = V_2 -> V_67 ;
V_69 = V_67 -> V_89 ;
V_80 = V_67 -> V_90 [ F_18 ( V_81 ) ] . V_80 ;
V_75 = ( unsigned short ) F_19 ( V_2 , V_80 ) ;
V_76 = ( unsigned short ) F_20 ( V_2 , V_80 ) ;
V_79 = & V_78 ;
F_21 ( V_2 , V_79 ) ;
if ( F_12 ( & V_7 -> V_14 ) )
return 0 ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_83 = F_15 ( V_9 ) ;
V_11 = V_29 -> V_36 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_6 ( V_9 , V_29 -> V_41 , false , 1 ) ;
F_7 ( & V_11 -> V_15 , V_48 ,
V_91 ,
V_29 -> V_41 ) ;
if ( V_63 -> V_84 == V_85 ) {
T_1 V_92 = V_71 -> V_93 . V_92 ;
V_11 -> V_94 . V_95 = V_96 ;
V_11 -> V_94 . V_97 [ 0 ] = V_92 & 0x000000ff ;
V_11 -> V_94 . V_97 [ 1 ] = ( V_92 & 0x0000ff00 ) >> 8 ;
V_11 -> V_94 . V_97 [ 2 ] = ( V_92 & 0x00ff0000 ) >> 16 ;
V_11 -> V_94 . V_97 [ 3 ] = ( V_92 & 0xff000000 ) >> 24 ;
V_11 -> V_98 = F_22 ( V_71 -> V_99 ) ;
V_65 -> V_63 = V_71 -> V_93 . V_92 ;
V_65 -> V_100 = F_22 ( V_71 -> V_99 ) ;
V_65 -> V_95 = V_96 ;
} else {
V_11 -> V_94 . V_95 = V_101 ;
memcpy ( & V_11 -> V_94 . V_97 ,
& V_73 -> V_102 . V_103 . V_104 , 16 ) ;
V_11 -> V_98 = F_22 ( V_73 -> V_105 ) ;
V_65 -> V_100 = F_22 ( V_73 -> V_105 ) ;
memcpy ( & V_65 -> V_106 ,
& V_73 -> V_102 . V_103 . V_104 , 16 ) ;
V_65 -> V_95 = V_101 ;
}
V_11 -> V_81 = V_81 ;
V_13 = V_2 -> V_107 ++ ;
if ( V_2 -> V_107 == V_2 -> V_108 )
V_2 -> V_107 = 0 ;
V_11 -> V_109 = V_69 -> V_110 [ V_13 ] . V_111 ;
F_14 ( V_2 , V_112 , V_56 ,
L_3 , V_13 , V_11 -> V_109 ) ;
V_11 -> V_113 = V_75 ;
V_11 -> V_114 = V_75 ;
V_11 -> V_115 = V_76 ;
V_11 -> V_116 = 1 ;
V_11 -> V_117 . V_118 = V_79 -> V_118 ;
V_11 -> V_117 . V_119 = V_79 -> V_119 ;
V_83 -> V_58 = F_8 ( F_16 ( V_29 -> V_59 ) ) ;
V_83 -> V_60 = F_8 ( V_29 -> V_59 & 0xFFFFFFFF ) ;
V_83 -> V_61 = F_8 ( V_29 -> V_41 ) ;
if ( ! F_23 ( V_2 ) ) {
V_11 -> V_15 . V_120 = V_121 ;
V_11 -> V_122 = 0x8000 ;
V_11 -> V_123 = 2 ;
}
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_28 * V_29 , void * V_124 ,
int V_125 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_30 * V_83 ;
unsigned int V_12 ;
int V_126 = 0 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
V_126 = - V_127 ;
goto V_128;
}
V_83 = F_15 ( V_9 ) ;
F_6 ( V_9 , V_29 -> V_41 , false , 1 ) ;
V_83 -> V_58 = F_8 ( F_16 ( V_29 -> V_59 ) ) ;
V_83 -> V_60 = F_8 ( F_25 ( V_29 -> V_59 ) ) ;
V_83 -> V_61 = F_8 ( V_29 -> V_41 ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
V_126 = F_26 ( V_2 , V_12 , NULL , V_29 ) ;
if ( V_124 )
memcpy ( V_124 , V_29 -> V_36 , V_125 ) ;
if ( V_126 ) {
if ( V_126 == - V_129 )
return V_126 ;
F_14 ( V_2 , V_55 ,
V_56 | V_130 ,
L_4 ) ;
if ( V_126 != - V_131 )
goto V_128;
else
return V_126 ;
}
V_128:
F_27 ( V_7 -> V_132 , V_29 -> V_41 ,
V_29 -> V_36 , V_29 -> V_59 ) ;
return V_126 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_28 * V_133 ,
int V_134 , int V_41 )
{
V_133 -> V_36 = F_29 ( V_2 -> V_7 . V_132 , V_41 , & V_133 -> V_59 ) ;
if ( ! V_133 -> V_36 ) {
F_14 ( V_2 , V_87 , V_56 ,
L_5 ) ;
return - V_127 ;
}
V_133 -> V_41 = V_41 ;
F_7 ( V_133 -> V_36 , V_48 , V_134 , V_41 ) ;
F_14 ( V_2 , V_112 , V_56 ,
L_6 ,
V_134 , V_41 ) ;
return 0 ;
}
unsigned int F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_135 * V_11 ;
struct V_135 * V_136 ;
unsigned int V_12 ;
int V_137 = 0 ;
if ( F_12 ( & V_7 -> V_14 ) )
return - V_138 ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return - V_127 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_48 ,
V_139 ,
sizeof( * V_11 ) ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
V_137 = F_26 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( V_137 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_7 , V_140 , V_137 ) ;
return - V_131 ;
}
V_136 = F_5 ( V_9 ) ;
V_2 -> V_141 = V_136 -> V_142 [ 0 ] ;
return V_137 ;
}
static inline bool F_31 ( T_2 * V_143 , T_3 V_95 )
{
T_3 V_61 ;
V_61 = ( V_95 < V_101 ) ? V_144 : V_145 ;
while ( V_61 && ! V_143 [ V_61 - 1 ] )
V_61 -- ;
return ( V_61 == 0 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
T_3 V_146 , T_3 V_95 , T_2 * V_147 )
{
struct V_148 * V_11 ;
struct V_28 V_29 ;
int V_149 ;
V_149 = F_28 ( V_2 , & V_29 ,
V_150 ,
sizeof( * V_11 ) ) ;
if ( V_149 )
return V_149 ;
V_11 = V_29 . V_36 ;
V_11 -> V_146 = V_146 ;
V_11 -> V_151 . V_95 = V_95 ;
memcpy ( V_11 -> V_151 . V_97 , V_147 ,
( V_95 < V_101 ) ? V_144 : V_145 ) ;
return F_24 ( V_2 , & V_29 , NULL , 0 ) ;
}
int F_33 ( struct V_1 * V_2 , T_3 V_95 , T_2 * V_147 )
{
struct V_152 V_153 ;
int V_149 ;
memset ( & V_153 , 0 , sizeof( V_153 ) ) ;
V_149 = F_34 ( V_2 , V_95 , & V_153 ) ;
if ( V_149 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_8 ) ;
return V_149 ;
}
if ( ! F_31 ( V_153 . V_151 . V_97 , V_95 ) ) {
V_149 = F_32 ( V_2 , V_154 , V_95 ,
V_153 . V_151 . V_97 ) ;
if ( V_149 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_9 ) ;
return V_149 ;
}
}
V_149 = F_32 ( V_2 , V_155 , V_95 , V_147 ) ;
if ( V_149 )
F_14 ( V_2 , V_55 , V_56 ,
L_10 ) ;
return V_149 ;
}
int F_34 ( struct V_1 * V_2 , T_3 V_95 ,
struct V_152 * V_156 )
{
struct V_157 * V_11 ;
struct V_28 V_29 ;
int V_126 ;
V_126 = F_28 ( V_2 , & V_29 ,
V_158 ,
sizeof( * V_156 ) ) ;
if ( V_126 )
return V_126 ;
V_11 = V_29 . V_36 ;
V_11 -> V_95 = V_95 ;
return F_24 ( V_2 , & V_29 , V_156 ,
sizeof( * V_156 ) ) ;
}
static int
F_35 ( struct V_1 * V_2 ,
struct V_159 * V_160 )
{
struct V_161 * V_11 ;
struct V_28 V_29 ;
int V_126 ;
V_126 = F_28 ( V_2 , & V_29 ,
V_162 ,
sizeof( * V_11 ) ) ;
if ( V_126 )
return V_126 ;
V_11 = V_29 . V_36 ;
V_11 -> V_163 . V_164 = 1 ;
V_11 -> V_163 . V_165 . V_146 = V_154 ;
V_11 -> V_163 . V_165 . V_166 =
V_2 -> V_141 ;
V_11 -> V_163 . V_165 . V_151 . V_167 =
sizeof( struct V_168 ) ;
V_11 -> V_163 . V_165 . V_151 . V_95 = V_160 -> V_151 . V_95 ;
memcpy ( V_11 -> V_163 . V_165 . V_151 . V_97 ,
V_160 -> V_151 . V_97 ,
sizeof( V_160 -> V_151 . V_97 ) ) ;
memcpy ( V_11 -> V_163 . V_165 . V_151 . V_169 ,
V_160 -> V_151 . V_169 ,
sizeof( V_160 -> V_151 . V_169 ) ) ;
V_126 = F_24 ( V_2 , & V_29 , NULL , 0 ) ;
if ( V_126 < 0 || V_11 -> V_163 . V_165 . V_137 ) {
F_14 ( V_2 , V_112 , V_56 ,
L_11 ,
V_126 , V_11 -> V_163 . V_165 . V_137 ) ;
}
return V_126 ;
}
static int
F_36 ( struct V_1 * V_2 , T_2 * V_143 ,
T_2 * V_170 , T_3 V_95 )
{
struct V_161 * V_11 ;
struct V_28 V_29 ;
T_4 V_171 ;
int V_126 ;
V_126 = F_28 ( V_2 , & V_29 ,
V_162 ,
sizeof( * V_11 ) ) ;
if ( V_126 )
return V_126 ;
V_11 = V_29 . V_36 ;
V_11 -> V_163 . V_164 = 1 ;
V_11 -> V_163 . V_165 . V_146 = V_155 ;
V_11 -> V_163 . V_165 . V_166 =
V_2 -> V_141 ;
V_11 -> V_163 . V_165 . V_151 . V_167 =
sizeof( struct V_168 ) ;
V_11 -> V_163 . V_165 . V_151 . V_95 = V_95 ;
V_171 = ( V_95 < V_101 ) ? V_144 : V_145 ;
memcpy ( V_11 -> V_163 . V_165 . V_151 . V_97 , V_143 , V_171 ) ;
if ( V_170 )
memcpy ( V_11 -> V_163 . V_165 . V_151 . V_169 ,
V_170 , V_171 ) ;
V_126 = F_24 ( V_2 , & V_29 , NULL , 0 ) ;
if ( V_126 < 0 || V_11 -> V_163 . V_165 . V_137 ) {
F_37 ( V_2 , V_87 ,
L_12 ,
V_126 , V_11 -> V_163 . V_165 . V_137 ) ;
if ( V_11 -> V_163 . V_165 . V_137 )
V_126 = - V_88 ;
}
return V_126 ;
}
int F_38 ( struct V_1 * V_2 , T_3 V_95 ,
T_2 * V_143 , T_2 * V_170 )
{
struct V_159 * V_160 ;
struct V_172 * V_173 ;
struct V_28 V_29 ;
int V_126 ;
V_126 = F_39 ( V_2 , V_95 , & V_160 ) ;
if ( V_126 )
return V_126 ;
if ( V_160 -> V_174 ) {
V_126 = F_28 ( V_2 , & V_29 ,
V_175 ,
sizeof( * V_173 ) ) ;
if ( V_126 )
goto exit;
V_173 = V_29 . V_36 ;
V_173 -> V_166 = V_2 -> V_141 ;
V_173 -> V_95 = V_95 ;
V_126 = F_24 ( V_2 , & V_29 , NULL , 0 ) ;
if ( V_126 < 0 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_13 ,
V_126 ) ;
goto exit;
}
}
if ( ! F_31 ( V_160 -> V_151 . V_97 , V_95 ) ) {
V_126 = F_35 ( V_2 , V_160 ) ;
if ( V_126 )
goto exit;
}
if ( V_143 )
V_126 = F_36 ( V_2 , V_143 , V_170 , V_95 ) ;
exit:
F_40 ( V_160 ) ;
return V_126 ;
}
int F_41 ( struct V_1 * V_2 , T_3 V_95 )
{
struct V_152 V_153 ;
struct V_159 * V_160 ;
struct V_176 * V_177 ;
struct V_28 V_29 ;
T_2 * V_147 ;
int V_126 ;
V_126 = F_39 ( V_2 , V_95 , & V_160 ) ;
if ( V_126 )
return V_126 ;
if ( V_160 -> V_174 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_14 ) ;
goto exit;
}
if ( ! F_31 ( V_160 -> V_151 . V_97 , V_95 ) ) {
V_126 = F_35 ( V_2 , V_160 ) ;
if ( V_126 )
goto exit;
}
memset ( & V_153 , 0 , sizeof( V_153 ) ) ;
V_126 = F_34 ( V_2 , V_160 -> V_151 . V_95 , & V_153 ) ;
if ( V_126 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_8 ) ;
goto exit;
}
V_147 = ( T_2 * ) & V_153 . V_151 . V_97 ;
if ( ! F_31 ( V_147 , V_160 -> V_151 . V_95 ) ) {
V_126 = F_32 ( V_2 , V_154 ,
V_160 -> V_151 . V_95 , V_147 ) ;
if ( V_126 ) {
F_14 ( V_2 , V_55 , V_56 ,
L_9 ) ;
goto exit;
}
}
V_126 = F_28 ( V_2 , & V_29 ,
V_178 ,
sizeof( * V_177 ) ) ;
if ( V_126 )
goto exit;
V_177 = V_29 . V_36 ;
V_177 -> V_179 = 1 ;
V_177 -> V_180 = 1 ;
V_177 -> V_166 = V_2 -> V_141 ;
V_177 -> V_95 = V_95 ;
V_126 = F_24 ( V_2 , & V_29 , NULL , 0 ) ;
exit:
F_40 ( V_160 ) ;
return V_126 ;
}
int F_42 ( struct V_1 * V_2 , T_5 V_181 )
{
int V_126 ;
unsigned int V_12 ;
V_12 = F_43 ( V_2 , V_181 ) ;
if ( ! V_12 ) {
F_14 ( V_2 , V_87 ,
( V_56 | V_130 ) ,
L_15 ) ;
return - V_131 ;
}
V_126 = F_26 ( V_2 , V_12 , NULL , NULL ) ;
if ( V_126 ) {
F_14 ( V_2 , V_87 ,
( V_56 | V_130 ) ,
L_16 ) ;
return V_126 ;
}
return V_126 ;
}
int F_39 ( struct V_1 * V_2 , int V_95 ,
struct V_159 * * V_160 )
{
struct V_182 * V_11 ;
struct V_28 V_29 ;
T_4 V_183 = sizeof( struct V_159 ) ;
int V_126 ;
V_126 = F_30 ( V_2 ) ;
if ( V_126 )
return V_126 ;
do {
V_126 = F_28 ( V_2 , & V_29 ,
V_184 ,
V_183 ) ;
if ( V_126 )
return V_126 ;
V_11 = V_29 . V_36 ;
V_11 -> V_166 = V_2 -> V_141 ;
V_11 -> V_95 = V_95 ;
* V_160 = F_44 ( V_183 , V_185 ) ;
if ( ! * V_160 ) {
F_14 ( V_2 , V_87 ,
V_186 | V_56 ,
L_17 ) ;
F_27 ( V_2 -> V_7 . V_132 ,
V_29 . V_41 ,
V_29 . V_36 ,
V_29 . V_59 ) ;
return - V_127 ;
}
V_126 = F_24 ( V_2 , & V_29 , * V_160 ,
V_183 ) ;
if ( V_126 == - V_129 ) {
V_183 = ( (struct V_187 * )
V_29 . V_36 ) -> V_188 ;
V_183 += sizeof( struct V_189 ) ;
F_27 ( V_2 -> V_7 . V_132 , V_29 . V_41 ,
V_29 . V_36 ,
V_29 . V_59 ) ;
F_40 ( * V_160 ) ;
} else
break;
} while ( true );
return V_126 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_190 * V_191 )
{
struct V_28 V_29 ;
int V_126 ;
V_126 = F_28 ( V_2 , & V_29 ,
V_192 ,
sizeof( * V_191 ) ) ;
if ( V_126 )
return V_126 ;
return F_24 ( V_2 , & V_29 , V_191 , sizeof( * V_191 ) ) ;
}
unsigned int F_46 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
struct V_8 * V_9 ;
struct V_193 * V_11 ;
struct V_6 * V_7 = & V_2 -> V_7 ;
if ( F_12 ( & V_7 -> V_14 ) )
return 0 ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_194 ,
V_195 ,
sizeof( * V_11 ) ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
static void F_47 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
struct V_196 * V_197 ;
struct V_198 * V_199 ;
struct V_200 * V_201 ;
struct V_8 * V_9 ;
struct V_202 * V_203 ;
int V_204 , V_137 ;
if ( ! F_48 ( V_205 , & V_2 -> V_206 ) ) {
F_37 ( V_2 , V_87 ,
L_18 ,
V_140 , V_2 -> V_206 ) ;
return;
}
if ( V_2 -> V_202 . V_12 != V_12 ) {
F_37 ( V_2 , V_87 ,
L_19 ,
V_140 , V_12 , V_2 -> V_202 . V_12 ) ;
return;
}
V_203 = & V_2 -> V_202 ;
V_204 = 1 ;
V_137 = 0 ;
switch ( V_203 -> V_146 ) {
case V_207 :
V_137 = F_49 ( V_2 , V_12 , NULL , NULL ) ;
if ( ! V_137 )
V_203 -> V_146 = V_208 ;
else
V_203 -> V_209 -- ;
break;
case V_208 :
V_137 = F_49 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( ! V_137 ) {
V_197 = F_5 ( V_9 ) ;
V_203 -> V_210 = V_197 -> V_211 ;
}
if ( V_203 -> V_210 == V_212 ) {
V_203 -> V_146 = V_207 ;
V_203 -> V_209 -- ;
} else {
V_203 -> V_146 = V_213 ;
}
break;
case V_213 :
V_137 = F_49 ( V_2 , V_12 , NULL ,
& V_203 -> V_29 ) ;
if ( ! V_137 ) {
V_201 = V_203 -> V_29 . V_36 ;
memcpy ( & V_203 -> V_214 , & V_201 -> V_215 ,
sizeof( struct V_216 ) ) ;
V_203 -> V_146 = V_217 ;
} else {
F_37 ( V_2 , V_87 ,
L_20 ,
V_137 ) ;
V_204 = 0 ;
}
F_27 ( V_2 -> V_7 . V_132 , V_203 -> V_29 . V_41 ,
V_203 -> V_29 . V_36 , V_203 -> V_29 . V_59 ) ;
V_203 -> V_29 . V_36 = NULL ;
break;
case V_217 :
V_137 = F_49 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( ! V_137 ) {
V_199 = F_5 ( V_9 ) ;
if ( V_199 -> V_218 != V_219 ) {
F_37 ( V_2 , V_87 ,
L_21 ,
V_199 -> V_218 ) ;
}
}
V_203 -> V_146 = V_220 ;
break;
default:
break;
}
V_203 -> V_12 = 0 ;
if ( ! V_203 -> V_209 ) {
V_204 = 0 ;
F_37 ( V_2 , V_87 ,
L_22 ,
V_137 , V_203 -> V_146 ) ;
}
if ( ! V_204 ) {
F_50 ( V_205 , & V_2 -> V_206 ) ;
return;
}
F_51 ( & V_2 -> V_204 ) ;
}
unsigned int F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_221 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_194 ,
V_222 ,
sizeof( struct V_221 ) ) ;
V_11 -> V_223 = V_2 -> V_202 . V_214 . V_223 ;
V_2 -> V_202 . V_12 = V_12 ;
F_9 ( V_224 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_225 = F_47 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_53 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_226 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_194 ,
V_227 ,
sizeof( struct V_228 ) ) ;
V_11 -> V_229 = V_230 ;
V_11 -> V_223 = V_212 ;
V_2 -> V_202 . V_12 = V_12 ;
F_9 ( V_224 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_225 = F_47 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_54 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_231 * V_11 ;
struct V_28 * V_29 ;
struct V_8 * V_9 ;
struct V_30 * V_83 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_29 = & V_2 -> V_202 . V_29 ;
V_29 -> V_41 = sizeof( struct V_200 ) ;
V_29 -> V_36 = F_55 ( V_2 -> V_7 . V_132 ,
V_29 -> V_41 ,
& V_29 -> V_59 ) ;
if ( ! V_29 -> V_36 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = V_29 -> V_36 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_83 = F_15 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , false , 1 ) ;
F_7 ( & V_11 -> V_15 , V_194 ,
V_232 ,
sizeof( struct V_200 ) ) ;
V_11 -> V_223 = V_2 -> V_202 . V_210 ;
V_83 -> V_58 = F_8 ( F_16 ( V_29 -> V_59 ) ) ;
V_83 -> V_60 = F_8 ( V_29 -> V_59 & 0xFFFFFFFF ) ;
V_83 -> V_61 = F_8 ( V_29 -> V_41 ) ;
V_2 -> V_202 . V_12 = V_12 ;
F_9 ( V_224 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_225 = F_47 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_56 ( struct V_1 * V_2 , int V_233 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_234 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( * V_11 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_194 ,
V_235 ,
sizeof( struct V_196 ) ) ;
if ( V_233 ) {
V_2 -> V_202 . V_12 = V_12 ;
F_9 ( V_224 , & V_7 -> V_24 [ V_12 ] . V_25 ) ;
V_7 -> V_24 [ V_12 ] . V_225 = F_47 ;
}
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
int F_57 ( struct V_1 * V_2 , unsigned int * V_210 )
{
struct V_196 * V_197 ;
struct V_8 * V_9 ;
unsigned int V_12 ;
int V_126 ;
* V_210 = V_212 ;
V_12 = F_56 ( V_2 , 0 ) ;
if ( ! V_12 ) {
F_14 ( V_2 , V_87 ,
V_56 | V_186 ,
L_23 ) ;
return - V_129 ;
}
V_126 = F_26 ( V_2 , V_12 , & V_9 , NULL ) ;
if ( V_126 ) {
F_14 ( V_2 , V_87 ,
V_186 | V_56 ,
L_24 ) ;
return - V_131 ;
}
V_197 = F_5 ( V_9 ) ;
if ( ! V_197 -> V_236 ) {
F_37 ( V_2 , V_112 ,
L_25 ) ;
return - V_237 ;
}
* V_210 = V_197 -> V_211 ;
return 1 ;
}
T_6
F_58 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * V_242 )
{
return snprintf ( V_242 , V_243 , V_244 L_26 ) ;
}
T_6
F_59 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * V_242 )
{
struct V_245 * V_246 = F_60 ( V_239 ) ;
struct V_1 * V_2 = F_61 ( V_246 ) ;
return snprintf ( V_242 , V_243 , L_27 , V_2 -> V_247 ) ;
}
T_6
F_62 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * V_242 )
{
struct V_245 * V_246 = F_60 ( V_239 ) ;
struct V_1 * V_2 = F_61 ( V_246 ) ;
T_5 V_248 = 0 , V_80 , V_61 = 0 , V_249 = 0 ;
for ( V_80 = 0 ; V_80 < V_250 ; V_80 ++ ) {
if ( F_48 ( V_80 , ( void * ) & V_2 -> V_251 . V_252 ) ) {
V_248 = F_63 ( V_2 , V_80 ) ;
V_249 = F_64 ( V_2 , V_80 ) ;
V_61 += snprintf ( V_242 + V_61 , V_243 - V_61 ,
L_28 , V_80 ,
( V_249 - V_248 ) ) ;
} else
V_61 += snprintf ( V_242 + V_61 , V_243 - V_61 ,
L_28 , V_80 , 0 ) ;
}
return V_61 ;
}
T_6
F_65 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * V_242 )
{
struct V_245 * V_246 = F_60 ( V_239 ) ;
struct V_1 * V_2 = F_61 ( V_246 ) ;
T_5 V_80 , V_61 = 0 ;
for ( V_80 = 0 ; V_80 < V_250 ; V_80 ++ ) {
if ( F_48 ( V_80 , ( void * ) & V_2 -> V_251 . V_252 ) )
V_61 += snprintf ( V_242 + V_61 , V_243 - V_61 ,
L_28 , V_80 ,
F_63 ( V_2 , V_80 ) ) ;
else
V_61 += snprintf ( V_242 + V_61 , V_243 - V_61 ,
L_28 , V_80 , 0 ) ;
}
return V_61 ;
}
T_6
F_66 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * V_242 )
{
T_5 V_253 = 0 ;
struct V_245 * V_246 = F_60 ( V_239 ) ;
struct V_1 * V_2 = F_61 ( V_246 ) ;
V_253 = V_2 -> V_254 -> V_238 ;
switch ( V_253 ) {
case V_255 :
case V_256 :
case V_257 :
return snprintf ( V_242 , V_243 ,
L_29 ) ;
break;
case V_258 :
case V_259 :
return snprintf ( V_242 , V_243 , L_30 ) ;
break;
case V_260 :
return snprintf ( V_242 , V_243 , L_31 ) ;
break;
default:
return snprintf ( V_242 , V_243 ,
L_32 , V_253 ) ;
break;
}
}
T_6
F_67 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * V_242 )
{
struct V_245 * V_246 = F_60 ( V_239 ) ;
struct V_1 * V_2 = F_61 ( V_246 ) ;
return snprintf ( V_242 , V_243 , L_33 ,
V_2 -> V_251 . V_261 ) ;
}
void F_68 ( struct V_262 * V_263 ,
struct V_264 * V_265 ,
struct V_266 * V_267 ,
struct V_268 * V_269 )
{
struct V_270 * V_271 = V_265 -> V_271 ;
F_69 ( struct V_272 ,
V_273 , V_271 ,
V_263 -> V_274 [ F_70 ( struct V_275 ,
V_273 ) / 32 ] ) ;
F_69 ( struct V_272 , type , V_271 ,
V_276 ) ;
F_69 ( struct V_272 ,
V_277 ,
V_271 ,
V_263 -> V_274 [ F_70 ( struct V_275 ,
V_277 ) / 32 ] ) ;
F_69 ( struct V_272 , V_278 , V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_278 ) / 32 ] & V_279 ) ) ;
F_69 ( struct V_272 , V_280 , V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_280 ) / 32 ] & V_281 ) >> 2 ) ;
F_69 ( struct V_272 , V_282 , V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_282 ) / 32 ] & V_283 ) >> 3 ) ;
F_69 ( struct V_272 , V_284 , V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_284 ) / 32 ] & V_285 ) >> 4 ) ;
F_69 ( struct V_272 , V_286 , V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_286 ) / 32 ] & V_287 ) >> 5 ) ;
F_69 ( struct V_272 , V_288 ,
V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_289 ) / 32 ] + 1 ) ) ;
F_69 ( struct V_272 , V_290 ,
V_271 , V_265 -> V_291 ) ;
F_69 ( struct V_272 ,
V_292 , V_271 , V_263 -> V_274 [ F_70
( struct V_275 ,
V_292 ) / 32 ] ) ;
F_69 ( struct V_272 , V_293 ,
V_271 , V_265 -> V_291 ) ;
if ( V_269 -> V_294 )
F_69 ( struct V_272 ,
V_293 ,
V_269 -> V_294 ,
V_265 -> V_291 ) ;
V_269 -> V_294 = V_271 ;
F_69 ( struct V_272 ,
V_295 , V_271 , 0 ) ;
F_69 ( struct V_272 , V_296 ,
V_271 , 1 ) ;
F_69 ( struct V_272 , V_297 ,
V_271 , 0 ) ;
F_69 ( struct V_272 , V_298 , V_271 ,
0 ) ;
V_267 += V_299 ;
F_69 ( struct V_272 ,
V_300 , V_271 ,
V_267 -> V_301 [ 0 ] . V_302 . V_303 . V_304 . V_305 ) ;
F_69 ( struct V_272 ,
V_306 , V_271 ,
V_267 -> V_301 [ 0 ] . V_302 . V_303 . V_304 . V_307 ) ;
}
void F_71 ( struct V_262 * V_263 ,
struct V_264 * V_265 ,
struct V_268 * V_269 )
{
struct V_270 * V_271 = V_265 -> V_271 ;
F_69 ( struct V_308 ,
V_292 , V_271 , V_263 -> V_274 [ F_70
( struct V_275 ,
V_292 ) / 32 ] ) ;
F_69 ( struct V_308 ,
type , V_271 ,
V_276 ) ;
F_69 ( struct V_308 ,
V_293 ,
V_271 , V_265 -> V_291 ) ;
if ( V_269 -> V_294 )
F_69 ( struct V_308 ,
V_293 ,
V_269 -> V_294 ,
V_265 -> V_291 ) ;
V_269 -> V_294 = V_271 ;
F_69 ( struct V_308 , V_290 ,
V_271 , V_265 -> V_291 ) ;
F_69 ( struct V_308 ,
V_273 , V_271 ,
V_263 -> V_274 [ F_70 ( struct V_275 ,
V_273 ) / 32 ] ) ;
F_69 ( struct V_308 ,
V_277 , V_271 ,
V_263 -> V_274 [ F_70 ( struct V_275 ,
V_277 ) / 32 ] ) ;
F_69 ( struct V_308 ,
V_309 , V_271 ,
V_263 -> V_274 [ F_70 ( struct V_275 ,
V_310 ) / 32 ] ) ;
F_69 ( struct V_308 ,
V_311 , V_271 , V_312 ) ;
F_69 ( struct V_308 , V_278 , V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_278 ) / 32 ] & V_279 ) ) ;
F_69 ( struct V_308 , V_280 , V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_280 ) / 32 ] & V_281 ) >> 2 ) ;
F_69 ( struct V_308 , V_282 , V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_282 ) / 32 ] & V_283 ) >> 3 ) ;
F_69 ( struct V_308 ,
V_284 , V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_284 ) / 32 ] & V_285 ) >> 4 ) ;
F_69 ( struct V_308 , V_286 , V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_286 ) / 32 ] & V_287 ) >> 5 ) ;
F_69 ( struct V_308 ,
V_313 ,
V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_313 ) / 32 ] &
V_314 ) >> 6 ) ;
F_69 ( struct V_308 ,
V_315 ,
V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_315 ) / 32 ] &
V_316 ) >> 7 ) ;
F_69 ( struct V_308 , V_317 ,
V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_317 ) / 32 ] &
V_318 ) >> 8 ) ;
F_69 ( struct V_308 , V_288 ,
V_271 ,
( V_263 -> V_274 [ F_70 ( struct V_275 ,
V_289 ) / 32 ] + 1 ) ) ;
}
unsigned int F_72 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_319 * V_11 ;
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
unsigned int V_12 = 0 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( union V_320 ) ,
true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_194 ,
V_321 ,
sizeof( * V_11 ) ) ;
V_11 -> V_223 = V_65 -> V_322 ;
V_11 -> V_81 = V_65 -> V_82 ;
if ( V_65 -> V_323 )
V_11 -> V_324 = V_325 ;
else
V_11 -> V_324 = V_326 ;
V_11 -> V_327 = 0 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
unsigned int F_73 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_328 * V_11 ;
unsigned int V_12 ;
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
return 0 ;
}
V_11 = F_5 ( V_9 ) ;
F_6 ( V_9 , sizeof( union V_329 ) , true , 0 ) ;
F_7 ( & V_11 -> V_15 , V_330 ,
V_331 , sizeof( * V_11 ) ) ;
V_11 -> V_111 = V_65 -> V_82 ;
if ( V_65 -> V_323 )
V_11 -> V_332 = V_333 ;
else
V_11 -> V_332 = V_334 ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_12 ;
}
int F_74 ( struct V_1 * V_2 ,
struct V_335 * V_336 ,
unsigned int V_337 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_338 * V_11 ;
struct V_28 V_29 ;
struct V_8 * V_9 ;
unsigned int V_13 , V_12 ;
struct V_30 * V_83 ;
int V_126 ;
if ( ! V_337 || V_337 > V_339 )
return - V_88 ;
V_29 . V_41 = sizeof( union V_340 ) ;
V_29 . V_36 = F_29 ( V_2 -> V_7 . V_132 ,
V_29 . V_41 ,
& V_29 . V_59 ) ;
if ( ! V_29 . V_36 ) {
F_14 ( V_2 , V_87 , V_341 ,
L_34 ) ;
return - V_127 ;
}
F_2 ( & V_7 -> V_14 ) ;
V_9 = F_3 ( V_2 , & V_12 ) ;
if ( ! V_9 ) {
F_4 ( & V_7 -> V_14 ) ;
F_27 ( V_2 -> V_7 . V_132 , V_29 . V_41 ,
V_29 . V_36 , V_29 . V_59 ) ;
return - V_127 ;
}
V_11 = V_29 . V_36 ;
F_6 ( V_9 , V_29 . V_41 , false , 1 ) ;
F_7 ( & V_11 -> V_15 , V_48 ,
V_342 ,
sizeof( * V_11 ) ) ;
V_11 -> V_343 = 0 ;
V_11 -> V_324 = V_344 ;
for ( V_13 = 0 ; V_13 < V_337 ; V_13 ++ ) {
V_11 -> V_345 [ V_13 ] . V_346 = V_336 [ V_13 ] . V_346 ;
V_11 -> V_345 [ V_13 ] . V_81 = V_336 [ V_13 ] . V_81 ;
V_11 -> V_347 ++ ;
}
V_83 = F_15 ( V_9 ) ;
V_83 -> V_58 = F_8 ( F_16 ( V_29 . V_59 ) ) ;
V_83 -> V_60 = F_8 ( F_25 ( V_29 . V_59 ) ) ;
V_83 -> V_61 = F_8 ( V_29 . V_41 ) ;
F_10 ( V_2 , V_12 ) ;
F_4 ( & V_7 -> V_14 ) ;
V_126 = F_26 ( V_2 , V_12 , NULL , & V_29 ) ;
if ( V_126 != - V_131 )
F_27 ( V_2 -> V_7 . V_132 , V_29 . V_41 ,
V_29 . V_36 , V_29 . V_59 ) ;
return V_126 ;
}
