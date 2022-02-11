static inline bool F_1 ( int V_1 )
{
return V_2 >= V_1 ;
}
static void F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_3 ( V_4 , struct V_5 , V_4 ) ;
V_8 = F_4 ( V_6 -> V_9 , 0 , V_6 -> V_10 , V_6 -> V_11 ) ;
if ( ! V_8 )
goto V_12;
F_5 ( & V_8 -> V_13 ) ;
F_6 ( V_8 ) ;
V_12:
F_7 ( V_6 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_14 * V_9 ;
struct V_7 * V_8 ;
V_6 = F_3 ( V_4 , struct V_5 , V_4 ) ;
V_9 = V_6 -> V_9 ;
F_9 ( & V_9 -> V_15 ) ;
F_10 (sdev, host)
F_11 ( V_8 , 1 , 1 , NULL ) ;
F_12 ( & V_9 -> V_15 ) ;
F_13 ( V_9 ) ;
F_7 ( V_6 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_3 ( V_4 , struct V_5 , V_4 ) ;
if ( ! F_15 ( V_6 -> V_9 ) )
goto V_12;
V_8 = F_4 ( V_6 -> V_9 , 0 , V_6 -> V_10 , V_6 -> V_11 ) ;
if ( V_8 ) {
F_16 ( V_8 ) ;
F_6 ( V_8 ) ;
}
F_17 ( V_6 -> V_9 ) ;
V_12:
F_7 ( V_6 ) ;
}
static inline struct V_16 * F_18 (
struct V_17 * V_18 )
{
struct V_16 * V_19 ;
V_19 = F_19 ( V_18 ) ;
if ( V_19 && V_19 -> V_20 )
V_19 = NULL ;
return V_19 ;
}
static inline void F_20 ( struct V_16 * V_21 )
{
V_21 -> V_22 = true ;
F_21 ( V_21 -> V_23 ,
F_22 ( & V_21 -> V_24 ) == 0 ) ;
V_21 -> V_22 = false ;
}
static inline struct V_16 * F_23 (
struct V_17 * V_18 )
{
struct V_16 * V_19 ;
V_19 = F_19 ( V_18 ) ;
if ( ! V_19 )
goto V_25;
if ( V_19 -> V_20 &&
( F_22 ( & V_19 -> V_24 ) == 0 ) )
V_19 = NULL ;
V_25:
return V_19 ;
}
static void F_24 ( struct V_26 * V_27 )
{
struct V_17 * V_18 = V_27 -> V_28 -> V_29 ;
struct V_16 * V_19 ;
struct V_30 V_31 ;
V_19 = F_18 ( V_18 ) ;
if ( ! V_19 )
return;
if ( V_19 -> V_32 == false )
return;
memset ( & V_31 , 0 , sizeof( struct V_30 ) ) ;
F_25 ( V_27 ,
V_33 ,
V_33 ,
( void * ) & V_31 ,
sizeof( struct V_30 ) ,
V_34 , V_27 ) ;
}
static void F_26 ( struct V_17 * V_18 , int V_35 )
{
struct V_16 * V_19 ;
int V_36 = F_27 () ;
int V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_40 ;
int V_41 , V_42 ;
V_37 = ( ( V_35 > V_36 ) ? V_36 : V_35 ) ;
V_19 = F_18 ( V_18 ) ;
if ( ! V_19 )
return;
V_39 = & V_19 -> V_43 ;
V_40 = & V_39 -> V_40 ;
V_19 -> V_32 = true ;
F_28 ( V_18 -> V_44 , F_24 ) ;
if ( F_29 ( V_18 -> V_44 ) )
return;
V_19 -> V_32 = false ;
memset ( V_39 , 0 , sizeof( struct V_38 ) ) ;
F_30 ( & V_39 -> F_21 ) ;
V_40 -> V_45 = V_46 ;
V_40 -> V_47 = V_48 ;
V_40 -> V_49 = V_37 ;
V_41 = F_31 ( V_18 -> V_44 , V_40 ,
( sizeof( struct V_40 ) -
V_50 ) ,
( unsigned long ) V_39 ,
V_51 ,
V_52 ) ;
if ( V_41 != 0 )
return;
V_42 = F_32 ( & V_39 -> F_21 , 10 * V_53 ) ;
if ( V_42 == 0 )
return;
if ( V_40 -> V_45 != V_54 ||
V_40 -> V_55 != 0 )
return;
V_19 -> V_32 = true ;
F_29 ( V_18 -> V_44 ) ;
}
static void F_33 ( struct V_16 * V_19 ,
struct V_40 * V_40 )
{
if ( V_40 -> V_56 . V_57 ) {
V_19 -> V_58 =
F_34 ( V_40 -> V_56 . V_59 ) ;
V_19 -> V_60 =
F_34 ( V_40 -> V_56 . V_61 ) ;
} else {
V_19 -> V_58 =
F_34 ( V_40 -> V_56 . V_62 ) ;
V_19 -> V_60 =
F_34 ( V_40 -> V_56 . V_63 ) ;
}
}
static int F_35 ( struct V_17 * V_18 ,
struct V_38 * V_39 ,
bool V_64 )
{
struct V_40 * V_40 ;
int V_41 , V_42 ;
V_40 = & V_39 -> V_40 ;
F_30 ( & V_39 -> F_21 ) ;
V_40 -> V_47 = V_48 ;
V_41 = F_31 ( V_18 -> V_44 , V_40 ,
( sizeof( struct V_40 ) -
V_50 ) ,
( unsigned long ) V_39 ,
V_51 ,
V_52 ) ;
if ( V_41 != 0 )
return V_41 ;
V_42 = F_32 ( & V_39 -> F_21 , 5 * V_53 ) ;
if ( V_42 == 0 )
return - V_65 ;
if ( ! V_64 )
return V_41 ;
if ( V_40 -> V_45 != V_54 ||
V_40 -> V_55 != 0 )
return - V_66 ;
return V_41 ;
}
static int F_36 ( struct V_17 * V_18 , bool V_67 )
{
struct V_16 * V_19 ;
struct V_38 * V_39 ;
struct V_40 * V_40 ;
int V_41 , V_68 ;
int V_35 ;
bool V_69 = false ;
V_19 = F_18 ( V_18 ) ;
if ( ! V_19 )
return - V_70 ;
V_39 = & V_19 -> V_43 ;
V_40 = & V_39 -> V_40 ;
memset ( V_39 , 0 , sizeof( struct V_38 ) ) ;
V_40 -> V_45 = V_71 ;
V_41 = F_35 ( V_18 , V_39 , true ) ;
if ( V_41 )
return V_41 ;
for ( V_68 = 0 ; V_68 < F_37 ( V_72 ) ; V_68 ++ ) {
memset ( V_40 , 0 , sizeof( struct V_40 ) ) ;
V_40 -> V_45 =
V_73 ;
V_40 -> V_74 . V_75 =
V_72 [ V_68 ] . V_76 ;
V_40 -> V_74 . V_77 = 0 ;
V_41 = F_35 ( V_18 , V_39 , false ) ;
if ( V_41 != 0 )
return V_41 ;
if ( V_40 -> V_45 != V_54 )
return - V_66 ;
if ( V_40 -> V_55 == 0 ) {
V_78 =
V_72 [ V_68 ] . V_76 ;
V_79 =
V_72 [ V_68 ] . V_79 ;
V_50 =
V_72 [ V_68 ] . V_50 ;
break;
}
}
if ( V_40 -> V_55 != 0 )
return - V_66 ;
memset ( V_40 , 0 , sizeof( struct V_40 ) ) ;
V_40 -> V_45 = V_80 ;
V_41 = F_35 ( V_18 , V_39 , true ) ;
if ( V_41 != 0 )
return V_41 ;
V_35 = V_40 -> V_81 . V_82 ;
if ( V_78 >= V_83 ) {
if ( V_40 -> V_81 . V_47 &
V_84 )
V_69 = true ;
}
V_19 -> V_85 =
V_40 -> V_81 . V_85 ;
if ( ! V_67 )
goto V_12;
memset ( V_40 , 0 , sizeof( struct V_40 ) ) ;
V_40 -> V_45 = V_86 ;
V_41 = F_35 ( V_18 , V_39 , true ) ;
if ( V_41 != 0 )
return V_41 ;
F_33 ( V_19 , V_40 ) ;
V_12:
memset ( V_40 , 0 , sizeof( struct V_40 ) ) ;
V_40 -> V_45 = V_87 ;
V_41 = F_35 ( V_18 , V_39 , true ) ;
if ( V_41 != 0 )
return V_41 ;
if ( V_69 )
F_26 ( V_18 , V_35 ) ;
return V_41 ;
}
static void F_38 ( struct V_88 * V_89 ,
struct V_90 * V_91 ,
struct V_14 * V_9 ,
T_1 V_92 , T_1 V_93 )
{
struct V_5 * V_6 ;
void (* F_39)( struct V_3 * V_4 );
bool V_94 = false ;
switch ( F_40 ( V_89 -> V_95 ) ) {
case V_96 :
switch ( V_91 -> V_97 [ 0 ] ) {
case V_98 :
case V_99 :
F_41 ( V_91 , V_100 ) ;
break;
case V_101 :
break;
default:
F_41 ( V_91 , V_102 ) ;
}
break;
case V_103 :
V_94 = true ;
F_39 = F_14 ;
break;
case V_104 :
if ( V_89 -> V_95 & V_105 &&
( V_92 == 0x2a ) && ( V_93 == 0x9 ) ) {
V_94 = true ;
F_39 = F_2 ;
F_41 ( V_91 , V_106 ) ;
}
break;
}
if ( ! V_94 )
return;
V_6 = F_42 ( sizeof( struct V_5 ) , V_107 ) ;
if ( ! V_6 ) {
F_41 ( V_91 , V_102 ) ;
return;
}
V_6 -> V_9 = V_9 ;
V_6 -> V_11 = V_89 -> V_11 ;
V_6 -> V_10 = V_89 -> V_108 ;
F_43 ( & V_6 -> V_4 , F_39 ) ;
F_44 ( & V_6 -> V_4 ) ;
}
static void F_45 ( struct V_38 * V_109 ,
struct V_16 * V_110 )
{
struct V_90 * V_91 = V_109 -> V_111 ;
struct V_112 V_113 ;
struct V_88 * V_89 ;
struct V_14 * V_9 ;
T_2 V_114 = V_109 -> V_114 ;
void * V_115 = V_109 -> V_115 ;
V_9 = V_110 -> V_9 ;
V_89 = & V_109 -> V_40 . V_89 ;
V_91 -> V_116 = V_89 -> V_117 ;
if ( V_91 -> V_116 ) {
if ( F_46 ( V_91 -> V_118 ,
V_119 , & V_113 ) &&
! ( V_113 . V_120 == V_121 &&
V_113 . V_92 == 0x03A ) &&
F_1 ( V_122 ) )
F_47 ( V_91 -> V_18 , L_1 ,
& V_113 ) ;
}
if ( V_89 -> V_95 != V_123 )
F_38 ( V_89 , V_91 , V_9 , V_113 . V_92 ,
V_113 . V_93 ) ;
F_48 ( V_91 ,
V_109 -> V_115 -> V_124 . V_125 -
V_89 -> V_126 ) ;
V_91 -> V_127 ( V_91 ) ;
if ( V_114 >
sizeof( struct V_128 ) )
F_7 ( V_115 ) ;
}
static void F_49 ( struct V_16 * V_19 ,
struct V_40 * V_40 ,
struct V_38 * V_39 )
{
struct V_40 * V_129 ;
struct V_17 * V_18 = V_19 -> V_18 ;
V_129 = & V_39 -> V_40 ;
if ( ( V_129 -> V_89 . V_130 [ 0 ] == V_131 ) ||
( V_129 -> V_89 . V_130 [ 0 ] == V_132 ) ) {
V_40 -> V_89 . V_117 = 0 ;
V_40 -> V_89 . V_95 = V_123 ;
}
V_129 -> V_89 . V_117 = V_40 -> V_89 . V_117 ;
V_129 -> V_89 . V_95 = V_40 -> V_89 . V_95 ;
V_129 -> V_89 . V_133 =
V_40 -> V_89 . V_133 ;
if ( V_40 -> V_89 . V_117 != 0 ||
V_40 -> V_89 . V_95 != V_123 )
F_50 ( V_18 , V_134 ,
L_2 ,
V_129 -> V_89 . V_130 [ 0 ] ,
V_40 -> V_89 . V_117 ,
V_40 -> V_89 . V_95 ) ;
if ( ( V_40 -> V_89 . V_117 & 0xFF ) == 0x02 ) {
if ( V_40 -> V_89 . V_95 &
V_105 ) {
F_50 ( V_18 , V_134 ,
L_3 ,
V_39 , V_40 -> V_89 . V_133 ) ;
memcpy ( V_39 -> V_111 -> V_118 ,
V_40 -> V_89 . V_135 ,
V_40 -> V_89 . V_133 ) ;
}
}
V_129 -> V_89 . V_126 =
V_40 -> V_89 . V_126 ;
F_45 ( V_39 , V_19 ) ;
if ( F_51 ( & V_19 -> V_24 ) &&
V_19 -> V_22 )
F_52 ( & V_19 -> V_23 ) ;
}
static void F_53 ( struct V_16 * V_19 ,
struct V_40 * V_40 ,
struct V_38 * V_39 )
{
struct V_5 * V_4 ;
switch ( V_40 -> V_45 ) {
case V_54 :
F_49 ( V_19 , V_40 , V_39 ) ;
break;
case V_136 :
case V_137 :
V_4 = F_42 ( sizeof( struct V_5 ) , V_107 ) ;
if ( ! V_4 )
return;
F_43 ( & V_4 -> V_4 , F_8 ) ;
V_4 -> V_9 = V_19 -> V_9 ;
F_44 ( & V_4 -> V_4 ) ;
break;
case V_86 :
F_33 ( V_19 , V_40 ) ;
#if F_54 ( V_138 )
F_55 ( V_19 -> V_9 ) = V_19 -> V_58 ;
F_56 ( V_19 -> V_9 ) = V_19 -> V_60 ;
#endif
break;
default:
break;
}
}
static void V_34 ( void * V_139 )
{
struct V_26 * V_44 = (struct V_26 * ) V_139 ;
struct V_17 * V_18 ;
struct V_16 * V_19 ;
T_2 V_140 ;
T_3 V_141 ;
unsigned char V_142 [ F_57 ( sizeof( struct V_40 ) , 8 ) ] ;
struct V_38 * V_39 ;
int V_41 ;
if ( V_44 -> V_28 != NULL )
V_18 = V_44 -> V_28 -> V_29 ;
else
V_18 = V_44 -> V_29 ;
V_19 = F_23 ( V_18 ) ;
if ( ! V_19 )
return;
do {
V_41 = F_58 ( V_44 , V_142 ,
F_57 ( ( sizeof( struct V_40 ) -
V_50 ) , 8 ) ,
& V_140 , & V_141 ) ;
if ( V_41 == 0 && V_140 > 0 ) {
V_39 = (struct V_38 * )
( unsigned long ) V_141 ;
if ( ( V_39 == & V_19 -> V_43 ) ||
( V_39 == & V_19 -> V_143 ) ) {
memcpy ( & V_39 -> V_40 , V_142 ,
( sizeof( struct V_40 ) -
V_50 ) ) ;
F_59 ( & V_39 -> F_21 ) ;
} else {
F_53 ( V_19 ,
(struct V_40 * ) V_142 ,
V_39 ) ;
}
} else {
break;
}
} while ( 1 );
return;
}
static int F_60 ( struct V_17 * V_18 , T_2 V_144 ,
bool V_67 )
{
struct V_30 V_31 ;
int V_41 ;
memset ( & V_31 , 0 , sizeof( struct V_30 ) ) ;
V_41 = F_25 ( V_18 -> V_44 ,
V_144 ,
V_144 ,
( void * ) & V_31 ,
sizeof( struct V_30 ) ,
V_34 , V_18 -> V_44 ) ;
if ( V_41 != 0 )
return V_41 ;
V_41 = F_36 ( V_18 , V_67 ) ;
return V_41 ;
}
static int F_61 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
unsigned long V_47 ;
V_19 = F_19 ( V_18 ) ;
F_62 ( & V_18 -> V_44 -> V_145 , V_47 ) ;
V_19 -> V_20 = true ;
F_63 ( & V_18 -> V_44 -> V_145 , V_47 ) ;
F_20 ( V_19 ) ;
F_62 ( & V_18 -> V_44 -> V_145 , V_47 ) ;
F_64 ( V_18 , NULL ) ;
F_63 ( & V_18 -> V_44 -> V_145 , V_47 ) ;
F_65 ( V_18 -> V_44 ) ;
F_7 ( V_19 ) ;
return 0 ;
}
static int F_66 ( struct V_17 * V_18 ,
struct V_38 * V_39 )
{
struct V_16 * V_19 ;
struct V_40 * V_40 ;
struct V_26 * V_146 ;
int V_41 = 0 ;
V_40 = & V_39 -> V_40 ;
V_19 = F_18 ( V_18 ) ;
if ( ! V_19 )
return - V_70 ;
V_39 -> V_18 = V_18 ;
V_146 = F_67 ( V_18 -> V_44 ) ;
V_40 -> V_47 |= V_48 ;
V_40 -> V_89 . V_147 = ( sizeof( struct V_88 ) -
V_50 ) ;
V_40 -> V_89 . V_133 = V_79 ;
V_40 -> V_89 . V_126 =
V_39 -> V_115 -> V_124 . V_125 ;
V_40 -> V_45 = V_148 ;
if ( V_39 -> V_115 -> V_124 . V_125 ) {
V_41 = F_68 ( V_146 ,
V_39 -> V_115 , V_39 -> V_114 ,
V_40 ,
( sizeof( struct V_40 ) -
V_50 ) ,
( unsigned long ) V_39 ) ;
} else {
V_41 = F_31 ( V_146 , V_40 ,
( sizeof( struct V_40 ) -
V_50 ) ,
( unsigned long ) V_39 ,
V_51 ,
V_52 ) ;
}
if ( V_41 != 0 )
return V_41 ;
F_69 ( & V_19 -> V_24 ) ;
return V_41 ;
}
static int F_70 ( struct V_7 * V_149 )
{
F_71 ( V_149 -> V_150 , V_151 ) ;
F_72 ( V_149 -> V_150 , V_152 ) ;
F_73 ( V_149 -> V_150 , ( V_153 * V_53 ) ) ;
F_74 ( V_149 -> V_150 , V_151 - 1 ) ;
V_149 -> V_154 = 1 ;
V_149 -> V_155 |= V_156 ;
if ( ! strncmp ( V_149 -> V_157 , L_4 , 4 ) ) {
switch ( V_78 ) {
case V_83 :
case V_158 :
V_149 -> V_159 = V_160 ;
break;
}
if ( V_78 >= V_161 )
V_149 -> V_154 = 0 ;
}
return 0 ;
}
static int F_75 ( struct V_7 * V_8 , struct V_162 * V_163 ,
T_4 V_164 , int * V_165 )
{
T_4 V_166 = V_164 ;
T_4 V_167 = V_166 ;
int V_168 , V_169 ;
V_168 = 0xff ;
V_169 = 0x3f ;
F_76 ( V_167 , V_168 * V_169 ) ;
if ( ( T_4 ) ( V_167 + 1 ) * V_168 * V_169 < V_166 )
V_167 = 0xffff ;
V_165 [ 0 ] = V_168 ;
V_165 [ 1 ] = V_169 ;
V_165 [ 2 ] = ( int ) V_167 ;
return 0 ;
}
static int F_77 ( struct V_90 * V_91 )
{
struct V_170 * V_171 = F_78 ( V_91 -> V_18 -> V_9 ) ;
struct V_17 * V_18 = V_171 -> V_21 ;
struct V_16 * V_19 ;
struct V_38 * V_39 ;
struct V_40 * V_40 ;
int V_41 , V_42 ;
V_19 = F_18 ( V_18 ) ;
if ( ! V_19 )
return V_172 ;
V_39 = & V_19 -> V_143 ;
V_40 = & V_39 -> V_40 ;
F_30 ( & V_39 -> F_21 ) ;
V_40 -> V_45 = V_173 ;
V_40 -> V_47 = V_48 ;
V_40 -> V_89 . V_174 = V_19 -> V_174 ;
V_41 = F_31 ( V_18 -> V_44 , V_40 ,
( sizeof( struct V_40 ) -
V_50 ) ,
( unsigned long ) & V_19 -> V_143 ,
V_51 ,
V_52 ) ;
if ( V_41 != 0 )
return V_172 ;
V_42 = F_32 ( & V_39 -> F_21 , 5 * V_53 ) ;
if ( V_42 == 0 )
return V_175 ;
F_20 ( V_19 ) ;
return V_176 ;
}
static enum V_177 F_79 ( struct V_90 * V_91 )
{
return V_178 ;
}
static bool F_80 ( struct V_90 * V_91 )
{
bool V_179 = true ;
T_1 V_180 = V_91 -> V_97 [ 0 ] ;
switch ( V_180 ) {
case V_181 :
case V_182 :
V_91 -> V_116 = V_183 << 16 ;
V_179 = false ;
break;
default:
break;
}
return V_179 ;
}
static int F_81 ( struct V_14 * V_9 , struct V_90 * V_91 )
{
int V_41 ;
struct V_170 * V_171 = F_78 ( V_9 ) ;
struct V_17 * V_21 = V_171 -> V_21 ;
struct V_38 * V_109 = F_82 ( V_91 ) ;
int V_68 ;
struct V_184 * V_185 ;
unsigned int V_186 = 0 ;
struct V_88 * V_89 ;
struct V_184 * V_187 ;
struct V_188 * V_115 ;
T_2 V_114 ;
T_2 V_147 ;
if ( V_78 <= V_83 ) {
if ( ! F_80 ( V_91 ) ) {
V_91 -> V_127 ( V_91 ) ;
return 0 ;
}
}
V_109 -> V_111 = V_91 ;
V_89 = & V_109 -> V_40 . V_89 ;
V_89 -> V_189 . V_190 = 60 ;
V_89 -> V_189 . V_191 |=
V_192 ;
switch ( V_91 -> V_193 ) {
case V_194 :
V_89 -> V_195 = V_196 ;
V_89 -> V_189 . V_191 |= V_197 ;
break;
case V_198 :
V_89 -> V_195 = V_199 ;
V_89 -> V_189 . V_191 |= V_200 ;
break;
case V_201 :
V_89 -> V_195 = V_202 ;
V_89 -> V_189 . V_191 |= V_203 ;
break;
default:
F_83 ( 1 , L_5 ,
V_91 -> V_193 ) ;
return - V_66 ;
}
V_89 -> V_204 = V_171 -> V_205 ;
V_89 -> V_174 = V_91 -> V_18 -> V_44 ;
V_89 -> V_108 = V_91 -> V_18 -> V_206 ;
V_89 -> V_11 = V_91 -> V_18 -> V_11 ;
V_89 -> V_207 = V_91 -> V_208 ;
memcpy ( V_89 -> V_130 , V_91 -> V_97 , V_89 -> V_207 ) ;
V_185 = (struct V_184 * ) F_84 ( V_91 ) ;
V_186 = F_85 ( V_91 ) ;
V_147 = F_86 ( V_91 ) ;
V_115 = (struct V_188 * ) & V_109 -> V_209 ;
V_114 = sizeof( V_109 -> V_209 ) ;
if ( V_186 ) {
if ( V_186 > V_210 ) {
V_114 = ( V_186 * sizeof( void * ) +
sizeof( struct V_188 ) ) ;
V_115 = F_42 ( V_114 , V_107 ) ;
if ( ! V_115 )
return V_211 ;
}
V_115 -> V_124 . V_125 = V_147 ;
V_115 -> V_124 . V_212 = V_185 [ 0 ] . V_212 ;
V_187 = V_185 ;
for ( V_68 = 0 ; V_68 < V_186 ; V_68 ++ ) {
V_115 -> V_124 . V_213 [ V_68 ] =
F_87 ( F_88 ( ( V_187 ) ) ) ;
V_187 = F_89 ( V_187 ) ;
}
} else if ( F_84 ( V_91 ) ) {
V_115 -> V_124 . V_125 = V_147 ;
V_115 -> V_124 . V_212 =
F_90 ( F_84 ( V_91 ) ) & ( V_151 - 1 ) ;
V_115 -> V_124 . V_213 [ 0 ] =
F_90 ( F_84 ( V_91 ) ) >> V_214 ;
}
V_109 -> V_115 = V_115 ;
V_109 -> V_114 = V_114 ;
V_41 = F_66 ( V_21 , V_109 ) ;
if ( V_41 == - V_215 ) {
return V_211 ;
}
return 0 ;
}
static int F_91 ( struct V_17 * V_18 ,
const struct V_216 * V_217 )
{
int V_41 ;
int V_36 = F_27 () ;
struct V_14 * V_9 ;
struct V_170 * V_171 ;
bool V_218 = ( ( V_217 -> V_219 == V_220 ) ? true : false ) ;
bool V_67 = ( ( V_217 -> V_219 == V_221 ) ? true : false ) ;
int V_222 = 0 ;
struct V_16 * V_19 ;
int V_223 ;
int V_224 ;
int V_225 ;
int V_226 = 0 ;
if ( V_227 < V_228 ) {
V_223 = V_229 ;
V_224 = V_230 ;
V_225 = V_231 ;
} else {
V_223 = V_232 ;
V_224 = V_233 ;
V_225 = V_234 ;
V_226 = ( V_36 / V_235 ) ;
}
V_236 . V_237 = ( V_238 *
( V_226 + 1 ) ) ;
V_9 = F_92 ( & V_236 ,
sizeof( struct V_170 ) ) ;
if ( ! V_9 )
return - V_239 ;
V_171 = F_78 ( V_9 ) ;
memset ( V_171 , 0 , sizeof( struct V_170 ) ) ;
V_171 -> V_205 = V_9 -> V_240 ;
V_171 -> V_21 = V_18 ;
V_19 = F_93 ( sizeof( struct V_16 ) , V_241 ) ;
if ( ! V_19 ) {
V_41 = - V_239 ;
goto V_242;
}
V_19 -> V_20 = false ;
V_19 -> V_32 = false ;
F_94 ( & V_19 -> V_23 ) ;
V_19 -> V_18 = V_18 ;
V_19 -> V_9 = V_9 ;
F_64 ( V_18 , V_19 ) ;
V_19 -> V_204 = V_9 -> V_240 ;
V_41 = F_60 ( V_18 , V_33 , V_67 ) ;
if ( V_41 )
goto V_243;
V_171 -> V_244 = V_19 -> V_174 ;
V_171 -> V_222 = V_19 -> V_108 ;
switch ( V_217 -> V_219 ) {
case V_221 :
V_9 -> V_245 = V_246 ;
V_9 -> V_247 = V_248 ;
V_9 -> V_249 = V_250 - 1 ;
#if F_54 ( V_138 )
V_9 -> V_251 = V_252 ;
#endif
break;
case V_253 :
V_9 -> V_245 = V_223 ;
V_9 -> V_247 = V_224 ;
V_9 -> V_249 = V_225 - 1 ;
break;
default:
V_9 -> V_245 = V_229 ;
V_9 -> V_247 = V_230 ;
V_9 -> V_249 = V_231 - 1 ;
break;
}
V_9 -> V_254 = V_255 ;
V_9 -> V_256 = ( V_19 -> V_85 >> V_214 ) ;
V_41 = F_95 ( V_9 , & V_18 -> V_18 ) ;
if ( V_41 != 0 )
goto V_257;
if ( ! V_218 ) {
F_13 ( V_9 ) ;
} else {
V_222 = ( V_18 -> V_258 . V_259 [ 5 ] << 8 |
V_18 -> V_258 . V_259 [ 4 ] ) ;
V_41 = F_96 ( V_9 , 0 , V_222 , 0 ) ;
if ( V_41 ) {
F_97 ( V_9 ) ;
goto V_257;
}
}
#if F_54 ( V_138 )
if ( V_9 -> V_251 == V_252 ) {
F_55 ( V_9 ) = V_19 -> V_58 ;
F_56 ( V_9 ) = V_19 -> V_60 ;
}
#endif
return 0 ;
V_257:
F_61 ( V_18 ) ;
goto V_242;
V_243:
F_7 ( V_19 ) ;
V_242:
F_17 ( V_9 ) ;
return V_41 ;
}
static int F_98 ( struct V_17 * V_21 )
{
struct V_16 * V_19 = F_19 ( V_21 ) ;
struct V_14 * V_9 = V_19 -> V_9 ;
#if F_54 ( V_138 )
if ( V_9 -> V_251 == V_252 )
F_99 ( V_9 ) ;
#endif
F_97 ( V_9 ) ;
F_61 ( V_21 ) ;
F_17 ( V_9 ) ;
return 0 ;
}
static int T_5 F_100 ( void )
{
int V_41 ;
V_238 =
( ( V_33 - V_151 ) /
F_57 ( V_260 +
sizeof( struct V_40 ) + sizeof( T_3 ) -
V_50 ,
sizeof( T_3 ) ) ) ;
#if F_54 ( V_138 )
V_252 = F_101 ( & V_261 ) ;
if ( ! V_252 )
return - V_70 ;
V_252 -> V_262 = F_79 ;
#endif
V_41 = F_102 ( & V_263 ) ;
#if F_54 ( V_138 )
if ( V_41 )
F_103 ( V_252 ) ;
#endif
return V_41 ;
}
static void T_6 F_104 ( void )
{
F_105 ( & V_263 ) ;
#if F_54 ( V_138 )
F_103 ( V_252 ) ;
#endif
}
