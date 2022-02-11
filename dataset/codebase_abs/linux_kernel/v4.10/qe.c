T_1 F_1 ( void )
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
if ( V_34 )
return V_34 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_34 ;
}
V_33 = F_19 ( V_2 , L_4 , & V_32 ) ;
if ( V_33 && V_32 == sizeof( * V_33 ) )
V_34 = * V_33 ;
F_5 ( V_2 ) ;
return V_34 ;
}
int F_20 ( enum V_35 V_36 , unsigned int V_37 , unsigned int V_38 )
{
T_2 V_39 , V_40 ;
T_2 V_41 = 0 ;
if ( ( V_36 < V_42 ) || ( V_36 > V_43 ) )
return - V_44 ;
V_39 = F_18 () / ( V_37 * V_38 ) ;
if ( V_39 > V_45 + 1 ) {
V_41 = V_46 ;
V_39 /= 16 ;
}
if ( ! V_41 && ( V_39 & 1 ) && ( V_39 > 3 ) )
V_39 ++ ;
V_40 = ( ( V_39 - 1 ) << V_47 ) |
V_48 | V_41 ;
F_14 ( & V_8 -> V_36 . V_49 [ V_36 - V_42 ] , V_40 ) ;
return 0 ;
}
enum V_35 F_21 ( const char * V_50 )
{
unsigned int V_51 ;
if ( strcasecmp ( V_50 , L_5 ) == 0 )
return V_52 ;
if ( strcmp ( V_50 , L_6 ) == 0 )
return V_53 ;
if ( strcmp ( V_50 , L_7 ) == 0 )
return V_54 ;
if ( strncasecmp ( V_50 , L_8 , 3 ) == 0 ) {
V_51 = F_22 ( V_50 + 3 , NULL , 10 ) ;
if ( ( V_51 >= 1 ) && ( V_51 <= 16 ) )
return ( V_42 - 1 ) + V_51 ;
else
return V_55 ;
}
if ( strncasecmp ( V_50 , L_9 , 3 ) == 0 ) {
V_51 = F_22 ( V_50 + 3 , NULL , 10 ) ;
if ( ( V_51 >= 1 ) && ( V_51 <= 24 ) )
return ( V_56 - 1 ) + V_51 ;
else
return V_55 ;
}
return V_55 ;
}
static void F_8 ( void )
{
int V_51 ;
static const T_3 V_57 [] = {
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
static const T_3 V_58 [] = {
0x04 , 0x05 , 0x0C , 0x0D , 0x14 , 0x15 , 0x1C , 0x1D ,
0x24 , 0x25 , 0x2C , 0x2D , 0x34 , 0x35 , 0x88 , 0x89 ,
0x98 , 0x99 , 0xA8 , 0xA9 , 0xB8 , 0xB9 , 0xC8 , 0xC9 ,
0xD8 , 0xD9 , 0xE8 , 0xE9 , 0x08 , 0x09 , 0x18 , 0x19 ,
0x28 , 0x29 , 0x38 , 0x39 , 0x48 , 0x49 , 0x58 , 0x59 ,
0x68 , 0x69 , 0x78 , 0x79 , 0x80 , 0x81 ,
} ;
static const T_3 * V_59 ;
V_60 = F_23 () ;
if ( V_60 == 76 )
V_59 = V_57 ;
else
V_59 = V_58 ;
for ( V_51 = 0 ; V_51 < V_60 ; V_51 ++ ) {
V_61 [ V_51 ] . V_62 = V_59 [ V_51 ] ;
V_61 [ V_51 ] . V_63 = V_64 ;
}
}
int F_24 ( void )
{
unsigned long V_17 ;
int V_65 = - V_66 ;
int V_51 ;
F_13 ( & V_20 , V_17 ) ;
for ( V_51 = 0 ; V_51 < V_60 ; V_51 ++ ) {
if ( V_61 [ V_51 ] . V_63 == V_64 ) {
V_61 [ V_51 ] . V_63 = V_67 ;
V_65 = V_61 [ V_51 ] . V_62 ;
break;
}
}
F_17 ( & V_20 , V_17 ) ;
return V_65 ;
}
void F_25 ( T_3 V_65 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_60 ; V_51 ++ ) {
if ( V_61 [ V_51 ] . V_62 == V_65 ) {
V_61 [ V_51 ] . V_63 = V_64 ;
break;
}
}
}
static int F_11 ( void )
{
struct V_68 T_4 * V_68 = & V_8 -> V_68 ;
static unsigned long V_69 = ( unsigned long ) - V_70 ;
if ( ! V_68 )
return - V_71 ;
if ( F_26 ( V_69 ) ) {
V_69 = F_27 ( 512 * 2 , 4096 ) ;
if ( F_26 ( V_69 ) )
return - V_70 ;
}
F_14 ( & V_68 -> V_72 , ( T_2 ) V_69 & V_73 ) ;
F_14 ( & V_68 -> V_74 , ( V_75 |
( 0x1 << V_76 ) ) ) ;
return 0 ;
}
static void F_28 ( const void * V_77 ,
const struct V_78 * V_79 )
{
const T_5 * V_80 = V_77 + F_29 ( V_79 -> V_81 ) ;
unsigned int V_51 ;
if ( V_79 -> V_82 || V_79 -> V_83 || V_79 -> V_84 )
F_30 ( V_85 L_10
L_11 ,
V_79 -> V_86 , V_79 -> V_82 , V_79 -> V_83 , V_79 -> V_84 ) ;
else
F_30 ( V_85 L_10
L_12 , V_79 -> V_86 ) ;
F_14 ( & V_8 -> V_87 . V_88 , F_29 ( V_79 -> V_89 ) |
V_90 | V_91 ) ;
for ( V_51 = 0 ; V_51 < F_29 ( V_79 -> V_92 ) ; V_51 ++ )
F_14 ( & V_8 -> V_87 . V_93 , F_29 ( V_80 [ V_51 ] ) ) ;
F_14 ( & V_8 -> V_87 . V_94 , F_29 ( V_95 ) ) ;
}
int F_31 ( const struct V_96 * V_97 )
{
unsigned int V_51 ;
unsigned int V_98 ;
T_2 V_99 ;
T_6 V_100 = sizeof( struct V_96 ) ;
T_6 V_101 ;
const struct V_102 * V_103 ;
if ( ! V_97 ) {
F_30 ( V_104 L_13 ) ;
return - V_44 ;
}
V_103 = & V_97 -> V_105 ;
V_101 = F_29 ( V_103 -> V_101 ) ;
if ( ( V_103 -> V_106 [ 0 ] != 'Q' ) || ( V_103 -> V_106 [ 1 ] != 'E' ) ||
( V_103 -> V_106 [ 2 ] != 'F' ) ) {
F_30 ( V_104 L_14 ) ;
return - V_107 ;
}
if ( V_103 -> V_108 != 1 ) {
F_30 ( V_104 L_15 ) ;
return - V_107 ;
}
if ( ( V_97 -> V_92 < 1 ) || ( V_97 -> V_92 > V_109 ) ) {
F_30 ( V_104 L_16 ) ;
return - V_44 ;
}
V_100 += ( V_97 -> V_92 - 1 ) * sizeof( struct V_78 ) ;
for ( V_51 = 0 ; V_51 < V_97 -> V_92 ; V_51 ++ )
V_100 += sizeof( T_5 ) *
F_29 ( V_97 -> V_110 [ V_51 ] . V_92 ) ;
if ( V_101 != V_100 + sizeof( T_5 ) ) {
F_30 ( V_104 L_17 ) ;
return - V_107 ;
}
V_99 = F_29 ( * ( T_5 * ) ( ( void * ) V_97 + V_100 ) ) ;
if ( V_99 != F_32 ( 0 , V_97 , V_100 ) ) {
F_30 ( V_104 L_18 ) ;
return - V_111 ;
}
if ( ! V_97 -> V_112 )
F_33 ( & V_8 -> V_21 . V_113 , V_114 ) ;
if ( V_97 -> V_115 . V_116 )
F_30 ( V_85
L_19 ,
V_97 -> V_86 , F_34 ( V_97 -> V_115 . V_116 ) ,
V_97 -> V_115 . V_82 , V_97 -> V_115 . V_83 ) ;
else
F_30 ( V_85 L_20 ,
V_97 -> V_86 ) ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
F_35 ( V_117 . V_86 , V_97 -> V_86 , sizeof( V_117 . V_86 ) ) ;
V_117 . V_118 = V_97 -> V_118 ;
memcpy ( V_117 . V_119 , V_97 -> V_119 ,
sizeof( V_97 -> V_119 ) ) ;
for ( V_51 = 0 ; V_51 < V_97 -> V_92 ; V_51 ++ ) {
const struct V_78 * V_79 = & V_97 -> V_110 [ V_51 ] ;
if ( V_79 -> V_81 )
F_28 ( V_97 , V_79 ) ;
for ( V_98 = 0 ; V_98 < 16 ; V_98 ++ ) {
T_2 V_120 = F_29 ( V_79 -> V_121 [ V_98 ] ) ;
if ( V_120 )
F_14 ( & V_8 -> V_122 [ V_51 ] . V_123 [ V_98 ] , V_120 ) ;
}
F_14 ( & V_8 -> V_122 [ V_51 ] . V_124 , F_29 ( V_79 -> V_124 ) ) ;
}
V_125 = 1 ;
return 0 ;
}
struct V_117 * F_36 ( void )
{
static int V_126 ;
struct V_127 * V_33 ;
struct V_1 * V_2 ;
struct V_1 * V_128 = NULL ;
const char * V_129 ;
unsigned int V_51 ;
if ( V_125 )
return & V_117 ;
if ( V_126 )
return NULL ;
V_126 = 1 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return NULL ;
}
F_37 (qe, fw) {
if ( strcmp ( V_128 -> V_130 , L_21 ) == 0 )
break;
}
F_5 ( V_2 ) ;
if ( ! V_128 )
return NULL ;
V_125 = 1 ;
V_129 = F_19 ( V_128 , L_22 , NULL ) ;
if ( V_129 )
F_35 ( V_117 . V_86 , V_129 ,
sizeof( V_117 . V_86 ) ) ;
V_33 = F_38 ( V_128 , L_23 , NULL ) ;
if ( V_33 && ( V_33 -> V_101 == sizeof( V_131 ) ) ) {
const V_131 * V_132 = V_33 -> V_133 ;
V_117 . V_118 = * V_132 ;
}
V_33 = F_38 ( V_128 , L_24 , NULL ) ;
if ( V_33 && ( V_33 -> V_101 == 32 ) ) {
const T_2 * V_132 = V_33 -> V_133 ;
for ( V_51 = 0 ; V_51 < F_39 ( V_117 . V_119 ) ; V_51 ++ )
V_117 . V_119 [ V_51 ] = V_132 [ V_51 ] ;
}
F_5 ( V_128 ) ;
return & V_117 ;
}
unsigned int F_40 ( void )
{
struct V_1 * V_2 ;
int V_32 ;
unsigned int V_134 = 0 ;
const T_2 * V_33 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_134 ;
}
V_33 = F_19 ( V_2 , L_25 , & V_32 ) ;
if ( V_33 && V_32 == sizeof( * V_33 ) )
V_134 = * V_33 ;
F_5 ( V_2 ) ;
return V_134 ;
}
unsigned int F_23 ( void )
{
struct V_1 * V_2 ;
int V_32 ;
unsigned int V_135 ;
const T_2 * V_33 ;
V_135 = 28 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_135 ;
}
V_33 = F_19 ( V_2 , L_26 , & V_32 ) ;
if ( V_33 && V_32 == sizeof( * V_33 ) ) {
V_135 = * V_33 ;
if ( ( V_135 < 28 ) || ( V_135 > V_136 ) ) {
F_41 ( L_27 ) ;
F_5 ( V_2 ) ;
return - V_44 ;
}
}
F_5 ( V_2 ) ;
return V_135 ;
}
static int T_7 F_42 ( void )
{
struct V_1 * V_137 ;
V_137 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_137 )
return - V_71 ;
F_6 () ;
F_5 ( V_137 ) ;
return 0 ;
}
static int F_43 ( struct V_138 * V_139 )
{
if ( ! F_44 () )
F_6 () ;
return 0 ;
}
static int F_45 ( struct V_138 * V_139 )
{
return 0 ;
}
