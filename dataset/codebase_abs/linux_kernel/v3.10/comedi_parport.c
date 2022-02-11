static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_7 [ 0 ] ) {
V_9 -> V_11 &= ~ V_7 [ 0 ] ;
V_9 -> V_11 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_9 -> V_11 , V_2 -> V_12 + V_13 ) ;
}
V_7 [ 1 ] = F_3 ( V_2 -> V_12 + V_13 ) ;
return V_6 -> V_14 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_15 = 0xff ;
V_9 -> V_16 &= ~ ( 1 << 5 ) ;
} else {
V_4 -> V_15 = 0 ;
V_9 -> V_16 |= ( 1 << 5 ) ;
}
F_2 ( V_9 -> V_16 , V_2 -> V_12 + V_17 ) ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
}
V_7 [ 1 ] = ( F_3 ( V_2 -> V_12 + V_18 ) >> 3 ) ;
return V_6 -> V_14 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_7 [ 0 ] &= 0x0f ;
if ( V_7 [ 0 ] ) {
V_9 -> V_16 &= ~ V_7 [ 0 ] ;
V_9 -> V_16 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_9 -> V_16 , V_2 -> V_12 + V_17 ) ;
}
V_7 [ 1 ] = V_9 -> V_16 & 0xf ;
return V_6 -> V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = 0 ;
return V_6 -> V_14 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_19 * V_20 )
{
int V_21 = 0 ;
V_21 |= F_9 ( & V_20 -> V_22 , V_23 ) ;
V_21 |= F_9 ( & V_20 -> V_24 , V_25 ) ;
V_21 |= F_9 ( & V_20 -> V_26 , V_27 ) ;
V_21 |= F_9 ( & V_20 -> V_28 , V_29 ) ;
V_21 |= F_9 ( & V_20 -> V_30 , V_31 ) ;
if ( V_21 )
return 1 ;
if ( V_21 )
return 2 ;
V_21 |= F_10 ( & V_20 -> V_32 , 0 ) ;
V_21 |= F_10 ( & V_20 -> V_33 , 0 ) ;
V_21 |= F_10 ( & V_20 -> V_34 , 0 ) ;
V_21 |= F_10 ( & V_20 -> V_35 , 1 ) ;
V_21 |= F_10 ( & V_20 -> V_36 , 0 ) ;
if ( V_21 )
return 3 ;
if ( V_21 )
return 4 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_9 -> V_16 |= 0x10 ;
F_2 ( V_9 -> V_16 , V_2 -> V_12 + V_17 ) ;
V_9 -> V_37 = 1 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_9 -> V_16 &= ~ 0x10 ;
F_2 ( V_9 -> V_16 , V_2 -> V_12 + V_17 ) ;
V_9 -> V_37 = 0 ;
return 0 ;
}
static T_1 F_13 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = & V_2 -> V_40 [ 3 ] ;
if ( ! V_9 -> V_37 )
return V_41 ;
F_14 ( V_4 -> V_42 , 0 ) ;
V_4 -> V_42 -> V_43 |= V_44 | V_45 ;
F_15 ( V_2 , V_4 ) ;
return V_46 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 ;
unsigned int V_38 ;
int V_49 ;
V_49 = F_17 ( V_2 , V_48 -> V_50 [ 0 ] , V_51 ) ;
if ( V_49 )
return V_49 ;
V_38 = V_48 -> V_50 [ 1 ] ;
if ( V_38 ) {
V_49 = F_18 ( V_38 , F_13 , 0 , V_2 -> V_52 ,
V_2 ) ;
if ( V_49 < 0 ) {
F_19 ( V_2 -> V_53 , L_1 ) ;
return - V_54 ;
}
V_2 -> V_38 = V_38 ;
}
V_49 = F_20 ( V_2 , 4 ) ;
if ( V_49 )
return V_49 ;
V_9 = F_21 ( sizeof( * V_9 ) , V_55 ) ;
if ( ! V_9 )
return - V_56 ;
V_2 -> V_10 = V_9 ;
V_4 = & V_2 -> V_40 [ 0 ] ;
V_4 -> type = V_57 ;
V_4 -> V_58 = V_59 | V_60 ;
V_4 -> V_61 = 8 ;
V_4 -> V_62 = 1 ;
V_4 -> V_63 = & V_64 ;
V_4 -> V_65 = F_1 ;
V_4 -> V_66 = F_4 ;
V_4 = & V_2 -> V_40 [ 1 ] ;
V_4 -> type = V_67 ;
V_4 -> V_58 = V_59 ;
V_4 -> V_61 = 5 ;
V_4 -> V_62 = 1 ;
V_4 -> V_63 = & V_64 ;
V_4 -> V_65 = F_5 ;
V_4 = & V_2 -> V_40 [ 2 ] ;
V_4 -> type = V_68 ;
V_4 -> V_58 = V_60 ;
V_4 -> V_61 = 4 ;
V_4 -> V_62 = 1 ;
V_4 -> V_63 = & V_64 ;
V_4 -> V_65 = F_6 ;
V_4 = & V_2 -> V_40 [ 3 ] ;
if ( V_38 ) {
V_2 -> V_69 = V_4 ;
V_4 -> type = V_67 ;
V_4 -> V_58 = V_59 | V_70 ;
V_4 -> V_61 = 1 ;
V_4 -> V_62 = 1 ;
V_4 -> V_63 = & V_64 ;
V_4 -> V_65 = F_7 ;
V_4 -> V_71 = F_8 ;
V_4 -> V_72 = F_11 ;
V_4 -> V_73 = F_12 ;
} else {
V_4 -> type = V_74 ;
}
V_9 -> V_11 = 0 ;
F_2 ( V_9 -> V_11 , V_2 -> V_12 + V_13 ) ;
V_9 -> V_16 = 0 ;
F_2 ( V_9 -> V_16 , V_2 -> V_12 + V_17 ) ;
return 0 ;
}
