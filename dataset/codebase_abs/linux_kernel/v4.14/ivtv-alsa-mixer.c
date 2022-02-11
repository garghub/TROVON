static inline int F_1 ( int V_1 )
{
if ( V_1 < - 96 )
V_1 = - 96 ;
else if ( V_1 > 8 )
V_1 = 8 ;
return ( V_1 + 119 ) << 9 ;
}
static inline int F_2 ( int V_2 )
{
if ( V_2 < ( 23 << 9 ) )
V_2 = ( 23 << 9 ) ;
else if ( V_2 > ( 127 << 9 ) )
V_2 = ( 127 << 9 ) ;
return ( V_2 >> 9 ) - 119 ;
}
static int F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
V_6 -> type = V_7 ;
V_6 -> V_8 = 1 ;
V_6 -> V_9 . integer . V_10 = - 96 ;
V_6 -> V_9 . integer . V_11 = 8 ;
V_6 -> V_9 . integer . V_12 = 1 ;
return 0 ;
}
static int F_4 ( struct V_3 * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = F_5 ( V_13 ) ;
struct V_18 * V_19 = F_6 ( V_17 -> V_20 ) ;
struct V_21 V_22 ;
int V_23 ;
V_22 . V_24 = V_25 ;
V_22 . V_9 = F_1 ( V_15 -> V_9 . integer . V_9 [ 0 ] ) ;
F_7 ( V_17 ) ;
V_23 = F_8 ( V_19 -> V_26 -> V_27 , & V_22 ) ;
F_9 ( V_17 ) ;
if ( ! V_23 )
V_15 -> V_9 . integer . V_9 [ 0 ] = F_2 ( V_22 . V_9 ) ;
return V_23 ;
}
static int F_10 ( struct V_3 * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = F_5 ( V_13 ) ;
struct V_18 * V_19 = F_6 ( V_17 -> V_20 ) ;
struct V_21 V_22 ;
int V_23 ;
V_22 . V_24 = V_25 ;
V_22 . V_9 = F_1 ( V_15 -> V_9 . integer . V_9 [ 0 ] ) ;
F_7 ( V_17 ) ;
V_23 = F_8 ( V_19 -> V_26 -> V_27 , & V_22 ) ;
if ( V_23 ||
( F_2 ( V_22 . V_9 ) != V_15 -> V_9 . integer . V_9 [ 0 ] ) ) {
V_22 . V_9 = F_1 ( V_15 -> V_9 . integer . V_9 [ 0 ] ) ;
V_23 = F_11 ( V_19 -> V_26 -> V_27 , & V_22 ) ;
if ( ! V_23 )
V_23 = 1 ;
}
F_9 ( V_17 ) ;
return V_23 ;
}
int T_1 F_12 ( struct V_16 * V_17 )
{
struct V_28 * V_20 = V_17 -> V_20 ;
struct V_29 * V_30 = V_17 -> V_30 ;
int V_23 ;
F_13 ( V_30 -> V_31 , L_1 , sizeof( V_30 -> V_31 ) ) ;
V_23 = F_14 ( V_30 , F_15 ( & V_32 , V_17 ) ) ;
if ( V_23 ) {
F_16 ( L_2 ,
V_33 , V_32 . V_34 , V_23 ) ;
}
return V_23 ;
}
