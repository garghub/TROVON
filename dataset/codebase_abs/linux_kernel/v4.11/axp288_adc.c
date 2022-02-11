static int F_1 ( int * V_1 , unsigned long V_2 ,
struct V_3 * V_3 )
{
T_1 V_4 [ 2 ] ;
if ( F_2 ( V_3 , V_2 , V_4 , 2 ) )
return - V_5 ;
* V_1 = ( V_4 [ 0 ] << 4 ) + ( ( V_4 [ 1 ] >> 4 ) & 0x0F ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 ,
struct V_9 const * V_10 ,
int * V_1 , int * V_11 , long V_12 )
{
int V_13 ;
struct V_14 * V_15 = F_4 ( V_8 ) ;
F_5 ( & V_8 -> V_16 ) ;
switch ( V_12 ) {
case V_17 :
V_13 = F_1 ( V_1 , V_10 -> V_2 , V_15 -> V_3 ) ;
break;
default:
V_13 = - V_18 ;
}
F_6 ( & V_8 -> V_16 ) ;
return V_13 ;
}
static int F_7 ( struct V_19 * V_20 )
{
int V_13 ;
struct V_14 * V_15 ;
struct V_7 * V_8 ;
struct V_21 * V_22 = F_8 ( V_20 -> V_23 . V_24 ) ;
V_8 = F_9 ( & V_20 -> V_23 , sizeof( * V_15 ) ) ;
if ( ! V_8 )
return - V_25 ;
V_15 = F_4 ( V_8 ) ;
V_15 -> V_26 = F_10 ( V_20 , 0 ) ;
if ( V_15 -> V_26 < 0 ) {
F_11 ( & V_20 -> V_23 , L_1 ) ;
return V_15 -> V_26 ;
}
F_12 ( V_20 , V_8 ) ;
V_15 -> V_3 = V_22 -> V_3 ;
V_13 = F_13 ( V_15 -> V_3 , V_27 , V_28 ) ;
if ( V_13 ) {
F_11 ( & V_20 -> V_23 , L_2 ) ;
return V_13 ;
}
V_8 -> V_23 . V_24 = & V_20 -> V_23 ;
V_8 -> V_29 = V_20 -> V_29 ;
V_8 -> V_30 = V_31 ;
V_8 -> V_32 = F_14 ( V_31 ) ;
V_8 -> V_15 = & V_33 ;
V_8 -> V_34 = V_35 ;
V_13 = F_15 ( V_8 , V_36 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_16 ( V_8 ) ;
if ( V_13 < 0 ) {
F_11 ( & V_20 -> V_23 , L_3 ) ;
goto V_37;
}
return 0 ;
V_37:
F_17 ( V_8 ) ;
return V_13 ;
}
static int F_18 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_19 ( V_20 ) ;
F_20 ( V_8 ) ;
F_17 ( V_8 ) ;
return 0 ;
}
