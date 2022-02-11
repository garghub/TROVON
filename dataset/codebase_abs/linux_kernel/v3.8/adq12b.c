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
unsigned long V_21 ;
int V_32 , V_33 ;
int V_34 ;
V_2 -> V_35 = V_2 -> V_36 -> V_37 ;
V_21 = V_31 -> V_38 [ 0 ] ;
V_32 = V_31 -> V_38 [ 1 ] ;
V_33 = V_31 -> V_38 [ 2 ] ;
F_10 ( V_39 L_1
L_2 , V_2 -> V_40 , V_21 ,
( V_32 == 1 ) ? L_3 : L_4 ,
( V_33 == 1 ) ? L_5 : L_6 ) ;
if ( V_21 == 0 ) {
F_10 ( V_41 L_7
L_8 ,
V_2 -> V_40 ) ;
V_21 = 0x300 ;
}
F_10 ( L_9 , V_2 -> V_40 , V_21 ) ;
if ( ! F_11 ( V_21 , V_42 , L_10 ) ) {
F_10 ( L_11 ) ;
return - V_43 ;
}
V_2 -> V_21 = V_21 ;
V_9 = F_12 ( sizeof( * V_9 ) , V_44 ) ;
if ( ! V_9 )
return - V_45 ;
V_2 -> V_10 = V_9 ;
V_9 -> V_32 = V_32 ;
V_9 -> V_33 = V_33 ;
V_9 -> V_29 = 0 ;
V_9 -> V_19 = - 1 ;
V_9 -> V_20 = - 1 ;
V_34 = F_13 ( V_2 , 3 ) ;
if ( V_34 )
return V_34 ;
V_4 = & V_2 -> V_46 [ 0 ] ;
V_4 -> type = V_47 ;
if ( V_33 ) {
V_4 -> V_48 = V_49 | V_50 | V_51 ;
V_4 -> V_52 = 8 ;
} else {
V_4 -> V_48 = V_49 | V_50 ;
V_4 -> V_52 = 16 ;
}
if ( V_32 )
V_4 -> V_53 = & V_54 ;
else
V_4 -> V_53 = & V_55 ;
V_4 -> V_56 = 0xfff ;
V_4 -> V_57 = 4 ;
V_4 -> V_58 = F_1 ;
V_4 = & V_2 -> V_46 [ 1 ] ;
V_4 -> type = V_59 ;
V_4 -> V_48 = V_49 ;
V_4 -> V_52 = 5 ;
V_4 -> V_56 = 1 ;
V_4 -> V_53 = & V_60 ;
V_4 -> V_61 = F_7 ;
V_4 = & V_2 -> V_46 [ 2 ] ;
V_4 -> type = V_62 ;
V_4 -> V_48 = V_63 ;
V_4 -> V_52 = 8 ;
V_4 -> V_56 = 1 ;
V_4 -> V_53 = & V_60 ;
V_4 -> V_61 = F_8 ;
F_10 ( V_39 L_12 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 )
F_15 ( V_2 -> V_21 , V_42 ) ;
}
