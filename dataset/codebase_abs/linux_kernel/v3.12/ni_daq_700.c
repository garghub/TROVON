static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_8 &= ~ V_7 [ 0 ] ;
V_4 -> V_8 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
if ( V_7 [ 0 ] & 0xff )
F_2 ( V_4 -> V_8 & 0xff , V_2 -> V_9 + V_10 ) ;
}
V_7 [ 1 ] = V_4 -> V_8 & 0xff ;
V_7 [ 1 ] |= F_3 ( V_2 -> V_9 + V_11 ) << 8 ;
return V_6 -> V_12 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_13 ;
V_13 = F_5 ( V_2 , V_4 , V_6 , V_7 , 0 ) ;
if ( V_13 )
return V_13 ;
V_4 -> V_14 = 0x00ff ;
return V_6 -> V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_12 , V_15 , V_16 ;
int V_17 ;
unsigned int V_18 ;
enum { V_19 = 100 };
V_16 = F_7 ( V_6 -> V_20 ) ;
F_2 ( V_16 | 0x80 , V_2 -> V_9 + V_21 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_12 ; V_12 ++ ) {
F_2 ( 0x00 , V_2 -> V_9 + V_22 ) ;
F_2 ( 0x30 , V_2 -> V_9 + V_23 ) ;
F_2 ( 0x32 , V_2 -> V_9 + V_23 ) ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
V_18 = F_3 ( V_2 -> V_9 + V_24 ) ;
if ( ( V_18 & 0x03 ) != 0 ) {
F_8 ( V_2 -> V_25 ,
L_1 ) ;
return - V_26 ;
}
V_18 = F_3 ( V_2 -> V_9 + V_27 ) ;
if ( ( V_18 & 0x02 ) != 0 ) {
F_8 ( V_2 -> V_25 , L_2 ) ;
return - V_28 ;
}
if ( ( V_18 & 0x11 ) == 0x01 ) {
break;
}
F_9 ( 1 ) ;
}
if ( V_15 == V_19 ) {
F_8 ( V_2 -> V_25 ,
L_3 ) ;
return - V_29 ;
}
V_17 = F_10 ( V_2 -> V_9 + V_30 ) ;
V_17 &= 0x0fff ;
V_17 ^= 0x0800 ;
V_7 [ V_12 ] = V_17 ;
}
return V_12 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_9 = V_2 -> V_9 ;
F_2 ( 0x80 , V_9 + V_21 ) ;
F_2 ( 0x00 , V_9 + V_22 ) ;
F_2 ( 0x00 , V_9 + V_31 ) ;
F_2 ( 0x32 , V_9 + V_23 ) ;
F_2 ( 0x00 , V_9 + V_32 ) ;
F_2 ( 0x00 , V_9 + V_33 ) ;
F_10 ( V_9 + V_30 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned long V_34 )
{
struct V_35 * V_36 = F_13 ( V_2 ) ;
struct V_3 * V_4 ;
int V_13 ;
V_36 -> V_37 |= V_38 ;
V_13 = F_14 ( V_2 , NULL ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_9 = V_36 -> V_39 [ 0 ] -> V_40 ;
V_13 = F_15 ( V_2 , 2 ) ;
if ( V_13 )
return V_13 ;
V_4 = & V_2 -> V_41 [ 0 ] ;
V_4 -> type = V_42 ;
V_4 -> V_43 = V_44 | V_45 ;
V_4 -> V_46 = 16 ;
V_4 -> V_47 = & V_48 ;
V_4 -> V_49 = 1 ;
V_4 -> V_50 = F_1 ;
V_4 -> V_51 = F_4 ;
V_4 -> V_8 = 0 ;
V_4 -> V_14 = 0x00ff ;
V_4 = & V_2 -> V_41 [ 1 ] ;
V_4 -> type = V_52 ;
V_4 -> V_43 = V_44 | V_53 ;
V_4 -> V_46 = 16 ;
V_4 -> V_49 = ( 1 << 12 ) - 1 ;
V_4 -> V_47 = & V_54 ;
V_4 -> V_55 = F_6 ;
F_11 ( V_2 , V_4 ) ;
F_8 ( V_2 -> V_25 , L_4 ,
V_2 -> V_56 -> V_57 ,
V_2 -> V_58 ,
V_2 -> V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_35 * V_36 )
{
return F_17 ( V_36 , & V_59 ) ;
}
