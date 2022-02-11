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
int V_4 ;
int V_12 = F_4 ( V_10 -> V_13 ) ;
for ( V_4 = 0 ; V_4 < V_10 -> V_14 ; V_4 ++ )
V_11 [ V_4 ] = V_15 -> V_16 [ V_12 ] ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_9 * V_10 , unsigned int * V_11 )
{
int V_4 ;
int V_12 = F_4 ( V_10 -> V_13 ) ;
unsigned int V_3 ;
unsigned int V_17 , V_18 ;
for ( V_4 = 0 ; V_4 < V_10 -> V_14 ; V_4 ++ ) {
V_17 = ( ( V_11 [ V_4 ] & 0x0f ) << 4 ) | ( V_12 << 1 ) | 0x01 ;
V_18 = ( V_11 [ V_4 ] & 0xff0 ) >> 4 ;
V_3 = F_1 ( V_2 , 0x00 ) ;
if ( V_3 != 0 ) {
F_6 ( V_19 L_1
L_2 , V_12 , V_3 ) ;
return - V_20 ;
}
F_7 ( V_17 , V_2 -> V_5 + V_21 ) ;
V_3 = F_1 ( V_2 , 0x10 ) ;
if ( V_3 != 0x10 ) {
F_6 ( V_19 L_3
L_2 , V_12 , V_3 ) ;
return - V_20 ;
}
V_15 -> V_16 [ V_12 ] = V_11 [ V_4 ] ;
}
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_7 * V_8 ;
int V_4 ;
const struct V_24 * V_25 , * V_26 ;
unsigned long V_5 ;
V_5 = V_23 -> V_27 [ 0 ] ;
F_6 ( V_28 L_4 , V_2 -> V_29 , V_5 ) ;
if ( ! F_9 ( V_5 , V_30 , L_5 ) ) {
F_6 ( V_19 L_6 ) ;
return - V_31 ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_32 = L_5 ;
if ( F_10 ( V_2 , 1 ) < 0 )
return - V_33 ;
if ( F_11 ( V_2 , sizeof( struct V_34 ) ) < 0 )
return - V_33 ;
V_8 = V_2 -> V_35 ;
V_8 -> type = V_36 ;
V_8 -> V_37 = V_38 ;
V_8 -> V_39 = 0xfff ;
V_8 -> V_40 = 8 ;
V_8 -> V_41 = F_5 ;
V_8 -> V_42 = F_3 ;
V_8 -> V_43 = V_15 -> V_44 ;
V_25 = ( V_23 -> V_27 [ 3 ] )
? & V_45 : & V_46 ;
V_26 = ( V_23 -> V_27 [ 2 ] )
? & V_47 : & V_48 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
V_15 -> V_44 [ V_4 ] = ( V_23 -> V_27 [ 5 + V_4 ] )
? V_25 : V_26 ;
}
F_7 ( 0x00 , V_2 -> V_5 + V_6 ) ;
for ( V_4 = 0 ; V_4 < 100 ; V_4 ++ ) {
unsigned int V_3 ;
F_12 ( 1000 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( V_3 == 4 ) {
unsigned int V_49 ;
V_49 = ( V_23 -> V_27 [ 4 ] & 0x3 ) << 3 | 0x7 ;
F_7 ( V_49 , V_2 -> V_5 + V_21 ) ;
F_6 ( V_28 L_7 ,
V_49 , V_4 ) ;
break;
} else if ( V_3 != 0x00 ) {
F_6 ( V_19 L_8
L_9 , V_3 , V_4 ) ;
if ( V_3 & 0x60 )
F_7 ( 0x00 , V_2 -> V_5 + V_6 ) ;
}
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
F_14 ( V_2 -> V_5 , V_30 ) ;
}
