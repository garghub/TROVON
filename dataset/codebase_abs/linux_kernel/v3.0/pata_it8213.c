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
T_2 V_30 ;
T_1 V_31 = V_18 -> V_32 ;
int V_33 = V_18 -> V_28 ;
T_1 V_34 ;
static const
T_1 V_25 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
F_9 ( V_11 , 0x40 , & V_30 ) ;
F_6 ( V_11 , 0x48 , & V_34 ) ;
if ( V_31 >= V_35 ) {
unsigned int V_36 = V_18 -> V_32 - V_35 ;
T_2 V_37 ;
T_2 V_38 ;
int V_39 , V_40 ;
V_40 = F_13 ( 2 - ( V_36 & 1 ) , V_36 ) ;
if ( V_36 == 5 )
V_39 = 0x1000 ;
else if ( V_36 > 2 )
V_39 = 1 ;
else
V_39 = 0 ;
V_34 |= ( 1 << V_33 ) ;
F_9 ( V_11 , 0x4A , & V_37 ) ;
V_37 &= ~ ( 3 << ( 4 * V_33 ) ) ;
V_37 |= V_40 << ( 4 * V_33 ) ;
F_11 ( V_11 , 0x4A , V_37 ) ;
F_9 ( V_11 , 0x54 , & V_38 ) ;
V_38 &= ~ ( 0x1001 << V_33 ) ;
V_38 |= V_39 << V_33 ;
F_11 ( V_11 , 0x54 , V_38 ) ;
} else {
unsigned int V_41 = V_18 -> V_32 - V_42 ;
unsigned int V_24 ;
T_1 V_29 ;
static const unsigned int V_43 [ 3 ] = {
V_21 , V_44 , V_45
} ;
int V_19 = V_43 [ V_41 ] - V_21 ;
V_24 = 3 ;
if ( V_18 -> V_20 < V_43 [ V_41 ] )
V_24 |= 8 ;
if ( V_33 ) {
V_30 &= 0xFF4F ;
V_30 |= V_24 << 4 ;
F_6 ( V_11 , 0x44 , & V_29 ) ;
V_29 &= 0xF0 ;
V_29 |= ( ( V_25 [ V_19 ] [ 0 ] << 2 ) | V_25 [ V_19 ] [ 1 ] ) << ( V_7 -> V_12 ? 4 : 0 ) ;
F_10 ( V_11 , 0x44 , V_29 ) ;
} else {
V_30 &= 0xCCF4 ;
V_30 |= V_24 ;
V_30 |=
( V_25 [ V_19 ] [ 0 ] << 12 ) |
( V_25 [ V_19 ] [ 1 ] << 8 ) ;
}
V_34 &= ~ ( 1 << V_33 ) ;
F_11 ( V_11 , 0x40 , V_30 ) ;
}
F_10 ( V_11 , 0x48 , V_34 ) ;
}
static int F_14 ( struct V_8 * V_9 , const struct V_46 * V_47 )
{
static int V_48 ;
static const struct V_49 V_50 = {
. V_51 = V_52 ,
. V_53 = V_54 ,
. V_55 = V_56 ,
. V_57 = V_58 ,
. V_59 = & V_60 ,
} ;
const struct V_49 * V_61 [] = { & V_50 , & V_62 } ;
if ( ! V_48 ++ )
F_15 ( V_63 , & V_9 -> V_11 ,
L_1 V_64 L_2 ) ;
return F_16 ( V_9 , V_61 , & V_65 , NULL , 0 ) ;
}
static int T_3 F_17 ( void )
{
return F_18 ( & V_66 ) ;
}
static void T_4 F_19 ( void )
{
F_20 ( & V_66 ) ;
}
