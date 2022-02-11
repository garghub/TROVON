static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
const T_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_8 ;
memcpy ( V_1 -> V_9 , V_3 , V_4 ) ;
V_8 = F_2 ( V_6 , F_3 ( V_6 , 0 ) , 0x01 ,
V_10 | V_11 | V_12 ,
0x00 , V_2 ,
V_1 -> V_9 , V_4 , V_13 ) ;
if ( V_8 < 0 )
V_8 ( L_1 ,
V_2 , V_8 ) ;
return V_8 ;
}
static int F_4 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_14 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_6 , F_3 ( V_6 , 0 ) , 0x00 ,
V_10 | V_11 | V_12 ,
V_14 , V_2 , NULL , 0 , V_13 ) ;
if ( V_8 )
V_8 ( L_2
L_3 , V_2 , V_14 , V_8 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_15 ;
V_15 = F_2 ( V_6 , F_6 ( V_6 , 0 ) , 0x00 ,
V_16 | V_11 | V_12 ,
0x00 , V_2 ,
V_1 -> V_9 , 1 , V_13 ) ;
if ( V_15 < 0 ) {
V_8 ( L_4 ,
V_2 , V_15 ) ;
return V_15 ;
}
return V_1 -> V_9 [ 0 ] ;
}
static int F_7 ( struct V_1 * V_1 ,
const struct V_17 * V_18 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
struct V_20 * V_20 ;
T_2 V_21 [ 2 ] ;
V_21 [ 0 ] = F_5 ( V_1 , 0x0000 ) ;
V_21 [ 1 ] = F_5 ( V_1 , 0x0001 ) ;
V_21 [ 0 ] = ( ( V_21 [ 0 ] & 0x0f ) << 4 ) | ( ( V_21 [ 1 ] & 0xf0 ) >> 4 ) ;
V_21 [ 1 ] = V_21 [ 1 ] & 0x0f ;
F_8 ( V_22 , L_5 ,
V_21 [ 0 ] , V_21 [ 1 ] ) ;
if ( V_21 [ 0 ] != 0x27 ) {
F_8 ( V_22 , L_6 ) ;
return - V_23 ;
}
F_8 ( V_22 ,
L_7
L_8 , V_18 -> V_24 , V_18 -> V_25 ) ;
V_20 = & V_1 -> V_20 ;
V_20 -> V_26 = V_27 ;
V_20 -> V_28 = F_9 ( V_27 ) ;
V_19 -> V_29 = V_30 ;
V_19 -> V_31 = V_32 ;
V_19 -> V_33 = V_34 ;
V_19 -> V_35 = V_36 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 )
{
F_4 ( V_1 , 0x41 , 0x00 ) ;
F_4 ( V_1 , 0x0f , 0x00 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
T_3 V_37 ;
F_4 ( V_1 , 0x0f , 0x10 ) ;
F_1 ( V_1 , 0x0002 , V_38 [ 0 ] , 8 ) ;
F_1 ( V_1 , 0x000a , V_38 [ 1 ] , 8 ) ;
F_1 ( V_1 , 0x0012 , V_38 [ 2 ] , 8 ) ;
F_1 ( V_1 , 0x0042 , V_38 [ 3 ] , 8 ) ;
if ( V_1 -> V_39 == 176 )
F_4 ( V_1 , 0x4a , 0xff ) ;
else
F_4 ( V_1 , 0x4a , 0x30 ) ;
F_4 ( V_1 , 0x4b , 0x00 ) ;
F_4 ( V_1 , 0x08 , V_19 -> V_29 ) ;
F_4 ( V_1 , 0x0e , V_19 -> V_33 ) ;
F_4 ( V_1 , 0x02 , V_19 -> V_31 ) ;
V_37 = 0x02 ;
if ( V_1 -> V_39 == 176 ) {
V_37 |= 0x01 ;
F_8 ( V_40 , L_9 ) ;
} else {
F_8 ( V_40 , L_10 ) ;
}
F_4 ( V_1 , 0x41 , V_37 ) ;
F_4 ( V_1 , 0x13 , 0x01 ) ;
F_4 ( V_1 , 0x1c , 0x01 ) ;
F_12 ( 10 ) ;
F_4 ( V_1 , 0x40 , 0x01 ) ;
V_19 -> V_41 = 0 ;
V_19 -> V_42 = 0 ;
F_13 ( & V_19 -> V_43 , - 1 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_1 )
{
F_4 ( V_1 , 0x40 , 0x00 ) ;
F_4 ( V_1 , 0x41 , 0x00 ) ;
F_4 ( V_1 , 0x0f , 0x00 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_43 = F_16 ( & V_19 -> V_43 ) ;
if ( V_43 == - 1 )
return;
if ( V_19 -> V_42 > 0 )
V_19 -> V_42 -- ;
else if ( F_17 ( V_1 , V_43 ,
100 , V_44 ,
V_45 , V_46 ) )
V_19 -> V_42 = V_47 ;
}
static void F_18 ( struct V_1 * V_1 ,
T_2 * V_48 ,
int V_49 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
unsigned char * V_50 ;
V_50 = F_19 ( & V_19 -> V_41 , V_48 , V_49 ) ;
if ( V_50 ) {
int V_51 ;
V_51 = V_50 - V_48 ;
if ( V_51 > sizeof F_20 )
V_51 -= sizeof F_20 ;
else
V_51 = 0 ;
F_21 ( V_1 , V_52 ,
V_48 , V_51 ) ;
V_19 -> V_53 = 0 ;
F_21 ( V_1 , V_54 , NULL , 0 ) ;
V_49 -= V_50 - V_48 ;
V_48 = V_50 ;
}
if ( V_19 -> V_53 < 11 ) {
int V_55 ;
if ( V_19 -> V_53 < 5 ) {
V_55 = 5 - V_19 -> V_53 ;
if ( V_49 >= V_55 )
F_13 ( & V_19 -> V_43 , V_48 [ V_55 - 1 ] ) ;
}
V_55 = 11 - V_19 -> V_53 ;
if ( V_49 <= V_55 ) {
V_19 -> V_53 += V_49 ;
return;
}
V_48 += V_55 ;
V_49 -= V_55 ;
V_19 -> V_53 = 11 ;
}
F_21 ( V_1 , V_56 , V_48 , V_49 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_4 ( V_1 , 0x08 , V_19 -> V_29 ) ;
F_4 ( V_1 , 0x13 , 0x01 ) ;
F_4 ( V_1 , 0x1c , 0x01 ) ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_4 ( V_1 , 0x02 , V_19 -> V_31 ) ;
F_4 ( V_1 , 0x13 , 0x01 ) ;
F_4 ( V_1 , 0x1c , 0x01 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_4 ( V_1 , 0x0e , V_19 -> V_33 ) ;
F_4 ( V_1 , 0x13 , 0x01 ) ;
F_4 ( V_1 , 0x1c , 0x01 ) ;
}
static int F_25 ( struct V_1 * V_1 , T_4 V_57 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
V_19 -> V_29 = V_57 ;
if ( V_1 -> V_58 )
F_22 ( V_1 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , T_4 * V_57 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
* V_57 = V_19 -> V_29 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 , T_4 V_57 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
V_19 -> V_31 = V_57 ;
if ( V_1 -> V_58 )
F_23 ( V_1 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , T_4 * V_57 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
* V_57 = V_19 -> V_31 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , T_4 V_57 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
V_19 -> V_33 = V_57 ;
if ( V_1 -> V_58 )
F_24 ( V_1 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , T_4 * V_57 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
* V_57 = V_19 -> V_33 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , T_4 V_57 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
V_19 -> V_35 = V_57 ;
if ( V_19 -> V_35 ) {
V_19 -> V_31 = V_32 ;
V_19 -> V_33 = V_34 ;
if ( V_1 -> V_58 ) {
V_19 -> V_42 =
V_47 ;
F_23 ( V_1 ) ;
F_24 ( V_1 ) ;
}
}
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , T_4 * V_57 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
* V_57 = V_19 -> V_35 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_1 ,
T_2 * V_48 ,
int V_49 )
{
int V_59 = - V_60 ;
if ( V_49 == 2 && V_48 [ 0 ] == 0x5a && V_48 [ 1 ] == 0x5a ) {
F_34 ( V_1 -> V_61 , V_62 , 1 ) ;
F_35 ( V_1 -> V_61 ) ;
F_34 ( V_1 -> V_61 , V_62 , 0 ) ;
F_35 ( V_1 -> V_61 ) ;
V_59 = 0 ;
}
return V_59 ;
}
static int F_36 ( struct V_63 * V_64 ,
const struct V_17 * V_18 )
{
return F_37 ( V_64 , V_18 , & V_65 , sizeof( struct V_19 ) ,
V_66 ) ;
}
static int T_5 F_38 ( void )
{
return F_39 ( & V_67 ) ;
}
static void T_6 F_40 ( void )
{
F_41 ( & V_67 ) ;
}
