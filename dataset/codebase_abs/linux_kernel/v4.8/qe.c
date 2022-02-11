T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
const T_2 * V_4 ;
if ( V_5 != - 1 )
return V_5 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_5 ;
}
V_4 = F_4 ( V_2 , L_3 , & V_3 ) ;
if ( V_4 && V_3 >= sizeof( * V_4 ) )
V_5 = F_5 ( V_2 , V_4 ) ;
F_6 ( V_2 ) ;
return V_5 ;
}
void F_7 ( void )
{
if ( V_6 == NULL )
V_6 = F_8 ( F_1 () , V_7 ) ;
F_9 () ;
F_10 ( V_8 , V_9 ,
V_10 , 0 ) ;
F_11 () ;
if ( F_12 () )
F_13 ( L_4 ) ;
}
int F_10 ( T_2 V_11 , T_2 V_12 , T_3 V_13 , T_2 V_14 )
{
unsigned long V_15 ;
T_3 V_16 = 0 , V_17 = 0 ;
T_2 V_18 ;
F_14 ( & V_19 , V_15 ) ;
if ( V_11 == V_8 ) {
F_15 ( & V_6 -> V_20 . V_21 , ( T_2 ) ( V_11 | V_22 ) ) ;
} else {
if ( V_11 == V_23 ) {
V_17 = V_24 ;
} else if ( V_11 == V_25 ) {
V_17 = V_24 ;
V_16 = V_26 ;
} else {
if ( V_12 == V_27 )
V_16 = V_28 ;
else
V_16 = V_29 ;
}
F_15 ( & V_6 -> V_20 . V_30 , V_14 ) ;
F_15 ( & V_6 -> V_20 . V_21 ,
( V_11 | V_22 | ( ( T_2 ) V_12 << V_17 ) | ( T_2 )
V_13 << V_16 ) ) ;
}
V_18 = F_16 ( ( F_17 ( & V_6 -> V_20 . V_21 ) & V_22 ) == 0 ,
100 , 0 ) ;
F_18 ( & V_19 , V_15 ) ;
return V_18 == 1 ;
}
unsigned int F_19 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
const T_2 * V_4 ;
if ( V_31 )
return V_31 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_31 ;
}
V_4 = F_4 ( V_2 , L_5 , & V_3 ) ;
if ( V_4 && V_3 == sizeof( * V_4 ) )
V_31 = * V_4 ;
F_6 ( V_2 ) ;
return V_31 ;
}
int F_20 ( enum V_32 V_33 , unsigned int V_34 , unsigned int V_35 )
{
T_2 V_36 , V_37 ;
T_2 V_38 = 0 ;
if ( ( V_33 < V_39 ) || ( V_33 > V_40 ) )
return - V_41 ;
V_36 = F_19 () / ( V_34 * V_35 ) ;
if ( V_36 > V_42 + 1 ) {
V_38 = V_43 ;
V_36 /= 16 ;
}
if ( ! V_38 && ( V_36 & 1 ) && ( V_36 > 3 ) )
V_36 ++ ;
V_37 = ( ( V_36 - 1 ) << V_44 ) |
V_45 | V_38 ;
F_15 ( & V_6 -> V_33 . V_46 [ V_33 - V_39 ] , V_37 ) ;
return 0 ;
}
enum V_32 F_21 ( const char * V_47 )
{
unsigned int V_48 ;
if ( strcasecmp ( V_47 , L_6 ) == 0 )
return V_49 ;
if ( strcmp ( V_47 , L_7 ) == 0 )
return V_50 ;
if ( strcmp ( V_47 , L_8 ) == 0 )
return V_51 ;
if ( strncasecmp ( V_47 , L_9 , 3 ) == 0 ) {
V_48 = F_22 ( V_47 + 3 , NULL , 10 ) ;
if ( ( V_48 >= 1 ) && ( V_48 <= 16 ) )
return ( V_39 - 1 ) + V_48 ;
else
return V_52 ;
}
if ( strncasecmp ( V_47 , L_10 , 3 ) == 0 ) {
V_48 = F_22 ( V_47 + 3 , NULL , 10 ) ;
if ( ( V_48 >= 1 ) && ( V_48 <= 24 ) )
return ( V_53 - 1 ) + V_48 ;
else
return V_52 ;
}
return V_52 ;
}
static void F_9 ( void )
{
int V_48 ;
static const T_3 V_54 [] = {
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
static const T_3 V_55 [] = {
0x04 , 0x05 , 0x0C , 0x0D , 0x14 , 0x15 , 0x1C , 0x1D ,
0x24 , 0x25 , 0x2C , 0x2D , 0x34 , 0x35 , 0x88 , 0x89 ,
0x98 , 0x99 , 0xA8 , 0xA9 , 0xB8 , 0xB9 , 0xC8 , 0xC9 ,
0xD8 , 0xD9 , 0xE8 , 0xE9 , 0x08 , 0x09 , 0x18 , 0x19 ,
0x28 , 0x29 , 0x38 , 0x39 , 0x48 , 0x49 , 0x58 , 0x59 ,
0x68 , 0x69 , 0x78 , 0x79 , 0x80 , 0x81 ,
} ;
static const T_3 * V_56 ;
V_57 = F_23 () ;
if ( V_57 == 76 )
V_56 = V_54 ;
else
V_56 = V_55 ;
for ( V_48 = 0 ; V_48 < V_57 ; V_48 ++ ) {
V_58 [ V_48 ] . V_59 = V_56 [ V_48 ] ;
V_58 [ V_48 ] . V_60 = V_61 ;
}
}
int F_24 ( void )
{
unsigned long V_15 ;
int V_62 = - V_63 ;
int V_48 ;
F_14 ( & V_19 , V_15 ) ;
for ( V_48 = 0 ; V_48 < V_57 ; V_48 ++ ) {
if ( V_58 [ V_48 ] . V_60 == V_61 ) {
V_58 [ V_48 ] . V_60 = V_64 ;
V_62 = V_58 [ V_48 ] . V_59 ;
break;
}
}
F_18 ( & V_19 , V_15 ) ;
return V_62 ;
}
void F_25 ( T_3 V_62 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_57 ; V_48 ++ ) {
if ( V_58 [ V_48 ] . V_59 == V_62 ) {
V_58 [ V_48 ] . V_60 = V_61 ;
break;
}
}
}
static int F_12 ( void )
{
struct V_65 T_4 * V_65 = & V_6 -> V_65 ;
static unsigned long V_66 = ( unsigned long ) - V_67 ;
if ( ! V_65 )
return - V_68 ;
if ( F_26 ( V_66 ) ) {
V_66 = F_27 ( 512 * 2 , 4096 ) ;
if ( F_26 ( V_66 ) )
return - V_67 ;
}
F_15 ( & V_65 -> V_69 , ( T_2 ) V_66 & V_70 ) ;
F_15 ( & V_65 -> V_71 , ( V_72 |
( 0x1 << V_73 ) ) ) ;
return 0 ;
}
static void F_28 ( const void * V_74 ,
const struct V_75 * V_76 )
{
const T_5 * V_77 = V_74 + F_29 ( V_76 -> V_78 ) ;
unsigned int V_48 ;
if ( V_76 -> V_79 || V_76 -> V_80 || V_76 -> V_81 )
F_30 ( V_82 L_11
L_12 ,
V_76 -> V_83 , V_76 -> V_79 , V_76 -> V_80 , V_76 -> V_81 ) ;
else
F_30 ( V_82 L_11
L_13 , V_76 -> V_83 ) ;
F_15 ( & V_6 -> V_84 . V_85 , F_29 ( V_76 -> V_86 ) |
V_87 | V_88 ) ;
for ( V_48 = 0 ; V_48 < F_29 ( V_76 -> V_89 ) ; V_48 ++ )
F_15 ( & V_6 -> V_84 . V_90 , F_29 ( V_77 [ V_48 ] ) ) ;
F_15 ( & V_6 -> V_84 . V_91 , F_29 ( V_92 ) ) ;
}
int F_31 ( const struct V_93 * V_94 )
{
unsigned int V_48 ;
unsigned int V_95 ;
T_2 V_96 ;
T_6 V_97 = sizeof( struct V_93 ) ;
T_6 V_98 ;
const struct V_99 * V_100 ;
if ( ! V_94 ) {
F_30 ( V_101 L_14 ) ;
return - V_41 ;
}
V_100 = & V_94 -> V_102 ;
V_98 = F_29 ( V_100 -> V_98 ) ;
if ( ( V_100 -> V_103 [ 0 ] != 'Q' ) || ( V_100 -> V_103 [ 1 ] != 'E' ) ||
( V_100 -> V_103 [ 2 ] != 'F' ) ) {
F_30 ( V_101 L_15 ) ;
return - V_104 ;
}
if ( V_100 -> V_105 != 1 ) {
F_30 ( V_101 L_16 ) ;
return - V_104 ;
}
if ( ( V_94 -> V_89 < 1 ) || ( V_94 -> V_89 > V_106 ) ) {
F_30 ( V_101 L_17 ) ;
return - V_41 ;
}
V_97 += ( V_94 -> V_89 - 1 ) * sizeof( struct V_75 ) ;
for ( V_48 = 0 ; V_48 < V_94 -> V_89 ; V_48 ++ )
V_97 += sizeof( T_5 ) *
F_29 ( V_94 -> V_107 [ V_48 ] . V_89 ) ;
if ( V_98 != V_97 + sizeof( T_5 ) ) {
F_30 ( V_101 L_18 ) ;
return - V_104 ;
}
V_96 = F_29 ( * ( T_5 * ) ( ( void * ) V_94 + V_97 ) ) ;
if ( V_96 != F_32 ( 0 , V_94 , V_97 ) ) {
F_30 ( V_101 L_19 ) ;
return - V_108 ;
}
if ( ! V_94 -> V_109 )
F_33 ( & V_6 -> V_20 . V_110 , V_111 ) ;
if ( V_94 -> V_112 . V_113 )
F_30 ( V_82
L_20 ,
V_94 -> V_83 , F_34 ( V_94 -> V_112 . V_113 ) ,
V_94 -> V_112 . V_79 , V_94 -> V_112 . V_80 ) ;
else
F_30 ( V_82 L_21 ,
V_94 -> V_83 ) ;
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
F_35 ( V_114 . V_83 , V_94 -> V_83 , sizeof( V_114 . V_83 ) ) ;
V_114 . V_115 = V_94 -> V_115 ;
memcpy ( V_114 . V_116 , V_94 -> V_116 ,
sizeof( V_94 -> V_116 ) ) ;
for ( V_48 = 0 ; V_48 < V_94 -> V_89 ; V_48 ++ ) {
const struct V_75 * V_76 = & V_94 -> V_107 [ V_48 ] ;
if ( V_76 -> V_78 )
F_28 ( V_94 , V_76 ) ;
for ( V_95 = 0 ; V_95 < 16 ; V_95 ++ ) {
T_2 V_117 = F_29 ( V_76 -> V_118 [ V_95 ] ) ;
if ( V_117 )
F_15 ( & V_6 -> V_119 [ V_48 ] . V_120 [ V_95 ] , V_117 ) ;
}
F_15 ( & V_6 -> V_119 [ V_48 ] . V_121 , F_29 ( V_76 -> V_121 ) ) ;
}
V_122 = 1 ;
return 0 ;
}
struct V_114 * F_36 ( void )
{
static int V_123 ;
struct V_124 * V_4 ;
struct V_1 * V_2 ;
struct V_1 * V_125 = NULL ;
const char * V_126 ;
unsigned int V_48 ;
if ( V_122 )
return & V_114 ;
if ( V_123 )
return NULL ;
V_123 = 1 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return NULL ;
}
F_37 (qe, fw) {
if ( strcmp ( V_125 -> V_127 , L_22 ) == 0 )
break;
}
F_6 ( V_2 ) ;
if ( ! V_125 )
return NULL ;
V_122 = 1 ;
V_126 = F_4 ( V_125 , L_23 , NULL ) ;
if ( V_126 )
F_35 ( V_114 . V_83 , V_126 ,
sizeof( V_114 . V_83 ) ) ;
V_4 = F_38 ( V_125 , L_24 , NULL ) ;
if ( V_4 && ( V_4 -> V_98 == sizeof( V_128 ) ) ) {
const V_128 * V_129 = V_4 -> V_130 ;
V_114 . V_115 = * V_129 ;
}
V_4 = F_38 ( V_125 , L_25 , NULL ) ;
if ( V_4 && ( V_4 -> V_98 == 32 ) ) {
const T_2 * V_129 = V_4 -> V_130 ;
for ( V_48 = 0 ; V_48 < F_39 ( V_114 . V_116 ) ; V_48 ++ )
V_114 . V_116 [ V_48 ] = V_129 [ V_48 ] ;
}
F_6 ( V_125 ) ;
return & V_114 ;
}
unsigned int F_40 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
unsigned int V_131 = 0 ;
const T_2 * V_4 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_131 ;
}
V_4 = F_4 ( V_2 , L_26 , & V_3 ) ;
if ( V_4 && V_3 == sizeof( * V_4 ) )
V_131 = * V_4 ;
F_6 ( V_2 ) ;
return V_131 ;
}
unsigned int F_23 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
unsigned int V_132 ;
const T_2 * V_4 ;
V_132 = 28 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_132 ;
}
V_4 = F_4 ( V_2 , L_27 , & V_3 ) ;
if ( V_4 && V_3 == sizeof( * V_4 ) ) {
V_132 = * V_4 ;
if ( ( V_132 < 28 ) || ( V_132 > V_133 ) ) {
F_41 ( L_28 ) ;
F_6 ( V_2 ) ;
return - V_41 ;
}
}
F_6 ( V_2 ) ;
return V_132 ;
}
static int T_7 F_42 ( void )
{
struct V_1 * V_134 ;
V_134 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_134 )
return - V_68 ;
F_7 () ;
F_6 ( V_134 ) ;
return 0 ;
}
static int F_43 ( struct V_135 * V_136 )
{
if ( ! F_44 () )
F_7 () ;
return 0 ;
}
static int F_45 ( struct V_135 * V_136 )
{
return 0 ;
}
static int T_7 F_46 ( void )
{
return F_47 ( & V_137 ) ;
}
