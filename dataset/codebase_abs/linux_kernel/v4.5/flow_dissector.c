static bool F_1 ( const struct V_1 * V_1 ,
enum V_2 V_3 )
{
return V_1 -> V_4 & ( 1 << V_3 ) ;
}
static void F_2 ( struct V_1 * V_1 ,
enum V_2 V_3 )
{
V_1 -> V_4 |= ( 1 << V_3 ) ;
}
static void * F_3 ( struct V_1 * V_1 ,
enum V_2 V_3 ,
void * V_5 )
{
return ( ( char * ) V_5 ) + V_1 -> V_6 [ V_3 ] ;
}
void F_4 ( struct V_1 * V_1 ,
const struct V_7 * V_8 ,
unsigned int V_9 )
{
unsigned int V_10 ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ , V_8 ++ ) {
F_5 ( V_8 -> V_6 > V_11 ) ;
F_5 ( F_1 ( V_1 ,
V_8 -> V_3 ) ) ;
F_2 ( V_1 , V_8 -> V_3 ) ;
V_1 -> V_6 [ V_8 -> V_3 ] = V_8 -> V_6 ;
}
F_5 ( ! F_1 ( V_1 ,
V_12 ) ) ;
F_5 ( ! F_1 ( V_1 ,
V_13 ) ) ;
}
T_1 F_6 ( const struct V_14 * V_15 , int V_16 , T_2 V_17 ,
void * V_18 , int V_19 )
{
int V_20 = F_7 ( V_17 ) ;
if ( ! V_18 ) {
V_18 = V_15 -> V_18 ;
V_19 = F_8 ( V_15 ) ;
}
if ( V_20 >= 0 ) {
T_1 * V_21 , V_22 ;
V_21 = F_9 ( V_15 , V_16 + V_20 ,
sizeof( V_22 ) , V_18 , V_19 , & V_22 ) ;
if ( V_21 )
return * V_21 ;
}
return 0 ;
}
bool F_10 ( const struct V_14 * V_15 ,
struct V_1 * V_1 ,
void * V_5 ,
void * V_18 , T_3 V_23 , int V_24 , int V_19 ,
unsigned int V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
T_2 V_17 = 0 ;
bool V_38 = false ;
if ( ! V_18 ) {
V_18 = V_15 -> V_18 ;
V_23 = V_15 -> V_39 ;
V_24 = F_11 ( V_15 ) ;
V_19 = F_8 ( V_15 ) ;
}
V_27 = F_3 ( V_1 ,
V_12 ,
V_5 ) ;
V_29 = F_3 ( V_1 ,
V_13 ,
V_5 ) ;
if ( F_1 ( V_1 ,
V_40 ) ) {
struct V_41 * V_42 = F_12 ( V_15 ) ;
struct V_43 * V_44 ;
V_44 = F_3 ( V_1 ,
V_40 ,
V_5 ) ;
memcpy ( V_44 , & V_42 -> V_45 , sizeof( * V_44 ) ) ;
}
V_46:
switch ( V_23 ) {
case F_13 ( V_47 ) : {
const struct V_48 * V_49 ;
struct V_48 V_50 ;
V_51:
V_49 = F_9 ( V_15 , V_24 , sizeof( V_50 ) , V_18 , V_19 , & V_50 ) ;
if ( ! V_49 || V_49 -> V_52 < 5 )
goto V_53;
V_24 += V_49 -> V_52 * 4 ;
V_17 = V_49 -> V_39 ;
if ( ! F_1 ( V_1 ,
V_54 ) )
break;
V_31 = F_3 ( V_1 ,
V_54 , V_5 ) ;
memcpy ( & V_31 -> V_55 , & V_49 -> V_56 ,
sizeof( V_31 -> V_55 ) ) ;
V_27 -> V_57 = V_54 ;
if ( F_14 ( V_49 ) ) {
V_27 -> V_25 |= V_58 ;
if ( V_49 -> V_59 & F_13 ( V_60 ) ) {
goto V_61;
} else {
V_27 -> V_25 |= V_62 ;
if ( ! ( V_25 & V_63 ) )
goto V_61;
}
}
if ( V_25 & V_64 )
goto V_61;
break;
}
case F_13 ( V_65 ) : {
const struct V_66 * V_49 ;
struct V_66 V_50 ;
V_67:
V_49 = F_9 ( V_15 , V_24 , sizeof( V_50 ) , V_18 , V_19 , & V_50 ) ;
if ( ! V_49 )
goto V_53;
V_17 = V_49 -> V_68 ;
V_24 += sizeof( struct V_66 ) ;
if ( F_1 ( V_1 ,
V_69 ) ) {
struct V_70 * V_71 ;
V_71 = F_3 ( V_1 ,
V_69 ,
V_5 ) ;
memcpy ( V_71 , & V_49 -> V_56 , sizeof( * V_71 ) ) ;
V_27 -> V_57 = V_69 ;
}
if ( ( F_1 ( V_1 ,
V_72 ) ||
( V_25 & V_73 ) ) &&
F_15 ( V_49 ) ) {
T_1 V_74 = F_15 ( V_49 ) ;
if ( F_1 ( V_1 ,
V_72 ) ) {
V_35 = F_3 ( V_1 ,
V_72 ,
V_5 ) ;
V_35 -> V_74 = F_16 ( V_74 ) ;
}
if ( V_25 & V_73 )
goto V_61;
}
if ( V_25 & V_64 )
goto V_61;
break;
}
case F_13 ( V_75 ) :
case F_13 ( V_76 ) : {
const struct V_77 * V_78 ;
struct V_77 V_79 ;
V_78 = F_9 ( V_15 , V_24 , sizeof( V_79 ) , V_18 , V_19 , & V_79 ) ;
if ( ! V_78 )
goto V_53;
if ( F_1 ( V_1 ,
V_80 ) ) {
V_35 = F_3 ( V_1 ,
V_80 ,
V_5 ) ;
V_35 -> V_81 = F_17 ( V_15 ) ;
}
V_23 = V_78 -> V_82 ;
V_24 += sizeof( * V_78 ) ;
goto V_46;
}
case F_13 ( V_83 ) : {
struct {
struct V_84 V_85 ;
T_3 V_23 ;
} * V_85 , V_86 ;
V_85 = F_9 ( V_15 , V_24 , sizeof( V_86 ) , V_18 , V_19 , & V_86 ) ;
if ( ! V_85 )
goto V_53;
V_23 = V_85 -> V_23 ;
V_24 += V_87 ;
switch ( V_23 ) {
case F_13 ( V_88 ) :
goto V_51;
case F_13 ( V_89 ) :
goto V_67;
default:
goto V_53;
}
}
case F_13 ( V_90 ) : {
struct {
T_1 V_91 [ 3 ] ;
T_1 V_92 ;
} * V_85 , V_86 ;
V_85 = F_9 ( V_15 , V_24 , sizeof( V_86 ) , V_18 , V_19 , & V_86 ) ;
if ( ! V_85 )
goto V_53;
if ( F_1 ( V_1 ,
V_93 ) ) {
V_31 = F_3 ( V_1 ,
V_93 ,
V_5 ) ;
V_31 -> V_94 . V_92 = V_85 -> V_92 ;
V_27 -> V_57 = V_93 ;
}
goto V_61;
}
case F_13 ( V_95 ) :
case F_13 ( V_96 ) : {
struct V_97 * V_85 , V_86 [ 2 ] ;
V_98:
V_85 = F_9 ( V_15 , V_24 , sizeof( V_86 ) , V_18 ,
V_19 , & V_86 ) ;
if ( ! V_85 )
goto V_53;
if ( ( F_16 ( V_85 [ 0 ] . V_99 ) & V_100 ) >>
V_101 == V_102 ) {
if ( F_1 ( V_1 ,
V_103 ) ) {
V_37 = F_3 ( V_1 ,
V_103 ,
V_5 ) ;
V_37 -> V_104 = V_85 [ 1 ] . V_99 &
F_18 ( V_100 ) ;
}
goto V_61;
}
goto V_61;
}
case F_13 ( V_105 ) :
V_27 -> V_16 = ( V_106 ) ( V_24 + V_107 ) ;
default:
goto V_53;
}
V_108:
switch ( V_17 ) {
case V_109 : {
struct V_110 {
T_3 V_25 ;
T_3 V_23 ;
} * V_85 , V_86 ;
V_85 = F_9 ( V_15 , V_24 , sizeof( V_86 ) , V_18 , V_19 , & V_86 ) ;
if ( ! V_85 )
goto V_53;
if ( V_85 -> V_25 & ( V_111 | V_112 ) )
break;
V_23 = V_85 -> V_23 ;
V_24 += 4 ;
if ( V_85 -> V_25 & V_113 )
V_24 += 4 ;
if ( V_85 -> V_25 & V_114 ) {
const T_1 * V_104 ;
T_1 V_115 ;
V_104 = F_9 ( V_15 , V_24 , sizeof( V_115 ) ,
V_18 , V_19 , & V_115 ) ;
if ( ! V_104 )
goto V_53;
if ( F_1 ( V_1 ,
V_116 ) ) {
V_37 = F_3 ( V_1 ,
V_116 ,
V_5 ) ;
V_37 -> V_104 = * V_104 ;
}
V_24 += 4 ;
}
if ( V_85 -> V_25 & V_117 )
V_24 += 4 ;
if ( V_23 == F_13 ( V_118 ) ) {
const struct V_41 * V_42 ;
struct V_41 V_119 ;
V_42 = F_9 ( V_15 , V_24 ,
sizeof( V_119 ) ,
V_18 , V_19 , & V_119 ) ;
if ( ! V_42 )
goto V_53;
V_23 = V_42 -> V_120 ;
V_24 += sizeof( * V_42 ) ;
if ( V_121 )
V_19 = V_24 ;
}
V_27 -> V_25 |= V_122 ;
if ( V_25 & V_123 )
goto V_61;
goto V_46;
}
case V_124 :
case V_125 :
case V_126 : {
T_2 V_127 [ 2 ] , * V_128 ;
if ( V_23 != F_13 ( V_65 ) )
break;
V_128 = F_9 ( V_15 , V_24 , sizeof( V_127 ) ,
V_18 , V_19 , & V_127 ) ;
if ( ! V_128 )
goto V_53;
V_17 = V_128 [ 0 ] ;
V_24 += ( V_128 [ 1 ] + 1 ) << 3 ;
goto V_108;
}
case V_129 : {
struct V_130 V_131 , * V_132 ;
if ( V_23 != F_13 ( V_65 ) )
break;
V_132 = F_9 ( V_15 , V_24 , sizeof( V_131 ) ,
V_18 , V_19 , & V_131 ) ;
if ( ! V_132 )
goto V_53;
V_27 -> V_25 |= V_58 ;
V_24 += sizeof( V_131 ) ;
if ( ! ( V_132 -> V_59 & F_13 ( V_133 ) ) ) {
V_27 -> V_25 |= V_62 ;
if ( V_25 & V_63 ) {
V_17 = V_132 -> V_68 ;
goto V_108;
}
}
goto V_61;
}
case V_134 :
V_23 = F_13 ( V_47 ) ;
V_27 -> V_25 |= V_122 ;
if ( V_25 & V_123 )
goto V_61;
goto V_51;
case V_135 :
V_23 = F_13 ( V_65 ) ;
V_27 -> V_25 |= V_122 ;
if ( V_25 & V_123 )
goto V_61;
goto V_67;
case V_136 :
V_23 = F_13 ( V_95 ) ;
goto V_98;
default:
break;
}
if ( F_1 ( V_1 ,
V_137 ) ) {
V_33 = F_3 ( V_1 ,
V_137 ,
V_5 ) ;
V_33 -> V_21 = F_6 ( V_15 , V_24 , V_17 ,
V_18 , V_19 ) ;
}
V_61:
V_38 = true ;
V_53:
V_29 -> V_138 = V_23 ;
V_29 -> V_17 = V_17 ;
V_27 -> V_16 = ( V_106 ) V_24 ;
return V_38 ;
}
static T_4 void F_19 ( void )
{
F_20 ( & V_139 , sizeof( V_139 ) ) ;
}
static T_4 T_5 F_21 ( const T_5 * V_140 , T_5 V_141 ,
T_5 V_142 )
{
return F_22 ( V_140 , V_141 , V_142 ) ;
}
static inline const T_5 * F_23 ( const struct V_143 * V_144 )
{
const void * V_145 = V_144 ;
F_24 ( V_146 % sizeof( T_5 ) ) ;
return ( const T_5 * ) ( V_145 + V_146 ) ;
}
static inline T_6 F_25 ( const struct V_143 * V_144 )
{
T_6 V_147 = V_146 + sizeof( V_144 -> V_148 ) ;
F_24 ( ( sizeof( * V_144 ) - V_146 ) % sizeof( T_5 ) ) ;
F_24 ( F_26 ( F_27 ( * V_144 ) , V_148 ) !=
sizeof( * V_144 ) - sizeof( V_144 -> V_148 ) ) ;
switch ( V_144 -> V_149 . V_57 ) {
case V_54 :
V_147 -= sizeof( V_144 -> V_148 . V_55 ) ;
break;
case V_69 :
V_147 -= sizeof( V_144 -> V_148 . V_150 ) ;
break;
case V_93 :
V_147 -= sizeof( V_144 -> V_148 . V_94 ) ;
break;
}
return ( sizeof( * V_144 ) - V_147 ) / sizeof( T_5 ) ;
}
T_1 F_28 ( const struct V_143 * V_144 )
{
switch ( V_144 -> V_149 . V_57 ) {
case V_54 :
return V_144 -> V_148 . V_55 . V_151 ;
case V_69 :
return ( V_152 T_1 ) F_29 (
& V_144 -> V_148 . V_150 . V_151 ) ;
case V_93 :
return V_144 -> V_148 . V_94 . V_92 ;
default:
return 0 ;
}
}
T_1 F_30 ( const struct V_143 * V_144 )
{
switch ( V_144 -> V_149 . V_57 ) {
case V_54 :
return V_144 -> V_148 . V_55 . V_153 ;
case V_69 :
return ( V_152 T_1 ) F_29 (
& V_144 -> V_148 . V_150 . V_153 ) ;
default:
return 0 ;
}
}
static inline void F_31 ( struct V_143 * V_154 )
{
int V_155 , V_10 ;
switch ( V_154 -> V_149 . V_57 ) {
case V_54 :
V_155 = ( V_152 T_5 ) V_154 -> V_148 . V_55 . V_153 -
( V_152 T_5 ) V_154 -> V_148 . V_55 . V_151 ;
if ( ( V_155 < 0 ) ||
( V_155 == 0 &&
( ( V_152 V_106 ) V_154 -> V_21 . V_153 <
( V_152 V_106 ) V_154 -> V_21 . V_151 ) ) ) {
F_32 ( V_154 -> V_148 . V_55 . V_151 , V_154 -> V_148 . V_55 . V_153 ) ;
F_32 ( V_154 -> V_21 . V_151 , V_154 -> V_21 . V_153 ) ;
}
break;
case V_69 :
V_155 = memcmp ( & V_154 -> V_148 . V_150 . V_153 ,
& V_154 -> V_148 . V_150 . V_151 ,
sizeof( V_154 -> V_148 . V_150 . V_153 ) ) ;
if ( ( V_155 < 0 ) ||
( V_155 == 0 &&
( ( V_152 V_106 ) V_154 -> V_21 . V_153 <
( V_152 V_106 ) V_154 -> V_21 . V_151 ) ) ) {
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
F_32 ( V_154 -> V_148 . V_150 . V_151 . V_156 [ V_10 ] ,
V_154 -> V_148 . V_150 . V_153 . V_156 [ V_10 ] ) ;
F_32 ( V_154 -> V_21 . V_151 , V_154 -> V_21 . V_153 ) ;
}
break;
}
}
static inline T_5 F_33 ( struct V_143 * V_154 , T_5 V_142 )
{
T_5 V_157 ;
F_31 ( V_154 ) ;
V_157 = F_21 ( F_23 ( V_154 ) ,
F_25 ( V_154 ) , V_142 ) ;
if ( ! V_157 )
V_157 = 1 ;
return V_157 ;
}
T_5 F_34 ( struct V_143 * V_154 )
{
F_19 () ;
return F_33 ( V_154 , V_139 ) ;
}
static inline T_5 F_35 ( const struct V_14 * V_15 ,
struct V_143 * V_154 , T_5 V_142 )
{
F_36 ( V_15 , V_154 ,
V_73 ) ;
return F_33 ( V_154 , V_142 ) ;
}
void F_37 ( struct V_158 * V_159 ,
const struct V_143 * V_144 )
{
struct V_160 * V_18 =
(struct V_160 * ) V_159 ;
F_24 ( sizeof( * V_18 ) > sizeof( * V_159 ) ) ;
memset ( V_159 , 0 , sizeof( * V_159 ) ) ;
V_18 -> V_138 = V_144 -> V_161 . V_138 ;
V_18 -> V_17 = V_144 -> V_161 . V_17 ;
V_18 -> V_21 = V_144 -> V_21 . V_21 ;
V_18 -> V_151 = V_144 -> V_148 . V_55 . V_151 ;
V_18 -> V_153 = V_144 -> V_148 . V_55 . V_153 ;
}
void F_38 ( struct V_14 * V_15 )
{
struct V_143 V_154 ;
F_19 () ;
F_39 ( V_15 , F_35 ( V_15 , & V_154 , V_139 ) ,
F_40 ( & V_154 ) ) ;
}
T_7 F_41 ( const struct V_14 * V_15 , T_5 V_162 )
{
struct V_143 V_154 ;
return F_35 ( V_15 , & V_154 , V_162 ) ;
}
T_7 F_42 ( struct V_14 * V_15 , const struct V_163 * V_164 )
{
struct V_143 V_154 ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
memcpy ( & V_154 . V_148 . V_150 . V_151 , & V_164 -> V_56 ,
sizeof( V_154 . V_148 . V_150 . V_151 ) ) ;
memcpy ( & V_154 . V_148 . V_150 . V_153 , & V_164 -> V_165 ,
sizeof( V_154 . V_148 . V_150 . V_153 ) ) ;
V_154 . V_149 . V_57 = V_69 ;
V_154 . V_21 . V_151 = V_164 -> V_166 ;
V_154 . V_21 . V_153 = V_164 -> V_167 ;
V_154 . V_104 . V_104 = V_164 -> V_168 ;
V_154 . V_169 . V_74 = ( V_152 T_5 ) V_164 -> V_170 ;
V_154 . V_161 . V_17 = V_164 -> V_171 ;
F_39 ( V_15 , F_34 ( & V_154 ) ,
F_40 ( & V_154 ) ) ;
return V_15 -> V_157 ;
}
T_7 F_43 ( struct V_14 * V_15 , const struct V_172 * V_173 )
{
struct V_143 V_154 ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_148 . V_55 . V_151 = V_173 -> V_56 ;
V_154 . V_148 . V_55 . V_153 = V_173 -> V_165 ;
V_154 . V_149 . V_57 = V_54 ;
V_154 . V_21 . V_151 = V_173 -> V_174 ;
V_154 . V_21 . V_153 = V_173 -> V_175 ;
V_154 . V_104 . V_104 = V_173 -> V_176 ;
V_154 . V_161 . V_17 = V_173 -> V_177 ;
F_39 ( V_15 , F_34 ( & V_154 ) ,
F_40 ( & V_154 ) ) ;
return V_15 -> V_157 ;
}
T_5 F_44 ( const struct V_14 * V_15 , void * V_18 ,
const struct V_143 * V_154 , int V_19 )
{
T_5 V_20 = V_154 -> V_149 . V_16 ;
switch ( V_154 -> V_161 . V_17 ) {
case V_178 : {
const T_2 * V_179 ;
T_2 V_180 ;
V_179 = F_9 ( V_15 , V_20 + 12 , sizeof( V_180 ) ,
V_18 , V_19 , & V_180 ) ;
if ( ! V_179 )
return V_20 ;
V_20 += F_45 ( T_5 , sizeof( struct V_181 ) , ( * V_179 & 0xF0 ) >> 2 ) ;
break;
}
case V_182 :
case V_183 :
V_20 += sizeof( struct V_184 ) ;
break;
case V_185 :
V_20 += sizeof( struct V_186 ) ;
break;
case V_187 :
V_20 += sizeof( struct V_188 ) ;
break;
case V_189 :
V_20 += sizeof( struct V_190 ) ;
break;
case V_191 :
V_20 += sizeof( struct V_192 ) ;
break;
case V_193 :
V_20 += sizeof( struct V_194 ) ;
break;
}
return V_20 ;
}
T_5 F_46 ( const struct V_14 * V_15 )
{
struct V_143 V_154 ;
if ( ! F_36 ( V_15 , & V_154 , 0 ) )
return 0 ;
return F_44 ( V_15 , V_15 -> V_18 , & V_154 , F_8 ( V_15 ) ) ;
}
T_7 F_47 ( const struct V_163 * V_164 , struct V_143 * V_154 )
{
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
memcpy ( & V_154 -> V_148 . V_150 . V_151 , & V_164 -> V_56 ,
sizeof( V_154 -> V_148 . V_150 . V_151 ) ) ;
memcpy ( & V_154 -> V_148 . V_150 . V_153 , & V_164 -> V_165 ,
sizeof( V_154 -> V_148 . V_150 . V_153 ) ) ;
V_154 -> V_149 . V_57 = V_69 ;
V_154 -> V_21 . V_151 = V_164 -> V_166 ;
V_154 -> V_21 . V_153 = V_164 -> V_167 ;
V_154 -> V_104 . V_104 = V_164 -> V_168 ;
V_154 -> V_169 . V_74 = ( V_152 T_5 ) V_164 -> V_170 ;
V_154 -> V_161 . V_17 = V_164 -> V_171 ;
return F_34 ( V_154 ) ;
}
T_7 F_48 ( const struct V_172 * V_173 , struct V_143 * V_154 )
{
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
V_154 -> V_148 . V_55 . V_151 = V_173 -> V_56 ;
V_154 -> V_148 . V_55 . V_153 = V_173 -> V_165 ;
V_154 -> V_149 . V_57 = V_54 ;
V_154 -> V_21 . V_151 = V_173 -> V_174 ;
V_154 -> V_21 . V_153 = V_173 -> V_175 ;
V_154 -> V_104 . V_104 = V_173 -> V_176 ;
V_154 -> V_161 . V_17 = V_173 -> V_177 ;
return F_34 ( V_154 ) ;
}
static int T_8 F_49 ( void )
{
F_4 ( & V_195 ,
V_196 ,
F_50 ( V_196 ) ) ;
F_4 ( & V_197 ,
V_198 ,
F_50 ( V_198 ) ) ;
return 0 ;
}
