static int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 [ 7 ] ;
int V_4 ;
V_4 = F_2 ( V_2 , V_5 ,
V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 [ 0 ] = V_7 ;
V_3 [ 1 ] = V_8 ;
V_3 [ 2 ] = V_9 ;
V_3 [ 3 ] = V_8 ;
V_3 [ 4 ] = V_10 ;
V_3 [ 5 ] = V_8 ;
V_4 = F_3 ( V_2 , V_3 , 6 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_2 , V_11 ,
V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 [ 0 ] = V_13 ;
V_3 [ 1 ] = V_14 ;
V_3 [ 2 ] = V_15 ;
V_3 [ 3 ] = V_16 ;
V_3 [ 4 ] = V_17 ;
V_3 [ 5 ] = 0x00 ;
V_3 [ 6 ] = 0x07 ;
V_4 = F_3 ( V_2 , V_3 , 7 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_2 , V_7 ,
V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned char V_3 [ 3 ] ;
V_3 [ 0 ] = V_7 ;
V_3 [ 1 ] = V_8 ;
V_3 [ 2 ] = V_19 ;
return F_3 ( V_2 , V_3 , 3 ) ;
}
static int F_5 ( struct V_20 * V_21 ,
struct V_22 const * V_23 ,
int * V_24 , int * V_25 , long V_26 )
{
struct V_27 * V_28 = F_6 ( V_21 ) ;
T_1 V_29 [ 4 ] ;
int V_4 ;
switch ( V_26 ) {
case V_30 :
V_4 = F_7 ( V_28 -> V_2 ,
V_31 ,
sizeof( V_29 ) , ( V_32 * ) V_29 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_8 ( V_29 [ V_23 -> V_33 ] ) ;
* V_24 = F_9 ( V_4 , 12 ) ;
return V_34 ;
case V_35 :
* V_24 = 0 ;
* V_25 = V_36 ;
return V_37 ;
default:
return - V_38 ;
}
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
int V_4 ;
struct V_20 * V_21 ;
struct V_27 * V_28 ;
V_4 = F_11 ( V_2 , V_31 ) ;
if ( V_4 != V_41 )
return ( V_4 < 0 ) ? V_4 : - V_42 ;
V_4 = F_11 ( V_2 , V_43 ) ;
if ( V_4 != V_44 )
return ( V_4 < 0 ) ? V_4 : - V_42 ;
V_21 = F_12 ( & V_2 -> V_45 , sizeof( * V_28 ) ) ;
if ( ! V_21 ) {
F_13 ( & V_2 -> V_45 , L_1 ) ;
return - V_46 ;
}
V_28 = F_6 ( V_21 ) ;
V_28 -> V_2 = V_2 ;
F_14 ( V_2 , V_21 ) ;
V_21 -> V_45 . V_47 = & V_2 -> V_45 ;
V_21 -> V_48 = & V_49 ;
V_21 -> V_50 = L_2 ;
V_21 -> V_51 = V_52 ;
V_21 -> V_53 = V_54 ;
V_21 -> V_55 = F_15 ( V_54 ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_16 ( V_21 ) ;
if ( V_4 < 0 ) {
F_13 ( & V_2 -> V_45 , L_3 ) ;
F_4 ( V_2 ) ;
}
return V_4 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
F_19 ( V_21 ) ;
return F_4 ( V_2 ) ;
}
static int F_20 ( struct V_56 * V_45 )
{
return F_4 ( F_21 ( V_45 ) ) ;
}
static int F_22 ( struct V_56 * V_45 )
{
return F_1 ( F_21 ( V_45 ) ) ;
}
