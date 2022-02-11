static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 , V_9 ;
int V_10 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
for ( V_10 = 0 ; V_10 < V_6 -> V_10 ; V_10 ++ ) {
V_9 = V_7 [ V_10 ] & 0xff ;
V_8 = ( V_7 [ V_10 ] >> 8 ) & 0xf ;
if ( V_13 -> V_14 [ V_11 ] )
V_8 ^= 0x8 ;
F_3 ( V_8 , V_2 -> V_15 + V_16 + 2 * V_11 ) ;
F_3 ( V_9 , V_2 -> V_15 + V_17 + 2 * V_11 ) ;
V_13 -> V_18 [ V_11 ] = V_7 [ V_10 ] ;
}
return V_10 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_11 = F_2 ( V_6 -> V_12 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_10 ; V_10 ++ )
V_7 [ V_10 ] = V_13 -> V_18 [ V_11 ] ;
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_10 != 2 )
return - V_19 ;
V_7 [ 1 ] = F_6 ( V_2 -> V_15 + V_20 -> V_21 ) |
( F_6 ( V_2 -> V_15 + V_20 -> V_22 ) << 8 ) ;
return 2 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_10 != 2 )
return - V_19 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_23 &= ~ V_7 [ 0 ] ;
V_4 -> V_23 |= V_7 [ 0 ] & V_7 [ 1 ] ;
}
if ( V_7 [ 1 ] & 0x00ff )
F_3 ( V_4 -> V_23 & 0xff , V_2 -> V_15 + V_20 -> V_24 ) ;
if ( V_7 [ 1 ] & 0xff00 )
F_3 ( ( V_4 -> V_23 >> 8 ) , V_2 -> V_15 + V_20 -> V_25 ) ;
V_7 [ 1 ] = V_4 -> V_23 ;
return 2 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_3 * V_4 ;
unsigned long V_15 ;
unsigned int V_28 ;
int V_29 , V_30 ;
#ifdef F_9
unsigned int V_31 ;
#endif
V_15 = V_27 -> V_32 [ 0 ] ;
V_28 = V_20 -> V_33 ;
F_10 ( V_34 L_1 , V_2 -> V_35 ,
V_20 -> V_36 , V_15 ) ;
if ( ! F_11 ( V_15 , V_28 , L_2 ) ) {
F_10 ( V_34 L_3 ) ;
return - V_37 ;
}
V_2 -> V_15 = V_15 ;
V_2 -> V_38 = V_20 -> V_36 ;
V_29 = F_12 ( V_2 , sizeof( struct V_39 ) ) ;
if ( V_29 < 0 )
return - V_40 ;
for ( V_30 = 0 ; V_30 < 12 ; V_30 ++ ) {
V_13 -> V_14 [ V_30 ] = 0 ;
V_13 -> V_41 [ V_30 ] = & V_42 ;
}
#ifdef F_9
V_31 = 0 ;
if ( V_43 [ V_44 ] . V_45 != 0 ) {
V_31 = V_27 -> V_32 [ 1 ] ;
V_13 -> V_46 = 2 ;
if ( V_31 ) {
if ( ( ( 1 << V_31 ) & V_43 [ V_44 ] . V_45 ) == 0 ) {
F_10 ( V_34
L_4
L_5 , V_31 ) ;
V_31 = 0 ;
} else {
if ( F_13 ( V_31 , V_47 , 0 ,
L_2 , V_2 ) ) {
F_10 ( V_34
L_6
L_5 , V_31 ) ;
V_31 = 0 ;
} else {
F_10 ( L_7 , V_31 ) ;
}
}
}
}
V_2 -> V_31 = V_31 ;
#endif
F_10 ( L_8 ) ;
V_29 = F_14 ( V_2 , 3 ) ;
if ( V_29 < 0 )
return V_29 ;
V_4 = V_2 -> V_48 + 0 ;
V_4 -> type = V_49 ;
V_4 -> V_50 = V_51 | V_52 ;
V_4 -> V_53 = V_20 -> V_54 ;
V_4 -> V_55 = 0xfff ;
V_4 -> V_56 = 1 ;
V_4 -> V_57 = F_1 ;
V_4 -> V_58 = F_4 ;
V_4 -> V_59 = V_13 -> V_41 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_54 ; V_30 ++ ) {
int V_60 ;
V_60 = V_27 -> V_32 [ 2 + 1 ] ;
if ( ( V_60 < 0 ) || ( V_60 >= V_20 -> V_61 ) ) {
F_10
( L_9 ,
V_30 , V_60 , V_20 -> V_61 - 1 ) ;
V_60 = 0 ;
}
V_13 -> V_41 [ V_30 ] = V_20 -> V_62 [ V_60 ] ;
if ( V_13 -> V_41 [ V_30 ] -> V_63 [ 0 ] . V_64 ==
- V_13 -> V_41 [ V_30 ] -> V_63 [ 0 ] . V_65 )
V_13 -> V_14 [ V_30 ] = 1 ;
}
V_4 = V_2 -> V_48 + 1 ;
if ( ! V_20 -> V_66 ) {
V_4 -> type = V_67 ;
} else {
V_4 -> type = V_68 ;
V_4 -> V_50 = V_69 | V_52 ;
V_4 -> V_53 = 16 ;
V_4 -> V_55 = 1 ;
V_4 -> V_56 = 1 ;
V_4 -> V_70 = F_5 ;
V_4 -> V_71 = & V_72 ;
}
V_4 = V_2 -> V_48 + 2 ;
if ( ! V_20 -> V_66 ) {
V_4 -> type = V_67 ;
} else {
V_4 -> type = V_73 ;
V_4 -> V_50 = V_51 | V_52 ;
V_4 -> V_53 = 16 ;
V_4 -> V_55 = 1 ;
V_4 -> V_56 = 1 ;
V_4 -> V_70 = F_7 ;
V_4 -> V_71 = & V_72 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
#ifdef F_9
if ( V_2 -> V_31 )
F_16 ( V_2 -> V_31 , V_2 ) ;
#endif
if ( V_2 -> V_15 )
F_17 ( V_2 -> V_15 , V_20 -> V_33 ) ;
}
