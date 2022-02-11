static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
T_1 V_7 ;
F_3 ( V_4 , V_8 + V_2 -> V_9 , & V_7 ) ;
if ( ( V_7 & 0x07 ) >= 0x04 || ( V_7 & 0x70 ) >= 0x40 )
return V_10 ;
return V_11 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_12 * V_13 , int V_14 )
{
static T_1 V_15 [ 5 ] = { 0x5D , 0x47 , 0x34 , 0x22 , 0x20 } ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_16 = 2 * V_2 -> V_9 + V_13 -> V_17 ;
int V_18 = ( 16 * V_2 -> V_9 ) + 8 * ( V_13 -> V_17 ^ 1 ) ;
T_2 V_19 ;
T_3 V_20 ;
F_5 ( V_4 , V_21 , & V_20 ) ;
V_20 &= ~ ( 0x7 << ( 4 * V_16 ) ) ;
V_20 |= V_14 << ( 4 * V_16 ) ;
F_6 ( V_4 , V_21 , V_20 ) ;
F_7 ( V_4 , V_22 , & V_19 ) ;
V_19 &= ~ ( 0xFF << V_18 ) ;
V_19 |= ( V_15 [ V_14 ] << V_18 ) ;
F_8 ( V_4 , V_22 , V_19 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
unsigned long V_23 ;
F_10 ( & V_24 , V_23 ) ;
F_4 ( V_2 , V_13 , V_13 -> V_25 - V_26 ) ;
F_11 ( & V_24 , V_23 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
static T_1 V_27 [ 5 ] = { 0x77 , 0x21 , 0x20 } ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_28 = V_13 -> V_29 ;
int V_16 = 2 * V_2 -> V_9 + V_13 -> V_17 ;
int V_30 ;
unsigned long V_23 ;
F_10 ( & V_24 , V_23 ) ;
if ( V_13 -> V_29 >= V_31 ) {
T_3 V_32 ;
V_28 -= V_31 ;
F_5 ( V_4 , V_8 , & V_32 ) ;
V_32 &= ~ ( 0x7 << ( 4 * V_16 ) ) ;
V_32 |= V_28 << ( 4 * V_16 ) ;
F_6 ( V_4 , V_8 , V_32 ) ;
} else {
int V_18 = ( 16 * V_2 -> V_9 ) + 8 * ( V_13 -> V_17 ^ 1 ) ;
T_2 V_33 ;
V_28 -= V_34 ;
F_7 ( V_4 , V_35 ,
& V_33 ) ;
V_33 &= ~ ( 0xFF << V_18 ) ;
V_33 |= ( V_27 [ V_28 ] << V_18 ) ;
F_8 ( V_4 , V_35 ,
V_33 ) ;
}
if ( V_13 -> V_29 >= V_36 )
V_30 = 4 ;
else if ( V_13 -> V_29 == V_37 )
V_30 = 3 ;
else if ( V_13 -> V_29 == V_34 )
V_30 = 0 ;
else F_13 () ;
if ( V_13 -> V_25 != V_30 )
F_4 ( V_2 , V_13 , V_30 ) ;
F_11 ( & V_24 , V_23 ) ;
}
static void F_14 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_12 * V_13 = V_39 -> V_6 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_16 = ( 2 * V_2 -> V_9 ) + V_13 -> V_17 ;
T_3 V_40 ;
F_5 ( V_4 , V_41 , & V_40 ) ;
if ( F_15 ( V_13 ) )
V_40 |= ( 1 << V_16 ) ;
else
V_40 &= ~ ( 1 << V_16 ) ;
F_6 ( V_4 , V_41 , V_40 ) ;
F_16 ( V_39 ) ;
}
static void F_17 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_16 = ( 2 * V_2 -> V_9 ) + V_39 -> V_6 -> V_17 ;
T_3 V_40 ;
F_5 ( V_4 , V_41 , & V_40 ) ;
V_40 &= ~ ( 1 << V_16 ) ;
F_6 ( V_4 , V_41 , V_40 ) ;
F_18 ( V_39 ) ;
}
static int F_19 ( struct V_3 * V_4 , const struct V_42 * V_43 )
{
static const struct V_44 V_45 = {
. V_23 = V_46 ,
. V_47 = V_48 ,
. V_49 = V_50 ,
. V_51 = V_52 ,
. V_53 = & V_54
} ;
static const struct V_55 V_56 [] = {
{ 0x48 , 1 , 0x01 , 0x00 } ,
{ 0x48 , 1 , 0x08 , 0x00 }
} ;
const struct V_44 * V_57 [] = { & V_45 , & V_45 } ;
int V_58 ;
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ )
if ( ! F_20 ( V_4 , & V_56 [ V_58 ] ) )
V_57 [ V_58 ] = & V_59 ;
return F_21 ( V_4 , V_57 , & V_60 , NULL ,
V_61 ) ;
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_62 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_62 ) ;
}
