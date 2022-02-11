static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 100 ; V_4 ++ ) {
if ( F_2 ( V_2 -> V_5 + V_6 ) == V_3 )
break;
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 , unsigned int * V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_4 ;
int V_15 = F_4 ( V_10 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_10 -> V_17 ; V_4 ++ )
V_11 [ V_4 ] = V_13 -> V_18 [ V_15 ] ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_9 * V_10 , unsigned int * V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_4 ;
int V_15 = F_4 ( V_10 -> V_16 ) ;
unsigned int V_3 ;
unsigned int V_19 , V_20 ;
for ( V_4 = 0 ; V_4 < V_10 -> V_17 ; V_4 ++ ) {
V_19 = ( ( V_11 [ V_4 ] & 0x0f ) << 4 ) | ( V_15 << 1 ) | 0x01 ;
V_20 = ( V_11 [ V_4 ] & 0xff0 ) >> 4 ;
V_3 = F_1 ( V_2 , 0x00 ) ;
if ( V_3 != 0 ) {
F_6 ( V_21 L_1
L_2 , V_15 , V_3 ) ;
return - V_22 ;
}
F_7 ( V_19 , V_2 -> V_5 + V_23 ) ;
V_3 = F_1 ( V_2 , 0x10 ) ;
if ( V_3 != 0x10 ) {
F_6 ( V_21 L_3
L_2 , V_15 , V_3 ) ;
return - V_22 ;
}
V_13 -> V_18 [ V_15 ] = V_11 [ V_4 ] ;
}
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
int V_4 ;
const struct V_26 * V_27 , * V_28 ;
int V_29 ;
V_29 = F_9 ( V_2 , V_25 -> V_30 [ 0 ] , V_31 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_10 ( V_2 , 1 ) ;
if ( V_29 )
return V_29 ;
V_13 = F_11 ( sizeof( * V_13 ) , V_32 ) ;
if ( ! V_13 )
return - V_33 ;
V_2 -> V_14 = V_13 ;
V_8 = & V_2 -> V_34 [ 0 ] ;
V_8 -> type = V_35 ;
V_8 -> V_36 = V_37 ;
V_8 -> V_38 = 0xfff ;
V_8 -> V_39 = 8 ;
V_8 -> V_40 = F_5 ;
V_8 -> V_41 = F_3 ;
V_8 -> V_42 = V_13 -> V_43 ;
V_27 = ( V_25 -> V_30 [ 3 ] )
? & V_44 : & V_45 ;
V_28 = ( V_25 -> V_30 [ 2 ] )
? & V_46 : & V_47 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
V_13 -> V_43 [ V_4 ] = ( V_25 -> V_30 [ 5 + V_4 ] )
? V_27 : V_28 ;
}
F_7 ( 0x00 , V_2 -> V_5 + V_6 ) ;
for ( V_4 = 0 ; V_4 < 100 ; V_4 ++ ) {
unsigned int V_3 ;
F_12 ( 1000 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( V_3 == 4 ) {
unsigned int V_48 ;
V_48 = ( V_25 -> V_30 [ 4 ] & 0x3 ) << 3 | 0x7 ;
F_7 ( V_48 , V_2 -> V_5 + V_23 ) ;
F_6 ( V_49 L_4 ,
V_48 , V_4 ) ;
break;
} else if ( V_3 != 0x00 ) {
F_6 ( V_21 L_5
L_6 , V_3 , V_4 ) ;
if ( V_3 & 0x60 )
F_7 ( 0x00 , V_2 -> V_5 + V_6 ) ;
}
}
return 0 ;
}
