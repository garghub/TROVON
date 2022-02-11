static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
T_1 V_6 [ 2 ] = { V_4 , V_5 } ;
struct V_7 V_8 = { . V_9 = V_3 , . V_10 = 0 , . V_11 = V_6 , . V_12 = 2 } ;
if ( F_2 ( V_2 , & V_8 , 1 ) != 1 ) {
F_3 ( & V_2 -> V_13 ,
L_1 ,
V_4 , V_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_5 , T_2 V_12 )
{
struct V_7 V_8 = { . V_9 = V_3 , . V_10 = 0 , . V_11 = V_5 , . V_12 = V_12 } ;
if ( F_2 ( V_2 , & V_8 , 1 ) != 1 ) {
F_3 ( & V_2 -> V_13 , L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 * V_14 )
{
struct V_7 V_15 [ 2 ] = { { . V_9 = V_3 , . V_10 = 0 ,
. V_11 = & V_4 , . V_12 = 1 } ,
{ . V_9 = V_3 , . V_10 = V_16 ,
. V_11 = V_14 , . V_12 = 1 } } ;
if ( F_2 ( V_2 , V_15 , 2 ) != 2 ) {
F_3 ( & V_2 -> V_13 , L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 * V_5 , T_2 V_17 )
{
struct V_7 V_15 [ 2 ] = { { . V_9 = V_3 , . V_10 = 0 ,
. V_11 = & V_4 , . V_12 = 1 } ,
{ . V_9 = V_3 , . V_10 = V_16 ,
. V_11 = V_5 , . V_12 = V_17 } } ;
if ( F_2 ( V_2 , V_15 , 2 ) != 2 ) {
F_3 ( & V_2 -> V_13 , L_4 ) ;
return - 1 ;
}
return 0 ;
}
static int F_7 ( struct V_18 * V_19 , T_1 V_3 , T_1 * V_5 , T_2 V_17 )
{
int V_20 = 0 ;
if ( V_19 -> V_21 != V_3 )
V_20 = F_1 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , 0 , V_3 ) ;
if ( ! V_20 ) {
V_19 -> V_21 = V_3 ;
while ( V_17 ) {
int V_12 = V_17 ;
if ( V_19 -> V_23 . V_24 && ( V_12 > V_19 -> V_23 . V_24 ) )
V_12 = V_19 -> V_23 . V_24 ;
V_20 = F_6 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , 1 , V_5 , V_12 ) ;
if ( V_20 )
return V_20 ;
V_5 += V_12 ;
V_17 -= V_12 ;
}
}
return V_20 ;
}
static int F_8 ( struct V_18 * V_19 , T_1 V_4 , T_1 * V_14 )
{
return F_7 ( V_19 , V_4 , V_14 , 1 ) ;
}
static int F_9 ( struct V_18 * V_19 , T_2 V_25 , T_1 * V_5 , T_1 V_17 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_25 & 0xff , V_25 >> 8 } ;
V_20 = F_4 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , V_9 , 3 ) ;
if ( ! V_20 )
V_20 = F_6 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , 3 , V_5 , V_17 ) ;
return V_20 ;
}
static int F_10 ( struct V_18 * V_19 , T_2 V_25 , T_1 * V_5 , T_1 V_17 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_25 & 0xff , V_25 >> 8 } ;
V_20 = F_4 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , V_9 , 3 ) ;
if ( ! V_20 ) {
T_1 V_11 [ 256 ] = { 3 } ;
memcpy ( V_11 + 1 , V_5 , V_17 ) ;
V_20 = F_4 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , V_11 , V_17 + 1 ) ;
}
return V_20 ;
}
static int F_11 ( struct V_18 * V_19 , T_2 V_25 , T_1 * V_14 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_25 & 0xff , V_25 >> 8 } ;
V_20 = F_4 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , V_9 , 3 ) ;
if ( ! V_20 )
V_20 = F_6 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , 3 , V_14 , 1 ) ;
return V_20 ;
}
static int F_12 ( struct V_18 * V_19 , T_2 V_25 , T_1 V_14 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_25 & 0xff , V_25 >> 8 } ;
T_1 V_11 [ 2 ] = { 3 , V_14 } ;
V_20 = F_4 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , V_9 , 3 ) ;
if ( ! V_20 )
V_20 = F_4 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , V_11 , 2 ) ;
return V_20 ;
}
static int F_13 ( struct V_18 * V_19 , T_1 V_4 , T_1 V_14 , T_1 V_26 )
{
int V_20 = 0 ;
if ( V_19 -> V_21 != V_4 )
V_20 = F_1 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , 0 , V_4 ) ;
if ( ! V_20 && V_4 >= 6 && V_4 <= 8 && V_26 != 0xff )
V_20 = F_5 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , 1 , & V_19 -> V_27 [ V_4 ] ) ;
V_19 -> V_21 = V_4 ;
V_19 -> V_27 [ V_4 ] = ( V_19 -> V_27 [ V_4 ] & ( ~ V_26 ) ) | V_14 ;
if ( ! V_20 )
V_20 = F_1 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , 1 , V_19 -> V_27 [ V_4 ] ) ;
if ( V_4 == 0x20 )
V_19 -> V_27 [ V_4 ] &= 0x7f ;
return V_20 ;
}
static int F_14 ( struct V_18 * V_19 , T_1 V_4 , T_1 V_14 )
{
return F_13 ( V_19 , V_4 , V_14 , 0xff ) ;
}
static int F_15 ( struct V_18 * V_19 , T_1 V_3 , T_1 * V_5 , T_2 V_17 )
{
int V_20 = 0 ;
T_1 * V_11 = V_19 -> V_28 ;
if ( V_19 -> V_21 != V_3 )
V_20 = F_1 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , 0 , V_3 ) ;
if ( V_20 )
return V_20 ;
V_19 -> V_21 = V_3 ;
V_11 [ 0 ] = 1 ;
while ( V_17 ) {
int V_12 = V_17 ;
if ( V_19 -> V_23 . V_24 && ( V_12 + 1 > V_19 -> V_23 . V_24 ) )
V_12 = V_19 -> V_23 . V_24 - 1 ;
memcpy ( V_11 + 1 , V_5 , V_12 ) ;
V_20 = F_4 ( V_19 -> V_22 , V_19 -> V_23 . V_3 , V_11 , V_12 + 1 ) ;
if ( V_20 )
return V_20 ;
V_17 -= V_12 ;
V_5 += V_12 ;
}
return V_20 ;
}
static void F_16 ( struct V_18 * V_19 , int V_29 )
{
if ( V_29 == V_19 -> V_29 )
return;
switch ( V_29 ) {
case 0x00 :
F_13 ( V_19 , 0x06 , 0x00 , 0x07 ) ;
break;
case 0x01 :
F_13 ( V_19 , 0x06 , 0x02 , 0x07 ) ;
break;
default:
break;
}
V_19 -> V_29 = V_29 ;
}
static void F_17 ( struct V_18 * V_19 , int V_29 )
{
T_1 V_30 ;
if ( V_29 == V_19 -> V_31 )
return;
switch ( V_29 ) {
case 0x00 :
F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ;
break;
case 0x01 :
if ( ! V_19 -> V_32 . V_33 )
return;
V_19 -> V_34 = 0 ;
F_18 ( & V_19 -> V_22 -> V_13 , L_5 ) ;
F_14 ( V_19 , 0x0d , 0x00 ) ;
F_14 ( V_19 , 0x0e , 0x01 ) ;
F_13 ( V_19 , 0x08 , 0x40 , 0x40 ) ;
F_8 ( V_19 , 0x12 , & V_30 ) ;
F_13 ( V_19 , 0x08 , 0x80 , 0x80 ) ;
break;
default:
break;
}
V_19 -> V_31 = V_29 ;
}
static int F_19 ( struct V_18 * V_19 )
{
int V_20 ;
F_20 ( & V_19 -> V_35 ) ;
V_19 -> V_29 = - 1 ;
do {
V_20 = F_14 ( V_19 , 0x00 , 0x00 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x01 , 0x00 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x02 , 0x10 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x03 , 0x00 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x05 , 0xFF ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x06 , 0x1F ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x07 , 0x1F ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x08 , 0x28 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x14 , 0x20 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x0A , 0xA7 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x0B , 0x33 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x0C , 0x33 ) ;
if ( V_20 < 0 )
break;
V_20 = F_13 ( V_19 , 0x14 , 0x00 , 0x0F ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x15 , V_19 -> V_36 ) ;
if ( V_20 < 0 )
break;
V_20 = F_13 ( V_19 , 0x16 , 0x00 , 0x0F ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x17 , V_19 -> V_37 ) ;
if ( V_20 < 0 )
break;
if ( V_19 -> V_23 . V_38 == 2 ) {
T_3 V_4 = ( ( V_19 -> V_23 . V_39 << 13 ) + 71999 ) / 72000 ;
if ( V_19 -> V_23 . V_40 ) {
V_20 = F_14 ( V_19 , 0x09 , 0x6f ) ;
if ( V_20 < 0 )
break;
} else {
V_20 = F_14 ( V_19 , 0x09 , 0x6d ) ;
if ( V_20 < 0 )
break;
}
V_20 = F_14 ( V_19 , 0x20 , 0x08 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x21 , ( V_4 >> 8 ) & 0xff ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x22 , V_4 & 0xff ) ;
if ( V_20 < 0 )
break;
} else if ( V_19 -> V_23 . V_38 == 1 ) {
if ( V_19 -> V_23 . V_40 ) {
V_20 = F_14 ( V_19 , 0x09 , 0x6f ) ;
if ( V_20 < 0 )
break;
} else {
V_20 = F_14 ( V_19 , 0x09 , 0x6d ) ;
if ( V_20 < 0 )
break;
}
V_20 = F_14 ( V_19 , 0x20 , 0x68 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x21 , 0x00 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x22 , 0x02 ) ;
if ( V_20 < 0 )
break;
} else {
if ( V_19 -> V_23 . V_40 ) {
V_20 = F_14 ( V_19 , 0x09 , 0x4f ) ;
if ( V_20 < 0 )
break;
} else {
V_20 = F_14 ( V_19 , 0x09 , 0x4d ) ;
if ( V_20 < 0 )
break;
}
V_20 = F_14 ( V_19 , 0x20 , 0x28 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x21 , 0x00 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x22 , 0x07 ) ;
if ( V_20 < 0 )
break;
}
V_20 = F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ;
if ( V_20 < 0 )
break;
V_20 = F_13 ( V_19 , 0x03 , 0x02 , 0x02 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x01 , 0x04 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x00 , 0x31 ) ;
if ( V_20 < 0 )
break;
V_20 = F_13 ( V_19 , 0x09 , 0x08 , 0x08 ) ;
if ( V_20 < 0 )
break;
V_19 -> V_31 = - 1 ;
F_17 ( V_19 , 0 ) ;
} while ( 0 );
F_21 ( & V_19 -> V_35 ) ;
return 0 ;
}
static int F_22 ( struct V_41 * V_42 ,
int V_43 , int V_25 )
{
struct V_18 * V_19 = V_42 -> V_5 ;
T_1 V_14 ;
F_20 ( & V_19 -> V_35 ) ;
F_16 ( V_19 , 1 ) ;
F_9 ( V_19 , V_25 , & V_14 , 1 ) ;
F_21 ( & V_19 -> V_35 ) ;
return V_14 ;
}
static int F_23 ( struct V_41 * V_42 , int V_43 ,
int V_25 , T_1 V_44 )
{
struct V_18 * V_19 = V_42 -> V_5 ;
F_20 ( & V_19 -> V_35 ) ;
F_16 ( V_19 , 1 ) ;
F_10 ( V_19 , V_25 , & V_44 , 1 ) ;
F_21 ( & V_19 -> V_35 ) ;
return 0 ;
}
static int F_24 ( struct V_41 * V_42 ,
int V_43 , T_1 V_25 )
{
struct V_18 * V_19 = V_42 -> V_5 ;
T_1 V_14 ;
F_20 ( & V_19 -> V_35 ) ;
F_16 ( V_19 , 0 ) ;
F_11 ( V_19 , V_25 , & V_14 ) ;
F_21 ( & V_19 -> V_35 ) ;
return V_14 ;
}
static int F_25 ( struct V_41 * V_42 , int V_43 ,
T_1 V_25 , T_1 V_44 )
{
struct V_18 * V_19 = V_42 -> V_5 ;
F_20 ( & V_19 -> V_35 ) ;
F_16 ( V_19 , 0 ) ;
F_12 ( V_19 , V_25 , V_44 ) ;
F_21 ( & V_19 -> V_35 ) ;
return 0 ;
}
static int F_26 ( struct V_41 * V_42 , int V_43 )
{
struct V_18 * V_19 = V_42 -> V_5 ;
if ( V_19 -> V_31 )
V_33 ( V_42 , V_43 , V_19 -> V_45 , 0 ) ;
F_20 ( & V_19 -> V_35 ) ;
F_17 ( V_19 , 0 ) ;
F_14 ( V_19 , 0x00 , 0x21 ) ;
F_14 ( V_19 , 0x06 , 0x1F ) ;
F_14 ( V_19 , 0x00 , 0x31 ) ;
F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ;
F_14 ( V_19 , 0x03 , 0x02 ) ;
V_19 -> V_46 = 0 ;
V_19 -> V_29 = - 1 ;
{
int V_47 ;
for ( V_47 = 0 ; V_47 < 100 ; V_47 ++ ) {
F_27 ( 10000 , 11000 ) ;
if ( V_19 -> V_46 )
break;
}
}
F_21 ( & V_19 -> V_35 ) ;
return 0 ;
}
static int F_28 ( struct V_41 * V_42 , int V_43 )
{
struct V_18 * V_19 = V_42 -> V_5 ;
F_18 ( & V_19 -> V_22 -> V_13 , L_6 , V_48 ) ;
if ( V_19 -> V_31 )
V_33 ( V_42 , V_43 , V_19 -> V_45 , 0 ) ;
F_20 ( & V_19 -> V_35 ) ;
F_14 ( V_19 , 0x00 , 0x21 ) ;
F_14 ( V_19 , 0x06 , 0x1F ) ;
F_29 ( 300 ) ;
F_13 ( V_19 , 0x09 , 0x08 , 0x08 ) ;
F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ;
F_13 ( V_19 , 0x06 , 0x07 , 0x07 ) ;
V_19 -> V_29 = - 1 ;
V_19 -> V_34 = 0 ;
F_21 ( & V_19 -> V_35 ) ;
return 0 ;
}
static int F_30 ( struct V_41 * V_42 , int V_43 )
{
struct V_18 * V_19 = V_42 -> V_5 ;
F_20 ( & V_19 -> V_35 ) ;
F_13 ( V_19 , 0x09 , 0x00 , 0x08 ) ;
F_16 ( V_19 , 0 ) ;
F_17 ( V_19 , 1 ) ;
F_21 ( & V_19 -> V_35 ) ;
return 0 ;
}
static int F_31 ( struct V_18 * V_19 )
{
T_1 V_49 ;
F_8 ( V_19 , 0x04 , & V_49 ) ;
if ( ! V_49 )
return 0 ;
F_14 ( V_19 , 0x05 , V_49 ) ;
if ( V_49 & 0x40 )
V_19 -> V_50 = 1 ;
if ( V_49 & 0x20 )
V_19 -> V_34 = 0 ;
if ( V_49 & 2 ) {
T_1 V_51 ;
F_8 ( V_19 , 0x01 , & V_51 ) ;
if ( ! ( 2 & V_51 ) ) {
if ( ! V_19 -> V_52 ) {
V_19 -> V_52 |=
V_53 ;
F_13 ( V_19 , 0x03 , 0x08 , 0x08 ) ;
}
} else {
if ( V_19 -> V_52 ) {
V_19 -> V_52 = 0 ;
F_13 ( V_19 , 0x03 , 0x00 , 0x08 ) ;
F_18 ( & V_19 -> V_22 -> V_13 , L_7 ) ;
V_19 -> V_46 = 0 ;
}
}
if ( ( V_49 & 8 ) &&
( V_19 -> V_52 == V_53 ) ) {
V_19 -> V_46 = 1 ;
V_19 -> V_52 |= V_54 ;
}
}
return 0 ;
}
static int F_32 ( struct V_41 * V_42 , int V_43 , int V_55 )
{
struct V_18 * V_19 = V_42 -> V_5 ;
T_1 V_51 ;
F_20 ( & V_19 -> V_35 ) ;
F_31 ( V_19 ) ;
F_8 ( V_19 , 0x01 , & V_51 ) ;
F_21 ( & V_19 -> V_35 ) ;
return V_19 -> V_52 ;
}
static int V_33 ( struct V_41 * V_42 , int V_43 , T_1 * V_56 , int V_57 )
{
struct V_18 * V_19 = V_42 -> V_5 ;
T_1 V_58 , V_59 ;
T_2 V_12 ;
F_20 ( & V_19 -> V_35 ) ;
F_31 ( V_19 ) ;
F_21 ( & V_19 -> V_35 ) ;
if ( ! V_19 -> V_50 )
return 0 ;
F_20 ( & V_19 -> V_35 ) ;
F_8 ( V_19 , 0x0f , & V_58 ) ;
F_8 ( V_19 , 0x10 , & V_59 ) ;
V_12 = ( ( T_2 ) V_58 << 8 ) | V_59 ;
if ( V_12 > V_57 || V_12 < 2 ) {
F_7 ( V_19 , 0x12 , V_19 -> V_45 , V_12 ) ;
F_21 ( & V_19 -> V_35 ) ;
return - V_60 ;
}
F_7 ( V_19 , 0x12 , V_56 , V_12 ) ;
V_19 -> V_50 = 0 ;
F_21 ( & V_19 -> V_35 ) ;
return V_12 ;
}
static int F_33 ( struct V_41 * V_42 , int V_43 , T_1 * V_56 , int V_57 )
{
struct V_18 * V_19 = V_42 -> V_5 ;
if ( V_19 -> V_34 )
return - V_61 ;
F_20 ( & V_19 -> V_35 ) ;
F_14 ( V_19 , 0x0d , V_57 >> 8 ) ;
F_14 ( V_19 , 0x0e , V_57 & 0xff ) ;
F_15 ( V_19 , 0x11 , V_56 , V_57 ) ;
V_19 -> V_34 = 1 ;
F_21 ( & V_19 -> V_35 ) ;
return V_57 ;
}
struct V_41 * F_34 ( struct V_62 * V_23 ,
void * V_63 ,
struct V_1 * V_22 )
{
struct V_18 * V_19 ;
T_1 V_14 ;
if ( F_5 ( V_22 , V_23 -> V_3 , 0 , & V_14 ) < 0 ) {
F_18 ( & V_22 -> V_13 , L_8 , V_23 -> V_3 ) ;
return NULL ;
}
V_19 = F_35 ( sizeof( * V_19 ) , V_64 ) ;
if ( ! V_19 )
return NULL ;
F_36 ( & V_19 -> V_35 ) ;
V_19 -> V_23 = * V_23 ;
V_19 -> V_22 = V_22 ;
V_19 -> V_21 = 0xff ;
V_19 -> V_36 = 0x4a ;
V_19 -> V_37 = 0x1b ;
V_19 -> V_32 = V_65 ;
V_19 -> V_32 . V_5 = V_19 ;
F_19 ( V_19 ) ;
F_18 ( & V_22 -> V_13 , L_9 , V_19 -> V_23 . V_3 ) ;
return & V_19 -> V_32 ;
}
