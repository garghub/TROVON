static T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
struct V_4 V_5 ;
if ( V_6 != - 1 )
return V_6 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_6 ;
}
V_3 = F_4 ( V_2 , 0 , & V_5 ) ;
if ( ! V_3 )
V_6 = V_5 . V_7 ;
F_5 ( V_2 ) ;
return V_6 ;
}
void F_6 ( void )
{
if ( V_8 == NULL )
V_8 = F_7 ( F_1 () , V_9 ) ;
F_8 () ;
F_9 ( V_10 , V_11 ,
V_12 , 0 ) ;
F_10 () ;
if ( F_11 () )
F_12 ( L_3 ) ;
}
int F_9 ( T_2 V_13 , T_2 V_14 , T_3 V_15 , T_2 V_16 )
{
unsigned long V_17 ;
T_3 V_18 = 0 , V_19 = 0 ;
T_2 V_3 ;
F_13 ( & V_20 , V_17 ) ;
if ( V_13 == V_10 ) {
F_14 ( & V_8 -> V_21 . V_22 , ( T_2 ) ( V_13 | V_23 ) ) ;
} else {
if ( V_13 == V_24 ) {
V_19 = V_25 ;
} else if ( V_13 == V_26 ) {
V_19 = V_25 ;
V_18 = V_27 ;
} else {
if ( V_14 == V_28 )
V_18 = V_29 ;
else
V_18 = V_30 ;
}
F_14 ( & V_8 -> V_21 . V_31 , V_16 ) ;
F_14 ( & V_8 -> V_21 . V_22 ,
( V_13 | V_23 | ( ( T_2 ) V_14 << V_19 ) | ( T_2 )
V_15 << V_18 ) ) ;
}
V_3 = F_15 ( ( F_16 ( & V_8 -> V_21 . V_22 ) & V_23 ) == 0 ,
100 , 0 ) ;
F_17 ( & V_20 , V_17 ) ;
return V_3 == 1 ;
}
unsigned int F_18 ( void )
{
struct V_1 * V_2 ;
int V_32 ;
const T_2 * V_33 ;
unsigned int V_34 ;
if ( V_35 )
return V_35 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_35 ;
}
V_33 = F_19 ( V_2 , L_4 , & V_32 ) ;
if ( V_33 && V_32 == sizeof( * V_33 ) )
V_35 = * V_33 ;
F_5 ( V_2 ) ;
V_34 = V_35 % V_36 ;
if ( V_34 ) {
if ( V_34 < V_37 )
V_35 -= V_34 ;
else if ( V_34 > ( V_36 - V_37 ) )
V_35 += V_36 - V_34 ;
}
return V_35 ;
}
int F_20 ( enum V_38 V_39 , unsigned int V_40 , unsigned int V_41 )
{
T_2 V_42 , V_43 ;
T_2 V_44 = 0 ;
if ( ( V_39 < V_45 ) || ( V_39 > V_46 ) )
return - V_47 ;
V_42 = F_18 () / ( V_40 * V_41 ) ;
if ( V_42 > V_48 + 1 ) {
V_44 = V_49 ;
V_42 /= 16 ;
}
if ( F_21 ( V_50 ) || F_21 ( V_51 ) )
if ( ! V_44 && ( V_42 & 1 ) && ( V_42 > 3 ) )
V_42 ++ ;
V_43 = ( ( V_42 - 1 ) << V_52 ) |
V_53 | V_44 ;
F_14 ( & V_8 -> V_39 . V_54 [ V_39 - V_45 ] , V_43 ) ;
return 0 ;
}
enum V_38 F_22 ( const char * V_55 )
{
unsigned int V_56 ;
if ( strcasecmp ( V_55 , L_5 ) == 0 )
return V_57 ;
if ( strcmp ( V_55 , L_6 ) == 0 )
return V_58 ;
if ( strcmp ( V_55 , L_7 ) == 0 )
return V_59 ;
if ( strncasecmp ( V_55 , L_8 , 3 ) == 0 ) {
V_56 = F_23 ( V_55 + 3 , NULL , 10 ) ;
if ( ( V_56 >= 1 ) && ( V_56 <= 16 ) )
return ( V_45 - 1 ) + V_56 ;
else
return V_60 ;
}
if ( strncasecmp ( V_55 , L_9 , 3 ) == 0 ) {
V_56 = F_23 ( V_55 + 3 , NULL , 10 ) ;
if ( ( V_56 >= 1 ) && ( V_56 <= 24 ) )
return ( V_61 - 1 ) + V_56 ;
else
return V_60 ;
}
return V_60 ;
}
static void F_8 ( void )
{
int V_56 ;
static const T_3 V_62 [] = {
0x04 , 0x05 , 0x0C , 0x0D , 0x14 , 0x15 , 0x1C , 0x1D ,
0x24 , 0x25 , 0x2C , 0x2D , 0x34 , 0x35 , 0x88 , 0x89 ,
0x98 , 0x99 , 0xA8 , 0xA9 , 0xB8 , 0xB9 , 0xC8 , 0xC9 ,
0xD8 , 0xD9 , 0xE8 , 0xE9 , 0x44 , 0x45 , 0x4C , 0x4D ,
0x54 , 0x55 , 0x5C , 0x5D , 0x64 , 0x65 , 0x6C , 0x6D ,
0x74 , 0x75 , 0x7C , 0x7D , 0x84 , 0x85 , 0x8C , 0x8D ,
0x94 , 0x95 , 0x9C , 0x9D , 0xA4 , 0xA5 , 0xAC , 0xAD ,
0xB4 , 0xB5 , 0xBC , 0xBD , 0xC4 , 0xC5 , 0xCC , 0xCD ,
0xD4 , 0xD5 , 0xDC , 0xDD , 0xE4 , 0xE5 , 0xEC , 0xED ,
0xF4 , 0xF5 , 0xFC , 0xFD ,
} ;
static const T_3 V_63 [] = {
0x04 , 0x05 , 0x0C , 0x0D , 0x14 , 0x15 , 0x1C , 0x1D ,
0x24 , 0x25 , 0x2C , 0x2D , 0x34 , 0x35 , 0x88 , 0x89 ,
0x98 , 0x99 , 0xA8 , 0xA9 , 0xB8 , 0xB9 , 0xC8 , 0xC9 ,
0xD8 , 0xD9 , 0xE8 , 0xE9 , 0x08 , 0x09 , 0x18 , 0x19 ,
0x28 , 0x29 , 0x38 , 0x39 , 0x48 , 0x49 , 0x58 , 0x59 ,
0x68 , 0x69 , 0x78 , 0x79 , 0x80 , 0x81 ,
} ;
static const T_3 * V_64 ;
V_65 = F_24 () ;
if ( V_65 == 76 )
V_64 = V_62 ;
else
V_64 = V_63 ;
for ( V_56 = 0 ; V_56 < V_65 ; V_56 ++ ) {
V_66 [ V_56 ] . V_67 = V_64 [ V_56 ] ;
V_66 [ V_56 ] . V_68 = V_69 ;
}
}
int F_25 ( void )
{
unsigned long V_17 ;
int V_70 = - V_71 ;
int V_56 ;
F_13 ( & V_20 , V_17 ) ;
for ( V_56 = 0 ; V_56 < V_65 ; V_56 ++ ) {
if ( V_66 [ V_56 ] . V_68 == V_69 ) {
V_66 [ V_56 ] . V_68 = V_72 ;
V_70 = V_66 [ V_56 ] . V_67 ;
break;
}
}
F_17 ( & V_20 , V_17 ) ;
return V_70 ;
}
void F_26 ( T_3 V_70 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_65 ; V_56 ++ ) {
if ( V_66 [ V_56 ] . V_67 == V_70 ) {
V_66 [ V_56 ] . V_68 = V_69 ;
break;
}
}
}
static int F_11 ( void )
{
struct V_73 T_4 * V_73 = & V_8 -> V_73 ;
static unsigned long V_74 = ( unsigned long ) - V_75 ;
if ( ! V_73 )
return - V_76 ;
if ( F_27 ( V_74 ) ) {
V_74 = F_28 ( 512 * 2 , 4096 ) ;
if ( F_27 ( V_74 ) )
return - V_75 ;
}
F_14 ( & V_73 -> V_77 , ( T_2 ) V_74 & V_78 ) ;
F_14 ( & V_73 -> V_79 , ( V_80 |
( 0x1 << V_81 ) ) ) ;
return 0 ;
}
static void F_29 ( const void * V_82 ,
const struct V_83 * V_84 )
{
const T_5 * V_85 = V_82 + F_30 ( V_84 -> V_86 ) ;
unsigned int V_56 ;
if ( V_84 -> V_87 || V_84 -> V_88 || V_84 -> V_89 )
F_31 ( V_90 L_10
L_11 ,
V_84 -> V_91 , V_84 -> V_87 , V_84 -> V_88 , V_84 -> V_89 ) ;
else
F_31 ( V_90 L_10
L_12 , V_84 -> V_91 ) ;
F_14 ( & V_8 -> V_92 . V_93 , F_30 ( V_84 -> V_94 ) |
V_95 | V_96 ) ;
for ( V_56 = 0 ; V_56 < F_30 ( V_84 -> V_97 ) ; V_56 ++ )
F_14 ( & V_8 -> V_92 . V_98 , F_30 ( V_85 [ V_56 ] ) ) ;
F_14 ( & V_8 -> V_92 . V_99 , F_30 ( V_100 ) ) ;
}
int F_32 ( const struct V_101 * V_102 )
{
unsigned int V_56 ;
unsigned int V_103 ;
T_2 V_104 ;
T_6 V_105 = sizeof( struct V_101 ) ;
T_6 V_106 ;
const struct V_107 * V_108 ;
if ( ! V_102 ) {
F_31 ( V_109 L_13 ) ;
return - V_47 ;
}
V_108 = & V_102 -> V_110 ;
V_106 = F_30 ( V_108 -> V_106 ) ;
if ( ( V_108 -> V_111 [ 0 ] != 'Q' ) || ( V_108 -> V_111 [ 1 ] != 'E' ) ||
( V_108 -> V_111 [ 2 ] != 'F' ) ) {
F_31 ( V_109 L_14 ) ;
return - V_112 ;
}
if ( V_108 -> V_113 != 1 ) {
F_31 ( V_109 L_15 ) ;
return - V_112 ;
}
if ( ( V_102 -> V_97 < 1 ) || ( V_102 -> V_97 > V_114 ) ) {
F_31 ( V_109 L_16 ) ;
return - V_47 ;
}
V_105 += ( V_102 -> V_97 - 1 ) * sizeof( struct V_83 ) ;
for ( V_56 = 0 ; V_56 < V_102 -> V_97 ; V_56 ++ )
V_105 += sizeof( T_5 ) *
F_30 ( V_102 -> V_115 [ V_56 ] . V_97 ) ;
if ( V_106 != V_105 + sizeof( T_5 ) ) {
F_31 ( V_109 L_17 ) ;
return - V_112 ;
}
V_104 = F_30 ( * ( T_5 * ) ( ( void * ) V_102 + V_105 ) ) ;
if ( V_104 != F_33 ( 0 , V_102 , V_105 ) ) {
F_31 ( V_109 L_18 ) ;
return - V_116 ;
}
if ( ! V_102 -> V_117 )
F_34 ( & V_8 -> V_21 . V_118 , V_119 ) ;
if ( V_102 -> V_120 . V_121 )
F_31 ( V_90
L_19 ,
V_102 -> V_91 , F_35 ( V_102 -> V_120 . V_121 ) ,
V_102 -> V_120 . V_87 , V_102 -> V_120 . V_88 ) ;
else
F_31 ( V_90 L_20 ,
V_102 -> V_91 ) ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
F_36 ( V_122 . V_91 , V_102 -> V_91 , sizeof( V_122 . V_91 ) ) ;
V_122 . V_123 = V_102 -> V_123 ;
memcpy ( V_122 . V_124 , V_102 -> V_124 ,
sizeof( V_102 -> V_124 ) ) ;
for ( V_56 = 0 ; V_56 < V_102 -> V_97 ; V_56 ++ ) {
const struct V_83 * V_84 = & V_102 -> V_115 [ V_56 ] ;
if ( V_84 -> V_86 )
F_29 ( V_102 , V_84 ) ;
for ( V_103 = 0 ; V_103 < 16 ; V_103 ++ ) {
T_2 V_125 = F_30 ( V_84 -> V_126 [ V_103 ] ) ;
if ( V_125 )
F_14 ( & V_8 -> V_127 [ V_56 ] . V_128 [ V_103 ] , V_125 ) ;
}
F_14 ( & V_8 -> V_127 [ V_56 ] . V_129 , F_30 ( V_84 -> V_129 ) ) ;
}
V_130 = 1 ;
return 0 ;
}
struct V_122 * F_37 ( void )
{
static int V_131 ;
struct V_132 * V_33 ;
struct V_1 * V_2 ;
struct V_1 * V_133 = NULL ;
const char * V_134 ;
unsigned int V_56 ;
if ( V_130 )
return & V_122 ;
if ( V_131 )
return NULL ;
V_131 = 1 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return NULL ;
}
F_38 (qe, fw) {
if ( strcmp ( V_133 -> V_135 , L_21 ) == 0 )
break;
}
F_5 ( V_2 ) ;
if ( ! V_133 )
return NULL ;
V_130 = 1 ;
V_134 = F_19 ( V_133 , L_22 , NULL ) ;
if ( V_134 )
F_36 ( V_122 . V_91 , V_134 ,
sizeof( V_122 . V_91 ) ) ;
V_33 = F_39 ( V_133 , L_23 , NULL ) ;
if ( V_33 && ( V_33 -> V_106 == sizeof( V_136 ) ) ) {
const V_136 * V_137 = V_33 -> V_138 ;
V_122 . V_123 = * V_137 ;
}
V_33 = F_39 ( V_133 , L_24 , NULL ) ;
if ( V_33 && ( V_33 -> V_106 == 32 ) ) {
const T_2 * V_137 = V_33 -> V_138 ;
for ( V_56 = 0 ; V_56 < F_40 ( V_122 . V_124 ) ; V_56 ++ )
V_122 . V_124 [ V_56 ] = V_137 [ V_56 ] ;
}
F_5 ( V_133 ) ;
return & V_122 ;
}
unsigned int F_41 ( void )
{
struct V_1 * V_2 ;
int V_32 ;
unsigned int V_139 = 0 ;
const T_2 * V_33 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_139 ;
}
V_33 = F_19 ( V_2 , L_25 , & V_32 ) ;
if ( V_33 && V_32 == sizeof( * V_33 ) )
V_139 = * V_33 ;
F_5 ( V_2 ) ;
return V_139 ;
}
unsigned int F_24 ( void )
{
struct V_1 * V_2 ;
int V_32 ;
unsigned int V_140 ;
const T_2 * V_33 ;
V_140 = 28 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_140 ;
}
V_33 = F_19 ( V_2 , L_26 , & V_32 ) ;
if ( V_33 && V_32 == sizeof( * V_33 ) ) {
V_140 = * V_33 ;
if ( ( V_140 < 28 ) || ( V_140 > V_141 ) ) {
F_42 ( L_27 ) ;
F_5 ( V_2 ) ;
return - V_47 ;
}
}
F_5 ( V_2 ) ;
return V_140 ;
}
static int T_7 F_43 ( void )
{
struct V_1 * V_142 ;
V_142 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_142 )
return - V_76 ;
F_6 () ;
F_5 ( V_142 ) ;
return 0 ;
}
static int F_44 ( struct V_143 * V_144 )
{
if ( ! F_45 () )
F_6 () ;
return 0 ;
}
static int F_46 ( struct V_143 * V_144 )
{
return 0 ;
}
