static void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 [ 0 ] = F_2 ( V_3 ) ;
V_1 -> V_2 [ 1 ] = F_2 ( V_3 ) ;
V_1 -> V_2 [ 2 ] = F_2 ( V_3 ) ;
V_1 -> V_4 [ 0 ] = F_2 ( V_3 ) ;
V_1 -> V_4 [ 1 ] = F_2 ( V_3 ) ;
V_1 -> V_4 [ 2 ] = F_2 ( V_3 ) ;
V_1 -> V_2 [ 3 ] = F_2 ( V_3 ) ;
V_1 -> V_4 [ 3 ] = F_2 ( V_3 ) ;
}
static int F_3 ( int V_5 [ 4 ] )
{
int V_6 , V_7 = V_5 [ 3 ] ;
V_6 = V_5 [ 0 ] | ( ( V_7 & 0x03 ) << 8 ) ;
V_6 += V_5 [ 1 ] | ( ( V_7 & 0x0c ) << 6 ) ;
V_6 += V_5 [ 2 ] | ( ( V_7 & 0x30 ) << 4 ) ;
return V_6 / 3 ;
}
static T_1 F_4 ( int V_8 , void * V_9 )
{
struct V_10 * V_11 = V_9 ;
struct V_1 * V_1 = F_5 ( V_11 ) ;
struct V_12 * V_13 = V_1 -> V_14 ;
int V_15 , V_16 ;
if ( F_6 ( V_1 -> V_17 ) ) {
F_7 ( V_13 , V_18 , 0 ) ;
F_8 ( V_13 ) ;
} else {
F_9 () ;
if ( F_10 ( V_19 ) == V_3 ) {
F_1 ( V_1 ) ;
V_15 = F_3 ( V_1 -> V_2 ) ;
V_16 = F_3 ( V_1 -> V_4 ) ;
F_7 ( V_13 , V_18 , 1 ) ;
F_11 ( V_13 , V_20 , V_15 ) ;
F_11 ( V_13 , V_21 , V_16 ) ;
F_8 ( V_13 ) ;
}
F_12 () ;
}
return V_22 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_1 ;
struct V_12 * V_12 ;
int error , V_8 ;
V_1 = F_14 ( & V_11 -> V_14 , sizeof( * V_1 ) , V_23 ) ;
if ( ! V_1 )
return - V_24 ;
V_12 = F_15 ( & V_11 -> V_14 ) ;
if ( ! V_12 )
return - V_24 ;
F_16 ( V_11 , V_1 ) ;
V_1 -> V_17 = F_17 ( & V_11 -> V_14 , L_1 , V_25 ) ;
if ( F_18 ( V_1 -> V_17 ) )
return F_19 ( V_1 -> V_17 ) ;
V_8 = F_20 ( V_1 -> V_17 ) ;
if ( V_8 <= 0 )
return V_8 < 0 ? V_8 : - V_26 ;
V_1 -> V_14 = V_12 ;
V_12 -> V_27 = L_2 ;
V_12 -> V_28 = L_3 ;
V_12 -> V_29 . V_30 = V_31 ;
V_12 -> V_14 . V_32 = & V_11 -> V_14 ;
V_12 -> V_33 [ 0 ] = F_21 ( V_34 ) | F_21 ( V_35 ) ;
V_12 -> V_36 [ F_22 ( V_18 ) ] = F_21 ( V_18 ) ;
F_23 ( V_12 , V_20 , 270 , 3900 , 0 , 0 ) ;
F_23 ( V_12 , V_21 , 180 , 3700 , 0 , 0 ) ;
error = F_24 ( & V_11 -> V_14 , V_8 , F_4 ,
V_37 ,
L_4 , V_11 ) ;
if ( error ) {
F_25 ( & V_11 -> V_14 , L_5 ) ;
return error ;
}
error = F_26 ( V_1 -> V_14 ) ;
if ( error )
return error ;
return 0 ;
}
