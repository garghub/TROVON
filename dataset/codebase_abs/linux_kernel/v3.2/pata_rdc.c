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
unsigned long V_26 ;
unsigned int V_27 = ( V_22 -> V_28 != 0 ) ;
unsigned int V_29 = V_2 -> V_8 ? 0x42 : 0x40 ;
unsigned int V_30 = 0x44 ;
T_2 V_31 ;
T_1 V_32 ;
T_1 V_33 ;
int V_34 = 0 ;
static const
T_1 V_35 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
if ( V_23 >= 2 )
V_34 |= 1 ;
if ( F_7 ( V_22 ) )
V_34 |= 2 ;
if ( V_22 -> V_36 == V_37 )
V_34 |= 4 ;
F_8 ( & V_38 , V_26 ) ;
F_9 ( V_17 , V_29 , & V_31 ) ;
if ( V_27 ) {
V_31 &= 0xff0f ;
V_31 |= 0x4000 ;
V_31 |= ( V_34 << 4 ) ;
F_10 ( V_17 , V_30 , & V_32 ) ;
V_32 &= ( V_2 -> V_8 ? 0x0f : 0xf0 ) ;
V_32 |= ( ( V_35 [ V_23 ] [ 0 ] << 2 ) | V_35 [ V_23 ] [ 1 ] )
<< ( V_2 -> V_8 ? 4 : 0 ) ;
} else {
V_31 &= 0xccf0 ;
V_31 |= V_34 ;
V_31 |=
( V_35 [ V_23 ] [ 0 ] << 12 ) |
( V_35 [ V_23 ] [ 1 ] << 8 ) ;
}
F_11 ( V_17 , V_29 , V_31 ) ;
if ( V_27 )
F_12 ( V_17 , V_30 , V_32 ) ;
F_10 ( V_17 , 0x48 , & V_33 ) ;
V_33 &= ~ ( 1 << ( 2 * V_2 -> V_8 + V_22 -> V_28 ) ) ;
F_12 ( V_17 , 0x48 , V_33 ) ;
F_13 ( & V_38 , V_26 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_15 * V_17 = F_3 ( V_2 -> V_5 -> V_17 ) ;
unsigned long V_26 ;
T_1 V_29 = V_2 -> V_8 ? 0x42 : 0x40 ;
T_2 V_31 ;
T_1 V_39 = V_22 -> V_40 ;
int V_41 = V_22 -> V_28 + 2 * V_2 -> V_8 ;
T_1 V_33 = 0 ;
static const
T_1 V_35 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
F_8 ( & V_38 , V_26 ) ;
F_9 ( V_17 , V_29 , & V_31 ) ;
F_10 ( V_17 , 0x48 , & V_33 ) ;
if ( V_39 >= V_42 ) {
unsigned int V_43 = V_22 -> V_40 - V_42 ;
T_2 V_44 ;
T_2 V_45 ;
int V_46 , V_47 ;
V_47 = F_15 ( 2 - ( V_43 & 1 ) , V_43 ) ;
if ( V_43 == 5 )
V_46 = 0x1000 ;
else if ( V_43 > 2 )
V_46 = 1 ;
else
V_46 = 0 ;
V_33 |= ( 1 << V_41 ) ;
F_9 ( V_17 , 0x4A , & V_44 ) ;
V_44 &= ~ ( 3 << ( 4 * V_41 ) ) ;
V_44 |= V_47 << ( 4 * V_41 ) ;
F_11 ( V_17 , 0x4A , V_44 ) ;
F_9 ( V_17 , 0x54 , & V_45 ) ;
V_45 &= ~ ( 0x1001 << V_41 ) ;
V_45 |= V_46 << V_41 ;
F_11 ( V_17 , 0x54 , V_45 ) ;
} else {
unsigned int V_48 = V_22 -> V_40 - V_49 ;
unsigned int V_34 ;
T_1 V_32 ;
const unsigned int V_50 [ 3 ] = {
V_25 , V_51 , V_52
} ;
int V_23 = V_50 [ V_48 ] - V_25 ;
V_34 = 3 ;
if ( V_22 -> V_24 < V_50 [ V_48 ] )
V_34 |= 8 ;
if ( V_22 -> V_28 ) {
V_31 &= 0xFF4F ;
V_31 |= V_34 << 4 ;
F_10 ( V_17 , 0x44 , & V_32 ) ;
V_32 &= ( V_2 -> V_8 ? 0x0f : 0xf0 ) ;
V_32 |= ( ( V_35 [ V_23 ] [ 0 ] << 2 ) | V_35 [ V_23 ] [ 1 ] ) << ( V_2 -> V_8 ? 4 : 0 ) ;
F_12 ( V_17 , 0x44 , V_32 ) ;
} else {
V_31 &= 0xCCF4 ;
V_31 |= V_34 ;
V_31 |=
( V_35 [ V_23 ] [ 0 ] << 12 ) |
( V_35 [ V_23 ] [ 1 ] << 8 ) ;
}
V_33 &= ~ ( 1 << V_41 ) ;
F_11 ( V_17 , V_29 , V_31 ) ;
}
F_12 ( V_17 , 0x48 , V_33 ) ;
F_13 ( & V_38 , V_26 ) ;
}
static int T_3 F_16 ( struct V_15 * V_16 ,
const struct V_53 * V_54 )
{
struct V_55 * V_17 = & V_16 -> V_17 ;
struct V_56 V_57 [ 2 ] ;
const struct V_56 * V_58 [] = { & V_57 [ 0 ] , & V_57 [ 1 ] } ;
unsigned long V_59 ;
struct V_60 * V_5 ;
struct V_3 * V_4 ;
int V_61 ;
F_17 ( & V_16 -> V_17 , V_62 ) ;
V_57 [ 0 ] = V_63 ;
V_57 [ 1 ] = V_63 ;
V_59 = V_57 [ 0 ] . V_26 ;
V_61 = F_18 ( V_16 ) ;
if ( V_61 )
return V_61 ;
V_4 = F_19 ( V_17 , sizeof( * V_4 ) , V_64 ) ;
if ( ! V_4 )
return - V_65 ;
F_20 ( V_16 , 0x54 , & V_4 -> V_9 ) ;
V_61 = F_21 ( V_16 , V_58 , & V_5 ) ;
if ( V_61 )
return V_61 ;
V_5 -> V_6 = V_4 ;
F_22 ( V_16 , 1 ) ;
V_5 -> V_26 |= V_66 ;
F_23 ( V_16 ) ;
return F_24 ( V_5 , V_67 , & V_68 ) ;
}
static void F_25 ( struct V_15 * V_16 )
{
struct V_60 * V_5 = F_26 ( & V_16 -> V_17 ) ;
struct V_3 * V_4 = V_5 -> V_6 ;
F_27 ( V_16 , 0x54 , V_4 -> V_9 ) ;
F_28 ( V_16 ) ;
}
static int T_4 F_29 ( void )
{
return F_30 ( & V_69 ) ;
}
static void T_5 F_31 ( void )
{
F_32 ( & V_69 ) ;
}
