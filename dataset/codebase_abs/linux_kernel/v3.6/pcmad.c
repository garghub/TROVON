static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
int V_11 ;
int V_12 ;
V_11 = F_3 ( V_6 -> V_13 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_12 ; V_12 ++ ) {
F_4 ( V_11 , V_2 -> V_14 + V_15 ) ;
for ( V_10 = 0 ; V_10 < V_16 ; V_10 ++ ) {
if ( ( F_5 ( V_2 -> V_14 + V_17 ) & 0x3 ) == 0x3 )
break;
}
V_7 [ V_12 ] = F_5 ( V_2 -> V_14 + V_18 ) ;
V_7 [ V_12 ] |= ( F_5 ( V_2 -> V_14 + V_19 ) << 8 ) ;
if ( V_20 -> V_21 )
V_7 [ V_12 ] ^= ( 1 << ( V_9 -> V_22 - 1 ) ) ;
}
return V_12 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_25 ;
struct V_3 * V_4 ;
unsigned long V_14 ;
V_14 = V_24 -> V_26 [ 0 ] ;
F_7 ( V_27 L_1 , V_2 -> V_28 , V_14 ) ;
if ( ! F_8 ( V_14 , V_29 , L_2 ) ) {
F_7 ( V_30 L_3 ) ;
return - V_31 ;
}
F_7 ( V_30 L_4 ) ;
V_2 -> V_14 = V_14 ;
V_25 = F_9 ( V_2 , 1 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_10 ( V_2 , sizeof( struct V_32 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_2 -> V_33 = V_9 -> V_34 ;
V_4 = V_2 -> V_35 + 0 ;
V_4 -> type = V_36 ;
V_4 -> V_37 = V_38 | V_39 ;
V_4 -> V_40 = 16 ;
V_4 -> V_41 = 1 ;
V_4 -> V_42 = F_1 ;
V_4 -> V_43 = ( 1 << V_9 -> V_22 ) - 1 ;
V_4 -> V_44 = & V_45 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 )
F_12 ( V_2 -> V_46 , V_2 ) ;
if ( V_2 -> V_14 )
F_13 ( V_2 -> V_14 , V_29 ) ;
}
