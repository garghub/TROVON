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
struct V_12 * F_24 ( struct V_40 * V_41 ,
struct V_24 * V_25 )
{
struct V_53 * V_54 = V_41 -> V_52 -> V_54 ;
struct V_12 * V_12 ;
F_25 ( V_54 ) ;
V_12 = F_22 ( V_41 , V_25 ) ;
F_26 ( V_54 ) ;
return V_12 ;
}
struct V_12 * F_27 ( const struct V_12 * V_12 )
{
return F_28 ( V_12 , ( V_12 -> V_20 + 1 ) * V_6 , V_48 ) ;
}
static bool F_29 ( struct V_12 * V_12 , char * V_55 )
{
char F_29 [ 3 ] ;
F_29 [ 0 ] = ( ( V_12 -> V_56 [ 0 ] & 0x7c ) >> 2 ) + '@' ;
F_29 [ 1 ] = ( ( ( V_12 -> V_56 [ 0 ] & 0x3 ) << 3 ) |
( ( V_12 -> V_56 [ 1 ] & 0xe0 ) >> 5 ) ) + '@' ;
F_29 [ 2 ] = ( V_12 -> V_56 [ 1 ] & 0x1f ) + '@' ;
return ! strncmp ( F_29 , V_55 , 3 ) ;
}
static T_3 F_30 ( struct V_12 * V_12 )
{
struct V_57 * V_58 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_31 ( V_59 ) ; V_2 ++ ) {
V_58 = & V_59 [ V_2 ] ;
if ( F_29 ( V_12 , V_58 -> V_55 ) &&
( F_32 ( V_12 ) == V_58 -> V_60 ) )
return V_58 -> V_61 ;
}
return 0 ;
}
static void F_33 ( struct V_40 * V_41 ,
T_3 V_61 )
{
struct V_62 * V_63 , * V_64 , * V_65 ;
int V_66 = 0 ;
int V_67 , V_68 ;
if ( F_34 ( & V_41 -> V_69 ) )
return;
if ( V_61 & V_70 )
V_66 = 60 ;
if ( V_61 & V_71 )
V_66 = 75 ;
V_65 = F_35 ( & V_41 -> V_69 ,
struct V_62 , V_72 ) ;
F_36 (cur_mode, t, &connector->probed_modes, head) {
V_64 -> type &= ~ V_73 ;
if ( V_64 == V_65 )
continue;
if ( F_37 ( V_64 ) > F_37 ( V_65 ) )
V_65 = V_64 ;
V_67 = V_64 -> V_74 ?
V_64 -> V_74 : F_38 ( V_64 ) ;
V_68 = V_65 -> V_74 ?
V_65 -> V_74 : F_38 ( V_65 ) ;
if ( ( F_37 ( V_64 ) == F_37 ( V_65 ) ) &&
F_39 ( V_67 , V_66 ) <
F_39 ( V_68 , V_66 ) ) {
V_65 = V_64 ;
}
}
V_65 -> type |= V_73 ;
}
static bool
F_40 ( const struct V_62 * V_75 )
{
return ( V_75 -> V_76 - V_75 -> V_77 == 160 ) &&
( V_75 -> V_78 - V_75 -> V_77 == 80 ) &&
( V_75 -> V_78 - V_75 -> V_79 == 32 ) &&
( V_75 -> V_80 - V_75 -> V_81 == 3 ) ;
}
struct V_62 * F_41 ( struct V_82 * V_52 ,
int V_83 , int V_84 , int V_85 ,
bool V_86 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_31 ( V_87 ) ; V_2 ++ ) {
const struct V_62 * V_88 = & V_87 [ V_2 ] ;
if ( V_83 != V_88 -> V_77 )
continue;
if ( V_84 != V_88 -> V_81 )
continue;
if ( V_85 != F_38 ( V_88 ) )
continue;
if ( V_86 != F_40 ( V_88 ) )
continue;
return F_42 ( V_52 , V_88 ) ;
}
return NULL ;
}
static void
F_43 ( T_1 * V_89 , T_4 * V_90 , void * V_91 )
{
int V_2 , V_92 = 0 ;
T_1 V_93 = V_89 [ 0x02 ] ;
T_1 * V_94 = V_89 + V_93 ;
V_92 = ( 127 - V_93 ) / 18 ;
for ( V_2 = 0 ; V_2 < V_92 ; V_2 ++ )
V_90 ( (struct V_95 * ) ( V_94 + 18 * V_2 ) , V_91 ) ;
}
static void
F_44 ( T_1 * V_89 , T_4 * V_90 , void * V_91 )
{
unsigned int V_2 , V_92 = F_45 ( ( int ) V_89 [ 0x02 ] , 6 ) ;
T_1 * V_94 = V_89 + 5 ;
if ( V_89 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_92 ; V_2 ++ )
V_90 ( (struct V_95 * ) ( V_94 + 18 * V_2 ) , V_91 ) ;
}
static void
F_46 ( T_1 * V_1 , T_4 * V_90 , void * V_91 )
{
int V_2 ;
struct V_12 * V_12 = (struct V_12 * ) V_1 ;
if ( V_12 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_96 ; V_2 ++ )
V_90 ( & ( V_12 -> V_97 [ V_2 ] ) , V_91 ) ;
for ( V_2 = 1 ; V_2 <= V_1 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_89 = V_1 + ( V_2 * V_6 ) ;
switch ( * V_89 ) {
case V_98 :
F_43 ( V_89 , V_90 , V_91 ) ;
break;
case V_99 :
F_44 ( V_89 , V_90 , V_91 ) ;
break;
default:
break;
}
}
}
static void
F_47 ( struct V_95 * V_63 , void * V_21 )
{
T_1 * V_100 = ( T_1 * ) V_63 ;
if ( V_100 [ 3 ] == V_101 )
if ( V_100 [ 15 ] & 0x10 )
* ( bool * ) V_21 = true ;
}
static bool
F_48 ( struct V_12 * V_12 )
{
if ( V_12 -> V_16 >= 4 ) {
bool V_29 = false ;
F_46 ( ( T_1 * ) V_12 , F_47 , & V_29 ) ;
return V_29 ;
}
return ( ( V_12 -> V_102 & V_103 ) != 0 ) ;
}
static void
F_49 ( struct V_95 * V_63 , void * V_21 )
{
T_1 * V_100 = ( T_1 * ) V_63 ;
if ( V_100 [ 3 ] == V_101 && V_100 [ 10 ] == 0x02 )
* ( T_1 * * ) V_21 = V_100 ;
}
static int
F_50 ( struct V_12 * V_12 )
{
T_1 * V_100 = NULL ;
F_46 ( ( T_1 * ) V_12 , F_49 , & V_100 ) ;
return V_100 ? ( V_100 [ 12 ] * 2 ) : 0 ;
}
static int
F_51 ( struct V_12 * V_12 )
{
T_1 * V_100 = NULL ;
F_46 ( ( T_1 * ) V_12 , F_49 , & V_100 ) ;
return V_100 ? V_100 [ 13 ] : 0 ;
}
static int
F_52 ( struct V_12 * V_12 )
{
T_1 * V_100 = NULL ;
F_46 ( ( T_1 * ) V_12 , F_49 , & V_100 ) ;
return V_100 ? ( V_100 [ 15 ] << 8 ) + V_100 [ 14 ] : 0 ;
}
static int
F_53 ( struct V_12 * V_12 )
{
T_1 * V_100 = NULL ;
F_46 ( ( T_1 * ) V_12 , F_49 , & V_100 ) ;
return V_100 ? V_100 [ 16 ] : 0 ;
}
static int
F_54 ( struct V_12 * V_12 )
{
T_1 * V_100 = NULL ;
F_46 ( ( T_1 * ) V_12 , F_49 , & V_100 ) ;
return V_100 ? V_100 [ 17 ] : 0 ;
}
static int F_55 ( struct V_12 * V_12 )
{
if ( V_12 -> V_16 >= 2 ) {
if ( V_12 -> V_16 >= 4 && ( V_12 -> V_104 & V_105 ) )
return V_106 ;
if ( F_50 ( V_12 ) )
return V_107 ;
return V_108 ;
}
return V_109 ;
}
static int
F_56 ( T_1 V_110 , T_1 V_111 )
{
return ( V_110 == 0x00 && V_111 == 0x00 ) ||
( V_110 == 0x01 && V_111 == 0x01 ) ||
( V_110 == 0x20 && V_111 == 0x20 ) ;
}
static struct V_62 *
F_57 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_112 * V_63 )
{
struct V_82 * V_52 = V_41 -> V_52 ;
struct V_62 * V_113 , * V_75 = NULL ;
int V_83 , V_84 ;
int V_114 ;
unsigned V_115 = ( V_63 -> V_116 & V_117 )
>> V_118 ;
unsigned V_119 = ( V_63 -> V_116 & V_120 )
>> V_121 ;
int V_122 = F_55 ( V_12 ) ;
if ( F_56 ( V_63 -> V_83 , V_63 -> V_116 ) )
return NULL ;
V_83 = V_63 -> V_83 * 8 + 248 ;
V_114 = V_119 + 60 ;
if ( V_115 == 0 ) {
if ( V_12 -> V_16 < 3 )
V_84 = V_83 ;
else
V_84 = ( V_83 * 10 ) / 16 ;
} else if ( V_115 == 1 )
V_84 = ( V_83 * 3 ) / 4 ;
else if ( V_115 == 2 )
V_84 = ( V_83 * 4 ) / 5 ;
else
V_84 = ( V_83 * 9 ) / 16 ;
if ( V_114 == 60 &&
( ( V_83 == 1360 && V_84 == 765 ) ||
( V_83 == 1368 && V_84 == 769 ) ) ) {
V_83 = 1366 ;
V_84 = 768 ;
}
F_58 (m, &connector->probed_modes, head)
if ( V_113 -> V_77 == V_83 && V_113 -> V_81 == V_84 &&
F_38 ( V_113 ) == V_114 )
return NULL ;
if ( V_83 == 1366 && V_84 == 768 && V_114 == 60 ) {
V_75 = F_59 ( V_52 , 1366 , 768 , V_114 , 0 , 0 ,
false ) ;
V_75 -> V_77 = 1366 ;
V_75 -> V_79 = V_75 -> V_79 - 1 ;
V_75 -> V_78 = V_75 -> V_78 - 1 ;
return V_75 ;
}
if ( F_48 ( V_12 ) ) {
V_75 = F_41 ( V_52 , V_83 , V_84 , V_114 ,
true ) ;
if ( V_75 )
return V_75 ;
}
V_75 = F_41 ( V_52 , V_83 , V_84 , V_114 , false ) ;
if ( V_75 )
return V_75 ;
switch ( V_122 ) {
case V_109 :
break;
case V_108 :
V_75 = F_60 ( V_52 , V_83 , V_84 , V_114 , 0 , 0 ) ;
break;
case V_107 :
V_75 = F_60 ( V_52 , V_83 , V_84 , V_114 , 0 , 0 ) ;
if ( ! V_75 )
return NULL ;
if ( F_61 ( V_75 ) > F_50 ( V_12 ) ) {
F_62 ( V_52 , V_75 ) ;
V_75 = F_63 ( V_52 , V_83 , V_84 ,
V_114 , 0 , 0 ,
F_52 ( V_12 ) ,
F_51 ( V_12 ) ,
F_53 ( V_12 ) ,
F_54 ( V_12 ) ) ;
}
break;
case V_106 :
V_75 = F_59 ( V_52 , V_83 , V_84 , V_114 , 0 , 0 ,
false ) ;
break;
}
return V_75 ;
}
static void
F_64 ( struct V_62 * V_75 ,
struct V_123 * V_124 )
{
int V_2 ;
static const struct {
int V_125 , V_126 ;
} V_127 [] = {
{ 1920 , 1080 } ,
{ 720 , 480 } ,
{ 1440 , 480 } ,
{ 2880 , 480 } ,
{ 720 , 576 } ,
{ 1440 , 576 } ,
{ 2880 , 576 } ,
} ;
if ( ! ( V_124 -> V_128 & V_129 ) )
return;
for ( V_2 = 0 ; V_2 < F_31 ( V_127 ) ; V_2 ++ ) {
if ( ( V_75 -> V_77 == V_127 [ V_2 ] . V_125 ) &&
( V_75 -> V_81 == V_127 [ V_2 ] . V_126 / 2 ) ) {
V_75 -> V_81 *= 2 ;
V_75 -> V_80 *= 2 ;
V_75 -> V_130 *= 2 ;
V_75 -> V_131 *= 2 ;
V_75 -> V_131 |= 1 ;
}
}
V_75 -> V_35 |= V_132 ;
}
static struct V_62 * F_65 ( struct V_82 * V_52 ,
struct V_12 * V_12 ,
struct V_95 * V_133 ,
T_3 V_61 )
{
struct V_62 * V_75 ;
struct V_123 * V_124 = & V_133 -> V_21 . V_134 ;
unsigned V_135 = ( V_124 -> V_136 & 0xf0 ) << 4 | V_124 -> V_137 ;
unsigned V_138 = ( V_124 -> V_139 & 0xf0 ) << 4 | V_124 -> V_140 ;
unsigned V_141 = ( V_124 -> V_136 & 0xf ) << 8 | V_124 -> V_142 ;
unsigned V_143 = ( V_124 -> V_139 & 0xf ) << 8 | V_124 -> V_144 ;
unsigned V_145 = ( V_124 -> V_146 & 0xc0 ) << 2 | V_124 -> V_147 ;
unsigned V_148 = ( V_124 -> V_146 & 0x30 ) << 4 | V_124 -> V_149 ;
unsigned V_150 = ( V_124 -> V_146 & 0xc ) << 2 | V_124 -> V_151 >> 4 ;
unsigned V_152 = ( V_124 -> V_146 & 0x3 ) << 4 | ( V_124 -> V_151 & 0xf ) ;
if ( V_135 < 64 || V_138 < 64 )
return NULL ;
if ( V_124 -> V_128 & V_153 ) {
F_14 ( L_11 ) ;
return NULL ;
}
if ( ! ( V_124 -> V_128 & V_154 ) ) {
F_14 ( L_12 ) ;
}
if ( ! V_148 || ! V_152 ) {
F_14 ( L_13
L_14 ) ;
return NULL ;
}
if ( V_61 & V_155 ) {
V_75 = F_59 ( V_52 , V_135 , V_138 , 60 , true , false , false ) ;
if ( ! V_75 )
return NULL ;
goto V_156;
}
V_75 = F_66 ( V_52 ) ;
if ( ! V_75 )
return NULL ;
if ( V_61 & V_157 )
V_133 -> V_158 = F_67 ( 1088 ) ;
V_75 -> clock = F_68 ( V_133 -> V_158 ) * 10 ;
V_75 -> V_77 = V_135 ;
V_75 -> V_79 = V_75 -> V_77 + V_145 ;
V_75 -> V_78 = V_75 -> V_79 + V_148 ;
V_75 -> V_76 = V_75 -> V_77 + V_141 ;
V_75 -> V_81 = V_138 ;
V_75 -> V_80 = V_75 -> V_81 + V_150 ;
V_75 -> V_130 = V_75 -> V_80 + V_152 ;
V_75 -> V_131 = V_75 -> V_81 + V_143 ;
if ( V_75 -> V_78 > V_75 -> V_76 )
V_75 -> V_76 = V_75 -> V_78 + 1 ;
if ( V_75 -> V_130 > V_75 -> V_131 )
V_75 -> V_131 = V_75 -> V_130 + 1 ;
F_64 ( V_75 , V_124 ) ;
if ( V_61 & V_159 ) {
V_124 -> V_128 |= V_160 | V_161 ;
}
V_75 -> V_35 |= ( V_124 -> V_128 & V_160 ) ?
V_162 : V_163 ;
V_75 -> V_35 |= ( V_124 -> V_128 & V_161 ) ?
V_164 : V_165 ;
V_156:
V_75 -> V_166 = V_124 -> V_167 | ( V_124 -> V_168 & 0xf0 ) << 4 ;
V_75 -> V_169 = V_124 -> V_170 | ( V_124 -> V_168 & 0xf ) << 8 ;
if ( V_61 & V_171 ) {
V_75 -> V_166 *= 10 ;
V_75 -> V_169 *= 10 ;
}
if ( V_61 & V_172 ) {
V_75 -> V_166 = V_12 -> V_173 * 10 ;
V_75 -> V_169 = V_12 -> V_174 * 10 ;
}
V_75 -> type = V_175 ;
V_75 -> V_74 = F_38 ( V_75 ) ;
F_69 ( V_75 ) ;
return V_75 ;
}
static bool
F_70 ( const struct V_62 * V_75 ,
struct V_12 * V_12 , T_1 * V_63 )
{
int V_176 , V_177 , V_178 ;
V_177 = V_63 [ 7 ] ;
if ( V_12 -> V_16 >= 4 )
V_177 += ( ( V_63 [ 4 ] & 0x04 ) ? 255 : 0 ) ;
V_178 = V_63 [ 8 ] ;
if ( V_12 -> V_16 >= 4 )
V_178 += ( ( V_63 [ 4 ] & 0x08 ) ? 255 : 0 ) ;
V_176 = F_61 ( V_75 ) ;
return ( V_176 <= V_178 && V_176 >= V_177 ) ;
}
static bool
F_71 ( const struct V_62 * V_75 ,
struct V_12 * V_12 , T_1 * V_63 )
{
int V_179 , V_180 , V_181 ;
V_180 = V_63 [ 5 ] ;
if ( V_12 -> V_16 >= 4 )
V_180 += ( ( V_63 [ 4 ] & 0x01 ) ? 255 : 0 ) ;
V_181 = V_63 [ 6 ] ;
if ( V_12 -> V_16 >= 4 )
V_181 += ( ( V_63 [ 4 ] & 0x02 ) ? 255 : 0 ) ;
V_179 = F_38 ( V_75 ) ;
return ( V_179 <= V_181 && V_179 >= V_180 ) ;
}
static T_3
F_72 ( struct V_12 * V_12 , T_1 * V_63 )
{
if ( V_63 [ 9 ] == 0 || V_63 [ 9 ] == 255 )
return 0 ;
if ( V_12 -> V_16 >= 4 && V_63 [ 10 ] == 0x04 )
return ( V_63 [ 9 ] * 10000 ) - ( ( V_63 [ 12 ] >> 2 ) * 250 ) ;
return V_63 [ 9 ] * 10000 + 5001 ;
}
static bool
F_73 ( const struct V_62 * V_75 , struct V_12 * V_12 ,
struct V_95 * V_133 )
{
T_3 V_182 ;
T_1 * V_63 = ( T_1 * ) V_133 ;
if ( ! F_70 ( V_75 , V_12 , V_63 ) )
return false ;
if ( ! F_71 ( V_75 , V_12 , V_63 ) )
return false ;
if ( ( V_182 = F_72 ( V_12 , V_63 ) ) )
if ( V_75 -> clock > V_182 )
return false ;
if ( V_12 -> V_16 >= 4 && V_63 [ 10 ] == 0x04 )
if ( V_63 [ 13 ] && V_75 -> V_77 > 8 * ( V_63 [ 13 ] + ( 256 * ( V_63 [ 12 ] & 0x3 ) ) ) )
return false ;
if ( F_40 ( V_75 ) && ! F_48 ( V_12 ) )
return false ;
return true ;
}
static bool F_74 ( const struct V_40 * V_41 ,
const struct V_62 * V_75 )
{
const struct V_62 * V_113 ;
bool V_183 = false ;
F_58 (m, &connector->probed_modes, head) {
if ( V_75 -> V_77 == V_113 -> V_77 &&
V_75 -> V_81 == V_113 -> V_81 &&
F_38 ( V_75 ) == F_38 ( V_113 ) )
return false ;
if ( V_75 -> V_77 <= V_113 -> V_77 &&
V_75 -> V_81 <= V_113 -> V_81 )
V_183 = true ;
}
return V_183 ;
}
static int
F_75 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_95 * V_133 )
{
int V_2 , V_184 = 0 ;
struct V_62 * V_185 ;
struct V_82 * V_52 = V_41 -> V_52 ;
for ( V_2 = 0 ; V_2 < F_31 ( V_87 ) ; V_2 ++ ) {
if ( F_73 ( V_87 + V_2 , V_12 , V_133 ) &&
F_74 ( V_41 , V_87 + V_2 ) ) {
V_185 = F_42 ( V_52 , & V_87 [ V_2 ] ) ;
if ( V_185 ) {
F_76 ( V_41 , V_185 ) ;
V_184 ++ ;
}
}
}
return V_184 ;
}
static void F_77 ( struct V_62 * V_75 )
{
if ( V_75 -> V_77 == 1368 && V_75 -> V_81 == 768 ) {
V_75 -> V_77 = 1366 ;
V_75 -> V_79 -- ;
V_75 -> V_78 -- ;
F_69 ( V_75 ) ;
}
}
static int
F_78 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_95 * V_133 )
{
int V_2 , V_184 = 0 ;
struct V_62 * V_185 ;
struct V_82 * V_52 = V_41 -> V_52 ;
for ( V_2 = 0 ; V_2 < F_31 ( V_186 ) ; V_2 ++ ) {
const struct V_187 * V_113 = & V_186 [ V_2 ] ;
V_185 = F_60 ( V_52 , V_113 -> V_125 , V_113 -> V_126 , V_113 -> V_100 , 0 , 0 ) ;
if ( ! V_185 )
return V_184 ;
F_77 ( V_185 ) ;
if ( ! F_73 ( V_185 , V_12 , V_133 ) ||
! F_74 ( V_41 , V_185 ) ) {
F_62 ( V_52 , V_185 ) ;
continue;
}
F_76 ( V_41 , V_185 ) ;
V_184 ++ ;
}
return V_184 ;
}
static int
F_79 ( struct V_40 * V_41 , struct V_12 * V_12 ,
struct V_95 * V_133 )
{
int V_2 , V_184 = 0 ;
struct V_62 * V_185 ;
struct V_82 * V_52 = V_41 -> V_52 ;
bool V_86 = F_48 ( V_12 ) ;
for ( V_2 = 0 ; V_2 < F_31 ( V_186 ) ; V_2 ++ ) {
const struct V_187 * V_113 = & V_186 [ V_2 ] ;
V_185 = F_59 ( V_52 , V_113 -> V_125 , V_113 -> V_126 , V_113 -> V_100 , V_86 , 0 , 0 ) ;
if ( ! V_185 )
return V_184 ;
F_77 ( V_185 ) ;
if ( ! F_73 ( V_185 , V_12 , V_133 ) ||
! F_74 ( V_41 , V_185 ) ) {
F_62 ( V_52 , V_185 ) ;
continue;
}
F_76 ( V_41 , V_185 ) ;
V_184 ++ ;
}
return V_184 ;
}
static void
F_80 ( struct V_95 * V_133 , void * V_188 )
{
struct V_189 * V_91 = V_188 ;
struct V_190 * V_21 = & V_133 -> V_21 . V_191 ;
struct V_192 * V_193 = & V_21 -> V_21 . V_193 ;
if ( V_21 -> type != V_101 )
return;
V_91 -> V_184 += F_75 ( V_91 -> V_41 ,
V_91 -> V_12 ,
V_133 ) ;
if ( ! F_81 ( V_91 -> V_12 , 1 , 1 ) )
return;
switch ( V_193 -> V_35 ) {
case 0x02 :
case 0x00 :
V_91 -> V_184 += F_78 ( V_91 -> V_41 ,
V_91 -> V_12 ,
V_133 ) ;
break;
case 0x04 :
if ( ! F_81 ( V_91 -> V_12 , 1 , 3 ) )
break;
V_91 -> V_184 += F_79 ( V_91 -> V_41 ,
V_91 -> V_12 ,
V_133 ) ;
break;
case 0x01 :
default:
break;
}
}
static int
F_82 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_189 V_91 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
if ( F_81 ( V_12 , 1 , 0 ) )
F_46 ( ( T_1 * ) V_12 , F_80 ,
& V_91 ) ;
return V_91 . V_184 ;
}
static int
F_83 ( struct V_40 * V_41 , struct V_95 * V_133 )
{
int V_2 , V_42 , V_113 , V_184 = 0 ;
struct V_62 * V_75 ;
T_1 * V_194 = ( ( T_1 * ) V_133 ) + 6 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_42 = 7 ; V_42 >= 0 ; V_42 -- ) {
V_113 = ( V_2 * 8 ) + ( 7 - V_42 ) ;
if ( V_113 >= F_31 ( V_195 ) )
break;
if ( V_194 [ V_2 ] & ( 1 << V_42 ) ) {
V_75 = F_41 ( V_41 -> V_52 ,
V_195 [ V_113 ] . V_125 ,
V_195 [ V_113 ] . V_126 ,
V_195 [ V_113 ] . V_100 ,
V_195 [ V_113 ] . V_86 ) ;
if ( V_75 ) {
F_76 ( V_41 , V_75 ) ;
V_184 ++ ;
}
}
}
}
return V_184 ;
}
static void
F_84 ( struct V_95 * V_133 , void * V_188 )
{
struct V_189 * V_91 = V_188 ;
struct V_190 * V_21 = & V_133 -> V_21 . V_191 ;
if ( V_21 -> type == V_196 )
V_91 -> V_184 += F_83 ( V_91 -> V_41 , V_133 ) ;
}
static int
F_85 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_82 * V_52 = V_41 -> V_52 ;
unsigned long V_197 = V_12 -> V_198 . V_199 |
( V_12 -> V_198 . V_200 << 8 ) |
( ( V_12 -> V_198 . V_201 & 0x80 ) << 9 ) ;
int V_2 , V_184 = 0 ;
struct V_189 V_91 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
for ( V_2 = 0 ; V_2 <= V_202 ; V_2 ++ ) {
if ( V_197 & ( 1 << V_2 ) ) {
struct V_62 * V_185 ;
V_185 = F_42 ( V_52 , & V_203 [ V_2 ] ) ;
if ( V_185 ) {
F_76 ( V_41 , V_185 ) ;
V_184 ++ ;
}
}
}
if ( F_81 ( V_12 , 1 , 0 ) )
F_46 ( ( T_1 * ) V_12 ,
F_84 , & V_91 ) ;
return V_184 + V_91 . V_184 ;
}
static void
F_86 ( struct V_95 * V_133 , void * V_188 )
{
struct V_189 * V_91 = V_188 ;
struct V_190 * V_21 = & V_133 -> V_21 . V_191 ;
struct V_40 * V_41 = V_91 -> V_41 ;
struct V_12 * V_12 = V_91 -> V_12 ;
if ( V_21 -> type == V_204 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_112 * V_205 ;
struct V_62 * V_185 ;
V_205 = & V_21 -> V_21 . V_206 [ V_2 ] ;
V_185 = F_57 ( V_41 , V_12 , V_205 ) ;
if ( V_185 ) {
F_76 ( V_41 , V_185 ) ;
V_91 -> V_184 ++ ;
}
}
}
}
static int
F_87 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
int V_2 , V_184 = 0 ;
struct V_189 V_91 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
for ( V_2 = 0 ; V_2 < V_207 ; V_2 ++ ) {
struct V_62 * V_185 ;
V_185 = F_57 ( V_41 , V_12 ,
& V_12 -> V_208 [ V_2 ] ) ;
if ( V_185 ) {
F_76 ( V_41 , V_185 ) ;
V_184 ++ ;
}
}
if ( F_81 ( V_12 , 1 , 0 ) )
F_46 ( ( T_1 * ) V_12 , F_86 ,
& V_91 ) ;
return V_184 + V_91 . V_184 ;
}
static int F_88 ( struct V_40 * V_41 ,
struct V_95 * V_133 )
{
int V_2 , V_42 , V_184 = 0 ;
struct V_62 * V_185 ;
struct V_82 * V_52 = V_41 -> V_52 ;
struct V_209 * V_210 ;
const int V_211 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_212 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_213 ( V_214 ) , V_215 ;
V_210 = & ( V_133 -> V_21 . V_191 . V_21 . V_210 [ V_2 ] ) ;
if ( ! memcmp ( V_210 -> V_216 , V_212 , 3 ) )
continue;
V_215 = ( V_210 -> V_216 [ 0 ] + ( ( V_210 -> V_216 [ 1 ] & 0xf0 ) << 4 ) + 1 ) * 2 ;
switch ( V_210 -> V_216 [ 1 ] & 0x0c ) {
case 0x00 :
V_214 = V_215 * 4 / 3 ;
break;
case 0x04 :
V_214 = V_215 * 16 / 9 ;
break;
case 0x08 :
V_214 = V_215 * 16 / 10 ;
break;
case 0x0c :
V_214 = V_215 * 15 / 9 ;
break;
}
for ( V_42 = 1 ; V_42 < 5 ; V_42 ++ ) {
if ( V_210 -> V_216 [ 2 ] & ( 1 << V_42 ) ) {
V_185 = F_59 ( V_52 , V_214 , V_215 ,
V_211 [ V_42 ] , V_42 == 0 ,
false , false ) ;
if ( V_185 ) {
F_76 ( V_41 , V_185 ) ;
V_184 ++ ;
}
}
}
}
return V_184 ;
}
static void
F_89 ( struct V_95 * V_133 , void * V_188 )
{
struct V_189 * V_91 = V_188 ;
struct V_190 * V_21 = & V_133 -> V_21 . V_191 ;
if ( V_21 -> type == V_217 )
V_91 -> V_184 += F_88 ( V_91 -> V_41 , V_133 ) ;
}
static int
F_90 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_189 V_91 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
} ;
if ( F_81 ( V_12 , 1 , 2 ) )
F_46 ( ( T_1 * ) V_12 , F_89 , & V_91 ) ;
return V_91 . V_184 ;
}
static void
F_91 ( struct V_95 * V_133 , void * V_188 )
{
struct V_189 * V_91 = V_188 ;
struct V_62 * V_185 ;
if ( V_133 -> V_158 ) {
V_185 = F_65 ( V_91 -> V_41 -> V_52 ,
V_91 -> V_12 , V_133 ,
V_91 -> V_61 ) ;
if ( ! V_185 )
return;
if ( V_91 -> V_218 )
V_185 -> type |= V_73 ;
F_92 ( V_185 ) ;
F_76 ( V_91 -> V_41 , V_185 ) ;
V_91 -> V_184 ++ ;
V_91 -> V_218 = 0 ;
}
}
static int
F_93 ( struct V_40 * V_41 , struct V_12 * V_12 ,
T_3 V_61 )
{
struct V_189 V_91 = {
. V_41 = V_41 ,
. V_12 = V_12 ,
. V_218 = 1 ,
. V_61 = V_61 ,
} ;
if ( V_91 . V_218 && ! F_81 ( V_12 , 1 , 3 ) )
V_91 . V_218 =
( V_12 -> V_104 & V_219 ) ;
F_46 ( ( T_1 * ) V_12 , F_91 , & V_91 ) ;
return V_91 . V_184 ;
}
static T_1 * F_94 ( struct V_12 * V_12 , int V_220 )
{
T_1 * V_221 = NULL ;
int V_2 ;
if ( V_12 == NULL || V_12 -> V_20 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_12 -> V_20 ; V_2 ++ ) {
V_221 = ( T_1 * ) V_12 + V_6 * ( V_2 + 1 ) ;
if ( V_221 [ 0 ] == V_220 )
break;
}
if ( V_2 == V_12 -> V_20 )
return NULL ;
return V_221 ;
}
static T_1 * F_95 ( struct V_12 * V_12 )
{
return F_94 ( V_12 , V_98 ) ;
}
static T_1 * F_96 ( struct V_12 * V_12 )
{
return F_94 ( V_12 , V_222 ) ;
}
static unsigned int
F_97 ( const struct V_62 * V_223 )
{
unsigned int clock = V_223 -> clock ;
if ( V_223 -> V_74 % 6 != 0 )
return clock ;
if ( V_223 -> V_81 == 240 || V_223 -> V_81 == 480 )
clock = F_98 ( clock * 1001 , 1000 ) ;
else
clock = F_98 ( clock * 1000 , 1001 ) ;
return clock ;
}
static T_1 F_99 ( const struct V_62 * V_224 ,
unsigned int V_225 )
{
T_1 V_226 ;
if ( ! V_224 -> clock )
return 0 ;
for ( V_226 = 1 ; V_226 < F_31 ( V_227 ) ; V_226 ++ ) {
const struct V_62 * V_223 = & V_227 [ V_226 ] ;
unsigned int V_228 , V_229 ;
V_228 = V_223 -> clock ;
V_229 = F_97 ( V_223 ) ;
if ( abs ( V_224 -> clock - V_228 ) > V_225 &&
abs ( V_224 -> clock - V_229 ) > V_225 )
continue;
if ( F_100 ( V_224 , V_223 ) )
return V_226 ;
}
return 0 ;
}
T_1 F_101 ( const struct V_62 * V_224 )
{
T_1 V_226 ;
if ( ! V_224 -> clock )
return 0 ;
for ( V_226 = 1 ; V_226 < F_31 ( V_227 ) ; V_226 ++ ) {
const struct V_62 * V_223 = & V_227 [ V_226 ] ;
unsigned int V_228 , V_229 ;
V_228 = V_223 -> clock ;
V_229 = F_97 ( V_223 ) ;
if ( ( F_102 ( V_224 -> clock ) == F_102 ( V_228 ) ||
F_102 ( V_224 -> clock ) == F_102 ( V_229 ) ) &&
F_103 ( V_224 , V_223 ) )
return V_226 ;
}
return 0 ;
}
static bool F_104 ( T_1 V_226 )
{
return V_226 > 0 && V_226 < F_31 ( V_227 ) ;
}
enum V_230 F_105 ( const T_1 V_231 )
{
return V_227 [ V_231 ] . V_232 ;
}
static unsigned int
F_106 ( const struct V_62 * V_233 )
{
if ( V_233 -> V_81 == 4096 && V_233 -> V_77 == 2160 )
return V_233 -> clock ;
return F_97 ( V_233 ) ;
}
static T_1 F_107 ( const struct V_62 * V_224 ,
unsigned int V_225 )
{
T_1 V_226 ;
if ( ! V_224 -> clock )
return 0 ;
for ( V_226 = 1 ; V_226 < F_31 ( V_234 ) ; V_226 ++ ) {
const struct V_62 * V_233 = & V_234 [ V_226 ] ;
unsigned int V_228 , V_229 ;
V_228 = V_233 -> clock ;
V_229 = F_106 ( V_233 ) ;
if ( abs ( V_224 -> clock - V_228 ) > V_225 &&
abs ( V_224 -> clock - V_229 ) > V_225 )
continue;
if ( F_100 ( V_224 , V_233 ) )
return V_226 ;
}
return 0 ;
}
static T_1 F_108 ( const struct V_62 * V_224 )
{
T_1 V_226 ;
if ( ! V_224 -> clock )
return 0 ;
for ( V_226 = 1 ; V_226 < F_31 ( V_234 ) ; V_226 ++ ) {
const struct V_62 * V_233 = & V_234 [ V_226 ] ;
unsigned int V_228 , V_229 ;
V_228 = V_233 -> clock ;
V_229 = F_106 ( V_233 ) ;
if ( ( F_102 ( V_224 -> clock ) == F_102 ( V_228 ) ||
F_102 ( V_224 -> clock ) == F_102 ( V_229 ) ) &&
F_103 ( V_224 , V_233 ) )
return V_226 ;
}
return 0 ;
}
static bool F_109 ( T_1 V_226 )
{
return V_226 > 0 && V_226 < F_31 ( V_234 ) ;
}
static int
F_110 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_82 * V_52 = V_41 -> V_52 ;
struct V_62 * V_75 , * V_235 ;
F_111 ( V_236 ) ;
int V_184 = 0 ;
if ( ! F_95 ( V_12 ) )
return 0 ;
F_58 (mode, &connector->probed_modes, head) {
const struct V_62 * V_223 = NULL ;
struct V_62 * V_185 ;
T_1 V_226 = F_101 ( V_75 ) ;
unsigned int V_228 , V_229 ;
if ( F_104 ( V_226 ) ) {
V_223 = & V_227 [ V_226 ] ;
V_229 = F_97 ( V_223 ) ;
} else {
V_226 = F_108 ( V_75 ) ;
if ( F_109 ( V_226 ) ) {
V_223 = & V_234 [ V_226 ] ;
V_229 = F_106 ( V_223 ) ;
}
}
if ( ! V_223 )
continue;
V_228 = V_223 -> clock ;
if ( V_228 == V_229 )
continue;
if ( V_75 -> clock != V_228 && V_75 -> clock != V_229 )
continue;
V_185 = F_42 ( V_52 , V_223 ) ;
if ( ! V_185 )
continue;
V_185 -> V_35 |= V_75 -> V_35 & V_237 ;
if ( V_75 -> clock != V_228 )
V_185 -> clock = V_228 ;
else
V_185 -> clock = V_229 ;
F_112 ( & V_185 -> V_72 , & V_236 ) ;
}
F_36 (mode, tmp, &list, head) {
F_113 ( & V_75 -> V_72 ) ;
F_76 ( V_41 , V_75 ) ;
V_184 ++ ;
}
return V_184 ;
}
static struct V_62 *
F_114 ( struct V_40 * V_41 ,
const T_1 * V_238 , T_1 V_239 ,
T_1 V_240 )
{
struct V_82 * V_52 = V_41 -> V_52 ;
struct V_62 * V_185 ;
T_1 V_226 ;
if ( V_238 == NULL || V_240 >= V_239 )
return NULL ;
V_226 = ( V_238 [ V_240 ] & 127 ) ;
if ( ! F_104 ( V_226 ) )
return NULL ;
V_185 = F_42 ( V_52 , & V_227 [ V_226 ] ) ;
if ( ! V_185 )
return NULL ;
V_185 -> V_74 = 0 ;
return V_185 ;
}
static int
F_115 ( struct V_40 * V_41 , const T_1 * V_241 , T_1 V_23 )
{
int V_2 , V_184 = 0 ;
for ( V_2 = 0 ; V_2 < V_23 ; V_2 ++ ) {
struct V_62 * V_75 ;
V_75 = F_114 ( V_41 , V_241 , V_23 , V_2 ) ;
if ( V_75 ) {
F_76 ( V_41 , V_75 ) ;
V_184 ++ ;
}
}
return V_184 ;
}
static bool
F_116 ( const struct V_62 * V_75 ,
const struct V_242 * V_243 )
{
unsigned int V_244 = V_75 -> V_35 & V_132 ;
return V_75 -> V_77 == V_243 -> V_214 &&
V_75 -> V_81 == V_243 -> V_215 &&
V_244 == ( V_243 -> V_35 & V_132 ) &&
F_38 ( V_75 ) == V_243 -> V_74 ;
}
static int F_117 ( struct V_40 * V_41 )
{
struct V_82 * V_52 = V_41 -> V_52 ;
const struct V_62 * V_75 ;
struct V_245 V_246 ;
int V_184 = 0 , V_2 ;
F_118 ( & V_246 ) ;
F_58 (mode, &connector->probed_modes, head) {
for ( V_2 = 0 ; V_2 < F_31 ( V_247 ) ; V_2 ++ ) {
const struct V_242 * V_248 ;
struct V_62 * V_249 ;
if ( ! F_116 ( V_75 ,
& V_247 [ V_2 ] ) )
continue;
V_248 = & V_247 [ V_2 ] ;
V_249 = F_42 ( V_52 , V_75 ) ;
if ( ! V_249 )
continue;
V_249 -> V_35 |= V_248 -> V_35 ;
F_112 ( & V_249 -> V_72 , & V_246 ) ;
V_184 ++ ;
}
}
F_119 ( & V_246 , & V_41 -> V_69 ) ;
return V_184 ;
}
static int F_120 ( struct V_40 * V_41 , T_1 V_226 )
{
struct V_82 * V_52 = V_41 -> V_52 ;
struct V_62 * V_185 ;
if ( ! F_109 ( V_226 ) ) {
F_8 ( L_15 , V_226 ) ;
return 0 ;
}
V_185 = F_42 ( V_52 , & V_234 [ V_226 ] ) ;
if ( ! V_185 )
return 0 ;
F_76 ( V_41 , V_185 ) ;
return 1 ;
}
static int F_121 ( struct V_40 * V_41 , T_5 V_250 ,
const T_1 * V_238 , T_1 V_239 , T_1 V_240 )
{
struct V_62 * V_185 ;
int V_184 = 0 ;
if ( V_250 & ( 1 << 0 ) ) {
V_185 = F_114 ( V_41 , V_238 ,
V_239 ,
V_240 ) ;
if ( V_185 ) {
V_185 -> V_35 |= V_251 ;
F_76 ( V_41 , V_185 ) ;
V_184 ++ ;
}
}
if ( V_250 & ( 1 << 6 ) ) {
V_185 = F_114 ( V_41 , V_238 ,
V_239 ,
V_240 ) ;
if ( V_185 ) {
V_185 -> V_35 |= V_252 ;
F_76 ( V_41 , V_185 ) ;
V_184 ++ ;
}
}
if ( V_250 & ( 1 << 8 ) ) {
V_185 = F_114 ( V_41 , V_238 ,
V_239 ,
V_240 ) ;
if ( V_185 ) {
V_185 -> V_35 |= V_253 ;
F_76 ( V_41 , V_185 ) ;
V_184 ++ ;
}
}
return V_184 ;
}
static int
F_122 ( struct V_40 * V_41 , const T_1 * V_241 , T_1 V_23 ,
const T_1 * V_238 , T_1 V_239 )
{
int V_184 = 0 , V_254 = 0 , V_2 , V_255 = 0 , V_256 ;
T_1 V_257 , V_258 = 0 ;
T_5 V_259 ;
T_5 V_260 ;
if ( V_23 < 8 )
goto V_49;
if ( ! ( V_241 [ 8 ] & ( 1 << 5 ) ) )
goto V_49;
if ( V_241 [ 8 ] & ( 1 << 7 ) )
V_254 += 2 ;
if ( V_241 [ 8 ] & ( 1 << 6 ) )
V_254 += 2 ;
if ( V_23 < ( 8 + V_254 + 2 ) )
goto V_49;
V_254 ++ ;
if ( V_241 [ 8 + V_254 ] & ( 1 << 7 ) ) {
V_184 += F_117 ( V_41 ) ;
V_255 = ( V_241 [ 8 + V_254 ] & 0x60 ) >> 5 ;
}
V_254 ++ ;
V_257 = V_241 [ 8 + V_254 ] >> 5 ;
V_258 = V_241 [ 8 + V_254 ] & 0x1f ;
for ( V_2 = 0 ; V_2 < V_257 && V_23 >= ( 9 + V_254 + V_2 ) ; V_2 ++ ) {
T_1 V_226 ;
V_226 = V_241 [ 9 + V_254 + V_2 ] ;
V_184 += F_120 ( V_41 , V_226 ) ;
}
V_254 += 1 + V_257 ;
if ( V_255 == 1 )
V_256 = 2 ;
else if ( V_255 == 2 )
V_256 = 4 ;
else
V_256 = 0 ;
if ( V_23 < ( 8 + V_254 + V_258 - 1 ) )
goto V_49;
if ( V_258 < V_256 )
goto V_49;
if ( V_255 == 1 || V_255 == 2 ) {
V_260 = ( V_241 [ 8 + V_254 ] << 8 ) | V_241 [ 9 + V_254 ] ;
if ( V_255 == 2 )
V_259 = ( V_241 [ 10 + V_254 ] << 8 ) | V_241 [ 11 + V_254 ] ;
else
V_259 = 0xffff ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
if ( V_259 & ( 1 << V_2 ) )
V_184 += F_121 ( V_41 ,
V_260 ,
V_238 ,
V_239 , V_2 ) ;
}
}
V_254 += V_256 ;
for ( V_2 = 0 ; V_2 < ( V_258 - V_256 ) ; V_2 ++ ) {
int V_261 ;
struct V_62 * V_185 = NULL ;
unsigned int V_262 = 0 ;
bool V_263 ;
V_263 = ( ( V_241 [ 8 + V_254 + V_2 ] & 0x0f ) > 7 ) ;
if ( V_263 && ( V_2 + 1 == V_258 - V_256 ) )
break;
V_261 = V_241 [ 8 + V_254 + V_2 ] >> 4 ;
switch ( V_241 [ 8 + V_254 + V_2 ] & 0x0f ) {
case 0 :
V_262 = V_251 ;
break;
case 6 :
V_262 = V_252 ;
break;
case 8 :
if ( ( V_241 [ 9 + V_254 + V_2 ] >> 4 ) == 1 )
V_262 = V_253 ;
break;
}
if ( V_262 != 0 ) {
V_185 = F_114 ( V_41 ,
V_238 ,
V_239 ,
V_261 ) ;
if ( V_185 ) {
V_185 -> V_35 |= V_262 ;
F_76 ( V_41 , V_185 ) ;
V_184 ++ ;
}
}
if ( V_263 )
V_2 ++ ;
}
V_49:
return V_184 ;
}
static int
F_123 ( const T_1 * V_241 )
{
return V_241 [ 0 ] & 0x1f ;
}
static int
F_124 ( const T_1 * V_241 )
{
return V_241 [ 0 ] >> 5 ;
}
static int
F_125 ( const T_1 * V_264 )
{
return V_264 [ 1 ] ;
}
static int
F_126 ( const T_1 * V_264 , int * V_26 , int * V_265 )
{
* V_26 = 4 ;
* V_265 = V_264 [ 2 ] ;
if ( * V_265 == 0 )
* V_265 = 127 ;
if ( * V_265 < 4 || * V_265 > 127 )
return - V_266 ;
return 0 ;
}
static bool F_127 ( const T_1 * V_241 )
{
int V_267 ;
if ( F_124 ( V_241 ) != V_268 )
return false ;
if ( F_123 ( V_241 ) < 5 )
return false ;
V_267 = V_241 [ 1 ] | ( V_241 [ 2 ] << 8 ) | ( V_241 [ 3 ] << 16 ) ;
return V_267 == V_269 ;
}
static int
F_128 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
const T_1 * V_264 = F_95 ( V_12 ) ;
const T_1 * V_241 , * V_270 = NULL , * V_271 = NULL ;
T_1 V_272 , V_273 , V_239 = 0 ;
int V_184 = 0 ;
if ( V_264 && F_125 ( V_264 ) >= 3 ) {
int V_2 , V_26 , V_265 ;
if ( F_126 ( V_264 , & V_26 , & V_265 ) )
return 0 ;
F_129 (cea, i, start, end) {
V_241 = & V_264 [ V_2 ] ;
V_272 = F_123 ( V_241 ) ;
if ( F_124 ( V_241 ) == V_274 ) {
V_271 = V_241 + 1 ;
V_239 = V_272 ;
V_184 += F_115 ( V_41 , V_271 , V_272 ) ;
}
else if ( F_127 ( V_241 ) ) {
V_270 = V_241 ;
V_273 = V_272 ;
}
}
}
if ( V_270 )
V_184 += F_122 ( V_41 , V_270 , V_273 , V_271 ,
V_239 ) ;
return V_184 ;
}
static void F_92 ( struct V_62 * V_75 )
{
const struct V_62 * V_223 ;
int V_228 , V_229 , clock ;
T_1 V_226 ;
const char * type ;
V_226 = F_99 ( V_75 , 5 ) ;
if ( F_104 ( V_226 ) ) {
type = L_16 ;
V_223 = & V_227 [ V_226 ] ;
V_228 = V_223 -> clock ;
V_229 = F_97 ( V_223 ) ;
} else {
V_226 = F_107 ( V_75 , 5 ) ;
if ( F_109 ( V_226 ) ) {
type = L_17 ;
V_223 = & V_234 [ V_226 ] ;
V_228 = V_223 -> clock ;
V_229 = F_106 ( V_223 ) ;
} else {
return;
}
}
if ( abs ( V_75 -> clock - V_228 ) < abs ( V_75 -> clock - V_229 ) )
clock = V_228 ;
else
clock = V_229 ;
if ( V_75 -> clock == clock )
return;
F_7 ( L_18 ,
type , V_226 , V_75 -> clock , clock ) ;
V_75 -> clock = clock ;
}
static void
F_130 ( struct V_40 * V_41 , const T_1 * V_241 )
{
T_1 V_23 = F_123 ( V_241 ) ;
if ( V_23 >= 6 ) {
V_41 -> V_275 [ 5 ] |= ( V_241 [ 6 ] >> 7 ) << 1 ;
V_41 -> V_276 = V_241 [ 6 ] & 1 ;
}
if ( V_23 >= 7 )
V_41 -> V_277 = V_241 [ 7 ] * 5 ;
if ( V_23 >= 8 ) {
V_41 -> V_278 [ 0 ] = V_241 [ 8 ] >> 7 ;
V_41 -> V_278 [ 1 ] = ( V_241 [ 8 ] >> 6 ) & 1 ;
}
if ( V_23 >= 9 )
V_41 -> V_279 [ 0 ] = V_241 [ 9 ] ;
if ( V_23 >= 10 )
V_41 -> V_280 [ 0 ] = V_241 [ 10 ] ;
if ( V_23 >= 11 )
V_41 -> V_279 [ 1 ] = V_241 [ 11 ] ;
if ( V_23 >= 12 )
V_41 -> V_280 [ 1 ] = V_241 [ 12 ] ;
F_14 ( L_19
L_20
L_21
L_22
L_23 ,
V_41 -> V_276 ,
V_41 -> V_277 ,
( int ) V_41 -> V_278 [ 0 ] ,
( int ) V_41 -> V_278 [ 1 ] ,
V_41 -> V_279 [ 0 ] ,
V_41 -> V_279 [ 1 ] ,
V_41 -> V_280 [ 0 ] ,
V_41 -> V_280 [ 1 ] ) ;
}
static void
F_131 ( struct V_95 * V_63 , void * V_21 )
{
if ( V_63 -> V_21 . V_191 . type == V_281 )
* ( T_1 * * ) V_21 = V_63 -> V_21 . V_191 . V_21 . V_282 . V_282 ;
}
void F_132 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
T_6 * V_275 = V_41 -> V_275 ;
T_1 * V_264 ;
T_1 * V_39 ;
T_1 * V_241 ;
int V_283 = 0 ;
int V_284 ;
int V_272 ;
memset ( V_275 , 0 , sizeof( V_41 -> V_275 ) ) ;
V_264 = F_95 ( V_12 ) ;
if ( ! V_264 ) {
F_14 ( L_24 ) ;
return;
}
V_39 = NULL ;
F_46 ( ( T_1 * ) V_12 , F_131 , & V_39 ) ;
for ( V_284 = 0 ; V_39 && V_284 < 13 ; V_284 ++ ) {
if ( V_39 [ V_284 ] == 0x0a )
break;
V_275 [ 20 + V_284 ] = V_39 [ V_284 ] ;
}
V_275 [ 4 ] = ( V_264 [ 1 ] << 5 ) | V_284 ;
F_14 ( L_25 , V_275 + 20 ) ;
V_275 [ 0 ] = 2 << 3 ;
V_275 [ 16 ] = V_12 -> V_56 [ 0 ] ;
V_275 [ 17 ] = V_12 -> V_56 [ 1 ] ;
V_275 [ 18 ] = V_12 -> V_285 [ 0 ] ;
V_275 [ 19 ] = V_12 -> V_285 [ 1 ] ;
if ( F_125 ( V_264 ) >= 3 ) {
int V_2 , V_26 , V_265 ;
if ( F_126 ( V_264 , & V_26 , & V_265 ) ) {
V_26 = 0 ;
V_265 = 0 ;
}
F_129 (cea, i, start, end) {
V_241 = & V_264 [ V_2 ] ;
V_272 = F_123 ( V_241 ) ;
switch ( F_124 ( V_241 ) ) {
int V_286 ;
case V_287 :
V_286 = F_45 ( V_272 / 3 , 15 - V_283 ) ;
if ( V_286 >= 1 )
memcpy ( V_275 + 20 + V_284 + V_283 * 3 ,
& V_241 [ 1 ] , V_286 * 3 ) ;
V_283 += V_286 ;
break;
case V_288 :
if ( V_272 >= 1 )
V_275 [ 7 ] = V_241 [ 1 ] ;
break;
case V_268 :
if ( F_127 ( V_241 ) )
F_130 ( V_41 , V_241 ) ;
break;
default:
break;
}
}
}
V_275 [ 5 ] |= V_283 << 4 ;
V_275 [ V_289 ] =
F_133 ( F_134 ( V_275 ) , 4 ) ;
F_14 ( L_26 ,
F_135 ( V_275 ) , V_283 ) ;
}
int F_136 ( struct V_12 * V_12 , struct V_290 * * V_291 )
{
int V_292 = 0 ;
int V_2 , V_26 , V_265 , V_272 ;
T_1 * V_264 ;
V_264 = F_95 ( V_12 ) ;
if ( ! V_264 ) {
F_14 ( L_27 ) ;
return - V_293 ;
}
if ( F_125 ( V_264 ) < 3 ) {
F_14 ( L_28 ) ;
return - V_294 ;
}
if ( F_126 ( V_264 , & V_26 , & V_265 ) ) {
F_14 ( L_29 ) ;
return - V_295 ;
}
F_129 (cea, i, start, end) {
T_1 * V_241 = & V_264 [ V_2 ] ;
if ( F_124 ( V_241 ) == V_287 ) {
int V_42 ;
V_272 = F_123 ( V_241 ) ;
V_292 = V_272 / 3 ;
* V_291 = F_137 ( V_292 , sizeof( * * V_291 ) , V_48 ) ;
if ( ! * V_291 )
return - V_296 ;
for ( V_42 = 0 ; V_42 < V_292 ; V_42 ++ ) {
T_1 * V_297 = & V_241 [ 1 + V_42 * 3 ] ;
( * V_291 ) [ V_42 ] . V_298 = ( V_297 [ 0 ] & 0x78 ) >> 3 ;
( * V_291 ) [ V_42 ] . V_299 = V_297 [ 0 ] & 0x7 ;
( * V_291 ) [ V_42 ] . V_300 = V_297 [ 1 ] & 0x7F ;
( * V_291 ) [ V_42 ] . V_301 = V_297 [ 2 ] ;
}
break;
}
}
return V_292 ;
}
int F_138 ( struct V_12 * V_12 , T_1 * * V_302 )
{
int V_292 = 0 ;
int V_2 , V_26 , V_265 , V_272 ;
const T_1 * V_264 ;
V_264 = F_95 ( V_12 ) ;
if ( ! V_264 ) {
F_14 ( L_27 ) ;
return - V_293 ;
}
if ( F_125 ( V_264 ) < 3 ) {
F_14 ( L_28 ) ;
return - V_294 ;
}
if ( F_126 ( V_264 , & V_26 , & V_265 ) ) {
F_14 ( L_29 ) ;
return - V_295 ;
}
F_129 (cea, i, start, end) {
const T_1 * V_241 = & V_264 [ V_2 ] ;
if ( F_124 ( V_241 ) == V_288 ) {
V_272 = F_123 ( V_241 ) ;
if ( V_272 == 3 ) {
* V_302 = F_28 ( & V_241 [ 1 ] , V_272 , V_48 ) ;
if ( ! * V_302 )
return - V_296 ;
V_292 = V_272 ;
break;
}
}
}
return V_292 ;
}
int F_139 ( struct V_40 * V_41 ,
const struct V_62 * V_75 )
{
int V_2 = ! ! ( V_75 -> V_35 & V_132 ) ;
int V_110 , V_303 ;
if ( ! V_41 -> V_278 [ 0 ] )
return 0 ;
if ( ! V_41 -> V_278 [ 1 ] )
V_2 = 0 ;
V_110 = V_41 -> V_280 [ V_2 ] ;
V_303 = V_41 -> V_279 [ V_2 ] ;
if ( V_110 == 255 || V_303 == 255 )
return 0 ;
if ( V_110 )
V_110 = F_45 ( 2 * ( V_110 - 1 ) , 500 ) ;
if ( V_303 )
V_303 = F_45 ( 2 * ( V_303 - 1 ) , 500 ) ;
return F_140 ( V_303 - V_110 , 0 ) ;
}
struct V_40 * F_141 ( struct V_304 * V_305 )
{
struct V_40 * V_41 ;
struct V_82 * V_52 = V_305 -> V_52 ;
F_6 ( ! F_142 ( & V_52 -> V_306 . V_307 ) ) ;
F_6 ( ! F_143 ( & V_52 -> V_306 . V_308 ) ) ;
F_144 (connector, dev)
if ( V_41 -> V_305 == V_305 && V_41 -> V_275 [ 0 ] )
return V_41 ;
return NULL ;
}
bool F_145 ( struct V_12 * V_12 )
{
T_1 * V_221 ;
int V_2 ;
int V_309 , V_310 ;
V_221 = F_95 ( V_12 ) ;
if ( ! V_221 )
return false ;
if ( F_126 ( V_221 , & V_309 , & V_310 ) )
return false ;
F_129 (edid_ext, i, start_offset, end_offset) {
if ( F_127 ( & V_221 [ V_2 ] ) )
return true ;
}
return false ;
}
bool F_146 ( struct V_12 * V_12 )
{
T_1 * V_221 ;
int V_2 , V_42 ;
bool V_311 = false ;
int V_309 , V_310 ;
V_221 = F_95 ( V_12 ) ;
if ( ! V_221 )
goto V_265;
V_311 = ( ( V_221 [ 3 ] & V_312 ) != 0 ) ;
if ( V_311 ) {
F_14 ( L_30 ) ;
goto V_265;
}
if ( F_126 ( V_221 , & V_309 , & V_310 ) )
goto V_265;
F_129 (edid_ext, i, start_offset, end_offset) {
if ( F_124 ( & V_221 [ V_2 ] ) == V_287 ) {
V_311 = true ;
for ( V_42 = 1 ; V_42 < F_123 ( & V_221 [ V_2 ] ) + 1 ; V_42 += 3 )
F_14 ( L_31 ,
( V_221 [ V_2 + V_42 ] >> 3 ) & 0xf ) ;
goto V_265;
}
}
V_265:
return V_311 ;
}
bool F_147 ( struct V_12 * V_12 )
{
T_1 * V_221 ;
int V_2 , V_26 , V_265 ;
V_221 = F_95 ( V_12 ) ;
if ( ! V_221 )
return false ;
if ( F_126 ( V_221 , & V_26 , & V_265 ) )
return false ;
F_129 (edid_ext, i, start, end) {
if ( F_124 ( & V_221 [ V_2 ] ) == V_313 &&
F_123 ( & V_221 [ V_2 ] ) == 2 ) {
F_14 ( L_32 , V_221 [ V_2 + 2 ] ) ;
return V_221 [ V_2 + 2 ] & V_314 ;
}
}
return false ;
}
static bool F_148 ( struct V_12 * V_12 ,
struct V_315 * V_316 ,
struct V_40 * V_41 )
{
T_1 * V_221 , * V_270 ;
int V_2 ;
int V_309 , V_310 ;
unsigned int V_317 = 0 ;
V_221 = F_95 ( V_12 ) ;
if ( ! V_221 )
return false ;
if ( F_126 ( V_221 , & V_309 , & V_310 ) )
return false ;
F_129 (edid_ext, i, start_offset, end_offset) {
if ( F_127 ( & V_221 [ V_2 ] ) ) {
V_316 -> V_318 = 8 ;
V_270 = & V_221 [ V_2 ] ;
if ( F_123 ( V_270 ) < 6 )
return false ;
if ( V_270 [ 6 ] & V_319 ) {
V_317 = 10 ;
V_316 -> V_320 |= V_319 ;
F_7 ( L_33 ,
V_41 -> V_39 ) ;
}
if ( V_270 [ 6 ] & V_321 ) {
V_317 = 12 ;
V_316 -> V_320 |= V_321 ;
F_7 ( L_34 ,
V_41 -> V_39 ) ;
}
if ( V_270 [ 6 ] & V_322 ) {
V_317 = 16 ;
V_316 -> V_320 |= V_322 ;
F_7 ( L_35 ,
V_41 -> V_39 ) ;
}
if ( V_317 > 0 ) {
F_7 ( L_36 ,
V_41 -> V_39 , V_317 ) ;
V_316 -> V_318 = V_317 ;
V_316 -> V_323 = V_324 ;
if ( V_270 [ 6 ] & V_325 ) {
V_316 -> V_323 |= V_326 ;
F_7 ( L_37 ,
V_41 -> V_39 ) ;
}
if ( ! ( V_270 [ 6 ] & V_321 ) ) {
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
static void F_149 ( struct V_12 * V_12 ,
struct V_315 * V_316 ,
struct V_40 * V_41 )
{
T_1 * V_221 ;
V_316 -> V_166 = V_12 -> V_173 * 10 ;
V_316 -> V_169 = V_12 -> V_174 * 10 ;
V_316 -> V_318 = 0 ;
V_316 -> V_323 = 0 ;
if ( V_12 -> V_16 < 3 )
return;
if ( ! ( V_12 -> V_102 & V_103 ) )
return;
V_221 = F_95 ( V_12 ) ;
if ( V_221 ) {
V_316 -> V_327 = V_221 [ 1 ] ;
V_316 -> V_323 = V_324 ;
if ( V_221 [ 3 ] & V_328 )
V_316 -> V_323 |= V_326 ;
if ( V_221 [ 3 ] & V_329 )
V_316 -> V_323 |= V_330 ;
}
F_148 ( V_12 , V_316 , V_41 ) ;
if ( V_12 -> V_16 < 4 )
return;
switch ( V_12 -> V_102 & V_331 ) {
case V_332 :
V_316 -> V_318 = 6 ;
break;
case V_333 :
V_316 -> V_318 = 8 ;
break;
case V_334 :
V_316 -> V_318 = 10 ;
break;
case V_335 :
V_316 -> V_318 = 12 ;
break;
case V_336 :
V_316 -> V_318 = 14 ;
break;
case V_337 :
V_316 -> V_318 = 16 ;
break;
case V_338 :
default:
V_316 -> V_318 = 0 ;
break;
}
F_7 ( L_40 ,
V_41 -> V_39 , V_316 -> V_318 ) ;
V_316 -> V_323 |= V_324 ;
if ( V_12 -> V_104 & V_339 )
V_316 -> V_323 |= V_326 ;
if ( V_12 -> V_104 & V_340 )
V_316 -> V_323 |= V_330 ;
}
int F_150 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
int V_341 = 0 ;
T_3 V_61 ;
if ( V_12 == NULL ) {
return 0 ;
}
if ( ! F_11 ( V_12 ) ) {
F_19 ( V_41 -> V_52 -> V_52 , L_41 ,
V_41 -> V_39 ) ;
return 0 ;
}
V_61 = F_30 ( V_12 ) ;
V_341 += F_93 ( V_41 , V_12 , V_61 ) ;
V_341 += F_90 ( V_41 , V_12 ) ;
V_341 += F_87 ( V_41 , V_12 ) ;
V_341 += F_85 ( V_41 , V_12 ) ;
V_341 += F_128 ( V_41 , V_12 ) ;
V_341 += F_110 ( V_41 , V_12 ) ;
if ( V_12 -> V_104 & V_105 )
V_341 += F_82 ( V_41 , V_12 ) ;
if ( V_61 & ( V_70 | V_71 ) )
F_33 ( V_41 , V_61 ) ;
F_149 ( V_12 , & V_41 -> V_342 , V_41 ) ;
if ( V_61 & V_343 )
V_41 -> V_342 . V_318 = 8 ;
if ( V_61 & V_344 )
V_41 -> V_342 . V_318 = 12 ;
return V_341 ;
}
int F_151 ( struct V_40 * V_41 ,
int V_77 , int V_81 )
{
int V_2 , V_292 , V_341 = 0 ;
struct V_62 * V_75 ;
struct V_82 * V_52 = V_41 -> V_52 ;
V_292 = F_31 ( V_87 ) ;
if ( V_77 < 0 )
V_77 = 0 ;
if ( V_81 < 0 )
V_81 = 0 ;
for ( V_2 = 0 ; V_2 < V_292 ; V_2 ++ ) {
const struct V_62 * V_88 = & V_87 [ V_2 ] ;
if ( V_77 && V_81 ) {
if ( V_88 -> V_77 > V_77 ||
V_88 -> V_81 > V_81 )
continue;
}
if ( F_38 ( V_88 ) > 61 )
continue;
V_75 = F_42 ( V_52 , V_88 ) ;
if ( V_75 ) {
F_76 ( V_41 , V_75 ) ;
V_341 ++ ;
}
}
return V_341 ;
}
void F_152 ( struct V_40 * V_41 ,
int V_345 , int V_346 )
{
struct V_62 * V_75 ;
F_58 (mode, &connector->probed_modes, head) {
if ( V_75 -> V_77 == V_345 &&
V_75 -> V_81 == V_346 )
V_75 -> type |= V_73 ;
}
}
int
F_153 ( struct V_347 * V_348 ,
const struct V_62 * V_75 )
{
int V_349 ;
if ( ! V_348 || ! V_75 )
return - V_350 ;
V_349 = F_154 ( V_348 ) ;
if ( V_349 < 0 )
return V_349 ;
if ( V_75 -> V_35 & V_351 )
V_348 -> V_352 = 1 ;
V_348 -> V_231 = F_101 ( V_75 ) ;
V_348 -> V_353 = V_354 ;
if ( V_75 -> V_232 == V_355 ||
V_75 -> V_232 == V_356 )
V_348 -> V_353 = V_75 -> V_232 ;
else if ( V_348 -> V_231 > 0 )
V_348 -> V_353 = F_105 (
V_348 -> V_231 ) ;
V_348 -> V_357 = V_358 ;
V_348 -> V_359 = V_360 ;
return 0 ;
}
static enum V_361
F_155 ( const struct V_62 * V_75 )
{
T_3 V_362 = V_75 -> V_35 & V_237 ;
switch ( V_362 ) {
case V_251 :
return V_363 ;
case V_364 :
return V_365 ;
case V_366 :
return V_367 ;
case V_368 :
return V_369 ;
case V_370 :
return V_371 ;
case V_372 :
return V_373 ;
case V_252 :
return V_374 ;
case V_253 :
return V_375 ;
default:
return V_376 ;
}
}
int
F_156 ( struct V_377 * V_348 ,
const struct V_62 * V_75 )
{
int V_349 ;
T_3 V_378 ;
T_1 V_226 ;
if ( ! V_348 || ! V_75 )
return - V_350 ;
V_226 = F_108 ( V_75 ) ;
V_378 = V_75 -> V_35 & V_237 ;
if ( ! V_226 && ! V_378 )
return - V_350 ;
if ( V_226 && V_378 )
return - V_350 ;
V_349 = F_157 ( V_348 ) ;
if ( V_349 < 0 )
return V_349 ;
if ( V_226 )
V_348 -> V_226 = V_226 ;
else
V_348 -> V_379 = F_155 ( V_75 ) ;
return 0 ;
}
static int F_158 ( struct V_40 * V_41 ,
T_1 * V_380 , int V_8 ,
bool V_381 )
{
int V_382 = 0 ;
struct V_383 * V_384 ;
struct V_385 * V_9 ;
T_1 V_5 = 0 ;
int V_2 ;
if ( V_381 )
V_382 = 1 ;
V_384 = (struct V_383 * ) & V_380 [ V_382 ] ;
F_14 ( L_42 ,
V_384 -> V_386 , V_384 -> V_387 , V_384 -> V_388 , V_384 -> V_389 ) ;
if ( V_384 -> V_387 + 5 > V_8 - V_382 )
return - V_350 ;
for ( V_2 = V_382 ; V_2 <= V_384 -> V_387 + 5 ; V_2 ++ ) {
V_5 += V_380 [ V_2 ] ;
}
if ( V_5 ) {
F_8 ( L_43 , V_5 ) ;
return - V_350 ;
}
V_9 = (struct V_385 * ) & V_380 [ V_382 + 4 ] ;
F_14 ( L_44 ,
V_9 -> V_390 , V_9 -> V_386 , V_9 -> V_391 ) ;
switch ( V_9 -> V_390 ) {
case V_392 : {
struct V_393 * V_394 = (struct V_393 * ) V_9 ;
T_5 V_125 , V_126 ;
T_1 V_395 , V_396 ;
T_1 V_397 , V_398 ;
struct V_399 * V_400 ;
V_125 = V_394 -> V_401 [ 0 ] | V_394 -> V_401 [ 1 ] << 8 ;
V_126 = V_394 -> V_401 [ 2 ] | V_394 -> V_401 [ 3 ] << 8 ;
V_397 = ( V_394 -> V_402 [ 0 ] & 0xf ) | ( V_394 -> V_402 [ 2 ] & 0x30 ) ;
V_398 = ( V_394 -> V_402 [ 0 ] >> 4 ) | ( ( V_394 -> V_402 [ 2 ] >> 2 ) & 0x30 ) ;
V_395 = ( V_394 -> V_402 [ 1 ] & 0xf ) | ( ( V_394 -> V_402 [ 2 ] & 0x3 ) << 4 ) ;
V_396 = ( V_394 -> V_402 [ 1 ] >> 4 ) | ( ( ( V_394 -> V_402 [ 2 ] >> 2 ) & 0x3 ) << 4 ) ;
V_41 -> V_403 = true ;
if ( V_394 -> V_404 & 0x80 )
V_41 -> V_405 = true ;
V_41 -> V_398 = V_398 + 1 ;
V_41 -> V_397 = V_397 + 1 ;
V_41 -> V_396 = V_396 ;
V_41 -> V_395 = V_395 ;
V_41 -> V_406 = V_125 + 1 ;
V_41 -> V_407 = V_126 + 1 ;
F_14 ( L_45 , V_394 -> V_404 ) ;
F_14 ( L_46 , V_125 + 1 , V_126 + 1 ) ;
F_14 ( L_47 ,
V_398 + 1 , V_397 + 1 , V_396 , V_395 ) ;
F_14 ( L_48 , V_394 -> V_408 [ 0 ] , V_394 -> V_408 [ 1 ] , V_394 -> V_408 [ 2 ] ) ;
V_400 = F_159 ( V_41 -> V_52 , V_394 -> V_408 ) ;
if ( ! V_400 ) {
V_400 = F_160 ( V_41 -> V_52 , V_394 -> V_408 ) ;
}
if ( ! V_400 )
return - V_296 ;
if ( V_41 -> V_409 != V_400 ) {
if ( V_41 -> V_409 ) {
F_161 ( V_41 -> V_52 , V_41 -> V_409 ) ;
}
V_41 -> V_409 = V_400 ;
} else
F_161 ( V_41 -> V_52 , V_400 ) ;
}
break;
default:
F_9 ( L_49 , V_9 -> V_390 ) ;
break;
}
return 0 ;
}
static void F_23 ( struct V_40 * V_41 ,
struct V_12 * V_12 )
{
void * V_380 = NULL ;
int V_29 ;
V_41 -> V_403 = false ;
V_380 = F_96 ( V_12 ) ;
if ( ! V_380 ) {
goto V_410;
}
V_29 = F_158 ( V_41 , V_380 , V_6 , true ) ;
if ( V_29 < 0 )
goto V_410;
if ( ! V_41 -> V_403 )
goto V_410;
return;
V_410:
if ( V_41 -> V_409 ) {
F_161 ( V_41 -> V_52 , V_41 -> V_409 ) ;
V_41 -> V_409 = NULL ;
}
return;
}
