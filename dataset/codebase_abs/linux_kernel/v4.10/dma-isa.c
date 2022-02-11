static int F_1 ( unsigned int V_1 , T_1 * V_2 )
{
unsigned int V_3 = V_4 [ V_1 ] [ V_5 ] ;
int V_6 ;
V_6 = 1 + F_2 ( V_3 ) ;
V_6 |= F_2 ( V_3 ) << 8 ;
return V_1 < 4 ? V_6 : ( V_6 << 1 ) ;
}
static void F_3 ( unsigned int V_1 , T_1 * V_2 )
{
if ( V_2 -> V_7 ) {
unsigned long V_8 , V_9 ;
unsigned int V_10 ;
enum V_11 V_12 ;
V_10 = ( V_1 & 3 ) | V_2 -> V_13 ;
switch ( V_2 -> V_13 & V_14 ) {
case V_15 :
V_12 = V_16 ;
break;
case V_17 :
V_12 = V_18 ;
break;
case V_19 :
V_12 = V_20 ;
break;
default:
V_12 = V_21 ;
break;
}
if ( ! V_2 -> V_22 ) {
V_2 -> V_22 = & V_2 -> V_23 ;
V_2 -> V_24 = 1 ;
V_2 -> V_23 . V_9 = V_2 -> V_6 ;
V_2 -> V_23 . V_25 = F_4 ( NULL ,
V_2 -> V_26 , V_2 -> V_6 ,
V_12 ) ;
}
V_8 = V_2 -> V_23 . V_25 ;
V_9 = V_2 -> V_23 . V_9 - 1 ;
F_5 ( V_8 >> 16 , V_4 [ V_1 ] [ V_27 ] ) ;
F_5 ( V_8 >> 24 , V_4 [ V_1 ] [ V_28 ] ) ;
if ( V_1 >= 4 ) {
V_8 >>= 1 ;
V_9 >>= 1 ;
}
F_5 ( 0 , V_4 [ V_1 ] [ V_29 ] ) ;
F_5 ( V_8 , V_4 [ V_1 ] [ V_30 ] ) ;
F_5 ( V_8 >> 8 , V_4 [ V_1 ] [ V_30 ] ) ;
F_5 ( V_9 , V_4 [ V_1 ] [ V_5 ] ) ;
F_5 ( V_9 >> 8 , V_4 [ V_1 ] [ V_5 ] ) ;
F_5 ( V_10 , V_4 [ V_1 ] [ V_31 ] ) ;
V_2 -> V_7 = 0 ;
}
F_5 ( V_1 & 3 , V_4 [ V_1 ] [ V_32 ] ) ;
}
static void F_6 ( unsigned int V_1 , T_1 * V_2 )
{
F_5 ( V_1 | 4 , V_4 [ V_1 ] [ V_32 ] ) ;
}
void T_2 F_7 ( void )
{
F_5 ( 0xff , 0x0d ) ;
F_5 ( 0xff , 0xda ) ;
F_5 ( 0x55 , 0x00 ) ;
F_5 ( 0xaa , 0x00 ) ;
if ( F_2 ( 0 ) == 0x55 && F_2 ( 0 ) == 0xaa ) {
unsigned int V_1 , V_33 ;
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ ) {
V_34 [ V_1 ] . V_35 = & V_36 ;
F_6 ( V_1 , NULL ) ;
}
F_5 ( 0x40 , 0x0b ) ;
F_5 ( 0x41 , 0x0b ) ;
F_5 ( 0x42 , 0x0b ) ;
F_5 ( 0x43 , 0x0b ) ;
F_5 ( 0xc0 , 0xd6 ) ;
F_5 ( 0x41 , 0xd6 ) ;
F_5 ( 0x42 , 0xd6 ) ;
F_5 ( 0x43 , 0xd6 ) ;
F_5 ( 0 , 0xd4 ) ;
F_5 ( 0x10 , 0x08 ) ;
F_5 ( 0x10 , 0xd0 ) ;
F_5 ( 0x30 , 0x40b ) ;
F_5 ( 0x31 , 0x40b ) ;
F_5 ( 0x32 , 0x40b ) ;
F_5 ( 0x33 , 0x40b ) ;
F_5 ( 0x31 , 0x4d6 ) ;
F_5 ( 0x32 , 0x4d6 ) ;
F_5 ( 0x33 , 0x4d6 ) ;
for ( V_33 = 0 ; V_33 < F_8 ( V_37 ) ; V_33 ++ )
F_9 ( & V_38 , V_37 + V_33 ) ;
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ ) {
int V_39 = F_10 ( V_1 , & V_34 [ V_1 ] ) ;
if ( V_39 )
F_11 ( L_1 ,
V_1 , V_39 ) ;
}
F_12 ( V_40 , L_2 ) ;
}
}
