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
int V_25 ;
for ( V_25 = 0 ; V_25 < V_6 -> V_28 ; V_25 ++ )
V_16 [ V_25 ] = V_18 -> V_33 [ V_20 ] ;
return V_6 -> V_28 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned int V_20 = F_5 ( V_6 -> V_21 ) ;
int V_34 = V_20 ? V_35 : V_36 ;
int V_37 = V_20 ? V_38 : V_39 ;
int V_40 = V_18 -> V_33 [ V_20 ] ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_6 -> V_28 ; V_25 ++ ) {
V_40 = V_16 [ V_25 ] ;
if ( V_18 -> V_41 [ V_20 ] )
V_40 ^= 0x800 ;
F_3 ( V_40 & 0xff , V_2 -> V_9 + V_34 ) ;
F_3 ( ( V_40 >> 8 ) & 0xff , V_2 -> V_9 + V_37 ) ;
}
V_18 -> V_33 [ V_20 ] = V_40 ;
return V_6 -> V_28 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
V_16 [ 1 ] = F_2 ( V_2 -> V_9 + V_42 ) ;
return V_6 -> V_28 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
if ( F_13 ( V_4 , V_16 ) ) {
F_3 ( V_4 -> V_43 ^ 0xff , V_2 -> V_9 + V_44 ) ;
}
V_16 [ 1 ] = V_4 -> V_43 ;
return V_6 -> V_28 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
const struct V_47 * V_48 = F_15 ( V_2 ) ;
struct V_17 * V_18 ;
struct V_3 * V_4 ;
int V_24 ;
V_24 = F_16 ( V_2 , V_46 -> V_49 [ 0 ] , 0x10 ) ;
if ( V_24 )
return V_24 ;
F_3 ( 0 , V_2 -> V_9 + V_10 ) ;
F_2 ( V_2 -> V_9 + V_26 ) ;
F_3 ( 0 , V_2 -> V_9 + V_12 ) ;
V_18 = F_17 ( V_2 , sizeof( * V_18 ) ) ;
if ( ! V_18 )
return - V_50 ;
V_18 -> V_32 = ( V_46 -> V_49 [ 4 ] == 0 ) ;
V_18 -> V_41 [ 0 ] = ( V_46 -> V_49 [ 6 ] == 0 ) ;
V_18 -> V_41 [ 1 ] = ( V_46 -> V_49 [ 8 ] == 0 ) ;
V_18 -> V_23 = 0xff ;
V_24 = F_18 ( V_2 , 4 ) ;
if ( V_24 )
return V_24 ;
V_4 = & V_2 -> V_51 [ 0 ] ;
V_4 -> type = V_52 ;
V_4 -> V_53 = V_54 | V_55 ;
V_4 -> V_56 = ( V_46 -> V_49 [ 2 ] ? 16 : 8 ) ;
V_4 -> V_57 = F_4 ;
V_4 -> V_58 = 0x0fff ;
V_4 -> V_59 = ( V_46 -> V_49 [ 3 ] < F_19 ( V_60 ) )
? V_60 [ V_46 -> V_49 [ 3 ] ]
: & V_61 ;
V_4 = & V_2 -> V_51 [ 1 ] ;
if ( V_48 -> V_62 ) {
V_4 -> type = V_63 ;
V_4 -> V_53 = V_64 ;
V_4 -> V_56 = 2 ;
V_4 -> V_57 = F_9 ;
V_4 -> V_65 = F_10 ;
V_4 -> V_58 = 0x0fff ;
V_4 -> V_66 = V_18 -> V_67 ;
V_18 -> V_67 [ 0 ] =
( V_46 -> V_49 [ 5 ] < F_19 ( V_68 ) )
? V_68 [ V_46 -> V_49 [ 5 ] ]
: & V_61 ;
V_18 -> V_67 [ 1 ] =
( V_46 -> V_49 [ 7 ] < F_19 ( V_68 ) )
? V_68 [ V_46 -> V_49 [ 7 ] ]
: & V_61 ;
} else {
V_4 -> type = V_69 ;
}
V_4 = & V_2 -> V_51 [ 2 ] ;
V_4 -> type = V_70 ;
V_4 -> V_53 = V_54 ;
V_4 -> V_56 = 8 ;
V_4 -> V_71 = F_11 ;
V_4 -> V_58 = 1 ;
V_4 -> V_59 = & V_72 ;
V_4 = & V_2 -> V_51 [ 3 ] ;
V_4 -> type = V_73 ;
V_4 -> V_53 = V_64 ;
V_4 -> V_56 = 8 ;
V_4 -> V_71 = F_12 ;
V_4 -> V_58 = 1 ;
V_4 -> V_59 = & V_72 ;
return 0 ;
}
