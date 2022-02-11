static inline int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
if ( F_2 ( V_5 ) ) {
T_1 T_2 V_6 ;
F_3 ( V_7 [ V_3 ] , * V_4 , T_2 ) ;
return 0 ;
}
return F_4 ( V_2 , V_8 [ V_3 ] , V_4 ) ;
}
static inline int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
if ( F_2 ( V_5 ) ) {
F_6 ( V_7 [ V_3 ] , V_4 , 0 ) ;
return 0 ;
}
return F_7 ( V_2 , V_8 [ V_3 ] , V_4 ) ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 -> V_11 -> V_12 ) ;
T_1 V_13 ;
F_1 ( V_2 , V_14 , & V_13 ) ;
if ( V_13 & ( V_15 << V_10 -> V_16 ) )
return V_17 ;
else
return V_18 ;
}
static void F_10 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
static const T_3 V_21 [ 5 ] = {
0x98 , 0x55 , 0x32 , 0x21 , 0x20 ,
} ;
static const T_3 V_22 [ 5 ] = {
0x2 , 0x1 , 0x0 , 0x0 , 0x0 ,
} ;
static const T_3 V_23 [ 5 ] = {
0x99 , 0x92 , 0x90 , 0x22 , 0x20 ,
} ;
struct V_1 * V_2 = F_9 ( V_10 -> V_11 -> V_12 ) ;
struct V_19 * V_24 = F_11 ( V_20 ) ;
int V_25 = V_20 -> V_26 - V_27 ;
int V_28 = V_25 ;
int V_29 = V_20 -> V_30 ? V_31 : V_32 ;
int V_33 = V_20 -> V_30 ? V_34 : V_35 ;
T_1 V_36 , V_37 , V_38 ;
if ( V_24 )
V_28 = F_12 ( V_25 , V_24 -> V_26 - V_27 ) ;
F_1 ( V_2 , V_39 , & V_36 ) ;
F_1 ( V_2 , V_40 , & V_37 ) ;
F_1 ( V_2 , V_41 , & V_38 ) ;
V_36 &= ~ ( V_42 << V_29 ) ;
V_36 |= V_21 [ V_25 ] << V_29 ;
V_37 &= ~ ( V_43 << V_33 ) ;
V_37 |= V_22 [ V_25 ] << V_33 ;
V_37 &= ~ ( V_44 << V_45 ) ;
V_37 |= V_23 [ V_28 ] << V_45 ;
V_38 &= ~ ( V_42 << V_29 ) ;
V_38 |= V_46 << V_29 ;
F_5 ( V_2 , V_39 , V_36 ) ;
F_5 ( V_2 , V_40 , V_37 ) ;
F_5 ( V_2 , V_41 , V_38 ) ;
}
static void F_13 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
static const T_3 V_47 [ 6 ] = {
0xc2 , 0xc1 , 0xc0 , 0xc4 , 0xc5 , 0xc6 ,
} ;
static const T_3 V_48 [ 3 ] = {
0x67 , 0x21 , 0x20 ,
} ;
struct V_1 * V_2 = F_9 ( V_10 -> V_11 -> V_12 ) ;
T_1 V_36 , V_38 ;
int V_25 = V_20 -> V_49 ;
int V_29 = V_20 -> V_30 ? V_31 : V_32 ;
if ( V_25 >= V_50 ) {
F_1 ( V_2 , V_41 , & V_38 ) ;
V_38 &= ~ ( V_42 << V_29 ) ;
V_38 |= V_47 [ V_25 - V_50 ] << V_29 ;
F_5 ( V_2 , V_41 , V_38 ) ;
} else {
F_1 ( V_2 , V_39 , & V_36 ) ;
V_36 &= ~ ( V_42 << V_29 ) ;
V_36 |= V_48 [ V_25 - V_51 ] << V_29 ;
F_5 ( V_2 , V_39 , V_36 ) ;
}
}
static int F_14 ( struct V_1 * V_12 , const struct V_52 * V_53 )
{
static const struct V_54 V_55 = {
. V_56 = V_57 ,
. V_58 = V_59 ,
. V_60 = V_61 ,
. V_62 = V_63 ,
. V_64 = & V_65 ,
} ;
const struct V_54 * V_66 [] = { & V_55 , & V_67 } ;
T_1 V_13 ;
if ( V_5 )
F_15 (KERN_ERR DRV_NAME L_1 ) ;
F_1 ( V_12 , V_14 , & V_13 ) ;
if ( ( V_13 & V_68 ) == 0 ) {
F_15 (KERN_ERR DRV_NAME L_2 ) ;
return - V_69 ;
}
return F_16 ( V_12 , V_66 , & V_70 , NULL , 0 ) ;
}
static int T_4 F_17 ( void )
{
return F_18 ( & V_71 ) ;
}
static void T_5 F_19 ( void )
{
F_20 ( & V_71 ) ;
}
