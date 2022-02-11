static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_8 ) ;
F_3 ( V_9 | V_10 , V_2 -> V_7 + V_11 ) ;
F_3 ( 0x03 , V_2 -> V_7 + V_12 ) ;
F_3 ( V_13 | V_9 | V_10 , V_2 -> V_7 + V_11 ) ;
V_4 -> V_14 = 0 ;
F_2 ( V_4 -> V_14 , V_2 -> V_7 + V_15 ) ;
V_4 -> V_16 = 0 ;
F_2 ( V_4 -> V_16 , V_2 -> V_7 + V_17 ) ;
F_4 ( V_2 -> V_7 + V_18 ) ;
V_4 -> V_6 |= V_19 ;
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_8 ) ;
F_2 ( 0 , V_2 -> V_7 + V_20 ) ;
F_2 ( 0 , V_2 -> V_7 + V_21 ) ;
F_2 ( 0 , V_2 -> V_7 + V_22 ) ;
V_4 -> V_6 &= ~ V_19 ;
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_28 ;
int V_29 = F_6 ( V_26 -> V_30 ) ;
short V_31 ;
for ( V_28 = 0 ; V_28 < V_26 -> V_32 ; V_28 ++ ) {
V_31 = V_27 [ V_28 ] - 0x800 ;
if ( V_29 == 0 ) {
V_4 -> V_6 |= V_19 ;
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_8 ) ;
}
F_2 ( V_31 , V_2 -> V_7 + F_7 ( V_29 ) ) ;
if ( V_29 == 0 ) {
V_4 -> V_6 &= ~ V_19 ;
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_8 ) ;
}
V_4 -> V_33 [ V_29 ] = V_27 [ V_28 ] ;
}
return V_28 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_28 ;
int V_29 = F_6 ( V_26 -> V_30 ) ;
for ( V_28 = 0 ; V_28 < V_26 -> V_32 ; V_28 ++ )
V_27 [ V_28 ] = V_4 -> V_33 [ V_29 ] ;
return V_28 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
if ( V_27 [ 0 ] ) {
V_24 -> V_34 &= ~ V_27 [ 0 ] ;
V_24 -> V_34 |= V_27 [ 0 ] & V_27 [ 1 ] ;
F_2 ( V_24 -> V_34 , V_2 -> V_7 + V_35 ) ;
}
V_27 [ 1 ] = F_4 ( V_2 -> V_7 + V_36 ) ;
return V_26 -> V_32 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned int * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_29 = F_6 ( V_26 -> V_30 ) ;
unsigned int V_37 ;
int V_38 ;
if ( V_29 < 4 )
V_37 = 0x0f ;
else
V_37 = 0xf0 ;
V_38 = F_11 ( V_2 , V_24 , V_26 , V_27 , V_37 ) ;
if ( V_38 )
return V_38 ;
if ( V_24 -> V_39 & 0x0f )
V_4 -> V_16 |= V_40 ;
else
V_4 -> V_16 &= ~ V_40 ;
if ( V_24 -> V_39 & 0xf0 )
V_4 -> V_16 |= V_41 ;
else
V_4 -> V_16 &= ~ V_41 ;
F_2 ( V_4 -> V_16 , V_2 -> V_7 + V_17 ) ;
return V_26 -> V_32 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_26 -> V_32 ; V_28 ++ )
V_27 [ V_28 ] = 0 ;
return V_26 -> V_32 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_42 , V_43 ;
unsigned int V_29 = F_6 ( V_26 -> V_30 ) ;
V_42 = ( ( V_29 & 0x7 ) << 8 ) | ( V_27 [ V_26 -> V_32 - 1 ] & 0xff ) ;
for ( V_43 = 1 << ( 11 - 1 ) ; V_43 ; V_43 >>= 1 ) {
F_2 ( V_4 -> V_14 | ( ( V_43 & V_42 ) ? V_44 : 0 ) ,
V_2 -> V_7 + V_15 ) ;
F_2 ( V_4 -> V_14 | V_45 | ( ( V_43 & V_42 ) ? V_44 : 0 ) ,
V_2 -> V_7 + V_15 ) ;
}
F_2 ( V_4 -> V_14 | ( ( ( V_29 >> 3 ) + 1 ) << 14 ) ,
V_2 -> V_7 + V_15 ) ;
F_2 ( V_4 -> V_14 , V_2 -> V_7 + V_15 ) ;
return V_26 -> V_32 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
const struct V_48 * V_49 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_23 * V_24 ;
int V_50 ;
int V_38 ;
V_50 = V_47 -> V_51 [ 3 ] ;
V_38 = F_16 ( V_2 , V_47 -> V_51 [ 0 ] , V_52 ) ;
if ( V_38 )
return V_38 ;
V_4 = F_17 ( V_2 , sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_53 ;
V_38 = F_18 ( V_2 , 4 ) ;
if ( V_38 )
return V_38 ;
V_24 = & V_2 -> V_54 [ 0 ] ;
V_24 -> type = V_55 ;
V_24 -> V_56 = V_57 ;
V_24 -> V_58 = V_49 -> V_59 ;
V_24 -> V_60 = ( 1 << 12 ) - 1 ;
if ( V_50 )
V_24 -> V_61 = & V_62 ;
else
V_24 -> V_61 = & V_63 ;
V_24 -> V_64 = & F_5 ;
V_24 -> V_65 = & F_8 ;
V_24 = & V_2 -> V_54 [ 1 ] ;
V_24 -> type = V_66 ;
V_24 -> V_56 = V_67 | V_57 ;
V_24 -> V_58 = 8 ;
V_24 -> V_60 = 1 ;
V_24 -> V_61 = & V_68 ;
V_24 -> V_69 = F_9 ;
V_24 -> V_70 = F_10 ;
V_24 = & V_2 -> V_54 [ 2 ] ;
V_24 -> type = V_71 ;
V_24 -> V_56 = V_57 | V_72 ;
V_24 -> V_58 = 21 ;
V_24 -> V_60 = 0xff ;
V_24 -> V_65 = F_12 ;
V_24 -> V_64 = F_13 ;
V_24 = & V_2 -> V_54 [ 3 ] ;
V_24 -> type = V_73 ;
F_1 ( V_2 ) ;
F_19 ( V_74 L_1 ) ;
return 0 ;
}
