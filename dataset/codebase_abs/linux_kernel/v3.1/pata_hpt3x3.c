static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 -> V_8 ) ;
T_1 V_9 , V_10 ;
int V_11 = 2 * V_2 -> V_12 + V_4 -> V_13 ;
F_3 ( V_6 , 0x44 , & V_9 ) ;
F_3 ( V_6 , 0x48 , & V_10 ) ;
V_9 &= ~ ( 7 << ( 3 * V_11 ) ) ;
V_9 |= ( V_4 -> V_14 - V_15 ) << ( 3 * V_11 ) ;
V_10 &= ~ ( 0x11 << V_11 ) ;
F_4 ( V_6 , 0x44 , V_9 ) ;
F_4 ( V_6 , 0x48 , V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 -> V_8 ) ;
T_1 V_9 , V_10 ;
int V_11 = 2 * V_2 -> V_12 + V_4 -> V_13 ;
int V_16 = V_4 -> V_17 & 0x0F ;
F_3 ( V_6 , 0x44 , & V_9 ) ;
F_3 ( V_6 , 0x48 , & V_10 ) ;
V_9 &= ~ ( 7 << ( 3 * V_11 ) ) ;
V_9 |= ( V_16 << ( 3 * V_11 ) ) ;
V_10 &= ~ ( 0x11 << V_11 ) ;
if ( V_4 -> V_17 >= V_18 )
V_10 |= ( 0x01 << V_11 ) ;
else
V_10 |= ( 0x10 << V_11 ) ;
F_4 ( V_6 , 0x44 , V_9 ) ;
F_4 ( V_6 , 0x48 , V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
void T_2 * V_19 = V_2 -> V_20 . V_21 ;
F_7 ( F_8 ( V_19 + V_22 ) & ~ V_23 ,
V_19 + V_22 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static void F_11 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
T_3 V_26 = F_8 ( V_2 -> V_20 . V_21 + V_27 ) ;
V_26 |= V_28 | V_29 ;
F_7 ( V_26 , V_2 -> V_20 . V_21 + V_27 ) ;
return F_12 ( V_25 ) ;
}
static int F_13 ( struct V_24 * V_25 )
{
return 1 ;
}
static void F_14 ( struct V_5 * V_8 )
{
T_4 V_30 ;
F_15 ( V_8 , 0x80 , 0x00 ) ;
F_16 ( V_8 , V_31 , & V_30 ) ;
if ( V_30 & V_32 )
F_17 ( V_8 , V_33 , 0xF0 ) ;
else
F_17 ( V_8 , V_33 , 0x20 ) ;
}
static int F_18 ( struct V_5 * V_6 , const struct V_34 * V_35 )
{
static const struct V_36 V_37 = {
. V_38 = V_39 ,
. V_40 = V_41 ,
#if F_19 ( V_42 )
. V_43 = V_44 ,
. V_45 = V_46 ,
#endif
. V_47 = & V_48
} ;
static const T_3 V_49 [ 2 ] = { 0x20 , 0x28 } ;
static const T_3 V_50 [ 2 ] = { 0x36 , 0x3E } ;
const struct V_36 * V_51 [] = { & V_37 , NULL } ;
struct V_52 * V_7 ;
int V_53 , V_54 ;
void T_2 * V_55 ;
F_14 ( V_6 ) ;
F_20 ( & V_6 -> V_8 , V_56 ) ;
V_7 = F_21 ( & V_6 -> V_8 , V_51 , 2 ) ;
if ( ! V_7 )
return - V_57 ;
V_54 = F_22 ( V_6 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_23 ( V_6 , 1 << 4 , V_58 ) ;
if ( V_54 == - V_59 )
F_24 ( V_6 ) ;
if ( V_54 )
return V_54 ;
V_7 -> V_60 = F_25 ( V_6 ) ;
V_54 = F_26 ( V_6 , V_61 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_27 ( V_6 , V_61 ) ;
if ( V_54 )
return V_54 ;
V_55 = V_7 -> V_60 [ 4 ] ;
for ( V_53 = 0 ; V_53 < V_7 -> V_62 ; V_53 ++ ) {
struct V_1 * V_2 = V_7 -> V_63 [ V_53 ] ;
struct V_64 * V_20 = & V_2 -> V_20 ;
V_20 -> V_65 = V_55 + V_49 [ V_53 ] ;
V_20 -> V_66 =
V_20 -> V_67 = V_55 + V_50 [ V_53 ] ;
V_20 -> V_68 = NULL ;
F_28 ( V_20 ) ;
V_20 -> V_21 = V_55 + 8 * V_53 ;
F_29 ( V_2 , 4 , - 1 , L_1 ) ;
F_29 ( V_2 , 4 , V_49 [ V_53 ] , L_2 ) ;
}
F_30 ( V_6 ) ;
return F_31 ( V_7 , V_6 -> V_69 , V_70 ,
V_71 , & V_72 ) ;
}
static int F_32 ( struct V_5 * V_8 )
{
struct V_52 * V_7 = F_33 ( & V_8 -> V_8 ) ;
int V_54 ;
V_54 = F_34 ( V_8 ) ;
if ( V_54 )
return V_54 ;
F_14 ( V_8 ) ;
F_35 ( V_7 ) ;
return 0 ;
}
static int T_5 F_36 ( void )
{
return F_37 ( & V_73 ) ;
}
static void T_6 F_38 ( void )
{
F_39 ( & V_73 ) ;
}
