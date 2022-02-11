static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_3 ,
int V_4 )
{
#if V_5 < 64
#error "USB buffer too small"
#endif
struct V_6 * V_7 = V_1 -> V_7 ;
int V_8 ;
if ( V_1 -> V_9 < 0 )
return;
V_8 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
V_2 ,
V_10 | V_11 | V_12 ,
0x0000 ,
V_3 ,
V_1 -> V_13 , V_4 ,
500 ) ;
F_4 ( V_14 , L_1 , V_2 , V_3 ,
V_1 -> V_13 [ 0 ] ) ;
if ( V_8 < 0 ) {
F_5 ( L_2 , V_8 ) ;
V_1 -> V_9 = V_8 ;
}
}
static void F_6 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_15 ,
T_2 V_3 )
{
struct V_6 * V_7 = V_1 -> V_7 ;
int V_8 ;
if ( V_1 -> V_9 < 0 )
return;
F_4 ( V_16 , L_3 , V_2 , V_15 , V_3 ) ;
V_8 = F_2 ( V_7 , F_7 ( V_7 , 0 ) ,
V_2 ,
V_17 | V_11 | V_12 ,
V_15 , V_3 ,
NULL , 0 , 500 ) ;
if ( V_8 < 0 ) {
F_5 ( L_4 , V_8 ) ;
V_1 -> V_9 = V_8 ;
}
}
static void F_8 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_15 ,
T_2 V_3 ,
T_1 V_18 )
{
struct V_6 * V_7 = V_1 -> V_7 ;
int V_8 ;
if ( V_1 -> V_9 < 0 )
return;
F_4 ( V_16 , L_5 , V_2 , V_15 , V_3 , V_18 ) ;
V_1 -> V_13 [ 0 ] = V_18 ;
V_8 = F_2 ( V_7 , F_7 ( V_7 , 0 ) ,
V_2 ,
V_17 | V_11 | V_12 ,
V_15 , V_3 ,
V_1 -> V_13 , 1 , 500 ) ;
if ( V_8 < 0 ) {
F_5 ( L_4 , V_8 ) ;
V_1 -> V_9 = V_8 ;
}
}
static void F_9 ( struct V_1 * V_1 )
{
int V_19 ;
V_19 = 20 ;
do {
F_1 ( V_1 , 0x21 , 0x0000 , 1 ) ;
if ( V_1 -> V_13 [ 0 ] == 0 )
return;
F_10 ( 30 ) ;
} while ( -- V_19 > 0 );
F_4 ( V_20 , L_6 ) ;
V_1 -> V_9 = - V_21 ;
}
static void F_11 ( struct V_1 * V_1 )
{
int V_19 ;
V_19 = 10 ;
do {
F_1 ( V_1 , 0x21 , 0x0001 , 1 ) ;
F_10 ( 10 ) ;
if ( V_1 -> V_13 [ 0 ] == 1 ) {
F_8 ( V_1 , 0x21 , 0x0000 , 0x0001 , 0x00 ) ;
F_1 ( V_1 , 0x21 , 0x0001 , 1 ) ;
return;
}
} while ( -- V_19 > 0 );
F_4 ( V_20 , L_7 ) ;
V_1 -> V_9 = - V_21 ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
F_8 ( V_1 , 0xc0 , 0x0000 , 0x00c0 , V_22 -> V_23 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
F_8 ( V_1 , 0xc1 , 0x0000 , 0x00c1 , V_22 -> V_24 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
F_8 ( V_1 , 0xc2 , 0x0000 , 0x0000 , V_22 -> V_25 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
F_8 ( V_1 , 0xc3 , 0x0000 , 0x00c3 , V_22 -> V_26 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
F_8 ( V_1 , 0xc4 , 0x0000 , 0x00c4 , V_22 -> V_27 ) ;
}
static int F_17 ( struct V_1 * V_1 ,
const struct V_28 * V_29 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_1 -> V_30 . V_31 = V_32 ;
V_1 -> V_30 . V_33 = F_18 ( V_32 ) ;
V_1 -> V_30 . V_34 = 128 ;
V_22 -> V_23 = V_35 ;
V_22 -> V_24 = V_36 ;
V_22 -> V_25 = V_37 ;
V_22 -> V_26 = V_38 ;
V_22 -> V_27 = V_39 ;
V_1 -> V_40 = 4 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
F_6 ( V_1 , 0x00 , 0x0001 , 0x2067 ) ;
F_6 ( V_1 , 0x00 , 0x00d0 , 0x206b ) ;
F_6 ( V_1 , 0x00 , 0x0000 , 0x206c ) ;
F_6 ( V_1 , 0x00 , 0x0001 , 0x2069 ) ;
F_10 ( 8 ) ;
F_6 ( V_1 , 0x00 , 0x00c0 , 0x206b ) ;
F_6 ( V_1 , 0x00 , 0x0000 , 0x206c ) ;
F_6 ( V_1 , 0x00 , 0x0001 , 0x2069 ) ;
F_1 ( V_1 , 0x20 , 0x0000 , 1 ) ;
F_1 ( V_1 , 0x20 , 0x0000 , 5 ) ;
F_1 ( V_1 , 0x23 , 0x0000 , 64 ) ;
F_4 ( V_41 , L_8 , & V_1 -> V_13 [ 0x1c ] ,
& V_1 -> V_13 [ 0x30 ] ) ;
F_1 ( V_1 , 0x23 , 0x0001 , 64 ) ;
return V_1 -> V_9 ;
}
static int F_20 ( struct V_1 * V_1 )
{
T_1 V_42 ;
F_1 ( V_1 , 0x00 , 0x2520 , 1 ) ;
F_9 ( V_1 ) ;
F_6 ( V_1 , 0xc5 , 0x0003 , 0x0000 ) ;
F_11 ( V_1 ) ;
F_9 ( V_1 ) ;
V_42 = V_1 -> V_30 . V_31 [ V_1 -> V_43 ] . V_44 ;
F_8 ( V_1 , 0x25 , 0x0000 , 0x0004 , V_42 ) ;
F_1 ( V_1 , 0x25 , 0x0004 , 1 ) ;
F_8 ( V_1 , 0x27 , 0x0000 , 0x0000 , 0x06 ) ;
F_1 ( V_1 , 0x27 , 0x0000 , 1 ) ;
return V_1 -> V_9 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
F_22 ( V_22 -> V_45 , V_1 -> V_46 , V_1 -> V_47 ,
0x22 ) ;
F_23 ( V_22 -> V_45 , 82 ) ;
F_12 ( V_1 ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
F_15 ( V_1 ) ;
F_16 ( V_1 ) ;
F_10 ( 5 ) ;
F_1 ( V_1 , 0x00 , 0x2520 , 1 ) ;
F_10 ( 8 ) ;
F_9 ( V_1 ) ;
F_6 ( V_1 , 0x31 , 0x0000 , 0x0004 ) ;
F_11 ( V_1 ) ;
F_9 ( V_1 ) ;
F_10 ( 200 ) ;
V_22 -> V_48 = 0 ;
return V_1 -> V_9 ;
}
static void F_24 ( struct V_1 * V_1 )
{
F_9 ( V_1 ) ;
F_6 ( V_1 , 0x31 , 0x0000 , 0x0000 ) ;
F_11 ( V_1 ) ;
F_9 ( V_1 ) ;
}
static void F_25 ( struct V_1 * V_1 ,
T_1 * V_49 ,
int V_4 )
{
int V_19 ;
V_19 = 0 ;
do {
if ( V_49 [ V_19 ] == 0xff ) {
F_26 ( V_1 , V_50 ,
V_49 , V_19 + 1 ) ;
V_4 -= V_19 ;
V_49 += V_19 ;
* V_49 = 0x00 ;
V_19 = 0 ;
}
} while ( ++ V_19 < V_4 );
F_26 ( V_1 , V_50 , V_49 , V_4 ) ;
}
static void F_27 ( struct V_1 * V_1 ,
T_1 * V_49 ,
int V_4 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
static const T_1 V_51 [] = { 0xff , 0xd9 } ;
if ( V_4 < 3 )
return;
if ( * V_49 == 0x02 ) {
if ( V_49 [ 1 ] & 0x02 ) {
V_22 -> V_48 = ! ( V_49 [ 1 ] & 1 ) ;
F_25 ( V_1 , V_49 + 2 , V_4 - 2 ) ;
F_26 ( V_1 , V_52 ,
V_51 , 2 ) ;
return;
}
if ( ( V_49 [ 1 ] & 1 ) != V_22 -> V_48 )
goto F_5;
if ( V_1 -> V_53 == V_52 )
F_26 ( V_1 , V_54 ,
V_22 -> V_45 , V_55 ) ;
F_25 ( V_1 , V_49 + 2 , V_4 - 2 ) ;
return;
}
F_5:
V_1 -> V_53 = V_56 ;
}
static int F_28 ( struct V_1 * V_1 , T_3 V_57 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_23 = V_57 ;
if ( V_1 -> V_58 )
F_12 ( V_1 ) ;
return V_1 -> V_9 ;
}
static int F_29 ( struct V_1 * V_1 , T_3 * V_57 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_57 = V_22 -> V_23 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , T_3 V_57 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_24 = V_57 ;
if ( V_1 -> V_58 )
F_13 ( V_1 ) ;
return V_1 -> V_9 ;
}
static int F_31 ( struct V_1 * V_1 , T_3 * V_57 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_57 = V_22 -> V_24 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , T_3 V_57 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_25 = V_57 ;
if ( V_1 -> V_58 )
F_14 ( V_1 ) ;
return V_1 -> V_9 ;
}
static int F_33 ( struct V_1 * V_1 , T_3 * V_57 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_57 = V_22 -> V_25 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , T_3 V_57 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_26 = V_57 ;
if ( V_1 -> V_58 )
F_15 ( V_1 ) ;
return V_1 -> V_9 ;
}
static int F_35 ( struct V_1 * V_1 , T_3 * V_57 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_57 = V_22 -> V_26 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 , T_3 V_57 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_27 = V_57 ;
if ( V_1 -> V_58 )
F_16 ( V_1 ) ;
return V_1 -> V_9 ;
}
static int F_37 ( struct V_1 * V_1 , T_3 * V_57 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_57 = V_22 -> V_27 ;
return 0 ;
}
static int F_38 ( struct V_59 * V_60 ,
const struct V_28 * V_29 )
{
if ( V_60 -> V_61 -> V_62 . V_63 != 1 )
return - V_64 ;
return F_39 ( V_60 , V_29 , & V_65 , sizeof( struct V_22 ) ,
V_66 ) ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_67 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_67 ) ;
}
