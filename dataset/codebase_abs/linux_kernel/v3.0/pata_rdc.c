static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
T_1 V_7 ;
V_7 = 0x30 << ( 2 * V_2 -> V_8 ) ;
if ( ( V_4 -> V_9 & V_7 ) == 0 )
return V_10 ;
return V_11 ;
}
static int F_2 ( struct V_12 * V_13 , unsigned long V_14 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_15 * V_16 = F_3 ( V_2 -> V_5 -> V_17 ) ;
static const struct V_18 V_19 [] = {
{ 0x41U , 1U , 0x80UL , 0x80UL } ,
{ 0x43U , 1U , 0x80UL , 0x80UL } ,
} ;
if ( ! F_4 ( V_16 , & V_19 [ V_2 -> V_8 ] ) )
return - V_20 ;
return F_5 ( V_13 , V_14 ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
unsigned int V_23 = V_22 -> V_24 - V_25 ;
struct V_15 * V_17 = F_3 ( V_2 -> V_5 -> V_17 ) ;
unsigned int V_26 = ( V_22 -> V_27 != 0 ) ;
unsigned int V_28 = V_2 -> V_8 ? 0x42 : 0x40 ;
unsigned int V_29 = 0x44 ;
T_2 V_30 ;
T_1 V_31 ;
T_1 V_32 ;
int V_33 = 0 ;
static const
T_1 V_34 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
if ( V_23 >= 2 )
V_33 |= 1 ;
if ( F_7 ( V_22 ) )
V_33 |= 2 ;
if ( V_22 -> V_35 == V_36 )
V_33 |= 4 ;
F_8 ( V_17 , V_28 , & V_30 ) ;
if ( V_26 ) {
V_30 &= 0xff0f ;
V_30 |= 0x4000 ;
V_30 |= ( V_33 << 4 ) ;
F_9 ( V_17 , V_29 , & V_31 ) ;
V_31 &= ( V_2 -> V_8 ? 0x0f : 0xf0 ) ;
V_31 |= ( ( V_34 [ V_23 ] [ 0 ] << 2 ) | V_34 [ V_23 ] [ 1 ] )
<< ( V_2 -> V_8 ? 4 : 0 ) ;
} else {
V_30 &= 0xccf0 ;
V_30 |= V_33 ;
V_30 |=
( V_34 [ V_23 ] [ 0 ] << 12 ) |
( V_34 [ V_23 ] [ 1 ] << 8 ) ;
}
F_10 ( V_17 , V_28 , V_30 ) ;
if ( V_26 )
F_11 ( V_17 , V_29 , V_31 ) ;
F_9 ( V_17 , 0x48 , & V_32 ) ;
V_32 &= ~ ( 1 << ( 2 * V_2 -> V_8 + V_22 -> V_27 ) ) ;
F_11 ( V_17 , 0x48 , V_32 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_15 * V_17 = F_3 ( V_2 -> V_5 -> V_17 ) ;
T_1 V_28 = V_2 -> V_8 ? 0x42 : 0x40 ;
T_2 V_30 ;
T_1 V_37 = V_22 -> V_38 ;
int V_39 = V_22 -> V_27 + 2 * V_2 -> V_8 ;
T_1 V_32 = 0 ;
static const
T_1 V_34 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
F_8 ( V_17 , V_28 , & V_30 ) ;
F_9 ( V_17 , 0x48 , & V_32 ) ;
if ( V_37 >= V_40 ) {
unsigned int V_41 = V_22 -> V_38 - V_40 ;
T_2 V_42 ;
T_2 V_43 ;
int V_44 , V_45 ;
V_45 = F_13 ( 2 - ( V_41 & 1 ) , V_41 ) ;
if ( V_41 == 5 )
V_44 = 0x1000 ;
else if ( V_41 > 2 )
V_44 = 1 ;
else
V_44 = 0 ;
V_32 |= ( 1 << V_39 ) ;
F_8 ( V_17 , 0x4A , & V_42 ) ;
V_42 &= ~ ( 3 << ( 4 * V_39 ) ) ;
V_42 |= V_45 << ( 4 * V_39 ) ;
F_10 ( V_17 , 0x4A , V_42 ) ;
F_8 ( V_17 , 0x54 , & V_43 ) ;
V_43 &= ~ ( 0x1001 << V_39 ) ;
V_43 |= V_44 << V_39 ;
F_10 ( V_17 , 0x54 , V_43 ) ;
} else {
unsigned int V_46 = V_22 -> V_38 - V_47 ;
unsigned int V_33 ;
T_1 V_31 ;
const unsigned int V_48 [ 3 ] = {
V_25 , V_49 , V_50
} ;
int V_23 = V_48 [ V_46 ] - V_25 ;
V_33 = 3 ;
if ( V_22 -> V_24 < V_48 [ V_46 ] )
V_33 |= 8 ;
if ( V_22 -> V_27 ) {
V_30 &= 0xFF4F ;
V_30 |= V_33 << 4 ;
F_9 ( V_17 , 0x44 , & V_31 ) ;
V_31 &= ( V_2 -> V_8 ? 0x0f : 0xf0 ) ;
V_31 |= ( ( V_34 [ V_23 ] [ 0 ] << 2 ) | V_34 [ V_23 ] [ 1 ] ) << ( V_2 -> V_8 ? 4 : 0 ) ;
F_11 ( V_17 , 0x44 , V_31 ) ;
} else {
V_30 &= 0xCCF4 ;
V_30 |= V_33 ;
V_30 |=
( V_34 [ V_23 ] [ 0 ] << 12 ) |
( V_34 [ V_23 ] [ 1 ] << 8 ) ;
}
V_32 &= ~ ( 1 << V_39 ) ;
F_10 ( V_17 , V_28 , V_30 ) ;
}
F_11 ( V_17 , 0x48 , V_32 ) ;
}
static int T_3 F_14 ( struct V_15 * V_16 ,
const struct V_51 * V_52 )
{
static int V_53 ;
struct V_54 * V_17 = & V_16 -> V_17 ;
struct V_55 V_56 [ 2 ] ;
const struct V_55 * V_57 [] = { & V_56 [ 0 ] , & V_56 [ 1 ] } ;
unsigned long V_58 ;
struct V_59 * V_5 ;
struct V_3 * V_4 ;
int V_60 ;
if ( ! V_53 ++ )
F_15 ( V_61 , & V_16 -> V_17 ,
L_1 V_62 L_2 ) ;
V_56 [ 0 ] = V_63 ;
V_56 [ 1 ] = V_63 ;
V_58 = V_56 [ 0 ] . V_64 ;
V_60 = F_16 ( V_16 ) ;
if ( V_60 )
return V_60 ;
V_4 = F_17 ( V_17 , sizeof( * V_4 ) , V_65 ) ;
if ( ! V_4 )
return - V_66 ;
F_18 ( V_16 , 0x54 , & V_4 -> V_9 ) ;
V_60 = F_19 ( V_16 , V_57 , & V_5 ) ;
if ( V_60 )
return V_60 ;
V_5 -> V_6 = V_4 ;
F_20 ( V_16 , 1 ) ;
V_5 -> V_64 |= V_67 ;
F_21 ( V_16 ) ;
return F_22 ( V_5 , V_68 , & V_69 ) ;
}
static void F_23 ( struct V_15 * V_16 )
{
struct V_59 * V_5 = F_24 ( & V_16 -> V_17 ) ;
struct V_3 * V_4 = V_5 -> V_6 ;
F_25 ( V_16 , 0x54 , V_4 -> V_9 ) ;
F_26 ( V_16 ) ;
}
static int T_4 F_27 ( void )
{
return F_28 ( & V_70 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_70 ) ;
}
