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
F_12 ( L_6 , V_4 ) ;
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
static void F_13 ( struct V_1 * V_1 )
{
int V_20 ;
T_3 V_17 , V_9 ;
F_14 ( L_8 ) ;
for ( V_20 = 0x1400 ; V_20 < 0x160f ; V_20 ++ ) {
F_5 ( V_1 , V_20 , & V_17 ) ;
F_14 ( L_9 , V_17 , V_20 ) ;
}
F_14 ( L_10 ) ;
for ( V_20 = 0x1400 ; V_20 < 0x160f ; V_20 ++ ) {
F_5 ( V_1 , V_20 , & V_17 ) ;
V_9 = V_17 ;
F_1 ( V_1 , V_20 , 0xff ) ;
F_5 ( V_1 , V_20 , & V_17 ) ;
if ( V_17 == 0xff )
F_14 ( L_11 , V_20 ) ;
else if ( V_17 != V_9 )
F_14 ( L_12 ,
V_20 ) ;
else
F_14 ( L_13 , V_20 ) ;
F_1 ( V_1 , V_20 , V_9 ) ;
}
}
static int F_15 ( struct V_7 * V_7 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
int V_4 ;
F_4 ( V_30 , L_14 ) ;
F_16 ( 250 ) ;
V_4 = V_1 -> V_15 -> V_31 ( V_1 ) ;
if ( V_32 && V_1 -> V_15 -> V_33 )
V_1 -> V_15 -> V_33 ( V_1 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static int F_17 ( struct V_7 * V_7 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
F_4 ( V_30 , L_15 ) ;
V_7 -> V_34 . V_35 = & V_7 -> V_35 ;
return V_1 -> V_15 -> V_36 ( V_1 ) ;
}
static int F_18 ( struct V_7 * V_7 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
int V_4 , V_41 ;
V_40 = F_19 ( V_1 -> V_7 . V_8 , V_1 -> V_7 . V_42 ) ;
V_38 = F_20 ( V_40 , V_1 -> V_7 . V_38 ) ;
if ( ! V_38 ) {
F_4 ( V_43 , L_16 ) ;
return - V_44 ;
}
V_41 = F_21 ( V_38 -> V_45 [ 0 ] . V_46 . V_47 ) ;
V_4 = F_1 ( V_1 , V_48 , V_41 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = V_1 -> V_15 -> V_49 ( V_1 ) ;
if ( V_4 < 0 )
goto V_50;
V_4 = F_1 ( V_1 , V_51 , 1 ) ;
V_50:
if ( V_4 < 0 )
F_4 ( V_52 , L_17 ) ;
else
F_4 ( V_52 , L_18 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static int F_22 ( struct V_7 * V_7 )
{
struct V_37 * V_38 ;
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
V_38 = & V_7 -> V_8 -> V_53 -> V_54 [ 0 ] -> V_55 [ 1 ] ;
V_38 -> V_45 [ 0 ] . V_46 . V_47 =
F_23 ( V_1 -> V_15 -> V_56 [ V_7 -> V_57 ] ) ;
return 0 ;
}
static int F_24 ( struct V_7 * V_7 )
{
int V_58 , V_41 , V_59 ;
struct V_37 * V_38 ;
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
V_38 = & V_7 -> V_8 -> V_53 -> V_54 [ 0 ] -> V_55 [ 1 ] ;
V_41 = F_21 ( V_38 -> V_45 [ 0 ] . V_46 . V_47 ) ;
V_59 = V_1 -> V_15 -> V_59 [ V_7 -> V_57 ] ;
if ( V_41 <= V_59 )
return - V_44 ;
V_41 -= 100 ;
if ( V_41 < V_59 )
V_41 = V_59 ;
V_38 -> V_45 [ 0 ] . V_46 . V_47 = F_23 ( V_41 ) ;
V_58 = F_25 ( V_7 -> V_8 , V_7 -> V_42 , 1 ) ;
if ( V_58 < 0 )
F_4 ( V_43 | V_52 , L_19 , V_58 ) ;
return V_58 ;
}
static void F_26 ( struct V_7 * V_7 )
{
int V_4 ;
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
V_4 = F_1 ( V_1 , V_51 , 0 ) ;
if ( V_4 < 0 )
goto V_50;
V_4 = V_1 -> V_15 -> V_60 ( V_1 ) ;
V_50:
if ( V_4 < 0 )
F_4 ( V_52 , L_20 ) ;
else
F_4 ( V_52 , L_21 ) ;
}
static void F_27 ( struct V_7 * V_7 ,
T_3 * V_17 ,
int V_11 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
F_4 ( V_61 , L_22 , V_11 ) ;
while ( V_11 ) {
int V_62 , V_63 ;
if ( V_11 < 4 ) {
F_4 ( V_61 , L_23 ) ;
return;
}
V_62 = ( V_17 [ 0 ] << 8 ) | V_17 [ 1 ] ;
V_63 = ( V_17 [ 2 ] << 8 ) | V_17 [ 3 ] ;
F_4 ( V_61 , L_24 , V_62 , V_63 ) ;
V_17 += 4 ;
V_11 -= 4 ;
if ( V_11 < V_63 ) {
F_4 ( V_43 , L_25
L_26 ) ;
V_7 -> V_64 = V_65 ;
return;
}
if ( V_1 -> V_18 == V_66 && ( V_62 & 0xff00 ) == 0x0200 )
goto V_67;
switch ( V_62 ) {
case 0x0200 :
case 0x4200 :
V_67:
F_4 ( V_61 , L_27 ) ;
if ( V_1 -> V_68 ) {
int V_69 = ( V_1 -> V_68 < V_63 ) ?
V_1 -> V_68 : V_63 ;
V_17 += V_69 ;
V_11 -= V_69 ;
V_63 -= V_69 ;
V_1 -> V_68 -= V_69 ;
}
F_28 ( V_7 , V_70 ,
V_17 , V_63 ) ;
break;
case 0x8001 :
case 0x8005 :
case 0xc001 :
case 0xc005 :
F_4 ( V_61 , L_28 ) ;
F_28 ( V_7 , V_71 ,
NULL , 0 ) ;
if ( V_1 -> V_18 == V_66 )
V_1 -> V_68 = V_7 -> V_72 * 4 ;
if ( V_63 )
F_4 ( V_43 , L_29
L_30 ) ;
break;
case 0x8002 :
case 0x8006 :
case 0xc002 :
F_4 ( V_61 , L_31 ) ;
F_28 ( V_7 , V_73 ,
NULL , 0 ) ;
if ( V_63 )
F_4 ( V_43 , L_29
L_32 ) ;
break;
case 0x0005 :
F_4 ( V_61 , L_33 ) ;
break;
case 0x0100 :
F_4 ( V_61 , L_34 ) ;
break;
case 0x42ff :
F_4 ( V_61 , L_35 ) ;
break;
default:
F_4 ( V_61 , L_36 , V_62 ) ;
}
V_17 += V_63 ;
V_11 -= V_63 ;
}
}
static int F_29 ( struct V_7 * V_7 ,
T_3 * V_17 ,
int V_11 )
{
int V_58 = - V_74 ;
if ( V_11 == 1 && V_17 [ 0 ] == 0x80 ) {
F_30 ( V_7 -> V_75 , V_76 , 1 ) ;
F_31 ( V_7 -> V_75 ) ;
V_58 = 0 ;
}
if ( V_11 == 1 && V_17 [ 0 ] == 0x88 ) {
F_30 ( V_7 -> V_75 , V_76 , 0 ) ;
F_31 ( V_7 -> V_75 ) ;
V_58 = 0 ;
}
return V_58 ;
}
static int F_32 ( struct V_7 * V_7 ,
const struct V_77 * V_62 )
{
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
F_4 ( V_30 , L_37 ) ;
V_1 -> V_18 = V_62 -> V_78 ;
V_7 -> V_79 = & V_79 ;
if ( V_80 )
F_13 ( V_1 ) ;
V_1 -> V_15 = & V_81 ;
if ( ! V_1 -> V_15 -> V_82 ( V_1 ) )
return 0 ;
V_1 -> V_15 = & V_83 ;
if ( ! V_1 -> V_15 -> V_82 ( V_1 ) )
return 0 ;
V_1 -> V_15 = & V_84 ;
if ( ! V_1 -> V_15 -> V_82 ( V_1 ) )
return 0 ;
V_1 -> V_15 = & V_85 ;
if ( ! V_1 -> V_15 -> V_82 ( V_1 ) )
return 0 ;
V_1 -> V_15 = & V_86 ;
if ( ! V_1 -> V_15 -> V_82 ( V_1 ) )
return 0 ;
V_1 -> V_15 = NULL ;
return - V_87 ;
}
static int F_33 ( struct V_39 * V_40 ,
const struct V_77 * V_62 )
{
F_4 ( V_30 , L_38 ) ;
return F_34 ( V_40 , V_62 , & V_79 , sizeof( struct V_1 ) ,
V_88 ) ;
}
static void F_35 ( struct V_39 * V_40 )
{
struct V_7 * V_7 = F_36 ( V_40 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_7 ;
void * V_89 = V_1 -> V_90 ;
F_4 ( V_30 , L_39 ) ;
V_1 -> V_15 = NULL ;
F_37 ( V_40 ) ;
F_38 ( V_89 ) ;
}
