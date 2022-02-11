static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned char V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( V_8 & V_11 ) {
F_3 ( 0 , V_2 -> V_9 + V_12 ) ;
return - V_13 ;
}
if ( V_8 & V_14 )
return 0 ;
return - V_15 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned int V_20 = F_5 ( V_6 -> V_21 ) ;
unsigned int V_22 = F_6 ( V_6 -> V_21 ) ;
unsigned char V_23 ;
int V_24 ;
int V_25 ;
F_2 ( V_2 -> V_9 + V_26 ) ;
F_3 ( 0 , V_2 -> V_9 + V_12 ) ;
V_23 = V_20 | ( V_22 << 5 ) ;
if ( V_23 != V_18 -> V_23 ) {
V_18 -> V_23 = V_23 ;
F_3 ( V_18 -> V_23 , V_2 -> V_9 + V_27 ) ;
if ( V_6 -> V_28 > 0 ) {
int V_29 = ( V_22 == 0 ) ? 10 :
( V_22 == 1 ) ? 20 :
( V_22 == 2 ) ? 40 : 80 ;
F_7 ( V_29 ) ;
}
}
for ( V_25 = 0 ; V_25 < V_6 -> V_28 ; V_25 ++ ) {
F_3 ( 0 , V_2 -> V_9 + V_30 ) ;
V_24 = F_8 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_24 )
return V_24 ;
V_16 [ V_25 ] = F_2 ( V_2 -> V_9 + V_31 ) ;
V_16 [ V_25 ] |= ( F_2 ( V_2 -> V_9 + V_26 ) & 0xf ) << 8 ;
if ( V_18 -> V_32 )
V_16 [ V_25 ] ^= 0x800 ;
}
return V_6 -> V_28 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned int V_20 = F_5 ( V_6 -> V_21 ) ;
int V_33 = V_20 ? V_34 : V_35 ;
int V_36 = V_20 ? V_37 : V_38 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_6 -> V_28 ; V_25 ++ ) {
unsigned int V_39 = V_16 [ V_25 ] ;
V_4 -> V_40 [ V_20 ] = V_39 ;
if ( V_18 -> V_41 [ V_20 ] )
V_39 ^= 0x800 ;
F_3 ( V_39 & 0xff , V_2 -> V_9 + V_33 ) ;
F_3 ( ( V_39 >> 8 ) & 0xff , V_2 -> V_9 + V_36 ) ;
}
return V_6 -> V_28 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
V_16 [ 1 ] = F_2 ( V_2 -> V_9 + V_42 ) ;
return V_6 -> V_28 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
if ( F_12 ( V_4 , V_16 ) ) {
F_3 ( V_4 -> V_43 ^ 0xff , V_2 -> V_9 + V_44 ) ;
}
V_16 [ 1 ] = V_4 -> V_43 ;
return V_6 -> V_28 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
const struct V_47 * V_48 = V_2 -> V_49 ;
struct V_17 * V_18 ;
struct V_3 * V_4 ;
int V_24 ;
V_24 = F_14 ( V_2 , V_46 -> V_50 [ 0 ] , 0x10 ) ;
if ( V_24 )
return V_24 ;
F_3 ( 0 , V_2 -> V_9 + V_10 ) ;
F_2 ( V_2 -> V_9 + V_26 ) ;
F_3 ( 0 , V_2 -> V_9 + V_12 ) ;
V_18 = F_15 ( V_2 , sizeof( * V_18 ) ) ;
if ( ! V_18 )
return - V_51 ;
V_18 -> V_32 = ( V_46 -> V_50 [ 4 ] == 0 ) ;
V_18 -> V_41 [ 0 ] = ( V_46 -> V_50 [ 6 ] == 0 ) ;
V_18 -> V_41 [ 1 ] = ( V_46 -> V_50 [ 8 ] == 0 ) ;
V_18 -> V_23 = 0xff ;
V_24 = F_16 ( V_2 , 4 ) ;
if ( V_24 )
return V_24 ;
V_4 = & V_2 -> V_52 [ 0 ] ;
V_4 -> type = V_53 ;
V_4 -> V_54 = V_55 | V_56 ;
V_4 -> V_57 = ( V_46 -> V_50 [ 2 ] ? 16 : 8 ) ;
V_4 -> V_58 = F_4 ;
V_4 -> V_59 = 0x0fff ;
V_4 -> V_60 = ( V_46 -> V_50 [ 3 ] < F_17 ( V_61 ) )
? V_61 [ V_46 -> V_50 [ 3 ] ]
: & V_62 ;
V_4 = & V_2 -> V_52 [ 1 ] ;
if ( V_48 -> V_63 ) {
V_4 -> type = V_64 ;
V_4 -> V_54 = V_65 ;
V_4 -> V_57 = 2 ;
V_4 -> V_59 = 0x0fff ;
V_4 -> V_66 = V_18 -> V_67 ;
V_18 -> V_67 [ 0 ] =
( V_46 -> V_50 [ 5 ] < F_17 ( V_68 ) )
? V_68 [ V_46 -> V_50 [ 5 ] ]
: & V_62 ;
V_18 -> V_67 [ 1 ] =
( V_46 -> V_50 [ 7 ] < F_17 ( V_68 ) )
? V_68 [ V_46 -> V_50 [ 7 ] ]
: & V_62 ;
V_4 -> V_69 = F_9 ;
V_4 -> V_58 = V_70 ;
V_24 = F_18 ( V_4 ) ;
if ( V_24 )
return V_24 ;
} else {
V_4 -> type = V_71 ;
}
V_4 = & V_2 -> V_52 [ 2 ] ;
V_4 -> type = V_72 ;
V_4 -> V_54 = V_55 ;
V_4 -> V_57 = 8 ;
V_4 -> V_73 = F_10 ;
V_4 -> V_59 = 1 ;
V_4 -> V_60 = & V_74 ;
V_4 = & V_2 -> V_52 [ 3 ] ;
V_4 -> type = V_75 ;
V_4 -> V_54 = V_65 ;
V_4 -> V_57 = 8 ;
V_4 -> V_73 = F_11 ;
V_4 -> V_59 = 1 ;
V_4 -> V_60 = & V_74 ;
return 0 ;
}
