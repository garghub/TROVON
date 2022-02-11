static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 |= V_3 ;
F_3 ( V_2 , V_5 , V_4 ) ;
}
static unsigned int F_4 ( struct V_1 * V_2 )
{
unsigned int V_6 = 0 ;
unsigned int * V_7 = V_2 -> V_8 . V_7 ;
if ( ( V_7 [ V_9 ] == V_10 ) &&
( ( ( V_7 [ V_11 ] == V_12 ) &&
( V_7 [ V_13 ] < V_14 ) ) ||
( ( V_7 [ V_11 ] == V_15 ) &&
( V_7 [ V_13 ] < V_16 ) ) ) )
V_6 |= V_17 ;
if ( ( V_7 [ V_11 ] == V_12 ) &&
( V_7 [ V_13 ] < V_18 ) )
V_6 |= V_19 ;
if ( V_7 [ V_11 ] == V_15 )
V_6 |= V_19 ;
return V_6 ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = sscanf ( V_2 -> V_8 . V_21 + 4 , L_1 ,
& V_2 -> V_8 . V_7 [ 0 ] , & V_2 -> V_8 . V_7 [ 1 ] ,
& V_2 -> V_8 . V_7 [ 2 ] , & V_2 -> V_8 . V_7 [ 3 ] ,
& V_2 -> V_8 . V_7 [ 4 ] ) ;
if ( V_20 != 5 ) {
F_6 ( L_2 ) ;
memset ( V_2 -> V_8 . V_7 , 0 , sizeof( V_2 -> V_8 . V_7 ) ) ;
return;
}
V_2 -> V_6 |= F_4 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_22 V_23 ;
F_8 ( V_2 , V_2 -> V_24 , & V_23 , sizeof( V_23 ) ,
false ) ;
strncpy ( V_2 -> V_8 . V_21 , V_23 . V_25 ,
sizeof( V_2 -> V_8 . V_21 ) ) ;
V_2 -> V_8 . V_21 [ sizeof( V_2 -> V_8 . V_21 ) - 1 ] = '\0' ;
F_5 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_26 ,
T_2 V_27 , T_1 V_28 )
{
struct V_29 V_30 ;
int V_31 , V_32 , V_33 ;
T_3 * V_34 , * V_35 ;
F_10 ( V_36 , L_3 ) ;
F_10 ( V_36 , L_4 ,
V_27 , V_37 ) ;
if ( ( V_27 % 4 ) != 0 ) {
F_11 ( L_5 ) ;
return - V_38 ;
}
V_35 = F_12 ( V_37 , V_39 ) ;
if ( ! V_35 ) {
F_11 ( L_6 ) ;
return - V_40 ;
}
memcpy ( & V_30 , & V_41 [ V_42 ] , sizeof( V_30 ) ) ;
V_30 . V_43 . V_44 = V_28 ;
F_13 ( V_2 , & V_30 ) ;
V_32 = 0 ;
V_33 = V_41 [ V_42 ] . V_43 . V_45 ;
while ( V_32 < V_27 / V_37 ) {
V_31 = V_28 + ( V_32 + 2 ) * V_37 ;
if ( V_31 > V_33 ) {
V_31 = V_28 + V_32 * V_37 ;
V_33 = V_32 * V_37 +
V_41 [ V_42 ] . V_43 . V_45 ;
V_30 . V_43 . V_44 = V_31 ;
F_13 ( V_2 , & V_30 ) ;
}
V_31 = V_28 + V_32 * V_37 ;
V_34 = V_26 + V_32 * V_37 ;
memcpy ( V_35 , V_34 , V_37 ) ;
F_10 ( V_36 , L_7 ,
V_34 , V_31 ) ;
F_14 ( V_2 , V_31 , V_35 , V_37 , false ) ;
V_32 ++ ;
}
V_31 = V_28 + V_32 * V_37 ;
V_34 = V_26 + V_32 * V_37 ;
memcpy ( V_35 , V_34 , V_27 % V_37 ) ;
F_10 ( V_36 , L_8 ,
V_27 % V_37 , V_34 , V_31 ) ;
F_14 ( V_2 , V_31 , V_35 , V_27 % V_37 , false ) ;
F_15 ( V_35 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_46 , V_31 , V_47 ;
int V_20 = 0 ;
T_3 * V_48 ;
V_48 = V_2 -> V_48 ;
V_46 = F_17 ( ( V_49 * ) V_48 ) ;
V_48 += sizeof( T_1 ) ;
F_10 ( V_36 , L_9 , V_46 ) ;
while ( V_46 -- ) {
V_31 = F_17 ( ( V_49 * ) V_48 ) ;
V_48 += sizeof( T_1 ) ;
V_47 = F_17 ( ( V_49 * ) V_48 ) ;
V_48 += sizeof( T_1 ) ;
if ( V_47 > 300000 ) {
F_18 ( L_10 , V_47 ) ;
return - V_50 ;
}
F_10 ( V_36 , L_11 ,
V_46 , V_31 , V_47 ) ;
V_20 = F_9 ( V_2 , V_48 , V_47 , V_31 ) ;
if ( V_20 != 0 )
break;
V_48 += V_47 ;
}
return V_20 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_2 V_51 , V_52 ;
int V_53 ;
T_1 V_54 , V_55 ;
T_3 * V_56 , * V_57 ;
if ( V_2 -> V_58 == NULL )
return - V_59 ;
if ( V_2 -> V_8 . V_60 == V_61 ) {
struct V_62 * V_58 = (struct V_62 * ) V_2 -> V_58 ;
if ( V_2 -> V_51 == sizeof( struct V_62 ) ) {
if ( V_58 -> V_63 . V_64 )
V_2 -> V_65 = true ;
} else {
F_11 ( L_12 ,
V_2 -> V_51 ,
sizeof( struct V_62 ) ) ;
F_15 ( V_2 -> V_58 ) ;
V_2 -> V_58 = NULL ;
V_2 -> V_51 = 0 ;
return - V_66 ;
}
V_51 = sizeof( V_58 -> V_58 ) ;
V_56 = ( T_3 * ) V_58 -> V_58 ;
} else {
struct V_67 * V_58 =
(struct V_67 * ) V_2 -> V_58 ;
if ( V_2 -> V_51 == sizeof( struct V_67 ) ||
V_2 -> V_51 == V_68 ) {
if ( V_2 -> V_69 != V_70 &&
V_58 -> V_63 . V_64 )
V_2 -> V_65 = true ;
}
if ( V_2 -> V_51 != sizeof( struct V_67 ) &&
( V_2 -> V_51 != V_68 ||
V_2 -> V_65 ) ) {
F_11 ( L_12 ,
V_2 -> V_51 , sizeof( struct V_67 ) ) ;
F_15 ( V_2 -> V_58 ) ;
V_2 -> V_58 = NULL ;
V_2 -> V_51 = 0 ;
return - V_66 ;
}
V_51 = sizeof( V_58 -> V_58 ) ;
V_56 = ( T_3 * ) V_58 -> V_58 ;
}
V_56 [ 11 ] = V_2 -> V_71 [ 0 ] ;
V_56 [ 10 ] = V_2 -> V_71 [ 1 ] ;
V_56 [ 6 ] = V_2 -> V_71 [ 2 ] ;
V_56 [ 5 ] = V_2 -> V_71 [ 3 ] ;
V_56 [ 4 ] = V_2 -> V_71 [ 4 ] ;
V_56 [ 3 ] = V_2 -> V_71 [ 5 ] ;
while ( V_56 [ 0 ] ) {
V_52 = V_56 [ 0 ] ;
V_54 = ( V_56 [ 1 ] & 0xfe ) | ( ( T_1 ) ( V_56 [ 2 ] << 8 ) ) ;
V_54 += V_72 ;
V_56 += 3 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_55 = ( V_56 [ 0 ] | ( V_56 [ 1 ] << 8 )
| ( V_56 [ 2 ] << 16 ) | ( V_56 [ 3 ] << 24 ) ) ;
F_10 ( V_36 ,
L_13 ,
V_54 , V_55 ) ;
F_3 ( V_2 , V_54 , V_55 ) ;
V_56 += 4 ;
V_54 += 4 ;
}
}
V_56 = ( T_3 * ) V_2 -> V_58 +
F_20 ( V_56 - ( T_3 * ) V_2 -> V_58 + 7 , 4 ) ;
V_51 -= V_56 - ( T_3 * ) V_2 -> V_58 ;
F_13 ( V_2 , & V_41 [ V_73 ] ) ;
V_57 = F_21 ( V_56 , V_51 , V_39 ) ;
if ( ! V_57 )
return - V_40 ;
F_14 ( V_2 , V_74 , V_57 , V_51 , false ) ;
F_15 ( V_57 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_3 ( V_2 , V_75 ,
V_76 & ~ ( V_77 ) ) ;
F_3 ( V_2 , V_78 , V_79 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned long V_80 ;
T_1 V_81 ;
F_3 ( V_2 , V_82 , V_83 ) ;
V_80 = V_84 + F_25 ( V_85 ) ;
while ( 1 ) {
V_81 = F_2 ( V_2 , V_82 ) ;
F_10 ( V_36 , L_14 , V_81 ) ;
if ( ( V_81 & V_83 ) == 0 )
break;
if ( F_26 ( V_84 , V_80 ) ) {
F_11 ( L_15 ) ;
return - 1 ;
}
F_27 ( V_86 ) ;
}
F_3 ( V_2 , V_87 , 0x0 ) ;
F_3 ( V_2 , V_88 , 0xffff ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_89 , V_20 ;
T_1 V_90 , V_91 ;
F_1 ( V_2 , V_92 ) ;
V_90 = F_2 ( V_2 , V_93 ) ;
F_10 ( V_36 , L_16 , V_90 ) ;
if ( V_90 != V_2 -> V_8 . V_60 ) {
F_11 ( L_17 ) ;
return - V_38 ;
}
V_89 = 0 ;
while ( V_89 ++ < V_94 ) {
F_27 ( V_95 ) ;
V_91 = F_2 ( V_2 , V_96 ) ;
if ( V_91 == 0xffffffff ) {
F_11 ( L_18
L_19 ) ;
return - V_38 ;
}
else if ( V_91 & V_97 ) {
F_3 ( V_2 , V_98 ,
V_97 ) ;
break;
}
}
if ( V_89 > V_94 ) {
F_11 ( L_20
L_21 ) ;
return - V_38 ;
}
V_2 -> V_24 = F_2 ( V_2 , V_99 ) ;
V_2 -> V_100 = F_2 ( V_2 , V_101 ) ;
F_13 ( V_2 , & V_41 [ V_73 ] ) ;
F_10 ( V_102 , L_22 ,
V_2 -> V_24 , V_2 -> V_100 ) ;
F_7 ( V_2 ) ;
V_2 -> V_103 = V_104 |
V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 ;
if ( V_2 -> V_69 == V_70 )
V_2 -> V_103 |= V_114 |
V_115 |
V_116 ;
else
V_2 -> V_103 |= V_117 |
V_118 ;
V_20 = F_29 ( V_2 ) ;
if ( V_20 < 0 ) {
F_11 ( L_23 ) ;
return V_20 ;
}
F_30 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_119 ;
V_119 = F_32 ( V_2 , V_120 ) ;
V_119 &= ~ V_121 ;
F_33 ( V_2 , V_120 , V_119 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_122 ;
V_122 = F_32 ( V_2 , V_123 ) ;
V_122 = ( V_122 & V_124 ) >> V_125 ;
V_2 -> V_126 = ( V_127 ) V_122 ;
if ( ( ( V_2 -> V_126 & V_128 ) >> V_129 ) < 3 )
V_2 -> V_6 |= V_130 ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_4 V_131 ;
V_131 = F_32 ( V_2 , V_132 ) ;
if ( V_131 == 0xFFFF )
return - V_133 ;
V_131 |= ( F_36 ( 3 ) | F_36 ( 5 ) | F_36 ( 6 ) ) ;
F_33 ( V_2 , V_132 , V_131 ) ;
F_33 ( V_2 , V_134 ,
V_135 | V_136 ) ;
F_37 ( 15 ) ;
return 0 ;
}
static bool F_38 ( struct V_1 * V_2 )
{
T_4 V_137 ;
V_137 = F_32 ( V_2 , V_138 ) ;
if ( V_137 & V_139 )
return false ;
return true ;
}
static bool F_39 ( struct V_1 * V_2 )
{
T_4 V_140 ;
V_140 = F_32 ( V_2 , V_141 ) ;
if ( V_140 & V_142 )
return false ;
return true ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_143 , V_144 ) ;
F_33 ( V_2 , V_145 , V_146 ) ;
F_33 ( V_2 , V_147 , V_148 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_149 )
{
T_4 V_131 ;
T_4 V_150 ;
T_3 V_151 ;
V_131 = F_32 ( V_2 , V_132 ) ;
if ( V_131 == 0xFFFF )
return - V_133 ;
V_131 |= F_36 ( 2 ) ;
F_33 ( V_2 , V_132 , V_131 ) ;
if ( V_2 -> V_152 == V_153 ||
V_2 -> V_152 == V_154 )
return F_40 ( V_2 ) ;
V_151 = ( V_149 & 1 ) + 1 ;
V_150 = F_32 ( V_2 , V_147 ) ;
if ( V_150 == 0xFFFF )
return - V_133 ;
V_150 |= ( V_151 << V_155 ) ;
V_150 |= V_156 ;
F_33 ( V_2 , V_147 , V_150 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , int * V_157 )
{
T_4 V_158 ;
if ( V_2 -> V_159 == V_160 ||
V_2 -> V_159 == V_161 ) {
if ( ! F_35 ( V_2 ) )
return - V_50 ;
goto V_162;
}
V_158 = F_32 ( V_2 , V_134 ) ;
if ( V_158 == 0xFFFF )
return - V_50 ;
if ( V_158 & V_163 )
goto V_162;
if ( V_2 -> V_152 == V_164 ||
V_2 -> V_152 == V_165 ) {
if ( ! F_35 ( V_2 ) )
return - V_50 ;
goto V_162;
}
if ( ! F_38 ( V_2 ) )
return - V_50 ;
* V_157 = V_2 -> V_152 ;
goto V_166;
V_162:
if ( ! F_39 ( V_2 ) )
return - V_50 ;
* V_157 = V_2 -> V_159 ;
V_166:
return F_41 ( V_2 , * V_157 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
T_1 V_167 ;
T_1 V_149 ;
F_34 ( V_2 ) ;
if ( V_2 -> V_159 == V_168 ||
V_2 -> V_159 == V_169 ||
V_2 -> V_159 == V_170 )
V_149 = 0x3 ;
else if ( V_2 -> V_159 == V_171 ||
V_2 -> V_159 == V_172 )
V_149 = 0x5 ;
else
return - V_50 ;
if ( V_2 -> V_159 != V_168 ) {
T_4 V_55 ;
V_55 = F_32 ( V_2 , V_173 ) ;
V_55 &= V_174 ;
F_33 ( V_2 , V_173 , V_55 ) ;
V_55 = F_32 ( V_2 , V_175 ) ;
V_55 |= V_176 ;
F_33 ( V_2 , V_175 , V_55 ) ;
} else {
T_4 V_55 ;
V_55 = F_32 ( V_2 , V_177 ) ;
V_55 &= V_178 ;
V_55 |= V_179 ;
F_33 ( V_2 , V_177 , V_55 ) ;
}
F_3 ( V_2 , V_180 , V_149 ) ;
V_167 = F_2 ( V_2 , V_180 ) ;
F_10 ( V_36 , L_24 , V_167 ) ;
V_167 &= ~ ( V_181 ) ;
V_167 |= V_181 ;
F_3 ( V_2 , V_182 , V_167 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
T_1 V_183 , V_149 ;
int V_157 = - 1 ;
if ( V_2 -> V_8 . V_60 == V_61 ) {
V_20 = F_42 ( V_2 , & V_157 ) ;
if ( V_20 < 0 )
goto V_184;
} else {
V_20 = F_43 ( V_2 ) ;
if ( V_20 < 0 )
goto V_184;
}
F_3 ( V_2 , V_185 , V_186 ) ;
F_27 ( 500 ) ;
F_13 ( V_2 , & V_41 [ V_187 ] ) ;
F_10 ( V_36 , L_25 , V_188 ) ;
V_149 = F_2 ( V_2 , V_188 ) ;
F_10 ( V_36 , L_26 , V_149 ) ;
if ( V_2 -> V_8 . V_60 == V_61 ) {
V_149 |= ( ( V_157 & 0x3 ) << 1 ) << 4 ;
} else {
V_149 |= ( V_2 -> V_159 << 1 ) << 4 ;
}
if ( V_2 -> V_6 & V_189 )
V_149 |= V_190 ;
F_3 ( V_2 , V_188 , V_149 ) ;
F_13 ( V_2 , & V_41 [ V_73 ] ) ;
F_3 ( V_2 , V_75 , V_76 ) ;
V_20 = F_24 ( V_2 ) ;
if ( V_20 < 0 )
goto V_184;
V_20 = F_19 ( V_2 ) ;
if ( V_20 < 0 )
goto V_184;
F_10 ( V_36 , L_27 ) ;
F_3 ( V_2 , V_191 , V_191 ) ;
V_183 = F_2 ( V_2 , V_93 ) ;
F_10 ( V_36 , L_28 , V_183 ) ;
V_183 = F_2 ( V_2 , V_192 ) ;
if ( V_2 -> V_8 . V_60 == V_61 )
F_33 ( V_2 , V_193 , V_2 -> V_194 . V_195 ) ;
V_20 = F_16 ( V_2 ) ;
if ( V_20 < 0 )
goto V_184;
V_184:
return V_20 ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_44 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_28 ( V_2 ) ;
if ( V_20 < 0 )
goto V_184;
V_20 = F_31 ( V_2 ) ;
if ( V_20 < 0 )
goto V_184;
F_3 ( V_2 , V_75 ,
V_196 ) ;
F_22 ( V_2 ) ;
F_46 ( V_2 ) ;
F_30 ( V_2 ) ;
V_184:
return V_20 ;
}
