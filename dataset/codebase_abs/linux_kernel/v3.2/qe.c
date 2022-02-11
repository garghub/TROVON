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
if ( strncasecmp ( V_47 , L_7 , 3 ) == 0 ) {
V_48 = F_22 ( V_47 + 3 , NULL , 10 ) ;
if ( ( V_48 >= 1 ) && ( V_48 <= 16 ) )
return ( V_39 - 1 ) + V_48 ;
else
return V_50 ;
}
if ( strncasecmp ( V_47 , L_8 , 3 ) == 0 ) {
V_48 = F_22 ( V_47 + 3 , NULL , 10 ) ;
if ( ( V_48 >= 1 ) && ( V_48 <= 24 ) )
return ( V_51 - 1 ) + V_48 ;
else
return V_50 ;
}
return V_50 ;
}
static void F_9 ( void )
{
int V_48 ;
static const T_3 V_52 [] = {
0x04 , 0x05 , 0x0C , 0x0D , 0x14 , 0x15 , 0x1C , 0x1D ,
0x24 , 0x25 , 0x2C , 0x2D , 0x34 , 0x35 , 0x88 , 0x89 ,
0x98 , 0x99 , 0xA8 , 0xA9 , 0xB8 , 0xB9 , 0xC8 , 0xC9 ,
0xD8 , 0xD9 , 0xE8 , 0xE9 , 0x08 , 0x09 , 0x18 , 0x19 ,
0x28 , 0x29 , 0x38 , 0x39 , 0x48 , 0x49 , 0x58 , 0x59 ,
0x68 , 0x69 , 0x78 , 0x79 , 0x80 , 0x81 ,
} ;
V_53 = F_23 () ;
for ( V_48 = 0 ; V_48 < V_53 ; V_48 ++ ) {
V_54 [ V_48 ] . V_55 = V_52 [ V_48 ] ;
V_54 [ V_48 ] . V_56 = V_57 ;
}
}
int F_24 ( void )
{
unsigned long V_15 ;
int V_58 = - V_59 ;
int V_48 ;
F_14 ( & V_19 , V_15 ) ;
for ( V_48 = 0 ; V_48 < V_53 ; V_48 ++ ) {
if ( V_54 [ V_48 ] . V_56 == V_57 ) {
V_54 [ V_48 ] . V_56 = V_60 ;
V_58 = V_54 [ V_48 ] . V_55 ;
break;
}
}
F_18 ( & V_19 , V_15 ) ;
return V_58 ;
}
void F_25 ( T_3 V_58 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_53 ; V_48 ++ ) {
if ( V_54 [ V_48 ] . V_55 == V_58 ) {
V_54 [ V_48 ] . V_56 = V_57 ;
break;
}
}
}
static int F_12 ( void )
{
struct V_61 T_4 * V_61 = & V_6 -> V_61 ;
static unsigned long V_62 = ( unsigned long ) - V_63 ;
if ( ! V_61 )
return - V_64 ;
if ( F_26 ( V_62 ) ) {
V_62 = F_27 ( 512 * 2 , 4096 ) ;
if ( F_26 ( V_62 ) )
return - V_63 ;
}
F_15 ( & V_61 -> V_65 , ( T_2 ) V_62 & V_66 ) ;
F_15 ( & V_61 -> V_67 , ( V_68 |
( 0x1 << V_69 ) ) ) ;
return 0 ;
}
static void F_28 ( const void * V_70 ,
const struct V_71 * V_72 )
{
const T_5 * V_73 = V_70 + F_29 ( V_72 -> V_74 ) ;
unsigned int V_48 ;
if ( V_72 -> V_75 || V_72 -> V_76 || V_72 -> V_77 )
F_30 ( V_78 L_9
L_10 ,
V_72 -> V_79 , V_72 -> V_75 , V_72 -> V_76 , V_72 -> V_77 ) ;
else
F_30 ( V_78 L_9
L_11 , V_72 -> V_79 ) ;
F_15 ( & V_6 -> V_80 . V_81 , F_29 ( V_72 -> V_82 ) |
V_83 | V_84 ) ;
for ( V_48 = 0 ; V_48 < F_29 ( V_72 -> V_85 ) ; V_48 ++ )
F_15 ( & V_6 -> V_80 . V_86 , F_29 ( V_73 [ V_48 ] ) ) ;
}
int F_31 ( const struct V_87 * V_88 )
{
unsigned int V_48 ;
unsigned int V_89 ;
T_2 V_90 ;
T_6 V_91 = sizeof( struct V_87 ) ;
T_6 V_92 ;
const struct V_93 * V_94 ;
if ( ! V_88 ) {
F_30 ( V_95 L_12 ) ;
return - V_41 ;
}
V_94 = & V_88 -> V_96 ;
V_92 = F_29 ( V_94 -> V_92 ) ;
if ( ( V_94 -> V_97 [ 0 ] != 'Q' ) || ( V_94 -> V_97 [ 1 ] != 'E' ) ||
( V_94 -> V_97 [ 2 ] != 'F' ) ) {
F_30 ( V_95 L_13 ) ;
return - V_98 ;
}
if ( V_94 -> V_99 != 1 ) {
F_30 ( V_95 L_14 ) ;
return - V_98 ;
}
if ( ( V_88 -> V_85 < 1 ) || ( V_88 -> V_85 > V_100 ) ) {
F_30 ( V_95 L_15 ) ;
return - V_41 ;
}
V_91 += ( V_88 -> V_85 - 1 ) * sizeof( struct V_71 ) ;
for ( V_48 = 0 ; V_48 < V_88 -> V_85 ; V_48 ++ )
V_91 += sizeof( T_5 ) *
F_29 ( V_88 -> V_101 [ V_48 ] . V_85 ) ;
if ( V_92 != V_91 + sizeof( T_5 ) ) {
F_30 ( V_95 L_16 ) ;
return - V_98 ;
}
V_90 = F_29 ( * ( T_5 * ) ( ( void * ) V_88 + V_91 ) ) ;
if ( V_90 != F_32 ( 0 , V_88 , V_91 ) ) {
F_30 ( V_95 L_17 ) ;
return - V_102 ;
}
if ( ! V_88 -> V_103 )
F_33 ( & V_6 -> V_20 . V_104 , V_105 ) ;
if ( V_88 -> V_106 . V_107 )
F_30 ( V_78
L_18 ,
V_88 -> V_79 , F_34 ( V_88 -> V_106 . V_107 ) ,
V_88 -> V_106 . V_75 , V_88 -> V_106 . V_76 ) ;
else
F_30 ( V_78 L_19 ,
V_88 -> V_79 ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
strcpy ( V_108 . V_79 , V_88 -> V_79 ) ;
V_108 . V_109 = V_88 -> V_109 ;
memcpy ( V_108 . V_110 , V_88 -> V_110 ,
sizeof( V_88 -> V_110 ) ) ;
for ( V_48 = 0 ; V_48 < V_88 -> V_85 ; V_48 ++ ) {
const struct V_71 * V_72 = & V_88 -> V_101 [ V_48 ] ;
if ( V_72 -> V_74 )
F_28 ( V_88 , V_72 ) ;
for ( V_89 = 0 ; V_89 < 16 ; V_89 ++ ) {
T_2 V_111 = F_29 ( V_72 -> V_112 [ V_89 ] ) ;
if ( V_111 )
F_15 ( & V_6 -> V_113 [ V_48 ] . V_114 [ V_89 ] , V_111 ) ;
}
F_15 ( & V_6 -> V_113 [ V_48 ] . V_115 , F_29 ( V_72 -> V_115 ) ) ;
}
V_116 = 1 ;
return 0 ;
}
struct V_108 * F_35 ( void )
{
static int V_117 ;
struct V_118 * V_4 ;
struct V_1 * V_2 ;
struct V_1 * V_119 = NULL ;
const char * V_120 ;
unsigned int V_48 ;
if ( V_116 )
return & V_108 ;
if ( V_117 )
return NULL ;
V_117 = 1 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return NULL ;
}
F_36 (qe, fw) {
if ( strcmp ( V_119 -> V_121 , L_20 ) == 0 )
break;
}
F_6 ( V_2 ) ;
if ( ! V_119 )
return NULL ;
V_116 = 1 ;
V_120 = F_4 ( V_119 , L_21 , NULL ) ;
if ( V_120 )
strncpy ( V_108 . V_79 , V_120 ,
sizeof( V_108 . V_79 ) - 1 ) ;
V_4 = F_37 ( V_119 , L_22 , NULL ) ;
if ( V_4 && ( V_4 -> V_92 == sizeof( V_122 ) ) ) {
const V_122 * V_123 = V_4 -> V_124 ;
V_108 . V_109 = * V_123 ;
}
V_4 = F_37 ( V_119 , L_23 , NULL ) ;
if ( V_4 && ( V_4 -> V_92 == 32 ) ) {
const T_2 * V_123 = V_4 -> V_124 ;
for ( V_48 = 0 ; V_48 < F_38 ( V_108 . V_110 ) ; V_48 ++ )
V_108 . V_110 [ V_48 ] = V_123 [ V_48 ] ;
}
F_6 ( V_119 ) ;
return & V_108 ;
}
unsigned int F_39 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
unsigned int V_125 = 0 ;
const T_2 * V_4 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_125 ;
}
V_4 = F_4 ( V_2 , L_24 , & V_3 ) ;
if ( V_4 && V_3 == sizeof( * V_4 ) )
V_125 = * V_4 ;
F_6 ( V_2 ) ;
return V_125 ;
}
unsigned int F_23 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
unsigned int V_126 ;
const T_2 * V_4 ;
V_126 = 28 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_3 ( NULL , L_2 ) ;
if ( ! V_2 )
return V_126 ;
}
V_4 = F_4 ( V_2 , L_25 , & V_3 ) ;
if ( V_4 && V_3 == sizeof( * V_4 ) ) {
V_126 = * V_4 ;
if ( ( V_126 < 28 ) || ( V_126 > V_127 ) ) {
F_40 ( L_26 ) ;
F_6 ( V_2 ) ;
return - V_41 ;
}
}
F_6 ( V_2 ) ;
return V_126 ;
}
static int F_41 ( struct V_128 * V_129 )
{
if ( ! F_42 () )
F_7 () ;
return 0 ;
}
static int F_43 ( struct V_128 * V_129 )
{
return 0 ;
}
static int T_7 F_44 ( void )
{
return F_45 ( & V_130 ) ;
}
