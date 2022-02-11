static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [] = { V_3 , V_4 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 ,
. V_11 = 0 , . V_5 = V_5 , . V_12 = 2 } ;
int V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_1 ,
V_16 , V_2 -> V_17 , V_3 , V_4 ) ;
V_13 = F_3 ( V_2 -> V_9 -> V_14 , & V_7 , 1 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_2 ,
V_18 , V_2 -> V_17 , V_13 , V_3 , V_4 ) ;
return V_13 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_6 V_7 ;
T_1 V_5 [ V_21 + 1 ] ;
int V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_3 ,
V_16 , V_2 -> V_17 , V_20 -> V_12 ) ;
V_5 [ 0 ] = V_22 ;
memcpy ( & V_5 [ 1 ] , V_20 -> args , V_20 -> V_12 ) ;
V_7 . V_8 = V_2 -> V_9 -> V_10 ;
V_7 . V_11 = 0 ;
V_7 . V_12 = V_20 -> V_12 + 1 ;
V_7 . V_5 = V_5 ;
V_13 = F_3 ( V_2 -> V_9 -> V_14 , & V_7 , 1 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_4 ,
V_18 , V_2 -> V_17 , V_13 , V_20 -> V_12 ) ;
return V_13 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_13 ;
T_1 V_23 = 0 ;
struct V_6 V_7 [] = {
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 ,
. V_5 = & V_3 , . V_12 = 1 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_24 ,
. V_5 = & V_23 , . V_12 = 1 }
} ;
V_13 = F_3 ( V_2 -> V_9 -> V_14 , V_7 , 2 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_5 ,
V_18 , V_2 -> V_17 , V_13 , V_3 ) ;
return V_13 ;
}
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_6 ,
V_16 , V_2 -> V_17 , V_3 , V_23 ) ;
return V_23 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_5 , int V_12 )
{
int V_13 ;
struct V_6 V_7 [] = {
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 ,
. V_5 = & V_3 , . V_12 = 1 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_24 ,
. V_5 = V_5 , . V_12 = V_12 }
} ;
V_13 = F_3 ( V_2 -> V_9 -> V_14 , V_7 , 2 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_5 ,
V_18 , V_2 -> V_17 , V_13 , V_3 ) ;
return V_13 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
enum V_25 V_26 )
{
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_7 ,
V_16 , V_26 , V_2 -> V_17 ) ;
switch ( V_26 ) {
case V_27 :
V_2 -> V_28 . V_29 = 0x00 ;
break;
case V_30 :
V_2 -> V_28 . V_29 = 0x04 ;
break;
case V_31 :
V_2 -> V_28 . V_29 = 0x0C ;
break;
default:
return - V_32 ;
}
V_2 -> V_28 . V_26 = V_26 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
enum V_33 V_34 , enum V_35 V_36 , enum V_37 V_38 )
{
int V_39 , V_13 = - V_32 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_8 ,
V_16 , V_36 , V_38 , V_2 -> V_17 ) ;
for ( V_39 = 0 ; V_39 < F_10 ( V_40 ) ; V_39 ++ ) {
if ( ( V_34 == V_40 [ V_39 ] . V_41 ) &&
( V_36 == V_40 [ V_39 ] . V_42 ) &&
( V_38 == V_40 [ V_39 ] . V_43 ) ) {
V_13 = V_39 ;
break;
}
}
return V_13 ;
}
static int F_11 ( struct V_1 * V_2 ,
enum V_33 V_44 ,
enum V_35 V_45 ,
enum V_37 V_43 )
{
int V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_9 ,
V_16 , V_45 , V_43 , V_2 -> V_17 ) ;
V_13 = F_9 ( V_2 , V_44 , V_45 , V_43 ) ;
if ( V_13 < 0 )
return V_13 ;
V_2 -> V_28 . V_43 = V_43 ;
V_2 -> V_28 . V_46 = V_40 [ V_13 ] . V_47 ;
V_2 -> V_28 . V_48 = V_40 [ V_13 ] . V_49 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_10 , V_16 ,
V_2 -> V_17 , V_2 -> V_28 . V_48 , V_2 -> V_28 . V_46 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_50 )
{
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_7 ,
V_16 , V_50 , V_2 -> V_17 ) ;
V_2 -> V_28 . V_51 = V_50 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_11 ,
V_16 , V_2 -> V_17 , V_50 ) ;
return 0 ;
}
static int F_13 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
const struct V_55 * V_56 ;
int V_13 = 0 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_12 ,
V_16 , V_2 -> V_17 , V_2 -> V_9 -> V_57 ) ;
if ( V_2 -> V_9 -> V_57 )
return 0 ;
if ( F_6 ( V_2 , 0xeb ) != 0xa ) {
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_13 ,
V_16 , V_58 ) ;
V_13 = F_14 ( & V_56 , V_58 ,
V_2 -> V_9 -> V_14 -> V_15 . V_59 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_14 , V_16 ) ;
if ( V_13 ) {
F_15 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_15
L_16 , V_16 ) ;
return V_13 ;
}
V_2 -> V_9 -> V_57 = 1 ;
V_13 = F_16 ( V_53 , V_56 ) ;
if ( V_13 )
F_15 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_17 , V_16 ) ;
F_17 ( V_56 ) ;
F_18 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_18 , V_16 ,
V_13 == 0 ? L_19 : L_20 ) ;
V_2 -> V_9 -> V_57 = 0 ;
}
return V_13 ;
}
static int F_19 ( struct V_52 * V_53 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_39 , V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_21 ,
V_16 , V_2 -> V_17 ) ;
V_13 = F_13 ( V_53 ) ;
if ( V_13 != 0 )
return V_13 ;
F_5 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_60 , 0x01 ) ;
V_39 = 0 ;
while ( F_6 ( V_2 , V_60 ) ) {
F_20 ( 20 ) ;
if ( V_39 ++ > 40 ) {
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_22 , V_16 ) ;
return - V_61 ;
}
}
return 0 ;
}
static int F_21 ( struct V_52 * V_53 , struct V_19 * V_20 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_13 ;
F_22 ( & V_2 -> V_9 -> V_62 ) ;
V_13 = F_19 ( V_53 , V_20 ) ;
F_23 ( & V_2 -> V_9 -> V_62 ) ;
return V_13 ;
}
static int F_16 ( struct V_52 * V_53 ,
const struct V_55 * V_56 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_19 V_20 ;
int V_39 , V_13 ;
unsigned char V_63 [ 4 ] ;
struct V_6 V_7 ;
T_1 * V_5 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_23 ,
V_16 , V_2 -> V_17 , V_56 -> V_64 , V_56 -> V_4 [ 0 ] , V_56 -> V_4 [ 1 ] ,
V_56 -> V_4 [ V_56 -> V_64 - 2 ] , V_56 -> V_4 [ V_56 -> V_64 - 1 ] ) ;
F_1 ( V_2 , 0xea , 0x00 ) ;
F_1 ( V_2 , 0xea , 0x01 ) ;
F_1 ( V_2 , 0xea , 0x00 ) ;
F_1 ( V_2 , 0xce , 0x92 ) ;
F_1 ( V_2 , 0xfb , 0x00 ) ;
F_1 ( V_2 , 0xfc , 0x00 ) ;
F_1 ( V_2 , 0xc3 , 0x04 ) ;
F_1 ( V_2 , 0xc4 , 0x04 ) ;
F_1 ( V_2 , 0xce , 0x00 ) ;
F_1 ( V_2 , 0xcf , 0x00 ) ;
F_1 ( V_2 , 0xea , 0x00 ) ;
F_1 ( V_2 , 0xeb , 0x0c ) ;
F_1 ( V_2 , 0xec , 0x06 ) ;
F_1 ( V_2 , 0xed , 0x05 ) ;
F_1 ( V_2 , 0xee , 0x03 ) ;
F_1 ( V_2 , 0xef , 0x05 ) ;
F_1 ( V_2 , 0xf3 , 0x03 ) ;
F_1 ( V_2 , 0xf4 , 0x44 ) ;
F_1 ( V_2 , V_65 , 0x04 ) ;
F_1 ( V_2 , V_66 , 0x02 ) ;
F_1 ( V_2 , V_67 , 0x04 ) ;
F_1 ( V_2 , V_68 , 0x02 ) ;
F_1 ( V_2 , 0xf2 , 0x04 ) ;
F_1 ( V_2 , 0xe8 , 0x02 ) ;
F_1 ( V_2 , 0xea , 0x01 ) ;
F_1 ( V_2 , 0xc8 , 0x00 ) ;
F_1 ( V_2 , 0xc9 , 0x00 ) ;
F_1 ( V_2 , 0xca , 0x00 ) ;
F_1 ( V_2 , 0xcb , 0x00 ) ;
F_1 ( V_2 , 0xcc , 0x00 ) ;
F_1 ( V_2 , 0xcd , 0x00 ) ;
F_1 ( V_2 , 0xe4 , 0x03 ) ;
F_1 ( V_2 , 0xeb , 0x0a ) ;
F_1 ( V_2 , 0xfb , 0x00 ) ;
F_1 ( V_2 , 0xe0 , 0x76 ) ;
F_1 ( V_2 , 0xf7 , 0x81 ) ;
F_1 ( V_2 , 0xf8 , 0x00 ) ;
F_1 ( V_2 , 0xf9 , 0x00 ) ;
V_5 = F_24 ( V_56 -> V_64 + 1 , V_69 ) ;
if ( V_5 == NULL ) {
V_2 -> V_9 -> V_57 = 0 ;
return - V_70 ;
}
V_5 [ 0 ] = 0xfa ;
memcpy ( & V_5 [ 1 ] , V_56 -> V_4 , V_56 -> V_64 ) ;
V_7 . V_8 = V_2 -> V_9 -> V_10 ;
V_7 . V_11 = 0 ;
V_7 . V_12 = V_56 -> V_64 + 1 ;
V_7 . V_5 = V_5 ;
V_13 = F_3 ( V_2 -> V_9 -> V_14 , & V_7 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
F_25 ( V_5 ) ;
F_1 ( V_2 , 0xf7 , 0x0c ) ;
F_1 ( V_2 , 0xe0 , 0x00 ) ;
V_20 . args [ 0 ] = V_71 ;
V_20 . args [ 1 ] = 0x00 ;
V_20 . args [ 2 ] = 0x01 ;
V_20 . args [ 3 ] = 0x00 ;
V_20 . V_12 = 4 ;
V_13 = F_19 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
V_20 . args [ 0 ] = V_72 ;
V_20 . args [ 1 ] = 0x06 ;
V_20 . args [ 2 ] = 0x2b ;
V_20 . args [ 3 ] = 0xd8 ;
V_20 . args [ 4 ] = 0xa5 ;
V_20 . args [ 5 ] = 0xee ;
V_20 . args [ 6 ] = 0x03 ;
V_20 . args [ 7 ] = 0x9d ;
V_20 . args [ 8 ] = 0xfc ;
V_20 . args [ 9 ] = 0x06 ;
V_20 . args [ 10 ] = 0x02 ;
V_20 . args [ 11 ] = 0x9d ;
V_20 . args [ 12 ] = 0xfc ;
V_20 . V_12 = 13 ;
V_13 = F_19 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
V_20 . args [ 0 ] = V_73 ;
V_20 . args [ 1 ] = 0x00 ;
V_20 . args [ 2 ] = 0x01 ;
V_20 . args [ 3 ] = 0x00 ;
V_20 . args [ 4 ] = 0x00 ;
V_20 . args [ 5 ] = 0x01 ;
V_20 . args [ 6 ] = 0x01 ;
V_20 . args [ 7 ] = 0x01 ;
V_20 . args [ 8 ] = 0x00 ;
V_20 . args [ 9 ] = 0x05 ;
V_20 . args [ 10 ] = 0x02 ;
V_20 . args [ 11 ] = 0x02 ;
V_20 . args [ 12 ] = 0x00 ;
V_20 . V_12 = 13 ;
V_13 = F_19 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
V_20 . args [ 0 ] = V_74 ;
V_20 . args [ 1 ] = 0x00 ;
V_20 . args [ 2 ] = 0x00 ;
V_20 . args [ 3 ] = 0x00 ;
V_20 . args [ 4 ] = 0x01 ;
V_20 . args [ 5 ] = 0x00 ;
V_20 . V_12 = 6 ;
V_13 = F_19 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
for ( V_39 = 0 ; V_39 < 2 ; V_39 ++ ) {
V_20 . args [ 0 ] = V_75 ;
V_20 . args [ 1 ] = ( T_1 ) V_39 ;
V_20 . args [ 2 ] = 0x00 ;
V_20 . args [ 3 ] = 0x05 ;
V_20 . args [ 4 ] = 0x00 ;
V_20 . args [ 5 ] = 0x00 ;
V_20 . args [ 6 ] = 0x55 ;
V_20 . args [ 7 ] = 0x00 ;
V_20 . V_12 = 8 ;
V_13 = F_19 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
}
F_1 ( V_2 , 0xce , 0xc0 ) ;
F_1 ( V_2 , 0xcf , 0x00 ) ;
F_1 ( V_2 , 0xe5 , 0x04 ) ;
V_20 . args [ 0 ] = V_76 ;
V_20 . V_12 = 2 ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_20 . args [ 1 ] = V_39 ;
V_13 = F_19 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
V_63 [ V_39 ] = F_6 ( V_2 , 0x33 ) ;
}
F_18 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_24 , V_16 ,
V_63 [ 0 ] , V_63 [ 1 ] , V_63 [ 2 ] , V_63 [ 3 ] ) ;
return 0 ;
error:
V_2 -> V_9 -> V_57 = 0 ;
F_15 ( & V_2 -> V_9 -> V_14 -> V_15 , L_25 , V_16 ) ;
return V_13 ;
}
static int F_26 ( struct V_52 * V_53 , enum V_77 * V_78 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_79 ;
V_79 = F_6 ( V_2 ,
( V_2 -> V_17 == 0 ) ? V_80 :
V_81 ) &
V_82 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_26 ,
V_16 , V_2 -> V_17 , V_79 ) ;
* V_78 = 0 ;
if ( V_79 & V_83 )
* V_78 |= V_84 ;
if ( V_79 & V_85 )
* V_78 |= V_86 ;
if ( V_79 & V_87 )
* V_78 |= V_88 ;
if ( V_79 & V_89 )
* V_78 |= V_90 | V_91 ;
return 0 ;
}
static int F_27 ( struct V_52 * V_53 , T_2 * V_92 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_13 ;
T_1 V_5 [ 4 ] ;
T_1 V_93 = ( V_2 -> V_17 == 0 ) ?
V_94 :
V_95 ;
V_13 = F_7 ( V_2 , V_93 , V_5 , 4 ) ;
if ( V_13 != 0 )
return V_13 ;
* V_92 = ( V_5 [ 0 ] << 24 ) | ( V_5 [ 1 ] << 16 ) |
( V_5 [ 1 ] << 8 ) | V_5 [ 0 ] ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_27 ,
V_16 , V_2 -> V_17 , * V_92 ) ;
return 0 ;
}
static int F_28 ( struct V_52 * V_53 ,
T_3 * V_96 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_19 V_20 ;
int V_13 ;
T_3 V_97 ;
T_1 V_5 [ 2 ] ;
T_1 V_3 = ( V_2 -> V_17 == 0 ) ?
V_80 : V_81 ;
V_20 . args [ 0 ] = V_98 ;
V_20 . args [ 1 ] = ( T_1 ) V_2 -> V_17 ;
V_20 . V_12 = 2 ;
V_13 = F_21 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_7 ( V_2 , V_3 , V_5 , 2 ) ;
if ( V_13 != 0 )
return V_13 ;
V_97 = ( ( V_5 [ 0 ] & V_99 ) << 2 ) | V_5 [ 1 ] ;
* V_96 = - 100 * V_97 + 94324 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_28 ,
V_16 , V_2 -> V_17 , V_97 , * V_96 ) ;
return 0 ;
}
static int F_29 ( struct V_52 * V_53 , T_3 * V_100 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_13 ;
T_1 V_5 [ 2 ] ;
T_1 V_3 = ( V_2 -> V_17 == 0 ) ?
V_101 : V_102 ;
V_13 = F_7 ( V_2 , V_3 , V_5 , 2 ) ;
if ( V_13 != 0 )
return V_13 ;
* V_100 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_29 ,
V_16 , V_2 -> V_17 , * V_100 ) ;
return V_13 ;
}
static int F_30 ( struct V_52 * V_53 , T_2 * V_103 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
enum V_33 V_44 = V_53 -> V_104 . V_41 ;
int V_13 ;
T_1 V_5 [ 2 ] ;
T_1 V_3 = ( V_2 -> V_17 == 0 ) ?
V_105 :
V_106 ;
switch ( V_44 ) {
case V_107 :
break;
case V_108 :
V_3 += ( V_109 - V_105 ) ;
break;
default:
return - V_32 ;
}
V_13 = F_7 ( V_2 , V_3 , V_5 , 2 ) ;
if ( V_13 != 0 )
return V_13 ;
* V_103 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_30 ,
V_16 , V_2 -> V_17 , * V_103 ) ;
return 0 ;
}
static void F_31 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
V_2 -> V_110 = V_2 -> V_28 ;
}
static int F_32 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_39 ;
T_1 V_47 , V_3 = ( V_2 -> V_17 == 0 ) ? V_111 :
V_112 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_31 ,
V_16 , V_2 -> V_17 , F_6 ( V_2 , V_3 ) ) ;
for ( V_39 = 0 ; V_39 < 10 ; V_39 ++ ) {
V_47 = F_6 ( V_2 , V_3 ) & 0x01 ;
if ( V_47 != 0 )
return 0 ;
F_20 ( 30 ) ;
}
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 , L_32 ,
V_18 , V_2 -> V_17 ) ;
return - V_113 ;
}
static int F_33 ( struct V_52 * V_53 ,
enum V_114 V_115 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_19 V_20 ;
int V_13 ;
T_1 V_3 = ( V_2 -> V_17 == 0 ) ? 0x10 : 0x20 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_33 ,
V_16 , V_2 -> V_17 ,
V_115 == V_116 ? L_34 :
V_115 == V_117 ? L_35 :
L_36 ) ;
V_20 . args [ 0 ] = V_118 ;
V_20 . args [ 2 ] = V_3 ;
V_20 . V_12 = 3 ;
if ( ( V_115 == V_116 ) ||
( V_115 == V_117 ) ) {
V_20 . args [ 1 ] = V_3 ;
V_13 = F_21 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_32 ( V_53 ) ;
if ( V_13 != 0 )
return V_13 ;
F_20 ( 100 ) ;
V_20 . args [ 0 ] = V_119 ;
V_20 . args [ 1 ] = V_2 -> V_17 ? 0 : 1 ;
V_20 . args [ 2 ] = ( V_115 == V_117 ? 0x01 : 0x00 ) ;
V_20 . V_12 = 3 ;
V_13 = F_21 ( V_53 , & V_20 ) ;
F_20 ( 20 ) ;
} else {
V_20 . args [ 1 ] = 0x00 ;
V_13 = F_21 ( V_53 , & V_20 ) ;
}
return V_13 ;
}
static int F_34 ( struct V_52 * V_53 ,
enum V_120 V_121 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_19 V_20 ;
int V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_7 ,
V_16 , V_2 -> V_17 , V_121 ) ;
if ( ( V_121 != V_122 ) && ( V_121 != V_123 ) ) {
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 , L_37 ,
V_18 , V_2 -> V_17 , V_121 ) ;
return - V_32 ;
}
V_13 = F_32 ( V_53 ) ;
if ( V_13 != 0 )
return V_13 ;
F_20 ( 20 ) ;
V_20 . args [ 0 ] = V_124 ;
V_20 . args [ 1 ] = ( V_2 -> V_17 ? 0 : 1 ) ;
V_20 . args [ 2 ] = 0x00 ;
V_20 . args [ 3 ] = 0x00 ;
V_20 . V_12 = 5 ;
switch ( V_121 ) {
case V_122 :
V_20 . args [ 4 ] = 0x01 ;
break;
case V_123 :
V_20 . args [ 4 ] = 0x00 ;
break;
}
F_20 ( 20 ) ;
return F_21 ( V_53 , & V_20 ) ;
}
static int F_35 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
V_2 -> V_125 . args [ 0 ] = V_126 ;
V_2 -> V_125 . args [ V_127 ] = V_2 -> V_17 ? 0 : 1 ;
V_2 -> V_125 . args [ V_128 ] = V_129 ;
V_2 -> V_125 . args [ V_130 ] = 0x02 ;
V_2 -> V_125 . args [ V_131 ] = 0x00 ;
V_2 -> V_125 . args [ V_132 ] = 0x00 ;
V_2 -> V_125 . args [ V_133 ] = 0x00 ;
V_2 -> V_125 . V_12 = 7 ;
return 0 ;
}
static int F_36 ( struct V_52 * V_53 ,
struct V_134 * V_34 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
int V_39 , V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_38 ,
V_16 , V_2 -> V_17 ) ;
for ( V_39 = 0 ; V_39 < V_34 -> V_135 ; V_39 ++ )
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_39 , V_34 -> V_7 [ V_39 ] ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_40 ) ;
if ( V_34 -> V_135 > sizeof( V_34 -> V_7 ) )
return - V_32 ;
for ( V_39 = 0 ; V_39 < V_34 -> V_135 ; V_39 ++ )
V_2 -> V_125 . args [ V_136 + V_39 ] = V_34 -> V_7 [ V_39 ] ;
V_2 -> V_125 . args [ V_133 ] = V_34 -> V_135 ;
V_2 -> V_125 . V_12 = V_136 +
V_2 -> V_125 . args [ V_133 ] ;
if ( V_34 -> V_135 >= 4 && V_34 -> V_7 [ 2 ] == 0x38 )
V_2 -> V_125 . args [ V_128 ] =
( ( V_34 -> V_7 [ 3 ] & 4 ) >> 2 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_41 ,
V_16 , V_2 -> V_17 ,
V_2 -> V_125 . args [ V_128 ] ) ;
V_13 = F_32 ( V_53 ) ;
if ( V_13 != 0 )
return V_13 ;
F_20 ( 100 ) ;
V_13 = F_21 ( V_53 , & V_2 -> V_125 ) ;
if ( V_13 != 0 )
return V_13 ;
F_20 ( ( V_2 -> V_125 . args [ V_133 ] << 4 ) + 60 ) ;
return 0 ;
}
static int F_37 ( struct V_52 * V_53 ,
enum V_137 V_138 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_42 ,
V_16 , V_138 , V_2 -> V_17 ) ;
if ( V_138 == V_139 )
V_2 -> V_125 . args [ V_128 ] =
V_129 ;
else if ( V_138 == V_140 )
V_2 -> V_125 . args [ V_128 ] =
V_141 ;
else
return - V_32 ;
return 0 ;
}
static int F_38 ( struct V_142 * * V_9 ,
struct V_143 * V_14 , T_1 V_144 )
{
int V_13 ;
F_22 ( & V_145 ) ;
V_13 = F_39 ( struct V_142 , ( * V_9 ) ,
V_146 , V_14 , V_144 , L_43 ) ;
F_23 ( & V_145 ) ;
return V_13 ;
}
static void F_40 ( struct V_142 * V_9 )
{
F_22 ( & V_145 ) ;
if ( V_9 != NULL )
F_41 ( V_9 ) ;
F_23 ( & V_145 ) ;
}
static void F_42 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_44 ,
V_16 , V_2 -> V_17 ) ;
F_40 ( V_2 -> V_9 ) ;
F_25 ( V_2 ) ;
}
struct V_52 * F_43 ( const struct V_147 * V_148 ,
struct V_143 * V_14 )
{
struct V_1 * V_2 = NULL ;
struct V_142 * V_9 = NULL ;
int V_17 = 0 ;
V_17 = F_38 ( & V_9 , V_14 , V_148 -> V_10 ) ;
switch ( V_17 ) {
case 0 :
F_15 ( & V_14 -> V_15 ,
L_45 ,
V_18 , V_17 ) ;
goto V_149;
break;
case 1 :
V_9 -> V_14 = V_14 ;
V_9 -> V_10 = V_148 -> V_10 ;
F_44 ( & V_9 -> V_62 ) ;
break;
default:
break;
}
V_2 = F_45 ( sizeof( struct V_1 ) , V_69 ) ;
if ( V_2 == NULL )
goto V_150;
V_2 -> V_17 = V_17 - 1 ;
V_2 -> V_9 = V_9 ;
F_18 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_46 ,
V_18 , V_2 -> V_17 ) ;
memcpy ( & V_2 -> V_151 . V_152 , & V_153 ,
sizeof( struct V_154 ) ) ;
V_2 -> V_151 . V_54 = V_2 ;
return & V_2 -> V_151 ;
V_150:
F_40 ( V_9 ) ;
V_149:
return NULL ;
}
static int F_46 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_19 V_20 ;
int V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_21 ,
V_16 , V_2 -> V_17 ) ;
F_22 ( & V_2 -> V_9 -> V_62 ) ;
V_20 . args [ 0 ] = V_155 ;
V_20 . args [ 1 ] = ( V_2 -> V_17 ? 1 : 0 ) ;
V_20 . args [ 2 ] = 0 ;
V_20 . V_12 = 3 ;
V_13 = F_19 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
goto exit;
V_13 = F_35 ( V_53 ) ;
if ( V_13 != 0 )
goto exit;
V_20 . args [ 0 ] = V_156 ;
V_20 . args [ 1 ] = ( V_2 -> V_17 ? 1 : 0 ) ;
V_20 . args [ 2 ] = 0x10 ;
V_20 . args [ 3 ] = 0x10 ;
V_20 . V_12 = 4 ;
V_13 = F_19 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
goto exit;
V_20 . args [ 0 ] = V_157 ;
V_20 . args [ 1 ] = ( V_2 -> V_17 ? 1 : 0 ) ;
V_20 . args [ 2 ] = V_158 ;
V_20 . V_12 = 3 ;
V_13 = F_19 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
goto exit;
V_20 . args [ 0 ] = V_159 ;
V_20 . args [ 1 ] = 0x30 ;
V_20 . args [ 2 ] = 0x30 ;
V_20 . V_12 = 3 ;
V_13 = F_19 ( V_53 , & V_20 ) ;
exit:
F_23 ( & V_2 -> V_9 -> V_62 ) ;
return V_13 ;
}
static int F_47 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_19 V_20 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_21 ,
V_16 , V_2 -> V_17 ) ;
V_20 . args [ 0 ] = V_155 ;
V_20 . args [ 1 ] = ( V_2 -> V_17 ? 1 : 0 ) ;
V_20 . args [ 2 ] = 1 ;
V_20 . V_12 = 3 ;
return F_21 ( V_53 , & V_20 ) ;
}
static int F_48 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_160 * V_161 = & V_53 -> V_104 ;
struct V_19 V_20 ;
enum V_77 V_162 ;
int V_39 , V_78 , V_13 , V_163 = 1 ;
T_1 V_164 , V_165 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_21 ,
V_16 , V_2 -> V_17 ) ;
switch ( V_161 -> V_41 ) {
case V_107 :
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_47 ,
V_16 , V_2 -> V_17 ) ;
if ( V_161 -> V_42 != V_166 ) {
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_48 ,
V_16 , V_2 -> V_17 , V_161 -> V_42 ) ;
return - V_32 ;
}
V_2 -> V_28 . V_167 = V_168 ;
V_2 -> V_28 . V_169 = V_170 ;
break;
case V_108 :
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_49 ,
V_16 , V_2 -> V_17 ) ;
if ( V_161 -> V_42 != V_171 && V_161 -> V_42 != V_166 ) {
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_48 ,
V_16 , V_2 -> V_17 , V_161 -> V_42 ) ;
return - V_172 ;
}
switch ( V_161 -> V_173 ) {
case V_174 :
V_2 -> V_28 . V_167 = V_175 ;
break;
case V_176 :
V_2 -> V_28 . V_167 = V_168 ;
break;
case V_177 :
V_2 -> V_28 . V_167 = V_178 ;
break;
default:
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_50 ,
V_16 , V_2 -> V_17 , V_161 -> V_173 ) ;
return - V_172 ;
}
switch ( V_161 -> V_179 ) {
case V_180 :
V_2 -> V_28 . V_169 = V_181 ;
break;
case V_182 :
V_2 -> V_28 . V_169 = V_183 ;
break;
case V_184 :
V_2 -> V_28 . V_169 = V_170 ;
break;
case V_185 :
V_2 -> V_28 . V_169 = V_170 ;
V_163 = 3 ;
break;
default:
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_51 ,
V_18 , V_2 -> V_17 , V_161 -> V_179 ) ;
return - V_172 ;
}
break;
default:
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_52 ,
V_18 , V_2 -> V_17 , V_161 -> V_41 ) ;
return - V_32 ;
}
V_2 -> V_28 . V_44 = V_161 -> V_41 ;
V_2 -> V_28 . V_42 = V_161 -> V_42 ;
V_2 -> V_28 . V_186 = V_161 -> V_186 ;
V_2 -> V_28 . V_173 = V_161 -> V_173 ;
V_2 -> V_28 . V_179 = V_161 -> V_179 ;
V_13 = F_8 ( V_2 , V_161 -> V_26 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_11 ( V_2 ,
V_161 -> V_41 , V_161 -> V_42 , V_161 -> V_187 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_12 ( V_2 , V_161 -> V_51 ) ;
if ( V_13 != 0 )
return V_13 ;
F_31 ( V_53 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_53 , V_16 , V_2 -> V_110 . V_44 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_54 , V_16 , V_2 -> V_110 . V_42 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_55 , V_16 , V_2 -> V_110 . V_186 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_56 , V_16 ,
V_2 -> V_110 . V_173 , V_2 -> V_110 . V_167 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_57 , V_16 , V_163 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_58 , V_16 ,
V_2 -> V_110 . V_179 , V_2 -> V_110 . V_169 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_59 , V_16 , V_2 -> V_110 . V_51 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_60 , V_16 ,
V_2 -> V_110 . V_43 , V_2 -> V_110 . V_48 , V_2 -> V_110 . V_46 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_61 , V_16 ,
V_2 -> V_110 . V_26 , V_2 -> V_110 . V_29 ) ;
V_20 . args [ 0 ] = V_188 ;
V_20 . args [ 1 ] = V_2 -> V_17 ;
V_20 . args [ 2 ] = ( V_2 -> V_110 . V_186 & 0xff0000 ) >> 16 ;
V_20 . args [ 3 ] = ( V_2 -> V_110 . V_186 & 0x00ff00 ) >> 8 ;
V_20 . args [ 4 ] = ( V_2 -> V_110 . V_186 & 0x0000ff ) ;
V_20 . args [ 5 ] = ( ( V_2 -> V_110 . V_51 / 1000 ) & 0xff00 ) >> 8 ;
V_20 . args [ 6 ] = ( ( V_2 -> V_110 . V_51 / 1000 ) & 0x00ff ) ;
V_20 . args [ 7 ] = V_2 -> V_110 . V_29 ;
V_20 . args [ 8 ] = V_2 -> V_110 . V_46 | V_2 -> V_110 . V_167 ;
V_20 . args [ 9 ] = V_189 >> 8 ;
V_20 . args [ 10 ] = V_189 & 0xff ;
V_20 . args [ 11 ] = V_2 -> V_110 . V_169 ;
V_20 . args [ 12 ] = V_2 -> V_110 . V_48 ;
if ( V_2 -> V_110 . V_51 > 30000000 ) {
V_165 = 0x04 ;
V_164 = 0x02 ;
} else if ( V_2 -> V_110 . V_51 > 10000000 ) {
V_165 = 0x06 ;
V_164 = 0x03 ;
} else {
V_165 = 0x0a ;
V_164 = 0x05 ;
}
V_20 . args [ 13 ] = V_165 ;
V_20 . args [ 14 ] = V_164 ;
F_1 ( V_2 , ( V_2 -> V_17 == 0 ) ?
V_66 : V_68 , V_164 ) ;
F_1 ( V_2 , ( V_2 -> V_17 == 0 ) ?
V_65 : V_67 , V_165 ) ;
V_20 . args [ 15 ] = V_190 ;
V_20 . V_12 = 16 ;
do {
V_78 = F_6 ( V_2 , ( V_2 -> V_17 == 0 ) ?
V_80 : V_81 ) &
V_99 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_62 ,
V_16 , V_2 -> V_17 , V_78 ) ;
F_1 ( V_2 , ( V_2 -> V_17 == 0 ) ?
V_80 : V_81 , V_78 ) ;
V_13 = F_21 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
break;
for ( V_39 = 0 ; V_39 < 50 ; V_39 ++ ) {
F_26 ( V_53 , & V_162 ) ;
V_78 = V_162 & ( V_84 | V_90 ) ;
if ( V_78 == ( V_84 | V_90 ) ) {
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_63 ,
V_16 , V_2 -> V_17 ) ;
return 0 ;
}
F_20 ( 20 ) ;
}
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_64 ,
V_16 , V_2 -> V_17 ) ;
if ( V_2 -> V_110 . V_179 == 3 )
V_20 . args [ 11 ] -- ;
} while ( -- V_163 );
return - V_32 ;
}
static int F_49 ( struct V_52 * V_53 , bool V_191 ,
unsigned int V_192 , unsigned int * V_193 , enum V_77 * V_78 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_21 ,
V_16 , V_2 -> V_17 ) ;
* V_193 = V_194 / 5 ;
if ( V_191 ) {
int V_13 = F_48 ( V_53 ) ;
if ( V_13 )
return V_13 ;
}
return F_26 ( V_53 , V_78 ) ;
}
static int F_50 ( struct V_52 * V_53 )
{
return V_195 ;
}
static int F_51 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
struct V_160 * V_161 = & V_53 -> V_104 ;
struct V_19 V_20 ;
T_1 V_3 , V_196 , V_197 ;
int V_13 , V_198 ;
unsigned int V_199 ;
short V_200 , V_201 ;
T_1 V_5 [ 0x1f - 4 ] ;
V_20 . args [ 0 ] = V_202 ;
V_20 . args [ 1 ] = ( T_1 ) V_2 -> V_17 ;
V_20 . V_12 = 2 ;
V_13 = F_21 ( V_53 , & V_20 ) ;
if ( V_13 != 0 )
return V_13 ;
V_3 = ( V_2 -> V_17 == 0 ) ? V_203 : V_204 ;
V_13 = F_7 ( V_2 , V_3 , V_5 , 0x1f - 4 ) ;
if ( V_13 != 0 )
return V_13 ;
V_196 = V_5 [ 5 ] ;
V_197 = ( ( ( V_2 -> V_17 == 0 ) ? ~ V_196 : V_196 ) >> 6 ) & 1 ;
if ( V_197 == 0 )
V_161 -> V_26 = V_27 ;
else
V_161 -> V_26 = V_30 ;
V_198 = V_196 & 0x3f ;
if ( V_161 -> V_41 == V_108 ) {
if ( V_198 > 11 )
V_198 += 9 ;
else
V_198 += 7 ;
}
V_161 -> V_42 = V_40 [ V_198 ] . V_42 ;
V_161 -> V_187 = V_40 [ V_198 ] . V_43 ;
V_199 = ( V_5 [ 0 ] << 16 ) | ( V_5 [ 1 ] << 8 ) | V_5 [ 2 ] ;
V_201 = ( V_5 [ 8 ] << 8 ) | V_5 [ 9 ] ;
V_161 -> V_186 = V_199 + V_201 ;
V_200 = ( V_5 [ 10 ] << 8 ) | V_5 [ 11 ] ;
V_161 -> V_51 = - 1000 * V_200 + V_2 -> V_110 . V_51 ;
return 0 ;
}
