static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 0 , V_6 ;
unsigned short V_7 , V_8 ;
static const char * V_9 [ 12 ] = {
L_1 , L_2 , L_3 , L_4 ,
L_5 , L_6 , L_7 , L_8 , L_9 , L_10 ,
L_11 , L_12
} ;
static const char * V_10 [ 8 ] = {
L_13 , L_14 , L_15 , L_16 ,
L_17 , L_17 , L_17 , L_18
} ;
for ( V_6 = 0 ; V_6 < 12 ; ++ V_6 ) {
F_2 ( V_2 , V_11 , V_6 << 1 ) ;
V_7 = F_3 ( V_2 , V_12 ) ;
if ( ! ( V_7 & 0x0001 ) )
continue;
if ( ! V_5 ) {
F_4 ( V_4 , L_19 ) ;
V_5 = 1 ;
}
V_8 = F_3 ( V_2 , V_13 ) ;
F_4 ( V_4 , L_20 ,
V_9 [ V_6 ] ,
( V_7 & 0x8000 ? - 1 : 1 ) * ( ( V_7 & 0x7000 ) >> 12 ) * 3 / 2 ,
( ( V_7 & 0x0800 ) >> 11 ) * 5 ,
V_7 & 0x0400 ? 'X' : '-' ,
( V_7 & 0x03e0 ) >> 5 ,
V_10 [ V_8 >> 13 ] ) ;
}
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_14 )
{
char V_15 [ 64 ] ;
unsigned short V_16 , V_17 , V_18 , V_19 ;
static const char * V_20 [ 4 ] = { L_21 , L_22 , L_23 , L_24 } ;
static const char * V_21 [ 4 ] = { L_25 , L_26 , L_27 , L_28 } ;
static const char * V_22 [ 4 ] = { L_27 , L_25 , L_26 , L_26 } ;
static const char * V_23 [ 4 ] = { L_29 , L_30 , L_17 , L_17 } ;
F_6 ( NULL , V_2 -> V_24 , V_15 , 0 ) ;
F_4 ( V_4 , L_31 , V_2 -> V_25 , V_2 -> V_26 , V_14 , V_15 ) ;
if ( ( V_2 -> V_27 & V_28 ) == 0 )
goto V_29;
F_4 ( V_4 , L_32 ,
V_2 -> V_30 ) ;
F_4 ( V_4 , L_33 ,
V_2 -> V_31 ) ;
F_4 ( V_4 , L_34 , V_2 -> V_32 ) ;
if ( ( V_2 -> V_33 & V_34 ) >= V_35 ) {
V_16 = F_3 ( V_2 , V_36 ) ;
F_7 ( V_2 , V_36 ,
V_37 , V_38 ) ;
V_17 = F_3 ( V_2 , V_39 ) ;
F_4 ( V_4 , L_35 , V_17 & 0xff ) ;
F_4 ( V_4 , L_36 , ( V_17 >> 8 ) & 0x1f ) ;
F_4 ( V_4 , L_37 ,
F_3 ( V_2 , V_40 ) ) ;
F_4 ( V_4 , L_38 ,
F_3 ( V_2 , V_41 ) ) ;
F_7 ( V_2 , V_36 ,
V_37 , V_16 & V_37 ) ;
}
V_16 = V_2 -> V_42 ;
F_4 ( V_4 , L_39 ,
V_16 & V_43 ? L_40 : L_41 ,
V_16 & V_44 ? L_42 : L_41 ,
V_16 & V_45 ? L_43 : L_41 ,
V_16 & V_46 ? L_44 : L_41 ,
V_16 & V_47 ? L_45 : L_41 ,
V_16 & V_48 ? L_46 : L_41 ) ;
V_17 = V_2 -> V_42 & V_49 ;
F_4 ( V_4 , L_47 ,
V_17 == V_50 ? L_48 : L_41 ,
V_17 == V_51 ? L_49 : L_41 ,
V_17 == V_52 ? L_50 : L_41 ,
V_17 == V_49 ? L_51 : L_41 ) ;
V_17 = V_2 -> V_42 & V_53 ;
F_4 ( V_4 , L_52 ,
V_17 == V_54 ? L_48 : L_41 ,
V_17 == V_55 ? L_49 : L_41 ,
V_17 == V_56 ? L_50 : L_41 ,
V_17 == V_53 ? L_51 : L_41 ) ;
F_4 ( V_4 , L_53 ,
V_57 [ ( V_16 >> 10 ) & 0x1f ] ) ;
F_4 ( V_4 , L_54 ) ;
V_16 = F_3 ( V_2 , V_58 ) ;
F_4 ( V_4 , L_55 , V_16 & 0x0040 ? L_56 : L_57 , V_2 -> V_59 [ V_58 ] & 0x0040 ? L_56 : L_57 ) ;
V_16 = F_3 ( V_2 , V_60 ) ;
F_4 ( V_4 , L_58
L_59
L_53
L_60
L_61
L_62
L_63 ,
V_16 & 0x8000 ? L_64 : L_65 ,
V_16 & 0x4000 ? L_66 : L_67 ,
V_16 & 0x2000 ? L_66 : L_67 ,
V_16 & 0x1000 ? L_66 : L_67 ,
V_16 & 0x0200 ? L_68 : L_69 ,
V_16 & 0x0100 ? L_70 : L_71 ,
V_16 & 0x0080 ? L_66 : L_67 ) ;
if ( V_2 -> V_33 & V_61 )
F_4 ( V_4 , L_72 ,
V_23 [ ( V_16 >> 10 ) & 3 ] ) ;
V_18 = F_3 ( V_2 , V_62 ) ;
if ( V_18 == 0 )
goto V_29;
F_4 ( V_4 , L_73 ,
( V_18 & V_63 ) >> V_64 ,
( V_18 & V_34 ) >> V_65 ,
V_18 & V_66 ? L_74 : L_41 ,
V_18 & V_67 ? L_75 : L_41 ,
V_18 & V_68 ? L_76 : L_41 ,
V_18 & V_69 ? L_77 : L_41 ,
( V_18 & V_70 ) >> V_71 ,
V_18 & V_72 ? L_78 : L_41 ,
V_18 & V_73 ? L_79 : L_41 ,
V_18 & V_61 ? L_80 : L_41 ,
V_18 & V_74 ? L_81 : L_41 ) ;
V_16 = F_3 ( V_2 , V_75 ) ;
F_4 ( V_4 , L_82 ,
V_16 & V_76 ? L_83 : L_41 ,
V_16 & V_77 ? L_84 : L_41 ,
V_16 & V_78 ? L_85 : L_41 ,
V_16 & V_79 ? L_86 : L_41 ,
V_16 & V_80 ? L_87 : L_41 ,
V_16 & V_81 ? L_88 : L_41 ,
V_16 & V_82 ? L_75 : L_41 ,
V_16 & V_83 ? L_76 : L_41 ,
V_16 & V_84 ? L_77 : L_41 ,
V_18 & V_73 ? V_20 [ ( V_16 & V_85 ) >> V_86 ] : L_41 ,
V_16 & V_87 ? L_78 : L_41 ,
V_16 & V_88 ? L_79 : L_41 ,
V_16 & V_89 ? L_80 : L_41 ,
V_16 & V_90 ? L_81 : L_41 ) ;
if ( V_18 & V_74 ) {
V_16 = F_3 ( V_2 , V_91 ) ;
F_4 ( V_4 , L_89 , V_16 ) ;
if ( V_18 & V_68 ) {
V_16 = F_3 ( V_2 , V_92 ) ;
F_4 ( V_4 , L_90 , V_16 ) ;
}
if ( V_18 & V_67 ) {
V_16 = F_3 ( V_2 , V_93 ) ;
F_4 ( V_4 , L_91 , V_16 ) ;
}
V_16 = F_3 ( V_2 , V_94 ) ;
F_4 ( V_4 , L_92 , V_16 ) ;
}
if ( V_18 & V_72 ) {
V_16 = F_3 ( V_2 , V_95 ) ;
F_4 ( V_4 , L_93 , V_16 ) ;
}
if ( ( V_18 & V_73 ) || ( V_2 -> V_32 & V_96 ) ||
( V_2 -> V_24 == V_97 ) ) {
if ( V_2 -> V_32 & V_96 )
V_16 = F_3 ( V_2 , V_98 ) ;
else if ( V_2 -> V_24 == V_97 ) {
V_16 = F_3 ( V_2 , V_99 ) ;
V_16 = 0x2000 | ( V_16 & 0xff00 ) >> 4 | ( V_16 & 0x38 ) >> 2 ;
} else
V_16 = F_3 ( V_2 , V_100 ) ;
F_4 ( V_4 , L_94 ,
V_16 & V_101 ? L_95 : L_96 ,
V_16 & V_102 ? L_97 : L_98 ,
V_16 & V_103 ? L_41 : L_99 ,
V_16 & V_104 ? L_100 : L_41 ,
( V_16 & V_105 ) >> V_106 ,
( V_16 & V_107 ) >> 11 ,
( V_2 -> V_32 & V_96 ) ?
V_22 [ ( V_16 & V_108 ) >> V_109 ] :
V_21 [ ( V_16 & V_108 ) >> V_109 ] ,
( V_2 -> V_32 & V_96 ) ?
( V_16 & V_110 ? L_101 : L_41 ) :
( V_16 & V_110 ? L_102 : L_41 ) ,
( V_2 -> V_32 & V_96 ) ?
( V_16 & V_111 ? L_103 : L_41 ) :
( V_16 & V_111 ? L_101 : L_41 ) ) ;
if ( ( V_2 -> V_24 & 0xfffffff0 ) == 0x414c4720 &&
( F_3 ( V_2 , V_112 ) & 0x01 ) ) {
V_16 = F_3 ( V_2 , V_113 ) ;
if ( V_16 & V_114 ) {
V_16 = F_3 ( V_2 , V_115 ) ;
F_4 ( V_4 , L_104 ,
V_16 & V_116 ? L_95 : L_96 ,
V_16 & V_117 ? L_97 : L_98 ,
V_16 & V_118 ? L_41 : L_99 ,
V_16 & V_119 ? L_100 : L_41 ,
( V_16 & V_120 ) >> V_121 ,
( V_16 & V_122 ) >> 15 ) ;
V_16 = F_3 ( V_2 , V_113 ) ;
F_4 ( V_4 , L_105 ,
V_21 [ ( V_16 & V_123 ) >> V_124 ] ,
( V_16 & V_125 ) >> V_126 ,
( V_16 & V_114 ? L_106 : L_107 ) ,
( V_16 & V_127 ? L_108 : L_41 ) ) ;
} else {
F_4 ( V_4 , L_109 ) ;
}
}
}
if ( ( V_2 -> V_33 & V_34 ) >= V_35 ) {
V_16 = F_3 ( V_2 , V_36 ) ;
F_7 ( V_2 , V_36 ,
V_37 , V_38 ) ;
F_1 ( V_2 , V_4 ) ;
F_7 ( V_2 , V_36 ,
V_37 , V_16 & V_37 ) ;
}
V_29:
V_19 = F_3 ( V_2 , V_128 ) ;
if ( V_19 == 0 )
return;
F_4 ( V_4 , L_110 ,
( V_19 & V_129 ) >> V_130 ,
V_19 & V_131 ? L_111 : L_41 ,
V_19 & V_132 ? L_112 : L_41 ,
V_19 & V_133 ? L_113 : L_41 ,
V_19 & V_134 ? L_114 : L_41 ,
V_19 & V_135 ? L_115 : L_41 ) ;
V_16 = F_3 ( V_2 , V_136 ) ;
F_4 ( V_4 , L_116 ,
V_16 & V_137 ? L_117 : L_41 ,
V_16 & V_138 ? L_118 : L_41 ,
V_16 & V_139 ? L_119 : L_41 ,
V_16 & V_140 ? L_120 : L_41 ,
V_16 & V_141 ? L_121 : L_41 ,
V_16 & V_142 ? L_122 : L_41 ,
V_16 & V_143 ? L_123 : L_41 ,
V_16 & V_144 ? L_124 : L_41 ,
V_16 & V_145 ? L_125 : L_41 ,
V_16 & V_146 ? L_126 : L_41 ,
V_16 & V_147 ? L_127 : L_41 ,
V_16 & V_148 ? L_128 : L_41 ,
V_16 & V_149 ? L_129 : L_41 ,
V_16 & V_150 ? L_130 : L_41 ,
V_16 & V_151 ? L_131 : L_41 ,
V_16 & V_152 ? L_132 : L_41 ) ;
if ( V_19 & V_135 ) {
V_16 = F_3 ( V_2 , V_153 ) ;
F_4 ( V_4 , L_133 , V_16 ) ;
}
if ( V_19 & V_134 ) {
V_16 = F_3 ( V_2 , V_154 ) ;
F_4 ( V_4 , L_134 , V_16 ) ;
}
if ( V_19 & V_133 ) {
V_16 = F_3 ( V_2 , V_155 ) ;
F_4 ( V_4 , L_135 , V_16 ) ;
}
}
static void F_8 ( struct V_156 * V_157 , struct V_3 * V_4 )
{
struct V_1 * V_2 = V_157 -> V_158 ;
F_9 ( & V_2 -> V_159 ) ;
if ( ( V_2 -> V_24 & 0xffffff40 ) == V_160 ) {
int V_161 ;
for ( V_161 = 0 ; V_161 < 3 ; V_161 ++ )
if ( V_2 -> V_162 . V_163 . V_24 [ V_161 ] ) {
F_7 ( V_2 , V_164 , 0x7000 ,
V_2 -> V_162 . V_163 . V_165 [ V_161 ] | V_2 -> V_162 . V_163 . V_166 [ V_161 ] ) ;
F_5 ( V_2 , V_4 , V_161 ) ;
F_4 ( V_4 , L_136 ) ;
}
F_7 ( V_2 , V_164 , 0x7000 , 0x7000 ) ;
F_4 ( V_4 , L_137 ) ;
F_4 ( V_4 , L_138 ,
V_2 -> V_162 . V_163 . V_165 [ 0 ] ,
V_2 -> V_162 . V_163 . V_165 [ 1 ] ,
V_2 -> V_162 . V_163 . V_165 [ 2 ] ) ;
F_4 ( V_4 , L_139 ,
V_2 -> V_162 . V_163 . V_166 [ 0 ] ,
V_2 -> V_162 . V_163 . V_166 [ 1 ] ,
V_2 -> V_162 . V_163 . V_166 [ 2 ] ) ;
} else {
F_5 ( V_2 , V_4 , 0 ) ;
}
F_10 ( & V_2 -> V_159 ) ;
}
static void F_11 ( struct V_156 * V_157 , struct V_3 * V_4 )
{
struct V_1 * V_2 = V_157 -> V_158 ;
char line [ 64 ] ;
unsigned int V_167 , V_16 ;
F_9 ( & V_2 -> V_159 ) ;
while ( ! F_12 ( V_4 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_140 , & V_167 , & V_16 ) != 2 )
continue;
if ( V_167 < 0x80 && ( V_167 & 1 ) == 0 && V_16 <= 0xffff )
F_13 ( V_2 , V_167 , V_16 ) ;
}
F_10 ( & V_2 -> V_159 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_14 )
{
int V_167 , V_16 ;
for ( V_167 = 0 ; V_167 < 0x80 ; V_167 += 2 ) {
V_16 = F_3 ( V_2 , V_167 ) ;
F_4 ( V_4 , L_141 , V_14 , V_167 , V_16 ) ;
}
}
static void F_15 ( struct V_156 * V_157 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_157 -> V_158 ;
F_9 ( & V_2 -> V_159 ) ;
if ( ( V_2 -> V_24 & 0xffffff40 ) == V_160 ) {
int V_161 ;
for ( V_161 = 0 ; V_161 < 3 ; V_161 ++ )
if ( V_2 -> V_162 . V_163 . V_24 [ V_161 ] ) {
F_7 ( V_2 , V_164 , 0x7000 ,
V_2 -> V_162 . V_163 . V_165 [ V_161 ] | V_2 -> V_162 . V_163 . V_166 [ V_161 ] ) ;
F_14 ( V_2 , V_4 , V_161 ) ;
}
F_7 ( V_2 , V_164 , 0x7000 , 0x7000 ) ;
} else {
F_14 ( V_2 , V_4 , 0 ) ;
}
F_10 ( & V_2 -> V_159 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_156 * V_157 ;
char V_15 [ 32 ] ;
const char * V_168 ;
if ( V_2 -> V_169 -> V_170 == NULL )
return;
V_168 = F_17 ( V_2 ) ? L_142 : L_143 ;
sprintf ( V_15 , L_144 , V_168 , V_2 -> V_25 , V_2 -> V_26 ) ;
if ( ( V_157 = F_18 ( V_2 -> V_169 -> V_171 , V_15 , V_2 -> V_169 -> V_170 ) ) != NULL ) {
F_19 ( V_157 , V_2 , F_8 ) ;
if ( F_20 ( V_157 ) < 0 ) {
F_21 ( V_157 ) ;
V_157 = NULL ;
}
}
V_2 -> V_170 = V_157 ;
sprintf ( V_15 , L_145 , V_168 , V_2 -> V_25 , V_2 -> V_26 ) ;
if ( ( V_157 = F_18 ( V_2 -> V_169 -> V_171 , V_15 , V_2 -> V_169 -> V_170 ) ) != NULL ) {
F_19 ( V_157 , V_2 , F_15 ) ;
#ifdef F_22
V_157 -> V_172 |= V_173 ;
V_157 -> V_174 . V_175 . V_176 = F_11 ;
#endif
if ( F_20 ( V_157 ) < 0 ) {
F_21 ( V_157 ) ;
V_157 = NULL ;
}
}
V_2 -> V_177 = V_157 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_177 ) ;
V_2 -> V_177 = NULL ;
F_21 ( V_2 -> V_170 ) ;
V_2 -> V_170 = NULL ;
}
void F_24 ( struct V_178 * V_169 )
{
struct V_156 * V_157 ;
char V_15 [ 32 ] ;
sprintf ( V_15 , L_146 , V_169 -> V_26 ) ;
if ( ( V_157 = F_18 ( V_169 -> V_171 , V_15 , V_169 -> V_171 -> V_179 ) ) != NULL ) {
V_157 -> V_172 = V_180 | V_181 | V_182 ;
if ( F_20 ( V_157 ) < 0 ) {
F_21 ( V_157 ) ;
V_157 = NULL ;
}
}
V_169 -> V_170 = V_157 ;
}
void F_25 ( struct V_178 * V_169 )
{
F_21 ( V_169 -> V_170 ) ;
V_169 -> V_170 = NULL ;
}
