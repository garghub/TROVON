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
static int F_11 ( struct V_8 * V_9 , T_2 * V_6 )
{
T_1 V_1 [ V_14 ] ;
int type , V_4 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
T_2 V_17 [ 6 ] ;
F_6 ( V_9 , V_4 , V_1 ) ;
type = F_12 ( V_1 ) ;
if ( type != V_18 && type != V_19 )
continue;
F_4 ( V_1 , V_17 ) ;
if ( memcmp ( V_17 , V_6 , 6 ) == 0 )
return V_4 ;
}
return - V_20 ;
}
static int F_13 ( struct V_8 * V_9 )
{
T_1 V_1 [ V_14 ] ;
int type , V_4 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
F_6 ( V_9 , V_4 , V_1 ) ;
type = F_12 ( V_1 ) ;
if ( type == V_21 )
return V_4 ;
}
return - V_20 ;
}
static int F_14 ( struct V_8 * V_9 )
{
T_1 V_1 [ V_14 ] ;
int type , V_4 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
F_6 ( V_9 , V_4 , V_1 ) ;
type = F_12 ( V_1 ) ;
if ( type != V_18 && type != V_19 )
continue;
if ( F_15 ( V_1 ) )
continue;
type = F_16 ( V_1 ) ;
if ( type != V_22 &&
type != V_23 )
return V_4 ;
}
return - V_20 ;
}
static void F_17 ( struct V_8 * V_9 , T_1 * V_1 ,
int V_24 )
{
int V_25 ;
V_25 = F_18 ( V_1 ) ;
if ( ( V_25 & V_24 ) == 0 )
return;
V_25 &= ~ V_24 ;
if ( V_25 == F_19 ( V_9 -> V_10 . V_26 ) )
F_20 ( V_1 , V_21 ) ;
else
F_21 ( V_1 , V_25 ) ;
}
static void F_22 ( struct V_8 * V_9 , T_1 * V_1 ,
int V_24 )
{
int V_27 ;
V_27 = F_23 ( V_1 ) ;
if ( ( F_19 ( V_27 ) & V_24 ) == 0 )
return;
F_20 ( V_1 , V_21 ) ;
}
int F_24 ( struct V_8 * V_9 , int V_24 )
{
T_1 V_1 [ V_14 ] ;
int V_28 , V_4 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_10 . V_11 ; V_4 ++ ) {
F_6 ( V_9 , V_4 , V_1 ) ;
V_28 = F_12 ( V_1 ) ;
if ( V_28 != V_18 && V_28 != V_19 )
continue;
if ( F_15 ( V_1 ) )
F_17 ( V_9 , V_1 , V_24 ) ;
else
F_22 ( V_9 , V_1 , V_24 ) ;
F_10 ( V_9 , V_4 , V_1 ) ;
}
return 0 ;
}
int F_25 ( struct V_8 * V_9 , T_2 * V_6 , int V_27 , int V_29 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
F_20 ( V_1 , V_18 ) ;
F_5 ( V_1 , V_6 ) ;
F_26 ( V_1 , V_22 ) ;
F_27 ( V_1 , ( V_29 & V_30 ) ? 1 : 0 ) ;
F_28 ( V_1 , ( V_29 & V_31 ) ? 1 : 0 ) ;
F_29 ( V_1 , V_27 ) ;
V_4 = F_11 ( V_9 , V_6 ) ;
if ( V_4 < 0 )
V_4 = F_13 ( V_9 ) ;
if ( V_4 < 0 )
V_4 = F_14 ( V_9 ) ;
if ( V_4 < 0 )
return - V_32 ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_30 ( struct V_8 * V_9 , T_2 * V_6 , int V_27 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
V_4 = F_11 ( V_9 , V_6 ) ;
if ( V_4 < 0 )
return - V_20 ;
F_20 ( V_1 , V_21 ) ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_31 ( struct V_8 * V_9 , T_2 * V_6 , int V_24 ,
int V_33 , int V_34 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 , V_25 ;
V_4 = F_11 ( V_9 , V_6 ) ;
if ( V_4 >= 0 )
F_6 ( V_9 , V_4 , V_1 ) ;
F_20 ( V_1 , V_18 ) ;
F_5 ( V_1 , V_6 ) ;
F_32 ( V_1 , V_33 ) ;
F_33 ( V_1 , V_34 ) ;
V_25 = F_18 ( V_1 ) ;
V_24 |= V_25 ;
F_21 ( V_1 , V_24 ) ;
if ( V_4 < 0 )
V_4 = F_13 ( V_9 ) ;
if ( V_4 < 0 )
V_4 = F_14 ( V_9 ) ;
if ( V_4 < 0 )
return - V_32 ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_34 ( struct V_8 * V_9 , T_2 * V_6 , int V_24 )
{
T_1 V_1 [ V_14 ] = { 0 , 0 , 0 } ;
int V_4 ;
V_4 = F_11 ( V_9 , V_6 ) ;
if ( V_4 < 0 )
return - V_35 ;
F_6 ( V_9 , V_4 , V_1 ) ;
if ( V_24 )
F_21 ( V_1 , V_24 ) ;
else
F_20 ( V_1 , V_21 ) ;
F_10 ( V_9 , V_4 , V_1 ) ;
return 0 ;
}
int F_35 ( struct V_8 * V_9 , int V_27 , int V_36 ,
int V_5 )
{
const struct V_37 * V_38 ;
int V_39 , V_40 ;
T_1 V_41 , V_25 ;
if ( V_36 < 0 || V_36 >= F_36 ( V_42 ) )
return - V_35 ;
V_38 = & V_42 [ V_36 ] ;
if ( V_38 -> V_43 == 0 && V_38 -> V_44 == 0 )
V_27 = 0 ;
if ( V_27 < 0 || V_27 > V_9 -> V_10 . V_26 )
return - V_35 ;
V_25 = F_2 ( V_38 -> V_3 ) ;
if ( V_5 & ~ V_25 )
return - V_35 ;
V_39 = V_38 -> V_39 + ( V_27 * V_38 -> V_43 ) ;
V_40 = V_38 -> V_40 + ( V_27 * V_38 -> V_44 ) ;
V_41 = F_9 ( V_9 -> V_10 . V_12 + V_39 ) ;
V_41 = ( V_41 & ~ ( V_25 << V_40 ) ) | ( V_5 << V_40 ) ;
F_8 ( V_41 , V_9 -> V_10 . V_12 + V_39 ) ;
return 0 ;
}
int F_37 ( struct V_8 * V_9 , int V_27 , int V_36 )
{
const struct V_37 * V_38 ;
int V_39 , V_40 ;
T_1 V_41 ;
if ( V_36 < 0 || V_36 >= F_36 ( V_42 ) )
return - V_35 ;
V_38 = & V_42 [ V_36 ] ;
if ( V_38 -> V_43 == 0 && V_38 -> V_44 == 0 )
V_27 = 0 ;
if ( V_27 < 0 || V_27 > V_9 -> V_10 . V_26 )
return - V_35 ;
V_39 = V_38 -> V_39 + ( V_27 * V_38 -> V_43 ) ;
V_40 = V_38 -> V_40 + ( V_27 * V_38 -> V_44 ) ;
V_41 = F_9 ( V_9 -> V_10 . V_12 + V_39 ) >> V_40 ;
return V_41 & F_2 ( V_38 -> V_3 ) ;
}
static void F_38 ( unsigned long V_45 )
{
struct V_8 * V_9 = (struct V_8 * ) V_45 ;
F_35 ( V_9 , 0 , V_46 , 1 ) ;
if ( V_9 -> V_47 ) {
V_9 -> V_48 . V_49 = V_50 + V_9 -> V_47 ;
F_39 ( & V_9 -> V_48 ) ;
}
}
int F_40 ( struct V_8 * V_9 , int V_47 )
{
F_41 ( & V_9 -> V_48 ) ;
V_9 -> V_47 = V_47 * V_51 ;
if ( V_9 -> V_47 ) {
V_9 -> V_48 . V_49 = V_50 + V_9 -> V_47 ;
F_39 ( & V_9 -> V_48 ) ;
}
return 0 ;
}
void F_42 ( struct V_8 * V_9 )
{
T_1 V_52 ;
V_52 = F_9 ( V_9 -> V_10 . V_12 + V_53 ) ;
F_43 ( V_9 -> V_10 . V_54 , L_1 ,
F_44 ( V_52 ) , F_45 ( V_52 ) ) ;
F_35 ( V_9 , 0 , V_55 , 1 ) ;
F_35 ( V_9 , 0 , V_56 , 1 ) ;
F_46 ( & V_9 -> V_48 ) ;
V_9 -> V_48 . V_57 = ( unsigned long ) V_9 ;
V_9 -> V_48 . V_58 = F_38 ;
if ( V_9 -> V_47 ) {
V_9 -> V_48 . V_49 = V_50 + V_9 -> V_47 ;
F_39 ( & V_9 -> V_48 ) ;
}
}
void F_47 ( struct V_8 * V_9 )
{
F_41 ( & V_9 -> V_48 ) ;
}
struct V_8 * F_48 ( struct V_59 * V_10 )
{
struct V_8 * V_9 ;
V_9 = F_49 ( sizeof( * V_9 ) , V_60 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_10 = * V_10 ;
V_9 -> V_47 = V_9 -> V_10 . V_61 * V_51 ;
return V_9 ;
}
int F_50 ( struct V_8 * V_9 )
{
if ( ! V_9 )
return - V_35 ;
F_47 ( V_9 ) ;
F_35 ( V_9 , 0 , V_55 , 0 ) ;
F_51 ( V_9 ) ;
return 0 ;
}
