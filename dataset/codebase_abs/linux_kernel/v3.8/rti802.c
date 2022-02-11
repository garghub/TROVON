static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_12 ; V_11 ++ )
V_7 [ V_11 ] = V_9 -> V_13 [ F_2 ( V_6 -> V_14 ) ] ;
return V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_15 ;
int V_16 = F_2 ( V_6 -> V_14 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_12 ; V_11 ++ ) {
V_15 = V_9 -> V_13 [ V_16 ] = V_7 [ V_11 ] ;
if ( V_9 -> V_17 [ V_16 ] == V_18 )
V_15 ^= 0x800 ;
F_4 ( V_16 , V_2 -> V_19 + V_20 ) ;
F_4 ( V_15 & 0xff , V_2 -> V_19 + V_21 ) ;
F_4 ( V_15 >> 8 , V_2 -> V_19 + V_22 ) ;
}
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_11 ;
unsigned long V_19 ;
int V_25 ;
V_19 = V_24 -> V_26 [ 0 ] ;
F_6 ( V_27 L_1 , V_2 -> V_28 , V_19 ) ;
if ( ! F_7 ( V_19 , V_29 , L_2 ) ) {
F_6 ( V_30 L_3 ) ;
return - V_31 ;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_32 = L_2 ;
V_9 = F_8 ( sizeof( * V_9 ) , V_33 ) ;
if ( ! V_9 )
return - V_34 ;
V_2 -> V_10 = V_9 ;
V_25 = F_9 ( V_2 , 1 ) ;
if ( V_25 )
return V_25 ;
V_4 = & V_2 -> V_35 [ 0 ] ;
V_4 -> type = V_36 ;
V_4 -> V_37 = V_38 ;
V_4 -> V_39 = 0xfff ;
V_4 -> V_40 = 8 ;
V_4 -> V_41 = F_1 ;
V_4 -> V_42 = F_3 ;
V_4 -> V_43 = V_9 -> V_44 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_9 -> V_17 [ V_11 ] = ( V_24 -> V_26 [ 3 + 2 * V_11 ] )
? ( V_45 )
: ( V_18 ) ;
V_9 -> V_44 [ V_11 ] = ( V_24 -> V_26 [ 2 + 2 * V_11 ] )
? & V_46 : & V_47 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 )
F_11 ( V_2 -> V_19 , V_29 ) ;
}
