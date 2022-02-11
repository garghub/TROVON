static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( V_8 == V_7 )
return 0 ;
return - V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
int V_16 ;
int V_17 = F_4 ( V_6 -> V_18 ) ;
for ( V_16 = 0 ; V_16 < V_6 -> V_19 ; V_16 ++ )
V_12 [ V_16 ] = V_14 -> V_20 [ V_17 ] ;
return V_16 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
int V_16 ;
int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_21 , V_22 ;
int V_23 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_19 ; V_16 ++ ) {
V_21 = ( ( V_12 [ V_16 ] & 0x0f ) << 4 ) | ( V_17 << 1 ) | 0x01 ;
V_22 = ( V_12 [ V_16 ] & 0xff0 ) >> 4 ;
V_23 = F_6 ( V_2 , V_4 , V_6 , F_1 , 0x00 ) ;
if ( V_23 )
return V_23 ;
F_7 ( V_21 , V_2 -> V_9 + V_24 ) ;
V_23 = F_6 ( V_2 , V_4 , V_6 , F_1 , 0x10 ) ;
if ( V_23 )
return V_23 ;
V_14 -> V_20 [ V_17 ] = V_12 [ V_16 ] ;
}
return V_16 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
int V_16 ;
const struct V_27 * V_28 , * V_29 ;
int V_23 ;
V_23 = F_9 ( V_2 , V_26 -> V_30 [ 0 ] , V_31 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_10 ( V_2 , 1 ) ;
if ( V_23 )
return V_23 ;
V_14 = F_11 ( V_2 , sizeof( * V_14 ) ) ;
if ( ! V_14 )
return - V_32 ;
V_4 = & V_2 -> V_33 [ 0 ] ;
V_4 -> type = V_34 ;
V_4 -> V_35 = V_36 ;
V_4 -> V_37 = 0xfff ;
V_4 -> V_38 = 8 ;
V_4 -> V_39 = F_5 ;
V_4 -> V_40 = F_3 ;
V_4 -> V_41 = V_14 -> V_42 ;
V_28 = ( V_26 -> V_30 [ 3 ] )
? & V_43 : & V_44 ;
V_29 = ( V_26 -> V_30 [ 2 ] )
? & V_45 : & V_46 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
V_14 -> V_42 [ V_16 ] = ( V_26 -> V_30 [ 5 + V_16 ] )
? V_28 : V_29 ;
}
F_7 ( 0x00 , V_2 -> V_9 + V_10 ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
unsigned int V_8 ;
F_12 ( 1000 ) ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( V_8 == 4 ) {
unsigned int V_47 ;
V_47 = ( V_26 -> V_30 [ 4 ] & 0x3 ) << 3 | 0x7 ;
F_7 ( V_47 , V_2 -> V_9 + V_24 ) ;
F_13 ( V_2 -> V_48 , L_1 ,
V_47 , V_16 ) ;
break;
} else if ( V_8 != 0x00 ) {
F_13 ( V_2 -> V_48 ,
L_2 ,
V_8 , V_16 ) ;
if ( V_8 & 0x60 )
F_7 ( 0x00 , V_2 -> V_9 + V_10 ) ;
}
}
return 0 ;
}
