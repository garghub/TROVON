static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
static const struct V_4 V_5 [] = {
{ 0x41U , 1U , 0x80UL , 0x80UL } ,
} ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 -> V_10 -> V_11 ) ;
if ( ! F_3 ( V_9 , & V_5 [ V_7 -> V_12 ] ) )
return - V_13 ;
return F_4 ( V_2 , V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 -> V_10 -> V_11 ) ;
T_1 V_14 ;
F_6 ( V_9 , 0x42 , & V_14 ) ;
if ( V_14 & 2 )
return V_15 ;
return V_16 ;
}
static void F_7 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
unsigned int V_19 = V_18 -> V_20 - V_21 ;
struct V_8 * V_11 = F_2 ( V_7 -> V_10 -> V_11 ) ;
unsigned int V_22 = V_7 -> V_12 ? 0x42 : 0x40 ;
T_2 V_23 ;
int V_24 = 0 ;
static const
T_1 V_25 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
if ( V_19 > 1 )
V_24 |= 1 ;
if ( F_8 ( V_18 ) )
V_24 |= 2 ;
if ( V_18 -> V_26 != V_27 )
V_24 |= 4 ;
F_9 ( V_11 , V_22 , & V_23 ) ;
if ( V_18 -> V_28 == 0 ) {
V_23 &= 0xCCF0 ;
V_23 |= V_24 ;
V_23 |= ( V_25 [ V_19 ] [ 0 ] << 12 ) |
( V_25 [ V_19 ] [ 1 ] << 8 ) ;
} else {
T_1 V_29 ;
V_23 &= 0xFF0F ;
V_23 |= ( V_24 << 4 ) ;
F_6 ( V_11 , 0x44 , & V_29 ) ;
V_29 &= 0xF0 ;
V_29 |= ( V_25 [ V_19 ] [ 0 ] << 2 ) | V_25 [ V_19 ] [ 1 ] ;
F_10 ( V_11 , 0x44 , V_29 ) ;
}
V_23 |= 0x4000 ;
F_11 ( V_11 , V_22 , V_23 ) ;
}
static void F_12 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
struct V_8 * V_11 = F_2 ( V_7 -> V_10 -> V_11 ) ;
T_2 V_23 ;
T_1 V_30 = V_18 -> V_31 ;
int V_32 = V_18 -> V_28 ;
T_1 V_33 ;
static const
T_1 V_25 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
F_9 ( V_11 , 0x40 , & V_23 ) ;
F_6 ( V_11 , 0x48 , & V_33 ) ;
if ( V_30 >= V_34 ) {
unsigned int V_35 = V_18 -> V_31 - V_34 ;
T_2 V_36 ;
T_2 V_37 ;
int V_38 , V_39 ;
V_39 = F_13 ( 2 - ( V_35 & 1 ) , V_35 ) ;
if ( V_35 > 4 )
V_38 = 0x1000 ;
else if ( V_35 > 2 )
V_38 = 1 ;
else
V_38 = 0 ;
V_33 |= ( 1 << V_32 ) ;
F_9 ( V_11 , 0x4A , & V_36 ) ;
V_36 &= ~ ( 3 << ( 4 * V_32 ) ) ;
V_36 |= V_39 << ( 4 * V_32 ) ;
F_11 ( V_11 , 0x4A , V_36 ) ;
F_9 ( V_11 , 0x54 , & V_37 ) ;
V_37 &= ~ ( 0x1001 << V_32 ) ;
V_37 |= V_38 << V_32 ;
F_11 ( V_11 , 0x54 , V_37 ) ;
} else {
unsigned int V_40 = V_18 -> V_31 - V_41 ;
unsigned int V_24 ;
T_1 V_29 ;
static const unsigned int V_42 [ 3 ] = {
V_21 , V_43 , V_44
} ;
int V_19 = V_42 [ V_40 ] - V_21 ;
V_24 = 3 ;
if ( V_18 -> V_20 < V_42 [ V_40 ] )
V_24 |= 8 ;
if ( V_32 ) {
V_23 &= 0xFF4F ;
V_23 |= V_24 << 4 ;
F_6 ( V_11 , 0x44 , & V_29 ) ;
V_29 &= 0xF0 ;
V_29 |= ( ( V_25 [ V_19 ] [ 0 ] << 2 ) | V_25 [ V_19 ] [ 1 ] ) << ( V_7 -> V_12 ? 4 : 0 ) ;
F_10 ( V_11 , 0x44 , V_29 ) ;
} else {
V_23 &= 0xCCF4 ;
V_23 |= V_24 ;
V_23 |=
( V_25 [ V_19 ] [ 0 ] << 12 ) |
( V_25 [ V_19 ] [ 1 ] << 8 ) ;
}
V_33 &= ~ ( 1 << V_32 ) ;
F_11 ( V_11 , 0x40 , V_23 ) ;
}
F_10 ( V_11 , 0x48 , V_33 ) ;
}
static int F_14 ( struct V_8 * V_9 , const struct V_45 * V_46 )
{
static const struct V_47 V_48 = {
. V_49 = V_50 ,
. V_51 = V_52 ,
. V_53 = V_54 ,
. V_55 = V_56 ,
. V_57 = & V_58 ,
} ;
const struct V_47 * V_59 [] = { & V_48 , & V_60 } ;
F_15 ( & V_9 -> V_11 , V_61 ) ;
return F_16 ( V_9 , V_59 , & V_62 , NULL , 0 ) ;
}
static int T_3 F_17 ( void )
{
return F_18 ( & V_63 ) ;
}
static void T_4 F_19 ( void )
{
F_20 ( & V_63 ) ;
}
