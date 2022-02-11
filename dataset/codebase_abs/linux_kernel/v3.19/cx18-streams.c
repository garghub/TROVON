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
struct V_41 * V_42 = V_4 -> V_42 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_42 = V_42 ;
V_4 -> V_43 = NULL ;
V_4 -> V_16 = V_16 ;
V_4 -> type = type ;
V_4 -> V_44 = V_45 [ type ] . V_44 ;
V_4 -> V_46 = V_47 ;
V_4 -> V_48 = V_45 [ type ] . V_48 ;
V_4 -> V_49 = V_45 [ type ] . V_50 ;
V_4 -> V_51 = V_16 -> V_52 [ type ] ;
V_4 -> V_53 = V_16 -> V_54 [ type ] ;
F_13 ( & V_4 -> V_55 ) ;
V_4 -> V_56 = 1 ;
V_4 -> V_57 = V_4 -> V_53 * V_4 -> V_56 ;
F_14 ( & V_4 -> V_58 ) ;
V_4 -> V_59 = - 1 ;
F_15 ( & V_4 -> V_60 . V_61 ) ;
F_16 ( & V_4 -> V_60 ) ;
F_15 ( & V_4 -> V_62 . V_61 ) ;
F_16 ( & V_4 -> V_62 ) ;
F_15 ( & V_4 -> V_63 . V_61 ) ;
F_16 ( & V_4 -> V_63 ) ;
F_15 ( & V_4 -> V_64 . V_61 ) ;
F_16 ( & V_4 -> V_64 ) ;
F_17 ( & V_4 -> V_65 , V_66 ) ;
F_13 ( & V_4 -> V_39 ) ;
V_4 -> V_67 . V_68 = V_69 ;
V_4 -> V_67 . V_70 = ( unsigned long ) V_4 ;
F_18 ( & V_4 -> V_67 ) ;
F_15 ( & V_4 -> V_71 ) ;
if ( type == V_72 ) {
F_15 ( & V_4 -> V_73 ) ;
V_4 -> V_74 = V_75 ;
F_19 ( & V_4 -> V_76 , & V_77 ,
& V_16 -> V_78 -> V_79 , & V_4 -> V_73 ,
V_75 ,
V_27 ,
sizeof( struct V_5 ) ,
V_4 , & V_16 -> V_80 ) ;
V_4 -> V_10 = V_25 ;
V_4 -> V_26 = V_16 -> V_32 . V_12 * 720 * 3 / 2 ;
}
}
static int F_20 ( struct V_15 * V_16 , int type )
{
struct V_3 * V_4 = & V_16 -> V_40 [ type ] ;
T_1 V_81 = V_16 -> V_82 ;
int V_83 = V_45 [ type ] . V_83 ;
int V_84 = V_16 -> V_85 + V_86 + V_83 ;
V_4 -> V_42 = NULL ;
V_4 -> V_43 = NULL ;
V_4 -> V_16 = V_16 ;
V_4 -> type = type ;
V_4 -> V_44 = V_45 [ type ] . V_44 ;
if ( type == V_87 && ! ( V_81 & V_88 ) )
return 0 ;
if ( type == V_89 &&
! ( V_81 & ( V_90 | V_91 ) ) )
return 0 ;
if ( V_45 [ type ] . V_48 != V_92 &&
V_16 -> V_52 [ type ] == 0 ) {
F_21 ( L_1 , V_45 [ type ] . V_44 ) ;
return 0 ;
}
F_12 ( V_16 , type ) ;
if ( type == V_93 ) {
if ( V_16 -> V_94 -> V_95 & V_96 ) {
V_4 -> V_43 = F_22 ( sizeof( struct V_97 ) , V_98 ) ;
if ( V_4 -> V_43 == NULL ) {
F_23 ( L_2
L_3 , V_4 -> V_44 ) ;
return - V_99 ;
}
} else {
V_4 -> V_51 = 0 ;
}
}
if ( V_83 == - 1 )
return 0 ;
V_4 -> V_42 = F_24 () ;
if ( V_4 -> V_42 == NULL ) {
F_23 ( L_4 ,
V_4 -> V_44 ) ;
return - V_99 ;
}
snprintf ( V_4 -> V_42 -> V_44 , sizeof( V_4 -> V_42 -> V_44 ) , L_5 ,
V_16 -> V_100 . V_44 , V_4 -> V_44 ) ;
V_4 -> V_42 -> V_84 = V_84 ;
V_4 -> V_42 -> V_100 = & V_16 -> V_100 ;
V_4 -> V_42 -> V_101 = & V_102 ;
V_4 -> V_42 -> V_103 = V_104 ;
V_4 -> V_42 -> V_105 = V_106 ;
V_4 -> V_42 -> V_61 = & V_16 -> V_80 ;
F_25 ( V_4 -> V_42 ) ;
return 0 ;
}
int F_26 ( struct V_15 * V_16 )
{
int type , V_107 ;
for ( type = 0 ; type < V_108 ; type ++ ) {
V_107 = F_20 ( V_16 , type ) ;
if ( V_107 < 0 )
break;
V_107 = F_27 ( & V_16 -> V_40 [ type ] ) ;
if ( V_107 < 0 )
break;
}
if ( type == V_108 )
return 0 ;
F_28 ( V_16 , 0 ) ;
return V_107 ;
}
static int F_29 ( struct V_15 * V_16 , int type )
{
struct V_3 * V_4 = & V_16 -> V_40 [ type ] ;
int V_109 = V_45 [ type ] . V_109 ;
const char * V_44 ;
int V_84 , V_107 ;
if ( type == V_93 && V_4 -> V_43 != NULL ) {
V_107 = F_30 ( V_4 ) ;
if ( V_107 < 0 ) {
F_23 ( L_6 ) ;
return V_107 ;
}
}
if ( V_4 -> V_42 == NULL )
return 0 ;
V_84 = V_4 -> V_42 -> V_84 ;
if ( type != V_110 ) {
struct V_3 * V_111 = & V_16 -> V_40 [ V_110 ] ;
if ( V_111 -> V_42 )
V_84 = V_111 -> V_42 -> V_84
+ V_45 [ type ] . V_83 ;
}
F_31 ( V_4 -> V_42 , V_4 ) ;
V_107 = F_32 ( V_4 -> V_42 , V_109 , V_84 ) ;
if ( V_107 < 0 ) {
F_23 ( L_7 ,
V_4 -> V_44 , V_84 ) ;
V_104 ( V_4 -> V_42 ) ;
V_4 -> V_42 = NULL ;
return V_107 ;
}
V_44 = F_33 ( V_4 -> V_42 ) ;
switch ( V_109 ) {
case V_112 :
F_21 ( L_8 ,
V_44 , V_4 -> V_44 , V_16 -> V_52 [ type ] ,
V_16 -> V_54 [ type ] / 1024 ,
( V_16 -> V_54 [ type ] * 100 / 1024 ) % 100 ) ;
break;
case V_113 :
F_21 ( L_9 , V_44 , V_4 -> V_44 ) ;
break;
case V_114 :
if ( V_16 -> V_52 [ type ] )
F_21 ( L_10
L_11 ,
V_44 , V_4 -> V_44 , V_16 -> V_52 [ type ] ,
V_16 -> V_54 [ type ] ) ;
else
F_21 ( L_9 ,
V_44 , V_4 -> V_44 ) ;
break;
}
return 0 ;
}
int F_34 ( struct V_15 * V_16 )
{
int type ;
int V_115 ;
int V_107 = 0 ;
for ( type = 0 ; type < V_108 ; type ++ ) {
V_115 = F_29 ( V_16 , type ) ;
if ( V_115 && V_107 == 0 )
V_107 = V_115 ;
}
if ( V_107 == 0 )
return 0 ;
F_28 ( V_16 , 1 ) ;
return V_107 ;
}
void F_28 ( struct V_15 * V_16 , int V_116 )
{
struct V_41 * V_117 ;
int type ;
for ( type = 0 ; type < V_108 ; type ++ ) {
if ( type == V_93 ) {
if ( V_16 -> V_40 [ type ] . V_43 != NULL ) {
if ( V_116 )
F_35 ( & V_16 -> V_40 [ type ] ) ;
F_36 ( V_16 -> V_40 [ type ] . V_43 ) ;
V_16 -> V_40 [ type ] . V_43 = NULL ;
F_37 ( & V_16 -> V_40 [ type ] ) ;
}
continue;
}
if ( type == V_118 ) {
if ( V_16 -> V_52 [ type ] != 0 ) {
V_16 -> V_52 [ type ] = 0 ;
if ( V_16 -> V_40 [ type ] . V_51 != 0 )
F_37 ( & V_16 -> V_40 [ type ] ) ;
}
continue;
}
V_117 = V_16 -> V_40 [ type ] . V_42 ;
V_16 -> V_40 [ type ] . V_42 = NULL ;
if ( V_117 == NULL )
continue;
if ( type == V_72 )
F_38 ( & V_16 -> V_40 [ type ] . V_76 ) ;
F_37 ( & V_16 -> V_40 [ type ] ) ;
if ( V_116 )
F_39 ( V_117 ) ;
else
V_104 ( V_117 ) ;
}
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
int V_119 = F_41 ( V_16 ) ;
T_1 V_70 [ V_120 ] ;
int V_121 ;
if ( V_16 -> V_122 ) {
V_16 -> V_123 . V_30 = 12 ;
V_16 -> V_123 . V_124 [ 0 ] = 10 ;
V_16 -> V_123 . V_124 [ 1 ] = 273 ;
} else {
V_16 -> V_123 . V_30 = 18 ;
V_16 -> V_123 . V_124 [ 0 ] = 6 ;
V_16 -> V_123 . V_124 [ 1 ] = 318 ;
}
if ( V_119 )
F_42 ( V_16 -> V_125 , V_123 , V_126 , & V_16 -> V_123 . V_127 . V_128 . V_123 ) ;
else
F_42 ( V_16 -> V_125 , V_123 , V_129 , & V_16 -> V_123 . V_127 . V_128 . V_130 ) ;
if ( V_119 ) {
V_121 = V_16 -> V_123 . V_30 * 2 ;
} else {
V_121 = V_16 -> V_122 ? ( 21 - 4 + 1 ) * 2 : ( 23 - 2 + 1 ) * 2 ;
}
V_70 [ 0 ] = V_4 -> V_46 ;
V_70 [ 1 ] = ( V_121 / 2 ) | ( ( V_121 / 2 ) << 16 ) ;
V_70 [ 2 ] = ( V_119 ? V_131
: ( V_16 -> V_122 ? V_132
: V_133 ) ) ;
V_70 [ 3 ] = 1 ;
if ( V_119 ) {
V_70 [ 4 ] = 0x20602060 ;
V_70 [ 5 ] = 0x307090d0 ;
} else {
V_70 [ 4 ] = 0xB0F0B0F0 ;
V_70 [ 5 ] = 0xA0E0A0E0 ;
}
F_43 ( L_12 ,
V_70 [ 0 ] , V_70 [ 1 ] , V_70 [ 2 ] , V_70 [ 3 ] , V_70 [ 4 ] , V_70 [ 5 ] ) ;
F_44 ( V_16 , V_134 , 6 , V_70 ) ;
}
void F_45 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = & V_16 -> V_40 [ V_118 ] ;
struct V_135 * V_136 ;
if ( ! F_46 ( V_4 ) )
return;
if ( ( F_47 ( & V_4 -> V_60 . V_137 ) + F_47 ( & V_4 -> V_62 . V_137 ) ) >=
V_138 )
return;
if ( F_47 ( & V_4 -> V_63 . V_137 ) < 2 )
return;
V_136 = F_48 ( V_4 , & V_4 -> V_63 ) ;
if ( V_136 != NULL )
F_49 ( V_4 , V_136 , & V_4 -> V_60 ) ;
}
static
struct V_139 * F_50 ( struct V_3 * V_4 ,
struct V_135 * V_136 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_139 * V_2 ;
if ( V_4 -> V_46 == V_47 ||
F_51 ( V_140 , & V_4 -> V_141 ) ||
! F_51 ( V_142 , & V_4 -> V_141 ) )
return F_49 ( V_4 , V_136 , & V_4 -> V_60 ) ;
V_2 = F_49 ( V_4 , V_136 , & V_4 -> V_62 ) ;
if ( V_2 != & V_4 -> V_62 )
return V_2 ;
F_52 ( V_4 , V_136 ) ;
F_53 ( V_16 , V_143 , 5 , V_4 -> V_46 ,
( void V_144 * ) & V_16 -> V_145 -> V_146 [ V_136 -> V_59 ] - V_16 -> V_147 ,
V_4 -> V_56 , V_136 -> V_59 , V_4 -> V_57 ) ;
return V_2 ;
}
static
void F_54 ( struct V_3 * V_4 )
{
struct V_139 * V_2 ;
struct V_135 * V_136 ;
if ( F_47 ( & V_4 -> V_60 . V_137 ) == 0 ||
F_47 ( & V_4 -> V_62 . V_137 ) >= V_148 )
return;
do {
V_136 = F_48 ( V_4 , & V_4 -> V_60 ) ;
if ( V_136 == NULL )
break;
V_2 = F_50 ( V_4 , V_136 ) ;
} while ( F_47 ( & V_4 -> V_62 . V_137 ) < V_148
&& V_2 == & V_4 -> V_62 );
}
void V_66 ( struct V_149 * V_150 )
{
struct V_3 * V_4 =
F_8 ( V_150 , struct V_3 , V_65 ) ;
F_54 ( V_4 ) ;
}
static void F_55 ( struct V_3 * V_4 )
{
F_56 ( V_4 ) ;
switch ( V_4 -> type ) {
case V_72 :
if ( V_4 -> V_10 == V_25 )
V_4 -> V_57 = 720 * V_4 -> V_16 -> V_32 . V_12 * 3 / 2 ;
else
V_4 -> V_57 = 720 * V_4 -> V_16 -> V_32 . V_12 * 2 ;
V_4 -> V_56 = V_4 -> V_57 / V_4 -> V_53 ;
if ( V_4 -> V_57 % V_4 -> V_53 )
V_4 -> V_56 ++ ;
break;
case V_89 :
V_4 -> V_56 = 1 ;
if ( F_41 ( V_4 -> V_16 ) ) {
V_4 -> V_57 = ( V_4 -> V_16 -> V_122 ? 12 : 18 )
* 2 * V_131 ;
} else {
V_4 -> V_57 = V_4 -> V_16 -> V_122
? ( 21 - 4 + 1 ) * 2 * V_132
: ( 23 - 2 + 1 ) * 2 * V_133 ;
}
break;
default:
V_4 -> V_56 = 1 ;
V_4 -> V_57 = V_4 -> V_53 * V_4 -> V_56 ;
break;
}
F_57 ( V_4 ) ;
}
int F_58 ( struct V_3 * V_4 )
{
T_1 V_70 [ V_151 ] ;
struct V_15 * V_16 = V_4 -> V_16 ;
int V_152 = 0 ;
struct V_3 * V_153 ;
if ( ! F_46 ( V_4 ) )
return - V_19 ;
F_43 ( L_13 , V_4 -> V_44 ) ;
switch ( V_4 -> type ) {
case V_110 :
V_152 = V_154 ;
V_16 -> V_155 = V_16 -> V_156 = 0 ;
V_16 -> V_157 = V_158 ;
V_16 -> V_159 = F_59 ( V_16 -> V_32 . V_160 ) ;
V_16 -> V_161 = 0 ;
break;
case V_118 :
V_152 = V_162 ;
break;
case V_93 :
V_152 = V_163 ;
break;
case V_72 :
V_152 = V_164 ;
break;
case V_165 :
V_152 = V_166 ;
break;
case V_89 :
#ifdef F_60
V_152 = F_41 ( V_16 ) ?
V_167 : V_168 ;
#else
V_152 = V_167 ;
#endif
V_16 -> V_123 . V_169 = 0 ;
V_16 -> V_123 . V_170 = 0 ;
memset ( V_16 -> V_123 . V_171 ,
0 , sizeof( V_16 -> V_123 . V_171 ) ) ;
break;
default:
return - V_19 ;
}
F_61 ( V_172 , & V_4 -> V_141 ) ;
F_62 ( V_16 , V_70 , V_173 , 1 , V_174 ) ;
V_4 -> V_46 = V_70 [ 0 ] ;
F_53 ( V_16 , V_175 , 2 , V_4 -> V_46 , V_152 ) ;
if ( V_152 != V_163 ) {
F_53 ( V_16 , V_176 , 2 , V_4 -> V_46 , 0 ) ;
F_53 ( V_16 , V_177 , 3 , V_4 -> V_46 , 3 , 1 ) ;
F_53 ( V_16 , V_177 , 3 , V_4 -> V_46 , 8 , 0 ) ;
F_53 ( V_16 , V_177 , 3 , V_4 -> V_46 , 4 , 1 ) ;
if ( F_47 ( & V_16 -> V_178 ) == 0 )
F_53 ( V_16 , V_177 , 2 ,
V_4 -> V_46 , 12 ) ;
F_53 ( V_16 , V_179 , 3 ,
V_4 -> V_46 , 312 , 313 ) ;
if ( V_16 -> V_82 & V_90 )
F_40 ( V_4 ) ;
V_153 = & V_16 -> V_40 [ V_118 ] ;
F_62 ( V_16 , V_70 , V_180 , 2 ,
V_4 -> V_46 , F_46 ( V_153 ) ? 7 : 0 ) ;
V_16 -> V_32 . V_181 = V_4 ;
F_63 ( & V_16 -> V_32 ) ;
if ( ! V_16 -> V_32 . V_182 &&
F_51 ( V_183 , & V_16 -> V_184 ) )
F_53 ( V_16 , V_185 , 2 , V_4 -> V_46 ,
( F_59 ( V_16 -> V_32 . V_186 ) << 8 ) | 1 ) ;
if ( V_152 == V_164 ) {
if ( V_4 -> V_10 == V_187 )
F_53 ( V_16 , V_188 , 2 ,
V_4 -> V_46 , 1 ) ;
else
F_53 ( V_16 , V_188 , 2 ,
V_4 -> V_46 , 0 ) ;
}
}
if ( F_47 ( & V_16 -> V_189 ) == 0 ) {
F_64 ( & V_16 -> V_32 , 1 ) ;
F_61 ( V_190 , & V_16 -> V_184 ) ;
F_65 ( V_16 , 7 , V_191 ) ;
}
F_53 ( V_16 , V_192 , 3 , V_4 -> V_46 ,
( void V_144 * ) & V_16 -> V_145 -> V_193 [ V_4 -> type ] [ 0 ] - V_16 -> V_147 ,
( void V_144 * ) & V_16 -> V_145 -> V_193 [ V_4 -> type ] [ 1 ] - V_16 -> V_147 ) ;
F_55 ( V_4 ) ;
F_54 ( V_4 ) ;
if ( F_53 ( V_16 , V_194 , 1 , V_4 -> V_46 ) ) {
F_66 ( L_14 ) ;
F_67 ( V_140 , & V_4 -> V_141 ) ;
if ( V_4 -> type == V_110 )
F_53 ( V_16 , V_195 , 2 , V_4 -> V_46 , 1 ) ;
else
F_53 ( V_16 , V_195 , 1 , V_4 -> V_46 ) ;
F_61 ( V_142 , & V_4 -> V_141 ) ;
F_53 ( V_16 , V_196 , 1 , V_4 -> V_46 ) ;
F_53 ( V_16 , V_197 , 1 , V_4 -> V_46 ) ;
V_4 -> V_46 = V_47 ;
F_61 ( V_140 , & V_4 -> V_141 ) ;
if ( F_47 ( & V_16 -> V_189 ) == 0 ) {
F_67 ( V_190 , & V_16 -> V_184 ) ;
F_65 ( V_16 , 5 , V_191 ) ;
}
return - V_19 ;
}
if ( V_152 != V_163 )
F_68 ( & V_16 -> V_178 ) ;
F_68 ( & V_16 -> V_189 ) ;
return 0 ;
}
void F_69 ( struct V_15 * V_16 )
{
int V_198 ;
for ( V_198 = V_108 - 1 ; V_198 >= 0 ; V_198 -- ) {
struct V_3 * V_4 = & V_16 -> V_40 [ V_198 ] ;
if ( ! F_46 ( V_4 ) )
continue;
if ( F_51 ( V_142 , & V_4 -> V_141 ) )
F_70 ( V_4 , 0 ) ;
}
}
int F_70 ( struct V_3 * V_4 , int V_199 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( ! F_46 ( V_4 ) )
return - V_19 ;
F_43 ( L_15 ) ;
if ( F_47 ( & V_16 -> V_189 ) == 0 )
return 0 ;
F_67 ( V_140 , & V_4 -> V_141 ) ;
if ( V_4 -> type == V_110 )
F_53 ( V_16 , V_195 , 2 , V_4 -> V_46 , ! V_199 ) ;
else
F_53 ( V_16 , V_195 , 1 , V_4 -> V_46 ) ;
if ( V_4 -> type == V_110 && V_199 ) {
F_21 ( L_16 ) ;
}
if ( V_4 -> type != V_93 )
F_71 ( & V_16 -> V_178 ) ;
F_71 ( & V_16 -> V_189 ) ;
F_61 ( V_142 , & V_4 -> V_141 ) ;
F_53 ( V_16 , V_196 , 1 , V_4 -> V_46 ) ;
F_53 ( V_16 , V_197 , 1 , V_4 -> V_46 ) ;
V_4 -> V_46 = V_47 ;
F_61 ( V_140 , & V_4 -> V_141 ) ;
if ( F_47 ( & V_16 -> V_189 ) > 0 )
return 0 ;
F_64 ( & V_16 -> V_32 , 0 ) ;
F_65 ( V_16 , 5 , V_191 ) ;
F_72 ( & V_4 -> V_58 ) ;
return 0 ;
}
T_1 F_73 ( struct V_15 * V_16 )
{
int V_198 ;
for ( V_198 = 0 ; V_198 < V_108 ; V_198 ++ ) {
struct V_3 * V_4 = & V_16 -> V_40 [ V_198 ] ;
if ( V_4 -> V_42 && ( V_4 -> V_46 != V_47 ) )
return V_4 -> V_46 ;
}
return V_47 ;
}
struct V_3 * F_74 ( struct V_15 * V_16 , T_1 V_46 )
{
int V_198 ;
struct V_3 * V_4 ;
if ( V_46 == V_47 )
return NULL ;
for ( V_198 = 0 ; V_198 < V_108 ; V_198 ++ ) {
V_4 = & V_16 -> V_40 [ V_198 ] ;
if ( V_4 -> V_46 != V_46 )
continue;
if ( F_46 ( V_4 ) )
return V_4 ;
}
return NULL ;
}
