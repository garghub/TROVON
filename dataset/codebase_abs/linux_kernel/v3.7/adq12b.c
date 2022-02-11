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
const struct V_32 * V_33 = F_10 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
unsigned long V_21 ;
int V_34 , V_35 ;
int V_36 ;
V_21 = V_31 -> V_37 [ 0 ] ;
V_34 = V_31 -> V_37 [ 1 ] ;
V_35 = V_31 -> V_37 [ 2 ] ;
F_11 ( V_38 L_1
L_2 , V_2 -> V_39 , V_21 ,
( V_34 == 1 ) ? L_3 : L_4 ,
( V_35 == 1 ) ? L_5 : L_6 ) ;
if ( V_21 == 0 ) {
F_11 ( V_40 L_7
L_8 ,
V_2 -> V_39 ) ;
V_21 = 0x300 ;
}
F_11 ( L_9 , V_2 -> V_39 , V_21 ) ;
if ( ! F_12 ( V_21 , V_41 , L_10 ) ) {
F_11 ( L_11 ) ;
return - V_42 ;
}
V_2 -> V_21 = V_21 ;
V_2 -> V_43 = V_33 -> V_44 ;
V_36 = F_13 ( V_2 , sizeof( * V_9 ) ) ;
if ( V_36 )
return V_36 ;
V_9 = V_2 -> V_10 ;
V_9 -> V_34 = V_34 ;
V_9 -> V_35 = V_35 ;
V_9 -> V_29 = 0 ;
V_9 -> V_19 = - 1 ;
V_9 -> V_20 = - 1 ;
V_36 = F_14 ( V_2 , 3 ) ;
if ( V_36 )
return V_36 ;
V_4 = & V_2 -> V_45 [ 0 ] ;
V_4 -> type = V_46 ;
if ( V_35 ) {
V_4 -> V_47 = V_48 | V_49 | V_50 ;
V_4 -> V_51 = V_33 -> V_52 ;
} else {
V_4 -> V_47 = V_48 | V_49 ;
V_4 -> V_51 = V_33 -> V_53 ;
}
if ( V_34 )
V_4 -> V_54 = & V_55 ;
else
V_4 -> V_54 = & V_56 ;
V_4 -> V_57 = ( 1 << V_33 -> V_58 ) - 1 ;
V_4 -> V_59 = 4 ;
V_4 -> V_60 = F_1 ;
V_4 = & V_2 -> V_45 [ 1 ] ;
V_4 -> type = V_61 ;
V_4 -> V_47 = V_48 ;
V_4 -> V_51 = V_33 -> V_62 ;
V_4 -> V_57 = 1 ;
V_4 -> V_54 = & V_63 ;
V_4 -> V_64 = F_7 ;
V_4 = & V_2 -> V_45 [ 2 ] ;
V_4 -> type = V_65 ;
V_4 -> V_47 = V_66 ;
V_4 -> V_51 = V_33 -> V_67 ;
V_4 -> V_57 = 1 ;
V_4 -> V_54 = & V_63 ;
V_4 -> V_64 = F_8 ;
F_11 ( V_38 L_12 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 )
F_16 ( V_2 -> V_21 , V_41 ) ;
}
