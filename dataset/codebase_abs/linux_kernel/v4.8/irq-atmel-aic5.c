static T_1 void T_2
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_5 , 0 ) ;
T_3 V_6 ;
T_3 V_7 ;
V_6 = F_3 ( V_4 , V_8 ) ;
V_7 = F_3 ( V_4 , V_9 ) ;
if ( ! V_7 )
F_4 ( V_4 , 0 , V_10 ) ;
else
F_5 ( V_5 , V_6 , V_2 ) ;
}
static void F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_3 * V_4 = F_2 ( V_14 , 0 ) ;
struct V_3 * V_15 = F_7 ( V_12 ) ;
F_8 ( V_4 ) ;
F_4 ( V_15 , V_12 -> V_16 , V_17 ) ;
F_4 ( V_15 , 1 , V_18 ) ;
V_15 -> V_19 &= ~ V_12 -> V_20 ;
F_9 ( V_4 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_3 * V_4 = F_2 ( V_14 , 0 ) ;
struct V_3 * V_15 = F_7 ( V_12 ) ;
F_8 ( V_4 ) ;
F_4 ( V_15 , V_12 -> V_16 , V_17 ) ;
F_4 ( V_15 , 1 , V_21 ) ;
V_15 -> V_19 |= V_12 -> V_20 ;
F_9 ( V_4 ) ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_3 * V_4 = F_2 ( V_14 , 0 ) ;
F_8 ( V_4 ) ;
F_4 ( V_4 , V_12 -> V_16 , V_17 ) ;
F_4 ( V_4 , 1 , V_22 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 , unsigned type )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_3 * V_4 = F_2 ( V_14 , 0 ) ;
unsigned int V_23 ;
int V_24 ;
F_8 ( V_4 ) ;
F_4 ( V_4 , V_12 -> V_16 , V_17 ) ;
V_23 = F_3 ( V_4 , V_25 ) ;
V_24 = F_13 ( V_12 , type , & V_23 ) ;
if ( ! V_24 )
F_4 ( V_4 , V_23 , V_25 ) ;
F_9 ( V_4 ) ;
return V_24 ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_26 * V_27 = V_14 -> V_15 ;
struct V_3 * V_4 = F_2 ( V_14 , 0 ) ;
struct V_3 * V_15 = F_7 ( V_12 ) ;
int V_28 ;
T_3 V_20 ;
F_8 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_27 -> V_29 ; V_28 ++ ) {
V_20 = 1 << V_28 ;
if ( ( V_20 & V_15 -> V_19 ) == ( V_20 & V_15 -> V_30 ) )
continue;
F_4 ( V_4 , V_28 + V_15 -> V_31 , V_17 ) ;
if ( V_20 & V_15 -> V_30 )
F_4 ( V_4 , 1 , V_21 ) ;
else
F_4 ( V_4 , 1 , V_18 ) ;
}
F_9 ( V_4 ) ;
}
static void F_15 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_26 * V_27 = V_14 -> V_15 ;
struct V_3 * V_4 = F_2 ( V_14 , 0 ) ;
struct V_3 * V_15 = F_7 ( V_12 ) ;
int V_28 ;
T_3 V_20 ;
F_8 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_27 -> V_29 ; V_28 ++ ) {
V_20 = 1 << V_28 ;
if ( ( V_20 & V_15 -> V_19 ) == ( V_20 & V_15 -> V_30 ) )
continue;
F_4 ( V_4 , V_28 + V_15 -> V_31 , V_17 ) ;
if ( V_20 & V_15 -> V_19 )
F_4 ( V_4 , 1 , V_21 ) ;
else
F_4 ( V_4 , 1 , V_18 ) ;
}
F_9 ( V_4 ) ;
}
static void F_16 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_26 * V_27 = V_14 -> V_15 ;
struct V_3 * V_4 = F_2 ( V_14 , 0 ) ;
struct V_3 * V_15 = F_7 ( V_12 ) ;
int V_28 ;
F_8 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_27 -> V_29 ; V_28 ++ ) {
F_4 ( V_4 , V_28 + V_15 -> V_31 , V_17 ) ;
F_4 ( V_4 , 1 , V_18 ) ;
F_4 ( V_4 , 1 , V_32 ) ;
}
F_9 ( V_4 ) ;
}
static void T_4 F_17 ( struct V_13 * V_14 )
{
struct V_3 * V_15 = F_2 ( V_14 , 0 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ )
F_4 ( V_15 , 0 , V_10 ) ;
F_4 ( V_15 , 0xffffffff , V_33 ) ;
F_4 ( V_15 , 0 , V_34 ) ;
for ( V_28 = 0 ; V_28 < V_14 -> V_35 ; V_28 ++ ) {
F_4 ( V_15 , V_28 , V_17 ) ;
F_4 ( V_15 , V_28 , V_36 ) ;
F_4 ( V_15 , 1 , V_18 ) ;
F_4 ( V_15 , 1 , V_32 ) ;
}
}
static int F_18 ( struct V_13 * V_12 ,
struct V_37 * V_38 ,
const T_3 * V_39 , unsigned int V_40 ,
T_5 * V_41 ,
unsigned int * V_42 )
{
struct V_3 * V_4 = F_2 ( V_12 , 0 ) ;
unsigned long V_43 ;
unsigned V_23 ;
int V_24 ;
if ( ! V_4 )
return - V_44 ;
V_24 = F_19 ( V_12 , V_38 , V_39 , V_40 ,
V_41 , V_42 ) ;
if ( V_24 )
return V_24 ;
F_20 ( V_4 , V_43 ) ;
F_4 ( V_4 , * V_41 , V_17 ) ;
V_23 = F_3 ( V_4 , V_25 ) ;
F_21 ( V_39 [ 2 ] , & V_23 ) ;
F_4 ( V_4 , V_23 , V_25 ) ;
F_22 ( V_4 , V_43 ) ;
return V_24 ;
}
static void T_4 F_23 ( struct V_37 * V_45 )
{
F_24 ( V_45 ) ;
}
static int T_4 F_25 ( struct V_37 * V_46 ,
struct V_37 * V_47 ,
int V_48 )
{
struct V_3 * V_15 ;
struct V_13 * V_14 ;
int V_49 ;
int V_28 ;
if ( V_48 > V_50 )
return - V_44 ;
if ( V_5 )
return - V_51 ;
V_14 = F_26 ( V_46 , & V_52 , L_1 ,
V_48 , V_53 ) ;
if ( F_27 ( V_14 ) )
return F_28 ( V_14 ) ;
V_5 = V_14 ;
V_49 = V_5 -> V_35 / 32 ;
for ( V_28 = 0 ; V_28 < V_49 ; V_28 ++ ) {
V_15 = F_2 ( V_14 , V_28 * 32 ) ;
V_15 -> V_54 [ 0 ] . V_2 . V_55 = V_10 ;
V_15 -> V_54 [ 0 ] . V_56 . V_57 = F_6 ;
V_15 -> V_54 [ 0 ] . V_56 . V_58 = F_10 ;
V_15 -> V_54 [ 0 ] . V_56 . V_59 = F_11 ;
V_15 -> V_54 [ 0 ] . V_56 . V_60 = F_12 ;
V_15 -> V_54 [ 0 ] . V_56 . V_61 = F_14 ;
V_15 -> V_54 [ 0 ] . V_56 . V_62 = F_15 ;
V_15 -> V_54 [ 0 ] . V_56 . V_63 = F_16 ;
}
F_17 ( V_14 ) ;
F_29 ( F_1 ) ;
return 0 ;
}
static int T_4 F_30 ( struct V_37 * V_46 ,
struct V_37 * V_47 )
{
return F_25 ( V_46 , V_47 , V_64 ) ;
}
static int T_4 F_31 ( struct V_37 * V_46 ,
struct V_37 * V_47 )
{
return F_25 ( V_46 , V_47 , V_65 ) ;
}
static int T_4 F_32 ( struct V_37 * V_46 ,
struct V_37 * V_47 )
{
return F_25 ( V_46 , V_47 , V_66 ) ;
}
