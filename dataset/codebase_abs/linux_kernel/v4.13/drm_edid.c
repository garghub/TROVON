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
if ( V_11 )
* V_11 = true ;
if ( V_1 [ 0 ] == V_15 ) {
F_7 ( L_2 , V_5 ) ;
F_7 ( L_3 ) ;
} else {
if ( V_10 )
F_8 ( L_2 , V_5 ) ;
goto V_14;
}
}
switch ( V_1 [ 0 ] ) {
case 0 :
if ( V_12 -> V_16 != 1 ) {
F_8 ( L_4 , V_12 -> V_16 ) ;
goto V_14;
}
if ( V_12 -> V_17 > 4 )
F_7 ( L_5 ) ;
break;
default:
break;
}
return true ;
V_14:
if ( V_10 ) {
if ( F_3 ( V_1 , V_6 ) ) {
F_9 ( L_6 ) ;
} else {
F_9 ( L_7 ) ;
F_10 ( V_18 ,
L_8 , V_19 , 16 , 1 ,
V_1 , V_6 , false ) ;
}
}
return false ;
}
bool F_11 ( struct V_12 * V_12 )
{
int V_2 ;
T_1 * V_20 = ( T_1 * ) V_12 ;
if ( ! V_12 )
return false ;
for ( V_2 = 0 ; V_2 <= V_12 -> V_21 ; V_2 ++ )
if ( ! F_5 ( V_20 + V_2 * V_6 , V_2 , true , NULL ) )
return false ;
return true ;
}
static int
F_12 ( void * V_22 , T_1 * V_23 , unsigned int V_9 , T_2 V_24 )
{
struct V_25 * V_26 = V_22 ;
unsigned char V_27 = V_9 * V_6 ;
unsigned char V_28 = V_9 >> 1 ;
unsigned char V_29 = V_28 ? 3 : 2 ;
int V_30 , V_31 = 5 ;
do {
struct V_32 V_33 [] = {
{
. V_34 = V_35 ,
. V_36 = 0 ,
. V_24 = 1 ,
. V_23 = & V_28 ,
} , {
. V_34 = V_37 ,
. V_36 = 0 ,
. V_24 = 1 ,
. V_23 = & V_27 ,
} , {
. V_34 = V_37 ,
. V_36 = V_38 ,
. V_24 = V_24 ,
. V_23 = V_23 ,
}
} ;
V_30 = F_13 ( V_26 , & V_33 [ 3 - V_29 ] , V_29 ) ;
if ( V_30 == - V_39 ) {
F_14 ( L_9 ,
V_26 -> V_40 ) ;
break;
}
} while ( V_30 != V_29 && -- V_31 );
return V_30 == V_29 ? 0 : - 1 ;
}
static void F_15 ( struct V_41 * V_42 ,
T_1 * V_12 , int V_43 )
{
int V_2 ;
if ( V_42 -> V_44 ++ && ! ( V_45 & V_46 ) )
return;
F_16 ( V_42 -> V_47 -> V_47 ,
L_10 ,
V_42 -> V_40 ) ;
for ( V_2 = 0 ; V_2 < V_43 ; V_2 ++ ) {
T_1 * V_9 = V_12 + V_2 * V_6 ;
char V_48 [ 20 ] ;
if ( F_3 ( V_9 , V_6 ) )
sprintf ( V_48 , L_11 , V_2 ) ;
else if ( ! F_5 ( V_9 , V_2 , false , NULL ) )
sprintf ( V_48 , L_12 , V_2 ) ;
else
sprintf ( V_48 , L_13 , V_2 ) ;
F_10 ( V_49 ,
V_48 , V_19 , 16 , 1 ,
V_9 , V_6 , false ) ;
}
}
struct V_12 * F_17 ( struct V_41 * V_42 ,
int (* F_18)( void * V_22 , T_1 * V_23 , unsigned int V_9 ,
T_2 V_24 ) ,
void * V_22 )
{
int V_2 , V_50 = 0 , V_51 = 0 ;
T_1 * V_12 , * V_52 ;
if ( ( V_12 = F_19 ( V_6 , V_53 ) ) == NULL )
return NULL ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_18 ( V_22 , V_12 , 0 , V_6 ) )
goto V_54;
if ( F_5 ( V_12 , 0 , false ,
& V_42 -> V_11 ) )
break;
if ( V_2 == 0 && F_3 ( V_12 , V_6 ) ) {
V_42 -> V_55 ++ ;
goto V_56;
}
}
if ( V_2 == 4 )
goto V_56;
V_51 = V_12 [ 0x7e ] ;
if ( V_51 == 0 )
return (struct V_12 * ) V_12 ;
V_52 = F_20 ( V_12 , ( V_51 + 1 ) * V_6 , V_53 ) ;
if ( ! V_52 )
goto V_54;
V_12 = V_52 ;
for ( V_50 = 1 ; V_50 <= V_12 [ 0x7e ] ; V_50 ++ ) {
T_1 * V_9 = V_12 + V_50 * V_6 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_18 ( V_22 , V_9 , V_50 , V_6 ) )
goto V_54;
if ( F_5 ( V_9 , V_50 , false , NULL ) )
break;
}
if ( V_2 == 4 )
V_51 -- ;
}
if ( V_51 != V_12 [ 0x7e ] ) {
T_1 * V_57 ;
F_15 ( V_42 , V_12 , V_12 [ 0x7e ] + 1 ) ;
V_12 [ V_6 - 1 ] += V_12 [ 0x7e ] - V_51 ;
V_12 [ 0x7e ] = V_51 ;
V_52 = F_19 ( ( V_51 + 1 ) * V_6 , V_53 ) ;
if ( ! V_52 )
goto V_54;
V_57 = V_52 ;
for ( V_2 = 0 ; V_2 <= V_12 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_9 = V_12 + V_2 * V_6 ;
if ( ! F_5 ( V_9 , V_2 , false , NULL ) )
continue;
memcpy ( V_57 , V_9 , V_6 ) ;
V_57 += V_6 ;
}
F_21 ( V_12 ) ;
V_12 = V_52 ;
}
return (struct V_12 * ) V_12 ;
V_56:
F_15 ( V_42 , V_12 , 1 ) ;
V_54:
F_21 ( V_12 ) ;
return NULL ;
}
bool
F_22 ( struct V_25 * V_26 )
{
unsigned char V_54 ;
return ( F_12 ( V_26 , & V_54 , 0 , 1 ) == 0 ) ;
}
struct V_12 * F_23 ( struct V_41 * V_42 ,
struct V_25 * V_26 )
{
struct V_12 * V_12 ;
if ( V_42 -> V_58 == V_59 )
return NULL ;
if ( V_42 -> V_58 == V_60 && ! F_22 ( V_26 ) )
return NULL ;
V_12 = F_17 ( V_42 , F_12 , V_26 ) ;
if ( V_12 )
F_24 ( V_42 , V_12 ) ;
return V_12 ;
}
struct V_12 * F_25 ( struct V_41 * V_42 ,
struct V_25 * V_26 )
{
struct V_61 * V_62 = V_42 -> V_47 -> V_62 ;
struct V_12 * V_12 ;
F_26 ( V_62 ) ;
V_12 = F_23 ( V_42 , V_26 ) ;
F_27 ( V_62 ) ;
return V_12 ;
}
struct V_12 * F_28 ( const struct V_12 * V_12 )
{
return F_29 ( V_12 , ( V_12 -> V_21 + 1 ) * V_6 , V_53 ) ;
}
static bool F_30 ( struct V_12 * V_12 , const char * V_63 )
{
char F_30 [ 3 ] ;
F_30 [ 0 ] = ( ( V_12 -> V_64 [ 0 ] & 0x7c ) >> 2 ) + '@' ;
F_30 [ 1 ] = ( ( ( V_12 -> V_64 [ 0 ] & 0x3 ) << 3 ) |
( ( V_12 -> V_64 [ 1 ] & 0xe0 ) >> 5 ) ) + '@' ;
F_30 [ 2 ] = ( V_12 -> V_64 [ 1 ] & 0x1f ) + '@' ;
return ! strncmp ( F_30 , V_63 , 3 ) ;
}
static T_3 F_31 ( struct V_12 * V_12 )
{
const struct V_65 * V_66 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_32 ( V_67 ) ; V_2 ++ ) {
V_66 = & V_67 [ V_2 ] ;
if ( F_30 ( V_12 , V_66 -> V_63 ) &&
( F_33 ( V_12 ) == V_66 -> V_68 ) )
return V_66 -> V_69 ;
}
return 0 ;
}
static void F_34 ( struct V_41 * V_42 ,
T_3 V_69 )
{
struct V_70 * V_71 , * V_72 , * V_73 ;
int V_74 = 0 ;
int V_75 , V_76 ;
if ( F_35 ( & V_42 -> V_77 ) )
return;
if ( V_69 & V_78 )
V_74 = 60 ;
if ( V_69 & V_79 )
V_74 = 75 ;
V_73 = F_36 ( & V_42 -> V_77 ,
struct V_70 , V_80 ) ;
F_37 (cur_mode, t, &connector->probed_modes, head) {
V_72 -> type &= ~ V_81 ;
if ( V_72 == V_73 )
continue;
if ( F_38 ( V_72 ) > F_38 ( V_73 ) )
V_73 = V_72 ;
V_75 = V_72 -> V_82 ?
V_72 -> V_82 : F_39 ( V_72 ) ;
V_76 = V_73 -> V_82 ?
V_73 -> V_82 : F_39 ( V_73 ) ;
if ( ( F_38 ( V_72 ) == F_38 ( V_73 ) ) &&
F_40 ( V_75 , V_74 ) <
F_40 ( V_76 , V_74 ) ) {
V_73 = V_72 ;
}
}
V_73 -> type |= V_81 ;
}
static bool
F_41 ( const struct V_70 * V_83 )
{
return ( V_83 -> V_84 - V_83 -> V_85 == 160 ) &&
( V_83 -> V_86 - V_83 -> V_85 == 80 ) &&
( V_83 -> V_86 - V_83 -> V_87 == 32 ) &&
( V_83 -> V_88 - V_83 -> V_89 == 3 ) ;
}
struct V_70 * F_42 ( struct V_90 * V_47 ,
int V_91 , int V_92 , int V_93 ,
bool V_94 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_32 ( V_95 ) ; V_2 ++ ) {
const struct V_70 * V_96 = & V_95 [ V_2 ] ;
if ( V_91 != V_96 -> V_85 )
continue;
if ( V_92 != V_96 -> V_89 )
continue;
if ( V_93 != F_39 ( V_96 ) )
continue;
if ( V_94 != F_41 ( V_96 ) )
continue;
return F_43 ( V_47 , V_96 ) ;
}
return NULL ;
}
static void
F_44 ( T_1 * V_97 , T_4 * V_98 , void * V_99 )
{
int V_2 , V_100 = 0 ;
T_1 V_101 = V_97 [ 0x02 ] ;
T_1 * V_102 = V_97 + V_101 ;
V_100 = ( 127 - V_101 ) / 18 ;
for ( V_2 = 0 ; V_2 < V_100 ; V_2 ++ )
V_98 ( (struct V_103 * ) ( V_102 + 18 * V_2 ) , V_99 ) ;
}
static void
F_45 ( T_1 * V_97 , T_4 * V_98 , void * V_99 )
{
unsigned int V_2 , V_100 = F_46 ( ( int ) V_97 [ 0x02 ] , 6 ) ;
T_1 * V_102 = V_97 + 5 ;
if ( V_97 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_100 ; V_2 ++ )
V_98 ( (struct V_103 * ) ( V_102 + 18 * V_2 ) , V_99 ) ;
}
static void
F_47 ( T_1 * V_1 , T_4 * V_98 , void * V_99 )
{
int V_2 ;
struct V_12 * V_12 = (struct V_12 * ) V_1 ;
if ( V_12 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_104 ; V_2 ++ )
V_98 ( & ( V_12 -> V_105 [ V_2 ] ) , V_99 ) ;
for ( V_2 = 1 ; V_2 <= V_1 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_97 = V_1 + ( V_2 * V_6 ) ;
switch ( * V_97 ) {
case V_15 :
F_44 ( V_97 , V_98 , V_99 ) ;
break;
case V_106 :
F_45 ( V_97 , V_98 , V_99 ) ;
break;
default:
break;
}
}
}
static void
F_48 ( struct V_103 * V_71 , void * V_22 )
{
T_1 * V_107 = ( T_1 * ) V_71 ;
if ( V_107 [ 3 ] == V_108 )
if ( V_107 [ 15 ] & 0x10 )
* ( bool * ) V_22 = true ;
}
static bool
F_49 ( struct V_12 * V_12 )
{
if ( V_12 -> V_17 >= 4 ) {
bool V_30 = false ;
F_47 ( ( T_1 * ) V_12 , F_48 , & V_30 ) ;
return V_30 ;
}
return ( ( V_12 -> V_109 & V_110 ) != 0 ) ;
}
static void
F_50 ( struct V_103 * V_71 , void * V_22 )
{
T_1 * V_107 = ( T_1 * ) V_71 ;
if ( V_107 [ 3 ] == V_108 && V_107 [ 10 ] == 0x02 )
* ( T_1 * * ) V_22 = V_107 ;
}
static int
F_51 ( struct V_12 * V_12 )
{
T_1 * V_107 = NULL ;
F_47 ( ( T_1 * ) V_12 , F_50 , & V_107 ) ;
return V_107 ? ( V_107 [ 12 ] * 2 ) : 0 ;
}
static int
F_52 ( struct V_12 * V_12 )
{
T_1 * V_107 = NULL ;
F_47 ( ( T_1 * ) V_12 , F_50 , & V_107 ) ;
return V_107 ? V_107 [ 13 ] : 0 ;
}
static int
F_53 ( struct V_12 * V_12 )
{
T_1 * V_107 = NULL ;
F_47 ( ( T_1 * ) V_12 , F_50 , & V_107 ) ;
return V_107 ? ( V_107 [ 15 ] << 8 ) + V_107 [ 14 ] : 0 ;
}
static int
F_54 ( struct V_12 * V_12 )
{
T_1 * V_107 = NULL ;
F_47 ( ( T_1 * ) V_12 , F_50 , & V_107 ) ;
return V_107 ? V_107 [ 16 ] : 0 ;
}
static int
F_55 ( struct V_12 * V_12 )
{
T_1 * V_107 = NULL ;
F_47 ( ( T_1 * ) V_12 , F_50 , & V_107 ) ;
return V_107 ? V_107 [ 17 ] : 0 ;
}
static int F_56 ( struct V_12 * V_12 )
{
if ( V_12 -> V_17 >= 2 ) {
if ( V_12 -> V_17 >= 4 && ( V_12 -> V_111 & V_112 ) )
return V_113 ;
if ( F_51 ( V_12 ) )
return V_114 ;
return V_115 ;
}
return V_116 ;
}
static int
F_57 ( T_1 V_117 , T_1 V_118 )
{
return ( V_117 == 0x00 && V_118 == 0x00 ) ||
( V_117 == 0x01 && V_118 == 0x01 ) ||
( V_117 == 0x20 && V_118 == 0x20 ) ;
}
static struct V_70 *
F_58 ( struct V_41 * V_42 , struct V_12 * V_12 ,
struct V_119 * V_71 )
{
struct V_90 * V_47 = V_42 -> V_47 ;
struct V_70 * V_120 , * V_83 = NULL ;
int V_91 , V_92 ;
int V_121 ;
unsigned V_122 = ( V_71 -> V_123 & V_124 )
>> V_125 ;
unsigned V_126 = ( V_71 -> V_123 & V_127 )
>> V_128 ;
int V_129 = F_56 ( V_12 ) ;
if ( F_57 ( V_71 -> V_91 , V_71 -> V_123 ) )
return NULL ;
V_91 = V_71 -> V_91 * 8 + 248 ;
V_121 = V_126 + 60 ;
if ( V_122 == 0 ) {
if ( V_12 -> V_17 < 3 )
V_92 = V_91 ;
else
V_92 = ( V_91 * 10 ) / 16 ;
} else if ( V_122 == 1 )
V_92 = ( V_91 * 3 ) / 4 ;
else if ( V_122 == 2 )
V_92 = ( V_91 * 4 ) / 5 ;
else
V_92 = ( V_91 * 9 ) / 16 ;
if ( V_121 == 60 &&
( ( V_91 == 1360 && V_92 == 765 ) ||
( V_91 == 1368 && V_92 == 769 ) ) ) {
V_91 = 1366 ;
V_92 = 768 ;
}
F_59 (m, &connector->probed_modes, head)
if ( V_120 -> V_85 == V_91 && V_120 -> V_89 == V_92 &&
F_39 ( V_120 ) == V_121 )
return NULL ;
if ( V_91 == 1366 && V_92 == 768 && V_121 == 60 ) {
V_83 = F_60 ( V_47 , 1366 , 768 , V_121 , 0 , 0 ,
false ) ;
V_83 -> V_85 = 1366 ;
V_83 -> V_87 = V_83 -> V_87 - 1 ;
V_83 -> V_86 = V_83 -> V_86 - 1 ;
return V_83 ;
}
if ( F_49 ( V_12 ) ) {
V_83 = F_42 ( V_47 , V_91 , V_92 , V_121 ,
true ) ;
if ( V_83 )
return V_83 ;
}
V_83 = F_42 ( V_47 , V_91 , V_92 , V_121 , false ) ;
if ( V_83 )
return V_83 ;
switch ( V_129 ) {
case V_116 :
break;
case V_115 :
V_83 = F_61 ( V_47 , V_91 , V_92 , V_121 , 0 , 0 ) ;
break;
case V_114 :
V_83 = F_61 ( V_47 , V_91 , V_92 , V_121 , 0 , 0 ) ;
if ( ! V_83 )
return NULL ;
if ( F_62 ( V_83 ) > F_51 ( V_12 ) ) {
F_63 ( V_47 , V_83 ) ;
V_83 = F_64 ( V_47 , V_91 , V_92 ,
V_121 , 0 , 0 ,
F_53 ( V_12 ) ,
F_52 ( V_12 ) ,
F_54 ( V_12 ) ,
F_55 ( V_12 ) ) ;
}
break;
case V_113 :
V_83 = F_60 ( V_47 , V_91 , V_92 , V_121 , 0 , 0 ,
false ) ;
break;
}
return V_83 ;
}
static void
F_65 ( struct V_70 * V_83 ,
struct V_130 * V_131 )
{
int V_2 ;
static const struct {
int V_132 , V_133 ;
} V_134 [] = {
{ 1920 , 1080 } ,
{ 720 , 480 } ,
{ 1440 , 480 } ,
{ 2880 , 480 } ,
{ 720 , 576 } ,
{ 1440 , 576 } ,
{ 2880 , 576 } ,
} ;
if ( ! ( V_131 -> V_135 & V_136 ) )
return;
for ( V_2 = 0 ; V_2 < F_32 ( V_134 ) ; V_2 ++ ) {
if ( ( V_83 -> V_85 == V_134 [ V_2 ] . V_132 ) &&
( V_83 -> V_89 == V_134 [ V_2 ] . V_133 / 2 ) ) {
V_83 -> V_89 *= 2 ;
V_83 -> V_88 *= 2 ;
V_83 -> V_137 *= 2 ;
V_83 -> V_138 *= 2 ;
V_83 -> V_138 |= 1 ;
}
}
V_83 -> V_36 |= V_139 ;
}
static struct V_70 * F_66 ( struct V_90 * V_47 ,
struct V_12 * V_12 ,
struct V_103 * V_140 ,
T_3 V_69 )
{
struct V_70 * V_83 ;
struct V_130 * V_131 = & V_140 -> V_22 . V_141 ;
unsigned V_142 = ( V_131 -> V_143 & 0xf0 ) << 4 | V_131 -> V_144 ;
unsigned V_145 = ( V_131 -> V_146 & 0xf0 ) << 4 | V_131 -> V_147 ;
unsigned V_148 = ( V_131 -> V_143 & 0xf ) << 8 | V_131 -> V_149 ;
unsigned V_150 = ( V_131 -> V_146 & 0xf ) << 8 | V_131 -> V_151 ;
unsigned V_152 = ( V_131 -> V_153 & 0xc0 ) << 2 | V_131 -> V_154 ;
unsigned V_155 = ( V_131 -> V_153 & 0x30 ) << 4 | V_131 -> V_156 ;
unsigned V_157 = ( V_131 -> V_153 & 0xc ) << 2 | V_131 -> V_158 >> 4 ;
unsigned V_159 = ( V_131 -> V_153 & 0x3 ) << 4 | ( V_131 -> V_158 & 0xf ) ;
if ( V_142 < 64 || V_145 < 64 )
return NULL ;
if ( V_131 -> V_135 & V_160 ) {
F_14 ( L_14 ) ;
return NULL ;
}
if ( ! ( V_131 -> V_135 & V_161 ) ) {
F_14 ( L_15 ) ;
}
if ( ! V_155 || ! V_159 ) {
F_14 ( L_16
L_17 ) ;
return NULL ;
}
if ( V_69 & V_162 ) {
V_83 = F_60 ( V_47 , V_142 , V_145 , 60 , true , false , false ) ;
if ( ! V_83 )
return NULL ;
goto V_163;
}
V_83 = F_67 ( V_47 ) ;
if ( ! V_83 )
return NULL ;
if ( V_69 & V_164 )
V_140 -> V_165 = F_68 ( 1088 ) ;
V_83 -> clock = F_69 ( V_140 -> V_165 ) * 10 ;
V_83 -> V_85 = V_142 ;
V_83 -> V_87 = V_83 -> V_85 + V_152 ;
V_83 -> V_86 = V_83 -> V_87 + V_155 ;
V_83 -> V_84 = V_83 -> V_85 + V_148 ;
V_83 -> V_89 = V_145 ;
V_83 -> V_88 = V_83 -> V_89 + V_157 ;
V_83 -> V_137 = V_83 -> V_88 + V_159 ;
V_83 -> V_138 = V_83 -> V_89 + V_150 ;
if ( V_83 -> V_86 > V_83 -> V_84 )
V_83 -> V_84 = V_83 -> V_86 + 1 ;
if ( V_83 -> V_137 > V_83 -> V_138 )
V_83 -> V_138 = V_83 -> V_137 + 1 ;
F_65 ( V_83 , V_131 ) ;
if ( V_69 & V_166 ) {
V_131 -> V_135 |= V_167 | V_168 ;
}
V_83 -> V_36 |= ( V_131 -> V_135 & V_167 ) ?
V_169 : V_170 ;
V_83 -> V_36 |= ( V_131 -> V_135 & V_168 ) ?
V_171 : V_172 ;
V_163:
V_83 -> V_173 = V_131 -> V_174 | ( V_131 -> V_175 & 0xf0 ) << 4 ;
V_83 -> V_176 = V_131 -> V_177 | ( V_131 -> V_175 & 0xf ) << 8 ;
if ( V_69 & V_178 ) {
V_83 -> V_173 *= 10 ;
V_83 -> V_176 *= 10 ;
}
if ( V_69 & V_179 ) {
V_83 -> V_173 = V_12 -> V_180 * 10 ;
V_83 -> V_176 = V_12 -> V_181 * 10 ;
}
V_83 -> type = V_182 ;
V_83 -> V_82 = F_39 ( V_83 ) ;
F_70 ( V_83 ) ;
return V_83 ;
}
static bool
F_71 ( const struct V_70 * V_83 ,
struct V_12 * V_12 , T_1 * V_71 )
{
int V_183 , V_184 , V_185 ;
V_184 = V_71 [ 7 ] ;
if ( V_12 -> V_17 >= 4 )
V_184 += ( ( V_71 [ 4 ] & 0x04 ) ? 255 : 0 ) ;
V_185 = V_71 [ 8 ] ;
if ( V_12 -> V_17 >= 4 )
V_185 += ( ( V_71 [ 4 ] & 0x08 ) ? 255 : 0 ) ;
V_183 = F_62 ( V_83 ) ;
return ( V_183 <= V_185 && V_183 >= V_184 ) ;
}
static bool
F_72 ( const struct V_70 * V_83 ,
struct V_12 * V_12 , T_1 * V_71 )
{
int V_186 , V_187 , V_188 ;
V_187 = V_71 [ 5 ] ;
if ( V_12 -> V_17 >= 4 )
V_187 += ( ( V_71 [ 4 ] & 0x01 ) ? 255 : 0 ) ;
V_188 = V_71 [ 6 ] ;
if ( V_12 -> V_17 >= 4 )
V_188 += ( ( V_71 [ 4 ] & 0x02 ) ? 255 : 0 ) ;
V_186 = F_39 ( V_83 ) ;
return ( V_186 <= V_188 && V_186 >= V_187 ) ;
}
static T_3
F_73 ( struct V_12 * V_12 , T_1 * V_71 )
{
if ( V_71 [ 9 ] == 0 || V_71 [ 9 ] == 255 )
return 0 ;
if ( V_12 -> V_17 >= 4 && V_71 [ 10 ] == 0x04 )
return ( V_71 [ 9 ] * 10000 ) - ( ( V_71 [ 12 ] >> 2 ) * 250 ) ;
return V_71 [ 9 ] * 10000 + 5001 ;
}
static bool
F_74 ( const struct V_70 * V_83 , struct V_12 * V_12 ,
struct V_103 * V_140 )
{
T_3 V_189 ;
T_1 * V_71 = ( T_1 * ) V_140 ;
if ( ! F_71 ( V_83 , V_12 , V_71 ) )
return false ;
if ( ! F_72 ( V_83 , V_12 , V_71 ) )
return false ;
if ( ( V_189 = F_73 ( V_12 , V_71 ) ) )
if ( V_83 -> clock > V_189 )
return false ;
if ( V_12 -> V_17 >= 4 && V_71 [ 10 ] == 0x04 )
if ( V_71 [ 13 ] && V_83 -> V_85 > 8 * ( V_71 [ 13 ] + ( 256 * ( V_71 [ 12 ] & 0x3 ) ) ) )
return false ;
if ( F_41 ( V_83 ) && ! F_49 ( V_12 ) )
return false ;
return true ;
}
static bool F_75 ( const struct V_41 * V_42 ,
const struct V_70 * V_83 )
{
const struct V_70 * V_120 ;
bool V_190 = false ;
F_59 (m, &connector->probed_modes, head) {
if ( V_83 -> V_85 == V_120 -> V_85 &&
V_83 -> V_89 == V_120 -> V_89 &&
F_39 ( V_83 ) == F_39 ( V_120 ) )
return false ;
if ( V_83 -> V_85 <= V_120 -> V_85 &&
V_83 -> V_89 <= V_120 -> V_89 )
V_190 = true ;
}
return V_190 ;
}
static int
F_76 ( struct V_41 * V_42 , struct V_12 * V_12 ,
struct V_103 * V_140 )
{
int V_2 , V_191 = 0 ;
struct V_70 * V_192 ;
struct V_90 * V_47 = V_42 -> V_47 ;
for ( V_2 = 0 ; V_2 < F_32 ( V_95 ) ; V_2 ++ ) {
if ( F_74 ( V_95 + V_2 , V_12 , V_140 ) &&
F_75 ( V_42 , V_95 + V_2 ) ) {
V_192 = F_43 ( V_47 , & V_95 [ V_2 ] ) ;
if ( V_192 ) {
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
}
return V_191 ;
}
void F_78 ( struct V_70 * V_83 )
{
if ( V_83 -> V_85 == 1368 && V_83 -> V_89 == 768 ) {
V_83 -> V_85 = 1366 ;
V_83 -> V_87 -- ;
V_83 -> V_86 -- ;
F_70 ( V_83 ) ;
}
}
static int
F_79 ( struct V_41 * V_42 , struct V_12 * V_12 ,
struct V_103 * V_140 )
{
int V_2 , V_191 = 0 ;
struct V_70 * V_192 ;
struct V_90 * V_47 = V_42 -> V_47 ;
for ( V_2 = 0 ; V_2 < F_32 ( V_193 ) ; V_2 ++ ) {
const struct V_194 * V_120 = & V_193 [ V_2 ] ;
V_192 = F_61 ( V_47 , V_120 -> V_132 , V_120 -> V_133 , V_120 -> V_107 , 0 , 0 ) ;
if ( ! V_192 )
return V_191 ;
F_78 ( V_192 ) ;
if ( ! F_74 ( V_192 , V_12 , V_140 ) ||
! F_75 ( V_42 , V_192 ) ) {
F_63 ( V_47 , V_192 ) ;
continue;
}
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
return V_191 ;
}
static int
F_80 ( struct V_41 * V_42 , struct V_12 * V_12 ,
struct V_103 * V_140 )
{
int V_2 , V_191 = 0 ;
struct V_70 * V_192 ;
struct V_90 * V_47 = V_42 -> V_47 ;
bool V_94 = F_49 ( V_12 ) ;
for ( V_2 = 0 ; V_2 < F_32 ( V_193 ) ; V_2 ++ ) {
const struct V_194 * V_120 = & V_193 [ V_2 ] ;
V_192 = F_60 ( V_47 , V_120 -> V_132 , V_120 -> V_133 , V_120 -> V_107 , V_94 , 0 , 0 ) ;
if ( ! V_192 )
return V_191 ;
F_78 ( V_192 ) ;
if ( ! F_74 ( V_192 , V_12 , V_140 ) ||
! F_75 ( V_42 , V_192 ) ) {
F_63 ( V_47 , V_192 ) ;
continue;
}
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
return V_191 ;
}
static void
F_81 ( struct V_103 * V_140 , void * V_195 )
{
struct V_196 * V_99 = V_195 ;
struct V_197 * V_22 = & V_140 -> V_22 . V_198 ;
struct V_199 * V_200 = & V_22 -> V_22 . V_200 ;
if ( V_22 -> type != V_108 )
return;
V_99 -> V_191 += F_76 ( V_99 -> V_42 ,
V_99 -> V_12 ,
V_140 ) ;
if ( ! F_82 ( V_99 -> V_12 , 1 , 1 ) )
return;
switch ( V_200 -> V_36 ) {
case 0x02 :
case 0x00 :
V_99 -> V_191 += F_79 ( V_99 -> V_42 ,
V_99 -> V_12 ,
V_140 ) ;
break;
case 0x04 :
if ( ! F_82 ( V_99 -> V_12 , 1 , 3 ) )
break;
V_99 -> V_191 += F_80 ( V_99 -> V_42 ,
V_99 -> V_12 ,
V_140 ) ;
break;
case 0x01 :
default:
break;
}
}
static int
F_83 ( struct V_41 * V_42 , struct V_12 * V_12 )
{
struct V_196 V_99 = {
. V_42 = V_42 ,
. V_12 = V_12 ,
} ;
if ( F_82 ( V_12 , 1 , 0 ) )
F_47 ( ( T_1 * ) V_12 , F_81 ,
& V_99 ) ;
return V_99 . V_191 ;
}
static int
F_84 ( struct V_41 * V_42 , struct V_103 * V_140 )
{
int V_2 , V_50 , V_120 , V_191 = 0 ;
struct V_70 * V_83 ;
T_1 * V_201 = ( ( T_1 * ) V_140 ) + 6 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_50 = 7 ; V_50 >= 0 ; V_50 -- ) {
V_120 = ( V_2 * 8 ) + ( 7 - V_50 ) ;
if ( V_120 >= F_32 ( V_202 ) )
break;
if ( V_201 [ V_2 ] & ( 1 << V_50 ) ) {
V_83 = F_42 ( V_42 -> V_47 ,
V_202 [ V_120 ] . V_132 ,
V_202 [ V_120 ] . V_133 ,
V_202 [ V_120 ] . V_107 ,
V_202 [ V_120 ] . V_94 ) ;
if ( V_83 ) {
F_77 ( V_42 , V_83 ) ;
V_191 ++ ;
}
}
}
}
return V_191 ;
}
static void
F_85 ( struct V_103 * V_140 , void * V_195 )
{
struct V_196 * V_99 = V_195 ;
struct V_197 * V_22 = & V_140 -> V_22 . V_198 ;
if ( V_22 -> type == V_203 )
V_99 -> V_191 += F_84 ( V_99 -> V_42 , V_140 ) ;
}
static int
F_86 ( struct V_41 * V_42 , struct V_12 * V_12 )
{
struct V_90 * V_47 = V_42 -> V_47 ;
unsigned long V_204 = V_12 -> V_205 . V_206 |
( V_12 -> V_205 . V_207 << 8 ) |
( ( V_12 -> V_205 . V_208 & 0x80 ) << 9 ) ;
int V_2 , V_191 = 0 ;
struct V_196 V_99 = {
. V_42 = V_42 ,
. V_12 = V_12 ,
} ;
for ( V_2 = 0 ; V_2 <= V_209 ; V_2 ++ ) {
if ( V_204 & ( 1 << V_2 ) ) {
struct V_70 * V_192 ;
V_192 = F_43 ( V_47 , & V_210 [ V_2 ] ) ;
if ( V_192 ) {
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
}
if ( F_82 ( V_12 , 1 , 0 ) )
F_47 ( ( T_1 * ) V_12 ,
F_85 , & V_99 ) ;
return V_191 + V_99 . V_191 ;
}
static void
F_87 ( struct V_103 * V_140 , void * V_195 )
{
struct V_196 * V_99 = V_195 ;
struct V_197 * V_22 = & V_140 -> V_22 . V_198 ;
struct V_41 * V_42 = V_99 -> V_42 ;
struct V_12 * V_12 = V_99 -> V_12 ;
if ( V_22 -> type == V_211 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_119 * V_212 ;
struct V_70 * V_192 ;
V_212 = & V_22 -> V_22 . V_213 [ V_2 ] ;
V_192 = F_58 ( V_42 , V_12 , V_212 ) ;
if ( V_192 ) {
F_77 ( V_42 , V_192 ) ;
V_99 -> V_191 ++ ;
}
}
}
}
static int
F_88 ( struct V_41 * V_42 , struct V_12 * V_12 )
{
int V_2 , V_191 = 0 ;
struct V_196 V_99 = {
. V_42 = V_42 ,
. V_12 = V_12 ,
} ;
for ( V_2 = 0 ; V_2 < V_214 ; V_2 ++ ) {
struct V_70 * V_192 ;
V_192 = F_58 ( V_42 , V_12 ,
& V_12 -> V_215 [ V_2 ] ) ;
if ( V_192 ) {
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
if ( F_82 ( V_12 , 1 , 0 ) )
F_47 ( ( T_1 * ) V_12 , F_87 ,
& V_99 ) ;
return V_191 + V_99 . V_191 ;
}
static int F_89 ( struct V_41 * V_42 ,
struct V_103 * V_140 )
{
int V_2 , V_50 , V_191 = 0 ;
struct V_70 * V_192 ;
struct V_90 * V_47 = V_42 -> V_47 ;
struct V_216 * V_217 ;
const int V_218 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_219 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_220 ( V_221 ) , V_222 ;
V_217 = & ( V_140 -> V_22 . V_198 . V_22 . V_217 [ V_2 ] ) ;
if ( ! memcmp ( V_217 -> V_223 , V_219 , 3 ) )
continue;
V_222 = ( V_217 -> V_223 [ 0 ] + ( ( V_217 -> V_223 [ 1 ] & 0xf0 ) << 4 ) + 1 ) * 2 ;
switch ( V_217 -> V_223 [ 1 ] & 0x0c ) {
case 0x00 :
V_221 = V_222 * 4 / 3 ;
break;
case 0x04 :
V_221 = V_222 * 16 / 9 ;
break;
case 0x08 :
V_221 = V_222 * 16 / 10 ;
break;
case 0x0c :
V_221 = V_222 * 15 / 9 ;
break;
}
for ( V_50 = 1 ; V_50 < 5 ; V_50 ++ ) {
if ( V_217 -> V_223 [ 2 ] & ( 1 << V_50 ) ) {
V_192 = F_60 ( V_47 , V_221 , V_222 ,
V_218 [ V_50 ] , V_50 == 0 ,
false , false ) ;
if ( V_192 ) {
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
}
}
return V_191 ;
}
static void
F_90 ( struct V_103 * V_140 , void * V_195 )
{
struct V_196 * V_99 = V_195 ;
struct V_197 * V_22 = & V_140 -> V_22 . V_198 ;
if ( V_22 -> type == V_224 )
V_99 -> V_191 += F_89 ( V_99 -> V_42 , V_140 ) ;
}
static int
F_91 ( struct V_41 * V_42 , struct V_12 * V_12 )
{
struct V_196 V_99 = {
. V_42 = V_42 ,
. V_12 = V_12 ,
} ;
if ( F_82 ( V_12 , 1 , 2 ) )
F_47 ( ( T_1 * ) V_12 , F_90 , & V_99 ) ;
return V_99 . V_191 ;
}
static void
F_92 ( struct V_103 * V_140 , void * V_195 )
{
struct V_196 * V_99 = V_195 ;
struct V_70 * V_192 ;
if ( V_140 -> V_165 ) {
V_192 = F_66 ( V_99 -> V_42 -> V_47 ,
V_99 -> V_12 , V_140 ,
V_99 -> V_69 ) ;
if ( ! V_192 )
return;
if ( V_99 -> V_225 )
V_192 -> type |= V_81 ;
F_93 ( V_192 ) ;
F_77 ( V_99 -> V_42 , V_192 ) ;
V_99 -> V_191 ++ ;
V_99 -> V_225 = 0 ;
}
}
static int
F_94 ( struct V_41 * V_42 , struct V_12 * V_12 ,
T_3 V_69 )
{
struct V_196 V_99 = {
. V_42 = V_42 ,
. V_12 = V_12 ,
. V_225 = 1 ,
. V_69 = V_69 ,
} ;
if ( V_99 . V_225 && ! F_82 ( V_12 , 1 , 3 ) )
V_99 . V_225 =
( V_12 -> V_111 & V_226 ) ;
F_47 ( ( T_1 * ) V_12 , F_92 , & V_99 ) ;
return V_99 . V_191 ;
}
static T_1 * F_95 ( struct V_12 * V_12 , int V_227 )
{
T_1 * V_228 = NULL ;
int V_2 ;
if ( V_12 == NULL || V_12 -> V_21 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_12 -> V_21 ; V_2 ++ ) {
V_228 = ( T_1 * ) V_12 + V_6 * ( V_2 + 1 ) ;
if ( V_228 [ 0 ] == V_227 )
break;
}
if ( V_2 == V_12 -> V_21 )
return NULL ;
return V_228 ;
}
static T_1 * F_96 ( struct V_12 * V_12 )
{
return F_95 ( V_12 , V_15 ) ;
}
static T_1 * F_97 ( struct V_12 * V_12 )
{
return F_95 ( V_12 , V_229 ) ;
}
static unsigned int
F_98 ( const struct V_70 * V_230 )
{
unsigned int clock = V_230 -> clock ;
if ( V_230 -> V_82 % 6 != 0 )
return clock ;
if ( V_230 -> V_89 == 240 || V_230 -> V_89 == 480 )
clock = F_99 ( clock * 1001 , 1000 ) ;
else
clock = F_99 ( clock * 1000 , 1001 ) ;
return clock ;
}
static bool
F_100 ( T_1 V_231 , struct V_70 * V_83 )
{
F_101 ( V_232 [ 8 ] . V_138 != 262 ||
V_232 [ 9 ] . V_138 != 262 ||
V_232 [ 12 ] . V_138 != 262 ||
V_232 [ 13 ] . V_138 != 262 ||
V_232 [ 23 ] . V_138 != 312 ||
V_232 [ 24 ] . V_138 != 312 ||
V_232 [ 27 ] . V_138 != 312 ||
V_232 [ 28 ] . V_138 != 312 ) ;
if ( ( ( V_231 == 8 || V_231 == 9 ||
V_231 == 12 || V_231 == 13 ) && V_83 -> V_138 < 263 ) ||
( ( V_231 == 23 || V_231 == 24 ||
V_231 == 27 || V_231 == 28 ) && V_83 -> V_138 < 314 ) ) {
V_83 -> V_88 ++ ;
V_83 -> V_137 ++ ;
V_83 -> V_138 ++ ;
return true ;
}
return false ;
}
static T_1 F_102 ( const struct V_70 * V_233 ,
unsigned int V_234 )
{
T_1 V_231 ;
if ( ! V_233 -> clock )
return 0 ;
for ( V_231 = 1 ; V_231 < F_32 ( V_232 ) ; V_231 ++ ) {
struct V_70 V_230 = V_232 [ V_231 ] ;
unsigned int V_235 , V_236 ;
V_235 = V_230 . clock ;
V_236 = F_98 ( & V_230 ) ;
if ( abs ( V_233 -> clock - V_235 ) > V_234 &&
abs ( V_233 -> clock - V_236 ) > V_234 )
continue;
do {
if ( F_103 ( V_233 , & V_230 ) )
return V_231 ;
} while ( F_100 ( V_231 , & V_230 ) );
}
return 0 ;
}
T_1 F_104 ( const struct V_70 * V_233 )
{
T_1 V_231 ;
if ( ! V_233 -> clock )
return 0 ;
for ( V_231 = 1 ; V_231 < F_32 ( V_232 ) ; V_231 ++ ) {
struct V_70 V_230 = V_232 [ V_231 ] ;
unsigned int V_235 , V_236 ;
V_235 = V_230 . clock ;
V_236 = F_98 ( & V_230 ) ;
if ( F_105 ( V_233 -> clock ) != F_105 ( V_235 ) &&
F_105 ( V_233 -> clock ) != F_105 ( V_236 ) )
continue;
do {
if ( F_103 ( V_233 , & V_230 ) )
return V_231 ;
} while ( F_100 ( V_231 , & V_230 ) );
}
return 0 ;
}
static bool F_106 ( T_1 V_231 )
{
return V_231 > 0 && V_231 < F_32 ( V_232 ) ;
}
enum V_237 F_107 ( const T_1 V_238 )
{
return V_232 [ V_238 ] . V_239 ;
}
static unsigned int
F_108 ( const struct V_70 * V_240 )
{
if ( V_240 -> V_89 == 4096 && V_240 -> V_85 == 2160 )
return V_240 -> clock ;
return F_98 ( V_240 ) ;
}
static T_1 F_109 ( const struct V_70 * V_233 ,
unsigned int V_234 )
{
T_1 V_231 ;
if ( ! V_233 -> clock )
return 0 ;
for ( V_231 = 1 ; V_231 < F_32 ( V_241 ) ; V_231 ++ ) {
const struct V_70 * V_240 = & V_241 [ V_231 ] ;
unsigned int V_235 , V_236 ;
V_235 = V_240 -> clock ;
V_236 = F_108 ( V_240 ) ;
if ( abs ( V_233 -> clock - V_235 ) > V_234 &&
abs ( V_233 -> clock - V_236 ) > V_234 )
continue;
if ( F_110 ( V_233 , V_240 ) )
return V_231 ;
}
return 0 ;
}
static T_1 F_111 ( const struct V_70 * V_233 )
{
T_1 V_231 ;
if ( ! V_233 -> clock )
return 0 ;
for ( V_231 = 1 ; V_231 < F_32 ( V_241 ) ; V_231 ++ ) {
const struct V_70 * V_240 = & V_241 [ V_231 ] ;
unsigned int V_235 , V_236 ;
V_235 = V_240 -> clock ;
V_236 = F_108 ( V_240 ) ;
if ( ( F_105 ( V_233 -> clock ) == F_105 ( V_235 ) ||
F_105 ( V_233 -> clock ) == F_105 ( V_236 ) ) &&
F_103 ( V_233 , V_240 ) )
return V_231 ;
}
return 0 ;
}
static bool F_112 ( T_1 V_231 )
{
return V_231 > 0 && V_231 < F_32 ( V_241 ) ;
}
static int
F_113 ( struct V_41 * V_42 , struct V_12 * V_12 )
{
struct V_90 * V_47 = V_42 -> V_47 ;
struct V_70 * V_83 , * V_242 ;
F_114 ( V_243 ) ;
int V_191 = 0 ;
if ( ! F_96 ( V_12 ) )
return 0 ;
F_59 (mode, &connector->probed_modes, head) {
const struct V_70 * V_230 = NULL ;
struct V_70 * V_192 ;
T_1 V_231 = F_104 ( V_83 ) ;
unsigned int V_235 , V_236 ;
if ( F_106 ( V_231 ) ) {
V_230 = & V_232 [ V_231 ] ;
V_236 = F_98 ( V_230 ) ;
} else {
V_231 = F_111 ( V_83 ) ;
if ( F_112 ( V_231 ) ) {
V_230 = & V_241 [ V_231 ] ;
V_236 = F_108 ( V_230 ) ;
}
}
if ( ! V_230 )
continue;
V_235 = V_230 -> clock ;
if ( V_235 == V_236 )
continue;
if ( V_83 -> clock != V_235 && V_83 -> clock != V_236 )
continue;
V_192 = F_43 ( V_47 , V_230 ) ;
if ( ! V_192 )
continue;
V_192 -> V_36 |= V_83 -> V_36 & V_244 ;
if ( V_83 -> clock != V_235 )
V_192 -> clock = V_235 ;
else
V_192 -> clock = V_236 ;
F_115 ( & V_192 -> V_80 , & V_243 ) ;
}
F_37 (mode, tmp, &list, head) {
F_116 ( & V_83 -> V_80 ) ;
F_77 ( V_42 , V_83 ) ;
V_191 ++ ;
}
return V_191 ;
}
static struct V_70 *
F_117 ( struct V_41 * V_42 ,
const T_1 * V_245 , T_1 V_246 ,
T_1 V_247 )
{
struct V_90 * V_47 = V_42 -> V_47 ;
struct V_70 * V_192 ;
T_1 V_231 ;
if ( V_245 == NULL || V_247 >= V_246 )
return NULL ;
V_231 = ( V_245 [ V_247 ] & 127 ) ;
if ( ! F_106 ( V_231 ) )
return NULL ;
V_192 = F_43 ( V_47 , & V_232 [ V_231 ] ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_82 = 0 ;
return V_192 ;
}
static int
F_118 ( struct V_41 * V_42 , const T_1 * V_248 , T_1 V_24 )
{
int V_2 , V_191 = 0 ;
for ( V_2 = 0 ; V_2 < V_24 ; V_2 ++ ) {
struct V_70 * V_83 ;
V_83 = F_117 ( V_42 , V_248 , V_24 , V_2 ) ;
if ( V_83 ) {
F_77 ( V_42 , V_83 ) ;
V_191 ++ ;
}
}
return V_191 ;
}
static bool
F_119 ( const struct V_70 * V_83 ,
const struct V_249 * V_250 )
{
unsigned int V_251 = V_83 -> V_36 & V_139 ;
return V_83 -> V_85 == V_250 -> V_221 &&
V_83 -> V_89 == V_250 -> V_222 &&
V_251 == ( V_250 -> V_36 & V_139 ) &&
F_39 ( V_83 ) == V_250 -> V_82 ;
}
static int F_120 ( struct V_41 * V_42 )
{
struct V_90 * V_47 = V_42 -> V_47 ;
const struct V_70 * V_83 ;
struct V_252 V_253 ;
int V_191 = 0 , V_2 ;
F_121 ( & V_253 ) ;
F_59 (mode, &connector->probed_modes, head) {
for ( V_2 = 0 ; V_2 < F_32 ( V_254 ) ; V_2 ++ ) {
const struct V_249 * V_255 ;
struct V_70 * V_256 ;
if ( ! F_119 ( V_83 ,
& V_254 [ V_2 ] ) )
continue;
V_255 = & V_254 [ V_2 ] ;
V_256 = F_43 ( V_47 , V_83 ) ;
if ( ! V_256 )
continue;
V_256 -> V_36 |= V_255 -> V_36 ;
F_115 ( & V_256 -> V_80 , & V_253 ) ;
V_191 ++ ;
}
}
F_122 ( & V_253 , & V_42 -> V_77 ) ;
return V_191 ;
}
static int F_123 ( struct V_41 * V_42 , T_1 V_231 )
{
struct V_90 * V_47 = V_42 -> V_47 ;
struct V_70 * V_192 ;
if ( ! F_112 ( V_231 ) ) {
F_124 ( L_18 , V_231 ) ;
return 0 ;
}
V_192 = F_43 ( V_47 , & V_241 [ V_231 ] ) ;
if ( ! V_192 )
return 0 ;
F_77 ( V_42 , V_192 ) ;
return 1 ;
}
static int F_125 ( struct V_41 * V_42 , T_5 V_257 ,
const T_1 * V_245 , T_1 V_246 , T_1 V_247 )
{
struct V_70 * V_192 ;
int V_191 = 0 ;
if ( V_257 & ( 1 << 0 ) ) {
V_192 = F_117 ( V_42 , V_245 ,
V_246 ,
V_247 ) ;
if ( V_192 ) {
V_192 -> V_36 |= V_258 ;
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
if ( V_257 & ( 1 << 6 ) ) {
V_192 = F_117 ( V_42 , V_245 ,
V_246 ,
V_247 ) ;
if ( V_192 ) {
V_192 -> V_36 |= V_259 ;
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
if ( V_257 & ( 1 << 8 ) ) {
V_192 = F_117 ( V_42 , V_245 ,
V_246 ,
V_247 ) ;
if ( V_192 ) {
V_192 -> V_36 |= V_260 ;
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
return V_191 ;
}
static int
F_126 ( struct V_41 * V_42 , const T_1 * V_248 , T_1 V_24 ,
const T_1 * V_245 , T_1 V_246 )
{
int V_191 = 0 , V_261 = 0 , V_2 , V_262 = 0 , V_263 ;
T_1 V_264 , V_265 = 0 ;
T_5 V_266 ;
T_5 V_267 ;
if ( V_24 < 8 )
goto V_54;
if ( ! ( V_248 [ 8 ] & ( 1 << 5 ) ) )
goto V_54;
if ( V_248 [ 8 ] & ( 1 << 7 ) )
V_261 += 2 ;
if ( V_248 [ 8 ] & ( 1 << 6 ) )
V_261 += 2 ;
if ( V_24 < ( 8 + V_261 + 2 ) )
goto V_54;
V_261 ++ ;
if ( V_248 [ 8 + V_261 ] & ( 1 << 7 ) ) {
V_191 += F_120 ( V_42 ) ;
V_262 = ( V_248 [ 8 + V_261 ] & 0x60 ) >> 5 ;
}
V_261 ++ ;
V_264 = V_248 [ 8 + V_261 ] >> 5 ;
V_265 = V_248 [ 8 + V_261 ] & 0x1f ;
for ( V_2 = 0 ; V_2 < V_264 && V_24 >= ( 9 + V_261 + V_2 ) ; V_2 ++ ) {
T_1 V_231 ;
V_231 = V_248 [ 9 + V_261 + V_2 ] ;
V_191 += F_123 ( V_42 , V_231 ) ;
}
V_261 += 1 + V_264 ;
if ( V_262 == 1 )
V_263 = 2 ;
else if ( V_262 == 2 )
V_263 = 4 ;
else
V_263 = 0 ;
if ( V_24 < ( 8 + V_261 + V_265 - 1 ) )
goto V_54;
if ( V_265 < V_263 )
goto V_54;
if ( V_262 == 1 || V_262 == 2 ) {
V_267 = ( V_248 [ 8 + V_261 ] << 8 ) | V_248 [ 9 + V_261 ] ;
if ( V_262 == 2 )
V_266 = ( V_248 [ 10 + V_261 ] << 8 ) | V_248 [ 11 + V_261 ] ;
else
V_266 = 0xffff ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
if ( V_266 & ( 1 << V_2 ) )
V_191 += F_125 ( V_42 ,
V_267 ,
V_245 ,
V_246 , V_2 ) ;
}
}
V_261 += V_263 ;
for ( V_2 = 0 ; V_2 < ( V_265 - V_263 ) ; V_2 ++ ) {
int V_268 ;
struct V_70 * V_192 = NULL ;
unsigned int V_269 = 0 ;
bool V_270 ;
V_270 = ( ( V_248 [ 8 + V_261 + V_2 ] & 0x0f ) > 7 ) ;
if ( V_270 && ( V_2 + 1 == V_265 - V_263 ) )
break;
V_268 = V_248 [ 8 + V_261 + V_2 ] >> 4 ;
switch ( V_248 [ 8 + V_261 + V_2 ] & 0x0f ) {
case 0 :
V_269 = V_258 ;
break;
case 6 :
V_269 = V_259 ;
break;
case 8 :
if ( ( V_248 [ 9 + V_261 + V_2 ] >> 4 ) == 1 )
V_269 = V_260 ;
break;
}
if ( V_269 != 0 ) {
V_192 = F_117 ( V_42 ,
V_245 ,
V_246 ,
V_268 ) ;
if ( V_192 ) {
V_192 -> V_36 |= V_269 ;
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
if ( V_270 )
V_2 ++ ;
}
V_54:
return V_191 ;
}
static int
F_127 ( const T_1 * V_248 )
{
return V_248 [ 0 ] & 0x1f ;
}
static int
F_128 ( const T_1 * V_248 )
{
return V_248 [ 0 ] >> 5 ;
}
static int
F_129 ( const T_1 * V_271 )
{
return V_271 [ 1 ] ;
}
static int
F_130 ( const T_1 * V_271 , int * V_27 , int * V_272 )
{
* V_27 = 4 ;
* V_272 = V_271 [ 2 ] ;
if ( * V_272 == 0 )
* V_272 = 127 ;
if ( * V_272 < 4 || * V_272 > 127 )
return - V_273 ;
return 0 ;
}
static bool F_131 ( const T_1 * V_248 )
{
int V_274 ;
if ( F_128 ( V_248 ) != V_275 )
return false ;
if ( F_127 ( V_248 ) < 5 )
return false ;
V_274 = V_248 [ 1 ] | ( V_248 [ 2 ] << 8 ) | ( V_248 [ 3 ] << 16 ) ;
return V_274 == V_276 ;
}
static bool F_132 ( const T_1 * V_248 )
{
unsigned int V_277 ;
if ( F_128 ( V_248 ) != V_275 )
return false ;
if ( F_127 ( V_248 ) < 7 )
return false ;
V_277 = V_248 [ 3 ] << 16 | V_248 [ 2 ] << 8 | V_248 [ 1 ] ;
return V_277 == V_278 ;
}
static int
F_133 ( struct V_41 * V_42 , struct V_12 * V_12 )
{
const T_1 * V_271 = F_96 ( V_12 ) ;
const T_1 * V_248 , * V_279 = NULL , * V_280 = NULL ;
T_1 V_281 , V_282 , V_246 = 0 ;
int V_191 = 0 ;
if ( V_271 && F_129 ( V_271 ) >= 3 ) {
int V_2 , V_27 , V_272 ;
if ( F_130 ( V_271 , & V_27 , & V_272 ) )
return 0 ;
F_134 (cea, i, start, end) {
V_248 = & V_271 [ V_2 ] ;
V_281 = F_127 ( V_248 ) ;
if ( F_128 ( V_248 ) == V_283 ) {
V_280 = V_248 + 1 ;
V_246 = V_281 ;
V_191 += F_118 ( V_42 , V_280 , V_281 ) ;
}
else if ( F_131 ( V_248 ) ) {
V_279 = V_248 ;
V_282 = V_281 ;
}
}
}
if ( V_279 )
V_191 += F_126 ( V_42 , V_279 , V_282 , V_280 ,
V_246 ) ;
return V_191 ;
}
static void F_93 ( struct V_70 * V_83 )
{
const struct V_70 * V_230 ;
int V_235 , V_236 , clock ;
T_1 V_231 ;
const char * type ;
V_231 = F_102 ( V_83 , 5 ) ;
if ( F_106 ( V_231 ) ) {
type = L_19 ;
V_230 = & V_232 [ V_231 ] ;
V_235 = V_230 -> clock ;
V_236 = F_98 ( V_230 ) ;
} else {
V_231 = F_109 ( V_83 , 5 ) ;
if ( F_112 ( V_231 ) ) {
type = L_20 ;
V_230 = & V_241 [ V_231 ] ;
V_235 = V_230 -> clock ;
V_236 = F_108 ( V_230 ) ;
} else {
return;
}
}
if ( abs ( V_83 -> clock - V_235 ) < abs ( V_83 -> clock - V_236 ) )
clock = V_235 ;
else
clock = V_236 ;
if ( V_83 -> clock == clock )
return;
F_7 ( L_21 ,
type , V_231 , V_83 -> clock , clock ) ;
V_83 -> clock = clock ;
}
static void
F_135 ( struct V_41 * V_42 , const T_1 * V_248 )
{
T_1 V_24 = F_127 ( V_248 ) ;
if ( V_24 >= 6 )
V_42 -> V_284 [ 5 ] |= ( V_248 [ 6 ] >> 7 ) << 1 ;
if ( V_24 >= 8 ) {
V_42 -> V_285 [ 0 ] = V_248 [ 8 ] >> 7 ;
V_42 -> V_285 [ 1 ] = ( V_248 [ 8 ] >> 6 ) & 1 ;
}
if ( V_24 >= 9 )
V_42 -> V_286 [ 0 ] = V_248 [ 9 ] ;
if ( V_24 >= 10 )
V_42 -> V_287 [ 0 ] = V_248 [ 10 ] ;
if ( V_24 >= 11 )
V_42 -> V_286 [ 1 ] = V_248 [ 11 ] ;
if ( V_24 >= 12 )
V_42 -> V_287 [ 1 ] = V_248 [ 12 ] ;
F_14 ( L_22
L_23
L_24 ,
V_42 -> V_285 [ 0 ] ,
V_42 -> V_285 [ 1 ] ,
V_42 -> V_286 [ 0 ] ,
V_42 -> V_286 [ 1 ] ,
V_42 -> V_287 [ 0 ] ,
V_42 -> V_287 [ 1 ] ) ;
}
static void
F_136 ( struct V_103 * V_71 , void * V_22 )
{
if ( V_71 -> V_22 . V_198 . type == V_288 )
* ( T_1 * * ) V_22 = V_71 -> V_22 . V_198 . V_22 . V_289 . V_289 ;
}
static int F_137 ( struct V_12 * V_12 , char V_40 [ 13 ] )
{
char * V_290 = NULL ;
int V_291 ;
if ( ! V_12 || ! V_40 )
return 0 ;
F_47 ( ( T_1 * ) V_12 , F_136 , & V_290 ) ;
for ( V_291 = 0 ; V_290 && V_291 < 13 ; V_291 ++ ) {
if ( V_290 [ V_291 ] == 0x0a )
break;
V_40 [ V_291 ] = V_290 [ V_291 ] ;
}
return V_291 ;
}
void F_138 ( struct V_12 * V_12 , char * V_40 , int V_292 )
{
int V_293 ;
char V_23 [ 13 ] ;
if ( V_292 <= 0 )
return;
V_293 = F_46 ( F_137 ( V_12 , V_23 ) , V_292 - 1 ) ;
memcpy ( V_40 , V_23 , V_293 ) ;
V_40 [ V_293 ] = '\0' ;
}
void F_139 ( struct V_41 * V_42 , struct V_12 * V_12 )
{
T_6 * V_284 = V_42 -> V_284 ;
T_1 * V_271 ;
T_1 * V_248 ;
int V_294 = 0 ;
int V_291 ;
int V_281 ;
memset ( V_284 , 0 , sizeof( V_42 -> V_284 ) ) ;
V_42 -> V_285 [ 0 ] = false ;
V_42 -> V_285 [ 1 ] = false ;
V_42 -> V_286 [ 0 ] = 0 ;
V_42 -> V_287 [ 0 ] = 0 ;
V_42 -> V_286 [ 1 ] = 0 ;
V_42 -> V_287 [ 1 ] = 0 ;
if ( ! V_12 )
return;
V_271 = F_96 ( V_12 ) ;
if ( ! V_271 ) {
F_14 ( L_25 ) ;
return;
}
V_291 = F_137 ( V_12 , V_284 + 20 ) ;
V_284 [ 4 ] = ( V_271 [ 1 ] << 5 ) | V_291 ;
F_14 ( L_26 , V_284 + 20 ) ;
V_284 [ 0 ] = 2 << 3 ;
V_284 [ 16 ] = V_12 -> V_64 [ 0 ] ;
V_284 [ 17 ] = V_12 -> V_64 [ 1 ] ;
V_284 [ 18 ] = V_12 -> V_295 [ 0 ] ;
V_284 [ 19 ] = V_12 -> V_295 [ 1 ] ;
if ( F_129 ( V_271 ) >= 3 ) {
int V_2 , V_27 , V_272 ;
if ( F_130 ( V_271 , & V_27 , & V_272 ) ) {
V_27 = 0 ;
V_272 = 0 ;
}
F_134 (cea, i, start, end) {
V_248 = & V_271 [ V_2 ] ;
V_281 = F_127 ( V_248 ) ;
switch ( F_128 ( V_248 ) ) {
int V_296 ;
case V_297 :
V_296 = F_46 ( V_281 / 3 , 15 - V_294 ) ;
if ( V_296 >= 1 )
memcpy ( V_284 + 20 + V_291 + V_294 * 3 ,
& V_248 [ 1 ] , V_296 * 3 ) ;
V_294 += V_296 ;
break;
case V_298 :
if ( V_281 >= 1 )
V_284 [ 7 ] = V_248 [ 1 ] ;
break;
case V_275 :
if ( F_131 ( V_248 ) )
F_135 ( V_42 , V_248 ) ;
break;
default:
break;
}
}
}
V_284 [ 5 ] |= V_294 << 4 ;
V_284 [ V_299 ] =
F_140 ( F_141 ( V_284 ) , 4 ) ;
F_14 ( L_27 ,
F_142 ( V_284 ) , V_294 ) ;
}
int F_143 ( struct V_12 * V_12 , struct V_300 * * V_301 )
{
int V_302 = 0 ;
int V_2 , V_27 , V_272 , V_281 ;
T_1 * V_271 ;
V_271 = F_96 ( V_12 ) ;
if ( ! V_271 ) {
F_14 ( L_28 ) ;
return - V_303 ;
}
if ( F_129 ( V_271 ) < 3 ) {
F_14 ( L_29 ) ;
return - V_304 ;
}
if ( F_130 ( V_271 , & V_27 , & V_272 ) ) {
F_14 ( L_30 ) ;
return - V_305 ;
}
F_134 (cea, i, start, end) {
T_1 * V_248 = & V_271 [ V_2 ] ;
if ( F_128 ( V_248 ) == V_297 ) {
int V_50 ;
V_281 = F_127 ( V_248 ) ;
V_302 = V_281 / 3 ;
* V_301 = F_144 ( V_302 , sizeof( * * V_301 ) , V_53 ) ;
if ( ! * V_301 )
return - V_306 ;
for ( V_50 = 0 ; V_50 < V_302 ; V_50 ++ ) {
T_1 * V_307 = & V_248 [ 1 + V_50 * 3 ] ;
( * V_301 ) [ V_50 ] . V_308 = ( V_307 [ 0 ] & 0x78 ) >> 3 ;
( * V_301 ) [ V_50 ] . V_309 = V_307 [ 0 ] & 0x7 ;
( * V_301 ) [ V_50 ] . V_310 = V_307 [ 1 ] & 0x7F ;
( * V_301 ) [ V_50 ] . V_311 = V_307 [ 2 ] ;
}
break;
}
}
return V_302 ;
}
int F_145 ( struct V_12 * V_12 , T_1 * * V_312 )
{
int V_302 = 0 ;
int V_2 , V_27 , V_272 , V_281 ;
const T_1 * V_271 ;
V_271 = F_96 ( V_12 ) ;
if ( ! V_271 ) {
F_14 ( L_28 ) ;
return - V_303 ;
}
if ( F_129 ( V_271 ) < 3 ) {
F_14 ( L_29 ) ;
return - V_304 ;
}
if ( F_130 ( V_271 , & V_27 , & V_272 ) ) {
F_14 ( L_30 ) ;
return - V_305 ;
}
F_134 (cea, i, start, end) {
const T_1 * V_248 = & V_271 [ V_2 ] ;
if ( F_128 ( V_248 ) == V_298 ) {
V_281 = F_127 ( V_248 ) ;
if ( V_281 == 3 ) {
* V_312 = F_29 ( & V_248 [ 1 ] , V_281 , V_53 ) ;
if ( ! * V_312 )
return - V_306 ;
V_302 = V_281 ;
break;
}
}
}
return V_302 ;
}
int F_146 ( struct V_41 * V_42 ,
const struct V_70 * V_83 )
{
int V_2 = ! ! ( V_83 -> V_36 & V_139 ) ;
int V_117 , V_313 ;
if ( ! V_42 -> V_285 [ 0 ] )
return 0 ;
if ( ! V_42 -> V_285 [ 1 ] )
V_2 = 0 ;
V_117 = V_42 -> V_287 [ V_2 ] ;
V_313 = V_42 -> V_286 [ V_2 ] ;
if ( V_117 == 255 || V_313 == 255 )
return 0 ;
if ( V_117 )
V_117 = F_46 ( 2 * ( V_117 - 1 ) , 500 ) ;
if ( V_313 )
V_313 = F_46 ( 2 * ( V_313 - 1 ) , 500 ) ;
return F_147 ( V_313 - V_117 , 0 ) ;
}
bool F_148 ( struct V_12 * V_12 )
{
T_1 * V_228 ;
int V_2 ;
int V_314 , V_315 ;
V_228 = F_96 ( V_12 ) ;
if ( ! V_228 )
return false ;
if ( F_130 ( V_228 , & V_314 , & V_315 ) )
return false ;
F_134 (edid_ext, i, start_offset, end_offset) {
if ( F_131 ( & V_228 [ V_2 ] ) )
return true ;
}
return false ;
}
bool F_149 ( struct V_12 * V_12 )
{
T_1 * V_228 ;
int V_2 , V_50 ;
bool V_316 = false ;
int V_314 , V_315 ;
V_228 = F_96 ( V_12 ) ;
if ( ! V_228 )
goto V_272;
V_316 = ( ( V_228 [ 3 ] & V_317 ) != 0 ) ;
if ( V_316 ) {
F_14 ( L_31 ) ;
goto V_272;
}
if ( F_130 ( V_228 , & V_314 , & V_315 ) )
goto V_272;
F_134 (edid_ext, i, start_offset, end_offset) {
if ( F_128 ( & V_228 [ V_2 ] ) == V_297 ) {
V_316 = true ;
for ( V_50 = 1 ; V_50 < F_127 ( & V_228 [ V_2 ] ) + 1 ; V_50 += 3 )
F_14 ( L_32 ,
( V_228 [ V_2 + V_50 ] >> 3 ) & 0xf ) ;
goto V_272;
}
}
V_272:
return V_316 ;
}
bool F_150 ( struct V_12 * V_12 )
{
T_1 * V_228 ;
int V_2 , V_27 , V_272 ;
V_228 = F_96 ( V_12 ) ;
if ( ! V_228 )
return false ;
if ( F_130 ( V_228 , & V_27 , & V_272 ) )
return false ;
F_134 (edid_ext, i, start, end) {
if ( F_128 ( & V_228 [ V_2 ] ) == V_318 &&
F_127 ( & V_228 [ V_2 ] ) == 2 ) {
F_14 ( L_33 , V_228 [ V_2 + 2 ] ) ;
return V_228 [ V_2 + 2 ] & V_319 ;
}
}
return false ;
}
enum V_320
F_151 ( const struct V_70 * V_83 )
{
return F_104 ( V_83 ) > 1 ?
V_321 :
V_322 ;
}
static void F_152 ( struct V_41 * V_42 ,
const T_1 * V_323 )
{
struct V_324 * V_325 = & V_42 -> V_326 ;
struct V_327 * V_279 = & V_325 -> V_279 ;
if ( V_323 [ 6 ] & 0x80 ) {
V_279 -> V_328 . V_329 = true ;
if ( V_323 [ 6 ] & 0x40 )
V_279 -> V_328 . V_330 = true ;
}
if ( V_323 [ 5 ] ) {
T_3 V_331 = V_323 [ 5 ] * 5000 ;
struct V_332 * V_328 = & V_279 -> V_328 ;
if ( V_331 > 340000 ) {
V_325 -> V_331 = V_331 ;
F_14 ( L_34 ,
V_325 -> V_331 ) ;
}
if ( V_328 -> V_329 ) {
V_328 -> V_333 . V_329 = true ;
if ( ( V_323 [ 6 ] & 0x8 ) )
V_328 -> V_333 . V_334 = true ;
}
}
}
static void F_153 ( struct V_41 * V_42 ,
const T_1 * V_279 )
{
struct V_324 * V_335 = & V_42 -> V_326 ;
unsigned int V_336 = 0 ;
V_335 -> V_337 = 8 ;
if ( F_127 ( V_279 ) < 6 )
return;
if ( V_279 [ 6 ] & V_338 ) {
V_336 = 10 ;
V_335 -> V_339 |= V_338 ;
F_7 ( L_35 ,
V_42 -> V_40 ) ;
}
if ( V_279 [ 6 ] & V_340 ) {
V_336 = 12 ;
V_335 -> V_339 |= V_340 ;
F_7 ( L_36 ,
V_42 -> V_40 ) ;
}
if ( V_279 [ 6 ] & V_341 ) {
V_336 = 16 ;
V_335 -> V_339 |= V_341 ;
F_7 ( L_37 ,
V_42 -> V_40 ) ;
}
if ( V_336 == 0 ) {
F_7 ( L_38 ,
V_42 -> V_40 ) ;
return;
}
F_7 ( L_39 ,
V_42 -> V_40 , V_336 ) ;
V_335 -> V_337 = V_336 ;
V_335 -> V_342 = V_343 ;
if ( V_279 [ 6 ] & V_344 ) {
V_335 -> V_342 |= V_345 ;
F_7 ( L_40 ,
V_42 -> V_40 ) ;
}
if ( ! ( V_279 [ 6 ] & V_340 ) ) {
F_7 ( L_41 ,
V_42 -> V_40 ) ;
}
}
static void
F_154 ( struct V_41 * V_42 , const T_1 * V_248 )
{
struct V_324 * V_335 = & V_42 -> V_326 ;
T_1 V_24 = F_127 ( V_248 ) ;
if ( V_24 >= 6 )
V_335 -> V_346 = V_248 [ 6 ] & 1 ;
if ( V_24 >= 7 )
V_335 -> V_331 = V_248 [ 7 ] * 5000 ;
F_14 ( L_42
L_43 ,
V_335 -> V_346 ,
V_335 -> V_331 ) ;
F_153 ( V_42 , V_248 ) ;
}
static void F_155 ( struct V_41 * V_42 ,
struct V_12 * V_12 )
{
struct V_324 * V_335 = & V_42 -> V_326 ;
const T_1 * V_228 ;
int V_2 , V_27 , V_272 ;
V_228 = F_96 ( V_12 ) ;
if ( ! V_228 )
return;
V_335 -> V_347 = V_228 [ 1 ] ;
V_335 -> V_342 = V_343 ;
if ( V_228 [ 3 ] & V_348 )
V_335 -> V_342 |= V_345 ;
if ( V_228 [ 3 ] & V_349 )
V_335 -> V_342 |= V_350 ;
if ( F_130 ( V_228 , & V_27 , & V_272 ) )
return;
F_134 (edid_ext, i, start, end) {
const T_1 * V_248 = & V_228 [ V_2 ] ;
if ( F_131 ( V_248 ) )
F_154 ( V_42 , V_248 ) ;
if ( F_132 ( V_248 ) )
F_152 ( V_42 , V_248 ) ;
}
}
static void F_156 ( struct V_41 * V_42 ,
struct V_12 * V_12 )
{
struct V_324 * V_335 = & V_42 -> V_326 ;
V_335 -> V_173 = V_12 -> V_180 * 10 ;
V_335 -> V_176 = V_12 -> V_181 * 10 ;
V_335 -> V_337 = 0 ;
V_335 -> V_342 = 0 ;
V_335 -> V_347 = 0 ;
V_335 -> V_331 = 0 ;
V_335 -> V_346 = false ;
if ( V_12 -> V_17 < 3 )
return;
if ( ! ( V_12 -> V_109 & V_110 ) )
return;
F_155 ( V_42 , V_12 ) ;
if ( ( V_335 -> V_337 == 0 ) && ( V_12 -> V_17 < 4 ) &&
( V_12 -> V_109 & V_351 ) ) {
V_335 -> V_337 = 8 ;
F_7 ( L_44 ,
V_42 -> V_40 , V_335 -> V_337 ) ;
}
if ( V_12 -> V_17 < 4 )
return;
switch ( V_12 -> V_109 & V_352 ) {
case V_353 :
V_335 -> V_337 = 6 ;
break;
case V_354 :
V_335 -> V_337 = 8 ;
break;
case V_355 :
V_335 -> V_337 = 10 ;
break;
case V_356 :
V_335 -> V_337 = 12 ;
break;
case V_357 :
V_335 -> V_337 = 14 ;
break;
case V_358 :
V_335 -> V_337 = 16 ;
break;
case V_359 :
default:
V_335 -> V_337 = 0 ;
break;
}
F_7 ( L_45 ,
V_42 -> V_40 , V_335 -> V_337 ) ;
V_335 -> V_342 |= V_343 ;
if ( V_12 -> V_111 & V_360 )
V_335 -> V_342 |= V_345 ;
if ( V_12 -> V_111 & V_361 )
V_335 -> V_342 |= V_350 ;
}
static int F_157 ( T_1 * V_362 , int V_8 , int V_363 )
{
int V_2 ;
T_1 V_5 = 0 ;
struct V_364 * V_57 ;
V_57 = (struct V_364 * ) & V_362 [ V_363 ] ;
F_14 ( L_46 ,
V_57 -> V_365 , V_57 -> V_366 , V_57 -> V_367 , V_57 -> V_368 ) ;
if ( V_57 -> V_366 + 5 > V_8 - V_363 )
return - V_369 ;
for ( V_2 = V_363 ; V_2 <= V_57 -> V_366 + 5 ; V_2 ++ ) {
V_5 += V_362 [ V_2 ] ;
}
if ( V_5 ) {
F_8 ( L_47 , V_5 ) ;
return - V_369 ;
}
return 0 ;
}
static struct V_70 * F_158 ( struct V_90 * V_47 ,
struct V_370 * V_213 )
{
struct V_70 * V_83 ;
unsigned V_165 = ( V_213 -> V_165 [ 0 ] |
( V_213 -> V_165 [ 1 ] << 8 ) |
( V_213 -> V_165 [ 2 ] << 16 ) ) ;
unsigned V_142 = ( V_213 -> V_142 [ 0 ] | V_213 -> V_142 [ 1 ] << 8 ) + 1 ;
unsigned V_148 = ( V_213 -> V_148 [ 0 ] | V_213 -> V_148 [ 1 ] << 8 ) + 1 ;
unsigned V_183 = ( V_213 -> V_183 [ 0 ] | ( V_213 -> V_183 [ 1 ] & 0x7f ) << 8 ) + 1 ;
unsigned V_371 = ( V_213 -> V_372 [ 0 ] | V_213 -> V_372 [ 1 ] << 8 ) + 1 ;
unsigned V_145 = ( V_213 -> V_145 [ 0 ] | V_213 -> V_145 [ 1 ] << 8 ) + 1 ;
unsigned V_150 = ( V_213 -> V_150 [ 0 ] | V_213 -> V_150 [ 1 ] << 8 ) + 1 ;
unsigned V_186 = ( V_213 -> V_186 [ 0 ] | ( V_213 -> V_186 [ 1 ] & 0x7f ) << 8 ) + 1 ;
unsigned V_373 = ( V_213 -> V_374 [ 0 ] | V_213 -> V_374 [ 1 ] << 8 ) + 1 ;
bool V_375 = ( V_213 -> V_183 [ 1 ] >> 7 ) & 0x1 ;
bool V_376 = ( V_213 -> V_186 [ 1 ] >> 7 ) & 0x1 ;
V_83 = F_67 ( V_47 ) ;
if ( ! V_83 )
return NULL ;
V_83 -> clock = V_165 * 10 ;
V_83 -> V_85 = V_142 ;
V_83 -> V_87 = V_83 -> V_85 + V_183 ;
V_83 -> V_86 = V_83 -> V_87 + V_371 ;
V_83 -> V_84 = V_83 -> V_85 + V_148 ;
V_83 -> V_89 = V_145 ;
V_83 -> V_88 = V_83 -> V_89 + V_186 ;
V_83 -> V_137 = V_83 -> V_88 + V_373 ;
V_83 -> V_138 = V_83 -> V_89 + V_150 ;
V_83 -> V_36 = 0 ;
V_83 -> V_36 |= V_375 ? V_169 : V_170 ;
V_83 -> V_36 |= V_376 ? V_171 : V_172 ;
V_83 -> type = V_182 ;
if ( V_213 -> V_36 & 0x80 )
V_83 -> type |= V_81 ;
V_83 -> V_82 = F_39 ( V_83 ) ;
F_70 ( V_83 ) ;
return V_83 ;
}
static int F_159 ( struct V_41 * V_42 ,
struct V_377 * V_9 )
{
struct V_378 * V_379 = (struct V_378 * ) V_9 ;
int V_2 ;
int V_380 ;
struct V_70 * V_192 ;
int V_381 = 0 ;
if ( V_9 -> V_382 % 20 )
return 0 ;
V_380 = V_9 -> V_382 / 20 ;
for ( V_2 = 0 ; V_2 < V_380 ; V_2 ++ ) {
struct V_370 * V_213 = & V_379 -> V_213 [ V_2 ] ;
V_192 = F_158 ( V_42 -> V_47 , V_213 ) ;
if ( ! V_192 )
continue;
F_77 ( V_42 , V_192 ) ;
V_381 ++ ;
}
return V_381 ;
}
static int F_160 ( struct V_41 * V_42 ,
struct V_12 * V_12 )
{
T_1 * V_362 ;
int V_30 ;
int V_363 = 1 ;
int V_8 = V_6 ;
struct V_377 * V_9 ;
int V_381 = 0 ;
V_362 = F_97 ( V_12 ) ;
if ( ! V_362 )
return 0 ;
V_30 = F_157 ( V_362 , V_8 , V_363 ) ;
if ( V_30 )
return 0 ;
V_363 += sizeof( struct V_364 ) ;
while ( V_9 = (struct V_377 * ) & V_362 [ V_363 ] ,
V_363 + sizeof( struct V_377 ) <= V_8 &&
V_363 + sizeof( struct V_377 ) + V_9 -> V_382 <= V_8 &&
V_9 -> V_382 > 0 ) {
V_363 += V_9 -> V_382 + sizeof( struct V_377 ) ;
switch ( V_9 -> V_383 ) {
case V_384 :
V_381 += F_159 ( V_42 , V_9 ) ;
break;
}
}
return V_381 ;
}
int F_161 ( struct V_41 * V_42 , struct V_12 * V_12 )
{
int V_381 = 0 ;
T_3 V_69 ;
if ( V_12 == NULL ) {
return 0 ;
}
if ( ! F_11 ( V_12 ) ) {
F_16 ( V_42 -> V_47 -> V_47 , L_48 ,
V_42 -> V_40 ) ;
return 0 ;
}
V_69 = F_31 ( V_12 ) ;
V_381 += F_94 ( V_42 , V_12 , V_69 ) ;
V_381 += F_91 ( V_42 , V_12 ) ;
V_381 += F_88 ( V_42 , V_12 ) ;
V_381 += F_86 ( V_42 , V_12 ) ;
V_381 += F_133 ( V_42 , V_12 ) ;
V_381 += F_113 ( V_42 , V_12 ) ;
V_381 += F_160 ( V_42 , V_12 ) ;
if ( V_12 -> V_111 & V_112 )
V_381 += F_83 ( V_42 , V_12 ) ;
if ( V_69 & ( V_78 | V_79 ) )
F_34 ( V_42 , V_69 ) ;
F_156 ( V_42 , V_12 ) ;
if ( V_69 & V_385 )
V_42 -> V_326 . V_337 = 6 ;
if ( V_69 & V_386 )
V_42 -> V_326 . V_337 = 8 ;
if ( V_69 & V_387 )
V_42 -> V_326 . V_337 = 10 ;
if ( V_69 & V_388 )
V_42 -> V_326 . V_337 = 12 ;
return V_381 ;
}
int F_162 ( struct V_41 * V_42 ,
int V_85 , int V_89 )
{
int V_2 , V_302 , V_381 = 0 ;
struct V_70 * V_83 ;
struct V_90 * V_47 = V_42 -> V_47 ;
V_302 = F_32 ( V_95 ) ;
if ( V_85 < 0 )
V_85 = 0 ;
if ( V_89 < 0 )
V_89 = 0 ;
for ( V_2 = 0 ; V_2 < V_302 ; V_2 ++ ) {
const struct V_70 * V_96 = & V_95 [ V_2 ] ;
if ( V_85 && V_89 ) {
if ( V_96 -> V_85 > V_85 ||
V_96 -> V_89 > V_89 )
continue;
}
if ( F_39 ( V_96 ) > 61 )
continue;
V_83 = F_43 ( V_47 , V_96 ) ;
if ( V_83 ) {
F_77 ( V_42 , V_83 ) ;
V_381 ++ ;
}
}
return V_381 ;
}
void F_163 ( struct V_41 * V_42 ,
int V_389 , int V_390 )
{
struct V_70 * V_83 ;
F_59 (mode, &connector->probed_modes, head) {
if ( V_83 -> V_85 == V_389 &&
V_83 -> V_89 == V_390 )
V_83 -> type |= V_81 ;
}
}
int
F_164 ( struct V_391 * V_392 ,
const struct V_70 * V_83 )
{
int V_393 ;
if ( ! V_392 || ! V_83 )
return - V_369 ;
V_393 = F_165 ( V_392 ) ;
if ( V_393 < 0 )
return V_393 ;
if ( V_83 -> V_36 & V_394 )
V_392 -> V_395 = 1 ;
V_392 -> V_238 = F_104 ( V_83 ) ;
V_392 -> V_396 = V_397 ;
if ( V_83 -> V_239 == V_398 ||
V_83 -> V_239 == V_399 )
V_392 -> V_396 = V_83 -> V_239 ;
else if ( V_392 -> V_238 > 0 )
V_392 -> V_396 = F_107 (
V_392 -> V_238 ) ;
V_392 -> V_400 = V_401 ;
V_392 -> V_402 = V_403 ;
return 0 ;
}
void
F_166 ( struct V_391 * V_392 ,
const struct V_70 * V_83 ,
enum V_320 V_404 ,
bool V_405 )
{
if ( V_405 ||
V_404 == F_151 ( V_83 ) )
V_392 -> V_406 = V_404 ;
else
V_392 -> V_406 = V_407 ;
if ( V_404 == V_321 )
V_392 -> V_408 =
V_409 ;
else
V_392 -> V_408 =
V_410 ;
}
static enum V_411
F_167 ( const struct V_70 * V_83 )
{
T_3 V_412 = V_83 -> V_36 & V_244 ;
switch ( V_412 ) {
case V_258 :
return V_413 ;
case V_414 :
return V_415 ;
case V_416 :
return V_417 ;
case V_418 :
return V_419 ;
case V_420 :
return V_421 ;
case V_422 :
return V_423 ;
case V_259 :
return V_424 ;
case V_260 :
return V_425 ;
default:
return V_426 ;
}
}
int
F_168 ( struct V_427 * V_392 ,
const struct V_70 * V_83 )
{
int V_393 ;
T_3 V_428 ;
T_1 V_231 ;
if ( ! V_392 || ! V_83 )
return - V_369 ;
V_231 = F_111 ( V_83 ) ;
V_428 = V_83 -> V_36 & V_244 ;
if ( ! V_231 && ! V_428 )
return - V_369 ;
if ( V_231 && V_428 )
return - V_369 ;
V_393 = F_169 ( V_392 ) ;
if ( V_393 < 0 )
return V_393 ;
if ( V_231 )
V_392 -> V_231 = V_231 ;
else
V_392 -> V_429 = F_167 ( V_83 ) ;
return 0 ;
}
static int F_170 ( struct V_41 * V_42 ,
struct V_377 * V_9 )
{
struct V_430 * V_431 = (struct V_430 * ) V_9 ;
T_5 V_132 , V_133 ;
T_1 V_432 , V_433 ;
T_1 V_434 , V_435 ;
struct V_436 * V_437 ;
V_132 = V_431 -> V_438 [ 0 ] | V_431 -> V_438 [ 1 ] << 8 ;
V_133 = V_431 -> V_438 [ 2 ] | V_431 -> V_438 [ 3 ] << 8 ;
V_434 = ( V_431 -> V_439 [ 0 ] & 0xf ) | ( V_431 -> V_439 [ 2 ] & 0x30 ) ;
V_435 = ( V_431 -> V_439 [ 0 ] >> 4 ) | ( ( V_431 -> V_439 [ 2 ] >> 2 ) & 0x30 ) ;
V_432 = ( V_431 -> V_439 [ 1 ] & 0xf ) | ( ( V_431 -> V_439 [ 2 ] & 0x3 ) << 4 ) ;
V_433 = ( V_431 -> V_439 [ 1 ] >> 4 ) | ( ( ( V_431 -> V_439 [ 2 ] >> 2 ) & 0x3 ) << 4 ) ;
V_42 -> V_440 = true ;
if ( V_431 -> V_441 & 0x80 )
V_42 -> V_442 = true ;
V_42 -> V_435 = V_435 + 1 ;
V_42 -> V_434 = V_434 + 1 ;
V_42 -> V_433 = V_433 ;
V_42 -> V_432 = V_432 ;
V_42 -> V_443 = V_132 + 1 ;
V_42 -> V_444 = V_133 + 1 ;
F_14 ( L_49 , V_431 -> V_441 ) ;
F_14 ( L_50 , V_132 + 1 , V_133 + 1 ) ;
F_14 ( L_51 ,
V_435 + 1 , V_434 + 1 , V_433 , V_432 ) ;
F_14 ( L_52 , V_431 -> V_445 [ 0 ] , V_431 -> V_445 [ 1 ] , V_431 -> V_445 [ 2 ] ) ;
V_437 = F_171 ( V_42 -> V_47 , V_431 -> V_445 ) ;
if ( ! V_437 ) {
V_437 = F_172 ( V_42 -> V_47 , V_431 -> V_445 ) ;
}
if ( ! V_437 )
return - V_306 ;
if ( V_42 -> V_446 != V_437 ) {
if ( V_42 -> V_446 ) {
F_173 ( V_42 -> V_47 , V_42 -> V_446 ) ;
}
V_42 -> V_446 = V_437 ;
} else
F_173 ( V_42 -> V_47 , V_437 ) ;
return 0 ;
}
static int F_174 ( struct V_41 * V_42 ,
T_1 * V_362 , int V_8 ,
bool V_447 )
{
int V_363 = 0 ;
struct V_377 * V_9 ;
int V_30 ;
if ( V_447 )
V_363 = 1 ;
V_30 = F_157 ( V_362 , V_8 , V_363 ) ;
if ( V_30 )
return V_30 ;
V_363 += sizeof( struct V_364 ) ;
while ( V_9 = (struct V_377 * ) & V_362 [ V_363 ] ,
V_363 + sizeof( struct V_377 ) <= V_8 &&
V_363 + sizeof( struct V_377 ) + V_9 -> V_382 <= V_8 &&
V_9 -> V_382 > 0 ) {
V_363 += V_9 -> V_382 + sizeof( struct V_377 ) ;
F_14 ( L_53 ,
V_9 -> V_383 , V_9 -> V_365 , V_9 -> V_382 ) ;
switch ( V_9 -> V_383 ) {
case V_448 :
V_30 = F_170 ( V_42 , V_9 ) ;
if ( V_30 )
return V_30 ;
break;
case V_384 :
break;
default:
F_14 ( L_54 , V_9 -> V_383 ) ;
break;
}
}
return 0 ;
}
static void F_24 ( struct V_41 * V_42 ,
struct V_12 * V_12 )
{
void * V_362 = NULL ;
int V_30 ;
V_42 -> V_440 = false ;
V_362 = F_97 ( V_12 ) ;
if ( ! V_362 ) {
goto V_449;
}
V_30 = F_174 ( V_42 , V_362 , V_6 , true ) ;
if ( V_30 < 0 )
goto V_449;
if ( ! V_42 -> V_440 )
goto V_449;
return;
V_449:
if ( V_42 -> V_446 ) {
F_173 ( V_42 -> V_47 , V_42 -> V_446 ) ;
V_42 -> V_446 = NULL ;
}
return;
}
