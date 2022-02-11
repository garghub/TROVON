T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned char * V_4 = V_1 -> V_4 ;
if ( V_1 -> V_5 < V_1 -> V_6 )
return V_7 ;
switch ( V_1 -> type ) {
case V_8 :
F_2 ( V_3 , V_9 , - ( signed char ) V_4 [ 3 ] ) ;
break;
case V_10 :
switch ( V_4 [ 3 ] & 0xC0 ) {
case 0x80 :
F_2 ( V_3 , V_9 , ( int ) ( V_4 [ 3 ] & 32 ) - ( int ) ( V_4 [ 3 ] & 31 ) ) ;
break;
case 0x40 :
F_2 ( V_3 , V_11 , ( int ) ( V_4 [ 3 ] & 32 ) - ( int ) ( V_4 [ 3 ] & 31 ) ) ;
break;
case 0x00 :
case 0xC0 :
F_2 ( V_3 , V_9 , ( int ) ( V_4 [ 3 ] & 8 ) - ( int ) ( V_4 [ 3 ] & 7 ) ) ;
F_3 ( V_3 , V_12 , ( V_4 [ 3 ] >> 4 ) & 1 ) ;
F_3 ( V_3 , V_13 , ( V_4 [ 3 ] >> 5 ) & 1 ) ;
break;
}
break;
case V_14 :
F_2 ( V_3 , V_9 , - ( signed char ) V_4 [ 3 ] ) ;
F_3 ( V_3 , V_12 , ( V_4 [ 0 ] >> 6 ) & 1 ) ;
F_3 ( V_3 , V_13 , ( V_4 [ 0 ] >> 7 ) & 1 ) ;
break;
case V_15 :
F_3 ( V_3 , V_13 , ( V_4 [ 0 ] >> 3 ) & 1 ) ;
V_4 [ 1 ] |= ( V_4 [ 0 ] & 0x40 ) << 1 ;
break;
case V_16 :
F_3 ( V_3 , V_12 , ( V_4 [ 0 ] >> 3 ) & 1 ) ;
V_4 [ 0 ] |= 0x08 ;
break;
default:
break;
}
F_3 ( V_3 , V_17 , V_4 [ 0 ] & 1 ) ;
F_3 ( V_3 , V_18 , ( V_4 [ 0 ] >> 2 ) & 1 ) ;
F_3 ( V_3 , V_19 , ( V_4 [ 0 ] >> 1 ) & 1 ) ;
F_2 ( V_3 , V_20 , V_4 [ 1 ] ? ( int ) V_4 [ 1 ] - ( int ) ( ( V_4 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_2 ( V_3 , V_21 , V_4 [ 2 ] ? ( int ) ( ( V_4 [ 0 ] << 3 ) & 0x100 ) - ( int ) V_4 [ 2 ] : 0 ) ;
F_4 ( V_3 ) ;
return V_22 ;
}
void F_5 ( struct V_1 * V_1 , struct V_23 * V_24 ,
unsigned long V_25 )
{
F_6 ( V_26 , V_24 , V_25 ) ;
}
static inline void F_7 ( struct V_1 * V_1 , enum V_27 V_28 )
{
V_1 -> V_29 = V_28 ;
V_1 -> V_5 = V_1 -> V_30 = 0 ;
V_1 -> V_31 . V_32 = 0 ;
V_1 -> V_33 = V_34 ;
}
void F_8 ( struct V_1 * V_1 , enum V_27 V_28 )
{
F_9 ( V_1 -> V_31 . V_35 ) ;
F_7 ( V_1 , V_28 ) ;
F_10 ( V_1 -> V_31 . V_35 ) ;
}
static int F_11 ( struct V_1 * V_1 )
{
T_1 V_36 = V_1 -> V_37 ( V_1 ) ;
switch ( V_36 ) {
case V_38 :
if ( V_1 -> V_29 == V_39 ) {
F_12 ( V_1 ,
L_1 ,
V_1 -> V_40 , V_1 -> V_41 ,
V_1 -> V_5 ) ;
if ( ++ V_1 -> V_30 == V_1 -> V_42 ) {
F_7 ( V_1 , V_43 ) ;
F_13 ( V_1 ,
L_2 ) ;
F_14 ( V_1 -> V_31 . V_35 ) ;
return - 1 ;
}
}
V_1 -> V_5 = 0 ;
break;
case V_22 :
V_1 -> V_5 = 0 ;
if ( V_1 -> V_30 ) {
V_1 -> V_30 = 0 ;
F_13 ( V_1 ,
L_3 ,
V_1 -> V_40 , V_1 -> V_41 ) ;
}
break;
case V_7 :
break;
}
return 0 ;
}
static T_2 F_15 ( struct V_35 * V_35 ,
unsigned char V_44 , unsigned int V_32 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
if ( V_1 -> V_29 == V_43 )
goto V_45;
if ( F_17 ( ( V_32 & V_46 ) ||
( ( V_32 & V_47 ) && ! V_1 -> V_48 ) ) ) {
if ( V_1 -> V_29 == V_39 )
F_12 ( V_1 ,
L_4 ,
V_32 & V_46 ? L_5 : L_6 ,
V_32 & V_47 ? L_7 : L_6 ) ;
F_18 ( & V_1 -> V_31 ) ;
goto V_45;
}
if ( F_17 ( V_1 -> V_31 . V_32 & V_49 ) )
if ( F_19 ( & V_1 -> V_31 , V_44 ) )
goto V_45;
if ( F_17 ( V_1 -> V_31 . V_32 & V_50 ) )
if ( F_20 ( & V_1 -> V_31 , V_44 ) )
goto V_45;
if ( V_1 -> V_29 <= V_51 )
goto V_45;
if ( V_1 -> V_29 == V_39 &&
V_1 -> V_5 && F_21 ( V_34 , V_1 -> V_33 + V_52 / 2 ) ) {
F_22 ( V_1 , L_8 ,
V_1 -> V_40 , V_1 -> V_41 , V_1 -> V_5 ) ;
V_1 -> V_53 = V_1 -> V_4 [ 0 ] ;
F_7 ( V_1 , V_51 ) ;
F_5 ( V_1 , & V_1 -> V_54 , 0 ) ;
goto V_45;
}
V_1 -> V_4 [ V_1 -> V_5 ++ ] = V_44 ;
if ( F_17 ( V_1 -> V_4 [ 0 ] == V_55 && V_1 -> V_5 <= 2 ) ) {
if ( V_1 -> V_5 == 1 ) {
V_1 -> V_33 = V_34 ;
goto V_45;
}
if ( V_1 -> V_4 [ 1 ] == V_56 ||
( V_1 -> type == V_57 &&
V_1 -> V_4 [ 1 ] == V_55 ) ) {
F_7 ( V_1 , V_43 ) ;
F_14 ( V_35 ) ;
goto V_45;
}
V_1 -> V_5 = 1 ;
if ( F_11 ( V_1 ) )
goto V_45;
V_1 -> V_4 [ V_1 -> V_5 ++ ] = V_44 ;
}
if ( V_1 -> V_29 == V_39 &&
V_1 -> V_5 == 1 && V_1 -> V_58 &&
F_21 ( V_34 , V_1 -> V_33 + V_1 -> V_58 * V_52 ) ) {
V_1 -> V_53 = V_1 -> V_4 [ 0 ] ;
F_7 ( V_1 , V_51 ) ;
F_5 ( V_1 , & V_1 -> V_54 , 0 ) ;
goto V_45;
}
V_1 -> V_33 = V_34 ;
F_11 ( V_1 ) ;
V_45:
return V_59 ;
}
int F_23 ( struct V_1 * V_1 , unsigned char V_60 )
{
int V_61 ;
if ( F_24 ( & V_1 -> V_31 , NULL , V_62 ) )
return - 1 ;
for ( V_61 = 6 ; V_61 >= 0 ; V_61 -= 2 ) {
unsigned char V_63 = ( V_60 >> V_61 ) & 3 ;
if ( F_24 ( & V_1 -> V_31 , & V_63 , V_64 ) )
return - 1 ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_1 )
{
unsigned char V_65 [ 2 ] ;
if ( F_24 ( & V_1 -> V_31 , V_65 , V_66 ) )
return - 1 ;
if ( V_65 [ 0 ] != V_55 && V_65 [ 1 ] != V_56 )
return - 1 ;
return 0 ;
}
void F_26 ( struct V_1 * V_1 , unsigned int V_67 )
{
static const unsigned char V_68 [] = { 0 , 1 , 2 , 2 , 3 } ;
unsigned char V_69 ;
if ( V_67 == 0 || V_67 > 200 )
V_67 = 200 ;
V_69 = V_68 [ V_67 / 50 ] ;
F_24 ( & V_1 -> V_31 , & V_69 , V_64 ) ;
V_1 -> V_67 = 25 << V_69 ;
}
static void F_27 ( struct V_1 * V_1 , unsigned int V_70 )
{
static const unsigned char V_71 [] = { 200 , 100 , 80 , 60 , 40 , 20 , 10 , 0 } ;
unsigned char V_72 ;
int V_61 = 0 ;
while ( V_71 [ V_61 ] > V_70 ) V_61 ++ ;
V_72 = V_71 [ V_61 ] ;
F_24 ( & V_1 -> V_31 , & V_72 , V_73 ) ;
V_1 -> V_70 = V_72 ;
}
static void F_28 ( struct V_1 * V_1 , enum V_74 V_75 )
{
F_24 ( & V_1 -> V_31 , NULL ,
V_75 == V_76 ? V_77 :
V_62 ) ;
}
static int F_29 ( struct V_1 * V_1 )
{
return F_24 ( & V_1 -> V_31 , V_1 -> V_4 ,
V_78 | ( V_1 -> V_6 << 8 ) ) ;
}
static bool F_30 ( const char * V_79 , const char * const V_80 [] )
{
int V_61 ;
for ( V_61 = 0 ; V_80 [ V_61 ] ; V_61 ++ )
if ( ! strcasecmp ( V_79 , V_80 [ V_61 ] ) )
return true ;
return false ;
}
bool F_31 ( struct V_1 * V_1 , const char * const V_80 [] )
{
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
char * V_69 , * V_81 , * V_82 ;
bool V_83 = false ;
if ( strncmp ( V_35 -> V_84 , L_9 , 5 ) )
return false ;
V_81 = F_32 ( & V_35 -> V_84 [ 5 ] ,
sizeof( V_35 -> V_84 ) - 5 ,
V_85 ) ;
if ( ! V_81 )
return false ;
V_82 = V_81 ;
while ( ( V_69 = F_33 ( & V_81 , L_10 ) ) != NULL ) {
if ( F_30 ( V_69 , V_80 ) ) {
V_83 = true ;
break;
}
}
F_34 ( V_82 ) ;
return V_83 ;
}
static int F_35 ( struct V_1 * V_1 , bool V_86 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 4 ] ;
V_65 [ 0 ] = 3 ;
F_24 ( V_31 , V_65 , V_64 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , V_65 , V_87 ) ;
if ( V_65 [ 0 ] != 0x00 || V_65 [ 1 ] != 0x33 || V_65 [ 2 ] != 0x55 )
return - 1 ;
if ( V_86 ) {
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_13 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_12 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_9 , V_1 -> V_3 -> V_89 ) ;
V_1 -> V_90 = L_11 ;
V_1 -> V_40 = L_12 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , bool V_86 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 100 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
F_24 ( V_31 , V_65 , V_91 ) ;
if ( V_65 [ 0 ] != 3 )
return - 1 ;
if ( V_86 ) {
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_9 , V_1 -> V_3 -> V_89 ) ;
if ( ! V_1 -> V_90 )
V_1 -> V_90 = L_13 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_14 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_1 , bool V_86 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
F_37 ( V_1 , 0 ) ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
F_24 ( V_31 , V_65 , V_91 ) ;
if ( V_65 [ 0 ] != 4 )
return - 1 ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 40 ;
F_24 ( V_31 , V_65 , V_73 ) ;
if ( V_86 ) {
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_9 , V_1 -> V_3 -> V_89 ) ;
F_36 ( V_11 , V_1 -> V_3 -> V_89 ) ;
F_36 ( V_12 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_13 , V_1 -> V_3 -> V_88 ) ;
if ( ! V_1 -> V_90 )
V_1 -> V_90 = L_13 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_15 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , bool V_86 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
static const unsigned char V_92 [] = { 20 , 60 , 40 , 20 , 20 , 60 , 40 , 20 , 20 } ;
int V_61 ;
V_65 [ 0 ] = 10 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 0 ;
F_24 ( V_31 , V_65 , V_64 ) ;
for ( V_61 = 0 ; V_61 < F_40 ( V_92 ) ; V_61 ++ ) {
V_65 [ 0 ] = V_92 [ V_61 ] ;
F_24 ( V_31 , V_65 , V_73 ) ;
}
F_24 ( V_31 , V_65 , V_91 ) ;
if ( V_65 [ 0 ] != 2 )
return - 1 ;
if ( V_86 ) {
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_13 , V_1 -> V_3 -> V_88 ) ;
V_1 -> V_90 = L_16 ;
V_1 -> V_40 = L_17 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_1 , bool V_86 )
{
if ( V_86 ) {
if ( ! V_1 -> V_90 )
V_1 -> V_90 = L_13 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_12 ;
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_1 , bool V_86 )
{
if ( V_86 ) {
V_1 -> V_90 = L_18 ;
V_1 -> V_40 = L_19 ;
F_36 ( V_18 , V_1 -> V_3 -> V_88 ) ;
F_36 ( V_12 , V_1 -> V_3 -> V_88 ) ;
}
return 0 ;
}
static const struct V_93 * F_43 ( enum V_94 type )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < F_40 ( V_95 ) ; V_61 ++ )
if ( V_95 [ V_61 ] . type == type )
return & V_95 [ V_61 ] ;
return NULL ;
}
static const struct V_93 * F_44 ( enum V_94 type )
{
const struct V_93 * V_96 ;
V_96 = F_43 ( type ) ;
if ( V_96 )
return V_96 ;
F_45 ( 1 ) ;
return & V_95 [ 0 ] ;
}
static const struct V_93 * F_46 ( const char * V_40 , T_3 V_97 )
{
const struct V_93 * V_69 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_40 ( V_95 ) ; V_61 ++ ) {
V_69 = & V_95 [ V_61 ] ;
if ( ( strlen ( V_69 -> V_40 ) == V_97 && ! strncmp ( V_69 -> V_40 , V_40 , V_97 ) ) ||
( strlen ( V_69 -> V_98 ) == V_97 && ! strncmp ( V_69 -> V_98 , V_40 , V_97 ) ) )
return & V_95 [ V_61 ] ;
}
return NULL ;
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
memset ( V_2 -> V_99 , 0 , sizeof( V_2 -> V_99 ) ) ;
memset ( V_2 -> V_88 , 0 , sizeof( V_2 -> V_88 ) ) ;
memset ( V_2 -> V_89 , 0 , sizeof( V_2 -> V_89 ) ) ;
memset ( V_2 -> V_100 , 0 , sizeof( V_2 -> V_100 ) ) ;
memset ( V_2 -> V_101 , 0 , sizeof( V_2 -> V_101 ) ) ;
F_36 ( V_102 , V_2 -> V_99 ) ;
F_36 ( V_103 , V_2 -> V_99 ) ;
F_36 ( V_17 , V_2 -> V_88 ) ;
F_36 ( V_19 , V_2 -> V_88 ) ;
F_36 ( V_20 , V_2 -> V_89 ) ;
F_36 ( V_21 , V_2 -> V_89 ) ;
F_36 ( V_104 , V_2 -> V_105 ) ;
V_1 -> V_106 = F_27 ;
V_1 -> V_107 = F_26 ;
V_1 -> V_108 = F_28 ;
V_1 -> V_109 = F_29 ;
V_1 -> V_37 = F_1 ;
V_1 -> V_6 = 3 ;
V_1 -> V_110 = NULL ;
V_1 -> V_111 = NULL ;
V_1 -> V_112 = NULL ;
V_1 -> V_113 = NULL ;
V_1 -> V_114 = NULL ;
}
static bool F_48 ( struct V_1 * V_1 ,
enum V_94 type ,
unsigned int * V_115 ,
bool V_86 , bool V_116 )
{
const struct V_93 * V_96 ;
V_96 = F_43 ( type ) ;
if ( ! V_96 )
return false ;
if ( V_1 -> V_31 . V_35 -> V_79 . type == V_117 &&
! V_96 -> V_118 ) {
return false ;
}
if ( V_86 )
F_47 ( V_1 ) ;
if ( V_96 -> V_119 ( V_1 , V_86 ) != 0 )
return false ;
if ( V_86 && V_96 -> V_120 && V_116 ) {
if ( V_96 -> V_120 ( V_1 ) != 0 ) {
if ( * V_115 > V_10 )
* V_115 = V_10 ;
return false ;
}
}
return true ;
}
static int F_49 ( struct V_1 * V_1 ,
unsigned int V_115 , bool V_86 )
{
bool V_121 = false ;
if ( F_48 ( V_1 , V_122 ,
& V_115 , V_86 , false ) ) {
if ( V_115 > V_10 &&
F_50 ( V_123 ) &&
( ! V_86 || F_51 ( V_1 ) == 0 ) ) {
return V_122 ;
}
V_124 = V_115 = V_125 ;
}
if ( F_48 ( V_1 , V_126 , & V_115 ,
V_86 , V_115 > V_10 ) )
return V_126 ;
if ( F_48 ( V_1 , V_127 , & V_115 ,
V_86 , V_115 > V_10 ) )
return V_127 ;
if ( V_115 > V_10 &&
F_48 ( V_1 , V_15 , & V_115 ,
V_86 , true ) ) {
return V_15 ;
}
if ( V_115 > V_125 &&
F_48 ( V_1 , V_128 , & V_115 ,
V_86 , false ) ) {
V_121 = true ;
if ( V_115 > V_10 ) {
if ( F_50 ( V_129 ) &&
( ! V_86 || F_52 ( V_1 ) == 0 ) ) {
return V_128 ;
}
V_115 = V_10 ;
}
F_53 ( V_1 ) ;
}
if ( V_115 > V_10 &&
F_48 ( V_1 , V_130 , & V_115 ,
V_86 , true ) ) {
return V_130 ;
}
if ( V_115 > V_10 ) {
F_24 ( & V_1 -> V_31 , NULL , V_131 ) ;
if ( F_48 ( V_1 , V_132 ,
& V_115 , V_86 , true ) )
return V_132 ;
}
if ( V_115 > V_10 &&
F_48 ( V_1 , V_57 , & V_115 ,
V_86 , true ) ) {
return V_57 ;
}
if ( V_115 > V_10 &&
F_48 ( V_1 , V_133 ,
& V_115 , V_86 , true ) ) {
return V_133 ;
}
if ( V_115 > V_10 ) {
if ( F_48 ( V_1 , V_14 ,
& V_115 , V_86 , true ) )
return V_14 ;
if ( F_48 ( V_1 , V_134 ,
& V_115 , V_86 , true ) )
return V_134 ;
if ( F_48 ( V_1 , V_135 ,
& V_115 , V_86 , true ) )
return V_135 ;
if ( F_48 ( V_1 , V_136 ,
& V_115 , V_86 , true ) )
return V_136 ;
if ( F_48 ( V_1 , V_137 ,
& V_115 , V_86 , true ) )
return V_137 ;
}
if ( V_115 > V_10 &&
F_48 ( V_1 , V_138 ,
& V_115 , V_86 , true ) ) {
return V_138 ;
}
F_24 ( & V_1 -> V_31 , NULL , V_131 ) ;
F_25 ( V_1 ) ;
if ( V_115 >= V_10 &&
F_48 ( V_1 , V_10 ,
& V_115 , V_86 , true ) ) {
return V_10 ;
}
if ( V_115 >= V_8 &&
F_48 ( V_1 , V_8 ,
& V_115 , V_86 , true ) ) {
return V_8 ;
}
F_48 ( V_1 , V_125 ,
& V_115 , V_86 , true ) ;
if ( V_121 ) {
F_25 ( V_1 ) ;
}
return V_125 ;
}
static int F_54 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
V_65 [ 0 ] = 0xa5 ;
if ( F_24 ( V_31 , V_65 , V_91 ) )
return - 1 ;
if ( V_65 [ 0 ] != 0x00 && V_65 [ 0 ] != 0x03 &&
V_65 [ 0 ] != 0x04 && V_65 [ 0 ] != 0xff )
return - 1 ;
if ( F_24 ( V_31 , NULL , V_131 ) )
F_12 ( V_1 , L_20 ,
V_31 -> V_35 -> V_41 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_1 )
{
if ( V_124 != V_125 ) {
V_1 -> V_106 ( V_1 , V_1 -> V_70 ) ;
V_1 -> V_107 ( V_1 , V_1 -> V_67 ) ;
V_1 -> V_108 ( V_1 , V_139 ) ;
}
}
int F_56 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_140 ) ) {
F_12 ( V_1 , L_21 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
return - 1 ;
}
F_8 ( V_1 , V_39 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_141 ) ) {
F_12 ( V_1 , L_22 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
return - 1 ;
}
F_8 ( V_1 , V_142 ) ;
return 0 ;
}
static void F_58 ( struct V_143 * V_24 )
{
struct V_1 * V_144 = NULL , * V_1 =
F_59 ( V_24 , struct V_1 , V_54 . V_24 ) ;
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
T_1 V_36 = V_7 ;
bool V_145 = false , V_146 = false ;
int V_61 ;
F_60 ( & V_147 ) ;
if ( V_1 -> V_29 != V_51 )
goto V_45;
if ( V_35 -> V_144 && V_35 -> V_79 . type == V_117 ) {
V_144 = F_16 ( V_35 -> V_144 ) ;
F_57 ( V_144 ) ;
}
V_1 -> V_148 ++ ;
if ( F_61 ( & V_1 -> V_31 , V_141 , 20 ) ) {
if ( V_1 -> V_148 < 3 || V_1 -> V_149 )
V_145 = true ;
} else
V_1 -> V_149 = true ;
if ( ! V_145 ) {
if ( V_1 -> V_109 ( V_1 ) )
V_145 = true ;
else {
F_8 ( V_1 , V_142 ) ;
for ( V_61 = 0 ; V_61 < V_1 -> V_6 ; V_61 ++ ) {
V_1 -> V_5 ++ ;
V_36 = V_1 -> V_37 ( V_1 ) ;
if ( V_36 != V_7 )
break;
}
if ( V_36 != V_22 )
V_145 = true ;
F_8 ( V_1 , V_51 ) ;
}
}
for ( V_61 = 0 ; V_61 < 5 ; V_61 ++ ) {
if ( ! F_24 ( & V_1 -> V_31 , NULL , V_140 ) ) {
V_146 = true ;
break;
}
F_62 ( 200 ) ;
}
if ( ! V_146 ) {
F_12 ( V_1 , L_23 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
V_145 = true ;
}
if ( V_145 ) {
F_8 ( V_1 , V_43 ) ;
F_22 ( V_1 ,
L_24 ) ;
F_14 ( V_35 ) ;
} else
F_8 ( V_1 , V_39 ) ;
if ( V_144 )
F_56 ( V_144 ) ;
V_45:
F_63 ( & V_147 ) ;
}
static void F_64 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_144 = NULL ;
F_60 ( & V_147 ) ;
if ( V_35 -> V_144 && V_35 -> V_79 . type == V_117 ) {
V_144 = F_16 ( V_35 -> V_144 ) ;
F_57 ( V_144 ) ;
}
F_8 ( V_1 , V_150 ) ;
if ( F_24 ( & V_1 -> V_31 , NULL , V_141 ) )
F_12 ( V_1 , L_25 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
if ( V_1 -> V_112 )
V_1 -> V_112 ( V_1 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_131 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_140 ) ;
if ( V_144 ) {
if ( V_144 -> V_114 )
V_144 -> V_114 ( V_144 ) ;
F_56 ( V_144 ) ;
}
F_63 ( & V_147 ) ;
}
static void F_65 ( struct V_35 * V_35 )
{
struct V_1 * V_1 , * V_144 = NULL ;
V_1 = F_16 ( V_35 ) ;
F_66 ( & V_35 -> V_3 . V_151 , & V_152 ) ;
F_60 ( & V_147 ) ;
F_8 ( V_1 , V_142 ) ;
F_63 ( & V_147 ) ;
F_67 ( V_26 ) ;
F_60 ( & V_147 ) ;
if ( V_35 -> V_144 && V_35 -> V_79 . type == V_117 ) {
V_144 = F_16 ( V_35 -> V_144 ) ;
F_57 ( V_144 ) ;
}
if ( V_1 -> V_111 )
V_1 -> V_111 ( V_1 ) ;
if ( V_144 && V_144 -> V_114 )
V_144 -> V_114 ( V_144 ) ;
F_8 ( V_1 , V_43 ) ;
F_68 ( V_35 ) ;
F_69 ( V_35 , NULL ) ;
F_70 ( V_1 -> V_3 ) ;
F_34 ( V_1 ) ;
if ( V_144 )
F_56 ( V_144 ) ;
F_63 ( & V_147 ) ;
}
static int F_71 ( struct V_1 * V_1 ,
const struct V_93 * V_96 )
{
const struct V_93 * V_153 ;
struct V_2 * V_2 = V_1 -> V_3 ;
V_2 -> V_3 . V_144 = & V_1 -> V_31 . V_35 -> V_3 ;
if ( V_96 && ( V_96 -> V_119 || V_96 -> V_120 ) ) {
F_47 ( V_1 ) ;
if ( V_96 -> V_119 && V_96 -> V_119 ( V_1 , true ) < 0 )
return - 1 ;
if ( V_96 -> V_120 && V_96 -> V_120 ( V_1 ) < 0 )
return - 1 ;
V_1 -> type = V_96 -> type ;
V_153 = V_96 ;
} else {
V_1 -> type = F_49 ( V_1 ,
V_124 , true ) ;
V_153 = F_44 ( V_1 -> type ) ;
}
V_1 -> V_48 = V_153 -> V_48 ;
if ( V_1 -> V_6 == 3 )
V_1 -> V_58 = 0 ;
if ( V_1 -> V_58 && V_1 -> V_109 ( V_1 ) )
V_1 -> V_58 = 0 ;
snprintf ( V_1 -> V_154 , sizeof( V_1 -> V_154 ) , L_26 ,
V_153 -> V_40 , V_1 -> V_90 , V_1 -> V_40 ) ;
V_2 -> V_40 = V_1 -> V_154 ;
V_2 -> V_41 = V_1 -> V_41 ;
V_2 -> V_79 . V_155 = V_156 ;
V_2 -> V_79 . V_90 = 0x0002 ;
V_2 -> V_79 . V_157 = V_1 -> type ;
V_2 -> V_79 . V_158 = V_1 -> V_159 ;
return 0 ;
}
static int F_72 ( struct V_35 * V_35 , struct V_160 * V_161 )
{
struct V_1 * V_1 , * V_144 = NULL ;
struct V_2 * V_2 ;
int V_162 = 0 , error = - V_163 ;
F_60 ( & V_147 ) ;
if ( V_35 -> V_144 && V_35 -> V_79 . type == V_117 ) {
V_144 = F_16 ( V_35 -> V_144 ) ;
F_57 ( V_144 ) ;
}
V_1 = F_73 ( sizeof( struct V_1 ) , V_85 ) ;
V_2 = F_74 () ;
if ( ! V_1 || ! V_2 )
goto V_164;
F_75 ( & V_1 -> V_31 , V_35 ) ;
F_76 ( & V_1 -> V_54 , F_58 ) ;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_41 , sizeof( V_1 -> V_41 ) , L_27 , V_35 -> V_41 ) ;
F_8 ( V_1 , V_150 ) ;
F_69 ( V_35 , V_1 ) ;
error = F_77 ( V_35 , V_161 ) ;
if ( error )
goto V_165;
if ( V_35 -> V_79 . type == V_117 )
F_78 ( 10000 , 15000 ) ;
if ( F_54 ( V_1 ) < 0 ) {
error = - V_166 ;
goto V_167;
}
V_1 -> V_70 = V_168 ;
V_1 -> V_67 = V_169 ;
V_1 -> V_42 = V_170 ;
V_1 -> V_58 = V_144 ? 0 : V_171 ;
V_1 -> V_172 = V_173 ;
F_71 ( V_1 , NULL ) ;
F_8 ( V_1 , V_142 ) ;
F_55 ( V_1 ) ;
error = F_79 ( V_1 -> V_3 ) ;
if ( error )
goto V_174;
if ( V_144 && V_144 -> V_113 )
V_144 -> V_113 ( V_144 ) ;
error = F_80 ( & V_35 -> V_3 . V_151 , & V_152 ) ;
if ( error )
goto V_175;
F_56 ( V_1 ) ;
V_45:
if ( V_144 )
F_56 ( V_144 ) ;
F_63 ( & V_147 ) ;
return V_162 ;
V_175:
if ( V_144 && V_144 -> V_114 )
V_144 -> V_114 ( V_144 ) ;
F_70 ( V_1 -> V_3 ) ;
V_2 = NULL ;
V_174:
if ( V_1 -> V_111 )
V_1 -> V_111 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_167:
F_68 ( V_35 ) ;
V_165:
F_69 ( V_35 , NULL ) ;
V_164:
F_81 ( V_2 ) ;
F_34 ( V_1 ) ;
V_162 = error ;
goto V_45;
}
static int F_82 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_144 = NULL ;
unsigned char type ;
int V_36 = - 1 ;
F_60 ( & V_147 ) ;
if ( V_35 -> V_144 && V_35 -> V_79 . type == V_117 ) {
V_144 = F_16 ( V_35 -> V_144 ) ;
F_57 ( V_144 ) ;
}
F_8 ( V_1 , V_150 ) ;
if ( V_1 -> V_110 ) {
if ( V_1 -> V_110 ( V_1 ) )
goto V_45;
} else {
F_25 ( V_1 ) ;
if ( F_54 ( V_1 ) < 0 )
goto V_45;
type = F_49 ( V_1 , V_124 , false ) ;
if ( V_1 -> type != type )
goto V_45;
}
F_8 ( V_1 , V_142 ) ;
F_55 ( V_1 ) ;
if ( V_144 && V_144 -> V_113 )
V_144 -> V_113 ( V_144 ) ;
F_56 ( V_1 ) ;
V_36 = 0 ;
V_45:
if ( V_144 )
F_56 ( V_144 ) ;
F_63 ( & V_147 ) ;
return V_36 ;
}
T_4 F_83 ( struct V_176 * V_3 , struct V_177 * V_178 ,
char * V_179 )
{
struct V_35 * V_35 = F_84 ( V_3 ) ;
struct V_180 * V_181 = F_85 ( V_178 ) ;
struct V_1 * V_1 ;
V_1 = F_16 ( V_35 ) ;
return V_181 -> V_182 ( V_1 , V_181 -> V_44 , V_179 ) ;
}
T_4 F_86 ( struct V_176 * V_3 , struct V_177 * V_178 ,
const char * V_179 , T_3 V_183 )
{
struct V_35 * V_35 = F_84 ( V_3 ) ;
struct V_180 * V_181 = F_85 ( V_178 ) ;
struct V_1 * V_1 , * V_144 = NULL ;
int V_162 ;
V_162 = F_87 ( & V_147 ) ;
if ( V_162 )
goto V_45;
V_1 = F_16 ( V_35 ) ;
if ( V_181 -> V_184 ) {
if ( V_1 -> V_29 == V_43 ) {
V_162 = - V_166 ;
goto V_185;
}
if ( V_35 -> V_144 && V_35 -> V_79 . type == V_117 ) {
V_144 = F_16 ( V_35 -> V_144 ) ;
F_57 ( V_144 ) ;
}
F_57 ( V_1 ) ;
}
V_162 = V_181 -> V_186 ( V_1 , V_181 -> V_44 , V_179 , V_183 ) ;
if ( V_181 -> V_184 ) {
if ( V_162 != - V_166 )
F_56 ( V_1 ) ;
if ( V_144 )
F_56 ( V_144 ) ;
}
V_185:
F_63 ( & V_147 ) ;
V_45:
return V_162 ;
}
static T_4 F_88 ( struct V_1 * V_1 , void * V_187 , char * V_179 )
{
unsigned int * V_188 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_187 ) ;
return sprintf ( V_179 , L_28 , * V_188 ) ;
}
static T_4 F_89 ( struct V_1 * V_1 , void * V_187 , const char * V_179 , T_3 V_183 )
{
unsigned int * V_188 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_187 ) ;
unsigned int V_189 ;
int V_190 ;
V_190 = F_90 ( V_179 , 10 , & V_189 ) ;
if ( V_190 )
return V_190 ;
* V_188 = V_189 ;
return V_183 ;
}
static T_4 F_91 ( struct V_1 * V_1 , void * V_44 , char * V_179 )
{
return sprintf ( V_179 , L_29 , F_44 ( V_1 -> type ) -> V_40 ) ;
}
static T_4 F_92 ( struct V_1 * V_1 , void * V_44 , const char * V_179 , T_3 V_183 )
{
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
struct V_1 * V_144 = NULL ;
struct V_2 * V_191 , * V_192 ;
const struct V_93 * V_96 , * V_193 ;
int error ;
int V_194 = 0 ;
V_96 = F_46 ( V_179 , V_183 ) ;
if ( ! V_96 )
return - V_195 ;
if ( V_1 -> type == V_96 -> type )
return V_183 ;
V_192 = F_74 () ;
if ( ! V_192 )
return - V_163 ;
while ( ! F_93 ( & V_35 -> V_196 ) ) {
if ( ++ V_194 > 3 ) {
F_12 ( V_1 ,
L_30 ) ;
F_81 ( V_192 ) ;
return - V_197 ;
}
F_63 ( & V_147 ) ;
F_94 ( V_35 ) ;
F_60 ( & V_147 ) ;
if ( V_35 -> V_161 != & V_198 ) {
F_81 ( V_192 ) ;
return - V_166 ;
}
if ( V_1 -> type == V_96 -> type ) {
F_81 ( V_192 ) ;
return V_183 ;
}
}
if ( V_35 -> V_144 && V_35 -> V_79 . type == V_117 ) {
V_144 = F_16 ( V_35 -> V_144 ) ;
if ( V_144 -> V_114 )
V_144 -> V_114 ( V_144 ) ;
}
V_191 = V_1 -> V_3 ;
V_193 = F_44 ( V_1 -> type ) ;
if ( V_1 -> V_111 )
V_1 -> V_111 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_1 -> V_3 = V_192 ;
F_8 ( V_1 , V_150 ) ;
if ( F_71 ( V_1 , V_96 ) < 0 ) {
F_25 ( V_1 ) ;
F_71 ( V_1 , & V_95 [ 0 ] ) ;
}
F_55 ( V_1 ) ;
F_8 ( V_1 , V_142 ) ;
error = F_79 ( V_1 -> V_3 ) ;
if ( error ) {
if ( V_1 -> V_111 )
V_1 -> V_111 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
F_81 ( V_192 ) ;
V_1 -> V_3 = V_191 ;
F_8 ( V_1 , V_150 ) ;
F_71 ( V_1 , V_193 ) ;
F_55 ( V_1 ) ;
F_8 ( V_1 , V_142 ) ;
return error ;
}
F_70 ( V_191 ) ;
if ( V_144 && V_144 -> V_113 )
V_144 -> V_113 ( V_144 ) ;
return V_183 ;
}
static T_4 F_95 ( struct V_1 * V_1 , void * V_44 , const char * V_179 , T_3 V_183 )
{
unsigned int V_189 ;
int V_190 ;
V_190 = F_90 ( V_179 , 10 , & V_189 ) ;
if ( V_190 )
return V_190 ;
V_1 -> V_106 ( V_1 , V_189 ) ;
return V_183 ;
}
static T_4 F_96 ( struct V_1 * V_1 , void * V_44 , const char * V_179 , T_3 V_183 )
{
unsigned int V_189 ;
int V_190 ;
V_190 = F_90 ( V_179 , 10 , & V_189 ) ;
if ( V_190 )
return V_190 ;
V_1 -> V_107 ( V_1 , V_189 ) ;
return V_183 ;
}
static int F_97 ( const char * V_199 , const struct V_200 * V_201 )
{
const struct V_93 * V_96 ;
if ( ! V_199 )
return - V_195 ;
V_96 = F_46 ( V_199 , strlen ( V_199 ) ) ;
if ( ! V_96 || ! V_96 -> V_202 )
return - V_195 ;
* ( ( unsigned int * ) V_201 -> V_203 ) = V_96 -> type ;
return 0 ;
}
static int F_98 ( char * V_204 , const struct V_200 * V_201 )
{
int type = * ( ( unsigned int * ) V_201 -> V_203 ) ;
return sprintf ( V_204 , L_31 , F_44 ( type ) -> V_40 ) ;
}
static int T_5 F_99 ( void )
{
int V_190 ;
F_100 () ;
F_101 () ;
F_102 () ;
V_26 = F_103 ( L_32 ) ;
if ( ! V_26 ) {
F_104 ( L_33 ) ;
return - V_163 ;
}
V_190 = F_105 ( & V_198 ) ;
if ( V_190 )
F_106 ( V_26 ) ;
return V_190 ;
}
static void T_6 F_107 ( void )
{
F_108 ( & V_198 ) ;
F_106 ( V_26 ) ;
}
