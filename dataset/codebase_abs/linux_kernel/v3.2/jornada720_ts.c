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
if ( V_17 & F_6 ( 9 ) ) {
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
static int T_2 F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_1 ;
struct V_12 * V_12 ;
int error ;
V_1 = F_14 ( sizeof( struct V_1 ) , V_23 ) ;
V_12 = F_15 () ;
if ( ! V_1 || ! V_12 ) {
error = - V_24 ;
goto V_25;
}
F_16 ( V_11 , V_1 ) ;
V_1 -> V_14 = V_12 ;
V_12 -> V_26 = L_1 ;
V_12 -> V_27 = L_2 ;
V_12 -> V_28 . V_29 = V_30 ;
V_12 -> V_14 . V_31 = & V_11 -> V_14 ;
V_12 -> V_32 [ 0 ] = F_17 ( V_33 ) | F_17 ( V_34 ) ;
V_12 -> V_35 [ F_18 ( V_18 ) ] = F_17 ( V_18 ) ;
F_19 ( V_12 , V_20 , 270 , 3900 , 0 , 0 ) ;
F_19 ( V_12 , V_21 , 180 , 3700 , 0 , 0 ) ;
error = F_20 ( V_36 ,
F_4 ,
V_37 ,
L_3 , V_11 ) ;
if ( error ) {
F_21 ( V_38 L_4 ) ;
goto V_25;
}
error = F_22 ( V_1 -> V_14 ) ;
if ( error )
goto V_39;
return 0 ;
V_39:
F_23 ( V_36 , V_11 ) ;
V_25:
F_16 ( V_11 , NULL ) ;
F_24 ( V_12 ) ;
F_25 ( V_1 ) ;
return error ;
}
static int T_3 F_26 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_5 ( V_11 ) ;
F_23 ( V_36 , V_11 ) ;
F_16 ( V_11 , NULL ) ;
F_27 ( V_1 -> V_14 ) ;
F_25 ( V_1 ) ;
return 0 ;
}
static int T_4 F_28 ( void )
{
return F_29 ( & V_40 ) ;
}
static void T_5 F_30 ( void )
{
F_31 ( & V_40 ) ;
}
