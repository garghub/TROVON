static unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= F_2 ( V_2 -> V_4 + V_6 ) << 8 ;
return V_3 ;
}
static T_1 F_3 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_12 ;
unsigned int V_3 ;
V_12 = F_2 ( V_2 -> V_4 + V_13 ) ;
if ( ! ( V_12 & V_14 ) )
return V_15 ;
V_3 = F_1 ( V_2 ) ;
V_3 |= ( V_12 << 16 ) ;
F_4 ( V_10 , & V_3 , 1 ) ;
F_5 ( V_2 , V_10 ) ;
return V_16 ;
}
static void F_6 ( struct V_1 * V_2 , bool V_17 )
{
if ( V_17 )
F_2 ( V_2 -> V_4 + V_18 ) ;
else
F_7 ( 0 , V_2 -> V_4 + V_18 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
F_6 ( V_2 , false ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
F_6 ( V_2 , true ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_19 * V_20 )
{
int V_21 = 0 ;
V_21 |= F_11 ( & V_20 -> V_22 , V_23 ) ;
V_21 |= F_11 ( & V_20 -> V_24 , V_25 ) ;
V_21 |= F_11 ( & V_20 -> V_26 , V_27 ) ;
V_21 |= F_11 ( & V_20 -> V_28 , V_29 ) ;
V_21 |= F_11 ( & V_20 -> V_30 , V_31 ) ;
if ( V_21 )
return 1 ;
V_21 |= F_12 ( & V_20 -> V_32 , 0 ) ;
V_21 |= F_12 ( & V_20 -> V_33 , 0 ) ;
V_21 |= F_12 ( & V_20 -> V_34 , 0 ) ;
V_21 |= F_12 ( & V_20 -> V_35 ,
V_20 -> V_36 ) ;
V_21 |= F_12 ( & V_20 -> V_37 , 0 ) ;
if ( V_21 )
return 3 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_38 * V_39 ,
unsigned int * V_40 )
{
if ( F_14 ( V_10 , V_40 ) ) {
F_7 ( V_10 -> V_41 & 0xff , V_2 -> V_4 + V_42 ) ;
F_7 ( ( V_10 -> V_41 >> 8 ) & 0xff ,
V_2 -> V_4 + V_43 ) ;
}
V_40 [ 1 ] = V_10 -> V_41 ;
return V_39 -> V_44 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_38 * V_39 ,
unsigned int * V_40 )
{
V_40 [ 1 ] = F_1 ( V_2 ) ;
return V_39 -> V_44 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_9 * V_10 ;
int V_47 ;
V_47 = F_17 ( V_2 , V_46 -> V_48 [ 0 ] , 0x8 ) ;
if ( V_47 )
return V_47 ;
F_6 ( V_2 , false ) ;
if ( ( 1 << V_46 -> V_48 [ 1 ] ) & 0xdcfc ) {
V_47 = F_18 ( V_46 -> V_48 [ 1 ] , F_3 , 0 ,
V_2 -> V_49 , V_2 ) ;
if ( V_47 == 0 )
V_2 -> V_7 = V_46 -> V_48 [ 1 ] ;
}
V_47 = F_19 ( V_2 , 2 ) ;
if ( V_47 )
return V_47 ;
V_10 = & V_2 -> V_50 [ 0 ] ;
V_10 -> type = V_51 ;
V_10 -> V_52 = V_53 ;
V_10 -> V_54 = 16 ;
V_10 -> V_55 = 1 ;
V_10 -> V_56 = & V_57 ;
V_10 -> V_58 = F_13 ;
V_10 -> V_41 = F_2 ( V_2 -> V_4 + V_42 ) |
( F_2 ( V_2 -> V_4 + V_43 ) << 8 ) ;
V_10 = & V_2 -> V_50 [ 1 ] ;
V_10 -> type = V_59 ;
V_10 -> V_52 = V_60 ;
V_10 -> V_54 = 16 ;
V_10 -> V_55 = 1 ;
V_10 -> V_56 = & V_57 ;
V_10 -> V_58 = F_15 ;
if ( V_2 -> V_7 ) {
V_2 -> V_11 = V_10 ;
V_10 -> V_52 |= V_61 | V_62 ;
V_10 -> V_63 = 1 ;
V_10 -> V_64 = F_10 ;
V_10 -> V_65 = F_9 ;
V_10 -> V_66 = F_8 ;
}
return 0 ;
}
