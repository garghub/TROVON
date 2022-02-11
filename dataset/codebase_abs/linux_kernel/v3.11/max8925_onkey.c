static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 ;
V_5 = F_2 ( V_4 -> V_6 , V_7 ) ;
F_3 ( V_4 -> V_8 , V_9 , V_5 & V_10 ) ;
F_4 ( V_4 -> V_8 ) ;
F_5 ( V_4 -> V_11 , L_1 , V_5 ) ;
F_6 ( V_4 -> V_6 , V_12 ,
V_13 , V_13 ) ;
return V_14 ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_8 ( V_16 -> V_11 . V_19 ) ;
struct V_3 * V_4 ;
struct V_20 * V_21 ;
int V_1 [ 2 ] , error ;
V_1 [ 0 ] = F_9 ( V_16 , 0 ) ;
if ( V_1 [ 0 ] < 0 ) {
F_10 ( & V_16 -> V_11 , L_2 ) ;
return - V_22 ;
}
V_1 [ 1 ] = F_9 ( V_16 , 1 ) ;
if ( V_1 [ 1 ] < 0 ) {
F_10 ( & V_16 -> V_11 , L_2 ) ;
return - V_22 ;
}
V_4 = F_11 ( sizeof( struct V_3 ) , V_23 ) ;
V_21 = F_12 () ;
if ( ! V_4 || ! V_21 ) {
error = - V_24 ;
goto V_25;
}
V_4 -> V_8 = V_21 ;
V_4 -> V_6 = V_18 -> V_6 ;
V_4 -> V_11 = & V_16 -> V_11 ;
V_4 -> V_1 [ 0 ] = V_1 [ 0 ] ;
V_4 -> V_1 [ 1 ] = V_1 [ 1 ] ;
V_21 -> V_26 = L_3 ;
V_21 -> V_27 = L_4 ;
V_21 -> V_28 . V_29 = V_30 ;
V_21 -> V_11 . V_19 = & V_16 -> V_11 ;
F_13 ( V_21 , V_31 , V_9 ) ;
error = F_14 ( V_1 [ 0 ] , NULL , F_1 ,
V_32 , L_5 , V_4 ) ;
if ( error < 0 ) {
F_10 ( V_18 -> V_11 , L_6 ,
V_1 [ 0 ] , error ) ;
goto V_25;
}
error = F_14 ( V_1 [ 1 ] , NULL , F_1 ,
V_32 , L_7 , V_4 ) ;
if ( error < 0 ) {
F_10 ( V_18 -> V_11 , L_6 ,
V_1 [ 1 ] , error ) ;
goto V_33;
}
error = F_15 ( V_4 -> V_8 ) ;
if ( error ) {
F_10 ( V_18 -> V_11 , L_8 , error ) ;
goto V_34;
}
F_16 ( V_16 , V_4 ) ;
F_17 ( & V_16 -> V_11 , 1 ) ;
return 0 ;
V_34:
F_18 ( V_1 [ 1 ] , V_4 ) ;
V_33:
F_18 ( V_1 [ 0 ] , V_4 ) ;
V_25:
F_19 ( V_21 ) ;
F_20 ( V_4 ) ;
return error ;
}
static int F_21 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = F_22 ( V_16 ) ;
struct V_17 * V_18 = F_8 ( V_16 -> V_11 . V_19 ) ;
F_18 ( V_4 -> V_1 [ 0 ] + V_18 -> V_35 , V_4 ) ;
F_18 ( V_4 -> V_1 [ 1 ] + V_18 -> V_35 , V_4 ) ;
F_23 ( V_4 -> V_8 ) ;
F_20 ( V_4 ) ;
return 0 ;
}
static int F_24 ( struct V_36 * V_11 )
{
struct V_15 * V_16 = F_25 ( V_11 ) ;
struct V_3 * V_4 = F_22 ( V_16 ) ;
struct V_17 * V_18 = F_8 ( V_16 -> V_11 . V_19 ) ;
if ( F_26 ( V_11 ) ) {
V_18 -> V_37 |= 1 << V_4 -> V_1 [ 0 ] ;
V_18 -> V_37 |= 1 << V_4 -> V_1 [ 1 ] ;
}
return 0 ;
}
static int F_27 ( struct V_36 * V_11 )
{
struct V_15 * V_16 = F_25 ( V_11 ) ;
struct V_3 * V_4 = F_22 ( V_16 ) ;
struct V_17 * V_18 = F_8 ( V_16 -> V_11 . V_19 ) ;
if ( F_26 ( V_11 ) ) {
V_18 -> V_37 &= ~ ( 1 << V_4 -> V_1 [ 0 ] ) ;
V_18 -> V_37 &= ~ ( 1 << V_4 -> V_1 [ 1 ] ) ;
}
return 0 ;
}
