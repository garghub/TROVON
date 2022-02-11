static int F_1 ( int * V_1 , unsigned long V_2 ,
struct V_3 * V_3 )
{
T_1 V_4 [ 2 ] ;
if ( F_2 ( V_3 , V_2 , V_4 , 2 ) )
return - V_5 ;
* V_1 = ( V_4 [ 0 ] << 4 ) + ( ( V_4 [ 1 ] >> 4 ) & 0x0F ) ;
return V_6 ;
}
static int F_3 ( struct V_3 * V_3 , unsigned int V_7 ,
unsigned long V_2 )
{
int V_8 ;
if ( V_2 != V_9 )
return 0 ;
V_8 = F_4 ( V_3 , V_10 , V_7 ) ;
if ( V_8 )
return V_8 ;
if ( V_7 == V_11 )
F_5 ( 6000 , 10000 ) ;
return 0 ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_14 const * V_15 ,
int * V_1 , int * V_16 , long V_17 )
{
int V_8 ;
struct V_18 * V_19 = F_7 ( V_13 ) ;
F_8 ( & V_13 -> V_20 ) ;
switch ( V_17 ) {
case V_21 :
if ( F_3 ( V_19 -> V_3 , V_11 ,
V_15 -> V_2 ) ) {
F_9 ( & V_13 -> V_22 , L_1 ) ;
V_8 = - V_23 ;
break;
}
V_8 = F_1 ( V_1 , V_15 -> V_2 , V_19 -> V_3 ) ;
if ( F_3 ( V_19 -> V_3 , V_24 ,
V_15 -> V_2 ) )
F_9 ( & V_13 -> V_22 , L_2 ) ;
break;
default:
V_8 = - V_23 ;
}
F_10 ( & V_13 -> V_20 ) ;
return V_8 ;
}
static int F_11 ( struct V_3 * V_3 )
{
if ( F_4 ( V_3 , V_10 , V_24 ) )
return - V_5 ;
return F_4 ( V_3 , V_25 , V_26 ) ;
}
static int F_12 ( struct V_27 * V_28 )
{
int V_8 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
struct V_29 * V_30 = F_13 ( V_28 -> V_22 . V_31 ) ;
V_13 = F_14 ( & V_28 -> V_22 , sizeof( * V_19 ) ) ;
if ( ! V_13 )
return - V_32 ;
V_19 = F_7 ( V_13 ) ;
V_19 -> V_33 = F_15 ( V_28 , 0 ) ;
if ( V_19 -> V_33 < 0 ) {
F_9 ( & V_28 -> V_22 , L_3 ) ;
return V_19 -> V_33 ;
}
F_16 ( V_28 , V_13 ) ;
V_19 -> V_3 = V_30 -> V_3 ;
V_8 = F_11 ( V_30 -> V_3 ) ;
if ( V_8 ) {
F_9 ( & V_28 -> V_22 , L_4 ) ;
return V_8 ;
}
V_13 -> V_22 . V_31 = & V_28 -> V_22 ;
V_13 -> V_34 = V_28 -> V_34 ;
V_13 -> V_35 = V_36 ;
V_13 -> V_37 = F_17 ( V_36 ) ;
V_13 -> V_19 = & V_38 ;
V_13 -> V_39 = V_40 ;
V_8 = F_18 ( V_13 , V_41 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_19 ( V_13 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_28 -> V_22 , L_5 ) ;
goto V_42;
}
return 0 ;
V_42:
F_20 ( V_13 ) ;
return V_8 ;
}
static int F_21 ( struct V_27 * V_28 )
{
struct V_12 * V_13 = F_22 ( V_28 ) ;
F_23 ( V_13 ) ;
F_20 ( V_13 ) ;
return 0 ;
}
