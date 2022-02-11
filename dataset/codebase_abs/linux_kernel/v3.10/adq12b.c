static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_12 ;
int V_13 , V_14 ;
unsigned char V_15 , V_16 , V_17 ;
V_13 = F_2 ( V_6 -> V_18 ) ;
V_14 = F_3 ( V_6 -> V_18 ) ;
if ( V_14 != V_9 -> V_19 || V_13 != V_9 -> V_20 ) {
F_4 ( ( V_13 << 4 ) | V_14 , V_2 -> V_21 + V_22 ) ;
F_5 ( 50 ) ;
}
V_17 = F_6 ( V_2 -> V_21 + V_23 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_11 ; V_11 ++ ) {
V_12 = 0 ;
do {
V_17 = F_6 ( V_2 -> V_21 + V_24 ) ;
V_17 = V_17 & V_25 ;
} while ( V_17 == 0 && ++ V_12 < V_26 );
V_15 = F_6 ( V_2 -> V_21 + V_27 ) ;
V_16 = F_6 ( V_2 -> V_21 + V_23 ) ;
V_7 [ V_11 ] = ( V_15 << 8 ) | V_16 ;
}
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = ( F_6 ( V_2 -> V_21 + V_24 ) & ( 0x1f ) ) ;
return V_6 -> V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ )
if ( ( ( V_7 [ 0 ] >> V_14 ) & 0x01 ) != 0 )
F_4 ( ( ( ( V_7 [ 1 ] >> V_14 ) & 0x01 ) << 3 ) | V_14 ,
V_2 -> V_21 + V_28 ) ;
if ( V_7 [ 0 ] ) {
V_9 -> V_29 &= ~ V_7 [ 0 ] ;
V_9 -> V_29 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
}
V_7 [ 1 ] = V_9 -> V_29 ;
return V_6 -> V_11 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_32 ;
V_32 = F_10 ( V_2 , V_31 -> V_33 [ 0 ] , V_34 ) ;
if ( V_32 )
return V_32 ;
V_9 = F_11 ( sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
return - V_36 ;
V_2 -> V_10 = V_9 ;
V_9 -> V_37 = V_31 -> V_33 [ 1 ] ;
V_9 -> V_38 = V_31 -> V_33 [ 2 ] ;
V_9 -> V_29 = 0 ;
V_9 -> V_19 = - 1 ;
V_9 -> V_20 = - 1 ;
V_32 = F_12 ( V_2 , 3 ) ;
if ( V_32 )
return V_32 ;
V_4 = & V_2 -> V_39 [ 0 ] ;
V_4 -> type = V_40 ;
if ( V_9 -> V_38 ) {
V_4 -> V_41 = V_42 | V_43 | V_44 ;
V_4 -> V_45 = 8 ;
} else {
V_4 -> V_41 = V_42 | V_43 ;
V_4 -> V_45 = 16 ;
}
if ( V_9 -> V_37 )
V_4 -> V_46 = & V_47 ;
else
V_4 -> V_46 = & V_48 ;
V_4 -> V_49 = 0xfff ;
V_4 -> V_50 = 4 ;
V_4 -> V_51 = F_1 ;
V_4 = & V_2 -> V_39 [ 1 ] ;
V_4 -> type = V_52 ;
V_4 -> V_41 = V_42 ;
V_4 -> V_45 = 5 ;
V_4 -> V_49 = 1 ;
V_4 -> V_46 = & V_53 ;
V_4 -> V_54 = F_7 ;
V_4 = & V_2 -> V_39 [ 2 ] ;
V_4 -> type = V_55 ;
V_4 -> V_41 = V_56 ;
V_4 -> V_45 = 8 ;
V_4 -> V_49 = 1 ;
V_4 -> V_46 = & V_53 ;
V_4 -> V_54 = F_8 ;
return 0 ;
}
