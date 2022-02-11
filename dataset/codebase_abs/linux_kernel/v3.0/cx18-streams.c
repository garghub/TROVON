void F_1 ( struct V_1 * V_2 ,
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
F_1 ( V_2 , V_4 , V_6 ) ;
}
if ( ( V_6 -> V_7 . V_21 != 0 ) && ( V_6 -> V_7 . V_22 < V_6 -> V_7 . V_20 ) )
return - V_19 ;
if ( V_6 -> V_7 . V_14 == 0 )
V_6 -> V_7 . V_14 = V_25 ;
if ( V_9 == V_6 -> V_7 . V_8 ) {
V_6 -> V_7 . V_11 = V_11 ;
V_6 -> V_7 . V_12 = V_12 ;
V_6 -> V_7 . V_14 = V_14 ;
V_6 -> V_23 = V_16 -> V_24 ;
V_4 -> V_10 = V_10 ;
V_17 = F_5 ( V_2 , & V_6 -> V_7 , NULL ) ;
if ( V_17 != 0 )
goto V_26;
}
V_6 -> V_7 . V_8 = V_27 ;
return 0 ;
V_26:
F_1 ( V_2 , V_4 , V_6 ) ;
return V_17 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int * V_28 , unsigned int * V_20 )
{
struct V_3 * V_4 = V_2 -> V_29 ;
struct V_15 * V_16 = V_4 -> V_16 ;
* V_20 = 2 * V_16 -> V_30 . V_11 * V_16 -> V_30 . V_12 ;
if ( * V_28 == 0 )
* V_28 = V_31 ;
while ( * V_20 * * V_28 > V_31 * V_32 )
( * V_28 ) -- ;
V_2 -> V_14 = V_25 ;
V_2 -> V_33 = V_25 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_34 * V_7 ,
enum V_13 V_14 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_3 * V_4 = V_2 -> V_29 ;
struct V_15 * V_16 = V_4 -> V_16 ;
return F_4 ( V_2 , V_4 , V_6 , V_4 -> V_10 ,
V_16 -> V_30 . V_11 , V_16 -> V_30 . V_12 , V_14 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_34 * V_7 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_3 * V_4 = V_2 -> V_29 ;
F_1 ( V_2 , V_4 , V_6 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_34 * V_7 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_3 * V_4 = V_2 -> V_29 ;
V_6 -> V_7 . V_8 = V_35 ;
F_11 ( & V_6 -> V_7 . V_36 , & V_4 -> V_37 ) ;
}
static void F_12 ( struct V_15 * V_16 , int type )
{
struct V_3 * V_4 = & V_16 -> V_38 [ type ] ;
struct V_39 * V_40 = V_4 -> V_40 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_40 = V_40 ;
V_4 -> V_41 = NULL ;
V_4 -> V_16 = V_16 ;
V_4 -> type = type ;
V_4 -> V_42 = V_43 [ type ] . V_42 ;
V_4 -> V_44 = V_45 ;
V_4 -> V_46 = V_43 [ type ] . V_46 ;
V_4 -> V_47 = V_16 -> V_48 [ type ] ;
V_4 -> V_49 = V_16 -> V_50 [ type ] ;
F_13 ( & V_4 -> V_51 ) ;
V_4 -> V_52 = 1 ;
V_4 -> V_53 = V_4 -> V_49 * V_4 -> V_52 ;
F_14 ( & V_4 -> V_54 ) ;
V_4 -> V_55 = - 1 ;
F_15 ( & V_4 -> V_56 . V_57 ) ;
F_16 ( & V_4 -> V_56 ) ;
F_15 ( & V_4 -> V_58 . V_57 ) ;
F_16 ( & V_4 -> V_58 ) ;
F_15 ( & V_4 -> V_59 . V_57 ) ;
F_16 ( & V_4 -> V_59 ) ;
F_15 ( & V_4 -> V_60 . V_57 ) ;
F_16 ( & V_4 -> V_60 ) ;
F_17 ( & V_4 -> V_61 , V_62 ) ;
F_13 ( & V_4 -> V_37 ) ;
V_4 -> V_63 . V_64 = V_65 ;
V_4 -> V_63 . V_66 = ( unsigned long ) V_4 ;
F_18 ( & V_4 -> V_63 ) ;
F_15 ( & V_4 -> V_67 ) ;
if ( type == V_68 ) {
F_15 ( & V_4 -> V_69 ) ;
V_4 -> V_70 = V_71 ;
F_19 ( & V_4 -> V_72 , & V_73 ,
& V_16 -> V_74 -> V_75 , & V_4 -> V_69 ,
V_71 ,
V_25 ,
sizeof( struct V_5 ) ,
V_4 , & V_16 -> V_76 ) ;
V_4 -> V_10 = V_77 ;
}
}
static int F_20 ( struct V_15 * V_16 , int type )
{
struct V_3 * V_4 = & V_16 -> V_38 [ type ] ;
T_1 V_78 = V_16 -> V_79 ;
int V_80 = V_43 [ type ] . V_80 ;
int V_81 = V_16 -> V_82 + V_83 + V_80 ;
V_4 -> V_40 = NULL ;
V_4 -> V_41 = NULL ;
V_4 -> V_16 = V_16 ;
V_4 -> type = type ;
V_4 -> V_42 = V_43 [ type ] . V_42 ;
if ( type == V_84 && ! ( V_78 & V_85 ) )
return 0 ;
if ( type == V_86 &&
! ( V_78 & ( V_87 | V_88 ) ) )
return 0 ;
if ( V_43 [ type ] . V_46 != V_89 &&
V_16 -> V_48 [ type ] == 0 ) {
F_21 ( L_1 , V_43 [ type ] . V_42 ) ;
return 0 ;
}
F_12 ( V_16 , type ) ;
if ( type == V_90 ) {
if ( V_16 -> V_91 -> V_92 & V_93 ) {
V_4 -> V_41 = F_22 ( sizeof( struct V_94 ) , V_95 ) ;
if ( V_4 -> V_41 == NULL ) {
F_23 ( L_2
L_3 , V_4 -> V_42 ) ;
return - V_96 ;
}
} else {
V_4 -> V_47 = 0 ;
}
}
if ( V_80 == - 1 )
return 0 ;
V_4 -> V_40 = F_24 () ;
if ( V_4 -> V_40 == NULL ) {
F_23 ( L_4 ,
V_4 -> V_42 ) ;
return - V_96 ;
}
snprintf ( V_4 -> V_40 -> V_42 , sizeof( V_4 -> V_40 -> V_42 ) , L_5 ,
V_16 -> V_97 . V_42 , V_4 -> V_42 ) ;
V_4 -> V_40 -> V_81 = V_81 ;
V_4 -> V_40 -> V_97 = & V_16 -> V_97 ;
V_4 -> V_40 -> V_98 = & V_99 ;
V_4 -> V_40 -> V_100 = V_101 ;
V_4 -> V_40 -> V_102 = V_103 ;
F_25 ( V_104 , & V_4 -> V_40 -> V_105 ) ;
F_26 ( V_4 -> V_40 ) ;
return 0 ;
}
int F_27 ( struct V_15 * V_16 )
{
int type , V_106 ;
for ( type = 0 ; type < V_107 ; type ++ ) {
V_106 = F_20 ( V_16 , type ) ;
if ( V_106 < 0 )
break;
V_106 = F_28 ( & V_16 -> V_38 [ type ] ) ;
if ( V_106 < 0 )
break;
}
if ( type == V_107 )
return 0 ;
F_29 ( V_16 , 0 ) ;
return V_106 ;
}
static int F_30 ( struct V_15 * V_16 , int type )
{
struct V_3 * V_4 = & V_16 -> V_38 [ type ] ;
int V_108 = V_43 [ type ] . V_108 ;
const char * V_42 ;
int V_81 , V_106 ;
if ( type == V_90 && V_4 -> V_41 != NULL ) {
V_106 = F_31 ( V_4 ) ;
if ( V_106 < 0 ) {
F_23 ( L_6 ) ;
return V_106 ;
}
}
if ( V_4 -> V_40 == NULL )
return 0 ;
V_81 = V_4 -> V_40 -> V_81 ;
if ( type != V_109 ) {
struct V_3 * V_110 = & V_16 -> V_38 [ V_109 ] ;
if ( V_110 -> V_40 )
V_81 = V_110 -> V_40 -> V_81
+ V_43 [ type ] . V_80 ;
}
F_32 ( V_4 -> V_40 , V_4 ) ;
V_106 = F_33 ( V_4 -> V_40 , V_108 , V_81 ) ;
if ( V_106 < 0 ) {
F_23 ( L_7 ,
V_4 -> V_42 , V_81 ) ;
V_101 ( V_4 -> V_40 ) ;
V_4 -> V_40 = NULL ;
return V_106 ;
}
V_42 = F_34 ( V_4 -> V_40 ) ;
switch ( V_108 ) {
case V_111 :
F_21 ( L_8 ,
V_42 , V_4 -> V_42 , V_16 -> V_48 [ type ] ,
V_16 -> V_50 [ type ] / 1024 ,
( V_16 -> V_50 [ type ] * 100 / 1024 ) % 100 ) ;
break;
case V_112 :
F_21 ( L_9 , V_42 , V_4 -> V_42 ) ;
break;
case V_113 :
if ( V_16 -> V_48 [ type ] )
F_21 ( L_10
L_11 ,
V_42 , V_4 -> V_42 , V_16 -> V_48 [ type ] ,
V_16 -> V_50 [ type ] ) ;
else
F_21 ( L_9 ,
V_42 , V_4 -> V_42 ) ;
break;
}
return 0 ;
}
int F_35 ( struct V_15 * V_16 )
{
int type ;
int V_114 ;
int V_106 = 0 ;
for ( type = 0 ; type < V_107 ; type ++ ) {
V_114 = F_30 ( V_16 , type ) ;
if ( V_114 && V_106 == 0 )
V_106 = V_114 ;
}
if ( V_106 == 0 )
return 0 ;
F_29 ( V_16 , 1 ) ;
return V_106 ;
}
void F_29 ( struct V_15 * V_16 , int V_115 )
{
struct V_39 * V_116 ;
int type ;
for ( type = 0 ; type < V_107 ; type ++ ) {
if ( type == V_90 ) {
if ( V_16 -> V_38 [ type ] . V_41 != NULL ) {
if ( V_115 )
F_36 ( & V_16 -> V_38 [ type ] ) ;
F_37 ( V_16 -> V_38 [ type ] . V_41 ) ;
V_16 -> V_38 [ type ] . V_41 = NULL ;
F_38 ( & V_16 -> V_38 [ type ] ) ;
}
continue;
}
if ( type == V_117 ) {
if ( V_16 -> V_48 [ type ] != 0 ) {
V_16 -> V_48 [ type ] = 0 ;
if ( V_16 -> V_38 [ type ] . V_47 != 0 )
F_38 ( & V_16 -> V_38 [ type ] ) ;
}
continue;
}
V_116 = V_16 -> V_38 [ type ] . V_40 ;
V_16 -> V_38 [ type ] . V_40 = NULL ;
if ( V_116 == NULL )
continue;
if ( type == V_68 )
F_39 ( & V_16 -> V_38 [ type ] . V_72 ) ;
F_38 ( & V_16 -> V_38 [ type ] ) ;
if ( V_115 )
F_40 ( V_116 ) ;
else
V_101 ( V_116 ) ;
}
}
static void F_41 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
int V_118 = F_42 ( V_16 ) ;
T_1 V_66 [ V_119 ] ;
int V_120 ;
if ( V_16 -> V_121 ) {
V_16 -> V_122 . V_28 = 12 ;
V_16 -> V_122 . V_123 [ 0 ] = 10 ;
V_16 -> V_122 . V_123 [ 1 ] = 273 ;
} else {
V_16 -> V_122 . V_28 = 18 ;
V_16 -> V_122 . V_123 [ 0 ] = 6 ;
V_16 -> V_122 . V_123 [ 1 ] = 318 ;
}
if ( V_118 )
F_43 ( V_16 -> V_124 , V_122 , V_125 , & V_16 -> V_122 . V_126 . V_127 . V_122 ) ;
else
F_43 ( V_16 -> V_124 , V_122 , V_128 , & V_16 -> V_122 . V_126 . V_127 . V_129 ) ;
if ( V_118 ) {
V_120 = V_16 -> V_122 . V_28 * 2 ;
} else {
V_120 = V_16 -> V_121 ? ( 21 - 4 + 1 ) * 2 : ( 23 - 2 + 1 ) * 2 ;
}
V_66 [ 0 ] = V_4 -> V_44 ;
V_66 [ 1 ] = ( V_120 / 2 ) | ( ( V_120 / 2 ) << 16 ) ;
V_66 [ 2 ] = ( V_118 ? V_130
: ( V_16 -> V_121 ? V_131
: V_132 ) ) ;
V_66 [ 3 ] = 1 ;
if ( V_118 ) {
V_66 [ 4 ] = 0x20602060 ;
V_66 [ 5 ] = 0x307090d0 ;
} else {
V_66 [ 4 ] = 0xB0F0B0F0 ;
V_66 [ 5 ] = 0xA0E0A0E0 ;
}
F_44 ( L_12 ,
V_66 [ 0 ] , V_66 [ 1 ] , V_66 [ 2 ] , V_66 [ 3 ] , V_66 [ 4 ] , V_66 [ 5 ] ) ;
F_45 ( V_16 , V_133 , 6 , V_66 ) ;
}
void F_46 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = & V_16 -> V_38 [ V_117 ] ;
struct V_134 * V_135 ;
if ( ! F_47 ( V_4 ) )
return;
if ( ( F_48 ( & V_4 -> V_56 . V_136 ) + F_48 ( & V_4 -> V_58 . V_136 ) ) >=
V_137 )
return;
if ( F_48 ( & V_4 -> V_59 . V_136 ) < 2 )
return;
V_135 = F_49 ( V_4 , & V_4 -> V_59 ) ;
if ( V_135 != NULL )
F_50 ( V_4 , V_135 , & V_4 -> V_56 ) ;
}
static
struct V_138 * F_51 ( struct V_3 * V_4 ,
struct V_134 * V_135 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_138 * V_2 ;
if ( V_4 -> V_44 == V_45 ||
F_52 ( V_139 , & V_4 -> V_140 ) ||
! F_52 ( V_141 , & V_4 -> V_140 ) )
return F_50 ( V_4 , V_135 , & V_4 -> V_56 ) ;
V_2 = F_50 ( V_4 , V_135 , & V_4 -> V_58 ) ;
if ( V_2 != & V_4 -> V_58 )
return V_2 ;
F_53 ( V_4 , V_135 ) ;
F_54 ( V_16 , V_142 , 5 , V_4 -> V_44 ,
( void V_143 * ) & V_16 -> V_144 -> V_145 [ V_135 -> V_55 ] - V_16 -> V_146 ,
V_4 -> V_52 , V_135 -> V_55 , V_4 -> V_53 ) ;
return V_2 ;
}
static
void F_55 ( struct V_3 * V_4 )
{
struct V_138 * V_2 ;
struct V_134 * V_135 ;
if ( F_48 ( & V_4 -> V_56 . V_136 ) == 0 ||
F_48 ( & V_4 -> V_58 . V_136 ) >= V_147 )
return;
do {
V_135 = F_49 ( V_4 , & V_4 -> V_56 ) ;
if ( V_135 == NULL )
break;
V_2 = F_51 ( V_4 , V_135 ) ;
} while ( F_48 ( & V_4 -> V_58 . V_136 ) < V_147
&& V_2 == & V_4 -> V_58 );
}
void V_62 ( struct V_148 * V_149 )
{
struct V_3 * V_4 =
F_8 ( V_149 , struct V_3 , V_61 ) ;
F_55 ( V_4 ) ;
}
static void F_56 ( struct V_3 * V_4 )
{
F_57 ( V_4 ) ;
switch ( V_4 -> type ) {
case V_68 :
if ( V_4 -> V_10 == V_77 )
V_4 -> V_53 = 720 * V_4 -> V_16 -> V_30 . V_12 * 3 / 2 ;
else
V_4 -> V_53 = 720 * V_4 -> V_16 -> V_30 . V_12 * 2 ;
V_4 -> V_52 = V_4 -> V_53 / V_4 -> V_49 ;
if ( V_4 -> V_53 % V_4 -> V_49 )
V_4 -> V_52 ++ ;
break;
case V_86 :
V_4 -> V_52 = 1 ;
if ( F_42 ( V_4 -> V_16 ) ) {
V_4 -> V_53 = ( V_4 -> V_16 -> V_121 ? 12 : 18 )
* 2 * V_130 ;
} else {
V_4 -> V_53 = V_4 -> V_16 -> V_121
? ( 21 - 4 + 1 ) * 2 * V_131
: ( 23 - 2 + 1 ) * 2 * V_132 ;
}
break;
default:
V_4 -> V_52 = 1 ;
V_4 -> V_53 = V_4 -> V_49 * V_4 -> V_52 ;
break;
}
F_58 ( V_4 ) ;
}
int F_59 ( struct V_3 * V_4 )
{
T_1 V_66 [ V_150 ] ;
struct V_15 * V_16 = V_4 -> V_16 ;
int V_151 = 0 ;
struct V_3 * V_152 ;
if ( ! F_47 ( V_4 ) )
return - V_19 ;
F_44 ( L_13 , V_4 -> V_42 ) ;
switch ( V_4 -> type ) {
case V_109 :
V_151 = V_153 ;
V_16 -> V_154 = V_16 -> V_155 = 0 ;
V_16 -> V_156 = V_157 ;
V_16 -> V_158 = F_60 ( V_16 -> V_30 . V_159 ) ;
V_16 -> V_160 = 0 ;
break;
case V_117 :
V_151 = V_161 ;
break;
case V_90 :
V_151 = V_162 ;
break;
case V_68 :
V_151 = V_163 ;
break;
case V_164 :
V_151 = V_165 ;
break;
case V_86 :
#ifdef F_61
V_151 = F_42 ( V_16 ) ?
V_166 : V_167 ;
#else
V_151 = V_166 ;
#endif
V_16 -> V_122 . V_168 = 0 ;
V_16 -> V_122 . V_169 = 0 ;
memset ( V_16 -> V_122 . V_170 ,
0 , sizeof( V_16 -> V_122 . V_170 ) ) ;
break;
default:
return - V_19 ;
}
F_62 ( V_171 , & V_4 -> V_140 ) ;
F_63 ( V_16 , V_66 , V_172 , 1 , V_173 ) ;
V_4 -> V_44 = V_66 [ 0 ] ;
F_54 ( V_16 , V_174 , 2 , V_4 -> V_44 , V_151 ) ;
if ( V_151 != V_162 ) {
F_54 ( V_16 , V_175 , 2 , V_4 -> V_44 , 0 ) ;
F_54 ( V_16 , V_176 , 3 , V_4 -> V_44 , 3 , 1 ) ;
F_54 ( V_16 , V_176 , 3 , V_4 -> V_44 , 8 , 0 ) ;
F_54 ( V_16 , V_176 , 3 , V_4 -> V_44 , 4 , 1 ) ;
if ( F_48 ( & V_16 -> V_177 ) == 0 )
F_54 ( V_16 , V_176 , 2 ,
V_4 -> V_44 , 12 ) ;
F_54 ( V_16 , V_178 , 3 ,
V_4 -> V_44 , 312 , 313 ) ;
if ( V_16 -> V_79 & V_87 )
F_41 ( V_4 ) ;
V_152 = & V_16 -> V_38 [ V_117 ] ;
F_63 ( V_16 , V_66 , V_179 , 2 ,
V_4 -> V_44 , F_47 ( V_152 ) ? 7 : 0 ) ;
V_16 -> V_30 . V_180 = V_4 ;
F_64 ( & V_16 -> V_30 ) ;
if ( ! V_16 -> V_30 . V_181 &&
F_52 ( V_182 , & V_16 -> V_183 ) )
F_54 ( V_16 , V_184 , 2 , V_4 -> V_44 ,
( F_60 ( V_16 -> V_30 . V_185 ) << 8 ) | 1 ) ;
if ( V_151 == V_163 ) {
if ( V_4 -> V_10 == V_186 )
F_54 ( V_16 , V_187 , 2 ,
V_4 -> V_44 , 1 ) ;
else
F_54 ( V_16 , V_187 , 2 ,
V_4 -> V_44 , 0 ) ;
}
}
if ( F_48 ( & V_16 -> V_188 ) == 0 ) {
F_65 ( & V_16 -> V_30 , 1 ) ;
F_62 ( V_189 , & V_16 -> V_183 ) ;
F_66 ( V_16 , 7 , V_190 ) ;
}
F_54 ( V_16 , V_191 , 3 , V_4 -> V_44 ,
( void V_143 * ) & V_16 -> V_144 -> V_192 [ V_4 -> type ] [ 0 ] - V_16 -> V_146 ,
( void V_143 * ) & V_16 -> V_144 -> V_192 [ V_4 -> type ] [ 1 ] - V_16 -> V_146 ) ;
F_56 ( V_4 ) ;
F_55 ( V_4 ) ;
if ( F_54 ( V_16 , V_193 , 1 , V_4 -> V_44 ) ) {
F_67 ( L_14 ) ;
F_25 ( V_139 , & V_4 -> V_140 ) ;
if ( V_4 -> type == V_109 )
F_54 ( V_16 , V_194 , 2 , V_4 -> V_44 , 1 ) ;
else
F_54 ( V_16 , V_194 , 1 , V_4 -> V_44 ) ;
F_62 ( V_141 , & V_4 -> V_140 ) ;
F_54 ( V_16 , V_195 , 1 , V_4 -> V_44 ) ;
F_54 ( V_16 , V_196 , 1 , V_4 -> V_44 ) ;
V_4 -> V_44 = V_45 ;
F_62 ( V_139 , & V_4 -> V_140 ) ;
if ( F_48 ( & V_16 -> V_188 ) == 0 ) {
F_25 ( V_189 , & V_16 -> V_183 ) ;
F_66 ( V_16 , 5 , V_190 ) ;
}
return - V_19 ;
}
if ( V_151 != V_162 )
F_68 ( & V_16 -> V_177 ) ;
F_68 ( & V_16 -> V_188 ) ;
return 0 ;
}
void F_69 ( struct V_15 * V_16 )
{
int V_197 ;
for ( V_197 = V_107 - 1 ; V_197 >= 0 ; V_197 -- ) {
struct V_3 * V_4 = & V_16 -> V_38 [ V_197 ] ;
if ( ! F_47 ( V_4 ) )
continue;
if ( F_52 ( V_141 , & V_4 -> V_140 ) )
F_70 ( V_4 , 0 ) ;
}
}
int F_70 ( struct V_3 * V_4 , int V_198 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
unsigned long V_199 ;
if ( ! F_47 ( V_4 ) )
return - V_19 ;
F_44 ( L_15 ) ;
if ( F_48 ( & V_16 -> V_188 ) == 0 )
return 0 ;
F_25 ( V_139 , & V_4 -> V_140 ) ;
if ( V_4 -> type == V_109 )
F_54 ( V_16 , V_194 , 2 , V_4 -> V_44 , ! V_198 ) ;
else
F_54 ( V_16 , V_194 , 1 , V_4 -> V_44 ) ;
V_199 = V_157 ;
if ( V_4 -> type == V_109 && V_198 ) {
F_21 ( L_16 ) ;
}
if ( V_4 -> type != V_90 )
F_71 ( & V_16 -> V_177 ) ;
F_71 ( & V_16 -> V_188 ) ;
F_62 ( V_141 , & V_4 -> V_140 ) ;
F_54 ( V_16 , V_195 , 1 , V_4 -> V_44 ) ;
F_54 ( V_16 , V_196 , 1 , V_4 -> V_44 ) ;
V_4 -> V_44 = V_45 ;
F_62 ( V_139 , & V_4 -> V_140 ) ;
if ( F_48 ( & V_16 -> V_188 ) > 0 )
return 0 ;
F_65 ( & V_16 -> V_30 , 0 ) ;
F_66 ( V_16 , 5 , V_190 ) ;
F_72 ( & V_4 -> V_54 ) ;
return 0 ;
}
T_1 F_73 ( struct V_15 * V_16 )
{
int V_197 ;
for ( V_197 = 0 ; V_197 < V_107 ; V_197 ++ ) {
struct V_3 * V_4 = & V_16 -> V_38 [ V_197 ] ;
if ( V_4 -> V_40 && ( V_4 -> V_44 != V_45 ) )
return V_4 -> V_44 ;
}
return V_45 ;
}
struct V_3 * F_74 ( struct V_15 * V_16 , T_1 V_44 )
{
int V_197 ;
struct V_3 * V_4 ;
if ( V_44 == V_45 )
return NULL ;
for ( V_197 = 0 ; V_197 < V_107 ; V_197 ++ ) {
V_4 = & V_16 -> V_38 [ V_197 ] ;
if ( V_4 -> V_44 != V_44 )
continue;
if ( F_47 ( V_4 ) )
return V_4 ;
}
return NULL ;
}
