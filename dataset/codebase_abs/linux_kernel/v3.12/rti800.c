static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
unsigned char V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
V_4 = F_2 ( V_2 -> V_6 + V_7 ) ;
if ( V_4 & V_8 ) {
F_3 ( 0 , V_2 -> V_6 + V_9 ) ;
return - V_10 ;
}
if ( V_4 & V_11 )
return 0 ;
F_4 ( 1 ) ;
}
return - V_12 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_21 = F_6 ( V_16 -> V_22 ) ;
unsigned int V_23 = F_7 ( V_16 -> V_22 ) ;
unsigned char V_24 ;
int V_25 ;
int V_5 ;
F_2 ( V_2 -> V_6 + V_26 ) ;
F_3 ( 0 , V_2 -> V_6 + V_9 ) ;
V_24 = V_21 | ( V_23 << 5 ) ;
if ( V_24 != V_19 -> V_24 ) {
V_19 -> V_24 = V_24 ;
F_3 ( V_19 -> V_24 , V_2 -> V_6 + V_27 ) ;
if ( V_16 -> V_28 > 0 ) {
int V_29 = ( V_23 == 0 ) ? 10 :
( V_23 == 1 ) ? 20 :
( V_23 == 2 ) ? 40 : 80 ;
F_4 ( V_29 ) ;
}
}
for ( V_5 = 0 ; V_5 < V_16 -> V_28 ; V_5 ++ ) {
F_3 ( 0 , V_2 -> V_6 + V_30 ) ;
V_25 = F_1 ( V_2 , V_31 ) ;
if ( V_25 )
return V_25 ;
V_17 [ V_5 ] = F_2 ( V_2 -> V_6 + V_32 ) ;
V_17 [ V_5 ] |= ( F_2 ( V_2 -> V_6 + V_26 ) & 0xf ) << 8 ;
if ( V_19 -> V_33 )
V_17 [ V_5 ] ^= 0x800 ;
}
return V_16 -> V_28 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_21 = F_6 ( V_16 -> V_22 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_16 -> V_28 ; V_5 ++ )
V_17 [ V_5 ] = V_19 -> V_34 [ V_21 ] ;
return V_16 -> V_28 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_21 = F_6 ( V_16 -> V_22 ) ;
int V_35 = V_21 ? V_36 : V_37 ;
int V_38 = V_21 ? V_39 : V_40 ;
int V_41 = V_19 -> V_34 [ V_21 ] ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_16 -> V_28 ; V_5 ++ ) {
V_41 = V_17 [ V_5 ] ;
if ( V_19 -> V_42 [ V_21 ] )
V_41 ^= 0x800 ;
F_3 ( V_41 & 0xff , V_2 -> V_6 + V_35 ) ;
F_3 ( ( V_41 >> 8 ) & 0xff , V_2 -> V_6 + V_38 ) ;
}
V_19 -> V_34 [ V_21 ] = V_41 ;
return V_16 -> V_28 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
V_17 [ 1 ] = F_2 ( V_2 -> V_6 + V_43 ) ;
return V_16 -> V_28 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
unsigned int V_44 = V_17 [ 0 ] ;
unsigned int V_45 = V_17 [ 1 ] ;
if ( V_44 ) {
V_14 -> V_46 &= ~ V_44 ;
V_14 -> V_46 |= ( V_45 & V_44 ) ;
F_3 ( V_14 -> V_46 ^ 0xff , V_2 -> V_6 + V_47 ) ;
}
V_17 [ 1 ] = V_14 -> V_46 ;
return V_16 -> V_28 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
const struct V_50 * V_51 = F_13 ( V_2 ) ;
struct V_18 * V_19 ;
struct V_13 * V_14 ;
int V_25 ;
V_25 = F_14 ( V_2 , V_49 -> V_52 [ 0 ] , V_53 ) ;
if ( V_25 )
return V_25 ;
F_3 ( 0 , V_2 -> V_6 + V_7 ) ;
F_2 ( V_2 -> V_6 + V_26 ) ;
F_3 ( 0 , V_2 -> V_6 + V_9 ) ;
V_19 = F_15 ( V_2 , sizeof( * V_19 ) ) ;
if ( ! V_19 )
return - V_54 ;
V_19 -> V_33 = ( V_49 -> V_52 [ 4 ] == 0 ) ;
V_19 -> V_42 [ 0 ] = ( V_49 -> V_52 [ 6 ] == 0 ) ;
V_19 -> V_42 [ 1 ] = ( V_49 -> V_52 [ 8 ] == 0 ) ;
V_19 -> V_24 = 0xff ;
V_25 = F_16 ( V_2 , 4 ) ;
if ( V_25 )
return V_25 ;
V_14 = & V_2 -> V_55 [ 0 ] ;
V_14 -> type = V_56 ;
V_14 -> V_57 = V_58 | V_59 ;
V_14 -> V_60 = ( V_49 -> V_52 [ 2 ] ? 16 : 8 ) ;
V_14 -> V_61 = F_5 ;
V_14 -> V_62 = 0x0fff ;
V_14 -> V_63 = ( V_49 -> V_52 [ 3 ] < F_17 ( V_64 ) )
? V_64 [ V_49 -> V_52 [ 3 ] ]
: & V_65 ;
V_14 = & V_2 -> V_55 [ 1 ] ;
if ( V_51 -> V_66 ) {
V_14 -> type = V_67 ;
V_14 -> V_57 = V_68 ;
V_14 -> V_60 = 2 ;
V_14 -> V_61 = F_8 ;
V_14 -> V_69 = F_9 ;
V_14 -> V_62 = 0x0fff ;
V_14 -> V_70 = V_19 -> V_71 ;
V_19 -> V_71 [ 0 ] =
( V_49 -> V_52 [ 5 ] < F_17 ( V_72 ) )
? V_72 [ V_49 -> V_52 [ 5 ] ]
: & V_65 ;
V_19 -> V_71 [ 1 ] =
( V_49 -> V_52 [ 7 ] < F_17 ( V_72 ) )
? V_72 [ V_49 -> V_52 [ 7 ] ]
: & V_65 ;
} else {
V_14 -> type = V_73 ;
}
V_14 = & V_2 -> V_55 [ 2 ] ;
V_14 -> type = V_74 ;
V_14 -> V_57 = V_58 ;
V_14 -> V_60 = 8 ;
V_14 -> V_75 = F_10 ;
V_14 -> V_62 = 1 ;
V_14 -> V_63 = & V_76 ;
V_14 = & V_2 -> V_55 [ 3 ] ;
V_14 -> type = V_77 ;
V_14 -> V_57 = V_68 ;
V_14 -> V_60 = 8 ;
V_14 -> V_75 = F_11 ;
V_14 -> V_62 = 1 ;
V_14 -> V_63 = & V_76 ;
return 0 ;
}
