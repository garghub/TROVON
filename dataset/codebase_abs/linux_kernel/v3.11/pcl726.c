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
V_9 = F_12 ( sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
return - V_36 ;
V_2 -> V_10 = V_9 ;
for ( V_31 = 0 ; V_31 < 12 ; V_31 ++ ) {
V_9 -> V_16 [ V_31 ] = 0 ;
V_9 -> V_37 [ V_31 ] = & V_38 ;
}
#ifdef F_10
V_32 = 0 ;
if ( V_39 [ V_22 ] . V_40 != 0 ) {
V_32 = V_29 -> V_33 [ 1 ] ;
V_9 -> V_41 = 2 ;
if ( V_32 ) {
if ( ( ( 1 << V_32 ) & V_39 [ V_22 ] . V_40 ) == 0 ) {
F_13 ( V_42
L_1
L_2 , V_32 ) ;
V_32 = 0 ;
} else {
if ( F_14 ( V_32 , V_43 , 0 ,
V_2 -> V_44 , V_2 ) ) {
F_13 ( V_42
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
V_4 = & V_2 -> V_45 [ 0 ] ;
V_4 -> type = V_46 ;
V_4 -> V_47 = V_48 | V_49 ;
V_4 -> V_50 = V_22 -> V_51 ;
V_4 -> V_52 = 0xfff ;
V_4 -> V_53 = 1 ;
V_4 -> V_54 = F_1 ;
V_4 -> V_55 = F_4 ;
V_4 -> V_56 = V_9 -> V_37 ;
for ( V_31 = 0 ; V_31 < V_22 -> V_51 ; V_31 ++ ) {
int V_57 ;
V_57 = V_29 -> V_33 [ 2 + 1 ] ;
if ( ( V_57 < 0 ) || ( V_57 >= V_22 -> V_58 ) ) {
F_13
( L_6 ,
V_31 , V_57 , V_22 -> V_58 - 1 ) ;
V_57 = 0 ;
}
V_9 -> V_37 [ V_31 ] = V_22 -> V_59 [ V_57 ] ;
if ( V_9 -> V_37 [ V_31 ] -> V_60 [ 0 ] . V_61 ==
- V_9 -> V_37 [ V_31 ] -> V_60 [ 0 ] . V_62 )
V_9 -> V_16 [ V_31 ] = 1 ;
}
V_4 = & V_2 -> V_45 [ 1 ] ;
if ( ! V_22 -> V_63 ) {
V_4 -> type = V_64 ;
} else {
V_4 -> type = V_65 ;
V_4 -> V_47 = V_66 | V_49 ;
V_4 -> V_50 = 16 ;
V_4 -> V_52 = 1 ;
V_4 -> V_53 = 1 ;
V_4 -> V_67 = F_5 ;
V_4 -> V_68 = & V_69 ;
}
V_4 = & V_2 -> V_45 [ 2 ] ;
if ( ! V_22 -> V_63 ) {
V_4 -> type = V_64 ;
} else {
V_4 -> type = V_70 ;
V_4 -> V_47 = V_48 | V_49 ;
V_4 -> V_50 = 16 ;
V_4 -> V_52 = 1 ;
V_4 -> V_53 = 1 ;
V_4 -> V_67 = F_8 ;
V_4 -> V_68 = & V_69 ;
}
return 0 ;
}
