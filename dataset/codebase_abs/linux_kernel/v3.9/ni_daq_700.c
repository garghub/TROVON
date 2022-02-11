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
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_13 = 1 << F_5 ( V_6 -> V_14 ) ;
switch ( V_7 [ 0 ] ) {
case V_15 :
break;
case V_16 :
break;
case V_17 :
V_7 [ 1 ] = ( V_4 -> V_18 & V_13 ) ? V_19 : V_20 ;
break;
default:
return - V_21 ;
}
return V_6 -> V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_12 , V_22 , V_13 ;
int V_23 ;
unsigned int V_24 ;
enum { V_25 = 100 };
V_13 = F_5 ( V_6 -> V_14 ) ;
F_2 ( V_13 | 0x80 , V_2 -> V_9 + V_26 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_12 ; V_12 ++ ) {
F_2 ( 0x00 , V_2 -> V_9 + V_27 ) ;
F_2 ( 0x30 , V_2 -> V_9 + V_28 ) ;
F_2 ( 0x32 , V_2 -> V_9 + V_28 ) ;
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
V_24 = F_3 ( V_2 -> V_9 + V_29 ) ;
if ( ( V_24 & 0x03 ) != 0 ) {
F_7 ( V_2 -> V_30 ,
L_1 ) ;
return - V_31 ;
}
V_24 = F_3 ( V_2 -> V_9 + V_32 ) ;
if ( ( V_24 & 0x02 ) != 0 ) {
F_7 ( V_2 -> V_30 , L_2 ) ;
return - V_33 ;
}
if ( ( V_24 & 0x11 ) == 0x01 ) {
break;
}
F_8 ( 1 ) ;
}
if ( V_22 == V_25 ) {
F_7 ( V_2 -> V_30 ,
L_3 ) ;
return - V_34 ;
}
V_23 = F_9 ( V_2 -> V_9 + V_35 ) ;
V_23 &= 0x0fff ;
V_23 ^= 0x0800 ;
V_7 [ V_12 ] = V_23 ;
}
return V_12 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_9 = V_2 -> V_9 ;
F_2 ( 0x80 , V_9 + V_26 ) ;
F_2 ( 0x00 , V_9 + V_27 ) ;
F_2 ( 0x00 , V_9 + V_36 ) ;
F_2 ( 0x32 , V_9 + V_28 ) ;
F_2 ( 0x00 , V_9 + V_37 ) ;
F_2 ( 0x00 , V_9 + V_38 ) ;
F_9 ( V_9 + V_35 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long V_39 )
{
struct V_40 * V_41 = F_12 ( V_2 ) ;
struct V_3 * V_4 ;
int V_42 ;
V_2 -> V_43 = V_2 -> V_44 -> V_45 ;
V_41 -> V_46 |= V_47 ;
V_42 = F_13 ( V_2 , NULL ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_9 = V_41 -> V_48 [ 0 ] -> V_49 ;
V_42 = F_14 ( V_2 , 2 ) ;
if ( V_42 )
return V_42 ;
V_4 = & V_2 -> V_50 [ 0 ] ;
V_4 -> type = V_51 ;
V_4 -> V_52 = V_53 | V_54 ;
V_4 -> V_55 = 16 ;
V_4 -> V_56 = & V_57 ;
V_4 -> V_58 = 1 ;
V_4 -> V_59 = F_1 ;
V_4 -> V_60 = F_4 ;
V_4 -> V_8 = 0 ;
V_4 -> V_18 = 0x00ff ;
V_4 = & V_2 -> V_50 [ 1 ] ;
V_4 -> type = V_61 ;
V_4 -> V_52 = V_53 | V_62 ;
V_4 -> V_55 = 16 ;
V_4 -> V_58 = ( 1 << 12 ) - 1 ;
V_4 -> V_56 = & V_63 ;
V_4 -> V_64 = F_6 ;
F_10 ( V_2 , V_4 ) ;
F_7 ( V_2 -> V_30 , L_4 ,
V_2 -> V_44 -> V_45 ,
V_2 -> V_43 ,
V_2 -> V_9 ) ;
return 0 ;
}
static int F_15 ( struct V_40 * V_41 )
{
return F_16 ( V_41 , & V_65 ) ;
}
