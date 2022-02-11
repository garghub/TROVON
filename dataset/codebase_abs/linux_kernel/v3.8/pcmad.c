static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 ;
int V_14 ;
int V_15 ;
V_14 = F_3 ( V_6 -> V_16 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_15 ; V_15 ++ ) {
F_4 ( V_14 , V_2 -> V_17 + V_18 ) ;
for ( V_13 = 0 ; V_13 < V_19 ; V_13 ++ ) {
if ( ( F_5 ( V_2 -> V_17 + V_20 ) & 0x3 ) == 0x3 )
break;
}
V_7 [ V_15 ] = F_5 ( V_2 -> V_17 + V_21 ) ;
V_7 [ V_15 ] |= ( F_5 ( V_2 -> V_17 + V_22 ) << 8 ) ;
if ( V_11 -> V_23 )
V_7 [ V_15 ] ^= ( 1 << ( V_9 -> V_24 - 1 ) ) ;
}
return V_15 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
int V_27 ;
struct V_3 * V_4 ;
unsigned long V_17 ;
V_17 = V_26 -> V_28 [ 0 ] ;
F_7 ( V_29 L_1 , V_2 -> V_30 , V_17 ) ;
if ( ! F_8 ( V_17 , V_31 , L_2 ) ) {
F_7 ( V_32 L_3 ) ;
return - V_33 ;
}
F_7 ( V_32 L_4 ) ;
V_2 -> V_17 = V_17 ;
V_27 = F_9 ( V_2 , 1 ) ;
if ( V_27 )
return V_27 ;
V_11 = F_10 ( sizeof( * V_11 ) , V_34 ) ;
if ( ! V_11 )
return - V_35 ;
V_2 -> V_12 = V_11 ;
V_2 -> V_36 = V_9 -> V_37 ;
V_4 = & V_2 -> V_38 [ 0 ] ;
V_4 -> type = V_39 ;
V_4 -> V_40 = V_41 | V_42 ;
V_4 -> V_43 = 16 ;
V_4 -> V_44 = 1 ;
V_4 -> V_45 = F_1 ;
V_4 -> V_46 = ( 1 << V_9 -> V_24 ) - 1 ;
V_4 -> V_47 = & V_48 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 )
F_12 ( V_2 -> V_49 , V_2 ) ;
if ( V_2 -> V_17 )
F_13 ( V_2 -> V_17 , V_31 ) ;
}
