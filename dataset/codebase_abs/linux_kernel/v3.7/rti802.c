static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_9 ; V_8 ++ )
V_7 [ V_8 ] = V_10 -> V_11 [ F_2 ( V_6 -> V_12 ) ] ;
return V_8 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 , V_13 ;
int V_14 = F_2 ( V_6 -> V_12 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_9 ; V_8 ++ ) {
V_13 = V_10 -> V_11 [ V_14 ] = V_7 [ V_8 ] ;
if ( V_10 -> V_15 [ V_14 ] == V_16 )
V_13 ^= 0x800 ;
F_4 ( V_14 , V_2 -> V_17 + V_18 ) ;
F_4 ( V_13 & 0xff , V_2 -> V_17 + V_19 ) ;
F_4 ( V_13 >> 8 , V_2 -> V_17 + V_20 ) ;
}
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_3 * V_4 ;
int V_8 ;
unsigned long V_17 ;
int V_23 ;
V_17 = V_22 -> V_24 [ 0 ] ;
F_6 ( V_25 L_1 , V_2 -> V_26 , V_17 ) ;
if ( ! F_7 ( V_17 , V_27 , L_2 ) ) {
F_6 ( V_28 L_3 ) ;
return - V_29 ;
}
V_2 -> V_17 = V_17 ;
V_2 -> V_30 = L_2 ;
if ( F_8 ( V_2 , sizeof( struct V_31 ) ) )
return - V_32 ;
V_23 = F_9 ( V_2 , 1 ) ;
if ( V_23 )
return V_23 ;
V_4 = & V_2 -> V_33 [ 0 ] ;
V_4 -> type = V_34 ;
V_4 -> V_35 = V_36 ;
V_4 -> V_37 = 0xfff ;
V_4 -> V_38 = 8 ;
V_4 -> V_39 = F_1 ;
V_4 -> V_40 = F_3 ;
V_4 -> V_41 = V_10 -> V_42 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_10 -> V_15 [ V_8 ] = ( V_22 -> V_24 [ 3 + 2 * V_8 ] )
? ( V_43 )
: ( V_16 ) ;
V_10 -> V_42 [ V_8 ] = ( V_22 -> V_24 [ 2 + 2 * V_8 ] )
? & V_44 : & V_45 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 )
F_11 ( V_2 -> V_17 , V_27 ) ;
}
