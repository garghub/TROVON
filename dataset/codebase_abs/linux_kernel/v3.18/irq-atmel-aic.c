static T_1 void T_2
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
struct V_7 * V_6 = V_4 -> V_6 [ 0 ] ;
T_3 V_8 ;
T_3 V_9 ;
V_8 = F_2 ( V_6 -> V_10 + V_11 ) ;
V_9 = F_2 ( V_6 -> V_10 + V_12 ) ;
if ( ! V_9 )
F_3 ( 0 , V_6 -> V_10 + V_13 ) ;
else
F_4 ( V_5 , V_8 , V_2 ) ;
}
static int F_5 ( struct V_14 * V_15 )
{
struct V_7 * V_6 = F_6 ( V_15 ) ;
F_7 ( V_6 ) ;
F_3 ( V_15 -> V_16 , V_6 -> V_10 + V_17 ) ;
F_8 ( V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 , unsigned type )
{
struct V_7 * V_6 = F_6 ( V_15 ) ;
unsigned int V_18 ;
int V_19 ;
V_18 = F_2 ( V_6 -> V_10 + F_10 ( V_15 -> V_20 ) ) ;
V_19 = F_11 ( V_15 , type , & V_18 ) ;
if ( V_19 )
return V_19 ;
F_3 ( V_18 , V_6 -> V_10 + F_10 ( V_15 -> V_20 ) ) ;
return 0 ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_7 * V_6 = F_6 ( V_15 ) ;
F_7 ( V_6 ) ;
F_3 ( V_6 -> V_21 , V_6 -> V_10 + V_22 ) ;
F_3 ( V_6 -> V_23 , V_6 -> V_10 + V_24 ) ;
F_8 ( V_6 ) ;
}
static void F_13 ( struct V_14 * V_15 )
{
struct V_7 * V_6 = F_6 ( V_15 ) ;
F_7 ( V_6 ) ;
F_3 ( V_6 -> V_23 , V_6 -> V_10 + V_22 ) ;
F_3 ( V_6 -> V_21 , V_6 -> V_10 + V_24 ) ;
F_8 ( V_6 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_7 * V_6 = F_6 ( V_15 ) ;
F_7 ( V_6 ) ;
F_3 ( 0xffffffff , V_6 -> V_10 + V_22 ) ;
F_3 ( 0xffffffff , V_6 -> V_10 + V_25 ) ;
F_8 ( V_6 ) ;
}
static void T_4 F_15 ( struct V_26 * V_27 )
{
struct V_7 * V_6 = F_16 ( V_27 , 0 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ )
F_3 ( 0 , V_6 -> V_10 + V_13 ) ;
F_3 ( 0xffffffff , V_6 -> V_10 + V_29 ) ;
F_3 ( 0 , V_6 -> V_10 + V_30 ) ;
F_3 ( 0xffffffff , V_6 -> V_10 + V_22 ) ;
F_3 ( 0xffffffff , V_6 -> V_10 + V_25 ) ;
for ( V_28 = 0 ; V_28 < 32 ; V_28 ++ )
F_3 ( V_28 , V_6 -> V_10 + F_17 ( V_28 ) ) ;
}
static int F_18 ( struct V_26 * V_15 ,
struct V_31 * V_32 ,
const T_3 * V_33 , unsigned int V_34 ,
T_5 * V_35 ,
unsigned int * V_36 )
{
struct V_3 * V_4 = V_15 -> V_6 ;
struct V_7 * V_6 ;
unsigned V_18 ;
int V_37 ;
int V_19 ;
if ( ! V_4 )
return - V_38 ;
V_19 = F_19 ( V_15 , V_32 , V_33 , V_34 ,
V_35 , V_36 ) ;
if ( V_19 )
return V_19 ;
V_37 = V_33 [ 0 ] / V_4 -> V_39 ;
if ( V_37 >= V_4 -> V_40 )
return - V_38 ;
V_6 = V_4 -> V_6 [ V_37 ] ;
F_7 ( V_6 ) ;
V_18 = F_2 ( V_6 -> V_10 + F_10 ( * V_35 ) ) ;
V_19 = F_20 ( V_33 [ 2 ] , & V_18 ) ;
if ( ! V_19 )
F_3 ( V_18 , V_6 -> V_10 + F_10 ( * V_35 ) ) ;
F_8 ( V_6 ) ;
return V_19 ;
}
static void T_4 F_21 ( struct V_31 * V_41 )
{
F_22 ( V_41 ) ;
}
static int T_4 F_23 ( struct V_31 * V_42 ,
struct V_31 * V_43 )
{
struct V_7 * V_6 ;
struct V_26 * V_27 ;
if ( V_5 )
return - V_44 ;
V_27 = F_24 ( V_42 , & V_45 , L_1 ,
V_46 ) ;
if ( F_25 ( V_27 ) )
return F_26 ( V_27 ) ;
F_27 ( V_47 ) ;
V_5 = V_27 ;
V_6 = F_16 ( V_27 , 0 ) ;
V_6 -> V_48 [ 0 ] . V_2 . V_49 = V_13 ;
V_6 -> V_48 [ 0 ] . V_2 . V_50 = V_24 ;
V_6 -> V_48 [ 0 ] . V_2 . V_51 = V_22 ;
V_6 -> V_48 [ 0 ] . V_52 . V_53 = V_54 ;
V_6 -> V_48 [ 0 ] . V_52 . V_55 = V_56 ;
V_6 -> V_48 [ 0 ] . V_52 . V_57 = F_5 ;
V_6 -> V_48 [ 0 ] . V_52 . V_58 = F_9 ;
V_6 -> V_48 [ 0 ] . V_52 . V_59 = F_12 ;
V_6 -> V_48 [ 0 ] . V_52 . V_60 = F_13 ;
V_6 -> V_48 [ 0 ] . V_52 . V_61 = F_14 ;
F_15 ( V_27 ) ;
F_28 ( F_1 ) ;
return 0 ;
}
