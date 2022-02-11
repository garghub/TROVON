static inline int F_1 ( T_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = V_2 / 32 ;
V_2 -= V_4 * 32 ;
V_4 = 2 - V_4 ;
return ( V_1 [ V_4 ] >> V_2 ) & F_2 ( V_3 ) ;
}
static inline void F_3 ( T_1 * V_1 , T_1 V_2 , T_1 V_3 ,
T_1 V_5 )
{
int V_4 ;
V_5 &= F_2 ( V_3 ) ;
V_4 = V_2 / 32 ;
V_2 -= V_4 * 32 ;
V_4 = 2 - V_4 ;
V_1 [ V_4 ] &= ~ ( F_2 ( V_3 ) << V_2 ) ;
V_1 [ V_4 ] |= ( V_5 << V_2 ) ;
}
static inline void F_4 ( T_1 * V_1 , T_2 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
V_6 [ V_7 ] = F_1 ( V_1 , 40 - 8 * V_7 , 8 ) ;
}
static inline void F_5 ( T_1 * V_1 , T_2 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_3 ( V_1 , 40 - 8 * V_7 , 8 , V_6 [ V_7 ] ) ;
}
static int F_6 ( struct V_8 * V_9 , int V_4 , T_1 * V_1 )
{
int V_7 ;
F_7 ( V_4 > V_9 -> V_10 . V_11 ) ;
F_8 ( V_4 , V_9 -> V_10 . V_12 + V_13 ) ;
for ( V_7 = 0 ; V_7 < V_14 ; V_7 ++ )
V_1 [ V_7 ] = F_9 ( V_9 -> V_10 . V_12 +
V_15 + 4 * V_7 ) ;
return V_4 ;
}
static int F_10 ( struct V_8 * V_9 , int V_4 , T_1 * V_1 )
{
int V_7 ;
F_7 ( V_4 > V_9 -> V_10 . V_11 ) ;
for ( V_7 = 0 ; V_7 < V_14 ; V_7 ++ )
F_8 ( V_1 [ V_7 ] , V_9 -> V_10 . V_12 +
V_15 + 4 * V_7 ) ;
F_8 ( V_4 | V_16 , V_9 -> V_10 . V_12 +
V_13 ) ;
return V_4 ;
}
static int F_11 ( struct V_8 * V_9 , T_2 * V_6 , T_3 V_17 )
{
T_1 V_1 [ V_14 ] ;
int type , V_4 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
T_2 V_18 [ 6 ] ;
F_6 ( V_9 , V_4 , V_1 ) ;
type = F_12 ( V_1 ) ;
if ( type != V_19 && type != V_20 )
continue;
if ( F_13 ( V_1 ) != V_17 )
continue;
F_4 ( V_1 , V_18 ) ;
if ( F_14 ( V_18 , V_6 ) )
return V_4 ;
}
return - V_21 ;
}
static int F_15 ( struct V_8 * V_9 , T_3 V_17 )
{
T_1 V_1 [ V_14 ] ;
int type , V_4 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
F_6 ( V_9 , V_4 , V_1 ) ;
type = F_12 ( V_1 ) ;
if ( type != V_22 )
continue;
if ( F_13 ( V_1 ) == V_17 )
return V_4 ;
}
return - V_21 ;
}
static int F_16 ( struct V_8 * V_9 )
{
T_1 V_1 [ V_14 ] ;
int type , V_4 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
F_6 ( V_9 , V_4 , V_1 ) ;
type = F_12 ( V_1 ) ;
if ( type == V_23 )
return V_4 ;
}
return - V_21 ;
}
static int F_17 ( struct V_8 * V_9 )
{
T_1 V_1 [ V_14 ] ;
int type , V_4 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
F_6 ( V_9 , V_4 , V_1 ) ;
type = F_12 ( V_1 ) ;
if ( type != V_19 && type != V_20 )
continue;
if ( F_18 ( V_1 ) )
continue;
type = F_19 ( V_1 ) ;
if ( type != V_24 &&
type != V_25 )
return V_4 ;
}
return - V_21 ;
}
static void F_20 ( struct V_8 * V_9 , T_1 * V_1 ,
int V_26 )
{
int V_27 ;
V_27 = F_21 ( V_1 ,
V_9 -> V_28 ) ;
if ( ( V_27 & V_26 ) == 0 )
return;
V_27 &= ~ V_26 ;
if ( V_27 )
F_22 ( V_1 , V_27 ,
V_9 -> V_28 ) ;
else
F_23 ( V_1 , V_23 ) ;
}
int F_24 ( struct V_8 * V_9 , int V_26 , int V_17 )
{
T_1 V_1 [ V_14 ] ;
int V_29 , V_4 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
F_6 ( V_9 , V_4 , V_1 ) ;
V_29 = F_12 ( V_1 ) ;
if ( V_29 != V_19 && V_29 != V_20 )
continue;
if ( V_17 != - 1 && F_13 ( V_1 ) != V_17 )
continue;
if ( F_18 ( V_1 ) ) {
T_2 V_6 [ 6 ] ;
F_4 ( V_1 , V_6 ) ;
if ( ! F_25 ( V_6 ) )
F_20 ( V_9 , V_1 , V_26 ) ;
}
F_10 ( V_9 , V_4 , V_1 ) ;
}
return 0 ;
}
static inline void F_26 ( T_1 * V_1 ,
int V_30 , T_3 V_17 )
{
if ( V_30 & V_31 ) {
F_23 ( V_1 , V_20 ) ;
F_27 ( V_1 , V_17 ) ;
} else {
F_23 ( V_1 , V_19 ) ;
}
}
int F_28 ( struct V_8 * V_9 , T_2 * V_6 , int V_32 ,
int V_30 , T_3 V_17 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
F_26 ( V_1 , V_30 , V_17 ) ;
F_5 ( V_1 , V_6 ) ;
F_29 ( V_1 , V_24 ) ;
F_30 ( V_1 , ( V_30 & V_33 ) ? 1 : 0 ) ;
F_31 ( V_1 , ( V_30 & V_34 ) ? 1 : 0 ) ;
F_32 ( V_1 , V_32 , V_9 -> V_35 ) ;
V_4 = F_11 ( V_9 , V_6 , ( V_30 & V_31 ) ? V_17 : 0 ) ;
if ( V_4 < 0 )
V_4 = F_16 ( V_9 ) ;
if ( V_4 < 0 )
V_4 = F_17 ( V_9 ) ;
if ( V_4 < 0 )
return - V_36 ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_33 ( struct V_8 * V_9 , T_2 * V_6 , int V_32 ,
int V_30 , T_3 V_17 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
V_4 = F_11 ( V_9 , V_6 , ( V_30 & V_31 ) ? V_17 : 0 ) ;
if ( V_4 < 0 )
return - V_21 ;
F_23 ( V_1 , V_23 ) ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_34 ( struct V_8 * V_9 , T_2 * V_6 , int V_26 ,
int V_30 , T_3 V_17 , int V_37 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 , V_27 ;
V_4 = F_11 ( V_9 , V_6 , ( V_30 & V_31 ) ? V_17 : 0 ) ;
if ( V_4 >= 0 )
F_6 ( V_9 , V_4 , V_1 ) ;
F_26 ( V_1 , V_30 , V_17 ) ;
F_5 ( V_1 , V_6 ) ;
F_35 ( V_1 , ( V_30 & V_34 ) ? 1 : 0 ) ;
F_36 ( V_1 , V_37 ) ;
V_27 = F_21 ( V_1 ,
V_9 -> V_28 ) ;
V_26 |= V_27 ;
F_22 ( V_1 , V_26 ,
V_9 -> V_28 ) ;
if ( V_4 < 0 )
V_4 = F_16 ( V_9 ) ;
if ( V_4 < 0 )
V_4 = F_17 ( V_9 ) ;
if ( V_4 < 0 )
return - V_36 ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_37 ( struct V_8 * V_9 , T_2 * V_6 , int V_26 ,
int V_30 , T_3 V_17 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
V_4 = F_11 ( V_9 , V_6 , ( V_30 & V_31 ) ? V_17 : 0 ) ;
if ( V_4 < 0 )
return - V_38 ;
F_6 ( V_9 , V_4 , V_1 ) ;
if ( V_26 )
F_22 ( V_1 , V_26 ,
V_9 -> V_28 ) ;
else
F_23 ( V_1 , V_23 ) ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
static void F_38 ( struct V_8 * V_9 , T_1 * V_1 ,
int V_39 , int V_40 )
{
int V_4 ;
V_4 = F_39 ( V_1 ) ;
F_40 ( V_39 , V_9 -> V_10 . V_12 + F_41 ( V_4 ) ) ;
V_4 = F_42 ( V_1 ) ;
F_40 ( V_40 , V_9 -> V_10 . V_12 + F_41 ( V_4 ) ) ;
}
int F_43 ( struct V_8 * V_9 , T_3 V_17 , int V_32 , int V_41 ,
int V_39 , int V_40 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
V_4 = F_15 ( V_9 , V_17 ) ;
if ( V_4 >= 0 )
F_6 ( V_9 , V_4 , V_1 ) ;
F_23 ( V_1 , V_22 ) ;
F_27 ( V_1 , V_17 ) ;
F_44 ( V_1 , V_41 , V_9 -> V_42 ) ;
if ( ! V_9 -> V_10 . V_43 ) {
F_45 ( V_1 , V_39 ,
V_9 -> V_42 ) ;
F_46 ( V_1 , V_40 ,
V_9 -> V_42 ) ;
} else {
F_38 ( V_9 , V_1 , V_39 , V_40 ) ;
}
F_47 ( V_1 , V_32 , V_9 -> V_42 ) ;
if ( V_4 < 0 )
V_4 = F_16 ( V_9 ) ;
if ( V_4 < 0 )
V_4 = F_17 ( V_9 ) ;
if ( V_4 < 0 )
return - V_36 ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_48 ( struct V_8 * V_9 , T_3 V_17 , int V_26 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
V_4 = F_15 ( V_9 , V_17 ) ;
if ( V_4 < 0 )
return - V_21 ;
F_6 ( V_9 , V_4 , V_1 ) ;
if ( V_26 )
F_47 ( V_1 , V_26 ,
V_9 -> V_42 ) ;
else
F_23 ( V_1 , V_23 ) ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
void F_49 ( struct V_8 * V_9 , int V_44 )
{
T_1 V_1 [ V_14 ] ;
int type , V_4 ;
int V_40 = 0 ;
if ( V_9 -> V_44 == V_44 )
return;
V_9 -> V_44 = V_44 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
F_6 ( V_9 , V_4 , V_1 ) ;
type = F_12 ( V_1 ) ;
if ( type != V_22 )
continue;
V_40 =
F_50 ( V_1 ,
V_9 -> V_42 ) ;
if ( V_44 )
V_40 |= 1 ;
else
V_40 &= ~ 1 ;
F_46 ( V_1 , V_40 ,
V_9 -> V_42 ) ;
F_10 ( V_9 , V_4 , V_1 ) ;
}
}
int F_51 ( struct V_8 * V_9 , int V_32 , int V_45 ,
int V_5 )
{
const struct V_46 * V_47 ;
int V_48 , V_49 ;
T_1 V_50 , V_27 ;
if ( V_45 < 0 || V_45 >= F_52 ( V_51 ) )
return - V_38 ;
V_47 = & V_51 [ V_45 ] ;
if ( V_47 -> V_52 == 0 && V_47 -> V_53 == 0 )
V_32 = 0 ;
if ( V_32 < 0 || V_32 > V_9 -> V_10 . V_54 )
return - V_38 ;
V_27 = F_2 ( V_47 -> V_3 ) ;
if ( V_5 & ~ V_27 )
return - V_38 ;
V_48 = V_47 -> V_48 + ( V_32 * V_47 -> V_52 ) ;
V_49 = V_47 -> V_49 + ( V_32 * V_47 -> V_53 ) ;
V_50 = F_9 ( V_9 -> V_10 . V_12 + V_48 ) ;
V_50 = ( V_50 & ~ ( V_27 << V_49 ) ) | ( V_5 << V_49 ) ;
F_8 ( V_50 , V_9 -> V_10 . V_12 + V_48 ) ;
return 0 ;
}
int F_53 ( struct V_8 * V_9 , int V_32 , int V_45 )
{
const struct V_46 * V_47 ;
int V_48 , V_49 ;
T_1 V_50 ;
if ( V_45 < 0 || V_45 >= F_52 ( V_51 ) )
return - V_38 ;
V_47 = & V_51 [ V_45 ] ;
if ( V_47 -> V_52 == 0 && V_47 -> V_53 == 0 )
V_32 = 0 ;
if ( V_32 < 0 || V_32 > V_9 -> V_10 . V_54 )
return - V_38 ;
V_48 = V_47 -> V_48 + ( V_32 * V_47 -> V_52 ) ;
V_49 = V_47 -> V_49 + ( V_32 * V_47 -> V_53 ) ;
V_50 = F_9 ( V_9 -> V_10 . V_12 + V_48 ) >> V_49 ;
return V_50 & F_2 ( V_47 -> V_3 ) ;
}
static void F_54 ( unsigned long V_55 )
{
struct V_8 * V_9 = (struct V_8 * ) V_55 ;
F_51 ( V_9 , 0 , V_56 , 1 ) ;
if ( V_9 -> V_57 ) {
V_9 -> V_58 . V_59 = V_60 + V_9 -> V_57 ;
F_55 ( & V_9 -> V_58 ) ;
}
}
void F_56 ( struct V_8 * V_9 )
{
T_1 V_61 , V_11 ;
V_61 = F_9 ( V_9 -> V_10 . V_12 + V_62 ) ;
if ( ! V_9 -> V_10 . V_63 )
V_9 -> V_10 . V_63 = 0xff ;
V_9 -> V_64 =
( F_57 ( V_61 , V_9 -> V_10 . V_63 ) << 8 ) |
F_58 ( V_61 ) ;
F_59 ( V_9 -> V_10 . V_65 , L_1 ,
F_57 ( V_61 , V_9 -> V_10 . V_63 ) ,
F_58 ( V_61 ) ) ;
if ( ! V_9 -> V_10 . V_11 ) {
V_11 =
F_9 ( V_9 -> V_10 . V_12 + V_66 ) &
V_67 ;
if ( ! V_11 )
V_11 = V_68 ;
else
V_11 *= V_69 ;
V_9 -> V_10 . V_11 = V_11 ;
}
F_59 ( V_9 -> V_10 . V_65 ,
L_2 , V_9 -> V_10 . V_11 ) ;
V_9 -> V_28 = 3 ;
V_9 -> V_35 = 2 ;
V_9 -> V_42 = 3 ;
if ( V_9 -> V_10 . V_43 ) {
V_51 [ V_70 ] . V_3 =
V_9 -> V_10 . V_54 ;
V_51 [ V_70 ] . V_48 =
V_71 ;
V_51 [ V_72 ] . V_3 =
V_9 -> V_10 . V_54 ;
V_51 [ V_72 ] . V_49 = 0 ;
V_51 [ V_72 ] . V_48 =
V_73 ;
V_51 [ V_74 ] . V_3 =
V_9 -> V_10 . V_54 ;
V_51 [ V_74 ] . V_49 = 0 ;
V_51 [ V_74 ] . V_48 =
V_75 ;
V_51 [ V_76 ] . V_3 =
V_9 -> V_10 . V_54 ;
V_51 [ V_76 ] . V_49 = 0 ;
V_51 [ V_76 ] . V_48 =
V_77 ;
V_9 -> V_28 = V_9 -> V_10 . V_54 ;
V_9 -> V_35 = V_9 -> V_10 . V_54 - 1 ;
V_9 -> V_42 = V_9 -> V_10 . V_54 ;
} else if ( V_9 -> V_64 == V_78 ) {
V_9 -> V_28 = V_9 -> V_10 . V_54 ;
V_9 -> V_35 = 3 ;
V_9 -> V_42 = V_9 -> V_10 . V_54 ;
}
F_51 ( V_9 , 0 , V_79 , 1 ) ;
F_51 ( V_9 , 0 , V_80 , 1 ) ;
F_60 ( & V_9 -> V_58 ) ;
V_9 -> V_58 . V_81 = ( unsigned long ) V_9 ;
V_9 -> V_58 . V_82 = F_54 ;
if ( V_9 -> V_57 ) {
V_9 -> V_58 . V_59 = V_60 + V_9 -> V_57 ;
F_55 ( & V_9 -> V_58 ) ;
}
}
void F_61 ( struct V_8 * V_9 )
{
F_62 ( & V_9 -> V_58 ) ;
}
struct V_8 * F_63 ( struct V_83 * V_10 )
{
struct V_8 * V_9 ;
V_9 = F_64 ( sizeof( * V_9 ) , V_84 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_10 = * V_10 ;
V_9 -> V_57 = V_9 -> V_10 . V_85 * V_86 ;
return V_9 ;
}
int F_65 ( struct V_8 * V_9 )
{
if ( ! V_9 )
return - V_38 ;
F_51 ( V_9 , 0 , V_79 , 0 ) ;
F_66 ( V_9 ) ;
return 0 ;
}
void F_67 ( struct V_8 * V_9 , T_1 * V_81 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_9 -> V_10 . V_11 ; V_7 ++ ) {
F_6 ( V_9 , V_7 , V_81 ) ;
V_81 += V_14 ;
}
}
