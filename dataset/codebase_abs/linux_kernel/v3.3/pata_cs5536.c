static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
if ( F_2 ( V_5 ) ) {
T_1 T_2 V_6 ;
F_3 ( V_7 + V_3 , * V_4 , T_2 ) ;
return 0 ;
}
return F_4 ( V_2 , V_8 + V_3 * 4 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
if ( F_2 ( V_5 ) ) {
F_6 ( V_7 + V_3 , V_4 , 0 ) ;
return 0 ;
}
return F_7 ( V_2 , V_8 + V_3 * 4 , V_4 ) ;
}
static void F_8 ( struct V_9 * V_10 , T_3 V_11 )
{
struct V_1 * V_2 = F_9 ( V_10 -> V_12 -> V_13 -> V_14 -> V_15 ) ;
int V_16 = V_10 -> V_17 ? V_18 : V_19 ;
T_1 V_20 ;
F_1 ( V_2 , V_21 , & V_20 ) ;
V_20 &= ~ ( V_22 << V_16 ) ;
V_20 |= V_11 << V_16 ;
F_5 ( V_2 , V_21 , V_20 ) ;
}
static int F_10 ( struct V_23 * V_13 )
{
struct V_1 * V_2 = F_9 ( V_13 -> V_14 -> V_15 ) ;
T_1 V_24 ;
F_1 ( V_2 , V_25 , & V_24 ) ;
if ( V_24 & V_26 )
return V_27 ;
else
return V_28 ;
}
static void F_11 ( struct V_23 * V_13 , struct V_9 * V_10 )
{
static const T_3 V_29 [ 5 ] = {
0x98 , 0x55 , 0x32 , 0x21 , 0x20 ,
} ;
static const T_3 V_30 [ 5 ] = {
0x2 , 0x1 , 0x0 , 0x0 , 0x0 ,
} ;
static const T_3 V_31 [ 5 ] = {
0x99 , 0x92 , 0x90 , 0x22 , 0x20 ,
} ;
struct V_1 * V_2 = F_9 ( V_13 -> V_14 -> V_15 ) ;
struct V_9 * V_32 = F_12 ( V_10 ) ;
int V_33 = V_10 -> V_34 - V_35 ;
int V_36 = V_33 ;
int V_37 = V_10 -> V_17 ? V_38 : V_39 ;
T_1 V_40 ;
if ( V_32 )
V_36 = F_13 ( V_33 , V_32 -> V_34 - V_35 ) ;
F_8 ( V_10 , V_29 [ V_33 ] ) ;
F_1 ( V_2 , V_41 , & V_40 ) ;
V_40 &= ~ ( V_42 << V_37 ) ;
V_40 |= V_30 [ V_33 ] << V_37 ;
V_40 &= ~ ( V_43 << V_44 ) ;
V_40 |= V_31 [ V_36 ] << V_44 ;
F_5 ( V_2 , V_41 , V_40 ) ;
}
static void F_14 ( struct V_23 * V_13 , struct V_9 * V_10 )
{
static const T_3 V_45 [ 6 ] = {
0xc2 , 0xc1 , 0xc0 , 0xc4 , 0xc5 , 0xc6 ,
} ;
static const T_3 V_46 [ 3 ] = {
0x67 , 0x21 , 0x20 ,
} ;
struct V_1 * V_2 = F_9 ( V_13 -> V_14 -> V_15 ) ;
T_1 V_47 ;
int V_33 = V_10 -> V_48 ;
int V_16 = V_10 -> V_17 ? V_18 : V_19 ;
F_1 ( V_2 , V_49 , & V_47 ) ;
if ( V_33 >= V_50 ) {
V_47 &= ~ ( V_22 << V_16 ) ;
V_47 |= V_45 [ V_33 - V_50 ] << V_16 ;
} else {
V_47 &= ~ ( V_51 << V_16 ) ;
F_8 ( V_10 , V_46 [ V_33 - V_52 ] ) ;
}
F_5 ( V_2 , V_49 , V_47 ) ;
}
static int F_15 ( struct V_1 * V_15 , const struct V_53 * V_54 )
{
static const struct V_55 V_56 = {
. V_57 = V_58 ,
. V_59 = V_60 ,
. V_61 = V_62 ,
. V_63 = V_64 ,
. V_65 = & V_66 ,
} ;
const struct V_55 * V_67 [] = { & V_56 , & V_68 } ;
T_1 V_24 ;
if ( V_5 )
F_16 (KERN_ERR DRV_NAME L_1 ) ;
F_1 ( V_15 , V_25 , & V_24 ) ;
if ( ( V_24 & V_69 ) == 0 ) {
F_16 (KERN_ERR DRV_NAME L_2 ) ;
return - V_70 ;
}
return F_17 ( V_15 , V_67 , & V_71 , NULL , 0 ) ;
}
static int T_4 F_18 ( void )
{
return F_19 ( & V_72 ) ;
}
static void T_5 F_20 ( void )
{
F_21 ( & V_72 ) ;
}
