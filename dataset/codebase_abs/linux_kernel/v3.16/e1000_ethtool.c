static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( V_8 -> V_9 == V_10 ) {
V_4 -> V_11 = ( V_12 |
V_13 |
V_14 |
V_15 |
V_16 |
V_17 |
V_18 ) ;
V_4 -> V_19 = V_20 ;
if ( V_8 -> V_21 == 1 ) {
V_4 -> V_19 |= V_22 ;
V_4 -> V_19 |= V_8 -> V_23 ;
}
V_4 -> V_24 = V_25 ;
V_4 -> V_26 = V_8 -> V_27 ;
if ( V_8 -> V_28 == V_29 )
V_4 -> V_30 = V_31 ;
else
V_4 -> V_30 = V_32 ;
} else {
V_4 -> V_11 = ( V_16 |
V_33 |
V_17 ) ;
V_4 -> V_19 = ( V_34 |
V_35 |
V_22 ) ;
V_4 -> V_24 = V_36 ;
if ( V_8 -> V_28 >= V_37 )
V_4 -> V_30 = V_32 ;
else
V_4 -> V_30 = V_31 ;
}
if ( F_3 ( V_38 ) & V_39 ) {
F_4 ( V_8 , & V_6 -> V_40 ,
& V_6 -> V_41 ) ;
F_5 ( V_4 , V_6 -> V_40 ) ;
if ( V_6 -> V_41 == V_42 )
V_4 -> V_43 = V_44 ;
else
V_4 -> V_43 = V_45 ;
} else {
F_5 ( V_4 , V_46 ) ;
V_4 -> V_43 = V_47 ;
}
V_4 -> V_21 = ( ( V_8 -> V_9 == V_48 ) ||
V_8 -> V_21 ) ? V_49 : V_50 ;
if ( ( V_8 -> V_9 == V_10 ) &&
F_6 ( V_2 ) )
V_4 -> V_51 = ( ! ! V_6 -> V_52 . V_53 ?
V_54 : V_55 ) ;
else
V_4 -> V_51 = V_56 ;
if ( V_8 -> V_57 == V_58 )
V_4 -> V_59 = V_60 ;
else
V_4 -> V_59 = V_8 -> V_57 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( V_4 -> V_59 ) {
if ( V_8 -> V_9 != V_10 )
return - V_61 ;
if ( ( V_4 -> V_59 != V_60 ) &&
( V_4 -> V_21 != V_49 ) ) {
F_8 ( V_62 , L_1 ) ;
return - V_63 ;
}
}
while ( F_9 ( V_64 , & V_6 -> V_65 ) )
F_10 ( 1 ) ;
if ( V_4 -> V_21 == V_49 ) {
V_8 -> V_21 = 1 ;
if ( V_8 -> V_9 == V_48 )
V_8 -> V_23 = V_34 |
V_35 |
V_22 ;
else
V_8 -> V_23 = V_4 -> V_19 |
V_20 |
V_22 ;
V_4 -> V_19 = V_8 -> V_23 ;
} else {
T_1 V_66 = F_11 ( V_4 ) ;
if ( F_12 ( V_6 , V_66 , V_4 -> V_43 ) ) {
F_13 ( V_64 , & V_6 -> V_65 ) ;
return - V_63 ;
}
}
if ( V_4 -> V_59 ) {
if ( V_4 -> V_59 == V_60 )
V_8 -> V_57 = V_58 ;
else
V_8 -> V_57 = V_4 -> V_59 ;
}
if ( F_14 ( V_6 -> V_2 ) ) {
F_15 ( V_6 ) ;
F_16 ( V_6 ) ;
} else
F_17 ( V_6 ) ;
F_13 ( V_64 , & V_6 -> V_65 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_6 ( V_2 ) )
V_6 -> V_8 . V_67 = 1 ;
return F_19 ( V_6 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_69 -> V_21 =
( V_6 -> V_70 ? V_49 : V_50 ) ;
if ( V_8 -> V_71 == V_72 )
V_69 -> V_73 = 1 ;
else if ( V_8 -> V_71 == V_74 )
V_69 -> V_75 = 1 ;
else if ( V_8 -> V_71 == V_76 ) {
V_69 -> V_73 = 1 ;
V_69 -> V_75 = 1 ;
}
}
static int F_21 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
int V_77 = 0 ;
V_6 -> V_70 = V_69 -> V_21 ;
while ( F_9 ( V_64 , & V_6 -> V_65 ) )
F_10 ( 1 ) ;
if ( V_69 -> V_73 && V_69 -> V_75 )
V_8 -> V_71 = V_76 ;
else if ( V_69 -> V_73 && ! V_69 -> V_75 )
V_8 -> V_71 = V_72 ;
else if ( ! V_69 -> V_73 && V_69 -> V_75 )
V_8 -> V_71 = V_74 ;
else if ( ! V_69 -> V_73 && ! V_69 -> V_75 )
V_8 -> V_71 = V_78 ;
V_8 -> V_79 = V_8 -> V_71 ;
if ( V_6 -> V_70 == V_49 ) {
if ( F_14 ( V_6 -> V_2 ) ) {
F_15 ( V_6 ) ;
F_16 ( V_6 ) ;
} else
F_17 ( V_6 ) ;
} else
V_77 = ( ( V_8 -> V_9 == V_48 ) ?
F_22 ( V_8 ) : F_23 ( V_8 ) ) ;
F_13 ( V_64 , & V_6 -> V_65 ) ;
return V_77 ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_80 ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_80 = V_81 ;
}
static int F_26 ( struct V_1 * V_2 )
{
#define F_27 32
return F_27 * sizeof( T_1 ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_82 * V_83 ,
void * V_84 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 * V_85 = V_84 ;
T_2 V_86 ;
memset ( V_84 , 0 , F_27 * sizeof( T_1 ) ) ;
V_83 -> V_87 = ( 1 << 24 ) | ( V_8 -> V_88 << 16 ) | V_8 -> V_89 ;
V_85 [ 0 ] = F_3 ( V_90 ) ;
V_85 [ 1 ] = F_3 ( V_38 ) ;
V_85 [ 2 ] = F_3 ( V_91 ) ;
V_85 [ 3 ] = F_3 ( V_92 ) ;
V_85 [ 4 ] = F_3 ( V_93 ) ;
V_85 [ 5 ] = F_3 ( V_94 ) ;
V_85 [ 6 ] = F_3 ( V_95 ) ;
V_85 [ 7 ] = F_3 ( V_96 ) ;
V_85 [ 8 ] = F_3 ( V_97 ) ;
V_85 [ 9 ] = F_3 ( V_98 ) ;
V_85 [ 10 ] = F_3 ( V_99 ) ;
V_85 [ 11 ] = F_3 ( V_100 ) ;
V_85 [ 12 ] = V_8 -> V_101 ;
if ( V_8 -> V_101 == V_102 ) {
F_29 ( V_8 , V_103 ,
V_104 ) ;
F_30 ( V_8 , V_104 &
V_103 , & V_86 ) ;
V_85 [ 13 ] = ( T_1 ) V_86 ;
F_29 ( V_8 , V_103 ,
V_105 ) ;
F_30 ( V_8 , V_105 &
V_103 , & V_86 ) ;
V_85 [ 14 ] = ( T_1 ) V_86 ;
F_29 ( V_8 , V_103 ,
V_106 ) ;
F_30 ( V_8 , V_106 &
V_103 , & V_86 ) ;
V_85 [ 15 ] = ( T_1 ) V_86 ;
F_29 ( V_8 , V_103 ,
V_107 ) ;
F_30 ( V_8 , V_107 &
V_103 , & V_86 ) ;
V_85 [ 16 ] = ( T_1 ) V_86 ;
V_85 [ 17 ] = 0 ;
F_29 ( V_8 , V_103 , 0x0 ) ;
F_30 ( V_8 , V_108 &
V_103 , & V_86 ) ;
V_85 [ 18 ] = ( T_1 ) V_86 ;
F_29 ( V_8 , V_103 ,
V_109 ) ;
F_30 ( V_8 , V_109 &
V_103 , & V_86 ) ;
V_85 [ 19 ] = ( T_1 ) V_86 ;
V_85 [ 20 ] = 0 ;
V_85 [ 22 ] = 0 ;
V_85 [ 23 ] = V_85 [ 18 ] ;
F_29 ( V_8 , V_103 , 0x0 ) ;
} else {
F_30 ( V_8 , V_110 , & V_86 ) ;
V_85 [ 13 ] = ( T_1 ) V_86 ;
V_85 [ 14 ] = 0 ;
V_85 [ 15 ] = 0 ;
V_85 [ 16 ] = 0 ;
F_30 ( V_8 , V_111 , & V_86 ) ;
V_85 [ 17 ] = ( T_1 ) V_86 ;
V_85 [ 18 ] = V_85 [ 13 ] ;
V_85 [ 19 ] = 0 ;
V_85 [ 20 ] = V_85 [ 17 ] ;
V_85 [ 22 ] = V_6 -> V_112 . V_113 ;
V_85 [ 23 ] = V_85 [ 13 ] ;
}
V_85 [ 21 ] = V_6 -> V_112 . V_114 ;
F_30 ( V_8 , V_115 , & V_86 ) ;
V_85 [ 24 ] = ( T_1 ) V_86 ;
V_85 [ 25 ] = V_85 [ 24 ] ;
if ( V_8 -> V_28 >= V_116 &&
V_8 -> V_9 == V_10 ) {
V_85 [ 26 ] = F_3 ( V_117 ) ;
}
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
return V_8 -> V_118 . V_119 * 2 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_120 * V_118 , T_3 * V_121 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 * V_122 ;
int V_123 , V_124 ;
int V_125 = 0 ;
T_2 V_126 ;
if ( V_118 -> V_127 == 0 )
return - V_63 ;
V_118 -> V_128 = V_8 -> V_129 | ( V_8 -> V_89 << 16 ) ;
V_123 = V_118 -> V_130 >> 1 ;
V_124 = ( V_118 -> V_130 + V_118 -> V_127 - 1 ) >> 1 ;
V_122 = F_33 ( sizeof( T_2 ) *
( V_124 - V_123 + 1 ) , V_131 ) ;
if ( ! V_122 )
return - V_132 ;
if ( V_8 -> V_118 . type == V_133 )
V_125 = F_34 ( V_8 , V_123 ,
V_124 - V_123 + 1 ,
V_122 ) ;
else {
for ( V_126 = 0 ; V_126 < V_124 - V_123 + 1 ; V_126 ++ ) {
V_125 = F_34 ( V_8 , V_123 + V_126 , 1 ,
& V_122 [ V_126 ] ) ;
if ( V_125 )
break;
}
}
for ( V_126 = 0 ; V_126 < V_124 - V_123 + 1 ; V_126 ++ )
F_35 ( & V_122 [ V_126 ] ) ;
memcpy ( V_121 , ( T_3 * ) V_122 + ( V_118 -> V_130 & 1 ) ,
V_118 -> V_127 ) ;
F_36 ( V_122 ) ;
return V_125 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_120 * V_118 , T_3 * V_121 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 * V_122 ;
void * V_134 ;
int V_135 , V_123 , V_124 , V_125 = 0 ;
T_2 V_126 ;
if ( V_118 -> V_127 == 0 )
return - V_61 ;
if ( V_118 -> V_128 != ( V_8 -> V_129 | ( V_8 -> V_89 << 16 ) ) )
return - V_136 ;
V_135 = V_8 -> V_118 . V_119 * 2 ;
V_123 = V_118 -> V_130 >> 1 ;
V_124 = ( V_118 -> V_130 + V_118 -> V_127 - 1 ) >> 1 ;
V_122 = F_33 ( V_135 , V_131 ) ;
if ( ! V_122 )
return - V_132 ;
V_134 = ( void * ) V_122 ;
if ( V_118 -> V_130 & 1 ) {
V_125 = F_34 ( V_8 , V_123 , 1 ,
& V_122 [ 0 ] ) ;
V_134 ++ ;
}
if ( ( ( V_118 -> V_130 + V_118 -> V_127 ) & 1 ) && ( V_125 == 0 ) ) {
V_125 = F_34 ( V_8 , V_124 , 1 ,
& V_122 [ V_124 - V_123 ] ) ;
}
for ( V_126 = 0 ; V_126 < V_124 - V_123 + 1 ; V_126 ++ )
F_35 ( & V_122 [ V_126 ] ) ;
memcpy ( V_134 , V_121 , V_118 -> V_127 ) ;
for ( V_126 = 0 ; V_126 < V_124 - V_123 + 1 ; V_126 ++ )
V_122 [ V_126 ] = F_38 ( V_122 [ V_126 ] ) ;
V_125 = F_39 ( V_8 , V_123 ,
V_124 - V_123 + 1 , V_122 ) ;
if ( ( V_125 == 0 ) && ( V_123 <= V_137 ) )
F_40 ( V_8 ) ;
F_36 ( V_122 ) ;
return V_125 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_42 ( V_139 -> V_140 , V_141 ,
sizeof( V_139 -> V_140 ) ) ;
F_42 ( V_139 -> V_87 , V_142 ,
sizeof( V_139 -> V_87 ) ) ;
F_42 ( V_139 -> V_143 , F_43 ( V_6 -> V_144 ) ,
sizeof( V_139 -> V_143 ) ) ;
V_139 -> V_145 = F_26 ( V_2 ) ;
V_139 -> V_146 = F_31 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_4 V_28 = V_8 -> V_28 ;
struct V_149 * V_150 = V_6 -> V_151 ;
struct V_152 * V_153 = V_6 -> V_154 ;
V_148 -> V_155 = ( V_28 < V_156 ) ? V_157 :
V_158 ;
V_148 -> V_159 = ( V_28 < V_156 ) ? V_160 :
V_161 ;
V_148 -> V_162 = V_153 -> V_163 ;
V_148 -> V_164 = V_150 -> V_163 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_4 V_28 = V_8 -> V_28 ;
struct V_149 * V_150 , * V_165 ;
struct V_152 * V_153 , * V_166 ;
int V_126 , V_167 ;
if ( ( V_148 -> V_168 ) || ( V_148 -> V_169 ) )
return - V_63 ;
while ( F_9 ( V_64 , & V_6 -> V_65 ) )
F_10 ( 1 ) ;
if ( F_14 ( V_6 -> V_2 ) )
F_15 ( V_6 ) ;
V_165 = V_6 -> V_151 ;
V_166 = V_6 -> V_154 ;
V_167 = - V_132 ;
V_150 = F_46 ( V_6 -> V_170 , sizeof( struct V_149 ) ,
V_131 ) ;
if ( ! V_150 )
goto V_171;
V_153 = F_46 ( V_6 -> V_172 , sizeof( struct V_152 ) ,
V_131 ) ;
if ( ! V_153 )
goto V_173;
V_6 -> V_151 = V_150 ;
V_6 -> V_154 = V_153 ;
V_153 -> V_163 = F_47 ( V_148 -> V_162 , ( T_1 ) V_174 ) ;
V_153 -> V_163 = F_48 ( V_153 -> V_163 , ( T_1 ) ( V_28 < V_156 ?
V_157 : V_158 ) ) ;
V_153 -> V_163 = F_49 ( V_153 -> V_163 , V_175 ) ;
V_150 -> V_163 = F_47 ( V_148 -> V_164 , ( T_1 ) V_176 ) ;
V_150 -> V_163 = F_48 ( V_150 -> V_163 , ( T_1 ) ( V_28 < V_156 ?
V_160 : V_161 ) ) ;
V_150 -> V_163 = F_49 ( V_150 -> V_163 , V_177 ) ;
for ( V_126 = 0 ; V_126 < V_6 -> V_170 ; V_126 ++ )
V_150 [ V_126 ] . V_163 = V_150 -> V_163 ;
for ( V_126 = 0 ; V_126 < V_6 -> V_172 ; V_126 ++ )
V_153 [ V_126 ] . V_163 = V_153 -> V_163 ;
if ( F_14 ( V_6 -> V_2 ) ) {
V_167 = F_50 ( V_6 ) ;
if ( V_167 )
goto V_178;
V_167 = F_51 ( V_6 ) ;
if ( V_167 )
goto V_179;
V_6 -> V_154 = V_166 ;
V_6 -> V_151 = V_165 ;
F_52 ( V_6 ) ;
F_53 ( V_6 ) ;
F_36 ( V_165 ) ;
F_36 ( V_166 ) ;
V_6 -> V_154 = V_153 ;
V_6 -> V_151 = V_150 ;
V_167 = F_16 ( V_6 ) ;
if ( V_167 )
goto V_180;
}
F_13 ( V_64 , & V_6 -> V_65 ) ;
return 0 ;
V_179:
F_52 ( V_6 ) ;
V_178:
V_6 -> V_154 = V_166 ;
V_6 -> V_151 = V_165 ;
F_36 ( V_153 ) ;
V_173:
F_36 ( V_150 ) ;
V_171:
F_16 ( V_6 ) ;
V_180:
F_13 ( V_64 , & V_6 -> V_65 ) ;
return V_167 ;
}
static bool F_54 ( struct V_5 * V_6 , T_5 * V_81 , int V_181 ,
T_1 V_182 , T_1 V_183 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
static const T_1 V_184 [] =
{ 0x5A5A5A5A , 0xA5A5A5A5 , 0x00000000 , 0xFFFFFFFF } ;
T_3 T_6 * V_185 = V_8 -> V_186 + V_181 ;
T_1 V_187 ;
int V_126 ;
for ( V_126 = 0 ; V_126 < F_55 ( V_184 ) ; V_126 ++ ) {
F_56 ( V_183 & V_184 [ V_126 ] , V_185 ) ;
V_187 = F_57 ( V_185 ) ;
if ( V_187 != ( V_183 & V_184 [ V_126 ] & V_182 ) ) {
F_8 ( V_62 , L_2
L_3 ,
V_181 , V_187 , ( V_183 & V_184 [ V_126 ] & V_182 ) ) ;
* V_81 = V_181 ;
return true ;
}
}
return false ;
}
static bool F_58 ( struct V_5 * V_6 , T_5 * V_81 , int V_181 ,
T_1 V_182 , T_1 V_183 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_3 T_6 * V_185 = V_8 -> V_186 + V_181 ;
T_1 V_187 ;
F_56 ( V_183 & V_182 , V_185 ) ;
V_187 = F_57 ( V_185 ) ;
if ( ( V_187 & V_182 ) != ( V_183 & V_182 ) ) {
F_8 ( V_62 , L_4
L_3 ,
V_181 , ( V_187 & V_182 ) , ( V_183 & V_182 ) ) ;
* V_81 = V_181 ;
return true ;
}
return false ;
}
static int F_59 ( struct V_5 * V_6 , T_5 * V_81 )
{
T_1 V_188 , V_189 , V_190 ;
T_1 V_126 , V_191 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_191 = 0xFFFFF833 ;
V_189 = F_3 ( V_38 ) ;
V_188 = ( F_3 ( V_38 ) & V_191 ) ;
F_60 ( V_38 , V_191 ) ;
V_190 = F_3 ( V_38 ) & V_191 ;
if ( V_188 != V_190 ) {
F_8 ( V_62 , L_5
L_6 , V_190 , V_188 ) ;
* V_81 = 1 ;
return 1 ;
}
F_60 ( V_38 , V_189 ) ;
F_61 ( V_192 , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_61 ( V_193 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_61 ( V_194 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_61 ( V_195 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_61 ( V_95 , 0x0000FFFF , 0xFFFFFFFF ) ;
F_61 ( V_196 , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_61 ( V_92 , 0x000FFF80 , 0x000FFFFF ) ;
F_61 ( V_93 , 0x0000FFFF , 0x0000FFFF ) ;
F_61 ( V_94 , 0x0000FFFF , 0x0000FFFF ) ;
F_61 ( V_197 , 0x0000FFF8 , 0x0000FFF8 ) ;
F_61 ( V_198 , 0x0000FFFF , 0x0000FFFF ) ;
F_61 ( V_199 , 0x3FFFFFFF , 0x3FFFFFFF ) ;
F_61 ( V_200 , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_61 ( V_97 , 0x000FFF80 , 0x000FFFFF ) ;
F_62 ( V_91 , 0xFFFFFFFF , 0x00000000 ) ;
V_189 = 0x06DFB3FE ;
F_62 ( V_91 , V_189 , 0x003FFFFB ) ;
F_62 ( V_96 , 0xFFFFFFFF , 0x00000000 ) ;
if ( V_8 -> V_28 >= V_29 ) {
F_62 ( V_91 , V_189 , 0xFFFFFFFF ) ;
F_61 ( V_201 , 0xFFFFFFF0 , 0xFFFFFFFF ) ;
F_61 ( V_202 , 0xC000FFFF , 0x0000FFFF ) ;
F_61 ( V_203 , 0xFFFFFFF0 , 0xFFFFFFFF ) ;
F_61 ( V_100 , 0x0000FFFF , 0x0000FFFF ) ;
V_188 = V_204 ;
for ( V_126 = 0 ; V_126 < V_188 ; V_126 ++ ) {
F_61 ( V_205 + ( ( ( V_126 << 1 ) + 1 ) << 2 ) , 0x8003FFFF ,
0xFFFFFFFF ) ;
}
} else {
F_62 ( V_91 , 0xFFFFFFFF , 0x01FFFFFF ) ;
F_61 ( V_201 , 0xFFFFF000 , 0xFFFFFFFF ) ;
F_61 ( V_202 , 0x0000FFFF , 0x0000FFFF ) ;
F_61 ( V_203 , 0xFFFFF000 , 0xFFFFFFFF ) ;
}
V_188 = V_206 ;
for ( V_126 = 0 ; V_126 < V_188 ; V_126 ++ )
F_61 ( V_207 + ( V_126 << 2 ) , 0xFFFFFFFF , 0xFFFFFFFF ) ;
* V_81 = 0 ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 , T_5 * V_81 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 V_208 ;
T_2 V_209 = 0 ;
T_2 V_126 ;
* V_81 = 0 ;
for ( V_126 = 0 ; V_126 < ( V_137 + 1 ) ; V_126 ++ ) {
if ( ( F_34 ( V_8 , V_126 , 1 , & V_208 ) ) < 0 ) {
* V_81 = 1 ;
break;
}
V_209 += V_208 ;
}
if ( ( V_209 != ( T_2 ) V_210 ) && ! ( * V_81 ) )
* V_81 = 2 ;
return * V_81 ;
}
static T_7 F_64 ( int V_211 , void * V_81 )
{
struct V_1 * V_2 = (struct V_1 * ) V_81 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_6 -> V_212 |= F_3 ( V_213 ) ;
return V_214 ;
}
static int F_65 ( struct V_5 * V_6 , T_5 * V_81 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
T_1 V_182 , V_126 = 0 ;
bool V_215 = true ;
T_1 V_211 = V_6 -> V_144 -> V_211 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
* V_81 = 0 ;
if ( ! F_66 ( V_211 , F_64 , V_216 , V_2 -> V_217 ,
V_2 ) )
V_215 = false ;
else if ( F_66 ( V_211 , F_64 , V_218 ,
V_2 -> V_217 , V_2 ) ) {
* V_81 = 1 ;
return - 1 ;
}
F_67 ( V_8 , L_7 , ( V_215 ?
L_8 : L_9 ) ) ;
F_60 ( V_219 , 0xFFFFFFFF ) ;
F_68 () ;
F_10 ( 10 ) ;
for (; V_126 < 10 ; V_126 ++ ) {
V_182 = 1 << V_126 ;
if ( ! V_215 ) {
V_6 -> V_212 = 0 ;
F_60 ( V_219 , V_182 ) ;
F_60 ( V_220 , V_182 ) ;
F_68 () ;
F_10 ( 10 ) ;
if ( V_6 -> V_212 & V_182 ) {
* V_81 = 3 ;
break;
}
}
V_6 -> V_212 = 0 ;
F_60 ( V_221 , V_182 ) ;
F_60 ( V_220 , V_182 ) ;
F_68 () ;
F_10 ( 10 ) ;
if ( ! ( V_6 -> V_212 & V_182 ) ) {
* V_81 = 4 ;
break;
}
if ( ! V_215 ) {
V_6 -> V_212 = 0 ;
F_60 ( V_219 , ~ V_182 & 0x00007FFF ) ;
F_60 ( V_220 , ~ V_182 & 0x00007FFF ) ;
F_68 () ;
F_10 ( 10 ) ;
if ( V_6 -> V_212 ) {
* V_81 = 5 ;
break;
}
}
}
F_60 ( V_219 , 0xFFFFFFFF ) ;
F_68 () ;
F_10 ( 10 ) ;
F_69 ( V_211 , V_2 ) ;
return * V_81 ;
}
static void F_70 ( struct V_5 * V_6 )
{
struct V_149 * V_150 = & V_6 -> V_222 ;
struct V_152 * V_153 = & V_6 -> V_223 ;
struct V_224 * V_144 = V_6 -> V_144 ;
int V_126 ;
if ( V_150 -> V_225 && V_150 -> V_226 ) {
for ( V_126 = 0 ; V_126 < V_150 -> V_163 ; V_126 ++ ) {
if ( V_150 -> V_226 [ V_126 ] . V_227 )
F_71 ( & V_144 -> V_228 ,
V_150 -> V_226 [ V_126 ] . V_227 ,
V_150 -> V_226 [ V_126 ] . V_229 ,
V_230 ) ;
if ( V_150 -> V_226 [ V_126 ] . V_231 )
F_72 ( V_150 -> V_226 [ V_126 ] . V_231 ) ;
}
}
if ( V_153 -> V_225 && V_153 -> V_226 ) {
for ( V_126 = 0 ; V_126 < V_153 -> V_163 ; V_126 ++ ) {
if ( V_153 -> V_226 [ V_126 ] . V_227 )
F_71 ( & V_144 -> V_228 ,
V_153 -> V_226 [ V_126 ] . V_227 ,
V_153 -> V_226 [ V_126 ] . V_229 ,
V_232 ) ;
if ( V_153 -> V_226 [ V_126 ] . V_231 )
F_72 ( V_153 -> V_226 [ V_126 ] . V_231 ) ;
}
}
if ( V_150 -> V_225 ) {
F_73 ( & V_144 -> V_228 , V_150 -> V_233 , V_150 -> V_225 ,
V_150 -> V_227 ) ;
V_150 -> V_225 = NULL ;
}
if ( V_153 -> V_225 ) {
F_73 ( & V_144 -> V_228 , V_153 -> V_233 , V_153 -> V_225 ,
V_153 -> V_227 ) ;
V_153 -> V_225 = NULL ;
}
F_36 ( V_150 -> V_226 ) ;
V_150 -> V_226 = NULL ;
F_36 ( V_153 -> V_226 ) ;
V_153 -> V_226 = NULL ;
}
static int F_74 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_149 * V_150 = & V_6 -> V_222 ;
struct V_152 * V_153 = & V_6 -> V_223 ;
struct V_224 * V_144 = V_6 -> V_144 ;
T_1 V_234 ;
int V_126 , V_125 ;
if ( ! V_150 -> V_163 )
V_150 -> V_163 = V_235 ;
V_150 -> V_226 = F_46 ( V_150 -> V_163 , sizeof( struct V_236 ) ,
V_131 ) ;
if ( ! V_150 -> V_226 ) {
V_125 = 1 ;
goto V_237;
}
V_150 -> V_233 = V_150 -> V_163 * sizeof( struct V_238 ) ;
V_150 -> V_233 = F_49 ( V_150 -> V_233 , 4096 ) ;
V_150 -> V_225 = F_75 ( & V_144 -> V_228 , V_150 -> V_233 , & V_150 -> V_227 ,
V_131 ) ;
if ( ! V_150 -> V_225 ) {
V_125 = 2 ;
goto V_237;
}
V_150 -> V_239 = V_150 -> V_240 = 0 ;
F_60 ( V_203 , ( ( T_5 ) V_150 -> V_227 & 0x00000000FFFFFFFF ) ) ;
F_60 ( V_200 , ( ( T_5 ) V_150 -> V_227 >> 32 ) ) ;
F_60 ( V_97 , V_150 -> V_163 * sizeof( struct V_238 ) ) ;
F_60 ( V_98 , 0 ) ;
F_60 ( V_99 , 0 ) ;
F_60 ( V_96 , V_241 | V_242 |
V_243 << V_244 |
V_245 << V_246 ) ;
for ( V_126 = 0 ; V_126 < V_150 -> V_163 ; V_126 ++ ) {
struct V_238 * V_247 = F_76 ( * V_150 , V_126 ) ;
struct V_248 * V_231 ;
unsigned int V_233 = 1024 ;
V_231 = F_77 ( V_233 , V_131 ) ;
if ( ! V_231 ) {
V_125 = 3 ;
goto V_237;
}
F_78 ( V_231 , V_233 ) ;
V_150 -> V_226 [ V_126 ] . V_231 = V_231 ;
V_150 -> V_226 [ V_126 ] . V_229 = V_231 -> V_127 ;
V_150 -> V_226 [ V_126 ] . V_227 =
F_79 ( & V_144 -> V_228 , V_231 -> V_81 , V_231 -> V_127 ,
V_230 ) ;
if ( F_80 ( & V_144 -> V_228 , V_150 -> V_226 [ V_126 ] . V_227 ) ) {
V_125 = 4 ;
goto V_237;
}
V_247 -> V_249 = F_81 ( V_150 -> V_226 [ V_126 ] . V_227 ) ;
V_247 -> V_250 . V_81 = F_82 ( V_231 -> V_127 ) ;
V_247 -> V_250 . V_81 |= F_82 ( V_251 |
V_252 |
V_253 ) ;
V_247 -> V_254 . V_81 = 0 ;
}
if ( ! V_153 -> V_163 )
V_153 -> V_163 = V_255 ;
V_153 -> V_226 = F_46 ( V_153 -> V_163 , sizeof( struct V_236 ) ,
V_131 ) ;
if ( ! V_153 -> V_226 ) {
V_125 = 5 ;
goto V_237;
}
V_153 -> V_233 = V_153 -> V_163 * sizeof( struct V_256 ) ;
V_153 -> V_225 = F_75 ( & V_144 -> V_228 , V_153 -> V_233 , & V_153 -> V_227 ,
V_131 ) ;
if ( ! V_153 -> V_225 ) {
V_125 = 6 ;
goto V_237;
}
V_153 -> V_239 = V_153 -> V_240 = 0 ;
V_234 = F_3 ( V_91 ) ;
F_60 ( V_91 , V_234 & ~ V_257 ) ;
F_60 ( V_201 , ( ( T_5 ) V_153 -> V_227 & 0xFFFFFFFF ) ) ;
F_60 ( V_196 , ( ( T_5 ) V_153 -> V_227 >> 32 ) ) ;
F_60 ( V_92 , V_153 -> V_233 ) ;
F_60 ( V_93 , 0 ) ;
F_60 ( V_94 , 0 ) ;
V_234 = V_257 | V_258 | V_259 |
V_260 | V_261 |
( V_8 -> V_262 << V_263 ) ;
F_60 ( V_91 , V_234 ) ;
for ( V_126 = 0 ; V_126 < V_153 -> V_163 ; V_126 ++ ) {
struct V_256 * V_264 = F_83 ( * V_153 , V_126 ) ;
struct V_248 * V_231 ;
V_231 = F_77 ( V_265 + V_266 , V_131 ) ;
if ( ! V_231 ) {
V_125 = 7 ;
goto V_237;
}
F_84 ( V_231 , V_266 ) ;
V_153 -> V_226 [ V_126 ] . V_231 = V_231 ;
V_153 -> V_226 [ V_126 ] . V_229 = V_265 ;
V_153 -> V_226 [ V_126 ] . V_227 =
F_79 ( & V_144 -> V_228 , V_231 -> V_81 ,
V_265 , V_232 ) ;
if ( F_80 ( & V_144 -> V_228 , V_153 -> V_226 [ V_126 ] . V_227 ) ) {
V_125 = 8 ;
goto V_237;
}
V_264 -> V_249 = F_81 ( V_153 -> V_226 [ V_126 ] . V_227 ) ;
memset ( V_231 -> V_81 , 0x00 , V_231 -> V_127 ) ;
}
return 0 ;
V_237:
F_70 ( V_6 ) ;
return V_125 ;
}
static void F_85 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
F_29 ( V_8 , 29 , 0x001F ) ;
F_29 ( V_8 , 30 , 0x8FFC ) ;
F_29 ( V_8 , 29 , 0x001A ) ;
F_29 ( V_8 , 30 , 0x8FF0 ) ;
}
static void F_86 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 V_267 ;
F_30 ( V_8 , V_268 , & V_267 ) ;
V_267 |= V_269 ;
F_29 ( V_8 ,
V_268 , V_267 ) ;
F_30 ( V_8 , V_111 , & V_267 ) ;
V_267 |= V_270 ;
F_29 ( V_8 ,
V_111 , V_267 ) ;
}
static int F_87 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_271 ;
T_2 V_267 ;
V_271 = F_3 ( V_90 ) ;
V_271 |= ( V_272 |
V_273 |
V_274 |
V_275 |
V_276 ) ;
F_60 ( V_90 , V_271 ) ;
F_30 ( V_8 , V_111 , & V_267 ) ;
V_267 &= ~ V_277 ;
F_29 ( V_8 , V_111 , V_267 ) ;
F_88 ( V_8 ) ;
F_86 ( V_6 ) ;
F_29 ( V_8 , V_278 , 0x8100 ) ;
F_89 ( 500 ) ;
F_86 ( V_6 ) ;
F_85 ( V_6 ) ;
F_30 ( V_8 , V_278 , & V_267 ) ;
V_267 |= V_279 ;
F_29 ( V_8 , V_278 , V_267 ) ;
F_86 ( V_6 ) ;
F_30 ( V_8 , V_278 , & V_267 ) ;
if ( V_267 != 0x4100 )
return 9 ;
F_30 ( V_8 , V_268 , & V_267 ) ;
if ( V_267 != 0x0070 )
return 10 ;
F_30 ( V_8 , 29 , & V_267 ) ;
if ( V_267 != 0x001A )
return 11 ;
return 0 ;
}
static int F_90 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_271 = 0 ;
T_1 V_280 = 0 ;
V_8 -> V_21 = false ;
if ( V_8 -> V_101 == V_281 ) {
F_29 ( V_8 ,
V_111 , 0x0808 ) ;
F_29 ( V_8 , V_278 , 0x9140 ) ;
F_29 ( V_8 , V_278 , 0x8140 ) ;
}
V_271 = F_3 ( V_90 ) ;
F_29 ( V_8 , V_278 , 0x4140 ) ;
V_271 = F_3 ( V_90 ) ;
V_271 &= ~ V_282 ;
V_271 |= ( V_273 |
V_274 |
V_275 |
V_276 ) ;
if ( V_8 -> V_9 == V_10 &&
V_8 -> V_101 == V_281 )
V_271 |= V_272 ;
else {
V_280 = F_3 ( V_38 ) ;
if ( ( V_280 & V_283 ) == 0 )
V_271 |= ( V_272 | V_284 ) ;
}
F_60 ( V_90 , V_271 ) ;
if ( V_8 -> V_101 == V_281 )
F_85 ( V_6 ) ;
F_89 ( 500 ) ;
return 0 ;
}
static int F_91 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_2 V_267 = 0 ;
T_2 V_163 = 0 ;
switch ( V_8 -> V_28 ) {
case V_29 :
if ( V_8 -> V_9 == V_10 ) {
while ( F_87 ( V_6 ) &&
V_163 ++ < 10 ) ;
if ( V_163 < 11 )
return 0 ;
}
break;
case V_156 :
case V_116 :
case V_37 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
return F_90 ( V_6 ) ;
break;
default:
F_30 ( V_8 , V_278 , & V_267 ) ;
V_267 |= V_279 ;
F_29 ( V_8 , V_278 , V_267 ) ;
return 0 ;
break;
}
return 8 ;
}
static int F_92 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_234 ;
if ( V_8 -> V_9 == V_48 ||
V_8 -> V_9 == V_292 ) {
switch ( V_8 -> V_28 ) {
case V_37 :
case V_286 :
case V_285 :
case V_287 :
return F_91 ( V_6 ) ;
break;
default:
V_234 = F_3 ( V_91 ) ;
V_234 |= V_293 ;
F_60 ( V_91 , V_234 ) ;
return 0 ;
}
} else if ( V_8 -> V_9 == V_10 )
return F_91 ( V_6 ) ;
return 7 ;
}
static void F_93 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_234 ;
T_2 V_267 ;
V_234 = F_3 ( V_91 ) ;
V_234 &= ~ ( V_293 | V_294 ) ;
F_60 ( V_91 , V_234 ) ;
switch ( V_8 -> V_28 ) {
case V_37 :
case V_286 :
case V_285 :
case V_287 :
default:
V_8 -> V_21 = true ;
F_30 ( V_8 , V_278 , & V_267 ) ;
if ( V_267 & V_279 ) {
V_267 &= ~ V_279 ;
F_29 ( V_8 , V_278 , V_267 ) ;
F_88 ( V_8 ) ;
}
break;
}
}
static void F_94 ( struct V_248 * V_231 ,
unsigned int V_295 )
{
memset ( V_231 -> V_81 , 0xFF , V_295 ) ;
V_295 &= ~ 1 ;
memset ( & V_231 -> V_81 [ V_295 / 2 ] , 0xAA , V_295 / 2 - 1 ) ;
memset ( & V_231 -> V_81 [ V_295 / 2 + 10 ] , 0xBE , 1 ) ;
memset ( & V_231 -> V_81 [ V_295 / 2 + 12 ] , 0xAF , 1 ) ;
}
static int F_95 ( struct V_248 * V_231 ,
unsigned int V_295 )
{
V_295 &= ~ 1 ;
if ( * ( V_231 -> V_81 + 3 ) == 0xFF ) {
if ( ( * ( V_231 -> V_81 + V_295 / 2 + 10 ) == 0xBE ) &&
( * ( V_231 -> V_81 + V_295 / 2 + 12 ) == 0xAF ) ) {
return 0 ;
}
}
return 13 ;
}
static int F_96 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_149 * V_150 = & V_6 -> V_222 ;
struct V_152 * V_153 = & V_6 -> V_223 ;
struct V_224 * V_144 = V_6 -> V_144 ;
int V_126 , V_296 , V_297 , V_298 , V_299 , V_300 , V_125 = 0 ;
unsigned long time ;
F_60 ( V_94 , V_153 -> V_163 - 1 ) ;
if ( V_153 -> V_163 <= V_150 -> V_163 )
V_299 = ( ( V_150 -> V_163 / 64 ) * 2 ) + 1 ;
else
V_299 = ( ( V_153 -> V_163 / 64 ) * 2 ) + 1 ;
V_297 = V_298 = 0 ;
for ( V_296 = 0 ; V_296 <= V_299 ; V_296 ++ ) {
for ( V_126 = 0 ; V_126 < 64 ; V_126 ++ ) {
F_94 ( V_150 -> V_226 [ V_126 ] . V_231 ,
1024 ) ;
F_97 ( & V_144 -> V_228 ,
V_150 -> V_226 [ V_297 ] . V_227 ,
V_150 -> V_226 [ V_297 ] . V_229 ,
V_230 ) ;
if ( F_98 ( ++ V_297 == V_150 -> V_163 ) ) V_297 = 0 ;
}
F_60 ( V_99 , V_297 ) ;
F_68 () ;
F_10 ( 200 ) ;
time = V_301 ;
V_300 = 0 ;
do {
F_99 ( & V_144 -> V_228 ,
V_153 -> V_226 [ V_298 ] . V_227 ,
V_153 -> V_226 [ V_298 ] . V_229 ,
V_232 ) ;
V_125 = F_95 (
V_153 -> V_226 [ V_298 ] . V_231 ,
1024 ) ;
if ( ! V_125 )
V_300 ++ ;
if ( F_98 ( ++ V_298 == V_153 -> V_163 ) ) V_298 = 0 ;
} while ( V_300 < 64 && F_100 ( time + 20 , V_301 ) );
if ( V_300 != 64 ) {
V_125 = 13 ;
break;
}
if ( V_301 >= ( time + 2 ) ) {
V_125 = 14 ;
break;
}
}
return V_125 ;
}
static int F_101 ( struct V_5 * V_6 , T_5 * V_81 )
{
* V_81 = F_74 ( V_6 ) ;
if ( * V_81 )
goto V_302;
* V_81 = F_92 ( V_6 ) ;
if ( * V_81 )
goto V_303;
* V_81 = F_96 ( V_6 ) ;
F_93 ( V_6 ) ;
V_303:
F_70 ( V_6 ) ;
V_302:
return * V_81 ;
}
static int F_102 ( struct V_5 * V_6 , T_5 * V_81 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
* V_81 = 0 ;
if ( V_8 -> V_9 == V_292 ) {
int V_126 = 0 ;
V_8 -> V_304 = false ;
do {
F_103 ( V_8 ) ;
if ( V_8 -> V_304 )
return * V_81 ;
F_10 ( 20 ) ;
} while ( V_126 ++ < 3750 );
* V_81 = 1 ;
} else {
F_103 ( V_8 ) ;
if ( V_8 -> V_21 )
F_10 ( 4000 ) ;
if ( ! ( F_3 ( V_38 ) & V_39 ) ) {
* V_81 = 1 ;
}
}
return * V_81 ;
}
static int F_104 ( struct V_1 * V_2 , int V_305 )
{
switch ( V_305 ) {
case V_306 :
return V_307 ;
case V_308 :
return V_309 ;
default:
return - V_61 ;
}
}
static void F_105 ( struct V_1 * V_2 ,
struct V_310 * V_311 , T_5 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
bool V_312 = F_14 ( V_2 ) ;
F_106 ( V_313 , & V_6 -> V_65 ) ;
if ( V_311 -> V_65 == V_314 ) {
T_2 V_23 = V_8 -> V_23 ;
T_3 V_315 = V_8 -> V_315 ;
T_3 V_21 = V_8 -> V_21 ;
F_67 ( V_8 , L_10 ) ;
if ( F_102 ( V_6 , & V_81 [ 4 ] ) )
V_311 -> V_65 |= V_316 ;
if ( V_312 )
F_107 ( V_2 ) ;
else
F_17 ( V_6 ) ;
if ( F_59 ( V_6 , & V_81 [ 0 ] ) )
V_311 -> V_65 |= V_316 ;
F_17 ( V_6 ) ;
if ( F_63 ( V_6 , & V_81 [ 1 ] ) )
V_311 -> V_65 |= V_316 ;
F_17 ( V_6 ) ;
if ( F_65 ( V_6 , & V_81 [ 2 ] ) )
V_311 -> V_65 |= V_316 ;
F_17 ( V_6 ) ;
F_108 ( V_6 ) ;
if ( F_101 ( V_6 , & V_81 [ 3 ] ) )
V_311 -> V_65 |= V_316 ;
V_8 -> V_23 = V_23 ;
V_8 -> V_315 = V_315 ;
V_8 -> V_21 = V_21 ;
F_17 ( V_6 ) ;
F_13 ( V_313 , & V_6 -> V_65 ) ;
if ( V_312 )
F_109 ( V_2 ) ;
} else {
F_67 ( V_8 , L_11 ) ;
if ( F_102 ( V_6 , & V_81 [ 4 ] ) )
V_311 -> V_65 |= V_316 ;
V_81 [ 0 ] = 0 ;
V_81 [ 1 ] = 0 ;
V_81 [ 2 ] = 0 ;
V_81 [ 3 ] = 0 ;
F_13 ( V_313 , & V_6 -> V_65 ) ;
}
F_110 ( 4 * 1000 ) ;
}
static int F_111 ( struct V_5 * V_6 ,
struct V_317 * V_318 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
int V_77 = 1 ;
switch ( V_8 -> V_89 ) {
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
V_318 -> V_11 = 0 ;
break;
case V_328 :
case V_329 :
if ( F_3 ( V_38 ) & V_330 ) {
V_318 -> V_11 = 0 ;
break;
}
V_77 = 0 ;
break;
case V_331 :
if ( ! V_6 -> V_332 ) {
V_318 -> V_11 = 0 ;
break;
}
V_77 = 0 ;
break;
default:
if ( F_3 ( V_38 ) & V_330 &&
! V_6 -> V_333 ) {
V_318 -> V_11 = 0 ;
break;
}
V_77 = 0 ;
}
return V_77 ;
}
static void F_112 ( struct V_1 * V_2 ,
struct V_317 * V_318 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
V_318 -> V_11 = V_334 | V_335 |
V_336 | V_337 ;
V_318 -> V_338 = 0 ;
if ( F_111 ( V_6 , V_318 ) ||
! F_113 ( & V_6 -> V_144 -> V_228 ) )
return;
switch ( V_8 -> V_89 ) {
case V_331 :
V_318 -> V_11 &= ~ V_334 ;
if ( V_6 -> V_318 & V_339 )
F_8 ( V_62 , L_12
L_13 ) ;
break;
default:
break;
}
if ( V_6 -> V_318 & V_339 )
V_318 -> V_338 |= V_334 ;
if ( V_6 -> V_318 & V_340 )
V_318 -> V_338 |= V_335 ;
if ( V_6 -> V_318 & V_341 )
V_318 -> V_338 |= V_336 ;
if ( V_6 -> V_318 & V_342 )
V_318 -> V_338 |= V_337 ;
}
static int F_114 ( struct V_1 * V_2 , struct V_317 * V_318 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( V_318 -> V_338 & ( V_343 | V_344 | V_345 ) )
return - V_61 ;
if ( F_111 ( V_6 , V_318 ) ||
! F_113 ( & V_6 -> V_144 -> V_228 ) )
return V_318 -> V_338 ? - V_61 : 0 ;
switch ( V_8 -> V_89 ) {
case V_331 :
if ( V_318 -> V_338 & V_334 ) {
F_8 ( V_62 , L_12
L_13 ) ;
return - V_61 ;
}
break;
default:
break;
}
V_6 -> V_318 = 0 ;
if ( V_318 -> V_338 & V_334 )
V_6 -> V_318 |= V_339 ;
if ( V_318 -> V_338 & V_335 )
V_6 -> V_318 |= V_340 ;
if ( V_318 -> V_338 & V_336 )
V_6 -> V_318 |= V_341 ;
if ( V_318 -> V_338 & V_337 )
V_6 -> V_318 |= V_342 ;
F_115 ( & V_6 -> V_144 -> V_228 , V_6 -> V_318 ) ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 ,
enum V_346 V_347 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
switch ( V_347 ) {
case V_348 :
F_117 ( V_8 ) ;
return 2 ;
case V_349 :
F_118 ( V_8 ) ;
break;
case V_350 :
F_119 ( V_8 ) ;
break;
case V_351 :
F_120 ( V_8 ) ;
}
return 0 ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_352 * V_353 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_8 . V_28 < V_37 )
return - V_61 ;
if ( V_6 -> V_354 <= 4 )
V_353 -> V_355 = V_6 -> V_354 ;
else
V_353 -> V_355 = 1000000 / V_6 -> V_354 ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_352 * V_353 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( V_8 -> V_28 < V_37 )
return - V_61 ;
if ( ( V_353 -> V_355 > V_356 ) ||
( ( V_353 -> V_355 > 4 ) &&
( V_353 -> V_355 < V_357 ) ) ||
( V_353 -> V_355 == 2 ) )
return - V_63 ;
if ( V_353 -> V_355 == 4 ) {
V_6 -> V_358 = V_6 -> V_354 = 4 ;
} else if ( V_353 -> V_355 <= 3 ) {
V_6 -> V_358 = 20000 ;
V_6 -> V_354 = V_353 -> V_355 ;
} else {
V_6 -> V_358 = ( 1000000 / V_353 -> V_355 ) ;
V_6 -> V_354 = V_6 -> V_358 & ~ 3 ;
}
if ( V_6 -> V_354 != 0 )
F_60 ( V_359 , 1000000000 / ( V_6 -> V_358 * 256 ) ) ;
else
F_60 ( V_359 , 0 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_14 ( V_2 ) )
F_124 ( V_6 ) ;
return 0 ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_360 * V_361 , T_5 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_126 ;
char * V_84 = NULL ;
F_126 ( V_6 ) ;
for ( V_126 = 0 ; V_126 < V_362 ; V_126 ++ ) {
switch ( V_363 [ V_126 ] . type ) {
case V_364 :
V_84 = ( char * ) V_2 +
V_363 [ V_126 ] . V_365 ;
break;
case V_366 :
V_84 = ( char * ) V_6 +
V_363 [ V_126 ] . V_365 ;
break;
}
V_81 [ V_126 ] = ( V_363 [ V_126 ] . V_367 ==
sizeof( T_5 ) ) ? * ( T_5 * ) V_84 : * ( T_1 * ) V_84 ;
}
}
static void F_127 ( struct V_1 * V_2 , T_1 V_368 ,
T_3 * V_81 )
{
T_3 * V_84 = V_81 ;
int V_126 ;
switch ( V_368 ) {
case V_306 :
memcpy ( V_81 , * V_369 ,
sizeof( V_369 ) ) ;
break;
case V_308 :
for ( V_126 = 0 ; V_126 < V_362 ; V_126 ++ ) {
memcpy ( V_84 , V_363 [ V_126 ] . V_370 ,
V_371 ) ;
V_84 += V_371 ;
}
break;
}
}
void F_128 ( struct V_1 * V_2 )
{
V_2 -> V_372 = & V_373 ;
}
