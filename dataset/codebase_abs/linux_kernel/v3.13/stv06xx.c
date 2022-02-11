int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
int V_4 ;
struct V_5 * V_5 = (struct V_5 * ) V_1 ;
struct V_6 * V_7 = V_1 -> V_5 . V_8 ;
T_2 * V_9 = V_1 -> V_5 . V_10 ;
T_3 V_11 = ( V_3 > 0xff ) ? 2 : 1 ;
V_9 [ 0 ] = V_3 & 0xff ;
V_9 [ 1 ] = ( V_3 >> 8 ) & 0xff ;
V_4 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
0x04 , 0x40 , V_2 , 0 , V_9 , V_11 ,
V_12 ) ;
F_4 ( V_13 , L_1 ,
V_3 , V_2 , V_4 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_3 * V_3 )
{
int V_4 ;
struct V_5 * V_5 = (struct V_5 * ) V_1 ;
struct V_6 * V_7 = V_1 -> V_5 . V_8 ;
T_2 * V_9 = V_1 -> V_5 . V_10 ;
V_4 = F_2 ( V_7 , F_6 ( V_7 , 0 ) ,
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
struct V_6 * V_7 = V_1 -> V_5 . V_8 ;
T_2 * V_9 = V_1 -> V_5 . V_10 ;
V_9 [ 0 ] = 0 ;
V_4 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
0x04 , 0x40 , 0x1704 , 0 , V_9 , 1 ,
V_12 ) ;
}
return ( V_4 < 0 ) ? V_4 : 0 ;
}
int F_9 ( struct V_1 * V_1 , const T_3 * V_17 , T_3 V_11 )
{
int V_4 , V_20 , V_21 ;
struct V_5 * V_5 = (struct V_5 * ) V_1 ;
struct V_6 * V_7 = V_1 -> V_5 . V_8 ;
T_2 * V_9 = V_1 -> V_5 . V_10 ;
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
V_4 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
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
struct V_5 * V_5 = (struct V_5 * ) V_1 ;
struct V_6 * V_7 = V_1 -> V_5 . V_8 ;
T_2 * V_9 = V_1 -> V_5 . V_10 ;
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
V_4 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
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
struct V_5 * V_5 = (struct V_5 * ) V_1 ;
struct V_6 * V_7 = V_1 -> V_5 . V_8 ;
T_2 * V_9 = V_1 -> V_5 . V_10 ;
V_4 = F_1 ( V_1 , V_27 , V_1 -> V_15 -> V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
memset ( V_9 , 0 , V_22 ) ;
V_9 [ 0 ] = V_2 ;
V_9 [ 0x20 ] = V_1 -> V_15 -> V_24 ;
V_9 [ 0x21 ] = 0 ;
V_9 [ 0x22 ] = V_29 ;
V_4 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
0x04 , 0x40 , 0x1400 , 0 , V_9 , V_22 ,
V_12 ) ;
if ( V_4 < 0 ) {
F_12 ( L_6 , V_4 ) ;
return V_4 ;
}
V_4 = F_2 ( V_7 , F_6 ( V_7 , 0 ) ,
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
static int F_15 ( struct V_5 * V_5 )
{
struct V_1 * V_1 = (struct V_1 * ) V_5 ;
int V_4 ;
F_4 ( V_30 , L_14 ) ;
F_16 ( 250 ) ;
V_4 = V_1 -> V_15 -> V_31 ( V_1 ) ;
if ( V_32 && V_1 -> V_15 -> V_33 )
V_1 -> V_15 -> V_33 ( V_1 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static int F_17 ( struct V_5 * V_5 )
{
struct V_1 * V_1 = (struct V_1 * ) V_5 ;
F_4 ( V_30 , L_15 ) ;
V_5 -> V_34 . V_35 = & V_5 -> V_35 ;
return V_1 -> V_15 -> V_36 ( V_1 ) ;
}
static int F_18 ( struct V_5 * V_5 )
{
struct V_1 * V_1 = (struct V_1 * ) V_5 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
int V_4 , V_41 ;
V_40 = F_19 ( V_1 -> V_5 . V_8 , V_1 -> V_5 . V_42 ) ;
V_38 = F_20 ( V_40 , V_1 -> V_5 . V_38 ) ;
if ( ! V_38 ) {
F_21 ( L_16 ) ;
return - V_43 ;
}
V_41 = F_22 ( V_38 -> V_44 [ 0 ] . V_45 . V_46 ) ;
V_4 = F_1 ( V_1 , V_47 , V_41 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = V_1 -> V_15 -> V_48 ( V_1 ) ;
if ( V_4 < 0 )
goto V_49;
V_4 = F_1 ( V_1 , V_50 , 1 ) ;
V_49:
if ( V_4 < 0 )
F_4 ( V_51 , L_17 ) ;
else
F_4 ( V_51 , L_18 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static int F_23 ( struct V_5 * V_5 )
{
struct V_37 * V_38 ;
struct V_1 * V_1 = (struct V_1 * ) V_5 ;
V_38 = & V_5 -> V_8 -> V_52 -> V_53 [ 0 ] -> V_54 [ 1 ] ;
V_38 -> V_44 [ 0 ] . V_45 . V_46 =
F_24 ( V_1 -> V_15 -> V_55 [ V_5 -> V_56 ] ) ;
return 0 ;
}
static int F_25 ( struct V_5 * V_5 )
{
int V_57 , V_41 , V_58 ;
struct V_37 * V_38 ;
struct V_1 * V_1 = (struct V_1 * ) V_5 ;
V_38 = & V_5 -> V_8 -> V_52 -> V_53 [ 0 ] -> V_54 [ 1 ] ;
V_41 = F_22 ( V_38 -> V_44 [ 0 ] . V_45 . V_46 ) ;
V_58 = V_1 -> V_15 -> V_58 [ V_5 -> V_56 ] ;
if ( V_41 <= V_58 )
return - V_43 ;
V_41 -= 100 ;
if ( V_41 < V_58 )
V_41 = V_58 ;
V_38 -> V_44 [ 0 ] . V_45 . V_46 = F_24 ( V_41 ) ;
V_57 = F_26 ( V_5 -> V_8 , V_5 -> V_42 , 1 ) ;
if ( V_57 < 0 )
F_21 ( L_19 , V_57 ) ;
return V_57 ;
}
static void F_27 ( struct V_5 * V_5 )
{
int V_4 ;
struct V_1 * V_1 = (struct V_1 * ) V_5 ;
V_4 = F_1 ( V_1 , V_50 , 0 ) ;
if ( V_4 < 0 )
goto V_49;
V_4 = V_1 -> V_15 -> V_59 ( V_1 ) ;
V_49:
if ( V_4 < 0 )
F_4 ( V_51 , L_20 ) ;
else
F_4 ( V_51 , L_21 ) ;
}
static void F_28 ( struct V_5 * V_5 ,
T_3 * V_17 ,
int V_11 )
{
struct V_1 * V_1 = (struct V_1 * ) V_5 ;
F_4 ( V_60 , L_22 , V_11 ) ;
while ( V_11 ) {
int V_61 , V_62 ;
if ( V_11 < 4 ) {
F_4 ( V_60 , L_23 ) ;
return;
}
V_61 = ( V_17 [ 0 ] << 8 ) | V_17 [ 1 ] ;
V_62 = ( V_17 [ 2 ] << 8 ) | V_17 [ 3 ] ;
F_4 ( V_60 , L_24 , V_61 , V_62 ) ;
V_17 += 4 ;
V_11 -= 4 ;
if ( V_11 < V_62 ) {
F_21 ( L_25
L_26 ) ;
V_5 -> V_63 = V_64 ;
return;
}
if ( V_1 -> V_18 == V_65 && ( V_61 & 0xff00 ) == 0x0200 )
goto V_66;
switch ( V_61 ) {
case 0x0200 :
case 0x4200 :
V_66:
F_4 ( V_60 , L_27 ) ;
if ( V_1 -> V_67 ) {
int V_68 = ( V_1 -> V_67 < V_62 ) ?
V_1 -> V_67 : V_62 ;
V_17 += V_68 ;
V_11 -= V_68 ;
V_62 -= V_68 ;
V_1 -> V_67 -= V_68 ;
}
F_29 ( V_5 , V_69 ,
V_17 , V_62 ) ;
break;
case 0x8001 :
case 0x8005 :
case 0xc001 :
case 0xc005 :
F_4 ( V_60 , L_28 ) ;
F_29 ( V_5 , V_70 ,
NULL , 0 ) ;
if ( V_1 -> V_18 == V_65 )
V_1 -> V_67 = V_5 -> V_71 . V_72 * 4 ;
if ( V_62 )
F_21 ( L_29
L_30 ) ;
break;
case 0x8002 :
case 0x8006 :
case 0xc002 :
F_4 ( V_60 , L_31 ) ;
F_29 ( V_5 , V_73 ,
NULL , 0 ) ;
if ( V_62 )
F_21 ( L_29
L_32 ) ;
break;
case 0x0005 :
F_4 ( V_60 , L_33 ) ;
break;
case 0x0100 :
F_4 ( V_60 , L_34 ) ;
break;
case 0x42ff :
F_4 ( V_60 , L_35 ) ;
break;
default:
F_4 ( V_60 , L_36 , V_61 ) ;
}
V_17 += V_62 ;
V_11 -= V_62 ;
}
}
static int F_30 ( struct V_5 * V_5 ,
T_3 * V_17 ,
int V_11 )
{
int V_57 = - V_74 ;
if ( V_11 == 1 && V_17 [ 0 ] == 0x80 ) {
F_31 ( V_5 -> V_75 , V_76 , 1 ) ;
F_32 ( V_5 -> V_75 ) ;
V_57 = 0 ;
}
if ( V_11 == 1 && V_17 [ 0 ] == 0x88 ) {
F_31 ( V_5 -> V_75 , V_76 , 0 ) ;
F_32 ( V_5 -> V_75 ) ;
V_57 = 0 ;
}
return V_57 ;
}
static int F_33 ( struct V_5 * V_5 ,
const struct V_77 * V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_5 ;
F_4 ( V_30 , L_37 ) ;
V_1 -> V_18 = V_61 -> V_78 ;
V_5 -> V_79 = & V_79 ;
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
static int F_34 ( struct V_39 * V_40 ,
const struct V_77 * V_61 )
{
return F_35 ( V_40 , V_61 , & V_79 , sizeof( struct V_1 ) ,
V_88 ) ;
}
static void F_36 ( struct V_39 * V_40 )
{
struct V_5 * V_5 = F_37 ( V_40 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_5 ;
void * V_89 = V_1 -> V_90 ;
F_4 ( V_30 , L_38 ) ;
V_1 -> V_15 = NULL ;
F_38 ( V_40 ) ;
F_39 ( V_89 ) ;
}
