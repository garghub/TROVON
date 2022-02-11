static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 = 0 ;
V_5 |= V_6 ;
V_5 |= F_2 ( V_2 -> V_7 ) ;
V_5 |= V_8 ;
V_5 |= V_9 ;
V_5 |= F_3 ( V_2 -> V_10 ) ;
V_5 |= V_11 ;
F_4 ( V_2 , V_12 , 1 , & V_5 ) ;
V_4 -> V_13 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_14 ,
T_1 y1 , T_1 V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 -> V_16 ;
unsigned char * V_19 = ( unsigned char * ) V_2 -> V_18 -> V_20 ;
int V_21 = V_2 -> V_18 -> V_22 . V_21 ;
T_1 args [ 4 ] ;
F_6 ( V_17 ) ;
F_7 ( & ( V_2 -> V_23 ) ) ;
y1 &= 0xfffe ;
V_15 &= 0xfffe ;
F_8 ( V_17 , L_1 ,
1 , y1 + 1 , V_21 , V_15 - y1 , V_14 ) ;
args [ 0 ] = V_14 | 1 ;
args [ 1 ] = y1 + 1 ;
args [ 2 ] = V_21 ;
args [ 3 ] = V_15 - y1 ;
V_19 += y1 * V_21 ;
F_9 ( V_2 , V_24 , 4 , args ,
( ( V_15 - y1 ) * V_21 ) / 2 , ( T_1 * ) V_19 ) ;
F_10 ( V_2 , V_25 ) ;
V_2 -> V_26 ++ ;
F_11 ( & ( V_2 -> V_23 ) ) ;
F_12 ( V_17 ) ;
F_13 ( V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
T_1 y1 , T_1 V_15 )
{
int V_14 ;
if ( V_2 -> V_27 < 0 ) {
V_14 = F_15 ( 1 ) ;
V_2 -> V_28 = - 1 ;
} else {
V_14 = F_15 ( V_2 -> V_27 ) ;
V_2 -> V_28 = V_2 -> V_27 ;
}
if ( V_2 -> V_29 )
V_14 |= V_30 ;
F_5 ( V_2 , V_14 , y1 , V_15 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_14 ;
if ( V_2 -> V_27 < 0 ) {
V_14 = F_15 ( 0 ) ;
V_2 -> V_28 = - 1 ;
} else {
V_14 = F_15 ( V_2 -> V_27 ) ;
V_2 -> V_28 = V_2 -> V_27 ;
}
if ( V_2 -> V_29 )
V_14 |= V_30 ;
F_5 ( V_2 , V_14 , 0 , V_2 -> V_18 -> V_22 . V_31 ) ;
V_2 -> V_26 = 0 ;
}
static bool F_17 ( struct V_1 * V_2 )
{
return ( V_2 -> V_26 > 10 ) ;
}
static int T_2 F_18 ( struct V_32 * V_33 )
{
struct V_34 V_35 ;
struct V_3 * V_4 ;
V_4 = V_33 -> V_17 . V_36 ;
if ( ! V_4 )
return - V_37 ;
V_35 . V_38 = L_2 ;
V_35 . V_4 = V_4 ;
V_35 . V_39 = F_14 ;
V_35 . V_40 = F_16 ;
V_35 . V_41 = F_17 ;
V_35 . V_35 = F_1 ;
return F_19 ( V_33 , & V_35 ) ;
}
static int T_3 F_20 ( struct V_32 * V_33 )
{
return F_21 ( V_33 ) ;
}
