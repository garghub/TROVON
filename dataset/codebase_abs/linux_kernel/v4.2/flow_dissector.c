static bool F_1 ( struct V_1 * V_1 ,
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
void * V_18 , T_3 V_23 , int V_24 , int V_19 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_2 V_17 = 0 ;
if ( ! V_18 ) {
V_18 = V_15 -> V_18 ;
V_23 = V_15 -> V_37 ;
V_24 = F_11 ( V_15 ) ;
V_19 = F_8 ( V_15 ) ;
}
V_26 = F_3 ( V_1 ,
V_12 ,
V_5 ) ;
V_28 = F_3 ( V_1 ,
V_13 ,
V_5 ) ;
if ( F_1 ( V_1 ,
V_38 ) ) {
struct V_39 * V_40 = F_12 ( V_15 ) ;
struct V_41 * V_42 ;
V_42 = F_3 ( V_1 ,
V_38 ,
V_5 ) ;
memcpy ( V_42 , & V_40 -> V_43 , sizeof( * V_42 ) ) ;
}
V_44:
switch ( V_23 ) {
case F_13 ( V_45 ) : {
const struct V_46 * V_47 ;
struct V_46 V_48 ;
V_49:
V_47 = F_9 ( V_15 , V_24 , sizeof( V_48 ) , V_18 , V_19 , & V_48 ) ;
if ( ! V_47 || V_47 -> V_50 < 5 )
return false ;
V_24 += V_47 -> V_50 * 4 ;
V_17 = V_47 -> V_37 ;
if ( F_14 ( V_47 ) )
V_17 = 0 ;
if ( ! F_1 ( V_1 ,
V_51 ) )
break;
V_30 = F_3 ( V_1 ,
V_51 , V_5 ) ;
memcpy ( & V_30 -> V_52 , & V_47 -> V_53 ,
sizeof( V_30 -> V_52 ) ) ;
V_26 -> V_54 = V_51 ;
break;
}
case F_13 ( V_55 ) : {
const struct V_56 * V_47 ;
struct V_56 V_48 ;
T_1 V_57 ;
V_58:
V_47 = F_9 ( V_15 , V_24 , sizeof( V_48 ) , V_18 , V_19 , & V_48 ) ;
if ( ! V_47 )
return false ;
V_17 = V_47 -> V_59 ;
V_24 += sizeof( struct V_56 ) ;
if ( F_1 ( V_1 ,
V_60 ) ) {
struct V_61 * V_62 ;
V_62 = F_3 ( V_1 ,
V_60 ,
V_5 ) ;
memcpy ( V_62 , & V_47 -> V_53 , sizeof( * V_62 ) ) ;
V_26 -> V_54 = V_60 ;
}
V_57 = F_15 ( V_47 ) ;
if ( V_57 ) {
if ( F_1 ( V_1 ,
V_63 ) ) {
V_34 = F_3 ( V_1 ,
V_63 ,
V_5 ) ;
V_34 -> V_57 = F_16 ( V_57 ) ;
}
}
break;
}
case F_13 ( V_64 ) :
case F_13 ( V_65 ) : {
const struct V_66 * V_67 ;
struct V_66 V_68 ;
V_67 = F_9 ( V_15 , V_24 , sizeof( V_68 ) , V_18 , V_19 , & V_68 ) ;
if ( ! V_67 )
return false ;
if ( F_1 ( V_1 ,
V_69 ) ) {
V_34 = F_3 ( V_1 ,
V_69 ,
V_5 ) ;
V_34 -> V_70 = F_17 ( V_15 ) ;
}
V_23 = V_67 -> V_71 ;
V_24 += sizeof( * V_67 ) ;
goto V_44;
}
case F_13 ( V_72 ) : {
struct {
struct V_73 V_74 ;
T_3 V_23 ;
} * V_74 , V_75 ;
V_74 = F_9 ( V_15 , V_24 , sizeof( V_75 ) , V_18 , V_19 , & V_75 ) ;
if ( ! V_74 )
return false ;
V_23 = V_74 -> V_23 ;
V_24 += V_76 ;
switch ( V_23 ) {
case F_13 ( V_77 ) :
goto V_49;
case F_13 ( V_78 ) :
goto V_58;
default:
return false ;
}
}
case F_13 ( V_79 ) : {
struct {
T_1 V_80 [ 3 ] ;
T_1 V_81 ;
} * V_74 , V_75 ;
V_74 = F_9 ( V_15 , V_24 , sizeof( V_75 ) , V_18 , V_19 , & V_75 ) ;
if ( ! V_74 )
return false ;
V_28 -> V_82 = V_23 ;
V_26 -> V_16 = ( V_83 ) V_24 ;
if ( F_1 ( V_1 ,
V_84 ) ) {
V_30 = F_3 ( V_1 ,
V_84 ,
V_5 ) ;
V_30 -> V_85 . V_81 = V_74 -> V_81 ;
V_26 -> V_54 = V_84 ;
}
return true ;
}
case F_13 ( V_86 ) :
case F_13 ( V_87 ) : {
struct V_88 * V_74 , V_75 [ 2 ] ;
V_89:
V_74 = F_9 ( V_15 , V_24 , sizeof( V_75 ) , V_18 ,
V_19 , & V_75 ) ;
if ( ! V_74 )
return false ;
if ( ( F_16 ( V_74 [ 0 ] . V_90 ) & V_91 ) >>
V_92 == V_93 ) {
if ( F_1 ( V_1 ,
V_94 ) ) {
V_36 = F_3 ( V_1 ,
V_94 ,
V_5 ) ;
V_36 -> V_95 = V_74 [ 1 ] . V_90 &
F_18 ( V_91 ) ;
}
V_28 -> V_82 = V_23 ;
V_28 -> V_17 = V_17 ;
V_26 -> V_16 = ( V_83 ) V_24 ;
return true ;
}
return true ;
}
case F_13 ( V_96 ) :
V_26 -> V_16 = ( V_83 ) ( V_24 + V_97 ) ;
default:
return false ;
}
V_98:
switch ( V_17 ) {
case V_99 : {
struct V_100 {
T_3 V_101 ;
T_3 V_23 ;
} * V_74 , V_75 ;
V_74 = F_9 ( V_15 , V_24 , sizeof( V_75 ) , V_18 , V_19 , & V_75 ) ;
if ( ! V_74 )
return false ;
if ( V_74 -> V_101 & ( V_102 | V_103 ) )
break;
V_23 = V_74 -> V_23 ;
V_24 += 4 ;
if ( V_74 -> V_101 & V_104 )
V_24 += 4 ;
if ( V_74 -> V_101 & V_105 ) {
const T_1 * V_95 ;
T_1 V_106 ;
V_95 = F_9 ( V_15 , V_24 , sizeof( V_106 ) ,
V_18 , V_19 , & V_106 ) ;
if ( ! V_95 )
return false ;
if ( F_1 ( V_1 ,
V_107 ) ) {
V_36 = F_3 ( V_1 ,
V_107 ,
V_5 ) ;
V_36 -> V_95 = * V_95 ;
}
V_24 += 4 ;
}
if ( V_74 -> V_101 & V_108 )
V_24 += 4 ;
if ( V_23 == F_13 ( V_109 ) ) {
const struct V_39 * V_40 ;
struct V_39 V_110 ;
V_40 = F_9 ( V_15 , V_24 ,
sizeof( V_110 ) ,
V_18 , V_19 , & V_110 ) ;
if ( ! V_40 )
return false ;
V_23 = V_40 -> V_111 ;
V_24 += sizeof( * V_40 ) ;
}
goto V_44;
}
case V_112 :
case V_113 :
case V_114 : {
T_2 V_115 [ 2 ] , * V_116 ;
if ( V_23 != F_13 ( V_55 ) )
break;
V_116 = F_9 ( V_15 , V_24 , sizeof( V_115 ) ,
V_18 , V_19 , & V_115 ) ;
if ( ! V_116 )
return false ;
V_17 = V_116 [ 0 ] ;
V_24 += ( V_116 [ 1 ] + 1 ) << 3 ;
goto V_98;
}
case V_117 :
V_23 = F_13 ( V_45 ) ;
goto V_49;
case V_118 :
V_23 = F_13 ( V_55 ) ;
goto V_58;
case V_119 :
V_23 = F_13 ( V_86 ) ;
goto V_89;
default:
break;
}
V_28 -> V_82 = V_23 ;
V_28 -> V_17 = V_17 ;
V_26 -> V_16 = ( V_83 ) V_24 ;
if ( F_1 ( V_1 ,
V_120 ) ) {
V_32 = F_3 ( V_1 ,
V_120 ,
V_5 ) ;
V_32 -> V_21 = F_6 ( V_15 , V_24 , V_17 ,
V_18 , V_19 ) ;
}
return true ;
}
static T_4 void F_19 ( void )
{
F_20 ( & V_121 , sizeof( V_121 ) ) ;
}
static T_4 T_5 F_21 ( T_5 * V_122 , T_5 V_123 , T_5 V_124 )
{
return F_22 ( V_122 , V_123 , V_124 ) ;
}
static inline void * F_23 ( struct V_125 * V_126 )
{
F_24 ( V_127 % sizeof( T_5 ) ) ;
return ( void * ) V_126 + V_127 ;
}
static inline T_6 F_25 ( struct V_125 * V_126 )
{
T_6 V_128 = V_127 + sizeof( V_126 -> V_129 ) ;
F_24 ( ( sizeof( * V_126 ) - V_127 ) % sizeof( T_5 ) ) ;
F_24 ( F_26 ( F_27 ( * V_126 ) , V_129 ) !=
sizeof( * V_126 ) - sizeof( V_126 -> V_129 ) ) ;
switch ( V_126 -> V_130 . V_54 ) {
case V_51 :
V_128 -= sizeof( V_126 -> V_129 . V_52 ) ;
break;
case V_60 :
V_128 -= sizeof( V_126 -> V_129 . V_131 ) ;
break;
case V_84 :
V_128 -= sizeof( V_126 -> V_129 . V_85 ) ;
break;
}
return ( sizeof( * V_126 ) - V_128 ) / sizeof( T_5 ) ;
}
T_1 F_28 ( const struct V_125 * V_126 )
{
switch ( V_126 -> V_130 . V_54 ) {
case V_51 :
return V_126 -> V_129 . V_52 . V_132 ;
case V_60 :
return ( V_133 T_1 ) F_29 (
& V_126 -> V_129 . V_131 . V_132 ) ;
case V_84 :
return V_126 -> V_129 . V_85 . V_81 ;
default:
return 0 ;
}
}
T_1 F_30 ( const struct V_125 * V_126 )
{
switch ( V_126 -> V_130 . V_54 ) {
case V_51 :
return V_126 -> V_129 . V_52 . V_134 ;
case V_60 :
return ( V_133 T_1 ) F_29 (
& V_126 -> V_129 . V_131 . V_134 ) ;
default:
return 0 ;
}
}
static inline void F_31 ( struct V_125 * V_135 )
{
int V_136 , V_10 ;
switch ( V_135 -> V_130 . V_54 ) {
case V_51 :
V_136 = ( V_133 T_5 ) V_135 -> V_129 . V_52 . V_134 -
( V_133 T_5 ) V_135 -> V_129 . V_52 . V_132 ;
if ( ( V_136 < 0 ) ||
( V_136 == 0 &&
( ( V_133 V_83 ) V_135 -> V_21 . V_134 <
( V_133 V_83 ) V_135 -> V_21 . V_132 ) ) ) {
F_32 ( V_135 -> V_129 . V_52 . V_132 , V_135 -> V_129 . V_52 . V_134 ) ;
F_32 ( V_135 -> V_21 . V_132 , V_135 -> V_21 . V_134 ) ;
}
break;
case V_60 :
V_136 = memcmp ( & V_135 -> V_129 . V_131 . V_134 ,
& V_135 -> V_129 . V_131 . V_132 ,
sizeof( V_135 -> V_129 . V_131 . V_134 ) ) ;
if ( ( V_136 < 0 ) ||
( V_136 == 0 &&
( ( V_133 V_83 ) V_135 -> V_21 . V_134 <
( V_133 V_83 ) V_135 -> V_21 . V_132 ) ) ) {
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
F_32 ( V_135 -> V_129 . V_131 . V_132 . V_137 [ V_10 ] ,
V_135 -> V_129 . V_131 . V_134 . V_137 [ V_10 ] ) ;
F_32 ( V_135 -> V_21 . V_132 , V_135 -> V_21 . V_134 ) ;
}
break;
}
}
static inline T_5 F_33 ( struct V_125 * V_135 , T_5 V_124 )
{
T_5 V_138 ;
F_31 ( V_135 ) ;
V_138 = F_21 ( ( T_5 * ) F_23 ( V_135 ) ,
F_25 ( V_135 ) , V_124 ) ;
if ( ! V_138 )
V_138 = 1 ;
return V_138 ;
}
T_5 F_34 ( struct V_125 * V_135 )
{
F_19 () ;
return F_33 ( V_135 , V_121 ) ;
}
static inline T_5 F_35 ( const struct V_14 * V_15 ,
struct V_125 * V_135 , T_5 V_124 )
{
if ( ! F_36 ( V_15 , V_135 ) )
return 0 ;
return F_33 ( V_135 , V_124 ) ;
}
void F_37 ( struct V_139 * V_140 ,
const struct V_125 * V_126 )
{
struct V_141 * V_18 =
(struct V_141 * ) V_140 ;
F_24 ( sizeof( * V_18 ) > sizeof( * V_140 ) ) ;
memset ( V_140 , 0 , sizeof( * V_140 ) ) ;
V_18 -> V_82 = V_126 -> V_142 . V_82 ;
V_18 -> V_17 = V_126 -> V_142 . V_17 ;
V_18 -> V_21 = V_126 -> V_21 . V_21 ;
V_18 -> V_132 = V_126 -> V_129 . V_52 . V_132 ;
V_18 -> V_134 = V_126 -> V_129 . V_52 . V_134 ;
}
void F_38 ( struct V_14 * V_15 )
{
struct V_125 V_135 ;
T_5 V_138 ;
F_19 () ;
V_138 = F_35 ( V_15 , & V_135 , V_121 ) ;
if ( ! V_138 )
return;
if ( V_135 . V_21 . V_21 )
V_15 -> V_143 = 1 ;
V_15 -> V_144 = 1 ;
V_15 -> V_138 = V_138 ;
}
T_7 F_39 ( const struct V_14 * V_15 , T_5 V_145 )
{
struct V_125 V_135 ;
return F_35 ( V_15 , & V_135 , V_145 ) ;
}
T_5 F_40 ( const struct V_14 * V_15 , void * V_18 ,
const struct V_125 * V_135 , int V_19 )
{
T_5 V_20 = V_135 -> V_130 . V_16 ;
switch ( V_135 -> V_142 . V_17 ) {
case V_146 : {
const T_2 * V_147 ;
T_2 V_148 ;
V_147 = F_9 ( V_15 , V_20 + 12 , sizeof( V_148 ) ,
V_18 , V_19 , & V_148 ) ;
if ( ! V_147 )
return V_20 ;
V_20 += F_41 ( T_5 , sizeof( struct V_149 ) , ( * V_147 & 0xF0 ) >> 2 ) ;
break;
}
case V_150 :
case V_151 :
V_20 += sizeof( struct V_152 ) ;
break;
case V_153 :
V_20 += sizeof( struct V_154 ) ;
break;
case V_155 :
V_20 += sizeof( struct V_156 ) ;
break;
case V_157 :
V_20 += sizeof( struct V_158 ) ;
break;
case V_159 :
V_20 += sizeof( struct V_160 ) ;
break;
case V_161 :
V_20 += sizeof( struct V_162 ) ;
break;
}
return V_20 ;
}
T_5 F_42 ( const struct V_14 * V_15 )
{
struct V_125 V_135 ;
if ( ! F_36 ( V_15 , & V_135 ) )
return 0 ;
return F_40 ( V_15 , V_15 -> V_18 , & V_135 , F_8 ( V_15 ) ) ;
}
static int T_8 F_43 ( void )
{
F_4 ( & V_163 ,
V_164 ,
F_44 ( V_164 ) ) ;
F_4 ( & V_165 ,
V_166 ,
F_44 ( V_166 ) ) ;
return 0 ;
}
