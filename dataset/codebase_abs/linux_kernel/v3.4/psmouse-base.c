T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned char * V_4 = V_1 -> V_4 ;
if ( V_1 -> V_5 < V_1 -> V_6 )
return V_7 ;
if ( V_1 -> type == V_8 || V_1 -> type == V_9 )
F_2 ( V_3 , V_10 , - ( signed char ) V_4 [ 3 ] ) ;
if ( V_1 -> type == V_11 ) {
switch ( V_4 [ 3 ] & 0xC0 ) {
case 0x80 :
F_2 ( V_3 , V_10 , ( int ) ( V_4 [ 3 ] & 32 ) - ( int ) ( V_4 [ 3 ] & 31 ) ) ;
break;
case 0x40 :
F_2 ( V_3 , V_12 , ( int ) ( V_4 [ 3 ] & 32 ) - ( int ) ( V_4 [ 3 ] & 31 ) ) ;
break;
case 0x00 :
case 0xC0 :
F_2 ( V_3 , V_10 , ( int ) ( V_4 [ 3 ] & 8 ) - ( int ) ( V_4 [ 3 ] & 7 ) ) ;
F_3 ( V_3 , V_13 , ( V_4 [ 3 ] >> 4 ) & 1 ) ;
F_3 ( V_3 , V_14 , ( V_4 [ 3 ] >> 5 ) & 1 ) ;
break;
}
}
if ( V_1 -> type == V_9 ) {
F_3 ( V_3 , V_13 , ( V_4 [ 0 ] >> 6 ) & 1 ) ;
F_3 ( V_3 , V_14 , ( V_4 [ 0 ] >> 7 ) & 1 ) ;
}
if ( V_1 -> type == V_15 ) {
F_3 ( V_3 , V_14 , ( V_4 [ 0 ] >> 3 ) & 1 ) ;
V_4 [ 1 ] |= ( V_4 [ 0 ] & 0x40 ) << 1 ;
}
if ( V_1 -> type == V_16 ) {
F_3 ( V_3 , V_13 , ( V_4 [ 0 ] >> 3 ) & 1 ) ;
V_4 [ 0 ] |= 0x08 ;
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
static int F_28 ( struct V_1 * V_1 )
{
return F_24 ( & V_1 -> V_31 , V_1 -> V_4 ,
V_74 | ( V_1 -> V_6 << 8 ) ) ;
}
static int F_29 ( struct V_1 * V_1 , bool V_75 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 4 ] ;
V_65 [ 0 ] = 3 ;
F_24 ( V_31 , V_65 , V_64 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , NULL , V_62 ) ;
F_24 ( V_31 , V_65 , V_76 ) ;
if ( V_65 [ 0 ] != 0x00 || V_65 [ 1 ] != 0x33 || V_65 [ 2 ] != 0x55 )
return - 1 ;
if ( V_75 ) {
F_30 ( V_18 , V_1 -> V_3 -> V_77 ) ;
F_30 ( V_14 , V_1 -> V_3 -> V_77 ) ;
F_30 ( V_13 , V_1 -> V_3 -> V_77 ) ;
F_30 ( V_10 , V_1 -> V_3 -> V_78 ) ;
V_1 -> V_79 = L_9 ;
V_1 -> V_40 = L_10 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , bool V_75 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 100 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
F_24 ( V_31 , V_65 , V_80 ) ;
if ( V_65 [ 0 ] != 3 )
return - 1 ;
if ( V_75 ) {
F_30 ( V_18 , V_1 -> V_3 -> V_77 ) ;
F_30 ( V_10 , V_1 -> V_3 -> V_78 ) ;
if ( ! V_1 -> V_79 )
V_1 -> V_79 = L_11 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_12 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , bool V_75 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
F_31 ( V_1 , 0 ) ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
F_24 ( V_31 , V_65 , V_80 ) ;
if ( V_65 [ 0 ] != 4 )
return - 1 ;
V_65 [ 0 ] = 200 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 80 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 40 ;
F_24 ( V_31 , V_65 , V_73 ) ;
if ( V_75 ) {
F_30 ( V_18 , V_1 -> V_3 -> V_77 ) ;
F_30 ( V_10 , V_1 -> V_3 -> V_78 ) ;
F_30 ( V_12 , V_1 -> V_3 -> V_78 ) ;
F_30 ( V_13 , V_1 -> V_3 -> V_77 ) ;
F_30 ( V_14 , V_1 -> V_3 -> V_77 ) ;
if ( ! V_1 -> V_79 )
V_1 -> V_79 = L_11 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_13 ;
V_1 -> V_6 = 4 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , bool V_75 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
static const unsigned char V_81 [] = { 20 , 60 , 40 , 20 , 20 , 60 , 40 , 20 , 20 } ;
int V_61 ;
V_65 [ 0 ] = 10 ;
F_24 ( V_31 , V_65 , V_73 ) ;
V_65 [ 0 ] = 0 ;
F_24 ( V_31 , V_65 , V_64 ) ;
for ( V_61 = 0 ; V_61 < F_34 ( V_81 ) ; V_61 ++ ) {
V_65 [ 0 ] = V_81 [ V_61 ] ;
F_24 ( V_31 , V_65 , V_73 ) ;
}
F_24 ( V_31 , V_65 , V_80 ) ;
if ( V_65 [ 0 ] != 2 )
return - 1 ;
if ( V_75 ) {
F_30 ( V_18 , V_1 -> V_3 -> V_77 ) ;
F_30 ( V_14 , V_1 -> V_3 -> V_77 ) ;
V_1 -> V_79 = L_14 ;
V_1 -> V_40 = L_15 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , bool V_75 )
{
if ( V_75 ) {
if ( ! V_1 -> V_79 )
V_1 -> V_79 = L_11 ;
if ( ! V_1 -> V_40 )
V_1 -> V_40 = L_10 ;
F_30 ( V_18 , V_1 -> V_3 -> V_77 ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_1 , bool V_75 )
{
if ( V_75 ) {
V_1 -> V_79 = L_16 ;
V_1 -> V_40 = L_17 ;
F_30 ( V_18 , V_1 -> V_3 -> V_77 ) ;
F_30 ( V_13 , V_1 -> V_3 -> V_77 ) ;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
memset ( V_2 -> V_82 , 0 , sizeof( V_2 -> V_82 ) ) ;
memset ( V_2 -> V_77 , 0 , sizeof( V_2 -> V_77 ) ) ;
memset ( V_2 -> V_78 , 0 , sizeof( V_2 -> V_78 ) ) ;
memset ( V_2 -> V_83 , 0 , sizeof( V_2 -> V_83 ) ) ;
memset ( V_2 -> V_84 , 0 , sizeof( V_2 -> V_84 ) ) ;
F_30 ( V_85 , V_2 -> V_82 ) ;
F_30 ( V_86 , V_2 -> V_82 ) ;
F_30 ( V_17 , V_2 -> V_77 ) ;
F_30 ( V_19 , V_2 -> V_77 ) ;
F_30 ( V_20 , V_2 -> V_78 ) ;
F_30 ( V_21 , V_2 -> V_78 ) ;
V_1 -> V_87 = F_27 ;
V_1 -> V_88 = F_26 ;
V_1 -> V_89 = F_28 ;
V_1 -> V_37 = F_1 ;
V_1 -> V_6 = 3 ;
V_1 -> V_90 = NULL ;
V_1 -> V_91 = NULL ;
V_1 -> V_92 = NULL ;
V_1 -> V_93 = NULL ;
V_1 -> V_94 = NULL ;
}
static int F_38 ( int (* F_39)( struct V_1 * V_1 ,
bool V_75 ) ,
struct V_1 * V_1 , bool V_75 )
{
if ( V_75 )
F_37 ( V_1 ) ;
return F_39 ( V_1 , V_75 ) ;
}
static int F_40 ( struct V_1 * V_1 ,
unsigned int V_95 , bool V_75 )
{
bool V_96 = false ;
if ( F_38 ( V_97 , V_1 , V_75 ) == 0 ) {
if ( V_95 > V_11 ) {
if ( ! V_75 || F_41 ( V_1 ) == 0 )
return V_98 ;
}
}
if ( V_95 > V_11 &&
F_38 ( F_33 , V_1 , V_75 ) == 0 ) {
return V_15 ;
}
if ( V_95 > V_99 &&
F_38 ( V_100 , V_1 , V_75 ) == 0 ) {
V_96 = true ;
if ( V_95 > V_11 ) {
if ( F_42 () &&
( ! V_75 || F_43 ( V_1 ) == 0 ) ) {
return V_101 ;
}
V_95 = V_11 ;
}
F_44 ( V_1 ) ;
}
if ( V_95 > V_11 ) {
F_24 ( & V_1 -> V_31 , NULL , V_102 ) ;
if ( F_38 ( V_103 ,
V_1 , V_75 ) == 0 ) {
if ( ! V_75 || F_45 ( V_1 ) == 0 )
return V_104 ;
V_95 = V_11 ;
}
}
if ( V_95 > V_11 &&
F_38 ( V_105 , V_1 , V_75 ) == 0 ) {
if ( ! V_75 || F_46 ( V_1 ) == 0 )
return V_57 ;
V_95 = V_11 ;
}
if ( V_95 > V_11 &&
F_38 ( V_106 , V_1 , V_75 ) == 0 ) {
if ( ! V_75 || F_47 ( V_1 ) == 0 )
return V_107 ;
V_95 = V_11 ;
}
if ( V_95 > V_11 ) {
if ( F_38 ( F_29 ,
V_1 , V_75 ) == 0 )
return V_9 ;
if ( F_38 ( V_108 ,
V_1 , V_75 ) == 0 )
return V_109 ;
if ( F_38 ( V_110 ,
V_1 , V_75 ) == 0 )
return V_111 ;
if ( F_38 ( V_112 ,
V_1 , V_75 ) == 0 )
return V_113 ;
}
if ( V_95 > V_11 ) {
if ( F_38 ( V_114 ,
V_1 , V_75 ) == 0 ) {
if ( ! V_75 || F_48 ( V_1 ) == 0 )
return V_115 ;
V_95 = V_11 ;
}
}
F_24 ( & V_1 -> V_31 , NULL , V_102 ) ;
F_25 ( V_1 ) ;
if ( V_95 >= V_11 &&
F_38 ( F_32 ,
V_1 , V_75 ) == 0 ) {
return V_11 ;
}
if ( V_95 >= V_8 &&
F_38 ( F_31 ,
V_1 , V_75 ) == 0 ) {
return V_8 ;
}
F_38 ( F_35 , V_1 , V_75 ) ;
if ( V_96 ) {
F_25 ( V_1 ) ;
}
return V_99 ;
}
static const struct V_116 * F_49 ( enum V_117 type )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < F_34 ( V_118 ) ; V_61 ++ )
if ( V_118 [ V_61 ] . type == type )
return & V_118 [ V_61 ] ;
F_50 ( 1 ) ;
return & V_118 [ 0 ] ;
}
static const struct V_116 * F_51 ( const char * V_40 , T_3 V_119 )
{
const struct V_116 * V_69 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_34 ( V_118 ) ; V_61 ++ ) {
V_69 = & V_118 [ V_61 ] ;
if ( ( strlen ( V_69 -> V_40 ) == V_119 && ! strncmp ( V_69 -> V_40 , V_40 , V_119 ) ) ||
( strlen ( V_69 -> V_120 ) == V_119 && ! strncmp ( V_69 -> V_120 , V_40 , V_119 ) ) )
return & V_118 [ V_61 ] ;
}
return NULL ;
}
static int F_52 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
V_65 [ 0 ] = 0xa5 ;
if ( F_24 ( V_31 , V_65 , V_80 ) )
return - 1 ;
if ( V_65 [ 0 ] != 0x00 && V_65 [ 0 ] != 0x03 &&
V_65 [ 0 ] != 0x04 && V_65 [ 0 ] != 0xff )
return - 1 ;
if ( F_24 ( V_31 , NULL , V_102 ) )
F_12 ( V_1 , L_18 ,
V_31 -> V_35 -> V_41 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_1 )
{
if ( V_121 != V_99 ) {
V_1 -> V_87 ( V_1 , V_1 -> V_70 ) ;
V_1 -> V_88 ( V_1 , V_1 -> V_67 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_62 ) ;
}
}
int F_54 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_122 ) ) {
F_12 ( V_1 , L_19 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
return - 1 ;
}
F_8 ( V_1 , V_39 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_123 ) ) {
F_12 ( V_1 , L_20 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
return - 1 ;
}
F_8 ( V_1 , V_124 ) ;
return 0 ;
}
static void F_56 ( struct V_125 * V_24 )
{
struct V_1 * V_126 = NULL , * V_1 =
F_57 ( V_24 , struct V_1 , V_54 . V_24 ) ;
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
T_1 V_36 = V_7 ;
bool V_127 = false , V_128 = false ;
int V_61 ;
F_58 ( & V_129 ) ;
if ( V_1 -> V_29 != V_51 )
goto V_45;
if ( V_35 -> V_126 && V_35 -> V_130 . type == V_131 ) {
V_126 = F_16 ( V_35 -> V_126 ) ;
F_55 ( V_126 ) ;
}
V_1 -> V_132 ++ ;
if ( F_59 ( & V_1 -> V_31 , V_123 , 20 ) ) {
if ( V_1 -> V_132 < 3 || V_1 -> V_133 )
V_127 = true ;
} else
V_1 -> V_133 = true ;
if ( ! V_127 ) {
if ( V_1 -> V_89 ( V_1 ) )
V_127 = true ;
else {
F_8 ( V_1 , V_124 ) ;
for ( V_61 = 0 ; V_61 < V_1 -> V_6 ; V_61 ++ ) {
V_1 -> V_5 ++ ;
V_36 = V_1 -> V_37 ( V_1 ) ;
if ( V_36 != V_7 )
break;
}
if ( V_36 != V_22 )
V_127 = true ;
F_8 ( V_1 , V_51 ) ;
}
}
for ( V_61 = 0 ; V_61 < 5 ; V_61 ++ ) {
if ( ! F_24 ( & V_1 -> V_31 , NULL , V_122 ) ) {
V_128 = true ;
break;
}
F_60 ( 200 ) ;
}
if ( ! V_128 ) {
F_12 ( V_1 , L_21 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
V_127 = true ;
}
if ( V_127 ) {
F_8 ( V_1 , V_43 ) ;
F_22 ( V_1 ,
L_22 ) ;
F_14 ( V_35 ) ;
} else
F_8 ( V_1 , V_39 ) ;
if ( V_126 )
F_54 ( V_126 ) ;
V_45:
F_61 ( & V_129 ) ;
}
static void F_62 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_126 = NULL ;
F_58 ( & V_129 ) ;
if ( V_35 -> V_126 && V_35 -> V_130 . type == V_131 ) {
V_126 = F_16 ( V_35 -> V_126 ) ;
F_55 ( V_126 ) ;
}
F_8 ( V_1 , V_134 ) ;
if ( F_24 ( & V_1 -> V_31 , NULL , V_123 ) )
F_12 ( V_1 , L_23 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
if ( V_1 -> V_92 )
V_1 -> V_92 ( V_1 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_102 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_122 ) ;
if ( V_126 ) {
if ( V_126 -> V_94 )
V_126 -> V_94 ( V_126 ) ;
F_54 ( V_126 ) ;
}
F_61 ( & V_129 ) ;
}
static void F_63 ( struct V_35 * V_35 )
{
struct V_1 * V_1 , * V_126 = NULL ;
V_1 = F_16 ( V_35 ) ;
F_64 ( & V_35 -> V_3 . V_135 , & V_136 ) ;
F_58 ( & V_129 ) ;
F_8 ( V_1 , V_124 ) ;
F_61 ( & V_129 ) ;
F_65 ( V_26 ) ;
F_58 ( & V_129 ) ;
if ( V_35 -> V_126 && V_35 -> V_130 . type == V_131 ) {
V_126 = F_16 ( V_35 -> V_126 ) ;
F_55 ( V_126 ) ;
}
if ( V_1 -> V_91 )
V_1 -> V_91 ( V_1 ) ;
if ( V_126 && V_126 -> V_94 )
V_126 -> V_94 ( V_126 ) ;
F_8 ( V_1 , V_43 ) ;
F_66 ( V_35 ) ;
F_67 ( V_35 , NULL ) ;
F_68 ( V_1 -> V_3 ) ;
F_69 ( V_1 ) ;
if ( V_126 )
F_54 ( V_126 ) ;
F_61 ( & V_129 ) ;
}
static int F_70 ( struct V_1 * V_1 ,
const struct V_116 * V_137 )
{
const struct V_116 * V_138 ;
struct V_2 * V_2 = V_1 -> V_3 ;
V_2 -> V_3 . V_126 = & V_1 -> V_31 . V_35 -> V_3 ;
if ( V_137 && ( V_137 -> F_39 || V_137 -> V_139 ) ) {
F_37 ( V_1 ) ;
if ( V_137 -> F_39 && V_137 -> F_39 ( V_1 , true ) < 0 )
return - 1 ;
if ( V_137 -> V_139 && V_137 -> V_139 ( V_1 ) < 0 )
return - 1 ;
V_1 -> type = V_137 -> type ;
V_138 = V_137 ;
} else {
V_1 -> type = F_40 ( V_1 ,
V_121 , true ) ;
V_138 = F_49 ( V_1 -> type ) ;
}
V_1 -> V_48 = V_138 -> V_48 ;
if ( V_1 -> V_6 == 3 )
V_1 -> V_58 = 0 ;
if ( V_1 -> V_58 && V_1 -> V_89 ( V_1 ) )
V_1 -> V_58 = 0 ;
snprintf ( V_1 -> V_140 , sizeof( V_1 -> V_140 ) , L_24 ,
V_138 -> V_40 , V_1 -> V_79 , V_1 -> V_40 ) ;
V_2 -> V_40 = V_1 -> V_140 ;
V_2 -> V_41 = V_1 -> V_41 ;
V_2 -> V_130 . V_141 = V_142 ;
V_2 -> V_130 . V_79 = 0x0002 ;
V_2 -> V_130 . V_143 = V_1 -> type ;
V_2 -> V_130 . V_144 = V_1 -> V_145 ;
return 0 ;
}
static int F_71 ( struct V_35 * V_35 , struct V_146 * V_147 )
{
struct V_1 * V_1 , * V_126 = NULL ;
struct V_2 * V_2 ;
int V_148 = 0 , error = - V_149 ;
F_58 ( & V_129 ) ;
if ( V_35 -> V_126 && V_35 -> V_130 . type == V_131 ) {
V_126 = F_16 ( V_35 -> V_126 ) ;
F_55 ( V_126 ) ;
}
V_1 = F_72 ( sizeof( struct V_1 ) , V_150 ) ;
V_2 = F_73 () ;
if ( ! V_1 || ! V_2 )
goto V_151;
F_74 ( & V_1 -> V_31 , V_35 ) ;
F_75 ( & V_1 -> V_54 , F_56 ) ;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_41 , sizeof( V_1 -> V_41 ) , L_25 , V_35 -> V_41 ) ;
F_8 ( V_1 , V_134 ) ;
F_67 ( V_35 , V_1 ) ;
error = F_76 ( V_35 , V_147 ) ;
if ( error )
goto V_152;
if ( F_52 ( V_1 ) < 0 ) {
error = - V_153 ;
goto V_154;
}
V_1 -> V_70 = V_155 ;
V_1 -> V_67 = V_156 ;
V_1 -> V_42 = V_157 ;
V_1 -> V_58 = V_126 ? 0 : V_158 ;
V_1 -> V_159 = V_160 ;
F_70 ( V_1 , NULL ) ;
F_8 ( V_1 , V_124 ) ;
F_53 ( V_1 ) ;
error = F_77 ( V_1 -> V_3 ) ;
if ( error )
goto V_161;
if ( V_126 && V_126 -> V_93 )
V_126 -> V_93 ( V_126 ) ;
error = F_78 ( & V_35 -> V_3 . V_135 , & V_136 ) ;
if ( error )
goto V_162;
F_54 ( V_1 ) ;
V_45:
if ( V_126 )
F_54 ( V_126 ) ;
F_61 ( & V_129 ) ;
return V_148 ;
V_162:
if ( V_126 && V_126 -> V_94 )
V_126 -> V_94 ( V_126 ) ;
F_68 ( V_1 -> V_3 ) ;
V_2 = NULL ;
V_161:
if ( V_1 -> V_91 )
V_1 -> V_91 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_154:
F_66 ( V_35 ) ;
V_152:
F_67 ( V_35 , NULL ) ;
V_151:
F_79 ( V_2 ) ;
F_69 ( V_1 ) ;
V_148 = error ;
goto V_45;
}
static int F_80 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_126 = NULL ;
struct V_146 * V_147 = V_35 -> V_147 ;
unsigned char type ;
int V_36 = - 1 ;
if ( ! V_147 || ! V_1 ) {
F_81 ( V_1 ,
L_26 ) ;
return - 1 ;
}
F_58 ( & V_129 ) ;
if ( V_35 -> V_126 && V_35 -> V_130 . type == V_131 ) {
V_126 = F_16 ( V_35 -> V_126 ) ;
F_55 ( V_126 ) ;
}
F_8 ( V_1 , V_134 ) ;
if ( V_1 -> V_90 ) {
if ( V_1 -> V_90 ( V_1 ) )
goto V_45;
} else {
F_25 ( V_1 ) ;
if ( F_52 ( V_1 ) < 0 )
goto V_45;
type = F_40 ( V_1 , V_121 , false ) ;
if ( V_1 -> type != type )
goto V_45;
}
F_8 ( V_1 , V_124 ) ;
F_53 ( V_1 ) ;
if ( V_126 && V_126 -> V_93 )
V_126 -> V_93 ( V_126 ) ;
F_54 ( V_1 ) ;
V_36 = 0 ;
V_45:
if ( V_126 )
F_54 ( V_126 ) ;
F_61 ( & V_129 ) ;
return V_36 ;
}
T_4 F_82 ( struct V_163 * V_3 , struct V_164 * V_165 ,
char * V_166 )
{
struct V_35 * V_35 = F_83 ( V_3 ) ;
struct V_167 * V_168 = F_84 ( V_165 ) ;
struct V_1 * V_1 ;
V_1 = F_16 ( V_35 ) ;
return V_168 -> V_169 ( V_1 , V_168 -> V_44 , V_166 ) ;
}
T_4 F_85 ( struct V_163 * V_3 , struct V_164 * V_165 ,
const char * V_166 , T_3 V_170 )
{
struct V_35 * V_35 = F_83 ( V_3 ) ;
struct V_167 * V_168 = F_84 ( V_165 ) ;
struct V_1 * V_1 , * V_126 = NULL ;
int V_148 ;
V_148 = F_86 ( & V_129 ) ;
if ( V_148 )
goto V_45;
V_1 = F_16 ( V_35 ) ;
if ( V_168 -> V_171 ) {
if ( V_1 -> V_29 == V_43 ) {
V_148 = - V_153 ;
goto V_172;
}
if ( V_35 -> V_126 && V_35 -> V_130 . type == V_131 ) {
V_126 = F_16 ( V_35 -> V_126 ) ;
F_55 ( V_126 ) ;
}
F_55 ( V_1 ) ;
}
V_148 = V_168 -> V_173 ( V_1 , V_168 -> V_44 , V_166 , V_170 ) ;
if ( V_168 -> V_171 ) {
if ( V_148 != - V_153 )
F_54 ( V_1 ) ;
if ( V_126 )
F_54 ( V_126 ) ;
}
V_172:
F_61 ( & V_129 ) ;
V_45:
return V_148 ;
}
static T_4 F_87 ( struct V_1 * V_1 , void * V_174 , char * V_166 )
{
unsigned int * V_175 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_174 ) ;
return sprintf ( V_166 , L_27 , * V_175 ) ;
}
static T_4 F_88 ( struct V_1 * V_1 , void * V_174 , const char * V_166 , T_3 V_170 )
{
unsigned int * V_175 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_174 ) ;
unsigned int V_176 ;
int V_177 ;
V_177 = F_89 ( V_166 , 10 , & V_176 ) ;
if ( V_177 )
return V_177 ;
* V_175 = V_176 ;
return V_170 ;
}
static T_4 F_90 ( struct V_1 * V_1 , void * V_44 , char * V_166 )
{
return sprintf ( V_166 , L_28 , F_49 ( V_1 -> type ) -> V_40 ) ;
}
static T_4 F_91 ( struct V_1 * V_1 , void * V_44 , const char * V_166 , T_3 V_170 )
{
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
struct V_1 * V_126 = NULL ;
struct V_2 * V_178 , * V_179 ;
const struct V_116 * V_137 , * V_180 ;
int error ;
int V_181 = 0 ;
V_137 = F_51 ( V_166 , V_170 ) ;
if ( ! V_137 )
return - V_182 ;
if ( V_1 -> type == V_137 -> type )
return V_170 ;
V_179 = F_73 () ;
if ( ! V_179 )
return - V_149 ;
while ( ! F_92 ( & V_35 -> V_183 ) ) {
if ( ++ V_181 > 3 ) {
F_12 ( V_1 ,
L_29 ) ;
F_79 ( V_179 ) ;
return - V_184 ;
}
F_61 ( & V_129 ) ;
F_93 ( V_35 ) ;
F_58 ( & V_129 ) ;
if ( V_35 -> V_147 != & V_185 ) {
F_79 ( V_179 ) ;
return - V_153 ;
}
if ( V_1 -> type == V_137 -> type ) {
F_79 ( V_179 ) ;
return V_170 ;
}
}
if ( V_35 -> V_126 && V_35 -> V_130 . type == V_131 ) {
V_126 = F_16 ( V_35 -> V_126 ) ;
if ( V_126 -> V_94 )
V_126 -> V_94 ( V_126 ) ;
}
V_178 = V_1 -> V_3 ;
V_180 = F_49 ( V_1 -> type ) ;
if ( V_1 -> V_91 )
V_1 -> V_91 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_1 -> V_3 = V_179 ;
F_8 ( V_1 , V_134 ) ;
if ( F_70 ( V_1 , V_137 ) < 0 ) {
F_25 ( V_1 ) ;
F_70 ( V_1 , & V_118 [ 0 ] ) ;
}
F_53 ( V_1 ) ;
F_8 ( V_1 , V_124 ) ;
error = F_77 ( V_1 -> V_3 ) ;
if ( error ) {
if ( V_1 -> V_91 )
V_1 -> V_91 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
F_79 ( V_179 ) ;
V_1 -> V_3 = V_178 ;
F_8 ( V_1 , V_134 ) ;
F_70 ( V_1 , V_180 ) ;
F_53 ( V_1 ) ;
F_8 ( V_1 , V_124 ) ;
return error ;
}
F_68 ( V_178 ) ;
if ( V_126 && V_126 -> V_93 )
V_126 -> V_93 ( V_126 ) ;
return V_170 ;
}
static T_4 F_94 ( struct V_1 * V_1 , void * V_44 , const char * V_166 , T_3 V_170 )
{
unsigned int V_176 ;
int V_177 ;
V_177 = F_89 ( V_166 , 10 , & V_176 ) ;
if ( V_177 )
return V_177 ;
V_1 -> V_87 ( V_1 , V_176 ) ;
return V_170 ;
}
static T_4 F_95 ( struct V_1 * V_1 , void * V_44 , const char * V_166 , T_3 V_170 )
{
unsigned int V_176 ;
int V_177 ;
V_177 = F_89 ( V_166 , 10 , & V_176 ) ;
if ( V_177 )
return V_177 ;
V_1 -> V_88 ( V_1 , V_176 ) ;
return V_170 ;
}
static int F_96 ( const char * V_186 , const struct V_187 * V_188 )
{
const struct V_116 * V_137 ;
if ( ! V_186 )
return - V_182 ;
V_137 = F_51 ( V_186 , strlen ( V_186 ) ) ;
if ( ! V_137 || ! V_137 -> V_189 )
return - V_182 ;
* ( ( unsigned int * ) V_188 -> V_190 ) = V_137 -> type ;
return 0 ;
}
static int F_97 ( char * V_191 , const struct V_187 * V_188 )
{
int type = * ( ( unsigned int * ) V_188 -> V_190 ) ;
return sprintf ( V_191 , L_30 , F_49 ( type ) -> V_40 ) ;
}
static int T_5 F_98 ( void )
{
int V_177 ;
F_99 () ;
F_100 () ;
F_101 () ;
V_26 = F_102 ( L_31 ) ;
if ( ! V_26 ) {
F_103 ( L_32 ) ;
return - V_149 ;
}
V_177 = F_104 ( & V_185 ) ;
if ( V_177 )
F_105 ( V_26 ) ;
return V_177 ;
}
static void T_6 F_106 ( void )
{
F_107 ( & V_185 ) ;
F_105 ( V_26 ) ;
}
