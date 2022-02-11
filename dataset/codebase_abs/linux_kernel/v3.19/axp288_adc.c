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
if ( V_2 != V_8 )
return 0 ;
return F_4 ( V_3 , V_9 , V_7 ) ;
}
static int F_5 ( struct V_10 * V_11 ,
struct V_12 const * V_13 ,
int * V_1 , int * V_14 , long V_15 )
{
int V_16 ;
struct V_17 * V_18 = F_6 ( V_11 ) ;
F_7 ( & V_11 -> V_19 ) ;
switch ( V_15 ) {
case V_20 :
if ( F_3 ( V_18 -> V_3 , V_21 ,
V_13 -> V_2 ) ) {
F_8 ( & V_11 -> V_22 , L_1 ) ;
V_16 = - V_23 ;
break;
}
V_16 = F_1 ( V_1 , V_13 -> V_2 , V_18 -> V_3 ) ;
if ( F_3 ( V_18 -> V_3 , V_24 ,
V_13 -> V_2 ) )
F_8 ( & V_11 -> V_22 , L_2 ) ;
break;
case V_25 :
V_16 = F_1 ( V_1 , V_13 -> V_2 , V_18 -> V_3 ) ;
break;
default:
V_16 = - V_23 ;
}
F_9 ( & V_11 -> V_19 ) ;
return V_16 ;
}
static int F_10 ( struct V_3 * V_3 )
{
if ( F_4 ( V_3 , V_9 , V_24 ) )
return - V_5 ;
return F_4 ( V_3 , V_26 , V_27 ) ;
}
static int F_11 ( struct V_28 * V_29 )
{
int V_16 ;
struct V_17 * V_18 ;
struct V_10 * V_11 ;
struct V_30 * V_31 = F_12 ( V_29 -> V_22 . V_32 ) ;
V_11 = F_13 ( & V_29 -> V_22 , sizeof( * V_18 ) ) ;
if ( ! V_11 )
return - V_33 ;
V_18 = F_6 ( V_11 ) ;
V_18 -> V_34 = F_14 ( V_29 , 0 ) ;
if ( V_18 -> V_34 < 0 ) {
F_8 ( & V_29 -> V_22 , L_3 ) ;
return V_18 -> V_34 ;
}
F_15 ( V_29 , V_11 ) ;
V_18 -> V_3 = V_31 -> V_3 ;
V_16 = F_10 ( V_31 -> V_3 ) ;
if ( V_16 ) {
F_8 ( & V_29 -> V_22 , L_4 ) ;
return V_16 ;
}
V_11 -> V_22 . V_32 = & V_29 -> V_22 ;
V_11 -> V_35 = V_29 -> V_35 ;
V_11 -> V_36 = V_37 ;
V_11 -> V_38 = F_16 ( V_37 ) ;
V_11 -> V_18 = & V_39 ;
V_11 -> V_40 = V_41 ;
V_16 = F_17 ( V_11 , V_42 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_18 ( V_11 ) ;
if ( V_16 < 0 ) {
F_8 ( & V_29 -> V_22 , L_5 ) ;
goto V_43;
}
return 0 ;
V_43:
F_19 ( V_11 ) ;
return V_16 ;
}
static int F_20 ( struct V_28 * V_29 )
{
struct V_10 * V_11 = F_21 ( V_29 ) ;
F_22 ( V_11 ) ;
F_19 ( V_11 ) ;
return 0 ;
}
