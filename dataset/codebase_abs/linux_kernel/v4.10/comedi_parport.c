static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( F_2 ( V_4 , V_7 ) )
F_3 ( V_4 -> V_8 , V_2 -> V_9 + V_10 ) ;
V_7 [ 1 ] = F_4 ( V_2 -> V_9 + V_10 ) ;
return V_6 -> V_11 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_12 ;
int V_13 ;
V_13 = F_6 ( V_2 , V_4 , V_6 , V_7 , 0xff ) ;
if ( V_13 )
return V_13 ;
V_12 = F_4 ( V_2 -> V_9 + V_14 ) ;
if ( V_4 -> V_15 )
V_12 &= ~ V_16 ;
else
V_12 |= V_16 ;
F_3 ( V_12 , V_2 -> V_9 + V_14 ) ;
return V_6 -> V_11 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = F_4 ( V_2 -> V_9 + V_17 ) >> 3 ;
return V_6 -> V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_12 ;
if ( F_2 ( V_4 , V_7 ) ) {
V_12 = F_4 ( V_2 -> V_9 + V_14 ) ;
V_12 &= ( V_18 | V_16 ) ;
V_12 |= V_4 -> V_8 ;
F_3 ( V_12 , V_2 -> V_9 + V_14 ) ;
}
V_7 [ 1 ] = V_4 -> V_8 ;
return V_6 -> V_11 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = 0 ;
return V_6 -> V_11 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
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
struct V_3 * V_4 )
{
unsigned int V_12 ;
V_12 = F_4 ( V_2 -> V_9 + V_14 ) ;
V_12 |= V_18 ;
F_3 ( V_12 , V_2 -> V_9 + V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_12 ;
V_12 = F_4 ( V_2 -> V_9 + V_14 ) ;
V_12 &= ~ V_18 ;
F_3 ( V_12 , V_2 -> V_9 + V_14 ) ;
return 0 ;
}
static T_1 F_15 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
struct V_3 * V_4 = V_2 -> V_40 ;
unsigned int V_12 ;
V_12 = F_4 ( V_2 -> V_9 + V_14 ) ;
if ( ! ( V_12 & V_18 ) )
return V_41 ;
F_16 ( V_4 , & V_4 -> V_8 , 1 ) ;
F_17 ( V_2 , V_4 ) ;
return V_42 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_3 * V_4 ;
int V_13 ;
V_13 = F_19 ( V_2 , V_44 -> V_45 [ 0 ] , 0x03 ) ;
if ( V_13 )
return V_13 ;
if ( V_44 -> V_45 [ 1 ] ) {
V_13 = F_20 ( V_44 -> V_45 [ 1 ] , F_15 , 0 ,
V_2 -> V_46 , V_2 ) ;
if ( V_13 == 0 )
V_2 -> V_38 = V_44 -> V_45 [ 1 ] ;
}
V_13 = F_21 ( V_2 , V_2 -> V_38 ? 4 : 3 ) ;
if ( V_13 )
return V_13 ;
V_4 = & V_2 -> V_47 [ 0 ] ;
V_4 -> type = V_48 ;
V_4 -> V_49 = V_50 | V_51 ;
V_4 -> V_52 = 8 ;
V_4 -> V_53 = 1 ;
V_4 -> V_54 = & V_55 ;
V_4 -> V_56 = F_1 ;
V_4 -> V_57 = F_5 ;
V_4 = & V_2 -> V_47 [ 1 ] ;
V_4 -> type = V_58 ;
V_4 -> V_49 = V_50 ;
V_4 -> V_52 = 5 ;
V_4 -> V_53 = 1 ;
V_4 -> V_54 = & V_55 ;
V_4 -> V_56 = F_7 ;
V_4 = & V_2 -> V_47 [ 2 ] ;
V_4 -> type = V_59 ;
V_4 -> V_49 = V_51 ;
V_4 -> V_52 = 4 ;
V_4 -> V_53 = 1 ;
V_4 -> V_54 = & V_55 ;
V_4 -> V_56 = F_8 ;
if ( V_2 -> V_38 ) {
V_4 = & V_2 -> V_47 [ 3 ] ;
V_2 -> V_40 = V_4 ;
V_4 -> type = V_58 ;
V_4 -> V_49 = V_50 | V_60 ;
V_4 -> V_52 = 1 ;
V_4 -> V_53 = 1 ;
V_4 -> V_54 = & V_55 ;
V_4 -> V_56 = F_9 ;
V_4 -> V_61 = 1 ;
V_4 -> V_62 = F_10 ;
V_4 -> V_63 = F_13 ;
V_4 -> V_64 = F_14 ;
}
F_3 ( 0 , V_2 -> V_9 + V_10 ) ;
F_3 ( 0 , V_2 -> V_9 + V_14 ) ;
return 0 ;
}
