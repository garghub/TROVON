static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
T_1 V_7 ;
F_3 ( V_4 , V_8 + V_2 -> V_9 , & V_7 ) ;
if ( ( V_7 & 0x07 ) >= 0x04 || ( V_7 & 0x70 ) >= 0x40 )
return V_10 ;
return V_11 ;
}
static int F_4 ( struct V_12 * V_13 , unsigned long V_14 )
{
static const struct V_15 V_16 [] = {
{ 0x48 , 1 , 0x01 , 0x00 } ,
{ 0x48 , 1 , 0x08 , 0x00 }
} ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( ! F_5 ( V_4 , & V_16 [ V_2 -> V_9 ] ) )
return - V_17 ;
return F_6 ( V_13 , V_14 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_18 * V_19 , int V_20 )
{
static T_1 V_21 [ 5 ] = { 0x5D , 0x47 , 0x34 , 0x22 , 0x20 } ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_22 = 2 * V_2 -> V_9 + V_19 -> V_23 ;
int V_24 = ( 16 * V_2 -> V_9 ) + 8 * ( V_19 -> V_23 ^ 1 ) ;
T_2 V_25 ;
T_3 V_26 ;
F_8 ( V_4 , V_27 , & V_26 ) ;
V_26 &= ~ ( 0x7 << ( 4 * V_22 ) ) ;
V_26 |= V_20 << ( 4 * V_22 ) ;
F_9 ( V_4 , V_27 , V_26 ) ;
F_10 ( V_4 , V_28 , & V_25 ) ;
V_25 &= ~ ( 0xFF << V_24 ) ;
V_25 |= ( V_21 [ V_20 ] << V_24 ) ;
F_11 ( V_4 , V_28 , V_25 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
unsigned long V_29 ;
F_13 ( & V_30 , V_29 ) ;
F_7 ( V_2 , V_19 , V_19 -> V_31 - V_32 ) ;
F_14 ( & V_30 , V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
static T_1 V_33 [ 5 ] = { 0x77 , 0x21 , 0x20 } ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_34 = V_19 -> V_35 ;
int V_22 = 2 * V_2 -> V_9 + V_19 -> V_23 ;
int V_36 ;
unsigned long V_29 ;
F_13 ( & V_30 , V_29 ) ;
if ( V_19 -> V_35 >= V_37 ) {
T_3 V_38 ;
V_34 -= V_37 ;
F_8 ( V_4 , V_8 , & V_38 ) ;
V_38 &= ~ ( 0x7 << ( 4 * V_22 ) ) ;
V_38 |= V_34 << ( 4 * V_22 ) ;
F_9 ( V_4 , V_8 , V_38 ) ;
} else {
int V_24 = ( 16 * V_2 -> V_9 ) + 8 * ( V_19 -> V_23 ^ 1 ) ;
T_2 V_39 ;
V_34 -= V_40 ;
F_10 ( V_4 , V_41 ,
& V_39 ) ;
V_39 &= ~ ( 0xFF << V_24 ) ;
V_39 |= ( V_33 [ V_34 ] << V_24 ) ;
F_11 ( V_4 , V_41 ,
V_39 ) ;
}
if ( V_19 -> V_35 >= V_42 )
V_36 = 4 ;
else if ( V_19 -> V_35 == V_43 )
V_36 = 3 ;
else if ( V_19 -> V_35 == V_40 )
V_36 = 0 ;
else F_16 () ;
if ( V_19 -> V_31 != V_36 )
F_7 ( V_2 , V_19 , V_36 ) ;
F_14 ( & V_30 , V_29 ) ;
}
static void F_17 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_18 * V_19 = V_45 -> V_6 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_22 = ( 2 * V_2 -> V_9 ) + V_19 -> V_23 ;
T_3 V_46 ;
F_8 ( V_4 , V_47 , & V_46 ) ;
if ( F_18 ( V_19 ) )
V_46 |= ( 1 << V_22 ) ;
else
V_46 &= ~ ( 1 << V_22 ) ;
F_9 ( V_4 , V_47 , V_46 ) ;
F_19 ( V_45 ) ;
}
static void F_20 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_22 = ( 2 * V_2 -> V_9 ) + V_45 -> V_6 -> V_23 ;
T_3 V_46 ;
F_8 ( V_4 , V_47 , & V_46 ) ;
V_46 &= ~ ( 1 << V_22 ) ;
F_9 ( V_4 , V_47 , V_46 ) ;
F_21 ( V_45 ) ;
}
static int F_22 ( struct V_3 * V_4 , const struct V_48 * V_49 )
{
static const struct V_50 V_51 = {
. V_29 = V_52 ,
. V_53 = V_54 ,
. V_55 = V_56 ,
. V_57 = V_58 ,
. V_59 = & V_60
} ;
const struct V_50 * V_61 [] = { & V_51 , & V_51 } ;
return F_23 ( V_4 , V_61 , & V_62 , NULL ,
V_63 ) ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_64 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_64 ) ;
}
