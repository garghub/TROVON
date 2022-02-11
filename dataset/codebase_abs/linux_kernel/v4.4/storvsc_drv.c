static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
struct V_6 * V_7 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_5 = V_4 -> V_5 ;
V_7 = F_3 ( V_4 -> V_8 , 0 , 0 , V_5 ) ;
if ( ! V_7 )
goto V_9;
F_4 ( & V_7 -> V_10 ) ;
F_5 ( V_7 ) ;
V_9:
F_6 ( V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_11 * V_8 ;
struct V_6 * V_7 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_8 = V_4 -> V_8 ;
F_8 ( & V_8 -> V_12 ) ;
F_9 (sdev, host)
F_10 ( V_7 , 1 , 1 , NULL ) ;
F_11 ( & V_8 -> V_12 ) ;
F_12 ( V_8 ) ;
F_6 ( V_4 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( ! F_14 ( V_4 -> V_8 ) )
goto V_9;
V_7 = F_3 ( V_4 -> V_8 , 0 , 0 , V_4 -> V_5 ) ;
if ( V_7 ) {
F_15 ( V_7 ) ;
F_5 ( V_7 ) ;
}
F_16 ( V_4 -> V_8 ) ;
V_9:
F_6 ( V_4 ) ;
}
static inline struct V_13 * F_17 (
struct V_14 * V_15 )
{
struct V_13 * V_16 ;
V_16 = F_18 ( V_15 ) ;
if ( V_16 && V_16 -> V_17 )
V_16 = NULL ;
return V_16 ;
}
static inline void F_19 ( struct V_13 * V_18 )
{
V_18 -> V_19 = true ;
F_20 ( V_18 -> V_20 ,
F_21 ( & V_18 -> V_21 ) == 0 ) ;
V_18 -> V_19 = false ;
}
static inline struct V_13 * F_22 (
struct V_14 * V_15 )
{
struct V_13 * V_16 ;
V_16 = F_18 ( V_15 ) ;
if ( ! V_16 )
goto V_22;
if ( V_16 -> V_17 &&
( F_21 ( & V_16 -> V_21 ) == 0 ) )
V_16 = NULL ;
V_22:
return V_16 ;
}
static void F_23 ( struct V_23 * V_24 )
{
struct V_14 * V_15 = V_24 -> V_25 -> V_26 ;
struct V_13 * V_16 ;
struct V_27 V_28 ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 )
return;
if ( V_16 -> V_29 == false )
return;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
F_24 ( V_24 ,
V_30 ,
V_30 ,
( void * ) & V_28 ,
sizeof( struct V_27 ) ,
V_31 , V_24 ) ;
}
static void F_25 ( struct V_14 * V_15 , int V_32 )
{
struct V_13 * V_16 ;
int V_33 = F_26 () ;
int V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_37 ;
int V_38 , V_39 ;
V_34 = ( ( V_32 > V_33 ) ? V_33 : V_32 ) ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 )
return;
V_36 = & V_16 -> V_40 ;
V_37 = & V_36 -> V_37 ;
V_16 -> V_29 = true ;
F_27 ( V_15 -> V_41 , F_23 ) ;
if ( F_28 ( V_15 -> V_41 ) )
return;
V_16 -> V_29 = false ;
memset ( V_36 , 0 , sizeof( struct V_35 ) ) ;
F_29 ( & V_36 -> F_20 ) ;
V_37 -> V_42 = V_43 ;
V_37 -> V_44 = V_45 ;
V_37 -> V_46 = V_34 ;
V_38 = F_30 ( V_15 -> V_41 , V_37 ,
( sizeof( struct V_37 ) -
V_47 ) ,
( unsigned long ) V_36 ,
V_48 ,
V_49 ) ;
if ( V_38 != 0 )
return;
V_39 = F_31 ( & V_36 -> F_20 , 10 * V_50 ) ;
if ( V_39 == 0 )
return;
if ( V_37 -> V_42 != V_51 ||
V_37 -> V_52 != 0 )
return;
V_16 -> V_29 = true ;
F_28 ( V_15 -> V_41 ) ;
}
static int F_32 ( struct V_14 * V_15 )
{
struct V_13 * V_16 ;
struct V_35 * V_36 ;
struct V_37 * V_37 ;
int V_38 , V_39 , V_53 ;
int V_32 ;
bool V_54 = false ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 )
return - V_55 ;
V_36 = & V_16 -> V_40 ;
V_37 = & V_36 -> V_37 ;
memset ( V_36 , 0 , sizeof( struct V_35 ) ) ;
F_29 ( & V_36 -> F_20 ) ;
V_37 -> V_42 = V_56 ;
V_37 -> V_44 = V_45 ;
V_38 = F_30 ( V_15 -> V_41 , V_37 ,
( sizeof( struct V_37 ) -
V_47 ) ,
( unsigned long ) V_36 ,
V_48 ,
V_49 ) ;
if ( V_38 != 0 )
goto V_57;
V_39 = F_31 ( & V_36 -> F_20 , 5 * V_50 ) ;
if ( V_39 == 0 ) {
V_38 = - V_58 ;
goto V_57;
}
if ( V_37 -> V_42 != V_51 ||
V_37 -> V_52 != 0 ) {
V_38 = - V_59 ;
goto V_57;
}
for ( V_53 = 0 ; V_53 < F_33 ( V_60 ) ; V_53 ++ ) {
memset ( V_37 , 0 , sizeof( struct V_37 ) ) ;
V_37 -> V_42 =
V_61 ;
V_37 -> V_44 = V_45 ;
V_37 -> V_62 . V_63 =
V_60 [ V_53 ] . V_64 ;
V_37 -> V_62 . V_65 = 0 ;
V_38 = F_30 ( V_15 -> V_41 , V_37 ,
( sizeof( struct V_37 ) -
V_47 ) ,
( unsigned long ) V_36 ,
V_48 ,
V_49 ) ;
if ( V_38 != 0 )
goto V_57;
V_39 = F_31 ( & V_36 -> F_20 , 5 * V_50 ) ;
if ( V_39 == 0 ) {
V_38 = - V_58 ;
goto V_57;
}
if ( V_37 -> V_42 != V_51 ) {
V_38 = - V_59 ;
goto V_57;
}
if ( V_37 -> V_52 == 0 ) {
V_66 =
V_60 [ V_53 ] . V_64 ;
V_67 =
V_60 [ V_53 ] . V_67 ;
V_47 =
V_60 [ V_53 ] . V_47 ;
break;
}
}
if ( V_37 -> V_52 != 0 ) {
V_38 = - V_59 ;
goto V_57;
}
memset ( V_37 , 0 , sizeof( struct V_37 ) ) ;
V_37 -> V_42 = V_68 ;
V_37 -> V_44 = V_45 ;
V_38 = F_30 ( V_15 -> V_41 , V_37 ,
( sizeof( struct V_37 ) -
V_47 ) ,
( unsigned long ) V_36 ,
V_48 ,
V_49 ) ;
if ( V_38 != 0 )
goto V_57;
V_39 = F_31 ( & V_36 -> F_20 , 5 * V_50 ) ;
if ( V_39 == 0 ) {
V_38 = - V_58 ;
goto V_57;
}
if ( V_37 -> V_42 != V_51 ||
V_37 -> V_52 != 0 ) {
V_38 = - V_59 ;
goto V_57;
}
V_32 = V_37 -> V_69 . V_70 ;
if ( V_66 >= V_71 ) {
if ( V_37 -> V_69 . V_44 &
V_72 )
V_54 = true ;
}
V_16 -> V_73 =
V_37 -> V_69 . V_73 ;
memset ( V_37 , 0 , sizeof( struct V_37 ) ) ;
V_37 -> V_42 = V_74 ;
V_37 -> V_44 = V_45 ;
V_38 = F_30 ( V_15 -> V_41 , V_37 ,
( sizeof( struct V_37 ) -
V_47 ) ,
( unsigned long ) V_36 ,
V_48 ,
V_49 ) ;
if ( V_38 != 0 )
goto V_57;
V_39 = F_31 ( & V_36 -> F_20 , 5 * V_50 ) ;
if ( V_39 == 0 ) {
V_38 = - V_58 ;
goto V_57;
}
if ( V_37 -> V_42 != V_51 ||
V_37 -> V_52 != 0 ) {
V_38 = - V_59 ;
goto V_57;
}
if ( V_54 )
F_25 ( V_15 , V_32 ) ;
V_57:
return V_38 ;
}
static void F_34 ( struct V_75 * V_76 ,
struct V_77 * V_78 ,
struct V_11 * V_8 ,
T_2 V_79 , T_2 V_80 )
{
struct V_3 * V_4 ;
void (* F_35)( struct V_1 * V_2 );
bool V_81 = false ;
switch ( F_36 ( V_76 -> V_82 ) ) {
case V_83 :
switch ( V_78 -> V_84 [ 0 ] ) {
case V_85 :
case V_86 :
F_37 ( V_78 , V_87 ) ;
break;
case V_88 :
break;
default:
F_37 ( V_78 , V_89 ) ;
}
break;
case V_90 :
V_81 = true ;
F_35 = F_13 ;
break;
case ( V_91 | V_92 ) :
if ( ( V_79 == 0x2a ) && ( V_80 == 0x9 ) ) {
V_81 = true ;
F_35 = F_1 ;
F_37 ( V_78 , V_93 ) ;
}
break;
}
if ( ! V_81 )
return;
V_4 = F_38 ( sizeof( struct V_3 ) , V_94 ) ;
if ( ! V_4 ) {
F_37 ( V_78 , V_89 ) ;
return;
}
V_4 -> V_8 = V_8 ;
V_4 -> V_5 = V_76 -> V_5 ;
F_39 ( & V_4 -> V_2 , F_35 ) ;
F_40 ( & V_4 -> V_2 ) ;
}
static void F_41 ( struct V_35 * V_95 )
{
struct V_77 * V_78 = V_95 -> V_96 ;
struct V_97 * V_98 = F_42 ( V_78 -> V_15 -> V_8 ) ;
struct V_99 V_100 ;
struct V_75 * V_76 ;
struct V_11 * V_8 ;
struct V_13 * V_101 ;
struct V_14 * V_18 = V_98 -> V_18 ;
T_3 V_102 = V_95 -> V_102 ;
void * V_103 = V_95 -> V_103 ;
V_101 = F_22 ( V_18 ) ;
V_8 = V_101 -> V_8 ;
V_76 = & V_95 -> V_37 . V_76 ;
V_78 -> V_104 = V_76 -> V_105 ;
if ( V_78 -> V_104 ) {
if ( F_43 ( V_78 -> V_106 ,
V_107 , & V_100 ) )
F_44 ( V_78 -> V_15 , L_1 ,
& V_100 ) ;
}
if ( V_76 -> V_82 != V_108 )
F_34 ( V_76 , V_78 , V_8 , V_100 . V_79 ,
V_100 . V_80 ) ;
F_45 ( V_78 ,
V_95 -> V_103 -> V_109 . V_110 -
V_76 -> V_111 ) ;
V_78 -> V_112 ( V_78 ) ;
if ( V_102 >
sizeof( struct V_113 ) )
F_6 ( V_103 ) ;
}
static void F_46 ( struct V_14 * V_15 ,
struct V_37 * V_37 ,
struct V_35 * V_36 )
{
struct V_13 * V_16 ;
struct V_37 * V_114 ;
V_16 = F_18 ( V_15 ) ;
V_114 = & V_36 -> V_37 ;
if ( ( V_114 -> V_76 . V_115 [ 0 ] == V_116 ) ||
( V_114 -> V_76 . V_115 [ 0 ] == V_117 ) ) {
V_37 -> V_76 . V_105 = 0 ;
V_37 -> V_76 . V_82 = V_108 ;
}
V_114 -> V_76 . V_105 = V_37 -> V_76 . V_105 ;
V_114 -> V_76 . V_82 = V_37 -> V_76 . V_82 ;
V_114 -> V_76 . V_118 =
V_37 -> V_76 . V_118 ;
if ( ( V_37 -> V_76 . V_105 & 0xFF ) == 0x02 ) {
if ( V_37 -> V_76 . V_82 &
V_92 ) {
memcpy ( V_36 -> V_96 -> V_106 ,
V_37 -> V_76 . V_119 ,
V_37 -> V_76 . V_118 ) ;
}
}
V_114 -> V_76 . V_111 =
V_37 -> V_76 . V_111 ;
F_41 ( V_36 ) ;
if ( F_47 ( & V_16 -> V_21 ) &&
V_16 -> V_19 )
F_48 ( & V_16 -> V_20 ) ;
}
static void F_49 ( struct V_14 * V_15 ,
struct V_37 * V_37 ,
struct V_35 * V_36 )
{
struct V_3 * V_2 ;
struct V_13 * V_16 ;
switch ( V_37 -> V_42 ) {
case V_51 :
F_46 ( V_15 , V_37 , V_36 ) ;
break;
case V_120 :
case V_121 :
V_16 = F_22 ( V_15 ) ;
V_2 = F_38 ( sizeof( struct V_3 ) , V_94 ) ;
if ( ! V_2 )
return;
F_39 ( & V_2 -> V_2 , F_7 ) ;
V_2 -> V_8 = V_16 -> V_8 ;
F_40 ( & V_2 -> V_2 ) ;
break;
default:
break;
}
}
static void V_31 ( void * V_122 )
{
struct V_23 * V_41 = (struct V_23 * ) V_122 ;
struct V_14 * V_15 ;
struct V_13 * V_16 ;
T_3 V_123 ;
T_4 V_124 ;
unsigned char V_125 [ F_50 ( sizeof( struct V_37 ) , 8 ) ] ;
struct V_35 * V_36 ;
int V_38 ;
if ( V_41 -> V_25 != NULL )
V_15 = V_41 -> V_25 -> V_26 ;
else
V_15 = V_41 -> V_26 ;
V_16 = F_22 ( V_15 ) ;
if ( ! V_16 )
return;
do {
V_38 = F_51 ( V_41 , V_125 ,
F_50 ( ( sizeof( struct V_37 ) -
V_47 ) , 8 ) ,
& V_123 , & V_124 ) ;
if ( V_38 == 0 && V_123 > 0 ) {
V_36 = (struct V_35 * )
( unsigned long ) V_124 ;
if ( ( V_36 == & V_16 -> V_40 ) ||
( V_36 == & V_16 -> V_126 ) ) {
memcpy ( & V_36 -> V_37 , V_125 ,
( sizeof( struct V_37 ) -
V_47 ) ) ;
F_52 ( & V_36 -> F_20 ) ;
} else {
F_49 ( V_15 ,
(struct V_37 * ) V_125 ,
V_36 ) ;
}
} else {
break;
}
} while ( 1 );
return;
}
static int F_53 ( struct V_14 * V_15 , T_3 V_127 )
{
struct V_27 V_28 ;
int V_38 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_38 = F_24 ( V_15 -> V_41 ,
V_127 ,
V_127 ,
( void * ) & V_28 ,
sizeof( struct V_27 ) ,
V_31 , V_15 -> V_41 ) ;
if ( V_38 != 0 )
return V_38 ;
V_38 = F_32 ( V_15 ) ;
return V_38 ;
}
static int F_54 ( struct V_14 * V_15 )
{
struct V_13 * V_16 ;
unsigned long V_44 ;
V_16 = F_18 ( V_15 ) ;
F_55 ( & V_15 -> V_41 -> V_128 , V_44 ) ;
V_16 -> V_17 = true ;
F_56 ( & V_15 -> V_41 -> V_128 , V_44 ) ;
F_19 ( V_16 ) ;
F_55 ( & V_15 -> V_41 -> V_128 , V_44 ) ;
F_57 ( V_15 , NULL ) ;
F_56 ( & V_15 -> V_41 -> V_128 , V_44 ) ;
F_58 ( V_15 -> V_41 ) ;
F_6 ( V_16 ) ;
return 0 ;
}
static int F_59 ( struct V_14 * V_15 ,
struct V_35 * V_36 )
{
struct V_13 * V_16 ;
struct V_37 * V_37 ;
struct V_23 * V_129 ;
int V_38 = 0 ;
V_37 = & V_36 -> V_37 ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 )
return - V_55 ;
V_36 -> V_15 = V_15 ;
V_129 = F_60 ( V_15 -> V_41 ) ;
V_37 -> V_44 |= V_45 ;
V_37 -> V_76 . V_130 = ( sizeof( struct V_75 ) -
V_47 ) ;
V_37 -> V_76 . V_118 = V_67 ;
V_37 -> V_76 . V_111 =
V_36 -> V_103 -> V_109 . V_110 ;
V_37 -> V_42 = V_131 ;
if ( V_36 -> V_103 -> V_109 . V_110 ) {
V_38 = F_61 ( V_129 ,
V_36 -> V_103 , V_36 -> V_102 ,
V_37 ,
( sizeof( struct V_37 ) -
V_47 ) ,
( unsigned long ) V_36 ) ;
} else {
V_38 = F_30 ( V_129 , V_37 ,
( sizeof( struct V_37 ) -
V_47 ) ,
( unsigned long ) V_36 ,
V_48 ,
V_49 ) ;
}
if ( V_38 != 0 )
return V_38 ;
F_62 ( & V_16 -> V_21 ) ;
return V_38 ;
}
static int F_63 ( struct V_6 * V_132 )
{
F_64 ( V_132 -> V_133 , V_134 ) ;
F_65 ( V_132 -> V_133 , V_135 ) ;
F_66 ( V_132 -> V_133 , ( V_136 * V_50 ) ) ;
F_67 ( V_132 -> V_133 , V_134 - 1 ) ;
V_132 -> V_137 = 1 ;
V_132 -> V_138 |= V_139 ;
if ( ! strncmp ( V_132 -> V_140 , L_2 , 4 ) ) {
switch ( V_66 ) {
case V_71 :
case V_141 :
V_132 -> V_142 = V_143 ;
break;
}
if ( V_66 >= V_144 )
V_132 -> V_137 = 0 ;
}
return 0 ;
}
static int F_68 ( struct V_6 * V_7 , struct V_145 * V_146 ,
T_5 V_147 , int * V_148 )
{
T_5 V_149 = V_147 ;
T_5 V_150 = V_149 ;
int V_151 , V_152 ;
V_151 = 0xff ;
V_152 = 0x3f ;
F_69 ( V_150 , V_151 * V_152 ) ;
if ( ( T_5 ) ( V_150 + 1 ) * V_151 * V_152 < V_149 )
V_150 = 0xffff ;
V_148 [ 0 ] = V_151 ;
V_148 [ 1 ] = V_152 ;
V_148 [ 2 ] = ( int ) V_150 ;
return 0 ;
}
static int F_70 ( struct V_77 * V_78 )
{
struct V_97 * V_98 = F_42 ( V_78 -> V_15 -> V_8 ) ;
struct V_14 * V_15 = V_98 -> V_18 ;
struct V_13 * V_16 ;
struct V_35 * V_36 ;
struct V_37 * V_37 ;
int V_38 , V_39 ;
V_16 = F_17 ( V_15 ) ;
if ( ! V_16 )
return V_153 ;
V_36 = & V_16 -> V_126 ;
V_37 = & V_36 -> V_37 ;
F_29 ( & V_36 -> F_20 ) ;
V_37 -> V_42 = V_154 ;
V_37 -> V_44 = V_45 ;
V_37 -> V_76 . V_155 = V_16 -> V_155 ;
V_38 = F_30 ( V_15 -> V_41 , V_37 ,
( sizeof( struct V_37 ) -
V_47 ) ,
( unsigned long ) & V_16 -> V_126 ,
V_48 ,
V_49 ) ;
if ( V_38 != 0 )
return V_153 ;
V_39 = F_31 ( & V_36 -> F_20 , 5 * V_50 ) ;
if ( V_39 == 0 )
return V_156 ;
F_19 ( V_16 ) ;
return V_157 ;
}
static enum V_158 F_71 ( struct V_77 * V_78 )
{
return V_159 ;
}
static bool F_72 ( struct V_77 * V_78 )
{
bool V_160 = true ;
T_2 V_161 = V_78 -> V_84 [ 0 ] ;
switch ( V_161 ) {
case V_162 :
case V_163 :
V_78 -> V_104 = V_164 << 16 ;
V_160 = false ;
break;
default:
break;
}
return V_160 ;
}
static int F_73 ( struct V_11 * V_8 , struct V_77 * V_78 )
{
int V_38 ;
struct V_97 * V_98 = F_42 ( V_8 ) ;
struct V_14 * V_18 = V_98 -> V_18 ;
struct V_35 * V_95 = F_74 ( V_78 ) ;
int V_53 ;
struct V_165 * V_166 ;
unsigned int V_167 = 0 ;
struct V_75 * V_76 ;
struct V_165 * V_168 ;
struct V_169 * V_103 ;
T_3 V_102 ;
T_3 V_130 ;
if ( V_66 <= V_71 ) {
if ( ! F_72 ( V_78 ) ) {
V_78 -> V_112 ( V_78 ) ;
return 0 ;
}
}
V_95 -> V_96 = V_78 ;
V_76 = & V_95 -> V_37 . V_76 ;
V_76 -> V_170 . V_171 = 60 ;
V_76 -> V_170 . V_172 |=
V_173 ;
switch ( V_78 -> V_174 ) {
case V_175 :
V_76 -> V_176 = V_177 ;
V_76 -> V_170 . V_172 |= V_178 ;
break;
case V_179 :
V_76 -> V_176 = V_180 ;
V_76 -> V_170 . V_172 |= V_181 ;
break;
case V_182 :
V_76 -> V_176 = V_183 ;
V_76 -> V_170 . V_172 |= V_184 ;
break;
default:
F_75 ( 1 , L_3 ,
V_78 -> V_174 ) ;
return - V_59 ;
}
V_76 -> V_185 = V_98 -> V_186 ;
V_76 -> V_155 = V_78 -> V_15 -> V_41 ;
V_76 -> V_187 = V_78 -> V_15 -> V_188 ;
V_76 -> V_5 = V_78 -> V_15 -> V_5 ;
V_76 -> V_189 = V_78 -> V_190 ;
memcpy ( V_76 -> V_115 , V_78 -> V_84 , V_76 -> V_189 ) ;
V_166 = (struct V_165 * ) F_76 ( V_78 ) ;
V_167 = F_77 ( V_78 ) ;
V_130 = F_78 ( V_78 ) ;
V_103 = (struct V_169 * ) & V_95 -> V_191 ;
V_102 = sizeof( V_95 -> V_191 ) ;
if ( V_167 ) {
if ( V_167 > V_192 ) {
V_102 = ( V_167 * sizeof( void * ) +
sizeof( struct V_169 ) ) ;
V_103 = F_38 ( V_102 , V_94 ) ;
if ( ! V_103 )
return V_193 ;
}
V_103 -> V_109 . V_110 = V_130 ;
V_103 -> V_109 . V_194 = V_166 [ 0 ] . V_194 ;
V_168 = V_166 ;
for ( V_53 = 0 ; V_53 < V_167 ; V_53 ++ ) {
V_103 -> V_109 . V_195 [ V_53 ] =
F_79 ( F_80 ( ( V_168 ) ) ) ;
V_168 = F_81 ( V_168 ) ;
}
} else if ( F_76 ( V_78 ) ) {
V_103 -> V_109 . V_110 = V_130 ;
V_103 -> V_109 . V_194 =
F_82 ( F_76 ( V_78 ) ) & ( V_134 - 1 ) ;
V_103 -> V_109 . V_195 [ 0 ] =
F_82 ( F_76 ( V_78 ) ) >> V_196 ;
}
V_95 -> V_103 = V_103 ;
V_95 -> V_102 = V_102 ;
V_38 = F_59 ( V_18 , V_95 ) ;
if ( V_38 == - V_197 ) {
return V_193 ;
}
return 0 ;
}
static int F_83 ( struct V_14 * V_15 ,
const struct V_198 * V_199 )
{
int V_38 ;
int V_33 = F_26 () ;
struct V_11 * V_8 ;
struct V_97 * V_98 ;
bool V_200 = ( ( V_199 -> V_201 == V_202 ) ? true : false ) ;
int V_203 = 0 ;
struct V_13 * V_16 ;
int V_204 ;
int V_205 ;
int V_206 ;
int V_207 = 0 ;
if ( V_208 < V_209 ) {
V_204 = V_210 ;
V_205 = V_211 ;
V_206 = V_212 ;
} else {
V_204 = V_213 ;
V_205 = V_214 ;
V_206 = V_215 ;
V_207 = ( V_33 / V_216 ) ;
}
V_217 . V_218 = ( V_219 *
( V_207 + 1 ) ) ;
V_8 = F_84 ( & V_217 ,
sizeof( struct V_97 ) ) ;
if ( ! V_8 )
return - V_220 ;
V_98 = F_42 ( V_8 ) ;
memset ( V_98 , 0 , sizeof( struct V_97 ) ) ;
V_98 -> V_186 = V_8 -> V_221 ;
V_98 -> V_18 = V_15 ;
V_16 = F_85 ( sizeof( struct V_13 ) , V_222 ) ;
if ( ! V_16 ) {
V_38 = - V_220 ;
goto V_223;
}
V_16 -> V_17 = false ;
V_16 -> V_29 = false ;
F_86 ( & V_16 -> V_20 ) ;
V_16 -> V_15 = V_15 ;
V_16 -> V_8 = V_8 ;
F_57 ( V_15 , V_16 ) ;
V_16 -> V_185 = V_8 -> V_221 ;
V_38 = F_53 ( V_15 , V_30 ) ;
if ( V_38 )
goto V_224;
V_98 -> V_225 = V_16 -> V_155 ;
V_98 -> V_203 = V_16 -> V_187 ;
switch ( V_199 -> V_201 ) {
case V_226 :
V_8 -> V_227 = V_228 ;
V_8 -> V_229 = V_230 ;
V_8 -> V_231 = V_232 - 1 ;
break;
case V_233 :
V_8 -> V_227 = V_204 ;
V_8 -> V_229 = V_205 ;
V_8 -> V_231 = V_206 - 1 ;
break;
default:
V_8 -> V_227 = V_210 ;
V_8 -> V_229 = V_211 ;
V_8 -> V_231 = V_212 - 1 ;
break;
}
V_8 -> V_234 = V_235 ;
V_8 -> V_236 = ( V_16 -> V_73 >> V_196 ) ;
V_38 = F_87 ( V_8 , & V_15 -> V_15 ) ;
if ( V_38 != 0 )
goto V_237;
if ( ! V_200 ) {
F_12 ( V_8 ) ;
} else {
V_203 = ( V_15 -> V_238 . V_239 [ 5 ] << 8 |
V_15 -> V_238 . V_239 [ 4 ] ) ;
V_38 = F_88 ( V_8 , 0 , V_203 , 0 ) ;
if ( V_38 ) {
F_89 ( V_8 ) ;
goto V_237;
}
}
return 0 ;
V_237:
F_54 ( V_15 ) ;
goto V_223;
V_224:
F_6 ( V_16 ) ;
V_223:
F_16 ( V_8 ) ;
return V_38 ;
}
static int F_90 ( struct V_14 * V_18 )
{
struct V_13 * V_16 = F_18 ( V_18 ) ;
struct V_11 * V_8 = V_16 -> V_8 ;
F_89 ( V_8 ) ;
F_54 ( V_18 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
static int T_6 F_91 ( void )
{
V_219 =
( ( V_30 - V_134 ) /
F_50 ( V_240 +
sizeof( struct V_37 ) + sizeof( T_4 ) -
V_47 ,
sizeof( T_4 ) ) ) ;
return F_92 ( & V_241 ) ;
}
static void T_7 F_93 ( void )
{
F_94 ( & V_241 ) ;
}
