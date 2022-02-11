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
static struct V_18 * F_6 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
const struct V_21 * V_22 ;
struct V_18 * V_23 = NULL ;
int V_24 = V_20 -> V_25 [ 0 ] ;
int V_26 = V_20 -> V_25 [ 1 ] ;
int V_27 ;
F_7 (pcidev) {
if ( V_24 || V_26 ) {
if ( V_23 -> V_24 -> V_28 != V_24 ||
F_8 ( V_23 -> V_29 ) != V_26 )
continue;
}
if ( V_23 -> V_30 != V_31 )
continue;
for ( V_27 = 0 ; V_27 < F_9 ( V_32 ) ; V_27 ++ ) {
V_22 = & V_32 [ V_27 ] ;
if ( V_22 -> V_33 != V_23 -> V_34 )
continue;
V_2 -> V_35 = V_22 ;
return V_23 ;
}
}
F_10 ( V_2 -> V_36 ,
L_1 ,
V_24 , V_26 ) ;
return NULL ;
}
static int F_11 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
const struct V_21 * V_22 ;
struct V_18 * V_23 ;
struct V_3 * V_37 ;
unsigned long V_38 ;
int error ;
V_23 = F_6 ( V_2 , V_20 ) ;
if ( ! V_23 )
return - V_39 ;
F_12 ( V_2 , & V_23 -> V_2 ) ;
V_22 = F_13 ( V_2 ) ;
V_2 -> V_40 = V_22 -> V_41 ;
error = F_14 ( V_23 , V_42 ) ;
if ( error < 0 ) {
F_15 ( V_43 L_2
L_3 ,
V_2 -> V_44 ) ;
return error ;
}
V_38 = F_16 ( V_23 , 0 ) ;
V_2 -> V_10 = V_38 ;
error = F_17 ( V_2 , 1 ) ;
if ( error )
return error ;
V_37 = V_2 -> V_45 + 0 ;
V_2 -> V_46 = V_37 ;
V_37 -> type = V_47 ;
V_37 -> V_48 = V_49 ;
V_37 -> V_50 = V_22 -> V_51 ;
V_37 -> V_17 = ( 1 << V_22 -> V_52 ) - 1 ;
V_37 -> V_53 = F_4 ;
V_37 -> V_54 = F_1 ;
F_3 ( 3 , V_2 -> V_10 + 248 ) ;
F_3 ( 0 , V_2 -> V_10 ) ;
F_3 ( 0 , V_2 -> V_10 + 0x20 ) ;
F_3 ( 0 , V_2 -> V_10 + 0x40 ) ;
F_15 ( V_55 L_2 V_42 L_4 ,
V_2 -> V_44 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_18 * V_23 = F_19 ( V_2 ) ;
if ( V_23 ) {
if ( V_2 -> V_10 )
F_20 ( V_23 ) ;
F_21 ( V_23 ) ;
}
}
static int T_1 F_22 ( struct V_18 * V_2 ,
const struct V_56 * V_57 )
{
return F_23 ( V_2 , & V_58 ) ;
}
static void T_2 F_24 ( struct V_18 * V_2 )
{
F_25 ( V_2 ) ;
}
