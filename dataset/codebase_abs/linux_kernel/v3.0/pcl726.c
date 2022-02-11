static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 , V_10 ;
int V_11 ;
int V_12 = F_6 ( V_7 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < V_7 -> V_11 ; V_11 ++ ) {
V_10 = V_8 [ V_11 ] & 0xff ;
V_9 = ( V_8 [ V_11 ] >> 8 ) & 0xf ;
if ( V_14 -> V_15 [ V_12 ] )
V_9 ^= 0x8 ;
F_7 ( V_9 , V_3 -> V_16 + V_17 + 2 * V_12 ) ;
F_7 ( V_10 , V_3 -> V_16 + V_18 + 2 * V_12 ) ;
V_14 -> V_19 [ V_12 ] = V_8 [ V_11 ] ;
}
return V_11 ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_12 = F_6 ( V_7 -> V_13 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_11 ; V_11 ++ )
V_8 [ V_11 ] = V_14 -> V_19 [ V_12 ] ;
return V_11 ;
}
static int F_9 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_7 -> V_11 != 2 )
return - V_20 ;
V_8 [ 1 ] = F_10 ( V_3 -> V_16 + V_21 -> V_22 ) |
( F_10 ( V_3 -> V_16 + V_21 -> V_23 ) << 8 ) ;
return 2 ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
if ( V_7 -> V_11 != 2 )
return - V_20 ;
if ( V_8 [ 0 ] ) {
V_5 -> V_24 &= ~ V_8 [ 0 ] ;
V_5 -> V_24 |= V_8 [ 0 ] & V_8 [ 1 ] ;
}
if ( V_8 [ 1 ] & 0x00ff )
F_7 ( V_5 -> V_24 & 0xff , V_3 -> V_16 + V_21 -> V_25 ) ;
if ( V_8 [ 1 ] & 0xff00 )
F_7 ( ( V_5 -> V_24 >> 8 ) , V_3 -> V_16 + V_21 -> V_26 ) ;
V_8 [ 1 ] = V_5 -> V_24 ;
return 2 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_27 * V_28 )
{
struct V_4 * V_5 ;
unsigned long V_16 ;
unsigned int V_29 ;
int V_30 , V_31 ;
#ifdef F_13
unsigned int V_32 ;
#endif
V_16 = V_28 -> V_33 [ 0 ] ;
V_29 = V_21 -> V_34 ;
F_14 ( V_35 L_1 , V_3 -> V_36 ,
V_21 -> V_37 , V_16 ) ;
if ( ! F_15 ( V_16 , V_29 , L_2 ) ) {
F_14 ( V_35 L_3 ) ;
return - V_38 ;
}
V_3 -> V_16 = V_16 ;
V_3 -> V_39 = V_21 -> V_37 ;
V_30 = F_16 ( V_3 , sizeof( struct V_40 ) ) ;
if ( V_30 < 0 )
return - V_41 ;
for ( V_31 = 0 ; V_31 < 12 ; V_31 ++ ) {
V_14 -> V_15 [ V_31 ] = 0 ;
V_14 -> V_42 [ V_31 ] = & V_43 ;
}
#ifdef F_13
V_32 = 0 ;
if ( V_44 [ V_45 ] . V_46 != 0 ) {
V_32 = V_28 -> V_33 [ 1 ] ;
V_14 -> V_47 = 2 ;
if ( V_32 ) {
if ( ( ( 1 << V_32 ) & V_44 [ V_45 ] . V_46 ) == 0 ) {
F_14 ( V_35
L_4
L_5 , V_32 ) ;
V_32 = 0 ;
} else {
if ( F_17 ( V_32 , V_48 , 0 ,
L_2 , V_3 ) ) {
F_14 ( V_35
L_6
L_5 , V_32 ) ;
V_32 = 0 ;
} else {
F_14 ( L_7 , V_32 ) ;
}
}
}
}
V_3 -> V_32 = V_32 ;
#endif
F_14 ( L_8 ) ;
V_30 = F_18 ( V_3 , 3 ) ;
if ( V_30 < 0 )
return V_30 ;
V_5 = V_3 -> V_49 + 0 ;
V_5 -> type = V_50 ;
V_5 -> V_51 = V_52 | V_53 ;
V_5 -> V_54 = V_21 -> V_55 ;
V_5 -> V_56 = 0xfff ;
V_5 -> V_57 = 1 ;
V_5 -> V_58 = F_5 ;
V_5 -> V_59 = F_8 ;
V_5 -> V_60 = V_14 -> V_42 ;
for ( V_31 = 0 ; V_31 < V_21 -> V_55 ; V_31 ++ ) {
int V_61 ;
V_61 = V_28 -> V_33 [ 2 + 1 ] ;
if ( ( V_61 < 0 ) || ( V_61 >= V_21 -> V_62 ) ) {
F_14
( L_9 ,
V_31 , V_61 , V_21 -> V_62 - 1 ) ;
V_61 = 0 ;
}
V_14 -> V_42 [ V_31 ] = V_21 -> V_63 [ V_61 ] ;
if ( V_14 -> V_42 [ V_31 ] -> V_64 [ 0 ] . V_65 ==
- V_14 -> V_42 [ V_31 ] -> V_64 [ 0 ] . V_66 )
V_14 -> V_15 [ V_31 ] = 1 ;
}
V_5 = V_3 -> V_49 + 1 ;
if ( ! V_21 -> V_67 ) {
V_5 -> type = V_68 ;
} else {
V_5 -> type = V_69 ;
V_5 -> V_51 = V_70 | V_53 ;
V_5 -> V_54 = 16 ;
V_5 -> V_56 = 1 ;
V_5 -> V_57 = 1 ;
V_5 -> V_71 = F_9 ;
V_5 -> V_72 = & V_73 ;
}
V_5 = V_3 -> V_49 + 2 ;
if ( ! V_21 -> V_67 ) {
V_5 -> type = V_68 ;
} else {
V_5 -> type = V_74 ;
V_5 -> V_51 = V_52 | V_53 ;
V_5 -> V_54 = 16 ;
V_5 -> V_56 = 1 ;
V_5 -> V_57 = 1 ;
V_5 -> V_71 = F_11 ;
V_5 -> V_72 = & V_73 ;
}
return 0 ;
}
static int F_19 ( struct V_2 * V_3 )
{
#ifdef F_13
if ( V_3 -> V_32 )
F_20 ( V_3 -> V_32 , V_3 ) ;
#endif
if ( V_3 -> V_16 )
F_21 ( V_3 -> V_16 , V_21 -> V_34 ) ;
return 0 ;
}
