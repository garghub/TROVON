T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_2 ( & V_4 -> V_6 ,
( void (*) ( unsigned long ) ) V_7 ,
( unsigned long ) V_2 ) ;
return V_8 ;
}
static T_2 F_3 ( struct V_1 * V_2 , int V_9 )
{
return ! ( ( V_9 + V_10 ) % V_2 -> V_11 -> V_12 ) ;
}
static void F_4 ( struct V_13 * V_14 )
{
T_3 * V_15 = ( T_3 * ) V_14 ;
T_4 V_16 = 16 ;
T_4 V_17 ;
T_3 V_18 = 0 ;
V_14 -> V_19 &= F_5 ( 0xffff0000 ) ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
V_18 = V_18 ^ F_6 ( * ( V_20 * ) ( V_15 + V_17 ) ) ;
V_14 -> V_19 |= F_5 ( 0x0000ffff & V_18 ) ;
}
void F_7 ( struct V_1 * V_2 , T_2 * V_21 , T_4 V_22 , T_2 V_23 , T_2 V_24 )
{
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) V_21 ;
memset ( V_21 , 0 , V_10 ) ;
V_14 -> V_25 |= F_5 ( V_26 | V_27 | V_28 ) ;
V_14 -> V_25 |= F_5 ( ( ( V_10 + V_29 ) << V_30 ) & 0x00ff0000 ) ;
V_14 -> V_25 |= F_5 ( V_22 & 0x0000ffff ) ;
V_14 -> V_31 |= F_5 ( ( V_32 << V_33 ) & 0x00001f00 ) ;
if ( V_23 ) {
V_14 -> V_31 |= F_5 ( V_34 ) ;
} else {
V_14 -> V_35 |= F_5 ( F_8 ( 7 ) ) ;
V_14 -> V_36 |= F_5 ( ( 8 << 28 ) ) ;
}
if ( V_24 )
V_14 -> V_37 |= F_5 ( F_8 ( 23 ) ) ;
V_14 -> V_35 |= F_5 ( F_8 ( 8 ) ) ;
F_4 ( V_14 ) ;
}
static void F_9 ( struct V_38 * V_39 , struct V_13 * V_14 )
{
if ( ( V_39 -> V_40 > 0 ) && ! V_39 -> V_41 ) {
switch ( V_39 -> V_40 ) {
case V_42 :
case V_43 :
V_14 -> V_31 |= F_5 ( ( 0x01 << V_44 ) & 0x00c00000 ) ;
V_14 -> V_37 |= F_5 ( 0x7 << V_45 ) ;
break;
case V_46 :
case V_47 :
V_14 -> V_31 |= F_5 ( ( 0x01 << V_44 ) & 0x00c00000 ) ;
V_14 -> V_37 |= F_5 ( 0x7 << V_45 ) ;
break;
case V_48 :
V_14 -> V_31 |= F_5 ( ( 0x03 << V_44 ) & 0x00c00000 ) ;
V_14 -> V_37 |= F_5 ( 0x7 << V_45 ) ;
break;
case V_49 :
default:
break;
}
}
}
static void F_10 ( struct V_38 * V_39 , T_5 * V_50 )
{
switch ( V_39 -> V_51 ) {
case V_52 :
* V_50 |= F_5 ( V_53 ) ;
break;
case V_54 :
* V_50 |= F_5 ( V_55 ) ;
break;
case V_56 :
default:
break;
}
if ( V_39 -> V_51 ) {
* V_50 |= F_5 ( V_57 ) ;
if ( V_39 -> V_58 ) {
* V_50 |= ( V_39 -> V_59 & V_60 ) ? F_5 ( F_8 ( 27 ) ) : 0 ;
if ( V_39 -> V_61 == V_62 )
* V_50 |= F_5 ( ( 0x01 << 28 ) & 0x30000000 ) ;
else if ( V_39 -> V_61 == V_63 )
* V_50 |= F_5 ( ( 0x02 << 28 ) & 0x30000000 ) ;
else if ( V_39 -> V_61 == V_64 )
* V_50 |= 0 ;
else
* V_50 |= F_5 ( ( 0x03 << 28 ) & 0x30000000 ) ;
}
}
}
static void F_11 ( struct V_38 * V_39 , T_5 * V_50 )
{
if ( V_39 -> V_58 ) {
* V_50 |= ( V_39 -> V_59 & V_60 ) ? F_5 ( F_8 ( 25 ) ) : 0 ;
if ( V_39 -> V_61 == V_62 )
* V_50 |= F_5 ( ( 0x01 << V_65 ) & 0x003f0000 ) ;
else if ( V_39 -> V_61 == V_63 )
* V_50 |= F_5 ( ( 0x02 << V_65 ) & 0x003f0000 ) ;
else if ( V_39 -> V_61 == V_64 )
* V_50 |= 0 ;
else
* V_50 |= F_5 ( ( 0x03 << V_65 ) & 0x003f0000 ) ;
}
}
static T_1 F_12 ( struct V_66 * V_67 , T_2 * V_68 , T_1 V_9 , T_2 V_69 )
{
int V_70 = 0 ;
T_6 V_71 ;
T_2 V_72 , V_73 , V_74 ;
struct V_1 * V_2 = V_67 -> V_75 ;
struct V_38 * V_39 = & V_67 -> V_76 ;
struct V_77 * V_78 = & V_2 -> V_11 -> V_78 ;
struct V_13 * V_14 = (struct V_13 * ) V_68 ;
struct V_79 * V_80 = & V_2 -> V_81 ;
struct V_82 * V_83 = & ( V_80 -> V_84 ) ;
int V_85 = F_13 ( V_39 -> V_86 ) ;
if ( V_2 -> V_87 . V_88 == 0 ) {
if ( ( ! V_69 ) && ( F_3 ( V_2 , V_9 ) == 0 ) ) {
V_14 = (struct V_13 * ) ( V_68 + V_89 ) ;
V_70 = 1 ;
}
}
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_25 |= F_5 ( V_26 | V_27 | V_28 ) ;
V_14 -> V_25 |= F_5 ( V_9 & 0x0000ffff ) ;
V_74 = V_10 + V_29 ;
V_14 -> V_25 |= F_5 ( ( ( V_74 ) << V_30 ) & 0x00ff0000 ) ;
if ( V_85 )
V_14 -> V_25 |= F_5 ( V_90 ) ;
if ( V_2 -> V_87 . V_88 == 0 ) {
if ( ! V_69 ) {
if ( ( V_70 ) && ( V_67 -> V_91 > 0 ) )
V_67 -> V_91 = V_67 -> V_91 - 1 ;
}
}
if ( V_67 -> V_91 > 0 )
V_14 -> V_31 |= F_5 ( ( V_67 -> V_91 << 26 ) & 0x7c000000 ) ;
V_14 -> V_35 |= F_5 ( V_92 ) ;
if ( ( V_67 -> V_93 & 0x0f ) == V_94 ) {
V_14 -> V_31 |= F_5 ( V_39 -> V_95 & 0x3F ) ;
V_71 = ( T_6 ) ( V_39 -> V_71 & 0x0000001f ) ;
V_14 -> V_31 |= F_5 ( ( V_71 << V_33 ) & 0x00001f00 ) ;
V_14 -> V_31 |= F_5 ( ( V_39 -> V_96 << V_97 ) & 0x000F0000 ) ;
F_9 ( V_39 , V_14 ) ;
if ( V_39 -> V_98 ) {
V_14 -> V_37 |= F_5 ( V_99 ) ;
V_14 -> V_100 = F_5 ( 0x6666f800 ) ;
} else {
V_14 -> V_37 |= F_5 ( V_101 ) ;
}
V_14 -> V_36 |= F_5 ( ( V_39 -> V_102 << V_103 ) & 0x0FFF0000 ) ;
if ( V_39 -> V_104 )
V_14 -> V_35 |= F_5 ( V_105 ) ;
if ( V_67 -> V_106 > 1 )
V_14 -> V_107 |= F_5 ( ( V_67 -> V_106 << V_108 ) & 0xFF000000 ) ;
if ( ( V_39 -> V_109 != 0x888e ) &&
( V_39 -> V_109 != 0x0806 ) &&
( V_39 -> V_109 != 0x88b4 ) &&
( V_39 -> V_110 != 1 ) ) {
F_10 ( V_39 , & V_14 -> V_35 ) ;
F_11 ( V_39 , & V_14 -> V_35 ) ;
V_14 -> V_35 |= F_5 ( 0x00000008 ) ;
V_14 -> V_107 |= F_5 ( 0x0001ff00 ) ;
if ( V_39 -> V_58 ) {
if ( F_14 ( V_78 , V_39 -> V_95 ) )
V_14 -> V_107 |= F_5 ( V_111 ) ;
}
V_72 = F_15 ( V_78 , V_39 -> V_95 ) ;
V_14 -> V_107 |= F_5 ( V_72 & 0x3F ) ;
V_73 = F_16 ( V_78 , V_39 -> V_95 ) ;
V_14 -> V_35 |= F_5 ( ( V_73 & 0x7 ) << V_112 ) ;
} else {
V_14 -> V_37 |= F_5 ( V_101 ) ;
if ( V_83 -> V_113 == V_114 )
V_14 -> V_35 |= F_5 ( F_8 ( 24 ) ) ;
V_14 -> V_107 |= F_5 ( F_17 ( V_80 -> V_115 ) ) ;
}
} else if ( ( V_67 -> V_93 & 0x0f ) == V_116 ) {
V_14 -> V_31 |= F_5 ( V_39 -> V_95 & 0x3f ) ;
V_71 = ( T_6 ) ( V_39 -> V_71 & 0x0000001f ) ;
V_14 -> V_31 |= F_5 ( ( V_71 << V_33 ) & 0x00001f00 ) ;
V_14 -> V_31 |= F_5 ( ( V_39 -> V_96 << V_97 ) & 0x000f0000 ) ;
if ( V_67 -> V_117 )
V_14 -> V_37 |= F_5 ( F_8 ( 19 ) ) ;
V_14 -> V_36 |= F_5 ( ( V_39 -> V_102 << V_103 ) & 0x0FFF0000 ) ;
V_14 -> V_107 |= F_5 ( V_118 ) ;
if ( V_39 -> V_119 )
V_14 -> V_107 |= F_5 ( 0x00180000 ) ;
else
V_14 -> V_107 |= F_5 ( 0x00300000 ) ;
V_14 -> V_107 |= F_5 ( F_17 ( V_80 -> V_115 ) ) ;
} else if ( ( V_67 -> V_93 & 0x0f ) == V_120 ) {
F_18 ( L_1 ) ;
} else {
F_18 ( L_2 , V_67 -> V_93 ) ;
V_14 -> V_31 |= F_5 ( ( 4 ) & 0x3f ) ;
V_14 -> V_31 |= F_5 ( ( 6 << V_97 ) & 0x000f0000 ) ;
V_14 -> V_36 |= F_5 ( ( V_39 -> V_102 << V_103 ) & 0x0fff0000 ) ;
V_14 -> V_107 |= F_5 ( F_17 ( V_80 -> V_115 ) ) ;
}
if ( ! V_39 -> V_104 ) {
V_14 -> V_36 |= F_5 ( V_121 ) ;
V_14 -> V_35 |= F_5 ( V_122 ) ;
}
F_19 ( V_78 , V_68 , V_39 -> V_95 ) ;
F_4 ( V_14 ) ;
F_20 ( V_2 , V_67 -> V_93 , V_14 ) ;
return V_70 ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
T_1 V_123 = V_8 ;
T_1 V_124 = V_8 ;
int V_125 , V_9 , V_126 , V_70 = 0 ;
T_2 * V_127 ;
T_4 V_128 ;
struct V_129 * V_130 = V_67 -> V_130 ;
struct V_38 * V_39 = & V_67 -> V_76 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_131 * V_132 = & V_2 -> V_133 ;
if ( ( V_67 -> V_93 == V_94 ) &&
( V_67 -> V_76 . V_109 != 0x0806 ) &&
( V_67 -> V_76 . V_109 != 0x888e ) &&
( V_67 -> V_76 . V_109 != 0x88b4 ) &&
( V_67 -> V_76 . V_110 != 1 ) )
F_22 ( V_2 , V_67 ) ;
V_127 = V_67 -> V_134 ;
F_23 ( V_135 , V_136 , ( L_3 ) ) ;
for ( V_125 = 0 ; V_125 < V_39 -> V_137 ; V_125 ++ ) {
if ( V_124 != V_8 && V_123 == V_8 )
V_123 = V_138 ;
if ( V_125 != ( V_39 -> V_137 - 1 ) ) {
F_23 ( V_135 , V_139 , ( L_4 , V_39 -> V_137 ) ) ;
V_9 = V_4 -> V_140 ;
V_9 = V_9 - 4 - ( V_132 -> V_141 ? 0 : V_39 -> V_142 ) ;
} else {
V_9 = V_39 -> V_143 ;
}
V_70 = F_12 ( V_67 , V_127 , V_9 , false ) ;
if ( V_70 ) {
V_127 += V_89 ;
V_67 -> V_134 = V_127 ;
V_126 = V_9 + V_10 ;
} else {
V_126 = V_9 + V_10 + V_89 ;
}
V_128 = F_24 ( V_67 ) ;
V_124 = F_25 ( V_2 , V_128 , V_126 , V_130 ) ;
F_26 ( V_2 , V_67 , V_9 ) ;
F_23 ( V_135 , V_136 , ( L_5 , V_126 ) ) ;
V_127 += V_126 ;
V_127 = ( T_2 * ) F_27 ( ( V_144 ) V_127 , 4 ) ;
}
F_28 ( V_4 , V_67 ) ;
if ( V_123 != V_8 )
F_29 ( & V_130 -> V_145 , V_146 ) ;
return V_123 ;
}
static T_4 F_30 ( struct V_66 * V_67 )
{
struct V_38 * V_39 = & V_67 -> V_76 ;
T_4 V_147 ;
V_147 = V_39 -> V_148 + V_39 -> V_149 +
V_150 + sizeof( T_3 ) +
V_39 -> V_151 +
( ( V_39 -> V_41 ) ? V_39 -> V_142 : 0 ) ;
if ( V_39 -> V_40 == V_46 )
V_147 += 8 ;
return V_147 ;
}
T_1 F_31 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_66 * V_67 = NULL ;
struct V_66 * V_152 = NULL ;
struct V_129 * V_130 ;
struct V_153 * V_154 ;
struct V_155 * V_156 = NULL ;
struct V_157 * V_158 = NULL ;
struct V_159 * V_160 = NULL , * V_161 = NULL ;
T_4 V_162 ;
T_4 V_163 ;
T_4 V_147 ;
T_4 V_164 = V_2 -> V_11 -> V_12 ;
T_2 V_165 ;
T_4 V_166 ;
T_4 V_128 ;
F_23 ( V_167 , V_136 , ( L_6 ) ) ;
V_130 = F_32 ( V_4 ) ;
if ( V_130 == NULL )
return false ;
F_28 ( V_4 , V_67 ) ;
V_67 = F_33 ( V_4 , V_4 -> V_168 , V_4 -> V_169 ) ;
if ( V_67 == NULL ) {
F_34 ( V_4 , V_130 ) ;
return false ;
}
V_67 -> V_130 = V_130 ;
V_67 -> V_134 = V_130 -> V_162 ;
V_130 -> V_170 = V_67 ;
V_67 -> V_106 = 1 ;
V_67 -> V_91 = 1 ;
F_35 ( V_2 , V_67 -> V_171 , V_67 ) ;
F_36 ( V_2 , V_67 ) ;
V_152 = V_67 ;
V_147 = F_30 ( V_152 ) + V_10 + ( V_152 -> V_91 * V_89 ) ;
V_163 = V_147 ;
V_162 = F_27 ( V_163 , 8 ) ;
V_165 = 0 ;
V_166 = V_164 ;
if ( V_162 < V_166 ) {
V_165 ++ ;
} else {
V_165 = 0 ;
V_166 = ( ( V_162 / V_164 ) + 1 ) * V_164 ;
}
V_156 = V_152 -> V_76 . V_156 ;
switch ( V_152 -> V_76 . V_172 ) {
case 1 :
case 2 :
V_158 = & ( V_156 -> V_173 . V_174 ) ;
V_154 = V_4 -> V_168 + 3 ;
break;
case 4 :
case 5 :
V_158 = & ( V_156 -> V_173 . V_175 ) ;
V_154 = V_4 -> V_168 + 1 ;
break;
case 6 :
case 7 :
V_158 = & ( V_156 -> V_173 . V_176 ) ;
V_154 = V_4 -> V_168 ;
break;
case 0 :
case 3 :
default:
V_158 = & ( V_156 -> V_173 . V_177 ) ;
V_154 = V_4 -> V_168 + 2 ;
break;
}
F_37 ( & V_4 -> V_178 ) ;
V_161 = F_38 ( & V_158 -> V_179 ) ;
V_160 = V_161 -> V_180 ;
while ( V_161 != V_160 ) {
V_67 = F_39 ( V_160 , struct V_66 , V_181 ) ;
V_160 = V_160 -> V_180 ;
V_67 -> V_106 = 0 ;
V_67 -> V_91 = 0 ;
V_147 = F_30 ( V_67 ) + V_10 + ( V_67 -> V_91 * V_89 ) ;
if ( F_27 ( V_162 + V_147 , 8 ) > V_182 ) {
V_67 -> V_106 = 1 ;
V_67 -> V_91 = 1 ;
break;
}
F_40 ( & V_67 -> V_181 ) ;
V_158 -> V_183 -- ;
V_154 -> V_184 -- ;
V_67 -> V_134 = V_130 -> V_162 + V_162 ;
F_35 ( V_2 , V_67 -> V_171 , V_67 ) ;
F_36 ( V_2 , V_67 ) ;
F_12 ( V_67 , V_67 -> V_134 , V_67 -> V_76 . V_143 , true ) ;
F_28 ( V_4 , V_67 ) ;
V_163 = V_162 + V_147 ;
V_162 = F_27 ( V_163 , 8 ) ;
V_152 -> V_106 ++ ;
if ( V_185 == V_152 -> V_106 )
break;
if ( V_162 < V_166 ) {
V_165 ++ ;
if ( V_165 == V_2 -> V_11 -> V_186 )
break;
} else {
V_165 = 0 ;
V_166 = ( ( V_162 / V_164 ) + 1 ) * V_164 ;
}
}
if ( F_41 ( & V_158 -> V_179 . V_187 ) )
F_40 ( & V_158 -> V_188 ) ;
F_42 ( & V_4 -> V_178 ) ;
if ( ( V_152 -> V_76 . V_109 != 0x0806 ) &&
( V_152 -> V_76 . V_109 != 0x888e ) &&
( V_152 -> V_76 . V_109 != 0x88b4 ) &&
( V_152 -> V_76 . V_110 != 1 ) )
F_22 ( V_2 , V_152 ) ;
if ( ( V_163 % V_164 ) == 0 ) {
V_163 -= V_89 ;
V_152 -> V_134 += V_89 ;
V_152 -> V_91 -- ;
}
F_12 ( V_152 , V_152 -> V_134 , V_152 -> V_76 . V_143 , true ) ;
V_128 = F_24 ( V_152 ) ;
F_25 ( V_2 , V_128 , V_163 , V_130 ) ;
V_163 -= ( V_152 -> V_106 * V_10 ) ;
V_163 -= ( V_152 -> V_91 * V_89 ) ;
F_26 ( V_2 , V_152 , V_163 ) ;
F_28 ( V_4 , V_152 ) ;
return true ;
}
T_1 F_43 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
T_1 V_189 ;
struct V_129 * V_130 = NULL ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_38 * V_39 = & V_67 -> V_76 ;
struct V_190 * V_191 = & V_2 -> V_192 ;
F_37 ( & V_4 -> V_178 ) ;
if ( F_44 ( V_2 , V_39 ) > 0 )
goto V_193;
if ( F_45 ( V_191 , V_194 | V_195 ) == true )
goto V_193;
V_130 = F_32 ( V_4 ) ;
if ( ! V_130 )
goto V_193;
F_42 ( & V_4 -> V_178 ) ;
V_67 -> V_130 = V_130 ;
V_67 -> V_134 = V_130 -> V_162 ;
V_130 -> V_170 = V_67 ;
V_189 = F_35 ( V_2 , V_67 -> V_171 , V_67 ) ;
if ( V_189 == V_8 ) {
F_21 ( V_2 , V_67 ) ;
} else {
F_18 ( L_7 , V_196 ) ;
F_34 ( V_4 , V_130 ) ;
F_28 ( V_4 , V_67 ) ;
}
return true ;
V_193:
V_189 = F_46 ( V_2 , V_67 ) ;
F_42 ( & V_4 -> V_178 ) ;
if ( V_189 != V_8 ) {
F_23 ( V_197 , V_139 , ( L_8 ) ) ;
F_28 ( V_4 , V_67 ) ;
V_4 -> V_198 -- ;
V_4 -> V_199 ++ ;
return true ;
}
return false ;
}
T_1 F_47 ( struct V_1 * V_2 , struct V_66 * V_200 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
F_48 ( V_2 -> V_201 , V_200 , V_5 -> V_140 ) ;
return F_21 ( V_2 , V_200 ) ;
}
