static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 = F_3 ( V_2 -> V_8 ) ;
T_1 V_9 = F_4 ( V_2 -> V_8 ) ;
V_4 -> V_10 . integer . V_10 [ 0 ] = ( F_5 ( V_6 , V_7 ) ) & V_9 ? 1 : 0 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 = F_3 ( V_2 -> V_8 ) ;
T_1 V_9 = F_4 ( V_2 -> V_8 ) ;
if ( V_4 -> V_10 . integer . V_10 [ 0 ] )
F_7 ( V_6 , V_7 , ( F_5 ( V_6 , V_7 ) ) | V_9 ) ;
else
F_7 ( V_6 , V_7 , ( F_5 ( V_6 , V_7 ) ) & ~ V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
return F_9 ( V_6 , V_11 ) ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_5 * V_6 ,
unsigned int V_14 ,
unsigned int V_15 ,
struct V_16 * V_17 )
{
T_1 V_18 ;
F_11 ( V_6 , V_19 , V_17 -> V_20 -> V_21 ) ;
V_18 = F_5 ( V_6 , V_22 ) ;
V_18 &= 0xff << ( 8 * ( V_17 -> V_23 != V_24 ) ) ;
V_18 |= ( ( V_14 & 0xf ) << 4 ) << ( 8 * ( V_17 -> V_23 == V_24 ) ) ;
F_11 ( V_6 , V_22 , V_18 ) ;
F_12 ( V_6 , V_13 -> V_25 ,
V_14 , 0 , V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_16 * V_17 )
{
static unsigned int V_26 [] = { 8000 , 9600 , 16000 } ;
static struct V_27 V_28 = {
. V_29 = F_14 ( V_26 ) ,
. V_30 = V_26 ,
. V_9 = 0 ,
} ;
V_17 -> V_20 -> V_31 . V_32 = 80 ;
return V_27 ( V_17 -> V_20 , 0 ,
V_33 , & V_28 ) ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_34 * V_35 ;
V_35 = F_16 ( V_6 , L_1 ) ;
if ( ! V_35 )
return - V_36 ;
V_35 -> V_23 [ V_24 ] = V_37 ;
V_35 -> V_23 [ V_38 ] = V_37 ;
V_35 -> V_23 [ V_24 ] . V_25 = V_6 -> V_39 . V_40 ;
V_35 -> V_23 [ V_38 ] . V_25 = V_6 -> V_39 . V_40 ;
V_35 -> V_41 = V_42 ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_43 * V_44 = V_6 -> V_44 ;
unsigned V_45 ;
T_1 V_18 ;
if ( F_18 ( & V_6 -> V_39 ,
V_46 ) )
return - V_36 ;
F_19 ( V_6 , V_47 , 0 , V_48 , 0 ) ;
F_19 ( V_6 , V_6 -> V_39 . V_40 , 0 , V_49 , 0 ) ;
F_11 ( V_6 , V_19 , 9600 ) ;
F_11 ( V_6 , V_22 , V_50 | V_51 ) ;
F_11 ( V_6 , V_52 , 0 ) ;
V_45 = 10 ;
do {
F_20 ( 2 ) ;
V_18 = F_5 ( V_6 , V_52 ) ;
} while ( ( V_18 & V_53 ) != V_53 && V_45 -- );
if( ( V_18 & V_53 ) != V_53 ) {
F_21 ( V_6 , L_2 , V_18 ) ;
}
F_11 ( V_6 , V_54 , 0xffff ) ;
F_11 ( V_6 , V_55 , 0x0 ) ;
F_11 ( V_6 , V_56 , 0 ) ;
F_11 ( V_6 , V_57 , 0x200 ) ;
if( ( F_5 ( V_6 , V_58 ) & ( 1 << 6 ) ) == 0 ) {
F_22 ( V_6 ,
L_3 ,
F_5 ( V_6 , V_58 ) ) ;
}
V_44 -> V_59 = F_5 ( V_6 , V_60 ) & V_61 ;
return 0 ;
}
static void F_23 ( struct V_5 * V_6 )
{
F_24 ( V_6 -> V_44 ) ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_43 * V_44 = F_26 ( sizeof( * V_44 ) , V_62 ) ;
if ( V_44 == NULL )
return - V_36 ;
V_6 -> V_44 = V_44 ;
V_6 -> V_63 = V_64 ;
return 0 ;
}
