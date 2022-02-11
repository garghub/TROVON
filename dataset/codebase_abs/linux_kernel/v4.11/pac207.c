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
L_6 ,
V_19 -> V_24 , V_19 -> V_25 ) ;
V_20 = & V_1 -> V_20 ;
V_20 -> V_26 = V_27 ;
V_20 -> V_28 = F_10 ( V_27 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
T_2 V_29 ;
if ( V_30 )
V_29 = 0x02 ;
else
V_29 = 0x00 ;
F_5 ( V_1 , 0x41 , V_29 ) ;
F_5 ( V_1 , 0x0f , 0x00 ) ;
return V_1 -> V_9 ;
}
static void F_12 ( struct V_1 * V_1 , T_1 V_31 , T_1 V_32 )
{
F_5 ( V_1 , V_31 , V_32 ) ;
F_5 ( V_1 , 0x13 , 0x01 ) ;
F_5 ( V_1 , 0x1c , 0x01 ) ;
}
static int F_13 ( struct V_33 * V_34 )
{
struct V_1 * V_1 =
F_14 ( V_34 -> V_35 , struct V_1 , V_36 ) ;
struct V_37 * V_37 = (struct V_37 * ) V_1 ;
V_1 -> V_9 = 0 ;
if ( V_34 -> V_19 == V_38 && V_34 -> V_39 && V_34 -> V_32 ) {
V_1 -> V_40 -> V_32 = V_41 ;
V_1 -> V_42 -> V_32 = V_43 ;
V_37 -> V_44 = V_45 ;
}
if ( ! V_1 -> V_46 )
return 0 ;
switch ( V_34 -> V_19 ) {
case V_47 :
F_12 ( V_1 , V_48 , V_34 -> V_32 ) ;
break;
case V_38 :
if ( V_1 -> V_40 -> V_39 || ( V_34 -> V_39 && V_34 -> V_32 ) )
F_12 ( V_1 , V_49 ,
V_1 -> V_40 -> V_32 ) ;
if ( V_1 -> V_42 -> V_39 || ( V_34 -> V_39 && V_34 -> V_32 ) )
F_12 ( V_1 , V_50 ,
V_1 -> V_42 -> V_32 ) ;
break;
default:
return - V_51 ;
}
return V_1 -> V_9 ;
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_37 * V_37 = (struct V_37 * ) V_1 ;
struct V_52 * V_53 = & V_1 -> V_36 ;
V_1 -> V_54 . V_36 = V_53 ;
F_16 ( V_53 , 4 ) ;
V_37 -> V_55 = F_17 ( V_53 , & V_56 ,
V_47 ,
V_57 , V_58 ,
1 , V_59 ) ;
V_1 -> V_60 = F_17 ( V_53 , & V_56 ,
V_38 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_40 = F_17 ( V_53 , & V_56 ,
V_61 ,
V_62 , V_63 ,
1 , V_41 ) ;
V_1 -> V_42 = F_17 ( V_53 , & V_56 ,
V_64 ,
V_65 , V_66 ,
1 , V_43 ) ;
if ( V_53 -> error ) {
F_4 ( L_7 ) ;
return V_53 -> error ;
}
F_18 ( 3 , & V_1 -> V_60 , 0 , false ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_37 * V_37 = (struct V_37 * ) V_1 ;
T_3 V_29 ;
F_5 ( V_1 , 0x0f , 0x10 ) ;
F_1 ( V_1 , 0x0002 , V_67 [ 0 ] , 8 ) ;
F_1 ( V_1 , 0x000a , V_67 [ 1 ] , 8 ) ;
F_1 ( V_1 , 0x0012 , V_67 [ 2 ] , 8 ) ;
F_1 ( V_1 , 0x0042 , V_67 [ 3 ] , 8 ) ;
if ( V_1 -> V_68 . V_69 == 176 )
F_5 ( V_1 , 0x4a , 0xff ) ;
else
F_5 ( V_1 , 0x4a , 0x30 ) ;
F_5 ( V_1 , 0x4b , 0x00 ) ;
F_5 ( V_1 , 0x08 , F_20 ( V_37 -> V_55 ) ) ;
F_5 ( V_1 , 0x0e ,
F_20 ( V_1 -> V_42 ) ) ;
F_5 ( V_1 , 0x02 ,
F_20 ( V_1 -> V_40 ) ) ;
if ( V_30 )
V_29 = 0x00 ;
else
V_29 = 0x02 ;
if ( V_1 -> V_68 . V_69 == 176 ) {
V_29 |= 0x01 ;
F_9 ( V_70 , L_8 ) ;
} else {
F_9 ( V_70 , L_9 ) ;
}
F_5 ( V_1 , 0x41 , V_29 ) ;
F_5 ( V_1 , 0x13 , 0x01 ) ;
F_5 ( V_1 , 0x1c , 0x01 ) ;
F_21 ( 10 ) ;
F_5 ( V_1 , 0x40 , 0x01 ) ;
V_37 -> V_71 = 0 ;
V_37 -> V_44 = 0 ;
F_22 ( & V_37 -> V_72 , - 1 ) ;
return V_1 -> V_9 ;
}
static void F_23 ( struct V_1 * V_1 )
{
T_2 V_29 ;
if ( V_30 )
V_29 = 0x02 ;
else
V_29 = 0x00 ;
F_5 ( V_1 , 0x40 , 0x00 ) ;
F_5 ( V_1 , 0x41 , V_29 ) ;
F_5 ( V_1 , 0x0f , 0x00 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_37 * V_37 = (struct V_37 * ) V_1 ;
int V_72 = F_25 ( & V_37 -> V_72 ) ;
if ( V_72 == - 1 )
return;
if ( V_37 -> V_44 > 0 )
V_37 -> V_44 -- ;
else if ( F_26 ( V_1 , V_72 ,
90 , V_73 ) )
V_37 -> V_44 = V_45 ;
}
static void F_27 ( struct V_1 * V_1 ,
T_2 * V_74 ,
int V_75 )
{
struct V_37 * V_37 = (struct V_37 * ) V_1 ;
unsigned char * V_76 ;
V_76 = F_28 ( V_1 , & V_37 -> V_71 , V_74 , V_75 ) ;
if ( V_76 ) {
int V_77 ;
V_77 = V_76 - V_74 ;
if ( V_77 > sizeof F_29 )
V_77 -= sizeof F_29 ;
else
V_77 = 0 ;
F_30 ( V_1 , V_78 ,
V_74 , V_77 ) ;
V_37 -> V_79 = 0 ;
F_30 ( V_1 , V_80 , NULL , 0 ) ;
V_75 -= V_76 - V_74 ;
V_74 = V_76 ;
}
if ( V_37 -> V_79 < 11 ) {
int V_81 ;
if ( V_37 -> V_79 < 5 ) {
V_81 = 5 - V_37 -> V_79 ;
if ( V_75 >= V_81 )
F_22 ( & V_37 -> V_72 , V_74 [ V_81 - 1 ] ) ;
}
V_81 = 11 - V_37 -> V_79 ;
if ( V_75 <= V_81 ) {
V_37 -> V_79 += V_75 ;
return;
}
V_74 += V_81 ;
V_75 -= V_81 ;
V_37 -> V_79 = 11 ;
}
F_30 ( V_1 , V_82 , V_74 , V_75 ) ;
}
static int F_31 ( struct V_1 * V_1 ,
T_2 * V_74 ,
int V_75 )
{
int V_83 = - V_51 ;
if ( V_75 == 2 && V_74 [ 0 ] == 0x5a && V_74 [ 1 ] == 0x5a ) {
F_32 ( V_1 -> V_84 , V_85 , 1 ) ;
F_33 ( V_1 -> V_84 ) ;
F_32 ( V_1 -> V_84 , V_85 , 0 ) ;
F_33 ( V_1 -> V_84 ) ;
V_83 = 0 ;
}
return V_83 ;
}
static int F_34 ( struct V_86 * V_87 ,
const struct V_18 * V_19 )
{
return F_35 ( V_87 , V_19 , & V_88 , sizeof( struct V_37 ) ,
V_89 ) ;
}
