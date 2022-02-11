static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 100 ; V_5 ++ ) {
if ( F_6 ( V_3 -> V_6 + V_7 ) == V_4 )
break;
}
return V_4 ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_8 * V_9 ,
struct V_10 * V_11 , unsigned int * V_12 )
{
int V_5 ;
int V_13 = F_8 ( V_11 -> V_14 ) ;
for ( V_5 = 0 ; V_5 < V_11 -> V_15 ; V_5 ++ )
V_12 [ V_5 ] = V_16 -> V_17 [ V_13 ] ;
return V_5 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_10 * V_11 , unsigned int * V_12 )
{
int V_5 ;
int V_13 = F_8 ( V_11 -> V_14 ) ;
unsigned int V_4 ;
unsigned int V_18 , V_19 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_15 ; V_5 ++ ) {
V_18 = ( ( V_12 [ V_5 ] & 0x0f ) << 4 ) | ( V_13 << 1 ) | 0x01 ;
V_19 = ( V_12 [ V_5 ] & 0xff0 ) >> 4 ;
V_4 = F_5 ( V_3 , 0x00 ) ;
if ( V_4 != 0 ) {
F_10 ( V_20 L_1
L_2 , V_13 , V_4 ) ;
return - V_21 ;
}
F_11 ( V_18 , V_3 -> V_6 + V_22 ) ;
V_4 = F_5 ( V_3 , 0x10 ) ;
if ( V_4 != 0x10 ) {
F_10 ( V_20 L_3
L_2 , V_13 , V_4 ) ;
return - V_21 ;
}
V_16 -> V_17 [ V_13 ] = V_12 [ V_5 ] ;
}
return V_5 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_8 * V_9 ;
int V_5 ;
const struct V_25 * V_26 , * V_27 ;
unsigned long V_6 ;
V_6 = V_24 -> V_28 [ 0 ] ;
F_10 ( V_29 L_4 , V_3 -> V_30 , V_6 ) ;
if ( ! F_13 ( V_6 , V_31 , L_5 ) ) {
F_10 ( V_20 L_6 ) ;
return - V_32 ;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_33 = L_5 ;
if ( F_14 ( V_3 , 1 ) < 0 )
return - V_34 ;
if ( F_15 ( V_3 , sizeof( struct V_35 ) ) < 0 )
return - V_34 ;
V_9 = V_3 -> V_36 ;
V_9 -> type = V_37 ;
V_9 -> V_38 = V_39 ;
V_9 -> V_40 = 0xfff ;
V_9 -> V_41 = 8 ;
V_9 -> V_42 = F_9 ;
V_9 -> V_43 = F_7 ;
V_9 -> V_44 = V_16 -> V_45 ;
V_26 = ( V_24 -> V_28 [ 3 ] )
? & V_46 : & V_47 ;
V_27 = ( V_24 -> V_28 [ 2 ] )
? & V_48 : & V_49 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
V_16 -> V_45 [ V_5 ] = ( V_24 -> V_28 [ 5 + V_5 ] )
? V_26 : V_27 ;
}
F_11 ( 0x00 , V_3 -> V_6 + V_7 ) ;
for ( V_5 = 0 ; V_5 < 100 ; V_5 ++ ) {
unsigned int V_4 ;
F_16 ( 1000 ) ;
V_4 = F_6 ( V_3 -> V_6 + V_7 ) ;
if ( V_4 == 4 ) {
unsigned int V_50 ;
V_50 = ( V_24 -> V_28 [ 4 ] & 0x3 ) << 3 | 0x7 ;
F_11 ( V_50 , V_3 -> V_6 + V_22 ) ;
F_10 ( V_29 L_7 ,
V_50 , V_5 ) ;
break;
} else if ( V_4 != 0x00 ) {
F_10 ( V_20 L_8
L_9 , V_4 , V_5 ) ;
if ( V_4 & 0x60 )
F_11 ( 0x00 , V_3 -> V_6 + V_7 ) ;
}
}
return 0 ;
}
static void F_17 ( struct V_2 * V_3 )
{
if ( V_3 -> V_6 )
F_18 ( V_3 -> V_6 , V_31 ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
F_10 ( V_29 L_10 , V_3 -> V_30 ) ;
F_17 ( V_3 ) ;
return 0 ;
}
