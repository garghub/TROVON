static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_2 V_5 [] = { V_3 >> 8 , V_3 & 0xff , V_4 >> 8 , V_4 & 0xff } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_5 , . V_12 = 4 } ;
int V_13 ;
if ( ( V_13 = F_2 ( V_2 -> V_14 , & V_7 , 1 ) ) != 1 ) {
F_3 ( L_1 , V_15 , V_13 , V_3 , V_4 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_17 ;
T_2 V_18 [] = { V_3 >> 8 , V_3 & 0xff } ;
T_2 V_19 [] = { 0 , 0 } ;
struct V_6 V_7 [] = { { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_18 , . V_12 = 2 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_20 , . V_5 = V_19 , . V_12 = 2 } } ;
V_17 = F_2 ( V_2 -> V_14 , V_7 , 2 ) ;
if ( V_17 != 2 ) {
F_3 ( L_2 , V_15 , V_17 ) ;
return - 1 ;
}
return ( V_19 [ 0 ] << 8 | V_19 [ 1 ] ) ;
}
static int F_5 ( struct V_1 * V_2 , const struct V_21 * V_22 )
{
struct V_6 V_7 ;
const char * V_23 = V_22 -> V_4 ;
int V_24 ;
T_2 V_25 [ 255 ] ;
int V_26 ;
int V_13 = 0 ;
F_3 ( L_3 , V_15 ) ;
if ( V_22 -> V_27 < V_28 + V_29 )
return - V_30 ;
F_1 ( V_2 , 0x0F00 , 0x0000 ) ;
F_1 ( V_2 , 0x8F08 , ( ( V_28 / 2 ) & 0xFFFF ) ) ;
F_1 ( V_2 , 0x8F0A , ( ( V_28 / 2 ) >> 16 ) ) ;
V_24 = V_29 ;
while ( V_24 < V_28 + V_29 ) {
V_26 = ( V_24 <= V_28 + V_29 - 252 ) ? 252 : V_28 + V_29 - V_24 ;
V_25 [ 0 ] = 0xCF ;
V_25 [ 1 ] = 0x0A ;
memcpy ( & V_25 [ 2 ] , V_23 + V_24 , V_26 ) ;
V_7 . V_8 = V_2 -> V_9 -> V_10 ;
V_7 . V_11 = 0 ;
V_7 . V_5 = V_25 ;
V_7 . V_12 = V_26 + 2 ;
if ( ( V_13 = F_2 ( V_2 -> V_14 , & V_7 , 1 ) ) != 1 ) {
F_6 ( L_4 , V_15 ) ;
F_6 ( L_5 , V_15 , V_13 ) ;
return V_13 ;
}
V_24 += V_26 ;
}
F_3 ( L_6 , V_15 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x0F08 , 0x000 ) ;
F_1 ( V_2 , 0x0F09 , 0x000 ) ;
F_1 ( V_2 , 0x0F00 , 0x000 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x0F08 , 0x000 ) ;
F_1 ( V_2 , 0x0F09 , 0x000 ) ;
F_1 ( V_2 , 0x0F00 , 0x001 ) ;
F_4 ( V_2 , 0x0D01 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return ( F_4 ( V_2 , 0x0D02 ) > 0 ) ;
}
static int F_10 ( struct V_31 * V_32 , T_1 * V_33 )
{
int V_34 = 1 ;
* V_33 = 0x000 ;
switch ( V_32 -> V_35 ) {
case V_36 :
break;
case V_37 :
* V_33 |= ( 1 << 10 ) ;
break;
case V_38 :
* V_33 |= ( 2 << 10 ) ;
break;
case V_39 :
V_34 = 0 ;
break;
default:
return - V_30 ;
}
switch ( V_32 -> V_40 ) {
case V_41 :
break;
case V_42 :
* V_33 |= ( 1 << 7 ) ;
break;
case V_43 :
* V_33 |= ( 2 << 7 ) ;
break;
case V_44 :
* V_33 |= ( 3 << 7 ) ;
break;
case V_45 :
V_34 = 0 ;
break;
default:
return - V_30 ;
}
switch ( V_32 -> V_46 ) {
case V_47 :
break;
case V_48 :
* V_33 |= ( 1 << 3 ) ;
break;
case V_49 :
* V_33 |= ( 2 << 3 ) ;
break;
case V_50 :
* V_33 |= ( 3 << 3 ) ;
break;
case V_51 :
* V_33 |= ( 4 << 3 ) ;
break;
case V_52 :
V_34 = 0 ;
break;
default:
return - V_30 ;
}
if ( V_34 )
* V_33 |= ( 2 << 1 ) ;
else
* V_33 |= ( 1 << 1 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , 0xC18 , 0x00D ) ;
}
static int F_12 ( struct V_53 * V_54 )
{
struct V_31 * V_32 = & V_54 -> V_55 ;
struct V_1 * V_2 = V_54 -> V_56 ;
int V_13 ;
T_1 V_33 ;
if ( ( V_13 = F_10 ( V_32 , & V_33 ) ) )
return V_13 ;
F_7 ( V_2 ) ;
if ( V_54 -> V_57 . V_58 . V_59 ) {
V_54 -> V_57 . V_58 . V_59 ( V_54 ) ;
if ( V_54 -> V_57 . V_60 ) V_54 -> V_57 . V_60 ( V_54 , 0 ) ;
}
F_1 ( V_2 , 0x0319 , 0x000A ) ;
F_1 ( V_2 , 0x031A , 0x0AAB ) ;
F_1 ( V_2 , 0x0309 , 0x0400 ) ;
F_1 ( V_2 , 0x030A , 0x0000 ) ;
if ( V_32 -> V_61 == 6000000 )
F_1 ( V_2 , 0x0311 , 0x0002 ) ;
else if ( V_32 -> V_61 == 7000000 )
F_1 ( V_2 , 0x0311 , 0x0001 ) ;
else
F_1 ( V_2 , 0x0311 , 0x0000 ) ;
if ( V_32 -> V_62 == V_63 )
F_1 ( V_2 , 0x0338 , 0x0000 ) ;
else
F_1 ( V_2 , 0x0338 , 0x0001 ) ;
F_1 ( V_2 , 0xc05 , V_33 ) ;
F_4 ( V_2 , 0x200 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_56 ;
const struct V_21 * V_22 = NULL ;
F_11 ( V_2 ) ;
if ( V_2 -> V_64 ) return 0 ;
V_2 -> V_64 = 1 ;
F_3 ( L_7 , V_15 ) ;
F_6 ( L_8 , V_65 ) ;
if ( V_2 -> V_9 -> V_66 ( V_54 , & V_22 , V_65 ) ) {
F_6 ( L_9 ) ;
return - V_67 ;
}
if ( F_5 ( V_2 , V_22 ) ) {
F_6 ( L_10 ) ;
F_14 ( V_22 ) ;
return - V_67 ;
}
F_14 ( V_22 ) ;
F_6 ( L_11 ) ;
F_1 ( V_2 , 0xc18 , 0x00d ) ;
F_7 ( V_2 ) ;
F_1 ( V_2 , 0x0301 , 0x0003 ) ;
F_1 ( V_2 , 0x0C13 , 0x0001 ) ;
F_1 ( V_2 , 0x0C14 , 0x0001 ) ;
F_1 ( V_2 , 0x0D00 , 0x010 ) ;
F_1 ( V_2 , 0x0D01 , 0x000 ) ;
return 0 ;
}
static int F_15 ( struct V_53 * V_54 , T_3 * V_68 )
{
struct V_1 * V_2 = V_54 -> V_56 ;
int V_69 ;
int signal ;
* V_68 = 0 ;
V_69 = F_4 ( V_2 , 0x0200 ) ;
if ( V_69 < 0 )
return - V_67 ;
signal = F_4 ( V_2 , 0x0303 ) ;
if ( signal < 0 )
return - V_67 ;
if ( signal > 0x0F )
* V_68 |= V_70 ;
if ( V_69 & 0x08 )
* V_68 |= V_71 ;
if ( V_69 & 0x04 )
* V_68 |= V_72 | V_73 | V_74 ;
return 0 ;
}
static int F_16 ( struct V_53 * V_54 , T_4 * V_75 )
{
struct V_1 * V_2 = V_54 -> V_56 ;
int V_17 ;
T_4 V_76 ;
* V_75 = 0 ;
V_17 = F_4 ( V_2 , 0xC08 ) ;
if ( V_17 < 0 )
return - V_67 ;
V_76 = V_17 & 0x3F ;
V_17 = F_4 ( V_2 , 0xC07 ) ;
if ( V_17 < 0 )
return - V_67 ;
V_76 = V_17 << 6 ;
if ( V_76 >= 0x3FFF0 )
V_76 = ~ 0 ;
* V_75 = V_76 ;
return 0 ;
}
static int F_17 ( struct V_53 * V_54 , T_1 * signal )
{
struct V_1 * V_2 = V_54 -> V_56 ;
int V_17 ;
T_1 V_76 ;
* signal = 0 ;
V_17 = F_4 ( V_2 , 0x306 ) ;
if ( V_17 < 0 )
return - V_67 ;
V_76 = V_17 << 8 ;
V_17 = F_4 ( V_2 , 0x303 ) ;
if ( V_17 < 0 )
return - V_67 ;
V_76 |= V_17 ;
if ( V_76 )
* signal = 0xFFFF - V_76 ;
return 0 ;
}
static int F_18 ( struct V_53 * V_54 , T_4 * V_77 )
{
struct V_1 * V_2 = V_54 -> V_56 ;
int V_17 ;
* V_77 = 0 ;
V_17 = F_4 ( V_2 , 0xC0C ) ;
if ( V_17 < 0 )
return - V_67 ;
if ( V_17 == 0xFFFF )
V_17 = ~ 0 ;
* V_77 = V_17 ;
return 0 ;
}
static int F_19 ( struct V_53 * V_54 )
{
struct V_31 * V_32 = & V_54 -> V_55 ;
struct V_1 * V_2 = V_54 -> V_56 ;
int V_13 = 0 ;
int V_78 = 0 ;
int V_79 = 0 ;
int V_80 = 0 ;
F_3 ( L_12 , V_15 , V_32 -> V_81 ) ;
for ( V_79 = 1 ; V_79 <= V_82 ; V_79 ++ ) {
V_13 = F_12 ( V_54 ) ;
if ( V_13 )
return V_13 ;
for ( V_80 = 0 ; V_80 < V_83 ; V_80 ++ ) {
V_78 = F_9 ( V_2 ) ;
if ( V_78 ) {
F_3 ( L_13 ,
V_15 , V_80 * 10 ) ;
break;
}
F_20 ( 10 ) ;
}
if ( V_78 )
break;
}
if ( ! V_78 ) {
F_6 ( L_14 , V_15 ) ;
return - V_67 ;
}
if ( V_84 ) {
if ( V_78 ) {
if ( V_79 > 1 ) {
F_6 ( L_15 , V_15 ) ;
F_6 ( L_16 , V_15 , V_79 - 1 ) ;
V_85 ++ ;
}
}
V_86 ++ ;
F_6 ( L_17 , V_15 , V_86 , V_85 ) ;
}
return 0 ;
}
static int F_21 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_56 ;
return F_1 ( V_2 , 0xC18 , 0x000 ) ;
}
static int F_22 ( struct V_53 * V_54 , struct V_87 * V_88 )
{
V_88 -> V_89 = 350 ;
V_88 -> V_90 = 0 ;
V_88 -> V_91 = 0 ;
return 0 ;
}
static int F_23 ( struct V_53 * V_54 , int V_92 )
{
struct V_1 * V_2 = V_54 -> V_56 ;
if ( V_92 ) {
return F_1 ( V_2 , 0x206 , 0x001 ) ;
} else {
return F_1 ( V_2 , 0x206 , 0x000 ) ;
}
}
static void F_24 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_56 ;
F_25 ( V_2 ) ;
}
struct V_53 * F_26 ( const struct V_93 * V_9 ,
struct V_94 * V_14 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_95 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_64 = 0 ;
if ( F_4 ( V_2 , 0x0200 ) < 0 ) goto error;
memcpy ( & V_2 -> V_96 . V_57 , & V_97 , sizeof( struct V_98 ) ) ;
V_2 -> V_96 . V_56 = V_2 ;
return & V_2 -> V_96 ;
error:
F_25 ( V_2 ) ;
return NULL ;
}
