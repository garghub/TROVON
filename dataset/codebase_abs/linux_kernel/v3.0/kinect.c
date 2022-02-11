static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 )
{
return F_2 ( V_2 ,
F_3 ( V_2 , 0 ) ,
0x00 ,
V_5 | V_6 | V_7 ,
0 , 0 , V_3 , V_4 , V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
return F_2 ( V_2 ,
F_5 ( V_2 , 0 ) ,
0x00 ,
V_9 | V_6 | V_7 ,
0 , 0 , V_3 , V_4 , V_8 ) ;
}
static int F_6 ( struct V_10 * V_10 , T_2 V_11 , void * V_12 ,
unsigned int V_13 , void * V_14 , unsigned int V_15 )
{
struct V_16 * V_16 = (struct V_16 * ) V_10 ;
struct V_1 * V_2 = V_10 -> V_17 ;
int V_18 , V_19 ;
T_1 * V_20 = V_16 -> V_20 ;
T_1 * V_21 = V_16 -> V_21 ;
struct V_22 * V_23 = ( void * ) V_20 ;
struct V_22 * V_24 = ( void * ) V_21 ;
if ( V_13 & 1 || V_13 > ( 0x400 - sizeof( * V_23 ) ) ) {
F_7 ( L_1 , V_13 ) ;
return - 1 ;
}
V_23 -> V_25 [ 0 ] = 0x47 ;
V_23 -> V_25 [ 1 ] = 0x4d ;
V_23 -> V_11 = F_8 ( V_11 ) ;
V_23 -> V_26 = F_8 ( V_16 -> V_27 ) ;
V_23 -> V_28 = F_8 ( V_13 / 2 ) ;
memcpy ( V_20 + sizeof( * V_23 ) , V_12 , V_13 ) ;
V_18 = F_1 ( V_2 , V_20 , V_13 + sizeof( * V_23 ) ) ;
F_9 ( V_29 , L_2 , V_11 ,
V_16 -> V_27 , V_13 , V_18 ) ;
if ( V_18 < 0 ) {
F_7 ( L_3 , V_18 ) ;
return V_18 ;
}
do {
V_19 = F_4 ( V_2 , V_21 , 0x200 ) ;
} while ( V_19 == 0 );
F_9 ( V_29 , L_4 , V_18 ) ;
if ( V_19 < sizeof( * V_24 ) ) {
F_7 ( L_5 , V_18 ) ;
return V_18 ;
}
V_19 -= sizeof( * V_24 ) ;
if ( V_24 -> V_25 [ 0 ] != 0x52 || V_24 -> V_25 [ 1 ] != 0x42 ) {
F_7 ( L_6 , V_24 -> V_25 [ 0 ] ,
V_24 -> V_25 [ 1 ] ) ;
return - 1 ;
}
if ( V_24 -> V_11 != V_23 -> V_11 ) {
F_7 ( L_7 , V_24 -> V_11 , V_23 -> V_11 ) ;
return - 1 ;
}
if ( V_24 -> V_26 != V_23 -> V_26 ) {
F_7 ( L_8 , V_24 -> V_26 , V_23 -> V_26 ) ;
return - 1 ;
}
if ( F_8 ( V_24 -> V_28 ) != ( V_19 / 2 ) ) {
F_7 ( L_9 ,
F_8 ( V_24 -> V_28 ) , ( int ) ( V_19 / 2 ) ) ;
return - 1 ;
}
if ( V_19 > V_15 ) {
F_10 ( L_10 ,
V_15 , V_19 ) ;
memcpy ( V_14 , V_21 + sizeof( * V_24 ) , V_15 ) ;
} else {
memcpy ( V_14 , V_21 + sizeof( * V_24 ) , V_19 ) ;
}
V_16 -> V_27 ++ ;
return V_19 ;
}
static int F_11 ( struct V_10 * V_10 , T_2 V_30 ,
T_2 V_3 )
{
T_2 V_31 [ 2 ] ;
T_2 V_11 [ 2 ] ;
int V_18 ;
V_11 [ 0 ] = F_8 ( V_30 ) ;
V_11 [ 1 ] = F_8 ( V_3 ) ;
F_9 ( V_29 , L_11 , V_30 , V_3 ) ;
V_18 = F_6 ( V_10 , 0x03 , V_11 , 4 , V_31 , 4 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 != 2 ) {
F_10 ( L_12 ,
V_18 , V_31 [ 0 ] , V_31 [ 1 ] ) ;
}
return 0 ;
}
static int F_12 ( struct V_10 * V_10 ,
const struct V_32 * V_33 )
{
struct V_16 * V_16 = (struct V_16 * ) V_10 ;
struct V_34 * V_34 ;
V_16 -> V_27 = 0 ;
V_16 -> V_35 = 0x80 ;
V_34 = & V_10 -> V_34 ;
V_34 -> V_36 = V_37 ;
V_34 -> V_38 = F_13 ( V_37 ) ;
#if 0
cam->npkt = 15;
gspca_dev->pkt_size = 960 * 2;
#endif
return 0 ;
}
static int F_14 ( struct V_10 * V_10 )
{
F_9 ( V_39 , L_13 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_10 )
{
int V_40 ;
T_1 V_41 , V_42 ;
T_1 V_43 , V_44 ;
T_1 V_45 , V_46 ;
T_1 V_47 ;
V_40 = V_10 -> V_34 . V_36 [ V_10 -> V_48 ] . V_49 ;
if ( V_40 & V_50 ) {
V_41 = 0x19 ;
V_43 = 0x1a ;
V_45 = 0x1b ;
V_47 = 0x03 ;
} else {
V_41 = 0x0c ;
V_43 = 0x0d ;
V_45 = 0x0e ;
V_47 = 0x01 ;
}
if ( V_40 & V_51 )
V_42 = 0x05 ;
else
V_42 = 0x00 ;
if ( V_40 & V_52 )
V_44 = 0x02 ;
else
V_44 = 0x01 ;
if ( V_40 & V_53 )
V_46 = 0x1e ;
else
V_46 = 0x0f ;
F_11 ( V_10 , 0x105 , 0x00 ) ;
F_11 ( V_10 , 0x05 , 0x00 ) ;
if ( V_40 & ( V_50 | V_52 ) ) {
F_11 ( V_10 , 0x13 , 0x01 ) ;
F_11 ( V_10 , 0x14 , 0x1e ) ;
F_11 ( V_10 , 0x06 , 0x02 ) ;
F_11 ( V_10 , 0x06 , 0x00 ) ;
}
F_11 ( V_10 , V_41 , V_42 ) ;
F_11 ( V_10 , V_43 , V_44 ) ;
F_11 ( V_10 , V_45 , V_46 ) ;
F_11 ( V_10 , 0x05 , V_47 ) ;
F_11 ( V_10 , 0x47 , 0x00 ) ;
return 0 ;
}
static void F_16 ( struct V_10 * V_10 )
{
F_11 ( V_10 , 0x05 , 0x00 ) ;
}
static void F_17 ( struct V_10 * V_10 , T_3 * V_54 , int V_28 )
{
struct V_16 * V_16 = (struct V_16 * ) V_10 ;
struct V_55 * V_56 = ( void * ) V_54 ;
T_1 * V_3 = V_54 + sizeof( * V_56 ) ;
int V_57 = V_28 - sizeof( * V_56 ) ;
T_1 V_58 = V_16 -> V_35 | 1 ;
T_1 V_59 = V_16 -> V_35 | 2 ;
T_1 V_60 = V_16 -> V_35 | 5 ;
if ( V_28 < 12 )
return;
if ( V_56 -> V_25 [ 0 ] != 'R' || V_56 -> V_25 [ 1 ] != 'B' ) {
F_10 ( L_14 , V_16 -> V_35 ,
V_56 -> V_25 [ 0 ] , V_56 -> V_25 [ 1 ] ) ;
return;
}
if ( V_56 -> V_61 == V_58 )
F_18 ( V_10 , V_62 , V_3 , V_57 ) ;
else if ( V_56 -> V_61 == V_59 )
F_18 ( V_10 , V_63 , V_3 , V_57 ) ;
else if ( V_56 -> V_61 == V_60 )
F_18 ( V_10 , V_64 , V_3 , V_57 ) ;
else
F_10 ( L_15 ) ;
}
static int F_19 ( struct V_65 * V_66 , const struct V_32 * V_33 )
{
return F_20 ( V_66 , V_33 , & V_67 , sizeof( struct V_16 ) ,
V_68 ) ;
}
static int T_4 F_21 ( void )
{
return F_22 ( & V_69 ) ;
}
static void T_5 F_23 ( void )
{
F_24 ( & V_69 ) ;
}
