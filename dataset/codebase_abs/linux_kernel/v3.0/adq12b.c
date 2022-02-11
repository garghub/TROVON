static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
int V_8 , V_9 ;
V_7 = V_4 -> V_10 [ 0 ] ;
V_8 = V_4 -> V_10 [ 1 ] ;
V_9 = V_4 -> V_10 [ 2 ] ;
F_2 ( V_11 L_1
L_2 , V_2 -> V_12 , V_7 ,
( V_8 == 1 ) ? L_3 : L_4 ,
( V_9 == 1 ) ? L_5 : L_6 ) ;
if ( V_7 == 0 ) {
F_2 ( V_13 L_7
L_8 ,
V_2 -> V_12 ) ;
V_7 = 0x300 ;
}
F_2 ( L_9 , V_2 -> V_12 , V_7 ) ;
if ( ! F_3 ( V_7 , V_14 , L_10 ) ) {
F_2 ( L_11 ) ;
return - V_15 ;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_16 = V_17 -> V_18 ;
if ( F_4 ( V_2 , sizeof( struct V_19 ) ) < 0 )
return - V_20 ;
V_21 -> V_8 = V_8 ;
V_21 -> V_9 = V_9 ;
V_21 -> V_22 = 0 ;
V_21 -> V_23 = - 1 ;
V_21 -> V_24 = - 1 ;
if ( F_5 ( V_2 , 3 ) < 0 )
return - V_20 ;
V_6 = V_2 -> V_25 + 0 ;
V_6 -> type = V_26 ;
if ( V_9 ) {
V_6 -> V_27 = V_28 | V_29 | V_30 ;
V_6 -> V_31 = V_17 -> V_32 ;
} else {
V_6 -> V_27 = V_28 | V_29 ;
V_6 -> V_31 = V_17 -> V_33 ;
}
if ( V_8 )
V_6 -> V_34 = & V_35 ;
else
V_6 -> V_34 = & V_36 ;
V_6 -> V_37 = ( 1 << V_17 -> V_38 ) - 1 ;
V_6 -> V_39 = 4 ;
V_6 -> V_40 = V_41 ;
V_6 = V_2 -> V_25 + 1 ;
V_6 -> type = V_42 ;
V_6 -> V_27 = V_28 ;
V_6 -> V_31 = V_17 -> V_43 ;
V_6 -> V_37 = 1 ;
V_6 -> V_34 = & V_44 ;
V_6 -> V_45 = V_46 ;
V_6 = V_2 -> V_25 + 2 ;
V_6 -> type = V_47 ;
V_6 -> V_27 = V_48 ;
V_6 -> V_31 = V_17 -> V_49 ;
V_6 -> V_37 = 1 ;
V_6 -> V_34 = & V_44 ;
V_6 -> V_45 = V_50 ;
F_2 ( V_11 L_12 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 )
F_7 ( V_2 -> V_7 , V_14 ) ;
F_8 ( V_21 ) ;
F_2 ( V_11 L_13 , V_2 -> V_12 ) ;
return 0 ;
}
static int V_41 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_51 * V_52 ,
unsigned int * V_53 )
{
int V_54 , V_55 ;
int V_56 , V_57 ;
unsigned char V_58 , V_59 , V_60 ;
V_56 = F_9 ( V_52 -> V_61 ) ;
V_57 = F_10 ( V_52 -> V_61 ) ;
if ( V_57 != V_21 -> V_23 || V_56 != V_21 -> V_24 ) {
F_11 ( ( V_56 << 4 ) | V_57 , V_2 -> V_7 + V_62 ) ;
F_12 ( 50 ) ;
}
V_60 = F_13 ( V_2 -> V_7 + V_63 ) ;
for ( V_54 = 0 ; V_54 < V_52 -> V_54 ; V_54 ++ ) {
V_55 = 0 ;
do {
V_60 = F_13 ( V_2 -> V_7 + V_64 ) ;
V_60 = V_60 & V_65 ;
} while ( V_60 == 0 && ++ V_55 < V_66 );
V_58 = F_13 ( V_2 -> V_7 + V_67 ) ;
V_59 = F_13 ( V_2 -> V_7 + V_63 ) ;
V_53 [ V_54 ] = ( V_58 << 8 ) | V_59 ;
}
return V_54 ;
}
static int V_46 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_51 * V_52 , unsigned int * V_53 )
{
V_53 [ 1 ] = ( F_13 ( V_2 -> V_7 + V_64 ) & ( 0x1f ) ) ;
return 2 ;
}
static int V_50 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_51 * V_52 , unsigned int * V_53 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ )
if ( ( ( V_53 [ 0 ] >> V_57 ) & 0x01 ) != 0 )
F_11 ( ( ( ( V_53 [ 1 ] >> V_57 ) & 0x01 ) << 3 ) | V_57 ,
V_2 -> V_7 + V_68 ) ;
if ( V_53 [ 0 ] ) {
V_21 -> V_22 &= ~ V_53 [ 0 ] ;
V_21 -> V_22 |= ( V_53 [ 0 ] & V_53 [ 1 ] ) ;
}
V_53 [ 1 ] = V_21 -> V_22 ;
return 2 ;
}
static int T_1 F_14 ( void )
{
return F_15 ( & V_69 ) ;
}
static void T_2 F_16 ( void )
{
F_17 ( & V_69 ) ;
}
