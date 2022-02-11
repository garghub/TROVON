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
if ( F_12 ( V_14 , V_17 ) ) {
F_3 ( V_14 -> V_44 ^ 0xff , V_2 -> V_6 + V_45 ) ;
}
V_17 [ 1 ] = V_14 -> V_44 ;
return V_16 -> V_28 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
const struct V_48 * V_49 = F_14 ( V_2 ) ;
struct V_18 * V_19 ;
struct V_13 * V_14 ;
int V_25 ;
V_25 = F_15 ( V_2 , V_47 -> V_50 [ 0 ] , V_51 ) ;
if ( V_25 )
return V_25 ;
F_3 ( 0 , V_2 -> V_6 + V_7 ) ;
F_2 ( V_2 -> V_6 + V_26 ) ;
F_3 ( 0 , V_2 -> V_6 + V_9 ) ;
V_19 = F_16 ( V_2 , sizeof( * V_19 ) ) ;
if ( ! V_19 )
return - V_52 ;
V_19 -> V_33 = ( V_47 -> V_50 [ 4 ] == 0 ) ;
V_19 -> V_42 [ 0 ] = ( V_47 -> V_50 [ 6 ] == 0 ) ;
V_19 -> V_42 [ 1 ] = ( V_47 -> V_50 [ 8 ] == 0 ) ;
V_19 -> V_24 = 0xff ;
V_25 = F_17 ( V_2 , 4 ) ;
if ( V_25 )
return V_25 ;
V_14 = & V_2 -> V_53 [ 0 ] ;
V_14 -> type = V_54 ;
V_14 -> V_55 = V_56 | V_57 ;
V_14 -> V_58 = ( V_47 -> V_50 [ 2 ] ? 16 : 8 ) ;
V_14 -> V_59 = F_5 ;
V_14 -> V_60 = 0x0fff ;
V_14 -> V_61 = ( V_47 -> V_50 [ 3 ] < F_18 ( V_62 ) )
? V_62 [ V_47 -> V_50 [ 3 ] ]
: & V_63 ;
V_14 = & V_2 -> V_53 [ 1 ] ;
if ( V_49 -> V_64 ) {
V_14 -> type = V_65 ;
V_14 -> V_55 = V_66 ;
V_14 -> V_58 = 2 ;
V_14 -> V_59 = F_8 ;
V_14 -> V_67 = F_9 ;
V_14 -> V_60 = 0x0fff ;
V_14 -> V_68 = V_19 -> V_69 ;
V_19 -> V_69 [ 0 ] =
( V_47 -> V_50 [ 5 ] < F_18 ( V_70 ) )
? V_70 [ V_47 -> V_50 [ 5 ] ]
: & V_63 ;
V_19 -> V_69 [ 1 ] =
( V_47 -> V_50 [ 7 ] < F_18 ( V_70 ) )
? V_70 [ V_47 -> V_50 [ 7 ] ]
: & V_63 ;
} else {
V_14 -> type = V_71 ;
}
V_14 = & V_2 -> V_53 [ 2 ] ;
V_14 -> type = V_72 ;
V_14 -> V_55 = V_56 ;
V_14 -> V_58 = 8 ;
V_14 -> V_73 = F_10 ;
V_14 -> V_60 = 1 ;
V_14 -> V_61 = & V_74 ;
V_14 = & V_2 -> V_53 [ 3 ] ;
V_14 -> type = V_75 ;
V_14 -> V_55 = V_66 ;
V_14 -> V_58 = 8 ;
V_14 -> V_73 = F_11 ;
V_14 -> V_60 = 1 ;
V_14 -> V_61 = & V_74 ;
return 0 ;
}
