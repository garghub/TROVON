static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_5 . V_6 ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static int T_3 F_5 ( void )
{
int V_7 ;
V_7 = F_6 ( & V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 . V_9 = ( char * ) V_5 . V_6 ;
return F_7 ( & V_8 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_8 ) ;
F_10 ( & V_5 ) ;
}
static int F_11 ( struct V_10 * V_2 ,
struct V_11 * V_12 , struct V_13 * V_14 ,
unsigned int * V_15 )
{
int V_16 = F_12 ( V_14 -> V_17 ) ;
F_13 ( ( unsigned char ) ( ( V_15 [ 0 ] >> 24 ) & 0xff ) ,
V_2 -> V_18 + V_16 * 0x20 + 0x10 ) ;
F_13 ( ( unsigned char ) ( ( V_15 [ 0 ] >> 16 ) & 0xff ) ,
V_2 -> V_18 + V_16 * 0x20 + 0x0c ) ;
F_13 ( ( unsigned char ) ( ( V_15 [ 0 ] >> 8 ) & 0xff ) ,
V_2 -> V_18 + V_16 * 0x20 + 0x08 ) ;
F_13 ( ( unsigned char ) ( ( V_15 [ 0 ] >> 0 ) & 0xff ) ,
V_2 -> V_18 + V_16 * 0x20 + 0x04 ) ;
return 1 ;
}
static int F_14 ( struct V_10 * V_2 ,
struct V_11 * V_12 , struct V_13 * V_14 ,
unsigned int * V_15 )
{
unsigned char V_19 , V_20 , V_21 , V_22 , V_23 ;
int V_16 = F_12 ( V_14 -> V_17 ) ;
int V_24 ;
V_19 = F_15 ( V_2 -> V_18 + V_16 * 0x20 ) ;
V_20 = F_15 ( V_2 -> V_18 + V_16 * 0x20 + 0x04 ) ;
V_21 = F_15 ( V_2 -> V_18 + V_16 * 0x20 + 0x08 ) ;
V_22 = F_15 ( V_2 -> V_18 + V_16 * 0x20 + 0x0c ) ;
V_23 = F_15 ( V_2 -> V_18 + V_16 * 0x20 + 0x10 ) ;
V_24 = ( V_20 + ( V_21 * 256 ) + ( V_22 * 65536 ) ) ;
if ( V_23 > 0 )
V_24 = V_24 - V_12 -> V_25 ;
* V_15 = ( unsigned int ) V_24 ;
return 1 ;
}
static int F_16 ( struct V_10 * V_2 , struct V_26 * V_27 )
{
struct V_11 * V_28 ;
struct V_1 * V_29 = NULL ;
struct V_30 * V_31 ;
unsigned long V_32 ;
int error , V_33 ;
error = F_17 ( V_2 , sizeof( struct V_34 ) ) ;
if ( error < 0 )
return error ;
F_18 (pci_device) {
if ( V_29 -> V_35 == V_36 ) {
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
if ( V_38 [ V_33 ] . V_39 ==
V_29 -> V_40 ) {
if ( ( V_27 -> V_41 [ 0 ] != 0 )
|| ( V_27 -> V_41 [ 1 ] != 0 ) ) {
if ( V_29 -> V_42 -> V_43 !=
V_27 -> V_41 [ 0 ]
||
F_19 ( V_29 -> V_44 )
!= V_27 -> V_41 [ 1 ] ) {
continue;
}
}
V_2 -> V_45 = V_38 + V_33 ;
V_31 =
(struct V_30 * )
V_2 -> V_45 ;
goto V_46;
}
}
}
}
F_20 ( V_47
L_1 ,
V_2 -> V_48 , V_27 -> V_41 [ 0 ] , V_27 -> V_41 [ 1 ] ) ;
return - V_49 ;
V_46:
F_20 ( V_50
L_2 , V_2 -> V_48 ,
V_31 -> V_9 , V_29 -> V_42 -> V_43 ,
F_19 ( V_29 -> V_44 ) ) ;
V_51 -> V_52 = V_29 ;
V_2 -> V_53 = V_31 -> V_9 ;
error = F_21 ( V_29 , V_54 ) ;
if ( error < 0 ) {
F_20 ( V_47 L_3
L_4 ,
V_2 -> V_48 ) ;
return error ;
}
V_32 = F_22 ( V_29 , 0 ) ;
V_2 -> V_18 = V_32 ;
error = F_23 ( V_2 , 1 ) ;
if ( error < 0 )
return error ;
V_28 = V_2 -> V_55 + 0 ;
V_2 -> V_56 = V_28 ;
V_28 -> type = V_57 ;
V_28 -> V_58 = V_59 ;
V_28 -> V_60 = V_31 -> V_61 ;
V_28 -> V_25 = ( 1 << V_31 -> V_62 ) - 1 ;
V_28 -> V_63 = F_14 ;
V_28 -> V_64 = F_11 ;
F_13 ( 3 , V_2 -> V_18 + 248 ) ;
F_13 ( 0 , V_2 -> V_18 ) ;
F_13 ( 0 , V_2 -> V_18 + 0x20 ) ;
F_13 ( 0 , V_2 -> V_18 + 0x40 ) ;
F_20 ( V_50 L_3 V_54 L_5 ,
V_2 -> V_48 ) ;
return 0 ;
}
static int F_24 ( struct V_10 * V_2 )
{
if ( V_51 && V_51 -> V_52 ) {
if ( V_2 -> V_18 )
F_25 ( V_51 -> V_52 ) ;
F_26 ( V_51 -> V_52 ) ;
}
F_20 ( V_50 L_3 V_54 L_6 ,
V_2 -> V_48 ) ;
return 0 ;
}
