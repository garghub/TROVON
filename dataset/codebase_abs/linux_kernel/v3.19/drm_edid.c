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
bool F_5 ( T_1 * V_1 , int V_9 , bool V_10 )
{
T_1 V_5 ;
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
if ( F_6 ( ! V_1 ) )
return false ;
if ( V_12 > 8 || V_12 < 0 )
V_12 = 6 ;
if ( V_9 == 0 ) {
int V_3 = F_1 ( V_1 ) ;
if ( V_3 == 8 ) ;
else if ( V_3 >= V_12 ) {
F_7 ( L_1 ) ;
memcpy ( V_1 , V_4 , sizeof( V_4 ) ) ;
} else {
goto V_13;
}
}
V_5 = F_2 ( V_1 ) ;
if ( V_5 ) {
if ( V_10 ) {
F_8 ( L_2 , V_5 ) ;
}
if ( V_1 [ 0 ] != 0x02 )
goto V_13;
}
switch ( V_1 [ 0 ] ) {
case 0 :
if ( V_11 -> V_14 != 1 ) {
F_8 ( L_3 , V_11 -> V_14 ) ;
goto V_13;
}
if ( V_11 -> V_15 > 4 )
F_7 ( L_4 ) ;
break;
default:
break;
}
return true ;
V_13:
if ( V_10 ) {
if ( F_3 ( V_1 , V_6 ) ) {
F_9 ( V_16 L_5 ) ;
} else {
F_9 ( V_16 L_6 ) ;
F_10 ( V_16 , L_7 , V_17 , 16 , 1 ,
V_1 , V_6 , false ) ;
}
}
return false ;
}
bool F_11 ( struct V_11 * V_11 )
{
int V_2 ;
T_1 * V_18 = ( T_1 * ) V_11 ;
if ( ! V_11 )
return false ;
for ( V_2 = 0 ; V_2 <= V_11 -> V_19 ; V_2 ++ )
if ( ! F_5 ( V_18 + V_2 * V_6 , V_2 , true ) )
return false ;
return true ;
}
static int
F_12 ( void * V_20 , T_1 * V_21 , unsigned int V_9 , T_2 V_22 )
{
struct V_23 * V_24 = V_20 ;
unsigned char V_25 = V_9 * V_6 ;
unsigned char V_26 = V_9 >> 1 ;
unsigned char V_27 = V_26 ? 3 : 2 ;
int V_28 , V_29 = 5 ;
do {
struct V_30 V_31 [] = {
{
. V_32 = V_33 ,
. V_34 = 0 ,
. V_22 = 1 ,
. V_21 = & V_26 ,
} , {
. V_32 = V_35 ,
. V_34 = 0 ,
. V_22 = 1 ,
. V_21 = & V_25 ,
} , {
. V_32 = V_35 ,
. V_34 = V_36 ,
. V_22 = V_22 ,
. V_21 = V_21 ,
}
} ;
V_28 = F_13 ( V_24 , & V_31 [ 3 - V_27 ] , V_27 ) ;
if ( V_28 == - V_37 ) {
F_14 ( L_8 ,
V_24 -> V_38 ) ;
break;
}
} while ( V_28 != V_27 && -- V_29 );
return V_28 == V_27 ? 0 : - 1 ;
}
struct V_11 * F_15 ( struct V_39 * V_40 ,
int (* F_16)( void * V_20 , T_1 * V_21 , unsigned int V_9 ,
T_2 V_22 ) ,
void * V_20 )
{
int V_2 , V_41 = 0 , V_42 = 0 ;
T_1 * V_9 , * V_43 ;
bool V_10 = ! V_40 -> V_44 || ( V_45 & V_46 ) ;
if ( ( V_9 = F_17 ( V_6 , V_47 ) ) == NULL )
return NULL ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_16 ( V_20 , V_9 , 0 , V_6 ) )
goto V_48;
if ( F_5 ( V_9 , 0 , V_10 ) )
break;
if ( V_2 == 0 && F_3 ( V_9 , V_6 ) ) {
V_40 -> V_49 ++ ;
goto V_50;
}
}
if ( V_2 == 4 )
goto V_50;
if ( V_9 [ 0x7e ] == 0 )
return (struct V_11 * ) V_9 ;
V_43 = F_18 ( V_9 , ( V_9 [ 0x7e ] + 1 ) * V_6 , V_47 ) ;
if ( ! V_43 )
goto V_48;
V_9 = V_43 ;
for ( V_41 = 1 ; V_41 <= V_9 [ 0x7e ] ; V_41 ++ ) {
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
if ( F_16 ( V_20 ,
V_9 + ( V_42 + 1 ) * V_6 ,
V_41 , V_6 ) )
goto V_48;
if ( F_5 ( V_9 + ( V_42 + 1 ) * V_6 , V_41 , V_10 ) ) {
V_42 ++ ;
break;
}
}
if ( V_2 == 4 && V_10 ) {
F_19 ( V_40 -> V_51 -> V_51 ,
L_9 ,
V_40 -> V_38 , V_41 ) ;
V_40 -> V_44 ++ ;
}
}
if ( V_42 != V_9 [ 0x7e ] ) {
V_9 [ V_6 - 1 ] += V_9 [ 0x7e ] - V_42 ;
V_9 [ 0x7e ] = V_42 ;
V_43 = F_18 ( V_9 , ( V_42 + 1 ) * V_6 , V_47 ) ;
if ( ! V_43 )
goto V_48;
V_9 = V_43 ;
}
return (struct V_11 * ) V_9 ;
V_50:
if ( V_10 ) {
F_19 ( V_40 -> V_51 -> V_51 , L_10 ,
V_40 -> V_38 , V_41 ) ;
}
V_40 -> V_44 ++ ;
V_48:
F_20 ( V_9 ) ;
return NULL ;
}
bool
F_21 ( struct V_23 * V_24 )
{
unsigned char V_48 ;
return ( F_12 ( V_24 , & V_48 , 0 , 1 ) == 0 ) ;
}
struct V_11 * F_22 ( struct V_39 * V_40 ,
struct V_23 * V_24 )
{
struct V_11 * V_11 ;
if ( ! F_21 ( V_24 ) )
return NULL ;
V_11 = F_15 ( V_40 , F_12 , V_24 ) ;
if ( V_11 )
F_23 ( V_40 , V_11 ) ;
return V_11 ;
}
struct V_11 * F_24 ( const struct V_11 * V_11 )
{
return F_25 ( V_11 , ( V_11 -> V_19 + 1 ) * V_6 , V_47 ) ;
}
static bool F_26 ( struct V_11 * V_11 , char * V_52 )
{
char F_26 [ 3 ] ;
F_26 [ 0 ] = ( ( V_11 -> V_53 [ 0 ] & 0x7c ) >> 2 ) + '@' ;
F_26 [ 1 ] = ( ( ( V_11 -> V_53 [ 0 ] & 0x3 ) << 3 ) |
( ( V_11 -> V_53 [ 1 ] & 0xe0 ) >> 5 ) ) + '@' ;
F_26 [ 2 ] = ( V_11 -> V_53 [ 1 ] & 0x1f ) + '@' ;
return ! strncmp ( F_26 , V_52 , 3 ) ;
}
static T_3 F_27 ( struct V_11 * V_11 )
{
struct V_54 * V_55 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_28 ( V_56 ) ; V_2 ++ ) {
V_55 = & V_56 [ V_2 ] ;
if ( F_26 ( V_11 , V_55 -> V_52 ) &&
( F_29 ( V_11 ) == V_55 -> V_57 ) )
return V_55 -> V_58 ;
}
return 0 ;
}
static void F_30 ( struct V_39 * V_40 ,
T_3 V_58 )
{
struct V_59 * V_60 , * V_61 , * V_62 ;
int V_63 = 0 ;
int V_64 , V_65 ;
if ( F_31 ( & V_40 -> V_66 ) )
return;
if ( V_58 & V_67 )
V_63 = 60 ;
if ( V_58 & V_68 )
V_63 = 75 ;
V_62 = F_32 ( & V_40 -> V_66 ,
struct V_59 , V_69 ) ;
F_33 (cur_mode, t, &connector->probed_modes, head) {
V_61 -> type &= ~ V_70 ;
if ( V_61 == V_62 )
continue;
if ( F_34 ( V_61 ) > F_34 ( V_62 ) )
V_62 = V_61 ;
V_64 = V_61 -> V_71 ?
V_61 -> V_71 : F_35 ( V_61 ) ;
V_65 = V_62 -> V_71 ?
V_62 -> V_71 : F_35 ( V_62 ) ;
if ( ( F_34 ( V_61 ) == F_34 ( V_62 ) ) &&
F_36 ( V_64 , V_63 ) <
F_36 ( V_65 , V_63 ) ) {
V_62 = V_61 ;
}
}
V_62 -> type |= V_70 ;
}
static bool
F_37 ( const struct V_59 * V_72 )
{
return ( V_72 -> V_73 - V_72 -> V_74 == 160 ) &&
( V_72 -> V_75 - V_72 -> V_74 == 80 ) &&
( V_72 -> V_75 - V_72 -> V_76 == 32 ) &&
( V_72 -> V_77 - V_72 -> V_78 == 3 ) ;
}
struct V_59 * F_38 ( struct V_79 * V_51 ,
int V_80 , int V_81 , int V_82 ,
bool V_83 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_28 ( V_84 ) ; V_2 ++ ) {
const struct V_59 * V_85 = & V_84 [ V_2 ] ;
if ( V_80 != V_85 -> V_74 )
continue;
if ( V_81 != V_85 -> V_78 )
continue;
if ( V_82 != F_35 ( V_85 ) )
continue;
if ( V_83 != F_37 ( V_85 ) )
continue;
return F_39 ( V_51 , V_85 ) ;
}
return NULL ;
}
static void
F_40 ( T_1 * V_86 , T_4 * V_87 , void * V_88 )
{
int V_2 , V_89 = 0 ;
T_1 V_90 = V_86 [ 0x02 ] ;
T_1 * V_91 = V_86 + V_90 ;
V_89 = ( 127 - V_90 ) / 18 ;
for ( V_2 = 0 ; V_2 < V_89 ; V_2 ++ )
V_87 ( (struct V_92 * ) ( V_91 + 18 * V_2 ) , V_88 ) ;
}
static void
F_41 ( T_1 * V_86 , T_4 * V_87 , void * V_88 )
{
unsigned int V_2 , V_89 = F_42 ( ( int ) V_86 [ 0x02 ] , 6 ) ;
T_1 * V_91 = V_86 + 5 ;
if ( V_86 [ 0x01 ] != 1 )
return;
for ( V_2 = 0 ; V_2 < V_89 ; V_2 ++ )
V_87 ( (struct V_92 * ) ( V_91 + 18 * V_2 ) , V_88 ) ;
}
static void
F_43 ( T_1 * V_1 , T_4 * V_87 , void * V_88 )
{
int V_2 ;
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
if ( V_11 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_93 ; V_2 ++ )
V_87 ( & ( V_11 -> V_94 [ V_2 ] ) , V_88 ) ;
for ( V_2 = 1 ; V_2 <= V_1 [ 0x7e ] ; V_2 ++ ) {
T_1 * V_86 = V_1 + ( V_2 * V_6 ) ;
switch ( * V_86 ) {
case V_95 :
F_40 ( V_86 , V_87 , V_88 ) ;
break;
case V_96 :
F_41 ( V_86 , V_87 , V_88 ) ;
break;
default:
break;
}
}
}
static void
F_44 ( struct V_92 * V_60 , void * V_20 )
{
T_1 * V_97 = ( T_1 * ) V_60 ;
if ( V_97 [ 3 ] == V_98 )
if ( V_97 [ 15 ] & 0x10 )
* ( bool * ) V_20 = true ;
}
static bool
F_45 ( struct V_11 * V_11 )
{
if ( V_11 -> V_15 >= 4 ) {
bool V_28 = false ;
F_43 ( ( T_1 * ) V_11 , F_44 , & V_28 ) ;
return V_28 ;
}
return ( ( V_11 -> V_99 & V_100 ) != 0 ) ;
}
static void
F_46 ( struct V_92 * V_60 , void * V_20 )
{
T_1 * V_97 = ( T_1 * ) V_60 ;
if ( V_97 [ 3 ] == V_98 && V_97 [ 10 ] == 0x02 )
* ( T_1 * * ) V_20 = V_97 ;
}
static int
F_47 ( struct V_11 * V_11 )
{
T_1 * V_97 = NULL ;
F_43 ( ( T_1 * ) V_11 , F_46 , & V_97 ) ;
return V_97 ? ( V_97 [ 12 ] * 2 ) : 0 ;
}
static int
F_48 ( struct V_11 * V_11 )
{
T_1 * V_97 = NULL ;
F_43 ( ( T_1 * ) V_11 , F_46 , & V_97 ) ;
return V_97 ? V_97 [ 13 ] : 0 ;
}
static int
F_49 ( struct V_11 * V_11 )
{
T_1 * V_97 = NULL ;
F_43 ( ( T_1 * ) V_11 , F_46 , & V_97 ) ;
return V_97 ? ( V_97 [ 15 ] << 8 ) + V_97 [ 14 ] : 0 ;
}
static int
F_50 ( struct V_11 * V_11 )
{
T_1 * V_97 = NULL ;
F_43 ( ( T_1 * ) V_11 , F_46 , & V_97 ) ;
return V_97 ? V_97 [ 16 ] : 0 ;
}
static int
F_51 ( struct V_11 * V_11 )
{
T_1 * V_97 = NULL ;
F_43 ( ( T_1 * ) V_11 , F_46 , & V_97 ) ;
return V_97 ? V_97 [ 17 ] : 0 ;
}
static int F_52 ( struct V_11 * V_11 )
{
if ( V_11 -> V_15 >= 2 ) {
if ( V_11 -> V_15 >= 4 && ( V_11 -> V_101 & V_102 ) )
return V_103 ;
if ( F_47 ( V_11 ) )
return V_104 ;
return V_105 ;
}
return V_106 ;
}
static int
F_53 ( T_1 V_107 , T_1 V_108 )
{
return ( V_107 == 0x00 && V_108 == 0x00 ) ||
( V_107 == 0x01 && V_108 == 0x01 ) ||
( V_107 == 0x20 && V_108 == 0x20 ) ;
}
static struct V_59 *
F_54 ( struct V_39 * V_40 , struct V_11 * V_11 ,
struct V_109 * V_60 )
{
struct V_79 * V_51 = V_40 -> V_51 ;
struct V_59 * V_110 , * V_72 = NULL ;
int V_80 , V_81 ;
int V_111 ;
unsigned V_112 = ( V_60 -> V_113 & V_114 )
>> V_115 ;
unsigned V_116 = ( V_60 -> V_113 & V_117 )
>> V_118 ;
int V_119 = F_52 ( V_11 ) ;
if ( F_53 ( V_60 -> V_80 , V_60 -> V_113 ) )
return NULL ;
V_80 = V_60 -> V_80 * 8 + 248 ;
V_111 = V_116 + 60 ;
if ( V_112 == 0 ) {
if ( V_11 -> V_15 < 3 )
V_81 = V_80 ;
else
V_81 = ( V_80 * 10 ) / 16 ;
} else if ( V_112 == 1 )
V_81 = ( V_80 * 3 ) / 4 ;
else if ( V_112 == 2 )
V_81 = ( V_80 * 4 ) / 5 ;
else
V_81 = ( V_80 * 9 ) / 16 ;
if ( V_111 == 60 &&
( ( V_80 == 1360 && V_81 == 765 ) ||
( V_80 == 1368 && V_81 == 769 ) ) ) {
V_80 = 1366 ;
V_81 = 768 ;
}
F_55 (m, &connector->probed_modes, head)
if ( V_110 -> V_74 == V_80 && V_110 -> V_78 == V_81 &&
F_35 ( V_110 ) == V_111 )
return NULL ;
if ( V_80 == 1366 && V_81 == 768 && V_111 == 60 ) {
V_72 = F_56 ( V_51 , 1366 , 768 , V_111 , 0 , 0 ,
false ) ;
V_72 -> V_74 = 1366 ;
V_72 -> V_76 = V_72 -> V_76 - 1 ;
V_72 -> V_75 = V_72 -> V_75 - 1 ;
return V_72 ;
}
if ( F_45 ( V_11 ) ) {
V_72 = F_38 ( V_51 , V_80 , V_81 , V_111 ,
true ) ;
if ( V_72 )
return V_72 ;
}
V_72 = F_38 ( V_51 , V_80 , V_81 , V_111 , false ) ;
if ( V_72 )
return V_72 ;
switch ( V_119 ) {
case V_106 :
break;
case V_105 :
V_72 = F_57 ( V_51 , V_80 , V_81 , V_111 , 0 , 0 ) ;
break;
case V_104 :
V_72 = F_57 ( V_51 , V_80 , V_81 , V_111 , 0 , 0 ) ;
if ( ! V_72 )
return NULL ;
if ( F_58 ( V_72 ) > F_47 ( V_11 ) ) {
F_59 ( V_51 , V_72 ) ;
V_72 = F_60 ( V_51 , V_80 , V_81 ,
V_111 , 0 , 0 ,
F_49 ( V_11 ) ,
F_48 ( V_11 ) ,
F_50 ( V_11 ) ,
F_51 ( V_11 ) ) ;
}
break;
case V_103 :
V_72 = F_56 ( V_51 , V_80 , V_81 , V_111 , 0 , 0 ,
false ) ;
break;
}
return V_72 ;
}
static void
F_61 ( struct V_59 * V_72 ,
struct V_120 * V_121 )
{
int V_2 ;
static const struct {
int V_122 , V_123 ;
} V_124 [] = {
{ 1920 , 1080 } ,
{ 720 , 480 } ,
{ 1440 , 480 } ,
{ 2880 , 480 } ,
{ 720 , 576 } ,
{ 1440 , 576 } ,
{ 2880 , 576 } ,
} ;
if ( ! ( V_121 -> V_125 & V_126 ) )
return;
for ( V_2 = 0 ; V_2 < F_28 ( V_124 ) ; V_2 ++ ) {
if ( ( V_72 -> V_74 == V_124 [ V_2 ] . V_122 ) &&
( V_72 -> V_78 == V_124 [ V_2 ] . V_123 / 2 ) ) {
V_72 -> V_78 *= 2 ;
V_72 -> V_77 *= 2 ;
V_72 -> V_127 *= 2 ;
V_72 -> V_128 *= 2 ;
V_72 -> V_128 |= 1 ;
}
}
V_72 -> V_34 |= V_129 ;
}
static struct V_59 * F_62 ( struct V_79 * V_51 ,
struct V_11 * V_11 ,
struct V_92 * V_130 ,
T_3 V_58 )
{
struct V_59 * V_72 ;
struct V_120 * V_121 = & V_130 -> V_20 . V_131 ;
unsigned V_132 = ( V_121 -> V_133 & 0xf0 ) << 4 | V_121 -> V_134 ;
unsigned V_135 = ( V_121 -> V_136 & 0xf0 ) << 4 | V_121 -> V_137 ;
unsigned V_138 = ( V_121 -> V_133 & 0xf ) << 8 | V_121 -> V_139 ;
unsigned V_140 = ( V_121 -> V_136 & 0xf ) << 8 | V_121 -> V_141 ;
unsigned V_142 = ( V_121 -> V_143 & 0xc0 ) << 2 | V_121 -> V_144 ;
unsigned V_145 = ( V_121 -> V_143 & 0x30 ) << 4 | V_121 -> V_146 ;
unsigned V_147 = ( V_121 -> V_143 & 0xc ) << 2 | V_121 -> V_148 >> 4 ;
unsigned V_149 = ( V_121 -> V_143 & 0x3 ) << 4 | ( V_121 -> V_148 & 0xf ) ;
if ( V_132 < 64 || V_135 < 64 )
return NULL ;
if ( V_121 -> V_125 & V_150 ) {
F_14 ( L_11 ) ;
return NULL ;
}
if ( ! ( V_121 -> V_125 & V_151 ) ) {
F_14 ( L_12 ) ;
}
if ( ! V_145 || ! V_149 ) {
F_14 ( L_13
L_14 ) ;
return NULL ;
}
if ( V_58 & V_152 ) {
V_72 = F_56 ( V_51 , V_132 , V_135 , 60 , true , false , false ) ;
if ( ! V_72 )
return NULL ;
goto V_153;
}
V_72 = F_63 ( V_51 ) ;
if ( ! V_72 )
return NULL ;
if ( V_58 & V_154 )
V_130 -> V_155 = F_64 ( 1088 ) ;
V_72 -> clock = F_65 ( V_130 -> V_155 ) * 10 ;
V_72 -> V_74 = V_132 ;
V_72 -> V_76 = V_72 -> V_74 + V_142 ;
V_72 -> V_75 = V_72 -> V_76 + V_145 ;
V_72 -> V_73 = V_72 -> V_74 + V_138 ;
V_72 -> V_78 = V_135 ;
V_72 -> V_77 = V_72 -> V_78 + V_147 ;
V_72 -> V_127 = V_72 -> V_77 + V_149 ;
V_72 -> V_128 = V_72 -> V_78 + V_140 ;
if ( V_72 -> V_75 > V_72 -> V_73 )
V_72 -> V_73 = V_72 -> V_75 + 1 ;
if ( V_72 -> V_127 > V_72 -> V_128 )
V_72 -> V_128 = V_72 -> V_127 + 1 ;
F_61 ( V_72 , V_121 ) ;
if ( V_58 & V_156 ) {
V_121 -> V_125 |= V_157 | V_158 ;
}
V_72 -> V_34 |= ( V_121 -> V_125 & V_157 ) ?
V_159 : V_160 ;
V_72 -> V_34 |= ( V_121 -> V_125 & V_158 ) ?
V_161 : V_162 ;
V_153:
V_72 -> V_163 = V_121 -> V_164 | ( V_121 -> V_165 & 0xf0 ) << 4 ;
V_72 -> V_166 = V_121 -> V_167 | ( V_121 -> V_165 & 0xf ) << 8 ;
if ( V_58 & V_168 ) {
V_72 -> V_163 *= 10 ;
V_72 -> V_166 *= 10 ;
}
if ( V_58 & V_169 ) {
V_72 -> V_163 = V_11 -> V_170 * 10 ;
V_72 -> V_166 = V_11 -> V_171 * 10 ;
}
V_72 -> type = V_172 ;
V_72 -> V_71 = F_35 ( V_72 ) ;
F_66 ( V_72 ) ;
return V_72 ;
}
static bool
F_67 ( const struct V_59 * V_72 ,
struct V_11 * V_11 , T_1 * V_60 )
{
int V_173 , V_174 , V_175 ;
V_174 = V_60 [ 7 ] ;
if ( V_11 -> V_15 >= 4 )
V_174 += ( ( V_60 [ 4 ] & 0x04 ) ? 255 : 0 ) ;
V_175 = V_60 [ 8 ] ;
if ( V_11 -> V_15 >= 4 )
V_175 += ( ( V_60 [ 4 ] & 0x08 ) ? 255 : 0 ) ;
V_173 = F_58 ( V_72 ) ;
return ( V_173 <= V_175 && V_173 >= V_174 ) ;
}
static bool
F_68 ( const struct V_59 * V_72 ,
struct V_11 * V_11 , T_1 * V_60 )
{
int V_176 , V_177 , V_178 ;
V_177 = V_60 [ 5 ] ;
if ( V_11 -> V_15 >= 4 )
V_177 += ( ( V_60 [ 4 ] & 0x01 ) ? 255 : 0 ) ;
V_178 = V_60 [ 6 ] ;
if ( V_11 -> V_15 >= 4 )
V_178 += ( ( V_60 [ 4 ] & 0x02 ) ? 255 : 0 ) ;
V_176 = F_35 ( V_72 ) ;
return ( V_176 <= V_178 && V_176 >= V_177 ) ;
}
static T_3
F_69 ( struct V_11 * V_11 , T_1 * V_60 )
{
if ( V_60 [ 9 ] == 0 || V_60 [ 9 ] == 255 )
return 0 ;
if ( V_11 -> V_15 >= 4 && V_60 [ 10 ] == 0x04 )
return ( V_60 [ 9 ] * 10000 ) - ( ( V_60 [ 12 ] >> 2 ) * 250 ) ;
return V_60 [ 9 ] * 10000 + 5001 ;
}
static bool
F_70 ( const struct V_59 * V_72 , struct V_11 * V_11 ,
struct V_92 * V_130 )
{
T_3 V_179 ;
T_1 * V_60 = ( T_1 * ) V_130 ;
if ( ! F_67 ( V_72 , V_11 , V_60 ) )
return false ;
if ( ! F_68 ( V_72 , V_11 , V_60 ) )
return false ;
if ( ( V_179 = F_69 ( V_11 , V_60 ) ) )
if ( V_72 -> clock > V_179 )
return false ;
if ( V_11 -> V_15 >= 4 && V_60 [ 10 ] == 0x04 )
if ( V_60 [ 13 ] && V_72 -> V_74 > 8 * ( V_60 [ 13 ] + ( 256 * ( V_60 [ 12 ] & 0x3 ) ) ) )
return false ;
if ( F_37 ( V_72 ) && ! F_45 ( V_11 ) )
return false ;
return true ;
}
static bool F_71 ( const struct V_39 * V_40 ,
const struct V_59 * V_72 )
{
struct V_59 * V_110 ;
bool V_180 = false ;
F_55 (m, &connector->probed_modes, head) {
if ( V_72 -> V_74 == V_110 -> V_74 &&
V_72 -> V_78 == V_110 -> V_78 &&
F_35 ( V_72 ) == F_35 ( V_110 ) )
return false ;
if ( V_72 -> V_74 <= V_110 -> V_74 &&
V_72 -> V_78 <= V_110 -> V_78 )
V_180 = true ;
}
return V_180 ;
}
static int
F_72 ( struct V_39 * V_40 , struct V_11 * V_11 ,
struct V_92 * V_130 )
{
int V_2 , V_181 = 0 ;
struct V_59 * V_182 ;
struct V_79 * V_51 = V_40 -> V_51 ;
for ( V_2 = 0 ; V_2 < F_28 ( V_84 ) ; V_2 ++ ) {
if ( F_70 ( V_84 + V_2 , V_11 , V_130 ) &&
F_71 ( V_40 , V_84 + V_2 ) ) {
V_182 = F_39 ( V_51 , & V_84 [ V_2 ] ) ;
if ( V_182 ) {
F_73 ( V_40 , V_182 ) ;
V_181 ++ ;
}
}
}
return V_181 ;
}
static void F_74 ( struct V_59 * V_72 )
{
if ( V_72 -> V_74 == 1368 && V_72 -> V_78 == 768 ) {
V_72 -> V_74 = 1366 ;
V_72 -> V_76 -- ;
V_72 -> V_75 -- ;
F_66 ( V_72 ) ;
}
}
static int
F_75 ( struct V_39 * V_40 , struct V_11 * V_11 ,
struct V_92 * V_130 )
{
int V_2 , V_181 = 0 ;
struct V_59 * V_182 ;
struct V_79 * V_51 = V_40 -> V_51 ;
for ( V_2 = 0 ; V_2 < F_28 ( V_183 ) ; V_2 ++ ) {
const struct V_184 * V_110 = & V_183 [ V_2 ] ;
V_182 = F_57 ( V_51 , V_110 -> V_122 , V_110 -> V_123 , V_110 -> V_97 , 0 , 0 ) ;
if ( ! V_182 )
return V_181 ;
F_74 ( V_182 ) ;
if ( ! F_70 ( V_182 , V_11 , V_130 ) ||
! F_71 ( V_40 , V_182 ) ) {
F_59 ( V_51 , V_182 ) ;
continue;
}
F_73 ( V_40 , V_182 ) ;
V_181 ++ ;
}
return V_181 ;
}
static int
F_76 ( struct V_39 * V_40 , struct V_11 * V_11 ,
struct V_92 * V_130 )
{
int V_2 , V_181 = 0 ;
struct V_59 * V_182 ;
struct V_79 * V_51 = V_40 -> V_51 ;
bool V_83 = F_45 ( V_11 ) ;
for ( V_2 = 0 ; V_2 < F_28 ( V_183 ) ; V_2 ++ ) {
const struct V_184 * V_110 = & V_183 [ V_2 ] ;
V_182 = F_56 ( V_51 , V_110 -> V_122 , V_110 -> V_123 , V_110 -> V_97 , V_83 , 0 , 0 ) ;
if ( ! V_182 )
return V_181 ;
F_74 ( V_182 ) ;
if ( ! F_70 ( V_182 , V_11 , V_130 ) ||
! F_71 ( V_40 , V_182 ) ) {
F_59 ( V_51 , V_182 ) ;
continue;
}
F_73 ( V_40 , V_182 ) ;
V_181 ++ ;
}
return V_181 ;
}
static void
F_77 ( struct V_92 * V_130 , void * V_185 )
{
struct V_186 * V_88 = V_185 ;
struct V_187 * V_20 = & V_130 -> V_20 . V_188 ;
struct V_189 * V_190 = & V_20 -> V_20 . V_190 ;
if ( V_20 -> type != V_98 )
return;
V_88 -> V_181 += F_72 ( V_88 -> V_40 ,
V_88 -> V_11 ,
V_130 ) ;
if ( ! F_78 ( V_88 -> V_11 , 1 , 1 ) )
return;
switch ( V_190 -> V_34 ) {
case 0x02 :
case 0x00 :
V_88 -> V_181 += F_75 ( V_88 -> V_40 ,
V_88 -> V_11 ,
V_130 ) ;
break;
case 0x04 :
if ( ! F_78 ( V_88 -> V_11 , 1 , 3 ) )
break;
V_88 -> V_181 += F_76 ( V_88 -> V_40 ,
V_88 -> V_11 ,
V_130 ) ;
break;
case 0x01 :
default:
break;
}
}
static int
F_79 ( struct V_39 * V_40 , struct V_11 * V_11 )
{
struct V_186 V_88 = {
. V_40 = V_40 ,
. V_11 = V_11 ,
} ;
if ( F_78 ( V_11 , 1 , 0 ) )
F_43 ( ( T_1 * ) V_11 , F_77 ,
& V_88 ) ;
return V_88 . V_181 ;
}
static int
F_80 ( struct V_39 * V_40 , struct V_92 * V_130 )
{
int V_2 , V_41 , V_110 , V_181 = 0 ;
struct V_59 * V_72 ;
T_1 * V_191 = ( ( T_1 * ) V_130 ) + 5 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
for ( V_41 = 7 ; V_41 >= 0 ; V_41 -- ) {
V_110 = ( V_2 * 8 ) + ( 7 - V_41 ) ;
if ( V_110 >= F_28 ( V_192 ) )
break;
if ( V_191 [ V_2 ] & ( 1 << V_41 ) ) {
V_72 = F_38 ( V_40 -> V_51 ,
V_192 [ V_110 ] . V_122 ,
V_192 [ V_110 ] . V_123 ,
V_192 [ V_110 ] . V_97 ,
V_192 [ V_110 ] . V_83 ) ;
if ( V_72 ) {
F_73 ( V_40 , V_72 ) ;
V_181 ++ ;
}
}
}
}
return V_181 ;
}
static void
F_81 ( struct V_92 * V_130 , void * V_185 )
{
struct V_186 * V_88 = V_185 ;
struct V_187 * V_20 = & V_130 -> V_20 . V_188 ;
if ( V_20 -> type == V_193 )
V_88 -> V_181 += F_80 ( V_88 -> V_40 , V_130 ) ;
}
static int
F_82 ( struct V_39 * V_40 , struct V_11 * V_11 )
{
struct V_79 * V_51 = V_40 -> V_51 ;
unsigned long V_194 = V_11 -> V_195 . V_196 |
( V_11 -> V_195 . V_197 << 8 ) |
( ( V_11 -> V_195 . V_198 & 0x80 ) << 9 ) ;
int V_2 , V_181 = 0 ;
struct V_186 V_88 = {
. V_40 = V_40 ,
. V_11 = V_11 ,
} ;
for ( V_2 = 0 ; V_2 <= V_199 ; V_2 ++ ) {
if ( V_194 & ( 1 << V_2 ) ) {
struct V_59 * V_182 ;
V_182 = F_39 ( V_51 , & V_200 [ V_2 ] ) ;
if ( V_182 ) {
F_73 ( V_40 , V_182 ) ;
V_181 ++ ;
}
}
}
if ( F_78 ( V_11 , 1 , 0 ) )
F_43 ( ( T_1 * ) V_11 ,
F_81 , & V_88 ) ;
return V_181 + V_88 . V_181 ;
}
static void
F_83 ( struct V_92 * V_130 , void * V_185 )
{
struct V_186 * V_88 = V_185 ;
struct V_187 * V_20 = & V_130 -> V_20 . V_188 ;
struct V_39 * V_40 = V_88 -> V_40 ;
struct V_11 * V_11 = V_88 -> V_11 ;
if ( V_20 -> type == V_201 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
struct V_109 * V_202 ;
struct V_59 * V_182 ;
V_202 = & V_20 -> V_20 . V_203 [ V_2 ] ;
V_182 = F_54 ( V_40 , V_11 , V_202 ) ;
if ( V_182 ) {
F_73 ( V_40 , V_182 ) ;
V_88 -> V_181 ++ ;
}
}
}
}
static int
F_84 ( struct V_39 * V_40 , struct V_11 * V_11 )
{
int V_2 , V_181 = 0 ;
struct V_186 V_88 = {
. V_40 = V_40 ,
. V_11 = V_11 ,
} ;
for ( V_2 = 0 ; V_2 < V_204 ; V_2 ++ ) {
struct V_59 * V_182 ;
V_182 = F_54 ( V_40 , V_11 ,
& V_11 -> V_205 [ V_2 ] ) ;
if ( V_182 ) {
F_73 ( V_40 , V_182 ) ;
V_181 ++ ;
}
}
if ( F_78 ( V_11 , 1 , 0 ) )
F_43 ( ( T_1 * ) V_11 , F_83 ,
& V_88 ) ;
return V_181 + V_88 . V_181 ;
}
static int F_85 ( struct V_39 * V_40 ,
struct V_92 * V_130 )
{
int V_2 , V_41 , V_181 = 0 ;
struct V_59 * V_182 ;
struct V_79 * V_51 = V_40 -> V_51 ;
struct V_206 * V_207 ;
const int V_208 [] = { 60 , 85 , 75 , 60 , 50 } ;
const T_1 V_209 [ 3 ] = { 0 , 0 , 0 } ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_210 ( V_211 ) , V_212 ;
V_207 = & ( V_130 -> V_20 . V_188 . V_20 . V_207 [ V_2 ] ) ;
if ( ! memcmp ( V_207 -> V_213 , V_209 , 3 ) )
continue;
V_212 = ( V_207 -> V_213 [ 0 ] + ( ( V_207 -> V_213 [ 1 ] & 0xf0 ) << 4 ) + 1 ) * 2 ;
switch ( V_207 -> V_213 [ 1 ] & 0x0c ) {
case 0x00 :
V_211 = V_212 * 4 / 3 ;
break;
case 0x04 :
V_211 = V_212 * 16 / 9 ;
break;
case 0x08 :
V_211 = V_212 * 16 / 10 ;
break;
case 0x0c :
V_211 = V_212 * 15 / 9 ;
break;
}
for ( V_41 = 1 ; V_41 < 5 ; V_41 ++ ) {
if ( V_207 -> V_213 [ 2 ] & ( 1 << V_41 ) ) {
V_182 = F_56 ( V_51 , V_211 , V_212 ,
V_208 [ V_41 ] , V_41 == 0 ,
false , false ) ;
if ( V_182 ) {
F_73 ( V_40 , V_182 ) ;
V_181 ++ ;
}
}
}
}
return V_181 ;
}
static void
F_86 ( struct V_92 * V_130 , void * V_185 )
{
struct V_186 * V_88 = V_185 ;
struct V_187 * V_20 = & V_130 -> V_20 . V_188 ;
if ( V_20 -> type == V_214 )
V_88 -> V_181 += F_85 ( V_88 -> V_40 , V_130 ) ;
}
static int
F_87 ( struct V_39 * V_40 , struct V_11 * V_11 )
{
struct V_186 V_88 = {
. V_40 = V_40 ,
. V_11 = V_11 ,
} ;
if ( F_78 ( V_11 , 1 , 2 ) )
F_43 ( ( T_1 * ) V_11 , F_86 , & V_88 ) ;
return V_88 . V_181 ;
}
static void
F_88 ( struct V_92 * V_130 , void * V_185 )
{
struct V_186 * V_88 = V_185 ;
struct V_59 * V_182 ;
if ( V_130 -> V_155 ) {
V_182 = F_62 ( V_88 -> V_40 -> V_51 ,
V_88 -> V_11 , V_130 ,
V_88 -> V_58 ) ;
if ( ! V_182 )
return;
if ( V_88 -> V_215 )
V_182 -> type |= V_70 ;
F_73 ( V_88 -> V_40 , V_182 ) ;
V_88 -> V_181 ++ ;
V_88 -> V_215 = 0 ;
}
}
static int
F_89 ( struct V_39 * V_40 , struct V_11 * V_11 ,
T_3 V_58 )
{
struct V_186 V_88 = {
. V_40 = V_40 ,
. V_11 = V_11 ,
. V_215 = 1 ,
. V_58 = V_58 ,
} ;
if ( V_88 . V_215 && ! F_78 ( V_11 , 1 , 3 ) )
V_88 . V_215 =
( V_11 -> V_101 & V_216 ) ;
F_43 ( ( T_1 * ) V_11 , F_88 , & V_88 ) ;
return V_88 . V_181 ;
}
static T_1 * F_90 ( struct V_11 * V_11 , int V_217 )
{
T_1 * V_218 = NULL ;
int V_2 ;
if ( V_11 == NULL || V_11 -> V_19 == 0 )
return NULL ;
for ( V_2 = 0 ; V_2 < V_11 -> V_19 ; V_2 ++ ) {
V_218 = ( T_1 * ) V_11 + V_6 * ( V_2 + 1 ) ;
if ( V_218 [ 0 ] == V_217 )
break;
}
if ( V_2 == V_11 -> V_19 )
return NULL ;
return V_218 ;
}
static T_1 * F_91 ( struct V_11 * V_11 )
{
return F_90 ( V_11 , V_95 ) ;
}
static T_1 * F_92 ( struct V_11 * V_11 )
{
return F_90 ( V_11 , V_219 ) ;
}
static unsigned int
F_93 ( const struct V_59 * V_220 )
{
unsigned int clock = V_220 -> clock ;
if ( V_220 -> V_71 % 6 != 0 )
return clock ;
if ( V_220 -> V_78 == 240 || V_220 -> V_78 == 480 )
clock = clock * 1001 / 1000 ;
else
clock = F_94 ( clock * 1000 , 1001 ) ;
return clock ;
}
T_1 F_95 ( const struct V_59 * V_221 )
{
T_1 V_72 ;
if ( ! V_221 -> clock )
return 0 ;
for ( V_72 = 0 ; V_72 < F_28 ( V_222 ) ; V_72 ++ ) {
const struct V_59 * V_220 = & V_222 [ V_72 ] ;
unsigned int V_223 , V_224 ;
V_223 = V_220 -> clock ;
V_224 = F_93 ( V_220 ) ;
if ( ( F_96 ( V_221 -> clock ) == F_96 ( V_223 ) ||
F_96 ( V_221 -> clock ) == F_96 ( V_224 ) ) &&
F_97 ( V_221 , V_220 ) )
return V_72 + 1 ;
}
return 0 ;
}
enum V_225 F_98 ( const T_1 V_226 )
{
return V_222 [ V_226 - 1 ] . V_227 ;
}
static unsigned int
F_99 ( const struct V_59 * V_228 )
{
if ( V_228 -> V_78 == 4096 && V_228 -> V_74 == 2160 )
return V_228 -> clock ;
return F_93 ( V_228 ) ;
}
static T_1 F_100 ( const struct V_59 * V_221 )
{
T_1 V_72 ;
if ( ! V_221 -> clock )
return 0 ;
for ( V_72 = 0 ; V_72 < F_28 ( V_229 ) ; V_72 ++ ) {
const struct V_59 * V_228 = & V_229 [ V_72 ] ;
unsigned int V_223 , V_224 ;
V_223 = V_228 -> clock ;
V_224 = F_99 ( V_228 ) ;
if ( ( F_96 ( V_221 -> clock ) == F_96 ( V_223 ) ||
F_96 ( V_221 -> clock ) == F_96 ( V_224 ) ) &&
F_97 ( V_221 , V_228 ) )
return V_72 + 1 ;
}
return 0 ;
}
static int
F_101 ( struct V_39 * V_40 , struct V_11 * V_11 )
{
struct V_79 * V_51 = V_40 -> V_51 ;
struct V_59 * V_72 , * V_230 ;
F_102 ( V_231 ) ;
int V_181 = 0 ;
if ( ! F_91 ( V_11 ) )
return 0 ;
F_55 (mode, &connector->probed_modes, head) {
const struct V_59 * V_220 = NULL ;
struct V_59 * V_182 ;
T_1 V_232 = F_95 ( V_72 ) - 1 ;
unsigned int V_223 , V_224 ;
if ( V_232 < F_28 ( V_222 ) ) {
V_220 = & V_222 [ V_232 ] ;
V_224 = F_93 ( V_220 ) ;
} else {
V_232 = F_100 ( V_72 ) - 1 ;
if ( V_232 < F_28 ( V_229 ) ) {
V_220 = & V_229 [ V_232 ] ;
V_224 = F_99 ( V_220 ) ;
}
}
if ( ! V_220 )
continue;
V_223 = V_220 -> clock ;
if ( V_223 == V_224 )
continue;
if ( V_72 -> clock != V_223 && V_72 -> clock != V_224 )
continue;
V_182 = F_39 ( V_51 , V_220 ) ;
if ( ! V_182 )
continue;
V_182 -> V_34 |= V_72 -> V_34 & V_233 ;
if ( V_72 -> clock != V_223 )
V_182 -> clock = V_223 ;
else
V_182 -> clock = V_224 ;
F_103 ( & V_182 -> V_69 , & V_231 ) ;
}
F_33 (mode, tmp, &list, head) {
F_104 ( & V_72 -> V_69 ) ;
F_73 ( V_40 , V_72 ) ;
V_181 ++ ;
}
return V_181 ;
}
static struct V_59 *
F_105 ( struct V_39 * V_40 ,
const T_1 * V_234 , T_1 V_235 ,
T_1 V_236 )
{
struct V_79 * V_51 = V_40 -> V_51 ;
struct V_59 * V_182 ;
T_1 V_220 ;
if ( V_234 == NULL || V_236 >= V_235 )
return NULL ;
V_220 = ( V_234 [ V_236 ] & 127 ) - 1 ;
if ( V_220 >= F_28 ( V_222 ) )
return NULL ;
V_182 = F_39 ( V_51 , & V_222 [ V_220 ] ) ;
if ( ! V_182 )
return NULL ;
V_182 -> V_71 = 0 ;
return V_182 ;
}
static int
F_106 ( struct V_39 * V_40 , const T_1 * V_237 , T_1 V_22 )
{
int V_2 , V_181 = 0 ;
for ( V_2 = 0 ; V_2 < V_22 ; V_2 ++ ) {
struct V_59 * V_72 ;
V_72 = F_105 ( V_40 , V_237 , V_22 , V_2 ) ;
if ( V_72 ) {
F_73 ( V_40 , V_72 ) ;
V_181 ++ ;
}
}
return V_181 ;
}
static bool
F_107 ( const struct V_59 * V_72 ,
const struct V_238 * V_239 )
{
unsigned int V_240 = V_72 -> V_34 & V_129 ;
return V_72 -> V_74 == V_239 -> V_211 &&
V_72 -> V_78 == V_239 -> V_212 &&
V_240 == ( V_239 -> V_34 & V_129 ) &&
F_35 ( V_72 ) == V_239 -> V_71 ;
}
static int F_108 ( struct V_39 * V_40 )
{
struct V_79 * V_51 = V_40 -> V_51 ;
const struct V_59 * V_72 ;
struct V_241 V_242 ;
int V_181 = 0 , V_2 ;
F_109 ( & V_242 ) ;
F_55 (mode, &connector->probed_modes, head) {
for ( V_2 = 0 ; V_2 < F_28 ( V_243 ) ; V_2 ++ ) {
const struct V_238 * V_244 ;
struct V_59 * V_245 ;
if ( ! F_107 ( V_72 ,
& V_243 [ V_2 ] ) )
continue;
V_244 = & V_243 [ V_2 ] ;
V_245 = F_39 ( V_51 , V_72 ) ;
if ( ! V_245 )
continue;
V_245 -> V_34 |= V_244 -> V_34 ;
F_103 ( & V_245 -> V_69 , & V_242 ) ;
V_181 ++ ;
}
}
F_110 ( & V_242 , & V_40 -> V_66 ) ;
return V_181 ;
}
static int F_111 ( struct V_39 * V_40 , T_1 V_246 )
{
struct V_79 * V_51 = V_40 -> V_51 ;
struct V_59 * V_182 ;
V_246 -- ;
if ( V_246 >= F_28 ( V_229 ) ) {
F_8 ( L_15 , V_246 ) ;
return 0 ;
}
V_182 = F_39 ( V_51 , & V_229 [ V_246 ] ) ;
if ( ! V_182 )
return 0 ;
F_73 ( V_40 , V_182 ) ;
return 1 ;
}
static int F_112 ( struct V_39 * V_40 , T_5 V_247 ,
const T_1 * V_234 , T_1 V_235 , T_1 V_236 )
{
struct V_59 * V_182 ;
int V_181 = 0 ;
if ( V_247 & ( 1 << 0 ) ) {
V_182 = F_105 ( V_40 , V_234 ,
V_235 ,
V_236 ) ;
if ( V_182 ) {
V_182 -> V_34 |= V_248 ;
F_73 ( V_40 , V_182 ) ;
V_181 ++ ;
}
}
if ( V_247 & ( 1 << 6 ) ) {
V_182 = F_105 ( V_40 , V_234 ,
V_235 ,
V_236 ) ;
if ( V_182 ) {
V_182 -> V_34 |= V_249 ;
F_73 ( V_40 , V_182 ) ;
V_181 ++ ;
}
}
if ( V_247 & ( 1 << 8 ) ) {
V_182 = F_105 ( V_40 , V_234 ,
V_235 ,
V_236 ) ;
if ( V_182 ) {
V_182 -> V_34 |= V_250 ;
F_73 ( V_40 , V_182 ) ;
V_181 ++ ;
}
}
return V_181 ;
}
static int
F_113 ( struct V_39 * V_40 , const T_1 * V_237 , T_1 V_22 ,
const T_1 * V_234 , T_1 V_235 )
{
int V_181 = 0 , V_251 = 0 , V_2 , V_252 = 0 , V_253 ;
T_1 V_254 , V_255 = 0 ;
T_5 V_256 ;
T_5 V_257 ;
if ( V_22 < 8 )
goto V_48;
if ( ! ( V_237 [ 8 ] & ( 1 << 5 ) ) )
goto V_48;
if ( V_237 [ 8 ] & ( 1 << 7 ) )
V_251 += 2 ;
if ( V_237 [ 8 ] & ( 1 << 6 ) )
V_251 += 2 ;
if ( V_22 < ( 8 + V_251 + 2 ) )
goto V_48;
V_251 ++ ;
if ( V_237 [ 8 + V_251 ] & ( 1 << 7 ) ) {
V_181 += F_108 ( V_40 ) ;
V_252 = ( V_237 [ 8 + V_251 ] & 0x60 ) >> 5 ;
}
V_251 ++ ;
V_254 = V_237 [ 8 + V_251 ] >> 5 ;
V_255 = V_237 [ 8 + V_251 ] & 0x1f ;
for ( V_2 = 0 ; V_2 < V_254 && V_22 >= ( 9 + V_251 + V_2 ) ; V_2 ++ ) {
T_1 V_246 ;
V_246 = V_237 [ 9 + V_251 + V_2 ] ;
V_181 += F_111 ( V_40 , V_246 ) ;
}
V_251 += 1 + V_254 ;
if ( V_252 == 1 )
V_253 = 2 ;
else if ( V_252 == 2 )
V_253 = 4 ;
else
V_253 = 0 ;
if ( V_22 < ( 8 + V_251 + V_255 - 1 ) )
goto V_48;
if ( V_255 < V_253 )
goto V_48;
if ( V_252 == 1 || V_252 == 2 ) {
V_257 = ( V_237 [ 8 + V_251 ] << 8 ) | V_237 [ 9 + V_251 ] ;
if ( V_252 == 2 )
V_256 = ( V_237 [ 10 + V_251 ] << 8 ) | V_237 [ 11 + V_251 ] ;
else
V_256 = 0xffff ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
if ( V_256 & ( 1 << V_2 ) )
V_181 += F_112 ( V_40 ,
V_257 ,
V_234 ,
V_235 , V_2 ) ;
}
}
V_251 += V_253 ;
for ( V_2 = 0 ; V_2 < ( V_255 - V_253 ) ; V_2 ++ ) {
int V_258 ;
struct V_59 * V_182 = NULL ;
unsigned int V_259 = 0 ;
bool V_260 ;
V_260 = ( ( V_237 [ 8 + V_251 + V_2 ] & 0x0f ) > 7 ) ;
if ( V_260 && ( V_2 + 1 == V_255 - V_253 ) )
break;
V_258 = V_237 [ 8 + V_251 + V_2 ] >> 4 ;
switch ( V_237 [ 8 + V_251 + V_2 ] & 0x0f ) {
case 0 :
V_259 = V_248 ;
break;
case 6 :
V_259 = V_249 ;
break;
case 8 :
if ( ( V_237 [ 9 + V_251 + V_2 ] >> 4 ) == 1 )
V_259 = V_250 ;
break;
}
if ( V_259 != 0 ) {
V_182 = F_105 ( V_40 ,
V_234 ,
V_235 ,
V_258 ) ;
if ( V_182 ) {
V_182 -> V_34 |= V_259 ;
F_73 ( V_40 , V_182 ) ;
V_181 ++ ;
}
}
if ( V_260 )
V_2 ++ ;
}
V_48:
return V_181 ;
}
static int
F_114 ( const T_1 * V_237 )
{
return V_237 [ 0 ] & 0x1f ;
}
static int
F_115 ( const T_1 * V_237 )
{
return V_237 [ 0 ] >> 5 ;
}
static int
F_116 ( const T_1 * V_261 )
{
return V_261 [ 1 ] ;
}
static int
F_117 ( const T_1 * V_261 , int * V_25 , int * V_262 )
{
* V_25 = 4 ;
* V_262 = V_261 [ 2 ] ;
if ( * V_262 == 0 )
* V_262 = 127 ;
if ( * V_262 < 4 || * V_262 > 127 )
return - V_263 ;
return 0 ;
}
static bool F_118 ( const T_1 * V_237 )
{
int V_264 ;
if ( F_115 ( V_237 ) != V_265 )
return false ;
if ( F_114 ( V_237 ) < 5 )
return false ;
V_264 = V_237 [ 1 ] | ( V_237 [ 2 ] << 8 ) | ( V_237 [ 3 ] << 16 ) ;
return V_264 == V_266 ;
}
static int
F_119 ( struct V_39 * V_40 , struct V_11 * V_11 )
{
const T_1 * V_261 = F_91 ( V_11 ) ;
const T_1 * V_237 , * V_267 = NULL , * V_268 = NULL ;
T_1 V_269 , V_270 , V_235 = 0 ;
int V_181 = 0 ;
if ( V_261 && F_116 ( V_261 ) >= 3 ) {
int V_2 , V_25 , V_262 ;
if ( F_117 ( V_261 , & V_25 , & V_262 ) )
return 0 ;
F_120 (cea, i, start, end) {
V_237 = & V_261 [ V_2 ] ;
V_269 = F_114 ( V_237 ) ;
if ( F_115 ( V_237 ) == V_271 ) {
V_268 = V_237 + 1 ;
V_235 = V_269 ;
V_181 += F_106 ( V_40 , V_268 , V_269 ) ;
}
else if ( F_118 ( V_237 ) ) {
V_267 = V_237 ;
V_270 = V_269 ;
}
}
}
if ( V_267 )
V_181 += F_113 ( V_40 , V_267 , V_270 , V_268 ,
V_235 ) ;
return V_181 ;
}
static void
F_121 ( struct V_39 * V_40 , const T_1 * V_237 )
{
T_1 V_22 = F_114 ( V_237 ) ;
if ( V_22 >= 6 ) {
V_40 -> V_272 [ 5 ] |= ( V_237 [ 6 ] >> 7 ) << 1 ;
V_40 -> V_273 = V_237 [ 6 ] & 1 ;
}
if ( V_22 >= 7 )
V_40 -> V_274 = V_237 [ 7 ] * 5 ;
if ( V_22 >= 8 ) {
V_40 -> V_275 [ 0 ] = V_237 [ 8 ] >> 7 ;
V_40 -> V_275 [ 1 ] = ( V_237 [ 8 ] >> 6 ) & 1 ;
}
if ( V_22 >= 9 )
V_40 -> V_276 [ 0 ] = V_237 [ 9 ] ;
if ( V_22 >= 10 )
V_40 -> V_277 [ 0 ] = V_237 [ 10 ] ;
if ( V_22 >= 11 )
V_40 -> V_276 [ 1 ] = V_237 [ 11 ] ;
if ( V_22 >= 12 )
V_40 -> V_277 [ 1 ] = V_237 [ 12 ] ;
F_14 ( L_16
L_17
L_18
L_19
L_20 ,
V_40 -> V_273 ,
V_40 -> V_274 ,
( int ) V_40 -> V_275 [ 0 ] ,
( int ) V_40 -> V_275 [ 1 ] ,
V_40 -> V_276 [ 0 ] ,
V_40 -> V_276 [ 1 ] ,
V_40 -> V_277 [ 0 ] ,
V_40 -> V_277 [ 1 ] ) ;
}
static void
F_122 ( struct V_92 * V_60 , void * V_20 )
{
if ( V_60 -> V_20 . V_188 . type == V_278 )
* ( T_1 * * ) V_20 = V_60 -> V_20 . V_188 . V_20 . V_279 . V_279 ;
}
void F_123 ( struct V_39 * V_40 , struct V_11 * V_11 )
{
T_6 * V_272 = V_40 -> V_272 ;
T_1 * V_261 ;
T_1 * V_38 ;
T_1 * V_237 ;
int V_280 = 0 ;
int V_281 ;
int V_269 ;
memset ( V_272 , 0 , sizeof( V_40 -> V_272 ) ) ;
V_261 = F_91 ( V_11 ) ;
if ( ! V_261 ) {
F_14 ( L_21 ) ;
return;
}
V_38 = NULL ;
F_43 ( ( T_1 * ) V_11 , F_122 , & V_38 ) ;
for ( V_281 = 0 ; V_38 && V_281 < 13 ; V_281 ++ ) {
if ( V_38 [ V_281 ] == 0x0a )
break;
V_272 [ 20 + V_281 ] = V_38 [ V_281 ] ;
}
V_272 [ 4 ] = ( V_261 [ 1 ] << 5 ) | V_281 ;
F_14 ( L_22 , V_272 + 20 ) ;
V_272 [ 0 ] = 2 << 3 ;
V_272 [ 16 ] = V_11 -> V_53 [ 0 ] ;
V_272 [ 17 ] = V_11 -> V_53 [ 1 ] ;
V_272 [ 18 ] = V_11 -> V_282 [ 0 ] ;
V_272 [ 19 ] = V_11 -> V_282 [ 1 ] ;
if ( F_116 ( V_261 ) >= 3 ) {
int V_2 , V_25 , V_262 ;
if ( F_117 ( V_261 , & V_25 , & V_262 ) ) {
V_25 = 0 ;
V_262 = 0 ;
}
F_120 (cea, i, start, end) {
V_237 = & V_261 [ V_2 ] ;
V_269 = F_114 ( V_237 ) ;
switch ( F_115 ( V_237 ) ) {
case V_283 :
V_280 = V_269 / 3 ;
if ( V_269 >= 1 )
memcpy ( V_272 + 20 + V_281 , & V_237 [ 1 ] , V_269 ) ;
break;
case V_284 :
if ( V_269 >= 1 )
V_272 [ 7 ] = V_237 [ 1 ] ;
break;
case V_265 :
if ( F_118 ( V_237 ) )
F_121 ( V_40 , V_237 ) ;
break;
default:
break;
}
}
}
V_272 [ 5 ] |= V_280 << 4 ;
V_272 [ V_285 ] =
F_94 ( F_124 ( V_272 ) , 4 ) ;
F_14 ( L_23 ,
F_125 ( V_272 ) , V_280 ) ;
}
int F_126 ( struct V_11 * V_11 , struct V_286 * * V_287 )
{
int V_288 = 0 ;
int V_2 , V_25 , V_262 , V_269 ;
T_1 * V_261 ;
V_261 = F_91 ( V_11 ) ;
if ( ! V_261 ) {
F_14 ( L_24 ) ;
return - V_289 ;
}
if ( F_116 ( V_261 ) < 3 ) {
F_14 ( L_25 ) ;
return - V_290 ;
}
if ( F_117 ( V_261 , & V_25 , & V_262 ) ) {
F_14 ( L_26 ) ;
return - V_291 ;
}
F_120 (cea, i, start, end) {
T_1 * V_237 = & V_261 [ V_2 ] ;
if ( F_115 ( V_237 ) == V_283 ) {
int V_41 ;
V_269 = F_114 ( V_237 ) ;
V_288 = V_269 / 3 ;
* V_287 = F_127 ( V_288 , sizeof( * * V_287 ) , V_47 ) ;
if ( ! * V_287 )
return - V_292 ;
for ( V_41 = 0 ; V_41 < V_288 ; V_41 ++ ) {
T_1 * V_293 = & V_237 [ 1 + V_41 * 3 ] ;
( * V_287 ) [ V_41 ] . V_294 = ( V_293 [ 0 ] & 0x78 ) >> 3 ;
( * V_287 ) [ V_41 ] . V_295 = V_293 [ 0 ] & 0x7 ;
( * V_287 ) [ V_41 ] . V_296 = V_293 [ 1 ] & 0x7F ;
( * V_287 ) [ V_41 ] . V_297 = V_293 [ 2 ] ;
}
break;
}
}
return V_288 ;
}
int F_128 ( struct V_11 * V_11 , T_1 * * V_298 )
{
int V_288 = 0 ;
int V_2 , V_25 , V_262 , V_269 ;
const T_1 * V_261 ;
V_261 = F_91 ( V_11 ) ;
if ( ! V_261 ) {
F_14 ( L_24 ) ;
return - V_289 ;
}
if ( F_116 ( V_261 ) < 3 ) {
F_14 ( L_25 ) ;
return - V_290 ;
}
if ( F_117 ( V_261 , & V_25 , & V_262 ) ) {
F_14 ( L_26 ) ;
return - V_291 ;
}
F_120 (cea, i, start, end) {
const T_1 * V_237 = & V_261 [ V_2 ] ;
if ( F_115 ( V_237 ) == V_284 ) {
V_269 = F_114 ( V_237 ) ;
if ( V_269 == 3 ) {
* V_298 = F_25 ( & V_237 [ 1 ] , V_269 , V_47 ) ;
if ( ! * V_298 )
return - V_292 ;
V_288 = V_269 ;
break;
}
}
}
return V_288 ;
}
int F_129 ( struct V_39 * V_40 ,
struct V_59 * V_72 )
{
int V_2 = ! ! ( V_72 -> V_34 & V_129 ) ;
int V_107 , V_299 ;
if ( ! V_40 -> V_275 [ 0 ] )
return 0 ;
if ( ! V_40 -> V_275 [ 1 ] )
V_2 = 0 ;
V_107 = V_40 -> V_277 [ V_2 ] ;
V_299 = V_40 -> V_276 [ V_2 ] ;
if ( V_107 == 255 || V_299 == 255 )
return 0 ;
if ( V_107 )
V_107 = F_42 ( 2 * ( V_107 - 1 ) , 500 ) ;
if ( V_299 )
V_299 = F_42 ( 2 * ( V_299 - 1 ) , 500 ) ;
return F_130 ( V_299 - V_107 , 0 ) ;
}
struct V_39 * F_131 ( struct V_300 * V_301 ,
struct V_59 * V_72 )
{
struct V_39 * V_40 ;
struct V_79 * V_51 = V_301 -> V_51 ;
F_6 ( ! F_132 ( & V_51 -> V_302 . V_303 ) ) ;
F_6 ( ! F_133 ( & V_51 -> V_302 . V_304 ) ) ;
F_55 (connector, &dev->mode_config.connector_list, head)
if ( V_40 -> V_301 == V_301 && V_40 -> V_272 [ 0 ] )
return V_40 ;
return NULL ;
}
bool F_134 ( struct V_11 * V_11 )
{
T_1 * V_218 ;
int V_2 ;
int V_305 , V_306 ;
V_218 = F_91 ( V_11 ) ;
if ( ! V_218 )
return false ;
if ( F_117 ( V_218 , & V_305 , & V_306 ) )
return false ;
F_120 (edid_ext, i, start_offset, end_offset) {
if ( F_118 ( & V_218 [ V_2 ] ) )
return true ;
}
return false ;
}
bool F_135 ( struct V_11 * V_11 )
{
T_1 * V_218 ;
int V_2 , V_41 ;
bool V_307 = false ;
int V_305 , V_306 ;
V_218 = F_91 ( V_11 ) ;
if ( ! V_218 )
goto V_262;
V_307 = ( ( V_218 [ 3 ] & V_308 ) != 0 ) ;
if ( V_307 ) {
F_14 ( L_27 ) ;
goto V_262;
}
if ( F_117 ( V_218 , & V_305 , & V_306 ) )
goto V_262;
F_120 (edid_ext, i, start_offset, end_offset) {
if ( F_115 ( & V_218 [ V_2 ] ) == V_283 ) {
V_307 = true ;
for ( V_41 = 1 ; V_41 < F_114 ( & V_218 [ V_2 ] ) + 1 ; V_41 += 3 )
F_14 ( L_28 ,
( V_218 [ V_2 + V_41 ] >> 3 ) & 0xf ) ;
goto V_262;
}
}
V_262:
return V_307 ;
}
bool F_136 ( struct V_11 * V_11 )
{
T_1 * V_218 ;
int V_2 , V_25 , V_262 ;
V_218 = F_91 ( V_11 ) ;
if ( ! V_218 )
return false ;
if ( F_117 ( V_218 , & V_25 , & V_262 ) )
return false ;
F_120 (edid_ext, i, start, end) {
if ( F_115 ( & V_218 [ V_2 ] ) == V_309 &&
F_114 ( & V_218 [ V_2 ] ) == 2 ) {
F_14 ( L_29 , V_218 [ V_2 + 2 ] ) ;
return V_218 [ V_2 + 2 ] & V_310 ;
}
}
return false ;
}
static bool F_137 ( struct V_11 * V_11 ,
struct V_311 * V_312 ,
struct V_39 * V_40 )
{
T_1 * V_218 , * V_267 ;
int V_2 ;
int V_305 , V_306 ;
unsigned int V_313 = 0 ;
V_218 = F_91 ( V_11 ) ;
if ( ! V_218 )
return false ;
if ( F_117 ( V_218 , & V_305 , & V_306 ) )
return false ;
F_120 (edid_ext, i, start_offset, end_offset) {
if ( F_118 ( & V_218 [ V_2 ] ) ) {
V_312 -> V_314 = 8 ;
V_267 = & V_218 [ V_2 ] ;
if ( F_114 ( V_267 ) < 6 )
return false ;
if ( V_267 [ 6 ] & V_315 ) {
V_313 = 10 ;
V_312 -> V_316 |= V_315 ;
F_7 ( L_30 ,
V_40 -> V_38 ) ;
}
if ( V_267 [ 6 ] & V_317 ) {
V_313 = 12 ;
V_312 -> V_316 |= V_317 ;
F_7 ( L_31 ,
V_40 -> V_38 ) ;
}
if ( V_267 [ 6 ] & V_318 ) {
V_313 = 16 ;
V_312 -> V_316 |= V_318 ;
F_7 ( L_32 ,
V_40 -> V_38 ) ;
}
if ( V_313 > 0 ) {
F_7 ( L_33 ,
V_40 -> V_38 , V_313 ) ;
V_312 -> V_314 = V_313 ;
V_312 -> V_319 = V_320 ;
if ( V_267 [ 6 ] & V_321 ) {
V_312 -> V_319 |= V_322 ;
F_7 ( L_34 ,
V_40 -> V_38 ) ;
}
if ( ! ( V_267 [ 6 ] & V_317 ) ) {
F_7 ( L_35 ,
V_40 -> V_38 ) ;
}
return true ;
}
else {
F_7 ( L_36 ,
V_40 -> V_38 ) ;
}
}
}
return false ;
}
static void F_138 ( struct V_11 * V_11 ,
struct V_311 * V_312 ,
struct V_39 * V_40 )
{
T_1 * V_218 ;
V_312 -> V_163 = V_11 -> V_170 * 10 ;
V_312 -> V_166 = V_11 -> V_171 * 10 ;
V_312 -> V_314 = 0 ;
V_312 -> V_319 = 0 ;
if ( V_11 -> V_15 < 3 )
return;
if ( ! ( V_11 -> V_99 & V_100 ) )
return;
V_218 = F_91 ( V_11 ) ;
if ( V_218 ) {
V_312 -> V_323 = V_218 [ 1 ] ;
V_312 -> V_319 = V_320 ;
if ( V_218 [ 3 ] & V_324 )
V_312 -> V_319 |= V_322 ;
if ( V_218 [ 3 ] & V_325 )
V_312 -> V_319 |= V_326 ;
}
F_137 ( V_11 , V_312 , V_40 ) ;
if ( V_11 -> V_15 < 4 )
return;
switch ( V_11 -> V_99 & V_327 ) {
case V_328 :
V_312 -> V_314 = 6 ;
break;
case V_329 :
V_312 -> V_314 = 8 ;
break;
case V_330 :
V_312 -> V_314 = 10 ;
break;
case V_331 :
V_312 -> V_314 = 12 ;
break;
case V_332 :
V_312 -> V_314 = 14 ;
break;
case V_333 :
V_312 -> V_314 = 16 ;
break;
case V_334 :
default:
V_312 -> V_314 = 0 ;
break;
}
F_7 ( L_37 ,
V_40 -> V_38 , V_312 -> V_314 ) ;
V_312 -> V_319 |= V_320 ;
if ( V_11 -> V_101 & V_335 )
V_312 -> V_319 |= V_322 ;
if ( V_11 -> V_101 & V_336 )
V_312 -> V_319 |= V_326 ;
}
int F_139 ( struct V_39 * V_40 , struct V_11 * V_11 )
{
int V_337 = 0 ;
T_3 V_58 ;
if ( V_11 == NULL ) {
return 0 ;
}
if ( ! F_11 ( V_11 ) ) {
F_19 ( V_40 -> V_51 -> V_51 , L_38 ,
V_40 -> V_38 ) ;
return 0 ;
}
V_58 = F_27 ( V_11 ) ;
V_337 += F_89 ( V_40 , V_11 , V_58 ) ;
V_337 += F_87 ( V_40 , V_11 ) ;
V_337 += F_84 ( V_40 , V_11 ) ;
V_337 += F_82 ( V_40 , V_11 ) ;
if ( V_11 -> V_101 & V_102 )
V_337 += F_79 ( V_40 , V_11 ) ;
V_337 += F_119 ( V_40 , V_11 ) ;
V_337 += F_101 ( V_40 , V_11 ) ;
if ( V_58 & ( V_67 | V_68 ) )
F_30 ( V_40 , V_58 ) ;
F_138 ( V_11 , & V_40 -> V_338 , V_40 ) ;
if ( V_58 & V_339 )
V_40 -> V_338 . V_314 = 8 ;
if ( V_58 & V_340 )
V_40 -> V_338 . V_314 = 12 ;
return V_337 ;
}
int F_140 ( struct V_39 * V_40 ,
int V_74 , int V_78 )
{
int V_2 , V_288 , V_337 = 0 ;
struct V_59 * V_72 ;
struct V_79 * V_51 = V_40 -> V_51 ;
V_288 = sizeof( V_84 ) / sizeof( struct V_59 ) ;
if ( V_74 < 0 )
V_74 = 0 ;
if ( V_78 < 0 )
V_78 = 0 ;
for ( V_2 = 0 ; V_2 < V_288 ; V_2 ++ ) {
const struct V_59 * V_85 = & V_84 [ V_2 ] ;
if ( V_74 && V_78 ) {
if ( V_85 -> V_74 > V_74 ||
V_85 -> V_78 > V_78 )
continue;
}
if ( F_35 ( V_85 ) > 61 )
continue;
V_72 = F_39 ( V_51 , V_85 ) ;
if ( V_72 ) {
F_73 ( V_40 , V_72 ) ;
V_337 ++ ;
}
}
return V_337 ;
}
void F_141 ( struct V_39 * V_40 ,
int V_341 , int V_342 )
{
struct V_59 * V_72 ;
F_55 (mode, &connector->probed_modes, head) {
if ( V_72 -> V_74 == V_341 &&
V_72 -> V_78 == V_342 )
V_72 -> type |= V_70 ;
}
}
int
F_142 ( struct V_343 * V_344 ,
const struct V_59 * V_72 )
{
int V_345 ;
if ( ! V_344 || ! V_72 )
return - V_346 ;
V_345 = F_143 ( V_344 ) ;
if ( V_345 < 0 )
return V_345 ;
if ( V_72 -> V_34 & V_347 )
V_344 -> V_348 = 1 ;
V_344 -> V_226 = F_95 ( V_72 ) ;
V_344 -> V_349 = V_350 ;
if ( V_72 -> V_227 == V_351 ||
V_72 -> V_227 == V_352 )
V_344 -> V_349 = V_72 -> V_227 ;
else if ( V_344 -> V_226 > 0 )
V_344 -> V_349 = F_98 (
V_344 -> V_226 ) ;
V_344 -> V_353 = V_354 ;
V_344 -> V_355 = V_356 ;
return 0 ;
}
static enum V_357
F_144 ( const struct V_59 * V_72 )
{
T_3 V_358 = V_72 -> V_34 & V_233 ;
switch ( V_358 ) {
case V_248 :
return V_359 ;
case V_360 :
return V_361 ;
case V_362 :
return V_363 ;
case V_364 :
return V_365 ;
case V_366 :
return V_367 ;
case V_368 :
return V_369 ;
case V_249 :
return V_370 ;
case V_250 :
return V_371 ;
default:
return V_372 ;
}
}
int
F_145 ( struct V_373 * V_344 ,
const struct V_59 * V_72 )
{
int V_345 ;
T_3 V_374 ;
T_1 V_246 ;
if ( ! V_344 || ! V_72 )
return - V_346 ;
V_246 = F_100 ( V_72 ) ;
V_374 = V_72 -> V_34 & V_233 ;
if ( ! V_246 && ! V_374 )
return - V_346 ;
if ( V_246 && V_374 )
return - V_346 ;
V_345 = F_146 ( V_344 ) ;
if ( V_345 < 0 )
return V_345 ;
if ( V_246 )
V_344 -> V_246 = V_246 ;
else
V_344 -> V_375 = F_144 ( V_72 ) ;
return 0 ;
}
static int F_147 ( struct V_39 * V_40 ,
T_1 * V_376 , int V_8 ,
bool V_377 )
{
int V_378 = 0 ;
struct V_379 * V_380 ;
struct V_381 * V_9 ;
T_1 V_5 = 0 ;
int V_2 ;
if ( V_377 )
V_378 = 1 ;
V_380 = (struct V_379 * ) & V_376 [ V_378 ] ;
F_14 ( L_39 ,
V_380 -> V_382 , V_380 -> V_383 , V_380 -> V_384 , V_380 -> V_385 ) ;
if ( V_380 -> V_383 + 5 > V_8 - V_378 )
return - V_346 ;
for ( V_2 = V_378 ; V_2 <= V_380 -> V_383 + 5 ; V_2 ++ ) {
V_5 += V_376 [ V_2 ] ;
}
if ( V_5 ) {
F_8 ( L_40 , V_5 ) ;
return - V_346 ;
}
V_9 = (struct V_381 * ) & V_376 [ V_378 + 4 ] ;
F_14 ( L_41 ,
V_9 -> V_386 , V_9 -> V_382 , V_9 -> V_387 ) ;
switch ( V_9 -> V_386 ) {
case V_388 : {
struct V_389 * V_390 = (struct V_389 * ) V_9 ;
T_5 V_122 , V_123 ;
T_1 V_391 , V_392 ;
T_1 V_393 , V_394 ;
struct V_395 * V_396 ;
V_122 = V_390 -> V_397 [ 0 ] | V_390 -> V_397 [ 1 ] << 8 ;
V_123 = V_390 -> V_397 [ 2 ] | V_390 -> V_397 [ 3 ] << 8 ;
V_393 = ( V_390 -> V_398 [ 0 ] & 0xf ) | ( V_390 -> V_398 [ 2 ] & 0x30 ) ;
V_394 = ( V_390 -> V_398 [ 0 ] >> 4 ) | ( ( V_390 -> V_398 [ 2 ] >> 2 ) & 0x30 ) ;
V_391 = ( V_390 -> V_398 [ 1 ] & 0xf ) | ( ( V_390 -> V_398 [ 2 ] & 0x3 ) << 4 ) ;
V_392 = ( V_390 -> V_398 [ 1 ] >> 4 ) | ( ( ( V_390 -> V_398 [ 2 ] >> 2 ) & 0x3 ) << 4 ) ;
V_40 -> V_399 = true ;
if ( V_390 -> V_400 & 0x80 )
V_40 -> V_401 = true ;
V_40 -> V_394 = V_394 + 1 ;
V_40 -> V_393 = V_393 + 1 ;
V_40 -> V_392 = V_392 ;
V_40 -> V_391 = V_391 ;
V_40 -> V_402 = V_122 + 1 ;
V_40 -> V_403 = V_123 + 1 ;
F_14 ( L_42 , V_390 -> V_400 ) ;
F_14 ( L_43 , V_122 + 1 , V_123 + 1 ) ;
F_14 ( L_44 ,
V_394 + 1 , V_393 + 1 , V_392 , V_391 ) ;
F_14 ( L_45 , V_390 -> V_404 [ 0 ] , V_390 -> V_404 [ 1 ] , V_390 -> V_404 [ 2 ] ) ;
V_396 = F_148 ( V_40 -> V_51 , V_390 -> V_404 ) ;
if ( ! V_396 ) {
V_396 = F_149 ( V_40 -> V_51 , V_390 -> V_404 ) ;
}
if ( ! V_396 )
return - V_292 ;
if ( V_40 -> V_405 != V_396 ) {
if ( V_40 -> V_405 ) {
F_150 ( V_40 -> V_51 , V_40 -> V_405 ) ;
}
V_40 -> V_405 = V_396 ;
} else
F_150 ( V_40 -> V_51 , V_396 ) ;
}
break;
default:
F_9 ( L_46 , V_9 -> V_386 ) ;
break;
}
return 0 ;
}
static void F_23 ( struct V_39 * V_40 ,
struct V_11 * V_11 )
{
void * V_376 = NULL ;
int V_28 ;
V_40 -> V_399 = false ;
V_376 = F_92 ( V_11 ) ;
if ( ! V_376 ) {
goto V_406;
}
V_28 = F_147 ( V_40 , V_376 , V_6 , true ) ;
if ( V_28 < 0 )
goto V_406;
if ( ! V_40 -> V_399 )
goto V_406;
return;
V_406:
if ( V_40 -> V_405 ) {
F_150 ( V_40 -> V_51 , V_40 -> V_405 ) ;
V_40 -> V_405 = NULL ;
}
return;
}
