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
static T_1 F_117 ( T_1 V_245 )
{
if ( ( V_245 >= 1 && V_245 <= 64 ) || ( V_245 >= 129 && V_245 <= 192 ) )
return V_245 & 127 ;
return V_245 ;
}
static struct V_70 *
F_118 ( struct V_41 * V_42 ,
const T_1 * V_246 , T_1 V_247 ,
T_1 V_248 )
{
struct V_90 * V_47 = V_42 -> V_47 ;
struct V_70 * V_192 ;
T_1 V_231 ;
if ( V_246 == NULL || V_248 >= V_247 )
return NULL ;
V_231 = F_117 ( V_246 [ V_248 ] ) ;
if ( ! F_106 ( V_231 ) )
return NULL ;
V_192 = F_43 ( V_47 , & V_232 [ V_231 ] ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_82 = 0 ;
return V_192 ;
}
static int F_119 ( struct V_41 * V_42 ,
const T_1 * V_249 , T_1 V_250 )
{
int V_191 = 0 , V_2 ;
struct V_90 * V_47 = V_42 -> V_47 ;
struct V_251 * V_252 = & V_42 -> V_253 ;
struct V_254 * V_255 = & V_252 -> V_255 ;
for ( V_2 = 0 ; V_2 < V_250 ; V_2 ++ ) {
T_1 V_231 = F_117 ( V_249 [ V_2 ] ) ;
struct V_70 * V_192 ;
if ( ! F_106 ( V_231 ) )
continue;
V_192 = F_43 ( V_47 , & V_232 [ V_231 ] ) ;
if ( ! V_192 )
break;
F_120 ( V_255 -> V_256 , V_231 , 1 ) ;
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
if ( V_191 > 0 )
V_252 -> V_257 |= V_258 ;
return V_191 ;
}
static void
F_121 ( struct V_41 * V_42 , T_1 V_245 )
{
T_1 V_231 = F_117 ( V_245 ) ;
struct V_254 * V_255 = & V_42 -> V_253 . V_255 ;
if ( ! F_106 ( V_231 ) )
return;
F_120 ( V_255 -> V_259 , V_231 , 1 ) ;
}
static int
F_122 ( struct V_41 * V_42 , const T_1 * V_260 , T_1 V_24 )
{
int V_2 , V_191 = 0 ;
struct V_254 * V_255 = & V_42 -> V_253 . V_255 ;
for ( V_2 = 0 ; V_2 < V_24 ; V_2 ++ ) {
struct V_70 * V_83 ;
V_83 = F_118 ( V_42 , V_260 , V_24 , V_2 ) ;
if ( V_83 ) {
if ( V_2 < 64 && V_255 -> V_261 & ( 1ULL << V_2 ) )
F_121 ( V_42 , V_260 [ V_2 ] ) ;
F_77 ( V_42 , V_83 ) ;
V_191 ++ ;
}
}
return V_191 ;
}
static bool
F_123 ( const struct V_70 * V_83 ,
const struct V_262 * V_263 )
{
unsigned int V_264 = V_83 -> V_36 & V_139 ;
return V_83 -> V_85 == V_263 -> V_221 &&
V_83 -> V_89 == V_263 -> V_222 &&
V_264 == ( V_263 -> V_36 & V_139 ) &&
F_39 ( V_83 ) == V_263 -> V_82 ;
}
static int F_124 ( struct V_41 * V_42 )
{
struct V_90 * V_47 = V_42 -> V_47 ;
const struct V_70 * V_83 ;
struct V_265 V_266 ;
int V_191 = 0 , V_2 ;
F_125 ( & V_266 ) ;
F_59 (mode, &connector->probed_modes, head) {
for ( V_2 = 0 ; V_2 < F_32 ( V_267 ) ; V_2 ++ ) {
const struct V_262 * V_268 ;
struct V_70 * V_269 ;
if ( ! F_123 ( V_83 ,
& V_267 [ V_2 ] ) )
continue;
V_268 = & V_267 [ V_2 ] ;
V_269 = F_43 ( V_47 , V_83 ) ;
if ( ! V_269 )
continue;
V_269 -> V_36 |= V_268 -> V_36 ;
F_115 ( & V_269 -> V_80 , & V_266 ) ;
V_191 ++ ;
}
}
F_126 ( & V_266 , & V_42 -> V_77 ) ;
return V_191 ;
}
static int F_127 ( struct V_41 * V_42 , T_1 V_231 )
{
struct V_90 * V_47 = V_42 -> V_47 ;
struct V_70 * V_192 ;
if ( ! F_112 ( V_231 ) ) {
F_128 ( L_18 , V_231 ) ;
return 0 ;
}
V_192 = F_43 ( V_47 , & V_241 [ V_231 ] ) ;
if ( ! V_192 )
return 0 ;
F_77 ( V_42 , V_192 ) ;
return 1 ;
}
static int F_129 ( struct V_41 * V_42 , T_5 V_270 ,
const T_1 * V_246 , T_1 V_247 , T_1 V_248 )
{
struct V_70 * V_192 ;
int V_191 = 0 ;
if ( V_270 & ( 1 << 0 ) ) {
V_192 = F_118 ( V_42 , V_246 ,
V_247 ,
V_248 ) ;
if ( V_192 ) {
V_192 -> V_36 |= V_271 ;
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
if ( V_270 & ( 1 << 6 ) ) {
V_192 = F_118 ( V_42 , V_246 ,
V_247 ,
V_248 ) ;
if ( V_192 ) {
V_192 -> V_36 |= V_272 ;
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
if ( V_270 & ( 1 << 8 ) ) {
V_192 = F_118 ( V_42 , V_246 ,
V_247 ,
V_248 ) ;
if ( V_192 ) {
V_192 -> V_36 |= V_273 ;
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
return V_191 ;
}
static int
F_130 ( struct V_41 * V_42 , const T_1 * V_260 , T_1 V_24 ,
const T_1 * V_246 , T_1 V_247 )
{
int V_191 = 0 , V_274 = 0 , V_2 , V_275 = 0 , V_276 ;
T_1 V_277 , V_278 = 0 ;
T_5 V_279 ;
T_5 V_280 ;
if ( V_24 < 8 )
goto V_54;
if ( ! ( V_260 [ 8 ] & ( 1 << 5 ) ) )
goto V_54;
if ( V_260 [ 8 ] & ( 1 << 7 ) )
V_274 += 2 ;
if ( V_260 [ 8 ] & ( 1 << 6 ) )
V_274 += 2 ;
if ( V_24 < ( 8 + V_274 + 2 ) )
goto V_54;
V_274 ++ ;
if ( V_260 [ 8 + V_274 ] & ( 1 << 7 ) ) {
V_191 += F_124 ( V_42 ) ;
V_275 = ( V_260 [ 8 + V_274 ] & 0x60 ) >> 5 ;
}
V_274 ++ ;
V_277 = V_260 [ 8 + V_274 ] >> 5 ;
V_278 = V_260 [ 8 + V_274 ] & 0x1f ;
for ( V_2 = 0 ; V_2 < V_277 && V_24 >= ( 9 + V_274 + V_2 ) ; V_2 ++ ) {
T_1 V_231 ;
V_231 = V_260 [ 9 + V_274 + V_2 ] ;
V_191 += F_127 ( V_42 , V_231 ) ;
}
V_274 += 1 + V_277 ;
if ( V_275 == 1 )
V_276 = 2 ;
else if ( V_275 == 2 )
V_276 = 4 ;
else
V_276 = 0 ;
if ( V_24 < ( 8 + V_274 + V_278 - 1 ) )
goto V_54;
if ( V_278 < V_276 )
goto V_54;
if ( V_275 == 1 || V_275 == 2 ) {
V_280 = ( V_260 [ 8 + V_274 ] << 8 ) | V_260 [ 9 + V_274 ] ;
if ( V_275 == 2 )
V_279 = ( V_260 [ 10 + V_274 ] << 8 ) | V_260 [ 11 + V_274 ] ;
else
V_279 = 0xffff ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
if ( V_279 & ( 1 << V_2 ) )
V_191 += F_129 ( V_42 ,
V_280 ,
V_246 ,
V_247 , V_2 ) ;
}
}
V_274 += V_276 ;
for ( V_2 = 0 ; V_2 < ( V_278 - V_276 ) ; V_2 ++ ) {
int V_281 ;
struct V_70 * V_192 = NULL ;
unsigned int V_282 = 0 ;
bool V_283 ;
V_283 = ( ( V_260 [ 8 + V_274 + V_2 ] & 0x0f ) > 7 ) ;
if ( V_283 && ( V_2 + 1 == V_278 - V_276 ) )
break;
V_281 = V_260 [ 8 + V_274 + V_2 ] >> 4 ;
switch ( V_260 [ 8 + V_274 + V_2 ] & 0x0f ) {
case 0 :
V_282 = V_271 ;
break;
case 6 :
V_282 = V_272 ;
break;
case 8 :
if ( ( V_260 [ 9 + V_274 + V_2 ] >> 4 ) == 1 )
V_282 = V_273 ;
break;
}
if ( V_282 != 0 ) {
V_192 = F_118 ( V_42 ,
V_246 ,
V_247 ,
V_281 ) ;
if ( V_192 ) {
V_192 -> V_36 |= V_282 ;
F_77 ( V_42 , V_192 ) ;
V_191 ++ ;
}
}
if ( V_283 )
V_2 ++ ;
}
V_54:
return V_191 ;
}
static int
F_131 ( const T_1 * V_260 )
{
return V_260 [ 0 ] & 0x1f ;
}
static int
F_132 ( const T_1 * V_260 )
{
return V_260 [ 1 ] ;
}
static int
F_133 ( const T_1 * V_260 )
{
return V_260 [ 0 ] >> 5 ;
}
static int
F_134 ( const T_1 * V_284 )
{
return V_284 [ 1 ] ;
}
static int
F_135 ( const T_1 * V_284 , int * V_27 , int * V_285 )
{
* V_27 = 4 ;
* V_285 = V_284 [ 2 ] ;
if ( * V_285 == 0 )
* V_285 = 127 ;
if ( * V_285 < 4 || * V_285 > 127 )
return - V_286 ;
return 0 ;
}
static bool F_136 ( const T_1 * V_260 )
{
int V_287 ;
if ( F_133 ( V_260 ) != V_288 )
return false ;
if ( F_131 ( V_260 ) < 5 )
return false ;
V_287 = V_260 [ 1 ] | ( V_260 [ 2 ] << 8 ) | ( V_260 [ 3 ] << 16 ) ;
return V_287 == V_289 ;
}
static bool F_137 ( const T_1 * V_260 )
{
unsigned int V_290 ;
if ( F_133 ( V_260 ) != V_288 )
return false ;
if ( F_131 ( V_260 ) < 7 )
return false ;
V_290 = V_260 [ 3 ] << 16 | V_260 [ 2 ] << 8 | V_260 [ 1 ] ;
return V_290 == V_291 ;
}
static bool F_138 ( const T_1 * V_260 )
{
if ( F_133 ( V_260 ) != V_292 )
return false ;
if ( ! F_131 ( V_260 ) )
return false ;
if ( F_132 ( V_260 ) != V_293 )
return false ;
return true ;
}
static bool F_139 ( const T_1 * V_260 )
{
if ( F_133 ( V_260 ) != V_292 )
return false ;
if ( ! F_131 ( V_260 ) )
return false ;
if ( F_132 ( V_260 ) != V_294 )
return false ;
return true ;
}
static void F_140 ( struct V_41 * V_42 ,
const T_1 * V_260 )
{
struct V_251 * V_252 = & V_42 -> V_253 ;
struct V_254 * V_255 = & V_252 -> V_255 ;
T_1 V_295 = F_131 ( V_260 ) - 1 ;
T_1 V_296 ;
T_6 V_297 = 0 ;
if ( V_295 == 0 ) {
V_255 -> V_261 = V_298 ;
V_252 -> V_257 |= V_258 ;
return;
}
if ( F_141 ( V_295 > 8 ) )
V_295 = 8 ;
for ( V_296 = 0 ; V_296 < V_295 ; V_296 ++ )
V_297 |= ( T_6 ) V_260 [ 2 + V_296 ] << ( 8 * V_296 ) ;
if ( V_297 )
V_252 -> V_257 |= V_258 ;
V_255 -> V_261 = V_297 ;
}
static int
F_142 ( struct V_41 * V_42 , struct V_12 * V_12 )
{
const T_1 * V_284 = F_96 ( V_12 ) ;
const T_1 * V_260 , * V_255 = NULL , * V_299 = NULL ;
T_1 V_300 , V_301 , V_247 = 0 ;
int V_191 = 0 ;
if ( V_284 && F_134 ( V_284 ) >= 3 ) {
int V_2 , V_27 , V_285 ;
if ( F_135 ( V_284 , & V_27 , & V_285 ) )
return 0 ;
F_143 (cea, i, start, end) {
V_260 = & V_284 [ V_2 ] ;
V_300 = F_131 ( V_260 ) ;
if ( F_133 ( V_260 ) == V_302 ) {
V_299 = V_260 + 1 ;
V_247 = V_300 ;
V_191 += F_122 ( V_42 , V_299 , V_300 ) ;
} else if ( F_136 ( V_260 ) ) {
V_255 = V_260 ;
V_301 = V_300 ;
} else if ( F_139 ( V_260 ) ) {
const T_1 * V_303 = & V_260 [ 2 ] ;
V_191 += F_119 ( V_42 ,
V_303 ,
V_300 - 1 ) ;
}
}
}
if ( V_255 )
V_191 += F_130 ( V_42 , V_255 , V_301 , V_299 ,
V_247 ) ;
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
F_144 ( struct V_41 * V_42 , const T_1 * V_260 )
{
T_1 V_24 = F_131 ( V_260 ) ;
if ( V_24 >= 6 )
V_42 -> V_304 [ 5 ] |= ( V_260 [ 6 ] >> 7 ) << 1 ;
if ( V_24 >= 8 ) {
V_42 -> V_305 [ 0 ] = V_260 [ 8 ] >> 7 ;
V_42 -> V_305 [ 1 ] = ( V_260 [ 8 ] >> 6 ) & 1 ;
}
if ( V_24 >= 9 )
V_42 -> V_306 [ 0 ] = V_260 [ 9 ] ;
if ( V_24 >= 10 )
V_42 -> V_307 [ 0 ] = V_260 [ 10 ] ;
if ( V_24 >= 11 )
V_42 -> V_306 [ 1 ] = V_260 [ 11 ] ;
if ( V_24 >= 12 )
V_42 -> V_307 [ 1 ] = V_260 [ 12 ] ;
F_14 ( L_22
L_23
L_24 ,
V_42 -> V_305 [ 0 ] ,
V_42 -> V_305 [ 1 ] ,
V_42 -> V_306 [ 0 ] ,
V_42 -> V_306 [ 1 ] ,
V_42 -> V_307 [ 0 ] ,
V_42 -> V_307 [ 1 ] ) ;
}
static void
F_145 ( struct V_103 * V_71 , void * V_22 )
{
if ( V_71 -> V_22 . V_198 . type == V_308 )
* ( T_1 * * ) V_22 = V_71 -> V_22 . V_198 . V_22 . V_309 . V_309 ;
}
static int F_146 ( struct V_12 * V_12 , char V_40 [ 13 ] )
{
char * V_310 = NULL ;
int V_311 ;
if ( ! V_12 || ! V_40 )
return 0 ;
F_47 ( ( T_1 * ) V_12 , F_145 , & V_310 ) ;
for ( V_311 = 0 ; V_310 && V_311 < 13 ; V_311 ++ ) {
if ( V_310 [ V_311 ] == 0x0a )
break;
V_40 [ V_311 ] = V_310 [ V_311 ] ;
}
return V_311 ;
}
void F_147 ( struct V_12 * V_12 , char * V_40 , int V_312 )
{
int V_313 ;
char V_23 [ 13 ] ;
if ( V_312 <= 0 )
return;
V_313 = F_46 ( F_146 ( V_12 , V_23 ) , V_312 - 1 ) ;
memcpy ( V_40 , V_23 , V_313 ) ;
V_40 [ V_313 ] = '\0' ;
}
void F_148 ( struct V_41 * V_42 , struct V_12 * V_12 )
{
T_7 * V_304 = V_42 -> V_304 ;
T_1 * V_284 ;
T_1 * V_260 ;
int V_314 = 0 ;
int V_311 ;
int V_300 ;
memset ( V_304 , 0 , sizeof( V_42 -> V_304 ) ) ;
V_42 -> V_305 [ 0 ] = false ;
V_42 -> V_305 [ 1 ] = false ;
V_42 -> V_306 [ 0 ] = 0 ;
V_42 -> V_307 [ 0 ] = 0 ;
V_42 -> V_306 [ 1 ] = 0 ;
V_42 -> V_307 [ 1 ] = 0 ;
if ( ! V_12 )
return;
V_284 = F_96 ( V_12 ) ;
if ( ! V_284 ) {
F_14 ( L_25 ) ;
return;
}
V_311 = F_146 ( V_12 , V_304 + 20 ) ;
V_304 [ 4 ] = ( V_284 [ 1 ] << 5 ) | V_311 ;
F_14 ( L_26 , V_304 + 20 ) ;
V_304 [ 0 ] = 2 << 3 ;
V_304 [ 16 ] = V_12 -> V_64 [ 0 ] ;
V_304 [ 17 ] = V_12 -> V_64 [ 1 ] ;
V_304 [ 18 ] = V_12 -> V_315 [ 0 ] ;
V_304 [ 19 ] = V_12 -> V_315 [ 1 ] ;
if ( F_134 ( V_284 ) >= 3 ) {
int V_2 , V_27 , V_285 ;
if ( F_135 ( V_284 , & V_27 , & V_285 ) ) {
V_27 = 0 ;
V_285 = 0 ;
}
F_143 (cea, i, start, end) {
V_260 = & V_284 [ V_2 ] ;
V_300 = F_131 ( V_260 ) ;
switch ( F_133 ( V_260 ) ) {
int V_316 ;
case V_317 :
V_316 = F_46 ( V_300 / 3 , 15 - V_314 ) ;
if ( V_316 >= 1 )
memcpy ( V_304 + 20 + V_311 + V_314 * 3 ,
& V_260 [ 1 ] , V_316 * 3 ) ;
V_314 += V_316 ;
break;
case V_318 :
if ( V_300 >= 1 )
V_304 [ 7 ] = V_260 [ 1 ] ;
break;
case V_288 :
if ( F_136 ( V_260 ) )
F_144 ( V_42 , V_260 ) ;
break;
default:
break;
}
}
}
V_304 [ 5 ] |= V_314 << 4 ;
V_304 [ V_319 ] =
F_149 ( F_150 ( V_304 ) , 4 ) ;
F_14 ( L_27 ,
F_151 ( V_304 ) , V_314 ) ;
}
int F_152 ( struct V_12 * V_12 , struct V_320 * * V_321 )
{
int V_296 = 0 ;
int V_2 , V_27 , V_285 , V_300 ;
T_1 * V_284 ;
V_284 = F_96 ( V_12 ) ;
if ( ! V_284 ) {
F_14 ( L_28 ) ;
return - V_322 ;
}
if ( F_134 ( V_284 ) < 3 ) {
F_14 ( L_29 ) ;
return - V_323 ;
}
if ( F_135 ( V_284 , & V_27 , & V_285 ) ) {
F_14 ( L_30 ) ;
return - V_324 ;
}
F_143 (cea, i, start, end) {
T_1 * V_260 = & V_284 [ V_2 ] ;
if ( F_133 ( V_260 ) == V_317 ) {
int V_50 ;
V_300 = F_131 ( V_260 ) ;
V_296 = V_300 / 3 ;
* V_321 = F_153 ( V_296 , sizeof( * * V_321 ) , V_53 ) ;
if ( ! * V_321 )
return - V_325 ;
for ( V_50 = 0 ; V_50 < V_296 ; V_50 ++ ) {
T_1 * V_326 = & V_260 [ 1 + V_50 * 3 ] ;
( * V_321 ) [ V_50 ] . V_327 = ( V_326 [ 0 ] & 0x78 ) >> 3 ;
( * V_321 ) [ V_50 ] . V_328 = V_326 [ 0 ] & 0x7 ;
( * V_321 ) [ V_50 ] . V_329 = V_326 [ 1 ] & 0x7F ;
( * V_321 ) [ V_50 ] . V_330 = V_326 [ 2 ] ;
}
break;
}
}
return V_296 ;
}
int F_154 ( struct V_12 * V_12 , T_1 * * V_331 )
{
int V_296 = 0 ;
int V_2 , V_27 , V_285 , V_300 ;
const T_1 * V_284 ;
V_284 = F_96 ( V_12 ) ;
if ( ! V_284 ) {
F_14 ( L_28 ) ;
return - V_322 ;
}
if ( F_134 ( V_284 ) < 3 ) {
F_14 ( L_29 ) ;
return - V_323 ;
}
if ( F_135 ( V_284 , & V_27 , & V_285 ) ) {
F_14 ( L_30 ) ;
return - V_324 ;
}
F_143 (cea, i, start, end) {
const T_1 * V_260 = & V_284 [ V_2 ] ;
if ( F_133 ( V_260 ) == V_318 ) {
V_300 = F_131 ( V_260 ) ;
if ( V_300 == 3 ) {
* V_331 = F_29 ( & V_260 [ 1 ] , V_300 , V_53 ) ;
if ( ! * V_331 )
return - V_325 ;
V_296 = V_300 ;
break;
}
}
}
return V_296 ;
}
int F_155 ( struct V_41 * V_42 ,
const struct V_70 * V_83 )
{
int V_2 = ! ! ( V_83 -> V_36 & V_139 ) ;
int V_117 , V_332 ;
if ( ! V_42 -> V_305 [ 0 ] )
return 0 ;
if ( ! V_42 -> V_305 [ 1 ] )
V_2 = 0 ;
V_117 = V_42 -> V_307 [ V_2 ] ;
V_332 = V_42 -> V_306 [ V_2 ] ;
if ( V_117 == 255 || V_332 == 255 )
return 0 ;
if ( V_117 )
V_117 = F_46 ( 2 * ( V_117 - 1 ) , 500 ) ;
if ( V_332 )
V_332 = F_46 ( 2 * ( V_332 - 1 ) , 500 ) ;
return F_156 ( V_332 - V_117 , 0 ) ;
}
bool F_157 ( struct V_12 * V_12 )
{
T_1 * V_228 ;
int V_2 ;
int V_333 , V_334 ;
V_228 = F_96 ( V_12 ) ;
if ( ! V_228 )
return false ;
if ( F_135 ( V_228 , & V_333 , & V_334 ) )
return false ;
F_143 (edid_ext, i, start_offset, end_offset) {
if ( F_136 ( & V_228 [ V_2 ] ) )
return true ;
}
return false ;
}
bool F_158 ( struct V_12 * V_12 )
{
T_1 * V_228 ;
int V_2 , V_50 ;
bool V_335 = false ;
int V_333 , V_334 ;
V_228 = F_96 ( V_12 ) ;
if ( ! V_228 )
goto V_285;
V_335 = ( ( V_228 [ 3 ] & V_336 ) != 0 ) ;
if ( V_335 ) {
F_14 ( L_31 ) ;
goto V_285;
}
if ( F_135 ( V_228 , & V_333 , & V_334 ) )
goto V_285;
F_143 (edid_ext, i, start_offset, end_offset) {
if ( F_133 ( & V_228 [ V_2 ] ) == V_317 ) {
V_335 = true ;
for ( V_50 = 1 ; V_50 < F_131 ( & V_228 [ V_2 ] ) + 1 ; V_50 += 3 )
F_14 ( L_32 ,
( V_228 [ V_2 + V_50 ] >> 3 ) & 0xf ) ;
goto V_285;
}
}
V_285:
return V_335 ;
}
bool F_159 ( struct V_12 * V_12 )
{
T_1 * V_228 ;
int V_2 , V_27 , V_285 ;
V_228 = F_96 ( V_12 ) ;
if ( ! V_228 )
return false ;
if ( F_135 ( V_228 , & V_27 , & V_285 ) )
return false ;
F_143 (edid_ext, i, start, end) {
if ( F_133 ( & V_228 [ V_2 ] ) == V_292 &&
F_131 ( & V_228 [ V_2 ] ) == 2 &&
F_132 ( & V_228 [ V_2 ] ) ==
V_337 ) {
F_14 ( L_33 , V_228 [ V_2 + 2 ] ) ;
return V_228 [ V_2 + 2 ] & V_338 ;
}
}
return false ;
}
enum V_339
F_160 ( const struct V_70 * V_83 )
{
return F_104 ( V_83 ) > 1 ?
V_340 :
V_341 ;
}
static void F_161 ( struct V_41 * V_42 ,
const T_1 * V_260 )
{
T_1 V_342 ;
struct V_254 * V_255 = & V_42 -> V_253 . V_255 ;
V_342 = V_260 [ 7 ] & V_343 ;
V_255 -> V_344 |= V_342 ;
}
static void F_162 ( struct V_41 * V_42 ,
const T_1 * V_345 )
{
struct V_251 * V_346 = & V_42 -> V_253 ;
struct V_254 * V_255 = & V_346 -> V_255 ;
if ( V_345 [ 6 ] & 0x80 ) {
V_255 -> V_347 . V_348 = true ;
if ( V_345 [ 6 ] & 0x40 )
V_255 -> V_347 . V_349 = true ;
}
if ( V_345 [ 5 ] ) {
T_3 V_350 = V_345 [ 5 ] * 5000 ;
struct V_351 * V_347 = & V_255 -> V_347 ;
if ( V_350 > 340000 ) {
V_346 -> V_350 = V_350 ;
F_14 ( L_34 ,
V_346 -> V_350 ) ;
}
if ( V_347 -> V_348 ) {
V_347 -> V_352 . V_348 = true ;
if ( ( V_345 [ 6 ] & 0x8 ) )
V_347 -> V_352 . V_353 = true ;
}
}
F_161 ( V_42 , V_345 ) ;
}
static void F_163 ( struct V_41 * V_42 ,
const T_1 * V_255 )
{
struct V_251 * V_252 = & V_42 -> V_253 ;
unsigned int V_354 = 0 ;
V_252 -> V_355 = 8 ;
if ( F_131 ( V_255 ) < 6 )
return;
if ( V_255 [ 6 ] & V_356 ) {
V_354 = 10 ;
V_252 -> V_357 |= V_356 ;
F_7 ( L_35 ,
V_42 -> V_40 ) ;
}
if ( V_255 [ 6 ] & V_358 ) {
V_354 = 12 ;
V_252 -> V_357 |= V_358 ;
F_7 ( L_36 ,
V_42 -> V_40 ) ;
}
if ( V_255 [ 6 ] & V_359 ) {
V_354 = 16 ;
V_252 -> V_357 |= V_359 ;
F_7 ( L_37 ,
V_42 -> V_40 ) ;
}
if ( V_354 == 0 ) {
F_7 ( L_38 ,
V_42 -> V_40 ) ;
return;
}
F_7 ( L_39 ,
V_42 -> V_40 , V_354 ) ;
V_252 -> V_355 = V_354 ;
V_252 -> V_257 = V_360 ;
if ( V_255 [ 6 ] & V_361 ) {
V_252 -> V_257 |= V_362 ;
F_7 ( L_40 ,
V_42 -> V_40 ) ;
}
if ( ! ( V_255 [ 6 ] & V_358 ) ) {
F_7 ( L_41 ,
V_42 -> V_40 ) ;
}
}
static void
F_164 ( struct V_41 * V_42 , const T_1 * V_260 )
{
struct V_251 * V_252 = & V_42 -> V_253 ;
T_1 V_24 = F_131 ( V_260 ) ;
if ( V_24 >= 6 )
V_252 -> V_363 = V_260 [ 6 ] & 1 ;
if ( V_24 >= 7 )
V_252 -> V_350 = V_260 [ 7 ] * 5000 ;
F_14 ( L_42
L_43 ,
V_252 -> V_363 ,
V_252 -> V_350 ) ;
F_163 ( V_42 , V_260 ) ;
}
static void F_165 ( struct V_41 * V_42 ,
struct V_12 * V_12 )
{
struct V_251 * V_252 = & V_42 -> V_253 ;
const T_1 * V_228 ;
int V_2 , V_27 , V_285 ;
V_228 = F_96 ( V_12 ) ;
if ( ! V_228 )
return;
V_252 -> V_364 = V_228 [ 1 ] ;
V_252 -> V_257 = V_360 ;
if ( V_228 [ 3 ] & V_365 )
V_252 -> V_257 |= V_362 ;
if ( V_228 [ 3 ] & V_366 )
V_252 -> V_257 |= V_367 ;
if ( F_135 ( V_228 , & V_27 , & V_285 ) )
return;
F_143 (edid_ext, i, start, end) {
const T_1 * V_260 = & V_228 [ V_2 ] ;
if ( F_136 ( V_260 ) )
F_164 ( V_42 , V_260 ) ;
if ( F_137 ( V_260 ) )
F_162 ( V_42 , V_260 ) ;
if ( F_138 ( V_260 ) )
F_140 ( V_42 , V_260 ) ;
}
}
static void F_166 ( struct V_41 * V_42 ,
struct V_12 * V_12 )
{
struct V_251 * V_252 = & V_42 -> V_253 ;
V_252 -> V_173 = V_12 -> V_180 * 10 ;
V_252 -> V_176 = V_12 -> V_181 * 10 ;
V_252 -> V_355 = 0 ;
V_252 -> V_257 = 0 ;
V_252 -> V_364 = 0 ;
V_252 -> V_350 = 0 ;
V_252 -> V_363 = false ;
if ( V_12 -> V_17 < 3 )
return;
if ( ! ( V_12 -> V_109 & V_110 ) )
return;
F_165 ( V_42 , V_12 ) ;
if ( ( V_252 -> V_355 == 0 ) && ( V_12 -> V_17 < 4 ) &&
( V_12 -> V_109 & V_368 ) ) {
V_252 -> V_355 = 8 ;
F_7 ( L_44 ,
V_42 -> V_40 , V_252 -> V_355 ) ;
}
if ( V_12 -> V_17 < 4 )
return;
switch ( V_12 -> V_109 & V_369 ) {
case V_370 :
V_252 -> V_355 = 6 ;
break;
case V_371 :
V_252 -> V_355 = 8 ;
break;
case V_372 :
V_252 -> V_355 = 10 ;
break;
case V_373 :
V_252 -> V_355 = 12 ;
break;
case V_374 :
V_252 -> V_355 = 14 ;
break;
case V_375 :
V_252 -> V_355 = 16 ;
break;
case V_376 :
default:
V_252 -> V_355 = 0 ;
break;
}
F_7 ( L_45 ,
V_42 -> V_40 , V_252 -> V_355 ) ;
V_252 -> V_257 |= V_360 ;
if ( V_12 -> V_111 & V_377 )
V_252 -> V_257 |= V_362 ;
if ( V_12 -> V_111 & V_378 )
V_252 -> V_257 |= V_367 ;
}
static int F_167 ( T_1 * V_379 , int V_8 , int V_380 )
{
int V_2 ;
T_1 V_5 = 0 ;
struct V_381 * V_57 ;
V_57 = (struct V_381 * ) & V_379 [ V_380 ] ;
F_14 ( L_46 ,
V_57 -> V_382 , V_57 -> V_383 , V_57 -> V_384 , V_57 -> V_385 ) ;
if ( V_57 -> V_383 + 5 > V_8 - V_380 )
return - V_386 ;
for ( V_2 = V_380 ; V_2 <= V_57 -> V_383 + 5 ; V_2 ++ ) {
V_5 += V_379 [ V_2 ] ;
}
if ( V_5 ) {
F_8 ( L_47 , V_5 ) ;
return - V_386 ;
}
return 0 ;
}
static struct V_70 * F_168 ( struct V_90 * V_47 ,
struct V_387 * V_213 )
{
struct V_70 * V_83 ;
unsigned V_165 = ( V_213 -> V_165 [ 0 ] |
( V_213 -> V_165 [ 1 ] << 8 ) |
( V_213 -> V_165 [ 2 ] << 16 ) ) ;
unsigned V_142 = ( V_213 -> V_142 [ 0 ] | V_213 -> V_142 [ 1 ] << 8 ) + 1 ;
unsigned V_148 = ( V_213 -> V_148 [ 0 ] | V_213 -> V_148 [ 1 ] << 8 ) + 1 ;
unsigned V_183 = ( V_213 -> V_183 [ 0 ] | ( V_213 -> V_183 [ 1 ] & 0x7f ) << 8 ) + 1 ;
unsigned V_388 = ( V_213 -> V_389 [ 0 ] | V_213 -> V_389 [ 1 ] << 8 ) + 1 ;
unsigned V_145 = ( V_213 -> V_145 [ 0 ] | V_213 -> V_145 [ 1 ] << 8 ) + 1 ;
unsigned V_150 = ( V_213 -> V_150 [ 0 ] | V_213 -> V_150 [ 1 ] << 8 ) + 1 ;
unsigned V_186 = ( V_213 -> V_186 [ 0 ] | ( V_213 -> V_186 [ 1 ] & 0x7f ) << 8 ) + 1 ;
unsigned V_390 = ( V_213 -> V_391 [ 0 ] | V_213 -> V_391 [ 1 ] << 8 ) + 1 ;
bool V_392 = ( V_213 -> V_183 [ 1 ] >> 7 ) & 0x1 ;
bool V_393 = ( V_213 -> V_186 [ 1 ] >> 7 ) & 0x1 ;
V_83 = F_67 ( V_47 ) ;
if ( ! V_83 )
return NULL ;
V_83 -> clock = V_165 * 10 ;
V_83 -> V_85 = V_142 ;
V_83 -> V_87 = V_83 -> V_85 + V_183 ;
V_83 -> V_86 = V_83 -> V_87 + V_388 ;
V_83 -> V_84 = V_83 -> V_85 + V_148 ;
V_83 -> V_89 = V_145 ;
V_83 -> V_88 = V_83 -> V_89 + V_186 ;
V_83 -> V_137 = V_83 -> V_88 + V_390 ;
V_83 -> V_138 = V_83 -> V_89 + V_150 ;
V_83 -> V_36 = 0 ;
V_83 -> V_36 |= V_392 ? V_169 : V_170 ;
V_83 -> V_36 |= V_393 ? V_171 : V_172 ;
V_83 -> type = V_182 ;
if ( V_213 -> V_36 & 0x80 )
V_83 -> type |= V_81 ;
V_83 -> V_82 = F_39 ( V_83 ) ;
F_70 ( V_83 ) ;
return V_83 ;
}
static int F_169 ( struct V_41 * V_42 ,
struct V_394 * V_9 )
{
struct V_395 * V_396 = (struct V_395 * ) V_9 ;
int V_2 ;
int V_397 ;
struct V_70 * V_192 ;
int V_398 = 0 ;
if ( V_9 -> V_399 % 20 )
return 0 ;
V_397 = V_9 -> V_399 / 20 ;
for ( V_2 = 0 ; V_2 < V_397 ; V_2 ++ ) {
struct V_387 * V_213 = & V_396 -> V_213 [ V_2 ] ;
V_192 = F_168 ( V_42 -> V_47 , V_213 ) ;
if ( ! V_192 )
continue;
F_77 ( V_42 , V_192 ) ;
V_398 ++ ;
}
return V_398 ;
}
static int F_170 ( struct V_41 * V_42 ,
struct V_12 * V_12 )
{
T_1 * V_379 ;
int V_30 ;
int V_380 = 1 ;
int V_8 = V_6 ;
struct V_394 * V_9 ;
int V_398 = 0 ;
V_379 = F_97 ( V_12 ) ;
if ( ! V_379 )
return 0 ;
V_30 = F_167 ( V_379 , V_8 , V_380 ) ;
if ( V_30 )
return 0 ;
V_380 += sizeof( struct V_381 ) ;
while ( V_9 = (struct V_394 * ) & V_379 [ V_380 ] ,
V_380 + sizeof( struct V_394 ) <= V_8 &&
V_380 + sizeof( struct V_394 ) + V_9 -> V_399 <= V_8 &&
V_9 -> V_399 > 0 ) {
V_380 += V_9 -> V_399 + sizeof( struct V_394 ) ;
switch ( V_9 -> V_400 ) {
case V_401 :
V_398 += F_169 ( V_42 , V_9 ) ;
break;
}
}
return V_398 ;
}
int F_171 ( struct V_41 * V_42 , struct V_12 * V_12 )
{
int V_398 = 0 ;
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
F_166 ( V_42 , V_12 ) ;
V_398 += F_94 ( V_42 , V_12 , V_69 ) ;
V_398 += F_91 ( V_42 , V_12 ) ;
V_398 += F_88 ( V_42 , V_12 ) ;
V_398 += F_86 ( V_42 , V_12 ) ;
V_398 += F_142 ( V_42 , V_12 ) ;
V_398 += F_113 ( V_42 , V_12 ) ;
V_398 += F_170 ( V_42 , V_12 ) ;
if ( V_12 -> V_111 & V_112 )
V_398 += F_83 ( V_42 , V_12 ) ;
if ( V_69 & ( V_78 | V_79 ) )
F_34 ( V_42 , V_69 ) ;
if ( V_69 & V_402 )
V_42 -> V_253 . V_355 = 6 ;
if ( V_69 & V_403 )
V_42 -> V_253 . V_355 = 8 ;
if ( V_69 & V_404 )
V_42 -> V_253 . V_355 = 10 ;
if ( V_69 & V_405 )
V_42 -> V_253 . V_355 = 12 ;
return V_398 ;
}
int F_172 ( struct V_41 * V_42 ,
int V_85 , int V_89 )
{
int V_2 , V_296 , V_398 = 0 ;
struct V_70 * V_83 ;
struct V_90 * V_47 = V_42 -> V_47 ;
V_296 = F_32 ( V_95 ) ;
if ( V_85 < 0 )
V_85 = 0 ;
if ( V_89 < 0 )
V_89 = 0 ;
for ( V_2 = 0 ; V_2 < V_296 ; V_2 ++ ) {
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
V_398 ++ ;
}
}
return V_398 ;
}
void F_173 ( struct V_41 * V_42 ,
int V_406 , int V_407 )
{
struct V_70 * V_83 ;
F_59 (mode, &connector->probed_modes, head) {
if ( V_83 -> V_85 == V_406 &&
V_83 -> V_89 == V_407 )
V_83 -> type |= V_81 ;
}
}
int
F_174 ( struct V_408 * V_409 ,
const struct V_70 * V_83 ,
bool V_410 )
{
int V_411 ;
if ( ! V_409 || ! V_83 )
return - V_386 ;
V_411 = F_175 ( V_409 ) ;
if ( V_411 < 0 )
return V_411 ;
if ( V_83 -> V_36 & V_412 )
V_409 -> V_413 = 1 ;
V_409 -> V_238 = F_104 ( V_83 ) ;
if ( ! V_410 && V_409 -> V_238 > 64 )
V_409 -> V_238 = 0 ;
if ( V_409 -> V_238 ) {
T_1 V_414 = F_111 ( V_83 ) ;
bool V_415 = V_83 -> V_36 & V_244 ;
if ( F_112 ( V_414 ) && ! V_415 )
V_409 -> V_238 = 0 ;
}
V_409 -> V_416 = V_417 ;
if ( V_83 -> V_239 == V_418 ||
V_83 -> V_239 == V_419 )
V_409 -> V_416 = V_83 -> V_239 ;
else if ( V_409 -> V_238 > 0 )
V_409 -> V_416 = F_107 (
V_409 -> V_238 ) ;
V_409 -> V_420 = V_421 ;
V_409 -> V_422 = V_423 ;
return 0 ;
}
void
F_176 ( struct V_408 * V_409 ,
const struct V_70 * V_83 ,
enum V_339 V_424 ,
bool V_425 )
{
if ( V_425 ||
V_424 == F_160 ( V_83 ) )
V_409 -> V_426 = V_424 ;
else
V_409 -> V_426 = V_427 ;
if ( V_424 == V_340 )
V_409 -> V_428 =
V_429 ;
else
V_409 -> V_428 =
V_430 ;
}
static enum V_431
F_177 ( const struct V_70 * V_83 )
{
T_3 V_432 = V_83 -> V_36 & V_244 ;
switch ( V_432 ) {
case V_271 :
return V_433 ;
case V_434 :
return V_435 ;
case V_436 :
return V_437 ;
case V_438 :
return V_439 ;
case V_440 :
return V_441 ;
case V_442 :
return V_443 ;
case V_272 :
return V_444 ;
case V_273 :
return V_445 ;
default:
return V_446 ;
}
}
int
F_178 ( struct V_447 * V_409 ,
const struct V_70 * V_83 )
{
int V_411 ;
T_3 V_448 ;
T_1 V_231 ;
if ( ! V_409 || ! V_83 )
return - V_386 ;
V_231 = F_111 ( V_83 ) ;
V_448 = V_83 -> V_36 & V_244 ;
if ( ! V_231 && ! V_448 )
return - V_386 ;
if ( V_231 && V_448 )
return - V_386 ;
V_411 = F_179 ( V_409 ) ;
if ( V_411 < 0 )
return V_411 ;
if ( V_231 )
V_409 -> V_231 = V_231 ;
else
V_409 -> V_449 = F_177 ( V_83 ) ;
return 0 ;
}
static int F_180 ( struct V_41 * V_42 ,
struct V_394 * V_9 )
{
struct V_450 * V_451 = (struct V_450 * ) V_9 ;
T_5 V_132 , V_133 ;
T_1 V_452 , V_453 ;
T_1 V_454 , V_455 ;
struct V_456 * V_457 ;
V_132 = V_451 -> V_458 [ 0 ] | V_451 -> V_458 [ 1 ] << 8 ;
V_133 = V_451 -> V_458 [ 2 ] | V_451 -> V_458 [ 3 ] << 8 ;
V_454 = ( V_451 -> V_459 [ 0 ] & 0xf ) | ( V_451 -> V_459 [ 2 ] & 0x30 ) ;
V_455 = ( V_451 -> V_459 [ 0 ] >> 4 ) | ( ( V_451 -> V_459 [ 2 ] >> 2 ) & 0x30 ) ;
V_452 = ( V_451 -> V_459 [ 1 ] & 0xf ) | ( ( V_451 -> V_459 [ 2 ] & 0x3 ) << 4 ) ;
V_453 = ( V_451 -> V_459 [ 1 ] >> 4 ) | ( ( ( V_451 -> V_459 [ 2 ] >> 2 ) & 0x3 ) << 4 ) ;
V_42 -> V_460 = true ;
if ( V_451 -> V_461 & 0x80 )
V_42 -> V_462 = true ;
V_42 -> V_455 = V_455 + 1 ;
V_42 -> V_454 = V_454 + 1 ;
V_42 -> V_453 = V_453 ;
V_42 -> V_452 = V_452 ;
V_42 -> V_463 = V_132 + 1 ;
V_42 -> V_464 = V_133 + 1 ;
F_14 ( L_49 , V_451 -> V_461 ) ;
F_14 ( L_50 , V_132 + 1 , V_133 + 1 ) ;
F_14 ( L_51 ,
V_455 + 1 , V_454 + 1 , V_453 , V_452 ) ;
F_14 ( L_52 , V_451 -> V_465 [ 0 ] , V_451 -> V_465 [ 1 ] , V_451 -> V_465 [ 2 ] ) ;
V_457 = F_181 ( V_42 -> V_47 , V_451 -> V_465 ) ;
if ( ! V_457 ) {
V_457 = F_182 ( V_42 -> V_47 , V_451 -> V_465 ) ;
}
if ( ! V_457 )
return - V_325 ;
if ( V_42 -> V_466 != V_457 ) {
if ( V_42 -> V_466 ) {
F_183 ( V_42 -> V_47 , V_42 -> V_466 ) ;
}
V_42 -> V_466 = V_457 ;
} else
F_183 ( V_42 -> V_47 , V_457 ) ;
return 0 ;
}
static int F_184 ( struct V_41 * V_42 ,
T_1 * V_379 , int V_8 ,
bool V_467 )
{
int V_380 = 0 ;
struct V_394 * V_9 ;
int V_30 ;
if ( V_467 )
V_380 = 1 ;
V_30 = F_167 ( V_379 , V_8 , V_380 ) ;
if ( V_30 )
return V_30 ;
V_380 += sizeof( struct V_381 ) ;
while ( V_9 = (struct V_394 * ) & V_379 [ V_380 ] ,
V_380 + sizeof( struct V_394 ) <= V_8 &&
V_380 + sizeof( struct V_394 ) + V_9 -> V_399 <= V_8 &&
V_9 -> V_399 > 0 ) {
V_380 += V_9 -> V_399 + sizeof( struct V_394 ) ;
F_14 ( L_53 ,
V_9 -> V_400 , V_9 -> V_382 , V_9 -> V_399 ) ;
switch ( V_9 -> V_400 ) {
case V_468 :
V_30 = F_180 ( V_42 , V_9 ) ;
if ( V_30 )
return V_30 ;
break;
case V_401 :
break;
default:
F_14 ( L_54 , V_9 -> V_400 ) ;
break;
}
}
return 0 ;
}
static void F_24 ( struct V_41 * V_42 ,
struct V_12 * V_12 )
{
void * V_379 = NULL ;
int V_30 ;
V_42 -> V_460 = false ;
V_379 = F_97 ( V_12 ) ;
if ( ! V_379 ) {
goto V_469;
}
V_30 = F_184 ( V_42 , V_379 , V_6 , true ) ;
if ( V_30 < 0 )
goto V_469;
if ( ! V_42 -> V_460 )
goto V_469;
return;
V_469:
if ( V_42 -> V_466 ) {
F_183 ( V_42 -> V_47 , V_42 -> V_466 ) ;
V_42 -> V_466 = NULL ;
}
return;
}
