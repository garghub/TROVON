static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_2 ( V_3 , V_2 -> V_5 ) ;
}
static char * F_3 ( struct V_1 * V_2 , int V_6 ,
int V_7 )
{
return F_4 ( & V_2 -> V_8 , V_9 , V_6 ,
V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 , const unsigned char * V_10 )
{
int V_7 = 1 + sizeof( V_2 -> V_11 ) ;
char * V_12 = F_3 ( V_2 , V_13 , V_7 ) ;
if ( ! V_12 )
return;
V_12 [ V_14 ] = 5 ;
memcpy ( V_12 + V_14 + 1 , V_10 , sizeof( V_2 -> V_11 ) ) ;
F_6 ( & V_2 -> V_8 , V_12 , V_7 ) ;
memcpy ( & V_2 -> V_11 , V_10 , sizeof( V_2 -> V_11 ) ) ;
F_1 ( V_2 ) ;
F_7 ( V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_15 , int V_16 )
{
V_2 -> V_11 . V_17 [ V_15 ] = V_16 ;
F_2 ( V_15 , V_2 -> V_5 ) ;
V_2 -> V_18 = 1 ;
}
static void F_9 ( struct V_1 * V_2 , int type ,
int V_19 )
{
V_2 -> V_18 = 0 ;
F_2 ( V_20 , & V_2 -> V_21 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
const unsigned char * V_22 = V_2 -> V_8 . V_23 ;
switch ( V_22 [ 0 ] & 0xf0 ) {
case V_24 :
case V_25 :
case V_26 :
break;
default:
return;
}
switch ( V_22 [ 0 ] ) {
case V_24 | V_27 :
F_8 ( V_2 , V_22 [ 1 ] , V_22 [ 2 ] ) ;
case V_24 | V_28 :
if ( ( V_22 [ 1 ] == V_29 ) ||
( V_22 [ 1 ] == V_30 ) )
F_11 ( & V_2 -> V_31 , & V_2 -> V_8 , 0 ,
V_32 ) ;
break;
case V_25 | V_27 :
case V_25 | V_28 :
V_2 -> V_33 = V_22 [ 1 ] ;
V_2 -> V_18 = 0 ;
F_2 ( V_34 , & V_2 -> V_21 ) ;
F_11 ( & V_2 -> V_31 , & V_2 -> V_8 , 0 ,
V_32 ) ;
break;
case V_26 | V_27 :
case V_26 | V_35 :
if ( memcmp ( V_22 + 1 , V_36 , sizeof( V_36 ) ) == 0 ) {
switch ( V_22 [ 5 ] ) {
case V_13 :
if ( V_2 -> V_8 . V_37 ==
sizeof( V_2 -> V_11 ) + 7 ) {
switch ( V_2 -> V_31 . V_38 ) {
case V_32 :
memcpy ( & V_2 -> V_11 , V_22 + 7 ,
sizeof( V_2 -> V_11 ) ) ;
F_1 ( V_2 ) ;
break;
case V_39 :
memcpy ( & V_2 -> V_40 ,
V_22 + 7 ,
sizeof
( V_2 -> V_40 ) ) ;
break;
default:
F_12 ( F_13
( V_2 ->
V_8 . V_41 ,
L_1 ,
V_2 ->
V_31 . V_38 ) ) ;
}
F_14 ( & V_2 -> V_31 ) ;
F_15 ( V_2 ) ;
} else
F_12 ( F_13
( V_2 -> V_8 . V_41 ,
L_2 ,
V_2 ->
V_8 . V_37 ,
( int )
sizeof( V_2 -> V_11 ) +
7 ) ) ;
break;
case V_42 : {
short V_16 =
( ( int ) V_22 [ 7 ] << 12 ) | ( ( int ) V_22 [ 8 ]
<< 8 ) |
( ( int ) V_22 [ 9 ] << 4 ) | ( int ) V_22 [ 10 ] ;
#define F_16 ( T_1 ) \
case POD_ ## x: \
pod->x.value = value; \
wake_up(&pod->x.wait); \
break;
switch ( V_22 [ 6 ] ) {
F_16
( V_43 ) ;
F_16 ( V_44 ) ;
F_16
( V_45 ) ;
F_16
( V_46 ) ;
F_16
( V_47 ) ;
F_16
( V_48 ) ;
#undef F_16
default:
F_12 ( F_13
( V_2 ->
V_8 . V_41 ,
L_3 ,
V_22 [ 6 ] ) ) ;
}
break;
}
case V_49 :
break;
case V_50 :
F_9 ( V_2 , V_22 [ 6 ] , V_22 [ 7 ] ) ;
break;
case V_51 :
F_12 ( F_13
( V_2 -> V_8 . V_41 ,
L_4 ) ) ;
V_2 -> V_52 . V_16 = 1 ;
F_17 ( & V_2 -> V_52 . V_53 ) ;
break;
case V_54 :
F_12 ( F_13
( V_2 -> V_8 . V_41 ,
L_5 ,
V_22 [ 5 ] ) ) ;
break;
default:
F_12 ( F_13
( V_2 -> V_8 . V_41 ,
L_6 ,
V_22 [ 5 ] ) ) ;
}
} else
if ( memcmp
( V_22 , V_55 ,
sizeof( V_55 ) ) == 0 ) {
V_2 -> V_56 =
V_22 [ 13 ] * 100 + V_22 [ 14 ] * 10 + V_22 [ 15 ] ;
V_2 -> V_57 =
( ( int ) V_22 [ 8 ] << 16 ) | ( ( int ) V_22 [ 9 ] << 8 ) | ( int )
V_22 [ 10 ] ;
F_18 ( V_2 ) ;
} else
F_12 ( F_13
( V_2 -> V_8 . V_41 ,
L_7 ) ) ;
break;
case V_58 :
break;
default:
F_12 ( F_13
( V_2 -> V_8 . V_41 ,
L_8 , V_22 [ 0 ] ) ) ;
}
}
void F_19 ( struct V_1 * V_2 , unsigned char * V_10 ,
int V_59 )
{
int V_3 ;
if ( ! V_2 -> V_60 )
return;
for ( V_3 = 0 ; V_3 < V_59 ; ++ V_3 ) {
if ( V_10 [ V_3 ] == ( V_25 | V_28 ) ) {
F_20 ( & V_2 -> V_31 ) ;
break;
} else
if ( ( V_10 [ V_3 ] == ( V_24 | V_28 ) )
&& ( V_3 < V_59 - 1 ) )
if ( ( V_10 [ V_3 + 1 ] == V_29 )
|| ( V_10 [ V_3 + 1 ] == V_30 ) ) {
F_20 ( & V_2 -> V_31 ) ;
break;
}
}
}
static void F_21 ( struct V_1 * V_2 , int V_16 )
{
F_20 ( & V_2 -> V_31 ) ;
if ( F_22 ( & V_2 -> V_8 , V_16 ) == 0 )
V_2 -> V_33 = V_16 ;
else
F_14 ( & V_2 -> V_31 ) ;
}
void F_23 ( struct V_1 * V_2 , int V_15 ,
int V_16 )
{
if ( F_24 ( & V_2 -> V_8 , V_15 , V_16 ) == 0 )
F_8 ( V_2 , V_15 , V_16 ) ;
if ( ( V_15 == V_29 ) || ( V_15 == V_30 ) )
F_20 ( & V_2 -> V_31 ) ;
}
static int F_25 ( const char * V_22 , short V_61 , short V_62 ,
unsigned char * V_63 )
{
unsigned long V_16 ;
short V_64 ;
int V_65 ;
V_65 = F_26 ( V_22 , 10 , & V_16 ) ;
if ( V_65 )
return V_65 ;
V_64 = ( V_16 < 0x40 ) ? V_61 : V_62 ;
V_16 &= 0x3f ;
V_63 [ 0 ] = V_64 >> 7 ;
V_63 [ 1 ] = V_16 | ( V_64 & 0x7f ) ;
return 0 ;
}
static T_2 F_27 ( struct V_66 * V_67 , const char * V_22 ,
T_3 V_68 , short V_61 , short V_62 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
int V_65 ;
int V_7 = 3 + sizeof( V_2 -> V_40 ) ;
char * V_12 = F_3 ( V_2 , V_54 , V_7 ) ;
if ( ! V_12 )
return 0 ;
V_12 [ V_14 ] = 5 ;
V_65 = F_25 ( V_22 , V_61 , V_62 , V_12 + V_14 + 1 ) ;
if ( V_65 ) {
F_7 ( V_12 ) ;
return V_65 ;
}
memcpy ( V_12 + V_14 + 3 , & V_2 -> V_40 ,
sizeof( V_2 -> V_40 ) ) ;
F_6 ( & V_2 -> V_8 , V_12 , V_7 ) ;
F_7 ( V_12 ) ;
return V_68 ;
}
static T_2 F_30 ( struct V_66 * V_67 , const char * V_22 ,
T_3 V_68 , short V_61 ,
short V_62 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
int V_65 ;
int V_7 = 4 ;
char * V_12 = F_3 ( V_2 , V_71 , V_7 ) ;
if ( ! V_12 )
return 0 ;
V_65 = F_25 ( V_22 , V_61 , V_62 , V_12 + V_14 ) ;
if ( V_65 ) {
F_7 ( V_12 ) ;
return V_65 ;
}
V_12 [ V_14 + 2 ] = 0 ;
V_12 [ V_14 + 3 ] = 0 ;
F_31 ( & V_2 -> V_31 , V_39 ) ;
if ( F_6 ( & V_2 -> V_8 , V_12 , V_7 ) < V_7 )
F_14 ( & V_2 -> V_31 ) ;
F_7 ( V_12 ) ;
return V_68 ;
}
static T_2 F_32 ( struct V_1 * V_2 , const char * V_72 ,
char * V_22 )
{
int V_59 = 0 ;
const char * V_73 ;
char * V_74 ;
char * V_75 = V_22 ;
int V_76 = F_33 ( & V_2 -> V_31 ) ;
if ( V_76 < 0 )
return V_76 ;
for ( V_73 = V_72 , V_74 = V_22 ; * V_73 ; ++ V_73 , ++ V_74 ) {
* V_74 = * V_73 ;
if ( * V_74 != ' ' )
V_75 = V_74 ;
if ( ++ V_59 == V_77 )
break;
}
* ( V_75 + 1 ) = '\n' ;
return V_75 - V_22 + 2 ;
}
static T_2 F_34 ( struct V_66 * V_67 ,
struct V_78 * V_79 , char * V_22 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
return sprintf ( V_22 , L_9 , V_2 -> V_33 ) ;
}
static T_2 F_35 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
const char * V_22 , T_3 V_68 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
unsigned long V_16 ;
int V_65 ;
V_65 = F_26 ( V_22 , 10 , & V_16 ) ;
if ( V_65 )
return V_65 ;
F_21 ( V_2 , V_16 ) ;
return V_68 ;
}
static T_2 F_36 ( struct V_66 * V_67 , struct V_78 * V_79 ,
char * V_22 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
return F_32 ( V_2 , V_2 -> V_11 . V_80 + V_81 ,
V_22 ) ;
}
static T_2 F_37 ( struct V_66 * V_67 ,
struct V_78 * V_79 , char * V_22 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
return F_32 ( V_2 ,
V_2 -> V_40 . V_80 + V_81 ,
V_22 ) ;
}
static T_2 F_38 ( struct V_66 * V_67 , struct V_78 * V_79 ,
char * V_22 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
int V_76 = F_33 ( & V_2 -> V_31 ) ;
if ( V_76 < 0 )
return V_76 ;
memcpy ( V_22 , & V_2 -> V_11 , sizeof( V_2 -> V_11 ) ) ;
return sizeof( V_2 -> V_11 ) ;
}
static T_2 F_39 ( struct V_66 * V_67 , struct V_78 * V_79 ,
const char * V_22 , T_3 V_68 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
if ( V_68 != sizeof( V_2 -> V_11 ) ) {
F_13 ( V_2 -> V_8 . V_41 ,
L_10 ,
( int ) sizeof( V_2 -> V_11 ) ) ;
return - V_82 ;
}
F_5 ( V_2 , V_22 ) ;
return sizeof( V_2 -> V_11 ) ;
}
static bool F_40 ( int V_6 )
{
return
( V_6 == V_83 ) ||
( V_6 == V_84 ) ||
( V_6 == V_85 ) || ( V_6 == V_86 ) ;
}
static int F_41 ( struct V_1 * V_2 , int * V_16 ,
int V_6 , struct V_87 * V_15 , int V_88 )
{
char * V_12 ;
static const int V_7 = 1 ;
int V_76 = 0 ;
if ( ( ( V_2 -> V_11 . V_17 [ V_89 ] & 0x40 ) == 0 )
&& F_40 ( V_6 ) )
return - V_90 ;
V_15 -> V_16 = V_91 ;
V_12 = F_3 ( V_2 , V_92 , V_7 ) ;
if ( ! V_12 )
return - V_93 ;
V_12 [ V_14 ] = V_6 ;
F_6 ( & V_2 -> V_8 , V_12 , V_7 ) ;
F_7 ( V_12 ) ;
V_76 =
F_42 ( V_15 -> V_53 ,
V_15 -> V_16 != V_91 ) ;
if ( V_76 < 0 )
return V_76 ;
* V_16 = V_88 ? ( int ) ( signed short ) V_15 -> V_16 : ( int ) ( unsigned short )
V_15 -> V_16 ;
if ( * V_16 == V_91 )
* V_16 = 0 ;
return 0 ;
}
static T_2 F_43 ( struct V_1 * V_2 , char * V_22 ,
int V_6 , struct V_87 * V_15 ,
int V_88 )
{
int V_76 , V_16 = 0 ;
V_76 = F_41 ( V_2 , & V_16 , V_6 , V_15 , V_88 ) ;
if ( V_76 < 0 )
return V_76 ;
return sprintf ( V_22 , L_9 , V_16 ) ;
}
static int F_44 ( struct V_1 * V_2 , int V_16 ,
int V_6 )
{
char * V_12 ;
static const int V_7 = 5 ;
if ( ( ( V_2 -> V_11 . V_17 [ V_89 ] & 0x40 ) == 0 )
&& F_40 ( V_6 ) )
return - V_82 ;
V_12 = F_3 ( V_2 , V_42 , V_7 ) ;
if ( ! V_12 )
return - V_93 ;
V_12 [ V_14 ] = V_6 ;
V_12 [ V_14 + 1 ] = ( V_16 >> 12 ) & 0x0f ;
V_12 [ V_14 + 2 ] = ( V_16 >> 8 ) & 0x0f ;
V_12 [ V_14 + 3 ] = ( V_16 >> 4 ) & 0x0f ;
V_12 [ V_14 + 4 ] = ( V_16 ) & 0x0f ;
F_6 ( & V_2 -> V_8 , V_12 , V_7 ) ;
F_7 ( V_12 ) ;
return 0 ;
}
static T_2 F_45 ( struct V_1 * V_2 ,
const char * V_22 , int V_68 , int V_6 ,
unsigned short V_94 )
{
int V_76 ;
unsigned short V_16 = F_46 ( V_22 , NULL , 10 ) & V_94 ;
V_76 = F_44 ( V_2 , V_16 , V_6 ) ;
return ( V_76 < 0 ) ? V_76 : V_68 ;
}
static T_2 F_47 ( struct V_66 * V_67 ,
struct V_78 * V_79 , char * V_22 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
int V_76 = F_33 ( & V_2 -> V_31 ) ;
if ( V_76 < 0 )
return V_76 ;
memcpy ( V_22 , & V_2 -> V_40 , sizeof( V_2 -> V_40 ) ) ;
return sizeof( V_2 -> V_40 ) ;
}
static T_2 F_48 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
const char * V_22 , T_3 V_68 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
if ( V_68 != sizeof( V_2 -> V_11 ) ) {
F_13 ( V_2 -> V_8 . V_41 ,
L_10 ,
( int ) sizeof( V_2 -> V_11 ) ) ;
return - V_82 ;
}
memcpy ( & V_2 -> V_40 , V_22 , sizeof( V_2 -> V_11 ) ) ;
return sizeof( V_2 -> V_11 ) ;
}
static T_2 F_49 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
const char * V_22 , T_3 V_68 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
int V_7 = 0 ;
char * V_12 = F_3 ( V_2 , V_49 , V_7 ) ;
if ( ! V_12 )
return 0 ;
F_6 ( & V_2 -> V_8 , V_12 , V_7 ) ;
F_7 ( V_12 ) ;
return V_68 ;
}
static T_2 F_50 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
const char * V_22 , T_3 V_68 )
{
return F_27 ( V_67 , V_22 , V_68 , 0x0000 , 0x00c0 ) ;
}
static T_2 F_51 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
const char * V_22 , T_3 V_68 )
{
return F_27 ( V_67 , V_22 , V_68 , 0x0080 , 0x0080 ) ;
}
static T_2 F_52 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
const char * V_22 , T_3 V_68 )
{
return F_27 ( V_67 , V_22 , V_68 , 0x0040 , 0x0100 ) ;
}
static T_2 F_53 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
const char * V_22 , T_3 V_68 )
{
return F_30 ( V_67 , V_22 , V_68 , 0x0000 , 0x00c0 ) ;
}
static T_2 F_54 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
const char * V_22 , T_3 V_68 )
{
return F_30 ( V_67 , V_22 , V_68 , 0x0080 , 0x0080 ) ;
}
static T_2 F_55 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
const char * V_22 , T_3 V_68 )
{
return F_30 ( V_67 , V_22 , V_68 , 0x0040 , 0x0100 ) ;
}
static T_2 F_56 ( struct V_66 * V_67 , struct V_78 * V_79 ,
char * V_22 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
V_22 [ 0 ] = V_2 -> V_18 ? '1' : '0' ;
V_22 [ 1 ] = '\n' ;
return 2 ;
}
static T_2 F_57 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
char * V_22 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
return sprintf ( V_22 , L_9 , V_2 -> V_60 ) ;
}
static T_2 F_58 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
const char * V_22 , T_3 V_68 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
unsigned long V_16 ;
int V_65 ;
V_65 = F_26 ( V_22 , 10 , & V_16 ) ;
if ( V_65 )
return V_65 ;
V_2 -> V_60 = V_16 ? 1 : 0 ;
return V_68 ;
}
static T_2 F_59 ( struct V_66 * V_67 ,
struct V_78 * V_79 , char * V_22 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
return sprintf ( V_22 , L_9 , V_2 -> V_95 ) ;
}
static T_2 F_60 ( struct V_66 * V_67 ,
struct V_78 * V_79 ,
char * V_22 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
return sprintf ( V_22 , L_11 , V_2 -> V_56 / 100 ,
V_2 -> V_56 % 100 ) ;
}
static T_2 F_61 ( struct V_66 * V_67 ,
struct V_78 * V_79 , char * V_22 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
return sprintf ( V_22 , L_9 , V_2 -> V_57 ) ;
}
static T_2 F_62 ( struct V_66 * V_67 ,
struct V_78 * V_79 , char * V_22 )
{
struct V_69 * V_70 = F_28 ( V_67 ) ;
struct V_1 * V_2 = F_29 ( V_70 ) ;
return F_42 ( V_2 -> V_52 . V_53 ,
V_2 -> V_52 . V_16 != 0 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_64 ( V_2 -> V_96 , V_97 ) ;
F_65 ( & V_2 -> V_98 , V_99 , V_100 ,
( unsigned long ) V_2 ) ;
}
static void V_100 ( unsigned long V_10 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 ;
if ( V_2 -> V_96 >= V_101 )
return;
V_2 -> V_96 = V_102 ;
F_65 ( & V_2 -> V_98 , V_99 , V_100 ,
( unsigned long ) V_2 ) ;
F_11 ( & V_2 -> V_31 , & V_2 -> V_8 , 0 ,
V_32 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_103 * V_8 = & V_2 -> V_8 ;
F_64 ( V_2 -> V_96 , V_104 ) ;
F_66 ( V_8 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_64 ( V_2 -> V_96 , V_105 ) ;
F_67 ( & V_2 -> V_106 ) ;
}
static void F_68 ( struct V_107 * V_108 )
{
struct V_1 * V_2 =
F_69 ( V_108 , struct V_1 , V_106 ) ;
struct V_103 * V_8 = & V_2 -> V_8 ;
F_64 ( V_2 -> V_96 , V_109 ) ;
F_70 ( & V_2 -> V_8 , & V_2 -> V_95 ) ;
F_71 ( V_8 ) ;
F_72 ( V_2 -> V_56 ,
V_8 -> V_110 -> V_111 , V_8 -> V_41 ) ;
}
static int F_73 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
V_115 -> type = V_116 ;
V_115 -> V_68 = 1 ;
V_115 -> V_16 . integer . V_117 = 0 ;
V_115 -> V_16 . integer . V_118 = 65535 ;
return 0 ;
}
static int F_74 ( struct V_112 * V_113 ,
struct V_119 * V_120 )
{
struct V_121 * V_122 = F_75 ( V_113 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_122 -> V_8 ;
V_120 -> V_16 . integer . V_16 [ 0 ] = V_2 -> V_43 . V_16 ;
return 0 ;
}
static int F_76 ( struct V_112 * V_113 ,
struct V_119 * V_120 )
{
struct V_121 * V_122 = F_75 ( V_113 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_122 -> V_8 ;
if ( V_120 -> V_16 . integer . V_16 [ 0 ] == V_2 -> V_43 . V_16 )
return 0 ;
V_2 -> V_43 . V_16 = V_120 -> V_16 . integer . V_16 [ 0 ] ;
F_44 ( V_2 , V_120 -> V_16 . integer . V_16 [ 0 ] ,
V_123 ) ;
return 1 ;
}
static void F_77 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_29 ( V_70 ) ;
if ( V_2 == NULL )
return;
F_78 ( & V_2 -> V_8 ) ;
F_79 ( & V_2 -> V_98 ) ;
F_80 ( & V_2 -> V_106 ) ;
F_81 ( & V_2 -> V_31 ) ;
}
static int F_82 ( struct V_66 * V_67 )
{
int V_124 ;
F_83 ( F_84 ( V_67 , & V_125 ) ) ;
F_83 ( F_84 ( V_67 , & V_126 ) ) ;
F_83 ( F_84 ( V_67 , & V_127 ) ) ;
F_83 ( F_84 ( V_67 , & V_128 ) ) ;
F_83 ( F_84 ( V_67 , & V_129 ) ) ;
F_83 ( F_84 ( V_67 , & V_130 ) ) ;
F_83 ( F_84 ( V_67 , & V_131 ) ) ;
F_83 ( F_84 ( V_67 , & V_132 ) ) ;
F_83 ( F_84 ( V_67 , & V_133 ) ) ;
F_83 ( F_84 ( V_67 , & V_134 ) ) ;
F_83 ( F_84 ( V_67 , & V_135 ) ) ;
F_83 ( F_84 ( V_67 , & V_136 ) ) ;
F_83 ( F_84 ( V_67 , & V_137 ) ) ;
F_83 ( F_84 ( V_67 , & V_138 ) ) ;
F_83 ( F_84 ( V_67 , & V_139 ) ) ;
F_83 ( F_84 ( V_67 , & V_140 ) ) ;
F_83 ( F_84 ( V_67 , & V_141 ) ) ;
F_83 ( F_84 ( V_67 , & V_142 ) ) ;
F_83 ( F_84 ( V_67 , & V_143 ) ) ;
F_83 ( F_84 ( V_67 , & V_144 ) ) ;
F_83 ( F_84 ( V_67 , & V_145 ) ) ;
F_83 ( F_84 ( V_67 , & V_146 ) ) ;
F_83 ( F_84 ( V_67 , & V_147 ) ) ;
F_83 ( F_84 ( V_67 , & V_148 ) ) ;
#ifdef F_85
F_83 ( F_84 ( V_67 , & V_149 ) ) ;
#endif
return 0 ;
}
static int F_86 ( struct V_69 * V_70 ,
struct V_1 * V_2 )
{
int V_124 ;
struct V_103 * V_8 = & V_2 -> V_8 ;
F_87 ( & V_2 -> V_98 ) ;
F_88 ( & V_2 -> V_106 , F_68 ) ;
if ( ( V_70 == NULL ) || ( V_2 == NULL ) )
return - V_90 ;
V_2 -> V_33 = 255 ;
F_89 ( & V_2 -> V_43 . V_53 ) ;
F_89 ( & V_2 -> V_44 . V_53 ) ;
F_89 ( & V_2 -> V_45 . V_53 ) ;
F_89 ( & V_2 -> V_46 . V_53 ) ;
F_89 ( & V_2 -> V_47 . V_53 ) ;
F_89 ( & V_2 -> V_48 . V_53 ) ;
F_89 ( & V_2 -> V_52 . V_53 ) ;
memset ( V_2 -> V_5 , 0xff , sizeof( V_2 -> V_5 ) ) ;
V_124 = F_90 ( & V_2 -> V_31 , V_150 ,
sizeof( V_150 ) ) ;
if ( V_124 < 0 ) {
F_13 ( & V_70 -> V_67 , L_12 ) ;
return - V_93 ;
}
V_124 = F_82 ( & V_70 -> V_67 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_8 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_92 ( V_8 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_93 ( V_8 , & V_151 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_94 ( V_8 -> V_152 ,
F_95 ( & V_153 , V_8 -> V_122 ) ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_2 -> V_8 . V_110 -> V_154 & V_155 ) {
V_2 -> V_43 . V_16 = V_91 ;
F_63 ( V_2 ) ;
}
return 0 ;
}
int F_96 ( struct V_69 * V_70 , struct V_1 * V_2 )
{
int V_124 = F_86 ( V_70 , V_2 ) ;
if ( V_124 < 0 )
F_77 ( V_70 ) ;
return V_124 ;
}
void F_97 ( struct V_69 * V_70 )
{
struct V_1 * V_2 ;
if ( V_70 == NULL )
return;
V_2 = F_29 ( V_70 ) ;
if ( V_2 != NULL ) {
struct V_121 * V_122 = V_2 -> V_8 . V_122 ;
struct V_66 * V_67 = & V_70 -> V_67 ;
if ( V_122 != NULL )
F_98 ( V_122 ) ;
if ( V_67 != NULL ) {
F_99 ( V_2 -> V_56 ,
V_2 -> V_8 .
V_110 -> V_111 , V_67 ) ;
F_100 ( V_67 , & V_125 ) ;
F_100 ( V_67 , & V_126 ) ;
F_100 ( V_67 , & V_127 ) ;
F_100 ( V_67 , & V_128 ) ;
F_100 ( V_67 , & V_129 ) ;
F_100 ( V_67 , & V_130 ) ;
F_100 ( V_67 , & V_131 ) ;
F_100 ( V_67 , & V_132 ) ;
F_100 ( V_67 , & V_133 ) ;
F_100 ( V_67 , & V_134 ) ;
F_100 ( V_67 , & V_135 ) ;
F_100 ( V_67 , & V_136 ) ;
F_100 ( V_67 , & V_137 ) ;
F_100 ( V_67 , & V_138 ) ;
F_100 ( V_67 ,
& V_139 ) ;
F_100 ( V_67 , & V_140 ) ;
F_100 ( V_67 , & V_141 ) ;
F_100 ( V_67 , & V_142 ) ;
F_100 ( V_67 , & V_143 ) ;
F_100 ( V_67 , & V_144 ) ;
F_100 ( V_67 , & V_145 ) ;
F_100 ( V_67 , & V_146 ) ;
F_100 ( V_67 , & V_147 ) ;
F_100 ( V_67 , & V_148 ) ;
#ifdef F_85
F_100 ( V_67 , & V_149 ) ;
#endif
}
}
F_77 ( V_70 ) ;
}
