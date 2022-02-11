static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 ;
F_2 ( V_3 , V_7 , & V_6 ) ;
V_6 &= V_8 ;
F_3 ( & V_5 -> V_9 , L_1 ,
V_6 ? L_2 : L_3 ) ;
V_2 -> V_10 = V_6 ? true : false ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_3 ( & V_5 -> V_9 , L_4 ) ;
if ( ! V_2 -> V_10 )
F_5 ( V_3 , V_11 , V_12 , 0 ) ;
}
static void F_6 ( struct V_1 * V_2 , char V_13 )
{
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 * V_17 , V_18 , V_19 , V_20 ;
switch ( V_13 ) {
case 'U' :
V_17 = & V_15 -> V_21 ;
V_18 = V_22 ;
V_20 = V_23 ;
break;
case 'Q' :
V_17 = & V_15 -> V_24 ;
V_18 = V_25 ;
V_20 = V_26 ;
break;
default:
F_7 ( & V_5 -> V_9 , L_5 ) ;
return;
}
F_3 ( & V_5 -> V_9 , L_6 , V_13 ) ;
if ( * V_17 >= V_18 * 2 ) {
* V_17 = 0 ;
} else if ( F_8 ( ( * V_17 % V_18 ) + 3 > V_18 ) ) {
F_7 ( & V_5 -> V_9 , L_7 ) ;
return;
}
F_2 ( V_3 , V_20 , & V_19 ) ;
V_15 -> V_27 [ * V_17 ++ ] = V_19 >> 16 ;
V_15 -> V_27 [ * V_17 ++ ] = V_19 >> 8 ;
V_15 -> V_27 [ * V_17 ++ ] = V_19 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_3 ( & V_5 -> V_9 , L_8 ) ;
if ( V_15 -> V_24 == 0 )
return;
V_15 -> V_28 = ( V_15 -> V_24 - 1 ) / V_25 + 1 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_19 ;
F_3 ( & V_5 -> V_9 , L_9 ) ;
F_2 ( V_3 , V_23 , & V_19 ) ;
F_2 ( V_3 , V_26 , & V_19 ) ;
V_15 -> V_28 = 0 ;
V_15 -> V_21 = 0 ;
V_15 -> V_24 = 0 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 , V_29 ;
F_2 ( V_3 , V_30 , & V_19 ) ;
F_2 ( V_3 , V_11 , & V_29 ) ;
F_12 ( V_3 , V_31 , V_19 & V_29 ) ;
return V_19 ;
}
static T_2 F_13 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_34 ;
V_34 = F_11 ( V_2 ) ;
if ( V_34 & V_35 )
F_1 ( V_2 ) ;
if ( V_34 & V_36 )
F_3 ( & V_5 -> V_9 , L_10 ) ;
if ( V_34 & V_37 )
F_3 ( & V_5 -> V_9 , L_11 ) ;
if ( V_34 & V_38 )
F_3 ( & V_5 -> V_9 , L_12 ) ;
if ( V_34 & V_39 )
F_3 ( & V_5 -> V_9 , L_13 ) ;
if ( V_34 & V_12 )
F_4 ( V_2 ) ;
if ( V_34 & V_40 )
F_3 ( & V_5 -> V_9 , L_14 ) ;
if ( V_34 & V_41 )
F_6 ( V_2 , 'U' ) ;
if ( V_34 & V_42 )
F_3 ( & V_5 -> V_9 , L_15 ) ;
if ( V_34 & V_43 )
F_6 ( V_2 , 'Q' ) ;
if ( V_34 & V_44 )
F_3 ( & V_5 -> V_9 , L_16 ) ;
if ( V_34 & V_45 )
F_9 ( V_2 ) ;
if ( V_34 & V_46 )
F_10 ( V_2 ) ;
if ( V_34 & V_47 )
F_3 ( & V_5 -> V_9 , L_17 ) ;
if ( V_34 & V_48 )
F_3 ( & V_5 -> V_9 , L_18 ) ;
if ( V_34 & V_49 )
F_1 ( V_2 ) ;
if ( V_34 & V_50 )
F_3 ( & V_5 -> V_9 , L_19 ) ;
if ( V_34 & V_51 )
F_3 ( & V_5 -> V_9 , L_20 ) ;
return V_52 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 , V_53 = 1000 ;
F_15 ( V_3 , true ) ;
F_12 ( V_3 , V_54 , V_55 ) ;
do {
F_2 ( V_3 , V_54 , & V_19 ) ;
} while ( ( V_19 & V_55 ) && V_53 -- );
F_15 ( V_3 , false ) ;
F_16 ( V_3 ) ;
F_17 ( V_3 ) ;
if ( V_53 )
return 0 ;
else
return - V_56 ;
}
static void F_18 ( struct V_14 * V_15 ,
T_3 V_57 , T_3 V_58 )
{
V_15 -> V_59 [ 3 ] &= ~ V_57 ;
V_15 -> V_59 [ 3 ] |= V_58 & V_57 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_59 ;
V_59 = ( F_20 ( V_15 -> V_59 [ 0 ] ) << 16 ) |
( F_20 ( V_15 -> V_59 [ 1 ] ) << 8 ) |
F_20 ( V_15 -> V_59 [ 2 ] ) ;
F_12 ( V_3 , V_60 , V_59 ) ;
F_3 ( & V_5 -> V_9 , L_21 , V_59 ) ;
V_59 = F_20 ( V_15 -> V_59 [ 3 ] ) << 16 ;
F_12 ( V_3 , V_61 , V_59 ) ;
F_3 ( & V_5 -> V_9 , L_22 , V_59 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_62 V_63 , int V_10 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_64 = V_2 -> V_65 ;
if ( V_64 >= V_66 || V_63 >= V_67 )
return - V_68 ;
F_5 ( V_3 , V_7 ,
V_69 | V_70 ,
F_22 ( V_64 ) | F_23 ( V_63 ) ) ;
return 0 ;
}
static int F_24 ( struct V_71 * V_72 ,
int V_73 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_25 ( V_75 -> V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_78 = 0 ;
T_1 V_79 , V_57 , V_80 ;
T_3 V_81 , V_82 , V_83 ;
int V_84 ;
switch ( V_73 ) {
case 32000 :
V_80 = V_85 ;
V_78 = V_86 ;
break;
case 44100 :
V_80 = V_87 ;
V_78 = V_88 ;
break;
case 48000 :
V_80 = V_89 ;
V_78 = V_90 ;
break;
case 96000 :
V_80 = V_91 ;
V_78 = V_92 ;
break;
case 192000 :
V_80 = V_93 ;
V_78 = V_94 ;
break;
default:
F_7 ( & V_5 -> V_9 , L_23 , V_73 ) ;
return - V_68 ;
}
V_81 = V_2 -> V_95 [ V_80 ] ;
if ( V_81 >= V_96 ) {
F_7 ( & V_5 -> V_9 , L_24 ) ;
return - V_68 ;
}
V_82 = V_2 -> V_82 [ V_80 ] ;
if ( V_82 == 0 ) {
F_7 ( & V_5 -> V_9 , L_25 ) ;
return - V_68 ;
}
V_83 = V_2 -> V_83 [ V_80 ] ;
if ( V_81 != V_97 )
goto V_98;
V_84 = F_26 ( V_2 -> V_99 [ V_80 ] ,
64 * V_73 * V_82 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_26 ) ;
return V_84 ;
}
V_98:
F_3 ( & V_5 -> V_9 , L_27 ,
( 64 * V_73 * V_82 * V_83 ) ) ;
F_3 ( & V_5 -> V_9 , L_28 ,
F_27 ( V_2 -> V_99 [ V_80 ] ) ) ;
F_18 ( V_15 , V_100 , V_78 ) ;
V_79 = V_101 | F_28 ( V_81 ) |
F_29 ( V_82 ) | F_30 ( V_83 ) ;
V_57 = V_102 | V_103 |
V_104 | V_105 ;
F_5 ( V_3 , V_106 , V_57 , V_79 ) ;
F_3 ( & V_5 -> V_9 , L_29 ,
V_2 -> V_107 [ V_80 ] , V_73 ) ;
return 0 ;
}
static int F_31 ( struct V_71 * V_72 ,
struct V_108 * V_77 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_25 ( V_75 -> V_77 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_109 , V_57 ;
int V_110 ;
int V_84 ;
if ( ! V_77 -> V_111 ) {
V_84 = F_32 ( V_2 -> V_112 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_30 ) ;
return V_84 ;
}
if ( ! F_33 ( V_2 -> V_113 ) ) {
V_84 = F_32 ( V_2 -> V_113 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_31 ) ;
goto V_114;
}
}
V_84 = F_14 ( V_2 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_32 ) ;
goto V_115;
}
F_5 ( V_3 , V_11 , 0xffffff , 0 ) ;
}
if ( V_72 -> V_116 == V_117 ) {
V_109 = V_118 | V_119 |
V_120 | V_121 |
V_122 ;
V_57 = V_123 | V_124 |
V_125 | V_126 |
V_127 ;
for ( V_110 = 0 ; V_110 < V_128 ; V_110 ++ ) {
V_84 = F_32 ( V_2 -> V_99 [ V_110 ] ) ;
if ( V_84 )
goto V_129;
}
} else {
V_109 = V_130 | V_131 ;
V_57 = V_132 | V_133 |
V_134 | V_135 ;
V_84 = F_32 ( V_2 -> V_136 ) ;
if ( V_84 )
goto V_115;
}
F_5 ( V_3 , V_54 , V_57 , V_109 ) ;
F_5 ( V_3 , V_54 , V_137 , 0 ) ;
return 0 ;
V_129:
for ( V_110 -- ; V_110 >= 0 ; V_110 -- )
F_34 ( V_2 -> V_99 [ V_110 ] ) ;
V_115:
if ( ! F_33 ( V_2 -> V_113 ) )
F_34 ( V_2 -> V_113 ) ;
V_114:
F_34 ( V_2 -> V_112 ) ;
return V_84 ;
}
static void F_35 ( struct V_71 * V_72 ,
struct V_108 * V_77 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_25 ( V_75 -> V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_109 , V_57 , V_110 ;
if ( V_72 -> V_116 == V_117 ) {
V_109 = 0 ;
V_57 = V_123 | V_124 |
V_125 | V_126 |
V_127 ;
for ( V_110 = 0 ; V_110 < V_128 ; V_110 ++ )
F_34 ( V_2 -> V_99 [ V_110 ] ) ;
} else {
V_109 = V_138 | V_139 ;
V_57 = V_132 | V_133 |
V_134 | V_135 ;
F_34 ( V_2 -> V_136 ) ;
}
F_5 ( V_3 , V_54 , V_57 , V_109 ) ;
if ( ! V_77 -> V_111 ) {
F_11 ( V_2 ) ;
F_5 ( V_3 , V_54 ,
V_137 , V_137 ) ;
if ( ! F_33 ( V_2 -> V_113 ) )
F_34 ( V_2 -> V_113 ) ;
F_34 ( V_2 -> V_112 ) ;
}
}
static int F_36 ( struct V_71 * V_72 ,
struct V_140 * V_141 ,
struct V_108 * V_142 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_25 ( V_75 -> V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_73 = F_37 ( V_141 ) ;
int V_84 = 0 ;
if ( V_72 -> V_116 == V_117 ) {
V_84 = F_24 ( V_72 , V_73 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_33 ,
V_143 , V_73 ) ;
return V_84 ;
}
F_18 ( V_15 , V_144 ,
V_145 ) ;
F_19 ( V_2 ) ;
} else {
V_84 = F_21 ( V_2 , V_146 , 1 ) ;
}
return V_84 ;
}
static int F_38 ( struct V_71 * V_72 ,
int V_147 , struct V_108 * V_142 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_1 * V_2 = F_25 ( V_75 -> V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
bool V_148 = V_72 -> V_116 == V_117 ;
T_1 V_149 = F_39 ( V_148 ) ;
T_1 V_150 = F_40 ( V_148 ) ;
switch ( V_147 ) {
case V_151 :
case V_152 :
case V_153 :
F_5 ( V_3 , V_11 , V_149 , V_149 ) ;
F_5 ( V_3 , V_54 , V_150 , V_150 ) ;
break;
case V_154 :
case V_155 :
case V_156 :
F_5 ( V_3 , V_54 , V_150 , 0 ) ;
F_5 ( V_3 , V_11 , V_149 , 0 ) ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_41 ( struct V_157 * V_158 ,
struct V_159 * V_160 )
{
V_160 -> type = V_161 ;
V_160 -> V_162 = 1 ;
return 0 ;
}
static int F_42 ( struct V_157 * V_158 ,
struct V_163 * V_164 )
{
struct V_108 * V_77 = F_43 ( V_158 ) ;
struct V_1 * V_2 = F_25 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
V_164 -> V_165 . V_166 . V_167 [ 0 ] = V_15 -> V_59 [ 0 ] ;
V_164 -> V_165 . V_166 . V_167 [ 1 ] = V_15 -> V_59 [ 1 ] ;
V_164 -> V_165 . V_166 . V_167 [ 2 ] = V_15 -> V_59 [ 2 ] ;
V_164 -> V_165 . V_166 . V_167 [ 3 ] = V_15 -> V_59 [ 3 ] ;
return 0 ;
}
static int F_44 ( struct V_157 * V_158 ,
struct V_163 * V_164 )
{
struct V_108 * V_77 = F_43 ( V_158 ) ;
struct V_1 * V_2 = F_25 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
V_15 -> V_59 [ 0 ] = V_164 -> V_165 . V_166 . V_167 [ 0 ] ;
V_15 -> V_59 [ 1 ] = V_164 -> V_165 . V_166 . V_167 [ 1 ] ;
V_15 -> V_59 [ 2 ] = V_164 -> V_165 . V_166 . V_167 [ 2 ] ;
V_15 -> V_59 [ 3 ] = V_164 -> V_165 . V_166 . V_167 [ 3 ] ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_157 * V_158 ,
struct V_163 * V_168 )
{
struct V_108 * V_77 = F_43 ( V_158 ) ;
struct V_1 * V_2 = F_25 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_58 , V_19 ;
F_2 ( V_3 , V_30 , & V_19 ) ;
if ( ! ( V_19 & V_38 ) )
return - V_169 ;
F_2 ( V_3 , V_170 , & V_58 ) ;
V_168 -> V_165 . V_166 . V_167 [ 0 ] = ( V_58 >> 16 ) & 0xFF ;
V_168 -> V_165 . V_166 . V_167 [ 1 ] = ( V_58 >> 8 ) & 0xFF ;
V_168 -> V_165 . V_166 . V_167 [ 2 ] = V_58 & 0xFF ;
F_2 ( V_3 , V_171 , & V_58 ) ;
V_168 -> V_165 . V_166 . V_167 [ 3 ] = ( V_58 >> 16 ) & 0xFF ;
V_168 -> V_165 . V_166 . V_167 [ 4 ] = ( V_58 >> 8 ) & 0xFF ;
V_168 -> V_165 . V_166 . V_167 [ 5 ] = V_58 & 0xFF ;
F_12 ( V_3 , V_31 , V_38 ) ;
return 0 ;
}
static int F_46 ( struct V_157 * V_158 ,
struct V_163 * V_168 )
{
struct V_108 * V_77 = F_43 ( V_158 ) ;
struct V_1 * V_2 = F_25 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
unsigned long V_172 ;
int V_84 = - V_169 ;
F_47 ( & V_15 -> V_173 , V_172 ) ;
if ( V_15 -> V_28 ) {
int V_174 = ( V_15 -> V_28 - 1 ) * V_22 ;
memcpy ( & V_168 -> V_165 . V_166 . V_27 [ 0 ] ,
& V_15 -> V_27 [ V_174 ] , V_22 ) ;
V_84 = 0 ;
}
F_48 ( & V_15 -> V_173 , V_172 ) ;
return V_84 ;
}
static int F_49 ( struct V_157 * V_158 ,
struct V_159 * V_160 )
{
V_160 -> type = V_175 ;
V_160 -> V_162 = V_25 ;
return 0 ;
}
static int F_50 ( struct V_157 * V_158 ,
struct V_163 * V_168 )
{
struct V_108 * V_77 = F_43 ( V_158 ) ;
struct V_1 * V_2 = F_25 ( V_77 ) ;
struct V_14 * V_15 = & V_2 -> V_16 ;
unsigned long V_172 ;
int V_84 = - V_169 ;
F_47 ( & V_15 -> V_173 , V_172 ) ;
if ( V_15 -> V_28 ) {
int V_174 = ( V_15 -> V_28 - 1 ) * V_25 ;
memcpy ( & V_168 -> V_165 . V_176 . V_177 [ 0 ] ,
& V_15 -> V_178 [ V_174 ] , V_25 ) ;
V_84 = 0 ;
}
F_48 ( & V_15 -> V_173 , V_172 ) ;
return V_84 ;
}
static int F_51 ( struct V_157 * V_158 ,
struct V_159 * V_160 )
{
V_160 -> type = V_179 ;
V_160 -> V_162 = 1 ;
V_160 -> V_165 . integer . V_180 = 0 ;
V_160 -> V_165 . integer . V_181 = 1 ;
return 0 ;
}
static int F_52 ( struct V_157 * V_158 ,
struct V_163 * V_168 )
{
struct V_108 * V_77 = F_43 ( V_158 ) ;
struct V_1 * V_2 = F_25 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 ;
F_2 ( V_3 , V_30 , & V_19 ) ;
V_168 -> V_165 . integer . V_165 [ 0 ] = ( V_19 & V_39 ) != 0 ;
F_12 ( V_3 , V_31 , V_39 ) ;
return 0 ;
}
static int F_53 ( struct V_157 * V_158 ,
struct V_159 * V_160 )
{
V_160 -> type = V_182 ;
V_160 -> V_162 = 1 ;
V_160 -> V_165 . integer . V_180 = 16000 ;
V_160 -> V_165 . integer . V_181 = 96000 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
enum V_62 V_63 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_4 V_183 , V_184 = 0 ;
T_1 V_185 , V_186 ;
T_3 V_64 ;
F_2 ( V_3 , V_187 , & V_185 ) ;
F_2 ( V_3 , V_7 , & V_186 ) ;
V_64 = ( V_186 >> V_188 ) & 0xf ;
if ( V_189 [ V_64 ] && ( V_186 & V_8 ) )
V_184 = F_27 ( V_2 -> V_190 ) ;
V_183 = ( T_4 ) V_184 * V_185 ;
F_55 ( V_183 , V_191 [ V_63 ] * 1024 ) ;
F_55 ( V_183 , 128 * 1024 ) ;
F_3 ( & V_5 -> V_9 , L_34 , V_185 ) ;
F_3 ( & V_5 -> V_9 , L_35 , V_184 ) ;
F_3 ( & V_5 -> V_9 , L_36 , V_183 ) ;
return ( int ) V_183 ;
}
static int F_56 ( struct V_157 * V_158 ,
struct V_163 * V_168 )
{
struct V_108 * V_77 = F_43 ( V_158 ) ;
struct V_1 * V_2 = F_25 ( V_77 ) ;
int V_80 = 0 ;
if ( V_2 -> V_10 )
V_80 = F_54 ( V_2 , V_146 ) ;
V_168 -> V_165 . integer . V_165 [ 0 ] = V_80 ;
return 0 ;
}
static int F_57 ( struct V_157 * V_158 ,
struct V_159 * V_160 )
{
V_160 -> type = V_179 ;
V_160 -> V_162 = 1 ;
V_160 -> V_165 . integer . V_180 = 0 ;
V_160 -> V_165 . integer . V_181 = 1 ;
return 0 ;
}
static int F_58 ( struct V_157 * V_158 ,
struct V_163 * V_168 )
{
struct V_108 * V_77 = F_43 ( V_158 ) ;
struct V_1 * V_2 = F_25 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 ;
F_2 ( V_3 , V_192 , & V_19 ) ;
V_168 -> V_165 . integer . V_165 [ 0 ] = ( V_19 & V_193 ) != 0 ;
return 0 ;
}
static int F_59 ( struct V_157 * V_158 ,
struct V_163 * V_168 )
{
struct V_108 * V_77 = F_43 ( V_158 ) ;
struct V_1 * V_2 = F_25 ( V_77 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_19 = V_168 -> V_165 . integer . V_165 [ 0 ] << V_194 ;
F_5 ( V_3 , V_192 , V_193 , V_19 ) ;
return 0 ;
}
static int F_60 ( struct V_108 * V_142 )
{
struct V_1 * V_195 = F_25 ( V_142 ) ;
F_61 ( V_142 , & V_195 -> V_196 ,
& V_195 -> V_197 ) ;
F_62 ( V_142 , V_198 , F_63 ( V_198 ) ) ;
return 0 ;
}
static bool F_64 ( struct V_199 * V_9 , unsigned int V_20 )
{
switch ( V_20 ) {
case V_54 :
case V_192 :
case V_7 :
case V_11 :
case V_30 :
case V_200 :
case V_201 :
case V_170 :
case V_171 :
case V_23 :
case V_26 :
case V_60 :
case V_61 :
case V_187 :
case V_106 :
return true ;
default:
return false ;
}
}
static bool F_65 ( struct V_199 * V_9 , unsigned int V_20 )
{
switch ( V_20 ) {
case V_7 :
case V_30 :
case V_200 :
case V_201 :
case V_170 :
case V_171 :
case V_23 :
case V_26 :
case V_187 :
return true ;
default:
return false ;
}
}
static bool F_66 ( struct V_199 * V_9 , unsigned int V_20 )
{
switch ( V_20 ) {
case V_54 :
case V_192 :
case V_7 :
case V_11 :
case V_31 :
case V_202 :
case V_203 :
case V_60 :
case V_61 :
case V_106 :
return true ;
default:
return false ;
}
}
static T_1 F_67 ( struct V_1 * V_2 ,
struct V_81 * V_81 , T_4 V_204 ,
enum V_205 V_206 , bool V_207 )
{
const T_1 V_80 [] = { 32000 , 44100 , 48000 , 96000 , 192000 } ;
bool V_208 = F_68 ( V_81 , V_2 -> V_190 ) ;
T_4 V_209 , V_210 , V_211 ;
T_1 V_212 , V_213 ;
T_1 V_82 , V_83 , V_214 ;
V_212 = V_208 ? 2 : 1 ;
V_213 = V_208 ? 512 : 1 ;
for ( V_83 = V_212 ; V_83 <= V_213 ; V_83 ++ ) {
for ( V_82 = 1 ; V_82 <= 128 ; V_82 ++ ) {
V_209 = V_80 [ V_206 ] * V_82 * 64 ;
if ( V_207 )
V_210 = F_69 ( V_81 , V_209 ) ;
else
V_210 = F_27 ( V_81 ) ;
V_214 = V_210 / 64 ;
V_214 /= V_82 * V_83 ;
if ( V_214 == V_80 [ V_206 ] ) {
V_204 = 0 ;
V_2 -> V_82 [ V_206 ] = V_82 ;
V_2 -> V_83 [ V_206 ] = V_83 ;
V_2 -> V_107 [ V_206 ] = V_214 ;
goto V_215;
} else if ( V_214 / V_80 [ V_206 ] == 1 ) {
V_211 = ( T_4 ) ( V_214 - V_80 [ V_206 ] ) * 100000 ;
F_55 ( V_211 , V_80 [ V_206 ] ) ;
if ( V_211 >= V_204 )
continue;
V_204 = V_211 ;
V_2 -> V_82 [ V_206 ] = V_82 ;
V_2 -> V_83 [ V_206 ] = V_83 ;
V_2 -> V_107 [ V_206 ] = V_214 ;
} else if ( V_80 [ V_206 ] / V_214 == 1 ) {
V_211 = ( T_4 ) ( V_80 [ V_206 ] - V_214 ) * 100000 ;
F_55 ( V_211 , V_80 [ V_206 ] ) ;
if ( V_211 >= V_204 )
continue;
V_204 = V_211 ;
V_2 -> V_82 [ V_206 ] = V_82 ;
V_2 -> V_83 [ V_206 ] = V_83 ;
V_2 -> V_107 [ V_206 ] = V_214 ;
}
}
}
V_215:
return V_204 ;
}
static int F_70 ( struct V_1 * V_2 ,
enum V_205 V_206 )
{
const T_1 V_80 [] = { 32000 , 44100 , 48000 , 96000 , 192000 } ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_199 * V_9 = & V_5 -> V_9 ;
T_4 V_204 = 100000 , V_84 ;
struct V_81 * V_81 ;
char V_216 [ 16 ] ;
int V_110 ;
for ( V_110 = 0 ; V_110 < V_96 ; V_110 ++ ) {
sprintf ( V_216 , L_37 , V_110 ) ;
V_81 = F_71 ( & V_5 -> V_9 , V_216 ) ;
if ( F_33 ( V_81 ) ) {
F_7 ( V_9 , L_38 , V_110 ) ;
return F_72 ( V_81 ) ;
}
if ( ! F_27 ( V_81 ) )
continue;
V_84 = F_67 ( V_2 , V_81 , V_204 , V_206 ,
V_110 == V_97 ) ;
if ( V_204 == V_84 )
continue;
V_204 = V_84 ;
V_2 -> V_99 [ V_206 ] = V_81 ;
V_2 -> V_95 [ V_206 ] = V_110 ;
if ( V_204 < 100 )
break;
}
F_3 ( & V_5 -> V_9 , L_39 ,
V_2 -> V_95 [ V_206 ] , V_80 [ V_206 ] ) ;
F_3 ( & V_5 -> V_9 , L_40 ,
V_2 -> V_82 [ V_206 ] , V_80 [ V_206 ] ) ;
if ( F_68 ( V_2 -> V_99 [ V_206 ] , V_2 -> V_190 ) )
F_3 ( & V_5 -> V_9 , L_41 ,
V_2 -> V_83 [ V_206 ] , V_80 [ V_206 ] ) ;
F_3 ( & V_5 -> V_9 , L_42 ,
V_80 [ V_206 ] , V_2 -> V_107 [ V_206 ] ) ;
return 0 ;
}
static int F_73 ( struct V_4 * V_5 )
{
struct V_217 * V_218 = V_5 -> V_9 . V_219 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_220 * V_221 ;
void T_5 * V_222 ;
int V_32 , V_84 , V_110 ;
if ( ! V_218 )
return - V_223 ;
V_2 = F_74 ( & V_5 -> V_9 , sizeof( * V_2 ) , V_224 ) ;
if ( ! V_2 )
return - V_225 ;
V_2 -> V_5 = V_5 ;
memcpy ( & V_2 -> V_226 , & V_227 , sizeof( V_227 ) ) ;
V_2 -> V_226 . V_13 = F_75 ( & V_5 -> V_9 ) ;
V_221 = F_76 ( V_5 , V_228 , 0 ) ;
V_222 = F_77 ( & V_5 -> V_9 , V_221 ) ;
if ( F_33 ( V_222 ) )
return F_72 ( V_222 ) ;
V_2 -> V_3 = F_78 ( & V_5 -> V_9 ,
L_43 , V_222 , & V_229 ) ;
if ( F_33 ( V_2 -> V_3 ) ) {
F_7 ( & V_5 -> V_9 , L_44 ) ;
return F_72 ( V_2 -> V_3 ) ;
}
V_32 = F_79 ( V_5 , 0 ) ;
if ( V_32 < 0 ) {
F_7 ( & V_5 -> V_9 , L_45 , V_5 -> V_13 ) ;
return V_32 ;
}
V_84 = F_80 ( & V_5 -> V_9 , V_32 , F_13 , 0 ,
F_75 ( & V_5 -> V_9 ) , V_2 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_46 , V_32 ) ;
return V_84 ;
}
V_2 -> V_190 = F_71 ( & V_5 -> V_9 , L_47 ) ;
if ( F_33 ( V_2 -> V_190 ) ) {
F_7 ( & V_5 -> V_9 , L_48 ) ;
return F_72 ( V_2 -> V_190 ) ;
}
V_2 -> V_112 = F_71 ( & V_5 -> V_9 , L_43 ) ;
if ( F_33 ( V_2 -> V_112 ) ) {
F_7 ( & V_5 -> V_9 , L_49 ) ;
return F_72 ( V_2 -> V_112 ) ;
}
V_2 -> V_113 = F_71 ( & V_5 -> V_9 , L_50 ) ;
if ( F_33 ( V_2 -> V_113 ) )
F_81 ( & V_5 -> V_9 , L_51 ) ;
V_2 -> V_136 = F_71 ( & V_5 -> V_9 , L_52 ) ;
if ( F_33 ( V_2 -> V_136 ) ) {
F_7 ( & V_5 -> V_9 , L_53 ) ;
return F_72 ( V_2 -> V_136 ) ;
}
V_2 -> V_65 = V_230 ;
for ( V_110 = 0 ; V_110 < V_128 ; V_110 ++ ) {
V_84 = F_70 ( V_2 , V_110 ) ;
if ( V_84 )
return V_84 ;
}
V_15 = & V_2 -> V_16 ;
F_82 ( & V_15 -> V_173 ) ;
V_15 -> V_59 [ 0 ] = V_231 |
V_232 ;
V_15 -> V_59 [ 1 ] = V_233 ;
V_15 -> V_59 [ 2 ] = 0x00 ;
V_15 -> V_59 [ 3 ] = V_88 |
V_145 ;
V_2 -> V_10 = false ;
V_2 -> V_196 . V_234 = V_235 ;
V_2 -> V_197 . V_234 = V_236 ;
V_2 -> V_196 . V_237 = V_221 -> V_238 + V_202 ;
V_2 -> V_197 . V_237 = V_221 -> V_238 + V_200 ;
F_83 ( & V_5 -> V_9 , V_2 ) ;
V_84 = F_84 ( & V_5 -> V_9 , & V_239 ,
& V_2 -> V_226 , 1 ) ;
if ( V_84 ) {
F_7 ( & V_5 -> V_9 , L_54 , V_84 ) ;
return V_84 ;
}
V_84 = F_85 ( V_5 , V_240 ) ;
if ( V_84 )
F_7 ( & V_5 -> V_9 , L_55 , V_84 ) ;
return V_84 ;
}
static int F_86 ( struct V_199 * V_9 )
{
struct V_1 * V_2 = F_87 ( V_9 ) ;
F_2 ( V_2 -> V_3 , V_7 ,
& V_2 -> V_241 ) ;
F_88 ( V_2 -> V_3 , true ) ;
F_16 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_89 ( struct V_199 * V_9 )
{
struct V_1 * V_2 = F_87 ( V_9 ) ;
F_88 ( V_2 -> V_3 , false ) ;
F_5 ( V_2 -> V_3 , V_7 ,
V_69 | V_70 ,
V_2 -> V_241 ) ;
return F_17 ( V_2 -> V_3 ) ;
}
