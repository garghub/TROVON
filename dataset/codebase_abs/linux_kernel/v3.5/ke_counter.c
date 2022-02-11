static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_8 = F_2 ( V_6 -> V_9 ) ;
F_3 ( ( unsigned char ) ( ( V_7 [ 0 ] >> 24 ) & 0xff ) ,
V_2 -> V_10 + V_8 * 0x20 + 0x10 ) ;
F_3 ( ( unsigned char ) ( ( V_7 [ 0 ] >> 16 ) & 0xff ) ,
V_2 -> V_10 + V_8 * 0x20 + 0x0c ) ;
F_3 ( ( unsigned char ) ( ( V_7 [ 0 ] >> 8 ) & 0xff ) ,
V_2 -> V_10 + V_8 * 0x20 + 0x08 ) ;
F_3 ( ( unsigned char ) ( ( V_7 [ 0 ] >> 0 ) & 0xff ) ,
V_2 -> V_10 + V_8 * 0x20 + 0x04 ) ;
return 1 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned char V_11 , V_12 , V_13 , V_14 , V_15 ;
int V_8 = F_2 ( V_6 -> V_9 ) ;
int V_16 ;
V_11 = F_5 ( V_2 -> V_10 + V_8 * 0x20 ) ;
V_12 = F_5 ( V_2 -> V_10 + V_8 * 0x20 + 0x04 ) ;
V_13 = F_5 ( V_2 -> V_10 + V_8 * 0x20 + 0x08 ) ;
V_14 = F_5 ( V_2 -> V_10 + V_8 * 0x20 + 0x0c ) ;
V_15 = F_5 ( V_2 -> V_10 + V_8 * 0x20 + 0x10 ) ;
V_16 = ( V_12 + ( V_13 * 256 ) + ( V_14 * 65536 ) ) ;
if ( V_15 > 0 )
V_16 = V_16 - V_4 -> V_17 ;
* V_7 = ( unsigned int ) V_16 ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_3 * V_20 ;
struct V_21 * V_22 = NULL ;
struct V_23 * V_24 ;
unsigned long V_25 ;
int error , V_26 ;
error = F_7 ( V_2 , sizeof( struct V_27 ) ) ;
if ( error < 0 )
return error ;
F_8 (pci_device) {
if ( V_22 -> V_28 == V_29 ) {
for ( V_26 = 0 ; V_26 < V_30 ; V_26 ++ ) {
if ( V_31 [ V_26 ] . V_32 ==
V_22 -> V_33 ) {
if ( ( V_19 -> V_34 [ 0 ] != 0 )
|| ( V_19 -> V_34 [ 1 ] != 0 ) ) {
if ( V_22 -> V_35 -> V_36 !=
V_19 -> V_34 [ 0 ]
||
F_9 ( V_22 -> V_37 )
!= V_19 -> V_34 [ 1 ] ) {
continue;
}
}
V_2 -> V_38 = V_31 + V_26 ;
V_24 =
(struct V_23 * )
V_2 -> V_38 ;
goto V_39;
}
}
}
}
F_10 ( V_40
L_1 ,
V_2 -> V_41 , V_19 -> V_34 [ 0 ] , V_19 -> V_34 [ 1 ] ) ;
return - V_42 ;
V_39:
F_10 ( V_43
L_2 , V_2 -> V_41 ,
V_24 -> V_44 , V_22 -> V_35 -> V_36 ,
F_9 ( V_22 -> V_37 ) ) ;
V_45 -> V_46 = V_22 ;
V_2 -> V_47 = V_24 -> V_44 ;
error = F_11 ( V_22 , V_48 ) ;
if ( error < 0 ) {
F_10 ( V_40 L_3
L_4 ,
V_2 -> V_41 ) ;
return error ;
}
V_25 = F_12 ( V_22 , 0 ) ;
V_2 -> V_10 = V_25 ;
error = F_13 ( V_2 , 1 ) ;
if ( error < 0 )
return error ;
V_20 = V_2 -> V_49 + 0 ;
V_2 -> V_50 = V_20 ;
V_20 -> type = V_51 ;
V_20 -> V_52 = V_53 ;
V_20 -> V_54 = V_24 -> V_55 ;
V_20 -> V_17 = ( 1 << V_24 -> V_56 ) - 1 ;
V_20 -> V_57 = F_4 ;
V_20 -> V_58 = F_1 ;
F_3 ( 3 , V_2 -> V_10 + 248 ) ;
F_3 ( 0 , V_2 -> V_10 ) ;
F_3 ( 0 , V_2 -> V_10 + 0x20 ) ;
F_3 ( 0 , V_2 -> V_10 + 0x40 ) ;
F_10 ( V_43 L_3 V_48 L_5 ,
V_2 -> V_41 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_45 && V_45 -> V_46 ) {
if ( V_2 -> V_10 )
F_15 ( V_45 -> V_46 ) ;
F_16 ( V_45 -> V_46 ) ;
}
}
static int T_1 F_17 ( struct V_21 * V_2 ,
const struct V_59 * V_60 )
{
return F_18 ( V_2 , & V_61 ) ;
}
static void T_2 F_19 ( struct V_21 * V_2 )
{
F_20 ( V_2 ) ;
}
