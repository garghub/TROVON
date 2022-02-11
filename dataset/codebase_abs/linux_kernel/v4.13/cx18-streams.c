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
F_18 ( & V_4 -> V_65 , V_66 , ( unsigned long ) V_4 ) ;
F_15 ( & V_4 -> V_67 ) ;
if ( type == V_68 ) {
F_15 ( & V_4 -> V_69 ) ;
V_4 -> V_70 = V_71 ;
F_19 ( & V_4 -> V_72 , & V_73 ,
& V_16 -> V_74 -> V_75 , & V_4 -> V_69 ,
V_71 ,
V_27 ,
sizeof( struct V_5 ) ,
V_4 , & V_16 -> V_76 ) ;
V_4 -> V_10 = V_25 ;
V_4 -> V_26 = V_16 -> V_32 . V_12 * 720 * 3 / 2 ;
V_4 -> V_77 = 720 ;
}
}
static int F_20 ( struct V_15 * V_16 , int type )
{
struct V_3 * V_4 = & V_16 -> V_40 [ type ] ;
T_1 V_78 = V_16 -> V_79 ;
int V_80 = V_43 [ type ] . V_80 ;
int V_81 = V_16 -> V_82 + V_83 + V_80 ;
V_4 -> V_84 . V_85 = NULL ;
V_4 -> V_41 = NULL ;
V_4 -> V_16 = V_16 ;
V_4 -> type = type ;
V_4 -> V_42 = V_43 [ type ] . V_42 ;
if ( type == V_86 && ! ( V_78 & V_87 ) )
return 0 ;
if ( type == V_88 &&
! ( V_78 & ( V_89 | V_90 ) ) )
return 0 ;
if ( V_43 [ type ] . V_46 != V_91 &&
V_16 -> V_50 [ type ] == 0 ) {
F_21 ( L_1 , V_43 [ type ] . V_42 ) ;
return 0 ;
}
F_12 ( V_16 , type ) ;
if ( type == V_92 ) {
if ( V_16 -> V_93 -> V_94 & V_95 ) {
V_4 -> V_41 = F_22 ( sizeof( struct V_96 ) , V_97 ) ;
if ( V_4 -> V_41 == NULL ) {
F_23 ( L_2 ,
V_4 -> V_42 ) ;
return - V_98 ;
}
} else {
V_4 -> V_49 = 0 ;
}
}
if ( V_80 == - 1 )
return 0 ;
snprintf ( V_4 -> V_84 . V_42 , sizeof( V_4 -> V_84 . V_42 ) , L_3 ,
V_16 -> V_85 . V_42 , V_4 -> V_42 ) ;
V_4 -> V_84 . V_81 = V_81 ;
V_4 -> V_84 . V_85 = & V_16 -> V_85 ;
V_4 -> V_84 . V_99 = & V_100 ;
V_4 -> V_84 . V_101 = V_102 ;
if ( V_16 -> V_93 -> V_103 -> V_104 == V_105 )
V_4 -> V_84 . V_106 = V_16 -> V_107 ;
else
V_4 -> V_84 . V_106 = V_108 ;
V_4 -> V_84 . V_59 = & V_16 -> V_76 ;
F_24 ( & V_4 -> V_84 ) ;
return 0 ;
}
int F_25 ( struct V_15 * V_16 )
{
int type , V_109 ;
for ( type = 0 ; type < V_110 ; type ++ ) {
V_109 = F_20 ( V_16 , type ) ;
if ( V_109 < 0 )
break;
V_109 = F_26 ( & V_16 -> V_40 [ type ] ) ;
if ( V_109 < 0 )
break;
}
if ( type == V_110 )
return 0 ;
F_27 ( V_16 , 0 ) ;
return V_109 ;
}
static int F_28 ( struct V_15 * V_16 , int type )
{
struct V_3 * V_4 = & V_16 -> V_40 [ type ] ;
int V_111 = V_43 [ type ] . V_111 ;
const char * V_42 ;
int V_81 , V_109 ;
if ( type == V_92 && V_4 -> V_41 != NULL ) {
V_109 = F_29 ( V_4 ) ;
if ( V_109 < 0 ) {
F_23 ( L_4 ) ;
return V_109 ;
}
}
if ( V_4 -> V_84 . V_85 == NULL )
return 0 ;
V_81 = V_4 -> V_84 . V_81 ;
if ( type != V_112 ) {
struct V_3 * V_113 = & V_16 -> V_40 [ V_112 ] ;
if ( V_113 -> V_84 . V_85 )
V_81 = V_113 -> V_84 . V_81
+ V_43 [ type ] . V_80 ;
}
F_30 ( & V_4 -> V_84 , V_4 ) ;
V_109 = F_31 ( & V_4 -> V_84 , V_111 , V_81 ) ;
if ( V_109 < 0 ) {
F_23 ( L_5 ,
V_4 -> V_42 , V_81 ) ;
V_4 -> V_84 . V_85 = NULL ;
return V_109 ;
}
V_42 = F_32 ( & V_4 -> V_84 ) ;
switch ( V_111 ) {
case V_114 :
F_21 ( L_6 ,
V_42 , V_4 -> V_42 , V_16 -> V_50 [ type ] ,
V_16 -> V_52 [ type ] / 1024 ,
( V_16 -> V_52 [ type ] * 100 / 1024 ) % 100 ) ;
break;
case V_115 :
F_21 ( L_7 , V_42 , V_4 -> V_42 ) ;
break;
case V_116 :
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
int V_117 ;
int V_109 = 0 ;
for ( type = 0 ; type < V_110 ; type ++ ) {
V_117 = F_28 ( V_16 , type ) ;
if ( V_117 && V_109 == 0 )
V_109 = V_117 ;
}
if ( V_109 == 0 )
return 0 ;
F_27 ( V_16 , 1 ) ;
return V_109 ;
}
void F_27 ( struct V_15 * V_16 , int V_118 )
{
struct V_119 * V_120 ;
int type ;
for ( type = 0 ; type < V_110 ; type ++ ) {
if ( type == V_92 ) {
if ( V_16 -> V_40 [ type ] . V_41 != NULL ) {
if ( V_118 )
F_34 ( & V_16 -> V_40 [ type ] ) ;
F_35 ( V_16 -> V_40 [ type ] . V_41 ) ;
V_16 -> V_40 [ type ] . V_41 = NULL ;
F_36 ( & V_16 -> V_40 [ type ] ) ;
}
continue;
}
if ( type == V_121 ) {
if ( V_16 -> V_50 [ type ] != 0 ) {
V_16 -> V_50 [ type ] = 0 ;
if ( V_16 -> V_40 [ type ] . V_49 != 0 )
F_36 ( & V_16 -> V_40 [ type ] ) ;
}
continue;
}
V_120 = & V_16 -> V_40 [ type ] . V_84 ;
if ( V_120 -> V_85 == NULL )
continue;
if ( type == V_68 )
F_37 ( & V_16 -> V_40 [ type ] . V_72 ) ;
F_36 ( & V_16 -> V_40 [ type ] ) ;
F_38 ( V_120 ) ;
}
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
int V_122 = F_40 ( V_16 ) ;
T_1 V_123 [ V_124 ] ;
int V_125 ;
if ( V_16 -> V_126 ) {
V_16 -> V_127 . V_30 = 12 ;
V_16 -> V_127 . V_128 [ 0 ] = 10 ;
V_16 -> V_127 . V_128 [ 1 ] = 273 ;
} else {
V_16 -> V_127 . V_30 = 18 ;
V_16 -> V_127 . V_128 [ 0 ] = 6 ;
V_16 -> V_127 . V_128 [ 1 ] = 318 ;
}
if ( V_122 )
F_41 ( V_16 -> V_129 , V_127 , V_130 , & V_16 -> V_127 . V_131 . V_132 . V_127 ) ;
else
F_41 ( V_16 -> V_129 , V_127 , V_133 , & V_16 -> V_127 . V_131 . V_132 . V_134 ) ;
if ( V_122 ) {
V_125 = V_16 -> V_127 . V_30 * 2 ;
} else {
V_125 = V_16 -> V_126 ? ( 21 - 4 + 1 ) * 2 : ( 23 - 2 + 1 ) * 2 ;
}
V_123 [ 0 ] = V_4 -> V_44 ;
V_123 [ 1 ] = ( V_125 / 2 ) | ( ( V_125 / 2 ) << 16 ) ;
V_123 [ 2 ] = ( V_122 ? V_135
: ( V_16 -> V_126 ? V_136
: V_137 ) ) ;
V_123 [ 3 ] = 1 ;
if ( V_122 ) {
V_123 [ 4 ] = 0x20602060 ;
V_123 [ 5 ] = 0x307090d0 ;
} else {
V_123 [ 4 ] = 0xB0F0B0F0 ;
V_123 [ 5 ] = 0xA0E0A0E0 ;
}
F_42 ( L_9 ,
V_123 [ 0 ] , V_123 [ 1 ] , V_123 [ 2 ] , V_123 [ 3 ] , V_123 [ 4 ] , V_123 [ 5 ] ) ;
F_43 ( V_16 , V_138 , 6 , V_123 ) ;
}
void F_44 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = & V_16 -> V_40 [ V_121 ] ;
struct V_139 * V_140 ;
if ( ! F_45 ( V_4 ) )
return;
if ( ( F_46 ( & V_4 -> V_58 . V_141 ) + F_46 ( & V_4 -> V_60 . V_141 ) ) >=
V_142 )
return;
if ( F_46 ( & V_4 -> V_61 . V_141 ) < 2 )
return;
V_140 = F_47 ( V_4 , & V_4 -> V_61 ) ;
if ( V_140 != NULL )
F_48 ( V_4 , V_140 , & V_4 -> V_58 ) ;
}
static
struct V_143 * F_49 ( struct V_3 * V_4 ,
struct V_139 * V_140 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_143 * V_2 ;
if ( V_4 -> V_44 == V_45 ||
F_50 ( V_144 , & V_4 -> V_145 ) ||
! F_50 ( V_146 , & V_4 -> V_145 ) )
return F_48 ( V_4 , V_140 , & V_4 -> V_58 ) ;
V_2 = F_48 ( V_4 , V_140 , & V_4 -> V_60 ) ;
if ( V_2 != & V_4 -> V_60 )
return V_2 ;
F_51 ( V_4 , V_140 ) ;
F_52 ( V_16 , V_147 , 5 , V_4 -> V_44 ,
( void V_148 * ) & V_16 -> V_149 -> V_150 [ V_140 -> V_57 ] - V_16 -> V_151 ,
V_4 -> V_54 , V_140 -> V_57 , V_4 -> V_55 ) ;
return V_2 ;
}
static
void F_53 ( struct V_3 * V_4 )
{
struct V_143 * V_2 ;
struct V_139 * V_140 ;
if ( F_46 ( & V_4 -> V_58 . V_141 ) == 0 ||
F_46 ( & V_4 -> V_60 . V_141 ) >= V_152 )
return;
do {
V_140 = F_47 ( V_4 , & V_4 -> V_58 ) ;
if ( V_140 == NULL )
break;
V_2 = F_49 ( V_4 , V_140 ) ;
} while ( F_46 ( & V_4 -> V_60 . V_141 ) < V_152
&& V_2 == & V_4 -> V_60 );
}
void V_64 ( struct V_153 * V_154 )
{
struct V_3 * V_4 =
F_8 ( V_154 , struct V_3 , V_63 ) ;
F_53 ( V_4 ) ;
}
static void F_54 ( struct V_3 * V_4 )
{
F_55 ( V_4 ) ;
switch ( V_4 -> type ) {
case V_68 :
if ( V_4 -> V_10 == V_25 )
V_4 -> V_55 = 720 * V_4 -> V_16 -> V_32 . V_12 * 3 / 2 ;
else
V_4 -> V_55 = 720 * V_4 -> V_16 -> V_32 . V_12 * 2 ;
V_4 -> V_54 = V_4 -> V_55 / V_4 -> V_51 ;
if ( V_4 -> V_55 % V_4 -> V_51 )
V_4 -> V_54 ++ ;
break;
case V_88 :
V_4 -> V_54 = 1 ;
if ( F_40 ( V_4 -> V_16 ) ) {
V_4 -> V_55 = ( V_4 -> V_16 -> V_126 ? 12 : 18 )
* 2 * V_135 ;
} else {
V_4 -> V_55 = V_4 -> V_16 -> V_126
? ( 21 - 4 + 1 ) * 2 * V_136
: ( 23 - 2 + 1 ) * 2 * V_137 ;
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
T_1 V_123 [ V_155 ] ;
struct V_15 * V_16 = V_4 -> V_16 ;
int V_156 = 0 ;
struct V_3 * V_157 ;
if ( ! F_45 ( V_4 ) )
return - V_19 ;
F_42 ( L_10 , V_4 -> V_42 ) ;
switch ( V_4 -> type ) {
case V_112 :
V_156 = V_158 ;
V_16 -> V_159 = V_16 -> V_160 = 0 ;
V_16 -> V_161 = V_162 ;
V_16 -> V_163 = F_58 ( V_16 -> V_32 . V_164 ) ;
V_16 -> V_165 = 0 ;
break;
case V_121 :
V_156 = V_166 ;
break;
case V_92 :
V_156 = V_167 ;
break;
case V_68 :
V_156 = V_168 ;
break;
case V_169 :
V_156 = V_170 ;
break;
case V_88 :
#ifdef F_59
V_156 = F_40 ( V_16 ) ?
V_171 : V_172 ;
#else
V_156 = V_171 ;
#endif
V_16 -> V_127 . V_173 = 0 ;
V_16 -> V_127 . V_174 = 0 ;
memset ( V_16 -> V_127 . V_175 ,
0 , sizeof( V_16 -> V_127 . V_175 ) ) ;
break;
default:
return - V_19 ;
}
F_60 ( V_176 , & V_4 -> V_145 ) ;
F_61 ( V_16 , V_123 , V_177 , 1 , V_178 ) ;
V_4 -> V_44 = V_123 [ 0 ] ;
F_52 ( V_16 , V_179 , 2 , V_4 -> V_44 , V_156 ) ;
if ( V_156 != V_167 ) {
F_52 ( V_16 , V_180 , 2 , V_4 -> V_44 , 0 ) ;
F_52 ( V_16 , V_181 , 3 , V_4 -> V_44 , 3 , 1 ) ;
F_52 ( V_16 , V_181 , 3 , V_4 -> V_44 , 8 , 0 ) ;
F_52 ( V_16 , V_181 , 3 , V_4 -> V_44 , 4 , 1 ) ;
if ( F_46 ( & V_16 -> V_182 ) == 0 )
F_52 ( V_16 , V_181 , 2 ,
V_4 -> V_44 , 12 ) ;
F_52 ( V_16 , V_183 , 3 ,
V_4 -> V_44 , 312 , 313 ) ;
if ( V_16 -> V_79 & V_89 )
F_39 ( V_4 ) ;
V_157 = & V_16 -> V_40 [ V_121 ] ;
F_61 ( V_16 , V_123 , V_184 , 2 ,
V_4 -> V_44 , F_45 ( V_157 ) ? 7 : 0 ) ;
V_16 -> V_32 . V_185 = V_4 ;
F_62 ( & V_16 -> V_32 ) ;
if ( ! V_16 -> V_32 . V_186 &&
F_50 ( V_187 , & V_16 -> V_188 ) )
F_52 ( V_16 , V_189 , 2 , V_4 -> V_44 ,
( F_58 ( V_16 -> V_32 . V_190 ) << 8 ) | 1 ) ;
if ( V_156 == V_168 ) {
if ( V_4 -> V_10 == V_191 )
F_52 ( V_16 , V_192 , 2 ,
V_4 -> V_44 , 1 ) ;
else
F_52 ( V_16 , V_192 , 2 ,
V_4 -> V_44 , 0 ) ;
}
}
if ( F_46 ( & V_16 -> V_193 ) == 0 ) {
F_63 ( & V_16 -> V_32 , 1 ) ;
F_60 ( V_194 , & V_16 -> V_188 ) ;
F_64 ( V_16 , 7 , V_195 ) ;
}
F_52 ( V_16 , V_196 , 3 , V_4 -> V_44 ,
( void V_148 * ) & V_16 -> V_149 -> V_197 [ V_4 -> type ] [ 0 ] - V_16 -> V_151 ,
( void V_148 * ) & V_16 -> V_149 -> V_197 [ V_4 -> type ] [ 1 ] - V_16 -> V_151 ) ;
F_54 ( V_4 ) ;
F_53 ( V_4 ) ;
if ( F_52 ( V_16 , V_198 , 1 , V_4 -> V_44 ) ) {
F_65 ( L_11 ) ;
F_66 ( V_144 , & V_4 -> V_145 ) ;
if ( V_4 -> type == V_112 )
F_52 ( V_16 , V_199 , 2 , V_4 -> V_44 , 1 ) ;
else
F_52 ( V_16 , V_199 , 1 , V_4 -> V_44 ) ;
F_60 ( V_146 , & V_4 -> V_145 ) ;
F_52 ( V_16 , V_200 , 1 , V_4 -> V_44 ) ;
F_52 ( V_16 , V_201 , 1 , V_4 -> V_44 ) ;
V_4 -> V_44 = V_45 ;
F_60 ( V_144 , & V_4 -> V_145 ) ;
if ( F_46 ( & V_16 -> V_193 ) == 0 ) {
F_66 ( V_194 , & V_16 -> V_188 ) ;
F_64 ( V_16 , 5 , V_195 ) ;
}
return - V_19 ;
}
if ( V_156 != V_167 )
F_67 ( & V_16 -> V_182 ) ;
F_67 ( & V_16 -> V_193 ) ;
return 0 ;
}
void F_68 ( struct V_15 * V_16 )
{
int V_202 ;
for ( V_202 = V_110 - 1 ; V_202 >= 0 ; V_202 -- ) {
struct V_3 * V_4 = & V_16 -> V_40 [ V_202 ] ;
if ( ! F_45 ( V_4 ) )
continue;
if ( F_50 ( V_146 , & V_4 -> V_145 ) )
F_69 ( V_4 , 0 ) ;
}
}
int F_69 ( struct V_3 * V_4 , int V_203 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( ! F_45 ( V_4 ) )
return - V_19 ;
F_42 ( L_12 ) ;
if ( F_46 ( & V_16 -> V_193 ) == 0 )
return 0 ;
F_66 ( V_144 , & V_4 -> V_145 ) ;
if ( V_4 -> type == V_112 )
F_52 ( V_16 , V_199 , 2 , V_4 -> V_44 , ! V_203 ) ;
else
F_52 ( V_16 , V_199 , 1 , V_4 -> V_44 ) ;
if ( V_4 -> type == V_112 && V_203 ) {
F_21 ( L_13 ) ;
}
if ( V_4 -> type != V_92 )
F_70 ( & V_16 -> V_182 ) ;
F_70 ( & V_16 -> V_193 ) ;
F_60 ( V_146 , & V_4 -> V_145 ) ;
F_52 ( V_16 , V_200 , 1 , V_4 -> V_44 ) ;
F_52 ( V_16 , V_201 , 1 , V_4 -> V_44 ) ;
V_4 -> V_44 = V_45 ;
F_60 ( V_144 , & V_4 -> V_145 ) ;
if ( F_46 ( & V_16 -> V_193 ) > 0 )
return 0 ;
F_63 ( & V_16 -> V_32 , 0 ) ;
F_64 ( V_16 , 5 , V_195 ) ;
F_71 ( & V_4 -> V_56 ) ;
return 0 ;
}
T_1 F_72 ( struct V_15 * V_16 )
{
int V_202 ;
for ( V_202 = 0 ; V_202 < V_110 ; V_202 ++ ) {
struct V_3 * V_4 = & V_16 -> V_40 [ V_202 ] ;
if ( V_4 -> V_84 . V_85 && ( V_4 -> V_44 != V_45 ) )
return V_4 -> V_44 ;
}
return V_45 ;
}
struct V_3 * F_73 ( struct V_15 * V_16 , T_1 V_44 )
{
int V_202 ;
struct V_3 * V_4 ;
if ( V_44 == V_45 )
return NULL ;
for ( V_202 = 0 ; V_202 < V_110 ; V_202 ++ ) {
V_4 = & V_16 -> V_40 [ V_202 ] ;
if ( V_4 -> V_44 != V_44 )
continue;
if ( F_45 ( V_4 ) )
return V_4 ;
}
return NULL ;
}
