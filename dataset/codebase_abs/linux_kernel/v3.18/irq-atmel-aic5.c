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
static void F_5 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_3 * V_4 = V_17 -> V_6 ;
struct V_7 * V_6 = V_4 -> V_6 [ 0 ] ;
F_6 ( V_6 ) ;
F_3 ( V_15 -> V_18 , V_6 -> V_10 + V_19 ) ;
F_3 ( 1 , V_6 -> V_10 + V_20 ) ;
V_6 -> V_21 &= ~ V_15 -> V_22 ;
F_7 ( V_6 ) ;
}
static void F_8 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_3 * V_4 = V_17 -> V_6 ;
struct V_7 * V_6 = V_4 -> V_6 [ 0 ] ;
F_6 ( V_6 ) ;
F_3 ( V_15 -> V_18 , V_6 -> V_10 + V_19 ) ;
F_3 ( 1 , V_6 -> V_10 + V_23 ) ;
V_6 -> V_21 |= V_15 -> V_22 ;
F_7 ( V_6 ) ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_3 * V_4 = V_17 -> V_6 ;
struct V_7 * V_6 = V_4 -> V_6 [ 0 ] ;
F_6 ( V_6 ) ;
F_3 ( V_15 -> V_18 , V_6 -> V_10 + V_19 ) ;
F_3 ( 1 , V_6 -> V_10 + V_24 ) ;
F_7 ( V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 , unsigned type )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_3 * V_4 = V_17 -> V_6 ;
struct V_7 * V_6 = V_4 -> V_6 [ 0 ] ;
unsigned int V_25 ;
int V_26 ;
F_6 ( V_6 ) ;
F_3 ( V_15 -> V_18 , V_6 -> V_10 + V_19 ) ;
V_25 = F_2 ( V_6 -> V_10 + V_27 ) ;
V_26 = F_11 ( V_15 , type , & V_25 ) ;
if ( ! V_26 )
F_3 ( V_25 , V_6 -> V_10 + V_27 ) ;
F_7 ( V_6 ) ;
return V_26 ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_3 * V_4 = V_17 -> V_6 ;
struct V_7 * V_28 = V_4 -> V_6 [ 0 ] ;
struct V_7 * V_6 = F_13 ( V_15 ) ;
int V_29 ;
T_3 V_22 ;
F_6 ( V_28 ) ;
for ( V_29 = 0 ; V_29 < V_4 -> V_30 ; V_29 ++ ) {
V_22 = 1 << V_29 ;
if ( ( V_22 & V_6 -> V_21 ) == ( V_22 & V_6 -> V_31 ) )
continue;
F_3 ( V_29 + V_6 -> V_32 ,
V_28 -> V_10 + V_19 ) ;
if ( V_22 & V_6 -> V_31 )
F_3 ( 1 , V_28 -> V_10 + V_23 ) ;
else
F_3 ( 1 , V_28 -> V_10 + V_20 ) ;
}
F_7 ( V_28 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_3 * V_4 = V_17 -> V_6 ;
struct V_7 * V_28 = V_4 -> V_6 [ 0 ] ;
struct V_7 * V_6 = F_13 ( V_15 ) ;
int V_29 ;
T_3 V_22 ;
F_6 ( V_28 ) ;
for ( V_29 = 0 ; V_29 < V_4 -> V_30 ; V_29 ++ ) {
V_22 = 1 << V_29 ;
if ( ( V_22 & V_6 -> V_21 ) == ( V_22 & V_6 -> V_31 ) )
continue;
F_3 ( V_29 + V_6 -> V_32 ,
V_28 -> V_10 + V_19 ) ;
if ( V_22 & V_6 -> V_21 )
F_3 ( 1 , V_28 -> V_10 + V_23 ) ;
else
F_3 ( 1 , V_28 -> V_10 + V_20 ) ;
}
F_7 ( V_28 ) ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_3 * V_4 = V_17 -> V_6 ;
struct V_7 * V_28 = V_4 -> V_6 [ 0 ] ;
struct V_7 * V_6 = F_13 ( V_15 ) ;
int V_29 ;
F_6 ( V_28 ) ;
for ( V_29 = 0 ; V_29 < V_4 -> V_30 ; V_29 ++ ) {
F_3 ( V_29 + V_6 -> V_32 ,
V_28 -> V_10 + V_19 ) ;
F_3 ( 1 , V_28 -> V_10 + V_20 ) ;
F_3 ( 1 , V_28 -> V_10 + V_33 ) ;
}
F_7 ( V_28 ) ;
}
static void T_4 F_16 ( struct V_16 * V_17 )
{
struct V_7 * V_6 = F_17 ( V_17 , 0 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ )
F_3 ( 0 , V_6 -> V_10 + V_13 ) ;
F_3 ( 0xffffffff , V_6 -> V_10 + V_34 ) ;
F_3 ( 0 , V_6 -> V_10 + V_35 ) ;
for ( V_29 = 0 ; V_29 < V_17 -> V_36 ; V_29 ++ ) {
F_3 ( V_29 , V_6 -> V_10 + V_19 ) ;
F_3 ( V_29 , V_6 -> V_10 + V_37 ) ;
F_3 ( 1 , V_6 -> V_10 + V_20 ) ;
F_3 ( 1 , V_6 -> V_10 + V_33 ) ;
}
}
static int F_18 ( struct V_16 * V_15 ,
struct V_38 * V_39 ,
const T_3 * V_40 , unsigned int V_41 ,
T_5 * V_42 ,
unsigned int * V_43 )
{
struct V_3 * V_4 = V_15 -> V_6 ;
struct V_7 * V_6 ;
unsigned V_25 ;
int V_26 ;
if ( ! V_4 )
return - V_44 ;
V_26 = F_19 ( V_15 , V_39 , V_40 , V_41 ,
V_42 , V_43 ) ;
if ( V_26 )
return V_26 ;
V_6 = V_4 -> V_6 [ 0 ] ;
F_6 ( V_6 ) ;
F_3 ( * V_42 , V_6 -> V_10 + V_19 ) ;
V_25 = F_2 ( V_6 -> V_10 + V_27 ) ;
V_26 = F_20 ( V_40 [ 2 ] , & V_25 ) ;
if ( ! V_26 )
F_3 ( V_40 [ 2 ] | V_25 , V_6 -> V_10 + V_27 ) ;
F_7 ( V_6 ) ;
return V_26 ;
}
static void T_4 F_21 ( struct V_38 * V_45 )
{
F_22 ( V_45 ) ;
}
static int T_4 F_23 ( struct V_38 * V_46 ,
struct V_38 * V_47 ,
int V_48 )
{
struct V_7 * V_6 ;
struct V_16 * V_17 ;
int V_49 ;
int V_29 ;
if ( V_48 > V_50 )
return - V_44 ;
if ( V_5 )
return - V_51 ;
V_17 = F_24 ( V_46 , & V_52 , L_1 ,
V_48 ) ;
if ( F_25 ( V_17 ) )
return F_26 ( V_17 ) ;
F_27 ( V_53 ) ;
V_5 = V_17 ;
V_49 = V_5 -> V_36 / 32 ;
for ( V_29 = 0 ; V_29 < V_49 ; V_29 ++ ) {
V_6 = F_17 ( V_17 , V_29 * 32 ) ;
V_6 -> V_54 [ 0 ] . V_2 . V_55 = V_13 ;
V_6 -> V_54 [ 0 ] . V_56 . V_57 = F_5 ;
V_6 -> V_54 [ 0 ] . V_56 . V_58 = F_8 ;
V_6 -> V_54 [ 0 ] . V_56 . V_59 = F_9 ;
V_6 -> V_54 [ 0 ] . V_56 . V_60 = F_10 ;
V_6 -> V_54 [ 0 ] . V_56 . V_61 = F_12 ;
V_6 -> V_54 [ 0 ] . V_56 . V_62 = F_14 ;
V_6 -> V_54 [ 0 ] . V_56 . V_63 = F_15 ;
}
F_16 ( V_17 ) ;
F_28 ( F_1 ) ;
return 0 ;
}
static int T_4 F_29 ( struct V_38 * V_46 ,
struct V_38 * V_47 )
{
return F_23 ( V_46 , V_47 , V_64 ) ;
}
static int T_4 F_30 ( struct V_38 * V_46 ,
struct V_38 * V_47 )
{
return F_23 ( V_46 , V_47 , V_65 ) ;
}
