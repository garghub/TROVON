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
static int V_36 ;
static const struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_42 ,
#if F_19 ( V_43 )
. V_44 = V_45 ,
. V_46 = V_47 ,
#endif
. V_48 = & V_49
} ;
static const T_3 V_50 [ 2 ] = { 0x20 , 0x28 } ;
static const T_3 V_51 [ 2 ] = { 0x36 , 0x3E } ;
const struct V_37 * V_52 [] = { & V_38 , NULL } ;
struct V_53 * V_7 ;
int V_54 , V_55 ;
void T_2 * V_56 ;
F_14 ( V_6 ) ;
if ( ! V_36 ++ )
F_20 ( V_57 , & V_6 -> V_8 , L_1 V_58 L_2 ) ;
V_7 = F_21 ( & V_6 -> V_8 , V_52 , 2 ) ;
if ( ! V_7 )
return - V_59 ;
V_55 = F_22 ( V_6 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_23 ( V_6 , 1 << 4 , V_60 ) ;
if ( V_55 == - V_61 )
F_24 ( V_6 ) ;
if ( V_55 )
return V_55 ;
V_7 -> V_62 = F_25 ( V_6 ) ;
V_55 = F_26 ( V_6 , V_63 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_27 ( V_6 , V_63 ) ;
if ( V_55 )
return V_55 ;
V_56 = V_7 -> V_62 [ 4 ] ;
for ( V_54 = 0 ; V_54 < V_7 -> V_64 ; V_54 ++ ) {
struct V_1 * V_2 = V_7 -> V_65 [ V_54 ] ;
struct V_66 * V_20 = & V_2 -> V_20 ;
V_20 -> V_67 = V_56 + V_50 [ V_54 ] ;
V_20 -> V_68 =
V_20 -> V_69 = V_56 + V_51 [ V_54 ] ;
V_20 -> V_70 = NULL ;
F_28 ( V_20 ) ;
V_20 -> V_21 = V_56 + 8 * V_54 ;
F_29 ( V_2 , 4 , - 1 , L_3 ) ;
F_29 ( V_2 , 4 , V_50 [ V_54 ] , L_4 ) ;
}
F_30 ( V_6 ) ;
return F_31 ( V_7 , V_6 -> V_71 , V_72 ,
V_73 , & V_74 ) ;
}
static int F_32 ( struct V_5 * V_8 )
{
struct V_53 * V_7 = F_33 ( & V_8 -> V_8 ) ;
int V_55 ;
V_55 = F_34 ( V_8 ) ;
if ( V_55 )
return V_55 ;
F_14 ( V_8 ) ;
F_35 ( V_7 ) ;
return 0 ;
}
static int T_5 F_36 ( void )
{
return F_37 ( & V_75 ) ;
}
static void T_6 F_38 ( void )
{
F_39 ( & V_75 ) ;
}
