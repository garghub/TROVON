static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
F_2 ( V_2 , & V_6 -> V_7 , 0 , 0 ) ;
F_3 ( & V_6 -> V_7 ) ;
V_6 -> V_7 . V_8 = V_9 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 V_10 ,
unsigned int V_11 , unsigned int V_12 ,
enum V_13 V_14 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
int V_17 = 0 ;
V_6 -> V_18 = 0 ;
if ( ( V_11 < 48 ) || ( V_12 < 32 ) )
return - V_19 ;
V_6 -> V_7 . V_20 = ( V_11 * V_12 * 2 ) ;
if ( ( V_6 -> V_7 . V_21 != 0 ) && ( V_6 -> V_7 . V_22 < V_6 -> V_7 . V_20 ) )
return - V_19 ;
if ( V_6 -> V_7 . V_11 != V_11 || V_6 -> V_7 . V_12 != V_12 ||
V_6 -> V_7 . V_14 != V_14 || V_4 -> V_10 != V_10 ||
V_6 -> V_23 != V_16 -> V_24 ) {
V_6 -> V_7 . V_11 = V_11 ;
V_6 -> V_7 . V_12 = V_12 ;
V_6 -> V_7 . V_14 = V_14 ;
V_6 -> V_23 = V_16 -> V_24 ;
V_4 -> V_10 = V_10 ;
if ( V_4 -> V_10 == V_25 )
V_4 -> V_26 = V_12 * 720 * 3 / 2 ;
else
V_4 -> V_26 = V_12 * 720 * 2 ;
F_1 ( V_2 , V_4 , V_6 ) ;
}
if ( ( V_6 -> V_7 . V_21 != 0 ) && ( V_6 -> V_7 . V_22 < V_6 -> V_7 . V_20 ) )
return - V_19 ;
if ( V_6 -> V_7 . V_14 == 0 )
V_6 -> V_7 . V_14 = V_27 ;
if ( V_9 == V_6 -> V_7 . V_8 ) {
V_6 -> V_7 . V_11 = V_11 ;
V_6 -> V_7 . V_12 = V_12 ;
V_6 -> V_7 . V_14 = V_14 ;
V_6 -> V_23 = V_16 -> V_24 ;
V_4 -> V_10 = V_10 ;
if ( V_4 -> V_10 == V_25 )
V_4 -> V_26 = V_12 * 720 * 3 / 2 ;
else
V_4 -> V_26 = V_12 * 720 * 2 ;
V_17 = F_5 ( V_2 , & V_6 -> V_7 , NULL ) ;
if ( V_17 != 0 )
goto V_28;
}
V_6 -> V_7 . V_8 = V_29 ;
return 0 ;
V_28:
F_1 ( V_2 , V_4 , V_6 ) ;
return V_17 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int * V_30 , unsigned int * V_20 )
{
struct V_3 * V_4 = V_2 -> V_31 ;
struct V_15 * V_16 = V_4 -> V_16 ;
* V_20 = 2 * V_16 -> V_32 . V_11 * V_16 -> V_32 . V_12 ;
if ( * V_30 == 0 )
* V_30 = V_33 ;
while ( * V_20 * * V_30 > V_33 * V_34 )
( * V_30 ) -- ;
V_2 -> V_14 = V_27 ;
V_2 -> V_35 = V_27 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_36 * V_7 ,
enum V_13 V_14 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_3 * V_4 = V_2 -> V_31 ;
struct V_15 * V_16 = V_4 -> V_16 ;
return F_4 ( V_2 , V_4 , V_6 , V_4 -> V_10 ,
V_16 -> V_32 . V_11 , V_16 -> V_32 . V_12 , V_14 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_36 * V_7 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_3 * V_4 = V_2 -> V_31 ;
F_1 ( V_2 , V_4 , V_6 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_36 * V_7 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_3 * V_4 = V_2 -> V_31 ;
V_6 -> V_7 . V_8 = V_37 ;
F_11 ( & V_6 -> V_7 . V_38 , & V_4 -> V_39 ) ;
}
static void F_12 ( struct V_15 * V_16 , int type )
{
struct V_3 * V_4 = & V_16 -> V_40 [ type ] ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_41 = NULL ;
V_4 -> V_16 = V_16 ;
V_4 -> type = type ;
V_4 -> V_42 = V_43 [ type ] . V_42 ;
V_4 -> V_44 = V_45 ;
V_4 -> V_46 = V_43 [ type ] . V_46 ;
V_4 -> V_47 = V_43 [ type ] . V_48 ;
V_4 -> V_49 = V_16 -> V_50 [ type ] ;
V_4 -> V_51 = V_16 -> V_52 [ type ] ;
F_13 ( & V_4 -> V_53 ) ;
V_4 -> V_54 = 1 ;
V_4 -> V_55 = V_4 -> V_51 * V_4 -> V_54 ;
F_14 ( & V_4 -> V_56 ) ;
V_4 -> V_57 = - 1 ;
F_15 ( & V_4 -> V_58 . V_59 ) ;
F_16 ( & V_4 -> V_58 ) ;
F_15 ( & V_4 -> V_60 . V_59 ) ;
F_16 ( & V_4 -> V_60 ) ;
F_15 ( & V_4 -> V_61 . V_59 ) ;
F_16 ( & V_4 -> V_61 ) ;
F_15 ( & V_4 -> V_62 . V_59 ) ;
F_16 ( & V_4 -> V_62 ) ;
F_17 ( & V_4 -> V_63 , V_64 ) ;
F_13 ( & V_4 -> V_39 ) ;
V_4 -> V_65 . V_66 = V_67 ;
V_4 -> V_65 . V_68 = ( unsigned long ) V_4 ;
F_18 ( & V_4 -> V_65 ) ;
F_15 ( & V_4 -> V_69 ) ;
if ( type == V_70 ) {
F_15 ( & V_4 -> V_71 ) ;
V_4 -> V_72 = V_73 ;
F_19 ( & V_4 -> V_74 , & V_75 ,
& V_16 -> V_76 -> V_77 , & V_4 -> V_71 ,
V_73 ,
V_27 ,
sizeof( struct V_5 ) ,
V_4 , & V_16 -> V_78 ) ;
V_4 -> V_10 = V_25 ;
V_4 -> V_26 = V_16 -> V_32 . V_12 * 720 * 3 / 2 ;
V_4 -> V_79 = 720 ;
}
}
static int F_20 ( struct V_15 * V_16 , int type )
{
struct V_3 * V_4 = & V_16 -> V_40 [ type ] ;
T_1 V_80 = V_16 -> V_81 ;
int V_82 = V_43 [ type ] . V_82 ;
int V_83 = V_16 -> V_84 + V_85 + V_82 ;
V_4 -> V_86 . V_87 = NULL ;
V_4 -> V_41 = NULL ;
V_4 -> V_16 = V_16 ;
V_4 -> type = type ;
V_4 -> V_42 = V_43 [ type ] . V_42 ;
if ( type == V_88 && ! ( V_80 & V_89 ) )
return 0 ;
if ( type == V_90 &&
! ( V_80 & ( V_91 | V_92 ) ) )
return 0 ;
if ( V_43 [ type ] . V_46 != V_93 &&
V_16 -> V_50 [ type ] == 0 ) {
F_21 ( L_1 , V_43 [ type ] . V_42 ) ;
return 0 ;
}
F_12 ( V_16 , type ) ;
if ( type == V_94 ) {
if ( V_16 -> V_95 -> V_96 & V_97 ) {
V_4 -> V_41 = F_22 ( sizeof( struct V_98 ) , V_99 ) ;
if ( V_4 -> V_41 == NULL ) {
F_23 ( L_2 ,
V_4 -> V_42 ) ;
return - V_100 ;
}
} else {
V_4 -> V_49 = 0 ;
}
}
if ( V_82 == - 1 )
return 0 ;
snprintf ( V_4 -> V_86 . V_42 , sizeof( V_4 -> V_86 . V_42 ) , L_3 ,
V_16 -> V_87 . V_42 , V_4 -> V_42 ) ;
V_4 -> V_86 . V_83 = V_83 ;
V_4 -> V_86 . V_87 = & V_16 -> V_87 ;
V_4 -> V_86 . V_101 = & V_102 ;
V_4 -> V_86 . V_103 = V_104 ;
if ( V_16 -> V_95 -> V_105 -> V_106 == V_107 )
V_4 -> V_86 . V_108 = V_16 -> V_109 ;
else
V_4 -> V_86 . V_108 = V_110 ;
V_4 -> V_86 . V_59 = & V_16 -> V_78 ;
F_24 ( & V_4 -> V_86 ) ;
return 0 ;
}
int F_25 ( struct V_15 * V_16 )
{
int type , V_111 ;
for ( type = 0 ; type < V_112 ; type ++ ) {
V_111 = F_20 ( V_16 , type ) ;
if ( V_111 < 0 )
break;
V_111 = F_26 ( & V_16 -> V_40 [ type ] ) ;
if ( V_111 < 0 )
break;
}
if ( type == V_112 )
return 0 ;
F_27 ( V_16 , 0 ) ;
return V_111 ;
}
static int F_28 ( struct V_15 * V_16 , int type )
{
struct V_3 * V_4 = & V_16 -> V_40 [ type ] ;
int V_113 = V_43 [ type ] . V_113 ;
const char * V_42 ;
int V_83 , V_111 ;
if ( type == V_94 && V_4 -> V_41 != NULL ) {
V_111 = F_29 ( V_4 ) ;
if ( V_111 < 0 ) {
F_23 ( L_4 ) ;
return V_111 ;
}
}
if ( V_4 -> V_86 . V_87 == NULL )
return 0 ;
V_83 = V_4 -> V_86 . V_83 ;
if ( type != V_114 ) {
struct V_3 * V_115 = & V_16 -> V_40 [ V_114 ] ;
if ( V_115 -> V_86 . V_87 )
V_83 = V_115 -> V_86 . V_83
+ V_43 [ type ] . V_82 ;
}
F_30 ( & V_4 -> V_86 , V_4 ) ;
V_111 = F_31 ( & V_4 -> V_86 , V_113 , V_83 ) ;
if ( V_111 < 0 ) {
F_23 ( L_5 ,
V_4 -> V_42 , V_83 ) ;
V_4 -> V_86 . V_87 = NULL ;
return V_111 ;
}
V_42 = F_32 ( & V_4 -> V_86 ) ;
switch ( V_113 ) {
case V_116 :
F_21 ( L_6 ,
V_42 , V_4 -> V_42 , V_16 -> V_50 [ type ] ,
V_16 -> V_52 [ type ] / 1024 ,
( V_16 -> V_52 [ type ] * 100 / 1024 ) % 100 ) ;
break;
case V_117 :
F_21 ( L_7 , V_42 , V_4 -> V_42 ) ;
break;
case V_118 :
if ( V_16 -> V_50 [ type ] )
F_21 ( L_8 ,
V_42 , V_4 -> V_42 , V_16 -> V_50 [ type ] ,
V_16 -> V_52 [ type ] ) ;
else
F_21 ( L_7 ,
V_42 , V_4 -> V_42 ) ;
break;
}
return 0 ;
}
int F_33 ( struct V_15 * V_16 )
{
int type ;
int V_119 ;
int V_111 = 0 ;
for ( type = 0 ; type < V_112 ; type ++ ) {
V_119 = F_28 ( V_16 , type ) ;
if ( V_119 && V_111 == 0 )
V_111 = V_119 ;
}
if ( V_111 == 0 )
return 0 ;
F_27 ( V_16 , 1 ) ;
return V_111 ;
}
void F_27 ( struct V_15 * V_16 , int V_120 )
{
struct V_121 * V_122 ;
int type ;
for ( type = 0 ; type < V_112 ; type ++ ) {
if ( type == V_94 ) {
if ( V_16 -> V_40 [ type ] . V_41 != NULL ) {
if ( V_120 )
F_34 ( & V_16 -> V_40 [ type ] ) ;
F_35 ( V_16 -> V_40 [ type ] . V_41 ) ;
V_16 -> V_40 [ type ] . V_41 = NULL ;
F_36 ( & V_16 -> V_40 [ type ] ) ;
}
continue;
}
if ( type == V_123 ) {
if ( V_16 -> V_50 [ type ] != 0 ) {
V_16 -> V_50 [ type ] = 0 ;
if ( V_16 -> V_40 [ type ] . V_49 != 0 )
F_36 ( & V_16 -> V_40 [ type ] ) ;
}
continue;
}
V_122 = & V_16 -> V_40 [ type ] . V_86 ;
if ( V_122 -> V_87 == NULL )
continue;
if ( type == V_70 )
F_37 ( & V_16 -> V_40 [ type ] . V_74 ) ;
F_36 ( & V_16 -> V_40 [ type ] ) ;
F_38 ( V_122 ) ;
}
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
int V_124 = F_40 ( V_16 ) ;
T_1 V_68 [ V_125 ] ;
int V_126 ;
if ( V_16 -> V_127 ) {
V_16 -> V_128 . V_30 = 12 ;
V_16 -> V_128 . V_129 [ 0 ] = 10 ;
V_16 -> V_128 . V_129 [ 1 ] = 273 ;
} else {
V_16 -> V_128 . V_30 = 18 ;
V_16 -> V_128 . V_129 [ 0 ] = 6 ;
V_16 -> V_128 . V_129 [ 1 ] = 318 ;
}
if ( V_124 )
F_41 ( V_16 -> V_130 , V_128 , V_131 , & V_16 -> V_128 . V_132 . V_133 . V_128 ) ;
else
F_41 ( V_16 -> V_130 , V_128 , V_134 , & V_16 -> V_128 . V_132 . V_133 . V_135 ) ;
if ( V_124 ) {
V_126 = V_16 -> V_128 . V_30 * 2 ;
} else {
V_126 = V_16 -> V_127 ? ( 21 - 4 + 1 ) * 2 : ( 23 - 2 + 1 ) * 2 ;
}
V_68 [ 0 ] = V_4 -> V_44 ;
V_68 [ 1 ] = ( V_126 / 2 ) | ( ( V_126 / 2 ) << 16 ) ;
V_68 [ 2 ] = ( V_124 ? V_136
: ( V_16 -> V_127 ? V_137
: V_138 ) ) ;
V_68 [ 3 ] = 1 ;
if ( V_124 ) {
V_68 [ 4 ] = 0x20602060 ;
V_68 [ 5 ] = 0x307090d0 ;
} else {
V_68 [ 4 ] = 0xB0F0B0F0 ;
V_68 [ 5 ] = 0xA0E0A0E0 ;
}
F_42 ( L_9 ,
V_68 [ 0 ] , V_68 [ 1 ] , V_68 [ 2 ] , V_68 [ 3 ] , V_68 [ 4 ] , V_68 [ 5 ] ) ;
F_43 ( V_16 , V_139 , 6 , V_68 ) ;
}
void F_44 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = & V_16 -> V_40 [ V_123 ] ;
struct V_140 * V_141 ;
if ( ! F_45 ( V_4 ) )
return;
if ( ( F_46 ( & V_4 -> V_58 . V_142 ) + F_46 ( & V_4 -> V_60 . V_142 ) ) >=
V_143 )
return;
if ( F_46 ( & V_4 -> V_61 . V_142 ) < 2 )
return;
V_141 = F_47 ( V_4 , & V_4 -> V_61 ) ;
if ( V_141 != NULL )
F_48 ( V_4 , V_141 , & V_4 -> V_58 ) ;
}
static
struct V_144 * F_49 ( struct V_3 * V_4 ,
struct V_140 * V_141 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_144 * V_2 ;
if ( V_4 -> V_44 == V_45 ||
F_50 ( V_145 , & V_4 -> V_146 ) ||
! F_50 ( V_147 , & V_4 -> V_146 ) )
return F_48 ( V_4 , V_141 , & V_4 -> V_58 ) ;
V_2 = F_48 ( V_4 , V_141 , & V_4 -> V_60 ) ;
if ( V_2 != & V_4 -> V_60 )
return V_2 ;
F_51 ( V_4 , V_141 ) ;
F_52 ( V_16 , V_148 , 5 , V_4 -> V_44 ,
( void V_149 * ) & V_16 -> V_150 -> V_151 [ V_141 -> V_57 ] - V_16 -> V_152 ,
V_4 -> V_54 , V_141 -> V_57 , V_4 -> V_55 ) ;
return V_2 ;
}
static
void F_53 ( struct V_3 * V_4 )
{
struct V_144 * V_2 ;
struct V_140 * V_141 ;
if ( F_46 ( & V_4 -> V_58 . V_142 ) == 0 ||
F_46 ( & V_4 -> V_60 . V_142 ) >= V_153 )
return;
do {
V_141 = F_47 ( V_4 , & V_4 -> V_58 ) ;
if ( V_141 == NULL )
break;
V_2 = F_49 ( V_4 , V_141 ) ;
} while ( F_46 ( & V_4 -> V_60 . V_142 ) < V_153
&& V_2 == & V_4 -> V_60 );
}
void V_64 ( struct V_154 * V_155 )
{
struct V_3 * V_4 =
F_8 ( V_155 , struct V_3 , V_63 ) ;
F_53 ( V_4 ) ;
}
static void F_54 ( struct V_3 * V_4 )
{
F_55 ( V_4 ) ;
switch ( V_4 -> type ) {
case V_70 :
if ( V_4 -> V_10 == V_25 )
V_4 -> V_55 = 720 * V_4 -> V_16 -> V_32 . V_12 * 3 / 2 ;
else
V_4 -> V_55 = 720 * V_4 -> V_16 -> V_32 . V_12 * 2 ;
V_4 -> V_54 = V_4 -> V_55 / V_4 -> V_51 ;
if ( V_4 -> V_55 % V_4 -> V_51 )
V_4 -> V_54 ++ ;
break;
case V_90 :
V_4 -> V_54 = 1 ;
if ( F_40 ( V_4 -> V_16 ) ) {
V_4 -> V_55 = ( V_4 -> V_16 -> V_127 ? 12 : 18 )
* 2 * V_136 ;
} else {
V_4 -> V_55 = V_4 -> V_16 -> V_127
? ( 21 - 4 + 1 ) * 2 * V_137
: ( 23 - 2 + 1 ) * 2 * V_138 ;
}
break;
default:
V_4 -> V_54 = 1 ;
V_4 -> V_55 = V_4 -> V_51 * V_4 -> V_54 ;
break;
}
F_56 ( V_4 ) ;
}
int F_57 ( struct V_3 * V_4 )
{
T_1 V_68 [ V_156 ] ;
struct V_15 * V_16 = V_4 -> V_16 ;
int V_157 = 0 ;
struct V_3 * V_158 ;
if ( ! F_45 ( V_4 ) )
return - V_19 ;
F_42 ( L_10 , V_4 -> V_42 ) ;
switch ( V_4 -> type ) {
case V_114 :
V_157 = V_159 ;
V_16 -> V_160 = V_16 -> V_161 = 0 ;
V_16 -> V_162 = V_163 ;
V_16 -> V_164 = F_58 ( V_16 -> V_32 . V_165 ) ;
V_16 -> V_166 = 0 ;
break;
case V_123 :
V_157 = V_167 ;
break;
case V_94 :
V_157 = V_168 ;
break;
case V_70 :
V_157 = V_169 ;
break;
case V_170 :
V_157 = V_171 ;
break;
case V_90 :
#ifdef F_59
V_157 = F_40 ( V_16 ) ?
V_172 : V_173 ;
#else
V_157 = V_172 ;
#endif
V_16 -> V_128 . V_174 = 0 ;
V_16 -> V_128 . V_175 = 0 ;
memset ( V_16 -> V_128 . V_176 ,
0 , sizeof( V_16 -> V_128 . V_176 ) ) ;
break;
default:
return - V_19 ;
}
F_60 ( V_177 , & V_4 -> V_146 ) ;
F_61 ( V_16 , V_68 , V_178 , 1 , V_179 ) ;
V_4 -> V_44 = V_68 [ 0 ] ;
F_52 ( V_16 , V_180 , 2 , V_4 -> V_44 , V_157 ) ;
if ( V_157 != V_168 ) {
F_52 ( V_16 , V_181 , 2 , V_4 -> V_44 , 0 ) ;
F_52 ( V_16 , V_182 , 3 , V_4 -> V_44 , 3 , 1 ) ;
F_52 ( V_16 , V_182 , 3 , V_4 -> V_44 , 8 , 0 ) ;
F_52 ( V_16 , V_182 , 3 , V_4 -> V_44 , 4 , 1 ) ;
if ( F_46 ( & V_16 -> V_183 ) == 0 )
F_52 ( V_16 , V_182 , 2 ,
V_4 -> V_44 , 12 ) ;
F_52 ( V_16 , V_184 , 3 ,
V_4 -> V_44 , 312 , 313 ) ;
if ( V_16 -> V_81 & V_91 )
F_39 ( V_4 ) ;
V_158 = & V_16 -> V_40 [ V_123 ] ;
F_61 ( V_16 , V_68 , V_185 , 2 ,
V_4 -> V_44 , F_45 ( V_158 ) ? 7 : 0 ) ;
V_16 -> V_32 . V_186 = V_4 ;
F_62 ( & V_16 -> V_32 ) ;
if ( ! V_16 -> V_32 . V_187 &&
F_50 ( V_188 , & V_16 -> V_189 ) )
F_52 ( V_16 , V_190 , 2 , V_4 -> V_44 ,
( F_58 ( V_16 -> V_32 . V_191 ) << 8 ) | 1 ) ;
if ( V_157 == V_169 ) {
if ( V_4 -> V_10 == V_192 )
F_52 ( V_16 , V_193 , 2 ,
V_4 -> V_44 , 1 ) ;
else
F_52 ( V_16 , V_193 , 2 ,
V_4 -> V_44 , 0 ) ;
}
}
if ( F_46 ( & V_16 -> V_194 ) == 0 ) {
F_63 ( & V_16 -> V_32 , 1 ) ;
F_60 ( V_195 , & V_16 -> V_189 ) ;
F_64 ( V_16 , 7 , V_196 ) ;
}
F_52 ( V_16 , V_197 , 3 , V_4 -> V_44 ,
( void V_149 * ) & V_16 -> V_150 -> V_198 [ V_4 -> type ] [ 0 ] - V_16 -> V_152 ,
( void V_149 * ) & V_16 -> V_150 -> V_198 [ V_4 -> type ] [ 1 ] - V_16 -> V_152 ) ;
F_54 ( V_4 ) ;
F_53 ( V_4 ) ;
if ( F_52 ( V_16 , V_199 , 1 , V_4 -> V_44 ) ) {
F_65 ( L_11 ) ;
F_66 ( V_145 , & V_4 -> V_146 ) ;
if ( V_4 -> type == V_114 )
F_52 ( V_16 , V_200 , 2 , V_4 -> V_44 , 1 ) ;
else
F_52 ( V_16 , V_200 , 1 , V_4 -> V_44 ) ;
F_60 ( V_147 , & V_4 -> V_146 ) ;
F_52 ( V_16 , V_201 , 1 , V_4 -> V_44 ) ;
F_52 ( V_16 , V_202 , 1 , V_4 -> V_44 ) ;
V_4 -> V_44 = V_45 ;
F_60 ( V_145 , & V_4 -> V_146 ) ;
if ( F_46 ( & V_16 -> V_194 ) == 0 ) {
F_66 ( V_195 , & V_16 -> V_189 ) ;
F_64 ( V_16 , 5 , V_196 ) ;
}
return - V_19 ;
}
if ( V_157 != V_168 )
F_67 ( & V_16 -> V_183 ) ;
F_67 ( & V_16 -> V_194 ) ;
return 0 ;
}
void F_68 ( struct V_15 * V_16 )
{
int V_203 ;
for ( V_203 = V_112 - 1 ; V_203 >= 0 ; V_203 -- ) {
struct V_3 * V_4 = & V_16 -> V_40 [ V_203 ] ;
if ( ! F_45 ( V_4 ) )
continue;
if ( F_50 ( V_147 , & V_4 -> V_146 ) )
F_69 ( V_4 , 0 ) ;
}
}
int F_69 ( struct V_3 * V_4 , int V_204 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( ! F_45 ( V_4 ) )
return - V_19 ;
F_42 ( L_12 ) ;
if ( F_46 ( & V_16 -> V_194 ) == 0 )
return 0 ;
F_66 ( V_145 , & V_4 -> V_146 ) ;
if ( V_4 -> type == V_114 )
F_52 ( V_16 , V_200 , 2 , V_4 -> V_44 , ! V_204 ) ;
else
F_52 ( V_16 , V_200 , 1 , V_4 -> V_44 ) ;
if ( V_4 -> type == V_114 && V_204 ) {
F_21 ( L_13 ) ;
}
if ( V_4 -> type != V_94 )
F_70 ( & V_16 -> V_183 ) ;
F_70 ( & V_16 -> V_194 ) ;
F_60 ( V_147 , & V_4 -> V_146 ) ;
F_52 ( V_16 , V_201 , 1 , V_4 -> V_44 ) ;
F_52 ( V_16 , V_202 , 1 , V_4 -> V_44 ) ;
V_4 -> V_44 = V_45 ;
F_60 ( V_145 , & V_4 -> V_146 ) ;
if ( F_46 ( & V_16 -> V_194 ) > 0 )
return 0 ;
F_63 ( & V_16 -> V_32 , 0 ) ;
F_64 ( V_16 , 5 , V_196 ) ;
F_71 ( & V_4 -> V_56 ) ;
return 0 ;
}
T_1 F_72 ( struct V_15 * V_16 )
{
int V_203 ;
for ( V_203 = 0 ; V_203 < V_112 ; V_203 ++ ) {
struct V_3 * V_4 = & V_16 -> V_40 [ V_203 ] ;
if ( V_4 -> V_86 . V_87 && ( V_4 -> V_44 != V_45 ) )
return V_4 -> V_44 ;
}
return V_45 ;
}
struct V_3 * F_73 ( struct V_15 * V_16 , T_1 V_44 )
{
int V_203 ;
struct V_3 * V_4 ;
if ( V_44 == V_45 )
return NULL ;
for ( V_203 = 0 ; V_203 < V_112 ; V_203 ++ ) {
V_4 = & V_16 -> V_40 [ V_203 ] ;
if ( V_4 -> V_44 != V_44 )
continue;
if ( F_45 ( V_4 ) )
return V_4 ;
}
return NULL ;
}
