static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_6 [ 0 ] = V_3 << 3 ;
V_2 -> V_6 [ 1 ] = 0 ;
V_4 = F_3 ( V_2 -> V_7 , & V_2 -> V_6 , 2 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
V_4 = F_5 ( V_2 -> V_7 , & V_2 -> V_6 , 2 ) ;
F_4 ( & V_2 -> V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
return ( ( V_2 -> V_6 [ 0 ] << 8 | V_2 -> V_6 [ 1 ] ) & 0xFFF ) ;
}
static int F_6 ( struct V_8 * V_9 ,
struct V_10 const * V_3 , int * V_11 ,
int * V_12 , long V_13 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
int V_4 ;
switch ( V_13 ) {
case V_14 :
V_4 = F_1 ( V_2 , V_3 -> V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_11 = V_4 ;
return V_15 ;
case V_16 :
V_4 = F_8 ( V_2 -> V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_11 = V_4 / 1000 ;
* V_12 = 12 ;
return V_18 ;
default:
return - V_19 ;
}
}
static int F_9 ( struct V_20 * V_7 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
int V_21 = F_10 ( V_7 ) -> V_22 ;
int V_4 ;
V_9 = F_11 ( & V_7 -> V_23 , sizeof( * V_2 ) ) ;
if ( ! V_9 )
return - V_24 ;
V_2 = F_7 ( V_9 ) ;
V_2 -> V_7 = V_7 ;
F_12 ( V_7 , V_9 ) ;
V_9 -> V_23 . V_25 = & V_7 -> V_23 ;
V_9 -> V_23 . V_26 = V_7 -> V_23 . V_26 ;
V_9 -> V_27 = F_10 ( V_7 ) -> V_27 ;
V_9 -> V_28 = V_29 ;
V_9 -> V_30 = & V_31 ;
V_9 -> V_32 = V_33 [ V_21 ] . V_32 ;
V_9 -> V_34 = V_33 [ V_21 ] . V_34 ;
V_2 -> V_17 = F_13 ( & V_7 -> V_23 , L_1 ) ;
if ( F_14 ( V_2 -> V_17 ) )
return F_15 ( V_2 -> V_17 ) ;
V_4 = F_16 ( V_2 -> V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_17 ( & V_2 -> V_5 ) ;
V_4 = F_18 ( V_9 ) ;
return V_4 ;
}
static int F_19 ( struct V_20 * V_7 )
{
struct V_8 * V_9 = F_20 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_21 ( V_9 ) ;
F_22 ( V_2 -> V_17 ) ;
return 0 ;
}
