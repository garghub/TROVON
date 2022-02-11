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
unsigned int V_16 = F_4 ( V_14 -> V_17 ) ;
unsigned int V_18 = V_12 -> V_19 [ V_16 ] ;
int V_20 ;
if ( V_16 == 0 )
F_1 ( V_2 , 1 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_21 ; V_20 ++ ) {
V_18 = V_15 [ V_20 ] ;
F_2 ( F_5 ( V_12 , V_18 ) ,
V_2 -> V_9 + F_6 ( V_16 ) ) ;
}
V_12 -> V_19 [ V_16 ] = V_18 ;
if ( V_16 == 0 )
F_1 ( V_2 , 0 ) ;
return V_14 -> V_21 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
if ( F_8 ( V_12 , V_15 ) )
F_2 ( V_12 -> V_22 , V_2 -> V_9 + V_23 ) ;
V_15 [ 1 ] = F_9 ( V_2 -> V_9 + V_23 ) ;
return V_14 -> V_21 ;
}
static int F_10 ( struct V_1 * V_2 ,
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
V_25 = F_11 ( V_2 , V_12 , V_14 , V_15 , V_24 ) ;
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
return V_14 -> V_21 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
unsigned int V_16 = F_4 ( V_14 -> V_17 ) ;
if ( V_14 -> V_21 ) {
unsigned int V_18 = V_15 [ V_14 -> V_21 - 1 ] ;
unsigned int V_31 = ( ( V_16 & 0x7 ) << 8 ) | V_18 ;
unsigned int V_32 ;
int V_33 ;
for ( V_33 = 1 << 10 ; V_33 ; V_33 >>= 1 ) {
V_32 = ( V_33 & V_31 ) ? V_34 : 0 ;
F_2 ( V_32 , V_2 -> V_9 + V_35 ) ;
F_2 ( V_32 | V_36 ,
V_2 -> V_9 + V_35 ) ;
}
F_2 ( F_13 ( V_16 ) , V_2 -> V_9 + V_35 ) ;
F_2 ( V_37 , V_2 -> V_9 + V_35 ) ;
V_12 -> V_19 [ V_16 ] = V_18 ;
}
return V_14 -> V_21 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_38 = V_2 -> V_9 + V_39 ;
V_5 -> V_7 = 0 ;
F_2 ( V_5 -> V_7 , V_2 -> V_9 + V_10 ) ;
F_15 ( V_38 , 0 , 0 , V_40 | V_41 ) ;
F_15 ( V_38 , 0 , 1 , V_40 | V_41 ) ;
F_16 ( V_38 , 0 , 0 , 0x0003 ) ;
F_2 ( V_37 , V_2 -> V_9 + V_35 ) ;
V_5 -> V_27 = 0 ;
F_2 ( V_5 -> V_27 , V_2 -> V_9 + V_30 ) ;
F_9 ( V_2 -> V_9 + V_42 ) ;
F_1 ( V_2 , 1 ) ;
F_2 ( 0 , V_2 -> V_9 + V_43 ) ;
F_2 ( 0 , V_2 -> V_9 + V_44 ) ;
F_2 ( 0 , V_2 -> V_9 + V_45 ) ;
F_1 ( V_2 , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
const struct V_48 * V_49 = V_2 -> V_50 ;
struct V_4 * V_5 ;
struct V_11 * V_12 ;
int V_25 ;
V_25 = F_18 ( V_2 , V_47 -> V_51 [ 0 ] , 0x20 ) ;
if ( V_25 )
return V_25 ;
V_5 = F_19 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_52 ;
V_25 = F_20 ( V_2 , 4 ) ;
if ( V_25 )
return V_25 ;
V_12 = & V_2 -> V_53 [ 0 ] ;
V_12 -> type = V_54 ;
V_12 -> V_55 = V_56 ;
V_12 -> V_57 = V_49 -> V_58 ;
V_12 -> V_59 = 0x0fff ;
V_12 -> V_60 = V_47 -> V_51 [ 3 ] ? & V_61 : & V_62 ;
V_12 -> V_63 = F_3 ;
V_25 = F_21 ( V_12 ) ;
if ( V_25 )
return V_25 ;
V_12 = & V_2 -> V_53 [ 1 ] ;
V_12 -> type = V_64 ;
V_12 -> V_55 = V_65 | V_56 ;
V_12 -> V_57 = 8 ;
V_12 -> V_59 = 1 ;
V_12 -> V_60 = & V_66 ;
V_12 -> V_67 = F_7 ;
V_12 -> V_68 = F_10 ;
V_12 = & V_2 -> V_53 [ 2 ] ;
V_12 -> type = V_69 ;
V_12 -> V_55 = V_56 | V_70 ;
V_12 -> V_57 = ( V_49 -> V_58 * 2 ) + 1 ;
V_12 -> V_59 = 0xff ;
V_12 -> V_63 = F_12 ;
V_25 = F_21 ( V_12 ) ;
if ( V_25 )
return V_25 ;
V_12 = & V_2 -> V_53 [ 3 ] ;
V_12 -> type = V_71 ;
F_14 ( V_2 ) ;
return 0 ;
}
