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
int F_11 ( struct V_8 * V_9 , T_2 * V_6 , T_3 V_17 )
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
int F_15 ( struct V_8 * V_9 , T_3 V_17 )
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
V_27 = F_21 ( V_1 ) ;
if ( ( V_27 & V_26 ) == 0 )
return;
V_27 &= ~ V_26 ;
if ( V_27 )
F_22 ( V_1 , V_27 ) ;
else
F_23 ( V_1 , V_23 ) ;
}
int F_24 ( struct V_8 * V_9 , int V_26 , int V_17 )
{
T_1 V_1 [ V_14 ] ;
int V_28 , V_4 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
F_6 ( V_9 , V_4 , V_1 ) ;
V_28 = F_12 ( V_1 ) ;
if ( V_28 != V_19 && V_28 != V_20 )
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
static void F_26 ( struct V_8 * V_9 , T_1 * V_1 ,
int V_26 )
{
int V_29 ;
V_29 = F_27 ( V_1 ) ;
if ( ( F_28 ( V_29 ) & V_26 ) == 0 )
return;
F_23 ( V_1 , V_23 ) ;
}
int F_29 ( struct V_8 * V_9 , int V_26 )
{
T_1 V_1 [ V_14 ] ;
int V_28 , V_4 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
F_6 ( V_9 , V_4 , V_1 ) ;
V_28 = F_12 ( V_1 ) ;
if ( V_28 != V_19 && V_28 != V_20 )
continue;
if ( F_18 ( V_1 ) )
F_20 ( V_9 , V_1 , V_26 ) ;
else
F_26 ( V_9 , V_1 , V_26 ) ;
F_10 ( V_9 , V_4 , V_1 ) ;
}
return 0 ;
}
static inline void F_30 ( T_1 * V_1 ,
int V_30 , T_3 V_17 )
{
if ( V_30 & V_31 ) {
F_23 ( V_1 , V_20 ) ;
F_31 ( V_1 , V_17 ) ;
} else {
F_23 ( V_1 , V_19 ) ;
}
}
int F_32 ( struct V_8 * V_9 , T_2 * V_6 , int V_29 ,
int V_30 , T_3 V_17 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
F_30 ( V_1 , V_30 , V_17 ) ;
F_5 ( V_1 , V_6 ) ;
F_33 ( V_1 , V_24 ) ;
F_34 ( V_1 , ( V_30 & V_32 ) ? 1 : 0 ) ;
F_35 ( V_1 , ( V_30 & V_33 ) ? 1 : 0 ) ;
F_36 ( V_1 , V_29 ) ;
V_4 = F_11 ( V_9 , V_6 , ( V_30 & V_31 ) ? V_17 : 0 ) ;
if ( V_4 < 0 )
V_4 = F_16 ( V_9 ) ;
if ( V_4 < 0 )
V_4 = F_17 ( V_9 ) ;
if ( V_4 < 0 )
return - V_34 ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_37 ( struct V_8 * V_9 , T_2 * V_6 , int V_29 ,
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
int F_38 ( struct V_8 * V_9 , T_2 * V_6 , int V_26 ,
int V_30 , T_3 V_17 , int V_35 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 , V_27 ;
V_4 = F_11 ( V_9 , V_6 , ( V_30 & V_31 ) ? V_17 : 0 ) ;
if ( V_4 >= 0 )
F_6 ( V_9 , V_4 , V_1 ) ;
F_30 ( V_1 , V_30 , V_17 ) ;
F_5 ( V_1 , V_6 ) ;
F_39 ( V_1 , ( V_30 & V_33 ) ? 1 : 0 ) ;
F_40 ( V_1 , V_35 ) ;
V_27 = F_21 ( V_1 ) ;
V_26 |= V_27 ;
F_22 ( V_1 , V_26 ) ;
if ( V_4 < 0 )
V_4 = F_16 ( V_9 ) ;
if ( V_4 < 0 )
V_4 = F_17 ( V_9 ) ;
if ( V_4 < 0 )
return - V_34 ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_41 ( struct V_8 * V_9 , T_2 * V_6 , int V_26 ,
int V_30 , T_3 V_17 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
V_4 = F_11 ( V_9 , V_6 , ( V_30 & V_31 ) ? V_17 : 0 ) ;
if ( V_4 < 0 )
return - V_36 ;
F_6 ( V_9 , V_4 , V_1 ) ;
if ( V_26 )
F_22 ( V_1 , V_26 ) ;
else
F_23 ( V_1 , V_23 ) ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_42 ( struct V_8 * V_9 , T_3 V_17 , int V_29 , int V_37 ,
int V_38 , int V_39 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
V_4 = F_15 ( V_9 , V_17 ) ;
if ( V_4 >= 0 )
F_6 ( V_9 , V_4 , V_1 ) ;
F_23 ( V_1 , V_22 ) ;
F_31 ( V_1 , V_17 ) ;
F_43 ( V_1 , V_37 ) ;
F_44 ( V_1 , V_38 ) ;
F_45 ( V_1 , V_39 ) ;
F_46 ( V_1 , V_29 ) ;
if ( V_4 < 0 )
V_4 = F_16 ( V_9 ) ;
if ( V_4 < 0 )
V_4 = F_17 ( V_9 ) ;
if ( V_4 < 0 )
return - V_34 ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_47 ( struct V_8 * V_9 , T_3 V_17 , int V_26 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
V_4 = F_15 ( V_9 , V_17 ) ;
if ( V_4 < 0 )
return - V_21 ;
F_6 ( V_9 , V_4 , V_1 ) ;
if ( V_26 )
F_46 ( V_1 , V_26 ) ;
else
F_23 ( V_1 , V_23 ) ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
void F_48 ( struct V_8 * V_9 , int V_40 )
{
T_1 V_1 [ V_14 ] ;
int type , V_4 ;
int V_39 = 0 ;
if ( V_9 -> V_40 == V_40 )
return;
V_9 -> V_40 = V_40 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
F_6 ( V_9 , V_4 , V_1 ) ;
type = F_12 ( V_1 ) ;
if ( type != V_22 )
continue;
V_39 = F_49 ( V_1 ) ;
if ( V_40 )
V_39 |= 1 ;
else
V_39 &= ~ 1 ;
F_45 ( V_1 , V_39 ) ;
F_10 ( V_9 , V_4 , V_1 ) ;
}
}
int F_50 ( struct V_8 * V_9 , int V_29 , int V_41 ,
int V_5 )
{
const struct V_42 * V_43 ;
int V_44 , V_45 ;
T_1 V_46 , V_27 ;
if ( V_41 < 0 || V_41 >= F_51 ( V_47 ) )
return - V_36 ;
V_43 = & V_47 [ V_41 ] ;
if ( V_43 -> V_48 == 0 && V_43 -> V_49 == 0 )
V_29 = 0 ;
if ( V_29 < 0 || V_29 > V_9 -> V_10 . V_50 )
return - V_36 ;
V_27 = F_2 ( V_43 -> V_3 ) ;
if ( V_5 & ~ V_27 )
return - V_36 ;
V_44 = V_43 -> V_44 + ( V_29 * V_43 -> V_48 ) ;
V_45 = V_43 -> V_45 + ( V_29 * V_43 -> V_49 ) ;
V_46 = F_9 ( V_9 -> V_10 . V_12 + V_44 ) ;
V_46 = ( V_46 & ~ ( V_27 << V_45 ) ) | ( V_5 << V_45 ) ;
F_8 ( V_46 , V_9 -> V_10 . V_12 + V_44 ) ;
return 0 ;
}
int F_52 ( struct V_8 * V_9 , int V_29 , int V_41 )
{
const struct V_42 * V_43 ;
int V_44 , V_45 ;
T_1 V_46 ;
if ( V_41 < 0 || V_41 >= F_51 ( V_47 ) )
return - V_36 ;
V_43 = & V_47 [ V_41 ] ;
if ( V_43 -> V_48 == 0 && V_43 -> V_49 == 0 )
V_29 = 0 ;
if ( V_29 < 0 || V_29 > V_9 -> V_10 . V_50 )
return - V_36 ;
V_44 = V_43 -> V_44 + ( V_29 * V_43 -> V_48 ) ;
V_45 = V_43 -> V_45 + ( V_29 * V_43 -> V_49 ) ;
V_46 = F_9 ( V_9 -> V_10 . V_12 + V_44 ) >> V_45 ;
return V_46 & F_2 ( V_43 -> V_3 ) ;
}
static void F_53 ( unsigned long V_51 )
{
struct V_8 * V_9 = (struct V_8 * ) V_51 ;
F_50 ( V_9 , 0 , V_52 , 1 ) ;
if ( V_9 -> V_53 ) {
V_9 -> V_54 . V_55 = V_56 + V_9 -> V_53 ;
F_54 ( & V_9 -> V_54 ) ;
}
}
int F_55 ( struct V_8 * V_9 , int V_53 )
{
F_56 ( & V_9 -> V_54 ) ;
V_9 -> V_53 = V_53 * V_57 ;
if ( V_9 -> V_53 ) {
V_9 -> V_54 . V_55 = V_56 + V_9 -> V_53 ;
F_54 ( & V_9 -> V_54 ) ;
}
return 0 ;
}
void F_57 ( struct V_8 * V_9 )
{
T_1 V_58 ;
V_58 = F_9 ( V_9 -> V_10 . V_12 + V_59 ) ;
F_58 ( V_9 -> V_10 . V_60 , L_1 ,
F_59 ( V_58 ) , F_60 ( V_58 ) ) ;
F_50 ( V_9 , 0 , V_61 , 1 ) ;
F_50 ( V_9 , 0 , V_62 , 1 ) ;
F_61 ( & V_9 -> V_54 ) ;
V_9 -> V_54 . V_63 = ( unsigned long ) V_9 ;
V_9 -> V_54 . V_64 = F_53 ;
if ( V_9 -> V_53 ) {
V_9 -> V_54 . V_55 = V_56 + V_9 -> V_53 ;
F_54 ( & V_9 -> V_54 ) ;
}
}
void F_62 ( struct V_8 * V_9 )
{
F_56 ( & V_9 -> V_54 ) ;
}
struct V_8 * F_63 ( struct V_65 * V_10 )
{
struct V_8 * V_9 ;
V_9 = F_64 ( sizeof( * V_9 ) , V_66 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_10 = * V_10 ;
V_9 -> V_53 = V_9 -> V_10 . V_67 * V_57 ;
return V_9 ;
}
int F_65 ( struct V_8 * V_9 )
{
if ( ! V_9 )
return - V_36 ;
F_50 ( V_9 , 0 , V_61 , 0 ) ;
F_66 ( V_9 ) ;
return 0 ;
}
void F_67 ( struct V_8 * V_9 , T_1 * V_63 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_9 -> V_10 . V_11 ; V_7 ++ ) {
F_6 ( V_9 , V_7 , V_63 ) ;
V_63 += V_14 ;
}
}
