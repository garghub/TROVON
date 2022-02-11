static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_4 , V_3 & F_3 ( 0 ) ) ;
F_2 ( V_2 , V_5 , V_3 & F_3 ( 2 ) ) ;
F_2 ( V_2 , V_6 , V_3 & F_3 ( 1 ) ) ;
}
T_2 F_4 ( struct V_7 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned char * V_8 = V_7 -> V_8 ;
if ( V_7 -> V_9 < V_7 -> V_10 )
return V_11 ;
switch ( V_7 -> type ) {
case V_12 :
F_5 ( V_2 , V_13 , - ( signed char ) V_8 [ 3 ] ) ;
break;
case V_14 :
switch ( V_8 [ 3 ] & 0xC0 ) {
case 0x80 :
F_5 ( V_2 , V_13 , ( int ) ( V_8 [ 3 ] & 32 ) - ( int ) ( V_8 [ 3 ] & 31 ) ) ;
break;
case 0x40 :
F_5 ( V_2 , V_15 , ( int ) ( V_8 [ 3 ] & 32 ) - ( int ) ( V_8 [ 3 ] & 31 ) ) ;
break;
case 0x00 :
case 0xC0 :
F_5 ( V_2 , V_13 , ( int ) ( V_8 [ 3 ] & 8 ) - ( int ) ( V_8 [ 3 ] & 7 ) ) ;
F_2 ( V_2 , V_16 , ( V_8 [ 3 ] >> 4 ) & 1 ) ;
F_2 ( V_2 , V_17 , ( V_8 [ 3 ] >> 5 ) & 1 ) ;
break;
}
break;
case V_18 :
F_5 ( V_2 , V_13 , - ( signed char ) V_8 [ 3 ] ) ;
F_2 ( V_2 , V_16 , ( V_8 [ 0 ] >> 6 ) & 1 ) ;
F_2 ( V_2 , V_17 , ( V_8 [ 0 ] >> 7 ) & 1 ) ;
break;
case V_19 :
F_2 ( V_2 , V_17 , ( V_8 [ 0 ] >> 3 ) & 1 ) ;
V_8 [ 1 ] |= ( V_8 [ 0 ] & 0x40 ) << 1 ;
break;
case V_20 :
F_2 ( V_2 , V_16 , ( V_8 [ 0 ] >> 3 ) & 1 ) ;
V_8 [ 0 ] |= 0x08 ;
break;
default:
break;
}
F_1 ( V_2 ,
V_8 [ 0 ] | V_7 -> V_21 ) ;
F_5 ( V_2 , V_22 , V_8 [ 1 ] ? ( int ) V_8 [ 1 ] - ( int ) ( ( V_8 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_5 ( V_2 , V_23 , V_8 [ 2 ] ? ( int ) ( ( V_8 [ 0 ] << 3 ) & 0x100 ) - ( int ) V_8 [ 2 ] : 0 ) ;
F_6 ( V_2 ) ;
return V_24 ;
}
void F_7 ( struct V_7 * V_7 , struct V_25 * V_26 ,
unsigned long V_27 )
{
F_8 ( V_28 , V_26 , V_27 ) ;
}
static inline void F_9 ( struct V_7 * V_7 , enum V_29 V_30 )
{
V_7 -> V_31 = V_30 ;
V_7 -> V_9 = V_7 -> V_32 = 0 ;
V_7 -> V_33 . V_34 = 0 ;
V_7 -> V_35 = V_36 ;
}
void F_10 ( struct V_7 * V_7 , enum V_29 V_30 )
{
F_11 ( V_7 -> V_33 . V_37 ) ;
F_9 ( V_7 , V_30 ) ;
F_12 ( V_7 -> V_33 . V_37 ) ;
}
static int F_13 ( struct V_7 * V_7 )
{
T_2 V_38 = V_7 -> V_39 ( V_7 ) ;
switch ( V_38 ) {
case V_40 :
if ( V_7 -> V_31 == V_41 ) {
F_14 ( V_7 ,
L_1 ,
V_7 -> V_42 , V_7 -> V_43 ,
V_7 -> V_9 ) ;
if ( ++ V_7 -> V_32 == V_7 -> V_44 ) {
F_9 ( V_7 , V_45 ) ;
F_15 ( V_7 ,
L_2 ) ;
F_16 ( V_7 -> V_33 . V_37 ) ;
return - 1 ;
}
}
V_7 -> V_9 = 0 ;
break;
case V_24 :
V_7 -> V_9 = 0 ;
if ( V_7 -> V_32 ) {
V_7 -> V_32 = 0 ;
F_15 ( V_7 ,
L_3 ,
V_7 -> V_42 , V_7 -> V_43 ) ;
}
break;
case V_11 :
break;
}
return 0 ;
}
static void F_17 ( struct V_7 * V_7 , T_1 V_46 )
{
switch ( V_7 -> V_47 ) {
case V_48 :
V_7 -> V_47 = V_46 ;
break;
case V_49 :
F_1 ( V_7 -> V_2 , V_46 ) ;
F_6 ( V_7 -> V_2 ) ;
V_7 -> V_21 = V_46 ;
V_7 -> V_47 = V_48 ;
break;
default:
F_14 ( V_7 ,
L_4 ,
V_7 -> V_47 ) ;
V_7 -> V_47 = V_48 ;
break;
}
}
static T_3 F_18 ( struct V_37 * V_37 ,
unsigned char V_46 , unsigned int V_34 )
{
struct V_7 * V_7 = F_19 ( V_37 ) ;
if ( V_7 -> V_31 == V_45 )
goto V_50;
if ( F_20 ( ( V_34 & V_51 ) ||
( ( V_34 & V_52 ) && ! V_7 -> V_53 ) ) ) {
if ( V_7 -> V_31 == V_41 )
F_14 ( V_7 ,
L_5 ,
V_34 & V_51 ? L_6 : L_7 ,
V_34 & V_52 ? L_8 : L_7 ) ;
F_21 ( & V_7 -> V_33 ) ;
goto V_50;
}
if ( V_34 & V_54 ) {
F_17 ( V_7 , V_46 ) ;
goto V_50;
}
if ( F_20 ( V_7 -> V_33 . V_34 & V_55 ) )
if ( F_22 ( & V_7 -> V_33 , V_46 ) )
goto V_50;
if ( F_20 ( V_7 -> V_33 . V_34 & V_56 ) )
if ( F_23 ( & V_7 -> V_33 , V_46 ) )
goto V_50;
if ( V_7 -> V_31 <= V_57 )
goto V_50;
if ( V_7 -> V_31 == V_41 &&
V_7 -> V_9 && F_24 ( V_36 , V_7 -> V_35 + V_58 / 2 ) ) {
F_25 ( V_7 , L_9 ,
V_7 -> V_42 , V_7 -> V_43 , V_7 -> V_9 ) ;
V_7 -> V_59 = V_7 -> V_8 [ 0 ] ;
F_9 ( V_7 , V_57 ) ;
F_7 ( V_7 , & V_7 -> V_60 , 0 ) ;
goto V_50;
}
V_7 -> V_8 [ V_7 -> V_9 ++ ] = V_46 ;
if ( F_20 ( V_7 -> V_8 [ 0 ] == V_61 && V_7 -> V_9 <= 2 ) ) {
if ( V_7 -> V_9 == 1 ) {
V_7 -> V_35 = V_36 ;
goto V_50;
}
if ( V_7 -> V_8 [ 1 ] == V_62 ||
( V_7 -> type == V_63 &&
V_7 -> V_8 [ 1 ] == V_61 ) ) {
F_9 ( V_7 , V_45 ) ;
F_16 ( V_37 ) ;
goto V_50;
}
V_7 -> V_9 = 1 ;
if ( F_13 ( V_7 ) )
goto V_50;
V_7 -> V_8 [ V_7 -> V_9 ++ ] = V_46 ;
}
if ( V_7 -> V_31 == V_41 &&
V_7 -> V_9 == 1 && V_7 -> V_64 &&
F_24 ( V_36 , V_7 -> V_35 + V_7 -> V_64 * V_58 ) ) {
V_7 -> V_59 = V_7 -> V_8 [ 0 ] ;
F_9 ( V_7 , V_57 ) ;
F_7 ( V_7 , & V_7 -> V_60 , 0 ) ;
goto V_50;
}
V_7 -> V_35 = V_36 ;
F_13 ( V_7 ) ;
V_50:
return V_65 ;
}
int F_26 ( struct V_7 * V_7 , unsigned char V_66 )
{
int V_67 ;
if ( F_27 ( & V_7 -> V_33 , NULL , V_68 ) )
return - 1 ;
for ( V_67 = 6 ; V_67 >= 0 ; V_67 -= 2 ) {
unsigned char V_69 = ( V_66 >> V_67 ) & 3 ;
if ( F_27 ( & V_7 -> V_33 , & V_69 , V_70 ) )
return - 1 ;
}
return 0 ;
}
int F_28 ( struct V_7 * V_7 )
{
unsigned char V_71 [ 2 ] ;
if ( F_27 ( & V_7 -> V_33 , V_71 , V_72 ) )
return - 1 ;
if ( V_71 [ 0 ] != V_61 && V_71 [ 1 ] != V_62 )
return - 1 ;
return 0 ;
}
void F_29 ( struct V_7 * V_7 , unsigned int V_73 )
{
static const unsigned char V_74 [] = { 0 , 1 , 2 , 2 , 3 } ;
unsigned char V_75 ;
if ( V_73 == 0 || V_73 > 200 )
V_73 = 200 ;
V_75 = V_74 [ V_73 / 50 ] ;
F_27 ( & V_7 -> V_33 , & V_75 , V_70 ) ;
V_7 -> V_73 = 25 << V_75 ;
}
static void F_30 ( struct V_7 * V_7 , unsigned int V_76 )
{
static const unsigned char V_77 [] = { 200 , 100 , 80 , 60 , 40 , 20 , 10 , 0 } ;
unsigned char V_78 ;
int V_67 = 0 ;
while ( V_77 [ V_67 ] > V_76 ) V_67 ++ ;
V_78 = V_77 [ V_67 ] ;
F_27 ( & V_7 -> V_33 , & V_78 , V_79 ) ;
V_7 -> V_76 = V_78 ;
}
static void F_31 ( struct V_7 * V_7 , enum V_80 V_81 )
{
F_27 ( & V_7 -> V_33 , NULL ,
V_81 == V_82 ? V_83 :
V_68 ) ;
}
static int F_32 ( struct V_7 * V_7 )
{
return F_27 ( & V_7 -> V_33 , V_7 -> V_8 ,
V_84 | ( V_7 -> V_10 << 8 ) ) ;
}
static bool F_33 ( const char * V_85 , const char * const V_86 [] )
{
int V_67 ;
for ( V_67 = 0 ; V_86 [ V_67 ] ; V_67 ++ )
if ( ! strcasecmp ( V_85 , V_86 [ V_67 ] ) )
return true ;
return false ;
}
bool F_34 ( struct V_7 * V_7 , const char * const V_86 [] )
{
struct V_37 * V_37 = V_7 -> V_33 . V_37 ;
char * V_75 , * V_87 , * V_88 ;
bool V_89 = false ;
if ( strncmp ( V_37 -> V_90 , L_10 , 5 ) )
return false ;
V_87 = F_35 ( & V_37 -> V_90 [ 5 ] ,
sizeof( V_37 -> V_90 ) - 5 ,
V_91 ) ;
if ( ! V_87 )
return false ;
V_88 = V_87 ;
while ( ( V_75 = F_36 ( & V_87 , L_11 ) ) != NULL ) {
if ( F_33 ( V_75 , V_86 ) ) {
V_89 = true ;
break;
}
}
F_37 ( V_88 ) ;
return V_89 ;
}
static int F_38 ( struct V_7 * V_7 , bool V_92 )
{
struct V_33 * V_33 = & V_7 -> V_33 ;
unsigned char V_71 [ 4 ] ;
V_71 [ 0 ] = 3 ;
F_27 ( V_33 , V_71 , V_70 ) ;
F_27 ( V_33 , NULL , V_68 ) ;
F_27 ( V_33 , NULL , V_68 ) ;
F_27 ( V_33 , NULL , V_68 ) ;
F_27 ( V_33 , V_71 , V_93 ) ;
if ( V_71 [ 0 ] != 0x00 || V_71 [ 1 ] != 0x33 || V_71 [ 2 ] != 0x55 )
return - 1 ;
if ( V_92 ) {
F_39 ( V_5 , V_7 -> V_2 -> V_94 ) ;
F_39 ( V_17 , V_7 -> V_2 -> V_94 ) ;
F_39 ( V_16 , V_7 -> V_2 -> V_94 ) ;
F_39 ( V_13 , V_7 -> V_2 -> V_95 ) ;
V_7 -> V_96 = L_12 ;
V_7 -> V_42 = L_13 ;
V_7 -> V_10 = 4 ;
}
return 0 ;
}
static int F_40 ( struct V_7 * V_7 , bool V_92 )
{
struct V_33 * V_33 = & V_7 -> V_33 ;
unsigned char V_71 [ 2 ] ;
V_71 [ 0 ] = 200 ;
F_27 ( V_33 , V_71 , V_79 ) ;
V_71 [ 0 ] = 100 ;
F_27 ( V_33 , V_71 , V_79 ) ;
V_71 [ 0 ] = 80 ;
F_27 ( V_33 , V_71 , V_79 ) ;
F_27 ( V_33 , V_71 , V_97 ) ;
if ( V_71 [ 0 ] != 3 )
return - 1 ;
if ( V_92 ) {
F_39 ( V_5 , V_7 -> V_2 -> V_94 ) ;
F_39 ( V_13 , V_7 -> V_2 -> V_95 ) ;
if ( ! V_7 -> V_96 )
V_7 -> V_96 = L_14 ;
if ( ! V_7 -> V_42 )
V_7 -> V_42 = L_15 ;
V_7 -> V_10 = 4 ;
}
return 0 ;
}
static int F_41 ( struct V_7 * V_7 , bool V_92 )
{
struct V_33 * V_33 = & V_7 -> V_33 ;
unsigned char V_71 [ 2 ] ;
F_40 ( V_7 , 0 ) ;
V_71 [ 0 ] = 200 ;
F_27 ( V_33 , V_71 , V_79 ) ;
V_71 [ 0 ] = 200 ;
F_27 ( V_33 , V_71 , V_79 ) ;
V_71 [ 0 ] = 80 ;
F_27 ( V_33 , V_71 , V_79 ) ;
F_27 ( V_33 , V_71 , V_97 ) ;
if ( V_71 [ 0 ] != 4 )
return - 1 ;
V_71 [ 0 ] = 200 ;
F_27 ( V_33 , V_71 , V_79 ) ;
V_71 [ 0 ] = 80 ;
F_27 ( V_33 , V_71 , V_79 ) ;
V_71 [ 0 ] = 40 ;
F_27 ( V_33 , V_71 , V_79 ) ;
if ( V_92 ) {
F_39 ( V_5 , V_7 -> V_2 -> V_94 ) ;
F_39 ( V_13 , V_7 -> V_2 -> V_95 ) ;
F_39 ( V_15 , V_7 -> V_2 -> V_95 ) ;
F_39 ( V_16 , V_7 -> V_2 -> V_94 ) ;
F_39 ( V_17 , V_7 -> V_2 -> V_94 ) ;
if ( ! V_7 -> V_96 )
V_7 -> V_96 = L_14 ;
if ( ! V_7 -> V_42 )
V_7 -> V_42 = L_16 ;
V_7 -> V_10 = 4 ;
}
return 0 ;
}
static int F_42 ( struct V_7 * V_7 , bool V_92 )
{
struct V_33 * V_33 = & V_7 -> V_33 ;
unsigned char V_71 [ 2 ] ;
static const unsigned char V_98 [] = { 20 , 60 , 40 , 20 , 20 , 60 , 40 , 20 , 20 } ;
int V_67 ;
V_71 [ 0 ] = 10 ;
F_27 ( V_33 , V_71 , V_79 ) ;
V_71 [ 0 ] = 0 ;
F_27 ( V_33 , V_71 , V_70 ) ;
for ( V_67 = 0 ; V_67 < F_43 ( V_98 ) ; V_67 ++ ) {
V_71 [ 0 ] = V_98 [ V_67 ] ;
F_27 ( V_33 , V_71 , V_79 ) ;
}
F_27 ( V_33 , V_71 , V_97 ) ;
if ( V_71 [ 0 ] != 2 )
return - 1 ;
if ( V_92 ) {
F_39 ( V_5 , V_7 -> V_2 -> V_94 ) ;
F_39 ( V_17 , V_7 -> V_2 -> V_94 ) ;
V_7 -> V_96 = L_17 ;
V_7 -> V_42 = L_18 ;
}
return 0 ;
}
static int F_44 ( struct V_7 * V_7 , bool V_92 )
{
if ( V_92 ) {
if ( ! V_7 -> V_96 )
V_7 -> V_96 = L_14 ;
if ( ! V_7 -> V_42 )
V_7 -> V_42 = L_13 ;
F_39 ( V_5 , V_7 -> V_2 -> V_94 ) ;
}
return 0 ;
}
static int F_45 ( struct V_7 * V_7 , bool V_92 )
{
if ( V_92 ) {
V_7 -> V_96 = L_19 ;
V_7 -> V_42 = L_20 ;
F_39 ( V_5 , V_7 -> V_2 -> V_94 ) ;
F_39 ( V_16 , V_7 -> V_2 -> V_94 ) ;
}
return 0 ;
}
static const struct V_99 * F_46 ( enum V_100 type )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < F_43 ( V_101 ) ; V_67 ++ )
if ( V_101 [ V_67 ] . type == type )
return & V_101 [ V_67 ] ;
return NULL ;
}
static const struct V_99 * F_47 ( enum V_100 type )
{
const struct V_99 * V_102 ;
V_102 = F_46 ( type ) ;
if ( V_102 )
return V_102 ;
F_48 ( 1 ) ;
return & V_101 [ 0 ] ;
}
static const struct V_99 * F_49 ( const char * V_42 , T_4 V_103 )
{
const struct V_99 * V_75 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < F_43 ( V_101 ) ; V_67 ++ ) {
V_75 = & V_101 [ V_67 ] ;
if ( ( strlen ( V_75 -> V_42 ) == V_103 && ! strncmp ( V_75 -> V_42 , V_42 , V_103 ) ) ||
( strlen ( V_75 -> V_104 ) == V_103 && ! strncmp ( V_75 -> V_104 , V_42 , V_103 ) ) )
return & V_101 [ V_67 ] ;
}
return NULL ;
}
static void F_50 ( struct V_7 * V_7 )
{
struct V_1 * V_1 = V_7 -> V_2 ;
memset ( V_1 -> V_105 , 0 , sizeof( V_1 -> V_105 ) ) ;
memset ( V_1 -> V_94 , 0 , sizeof( V_1 -> V_94 ) ) ;
memset ( V_1 -> V_95 , 0 , sizeof( V_1 -> V_95 ) ) ;
memset ( V_1 -> V_106 , 0 , sizeof( V_1 -> V_106 ) ) ;
memset ( V_1 -> V_107 , 0 , sizeof( V_1 -> V_107 ) ) ;
F_39 ( V_108 , V_1 -> V_105 ) ;
F_39 ( V_109 , V_1 -> V_105 ) ;
F_39 ( V_4 , V_1 -> V_94 ) ;
F_39 ( V_6 , V_1 -> V_94 ) ;
F_39 ( V_22 , V_1 -> V_95 ) ;
F_39 ( V_23 , V_1 -> V_95 ) ;
F_39 ( V_110 , V_1 -> V_111 ) ;
V_7 -> V_112 = F_30 ;
V_7 -> V_113 = F_29 ;
V_7 -> V_114 = F_31 ;
V_7 -> V_115 = F_32 ;
V_7 -> V_39 = F_4 ;
V_7 -> V_10 = 3 ;
V_7 -> V_116 = NULL ;
V_7 -> V_117 = NULL ;
V_7 -> V_118 = NULL ;
V_7 -> V_119 = NULL ;
V_7 -> V_120 = NULL ;
}
static bool F_51 ( struct V_7 * V_7 ,
enum V_100 type ,
unsigned int * V_121 ,
bool V_92 , bool V_122 )
{
const struct V_99 * V_102 ;
V_102 = F_46 ( type ) ;
if ( ! V_102 )
return false ;
if ( V_7 -> V_33 . V_37 -> V_85 . type == V_123 &&
! V_102 -> V_124 ) {
return false ;
}
if ( V_92 )
F_50 ( V_7 ) ;
if ( V_102 -> V_125 ( V_7 , V_92 ) != 0 )
return false ;
if ( V_92 && V_102 -> V_126 && V_122 ) {
if ( V_102 -> V_126 ( V_7 ) != 0 ) {
if ( * V_121 > V_14 )
* V_121 = V_14 ;
return false ;
}
}
return true ;
}
static int F_52 ( struct V_7 * V_7 ,
unsigned int V_121 , bool V_92 )
{
bool V_127 = false ;
if ( F_51 ( V_7 , V_128 ,
& V_121 , V_92 , false ) ) {
if ( V_121 > V_14 &&
F_53 ( V_129 ) &&
( ! V_92 || F_54 ( V_7 ) == 0 ) ) {
return V_128 ;
}
V_130 = V_121 = V_131 ;
}
if ( F_51 ( V_7 , V_132 , & V_121 ,
V_92 , V_121 > V_14 ) )
return V_132 ;
if ( F_51 ( V_7 , V_133 , & V_121 ,
V_92 , V_121 > V_14 ) )
return V_133 ;
if ( V_121 > V_14 &&
F_51 ( V_7 , V_19 , & V_121 ,
V_92 , true ) ) {
return V_19 ;
}
if ( V_121 > V_131 &&
F_51 ( V_7 , V_134 , & V_121 ,
V_92 , false ) ) {
V_127 = true ;
if ( V_121 > V_14 ) {
if ( F_53 ( V_135 ) &&
( ! V_92 || F_55 ( V_7 ) == 0 ) ) {
return V_134 ;
}
V_121 = V_14 ;
}
F_56 ( V_7 ) ;
}
if ( V_121 > V_14 &&
F_51 ( V_7 , V_136 , & V_121 ,
V_92 , true ) ) {
return V_136 ;
}
if ( V_121 > V_14 ) {
F_27 ( & V_7 -> V_33 , NULL , V_137 ) ;
if ( F_51 ( V_7 , V_138 ,
& V_121 , V_92 , true ) )
return V_138 ;
}
if ( V_121 > V_14 &&
F_51 ( V_7 , V_63 , & V_121 ,
V_92 , true ) ) {
return V_63 ;
}
if ( V_121 > V_14 &&
F_51 ( V_7 , V_139 ,
& V_121 , V_92 , true ) ) {
return V_139 ;
}
if ( V_121 > V_14 ) {
if ( F_51 ( V_7 , V_18 ,
& V_121 , V_92 , true ) )
return V_18 ;
if ( F_51 ( V_7 , V_140 ,
& V_121 , V_92 , true ) )
return V_140 ;
if ( F_51 ( V_7 , V_141 ,
& V_121 , V_92 , true ) )
return V_141 ;
if ( F_51 ( V_7 , V_142 ,
& V_121 , V_92 , true ) )
return V_142 ;
}
if ( V_121 > V_14 &&
F_51 ( V_7 , V_143 ,
& V_121 , V_92 , true ) ) {
return V_143 ;
}
F_27 ( & V_7 -> V_33 , NULL , V_137 ) ;
F_28 ( V_7 ) ;
if ( V_121 >= V_14 &&
F_51 ( V_7 , V_14 ,
& V_121 , V_92 , true ) ) {
return V_14 ;
}
if ( V_121 >= V_12 &&
F_51 ( V_7 , V_12 ,
& V_121 , V_92 , true ) ) {
return V_12 ;
}
F_51 ( V_7 , V_131 ,
& V_121 , V_92 , true ) ;
if ( V_127 ) {
F_28 ( V_7 ) ;
}
return V_131 ;
}
static int F_57 ( struct V_7 * V_7 )
{
struct V_33 * V_33 = & V_7 -> V_33 ;
unsigned char V_71 [ 2 ] ;
V_71 [ 0 ] = 0xa5 ;
if ( F_27 ( V_33 , V_71 , V_97 ) )
return - 1 ;
if ( V_71 [ 0 ] != 0x00 && V_71 [ 0 ] != 0x03 &&
V_71 [ 0 ] != 0x04 && V_71 [ 0 ] != 0xff )
return - 1 ;
if ( F_27 ( V_33 , NULL , V_137 ) )
F_14 ( V_7 , L_21 ,
V_33 -> V_37 -> V_43 ) ;
return 0 ;
}
static void F_58 ( struct V_7 * V_7 )
{
if ( V_130 != V_131 ) {
V_7 -> V_112 ( V_7 , V_7 -> V_76 ) ;
V_7 -> V_113 ( V_7 , V_7 -> V_73 ) ;
V_7 -> V_114 ( V_7 , V_144 ) ;
}
}
int F_59 ( struct V_7 * V_7 )
{
if ( F_27 ( & V_7 -> V_33 , NULL , V_145 ) ) {
F_14 ( V_7 , L_22 ,
V_7 -> V_33 . V_37 -> V_43 ) ;
return - 1 ;
}
F_10 ( V_7 , V_41 ) ;
return 0 ;
}
int F_60 ( struct V_7 * V_7 )
{
if ( F_27 ( & V_7 -> V_33 , NULL , V_146 ) ) {
F_14 ( V_7 , L_23 ,
V_7 -> V_33 . V_37 -> V_43 ) ;
return - 1 ;
}
F_10 ( V_7 , V_147 ) ;
return 0 ;
}
static void F_61 ( struct V_148 * V_26 )
{
struct V_7 * V_149 = NULL , * V_7 =
F_62 ( V_26 , struct V_7 , V_60 . V_26 ) ;
struct V_37 * V_37 = V_7 -> V_33 . V_37 ;
T_2 V_38 = V_11 ;
bool V_150 = false , V_151 = false ;
int V_67 ;
F_63 ( & V_152 ) ;
if ( V_7 -> V_31 != V_57 )
goto V_50;
if ( V_37 -> V_149 && V_37 -> V_85 . type == V_123 ) {
V_149 = F_19 ( V_37 -> V_149 ) ;
F_60 ( V_149 ) ;
}
V_7 -> V_153 ++ ;
if ( F_64 ( & V_7 -> V_33 , V_146 , 20 ) ) {
if ( V_7 -> V_153 < 3 || V_7 -> V_154 )
V_150 = true ;
} else
V_7 -> V_154 = true ;
if ( ! V_150 ) {
if ( V_7 -> V_115 ( V_7 ) )
V_150 = true ;
else {
F_10 ( V_7 , V_147 ) ;
for ( V_67 = 0 ; V_67 < V_7 -> V_10 ; V_67 ++ ) {
V_7 -> V_9 ++ ;
V_38 = V_7 -> V_39 ( V_7 ) ;
if ( V_38 != V_11 )
break;
}
if ( V_38 != V_24 )
V_150 = true ;
F_10 ( V_7 , V_57 ) ;
}
}
for ( V_67 = 0 ; V_67 < 5 ; V_67 ++ ) {
if ( ! F_27 ( & V_7 -> V_33 , NULL , V_145 ) ) {
V_151 = true ;
break;
}
F_65 ( 200 ) ;
}
if ( ! V_151 ) {
F_14 ( V_7 , L_24 ,
V_7 -> V_33 . V_37 -> V_43 ) ;
V_150 = true ;
}
if ( V_150 ) {
F_10 ( V_7 , V_45 ) ;
F_25 ( V_7 ,
L_25 ) ;
F_16 ( V_37 ) ;
} else
F_10 ( V_7 , V_41 ) ;
if ( V_149 )
F_59 ( V_149 ) ;
V_50:
F_66 ( & V_152 ) ;
}
static void F_67 ( struct V_37 * V_37 )
{
struct V_7 * V_7 = F_19 ( V_37 ) ;
struct V_7 * V_149 = NULL ;
F_63 ( & V_152 ) ;
if ( V_37 -> V_149 && V_37 -> V_85 . type == V_123 ) {
V_149 = F_19 ( V_37 -> V_149 ) ;
F_60 ( V_149 ) ;
}
F_10 ( V_7 , V_155 ) ;
if ( F_27 ( & V_7 -> V_33 , NULL , V_146 ) )
F_14 ( V_7 , L_26 ,
V_7 -> V_33 . V_37 -> V_43 ) ;
if ( V_7 -> V_118 )
V_7 -> V_118 ( V_7 ) ;
F_27 ( & V_7 -> V_33 , NULL , V_137 ) ;
F_27 ( & V_7 -> V_33 , NULL , V_145 ) ;
if ( V_149 ) {
if ( V_149 -> V_120 )
V_149 -> V_120 ( V_149 ) ;
F_59 ( V_149 ) ;
}
F_66 ( & V_152 ) ;
}
static void F_68 ( struct V_37 * V_37 )
{
struct V_7 * V_7 , * V_149 = NULL ;
V_7 = F_19 ( V_37 ) ;
F_69 ( & V_37 -> V_2 . V_156 , & V_157 ) ;
F_63 ( & V_152 ) ;
F_10 ( V_7 , V_147 ) ;
F_66 ( & V_152 ) ;
F_70 ( V_28 ) ;
F_63 ( & V_152 ) ;
if ( V_37 -> V_149 && V_37 -> V_85 . type == V_123 ) {
V_149 = F_19 ( V_37 -> V_149 ) ;
F_60 ( V_149 ) ;
}
if ( V_7 -> V_117 )
V_7 -> V_117 ( V_7 ) ;
if ( V_149 && V_149 -> V_120 )
V_149 -> V_120 ( V_149 ) ;
F_10 ( V_7 , V_45 ) ;
F_71 ( V_37 ) ;
F_72 ( V_37 , NULL ) ;
F_73 ( V_7 -> V_2 ) ;
F_37 ( V_7 ) ;
if ( V_149 )
F_59 ( V_149 ) ;
F_66 ( & V_152 ) ;
}
static int F_74 ( struct V_7 * V_7 ,
const struct V_99 * V_102 )
{
const struct V_99 * V_158 ;
struct V_1 * V_1 = V_7 -> V_2 ;
V_1 -> V_2 . V_149 = & V_7 -> V_33 . V_37 -> V_2 ;
if ( V_102 && ( V_102 -> V_125 || V_102 -> V_126 ) ) {
F_50 ( V_7 ) ;
if ( V_102 -> V_125 && V_102 -> V_125 ( V_7 , true ) < 0 )
return - 1 ;
if ( V_102 -> V_126 && V_102 -> V_126 ( V_7 ) < 0 )
return - 1 ;
V_7 -> type = V_102 -> type ;
V_158 = V_102 ;
} else {
V_7 -> type = F_52 ( V_7 ,
V_130 , true ) ;
V_158 = F_47 ( V_7 -> type ) ;
}
V_7 -> V_53 = V_158 -> V_53 ;
if ( V_7 -> V_10 == 3 )
V_7 -> V_64 = 0 ;
if ( V_7 -> V_64 && V_7 -> V_115 ( V_7 ) )
V_7 -> V_64 = 0 ;
snprintf ( V_7 -> V_159 , sizeof( V_7 -> V_159 ) , L_27 ,
V_158 -> V_42 , V_7 -> V_96 , V_7 -> V_42 ) ;
V_1 -> V_42 = V_7 -> V_159 ;
V_1 -> V_43 = V_7 -> V_43 ;
V_1 -> V_85 . V_160 = V_161 ;
V_1 -> V_85 . V_96 = 0x0002 ;
V_1 -> V_85 . V_162 = V_7 -> type ;
V_1 -> V_85 . V_163 = V_7 -> V_164 ;
return 0 ;
}
static int F_75 ( struct V_37 * V_37 , struct V_165 * V_166 )
{
struct V_7 * V_7 , * V_149 = NULL ;
struct V_1 * V_1 ;
int V_167 = 0 , error = - V_168 ;
F_63 ( & V_152 ) ;
if ( V_37 -> V_149 && V_37 -> V_85 . type == V_123 ) {
V_149 = F_19 ( V_37 -> V_149 ) ;
F_60 ( V_149 ) ;
}
V_7 = F_76 ( sizeof( struct V_7 ) , V_91 ) ;
V_1 = F_77 () ;
if ( ! V_7 || ! V_1 )
goto V_169;
F_78 ( & V_7 -> V_33 , V_37 ) ;
F_79 ( & V_7 -> V_60 , F_61 ) ;
V_7 -> V_2 = V_1 ;
snprintf ( V_7 -> V_43 , sizeof( V_7 -> V_43 ) , L_28 , V_37 -> V_43 ) ;
F_10 ( V_7 , V_155 ) ;
F_72 ( V_37 , V_7 ) ;
error = F_80 ( V_37 , V_166 ) ;
if ( error )
goto V_170;
if ( V_37 -> V_85 . type == V_123 )
F_81 ( 10000 , 15000 ) ;
if ( F_57 ( V_7 ) < 0 ) {
error = - V_171 ;
goto V_172;
}
V_7 -> V_76 = V_173 ;
V_7 -> V_73 = V_174 ;
V_7 -> V_44 = V_175 ;
V_7 -> V_64 = V_149 ? 0 : V_176 ;
V_7 -> V_177 = V_178 ;
F_74 ( V_7 , NULL ) ;
F_10 ( V_7 , V_147 ) ;
F_58 ( V_7 ) ;
error = F_82 ( V_7 -> V_2 ) ;
if ( error )
goto V_179;
if ( V_149 && V_149 -> V_119 )
V_149 -> V_119 ( V_149 ) ;
error = F_83 ( & V_37 -> V_2 . V_156 , & V_157 ) ;
if ( error )
goto V_180;
F_59 ( V_7 ) ;
V_50:
if ( V_149 )
F_59 ( V_149 ) ;
F_66 ( & V_152 ) ;
return V_167 ;
V_180:
if ( V_149 && V_149 -> V_120 )
V_149 -> V_120 ( V_149 ) ;
F_73 ( V_7 -> V_2 ) ;
V_1 = NULL ;
V_179:
if ( V_7 -> V_117 )
V_7 -> V_117 ( V_7 ) ;
F_10 ( V_7 , V_45 ) ;
V_172:
F_71 ( V_37 ) ;
V_170:
F_72 ( V_37 , NULL ) ;
V_169:
F_84 ( V_1 ) ;
F_37 ( V_7 ) ;
V_167 = error ;
goto V_50;
}
static int F_85 ( struct V_37 * V_37 )
{
struct V_7 * V_7 = F_19 ( V_37 ) ;
struct V_7 * V_149 = NULL ;
unsigned char type ;
int V_38 = - 1 ;
F_63 ( & V_152 ) ;
if ( V_37 -> V_149 && V_37 -> V_85 . type == V_123 ) {
V_149 = F_19 ( V_37 -> V_149 ) ;
F_60 ( V_149 ) ;
}
F_10 ( V_7 , V_155 ) ;
if ( V_7 -> V_116 ) {
if ( V_7 -> V_116 ( V_7 ) )
goto V_50;
} else {
F_28 ( V_7 ) ;
if ( F_57 ( V_7 ) < 0 )
goto V_50;
type = F_52 ( V_7 , V_130 , false ) ;
if ( V_7 -> type != type )
goto V_50;
}
F_10 ( V_7 , V_147 ) ;
F_58 ( V_7 ) ;
if ( V_149 && V_149 -> V_119 )
V_149 -> V_119 ( V_149 ) ;
F_59 ( V_7 ) ;
V_38 = 0 ;
V_50:
if ( V_149 )
F_59 ( V_149 ) ;
F_66 ( & V_152 ) ;
return V_38 ;
}
T_5 F_86 ( struct V_181 * V_2 , struct V_182 * V_183 ,
char * V_184 )
{
struct V_37 * V_37 = F_87 ( V_2 ) ;
struct V_185 * V_186 = F_88 ( V_183 ) ;
struct V_7 * V_7 ;
V_7 = F_19 ( V_37 ) ;
return V_186 -> V_187 ( V_7 , V_186 -> V_46 , V_184 ) ;
}
T_5 F_89 ( struct V_181 * V_2 , struct V_182 * V_183 ,
const char * V_184 , T_4 V_188 )
{
struct V_37 * V_37 = F_87 ( V_2 ) ;
struct V_185 * V_186 = F_88 ( V_183 ) ;
struct V_7 * V_7 , * V_149 = NULL ;
int V_167 ;
V_167 = F_90 ( & V_152 ) ;
if ( V_167 )
goto V_50;
V_7 = F_19 ( V_37 ) ;
if ( V_186 -> V_189 ) {
if ( V_7 -> V_31 == V_45 ) {
V_167 = - V_171 ;
goto V_190;
}
if ( V_37 -> V_149 && V_37 -> V_85 . type == V_123 ) {
V_149 = F_19 ( V_37 -> V_149 ) ;
F_60 ( V_149 ) ;
}
F_60 ( V_7 ) ;
}
V_167 = V_186 -> V_191 ( V_7 , V_186 -> V_46 , V_184 , V_188 ) ;
if ( V_186 -> V_189 ) {
if ( V_167 != - V_171 )
F_59 ( V_7 ) ;
if ( V_149 )
F_59 ( V_149 ) ;
}
V_190:
F_66 ( & V_152 ) ;
V_50:
return V_167 ;
}
static T_5 F_91 ( struct V_7 * V_7 , void * V_192 , char * V_184 )
{
unsigned int * V_193 = ( unsigned int * ) ( ( char * ) V_7 + ( T_4 ) V_192 ) ;
return sprintf ( V_184 , L_29 , * V_193 ) ;
}
static T_5 F_92 ( struct V_7 * V_7 , void * V_192 , const char * V_184 , T_4 V_188 )
{
unsigned int * V_193 = ( unsigned int * ) ( ( char * ) V_7 + ( T_4 ) V_192 ) ;
unsigned int V_194 ;
int V_195 ;
V_195 = F_93 ( V_184 , 10 , & V_194 ) ;
if ( V_195 )
return V_195 ;
* V_193 = V_194 ;
return V_188 ;
}
static T_5 F_94 ( struct V_7 * V_7 , void * V_46 , char * V_184 )
{
return sprintf ( V_184 , L_30 , F_47 ( V_7 -> type ) -> V_42 ) ;
}
static T_5 F_95 ( struct V_7 * V_7 , void * V_46 , const char * V_184 , T_4 V_188 )
{
struct V_37 * V_37 = V_7 -> V_33 . V_37 ;
struct V_7 * V_149 = NULL ;
struct V_1 * V_196 , * V_197 ;
const struct V_99 * V_102 , * V_198 ;
int error ;
int V_199 = 0 ;
V_102 = F_49 ( V_184 , V_188 ) ;
if ( ! V_102 )
return - V_200 ;
if ( V_7 -> type == V_102 -> type )
return V_188 ;
V_197 = F_77 () ;
if ( ! V_197 )
return - V_168 ;
while ( ! F_96 ( & V_37 -> V_201 ) ) {
if ( ++ V_199 > 3 ) {
F_14 ( V_7 ,
L_31 ) ;
F_84 ( V_197 ) ;
return - V_202 ;
}
F_66 ( & V_152 ) ;
F_97 ( V_37 ) ;
F_63 ( & V_152 ) ;
if ( V_37 -> V_166 != & V_203 ) {
F_84 ( V_197 ) ;
return - V_171 ;
}
if ( V_7 -> type == V_102 -> type ) {
F_84 ( V_197 ) ;
return V_188 ;
}
}
if ( V_37 -> V_149 && V_37 -> V_85 . type == V_123 ) {
V_149 = F_19 ( V_37 -> V_149 ) ;
if ( V_149 -> V_120 )
V_149 -> V_120 ( V_149 ) ;
}
V_196 = V_7 -> V_2 ;
V_198 = F_47 ( V_7 -> type ) ;
if ( V_7 -> V_117 )
V_7 -> V_117 ( V_7 ) ;
F_10 ( V_7 , V_45 ) ;
V_7 -> V_2 = V_197 ;
F_10 ( V_7 , V_155 ) ;
if ( F_74 ( V_7 , V_102 ) < 0 ) {
F_28 ( V_7 ) ;
F_74 ( V_7 , & V_101 [ 0 ] ) ;
}
F_58 ( V_7 ) ;
F_10 ( V_7 , V_147 ) ;
error = F_82 ( V_7 -> V_2 ) ;
if ( error ) {
if ( V_7 -> V_117 )
V_7 -> V_117 ( V_7 ) ;
F_10 ( V_7 , V_45 ) ;
F_84 ( V_197 ) ;
V_7 -> V_2 = V_196 ;
F_10 ( V_7 , V_155 ) ;
F_74 ( V_7 , V_198 ) ;
F_58 ( V_7 ) ;
F_10 ( V_7 , V_147 ) ;
return error ;
}
F_73 ( V_196 ) ;
if ( V_149 && V_149 -> V_119 )
V_149 -> V_119 ( V_149 ) ;
return V_188 ;
}
static T_5 F_98 ( struct V_7 * V_7 , void * V_46 , const char * V_184 , T_4 V_188 )
{
unsigned int V_194 ;
int V_195 ;
V_195 = F_93 ( V_184 , 10 , & V_194 ) ;
if ( V_195 )
return V_195 ;
V_7 -> V_112 ( V_7 , V_194 ) ;
return V_188 ;
}
static T_5 F_99 ( struct V_7 * V_7 , void * V_46 , const char * V_184 , T_4 V_188 )
{
unsigned int V_194 ;
int V_195 ;
V_195 = F_93 ( V_184 , 10 , & V_194 ) ;
if ( V_195 )
return V_195 ;
V_7 -> V_113 ( V_7 , V_194 ) ;
return V_188 ;
}
static int F_100 ( const char * V_204 , const struct V_205 * V_206 )
{
const struct V_99 * V_102 ;
if ( ! V_204 )
return - V_200 ;
V_102 = F_49 ( V_204 , strlen ( V_204 ) ) ;
if ( ! V_102 || ! V_102 -> V_207 )
return - V_200 ;
* ( ( unsigned int * ) V_206 -> V_208 ) = V_102 -> type ;
return 0 ;
}
static int F_101 ( char * V_209 , const struct V_205 * V_206 )
{
int type = * ( ( unsigned int * ) V_206 -> V_208 ) ;
return sprintf ( V_209 , L_32 , F_47 ( type ) -> V_42 ) ;
}
static int T_6 F_102 ( void )
{
int V_195 ;
F_103 () ;
F_104 () ;
F_105 () ;
V_28 = F_106 ( L_33 , 0 ) ;
if ( ! V_28 ) {
F_107 ( L_34 ) ;
return - V_168 ;
}
V_195 = F_108 ( & V_203 ) ;
if ( V_195 )
F_109 ( V_28 ) ;
return V_195 ;
}
static void T_7 F_110 ( void )
{
F_111 ( & V_203 ) ;
F_109 ( V_28 ) ;
}
