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
static void F_5 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_3 * V_4 = V_16 -> V_6 ;
struct V_7 * V_6 = V_4 -> V_6 [ 0 ] ;
F_6 ( V_6 ) ;
F_3 ( V_6 , V_14 -> V_17 , V_18 ) ;
F_3 ( V_6 , 1 , V_19 ) ;
V_6 -> V_20 &= ~ V_14 -> V_21 ;
F_7 ( V_6 ) ;
}
static void F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_3 * V_4 = V_16 -> V_6 ;
struct V_7 * V_6 = V_4 -> V_6 [ 0 ] ;
F_6 ( V_6 ) ;
F_3 ( V_6 , V_14 -> V_17 , V_18 ) ;
F_3 ( V_6 , 1 , V_22 ) ;
V_6 -> V_20 |= V_14 -> V_21 ;
F_7 ( V_6 ) ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_3 * V_4 = V_16 -> V_6 ;
struct V_7 * V_6 = V_4 -> V_6 [ 0 ] ;
F_6 ( V_6 ) ;
F_3 ( V_6 , V_14 -> V_17 , V_18 ) ;
F_3 ( V_6 , 1 , V_23 ) ;
F_7 ( V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 , unsigned type )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_3 * V_4 = V_16 -> V_6 ;
struct V_7 * V_6 = V_4 -> V_6 [ 0 ] ;
unsigned int V_24 ;
int V_25 ;
F_6 ( V_6 ) ;
F_3 ( V_6 , V_14 -> V_17 , V_18 ) ;
V_24 = F_2 ( V_6 , V_26 ) ;
V_25 = F_11 ( V_14 , type , & V_24 ) ;
if ( ! V_25 )
F_3 ( V_6 , V_24 , V_26 ) ;
F_7 ( V_6 ) ;
return V_25 ;
}
static void F_12 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_3 * V_4 = V_16 -> V_6 ;
struct V_7 * V_27 = V_4 -> V_6 [ 0 ] ;
struct V_7 * V_6 = F_13 ( V_14 ) ;
int V_28 ;
T_3 V_21 ;
F_6 ( V_27 ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; V_28 ++ ) {
V_21 = 1 << V_28 ;
if ( ( V_21 & V_6 -> V_20 ) == ( V_21 & V_6 -> V_30 ) )
continue;
F_3 ( V_27 , V_28 + V_6 -> V_31 , V_18 ) ;
if ( V_21 & V_6 -> V_30 )
F_3 ( V_27 , 1 , V_22 ) ;
else
F_3 ( V_27 , 1 , V_19 ) ;
}
F_7 ( V_27 ) ;
}
static void F_14 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_3 * V_4 = V_16 -> V_6 ;
struct V_7 * V_27 = V_4 -> V_6 [ 0 ] ;
struct V_7 * V_6 = F_13 ( V_14 ) ;
int V_28 ;
T_3 V_21 ;
F_6 ( V_27 ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; V_28 ++ ) {
V_21 = 1 << V_28 ;
if ( ( V_21 & V_6 -> V_20 ) == ( V_21 & V_6 -> V_30 ) )
continue;
F_3 ( V_27 , V_28 + V_6 -> V_31 , V_18 ) ;
if ( V_21 & V_6 -> V_20 )
F_3 ( V_27 , 1 , V_22 ) ;
else
F_3 ( V_27 , 1 , V_19 ) ;
}
F_7 ( V_27 ) ;
}
static void F_15 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_3 * V_4 = V_16 -> V_6 ;
struct V_7 * V_27 = V_4 -> V_6 [ 0 ] ;
struct V_7 * V_6 = F_13 ( V_14 ) ;
int V_28 ;
F_6 ( V_27 ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; V_28 ++ ) {
F_3 ( V_27 , V_28 + V_6 -> V_31 , V_18 ) ;
F_3 ( V_27 , 1 , V_19 ) ;
F_3 ( V_27 , 1 , V_32 ) ;
}
F_7 ( V_27 ) ;
}
static void T_4 F_16 ( struct V_15 * V_16 )
{
struct V_7 * V_6 = F_17 ( V_16 , 0 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ )
F_3 ( V_6 , 0 , V_12 ) ;
F_3 ( V_6 , 0xffffffff , V_33 ) ;
F_3 ( V_6 , 0 , V_34 ) ;
for ( V_28 = 0 ; V_28 < V_16 -> V_35 ; V_28 ++ ) {
F_3 ( V_6 , V_28 , V_18 ) ;
F_3 ( V_6 , V_28 , V_36 ) ;
F_3 ( V_6 , 1 , V_19 ) ;
F_3 ( V_6 , 1 , V_32 ) ;
}
}
static int F_18 ( struct V_15 * V_14 ,
struct V_37 * V_38 ,
const T_3 * V_39 , unsigned int V_40 ,
T_5 * V_41 ,
unsigned int * V_42 )
{
struct V_3 * V_4 = V_14 -> V_6 ;
struct V_7 * V_6 ;
unsigned V_24 ;
int V_25 ;
if ( ! V_4 )
return - V_43 ;
V_25 = F_19 ( V_14 , V_38 , V_39 , V_40 ,
V_41 , V_42 ) ;
if ( V_25 )
return V_25 ;
V_6 = V_4 -> V_6 [ 0 ] ;
F_6 ( V_6 ) ;
F_3 ( V_6 , * V_41 , V_18 ) ;
V_24 = F_2 ( V_6 , V_26 ) ;
V_25 = F_20 ( V_39 [ 2 ] , & V_24 ) ;
if ( ! V_25 )
F_3 ( V_6 , V_39 [ 2 ] | V_24 , V_26 ) ;
F_7 ( V_6 ) ;
return V_25 ;
}
static void T_4 F_21 ( struct V_37 * V_44 )
{
F_22 ( V_44 ) ;
}
static int T_4 F_23 ( struct V_37 * V_45 ,
struct V_37 * V_46 ,
int V_47 )
{
struct V_7 * V_6 ;
struct V_15 * V_16 ;
int V_48 ;
int V_28 ;
if ( V_47 > V_49 )
return - V_43 ;
if ( V_5 )
return - V_50 ;
V_16 = F_24 ( V_45 , & V_51 , L_1 ,
V_47 ) ;
if ( F_25 ( V_16 ) )
return F_26 ( V_16 ) ;
F_27 ( V_52 ) ;
V_5 = V_16 ;
V_48 = V_5 -> V_35 / 32 ;
for ( V_28 = 0 ; V_28 < V_48 ; V_28 ++ ) {
V_6 = F_17 ( V_16 , V_28 * 32 ) ;
V_6 -> V_53 [ 0 ] . V_2 . V_54 = V_12 ;
V_6 -> V_53 [ 0 ] . V_55 . V_56 = F_5 ;
V_6 -> V_53 [ 0 ] . V_55 . V_57 = F_8 ;
V_6 -> V_53 [ 0 ] . V_55 . V_58 = F_9 ;
V_6 -> V_53 [ 0 ] . V_55 . V_59 = F_10 ;
V_6 -> V_53 [ 0 ] . V_55 . V_60 = F_12 ;
V_6 -> V_53 [ 0 ] . V_55 . V_61 = F_14 ;
V_6 -> V_53 [ 0 ] . V_55 . V_62 = F_15 ;
}
F_16 ( V_16 ) ;
F_28 ( F_1 ) ;
return 0 ;
}
static int T_4 F_29 ( struct V_37 * V_45 ,
struct V_37 * V_46 )
{
return F_23 ( V_45 , V_46 , V_63 ) ;
}
static int T_4 F_30 ( struct V_37 * V_45 ,
struct V_37 * V_46 )
{
return F_23 ( V_45 , V_46 , V_64 ) ;
}
