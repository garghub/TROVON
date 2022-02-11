static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_9 ) ;
int V_11 = ! F_3 ( V_5 ) ;
if ( F_4 ( V_10 -> V_12 ) )
F_5 ( V_10 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_10 = F_2 ( V_9 ) ;
int V_11 = ! F_3 ( V_5 ) ;
if ( F_4 ( V_10 -> V_13 ) )
F_5 ( V_10 -> V_13 , V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = & V_16 ;
struct V_10 * V_10 ;
int V_17 ;
V_10 = F_8 ( & V_15 -> V_18 , sizeof( struct V_10 ) ,
V_19 ) ;
if ( V_10 == NULL )
return - V_20 ;
V_21 [ 0 ] . V_22 =
F_9 ( V_15 -> V_18 . V_23 , L_1 , 0 ) ;
V_21 [ 0 ] . V_24 =
F_9 ( V_15 -> V_18 . V_23 , L_1 , 0 ) ;
V_21 [ 0 ] . V_25 =
F_9 ( V_15 -> V_18 . V_23 , L_2 , 0 ) ;
V_10 -> V_13 = F_10 ( V_15 -> V_18 . V_23 ,
L_3 , 0 ) ;
V_10 -> V_12 = F_10 ( V_15 -> V_18 . V_23 ,
L_4 , 0 ) ;
if ( F_4 ( V_10 -> V_13 ) ) {
V_17 = F_11 ( & V_15 -> V_18 ,
V_10 -> V_13 ,
V_26 , L_5 ) ;
if ( V_17 ) {
F_12 ( & V_15 -> V_18 ,
L_6 ,
V_10 -> V_13 , V_17 ) ;
return V_17 ;
}
}
if ( F_4 ( V_10 -> V_12 ) ) {
V_17 = F_11 ( & V_15 -> V_18 ,
V_10 -> V_12 ,
V_26 , L_7 ) ;
if ( V_17 ) {
F_12 ( & V_15 -> V_18 ,
L_6 ,
V_10 -> V_12 , V_17 ) ;
return V_17 ;
}
}
V_9 -> V_18 = & V_15 -> V_18 ;
F_13 ( V_9 , V_10 ) ;
V_17 = F_14 ( & V_15 -> V_18 , V_9 ) ;
if ( V_17 )
F_12 ( & V_15 -> V_18 , L_8 , V_17 ) ;
return V_17 ;
}
