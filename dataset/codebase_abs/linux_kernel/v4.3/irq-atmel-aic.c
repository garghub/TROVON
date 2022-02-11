static T_1 void T_2
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
struct V_7 * V_6 = V_4 -> V_6 [ 0 ] ;
T_3 V_8 ;
T_3 V_9 ;
V_8 = F_2 ( V_6 , V_10 ) ;
V_9 = F_2 ( V_6 , V_11 ) ;
if ( ! V_9 )
F_3 ( V_6 , 0 , V_12 ) ;
else
F_4 ( V_5 , V_8 , V_2 ) ;
}
static int F_5 ( struct V_13 * V_14 )
{
struct V_7 * V_6 = F_6 ( V_14 ) ;
F_7 ( V_6 ) ;
F_3 ( V_6 , V_14 -> V_15 , V_16 ) ;
F_8 ( V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 , unsigned type )
{
struct V_7 * V_6 = F_6 ( V_14 ) ;
unsigned int V_17 ;
int V_18 ;
V_17 = F_2 ( V_6 , F_10 ( V_14 -> V_19 ) ) ;
V_18 = F_11 ( V_14 , type , & V_17 ) ;
if ( V_18 )
return V_18 ;
F_3 ( V_6 , V_17 , F_10 ( V_14 -> V_19 ) ) ;
return 0 ;
}
static void F_12 ( struct V_13 * V_14 )
{
struct V_7 * V_6 = F_6 ( V_14 ) ;
F_7 ( V_6 ) ;
F_3 ( V_6 , V_6 -> V_20 , V_21 ) ;
F_3 ( V_6 , V_6 -> V_22 , V_23 ) ;
F_8 ( V_6 ) ;
}
static void F_13 ( struct V_13 * V_14 )
{
struct V_7 * V_6 = F_6 ( V_14 ) ;
F_7 ( V_6 ) ;
F_3 ( V_6 , V_6 -> V_22 , V_21 ) ;
F_3 ( V_6 , V_6 -> V_20 , V_23 ) ;
F_8 ( V_6 ) ;
}
static void F_14 ( struct V_13 * V_14 )
{
struct V_7 * V_6 = F_6 ( V_14 ) ;
F_7 ( V_6 ) ;
F_3 ( V_6 , 0xffffffff , V_21 ) ;
F_3 ( V_6 , 0xffffffff , V_24 ) ;
F_8 ( V_6 ) ;
}
static void T_4 F_15 ( struct V_25 * V_26 )
{
struct V_7 * V_6 = F_16 ( V_26 , 0 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ )
F_3 ( V_6 , 0 , V_12 ) ;
F_3 ( V_6 , 0xffffffff , V_28 ) ;
F_3 ( V_6 , 0 , V_29 ) ;
F_3 ( V_6 , 0xffffffff , V_21 ) ;
F_3 ( V_6 , 0xffffffff , V_24 ) ;
for ( V_27 = 0 ; V_27 < 32 ; V_27 ++ )
F_3 ( V_6 , V_27 , F_17 ( V_27 ) ) ;
}
static int F_18 ( struct V_25 * V_14 ,
struct V_30 * V_31 ,
const T_3 * V_32 , unsigned int V_33 ,
T_5 * V_34 ,
unsigned int * V_35 )
{
struct V_3 * V_4 = V_14 -> V_6 ;
struct V_7 * V_6 ;
unsigned V_17 ;
int V_36 ;
int V_18 ;
if ( ! V_4 )
return - V_37 ;
V_18 = F_19 ( V_14 , V_31 , V_32 , V_33 ,
V_34 , V_35 ) ;
if ( V_18 )
return V_18 ;
V_36 = V_32 [ 0 ] / V_4 -> V_38 ;
if ( V_36 >= V_4 -> V_39 )
return - V_37 ;
V_6 = V_4 -> V_6 [ V_36 ] ;
F_7 ( V_6 ) ;
V_17 = F_2 ( V_6 , F_10 ( * V_34 ) ) ;
V_18 = F_20 ( V_32 [ 2 ] , & V_17 ) ;
if ( ! V_18 )
F_3 ( V_6 , V_17 , F_10 ( * V_34 ) ) ;
F_8 ( V_6 ) ;
return V_18 ;
}
static void T_4 F_21 ( struct V_30 * V_40 )
{
F_22 ( V_40 ) ;
}
static void T_4 F_23 ( struct V_30 * V_40 )
{
F_24 ( V_40 ) ;
}
static void T_4 F_25 ( struct V_30 * V_40 )
{
F_22 ( V_40 ) ;
F_24 ( V_40 ) ;
}
static int T_4 F_26 ( struct V_30 * V_41 ,
struct V_30 * V_42 )
{
struct V_7 * V_6 ;
struct V_25 * V_26 ;
if ( V_5 )
return - V_43 ;
V_26 = F_27 ( V_41 , & V_44 , L_1 ,
V_45 ) ;
if ( F_28 ( V_26 ) )
return F_29 ( V_26 ) ;
F_30 ( V_46 ) ;
V_5 = V_26 ;
V_6 = F_16 ( V_26 , 0 ) ;
V_6 -> V_47 [ 0 ] . V_2 . V_48 = V_12 ;
V_6 -> V_47 [ 0 ] . V_2 . V_49 = V_23 ;
V_6 -> V_47 [ 0 ] . V_2 . V_50 = V_21 ;
V_6 -> V_47 [ 0 ] . V_51 . V_52 = V_53 ;
V_6 -> V_47 [ 0 ] . V_51 . V_54 = V_55 ;
V_6 -> V_47 [ 0 ] . V_51 . V_56 = F_5 ;
V_6 -> V_47 [ 0 ] . V_51 . V_57 = F_9 ;
V_6 -> V_47 [ 0 ] . V_51 . V_58 = F_12 ;
V_6 -> V_47 [ 0 ] . V_51 . V_59 = F_13 ;
V_6 -> V_47 [ 0 ] . V_51 . V_60 = F_14 ;
F_15 ( V_26 ) ;
F_31 ( F_1 ) ;
return 0 ;
}
