static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , void * V_4 , int V_5 )
{
int V_6 ;
if ( ! V_2 )
return - V_7 ;
V_6 = F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
0x00 ,
( V_8 | V_9 | V_10 ) ,
0x00 ,
V_3 , V_4 , V_5 , 50000 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
int V_6 ;
if ( ! V_2 )
return - V_7 ;
V_6 = F_2 ( V_2 , F_5 ( V_2 , 0 ) ,
0x01 ,
( V_12 | V_9 | V_10 ) ,
V_11 , V_3 , NULL , 0 , 500 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_13 ) {
T_1 V_14 = 0 ;
V_6 = F_1 ( V_2 , V_3 , & V_14 , sizeof( V_14 ) ) ;
V_14 = 0xFF & V_14 ;
switch ( V_3 ) {
case 0x000 :
case 0x500 :
case 0x502 :
case 0x503 :
case 0x504 :
case 0x506 :
case 0x507 :
break;
case 0x204 :
case 0x205 :
case 0x350 :
case 0x351 :
if ( V_14 )
F_6 ( 8 , L_1
L_2 ,
V_14 , V_3 ) ;
break;
default:
if ( ( 0xFF & V_11 ) != V_14 )
F_6 ( 8 , L_3
L_2 ,
V_14 , V_11 , V_3 ) ;
break;
}
}
return V_6 ;
}
static int F_7 ( struct V_1 * V_15 )
{
T_1 V_16 ;
T_2 V_14 ;
const int V_17 = 2 ;
int V_18 ;
if ( ! V_15 )
return - V_7 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
F_8 ( V_15 , 0x0201 , & V_14 ) ; V_16 = V_14 ;
switch ( V_16 ) {
case 0x04 :
case 0x01 :
return 0 ;
case 0x00 :
F_9 ( 20 ) ;
continue;
default:
return V_16 - 1 ;
}
}
return - 1 ;
}
int F_10 ( struct V_1 * V_15 , T_1 V_19 , T_1 V_20 )
{
if ( ! V_15 )
return - V_7 ;
F_11 ( V_15 , 0x200 , 0x00 ) ;
F_11 ( V_15 , 0x204 , V_19 ) ;
F_11 ( V_15 , 0x205 , V_20 ) ;
F_11 ( V_15 , 0x200 , 0x01 ) ;
return F_7 ( V_15 ) ;
}
static int F_12 ( struct V_1 * V_15 , T_1 V_19 , T_1 V_20 )
{
T_2 V_14 ;
T_1 V_21 , V_22 ;
T_1 V_23 , V_24 ;
if ( ! V_15 )
return - V_7 ;
F_11 ( V_15 , 0x0504 , V_19 ) ;
F_11 ( V_15 , 0x0500 , 0x008B ) ;
F_8 ( V_15 , 0x0502 , & V_14 ) ; V_21 = ( 0xFF & V_14 ) ;
F_8 ( V_15 , 0x0503 , & V_14 ) ; V_22 = ( 0xFF & V_14 ) ;
F_6 ( 16 , L_4 ,
V_19 , V_20 , ( ( V_22 << 8 ) | V_21 ) ) ;
V_23 = ( 0x00FF & V_20 ) ;
V_24 = ( ( 0xFF00 & V_20 ) >> 8 ) ;
F_11 ( V_15 , 0x0504 , V_19 ) ;
F_11 ( V_15 , 0x0502 , V_23 ) ;
F_11 ( V_15 , 0x0503 , V_24 ) ;
F_11 ( V_15 , 0x0500 , 0x008C ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_15 , T_1 V_19 )
{
T_2 V_14 ;
T_1 V_21 , V_22 ;
if ( ! V_15 )
return - V_7 ;
F_11 ( V_15 , 0x0504 , V_19 ) ;
F_11 ( V_15 , 0x0500 , 0x008B ) ;
F_8 ( V_15 , 0x0502 , & V_14 ) ; V_21 = ( 0xFF & V_14 ) ;
F_8 ( V_15 , 0x0503 , & V_14 ) ; V_22 = ( 0xFF & V_14 ) ;
F_6 ( 16 , L_5 ,
V_19 , ( ( V_22 << 8 ) | V_21 ) ) ;
return ( V_22 << 8 ) | V_21 ;
}
static int F_14 ( struct V_1 * V_15 )
{
if ( ! V_15 )
return - V_7 ;
F_11 ( V_15 , 0x300 , 0x0012 ) ;
F_11 ( V_15 , 0x350 , 0x002D ) ;
F_11 ( V_15 , 0x351 , 0x0001 ) ;
F_11 ( V_15 , 0x352 , 0x0000 ) ;
F_11 ( V_15 , 0x353 , 0x0000 ) ;
F_11 ( V_15 , 0x300 , 0x0080 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_15 , bool V_25 )
{
int V_26 ;
const struct V_27 * V_28 ;
if ( ! V_15 )
return - V_7 ;
V_28 = ( V_25 ) ? V_29 : V_30 ;
for ( V_26 = 0 ; V_28 [ V_26 ] . V_4 != 0xFFF ; V_26 ++ )
F_11 ( V_15 , V_28 [ V_26 ] . V_4 , V_28 [ V_26 ] . V_31 ) ;
F_14 ( V_15 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_15 , bool V_25 )
{
int V_26 , V_6 ;
const struct V_32 * V_28 ;
if ( ! V_15 )
return - V_7 ;
V_28 = ( V_25 ) ? V_33 : V_34 ;
for ( V_26 = 0 ; V_28 [ V_26 ] . V_4 != 0xFF ; V_26 ++ ) {
V_6 = F_10 ( V_15 , V_28 [ V_26 ] . V_4 , V_28 [ V_26 ] . V_31 ) ;
if ( V_6 )
F_17 ( & V_15 -> V_35 ,
L_6 , V_28 [ V_26 ] . V_4 ) ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_15 )
{
int V_6 ;
if ( ! V_15 )
return - V_7 ;
V_6 = F_19 ( V_15 , 0x1F ) ;
return ( ( 0 > V_6 ) || ( 0x02 & V_6 ) ) ? 1 : 0 ;
}
int F_20 ( struct V_1 * V_15 )
{
int V_36 , V_6 , V_37 ;
const int V_17 = 5 , V_38 = V_39 / 5 ;
if ( ! V_15 )
return - V_7 ;
V_36 = 0 ;
while ( V_17 > V_36 ) {
V_6 = F_19 ( V_15 , 0x1F ) ;
if ( 0 <= V_6 ) {
if ( 0 == ( 0x40 & V_6 ) )
break;
if ( 1 == ( 0x01 & V_6 ) )
break;
}
F_9 ( V_38 ) ;
V_36 ++ ;
}
if ( V_17 == V_36 )
return - 1 ;
if ( 0x20 & V_6 ) {
V_37 = 2 ;
F_6 ( 8 , L_7 ) ;
} else {
V_37 = 0 ;
F_6 ( 8 , L_8 ) ;
}
if ( 0x80 & V_6 )
F_6 ( 8 , L_9 ) ;
else {
V_37 ++ ;
F_6 ( 8 , L_10 ) ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_15 , T_1 V_19 )
{
T_2 V_14 ;
if ( ! V_15 )
return - V_7 ;
F_11 ( V_15 , 0x208 , V_19 ) ;
F_11 ( V_15 , 0x200 , 0x20 ) ;
if ( 0 != F_7 ( V_15 ) )
return - 1 ;
V_14 = 0 ;
F_8 ( V_15 , 0x0209 , & V_14 ) ;
return V_14 ;
}
static int F_21 ( struct V_1 * V_15 , T_3 V_19 )
{
T_2 V_14 ;
if ( ! V_15 )
return - V_7 ;
V_14 = 0 ;
F_8 ( V_15 , V_19 , & V_14 ) ;
return V_14 ;
}
int F_22 ( struct V_1 * V_15 , int V_40 , int V_41 )
{
int V_42 ;
if ( ! V_15 )
return - V_7 ;
F_23 ( V_15 ) ;
switch ( V_40 ) {
case 0 :
case 1 : {
if ( 0 != F_10 ( V_15 , 0x02 , 0x80 ) )
F_24 ( L_11
L_12 , V_40 ) ;
F_11 ( V_15 , 0x0000 , 0x0098 ) ;
F_11 ( V_15 , 0x0002 , 0x0078 ) ;
break;
}
case 2 : {
if ( 0 != F_10 ( V_15 , 0x02 , 0x80 ) )
F_24 ( L_11
L_12 , V_40 ) ;
F_11 ( V_15 , 0x0000 , 0x0090 ) ;
F_11 ( V_15 , 0x0002 , 0x0078 ) ;
break;
}
case 3 : {
if ( 0 != F_10 ( V_15 , 0x02 , 0x80 ) )
F_24 ( L_11
L_13 , V_40 ) ;
F_11 ( V_15 , 0x0000 , 0x0088 ) ;
F_11 ( V_15 , 0x0002 , 0x0078 ) ;
break;
}
case 4 : {
if ( 0 != F_10 ( V_15 , 0x02 , 0x80 ) ) {
F_24 ( L_11
L_12 , V_40 ) ;
}
F_11 ( V_15 , 0x0000 , 0x0080 ) ;
F_11 ( V_15 , 0x0002 , 0x0078 ) ;
break;
}
case 5 : {
if ( 9 != V_41 )
V_41 = 7 ;
switch ( V_41 ) {
case 7 : {
if ( 0 != F_10 ( V_15 , 0x02 , 0x87 ) )
F_24 ( L_11
L_12 , V_40 ) ;
if ( 0 != F_10 ( V_15 , 0x05 , 0xFF ) )
F_24 ( L_14
L_12 , V_40 ) ;
break;
}
case 9 : {
if ( 0 != F_10 ( V_15 , 0x02 , 0x89 ) )
F_24 ( L_11
L_12 , V_40 ) ;
if ( 0 != F_10 ( V_15 , 0x05 , 0x00 ) )
F_24 ( L_14
L_12 , V_40 ) ;
break;
}
default:
F_24 ( L_15 , V_41 ) ;
return - 1 ;
}
if ( 0 != F_10 ( V_15 , 0x04 , 0x00 ) )
F_24 ( L_16
L_12 , V_40 ) ;
if ( 0 != F_10 ( V_15 , 0x09 , 0x80 ) )
F_24 ( L_17
L_12 , V_40 ) ;
F_11 ( V_15 , 0x0002 , 0x0093 ) ;
break;
}
default:
F_24 ( L_18 , V_40 ) ;
return - 1 ;
}
V_42 = F_21 ( V_15 , 0x00 ) ;
F_6 ( 8 , L_19 , V_42 ) ;
V_42 = F_19 ( V_15 , 0x02 ) ;
F_6 ( 8 , L_20 , V_42 ) ;
F_25 ( V_15 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_15 ,
T_1 V_20 , T_1 V_43 , T_1 V_44 , T_1 V_45 )
{
T_1 V_46 , V_47 , V_48 , V_49 ;
if ( ! V_15 )
return - V_7 ;
V_46 = ( ( 0xFF00 & V_20 ) >> 8 ) ;
V_47 = ( ( 0xFF00 & V_43 ) >> 8 ) ;
V_48 = ( ( 0xFF00 & V_44 ) >> 8 ) ;
V_49 = ( ( 0xFF00 & V_45 ) >> 8 ) ;
F_11 ( V_15 , 0x0110 , ( 0x00FF & V_20 ) ) ;
F_11 ( V_15 , 0x0111 , V_46 ) ;
F_11 ( V_15 , 0x0112 , ( 0x00FF & V_43 ) ) ;
F_11 ( V_15 , 0x0113 , V_47 ) ;
F_11 ( V_15 , 0x0114 , ( 0x00FF & V_44 ) ) ;
F_11 ( V_15 , 0x0115 , V_48 ) ;
F_11 ( V_15 , 0x0116 , ( 0x00FF & V_45 ) ) ;
F_11 ( V_15 , 0x0117 , V_49 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_15 )
{
T_1 V_50 , V_51 , V_16 ;
T_2 V_52 , V_53 , V_14 ;
if ( ! V_15 )
return - V_7 ;
F_8 ( V_15 , 0x0116 , & V_52 ) ;
V_50 = V_52 ;
F_8 ( V_15 , 0x0117 , & V_53 ) ;
V_51 = V_53 ;
F_11 ( V_15 , 0x0116 , 0x0000 ) ;
F_11 ( V_15 , 0x0117 , 0x0000 ) ;
F_8 ( V_15 , 0x0100 , & V_14 ) ;
V_16 = V_14 ;
F_11 ( V_15 , 0x0100 , ( 0x80 | V_16 ) ) ;
F_11 ( V_15 , 0x0116 , V_50 ) ;
F_11 ( V_15 , 0x0117 , V_51 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_15 )
{
T_1 V_16 ;
T_2 V_14 ;
if ( ! V_15 )
return - V_7 ;
F_8 ( V_15 , 0x0100 , & V_14 ) ;
V_16 = V_14 ;
F_11 ( V_15 , 0x0100 , ( 0x7F & V_16 ) ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_7 ;
return F_2 ( V_2 , F_5 ( V_2 , 0 ) ,
V_54 ,
V_12 | V_55 | V_10 ,
V_56 ,
0 , NULL , 0 , 50000 ) ;
}
int F_28 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
T_2 V_59 [ 1 ] ;
int V_6 , V_60 , V_61 ;
const T_2 V_62 = 0x01 ;
const T_2 V_63 = V_12 |
V_64 |
V_65 ;
const T_1 V_66 = 0x0200 ;
const T_1 V_3 = 0x0301 ;
const T_1 V_67 = 1 ;
if ( ! V_58 )
return - V_68 ;
V_2 = V_58 -> V_2 ;
if ( ! V_2 )
return - V_7 ;
F_29 ( 8 , L_21 ,
V_63 , V_62 ,
( 0x00FF & V_66 ) ,
( 0xFF00 & V_66 ) >> 8 ,
( 0x00FF & V_3 ) ,
( 0xFF00 & V_3 ) >> 8 ,
( 0x00FF & V_67 ) ,
( 0xFF00 & V_67 ) >> 8 ) ;
V_59 [ 0 ] = 0x01 ;
V_6 = F_2 ( V_2 , F_5 ( V_2 , 0 ) ,
V_62 , V_63 , V_66 ,
V_3 , & V_59 [ 0 ] , V_67 , 50000 ) ;
F_6 ( 8 , L_22 , V_59 [ 0 ] ) ;
if ( V_6 != ( int ) V_67 ) {
switch ( V_6 ) {
case - V_69 :
F_24 ( L_23 ) ;
break;
default:
F_24 ( L_24 , V_6 ) ;
break;
}
}
F_11 ( V_2 , 0x0500 , 0x0094 ) ;
F_11 ( V_2 , 0x0500 , 0x008C ) ;
F_11 ( V_2 , 0x0506 , 0x0001 ) ;
F_11 ( V_2 , 0x0507 , 0x0000 ) ;
V_60 = F_13 ( V_2 , 0x007C ) ;
V_61 = F_13 ( V_2 , 0x007E ) ;
F_30 ( L_25 , V_60 , V_61 ) ;
if ( F_31 ( V_2 , V_58 -> V_70 ) )
F_24 ( L_26 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_14 ;
if ( ! V_2 )
return - V_7 ;
V_14 = F_13 ( V_2 , 0x0002 ) ;
if ( 0 > V_14 )
F_24 ( L_27 ) ;
if ( 0x8000 & V_14 )
F_24 ( L_28 , 0x02 ) ;
V_14 = F_13 ( V_2 , 0x000E ) ;
if ( 0 > V_14 )
F_24 ( L_29 ) ;
if ( 0x8000 & V_14 )
F_24 ( L_28 , 0x0E ) ;
V_14 = F_13 ( V_2 , 0x0010 ) ;
if ( 0 > V_14 )
F_24 ( L_30 ) ;
if ( 0x8000 & V_14 )
F_24 ( L_28 , 0x10 ) ;
V_14 = F_13 ( V_2 , 0x0012 ) ;
if ( 0 > V_14 )
F_24 ( L_31 ) ;
if ( 0x8000 & V_14 )
F_24 ( L_28 , 0x12 ) ;
V_14 = F_13 ( V_2 , 0x0014 ) ;
if ( 0 > V_14 )
F_24 ( L_32 ) ;
if ( 0x8000 & V_14 )
F_24 ( L_28 , 0x14 ) ;
V_14 = F_13 ( V_2 , 0x0016 ) ;
if ( 0 > V_14 )
F_24 ( L_33 ) ;
if ( 0x8000 & V_14 )
F_24 ( L_28 , 0x16 ) ;
V_14 = F_13 ( V_2 , 0x0018 ) ;
if ( 0 > V_14 )
F_24 ( L_34 ) ;
if ( 0x8000 & V_14 )
F_24 ( L_28 , 0x18 ) ;
V_14 = F_13 ( V_2 , 0x001C ) ;
if ( 0 > V_14 )
F_24 ( L_35 ) ;
if ( 0x8000 & V_14 )
F_24 ( L_28 , 0x1C ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , T_4 V_71 )
{
int V_14 ;
T_2 V_72 ;
T_1 V_73 ;
if ( ! V_2 )
return - V_7 ;
if ( 0 > V_71 )
V_71 = 0 ;
if ( 31 < V_71 )
V_71 = 31 ;
F_12 ( V_2 , 0x0002 , 0x8000 ) ;
V_14 = F_13 ( V_2 , 0x000E ) ;
if ( 0 > V_14 ) {
F_24 ( L_29 ) ;
V_73 = 0x0000 ;
} else
V_73 = 0x8000 & ( ( unsigned int ) V_14 ) ;
V_73 = 0 ;
if ( 16 > V_71 )
V_72 = 0x01 | ( 0x001F & ( ( ( T_2 ) ( 15 - V_71 ) ) << 1 ) ) ;
else
V_72 = 0 ;
F_6 ( 8 , L_36 , V_73 | V_72 ) ;
F_12 ( V_2 , 0x000E , ( V_73 | V_72 ) ) ;
V_14 = F_13 ( V_2 , 0x0010 ) ;
if ( 0 > V_14 ) {
F_24 ( L_30 ) ;
V_73 = 0x0000 ;
} else
V_73 = 0x8000 & ( ( unsigned int ) V_14 ) ;
V_73 = 0 ;
F_6 ( 8 , L_37 ,
V_73 | V_72 | ( V_72 << 8 ) ) ;
F_12 ( V_2 , 0x0010 , ( V_73 | V_72 | ( V_72 << 8 ) ) ) ;
F_12 ( V_2 , 0x0012 , ( V_73 | V_72 | ( V_72 << 8 ) ) ) ;
F_12 ( V_2 , 0x0014 , ( V_73 | V_72 | ( V_72 << 8 ) ) ) ;
F_12 ( V_2 , 0x0016 , ( V_73 | V_72 | ( V_72 << 8 ) ) ) ;
F_12 ( V_2 , 0x0018 , ( V_73 | V_72 | ( V_72 << 8 ) ) ) ;
V_14 = F_13 ( V_2 , 0x001C ) ;
if ( 0 > V_14 ) {
F_24 ( L_35 ) ;
V_73 = 0x0000 ;
} else
V_73 = 0x8000 & ( ( unsigned int ) V_14 ) ;
V_73 = 0 ;
if ( 16 <= V_71 )
V_72 = 0x000F & ( T_2 ) ( V_71 - 16 ) ;
else
V_72 = 0 ;
F_6 ( 8 , L_38 ,
V_73 | V_72 | ( V_72 << 8 ) ) ;
F_12 ( V_2 , 0x001C , ( V_73 | V_72 | ( V_72 << 8 ) ) ) ;
F_12 ( V_2 , 0x001A , 0x0404 ) ;
F_12 ( V_2 , 0x0002 , 0x0000 ) ;
return 0 ;
}
