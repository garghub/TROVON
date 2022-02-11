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
if ( V_95 > V_11 &&
F_45 ( V_1 , V_75 ) == 0 ) {
if ( F_46 () ) {
if ( F_47 ( V_1 ) == 0 )
return V_102 ;
return V_99 ;
}
V_95 = V_11 ;
}
if ( V_95 > V_11 ) {
F_24 ( & V_1 -> V_31 , NULL , V_103 ) ;
if ( F_38 ( V_104 ,
V_1 , V_75 ) == 0 ) {
if ( ! V_75 || F_48 ( V_1 ) == 0 )
return V_105 ;
V_95 = V_11 ;
}
}
if ( V_95 > V_11 &&
F_38 ( V_106 , V_1 , V_75 ) == 0 ) {
if ( ! V_75 || F_49 ( V_1 ) == 0 )
return V_57 ;
V_95 = V_11 ;
}
if ( V_95 > V_11 &&
F_38 ( V_107 , V_1 , V_75 ) == 0 ) {
if ( ! V_75 || F_50 ( V_1 ) == 0 )
return V_108 ;
V_95 = V_11 ;
}
if ( V_95 > V_11 ) {
if ( F_38 ( F_29 ,
V_1 , V_75 ) == 0 )
return V_9 ;
if ( F_38 ( V_109 ,
V_1 , V_75 ) == 0 )
return V_110 ;
if ( F_38 ( V_111 ,
V_1 , V_75 ) == 0 )
return V_112 ;
if ( F_38 ( V_113 ,
V_1 , V_75 ) == 0 )
return V_114 ;
}
if ( V_95 > V_11 ) {
if ( F_38 ( V_115 ,
V_1 , V_75 ) == 0 ) {
if ( ! V_75 || F_51 ( V_1 ) == 0 )
return V_116 ;
V_95 = V_11 ;
}
}
F_24 ( & V_1 -> V_31 , NULL , V_103 ) ;
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
static const struct V_117 * F_52 ( enum V_118 type )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < F_34 ( V_119 ) ; V_61 ++ )
if ( V_119 [ V_61 ] . type == type )
return & V_119 [ V_61 ] ;
F_53 ( 1 ) ;
return & V_119 [ 0 ] ;
}
static const struct V_117 * F_54 ( const char * V_40 , T_3 V_120 )
{
const struct V_117 * V_69 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_34 ( V_119 ) ; V_61 ++ ) {
V_69 = & V_119 [ V_61 ] ;
if ( ( strlen ( V_69 -> V_40 ) == V_120 && ! strncmp ( V_69 -> V_40 , V_40 , V_120 ) ) ||
( strlen ( V_69 -> V_121 ) == V_120 && ! strncmp ( V_69 -> V_121 , V_40 , V_120 ) ) )
return & V_119 [ V_61 ] ;
}
return NULL ;
}
static int F_55 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
unsigned char V_65 [ 2 ] ;
V_65 [ 0 ] = 0xa5 ;
if ( F_24 ( V_31 , V_65 , V_80 ) )
return - 1 ;
if ( V_65 [ 0 ] != 0x00 && V_65 [ 0 ] != 0x03 &&
V_65 [ 0 ] != 0x04 && V_65 [ 0 ] != 0xff )
return - 1 ;
if ( F_24 ( V_31 , NULL , V_103 ) )
F_12 ( V_1 , L_18 ,
V_31 -> V_35 -> V_41 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_1 )
{
if ( V_122 != V_99 ) {
V_1 -> V_87 ( V_1 , V_1 -> V_70 ) ;
V_1 -> V_88 ( V_1 , V_1 -> V_67 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_62 ) ;
}
}
int F_57 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_123 ) ) {
F_12 ( V_1 , L_19 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
return - 1 ;
}
F_8 ( V_1 , V_39 ) ;
return 0 ;
}
int F_58 ( struct V_1 * V_1 )
{
if ( F_24 ( & V_1 -> V_31 , NULL , V_124 ) ) {
F_12 ( V_1 , L_20 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
return - 1 ;
}
F_8 ( V_1 , V_125 ) ;
return 0 ;
}
static void F_59 ( struct V_126 * V_24 )
{
struct V_1 * V_127 = NULL , * V_1 =
F_60 ( V_24 , struct V_1 , V_54 . V_24 ) ;
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
T_1 V_36 = V_7 ;
bool V_128 = false , V_129 = false ;
int V_61 ;
F_61 ( & V_130 ) ;
if ( V_1 -> V_29 != V_51 )
goto V_45;
if ( V_35 -> V_127 && V_35 -> V_131 . type == V_132 ) {
V_127 = F_16 ( V_35 -> V_127 ) ;
F_58 ( V_127 ) ;
}
V_1 -> V_133 ++ ;
if ( F_62 ( & V_1 -> V_31 , V_124 , 20 ) ) {
if ( V_1 -> V_133 < 3 || V_1 -> V_134 )
V_128 = true ;
} else
V_1 -> V_134 = true ;
if ( ! V_128 ) {
if ( V_1 -> V_89 ( V_1 ) )
V_128 = true ;
else {
F_8 ( V_1 , V_125 ) ;
for ( V_61 = 0 ; V_61 < V_1 -> V_6 ; V_61 ++ ) {
V_1 -> V_5 ++ ;
V_36 = V_1 -> V_37 ( V_1 ) ;
if ( V_36 != V_7 )
break;
}
if ( V_36 != V_22 )
V_128 = true ;
F_8 ( V_1 , V_51 ) ;
}
}
for ( V_61 = 0 ; V_61 < 5 ; V_61 ++ ) {
if ( ! F_24 ( & V_1 -> V_31 , NULL , V_123 ) ) {
V_129 = true ;
break;
}
F_63 ( 200 ) ;
}
if ( ! V_129 ) {
F_12 ( V_1 , L_21 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
V_128 = true ;
}
if ( V_128 ) {
F_8 ( V_1 , V_43 ) ;
F_22 ( V_1 ,
L_22 ) ;
F_14 ( V_35 ) ;
} else
F_8 ( V_1 , V_39 ) ;
if ( V_127 )
F_57 ( V_127 ) ;
V_45:
F_64 ( & V_130 ) ;
}
static void F_65 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_127 = NULL ;
F_61 ( & V_130 ) ;
if ( V_35 -> V_127 && V_35 -> V_131 . type == V_132 ) {
V_127 = F_16 ( V_35 -> V_127 ) ;
F_58 ( V_127 ) ;
}
F_8 ( V_1 , V_135 ) ;
if ( F_24 ( & V_1 -> V_31 , NULL , V_124 ) )
F_12 ( V_1 , L_23 ,
V_1 -> V_31 . V_35 -> V_41 ) ;
if ( V_1 -> V_92 )
V_1 -> V_92 ( V_1 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_103 ) ;
F_24 ( & V_1 -> V_31 , NULL , V_123 ) ;
if ( V_127 ) {
if ( V_127 -> V_94 )
V_127 -> V_94 ( V_127 ) ;
F_57 ( V_127 ) ;
}
F_64 ( & V_130 ) ;
}
static void F_66 ( struct V_35 * V_35 )
{
struct V_1 * V_1 , * V_127 = NULL ;
V_1 = F_16 ( V_35 ) ;
F_67 ( & V_35 -> V_3 . V_136 , & V_137 ) ;
F_61 ( & V_130 ) ;
F_8 ( V_1 , V_125 ) ;
F_64 ( & V_130 ) ;
F_68 ( V_26 ) ;
F_61 ( & V_130 ) ;
if ( V_35 -> V_127 && V_35 -> V_131 . type == V_132 ) {
V_127 = F_16 ( V_35 -> V_127 ) ;
F_58 ( V_127 ) ;
}
if ( V_1 -> V_91 )
V_1 -> V_91 ( V_1 ) ;
if ( V_127 && V_127 -> V_94 )
V_127 -> V_94 ( V_127 ) ;
F_8 ( V_1 , V_43 ) ;
F_69 ( V_35 ) ;
F_70 ( V_35 , NULL ) ;
F_71 ( V_1 -> V_3 ) ;
F_72 ( V_1 ) ;
if ( V_127 )
F_57 ( V_127 ) ;
F_64 ( & V_130 ) ;
}
static int F_73 ( struct V_1 * V_1 ,
const struct V_117 * V_138 )
{
const struct V_117 * V_139 ;
struct V_2 * V_2 = V_1 -> V_3 ;
V_2 -> V_3 . V_127 = & V_1 -> V_31 . V_35 -> V_3 ;
if ( V_138 && ( V_138 -> F_39 || V_138 -> V_140 ) ) {
F_37 ( V_1 ) ;
if ( V_138 -> F_39 && V_138 -> F_39 ( V_1 , true ) < 0 )
return - 1 ;
if ( V_138 -> V_140 && V_138 -> V_140 ( V_1 ) < 0 )
return - 1 ;
V_1 -> type = V_138 -> type ;
V_139 = V_138 ;
} else {
V_1 -> type = F_40 ( V_1 ,
V_122 , true ) ;
V_139 = F_52 ( V_1 -> type ) ;
}
V_1 -> V_48 = V_139 -> V_48 ;
if ( V_1 -> V_6 == 3 )
V_1 -> V_58 = 0 ;
if ( V_1 -> V_58 && V_1 -> V_89 ( V_1 ) )
V_1 -> V_58 = 0 ;
snprintf ( V_1 -> V_141 , sizeof( V_1 -> V_141 ) , L_24 ,
V_139 -> V_40 , V_1 -> V_79 , V_1 -> V_40 ) ;
V_2 -> V_40 = V_1 -> V_141 ;
V_2 -> V_41 = V_1 -> V_41 ;
V_2 -> V_131 . V_142 = V_143 ;
V_2 -> V_131 . V_79 = 0x0002 ;
V_2 -> V_131 . V_144 = V_1 -> type ;
V_2 -> V_131 . V_145 = V_1 -> V_146 ;
return 0 ;
}
static int F_74 ( struct V_35 * V_35 , struct V_147 * V_148 )
{
struct V_1 * V_1 , * V_127 = NULL ;
struct V_2 * V_2 ;
int V_149 = 0 , error = - V_150 ;
F_61 ( & V_130 ) ;
if ( V_35 -> V_127 && V_35 -> V_131 . type == V_132 ) {
V_127 = F_16 ( V_35 -> V_127 ) ;
F_58 ( V_127 ) ;
}
V_1 = F_75 ( sizeof( struct V_1 ) , V_151 ) ;
V_2 = F_76 () ;
if ( ! V_1 || ! V_2 )
goto V_152;
F_77 ( & V_1 -> V_31 , V_35 ) ;
F_78 ( & V_1 -> V_54 , F_59 ) ;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_41 , sizeof( V_1 -> V_41 ) , L_25 , V_35 -> V_41 ) ;
F_8 ( V_1 , V_135 ) ;
F_70 ( V_35 , V_1 ) ;
error = F_79 ( V_35 , V_148 ) ;
if ( error )
goto V_153;
if ( F_55 ( V_1 ) < 0 ) {
error = - V_154 ;
goto V_155;
}
V_1 -> V_70 = V_156 ;
V_1 -> V_67 = V_157 ;
V_1 -> V_42 = V_158 ;
V_1 -> V_58 = V_127 ? 0 : V_159 ;
V_1 -> V_160 = V_161 ;
F_73 ( V_1 , NULL ) ;
F_8 ( V_1 , V_125 ) ;
F_56 ( V_1 ) ;
error = F_80 ( V_1 -> V_3 ) ;
if ( error )
goto V_162;
if ( V_127 && V_127 -> V_93 )
V_127 -> V_93 ( V_127 ) ;
error = F_81 ( & V_35 -> V_3 . V_136 , & V_137 ) ;
if ( error )
goto V_163;
F_57 ( V_1 ) ;
V_45:
if ( V_127 )
F_57 ( V_127 ) ;
F_64 ( & V_130 ) ;
return V_149 ;
V_163:
if ( V_127 && V_127 -> V_94 )
V_127 -> V_94 ( V_127 ) ;
F_71 ( V_1 -> V_3 ) ;
V_2 = NULL ;
V_162:
if ( V_1 -> V_91 )
V_1 -> V_91 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_155:
F_69 ( V_35 ) ;
V_153:
F_70 ( V_35 , NULL ) ;
V_152:
F_82 ( V_2 ) ;
F_72 ( V_1 ) ;
V_149 = error ;
goto V_45;
}
static int F_83 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = F_16 ( V_35 ) ;
struct V_1 * V_127 = NULL ;
struct V_147 * V_148 = V_35 -> V_148 ;
unsigned char type ;
int V_36 = - 1 ;
if ( ! V_148 || ! V_1 ) {
F_84 ( V_1 ,
L_26 ) ;
return - 1 ;
}
F_61 ( & V_130 ) ;
if ( V_35 -> V_127 && V_35 -> V_131 . type == V_132 ) {
V_127 = F_16 ( V_35 -> V_127 ) ;
F_58 ( V_127 ) ;
}
F_8 ( V_1 , V_135 ) ;
if ( V_1 -> V_90 ) {
if ( V_1 -> V_90 ( V_1 ) )
goto V_45;
} else {
F_25 ( V_1 ) ;
if ( F_55 ( V_1 ) < 0 )
goto V_45;
type = F_40 ( V_1 , V_122 , false ) ;
if ( V_1 -> type != type )
goto V_45;
}
F_8 ( V_1 , V_125 ) ;
F_56 ( V_1 ) ;
if ( V_127 && V_127 -> V_93 )
V_127 -> V_93 ( V_127 ) ;
F_57 ( V_1 ) ;
V_36 = 0 ;
V_45:
if ( V_127 )
F_57 ( V_127 ) ;
F_64 ( & V_130 ) ;
return V_36 ;
}
T_4 F_85 ( struct V_164 * V_3 , struct V_165 * V_166 ,
char * V_167 )
{
struct V_35 * V_35 = F_86 ( V_3 ) ;
struct V_168 * V_169 = F_87 ( V_166 ) ;
struct V_1 * V_1 ;
V_1 = F_16 ( V_35 ) ;
return V_169 -> V_170 ( V_1 , V_169 -> V_44 , V_167 ) ;
}
T_4 F_88 ( struct V_164 * V_3 , struct V_165 * V_166 ,
const char * V_167 , T_3 V_171 )
{
struct V_35 * V_35 = F_86 ( V_3 ) ;
struct V_168 * V_169 = F_87 ( V_166 ) ;
struct V_1 * V_1 , * V_127 = NULL ;
int V_149 ;
V_149 = F_89 ( & V_130 ) ;
if ( V_149 )
goto V_45;
V_1 = F_16 ( V_35 ) ;
if ( V_169 -> V_172 ) {
if ( V_1 -> V_29 == V_43 ) {
V_149 = - V_154 ;
goto V_173;
}
if ( V_35 -> V_127 && V_35 -> V_131 . type == V_132 ) {
V_127 = F_16 ( V_35 -> V_127 ) ;
F_58 ( V_127 ) ;
}
F_58 ( V_1 ) ;
}
V_149 = V_169 -> V_174 ( V_1 , V_169 -> V_44 , V_167 , V_171 ) ;
if ( V_169 -> V_172 ) {
if ( V_149 != - V_154 )
F_57 ( V_1 ) ;
if ( V_127 )
F_57 ( V_127 ) ;
}
V_173:
F_64 ( & V_130 ) ;
V_45:
return V_149 ;
}
static T_4 F_90 ( struct V_1 * V_1 , void * V_175 , char * V_167 )
{
unsigned int * V_176 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_175 ) ;
return sprintf ( V_167 , L_27 , * V_176 ) ;
}
static T_4 F_91 ( struct V_1 * V_1 , void * V_175 , const char * V_167 , T_3 V_171 )
{
unsigned int * V_176 = ( unsigned int * ) ( ( char * ) V_1 + ( T_3 ) V_175 ) ;
unsigned int V_177 ;
int V_178 ;
V_178 = F_92 ( V_167 , 10 , & V_177 ) ;
if ( V_178 )
return V_178 ;
* V_176 = V_177 ;
return V_171 ;
}
static T_4 F_93 ( struct V_1 * V_1 , void * V_44 , char * V_167 )
{
return sprintf ( V_167 , L_28 , F_52 ( V_1 -> type ) -> V_40 ) ;
}
static T_4 F_94 ( struct V_1 * V_1 , void * V_44 , const char * V_167 , T_3 V_171 )
{
struct V_35 * V_35 = V_1 -> V_31 . V_35 ;
struct V_1 * V_127 = NULL ;
struct V_2 * V_179 , * V_180 ;
const struct V_117 * V_138 , * V_181 ;
int error ;
int V_182 = 0 ;
V_138 = F_54 ( V_167 , V_171 ) ;
if ( ! V_138 )
return - V_183 ;
if ( V_1 -> type == V_138 -> type )
return V_171 ;
V_180 = F_76 () ;
if ( ! V_180 )
return - V_150 ;
while ( ! F_95 ( & V_35 -> V_184 ) ) {
if ( ++ V_182 > 3 ) {
F_12 ( V_1 ,
L_29 ) ;
F_82 ( V_180 ) ;
return - V_185 ;
}
F_64 ( & V_130 ) ;
F_96 ( V_35 ) ;
F_61 ( & V_130 ) ;
if ( V_35 -> V_148 != & V_186 ) {
F_82 ( V_180 ) ;
return - V_154 ;
}
if ( V_1 -> type == V_138 -> type ) {
F_82 ( V_180 ) ;
return V_171 ;
}
}
if ( V_35 -> V_127 && V_35 -> V_131 . type == V_132 ) {
V_127 = F_16 ( V_35 -> V_127 ) ;
if ( V_127 -> V_94 )
V_127 -> V_94 ( V_127 ) ;
}
V_179 = V_1 -> V_3 ;
V_181 = F_52 ( V_1 -> type ) ;
if ( V_1 -> V_91 )
V_1 -> V_91 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
V_1 -> V_3 = V_180 ;
F_8 ( V_1 , V_135 ) ;
if ( F_73 ( V_1 , V_138 ) < 0 ) {
F_25 ( V_1 ) ;
F_73 ( V_1 , & V_119 [ 0 ] ) ;
}
F_56 ( V_1 ) ;
F_8 ( V_1 , V_125 ) ;
error = F_80 ( V_1 -> V_3 ) ;
if ( error ) {
if ( V_1 -> V_91 )
V_1 -> V_91 ( V_1 ) ;
F_8 ( V_1 , V_43 ) ;
F_82 ( V_180 ) ;
V_1 -> V_3 = V_179 ;
F_8 ( V_1 , V_135 ) ;
F_73 ( V_1 , V_181 ) ;
F_56 ( V_1 ) ;
F_8 ( V_1 , V_125 ) ;
return error ;
}
F_71 ( V_179 ) ;
if ( V_127 && V_127 -> V_93 )
V_127 -> V_93 ( V_127 ) ;
return V_171 ;
}
static T_4 F_97 ( struct V_1 * V_1 , void * V_44 , const char * V_167 , T_3 V_171 )
{
unsigned int V_177 ;
int V_178 ;
V_178 = F_92 ( V_167 , 10 , & V_177 ) ;
if ( V_178 )
return V_178 ;
V_1 -> V_87 ( V_1 , V_177 ) ;
return V_171 ;
}
static T_4 F_98 ( struct V_1 * V_1 , void * V_44 , const char * V_167 , T_3 V_171 )
{
unsigned int V_177 ;
int V_178 ;
V_178 = F_92 ( V_167 , 10 , & V_177 ) ;
if ( V_178 )
return V_178 ;
V_1 -> V_88 ( V_1 , V_177 ) ;
return V_171 ;
}
static int F_99 ( const char * V_187 , const struct V_188 * V_189 )
{
const struct V_117 * V_138 ;
if ( ! V_187 )
return - V_183 ;
V_138 = F_54 ( V_187 , strlen ( V_187 ) ) ;
if ( ! V_138 || ! V_138 -> V_190 )
return - V_183 ;
* ( ( unsigned int * ) V_189 -> V_191 ) = V_138 -> type ;
return 0 ;
}
static int F_100 ( char * V_192 , const struct V_188 * V_189 )
{
int type = * ( ( unsigned int * ) V_189 -> V_191 ) ;
return sprintf ( V_192 , L_30 , F_52 ( type ) -> V_40 ) ;
}
static int T_5 F_101 ( void )
{
int V_178 ;
F_102 () ;
F_103 () ;
F_104 () ;
V_26 = F_105 ( L_31 ) ;
if ( ! V_26 ) {
F_106 ( L_32 ) ;
return - V_150 ;
}
V_178 = F_107 ( & V_186 ) ;
if ( V_178 )
F_108 ( V_26 ) ;
return V_178 ;
}
static void T_6 F_109 ( void )
{
F_110 ( & V_186 ) ;
F_108 ( V_26 ) ;
}
