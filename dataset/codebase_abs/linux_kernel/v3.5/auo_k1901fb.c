static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 = 0 ;
V_5 |= V_6 ;
V_5 |= V_7 ;
V_5 |= F_2 ( V_2 -> V_8 ) ;
V_5 |= V_9 ;
F_3 ( V_2 , V_10 , 1 , & V_5 ) ;
V_4 -> V_11 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_12 ,
T_1 y1 , T_1 V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 -> V_14 ;
unsigned char * V_17 = ( unsigned char * ) V_2 -> V_16 -> V_18 ;
int V_19 = V_2 -> V_16 -> V_20 . V_19 ;
T_1 args [ 5 ] ;
F_5 ( V_15 ) ;
F_6 ( & ( V_2 -> V_21 ) ) ;
y1 &= 0xfffe ;
V_13 &= 0xfffe ;
F_7 ( V_15 , L_1 ,
1 , y1 + 1 , V_19 , V_13 - y1 , V_12 ) ;
args [ 0 ] = F_8 ( V_2 -> V_22 ) | 1 ;
args [ 1 ] = y1 + 1 ;
args [ 2 ] = V_19 ;
args [ 3 ] = V_13 - y1 ;
V_17 += y1 * V_19 ;
F_9 ( V_2 , V_23 , 4 ,
args , ( ( V_13 - y1 ) * V_19 ) / 2 ,
( T_1 * ) V_17 ) ;
F_10 ( V_2 , V_24 ) ;
args [ 0 ] = V_12 | F_11 ( V_2 -> V_22 ) ;
args [ 1 ] = 1 ;
args [ 2 ] = y1 + 1 ;
args [ 3 ] = V_19 ;
args [ 4 ] = V_13 - y1 ;
F_12 ( V_2 , V_25 , 5 , args ) ;
V_2 -> V_26 ++ ;
F_13 ( & ( V_2 -> V_21 ) ) ;
F_14 ( V_15 ) ;
F_15 ( V_15 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
T_1 y1 , T_1 V_13 )
{
int V_12 ;
if ( V_2 -> V_27 < 0 ) {
V_12 = F_17 ( 1 ) ;
V_2 -> V_28 = - 1 ;
} else {
V_12 = F_17 ( V_2 -> V_27 ) ;
V_2 -> V_28 = V_2 -> V_27 ;
}
if ( V_2 -> V_29 )
V_12 |= V_30 ;
F_4 ( V_2 , V_12 , y1 , V_13 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_12 ;
V_2 -> V_4 -> V_11 ( V_2 ) ;
if ( V_2 -> V_27 < 0 ) {
V_12 = F_17 ( 0 ) ;
V_2 -> V_28 = - 1 ;
} else {
V_12 = F_17 ( V_2 -> V_27 ) ;
V_2 -> V_28 = V_2 -> V_27 ;
}
if ( V_2 -> V_29 )
V_12 |= V_30 ;
F_4 ( V_2 , V_12 , 0 , V_2 -> V_16 -> V_20 . V_31 ) ;
V_2 -> V_26 = 0 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
return ( V_2 -> V_26 > 10 ) ;
}
static int T_2 F_20 ( struct V_32 * V_33 )
{
struct V_34 V_35 ;
struct V_3 * V_4 ;
V_4 = V_33 -> V_15 . V_36 ;
if ( ! V_4 )
return - V_37 ;
V_35 . V_38 = L_2 ;
V_35 . V_4 = V_4 ;
V_35 . V_39 = F_16 ;
V_35 . V_40 = F_18 ;
V_35 . V_41 = F_19 ;
V_35 . V_35 = F_1 ;
return F_21 ( V_33 , & V_35 ) ;
}
static int T_3 F_22 ( struct V_32 * V_33 )
{
return F_23 ( V_33 ) ;
}
