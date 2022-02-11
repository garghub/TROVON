int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 ;
T_2 * V_9 = V_1 -> V_7 . V_10 ;
T_3 V_11 = ( V_3 > 0xff ) ? 2 : 1 ;
V_9 [ 0 ] = V_3 & 0xff ;
V_9 [ 1 ] = ( V_3 >> 8 ) & 0xff ;
V_4 = F_2 ( V_6 , F_3 ( V_6 , 0 ) ,
0x04 , 0x40 , V_2 , 0 , V_9 , V_11 ,
V_12 ) ;
F_4 ( V_13 , L_1 ,
V_3 , V_2 , V_4 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_3 * V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 ;
T_2 * V_9 = V_1 -> V_7 . V_10 ;
V_4 = F_2 ( V_6 , F_6 ( V_6 , 0 ) ,
0x04 , 0xc0 , V_2 , 0 , V_9 , 1 ,
V_12 ) ;
* V_3 = V_9 [ 0 ] ;
F_4 ( V_13 , L_2 ,
* V_3 , V_2 , V_4 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
int F_7 ( struct V_1 * V_1 , T_3 V_2 , T_1 V_14 )
{
if ( V_1 -> V_15 -> V_16 == 2 ) {
T_1 V_17 [ 2 ] = { V_2 , V_14 } ;
return F_8 ( V_1 , V_17 , 1 ) ;
} else {
T_3 V_17 [ 2 ] = { V_2 , V_14 } ;
return F_9 ( V_1 , V_17 , 1 ) ;
}
}
static int F_10 ( struct V_1 * V_1 )
{
int V_4 = 0 ;
if ( V_1 -> V_18 == V_19 ) {
struct V_5 * V_6 = V_1 -> V_7 . V_8 ;
T_2 * V_9 = V_1 -> V_7 . V_10 ;
V_9 [ 0 ] = 0 ;
V_4 = F_2 ( V_6 , F_3 ( V_6 , 0 ) ,
0x04 , 0x40 , 0x1704 , 0 , V_9 , 1 ,
V_12 ) ;
}
return ( V_4 < 0 ) ? V_4 : 0 ;
}
int F_9 ( struct V_1 * V_1 , const T_3 * V_17 , T_3 V_11 )
{
int V_4 , V_20 , V_21 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 ;
T_2 * V_9 = V_1 -> V_7 . V_10 ;
F_4 ( V_13 , L_3 , V_11 ) ;
for ( V_20 = 0 ; V_20 < V_11 ; ) {
memset ( V_9 , 0 , V_22 ) ;
for ( V_21 = 0 ; V_21 < V_23 && V_20 < V_11 ; V_21 ++ , V_20 ++ ) {
V_9 [ V_21 ] = V_17 [ 2 * V_20 ] ;
V_9 [ 0x10 + V_21 ] = V_17 [ 2 * V_20 + 1 ] ;
F_4 ( V_13 , L_4 ,
V_17 [ 2 * V_20 + 1 ] , V_17 [ 2 * V_20 ] ) ;
}
V_9 [ 0x20 ] = V_1 -> V_15 -> V_24 ;
V_9 [ 0x21 ] = V_21 - 1 ;
V_9 [ 0x22 ] = V_25 ;
V_4 = F_2 ( V_6 , F_3 ( V_6 , 0 ) ,
0x04 , 0x40 , 0x0400 , 0 , V_9 ,
V_22 ,
V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_10 ( V_1 ) ;
}
int F_8 ( struct V_1 * V_1 , const T_1 * V_17 , T_3 V_11 )
{
int V_4 , V_20 , V_21 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 ;
T_2 * V_9 = V_1 -> V_7 . V_10 ;
F_4 ( V_13 , L_3 , V_11 ) ;
for ( V_20 = 0 ; V_20 < V_11 ; ) {
memset ( V_9 , 0 , V_22 ) ;
for ( V_21 = 0 ; V_21 < V_26 && V_20 < V_11 ; V_21 ++ , V_20 ++ ) {
V_9 [ V_21 ] = V_17 [ 2 * V_20 ] ;
V_9 [ 0x10 + V_21 * 2 ] = V_17 [ 2 * V_20 + 1 ] ;
V_9 [ 0x10 + V_21 * 2 + 1 ] = V_17 [ 2 * V_20 + 1 ] >> 8 ;
F_4 ( V_13 , L_5 ,
V_17 [ 2 * V_20 + 1 ] , V_17 [ 2 * V_20 ] ) ;
}
V_9 [ 0x20 ] = V_1 -> V_15 -> V_24 ;
V_9 [ 0x21 ] = V_21 - 1 ;
V_9 [ 0x22 ] = V_25 ;
V_4 = F_2 ( V_6 , F_3 ( V_6 , 0 ) ,
0x04 , 0x40 , 0x0400 , 0 , V_9 ,
V_22 ,
V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_10 ( V_1 ) ;
}
int F_11 ( struct V_1 * V_1 , const T_3 V_2 , T_1 * V_14 )
{
int V_4 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 ;
T_2 * V_9 = V_1 -> V_7 . V_10 ;
V_4 = F_1 ( V_1 , V_27 , V_1 -> V_15 -> V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
memset ( V_9 , 0 , V_22 ) ;
V_9 [ 0 ] = V_2 ;
V_9 [ 0x20 ] = V_1 -> V_15 -> V_24 ;
V_9 [ 0x21 ] = 0 ;
V_9 [ 0x22 ] = V_29 ;
V_4 = F_2 ( V_6 , F_3 ( V_6 , 0 ) ,
0x04 , 0x40 , 0x1400 , 0 , V_9 , V_22 ,
V_12 ) ;
if ( V_4 < 0 ) {
V_4 ( L_6 , V_4 ) ;
return V_4 ;
}
V_4 = F_2 ( V_6 , F_6 ( V_6 , 0 ) ,
0x04 , 0xc0 , 0x1410 , 0 , V_9 , V_1 -> V_15 -> V_16 ,
V_12 ) ;
if ( V_1 -> V_15 -> V_16 == 2 )
* V_14 = V_9 [ 0 ] | ( V_9 [ 1 ] << 8 ) ;
else
* V_14 = V_9 [ 0 ] ;
F_4 ( V_13 , L_7 ,
* V_14 , V_2 , V_4 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static void F_12 ( struct V_1 * V_1 )
{
int V_20 ;
T_3 V_17 , V_9 ;
F_13 ( L_8 ) ;
for ( V_20 = 0x1400 ; V_20 < 0x160f ; V_20 ++ ) {
F_5 ( V_1 , V_20 , & V_17 ) ;
F_13 ( L_9 , V_17 , V_20 ) ;
}
F_13 ( L_10 ) ;
for ( V_20 = 0x1400 ; V_20 < 0x160f ; V_20 ++ ) {
F_5 ( V_1 , V_20 , & V_17 ) ;
V_9 = V_17 ;
F_1 ( V_1 , V_20 , 0xff ) ;
F_5 ( V_1 , V_20 , & V_17 ) ;
if ( V_17 == 0xff )
F_13 ( L_11 , V_20 ) ;
else if ( V_17 != V_9 )
F_13 ( L_12
L_13 , V_20 ) ;
else
F_13 ( L_14 , V_20 ) ;
F_1 ( V_1 , V_20 , V_9 ) ;
}
}
static int F_14 ( struct V_7 * V_7 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
int V_4 ;
F_4 ( V_30 , L_15 ) ;
F_15 ( 250 ) ;
V_4 = V_1 -> V_15 -> V_31 ( V_1 ) ;
if ( V_32 && V_1 -> V_15 -> V_33 )
V_1 -> V_15 -> V_33 ( V_1 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static int F_16 ( struct V_7 * V_7 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
int V_4 , V_38 ;
V_37 = F_17 ( V_1 -> V_7 . V_8 , V_1 -> V_7 . V_39 ) ;
V_35 = F_18 ( V_37 , V_1 -> V_7 . V_35 ) ;
if ( ! V_35 ) {
F_4 ( V_40 , L_16 ) ;
return - V_41 ;
}
V_38 = F_19 ( V_35 -> V_42 [ 0 ] . V_43 . V_44 ) ;
V_4 = F_1 ( V_1 , V_45 , V_38 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = V_1 -> V_15 -> V_46 ( V_1 ) ;
if ( V_4 < 0 )
goto V_47;
V_4 = F_1 ( V_1 , V_48 , 1 ) ;
V_47:
if ( V_4 < 0 )
F_4 ( V_49 , L_17 ) ;
else
F_4 ( V_49 , L_18 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static int F_20 ( struct V_7 * V_7 )
{
struct V_34 * V_35 ;
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
V_35 = & V_7 -> V_8 -> V_50 -> V_51 [ 0 ] -> V_52 [ 1 ] ;
V_35 -> V_42 [ 0 ] . V_43 . V_44 =
F_21 ( V_1 -> V_15 -> V_53 [ V_7 -> V_54 ] ) ;
return 0 ;
}
static int F_22 ( struct V_7 * V_7 )
{
int V_55 , V_38 , V_56 ;
struct V_34 * V_35 ;
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
V_35 = & V_7 -> V_8 -> V_50 -> V_51 [ 0 ] -> V_52 [ 1 ] ;
V_38 = F_19 ( V_35 -> V_42 [ 0 ] . V_43 . V_44 ) ;
V_56 = V_1 -> V_15 -> V_56 [ V_7 -> V_54 ] ;
if ( V_38 <= V_56 )
return - V_41 ;
V_38 -= 100 ;
if ( V_38 < V_56 )
V_38 = V_56 ;
V_35 -> V_42 [ 0 ] . V_43 . V_44 = F_21 ( V_38 ) ;
V_55 = F_23 ( V_7 -> V_8 , V_7 -> V_39 , 1 ) ;
if ( V_55 < 0 )
F_4 ( V_40 | V_49 , L_19 , V_55 ) ;
return V_55 ;
}
static void F_24 ( struct V_7 * V_7 )
{
int V_4 ;
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
V_4 = F_1 ( V_1 , V_48 , 0 ) ;
if ( V_4 < 0 )
goto V_47;
V_4 = V_1 -> V_15 -> V_57 ( V_1 ) ;
V_47:
if ( V_4 < 0 )
F_4 ( V_49 , L_20 ) ;
else
F_4 ( V_49 , L_21 ) ;
}
static void F_25 ( struct V_7 * V_7 ,
T_3 * V_17 ,
int V_11 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
F_4 ( V_58 , L_22 , V_11 ) ;
while ( V_11 ) {
int V_59 , V_60 ;
if ( V_11 < 4 ) {
F_4 ( V_58 , L_23 ) ;
return;
}
V_59 = ( V_17 [ 0 ] << 8 ) | V_17 [ 1 ] ;
V_60 = ( V_17 [ 2 ] << 8 ) | V_17 [ 3 ] ;
F_4 ( V_58 , L_24 , V_59 , V_60 ) ;
V_17 += 4 ;
V_11 -= 4 ;
if ( V_11 < V_60 ) {
F_4 ( V_40 , L_25
L_26 ) ;
V_7 -> V_61 = V_62 ;
return;
}
if ( V_1 -> V_18 == V_63 && ( V_59 & 0xff00 ) == 0x0200 )
goto V_64;
switch ( V_59 ) {
case 0x0200 :
case 0x4200 :
V_64:
F_4 ( V_58 , L_27 ) ;
if ( V_1 -> V_65 ) {
int V_66 = ( V_1 -> V_65 < V_60 ) ?
V_1 -> V_65 : V_60 ;
V_17 += V_66 ;
V_11 -= V_66 ;
V_60 -= V_66 ;
V_1 -> V_65 -= V_66 ;
}
F_26 ( V_7 , V_67 ,
V_17 , V_60 ) ;
break;
case 0x8001 :
case 0x8005 :
case 0xc001 :
case 0xc005 :
F_4 ( V_58 , L_28 ) ;
F_26 ( V_7 , V_68 ,
NULL , 0 ) ;
if ( V_1 -> V_18 == V_63 )
V_1 -> V_65 = V_7 -> V_69 * 4 ;
if ( V_60 )
F_4 ( V_40 , L_29
L_30 ) ;
break;
case 0x8002 :
case 0x8006 :
case 0xc002 :
F_4 ( V_58 , L_31 ) ;
F_26 ( V_7 , V_70 ,
NULL , 0 ) ;
if ( V_60 )
F_4 ( V_40 , L_29
L_32 ) ;
break;
case 0x0005 :
F_4 ( V_58 , L_33 ) ;
break;
case 0x0100 :
F_4 ( V_58 , L_34 ) ;
break;
case 0x42ff :
F_4 ( V_58 , L_35 ) ;
break;
default:
F_4 ( V_58 , L_36 , V_59 ) ;
}
V_17 += V_60 ;
V_11 -= V_60 ;
}
}
static int F_27 ( struct V_7 * V_7 ,
T_3 * V_17 ,
int V_11 )
{
int V_55 = - V_71 ;
if ( V_11 == 1 && V_17 [ 0 ] == 0x80 ) {
F_28 ( V_7 -> V_72 , V_73 , 1 ) ;
F_29 ( V_7 -> V_72 ) ;
V_55 = 0 ;
}
if ( V_11 == 1 && V_17 [ 0 ] == 0x88 ) {
F_28 ( V_7 -> V_72 , V_73 , 0 ) ;
F_29 ( V_7 -> V_72 ) ;
V_55 = 0 ;
}
return V_55 ;
}
static int F_30 ( struct V_7 * V_7 ,
const struct V_74 * V_59 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
F_4 ( V_30 , L_37 ) ;
V_1 -> V_43 = V_75 ;
V_1 -> V_18 = V_59 -> V_76 ;
V_7 -> V_75 = & V_1 -> V_43 ;
if ( V_77 )
F_12 ( V_1 ) ;
V_1 -> V_15 = & V_78 ;
if ( ! V_1 -> V_15 -> V_79 ( V_1 ) )
return 0 ;
V_1 -> V_15 = & V_80 ;
if ( ! V_1 -> V_15 -> V_79 ( V_1 ) )
return 0 ;
V_1 -> V_15 = & V_81 ;
if ( ! V_1 -> V_15 -> V_79 ( V_1 ) )
return 0 ;
V_1 -> V_15 = & V_82 ;
if ( ! V_1 -> V_15 -> V_79 ( V_1 ) )
return 0 ;
V_1 -> V_15 = & V_83 ;
if ( ! V_1 -> V_15 -> V_79 ( V_1 ) )
return 0 ;
V_1 -> V_15 = NULL ;
return - V_84 ;
}
static int F_31 ( struct V_36 * V_37 ,
const struct V_74 * V_59 )
{
F_4 ( V_30 , L_38 ) ;
return F_32 ( V_37 , V_59 , & V_75 , sizeof( struct V_1 ) ,
V_85 ) ;
}
static void F_33 ( struct V_36 * V_37 )
{
struct V_7 * V_7 = F_34 ( V_37 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
F_4 ( V_30 , L_39 ) ;
if ( V_1 -> V_15 -> V_86 )
V_1 -> V_15 -> V_86 ( V_1 ) ;
F_35 ( V_37 ) ;
}
static int T_4 F_36 ( void )
{
return F_37 ( & V_87 ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( & V_87 ) ;
}
