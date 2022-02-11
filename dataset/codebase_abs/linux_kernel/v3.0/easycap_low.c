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
int F_10 ( struct V_1 * V_15 )
{
T_2 V_16 , V_19 , V_20 , V_21 , V_22 , V_23 , V_24 , V_25 ;
if ( ! V_15 )
return - V_7 ;
F_8 ( V_15 , 0x0110 , & V_16 ) ;
F_8 ( V_15 , 0x0111 , & V_19 ) ;
F_8 ( V_15 , 0x0112 , & V_20 ) ;
F_8 ( V_15 , 0x0113 , & V_21 ) ;
F_8 ( V_15 , 0x0114 , & V_22 ) ;
F_8 ( V_15 , 0x0115 , & V_23 ) ;
F_8 ( V_15 , 0x0116 , & V_24 ) ;
F_8 ( V_15 , 0x0117 , & V_25 ) ;
F_6 ( 8 , L_4
L_4
L_4
L_5 ,
V_16 , V_19 , V_20 , V_21 , V_22 , V_23 , V_24 , V_25 ) ;
F_6 ( 8 , L_6
L_4
L_4
L_4
L_5 ,
0x000 , 0x000 , 0x001 , 0x000 , 0x5A0 , 0x005 , 0x121 , 0x001 ) ;
F_6 ( 8 , L_7
L_4
L_4
L_4
L_5 ,
0x004 , 0x000 , 0x001 , 0x000 , 0x584 , 0x005 , 0x121 , 0x001 ) ;
F_6 ( 8 , L_8
L_4
L_4
L_4
L_5 ,
0x008 , 0x000 , 0x020 , 0x000 , 0x508 , 0x005 , 0x110 , 0x001 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_15 )
{
T_1 V_20 ;
T_2 V_14 ;
if ( ! V_15 )
return - V_7 ;
F_8 ( V_15 , 0x0100 , & V_14 ) ; V_20 = 0x80 & V_14 ;
if ( 0x80 == V_20 )
F_6 ( 8 , L_9 ) ;
else
F_6 ( 8 , L_10 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_15 , bool V_26 )
{
int V_27 ;
const struct V_28 * V_29 ;
if ( ! V_15 )
return - V_7 ;
V_29 = ( V_26 ) ? V_30 : V_31 ;
for ( V_27 = 0 ; V_29 [ V_27 ] . V_4 != 0xFFF ; V_27 ++ )
F_13 ( V_15 , V_29 [ V_27 ] . V_4 , V_29 [ V_27 ] . V_32 ) ;
F_14 ( V_15 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_15 , bool V_26 )
{
int V_27 , V_33 ;
const struct V_34 * V_29 ;
if ( ! V_15 )
return - V_7 ;
V_29 = ( V_26 ) ? V_35 : V_36 ;
for ( V_27 = 0 ; V_29 [ V_27 ] . V_4 != 0xFF ; V_27 ++ )
V_33 = F_16 ( V_15 , V_29 [ V_27 ] . V_4 , V_29 [ V_27 ] . V_32 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_15 , T_1 V_37 , T_1 V_38 )
{
T_2 V_39 , V_40 ;
if ( ! V_15 )
return - V_7 ;
F_8 ( V_15 , 0x0002 , & V_40 ) ;
F_8 ( V_15 , 0x0000 , & V_39 ) ;
F_13 ( V_15 , 0x0002 , V_37 ) ;
F_13 ( V_15 , 0x0000 , V_38 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_15 , T_1 V_41 , T_1 V_38 )
{
if ( ! V_15 )
return - V_7 ;
F_13 ( V_15 , 0x200 , 0x00 ) ;
F_13 ( V_15 , 0x204 , V_41 ) ;
F_13 ( V_15 , 0x205 , V_38 ) ;
F_13 ( V_15 , 0x200 , 0x01 ) ;
return F_7 ( V_15 ) ;
}
int
F_18 ( struct V_1 * V_15 , T_1 V_41 , T_1 V_38 )
{
T_2 V_14 ;
T_1 V_42 , V_43 ;
T_1 V_44 , V_45 ;
if ( ! V_15 )
return - V_7 ;
F_13 ( V_15 , 0x0504 , V_41 ) ;
F_13 ( V_15 , 0x0500 , 0x008B ) ;
F_8 ( V_15 , 0x0502 , & V_14 ) ; V_42 = ( 0xFF & V_14 ) ;
F_8 ( V_15 , 0x0503 , & V_14 ) ; V_43 = ( 0xFF & V_14 ) ;
F_6 ( 16 , L_11 ,
V_41 , V_38 , ( ( V_43 << 8 ) | V_42 ) ) ;
V_44 = ( 0x00FF & V_38 ) ;
V_45 = ( ( 0xFF00 & V_38 ) >> 8 ) ;
F_13 ( V_15 , 0x0504 , V_41 ) ;
F_13 ( V_15 , 0x0502 , V_44 ) ;
F_13 ( V_15 , 0x0503 , V_45 ) ;
F_13 ( V_15 , 0x0500 , 0x008C ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_15 , T_1 V_41 )
{
T_2 V_14 ;
T_1 V_42 , V_43 ;
if ( ! V_15 )
return - V_7 ;
F_13 ( V_15 , 0x0504 , V_41 ) ;
F_13 ( V_15 , 0x0500 , 0x008B ) ;
F_8 ( V_15 , 0x0502 , & V_14 ) ; V_42 = ( 0xFF & V_14 ) ;
F_8 ( V_15 , 0x0503 , & V_14 ) ; V_43 = ( 0xFF & V_14 ) ;
F_6 ( 16 , L_12 ,
V_41 , ( ( V_43 << 8 ) | V_42 ) ) ;
return ( V_43 << 8 ) | V_42 ;
}
int F_14 ( struct V_1 * V_15 )
{
if ( ! V_15 )
return - V_7 ;
F_13 ( V_15 , 0x300 , 0x0012 ) ;
F_13 ( V_15 , 0x350 , 0x002D ) ;
F_13 ( V_15 , 0x351 , 0x0001 ) ;
F_13 ( V_15 , 0x352 , 0x0000 ) ;
F_13 ( V_15 , 0x353 , 0x0000 ) ;
F_13 ( V_15 , 0x300 , 0x0080 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_15 , bool V_26 )
{
int V_27 , V_33 , V_6 = 0 ;
struct V_34 const * V_29 ;
if ( ! V_15 )
return - V_7 ;
V_29 = ( V_26 ) ? V_35 : V_36 ;
for ( V_27 = 0 ; V_29 [ V_27 ] . V_4 != 0xFF ; V_27 ++ ) {
if ( 0x0F == V_29 [ V_27 ] . V_4 )
continue;
V_33 = F_21 ( V_15 , V_29 [ V_27 ] . V_4 ) ;
if ( V_33 != V_29 [ V_27 ] . V_32 ) {
F_22 ( L_13 ,
V_29 [ V_27 ] . V_4 , V_33 , V_29 [ V_27 ] . V_32 ) ;
V_6 -- ;
}
}
return ( V_6 < - 8 ) ? V_6 : 0 ;
}
int F_23 ( struct V_1 * V_15 )
{
int V_6 ;
if ( ! V_15 )
return - V_7 ;
V_6 = F_21 ( V_15 , 0x1F ) ;
return ( ( 0 > V_6 ) || ( 0x02 & V_6 ) ) ? 1 : 0 ;
}
int F_24 ( struct V_1 * V_15 )
{
int V_46 , V_6 , V_47 ;
const int V_17 = 5 , V_48 = V_49 / 5 ;
if ( ! V_15 )
return - V_7 ;
V_46 = 0 ;
while ( V_17 > V_46 ) {
V_6 = F_21 ( V_15 , 0x1F ) ;
if ( 0 <= V_6 ) {
if ( 0 == ( 0x40 & V_6 ) )
break;
if ( 1 == ( 0x01 & V_6 ) )
break;
}
F_9 ( V_48 ) ;
V_46 ++ ;
}
if ( V_17 == V_46 )
return - 1 ;
else {
if ( 0x20 & V_6 ) {
V_47 = 2 ;
F_6 ( 8 , L_14 ) ;
} else {
V_47 = 0 ;
F_6 ( 8 , L_15 ) ;
}
if ( 0x80 & V_6 )
F_6 ( 8 , L_16 ) ;
else {
V_47 ++ ;
F_6 ( 8 , L_17 ) ;
}
}
return 0 ;
}
int F_25 ( struct V_1 * V_15 , bool V_26 )
{
int V_27 , V_33 ;
const struct V_28 * V_29 ;
if ( ! V_15 )
return - V_7 ;
V_29 = ( V_26 ) ? V_30 : V_31 ;
for ( V_27 = 0 ; 0xFFF != V_29 [ V_27 ] . V_4 ; V_27 ++ ) {
if ( 0x000 == V_29 [ V_27 ] . V_4 || 0x002 == V_29 [ V_27 ] . V_4 )
continue;
V_33 = F_26 ( V_15 , V_29 [ V_27 ] . V_4 ) ;
if ( 0x100 == V_29 [ V_27 ] . V_4 ) {
if ( ( V_33 != ( 0xFF & V_29 [ V_27 ] . V_32 ) ) &&
( V_33 != ( 0x80 | ( 0xFF & V_29 [ V_27 ] . V_32 ) ) ) &&
( 0xFFFF != V_29 [ V_27 ] . V_32 ) ) {
F_22 ( L_18 ,
V_29 [ V_27 ] . V_4 , V_33 , V_29 [ V_27 ] . V_32 ) ;
}
continue;
}
if ( ( V_33 != ( 0xFF & V_29 [ V_27 ] . V_32 ) ) && ( 0xFFFF != V_29 [ V_27 ] . V_32 ) )
F_22 ( L_19 ,
V_29 [ V_27 ] . V_4 , V_33 , V_29 [ V_27 ] . V_32 ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_15 , T_1 V_41 )
{
T_2 V_14 ;
if ( ! V_15 )
return - V_7 ;
F_13 ( V_15 , 0x208 , V_41 ) ;
F_13 ( V_15 , 0x200 , 0x20 ) ;
if ( 0 != F_7 ( V_15 ) )
return - 1 ;
V_14 = 0 ;
F_8 ( V_15 , 0x0209 , & V_14 ) ;
return V_14 ;
}
int F_26 ( struct V_1 * V_15 , T_3 V_41 )
{
T_2 V_14 ;
if ( ! V_15 )
return - V_7 ;
V_14 = 0 ;
F_8 ( V_15 , V_41 , & V_14 ) ;
return V_14 ;
}
int
F_27 ( struct V_1 * V_15 , int V_50 , int V_51 )
{
int V_33 ;
if ( ! V_15 )
return - V_7 ;
F_28 ( V_15 ) ;
switch ( V_50 ) {
case 0 :
case 1 : {
if ( 0 != F_16 ( V_15 , 0x02 , 0x80 ) )
F_22 ( L_20
L_21 , V_50 ) ;
F_13 ( V_15 , 0x0000 , 0x0098 ) ;
F_13 ( V_15 , 0x0002 , 0x0078 ) ;
break;
}
case 2 : {
if ( 0 != F_16 ( V_15 , 0x02 , 0x80 ) )
F_22 ( L_20
L_21 , V_50 ) ;
F_13 ( V_15 , 0x0000 , 0x0090 ) ;
F_13 ( V_15 , 0x0002 , 0x0078 ) ;
break;
}
case 3 : {
if ( 0 != F_16 ( V_15 , 0x02 , 0x80 ) )
F_22 ( L_20
L_22 , V_50 ) ;
F_13 ( V_15 , 0x0000 , 0x0088 ) ;
F_13 ( V_15 , 0x0002 , 0x0078 ) ;
break;
}
case 4 : {
if ( 0 != F_16 ( V_15 , 0x02 , 0x80 ) ) {
F_22 ( L_20
L_21 , V_50 ) ;
}
F_13 ( V_15 , 0x0000 , 0x0080 ) ;
F_13 ( V_15 , 0x0002 , 0x0078 ) ;
break;
}
case 5 : {
if ( 9 != V_51 )
V_51 = 7 ;
switch ( V_51 ) {
case 7 : {
if ( 0 != F_16 ( V_15 , 0x02 , 0x87 ) )
F_22 ( L_20
L_21 , V_50 ) ;
if ( 0 != F_16 ( V_15 , 0x05 , 0xFF ) )
F_22 ( L_23
L_21 , V_50 ) ;
break;
}
case 9 : {
if ( 0 != F_16 ( V_15 , 0x02 , 0x89 ) )
F_22 ( L_20
L_21 , V_50 ) ;
if ( 0 != F_16 ( V_15 , 0x05 , 0x00 ) )
F_22 ( L_23
L_21 , V_50 ) ;
break;
}
default:
F_22 ( L_24 , V_51 ) ;
return - 1 ;
}
if ( 0 != F_16 ( V_15 , 0x04 , 0x00 ) )
F_22 ( L_25
L_21 , V_50 ) ;
if ( 0 != F_16 ( V_15 , 0x09 , 0x80 ) )
F_22 ( L_26
L_21 , V_50 ) ;
F_13 ( V_15 , 0x0002 , 0x0093 ) ;
break;
}
default:
F_22 ( L_27 , V_50 ) ;
return - 1 ;
}
V_33 = F_26 ( V_15 , 0x00 ) ;
F_6 ( 8 , L_28 , V_33 ) ;
V_33 = F_21 ( V_15 , 0x02 ) ;
F_6 ( 8 , L_29 , V_33 ) ;
F_29 ( V_15 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_15 ,
T_1 V_38 , T_1 V_52 , T_1 V_37 , T_1 V_53 )
{
T_1 V_54 , V_55 , V_56 , V_57 ;
if ( ! V_15 )
return - V_7 ;
V_54 = ( ( 0xFF00 & V_38 ) >> 8 ) ;
V_55 = ( ( 0xFF00 & V_52 ) >> 8 ) ;
V_56 = ( ( 0xFF00 & V_37 ) >> 8 ) ;
V_57 = ( ( 0xFF00 & V_53 ) >> 8 ) ;
F_13 ( V_15 , 0x0110 , ( 0x00FF & V_38 ) ) ;
F_13 ( V_15 , 0x0111 , V_54 ) ;
F_13 ( V_15 , 0x0112 , ( 0x00FF & V_52 ) ) ;
F_13 ( V_15 , 0x0113 , V_55 ) ;
F_13 ( V_15 , 0x0114 , ( 0x00FF & V_37 ) ) ;
F_13 ( V_15 , 0x0115 , V_56 ) ;
F_13 ( V_15 , 0x0116 , ( 0x00FF & V_53 ) ) ;
F_13 ( V_15 , 0x0117 , V_57 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_15 )
{
T_1 V_58 , V_59 , V_16 ;
T_2 V_60 , V_61 , V_14 ;
if ( ! V_15 )
return - V_7 ;
F_8 ( V_15 , 0x0116 , & V_60 ) ;
V_58 = V_60 ;
F_8 ( V_15 , 0x0117 , & V_61 ) ;
V_59 = V_61 ;
F_13 ( V_15 , 0x0116 , 0x0000 ) ;
F_13 ( V_15 , 0x0117 , 0x0000 ) ;
F_8 ( V_15 , 0x0100 , & V_14 ) ;
V_16 = V_14 ;
F_13 ( V_15 , 0x0100 , ( 0x80 | V_16 ) ) ;
F_13 ( V_15 , 0x0116 , V_58 ) ;
F_13 ( V_15 , 0x0117 , V_59 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_15 )
{
T_1 V_16 ;
T_2 V_14 ;
if ( ! V_15 )
return - V_7 ;
F_8 ( V_15 , 0x0100 , & V_14 ) ;
V_16 = V_14 ;
F_13 ( V_15 , 0x0100 , ( 0x7F & V_16 ) ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_7 ;
return F_2 ( V_2 , F_5 ( V_2 , 0 ) ,
V_62 ,
V_12 | V_63 | V_10 ,
V_64 ,
0 , NULL , 0 , 50000 ) ;
}
int
F_32 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
T_2 V_67 [ 1 ] ;
int V_6 , V_68 , V_69 ;
const T_2 V_70 = 0x01 ;
const T_2 V_71 = V_12 |
V_72 |
V_73 ;
const T_1 V_74 = 0x0200 ;
const T_1 V_3 = 0x0301 ;
const T_1 V_75 = 1 ;
if ( ! V_66 )
return - V_76 ;
V_2 = V_66 -> V_2 ;
if ( ! V_2 )
return - V_7 ;
F_33 ( 8 , L_30 ,
V_71 , V_70 ,
( 0x00FF & V_74 ) ,
( 0xFF00 & V_74 ) >> 8 ,
( 0x00FF & V_3 ) ,
( 0xFF00 & V_3 ) >> 8 ,
( 0x00FF & V_75 ) ,
( 0xFF00 & V_75 ) >> 8 ) ;
V_67 [ 0 ] = 0x01 ;
V_6 = F_2 ( V_2 , F_5 ( V_2 , 0 ) ,
V_70 , V_71 , V_74 ,
V_3 , & V_67 [ 0 ] , V_75 , 50000 ) ;
F_6 ( 8 , L_31 , V_67 [ 0 ] ) ;
if ( V_6 != ( int ) V_75 ) {
switch ( V_6 ) {
case - V_77 :
F_22 ( L_32 ) ;
break;
default:
F_22 ( L_33 , V_6 ) ;
break;
}
}
F_13 ( V_2 , 0x0500 , 0x0094 ) ;
F_13 ( V_2 , 0x0500 , 0x008C ) ;
F_13 ( V_2 , 0x0506 , 0x0001 ) ;
F_13 ( V_2 , 0x0507 , 0x0000 ) ;
V_68 = F_19 ( V_2 , 0x007C ) ;
V_69 = F_19 ( V_2 , 0x007E ) ;
F_34 ( L_34 , V_68 , V_69 ) ;
if ( 0 != F_35 ( V_2 , V_66 -> V_78 ) )
F_22 ( L_35 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_14 ;
if ( ! V_2 )
return - V_7 ;
V_14 = F_19 ( V_2 , 0x0002 ) ;
if ( 0 > V_14 )
F_22 ( L_36 ) ;
if ( 0x8000 & V_14 )
F_22 ( L_37 , 0x02 ) ;
V_14 = F_19 ( V_2 , 0x000E ) ;
if ( 0 > V_14 )
F_22 ( L_38 ) ;
if ( 0x8000 & V_14 )
F_22 ( L_37 , 0x0E ) ;
V_14 = F_19 ( V_2 , 0x0010 ) ;
if ( 0 > V_14 )
F_22 ( L_39 ) ;
if ( 0x8000 & V_14 )
F_22 ( L_37 , 0x10 ) ;
V_14 = F_19 ( V_2 , 0x0012 ) ;
if ( 0 > V_14 )
F_22 ( L_40 ) ;
if ( 0x8000 & V_14 )
F_22 ( L_37 , 0x12 ) ;
V_14 = F_19 ( V_2 , 0x0014 ) ;
if ( 0 > V_14 )
F_22 ( L_41 ) ;
if ( 0x8000 & V_14 )
F_22 ( L_37 , 0x14 ) ;
V_14 = F_19 ( V_2 , 0x0016 ) ;
if ( 0 > V_14 )
F_22 ( L_42 ) ;
if ( 0x8000 & V_14 )
F_22 ( L_37 , 0x16 ) ;
V_14 = F_19 ( V_2 , 0x0018 ) ;
if ( 0 > V_14 )
F_22 ( L_43 ) ;
if ( 0x8000 & V_14 )
F_22 ( L_37 , 0x18 ) ;
V_14 = F_19 ( V_2 , 0x001C ) ;
if ( 0 > V_14 )
F_22 ( L_44 ) ;
if ( 0x8000 & V_14 )
F_22 ( L_37 , 0x1C ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , T_4 V_79 )
{
int V_14 ;
T_2 V_80 ;
T_1 V_81 ;
if ( ! V_2 )
return - V_7 ;
if ( 0 > V_79 )
V_79 = 0 ;
if ( 31 < V_79 )
V_79 = 31 ;
F_18 ( V_2 , 0x0002 , 0x8000 ) ;
V_14 = F_19 ( V_2 , 0x000E ) ;
if ( 0 > V_14 ) {
F_22 ( L_38 ) ;
V_81 = 0x0000 ;
} else
V_81 = 0x8000 & ( ( unsigned int ) V_14 ) ;
V_81 = 0 ;
if ( 16 > V_79 )
V_80 = 0x01 | ( 0x001F & ( ( ( T_2 ) ( 15 - V_79 ) ) << 1 ) ) ;
else
V_80 = 0 ;
F_6 ( 8 , L_45 , V_81 | V_80 ) ;
F_18 ( V_2 , 0x000E , ( V_81 | V_80 ) ) ;
V_14 = F_19 ( V_2 , 0x0010 ) ;
if ( 0 > V_14 ) {
F_22 ( L_39 ) ;
V_81 = 0x0000 ;
} else
V_81 = 0x8000 & ( ( unsigned int ) V_14 ) ;
V_81 = 0 ;
F_6 ( 8 , L_46 ,
V_81 | V_80 | ( V_80 << 8 ) ) ;
F_18 ( V_2 , 0x0010 , ( V_81 | V_80 | ( V_80 << 8 ) ) ) ;
F_18 ( V_2 , 0x0012 , ( V_81 | V_80 | ( V_80 << 8 ) ) ) ;
F_18 ( V_2 , 0x0014 , ( V_81 | V_80 | ( V_80 << 8 ) ) ) ;
F_18 ( V_2 , 0x0016 , ( V_81 | V_80 | ( V_80 << 8 ) ) ) ;
F_18 ( V_2 , 0x0018 , ( V_81 | V_80 | ( V_80 << 8 ) ) ) ;
V_14 = F_19 ( V_2 , 0x001C ) ;
if ( 0 > V_14 ) {
F_22 ( L_44 ) ;
V_81 = 0x0000 ;
} else
V_81 = 0x8000 & ( ( unsigned int ) V_14 ) ;
V_81 = 0 ;
if ( 16 <= V_79 )
V_80 = 0x000F & ( T_2 ) ( V_79 - 16 ) ;
else
V_80 = 0 ;
F_6 ( 8 , L_47 ,
V_81 | V_80 | ( V_80 << 8 ) ) ;
F_18 ( V_2 , 0x001C , ( V_81 | V_80 | ( V_80 << 8 ) ) ) ;
F_18 ( V_2 , 0x001A , 0x0404 ) ;
F_18 ( V_2 , 0x0002 , 0x0000 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
int V_14 ;
if ( ! V_2 )
return - V_7 ;
V_14 = F_19 ( V_2 , 0x001C ) ;
if ( 0 > V_14 )
F_22 ( L_44 ) ;
return V_14 ;
}
