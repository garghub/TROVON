T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_2 ( & V_4 -> V_6 ,
( void (*) ( unsigned long ) ) V_7 ,
( unsigned long ) V_2 ) ;
return V_8 ;
}
void F_3 ( struct V_1 * V_2 )
{
}
static T_2 F_4 ( struct V_1 * V_2 , int V_9 )
{
T_2 V_10 ;
struct V_11 * V_12 = F_5 ( V_2 ) ;
V_10 = ( ( ( V_9 + V_13 ) % V_12 -> V_14 ) == 0 ) ? 1 : 0 ;
return V_10 ;
}
static void F_6 ( struct V_15 * V_16 )
{
T_3 * V_17 = ( T_3 * ) V_16 ;
T_4 V_18 = 16 ;
T_4 V_19 ;
T_3 V_20 = 0 ;
V_16 -> V_21 &= F_7 ( 0xffff0000 ) ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ )
V_20 = V_20 ^ F_8 ( * ( V_22 * ) ( V_17 + V_19 ) ) ;
V_16 -> V_21 |= F_7 ( 0x0000ffff & V_20 ) ;
}
void F_9 ( struct V_1 * V_2 , T_2 * V_23 , T_4 V_24 , T_2 V_25 , T_2 V_26 )
{
struct V_15 * V_16 ;
V_16 = (struct V_15 * ) V_23 ;
F_10 ( V_23 , 0 , V_13 ) ;
V_16 -> V_27 |= F_7 ( V_28 | V_29 | V_30 ) ;
V_16 -> V_27 |= F_7 ( ( ( V_13 + V_31 ) << V_32 ) & 0x00ff0000 ) ;
V_16 -> V_27 |= F_7 ( V_24 & 0x0000ffff ) ;
V_16 -> V_33 |= F_7 ( ( V_34 << V_35 ) & 0x00001f00 ) ;
if ( V_25 ) {
V_16 -> V_33 |= F_7 ( V_36 ) ;
} else {
V_16 -> V_37 |= F_7 ( F_11 ( 7 ) ) ;
V_16 -> V_38 |= F_7 ( ( 8 << 28 ) ) ;
}
if ( V_26 )
V_16 -> V_39 |= F_7 ( F_11 ( 23 ) ) ;
V_16 -> V_37 |= F_7 ( F_11 ( 8 ) ) ;
F_6 ( V_16 ) ;
}
static void F_12 ( struct V_40 * V_41 , struct V_15 * V_16 )
{
if ( ( V_41 -> V_42 > 0 ) && ! V_41 -> V_43 ) {
switch ( V_41 -> V_42 ) {
case V_44 :
case V_45 :
V_16 -> V_33 |= F_7 ( ( 0x01 << V_46 ) & 0x00c00000 ) ;
V_16 -> V_39 |= F_7 ( 0x7 << V_47 ) ;
break;
case V_48 :
case V_49 :
V_16 -> V_33 |= F_7 ( ( 0x01 << V_46 ) & 0x00c00000 ) ;
V_16 -> V_39 |= F_7 ( 0x7 << V_47 ) ;
break;
case V_50 :
V_16 -> V_33 |= F_7 ( ( 0x03 << V_46 ) & 0x00c00000 ) ;
V_16 -> V_39 |= F_7 ( 0x7 << V_47 ) ;
break;
case V_51 :
default:
break;
}
}
}
static void F_13 ( struct V_40 * V_41 , T_5 * V_52 )
{
switch ( V_41 -> V_53 ) {
case V_54 :
* V_52 |= F_7 ( V_55 ) ;
break;
case V_56 :
* V_52 |= F_7 ( V_57 ) ;
break;
case V_58 :
default:
break;
}
if ( V_41 -> V_53 ) {
* V_52 |= F_7 ( V_59 ) ;
if ( V_41 -> V_60 ) {
* V_52 |= ( V_41 -> V_61 & V_62 ) ? F_7 ( F_11 ( 27 ) ) : 0 ;
if ( V_41 -> V_63 == V_64 )
* V_52 |= F_7 ( ( 0x01 << 28 ) & 0x30000000 ) ;
else if ( V_41 -> V_63 == V_65 )
* V_52 |= F_7 ( ( 0x02 << 28 ) & 0x30000000 ) ;
else if ( V_41 -> V_63 == V_66 )
* V_52 |= 0 ;
else
* V_52 |= F_7 ( ( 0x03 << 28 ) & 0x30000000 ) ;
}
}
}
static void F_14 ( struct V_40 * V_41 , T_5 * V_52 )
{
if ( V_41 -> V_60 ) {
* V_52 |= ( V_41 -> V_61 & V_62 ) ? F_7 ( F_11 ( 25 ) ) : 0 ;
if ( V_41 -> V_63 == V_64 )
* V_52 |= F_7 ( ( 0x01 << V_67 ) & 0x003f0000 ) ;
else if ( V_41 -> V_63 == V_65 )
* V_52 |= F_7 ( ( 0x02 << V_67 ) & 0x003f0000 ) ;
else if ( V_41 -> V_63 == V_66 )
* V_52 |= 0 ;
else
* V_52 |= F_7 ( ( 0x03 << V_67 ) & 0x003f0000 ) ;
}
}
static T_1 F_15 ( struct V_68 * V_69 , T_2 * V_70 , T_1 V_9 , T_2 V_71 )
{
int V_72 = 0 ;
T_6 V_73 ;
T_2 V_74 , V_75 , V_76 ;
struct V_1 * V_2 = V_69 -> V_77 ;
struct V_40 * V_41 = & V_69 -> V_78 ;
struct V_11 * V_12 = F_5 ( V_2 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_70 ;
struct V_79 * V_80 = & V_2 -> V_81 ;
struct V_82 * V_83 = & ( V_80 -> V_84 ) ;
int V_85 = F_16 ( V_41 -> V_86 ) ;
if ( V_2 -> V_87 . V_88 == 0 ) {
if ( ( ! V_71 ) && ( F_4 ( V_2 , V_9 ) == 0 ) ) {
V_16 = (struct V_15 * ) ( V_70 + V_89 ) ;
V_72 = 1 ;
}
}
F_10 ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 -> V_27 |= F_7 ( V_28 | V_29 | V_30 ) ;
V_16 -> V_27 |= F_7 ( V_9 & 0x0000ffff ) ;
V_76 = V_13 + V_31 ;
V_16 -> V_27 |= F_7 ( ( ( V_76 ) << V_32 ) & 0x00ff0000 ) ;
if ( V_85 )
V_16 -> V_27 |= F_7 ( V_90 ) ;
if ( V_2 -> V_87 . V_88 == 0 ) {
if ( ! V_71 ) {
if ( ( V_72 ) && ( V_69 -> V_91 > 0 ) )
V_69 -> V_91 = V_69 -> V_91 - 1 ;
}
}
if ( V_69 -> V_91 > 0 )
V_16 -> V_33 |= F_7 ( ( V_69 -> V_91 << 26 ) & 0x7c000000 ) ;
V_16 -> V_37 |= F_7 ( V_92 ) ;
if ( ( V_69 -> V_93 & 0x0f ) == V_94 ) {
V_16 -> V_33 |= F_7 ( V_41 -> V_95 & 0x3F ) ;
V_73 = ( T_6 ) ( V_41 -> V_73 & 0x0000001f ) ;
V_16 -> V_33 |= F_7 ( ( V_73 << V_35 ) & 0x00001f00 ) ;
V_16 -> V_33 |= F_7 ( ( V_41 -> V_96 << V_97 ) & 0x000F0000 ) ;
F_12 ( V_41 , V_16 ) ;
if ( V_41 -> V_98 ) {
V_16 -> V_39 |= F_7 ( V_99 ) ;
V_16 -> V_100 = F_7 ( 0x6666f800 ) ;
} else {
V_16 -> V_39 |= F_7 ( V_101 ) ;
}
V_16 -> V_38 |= F_7 ( ( V_41 -> V_102 << V_103 ) & 0x0FFF0000 ) ;
if ( V_41 -> V_104 )
V_16 -> V_37 |= F_7 ( V_105 ) ;
if ( V_69 -> V_106 > 1 )
V_16 -> V_107 |= F_7 ( ( V_69 -> V_106 << V_108 ) & 0xFF000000 ) ;
if ( ( V_41 -> V_109 != 0x888e ) &&
( V_41 -> V_109 != 0x0806 ) &&
( V_41 -> V_109 != 0x88b4 ) &&
( V_41 -> V_110 != 1 ) ) {
F_13 ( V_41 , & V_16 -> V_37 ) ;
F_14 ( V_41 , & V_16 -> V_37 ) ;
V_16 -> V_37 |= F_7 ( 0x00000008 ) ;
V_16 -> V_107 |= F_7 ( 0x0001ff00 ) ;
if ( V_41 -> V_60 ) {
if ( F_17 ( & V_12 -> V_111 , V_41 -> V_95 ) )
V_16 -> V_107 |= F_7 ( V_112 ) ;
}
V_74 = F_18 ( & V_12 -> V_111 , V_41 -> V_95 ) ;
V_16 -> V_107 |= F_7 ( V_74 & 0x3F ) ;
V_75 = F_19 ( & V_12 -> V_111 , V_41 -> V_95 ) ;
V_16 -> V_37 |= F_7 ( ( V_75 & 0x7 ) << V_113 ) ;
} else {
V_16 -> V_39 |= F_7 ( V_101 ) ;
if ( V_83 -> V_114 == V_115 )
V_16 -> V_37 |= F_7 ( F_11 ( 24 ) ) ;
V_16 -> V_107 |= F_7 ( F_20 ( V_80 -> V_116 ) ) ;
}
} else if ( ( V_69 -> V_93 & 0x0f ) == V_117 ) {
V_16 -> V_33 |= F_7 ( V_41 -> V_95 & 0x3f ) ;
V_73 = ( T_6 ) ( V_41 -> V_73 & 0x0000001f ) ;
V_16 -> V_33 |= F_7 ( ( V_73 << V_35 ) & 0x00001f00 ) ;
V_16 -> V_33 |= F_7 ( ( V_41 -> V_96 << V_97 ) & 0x000f0000 ) ;
if ( V_69 -> V_118 )
V_16 -> V_39 |= F_7 ( F_11 ( 19 ) ) ;
V_16 -> V_38 |= F_7 ( ( V_41 -> V_102 << V_103 ) & 0x0FFF0000 ) ;
V_16 -> V_107 |= F_7 ( V_119 ) ;
if ( V_41 -> V_120 )
V_16 -> V_107 |= F_7 ( 0x00180000 ) ;
else
V_16 -> V_107 |= F_7 ( 0x00300000 ) ;
V_16 -> V_107 |= F_7 ( F_20 ( V_80 -> V_116 ) ) ;
} else if ( ( V_69 -> V_93 & 0x0f ) == V_121 ) {
F_21 ( L_1 ) ;
} else if ( ( ( V_69 -> V_93 & 0x0f ) == V_122 ) &&
( V_2 -> V_87 . V_88 == 1 ) ) {
F_22 ( V_2 , V_16 ) ;
} else {
F_21 ( L_2 , V_69 -> V_93 ) ;
V_16 -> V_33 |= F_7 ( ( 4 ) & 0x3f ) ;
V_16 -> V_33 |= F_7 ( ( 6 << V_97 ) & 0x000f0000 ) ;
V_16 -> V_38 |= F_7 ( ( V_41 -> V_102 << V_103 ) & 0x0fff0000 ) ;
V_16 -> V_107 |= F_7 ( F_20 ( V_80 -> V_116 ) ) ;
}
if ( ! V_41 -> V_104 ) {
V_16 -> V_38 |= F_7 ( V_123 ) ;
V_16 -> V_37 |= F_7 ( V_124 ) ;
}
F_23 ( & V_12 -> V_111 , V_70 , V_41 -> V_95 ) ;
F_6 ( V_16 ) ;
F_24 ( V_2 , V_69 -> V_93 , V_16 ) ;
return V_72 ;
}
static T_1 F_25 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
T_1 V_125 = V_8 ;
T_1 V_126 = V_8 ;
int V_127 , V_9 , V_128 , V_72 = 0 ;
T_2 * V_129 ;
T_4 V_130 ;
struct V_131 * V_132 = V_69 -> V_132 ;
struct V_40 * V_41 = & V_69 -> V_78 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_133 * V_134 = & V_2 -> V_135 ;
if ( ( V_69 -> V_93 == V_94 ) &&
( V_69 -> V_78 . V_109 != 0x0806 ) &&
( V_69 -> V_78 . V_109 != 0x888e ) &&
( V_69 -> V_78 . V_109 != 0x88b4 ) &&
( V_69 -> V_78 . V_110 != 1 ) )
F_26 ( V_2 , V_69 ) ;
V_129 = V_69 -> V_136 ;
F_27 ( V_137 , V_138 , ( L_3 ) ) ;
for ( V_127 = 0 ; V_127 < V_41 -> V_139 ; V_127 ++ ) {
if ( V_126 != V_8 && V_125 == V_8 )
V_125 = V_140 ;
if ( V_127 != ( V_41 -> V_139 - 1 ) ) {
F_27 ( V_137 , V_141 , ( L_4 , V_41 -> V_139 ) ) ;
V_9 = V_4 -> V_142 ;
V_9 = V_9 - 4 - ( V_134 -> V_143 ? 0 : V_41 -> V_144 ) ;
} else {
V_9 = V_41 -> V_145 ;
}
V_72 = F_15 ( V_69 , V_129 , V_9 , false ) ;
if ( V_72 ) {
V_129 += V_89 ;
V_69 -> V_136 = V_129 ;
V_128 = V_9 + V_13 ;
} else {
V_128 = V_9 + V_13 + V_89 ;
}
V_130 = F_28 ( V_69 ) ;
V_126 = F_29 ( V_2 , V_130 , V_128 , ( unsigned char * ) V_132 ) ;
F_30 ( V_2 , V_69 , V_9 ) ;
F_27 ( V_137 , V_138 , ( L_5 , V_128 ) ) ;
V_129 += V_128 ;
V_129 = ( T_2 * ) F_31 ( ( ( V_146 ) ( V_129 ) ) ) ;
}
F_32 ( V_4 , V_69 ) ;
if ( V_125 != V_8 )
F_33 ( & V_132 -> V_147 , V_148 ) ;
return V_125 ;
}
static T_4 F_34 ( struct V_68 * V_69 )
{
struct V_40 * V_41 = & V_69 -> V_78 ;
T_4 V_149 = 0 ;
V_149 = V_41 -> V_150 + V_41 -> V_151 +
V_152 + sizeof( T_3 ) +
V_41 -> V_153 +
( ( V_41 -> V_43 ) ? V_41 -> V_144 : 0 ) ;
if ( V_41 -> V_42 == V_48 )
V_149 += 8 ;
return V_149 ;
}
T_1 F_35 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_131 * V_132 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
struct V_68 * V_69 = NULL ;
struct V_68 * V_154 = NULL ;
struct V_155 * V_156 ;
struct V_157 * V_158 = NULL ;
struct V_159 * V_160 = NULL ;
struct V_161 * V_162 = NULL , * V_163 = NULL ;
T_4 V_164 ;
T_4 V_165 ;
T_4 V_149 ;
T_4 V_166 = V_12 -> V_14 ;
T_2 V_167 ;
T_4 V_168 ;
T_4 V_130 ;
F_27 ( V_169 , V_138 , ( L_6 ) ) ;
if ( V_132 == NULL ) {
V_132 = F_36 ( V_4 ) ;
if ( V_132 == NULL )
return false ;
}
do {
F_32 ( V_4 , V_69 ) ;
V_69 = F_37 ( V_4 , V_4 -> V_170 , V_4 -> V_171 ) ;
if ( V_69 == NULL ) {
F_38 ( V_4 , V_132 ) ;
return false ;
}
V_69 -> V_132 = V_132 ;
V_69 -> V_136 = V_132 -> V_164 ;
V_132 -> V_172 = V_69 ;
V_69 -> V_106 = 1 ;
V_69 -> V_91 = 1 ;
F_39 ( V_2 , V_69 -> V_173 , V_69 ) ;
F_40 ( V_2 , V_69 ) ;
break;
} while ( 1 );
V_154 = V_69 ;
V_149 = F_34 ( V_154 ) + V_13 + ( V_154 -> V_91 * V_89 ) ;
V_165 = V_149 ;
V_164 = F_41 ( V_165 ) ;
V_167 = 0 ;
V_168 = V_166 ;
if ( V_164 < V_168 ) {
V_167 ++ ;
} else {
V_167 = 0 ;
V_168 = ( ( V_164 / V_166 ) + 1 ) * V_166 ;
}
V_158 = V_154 -> V_78 . V_158 ;
switch ( V_154 -> V_78 . V_174 ) {
case 1 :
case 2 :
V_160 = & ( V_158 -> V_175 . V_176 ) ;
V_156 = V_4 -> V_170 + 3 ;
break;
case 4 :
case 5 :
V_160 = & ( V_158 -> V_175 . V_177 ) ;
V_156 = V_4 -> V_170 + 1 ;
break;
case 6 :
case 7 :
V_160 = & ( V_158 -> V_175 . V_178 ) ;
V_156 = V_4 -> V_170 ;
break;
case 0 :
case 3 :
default:
V_160 = & ( V_158 -> V_175 . V_179 ) ;
V_156 = V_4 -> V_170 + 2 ;
break;
}
F_42 ( & V_4 -> V_180 ) ;
V_163 = F_43 ( & V_160 -> V_181 ) ;
V_162 = F_44 ( V_163 ) ;
while ( ! F_45 ( V_163 , V_162 ) ) {
V_69 = F_46 ( V_162 , struct V_68 , V_182 ) ;
V_162 = F_44 ( V_162 ) ;
V_69 -> V_106 = 0 ;
V_69 -> V_91 = 0 ;
V_149 = F_34 ( V_69 ) + V_13 + ( V_69 -> V_91 * V_89 ) ;
if ( F_41 ( V_164 + V_149 ) > V_183 ) {
V_69 -> V_106 = 1 ;
V_69 -> V_91 = 1 ;
break;
}
F_47 ( & V_69 -> V_182 ) ;
V_160 -> V_184 -- ;
V_156 -> V_185 -- ;
V_69 -> V_136 = V_132 -> V_164 + V_164 ;
F_39 ( V_2 , V_69 -> V_173 , V_69 ) ;
F_40 ( V_2 , V_69 ) ;
F_15 ( V_69 , V_69 -> V_136 , V_69 -> V_78 . V_145 , true ) ;
F_32 ( V_4 , V_69 ) ;
V_165 = V_164 + V_149 ;
V_164 = F_41 ( V_165 ) ;
V_154 -> V_106 ++ ;
if ( V_186 == V_154 -> V_106 )
break;
if ( V_164 < V_168 ) {
V_167 ++ ;
if ( V_167 == V_12 -> V_187 )
break;
} else {
V_167 = 0 ;
V_168 = ( ( V_164 / V_166 ) + 1 ) * V_166 ;
}
}
if ( F_48 ( & V_160 -> V_181 ) == true )
F_47 ( & V_160 -> V_188 ) ;
F_49 ( & V_4 -> V_180 ) ;
if ( ( V_154 -> V_78 . V_109 != 0x0806 ) &&
( V_154 -> V_78 . V_109 != 0x888e ) &&
( V_154 -> V_78 . V_109 != 0x88b4 ) &&
( V_154 -> V_78 . V_110 != 1 ) )
F_26 ( V_2 , V_154 ) ;
if ( ( V_165 % V_166 ) == 0 ) {
V_165 -= V_89 ;
V_154 -> V_136 += V_89 ;
V_154 -> V_91 -- ;
}
F_15 ( V_154 , V_154 -> V_136 , V_154 -> V_78 . V_145 , true ) ;
V_130 = F_28 ( V_154 ) ;
F_29 ( V_2 , V_130 , V_165 , ( T_2 * ) V_132 ) ;
V_165 -= ( V_154 -> V_106 * V_13 ) ;
V_165 -= ( V_154 -> V_91 * V_89 ) ;
F_30 ( V_2 , V_154 , V_165 ) ;
F_32 ( V_4 , V_154 ) ;
return true ;
}
static T_1 F_50 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
T_1 V_189 = V_8 ;
V_189 = F_39 ( V_2 , V_69 -> V_173 , V_69 ) ;
if ( V_189 == V_8 )
F_25 ( V_2 , V_69 ) ;
else
F_21 ( L_7 , V_190 ) ;
return V_189 ;
}
static T_1 F_51 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
T_1 V_189 ;
struct V_131 * V_132 = NULL ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_40 * V_41 = & V_69 -> V_78 ;
struct V_191 * V_192 = & V_2 -> V_193 ;
F_42 ( & V_4 -> V_180 ) ;
if ( F_52 ( V_2 , V_41 ) > 0 )
goto V_194;
if ( F_53 ( V_192 , V_195 | V_196 ) == true )
goto V_194;
V_132 = F_36 ( V_4 ) ;
if ( V_132 == NULL )
goto V_194;
F_49 ( & V_4 -> V_180 ) ;
V_69 -> V_132 = V_132 ;
V_69 -> V_136 = V_132 -> V_164 ;
V_132 -> V_172 = V_69 ;
if ( F_50 ( V_2 , V_69 ) != V_8 ) {
F_38 ( V_4 , V_132 ) ;
F_32 ( V_4 , V_69 ) ;
}
return true ;
V_194:
V_189 = F_54 ( V_2 , V_69 ) ;
F_49 ( & V_4 -> V_180 ) ;
if ( V_189 != V_8 ) {
F_27 ( V_197 , V_141 , ( L_8 ) ) ;
F_32 ( V_4 , V_69 ) ;
V_4 -> V_198 -- ;
V_4 -> V_199 ++ ;
return true ;
}
return false ;
}
T_1 F_55 ( struct V_1 * V_2 , struct V_68 * V_200 )
{
return F_25 ( V_2 , V_200 ) ;
}
T_1 F_56 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
return F_51 ( V_2 , V_69 ) ;
}
