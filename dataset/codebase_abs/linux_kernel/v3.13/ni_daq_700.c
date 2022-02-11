static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 ;
unsigned int V_9 ;
V_8 = F_2 ( V_4 , V_7 ) ;
if ( V_8 ) {
if ( V_8 & 0xff )
F_3 ( V_4 -> V_10 & 0xff , V_2 -> V_11 + V_12 ) ;
}
V_9 = V_4 -> V_10 & 0xff ;
V_9 |= F_4 ( V_2 -> V_11 + V_13 ) << 8 ;
V_7 [ 1 ] = V_9 ;
return V_6 -> V_14 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_15 ;
V_15 = F_6 ( V_2 , V_4 , V_6 , V_7 , 0 ) ;
if ( V_15 )
return V_15 ;
V_4 -> V_16 = 0x00ff ;
return V_6 -> V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_14 , V_17 , V_18 ;
int V_19 ;
unsigned int V_20 ;
enum { V_21 = 100 };
V_18 = F_8 ( V_6 -> V_22 ) ;
F_3 ( V_18 | 0x80 , V_2 -> V_11 + V_23 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_14 ; V_14 ++ ) {
F_3 ( 0x00 , V_2 -> V_11 + V_24 ) ;
F_3 ( 0x30 , V_2 -> V_11 + V_25 ) ;
F_3 ( 0x32 , V_2 -> V_11 + V_25 ) ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
V_20 = F_4 ( V_2 -> V_11 + V_26 ) ;
if ( ( V_20 & 0x03 ) != 0 ) {
F_9 ( V_2 -> V_27 ,
L_1 ) ;
return - V_28 ;
}
V_20 = F_4 ( V_2 -> V_11 + V_29 ) ;
if ( ( V_20 & 0x02 ) != 0 ) {
F_9 ( V_2 -> V_27 , L_2 ) ;
return - V_30 ;
}
if ( ( V_20 & 0x11 ) == 0x01 ) {
break;
}
F_10 ( 1 ) ;
}
if ( V_17 == V_21 ) {
F_9 ( V_2 -> V_27 ,
L_3 ) ;
return - V_31 ;
}
V_19 = F_11 ( V_2 -> V_11 + V_32 ) ;
V_19 &= 0x0fff ;
V_19 ^= 0x0800 ;
V_7 [ V_14 ] = V_19 ;
}
return V_14 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_11 = V_2 -> V_11 ;
F_3 ( 0x80 , V_11 + V_23 ) ;
F_3 ( 0x00 , V_11 + V_24 ) ;
F_3 ( 0x00 , V_11 + V_33 ) ;
F_3 ( 0x32 , V_11 + V_25 ) ;
F_3 ( 0x00 , V_11 + V_34 ) ;
F_3 ( 0x00 , V_11 + V_35 ) ;
F_11 ( V_11 + V_32 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned long V_36 )
{
struct V_37 * V_38 = F_14 ( V_2 ) ;
struct V_3 * V_4 ;
int V_15 ;
V_38 -> V_39 |= V_40 ;
V_15 = F_15 ( V_2 , NULL ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_11 = V_38 -> V_41 [ 0 ] -> V_42 ;
V_15 = F_16 ( V_2 , 2 ) ;
if ( V_15 )
return V_15 ;
V_4 = & V_2 -> V_43 [ 0 ] ;
V_4 -> type = V_44 ;
V_4 -> V_45 = V_46 | V_47 ;
V_4 -> V_48 = 16 ;
V_4 -> V_49 = & V_50 ;
V_4 -> V_51 = 1 ;
V_4 -> V_52 = F_1 ;
V_4 -> V_53 = F_5 ;
V_4 -> V_16 = 0x00ff ;
V_4 = & V_2 -> V_43 [ 1 ] ;
V_4 -> type = V_54 ;
V_4 -> V_45 = V_46 | V_55 ;
V_4 -> V_48 = 16 ;
V_4 -> V_51 = ( 1 << 12 ) - 1 ;
V_4 -> V_49 = & V_56 ;
V_4 -> V_57 = F_7 ;
F_12 ( V_2 , V_4 ) ;
F_9 ( V_2 -> V_27 , L_4 ,
V_2 -> V_58 -> V_59 ,
V_2 -> V_60 ,
V_2 -> V_11 ) ;
return 0 ;
}
static int F_17 ( struct V_37 * V_38 )
{
return F_18 ( V_38 , & V_61 ) ;
}
