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
T_2 V_25 )
{
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_7 ,
V_16 , V_25 , V_2 -> V_17 ) ;
switch ( V_25 ) {
case V_26 :
V_2 -> V_27 . V_28 = 0x00 ;
break;
case V_29 :
V_2 -> V_27 . V_28 = 0x04 ;
break;
case V_30 :
V_2 -> V_27 . V_28 = 0x0C ;
break;
default:
return - V_31 ;
}
V_2 -> V_27 . V_25 = V_25 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_3 V_32 , T_4 V_33 , T_5 V_34 )
{
int V_35 , V_13 = - V_31 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_8 ,
V_16 , V_33 , V_34 , V_2 -> V_17 ) ;
for ( V_35 = 0 ; V_35 < F_10 ( V_36 ) ; V_35 ++ ) {
if ( ( V_32 == V_36 [ V_35 ] . V_37 ) &&
( V_33 == V_36 [ V_35 ] . V_38 ) &&
( V_34 == V_36 [ V_35 ] . V_39 ) ) {
V_13 = V_35 ;
break;
}
}
return V_13 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_3 V_40 , T_4 V_41 , T_5 V_39 )
{
int V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_9 ,
V_16 , V_41 , V_39 , V_2 -> V_17 ) ;
V_13 = F_9 ( V_2 , V_40 , V_41 , V_39 ) ;
if ( V_13 < 0 )
return V_13 ;
V_2 -> V_27 . V_39 = V_39 ;
V_2 -> V_27 . V_42 = V_36 [ V_13 ] . V_43 ;
V_2 -> V_27 . V_44 = V_36 [ V_13 ] . V_45 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_10 , V_16 ,
V_2 -> V_17 , V_2 -> V_27 . V_44 , V_2 -> V_27 . V_42 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_6 V_46 )
{
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_7 ,
V_16 , V_46 , V_2 -> V_17 ) ;
V_2 -> V_27 . V_47 = V_46 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_11 ,
V_16 , V_2 -> V_17 , V_46 ) ;
return 0 ;
}
static int F_13 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
const struct V_51 * V_52 ;
int V_13 = 0 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_12 ,
V_16 , V_2 -> V_17 , V_2 -> V_9 -> V_53 ) ;
if ( V_2 -> V_9 -> V_53 )
return 0 ;
if ( F_6 ( V_2 , 0xeb ) != 0xa ) {
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_13 ,
V_16 , V_54 ) ;
V_13 = F_14 ( & V_52 , V_54 ,
V_2 -> V_9 -> V_14 -> V_15 . V_55 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_14 , V_16 ) ;
if ( V_13 ) {
F_15 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_15
L_16 , V_16 ) ;
return V_13 ;
}
V_2 -> V_9 -> V_53 = 1 ;
V_13 = F_16 ( V_49 , V_52 ) ;
if ( V_13 )
F_15 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_17 , V_16 ) ;
F_17 ( V_52 ) ;
F_18 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_18 , V_16 ,
V_13 == 0 ? L_19 : L_20 ) ;
V_2 -> V_9 -> V_53 = 0 ;
}
return V_13 ;
}
static int F_19 ( struct V_48 * V_49 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
int V_35 , V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_21 ,
V_16 , V_2 -> V_17 ) ;
V_13 = F_13 ( V_49 ) ;
if ( V_13 != 0 )
return V_13 ;
F_5 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_56 , 0x01 ) ;
V_35 = 0 ;
while ( F_6 ( V_2 , V_56 ) ) {
F_20 ( 20 ) ;
if ( V_35 ++ > 40 ) {
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_22 , V_16 ) ;
return - V_57 ;
}
}
return 0 ;
}
static int F_21 ( struct V_48 * V_49 , struct V_19 * V_20 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
int V_13 ;
F_22 ( & V_2 -> V_9 -> V_58 ) ;
V_13 = F_19 ( V_49 , V_20 ) ;
F_23 ( & V_2 -> V_9 -> V_58 ) ;
return V_13 ;
}
static int F_16 ( struct V_48 * V_49 ,
const struct V_51 * V_52 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
struct V_19 V_20 ;
int V_35 , V_13 ;
unsigned char V_59 [ 4 ] ;
struct V_6 V_7 ;
T_1 * V_5 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_23 ,
V_16 , V_2 -> V_17 , V_52 -> V_60 , V_52 -> V_4 [ 0 ] , V_52 -> V_4 [ 1 ] ,
V_52 -> V_4 [ V_52 -> V_60 - 2 ] , V_52 -> V_4 [ V_52 -> V_60 - 1 ] ) ;
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
F_1 ( V_2 , V_61 , 0x04 ) ;
F_1 ( V_2 , V_62 , 0x02 ) ;
F_1 ( V_2 , V_63 , 0x04 ) ;
F_1 ( V_2 , V_64 , 0x02 ) ;
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
V_5 = F_24 ( V_52 -> V_60 + 1 , V_65 ) ;
if ( V_5 == NULL ) {
V_2 -> V_9 -> V_53 = 0 ;
return - V_66 ;
}
V_5 [ 0 ] = 0xfa ;
memcpy ( & V_5 [ 1 ] , V_52 -> V_4 , V_52 -> V_60 ) ;
V_7 . V_8 = V_2 -> V_9 -> V_10 ;
V_7 . V_11 = 0 ;
V_7 . V_12 = V_52 -> V_60 + 1 ;
V_7 . V_5 = V_5 ;
V_13 = F_3 ( V_2 -> V_9 -> V_14 , & V_7 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
F_25 ( V_5 ) ;
F_1 ( V_2 , 0xf7 , 0x0c ) ;
F_1 ( V_2 , 0xe0 , 0x00 ) ;
V_20 . args [ 0 ] = V_67 ;
V_20 . args [ 1 ] = 0x00 ;
V_20 . args [ 2 ] = 0x01 ;
V_20 . args [ 3 ] = 0x00 ;
V_20 . V_12 = 4 ;
V_13 = F_19 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
V_20 . args [ 0 ] = V_68 ;
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
V_13 = F_19 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
V_20 . args [ 0 ] = V_69 ;
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
V_13 = F_19 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
V_20 . args [ 0 ] = V_70 ;
V_20 . args [ 1 ] = 0x00 ;
V_20 . args [ 2 ] = 0x00 ;
V_20 . args [ 3 ] = 0x00 ;
V_20 . args [ 4 ] = 0x01 ;
V_20 . args [ 5 ] = 0x00 ;
V_20 . V_12 = 6 ;
V_13 = F_19 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
for ( V_35 = 0 ; V_35 < 2 ; V_35 ++ ) {
V_20 . args [ 0 ] = V_71 ;
V_20 . args [ 1 ] = ( T_1 ) V_35 ;
V_20 . args [ 2 ] = 0x00 ;
V_20 . args [ 3 ] = 0x05 ;
V_20 . args [ 4 ] = 0x00 ;
V_20 . args [ 5 ] = 0x00 ;
V_20 . args [ 6 ] = 0x55 ;
V_20 . args [ 7 ] = 0x00 ;
V_20 . V_12 = 8 ;
V_13 = F_19 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
}
F_1 ( V_2 , 0xce , 0xc0 ) ;
F_1 ( V_2 , 0xcf , 0x00 ) ;
F_1 ( V_2 , 0xe5 , 0x04 ) ;
V_20 . args [ 0 ] = V_72 ;
V_20 . V_12 = 2 ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
V_20 . args [ 1 ] = V_35 ;
V_13 = F_19 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
goto error;
V_59 [ V_35 ] = F_6 ( V_2 , 0x33 ) ;
}
F_18 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_24 , V_16 ,
V_59 [ 0 ] , V_59 [ 1 ] , V_59 [ 2 ] , V_59 [ 3 ] ) ;
return 0 ;
error:
V_2 -> V_9 -> V_53 = 0 ;
F_15 ( & V_2 -> V_9 -> V_14 -> V_15 , L_25 , V_16 ) ;
return V_13 ;
}
static int F_26 ( struct V_48 * V_49 , T_7 * V_73 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
int V_74 ;
V_74 = F_6 ( V_2 ,
( V_2 -> V_17 == 0 ) ? V_75 :
V_76 ) &
V_77 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_26 ,
V_16 , V_2 -> V_17 , V_74 ) ;
* V_73 = 0 ;
if ( V_74 & V_78 )
* V_73 |= V_79 ;
if ( V_74 & V_80 )
* V_73 |= V_81 ;
if ( V_74 & V_82 )
* V_73 |= V_83 ;
if ( V_74 & V_84 )
* V_73 |= V_85 | V_86 ;
return 0 ;
}
static int F_27 ( struct V_48 * V_49 , T_6 * V_87 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
int V_13 ;
T_1 V_5 [ 4 ] ;
T_1 V_88 = ( V_2 -> V_17 == 0 ) ?
V_89 :
V_90 ;
V_13 = F_7 ( V_2 , V_88 , V_5 , 4 ) ;
if ( V_13 != 0 )
return V_13 ;
* V_87 = ( V_5 [ 0 ] << 24 ) | ( V_5 [ 1 ] << 16 ) |
( V_5 [ 1 ] << 8 ) | V_5 [ 0 ] ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_27 ,
V_16 , V_2 -> V_17 , * V_87 ) ;
return 0 ;
}
static int F_28 ( struct V_48 * V_49 ,
T_8 * V_91 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
struct V_19 V_20 ;
int V_13 ;
T_8 V_92 ;
T_1 V_5 [ 2 ] ;
T_1 V_3 = ( V_2 -> V_17 == 0 ) ?
V_75 : V_76 ;
V_20 . args [ 0 ] = V_93 ;
V_20 . args [ 1 ] = ( T_1 ) V_2 -> V_17 ;
V_20 . V_12 = 2 ;
V_13 = F_21 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_7 ( V_2 , V_3 , V_5 , 2 ) ;
if ( V_13 != 0 )
return V_13 ;
V_92 = ( ( V_5 [ 0 ] & V_94 ) << 2 ) | V_5 [ 1 ] ;
* V_91 = - 100 * V_92 + 94324 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_28 ,
V_16 , V_2 -> V_17 , V_92 , * V_91 ) ;
return 0 ;
}
static int F_29 ( struct V_48 * V_49 , T_8 * V_95 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
int V_13 ;
T_1 V_5 [ 2 ] ;
T_1 V_3 = ( V_2 -> V_17 == 0 ) ?
V_96 : V_97 ;
V_13 = F_7 ( V_2 , V_3 , V_5 , 2 ) ;
if ( V_13 != 0 )
return V_13 ;
* V_95 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_29 ,
V_16 , V_2 -> V_17 , * V_95 ) ;
return V_13 ;
}
static int F_30 ( struct V_48 * V_49 , T_6 * V_98 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
T_3 V_40 = V_49 -> V_99 . V_37 ;
int V_13 ;
T_1 V_5 [ 2 ] ;
T_1 V_3 = ( V_2 -> V_17 == 0 ) ?
V_100 :
V_101 ;
switch ( V_40 ) {
case V_102 :
break;
case V_103 :
V_3 += ( V_104 - V_100 ) ;
break;
default:
return - V_31 ;
}
V_13 = F_7 ( V_2 , V_3 , V_5 , 2 ) ;
if ( V_13 != 0 )
return V_13 ;
* V_98 = ( V_5 [ 0 ] << 8 ) | V_5 [ 1 ] ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_30 ,
V_16 , V_2 -> V_17 , * V_98 ) ;
return 0 ;
}
static void F_31 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
V_2 -> V_105 = V_2 -> V_27 ;
}
static int F_32 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
int V_35 ;
T_1 V_43 , V_3 = ( V_2 -> V_17 == 0 ) ? V_106 :
V_107 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_31 ,
V_16 , V_2 -> V_17 , F_6 ( V_2 , V_3 ) ) ;
for ( V_35 = 0 ; V_35 < 10 ; V_35 ++ ) {
V_43 = F_6 ( V_2 , V_3 ) & 0x01 ;
if ( V_43 != 0 )
return 0 ;
F_20 ( 30 ) ;
}
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 , L_32 ,
V_18 , V_2 -> V_17 ) ;
return - V_108 ;
}
static int F_33 ( struct V_48 * V_49 ,
T_9 V_109 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
struct V_19 V_20 ;
int V_13 ;
T_1 V_3 = ( V_2 -> V_17 == 0 ) ? 0x10 : 0x20 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_33 ,
V_16 , V_2 -> V_17 ,
V_109 == V_110 ? L_34 :
V_109 == V_111 ? L_35 :
L_36 ) ;
V_20 . args [ 0 ] = V_112 ;
V_20 . args [ 2 ] = V_3 ;
V_20 . V_12 = 3 ;
if ( ( V_109 == V_110 ) ||
( V_109 == V_111 ) ) {
V_20 . args [ 1 ] = V_3 ;
V_13 = F_21 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_32 ( V_49 ) ;
if ( V_13 != 0 )
return V_13 ;
F_20 ( 100 ) ;
V_20 . args [ 0 ] = V_113 ;
V_20 . args [ 1 ] = V_2 -> V_17 ? 0 : 1 ;
V_20 . args [ 2 ] = ( V_109 == V_111 ? 0x01 : 0x00 ) ;
V_20 . V_12 = 3 ;
V_13 = F_21 ( V_49 , & V_20 ) ;
F_20 ( 20 ) ;
} else {
V_20 . args [ 1 ] = 0x00 ;
V_13 = F_21 ( V_49 , & V_20 ) ;
}
return V_13 ;
}
static int F_34 ( struct V_48 * V_49 ,
T_10 V_114 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
struct V_19 V_20 ;
int V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_7 ,
V_16 , V_2 -> V_17 , V_114 ) ;
if ( ( V_114 != V_115 ) && ( V_114 != V_116 ) ) {
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 , L_37 ,
V_18 , V_2 -> V_17 , V_114 ) ;
return - V_31 ;
}
V_13 = F_32 ( V_49 ) ;
if ( V_13 != 0 )
return V_13 ;
F_20 ( 20 ) ;
V_20 . args [ 0 ] = V_117 ;
V_20 . args [ 1 ] = ( V_2 -> V_17 ? 0 : 1 ) ;
V_20 . args [ 2 ] = 0x00 ;
V_20 . args [ 3 ] = 0x00 ;
V_20 . V_12 = 5 ;
switch ( V_114 ) {
case V_115 :
V_20 . args [ 4 ] = 0x01 ;
break;
case V_116 :
V_20 . args [ 4 ] = 0x00 ;
break;
}
F_20 ( 20 ) ;
return F_21 ( V_49 , & V_20 ) ;
}
static int F_35 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
V_2 -> V_118 . args [ 0 ] = V_119 ;
V_2 -> V_118 . args [ V_120 ] = V_2 -> V_17 ? 0 : 1 ;
V_2 -> V_118 . args [ V_121 ] = V_122 ;
V_2 -> V_118 . args [ V_123 ] = 0x02 ;
V_2 -> V_118 . args [ V_124 ] = 0x00 ;
V_2 -> V_118 . args [ V_125 ] = 0x00 ;
V_2 -> V_118 . args [ V_126 ] = 0x00 ;
V_2 -> V_118 . V_12 = 7 ;
return 0 ;
}
static int F_36 ( struct V_48 * V_49 ,
struct V_127 * V_32 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
int V_35 , V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_38 ,
V_16 , V_2 -> V_17 ) ;
for ( V_35 = 0 ; V_35 < V_32 -> V_128 ; V_35 ++ )
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_39 , V_32 -> V_7 [ V_35 ] ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_40 ) ;
if ( V_32 -> V_128 > 15 )
return - V_31 ;
for ( V_35 = 0 ; V_35 < V_32 -> V_128 ; V_35 ++ )
V_2 -> V_118 . args [ V_129 + V_35 ] = V_32 -> V_7 [ V_35 ] ;
V_2 -> V_118 . args [ V_126 ] = V_32 -> V_128 ;
V_2 -> V_118 . V_12 = V_129 +
V_2 -> V_118 . args [ V_126 ] ;
if ( V_32 -> V_128 >= 4 && V_32 -> V_7 [ 2 ] == 0x38 )
V_2 -> V_118 . args [ V_121 ] =
( ( V_32 -> V_7 [ 3 ] & 4 ) >> 2 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_41 ,
V_16 , V_2 -> V_17 ,
V_2 -> V_118 . args [ V_121 ] ) ;
V_13 = F_32 ( V_49 ) ;
if ( V_13 != 0 )
return V_13 ;
F_20 ( 100 ) ;
V_13 = F_21 ( V_49 , & V_2 -> V_118 ) ;
if ( V_13 != 0 )
return V_13 ;
F_20 ( ( V_2 -> V_118 . args [ V_126 ] << 4 ) + 60 ) ;
return 0 ;
}
static int F_37 ( struct V_48 * V_49 ,
T_11 V_130 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_42 ,
V_16 , V_130 , V_2 -> V_17 ) ;
if ( V_130 == V_131 )
V_2 -> V_118 . args [ V_121 ] =
V_122 ;
else if ( V_130 == V_132 )
V_2 -> V_118 . args [ V_121 ] =
V_133 ;
else
return - V_31 ;
return 0 ;
}
static int F_38 ( struct V_134 * * V_9 ,
struct V_135 * V_14 , T_1 V_136 )
{
int V_13 ;
F_22 ( & V_137 ) ;
V_13 = F_39 ( struct V_134 , ( * V_9 ) ,
V_138 , V_14 , V_136 , L_43 ) ;
F_23 ( & V_137 ) ;
return V_13 ;
}
static void F_40 ( struct V_134 * V_9 )
{
F_22 ( & V_137 ) ;
if ( V_9 != NULL )
F_41 ( V_9 ) ;
F_23 ( & V_137 ) ;
}
static void F_42 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_44 ,
V_16 , V_2 -> V_17 ) ;
F_40 ( V_2 -> V_9 ) ;
F_25 ( V_2 ) ;
}
struct V_48 * F_43 ( const struct V_139 * V_140 ,
struct V_135 * V_14 )
{
struct V_1 * V_2 = NULL ;
struct V_134 * V_9 = NULL ;
int V_17 = 0 ;
V_17 = F_38 ( & V_9 , V_14 , V_140 -> V_10 ) ;
switch ( V_17 ) {
case 0 :
F_15 ( & V_14 -> V_15 ,
L_45 ,
V_18 , V_17 ) ;
goto V_141;
break;
case 1 :
V_9 -> V_14 = V_14 ;
V_9 -> V_10 = V_140 -> V_10 ;
F_44 ( & V_9 -> V_58 ) ;
break;
default:
break;
}
V_2 = F_45 ( sizeof( struct V_1 ) , V_65 ) ;
if ( V_2 == NULL )
goto V_142;
V_2 -> V_17 = V_17 - 1 ;
V_2 -> V_9 = V_9 ;
F_18 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_46 ,
V_18 , V_2 -> V_17 ) ;
memcpy ( & V_2 -> V_143 . V_144 , & V_145 ,
sizeof( struct V_146 ) ) ;
V_2 -> V_143 . V_50 = V_2 ;
return & V_2 -> V_143 ;
V_142:
F_40 ( V_9 ) ;
V_141:
return NULL ;
}
static int F_46 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
struct V_19 V_20 ;
int V_13 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_21 ,
V_16 , V_2 -> V_17 ) ;
F_22 ( & V_2 -> V_9 -> V_58 ) ;
V_20 . args [ 0 ] = V_147 ;
V_20 . args [ 1 ] = ( V_2 -> V_17 ? 1 : 0 ) ;
V_20 . args [ 2 ] = 0 ;
V_20 . V_12 = 3 ;
V_13 = F_19 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
goto exit;
V_13 = F_35 ( V_49 ) ;
if ( V_13 != 0 )
goto exit;
V_20 . args [ 0 ] = V_148 ;
V_20 . args [ 1 ] = ( V_2 -> V_17 ? 1 : 0 ) ;
V_20 . args [ 2 ] = 0x10 ;
V_20 . args [ 3 ] = 0x10 ;
V_20 . V_12 = 4 ;
V_13 = F_19 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
goto exit;
V_20 . args [ 0 ] = V_149 ;
V_20 . args [ 1 ] = ( V_2 -> V_17 ? 1 : 0 ) ;
V_20 . args [ 2 ] = V_150 ;
V_20 . V_12 = 3 ;
V_13 = F_19 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
goto exit;
V_20 . args [ 0 ] = V_151 ;
V_20 . args [ 1 ] = 0x30 ;
V_20 . args [ 2 ] = 0x30 ;
V_20 . V_12 = 3 ;
V_13 = F_19 ( V_49 , & V_20 ) ;
exit:
F_23 ( & V_2 -> V_9 -> V_58 ) ;
return V_13 ;
}
static int F_47 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
struct V_19 V_20 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_21 ,
V_16 , V_2 -> V_17 ) ;
V_20 . args [ 0 ] = V_147 ;
V_20 . args [ 1 ] = ( V_2 -> V_17 ? 1 : 0 ) ;
V_20 . args [ 2 ] = 1 ;
V_20 . V_12 = 3 ;
return F_21 ( V_49 , & V_20 ) ;
}
static int F_48 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
struct V_152 * V_153 = & V_49 -> V_99 ;
struct V_19 V_20 ;
T_7 V_154 ;
int V_35 , V_73 , V_13 , V_155 = 1 ;
T_1 V_156 , V_157 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_21 ,
V_16 , V_2 -> V_17 ) ;
switch ( V_153 -> V_37 ) {
case V_102 :
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_47 ,
V_16 , V_2 -> V_17 ) ;
if ( V_153 -> V_38 != V_158 ) {
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_48 ,
V_16 , V_2 -> V_17 , V_153 -> V_38 ) ;
return - V_31 ;
}
V_2 -> V_27 . V_159 = V_160 ;
V_2 -> V_27 . V_161 = V_162 ;
break;
case V_103 :
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_49 ,
V_16 , V_2 -> V_17 ) ;
if ( V_153 -> V_38 != V_163 && V_153 -> V_38 != V_158 ) {
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_48 ,
V_16 , V_2 -> V_17 , V_153 -> V_38 ) ;
return - V_164 ;
}
switch ( V_153 -> V_165 ) {
case V_166 :
V_2 -> V_27 . V_159 = V_167 ;
break;
case V_168 :
V_2 -> V_27 . V_159 = V_160 ;
break;
case V_169 :
V_2 -> V_27 . V_159 = V_170 ;
break;
default:
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_50 ,
V_16 , V_2 -> V_17 , V_153 -> V_165 ) ;
return - V_164 ;
}
switch ( V_153 -> V_171 ) {
case V_172 :
V_2 -> V_27 . V_161 = V_173 ;
break;
case V_174 :
V_2 -> V_27 . V_161 = V_175 ;
break;
case V_176 :
V_2 -> V_27 . V_161 = V_162 ;
break;
case V_177 :
V_2 -> V_27 . V_161 = V_162 ;
V_155 = 3 ;
break;
default:
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_51 ,
V_18 , V_2 -> V_17 , V_153 -> V_171 ) ;
return - V_164 ;
}
break;
default:
F_4 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_52 ,
V_18 , V_2 -> V_17 , V_153 -> V_37 ) ;
return - V_31 ;
}
V_2 -> V_27 . V_40 = V_153 -> V_37 ;
V_2 -> V_27 . V_38 = V_153 -> V_38 ;
V_2 -> V_27 . V_178 = V_153 -> V_178 ;
V_2 -> V_27 . V_165 = V_153 -> V_165 ;
V_2 -> V_27 . V_171 = V_153 -> V_171 ;
V_13 = F_8 ( V_2 , V_153 -> V_25 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_11 ( V_2 ,
V_153 -> V_37 , V_153 -> V_38 , V_153 -> V_179 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_12 ( V_2 , V_153 -> V_47 ) ;
if ( V_13 != 0 )
return V_13 ;
F_31 ( V_49 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_53 , V_16 , V_2 -> V_105 . V_40 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_54 , V_16 , V_2 -> V_105 . V_38 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_55 , V_16 , V_2 -> V_105 . V_178 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_56 , V_16 ,
V_2 -> V_105 . V_165 , V_2 -> V_105 . V_159 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_57 , V_16 , V_155 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_58 , V_16 ,
V_2 -> V_105 . V_171 , V_2 -> V_105 . V_161 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_59 , V_16 , V_2 -> V_105 . V_47 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_60 , V_16 ,
V_2 -> V_105 . V_39 , V_2 -> V_105 . V_44 , V_2 -> V_105 . V_42 ) ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_61 , V_16 ,
V_2 -> V_105 . V_25 , V_2 -> V_105 . V_28 ) ;
V_20 . args [ 0 ] = V_180 ;
V_20 . args [ 1 ] = V_2 -> V_17 ;
V_20 . args [ 2 ] = ( V_2 -> V_105 . V_178 & 0xff0000 ) >> 16 ;
V_20 . args [ 3 ] = ( V_2 -> V_105 . V_178 & 0x00ff00 ) >> 8 ;
V_20 . args [ 4 ] = ( V_2 -> V_105 . V_178 & 0x0000ff ) ;
V_20 . args [ 5 ] = ( ( V_2 -> V_105 . V_47 / 1000 ) & 0xff00 ) >> 8 ;
V_20 . args [ 6 ] = ( ( V_2 -> V_105 . V_47 / 1000 ) & 0x00ff ) ;
V_20 . args [ 7 ] = V_2 -> V_105 . V_28 ;
V_20 . args [ 8 ] = V_2 -> V_105 . V_42 | V_2 -> V_105 . V_159 ;
V_20 . args [ 9 ] = V_181 >> 8 ;
V_20 . args [ 10 ] = V_181 & 0xff ;
V_20 . args [ 11 ] = V_2 -> V_105 . V_161 ;
V_20 . args [ 12 ] = V_2 -> V_105 . V_44 ;
if ( V_2 -> V_105 . V_47 > 30000000 ) {
V_157 = 0x04 ;
V_156 = 0x02 ;
} else if ( V_2 -> V_105 . V_47 > 10000000 ) {
V_157 = 0x06 ;
V_156 = 0x03 ;
} else {
V_157 = 0x0a ;
V_156 = 0x05 ;
}
V_20 . args [ 13 ] = V_157 ;
V_20 . args [ 14 ] = V_156 ;
F_1 ( V_2 , ( V_2 -> V_17 == 0 ) ?
V_62 : V_64 , V_156 ) ;
F_1 ( V_2 , ( V_2 -> V_17 == 0 ) ?
V_61 : V_63 , V_157 ) ;
V_20 . args [ 15 ] = V_182 ;
V_20 . V_12 = 16 ;
do {
V_73 = F_6 ( V_2 , ( V_2 -> V_17 == 0 ) ?
V_75 : V_76 ) &
V_94 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_62 ,
V_16 , V_2 -> V_17 , V_73 ) ;
F_1 ( V_2 , ( V_2 -> V_17 == 0 ) ?
V_75 : V_76 , V_73 ) ;
V_13 = F_21 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
break;
for ( V_35 = 0 ; V_35 < 50 ; V_35 ++ ) {
F_26 ( V_49 , & V_154 ) ;
V_73 = V_154 & ( V_79 | V_85 ) ;
if ( V_73 == ( V_79 | V_85 ) ) {
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 ,
L_63 ,
V_16 , V_2 -> V_17 ) ;
return 0 ;
}
F_20 ( 20 ) ;
}
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_64 ,
V_16 , V_2 -> V_17 ) ;
if ( V_2 -> V_105 . V_171 == 3 )
V_20 . args [ 11 ] -- ;
} while ( -- V_155 );
return - V_31 ;
}
static int F_49 ( struct V_48 * V_49 , bool V_183 ,
unsigned int V_184 , unsigned int * V_185 , T_7 * V_73 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
F_2 ( & V_2 -> V_9 -> V_14 -> V_15 , L_21 ,
V_16 , V_2 -> V_17 ) ;
* V_185 = V_186 / 5 ;
if ( V_183 ) {
int V_13 = F_48 ( V_49 ) ;
if ( V_13 )
return V_13 ;
}
return F_26 ( V_49 , V_73 ) ;
}
static int F_50 ( struct V_48 * V_49 )
{
return V_187 ;
}
static int F_51 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
struct V_152 * V_153 = & V_49 -> V_99 ;
struct V_19 V_20 ;
T_1 V_3 , V_188 , V_189 ;
int V_13 , V_190 ;
unsigned int V_191 ;
short V_192 , V_193 ;
T_1 V_5 [ 0x1f - 4 ] ;
V_20 . args [ 0 ] = V_194 ;
V_20 . args [ 1 ] = ( T_1 ) V_2 -> V_17 ;
V_20 . V_12 = 2 ;
V_13 = F_21 ( V_49 , & V_20 ) ;
if ( V_13 != 0 )
return V_13 ;
V_3 = ( V_2 -> V_17 == 0 ) ? V_195 : V_196 ;
V_13 = F_7 ( V_2 , V_3 , V_5 , 0x1f - 4 ) ;
if ( V_13 != 0 )
return V_13 ;
V_188 = V_5 [ 5 ] ;
V_189 = ( ( ( V_2 -> V_17 == 0 ) ? ~ V_188 : V_188 ) >> 6 ) & 1 ;
if ( V_189 == 0 )
V_153 -> V_25 = V_26 ;
else
V_153 -> V_25 = V_29 ;
V_190 = V_188 & 0x3f ;
if ( V_153 -> V_37 == V_103 ) {
if ( V_190 > 11 )
V_190 += 9 ;
else
V_190 += 7 ;
}
V_153 -> V_38 = V_36 [ V_190 ] . V_38 ;
V_153 -> V_179 = V_36 [ V_190 ] . V_39 ;
V_191 = ( V_5 [ 0 ] << 16 ) | ( V_5 [ 1 ] << 8 ) | V_5 [ 2 ] ;
V_193 = ( V_5 [ 8 ] << 8 ) | V_5 [ 9 ] ;
V_153 -> V_178 = V_191 + V_193 ;
V_192 = ( V_5 [ 10 ] << 8 ) | V_5 [ 11 ] ;
V_153 -> V_47 = - 1000 * V_192 + V_2 -> V_105 . V_47 ;
return 0 ;
}
