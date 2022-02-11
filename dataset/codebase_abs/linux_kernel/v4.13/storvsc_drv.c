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
if ( V_27 -> V_35 == V_36 ) {
V_19 -> V_37 [ V_27 -> V_38 ] = V_27 ;
F_26 ( V_27 -> V_38 , & V_19 -> V_39 ) ;
}
}
static void F_27 ( struct V_17 * V_18 , int V_40 )
{
struct V_16 * V_19 ;
int V_41 = F_28 () ;
int V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_45 ;
int V_46 , V_47 ;
V_42 = ( ( V_40 > V_41 ) ? V_41 : V_40 ) ;
V_19 = F_18 ( V_18 ) ;
if ( ! V_19 )
return;
V_19 -> V_42 = V_42 ;
V_44 = & V_19 -> V_48 ;
V_45 = & V_44 -> V_45 ;
V_19 -> V_32 = true ;
F_29 ( V_18 -> V_49 , F_24 ) ;
if ( F_30 ( V_18 -> V_49 ) )
return;
V_19 -> V_32 = false ;
memset ( V_44 , 0 , sizeof( struct V_43 ) ) ;
F_31 ( & V_44 -> F_21 ) ;
V_45 -> V_50 = V_51 ;
V_45 -> V_52 = V_53 ;
V_45 -> V_54 = V_42 ;
V_46 = F_32 ( V_18 -> V_49 , V_45 ,
( sizeof( struct V_45 ) -
V_55 ) ,
( unsigned long ) V_44 ,
V_56 ,
V_57 ) ;
if ( V_46 != 0 )
return;
V_47 = F_33 ( & V_44 -> F_21 , 10 * V_58 ) ;
if ( V_47 == 0 )
return;
if ( V_45 -> V_50 != V_59 ||
V_45 -> V_60 != 0 )
return;
V_19 -> V_32 = true ;
F_30 ( V_18 -> V_49 ) ;
}
static void F_34 ( struct V_16 * V_19 ,
struct V_45 * V_45 )
{
if ( V_45 -> V_61 . V_62 ) {
V_19 -> V_63 =
F_35 ( V_45 -> V_61 . V_64 ) ;
V_19 -> V_65 =
F_35 ( V_45 -> V_61 . V_66 ) ;
} else {
V_19 -> V_63 =
F_35 ( V_45 -> V_61 . V_67 ) ;
V_19 -> V_65 =
F_35 ( V_45 -> V_61 . V_68 ) ;
}
}
static int F_36 ( struct V_17 * V_18 ,
struct V_43 * V_44 ,
bool V_69 )
{
struct V_45 * V_45 ;
int V_46 , V_47 ;
V_45 = & V_44 -> V_45 ;
F_31 ( & V_44 -> F_21 ) ;
V_45 -> V_52 = V_53 ;
V_46 = F_32 ( V_18 -> V_49 , V_45 ,
( sizeof( struct V_45 ) -
V_55 ) ,
( unsigned long ) V_44 ,
V_56 ,
V_57 ) ;
if ( V_46 != 0 )
return V_46 ;
V_47 = F_33 ( & V_44 -> F_21 , 5 * V_58 ) ;
if ( V_47 == 0 )
return - V_70 ;
if ( ! V_69 )
return V_46 ;
if ( V_45 -> V_50 != V_59 ||
V_45 -> V_60 != 0 )
return - V_71 ;
return V_46 ;
}
static int F_37 ( struct V_17 * V_18 , bool V_72 )
{
struct V_16 * V_19 ;
struct V_43 * V_44 ;
struct V_45 * V_45 ;
int V_46 , V_73 ;
int V_40 ;
bool V_74 = false ;
V_19 = F_18 ( V_18 ) ;
if ( ! V_19 )
return - V_75 ;
V_44 = & V_19 -> V_48 ;
V_45 = & V_44 -> V_45 ;
memset ( V_44 , 0 , sizeof( struct V_43 ) ) ;
V_45 -> V_50 = V_76 ;
V_46 = F_36 ( V_18 , V_44 , true ) ;
if ( V_46 )
return V_46 ;
for ( V_73 = 0 ; V_73 < F_38 ( V_77 ) ; V_73 ++ ) {
memset ( V_45 , 0 , sizeof( struct V_45 ) ) ;
V_45 -> V_50 =
V_78 ;
V_45 -> V_79 . V_80 =
V_77 [ V_73 ] . V_81 ;
V_45 -> V_79 . V_82 = 0 ;
V_46 = F_36 ( V_18 , V_44 , false ) ;
if ( V_46 != 0 )
return V_46 ;
if ( V_45 -> V_50 != V_59 )
return - V_71 ;
if ( V_45 -> V_60 == 0 ) {
V_83 =
V_77 [ V_73 ] . V_81 ;
V_84 =
V_77 [ V_73 ] . V_84 ;
V_55 =
V_77 [ V_73 ] . V_55 ;
break;
}
}
if ( V_45 -> V_60 != 0 )
return - V_71 ;
memset ( V_45 , 0 , sizeof( struct V_45 ) ) ;
V_45 -> V_50 = V_85 ;
V_46 = F_36 ( V_18 , V_44 , true ) ;
if ( V_46 != 0 )
return V_46 ;
V_40 = V_45 -> V_86 . V_87 ;
V_19 -> V_37 = F_39 ( F_40 () , sizeof( void * ) ,
V_88 ) ;
if ( V_19 -> V_37 == NULL )
return - V_89 ;
V_19 -> V_37 [ V_18 -> V_49 -> V_38 ] = V_18 -> V_49 ;
F_26 ( V_18 -> V_49 -> V_38 ,
& V_19 -> V_39 ) ;
if ( V_83 >= V_90 ) {
if ( V_45 -> V_86 . V_52 &
V_91 )
V_74 = true ;
}
V_19 -> V_92 =
V_45 -> V_86 . V_92 ;
if ( ! V_72 )
goto V_12;
memset ( V_45 , 0 , sizeof( struct V_45 ) ) ;
V_45 -> V_50 = V_93 ;
V_46 = F_36 ( V_18 , V_44 , true ) ;
if ( V_46 != 0 )
return V_46 ;
F_34 ( V_19 , V_45 ) ;
V_12:
memset ( V_45 , 0 , sizeof( struct V_45 ) ) ;
V_45 -> V_50 = V_94 ;
V_46 = F_36 ( V_18 , V_44 , true ) ;
if ( V_46 != 0 )
return V_46 ;
if ( V_74 )
F_27 ( V_18 , V_40 ) ;
return V_46 ;
}
static void F_41 ( struct V_95 * V_96 ,
struct V_97 * V_98 ,
struct V_14 * V_9 ,
T_1 V_99 , T_1 V_100 )
{
struct V_5 * V_6 ;
void (* F_42)( struct V_3 * V_4 );
bool V_101 = false ;
switch ( F_43 ( V_96 -> V_102 ) ) {
case V_103 :
if ( V_96 -> V_102 & V_104 )
break;
switch ( V_98 -> V_105 [ 0 ] ) {
case V_106 :
case V_107 :
F_44 ( V_98 , V_108 ) ;
break;
case V_109 :
break;
default:
F_44 ( V_98 , V_110 ) ;
}
break;
case V_111 :
V_101 = true ;
F_42 = F_14 ;
break;
case V_112 :
if ( V_96 -> V_102 & V_104 &&
( V_99 == 0x2a ) && ( V_100 == 0x9 ) ) {
V_101 = true ;
F_42 = F_2 ;
F_44 ( V_98 , V_113 ) ;
}
break;
}
if ( ! V_101 )
return;
V_6 = F_45 ( sizeof( struct V_5 ) , V_114 ) ;
if ( ! V_6 ) {
F_44 ( V_98 , V_110 ) ;
return;
}
V_6 -> V_9 = V_9 ;
V_6 -> V_11 = V_96 -> V_11 ;
V_6 -> V_10 = V_96 -> V_115 ;
F_46 ( & V_6 -> V_4 , F_42 ) ;
F_47 ( & V_6 -> V_4 ) ;
}
static void F_48 ( struct V_43 * V_116 ,
struct V_16 * V_117 )
{
struct V_97 * V_98 = V_116 -> V_118 ;
struct V_119 V_120 ;
struct V_95 * V_96 ;
T_2 V_121 ;
struct V_14 * V_9 ;
T_2 V_122 = V_116 -> V_122 ;
void * V_123 = V_116 -> V_123 ;
V_9 = V_117 -> V_9 ;
V_96 = & V_116 -> V_45 . V_96 ;
V_121 = V_96 -> V_121 ;
V_98 -> V_124 = V_96 -> V_125 ;
if ( V_98 -> V_124 ) {
if ( F_49 ( V_98 -> V_126 ,
V_127 , & V_120 ) &&
! ( V_120 . V_128 == V_129 &&
V_120 . V_99 == 0x03A ) &&
F_1 ( V_130 ) )
F_50 ( V_98 -> V_18 , L_1 ,
& V_120 ) ;
}
if ( V_96 -> V_102 != V_131 ) {
F_41 ( V_96 , V_98 , V_9 , V_120 . V_99 ,
V_120 . V_100 ) ;
if ( V_96 -> V_102 != V_132 )
V_121 = 0 ;
}
F_51 ( V_98 ,
V_116 -> V_123 -> V_133 . V_134 - V_121 ) ;
V_98 -> V_135 ( V_98 ) ;
if ( V_122 >
sizeof( struct V_136 ) )
F_7 ( V_123 ) ;
}
static void F_52 ( struct V_16 * V_19 ,
struct V_45 * V_45 ,
struct V_43 * V_44 )
{
struct V_45 * V_137 ;
struct V_17 * V_18 = V_19 -> V_18 ;
V_137 = & V_44 -> V_45 ;
if ( ( V_137 -> V_96 . V_138 [ 0 ] == V_139 ) ||
( V_137 -> V_96 . V_138 [ 0 ] == V_140 ) ) {
V_45 -> V_96 . V_125 = 0 ;
V_45 -> V_96 . V_102 = V_131 ;
}
V_137 -> V_96 . V_125 = V_45 -> V_96 . V_125 ;
V_137 -> V_96 . V_102 = V_45 -> V_96 . V_102 ;
V_137 -> V_96 . V_141 =
V_45 -> V_96 . V_141 ;
if ( V_45 -> V_96 . V_125 != 0 ||
V_45 -> V_96 . V_102 != V_131 )
F_53 ( V_18 , V_142 ,
L_2 ,
V_137 -> V_96 . V_138 [ 0 ] ,
V_45 -> V_96 . V_125 ,
V_45 -> V_96 . V_102 ) ;
if ( ( V_45 -> V_96 . V_125 & 0xFF ) == 0x02 ) {
if ( V_45 -> V_96 . V_102 &
V_104 ) {
F_53 ( V_18 , V_142 ,
L_3 ,
V_44 , V_45 -> V_96 . V_141 ) ;
memcpy ( V_44 -> V_118 -> V_126 ,
V_45 -> V_96 . V_143 ,
V_45 -> V_96 . V_141 ) ;
}
}
V_137 -> V_96 . V_121 =
V_45 -> V_96 . V_121 ;
F_48 ( V_44 , V_19 ) ;
if ( F_54 ( & V_19 -> V_24 ) &&
V_19 -> V_22 )
F_55 ( & V_19 -> V_23 ) ;
}
static void F_56 ( struct V_16 * V_19 ,
struct V_45 * V_45 ,
struct V_43 * V_44 )
{
struct V_5 * V_4 ;
switch ( V_45 -> V_50 ) {
case V_59 :
F_52 ( V_19 , V_45 , V_44 ) ;
break;
case V_144 :
case V_145 :
V_4 = F_45 ( sizeof( struct V_5 ) , V_114 ) ;
if ( ! V_4 )
return;
F_46 ( & V_4 -> V_4 , F_8 ) ;
V_4 -> V_9 = V_19 -> V_9 ;
F_47 ( & V_4 -> V_4 ) ;
break;
case V_93 :
F_34 ( V_19 , V_45 ) ;
#if F_57 ( V_146 )
F_58 ( V_19 -> V_9 ) = V_19 -> V_63 ;
F_59 ( V_19 -> V_9 ) = V_19 -> V_65 ;
#endif
break;
default:
break;
}
}
static void V_34 ( void * V_147 )
{
struct V_26 * V_49 = (struct V_26 * ) V_147 ;
const struct V_148 * V_149 ;
struct V_17 * V_18 ;
struct V_16 * V_19 ;
if ( V_49 -> V_28 != NULL )
V_18 = V_49 -> V_28 -> V_29 ;
else
V_18 = V_49 -> V_29 ;
V_19 = F_23 ( V_18 ) ;
if ( ! V_19 )
return;
F_60 (desc, channel) {
void * V_150 = F_61 ( V_149 ) ;
struct V_43 * V_44 ;
V_44 = (struct V_43 * )
( ( unsigned long ) V_149 -> V_151 ) ;
if ( V_44 == & V_19 -> V_48 ||
V_44 == & V_19 -> V_152 ) {
memcpy ( & V_44 -> V_45 , V_150 ,
( sizeof( struct V_45 ) - V_55 ) ) ;
F_62 ( & V_44 -> F_21 ) ;
} else {
F_56 ( V_19 , V_150 , V_44 ) ;
}
}
}
static int F_63 ( struct V_17 * V_18 , T_2 V_153 ,
bool V_72 )
{
struct V_30 V_31 ;
int V_46 ;
memset ( & V_31 , 0 , sizeof( struct V_30 ) ) ;
V_46 = F_25 ( V_18 -> V_49 ,
V_153 ,
V_153 ,
( void * ) & V_31 ,
sizeof( struct V_30 ) ,
V_34 , V_18 -> V_49 ) ;
if ( V_46 != 0 )
return V_46 ;
V_46 = F_37 ( V_18 , V_72 ) ;
return V_46 ;
}
static int F_64 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
V_19 = F_19 ( V_18 ) ;
V_19 -> V_20 = true ;
F_65 () ;
F_20 ( V_19 ) ;
F_66 ( V_18 , NULL ) ;
F_67 ( V_18 -> V_49 ) ;
F_7 ( V_19 -> V_37 ) ;
F_7 ( V_19 ) ;
return 0 ;
}
static struct V_26 * F_68 ( struct V_16 * V_19 ,
T_3 V_154 )
{
T_3 V_155 = 0 ;
T_3 V_156 ;
struct V_157 V_158 ;
int V_159 , V_160 ;
if ( V_19 -> V_42 == 0 )
return V_19 -> V_18 -> V_49 ;
F_69 ( & V_158 , & V_19 -> V_39 ,
F_70 ( F_71 ( V_154 ) ) ) ;
V_159 = F_72 ( & V_158 ) ;
if ( V_159 == 0 )
return V_19 -> V_18 -> V_49 ;
V_156 = V_154 ;
while ( V_156 >= V_159 )
V_156 -= V_159 ;
F_73 (tgt_cpu, &alloced_mask) {
if ( V_155 == V_156 )
break;
V_155 ++ ;
}
V_19 -> V_37 [ V_154 ] = V_19 -> V_37 [ V_160 ] ;
return V_19 -> V_37 [ V_154 ] ;
}
static int F_74 ( struct V_17 * V_18 ,
struct V_43 * V_44 , T_3 V_154 )
{
struct V_16 * V_19 ;
struct V_45 * V_45 ;
struct V_26 * V_161 ;
int V_46 = 0 ;
struct V_157 V_158 ;
int V_160 ;
V_45 = & V_44 -> V_45 ;
V_19 = F_18 ( V_18 ) ;
if ( ! V_19 )
return - V_75 ;
V_44 -> V_18 = V_18 ;
if ( V_19 -> V_37 [ V_154 ] != NULL ) {
V_161 = V_19 -> V_37 [ V_154 ] ;
if ( V_161 -> V_38 == F_75 () ) {
F_69 ( & V_158 , & V_19 -> V_39 ,
F_70 ( F_71 ( V_154 ) ) ) ;
F_73 (tgt_cpu, &alloced_mask) {
if ( V_160 != V_161 -> V_38 ) {
V_161 =
V_19 -> V_37 [ V_160 ] ;
break;
}
}
}
} else {
V_161 = F_68 ( V_19 , V_154 ) ;
}
V_45 -> V_52 |= V_53 ;
V_45 -> V_96 . V_162 = ( sizeof( struct V_95 ) -
V_55 ) ;
V_45 -> V_96 . V_141 = V_84 ;
V_45 -> V_96 . V_121 =
V_44 -> V_123 -> V_133 . V_134 ;
V_45 -> V_50 = V_163 ;
if ( V_44 -> V_123 -> V_133 . V_134 ) {
V_46 = F_76 ( V_161 ,
V_44 -> V_123 , V_44 -> V_122 ,
V_45 ,
( sizeof( struct V_45 ) -
V_55 ) ,
( unsigned long ) V_44 ) ;
} else {
V_46 = F_32 ( V_161 , V_45 ,
( sizeof( struct V_45 ) -
V_55 ) ,
( unsigned long ) V_44 ,
V_56 ,
V_57 ) ;
}
if ( V_46 != 0 )
return V_46 ;
F_77 ( & V_19 -> V_24 ) ;
return V_46 ;
}
static int F_78 ( struct V_7 * V_164 )
{
V_164 -> V_165 = V_166 | V_167 ;
return 0 ;
}
static int F_79 ( struct V_7 * V_164 )
{
F_80 ( V_164 -> V_168 , V_169 ) ;
F_81 ( V_164 -> V_168 , ( V_170 * V_58 ) ) ;
F_82 ( V_164 -> V_168 , V_171 - 1 ) ;
V_164 -> V_172 = 1 ;
if ( ! strncmp ( V_164 -> V_173 , L_4 , 4 ) ) {
switch ( V_83 ) {
case V_90 :
case V_174 :
V_164 -> V_175 = V_176 ;
break;
}
if ( V_83 >= V_177 )
V_164 -> V_172 = 0 ;
}
return 0 ;
}
static int F_83 ( struct V_7 * V_8 , struct V_178 * V_179 ,
T_4 V_180 , int * V_181 )
{
T_4 V_182 = V_180 ;
T_4 V_183 = V_182 ;
int V_184 , V_185 ;
V_184 = 0xff ;
V_185 = 0x3f ;
F_84 ( V_183 , V_184 * V_185 ) ;
if ( ( T_4 ) ( V_183 + 1 ) * V_184 * V_185 < V_182 )
V_183 = 0xffff ;
V_181 [ 0 ] = V_184 ;
V_181 [ 1 ] = V_185 ;
V_181 [ 2 ] = ( int ) V_183 ;
return 0 ;
}
static int F_85 ( struct V_97 * V_98 )
{
struct V_186 * V_187 = F_86 ( V_98 -> V_18 -> V_9 ) ;
struct V_17 * V_18 = V_187 -> V_21 ;
struct V_16 * V_19 ;
struct V_43 * V_44 ;
struct V_45 * V_45 ;
int V_46 , V_47 ;
V_19 = F_18 ( V_18 ) ;
if ( ! V_19 )
return V_188 ;
V_44 = & V_19 -> V_152 ;
V_45 = & V_44 -> V_45 ;
F_31 ( & V_44 -> F_21 ) ;
V_45 -> V_50 = V_189 ;
V_45 -> V_52 = V_53 ;
V_45 -> V_96 . V_190 = V_19 -> V_190 ;
V_46 = F_32 ( V_18 -> V_49 , V_45 ,
( sizeof( struct V_45 ) -
V_55 ) ,
( unsigned long ) & V_19 -> V_152 ,
V_56 ,
V_57 ) ;
if ( V_46 != 0 )
return V_188 ;
V_47 = F_33 ( & V_44 -> F_21 , 5 * V_58 ) ;
if ( V_47 == 0 )
return V_191 ;
F_20 ( V_19 ) ;
return V_192 ;
}
static enum V_193 F_87 ( struct V_97 * V_98 )
{
#if F_57 ( V_146 )
if ( V_98 -> V_18 -> V_9 -> V_194 == V_195 )
return F_88 ( V_98 ) ;
#endif
return V_196 ;
}
static bool F_89 ( struct V_97 * V_98 )
{
bool V_197 = true ;
T_1 V_198 = V_98 -> V_105 [ 0 ] ;
switch ( V_198 ) {
case V_199 :
case V_200 :
V_98 -> V_124 = V_201 << 16 ;
V_197 = false ;
break;
default:
break;
}
return V_197 ;
}
static int F_90 ( struct V_14 * V_9 , struct V_97 * V_98 )
{
int V_46 ;
struct V_186 * V_187 = F_86 ( V_9 ) ;
struct V_17 * V_21 = V_187 -> V_21 ;
struct V_43 * V_116 = F_91 ( V_98 ) ;
int V_73 ;
struct V_202 * V_203 ;
unsigned int V_204 = 0 ;
struct V_95 * V_96 ;
struct V_202 * V_205 ;
struct V_206 * V_123 ;
T_2 V_122 ;
T_2 V_162 ;
if ( V_83 <= V_90 ) {
if ( ! F_89 ( V_98 ) ) {
V_98 -> V_135 ( V_98 ) ;
return 0 ;
}
}
V_116 -> V_118 = V_98 ;
V_96 = & V_116 -> V_45 . V_96 ;
V_96 -> V_207 . V_208 = 60 ;
V_96 -> V_207 . V_209 |=
V_210 ;
if ( V_98 -> V_18 -> V_211 ) {
V_96 -> V_207 . V_209 |=
( V_212 | V_213 ) ;
V_96 -> V_207 . V_214 = V_215 ;
V_96 -> V_207 . V_216 = V_217 ;
}
switch ( V_98 -> V_218 ) {
case V_219 :
V_96 -> V_220 = V_221 ;
V_96 -> V_207 . V_209 |= V_222 ;
break;
case V_223 :
V_96 -> V_220 = V_224 ;
V_96 -> V_207 . V_209 |= V_225 ;
break;
case V_226 :
V_96 -> V_220 = V_227 ;
V_96 -> V_207 . V_209 |= V_228 ;
break;
default:
F_92 ( 1 , L_5 ,
V_98 -> V_218 ) ;
return - V_71 ;
}
V_96 -> V_229 = V_187 -> V_230 ;
V_96 -> V_190 = V_98 -> V_18 -> V_49 ;
V_96 -> V_115 = V_98 -> V_18 -> V_231 ;
V_96 -> V_11 = V_98 -> V_18 -> V_11 ;
V_96 -> V_232 = V_98 -> V_233 ;
memcpy ( V_96 -> V_138 , V_98 -> V_105 , V_96 -> V_232 ) ;
V_203 = (struct V_202 * ) F_93 ( V_98 ) ;
V_204 = F_94 ( V_98 ) ;
V_162 = F_95 ( V_98 ) ;
V_123 = (struct V_206 * ) & V_116 -> V_234 ;
V_122 = sizeof( V_116 -> V_234 ) ;
if ( V_204 ) {
if ( V_204 > V_235 ) {
V_122 = ( V_204 * sizeof( V_236 ) +
sizeof( struct V_206 ) ) ;
V_123 = F_96 ( V_122 , V_114 ) ;
if ( ! V_123 )
return V_237 ;
}
V_123 -> V_133 . V_134 = V_162 ;
V_123 -> V_133 . V_238 = V_203 [ 0 ] . V_238 ;
V_205 = V_203 ;
for ( V_73 = 0 ; V_73 < V_204 ; V_73 ++ ) {
V_123 -> V_133 . V_239 [ V_73 ] =
F_97 ( F_98 ( ( V_205 ) ) ) ;
V_205 = F_99 ( V_205 ) ;
}
}
V_116 -> V_123 = V_123 ;
V_116 -> V_122 = V_122 ;
V_46 = F_74 ( V_21 , V_116 , F_100 () ) ;
F_101 () ;
if ( V_46 == - V_240 ) {
return V_237 ;
}
return 0 ;
}
static int F_102 ( struct V_17 * V_18 ,
const struct V_241 * V_242 )
{
int V_46 ;
int V_41 = F_28 () ;
struct V_14 * V_9 ;
struct V_186 * V_187 ;
bool V_243 = ( ( V_242 -> V_244 == V_245 ) ? true : false ) ;
bool V_72 = ( ( V_242 -> V_244 == V_246 ) ? true : false ) ;
int V_247 = 0 ;
struct V_16 * V_19 ;
int V_248 ;
int V_249 ;
int V_250 ;
int V_251 = 0 ;
if ( V_252 < V_253 ) {
V_248 = V_254 ;
V_249 = V_255 ;
V_250 = V_256 ;
} else {
V_248 = V_257 ;
V_249 = V_258 ;
V_250 = V_259 ;
V_251 = ( V_41 / V_260 ) ;
}
V_261 . V_262 = ( V_263 *
( V_251 + 1 ) ) ;
V_9 = F_103 ( & V_261 ,
sizeof( struct V_186 ) ) ;
if ( ! V_9 )
return - V_89 ;
V_187 = F_86 ( V_9 ) ;
memset ( V_187 , 0 , sizeof( struct V_186 ) ) ;
V_187 -> V_230 = V_9 -> V_264 ;
V_187 -> V_21 = V_18 ;
V_19 = F_96 ( sizeof( struct V_16 ) , V_88 ) ;
if ( ! V_19 ) {
V_46 = - V_89 ;
goto V_265;
}
V_19 -> V_20 = false ;
V_19 -> V_32 = false ;
F_104 ( & V_19 -> V_23 ) ;
V_19 -> V_18 = V_18 ;
V_19 -> V_9 = V_9 ;
F_66 ( V_18 , V_19 ) ;
V_19 -> V_229 = V_9 -> V_264 ;
V_46 = F_63 ( V_18 , V_33 , V_72 ) ;
if ( V_46 )
goto V_266;
V_187 -> V_267 = V_19 -> V_190 ;
V_187 -> V_247 = V_19 -> V_115 ;
switch ( V_242 -> V_244 ) {
case V_246 :
V_9 -> V_268 = V_269 ;
V_9 -> V_270 = V_271 ;
V_9 -> V_272 = V_273 - 1 ;
#if F_57 ( V_146 )
V_9 -> V_194 = V_195 ;
#endif
break;
case V_274 :
V_9 -> V_268 = V_248 ;
V_9 -> V_270 = V_249 ;
V_9 -> V_272 = V_250 - 1 ;
break;
default:
V_9 -> V_268 = V_254 ;
V_9 -> V_270 = V_255 ;
V_9 -> V_272 = V_256 - 1 ;
break;
}
V_9 -> V_275 = V_276 ;
V_9 -> V_277 = ( V_19 -> V_92 >> V_278 ) ;
if ( V_19 -> V_42 != 0 )
V_9 -> V_279 = V_19 -> V_42 + 1 ;
V_46 = F_105 ( V_9 , & V_18 -> V_18 ) ;
if ( V_46 != 0 )
goto V_280;
if ( ! V_243 ) {
F_13 ( V_9 ) ;
} else {
V_247 = ( V_18 -> V_281 . V_282 [ 5 ] << 8 |
V_18 -> V_281 . V_282 [ 4 ] ) ;
V_46 = F_106 ( V_9 , 0 , V_247 , 0 ) ;
if ( V_46 )
goto V_283;
}
#if F_57 ( V_146 )
if ( V_9 -> V_194 == V_195 ) {
struct V_284 V_285 = {
. V_286 = V_287 ,
} ;
F_58 ( V_9 ) = V_19 -> V_63 ;
F_59 ( V_9 ) = V_19 -> V_65 ;
V_19 -> V_288 = F_107 ( V_9 , 0 , & V_285 ) ;
if ( ! V_19 -> V_288 )
goto V_283;
}
#endif
return 0 ;
V_283:
F_108 ( V_9 ) ;
V_280:
F_64 ( V_18 ) ;
goto V_265;
V_266:
F_7 ( V_19 -> V_37 ) ;
F_7 ( V_19 ) ;
V_265:
F_17 ( V_9 ) ;
return V_46 ;
}
static int F_109 ( struct V_17 * V_21 )
{
struct V_16 * V_19 = F_19 ( V_21 ) ;
struct V_14 * V_9 = V_19 -> V_9 ;
#if F_57 ( V_146 )
if ( V_9 -> V_194 == V_195 ) {
F_110 ( V_19 -> V_288 ) ;
F_111 ( V_9 ) ;
}
#endif
F_108 ( V_9 ) ;
F_64 ( V_21 ) ;
F_17 ( V_9 ) ;
return 0 ;
}
static int T_5 F_112 ( void )
{
int V_46 ;
V_263 =
( ( V_33 - V_171 ) /
F_113 ( V_289 +
sizeof( struct V_45 ) + sizeof( V_236 ) -
V_55 ,
sizeof( V_236 ) ) ) ;
#if F_57 ( V_146 )
V_195 = F_114 ( & V_290 ) ;
if ( ! V_195 )
return - V_75 ;
#endif
V_46 = F_115 ( & V_291 ) ;
#if F_57 ( V_146 )
if ( V_46 )
F_116 ( V_195 ) ;
#endif
return V_46 ;
}
static void T_6 F_117 ( void )
{
F_118 ( & V_291 ) ;
#if F_57 ( V_146 )
F_116 ( V_195 ) ;
#endif
}
