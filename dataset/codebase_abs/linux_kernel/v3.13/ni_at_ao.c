static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 )
V_5 -> V_7 |= V_8 ;
else
V_5 -> V_7 &= ~ V_8 ;
F_2 ( V_5 -> V_7 , V_2 -> V_9 + V_10 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_16 = F_4 ( V_14 -> V_17 ) ;
unsigned int V_18 ;
int V_19 ;
if ( V_16 == 0 )
F_1 ( V_2 , 1 ) ;
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ ) {
V_18 = V_15 [ V_19 ] ;
V_5 -> V_21 [ V_16 ] = V_18 ;
V_18 = F_5 ( V_12 , V_18 ) ;
F_2 ( V_18 , V_2 -> V_9 + F_6 ( V_16 ) ) ;
}
if ( V_16 == 0 )
F_1 ( V_2 , 0 ) ;
return V_14 -> V_20 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_16 = F_4 ( V_14 -> V_17 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ )
V_15 [ V_19 ] = V_5 -> V_21 [ V_16 ] ;
return V_14 -> V_20 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
if ( F_9 ( V_12 , V_15 ) )
F_2 ( V_12 -> V_22 , V_2 -> V_9 + V_23 ) ;
V_15 [ 1 ] = F_10 ( V_2 -> V_9 + V_23 ) ;
return V_14 -> V_20 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_16 = F_4 ( V_14 -> V_17 ) ;
unsigned int V_24 ;
int V_25 ;
if ( V_16 < 4 )
V_24 = 0x0f ;
else
V_24 = 0xf0 ;
V_25 = F_12 ( V_2 , V_12 , V_14 , V_15 , V_24 ) ;
if ( V_25 )
return V_25 ;
if ( V_12 -> V_26 & 0x0f )
V_5 -> V_27 |= V_28 ;
else
V_5 -> V_27 &= ~ V_28 ;
if ( V_12 -> V_26 & 0xf0 )
V_5 -> V_27 |= V_29 ;
else
V_5 -> V_27 &= ~ V_29 ;
F_2 ( V_5 -> V_27 , V_2 -> V_9 + V_30 ) ;
return V_14 -> V_20 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_16 = F_4 ( V_14 -> V_17 ) ;
unsigned int V_31 ;
unsigned int V_18 ;
int V_32 ;
if ( V_14 -> V_20 == 0 )
return 0 ;
V_5 -> V_33 [ V_16 ] = V_15 [ V_14 -> V_20 - 1 ] & V_12 -> V_34 ;
V_31 = ( ( V_16 & 0x7 ) << 8 ) | V_5 -> V_33 [ V_16 ] ;
for ( V_32 = 1 << 10 ; V_32 ; V_32 >>= 1 ) {
V_18 = ( V_32 & V_31 ) ? V_35 : 0 ;
F_2 ( V_18 , V_2 -> V_9 + V_36 ) ;
F_2 ( V_18 | V_37 , V_2 -> V_9 + V_36 ) ;
}
F_2 ( F_14 ( V_16 ) , V_2 -> V_9 + V_36 ) ;
F_2 ( V_38 , V_2 -> V_9 + V_36 ) ;
return V_14 -> V_20 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_16 = F_4 ( V_14 -> V_17 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_20 ; V_19 ++ )
V_15 [ V_19 ] = V_5 -> V_33 [ V_16 ] ;
return V_14 -> V_20 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_5 -> V_7 = 0 ;
F_2 ( V_5 -> V_7 , V_2 -> V_9 + V_10 ) ;
F_17 ( V_2 -> V_9 + V_39 , 0 ,
0 , 0x0003 , V_40 | V_41 ) ;
F_18 ( V_2 -> V_9 + V_39 , 0 ,
1 , V_40 | V_41 ) ;
F_2 ( V_38 , V_2 -> V_9 + V_36 ) ;
V_5 -> V_27 = 0 ;
F_2 ( V_5 -> V_27 , V_2 -> V_9 + V_30 ) ;
F_10 ( V_2 -> V_9 + V_42 ) ;
F_1 ( V_2 , 1 ) ;
F_2 ( 0 , V_2 -> V_9 + V_43 ) ;
F_2 ( 0 , V_2 -> V_9 + V_44 ) ;
F_2 ( 0 , V_2 -> V_9 + V_45 ) ;
F_1 ( V_2 , 0 ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
const struct V_48 * V_49 = F_20 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_11 * V_12 ;
int V_25 ;
V_25 = F_21 ( V_2 , V_47 -> V_50 [ 0 ] , 0x20 ) ;
if ( V_25 )
return V_25 ;
V_5 = F_22 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_51 ;
V_25 = F_23 ( V_2 , 4 ) ;
if ( V_25 )
return V_25 ;
V_12 = & V_2 -> V_52 [ 0 ] ;
V_12 -> type = V_53 ;
V_12 -> V_54 = V_55 ;
V_12 -> V_56 = V_49 -> V_57 ;
V_12 -> V_34 = 0x0fff ;
V_12 -> V_58 = V_47 -> V_50 [ 3 ] ? & V_59 : & V_60 ;
V_12 -> V_61 = F_3 ;
V_12 -> V_62 = F_7 ;
V_12 = & V_2 -> V_52 [ 1 ] ;
V_12 -> type = V_63 ;
V_12 -> V_54 = V_64 | V_55 ;
V_12 -> V_56 = 8 ;
V_12 -> V_34 = 1 ;
V_12 -> V_58 = & V_65 ;
V_12 -> V_66 = F_8 ;
V_12 -> V_67 = F_11 ;
V_12 = & V_2 -> V_52 [ 2 ] ;
V_12 -> type = V_68 ;
V_12 -> V_54 = V_55 | V_69 ;
V_12 -> V_56 = ( V_49 -> V_57 * 2 ) + 1 ;
V_12 -> V_34 = 0xff ;
V_12 -> V_62 = F_15 ;
V_12 -> V_61 = F_13 ;
V_12 = & V_2 -> V_52 [ 3 ] ;
V_12 -> type = V_70 ;
F_16 ( V_2 ) ;
return 0 ;
}
