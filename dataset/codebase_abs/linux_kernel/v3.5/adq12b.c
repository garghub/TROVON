static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_8 , V_9 ;
int V_10 , V_11 ;
unsigned char V_12 , V_13 , V_14 ;
V_10 = F_2 ( V_6 -> V_15 ) ;
V_11 = F_3 ( V_6 -> V_15 ) ;
if ( V_11 != V_16 -> V_17 || V_10 != V_16 -> V_18 ) {
F_4 ( ( V_10 << 4 ) | V_11 , V_2 -> V_19 + V_20 ) ;
F_5 ( 50 ) ;
}
V_14 = F_6 ( V_2 -> V_19 + V_21 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
V_9 = 0 ;
do {
V_14 = F_6 ( V_2 -> V_19 + V_22 ) ;
V_14 = V_14 & V_23 ;
} while ( V_14 == 0 && ++ V_9 < V_24 );
V_12 = F_6 ( V_2 -> V_19 + V_25 ) ;
V_13 = F_6 ( V_2 -> V_19 + V_21 ) ;
V_7 [ V_8 ] = ( V_12 << 8 ) | V_13 ;
}
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = ( F_6 ( V_2 -> V_19 + V_22 ) & ( 0x1f ) ) ;
return 2 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ )
if ( ( ( V_7 [ 0 ] >> V_11 ) & 0x01 ) != 0 )
F_4 ( ( ( ( V_7 [ 1 ] >> V_11 ) & 0x01 ) << 3 ) | V_11 ,
V_2 -> V_19 + V_26 ) ;
if ( V_7 [ 0 ] ) {
V_16 -> V_27 &= ~ V_7 [ 0 ] ;
V_16 -> V_27 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
}
V_7 [ 1 ] = V_16 -> V_27 ;
return 2 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_4 ;
unsigned long V_19 ;
int V_30 , V_31 ;
V_19 = V_29 -> V_32 [ 0 ] ;
V_30 = V_29 -> V_32 [ 1 ] ;
V_31 = V_29 -> V_32 [ 2 ] ;
F_10 ( V_33 L_1
L_2 , V_2 -> V_34 , V_19 ,
( V_30 == 1 ) ? L_3 : L_4 ,
( V_31 == 1 ) ? L_5 : L_6 ) ;
if ( V_19 == 0 ) {
F_10 ( V_35 L_7
L_8 ,
V_2 -> V_34 ) ;
V_19 = 0x300 ;
}
F_10 ( L_9 , V_2 -> V_34 , V_19 ) ;
if ( ! F_11 ( V_19 , V_36 , L_10 ) ) {
F_10 ( L_11 ) ;
return - V_37 ;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_38 = V_39 -> V_40 ;
if ( F_12 ( V_2 , sizeof( struct V_41 ) ) < 0 )
return - V_42 ;
V_16 -> V_30 = V_30 ;
V_16 -> V_31 = V_31 ;
V_16 -> V_27 = 0 ;
V_16 -> V_17 = - 1 ;
V_16 -> V_18 = - 1 ;
if ( F_13 ( V_2 , 3 ) < 0 )
return - V_42 ;
V_4 = V_2 -> V_43 + 0 ;
V_4 -> type = V_44 ;
if ( V_31 ) {
V_4 -> V_45 = V_46 | V_47 | V_48 ;
V_4 -> V_49 = V_39 -> V_50 ;
} else {
V_4 -> V_45 = V_46 | V_47 ;
V_4 -> V_49 = V_39 -> V_51 ;
}
if ( V_30 )
V_4 -> V_52 = & V_53 ;
else
V_4 -> V_52 = & V_54 ;
V_4 -> V_55 = ( 1 << V_39 -> V_56 ) - 1 ;
V_4 -> V_57 = 4 ;
V_4 -> V_58 = F_1 ;
V_4 = V_2 -> V_43 + 1 ;
V_4 -> type = V_59 ;
V_4 -> V_45 = V_46 ;
V_4 -> V_49 = V_39 -> V_60 ;
V_4 -> V_55 = 1 ;
V_4 -> V_52 = & V_61 ;
V_4 -> V_62 = F_7 ;
V_4 = V_2 -> V_43 + 2 ;
V_4 -> type = V_63 ;
V_4 -> V_45 = V_64 ;
V_4 -> V_49 = V_39 -> V_65 ;
V_4 -> V_55 = 1 ;
V_4 -> V_52 = & V_61 ;
V_4 -> V_62 = F_8 ;
F_10 ( V_33 L_12 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 )
F_15 ( V_2 -> V_19 , V_36 ) ;
F_16 ( V_16 ) ;
}
