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
F_2 ( V_18 L_1 ) ;
return - V_19 ;
}
V_13 = 0x12345678 ;
V_11 . V_20 = V_21 ;
V_11 . V_22 = (struct V_23 ) { 0 , 0 } ;
V_11 . V_24 = & V_13 ;
V_11 . V_25 = sizeof( V_13 ) ;
V_12 = F_3 ( V_2 , & V_11 , V_13 ) ;
if( V_12 ) {
F_2 ( V_18 L_2 ) ;
return V_12 ;
}
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_26 = 1 ;
V_7 . V_27 [ 0 ] = V_4 -> V_28 ;
if( V_5 )
V_11 . V_20 = V_29 ;
else
V_11 . V_20 = V_30 ;
V_11 . V_22 = V_4 -> V_28 ;
V_11 . V_24 = & V_7 ;
V_11 . V_25 = sizeof( V_7 ) ;
V_12 = F_4 ( V_2 , & V_11 , sizeof( V_9 ) , & V_9 ) ;
if ( V_12 < 0 || V_9 . V_31 != 0 ) {
F_2 ( V_18 L_3 , V_12 , V_9 . V_31 ) ;
return - V_19 ;
}
if( V_5 ) {
T_1 V_32 ;
V_7 . V_26 = 0 ;
V_12 = F_4 ( V_2 , & V_11 , sizeof( V_9 ) , & V_9 ) ;
if ( V_12 < 0 || V_9 . V_31 != 0 ) {
F_2 ( V_18 L_4 , V_12 , V_9 . V_31 ) ;
return - V_19 ;
}
V_11 . V_20 = V_33 ;
V_11 . V_22 = (struct V_23 ) { 0 , 0 } ;
V_11 . V_24 = NULL ;
V_11 . V_25 = 0 ;
V_12 = F_4 ( V_2 , & V_11 , sizeof( V_32 ) , & V_32 ) ;
if ( V_12 < 0 || V_32 != 0 ) {
F_2 ( V_18 L_5 , V_12 , V_32 ) ;
return - V_19 ;
}
V_4 -> V_14 = V_15 ;
}
else
V_4 -> V_14 = V_17 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_34 )
{
struct V_10 V_11 ;
struct V_35 V_36 ;
struct V_37 V_38 ;
int V_12 ;
switch( V_4 -> V_14 ) {
case V_16 :
break;
case V_15 :
if( V_34 != 0 )
break;
default:
if( V_34 == 0 )
return 0 ;
else {
F_2 ( V_18 L_6 , V_34 ) ;
return - V_19 ;
}
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_39 = ( V_34 != 0 ) ? V_40 : V_41 ;
V_36 . V_42 = V_43 ;
V_36 . V_44 = V_34 ;
V_36 . V_45 = 1 ;
V_36 . V_46 [ 0 ] = V_4 -> V_28 ;
F_6 ( L_7 , V_34 ) ;
V_11 . V_20 = V_47 ;
V_11 . V_22 = V_2 -> V_48 ;
V_11 . V_24 = & V_36 ;
V_11 . V_25 = sizeof( V_36 ) ;
V_12 = F_4 ( V_2 , & V_11 , sizeof( V_38 ) , & V_38 ) ;
if ( V_12 < 0 || V_38 . V_14 != 0 || V_38 . V_42 != V_43 ) {
F_2 ( V_18 L_8 , V_12 , V_38 . V_14 , V_38 . V_42 ) ;
return - V_19 ;
}
if( V_34 ) V_4 -> V_14 = V_16 ;
else V_4 -> V_14 = V_15 ;
return 0 ;
}
struct V_3 *
F_7 ( struct V_49 * V_50 , int V_51 , int V_52 ,
int V_53 )
{
int V_54 ;
struct V_3 * V_4 ;
struct V_10 V_11 ;
if( V_52 ) {
if ( V_51 == V_55 ) {
V_4 = & ( V_50 -> V_56 ) ;
} else {
V_4 = & ( V_50 -> V_57 ) ;
}
V_11 . V_20 = V_58 ;
V_54 = V_59 ;
} else {
if ( V_51 == V_55 ) {
V_4 = & ( V_50 -> V_60 ) ;
} else {
V_4 = & ( V_50 -> V_61 ) ;
}
V_11 . V_20 = V_62 ;
V_54 = V_63 ;
}
if( ( V_53 == 0 ) && ( V_4 -> V_64 >= V_54 ) ) {
return NULL ;
}
if( V_4 -> V_14 == V_65 ) {
int V_12 , V_66 ;
struct {
struct V_67 V_68 ;
struct V_69 V_70 ;
} * V_71 ;
F_6 ( L_9 , V_50 -> V_72 , V_51 ) ;
V_71 = F_8 ( sizeof( * V_71 ) , V_73 ) ;
if ( ! V_71 )
return NULL ;
V_11 . V_22 = (struct V_23 ) { 0 , 0 } ;
V_11 . V_24 = & V_71 -> V_68 ;
V_11 . V_25 = sizeof( V_71 -> V_68 ) ;
memset ( & V_71 -> V_68 , 0 , sizeof( V_71 -> V_68 ) ) ;
V_71 -> V_68 . V_54 = V_54 ;
V_71 -> V_68 . V_74 = 2 ;
V_71 -> V_68 . V_75 = 256 ;
V_71 -> V_68 . V_76 = V_4 -> V_77 ;
for ( V_66 = 0 ; V_66 < V_54 ; V_66 ++ ) {
int V_78 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
V_71 -> V_68 . V_83 [ V_66 ] . V_84 = 1024 ;
V_71 -> V_68 . V_83 [ V_66 ] . V_85 = 256 ;
V_71 -> V_68 . V_83 [ V_66 ] . V_86 = V_87 ;
V_78 = ( V_50 -> V_72 * V_88 ) + ( V_51 * ( V_63 + V_59 ) ) + V_66 ;
if( V_52 ) V_78 += V_63 ;
V_71 -> V_68 . V_89 [ V_66 ] = V_78 ;
V_80 = (struct V_79 * ) V_50 -> V_2 -> V_80 . V_90 ;
V_80 [ V_78 ] . V_91 = ( T_1 ) V_50 -> V_2 -> V_82 . V_92 + ( V_78 * sizeof( struct V_81 ) ) ;
V_80 [ V_78 ] . V_93 = 1 ;
V_82 = (struct V_81 * ) V_50 -> V_2 -> V_82 . V_90 ;
V_82 [ V_78 ] . V_94 = 0 ;
V_82 [ V_78 ] . V_95 = 0 ;
V_82 [ V_78 ] . V_96 = ( V_50 -> V_72 << V_97 ) + ( V_51 << V_98 ) + V_66 ;
if( V_52 ) {
V_82 [ V_78 ] . V_96 |= V_99 ;
}
}
V_12 = F_4 ( V_50 -> V_2 , & V_11 , sizeof( V_71 -> V_70 ) , & V_71 -> V_70 ) ;
if( ( V_12 < 0 ) || ( V_71 -> V_70 . V_14 != 0 ) ) {
F_2 ( V_18 L_10 , V_12 , V_71 -> V_70 . V_14 ) ;
F_9 ( V_71 ) ;
return NULL ;
}
V_4 -> V_28 = V_71 -> V_70 . V_100 ;
V_4 -> V_54 = V_71 -> V_70 . V_54 ;
V_4 -> V_14 = V_17 ;
F_9 ( V_71 ) ;
}
if( V_53 ) V_4 -> V_53 = 1 ;
else V_4 -> V_64 ++ ;
return V_4 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_53 )
{
int V_12 = 0 ;
if( V_4 -> V_14 == V_65 )
return 0 ;
if( V_53 )
V_4 -> V_53 = 0 ;
else
V_4 -> V_64 -- ;
if( ( V_4 -> V_64 <= 0 ) && ( V_4 -> V_53 == 0 ) ) {
struct V_10 V_11 ;
struct V_101 V_102 ;
V_12 = F_5 ( V_2 , V_4 , 0 ) ;
if( V_12 < 0 ) {
F_2 ( V_18 L_11 ) ;
}
V_12 = F_1 ( V_2 , V_4 , 0 ) ;
if( V_12 < 0 ) {
F_2 ( V_18 L_12 ) ;
}
V_11 . V_20 = V_103 ;
V_11 . V_22 = (struct V_23 ) { 0 , 0 } ;
V_11 . V_24 = & V_4 -> V_28 ;
V_11 . V_25 = sizeof( V_4 -> V_28 ) ;
V_12 = F_4 ( V_2 , & V_11 , sizeof( V_102 ) , & V_102 ) ;
if ( ( V_12 < 0 ) || ( V_102 . V_14 != 0 ) ) {
F_2 ( V_18 L_13 , V_12 , V_102 . V_14 ) ;
}
V_4 -> V_28 = (struct V_23 ) { 0 , 0 } ;
V_4 -> V_54 = 0 ;
V_4 -> V_14 = V_65 ;
}
return V_12 ;
}
static int F_11 ( struct V_104 * V_105 , int V_5 )
{
struct V_49 * V_50 ;
struct V_106 V_107 ;
struct V_10 V_11 ;
if( ! V_105 -> V_108 )
return - V_19 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
V_107 . V_54 = 1 ;
V_107 . V_83 . V_109 . V_110 = V_105 -> V_4 -> V_28 ;
V_107 . V_83 . V_109 . V_111 = V_105 -> V_108 -> V_112 ;
if ( V_105 -> V_108 -> V_105 == V_113 )
V_11 . V_20 = V_5 ? V_114 : V_115 ;
else
V_11 . V_20 = V_5 ? V_116 : V_117 ;
V_11 . V_22 = (struct V_23 ) { 0 , 0 } ;
V_11 . V_24 = & V_107 ;
V_11 . V_25 = sizeof( V_107 ) ;
V_105 -> V_118 = 0 ;
V_105 -> V_119 = 0 ;
V_105 -> V_120 = 0 ;
V_50 = F_12 ( V_105 -> V_108 ) ;
return F_13 ( V_50 -> V_2 , & V_11 ) ;
}
static int F_14 ( struct V_121 * V_122 , int V_123 )
{
struct V_104 * V_105 = V_122 -> V_124 -> V_125 ;
switch ( V_123 ) {
case V_126 :
F_6 ( L_14 ) ;
if( F_11 ( V_105 , 1 ) )
return - V_19 ;
V_105 -> V_14 = V_127 ;
break;
case V_128 :
if( F_11 ( V_105 , 0 ) )
return - V_19 ;
V_105 -> V_14 = V_129 ;
F_6 ( L_15 ) ;
break;
case V_130 :
V_105 -> V_14 = V_131 ;
F_6 ( L_16 ) ;
break;
case V_132 :
V_105 -> V_14 = V_127 ;
F_6 ( L_17 ) ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_133 = V_134 + V_135 ;
while ( F_16 ( & V_2 -> V_136 ) > 0 ) {
if ( F_17 ( V_134 , V_133 ) ) {
F_2 ( V_18 L_18 ) ;
return - V_137 ;
}
F_18 ( 1 ) ;
}
return 0 ;
}
static int F_19 ( struct V_121 * V_122 )
{
struct V_49 * V_50 = F_12 ( V_122 ) ;
struct V_104 * V_105 = V_122 -> V_124 -> V_125 ;
F_6 ( L_19 ) ;
F_15 ( V_50 -> V_2 ) ;
if( V_50 -> V_2 -> V_138 == 1 )
V_50 -> V_2 -> V_139 = V_122 -> V_124 -> V_34 ;
if( V_105 -> V_4 -> V_64 == 1 ) {
if( F_5 ( V_50 -> V_2 , V_105 -> V_4 , V_122 -> V_124 -> V_34 ) )
return - V_19 ;
}
return 0 ;
}
static int F_20 ( struct V_104 * V_105 , T_2 V_140 )
{
int V_12 ;
struct V_49 * V_50 ;
struct V_10 V_11 ;
struct V_141 V_142 ;
struct V_143 V_144 ;
V_50 = F_12 ( V_105 -> V_108 ) ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_145 = V_146 ;
V_142 . V_147 = V_105 -> V_148 ;
V_142 . V_149 = V_50 -> V_2 -> V_139 ;
if( V_142 . V_149 == 0 )
V_142 . V_149 = 44100 ;
switch( V_140 ) {
case V_150 :
V_142 . V_151 = V_152 ;
V_142 . V_153 = 8 ;
break;
case V_154 :
V_142 . V_151 = V_155 ;
V_142 . V_153 = 16 ;
break;
case V_156 :
V_142 . V_151 = V_157 ;
V_142 . V_153 = 16 ;
break;
case V_158 :
V_142 . V_151 = V_159 ;
V_142 . V_153 = 24 ;
break;
case V_160 :
V_142 . V_151 = V_161 ;
V_142 . V_153 = 24 ;
break;
case V_162 :
V_142 . V_151 = V_163 ;
V_142 . V_153 = 32 ;
break;
case V_164 :
V_142 . V_151 = V_165 ;
V_142 . V_153 = 32 ;
break;
default:
F_2 ( V_18 L_20 ) ;
return - V_19 ;
}
F_6 ( L_21 ,
V_142 . V_151 , V_142 . V_153 , V_142 . V_149 , V_105 -> V_148 ) ;
V_142 . V_26 = 1 ;
V_142 . V_54 = 1 ;
V_142 . V_109 [ 0 ] . V_110 = V_105 -> V_4 -> V_28 ;
V_142 . V_109 [ 0 ] . V_111 = V_105 -> V_108 -> V_112 ;
V_11 . V_20 = V_166 ;
V_11 . V_22 = (struct V_23 ) { 0 , 0 } ;
V_11 . V_24 = & V_142 ;
V_11 . V_25 = sizeof( V_142 ) ;
V_12 = F_4 ( V_50 -> V_2 , & V_11 , sizeof( V_144 ) , & V_144 ) ;
if( ( V_12 < 0 ) || V_144 . V_167 ) {
F_2 ( V_18 L_22 , V_12 , V_144 . V_167 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_21 ( struct V_121 * V_122 ,
struct V_168 * V_169 )
{
struct V_49 * V_50 = F_12 ( V_122 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_104 * V_105 = V_122 -> V_124 -> V_125 ;
T_2 V_140 ;
int V_12 ;
int V_148 ;
V_148 = F_22 ( V_169 ) ;
V_140 = F_23 ( V_169 ) ;
F_24 ( & V_2 -> V_170 ) ;
if( V_105 -> V_51 <= V_171 ) {
int V_172 = V_105 -> V_51 > V_55 ;
if( V_122 -> V_105 == V_113 )
F_25 ( V_50 , V_172 , V_122 -> V_112 ) ;
else
F_26 ( V_50 , V_172 ) ;
}
V_105 -> V_148 = V_148 ;
V_12 = F_20 ( V_105 , V_140 ) ;
if( V_12 < 0 ) {
F_27 ( & V_2 -> V_170 ) ;
return V_12 ;
}
V_12 = F_28 ( V_122 , F_29 ( V_169 ) ) ;
if ( V_12 > 0 ) {
struct V_81 * V_82 ;
int V_66 = ( V_50 -> V_72 * V_88 ) + ( V_105 -> V_51 * ( V_63 + V_59 ) ) + V_122 -> V_112 ;
if( V_122 -> V_105 == V_173 ) {
V_66 += V_63 ;
}
V_82 = (struct V_81 * ) V_50 -> V_2 -> V_82 . V_90 ;
V_82 [ V_66 ] . V_94 = V_122 -> V_124 -> V_174 ;
V_82 [ V_66 ] . V_95 = V_122 -> V_124 -> V_175 ;
F_6 ( L_23 , V_66 ,
V_82 [ V_66 ] . V_94 ,
V_82 [ V_66 ] . V_95 ,
V_122 -> V_112 ) ;
}
F_27 ( & V_2 -> V_170 ) ;
return V_12 ;
}
static int F_30 ( struct V_121 * V_122 )
{
struct V_49 * V_50 = F_12 ( V_122 ) ;
F_31 ( V_122 ) ;
F_15 ( V_50 -> V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_121 * V_122 )
{
struct V_49 * V_50 = F_12 ( V_122 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_176 * V_124 = V_122 -> V_124 ;
struct V_177 * V_178 = V_122 -> V_178 ;
struct V_104 * V_105 ;
struct V_3 * V_4 ;
int V_12 = 0 ;
int V_51 ;
F_24 ( & V_2 -> V_170 ) ;
if ( V_178 == V_50 -> V_178 ) {
V_51 = V_55 ;
V_124 -> V_169 = V_179 ;
} else {
F_33 ( V_178 != V_50 -> V_180 ) ;
V_51 = V_171 ;
V_124 -> V_169 = V_181 ;
}
F_6 ( L_24 , V_50 -> V_72 , V_51 , V_122 -> V_112 ) ;
V_105 = & ( V_50 -> V_182 [ V_51 ] [ V_122 -> V_112 ] ) ;
if ( V_105 -> V_14 != V_183 ) {
F_2 ( V_18 L_25 , V_50 -> V_72 , V_51 , V_122 -> V_112 ) ;
V_12 = - V_137 ;
goto V_184;
}
V_4 = F_7 ( V_50 , V_51 , 0 , 0 ) ;
if ( V_4 == NULL ) {
V_12 = - V_19 ;
goto V_184;
}
V_12 = F_1 ( V_50 -> V_2 , V_4 , 1 ) ;
if( V_12 < 0 ) {
F_2 ( V_18 L_26 ) ;
F_10 ( V_50 -> V_2 , V_4 , 0 ) ;
V_12 = - V_19 ;
goto V_184;
}
V_105 -> V_4 = V_4 ;
V_105 -> V_51 = V_51 ;
V_105 -> V_14 = V_129 ;
V_105 -> V_108 = V_122 ;
V_105 -> V_148 = 0 ;
V_124 -> V_125 = V_105 ;
F_34 ( V_124 , 0 , V_185 , 32 ) ;
F_34 ( V_124 , 0 , V_186 , 64 ) ;
if( V_2 -> V_138 ++ ) {
if( V_2 -> V_139 ) {
V_124 -> V_169 . V_187 = V_124 -> V_169 . V_188 = V_2 -> V_139 ;
}
}
V_184:
F_27 ( & V_2 -> V_170 ) ;
return V_12 ;
}
static int F_35 ( struct V_121 * V_122 )
{
struct V_49 * V_50 = F_12 ( V_122 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_176 * V_124 = V_122 -> V_124 ;
struct V_177 * V_178 = V_122 -> V_178 ;
struct V_104 * V_105 ;
struct V_3 * V_4 ;
int V_12 = 0 ;
int V_51 ;
F_24 ( & V_2 -> V_170 ) ;
if ( V_178 == V_50 -> V_178 ) {
V_51 = V_55 ;
V_124 -> V_169 = V_179 ;
} else {
F_33 ( V_178 != V_50 -> V_180 ) ;
V_51 = V_171 ;
V_124 -> V_169 = V_181 ;
}
V_124 -> V_169 . V_189 = 2 ;
F_6 ( L_27 , V_50 -> V_72 , V_51 , V_122 -> V_112 ) ;
V_105 = & ( V_50 -> V_190 [ V_51 ] ) ;
if ( V_105 -> V_14 != V_183 ) {
F_2 ( V_18 L_28 , V_50 -> V_72 , V_51 , V_122 -> V_112 ) ;
V_12 = - V_137 ;
goto V_184;
}
V_4 = F_7 ( V_50 , V_51 , 1 , 0 ) ;
if ( V_4 == NULL ) {
V_12 = - V_19 ;
goto V_184;
}
V_12 = F_1 ( V_50 -> V_2 , V_4 , 1 ) ;
if( V_12 < 0 ) {
F_2 ( V_18 L_26 ) ;
F_10 ( V_50 -> V_2 , V_4 , 0 ) ;
V_12 = - V_19 ;
goto V_184;
}
V_105 -> V_4 = V_4 ;
V_105 -> V_51 = V_51 ;
V_105 -> V_14 = V_129 ;
V_105 -> V_108 = V_122 ;
V_105 -> V_148 = 0 ;
V_124 -> V_125 = V_105 ;
F_34 ( V_124 , 0 , V_185 , 32 ) ;
F_34 ( V_124 , 0 , V_186 , 64 ) ;
if( V_2 -> V_138 ++ ) {
if( V_2 -> V_139 ) {
V_124 -> V_169 . V_187 = V_124 -> V_169 . V_188 = V_2 -> V_139 ;
}
}
V_184:
F_27 ( & V_2 -> V_170 ) ;
return V_12 ;
}
static int F_36 ( struct V_121 * V_122 )
{
struct V_49 * V_50 = F_12 ( V_122 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_104 * V_105 = V_122 -> V_124 -> V_125 ;
F_24 ( & V_2 -> V_170 ) ;
F_6 ( L_29 , V_50 -> V_72 , V_105 -> V_51 , V_122 -> V_112 ) ;
if( -- V_2 -> V_138 == 0 ) {
V_2 -> V_139 = 0 ;
}
if ( F_10 ( V_2 , V_105 -> V_4 , 0 ) < 0 ) {
F_2 ( V_18 L_30 , V_50 -> V_72 , V_105 -> V_51 ) ;
}
V_105 -> V_4 = NULL ;
V_105 -> V_14 = V_183 ;
V_105 -> V_108 = NULL ;
F_27 ( & V_2 -> V_170 ) ;
return 0 ;
}
static T_3 F_37 ( struct V_121 * V_122 )
{
struct V_176 * V_124 = V_122 -> V_124 ;
struct V_104 * V_105 = V_124 -> V_125 ;
return ( T_3 ) ( ( V_105 -> V_119 * V_124 -> V_191 ) + V_105 -> V_120 ) ;
}
static void F_38 ( struct V_49 * V_50 , struct V_177 * V_178 )
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
F_39 ( V_178 , V_192 ,
F_40 ( V_50 -> V_2 -> V_193 ) , 32 * 1024 , 32 * 1024 ) ;
}
static int F_41 ( struct V_49 * V_50 )
{
int V_12 ;
struct V_177 * V_178 ;
char V_194 [ 32 ] ;
sprintf ( V_194 , L_31 , V_50 -> V_72 ) ;
if ( ( V_12 = F_42 ( V_50 -> V_195 , V_194 , V_55 ,
V_63 ,
V_59 , & V_178 ) ) < 0 ) {
F_2 ( V_18 L_32 , V_50 -> V_72 ) ;
return V_12 ;
}
V_178 -> V_125 = V_50 ;
F_43 ( V_178 , V_113 , & V_196 ) ;
F_43 ( V_178 , V_173 , & V_197 ) ;
V_178 -> V_198 = 0 ;
strcpy ( V_178 -> V_194 , V_194 ) ;
F_38 ( V_50 , V_178 ) ;
V_50 -> V_178 = V_178 ;
return 0 ;
}
static int F_44 ( struct V_49 * V_50 )
{
int V_12 ;
struct V_177 * V_178 ;
char V_194 [ 32 ] ;
sprintf ( V_194 , L_33 , V_50 -> V_72 ) ;
if ( ( V_12 = F_42 ( V_50 -> V_195 , V_194 , V_171 ,
V_63 ,
V_59 , & V_178 ) ) < 0 ) {
F_2 ( V_18 L_34 , V_50 -> V_72 ) ;
return V_12 ;
}
V_178 -> V_125 = V_50 ;
F_43 ( V_178 , V_113 , & V_196 ) ;
F_43 ( V_178 , V_173 , & V_197 ) ;
V_178 -> V_198 = 0 ;
strcpy ( V_178 -> V_194 , V_194 ) ;
F_38 ( V_50 , V_178 ) ;
V_50 -> V_180 = V_178 ;
return 0 ;
}
static int F_45 ( struct V_49 * V_50 )
{
F_9 ( V_50 ) ;
return 0 ;
}
static int F_46 ( struct V_199 * V_200 )
{
struct V_49 * V_50 = V_200 -> V_201 ;
return F_45 ( V_50 ) ;
}
static int T_4 F_47 ( struct V_1 * V_2 , struct V_202 * V_195 , int V_203 )
{
int V_12 ;
struct V_49 * V_50 ;
static struct V_204 V_205 = {
. V_206 = F_46 ,
} ;
V_50 = F_48 ( sizeof( * V_50 ) , V_73 ) ;
if ( ! V_50 ) {
F_2 ( V_18 L_35 ) ;
return - V_207 ;
}
V_50 -> V_195 = V_195 ;
V_50 -> V_72 = V_203 ;
V_50 -> V_2 = V_2 ;
if ( ( V_12 = F_49 ( V_195 , V_208 , V_50 , & V_205 ) ) < 0 ) {
F_45 ( V_50 ) ;
return V_12 ;
}
V_2 -> V_50 [ V_203 ] = V_50 ;
F_50 ( V_195 , & V_2 -> V_193 -> V_209 ) ;
return 0 ;
}
int F_51 ( struct V_49 * V_50 )
{
int V_12 ;
V_12 = F_41 ( V_50 ) ;
if ( V_12 < 0 )
return V_12 ;
if( V_50 -> V_2 -> V_210 == V_211 ) {
V_12 = F_44 ( V_50 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return V_12 ;
}
static int F_52 ( struct V_1 * V_2 )
{
unsigned int V_66 ;
for ( V_66 = 0 ; V_66 < V_2 -> V_212 ; V_66 ++ ) {
if ( V_2 -> V_50 [ V_66 ] )
F_53 ( V_2 -> V_50 [ V_66 ] -> V_195 ) ;
}
F_54 ( V_2 ) ;
if ( V_2 -> V_213 >= 0 )
F_55 ( V_2 -> V_213 , V_2 ) ;
if( V_2 -> V_214 ) {
F_56 ( V_2 ) ;
F_6 ( L_36 ) ;
}
for ( V_66 = 0 ; V_66 < 2 ; V_66 ++ ) {
if ( V_2 -> V_215 [ V_66 ] . V_216 )
F_57 ( V_2 -> V_215 [ V_66 ] . V_216 ) ;
}
F_58 ( V_2 -> V_193 ) ;
if( V_2 -> V_80 . V_90 ) {
F_59 ( & V_2 -> V_80 ) ;
V_2 -> V_80 . V_90 = NULL ;
}
if( V_2 -> V_82 . V_90 ) {
F_59 ( & V_2 -> V_82 ) ;
V_2 -> V_82 . V_90 = NULL ;
}
F_60 ( V_2 -> V_193 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static T_5 F_61 ( struct V_217 * V_218 ,
void * V_219 ,
struct V_220 * V_220 , char T_6 * V_71 ,
T_7 V_221 , T_8 V_222 )
{
struct V_1 * V_2 = V_218 -> V_125 ;
V_221 = V_221 & ~ 3 ;
if ( F_62 ( V_71 , F_63 ( V_2 , V_222 ) , V_221 ) )
return - V_223 ;
return V_221 ;
}
static T_5 F_64 ( struct V_217 * V_218 ,
void * V_219 ,
struct V_220 * V_220 , char T_6 * V_71 ,
T_7 V_221 , T_8 V_222 )
{
struct V_1 * V_2 = V_218 -> V_125 ;
V_221 = V_221 & ~ 3 ;
if ( F_62 ( V_71 , F_65 ( V_2 , V_222 ) , V_221 ) )
return - V_223 ;
return V_221 ;
}
static void F_66 ( struct V_217 * V_218 ,
struct V_224 * V_225 )
{
struct V_49 * V_50 = V_218 -> V_125 ;
T_1 V_226 ;
F_67 ( V_225 , L_37 , V_50 -> V_72 ) ;
if ( V_50 -> V_2 -> V_214 & ( 1 << V_227 ) ) {
F_67 ( V_225 , L_38 ) ;
switch ( V_50 -> V_2 -> V_210 ) {
case V_228 : F_67 ( V_225 , L_39 ) ; break;
case V_211 : F_67 ( V_225 , L_40 ) ; break;
case V_229 : F_67 ( V_225 , L_41 ) ; break;
default: F_67 ( V_225 , L_42 ) ; break;
}
F_67 ( V_225 , L_43 ) ;
V_226 = F_68 ( F_63 ( V_50 -> V_2 , V_230 ) ) ;
if ( V_226 ) {
T_1 V_231 = 100 * F_68 ( F_63 ( V_50 -> V_2 , V_232 ) ) / V_226 ;
T_1 V_233 = 100 * F_68 ( F_63 ( V_50 -> V_2 , V_234 ) ) / V_226 ;
T_1 V_235 = 100 * F_68 ( F_63 ( V_50 -> V_2 , V_236 ) ) / V_226 ;
F_67 ( V_225 , L_44 , V_233 ) ;
F_67 ( V_225 , L_45 , V_231 ) ;
F_67 ( V_225 , L_46 , V_235 ) ;
}
}
}
static void T_4 F_69 ( struct V_49 * V_50 )
{
struct V_217 * V_218 ;
if ( ! F_70 ( V_50 -> V_195 , L_47 , & V_218 ) ) {
V_218 -> V_125 = V_50 ;
V_218 -> V_237 . V_238 . V_239 = F_66 ;
}
if ( ! F_70 ( V_50 -> V_195 , L_48 , & V_218 ) ) {
V_218 -> V_240 = V_241 ;
V_218 -> V_125 = V_50 -> V_2 ;
V_218 -> V_237 . V_205 = & V_242 ;
V_218 -> V_25 = V_243 ;
}
if ( ! F_70 ( V_50 -> V_195 , L_49 , & V_218 ) ) {
V_218 -> V_240 = V_241 ;
V_218 -> V_125 = V_50 -> V_2 ;
V_218 -> V_237 . V_205 = & V_244 ;
V_218 -> V_25 = V_245 ;
}
}
static int T_4 F_71 ( struct V_246 * V_193 ,
const struct V_247 * V_248 )
{
static int V_209 ;
struct V_1 * V_2 ;
unsigned int V_66 ;
int V_12 ;
T_7 V_25 ;
if ( V_209 >= V_249 )
return - V_250 ;
if ( ! V_251 [ V_209 ] ) {
V_209 ++ ;
return - V_252 ;
}
if ( ( V_12 = F_72 ( V_193 ) ) < 0 )
return V_12 ;
F_73 ( V_193 ) ;
if ( F_74 ( V_193 , F_75 ( 32 ) ) < 0 ) {
F_2 ( V_18 L_50 ) ;
F_60 ( V_193 ) ;
return - V_253 ;
}
V_2 = F_48 ( sizeof( * V_2 ) , V_73 ) ;
if ( ! V_2 ) {
F_60 ( V_193 ) ;
return - V_207 ;
}
V_2 -> V_193 = V_193 ;
V_2 -> V_213 = - 1 ;
if ( ( V_12 = F_76 ( V_193 , V_254 ) ) < 0 ) {
F_9 ( V_2 ) ;
F_60 ( V_193 ) ;
return V_12 ;
}
for ( V_66 = 0 ; V_66 < 2 ; V_66 ++ ) {
V_2 -> V_215 [ V_66 ] . V_255 = F_77 ( V_193 , V_66 ) ;
V_2 -> V_215 [ V_66 ] . V_216 = F_78 ( V_193 , V_66 ) ;
if ( ! V_2 -> V_215 [ V_66 ] . V_216 ) {
F_79 ( V_18 L_51 ,
V_2 -> V_215 [ V_66 ] . V_255 ) ;
F_52 ( V_2 ) ;
return - V_137 ;
}
}
if ( F_80 ( V_193 -> V_213 , V_256 , V_257 ,
V_258 , V_2 ) ) {
F_2 ( V_18 L_52 , V_193 -> V_213 ) ;
F_52 ( V_2 ) ;
return - V_137 ;
}
V_2 -> V_213 = V_193 -> V_213 ;
sprintf ( V_2 -> V_259 , L_53 ) ;
sprintf ( V_2 -> V_260 , L_54 , V_2 -> V_259 , V_2 -> V_215 [ 0 ] . V_255 , V_2 -> V_215 [ 1 ] . V_255 , V_2 -> V_213 ) ;
F_81 ( & V_2 -> V_261 ) ;
V_2 -> V_262 = 0 ;
V_2 -> V_263 = 0 ;
F_81 ( & V_2 -> V_264 ) ;
F_82 ( & V_2 -> V_265 ) ;
F_83 ( & V_2 -> V_266 ) ;
F_84 ( & V_2 -> V_136 , 0 ) ;
F_82 ( & V_2 -> V_170 ) ;
F_85 ( & V_2 -> V_267 , V_268 , ( unsigned long ) V_2 ) ;
V_2 -> V_212 = V_269 ;
for ( V_66 = 0 ; V_66 < V_2 -> V_212 ; V_66 ++ ) {
struct V_202 * V_195 ;
char V_270 [ 16 ] ;
int V_203 ;
if ( V_271 [ V_209 ] < 0 )
V_203 = V_271 [ V_209 ] ;
else
V_203 = V_271 [ V_209 ] + V_66 ;
snprintf ( V_270 , sizeof( V_270 ) , L_55 , V_272 [ V_209 ] ? V_272 [ V_209 ] : L_56 , V_66 ) ;
V_12 = F_86 ( V_203 , V_270 , V_273 , 0 , & V_195 ) ;
if ( V_12 < 0 ) {
F_2 ( V_18 L_57 , V_66 ) ;
F_52 ( V_2 ) ;
return V_12 ;
}
strcpy ( V_195 -> V_274 , V_254 ) ;
sprintf ( V_195 -> V_259 , L_58 , V_2 -> V_259 , V_66 ) ;
sprintf ( V_195 -> V_260 , L_58 , V_2 -> V_260 , V_66 ) ;
if ( ( V_12 = F_47 ( V_2 , V_195 , V_66 ) ) < 0 ) {
F_53 ( V_195 ) ;
F_52 ( V_2 ) ;
return V_12 ;
}
if( V_66 == 0 ) {
F_69 ( V_2 -> V_50 [ V_66 ] ) ;
}
if ( ( V_12 = F_87 ( V_195 ) ) < 0 ) {
F_52 ( V_2 ) ;
return V_12 ;
}
}
V_2 -> V_210 = V_228 ;
V_25 = F_88 ( ( V_88 * V_269 *
sizeof( struct V_79 ) ) ) ;
if ( F_89 ( V_192 , F_40 ( V_193 ) ,
V_25 , & V_2 -> V_80 ) < 0 ) {
F_52 ( V_2 ) ;
return - V_207 ;
}
memset ( V_2 -> V_80 . V_90 , 0 , V_25 ) ;
V_25 = F_88 ( ( V_88 * V_269 *
sizeof( struct V_81 ) ) ) ;
if ( F_89 ( V_192 , F_40 ( V_193 ) ,
V_25 , & V_2 -> V_82 ) < 0 ) {
F_52 ( V_2 ) ;
return - V_207 ;
}
memset ( V_2 -> V_82 . V_90 , 0 , V_25 ) ;
V_12 = F_90 ( V_2 ) ;
if ( V_12 < 0 ) {
F_52 ( V_2 ) ;
return V_12 ;
}
F_91 ( V_193 , V_2 ) ;
V_209 ++ ;
return 0 ;
}
static void T_9 F_92 ( struct V_246 * V_193 )
{
F_52 ( F_93 ( V_193 ) ) ;
F_91 ( V_193 , NULL ) ;
}
