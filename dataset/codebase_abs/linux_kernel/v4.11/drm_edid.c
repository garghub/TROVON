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
static void F_15 ( struct V_40 * V_41 ,
T_1 * V_12 , int V_42 )
{
int V_2 ;
if ( V_41 -> V_43 ++ && ! ( V_44 & V_45 ) )
return;
F_16 ( V_41 -> V_46 -> V_46 ,
L_9 ,
V_41 -> V_39 ) ;
for ( V_2 = 0 ; V_2 < V_42 ; V_2 ++ ) {
T_1 * V_9 = V_12 + V_2 * V_6 ;
char V_47 [ 20 ] ;
if ( F_3 ( V_9 , V_6 ) )
sprintf ( V_47 , L_10 , V_2 ) ;
else if ( ! F_5 ( V_9 , V_2 , false , NULL ) )
sprintf ( V_47 , L_11 , V_2 ) ;
else
sprintf ( V_47 , L_12 , V_2 ) ;
F_10 ( V_48 ,
V_47 , V_18 , 16 , 1 ,
V_9 , V_6 , false ) ;
}
}
struct V_12 * F_17 ( struct V_40 * V_41 ,
int (* F_18)( void * V_21 , T_1 * V_22 , unsigned int V_9 ,
T_2 V_23 ) ,
void * V_21 )
{
int V_2 , V_49 = 0 , V_50 = 0 ;
T_1 * V_12 , * V_51 ;
if ( ( V_12 = F_19 ( V_6 , V_52 ) ) == NULL )
return NULL ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_18 ( V_21 , V_12 , 0 , V_6 ) )
goto V_53;
if ( F_5 ( V_12 , 0 , false ,
& V_41 -> V_11 ) )
break;
if ( V_2 == 0 && F_3 ( V_12 , V_6 ) ) {
V_41 -> V_54 ++ ;
goto V_55;
}
}
if ( V_2 == 4 )
goto V_55;
V_50 = V_12 [ 0x7e ] ;
if ( V_50 == 0 )
return (struct V_12 * ) V_12 ;
V_51 = F_20 ( V_12 , ( V_50 + 1 ) * V_6 , V_52 ) ;
if ( ! V_51 )
goto V_53;
V_12 = V_51 ;
for ( V_49 = 1 ; V_49 <= V_12 [ 0x7e ] ; V_49 ++ ) {
T_1 * V_9 = V_12 + V_49 * V_6 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_18 ( V_21 , V_9 , V_49 , V_6 ) )
goto V_53;
if ( F_5 ( V_9 , V_49 , false , NULL ) )
break;
}
if ( V_2 == 4 )
V_50 -- ;
}
if ( V_50 != V_12 [ 0x7e ] ) {
T_1 * V_56 ;
F_15 ( V_41 , V_12 , V_12 [ 0x7e ] + 1 ) ;
V_12 [ V_6 - 1 ] += V_12 [ 0x7e ] - V_50 ;
V_12 [ 0x7e ] = V_50 ;
V_51 = F_19 ( ( V_50 + 1 ) * V_6 , V_52 ) ;
if ( ! V_51 )
goto V_53;
V_56 = V_51 ;
for ( V_2 = 0 ; V_2 <= V_12 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_9 = V_12 + V_2 * V_6 ;
if ( ! F_5 ( V_9 , V_2 , false , NULL ) )
continue;
memcpy ( V_56 , V_9 , V_6 ) ;
V_56 += V_6 ;
}
F_21 ( V_12 ) ;
V_12 = V_51 ;
}
return (struct V_12 * ) V_12 ;
V_55:
F_15 ( V_41 , V_12 , 1 ) ;
V_53:
F_21 ( V_12 ) ;
return NULL ;
}
bool
F_22 ( struct V_24 * V_25 )
{
unsigned char V_53 ;
return ( F_12 ( V_25 , & V_53 , 0 , 1 ) == 0 ) ;
}
struct V_12 * F_23 ( struct V_40 * V_41 ,
struct V_24 * V_25 )
{
struct V_12 * V_12 ;
if ( ! F_22 ( V_25 ) )
return NULL ;
V_12 = F_17 ( V_41 , F_12 , V_25 ) ;
if ( V_12 )
F_24 ( V_41 , V_12 ) ;
return V_12 ;
}
struct V_12 * F_25 ( struct V_40 * V_41 ,
struct V_24 * V_25 )
{
struct V_57 * V_58 = V_41 -> V_46 -> V_58 ;
struct V_12 * V_12 ;
F_26 ( V_58 ) ;
V_12 = F_23 ( V_41 , V_25 ) ;
F_27 ( V_58 ) ;
return V_12 ;
}
struct V_12 * F_28 ( const struct V_12 * V_12 )
{
return F_29 ( V_12 , ( V_12 -> V_20 + 1 ) * V_6 , V_52 ) ;
}
static bool F_30 ( struct V_12 * V_12 , const char * V_59 )
{
char F_30 [ 3 ] ;
F_30 [ 0 ] = ( ( V_12 -> V_60 [ 0 ] & 0x7c ) >> 2 ) + '@' ;
F_30 [ 1 ] = ( ( ( V_12 -> V_60 [ 0 ] & 0x3 ) << 3 ) |
( ( V_12 -> V_60 [ 1 ] & 0xe0 ) >> 5 ) ) + '@' ;
F_30 [ 2 ] = ( V_12 -> V_60 [ 1 ] & 0x1f ) + '@' ;
return ! strncmp ( F_30 , V_59 , 3 ) ;
}
static T_3 F_31 ( struct V_12 * V_12 )
{
const struct V_61 * V_62 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_32 ( V_63 ) ; V_2 ++ ) {
V_62 = & V_63 [ V_2 ] ;
if ( F_30 ( V_12 , V_62 -> V_59 ) &&
( F_33 ( V_12 ) == V_62 -> V_64 ) )
return V_62 -> V_65 ;
}
return 0 ;
}
static void F_34 ( struct V_40 * V_41 ,
T_3 V_65 )
{
struct V_66 * V_67 , * V_68 , * V_69 ;
int V_70 = 0 ;
int V_71 , V_72 ;
if ( F_35 ( & V_41 -> V_73 ) )
return;
if ( V_65 & V_74 )
V_70 = 60 ;
if ( V_65 & V_75 )
V_70 = 75 ;
V_69 = F_36 ( & V_41 -> V_73 ,
struct V_66 , V_76 ) ;
F_37 (cur_mode, t, &connector->probed_modes, head) {
V_68 -> type &= ~ V_77 ;
if ( V_68 == V_69 )
continue;
if ( F_38 ( V_68 ) > F_38 ( V_69 ) )
V_69 = V_68 ;
V_71 = V_68 -> V_78 ?
V_68 -> V_78 : F_39 ( V_68 ) ;
V_72 = V_69 -> V_78 ?
V_69 -> V_78 : F_39 ( V_69 ) ;
if ( ( F_38 ( V_68 ) == F_38 ( V_69 ) ) &&
F_40 ( V_71 , V_70 ) <
F_40 ( V_72 , V_70 ) ) {
V_69 = V_68 ;
}
}
V_69 -> type |= V_77 ;
}
static bool
F_41 ( const struct V_66 * V_79 )
{
return ( V_79 -> V_80 - V_79 -> V_81 == 160 ) &&
( V_79 -> V_82 - V_79 -> V_81 == 80 ) &&
( V_79 -> V_82 - V_79 -> V_83 == 32 ) &&
( V_79 -> V_84 - V_79 -> V_85 == 3 ) ;
}
struct V_66 * F_42 ( struct V_86 * V_46 ,
int V_87 , int V_88 , int V_89 ,
bool V_90 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_32 ( V_91 ) ; V_2 ++ ) {
const struct V_66 * V_92 = & V_91 [ V_2 ] ;
if ( V_87 != V_92 -> V_81 )
continue;
if ( V_88 != V_92 -> V_85 )
continue;
if ( V_89 != F_39 ( V_92 ) )
continue;
if ( V_90 != F_41 ( V_92 ) )
continue;
return F_43 ( V_46 , V_92 ) ;
}
return NULL ;
}
static void
F_44 ( T_1 * V_93 , T_4 * V_94 , void * V_95 )
{
int V_2 , V_96 = 0 ;
T_1 V_97 = V_93 [ 0x02 ] ;
T_1 * V_98 = V_93 + V_97 ;
V_96 = ( 127 - V_97 ) / 18 ;
for ( V_2 = 0 ; V_2 < V_96 ; V_2 ++ )
V_94 ( (struct V_99 * ) ( V_98 + 18 * V_2 ) , V_95 ) ;
}
static void
F_45 ( T_1 * V_93 , T_4 * V_94 , void * V_95 )
{
unsigned int V_2 , V_96 = F_46 ( ( int ) V_93 [ 0x02 ] , 6 ) ;
T_1 * V_98 = V_93 + 5 ;
if ( V_93 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_96 ; V_2 ++ )
V_94 ( (struct V_99 * ) ( V_98 + 18 * V_2 ) , V_95 ) ;
}
static void
F_47 ( T_1 * V_1 , T_4 * V_94 , void * V_95 )
{
int V_2 ;
struct V_12 * V_12 = (struct V_12 * ) V_1 ;
if ( V_12 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_100 ; V_2 ++ )
V_94 ( & ( V_12 -> V_101 [ V_2 ] ) , V_95 ) ;
for ( V_2 = 1 ; V_2 <= V_1 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_93 = V_1 + ( V_2 * V_6 ) ;
switch ( * V_93 ) {
case V_102 :
F_44 ( V_93 , V_94 , V_95 ) ;
break;
case V_103 :
F_45 ( V_93 , V_94 , V_95 ) ;
break;
default:
break;
}
}
}
static void
F_48 ( struct V_99 * V_67 , void * V_21 )
{
T_1 * V_104 = ( T_1 * ) V_67 ;
if ( V_104 [ 3 ] == V_105 )
if ( V_104 [ 15 ] & 0x10 )
* ( bool * ) V_21 = true ;
}
static bool
F_49 ( struct V_12 * V_12 )
{
if ( V_12 -> V_16 >= 4 ) {
bool V_29 = false ;
F_47 ( ( T_1 * ) V_12 , F_48 , & V_29 ) ;
return V_29 ;
}
return ( ( V_12 -> V_106 & V_107 ) != 0 ) ;
}
static void
F_50 ( struct V_99 * V_67 , void * V_21 )
{
T_1 * V_104 = ( T_1 * ) V_67 ;
if ( V_104 [ 3 ] == V_105 && V_104 [ 10 ] == 0x02 )
* ( T_1 * * ) V_21 = V_104 ;
}
static int
F_51 ( struct V_12 * V_12 )
{
T_1 * V_104 = NULL ;
F_47 ( ( T_1 * ) V_12 , F_50 , & V_104 ) ;
return V_104 ? ( V_104 [ 12 ] * 2 ) : 0 ;
}
static int
F_52 ( struct V_12 * V_12 )
{
T_1 * V_104 = NULL ;
F_47 ( ( T_1 * ) V_12 , F_50 , & V_104 ) ;
return V_104 ? V_104 [ 13 ] : 0 ;
}
static int
F_53 ( struct V_12 * V_12 )
{
T_1 * V_104 = NULL ;
F_47 ( ( T_1 * ) V_12 , F_50 , & V_104 ) ;
return V_104 ? ( V_104 [ 15 ] << 8 ) + V_104 [ 14 ] : 0 ;
}
static int
F_54 ( struct V_12 * V_12 )
{
T_1 * V_104 = NULL ;
F_47 ( ( T_1 * ) V_12 , F_50 , & V_104 ) ;
return V_104 ? V_104 [ 16 ] : 0 ;
}
static int
F_55 ( struct V_12 * V_12 )
{
T_1 * V_104 = NULL ;
F_47 ( ( T_1 * ) V_12 , F_50 , & V_104 ) ;
return V_104 ? V_104 [ 17 ] : 0 ;
}
static int F_56 ( struct V_12 * V_12 )
{
if ( V_12 -> V_16 >= 2 ) {
if ( V_12 -> V_16 >= 4 && ( V_12 -> V_108 & V_109 ) )
return V_110 ;
if ( F_51 ( V_12 ) )
return V_111 ;
return V_112 ;
}
return V_113 ;
}
static int
F_57 ( T_1 V_114 , T_1 V_115 )
{
return ( V_114 == 0x00 && V_115 == 0x00 ) ||
( V_114 == 0x01 && V_115 == 0x01 ) ||
( V_114 == 0x20 && V_115 == 0x20 ) ;
}
static struct V_66 *
F_58 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_116 * V_67 )
{
struct V_86 * V_46 = V_41 -> V_46 ;
struct V_66 * V_117 , * V_79 = NULL ;
int V_87 , V_88 ;
int V_118 ;
unsigned V_119 = ( V_67 -> V_120 & V_121 )
>> V_122 ;
unsigned V_123 = ( V_67 -> V_120 & V_124 )
>> V_125 ;
int V_126 = F_56 ( V_12 ) ;
if ( F_57 ( V_67 -> V_87 , V_67 -> V_120 ) )
return NULL ;
V_87 = V_67 -> V_87 * 8 + 248 ;
V_118 = V_123 + 60 ;
if ( V_119 == 0 ) {
if ( V_12 -> V_16 < 3 )
V_88 = V_87 ;
else
V_88 = ( V_87 * 10 ) / 16 ;
} else if ( V_119 == 1 )
V_88 = ( V_87 * 3 ) / 4 ;
else if ( V_119 == 2 )
V_88 = ( V_87 * 4 ) / 5 ;
else
V_88 = ( V_87 * 9 ) / 16 ;
if ( V_118 == 60 &&
( ( V_87 == 1360 && V_88 == 765 ) ||
( V_87 == 1368 && V_88 == 769 ) ) ) {
V_87 = 1366 ;
V_88 = 768 ;
}
F_59 (m, &connector->probed_modes, head)
if ( V_117 -> V_81 == V_87 && V_117 -> V_85 == V_88 &&
F_39 ( V_117 ) == V_118 )
return NULL ;
if ( V_87 == 1366 && V_88 == 768 && V_118 == 60 ) {
V_79 = F_60 ( V_46 , 1366 , 768 , V_118 , 0 , 0 ,
false ) ;
V_79 -> V_81 = 1366 ;
V_79 -> V_83 = V_79 -> V_83 - 1 ;
V_79 -> V_82 = V_79 -> V_82 - 1 ;
return V_79 ;
}
if ( F_49 ( V_12 ) ) {
V_79 = F_42 ( V_46 , V_87 , V_88 , V_118 ,
true ) ;
if ( V_79 )
return V_79 ;
}
V_79 = F_42 ( V_46 , V_87 , V_88 , V_118 , false ) ;
if ( V_79 )
return V_79 ;
switch ( V_126 ) {
case V_113 :
break;
case V_112 :
V_79 = F_61 ( V_46 , V_87 , V_88 , V_118 , 0 , 0 ) ;
break;
case V_111 :
V_79 = F_61 ( V_46 , V_87 , V_88 , V_118 , 0 , 0 ) ;
if ( ! V_79 )
return NULL ;
if ( F_62 ( V_79 ) > F_51 ( V_12 ) ) {
F_63 ( V_46 , V_79 ) ;
V_79 = F_64 ( V_46 , V_87 , V_88 ,
V_118 , 0 , 0 ,
F_53 ( V_12 ) ,
F_52 ( V_12 ) ,
F_54 ( V_12 ) ,
F_55 ( V_12 ) ) ;
}
break;
case V_110 :
V_79 = F_60 ( V_46 , V_87 , V_88 , V_118 , 0 , 0 ,
false ) ;
break;
}
return V_79 ;
}
static void
F_65 ( struct V_66 * V_79 ,
struct V_127 * V_128 )
{
int V_2 ;
static const struct {
int V_129 , V_130 ;
} V_131 [] = {
{ 1920 , 1080 } ,
{ 720 , 480 } ,
{ 1440 , 480 } ,
{ 2880 , 480 } ,
{ 720 , 576 } ,
{ 1440 , 576 } ,
{ 2880 , 576 } ,
} ;
if ( ! ( V_128 -> V_132 & V_133 ) )
return;
for ( V_2 = 0 ; V_2 < F_32 ( V_131 ) ; V_2 ++ ) {
if ( ( V_79 -> V_81 == V_131 [ V_2 ] . V_129 ) &&
( V_79 -> V_85 == V_131 [ V_2 ] . V_130 / 2 ) ) {
V_79 -> V_85 *= 2 ;
V_79 -> V_84 *= 2 ;
V_79 -> V_134 *= 2 ;
V_79 -> V_135 *= 2 ;
V_79 -> V_135 |= 1 ;
}
}
V_79 -> V_35 |= V_136 ;
}
static struct V_66 * F_66 ( struct V_86 * V_46 ,
struct V_12 * V_12 ,
struct V_99 * V_137 ,
T_3 V_65 )
{
struct V_66 * V_79 ;
struct V_127 * V_128 = & V_137 -> V_21 . V_138 ;
unsigned V_139 = ( V_128 -> V_140 & 0xf0 ) << 4 | V_128 -> V_141 ;
unsigned V_142 = ( V_128 -> V_143 & 0xf0 ) << 4 | V_128 -> V_144 ;
unsigned V_145 = ( V_128 -> V_140 & 0xf ) << 8 | V_128 -> V_146 ;
unsigned V_147 = ( V_128 -> V_143 & 0xf ) << 8 | V_128 -> V_148 ;
unsigned V_149 = ( V_128 -> V_150 & 0xc0 ) << 2 | V_128 -> V_151 ;
unsigned V_152 = ( V_128 -> V_150 & 0x30 ) << 4 | V_128 -> V_153 ;
unsigned V_154 = ( V_128 -> V_150 & 0xc ) << 2 | V_128 -> V_155 >> 4 ;
unsigned V_156 = ( V_128 -> V_150 & 0x3 ) << 4 | ( V_128 -> V_155 & 0xf ) ;
if ( V_139 < 64 || V_142 < 64 )
return NULL ;
if ( V_128 -> V_132 & V_157 ) {
F_14 ( L_13 ) ;
return NULL ;
}
if ( ! ( V_128 -> V_132 & V_158 ) ) {
F_14 ( L_14 ) ;
}
if ( ! V_152 || ! V_156 ) {
F_14 ( L_15
L_16 ) ;
return NULL ;
}
if ( V_65 & V_159 ) {
V_79 = F_60 ( V_46 , V_139 , V_142 , 60 , true , false , false ) ;
if ( ! V_79 )
return NULL ;
goto V_160;
}
V_79 = F_67 ( V_46 ) ;
if ( ! V_79 )
return NULL ;
if ( V_65 & V_161 )
V_137 -> V_162 = F_68 ( 1088 ) ;
V_79 -> clock = F_69 ( V_137 -> V_162 ) * 10 ;
V_79 -> V_81 = V_139 ;
V_79 -> V_83 = V_79 -> V_81 + V_149 ;
V_79 -> V_82 = V_79 -> V_83 + V_152 ;
V_79 -> V_80 = V_79 -> V_81 + V_145 ;
V_79 -> V_85 = V_142 ;
V_79 -> V_84 = V_79 -> V_85 + V_154 ;
V_79 -> V_134 = V_79 -> V_84 + V_156 ;
V_79 -> V_135 = V_79 -> V_85 + V_147 ;
if ( V_79 -> V_82 > V_79 -> V_80 )
V_79 -> V_80 = V_79 -> V_82 + 1 ;
if ( V_79 -> V_134 > V_79 -> V_135 )
V_79 -> V_135 = V_79 -> V_134 + 1 ;
F_65 ( V_79 , V_128 ) ;
if ( V_65 & V_163 ) {
V_128 -> V_132 |= V_164 | V_165 ;
}
V_79 -> V_35 |= ( V_128 -> V_132 & V_164 ) ?
V_166 : V_167 ;
V_79 -> V_35 |= ( V_128 -> V_132 & V_165 ) ?
V_168 : V_169 ;
V_160:
V_79 -> V_170 = V_128 -> V_171 | ( V_128 -> V_172 & 0xf0 ) << 4 ;
V_79 -> V_173 = V_128 -> V_174 | ( V_128 -> V_172 & 0xf ) << 8 ;
if ( V_65 & V_175 ) {
V_79 -> V_170 *= 10 ;
V_79 -> V_173 *= 10 ;
}
if ( V_65 & V_176 ) {
V_79 -> V_170 = V_12 -> V_177 * 10 ;
V_79 -> V_173 = V_12 -> V_178 * 10 ;
}
V_79 -> type = V_179 ;
V_79 -> V_78 = F_39 ( V_79 ) ;
F_70 ( V_79 ) ;
return V_79 ;
}
static bool
F_71 ( const struct V_66 * V_79 ,
struct V_12 * V_12 , T_1 * V_67 )
{
int V_180 , V_181 , V_182 ;
V_181 = V_67 [ 7 ] ;
if ( V_12 -> V_16 >= 4 )
V_181 += ( ( V_67 [ 4 ] & 0x04 ) ? 255 : 0 ) ;
V_182 = V_67 [ 8 ] ;
if ( V_12 -> V_16 >= 4 )
V_182 += ( ( V_67 [ 4 ] & 0x08 ) ? 255 : 0 ) ;
V_180 = F_62 ( V_79 ) ;
return ( V_180 <= V_182 && V_180 >= V_181 ) ;
}
static bool
F_72 ( const struct V_66 * V_79 ,
struct V_12 * V_12 , T_1 * V_67 )
{
int V_183 , V_184 , V_185 ;
V_184 = V_67 [ 5 ] ;
if ( V_12 -> V_16 >= 4 )
V_184 += ( ( V_67 [ 4 ] & 0x01 ) ? 255 : 0 ) ;
V_185 = V_67 [ 6 ] ;
if ( V_12 -> V_16 >= 4 )
V_185 += ( ( V_67 [ 4 ] & 0x02 ) ? 255 : 0 ) ;
V_183 = F_39 ( V_79 ) ;
return ( V_183 <= V_185 && V_183 >= V_184 ) ;
}
static T_3
F_73 ( struct V_12 * V_12 , T_1 * V_67 )
{
if ( V_67 [ 9 ] == 0 || V_67 [ 9 ] == 255 )
return 0 ;
if ( V_12 -> V_16 >= 4 && V_67 [ 10 ] == 0x04 )
return ( V_67 [ 9 ] * 10000 ) - ( ( V_67 [ 12 ] >> 2 ) * 250 ) ;
return V_67 [ 9 ] * 10000 + 5001 ;
}
static bool
F_74 ( const struct V_66 * V_79 , struct V_12 * V_12 ,
struct V_99 * V_137 )
{
T_3 V_186 ;
T_1 * V_67 = ( T_1 * ) V_137 ;
if ( ! F_71 ( V_79 , V_12 , V_67 ) )
return false ;
if ( ! F_72 ( V_79 , V_12 , V_67 ) )
return false ;
if ( ( V_186 = F_73 ( V_12 , V_67 ) ) )
if ( V_79 -> clock > V_186 )
return false ;
if ( V_12 -> V_16 >= 4 && V_67 [ 10 ] == 0x04 )
if ( V_67 [ 13 ] && V_79 -> V_81 > 8 * ( V_67 [ 13 ] + ( 256 * ( V_67 [ 12 ] & 0x3 ) ) ) )
return false ;
if ( F_41 ( V_79 ) && ! F_49 ( V_12 ) )
return false ;
return true ;
}
static bool F_75 ( const struct V_40 * V_41 ,
const struct V_66 * V_79 )
{
const struct V_66 * V_117 ;
bool V_187 = false ;
F_59 (m, &connector->probed_modes, head) {
if ( V_79 -> V_81 == V_117 -> V_81 &&
V_79 -> V_85 == V_117 -> V_85 &&
F_39 ( V_79 ) == F_39 ( V_117 ) )
return false ;
if ( V_79 -> V_81 <= V_117 -> V_81 &&
V_79 -> V_85 <= V_117 -> V_85 )
V_187 = true ;
}
return V_187 ;
}
static int
F_76 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_99 * V_137 )
{
int V_2 , V_188 = 0 ;
struct V_66 * V_189 ;
struct V_86 * V_46 = V_41 -> V_46 ;
for ( V_2 = 0 ; V_2 < F_32 ( V_91 ) ; V_2 ++ ) {
if ( F_74 ( V_91 + V_2 , V_12 , V_137 ) &&
F_75 ( V_41 , V_91 + V_2 ) ) {
V_189 = F_43 ( V_46 , & V_91 [ V_2 ] ) ;
if ( V_189 ) {
F_77 ( V_41 , V_189 ) ;
V_188 ++ ;
}
}
}
return V_188 ;
}
void F_78 ( struct V_66 * V_79 )
{
if ( V_79 -> V_81 == 1368 && V_79 -> V_85 == 768 ) {
V_79 -> V_81 = 1366 ;
V_79 -> V_83 -- ;
V_79 -> V_82 -- ;
F_70 ( V_79 ) ;
}
}
static int
F_79 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_99 * V_137 )
{
int V_2 , V_188 = 0 ;
struct V_66 * V_189 ;
struct V_86 * V_46 = V_41 -> V_46 ;
for ( V_2 = 0 ; V_2 < F_32 ( V_190 ) ; V_2 ++ ) {
const struct V_191 * V_117 = & V_190 [ V_2 ] ;
V_189 = F_61 ( V_46 , V_117 -> V_129 , V_117 -> V_130 , V_117 -> V_104 , 0 , 0 ) ;
if ( ! V_189 )
return V_188 ;
F_78 ( V_189 ) ;
if ( ! F_74 ( V_189 , V_12 , V_137 ) ||
! F_75 ( V_41 , V_189 ) ) {
F_63 ( V_46 , V_189 ) ;
continue;
}
F_77 ( V_41 , V_189 ) ;
V_188 ++ ;
}
return V_188 ;
}
static int
F_80 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_99 * V_137 )
{
int V_2 , V_188 = 0 ;
struct V_66 * V_189 ;
struct V_86 * V_46 = V_41 -> V_46 ;
bool V_90 = F_49 ( V_12 ) ;
for ( V_2 = 0 ; V_2 < F_32 ( V_190 ) ; V_2 ++ ) {
const struct V_191 * V_117 = & V_190 [ V_2 ] ;
V_189 = F_60 ( V_46 , V_117 -> V_129 , V_117 -> V_130 , V_117 -> V_104 , V_90 , 0 , 0 ) ;
if ( ! V_189 )
return V_188 ;
F_78 ( V_189 ) ;
if ( ! F_74 ( V_189 , V_12 , V_137 ) ||
! F_75 ( V_41 , V_189 ) ) {
F_63 ( V_46 , V_189 ) ;
continue;
}
F_77 ( V_41 , V_189 ) ;
V_188 ++ ;
}
return V_188 ;
}
static void
F_81 ( struct V_99 * V_137 , void * V_192 )
{
struct V_193 * V_95 = V_192 ;
struct V_194 * V_21 = & V_137 -> V_21 . V_195 ;
struct V_196 * V_197 = & V_21 -> V_21 . V_197 ;
if ( V_21 -> type != V_105 )
return;
V_95 -> V_188 += F_76 ( V_95 -> V_41 ,
V_95 -> V_12 ,
V_137 ) ;
if ( ! F_82 ( V_95 -> V_12 , 1 , 1 ) )
return;
switch ( V_197 -> V_35 ) {
case 0x02 :
case 0x00 :
V_95 -> V_188 += F_79 ( V_95 -> V_41 ,
V_95 -> V_12 ,
V_137 ) ;
break;
case 0x04 :
if ( ! F_82 ( V_95 -> V_12 , 1 , 3 ) )
break;
V_95 -> V_188 += F_80 ( V_95 -> V_41 ,
V_95 -> V_12 ,
V_137 ) ;
break;
case 0x01 :
default:
break;
}
}
static int
F_83 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_193 V_95 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
if ( F_82 ( V_12 , 1 , 0 ) )
F_47 ( ( T_1 * ) V_12 , F_81 ,
& V_95 ) ;
return V_95 . V_188 ;
}
static int
F_84 ( struct V_40 * V_41 , struct V_99 * V_137 )
{
int V_2 , V_49 , V_117 , V_188 = 0 ;
struct V_66 * V_79 ;
T_1 * V_198 = ( ( T_1 * ) V_137 ) + 6 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_49 = 7 ; V_49 >= 0 ; V_49 -- ) {
V_117 = ( V_2 * 8 ) + ( 7 - V_49 ) ;
if ( V_117 >= F_32 ( V_199 ) )
break;
if ( V_198 [ V_2 ] & ( 1 << V_49 ) ) {
V_79 = F_42 ( V_41 -> V_46 ,
V_199 [ V_117 ] . V_129 ,
V_199 [ V_117 ] . V_130 ,
V_199 [ V_117 ] . V_104 ,
V_199 [ V_117 ] . V_90 ) ;
if ( V_79 ) {
F_77 ( V_41 , V_79 ) ;
V_188 ++ ;
}
}
}
}
return V_188 ;
}
static void
F_85 ( struct V_99 * V_137 , void * V_192 )
{
struct V_193 * V_95 = V_192 ;
struct V_194 * V_21 = & V_137 -> V_21 . V_195 ;
if ( V_21 -> type == V_200 )
V_95 -> V_188 += F_84 ( V_95 -> V_41 , V_137 ) ;
}
static int
F_86 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_86 * V_46 = V_41 -> V_46 ;
unsigned long V_201 = V_12 -> V_202 . V_203 |
( V_12 -> V_202 . V_204 << 8 ) |
( ( V_12 -> V_202 . V_205 & 0x80 ) << 9 ) ;
int V_2 , V_188 = 0 ;
struct V_193 V_95 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
for ( V_2 = 0 ; V_2 <= V_206 ; V_2 ++ ) {
if ( V_201 & ( 1 << V_2 ) ) {
struct V_66 * V_189 ;
V_189 = F_43 ( V_46 , & V_207 [ V_2 ] ) ;
if ( V_189 ) {
F_77 ( V_41 , V_189 ) ;
V_188 ++ ;
}
}
}
if ( F_82 ( V_12 , 1 , 0 ) )
F_47 ( ( T_1 * ) V_12 ,
F_85 , & V_95 ) ;
return V_188 + V_95 . V_188 ;
}
static void
F_87 ( struct V_99 * V_137 , void * V_192 )
{
struct V_193 * V_95 = V_192 ;
struct V_194 * V_21 = & V_137 -> V_21 . V_195 ;
struct V_40 * V_41 = V_95 -> V_41 ;
struct V_12 * V_12 = V_95 -> V_12 ;
if ( V_21 -> type == V_208 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_116 * V_209 ;
struct V_66 * V_189 ;
V_209 = & V_21 -> V_21 . V_210 [ V_2 ] ;
V_189 = F_58 ( V_41 , V_12 , V_209 ) ;
if ( V_189 ) {
F_77 ( V_41 , V_189 ) ;
V_95 -> V_188 ++ ;
}
}
}
}
static int
F_88 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
int V_2 , V_188 = 0 ;
struct V_193 V_95 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
for ( V_2 = 0 ; V_2 < V_211 ; V_2 ++ ) {
struct V_66 * V_189 ;
V_189 = F_58 ( V_41 , V_12 ,
& V_12 -> V_212 [ V_2 ] ) ;
if ( V_189 ) {
F_77 ( V_41 , V_189 ) ;
V_188 ++ ;
}
}
if ( F_82 ( V_12 , 1 , 0 ) )
F_47 ( ( T_1 * ) V_12 , F_87 ,
& V_95 ) ;
return V_188 + V_95 . V_188 ;
}
static int F_89 ( struct V_40 * V_41 ,
struct V_99 * V_137 )
{
int V_2 , V_49 , V_188 = 0 ;
struct V_66 * V_189 ;
struct V_86 * V_46 = V_41 -> V_46 ;
struct V_213 * V_214 ;
const int V_215 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_216 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_217 ( V_218 ) , V_219 ;
V_214 = & ( V_137 -> V_21 . V_195 . V_21 . V_214 [ V_2 ] ) ;
if ( ! memcmp ( V_214 -> V_220 , V_216 , 3 ) )
continue;
V_219 = ( V_214 -> V_220 [ 0 ] + ( ( V_214 -> V_220 [ 1 ] & 0xf0 ) << 4 ) + 1 ) * 2 ;
switch ( V_214 -> V_220 [ 1 ] & 0x0c ) {
case 0x00 :
V_218 = V_219 * 4 / 3 ;
break;
case 0x04 :
V_218 = V_219 * 16 / 9 ;
break;
case 0x08 :
V_218 = V_219 * 16 / 10 ;
break;
case 0x0c :
V_218 = V_219 * 15 / 9 ;
break;
}
for ( V_49 = 1 ; V_49 < 5 ; V_49 ++ ) {
if ( V_214 -> V_220 [ 2 ] & ( 1 << V_49 ) ) {
V_189 = F_60 ( V_46 , V_218 , V_219 ,
V_215 [ V_49 ] , V_49 == 0 ,
false , false ) ;
if ( V_189 ) {
F_77 ( V_41 , V_189 ) ;
V_188 ++ ;
}
}
}
}
return V_188 ;
}
static void
F_90 ( struct V_99 * V_137 , void * V_192 )
{
struct V_193 * V_95 = V_192 ;
struct V_194 * V_21 = & V_137 -> V_21 . V_195 ;
if ( V_21 -> type == V_221 )
V_95 -> V_188 += F_89 ( V_95 -> V_41 , V_137 ) ;
}
static int
F_91 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_193 V_95 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
if ( F_82 ( V_12 , 1 , 2 ) )
F_47 ( ( T_1 * ) V_12 , F_90 , & V_95 ) ;
return V_95 . V_188 ;
}
static void
F_92 ( struct V_99 * V_137 , void * V_192 )
{
struct V_193 * V_95 = V_192 ;
struct V_66 * V_189 ;
if ( V_137 -> V_162 ) {
V_189 = F_66 ( V_95 -> V_41 -> V_46 ,
V_95 -> V_12 , V_137 ,
V_95 -> V_65 ) ;
if ( ! V_189 )
return;
if ( V_95 -> V_222 )
V_189 -> type |= V_77 ;
F_93 ( V_189 ) ;
F_77 ( V_95 -> V_41 , V_189 ) ;
V_95 -> V_188 ++ ;
V_95 -> V_222 = 0 ;
}
}
static int
F_94 ( struct V_40 * V_41 , struct V_12 * V_12 ,
T_3 V_65 )
{
struct V_193 V_95 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
. V_222 = 1 ,
. V_65 = V_65 ,
} ;
if ( V_95 . V_222 && ! F_82 ( V_12 , 1 , 3 ) )
V_95 . V_222 =
( V_12 -> V_108 & V_223 ) ;
F_47 ( ( T_1 * ) V_12 , F_92 , & V_95 ) ;
return V_95 . V_188 ;
}
static T_1 * F_95 ( struct V_12 * V_12 , int V_224 )
{
T_1 * V_225 = NULL ;
int V_2 ;
if ( V_12 == NULL || V_12 -> V_20 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_12 -> V_20 ; V_2 ++ ) {
V_225 = ( T_1 * ) V_12 + V_6 * ( V_2 + 1 ) ;
if ( V_225 [ 0 ] == V_224 )
break;
}
if ( V_2 == V_12 -> V_20 )
return NULL ;
return V_225 ;
}
static T_1 * F_96 ( struct V_12 * V_12 )
{
return F_95 ( V_12 , V_102 ) ;
}
static T_1 * F_97 ( struct V_12 * V_12 )
{
return F_95 ( V_12 , V_226 ) ;
}
static unsigned int
F_98 ( const struct V_66 * V_227 )
{
unsigned int clock = V_227 -> clock ;
if ( V_227 -> V_78 % 6 != 0 )
return clock ;
if ( V_227 -> V_85 == 240 || V_227 -> V_85 == 480 )
clock = F_99 ( clock * 1001 , 1000 ) ;
else
clock = F_99 ( clock * 1000 , 1001 ) ;
return clock ;
}
static bool
F_100 ( T_1 V_228 , struct V_66 * V_79 )
{
F_101 ( V_229 [ 8 ] . V_135 != 262 ||
V_229 [ 9 ] . V_135 != 262 ||
V_229 [ 12 ] . V_135 != 262 ||
V_229 [ 13 ] . V_135 != 262 ||
V_229 [ 23 ] . V_135 != 312 ||
V_229 [ 24 ] . V_135 != 312 ||
V_229 [ 27 ] . V_135 != 312 ||
V_229 [ 28 ] . V_135 != 312 ) ;
if ( ( ( V_228 == 8 || V_228 == 9 ||
V_228 == 12 || V_228 == 13 ) && V_79 -> V_135 < 263 ) ||
( ( V_228 == 23 || V_228 == 24 ||
V_228 == 27 || V_228 == 28 ) && V_79 -> V_135 < 314 ) ) {
V_79 -> V_84 ++ ;
V_79 -> V_134 ++ ;
V_79 -> V_135 ++ ;
return true ;
}
return false ;
}
static T_1 F_102 ( const struct V_66 * V_230 ,
unsigned int V_231 )
{
T_1 V_228 ;
if ( ! V_230 -> clock )
return 0 ;
for ( V_228 = 1 ; V_228 < F_32 ( V_229 ) ; V_228 ++ ) {
struct V_66 V_227 = V_229 [ V_228 ] ;
unsigned int V_232 , V_233 ;
V_232 = V_227 . clock ;
V_233 = F_98 ( & V_227 ) ;
if ( abs ( V_230 -> clock - V_232 ) > V_231 &&
abs ( V_230 -> clock - V_233 ) > V_231 )
continue;
do {
if ( F_103 ( V_230 , & V_227 ) )
return V_228 ;
} while ( F_100 ( V_228 , & V_227 ) );
}
return 0 ;
}
T_1 F_104 ( const struct V_66 * V_230 )
{
T_1 V_228 ;
if ( ! V_230 -> clock )
return 0 ;
for ( V_228 = 1 ; V_228 < F_32 ( V_229 ) ; V_228 ++ ) {
struct V_66 V_227 = V_229 [ V_228 ] ;
unsigned int V_232 , V_233 ;
V_232 = V_227 . clock ;
V_233 = F_98 ( & V_227 ) ;
if ( F_105 ( V_230 -> clock ) != F_105 ( V_232 ) &&
F_105 ( V_230 -> clock ) != F_105 ( V_233 ) )
continue;
do {
if ( F_103 ( V_230 , & V_227 ) )
return V_228 ;
} while ( F_100 ( V_228 , & V_227 ) );
}
return 0 ;
}
static bool F_106 ( T_1 V_228 )
{
return V_228 > 0 && V_228 < F_32 ( V_229 ) ;
}
enum V_234 F_107 ( const T_1 V_235 )
{
return V_229 [ V_235 ] . V_236 ;
}
static unsigned int
F_108 ( const struct V_66 * V_237 )
{
if ( V_237 -> V_85 == 4096 && V_237 -> V_81 == 2160 )
return V_237 -> clock ;
return F_98 ( V_237 ) ;
}
static T_1 F_109 ( const struct V_66 * V_230 ,
unsigned int V_231 )
{
T_1 V_228 ;
if ( ! V_230 -> clock )
return 0 ;
for ( V_228 = 1 ; V_228 < F_32 ( V_238 ) ; V_228 ++ ) {
const struct V_66 * V_237 = & V_238 [ V_228 ] ;
unsigned int V_232 , V_233 ;
V_232 = V_237 -> clock ;
V_233 = F_108 ( V_237 ) ;
if ( abs ( V_230 -> clock - V_232 ) > V_231 &&
abs ( V_230 -> clock - V_233 ) > V_231 )
continue;
if ( F_110 ( V_230 , V_237 ) )
return V_228 ;
}
return 0 ;
}
static T_1 F_111 ( const struct V_66 * V_230 )
{
T_1 V_228 ;
if ( ! V_230 -> clock )
return 0 ;
for ( V_228 = 1 ; V_228 < F_32 ( V_238 ) ; V_228 ++ ) {
const struct V_66 * V_237 = & V_238 [ V_228 ] ;
unsigned int V_232 , V_233 ;
V_232 = V_237 -> clock ;
V_233 = F_108 ( V_237 ) ;
if ( ( F_105 ( V_230 -> clock ) == F_105 ( V_232 ) ||
F_105 ( V_230 -> clock ) == F_105 ( V_233 ) ) &&
F_103 ( V_230 , V_237 ) )
return V_228 ;
}
return 0 ;
}
static bool F_112 ( T_1 V_228 )
{
return V_228 > 0 && V_228 < F_32 ( V_238 ) ;
}
static int
F_113 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_86 * V_46 = V_41 -> V_46 ;
struct V_66 * V_79 , * V_239 ;
F_114 ( V_240 ) ;
int V_188 = 0 ;
if ( ! F_96 ( V_12 ) )
return 0 ;
F_59 (mode, &connector->probed_modes, head) {
const struct V_66 * V_227 = NULL ;
struct V_66 * V_189 ;
T_1 V_228 = F_104 ( V_79 ) ;
unsigned int V_232 , V_233 ;
if ( F_106 ( V_228 ) ) {
V_227 = & V_229 [ V_228 ] ;
V_233 = F_98 ( V_227 ) ;
} else {
V_228 = F_111 ( V_79 ) ;
if ( F_112 ( V_228 ) ) {
V_227 = & V_238 [ V_228 ] ;
V_233 = F_108 ( V_227 ) ;
}
}
if ( ! V_227 )
continue;
V_232 = V_227 -> clock ;
if ( V_232 == V_233 )
continue;
if ( V_79 -> clock != V_232 && V_79 -> clock != V_233 )
continue;
V_189 = F_43 ( V_46 , V_227 ) ;
if ( ! V_189 )
continue;
V_189 -> V_35 |= V_79 -> V_35 & V_241 ;
if ( V_79 -> clock != V_232 )
V_189 -> clock = V_232 ;
else
V_189 -> clock = V_233 ;
F_115 ( & V_189 -> V_76 , & V_240 ) ;
}
F_37 (mode, tmp, &list, head) {
F_116 ( & V_79 -> V_76 ) ;
F_77 ( V_41 , V_79 ) ;
V_188 ++ ;
}
return V_188 ;
}
static struct V_66 *
F_117 ( struct V_40 * V_41 ,
const T_1 * V_242 , T_1 V_243 ,
T_1 V_244 )
{
struct V_86 * V_46 = V_41 -> V_46 ;
struct V_66 * V_189 ;
T_1 V_228 ;
if ( V_242 == NULL || V_244 >= V_243 )
return NULL ;
V_228 = ( V_242 [ V_244 ] & 127 ) ;
if ( ! F_106 ( V_228 ) )
return NULL ;
V_189 = F_43 ( V_46 , & V_229 [ V_228 ] ) ;
if ( ! V_189 )
return NULL ;
V_189 -> V_78 = 0 ;
return V_189 ;
}
static int
F_118 ( struct V_40 * V_41 , const T_1 * V_245 , T_1 V_23 )
{
int V_2 , V_188 = 0 ;
for ( V_2 = 0 ; V_2 < V_23 ; V_2 ++ ) {
struct V_66 * V_79 ;
V_79 = F_117 ( V_41 , V_245 , V_23 , V_2 ) ;
if ( V_79 ) {
F_77 ( V_41 , V_79 ) ;
V_188 ++ ;
}
}
return V_188 ;
}
static bool
F_119 ( const struct V_66 * V_79 ,
const struct V_246 * V_247 )
{
unsigned int V_248 = V_79 -> V_35 & V_136 ;
return V_79 -> V_81 == V_247 -> V_218 &&
V_79 -> V_85 == V_247 -> V_219 &&
V_248 == ( V_247 -> V_35 & V_136 ) &&
F_39 ( V_79 ) == V_247 -> V_78 ;
}
static int F_120 ( struct V_40 * V_41 )
{
struct V_86 * V_46 = V_41 -> V_46 ;
const struct V_66 * V_79 ;
struct V_249 V_250 ;
int V_188 = 0 , V_2 ;
F_121 ( & V_250 ) ;
F_59 (mode, &connector->probed_modes, head) {
for ( V_2 = 0 ; V_2 < F_32 ( V_251 ) ; V_2 ++ ) {
const struct V_246 * V_252 ;
struct V_66 * V_253 ;
if ( ! F_119 ( V_79 ,
& V_251 [ V_2 ] ) )
continue;
V_252 = & V_251 [ V_2 ] ;
V_253 = F_43 ( V_46 , V_79 ) ;
if ( ! V_253 )
continue;
V_253 -> V_35 |= V_252 -> V_35 ;
F_115 ( & V_253 -> V_76 , & V_250 ) ;
V_188 ++ ;
}
}
F_122 ( & V_250 , & V_41 -> V_73 ) ;
return V_188 ;
}
static int F_123 ( struct V_40 * V_41 , T_1 V_228 )
{
struct V_86 * V_46 = V_41 -> V_46 ;
struct V_66 * V_189 ;
if ( ! F_112 ( V_228 ) ) {
F_8 ( L_17 , V_228 ) ;
return 0 ;
}
V_189 = F_43 ( V_46 , & V_238 [ V_228 ] ) ;
if ( ! V_189 )
return 0 ;
F_77 ( V_41 , V_189 ) ;
return 1 ;
}
static int F_124 ( struct V_40 * V_41 , T_5 V_254 ,
const T_1 * V_242 , T_1 V_243 , T_1 V_244 )
{
struct V_66 * V_189 ;
int V_188 = 0 ;
if ( V_254 & ( 1 << 0 ) ) {
V_189 = F_117 ( V_41 , V_242 ,
V_243 ,
V_244 ) ;
if ( V_189 ) {
V_189 -> V_35 |= V_255 ;
F_77 ( V_41 , V_189 ) ;
V_188 ++ ;
}
}
if ( V_254 & ( 1 << 6 ) ) {
V_189 = F_117 ( V_41 , V_242 ,
V_243 ,
V_244 ) ;
if ( V_189 ) {
V_189 -> V_35 |= V_256 ;
F_77 ( V_41 , V_189 ) ;
V_188 ++ ;
}
}
if ( V_254 & ( 1 << 8 ) ) {
V_189 = F_117 ( V_41 , V_242 ,
V_243 ,
V_244 ) ;
if ( V_189 ) {
V_189 -> V_35 |= V_257 ;
F_77 ( V_41 , V_189 ) ;
V_188 ++ ;
}
}
return V_188 ;
}
static int
F_125 ( struct V_40 * V_41 , const T_1 * V_245 , T_1 V_23 ,
const T_1 * V_242 , T_1 V_243 )
{
int V_188 = 0 , V_258 = 0 , V_2 , V_259 = 0 , V_260 ;
T_1 V_261 , V_262 = 0 ;
T_5 V_263 ;
T_5 V_264 ;
if ( V_23 < 8 )
goto V_53;
if ( ! ( V_245 [ 8 ] & ( 1 << 5 ) ) )
goto V_53;
if ( V_245 [ 8 ] & ( 1 << 7 ) )
V_258 += 2 ;
if ( V_245 [ 8 ] & ( 1 << 6 ) )
V_258 += 2 ;
if ( V_23 < ( 8 + V_258 + 2 ) )
goto V_53;
V_258 ++ ;
if ( V_245 [ 8 + V_258 ] & ( 1 << 7 ) ) {
V_188 += F_120 ( V_41 ) ;
V_259 = ( V_245 [ 8 + V_258 ] & 0x60 ) >> 5 ;
}
V_258 ++ ;
V_261 = V_245 [ 8 + V_258 ] >> 5 ;
V_262 = V_245 [ 8 + V_258 ] & 0x1f ;
for ( V_2 = 0 ; V_2 < V_261 && V_23 >= ( 9 + V_258 + V_2 ) ; V_2 ++ ) {
T_1 V_228 ;
V_228 = V_245 [ 9 + V_258 + V_2 ] ;
V_188 += F_123 ( V_41 , V_228 ) ;
}
V_258 += 1 + V_261 ;
if ( V_259 == 1 )
V_260 = 2 ;
else if ( V_259 == 2 )
V_260 = 4 ;
else
V_260 = 0 ;
if ( V_23 < ( 8 + V_258 + V_262 - 1 ) )
goto V_53;
if ( V_262 < V_260 )
goto V_53;
if ( V_259 == 1 || V_259 == 2 ) {
V_264 = ( V_245 [ 8 + V_258 ] << 8 ) | V_245 [ 9 + V_258 ] ;
if ( V_259 == 2 )
V_263 = ( V_245 [ 10 + V_258 ] << 8 ) | V_245 [ 11 + V_258 ] ;
else
V_263 = 0xffff ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
if ( V_263 & ( 1 << V_2 ) )
V_188 += F_124 ( V_41 ,
V_264 ,
V_242 ,
V_243 , V_2 ) ;
}
}
V_258 += V_260 ;
for ( V_2 = 0 ; V_2 < ( V_262 - V_260 ) ; V_2 ++ ) {
int V_265 ;
struct V_66 * V_189 = NULL ;
unsigned int V_266 = 0 ;
bool V_267 ;
V_267 = ( ( V_245 [ 8 + V_258 + V_2 ] & 0x0f ) > 7 ) ;
if ( V_267 && ( V_2 + 1 == V_262 - V_260 ) )
break;
V_265 = V_245 [ 8 + V_258 + V_2 ] >> 4 ;
switch ( V_245 [ 8 + V_258 + V_2 ] & 0x0f ) {
case 0 :
V_266 = V_255 ;
break;
case 6 :
V_266 = V_256 ;
break;
case 8 :
if ( ( V_245 [ 9 + V_258 + V_2 ] >> 4 ) == 1 )
V_266 = V_257 ;
break;
}
if ( V_266 != 0 ) {
V_189 = F_117 ( V_41 ,
V_242 ,
V_243 ,
V_265 ) ;
if ( V_189 ) {
V_189 -> V_35 |= V_266 ;
F_77 ( V_41 , V_189 ) ;
V_188 ++ ;
}
}
if ( V_267 )
V_2 ++ ;
}
V_53:
return V_188 ;
}
static int
F_126 ( const T_1 * V_245 )
{
return V_245 [ 0 ] & 0x1f ;
}
static int
F_127 ( const T_1 * V_245 )
{
return V_245 [ 0 ] >> 5 ;
}
static int
F_128 ( const T_1 * V_268 )
{
return V_268 [ 1 ] ;
}
static int
F_129 ( const T_1 * V_268 , int * V_26 , int * V_269 )
{
* V_26 = 4 ;
* V_269 = V_268 [ 2 ] ;
if ( * V_269 == 0 )
* V_269 = 127 ;
if ( * V_269 < 4 || * V_269 > 127 )
return - V_270 ;
return 0 ;
}
static bool F_130 ( const T_1 * V_245 )
{
int V_271 ;
if ( F_127 ( V_245 ) != V_272 )
return false ;
if ( F_126 ( V_245 ) < 5 )
return false ;
V_271 = V_245 [ 1 ] | ( V_245 [ 2 ] << 8 ) | ( V_245 [ 3 ] << 16 ) ;
return V_271 == V_273 ;
}
static int
F_131 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
const T_1 * V_268 = F_96 ( V_12 ) ;
const T_1 * V_245 , * V_274 = NULL , * V_275 = NULL ;
T_1 V_276 , V_277 , V_243 = 0 ;
int V_188 = 0 ;
if ( V_268 && F_128 ( V_268 ) >= 3 ) {
int V_2 , V_26 , V_269 ;
if ( F_129 ( V_268 , & V_26 , & V_269 ) )
return 0 ;
F_132 (cea, i, start, end) {
V_245 = & V_268 [ V_2 ] ;
V_276 = F_126 ( V_245 ) ;
if ( F_127 ( V_245 ) == V_278 ) {
V_275 = V_245 + 1 ;
V_243 = V_276 ;
V_188 += F_118 ( V_41 , V_275 , V_276 ) ;
}
else if ( F_130 ( V_245 ) ) {
V_274 = V_245 ;
V_277 = V_276 ;
}
}
}
if ( V_274 )
V_188 += F_125 ( V_41 , V_274 , V_277 , V_275 ,
V_243 ) ;
return V_188 ;
}
static void F_93 ( struct V_66 * V_79 )
{
const struct V_66 * V_227 ;
int V_232 , V_233 , clock ;
T_1 V_228 ;
const char * type ;
V_228 = F_102 ( V_79 , 5 ) ;
if ( F_106 ( V_228 ) ) {
type = L_18 ;
V_227 = & V_229 [ V_228 ] ;
V_232 = V_227 -> clock ;
V_233 = F_98 ( V_227 ) ;
} else {
V_228 = F_109 ( V_79 , 5 ) ;
if ( F_112 ( V_228 ) ) {
type = L_19 ;
V_227 = & V_238 [ V_228 ] ;
V_232 = V_227 -> clock ;
V_233 = F_108 ( V_227 ) ;
} else {
return;
}
}
if ( abs ( V_79 -> clock - V_232 ) < abs ( V_79 -> clock - V_233 ) )
clock = V_232 ;
else
clock = V_233 ;
if ( V_79 -> clock == clock )
return;
F_7 ( L_20 ,
type , V_228 , V_79 -> clock , clock ) ;
V_79 -> clock = clock ;
}
static void
F_133 ( struct V_40 * V_41 , const T_1 * V_245 )
{
T_1 V_23 = F_126 ( V_245 ) ;
if ( V_23 >= 6 )
V_41 -> V_279 [ 5 ] |= ( V_245 [ 6 ] >> 7 ) << 1 ;
if ( V_23 >= 8 ) {
V_41 -> V_280 [ 0 ] = V_245 [ 8 ] >> 7 ;
V_41 -> V_280 [ 1 ] = ( V_245 [ 8 ] >> 6 ) & 1 ;
}
if ( V_23 >= 9 )
V_41 -> V_281 [ 0 ] = V_245 [ 9 ] ;
if ( V_23 >= 10 )
V_41 -> V_282 [ 0 ] = V_245 [ 10 ] ;
if ( V_23 >= 11 )
V_41 -> V_281 [ 1 ] = V_245 [ 11 ] ;
if ( V_23 >= 12 )
V_41 -> V_282 [ 1 ] = V_245 [ 12 ] ;
F_14 ( L_21
L_22
L_23 ,
V_41 -> V_280 [ 0 ] ,
V_41 -> V_280 [ 1 ] ,
V_41 -> V_281 [ 0 ] ,
V_41 -> V_281 [ 1 ] ,
V_41 -> V_282 [ 0 ] ,
V_41 -> V_282 [ 1 ] ) ;
}
static void
F_134 ( struct V_99 * V_67 , void * V_21 )
{
if ( V_67 -> V_21 . V_195 . type == V_283 )
* ( T_1 * * ) V_21 = V_67 -> V_21 . V_195 . V_21 . V_284 . V_284 ;
}
static int F_135 ( struct V_12 * V_12 , char V_39 [ 13 ] )
{
char * V_285 = NULL ;
int V_286 ;
if ( ! V_12 || ! V_39 )
return 0 ;
F_47 ( ( T_1 * ) V_12 , F_134 , & V_285 ) ;
for ( V_286 = 0 ; V_285 && V_286 < 13 ; V_286 ++ ) {
if ( V_285 [ V_286 ] == 0x0a )
break;
V_39 [ V_286 ] = V_285 [ V_286 ] ;
}
return V_286 ;
}
void F_136 ( struct V_12 * V_12 , char * V_39 , int V_287 )
{
int V_288 ;
char V_22 [ 13 ] ;
if ( V_287 <= 0 )
return;
V_288 = F_46 ( F_135 ( V_12 , V_22 ) , V_287 - 1 ) ;
memcpy ( V_39 , V_22 , V_288 ) ;
V_39 [ V_288 ] = '\0' ;
}
void F_137 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
T_6 * V_279 = V_41 -> V_279 ;
T_1 * V_268 ;
T_1 * V_245 ;
int V_289 = 0 ;
int V_286 ;
int V_276 ;
memset ( V_279 , 0 , sizeof( V_41 -> V_279 ) ) ;
V_41 -> V_280 [ 0 ] = false ;
V_41 -> V_280 [ 1 ] = false ;
V_41 -> V_281 [ 0 ] = 0 ;
V_41 -> V_282 [ 0 ] = 0 ;
V_41 -> V_281 [ 1 ] = 0 ;
V_41 -> V_282 [ 1 ] = 0 ;
V_268 = F_96 ( V_12 ) ;
if ( ! V_268 ) {
F_14 ( L_24 ) ;
return;
}
V_286 = F_135 ( V_12 , V_279 + 20 ) ;
V_279 [ 4 ] = ( V_268 [ 1 ] << 5 ) | V_286 ;
F_14 ( L_25 , V_279 + 20 ) ;
V_279 [ 0 ] = 2 << 3 ;
V_279 [ 16 ] = V_12 -> V_60 [ 0 ] ;
V_279 [ 17 ] = V_12 -> V_60 [ 1 ] ;
V_279 [ 18 ] = V_12 -> V_290 [ 0 ] ;
V_279 [ 19 ] = V_12 -> V_290 [ 1 ] ;
if ( F_128 ( V_268 ) >= 3 ) {
int V_2 , V_26 , V_269 ;
if ( F_129 ( V_268 , & V_26 , & V_269 ) ) {
V_26 = 0 ;
V_269 = 0 ;
}
F_132 (cea, i, start, end) {
V_245 = & V_268 [ V_2 ] ;
V_276 = F_126 ( V_245 ) ;
switch ( F_127 ( V_245 ) ) {
int V_291 ;
case V_292 :
V_291 = F_46 ( V_276 / 3 , 15 - V_289 ) ;
if ( V_291 >= 1 )
memcpy ( V_279 + 20 + V_286 + V_289 * 3 ,
& V_245 [ 1 ] , V_291 * 3 ) ;
V_289 += V_291 ;
break;
case V_293 :
if ( V_276 >= 1 )
V_279 [ 7 ] = V_245 [ 1 ] ;
break;
case V_272 :
if ( F_130 ( V_245 ) )
F_133 ( V_41 , V_245 ) ;
break;
default:
break;
}
}
}
V_279 [ 5 ] |= V_289 << 4 ;
V_279 [ V_294 ] =
F_138 ( F_139 ( V_279 ) , 4 ) ;
F_14 ( L_26 ,
F_140 ( V_279 ) , V_289 ) ;
}
int F_141 ( struct V_12 * V_12 , struct V_295 * * V_296 )
{
int V_297 = 0 ;
int V_2 , V_26 , V_269 , V_276 ;
T_1 * V_268 ;
V_268 = F_96 ( V_12 ) ;
if ( ! V_268 ) {
F_14 ( L_27 ) ;
return - V_298 ;
}
if ( F_128 ( V_268 ) < 3 ) {
F_14 ( L_28 ) ;
return - V_299 ;
}
if ( F_129 ( V_268 , & V_26 , & V_269 ) ) {
F_14 ( L_29 ) ;
return - V_300 ;
}
F_132 (cea, i, start, end) {
T_1 * V_245 = & V_268 [ V_2 ] ;
if ( F_127 ( V_245 ) == V_292 ) {
int V_49 ;
V_276 = F_126 ( V_245 ) ;
V_297 = V_276 / 3 ;
* V_296 = F_142 ( V_297 , sizeof( * * V_296 ) , V_52 ) ;
if ( ! * V_296 )
return - V_301 ;
for ( V_49 = 0 ; V_49 < V_297 ; V_49 ++ ) {
T_1 * V_302 = & V_245 [ 1 + V_49 * 3 ] ;
( * V_296 ) [ V_49 ] . V_303 = ( V_302 [ 0 ] & 0x78 ) >> 3 ;
( * V_296 ) [ V_49 ] . V_304 = V_302 [ 0 ] & 0x7 ;
( * V_296 ) [ V_49 ] . V_305 = V_302 [ 1 ] & 0x7F ;
( * V_296 ) [ V_49 ] . V_306 = V_302 [ 2 ] ;
}
break;
}
}
return V_297 ;
}
int F_143 ( struct V_12 * V_12 , T_1 * * V_307 )
{
int V_297 = 0 ;
int V_2 , V_26 , V_269 , V_276 ;
const T_1 * V_268 ;
V_268 = F_96 ( V_12 ) ;
if ( ! V_268 ) {
F_14 ( L_27 ) ;
return - V_298 ;
}
if ( F_128 ( V_268 ) < 3 ) {
F_14 ( L_28 ) ;
return - V_299 ;
}
if ( F_129 ( V_268 , & V_26 , & V_269 ) ) {
F_14 ( L_29 ) ;
return - V_300 ;
}
F_132 (cea, i, start, end) {
const T_1 * V_245 = & V_268 [ V_2 ] ;
if ( F_127 ( V_245 ) == V_293 ) {
V_276 = F_126 ( V_245 ) ;
if ( V_276 == 3 ) {
* V_307 = F_29 ( & V_245 [ 1 ] , V_276 , V_52 ) ;
if ( ! * V_307 )
return - V_301 ;
V_297 = V_276 ;
break;
}
}
}
return V_297 ;
}
int F_144 ( struct V_40 * V_41 ,
const struct V_66 * V_79 )
{
int V_2 = ! ! ( V_79 -> V_35 & V_136 ) ;
int V_114 , V_308 ;
if ( ! V_41 -> V_280 [ 0 ] )
return 0 ;
if ( ! V_41 -> V_280 [ 1 ] )
V_2 = 0 ;
V_114 = V_41 -> V_282 [ V_2 ] ;
V_308 = V_41 -> V_281 [ V_2 ] ;
if ( V_114 == 255 || V_308 == 255 )
return 0 ;
if ( V_114 )
V_114 = F_46 ( 2 * ( V_114 - 1 ) , 500 ) ;
if ( V_308 )
V_308 = F_46 ( 2 * ( V_308 - 1 ) , 500 ) ;
return F_145 ( V_308 - V_114 , 0 ) ;
}
bool F_146 ( struct V_12 * V_12 )
{
T_1 * V_225 ;
int V_2 ;
int V_309 , V_310 ;
V_225 = F_96 ( V_12 ) ;
if ( ! V_225 )
return false ;
if ( F_129 ( V_225 , & V_309 , & V_310 ) )
return false ;
F_132 (edid_ext, i, start_offset, end_offset) {
if ( F_130 ( & V_225 [ V_2 ] ) )
return true ;
}
return false ;
}
bool F_147 ( struct V_12 * V_12 )
{
T_1 * V_225 ;
int V_2 , V_49 ;
bool V_311 = false ;
int V_309 , V_310 ;
V_225 = F_96 ( V_12 ) ;
if ( ! V_225 )
goto V_269;
V_311 = ( ( V_225 [ 3 ] & V_312 ) != 0 ) ;
if ( V_311 ) {
F_14 ( L_30 ) ;
goto V_269;
}
if ( F_129 ( V_225 , & V_309 , & V_310 ) )
goto V_269;
F_132 (edid_ext, i, start_offset, end_offset) {
if ( F_127 ( & V_225 [ V_2 ] ) == V_292 ) {
V_311 = true ;
for ( V_49 = 1 ; V_49 < F_126 ( & V_225 [ V_2 ] ) + 1 ; V_49 += 3 )
F_14 ( L_31 ,
( V_225 [ V_2 + V_49 ] >> 3 ) & 0xf ) ;
goto V_269;
}
}
V_269:
return V_311 ;
}
bool F_148 ( struct V_12 * V_12 )
{
T_1 * V_225 ;
int V_2 , V_26 , V_269 ;
V_225 = F_96 ( V_12 ) ;
if ( ! V_225 )
return false ;
if ( F_129 ( V_225 , & V_26 , & V_269 ) )
return false ;
F_132 (edid_ext, i, start, end) {
if ( F_127 ( & V_225 [ V_2 ] ) == V_313 &&
F_126 ( & V_225 [ V_2 ] ) == 2 ) {
F_14 ( L_32 , V_225 [ V_2 + 2 ] ) ;
return V_225 [ V_2 + 2 ] & V_314 ;
}
}
return false ;
}
enum V_315
F_149 ( const struct V_66 * V_79 )
{
return F_104 ( V_79 ) > 1 ?
V_316 :
V_317 ;
}
static void F_150 ( struct V_40 * V_41 ,
const T_1 * V_274 )
{
struct V_318 * V_319 = & V_41 -> V_320 ;
unsigned int V_321 = 0 ;
V_319 -> V_322 = 8 ;
if ( F_126 ( V_274 ) < 6 )
return;
if ( V_274 [ 6 ] & V_323 ) {
V_321 = 10 ;
V_319 -> V_324 |= V_323 ;
F_7 ( L_33 ,
V_41 -> V_39 ) ;
}
if ( V_274 [ 6 ] & V_325 ) {
V_321 = 12 ;
V_319 -> V_324 |= V_325 ;
F_7 ( L_34 ,
V_41 -> V_39 ) ;
}
if ( V_274 [ 6 ] & V_326 ) {
V_321 = 16 ;
V_319 -> V_324 |= V_326 ;
F_7 ( L_35 ,
V_41 -> V_39 ) ;
}
if ( V_321 == 0 ) {
F_7 ( L_36 ,
V_41 -> V_39 ) ;
return;
}
F_7 ( L_37 ,
V_41 -> V_39 , V_321 ) ;
V_319 -> V_322 = V_321 ;
V_319 -> V_327 = V_328 ;
if ( V_274 [ 6 ] & V_329 ) {
V_319 -> V_327 |= V_330 ;
F_7 ( L_38 ,
V_41 -> V_39 ) ;
}
if ( ! ( V_274 [ 6 ] & V_325 ) ) {
F_7 ( L_39 ,
V_41 -> V_39 ) ;
}
}
static void
F_151 ( struct V_40 * V_41 , const T_1 * V_245 )
{
struct V_318 * V_319 = & V_41 -> V_320 ;
T_1 V_23 = F_126 ( V_245 ) ;
if ( V_23 >= 6 )
V_319 -> V_331 = V_245 [ 6 ] & 1 ;
if ( V_23 >= 7 )
V_319 -> V_332 = V_245 [ 7 ] * 5000 ;
F_14 ( L_40
L_41 ,
V_319 -> V_331 ,
V_319 -> V_332 ) ;
F_150 ( V_41 , V_245 ) ;
}
static void F_152 ( struct V_40 * V_41 ,
struct V_12 * V_12 )
{
struct V_318 * V_319 = & V_41 -> V_320 ;
const T_1 * V_225 ;
int V_2 , V_26 , V_269 ;
V_225 = F_96 ( V_12 ) ;
if ( ! V_225 )
return;
V_319 -> V_333 = V_225 [ 1 ] ;
V_319 -> V_327 = V_328 ;
if ( V_225 [ 3 ] & V_334 )
V_319 -> V_327 |= V_330 ;
if ( V_225 [ 3 ] & V_335 )
V_319 -> V_327 |= V_336 ;
if ( F_129 ( V_225 , & V_26 , & V_269 ) )
return;
F_132 (edid_ext, i, start, end) {
const T_1 * V_245 = & V_225 [ V_2 ] ;
if ( F_130 ( V_245 ) )
F_151 ( V_41 , V_245 ) ;
}
}
static void F_153 ( struct V_40 * V_41 ,
struct V_12 * V_12 )
{
struct V_318 * V_319 = & V_41 -> V_320 ;
V_319 -> V_170 = V_12 -> V_177 * 10 ;
V_319 -> V_173 = V_12 -> V_178 * 10 ;
V_319 -> V_322 = 0 ;
V_319 -> V_327 = 0 ;
V_319 -> V_333 = 0 ;
V_319 -> V_332 = 0 ;
V_319 -> V_331 = false ;
if ( V_12 -> V_16 < 3 )
return;
if ( ! ( V_12 -> V_106 & V_107 ) )
return;
F_152 ( V_41 , V_12 ) ;
if ( ( V_319 -> V_322 == 0 ) && ( V_12 -> V_16 < 4 ) &&
( V_12 -> V_106 & V_337 ) ) {
V_319 -> V_322 = 8 ;
F_7 ( L_42 ,
V_41 -> V_39 , V_319 -> V_322 ) ;
}
if ( V_12 -> V_16 < 4 )
return;
switch ( V_12 -> V_106 & V_338 ) {
case V_339 :
V_319 -> V_322 = 6 ;
break;
case V_340 :
V_319 -> V_322 = 8 ;
break;
case V_341 :
V_319 -> V_322 = 10 ;
break;
case V_342 :
V_319 -> V_322 = 12 ;
break;
case V_343 :
V_319 -> V_322 = 14 ;
break;
case V_344 :
V_319 -> V_322 = 16 ;
break;
case V_345 :
default:
V_319 -> V_322 = 0 ;
break;
}
F_7 ( L_43 ,
V_41 -> V_39 , V_319 -> V_322 ) ;
V_319 -> V_327 |= V_328 ;
if ( V_12 -> V_108 & V_346 )
V_319 -> V_327 |= V_330 ;
if ( V_12 -> V_108 & V_347 )
V_319 -> V_327 |= V_336 ;
}
static int F_154 ( T_1 * V_348 , int V_8 , int V_349 )
{
int V_2 ;
T_1 V_5 = 0 ;
struct V_350 * V_56 ;
V_56 = (struct V_350 * ) & V_348 [ V_349 ] ;
F_14 ( L_44 ,
V_56 -> V_351 , V_56 -> V_352 , V_56 -> V_353 , V_56 -> V_354 ) ;
if ( V_56 -> V_352 + 5 > V_8 - V_349 )
return - V_355 ;
for ( V_2 = V_349 ; V_2 <= V_56 -> V_352 + 5 ; V_2 ++ ) {
V_5 += V_348 [ V_2 ] ;
}
if ( V_5 ) {
F_8 ( L_45 , V_5 ) ;
return - V_355 ;
}
return 0 ;
}
static struct V_66 * F_155 ( struct V_86 * V_46 ,
struct V_356 * V_210 )
{
struct V_66 * V_79 ;
unsigned V_162 = ( V_210 -> V_162 [ 0 ] |
( V_210 -> V_162 [ 1 ] << 8 ) |
( V_210 -> V_162 [ 2 ] << 16 ) ) ;
unsigned V_139 = ( V_210 -> V_139 [ 0 ] | V_210 -> V_139 [ 1 ] << 8 ) + 1 ;
unsigned V_145 = ( V_210 -> V_145 [ 0 ] | V_210 -> V_145 [ 1 ] << 8 ) + 1 ;
unsigned V_180 = ( V_210 -> V_180 [ 0 ] | ( V_210 -> V_180 [ 1 ] & 0x7f ) << 8 ) + 1 ;
unsigned V_357 = ( V_210 -> V_358 [ 0 ] | V_210 -> V_358 [ 1 ] << 8 ) + 1 ;
unsigned V_142 = ( V_210 -> V_142 [ 0 ] | V_210 -> V_142 [ 1 ] << 8 ) + 1 ;
unsigned V_147 = ( V_210 -> V_147 [ 0 ] | V_210 -> V_147 [ 1 ] << 8 ) + 1 ;
unsigned V_183 = ( V_210 -> V_183 [ 0 ] | ( V_210 -> V_183 [ 1 ] & 0x7f ) << 8 ) + 1 ;
unsigned V_359 = ( V_210 -> V_360 [ 0 ] | V_210 -> V_360 [ 1 ] << 8 ) + 1 ;
bool V_361 = ( V_210 -> V_180 [ 1 ] >> 7 ) & 0x1 ;
bool V_362 = ( V_210 -> V_183 [ 1 ] >> 7 ) & 0x1 ;
V_79 = F_67 ( V_46 ) ;
if ( ! V_79 )
return NULL ;
V_79 -> clock = V_162 * 10 ;
V_79 -> V_81 = V_139 ;
V_79 -> V_83 = V_79 -> V_81 + V_180 ;
V_79 -> V_82 = V_79 -> V_83 + V_357 ;
V_79 -> V_80 = V_79 -> V_81 + V_145 ;
V_79 -> V_85 = V_142 ;
V_79 -> V_84 = V_79 -> V_85 + V_183 ;
V_79 -> V_134 = V_79 -> V_84 + V_359 ;
V_79 -> V_135 = V_79 -> V_85 + V_147 ;
V_79 -> V_35 = 0 ;
V_79 -> V_35 |= V_361 ? V_166 : V_167 ;
V_79 -> V_35 |= V_362 ? V_168 : V_169 ;
V_79 -> type = V_179 ;
if ( V_210 -> V_35 & 0x80 )
V_79 -> type |= V_77 ;
V_79 -> V_78 = F_39 ( V_79 ) ;
F_70 ( V_79 ) ;
return V_79 ;
}
static int F_156 ( struct V_40 * V_41 ,
struct V_363 * V_9 )
{
struct V_364 * V_365 = (struct V_364 * ) V_9 ;
int V_2 ;
int V_366 ;
struct V_66 * V_189 ;
int V_367 = 0 ;
if ( V_9 -> V_368 % 20 )
return 0 ;
V_366 = V_9 -> V_368 / 20 ;
for ( V_2 = 0 ; V_2 < V_366 ; V_2 ++ ) {
struct V_356 * V_210 = & V_365 -> V_210 [ V_2 ] ;
V_189 = F_155 ( V_41 -> V_46 , V_210 ) ;
if ( ! V_189 )
continue;
F_77 ( V_41 , V_189 ) ;
V_367 ++ ;
}
return V_367 ;
}
static int F_157 ( struct V_40 * V_41 ,
struct V_12 * V_12 )
{
T_1 * V_348 ;
int V_29 ;
int V_349 = 1 ;
int V_8 = V_6 ;
struct V_363 * V_9 ;
int V_367 = 0 ;
V_348 = F_97 ( V_12 ) ;
if ( ! V_348 )
return 0 ;
V_29 = F_154 ( V_348 , V_8 , V_349 ) ;
if ( V_29 )
return 0 ;
V_349 += sizeof( struct V_350 ) ;
while ( V_9 = (struct V_363 * ) & V_348 [ V_349 ] ,
V_349 + sizeof( struct V_363 ) <= V_8 &&
V_349 + sizeof( struct V_363 ) + V_9 -> V_368 <= V_8 &&
V_9 -> V_368 > 0 ) {
V_349 += V_9 -> V_368 + sizeof( struct V_363 ) ;
switch ( V_9 -> V_369 ) {
case V_370 :
V_367 += F_156 ( V_41 , V_9 ) ;
break;
}
}
return V_367 ;
}
int F_158 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
int V_367 = 0 ;
T_3 V_65 ;
if ( V_12 == NULL ) {
return 0 ;
}
if ( ! F_11 ( V_12 ) ) {
F_16 ( V_41 -> V_46 -> V_46 , L_46 ,
V_41 -> V_39 ) ;
return 0 ;
}
V_65 = F_31 ( V_12 ) ;
V_367 += F_94 ( V_41 , V_12 , V_65 ) ;
V_367 += F_91 ( V_41 , V_12 ) ;
V_367 += F_88 ( V_41 , V_12 ) ;
V_367 += F_86 ( V_41 , V_12 ) ;
V_367 += F_131 ( V_41 , V_12 ) ;
V_367 += F_113 ( V_41 , V_12 ) ;
V_367 += F_157 ( V_41 , V_12 ) ;
if ( V_12 -> V_108 & V_109 )
V_367 += F_83 ( V_41 , V_12 ) ;
if ( V_65 & ( V_74 | V_75 ) )
F_34 ( V_41 , V_65 ) ;
F_153 ( V_41 , V_12 ) ;
if ( V_65 & V_371 )
V_41 -> V_320 . V_322 = 6 ;
if ( V_65 & V_372 )
V_41 -> V_320 . V_322 = 8 ;
if ( V_65 & V_373 )
V_41 -> V_320 . V_322 = 12 ;
return V_367 ;
}
int F_159 ( struct V_40 * V_41 ,
int V_81 , int V_85 )
{
int V_2 , V_297 , V_367 = 0 ;
struct V_66 * V_79 ;
struct V_86 * V_46 = V_41 -> V_46 ;
V_297 = F_32 ( V_91 ) ;
if ( V_81 < 0 )
V_81 = 0 ;
if ( V_85 < 0 )
V_85 = 0 ;
for ( V_2 = 0 ; V_2 < V_297 ; V_2 ++ ) {
const struct V_66 * V_92 = & V_91 [ V_2 ] ;
if ( V_81 && V_85 ) {
if ( V_92 -> V_81 > V_81 ||
V_92 -> V_85 > V_85 )
continue;
}
if ( F_39 ( V_92 ) > 61 )
continue;
V_79 = F_43 ( V_46 , V_92 ) ;
if ( V_79 ) {
F_77 ( V_41 , V_79 ) ;
V_367 ++ ;
}
}
return V_367 ;
}
void F_160 ( struct V_40 * V_41 ,
int V_374 , int V_375 )
{
struct V_66 * V_79 ;
F_59 (mode, &connector->probed_modes, head) {
if ( V_79 -> V_81 == V_374 &&
V_79 -> V_85 == V_375 )
V_79 -> type |= V_77 ;
}
}
int
F_161 ( struct V_376 * V_377 ,
const struct V_66 * V_79 )
{
int V_378 ;
if ( ! V_377 || ! V_79 )
return - V_355 ;
V_378 = F_162 ( V_377 ) ;
if ( V_378 < 0 )
return V_378 ;
if ( V_79 -> V_35 & V_379 )
V_377 -> V_380 = 1 ;
V_377 -> V_235 = F_104 ( V_79 ) ;
V_377 -> V_381 = V_382 ;
if ( V_79 -> V_236 == V_383 ||
V_79 -> V_236 == V_384 )
V_377 -> V_381 = V_79 -> V_236 ;
else if ( V_377 -> V_235 > 0 )
V_377 -> V_381 = F_107 (
V_377 -> V_235 ) ;
V_377 -> V_385 = V_386 ;
V_377 -> V_387 = V_388 ;
return 0 ;
}
void
F_163 ( struct V_376 * V_377 ,
const struct V_66 * V_79 ,
enum V_315 V_389 ,
bool V_390 )
{
if ( V_390 ||
V_389 == F_149 ( V_79 ) )
V_377 -> V_391 = V_389 ;
else
V_377 -> V_391 = V_392 ;
if ( V_389 == V_316 )
V_377 -> V_393 =
V_394 ;
else
V_377 -> V_393 =
V_395 ;
}
static enum V_396
F_164 ( const struct V_66 * V_79 )
{
T_3 V_397 = V_79 -> V_35 & V_241 ;
switch ( V_397 ) {
case V_255 :
return V_398 ;
case V_399 :
return V_400 ;
case V_401 :
return V_402 ;
case V_403 :
return V_404 ;
case V_405 :
return V_406 ;
case V_407 :
return V_408 ;
case V_256 :
return V_409 ;
case V_257 :
return V_410 ;
default:
return V_411 ;
}
}
int
F_165 ( struct V_412 * V_377 ,
const struct V_66 * V_79 )
{
int V_378 ;
T_3 V_413 ;
T_1 V_228 ;
if ( ! V_377 || ! V_79 )
return - V_355 ;
V_228 = F_111 ( V_79 ) ;
V_413 = V_79 -> V_35 & V_241 ;
if ( ! V_228 && ! V_413 )
return - V_355 ;
if ( V_228 && V_413 )
return - V_355 ;
V_378 = F_166 ( V_377 ) ;
if ( V_378 < 0 )
return V_378 ;
if ( V_228 )
V_377 -> V_228 = V_228 ;
else
V_377 -> V_414 = F_164 ( V_79 ) ;
return 0 ;
}
static int F_167 ( struct V_40 * V_41 ,
struct V_363 * V_9 )
{
struct V_415 * V_416 = (struct V_415 * ) V_9 ;
T_5 V_129 , V_130 ;
T_1 V_417 , V_418 ;
T_1 V_419 , V_420 ;
struct V_421 * V_422 ;
V_129 = V_416 -> V_423 [ 0 ] | V_416 -> V_423 [ 1 ] << 8 ;
V_130 = V_416 -> V_423 [ 2 ] | V_416 -> V_423 [ 3 ] << 8 ;
V_419 = ( V_416 -> V_424 [ 0 ] & 0xf ) | ( V_416 -> V_424 [ 2 ] & 0x30 ) ;
V_420 = ( V_416 -> V_424 [ 0 ] >> 4 ) | ( ( V_416 -> V_424 [ 2 ] >> 2 ) & 0x30 ) ;
V_417 = ( V_416 -> V_424 [ 1 ] & 0xf ) | ( ( V_416 -> V_424 [ 2 ] & 0x3 ) << 4 ) ;
V_418 = ( V_416 -> V_424 [ 1 ] >> 4 ) | ( ( ( V_416 -> V_424 [ 2 ] >> 2 ) & 0x3 ) << 4 ) ;
V_41 -> V_425 = true ;
if ( V_416 -> V_426 & 0x80 )
V_41 -> V_427 = true ;
V_41 -> V_420 = V_420 + 1 ;
V_41 -> V_419 = V_419 + 1 ;
V_41 -> V_418 = V_418 ;
V_41 -> V_417 = V_417 ;
V_41 -> V_428 = V_129 + 1 ;
V_41 -> V_429 = V_130 + 1 ;
F_14 ( L_47 , V_416 -> V_426 ) ;
F_14 ( L_48 , V_129 + 1 , V_130 + 1 ) ;
F_14 ( L_49 ,
V_420 + 1 , V_419 + 1 , V_418 , V_417 ) ;
F_14 ( L_50 , V_416 -> V_430 [ 0 ] , V_416 -> V_430 [ 1 ] , V_416 -> V_430 [ 2 ] ) ;
V_422 = F_168 ( V_41 -> V_46 , V_416 -> V_430 ) ;
if ( ! V_422 ) {
V_422 = F_169 ( V_41 -> V_46 , V_416 -> V_430 ) ;
}
if ( ! V_422 )
return - V_301 ;
if ( V_41 -> V_431 != V_422 ) {
if ( V_41 -> V_431 ) {
F_170 ( V_41 -> V_46 , V_41 -> V_431 ) ;
}
V_41 -> V_431 = V_422 ;
} else
F_170 ( V_41 -> V_46 , V_422 ) ;
return 0 ;
}
static int F_171 ( struct V_40 * V_41 ,
T_1 * V_348 , int V_8 ,
bool V_432 )
{
int V_349 = 0 ;
struct V_363 * V_9 ;
int V_29 ;
if ( V_432 )
V_349 = 1 ;
V_29 = F_154 ( V_348 , V_8 , V_349 ) ;
if ( V_29 )
return V_29 ;
V_349 += sizeof( struct V_350 ) ;
while ( V_9 = (struct V_363 * ) & V_348 [ V_349 ] ,
V_349 + sizeof( struct V_363 ) <= V_8 &&
V_349 + sizeof( struct V_363 ) + V_9 -> V_368 <= V_8 &&
V_9 -> V_368 > 0 ) {
V_349 += V_9 -> V_368 + sizeof( struct V_363 ) ;
F_14 ( L_51 ,
V_9 -> V_369 , V_9 -> V_351 , V_9 -> V_368 ) ;
switch ( V_9 -> V_369 ) {
case V_433 :
V_29 = F_167 ( V_41 , V_9 ) ;
if ( V_29 )
return V_29 ;
break;
case V_370 :
break;
default:
F_14 ( L_52 , V_9 -> V_369 ) ;
break;
}
}
return 0 ;
}
static void F_24 ( struct V_40 * V_41 ,
struct V_12 * V_12 )
{
void * V_348 = NULL ;
int V_29 ;
V_41 -> V_425 = false ;
V_348 = F_97 ( V_12 ) ;
if ( ! V_348 ) {
goto V_434;
}
V_29 = F_171 ( V_41 , V_348 , V_6 , true ) ;
if ( V_29 < 0 )
goto V_434;
if ( ! V_41 -> V_425 )
goto V_434;
return;
V_434:
if ( V_41 -> V_431 ) {
F_170 ( V_41 -> V_46 , V_41 -> V_431 ) ;
V_41 -> V_431 = NULL ;
}
return;
}
