static void F_1 ( struct V_1 * V_1 ,
enum V_2 V_3 )
{
V_1 -> V_4 |= ( 1 << V_3 ) ;
}
void F_2 ( struct V_1 * V_1 ,
const struct V_5 * V_6 ,
unsigned int V_7 )
{
unsigned int V_8 ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ , V_6 ++ ) {
F_3 ( V_6 -> V_9 > V_10 ) ;
F_3 ( F_4 ( V_1 ,
V_6 -> V_3 ) ) ;
F_1 ( V_1 , V_6 -> V_3 ) ;
V_1 -> V_9 [ V_6 -> V_3 ] = V_6 -> V_9 ;
}
F_3 ( ! F_4 ( V_1 ,
V_11 ) ) ;
F_3 ( ! F_4 ( V_1 ,
V_12 ) ) ;
}
T_1 F_5 ( const struct V_13 * V_14 , int V_15 , T_2 V_16 ,
void * V_17 , int V_18 )
{
int V_19 = F_6 ( V_16 ) ;
if ( ! V_17 ) {
V_17 = V_14 -> V_17 ;
V_18 = F_7 ( V_14 ) ;
}
if ( V_19 >= 0 ) {
T_1 * V_20 , V_21 ;
V_20 = F_8 ( V_14 , V_15 + V_19 ,
sizeof( V_21 ) , V_17 , V_18 , & V_21 ) ;
if ( V_20 )
return * V_20 ;
}
return 0 ;
}
bool F_9 ( const struct V_13 * V_14 ,
struct V_1 * V_1 ,
void * V_22 ,
void * V_17 , T_3 V_23 , int V_24 , int V_18 ,
unsigned int V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
T_2 V_16 = 0 ;
bool V_38 = false ;
if ( ! V_17 ) {
V_17 = V_14 -> V_17 ;
V_23 = V_14 -> V_39 ;
V_24 = F_10 ( V_14 ) ;
V_18 = F_7 ( V_14 ) ;
}
V_27 = F_11 ( V_1 ,
V_11 ,
V_22 ) ;
V_29 = F_11 ( V_1 ,
V_12 ,
V_22 ) ;
if ( F_4 ( V_1 ,
V_40 ) ) {
struct V_41 * V_42 = F_12 ( V_14 ) ;
struct V_43 * V_44 ;
V_44 = F_11 ( V_1 ,
V_40 ,
V_22 ) ;
memcpy ( V_44 , & V_42 -> V_45 , sizeof( * V_44 ) ) ;
}
V_46:
switch ( V_23 ) {
case F_13 ( V_47 ) : {
const struct V_48 * V_49 ;
struct V_48 V_50 ;
V_51:
V_49 = F_8 ( V_14 , V_24 , sizeof( V_50 ) , V_17 , V_18 , & V_50 ) ;
if ( ! V_49 || V_49 -> V_52 < 5 )
goto V_53;
V_24 += V_49 -> V_52 * 4 ;
V_16 = V_49 -> V_39 ;
if ( F_4 ( V_1 ,
V_54 ) ) {
V_31 = F_11 ( V_1 ,
V_54 ,
V_22 ) ;
memcpy ( & V_31 -> V_55 , & V_49 -> V_56 ,
sizeof( V_31 -> V_55 ) ) ;
V_27 -> V_57 = V_54 ;
}
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
V_49 = F_8 ( V_14 , V_24 , sizeof( V_50 ) , V_17 , V_18 , & V_50 ) ;
if ( ! V_49 )
goto V_53;
V_16 = V_49 -> V_68 ;
V_24 += sizeof( struct V_66 ) ;
if ( F_4 ( V_1 ,
V_69 ) ) {
V_31 = F_11 ( V_1 ,
V_69 ,
V_22 ) ;
memcpy ( & V_31 -> V_70 , & V_49 -> V_56 ,
sizeof( V_31 -> V_70 ) ) ;
V_27 -> V_57 = V_69 ;
}
if ( ( F_4 ( V_1 ,
V_71 ) ||
( V_25 & V_72 ) ) &&
F_15 ( V_49 ) ) {
T_1 V_73 = F_15 ( V_49 ) ;
if ( F_4 ( V_1 ,
V_71 ) ) {
V_35 = F_11 ( V_1 ,
V_71 ,
V_22 ) ;
V_35 -> V_73 = F_16 ( V_73 ) ;
}
if ( V_25 & V_72 )
goto V_61;
}
if ( V_25 & V_64 )
goto V_61;
break;
}
case F_13 ( V_74 ) :
case F_13 ( V_75 ) : {
const struct V_76 * V_77 ;
struct V_76 V_78 ;
V_77 = F_8 ( V_14 , V_24 , sizeof( V_78 ) , V_17 , V_18 , & V_78 ) ;
if ( ! V_77 )
goto V_53;
if ( F_4 ( V_1 ,
V_79 ) ) {
V_35 = F_11 ( V_1 ,
V_79 ,
V_22 ) ;
V_35 -> V_80 = F_17 ( V_14 ) ;
}
V_23 = V_77 -> V_81 ;
V_24 += sizeof( * V_77 ) ;
goto V_46;
}
case F_13 ( V_82 ) : {
struct {
struct V_83 V_84 ;
T_3 V_23 ;
} * V_84 , V_85 ;
V_84 = F_8 ( V_14 , V_24 , sizeof( V_85 ) , V_17 , V_18 , & V_85 ) ;
if ( ! V_84 )
goto V_53;
V_23 = V_84 -> V_23 ;
V_24 += V_86 ;
switch ( V_23 ) {
case F_13 ( V_87 ) :
goto V_51;
case F_13 ( V_88 ) :
goto V_67;
default:
goto V_53;
}
}
case F_13 ( V_89 ) : {
struct {
T_1 V_90 [ 3 ] ;
T_1 V_91 ;
} * V_84 , V_85 ;
V_84 = F_8 ( V_14 , V_24 , sizeof( V_85 ) , V_17 , V_18 , & V_85 ) ;
if ( ! V_84 )
goto V_53;
if ( F_4 ( V_1 ,
V_92 ) ) {
V_31 = F_11 ( V_1 ,
V_92 ,
V_22 ) ;
V_31 -> V_93 . V_91 = V_84 -> V_91 ;
V_27 -> V_57 = V_92 ;
}
goto V_61;
}
case F_13 ( V_94 ) :
case F_13 ( V_95 ) : {
struct V_96 * V_84 , V_85 [ 2 ] ;
V_97:
V_84 = F_8 ( V_14 , V_24 , sizeof( V_85 ) , V_17 ,
V_18 , & V_85 ) ;
if ( ! V_84 )
goto V_53;
if ( ( F_16 ( V_84 [ 0 ] . V_98 ) & V_99 ) >>
V_100 == V_101 ) {
if ( F_4 ( V_1 ,
V_102 ) ) {
V_37 = F_11 ( V_1 ,
V_102 ,
V_22 ) ;
V_37 -> V_103 = V_84 [ 1 ] . V_98 &
F_18 ( V_99 ) ;
}
goto V_61;
}
goto V_61;
}
case F_13 ( V_104 ) :
if ( ( V_18 - V_24 ) < V_105 )
goto V_53;
V_24 += V_105 ;
goto V_61;
default:
goto V_53;
}
V_106:
switch ( V_16 ) {
case V_107 : {
struct V_108 {
T_3 V_25 ;
T_3 V_23 ;
} * V_84 , V_85 ;
V_84 = F_8 ( V_14 , V_24 , sizeof( V_85 ) , V_17 , V_18 , & V_85 ) ;
if ( ! V_84 )
goto V_53;
if ( V_84 -> V_25 & ( V_109 | V_110 ) )
break;
V_23 = V_84 -> V_23 ;
V_24 += 4 ;
if ( V_84 -> V_25 & V_111 )
V_24 += 4 ;
if ( V_84 -> V_25 & V_112 ) {
const T_1 * V_103 ;
T_1 V_113 ;
V_103 = F_8 ( V_14 , V_24 , sizeof( V_113 ) ,
V_17 , V_18 , & V_113 ) ;
if ( ! V_103 )
goto V_53;
if ( F_4 ( V_1 ,
V_114 ) ) {
V_37 = F_11 ( V_1 ,
V_114 ,
V_22 ) ;
V_37 -> V_103 = * V_103 ;
}
V_24 += 4 ;
}
if ( V_84 -> V_25 & V_115 )
V_24 += 4 ;
if ( V_23 == F_13 ( V_116 ) ) {
const struct V_41 * V_42 ;
struct V_41 V_117 ;
V_42 = F_8 ( V_14 , V_24 ,
sizeof( V_117 ) ,
V_17 , V_18 , & V_117 ) ;
if ( ! V_42 )
goto V_53;
V_23 = V_42 -> V_118 ;
V_24 += sizeof( * V_42 ) ;
if ( V_119 )
V_18 = V_24 ;
}
V_27 -> V_25 |= V_120 ;
if ( V_25 & V_121 )
goto V_61;
goto V_46;
}
case V_122 :
case V_123 :
case V_124 : {
T_2 V_125 [ 2 ] , * V_126 ;
if ( V_23 != F_13 ( V_65 ) )
break;
V_126 = F_8 ( V_14 , V_24 , sizeof( V_125 ) ,
V_17 , V_18 , & V_125 ) ;
if ( ! V_126 )
goto V_53;
V_16 = V_126 [ 0 ] ;
V_24 += ( V_126 [ 1 ] + 1 ) << 3 ;
goto V_106;
}
case V_127 : {
struct V_128 V_129 , * V_130 ;
if ( V_23 != F_13 ( V_65 ) )
break;
V_130 = F_8 ( V_14 , V_24 , sizeof( V_129 ) ,
V_17 , V_18 , & V_129 ) ;
if ( ! V_130 )
goto V_53;
V_27 -> V_25 |= V_58 ;
V_24 += sizeof( V_129 ) ;
V_16 = V_130 -> V_68 ;
if ( ! ( V_130 -> V_59 & F_13 ( V_131 ) ) ) {
V_27 -> V_25 |= V_62 ;
if ( V_25 & V_63 )
goto V_106;
}
goto V_61;
}
case V_132 :
V_23 = F_13 ( V_47 ) ;
V_27 -> V_25 |= V_120 ;
if ( V_25 & V_121 )
goto V_61;
goto V_51;
case V_133 :
V_23 = F_13 ( V_65 ) ;
V_27 -> V_25 |= V_120 ;
if ( V_25 & V_121 )
goto V_61;
goto V_67;
case V_134 :
V_23 = F_13 ( V_94 ) ;
goto V_97;
default:
break;
}
if ( F_4 ( V_1 ,
V_135 ) ) {
V_33 = F_11 ( V_1 ,
V_135 ,
V_22 ) ;
V_33 -> V_20 = F_5 ( V_14 , V_24 , V_16 ,
V_17 , V_18 ) ;
}
V_61:
V_38 = true ;
V_53:
V_29 -> V_136 = V_23 ;
V_29 -> V_16 = V_16 ;
V_27 -> V_15 = ( V_137 ) V_24 ;
return V_38 ;
}
static T_4 void F_19 ( void )
{
F_20 ( & V_138 , sizeof( V_138 ) ) ;
}
static T_4 T_5 F_21 ( const T_5 * V_139 , T_5 V_140 ,
T_5 V_141 )
{
return F_22 ( V_139 , V_140 , V_141 ) ;
}
static inline const T_5 * F_23 ( const struct V_142 * V_143 )
{
const void * V_144 = V_143 ;
F_24 ( V_145 % sizeof( T_5 ) ) ;
return ( const T_5 * ) ( V_144 + V_145 ) ;
}
static inline T_6 F_25 ( const struct V_142 * V_143 )
{
T_6 V_146 = V_145 + sizeof( V_143 -> V_147 ) ;
F_24 ( ( sizeof( * V_143 ) - V_145 ) % sizeof( T_5 ) ) ;
F_24 ( F_26 ( F_27 ( * V_143 ) , V_147 ) !=
sizeof( * V_143 ) - sizeof( V_143 -> V_147 ) ) ;
switch ( V_143 -> V_148 . V_57 ) {
case V_54 :
V_146 -= sizeof( V_143 -> V_147 . V_55 ) ;
break;
case V_69 :
V_146 -= sizeof( V_143 -> V_147 . V_70 ) ;
break;
case V_92 :
V_146 -= sizeof( V_143 -> V_147 . V_93 ) ;
break;
}
return ( sizeof( * V_143 ) - V_146 ) / sizeof( T_5 ) ;
}
T_1 F_28 ( const struct V_142 * V_143 )
{
switch ( V_143 -> V_148 . V_57 ) {
case V_54 :
return V_143 -> V_147 . V_55 . V_149 ;
case V_69 :
return ( V_150 T_1 ) F_29 (
& V_143 -> V_147 . V_70 . V_149 ) ;
case V_92 :
return V_143 -> V_147 . V_93 . V_91 ;
default:
return 0 ;
}
}
T_1 F_30 ( const struct V_142 * V_143 )
{
switch ( V_143 -> V_148 . V_57 ) {
case V_54 :
return V_143 -> V_147 . V_55 . V_151 ;
case V_69 :
return ( V_150 T_1 ) F_29 (
& V_143 -> V_147 . V_70 . V_151 ) ;
default:
return 0 ;
}
}
static inline void F_31 ( struct V_142 * V_152 )
{
int V_153 , V_8 ;
switch ( V_152 -> V_148 . V_57 ) {
case V_54 :
V_153 = ( V_150 T_5 ) V_152 -> V_147 . V_55 . V_151 -
( V_150 T_5 ) V_152 -> V_147 . V_55 . V_149 ;
if ( ( V_153 < 0 ) ||
( V_153 == 0 &&
( ( V_150 V_137 ) V_152 -> V_20 . V_151 <
( V_150 V_137 ) V_152 -> V_20 . V_149 ) ) ) {
F_32 ( V_152 -> V_147 . V_55 . V_149 , V_152 -> V_147 . V_55 . V_151 ) ;
F_32 ( V_152 -> V_20 . V_149 , V_152 -> V_20 . V_151 ) ;
}
break;
case V_69 :
V_153 = memcmp ( & V_152 -> V_147 . V_70 . V_151 ,
& V_152 -> V_147 . V_70 . V_149 ,
sizeof( V_152 -> V_147 . V_70 . V_151 ) ) ;
if ( ( V_153 < 0 ) ||
( V_153 == 0 &&
( ( V_150 V_137 ) V_152 -> V_20 . V_151 <
( V_150 V_137 ) V_152 -> V_20 . V_149 ) ) ) {
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ )
F_32 ( V_152 -> V_147 . V_70 . V_149 . V_154 [ V_8 ] ,
V_152 -> V_147 . V_70 . V_151 . V_154 [ V_8 ] ) ;
F_32 ( V_152 -> V_20 . V_149 , V_152 -> V_20 . V_151 ) ;
}
break;
}
}
static inline T_5 F_33 ( struct V_142 * V_152 , T_5 V_141 )
{
T_5 V_155 ;
F_31 ( V_152 ) ;
V_155 = F_21 ( F_23 ( V_152 ) ,
F_25 ( V_152 ) , V_141 ) ;
if ( ! V_155 )
V_155 = 1 ;
return V_155 ;
}
T_5 F_34 ( struct V_142 * V_152 )
{
F_19 () ;
return F_33 ( V_152 , V_138 ) ;
}
static inline T_5 F_35 ( const struct V_13 * V_14 ,
struct V_142 * V_152 , T_5 V_141 )
{
F_36 ( V_14 , V_152 ,
V_72 ) ;
return F_33 ( V_152 , V_141 ) ;
}
void F_37 ( struct V_156 * V_157 ,
const struct V_142 * V_143 )
{
struct V_158 * V_17 =
(struct V_158 * ) V_157 ;
F_24 ( sizeof( * V_17 ) > sizeof( * V_157 ) ) ;
memset ( V_157 , 0 , sizeof( * V_157 ) ) ;
V_17 -> V_136 = V_143 -> V_159 . V_136 ;
V_17 -> V_16 = V_143 -> V_159 . V_16 ;
V_17 -> V_20 = V_143 -> V_20 . V_20 ;
V_17 -> V_149 = V_143 -> V_147 . V_55 . V_149 ;
V_17 -> V_151 = V_143 -> V_147 . V_55 . V_151 ;
}
void F_38 ( struct V_13 * V_14 )
{
struct V_142 V_152 ;
F_19 () ;
F_39 ( V_14 , F_35 ( V_14 , & V_152 , V_138 ) ,
F_40 ( & V_152 ) ) ;
}
T_7 F_41 ( const struct V_13 * V_14 , T_5 V_160 )
{
struct V_142 V_152 ;
return F_35 ( V_14 , & V_152 , V_160 ) ;
}
T_7 F_42 ( struct V_13 * V_14 , const struct V_161 * V_162 )
{
struct V_142 V_152 ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
memcpy ( & V_152 . V_147 . V_70 . V_149 , & V_162 -> V_56 ,
sizeof( V_152 . V_147 . V_70 . V_149 ) ) ;
memcpy ( & V_152 . V_147 . V_70 . V_151 , & V_162 -> V_163 ,
sizeof( V_152 . V_147 . V_70 . V_151 ) ) ;
V_152 . V_148 . V_57 = V_69 ;
V_152 . V_20 . V_149 = V_162 -> V_164 ;
V_152 . V_20 . V_151 = V_162 -> V_165 ;
V_152 . V_103 . V_103 = V_162 -> V_166 ;
V_152 . V_167 . V_73 = ( V_150 T_5 ) V_162 -> V_168 ;
V_152 . V_159 . V_16 = V_162 -> V_169 ;
F_39 ( V_14 , F_34 ( & V_152 ) ,
F_40 ( & V_152 ) ) ;
return V_14 -> V_155 ;
}
T_7 F_43 ( struct V_13 * V_14 , const struct V_170 * V_171 )
{
struct V_142 V_152 ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_152 . V_147 . V_55 . V_149 = V_171 -> V_56 ;
V_152 . V_147 . V_55 . V_151 = V_171 -> V_163 ;
V_152 . V_148 . V_57 = V_54 ;
V_152 . V_20 . V_149 = V_171 -> V_172 ;
V_152 . V_20 . V_151 = V_171 -> V_173 ;
V_152 . V_103 . V_103 = V_171 -> V_174 ;
V_152 . V_159 . V_16 = V_171 -> V_175 ;
F_39 ( V_14 , F_34 ( & V_152 ) ,
F_40 ( & V_152 ) ) ;
return V_14 -> V_155 ;
}
T_5 F_44 ( const struct V_13 * V_14 , void * V_17 ,
const struct V_142 * V_152 , int V_18 )
{
T_5 V_19 = V_152 -> V_148 . V_15 ;
if ( ( V_152 -> V_148 . V_25 & V_58 ) &&
! ( V_152 -> V_148 . V_25 & V_62 ) )
return V_19 ;
switch ( V_152 -> V_159 . V_16 ) {
case V_176 : {
const T_2 * V_177 ;
T_2 V_178 ;
V_177 = F_8 ( V_14 , V_19 + 12 , sizeof( V_178 ) ,
V_17 , V_18 , & V_178 ) ;
if ( ! V_177 )
return V_19 ;
V_19 += F_45 ( T_5 , sizeof( struct V_179 ) , ( * V_177 & 0xF0 ) >> 2 ) ;
break;
}
case V_180 :
case V_181 :
V_19 += sizeof( struct V_182 ) ;
break;
case V_183 :
V_19 += sizeof( struct V_184 ) ;
break;
case V_185 :
V_19 += sizeof( struct V_186 ) ;
break;
case V_187 :
V_19 += sizeof( struct V_188 ) ;
break;
case V_189 :
V_19 += sizeof( struct V_190 ) ;
break;
case V_191 :
V_19 += sizeof( struct V_192 ) ;
break;
}
return V_19 ;
}
T_5 F_46 ( const struct V_13 * V_14 )
{
struct V_142 V_152 ;
if ( ! F_36 ( V_14 , & V_152 , 0 ) )
return 0 ;
return F_44 ( V_14 , V_14 -> V_17 , & V_152 , F_7 ( V_14 ) ) ;
}
T_7 F_47 ( const struct V_161 * V_162 , struct V_142 * V_152 )
{
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
memcpy ( & V_152 -> V_147 . V_70 . V_149 , & V_162 -> V_56 ,
sizeof( V_152 -> V_147 . V_70 . V_149 ) ) ;
memcpy ( & V_152 -> V_147 . V_70 . V_151 , & V_162 -> V_163 ,
sizeof( V_152 -> V_147 . V_70 . V_151 ) ) ;
V_152 -> V_148 . V_57 = V_69 ;
V_152 -> V_20 . V_149 = V_162 -> V_164 ;
V_152 -> V_20 . V_151 = V_162 -> V_165 ;
V_152 -> V_103 . V_103 = V_162 -> V_166 ;
V_152 -> V_167 . V_73 = ( V_150 T_5 ) V_162 -> V_168 ;
V_152 -> V_159 . V_16 = V_162 -> V_169 ;
return F_34 ( V_152 ) ;
}
T_7 F_48 ( const struct V_170 * V_171 , struct V_142 * V_152 )
{
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
V_152 -> V_147 . V_55 . V_149 = V_171 -> V_56 ;
V_152 -> V_147 . V_55 . V_151 = V_171 -> V_163 ;
V_152 -> V_148 . V_57 = V_54 ;
V_152 -> V_20 . V_149 = V_171 -> V_172 ;
V_152 -> V_20 . V_151 = V_171 -> V_173 ;
V_152 -> V_103 . V_103 = V_171 -> V_174 ;
V_152 -> V_159 . V_16 = V_171 -> V_175 ;
return F_34 ( V_152 ) ;
}
static int T_8 F_49 ( void )
{
F_2 ( & V_193 ,
V_194 ,
F_50 ( V_194 ) ) ;
F_2 ( & V_195 ,
V_196 ,
F_50 ( V_196 ) ) ;
return 0 ;
}
