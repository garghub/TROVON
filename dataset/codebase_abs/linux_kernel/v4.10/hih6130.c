static inline int F_1 ( int V_1 )
{
V_1 = V_1 >> 2 ;
return ( F_2 ( V_1 * 1650 , 16382 ) - 400 ) * 100 ;
}
static inline int F_3 ( int V_1 )
{
V_1 &= ~ 0xC000 ;
return F_2 ( V_1 * 1000 , 16382 ) * 100 ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_5 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = 0 ;
int V_8 ;
unsigned char V_9 [ 4 ] ;
struct V_10 V_11 [ 1 ] = {
{
. V_12 = V_6 -> V_12 ,
. V_13 = V_14 ,
. V_15 = 4 ,
. V_16 = V_9 ,
}
} ;
F_6 ( & V_4 -> V_17 ) ;
if ( F_7 ( V_18 , V_4 -> V_19 + V_20 ) || ! V_4 -> V_21 ) {
V_9 [ 0 ] = 0 ;
V_7 = F_8 ( V_6 , V_9 , V_4 -> V_22 ) ;
if ( V_7 < 0 )
goto V_23;
F_9 ( 40 ) ;
V_7 = F_10 ( V_6 -> V_24 , V_11 , 1 ) ;
if ( V_7 < 0 )
goto V_23;
if ( ( V_9 [ 0 ] & 0xC0 ) != 0 ) {
F_11 ( & V_6 -> V_3 , L_1 ) ;
V_7 = - V_25 ;
goto V_23;
}
V_8 = ( V_9 [ 0 ] << 8 ) + V_9 [ 1 ] ;
V_4 -> V_26 = F_3 ( V_8 ) ;
V_8 = ( V_9 [ 2 ] << 8 ) + V_9 [ 3 ] ;
V_4 -> V_27 = F_1 ( V_8 ) ;
V_4 -> V_19 = V_18 ;
V_4 -> V_21 = true ;
}
V_23:
F_12 ( & V_4 -> V_17 ) ;
return V_7 >= 0 ? 0 : V_7 ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_28 * V_29 ,
char * V_16 )
{
struct V_4 * V_4 = F_5 ( V_3 ) ;
int V_7 ;
V_7 = F_4 ( V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_16 , L_2 , V_4 -> V_27 ) ;
}
static T_1 F_14 ( struct V_2 * V_3 ,
struct V_28 * V_29 , char * V_16 )
{
struct V_4 * V_4 = F_5 ( V_3 ) ;
int V_7 ;
V_7 = F_4 ( V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_16 , L_2 , V_4 -> V_26 ) ;
}
static int F_15 ( struct V_5 * V_6 ,
const struct V_30 * V_31 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_4 * V_4 ;
struct V_2 * V_32 ;
if ( ! F_16 ( V_6 -> V_24 , V_33 ) ) {
F_11 ( & V_6 -> V_3 , L_3 ) ;
return - V_34 ;
}
V_4 = F_17 ( V_3 , sizeof( * V_4 ) , V_35 ) ;
if ( ! V_4 )
return - V_36 ;
V_4 -> V_6 = V_6 ;
F_18 ( & V_4 -> V_17 ) ;
if ( ! F_16 ( V_6 -> V_24 , V_37 ) )
V_4 -> V_22 = 1 ;
V_32 = F_19 ( V_3 , V_6 -> V_38 ,
V_4 ,
V_39 ) ;
return F_20 ( V_32 ) ;
}
