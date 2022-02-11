static const struct V_1 * F_1 (
struct V_2 * V_3 ,
int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_3 -> V_6 [ V_5 ] . V_4 > 0 ; V_5 ++ ) {
if ( V_3 -> V_6 [ V_5 ] . V_4 == V_4 )
return & V_3 -> V_6 [ V_5 ] ;
}
return NULL ;
}
static void F_2 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_2 * V_3 = V_8 -> V_10 ;
void T_1 * V_11 = V_8 -> V_12 . V_13 ;
if ( V_3 -> V_14 == V_15 ||
V_3 -> V_14 == V_16 ||
V_3 -> V_14 == V_17 ) {
F_3 ( V_3 -> V_18 [ V_9 ] [ 0 ] , V_11 + V_19 ) ;
F_3 ( V_3 -> V_18 [ V_9 ] [ 1 ] , V_11 + V_20 ) ;
} else
F_3 ( V_3 -> V_18 [ V_9 ] [ 0 ] , V_11 + V_21 ) ;
}
static void F_4 ( struct V_7 * V_8 , unsigned int V_9 )
{
F_5 ( V_8 , V_9 ) ;
F_2 ( V_8 , V_9 ) ;
}
static void F_6 ( struct V_7 * V_8 ,
struct V_22 * V_23 )
{
struct V_2 * V_3 = V_8 -> V_10 ;
const struct V_1 * V_24 ;
F_7 ( V_3 -> V_25 , L_1 ,
V_23 -> V_26 ,
V_23 -> V_27 ,
F_8 ( F_9 ( V_23 -> V_27 ) ) ,
V_23 -> V_28 ,
F_8 ( F_9 ( V_23 -> V_28 ) ) ) ;
V_3 -> V_18 [ V_23 -> V_26 ] [ 0 ] = V_3 -> V_18 [ V_23 -> V_26 ] [ 1 ] = 0 ;
V_24 = F_1 ( V_3 , V_23 -> V_27 ) ;
if ( V_24 == NULL ) {
F_10 ( V_3 -> V_25 , L_2 ,
V_23 -> V_27 ) ;
V_24 = F_1 ( V_3 , V_29 ) ;
}
F_11 ( V_24 == NULL ) ;
V_3 -> V_18 [ V_23 -> V_26 ] [ 0 ] |= V_24 -> V_30 ;
V_24 = F_1 ( V_3 , V_23 -> V_28 ) ;
if ( V_24 == NULL || ( V_24 -> V_30 == 0 && V_24 -> V_31 == 0 ) ) {
F_7 ( V_3 -> V_25 , L_3 ) ;
V_24 = F_1 ( V_3 , V_32 ) ;
}
F_11 ( V_24 == NULL ) ;
V_3 -> V_18 [ V_23 -> V_26 ] [ 0 ] |= V_24 -> V_30 ;
V_3 -> V_18 [ V_23 -> V_26 ] [ 1 ] |= V_24 -> V_31 ;
F_7 ( V_3 -> V_25 , L_4 ,
V_3 -> V_18 [ V_23 -> V_26 ] [ 0 ] ,
V_3 -> V_18 [ V_23 -> V_26 ] [ 1 ] ) ;
F_2 ( V_8 , V_23 -> V_26 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
unsigned int V_33 , V_34 = 0 ;
switch( V_3 -> V_14 ) {
case V_15 :
V_33 = 0x0a820c97 ;
V_34 = 0x00033031 ;
break;
case V_16 :
case V_17 :
V_33 = 0x08618a92 ;
V_34 = 0x00002921 ;
break;
case V_35 :
V_33 = 0x0008438c ;
break;
case V_36 :
V_33 = 0x00084526 ;
break;
case V_37 :
case V_38 :
default:
V_33 = 0x00074526 ;
break;
}
V_3 -> V_18 [ 0 ] [ 0 ] = V_3 -> V_18 [ 1 ] [ 0 ] = V_33 ;
V_3 -> V_18 [ 0 ] [ 1 ] = V_3 -> V_18 [ 1 ] [ 1 ] = V_34 ;
}
static int F_13 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_10 ;
if ( V_3 -> V_14 == V_35 ||
V_3 -> V_14 == V_16 ||
V_3 -> V_14 == V_17 ||
V_3 -> V_14 == V_15 ) {
const char * V_39 = F_14 ( V_3 -> V_40 , L_5 ,
NULL ) ;
struct V_41 * V_42 = F_15 ( L_6 ) ;
const char * V_43 = F_14 ( V_42 , L_7 , NULL ) ;
if ( V_39 && ! strncmp ( V_39 , L_8 , 3 ) ) {
if ( ! strncmp ( V_43 , L_9 , 9 ) )
return V_44 ;
else
return V_45 ;
}
}
if ( F_16 ( V_3 -> V_40 , L_10 ) ||
F_16 ( V_3 -> V_40 , L_11 ) )
return V_45 ;
return V_46 ;
}
static void F_17 ( struct V_47 * V_48 )
{
unsigned int V_49 = ( V_48 -> V_50 . V_51 & V_52 ) ;
struct V_7 * V_8 = V_48 -> V_8 ;
struct V_2 * V_3 = V_8 -> V_10 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned int V_57 , V_58 ;
F_18 ( V_3 -> V_25 , L_12 ,
V_59 , V_48 , V_48 -> V_51 , V_49 , V_48 -> V_25 -> V_26 ) ;
if ( ! ( V_48 -> V_51 & V_60 ) )
return;
V_56 = (struct V_55 * ) V_3 -> V_61 ;
V_58 = 0 ;
F_19 (qc->sg, sg, qc->n_elem, si) {
T_2 V_62 , V_63 , V_64 ;
V_62 = ( T_2 ) F_20 ( V_54 ) ;
V_63 = F_21 ( V_54 ) ;
while ( V_63 ) {
F_11 ( V_58 ++ >= V_65 ) ;
V_64 = ( V_63 < V_66 ) ? V_63 : V_66 ;
F_22 ( & V_56 -> V_67 , V_49 ? V_68 : V_69 ) ;
F_22 ( & V_56 -> V_70 , V_64 ) ;
F_23 ( & V_56 -> V_71 , V_62 ) ;
V_56 -> V_72 = 0 ;
V_56 -> V_73 = 0 ;
V_56 -> V_74 = 0 ;
V_62 += V_64 ;
V_63 -= V_64 ;
++ V_56 ;
}
}
F_11 ( ! V_58 ) ;
V_56 -- ;
F_22 ( & V_56 -> V_67 , V_49 ? V_75 : V_76 ) ;
V_56 ++ ;
memset ( V_56 , 0 , sizeof( struct V_55 ) ) ;
F_22 ( & V_56 -> V_67 , V_77 ) ;
F_18 ( V_3 -> V_25 , L_13 , V_59 , V_58 ) ;
}
static void F_24 ( struct V_7 * V_8 )
{
struct V_78 T_1 * V_79 = V_8 -> V_12 . V_80 ;
if ( V_79 ) {
unsigned int V_81 = 1000000 ;
F_3 ( ( V_82 | V_83 | V_84 | V_85 | V_86 ) << 16 , & V_79 -> V_87 ) ;
while ( -- V_81 && ( F_25 ( & V_79 -> V_88 ) & V_82 ) )
F_26 ( 1 ) ;
}
F_27 ( V_8 ) ;
}
static void F_28 ( struct V_47 * V_48 )
{
struct V_7 * V_8 = V_48 -> V_8 ;
struct V_2 * V_3 = V_8 -> V_10 ;
struct V_78 T_1 * V_79 = V_8 -> V_12 . V_80 ;
int V_25 = V_48 -> V_25 -> V_26 ;
F_18 ( V_3 -> V_25 , L_14 , V_59 , V_48 ) ;
F_3 ( V_3 -> V_89 , & V_79 -> V_90 ) ;
if ( V_3 -> V_14 == V_35 &&
( V_3 -> V_18 [ V_25 ] [ 0 ] & V_91 ) ) {
void T_1 * V_11 = V_8 -> V_12 . V_13 ;
T_2 V_92 = V_3 -> V_18 [ V_25 ] [ 0 ] ;
if ( ! ( V_48 -> V_50 . V_51 & V_52 ) )
V_92 += 0x00800000 ;
F_3 ( V_92 , V_11 + V_21 ) ;
}
V_8 -> V_93 -> V_94 ( V_8 , & V_48 -> V_50 ) ;
}
static void F_29 ( struct V_47 * V_48 )
{
struct V_7 * V_8 = V_48 -> V_8 ;
struct V_2 * V_3 = V_8 -> V_10 ;
struct V_78 T_1 * V_79 = V_8 -> V_12 . V_80 ;
F_18 ( V_3 -> V_25 , L_14 , V_59 , V_48 ) ;
F_3 ( ( V_82 << 16 ) | V_82 , & V_79 -> V_87 ) ;
( void ) F_25 ( & V_79 -> V_87 ) ;
}
static void F_30 ( struct V_47 * V_48 )
{
struct V_7 * V_8 = V_48 -> V_8 ;
struct V_2 * V_3 = V_8 -> V_10 ;
struct V_78 T_1 * V_79 = V_8 -> V_12 . V_80 ;
unsigned int V_81 = 1000000 ;
F_18 ( V_3 -> V_25 , L_14 , V_59 , V_48 ) ;
F_3 ( ( ( V_82 | V_85 | V_86 ) << 16 ) , & V_79 -> V_87 ) ;
while ( -- V_81 && ( F_25 ( & V_79 -> V_88 ) & V_82 ) )
F_26 ( 1 ) ;
}
static T_3 F_31 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_10 ;
struct V_78 T_1 * V_79 = V_8 -> V_12 . V_80 ;
T_2 V_95 , V_96 = V_97 ;
unsigned long V_81 = 0 ;
V_95 = F_25 ( & V_79 -> V_88 ) ;
F_18 ( V_3 -> V_25 , L_15 , V_59 , V_95 ) ;
if ( ( V_95 & ( V_82 | V_86 ) ) != V_82 )
V_96 |= V_98 ;
if ( ( V_95 & V_99 ) == 0 )
return V_96 ;
F_18 ( V_3 -> V_25 , L_16 , V_59 ) ;
F_26 ( 1 ) ;
F_3 ( ( V_84 << 16 ) | V_84 , & V_79 -> V_87 ) ;
for (; ; ) {
F_26 ( 1 ) ;
V_95 = F_25 ( & V_79 -> V_88 ) ;
if ( ( V_95 & V_84 ) == 0 )
break;
if ( ++ V_81 > 1000 ) {
F_10 ( V_3 -> V_25 , L_17 ) ;
V_96 |= V_98 ;
break;
}
}
return V_96 ;
}
static int F_32 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_10 ;
if ( V_8 -> V_12 . V_80 == NULL )
return 0 ;
V_3 -> V_61 =
F_33 ( V_3 -> V_25 ,
( V_65 + 2 ) * sizeof( struct V_55 ) ,
& V_3 -> V_89 , V_100 ) ;
if ( V_3 -> V_61 == NULL ) {
F_34 ( V_3 -> V_25 , L_18 ) ;
V_8 -> V_12 . V_80 = NULL ;
V_8 -> V_101 = 0 ;
V_8 -> V_102 = 0 ;
}
return 0 ;
}
static void F_35 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_10 ;
F_18 ( V_3 -> V_25 , L_19 , V_59 ) ;
}
static void F_36 ( struct V_2 * V_3 , int V_103 )
{
F_7 ( V_3 -> V_25 , L_20 ) ;
if ( V_3 -> V_104 )
return;
if ( V_3 -> V_14 == V_38 && ! V_103 ) {
V_105 . V_106 ( V_107 , V_3 -> V_40 , 0 , 1 ) ;
} else {
int V_108 ;
V_108 = V_105 . V_106 ( V_109 ,
V_3 -> V_40 , V_3 -> V_110 , 1 ) ;
V_105 . V_106 ( V_107 ,
V_3 -> V_40 , V_3 -> V_110 , 1 ) ;
F_37 ( 10 ) ;
if ( V_108 == 0 ) {
V_105 . V_106 ( V_109 ,
V_3 -> V_40 , V_3 -> V_110 , 0 ) ;
F_37 ( V_111 ) ;
}
}
if ( V_3 -> V_112 && V_103 ) {
int V_108 ;
F_38 ( V_3 -> V_112 ) ;
V_108 = F_39 ( V_3 -> V_112 ) ;
if ( V_108 )
F_40 ( V_113 , & V_3 -> V_112 -> V_25 ,
L_21 , V_108 ) ;
else
F_41 ( V_3 -> V_112 ) ;
}
if ( V_3 -> V_114 )
F_3 ( V_115 |
V_116 |
V_117 , V_3 -> V_114 ) ;
}
static int F_42 ( struct V_118 * V_119 )
{
struct V_7 * V_8 = F_43 ( V_119 -> V_120 ) ;
struct V_2 * V_3 = V_8 -> V_10 ;
struct V_22 * V_25 ;
T_4 V_121 ;
int V_108 ;
V_108 = F_44 ( V_119 ) ;
if ( V_108 )
return V_108 ;
V_25 = & V_8 -> V_122 . V_9 [ V_119 -> V_123 ] ;
if ( V_3 -> V_14 == V_38 ) {
F_45 ( V_119 -> V_124 , 31 ) ;
F_46 ( V_119 -> V_124 , 31 ) ;
F_47 ( V_25 , V_125 , L_22 ) ;
return 0 ;
}
if ( V_25 -> V_126 != V_127 )
return 0 ;
if ( V_3 -> V_14 == V_15 || V_3 -> V_14 == V_17 ) {
F_45 ( V_119 -> V_124 , 15 ) ;
F_46 ( V_119 -> V_124 , 15 ) ;
F_11 ( ! V_3 -> V_112 ) ;
F_48 ( V_3 -> V_112 , V_128 , 0x08 ) ;
F_49 ( V_3 -> V_112 , V_129 , & V_121 ) ;
F_50 ( V_3 -> V_112 , V_129 ,
V_121 | V_130 ) ;
F_47 ( V_25 , V_125 ,
L_23 ) ;
}
return 0 ;
}
static int F_51 ( struct V_2 * V_3 , T_5 V_131 )
{
int V_108 ;
V_108 = F_52 ( V_3 -> V_120 , V_131 ) ;
if ( V_108 )
return V_108 ;
F_12 ( V_3 ) ;
F_53 ( V_3 -> V_132 ) ;
if ( V_3 -> V_104 )
return 0 ;
if ( V_3 -> V_114 ) {
T_2 V_133 = F_25 ( V_3 -> V_114 ) ;
V_133 &= ~ ( V_116 | V_117 ) ;
F_3 ( V_133 , V_3 -> V_114 ) ;
}
if ( V_3 -> V_112 ) {
F_54 ( V_3 -> V_112 ) ;
F_55 ( V_3 -> V_112 ) ;
}
V_105 . V_106 ( V_107 , V_3 -> V_40 ,
V_3 -> V_110 , 0 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 )
{
F_36 ( V_3 , 1 ) ;
F_2 ( V_3 -> V_120 -> V_134 [ 0 ] , 0 ) ;
F_57 ( V_3 -> V_132 ) ;
F_58 ( V_3 -> V_120 ) ;
return 0 ;
}
static void T_6 F_59 ( struct V_2 * V_3 )
{
const int * V_135 ;
if ( F_16 ( V_3 -> V_40 , L_11 ) ) {
V_3 -> V_14 = V_15 ;
V_3 -> V_6 = V_136 ;
} else if ( F_16 ( V_3 -> V_40 , L_24 ) ) {
V_3 -> V_14 = V_16 ;
V_3 -> V_6 = V_137 ;
} else if ( F_16 ( V_3 -> V_40 , L_10 ) ) {
V_3 -> V_14 = V_17 ;
V_3 -> V_6 = V_137 ;
} else if ( F_16 ( V_3 -> V_40 , L_25 ) ) {
if ( strcmp ( V_3 -> V_40 -> V_138 , L_26 ) == 0 ) {
V_3 -> V_14 = V_35 ;
V_3 -> V_6 = V_139 ;
} else {
V_3 -> V_14 = V_36 ;
V_3 -> V_6 = V_140 ;
}
} else if ( F_16 ( V_3 -> V_40 , L_27 ) ) {
V_3 -> V_14 = V_37 ;
V_3 -> V_6 = V_141 ;
} else {
V_3 -> V_14 = V_38 ;
V_3 -> V_6 = V_142 ;
}
V_135 = F_14 ( V_3 -> V_40 , L_28 , NULL ) ;
V_3 -> V_110 = V_135 ? * V_135 : 0 ;
if ( V_3 -> V_104 && V_135 == 0 )
V_3 -> V_110 = 1 ;
}
static void T_6 F_60 ( struct V_143 * V_12 ,
void T_1 * V_144 ,
void T_1 * V_145 )
{
V_12 -> V_13 = V_144 ;
V_12 -> V_146 = V_144 + ( V_147 << 4 ) ;
V_12 -> V_148 = V_144 + ( V_149 << 4 ) ;
V_12 -> V_150 = V_144 + ( V_151 << 4 ) ;
V_12 -> V_152 = V_144 + ( V_153 << 4 ) ;
V_12 -> V_154 = V_144 + ( V_155 << 4 ) ;
V_12 -> V_156 = V_144 + ( V_157 << 4 ) ;
V_12 -> V_158 = V_144 + ( V_159 << 4 ) ;
V_12 -> V_160 = V_144 + ( V_161 << 4 ) ;
V_12 -> V_162 = V_144 + ( V_163 << 4 ) ;
V_12 -> V_164 = V_144 + ( V_165 << 4 ) ;
V_12 -> V_166 = V_144 + 0x160 ;
V_12 -> V_167 = V_144 + 0x160 ;
V_12 -> V_80 = V_145 ;
}
static void T_6 F_61 ( struct V_2 * V_3 ,
struct V_168 * V_169 )
{
int V_5 = 0 ;
V_169 -> V_170 = 0 ;
V_169 -> V_101 = 0 ;
V_169 -> V_102 = 0 ;
while ( V_3 -> V_6 [ V_5 ] . V_4 > 0 ) {
unsigned int V_171 = 1U << ( V_3 -> V_6 [ V_5 ] . V_4 & 0x0f ) ;
switch( V_3 -> V_6 [ V_5 ] . V_4 & 0xf0 ) {
case 0x00 :
V_169 -> V_170 |= ( V_171 >> 8 ) ;
break;
case 0x20 :
V_169 -> V_101 |= V_171 ;
break;
case 0x40 :
V_169 -> V_102 |= V_171 ;
break;
}
V_5 ++ ;
}
F_7 ( V_3 -> V_25 , L_29 ,
V_169 -> V_170 , V_169 -> V_101 , V_169 -> V_102 ) ;
}
static int T_6 F_62 ( struct V_2 * V_3 ,
T_7 V_172 ,
T_7 V_173 ,
T_7 V_174 ,
unsigned long V_132 )
{
struct V_168 V_169 ;
const struct V_168 * V_175 [] = { & V_169 , NULL } ;
void T_1 * V_79 = NULL ;
F_59 ( V_3 ) ;
F_12 ( V_3 ) ;
F_63 ( V_3 -> V_25 , V_66 ) ;
memset ( & V_169 , 0 , sizeof( struct V_168 ) ) ;
F_61 ( V_3 , & V_169 ) ;
V_169 . V_51 = V_176 ;
V_169 . V_177 = & V_178 ;
V_169 . V_10 = V_3 ;
V_3 -> V_120 = F_64 ( V_3 -> V_25 , V_175 , 1 ) ;
if ( V_3 -> V_120 == NULL ) {
F_34 ( V_3 -> V_25 , L_30 ) ;
return - V_179 ;
}
V_3 -> V_120 -> V_10 = V_3 ;
V_3 -> V_172 = F_65 ( V_3 -> V_25 , V_172 , 0x100 ) ;
if ( V_3 -> V_172 == NULL ) {
F_34 ( V_3 -> V_25 , L_31 ) ;
return - V_179 ;
}
V_3 -> V_120 -> V_180 = & V_3 -> V_172 ;
if ( V_173 != 0 ) {
V_79 = F_65 ( V_3 -> V_25 , V_173 ,
sizeof( struct V_78 ) ) ;
if ( V_79 == NULL )
F_10 ( V_3 -> V_25 , L_32 ) ;
}
if ( V_174 != 0 ) {
V_3 -> V_114 = F_65 ( V_3 -> V_25 , V_174 , 4 ) ;
if ( V_3 -> V_114 == NULL ) {
F_34 ( V_3 -> V_25 , L_33 ) ;
return - V_179 ;
}
}
F_60 ( & V_3 -> V_120 -> V_134 [ 0 ] -> V_12 ,
V_3 -> V_172 , V_79 ) ;
V_3 -> V_120 -> V_134 [ 0 ] -> V_10 = V_3 ;
F_36 ( V_3 , 0 ) ;
F_2 ( V_3 -> V_120 -> V_134 [ 0 ] , 0 ) ;
if ( V_3 -> V_112 && V_79 )
F_41 ( V_3 -> V_112 ) ;
F_66 ( V_3 -> V_25 , L_34 ,
V_181 [ V_3 -> V_14 ] , V_3 -> V_110 ) ;
V_3 -> V_132 = V_132 ;
return F_67 ( V_3 -> V_120 , V_132 , V_182 , 0 ,
& V_183 ) ;
}
static int T_6 F_68 ( struct V_184 * V_185 ,
const struct V_186 * V_187 )
{
struct V_2 * V_3 ;
T_7 V_172 , V_173 = 0 ;
unsigned long V_132 ;
int V_108 ;
if ( F_69 ( V_185 ) == 0 ) {
F_34 ( & V_185 -> V_188 . V_25 ,
L_35 ) ;
return - V_189 ;
}
F_70 ( V_185 ) ;
V_3 = F_71 ( & V_185 -> V_188 . V_25 ,
sizeof( struct V_2 ) , V_100 ) ;
if ( V_3 == NULL ) {
F_34 ( & V_185 -> V_188 . V_25 ,
L_36 ) ;
return - V_179 ;
}
V_3 -> V_40 = F_72 ( V_185 -> V_188 . V_25 . V_190 ) ;
V_3 -> V_185 = V_185 ;
V_3 -> V_25 = & V_185 -> V_188 . V_25 ;
if ( F_73 ( V_185 , 0 , L_37 ) ) {
F_34 ( & V_185 -> V_188 . V_25 ,
L_38 ) ;
return - V_191 ;
}
V_172 = F_74 ( V_185 , 0 ) ;
if ( F_69 ( V_185 ) >= 2 ) {
if ( F_73 ( V_185 , 1 , L_39 ) )
F_34 ( & V_185 -> V_188 . V_25 ,
L_40 ) ;
else
V_173 = F_74 ( V_185 , 1 ) ;
}
if ( F_75 ( V_185 ) == 0 ) {
F_10 ( & V_185 -> V_188 . V_25 ,
L_41 ) ;
V_132 = F_76 ( NULL , 13 ) ;
} else
V_132 = F_77 ( V_185 , 0 ) ;
F_78 ( V_3 -> V_185 -> V_192 ) ;
V_108 = F_62 ( V_3 ,
V_172 ,
V_173 ,
0 ,
V_132 ) ;
F_79 ( V_3 -> V_185 -> V_192 ) ;
return V_108 ;
}
static int T_8 F_80 ( struct V_184 * V_185 )
{
struct V_193 * V_120 = F_81 ( V_185 ) ;
struct V_2 * V_3 = V_120 -> V_10 ;
F_78 ( V_3 -> V_185 -> V_192 ) ;
V_3 -> V_120 -> V_10 = NULL ;
F_82 ( V_120 ) ;
F_79 ( V_3 -> V_185 -> V_192 ) ;
return 0 ;
}
static int F_83 ( struct V_184 * V_185 , T_5 V_131 )
{
struct V_193 * V_120 = F_81 ( V_185 ) ;
return F_51 ( V_120 -> V_10 , V_131 ) ;
}
static int F_84 ( struct V_184 * V_185 )
{
struct V_193 * V_120 = F_81 ( V_185 ) ;
return F_56 ( V_120 -> V_10 ) ;
}
static void F_85 ( struct V_184 * V_185 , int V_194 )
{
struct V_193 * V_120 = F_81 ( V_185 ) ;
struct V_7 * V_8 ;
struct V_195 * V_196 ;
struct V_22 * V_25 ;
unsigned long V_51 ;
if ( ! V_120 || ! V_120 -> V_10 )
return;
V_8 = V_120 -> V_134 [ 0 ] ;
F_86 ( V_8 -> V_197 , V_51 ) ;
V_196 = & V_8 -> V_122 . V_198 ;
if ( V_194 == V_199 ) {
F_87 ( V_196 , L_42 ) ;
F_88 ( V_196 ) ;
F_89 ( V_8 ) ;
} else {
F_87 ( V_196 , L_43 ) ;
F_90 (dev, &ap->link, ALL)
V_25 -> V_51 |= V_200 ;
F_91 ( V_8 ) ;
}
F_92 ( V_8 -> V_197 , V_51 ) ;
}
static int T_6 F_93 ( struct V_201 * V_112 ,
const struct V_202 * V_123 )
{
struct V_2 * V_3 ;
struct V_41 * V_203 ;
T_7 V_11 ;
V_203 = F_94 ( V_112 ) ;
if ( V_203 == NULL ) {
F_34 ( & V_112 -> V_25 ,
L_44 ) ;
return - V_204 ;
}
if ( F_39 ( V_112 ) ) {
F_34 ( & V_112 -> V_25 ,
L_45 ) ;
return - V_189 ;
}
V_3 = F_71 ( & V_112 -> V_25 ,
sizeof( struct V_2 ) , V_100 ) ;
if ( V_3 == NULL ) {
F_34 ( & V_112 -> V_25 ,
L_36 ) ;
return - V_179 ;
}
V_3 -> V_40 = F_72 ( V_203 ) ;
V_3 -> V_112 = V_112 ;
V_3 -> V_25 = & V_112 -> V_25 ;
if ( F_95 ( V_112 , L_37 ) ) {
F_34 ( & V_112 -> V_25 ,
L_46 ) ;
return - V_191 ;
}
V_11 = F_96 ( V_112 , 0 ) ;
if ( F_62 ( V_3 ,
V_11 + 0x2000 ,
V_11 + 0x1000 ,
V_11 ,
V_112 -> V_132 ) )
return - V_189 ;
return 0 ;
}
static void T_8 F_97 ( struct V_201 * V_112 )
{
struct V_193 * V_120 = F_98 ( & V_112 -> V_25 ) ;
F_82 ( V_120 ) ;
}
static int F_99 ( struct V_201 * V_112 , T_5 V_131 )
{
struct V_193 * V_120 = F_98 ( & V_112 -> V_25 ) ;
return F_51 ( V_120 -> V_10 , V_131 ) ;
}
static int F_100 ( struct V_201 * V_112 )
{
struct V_193 * V_120 = F_98 ( & V_112 -> V_25 ) ;
return F_56 ( V_120 -> V_10 ) ;
}
static int T_9 F_101 ( void )
{
int V_108 ;
if ( ! F_102 ( V_205 ) )
return - V_204 ;
V_108 = F_103 ( & V_206 ) ;
if ( V_108 )
return V_108 ;
V_108 = F_104 ( & V_207 ) ;
if ( V_108 ) {
F_105 ( & V_206 ) ;
return V_108 ;
}
return 0 ;
}
static void T_10 F_106 ( void )
{
F_107 ( & V_207 ) ;
F_105 ( & V_206 ) ;
}
