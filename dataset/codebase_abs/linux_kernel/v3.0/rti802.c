static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_10 ; V_9 ++ )
V_8 [ V_9 ] = V_11 -> V_12 [ F_6 ( V_7 -> V_13 ) ] ;
return V_9 ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 , V_14 ;
int V_15 = F_6 ( V_7 -> V_13 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_10 ; V_9 ++ ) {
V_14 = V_11 -> V_12 [ V_15 ] = V_8 [ V_9 ] ;
if ( V_11 -> V_16 [ V_15 ] == V_17 )
V_14 ^= 0x800 ;
F_8 ( V_15 , V_3 -> V_18 + V_19 ) ;
F_8 ( V_14 & 0xff , V_3 -> V_18 + V_20 ) ;
F_8 ( V_14 >> 8 , V_3 -> V_18 + V_21 ) ;
}
return V_9 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_22 * V_23 )
{
struct V_4 * V_5 ;
int V_9 ;
unsigned long V_18 ;
V_18 = V_23 -> V_24 [ 0 ] ;
F_10 ( V_25 L_1 , V_3 -> V_26 , V_18 ) ;
if ( ! F_11 ( V_18 , V_27 , L_2 ) ) {
F_10 ( V_28 L_3 ) ;
return - V_29 ;
}
V_3 -> V_18 = V_18 ;
V_3 -> V_30 = L_2 ;
if ( F_12 ( V_3 , 1 ) < 0
|| F_13 ( V_3 , sizeof( struct V_31 ) ) ) {
return - V_32 ;
}
V_5 = V_3 -> V_33 ;
V_5 -> type = V_34 ;
V_5 -> V_35 = V_36 ;
V_5 -> V_37 = 0xfff ;
V_5 -> V_38 = 8 ;
V_5 -> V_39 = F_5 ;
V_5 -> V_40 = F_7 ;
V_5 -> V_41 = V_11 -> V_42 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_11 -> V_16 [ V_9 ] = ( V_23 -> V_24 [ 3 + 2 * V_9 ] )
? ( V_43 )
: ( V_17 ) ;
V_11 -> V_42 [ V_9 ] = ( V_23 -> V_24 [ 2 + 2 * V_9 ] )
? & V_44 : & V_45 ;
}
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
F_10 ( V_25 L_4 , V_3 -> V_26 ) ;
if ( V_3 -> V_18 )
F_15 ( V_3 -> V_18 , V_27 ) ;
return 0 ;
}
