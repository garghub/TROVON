static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
static const struct V_4 V_5 [] = {
{ 0x41U , 1U , 0x80UL , 0x80UL } ,
{ 0x43U , 1U , 0x80UL , 0x80UL } ,
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
F_6 ( V_9 , 0x47 , & V_14 ) ;
if ( V_14 & ( 2 >> V_7 -> V_12 ) )
return V_15 ;
return V_16 ;
}
static void F_7 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
unsigned int V_19 = V_18 -> V_20 - V_21 ;
struct V_8 * V_11 = F_2 ( V_7 -> V_10 -> V_11 ) ;
unsigned int V_22 = V_7 -> V_12 ? 0x42 : 0x40 ;
unsigned long V_23 ;
T_2 V_24 ;
T_1 V_25 ;
int V_26 = 0 ;
static const
T_1 V_27 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
if ( V_19 > 1 )
V_26 |= 1 ;
if ( F_8 ( V_18 ) )
V_26 |= 2 ;
if ( V_18 -> V_28 == V_29 )
V_26 |= 4 ;
F_9 ( & V_30 , V_23 ) ;
F_10 ( V_11 , V_22 , & V_24 ) ;
if ( V_18 -> V_31 == 0 ) {
V_24 &= 0xCCF0 ;
V_24 |= V_26 ;
V_24 |= ( V_27 [ V_19 ] [ 0 ] << 12 ) |
( V_27 [ V_19 ] [ 1 ] << 8 ) ;
} else {
int V_32 = 4 * V_7 -> V_12 ;
T_1 V_33 ;
V_24 &= 0xFF0F ;
V_24 |= ( V_26 << 4 ) ;
F_6 ( V_11 , 0x44 , & V_33 ) ;
V_33 &= V_7 -> V_12 ? 0x0F : 0xF0 ;
V_33 |= ( ( V_27 [ V_19 ] [ 0 ] << 2 ) | V_27 [ V_19 ] [ 1 ] ) << V_32 ;
F_11 ( V_11 , 0x44 , V_33 ) ;
}
V_24 |= 0x4000 ;
F_12 ( V_11 , V_22 , V_24 ) ;
F_6 ( V_11 , 0x48 , & V_25 ) ;
V_25 &= ~ ( 1 << ( 2 * V_7 -> V_12 + V_18 -> V_31 ) ) ;
F_11 ( V_11 , 0x48 , V_25 ) ;
F_13 ( & V_30 , V_23 ) ;
}
static void F_14 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
struct V_8 * V_11 = F_2 ( V_7 -> V_10 -> V_11 ) ;
T_1 V_22 = V_7 -> V_12 ? 0x42 : 0x40 ;
T_2 V_24 ;
T_1 V_34 = V_18 -> V_35 ;
int V_36 = V_18 -> V_31 + 2 * V_7 -> V_12 ;
unsigned long V_23 ;
T_1 V_25 ;
static const
T_1 V_27 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
F_9 ( & V_30 , V_23 ) ;
F_10 ( V_11 , V_22 , & V_24 ) ;
F_6 ( V_11 , 0x48 , & V_25 ) ;
if ( V_34 >= V_37 ) {
unsigned int V_38 = V_18 -> V_35 - V_37 ;
T_2 V_39 ;
V_25 |= ( 1 << V_36 ) ;
F_10 ( V_11 , 0x4A , & V_39 ) ;
V_39 &= ~ ( 7 << ( 4 * V_36 ) ) ;
V_39 |= V_38 << ( 4 * V_36 ) ;
F_12 ( V_11 , 0x4A , V_39 ) ;
} else {
unsigned int V_40 = V_18 -> V_35 - V_41 ;
unsigned int V_26 ;
T_1 V_33 ;
const unsigned int V_42 [ 3 ] = {
V_21 , V_43 , V_44
} ;
int V_19 = V_42 [ V_40 ] - V_21 ;
V_26 = 3 ;
if ( V_18 -> V_20 < V_42 [ V_40 ] )
V_26 |= 8 ;
if ( V_18 -> V_31 ) {
V_24 &= 0xFF4F ;
V_24 |= V_26 << 4 ;
F_6 ( V_11 , 0x44 , & V_33 ) ;
V_33 &= V_7 -> V_12 ? 0x0F : 0xF0 ;
V_33 |= ( ( V_27 [ V_19 ] [ 0 ] << 2 ) | V_27 [ V_19 ] [ 1 ] ) << ( V_7 -> V_12 ? 4 : 0 ) ;
F_11 ( V_11 , 0x44 , V_33 ) ;
} else {
V_24 &= 0xCCF4 ;
V_24 |= V_26 ;
V_24 |=
( V_27 [ V_19 ] [ 0 ] << 12 ) |
( V_27 [ V_19 ] [ 1 ] << 8 ) ;
}
V_25 &= ~ ( 1 << V_36 ) ;
F_12 ( V_11 , V_22 , V_24 ) ;
}
F_11 ( V_11 , 0x48 , V_25 ) ;
F_13 ( & V_30 , V_23 ) ;
}
static int F_15 ( struct V_8 * V_9 , const struct V_45 * V_46 )
{
static const struct V_47 V_48 = {
. V_23 = V_49 ,
. V_50 = V_51 ,
. V_52 = V_53 ,
. V_54 = V_55 ,
. V_56 = & V_57 ,
} ;
const struct V_47 * V_58 [] = { & V_48 , & V_48 } ;
F_16 ( & V_9 -> V_11 , V_59 ) ;
return F_17 ( V_9 , V_58 , & V_60 , NULL ,
V_61 ) ;
}
