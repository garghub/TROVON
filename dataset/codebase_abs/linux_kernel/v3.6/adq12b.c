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
return V_6 -> V_8 ;
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
return V_6 -> V_8 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
const struct V_30 * V_31 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_19 ;
int V_32 , V_33 ;
int V_34 ;
V_19 = V_29 -> V_35 [ 0 ] ;
V_32 = V_29 -> V_35 [ 1 ] ;
V_33 = V_29 -> V_35 [ 2 ] ;
F_11 ( V_36 L_1
L_2 , V_2 -> V_37 , V_19 ,
( V_32 == 1 ) ? L_3 : L_4 ,
( V_33 == 1 ) ? L_5 : L_6 ) ;
if ( V_19 == 0 ) {
F_11 ( V_38 L_7
L_8 ,
V_2 -> V_37 ) ;
V_19 = 0x300 ;
}
F_11 ( L_9 , V_2 -> V_37 , V_19 ) ;
if ( ! F_12 ( V_19 , V_39 , L_10 ) ) {
F_11 ( L_11 ) ;
return - V_40 ;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_41 = V_31 -> V_42 ;
if ( F_13 ( V_2 , sizeof( struct V_43 ) ) < 0 )
return - V_44 ;
V_16 -> V_32 = V_32 ;
V_16 -> V_33 = V_33 ;
V_16 -> V_27 = 0 ;
V_16 -> V_17 = - 1 ;
V_16 -> V_18 = - 1 ;
V_34 = F_14 ( V_2 , 3 ) ;
if ( V_34 )
return V_34 ;
V_4 = V_2 -> V_45 + 0 ;
V_4 -> type = V_46 ;
if ( V_33 ) {
V_4 -> V_47 = V_48 | V_49 | V_50 ;
V_4 -> V_51 = V_31 -> V_52 ;
} else {
V_4 -> V_47 = V_48 | V_49 ;
V_4 -> V_51 = V_31 -> V_53 ;
}
if ( V_32 )
V_4 -> V_54 = & V_55 ;
else
V_4 -> V_54 = & V_56 ;
V_4 -> V_57 = ( 1 << V_31 -> V_58 ) - 1 ;
V_4 -> V_59 = 4 ;
V_4 -> V_60 = F_1 ;
V_4 = V_2 -> V_45 + 1 ;
V_4 -> type = V_61 ;
V_4 -> V_47 = V_48 ;
V_4 -> V_51 = V_31 -> V_62 ;
V_4 -> V_57 = 1 ;
V_4 -> V_54 = & V_63 ;
V_4 -> V_64 = F_7 ;
V_4 = V_2 -> V_45 + 2 ;
V_4 -> type = V_65 ;
V_4 -> V_47 = V_66 ;
V_4 -> V_51 = V_31 -> V_67 ;
V_4 -> V_57 = 1 ;
V_4 -> V_54 = & V_63 ;
V_4 -> V_64 = F_8 ;
F_11 ( V_36 L_12 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 )
F_16 ( V_2 -> V_19 , V_39 ) ;
F_17 ( V_16 ) ;
}
