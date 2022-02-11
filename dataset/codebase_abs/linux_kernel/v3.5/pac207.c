static void F_1 ( struct V_1 * V_1 , T_1 V_2 ,
const T_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_8 ;
if ( V_1 -> V_9 < 0 )
return;
memcpy ( V_1 -> V_10 , V_3 , V_4 ) ;
V_8 = F_2 ( V_6 , F_3 ( V_6 , 0 ) , 0x01 ,
V_11 | V_12 | V_13 ,
0x00 , V_2 ,
V_1 -> V_10 , V_4 , V_14 ) ;
if ( V_8 < 0 ) {
F_4 ( L_1 ,
V_2 , V_8 ) ;
V_1 -> V_9 = V_8 ;
}
}
static void F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_15 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_8 ;
if ( V_1 -> V_9 < 0 )
return;
V_8 = F_2 ( V_6 , F_3 ( V_6 , 0 ) , 0x00 ,
V_11 | V_12 | V_13 ,
V_15 , V_2 , NULL , 0 , V_14 ) ;
if ( V_8 ) {
F_4 ( L_2 ,
V_2 , V_15 , V_8 ) ;
V_1 -> V_9 = V_8 ;
}
}
static int F_6 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_16 ;
if ( V_1 -> V_9 < 0 )
return 0 ;
V_16 = F_2 ( V_6 , F_7 ( V_6 , 0 ) , 0x00 ,
V_17 | V_12 | V_13 ,
0x00 , V_2 ,
V_1 -> V_10 , 1 , V_14 ) ;
if ( V_16 < 0 ) {
F_4 ( L_3 ,
V_2 , V_16 ) ;
V_1 -> V_9 = V_16 ;
return 0 ;
}
return V_1 -> V_10 [ 0 ] ;
}
static int F_8 ( struct V_1 * V_1 ,
const struct V_18 * V_19 )
{
struct V_20 * V_20 ;
T_2 V_21 [ 2 ] ;
V_21 [ 0 ] = F_6 ( V_1 , 0x0000 ) ;
V_21 [ 1 ] = F_6 ( V_1 , 0x0001 ) ;
V_21 [ 0 ] = ( ( V_21 [ 0 ] & 0x0f ) << 4 ) | ( ( V_21 [ 1 ] & 0xf0 ) >> 4 ) ;
V_21 [ 1 ] = V_21 [ 1 ] & 0x0f ;
F_9 ( V_22 , L_4 ,
V_21 [ 0 ] , V_21 [ 1 ] ) ;
if ( V_21 [ 0 ] != 0x27 ) {
F_9 ( V_22 , L_5 ) ;
return - V_23 ;
}
F_9 ( V_22 ,
L_6
L_7 , V_19 -> V_24 , V_19 -> V_25 ) ;
V_20 = & V_1 -> V_20 ;
V_20 -> V_26 = V_27 ;
V_20 -> V_28 = F_10 ( V_27 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0x41 , 0x00 ) ;
F_5 ( V_1 , 0x0f , 0x00 ) ;
return V_1 -> V_9 ;
}
static void F_12 ( struct V_1 * V_1 , T_1 V_29 , T_1 V_30 )
{
F_5 ( V_1 , V_29 , V_30 ) ;
F_5 ( V_1 , 0x13 , 0x01 ) ;
F_5 ( V_1 , 0x1c , 0x01 ) ;
}
static int F_13 ( struct V_31 * V_32 )
{
struct V_1 * V_1 =
F_14 ( V_32 -> V_33 , struct V_1 , V_34 ) ;
struct V_35 * V_35 = (struct V_35 * ) V_1 ;
V_1 -> V_9 = 0 ;
if ( V_32 -> V_19 == V_36 && V_32 -> V_37 && V_32 -> V_30 ) {
V_1 -> V_38 -> V_30 = V_39 ;
V_1 -> V_40 -> V_30 = V_41 ;
V_35 -> V_42 = V_43 ;
}
if ( ! V_1 -> V_44 )
return 0 ;
switch ( V_32 -> V_19 ) {
case V_45 :
F_12 ( V_1 , V_46 , V_32 -> V_30 ) ;
break;
case V_36 :
if ( V_1 -> V_38 -> V_37 || ( V_32 -> V_37 && V_32 -> V_30 ) )
F_12 ( V_1 , V_47 ,
V_1 -> V_38 -> V_30 ) ;
if ( V_1 -> V_40 -> V_37 || ( V_32 -> V_37 && V_32 -> V_30 ) )
F_12 ( V_1 , V_48 ,
V_1 -> V_40 -> V_30 ) ;
break;
default:
return - V_49 ;
}
return V_1 -> V_9 ;
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_35 * V_35 = (struct V_35 * ) V_1 ;
struct V_50 * V_51 = & V_1 -> V_34 ;
V_1 -> V_52 . V_34 = V_51 ;
F_16 ( V_51 , 4 ) ;
V_35 -> V_53 = F_17 ( V_51 , & V_54 ,
V_45 ,
V_55 , V_56 ,
1 , V_57 ) ;
V_1 -> V_58 = F_17 ( V_51 , & V_54 ,
V_36 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_38 = F_17 ( V_51 , & V_54 ,
V_59 ,
V_60 , V_61 ,
1 , V_39 ) ;
V_1 -> V_40 = F_17 ( V_51 , & V_54 ,
V_62 ,
V_63 , V_64 ,
1 , V_41 ) ;
if ( V_51 -> error ) {
F_4 ( L_8 ) ;
return V_51 -> error ;
}
F_18 ( 3 , & V_1 -> V_58 , 0 , false ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_35 * V_35 = (struct V_35 * ) V_1 ;
T_3 V_65 ;
F_5 ( V_1 , 0x0f , 0x10 ) ;
F_1 ( V_1 , 0x0002 , V_66 [ 0 ] , 8 ) ;
F_1 ( V_1 , 0x000a , V_66 [ 1 ] , 8 ) ;
F_1 ( V_1 , 0x0012 , V_66 [ 2 ] , 8 ) ;
F_1 ( V_1 , 0x0042 , V_66 [ 3 ] , 8 ) ;
if ( V_1 -> V_67 == 176 )
F_5 ( V_1 , 0x4a , 0xff ) ;
else
F_5 ( V_1 , 0x4a , 0x30 ) ;
F_5 ( V_1 , 0x4b , 0x00 ) ;
F_5 ( V_1 , 0x08 , F_20 ( V_35 -> V_53 ) ) ;
F_5 ( V_1 , 0x0e ,
F_20 ( V_1 -> V_40 ) ) ;
F_5 ( V_1 , 0x02 ,
F_20 ( V_1 -> V_38 ) ) ;
V_65 = 0x02 ;
if ( V_1 -> V_67 == 176 ) {
V_65 |= 0x01 ;
F_9 ( V_68 , L_9 ) ;
} else {
F_9 ( V_68 , L_10 ) ;
}
F_5 ( V_1 , 0x41 , V_65 ) ;
F_5 ( V_1 , 0x13 , 0x01 ) ;
F_5 ( V_1 , 0x1c , 0x01 ) ;
F_21 ( 10 ) ;
F_5 ( V_1 , 0x40 , 0x01 ) ;
V_35 -> V_69 = 0 ;
V_35 -> V_42 = 0 ;
F_22 ( & V_35 -> V_70 , - 1 ) ;
return V_1 -> V_9 ;
}
static void F_23 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0x40 , 0x00 ) ;
F_5 ( V_1 , 0x41 , 0x00 ) ;
F_5 ( V_1 , 0x0f , 0x00 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_35 * V_35 = (struct V_35 * ) V_1 ;
int V_70 = F_25 ( & V_35 -> V_70 ) ;
if ( V_70 == - 1 )
return;
if ( V_35 -> V_42 > 0 )
V_35 -> V_42 -- ;
else if ( F_26 ( V_1 , V_70 ,
90 , V_71 ) )
V_35 -> V_42 = V_43 ;
}
static void F_27 ( struct V_1 * V_1 ,
T_2 * V_72 ,
int V_73 )
{
struct V_35 * V_35 = (struct V_35 * ) V_1 ;
unsigned char * V_74 ;
V_74 = F_28 ( & V_35 -> V_69 , V_72 , V_73 ) ;
if ( V_74 ) {
int V_75 ;
V_75 = V_74 - V_72 ;
if ( V_75 > sizeof F_29 )
V_75 -= sizeof F_29 ;
else
V_75 = 0 ;
F_30 ( V_1 , V_76 ,
V_72 , V_75 ) ;
V_35 -> V_77 = 0 ;
F_30 ( V_1 , V_78 , NULL , 0 ) ;
V_73 -= V_74 - V_72 ;
V_72 = V_74 ;
}
if ( V_35 -> V_77 < 11 ) {
int V_79 ;
if ( V_35 -> V_77 < 5 ) {
V_79 = 5 - V_35 -> V_77 ;
if ( V_73 >= V_79 )
F_22 ( & V_35 -> V_70 , V_72 [ V_79 - 1 ] ) ;
}
V_79 = 11 - V_35 -> V_77 ;
if ( V_73 <= V_79 ) {
V_35 -> V_77 += V_73 ;
return;
}
V_72 += V_79 ;
V_73 -= V_79 ;
V_35 -> V_77 = 11 ;
}
F_30 ( V_1 , V_80 , V_72 , V_73 ) ;
}
static int F_31 ( struct V_1 * V_1 ,
T_2 * V_72 ,
int V_73 )
{
int V_81 = - V_49 ;
if ( V_73 == 2 && V_72 [ 0 ] == 0x5a && V_72 [ 1 ] == 0x5a ) {
F_32 ( V_1 -> V_82 , V_83 , 1 ) ;
F_33 ( V_1 -> V_82 ) ;
F_32 ( V_1 -> V_82 , V_83 , 0 ) ;
F_33 ( V_1 -> V_82 ) ;
V_81 = 0 ;
}
return V_81 ;
}
static int F_34 ( struct V_84 * V_85 ,
const struct V_18 * V_19 )
{
return F_35 ( V_85 , V_19 , & V_86 , sizeof( struct V_35 ) ,
V_87 ) ;
}
