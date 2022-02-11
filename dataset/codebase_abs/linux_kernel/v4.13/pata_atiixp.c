static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
T_1 V_7 ;
if ( F_3 ( V_8 ) )
return V_9 ;
F_4 ( V_4 , V_10 + V_2 -> V_11 , & V_7 ) ;
if ( ( V_7 & 0x07 ) >= 0x04 || ( V_7 & 0x70 ) >= 0x40 )
return V_12 ;
return V_13 ;
}
static int F_5 ( struct V_14 * V_15 , unsigned long V_16 )
{
static const struct V_17 V_18 [] = {
{ 0x48 , 1 , 0x01 , 0x00 } ,
{ 0x48 , 1 , 0x08 , 0x00 }
} ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( ! F_6 ( V_4 , & V_18 [ V_2 -> V_11 ] ) )
return - V_19 ;
return F_7 ( V_15 , V_16 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_20 * V_21 , int V_22 )
{
static T_1 V_23 [ 5 ] = { 0x5D , 0x47 , 0x34 , 0x22 , 0x20 } ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_24 = 2 * V_2 -> V_11 + V_21 -> V_25 ;
int V_26 = ( 16 * V_2 -> V_11 ) + 8 * ( V_21 -> V_25 ^ 1 ) ;
T_2 V_27 ;
T_3 V_28 ;
F_9 ( V_4 , V_29 , & V_28 ) ;
V_28 &= ~ ( 0x7 << ( 4 * V_24 ) ) ;
V_28 |= V_22 << ( 4 * V_24 ) ;
F_10 ( V_4 , V_29 , V_28 ) ;
F_11 ( V_4 , V_30 , & V_27 ) ;
V_27 &= ~ ( 0xFF << V_26 ) ;
V_27 |= ( V_23 [ V_22 ] << V_26 ) ;
F_12 ( V_4 , V_30 , V_27 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
unsigned long V_31 ;
F_14 ( & V_32 , V_31 ) ;
F_8 ( V_2 , V_21 , V_21 -> V_33 - V_34 ) ;
F_15 ( & V_32 , V_31 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
static T_1 V_35 [ 5 ] = { 0x77 , 0x21 , 0x20 } ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_36 = V_21 -> V_37 ;
int V_24 = 2 * V_2 -> V_11 + V_21 -> V_25 ;
int V_38 ;
unsigned long V_31 ;
F_14 ( & V_32 , V_31 ) ;
if ( V_21 -> V_37 >= V_39 ) {
T_3 V_40 ;
V_36 -= V_39 ;
F_9 ( V_4 , V_10 , & V_40 ) ;
V_40 &= ~ ( 0x7 << ( 4 * V_24 ) ) ;
V_40 |= V_36 << ( 4 * V_24 ) ;
F_10 ( V_4 , V_10 , V_40 ) ;
} else {
int V_26 = ( 16 * V_2 -> V_11 ) + 8 * ( V_21 -> V_25 ^ 1 ) ;
T_2 V_41 ;
V_36 -= V_42 ;
F_11 ( V_4 , V_43 ,
& V_41 ) ;
V_41 &= ~ ( 0xFF << V_26 ) ;
V_41 |= ( V_35 [ V_36 ] << V_26 ) ;
F_12 ( V_4 , V_43 ,
V_41 ) ;
}
if ( V_21 -> V_37 >= V_44 )
V_38 = 4 ;
else if ( V_21 -> V_37 == V_45 )
V_38 = 3 ;
else if ( V_21 -> V_37 == V_42 )
V_38 = 0 ;
else F_17 () ;
if ( V_21 -> V_33 != V_38 )
F_8 ( V_2 , V_21 , V_38 ) ;
F_15 ( & V_32 , V_31 ) ;
}
static void F_18 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_2 ;
struct V_20 * V_21 = V_47 -> V_6 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_24 = ( 2 * V_2 -> V_11 ) + V_21 -> V_25 ;
T_3 V_48 ;
F_9 ( V_4 , V_49 , & V_48 ) ;
if ( F_19 ( V_21 ) )
V_48 |= ( 1 << V_24 ) ;
else
V_48 &= ~ ( 1 << V_24 ) ;
F_10 ( V_4 , V_49 , V_48 ) ;
F_20 ( V_47 ) ;
}
static void F_21 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_24 = ( 2 * V_2 -> V_11 ) + V_47 -> V_6 -> V_25 ;
T_3 V_48 ;
F_9 ( V_4 , V_49 , & V_48 ) ;
V_48 &= ~ ( 1 << V_24 ) ;
F_10 ( V_4 , V_49 , V_48 ) ;
F_22 ( V_47 ) ;
}
static int F_23 ( struct V_3 * V_4 , const struct V_50 * V_51 )
{
static const struct V_52 V_53 = {
. V_31 = V_54 ,
. V_55 = V_56 ,
. V_57 = V_58 ,
. V_59 = V_60 ,
. V_61 = & V_62
} ;
const struct V_52 * V_63 [] = { & V_53 , & V_53 } ;
return F_24 ( V_4 , V_63 , & V_64 , NULL ,
V_65 ) ;
}
