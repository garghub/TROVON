static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_3 ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_8 = 0 ;
F_2 ( V_4 ) ;
V_8 |= V_9 ;
V_8 |= V_10 ;
V_8 |= F_3 ( V_2 -> V_11 ) ;
V_8 |= V_12 ;
F_4 ( V_2 , V_13 , 1 , & V_8 ) ;
V_7 -> V_14 ( V_2 ) ;
F_5 ( V_4 ) ;
F_6 ( V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_15 ,
T_1 y1 , T_1 V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_3 ;
unsigned char * V_17 = ( unsigned char * ) V_2 -> V_5 -> V_18 ;
int V_19 = V_2 -> V_5 -> V_20 . V_19 ;
int V_21 = V_2 -> V_5 -> V_22 . V_21 ;
T_1 args [ 5 ] ;
F_2 ( V_4 ) ;
F_8 ( & ( V_2 -> V_23 ) ) ;
y1 &= 0xfffe ;
V_16 &= 0xfffe ;
F_9 ( V_4 , L_1 ,
1 , y1 + 1 , V_19 , V_16 - y1 , V_15 ) ;
args [ 0 ] = F_10 ( V_2 -> V_24 ) | 1 ;
args [ 1 ] = y1 + 1 ;
args [ 2 ] = V_19 ;
args [ 3 ] = V_16 - y1 ;
V_17 += y1 * V_21 ;
F_11 ( V_2 , V_25 , 4 ,
args , ( ( V_16 - y1 ) * V_21 ) / 2 ,
( T_1 * ) V_17 ) ;
F_12 ( V_2 , V_26 ) ;
args [ 0 ] = V_15 | F_13 ( V_2 -> V_24 ) ;
args [ 1 ] = 1 ;
args [ 2 ] = y1 + 1 ;
args [ 3 ] = V_19 ;
args [ 4 ] = V_16 - y1 ;
F_14 ( V_2 , V_27 , 5 , args ) ;
V_2 -> V_28 ++ ;
F_15 ( & ( V_2 -> V_23 ) ) ;
F_5 ( V_4 ) ;
F_6 ( V_4 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
T_1 y1 , T_1 V_16 )
{
int V_15 ;
if ( V_2 -> V_29 < 0 ) {
V_15 = F_17 ( 1 ) ;
V_2 -> V_30 = - 1 ;
} else {
V_15 = F_17 ( V_2 -> V_29 ) ;
V_2 -> V_30 = V_2 -> V_29 ;
}
if ( V_2 -> V_31 )
V_15 |= V_32 ;
F_7 ( V_2 , V_15 , y1 , V_16 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_15 ;
V_2 -> V_7 -> V_14 ( V_2 ) ;
if ( V_2 -> V_29 < 0 ) {
V_15 = F_17 ( 0 ) ;
V_2 -> V_30 = - 1 ;
} else {
V_15 = F_17 ( V_2 -> V_29 ) ;
V_2 -> V_30 = V_2 -> V_29 ;
}
if ( V_2 -> V_31 )
V_15 |= V_32 ;
F_7 ( V_2 , V_15 , 0 , V_2 -> V_5 -> V_20 . V_33 ) ;
V_2 -> V_28 = 0 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
return ( V_2 -> V_28 > 10 ) ;
}
static int F_20 ( struct V_34 * V_35 )
{
struct V_36 V_37 ;
struct V_6 * V_7 ;
V_7 = V_35 -> V_4 . V_38 ;
if ( ! V_7 )
return - V_39 ;
V_37 . V_40 = L_2 ;
V_37 . V_7 = V_7 ;
V_37 . V_41 = F_16 ;
V_37 . V_42 = F_18 ;
V_37 . V_43 = F_19 ;
V_37 . V_37 = F_1 ;
return F_21 ( V_35 , & V_37 ) ;
}
static int F_22 ( struct V_34 * V_35 )
{
return F_23 ( V_35 ) ;
}
