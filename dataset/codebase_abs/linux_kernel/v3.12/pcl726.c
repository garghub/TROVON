static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_12 ;
int V_13 ;
int V_14 = F_2 ( V_6 -> V_15 ) ;
for ( V_13 = 0 ; V_13 < V_6 -> V_13 ; V_13 ++ ) {
V_12 = V_7 [ V_13 ] & 0xff ;
V_11 = ( V_7 [ V_13 ] >> 8 ) & 0xf ;
if ( V_9 -> V_16 [ V_14 ] )
V_11 ^= 0x8 ;
F_3 ( V_11 , V_2 -> V_17 + V_18 + 2 * V_14 ) ;
F_3 ( V_12 , V_2 -> V_17 + V_19 + 2 * V_14 ) ;
V_9 -> V_20 [ V_14 ] = V_7 [ V_13 ] ;
}
return V_13 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_14 = F_2 ( V_6 -> V_15 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_13 ; V_13 ++ )
V_7 [ V_13 ] = V_9 -> V_20 [ V_14 ] ;
return V_13 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_21 * V_22 = F_6 ( V_2 ) ;
V_7 [ 1 ] = F_7 ( V_2 -> V_17 + V_22 -> V_23 ) |
( F_7 ( V_2 -> V_17 + V_22 -> V_24 ) << 8 ) ;
return V_6 -> V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_21 * V_22 = F_6 ( V_2 ) ;
if ( V_7 [ 0 ] ) {
V_4 -> V_25 &= ~ V_7 [ 0 ] ;
V_4 -> V_25 |= V_7 [ 0 ] & V_7 [ 1 ] ;
}
if ( V_7 [ 1 ] & 0x00ff )
F_3 ( V_4 -> V_25 & 0xff , V_2 -> V_17 + V_22 -> V_26 ) ;
if ( V_7 [ 1 ] & 0xff00 )
F_3 ( ( V_4 -> V_25 >> 8 ) , V_2 -> V_17 + V_22 -> V_27 ) ;
V_7 [ 1 ] = V_4 -> V_25 ;
return V_6 -> V_13 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
const struct V_21 * V_22 = F_6 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_30 , V_31 ;
#ifdef F_10
unsigned int V_32 ;
#endif
V_30 = F_11 ( V_2 , V_29 -> V_33 [ 0 ] , V_22 -> V_34 ) ;
if ( V_30 )
return V_30 ;
V_9 = F_12 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_35 ;
for ( V_31 = 0 ; V_31 < 12 ; V_31 ++ ) {
V_9 -> V_16 [ V_31 ] = 0 ;
V_9 -> V_36 [ V_31 ] = & V_37 ;
}
#ifdef F_10
V_32 = 0 ;
if ( V_38 [ V_22 ] . V_39 != 0 ) {
V_32 = V_29 -> V_33 [ 1 ] ;
V_9 -> V_40 = 2 ;
if ( V_32 ) {
if ( ( ( 1 << V_32 ) & V_38 [ V_22 ] . V_39 ) == 0 ) {
F_13 ( V_41
L_1
L_2 , V_32 ) ;
V_32 = 0 ;
} else {
if ( F_14 ( V_32 , V_42 , 0 ,
V_2 -> V_43 , V_2 ) ) {
F_13 ( V_41
L_3
L_2 , V_32 ) ;
V_32 = 0 ;
} else {
F_13 ( L_4 , V_32 ) ;
}
}
}
}
V_2 -> V_32 = V_32 ;
#endif
F_13 ( L_5 ) ;
V_30 = F_15 ( V_2 , 3 ) ;
if ( V_30 )
return V_30 ;
V_4 = & V_2 -> V_44 [ 0 ] ;
V_4 -> type = V_45 ;
V_4 -> V_46 = V_47 | V_48 ;
V_4 -> V_49 = V_22 -> V_50 ;
V_4 -> V_51 = 0xfff ;
V_4 -> V_52 = 1 ;
V_4 -> V_53 = F_1 ;
V_4 -> V_54 = F_4 ;
V_4 -> V_55 = V_9 -> V_36 ;
for ( V_31 = 0 ; V_31 < V_22 -> V_50 ; V_31 ++ ) {
int V_56 ;
V_56 = V_29 -> V_33 [ 2 + 1 ] ;
if ( ( V_56 < 0 ) || ( V_56 >= V_22 -> V_57 ) ) {
F_13
( L_6 ,
V_31 , V_56 , V_22 -> V_57 - 1 ) ;
V_56 = 0 ;
}
V_9 -> V_36 [ V_31 ] = V_22 -> V_58 [ V_56 ] ;
if ( V_9 -> V_36 [ V_31 ] -> V_59 [ 0 ] . V_60 ==
- V_9 -> V_36 [ V_31 ] -> V_59 [ 0 ] . V_61 )
V_9 -> V_16 [ V_31 ] = 1 ;
}
V_4 = & V_2 -> V_44 [ 1 ] ;
if ( ! V_22 -> V_62 ) {
V_4 -> type = V_63 ;
} else {
V_4 -> type = V_64 ;
V_4 -> V_46 = V_65 | V_48 ;
V_4 -> V_49 = 16 ;
V_4 -> V_51 = 1 ;
V_4 -> V_52 = 1 ;
V_4 -> V_66 = F_5 ;
V_4 -> V_67 = & V_68 ;
}
V_4 = & V_2 -> V_44 [ 2 ] ;
if ( ! V_22 -> V_62 ) {
V_4 -> type = V_63 ;
} else {
V_4 -> type = V_69 ;
V_4 -> V_46 = V_47 | V_48 ;
V_4 -> V_49 = 16 ;
V_4 -> V_51 = 1 ;
V_4 -> V_52 = 1 ;
V_4 -> V_66 = F_8 ;
V_4 -> V_67 = & V_68 ;
}
return 0 ;
}
