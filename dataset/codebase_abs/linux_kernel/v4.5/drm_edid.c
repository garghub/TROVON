int F_1 ( const T_1 * V_1 )
{
int V_2 , V_3 = 0 ;
for ( V_2 = 0 ; V_2 < sizeof( V_4 ) ; V_2 ++ )
if ( V_1 [ V_2 ] == V_4 [ V_2 ] )
V_3 ++ ;
return V_3 ;
}
static int F_2 ( const T_1 * V_1 )
{
int V_2 ;
T_1 V_5 = 0 ;
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ )
V_5 += V_1 [ V_2 ] ;
return V_5 ;
}
static bool F_3 ( const T_1 * V_7 , int V_8 )
{
if ( F_4 ( V_7 , 0 , V_8 ) )
return false ;
return true ;
}
bool F_5 ( T_1 * V_1 , int V_9 , bool V_10 ,
bool * V_11 )
{
T_1 V_5 ;
struct V_12 * V_12 = (struct V_12 * ) V_1 ;
if ( F_6 ( ! V_1 ) )
return false ;
if ( V_13 > 8 || V_13 < 0 )
V_13 = 6 ;
if ( V_9 == 0 ) {
int V_3 = F_1 ( V_1 ) ;
if ( V_3 == 8 ) {
if ( V_11 )
* V_11 = false ;
} else if ( V_3 >= V_13 ) {
if ( V_11 )
* V_11 = true ;
F_7 ( L_1 ) ;
memcpy ( V_1 , V_4 , sizeof( V_4 ) ) ;
} else {
if ( V_11 )
* V_11 = true ;
goto V_14;
}
}
V_5 = F_2 ( V_1 ) ;
if ( V_5 ) {
if ( V_10 ) {
F_8 ( L_2 , V_5 ) ;
}
if ( V_11 )
* V_11 = true ;
if ( V_1 [ 0 ] != 0x02 )
goto V_14;
}
switch ( V_1 [ 0 ] ) {
case 0 :
if ( V_12 -> V_15 != 1 ) {
F_8 ( L_3 , V_12 -> V_15 ) ;
goto V_14;
}
if ( V_12 -> V_16 > 4 )
F_7 ( L_4 ) ;
break;
default:
break;
}
return true ;
V_14:
if ( V_10 ) {
if ( F_3 ( V_1 , V_6 ) ) {
F_9 ( V_17 L_5 ) ;
} else {
F_9 ( V_17 L_6 ) ;
F_10 ( V_17 , L_7 , V_18 , 16 , 1 ,
V_1 , V_6 , false ) ;
}
}
return false ;
}
bool F_11 ( struct V_12 * V_12 )
{
int V_2 ;
T_1 * V_19 = ( T_1 * ) V_12 ;
if ( ! V_12 )
return false ;
for ( V_2 = 0 ; V_2 <= V_12 -> V_20 ; V_2 ++ )
if ( ! F_5 ( V_19 + V_2 * V_6 , V_2 , true , NULL ) )
return false ;
return true ;
}
static int
F_12 ( void * V_21 , T_1 * V_22 , unsigned int V_9 , T_2 V_23 )
{
struct V_24 * V_25 = V_21 ;
unsigned char V_26 = V_9 * V_6 ;
unsigned char V_27 = V_9 >> 1 ;
unsigned char V_28 = V_27 ? 3 : 2 ;
int V_29 , V_30 = 5 ;
do {
struct V_31 V_32 [] = {
{
. V_33 = V_34 ,
. V_35 = 0 ,
. V_23 = 1 ,
. V_22 = & V_27 ,
} , {
. V_33 = V_36 ,
. V_35 = 0 ,
. V_23 = 1 ,
. V_22 = & V_26 ,
} , {
. V_33 = V_36 ,
. V_35 = V_37 ,
. V_23 = V_23 ,
. V_22 = V_22 ,
}
} ;
V_29 = F_13 ( V_25 , & V_32 [ 3 - V_28 ] , V_28 ) ;
if ( V_29 == - V_38 ) {
F_14 ( L_8 ,
V_25 -> V_39 ) ;
break;
}
} while ( V_29 != V_28 && -- V_30 );
return V_29 == V_28 ? 0 : - 1 ;
}
struct V_12 * F_15 ( struct V_40 * V_41 ,
int (* F_16)( void * V_21 , T_1 * V_22 , unsigned int V_9 ,
T_2 V_23 ) ,
void * V_21 )
{
int V_2 , V_42 = 0 , V_43 = 0 ;
T_1 * V_9 , * V_44 ;
bool V_10 = ! V_41 -> V_45 || ( V_46 & V_47 ) ;
if ( ( V_9 = F_17 ( V_6 , V_48 ) ) == NULL )
return NULL ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_16 ( V_21 , V_9 , 0 , V_6 ) )
goto V_49;
if ( F_5 ( V_9 , 0 , V_10 ,
& V_41 -> V_11 ) )
break;
if ( V_2 == 0 && F_3 ( V_9 , V_6 ) ) {
V_41 -> V_50 ++ ;
goto V_51;
}
}
if ( V_2 == 4 )
goto V_51;
if ( V_9 [ 0x7e ] == 0 )
return (struct V_12 * ) V_9 ;
V_44 = F_18 ( V_9 , ( V_9 [ 0x7e ] + 1 ) * V_6 , V_48 ) ;
if ( ! V_44 )
goto V_49;
V_9 = V_44 ;
for ( V_42 = 1 ; V_42 <= V_9 [ 0x7e ] ; V_42 ++ ) {
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_16 ( V_21 ,
V_9 + ( V_43 + 1 ) * V_6 ,
V_42 , V_6 ) )
goto V_49;
if ( F_5 ( V_9 + ( V_43 + 1 )
* V_6 , V_42 ,
V_10 ,
NULL ) ) {
V_43 ++ ;
break;
}
}
if ( V_2 == 4 && V_10 ) {
F_19 ( V_41 -> V_52 -> V_52 ,
L_9 ,
V_41 -> V_39 , V_42 ) ;
V_41 -> V_45 ++ ;
}
}
if ( V_43 != V_9 [ 0x7e ] ) {
V_9 [ V_6 - 1 ] += V_9 [ 0x7e ] - V_43 ;
V_9 [ 0x7e ] = V_43 ;
V_44 = F_18 ( V_9 , ( V_43 + 1 ) * V_6 , V_48 ) ;
if ( ! V_44 )
goto V_49;
V_9 = V_44 ;
}
return (struct V_12 * ) V_9 ;
V_51:
if ( V_10 ) {
F_19 ( V_41 -> V_52 -> V_52 , L_10 ,
V_41 -> V_39 , V_42 ) ;
}
V_41 -> V_45 ++ ;
V_49:
F_20 ( V_9 ) ;
return NULL ;
}
bool
F_21 ( struct V_24 * V_25 )
{
unsigned char V_49 ;
return ( F_12 ( V_25 , & V_49 , 0 , 1 ) == 0 ) ;
}
struct V_12 * F_22 ( struct V_40 * V_41 ,
struct V_24 * V_25 )
{
struct V_12 * V_12 ;
if ( ! F_21 ( V_25 ) )
return NULL ;
V_12 = F_15 ( V_41 , F_12 , V_25 ) ;
if ( V_12 )
F_23 ( V_41 , V_12 ) ;
return V_12 ;
}
struct V_12 * F_24 ( const struct V_12 * V_12 )
{
return F_25 ( V_12 , ( V_12 -> V_20 + 1 ) * V_6 , V_48 ) ;
}
static bool F_26 ( struct V_12 * V_12 , char * V_53 )
{
char F_26 [ 3 ] ;
F_26 [ 0 ] = ( ( V_12 -> V_54 [ 0 ] & 0x7c ) >> 2 ) + '@' ;
F_26 [ 1 ] = ( ( ( V_12 -> V_54 [ 0 ] & 0x3 ) << 3 ) |
( ( V_12 -> V_54 [ 1 ] & 0xe0 ) >> 5 ) ) + '@' ;
F_26 [ 2 ] = ( V_12 -> V_54 [ 1 ] & 0x1f ) + '@' ;
return ! strncmp ( F_26 , V_53 , 3 ) ;
}
static T_3 F_27 ( struct V_12 * V_12 )
{
struct V_55 * V_56 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_28 ( V_57 ) ; V_2 ++ ) {
V_56 = & V_57 [ V_2 ] ;
if ( F_26 ( V_12 , V_56 -> V_53 ) &&
( F_29 ( V_12 ) == V_56 -> V_58 ) )
return V_56 -> V_59 ;
}
return 0 ;
}
static void F_30 ( struct V_40 * V_41 ,
T_3 V_59 )
{
struct V_60 * V_61 , * V_62 , * V_63 ;
int V_64 = 0 ;
int V_65 , V_66 ;
if ( F_31 ( & V_41 -> V_67 ) )
return;
if ( V_59 & V_68 )
V_64 = 60 ;
if ( V_59 & V_69 )
V_64 = 75 ;
V_63 = F_32 ( & V_41 -> V_67 ,
struct V_60 , V_70 ) ;
F_33 (cur_mode, t, &connector->probed_modes, head) {
V_62 -> type &= ~ V_71 ;
if ( V_62 == V_63 )
continue;
if ( F_34 ( V_62 ) > F_34 ( V_63 ) )
V_63 = V_62 ;
V_65 = V_62 -> V_72 ?
V_62 -> V_72 : F_35 ( V_62 ) ;
V_66 = V_63 -> V_72 ?
V_63 -> V_72 : F_35 ( V_63 ) ;
if ( ( F_34 ( V_62 ) == F_34 ( V_63 ) ) &&
F_36 ( V_65 , V_64 ) <
F_36 ( V_66 , V_64 ) ) {
V_63 = V_62 ;
}
}
V_63 -> type |= V_71 ;
}
static bool
F_37 ( const struct V_60 * V_73 )
{
return ( V_73 -> V_74 - V_73 -> V_75 == 160 ) &&
( V_73 -> V_76 - V_73 -> V_75 == 80 ) &&
( V_73 -> V_76 - V_73 -> V_77 == 32 ) &&
( V_73 -> V_78 - V_73 -> V_79 == 3 ) ;
}
struct V_60 * F_38 ( struct V_80 * V_52 ,
int V_81 , int V_82 , int V_83 ,
bool V_84 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_28 ( V_85 ) ; V_2 ++ ) {
const struct V_60 * V_86 = & V_85 [ V_2 ] ;
if ( V_81 != V_86 -> V_75 )
continue;
if ( V_82 != V_86 -> V_79 )
continue;
if ( V_83 != F_35 ( V_86 ) )
continue;
if ( V_84 != F_37 ( V_86 ) )
continue;
return F_39 ( V_52 , V_86 ) ;
}
return NULL ;
}
static void
F_40 ( T_1 * V_87 , T_4 * V_88 , void * V_89 )
{
int V_2 , V_90 = 0 ;
T_1 V_91 = V_87 [ 0x02 ] ;
T_1 * V_92 = V_87 + V_91 ;
V_90 = ( 127 - V_91 ) / 18 ;
for ( V_2 = 0 ; V_2 < V_90 ; V_2 ++ )
V_88 ( (struct V_93 * ) ( V_92 + 18 * V_2 ) , V_89 ) ;
}
static void
F_41 ( T_1 * V_87 , T_4 * V_88 , void * V_89 )
{
unsigned int V_2 , V_90 = F_42 ( ( int ) V_87 [ 0x02 ] , 6 ) ;
T_1 * V_92 = V_87 + 5 ;
if ( V_87 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_90 ; V_2 ++ )
V_88 ( (struct V_93 * ) ( V_92 + 18 * V_2 ) , V_89 ) ;
}
static void
F_43 ( T_1 * V_1 , T_4 * V_88 , void * V_89 )
{
int V_2 ;
struct V_12 * V_12 = (struct V_12 * ) V_1 ;
if ( V_12 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_94 ; V_2 ++ )
V_88 ( & ( V_12 -> V_95 [ V_2 ] ) , V_89 ) ;
for ( V_2 = 1 ; V_2 <= V_1 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_87 = V_1 + ( V_2 * V_6 ) ;
switch ( * V_87 ) {
case V_96 :
F_40 ( V_87 , V_88 , V_89 ) ;
break;
case V_97 :
F_41 ( V_87 , V_88 , V_89 ) ;
break;
default:
break;
}
}
}
static void
F_44 ( struct V_93 * V_61 , void * V_21 )
{
T_1 * V_98 = ( T_1 * ) V_61 ;
if ( V_98 [ 3 ] == V_99 )
if ( V_98 [ 15 ] & 0x10 )
* ( bool * ) V_21 = true ;
}
static bool
F_45 ( struct V_12 * V_12 )
{
if ( V_12 -> V_16 >= 4 ) {
bool V_29 = false ;
F_43 ( ( T_1 * ) V_12 , F_44 , & V_29 ) ;
return V_29 ;
}
return ( ( V_12 -> V_100 & V_101 ) != 0 ) ;
}
static void
F_46 ( struct V_93 * V_61 , void * V_21 )
{
T_1 * V_98 = ( T_1 * ) V_61 ;
if ( V_98 [ 3 ] == V_99 && V_98 [ 10 ] == 0x02 )
* ( T_1 * * ) V_21 = V_98 ;
}
static int
F_47 ( struct V_12 * V_12 )
{
T_1 * V_98 = NULL ;
F_43 ( ( T_1 * ) V_12 , F_46 , & V_98 ) ;
return V_98 ? ( V_98 [ 12 ] * 2 ) : 0 ;
}
static int
F_48 ( struct V_12 * V_12 )
{
T_1 * V_98 = NULL ;
F_43 ( ( T_1 * ) V_12 , F_46 , & V_98 ) ;
return V_98 ? V_98 [ 13 ] : 0 ;
}
static int
F_49 ( struct V_12 * V_12 )
{
T_1 * V_98 = NULL ;
F_43 ( ( T_1 * ) V_12 , F_46 , & V_98 ) ;
return V_98 ? ( V_98 [ 15 ] << 8 ) + V_98 [ 14 ] : 0 ;
}
static int
F_50 ( struct V_12 * V_12 )
{
T_1 * V_98 = NULL ;
F_43 ( ( T_1 * ) V_12 , F_46 , & V_98 ) ;
return V_98 ? V_98 [ 16 ] : 0 ;
}
static int
F_51 ( struct V_12 * V_12 )
{
T_1 * V_98 = NULL ;
F_43 ( ( T_1 * ) V_12 , F_46 , & V_98 ) ;
return V_98 ? V_98 [ 17 ] : 0 ;
}
static int F_52 ( struct V_12 * V_12 )
{
if ( V_12 -> V_16 >= 2 ) {
if ( V_12 -> V_16 >= 4 && ( V_12 -> V_102 & V_103 ) )
return V_104 ;
if ( F_47 ( V_12 ) )
return V_105 ;
return V_106 ;
}
return V_107 ;
}
static int
F_53 ( T_1 V_108 , T_1 V_109 )
{
return ( V_108 == 0x00 && V_109 == 0x00 ) ||
( V_108 == 0x01 && V_109 == 0x01 ) ||
( V_108 == 0x20 && V_109 == 0x20 ) ;
}
static struct V_60 *
F_54 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_110 * V_61 )
{
struct V_80 * V_52 = V_41 -> V_52 ;
struct V_60 * V_111 , * V_73 = NULL ;
int V_81 , V_82 ;
int V_112 ;
unsigned V_113 = ( V_61 -> V_114 & V_115 )
>> V_116 ;
unsigned V_117 = ( V_61 -> V_114 & V_118 )
>> V_119 ;
int V_120 = F_52 ( V_12 ) ;
if ( F_53 ( V_61 -> V_81 , V_61 -> V_114 ) )
return NULL ;
V_81 = V_61 -> V_81 * 8 + 248 ;
V_112 = V_117 + 60 ;
if ( V_113 == 0 ) {
if ( V_12 -> V_16 < 3 )
V_82 = V_81 ;
else
V_82 = ( V_81 * 10 ) / 16 ;
} else if ( V_113 == 1 )
V_82 = ( V_81 * 3 ) / 4 ;
else if ( V_113 == 2 )
V_82 = ( V_81 * 4 ) / 5 ;
else
V_82 = ( V_81 * 9 ) / 16 ;
if ( V_112 == 60 &&
( ( V_81 == 1360 && V_82 == 765 ) ||
( V_81 == 1368 && V_82 == 769 ) ) ) {
V_81 = 1366 ;
V_82 = 768 ;
}
F_55 (m, &connector->probed_modes, head)
if ( V_111 -> V_75 == V_81 && V_111 -> V_79 == V_82 &&
F_35 ( V_111 ) == V_112 )
return NULL ;
if ( V_81 == 1366 && V_82 == 768 && V_112 == 60 ) {
V_73 = F_56 ( V_52 , 1366 , 768 , V_112 , 0 , 0 ,
false ) ;
V_73 -> V_75 = 1366 ;
V_73 -> V_77 = V_73 -> V_77 - 1 ;
V_73 -> V_76 = V_73 -> V_76 - 1 ;
return V_73 ;
}
if ( F_45 ( V_12 ) ) {
V_73 = F_38 ( V_52 , V_81 , V_82 , V_112 ,
true ) ;
if ( V_73 )
return V_73 ;
}
V_73 = F_38 ( V_52 , V_81 , V_82 , V_112 , false ) ;
if ( V_73 )
return V_73 ;
switch ( V_120 ) {
case V_107 :
break;
case V_106 :
V_73 = F_57 ( V_52 , V_81 , V_82 , V_112 , 0 , 0 ) ;
break;
case V_105 :
V_73 = F_57 ( V_52 , V_81 , V_82 , V_112 , 0 , 0 ) ;
if ( ! V_73 )
return NULL ;
if ( F_58 ( V_73 ) > F_47 ( V_12 ) ) {
F_59 ( V_52 , V_73 ) ;
V_73 = F_60 ( V_52 , V_81 , V_82 ,
V_112 , 0 , 0 ,
F_49 ( V_12 ) ,
F_48 ( V_12 ) ,
F_50 ( V_12 ) ,
F_51 ( V_12 ) ) ;
}
break;
case V_104 :
V_73 = F_56 ( V_52 , V_81 , V_82 , V_112 , 0 , 0 ,
false ) ;
break;
}
return V_73 ;
}
static void
F_61 ( struct V_60 * V_73 ,
struct V_121 * V_122 )
{
int V_2 ;
static const struct {
int V_123 , V_124 ;
} V_125 [] = {
{ 1920 , 1080 } ,
{ 720 , 480 } ,
{ 1440 , 480 } ,
{ 2880 , 480 } ,
{ 720 , 576 } ,
{ 1440 , 576 } ,
{ 2880 , 576 } ,
} ;
if ( ! ( V_122 -> V_126 & V_127 ) )
return;
for ( V_2 = 0 ; V_2 < F_28 ( V_125 ) ; V_2 ++ ) {
if ( ( V_73 -> V_75 == V_125 [ V_2 ] . V_123 ) &&
( V_73 -> V_79 == V_125 [ V_2 ] . V_124 / 2 ) ) {
V_73 -> V_79 *= 2 ;
V_73 -> V_78 *= 2 ;
V_73 -> V_128 *= 2 ;
V_73 -> V_129 *= 2 ;
V_73 -> V_129 |= 1 ;
}
}
V_73 -> V_35 |= V_130 ;
}
static struct V_60 * F_62 ( struct V_80 * V_52 ,
struct V_12 * V_12 ,
struct V_93 * V_131 ,
T_3 V_59 )
{
struct V_60 * V_73 ;
struct V_121 * V_122 = & V_131 -> V_21 . V_132 ;
unsigned V_133 = ( V_122 -> V_134 & 0xf0 ) << 4 | V_122 -> V_135 ;
unsigned V_136 = ( V_122 -> V_137 & 0xf0 ) << 4 | V_122 -> V_138 ;
unsigned V_139 = ( V_122 -> V_134 & 0xf ) << 8 | V_122 -> V_140 ;
unsigned V_141 = ( V_122 -> V_137 & 0xf ) << 8 | V_122 -> V_142 ;
unsigned V_143 = ( V_122 -> V_144 & 0xc0 ) << 2 | V_122 -> V_145 ;
unsigned V_146 = ( V_122 -> V_144 & 0x30 ) << 4 | V_122 -> V_147 ;
unsigned V_148 = ( V_122 -> V_144 & 0xc ) << 2 | V_122 -> V_149 >> 4 ;
unsigned V_150 = ( V_122 -> V_144 & 0x3 ) << 4 | ( V_122 -> V_149 & 0xf ) ;
if ( V_133 < 64 || V_136 < 64 )
return NULL ;
if ( V_122 -> V_126 & V_151 ) {
F_14 ( L_11 ) ;
return NULL ;
}
if ( ! ( V_122 -> V_126 & V_152 ) ) {
F_14 ( L_12 ) ;
}
if ( ! V_146 || ! V_150 ) {
F_14 ( L_13
L_14 ) ;
return NULL ;
}
if ( V_59 & V_153 ) {
V_73 = F_56 ( V_52 , V_133 , V_136 , 60 , true , false , false ) ;
if ( ! V_73 )
return NULL ;
goto V_154;
}
V_73 = F_63 ( V_52 ) ;
if ( ! V_73 )
return NULL ;
if ( V_59 & V_155 )
V_131 -> V_156 = F_64 ( 1088 ) ;
V_73 -> clock = F_65 ( V_131 -> V_156 ) * 10 ;
V_73 -> V_75 = V_133 ;
V_73 -> V_77 = V_73 -> V_75 + V_143 ;
V_73 -> V_76 = V_73 -> V_77 + V_146 ;
V_73 -> V_74 = V_73 -> V_75 + V_139 ;
V_73 -> V_79 = V_136 ;
V_73 -> V_78 = V_73 -> V_79 + V_148 ;
V_73 -> V_128 = V_73 -> V_78 + V_150 ;
V_73 -> V_129 = V_73 -> V_79 + V_141 ;
if ( V_73 -> V_76 > V_73 -> V_74 )
V_73 -> V_74 = V_73 -> V_76 + 1 ;
if ( V_73 -> V_128 > V_73 -> V_129 )
V_73 -> V_129 = V_73 -> V_128 + 1 ;
F_61 ( V_73 , V_122 ) ;
if ( V_59 & V_157 ) {
V_122 -> V_126 |= V_158 | V_159 ;
}
V_73 -> V_35 |= ( V_122 -> V_126 & V_158 ) ?
V_160 : V_161 ;
V_73 -> V_35 |= ( V_122 -> V_126 & V_159 ) ?
V_162 : V_163 ;
V_154:
V_73 -> V_164 = V_122 -> V_165 | ( V_122 -> V_166 & 0xf0 ) << 4 ;
V_73 -> V_167 = V_122 -> V_168 | ( V_122 -> V_166 & 0xf ) << 8 ;
if ( V_59 & V_169 ) {
V_73 -> V_164 *= 10 ;
V_73 -> V_167 *= 10 ;
}
if ( V_59 & V_170 ) {
V_73 -> V_164 = V_12 -> V_171 * 10 ;
V_73 -> V_167 = V_12 -> V_172 * 10 ;
}
V_73 -> type = V_173 ;
V_73 -> V_72 = F_35 ( V_73 ) ;
F_66 ( V_73 ) ;
return V_73 ;
}
static bool
F_67 ( const struct V_60 * V_73 ,
struct V_12 * V_12 , T_1 * V_61 )
{
int V_174 , V_175 , V_176 ;
V_175 = V_61 [ 7 ] ;
if ( V_12 -> V_16 >= 4 )
V_175 += ( ( V_61 [ 4 ] & 0x04 ) ? 255 : 0 ) ;
V_176 = V_61 [ 8 ] ;
if ( V_12 -> V_16 >= 4 )
V_176 += ( ( V_61 [ 4 ] & 0x08 ) ? 255 : 0 ) ;
V_174 = F_58 ( V_73 ) ;
return ( V_174 <= V_176 && V_174 >= V_175 ) ;
}
static bool
F_68 ( const struct V_60 * V_73 ,
struct V_12 * V_12 , T_1 * V_61 )
{
int V_177 , V_178 , V_179 ;
V_178 = V_61 [ 5 ] ;
if ( V_12 -> V_16 >= 4 )
V_178 += ( ( V_61 [ 4 ] & 0x01 ) ? 255 : 0 ) ;
V_179 = V_61 [ 6 ] ;
if ( V_12 -> V_16 >= 4 )
V_179 += ( ( V_61 [ 4 ] & 0x02 ) ? 255 : 0 ) ;
V_177 = F_35 ( V_73 ) ;
return ( V_177 <= V_179 && V_177 >= V_178 ) ;
}
static T_3
F_69 ( struct V_12 * V_12 , T_1 * V_61 )
{
if ( V_61 [ 9 ] == 0 || V_61 [ 9 ] == 255 )
return 0 ;
if ( V_12 -> V_16 >= 4 && V_61 [ 10 ] == 0x04 )
return ( V_61 [ 9 ] * 10000 ) - ( ( V_61 [ 12 ] >> 2 ) * 250 ) ;
return V_61 [ 9 ] * 10000 + 5001 ;
}
static bool
F_70 ( const struct V_60 * V_73 , struct V_12 * V_12 ,
struct V_93 * V_131 )
{
T_3 V_180 ;
T_1 * V_61 = ( T_1 * ) V_131 ;
if ( ! F_67 ( V_73 , V_12 , V_61 ) )
return false ;
if ( ! F_68 ( V_73 , V_12 , V_61 ) )
return false ;
if ( ( V_180 = F_69 ( V_12 , V_61 ) ) )
if ( V_73 -> clock > V_180 )
return false ;
if ( V_12 -> V_16 >= 4 && V_61 [ 10 ] == 0x04 )
if ( V_61 [ 13 ] && V_73 -> V_75 > 8 * ( V_61 [ 13 ] + ( 256 * ( V_61 [ 12 ] & 0x3 ) ) ) )
return false ;
if ( F_37 ( V_73 ) && ! F_45 ( V_12 ) )
return false ;
return true ;
}
static bool F_71 ( const struct V_40 * V_41 ,
const struct V_60 * V_73 )
{
const struct V_60 * V_111 ;
bool V_181 = false ;
F_55 (m, &connector->probed_modes, head) {
if ( V_73 -> V_75 == V_111 -> V_75 &&
V_73 -> V_79 == V_111 -> V_79 &&
F_35 ( V_73 ) == F_35 ( V_111 ) )
return false ;
if ( V_73 -> V_75 <= V_111 -> V_75 &&
V_73 -> V_79 <= V_111 -> V_79 )
V_181 = true ;
}
return V_181 ;
}
static int
F_72 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_93 * V_131 )
{
int V_2 , V_182 = 0 ;
struct V_60 * V_183 ;
struct V_80 * V_52 = V_41 -> V_52 ;
for ( V_2 = 0 ; V_2 < F_28 ( V_85 ) ; V_2 ++ ) {
if ( F_70 ( V_85 + V_2 , V_12 , V_131 ) &&
F_71 ( V_41 , V_85 + V_2 ) ) {
V_183 = F_39 ( V_52 , & V_85 [ V_2 ] ) ;
if ( V_183 ) {
F_73 ( V_41 , V_183 ) ;
V_182 ++ ;
}
}
}
return V_182 ;
}
static void F_74 ( struct V_60 * V_73 )
{
if ( V_73 -> V_75 == 1368 && V_73 -> V_79 == 768 ) {
V_73 -> V_75 = 1366 ;
V_73 -> V_77 -- ;
V_73 -> V_76 -- ;
F_66 ( V_73 ) ;
}
}
static int
F_75 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_93 * V_131 )
{
int V_2 , V_182 = 0 ;
struct V_60 * V_183 ;
struct V_80 * V_52 = V_41 -> V_52 ;
for ( V_2 = 0 ; V_2 < F_28 ( V_184 ) ; V_2 ++ ) {
const struct V_185 * V_111 = & V_184 [ V_2 ] ;
V_183 = F_57 ( V_52 , V_111 -> V_123 , V_111 -> V_124 , V_111 -> V_98 , 0 , 0 ) ;
if ( ! V_183 )
return V_182 ;
F_74 ( V_183 ) ;
if ( ! F_70 ( V_183 , V_12 , V_131 ) ||
! F_71 ( V_41 , V_183 ) ) {
F_59 ( V_52 , V_183 ) ;
continue;
}
F_73 ( V_41 , V_183 ) ;
V_182 ++ ;
}
return V_182 ;
}
static int
F_76 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_93 * V_131 )
{
int V_2 , V_182 = 0 ;
struct V_60 * V_183 ;
struct V_80 * V_52 = V_41 -> V_52 ;
bool V_84 = F_45 ( V_12 ) ;
for ( V_2 = 0 ; V_2 < F_28 ( V_184 ) ; V_2 ++ ) {
const struct V_185 * V_111 = & V_184 [ V_2 ] ;
V_183 = F_56 ( V_52 , V_111 -> V_123 , V_111 -> V_124 , V_111 -> V_98 , V_84 , 0 , 0 ) ;
if ( ! V_183 )
return V_182 ;
F_74 ( V_183 ) ;
if ( ! F_70 ( V_183 , V_12 , V_131 ) ||
! F_71 ( V_41 , V_183 ) ) {
F_59 ( V_52 , V_183 ) ;
continue;
}
F_73 ( V_41 , V_183 ) ;
V_182 ++ ;
}
return V_182 ;
}
static void
F_77 ( struct V_93 * V_131 , void * V_186 )
{
struct V_187 * V_89 = V_186 ;
struct V_188 * V_21 = & V_131 -> V_21 . V_189 ;
struct V_190 * V_191 = & V_21 -> V_21 . V_191 ;
if ( V_21 -> type != V_99 )
return;
V_89 -> V_182 += F_72 ( V_89 -> V_41 ,
V_89 -> V_12 ,
V_131 ) ;
if ( ! F_78 ( V_89 -> V_12 , 1 , 1 ) )
return;
switch ( V_191 -> V_35 ) {
case 0x02 :
case 0x00 :
V_89 -> V_182 += F_75 ( V_89 -> V_41 ,
V_89 -> V_12 ,
V_131 ) ;
break;
case 0x04 :
if ( ! F_78 ( V_89 -> V_12 , 1 , 3 ) )
break;
V_89 -> V_182 += F_76 ( V_89 -> V_41 ,
V_89 -> V_12 ,
V_131 ) ;
break;
case 0x01 :
default:
break;
}
}
static int
F_79 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_187 V_89 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
if ( F_78 ( V_12 , 1 , 0 ) )
F_43 ( ( T_1 * ) V_12 , F_77 ,
& V_89 ) ;
return V_89 . V_182 ;
}
static int
F_80 ( struct V_40 * V_41 , struct V_93 * V_131 )
{
int V_2 , V_42 , V_111 , V_182 = 0 ;
struct V_60 * V_73 ;
T_1 * V_192 = ( ( T_1 * ) V_131 ) + 5 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_42 = 7 ; V_42 >= 0 ; V_42 -- ) {
V_111 = ( V_2 * 8 ) + ( 7 - V_42 ) ;
if ( V_111 >= F_28 ( V_193 ) )
break;
if ( V_192 [ V_2 ] & ( 1 << V_42 ) ) {
V_73 = F_38 ( V_41 -> V_52 ,
V_193 [ V_111 ] . V_123 ,
V_193 [ V_111 ] . V_124 ,
V_193 [ V_111 ] . V_98 ,
V_193 [ V_111 ] . V_84 ) ;
if ( V_73 ) {
F_73 ( V_41 , V_73 ) ;
V_182 ++ ;
}
}
}
}
return V_182 ;
}
static void
F_81 ( struct V_93 * V_131 , void * V_186 )
{
struct V_187 * V_89 = V_186 ;
struct V_188 * V_21 = & V_131 -> V_21 . V_189 ;
if ( V_21 -> type == V_194 )
V_89 -> V_182 += F_80 ( V_89 -> V_41 , V_131 ) ;
}
static int
F_82 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_80 * V_52 = V_41 -> V_52 ;
unsigned long V_195 = V_12 -> V_196 . V_197 |
( V_12 -> V_196 . V_198 << 8 ) |
( ( V_12 -> V_196 . V_199 & 0x80 ) << 9 ) ;
int V_2 , V_182 = 0 ;
struct V_187 V_89 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
for ( V_2 = 0 ; V_2 <= V_200 ; V_2 ++ ) {
if ( V_195 & ( 1 << V_2 ) ) {
struct V_60 * V_183 ;
V_183 = F_39 ( V_52 , & V_201 [ V_2 ] ) ;
if ( V_183 ) {
F_73 ( V_41 , V_183 ) ;
V_182 ++ ;
}
}
}
if ( F_78 ( V_12 , 1 , 0 ) )
F_43 ( ( T_1 * ) V_12 ,
F_81 , & V_89 ) ;
return V_182 + V_89 . V_182 ;
}
static void
F_83 ( struct V_93 * V_131 , void * V_186 )
{
struct V_187 * V_89 = V_186 ;
struct V_188 * V_21 = & V_131 -> V_21 . V_189 ;
struct V_40 * V_41 = V_89 -> V_41 ;
struct V_12 * V_12 = V_89 -> V_12 ;
if ( V_21 -> type == V_202 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_110 * V_203 ;
struct V_60 * V_183 ;
V_203 = & V_21 -> V_21 . V_204 [ V_2 ] ;
V_183 = F_54 ( V_41 , V_12 , V_203 ) ;
if ( V_183 ) {
F_73 ( V_41 , V_183 ) ;
V_89 -> V_182 ++ ;
}
}
}
}
static int
F_84 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
int V_2 , V_182 = 0 ;
struct V_187 V_89 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
for ( V_2 = 0 ; V_2 < V_205 ; V_2 ++ ) {
struct V_60 * V_183 ;
V_183 = F_54 ( V_41 , V_12 ,
& V_12 -> V_206 [ V_2 ] ) ;
if ( V_183 ) {
F_73 ( V_41 , V_183 ) ;
V_182 ++ ;
}
}
if ( F_78 ( V_12 , 1 , 0 ) )
F_43 ( ( T_1 * ) V_12 , F_83 ,
& V_89 ) ;
return V_182 + V_89 . V_182 ;
}
static int F_85 ( struct V_40 * V_41 ,
struct V_93 * V_131 )
{
int V_2 , V_42 , V_182 = 0 ;
struct V_60 * V_183 ;
struct V_80 * V_52 = V_41 -> V_52 ;
struct V_207 * V_208 ;
const int V_209 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_210 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_211 ( V_212 ) , V_213 ;
V_208 = & ( V_131 -> V_21 . V_189 . V_21 . V_208 [ V_2 ] ) ;
if ( ! memcmp ( V_208 -> V_214 , V_210 , 3 ) )
continue;
V_213 = ( V_208 -> V_214 [ 0 ] + ( ( V_208 -> V_214 [ 1 ] & 0xf0 ) << 4 ) + 1 ) * 2 ;
switch ( V_208 -> V_214 [ 1 ] & 0x0c ) {
case 0x00 :
V_212 = V_213 * 4 / 3 ;
break;
case 0x04 :
V_212 = V_213 * 16 / 9 ;
break;
case 0x08 :
V_212 = V_213 * 16 / 10 ;
break;
case 0x0c :
V_212 = V_213 * 15 / 9 ;
break;
}
for ( V_42 = 1 ; V_42 < 5 ; V_42 ++ ) {
if ( V_208 -> V_214 [ 2 ] & ( 1 << V_42 ) ) {
V_183 = F_56 ( V_52 , V_212 , V_213 ,
V_209 [ V_42 ] , V_42 == 0 ,
false , false ) ;
if ( V_183 ) {
F_73 ( V_41 , V_183 ) ;
V_182 ++ ;
}
}
}
}
return V_182 ;
}
static void
F_86 ( struct V_93 * V_131 , void * V_186 )
{
struct V_187 * V_89 = V_186 ;
struct V_188 * V_21 = & V_131 -> V_21 . V_189 ;
if ( V_21 -> type == V_215 )
V_89 -> V_182 += F_85 ( V_89 -> V_41 , V_131 ) ;
}
static int
F_87 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_187 V_89 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
if ( F_78 ( V_12 , 1 , 2 ) )
F_43 ( ( T_1 * ) V_12 , F_86 , & V_89 ) ;
return V_89 . V_182 ;
}
static void
F_88 ( struct V_93 * V_131 , void * V_186 )
{
struct V_187 * V_89 = V_186 ;
struct V_60 * V_183 ;
if ( V_131 -> V_156 ) {
V_183 = F_62 ( V_89 -> V_41 -> V_52 ,
V_89 -> V_12 , V_131 ,
V_89 -> V_59 ) ;
if ( ! V_183 )
return;
if ( V_89 -> V_216 )
V_183 -> type |= V_71 ;
F_89 ( V_183 ) ;
F_73 ( V_89 -> V_41 , V_183 ) ;
V_89 -> V_182 ++ ;
V_89 -> V_216 = 0 ;
}
}
static int
F_90 ( struct V_40 * V_41 , struct V_12 * V_12 ,
T_3 V_59 )
{
struct V_187 V_89 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
. V_216 = 1 ,
. V_59 = V_59 ,
} ;
if ( V_89 . V_216 && ! F_78 ( V_12 , 1 , 3 ) )
V_89 . V_216 =
( V_12 -> V_102 & V_217 ) ;
F_43 ( ( T_1 * ) V_12 , F_88 , & V_89 ) ;
return V_89 . V_182 ;
}
static T_1 * F_91 ( struct V_12 * V_12 , int V_218 )
{
T_1 * V_219 = NULL ;
int V_2 ;
if ( V_12 == NULL || V_12 -> V_20 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_12 -> V_20 ; V_2 ++ ) {
V_219 = ( T_1 * ) V_12 + V_6 * ( V_2 + 1 ) ;
if ( V_219 [ 0 ] == V_218 )
break;
}
if ( V_2 == V_12 -> V_20 )
return NULL ;
return V_219 ;
}
static T_1 * F_92 ( struct V_12 * V_12 )
{
return F_91 ( V_12 , V_96 ) ;
}
static T_1 * F_93 ( struct V_12 * V_12 )
{
return F_91 ( V_12 , V_220 ) ;
}
static unsigned int
F_94 ( const struct V_60 * V_221 )
{
unsigned int clock = V_221 -> clock ;
if ( V_221 -> V_72 % 6 != 0 )
return clock ;
if ( V_221 -> V_79 == 240 || V_221 -> V_79 == 480 )
clock = F_95 ( clock * 1001 , 1000 ) ;
else
clock = F_95 ( clock * 1000 , 1001 ) ;
return clock ;
}
static T_1 F_96 ( const struct V_60 * V_222 ,
unsigned int V_223 )
{
T_1 V_224 ;
if ( ! V_222 -> clock )
return 0 ;
for ( V_224 = 1 ; V_224 < F_28 ( V_225 ) ; V_224 ++ ) {
const struct V_60 * V_221 = & V_225 [ V_224 ] ;
unsigned int V_226 , V_227 ;
V_226 = V_221 -> clock ;
V_227 = F_94 ( V_221 ) ;
if ( abs ( V_222 -> clock - V_226 ) > V_223 &&
abs ( V_222 -> clock - V_227 ) > V_223 )
continue;
if ( F_97 ( V_222 , V_221 ) )
return V_224 ;
}
return 0 ;
}
T_1 F_98 ( const struct V_60 * V_222 )
{
T_1 V_224 ;
if ( ! V_222 -> clock )
return 0 ;
for ( V_224 = 1 ; V_224 < F_28 ( V_225 ) ; V_224 ++ ) {
const struct V_60 * V_221 = & V_225 [ V_224 ] ;
unsigned int V_226 , V_227 ;
V_226 = V_221 -> clock ;
V_227 = F_94 ( V_221 ) ;
if ( ( F_99 ( V_222 -> clock ) == F_99 ( V_226 ) ||
F_99 ( V_222 -> clock ) == F_99 ( V_227 ) ) &&
F_100 ( V_222 , V_221 ) )
return V_224 ;
}
return 0 ;
}
static bool F_101 ( T_1 V_224 )
{
return V_224 > 0 && V_224 < F_28 ( V_225 ) ;
}
enum V_228 F_102 ( const T_1 V_229 )
{
return V_225 [ V_229 ] . V_230 ;
}
static unsigned int
F_103 ( const struct V_60 * V_231 )
{
if ( V_231 -> V_79 == 4096 && V_231 -> V_75 == 2160 )
return V_231 -> clock ;
return F_94 ( V_231 ) ;
}
static T_1 F_104 ( const struct V_60 * V_222 ,
unsigned int V_223 )
{
T_1 V_224 ;
if ( ! V_222 -> clock )
return 0 ;
for ( V_224 = 1 ; V_224 < F_28 ( V_232 ) ; V_224 ++ ) {
const struct V_60 * V_231 = & V_232 [ V_224 ] ;
unsigned int V_226 , V_227 ;
V_226 = V_231 -> clock ;
V_227 = F_103 ( V_231 ) ;
if ( abs ( V_222 -> clock - V_226 ) > V_223 &&
abs ( V_222 -> clock - V_227 ) > V_223 )
continue;
if ( F_97 ( V_222 , V_231 ) )
return V_224 ;
}
return 0 ;
}
static T_1 F_105 ( const struct V_60 * V_222 )
{
T_1 V_224 ;
if ( ! V_222 -> clock )
return 0 ;
for ( V_224 = 1 ; V_224 < F_28 ( V_232 ) ; V_224 ++ ) {
const struct V_60 * V_231 = & V_232 [ V_224 ] ;
unsigned int V_226 , V_227 ;
V_226 = V_231 -> clock ;
V_227 = F_103 ( V_231 ) ;
if ( ( F_99 ( V_222 -> clock ) == F_99 ( V_226 ) ||
F_99 ( V_222 -> clock ) == F_99 ( V_227 ) ) &&
F_100 ( V_222 , V_231 ) )
return V_224 ;
}
return 0 ;
}
static bool F_106 ( T_1 V_224 )
{
return V_224 > 0 && V_224 < F_28 ( V_232 ) ;
}
static int
F_107 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_80 * V_52 = V_41 -> V_52 ;
struct V_60 * V_73 , * V_233 ;
F_108 ( V_234 ) ;
int V_182 = 0 ;
if ( ! F_92 ( V_12 ) )
return 0 ;
F_55 (mode, &connector->probed_modes, head) {
const struct V_60 * V_221 = NULL ;
struct V_60 * V_183 ;
T_1 V_224 = F_98 ( V_73 ) ;
unsigned int V_226 , V_227 ;
if ( F_101 ( V_224 ) ) {
V_221 = & V_225 [ V_224 ] ;
V_227 = F_94 ( V_221 ) ;
} else {
V_224 = F_105 ( V_73 ) ;
if ( F_106 ( V_224 ) ) {
V_221 = & V_232 [ V_224 ] ;
V_227 = F_103 ( V_221 ) ;
}
}
if ( ! V_221 )
continue;
V_226 = V_221 -> clock ;
if ( V_226 == V_227 )
continue;
if ( V_73 -> clock != V_226 && V_73 -> clock != V_227 )
continue;
V_183 = F_39 ( V_52 , V_221 ) ;
if ( ! V_183 )
continue;
V_183 -> V_35 |= V_73 -> V_35 & V_235 ;
if ( V_73 -> clock != V_226 )
V_183 -> clock = V_226 ;
else
V_183 -> clock = V_227 ;
F_109 ( & V_183 -> V_70 , & V_234 ) ;
}
F_33 (mode, tmp, &list, head) {
F_110 ( & V_73 -> V_70 ) ;
F_73 ( V_41 , V_73 ) ;
V_182 ++ ;
}
return V_182 ;
}
static struct V_60 *
F_111 ( struct V_40 * V_41 ,
const T_1 * V_236 , T_1 V_237 ,
T_1 V_238 )
{
struct V_80 * V_52 = V_41 -> V_52 ;
struct V_60 * V_183 ;
T_1 V_224 ;
if ( V_236 == NULL || V_238 >= V_237 )
return NULL ;
V_224 = ( V_236 [ V_238 ] & 127 ) ;
if ( ! F_101 ( V_224 ) )
return NULL ;
V_183 = F_39 ( V_52 , & V_225 [ V_224 ] ) ;
if ( ! V_183 )
return NULL ;
V_183 -> V_72 = 0 ;
return V_183 ;
}
static int
F_112 ( struct V_40 * V_41 , const T_1 * V_239 , T_1 V_23 )
{
int V_2 , V_182 = 0 ;
for ( V_2 = 0 ; V_2 < V_23 ; V_2 ++ ) {
struct V_60 * V_73 ;
V_73 = F_111 ( V_41 , V_239 , V_23 , V_2 ) ;
if ( V_73 ) {
F_73 ( V_41 , V_73 ) ;
V_182 ++ ;
}
}
return V_182 ;
}
static bool
F_113 ( const struct V_60 * V_73 ,
const struct V_240 * V_241 )
{
unsigned int V_242 = V_73 -> V_35 & V_130 ;
return V_73 -> V_75 == V_241 -> V_212 &&
V_73 -> V_79 == V_241 -> V_213 &&
V_242 == ( V_241 -> V_35 & V_130 ) &&
F_35 ( V_73 ) == V_241 -> V_72 ;
}
static int F_114 ( struct V_40 * V_41 )
{
struct V_80 * V_52 = V_41 -> V_52 ;
const struct V_60 * V_73 ;
struct V_243 V_244 ;
int V_182 = 0 , V_2 ;
F_115 ( & V_244 ) ;
F_55 (mode, &connector->probed_modes, head) {
for ( V_2 = 0 ; V_2 < F_28 ( V_245 ) ; V_2 ++ ) {
const struct V_240 * V_246 ;
struct V_60 * V_247 ;
if ( ! F_113 ( V_73 ,
& V_245 [ V_2 ] ) )
continue;
V_246 = & V_245 [ V_2 ] ;
V_247 = F_39 ( V_52 , V_73 ) ;
if ( ! V_247 )
continue;
V_247 -> V_35 |= V_246 -> V_35 ;
F_109 ( & V_247 -> V_70 , & V_244 ) ;
V_182 ++ ;
}
}
F_116 ( & V_244 , & V_41 -> V_67 ) ;
return V_182 ;
}
static int F_117 ( struct V_40 * V_41 , T_1 V_224 )
{
struct V_80 * V_52 = V_41 -> V_52 ;
struct V_60 * V_183 ;
if ( ! F_106 ( V_224 ) ) {
F_8 ( L_15 , V_224 ) ;
return 0 ;
}
V_183 = F_39 ( V_52 , & V_232 [ V_224 ] ) ;
if ( ! V_183 )
return 0 ;
F_73 ( V_41 , V_183 ) ;
return 1 ;
}
static int F_118 ( struct V_40 * V_41 , T_5 V_248 ,
const T_1 * V_236 , T_1 V_237 , T_1 V_238 )
{
struct V_60 * V_183 ;
int V_182 = 0 ;
if ( V_248 & ( 1 << 0 ) ) {
V_183 = F_111 ( V_41 , V_236 ,
V_237 ,
V_238 ) ;
if ( V_183 ) {
V_183 -> V_35 |= V_249 ;
F_73 ( V_41 , V_183 ) ;
V_182 ++ ;
}
}
if ( V_248 & ( 1 << 6 ) ) {
V_183 = F_111 ( V_41 , V_236 ,
V_237 ,
V_238 ) ;
if ( V_183 ) {
V_183 -> V_35 |= V_250 ;
F_73 ( V_41 , V_183 ) ;
V_182 ++ ;
}
}
if ( V_248 & ( 1 << 8 ) ) {
V_183 = F_111 ( V_41 , V_236 ,
V_237 ,
V_238 ) ;
if ( V_183 ) {
V_183 -> V_35 |= V_251 ;
F_73 ( V_41 , V_183 ) ;
V_182 ++ ;
}
}
return V_182 ;
}
static int
F_119 ( struct V_40 * V_41 , const T_1 * V_239 , T_1 V_23 ,
const T_1 * V_236 , T_1 V_237 )
{
int V_182 = 0 , V_252 = 0 , V_2 , V_253 = 0 , V_254 ;
T_1 V_255 , V_256 = 0 ;
T_5 V_257 ;
T_5 V_258 ;
if ( V_23 < 8 )
goto V_49;
if ( ! ( V_239 [ 8 ] & ( 1 << 5 ) ) )
goto V_49;
if ( V_239 [ 8 ] & ( 1 << 7 ) )
V_252 += 2 ;
if ( V_239 [ 8 ] & ( 1 << 6 ) )
V_252 += 2 ;
if ( V_23 < ( 8 + V_252 + 2 ) )
goto V_49;
V_252 ++ ;
if ( V_239 [ 8 + V_252 ] & ( 1 << 7 ) ) {
V_182 += F_114 ( V_41 ) ;
V_253 = ( V_239 [ 8 + V_252 ] & 0x60 ) >> 5 ;
}
V_252 ++ ;
V_255 = V_239 [ 8 + V_252 ] >> 5 ;
V_256 = V_239 [ 8 + V_252 ] & 0x1f ;
for ( V_2 = 0 ; V_2 < V_255 && V_23 >= ( 9 + V_252 + V_2 ) ; V_2 ++ ) {
T_1 V_224 ;
V_224 = V_239 [ 9 + V_252 + V_2 ] ;
V_182 += F_117 ( V_41 , V_224 ) ;
}
V_252 += 1 + V_255 ;
if ( V_253 == 1 )
V_254 = 2 ;
else if ( V_253 == 2 )
V_254 = 4 ;
else
V_254 = 0 ;
if ( V_23 < ( 8 + V_252 + V_256 - 1 ) )
goto V_49;
if ( V_256 < V_254 )
goto V_49;
if ( V_253 == 1 || V_253 == 2 ) {
V_258 = ( V_239 [ 8 + V_252 ] << 8 ) | V_239 [ 9 + V_252 ] ;
if ( V_253 == 2 )
V_257 = ( V_239 [ 10 + V_252 ] << 8 ) | V_239 [ 11 + V_252 ] ;
else
V_257 = 0xffff ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
if ( V_257 & ( 1 << V_2 ) )
V_182 += F_118 ( V_41 ,
V_258 ,
V_236 ,
V_237 , V_2 ) ;
}
}
V_252 += V_254 ;
for ( V_2 = 0 ; V_2 < ( V_256 - V_254 ) ; V_2 ++ ) {
int V_259 ;
struct V_60 * V_183 = NULL ;
unsigned int V_260 = 0 ;
bool V_261 ;
V_261 = ( ( V_239 [ 8 + V_252 + V_2 ] & 0x0f ) > 7 ) ;
if ( V_261 && ( V_2 + 1 == V_256 - V_254 ) )
break;
V_259 = V_239 [ 8 + V_252 + V_2 ] >> 4 ;
switch ( V_239 [ 8 + V_252 + V_2 ] & 0x0f ) {
case 0 :
V_260 = V_249 ;
break;
case 6 :
V_260 = V_250 ;
break;
case 8 :
if ( ( V_239 [ 9 + V_252 + V_2 ] >> 4 ) == 1 )
V_260 = V_251 ;
break;
}
if ( V_260 != 0 ) {
V_183 = F_111 ( V_41 ,
V_236 ,
V_237 ,
V_259 ) ;
if ( V_183 ) {
V_183 -> V_35 |= V_260 ;
F_73 ( V_41 , V_183 ) ;
V_182 ++ ;
}
}
if ( V_261 )
V_2 ++ ;
}
V_49:
return V_182 ;
}
static int
F_120 ( const T_1 * V_239 )
{
return V_239 [ 0 ] & 0x1f ;
}
static int
F_121 ( const T_1 * V_239 )
{
return V_239 [ 0 ] >> 5 ;
}
static int
F_122 ( const T_1 * V_262 )
{
return V_262 [ 1 ] ;
}
static int
F_123 ( const T_1 * V_262 , int * V_26 , int * V_263 )
{
* V_26 = 4 ;
* V_263 = V_262 [ 2 ] ;
if ( * V_263 == 0 )
* V_263 = 127 ;
if ( * V_263 < 4 || * V_263 > 127 )
return - V_264 ;
return 0 ;
}
static bool F_124 ( const T_1 * V_239 )
{
int V_265 ;
if ( F_121 ( V_239 ) != V_266 )
return false ;
if ( F_120 ( V_239 ) < 5 )
return false ;
V_265 = V_239 [ 1 ] | ( V_239 [ 2 ] << 8 ) | ( V_239 [ 3 ] << 16 ) ;
return V_265 == V_267 ;
}
static int
F_125 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
const T_1 * V_262 = F_92 ( V_12 ) ;
const T_1 * V_239 , * V_268 = NULL , * V_269 = NULL ;
T_1 V_270 , V_271 , V_237 = 0 ;
int V_182 = 0 ;
if ( V_262 && F_122 ( V_262 ) >= 3 ) {
int V_2 , V_26 , V_263 ;
if ( F_123 ( V_262 , & V_26 , & V_263 ) )
return 0 ;
F_126 (cea, i, start, end) {
V_239 = & V_262 [ V_2 ] ;
V_270 = F_120 ( V_239 ) ;
if ( F_121 ( V_239 ) == V_272 ) {
V_269 = V_239 + 1 ;
V_237 = V_270 ;
V_182 += F_112 ( V_41 , V_269 , V_270 ) ;
}
else if ( F_124 ( V_239 ) ) {
V_268 = V_239 ;
V_271 = V_270 ;
}
}
}
if ( V_268 )
V_182 += F_119 ( V_41 , V_268 , V_271 , V_269 ,
V_237 ) ;
return V_182 ;
}
static void F_89 ( struct V_60 * V_73 )
{
const struct V_60 * V_221 ;
int V_226 , V_227 , clock ;
T_1 V_224 ;
const char * type ;
V_224 = F_96 ( V_73 , 5 ) ;
if ( F_101 ( V_224 ) ) {
type = L_16 ;
V_221 = & V_225 [ V_224 ] ;
V_226 = V_221 -> clock ;
V_227 = F_94 ( V_221 ) ;
} else {
V_224 = F_104 ( V_73 , 5 ) ;
if ( F_106 ( V_224 ) ) {
type = L_17 ;
V_221 = & V_232 [ V_224 ] ;
V_226 = V_221 -> clock ;
V_227 = F_103 ( V_221 ) ;
} else {
return;
}
}
if ( abs ( V_73 -> clock - V_226 ) < abs ( V_73 -> clock - V_227 ) )
clock = V_226 ;
else
clock = V_227 ;
if ( V_73 -> clock == clock )
return;
F_7 ( L_18 ,
type , V_224 , V_73 -> clock , clock ) ;
V_73 -> clock = clock ;
}
static void
F_127 ( struct V_40 * V_41 , const T_1 * V_239 )
{
T_1 V_23 = F_120 ( V_239 ) ;
if ( V_23 >= 6 ) {
V_41 -> V_273 [ 5 ] |= ( V_239 [ 6 ] >> 7 ) << 1 ;
V_41 -> V_274 = V_239 [ 6 ] & 1 ;
}
if ( V_23 >= 7 )
V_41 -> V_275 = V_239 [ 7 ] * 5 ;
if ( V_23 >= 8 ) {
V_41 -> V_276 [ 0 ] = V_239 [ 8 ] >> 7 ;
V_41 -> V_276 [ 1 ] = ( V_239 [ 8 ] >> 6 ) & 1 ;
}
if ( V_23 >= 9 )
V_41 -> V_277 [ 0 ] = V_239 [ 9 ] ;
if ( V_23 >= 10 )
V_41 -> V_278 [ 0 ] = V_239 [ 10 ] ;
if ( V_23 >= 11 )
V_41 -> V_277 [ 1 ] = V_239 [ 11 ] ;
if ( V_23 >= 12 )
V_41 -> V_278 [ 1 ] = V_239 [ 12 ] ;
F_14 ( L_19
L_20
L_21
L_22
L_23 ,
V_41 -> V_274 ,
V_41 -> V_275 ,
( int ) V_41 -> V_276 [ 0 ] ,
( int ) V_41 -> V_276 [ 1 ] ,
V_41 -> V_277 [ 0 ] ,
V_41 -> V_277 [ 1 ] ,
V_41 -> V_278 [ 0 ] ,
V_41 -> V_278 [ 1 ] ) ;
}
static void
F_128 ( struct V_93 * V_61 , void * V_21 )
{
if ( V_61 -> V_21 . V_189 . type == V_279 )
* ( T_1 * * ) V_21 = V_61 -> V_21 . V_189 . V_21 . V_280 . V_280 ;
}
void F_129 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
T_6 * V_273 = V_41 -> V_273 ;
T_1 * V_262 ;
T_1 * V_39 ;
T_1 * V_239 ;
int V_281 = 0 ;
int V_282 ;
int V_270 ;
memset ( V_273 , 0 , sizeof( V_41 -> V_273 ) ) ;
V_262 = F_92 ( V_12 ) ;
if ( ! V_262 ) {
F_14 ( L_24 ) ;
return;
}
V_39 = NULL ;
F_43 ( ( T_1 * ) V_12 , F_128 , & V_39 ) ;
for ( V_282 = 0 ; V_39 && V_282 < 13 ; V_282 ++ ) {
if ( V_39 [ V_282 ] == 0x0a )
break;
V_273 [ 20 + V_282 ] = V_39 [ V_282 ] ;
}
V_273 [ 4 ] = ( V_262 [ 1 ] << 5 ) | V_282 ;
F_14 ( L_25 , V_273 + 20 ) ;
V_273 [ 0 ] = 2 << 3 ;
V_273 [ 16 ] = V_12 -> V_54 [ 0 ] ;
V_273 [ 17 ] = V_12 -> V_54 [ 1 ] ;
V_273 [ 18 ] = V_12 -> V_283 [ 0 ] ;
V_273 [ 19 ] = V_12 -> V_283 [ 1 ] ;
if ( F_122 ( V_262 ) >= 3 ) {
int V_2 , V_26 , V_263 ;
if ( F_123 ( V_262 , & V_26 , & V_263 ) ) {
V_26 = 0 ;
V_263 = 0 ;
}
F_126 (cea, i, start, end) {
V_239 = & V_262 [ V_2 ] ;
V_270 = F_120 ( V_239 ) ;
switch ( F_121 ( V_239 ) ) {
case V_284 :
V_281 = V_270 / 3 ;
if ( V_270 >= 1 )
memcpy ( V_273 + 20 + V_282 , & V_239 [ 1 ] , V_270 ) ;
break;
case V_285 :
if ( V_270 >= 1 )
V_273 [ 7 ] = V_239 [ 1 ] ;
break;
case V_266 :
if ( F_124 ( V_239 ) )
F_127 ( V_41 , V_239 ) ;
break;
default:
break;
}
}
}
V_273 [ 5 ] |= V_281 << 4 ;
V_273 [ V_286 ] =
F_130 ( F_131 ( V_273 ) , 4 ) ;
F_14 ( L_26 ,
F_132 ( V_273 ) , V_281 ) ;
}
int F_133 ( struct V_12 * V_12 , struct V_287 * * V_288 )
{
int V_289 = 0 ;
int V_2 , V_26 , V_263 , V_270 ;
T_1 * V_262 ;
V_262 = F_92 ( V_12 ) ;
if ( ! V_262 ) {
F_14 ( L_27 ) ;
return - V_290 ;
}
if ( F_122 ( V_262 ) < 3 ) {
F_14 ( L_28 ) ;
return - V_291 ;
}
if ( F_123 ( V_262 , & V_26 , & V_263 ) ) {
F_14 ( L_29 ) ;
return - V_292 ;
}
F_126 (cea, i, start, end) {
T_1 * V_239 = & V_262 [ V_2 ] ;
if ( F_121 ( V_239 ) == V_284 ) {
int V_42 ;
V_270 = F_120 ( V_239 ) ;
V_289 = V_270 / 3 ;
* V_288 = F_134 ( V_289 , sizeof( * * V_288 ) , V_48 ) ;
if ( ! * V_288 )
return - V_293 ;
for ( V_42 = 0 ; V_42 < V_289 ; V_42 ++ ) {
T_1 * V_294 = & V_239 [ 1 + V_42 * 3 ] ;
( * V_288 ) [ V_42 ] . V_295 = ( V_294 [ 0 ] & 0x78 ) >> 3 ;
( * V_288 ) [ V_42 ] . V_296 = V_294 [ 0 ] & 0x7 ;
( * V_288 ) [ V_42 ] . V_297 = V_294 [ 1 ] & 0x7F ;
( * V_288 ) [ V_42 ] . V_298 = V_294 [ 2 ] ;
}
break;
}
}
return V_289 ;
}
int F_135 ( struct V_12 * V_12 , T_1 * * V_299 )
{
int V_289 = 0 ;
int V_2 , V_26 , V_263 , V_270 ;
const T_1 * V_262 ;
V_262 = F_92 ( V_12 ) ;
if ( ! V_262 ) {
F_14 ( L_27 ) ;
return - V_290 ;
}
if ( F_122 ( V_262 ) < 3 ) {
F_14 ( L_28 ) ;
return - V_291 ;
}
if ( F_123 ( V_262 , & V_26 , & V_263 ) ) {
F_14 ( L_29 ) ;
return - V_292 ;
}
F_126 (cea, i, start, end) {
const T_1 * V_239 = & V_262 [ V_2 ] ;
if ( F_121 ( V_239 ) == V_285 ) {
V_270 = F_120 ( V_239 ) ;
if ( V_270 == 3 ) {
* V_299 = F_25 ( & V_239 [ 1 ] , V_270 , V_48 ) ;
if ( ! * V_299 )
return - V_293 ;
V_289 = V_270 ;
break;
}
}
}
return V_289 ;
}
int F_136 ( struct V_40 * V_41 ,
const struct V_60 * V_73 )
{
int V_2 = ! ! ( V_73 -> V_35 & V_130 ) ;
int V_108 , V_300 ;
if ( ! V_41 -> V_276 [ 0 ] )
return 0 ;
if ( ! V_41 -> V_276 [ 1 ] )
V_2 = 0 ;
V_108 = V_41 -> V_278 [ V_2 ] ;
V_300 = V_41 -> V_277 [ V_2 ] ;
if ( V_108 == 255 || V_300 == 255 )
return 0 ;
if ( V_108 )
V_108 = F_42 ( 2 * ( V_108 - 1 ) , 500 ) ;
if ( V_300 )
V_300 = F_42 ( 2 * ( V_300 - 1 ) , 500 ) ;
return F_137 ( V_300 - V_108 , 0 ) ;
}
struct V_40 * F_138 ( struct V_301 * V_302 )
{
struct V_40 * V_41 ;
struct V_80 * V_52 = V_302 -> V_52 ;
F_6 ( ! F_139 ( & V_52 -> V_303 . V_304 ) ) ;
F_6 ( ! F_140 ( & V_52 -> V_303 . V_305 ) ) ;
F_141 (connector, dev)
if ( V_41 -> V_302 == V_302 && V_41 -> V_273 [ 0 ] )
return V_41 ;
return NULL ;
}
bool F_142 ( struct V_12 * V_12 )
{
T_1 * V_219 ;
int V_2 ;
int V_306 , V_307 ;
V_219 = F_92 ( V_12 ) ;
if ( ! V_219 )
return false ;
if ( F_123 ( V_219 , & V_306 , & V_307 ) )
return false ;
F_126 (edid_ext, i, start_offset, end_offset) {
if ( F_124 ( & V_219 [ V_2 ] ) )
return true ;
}
return false ;
}
bool F_143 ( struct V_12 * V_12 )
{
T_1 * V_219 ;
int V_2 , V_42 ;
bool V_308 = false ;
int V_306 , V_307 ;
V_219 = F_92 ( V_12 ) ;
if ( ! V_219 )
goto V_263;
V_308 = ( ( V_219 [ 3 ] & V_309 ) != 0 ) ;
if ( V_308 ) {
F_14 ( L_30 ) ;
goto V_263;
}
if ( F_123 ( V_219 , & V_306 , & V_307 ) )
goto V_263;
F_126 (edid_ext, i, start_offset, end_offset) {
if ( F_121 ( & V_219 [ V_2 ] ) == V_284 ) {
V_308 = true ;
for ( V_42 = 1 ; V_42 < F_120 ( & V_219 [ V_2 ] ) + 1 ; V_42 += 3 )
F_14 ( L_31 ,
( V_219 [ V_2 + V_42 ] >> 3 ) & 0xf ) ;
goto V_263;
}
}
V_263:
return V_308 ;
}
bool F_144 ( struct V_12 * V_12 )
{
T_1 * V_219 ;
int V_2 , V_26 , V_263 ;
V_219 = F_92 ( V_12 ) ;
if ( ! V_219 )
return false ;
if ( F_123 ( V_219 , & V_26 , & V_263 ) )
return false ;
F_126 (edid_ext, i, start, end) {
if ( F_121 ( & V_219 [ V_2 ] ) == V_310 &&
F_120 ( & V_219 [ V_2 ] ) == 2 ) {
F_14 ( L_32 , V_219 [ V_2 + 2 ] ) ;
return V_219 [ V_2 + 2 ] & V_311 ;
}
}
return false ;
}
static bool F_145 ( struct V_12 * V_12 ,
struct V_312 * V_313 ,
struct V_40 * V_41 )
{
T_1 * V_219 , * V_268 ;
int V_2 ;
int V_306 , V_307 ;
unsigned int V_314 = 0 ;
V_219 = F_92 ( V_12 ) ;
if ( ! V_219 )
return false ;
if ( F_123 ( V_219 , & V_306 , & V_307 ) )
return false ;
F_126 (edid_ext, i, start_offset, end_offset) {
if ( F_124 ( & V_219 [ V_2 ] ) ) {
V_313 -> V_315 = 8 ;
V_268 = & V_219 [ V_2 ] ;
if ( F_120 ( V_268 ) < 6 )
return false ;
if ( V_268 [ 6 ] & V_316 ) {
V_314 = 10 ;
V_313 -> V_317 |= V_316 ;
F_7 ( L_33 ,
V_41 -> V_39 ) ;
}
if ( V_268 [ 6 ] & V_318 ) {
V_314 = 12 ;
V_313 -> V_317 |= V_318 ;
F_7 ( L_34 ,
V_41 -> V_39 ) ;
}
if ( V_268 [ 6 ] & V_319 ) {
V_314 = 16 ;
V_313 -> V_317 |= V_319 ;
F_7 ( L_35 ,
V_41 -> V_39 ) ;
}
if ( V_314 > 0 ) {
F_7 ( L_36 ,
V_41 -> V_39 , V_314 ) ;
V_313 -> V_315 = V_314 ;
V_313 -> V_320 = V_321 ;
if ( V_268 [ 6 ] & V_322 ) {
V_313 -> V_320 |= V_323 ;
F_7 ( L_37 ,
V_41 -> V_39 ) ;
}
if ( ! ( V_268 [ 6 ] & V_318 ) ) {
F_7 ( L_38 ,
V_41 -> V_39 ) ;
}
return true ;
}
else {
F_7 ( L_39 ,
V_41 -> V_39 ) ;
}
}
}
return false ;
}
static void F_146 ( struct V_12 * V_12 ,
struct V_312 * V_313 ,
struct V_40 * V_41 )
{
T_1 * V_219 ;
V_313 -> V_164 = V_12 -> V_171 * 10 ;
V_313 -> V_167 = V_12 -> V_172 * 10 ;
V_313 -> V_315 = 0 ;
V_313 -> V_320 = 0 ;
if ( V_12 -> V_16 < 3 )
return;
if ( ! ( V_12 -> V_100 & V_101 ) )
return;
V_219 = F_92 ( V_12 ) ;
if ( V_219 ) {
V_313 -> V_324 = V_219 [ 1 ] ;
V_313 -> V_320 = V_321 ;
if ( V_219 [ 3 ] & V_325 )
V_313 -> V_320 |= V_323 ;
if ( V_219 [ 3 ] & V_326 )
V_313 -> V_320 |= V_327 ;
}
F_145 ( V_12 , V_313 , V_41 ) ;
if ( V_12 -> V_16 < 4 )
return;
switch ( V_12 -> V_100 & V_328 ) {
case V_329 :
V_313 -> V_315 = 6 ;
break;
case V_330 :
V_313 -> V_315 = 8 ;
break;
case V_331 :
V_313 -> V_315 = 10 ;
break;
case V_332 :
V_313 -> V_315 = 12 ;
break;
case V_333 :
V_313 -> V_315 = 14 ;
break;
case V_334 :
V_313 -> V_315 = 16 ;
break;
case V_335 :
default:
V_313 -> V_315 = 0 ;
break;
}
F_7 ( L_40 ,
V_41 -> V_39 , V_313 -> V_315 ) ;
V_313 -> V_320 |= V_321 ;
if ( V_12 -> V_102 & V_336 )
V_313 -> V_320 |= V_323 ;
if ( V_12 -> V_102 & V_337 )
V_313 -> V_320 |= V_327 ;
}
int F_147 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
int V_338 = 0 ;
T_3 V_59 ;
if ( V_12 == NULL ) {
return 0 ;
}
if ( ! F_11 ( V_12 ) ) {
F_19 ( V_41 -> V_52 -> V_52 , L_41 ,
V_41 -> V_39 ) ;
return 0 ;
}
V_59 = F_27 ( V_12 ) ;
V_338 += F_90 ( V_41 , V_12 , V_59 ) ;
V_338 += F_87 ( V_41 , V_12 ) ;
V_338 += F_84 ( V_41 , V_12 ) ;
V_338 += F_82 ( V_41 , V_12 ) ;
V_338 += F_125 ( V_41 , V_12 ) ;
V_338 += F_107 ( V_41 , V_12 ) ;
if ( V_12 -> V_102 & V_103 )
V_338 += F_79 ( V_41 , V_12 ) ;
if ( V_59 & ( V_68 | V_69 ) )
F_30 ( V_41 , V_59 ) ;
F_146 ( V_12 , & V_41 -> V_339 , V_41 ) ;
if ( V_59 & V_340 )
V_41 -> V_339 . V_315 = 8 ;
if ( V_59 & V_341 )
V_41 -> V_339 . V_315 = 12 ;
return V_338 ;
}
int F_148 ( struct V_40 * V_41 ,
int V_75 , int V_79 )
{
int V_2 , V_289 , V_338 = 0 ;
struct V_60 * V_73 ;
struct V_80 * V_52 = V_41 -> V_52 ;
V_289 = F_28 ( V_85 ) ;
if ( V_75 < 0 )
V_75 = 0 ;
if ( V_79 < 0 )
V_79 = 0 ;
for ( V_2 = 0 ; V_2 < V_289 ; V_2 ++ ) {
const struct V_60 * V_86 = & V_85 [ V_2 ] ;
if ( V_75 && V_79 ) {
if ( V_86 -> V_75 > V_75 ||
V_86 -> V_79 > V_79 )
continue;
}
if ( F_35 ( V_86 ) > 61 )
continue;
V_73 = F_39 ( V_52 , V_86 ) ;
if ( V_73 ) {
F_73 ( V_41 , V_73 ) ;
V_338 ++ ;
}
}
return V_338 ;
}
void F_149 ( struct V_40 * V_41 ,
int V_342 , int V_343 )
{
struct V_60 * V_73 ;
F_55 (mode, &connector->probed_modes, head) {
if ( V_73 -> V_75 == V_342 &&
V_73 -> V_79 == V_343 )
V_73 -> type |= V_71 ;
}
}
int
F_150 ( struct V_344 * V_345 ,
const struct V_60 * V_73 )
{
int V_346 ;
if ( ! V_345 || ! V_73 )
return - V_347 ;
V_346 = F_151 ( V_345 ) ;
if ( V_346 < 0 )
return V_346 ;
if ( V_73 -> V_35 & V_348 )
V_345 -> V_349 = 1 ;
V_345 -> V_229 = F_98 ( V_73 ) ;
V_345 -> V_350 = V_351 ;
if ( V_73 -> V_230 == V_352 ||
V_73 -> V_230 == V_353 )
V_345 -> V_350 = V_73 -> V_230 ;
else if ( V_345 -> V_229 > 0 )
V_345 -> V_350 = F_102 (
V_345 -> V_229 ) ;
V_345 -> V_354 = V_355 ;
V_345 -> V_356 = V_357 ;
return 0 ;
}
static enum V_358
F_152 ( const struct V_60 * V_73 )
{
T_3 V_359 = V_73 -> V_35 & V_235 ;
switch ( V_359 ) {
case V_249 :
return V_360 ;
case V_361 :
return V_362 ;
case V_363 :
return V_364 ;
case V_365 :
return V_366 ;
case V_367 :
return V_368 ;
case V_369 :
return V_370 ;
case V_250 :
return V_371 ;
case V_251 :
return V_372 ;
default:
return V_373 ;
}
}
int
F_153 ( struct V_374 * V_345 ,
const struct V_60 * V_73 )
{
int V_346 ;
T_3 V_375 ;
T_1 V_224 ;
if ( ! V_345 || ! V_73 )
return - V_347 ;
V_224 = F_105 ( V_73 ) ;
V_375 = V_73 -> V_35 & V_235 ;
if ( ! V_224 && ! V_375 )
return - V_347 ;
if ( V_224 && V_375 )
return - V_347 ;
V_346 = F_154 ( V_345 ) ;
if ( V_346 < 0 )
return V_346 ;
if ( V_224 )
V_345 -> V_224 = V_224 ;
else
V_345 -> V_376 = F_152 ( V_73 ) ;
return 0 ;
}
static int F_155 ( struct V_40 * V_41 ,
T_1 * V_377 , int V_8 ,
bool V_378 )
{
int V_379 = 0 ;
struct V_380 * V_381 ;
struct V_382 * V_9 ;
T_1 V_5 = 0 ;
int V_2 ;
if ( V_378 )
V_379 = 1 ;
V_381 = (struct V_380 * ) & V_377 [ V_379 ] ;
F_14 ( L_42 ,
V_381 -> V_383 , V_381 -> V_384 , V_381 -> V_385 , V_381 -> V_386 ) ;
if ( V_381 -> V_384 + 5 > V_8 - V_379 )
return - V_347 ;
for ( V_2 = V_379 ; V_2 <= V_381 -> V_384 + 5 ; V_2 ++ ) {
V_5 += V_377 [ V_2 ] ;
}
if ( V_5 ) {
F_8 ( L_43 , V_5 ) ;
return - V_347 ;
}
V_9 = (struct V_382 * ) & V_377 [ V_379 + 4 ] ;
F_14 ( L_44 ,
V_9 -> V_387 , V_9 -> V_383 , V_9 -> V_388 ) ;
switch ( V_9 -> V_387 ) {
case V_389 : {
struct V_390 * V_391 = (struct V_390 * ) V_9 ;
T_5 V_123 , V_124 ;
T_1 V_392 , V_393 ;
T_1 V_394 , V_395 ;
struct V_396 * V_397 ;
V_123 = V_391 -> V_398 [ 0 ] | V_391 -> V_398 [ 1 ] << 8 ;
V_124 = V_391 -> V_398 [ 2 ] | V_391 -> V_398 [ 3 ] << 8 ;
V_394 = ( V_391 -> V_399 [ 0 ] & 0xf ) | ( V_391 -> V_399 [ 2 ] & 0x30 ) ;
V_395 = ( V_391 -> V_399 [ 0 ] >> 4 ) | ( ( V_391 -> V_399 [ 2 ] >> 2 ) & 0x30 ) ;
V_392 = ( V_391 -> V_399 [ 1 ] & 0xf ) | ( ( V_391 -> V_399 [ 2 ] & 0x3 ) << 4 ) ;
V_393 = ( V_391 -> V_399 [ 1 ] >> 4 ) | ( ( ( V_391 -> V_399 [ 2 ] >> 2 ) & 0x3 ) << 4 ) ;
V_41 -> V_400 = true ;
if ( V_391 -> V_401 & 0x80 )
V_41 -> V_402 = true ;
V_41 -> V_395 = V_395 + 1 ;
V_41 -> V_394 = V_394 + 1 ;
V_41 -> V_393 = V_393 ;
V_41 -> V_392 = V_392 ;
V_41 -> V_403 = V_123 + 1 ;
V_41 -> V_404 = V_124 + 1 ;
F_14 ( L_45 , V_391 -> V_401 ) ;
F_14 ( L_46 , V_123 + 1 , V_124 + 1 ) ;
F_14 ( L_47 ,
V_395 + 1 , V_394 + 1 , V_393 , V_392 ) ;
F_14 ( L_48 , V_391 -> V_405 [ 0 ] , V_391 -> V_405 [ 1 ] , V_391 -> V_405 [ 2 ] ) ;
V_397 = F_156 ( V_41 -> V_52 , V_391 -> V_405 ) ;
if ( ! V_397 ) {
V_397 = F_157 ( V_41 -> V_52 , V_391 -> V_405 ) ;
}
if ( ! V_397 )
return - V_293 ;
if ( V_41 -> V_406 != V_397 ) {
if ( V_41 -> V_406 ) {
F_158 ( V_41 -> V_52 , V_41 -> V_406 ) ;
}
V_41 -> V_406 = V_397 ;
} else
F_158 ( V_41 -> V_52 , V_397 ) ;
}
break;
default:
F_9 ( L_49 , V_9 -> V_387 ) ;
break;
}
return 0 ;
}
static void F_23 ( struct V_40 * V_41 ,
struct V_12 * V_12 )
{
void * V_377 = NULL ;
int V_29 ;
V_41 -> V_400 = false ;
V_377 = F_93 ( V_12 ) ;
if ( ! V_377 ) {
goto V_407;
}
V_29 = F_155 ( V_41 , V_377 , V_6 , true ) ;
if ( V_29 < 0 )
goto V_407;
if ( ! V_41 -> V_400 )
goto V_407;
return;
V_407:
if ( V_41 -> V_406 ) {
F_158 ( V_41 -> V_52 , V_41 -> V_406 ) ;
V_41 -> V_406 = NULL ;
}
return;
}
