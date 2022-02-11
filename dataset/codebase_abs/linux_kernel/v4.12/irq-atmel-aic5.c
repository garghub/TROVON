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
if ( V_29 )
for ( V_28 = 0 ; V_28 < V_14 -> V_30 ; V_28 ++ ) {
F_4 ( V_4 , V_28 , V_17 ) ;
V_29 [ V_28 ] = F_3 ( V_4 , V_25 ) ;
}
F_8 ( V_4 ) ;
for ( V_28 = 0 ; V_28 < V_27 -> V_31 ; V_28 ++ ) {
V_20 = 1 << V_28 ;
if ( ( V_20 & V_15 -> V_19 ) == ( V_20 & V_15 -> V_32 ) )
continue;
F_4 ( V_4 , V_28 + V_15 -> V_33 , V_17 ) ;
if ( V_20 & V_15 -> V_32 )
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
if ( V_29 ) {
F_4 ( V_4 , 0xffffffff , V_34 ) ;
for ( V_28 = 0 ; V_28 < V_14 -> V_30 ; V_28 ++ ) {
F_4 ( V_4 , V_28 , V_17 ) ;
F_4 ( V_4 , V_28 , V_35 ) ;
F_4 ( V_4 , V_29 [ V_28 ] , V_25 ) ;
}
}
for ( V_28 = 0 ; V_28 < V_27 -> V_31 ; V_28 ++ ) {
V_20 = 1 << V_28 ;
if ( ! V_29 &&
( ( V_20 & V_15 -> V_19 ) == ( V_20 & V_15 -> V_32 ) ) )
continue;
F_4 ( V_4 , V_28 + V_15 -> V_33 , V_17 ) ;
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
for ( V_28 = 0 ; V_28 < V_27 -> V_31 ; V_28 ++ ) {
F_4 ( V_4 , V_28 + V_15 -> V_33 , V_17 ) ;
F_4 ( V_4 , 1 , V_18 ) ;
F_4 ( V_4 , 1 , V_36 ) ;
}
F_9 ( V_4 ) ;
}
static void T_4 F_17 ( struct V_13 * V_14 )
{
struct V_3 * V_15 = F_2 ( V_14 , 0 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ )
F_4 ( V_15 , 0 , V_10 ) ;
F_4 ( V_15 , 0xffffffff , V_34 ) ;
F_4 ( V_15 , 0 , V_37 ) ;
for ( V_28 = 0 ; V_28 < V_14 -> V_30 ; V_28 ++ ) {
F_4 ( V_15 , V_28 , V_17 ) ;
F_4 ( V_15 , V_28 , V_35 ) ;
F_4 ( V_15 , 1 , V_18 ) ;
F_4 ( V_15 , 1 , V_36 ) ;
}
}
static int F_18 ( struct V_13 * V_12 ,
struct V_38 * V_39 ,
const T_3 * V_40 , unsigned int V_41 ,
T_5 * V_42 ,
unsigned int * V_43 )
{
struct V_3 * V_4 = F_2 ( V_12 , 0 ) ;
unsigned long V_44 ;
unsigned V_23 ;
int V_24 ;
if ( ! V_4 )
return - V_45 ;
V_24 = F_19 ( V_12 , V_39 , V_40 , V_41 ,
V_42 , V_43 ) ;
if ( V_24 )
return V_24 ;
F_20 ( V_4 , V_44 ) ;
F_4 ( V_4 , * V_42 , V_17 ) ;
V_23 = F_3 ( V_4 , V_25 ) ;
F_21 ( V_40 [ 2 ] , & V_23 ) ;
F_4 ( V_4 , V_23 , V_25 ) ;
F_22 ( V_4 , V_44 ) ;
return V_24 ;
}
static void T_4 F_23 ( struct V_38 * V_46 )
{
F_24 ( V_46 ) ;
}
static int T_4 F_25 ( struct V_38 * V_47 ,
struct V_38 * V_48 ,
int V_49 )
{
struct V_3 * V_15 ;
struct V_13 * V_14 ;
int V_50 ;
int V_28 ;
if ( V_49 > V_51 )
return - V_45 ;
if ( V_5 )
return - V_52 ;
V_14 = F_26 ( V_47 , & V_53 , L_1 ,
V_49 , V_54 ) ;
if ( F_27 ( V_14 ) )
return F_28 ( V_14 ) ;
V_5 = V_14 ;
V_50 = V_5 -> V_30 / 32 ;
for ( V_28 = 0 ; V_28 < V_50 ; V_28 ++ ) {
V_15 = F_2 ( V_14 , V_28 * 32 ) ;
V_15 -> V_55 [ 0 ] . V_2 . V_56 = V_10 ;
V_15 -> V_55 [ 0 ] . V_57 . V_58 = F_6 ;
V_15 -> V_55 [ 0 ] . V_57 . V_59 = F_10 ;
V_15 -> V_55 [ 0 ] . V_57 . V_60 = F_11 ;
V_15 -> V_55 [ 0 ] . V_57 . V_61 = F_12 ;
V_15 -> V_55 [ 0 ] . V_57 . V_62 = F_14 ;
V_15 -> V_55 [ 0 ] . V_57 . V_63 = F_15 ;
V_15 -> V_55 [ 0 ] . V_57 . V_64 = F_16 ;
}
F_17 ( V_14 ) ;
F_29 ( F_1 ) ;
return 0 ;
}
static int T_4 F_30 ( struct V_38 * V_47 ,
struct V_38 * V_48 )
{
#ifdef F_31
V_29 = F_32 ( F_33 ( V_65 , 32 ) * 32 ,
sizeof( * V_29 ) , V_66 ) ;
if ( ! V_29 )
return - V_67 ;
#endif
return F_25 ( V_47 , V_48 , V_65 ) ;
}
static int T_4 F_34 ( struct V_38 * V_47 ,
struct V_38 * V_48 )
{
return F_25 ( V_47 , V_48 , V_68 ) ;
}
static int T_4 F_35 ( struct V_38 * V_47 ,
struct V_38 * V_48 )
{
return F_25 ( V_47 , V_48 , V_69 ) ;
}
