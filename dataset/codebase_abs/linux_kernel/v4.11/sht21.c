static inline int F_1 ( int V_1 )
{
V_1 &= ~ 0x0003 ;
return ( ( 21965 * V_1 ) >> 13 ) - 46850 ;
}
static inline int F_2 ( int V_1 )
{
V_1 &= ~ 0x0003 ;
return ( ( 15625 * V_1 ) >> 13 ) - 6000 ;
}
static int F_3 ( struct V_2 * V_3 )
{
int V_4 = 0 ;
struct V_5 * V_5 = F_4 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_5 ( & V_5 -> V_8 ) ;
if ( F_6 ( V_9 , V_5 -> V_10 + V_11 / 2 ) || ! V_5 -> V_12 ) {
V_4 = F_7 ( V_7 ,
V_13 ) ;
if ( V_4 < 0 )
goto V_14;
V_5 -> V_15 = F_1 ( V_4 ) ;
V_4 = F_7 ( V_7 ,
V_16 ) ;
if ( V_4 < 0 )
goto V_14;
V_5 -> V_17 = F_2 ( V_4 ) ;
V_5 -> V_10 = V_9 ;
V_5 -> V_12 = 1 ;
}
V_14:
F_8 ( & V_5 -> V_8 ) ;
return V_4 >= 0 ? 0 : V_4 ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_5 * V_5 = F_4 ( V_3 ) ;
int V_4 ;
V_4 = F_3 ( V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_20 , L_1 , V_5 -> V_15 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_5 * V_5 = F_4 ( V_3 ) ;
int V_4 ;
V_4 = F_3 ( V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_20 , L_1 , V_5 -> V_17 ) ;
}
static T_1 F_11 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
T_2 V_21 [ 2 ] ;
T_2 V_22 [ 8 ] ;
T_2 V_23 [ 8 ] ;
struct V_24 V_25 [ 2 ] = {
{
. V_26 = V_7 -> V_26 ,
. V_27 = 0 ,
. V_28 = 2 ,
. V_20 = V_21 ,
} ,
{
. V_26 = V_7 -> V_26 ,
. V_27 = V_29 ,
. V_28 = 8 ,
. V_20 = V_22 ,
} ,
} ;
int V_4 ;
V_21 [ 0 ] = V_30 ;
V_21 [ 1 ] = V_31 ;
V_4 = F_12 ( V_7 -> V_32 , V_25 , 2 ) ;
if ( V_4 < 0 )
goto V_14;
V_23 [ 2 ] = V_22 [ 0 ] ;
V_23 [ 3 ] = V_22 [ 2 ] ;
V_23 [ 4 ] = V_22 [ 4 ] ;
V_23 [ 5 ] = V_22 [ 6 ] ;
V_21 [ 0 ] = V_33 ;
V_21 [ 1 ] = V_34 ;
V_25 [ 1 ] . V_28 = 6 ;
V_4 = F_12 ( V_7 -> V_32 , V_25 , 2 ) ;
if ( V_4 < 0 )
goto V_14;
V_23 [ 0 ] = V_22 [ 3 ] ;
V_23 [ 1 ] = V_22 [ 4 ] ;
V_23 [ 6 ] = V_22 [ 0 ] ;
V_23 [ 7 ] = V_22 [ 1 ] ;
V_4 = snprintf ( V_5 -> V_23 , sizeof( V_5 -> V_23 ) ,
L_2 ,
V_23 [ 0 ] , V_23 [ 1 ] , V_23 [ 2 ] , V_23 [ 3 ] ,
V_23 [ 4 ] , V_23 [ 5 ] , V_23 [ 6 ] , V_23 [ 7 ] ) ;
V_14:
if ( V_4 < 0 )
V_5 -> V_23 [ 0 ] = 0 ;
return V_4 ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_5 * V_5 = F_4 ( V_3 ) ;
int V_4 ;
V_4 = sizeof( V_5 -> V_23 ) - 1 ;
F_5 ( & V_5 -> V_8 ) ;
if ( ! V_5 -> V_23 [ 0 ] )
V_4 = F_11 ( V_5 ) ;
if ( V_4 > 0 )
memcpy ( V_20 , V_5 -> V_23 , V_4 ) ;
F_8 ( & V_5 -> V_8 ) ;
return V_4 ;
}
static int F_14 ( struct V_6 * V_7 ,
const struct V_35 * V_36 )
{
struct V_2 * V_3 = & V_7 -> V_3 ;
struct V_2 * V_37 ;
struct V_5 * V_5 ;
if ( ! F_15 ( V_7 -> V_32 ,
V_38 ) ) {
F_16 ( & V_7 -> V_3 ,
L_3 ) ;
return - V_39 ;
}
V_5 = F_17 ( V_3 , sizeof( * V_5 ) , V_40 ) ;
if ( ! V_5 )
return - V_41 ;
V_5 -> V_7 = V_7 ;
F_18 ( & V_5 -> V_8 ) ;
V_37 = F_19 ( V_3 , V_7 -> V_42 ,
V_5 , V_43 ) ;
return F_20 ( V_37 ) ;
}
