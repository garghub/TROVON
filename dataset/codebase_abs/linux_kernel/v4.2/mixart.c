static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 V_7 ;
struct V_8 V_9 ;
struct V_10 V_11 ;
int V_12 ;
T_1 V_13 ;
switch( V_4 -> V_14 ) {
case V_15 :
case V_16 :
if( V_5 ) return 0 ;
break;
case V_17 :
if( ! V_5 ) return 0 ;
break;
default:
F_2 ( & V_2 -> V_18 -> V_19 ,
L_1 ) ;
return - V_20 ;
}
V_13 = 0x12345678 ;
V_11 . V_21 = V_22 ;
V_11 . V_23 = (struct V_24 ) { 0 , 0 } ;
V_11 . V_25 = & V_13 ;
V_11 . V_26 = sizeof( V_13 ) ;
V_12 = F_3 ( V_2 , & V_11 , V_13 ) ;
if( V_12 ) {
F_2 ( & V_2 -> V_18 -> V_19 ,
L_2 ) ;
return V_12 ;
}
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_27 = 1 ;
V_7 . V_28 [ 0 ] = V_4 -> V_29 ;
if( V_5 )
V_11 . V_21 = V_30 ;
else
V_11 . V_21 = V_31 ;
V_11 . V_23 = V_4 -> V_29 ;
V_11 . V_25 = & V_7 ;
V_11 . V_26 = sizeof( V_7 ) ;
V_12 = F_4 ( V_2 , & V_11 , sizeof( V_9 ) , & V_9 ) ;
if ( V_12 < 0 || V_9 . V_32 != 0 ) {
F_2 ( & V_2 -> V_18 -> V_19 ,
L_3 ,
V_12 , V_9 . V_32 ) ;
return - V_20 ;
}
if( V_5 ) {
T_1 V_33 ;
V_7 . V_27 = 0 ;
V_12 = F_4 ( V_2 , & V_11 , sizeof( V_9 ) , & V_9 ) ;
if ( V_12 < 0 || V_9 . V_32 != 0 ) {
F_2 ( & V_2 -> V_18 -> V_19 ,
L_4 ,
V_12 , V_9 . V_32 ) ;
return - V_20 ;
}
V_11 . V_21 = V_34 ;
V_11 . V_23 = (struct V_24 ) { 0 , 0 } ;
V_11 . V_25 = NULL ;
V_11 . V_26 = 0 ;
V_12 = F_4 ( V_2 , & V_11 , sizeof( V_33 ) , & V_33 ) ;
if ( V_12 < 0 || V_33 != 0 ) {
F_2 ( & V_2 -> V_18 -> V_19 ,
L_5 ,
V_12 , V_33 ) ;
return - V_20 ;
}
V_4 -> V_14 = V_15 ;
}
else
V_4 -> V_14 = V_17 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_35 )
{
struct V_10 V_11 ;
struct V_36 V_37 ;
struct V_38 V_39 ;
int V_12 ;
switch( V_4 -> V_14 ) {
case V_16 :
break;
case V_15 :
if( V_35 != 0 )
break;
default:
if( V_35 == 0 )
return 0 ;
else {
F_2 ( & V_2 -> V_18 -> V_19 ,
L_6 ,
V_35 ) ;
return - V_20 ;
}
}
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_40 = ( V_35 != 0 ) ? V_41 : V_42 ;
V_37 . V_43 = V_44 ;
V_37 . V_45 = V_35 ;
V_37 . V_46 = 1 ;
V_37 . V_47 [ 0 ] = V_4 -> V_29 ;
F_6 ( & V_2 -> V_18 -> V_19 , L_7 , V_35 ) ;
V_11 . V_21 = V_48 ;
V_11 . V_23 = V_2 -> V_49 ;
V_11 . V_25 = & V_37 ;
V_11 . V_26 = sizeof( V_37 ) ;
V_12 = F_4 ( V_2 , & V_11 , sizeof( V_39 ) , & V_39 ) ;
if ( V_12 < 0 || V_39 . V_14 != 0 || V_39 . V_43 != V_44 ) {
F_2 ( & V_2 -> V_18 -> V_19 ,
L_8 ,
V_12 , V_39 . V_14 , V_39 . V_43 ) ;
return - V_20 ;
}
if( V_35 ) V_4 -> V_14 = V_16 ;
else V_4 -> V_14 = V_15 ;
return 0 ;
}
struct V_3 *
F_7 ( struct V_50 * V_51 , int V_52 , int V_53 ,
int V_54 )
{
int V_55 ;
struct V_3 * V_4 ;
struct V_10 V_11 ;
if( V_53 ) {
if ( V_52 == V_56 ) {
V_4 = & ( V_51 -> V_57 ) ;
} else {
V_4 = & ( V_51 -> V_58 ) ;
}
V_11 . V_21 = V_59 ;
V_55 = V_60 ;
} else {
if ( V_52 == V_56 ) {
V_4 = & ( V_51 -> V_61 ) ;
} else {
V_4 = & ( V_51 -> V_62 ) ;
}
V_11 . V_21 = V_63 ;
V_55 = V_64 ;
}
if( ( V_54 == 0 ) && ( V_4 -> V_65 >= V_55 ) ) {
return NULL ;
}
if( V_4 -> V_14 == V_66 ) {
int V_12 , V_67 ;
struct {
struct V_68 V_69 ;
struct V_70 V_71 ;
} * V_72 ;
F_6 ( V_51 -> V_73 -> V_19 ,
L_9 ,
V_51 -> V_74 , V_52 ) ;
V_72 = F_8 ( sizeof( * V_72 ) , V_75 ) ;
if ( ! V_72 )
return NULL ;
V_11 . V_23 = (struct V_24 ) { 0 , 0 } ;
V_11 . V_25 = & V_72 -> V_69 ;
V_11 . V_26 = sizeof( V_72 -> V_69 ) ;
memset ( & V_72 -> V_69 , 0 , sizeof( V_72 -> V_69 ) ) ;
V_72 -> V_69 . V_55 = V_55 ;
V_72 -> V_69 . V_76 = 2 ;
V_72 -> V_69 . V_77 = 256 ;
V_72 -> V_69 . V_78 = V_4 -> V_79 ;
for ( V_67 = 0 ; V_67 < V_55 ; V_67 ++ ) {
int V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
V_72 -> V_69 . V_85 [ V_67 ] . V_86 = 1024 ;
V_72 -> V_69 . V_85 [ V_67 ] . V_87 = 256 ;
V_72 -> V_69 . V_85 [ V_67 ] . V_88 = V_89 ;
V_80 = ( V_51 -> V_74 * V_90 ) + ( V_52 * ( V_64 + V_60 ) ) + V_67 ;
if( V_53 ) V_80 += V_64 ;
V_72 -> V_69 . V_91 [ V_67 ] = V_80 ;
V_82 = (struct V_81 * ) V_51 -> V_2 -> V_82 . V_92 ;
V_82 [ V_80 ] . V_93 = ( T_1 ) V_51 -> V_2 -> V_84 . V_94 + ( V_80 * sizeof( struct V_83 ) ) ;
V_82 [ V_80 ] . V_95 = 1 ;
V_84 = (struct V_83 * ) V_51 -> V_2 -> V_84 . V_92 ;
V_84 [ V_80 ] . V_96 = 0 ;
V_84 [ V_80 ] . V_97 = 0 ;
V_84 [ V_80 ] . V_98 = ( V_51 -> V_74 << V_99 ) + ( V_52 << V_100 ) + V_67 ;
if( V_53 ) {
V_84 [ V_80 ] . V_98 |= V_101 ;
}
}
V_12 = F_4 ( V_51 -> V_2 , & V_11 , sizeof( V_72 -> V_71 ) , & V_72 -> V_71 ) ;
if( ( V_12 < 0 ) || ( V_72 -> V_71 . V_14 != 0 ) ) {
F_2 ( V_51 -> V_73 -> V_19 ,
L_10 ,
V_12 , V_72 -> V_71 . V_14 ) ;
F_9 ( V_72 ) ;
return NULL ;
}
V_4 -> V_29 = V_72 -> V_71 . V_102 ;
V_4 -> V_55 = V_72 -> V_71 . V_55 ;
V_4 -> V_14 = V_17 ;
F_9 ( V_72 ) ;
}
if( V_54 ) V_4 -> V_54 = 1 ;
else V_4 -> V_65 ++ ;
return V_4 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_54 )
{
int V_12 = 0 ;
if( V_4 -> V_14 == V_66 )
return 0 ;
if( V_54 )
V_4 -> V_54 = 0 ;
else
V_4 -> V_65 -- ;
if( ( V_4 -> V_65 <= 0 ) && ( V_4 -> V_54 == 0 ) ) {
struct V_10 V_11 ;
struct V_103 V_104 ;
V_12 = F_5 ( V_2 , V_4 , 0 ) ;
if( V_12 < 0 ) {
F_2 ( & V_2 -> V_18 -> V_19 ,
L_11 ) ;
}
V_12 = F_1 ( V_2 , V_4 , 0 ) ;
if( V_12 < 0 ) {
F_2 ( & V_2 -> V_18 -> V_19 , L_12 ) ;
}
V_11 . V_21 = V_105 ;
V_11 . V_23 = (struct V_24 ) { 0 , 0 } ;
V_11 . V_25 = & V_4 -> V_29 ;
V_11 . V_26 = sizeof( V_4 -> V_29 ) ;
V_12 = F_4 ( V_2 , & V_11 , sizeof( V_104 ) , & V_104 ) ;
if ( ( V_12 < 0 ) || ( V_104 . V_14 != 0 ) ) {
F_2 ( & V_2 -> V_18 -> V_19 ,
L_13 ,
V_12 , V_104 . V_14 ) ;
}
V_4 -> V_29 = (struct V_24 ) { 0 , 0 } ;
V_4 -> V_55 = 0 ;
V_4 -> V_14 = V_66 ;
}
return V_12 ;
}
static int F_11 ( struct V_106 * V_107 , int V_5 )
{
struct V_50 * V_51 ;
struct V_108 V_109 ;
struct V_10 V_11 ;
if( ! V_107 -> V_110 )
return - V_20 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_109 . V_55 = 1 ;
V_109 . V_85 . V_111 . V_112 = V_107 -> V_4 -> V_29 ;
V_109 . V_85 . V_111 . V_113 = V_107 -> V_110 -> V_114 ;
if ( V_107 -> V_110 -> V_107 == V_115 )
V_11 . V_21 = V_5 ? V_116 : V_117 ;
else
V_11 . V_21 = V_5 ? V_118 : V_119 ;
V_11 . V_23 = (struct V_24 ) { 0 , 0 } ;
V_11 . V_25 = & V_109 ;
V_11 . V_26 = sizeof( V_109 ) ;
V_107 -> V_120 = 0 ;
V_107 -> V_121 = 0 ;
V_107 -> V_122 = 0 ;
V_51 = F_12 ( V_107 -> V_110 ) ;
return F_13 ( V_51 -> V_2 , & V_11 ) ;
}
static int F_14 ( struct V_123 * V_124 , int V_125 )
{
struct V_106 * V_107 = V_124 -> V_126 -> V_127 ;
switch ( V_125 ) {
case V_128 :
F_6 ( V_124 -> V_129 -> V_73 -> V_19 , L_14 ) ;
if( F_11 ( V_107 , 1 ) )
return - V_20 ;
V_107 -> V_14 = V_130 ;
break;
case V_131 :
if( F_11 ( V_107 , 0 ) )
return - V_20 ;
V_107 -> V_14 = V_132 ;
F_6 ( V_124 -> V_129 -> V_73 -> V_19 , L_15 ) ;
break;
case V_133 :
V_107 -> V_14 = V_134 ;
F_6 ( V_124 -> V_129 -> V_73 -> V_19 , L_16 ) ;
break;
case V_135 :
V_107 -> V_14 = V_130 ;
F_6 ( V_124 -> V_129 -> V_73 -> V_19 , L_17 ) ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_136 = V_137 + V_138 ;
while ( F_16 ( & V_2 -> V_139 ) > 0 ) {
if ( F_17 ( V_137 , V_136 ) ) {
F_2 ( & V_2 -> V_18 -> V_19 ,
L_18 ) ;
return - V_140 ;
}
F_18 ( 1 ) ;
}
return 0 ;
}
static int F_19 ( struct V_123 * V_124 )
{
struct V_50 * V_51 = F_12 ( V_124 ) ;
struct V_106 * V_107 = V_124 -> V_126 -> V_127 ;
F_6 ( V_51 -> V_73 -> V_19 , L_19 ) ;
F_15 ( V_51 -> V_2 ) ;
if( V_51 -> V_2 -> V_141 == 1 )
V_51 -> V_2 -> V_142 = V_124 -> V_126 -> V_35 ;
if( V_107 -> V_4 -> V_65 == 1 ) {
if( F_5 ( V_51 -> V_2 , V_107 -> V_4 , V_124 -> V_126 -> V_35 ) )
return - V_20 ;
}
return 0 ;
}
static int F_20 ( struct V_106 * V_107 , T_2 V_143 )
{
int V_12 ;
struct V_50 * V_51 ;
struct V_10 V_11 ;
struct V_144 V_145 ;
struct V_146 V_147 ;
V_51 = F_12 ( V_107 -> V_110 ) ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 . V_148 = V_149 ;
V_145 . V_150 = V_107 -> V_151 ;
V_145 . V_152 = V_51 -> V_2 -> V_142 ;
if( V_145 . V_152 == 0 )
V_145 . V_152 = 44100 ;
switch( V_143 ) {
case V_153 :
V_145 . V_154 = V_155 ;
V_145 . V_156 = 8 ;
break;
case V_157 :
V_145 . V_154 = V_158 ;
V_145 . V_156 = 16 ;
break;
case V_159 :
V_145 . V_154 = V_160 ;
V_145 . V_156 = 16 ;
break;
case V_161 :
V_145 . V_154 = V_162 ;
V_145 . V_156 = 24 ;
break;
case V_163 :
V_145 . V_154 = V_164 ;
V_145 . V_156 = 24 ;
break;
case V_165 :
V_145 . V_154 = V_166 ;
V_145 . V_156 = 32 ;
break;
case V_167 :
V_145 . V_154 = V_168 ;
V_145 . V_156 = 32 ;
break;
default:
F_2 ( V_51 -> V_73 -> V_19 ,
L_20 ) ;
return - V_20 ;
}
F_6 ( V_51 -> V_73 -> V_19 ,
L_21 ,
V_145 . V_154 , V_145 . V_156 , V_145 . V_152 , V_107 -> V_151 ) ;
V_145 . V_27 = 1 ;
V_145 . V_55 = 1 ;
V_145 . V_111 [ 0 ] . V_112 = V_107 -> V_4 -> V_29 ;
V_145 . V_111 [ 0 ] . V_113 = V_107 -> V_110 -> V_114 ;
V_11 . V_21 = V_169 ;
V_11 . V_23 = (struct V_24 ) { 0 , 0 } ;
V_11 . V_25 = & V_145 ;
V_11 . V_26 = sizeof( V_145 ) ;
V_12 = F_4 ( V_51 -> V_2 , & V_11 , sizeof( V_147 ) , & V_147 ) ;
if( ( V_12 < 0 ) || V_147 . V_170 ) {
F_2 ( V_51 -> V_73 -> V_19 ,
L_22 ,
V_12 , V_147 . V_170 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_21 ( struct V_123 * V_124 ,
struct V_171 * V_172 )
{
struct V_50 * V_51 = F_12 ( V_124 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_106 * V_107 = V_124 -> V_126 -> V_127 ;
T_2 V_143 ;
int V_12 ;
int V_151 ;
V_151 = F_22 ( V_172 ) ;
V_143 = F_23 ( V_172 ) ;
F_24 ( & V_2 -> V_173 ) ;
if( V_107 -> V_52 <= V_174 ) {
int V_175 = V_107 -> V_52 > V_56 ;
if( V_124 -> V_107 == V_115 )
F_25 ( V_51 , V_175 , V_124 -> V_114 ) ;
else
F_26 ( V_51 , V_175 ) ;
}
V_107 -> V_151 = V_151 ;
V_12 = F_20 ( V_107 , V_143 ) ;
if( V_12 < 0 ) {
F_27 ( & V_2 -> V_173 ) ;
return V_12 ;
}
V_12 = F_28 ( V_124 , F_29 ( V_172 ) ) ;
if ( V_12 > 0 ) {
struct V_83 * V_84 ;
int V_67 = ( V_51 -> V_74 * V_90 ) + ( V_107 -> V_52 * ( V_64 + V_60 ) ) + V_124 -> V_114 ;
if( V_124 -> V_107 == V_176 ) {
V_67 += V_64 ;
}
V_84 = (struct V_83 * ) V_51 -> V_2 -> V_84 . V_92 ;
V_84 [ V_67 ] . V_96 = V_124 -> V_126 -> V_177 ;
V_84 [ V_67 ] . V_97 = V_124 -> V_126 -> V_178 ;
F_6 ( V_51 -> V_73 -> V_19 ,
L_23 ,
V_67 , V_84 [ V_67 ] . V_96 ,
V_84 [ V_67 ] . V_97 ,
V_124 -> V_114 ) ;
}
F_27 ( & V_2 -> V_173 ) ;
return V_12 ;
}
static int F_30 ( struct V_123 * V_124 )
{
struct V_50 * V_51 = F_12 ( V_124 ) ;
F_31 ( V_124 ) ;
F_15 ( V_51 -> V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_123 * V_124 )
{
struct V_50 * V_51 = F_12 ( V_124 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_179 * V_126 = V_124 -> V_126 ;
struct V_180 * V_129 = V_124 -> V_129 ;
struct V_106 * V_107 ;
struct V_3 * V_4 ;
int V_12 = 0 ;
int V_52 ;
F_24 ( & V_2 -> V_173 ) ;
if ( V_129 == V_51 -> V_129 ) {
V_52 = V_56 ;
V_126 -> V_172 = V_181 ;
} else {
F_33 ( V_129 != V_51 -> V_182 ) ;
V_52 = V_174 ;
V_126 -> V_172 = V_183 ;
}
F_6 ( V_51 -> V_73 -> V_19 ,
L_24 ,
V_51 -> V_74 , V_52 , V_124 -> V_114 ) ;
V_107 = & ( V_51 -> V_184 [ V_52 ] [ V_124 -> V_114 ] ) ;
if ( V_107 -> V_14 != V_185 ) {
F_2 ( V_51 -> V_73 -> V_19 ,
L_25 ,
V_51 -> V_74 , V_52 , V_124 -> V_114 ) ;
V_12 = - V_140 ;
goto V_186;
}
V_4 = F_7 ( V_51 , V_52 , 0 , 0 ) ;
if ( V_4 == NULL ) {
V_12 = - V_20 ;
goto V_186;
}
V_12 = F_1 ( V_51 -> V_2 , V_4 , 1 ) ;
if( V_12 < 0 ) {
F_2 ( V_51 -> V_73 -> V_19 , L_26 ) ;
F_10 ( V_51 -> V_2 , V_4 , 0 ) ;
V_12 = - V_20 ;
goto V_186;
}
V_107 -> V_4 = V_4 ;
V_107 -> V_52 = V_52 ;
V_107 -> V_14 = V_132 ;
V_107 -> V_110 = V_124 ;
V_107 -> V_151 = 0 ;
V_126 -> V_127 = V_107 ;
F_34 ( V_126 , 0 , V_187 , 32 ) ;
F_34 ( V_126 , 0 , V_188 , 64 ) ;
if( V_2 -> V_141 ++ ) {
if( V_2 -> V_142 ) {
V_126 -> V_172 . V_189 = V_126 -> V_172 . V_190 = V_2 -> V_142 ;
}
}
V_186:
F_27 ( & V_2 -> V_173 ) ;
return V_12 ;
}
static int F_35 ( struct V_123 * V_124 )
{
struct V_50 * V_51 = F_12 ( V_124 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_179 * V_126 = V_124 -> V_126 ;
struct V_180 * V_129 = V_124 -> V_129 ;
struct V_106 * V_107 ;
struct V_3 * V_4 ;
int V_12 = 0 ;
int V_52 ;
F_24 ( & V_2 -> V_173 ) ;
if ( V_129 == V_51 -> V_129 ) {
V_52 = V_56 ;
V_126 -> V_172 = V_181 ;
} else {
F_33 ( V_129 != V_51 -> V_182 ) ;
V_52 = V_174 ;
V_126 -> V_172 = V_183 ;
}
V_126 -> V_172 . V_191 = 2 ;
F_6 ( V_51 -> V_73 -> V_19 , L_27 ,
V_51 -> V_74 , V_52 , V_124 -> V_114 ) ;
V_107 = & ( V_51 -> V_192 [ V_52 ] ) ;
if ( V_107 -> V_14 != V_185 ) {
F_2 ( V_51 -> V_73 -> V_19 ,
L_28 ,
V_51 -> V_74 , V_52 , V_124 -> V_114 ) ;
V_12 = - V_140 ;
goto V_186;
}
V_4 = F_7 ( V_51 , V_52 , 1 , 0 ) ;
if ( V_4 == NULL ) {
V_12 = - V_20 ;
goto V_186;
}
V_12 = F_1 ( V_51 -> V_2 , V_4 , 1 ) ;
if( V_12 < 0 ) {
F_2 ( V_51 -> V_73 -> V_19 , L_26 ) ;
F_10 ( V_51 -> V_2 , V_4 , 0 ) ;
V_12 = - V_20 ;
goto V_186;
}
V_107 -> V_4 = V_4 ;
V_107 -> V_52 = V_52 ;
V_107 -> V_14 = V_132 ;
V_107 -> V_110 = V_124 ;
V_107 -> V_151 = 0 ;
V_126 -> V_127 = V_107 ;
F_34 ( V_126 , 0 , V_187 , 32 ) ;
F_34 ( V_126 , 0 , V_188 , 64 ) ;
if( V_2 -> V_141 ++ ) {
if( V_2 -> V_142 ) {
V_126 -> V_172 . V_189 = V_126 -> V_172 . V_190 = V_2 -> V_142 ;
}
}
V_186:
F_27 ( & V_2 -> V_173 ) ;
return V_12 ;
}
static int F_36 ( struct V_123 * V_124 )
{
struct V_50 * V_51 = F_12 ( V_124 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_106 * V_107 = V_124 -> V_126 -> V_127 ;
F_24 ( & V_2 -> V_173 ) ;
F_6 ( V_51 -> V_73 -> V_19 , L_29 ,
V_51 -> V_74 , V_107 -> V_52 , V_124 -> V_114 ) ;
if( -- V_2 -> V_141 == 0 ) {
V_2 -> V_142 = 0 ;
}
if ( F_10 ( V_2 , V_107 -> V_4 , 0 ) < 0 ) {
F_2 ( V_51 -> V_73 -> V_19 ,
L_30 ,
V_51 -> V_74 , V_107 -> V_52 ) ;
}
V_107 -> V_4 = NULL ;
V_107 -> V_14 = V_185 ;
V_107 -> V_110 = NULL ;
F_27 ( & V_2 -> V_173 ) ;
return 0 ;
}
static T_3 F_37 ( struct V_123 * V_124 )
{
struct V_179 * V_126 = V_124 -> V_126 ;
struct V_106 * V_107 = V_126 -> V_127 ;
return ( T_3 ) ( ( V_107 -> V_121 * V_126 -> V_193 ) + V_107 -> V_122 ) ;
}
static void F_38 ( struct V_50 * V_51 , struct V_180 * V_129 )
{
#if 0
struct snd_pcm_substream *subs;
int stream;
for (stream = 0; stream < 2; stream++) {
int idx = 0;
for (subs = pcm->streams[stream].substream; subs; subs = subs->next, idx++)
subs->dma_device.id = subs->pcm->device << 16 |
subs->stream << 8 | (subs->number + 1) |
(chip->chip_idx + 1) << 24;
}
#endif
F_39 ( V_129 , V_194 ,
F_40 ( V_51 -> V_2 -> V_18 ) , 32 * 1024 , 32 * 1024 ) ;
}
static int F_41 ( struct V_50 * V_51 )
{
int V_12 ;
struct V_180 * V_129 ;
char V_195 [ 32 ] ;
sprintf ( V_195 , L_31 , V_51 -> V_74 ) ;
if ( ( V_12 = F_42 ( V_51 -> V_73 , V_195 , V_56 ,
V_64 ,
V_60 , & V_129 ) ) < 0 ) {
F_2 ( V_51 -> V_73 -> V_19 ,
L_32 , V_51 -> V_74 ) ;
return V_12 ;
}
V_129 -> V_127 = V_51 ;
F_43 ( V_129 , V_115 , & V_196 ) ;
F_43 ( V_129 , V_176 , & V_197 ) ;
V_129 -> V_198 = 0 ;
V_129 -> V_199 = true ;
strcpy ( V_129 -> V_195 , V_195 ) ;
F_38 ( V_51 , V_129 ) ;
V_51 -> V_129 = V_129 ;
return 0 ;
}
static int F_44 ( struct V_50 * V_51 )
{
int V_12 ;
struct V_180 * V_129 ;
char V_195 [ 32 ] ;
sprintf ( V_195 , L_33 , V_51 -> V_74 ) ;
if ( ( V_12 = F_42 ( V_51 -> V_73 , V_195 , V_174 ,
V_64 ,
V_60 , & V_129 ) ) < 0 ) {
F_2 ( V_51 -> V_73 -> V_19 ,
L_34 , V_51 -> V_74 ) ;
return V_12 ;
}
V_129 -> V_127 = V_51 ;
F_43 ( V_129 , V_115 , & V_196 ) ;
F_43 ( V_129 , V_176 , & V_197 ) ;
V_129 -> V_198 = 0 ;
V_129 -> V_199 = true ;
strcpy ( V_129 -> V_195 , V_195 ) ;
F_38 ( V_51 , V_129 ) ;
V_51 -> V_182 = V_129 ;
return 0 ;
}
static int F_45 ( struct V_50 * V_51 )
{
F_9 ( V_51 ) ;
return 0 ;
}
static int F_46 ( struct V_200 * V_201 )
{
struct V_50 * V_51 = V_201 -> V_202 ;
return F_45 ( V_51 ) ;
}
static int F_47 ( struct V_1 * V_2 , struct V_203 * V_73 , int V_204 )
{
int V_12 ;
struct V_50 * V_51 ;
static struct V_205 V_206 = {
. V_207 = F_46 ,
} ;
V_51 = F_48 ( sizeof( * V_51 ) , V_75 ) ;
if ( ! V_51 ) {
F_2 ( V_73 -> V_19 , L_35 ) ;
return - V_208 ;
}
V_51 -> V_73 = V_73 ;
V_51 -> V_74 = V_204 ;
V_51 -> V_2 = V_2 ;
if ( ( V_12 = F_49 ( V_73 , V_209 , V_51 , & V_206 ) ) < 0 ) {
F_45 ( V_51 ) ;
return V_12 ;
}
V_2 -> V_51 [ V_204 ] = V_51 ;
return 0 ;
}
int F_50 ( struct V_50 * V_51 )
{
int V_12 ;
V_12 = F_41 ( V_51 ) ;
if ( V_12 < 0 )
return V_12 ;
if( V_51 -> V_2 -> V_210 == V_211 ) {
V_12 = F_44 ( V_51 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return V_12 ;
}
static int F_51 ( struct V_1 * V_2 )
{
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_212 ; V_67 ++ ) {
if ( V_2 -> V_51 [ V_67 ] )
F_52 ( V_2 -> V_51 [ V_67 ] -> V_73 ) ;
}
F_53 ( V_2 ) ;
if ( V_2 -> V_213 >= 0 )
F_54 ( V_2 -> V_213 , V_2 ) ;
if( V_2 -> V_214 ) {
F_55 ( V_2 ) ;
F_6 ( & V_2 -> V_18 -> V_19 , L_36 ) ;
}
for ( V_67 = 0 ; V_67 < 2 ; ++ V_67 )
F_56 ( V_2 -> V_215 [ V_67 ] . V_216 ) ;
F_57 ( V_2 -> V_18 ) ;
if( V_2 -> V_82 . V_92 ) {
F_58 ( & V_2 -> V_82 ) ;
V_2 -> V_82 . V_92 = NULL ;
}
if( V_2 -> V_84 . V_92 ) {
F_58 ( & V_2 -> V_84 ) ;
V_2 -> V_84 . V_92 = NULL ;
}
F_59 ( V_2 -> V_18 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static T_4 F_60 ( struct V_217 * V_218 ,
void * V_219 ,
struct V_220 * V_220 , char T_5 * V_72 ,
T_6 V_221 , T_7 V_222 )
{
struct V_1 * V_2 = V_218 -> V_127 ;
V_221 = V_221 & ~ 3 ;
if ( F_61 ( V_72 , F_62 ( V_2 , V_222 ) , V_221 ) )
return - V_223 ;
return V_221 ;
}
static T_4 F_63 ( struct V_217 * V_218 ,
void * V_219 ,
struct V_220 * V_220 , char T_5 * V_72 ,
T_6 V_221 , T_7 V_222 )
{
struct V_1 * V_2 = V_218 -> V_127 ;
V_221 = V_221 & ~ 3 ;
if ( F_61 ( V_72 , F_64 ( V_2 , V_222 ) , V_221 ) )
return - V_223 ;
return V_221 ;
}
static void F_65 ( struct V_217 * V_218 ,
struct V_224 * V_225 )
{
struct V_50 * V_51 = V_218 -> V_127 ;
T_1 V_226 ;
F_66 ( V_225 , L_37 , V_51 -> V_74 ) ;
if ( V_51 -> V_2 -> V_214 & ( 1 << V_227 ) ) {
F_66 ( V_225 , L_38 ) ;
switch ( V_51 -> V_2 -> V_210 ) {
case V_228 : F_66 ( V_225 , L_39 ) ; break;
case V_211 : F_66 ( V_225 , L_40 ) ; break;
case V_229 : F_66 ( V_225 , L_41 ) ; break;
default: F_66 ( V_225 , L_42 ) ; break;
}
F_66 ( V_225 , L_43 ) ;
V_226 = F_67 ( F_62 ( V_51 -> V_2 , V_230 ) ) ;
if ( V_226 ) {
T_1 V_231 = 100 * F_67 ( F_62 ( V_51 -> V_2 , V_232 ) ) / V_226 ;
T_1 V_233 = 100 * F_67 ( F_62 ( V_51 -> V_2 , V_234 ) ) / V_226 ;
T_1 V_235 = 100 * F_67 ( F_62 ( V_51 -> V_2 , V_236 ) ) / V_226 ;
F_66 ( V_225 , L_44 , V_233 ) ;
F_66 ( V_225 , L_45 , V_231 ) ;
F_66 ( V_225 , L_46 , V_235 ) ;
}
}
}
static void F_68 ( struct V_50 * V_51 )
{
struct V_217 * V_218 ;
if ( ! F_69 ( V_51 -> V_73 , L_47 , & V_218 ) ) {
V_218 -> V_127 = V_51 ;
V_218 -> V_237 . V_238 . V_239 = F_65 ;
}
if ( ! F_69 ( V_51 -> V_73 , L_48 , & V_218 ) ) {
V_218 -> V_240 = V_241 ;
V_218 -> V_127 = V_51 -> V_2 ;
V_218 -> V_237 . V_206 = & V_242 ;
V_218 -> V_26 = V_243 ;
}
if ( ! F_69 ( V_51 -> V_73 , L_49 , & V_218 ) ) {
V_218 -> V_240 = V_241 ;
V_218 -> V_127 = V_51 -> V_2 ;
V_218 -> V_237 . V_206 = & V_244 ;
V_218 -> V_26 = V_245 ;
}
}
static int F_70 ( struct V_246 * V_18 ,
const struct V_247 * V_248 )
{
static int V_19 ;
struct V_1 * V_2 ;
unsigned int V_67 ;
int V_12 ;
T_6 V_26 ;
if ( V_19 >= V_249 )
return - V_250 ;
if ( ! V_251 [ V_19 ] ) {
V_19 ++ ;
return - V_252 ;
}
if ( ( V_12 = F_71 ( V_18 ) ) < 0 )
return V_12 ;
F_72 ( V_18 ) ;
if ( F_73 ( & V_18 -> V_19 , F_74 ( 32 ) ) < 0 ) {
F_2 ( & V_18 -> V_19 ,
L_50 ) ;
F_59 ( V_18 ) ;
return - V_253 ;
}
V_2 = F_48 ( sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 ) {
F_59 ( V_18 ) ;
return - V_208 ;
}
V_2 -> V_18 = V_18 ;
V_2 -> V_213 = - 1 ;
if ( ( V_12 = F_75 ( V_18 , V_254 ) ) < 0 ) {
F_9 ( V_2 ) ;
F_59 ( V_18 ) ;
return V_12 ;
}
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
V_2 -> V_215 [ V_67 ] . V_255 = F_76 ( V_18 , V_67 ) ;
V_2 -> V_215 [ V_67 ] . V_216 = F_77 ( V_18 , V_67 ) ;
if ( ! V_2 -> V_215 [ V_67 ] . V_216 ) {
F_2 ( & V_18 -> V_19 , L_51 ,
V_2 -> V_215 [ V_67 ] . V_255 ) ;
F_51 ( V_2 ) ;
return - V_140 ;
}
}
if ( F_78 ( V_18 -> V_213 , V_256 ,
V_257 , V_258 ,
V_259 , V_2 ) ) {
F_2 ( & V_18 -> V_19 , L_52 , V_18 -> V_213 ) ;
F_51 ( V_2 ) ;
return - V_140 ;
}
V_2 -> V_213 = V_18 -> V_213 ;
sprintf ( V_2 -> V_260 , L_53 ) ;
sprintf ( V_2 -> V_261 , L_54 , V_2 -> V_260 , V_2 -> V_215 [ 0 ] . V_255 , V_2 -> V_215 [ 1 ] . V_255 , V_2 -> V_213 ) ;
V_2 -> V_262 = 0 ;
V_2 -> V_263 = 0 ;
F_79 ( & V_2 -> V_264 ) ;
F_79 ( & V_2 -> V_265 ) ;
F_80 ( & V_2 -> V_266 ) ;
F_81 ( & V_2 -> V_139 , 0 ) ;
F_79 ( & V_2 -> V_173 ) ;
V_2 -> V_212 = V_267 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_212 ; V_67 ++ ) {
struct V_203 * V_73 ;
char V_268 [ 16 ] ;
int V_204 ;
if ( V_269 [ V_19 ] < 0 )
V_204 = V_269 [ V_19 ] ;
else
V_204 = V_269 [ V_19 ] + V_67 ;
snprintf ( V_268 , sizeof( V_268 ) , L_55 , V_270 [ V_19 ] ? V_270 [ V_19 ] : L_56 , V_67 ) ;
V_12 = F_82 ( & V_18 -> V_19 , V_204 , V_268 , V_271 ,
0 , & V_73 ) ;
if ( V_12 < 0 ) {
F_2 ( & V_18 -> V_19 , L_57 , V_67 ) ;
F_51 ( V_2 ) ;
return V_12 ;
}
strcpy ( V_73 -> V_272 , V_254 ) ;
sprintf ( V_73 -> V_260 , L_58 , V_2 -> V_260 , V_67 ) ;
sprintf ( V_73 -> V_261 , L_58 , V_2 -> V_261 , V_67 ) ;
if ( ( V_12 = F_47 ( V_2 , V_73 , V_67 ) ) < 0 ) {
F_52 ( V_73 ) ;
F_51 ( V_2 ) ;
return V_12 ;
}
if( V_67 == 0 ) {
F_68 ( V_2 -> V_51 [ V_67 ] ) ;
}
if ( ( V_12 = F_83 ( V_73 ) ) < 0 ) {
F_51 ( V_2 ) ;
return V_12 ;
}
}
V_2 -> V_210 = V_228 ;
V_26 = F_84 ( ( V_90 * V_267 *
sizeof( struct V_81 ) ) ) ;
if ( F_85 ( V_194 , F_40 ( V_18 ) ,
V_26 , & V_2 -> V_82 ) < 0 ) {
F_51 ( V_2 ) ;
return - V_208 ;
}
memset ( V_2 -> V_82 . V_92 , 0 , V_26 ) ;
V_26 = F_84 ( ( V_90 * V_267 *
sizeof( struct V_83 ) ) ) ;
if ( F_85 ( V_194 , F_40 ( V_18 ) ,
V_26 , & V_2 -> V_84 ) < 0 ) {
F_51 ( V_2 ) ;
return - V_208 ;
}
memset ( V_2 -> V_84 . V_92 , 0 , V_26 ) ;
V_12 = F_86 ( V_2 ) ;
if ( V_12 < 0 ) {
F_51 ( V_2 ) ;
return V_12 ;
}
F_87 ( V_18 , V_2 ) ;
V_19 ++ ;
return 0 ;
}
static void F_88 ( struct V_246 * V_18 )
{
F_51 ( F_89 ( V_18 ) ) ;
}
