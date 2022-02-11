static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
int V_9 ;
int V_10 ;
V_9 = F_2 ( V_6 -> V_11 ) ;
for ( V_10 = 0 ; V_10 < V_6 -> V_10 ; V_10 ++ ) {
F_3 ( V_9 , V_2 -> V_12 + V_13 ) ;
for ( V_8 = 0 ; V_8 < V_14 ; V_8 ++ ) {
if ( ( F_4 ( V_2 -> V_12 + V_15 ) & 0x3 ) == 0x3 )
break;
}
V_7 [ V_10 ] = F_4 ( V_2 -> V_12 + V_16 ) ;
V_7 [ V_10 ] |= ( F_4 ( V_2 -> V_12 + V_17 ) << 8 ) ;
if ( V_18 -> V_19 )
V_7 [ V_10 ] ^= ( 1 << ( V_20 -> V_21 - 1 ) ) ;
}
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
int V_24 ;
struct V_3 * V_4 ;
unsigned long V_12 ;
V_12 = V_23 -> V_25 [ 0 ] ;
F_6 ( V_26 L_1 , V_2 -> V_27 , V_12 ) ;
if ( ! F_7 ( V_12 , V_28 , L_2 ) ) {
F_6 ( V_29 L_3 ) ;
return - V_30 ;
}
F_6 ( V_29 L_4 ) ;
V_2 -> V_12 = V_12 ;
V_24 = F_8 ( V_2 , 1 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_9 ( V_2 , sizeof( struct V_31 ) ) ;
if ( V_24 < 0 )
return V_24 ;
V_2 -> V_32 = V_20 -> V_33 ;
V_4 = V_2 -> V_34 + 0 ;
V_4 -> type = V_35 ;
V_4 -> V_36 = V_37 | V_38 ;
V_4 -> V_39 = 16 ;
V_4 -> V_40 = 1 ;
V_4 -> V_41 = F_1 ;
V_4 -> V_42 = ( 1 << V_20 -> V_21 ) - 1 ;
V_4 -> V_43 = & V_44 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_45 )
F_11 ( V_2 -> V_45 , V_2 ) ;
if ( V_2 -> V_12 )
F_12 ( V_2 -> V_12 , V_28 ) ;
}
